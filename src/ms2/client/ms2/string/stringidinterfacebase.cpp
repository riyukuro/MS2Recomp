// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). client\ms2\string\stringidinterfacebase.cpp: the two
// name -> id string maps of StringPVP.xml / StringIndividualArena.xml, StringIdInterfaceBase (string id + arguments,
// packet reader/writer), StringXmlProc<T> construction and the StringManager singleton.
// MS2-UNIT: ?\stringidinterfacebase.cpp
// MS2-RANGE: 0x14084cb30-0x140851620 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: memmove_s 0x14084ed00 ; unique
// MS2-PIN: ??1CPair@?$CRBTree@W4IndividualArenaStringId@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@W4IndividualArenaStringId@@@3@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@3@@ATL@@IEAA@XZ 0x1408500e0 ; unique
// MS2-PIN: ??1CPair@?$CRBTree@W4PVPStringId@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@W4PVPStringId@@@3@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@3@@ATL@@IEAA@XZ 0x140850100 ; unique
// MS2-PIN: ??_G?$StringXmlProc@W4PVPStringId@@@@UEAAPEAXI@Z 0x140850270 ; prop
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@W4StringXmlCategory@@@ATL@@SAHAEBW4StringXmlCategory@@0@Z 0x140850480 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\string\\stringidinterfacebase.cpp"
#ifndef _HAS_AUTO_PTR_ETC
#define _HAS_AUTO_PTR_ETC 1
#endif
#include "ms2/placeholder/ms2stdafx.h"

#include <atlcoll.h>
#include <memory>

#include "ms2/placeholder/stringidinterface.h"
#include "ms2/placeholder/stringmanager.h"
#include "ms2/placeholder/stringxmlproc.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

typedef ATL::CRBMap<CStringW, PVPStringId, ATL::CStringElementTraits<CStringW> > PvpStringMap;
typedef ATL::CRBMap<CStringW, IndividualArenaStringId, ATL::CStringElementTraits<CStringW> > IndividualArenaStringMap;

