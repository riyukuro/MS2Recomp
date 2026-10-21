// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIQuestDialog: see uiquestdialog.h.
// MS2-UNIT: ?\uiquestdialog.cpp
// MS2-RANGE: 0x14011b110-0x14011b480 .text$di
// MS2-RANGE: 0x141a993a0-0x141aa86e0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@6B@ 0x142fd8648
// MS2-PIN: ??__Es_strSortTypeNames2@@YAXXZ 0x14011b110 ; probe
// MS2-PIN: ??__Es_strChapterClose@@YAXXZ 0x14011b1d0 ; probe
// MS2-PIN: ??__Es_strChapterOpen@@YAXXZ 0x14011b200 ; probe
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x14011b230 ; probe
// MS2-PIN: ??__Es_strSkill2@@YAXXZ 0x14011b2b0 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x14011b2e0 ; probe
// MS2-PIN: ??__Es_strSortTypeNames@@YAXXZ 0x14011b310 ; probe
// MS2-PIN: ??__Es_strStun2@@YAXXZ 0x14011b3d0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x14011b400 ; probe
// MS2-PIN: ??__Es_unk1402a9d70b@@YAXXZ 0x14011b430 ; probe
// MS2-PIN: ??$?8PEAVUIQuestDialog@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIQuestDialog@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x141aa28b0 ; prop
// MS2-PIN: ??$?8PEAVUIQuestDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x141aa2920 ; prop
// MS2-PIN: ?Allocate@?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@PEAX@Z 0x141aa2e50 ; prop
// MS2-PIN: ?Allocate@?$TPtrValue@V?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@@@PEAX@Z 0x141aa2ec0 ; prop
// MS2-PIN: ??0?$CRBMultiMap@_JIV?$CElementTraits@_J@ATL@@V?$CElementTraits@I@2@@ATL@@QEAA@_K@Z 0x141aa3300 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x141aa3390 ; unique
// MS2-PIN: ??0?$TPtredDummy@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@QEAA@XZ 0x141aa35c0 ; prop
// MS2-PIN: ??0?$TPtredDummy@V?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@@@QEAA@XZ 0x141aa3630 ; prop
// MS2-PIN: ??1?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@@2@@ATL@@QEAA@XZ 0x141aa38f0 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAA@XZ 0x141aa39d0 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x141aa39f0 ; prop
// MS2-PIN: ??1?$TPtredDummy@V?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@@@UEAA@XZ 0x141aa3aa0 ; order
// MS2-PIN: ?Value@?$TPtrValue@V?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@@@CAPEAV?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@PEAV?$TPtredDummy@V?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@@@@Z 0x141aa3d20 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VAScript@@@@QEBAPEAVAScript@@XZ 0x141aa3d60 ; order
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAPEAXI@Z 0x141aa3de0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x141aa3e20 ; prop
// MS2-PIN: ??_G?$TPtredDummy@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@UEAAPEAXI@Z 0x141aa3e60 ; order
// MS2-PIN: ??_G?$TPtredDummy@V?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@@@UEAAPEAXI@Z 0x141aa3ea0 ; order
// MS2-PIN: ??4?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@QEAAAEAV0@AEBUUnk_GrNewTag@@@Z 0x141aa4020 ; order
// MS2-PIN: ??4?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@QEAAAEAV0@AEBUUnk_GrNewTag@@@Z 0x141aa4050 ; order
// MS2-PIN: ??4?$TPtrValue@V?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@@@QEAAAEAV0@AEBUUnk_GrNewTag@@@Z 0x141aa4080 ; order
// MS2-PIN: ?GetKeyAt@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@QEBAAEBHPEAU__POSITION@@@Z 0x141aa49e0 ; order
// MS2-PIN: ?GetKeyAt@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@@2@@ATL@@QEBAAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@PEAU__POSITION@@@Z 0x141aa4a50 ; order
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141aa4e80 ; order
// MS2-PIN: ?GetStartPosition@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x141aa4ef0 ; order
// MS2-PIN: ?vfunc_48@UIQuestDialog@@UEAAHXZ 0x141aa4f60 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@QEAAAEAV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@PEAU__POSITION@@@Z 0x141aa4f70 ; order
// MS2-PIN: ?GetValueAt@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@@2@@ATL@@QEAAAEAV?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@PEAU__POSITION@@@Z 0x141aa4fe0 ; order
// MS2-PIN: ?IsEmpty@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@@2@@ATL@@QEBA_NXZ 0x141aa55a0 ; order
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@@@@3@@ATL@@@@@2@@ATL@@QEAAXMMM_N@Z 0x141aa7ba0 ; prop
// MS2-PIN: ?Make@?$TPtrValue@V?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@@@AEAAXXZ 0x141aa81a0 ; prop
// MS2-PIN: ?Create@?$TPtrValue@V?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@@@CAPEAV?$CAtlMap@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@PEAX@Z 0x141aa8200 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141aa8350 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141aa83b0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141aa8440 ; unique
// MS2-PIN: ??$Call@VUIQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x141aa84c0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141aa8500 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIQuestDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141aa8560 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquestdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiquestdialog.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdlib.h>

extern __int64 DAT_143ab2828;                                   // the character id

MS2_EMIT_CRT_MEMMOVE_S();

// The header statics of this unit: the sort-name / skill / stun strings and the condition, the key input controller,
// the two chapter sounds, then the first group again.
#include "ms2/placeholder/header_statics_a.h"
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strChapterClose("QuestChapter_Close");
static CString s_strChapterOpen("QuestChapter_Open");
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);

// ---- out-of-unit callees (names describe uses) ----
using ATL::CAtlArray;
template<> Unk_PayloadPtr<CQuest>::~Unk_PayloadPtr();
template<> CQuest* Unk_PayloadPtr<CQuest>::get() const;
template<> CQuest* Unk_PayloadPtr<CQuest>::operator->() const;
template<> Unk_PayloadPtr<CQuest>::Unk_PayloadPtr(const Unk_PayloadPtr&);

// The local player: only the level getter (slot 78) is used.
class Unk_QdActor
{
public:
    virtual ~Unk_QdActor();
    virtual void Unk_Slot0();
    virtual void Unk_Slot1();
    virtual void Unk_Slot2();
    virtual void Unk_Slot3();
    virtual void Unk_Slot4();
    virtual void Unk_Slot5();
    virtual void Unk_Slot6();
    virtual void Unk_Slot7();
    virtual void Unk_Slot8();
    virtual void Unk_Slot9();
    virtual void Unk_Slot10();
    virtual void Unk_Slot11();
    virtual void Unk_Slot12();
    virtual void Unk_Slot13();
    virtual void Unk_Slot14();
    virtual void Unk_Slot15();
    virtual void Unk_Slot16();
    virtual void Unk_Slot17();
    virtual void Unk_Slot18();
    virtual void Unk_Slot19();
    virtual void Unk_Slot20();
    virtual void Unk_Slot21();
    virtual void Unk_Slot22();
    virtual void Unk_Slot23();
    virtual void Unk_Slot24();
    virtual void Unk_Slot25();
    virtual void Unk_Slot26();
    virtual void Unk_Slot27();
    virtual void Unk_Slot28();
    virtual void Unk_Slot29();
    virtual void Unk_Slot30();
    virtual void Unk_Slot31();
    virtual void Unk_Slot32();
    virtual void Unk_Slot33();
    virtual void Unk_Slot34();
    virtual void Unk_Slot35();
    virtual void Unk_Slot36();
    virtual void Unk_Slot37();
    virtual void Unk_Slot38();
    virtual void Unk_Slot39();
    virtual void Unk_Slot40();
    virtual void Unk_Slot41();
    virtual void Unk_Slot42();
    virtual void Unk_Slot43();
    virtual void Unk_Slot44();
    virtual void Unk_Slot45();
    virtual void Unk_Slot46();
    virtual void Unk_Slot47();
    virtual void Unk_Slot48();
    virtual void Unk_Slot49();
    virtual void Unk_Slot50();
    virtual void Unk_Slot51();
    virtual void Unk_Slot52();
    virtual void Unk_Slot53();
    virtual void Unk_Slot54();
    virtual void Unk_Slot55();
    virtual void Unk_Slot56();
    virtual void Unk_Slot57();
    virtual void Unk_Slot58();
    virtual void Unk_Slot59();
    virtual void Unk_Slot60();
    virtual void Unk_Slot61();
    virtual void Unk_Slot62();
    virtual void Unk_Slot63();
    virtual void Unk_Slot64();
    virtual void Unk_Slot65();
    virtual void Unk_Slot66();
    virtual void Unk_Slot67();
    virtual void Unk_Slot68();
    virtual void Unk_Slot69();
    virtual void Unk_Slot70();
    virtual void Unk_Slot71();
    virtual void Unk_Slot72();
    virtual void Unk_Slot73();
    virtual void Unk_Slot74();
    virtual void Unk_Slot75();
    virtual void Unk_Slot76();
    virtual void Unk_Slot77();
    virtual unsigned short vfunc_78();                  // 0x270 the level
};
class Unk_QdWorld
{
public:
    Unk_QdActor* FUN_141bd0cc0();                       // the local player
    int FUN_141bd3060();                                // the current map id
    void FUN_141bd3880();
};
Unk_QdWorld* FUN_1403ed2d0();
class Unk_QdUIMgr { public: void FUN_141adc530(int nUIType); };
Unk_QdUIMgr* FUN_1403ed2b0();
class Unk_QdPackets
{
public:
    void FUN_140da5180(int nOp, Delegate<void(CInPacket&)> handler);
    void FUN_140da51e0(int nOp, Delegate<void(CInPacket&)> handler);
};
Unk_QdPackets* FUN_140bccd50();
UIQuestEventDispatcher* FUN_140bfc4b0();
CQuestManager* FUN_140764020();
QuestDataTable* FUN_1407476c0();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
int FUN_14074bc90(int nQuestId);                                // the quest type
int FUN_1416e8060(int nChapter);                                // the chapter is hidden
int FUN_14074b030(CQuestData* pData);                           // the quest id
int FUN_14074b070(CQuestData* pData);                           // the repeat kind
int FUN_14074b1c0(CQuestData* pData, int nKind);
int FUN_1416c6bf0(CQuest* pQuest, int nMapId);
int FUN_1416c6cc0(CQuest* pQuest, int nMapId);
CStringW FUN_1408116a0(int nId, const int& nArg);
template <class T> int Unk_ArrayFind(const ATL::CAtlArray<T>& rArray, const T& rValue);   // index of the value, -1 if absent
__int64 FUN_141aa4980(CQuest* pQuest);                          // when the quest was completed
char FUN_14074b090(CQuestData* pData);
int FUN_14074b790(int nQuestId);
CString FUN_141082090(int nQuestId, const CString& strEpic, const CString& strSatisfied, const CString& strRepeat, const CString& strEvent);
void FUN_140534050(void* pBox, int nValue);                     // the message box argument
typedef Delegate<bool(int, const CMsgBoxData&)> Unk_MsgBoxCallback;
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
class Unk_QdTagFilter { public: void FUN_1416fb340(CStringW& str); void FUN_1416fbf20(CStringW& str); };
Unk_QdTagFilter* FUN_1403b4750();
class Unk_QdStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_QdStrings* FUN_1401a9d70();
CStringW FUN_14028b8e0(const CStringW& strKey);                 // string table text
CStringW FUN_14028de60(int nStringId);                          // common string by id
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);      // common string by id, formatted
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& a, const CStringW& b);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_14062b4f0(CStringW strKey, const int* p);
CStringW FUN_1409e8970(CStringW strKey, const int& a, const int& b);
CStringW FUN_140938ae0(CStringW strKey, const int* p);
CStringW FUN_1409e9890(CStringW strKey, const int* p, const int* q);
CStringW FUN_140bfa7f0(CStringW strKey, const CStringW& strTitle, const int* pnLevel);
CStringW FUN_1409e8ca0(CStringW strKey, const int* a, const int* b, const int* c, const int* d, const int* e);
CStringW FUN_1416e4df0(int nQuestId);                           // the quest name
CStringW FUN_1416e5450(unsigned nQuestId);                      // the quest's end text
CStringW FUN_1416e57d0(int nQuestId, int nCondition);
CString FUN_14016a5c0(const char* psz, int n);
CTime FUN_1406c47a0(__int64 nTime);
void FUN_141276180(const CString& strSound, const CString& strExtra);
void FUN_141275260(int nStringId, int a, int b);
void FUN_140874440(void* pCfg, const char* szSection, const char* szKey, int nValue, int bFlag);
void FUN_1408741a0(void* pCfg, const char* szSection, const char* szKey, int* pnValue);
void FUN_141415600(const CString& strName);                     // close a quest movie by name
void FUN_141415450(const CString& strName, void* pItem, int a, int nType, int nFlags);
void FUN_140710590(COutPacket& packet);

