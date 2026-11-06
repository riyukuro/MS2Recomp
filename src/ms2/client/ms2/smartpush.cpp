// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\smartpush.cpp: the smart push
// (HUD suggestion button) classes of Table/smartPush.xml, see smartpush.h.
// MS2-UNIT: ?\smartpush.cpp
// MS2-RANGE: 0x1400d5a30-0x1400d5fd0 .text$di
// MS2-RANGE: 0x140dcf0c0-0x140dd81d0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVCSmartPush@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVCSmartPush@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140dd5b20 ; prop
// MS2-PIN: ??$?8PEAVCSmartPushAutoFishing@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVCSmartPushAutoFishing@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140dd5b70 ; prop
// MS2-PIN: ??$?8PEAVCSmartPushAutoFunctionCubeObjectBuffItem@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVCSmartPushAutoFunctionCubeObjectBuffItem@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140dd5bc0 ; prop
// MS2-PIN: ??$?8PEAVCSmartPushAutoInteractObjectBuffItem@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVCSmartPushAutoInteractObjectBuffItem@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140dd5c10 ; prop
// MS2-PIN: ??$?8PEAVCSmartPushAutoInteraction@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVCSmartPushAutoInteraction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140dd5c60 ; prop
// MS2-PIN: ??$?8PEAVCSmartPushAutoPlayInstrument@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVCSmartPushAutoPlayInstrument@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140dd5cb0 ; prop
// MS2-PIN: ??$FUN_14028dfa0@IH@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBIAEBH@Z 0x140dd5d00 ; unique
// MS2-PIN: ??$forward@AEBQ8CSmartPushAutoInteraction@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8CSmartPushAutoInteraction@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x140dd64f0 ; prop
// MS2-PIN: ??$forward@AEBQ8CSmartPushAutoPlayInstrument@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8CSmartPushAutoPlayInstrument@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x140dd6500 ; prop
// MS2-PIN: ??$forward@AEBQEAVCSmartPushAutoInteraction@@@std@@YAAEBQEAVCSmartPushAutoInteraction@@AEBQEAV1@@Z 0x140dd6550 ; prop
// MS2-PIN: ??$forward@AEBQEAVCSmartPushAutoPlayInstrument@@@std@@YAAEBQEAVCSmartPushAutoPlayInstrument@@AEBQEAV1@@Z 0x140dd6560 ; prop
// MS2-PIN: ??$make_pair@AEBQEAVCSmartPushAutoInteraction@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA?AU?$pair@PEAVCSmartPushAutoInteraction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@AEBQEAVCSmartPushAutoInteraction@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140dd66b0 ; prop
// MS2-PIN: ??$make_pair@AEBQEAVCSmartPushAutoPlayInstrument@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA?AU?$pair@PEAVCSmartPushAutoPlayInstrument@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@AEBQEAVCSmartPushAutoPlayInstrument@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140dd6700 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCSmartPush@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140dd6750 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCSmartPush@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVCSmartPush@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x140dd67a0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCSmartPushAutoFishing@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140dd67f0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCSmartPushAutoFishing@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVCSmartPushAutoFishing@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x140dd6840 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCSmartPushAutoInteraction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140dd69d0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCSmartPushAutoInteraction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVCSmartPushAutoInteraction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x140dd6a20 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCSmartPushAutoPlayInstrument@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140dd6a70 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCSmartPushAutoPlayInstrument@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVCSmartPushAutoPlayInstrument@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x140dd6ac0 ; prop
// MS2-PIN: ??1?$MS2Ptr@VRideOffActionAutoInteraction@@@@QEAA@XZ 0x140dd6ed0 ; prop
// MS2-PIN: ??7?$MS2SvrPtr@VCAutoActionPricePackage@@@@QEBA_NXZ 0x140dd7210 ; unique
// MS2-PIN: ??7?$MS2SvrPtr@VCSmartPushData@@@@QEBA_NXZ 0x140dd7240 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVCSmartPush@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140dd72d0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVCSmartPushAutoFishing@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140dd7310 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVCSmartPushAutoFunctionCubeObjectBuffItem@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140dd7350 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVCSmartPushAutoInteractObjectBuffItem@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140dd7390 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVCSmartPushAutoInteraction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140dd73d0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVCSmartPushAutoPlayInstrument@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140dd7410 ; prop
// MS2-PIN: ??_GCSmartPush@@UEAAPEAXI@Z 0x140dd7450 ; prop
// MS2-PIN: ??_GCSmartPushAutoFishing@@UEAAPEAXI@Z 0x140dd7590 ; prop
// MS2-PIN: ??_GCSmartPushAutoPlayInstrument@@UEAAPEAXI@Z 0x140dd7810 ; prop
// MS2-PIN: ??_GCSmartPushSafeRiding@@UEAAPEAXI@Z 0x140dd7850 ; prop
// MS2-PIN: ??_GCSmartPushSafeWaterRiding@@UEAAPEAXI@Z 0x140dd7890 ; prop
// MS2-PIN: ??_GCSmartPushSafeWaterRidingToggle@@UEAAPEAXI@Z 0x140dd78d0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCFunctionCubeObject@@@@AEBAXPEAX@Z 0x140dd79c0 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VRideOffActionAutoInteraction@@@@AEAAXXZ 0x140dd7a20 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VRideOffActionAutoInteraction@@@@AEAAXPEAX@Z 0x140dd7a60 ; prop
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVCSmartPush@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140dd7ab0 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoFishing@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140dd7b10 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoFunctionCubeObjectBuffItem@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140dd7b70 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoInteractObjectBuffItem@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140dd7bd0 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoInteraction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140dd7c30 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoPlayInstrument@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140dd7c90 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCSmartPush@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140dd7cf0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoFishing@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140dd7d30 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoFunctionCubeObjectBuffItem@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140dd7d70 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoInteractObjectBuffItem@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140dd7db0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoInteraction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140dd7df0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoPlayInstrument@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140dd7e30 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCSmartPush@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140dd7f90 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoFishing@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140dd7ff0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoFunctionCubeObjectBuffItem@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140dd8050 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoInteractObjectBuffItem@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140dd80b0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoInteraction@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140dd8110 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCSmartPushAutoPlayInstrument@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140dd8170 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1CSmartPushAutoBreeding@@UEAA@XZ 0x140dd6f00 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoBreedingBuff@@UEAA@XZ 0x140dd6f30 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoFarming@@UEAA@XZ 0x140dd6f60 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoFarmingBuff@@UEAA@XZ 0x140dd6f90 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoFunctionCubeObject@@UEAA@XZ 0x140dd6fc0 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoFunctionCubeObjectBuffItem@@UEAA@XZ 0x140dd6ff0 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoGathering@@UEAA@XZ 0x140dd7020 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoGatheringBuff@@UEAA@XZ 0x140dd7050 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoInteractObject@@UEAA@XZ 0x140dd7080 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoInteractObjectBuffItem@@UEAA@XZ 0x140dd70b0 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoInteraction@@UEAA@XZ 0x140dd70e0 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoMining@@UEAA@XZ 0x140dd7110 ; manual (implicit dtor, vftable store disambiguates)
// MS2-PIN: ??1CSmartPushAutoMiningBuff@@UEAA@XZ 0x140dd7140 ; manual (implicit dtor, vftable store disambiguates)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\smartpush.cpp"
#define MS2_SVRPTR_ASSIGN_INT
#define NOMINMAX                        // NxPhysics (interactobject.h)
#include "ms2/placeholder/ms2stdafx.h"

#include <algorithm>

#include "ms2/client/ms2/smartpush.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiplayinstrumentdialog.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/costumemanager.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/interactobject.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/luautil.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/fishingmanager.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uisystemshopdialog.h"
#include "ms2/client/ms2/instrumentmanager.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/commonfiles/additionalactionadditional.h"   // C3: AdditionalLevelData
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/commonfiles/skillactionadditional.h"
#include "ms2/commonfiles/masterytable.h"   // C3: CMasteryTable::Find (CMasteryReceipe)

