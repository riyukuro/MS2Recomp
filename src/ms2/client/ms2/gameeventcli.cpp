// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Client side of the GameEvent family: see gameeventcli.h.
// MS2-UNIT: client\ms2\gameeventcli.cpp
// MS2-RANGE: 0x1400d0b50-0x1400d1640 .text$di
// MS2-RANGE: 0x140ce27f0-0x140ceaa70 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVGameEventBurningLevelupCli@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x140ce7e90 ; prop
// MS2-PIN: ??$?8PEAVGameEventBurningLevelupCli@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x140ce7ee0 ; prop
// MS2-PIN: ??$?8PEAVGameEventDTRewardCli@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVGameEventDTRewardCli@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x140ce7f30 ; prop
// MS2-PIN: ??$?8PEAVGameEventItemBuffCli@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVGameEventItemBuffCli@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x140ce7f80 ; prop
// MS2-PIN: ??$?8PEAVGameEventSnowmanCli@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVGameEventSnowmanCli@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x140ce7fd0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x140ce8850 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVGameEventSnowmanCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x140ce8ad0 ; fx13: lea vftable 0x142e20ea8 (Snowman per RTTI); 0x140ce88f0 is BurningLevelup's
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAA@XZ 0x140ce9350 ; order
// MS2-PIN: ??1?$MS2Ptr@UItemGift@@@@QEAA@XZ 0x140ce93d0 ; prop
// MS2-PIN: ??8?$MS2Ptr@VUnk_CashAttendEntry@@@@QEBA_NPEAVUnk_CashAttendEntry@@@Z 0x140ce9880 ; unique
// MS2-PIN: ??A?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAAAEAI_K@Z 0x140ce98c0 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAPEAXI@Z 0x140ce9930 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x140ce9970 ; order
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVGameEventDTRewardCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x140ce99b0 ; order
// MS2-PIN: ??_GCWin32Heap@ATL@@UEAAPEAXI@Z 0x140ce9a30 ; order
// MS2-PIN: ?Reference@?$MS2Ptr@VEventIconInfo@@@@CAXPEAVEventIconInfo@@@Z 0x140cea200 ; unique
// MS2-PIN: ?Release@?$MS2Ptr@VDungeonExtraRewardCountCtx@@@@AEAAXXZ 0x140cea2c0 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VSnowmanContext@@@@AEAAXPEAX@Z 0x140cea300 ; prop
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140cea3a0 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140cea400 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVGameEventDTRewardCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140cea460 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVGameEventItemBuffCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140cea4c0 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVGameEventSnowmanCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140cea520 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x140cea5e0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140cea610 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVGameEventDTRewardCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140cea640 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVGameEventItemBuffCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140cea670 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVGameEventSnowmanCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140cea6a0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUICoupleDanceEventDialog@@P81@EAAXPEAVGameEventVariable@@@Z@std@@@?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@UEAAXPEAVGameEventVariable@@@Z 0x140cea6d0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140cea830 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVGameEventBurningLevelupCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140cea890 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVGameEventDTRewardCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140cea8f0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVGameEventItemBuffCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140cea950 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVGameEventSnowmanCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140cea9b0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICoupleDanceEventDialog@@P81@EAAXPEAVGameEventVariable@@@Z@std@@@?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140ceaa10 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_sortNames8A@@YAXXZ 0x1400d11e0
// MS2-PIN: ??__Es_sortNames8B@@YAXXZ 0x1400d14b0
// MS2-PIN: ??0?$MS2Ptr@VEventIconInfo@@@@QEAA@PEAVEventIconInfo@@@Z 0x140ce8c50
// MS2-PIN: ??1GameEventTrafficOptimizerCli@@UEAA@XZ 0x140ce96b0
// MS2-PIN: ??0RpsGameData@@QEAA@XZ 0x140ce9290
// MS2-PIN: ??1RpsGameData@@UEAA@XZ 0x140ce97a0
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVGameEventItemBuffCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAA@XZ 0x140ce9370
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVGameEventItemBuffCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x140ce99f0
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVGameEventSnowmanCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAA@XZ 0x140ce9390
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVGameEventSnowmanCli@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x140ce9a30
// MS2-FUNCTIONAL ??1RpsGameData@@UEAA@XZ: RpsGameData +0x18..+0x50 is a nested play struct { CStringW names[3]; CAtlArray<CStringW> messages; } in the exe with its own implicit ctor 0x140ce91f0 / dtor 0x140ce9720 (one call each in RpsGameData's ctor/dtor); gameevent.h keeps the members flat (statemicrogame.cpp / gameeventcontext.cpp access them directly)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameeventcli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gameeventcli.h"
#include "ms2/commonfiles/dtrewardeventcontext.h"
#include "uidteventdialog.h"
#include "uisnowmaneventdialog.h"
#include "uirpseventdialog.h"
#include "uicoupledanceeventdialog.h"
#include "ms2/placeholder/cgamerule.h"
#include "uientereventfielddialog.h"
#include "uisystemmailnotifydialog.h"
#include "uigamemenudialog.h"
#include "uiattendgiftdialog.h"
#include "uicashattenddialog.h"
#include "uileveluppackagewidgetdialog.h"
#include "uimessageboxdata.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "uiservice.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/trafficoptimizer.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit helpers.
// Constructor at 0x140316aa0: registers the factory under the name (the by-value CString is destroyed by the callee).
struct Unk_GEFactoryRegistry {
    Unk_GEFactoryRegistry(CStringW name, GameEvent* (*create)());
    char m_pad;
};
class Unk_SingletonObj;
CStringTable* FUN_1401a9d70();                                  // the string table singleton
__int64 FUN_140869440();                                        // the server time
UIGameMenuDialog* FUN_140938b90(unsigned nUIId);                // the game menu bar
NotifySystem* FUN_140939a10();                                  // TSingleton<NotifySystem>::GetInstance
// The event-key table at 0x143ab2fc0: (kind, id) -> value, read through the typed lookups below.
class Unk_CliEvtKeys {
public:
    int Get(int nKey, unsigned* pOut);                          // 0x140ce8590 (COMDAT wrapper below)
    int FUN_1409617d0(int nKind, unsigned nId, const int& nDefault);
    bool FUN_140482280(int nKind, const bool& bDefault);
    unsigned char FUN_14041f940(int nKind);
    int FUN_140c6d8d0(int nKind, int nId, const int& nDefault);
    __int64 FUN_140be8f80(int nKind, unsigned nId, const __int64& nDefault);
    unsigned __int64 FUN_140c5af20(int nKind, unsigned nId, const __int64* pDefault);
};
extern unsigned __int64 DAT_143ab2828;
extern Unk_CliEvtKeys DAT_143ab2fc0;
// @0x140ce8590
int Unk_CliEvtKeys::Get(int nKey, unsigned* pOut) { return FUN_1409617d0(nKey, 0, *(const int*)pOut); }
void FUN_14086a6c0(const CMsTime& t);                           // checks the time is valid
class Unk_CliClock { public: int FUN_141473560(); };            // seconds until the day ended
Unk_CliClock* FUN_14086d260();
void* FUN_140931510();                                          // the dungeon room manager
__int64 FUN_140d9f580(void* pMgr, unsigned nId);                // the room's end time
CStringW FUN_140275590(const wchar_t* pszFormat, const CStringW& a, const int& b);   // {0}({1})
void* FUN_140c053e0(int nId);                                   // the attend gift dialog (UIAttendGiftDialog)
class Unk_CliTextFilter { public: CStringW FUN_14087ede0(const CStringW& str); };
class Unk_CliCustomStr;
void FUN_14087f0f0(Unk_CliCustomStr* p, const CStringW& key, const CStringW& value);
void FUN_14087f140(Unk_CliCustomStr* p, const CStringW& key);
class Unk_CliTextMgr { public: Unk_CliTextFilter* FUN_140be95b0(); };
Unk_CliCustomStr* FUN_140a87690(Unk_CliTextMgr* p);
Unk_SingletonObj* FUN_140a87680();                              // the text manager
class Unk_CliDungeonDlg { public: void FUN_1412b9320(); };      // the dungeon bookmark dialog
Unk_CliDungeonDlg* FUN_140961550(int nUiId);
class Unk_CliMarket { public: void FUN_140d59990(const CStringW* pStr); CStringW FUN_140d599d0(); };
Unk_CliMarket* FUN_140939a00();                                 // the ugc market
class Unk_CliMeratDlg { public: void FUN_14130c5b0(const CStringW& str); };
Unk_CliMeratDlg* FUN_140bfed50(int nUiId);
CStringW FUN_14028b8e0(const CStringW& strKey);                 // string table text
void FUN_1412751b0(const CStringW& str, int nType);             // chat / system message
class Unk_CliStrMgr { public: void FUN_140259e60(Unk_140165cf0* pElem); };
Unk_CliStrMgr* FUN_14025e7d0();                                 // the CommonString singleton
class Unk_CliStrTbl { public: void FUN_141813970(Unk_140165cf0* pElem); void FUN_1418139b0(Unk_140165cf0* pElem); void FUN_1418139f0(Unk_140165cf0* pElem); };
void FUN_140851c40(Unk_140165cf0* pElem);
Unk_140165cf0* FUN_140345b40(TiXmlDocument* pDoc);              // the document's first child element
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& rOut);
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int& rOut);
int FUN_140873360(Unk_140165cf0* pElem, const char* pszName, float* pOut);
int FUN_140873420(Unk_140165cf0* pElem, const char* pszName, CStringW& rOut);
class Unk_CliPortalMgr {                                        // the UGC portal map's icon list
public:
    void FUN_141b9a300(int nFieldId, MS2Ptr<EventIconInfo> spInfo);
    void FUN_141b9a360(int nFieldId);
};
Unk_CliPortalMgr* FUN_140cb17d0();
CGameRule* FUN_1401c0d90();                                     // TSingleton<CGameRule>::GetInstance
class Unk_CliEvents { public: void FUN_140da5430(int nId, Delegate<void(GameEventVariable*)> handler); void FUN_140da5490(int nId, Delegate<void(GameEventVariable*)> handler); };
Unk_CliEvents* FUN_140933220();                                 // the game event variable manager
UICoupleDanceEventDialog* FUN_140b769d0(int nUiId);
typedef void (UICoupleDanceEventDialog::*Unk_CliCoupleFn)(GameEventVariable*);
class Unk_CliAttendOps {                                        // the attend popups' add / remove entries
public:
    void FUN_14102c8e0(Unk_14102fe10<Unk_140ce3510> spEvent);
    void FUN_14102c9e0(Unk_14102fe10<Unk_140ce3510> spEvent);
    void FUN_140c040c0(Unk_14102fe10<Unk_140ce3510> spEvent);
    void FUN_140c041a0(Unk_14102fe10<Unk_140ce3510> spEvent);
};