// The AS controls of the movie (children of the root). Slot 24 is the one the dialog calls on the list.
class Unk_QdCtl : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(int n);
};
// "m_tab" / "m_subTab".
class Unk_QdTabBar : public Unk_QdCtl
{
public:
    int FUN_1422e3210();                                // the selected tab
    void FUN_1422e31e0(int nTab);                       // select a tab
};
// "m_questList".
class Unk_QdList : public Unk_QdCtl
{
public:
    void FUN_1422dd1d0();                               // clear
    void FUN_1422dcca0(int nIndex);                     // select a row
    void FUN_1422dd110();                               // invalidate
    int FUN_1422dccd0();                                // the selected row (-1 for none)
};
// "m_questInfo".
class Unk_QdInfo : public Unk_QdCtl { };
// "m_properLevel" / "m_progressOnly".
class Unk_QdCheck : public Unk_QdCtl
{
public:
    bool FUN_1422bfca0();                               // visible
    unsigned char FUN_1422ce0e0();                      // checked
    void FUN_1422ce090(int bChecked);
};
class ASDialog : public ASDisplayObject
{
public:
    Scaleform::GFx::Value FUN_140ba26d0(const char* szMethod, int n);
};
int FUN_1409c1750(const Scaleform::GFx::Value& v);                  // Value -> int
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
// The option block of the quest guide: the "world" / "epic" / "repeat" flags of the quest list.
struct Unk_QdFlags { char m_pad_00[0x20]; bool m_20; bool m_21; bool m_22; };
class Unk_QdOptions
{
public:
    Unk_QdFlags* FUN_140c9b8b0();
    void FUN_141243540();                               // save
};
Unk_QdOptions* FUN_1409a8b10();
class Unk_QdPane : public UIDialog { public: };
class Unk_QdGuide : public UIDialog { public: void FUN_141b5bd30(); int IsFloating(); };
class Unk_QdMap : public UIDialog { public: void FUN_141a3add0(); int IsFloating(); };
Unk_QdGuide* FUN_140961730(int nUIType);
Unk_QdMap* FUN_140c9b540(int nUIType);
class UIQuestGuideDialog;
UIQuestGuideDialog* FUN_140e888d0(int nUIType);
bool FUN_141aacd70(UIQuestGuideDialog* p);
void* FUN_1422bb8b0(int nMovieId);                                  // the movie of a UI layer
void FUN_142575b00(void* pMovie, const Scaleform::GFx::Value& v);
Scaleform::GFx::Value FUN_140f17720(bool b);

// @0x141a993a0
UIQuestDialog::UIQuestDialog()
{
    m_180 = 0;
    m_184 = 1;
    m_7c = 1;
    m_188 = 0;
    FUN_141924170(1);
    ResetFilters();
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    FUN_140bccd50()->FUN_140da5180(0x53, Delegate<void(CInPacket&)>(this, &UIQuestDialog::OnPacketParty));
}

// @0x141a99600
UIQuestDialog::~UIQuestDialog()
{
    FUN_140bfc4b0()->FUN_141aa8850(this);
    FUN_140bccd50()->FUN_140da51e0(0x53, Delegate<void(CInPacket&)>(this, &UIQuestDialog::OnPacketParty));
}

// @0x141a997b0
CString UIQuestDialog::vfunc_1() { return "QuestDialog"; }

// @0x141a99800
void UIQuestDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    RefreshDetail();
    if (m_188 != 0)
    {
        FocusQuestTab(m_188);
        FocusQuestSubTab(m_188);
    }
    else
    {
        SetTab(m_180);
        SetSubTab(m_184);
    }
    ChangeTab(GetTab());
    RefreshTab();
    if (m_188 != 0)
        ScrollToQuest(m_188);
    m_188 = 0;
    if (m_30.get() != 0)
    {
        m_30->Invoke("initializeSetting", "epic", FUN_1409a8b10()->FUN_140c9b8b0()->m_20);
        m_30->Invoke("initializeSetting", "world", FUN_1409a8b10()->FUN_140c9b8b0()->m_21);
        m_30->Invoke("initializeSetting", "repeat", FUN_1409a8b10()->FUN_140c9b8b0()->m_22);
    }
}

// @0x141a99a40
void UIQuestDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1419260d0(CString("m_webGuideButton"), 0);
}