// ---- Callees of other units --------------------------------------------------------------------------------------------

void FUN_140710590(COutPacket& packet);                                 // send a packet
CStringW GetStringCommonByKey(const CStringW& strKey);                         // string table text
CStringW GetStringCommon(int nId);                                        // string table text by id
CStringW FUN_140298ea0(CStringW strKey);                                // string table text (the callee destroys the key)
template <class A> CStringW StringFormat(const wchar_t* pszFormat, const A& a);   // "{0}" formatting of a key
template <class A> CStringA StringFormat(const char* pszFormat, const A& a);      // "{0}" formatting of a narrow key
template <class A> CStringW BlockFormat(int nId, const A& a);                     // string table entry, one argument
void FUN_140841420(CStringW& str);                                      // the mastery name of a row content
int FUN_1407181a0(const CStringW& str);                                 // _wtoi of a CStringW
int FUN_14053feb0(int nItemId);                                         // default rank of an item
bool FUN_140811640(int nKind);                                          // the first use is paid with red merat
void* FUN_140d86260();   // C3: was FUN_140d86260

MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* pListener, CStringW strTag);   // new message box data
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                         // show it
void FUN_140d73aa0(CStringW strText, int nType, void* pListener, CStringW strTag);   // notice box
void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW strTag);   // notice box of a system string
void FUN_1412751f0(const CStringW& str, int nType, int nFlag);          // chat / center notice


// The local player's buffs (PCBase +0x748).
#include "ms2/client/ms2/additionalclilist.h"   // AdditionalCliList / AdditionalCli (C3: the local views are gone)
class Unk_PCBaseBuffs : public AdditionalCliList { };
//

// The safe riding map table (FUN_140ba4fa0).
class CAdventureLevelTableHelper { public: bool IsReached(unsigned nLevel); };   // C3: member view (adventureleveltablehelper.h)
class Unk_ALCurrent* FUN_140ba4fa0();   // C3: was FUN_140ba4fa0

// The play instrument manager (FUN_140c8dac0).
class Unk_SpInstrument : public CInstrumentManager
{
};
struct Unk_PmFixedItem* FUN_140c8dac0();   // C3: was FUN_140c8dac0
template <class T> T* Unk_FmGetDialog(eUIClassID nId);   // 0x140cdee10 for UISystemShopDialog (fishingmanager)
template <class T> T* Unk_ImGetDialog(int nId);   // C3: was FUN_140d0c040

// The local player as a game object: only slot 18 (the position, efd::Point3 by value) is used.
class Unk_SpGameObj
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual Vector3 vfunc_18();                                         // 18 0x14166bbe0
};
class Unk_MData* FUN_1409670c0();   // C3: was FUN_1409670c0
// CubeMapInformationService: the real header (B22 removed the Unk_BuddyHandle / Unk_1401cd100 clash).
#include "ms2/client/ms2/cubemapinformationservice_3.h"   // B22 follow-up: was a local member view (the Unk_BuddyHandle clash is gone)
//{
//public:
//    bool FUN_1410d5640();                                              // the home of the map is the player's
//};
class Unk_SpHome : public CubeMapInformationService {};
class Unk_AkoHouseSvc   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoHouseSvc* GetInstance();
};
class Unk_BmPriceMgr* FUN_1401c0db0();   // C3: was FUN_1401c0db0
CFunctionCubeService* FUN_1409670b0();                                  // the function cube service

// The auto interaction use counts of today (recipe id -> count).
extern ATL::CAtlMap<int, int> g_143ab3150;   // the gather counts (0x143ab3150)
typedef ATL::CAtlMap<unsigned long, int, ATL::CElementTraits<unsigned long>, ATL::CElementTraits<int>> CGatherCountMap;   // g_143ab3150 as the exe's map type

// The bag.
class Unk_Inventory   // C3: member view (inventory.h)
{
public:
    int FUN_140a5f780(int nTag, int nRarity);
    MS2Ptr<CItem> FUN_140a5e2e0(int nItemId);                          // the item in the bag
    int FUN_140a5f180(int nItemId, int nRarity);                       // owned count of the item
    void FUN_140a60880(int nTab, ATL::CAtlArray<MS2Ptr<CItem> >& out);
    unsigned FUN_140a635f0(CItem* pItem);                              // use the item
};
class Unk_SpInventory : public Unk_Inventory
{
};
extern Unk_Inventory g_143ab2a90;   // C3: the real global (0x143ab2a90); read through Unk_SpInventory
extern __int64 DAT_143ab2898;                                           // the money


// CMsgBoxData::SetValue<T> (the COMDATs 0x140dd6030..0x140dd63d0): a named GFx value of the box.
void Unk_SetBoxInt(CMsgBoxData* pBox, const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    pBox->m_values.insert(std::make_pair(szName, data.PopValue()));
}
void Unk_SetBoxUInt(CMsgBoxData* pBox, const char* szName, unsigned n)
{
    ASData data;
    data.FUN_1422b8030(n);
    pBox->m_values.insert(std::make_pair(szName, data.PopValue()));
}
void Unk_SetBoxString(CMsgBoxData* pBox, const char* szName, CStringW str)
{
    ASData data;
    data.AddWString(str);
    pBox->m_values.insert(std::make_pair(szName, data.PopValue()));
}
void Unk_SetBoxInt64(CMsgBoxData* pBox, const char* szName, __int64 n)
{
    ASData data;
    data.AddInt64(n);
    pBox->m_values.insert(std::make_pair(szName, data.PopValue()));
}
void Unk_SetBoxBool(CMsgBoxData* pBox, const char* szName, bool b)
{
    ASData data;
    data.AddBool(b);
    pBox->m_values.insert(std::make_pair(szName, data.PopValue()));
}

static MyPC* Unk_SpGetMyPC()
{
    return static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
}

// ---- Registration (.text$di 0x1400d5a30..) ------------------------------------------------------------------------------

#ifndef MS2_HOOK_DLL   // registers into the exe's ClassObject registry at DllMain time, before the exe's CRT/locks exist
static ClassObjectRegistrar s_regBreeding(L"CSmartPushAutoBreeding", CSmartPushAutoBreeding::CreateObject);
static ClassObjectRegistrar s_regBreedingBuff(L"CSmartPushAutoBreedingBuff", CSmartPushAutoBreedingBuff::CreateObject);
static ClassObjectRegistrar s_regFarming(L"CSmartPushAutoFarming", CSmartPushAutoFarming::CreateObject);
static ClassObjectRegistrar s_regFarmingBuff(L"CSmartPushAutoFarmingBuff", CSmartPushAutoFarmingBuff::CreateObject);
static ClassObjectRegistrar s_regFishing(L"CSmartPushAutoFishing", CSmartPushAutoFishing::CreateObject);
static ClassObjectRegistrar s_regGathering(L"CSmartPushAutoGathering", CSmartPushAutoGathering::CreateObject);
static ClassObjectRegistrar s_regGatheringBuff(L"CSmartPushAutoGatheringBuff", CSmartPushAutoGatheringBuff::CreateObject);
static ClassObjectRegistrar s_regMining(L"CSmartPushAutoMining", CSmartPushAutoMining::CreateObject);
static ClassObjectRegistrar s_regMiningBuff(L"CSmartPushAutoMiningBuff", CSmartPushAutoMiningBuff::CreateObject);
static ClassObjectRegistrar s_regPlayInstrument(L"CSmartPushAutoPlayInstrument", CSmartPushAutoPlayInstrument::CreateObject);
static ClassObjectRegistrar s_regSafeRiding(L"CSmartPushSafeRiding", CSmartPushSafeRiding::CreateObject);
static ClassObjectRegistrar s_regSafeWaterRiding(L"CSmartPushSafeWaterRiding", CSmartPushSafeWaterRiding::CreateObject);
static ClassObjectRegistrar s_regSafeWaterRidingToggle(L"CSmartPushSafeWaterRidingToggle", CSmartPushSafeWaterRidingToggle::CreateObject);
#endif
// @0x1400d5e40
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/statemanager_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION

