// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The PC class (RTTI PC -> PCBase; vftables 0x142f4ae28 /
// 0x142f4b2c8). Layout: placeholder/fittingdollpc.h (members 0xd40..0x12e0 from the ctor 0x14164dfd0 / dtor 0x141650b10).
// The third-party v2525 snapshot (tu/14164deb0.cpp, PC.h) has bodies for many of the small members; names here are
// the FUN_<va> / vfunc_<slot> spellings of the shared header unless the exe names them.
// MS2-UNIT: unit_14164dfd0
// MS2-RANGE: 0x14164dfd0-0x14166a650 .text$mn
// MS2-RANGE: 0x1400fb010-0x1400fb4d0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1416642e0 ; unique
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x141665910 ; unique
// MS2-PIN: ??0?$MS2Ptr@VUnk_PCBaseComp_a98@@@@QEAA@AEBV0@@Z 0x1416660b0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCSkillTierOptionManager@@@@QEAA@PEAVCSkillTierOptionManager@@@Z 0x1416661d0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCTailEffectObject@@@@QEAA@PEAVCTailEffectObject@@@Z 0x141666270 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@AEBV0@@Z 0x1416665b0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@IPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@1@@Z 0x141666670 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@IPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@1@@Z 0x1416666b0 ; unique
// MS2-PIN: ??1?$MS2Ptr@VCEquipItem@@@@QEAA@XZ 0x141666900 ; prop
// MS2-PIN: ??1?$MS2Ptr@VJobSystemCli@@@@QEAA@XZ 0x141666990 ; unique
// MS2-PIN: ??1?$MS2Ptr@VWaterGunBattleInfo@@@@QEAA@XZ 0x1416669c0 ; unique
// MS2-PIN: ??4?$MS2Ptr@VUnk_PCInteractMode@@@@QEAAAEAV0@H@Z 0x141666d90 ; unique
// MS2-PIN: ??4?$MS2Ptr@VUnk_PCBaseComp_a68@@@@QEAAAEAV0@AEBV0@@Z 0x1416670a0 ; prop
// MS2-PIN: ??_GUnk_PCCubeCraft@@QEAAPEAXI@Z 0x141667830 ; unique
// MS2-PIN: ?FindNextNode@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141667ac0 ; unique
// MS2-PIN: ?GetClassDesc@PC@@UEBAPEBVClassInfo@efd@@XZ 0x141667cd0 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x141667d00 ; unique
// MS2-PIN: ?GetKeyAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@PEAU__POSITION@@@Z 0x141667d20 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141667d80 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141667dd0 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141667f00 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VCTailEffectObject@@@@PEAU__POSITION@@@Z 0x141667fc0 ; unique
// MS2-PIN: ?GetValueAt@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@QEAAAEAV?$SmartPointer@VNiAVObject@@@efd@@PEAU__POSITION@@@Z 0x141668030 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@HV?$MS2Ptr@VCTailEffectObject@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCTailEffectObject@@@@@3@@ATL@@QEBA_NXZ 0x141668370 ; prop
// MS2-PIN: ?IsNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@AEBA_NPEAVCNode@12@@Z 0x1416683d0 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141668480 ; unique
// MS2-PIN: ?Successor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x141668ef0 ; unique
// MS2-PIN: ?TypeCast@PC@@UEBA_NIPEAPEAX@Z 0x141668fc0 ; unique
// MS2-PIN: ?TypeCast@PC@@UEBA_NIPEAPEBX@Z 0x141669010 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VRideOnAction@@@@AEBAXXZ 0x141669140 ; prop
// MS2-PIN: ?AddRef@?$MS2Ptr@VCSkillTierOptionManager@@@@AEBAXXZ 0x141669170 ; prop
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_PCBaseComp_a68@@@@AEBAXXZ 0x1416691d0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VRideOnAction@@@@AEBAXPEAX@Z 0x1416693f0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCSkillTierOptionManager@@@@AEBAXPEAX@Z 0x141669420 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCTailEffectObject@@@@AEBAXPEAX@Z 0x141669450 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUnk_PCBaseComp_a68@@@@AEBAXPEAX@Z 0x141669480 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VJobSystemCli@@@@AEBAXPEAX@Z 0x141669540 ; unique
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_PCBaseComp_a68@@@@AEAAXXZ 0x141669aa0 ; prop
// MS2-PIN: ??__FstrMgr@?1??GetInstance@CAtlStringMgr@ATL@@SAPEAUIAtlStringMgr@2@XZ@YAXXZ 0x14166a060 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@IPEAX@std@@@std@@QEAAPEAU?$_Tree_node@IPEAX@2@_K@Z 0x14166a0a0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pc.cpp"   // assumed (no __FILE__ in the TU)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/csetitemmanager.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/jobsystemcli.h"
#include "ms2/commonfiles/pvpinfo.h"
#include "ms2/commonfiles/hideandseek.h"
#include "ms2/guess/skilltieroptionmanager.h"
#include "ms2/client/ms2/statpointmanager.h"
#include "ms2/guess/watergunbattleinfo.h"
#include "ms2/client/ms2/taileffectobject.h"
#include "ms2/commonfiles/taileffectdatatable.h"
#include "ms2/client/ms2/randomtargeteffect.h"
#include "ms2/unnamed/unit_140b0e5f0.h"
#include "ms2/client/ms2/cubecraft_1.h"
#include "ms2/client/ms2/cubecraft_2.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/client/ms2/kfmmodel.h"
#include "ms2/client/ms2/clonepc.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/client/ms2/filepreload_1.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/client/ms2/notifychangebuff.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statebannerdata.h"
#include "ms2/client/ms2/statecashcalldata.h"
#include "ms2/client/ms2/statedatagrabtarget.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/statedead.h"
#include "ms2/client/ms2/stateemotionidle.h"
#include "ms2/client/ms2/statefalldamage.h"
#include "ms2/client/ms2/statefall.h"
#include "ms2/client/ms2/statefishingdata.h"
#include "ms2/client/ms2/stateglide.h"
#include "ms2/client/ms2/statehit.h"
#include "ms2/client/ms2/stateholddata.h"
#include "ms2/client/ms2/statehomeconvenient.h"
#include "ms2/client/ms2/statehomemade.h"
#include "ms2/client/ms2/stateidle.h"
#include "ms2/client/ms2/stateinteraction.h"
#include "ms2/client/ms2/statejump.h"
#include "ms2/client/ms2/statejumpto.h"
#include "ms2/client/ms2/stateladder.h"
#include "ms2/client/ms2/stateland.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/statemicrogame.h"
#include "ms2/client/ms2/statenurturing.h"
#include "ms2/client/ms2/stateobserver.h"
#include "ms2/client/ms2/stateplayinstrumentdata.h"
#include "ms2/client/ms2/statepvpwinlose.h"
#include "ms2/client/ms2/statereact.h"
#include "ms2/client/ms2/stateskill.h"
#include "ms2/client/ms2/statespawn.h"
#include "ms2/client/ms2/statestun.h"
#include "ms2/client/ms2/statesummon.h"
#include "ms2/client/ms2/stateswimdash.h"
#include "ms2/client/ms2/stateswim.h"
#include "ms2/client/ms2/statetalk.h"
#include "ms2/client/ms2/statetaxicalldata.h"
#include "ms2/client/ms2/statetransform.h"
#include "ms2/client/ms2/stateusefurnituredata.h"
#include "ms2/client/ms2/statewaitingselect.h"
#include "ms2/client/ms2/statewalk.h"
#include "ms2/placeholder/statecoupleemotion.h"
#include "ms2/placeholder/stateweddingemotion.h"
#include "ms2/unnamed/unit_140ad5280.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- exe functions and singletons used by the PC TU (other units) ----
void FUN_1411e0810(Unk_PCEquipSet* pEquip);                         // the equipment was reset (equipitem.cpp)
void FUN_141993180(int nObjectId);                                  // drop the actor's +0xfd8 record
void FUN_141b6f220(NiAVObject* pRoot, int nKind, const Unk_CharEquip* pEquip);
int FUN_140869420();                                                // the current second
CTailEffectDataTable* FUN_140ad0da0();                              // the tail effect table
void FUN_140a35900(Unk_PCD88* p);                                   // close the +0xd88 record
// The world (WorldService; FUN_1403ed2d0).
class Unk_PCLocalPlayer                                             // the MyPC
{
public:
    void FUN_14152a960();                                           // stop observing
    int FUN_1415278d0(__int64 nCharId);                             // the character is in the party
};
class Unk_PCWorld
{
public:
    Unk_PCLocalPlayer* FUN_141bd0cc0();                             // the local player
    PCBase* FUN_141bd1290(int nObjectId);                           // the player of an object id
    GameObject* FUN_141bd0fa0(egf::EntityID kId);                   // the object of an entity
    void FUN_141bbb7f0(GameObject* pObj, int n);                    // unregister an object
    int FUN_141bdb5a0(int nObserveMode);
};
Unk_PCWorld* FUN_1403ed2d0();
// The effect service (FUN_1403ed280).
class Unk_PCFxMgr
{
public:
    void FUN_1411a5770(int nKind, PCBase* pTarget);                 // play an event effect on an actor
    void FUN_1411a6060(unsigned nId);                               // stop the effects of an id
};
Unk_PCFxMgr* FUN_1403ed280();
// The pvp manager (FUN_140f97ef0).
class Unk_PCPvPMgr
{
public:
    void FUN_141280ca0(__int64 nCharId);                            // leave
};
Unk_PCPvPMgr* FUN_140f97ef0();
// The dialog 0x4e8a (FUN_141531b40): a name at +0x178.
class Unk_PCDialog4e8a
{
public:
    // @0x141667f70
    CStringW FUN_141667f70() { return m_str178; }
    unsigned char unknown0[0x178];
    CStringW m_str178;
};
Unk_PCDialog4e8a* FUN_141531b40(int nId);
extern "C" int DAT_143ae2b38;                                       // the model-cache reset switch (nifmodel.h)
void FUN_14098c6e0(void* pEntity, unsigned nProperty, const bool& bValue);   // set a bool entity property
// The KFM model of an equipped item (CEquipItem::FUN_1411dcbb0).
class CKfmModel;
class Unk_PCKfmActor
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(float fScale);                            // MS2: slot 22 (the model scale)
};
Unk_PCKfmActor* FUN_14141c720(const MS2Ptr<CKfmModel>& spModel);
class Unk_ItemEquipData : public CItemData {};
struct Unk_EquipItemData : public CItemData {};                     // CEquipItem::FUN_1411dc7f0's record (as astooltip_local.h)
int FUN_14082f1a0(int nType);                                       // the stat is a 64-bit value                     // CItem::FUN_140527840's record (as astooltip_local.h)
// The quick-equip option (FUN_1409f7c90).
class Unk_PCEquipConfig
{
public:
    int FUN_1409f7ea0();                                            // quick equip is on
};
Unk_PCEquipConfig* FUN_1409f7c90();
// The dialogs 0x4e96 / 0x4ec4 (FUN_141531c80 / FUN_141531be0): the hp of a party member changed.
class Unk_PCDialog4e96 { public: void FUN_141a92b10(__int64 nCharId, __int64 nCur, __int64 nMax); };
class Unk_PCDialog4ec4 { public: void FUN_14133afb0(__int64 nCharId, __int64 nCur, __int64 nMax); };
Unk_PCDialog4e96* FUN_141531c80(int nId);
Unk_PCDialog4ec4* FUN_141531be0(int nId);
// MS2Ptr<Unk_RideeData> (not CPtred-derived here; ridee.cpp/pcbase.cpp do the same): instantiated by other objs.
template <> MS2Ptr<Unk_RideeData>::~MS2Ptr();                                           // 0x140788ed0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::operator->() const;                   // 0x1407895d0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::get() const;                          // 0x1409f78a0
// The string table (FUN_1401a9d70).
class Unk_PCStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_PCStrings* FUN_1401a9d70();
// The PCBase UI components (pcbase.cpp has the same stand-ins) and their factories.
class Unk_PCBaseComp_a68 : public CPtred {};
class Unk_PCBaseComp_a78 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // refresh
    void FUN_141a5e4c0(int nFontSize);                              // UINameTag::Entity
    void FUN_141a5e500(int nColor);
};
class Unk_PCBaseComp_a88 : public CPtred {};
class Unk_PCBaseComp_a98 : public CPtred {};
class Unk_PCBaseComp_aa8 : public CPtred {};
class Unk_PCBaseComp_ab8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // refresh
};
class Unk_PCBaseComp_ac8 : public CPtred {};
MS2Ptr<Unk_PCBaseComp_a68> FUN_140e86320(int nActorId);
MS2Ptr<Unk_PCBaseComp_a78> FUN_141a60da0(int nActorId);            // UINameTag
MS2Ptr<Unk_PCBaseComp_a88> FUN_14192fd40(int nActorId);
MS2Ptr<Unk_PCBaseComp_a98> FUN_14128ef70(int nActorId);            // UIBuffBalloon
MS2Ptr<Unk_PCBaseComp_aa8> FUN_1418fbdb0(int nActorId);            // UIChatBalloon
MS2Ptr<Unk_PCBaseComp_ab8> FUN_141a8fb50(int nActorId);            // UIPopupProfileImage
MS2Ptr<Unk_PCBaseComp_ac8> FUN_140ba8cf0(int nActorId);
MS2Ptr<Unk_PCLinkFD8> FUN_141993100(int nActorId);
void FUN_141a60f00(int nActorId);                                   // the level changed (name tag)
// The game options (FUN_1409a8b10).
class Unk_PCOption
{
public:
    char m_pad_00[0xd];
    bool m_bShowPartyHp;                                            // +0xd
};
class Unk_PCOptions { public: Unk_PCOption* FUN_140b123b0(); };
Unk_PCOptions* FUN_1409a8b10();
unsigned FUN_140a7d630(Common::Constants::Value<Unk_ConstColor>* pColor); // the colour as ARGB (npcdatacli.cpp)
// The model resource cache (FUN_140a0afd0) and the file preloader.
class Unk_PCModelCache
{
public:
    bool FUN_141551db0(CString strPath);                            // the file is cached
};
Unk_PCModelCache* FUN_140a0afd0();
CFilePreload* FUN_140ab7a10();
// The UI root (FUN_1403ed2b0).
class Unk_PCUIRoot
{
public:
    void FUN_141ad9c40(MS2Ptr<CGemBase> spGem);                     // show the gem effect
};
Unk_PCUIRoot* FUN_1403ed2b0();
// The notice dispatcher (FUN_140939a10).
class Unk_PCNotices
{
public:
    void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify);
};
Unk_PCNotices* FUN_140939a10();