// @0x141a99aa0
int UIQuestDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("OnSelectQuest", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nQuestId = data.FUN_1422b8b10();
            SelectQuest(nQuestId);
            RemovePinned(nQuestId);
            return 1;
        }
    }
    else
    {
        if (_stricmp("OnSelectChapter", szMethod) == 0)
        {
            if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                int nChapter = data.FUN_1422b8a10();
                SelectChapter(nChapter);
                RefreshDetail();
            }
            return 1;
        }
        if (_stricmp("OnChangeTab", szMethod) == 0)
        {
            ChangeTab(GetTab());
            RefreshTab();
            RefreshDetail();
            return 1;
        }
        if (_stricmp("onGiveUpQuest", szMethod) == 0)
        {
            ASData dataGiveUp;
            if (dataGiveUp.FUN_1422b9620(pArgs, nArgs) != 0)
                GiveUpQuest(dataGiveUp.FUN_1422b8b10());
            return 1;
        }
        if (_stricmp("onRegister", szMethod) == 0)
        {
            ASData dataReg;
            if (dataReg.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                int nQuestId = dataReg.FUN_1422b8b10();
                bool bRegist = dataReg.FUN_1422b8a90();
                Unk_QdActor* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pPlayer == 0)
                    return 0;
                Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuestId);
                if (spQuest.get() != 0)
                    FUN_1416c6bf0(spQuest.operator->(), bRegist);
            }
            return 1;
        }
        if (_stricmp("CanAdd", szMethod) == 0)
        {
            UIQuestGuideDialog* pGuide = FUN_140e888d0(0x4e43);
            if (pGuide == 0)
                return 0;
            FUN_142575b00(FUN_1422bb8b0(FUN_1422db730()), FUN_140f17720(FUN_141aacd70(pGuide)));
            return 1;
        }
        if (_stricmp("ShowLimitMessage", szMethod) == 0)
        {
            FUN_141275260(0x5f1, 1, 1);
            return 1;
        }
        if (_stricmp("onSelectProperLevel", szMethod) == 0)
        {
            ASData dataLevel;
            if (dataLevel.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                int nTab = GetTab();
                if (nTab != 4)
                    m_filterA[nTab] = dataLevel.FUN_1422b8a90();
                RefreshTab();
            }
            return 1;
        }
        if (_stricmp("onSelectProgressOnly", szMethod) == 0)
        {
            ASData dataProgress;
            if (dataProgress.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                int nTab = GetTab();
                if (nTab != 4)
                    m_filterB[nTab] = dataProgress.FUN_1422b8a90();
                RefreshTab();
            }
            return 1;
        }
        if (_stricmp("onOkSetting", szMethod) == 0)
        {
            ASData dataSetting;
            if (dataSetting.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                FUN_1409a8b10()->FUN_140c9b8b0()->m_20 = dataSetting.FUN_1422b8a90();
                FUN_1409a8b10()->FUN_140c9b8b0()->m_21 = dataSetting.FUN_1422b8a90();
                FUN_1409a8b10()->FUN_140c9b8b0()->m_22 = dataSetting.FUN_1422b8a90();
                Unk_QdGuide* pGuide = FUN_140961730(0x4e42);
                if (pGuide != 0 && pGuide->FUN_141924630() != 0)
                    pGuide->FUN_141b5bd30();
                Unk_QdMap* pMap = FUN_140c9b540(0x4e29);
                if (pMap != 0 && pMap->FUN_141924630() != 0)
                    pMap->FUN_141a3add0();
                FUN_1403ed2d0()->FUN_141bd3880();
                FUN_1409a8b10()->FUN_141243540();
            }
            return 1;
        }
        if (_stricmp("onGotoNpc", szMethod) == 0)
        {
            ASData dataGoto;
            if (dataGoto.FUN_1422b9620(pArgs, nArgs) != 0)
                FUN_140764020()->FUN_1416cf510(dataGoto.FUN_1422b8b10());
            return 1;
        }
        if (_stricmp("onGotoDungeon", szMethod) == 0)
        {
            ASData dataGoto;
            if (dataGoto.FUN_1422b9620(pArgs, nArgs) != 0)
                FUN_140764020()->FUN_1416cf630(dataGoto.FUN_1422b8b10());
            return 1;
        }
        if (_stricmp("onGotoDispatch", szMethod) == 0)
        {
            ASData dataGoto;
            if (dataGoto.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                FUN_140764020()->FUN_1416cf870(dataGoto.FUN_1422b8b10());
                return 1;
            }
        }
        else
        {
            if (_stricmp("onGotoReEntry", szMethod) == 0)
            {
                ASData dataGoto;
                if (dataGoto.FUN_1422b9620(pArgs, nArgs) != 0)
                {
                    FUN_140764020()->FUN_1416cf750(dataGoto.FUN_1422b8b10());
                    return 1;
                }
            }
            else
            {
                if (_stricmp("onGotoFindParty", szMethod) == 0)
                {
                    ASData dataGoto;
                    if (dataGoto.FUN_1422b9620(pArgs, nArgs) != 0)
                    {
                        FUN_140764020()->FUN_1416cf980(dataGoto.FUN_1422b8b10(), 0);
                        return 1;
                    }
                }
                else
                {
                    if (_stricmp("onGotoFindPartyCancel", szMethod) == 0)
                    {
                        ASData dataGoto;
                        if (dataGoto.FUN_1422b9620(pArgs, nArgs) != 0)
                        {
                            FUN_140764020()->FUN_1416cf980(dataGoto.FUN_1422b8b10(), 1);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// @0x141a9a700
int UIQuestDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    return 1;
}

// @0x141a9a730
void UIQuestDialog::vfunc_67()
{
    ClearOpened();
    m_180 = GetTab();
    m_184 = GetSubTab();
    UIDialog::vfunc_67();
}

// @0x141a9a790
void UIQuestDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
}

// @0x141a9a7d0
int UIQuestDialog::vfunc_53(void* pCfg)
{
    UIDialog::vfunc_53(pCfg);
    FUN_140874440(pCfg, "tab", "properLevelWorld", m_filterA[2], 1);
    FUN_140874440(pCfg, "tab", "properLevelEpic", m_filterA[0], 1);
    FUN_140874440(pCfg, "tab", "properLevelEvent", m_filterA[1], 1);
    FUN_140874440(pCfg, "tab", "progressOnlyWorld", m_filterB[2], 1);
    FUN_140874440(pCfg, "tab", "progressOnlyEpic", m_filterB[0], 1);
    FUN_140874440(pCfg, "tab", "progressOnlyEvent", m_filterB[1], 1);
    return 1;
}

// @0x141a9a930
int UIQuestDialog::vfunc_54(void* pCfg)
{
    UIDialog::vfunc_54(pCfg);
    ResetFilters();
    FUN_1408741a0(pCfg, "tab", "properLevelWorld", &m_filterA[2]);
    FUN_1408741a0(pCfg, "tab", "properLevelEpic", &m_filterA[0]);
    FUN_1408741a0(pCfg, "tab", "properLevelEvent", &m_filterA[1]);
    FUN_1408741a0(pCfg, "tab", "progressOnlyWorld", &m_filterB[2]);
    FUN_1408741a0(pCfg, "tab", "progressOnlyEpic", &m_filterB[0]);
    FUN_1408741a0(pCfg, "tab", "progressOnlyEvent", &m_filterB[1]);
    return 1;
}

// @0x141a9aa90
void UIQuestDialog::vfunc_o178_1(void* pQuest)
{
    m_pinned.Add(static_cast<CQuest*>(pQuest)->FUN_140bfc580());
    if (vfunc_55() == 0)
        RefreshTab();
}

// @0x141a9ab10
void UIQuestDialog::vfunc_o178_2(void* pQuest)
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0)
    {
        int nChapter = static_cast<CQuest*>(pQuest)->GetData()->m_28;
        CloseChapter(nChapter);
        if (vfunc_55() == 0)
        {
            RefreshTab();
            SelectListIndex(-1);
            RefreshDetail();
            if (m_30.get() != 0)
                m_30->Invoke("updatePaper", 1);
        }
    }
}

// @0x141a9aca0
void UIQuestDialog::vfunc_o178_3(void*)
{
}

// @0x141a9acc0
void UIQuestDialog::vfunc_o178_5(void*)
{
    if (vfunc_55() == 0)
    {
        RefreshTab();
        SelectListIndex(-1);
        RefreshDetail();
        if (m_30.get() != 0)
            m_30->Invoke("updatePaper", 1);
    }
}

// @0x141a9ada0
void UIQuestDialog::vfunc_o178_6(void*)
{
    if (vfunc_55() == 0)
        RefreshTab();
}

// @0x141a9ae00
void UIQuestDialog::RefreshTab()
{
    if (GetSubTab())
    {
        switch (GetTab())
        {
        case 0:
            RefreshEpisodes();
            break;
        case 1:
            RefreshList();
            break;
        case 2:
            RefreshList();
            break;
        case 3:
            RefreshList();
            break;
        }
    }
    else
    {
        RefreshCompleted();
    }
}

// @0x141a9ae90
void UIQuestDialog::RefreshEpisodes()
{
    Unk_QdActor* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        MS2Ptr<Unk_QdList> spList = FUN_140c02900("m_questList");
        if (spList.get() != 0)
        {
            spList->FUN_1422dd1d0();
            CAtlArray<unsigned> ids;
            CollectEpisodes(ids);
            ASObj root(2);
            ASArray nodes(2);
            for (size_t i = 0; i < ids.GetCount(); i++)
            {
                if (FUN_1416e8060(ids[i]) == 0)
                    AddQuestNode(ids[i], nodes);
            }
            root.FUN_140e35d00("type", 1);
            root.FUN_1409eb1d0("nodes", nodes);
            m_30->Invoke("setList", root);
            m_30->Invoke("updatePaper");
        }
    }
}

// @0x141a9b0e0
void UIQuestDialog::RefreshList()
{
    MS2Ptr<Unk_QdList> spList = FUN_140c02900("m_questList");
    if (spList.get() != 0)
    {
        spList->FUN_1422dd1d0();
        ASObj root(2);
        ASArray nodes(2);
        QuestGroups groups;
        GroupChapters(groups);
        POSITION pos = groups.GetStartPosition();
        while (pos != 0)
        {
            CStringW strContinent(groups.GetKeyAt(pos));
            if (strContinent.GetLength() != 0)
            {
                ASObj node(2);
                node.FUN_1407cbb20("label", strContinent);
                node.FUN_140e35d00("type", 0);
                node.FUN_1409c0dc0("rendererClassName", "qd_renderer_continent");
                nodes.FUN_1422bbf00(node);
            }
            TPtrValue<ChapterQuests> spGroup(groups.GetValueAt(pos));
            POSITION pos2 = spGroup->GetStartPosition();
            while (pos2 != 0)
            {
                int nKey = spGroup->GetKeyAt(pos2);
                TPtrValue<CAtlArray<int> > spIds(static_cast<const ChapterQuests*>(spGroup.operator->())->GetValueAt(pos2));
                if (spIds->GetCount() != 0)
                {
                    CStringW strRegion = FUN_1401a9d70()->FUN_141811980(0x12, nKey);
                    if (strRegion.GetLength() != 0)
                    {
                        unsigned nCode = FUN_1407476c0()->FUN_14074e240((*spIds.operator->())[0]);
                        ASObj node(2);
                        node.FUN_1407cbb20("code", FUN_1401a9d70()->FUN_141811980(0x1a, nCode));
                        node.FUN_1407cbb20("field", strRegion);
                        node.FUN_140e35d00("type", 0);
                        node.FUN_1409c0dc0("rendererClassName", "qd_renderer_region");
                        nodes.FUN_1422bbf00(node);
                    }
                    for (size_t j = 0; j < spIds->GetCount(); j++)
                        AddQuestNode((*spIds.operator->())[j], nodes);
                }
                spGroup->GetNext(pos2);
            }
            groups.GetNext(pos);
        }
        root.FUN_140e35d00("type", 1);
        root.FUN_1409eb1d0("nodes", nodes);
        m_30->Invoke("setList", root);
        m_30->Invoke("updatePaper");
    }
}