// ---- CSmartPush ---------------------------------------------------------------------------------------------------------

// @0x140dcf0c0
CSmartPush::CSmartPush()
    : m_nId(0), m_n1c(0), m_nState(0), m_data(0)
{
}

// @0x140dcf140
CSmartPush::~CSmartPush()
{
    m_data = 0;
}

// @0x140dcf1a0
void CSmartPush::vfunc_3()
{
    if (m_data == 0)
        return;
    if (m_data->m_nRequireMerat == 0)
    {
        vfunc_5(false);
    }
    else
    {
        CStringW strText = vfunc_9();
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x20, strText, 0, CStringW(L""));
        if (spBox)
        {
            spBox->FUN_141a01800(1);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CSmartPush::FUN_140dcf800));
            spBox->SetBuff(m_data->m_nActionValue, 1, CStringW(L""));
            spBox->FUN_141a024a0(0);
            FUN_140d73c60(spBox);
        }
    }
}

// @0x140dcf440
void CSmartPush::vfunc_4(int nValue)
{
    if (!m_data)
        return;
    if (m_data->m_nActionType == 1)
    {
        CStringW strMsg = FUN_14028dfa0<CStringW>(CStringW(L"s_smartpush_active"),
                                        CStringTable::GetInstance()->FUN_141812290(m_data->m_nActionValue, 1, CString("name")));
        FUN_1412751f0(strMsg, 1, 1);
    }
}

// @0x140dcf590
void CSmartPush::vfunc_5(bool bAccept)
{
    if (m_data == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::SmartPush), 0);
    packet.WriteInt32(m_nId);
    packet.WriteInt32(m_n1c);
    packet.WriteInt32(0);
    packet.WriteBool(bAccept);
    FUN_140710590(packet);
}

// @0x140dcf640
int CSmartPush::vfunc_6()
{
    return 0;
}

// @0x140dcf650
CStringW CSmartPush::vfunc_7()
{
    return CStringW(L"");
}

// @0x140dcf6a0
CStringW CSmartPush::vfunc_8()
{
    if (m_data == 0)
        return CStringW(L"");
    return m_data->m_strImgPath;
}

// @0x140dcf740
CStringW CSmartPush::vfunc_9()
{
    return CStringW(L"");
}

// @0x140dcf790
CStringW CSmartPush::vfunc_10()
{
    return CStringW(L"");
}

// @0x140dcf7e0
bool CSmartPush::vfunc_11()
{
    return false;
}

// @0x140dcf7f0
bool CSmartPush::vfunc_12()
{
    return false;
}

// @0x140dcf800
bool CSmartPush::FUN_140dcf800(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    vfunc_5(false);
    return true;
}

// ---- CSmartPushAutoFishing ----------------------------------------------------------------------------------------------

// @0x140dcf840
ClassObject* CSmartPushAutoFishing::CreateObject()
{
    return new CSmartPushAutoFishing;
}

// @0x140dcf8a0
CStringW CSmartPushAutoFishing::GetTypeName()
{
    return CStringW(L"CSmartPushAutoFishing");
}

// @0x140dcf8f0
CSmartPushAutoFishing::CSmartPushAutoFishing()
{
    m_bActive = 0;
}

// @0x140dcf930
CSmartPushAutoFishing::~CSmartPushAutoFishing()
{
}

// @0x140dcf960
void CSmartPushAutoFishing::vfunc_2()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return;
    if (CFishingManager::GetInstance()->FUN_140954150() == 0)
        return;
    MS2Ptr<AdditionalCli> spBuff = pMy->FUN_1416749a0()->FindEnabledByEventBuffType(1);
    if (m_bActive != 0 && !spBuff)
    {
        int nCount = CFishingManager::GetInstance()->GetAutoCount();
        if (nCount > 0)
        {
            CSmartPushTable::PackagePtr pkg =
                CSmartPushTable::GetInstance()->GetPackage(CGameRule::GetInstance()->GetAutoFishingName(), m_n1c);
            if (!pkg)
            {
                CFishingManager::GetInstance()->FUN_140cdbdf0(0);
                FUN_140d73aa0(GetStringCommonByKey(L"s_msg_autofishing_extend_merat_warn"), 0, 0, L"");
                return;
            }
            if (FUN_140dd07b0())
            {
                --nCount;
                CFishingManager::GetInstance()->FUN_140cdbdf0(nCount);
                vfunc_5(true);
                CStringW strTime = CSmartPushTable::GetInstance()->GetPackageDurationText(
                    CGameRule::GetInstance()->GetAutoFishingName(), m_n1c);
                FUN_1412751f0(FUN_14028dfa0<CStringW>(CStringW(L"s_msg_autofishing_extend_complete"), strTime), 1, 1);
            }
            else
            {
                CFishingManager::GetInstance()->FUN_140cdbdf0(0);
                if (FUN_140dd06b0() == 2)
                    CUIService::GetInstance()->FUN_141add1f0();
                else
                    FUN_140d73bc0(0x34, 0, 0, CStringW(L""));
            }
        }
    }
    m_bActive = spBuff != 0;
}

// @0x140dcfd40
void CSmartPushAutoFishing::vfunc_3()
{
    if (m_data == 0)
        return;
    unsigned nSale = CGameRule::GetInstance()->FUN_140479900();
    CStringW strText;
    CStringW strTitle;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x24, strText, 0, CStringW(L""));
    if (spBox)
    {
        spBox->FUN_141a01800(1);
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CSmartPushAutoFishing::FUN_140dd0a00));
        spBox->SetBuff(m_data->m_nActionValue, 1,
            BlockFormat<unsigned>(0xc66, *Client::Constants::GetInstance()->extendAutoFishMaxCount.Get()));
        spBox->FUN_141a024a0(0);
        spBox->SetCheckbox0(GetStringCommon(0xc68), 0);
        spBox->SetStrike(strTitle);
        int nCount = CSmartPushTable::GetInstance()->GetPackageCount(CGameRule::GetInstance()->GetAutoFishingName());
        for (int i = 0; i < nCount; i++)
        {
            CSmartPushTable::PackagePtr pkg =
                CSmartPushTable::GetInstance()->GetPackage(CGameRule::GetInstance()->GetAutoFishingName(), i);
            Unk_SetBoxUInt(spBox.operator->(), StringFormat<int>("autoActionMinute{0}", i), pkg->m_nDuration);
            Unk_SetBoxInt64(spBox.operator->(), StringFormat<int>("autoActionMerat{0}", i), pkg->m_nMerat);
            Unk_SetBoxInt64(spBox.operator->(), StringFormat<int>("autoActionMeso{0}", i), pkg->m_nMeso);
        }
        Unk_SetBoxBool(spBox.operator->(), "firstUseRedMerat", FUN_140811640(1));
        Unk_SetBoxString(spBox.operator->(), "actionName", GetStringCommonByKey(L"s_auto_action_fishing"));
        Unk_SetBoxUInt(spBox.operator->(), "saleRate", nSale);
        Unk_SetBoxInt(spBox.operator->(), "packageCount", nCount);
        FUN_140d73c60(spBox);
    }
}

// @0x140dd03e0
void CSmartPushAutoFishing::vfunc_4(int nValue)
{
    CSmartPush::vfunc_4(nValue);
    if (CFishingManager::GetInstance()->FUN_140954150() != 0 && CFishingManager::GetInstance()->FUN_140cdbb90() != 0)
        CFishingManager::GetInstance()->SendFishingMode9();
    CGameOption::GetInstance()->FUN_140c9b8b0()->m_n2c = FUN_140dd06b0();
    CGameOption::GetInstance()->SaveCharacterSettings();
}