// The weapon stance of the worn weapons (+0xd70; RTTI unknown).
class Unk_PCStance : public CPtred
{
public:
    static int FUN_141b74c30(int nPrimary, int nSecondary);                       // the pair is valid
    static MS2Ptr<Unk_PCStance> FUN_141b74b50(int nPrimary, int nSecondary);      // the stance of a weapon pair
    int m_n18;                                                      // +0x18
    int m_nKind;                                                    // +0x20
    CString m_strName;                                              // +0x28
};
// The +0xd88 record (clonepc.cpp has the same stand-in) and the +0xfd8 record (create 0x141993100).
class Unk_PCD88 : public CPtred {};
class Unk_PCLinkFD8 : public CPtred {};
// The action timer at +0xfc8 (avatarpc.cpp has the same stand-in).
class Unk_PCActionTimer : public CPtred {};

// ---- PC ----

// MS2-FUNCTIONAL: written from the decompile; member construction order per the exe.
// @0x14164dfd0
PC::PC()
    : m_nD68(0), m_nD80(0), m_spD88(0), m_entityDB0(0ull), m_nCharIdDB8(0), m_nAccountIdDC0(0), m_nGenderDD8(0),
      m_nLevelDDC(1), m_kEquipDE0(this), m_spFD8(0), m_nFF0(0), m_nFF4(0), m_nFF8(0), m_nFF9(0), m_nCubeModeFFC(0),
      m_n1000(0), m_spCube1008(0), m_n1018(0), m_pCubeCraft(0), m_n1038(0), m_spItem1040(0), m_n1054(0), m_n1058(0),
      m_n105c(0), m_n1060(0), m_n1064(0), m_n1068(0), m_n106c(0), m_n10e8(0), m_n10ec(0), m_n10f0(0), m_n10f4(0),
      m_n10f8(0), m_n10fc(0), m_n1140(0), m_n1148(0), m_n114c(0), m_f1180(1.0f), m_n1184(0), m_n1188(0), m_n1190(0),
      m_n1198(0), m_n119c(0), m_n11a0(0), m_spItem11b8(0), m_n11c8(0), m_n11cc(0), m_n11d0(0), m_spCouple11d8(0),
      m_n11e8(0), m_n11f0(0), m_n11f4(0), m_n11f8(0), m_n1200(0), m_b1204(0), m_n1208(0), m_n120c(0), m_n1220(0),
      m_b1224(false), m_spInteractMode(0), m_mapTail1280(17, .75f, .25f, 2.25f, 10), m_sp12d8(0)
{
    m_str1028 = "";
    m_strNameDC8 = "";
    m_strDD0 = "";
    m_unk_180.m_z = 3.5f;
    m_unk_180.m_y = 1.2f;
    m_unk_180.m_w = 3.5f;
    m_unk_190.m_z = 3.5f;
    m_unk_190.m_y = 1.2f;
    m_unk_190.m_w = 3.5f;
    m_bD40 = true;
    m_colorD98[0] = NiColor(1.0f, 0.925490201f, 0.866666675f);
    m_colorD98[1] = NiColor(0.929411769f, 0.435294122f, 0.341176480f);
    m_f164 = FUN_1401d3200()->OffsetPcHpbar.Read();
    m_f168 = FUN_1401d3200()->OffsetPcChatballoon.Read();
    m_f16c = FUN_1401d3200()->OffsetPcNametag.Read();
    m_f170 = 0.0f;
    m_f174 = 0.0f;
    m_f178 = FUN_1401d3200()->OffsetPcDamagenumber.Read();
    m_f17c = FUN_1401d3200()->OffsetPcProfileTag.Read();
    m_spStateMgr.AssignRaw(new CStateManager(this));
    m_spStateMgr->FUN_1417daeb0(1, new StateIdle(this));
    m_spStateMgr->FUN_1417daeb0(2, new StateWalk(this));
    m_spStateMgr->FUN_1417daeb0(3, new StateCrawl(this));
    m_spStateMgr->FUN_1417daeb0(4, new StateLand(this));
    m_spStateMgr->FUN_1417daeb0(5, new StateFall(this));
    m_spStateMgr->FUN_1417daeb0(6, new StateJump(this));
    m_spStateMgr->FUN_1417daeb0(7, new StateJumpTo(this));
    m_spStateMgr->FUN_1417daeb0(8, new StateLadder(this));
    m_spStateMgr->FUN_1417daeb0(9, new StateRope(this));
    m_spStateMgr->FUN_1417daeb0(0xb, new StateEmotion(this));
    m_spStateMgr->FUN_1417daeb0(0xc, new StateDead(this));
    m_spStateMgr->FUN_1417daeb0(0xd, new StateHit(this));
    m_spStateMgr->FUN_1417daeb0(0xe, new StateWaitingSelect(this));
    m_spStateMgr->FUN_1417daeb0(0xf, new StateEmotionIdle(this));
    m_spStateMgr->FUN_1417daeb0(0x10, new StateSkill(this));
    m_spStateMgr->FUN_1417daeb0(0x12, new StateStun(this));
    m_spStateMgr->FUN_1417daeb0(0x11, new StateSpawn(this));
    m_spStateMgr->FUN_1417daeb0(0x14, new StateDash(this));
    m_spStateMgr->FUN_1417daeb0(0x15, new StatePush(this));
    m_spStateMgr->FUN_1417daeb0(0x16, new StateTalk(this));
    m_spStateMgr->FUN_1417daeb0(0x18, new StateRevival(this));
    m_spStateMgr->FUN_1417daeb0(0x19, new StateInteraction(this));
    m_spStateMgr->FUN_1417daeb0(0x1a, new StateInteractionNpc(this));
    m_spStateMgr->FUN_1417daeb0(0x1d, new StateClimb(this));
    m_spStateMgr->FUN_1417daeb0(0x1e, new StateGlide(this));
    m_spStateMgr->FUN_1417daeb0(0x1b, new StateSwim(this));
    m_spStateMgr->FUN_1417daeb0(0x1c, new StateSwimDash(this));
    m_spStateMgr->FUN_1417daeb0(0x1f, new StateFallDamage(this));
    m_spStateMgr->FUN_1417daeb0(0x20, new StateHold(this));
    m_spStateMgr->FUN_1417daeb0(0x21, new StateRide(this));
    m_spStateMgr->FUN_1417daeb0(0x22, new StateTransform(this));
    m_spStateMgr->FUN_1417daeb0(0x25, new StateTaxiCall(this));
    m_spStateMgr->FUN_1417daeb0(0x26, new StateSummon(this));
    m_spStateMgr->FUN_1417daeb0(0x28, new StatePvPWinLose(this));
    m_spStateMgr->FUN_1417daeb0(0x29, new StateUseFurniture(this));
    m_spStateMgr->FUN_1417daeb0(0x2a, new StateCashCall(this));
    m_spStateMgr->FUN_1417daeb0(0x2b, new StateGrabTarget(this));
    m_spStateMgr->FUN_1417daeb0(0x2c, new StateRecall(this));
    m_spStateMgr->FUN_1417daeb0(0x2d, new StateFishing(this));
    m_spStateMgr->FUN_1417daeb0(0x2f, new StatePlayInstrument(this));
    m_spStateMgr->FUN_1417daeb0(0x35, new StateTriggerEmotion(this));
    m_spStateMgr->FUN_1417daeb0(0x46, new StateTriggerFollowNpc(this));
    m_spStateMgr->FUN_1417daeb0(0x36, new StateHomeConvenient(this));
    m_spStateMgr->FUN_1417daeb0(0x37, new StateHomemade(this));
    m_spStateMgr->FUN_1417daeb0(0x39, new StateAutoInteraction(this));
    m_spStateMgr->FUN_1417daeb0(0x3a, new StateCoupleEmotion(this));
    m_spStateMgr->FUN_1417daeb0(0x3b, new StateBanner(this));
    m_spStateMgr->FUN_1417daeb0(0x3c, new StateMicroGameRps(this));
    m_spStateMgr->FUN_1417daeb0(0x3d, new StateReact(this));
    m_spStateMgr->FUN_1417daeb0(0x3e, new StateTreeWatering(this));
    m_spStateMgr->FUN_1417daeb0(0x3f, new StateObserver(this));
    m_spStateMgr->FUN_1417daeb0(0x40, new StateNurturing(this));
    m_spStateMgr->FUN_1417daeb0(0x45, new StateMicroGameCoupleDance(this));
    m_spStateMgr->FUN_1417daeb0(0x47, new StateWeddingEmotion(this));
    m_kGemEquip1078.FUN_141668230(this);
    m_spJobFB8.AssignRaw(new JobSystemCli());
    m_spJobFB8->FUN_140a6d8e0(this);
    m_spInteractMode.AssignRaw(reinterpret_cast<Unk_PCInteractMode*>(new CPvPInfo()));
    m_spHideAndSeek1250.AssignRaw(new HideAndSeek::Info());
    m_spSetItems.AssignRaw(new CSetItemManager());
    m_spSkillTier1110.AssignRaw(new CSkillTierOptionManager(this));
    m_spStatPoint1120.AssignRaw(new CStatPointManager(this));
    m_spCostume.AssignRaw(new CostumeManager((AvatarPC*)this));   // the shared ctor is declared with AvatarPC*
    for (size_t i = 0; i < 3; i++)
        m_spGuide1228[i] = 0;
    memset(m_aMastery1150, 0, sizeof(m_aMastery1150));
    int nTailId = *FUN_1401d3200()->TailEffectDefaultID.Get();
    MS2SvrPtr<TailEffectData> spTail = FUN_140ad0da0()->GetData(nTailId);
    if (spTail)
        m_spTailEffect1270.AssignRaw(new CTailEffectObject(this, spTail));
    m_spRandomTarget12c8.AssignRaw(new CRandomTargetEffect(this));
    m_spWaterGun1260.AssignRaw(new WaterGunBattleInfo());
}