// The chapter name record (a counted object; the name sits at +0x28).
class Unk_QdChapterText : public CPtred
{
public:
    char m_pad_18[0x10];
    CStringW m_28;
};
MS2Ptr<Unk_QdChapterText> FUN_1416e7f30(int nChapter);

// @0x141a9b6e0
void UIQuestDialog::RefreshCompleted()
{
    MS2Ptr<Unk_QdList> spList = FUN_140c02900("m_questList");
    if (spList.get() != 0)
    {
        spList->FUN_1422dd1d0();
        ASObj root(2);
        ASArray nodes(2);
        CAtlArray<MS2Ptr<CQuestData> > quests;
        CollectRecommended(quests);
        for (size_t i = 0; i < quests.GetCount(); i++)
        {
            MS2Ptr<CQuestData> spData(quests[i]);
            int nChapter = spData->m_28;
            MS2Ptr<Unk_QdChapterText> spText = FUN_1416e7f30(nChapter);
            if (spText.get() != 0)
            {
                ASObj node(2);
                ASArray children(2);
                node.FUN_1407cb9c0("chapter", nChapter);
                node.FUN_1407cbb20("level", LevelRange(nChapter));
                node.FUN_1407cbb20("label", spText->m_28);
                node.FUN_140e35d00("type", IsChapterOpen(nChapter) == 0 ? 2 : 1);
                node.FUN_1409c0dc0("rendererClassName", "qd_renderer_chapter");
                node.FUN_1409eb1d0("nodes", children);
                if (AddChapterQuests(MS2Ptr<CQuestData>(spData), children) != 0)
                    nodes.FUN_1422bbf00(node);
            }
        }
        root.FUN_140e35d00("type", 1);
        root.FUN_1409eb1d0("nodes", nodes);
        m_30->Invoke("setList", root);
        m_30->Invoke("updatePaper");
    }
}

// @0x141a9bb30
void UIQuestDialog::SelectQuest(int nQuestId)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.get() == 0)
        return;
    ClearOpened();
    MS2Ptr<Unk_QdInfo> spInfo = FUN_140c02990(CString("m_questInfo"));
    if (spInfo.get() != 0)
    {
        ASObj info(2);
        info.FUN_1409c0d20("id", nQuestId);
        info.FUN_1407cbb20("title", QuestTitle(nQuestId));
        info.FUN_1407cbb20("level", FUN_1408116a0(0x459, spData->m_level));
        info.FUN_1407cb9c0("hideReward", 0);
        info.FUN_1407cbbe0("main", spData->m_type == 0);
        if (GetSubTabFilter() == 0)
        {
            info.FUN_1409c0e60("date", L"");
            info.FUN_1407cbb20("story", QuestStory(nQuestId));
            info.FUN_1407cb9c0("progress", 0);
        }
        else
        {
            Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuestId);
            if (spQuest.IsNull())
                return;
            info.FUN_1407cbb20("date", QuestDate(FUN_141aa4980(spQuest.get())));
            info.FUN_1407cbb20("story", QuestProgressStory(spQuest.get()));
            info.FUN_1407cbbe0("progress", spQuest->IsRewarded() == 0);
            AddButtons(Unk_PayloadPtr<CQuest>(spQuest), info);
            AddConditions(nQuestId, info);
        }
        AddRewardInfo(nQuestId, info);
        spInfo->Invoke("setData", info);
    }
}

// @0x141a9bff0
void UIQuestDialog::FocusQuest(int nQuestId)
{
    MS2Ptr<Unk_QdList> spList = FUN_140c02900("m_questList");
    if (spList.get() == 0)
    {
        m_188 = nQuestId;
        FUN_1403ed2b0()->FUN_141adc530(0x4e3e);
    }
    else
    {
        m_188 = nQuestId;
        FocusQuestTab(nQuestId);
        FocusQuestSubTab(nQuestId);
        RefreshTab();
        ScrollToQuest(nQuestId);
    }
}

// @0x141a9c0e0
void UIQuestDialog::SelectListIndex(int nIndex)
{
    MS2Ptr<Unk_QdList> spList = FUN_140c02900("m_questList");
    if (spList.get() != 0)
    {
        spList->FUN_1422dcca0(nIndex);
        spList->vfunc_24(1);
        spList->FUN_1422dd110();
    }
}

// @0x141a9c1c0
void UIQuestDialog::ScrollToQuest(int nQuestId)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        int nIndex = FUN_1409c1750(pDialog->FUN_140ba26d0("getIndex", nQuestId));
        if (nIndex != -1)
            SelectListIndex(nIndex);
    }
}

// @0x141a9c290
int UIQuestDialog::HasAvailable(int nQuestId)
{
    if (FUN_140764020()->FUN_140745630(nQuestId) != 0)
        return 1;
    if (FUN_140764020()->FUN_140745590(nQuestId) != 0)
        return 1;
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.get() != 0)
    {
        CAtlArray<unsigned> chapterQuests;
        FUN_1407476c0()->FUN_14074cfd0(spData->m_28, chapterQuests);
        for (size_t i = 0; i < chapterQuests.GetCount(); i++)
        {
            if (FUN_140764020()->vfunc_1(chapterQuests[i], 0) != 0)
                return 1;
        }
        return 0;
    }
    return 0;
}

// @0x141a9c430
int UIQuestDialog::HasPinned(int nQuestId)
{
    if (Unk_ArrayFind<int>(m_pinned, nQuestId) != -1)
        return 1;
    return 0;
}

// @0x141a9c470
int UIQuestDialog::IsInCurrentTab(int nQuestId)
{
    return GetTab() == TabOfQuest(nQuestId);
}

// @0x141a9c4d0
void UIQuestDialog::RemovePinned(int nQuestId)
{
    for (size_t i = 0; i < m_pinned.GetCount(); i++)
    {
        if (m_pinned[i] == nQuestId)
            m_pinned.RemoveAt(i, 1);
    }
}

// @0x141a9c560
void UIQuestDialog::CollectQuests(CAtlArray<Unk_PayloadPtr<CQuest> >& rOut, unsigned nChapter)
{
    int nState = IsSubTabOne() ? 4 : 2;
    CAtlArray<Unk_PayloadPtr<CQuest> > quests;
    FUN_140764020()->FUN_1416cb8b0(quests, nState, 0xb, nChapter);
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        Unk_PayloadPtr<CQuest> spQuest(quests[i]);
        if (IsInCurrentTab(spQuest->FUN_140bfc580()) != 0)
        {
            if (spQuest->FUN_1407447c0() == 0)
                rOut.Add(spQuest);
        }
    }
}

// @0x141a9c6d0
int UIQuestDialog::GetTab()
{
    MS2Ptr<Unk_QdTabBar> spTab = FUN_140c02870("m_tab");
    if (spTab.get() == 0)
        return 4;
    return spTab->FUN_1422e3210();
}

// @0x141a9c780
int UIQuestDialog::GetSubTab()
{
    MS2Ptr<Unk_QdTabBar> spTab = FUN_140c02870("m_subTab");
    if (spTab.get() == 0)
        return 3;
    return spTab->FUN_1422e3210();
}

// @0x141a9c830
int UIQuestDialog::GetSubTabFilter()
{
    switch (GetSubTab())
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    }
    return 4;
}

// @0x141a9c880
int UIQuestDialog::GetQuestListIndex()
{
    MS2Ptr<Unk_QdList> spList = FUN_140c02900("m_questList");
    if (spList.get() == 0)
        return 0;
    int nIndex = spList->FUN_1422dccd0();
    if (nIndex == -1)
        nIndex = 0;
    return nIndex;
}

// @0x141a9c950
int UIQuestDialog::GetSelectedID()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        return FUN_1409c1750(pDialog->Invoke("getSelectedID"));
    return 0;
}

// @0x141a9ca00
int UIQuestDialog::IndexOfQuest(int nQuestId)
{
    CAtlArray<unsigned> ids;
    FUN_140764020()->FUN_1416cb260(ids, 1, 0xb, -1);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        if ((int)ids[i] == nQuestId)
            return (int)i;
    }
    return 0;
}

// @0x141a9cad0
CString UIQuestDialog::RewardIconName(int nItemId, int nRarity, int nCount, CString strBindName)
{
    CItem* pItem = new CItem();
    if (pItem->FUN_14052b130(nItemId, nRarity, 0) == 0)
        return "";
    pItem->FUN_140526c70(nCount);
    CString strIcon;
    strIcon.Format("%s_%s", (const char*)vfunc_1(), (const char*)FUN_14016a5c0((const char*)strBindName, 0));
    FUN_141415450(strIcon, MS2Ptr<CItem>(pItem), 0, 0x11, 0x800);
    return strIcon;
}

// @0x141a9cd30
CStringW UIQuestDialog::ConditionText(int nQuestId, int nIndex)
{
    return FUN_1416e57d0(nQuestId, nIndex);
}

// @0x141a9cd80
CString UIQuestDialog::QuestStateName(CQuest* pQuest)
{
    if (pQuest->FUN_1407447c0() == 0)
    {
        if (pQuest->IsComplete() == 0)
        {
            if (pQuest->IsRewarded() == 0)
                return "progress";
            return "complete";
        }
        CString strEvent("satisfied_event");
        CString strRepeat("satisfied_repeat");
        CString strSatisfied("satisfied");
        CString strEpic("satisfied_epic");
        return FUN_141082090(pQuest->FUN_140bfc580(), strEpic, strSatisfied, strRepeat, strEvent);
    }
    return "fail";
}