// @0x140dd0470
int CSmartPushAutoFishing::vfunc_6()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return 0;
    if (CFishingManager::GetInstance()->FUN_140954150() == 0)
        return 0;
    if (pMy->FUN_1416749a0()->HasEnabledWithEventBuffType(1))
        return 2;
    return 1;
}

// @0x140dd04e0
CStringW CSmartPushAutoFishing::vfunc_7()
{
    if (m_nState == 2)
    {
        CStringW strKey(L"s_smartpush_autofishing_active");
        return GetStringCommonByKey(strKey);
    }
    CStringW strKey(L"s_smartpush_autofishing");
    return GetStringCommonByKey(strKey);
}

// @0x140dd05a0
CStringW CSmartPushAutoFishing::vfunc_8()
{
    return CStringW(L"UISmartPush_autofish");
}

// @0x140dd05f0
CStringW CSmartPushAutoFishing::vfunc_10()
{
    unsigned nSale = CGameRule::GetInstance()->FUN_140479900();
    if (nSale != 0)
    {
        unsigned nRate = nSale / 100;
        return FUN_14028dfa0<unsigned>(CStringW(L"s_smartpush_autoaction_sale_popup"), nRate);
    }
    return CStringW(L"");
}

// @0x140dd06b0
int CSmartPushAutoFishing::FUN_140dd06b0()
{
    CSmartPushTable::PackagePtr pkg =
        CSmartPushTable::GetInstance()->GetPackage(CGameRule::GetInstance()->GetAutoFishingName(), m_n1c);
    if (!pkg)
        return 2;
    if (pkg->m_nMerat != 0)
        return 2;
    if (pkg->m_nMeso != 0)
        return 0;
    return 2;
}

// @0x140dd07b0
bool CSmartPushAutoFishing::FUN_140dd07b0()
{
    CSmartPushTable::PackagePtr pkg =
        CSmartPushTable::GetInstance()->GetPackage(CGameRule::GetInstance()->GetAutoFishingName(), m_n1c);
    if (!pkg)
        return false;
    __int64 nPrice = 0;
    unsigned nSale = CGameRule::GetInstance()->FUN_140479900();
    if (pkg->m_nMerat != 0)
    {
        nPrice = pkg->m_nMerat;
        if (nSale != 0)
            nPrice -= (__int64)(nPrice * (unsigned __int64)nSale) / 10000;
        if (FUN_140811640(m_nId) && ((class IClientPlatform*)FUN_140d86260())->vfunc_41(nPrice) == true)
            return true;
        return ((class IClientPlatform*)FUN_140d86260())->vfunc_40(nPrice);
    }
    else if (pkg->m_nMeso != 0)
    {
        nPrice = pkg->m_nMeso;
        if (nSale != 0)
            nPrice -= (__int64)(nPrice * (unsigned __int64)nSale) / 10000;
        return DAT_143ab2898 >= nPrice;
    }
    return true;
}

// @0x140dd0a00
bool CSmartPushAutoFishing::FUN_140dd0a00(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        int nPos = 0;
        CStringW strResult = data.FUN_141a02d50();
        bool bRedMerat = strResult.Tokenize(L",", nPos).CompareNoCase(L"true") == 0;
        m_n1c = _wtoi(strResult.Tokenize(L",", nPos)) - 1;
        CGameOption::GetInstance()->FUN_140c9b8b0()->m_n24 = m_n1c;
        CGameOption::GetInstance()->SaveCharacterSettings();
        int nOk = FUN_140dd07b0();
        if (nOk == 0)
        {
            if (FUN_140dd06b0() == 2)
                CUIService::GetInstance()->FUN_141add1f0();
            else
                FUN_140d73bc0(0x34, 0, 0, CStringW(L""));
        }
        else
        {
            vfunc_5(false);
        }
        if (bRedMerat && nOk != 0)
            CFishingManager::GetInstance()->FUN_140cdbdf0(*Client::Constants::GetInstance()->extendAutoFishMaxCount.Get());
        else
            CFishingManager::GetInstance()->FUN_140cdbdf0(0);
    }
    else if (nResult == 1)
    {
        return true;
    }
    return true;
}

// ---- CSmartPushAutoPlayInstrument ---------------------------------------------------------------------------------------

// @0x140dd0c30
ClassObject* CSmartPushAutoPlayInstrument::CreateObject()
{
    return new CSmartPushAutoPlayInstrument;
}

// @0x140dd0c90
CStringW CSmartPushAutoPlayInstrument::GetTypeName()
{
    return CStringW(L"CSmartPushAutoPlayInstrument");
}

// @0x140dd0ce0
CSmartPushAutoPlayInstrument::CSmartPushAutoPlayInstrument()
{
    m_bPlaying = 0;
}

// @0x140dd0d20
CSmartPushAutoPlayInstrument::~CSmartPushAutoPlayInstrument()
{
}

// @0x140dd0d50
void CSmartPushAutoPlayInstrument::vfunc_2()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return;
    if (pMy->GetCurStateId() != 0x2f)
        return;
    unsigned nCount;
    int nBlocked = ((class Unk_SpInstrument*)FUN_140c8dac0())->CanPlayEnsemble();
    if (m_bPlaying != 0 && nBlocked == 0)
    {
        nCount = ((class Unk_SpInstrument*)FUN_140c8dac0())->GetVolume();
        if (nCount > 0)
        {
            if (FUN_140dd1ba0())
            {
                --nCount;
                ((class Unk_SpInstrument*)FUN_140c8dac0())->SetVolume(nCount);
                vfunc_5(true);
                CStringW strTime = CSmartPushTable::GetInstance()->GetPackageDurationText(m_data->m_strContent, m_n1c);
                FUN_1412751f0(FUN_14028dfa0<CStringW>(CStringW(L"s_msg_auto_play_instrument_extend_complete"), strTime), 1, 1);
            }
            else
            {
                if (FUN_140dd1aa0() == 2)
                {
                    ((class Unk_SpInstrument*)FUN_140c8dac0())->SetVolume(0);
                    CUIService::GetInstance()->FUN_141add1f0();
                }
                else
                {
                    FUN_140d73bc0(0x34, 0, 0, CStringW(L""));
                }
            }
        }
    }
    else if (m_bPlaying == 0 && nBlocked == 0)
    {
        if (((class Unk_SpInstrument*)FUN_140c8dac0())->GetVolume() == 0 && CUIService::GetInstance()->FUN_141adc890((eUIClassID)0x4f07) != 0)
        {
            CUIService::GetInstance()->CloseDialog((eUIClassID)0x4f07);
            CStringW strKey(L"s_msg_auto_play_instrument_end");
            FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
        }
    }
    else if (m_bPlaying != 0 && nBlocked != 0)
    {
        if (((class Unk_SpInstrument*)FUN_140c8dac0())->IsPerforming() && !((class Unk_SpInstrument*)FUN_140c8dac0())->IsRemote())
        {
            UISystemShopDialog* pAuto = Unk_FmGetDialog<UISystemShopDialog>((eUIClassID)0x4f07);
            UIPlayInstrumentDialog* pPlay = Unk_ImGetDialog<UIPlayInstrumentDialog>((eUIClassID)0x4eec);
            if (pPlay != 0 && pAuto != 0 && pAuto->FUN_141924630() == 0 && pPlay->GetAutoPlay() != 0)
            {
                pAuto->SetMode(5);
                pAuto->FUN_141924680();
            }
        }
    }
    m_bPlaying = nBlocked;
}