// MS2-FUNCTIONAL: written from the decompile.
// @0x141650b10
PC::~PC()
{
    m_spFD8 = 0;
    if (m_spD88.get() != 0)
    {
        FUN_140a35900(m_spD88.operator->());
        m_spD88 = 0;
    }
    if (DAT_143ae2b38 != 0)
        m_sp12d8 = 0;
    if (m_pCubeCraft)
    {
        delete m_pCubeCraft;
        m_pCubeCraft = 0;
    }
    if (m_spInteractMode.get() != 0)
    {
        if (reinterpret_cast<CPvPInfo*>(m_spInteractMode.operator->())->FUN_140743550() && FUN_140f97ef0())
            FUN_140f97ef0()->FUN_141280ca0(FUN_141656a80());
        m_spInteractMode = 0;
    }
    if (m_n1060 != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_n1060);
        m_n1060 = 0;
    }
    if (Unk_PCDialog4e8a* pDialog = FUN_141531b40(0x4e8a))
    {
        if (PC::vfunc_77().GetLength() > 0 && pDialog->FUN_141667f70() == PC::vfunc_77())
        {
            if (Unk_PCLocalPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0())
                pPlayer->FUN_14152a960();
        }
    }
    for (std::set<unsigned int>::iterator it = m_set11a8.begin(); it != m_set11a8.end(); ++it)
    {
        if (ClonePC* pClone = dynamic_cast<ClonePC*>(FUN_1403ed2d0()->FUN_141bd1290(*it)))
            pClone->FUN_1410873d0();
    }
    m_set11a8.clear();
    POSITION pos = m_mapTail1280.GetStartPosition();
    while (pos)
    {
        MS2Ptr<CTailEffectObject> spTail = m_mapTail1280.GetValueAt(pos);
        spTail->FUN_140ad01d0();
        m_mapTail1280.GetNext(pos);
    }
    m_spWaterGun1260 = 0;
}