// The dialog lookup behind the five COMDATs at 0x140ce8270..0x140ce84f0 (CUIService object by class id, then a cast).
template <> Unk_14102fe10<Unk_140ce3510>::Unk_14102fe10(Unk_140ce3510* p);    // 0x140ce8d10 (defined below)

template <class T> T* FindCliDialog(int id)
{
    if (CUIService::GetInstance()) {
        MS2Ptr<UIObject> p = CUIService::GetInstance()->FUN_141adcea0((eUIClassID)id);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}


// The DT attend popup (uidtattendpopup.h clashes with uidteventdialog.h, so only its type is stood in here).
class UIDTAttendPopup : public UIDialog {};

class Unk_CliStateObj { public: int FUN_140b7f3b0(); };
// The local player (CWorldService::FUN_141bd0cc0), whose slot 78 is the level.
class Unk_CliPlayer {
public:
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
    virtual void Unk_Slot59(int a, int b, int c, int d);
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
    virtual unsigned short vfunc_78();
    int FUN_14166c930();                                        // the state
    Unk_CliStateObj* FUN_14166ccb0();                           // the state's object
};
class Unk_CliWorld {
public:
    int FUN_141bcfbd0();                                        // m_state == 4 && m_2b4 != 0
    Unk_CliPlayer* FUN_141bd0cc0();                             // the local player
};
void* FUN_14041beb0();                                          // the DT context manager
int FUN_1408d7e60(void* p, unsigned short n);                   // the manager has a context for the level
class Unk_CliAutoSvc {
public:
    void FUN_140dd87d0();
};
extern Unk_SingletonObj* DAT_143ac0d40;
// @0x140ce8270 (the DT dialog hands its reward through the by-value context handle)
class Unk_CliDTOps {
public:
    void FUN_140f38430(Unk_DTCtxArg<CommonUserEvent::DTRewardEventContext> pCtx);
};

// ---- GameEventOntimeCli ----------------------------------------------------------------------------------------------

// @0x140ce27f0
GameEvent* FUN_140ce27f0() { return new GameEventOntimeCli; }

// @0x140ce2850
CStringW GameEventOntimeCli::GetTypeName() { return CStringW(L"GameEventOntimeCli"); }

// @0x140ce28a0
void GameEventOntimeCli::OnStart()
{
    unsigned nValue = 0;
    UISystemMailNotifyDialog* pDlg;
    __int64 nHas = DAT_143ab2fc0.Get(400, &nValue);
    if (nHas != 0)
        return;
    pDlg = FindCliDialog<UISystemMailNotifyDialog>(0x4edc);
    if (pDlg != 0) {
        CMsTime now(FUN_140869440());
        CMsTime end(m_38);
        ATL::CTimeSpan span = end - now;
        if (pDlg->FUN_141924630())
            pDlg->vfunc_67();
        pDlg->SetOnTime(true);
        pDlg->FUN_1412a5c70((int)(span.GetTotalSeconds() * 1000));
        pDlg->FUN_141924680();
    }
}

// @0x140ce29a0
void GameEventOntimeCli::vfunc_6()
{
    UISystemMailNotifyDialog* pDlg = FindCliDialog<UISystemMailNotifyDialog>(0x4edc);
    if (pDlg) {
        if (pDlg->FUN_141924630())
            pDlg->vfunc_67();
    }
}

// ---- GameEventGameMenuPopupCli ---------------------------------------------------------------------------------------

// @0x140ce29f0
GameEvent* FUN_140ce29f0() { return new GameEventGameMenuPopupCli; }

// @0x140ce2a50
CStringW GameEventGameMenuPopupCli::GetTypeName() { return CStringW(L"GameEventGameMenuPopupCli"); }

// @0x140ce2aa0
void GameEventGameMenuPopupCli::OnStart()
{
    GameEventGameMenuPopup::OnStart();
    UIGameMenuDialog* pDlg = FUN_140938b90(0x4e28);
    if (pDlg) {
        pDlg->FUN_141938490(m_d0, m_d8);
        if (pDlg->FUN_141924630())
            pDlg->FUN_1419384d0();
    }
}

// @0x140ce2b10
void GameEventGameMenuPopupCli::vfunc_6()
{
    GameEventGameMenuPopup::vfunc_6();
    UIGameMenuDialog* pDlg = FUN_140938b90(0x4e28);
    if (pDlg) {
        {
            CStringW strEmpty(L"");
            pDlg->FUN_141938490(m_d0, strEmpty);
        }
        if (pDlg->FUN_141924630())
            pDlg->FUN_1419384d0();
    }
}

// ---- GameEventEventFieldPopupCli -------------------------------------------------------------------------------------

// @0x140ce2ba0
GameEvent* FUN_140ce2ba0() { return new GameEventEventFieldPopupCli; }

// @0x140ce2c00
CStringW GameEventEventFieldPopupCli::GetTypeName() { return CStringW(L"GameEventEventFieldPopupCli"); }

// @0x140ce2c50
void GameEventEventFieldPopupCli::OnStart()
{
    GameEventEventFieldPopup::OnStart();
    UIEnterEventFieldDialog* pDlg = FindCliDialog<UIEnterEventFieldDialog>(0x4f00);
    if (pDlg) {
        if (pDlg->FUN_141924630())
            pDlg->vfunc_67();
        pDlg->SetFieldId(m_d0);
        pDlg->FUN_141924680();
    }
}

// @0x140ce2cd0
void GameEventEventFieldPopupCli::vfunc_6()
{
    GameEventEventFieldPopup::vfunc_6();
    UIEnterEventFieldDialog* pDlg = FindCliDialog<UIEnterEventFieldDialog>(0x4f00);
    if (pDlg) {
        if (pDlg->FUN_141924630())
            pDlg->vfunc_67();
    }
}

// ---- GameEventDTRewardCli --------------------------------------------------------------------------------------------

// @0x140ce2d30
GameEvent* FUN_140ce2d30() { return new GameEventDTRewardCli; }

// @0x140ce2d90
CStringW GameEventDTRewardCli::GetTypeName() { return CStringW(L"GameEventDTRewardCli"); }

// @0x140ce2de0
void GameEventDTRewardCli::OnStart()
{
    GameEventDTReward::OnStart();
    UIDTEventDialog* pDlg = FindCliDialog<UIDTEventDialog>(0x4f01);
    if (pDlg) {
        if (pDlg->FUN_141924630() != 0) {
            reinterpret_cast<Unk_CliDTOps*>(pDlg)->FUN_140f38430(m_spContext);
        } else {
            if (((Unk_CliWorld*)FUN_1403ed2d0())->FUN_141bcfbd0() != 0)
                pDlg->FUN_141924680();
            else
                FUN_140939a10()->RegisterNotify(L"NotifyGameStart",
                    Delegate<void(NotifyObject*)>(this, &GameEventDTRewardCli::OnNotifyGameStart));
        }
    }
}

// @0x140ce2f30
void GameEventDTRewardCli::vfunc_6()
{
    GameEventDTReward::vfunc_6();
    UIDTEventDialog* pDlg = FindCliDialog<UIDTEventDialog>(0x4f01);
    if (pDlg) {
        pDlg->FUN_140f38630(FUN_1402e1d00());
        if (pDlg->FUN_141924630()) {
            unsigned short nLevel = 0;
            Unk_CliPlayer* pPlayer = ((Unk_CliWorld*)FUN_1403ed2d0())->FUN_141bd0cc0();
            if (pPlayer)
                nLevel = pPlayer->vfunc_78();
            if (FUN_1408d7e60(FUN_14041beb0(), nLevel) == 0)
                pDlg->vfunc_67();
        }
    }
}

// @0x140ce2ff0
void GameEventDTRewardCli::OnNotifyGameStart(NotifyObject*)
{
    UIDTEventDialog* pDlg = FindCliDialog<UIDTEventDialog>(0x4f01);
    if (pDlg)
        pDlg->FUN_141924680();
}

// ---- GameEventSaleAutoFishingCli / GameEventSaleAutoPlayInstrumentCli ------------------------------------------------

// @0x140ce3030
GameEvent* FUN_140ce3030() { return new GameEventSaleAutoFishingCli; }

// @0x140ce3090
CStringW GameEventSaleAutoFishingCli::GetTypeName() { return CStringW(L"GameEventSaleAutoFishingCli"); }

// @0x140cea070
Unk_SingletonObj* FUN_140cea070() { return DAT_143ac0d40; }

// @0x140ce30e0
void GameEventSaleAutoFishingCli::OnStart()
{
    GameEventSaleAutoFishing::OnStart();
    reinterpret_cast<Unk_CliAutoSvc*>(FUN_140cea070())->FUN_140dd87d0();
}

// @0x140ce3110
void GameEventSaleAutoFishingCli::vfunc_6()
{
    GameEventSaleAutoFishing::vfunc_6();
    reinterpret_cast<Unk_CliAutoSvc*>(FUN_140cea070())->FUN_140dd87d0();
}

// @0x140ce3140
GameEvent* FUN_140ce3140() { return new GameEventSaleAutoPlayInstrumentCli; }

// @0x140ce31a0
CStringW GameEventSaleAutoPlayInstrumentCli::GetTypeName() { return CStringW(L"GameEventSaleAutoPlayInstrumentCli"); }

// @0x140ce31f0
void GameEventSaleAutoPlayInstrumentCli::OnStart()
{
    GameEventSaleAutoPlayInstrument::OnStart();
    reinterpret_cast<Unk_CliAutoSvc*>(FUN_140cea070())->FUN_140dd87d0();
}

// @0x140ce3220
void GameEventSaleAutoPlayInstrumentCli::vfunc_6()
{
    GameEventSaleAutoPlayInstrument::vfunc_6();
    reinterpret_cast<Unk_CliAutoSvc*>(FUN_140cea070())->FUN_140dd87d0();
}

// ---- GameEventAttendGiftCli ------------------------------------------------------------------------------------------

// @0x140ce3250
GameEvent* FUN_140ce3250() { return new GameEventAttendGiftCli; }

// @0x140ce32b0
CStringW GameEventAttendGiftCli::GetTypeName() { return CStringW(L"GameEventAttendGiftCli"); }

// @0x140ce3300
void GameEventAttendGiftCli::OnStart()
{
    GameEventAttendGift::OnStart();
    Unk_CliAttendOps* pDlg = (Unk_CliAttendOps*)FUN_140c053e0(0x4eb8);
    if (pDlg)
        pDlg->FUN_14102c8e0(Unk_14102fe10<Unk_140ce3510>((Unk_140ce3510*)this));
    if ((unsigned)m_i120 > 0) {
        UIDTAttendPopup* pPopup = FindCliDialog<UIDTAttendPopup>(0x4eba);
        if (pPopup)
            ((Unk_CliAttendOps*)pPopup)->FUN_140c040c0(Unk_14102fe10<Unk_140ce3510>((Unk_140ce3510*)this));
    }
}

// @0x140ce33c0
void GameEventAttendGiftCli::vfunc_6()
{
    GameEventAttendGift::vfunc_6();
    Unk_CliAttendOps* pDlg = (Unk_CliAttendOps*)FUN_140c053e0(0x4eb8);
    if (pDlg)
        pDlg->FUN_14102c9e0(Unk_14102fe10<Unk_140ce3510>((Unk_140ce3510*)this));
    if ((unsigned)m_i120 > 0) {
        UIDTAttendPopup* pPopup = FindCliDialog<UIDTAttendPopup>(0x4eba);
        if (pPopup)
            ((Unk_CliAttendOps*)pPopup)->FUN_140c041a0(Unk_14102fe10<Unk_140ce3510>((Unk_140ce3510*)this));
    }
}

// @0x140ce3480
void GameEventAttendGiftCli::vfunc_10()
{
    m_strName = ((Unk_CliTextMgr*)FUN_140a87680())->FUN_140be95b0()->FUN_14087ede0(m_strName);
}

// @0x140ce3510
bool GameEventAttendGiftCli::FUN_140ce3510()
{
    if (m_b124)
        return false;
    switch (m_i114) {
    case 1: {
        bool bDefault = false;
        return DAT_143ab2fc0.FUN_140482280(m_i118, bDefault);
    }
    case 3:
        return DAT_143ab2fc0.FUN_14041f940(m_i118) == 0;
    default:
        return true;
    }
}

// @0x140ce35c0
bool GameEventAttendGiftCli::FUN_140ce35c0()
{
    CMsTime now(FUN_140869440());
    __int64 nDefault = 0;
    __int64 nEnd = DAT_143ab2fc0.FUN_140be8f80(0x65, FUN_1402e1d00(), nDefault);
    if (nEnd == 0)
        return false;
    CMsTime end(nEnd);
    FUN_14086a6c0(now);
    FUN_14086a6c0(end);
    return now <= end;
}

// @0x140ce3660
unsigned GameEventAttendGiftCli::FUN_140ce3660() { return (unsigned)m_gifts.GetCount(); }

// @0x140ce3690
unsigned GameEventAttendGiftCli::FUN_140ce3690()
{
    int nDefault = 0;
    return DAT_143ab2fc0.FUN_1409617d0(0x66, FUN_1402e1d00(), nDefault);
}

// @0x140ce36d0
int GameEventAttendGiftCli::FUN_140ce36d0()
{
    int nDefault = 0;
    return DAT_143ab2fc0.FUN_1409617d0(0x69, FUN_1402e1d00(), nDefault);
}

// @0x140ce3710
MS2Ptr<ItemGift> GameEventAttendGiftCli::FUN_140ce3710(unsigned nDay)
{
    if (nDay >= FUN_140ce3660())
        return MS2Ptr<ItemGift>(0);
    return m_gifts.GetAt(nDay);
}

// @0x140ce37a0
CStringW GameEventAttendGiftCli::FUN_140ce37a0()
{
    int nCount;
    if (!m_b125 && (nCount = FUN_140ce36d0(), 0 < nCount))
        return FUN_140275590(L"{0}({1})", m_strName, nCount);
    return m_strName;
}

// @0x140ce3850
CStringA GameEventAttendGiftCli::GetDesc() { return m_strDesc; }

// @0x140ce38a0
int GameEventAttendGiftCli::FUN_140ce38a0() { return m_i100; }

// @0x140ce38c0
unsigned GameEventAttendGiftCli::FUN_140ce38c0() { return m_i104; }

// @0x140ce38e0
__int64 GameEventAttendGiftCli::FUN_140ce38e0() { return m_i108; }

// @0x140ce3900
int GameEventAttendGiftCli::FUN_140ce3900() { return m_i110; }

// @0x140ce3920
unsigned GameEventAttendGiftCli::FUN_140ce3920()
{
    int nDefault = 0;
    return DAT_143ab2fc0.FUN_140c6d8d0(0x67, FUN_1402e1d00(), nDefault);
}

// @0x140ce3960
int GameEventAttendGiftCli::FUN_140ce3960() { return m_i114; }

// @0x140ce3980
int GameEventAttendGiftCli::FUN_140ce3980() { return m_i118; }

// @0x140ce39a0
int GameEventAttendGiftCli::FUN_140ce39a0()
{
    int nDefault = 0;
    int nTotal = DAT_143ab2fc0.FUN_140c6d8d0(0x6a, FUN_1402e1d00(), nDefault);
    nTotal += FUN_14086d260()->FUN_141473560();
    return nTotal;
}

// @0x140ce3a00
int GameEventAttendGiftCli::FUN_140ce3a00() { return m_i120; }

// @0x140ce3a20
int GameEventAttendGiftCli::FUN_140ce3a20()
{
    unsigned nUsed = FUN_140ce39a0();
    unsigned nMax = FUN_140ce3a00();
    unsigned nLeft;
    if (nUsed < nMax)
        nLeft = nMax - nUsed;
    else
        nLeft = 0;
    return nLeft;
}

// @0x140ce3a80
bool GameEventAttendGiftCli::FUN_140ce3a80() { return m_b125; }

// @0x140ce3aa0
CMsTime GameEventAttendGiftCli::FUN_140ce3aa0() { return m_28; }

// @0x140ce3ae0
CMsTime GameEventAttendGiftCli::FUN_140ce3ae0()
{
    if (m_i114 == 2) {
        __int64 nTime = FUN_140d9f580(FUN_140931510(), FUN_1402e1d00());
        if (nTime != 0)
            return CMsTime(nTime);
    }
    return m_38;
}

// ---- GameEventCashAttendCli ------------------------------------------------------------------------------------------

// @0x140ce3b70
GameEvent* FUN_140ce3b70() { return new GameEventCashAttendCli; }

// @0x140ce3bd0
CStringW GameEventCashAttendCli::GetTypeName() { return CStringW(L"GameEventCashAttendCli"); }

// @0x140ce3c20
void GameEventCashAttendCli::OnStart()
{
    GameEventCashAttend::OnStart();
    UICashAttendDialog* pDlg = FindCliDialog<UICashAttendDialog>(0x4eb9);
    if (pDlg)
        pDlg->FUN_140bc3db0(MS2Ptr<GameEventCashAttendCli>(this));
}

// @0x140ce3c90
void GameEventCashAttendCli::vfunc_6()
{
    GameEventCashAttend::vfunc_6();
    UICashAttendDialog* pDlg = FindCliDialog<UICashAttendDialog>(0x4eb9);
    if (pDlg)
        pDlg->FUN_140bc3eb0(MS2Ptr<GameEventCashAttendCli>(this));
}

// @0x140ce3d00
void GameEventCashAttendCli::vfunc_10()
{
    m_strDesc = ((Unk_CliTextMgr*)FUN_140a87680())->FUN_140be95b0()->FUN_14087ede0(m_strDesc);
}

// @0x140ce3d90
bool GameEventCashAttendCli::FUN_140ce3d90() { return true; }

// @0x140ce3da0
bool GameEventCashAttendCli::FUN_140ce3da0()
{
    CMsTime now(FUN_140869440());
    __int64 nDefault = 0;
    __int64 nEnd = DAT_143ab2fc0.FUN_140be8f80(0x65, FUN_1402e1d00(), nDefault);
    if (nEnd == 0)
        return false;
    CMsTime end(nEnd);
    FUN_14086a6c0(now);
    FUN_14086a6c0(end);
    return now <= end;
}

// MS2-FUNCTIONAL: the then-branch is two bytes longer than the exe's (one extra jump)
// @0x140ce3e40
unsigned GameEventCashAttendCli::FUN_140ce3e40()
{
    if (m_entry == 0)
        return 0;
    else
        return reinterpret_cast<AttendGiftData*>(m_entry.operator->())->GetGroupCount();
}

// @0x140ce3e90
unsigned GameEventCashAttendCli::FUN_140ce3e90()
{
    int nDefault = 0;
    return DAT_143ab2fc0.FUN_1409617d0(0x66, FUN_1402e1d00(), nDefault);
}

// @0x140ce3ed0
int GameEventCashAttendCli::FUN_140ce3ed0()
{
    int nDefault = 0;
    return DAT_143ab2fc0.FUN_1409617d0(0x69, FUN_1402e1d00(), nDefault);
}

// @0x140ce3f10
CStringW GameEventCashAttendCli::FUN_140ce3f10()
{
    return FUN_1401a9d70()->FUN_141811980(1, m_i4);
}

// @0x140ce3f70
CStringW GameEventCashAttendCli::GetDesc() { return m_strDesc; }

// @0x140ce3fc0
AttendGiftDataGroupPtr GameEventCashAttendCli::FUN_140ce3fc0(unsigned nDay)
{
    if (nDay >= FUN_140ce3e40())
        return AttendGiftDataGroupPtr(0);
    return reinterpret_cast<AttendGiftData*>(m_entry.operator->())->GetGroup(nDay);
}

// @0x140ce4050
CMsTime GameEventCashAttendCli::FUN_140ce4050() { return m_28; }

// @0x140ce4090
CMsTime GameEventCashAttendCli::FUN_140ce4090() { return m_38; }

// ---- GameEventTrafficOptimizerCli ------------------------------------------------------------------------------------

// @0x140ce40d0
GameEvent* FUN_140ce40d0() { return new GameEventTrafficOptimizerCli; }

// @0x140ce4130
CStringW GameEventTrafficOptimizerCli::GetTypeName() { return CStringW(L"GameEventTrafficOptimizerCli"); }

// @0x140ce41d0
void GameEventTrafficOptimizerCli::OnStart()
{
    GameEventTrafficOptimizer::OnStart();
    for (size_t i = 0; i < 7; i++)
        TSingleton<CTrafficOptimizer>::GetInstance()->FUN_14087d5b0((unsigned)i, m_values[i]);
}

// @0x140ce4250
void GameEventTrafficOptimizerCli::vfunc_6()
{
    GameEventTrafficOptimizer::vfunc_6();
    for (size_t i = 0; i < 7; i++)
        TSingleton<CTrafficOptimizer>::GetInstance()->FUN_14087d5b0((unsigned)i, 0);
}

// @0x140ce42b0
void GameEventTrafficOptimizerCli::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    for (size_t i = 0; i < 7; i++)
        m_values.Add(MS2_GE_READ_INT(in));
}

