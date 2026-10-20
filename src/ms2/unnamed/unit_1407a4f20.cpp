// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Networking: payload serializers (encode to COutputStream,
// decode from CInPacket / CInputStream), COutSendNoticePacket, the adventure-level mission packet and the item-closet tab.
// MS2-UNIT: unit_1407a4f20
// MS2-RANGE: 0x1407a4f20-0x1407ad240 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAIAEAPEAVCAdventureLevelMissionData@@$0A@@?$pair@IPEAVCAdventureLevelMissionData@@@std@@QEAA@AEAIAEAPEAVCAdventureLevelMissionData@@@Z 0x1407a97b0 ; unique
// MS2-PIN: ??$?0IPEAVCAdventureLevelMissionData@@$0A@@?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@QEAA@$$QEAU?$pair@IPEAVCAdventureLevelMissionData@@@1@@Z 0x1407a98a0 ; unique
// MS2-PIN: ??$Unk_SocketFormat@HHHHHH@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBH11111@Z 0x1407a9970 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@U?$pair@HH@std@@@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAX$$QEAU?$pair@HH@1@@Z 0x1407a9e70 ; unique
// MS2-PIN: ??$_Emplace_reallocate@U?$pair@HH@std@@@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAPEAU?$pair@HH@1@QEAU21@$$QEAU21@@Z 0x1407a9f30 ; unique
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@0@AEBV10@@Z 0x1407aaa30 ; prop
// MS2-PIN: ??$emplace_back@U?$pair@HH@std@@@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAX$$QEAU?$pair@HH@1@@Z 0x1407aaba0 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@PEAX@0@AEAPEAU10@@Z 0x1407aac10 ; unique
// MS2-PIN: ??$forward@AEAPEAVCAdventureLevelMissionData@@@std@@YAAEAPEAVCAdventureLevelMissionData@@AEAPEAV1@@Z 0x1407aac20 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1407aac40 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1407aac70 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@QEAA@XZ 0x1407aaec0 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@USlotInfo@ItemCloset@@@@QEAAAEAV1@PEAUSlotInfo@ItemCloset@@@Z 0x1407ab0a0 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@USlotInfo@ItemCloset@@@@V?$CElementTraits@V?$MS2Ptr@USlotInfo@ItemCloset@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@USlotInfo@ItemCloset@@@@_K@Z 0x1407ab190 ; prop
// MS2-PIN: ??A?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAAEAU?$pair@HH@1@_K@Z 0x1407ab1d0 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@USlotInfo@ItemCloset@@@@V?$CElementTraits@V?$MS2Ptr@USlotInfo@ItemCloset@@@@@ATL@@@ATL@@QEBAAEBV?$MS2Ptr@USlotInfo@ItemCloset@@@@_K@Z 0x1407ab6e0 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@V?$MS2Ptr@USlotInfo@ItemCloset@@@@V?$CElementTraits@V?$MS2Ptr@USlotInfo@ItemCloset@@@@@ATL@@@ATL@@QEAA_N_KH@Z 0x1407ab950 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x1407ac4d0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x1407ac4e0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@2@XZ 0x1407ac540 ; unique
// MS2-PIN: ?_Has_unused_capacity@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEBA_NXZ 0x1407ac5f0 ; unique
// MS2-PIN: ?clear@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAXXZ 0x1407acbe0 ; unique
// MS2-PIN: ?push_back@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAX$$QEAU?$pair@HH@2@@Z 0x1407ad0d0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??C?$MS2Ptr@USlotInfo@ItemCloset@@@@QEBAPEAUSlotInfo@ItemCloset@@XZ 0x1407ab200 ; manual: identical-body COMDAT folded in the exe
// MS2-PIN: ??$make_pair@AEAIAEAPEAVCAdventureLevelMissionData@@@std@@YA?AU?$pair@IPEAVCAdventureLevelMissionData@@@0@AEAIAEAPEAVCAdventureLevelMissionData@@@Z 0x1407aacc0 ; exe: forward<unsigned&> 0x140162e50 + pair<unsigned,CAdventureLevelMissionData*> ctor 0x1407a97b0
// MS2-PIN: ??A?$CAtlArray@_KV?$CElementTraits@_K@ATL@@@ATL@@QEAAAEA_K_K@Z 0x1407ab720 ; manual: identical-body COMDAT folded in the exe
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1407ab3b0 ; manual: map const_iterator operator-- (was mispinned as set<unsigned> operator++)
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1407ab3f0 ; manual: map unchecked iterator operator-- (was mispinned as set<unsigned>)
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@XZ 0x140703fd0 ; manual: set<unsigned> copy lives in fieldmetatable's TU, not here
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x140703ff0 ; manual: set<unsigned> copy lives in fieldmetatable's TU, not here
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@SAPEAU?$_Tree_node@IPEAX@2@PEAU32@@Z 0x1407041e0 ; manual: set<unsigned> copy lives in fieldmetatable's TU, not here
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1406ff750 ; manual: set<unsigned> copy lives in fieldmetatable's TU, not here
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x1407ac440 ; manual: identical-body COMDAT folded in the exe
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@2@XZ 0x1407ac500 ; manual: identical-body COMDAT folded in the exe
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x1407ac580 ; manual: identical-body COMDAT folded in the exe
// MS2-PIN: ?_Umove@?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@AEAAPEAU?$pair@HH@2@PEAU32@00@Z 0x1407ac9f0 ; manual: identical-body COMDAT folded in the exe
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@XZ 0x1407acad0 ; manual: identical-body COMDAT folded in the exe
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@XZ 0x1407acd20 ; manual: identical-body COMDAT folded in the exe
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@IPEAVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIPEAVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x1407ad100 ; manual: map size (was mispinned as set<unsigned>)
// MS2-PIN: ??_G?$MS2Ptr@USlotInfo@ItemCloset@@@@QEAAPEAXI@Z 0x1407ab4c0 ; manual: scalar deleting dtor, size 0x10
// MS2-PIN: ??_GCSAdventureLevelMission@@UEAAPEAXI@Z 0x1407ab500 ; manual
// MS2-PIN: ??_GSlotInfo@ItemCloset@@UEAAPEAXI@Z 0x1407ab540 ; manual
// MS2-PIN: ??_GStringIdInterface@@UEAAPEAXI@Z 0x1407ab580 ; manual
// MS2-PIN: ??_GStringIdInterfaceBase@@UEAAPEAXI@Z 0x1407ab5c0 ; manual
#define MS2_THIS_FILE "" // No original source path recovered; no unit-file assertions here.
#include "ms2/placeholder/ms2stdafx.h"
#include <atltime.h>
#include <atlcoll.h>
#include <map>
#include <vector>
#include <set>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/stringidinterface.h"
#include "ms2/placeholder/itemcloset.h"
#include "ms2/placeholder/csadventurelevelmission.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// ---- unrecovered neighbours -------------------------------------------------------------------------------------
CInputStream& FUN_14070f440(CInputStream&, long&);              // packet.cpp stream operators
CInputStream& FUN_14070f480(CInputStream&, unsigned int&);
CInputStream& FUN_14070f4c0(CInputStream&, __int64&);
CInputStream& FUN_14070f5f0(CInputStream&, CStringW&);
COutputStream& FUN_14070f960(COutputStream&, long);
COutputStream& FUN_14070f9a0(COutputStream&, unsigned int);
COutputStream& FUN_14070f9e0(COutputStream&, __int64);
COutputStream& FUN_14070fae0(COutputStream&, const CStringW&);
CStringW FUN_14028de60(int stringId);
void FUN_14084f270(const StringIdInterfaceBase&, COutputStream&);   // serializes a StringIdInterfaceBase
CStringW FUN_14016a730(const char*, int);                           // FormatStringId(id) without arguments