// @0x140dd1100
void CSmartPushAutoPlayInstrument::vfunc_3()
{
    if (m_data == 0)
        return;
    unsigned nSale = CGameRule::GetInstance()->FUN_140479a20();
    CStringW strText;
    CStringW strTitle;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x24, strText, 0, CStringW(L""));
    if (spBox)
    {
        spBox->FUN_141a01800(1);
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CSmartPushAutoPlayInstrument::FUN_140dd1df0));
        spBox->SetBuff(m_data->m_nActionValue, 1,
            FUN_14028dfa0<unsigned>(CStringW(L"s_msg_auto_play_instrument_extend_desc"),
                *Client::Constants::GetInstance()->extendAutoPlayInstrumentMaxCount.Get()));
        spBox->FUN_141a024a0(0);
        spBox->SetCheckbox0(GetStringCommonByKey(L"s_system_auto_play_instrument_extend"), 0);
        spBox->SetStrike(strTitle);
        int nCount = CSmartPushTable::GetInstance()->GetPackageCount(CGameRule::GetInstance()->GetAutoPlayInstrumentName());
        for (int i = 0; i < nCount; i++)
        {
            CSmartPushTable::PackagePtr pkg =
                CSmartPushTable::GetInstance()->GetPackage(CGameRule::GetInstance()->GetAutoPlayInstrumentName(), i);
            Unk_SetBoxUInt(spBox.operator->(), StringFormat<int>("autoActionMinute{0}", i), pkg->m_nDuration);
            Unk_SetBoxInt64(spBox.operator->(), StringFormat<int>("autoActionMerat{0}", i), pkg->m_nMerat);
            Unk_SetBoxInt64(spBox.operator->(), StringFormat<int>("autoActionMeso{0}", i), pkg->m_nMeso);
        }
        Unk_SetBoxBool(spBox.operator->(), "firstUseRedMerat", FUN_140811640(4));
        Unk_SetBoxString(spBox.operator->(), "actionName", GetStringCommonByKey(L"s_auto_action_play_instrument"));
        Unk_SetBoxUInt(spBox.operator->(), "saleRate", nSale);
        Unk_SetBoxInt(spBox.operator->(), "packageCount", nCount);
        FUN_140d73c60(spBox);
    }
}

// @0x140dd1800
void CSmartPushAutoPlayInstrument::vfunc_4(int nValue)
{
    CSmartPush::vfunc_4(nValue);
}

// @0x140dd1830
int CSmartPushAutoPlayInstrument::vfunc_6()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return 0;
    if (pMy->GetCurStateId() != 0x2f)
        return 0;
    if (!((class Unk_SpInstrument*)FUN_140c8dac0())->IsPerforming())
        return 0;
    if (((class Unk_SpInstrument*)FUN_140c8dac0())->IsRemote())
        return 0;
    if (((class Unk_SpInstrument*)FUN_140c8dac0())->CanPlayEnsemble())
        return 2;
    return 1;
}

// @0x140dd18d0
CStringW CSmartPushAutoPlayInstrument::vfunc_7()
{
    if (m_nState == 2)
    {
        CStringW strKey(L"s_msg_auto_play_instrument_active");
        return GetStringCommonByKey(strKey);
    }
    CStringW strKey(L"s_msg_auto_play_instrument");
    return GetStringCommonByKey(strKey);
}

// @0x140dd1990
CStringW CSmartPushAutoPlayInstrument::vfunc_8()
{
    return CStringW(L"UISmartPush_autofish");
}

// @0x140dd19e0
CStringW CSmartPushAutoPlayInstrument::vfunc_10()
{
    unsigned nSale = CGameRule::GetInstance()->FUN_140479a20();
    if (nSale != 0)
    {
        unsigned nRate = nSale / 100;
        return FUN_14028dfa0<unsigned>(CStringW(L"s_smartpush_autoaction_sale_popup"), nRate);
    }
    return CStringW(L"");
}

// @0x140dd1aa0
int CSmartPushAutoPlayInstrument::FUN_140dd1aa0()
{
    CSmartPushTable::PackagePtr pkg =
        CSmartPushTable::GetInstance()->GetPackage(CGameRule::GetInstance()->GetAutoPlayInstrumentName(), m_n1c);
    if (!pkg)
        return 2;
    if (pkg->m_nMerat != 0)
        return 2;
    if (pkg->m_nMeso != 0)
        return 0;
    return 2;
}

// @0x140dd1ba0
bool CSmartPushAutoPlayInstrument::FUN_140dd1ba0()
{
    CSmartPushTable::PackagePtr pkg =
        CSmartPushTable::GetInstance()->GetPackage(CGameRule::GetInstance()->GetAutoPlayInstrumentName(), m_n1c);
    if (!pkg)
        return false;
    __int64 nPrice = 0;
    unsigned nSale = CGameRule::GetInstance()->FUN_140479a20();
    if (pkg->m_nMerat != 0)
    {
        nPrice = pkg->m_nMerat;
        if (nSale != 0)
            nPrice -= (__int64)(nPrice * (unsigned __int64)nSale) / 10000;
        if (FUN_140811640(m_nId) && ((class IClientPlatform*)FUN_140d86260())->vfunc_41(nPrice) == true)
            return true;
        return ((class IClientPlatform*)FUN_140d86260())->vfunc_40(nPrice);
    }
    else if (pkg->m_nMeso != 0)
    {
        nPrice = pkg->m_nMeso;
        if (nSale != 0)
            nPrice -= (__int64)(nPrice * (unsigned __int64)nSale) / 10000;
        return DAT_143ab2898 >= nPrice;
    }
    return true;
}

// @0x140dd1df0
bool CSmartPushAutoPlayInstrument::FUN_140dd1df0(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        int nPos = 0;
        CStringW strResult = data.FUN_141a02d50();
        bool bRedMerat = strResult.Tokenize(L",", nPos).CompareNoCase(L"true") == 0;
        m_n1c = _wtoi(strResult.Tokenize(L",", nPos)) - 1;
        CGameOption::GetInstance()->FUN_140c9b8b0()->m_n28 = m_n1c;
        CGameOption::GetInstance()->SaveCharacterSettings();
        int nOk = FUN_140dd1ba0();
        if (nOk == 0)
        {
            if (FUN_140dd1aa0() == 2)
                CUIService::GetInstance()->FUN_141add1f0();
            else
                FUN_140d73bc0(0x34, 0, 0, CStringW(L""));
        }
        else
        {
            vfunc_5(false);
        }
        if (bRedMerat && nOk != 0)
            ((class Unk_SpInstrument*)FUN_140c8dac0())->SetVolume(*Client::Constants::GetInstance()->extendAutoPlayInstrumentMaxCount.Get());
        else
            ((class Unk_SpInstrument*)FUN_140c8dac0())->SetVolume(0);
    }
    else if (nResult == 1)
    {
        return true;
    }
    return true;
}

// ---- CSmartPushSafeRiding -----------------------------------------------------------------------------------------------

// @0x140dd2020
ClassObject* CSmartPushSafeRiding::CreateObject()
{
    return new CSmartPushSafeRiding;
}

// @0x140dd2080
CStringW CSmartPushSafeRiding::GetTypeName()
{
    return CStringW(L"CSmartPushSafeRiding");
}

// @0x140dd20d0
CSmartPushSafeRiding::CSmartPushSafeRiding()
{
}

// @0x140dd2110
CSmartPushSafeRiding::~CSmartPushSafeRiding()
{
}

// @0x140dd2140
int CSmartPushSafeRiding::vfunc_6()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return 0;
    if (pMy->FUN_1416764d0() == 0)
        return 0;
    if (pMy->FUN_1416764a0()->GetData()->m_basic.m_nType == 1)
        return 0;
    if (pMy->FUN_1416764a0()->GetData()->m_basic.m_nType == 2)
        return 0;
    if (pMy->FUN_1416749a0()->HasEnabledWithEventBuffType(2))
        return 2;
    return 1;
}