// ---- GameEventItemBuffCli --------------------------------------------------------------------------------------------

// @0x140ce4330
GameEvent* FUN_140ce4330() { return new GameEventItemBuffCli; }

// @0x140ce4390
CStringW GameEventItemBuffCli::GetTypeName() { return CStringW(L"GameEventItemBuffCli"); }

// @0x140ce4420
void GameEventItemBuffCli::OnStart()
{
    FUN_140939a10()->RegisterNotify(L"NotifyGameStart",
        Delegate<void(NotifyObject*)>(this, &GameEventItemBuffCli::FUN_140ce4580));
}

// @0x140ce44d0
void GameEventItemBuffCli::vfunc_6()
{
    FUN_140939a10()->UnregisterNotify(L"NotifyGameStart",
        Delegate<void(NotifyObject*)>(this, &GameEventItemBuffCli::FUN_140ce4580));
}

// @0x140ce4580
void GameEventItemBuffCli::FUN_140ce4580(NotifyObject*)
{
    if (m_d0 == 0x140) {
        bool bDefault = false;
        if (DAT_143ab2fc0.FUN_140482280(m_d0, bDefault))
            FUN_1412751b0(FUN_14028b8e0(L"s_event_return_user_item_buff"), 0x14);
    }
}

// ---- GameEventDungeonExtraRewardCli ----------------------------------------------------------------------------------