// ---- time / category text ---------------------------------------------------------------------------------------
// @0x1407a4f20
CString FUN_1407a4f20(CMsTime& time)
{
    int year = time.GetYear();
    int month = time.GetMonth();
    int day = time.GetDay();
    int hour = time.GetHour();
    int minute = time.GetMinute();
    int second = time.GetSecond();
    return Unk_SocketFormat("{0:04d}:{1:02d}:{2:02d} {3:02d}:{4:02d}:{5:02d}", year, month, day, hour, minute, second);
}
// @0x1407a4ff0
unsigned int FUN_1407a4ff0(CString& name)
{
    unsigned int mask = 0;
    if (name.CompareNoCase("all") == 0) mask |= 0xf;
    else if (name.CompareNoCase("center") == 0) mask |= 1;
    else if (name.CompareNoCase("game") == 0) mask |= 4;
    else if (name.CompareNoCase("dungeon") == 0) mask |= 8;
    else if (name.CompareNoCase("login") == 0) mask |= 2;
    return mask;
}
// @0x1407a50c0
CString FUN_1407a50c0(unsigned int mask)
{
    CString text;
    if ((mask & 1) != 0) text += "[center]";
    if ((mask & 2) != 0) text += "[login]";
    if ((mask & 4) != 0) text += "[game(normal)]";
    if ((mask & 8) != 0) text += "[game(dungeon)]";
    return text;
}
// @0x1407a51a0
CString FUN_1407a51a0(int command)
{
    CString text;
    switch (command) {
    case 0: text = L"/setservertime"; break;
    case 2: text = L"/addservertime"; break;
    case 1: text = L"/resetservertime"; break;
    default: text = L"unknown"; break;
    }
    return text;
}

// ---- payload serializers: encode(value, COutputStream&), decode(value, CInPacket& / CInputStream&) -------------------
struct Unk_1407a5270 { __int64 m_00; unsigned char m_08; };
// @0x1407a5270
void FUN_1407a5270(Unk_1407a5270& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_1(v.m_08);
}
// @0x1407a52c0
void FUN_1407a52c0(Unk_1407a5270& v, CInPacket& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_1();
}
struct Unk_1407a5330 {
    __int64 m_00, m_08; CStringW m_10, m_18; int m_20, m_24, m_28, m_2c, m_30, m_34; CString m_38; __int64 m_40; int m_48, m_4c, m_50, m_54;
};
// @0x1407a5330
void FUN_1407a5330(Unk_1407a5330& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_4(v.m_08);
    out.vfunc_o10_8(v.m_10);
    bool empty = v.m_18.IsEmpty();
    out.vfunc_o10_1(empty);
    if (empty) out.vfunc_o10_3(v.m_48);
    else out.vfunc_o10_8(v.m_18);
    out.vfunc_o10_3(v.m_20);
    out.vfunc_o10_1(v.m_34);
    out.vfunc_o10_3(v.m_30);
    if (v.m_20 == 3) out.vfunc_o10_6(v.m_38);
    else if (v.m_20 == 0x14) out.vfunc_o10_4(v.m_40);
    else if (v.m_20 == 0x10 || v.m_20 == 0x19) out.vfunc_o10_3(v.m_50);
    out.vfunc_o10_1(v.m_4c);
}
// @0x1407a5500
void FUN_1407a5500(Unk_1407a5330& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_4();
    v.m_10 = in.vfunc_o8_8();
    if (in.vfunc_o8_1() == 0) {
        v.m_18 = in.vfunc_o8_8();
    } else {
        v.m_48 = in.vfunc_o8_3();
        v.m_18 = FUN_14028de60(v.m_48);
    }
    v.m_20 = in.vfunc_o8_3();
    v.m_34 = in.vfunc_o8_1();
    v.m_30 = in.vfunc_o8_3();
    if (v.m_20 == 3) v.m_38 = in.vfunc_o8_6();
    else if (v.m_20 == 0x14) v.m_40 = in.vfunc_o8_4();
    else if (v.m_20 == 0x10 || v.m_20 == 0x19) v.m_50 = in.vfunc_o8_3();
    v.m_4c = in.vfunc_o8_1();
}

