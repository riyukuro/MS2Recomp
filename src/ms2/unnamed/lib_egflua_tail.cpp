// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The out-of-line instances of the egfLua EntityLua property
// dump helper behind egf::lua_DumpProperties (0x14224e2a0): one per property type, each writing "\n[name]" plus one
// "\n-> key = value" line per key for an associative property, or "\nname = value" for a scalar one ("???" when the
// value cannot be read). The engine-stage build inlines the helper into lua_DumpProperties, so these exe copies have
// no engine-stage pair.
// MS2-UNIT: lib_egflua_tail
// MS2-RANGE: 0x142249440-0x142249721 .text$mn
// MS2-RANGE: 0x142249730-0x142249a11 .text$mn
// MS2-RANGE: 0x142249a20-0x142249d01 .text$mn
// MS2-RANGE: 0x142249d10-0x142249ff1 .text$mn
// MS2-RANGE: 0x14224a000-0x14224a2df .text$mn
// MS2-RANGE: 0x14224a2e0-0x14224a5bf .text$mn
// MS2-RANGE: 0x14224abb0-0x14224aeb4 .text$mn
// MS2-RANGE: 0x14224b8e0-0x14224bbcd .text$mn
// MS2-RANGE: 0x14224c980-0x14224cc5f .text$mn
// MS2-RANGE: 0x14224cc60-0x14224cf3f .text$mn
// MS2-RANGE: 0x14224cf40-0x14224d247 .text$mn
// MS2-FLAGS: gamebryo
// MS2-PIN: ??$DumpEntityProperty@D@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x142249440
// MS2-PIN: ??$DumpEntityProperty@E@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x142249730
// MS2-PIN: ??$DumpEntityProperty@F@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x142249a20
// MS2-PIN: ??$DumpEntityProperty@G@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x142249d10
// MS2-PIN: ??$DumpEntityProperty@H@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x14224a000
// MS2-PIN: ??$DumpEntityProperty@I@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x14224a2e0
// MS2-PIN: ??$DumpEntityProperty@Uutf8char_t@efd@@@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x14224abb0
// MS2-PIN: ??$DumpEntityProperty@VEntityID@egf@@@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x14224b8e0
// MS2-PIN: ??$DumpEntityProperty@_J@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x14224c980
// MS2-PIN: ??$DumpEntityProperty@_K@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x14224cc60
// MS2-PIN: ??$DumpEntityProperty@_N@lib_egflua_tail@@YAXPEAVEntity@egf@@AEBVutf8string@efd@@AEAV34@@Z 0x14224cf40
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/utf8string.h>
#include <efd/ParseHelper.h>
#include <egf/Entity.h>
#include <egf/EntityID.h>

namespace lib_egflua_tail {

// Appends the property's value(s) to dumpText; T is the property's stored type.
template<typename T>
void DumpEntityProperty(egf::Entity* entity, const efd::utf8string& name, efd::utf8string& dumpText)
{
    T value;
    efd::utf8string text;
    efd::utf8string line;

    efd::UInt32 count;
    if (entity->GetPropertyCount(name, count) == egf::PropertyResult_OK)
    {
        line.sprintf("\n[%s]", name.c_str());
        dumpText += line;

        efd::list<efd::utf8string> keys;
        if (entity->GetPropertyKeys(name, keys) != egf::PropertyResult_OK)
        {
            line.sprintf("\nError receiving keys");
            dumpText += line;
            return;
        }
        for (efd::list<efd::utf8string>::const_iterator key = keys.begin(); key != keys.end(); ++key)
        {
            if (entity->GetPropertyValue<T>(name, *key, value) != egf::PropertyResult_OK)
            {
                line.sprintf("\n-> %s = ???", key->c_str());
                dumpText += line;
                continue;
            }
            if (!efd::ParseHelper<T>::ToString(value, text))
                text = "???";
            line.sprintf("\n-> %s = %s", key->c_str(), text.c_str());
            dumpText += line;
        }
    }
    else
    {
        if (entity->GetPropertyValue<T>(name, value) != egf::PropertyResult_OK)
        {
            line.sprintf("\n%s = ???", name.c_str());
            dumpText += line;
            return;
        }
        if (!efd::ParseHelper<T>::ToString(value, text))
            text = "???";
        line.sprintf("\n%s = %s", name.c_str(), text.c_str());
        dumpText += line;
    }
}

} // namespace lib_egflua_tail

// The exe instances, pinned in the header block.
// MS2-FUNCTIONAL: all 11 differ from the exe only in codegen: the exe keeps std::string::append(const basic_string&)
// out of line (0x1409a2d10) and builds `text` with one movdqa store, where MSVC 14.16 inlines both; r14/r15 swapped.
template void lib_egflua_tail::DumpEntityProperty<efd::SInt8>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x142249440
template void lib_egflua_tail::DumpEntityProperty<efd::UInt8>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x142249730
template void lib_egflua_tail::DumpEntityProperty<efd::SInt16>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x142249a20
template void lib_egflua_tail::DumpEntityProperty<efd::UInt16>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x142249d10
template void lib_egflua_tail::DumpEntityProperty<efd::SInt32>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x14224a000
template void lib_egflua_tail::DumpEntityProperty<efd::UInt32>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x14224a2e0
template void lib_egflua_tail::DumpEntityProperty<efd::utf8char_t>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x14224abb0
template void lib_egflua_tail::DumpEntityProperty<egf::EntityID>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x14224b8e0
template void lib_egflua_tail::DumpEntityProperty<efd::SInt64>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x14224c980
template void lib_egflua_tail::DumpEntityProperty<efd::UInt64>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x14224cc60
template void lib_egflua_tail::DumpEntityProperty<efd::Bool>(egf::Entity*, const efd::utf8string&, efd::utf8string&);   // 0x14224cf40