// MS2-FUNCTIONAL: behaviour-equivalent; temporaries of the string building differ from the exe
// @0x141a9cf90
CStringW UIQuestDialog::QuestProgressStory(CQuest* pQuest)
{
    CStringW strResult;
    int nType = pQuest->GetData()->m_type;
    if (nType == 8)
    {
        if (pQuest->GetData()->m_fields.GetCount() != 0)
        {
            int nField = pQuest->GetData()->m_fields[0];
            strResult += FUN_140938ae0(CStringW(L"s_quest_field_quest_link"), &nField);
        }
    }
    if (FUN_14074b090(pQuest->GetData().operator->()))
    {
        CStringW strEnd;
        if (pQuest->FUN_1407448a0() == 0)
        {
            if (pQuest->FUN_1407447c0() != 0)
            {
                strEnd = FUN_14028b8e0(CStringW(L"s_quest_end_time_expired"));
                strResult = strEnd;
                strResult += L"\n";
            }
        }
        else
        {
            CTime time(FUN_1406c47a0(pQuest->FUN_1407448a0()));
            int nYear = time.GetYear();
            int nMonth = time.GetMonth();
            int nDay = time.GetDay();
            int nHour = time.GetHour();
            int nMinute = time.GetMinute();
            if (pQuest->FUN_1407447c0() == 0)
                strEnd = FUN_1409e8ca0(CStringW(L"s_quest_dialog_end_time"), &nYear, &nMonth, &nDay, &nHour, &nMinute);
            else
                strEnd = FUN_1409e8ca0(CStringW(L"s_quest_dialog_end_time_expired"), &nYear, &nMonth, &nDay, &nHour, &nMinute);
            strResult = strEnd;
            strResult += L"\n";
        }
    }
    strResult += FUN_1416e5450(pQuest->FUN_140bfc580());
    FUN_1403b4750()->FUN_1416fb340(strResult);
    return strResult;
}

// The field meta table: which maps a field is made of; the map picker.
class Unk_QdFieldMeta { public: void FUN_1406fb2a0(int nField, CAtlArray<unsigned>& out); };
Unk_QdFieldMeta* FUN_140700390();
class Unk_QdFieldPick { public: int FUN_140c915a0(CAtlArray<unsigned>& fields); };
Unk_QdFieldPick* FUN_140c9b8e0();

// MS2-FUNCTIONAL: behaviour-equivalent; temporaries of the string building differ from the exe
// @0x141a9d690
CStringW UIQuestDialog::QuestStory(unsigned nQuestId)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.get() == 0)
        return L"";
    if (FUN_140764020()->vfunc_1(nQuestId, 0) == 0)
    {
        CStringW strRequire;
        for (size_t i = 0; i < spData->m_require.m_quest.GetCount(); i++)
        {
            if (strRequire.GetLength() != 0)
                strRequire += L", ";
            strRequire += QuestTitle(spData->m_require.m_quest[i]);
        }
        CStringW strAlternative;
        for (size_t j = 0; j < spData->m_require.m_selectableQuest.GetCount(); j++)
        {
            if (strAlternative.GetLength() != 0)
                strAlternative += FUN_14028b8e0(CStringW(L"s_quest_desc_require_or"));
            strAlternative += QuestTitle(spData->m_require.m_selectableQuest[j]);
        }
        if (strAlternative.GetLength() != 0)
        {
            if (strRequire.GetLength() != 0)
                strRequire += L", ";
            strRequire += strAlternative;
        }
        return FUN_1405c2690(CStringW(L"s_quest_desc_require"), strRequire);
    }
    int nField = spData->m_2e8;
    int nMap = 0;
    if (nField == 0)
        return QuestTitle(nQuestId);
    CAtlArray<unsigned> maps;
    FUN_140700390()->FUN_1406fb2a0(nField, maps);
    nMap = FUN_140c9b8e0()->FUN_140c915a0(maps);
    if (nMap == 0)
        nMap = spData->m_320.m_4;
    CStringW strText;
    if (nMap == 0)
        strText = FUN_140938ae0(CStringW(L"s_quest_desc_beginable_invalid_field"), &spData->m_2e8);
    else if (nMap == FUN_1403ed2d0()->FUN_141bd3060())
        strText = FUN_140938ae0(CStringW(L"s_quest_desc_beginable_current_field"), &spData->m_2e8);
    else
        strText = FUN_1409e9890(CStringW(L"s_quest_desc_beginable"), &nMap, &spData->m_2e8);
    FUN_1403b4750()->FUN_1416fbf20(strText);
    return strText;
}

// @0x141a9dd60
CStringW UIQuestDialog::LevelRange(int nChapter)
{
    int nMin = 0x7fffffff;
    int nMax = 0;
    CAtlArray<unsigned> quests;
    FUN_1407476c0()->FUN_14074cfd0(nChapter, quests);
    if (quests.GetCount() == 0)
        return L"";
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        MS2Ptr<CQuestData> spData = FUN_14074bc40(quests[i]);
        int nLevel = spData->m_level;
        if (nLevel < nMin)
            nMin = nLevel;
        if (nMax < nLevel)
            nMax = nLevel;
    }
    if (nMin == nMax)
        return FUN_14062b4f0(CStringW(L"s_quest_list_level_equal"), &nMin);
    return FUN_1409e8970(CStringW(L"s_quest_list_level"), nMin, nMax);
}

// The quest text record (a counted object; the quest name sits at +0x28).
class Unk_QdQuestText : public CPtred
{
public:
    char m_pad_18[0x10];
    CStringW m_28;
};
MS2Ptr<Unk_QdQuestText> FUN_1416e5f60(int nQuestId);

// MS2-FUNCTIONAL: behaviour-equivalent; temporaries of the string building differ from the exe
// @0x141a9df60
CStringW UIQuestDialog::QuestTitle(unsigned nQuestId)
{
    MS2Ptr<Unk_QdQuestText> spText = FUN_1416e5f60(nQuestId);
    if (spText.get() == 0)
        return L"";
    CStringW strTitle;
    int nType = FUN_14074bc90(nQuestId);
    if (nType == 8)
    {
        CStringW strKey(L"s_quest_field_quest");
        strTitle = FUN_140656190(L"[{0}] {1}", FUN_14028b8e0(strKey), spText->m_28);
    }
    if (nType == 8 || nType == 9)
    {
        CStringW strKey(L"s_quest_alliance_quest");
        strTitle = FUN_140656190(L"[{0}] {1}", FUN_14028b8e0(strKey), spText->m_28);
    }
    spText.operator->();
    strTitle = FUN_1416e4df0(nQuestId);
    FUN_1403b4750()->FUN_1416fb340(strTitle);
    return strTitle;
}

// @0x141a9e250
CStringW UIQuestDialog::QuestListLabel(unsigned nQuestId)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.get() == 0)
        return L"";
    return FUN_140bfa7f0(CStringW(L"s_quest_list_quest_name"), QuestTitle(nQuestId), &spData->m_level);
}

// @0x141a9e390
void UIQuestDialog::SetTab(int nTab)
{
    if (nTab != 4)
    {
        {
            MS2Ptr<Unk_QdTabBar> spTab = FUN_140c02870("m_tab");
            if (spTab.get() != 0)
                spTab->FUN_1422e31e0(nTab);
        }
        if (m_30.get() != 0)
            m_30->Invoke("updateSubTab");
    }
}