// @0x141651300
void PC::vfunc_9(void* p)
{
    PCBase::vfunc_9(p);
    FUN_14098c6e0(p, 0xa0b6b179, m_bD40 ? false : true);
}

// @0x141651bb0
void PC::vfunc_14()
{
    for (size_t i = 0; i < 3; i++)
    {
        efd::SmartPointer<CGuideObject> spGuide = m_spGuide1228[i];
        if (spGuide)
        {
            m_spGuide1228[i]->vfunc_128();
            if (GameObject* pObj = FUN_1403ed2d0()->FUN_141bd0fa0(spGuide->FUN_14123c460()))
                FUN_1403ed2d0()->FUN_141bbb7f0(spGuide, 0);
            FUN_1403ed2d0()->FUN_141bdb5a0(0);
        }
    }
    PCBase::vfunc_14();
}

// @0x141651d00
void PC::vfunc_15()
{
    PCBase::vfunc_15();
    FUN_1411e0810(&m_kEquipDE0);
}
MS2_REPLACE_METHOD(0x141651D00, PC, vfunc_15, 43, 0x5A36F6F9);

// @0x141651d40
void PC::vfunc_16()
{
    PCBase::vfunc_16();
    m_spFD8 = 0;
    FUN_141993180(m_unk_70);
}