// @0x140dd22a0
CStringW CSmartPushSafeRiding::vfunc_7()
{
    if (m_nState == 2)
    {
        CStringW strKey(L"s_smartpush_saferiding_active");
        return GetStringCommonByKey(strKey);
    }
    CStringW strKey(L"s_smartpush_saferiding");
    return GetStringCommonByKey(strKey);
}

// @0x140dd2360
CStringW CSmartPushSafeRiding::vfunc_9()
{
    if (FUN_140811640(2))
        return FUN_14028dfa0<__int64>(CStringW(L"s_smartpush_saferiding_rbmerat_desc"), m_data->m_nRequireMerat);
    return FUN_14028dfa0<__int64>(CStringW(L"s_smartpush_saferiding_desc"), m_data->m_nRequireMerat);
}

// @0x140dd2470
bool CSmartPushSafeRiding::vfunc_12()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return false;
    if (((class CAdventureLevelTableHelper*)FUN_140ba4fa0())->IsReached(pMy->vfunc_141()))
        return true;
    return false;
}

// ---- CSmartPushSafeWaterRiding ------------------------------------------------------------------------------------------

// @0x140dd24e0
ClassObject* CSmartPushSafeWaterRiding::CreateObject()
{
    return new CSmartPushSafeWaterRiding;
}

// @0x140dd2540
CStringW CSmartPushSafeWaterRiding::GetTypeName()
{
    return CStringW(L"CSmartPushSafeWaterRiding");
}

// @0x140dd2590
CSmartPushSafeWaterRiding::CSmartPushSafeWaterRiding()
{
}

// @0x140dd25d0
CSmartPushSafeWaterRiding::~CSmartPushSafeWaterRiding()
{
}

// @0x140dd2600
int CSmartPushSafeWaterRiding::vfunc_6()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return 0;
    if (pMy->FUN_1416764d0() == 0)
        return 0;
    if (pMy->FUN_1416764a0()->GetData()->m_basic.m_nType == 1)
        return 0;
    if (pMy->FUN_1416764a0()->GetData()->m_basic.m_nType == 2)
        return 0;
    if (((class CAdventureLevelTableHelper*)FUN_140ba4fa0())->IsReached(pMy->vfunc_141()))
        return 0;
    if (pMy->FUN_1416749a0()->HasEnabledWithEventBuffType(3))
        return 2;
    return 1;
}

// @0x140dd2790
CStringW CSmartPushSafeWaterRiding::vfunc_7()
{
    if (m_nState == 2)
    {
        CStringW strKey(L"s_smartpush_saferiding_water_active");
        return GetStringCommonByKey(strKey);
    }
    CStringW strKey(L"s_smartpush_saferiding_water");
    return GetStringCommonByKey(strKey);
}

// @0x140dd2850
CStringW CSmartPushSafeWaterRiding::vfunc_9()
{
    if (FUN_140811640(3))
        return FUN_14028dfa0<__int64>(CStringW(L"s_smartpush_saferiding_water_rbmerat_desc"), m_data->m_nRequireMerat);
    return FUN_14028dfa0<__int64>(CStringW(L"s_smartpush_saferiding_water_desc"), m_data->m_nRequireMerat);
}

// ---- CSmartPushSafeWaterRidingToggle ------------------------------------------------------------------------------------

// @0x140dd2960
ClassObject* CSmartPushSafeWaterRidingToggle::CreateObject()
{
    return new CSmartPushSafeWaterRidingToggle;
}

// @0x140dd29c0
CStringW CSmartPushSafeWaterRidingToggle::GetTypeName()
{
    return CStringW(L"CSmartPushSafeWaterRidingToggle");
}

// @0x140dd2a10
CSmartPushSafeWaterRidingToggle::CSmartPushSafeWaterRidingToggle()
{
}

// @0x140dd2a50
CSmartPushSafeWaterRidingToggle::~CSmartPushSafeWaterRidingToggle()
{
}

// @0x140dd2a80
void CSmartPushSafeWaterRidingToggle::vfunc_3()
{
    if (m_data == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::SmartPush), 0);
    packet.WriteInt32(m_nId);
    packet.WriteInt32(m_n1c);
    packet.WriteInt32(0);
    packet.WriteBool(false);
    FUN_140710590(packet);
}

// @0x140dd2b20
void CSmartPushSafeWaterRidingToggle::vfunc_13()
{
}

// @0x140dd2b30
int CSmartPushSafeWaterRidingToggle::vfunc_6()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return 0;
    if (pMy->FUN_1416764d0() == 0)
        return 0;
    if (pMy->FUN_1416764a0()->GetData()->m_basic.m_nType == 1)
        return 0;
    if (pMy->FUN_1416764a0()->GetData()->m_basic.m_nType == 2)
        return 0;
    if (!((class CAdventureLevelTableHelper*)FUN_140ba4fa0())->IsReached(pMy->vfunc_141()))
        return 0;
    if (pMy->FUN_1416749a0()->HasEnabledWithEventBuffType(3))
        return 2;
    return 1;
}

// @0x140dd2cc0
CStringW CSmartPushSafeWaterRidingToggle::vfunc_7()
{
    if (m_nState == 2)
    {
        CStringW strKey(L"s_smartpush_saferiding_water_active");
        return GetStringCommonByKey(strKey);
    }
    CStringW strKey(L"s_smartpush_saferiding_water");
    return GetStringCommonByKey(strKey);
}

// @0x140dd2d80
bool CSmartPushSafeWaterRidingToggle::vfunc_11()
{
    return true;
}

// @0x140dd2d90
void CSmartPushSafeWaterRidingToggle::vfunc_4(int nValue)
{
}

// ---- CSmartPushAutoInteraction ------------------------------------------------------------------------------------------

// @0x140dd2da0
void CSmartPushAutoInteraction::vfunc_4(int nValue)
{
    CStringW strMastery = m_data->m_strContent;
    FUN_140841420(strMastery);
    int nRecipe = vfunc_14();
    FUN_1412751f0(FUN_14028dfa0<int, CStringW>(CStringW(L"s_mastery_autointeraction_result"), nValue,
        CStringTable::GetInstance()->FUN_141811980(0x2f, nRecipe)), 3, 1);
    int nUsed = 0;
    reinterpret_cast<CGatherCountMap*>(&g_143ab3150)->Lookup(nRecipe, nUsed);
    reinterpret_cast<CGatherCountMap*>(&g_143ab3150)->SetAt(nRecipe, nUsed + nValue);
}

// @0x140dd2f10
CStringW CSmartPushAutoInteraction::vfunc_7()
{
    CStringW strMastery = m_data->m_strContent;
    strMastery.MakeLower();
    CStringW strKey = StringFormat<CStringW>(L"s_mastery_{0}_button", strMastery);
    return GetStringCommonByKey(strKey);
}