// @0x141a9e4a0
void UIQuestDialog::SetSubTab(int nTab)
{
    if (nTab != 3)
    {
        {
            MS2Ptr<Unk_QdTabBar> spTab = FUN_140c02870("m_subTab");
            if (spTab.get() != 0)
                spTab->FUN_1422e31e0(nTab);
        }
        if (m_30.get() != 0)
            m_30->Invoke("updateSubTab");
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; the am/pm string temporaries differ from the exe
// @0x141a9e5b0
CStringW UIQuestDialog::QuestDate(__int64 nTime)
{
    if (nTime == 0)
        return L"";
    CTime time(FUN_1406c47a0(nTime));
    int nHour = time.GetHour();
    CStringW strAmPm = (nHour > 11) ? FUN_14028de60(0x458) : FUN_14028de60(0x457);
    nHour = time.GetHour();
    if (nHour > 12)
        nHour -= 12;
    int nDay = time.GetDay();
    int nMonth = time.GetMonth();
    int nYear = time.GetYear();
    return FUN_14028dee0(0x456, nYear, nMonth, nDay, strAmPm, nHour);
}

// @0x141a9e7f0
void UIQuestDialog::ClearOpened()
{
    for (size_t i = 0; i < m_opened.GetCount(); i++)
        FUN_141415600(m_opened[i]);
    m_opened.RemoveAll();
}

// @0x141a9e870
void UIQuestDialog::RefreshDetail()
{
    ClearOpened();
    MS2Ptr<Unk_QdInfo> spInfo = FUN_140c02990(CString("m_questInfo"));
    if (spInfo.get() != 0)
    {
        ASObj info(2);
        info.FUN_1407cb9c0("id", 0);
        info.FUN_1409c0dc0("title", "");
        info.FUN_1409c0dc0("level", "");
        info.FUN_1409c0dc0("date", "");
        info.FUN_1409c0dc0("story", "");
        info.FUN_1407cb9c0("disableGiveup", 1);
        info.FUN_1407cbbe0("main", GetTab() == 0);
        spInfo->Invoke("setData", info);
    }
}

// @0x141a9ea20
void UIQuestDialog::ClearFlags()
{
    for (size_t i = 0; i < 3; i++)
        m_flags[i].RemoveAll();
}

// MS2-FUNCTIONAL: behaviour-equivalent; control flow of the nested early outs differs from the exe
// @0x141a9ea80
int UIQuestDialog::AddQuestNode(int nChapter, ASArray& rNodes)
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 0;
    if (FUN_1416e8060(nChapter) != 0)
        return 0;
    unsigned bProgressOnly = 0;
    {
        MS2Ptr<Unk_QdCheck> spCheck = FUN_140e52670(CString("m_progressOnly"));
        if (spCheck.get() != 0)
        {
            if (spCheck->FUN_1422bfca0())
                bProgressOnly = spCheck->FUN_1422ce0e0();
        }
    }
    int nAdded = 0;
    ASObj chapter(2);
    ASArray children(2);
    CAtlArray<unsigned> chapterQuests;
    CAtlArray<Unk_PayloadPtr<CQuest> > quests;
    FUN_1407476c0()->FUN_14074cfd0(nChapter, chapterQuests);
    for (size_t i = 0; i < chapterQuests.GetCount(); i++)
    {
        Unk_PayloadPtr<CQuest> spItem = FUN_140764020()->vfunc_o10_3(chapterQuests[i]);
        if (spItem.get() != 0)
            quests.Add(spItem);
    }
    for (size_t j = 0; j < quests.GetCount(); j++)
    {
        Unk_PayloadPtr<CQuest> spQuest(quests[j]);
        if (spQuest->IsRewarded() != 0)
        {
            bool bRepeat = false;
            if (FUN_14074b070(spQuest->GetData().operator->()) == 2)
                bRepeat = true;
            else if (FUN_14074b070(spQuest->GetData().operator->()) == 3)
                bRepeat = true;
            if (bRepeat)
                continue;
        }
        if (bProgressOnly != 0)
        {
            if (spQuest->FUN_1407476d0() != 1)
                continue;
        }
        ASObj node(2);
        node.FUN_1409c0d20("id", spQuest->FUN_140bfc580());
        node.FUN_1407cb9c0("regist", spQuest->GetTrackingState());
        node.FUN_1407cb9c0("forceRegist", FUN_14074b790(spQuest->FUN_140bfc580()));
        node.FUN_1407cbbe0("progress", spQuest->FUN_1407476d0() == 1);
        node.FUN_1407cbb20("label", QuestListLabel(spQuest->FUN_140bfc580()));
        node.FUN_1407cb9c0("isNew", HasPinned(spQuest->FUN_140bfc580()));
        node.FUN_1407cba60("icon", QuestStateName(spQuest.get()));
        node.FUN_1409c0dc0("rendererClassName", "qd_renderer_questList");
        children.FUN_1422bbf00(node);
        nAdded = 1;
    }
    if (nAdded != 0)
    {
        MS2Ptr<Unk_QdChapterText> spText = FUN_1416e7f30(nChapter);
        if (spText.get() != 0)
        {
            chapter.FUN_1407cb9c0("chapter", nChapter);
            chapter.FUN_1407cbb20("level", LevelRange(nChapter));
            CStringW strLabel = (spText.get() == 0) ? CStringW(L"") : CStringW(spText->m_28);
            chapter.FUN_1407cbb20("label", strLabel);
            chapter.FUN_140e35d00("type", IsChapterOpen(nChapter) == 0 ? 2 : 1);
            chapter.FUN_1409c0dc0("rendererClassName", "qd_renderer_chapter");
            chapter.FUN_1409eb1d0("nodes", children);
        }
        rNodes.FUN_1422bbf00(chapter);
    }
    return nAdded;
}

// The reward numbers of a quest (the exp / meso / karma ... of the complete reward for the player's level).
__int64 FUN_140761ba0(int nQuestId, int nKind);                 // exp
__int64 FUN_140761cc0(int nQuestId, int nKind);                 // meso
__int64 FUN_140761d80(int nQuestId, int nKind);                 // karma
__int64 FUN_140761de0(int nQuestId, int nKind);                 // lu
__int64 FUN_140761c00(int nQuestId, int nKind);                 // guild exp
__int64 FUN_140761d20(int nQuestId, int nKind);                 // guild fund
int FUN_140761ea0(int nQuestId, int nKind);                     // fame point
int FUN_140761c60(int nQuestId, int nKind);                     // guild coin
CStringW FUN_140ba7890(const wchar_t* pszFormat, const __int64* pn);
CStringW FUN_14042cb90(CStringW strKey, const float& v);
class Unk_QdExpTable { public: __int64 FUN_140353610(int nLevel); };    // the exp a level needs
Unk_QdExpTable* FUN_1404a1bb0();
float FUN_14028aed0(float f);                                   // floor
int FUN_14053feb0(int nItemId);                                 // default rank of an item
int FUN_141654700(Unk_QdActor* pActor);                         // the player's job
int FUN_140748050(CQuestData::QuestRewardItem* pItem, int nJob);
void FUN_140165270(CAtlArray<CString>& arr, const CString& s);

// @0x141a9f3c0
void UIQuestDialog::AddRewardInfo(int nQuestId, ASObj& rOut)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.get() != 0)
    {
        Unk_QdActor* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
        {
            __int64 nExp = FUN_140761ba0(nQuestId, 1);
            ASObj reward(2);
            reward.FUN_1409c1180("meso", FUN_140761cc0(nQuestId, 1));
            reward.FUN_1407cbb20("exp", FUN_140ba7890(L"{0}", &nExp));
            reward.FUN_1409c1180("karma", FUN_140761d80(nQuestId, 1));
            reward.FUN_1409c1180("lu", FUN_140761de0(nQuestId, 1));
            reward.FUN_1409c1180("guildExp", FUN_140761c00(nQuestId, 1));
            reward.FUN_1409c1180("guildFund", FUN_140761d20(nQuestId, 1));
            reward.FUN_1407cb9c0("famePoint", FUN_140761ea0(nQuestId, 1));
            if (pPlayer->vfunc_78() < 0x32)
            {
                if (GetSubTabFilter() != 2)
                {
                    __int64 nNeed = FUN_1404a1bb0()->FUN_140353610(pPlayer->vfunc_78());
                    float fRate = ((float)nExp / (float)nNeed) * 100.0f;
                    fRate = FUN_14028aed0(fRate * 100.0f + 0.5f);
                    fRate = fRate / 100.0f;
                    if (0.0f < fRate)
                        reward.FUN_1407cbb20("expRate", FUN_14042cb90(CStringW(L"s_quest_reward_exp_percent"), fRate));
                }
            }
            ASArray items(2);
            unsigned nIndex = 0;
            for (size_t i = 0; i < spData->m_complete.m_choiceRewards.GetCount(); i++)
            {
                CQuestData::QuestRewardItem& rItem = spData->m_complete.m_choiceRewards[i];
                if (rItem.m_itemId != 0)
                {
                    if (FUN_140748050(&rItem, FUN_141654700(pPlayer)) != 0)
                    {
                        CString strBind;
                        strBind.Format("reward%d", nIndex);
                        nIndex++;
                        CString strIcon = RewardIconName(rItem.m_itemId, rItem.m_count, rItem.m_job, strBind);
                        items.FUN_1422bbf70((const char*)strIcon);
                        FUN_140165270(m_opened, strIcon);
                    }
                }
            }
            int nCoin = FUN_140761c60(nQuestId, 1);
            if (nCoin != 0)
            {
                CString strBind;
                strBind.Format("reward%d", nIndex);
                int nNext = nIndex + 1;
                CString strIcon = RewardIconName(0x1c9c6dd, FUN_14053feb0(0x1c9c6dd), nCoin, strBind);
                items.FUN_1422bbf70((const char*)strIcon);
                FUN_140165270(m_opened, strIcon);
            }
            reward.FUN_1409adbe0("items", items.FUN_1422bb870());
            rOut.FUN_1409adbe0("reward", reward.FUN_1422bb870());
        }
    }
}

// @0x141a9fab0
void UIQuestDialog::AddConditions(int nQuestId, ASObj& rOut)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.get() == 0)
        return;
    ASArray summary(2);
    for (size_t i = 0; i < spData->m_conditions.GetCount(); i++)
    {
        ASObj cond(2);
        CString strBind;
        MS2Ptr<CConditionCommonData> spCond(spData->m_conditions[i]);
        if (spCond->m_nType == 2)
        {
            int nItemId = (int)spCond->m_code.GetFirstValue();
            CString strTag;
            strTag.Format("summary%d", (unsigned)i);
            strBind = RewardIconName(nItemId, FUN_14053feb0(nItemId), 1, strTag);
            FUN_140165270(m_opened, strBind);
        }
        cond.FUN_1407cbb20("condition", ConditionText(nQuestId, (int)i));
        cond.FUN_1407cba60("binding", strBind);
        summary.FUN_1422bc050(cond.FUN_1422bb870());
    }
    rOut.FUN_1409adbe0("summary", summary.FUN_1422bb870());
}