// @0x141651d80
// MS2-FUNCTIONAL: the exe calls a different MS2Ptr helper copy (0x141666800) for one smart-pointer test
void PC::vfunc_52(double fTime)
{
    if (GetClassID() != 0x6200016)
        FUN_14123c330(m_unk_748.FUN_1409705d0());
    float fScale = FUN_14123c260() / FUN_14123c2e0();
    if (fScale != m_fScaleA8)
    {
        int bShrink = m_fScaleA8 - fScale > 0.0f ? 0 : 1;
        float fStep = (float)fTime * 3.0f;
        if (bShrink)
            fStep = -fStep;
        fScale += fStep;
        if (bShrink)
        {
            if (fScale < m_fScaleA8)
                fScale = m_fScaleA8;
        }
        else if (fScale > m_fScaleA8)
            fScale = m_fScaleA8;
        FUN_14123c280(fScale * FUN_14123c2e0());
        MS2Ptr<CEquipItem> spItem = FUN_141655e10(1);
        if (spItem.get())
        {
            ATL::CAtlArray<MS2Ptr<CKfmModel> > aModels;
            spItem.get()->FUN_1411dcbb0(&aModels);
            float fNew = FUN_14123c260();
            for (size_t i = 0; i < aModels.GetCount(); i++)
            {
                if (Unk_PCKfmActor* pActor = FUN_14141c720(aModels[i]))
                    pActor->vfunc_22(fNew);
            }
        }
    }
}

// @0x141652030
void PC::vfunc_31(bool enabled)
{
    switch (FUN_14166c930())
    {
    case 0x3f:
        enabled = false;
        break;
    }
    GameObject::vfunc_31(enabled);
}
MS2_REPLACE_METHOD(0x141652030, PC, vfunc_31, 61, 0x5A226AF8);

// @0x141653740
void PC::FUN_141653740(int nTargetId, void* p, int nKind, int nFlag)
{
    if (nKind == 6)
    {
        if (nFlag == 1)
            FUN_1403ed280()->FUN_1411a5770(5, this);
    }
    else
    {
        PCBase* pTarget = FUN_1403ed2d0()->FUN_141bd1290(nTargetId);
        if (nKind == 1 || nKind == 3)
            FUN_1403ed280()->FUN_1411a5770(3, pTarget);
    }
}