// MS2-FUNCTIONAL: the exe spills the gathering max count to a temp before subtracting the used count (5 instructions); the rest matches
// @0x140dd2fc0
void CSmartPushAutoInteraction::vfunc_3()
{
    CStringW strMastery = m_data->m_strContent;
    FUN_140841420(strMastery);
    CStringW strMsg = StringFormat<CStringW>(L"s_mastery_{0}_msgbox_msg", strMastery);
    CStringW strBuff = StringFormat<CStringW>(L"s_mastery_{0}_msgbox_buff", strMastery);
    CStringW strText = FUN_14028dfa0<CStringW>(strMsg, CStringTable::GetInstance()->FUN_141811980(0x2f, vfunc_14()));
    int nRecipe = vfunc_14();
    unsigned nItemId = m_data->m_requireItem.FUN_14026b500();
    CStringW strDesc = FUN_14028dfa0(strBuff, nItemId, nRecipe);
    CReservedWordTable::GetInstance()->ReplaceObjectAndValueWords(strDesc);
    int nId = vfunc_14();
    CMasteryTable::ReceipePtr spRecipe = ((class CMasteryTable*)FUN_1409670c0())->Find(nId);
    if (!spRecipe)
        return;
    int nUsed = 0;
    reinterpret_cast<CGatherCountMap*>(&g_143ab3150)->Lookup(nId, nUsed);
    int nMax = ((class CLua*)FUN_1401c0db0())->CalcGatheringObjectgMaxCount(spRecipe->m_nHighPropLimit, spRecipe->m_nNormalPropLimit);
    int nAvail = nMax - nUsed;
    if (nAvail == 0)
    {
        FUN_1412751f0(FUN_140298ea0(L"s_mastery_autointeraction_none_available_count"), 1, 1);
        return;
    }
    int nHave = 0;
    if (m_data->m_requireItem.m_b != 0)
        nHave = reinterpret_cast<Unk_SpInventory&>(g_143ab2a90).FUN_140a5f780(m_data->m_requireItem.m_b, 0);
    else
        nHave = reinterpret_cast<Unk_SpInventory&>(g_143ab2a90).FUN_140a5f180(m_data->m_requireItem.FUN_14026b500(), 0);
    if (nHave == 0)
    {
        FUN_1412751f0(FUN_14028dfa0<CStringW>(L"s_mastery_autointeraction_lack_item",
            CStringTable::GetInstance()->FUN_141811980(1, m_data->m_requireItem.FUN_14026b500())), 1, 1);
        return;
    }
    int nUse = 0;
    nUse = std::min(nHave, nAvail);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x26, strText, 0, L"");
    if (spBox)
    {
        MS2Ptr<CItem> spItem(new CItem);
        int nItem = m_data->m_requireItem.FUN_14026b500();
        if (static_cast<CItem*>(spItem)->FUN_140523c40(nItem, FUN_14053feb0(nItem), 0))
        {
            static_cast<CItem*>(spItem)->SetCountClamped(m_data->m_requireItem.m_c);
            Unk_SetBoxString(spBox.operator->(), "buffIcon", m_data->m_strImgPath);
            Unk_SetBoxString(spBox.operator->(), "buffDesc", strDesc);
            spBox->FUN_141a01800(1);
            spBox->FUN_141a01ee0(spItem, static_cast<CItem*>(spItem)->FUN_140527b10(), 1, m_data->m_requireItem.m_c, nUse, -1, 1);
            spBox->FUN_141a024a0(0);
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CSmartPushAutoInteraction::FUN_140dd3a70));
        }
        FUN_140d73c60(spBox);
    }
}

// @0x140dd3a70
bool CSmartPushAutoInteraction::FUN_140dd3a70(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return true;
    CStringW strCount = data.FUN_141a02d50();
    strCount.Remove(L',');
    int nRecipe = vfunc_14();
    int nCount = FUN_1407181a0(strCount);
    if (pMy->FUN_1416764d0())
    {
        MS2Ptr<RideOffActionAutoInteraction> spAction(new RideOffActionAutoInteraction(0));
        spAction->m_n28 = m_data->m_nId;
        spAction->m_n2c = nCount;
        spAction->m_n30 = nRecipe;
        pMy->SendRequestRideMode1(spAction.get());
    }
    else
    {
        StateData* pData = new StateAutoInteractionData(m_data->m_nId, nCount, nRecipe);
        pMy->vfunc_59(0x39, pData, 0, 0);
    }
    return true;
}

// ---- CSmartPushAutoInteractObject ---------------------------------------------------------------------------------------

// @0x140dd3cb0
int CSmartPushAutoInteractObject::vfunc_6()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return 0;
    CInteractGatheringObject* pObj = FUN_140dd3dd0();
    if (pObj != 0 && pObj->FUN_141402c90())
        return 1;
    return 0;
}

// @0x140dd3d10
int CSmartPushAutoInteractObject::vfunc_13()
{
    return WorldService::GetInstance()->FUN_141bd99d0(vfunc_14());
}

// @0x140dd3d50
int CSmartPushAutoInteractObject::vfunc_14()
{
    CInteractGatheringObject* pObj = FUN_140dd3dd0();
    if (pObj == 0)
        return 0;
    return pObj->GetRow()->m_gathering.m_nReceipeId;
}

// @0x140dd3dd0
CInteractGatheringObject* CSmartPushAutoInteractObject::FUN_140dd3dd0()
{
    Unk_SpGameObj* pMy = static_cast<Unk_SpGameObj*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return 0;
    int nKind = m_data->m_nActionValue;
    ATL::CAtlArray<MS2Ptr<CInteractObject> > objects;
    WorldService::GetInstance()->FUN_141bc5fb0(&objects, 6);
    for (size_t i = 0; i < objects.GetCount(); i++)
    {
        CInteractObject* pObj = objects[i];
        CMasteryTable::ReceipePtr spRecipe = ((class CMasteryTable*)FUN_1409670c0())->Find(pObj->GetRow()->m_gathering.m_nReceipeId);
        if (!spRecipe)
            continue;
        if (spRecipe->m_nType != nKind)
            continue;
        float fRange = pObj->GetRow()->m_validate.m_fInteractionDistance;
        float fDist = pMy->vfunc_18().FUN_140965c40(pObj->GetPos()).FUN_140967ac0();
        if (fDist > fRange)
            continue;
        return dynamic_cast<CInteractGatheringObject*>(pObj);
    }
    return 0;
}

// ---- CSmartPushAutoFunctionCubeObject -----------------------------------------------------------------------------------

// @0x140dd40a0
int CSmartPushAutoFunctionCubeObject::vfunc_6()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return 0;
    if (reinterpret_cast<PC*>(pMy)->GetCubeMode() != 0)
        return 0;
    if (!((class Unk_SpHome*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d5640())
        return 0;
    CHomemadeCubeObject* pCube = FUN_140dd4230();
    if (pCube != 0 && pCube->FUN_141229000(1) != 0)
        return 1;
    return 0;
}

// @0x140dd4130
int CSmartPushAutoFunctionCubeObject::vfunc_13()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return 0;
    return FUN_1409670b0()->FUN_141232430(vfunc_14(), reinterpret_cast<PC*>(pMy)->FUN_141656ad0());
}

// @0x140dd41b0
int CSmartPushAutoFunctionCubeObject::vfunc_14()
{
    CHomemadeCubeObject* pCube = FUN_140dd4230();
    if (pCube == 0)
        return 0;
    return pCube->FUN_140ca6580()->m_n100;
}

// @0x140dd4230
CHomemadeCubeObject* CSmartPushAutoFunctionCubeObject::FUN_140dd4230()
{
    MyPC* pMy = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMy == 0)
        return 0;
    int nKind = m_data->m_nActionValue;
    MS2Ptr<CFunctionCubeObject> spCube(0);
    switch (nKind)
    {
    case 6:
    {
        spCube = FUN_1409670b0()->FUN_141231200(reinterpret_cast<Unk_SpGameObj*>(pMy)->vfunc_18(),
            Client::Constants::GetInstance()->FunctionCubeDistance.Read(), reinterpret_cast<PC*>(pMy)->FUN_141656ad0(), 8);
        break;
    }
    case 5:
    {
        spCube = FUN_1409670b0()->FUN_141231200(reinterpret_cast<Unk_SpGameObj*>(pMy)->vfunc_18(),
            Client::Constants::GetInstance()->FunctionCubeDistance.Read(), reinterpret_cast<PC*>(pMy)->FUN_141656ad0(), 7);
        break;
    }
    }
    if (spCube.operator->())
        return dynamic_cast<CHomemadeCubeObject*>(spCube.get());
    return 0;
}

// ---- The concrete auto interactions -------------------------------------------------------------------------------------