// @0x140ce4640
GameEvent* FUN_140ce4640() { return new GameEventDungeonExtraRewardCli; }

// @0x140ce46a0
CStringW GameEventDungeonExtraRewardCli::GetTypeName() { return CStringW(L"GameEventDungeonExtraRewardCli"); }

// @0x140ce46f0
void GameEventDungeonExtraRewardCli::OnStart()
{
    GameEventDungeonExtraReward::OnStart();
    Unk_CliDungeonDlg* pDlg = FUN_140961550(0x4ebd);
    if (pDlg)
        pDlg->FUN_1412b9320();
}

// @0x140ce4730
void GameEventDungeonExtraRewardCli::vfunc_6()
{
    GameEventDungeonExtraReward::vfunc_6();
    Unk_CliDungeonDlg* pDlg = FUN_140961550(0x4ebd);
    if (pDlg)
        pDlg->FUN_1412b9320();
}

// ---- GameEventMeratMarketNoticeCli -----------------------------------------------------------------------------------

// @0x140ce4770
GameEvent* FUN_140ce4770() { return new GameEventMeratMarketNoticeCli; }

// @0x140ce47d0
CStringW GameEventMeratMarketNoticeCli::GetTypeName() { return CStringW(L"GameEventMeratMarketNoticeCli"); }