struct Unk_1407a5820 {
    __int64 m_00; int m_08, m_0c; __int64 m_10; CStringW m_18, m_20;
    Unk_1407a5820();
};
// @0x1407a5820
Unk_1407a5820::Unk_1407a5820() : m_00(0), m_08(0), m_0c(0), m_10(0) {}
// @0x1407a5890
void FUN_1407a5890(Unk_1407a5820& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_3(v.m_08);
    out.vfunc_o10_3(v.m_0c);
    out.vfunc_o10_4(v.m_10);
    out.vfunc_o10_8(v.m_18);
    out.vfunc_o10_8(v.m_20);
}
// @0x1407a5960
void FUN_1407a5960(Unk_1407a5820& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_3();
    v.m_0c = in.vfunc_o8_3();
    v.m_10 = in.vfunc_o8_4();
    v.m_18 = in.vfunc_o8_8();
    v.m_20 = in.vfunc_o8_8();
}

struct Unk_1407a5a80 {
    int m_00, m_04;
    Unk_1407a5a80();
};
// @0x1407a5a80
Unk_1407a5a80::Unk_1407a5a80() : m_00(0), m_04(0) {}
// @0x1407a5ab0
void FUN_1407a5ab0(Unk_1407a5a80& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_3(v.m_04);
}
// @0x1407a5b00
void FUN_1407a5b00(Unk_1407a5a80& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_04 = in.vfunc_o8_3();
}

struct Unk_1407a5b50 {
    int m_00;
    Unk_1407a5b50();
};
// @0x1407a5b50
Unk_1407a5b50::Unk_1407a5b50() : m_00(0) {}
// @0x1407a5b70
void FUN_1407a5b70(Unk_1407a5b50& v, COutputStream& out) { out.vfunc_o10_3(v.m_00); }
// @0x1407a5ba0
void FUN_1407a5ba0(Unk_1407a5b50& v, CInputStream& in) { v.m_00 = in.vfunc_o8_3(); }

struct Unk_1407a5bd0 {
    std::vector<std::pair<int,int> > list;
    Unk_1407a5bd0();
};
// @0x1407a5bd0
Unk_1407a5bd0::Unk_1407a5bd0() {}
// @0x1407a5c00
void FUN_1407a5c00(Unk_1407a5bd0& v, COutputStream& out)
{
    unsigned short count = (unsigned short)v.list.size();
    out.vfunc_o10_2(count);
    for (unsigned short i = 0; i < count; i++) {
        out.vfunc_o10_3(v.list[i].first);
        out.vfunc_o10_3(v.list[i].second);
    }
}
// @0x1407a5cd0
void FUN_1407a5cd0(Unk_1407a5bd0& v, CInputStream& in)
{
    unsigned short count = in.vfunc_o8_2();
    v.list.clear();
    for (unsigned short i = 0; i < count; i++) {
        int first = in.vfunc_o8_3();
        int second = in.vfunc_o8_3();
        v.list.push_back(std::make_pair(first, second));
    }
}

struct Unk_1407a5d80 {
    int m_00, m_04, m_08; short m_0c; int m_10, m_14;
    Unk_1407a5d80();
};
// @0x1407a5d80
Unk_1407a5d80::Unk_1407a5d80() : m_00(0), m_04(0), m_08(0), m_0c(0), m_10(0), m_14(0) {}
// @0x1407a5de0
void FUN_1407a5de0(Unk_1407a5d80& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_1(v.m_04);
    out.vfunc_o10_3(v.m_08);
    out.vfunc_o10_2(v.m_0c);
    out.vfunc_o10_1(v.m_10);
    if (v.m_10 != 0) out.vfunc_o10_3(v.m_14);
}
// @0x1407a5ea0
void FUN_1407a5ea0(Unk_1407a5d80& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_04 = in.vfunc_o8_1();
    v.m_08 = in.vfunc_o8_3();
    v.m_0c = in.vfunc_o8_2();
    v.m_10 = in.vfunc_o8_1();
    if (v.m_10 != 0) v.m_14 = in.vfunc_o8_3();
}

struct Unk_1407a5f60 { bool m_00; __int64 m_08; CStringW m_10; };
// @0x1407a5f60
void FUN_1407a5f60(Unk_1407a5f60& v, COutputStream& out)
{
    out.vfunc_o10_1(v.m_00);
    out.vfunc_o10_4(v.m_08);
    out.vfunc_o10_8(v.m_10);
}
// @0x1407a5fd0
void FUN_1407a5fd0(Unk_1407a5f60& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_1() == 1;
    v.m_08 = in.vfunc_o8_4();
    v.m_10 = in.vfunc_o8_8();
}

struct Unk_1407a6090 { int m_00, m_04; short m_08; CStringW m_10; };
// @0x1407a6090
void FUN_1407a6090(Unk_1407a6090& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_3(v.m_04);
    out.vfunc_o10_2(v.m_08);
    out.vfunc_o10_8(v.m_10);
}
// @0x1407a6120
void FUN_1407a6120(Unk_1407a6090& v, CInPacket& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_04 = in.vfunc_o8_3();
    v.m_08 = in.vfunc_o8_2();
    v.m_10 = in.vfunc_o8_8();
}