// @0x140dd44c0
ClassObject* CSmartPushAutoGathering::CreateObject()
{
    return new CSmartPushAutoGathering;
}

// @0x140dd4520
CStringW CSmartPushAutoGathering::GetTypeName()
{
    return CStringW(L"CSmartPushAutoGathering");
}

// @0x140dd4570
ClassObject* CSmartPushAutoMining::CreateObject()
{
    return new CSmartPushAutoMining;
}

// @0x140dd45d0
CStringW CSmartPushAutoMining::GetTypeName()
{
    return CStringW(L"CSmartPushAutoMining");
}

// @0x140dd4620
ClassObject* CSmartPushAutoBreeding::CreateObject()
{
    return new CSmartPushAutoBreeding;
}

// @0x140dd4680
CStringW CSmartPushAutoBreeding::GetTypeName()
{
    return CStringW(L"CSmartPushAutoBreeding");
}

// @0x140dd46d0
ClassObject* CSmartPushAutoFarming::CreateObject()
{
    return new CSmartPushAutoFarming;
}

// @0x140dd4730
CStringW CSmartPushAutoFarming::GetTypeName()
{
    return CStringW(L"CSmartPushAutoFarming");
}

// ---- The buff item forms ------------------------------------------------------------------------------------------------

// @0x140dd4780
void CSmartPushAutoInteractObjectBuffItem::vfunc_3()
{
    CStringW strMastery = m_data->m_strContent;
    FUN_140841420(strMastery);
    int nItemId = vfunc_14();
    if (nItemId == 0)
    {
        CStringW strButton = StringFormat<CStringW>(L"s_mastery_{0}_button", strMastery);
        FUN_140d73aa0(FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_autointeraction_lack_buff_item"), GetStringCommonByKey(strButton)),
            0, 0, CStringW(L""));
        return;
    }
    CStringW strText = FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_autointeraction_buff_use"),
        CStringTable::GetInstance()->FUN_141811980(1, nItemId));
    CReservedWordTable::GetInstance()->ReplaceObjectAndValueWords(strText);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strText, 0, CStringW(L""));
    if (spBox.get())
    {
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CSmartPushAutoInteractObjectBuffItem::FUN_140dd4b70));
        FUN_140d73c60(spBox);
    }
}

// @0x140dd4b40
int CSmartPushAutoInteractObjectBuffItem::vfunc_14()
{
    return FUN_140dd5340(m_nAbility);
}

// @0x140dd4b70
bool CSmartPushAutoInteractObjectBuffItem::FUN_140dd4b70(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        MS2Ptr<CItem> spItem = reinterpret_cast<Unk_SpInventory&>(g_143ab2a90).FUN_140a5e2e0(vfunc_14());
        if (spItem.get())
            reinterpret_cast<Unk_SpInventory&>(g_143ab2a90).FUN_140a635f0(spItem.get());
    }
    return true;
}

// @0x140dd4c00
void CSmartPushAutoFunctionCubeObjectBuffItem::vfunc_3()
{
    CStringW strMastery = m_data->m_strContent;
    FUN_140841420(strMastery);
    int nItemId = vfunc_14();
    if (nItemId == 0)
    {
        CStringW strButton = StringFormat<CStringW>(L"s_mastery_{0}_button", strMastery);
        FUN_140d73aa0(FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_autointeraction_lack_buff_item"), GetStringCommonByKey(strButton)),
            0, 0, CStringW(L""));
        return;
    }
    CStringW strText = FUN_14028dfa0<CStringW>(CStringW(L"s_mastery_autointeraction_buff_use"),
        CStringTable::GetInstance()->FUN_141811980(1, nItemId));
    CReservedWordTable::GetInstance()->ReplaceObjectAndValueWords(strText);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strText, 0, CStringW(L""));
    if (spBox.get())
    {
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CSmartPushAutoFunctionCubeObjectBuffItem::FUN_140dd4ff0));
        FUN_140d73c60(spBox);
    }
}

// @0x140dd4fc0
int CSmartPushAutoFunctionCubeObjectBuffItem::vfunc_14()
{
    return FUN_140dd5340(m_nAbility);
}

// @0x140dd4ff0
bool CSmartPushAutoFunctionCubeObjectBuffItem::FUN_140dd4ff0(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        MS2Ptr<CItem> spItem = reinterpret_cast<Unk_SpInventory&>(g_143ab2a90).FUN_140a5e2e0(vfunc_14());
        if (spItem.get())
            reinterpret_cast<Unk_SpInventory&>(g_143ab2a90).FUN_140a635f0(spItem.get());
    }
    return true;
}

// @0x140dd5080
ClassObject* CSmartPushAutoGatheringBuff::CreateObject()
{
    return new CSmartPushAutoGatheringBuff;
}

// @0x140dd50e0
CStringW CSmartPushAutoGatheringBuff::GetTypeName()
{
    return CStringW(L"CSmartPushAutoGatheringBuff");
}

// @0x140dd5130
ClassObject* CSmartPushAutoMiningBuff::CreateObject()
{
    return new CSmartPushAutoMiningBuff;
}

// @0x140dd5190
CStringW CSmartPushAutoMiningBuff::GetTypeName()
{
    return CStringW(L"CSmartPushAutoMiningBuff");
}

// @0x140dd51e0
ClassObject* CSmartPushAutoBreedingBuff::CreateObject()
{
    return new CSmartPushAutoBreedingBuff;
}

// @0x140dd5240
CStringW CSmartPushAutoBreedingBuff::GetTypeName()
{
    return CStringW(L"CSmartPushAutoBreedingBuff");
}

// @0x140dd5290
ClassObject* CSmartPushAutoFarmingBuff::CreateObject()
{
    return new CSmartPushAutoFarmingBuff;
}

// @0x140dd52f0
CStringW CSmartPushAutoFarmingBuff::GetTypeName()
{
    return CStringW(L"CSmartPushAutoFarmingBuff");
}

// @0x140dd5340
int FUN_140dd5340(int nAbility)
{
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    reinterpret_cast<Unk_SpInventory&>(g_143ab2a90).FUN_140a60880(10, items);
    unsigned nBest = 0;
    int nItemId = 0;
    for (size_t i = 0; i < items.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = items[i];
        if (spItem == 0 || ((CItemData*)(static_cast<CItem*>(spItem)->FUN_140527840())) == 0)
            continue;
        if (((CItemData*)(static_cast<CItem*>(spItem)->FUN_140527840()))->FUN_14053dc20() == 0)
            continue;
        MS2Ptr<SkillLevelData> spSkill = TSingleton<SkillDataTableCli>::GetInstance()->GetSkillLevelData(((CItemData*)(static_cast<CItem*>(spItem)->FUN_140527840()))->FUN_14053dc20(), ((CItemData*)(static_cast<CItem*>(spItem)->FUN_140527840()))->FUN_14053dc40());
        if (spSkill.get())
        {
            std::vector<MS2Ptr<SkillActionAdditional> >& effects = spSkill->m_vAdditional;
            for (MS2Ptr<SkillActionAdditional> *p = effects._Unchecked_begin(), *pEnd = effects._Unchecked_end(); p != pEnd; ++p)
            {
                MS2Ptr<SkillActionAdditional>& effect = *p;
                MS2Ptr<AdditionalLevelData> spBuff = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(effect->m_nAdditionalID, effect->m_nLevel);
                if (spBuff == 0)
                    continue;
                if (spBuff->HasSA((SAType)nAbility) && nBest < spBuff->m_nDurationTick)
                {
                    nItemId = static_cast<CItem*>(spItem)->FUN_1405276c0();
                    nBest = spBuff->m_nDurationTick;
                    break;
                }
            }
        }
    }
    return nItemId;
}

// @0x140dd7930
void CSmartPush::vfunc_2()
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca5bd0-0x142ca5c60 .text$yd