// MS2-FUNCTIONAL: 3 bytes longer (the member reference argument is reloaded through rcx)
// @0x140ce4820
void GameEventMeratMarketNoticeCli::OnStart()
{
    GameEventMeratMarketNotice::OnStart();
    Unk_CliMeratDlg* pDlg = FUN_140bfed50(0x4ec1);
    if (pDlg) {
        const CStringW* pStr = &m_d0;
        FUN_140939a00()->FUN_140d59990(pStr);
        pDlg->FUN_14130c5b0(FUN_140939a00()->FUN_140d599d0());
    }
}

// @0x140ce48c0
void GameEventMeratMarketNoticeCli::vfunc_6()
{
    GameEventMeratMarketNotice::vfunc_6();
    Unk_CliMeratDlg* pDlg = FUN_140bfed50(0x4ec1);
    if (pDlg) {
        {
            CStringW strEmpty(L"");
            FUN_140939a00()->FUN_140d59990(&strEmpty);
        }
        pDlg->FUN_14130c5b0(FUN_140939a00()->FUN_140d599d0());
    }
}

// ---- GameEventUpdateStringCli ----------------------------------------------------------------------------------------

// @0x140ce4970
GameEvent* FUN_140ce4970() { return new GameEventUpdateStringCli; }

// @0x140ce49d0
CStringW GameEventUpdateStringCli::GetTypeName() { return CStringW(L"GameEventUpdateStringCli"); }

// @0x140ce4a20
void GameEventUpdateStringCli::OnStart()
{
    GameEventUpdateString::OnStart();
    CStringW strXml(m_d0);
    strXml.Trim();
    if (!strXml.IsEmpty()) {
        TiXmlDocument doc;
        if (GetFileSystem()->FUN_140397ab0(&doc, strXml) == 0) {
            MS2_ASSERT_AT(0x271, FALSE);
            return;
        }
        Unk_140165cf0* pRoot = FUN_140345b40(&doc);
        if (pRoot == 0) {
            MS2_ASSERT_AT(0x278, FALSE);
            return;
        }
        Unk_140165cf0* pStringCommon = pRoot->FUN_140165cf0("stringCommon");
        if (pStringCommon != 0)
            FUN_140ce4c60(pStringCommon);
        Unk_140165cf0* pItemDesc = pRoot->FUN_140165cf0("itemDescription");
        if (pItemDesc != 0)
            FUN_140ce4c90(pItemDesc);
        Unk_140165cf0* pAddDesc = pRoot->FUN_140165cf0("additionalDescription");
        if (pAddDesc != 0)
            FUN_140ce4cc0(pAddDesc);
        Unk_140165cf0* pSkillDesc = pRoot->FUN_140165cf0("skillDescription");
        if (pSkillDesc != 0)
            FUN_140ce4cf0(pSkillDesc);
        Unk_140165cf0* pMailContent = pRoot->FUN_140165cf0("systemMailContent");
        if (pMailContent != 0)
            FUN_140ce4d20(pMailContent);
    }
}

// @0x140ce4c50
void GameEventUpdateStringCli::vfunc_6() {}

// @0x140ce4c60
void GameEventUpdateStringCli::FUN_140ce4c60(Unk_140165cf0* pElem) { FUN_14025e7d0()->FUN_140259e60(pElem); }

// @0x140ce4c90
void GameEventUpdateStringCli::FUN_140ce4c90(Unk_140165cf0* pElem) { ((Unk_CliStrTbl*)FUN_1401a9d70())->FUN_141813970(pElem); }

// @0x140ce4cc0
void GameEventUpdateStringCli::FUN_140ce4cc0(Unk_140165cf0* pElem) { ((Unk_CliStrTbl*)FUN_1401a9d70())->FUN_1418139b0(pElem); }

// @0x140ce4cf0
void GameEventUpdateStringCli::FUN_140ce4cf0(Unk_140165cf0* pElem) { ((Unk_CliStrTbl*)FUN_1401a9d70())->FUN_1418139f0(pElem); }

// @0x140ce4d20
void GameEventUpdateStringCli::FUN_140ce4d20(Unk_140165cf0* pElem) { FUN_140851c40(pElem); }

// ---- GameEventWorldmapIconCli ----------------------------------------------------------------------------------------

// @0x140ce4d50
GameEvent* FUN_140ce4d50() { return new GameEventWorldmapIconCli; }

// @0x140ce4db0
CStringW GameEventWorldmapIconCli::GetTypeName() { return CStringW(L"GameEventWorldmapIconCli"); }

// MS2-FUNCTIONAL: the exe lays the icon pointer temps out in other stack slots (frame and unwind map differ)
// @0x140ce4e00
void GameEventWorldmapIconCli::OnStart()
{
    TiXmlDocument doc;
    const CStringW* pXml = &m_d0;
    if (GetFileSystem()->FUN_140397ab0(&doc, *pXml) == 0) {
        MS2_ASSERT_AT(0x2c1, FALSE);
    } else {
        Unk_140165cf0* pRoot = FUN_140345b40(&doc);
        if (pRoot == 0) {
            MS2_ASSERT_AT(0x2c8, FALSE);
        } else {
            for (Unk_140165cf0* pIcon = pRoot->FUN_140165cf0("v"); pIcon != 0; pIcon = pIcon->FUN_140168650("v")) {
                MS2Ptr<EventIconInfo> spInfo(new EventIconInfo);
                if (spInfo->Load(pIcon) == 0) {
                } else {
                    FUN_140cb17d0()->FUN_141b9a300(spInfo->m_nFieldId, spInfo);
                }
            }
        }
    }
}

// MS2-FUNCTIONAL: the exe lays the icon pointer temps out in other stack slots (frame and unwind map differ)
// @0x140ce5010
void GameEventWorldmapIconCli::vfunc_6()
{
    TiXmlDocument doc;
    const CStringW* pXml = &m_d0;
    if (GetFileSystem()->FUN_140397ab0(&doc, *pXml) == 0) {
        MS2_ASSERT_AT(0x2db, FALSE);
    } else {
        Unk_140165cf0* pRoot = FUN_140345b40(&doc);
        if (pRoot == 0) {
            MS2_ASSERT_AT(0x2e2, FALSE);
        } else {
            for (Unk_140165cf0* pIcon = pRoot->FUN_140165cf0("v"); pIcon != 0; pIcon = pIcon->FUN_140168650("v")) {
                MS2Ptr<EventIconInfo> spInfo(new EventIconInfo);
                if (spInfo->Load(pIcon) == 0) {
                } else {
                    FUN_140cb17d0()->FUN_141b9a360(spInfo->m_nFieldId);
                }
            }
        }
    }
}

