// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Data/Xml path builders (ItemPreset, ItemModel, npc, pet, AniKeyInfo,
// String) and the custom music (.ms2mml) path.
// MS2-UNIT: unit_14071a5b0
// MS2-RANGE: 0x14071a5b0-0x14071af20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_14071a5b0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

CStringA FUN_140513200(const char* fmt, const unsigned int& v);   // "{0:03d}.xml" style formatter
CStringA FUN_140188f50(const char* s, int n);
CStringA FUN_14071a5b0(const CStringA& dir, const CStringA& file);
CStringA FUN_14071a520(const CStringA& s);
CStringA FUN_14071ae20(const CStringA& file);
void FUN_14071a7e0(unsigned int id, unsigned int* hi, unsigned int* lo);

// @0x14071a5b0
CStringA FUN_14071a5b0(const CStringA& dir, const CStringA& file)
{
    CStringA s;
    s.Format("%s%s/%s", "./Data/Xml/", (const char*)dir, (const char*)file);
    return s;
}

// @0x14071a660
CStringA FUN_14071a660(const CStringA& file)
{
    CStringA s;
    s.Format("%s%s", "./Data/Xml/", (const char*)file);
    return s;
}

// @0x14071a6f0
CStringA FUN_14071a6f0(const CStringA& file)
{
    CStringA s;
    s.Format("%s%s", "./Data/XmlDebug/", (const char*)file);
    return s;
}

// @0x14071a7e0
void FUN_14071a7e0(unsigned int id, unsigned int* hi, unsigned int* lo)
{
    int t = id / 10000;
    *hi = t / 100;
    *lo = t % 100;
}

// @0x14071a840
CStringA GetItemPresetPath(const CStringA& dir, const CStringA& name)
{
    CStringA s;
    s.Format("%s%s.xml", (const char*)dir, (const char*)name);
    {
        CStringA sub("ItemPreset");
        s = FUN_14071a5b0(sub, s);
    }
    return s;
}

// @0x14071a940
// MS2-FUNCTIONAL: temp/destructor order of the ItemModel path build (extra copy vs the exe) not matched after 3 attempts
CStringA GetItemModelPath(unsigned int id)
{
    CStringA r = FUN_14071a5b0(CStringA("ItemModel"), FUN_140513200("{0:03d}.xml", id));
    return r;
}

// @0x14071aa00
CStringA GetNpcPath(unsigned int id)
{
    unsigned int hi, lo;
    FUN_14071a7e0(id, &hi, &lo);
    CStringA s;
    s.Format("%02d/%02d/%08d.xml", hi, lo, id);
    {
        CStringA sub("npc");
        s = FUN_14071a5b0(sub, s);
    }
    return s;
}

// @0x14071ab10
CStringA GetPetPath(unsigned int id)
{
    CStringA s;
    s.Format("%08d.xml", id);
    {
        CStringA sub("pet");
        s = FUN_14071a5b0(sub, s);
    }
    return s;
}

// @0x14071abf0
CStringA FUN_14071abf0(unsigned int id)
{
    unsigned int hi, lo;
    FUN_14071a7e0(id, &hi, &lo);
    CStringA s;
    s.Format("%02d/%02d", hi, lo);
    {
        CStringA sub("npc");
        s = FUN_14071a5b0(sub, s);
    }
    return s;
}

// @0x14071ace0
CStringA GetAniKeyInfoPath(const CStringA& name)
{
    CStringA n = FUN_140188f50((const char*)name, 0);
    CStringA s;
    {
        CStringA sub("AniKeyInfo");
        s = FUN_14071a5b0(sub, n);
    }
    s.Append(".xml");
    return s;
}

// @0x14071ade0
CStringA FUN_14071ade0()
{
    return CStringA("./Data/Xml/String");
}

// @0x14071ae20
CStringA FUN_14071ae20(const CStringA& file)
{
    CStringA sub("String");
    return FUN_14071a5b0(sub, file);
}

// @0x14071ae90
CStringW FUN_14071ae90(const CStringW& name)
{
    CStringW s;
    s.Format(L"%s/%s.ms2mml", L"./Custom/Music", (const wchar_t*)name);
    return s;
}
