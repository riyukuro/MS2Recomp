#!/usr/bin/env python3
"""Build the Mushking Royale item overlay of the restore client from your own client data.

The KMS2 client data lacks the survival items: it has no skin items (no itemdata/209.xml), the six survival mount
items and four survival glider items are empty rows in itemdata/506.xml and itemdata/404.xml, a few pass and level
reward items are missing or empty, and the skin name and description tables are empty. The images, riding models,
tail effects and glide rows are already in the KMS2 packs. This script takes the missing rows from a global (GMS)
client's Xml.m2d and writes them as loose files that the client reads before the packed data:

  itemdata/<group>.xml                       every KMS2 item file that gains rows: the KMS2 file with its empty
                                             rows filled and the missing ones added (209.xml is new)
  Table/na/mapleSurvivalSkinInfo.xml         the skin table (one of the survival tables of the README)
  string/en/maplesurvivalskinname.xml        skin names (read through the English row fallback)
  string/en/maplesurvivalskindescription.xml skin descriptions

The items are those of table/maplesurvivalskininfo.xml (the skins and their mount and glider items) and of the
survival reward tables in table/na (survivalPassReward, survivalPassReward_paid, survivalLevelReward). A KMS2 row
that has data is kept.

Mount and glider rows get the KMS2 link in property param1: a mount names its riding/<id>.xml (the skin id), a
glider its table/glidedata.xml row (the GMS glide skill id, which KMS2 keeps as the glide id). The grade moves from
option constant to property rank, where KMS2 reads it. The rows, skin table and skin strings lose their feature
attribute: the global data gates them on SurvivalContents03, which the KMS2 feature table leaves off at Live, so both
the client and a server ingest would drop them (the skin window itself still follows the feature).

Usage:
  survival-items.py --gms <GMS client>/Data/Xml.m2d --kms <KMS2 client>/Data/Xml.m2d --out <KMS2 client>/Data/Xml

Needs the .NET 8 SDK for tools/m2d (dotnet run), or --m2d <command> naming a built m2d (for example
"dotnet tools/m2d/bin/Debug/net8.0/m2d.dll"). Nothing is written outside --out.
"""
import argparse
import os
import re
import shlex
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
M2D_PROJECT = os.path.join(HERE, '..', 'm2d')

SKIN_INFO = 'table/maplesurvivalskininfo.xml'
SKIN_TABLE_OUT = 'Table/na/mapleSurvivalSkinInfo.xml'   # the name the client opens (Table/na first)
STRINGS = ['string/en/maplesurvivalskinname.xml', 'string/en/maplesurvivalskindescription.xml']
REWARDS = ['table/na/survivalpassreward.xml', 'table/na/survivalpassreward_paid.xml',
           'table/na/survivallevelreward.xml']


def m2d_extract(m2d, pack, outdir, prefixes):
    cmd = m2d + ['extract', pack, outdir] + prefixes
    r = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    if r.returncode != 0:
        sys.exit('m2d extract failed (%d): %s%s' % (r.returncode, r.stdout, r.stderr))


def read(path):
    with open(path, encoding='utf-8-sig') as f:
        return f.read()


def gms_item_path(root, item_id):
    s = str(item_id)
    return os.path.join(root, 'item', s[0], s[1:3], s + '.xml')


def environments(text):
    """The <environment> blocks of a GMS item file, each re-indented to sit under <item>."""
    blocks = re.findall(r'^([ \t]*)(<environment\b.*?</environment>)', text, re.S | re.M)
    if not blocks:
        raise ValueError('no <environment>')
    out = []
    for indent, block in blocks:
        lines = block.split('\n')
        fixed = ['\t\t' + lines[0]]
        for line in lines[1:]:
            if line.startswith(indent):
                line = line[len(indent):]
            fixed.append('\t\t' + line)
        block = drop_feature('\n'.join(fixed), 'environment')[0]
        block = re.sub(r'(<environment\b[^>]*?)\s+locale=""', r'\1', block, count=1)   # as the KMS2 rows
        out.append(set_rank(block))
    return out


def drop_feature(text, tag):
    """Remove the feature attribute of every <tag> element. Returns (text, count)."""
    pattern = re.compile(r'(<%s\b[^>]*?)\s+feature="[^"]*"' % tag)
    return pattern.subn(r'\1', text)


def set_rank(block):
    """KMS2 reads the item grade from property rank; the global data keeps it in option constant."""
    m = re.search(r'<option\b[^>]*\sconstant="(\d+)"', block)
    if not m or re.search(r'<property\b[^>]*\srank="', block):
        return block
    return block.replace('<property', '<property rank="%s"' % m.group(1), 1)


def set_param1(block, value):
    def repl(m):
        tag = m.group(0)
        if re.search(r'\sparam1="', tag):
            return re.sub(r'\sparam1="[^"]*"', ' param1="%d"' % value, tag)
        return tag.replace('<property', '<property param1="%d"' % value, 1)
    return re.sub(r'<property\b[^>]*>', repl, block)


def item_row(item_id, blocks):
    return '\t<item id="%d">\n%s\n\t</item>' % (item_id, '\n'.join(blocks))