// ---- GameEventStringBoardCli -----------------------------------------------------------------------------------------

// @0x140ce51e0
GameEvent* FUN_140ce51e0() { return new GameEventStringBoardCli; }

// @0x140ce5240
CStringW GameEventStringBoardCli::GetTypeName() { return CStringW(L"GameEventStringBoardCli"); }

// @0x140ce5290
void GameEventStringBoardCli::OnStart()
{
    CStringW strText;
    if (m_nId != 0)
        strText = FUN_1401a9d70()->FUN_141811980(0x40, m_nId);
    else
        strText = m_80;
    if (!strText.IsEmpty())
        FUN_1401c0d90()->FUN_14047d820(FUN_1402e1d00(), strText);
}

// @0x140ce5380
void GameEventStringBoardCli::vfunc_6() { FUN_1401c0d90()->FUN_14047d900(FUN_1402e1d00()); }

// ---- GameEventSnowmanCli ---------------------------------------------------------------------------------------------

// @0x140ce53c0
GameEvent* FUN_140ce53c0() { return new GameEventSnowmanCli; }

// @0x140ce5420
CStringW GameEventSnowmanCli::GetTypeName() { return CStringW(L"GameEventSnowmanCli"); }

// @0x140ce5470
void GameEventSnowmanCli::OnStart()
{
    GameEventSnowman::OnStart();
    UISnowmanEventDialog* pDlg = FindCliDialog<UISnowmanEventDialog>(0x4f5d);
    if (pDlg) {
        pDlg->FUN_140e96a90(m_e0);
        if (pDlg->FUN_141924630() == 0) {
            if (((Unk_CliWorld*)FUN_1403ed2d0())->FUN_141bcfbd0() != 0)
                pDlg->FUN_141924680();
            else
                FUN_140939a10()->RegisterNotify(L"NotifyGameStart",
                    Delegate<void(NotifyObject*)>(this, &GameEventSnowmanCli::FUN_140ce56a0));
        }
    }
}

// @0x140ce55a0
void GameEventSnowmanCli::vfunc_6()
{
    GameEventSnowman::vfunc_6();
    UISnowmanEventDialog* pDlg = FindCliDialog<UISnowmanEventDialog>(0x4f5d);
    if (pDlg) {
        if (pDlg->FUN_141924630())
            pDlg->vfunc_67();
    }
    FUN_140939a10()->UnregisterNotify(L"NotifyGameStart",
        Delegate<void(NotifyObject*)>(this, &GameEventSnowmanCli::FUN_140ce56a0));
}

// @0x140ce56a0
void GameEventSnowmanCli::FUN_140ce56a0(NotifyObject*)
{
    UISnowmanEventDialog* pDlg = FindCliDialog<UISnowmanEventDialog>(0x4f5d);
    if (pDlg)
        pDlg->FUN_141924680();
}

// ---- GameEventRpsCli -------------------------------------------------------------------------------------------------

// @0x140ce56e0
GameEvent* FUN_140ce56e0() { return new GameEventRpsCli; }

// @0x140ce5740
CStringW GameEventRpsCli::GetTypeName() { return CStringW(L"GameEventRpsCli"); }

// MS2-FUNCTIONAL: the exe lays the RpsGameData handle, document and xml pointer out in other stack slots (frame and unwind map differ)
// @0x140ce5790
void GameEventRpsCli::OnStart()
{
    MS2Ptr<RpsGameData> spData(new RpsGameData());
    TiXmlDocument doc;
    CStringW* pXml = &m_d0->m_strTitle;
    if (GetFileSystem()->FUN_140397ab0(&doc, *pXml) == 0) {
        MS2_ASSERT_AT(0x33e, 0);
    } else {
        Unk_140165cf0* pRoot = FUN_140345b40(&doc);
        if (pRoot == 0) {
            MS2_ASSERT_AT(0x345, 0);
        } else {
            if (!spData->Load(pRoot)) {
                MS2_ASSERT_AT(0x34b, 0);
            } else {
                m_d0->m_spGameData = spData;
                GameEventRps::OnStart();
            }
        }
    }
}

// @0x140ce5990
void GameEventRpsCli::vfunc_6()
{
    GameEventRps::vfunc_6();
    UIRpsEventDialog* pDlg = FindCliDialog<UIRpsEventDialog>(0x4f5f);
    if (pDlg && pDlg->FUN_141924630() != 0)
        pDlg->vfunc_67();
    Unk_CliPlayer* pPlayer = ((Unk_CliWorld*)FUN_1403ed2d0())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    switch (pPlayer->FUN_14166c930()) {
    case 0x3c:
        pPlayer->Unk_Slot59(1, 0, 0, 0);
        break;
    case 0x3b: {
        Unk_CliStateObj* pObj = pPlayer->FUN_14166ccb0();
        if (pObj && pObj->FUN_140b7f3b0() == 1)
            pPlayer->Unk_Slot59(1, 0, 0, 0);
        break;
    }
    }
}

// ---- GameEventCoupleDanceCli -----------------------------------------------------------------------------------------

// @0x140ce5aa0
GameEvent* FUN_140ce5aa0() { return new GameEventCoupleDanceCli; }

// @0x140ce5b00
CStringW GameEventCoupleDanceCli::GetTypeName() { return CStringW(L"GameEventCoupleDanceCli"); }

// MS2-FUNCTIONAL: the dialog's member pointer is 16 bytes in the exe (the real dialog has a second base the header lacks)
// @0x140ce5b50
void GameEventCoupleDanceCli::OnStart()
{
    GameEventCoupleDance::OnStart();
    UICoupleDanceEventDialog* pDlg = FUN_140b769d0(0x4f71);
    if (pDlg != 0) {
        Unk_CliCoupleFn pfn = reinterpret_cast<Unk_CliCoupleFn>(&UICoupleDanceEventDialog::FUN_140bfe1a0);
        FUN_140933220()->FUN_140da5430(0x834, Delegate<void(GameEventVariable*)>(pDlg, pfn));
        FUN_140933220()->FUN_140da5430(0x835, Delegate<void(GameEventVariable*)>(pDlg, pfn));
    }
}

// MS2-FUNCTIONAL: the dialog's member pointer is 16 bytes in the exe (the real dialog has a second base the header lacks)
// @0x140ce5ca0
void GameEventCoupleDanceCli::vfunc_6()
{
    GameEventCoupleDance::vfunc_6();
    UICoupleDanceEventDialog* pDlg = FUN_140b769d0(0x4f71);
    if (pDlg != 0) {
        Unk_CliCoupleFn pfn = reinterpret_cast<Unk_CliCoupleFn>(&UICoupleDanceEventDialog::FUN_140bfe1a0);
        FUN_140933220()->FUN_140da5490(0x834, Delegate<void(GameEventVariable*)>(pDlg, pfn));
        FUN_140933220()->FUN_140da5490(0x835, Delegate<void(GameEventVariable*)>(pDlg, pfn));
        if (pDlg->FUN_141924630() != 0)
            pDlg->vfunc_67();
    }
    Unk_CliPlayer* pPlayer = ((Unk_CliWorld*)FUN_1403ed2d0())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    int nState = pPlayer->FUN_14166c930();
    switch (nState) {
    case 0x3b: {
        Unk_CliStateObj* pObj = pPlayer->FUN_14166ccb0();
        if (pObj && pObj->FUN_140b7f3b0() == 2)
            pPlayer->Unk_Slot59(1, 0, 0, 0);
        break;
    }
    case 0x45:
        pPlayer->Unk_Slot59(1, 0, 0, 0);
        break;
    }
}

// ---- GameEventCustomTriggerStringCli ---------------------------------------------------------------------------------

// @0x140ce5ed0
GameEvent* FUN_140ce5ed0() { return new GameEventCustomTriggerStringCli; }

// @0x140ce5f30
CStringW GameEventCustomTriggerStringCli::GetTypeName() { return CStringW(L"GameEventCustomTriggerStringCli"); }