// @0x14084cb30
std::auto_ptr<PvpStringMap> MakePvpStringMap()
{
    std::auto_ptr<PvpStringMap> strings(new PvpStringMap(10));
    PVPStringId id0 = PVPStringId(0);
    strings->SetAt(L"s_empty_string_PVP", id0);
    PVPStringId id1 = PVPStringId(1);
    strings->SetAt(L"s_dualwin1", id1);
    PVPStringId id2 = PVPStringId(2);
    strings->SetAt(L"s_dualwin2", id2);
    PVPStringId id3 = PVPStringId(3);
    strings->SetAt(L"s_dualwin3", id3);
    PVPStringId id4 = PVPStringId(4);
    strings->SetAt(L"s_dualwin4", id4);
    PVPStringId id5 = PVPStringId(5);
    strings->SetAt(L"s_dualwin5", id5);
    PVPStringId id6 = PVPStringId(6);
    strings->SetAt(L"s_dualwin6", id6);
    PVPStringId id7 = PVPStringId(7);
    strings->SetAt(L"s_dualwin7", id7);
    PVPStringId id8 = PVPStringId(8);
    strings->SetAt(L"s_dualwin8", id8);
    PVPStringId id9 = PVPStringId(9);
    strings->SetAt(L"s_dualwin9", id9);
    PVPStringId id10 = PVPStringId(10);
    strings->SetAt(L"s_dualprepareplayer", id10);
    PVPStringId id11 = PVPStringId(11);
    strings->SetAt(L"s_dualstartcombat", id11);
    PVPStringId id12 = PVPStringId(12);
    strings->SetAt(L"s_dualwinnermessage", id12);
    PVPStringId id13 = PVPStringId(13);
    strings->SetAt(L"s_duallosermessage", id13);
    PVPStringId id14 = PVPStringId(14);
    strings->SetAt(L"s_freeforallwin", id14);
    PVPStringId id15 = PVPStringId(15);
    strings->SetAt(L"s_onepunchwin", id15);
    PVPStringId id16 = PVPStringId(16);
    strings->SetAt(L"s_guilddualprepare", id16);
    PVPStringId id17 = PVPStringId(17);
    strings->SetAt(L"s_guilddualstartcombat", id17);
    PVPStringId id18 = PVPStringId(18);
    strings->SetAt(L"s_guildteamnotifycombat", id18);
    PVPStringId id19 = PVPStringId(19);
    strings->SetAt(L"s_guildteamnotifylastcombat", id19);
    PVPStringId id20 = PVPStringId(20);
    strings->SetAt(L"s_guildteamnotifygamestart", id20);
    PVPStringId id21 = PVPStringId(21);
    strings->SetAt(L"s_guildteamnotifygamestartdetail1", id21);
    PVPStringId id22 = PVPStringId(22);
    strings->SetAt(L"s_guildteamnotifygamestartdetail2", id22);
    PVPStringId id23 = PVPStringId(23);
    strings->SetAt(L"s_guildteamnotifygamestartdetail3", id23);
    PVPStringId id24 = PVPStringId(24);
    strings->SetAt(L"s_guildteamnotifyprepareplayer", id24);
    PVPStringId id25 = PVPStringId(25);
    strings->SetAt(L"s_guildteamnotifypreparearena", id25);
    PVPStringId id26 = PVPStringId(26);
    strings->SetAt(L"s_guildteamstartcombat", id26);
    PVPStringId id27 = PVPStringId(27);
    strings->SetAt(L"s_teamnotifygamedetail1", id27);
    PVPStringId id28 = PVPStringId(28);
    strings->SetAt(L"s_teamnotifygamedetail2", id28);
    PVPStringId id29 = PVPStringId(29);
    strings->SetAt(L"s_teamnotifygamedetail3", id29);
    PVPStringId id30 = PVPStringId(30);
    strings->SetAt(L"s_teamprepare", id30);
    return strings;
}
// @0x14084d0c0
std::auto_ptr<IndividualArenaStringMap> MakeIndividualArenaStringMap()
{
    std::auto_ptr<IndividualArenaStringMap> strings(new IndividualArenaStringMap(10));
    IndividualArenaStringId id0 = IndividualArenaStringId(0);
    strings->SetAt(L"s_empty_string_IndividualArena", id0);
    IndividualArenaStringId id1 = IndividualArenaStringId(1);
    strings->SetAt(L"s_arenaname_1", id1);
    IndividualArenaStringId id2 = IndividualArenaStringId(2);
    strings->SetAt(L"s_arenaname_2", id2);
    IndividualArenaStringId id3 = IndividualArenaStringId(3);
    strings->SetAt(L"s_arenaname_3", id3);
    IndividualArenaStringId id4 = IndividualArenaStringId(4);
    strings->SetAt(L"s_arenadetail_1", id4);
    IndividualArenaStringId id5 = IndividualArenaStringId(5);
    strings->SetAt(L"s_arenadetail_2", id5);
    IndividualArenaStringId id6 = IndividualArenaStringId(6);
    strings->SetAt(L"s_arenadetail_3", id6);
    return strings;
}

// ---- unrecovered helpers -----------------------------------------------------------------------------------------
CStringW GetStringCommon(int stringId);                                   // text of a string id (StringManager lookup)
extern StringManager* DAT_143ab1c98;

// @0x14084ee20
StringIdInterfaceBase::StringIdInterfaceBase() : kind(0), id(0), formatted(false)
{
}

// @0x14084ee90
StringIdInterfaceBase::StringIdInterfaceBase(int kind, int id) : kind(kind), id(id), formatted(true)
{
}

// @0x14084ef10
StringIdInterfaceBase::StringIdInterfaceBase(int kind, int id, const CStringW& argument) : kind(kind), id(id), formatted(true)
{
    arguments.Add(argument);
}

// @0x14084efb0
StringIdInterfaceBase::StringIdInterfaceBase(int kind, int id, const ATL::CAtlArray<CStringW>& args) : kind(kind), id(id), formatted(true)
{
    arguments.Copy(args);
}