struct Unk_1407a6220 { int m_00; short m_04; CStringW m_08; };
// @0x1407a6220
void FUN_1407a6220(Unk_1407a6220& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_2(v.m_04);
    out.vfunc_o10_8(v.m_08);
}
// @0x1407a6290
void FUN_1407a6290(Unk_1407a6220& v, CInPacket& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_04 = in.vfunc_o8_2();
    v.m_08 = in.vfunc_o8_8();
}
// @0x1407a6360
void FUN_1407a6360(Unk_1407a5a80& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_3(v.m_04);
}
// @0x1407a63b0
void FUN_1407a63b0(Unk_1407a5a80& v, CInPacket& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_04 = in.vfunc_o8_3();
}

// @0x1407a6420
void FUN_1407a6420(const ATL::CAtlArray<unsigned __int64>& ids, COutputStream& out)
{
    int count = (int)ids.GetCount();
    out.vfunc_o10_3(count);
    for (int i = 0; i < count; i = i + 1) out.vfunc_o10_4(ids[i]);
}
// @0x1407a64b0
void FUN_1407a64b0(ATL::CAtlArray<unsigned __int64>& ids, CInPacket& in)
{
    int count = in.vfunc_o8_3();
    for (int i = 0; i < count; i = i + 1) {
        unsigned __int64 id = in.vfunc_o8_4();
        ids.Add(id);
    }
}
// @0x1407a6540
void FUN_1407a6540(Unk_1407a5b50& v, COutputStream& out) { out.vfunc_o10_3(v.m_00); }
// @0x1407a6570
void FUN_1407a6570(Unk_1407a5b50& v, CInPacket& in) { v.m_00 = in.vfunc_o8_3(); }

struct Unk_1407a65c0 { __int64 m_00, m_08, m_10; int m_18; CStringW m_20; __int64 m_28, m_30; };
// @0x1407a65c0
void FUN_1407a65c0(Unk_1407a65c0& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_4(v.m_08);
    out.vfunc_o10_4(v.m_10);
    out.vfunc_o10_3(v.m_18);
    out.vfunc_o10_8(v.m_20);
    out.vfunc_o10_4(v.m_28);
    out.vfunc_o10_4(v.m_30);
}
// @0x1407a66a0
void FUN_1407a66a0(Unk_1407a65c0& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_4();
    v.m_10 = in.vfunc_o8_4();
    v.m_18 = in.vfunc_o8_3();
    v.m_20 = in.vfunc_o8_8();
    v.m_28 = in.vfunc_o8_4();
    v.m_30 = in.vfunc_o8_4();
}

struct Unk_1407a67a0 { __int64 m_00, m_08; };
// @0x1407a67a0
void FUN_1407a67a0(Unk_1407a67a0& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_4(v.m_08);
}
// @0x1407a67f0
void FUN_1407a67f0(Unk_1407a67a0& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_4();
}

struct Unk_1407a6840 { __int64 m_00; unsigned __int64 m_08; };
// @0x1407a6840
void FUN_1407a6840(Unk_1407a6840& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_3((int)v.m_08);
}
// @0x1407a6890
void FUN_1407a6890(Unk_1407a6840& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = (unsigned int)in.vfunc_o8_3();
}

struct Unk_1407a68e0 { __int64 m_00, m_08, m_10, m_18, m_20, m_28; };
// @0x1407a68e0
void FUN_1407a68e0(Unk_1407a68e0& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_4(v.m_08);
    out.vfunc_o10_4(v.m_10);
    out.vfunc_o10_4(v.m_18);
    out.vfunc_o10_4(v.m_20);
    out.vfunc_o10_4(v.m_28);
}
// @0x1407a6990
void FUN_1407a6990(Unk_1407a68e0& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_4();
    v.m_10 = in.vfunc_o8_4();
    v.m_18 = in.vfunc_o8_4();
    v.m_20 = in.vfunc_o8_4();
    v.m_28 = in.vfunc_o8_4();
}

struct Unk_1407a6a40 { __int64 m_00, m_08, m_10; };
// @0x1407a6a40
void FUN_1407a6a40(Unk_1407a6a40& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_4(v.m_08);
    out.vfunc_o10_4(v.m_10);
}
// @0x1407a6ab0
void FUN_1407a6ab0(Unk_1407a6a40& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_4();
    v.m_10 = in.vfunc_o8_4();
}

struct Unk_1407a6b20 { int m_00, m_04; __int64 m_08, m_10; CStringW m_18, m_20; };
// @0x1407a6b20
void FUN_1407a6b20(Unk_1407a6b20& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_3(v.m_04);
    out.vfunc_o10_4(v.m_08);
    out.vfunc_o10_4(v.m_10);
    out.vfunc_o10_8(v.m_18);
    out.vfunc_o10_8(v.m_20);
}
// @0x1407a6bf0
void FUN_1407a6bf0(Unk_1407a6b20& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_04 = in.vfunc_o8_3();
    v.m_08 = in.vfunc_o8_4();
    v.m_10 = in.vfunc_o8_4();
    v.m_18 = in.vfunc_o8_8();
    v.m_20 = in.vfunc_o8_8();
}

struct Unk_1407a6d10 { int m_00; int m_04; };
// @0x1407a6d10
void FUN_1407a6d10(Unk_1407a6d10& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_1((unsigned char)v.m_04);
}
// @0x1407a6d60
void FUN_1407a6d60(Unk_1407a6d10& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_04 = in.vfunc_o8_1();
}