// MS2-FUNCTIONAL: the exe passes the map entry through a reloaded pointer (argument shuffle differs by 6 bytes)
// @0x140ce5f80
void GameEventCustomTriggerStringCli::OnStart()
{
    GameEventCustomTriggerString::OnStart();
    for (POSITION pos = m_d0.GetHeadPosition(); pos != 0; m_d0.GetNext(pos)) {
        const CStringW& strKey = m_d0.GetKeyAt(pos);
        CStringW strText = ((Unk_CliTextMgr*)FUN_140a87680())->FUN_140be95b0()->FUN_14087ede0(strKey);
        CStringW& strValue = m_d0.GetValueAt(pos);
        FUN_14087f0f0(FUN_140a87690((Unk_CliTextMgr*)FUN_140a87680()), strValue, strText);
    }
}

// MS2-FUNCTIONAL: the exe passes the map entry through a reloaded pointer (argument shuffle differs by 3 bytes)
// @0x140ce6080
void GameEventCustomTriggerStringCli::vfunc_6()
{
    GameEventCustomTriggerString::vfunc_6();
    for (POSITION pos = m_d0.GetHeadPosition(); pos != 0; m_d0.GetNext(pos)) {
        CStringW& strValue = m_d0.GetValueAt(pos);
        FUN_14087f140(FUN_140a87690((Unk_CliTextMgr*)FUN_140a87680()), strValue);
    }
}

// ---- GameEventBurningLevelupCli --------------------------------------------------------------------------------------

class Unk_MyPCBurningEvent : public CPtred {};
class Unk_CliMcPackets
{
public:
    void FUN_140da5180(int nOp, Delegate<void(CInPacket&)> handler);
    void FUN_140da51e0(int nOp, Delegate<void(CInPacket&)> handler);
};
Unk_CliMcPackets* FUN_140bccd50();
class Unk_CliUiMgr { public: void FUN_141adc5d0(int nId); };
void* FUN_1403ed2b0();
void FUN_140710590(COutPacket&);

class Unk_CliPktBody
{
public:
    virtual void vfunc_0() = 0;
    virtual unsigned char GetType() = 0;
    virtual void vfunc_2() = 0;
    virtual int GetId() = 0;
};
struct Unk_CliPktHead { void* m_pad; };
struct Unk_CliPkt : Unk_CliPktHead, Unk_CliPktBody {};

// @0x140ce6120
GameEvent* FUN_140ce6120() { return new GameEventBurningLevelupCli; }

// @0x140ce6180
CStringW GameEventBurningLevelupCli::GetTypeName() { return CStringW(L"GameEventBurningLevelupCli"); }

MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
CStringW FUN_14028b8e0(const CStringW& str);

class NotifyChangeMyLevel : public NotifyObject
{
public:
    virtual ~NotifyChangeMyLevel() = default;
    virtual CStringW GetTypeName();
    unsigned short m_nLevel;
    unsigned short m_nOldLevel;
};

// MS2-FUNCTIONAL: the exe also fills the box with the reward item bag (CMsgBoxDataItem/CItem built from the jumping item or the reward list); only the text is shown here
static void Unk_ShowBurningPopup(const CStringW& strKey)
{
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x2a, FUN_14028b8e0(strKey), 0, CStringW(L""));
    if (spBox == 0)
        return;
    spBox->FUN_141a01800(3);
    FUN_140d73c60(spBox);
}

typedef void (GameEventBurningLevelupCli::*Unk_CliBurnPktFn)(CInPacket&);

// @0x140ce61d0
void GameEventBurningLevelupCli::OnStart()
{
    GameEventBurningLevelup::OnStart();
    UIBurningEventWidgetDialog* pDlg = FindCliDialog<UIBurningEventWidgetDialog>(0x4f6a);
    if (pDlg)
        pDlg->FUN_140c5ab30(MS2Ptr<Unk_MyPCBurningEvent>(reinterpret_cast<Unk_MyPCBurningEvent*>(this)));
    FUN_140bccd50()->FUN_140da5180(0xf7,
        Delegate<void(CInPacket&)>(this, reinterpret_cast<Unk_CliBurnPktFn>(&GameEventBurningLevelupCli::FUN_140ce7250)));
    FUN_140939a10()->RegisterNotify(L"NotifyChangeMyLevel",
        Delegate<void(NotifyObject*)>(this, &GameEventBurningLevelupCli::vfunc_10));
}

// @0x140ce6360
void GameEventBurningLevelupCli::vfunc_6()
{
    GameEventBurningLevelup::vfunc_6();
    UIBurningEventWidgetDialog* pDlg = FindCliDialog<UIBurningEventWidgetDialog>(0x4f6a);
    if (pDlg)
        pDlg->FUN_140c5ab30(MS2Ptr<Unk_MyPCBurningEvent>(0));
    FUN_140bccd50()->FUN_140da51e0(0xf7,
        Delegate<void(CInPacket&)>(this, reinterpret_cast<Unk_CliBurnPktFn>(&GameEventBurningLevelupCli::FUN_140ce7250)));
    FUN_140939a10()->UnregisterNotify(L"NotifyChangeMyLevel",
        Delegate<void(NotifyObject*)>(this, &GameEventBurningLevelupCli::vfunc_10));
}

// MS2-FUNCTIONAL: the exe keeps the result in one 64-bit local across the branches (byte/qword mix)
// @0x140ce64e0
bool GameEventBurningLevelupCli::FUN_140ce64e0(short nLevel)
{
    if (m_d0 == 0)
        return false;
    __int64 b0 = 0;
    unsigned __int64 r = DAT_143ab2fc0.FUN_140c5af20(2000, m_d0->m_eventId, &b0);
    if (r != DAT_143ab2828)
        return false;
    __int64 q = 0;
    __int64 s = DAT_143ab2fc0.FUN_140be8f80(0x7d1, m_d0->m_eventId, q);
    if (s == 0)
        return nLevel == (short)m_d0->m_equipNametagSymbolId;
    return false;
}

// ---- GameEventLongTermAttendGiftCli ----------------------------------------------------------------------------------

// @0x140ce7870
GameEvent* FUN_140ce7870() { return new GameEventLongTermAttendGiftCli; }

// @0x140ce78d0
CStringW GameEventLongTermAttendGiftCli::GetTypeName() { return CStringW(L"GameEventLongTermAttendGiftCli"); }

// @0x140ce7920
void GameEventLongTermAttendGiftCli::OnStart()
{
    GameEventLongTermAttendGift::OnStart();
    COutPacket packet(0x97, 0);
    packet.vfunc_o10_1(0x1b);
    FUN_140710590(packet);
}

// @0x140ce7980
void GameEventLongTermAttendGiftCli::vfunc_6()
{
    GameEventLongTermAttendGift::vfunc_6();
    ((Unk_CliUiMgr*)FUN_1403ed2b0())->FUN_141adc5d0(0x4f98);
}

// MS2-FUNCTIONAL: see Unk_ShowBurningPopup (reward item bag not built)
// @0x140ce65f0
void GameEventBurningLevelupCli::vfunc_10(NotifyObject* pNotify)
{
    NotifyChangeMyLevel* pChg = dynamic_cast<NotifyChangeMyLevel*>(pNotify);
    if (pChg == 0 || m_d0 == 0 || !(pChg->m_nOldLevel < pChg->m_nLevel) || m_d0->m_8c == 0 || m_d0->m_spJumpingItem == 0)
        return;
    __int64 b0 = 0;
    unsigned __int64 r = DAT_143ab2fc0.FUN_140c5af20(2000, m_d0->m_eventId, &b0);
    if (r != DAT_143ab2828)
        return;
    if (pChg->m_nLevel < m_d0->m_8c) {
        __int64 q = 0;
        if (DAT_143ab2fc0.FUN_140be8f80(0x7d3, m_d0->m_eventId, q) != 0)
            Unk_ShowBurningPopup(m_d0->m_jumpingItemNotifyStringKey);
    } else if (pChg->m_nOldLevel < m_d0->m_8c && m_d0->m_8c <= pChg->m_nLevel) {
        Unk_ShowBurningPopup(m_d0->m_jumpingCompleteStringKey);
    }
}