// @0x1416537d0
void PC::vfunc_59(int state, StateData* data, int substate, int force)
{
    if (!vfunc_124(state, substate))
        return;
    PCBase::vfunc_59(state, data, substate, force);
}
MS2_REPLACE_METHOD(0x1416537D0, PC, vfunc_59, 94, 0x9CB1080D);

// @0x141653840
int PC::vfunc_124(int a, int b)
{
    __int64 nHp = FUN_141670a00(4);
    __int64 nMaxHp = FUN_141670a30(4);
    if ((FUN_14166ce30() == 0 && (nMaxHp <= 0 || nHp != 0)) || a == 0xc || a == 0x18 || a == 0x3f)
        return 1;
    return 0;
}


// @0x141653ce0
int PC::vfunc_57()
{
    return FUN_1416546d0()->FUN_140a6e640();
}

// MS2-FUNCTIONAL: written from the disassembly (asset preload of an owned item's model files).
// @0x141653d10
void PC::FUN_141653d10(MS2Ptr<CItem> spItem)
{
    m_kListD48.Add(spItem);
    MS2SvrPtr<CItemData> spData(reinterpret_cast<CItemData*>(spItem->FUN_140527840()));
    for (size_t i = 0; i < spData->FUN_14053eba0()->FUN_14054b3d0(); i++)
    {
        const ModelGroup* pGroup = spData->FUN_14053eba0()->FUN_14054b2f0(i);
        for (size_t j = 0; j < pGroup->FUN_1405450c0(); j++)
        {
            const ModelPart* pPart = pGroup->FUN_140544fe0(j);
            if (pPart->isNif != 0 && (pPart->gender == 2 || pPart->gender == FUN_141658e60()))
            {
                if (!FUN_140a0afd0()->FUN_141551db0(CString(pPart->name0)))
                    FUN_140ab7a10()->FUN_141210ac0(CString(pPart->name0));
            }
        }
    }
}

// @0x1416544f0
void PC::vfunc_66(int n)
{
    PCBase::vfunc_66(n);
    if (n != 0)
    {
        m_str9d8 = "defaultBattle";
        if (m_str9e0 == "default")
            FUN_14166ef10(m_str9d8, 0, 0, false);
    }
    else
    {
        m_str9d8 = "default";
        if (m_str9e0 == "defaultBattle")
            FUN_14166ef10(m_str9d8, 0, 0, false);
    }
    m_kEquipDE0.FUN_1411e89d0(n);
    FUN_141659000(0);
    FUN_141670180(false);
    if (n == 1)
    {
        MS2Ptr<CGemBase> spGem = reinterpret_cast<PCGemEquip*>(FUN_14165f460())->FUN_141270740(2);
        if (spGem.get())
            FUN_1403ed2b0()->FUN_141ad9c40(spGem);   // MS2: the exe copies through a converting ctor (0x140d40c90)
    }
}

// @0x1416546d0
JobSystemCli* PC::FUN_1416546d0()
{
    return m_spJobFB8.get();
}

// @0x141654700
int PC::FUN_141654700()
{
    return m_spJobFB8->FUN_140639340();
}

// @0x141654730
int PC::FUN_141654730()
{
    return m_spJobFB8->FUN_1406393f0();
}

// @0x141654760
int PC::FUN_141654760()
{
    return m_spJobFB8->FUN_1406394b0();
}

// @0x141654790
void PC::FUN_141654790()
{
    FUN_141679760();
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangeJob(this)));
}

// @0x141654840
int PC::vfunc_64() { return 0; }
MS2_REPLACE_METHOD(0x141654840, PC, vfunc_64, 8, 0x7F371472);

// @0x141654850
int PC::vfunc_99(int n)
{
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee)
        return spRidee->vfunc_99(n);
    return PCBase::vfunc_99(n);
}

// @0x141655a30
int PC::vfunc_118(const NiPoint3& kPos, float* pDist, CString* pName)
{
    *pDist = 3.402823466e+38f;
    for (POSITION pos = m_unk_b88.GetHeadPosition(); pos; m_unk_b88.GetNext(pos))
    {
        CString strName = m_unk_b88.GetKeyAt(pos);
        float fDist = (m_unk_b88.GetValueAt(pos)->GetWorldTranslate() - kPos).Length();
        if (fDist < *pDist)
        {
            *pDist = fDist;
            *pName = strName;
        }
    }
    return 1;
}

// @0x141655b80
MS2Ptr<CItem> PC::FUN_141655b80(__int64 nItemUid)
{
    MS2Ptr<CEquipItem> spEquip = FUN_141655c30(nItemUid);
    if (!spEquip)
        return MS2Ptr<CItem>(0);
    return spEquip->FUN_1411dc7a0();
}

// @0x141655c30
MS2Ptr<CEquipItem> PC::FUN_141655c30(__int64 nItemUid)
{
    return m_kEquipDE0.FUN_1411e1580(nItemUid);
}

// @0x141655c90
MS2Ptr<CEquipItem> PC::FUN_141655c90(int nSlot)
{
    return m_kEquipDE0.FUN_1411e1780(nSlot, 0);
}

// @0x141655cf0
MS2Ptr<CEquipItem> PC::FUN_141655cf0(int nSlot)
{
    return m_kEquipDE0.FUN_1411e1780(nSlot, 1);
}

// @0x141655d50
MS2Ptr<CEquipItem> PC::FUN_141655d50(int nSlot)
{
    return m_kEquipDE0.FUN_1411e1780(nSlot, 5);
}

// @0x141655db0
MS2Ptr<CEquipItem> PC::FUN_141655db0(int nSlot)
{
    return m_kEquipDE0.FUN_1411e1780(nSlot, 4);
}

// @0x141655e10
MS2Ptr<CEquipItem> PC::FUN_141655e10(int nSlot)
{
    return m_kEquipDE0.FUN_1411e1860(nSlot, 6, 0);
}

// @0x141655e80
MS2Ptr<CEquipItem> PC::FUN_141655e80(int nSlot, int nKind)
{
    return m_kEquipDE0.FUN_1411e1780(nSlot, nKind);
}