struct Unk_1407a6db0 { __int64 m_00; int m_08; };
// @0x1407a6db0
void FUN_1407a6db0(Unk_1407a6db0& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_3(v.m_08);
}
// @0x1407a6e00
void FUN_1407a6e00(Unk_1407a6db0& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_3();
}
// @0x1407a6e50
void FUN_1407a6e50(Unk_1407a6db0& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_3(v.m_08);
}
// @0x1407a6ea0
void FUN_1407a6ea0(Unk_1407a6db0& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_3();
}
// @0x1407a6ef0
void FUN_1407a6ef0(Unk_1407a6db0& v, COutputStream& out)
{
    FUN_14070f9e0(out, v.m_00);
    FUN_14070f960(out, v.m_08);
}
// @0x1407a6f30
void FUN_1407a6f30(Unk_1407a6db0& v, CInputStream& in)
{
    FUN_14070f4c0(in, v.m_00);
    FUN_14070f440(in, (long&)v.m_08);
}

struct Unk_1407a6f80 { long m_00, m_04; CStringW m_08; };
// @0x1407a6f80
void FUN_1407a6f80(Unk_1407a6f80& v, COutputStream& out)
{
    FUN_14070f960(out, v.m_00);
    FUN_14070f960(out, v.m_04);
    FUN_14070fae0(out, v.m_08);
}
// @0x1407a6fe0
void FUN_1407a6fe0(Unk_1407a6f80& v, CInputStream& in)
{
    FUN_14070f440(in, v.m_00);
    FUN_14070f440(in, v.m_04);
    FUN_14070f5f0(in, v.m_08);
}

struct Unk_1407a71a0 { unsigned int m_00; ATL::CAtlArray<unsigned __int64> m_08; };
struct Unk_1407a7040 : Unk_1407a71a0 { Unk_1407a6f80 m_28; };
// @0x1407a7040
void FUN_1407a7040(Unk_1407a7040& v, COutputStream& out)
{
    FUN_1407a6f80(v.m_28, out);
    int count = (int)v.m_08.GetCount();
    FUN_14070f9a0(out, v.m_00);
    FUN_14070f960(out, count);
    for (int i = 0; i < count; i = i + 1) FUN_14070f9e0(out, v.m_08[i]);
}
// @0x1407a70f0
void FUN_1407a70f0(Unk_1407a7040& v, CInputStream& in)
{
    FUN_1407a6fe0(v.m_28, in);
    int count = 0;
    FUN_14070f480(in, v.m_00);
    FUN_14070f440(in, (long&)count);
    for (int i = 0; i < count; i = i + 1) {
        unsigned __int64 id = 0;
        FUN_14070f4c0(in, (__int64&)id);
        v.m_08.Add(id);
    }
}
// @0x1407a71a0
void FUN_1407a71a0(Unk_1407a71a0& v, COutputStream& out)
{
    int count = (int)v.m_08.GetCount();
    FUN_14070f9a0(out, v.m_00);
    FUN_14070f960(out, count);
    for (int i = 0; i < count; i = i + 1) FUN_14070f9e0(out, v.m_08[i]);
}
// @0x1407a7230
void FUN_1407a7230(Unk_1407a71a0& v, CInputStream& in)
{
    int count = 0;
    FUN_14070f480(in, v.m_00);
    FUN_14070f440(in, (long&)count);
    for (int i = 0; i < count; i = i + 1) {
        unsigned __int64 id = 0;
        FUN_14070f4c0(in, (__int64&)id);
        v.m_08.Add(id);
    }
}

struct Unk_1407a72c0 { CString m_00, m_08; };
// @0x1407a72c0
void FUN_1407a72c0(Unk_1407a72c0& v, COutputStream& out)
{
    out.vfunc_o10_6(v.m_00);
    out.vfunc_o10_6(v.m_08);
}
// @0x1407a7330
void FUN_1407a7330(Unk_1407a72c0& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_6();
    v.m_08 = in.vfunc_o8_6();
}

// @0x1407a73e0
void FUN_1407a73e0(Unk_1407a6db0& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_3(v.m_08);
}
// @0x1407a7430
void FUN_1407a7430(Unk_1407a6db0& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_3();
}

struct Unk_1407a7480 { __int64 m_00; int m_08; CStringW m_10; __int64 m_18, m_20; };
// @0x1407a7480
void FUN_1407a7480(Unk_1407a7480& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_1((unsigned char)v.m_08);
    out.vfunc_o10_8(v.m_10);
    out.vfunc_o10_4(v.m_18);
    out.vfunc_o10_4(v.m_20);
}
// @0x1407a7530
void FUN_1407a7530(Unk_1407a7480& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_1();
    v.m_10 = in.vfunc_o8_8();
    v.m_18 = in.vfunc_o8_4();
    v.m_20 = in.vfunc_o8_4();
}

struct Unk_1407a7600 { __int64 m_00; };
// @0x1407a7600
void FUN_1407a7600(Unk_1407a7600& v, COutputStream& out) { out.vfunc_o10_4(v.m_00); }
// @0x1407a7640
void FUN_1407a7640(Unk_1407a7600& v, CInputStream& in) { v.m_00 = in.vfunc_o8_4(); }

struct Unk_1407a7680 { __int64 m_00; CStringW m_08; };
// @0x1407a7680
void FUN_1407a7680(Unk_1407a7680& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_8(v.m_08);
}
// @0x1407a76e0
void FUN_1407a76e0(Unk_1407a7680& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_8();
}