// @0x14084f050
StringIdInterfaceBase::StringIdInterfaceBase(int kind, CStringW text) : kind(kind), id(0), formatted(false), text(text)
{
}

// @0x14084f0e0
StringIdInterfaceBase::StringIdInterfaceBase(CStringW text) : kind(0), id(0), formatted(false), text(text)
{
}

// @0x14084f170
StringIdInterfaceBase::StringIdInterfaceBase(const StringIdInterfaceBase& other)
{
    *this = other;
}

// @0x14084f1e0
StringIdInterfaceBase& StringIdInterfaceBase::operator=(const StringIdInterfaceBase& other)
{
    kind = other.kind;
    id = other.id;
    arguments.Copy(other.arguments);
    formatted = other.formatted;
    text = other.text;
    return *this;
}

// @0x14084f270
// serializes a StringIdInterfaceBase
void FUN_14084f270(const StringIdInterfaceBase& body, COutputStream& out)
{
    out.vfunc_o10_0(body.formatted);
    out.vfunc_o10_3(body.kind);
    if (body.formatted)
    {
        out.vfunc_o10_3(body.id);
        unsigned count = body.arguments.GetCount();
        out.vfunc_o10_3(count);
        for (unsigned i = 0; i < count; i++)
            out.vfunc_o10_8(body.arguments[i]);
    }
    else
    {
        out.vfunc_o10_8(body.text);
    }
}

// @0x14084f390
// packet reader of StringIdInterfaceBase
void FUN_14084f390(StringIdInterfaceBase* pThis, CInPacket& packet)
{
    pThis->formatted = packet.vfunc_o8_0();
    pThis->kind = packet.vfunc_o8_3();
    if (pThis->formatted)
    {
        pThis->id = packet.vfunc_o8_3();
        size_t count = (unsigned)packet.vfunc_o8_3();
        if (count != 0)
        {
            for (size_t i = 0; i < count; i++)
                pThis->arguments.Add(packet.vfunc_o8_8());
        }
    }
    else
    {
        pThis->text = packet.vfunc_o8_8();
    }
}

// @0x14084f680
StringManager::StringManager() : m_tables(10)
{
    {
        MS2Ptr<StringXmlProcBase> pvpTable(new StringXmlProc<PVPStringId>(CStringA("stringPVP.xml"), MakePvpStringMap, CStringA("id"), CStringA("name")));
        StringXmlCategory pvpKey = StringXmlCategory(3);
        m_tables.SetAt(pvpKey, pvpTable);
    }
    {
        MS2Ptr<StringXmlProcBase> arenaTable(new StringXmlProc<IndividualArenaStringId>(CStringA("StringIndividualArena.xml"), MakeIndividualArenaStringMap, CStringA("id"), CStringA("name")));
        StringXmlCategory arenaKey = StringXmlCategory(4);
        m_tables.SetAt(arenaKey, arenaTable);
    }
}

// @0x14084f980
StringManager::~StringManager()
{
}

// @0x14084f9c0
CStringW StringManager::FUN_14084f9c0(StringXmlCategory category, int id)
{
    return GetStringCommon(id);
}

// @0x14084faa0 (IndividualArenaStringId), 0x14084fb70 (PVPStringId)
template <class T>
StringXmlProc<T>::StringXmlProc(CStringA path, std::auto_ptr<KeyMap> (*factory)(), CStringA keyAttribute, CStringA valueAttribute)
    : m_path18(path), m_keyAttribute20(keyAttribute), m_valueAttribute28(valueAttribute), m_factory30(factory), m_cached38(0)
{
}

// @0x14084fed0 (IndividualArenaStringId), 0x14084ff80 (PVPStringId)
template <class T>
StringXmlProc<T>::~StringXmlProc()
{
    delete m_cached38;
    m_cached38 = 0;
}

// @0x14084fd80
StringXmlProcBase::StringXmlProcBase()
{
}

// @0x140850140
StringXmlProcBase::~StringXmlProcBase()
{
}