// @0x1416561a0
Unk_PCEquipSet* PC::FUN_1416561a0() { return &m_kEquipDE0; }
MS2_REPLACE_METHOD(0x1416561A0, PC, FUN_1416561a0, 17, 0x1D689B1E);

// @0x1416561c0
Unk_PCItemCooldowns* PC::FUN_1416561c0()
{
    return reinterpret_cast<Unk_PCItemCooldowns*>(&m_kItemsF78);
}

// @0x1416561e0
void PC::vfunc_120(MS2Ptr<RideOnAction> spAction)
{
    PCBase::vfunc_120(spAction);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangePcRidee(this)));
}

// @0x1416562d0
void PC::vfunc_121(MS2Ptr<RideOffAction> spAction)
{
    PCBase::vfunc_121(spAction);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangePcRidee(this)));
}

// @0x1416563c0
void PC::vfunc_127(CItem* pItem, int n)
{
    if (!pItem)
        return;
    if (pItem->FUN_140527840()->FUN_14053ec50() != 0)
    {
        if (n == 0 && FUN_1409f7c90()->FUN_1409f7ea0())
            m_kEquipDE0.FUN_1411e38e0(MS2Ptr<CItem>(pItem));
        else
            m_kEquipDE0.FUN_1411e3600(MS2Ptr<CItem>(pItem));
        FUN_141656710();
    }
}

// @0x1416564a0
void PC::vfunc_128(CItem* pItem, int n)
{
    if (!pItem)
        return;
    if (pItem->FUN_140527840()->FUN_14053ec50() != 0)
    {
        if (n == 0 && FUN_1409f7c90()->FUN_1409f7ea0())
            m_kEquipDE0.FUN_1411e3b10(MS2Ptr<CItem>(pItem), 0);
        else
            m_kEquipDE0.FUN_1411e3960(MS2Ptr<CItem>(pItem), 0);
        FUN_141656710();
    }
}

// @0x141656580
void PC::FUN_141656580(MS2Ptr<CItem> spItem, __int64 n)
{
    m_kEquipDE0.FUN_1411e37f0(spItem, n);
}

// @0x1416565f0
void PC::FUN_1416565f0(MS2Ptr<CItem> spItem, int n)
{
    m_kEquipDE0.FUN_1411e3960(spItem, n);
}

// @0x141656660
void PC::FUN_141656660(MS2Ptr<CEquipItem> spItem, int n)
{
    m_kEquipDE0.FUN_1411e3bd0(spItem, n);
}

// @0x1416566d0
void PC::FUN_1416566d0(int n) { m_nD68 = n; }

// @0x1416566f0
int PC::FUN_1416566f0() { return m_nD68; }

// @0x141656710
void PC::FUN_141656710()
{
    FUN_141653f00();
    m_unk_748.FUN_140971150();
}

// @0x141656750
int PC::FUN_141656750()
{
    return m_kEquipDE0.FUN_1411e09a0();
}

// @0x1416569b0
int PC::FUN_1416569b0(CItem* pItem)
{
    if (pItem->FUN_140527840()->FUN_14053d460())
        return 5;
    if (pItem->FUN_140527840()->FUN_14053d510())
    {
        if (pItem->FUN_140526c30() != 0)
            return pItem->FUN_140526c30();
    }
    else if (pItem->FUN_140527840()->FUN_14053d2b0())
        return 8;
    return pItem->FUN_140527a20();
}

// @0x141656a50
void PC::FUN_141656a50(__int64 nCharId) { m_nCharIdDB8 = nCharId; }

// @0x141656a80
__int64 PCBase::FUN_141656a80() { return static_cast<PC*>(this)->m_nCharIdDB8; }

// @0x141656aa0
void PC::FUN_141656aa0(__int64 nAccountId) { m_nAccountIdDC0 = nAccountId; }

// @0x141656ad0
__int64 PC::FUN_141656ad0() { return m_nAccountIdDC0; }

// @0x141656af0
void PC::vfunc_74(__int64 nCur, __int64 nMax)
{
    PCBase::vfunc_74(nCur, nMax);
    if (FUN_14165ef30())
    {
        if (Unk_PCDialog4e96* pParty = FUN_141531c80(0x4e96))
            pParty->FUN_141a92b10(FUN_141656a80(), nCur, nMax);
        if (Unk_PCDialog4ec4* pRaid = FUN_141531be0(0x4ec4))
            pRaid->FUN_14133afb0(FUN_141656a80(), nCur, nMax);
    }
}

// @0x141656ba0
// MS2-FUNCTIONAL: the exe assigns through a CStringW temporary (two calls); a plain operator= is one
void PC::vfunc_129(const CStringW& str) { m_strNameDC8 = str; }

// @0x141656be0
CStringW& PC::FUN_141656be0() { return m_strNameDC8; }

// @0x141656c00
void PC::vfunc_130(CStringA str) { m_strDD0 = str; }

// @0x141656c50
CStringA& PC::FUN_141656c50() { return m_strDD0; }

// @0x141656c70
CStringW PC::vfunc_77()
{
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee)
    {
        MS2Ptr<Unk_RideeData> spData = spRidee->FUN_141707750();
        if (spData.get() && spData->m_nAC != 0)
            return FUN_1401a9d70()->FUN_141811980(0x31, spData->m_nNameId);
    }
    return PCBase::vfunc_77();
}

// @0x141656d90
CStringW& PC::FUN_141656d90() { return m_strName1030; }

// @0x141656f80
MS2Ptr<Unk_PCBaseComp_a68> PC::vfunc_81()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a68>(0);
    if (Unk_PCLocalPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0())
    {
        if (pPlayer->FUN_1415278d0(FUN_141656a80()) == 0)
            return MS2Ptr<Unk_PCBaseComp_a68>(0);
        if (!FUN_1409a8b10()->FUN_140b123b0()->m_bShowPartyHp)
            return MS2Ptr<Unk_PCBaseComp_a68>(0);
    }
    if (m_spA68 == 0)
        m_spA68 = FUN_140e86320(m_unk_70);
    return m_spA68;
}