struct Unk_1407a7770 { __int64 m_00; unsigned char m_08; CStringW m_10; int m_18; };
// @0x1407a7770
void FUN_1407a7770(Unk_1407a7770& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_1(v.m_08);
    out.vfunc_o10_8(v.m_10);
    out.vfunc_o10_3(v.m_18);
}
// @0x1407a7800
void FUN_1407a7800(Unk_1407a7770& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_1();
    v.m_10 = in.vfunc_o8_8();
    v.m_18 = in.vfunc_o8_3();
}
// @0x1407a78c0
void FUN_1407a78c0(Unk_1407a7680& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_8(v.m_08);
}
// @0x1407a7920
void FUN_1407a7920(Unk_1407a7680& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_8();
}
// @0x1407a79b0
void FUN_1407a79b0(Unk_1407a6db0& v, COutputStream& out)
{
    out.vfunc_o10_4(v.m_00);
    out.vfunc_o10_3(v.m_08);
}
// @0x1407a7a00
void FUN_1407a7a00(Unk_1407a6db0& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_4();
    v.m_08 = in.vfunc_o8_3();
}

// ---- COutSendNoticePacket: opcode 0x71, notice kind byte, flags, a StringIdInterfaceBase body, optional extra short -------
class COutSendNoticePacket : public COutPacket {
public:
    COutSendNoticePacket(unsigned char kind, int flags, CString text, unsigned short extra);
    COutSendNoticePacket(unsigned char kind, int flags, unsigned int stringId, unsigned short extra);
    COutSendNoticePacket(unsigned char kind, int flags, StringIdInterfaceBase& body, unsigned short extra);
};
// @0x1407a9940
void FUN_1407a9940(COutPacket& packet, StringIdInterfaceBase& body) { FUN_14084f270(body, packet); }
// @0x1407a7a50
COutSendNoticePacket::COutSendNoticePacket(unsigned char kind, int flags, CString text, unsigned short extra)
    : COutPacket(0x71, 0)
{
    Encode1(kind);
    Encode2(flags);
    const StringIdInterfaceBase& body = StringIdInterfaceBase(FUN_14016a730((const char*)text, 0));
    FUN_1407a9940(*this, const_cast<StringIdInterfaceBase&>(body));
    if ((flags & 0x10) != 0) Encode2(extra);
}
// @0x1407a7b80
COutSendNoticePacket::COutSendNoticePacket(unsigned char kind, int flags, unsigned int stringId, unsigned short extra)
    : COutPacket(0x71, 0)
{
    Encode1(kind);
    Encode2(flags);
    const StringIdInterfaceBase& body = StringIdInterfaceBase(1, stringId);
    FUN_1407a9940(*this, const_cast<StringIdInterfaceBase&>(body));
    if ((flags & 0x10) != 0) Encode2(extra);
}
// @0x1407a7c80
COutSendNoticePacket::COutSendNoticePacket(unsigned char kind, int flags, StringIdInterfaceBase& body, unsigned short extra)
    : COutPacket(0x71, 0)
{
    Encode1(kind);
    Encode2(flags);
    FUN_1407a9940(*this, body);
    if ((flags & 0x10) != 0) Encode2(extra);
}

// ---- decoders that build their object from a CInPacket (StringIdInterface text) ----------------------------------
struct Unk_1407a7d20 {
    unsigned char m_00; unsigned m_04; CStringW m_08; unsigned m_10; ATL::CAtlArray<void*> m_18;
    Unk_1407a7d20(CInPacket& in);
};
// @0x1407a7d20
Unk_1407a7d20::Unk_1407a7d20(CInPacket& in) : m_10(0)
{
    m_00 = in.vfunc_o8_1();
    m_04 = (unsigned short)in.vfunc_o8_2();
    StringIdInterface body(in);
    m_08 = body.FUN_141024e60();
    if ((m_04 & 0x10) != 0) m_10 = (unsigned short)in.vfunc_o8_2();
}
struct Unk_1407a7eb0 {
    __int64 m_00; CStringW m_08; unsigned char m_10; CStringW m_18;
    Unk_1407a7eb0(CInPacket& in);
};
// @0x1407a7eb0
Unk_1407a7eb0::Unk_1407a7eb0(CInPacket& in)
{
    m_00 = in.vfunc_o8_4();
    m_08 = in.vfunc_o8_8();
    m_10 = in.vfunc_o8_1();
    StringIdInterface body(in);
    m_18 = body.FUN_141024e60();
}

struct Unk_1407a8050 { int m_00, m_04; __int64 m_08; int m_10; int m_14; int m_18; };
// @0x1407a8050
void FUN_1407a8050(Unk_1407a8050& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_3(v.m_04);
    out.vfunc_o10_4(v.m_08);
    out.vfunc_o10_1((unsigned char)v.m_10);
    out.vfunc_o10_3(v.m_14);
    out.vfunc_o10_1((unsigned char)v.m_18);
}
// @0x1407a8100
void FUN_1407a8100(Unk_1407a8050& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_04 = in.vfunc_o8_3();
    v.m_08 = in.vfunc_o8_4();
    v.m_10 = in.vfunc_o8_1();
    v.m_14 = in.vfunc_o8_3();
    v.m_18 = in.vfunc_o8_1();
}

struct Unk_1407a81b0 { int m_00; __int64 m_08, m_10, m_18; bool m_20; };
// @0x1407a81b0
void FUN_1407a81b0(Unk_1407a81b0& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_4(v.m_08);
    out.vfunc_o10_4(v.m_10);
    out.vfunc_o10_4(v.m_18);
    out.vfunc_o10_0(v.m_20);
}
// @0x1407a8250
void FUN_1407a8250(Unk_1407a81b0& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_08 = in.vfunc_o8_4();
    v.m_10 = in.vfunc_o8_4();
    v.m_18 = in.vfunc_o8_4();
    v.m_20 = in.vfunc_o8_0();
}

struct Unk_1407a82f0 { int m_00; __int64 m_08; };
// @0x1407a82f0
void FUN_1407a82f0(Unk_1407a82f0& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_4(v.m_08);
}
// @0x1407a8340
void FUN_1407a8340(Unk_1407a82f0& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_08 = in.vfunc_o8_4();
}