// MS2-FUNCTIONAL: behaviour-equivalent; control flow of the nested early outs differs from the exe
// @0x141a9fe50
int UIQuestDialog::AddChapterQuests(MS2Ptr<CQuestData> spData, ASArray& rNodes)
{
    if (spData == (CQuestData*)0)
        return 0;
    CAtlArray<unsigned> chapterQuests;
    FUN_1407476c0()->FUN_14074cfd0(spData->m_28, chapterQuests);
    bool bBefore = true;
    int nAdded = 0;
    int nOwnId = FUN_14074b030(spData.operator->());
    for (size_t i = 0; i < chapterQuests.GetCount(); i++)
    {
        int nId = chapterQuests[i];
        if (nOwnId == nId)
            bBefore = false;
        if (!bBefore)
        {
            MS2Ptr<CQuestData> spItem = FUN_14074bc40(nId);
            bool bAdd = false;
            if (spItem->m_28 == spData->m_28 && spItem->m_30 == 0 && spItem->m_type != 8)
            {
                if (FUN_14074b070(spData.operator->()) == 1)
                {
                    if (FUN_140764020()->FUN_140745630(FUN_14074b030(spData.operator->())) == 0)
                        bAdd = true;
                }
                else if (FUN_14074b070(spData.operator->()) == 2 || FUN_14074b070(spData.operator->()) == 3)
                {
                    if (FUN_140764020()->vfunc_1(nId, 0) != 0)
                        bAdd = true;
                }
                else
                {
                    if (FUN_140764020()->FUN_140745630(FUN_14074b030(spData.operator->())) == 0)
                    {
                        if (FUN_140764020()->FUN_140745590(FUN_14074b030(spData.operator->())) == 0)
                            bAdd = true;
                    }
                }
            }
            if (bAdd)
            {
                ASObj node(2);
                node.FUN_1409c0d20("id", nId);
                node.FUN_1407cb9c0("regist", 0);
                node.FUN_1407cb9c0("progress", 0);
                node.FUN_1407cbb20("label", QuestTitle(nId));
                node.FUN_1407cb9c0("isNew", 0);
                node.FUN_1409c0dc0("icon", "");
                node.FUN_1409c0dc0("rendererClassName", "qd_renderer_questList");
                rNodes.FUN_1422bbf00(node);
                nAdded = 1;
            }
        }
    }
    return nAdded;
}

// The map record of a room (the party finder id sits at +0x1c) and the party finder.
class Unk_QdMapRec : public CPtred { public: int m_18; int m_1c; };
class Unk_QdMapTable { public: MS2Ptr<Unk_QdMapRec> FUN_1403206b0(int nMapId); };
Unk_QdMapTable* FUN_14031c2a0();
int FUN_1402178b0(int n);
class Unk_QdPartyFinder { public: char FUN_14162ac00(int nRoom); };
Unk_QdPartyFinder* FUN_1409670d0();
int FUN_1416c6cc0(CQuest* pQuest, int nMapId);

// MS2-FUNCTIONAL: behaviour-equivalent; control flow of the nested early outs differs from the exe
// @0x141aa02b0
void UIQuestDialog::AddButtons(Unk_PayloadPtr<CQuest> spQuest, ASObj& rOut)
{
    if (spQuest == (CQuest*)0)
        return;
    MS2Ptr<CQuestData> spData = spQuest->GetData();
    if (spData.get() == 0)
        return;
    int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    ASArray buttons(2);
    if (spData->m_2e == 0)
    {
        if (spQuest->IsActive() != 0)
            buttons.FUN_1422bbf70("giveup");
    }
    if (spQuest->FUN_1407441f0(nMapId) != 0)
        buttons.FUN_1422bbf70("gotoNpc");
    if (spQuest->FUN_1407443e0(nMapId) != 0)
        buttons.FUN_1422bbf70("gotoDungeon");
    if (spQuest->FUN_140744670(nMapId) != 0)
        buttons.FUN_1422bbf70("gotoReEntry");
    if (spQuest->FUN_140d738d0() != 0 || spQuest->FUN_140d738c0() != 0)
        buttons.FUN_1422bbf70("gotoDispatch");
    if (FUN_1416c6cc0(spQuest.get(), nMapId) != 0)
    {
        MS2Ptr<CQuestData> spData2 = spQuest->GetData();
        if (spData2.get() == 0)
            return;
        MS2Ptr<Unk_QdMapRec> spMap = FUN_14031c2a0()->FUN_1403206b0(spData2->m_30c.m_roomId);
        if (spMap.get() == 0)
            return;
        int nRoom = FUN_1402178b0(spMap->m_1c);
        if (FUN_1409670d0()->FUN_14162ac00(nRoom) == 0)
            buttons.FUN_1422bbf70("partyFind");
        else
            buttons.FUN_1422bbf70("partyFindCancel");
    }
    rOut.FUN_1409eb1d0("gotoButton", buttons);
}

int FUN_1416ce3d0(CQuestManager* pMgr, int nChapter);           // chapter finished
int FUN_1416ce340(CQuestManager* pMgr, int nChapter);           // chapter started
int FUN_1416e8060(int nChapter);                                // chapter hidden

// @0x141aa06f0
void UIQuestDialog::GetChapterIDs(CAtlArray<unsigned>& rOut)
{
    CAtlArray<unsigned> chapters;
    FUN_1407476c0()->FUN_14074cf20(chapters);
    int bSubTabOne = IsSubTabOne();
    for (size_t i = 0; i < chapters.GetCount(); i++)
    {
        unsigned nChapter = chapters[i];
        if (bSubTabOne == 0)
        {
            if (FUN_1416ce3d0(FUN_140764020(), nChapter) != 0)
                rOut.Add(nChapter);
        }
        else if (FUN_1416ce340(FUN_140764020(), nChapter) != 0)
        {
            if (FUN_1416ce3d0(FUN_140764020(), nChapter) == 0)
                rOut.Add(nChapter);
        }
    }
}

// @0x141aa07f0
void UIQuestDialog::CollectEpisodes(CAtlArray<unsigned>& rOut)
{
    CRBMultiMap<__int64, unsigned> sorted(10);
    CAtlArray<unsigned> chapters;
    GetChapterIDs(chapters);
    for (size_t i = 0; i < chapters.GetCount(); i++)
    {
        unsigned nChapter = chapters[i];
        CAtlArray<Unk_PayloadPtr<CQuest> > quests;
        CollectQuests(quests, nChapter);
        if (quests.GetCount() != 0)
        {
            Unk_PayloadPtr<CQuest> spFirst(quests[0]);
            if (spFirst->IsRewarded() == 0)
            {
                __int64 nKey;
                if (IsSubTabOne() == 0)
                    nKey = FUN_141aa4980(Unk_PayloadPtr<CQuest>(quests[quests.GetCount() - 1]).get());
                else
                    nKey = Unk_PayloadPtr<CQuest>(quests[0])->GetStartTime();
                sorted.Insert(nKey, nChapter);
            }
        }
    }
    POSITION pos = sorted.GetHeadPosition();
    while (pos != 0)
    {
        rOut.Add(sorted.GetValueAt(pos));
        sorted.GetNext(pos);
    }
}

// The list node of one chapter group (the group's quest ids per chapter) and the sorting helpers of GroupChapters.
void FUN_1416dd240(CAtlArray<Unk_PayloadPtr<CQuest> >& rArr, const Unk_PayloadPtr<CQuest>& rItem);

// MS2-FUNCTIONAL: behaviour-equivalent; control flow of the nested early outs differs from the exe
// @0x141aa0a00
void UIQuestDialog::GroupChapters(QuestGroups& rOut)
{
    CAtlArray<unsigned> chapters;
    GetChapterIDs(chapters);
    unsigned bProgressOnly = 0;
    {
        MS2Ptr<Unk_QdCheck> spCheck = FUN_140e52670(CString("m_progressOnly"));
        if (spCheck.get() != 0)
        {
            if (spCheck->FUN_1422bfca0())
                bProgressOnly = spCheck->FUN_1422ce0e0();
        }
    }
    for (size_t i = 0; i < chapters.GetCount(); i++)
    {
        unsigned nChapter = chapters[i];
        if (FUN_1416e8060(nChapter) != 0)
            continue;
        CAtlArray<Unk_PayloadPtr<CQuest> > quests;
        CAtlArray<Unk_PayloadPtr<CQuest> > kept;
        CollectQuests(quests, nChapter);
        for (size_t j = 0; j < quests.GetCount(); j++)
        {
            Unk_PayloadPtr<CQuest> spQuest(quests[j]);
            bool bRepeat = false;
            if (spQuest->IsRewarded() != 0)
            {
                CQuestData* pData = spQuest->GetData().operator->();
                if (FUN_14074b070(pData) == 2 || FUN_14074b070(pData) == 3)
                    bRepeat = true;
            }
            if (!bRepeat)
            {
                if (bProgressOnly != 0 && spQuest->FUN_1407476d0() != 1)
                    continue;
                FUN_1416dd240(kept, spQuest);
            }
        }
        if (kept.GetCount() != 0)
        {
            int nSort = FUN_1407476c0()->FUN_14074e1c0(nChapter);
            int nName = FUN_1407476c0()->FUN_14074e240(nChapter);
            CStringW strGroup = FUN_1401a9d70()->FUN_141811980(0x19, nName);
            TPtrValue<ChapterQuests> spGroup(0);
            if (!rOut.Lookup(strGroup, spGroup))
            {
                spGroup = Unk_GrNewTag(0);
                rOut.SetAt(strGroup, spGroup);
            }
            TPtrValue<CAtlArray<int> > spIds(0);
            if (!spGroup->Lookup(nSort, spIds))
            {
                spIds = Unk_GrNewTag(0);
                spGroup->SetAt(nSort, spIds);
            }
            spIds->Add((int)nChapter);
        }
    }
}

class Unk_QdLevelSet { public: CRBMultiMap<int, MS2Ptr<CQuestData> > m_pad; };
int FUN_14016a050(CAtlMap<int, int>* pMap, int nKey, int nValue);