// @0x141657100
MS2Ptr<Unk_PCBaseComp_a78> PC::vfunc_82()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a78>(0);
    if (m_spA78.get())
        return m_spA78;
    if ((m_spA78 = FUN_141a60da0(m_unk_70)).get())
    {
        m_spA78->FUN_141a5e4c0(0x12);
        m_spA78->FUN_141a5e500(FUN_140a7d630(&static_cast<Client::Constants*>(FUN_1401d3200())->NameTagColorFriendly));
        m_spA78->vfunc_2();
    }
    return m_spA78;
}

// @0x1416572b0
MS2Ptr<Unk_PCBaseComp_a98> PC::vfunc_84()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a98>(0);
    if (m_spA98 == 0)
        m_spA98 = FUN_14128ef70(m_unk_70);
    return m_spA98;
}

// @0x1416573b0
MS2Ptr<Unk_PCBaseComp_aa8> PC::vfunc_85()
{
    if (m_spAA8 == 0)
        m_spAA8 = FUN_1418fbdb0(m_unk_70);
    return m_spAA8;
}

// @0x141657470
MS2Ptr<Unk_PCBaseComp_ab8> PC::vfunc_86()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_ab8>(0);
    if (m_spAB8 == 0)
    {
        if (m_spAB8 = FUN_141a8fb50(m_unk_70))
            m_spAB8->vfunc_2();
    }
    return m_spAB8;
}

// @0x1416575b0
MS2Ptr<Unk_PCBaseComp_ac8> PC::vfunc_87()
{
    if (m_spAC8 == 0)
        m_spAC8 = FUN_140ba8cf0(m_unk_70);
    return m_spAC8;
}

// @0x141657670
MS2Ptr<Unk_PCBaseComp_a88> PC::vfunc_83()
{
    if (m_spA88 == 0)
        m_spA88 = FUN_14192fd40(m_unk_70);
    return m_spA88;
}

// @0x141657730
MS2Ptr<Unk_PCLinkFD8> PC::FUN_141657730()
{
    if (FUN_141661970())
        return MS2Ptr<Unk_PCLinkFD8>(0);
    if (m_spFD8 == 0)
        m_spFD8 = FUN_141993100(m_unk_70);
    return m_spFD8;
}

// @0x141657820
void PC::vfunc_131(short n)
{
    m_nLevelDDC = n;
    FUN_141a60f00(m_unk_70);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyChangeLevel(this)));
}

// @0x1416578f0
int PC::vfunc_78() { return m_nLevelDDC; }

// @0x141657910
void PC::vfunc_90(void* p)
{
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    unsigned char nCount = pPacket->vfunc_o8_1();
    if (nCount == 0x23)
    {
        for (int i = 0; i < 3; i++)
        {
            FUN_141670540(i, 4, pPacket->vfunc_o8_4());
            FUN_141670540(i, 0xd, (unsigned)pPacket->vfunc_o8_3());
            FUN_141670540(i, 0xe, (unsigned)pPacket->vfunc_o8_3());
            FUN_141670540(i, 0x20, (unsigned)pPacket->vfunc_o8_3());
            FUN_141670540(i, 0x16, (unsigned)pPacket->vfunc_o8_3());
        }
    }
    else
    {
        for (int n = 0; n < nCount; n++)
        {
            unsigned char nType = pPacket->vfunc_o8_1();
            for (int i = 0; i < 3; i++)
            {
                __int64 nValue;
                if (FUN_14082f1a0(nType) == 0)
                    nValue = (unsigned)pPacket->vfunc_o8_3();
                else
                    nValue = pPacket->vfunc_o8_4();
                FUN_141670540(i, nType, nValue);
            }
        }
    }
}

// @0x141657c40
void PC::vfunc_91(void* p) { vfunc_90(p); }

// @0x141657dc0
int PC::vfunc_133(CItem* pItem, bool bForce) { return vfunc_132(pItem, pItem->FUN_140527a20(), bForce); }

// @0x141657e20
// MS2-FUNCTIONAL: one smart-pointer temporary too many on the slot 4/5 fallback path
int PC::vfunc_132(CItem* pItem, int nSlot, bool bForce)
{
    int nResult = 0;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return nResult;
    if (!bForce && !spData->FUN_14053cf90())
        return nResult;
    if (spData->FUN_14053d2f0())
    {
        if (spData->FUN_14053d460())
        {
            MS2Ptr<CEquipItem> spEquip = FUN_141655c90(5);
            if (spEquip.get())
                nResult = spEquip->FUN_1411dc7f0()->FUN_14053c620();
            if (nResult == 0)
            {
                spEquip = FUN_141655c90(4);
                if (spEquip.get())
                    nResult = spEquip->FUN_1411dc7f0()->FUN_14053c620();
            }
        }
        else if (spData->FUN_14053d510())
        {
            MS2Ptr<CEquipItem> spEquip = FUN_141655c90(nSlot);
            if (spEquip.get())
                nResult = spEquip->FUN_1411dc7f0()->FUN_14053c620();
        }
        else if (spData->FUN_14053d340())
        {
            if (spData->FUN_14053eba0()->FUN_14054b450(5))
            {
                MS2Ptr<CEquipItem> spEquip = FUN_141655c90(5);
                if (spEquip.get())
                    nResult = spEquip->FUN_1411dc7f0()->FUN_14053c620();
            }
            else
            {
                MS2Ptr<CEquipItem> spEquip = FUN_141655c90(4);
                if (spEquip.get())
                    nResult = spEquip->FUN_1411dc7f0()->FUN_14053c620();
            }
        }
    }
    return nResult;
}

// ---- end of code ----

// MS2-PIN: ??_7PC@@6BIBase@efd@@@ 0x142f4ae28
// MS2-PIN: ??_7PC@@6BCallbackObject@NiActorManager@@@ 0x142f4b2c8
// MS2-PIN: ??_GPC@@UEAAPEAXI@Z 0x1416678b0
// MS2-PIN: ??_EPC@@W7EAAPEAXI@Z 0x1416677f8