// ---- ItemCloset ----------------------------------------------------------------------------------------------------
// @0x1407aaf00
ItemCloset::SlotInfo::SlotInfo() : m_itemId(0), m_20(0), m_24(0), m_28(0) {}
// @0x1407ab010
ItemCloset::SlotInfo::~SlotInfo() {}
// @0x1407a8390
void ItemCloset::SlotInfo::FUN_1407a8390(COutputStream& out) const
{
    out.vfunc_o10_4(m_itemId);
    out.vfunc_o10_3(m_20);
    out.vfunc_o10_3(m_24);
    out.vfunc_o10_3(m_28);
}
// @0x1407a8410
void ItemCloset::SlotInfo::FUN_1407a8410(CInPacket& in)
{
    m_itemId = in.vfunc_o8_4();
    m_20 = in.vfunc_o8_3();
    m_24 = in.vfunc_o8_3();
    m_28 = in.vfunc_o8_3();
}
// @0x1407a84e0
void ItemCloset::TabInfo::FUN_1407a84e0(COutputStream& out) const
{
    out.vfunc_o10_3(m_18);
    out.vfunc_o10_3(m_1c);
    out.vfunc_o10_3(m_20);
    out.vfunc_o10_8(m_name);
    out.vfunc_o10_3((int)m_slots.GetCount());
    for (unsigned i = 0; i < m_slots.GetCount(); i = i + 1) m_slots[i]->FUN_1407a8390(out);
}
// @0x1407a8600
void ItemCloset::TabInfo::FUN_1407a8600(CInPacket& in)
{
    m_18 = in.vfunc_o8_3();
    m_1c = in.vfunc_o8_3();
    m_20 = in.vfunc_o8_3();
    m_name = in.vfunc_o8_8();
    unsigned count = in.vfunc_o8_3();
    m_slots.SetCount(count, -1);
    for (unsigned i = 0; i < count; i = i + 1) {
        SlotInfo* slot = new SlotInfo();
        m_slots[i].AssignRaw(slot)->FUN_1407a8410(in);
    }
}

// ---- tagged payload: kind byte, then one of four bodies (0: ids + set, 1: two ids, 2: two ints, 4: flag + set) -----------
struct Unk_1407a8820 {
    unsigned int m_00;
    __int64 m_08;
    int m_10;
    __int64 m_18;
    std::set<unsigned int> m_20;
    __int64 m_30;
    int m_38, m_3c, m_40;
};
// @0x1407a8820
void FUN_1407a8820(Unk_1407a8820& v, COutputStream& out)
{
    out.vfunc_o10_1((unsigned char)v.m_00);
    if (v.m_00 == 0) {
        out.vfunc_o10_4(v.m_08);
        out.vfunc_o10_3(v.m_10);
        out.vfunc_o10_4(v.m_18);
        out.vfunc_o10_3((unsigned int)v.m_20.size());
        for (std::set<unsigned int>::iterator it = v.m_20.begin(); it != v.m_20.end(); ++it) out.vfunc_o10_3(*it);
    }
    else if (v.m_00 == 1) {
        out.vfunc_o10_4(v.m_08);
        out.vfunc_o10_4(v.m_30);
    }
    else if (v.m_00 == 2) {
        out.vfunc_o10_3(v.m_3c);
        out.vfunc_o10_3(v.m_38);
    }
    else if (v.m_00 == 4) {
        out.vfunc_o10_1((unsigned char)v.m_40);
        out.vfunc_o10_3((unsigned int)v.m_20.size());
        for (std::set<unsigned int>::iterator it = v.m_20.begin(); it != v.m_20.end(); ++it) out.vfunc_o10_3(*it);
    }
}
// @0x1407a8b20
void FUN_1407a8b20(Unk_1407a8820& v, CInputStream& in)
{
    v.m_00 = in.vfunc_o8_1();
    switch (v.m_00) {
    case 1:
        v.m_08 = in.vfunc_o8_4();
        v.m_30 = in.vfunc_o8_4();
        break;
    case 2:
        v.m_3c = in.vfunc_o8_3();
        v.m_38 = in.vfunc_o8_3();
        break;
    case 0: {
        v.m_08 = in.vfunc_o8_4();
        v.m_10 = in.vfunc_o8_3();
        v.m_18 = in.vfunc_o8_4();
        v.m_20.clear();
        int count = in.vfunc_o8_3();
        for (int i = 0; i < count; i = i + 1) {
            v.m_20.insert(in.vfunc_o8_3());
        }
        break;
    }
    case 4: {
        v.m_40 = in.vfunc_o8_1();
        v.m_20.clear();
        int count = in.vfunc_o8_3();
        for (int i = 0; i < count; i = i + 1) {
            v.m_20.insert(in.vfunc_o8_3());
        }
        break;
    }
    }
}