// MS2-FUNCTIONAL: behaviour-equivalent; control flow of the nested early outs differs from the exe
// @0x141aa0f80
void UIQuestDialog::CollectRecommended(CAtlArray<MS2Ptr<CQuestData> >& rOut)
{
    CRBMultiMap<int, MS2Ptr<CQuestData> > sorted(10);
    unsigned bProperLevel = 1;
    {
        MS2Ptr<Unk_QdCheck> spCheck = FUN_140e52670(CString("m_properLevel"));
        if (spCheck.get() != 0)
            bProperLevel = spCheck->FUN_1422ce0e0();
    }
    int nFocusChapter = 0;
    if (m_188 != 0)
    {
        MS2Ptr<CQuestData> spFocus = FUN_14074bc40(m_188);
        if (spFocus.get() != 0)
            nFocusChapter = spFocus->m_28;
    }
    Unk_QdActor* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    CAtlMap<int, int> seenQuests(17, 0.75f, 0.25f, 2.25f, 10);
    CAtlMap<int, int> seenChapters(17, 0.75f, 0.25f, 2.25f, 10);
    CAtlArray<unsigned> chapters;
    FUN_1407476c0()->FUN_14074cf20(chapters);
    for (size_t i = 0; i < chapters.GetCount(); i++)
    {
        int nChapter = chapters[i];
        CAtlArray<unsigned> chapterQuests;
        FUN_1407476c0()->FUN_14074cfd0(nChapter, chapterQuests);
        for (size_t j = 0; j < chapterQuests.GetCount(); j++)
        {
            MS2Ptr<CQuestData> spData = FUN_14074bc40(chapterQuests[j]);
            if (FUN_140764020()->vfunc_1(chapterQuests[j], 0) != 0)
                continue;
            if (FUN_140764020()->FUN_140745630(chapterQuests[j]) == 0)
                continue;
            bool bFound = false;
            for (size_t k = 0; k < spData->m_require.m_followingQuests.GetCount() && !bFound; k++)
            {
                MS2Ptr<CQuestData> spNext = FUN_14074bc40(spData->m_require.m_followingQuests[k]);
                if (!spNext)
                    continue;
                if (FUN_1416e8060(spNext->m_28) != 0)
                    continue;
                if (bProperLevel != 0 && nChapter != nFocusChapter)
                {
                    if (5 < (int)pPlayer->vfunc_78() - spNext->m_level)
                        continue;
                }
                int nNextId = FUN_14074b030(spNext.operator->());
                int nDummy;
                if (seenQuests.Lookup(nNextId, nDummy) || seenChapters.Lookup(nChapter, nDummy))
                    continue;
                if (FUN_1416e8060(spNext->m_28) == 0 && IsInCurrentTab(FUN_14074b030(spNext.operator->())) != 0)
                {
                    if (FUN_14074b1c0(spNext.operator->(), 1) == 0)
                    {
                        sorted.Insert(spNext->m_level, spNext);
                        seenQuests.SetAt(nNextId, 1);
                        seenChapters.SetAt(nChapter, 1);
                        bFound = true;
                    }
                }
            }
        }
    }
    POSITION pos = sorted.GetHeadPosition();
    while (pos != 0)
    {
        rOut.Add(sorted.GetValueAt(pos));
        sorted.GetNext(pos);
    }
}

// @0x141aa17b0
int UIQuestDialog::IsSubTabOne()
{
    return GetSubTabFilter() == 1;
}

// @0x141aa17f0
void UIQuestDialog::FocusQuestTab(int nQuestId)
{
    if (nQuestId != 0 && m_30.operator->() != 0 && IsInCurrentTab(nQuestId) == 0)
    {
        int nTab = TabOfQuest(nQuestId);
        if (nTab != -1)
        {
            m_30->Invoke("setTabIndex", nTab);
            ChangeTab(nTab);
        }
    }
}

// @0x141aa18b0
void UIQuestDialog::FocusQuestSubTab(int nQuestId)
{
    int nSubTab = -1;
    int nState;
    if (FUN_140764020()->FUN_140745590(nQuestId) != 0)
        nState = 2;
    else if (FUN_140764020()->FUN_140745630(nQuestId) != 0)
        nState = 1;
    else
        nState = 0;
    if (GetTab() != 0 || nState != 2)
    {
        if (nState == 0)
            nSubTab = 0;
        else if (nState == 1)
            nSubTab = 1;
        else if (nState == 2)
            nSubTab = 2;
        if (nSubTab != -1)
            SetSubTab(nSubTab);
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; control flow of the nested early outs differs from the exe
// @0x141aa1990
int UIQuestDialog::TabOfQuest(int nQuestId)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.get() == 0)
        return -1;
    if (spData->m_48 != -1)
        return spData->m_48;
    if (spData->m_type == 9 || spData->m_type == 8)
        return 3;
    if (FUN_14074b070(spData.operator->()) == 2 || FUN_14074b070(spData.operator->()) == 3)
        return 1;
    switch (spData->m_type)
    {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
    case 6:
        return 1;
    }
    return -1;
}

// MS2-FUNCTIONAL: behaviour-equivalent; the exe builds the callback through an inlined Delegate copy
// @0x141aa1b50
void UIQuestDialog::GiveUpQuest(int nQuestId)
{
    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuestId);
    if (spQuest.IsNull())
        return;
    if (spQuest->GetData().get() == 0)
        return;
    if (spQuest->FUN_1407476d0() != 1)
        return;
    bool bConfirm = false;
    if (FUN_14074b090(spQuest->GetData().operator->()) != 0 && spQuest->FUN_140744b90(0) == 0)
        bConfirm = true;
    if (bConfirm)
    {
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_14028b8e0(CStringW(L"s_quest_giveup_warning")), 0, CStringW(L""));
        if (box.get() != 0)
        {
            FUN_140534050(box.operator->(), nQuestId);
            box->FUN_141a027c0(Unk_MsgBoxCallback(this, &UIQuestDialog::OnGiveUpConfirm));
            FUN_140d73c60(box);
        }
    }
    else
    {
        COutPacket packet(0x29, 0);
        packet.Encode1(6);
        packet.Encode4(nQuestId);
        FUN_140710590(packet);
        RefreshDetail();
    }
}

// @0x141aa1fa0
bool UIQuestDialog::OnGiveUpConfirm(int nButton, const CMsgBoxData& rData)
{
    if (nButton != 0)
        return true;
    int nQuestId = rData.FUN_141a02e90(0, 0);
    COutPacket packet(0x29, 0);
    packet.Encode1(6);
    packet.Encode4(nQuestId);
    FUN_140710590(packet);
    RefreshDetail();
    return true;
}

// @0x141aa2050
void UIQuestDialog::ResetFilters()
{
    m_filterA[0] = 0;
    m_filterA[2] = 1;
    m_filterA[1] = 0;
    m_filterA[3] = 0;
    m_filterB[0] = 1;
    m_filterB[2] = 1;
    m_filterB[1] = 1;
    m_filterB[3] = 1;
}

// @0x141aa2130
void UIQuestDialog::ChangeTab(int nTab)
{
    {
        MS2Ptr<Unk_QdCheck> spCheck = FUN_140e52670(CString("m_properLevel"));
        if (spCheck.get() != 0 && nTab != 4)
            spCheck->FUN_1422ce090(m_filterA[nTab]);
    }
    {
        MS2Ptr<Unk_QdCheck> spCheck = FUN_140e52670(CString("m_progressOnly"));
        if (spCheck.get() != 0 && nTab != 4)
            spCheck->FUN_1422ce090(m_filterB[nTab]);
    }
}

// @0x141aa22b0
void UIQuestDialog::OnPacketParty(CInPacket& rPacket)
{
    if (FUN_141924630() == 0)
        return;
    int nType = rPacket.vfunc_o8_1();
    switch (nType)
    {
    case 0x1e:
        SelectQuest(GetSelectedID());
        break;
    }
}

// @0x141aa2330
int UIQuestDialog::IsChapterOpen(int nChapter)
{
    MS2Ptr<CQuestData> spFocus = FUN_14074bc40(m_188);
    if (spFocus.get() != 0 && spFocus->m_28 == nChapter)
        return 1;
    TPtrValue<QuestFlags> spFlags = GetFlags(nChapter);
    if (!spFlags)
        return 0;
    bool bOpen;
    spFlags->Lookup(nChapter, bOpen);
    return bOpen;
}

// @0x141aa2420
void UIQuestDialog::SelectChapter(int nChapter)
{
    TPtrValue<QuestFlags> spFlags = GetFlags(nChapter);
    if (!!spFlags)
    {
        bool bOpen;
        spFlags->Lookup(nChapter, bOpen);
        spFlags->SetAt(nChapter, !bOpen);
        CString strEmpty("");
        FUN_141276180(bOpen ? s_strChapterClose : s_strChapterOpen, strEmpty);
    }
}

// @0x141aa2520
void UIQuestDialog::CloseChapter(int nChapter)
{
    if (FUN_1416ce3d0(FUN_140764020(), nChapter) != 0)
    {
        TPtrValue<QuestFlags> spFlags = GetFlags(nChapter);
        if (!!spFlags)
            spFlags->SetAt(nChapter, false);
    }
}

// @0x141aa25a0
TPtrValue<UIQuestDialog::QuestFlags> UIQuestDialog::GetFlags(int nChapter)
{
    int nSubTab = GetSubTab();
    if (nSubTab == 3)
        return TPtrValue<QuestFlags>(0);
    TPtrValue<QuestFlags> spFlags(0);
    if (!m_flags[nSubTab].Lookup(DAT_143ab2828, spFlags))
    {
        spFlags = Unk_GrNewTag(0);
        m_flags[nSubTab].SetAt(DAT_143ab2828, spFlags);
    }
    bool bOpen;
    if (!spFlags->Lookup(nChapter, bOpen))
    {
        bOpen = IsSubTabOne() != 0;
        spFlags->SetAt(nChapter, bOpen);
    }
    return spFlags;
}

// @0x141aa4980
__int64 FUN_141aa4980(CQuest* pQuest)
{
    return pQuest->m_completeTime;
}

// @0x141aa2d90
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, const char* a1, bool a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc18c0-0x142cc1a40 .text$yd