// MS2-FUNCTIONAL: see Unk_ShowBurningPopup (reward item bag not built)
// @0x140ce7250
void GameEventBurningLevelupCli::FUN_140ce7250(Unk_CliPkt& pkt)
{
    if (m_d0 == 0)
        return;
    unsigned char nType = pkt.GetType();
    if (nType == 0x0f) {
        UIBurningEventWidgetDialog* pDlg = FindCliDialog<UIBurningEventWidgetDialog>(0x4f6a);
        if (pDlg)
            pDlg->FUN_140c5a100(&pkt);
    } else if (nType == 0x11) {
        if ((int)m_d0->m_eventId == pkt.GetId() && !m_d0->m_jumpingItemNotifyStringKey.IsEmpty())
            Unk_ShowBurningPopup(m_d0->m_jumpingItemNotifyStringKey);
    }
}

// ---- constructors ----------------------------------------------------------------------------------------------------

// @0x140ce8dd0
EventIconInfo::EventIconInfo() : m_nFieldId(0), m_nOffsetX(0), m_nOffsetY(0), m_fScale(1.0f) {}

// @0x140ce4180
GameEventTrafficOptimizerCli::GameEventTrafficOptimizerCli() {}

// @0x140ce43e0
GameEventItemBuffCli::GameEventItemBuffCli() {}

// @0x140ce8e60
GameEventAttendGiftCli::GameEventAttendGiftCli() {}

// @0x140ce8e90
GameEventBurningLevelupCli::GameEventBurningLevelupCli() {}

// @0x140ce8ec0
GameEventCashAttendCli::GameEventCashAttendCli() {}

// @0x140ce8ef0
GameEventCoupleDanceCli::GameEventCoupleDanceCli() {}

// @0x140ce8f20
GameEventCustomTriggerStringCli::GameEventCustomTriggerStringCli() {}

// @0x140ce8f50
GameEventDTRewardCli::GameEventDTRewardCli() {}

// @0x140ce8f80
GameEventDungeonExtraRewardCli::GameEventDungeonExtraRewardCli() {}

// @0x140ce8fb0
GameEventEventFieldPopupCli::GameEventEventFieldPopupCli() {}

// @0x140ce8fe0
GameEventGameMenuPopupCli::GameEventGameMenuPopupCli() {}

// @0x140ce9010
GameEventLongTermAttendGiftCli::GameEventLongTermAttendGiftCli() {}

// @0x140ce9040
GameEventMeratMarketNoticeCli::GameEventMeratMarketNoticeCli() {}

// @0x140ce9070
GameEventOntimeCli::GameEventOntimeCli() {}

// @0x140ce90a0
GameEventRpsCli::GameEventRpsCli() {}

// @0x140ce90d0
GameEventSaleAutoFishingCli::GameEventSaleAutoFishingCli() {}

// @0x140ce9100
GameEventSaleAutoPlayInstrumentCli::GameEventSaleAutoPlayInstrumentCli() {}

// @0x140ce9130
GameEventSnowmanCli::GameEventSnowmanCli() {}

// @0x140ce9160
GameEventStringBoardCli::GameEventStringBoardCli() {}

// @0x140ce9190
GameEventUpdateStringCli::GameEventUpdateStringCli() {}

// @0x140ce91c0
GameEventWorldmapIconCli::GameEventWorldmapIconCli() {}


// ---- dynamic initializers (.text$di) --------------------------------------------------------------------------------

#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regAttendGift(L"GameEventAttendGiftCli", FUN_140ce3250);
static Unk_GEFactoryRegistry s_regBurningLevelup(L"GameEventBurningLevelupCli", FUN_140ce6120);
static Unk_GEFactoryRegistry s_regCashAttend(L"GameEventCashAttendCli", FUN_140ce3b70);
static Unk_GEFactoryRegistry s_regCoupleDance(L"GameEventCoupleDanceCli", FUN_140ce5aa0);
static Unk_GEFactoryRegistry s_regCustomTriggerString(L"GameEventCustomTriggerStringCli", FUN_140ce5ed0);
static Unk_GEFactoryRegistry s_regDTReward(L"GameEventDTRewardCli", FUN_140ce2d30);
static Unk_GEFactoryRegistry s_regDungeonExtraReward(L"GameEventDungeonExtraRewardCli", FUN_140ce4640);
static Unk_GEFactoryRegistry s_regEventFieldPopup(L"GameEventEventFieldPopupCli", FUN_140ce2ba0);
static Unk_GEFactoryRegistry s_regGameMenuPopup(L"GameEventGameMenuPopupCli", FUN_140ce29f0);
static Unk_GEFactoryRegistry s_regItemBuff(L"GameEventItemBuffCli", FUN_140ce4330);
static Unk_GEFactoryRegistry s_regLongTermAttendGift(L"GameEventLongTermAttendGiftCli", FUN_140ce7870);
static Unk_GEFactoryRegistry s_regMeratMarketNotice(L"GameEventMeratMarketNoticeCli", FUN_140ce4770);
static Unk_GEFactoryRegistry s_regOntime(L"GameEventOntimeCli", FUN_140ce27f0);
static Unk_GEFactoryRegistry s_regRps(L"GameEventRpsCli", FUN_140ce56e0);
static Unk_GEFactoryRegistry s_regSaleAutoFishing(L"GameEventSaleAutoFishingCli", FUN_140ce3030);
static Unk_GEFactoryRegistry s_regSaleAutoPlayInstrument(L"GameEventSaleAutoPlayInstrumentCli", FUN_140ce3140);
static Unk_GEFactoryRegistry s_regSnowman(L"GameEventSnowmanCli", FUN_140ce53c0);
static Unk_GEFactoryRegistry s_regStringBoard(L"GameEventStringBoardCli", FUN_140ce51e0);
static Unk_GEFactoryRegistry s_regTrafficOptimizer(L"GameEventTrafficOptimizerCli", FUN_140ce40d0);
static Unk_GEFactoryRegistry s_regUpdateString(L"GameEventUpdateStringCli", FUN_140ce4970);
static Unk_GEFactoryRegistry s_regWorldmapIcon(L"GameEventWorldmapIconCli", FUN_140ce4d50);

// Header statics (the same sort-name tables as header_statics_a.h plus the grid column names).
static CStringA s_sortNames8A[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";
static CStringA s_sortNames8B[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif

// ---- smart-pointer glue ----------------------------------------------------------------------------------------------

void FUN_140c07070(void* pHolder);                          // AddRef of an attendance event holder
// @0x140ce8d10
template <> Unk_14102fe10<Unk_140ce3510>::Unk_14102fe10(Unk_140ce3510* p)
{
    m_p = p;
    FUN_140c07070(this);
}

// @0x140cea090
int EventIconInfo::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "fieldID", m_nFieldId);
    FUN_140873420(pElem, "iconFrame", m_strIconFrame);
    FUN_140873420(pElem, "eventStr", m_strEventStr);
    FUN_1408731e0(pElem, "offsetX", m_nOffsetX);
    FUN_1408731e0(pElem, "offsetY", m_nOffsetY);
    FUN_140873360(pElem, "scale", m_fScale);
    return m_nFieldId != 0;
}

// @0x140ce8ce0
template MS2Ptr<CMsgBoxDataItem>::MS2Ptr(CMsgBoxDataItem*);

// RpsGameData builds its text set (3 names + the message array, +0x18..+0x50) through these helpers; the shared header
// lays the members out flat.
// MS2-FUNCTIONAL: element loops are written out, the exe uses the EH vector iterators
// @0x140ce91f0
void* FUN_140ce91f0(void* p)
{
    CStringW* pNames = (CStringW*)p;
    for (int i = 0; i < 3; ++i)
        new (&pNames[i]) CStringW;
    new ((char*)p + 0x18) ATL::CAtlArray<void*>;
    return p;
}

// MS2-FUNCTIONAL: element loops are written out, the exe uses the EH vector iterators
// @0x140ce9720
void FUN_140ce9720(void* p)
{
    ((ATL::CAtlArray<void*>*)((char*)p + 0x18))->~CAtlArray();
    CStringW* pNames = (CStringW*)p;
    for (int i = 2; i >= 0; --i)
        pNames[i].~CStringW();
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca44b0-0x142ca4570 .text$yd
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142ca4450-0x142ca44b0 .text$yd
// MS2-RANGE: 0x142ca4570-0x142ca45d0 .text$yd