def fill_rows(text, rows):
    """Fill the empty rows (<item id=".." />) and add the missing ones; rows with data stay. Returns (text, count)."""
    count = 0
    for item_id, row in rows:
        stub = re.compile(r'\t<item id="%d"\s*/>' % item_id)
        full = re.compile(r'\t<item id="%d">.*?</item>' % item_id, re.S)
        if stub.search(text):
            text = stub.sub(lambda m: row, text, count=1)
            count += 1
        elif not full.search(text):
            text = text.replace('</ms2>', row + '\n</ms2>', 1)
            count += 1
    return text, count


def write(out, rel, text):
    path = os.path.join(out, *rel.split('/'))
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, 'w', encoding='utf-8', newline='\n') as f:
        f.write(text)
    print('wrote', path)


def reward_items(text):
    """Item ids of a survival reward table: pass rewards (type item / genderItem, id lists) and level rewards."""
    ids = set()
    for m in re.finditer(r'<survival\w*Reward\b([^>]*)/>', text):
        attrs = dict(re.findall(r'(\w+)="([^"]*)"', m.group(1)))
        for key, value in attrs.items():
            n = re.match(r'type(\d+)$', key)
            if n and value in ('item', 'genderItem'):
                ids.update(int(x) for x in attrs.get('id' + n.group(1), '').split(',') if x.strip())
            elif re.match(r'rewardItemID\d+$', key) and value.strip():
                ids.add(int(value))
    return ids


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--gms', required=True, help="the global client's Data/Xml.m2d")
    ap.add_argument('--kms', required=True, help="the KMS2 client's Data/Xml.m2d")
    ap.add_argument('--out', required=True, help="the KMS2 client's Data/Xml directory (loose files)")
    ap.add_argument('--m2d', help='command running m2d (default: dotnet run --project tools/m2d --)')
    a = ap.parse_args()
    m2d = shlex.split(a.m2d) if a.m2d else ['dotnet', 'run', '--project', M2D_PROJECT, '--']

    with tempfile.TemporaryDirectory(prefix='survival-items-') as tmp:
        g = os.path.join(tmp, 'gms')
        k = os.path.join(tmp, 'kms')
        m2d_extract(m2d, a.gms, g, [SKIN_INFO] + REWARDS + STRINGS)
        info = read(os.path.join(g, *SKIN_INFO.split('/')))
        skins = []
        for m in re.finditer(r'<skinInfo\b([^>]*)/>', info):
            attrs = dict(re.findall(r'(\w+)="([^"]*)"', m.group(1)))
            skins.append((int(attrs['id']), attrs['type'], int(attrs.get('value1') or 0)))
        if not skins:
            sys.exit('no skinInfo rows in ' + SKIN_INFO)
        param1 = {}   # item id -> the KMS2 link written to property param1
        for skin_id, kind, value in skins:
            if kind == 'riding':
                param1[value] = skin_id
            elif kind == 'gliding':
                param1[value] = 0   # the glide id, from the item's skill below
        rewards = set()
        for rel in REWARDS:
            path = os.path.join(g, *rel.split('/'))
            if os.path.exists(path):
                rewards |= reward_items(read(path))
        ids = sorted(set(s for s, _, _ in skins) | set(param1) | rewards)
        m2d_extract(m2d, a.gms, g, ['item/%s/%s/%d.xml' % (str(i)[0], str(i)[1:3], i) for i in ids])
        groups = sorted(set('itemdata/%s.xml' % str(i)[:3] for i in ids))
        m2d_extract(m2d, a.kms, k, groups)

        rows = {}
        for item_id in ids:
            path = gms_item_path(g, item_id)
            if not os.path.exists(path):
                print('item %d: not in the global data, skipped' % item_id)
                continue
            src = read(path)
            blocks = environments(src)
            if item_id in param1:
                link = param1[item_id]
                if link == 0:
                    skill = re.search(r'<skill skillID="(\d+)"', src)
                    if not skill or skill.group(1) == '0':
                        sys.exit('glider item %d has no skill' % item_id)
                    link = int(skill.group(1))
                blocks = [set_param1(b, link) for b in blocks]
            rows.setdefault('itemdata/%s.xml' % str(item_id)[:3], []).append((item_id, item_row(item_id, blocks)))

        added = 0
        empty = '<?xml version="1.0" encoding="utf-8"?>\n<ms2>\n</ms2>\n'
        for rel in groups:
            path = os.path.join(k, *rel.split('/'))
            base = read(path) if os.path.exists(path) else empty
            filled, count = fill_rows(base, rows.get(rel, []))
            if count:
                write(a.out, rel, filled)
                added += count
        for rel in STRINGS:
            text, count = drop_feature(read(os.path.join(g, *rel.split('/'))), 'key')
            write(a.out, rel, text)
            print('%s: feature removed from %d rows' % (rel, count))
        text, count = drop_feature(info, 'skinInfo')
        write(a.out, SKIN_TABLE_OUT, text)
        print('%s: feature removed from %d rows' % (SKIN_TABLE_OUT, count))
    print('%d skins, %d reward items; %d item rows written' % (len(skins), len(rewards), added))


if __name__ == '__main__':
    main()