// ---- adventure level mission -----------------------------------------------------------------------------------------
// @0x1407a8d50
CSAdventureLevelMission::CSAdventureLevelMission()
{
    m_kind = 8;
    m_0c = 0;
}
// @0x1407a8db0
CSAdventureLevelMission::~CSAdventureLevelMission()
{
    FUN_1407a95b0();
}
// @0x1407a8e00
void CSAdventureLevelMission::FUN_1407a8e00(COutputStream& out) const
{
    out.vfunc_o10_1((unsigned char)m_kind);
    if (m_kind == 6) {
        out.vfunc_o10_1((unsigned char)m_0c);
        out.vfunc_o10_3((unsigned int)m_missions.size());
        for (std::map<unsigned int, CAdventureLevelMissionData*>::const_iterator it = m_missions.begin(); it != m_missions.end(); ++it) {
            out.vfunc_o10_4(it->first);
            out.vfunc_o10_4(it->second->m_progress);
            out.vfunc_o10_1(it->second->m_complete);
        }
    }
    else if (m_kind == 7) {
        out.vfunc_o10_3((unsigned int)m_missions.size());
        for (std::map<unsigned int, CAdventureLevelMissionData*>::const_iterator it = m_missions.begin(); it != m_missions.end(); ++it) {
            out.vfunc_o10_4(it->first);
            out.vfunc_o10_4(it->second->m_progress);
            out.vfunc_o10_1(it->second->m_complete);
        }
    }
}
// @0x1407a90e0
void CSAdventureLevelMission::FUN_1407a90e0(CInputStream& in)
{
    m_kind = in.vfunc_o8_1();
    if (m_kind == 6) {
        m_0c = in.vfunc_o8_1();
        FUN_1407a95b0();
        unsigned __int64 count = (unsigned int)in.vfunc_o8_3();
        for (unsigned __int64 i = 0; i < count; i++) {
            CAdventureLevelMissionData* data = new CAdventureLevelMissionData();
            unsigned int id = (unsigned int)in.vfunc_o8_4();
            data->m_progress = (unsigned int)in.vfunc_o8_4();
            data->m_complete = in.vfunc_o8_1() != 0;
            m_missions.insert(std::make_pair(id, data));
        }
    }
    else if (m_kind == 7) {
        FUN_1407a95b0();
        unsigned __int64 count = (unsigned int)in.vfunc_o8_3();
        for (unsigned __int64 i = 0; i < count; i++) {
            CAdventureLevelMissionData* data = new CAdventureLevelMissionData();
            unsigned int id = (unsigned int)in.vfunc_o8_4();
            data->m_progress = (unsigned int)in.vfunc_o8_4();
            data->m_complete = in.vfunc_o8_1() != 0;
            m_missions.insert(std::make_pair(id, data));
        }
    }
}
// @0x1407a9420
void CSAdventureLevelMission::FUN_1407a9420(unsigned id, const CAdventureLevelMissionData& src)
{
    std::map<unsigned int, CAdventureLevelMissionData*>::iterator it = m_missions.find(id);
    if (it != m_missions.end()) {
        it->second->m_progress = src.m_progress;
        it->second->m_complete = src.m_complete;
        it->second->m_20 = src.m_20;
    }
    else {
        CAdventureLevelMissionData* data = new CAdventureLevelMissionData();
        data->m_progress = src.m_progress;
        data->m_complete = src.m_complete;
        data->m_20 = src.m_20;
        m_missions.insert(std::make_pair(id, data));
    }
}
// @0x1407a95b0
void CSAdventureLevelMission::FUN_1407a95b0()
{
    for (std::map<unsigned int, CAdventureLevelMissionData*>::iterator it = m_missions.begin(); it != m_missions.end(); ++it) {
        delete it->second;
        it->second = 0;
    }
    m_missions.clear();
}

struct Unk_1407a9690 {
    int m_00; unsigned __int64 m_08;
    Unk_1407a9690();
};
// @0x1407a9690
Unk_1407a9690::Unk_1407a9690() : m_00(0), m_08(0) {}
// @0x1407a96c0
void FUN_1407a96c0(Unk_1407a9690& v, COutputStream& out)
{
    out.vfunc_o10_3(v.m_00);
    out.vfunc_o10_3((int)v.m_08);
}
// @0x1407a9710
void FUN_1407a9710(Unk_1407a9690& v, CInPacket& in)
{
    v.m_00 = in.vfunc_o8_3();
    v.m_08 = (unsigned int)in.vfunc_o8_3();
}

// ---- COMDAT bodies --------------------------------------------------------------------------------------------------
StringIdInterface::~StringIdInterface() {}               // @0x1407ab030
StringIdInterfaceBase::~StringIdInterfaceBase() {}       // @0x1407ab060

// ---- hooks (functional, non-COMDAT, non-ctor bodies) ----------------------------------------------------------------
MS2_REPLACE(0x1407A5500, FUN_1407a5500, 789, 0xDF1D088C);
MS2_REPLACE(0x1407A5C00, FUN_1407a5c00, 187, 0x8C78ABA2);
MS2_REPLACE(0x1407A5CD0, FUN_1407a5cd0, 164, 0xEC56333D);
MS2_REPLACE(0x1407A6420, FUN_1407a6420, 135, 0xA8754CBE);
MS2_REPLACE(0x1407A64B0, FUN_1407a64b0, 136, 0x56ACCC94);
MS2_REPLACE(0x1407A7040, FUN_1407a7040, 160, 0xA2B671C6);
MS2_REPLACE(0x1407A70F0, FUN_1407a70f0, 160, 0x65717E46);
MS2_REPLACE(0x1407A71A0, FUN_1407a71a0, 138, 0xD9598B38);
MS2_REPLACE_METHOD(0x1407A84E0, ItemCloset::TabInfo, FUN_1407a84e0, 277, 0x6C94006F);
MS2_REPLACE_METHOD(0x1407A8600, ItemCloset::TabInfo, FUN_1407a8600, 532, 0x815D3F00);
MS2_REPLACE(0x1407A8820, FUN_1407a8820, 755, 0x74D5E0EF);
MS2_REPLACE(0x1407A8B20, FUN_1407a8b20, 543, 0x29AA898F);
MS2_REPLACE_METHOD(0x1407A8E00, CSAdventureLevelMission, FUN_1407a8e00, 723, 0x98772582);
MS2_REPLACE_METHOD(0x1407A90E0, CSAdventureLevelMission, FUN_1407a90e0, 816, 0x3E12E9CC);
MS2_REPLACE_METHOD(0x1407A9420, CSAdventureLevelMission, FUN_1407a9420, 386, 0x650C3EC3);
