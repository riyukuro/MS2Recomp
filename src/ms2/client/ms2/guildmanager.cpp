// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CGuildManager: guild requests and packet handlers.
// MS2-UNIT: client\ms2\guildmanager.cpp
// MS2-RANGE: 0x1413b5a10-0x1413d3000 .text$mn
// MS2-RANGE: 0x1400f4800-0x1400f4b40 .text$di
// MS2-RANGE: 0x142cb1280-0x142cb1430 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0VCGuildManager@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBQEAVCGuildManager@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x1413c8480 ; unique
// MS2-PIN: ??$?8PEAVCGuildManager@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x1413c8640 ; prop
// MS2-PIN: ??$?8PEAVCGuildManager@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVCGuildManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x1413c86b0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x1413cba30 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCGuildMember@@@@QEAAAEAV1@PEAVCGuildMember@@@Z 0x1413cc9b0 ; unique
// MS2-PIN: ??8?$MS2Ptr@VCGuildMember@@@@QEBA_NPEAVCGuildMember@@@Z 0x1413cca70
// MS2-PIN: ??8?$MS2Ptr@VCGuildSkill@@@@QEBA_NPEAVCGuildSkill@@@Z 0x1413ccab0
// MS2-PIN: ??8?$MS2Ptr@VCGuildCustomEvent@@@@QEBA_NPEAVCGuildCustomEvent@@@Z 0x1413ccaf0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1413d1ec0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1413d1f20 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x1413d25a0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x1413d25d0 ; unique
// MS2-PIN: ??$Call@VCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x1413d2610 ; unique
// MS2-PIN: ??$Call@VCGuildManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVCGuildManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x1413d2650 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1413d2690 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1413d26f0 ; unique
// MS2-PIN: ?pop_back@?$deque@V?$MS2Ptr@VCGuildPVPSeasonHistoryData@@@@V?$allocator@V?$MS2Ptr@VCGuildPVPSeasonHistoryData@@@@@std@@@std@@QEAAXXZ 0x1413d29d0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CGuildManager@@6B?$TSingleton@VCGuildManager@@@@@ 0x142f0a5d8
// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400f4980
// MS2-PIN: ?pop_back@?$deque@V?$MS2Ptr@VCGuildPVPHistoryData@@@@V?$allocator@V?$MS2Ptr@VCGuildPVPHistoryData@@@@@std@@@std@@QEAAXXZ 0x1413d28f0
// MS2-PIN: ?pop_front@?$deque@V?$MS2Ptr@VCGuildPVPHistoryData@@@@V?$allocator@V?$MS2Ptr@VCGuildPVPHistoryData@@@@@std@@@std@@QEAAXXZ 0x1413d2ab0
// MS2-PIN: ??$destroy@V?$MS2Ptr@VCGuildPVPHistoryData@@@@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCGuildPVPHistoryData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCGuildPVPHistoryData@@@@@1@QEAV?$MS2Ptr@VCGuildPVPHistoryData@@@@@Z 0x1413cb670
// MS2-PIN: ??$destroy@V?$MS2Ptr@VCGuildPVPSeasonHistoryData@@@@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCGuildPVPSeasonHistoryData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCGuildPVPSeasonHistoryData@@@@@1@QEAV?$MS2Ptr@VCGuildPVPSeasonHistoryData@@@@@Z 0x1413cb690
// MS2-PIN: ??1?$MS2Ptr@VCGuildPVPHistoryData@@@@QEAA@XZ 0x1413cc6a0
// MS2-PIN: ??1?$MS2Ptr@VCGuildPVPSeasonHistoryData@@@@QEAA@XZ 0x1413cc6d0
// MS2-PIN: ??_G?$MS2Ptr@VCGuildPVPHistoryData@@@@QEAAPEAXI@Z 0x1413cd620
// MS2-PIN: ??_G?$MS2Ptr@VCGuildPVPSeasonHistoryData@@@@QEAAPEAXI@Z 0x1413cd660
// MS2-PIN: ?get@?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@QEBAPEAUGuildNpc@CGuildXmlData@@XZ 0x1413cce40
// MS2-PIN: ??0?$MS2Ptr@VCGuildMember@@@@QEAA@AEBV0@@Z 0x1404ec5b0
// MS2-PIN: ??0?$MS2Ptr@VCGuildMember@@@@QEAA@H@Z 0x1404ec5f0
// MS2-PIN: ??0?$MS2Ptr@VCGuildMember@@@@QEAA@$$QEAV0@@Z 0x1404ec580
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\guildmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "guildmanager.h"
#include "pcbase.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/stringidinterface.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/uidialog.h"
#include "interactobject.h"
#include "worldservice.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Initializers retained in the .text$di range, in original order (names invented). The range after
// 0x1400f4b40 belongs to the next object (HardwareInstancingService message handlers).
static CStringW s_strGuildArenaJoin(L"guildArenaJoin");                        // @0x1400f4800
static CStringW s_strGuildInvite(L"guildinvite");                              // @0x1400f4830
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/statemanager_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
// the sound / effect keys of the guild notices
static CString s_strSystemGuildInvitation = "System_GuildInvitation";         // @0x1400f49f0
static CString s_strPcGuildMake = "PC_GuildMake";                              // @0x1400f4a20
static CString s_strGuildBattleApply = "guildBattle_Apply";                    // @0x1400f4a50
static CString s_strGuildBattleMatchingFail = "guildBattle_MatchingFail";      // @0x1400f4a80
static CString s_strGuildBattleMatchingSuccess = "guildBattle_MatchingSuccess";   // @0x1400f4ab0
static CString s_strGuildBattleMatchingNotice = "system_notice_GuildBattleMatching01";   // @0x1400f4ae0
static CString s_strPcInviteSuccess = "PC_InviteSuccess";                      // @0x1400f4b10

// ---- callees in other units (names inferred) ----
// Game-wide constants table: only the slots read here.
struct Unk_GuildConstInt { char m_pad_00[0x58]; };
struct Unk_GuildConstTable {
    char m_pad_00[0x4998];
    Unk_GuildConstInt m_guildCreateMinLevel;                  // +0x4998
    char m_pad_49f0[0x4aa0 - 0x49f0];
    Unk_GuildConstInt m_guildDonationMeso;                    // +0x4aa0
    Unk_GuildConstInt m_guildStorageGiftNeedPeriod;           // +0x4af8
    char m_pad_4b50[0x9d60 - 0x4b50];
    Unk_GuildConstInt m_guildNameMinLength;                   // +0x9d60
};
MS2_CHECK_OFFSET(Unk_GuildConstTable, m_guildCreateMinLevel, 0x4998);
MS2_CHECK_OFFSET(Unk_GuildConstTable, m_guildDonationMeso, 0x4aa0);
MS2_CHECK_OFFSET(Unk_GuildConstTable, m_guildStorageGiftNeedPeriod, 0x4af8);
MS2_CHECK_OFFSET(Unk_GuildConstTable, m_guildNameMinLength, 0x9d60);
Unk_GuildConstTable* FUN_1401d3200();
int* FUN_1402056b0(Unk_GuildConstInt* slot);

class Unk_GuildEventMgr { public: bool FUN_14047e880(); bool FUN_14047eca0(); };
Unk_GuildEventMgr* FUN_1401c0d90();
class Unk_GuildDialog4e28 { public: void FUN_1419381c0(); };
Unk_GuildDialog4e28* FUN_140938b90(int id);
class Unk_GuildDialog4e4f { public: void FUN_141973a70(); void FUN_141974240(); void FUN_141974640(); void FUN_1419729d0(); void FUN_14196cf80(); void FUN_14196f830(); void FUN_14196e230(bool show); void FUN_141973df0(const CStringW& oldName); void FUN_141973b20(const CStringW& newName); void FUN_14196da70(); void FUN_14196b620(); void FUN_14196e590(); void FUN_14196e2c0(); void FUN_14196c1d0(); void FUN_141970900(); void FUN_141971490(); void FUN_141971ac0(); void FUN_141972520(); void FUN_141972fc0(); void FUN_141973220(); void FUN_14196e0a0(); void FUN_141974930(); void FUN_141973fd0(int gradeIndex); void FUN_141974120(const CString& code); void FUN_141974190(const CStringW& guildName); void FUN_14196d0c0(int search); void FUN_14196d660(); };
Unk_GuildDialog4e4f* FUN_14136f480(int id);
void FUN_140506ca0(Unk_GuildMapC* history);   // std::deque<Unk_PayloadPtr<CGuildStorage::CGuildStroageHistory>>::clear over the opaque guilddef_1 spelling
class Unk_GuildNotifyCenter {
public:
    void FUN_140da4e40(CStringW name, Delegate<void(NotifyObject*)> handler);
    void FUN_140da4eb0(CStringW name, Delegate<void(NotifyObject*)> handler);
};
Unk_GuildNotifyCenter* FUN_140939a10();
class Unk_GuildFieldMgr { public: void FUN_14161cd60(__int64 characterId); };
Unk_GuildFieldMgr* FUN_1409f7c90();
// Ban-word filter behind the string table manager.
class Unk_GuildBanWord {
public:
    int FUN_140225720(const CStringW& text, CStringW& message);
    int FUN_1402259b0(const CStringW& text, CStringW& message);
    int FUN_140225c90(const CStringW& text, CStringW& message);
    int FUN_140225de0(const CStringW& text, CStringW& message);
};
class Unk_GuildBanWordPtr { public: ~Unk_GuildBanWordPtr(); Unk_GuildBanWord* FUN_14025cea0() const; void* m_00; void* m_08; };
class Unk_GuildStringMgr { public: Unk_GuildBanWordPtr FUN_140229a50(); };
Unk_GuildStringMgr* FUN_14025e7d0();
WorldService* FUN_1403ed2d0();
// The scoped lock (logstring.cpp's spelling): converts to 0 once the lock is held.
class Unk_140163940 {
public:
    Unk_140163940(CLockCriticalSection&);
    ~Unk_140163940();
    operator int() const;
private: void* m_lock;
};
CGuildManager* FUN_1403ed290();
CGuildXmlData* FUN_1404f4530();
// Game event bonus (guild donation bonus rate in 1/10000).
class Unk_GuildEventBonus { public: int FUN_140423780(); int FUN_140423450(); int FUN_140423560(); };
class Unk_GuildGameEventMgr {
public:
    Unk_GuildEventBonus* FUN_1403eea90();
    Unk_GuildEventBonus* FUN_1403eeab0();
    Unk_GuildEventBonus* FUN_1403eead0();
    int FUN_1413cdf60() { return 10000; }                  // the bonus rate scale
};
Unk_GuildGameEventMgr* FUN_140302b00();
// Party/field recall gate.
class Unk_GuildRecallGate { public: int FUN_140b040a0(int count); };
Unk_GuildRecallGate* FUN_140d294c0();
bool FUN_140841300(const CStringW& text, const char* value);
extern __int64 DAT_143ab2898;   // the local character's meso
extern int DAT_143ab2870;       // the local character's current map id
// A buff lookup result of the local character's buff list (PCBase::FUN_1416749a0).
class Unk_GuildBuffRef {
public:
    ~Unk_GuildBuffRef();                                       // 0x14096e5a0
    void* FUN_140975b90();                                     // the active buff, or 0
    void* m_00;
    void* m_08;
};
class Unk_PCBaseBuffs {
public:
    Unk_GuildBuffRef FUN_14096fe60(int buffId, unsigned short level, int a, bool b, int c);
};
CStringW FUN_14062b4f0(CStringW key, const int* value);
// The housing service, looked up from its registry cell.
class Unk_GuildHousingSvc { public: int FUN_1410d2f10(); };
class Unk_GuildHousingSvcPtr {
public:
    Unk_GuildHousingSvcPtr(Unk_GuildHousingSvc* p);           // 0x1401cd0b0
    ~Unk_GuildHousingSvcPtr();                                 // 0x1401cd150
    Unk_GuildHousingSvc* FUN_140885310() const;                // get
    Unk_GuildHousingSvc* FUN_1401cd1a0() const;                // operator->
    Unk_GuildHousingSvc* m_p;
};
Unk_GuildHousingSvc* FUN_1401cd040(char* cell);
extern char DAT_143b059e8;
// Content switches (feature ids).
class Unk_GuildFeatures { public: bool FUN_14036d570(int feature); };
Unk_GuildFeatures* FUN_140166410();
MS2Ptr<CItemData> FUN_14053f870(int itemId);
CStringW FUN_140938ae0(CStringW key, const int& value);
void FUN_140d73aa0(CStringW text, int type, void* data, CStringW tag);
void* FUN_1409613d0(PCBase* pc);
CStringW FUN_1405c2690(CStringW key, const CStringW& arg);
void FUN_140d73ff0(CStringW text);
class Unk_GuildMsgStrings { public: CStringW FUN_141812290(int buffId, unsigned short level, CString key); CStringW FUN_141811980(int table, int index); };
Unk_GuildMsgStrings* FUN_1401a9d70();
extern __int64 DAT_143ab2828;                       // the local character id
extern __int64 DAT_143ad9140;                       // the character the guild notice was last shown to
extern int DAT_143aaef18;                           // the current guild season id
class Unk_GuildUiMgr { public: void FUN_141adc5d0(int uiId); MS2Ptr<UIObject> FUN_141adcea0(int uiId); };
Unk_GuildUiMgr* FUN_1403ed2b0();
// The open UI dialog of an id, cast to its class.
template <class T> T* Unk_GuildFindDialog(int id)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(id);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}
class UIGuildHouseUpgradeDialog : public UIDialog { public: void FUN_140e39da0(); };
class UIPvPGuildTeamResultDialog : public UIDialog { public: void FUN_141341220(CInPacket& packet); };
CStringW FUN_14052bd00(int id, const CStringW& arg);
bool FUN_1403b3c40(const CStringW& text, const wchar_t* other);
CStringW FUN_140a2fcd0(__int64 begin, __int64 end);
CStringW FUN_140632a60(int id, const CStringW& arg0, const CStringW& arg1);
bool FUN_141b70f50(const CStringW& left, const CStringW& right);   // the names are equal
bool FUN_14025cd60(const CStringW& left, const CStringW& right);
CStringW FUN_1409eec40(int id);
CStringW FUN_1408116a0(int id, const int& value);
void FUN_1404eeaa0(Unk_GuildRef* grade);              // the grade reference dtor (guilddef_1.cpp)
int FUN_141adc890(Unk_GuildUiMgr* ui, int uiId);
CStringW FUN_140763e10(int value);                   // the number with digit grouping
CStringW FUN_1408f71a0(CStringW key, const CStringW& arg0, const CStringW& arg1);
CStringW FUN_141081c60(CStringW key, const CStringW& arg0, const CStringW& arg1, const int* arg2);
CStringW FUN_140d26d90(CStringW key, const CStringW& arg0, const int* arg1, const CStringW& arg2);
void FUN_1404ec690(Unk_GuildRef* out, const Unk_PayloadPtr<CGuildNpc>& npc);   // Unk_PayloadPtr<CGuildNpc> copy into raw storage
bool FUN_14028d780(char c);
void FUN_1404ec5b0(Unk_GuildRef* out, const MS2Ptr<CGuildMember>& member);   // MS2Ptr<CGuildMember> copy into raw storage
__int64 FUN_1404f0aa0(Unk_GuildRef* grade);          // the grade reference's get() (guilddef_1.cpp)
CGuildGrade* FUN_1404f0b70(Unk_GuildRef* grade);     // the grade reference's operator->
// The buddy list entry of a character (see buddymanager.cpp).
class Unk_GuildBuddyRef {
public:
    ~Unk_GuildBuddyRef();                                   // 0x140979fc0
    void* FUN_14097a170();                                  // get()
private:
    void* m_00;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_GuildBuddyRef, 0x10);
class Unk_GuildBuddyMgr { public: Unk_GuildBuddyRef FUN_140ae4950(const CStringW& name); };
Unk_GuildBuddyMgr* FUN_14097a780();
void FUN_1404ef970(Unk_GuildRef* dst, const MS2Ptr<CGuildMember>& src);   // MS2Ptr<CGuildMember> assignment into raw storage
bool FUN_1404effe0(Unk_GuildRef* grade, int null);   // the grade reference's operator==
int FUN_140267ef0(const Unk_GuildTriple* left, const Unk_GuildTriple* right);   // all three components equal
// An achievement (trophy) table row reference (see uimainplayerinfo.cpp).
class Unk_GuildAchieveRow { public: char m_pad_00[0x38]; int m_category; };
class Unk_GuildAchieveRowPtr {
public:
    ~Unk_GuildAchieveRowPtr();                              // 0x1401597b0
    bool FUN_140159920();                                   // == null
    Unk_GuildAchieveRow* FUN_140159a80();                   // operator->
private:
    void* m_00;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_GuildAchieveRowPtr, 0x10);
Unk_GuildAchieveRowPtr FUN_14015d9e0(int achieveId);
__int64 FUN_140869440();                                    // the server time
CMsTime FUN_1406c47a0(__int64 time);
CStringW FUN_14028de60(int id);
CStringW FUN_14083bab0(const CMsTime& time, CStringW separator);
CStringW FUN_140656190(const wchar_t* format, const CStringW& arg0, const CStringW& arg1);
CStringW FUN_140d2d8a0(int achieveId, int grade, CStringW text, CStringW date);
CStringW FUN_14062b4f0(CStringW key, const int* arg);
// Client options (+5: refuse guild invitations).
struct Unk_GuildClientOptions { bool m_flags[5]; bool m_refuseGuildInvite; };
class Unk_GuildOptionsMgr;
Unk_GuildOptionsMgr* FUN_1409a8b10();
Unk_GuildClientOptions* FUN_140ae6540(Unk_GuildOptionsMgr* mgr);
struct Unk_GuildBattleOptions { bool m_promptArenaJoin; };
Unk_GuildBattleOptions* FUN_140c9b8b0(Unk_GuildOptionsMgr* mgr);
// The local player's busy state (a pending party/trade request); see partymanager.cpp.
class Unk_GuildBusyState { public: bool FUN_140743550(); };
class Unk_GuildBusyStatePtr {
public:
    ~Unk_GuildBusyStatePtr();                               // 0x140964aa0
    Unk_GuildBusyState* operator->() const;                 // 0x140965970
private:
    void* m_00;
    Unk_GuildBusyState* m_p;
};
MS2_CHECK_SIZE(Unk_GuildBusyStatePtr, 0x10);
class Unk_GuildPlayer { public: Unk_GuildBusyStatePtr FUN_140967420(); };
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int type);
void FUN_1412752d0(const CStringW& text, int type);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int type, CStringW text, void* listener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
int FUN_140869470(int days);
CStringW FUN_14028de60(int id);
CStringW FUN_14028b8e0(const CStringW& key);
void FUN_1412751b0(const CStringW& text, int type);
void FUN_1412751f0(const CStringW& text, int type, int flag);
void FUN_141275260(int id, int type, int flag);
void FUN_141276180(const CString& name, const CString& arg);
void FUN_140d73bc0(int id, int a, void* b, CStringW text);
int FUN_141276c80(const CStringW& name, bool kind, CStringW& message);
int FUN_14086ace0(__int64 time);
bool FUN_1407105c0(COutPacket* packet, int key, int delay);
__int64 FUN_140869440();
// CGuildInfo containers reached through the guild chunk's COMDATs (see guilddef_1.cpp).
void* FUN_1404f4510(void* map);
MS2Ptr<CGuildMember>& FUN_1404f4f70(void* map, void* pos);
void FUN_1404f4700(void* map, void** pos);


// @0x1413b5a10
CGuildManager::CGuildManager()
{
    m_invite = 0;
    m_lastPvpHistoryId = 0;
    m_noticeAttendance = true;
    m_3e0 = false;
    m_400 = false;
    m_nextRefreshTime = 0;
    m_targetGuildId = 0;
    m_targetGuildName = L"";
    m_468 = 0;
    FUN_140939a10()->FUN_140da4e40(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &CGuildManager::FUN_1413bd5c0));
}

// @0x1413b5ca0
CGuildManager::~CGuildManager()
{
    m_invite = 0;
    FUN_140939a10()->FUN_140da4eb0(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &CGuildManager::FUN_1413bd5c0));
}

// @0x1413b5e80
void CGuildManager::FUN_1413b5e80()
{
    if (!FUN_1413b6160()) return;
    if (m_noticeAttendance) {
        if (FUN_1401c0d90()->FUN_14047e880()) {
            FUN_1412751f0(FUN_14028de60(0x3c4), 4, 1);
            m_noticeAttendance = false;
        }
    }
    if (FUN_14086ace0(m_nextRefreshTime) != 0) {
        if (Unk_GuildDialog4e28* dialog = FUN_140938b90(0x4e28))
            dialog->FUN_1419381c0();
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
            dialog->FUN_141973a70();
        m_nextRefreshTime = FUN_140869440();
    }
}
MS2_REPLACE_METHOD(0x1413B5E80, CGuildManager, FUN_1413b5e80, 257, 0x8AC759C9);

// @0x1413b5f90
void CGuildManager::FUN_1413b5f90()
{
    if (!FUN_1413b6160()) return;
    if (Unk_LockGuard guard = lock) {} else {
        for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
            MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
            if (member.get() != 0)
                FUN_1409f7c90()->FUN_14161cd60(member->data.f08);
        }
    }
    FUN_1404cc900();
    m_lastPvpHistoryId = 0;
    m_pvpHistory.clear();
    m_pvpSeasonHistory.clear();
    m_3e0 = false;
    m_400 = false;
    m_nextRefreshTime = 0;
}
MS2_REPLACE_METHOD(0x1413B5F90, CGuildManager, FUN_1413b5f90, 369, 0x6E224306);

// @0x1413b6110
void CGuildManager::FUN_1413b6110()
{
    if (m_invite == 0) return;
    m_invite = 0;
}
MS2_REPLACE_METHOD(0x1413B6110, CGuildManager, FUN_1413b6110, 65, 0x1957DBAA);

// @0x1413b6160
int CGuildManager::FUN_1413b6160()
{
    if ((unsigned __int64)FUN_1404ccbd0() > 0) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1413B6160, CGuildManager, FUN_1413b6160, 45, 0x88A95C3B);

// @0x1413b61a0
int CGuildManager::FUN_1413b61a0()
{
    if ((unsigned __int64)FUN_1404ccbd0() > 0) return 0;
    if (m_invite == 0) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1413B61A0, CGuildManager, FUN_1413b61a0, 77, 0x457B72EB);

// @0x1413b6200
MS2Ptr<CGuildMember> CGuildManager::FUN_1413b6200(__int64 characterId)
{
    MS2Ptr<CGuildMember> found(0);
    if (Unk_LockGuard guard = lock) {} else {
        for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
            MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
            if ((member.get() ? true : false) && member->data.f08 == characterId) {
                found = member;
                break;
            }
        }
    }
    return found;
}
MS2_REPLACE_METHOD(0x1413B6200, CGuildManager, FUN_1413b6200, 350, 0x4A61614B);

// @0x1413b6370
void CGuildManager::FUN_1413b6370(CInPacket& packet)
{
    int type = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (type) {
    case 0: return FUN_1413bd680(packet);
    case 1: return FUN_1413bd8a0(packet);
    case 2: return FUN_1413bda00(packet);
    case 3: return FUN_1413bdaf0(packet);
    case 4: return FUN_1413bdbb0(packet);
    case 5: return FUN_1413be020(packet);
    case 6: return FUN_1413be150(packet);
    case 7: return FUN_1413be350(packet);
    case 8: return FUN_1413be400(packet);
    case 9: return FUN_1413be460(packet);
    case 0xb: return FUN_1413be670(packet);
    case 0xa: return FUN_1413be7e0(packet);
    case 0xc: return FUN_1413be870(packet);
    case 0xe: return FUN_1413beb10(packet);
    case 0xf: return FUN_1413bebc0(packet);
    case 0x71: return FUN_1413bece0(packet);
    case 0x3f: return FUN_1413bee70(packet);
    case 0x40: return FUN_1413beed0(packet);
    case 0x41: return FUN_1413beff0(packet);
    case 0x42: return FUN_1413bf050(packet);
    case 0x43: return FUN_1413bf130(packet);
    case 0x44: return FUN_1413bf2a0(packet);
    case 0x5a: return FUN_1413bf340(packet);
    case 0x5b: return FUN_1413bf540(packet);
    case 0x61: return FUN_1413bf690(packet);
    case 0x63: return FUN_1413bf9a0(packet);
    case 0x12: return FUN_1413bfaf0(packet);
    case 0x13: return FUN_1413bfe50(packet);
    case 0x14: return FUN_1413c0030(packet);
    case 0x21: return FUN_1413c0250(packet);
    case 0x17: return FUN_1413c0430(packet);
    case 0x18: return FUN_1413c0630(packet);
    case 0x15: return FUN_1413c0880(packet);
    case 0x16: return FUN_1413c0be0(packet);
    case 0x24: return FUN_1413c0d30(packet);
    case 0x25: return FUN_1413c0e70(packet);
    case 0x19: return FUN_1413c0fe0(packet);
    case 0x1a: return FUN_1413c13d0(packet);
    case 0x1b: return FUN_1413c15b0(packet);
    case 0x22: return FUN_1413c1720(packet);
    case 0x1c: return FUN_1413c1840(packet);
    case 0x1d: return FUN_1413c1960(packet);
    case 0x1e: return FUN_1413c1c50(packet);
    case 0x20: return FUN_1413c1d30(packet);
    case 0x1f: return FUN_1413c1f00(packet);
    case 0x27: return FUN_1413c2860(packet);
    case 0x28: return FUN_1413c28e0(packet);
    case 0x29: return FUN_1413c2c60(packet);
    case 0x2a: return FUN_1413c2e50(packet);
    case 0x2b: return FUN_1413c2fc0(packet);
    case 0x2c: return FUN_1413c3080(packet);
    case 0x6b: return FUN_1413c3110(packet);
    case 0x32: return FUN_1413c4aa0(packet);
    case 0x33: return FUN_1413c4b60(packet);
    case 0x34: return FUN_1413c4bd0(packet);
    case 0x36: return FUN_1413c3170(packet);
    case 0x37: return FUN_1413c3460(packet);
    case 0x38: return FUN_1413c3780(packet);
    case 0x39: return FUN_1413c39e0(packet);
    case 0x3a: return FUN_1413c3c40(packet);
    case 0x6e: return FUN_1413c3e50(packet);
    case 0x3b: return FUN_1413c3ef0(packet);
    case 0x3d: FUN_1413c41b0(packet);
    case 0x3e: FUN_1413c4300(packet);
    case 0x76: return FUN_1413c4420(packet);
    case 0x75: return FUN_1413c4580(packet);
    case 0x77: return FUN_1413c45e0(packet);
    case 0x7a: return FUN_1413c4870(packet);
    case 0x7b: return FUN_1413c48b0(packet);
    case 0x4c: return FUN_1413c4c40(packet);
    case 0x47: return FUN_1413c4dd0(packet);
    case 0x4f: return FUN_1413c4e20(packet);
    case 0x50: return FUN_1413c4ed0(packet);
    case 0x4d: return FUN_1413c7700(packet);
    case 0x4e: return FUN_1413c7810(packet);
    case 0x23: return FUN_1413c2030(packet);
    case 0x26: return FUN_1413c23d0(packet);
    case 0x35: return FUN_1413c2590(packet);
    case 0x4a: return FUN_1413c5000(packet);
    case 0x4b: return FUN_1413c51c0(packet);
    case 0x52: return FUN_1413c5360(packet);
    case 0x53: return FUN_1413c5440(packet);
    case 0x54: return FUN_1413c5520(packet);
    case 0x55: return FUN_1413c5690(packet);
    case 0x56: return FUN_1413c5840(packet);
    case 0x57: return FUN_1413c59e0(packet);
    case 0x6d: return FUN_1413c5c00(packet);
    case 0x70: return FUN_1413c5dc0(packet);
    case 0x30: return FUN_1413c5f90(packet);
    case 0x2f: return FUN_1413c6180(packet);
    case 0x2d: return FUN_1413c6460(packet);
    case 0x2e: return FUN_1413c6580(packet);
    default:
        MS2_ASSERT_AT(0xeb, FALSE);
    }
}
MS2_REPLACE_METHOD(0x1413B6370, CGuildManager, FUN_1413b6370, 1949, 0xBACC3F7D);

// MS2-FUNCTIONAL: pc->vfunc_78() returns the level as unsigned short in the exe (movzx); pcbase.h declares int.
// @0x1413b6d10
bool CGuildManager::FUN_1413b6d10(CStringW name)
{
    if (FUN_1413b6160() == 1) return false;
    if (FUN_1413b61a0() == 1) return false;
    int minLength = *FUN_1402056b0(&FUN_1401d3200()->m_guildNameMinLength);
    if (name.GetLength() < minLength) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_invalide_create_name"), 1, 1);
        return false;
    }
    if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
        CStringW message;
        if (banWord->FUN_140225720(name, message) != 0) {
            FUN_1412751f0(message, 1, 1);
            return false;
        }
    }
    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0) return false;
    int level = pc->vfunc_78();
    if (level <= *FUN_1402056b0(&FUN_1401d3200()->m_guildCreateMinLevel)) {
        FUN_1413c66f0(1, 0x13, 0);
        return false;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(1);
    packet.vfunc_o10_8(name);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413B6D10, CGuildManager, FUN_1413b6d10, 763, 0x714A659F);

// @0x1413b7020
bool CGuildManager::FUN_1413b7020()
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return false;
    if (!FUN_1413b6160()) return false;
    if (FUN_1404d0020() > 1) {
        FUN_140d73bc0(0x40e, 0, 0, L"");
        return false;
    }
    if (!FUN_1404d01b0(myName)) return false;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(2);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413B7020, CGuildManager, FUN_1413b7020, 395, 0x358783A5);

// @0x1413b71c0
bool CGuildManager::FUN_1413b71c0(CStringW name)
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return false;
    CStringW message;
    int result = FUN_141276c80(name, true, message);
    if (result != 0) {
        int id = result == 10 ? 0x38d : 0x38e;
        FUN_141275260(id, 1, 1);
        return false;
    }
    if (!FUN_1413b6160()) return false;
    if (!FUN_1404d0600(myName, 2)) {
        FUN_141275260(0x415, 1, 1);
        return false;
    }
    if (FUN_1404d0020() >= FUN_1404cd1c0()) {
        FUN_140d73bc0(0x40f, 0, 0, L"");
        return false;
    }
    FUN_141276180(s_strPcInviteSuccess, "");
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(3);
    packet.vfunc_o10_8(name);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413B71C0, CGuildManager, FUN_1413b71c0, 810, 0x7CD4D2E7);

// @0x1413b74f0
void CGuildManager::FUN_1413b74f0(int accept)
{
    if (FUN_1413b6160() == 1) return;
    if (!FUN_1413b61a0()) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(5);
    m_invite->FUN_1404c9160(packet);
    packet.vfunc_o10_1((unsigned char)accept);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B74F0, CGuildManager, FUN_1413b74f0, 159, 0xF58ACAD6);

// @0x1413b75a0
void CGuildManager::FUN_1413b75a0()
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (!FUN_1413b6160()) return;
    if (FUN_1404d01b0(myName) == 1) {
        FUN_141275260(0x396, 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(7);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B75A0, CGuildManager, FUN_1413b75a0, 275, 0x3A516CA2);

// @0x1413b76c0
void CGuildManager::FUN_1413b76c0(CStringW name)
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (myName.CompareNoCase(name) == 0) return;
    if (!FUN_1413b6160()) return;
    if (!FUN_1404d0600(myName, 4)) return;
    if (FUN_1404d01b0(name)) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(8);
    packet.vfunc_o10_8(name);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B76C0, CGuildManager, FUN_1413b76c0, 498, 0xEC38E14E);

// @0x1413b78c0
void CGuildManager::FUN_1413b78c0(CStringW name, int grade)
{
    int length = name.GetLength();
    if (length < 2 || length > 0x18) {
        MS2_ASSERT_AT(0x664, FALSE);
        return;
    }
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (!FUN_1413b6160()) return;
    if (grade <= 0 || grade > FUN_1404d0580()) return;
    if (!FUN_1404d0600(myName, 0x20)) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_8(name);
    packet.vfunc_o10_1((unsigned char)grade);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B78C0, CGuildManager, FUN_1413b78c0, 519, 0x9B2C8425);

// @0x1413b7ad0
void CGuildManager::FUN_1413b7ad0(CStringW name)
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (myName.CompareNoCase(name) == 0) return;
    if (!FUN_1413b6160()) return;
    if (!FUN_1404d01b0(myName)) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x3f);
    packet.vfunc_o10_8(name);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B7AD0, CGuildManager, FUN_1413b7ad0, 398, 0xE3925E98);

// @0x1413b7c70
bool CGuildManager::FUN_1413b7c70(int kind, CStringW text)
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return false;
    if (!FUN_1413b6160()) return false;
    if (kind == 0) {
        if (text.GetLength() > 1000) return false;
        if (!FUN_1404d01b0(myName)) return false;
    } else if (kind == 1) {
        if (text.GetLength() > 300) return false;
        if (!FUN_1404d0600(myName, 8)) return false;
        if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
            CStringW message;
            if (banWord->FUN_1402259b0(text, message) != 0) return false;
        }
    }
    if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
        CStringW message;
        if (banWord->FUN_140225de0(text, message) != 0) {
            FUN_1412751f0(message, 1, 1);
            return false;
        }
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x40);
    packet.vfunc_o10_1((unsigned char)kind);
    packet.vfunc_o10_8(text);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413B7C70, CGuildManager, FUN_1413b7c70, 1105, 0xB7681062);

// @0x1413b80d0
bool CGuildManager::FUN_1413b80d0(const CStringW& text)
{
    if (!FUN_1413b6160()) return false;
    if (text.GetLength() > 0x14) return false;
    if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
        CStringW message;
        if (banWord->FUN_140225de0(text, message) != 0) {
            FUN_1412751f0(message, 1, 1);
            return false;
        }
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0xd);
    packet.vfunc_o10_8(text);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413B80D0, CGuildManager, FUN_1413b80d0, 333, 0x82B4AE83);

// @0x1413b8230
bool CGuildManager::FUN_1413b8230()
{
    if (!FUN_1413b6160()) return false;
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(FUN_1413c7c20());
    if (member == 0) return false;
    if (FUN_14086ace0(member->fc8) == 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_can_next_day"), 1, 1);
        return false;
    }
    if (!FUN_1413b8460()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_attend_already"), 1, 1);
        return false;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0xf);
    FUN_1407105c0(&packet, 0xf, 1000);
    return true;
}
MS2_REPLACE_METHOD(0x1413B8230, CGuildManager, FUN_1413b8230, 549, 0x4E99A56C);

// @0x1413b8460
bool CGuildManager::FUN_1413b8460()
{
    if (!FUN_1413b6160()) return false;
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(FUN_1413c7c20());
    if (member == 0) return false;
    if (FUN_14086ace0(member->fd8) == 0) return false;
    return true;
}
MS2_REPLACE_METHOD(0x1413B8460, CGuildManager, FUN_1413b8460, 211, 0x527B066B);

// @0x1413b8540
bool CGuildManager::FUN_1413b8540(int amount)
{
    if (!FUN_1413b6160()) return false;
    if (amount <= 0) return false;
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(FUN_1413c7c20());
    if (member == 0) return false;
    if (FUN_14086ace0(member->fc8) == 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_can_next_day"), 1, 1);
        return false;
    }
    Unk_PayloadPtr<CGuildXmlData::GuildProperty> property = FUN_1404f4530()->FUN_1404d7410(FUN_1404d1ad0());
    if (property == 0) return false;
    if (member->FUN_1404cb3e0() + amount > property->f30) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_donateMax"), 1, 1);
        return false;
    }
    int bonusRate = FUN_140302b00()->FUN_1403eea90()->FUN_140423780();
    __int64 cost = *FUN_1402056b0(&FUN_1401d3200()->m_guildDonationMeso) * amount;
    __int64 fund = cost;
    fund += fund * ((float)bonusRate / 10000.0f);
    __int64 guildFund = FUN_1404d1df0();
    __int64 guildFundMax = FUN_1404d1e90();
    if (guildFund + fund > guildFundMax) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_donate_guildFundMax"), 1, 1);
        return false;
    }
    if (DAT_143ab2898 < cost) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_no_money"), 1, 1);
        return false;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x71);
    packet.vfunc_o10_3(amount);
    FUN_1407105c0(&packet, 0x71, 200);
    return true;
}
MS2_REPLACE_METHOD(0x1413B8540, CGuildManager, FUN_1413b8540, 1331, 0xDB077540);

// @0x1413b8a80
void CGuildManager::FUN_1413b8a80(CString text)
{
    if (text.GetLength() > 500) {
        MS2_ASSERT_AT(0x74b, FALSE);
        return;
    }
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (!FUN_1413b6160()) return;
    if (!FUN_1404d0600(FUN_1413c7c20(), 0x40)) {
        FUN_141275260(0x415, 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x41);
    packet.vfunc_o10_6(text);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B8A80, CGuildManager, FUN_1413b8a80, 439, 0x2A0F3618);

// @0x1413b8c40
void CGuildManager::FUN_1413b8c40(int index, CGuildGrade grade)
{
    if (!grade.FUN_1404c72b0()) return;
    if (grade.grade != index) return;
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (!FUN_1413b6160()) return;
    if (!FUN_1404d01b0(myName)) return;
    if (index < 0 || index >= 6) return;
    if (index > FUN_1404d0580() + 1) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x43);
    packet.vfunc_o10_1((unsigned char)index);
    grade.FUN_1404c7160(packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B8C40, CGuildManager, FUN_1413b8c40, 537, 0x9A76DCD2);

// @0x1413b8e60
void CGuildManager::FUN_1413b8e60(int focus, int value)
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (!FUN_1413b6160()) return;
    if (f154 == focus && f158 == value) return;
    if (!FUN_1404d0600(myName, 2)) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x44);
    packet.vfunc_o10_1((unsigned char)focus);
    packet.vfunc_o10_3(value);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B8E60, CGuildManager, FUN_1413b8e60, 364, 0x80447355);

// @0x1413b8fe0
void CGuildManager::FUN_1413b8fe0(int skillId)
{
    if (!FUN_1413b6160()) return;
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_141275260(0x416, 1, 1);
        return;
    }
    int skillLevel = FUN_1404d26f0(skillId);
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skillData = FUN_1404f4530()->FUN_1404d74e0(skillId, skillLevel);
    if (skillData == 0) return;
    int requiredLevel = FUN_1404f4530()->FUN_1404d7130(FUN_1404d1a80());
    if (requiredLevel < skillData->f20) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_not_enough_guild_level"), 1, 1);
        return;
    }
    int fund = skillData->FUN_1404d4e80() ? FUN_1404d1e40() : FUN_1404d1df0();
    CStringW fundError(skillData->FUN_1404d4e80() ? FUN_14028b8e0(L"s_guild_err_not_enough_guild_event_fund")
                                                   : FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund"));
    if (fund < FUN_1403ed290()->FUN_1413bd050(skillId, skillLevel)) {
        FUN_1412751f0(fundError, 1, 1);
        return;
    }
    MS2Ptr<CGuildSkill> skill = FUN_1404d2640(skillId);
    if (skill == 0) return;
    if (!skill->FUN_1404cbcd0()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_cannot_use_skill"), 1, 1);
        return;
    }
    if (FUN_140841300(skillData->f40, "recall")) {
        ATL::CAtlMap<__int64, __int64> members;
        int memberCount = FUN_1404d3400(&members);
        int count = memberCount - 1;
        if (count <= 0) {
            FUN_140d73bc0(0xb5c, 0, 0, L"");
            return;
        }
        if (FUN_140d294c0()->FUN_140b040a0(count) == 0) return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x5a);
    packet.vfunc_o10_3(skillId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B8FE0, CGuildManager, FUN_1413b8fe0, 1783, 0x5D88B8E5);

// @0x1413b96e0
void CGuildManager::FUN_1413b96e0(int skillId)
{
    if (!FUN_1413b6160()) return;
    int skillLevel = FUN_1404d26f0(skillId);
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skillData = FUN_1404f4530()->FUN_1404d74e0(skillId, skillLevel);
    if (skillData == 0) return;
    if (!skillData->FUN_1404d4e40()) return;
    int requiredLevel = FUN_1404f4530()->FUN_1404d7130(FUN_1404d1a80());
    if (requiredLevel < skillData->f20) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_not_enough_guild_level"), 1, 1);
        return;
    }
    if (DAT_143ab2898 < FUN_1413bd1a0(skillId, skillLevel)) {
        FUN_1412751f0(FUN_14028b8e0(L"s_err_lack_meso"), 1, 1);
        return;
    }
    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0) return;
    Unk_GuildBuffRef buff = pc->FUN_1416749a0()->FUN_14096fe60(skillData->f34, skillData->f38, 0, true, 1);
    if (buff.FUN_140975b90() != 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_cannot_use_skill"), 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x5b);
    packet.vfunc_o10_3(skillId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B96E0, CGuildManager, FUN_1413b96e0, 981, 0xCE9A471E);

// @0x1413b9ac0
void CGuildManager::FUN_1413b9ac0(int skillId)
{
    if (!FUN_1413b6160()) return;
    int skillLevel = FUN_1404d26f0(skillId);
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> current = FUN_1404f4530()->FUN_1404d74e0(skillId, skillLevel);
    if (current == 0) return;
    int nextLevel = skillLevel + 1;
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> next = FUN_1404f4530()->FUN_1404d74e0(skillId, nextLevel);
    if (next == 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_max_level"), 1, 1);
        return;
    }
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_1412751f0(FUN_14028de60(0x416), 1, 1);
        return;
    }
    if (next->f20 > FUN_1404d1ad0()) {
        FUN_1412751f0(FUN_14062b4f0(CStringW(L"s_guild_err_need_guild_level"), &next->f20), 1, 1);
        return;
    }
    int fund = current->FUN_1404d4e80() ? FUN_1404d1e40() : FUN_1404d1df0();
    CStringW fundError(current->FUN_1404d4e80() ? FUN_14028b8e0(L"s_guild_err_not_enough_guild_event_fund")
                                                : FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund"));
    if (next->f24 > fund) {
        FUN_1412751f0(fundError, 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x5c);
    packet.vfunc_o10_3(skillId);
    FUN_1407105c0(&packet, 0x5c, 1000);
}
MS2_REPLACE_METHOD(0x1413B9AC0, CGuildManager, FUN_1413b9ac0, 1453, 0xDA842B83);

// @0x1413ba080
void CGuildManager::FUN_1413ba080(int eventId)
{
    if (!FUN_1413b6160()) return;
    Unk_PayloadPtr<CGuildXmlData::GuildEvent> eventData = FUN_1404f4530()->FUN_1404d7830(eventId);
    if (eventData == 0) return;
    __int64 now = FUN_140869440();
    if (FUN_1404ccec0() + FUN_140869470(1) > now) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_cannot_open_event_create_date"), 1, 1);
        return;
    }
    if (!FUN_1404d0600(FUN_1413c7c20(), 0x400)) {
        FUN_141275260(0x415, 1, 1);
        return;
    }
    MS2Ptr<CGuildCustomEvent> customEvent = FUN_1404d27b0(eventId);
    if (customEvent == 0) return;
    if (customEvent->FUN_1404cbee0() == true) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(99);
    packet.vfunc_o10_3(eventId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BA080, CGuildManager, FUN_1413ba080, 636, 0x9FB82CA0);

// @0x1413ba310
void CGuildManager::FUN_1413ba310(int eventId)
{
    if (!FUN_1413b6160()) return;
    Unk_PayloadPtr<CGuildXmlData::GuildEvent> eventData = FUN_1404f4530()->FUN_1404d7830(eventId);
    if (eventData == 0) return;
    MS2Ptr<CGuildCustomEvent> customEvent = FUN_1404d27b0(eventId);
    if (customEvent == 0) return;
    if (!customEvent->FUN_1404cbee0()) return;
    if (DAT_143ab2870 == eventData->f1c) {
        FUN_141275260(0x27b, 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(100);
    packet.vfunc_o10_3(eventId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BA310, CGuildManager, FUN_1413ba310, 403, 0xD386C619);

// @0x1413ba4b0
void CGuildManager::FUN_1413ba4b0()
{
    if (!FUN_1413b6160()) return;
    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0) return;
    if (pc->FUN_14166ce30() == 1) {
        FUN_141275260(0x279, 1, 1);
        return;
    }
    if (pc->vfunc_65() == 1) {
        FUN_141275260(0x27a, 1, 1);
        return;
    }
    int houseLevel = FUN_1404d1f90();
    int houseTheme = FUN_1404d2030();
    Unk_PayloadPtr<CGuildXmlData::GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(houseLevel, houseTheme);
    if (house == 0) return;
    if (FUN_1403ed2d0()->FUN_141bd3060() == house->f50) {
        FUN_1412751f0(FUN_14028b8e0(L"s_common_cant_move_from_here"), 1, 1);
        return;
    }
    if (FUN_1403ed2d0()->FUN_141bd30a0()->m_5c == 0) {
        Unk_GuildHousingSvcPtr housing(FUN_1401cd040(&DAT_143b059e8));
        if ((housing.FUN_140885310() ? true : false) && housing.FUN_1401cd1a0()->FUN_1410d2f10()) {
        } else {
            FUN_1412751f0(FUN_14028b8e0(L"s_common_cant_move_from_here"), 1, 1);
            return;
        }
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x67);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BA4B0, CGuildManager, FUN_1413ba4b0, 860, 0x926C7D25);

// @0x1413ba820
void CGuildManager::FUN_1413ba820(int level, int theme)
{
    if (!FUN_140166410()->FUN_14036d570(0x5b)) return;
    if (!FUN_1413b6160()) return;
    int nextLevel = FUN_1404d1f90() + 1;
    if (level != nextLevel) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_need_pre_house_level"), 1, 1);
        return;
    }
    Unk_PayloadPtr<CGuildXmlData::GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(nextLevel, theme);
    if (house == 0) return;
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_1412751f0(FUN_14028de60(0x416), 1, 1);
        return;
    }
    if (house->f2c > FUN_1404d1ad0()) {
        FUN_1412751f0(FUN_14062b4f0(CStringW(L"s_guild_err_need_guild_level"), &house->f2c), 1, 1);
        return;
    }
    if (house->f28 > FUN_1404d1df0()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund"), 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x65);
    packet.vfunc_o10_3(theme);
    FUN_1407105c0(&packet, 0x65, 1000);
}
MS2_REPLACE_METHOD(0x1413BA820, CGuildManager, FUN_1413ba820, 956, 0x590A86BA);

// @0x1413babf0
void CGuildManager::FUN_1413babf0(int theme)
{
    if (!FUN_140166410()->FUN_14036d570(0x5b)) return;
    if (!FUN_1413b6160()) return;
    int level = FUN_1404d1f90();
    Unk_PayloadPtr<CGuildXmlData::GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(level, theme);
    if (house == 0) return;
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_1412751f0(FUN_14028de60(0x416), 1, 1);
        return;
    }
    int currentTheme = FUN_1404d2030();
    if (currentTheme == theme) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_same_guild_house_theme"), 1, 1);
        return;
    }
    if (house->f30 > FUN_1404d1df0()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund"), 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x66);
    packet.vfunc_o10_3(theme);
    FUN_1407105c0(&packet, 0x66, 1000);
}
MS2_REPLACE_METHOD(0x1413BABF0, CGuildManager, FUN_1413babf0, 754, 0x4477F79B);

// @0x1413baef0
void CGuildManager::FUN_1413baef0(int posterId, unsigned char show)
{
    if (!FUN_140166410()->FUN_14036d570(0x5b)) return;
    ATL::CAtlArray<MS2Ptr<CInteractObject>> objects;
    FUN_1403ed2d0()->FUN_141bc5fb0(&objects, 7);
    for (size_t i = 0; i < objects.GetCount(); i++) {
        CInteractGuildPosterObject* poster = dynamic_cast<CInteractGuildPosterObject*>(objects[i].get());
        if (poster == 0) continue;
        if (poster->FUN_141402e60() != posterId) continue;
        poster->FUN_141402eb0(show);
    }
}
MS2_REPLACE_METHOD(0x1413BAEF0, CGuildManager, FUN_1413baef0, 262, 0x193C7769);

// @0x1413bb000
void CGuildManager::FUN_1413bb000(Unk_GuildNpcKind kind)
{
    if (!FUN_1413b6160()) return;
    int level = FUN_1404d2990(kind);
    int nextLevel = level + 1;
    Unk_PayloadPtr<CGuildXmlData::GuildNpc> npc = FUN_1404f4530()->FUN_1404d7b40(kind, nextLevel);
    if (npc == 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_max_level"), 1, 1);
        return;
    }
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_1412751f0(FUN_14028de60(0x416), 1, 1);
        return;
    }
    if (npc->f28 > FUN_1404d1ad0()) {
        FUN_1412751f0(FUN_14062b4f0(CStringW(L"s_guild_err_need_guild_level"), &npc->f28), 1, 1);
        return;
    }
    if (npc->f2c > FUN_1404d1f90()) {
        FUN_1412751f0(FUN_14062b4f0(CStringW(L"s_guild_err_need_guild_level"), &npc->f2c), 1, 1);
        return;
    }
    if (npc->f20 > FUN_1404d1df0()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund"), 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x72);
    packet.vfunc_o10_3(kind);
    FUN_1407105c0(&packet, 0x72, 1000);
}
MS2_REPLACE_METHOD(0x1413BB000, CGuildManager, FUN_1413bb000, 1152, 0xB931FFA8);

// @0x1413bb490
bool CGuildManager::FUN_1413bb490(ItemEntity& item, const CStringW& receiver)
{
    if (!FUN_1413b6160()) return false;
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_1412751f0(FUN_14028de60(0x416), 1, 1);
        return false;
    }
    if (receiver.IsEmpty()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_empty_member"), 1, 1);
        return false;
    }
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(receiver);
    if (member == 0) {
        FUN_1412751f0(FUN_14028de60(0x40d), 1, 1);
        return false;
    }
    if (item.m_count == 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_empty_count"), 1, 1);
        return false;
    }
    int stored = FUN_1404d2db0(item.vfunc_o18_0(), item.vfunc_o18_1());
    if (stored < 0) stored = 0;
    MS2Ptr<CItemData> itemData = FUN_14053f870(item.vfunc_o18_0());
    if (itemData == 0) return false;
    if ((unsigned)itemData->FUN_14053de60() < item.m_count) {
        int maxCount = itemData->FUN_14053de60();
        FUN_1412751f0(FUN_140938ae0(CStringW(L"s_guild_err_storage_over_slot_max_count"), maxCount), 1, 1);
        return false;
    }
    if ((unsigned)stored < item.m_count) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_storage_not_enough_count"), 1, 1);
        return false;
    }
    if (itemData->FUN_14053c6b0(0xd7)) {
        if (receiver != FUN_1413c7c20()) {
            FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_storage_send_only_to_me"), 1, 1);
            return false;
        }
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x6d);
    item.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(static_cast<COutputStream&>(packet)));   // itemgift.h types the stream as Unk_GiftOutput
    packet.vfunc_o10_8(receiver);
    FUN_1407105c0(&packet, 0x6d, 1000);
    return true;
}
MS2_REPLACE_METHOD(0x1413BB490, CGuildManager, FUN_1413bb490, 1766, 0x29FDE838);

// @0x1413bbb80
void CGuildManager::FUN_1413bbb80()
{
    if (!m_400) {
        COutPacket packet(0x4b, 0);
        packet.vfunc_o10_1(0x70);
        FUN_140710590(packet);
    } else {
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
            dialog->FUN_1419729d0();
    }
}
MS2_REPLACE_METHOD(0x1413BBB80, CGuildManager, FUN_1413bbb80, 129, 0x0AB11C34);

// @0x1413bbc10
bool CGuildManager::FUN_1413bbc10(const CStringW& title, const CStringW& body)
{
    if (title.GetLength() > 100) {
        FUN_141275260(0x244, 1, 1);
        return false;
    }
    if (body.GetLength() > 2000) {
        FUN_141275260(0x244, 1, 1);
        return false;
    }
    if (body.GetLength() < 1 || title.GetLength() < 1) {
        FUN_141275260(0x244, 1, 1);
        return false;
    }
    if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
        CStringW message;
        if (banWord->FUN_140225c90(title, message) || banWord->FUN_140225de0(body, message)) {
            FUN_1412751f0(message, 1, 1);
            return false;
        }
    }
    if (!FUN_1404d0600(FUN_1413c7c20(), 0x80)) {
        FUN_141275260(0x415, 1, 1);
        return false;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x47);
    packet.vfunc_o10_8(title);
    packet.vfunc_o10_8(body);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413BBC10, CGuildManager, FUN_1413bbc10, 609, 0xBC0EAAEE);

// @0x1413bbe80
void CGuildManager::FUN_1413bbe80()
{
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x4a);
    packet.vfunc_o10_4(m_lastPvpHistoryId);
    FUN_140710590(packet);
    if (!m_3e0) {
        COutPacket seasonPacket(0x4b, 0);
        seasonPacket.vfunc_o10_1(0x4b);
        FUN_140710590(seasonPacket);
        m_3e0 = true;
    } else {
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
            dialog->FUN_141974640();
    }
}
MS2_REPLACE_METHOD(0x1413BBE80, CGuildManager, FUN_1413bbe80, 226, 0xCC07F015);

// @0x1413bbf70
void CGuildManager::FUN_1413bbf70(ATL::CAtlArray<MS2Ptr<CGuildPVPHistoryData>>& out)
{
    for (int i = (int)m_pvpHistory.size() - 1; i >= 0; i--)
        out.Add(m_pvpHistory[i]);
}
MS2_REPLACE_METHOD(0x1413BBF70, CGuildManager, FUN_1413bbf70, 103, 0x37334414);

// @0x1413bbfe0
void CGuildManager::FUN_1413bbfe0(ATL::CAtlArray<MS2Ptr<CGuildPVPSeasonHistoryData>>& out)
{
    for (int i = (int)m_pvpSeasonHistory.size() - 1; i >= 0; i--)
        out.Add(m_pvpSeasonHistory[i]);
}
MS2_REPLACE_METHOD(0x1413BBFE0, CGuildManager, FUN_1413bbfe0, 103, 0xB4A0F13B);

// @0x1413bc050
void CGuildManager::FUN_1413bc050()
{
    if (FUN_1404d10d0() != 2) {
        CStringW message = FUN_14028de60(0x3c5);
        FUN_1412751f0(message, 1, 1);
        return;
    }
    if (FUN_1404ccbd0() != m_targetGuildId) {
        CStringW message = FUN_14028de60(0x3c7);
        FUN_1412751f0(message, 1, 1);
        return;
    }
    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0) return;
    if (pc->FUN_14166ce30() == 1) {
        FUN_141275260(0x279, 1, 1);
        return;
    }
    COutPacket packet(0x61, 0);
    packet.vfunc_o10_1(3);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC050, CGuildManager, FUN_1413bc050, 314, 0x235DE993);

// @0x1413bc190
void CGuildManager::FUN_1413bc190()
{
    COutPacket packet(0x61, 0);
    packet.vfunc_o10_1(4);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC190, CGuildManager, FUN_1413bc190, 75, 0x5F2CD8B4);

// @0x1413bc1f0
void CGuildManager::FUN_1413bc1f0(__int64 guildId, CStringW guildName)
{
    m_targetGuildId = guildId;
    m_targetGuildName = guildName;
}
MS2_REPLACE_METHOD(0x1413BC1F0, CGuildManager, FUN_1413bc1f0, 87, 0xF179820B);

// @0x1413bc250
void CGuildManager::FUN_1413bc250(Unk_GuildTarget* target)
{
    __int64 guildId = target->vfunc_4();
    CStringW guildName = target->vfunc_8();
    m_targetGuildId = guildId;
    m_targetGuildName = guildName;
    FUN_140d73aa0(FUN_14028de60(0x3c8), 0, 0, CStringW(L""));
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196cf80();
}
MS2_REPLACE_METHOD(0x1413BC250, CGuildManager, FUN_1413bc250, 314, 0xDB1C9312);

// @0x1413bc390
int CGuildManager::FUN_1413bc390()
{
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
            MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
            if ((member.get() ? true : false) && member->f158 == 0)
                count++;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x1413BC390, CGuildManager, FUN_1413bc390, 263, 0xCC512A9E);

// @0x1413bc4a0
void CGuildManager::FUN_1413bc4a0(__int64 guildId)
{
    if (m_joinRequestsForChar.GetCount() >= 10) {
        FUN_1413c66f0(0x52, 0x25, 0);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x52);
    packet.vfunc_o10_4(guildId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC4A0, CGuildManager, FUN_1413bc4a0, 146, 0x3573EDB9);

// @0x1413bc540
void CGuildManager::FUN_1413bc540(__int64 guildId)
{
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x53);
    packet.vfunc_o10_4(guildId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC540, CGuildManager, FUN_1413bc540, 95, 0x24398D36);

// @0x1413bc5b0
void CGuildManager::FUN_1413bc5b0(__int64 characterId, int accept)
{
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x54);
    packet.vfunc_o10_4(characterId);
    packet.vfunc_o10_1((unsigned char)accept);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC5B0, CGuildManager, FUN_1413bc5b0, 118, 0x2ED3EDDE);

// @0x1413bc630
void CGuildManager::FUN_1413bc630()
{
    if (!FUN_1413b6160())
        return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x55);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC630, CGuildManager, FUN_1413bc630, 91, 0xF18B1323);

// @0x1413bc6a0
void CGuildManager::FUN_1413bc6a0()
{
    if (FUN_1413b6160())
        return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x56);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC6A0, CGuildManager, FUN_1413bc6a0, 91, 0xD33A197F);

// @0x1413bc710
void CGuildManager::FUN_1413bc710(bool anyFocus)
{
    if (FUN_1413b6160())
        return;
    int focus = m_468;
    if (focus == 0) {
        if (!anyFocus) {
            FUN_140d73aa0(FUN_14028de60(0x3c9), 0, 0, CStringW(L""));
            return;
        }
        focus = 0x7fffffff;
    }
    CGuildJoinRequestSchCond cond;
    cond.f18 = focus;
    cond.f1c = 1;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x57);
    cond.FUN_1404c84e0(&packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC710, CGuildManager, FUN_1413bc710, 321, 0xF2C69BB4);

// @0x1413bc860
bool CGuildManager::FUN_1413bc860(CStringW name)
{
    if (FUN_1413b6160())
        return false;
    if (name.GetLength() < 2) {
        {
            CStringW key(L"s_guild_err_too_short_to_search");
            FUN_1412751f0(FUN_14028b8e0(key), 1, 1);
        }
        return false;
    }
    if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
        CStringW message;
        if (banWord->FUN_140225720(name, message) != 0) {
            FUN_1412751f0(message, 1, 1);
            return false;
        }
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x58);
    packet.vfunc_o10_8(name);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413BC860, CGuildManager, FUN_1413bc860, 516, 0x09853FD9);

// @0x1413bca70
int CGuildManager::FUN_1413bca70(std::map<unsigned __int64, PCBase*>& out)
{
    if (FUN_1413b6160()) {
        if (Unk_LockGuard guard = lock) {} else {
            for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
                MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
                if (member.get() != 0) {
                    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd1530(member->data.f08);
                    if (pc != 0)
                        out[reinterpret_cast<const unsigned __int64&>(member->data.f08)] = pc;   // the key binds the member directly (unsigned map key)
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1413BCA70, CGuildManager, FUN_1413bca70, 315, 0x9513FE17);

// @0x1413bcbc0
int CGuildManager::FUN_1413bcbc0(std::map<unsigned __int64, PCBase*>& out)
{
    if (FUN_1413b6160()) {
        if (Unk_LockGuard guard = lock) {} else {
            for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
                MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
                if (member.get() != 0) {
                    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd1530(member->data.f08);
                    if (pc != 0 && FUN_1409613d0(pc) == 0)
                        out[reinterpret_cast<const unsigned __int64&>(member->data.f08)] = pc;   // the key binds the member directly (unsigned map key)
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1413BCBC0, CGuildManager, FUN_1413bcbc0, 330, 0x3572C05E);

// @0x1413bcd10
void CGuildManager::FUN_1413bcd10()
{
    if (!FUN_1413b6160())
        return;
    if (DAT_143ad9140 != DAT_143ab2828) {
        CStringW notice = FUN_1404cd0b0();
        if (!notice.IsEmpty())
            FUN_1412751b0(FUN_1405c2690(CStringW(L"s_guild_notify_notify_message"), FUN_1404cd0b0()), 0xd);
        DAT_143ad9140 = DAT_143ab2828;
    }
}
MS2_REPLACE_METHOD(0x1413BCD10, CGuildManager, FUN_1413bcd10, 291, 0xD528D35D);

// @0x1413bce40
void CGuildManager::FUN_1413bce40(int skillId, unsigned short skillLevel)
{
    if (!FUN_1413b6160())
        return;
    std::pair<int, unsigned short> key(skillId, skillLevel);
    if (m_470.empty())
        return;
    if (m_470.find(key) == m_470.end())
        return;
    m_470.erase(key);
    FUN_1412751b0(FUN_1405c2690(CStringW(L"s_guild_skill_use_skill"), FUN_1401a9d70()->FUN_141812290(skillId, skillLevel, CString("name"))), 0xd);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196f830();
}
MS2_REPLACE_METHOD(0x1413BCE40, CGuildManager, FUN_1413bce40, 521, 0x528E31C1);

// @0x1413bd2e0
void CGuildManager::FUN_1413bd2e0()
{
    if (f354 != 0)
        return;
    if (f350 != 0) {
        FUN_140d73ff0(CStringW(L"s_guild_vsGame_another_game_exist"));
        return;
    }
    if (FUN_1404d0600(FUN_1413c7c20(), 0x400) == 0) {
        FUN_141275260(0x415, 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x73);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BD2E0, CGuildManager, FUN_1413bd2e0, 261, 0x8D07E0A5);

// @0x1413bd3f0
void CGuildManager::FUN_1413bd3f0()
{
    if (f354 == 0)
        return;
    if (FUN_1404d0600(FUN_1413c7c20(), 0x400) == 0) {
        FUN_141275260(0x415, 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x74);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BD3F0, CGuildManager, FUN_1413bd3f0, 196, 0x79AB3420);

// @0x1413bd4c0
void CGuildManager::FUN_1413bd4c0()
{
    if (!FUN_1413b6160())
        return;
    if (FUN_1401c0d90()->FUN_14047eca0()) {
        CStringW key(L"s_guild_vsGame_can_regist");
        FUN_1412751f0(FUN_14028b8e0(key), 4, 1);
    }
}
MS2_REPLACE_METHOD(0x1413BD4C0, CGuildManager, FUN_1413bd4c0, 153, 0x031DD505);

// @0x1413bd560
int CGuildManager::FUN_1413bd560()
{
    int count = 0;
    if (FUN_1413b8460())
        count++;
    count += m_joinRequestsForGuild.GetCount();
    return count;
}
MS2_REPLACE_METHOD(0x1413BD560, CGuildManager, FUN_1413bd560, 87, 0xC309A36F);

// @0x1413bd5c0
void CGuildManager::FUN_1413bd5c0(NotifyObject* notify)
{
    if (!FUN_1413b6160())
        return;
    if (FUN_1404d0600(FUN_1413c7c20(), 2))
        FUN_1413bc630();
}
MS2_REPLACE_METHOD(0x1413BD5C0, CGuildManager, FUN_1413bd5c0, 107, 0xE57A6F3B);

// @0x1413bd640
void CGuildManager::FUN_1413bd640(bool show)
{
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196e230(show);
}
MS2_REPLACE_METHOD(0x1413BD640, CGuildManager, FUN_1413bd640, 56, 0xE6D04E64);

// @0x1413bd050
int CGuildManager::FUN_1413bd050(int skillId, int skillLevel)
{
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skillData = FUN_1404f4530()->FUN_1404d74e0(skillId, skillLevel);
    if (skillData == 0) return 0;
    __int64 cost = FUN_1404d2510(skillId, skillLevel);
    int discount = skillData->FUN_1404d4e80() ? 0 : FUN_140302b00()->FUN_1403eead0()->FUN_140423450();
    cost -= cost * discount / FUN_140302b00()->FUN_1413cdf60();
    return (int)cost;
}
MS2_REPLACE_METHOD(0x1413BD050, CGuildManager, FUN_1413bd050, 321, 0xACB87D95);

// @0x1413bd1a0
int CGuildManager::FUN_1413bd1a0(int skillId, int skillLevel)
{
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skillData = FUN_1404f4530()->FUN_1404d74e0(skillId, skillLevel);
    if (skillData == 0) return 0x7fffffff;
    if (!skillData->FUN_1404d4e40()) return 0x7fffffff;
    __int64 duration = skillData->f28;
    int rate = FUN_140302b00()->FUN_1403eeab0()->FUN_140423560();
    duration -= duration * rate / FUN_140302b00()->FUN_1413cdf60();
    return (int)duration;
}
MS2_REPLACE_METHOD(0x1413BD1A0, CGuildManager, FUN_1413bd1a0, 304, 0x760524CF);

// @0x1413bd680
void CGuildManager::FUN_1413bd680(CInPacket& packet)
{
    if (FUN_1413b6160() == 1)
        FUN_1413b5f90();
    FUN_1404cdda0(packet);
    DAT_143aaef18 = FUN_1404d3180()->id;
    m_joinRequestsForGuild.RemoveAll();
    m_joinRequestsForChar.RemoveAll();
    if (Unk_LockGuard guard = lock) {} else {
        for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
            MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
            if (member.get() != 0)
                FUN_1409f7c90()->FUN_14161cd60(member->data.f08);
        }
    }
    if (FUN_1413b6160() && m_noticeAttendance) {
        if (FUN_1401c0d90()->FUN_14047e880()) {
            FUN_1412751b0(FUN_14028de60(0x3c3), 0xd);
            m_noticeAttendance = false;
        }
    }
    m_nextRefreshTime = FUN_140869440();
}
MS2_REPLACE_METHOD(0x1413BD680, CGuildManager, FUN_1413bd680, 535, 0x24AB49D2);

// @0x1413bd8a0
void CGuildManager::FUN_1413bd8a0(CInPacket& packet)
{
    int result = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (result != 0) {
        FUN_1413c66f0(1, result, 0);
        return;
    }
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    FUN_141276180(s_strPcGuildMake, "");
    FUN_140d73aa0(FUN_14052bd00(0x389, guildName), 0, 0, CStringW(L""));
    FUN_1403ed2b0()->FUN_141adc5d0(0x4e4f);
}
MS2_REPLACE_METHOD(0x1413BD8A0, CGuildManager, FUN_1413bd8a0, 344, 0x58CF0D27);

// @0x1413bda00
void CGuildManager::FUN_1413bda00(CInPacket& packet)
{
    int result = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (result != 0) {
        FUN_1413c66f0(2, result, 0);
        return;
    }
    FUN_1413b5f90();
    FUN_140d73aa0(FUN_14028de60(0x38a), 0, 0, CStringW(L""));
    FUN_1403ed2b0()->FUN_141adc5d0(0x4e4f);
}
MS2_REPLACE_METHOD(0x1413BDA00, CGuildManager, FUN_1413bda00, 234, 0x5056CD05);

// @0x1413bdaf0
void CGuildManager::FUN_1413bdaf0(CInPacket& packet)
{
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    FUN_140d73aa0(FUN_14052bd00(0x38b, guildName), 0, 0, CStringW(L""));
}
MS2_REPLACE_METHOD(0x1413BDAF0, CGuildManager, FUN_1413bdaf0, 184, 0x896C70E0);

// @0x1413bdbb0
void CGuildManager::FUN_1413bdbb0(CInPacket& packet)
{
    if (FUN_1413b6160() == 1)
        return;
    m_invite.AssignRaw(new CGuildInviteInfo());
    m_invite->FUN_1404c9230(packet);
    if (!FUN_141b70f50(m_invite->f38, FUN_1413c7c20())) {
        m_invite = 0;
        return;
    }
    Unk_GuildPlayer* player = (Unk_GuildPlayer*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (FUN_140ae6540(FUN_1409a8b10())->m_refuseGuildInvite) {
        FUN_1403ed290()->FUN_1413b74f0(0);
        return;
    }
    if (player != 0 && player->FUN_140967420()->FUN_140743550()) {
        FUN_1403ed290()->FUN_1413b74f0(0);
    } else {
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_140632a60(0x38c, m_invite->f30, m_invite->f20), 0, CStringW(s_strGuildInvite));
        if (box.get()) {
            box->FUN_141a01ca0(0x14, 1, FUN_14028de60(0x2b8));
            box->FUN_141a02460(1);
            box->FUN_141a02480(1);
            box->FUN_141a024a0(0);
            FUN_140d73c60(box);
            FUN_141276180(s_strSystemGuildInvitation, "");
        }
    }
}
MS2_REPLACE_METHOD(0x1413BDBB0, CGuildManager, FUN_1413bdbb0, 1121, 0xAEAA9B1C);

// @0x1413be020
void CGuildManager::FUN_1413be020(CInPacket& packet)
{
    CGuildInviteInfo invite;
    invite.FUN_1404c9230(packet);
    int result = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (result == 1) {
        FUN_1412751b0(FUN_14052bd00(0x38f, invite.f20), 0xd);
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e4f);
    } else {
        FUN_1412751b0(FUN_14052bd00(0x390, invite.f20), 0xd);
    }
    FUN_1413b6110();
}
MS2_REPLACE_METHOD(0x1413BE020, CGuildManager, FUN_1413be020, 298, 0x38874559);

// @0x1413be150
void CGuildManager::FUN_1413be150(CInPacket& packet)
{
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int accepted = static_cast<CInputStream&>(packet).vfunc_o8_1();
    unsigned char reason = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (accepted == 1) {
    } else {
        CStringW text(L"");
        switch (reason) {
        case 1: text = FUN_14052bd00(0x392, name); break;
        case 2: text = FUN_14052bd00(0x393, name); break;
        case 3: text = FUN_14052bd00(0x394, name); break;
        }
        FUN_1412751b0(text, 0xd);
    }
}
MS2_REPLACE_METHOD(0x1413BE150, CGuildManager, FUN_1413be150, 503, 0x92EF0721);

// @0x1413be350
void CGuildManager::FUN_1413be350(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW guildName(f40);
    FUN_1413b5f90();
    FUN_1403ed2b0()->FUN_141adc5d0(0x4e4f);
    FUN_1412751b0(FUN_14052bd00(0x395, guildName), 0xd);
}
MS2_REPLACE_METHOD(0x1413BE350, CGuildManager, FUN_1413be350, 170, 0xB4A3CC27);

// @0x1413be400
void CGuildManager::FUN_1413be400(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    static_cast<CInputStream&>(packet).vfunc_o8_8();
}
MS2_REPLACE_METHOD(0x1413BE400, CGuildManager, FUN_1413be400, 85, 0xB2138CA5);

// @0x1413be460
void CGuildManager::FUN_1413be460(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    if (name.IsEmpty())
        FUN_1412751b0(FUN_1409eec40(0x3aa), 0xd);
    else
        FUN_1412751b0(FUN_14052bd00(0x3ab, name), 0xd);
    if (Unk_LockGuard guard = lock) {} else {
        for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
            MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
            if (member.get() != 0)
                FUN_1409f7c90()->FUN_14161cd60(member->data.f08);
        }
    }
    FUN_1404cc900();
    FUN_1403ed2b0()->FUN_141adc5d0(0x4e4f);
}
MS2_REPLACE_METHOD(0x1413BE460, CGuildManager, FUN_1413be460, 522, 0x7C89BF43);

// @0x1413be670
void CGuildManager::FUN_1413be670(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member.get() != 0) {
        FUN_1409f7c90()->FUN_14161cd60(member->data.f08);
        vfunc_1(name);
        if (member->fb0 == 1) {
        } else {
            member->fb0;            // the exe evaluates member-> and discards it (a compiled-out statement)
        }
    }
}
MS2_REPLACE_METHOD(0x1413BE670, CGuildManager, FUN_1413be670, 353, 0x2DEAA79D);

// @0x1413be7e0
void CGuildManager::FUN_1413be7e0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int grade = static_cast<CInputStream&>(packet).vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x1413BE7E0, CGuildManager, FUN_1413be7e0, 136, 0xC9753032);

// @0x1413be870
void CGuildManager::FUN_1413be870(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW oldName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW newName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    bool memberRenamed = false;
    bool requestRenamed = false;
    if (FUN_1404cf9f0(oldName).get() != 0) {
        memberRenamed = true;
        FUN_1404cfc70(oldName, newName);
    } else {
        for (size_t i = 0; i < m_joinRequestsForGuild.GetCount(); i++) {
            MS2Ptr<CGuildJoinRequestForGuild> request = m_joinRequestsForGuild[i];
            if (request.get() != 0) {
                if (FUN_14025cd60(request->f38, oldName)) {
                    request->f38 = newName;
                    requestRenamed = true;
                    break;
                }
            }
        }
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        if (memberRenamed) {
            dialog->FUN_141973df0(oldName);
            dialog->FUN_141973b20(newName);
        }
        if (requestRenamed)
            dialog->FUN_14196da70();
    }
}
MS2_REPLACE_METHOD(0x1413BE870, CGuildManager, FUN_1413be870, 665, 0xD9E44CA6);

// @0x1413beb10
void CGuildManager::FUN_1413beb10(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int value = static_cast<CInputStream&>(packet).vfunc_o8_3();
    FUN_1404cfdb0(name, value);
}
MS2_REPLACE_METHOD(0x1413BEB10, CGuildManager, FUN_1413beb10, 161, 0xF64DC69A);

// @0x1413bebc0
void CGuildManager::FUN_1413bebc0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    FUN_140d73aa0(FUN_14028b8e0(L"s_guild_attend_complete"), 0, 0, CStringW(L""));
    FUN_1412751b0(FUN_14028b8e0(L"s_guild_attend_complete"), 0xd);
}
MS2_REPLACE_METHOD(0x1413BEBC0, CGuildManager, FUN_1413bebc0, 271, 0x92EE0AC3);

// @0x1413bece0
void CGuildManager::FUN_1413bece0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    int donationCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 donationTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(FUN_1413c7c20());
    if (member == 0)
        return;
    member->ff0 = donationCount;
    member->ff8 = donationTime;
    CStringW key(L"s_guild_donate_complete");
    FUN_1412751b0(FUN_14028b8e0(key), 0xd);
}
MS2_REPLACE_METHOD(0x1413BECE0, CGuildManager, FUN_1413bece0, 390, 0x314F4DBE);

// @0x1413bee70
void CGuildManager::FUN_1413bee70(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    static_cast<CInputStream&>(packet).vfunc_o8_8();
}
MS2_REPLACE_METHOD(0x1413BEE70, CGuildManager, FUN_1413bee70, 85, 0x76DEFDC8);

// @0x1413beed0
void CGuildManager::FUN_1413beed0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    int result = static_cast<CInputStream&>(packet).vfunc_o8_1();
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    if (result == 0) {
    } else if (result == 1) {
        FUN_140d73aa0(FUN_1409eec40(0x397), 0, 0, CStringW(L""));
    }
}
MS2_REPLACE_METHOD(0x1413BEED0, CGuildManager, FUN_1413beed0, 270, 0xE0BC5A02);

// @0x1413beff0
void CGuildManager::FUN_1413beff0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    static_cast<CInputStream&>(packet).vfunc_o8_8();
}
MS2_REPLACE_METHOD(0x1413BEFF0, CGuildManager, FUN_1413beff0, 85, 0x22DAF26D);

// @0x1413bf050
void CGuildManager::FUN_1413bf050(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    int capacity = static_cast<CInputStream&>(packet).vfunc_o8_3();
    FUN_1404cd2b0(capacity);
    FUN_140d73aa0(FUN_1408116a0(0x39f, capacity), 0, 0, CStringW(L""));
}
MS2_REPLACE_METHOD(0x1413BF050, CGuildManager, FUN_1413bf050, 216, 0x7E8A5D03);

// MS2-FUNCTIONAL: the grade reference is guilddef_1's POD Unk_GuildRef with an explicit FUN_1404eeaa0 call, so the
// exe's extra EH state for its destructible type is missing.
// @0x1413bf130
void CGuildManager::FUN_1413bf130(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    int index = static_cast<CInputStream&>(packet).vfunc_o8_1();
    CGuildGrade grade;
    grade.FUN_1404c71d0(packet);
    Unk_GuildRef current;
    FUN_1404d0860(&current, index);
    FUN_140d73aa0(FUN_14052bd00(0x398, FUN_1404d0af0(index)), 0, 0, CStringW(L""));
    FUN_1404eeaa0(&current);
}
MS2_REPLACE_METHOD(0x1413BF130, CGuildManager, FUN_1413bf130, 358, 0x5D4FD5ED);

// @0x1413bf2a0
void CGuildManager::FUN_1413bf2a0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    int focus = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int value = static_cast<CInputStream&>(packet).vfunc_o8_3();
    f154 = focus;
    f158 = value;
}
MS2_REPLACE_METHOD(0x1413BF2A0, CGuildManager, FUN_1413bf2a0, 144, 0x08B9DE58);

// @0x1413bf340
void CGuildManager::FUN_1413bf340(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    int skillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int skillLevel = FUN_1404d26f0(skillId);
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skillData = FUN_1404f4530()->FUN_1404d74e0(skillId, skillLevel);
    if (skillData == 0) return;
    FUN_1412751b0(FUN_1405c2690(CStringW(L"s_guild_skill_use_skill"), FUN_1401a9d70()->FUN_141812290(skillData->f34, skillData->f38, CString("name"))), 0xd);
}
MS2_REPLACE_METHOD(0x1413BF340, CGuildManager, FUN_1413bf340, 496, 0x976EC685);

// @0x1413bf540
void CGuildManager::FUN_1413bf540(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    int skillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int skillLevel = FUN_1404d26f0(skillId);
    if (FUN_141adc890(FUN_1403ed2b0(), 0x4e4f)) {
        Unk_PayloadPtr<CGuildXmlData::GuildSkill> skillData = FUN_1404f4530()->FUN_1404d74e0(skillId, skillLevel);
        if (skillData == 0) return;
        m_470.insert(std::make_pair(skillData->f34, skillData->f38));
    }
}
MS2_REPLACE_METHOD(0x1413BF540, CGuildManager, FUN_1413bf540, 318, 0x19340A02);

// @0x1413bf690
void CGuildManager::FUN_1413bf690(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    int exp = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int fund = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (exp > 0 && fund > 0)
        FUN_1412751b0(FUN_1408f71a0(CStringW(L"s_guild_gain_exp_fund"), FUN_140763e10(exp), FUN_140763e10(fund)), 0xd);
    else if (exp > 0)
        FUN_1412751b0(FUN_1405c2690(CStringW(L"s_guild_gain_exp"), FUN_140763e10(exp)), 0xd);
    else if (fund > 0)
        FUN_1412751b0(FUN_1405c2690(CStringW(L"s_guild_gain_fund"), FUN_140763e10(fund)), 0xd);
}
MS2_REPLACE_METHOD(0x1413BF690, CGuildManager, FUN_1413bf690, 772, 0x796401B2);

// @0x1413bf9a0
void CGuildManager::FUN_1413bf9a0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    int eventId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_PayloadPtr<CGuildXmlData::GuildEvent> eventData = FUN_1404f4530()->FUN_1404d7830(eventId);
    if (eventData == 0) return;
    CStringW eventName = FUN_1401a9d70()->FUN_141811980(3, eventData->f1c);
    FUN_1412751b0(FUN_1405c2690(CStringW(L"s_guild_open_event"), eventName), 0xd);
}
MS2_REPLACE_METHOD(0x1413BF9A0, CGuildManager, FUN_1413bf9a0, 328, 0xA408E437);

// MS2-FUNCTIONAL: CGuildInfo::vfunc_0 is declared over guilddef_1's POD Unk_GuildRef, so the by-value member copy is
// built in a named Unk_GuildRef instead of the exe's argument temporary.
// @0x1413bfaf0
void CGuildManager::FUN_1413bfaf0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW inviterName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    bool notify = FUN_14028d780(static_cast<CInputStream&>(packet).vfunc_o8_1());
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member.get() == 0) {
        member.AssignRaw(new CGuildMember());
        member->FUN_1404cb450(&packet);
        Unk_GuildRef copy;
        FUN_1404ec5b0(&copy, member);
        vfunc_0(&copy);
    } else {
        member->FUN_1404cb450(&packet);
    }
    FUN_1409f7c90()->FUN_14161cd60(member->data.f08);
    if (member->fb0 == 3) {
        if (notify)
            FUN_1412751b0(FUN_140632a60(0x3a8, inviterName, name), 0xd);
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
            dialog->FUN_14196b620();
            dialog->FUN_141973b20(member->data.FUN_1404ca890());
            dialog->FUN_14196e590();
        }
    } else {
        member->fb0;                // the exe evaluates member-> and discards it (a compiled-out statement)
    }
}
MS2_REPLACE_METHOD(0x1413BFAF0, CGuildManager, FUN_1413bfaf0, 858, 0xF3684F51);

// @0x1413bfe50
void CGuildManager::FUN_1413bfe50(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member.get() != 0) {
        FUN_1409f7c90()->FUN_14161cd60(member->data.f08);
        vfunc_1(name);
        FUN_1412751b0(FUN_14052bd00(0x3a6, name), 0xd);
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        dialog->FUN_14196b620();
        dialog->FUN_141973df0(name);
        dialog->FUN_14196e590();
    }
}
MS2_REPLACE_METHOD(0x1413BFE50, CGuildManager, FUN_1413bfe50, 460, 0x9807E2C0);

// @0x1413c0030
void CGuildManager::FUN_1413c0030(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW expellerName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member.get() != 0) {
        FUN_1409f7c90()->FUN_14161cd60(member->data.f08);
        vfunc_1(name);
        FUN_1412751b0(FUN_140632a60(0x3a9, expellerName, name), 0xd);
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        dialog->FUN_14196b620();
        dialog->FUN_141973df0(name);
        dialog->FUN_14196e590();
    }
}
MS2_REPLACE_METHOD(0x1413C0030, CGuildManager, FUN_1413c0030, 535, 0x68205272);

// @0x1413c0250
void CGuildManager::FUN_1413c0250(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member.get() != 0) {
        FUN_1409f7c90()->FUN_14161cd60(member->data.f08);
        vfunc_1(name);
        FUN_1412751b0(FUN_14052bd00(0x3a6, name), 0xd);
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        dialog->FUN_14196b620();
        dialog->FUN_141973df0(name);
        dialog->FUN_14196e590();
    }
}
MS2_REPLACE_METHOD(0x1413C0250, CGuildManager, FUN_1413c0250, 460, 0x1281A95C);

// @0x1413c0430
void CGuildManager::FUN_1413c0430(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member == 0)
        return;
    if (Unk_LockGuard guard = lock) {} else {
        member->f158 = 0;
    }
    void* buddy = FUN_14097a780()->FUN_140ae4950(name).FUN_14097a170();
    if (buddy == 0)   // buddies get their own login notice
        FUN_1412751b0(FUN_14052bd00(0x3ac, name), 0xd);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141973b20(name);
}
MS2_REPLACE_METHOD(0x1413C0430, CGuildManager, FUN_1413c0430, 500, 0x6A993622);

// @0x1413c0630
void CGuildManager::FUN_1413c0630(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    __int64 loginTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member == 0)
        return;
    if (Unk_LockGuard guard = lock) {} else {
        member->f158 = 1;
        member->fd0 = loginTime;
    }
    void* buddy = FUN_14097a780()->FUN_140ae4950(name).FUN_14097a170();
    if (buddy == 0)   // buddies get their own login notice
        FUN_1412751b0(FUN_14052bd00(0x3ad, name), 0xd);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141973b20(name);
}
MS2_REPLACE_METHOD(0x1413C0630, CGuildManager, FUN_1413c0630, 579, 0x092A4272);

// MS2-FUNCTIONAL: the grade reference is guilddef_1's POD Unk_GuildRef with an explicit FUN_1404eeaa0 call, so the
// exe's EH state for its destructible type is missing.
// @0x1413c0880
void CGuildManager::FUN_1413c0880(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW changerName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int gradeIndex = static_cast<CInputStream&>(packet).vfunc_o8_1();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member.get() != 0) {
        member->fb4 = gradeIndex;
        Unk_GuildRef grade;
        FUN_1404d0860(&grade, gradeIndex);
        if (FUN_1404f0aa0(&grade) != 0) {
            bool isMe = FUN_141b70f50(name, FUN_1413c7c20());
            if (isMe) {
                FUN_1412751b0(FUN_14052bd00(0x3af, FUN_1404f0b70(&grade)->name), 0xd);
                if (FUN_1404d0600(FUN_1413c7c20(), 2) && m_joinRequestsForGuild.IsEmpty())
                    FUN_1413bc630();
            } else {
                FUN_1412751b0(FUN_140632a60(0x3ae, name, FUN_1404f0b70(&grade)->name), 0xd);
            }
        }
        FUN_1404eeaa0(&grade);
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141973b20(name);
}
MS2_REPLACE_METHOD(0x1413C0880, CGuildManager, FUN_1413c0880, 852, 0xBCCB99C3);

// @0x1413c0be0
void CGuildManager::FUN_1413c0be0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW message = static_cast<CInputStream&>(packet).vfunc_o8_8();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member.get() != 0)
        member->fb8 = message;
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141973b20(name);
}
MS2_REPLACE_METHOD(0x1413C0BE0, CGuildManager, FUN_1413c0be0, 328, 0x21E0AE85);

// @0x1413c0d30
void CGuildManager::FUN_1413c0d30(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    __int64 contribution = static_cast<CInputStream&>(packet).vfunc_o8_4();
    FUN_1404cfe60(name, contribution);
    if (FUN_1413c7c20() == name) {
        if (Unk_GuildDialog4e28* dialog = FUN_140938b90(0x4e28))
            dialog->FUN_1419381c0();
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
            dialog->FUN_141973a70();
    }
}
MS2_REPLACE_METHOD(0x1413C0D30, CGuildManager, FUN_1413c0d30, 311, 0xDE9C2BFB);

// @0x1413c0e70
void CGuildManager::FUN_1413c0e70(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int raidId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int count = static_cast<CInputStream&>(packet).vfunc_o8_3();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member == 0)
        return;
    member->raid.FUN_1404cad50(raidId, count, false);
}
MS2_REPLACE_METHOD(0x1413C0E70, CGuildManager, FUN_1413c0e70, 354, 0xDB86286F);

// The guild master handed over (old master, new master).
// @0x1413c0fe0
void CGuildManager::FUN_1413c0fe0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW oldName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW newName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    MS2Ptr<CGuildMember> oldMaster = FUN_1404cf9f0(oldName);
    if (oldMaster == 0)
        return;
    MS2Ptr<CGuildMember> newMaster = FUN_1404cf9f0(newName);
    if (newMaster == 0)
        return;
    oldMaster->fb4 = 1;
    newMaster->fb4 = 0;
    FUN_1404cd310(newMaster->data.f00, newMaster->data.f08, newMaster->data.FUN_1404ca890(), 1);
    FUN_1404ef970(&f310, newMaster);
    bool isMe = FUN_141b70f50(newName, FUN_1413c7c20());
    if (isMe)
        FUN_1412751b0(FUN_1409eec40(0x3b1), 0xd);
    else
        FUN_1412751b0(FUN_14052bd00(0x3b0, newName), 0xd);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        dialog->FUN_14196b620();
        dialog->FUN_141973b20(newName);
        dialog->FUN_141973b20(oldName);
    }
}
MS2_REPLACE_METHOD(0x1413C0FE0, CGuildManager, FUN_1413c0fe0, 1002, 0x68832B06);

// @0x1413c13d0
void CGuildManager::FUN_1413c13d0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int kind = static_cast<CInputStream&>(packet).vfunc_o8_1();
    CStringW text = static_cast<CInputStream&>(packet).vfunc_o8_8();
    if (kind == 0) {
        FUN_1404cd030(text);
    } else if (kind == 1) {
        FUN_1404cd140(text);
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
            dialog->FUN_14196b620();
        FUN_1412751b0(FUN_14052bd00(0x3b2, name), 0xd);
    }
}
MS2_REPLACE_METHOD(0x1413C13D0, CGuildManager, FUN_1413c13d0, 470, 0x52E9F290);

// @0x1413c15b0
void CGuildManager::FUN_1413c15b0(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW changer = StringIdInterface(packet).FUN_141024e60();
    CString code = static_cast<CInputStream&>(packet).vfunc_o8_6();
    FUN_1404cce40(code);
    FUN_1412751b0(FUN_14052bd00(0x3b3, changer), 0xd);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141974120(code);
}
MS2_REPLACE_METHOD(0x1413C15B0, CGuildManager, FUN_1413c15b0, 350, 0xE25018AD);

// The guild was renamed.
// @0x1413c1720
void CGuildManager::FUN_1413c1720(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    FUN_1404ccd40(guildName);
    FUN_1412751b0(FUN_14052bd00(0x3b4, guildName), 0xd);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141974190(guildName);
    PC* pc = (PC*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc != 0)
        pc->vfunc_129(guildName);
}
MS2_REPLACE_METHOD(0x1413C1720, CGuildManager, FUN_1413c1720, 271, 0xC3A0D9CC);

// @0x1413c1840
void CGuildManager::FUN_1413c1840(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int value = static_cast<CInputStream&>(packet).vfunc_o8_3();
    FUN_1404cd2b0(value);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        dialog->FUN_14196b620();
        dialog->FUN_14196e2c0();
    }
    FUN_1412751b0(FUN_1408116a0(0x3b5, value), 0xd);
}
MS2_REPLACE_METHOD(0x1413C1840, CGuildManager, FUN_1413c1840, 281, 0xD98EC819);

// MS2-FUNCTIONAL: the grade reference is guilddef_1's POD Unk_GuildRef with an explicit FUN_1404eeaa0 call, so the
// exe's EH state for its destructible type is missing.
// @0x1413c1960
void CGuildManager::FUN_1413c1960(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW changer = StringIdInterface(packet).FUN_141024e60();
    int index = static_cast<CInputStream&>(packet).vfunc_o8_1();
    CGuildGrade grade;
    grade.FUN_1404c71d0(packet);
    Unk_GuildRef current;
    FUN_1404d0860(&current, index);
    if (FUN_1404effe0(&current, 0)) {
        FUN_1404eeaa0(&current);
        return;
    }
    FUN_1404f0b70(&current)->FUN_1404c70f0(grade.grade, grade.name, grade.permissions);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141973fd0(index);
    MS2Ptr<CGuildMember> me = FUN_1404cf9f0(FUN_1413c7c20());
    if (me.get() != 0 && me->fb4 == index)
        FUN_1412751b0(FUN_14052bd00(0x3a7, FUN_1413c7c20()), 0xd);
    FUN_1404eeaa0(&current);
}
MS2_REPLACE_METHOD(0x1413C1960, CGuildManager, FUN_1413c1960, 741, 0xB97EA301);

// @0x1413c1c50
void CGuildManager::FUN_1413c1c50(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int focus = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int value = static_cast<CInputStream&>(packet).vfunc_o8_3();
    FUN_1404d17e0(focus, value);
}
MS2_REPLACE_METHOD(0x1413C1C50, CGuildManager, FUN_1413c1c50, 204, 0x8C4BE824);

// A member's character data changed.
// MS2-FUNCTIONAL: the exe frame carries a /GS cookie (its Unk_GuildTriple is an int[3] array in the original, see the
// FUN_140267ef0 loop); the shared header models it as three ints, so no cookie is emitted here.
// @0x1413c1d30
void CGuildManager::FUN_1413c1d30(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    Unk_GuildMemberData data;
    data.FUN_1404c9670(&packet);
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member == 0)
        return;
    bool changed = FUN_140267ef0(&member->data.f2c, &data.f2c) == 0;
    member->data.FUN_1404ca1a0(data);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        if (changed)
            dialog->FUN_14196b620();
        dialog->FUN_141973b20(name);
    }
}
MS2_REPLACE_METHOD(0x1413C1D30, CGuildManager, FUN_1413c1d30, 457, 0x300F88FD);

// @0x1413c1f00
void CGuildManager::FUN_1413c1f00(CInPacket& packet)
{
    if (!FUN_1413b6160())
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member == 0)
        return;
    member->data.FUN_1404c95f0(packet);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141973b20(name);
}
MS2_REPLACE_METHOD(0x1413C1F00, CGuildManager, FUN_1413c1f00, 292, 0x1D49DD04);

// A guild member reached an achievement grade.
// @0x1413c2030
void CGuildManager::FUN_1413c2030(CInPacket& packet)
{
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int achieveId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int grade = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int kind = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    Unk_GuildAchieveRowPtr row = FUN_14015d9e0(achieveId);
    if (row.FUN_140159920())
        return;
    if (row.FUN_140159a80()->m_category == 8)
        return;
    CMsTime now = FUN_1406c47a0(FUN_140869440());
    CStringW suffix = FUN_14028de60(0x780);
    CStringW date = FUN_14083bab0(now, CStringW(L"/"));
    CStringW text = FUN_140656190(L"{0} {1}", name, suffix);
    CStringW detail = FUN_140d2d8a0(achieveId, grade, text, date);
    CStringW message;
    if (kind == 2)
        message = FUN_140632a60(0x3b6, name, detail);
    else
        message = FUN_140632a60(0x3b7, name, detail);
    FUN_1412751b0(message, 0xd);
}
MS2_REPLACE_METHOD(0x1413C2030, CGuildManager, FUN_1413c2030, 915, 0x7E9C85B6);

// @0x1413c23d0
void CGuildManager::FUN_1413c23d0(CInPacket& packet)
{
    Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f);
    if (dialog == 0)
        return;
    int count = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (int i = 0; i < count; i++) {
        CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
        int value0 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int value1 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
        if (member.get() != 0) {
            member->fe0 = value0;
            member->fe4 = value1;
            dialog->FUN_141973b20(name);
        }
    }
}
MS2_REPLACE_METHOD(0x1413C23D0, CGuildManager, FUN_1413c23d0, 440, 0x7F49B151);

// A member gained guild contribution.
// @0x1413c2590
void CGuildManager::FUN_1413c2590(CInPacket& packet)
{
    Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f);
    if (dialog == 0)
        return;
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int gained = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int weekly = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int total = static_cast<CInputStream&>(packet).vfunc_o8_3();
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(name);
    if (member.get() != 0) {
        member->fe8 = weekly;
        member->fec = total;
        dialog->FUN_141973b20(name);
    }
    if (gained > 0 && FUN_141b70f50(name, FUN_1413c7c20()) == true)
        FUN_1412751b0(FUN_14062b4f0(CStringW(L"s_guild_gain_contribution"), &gained), 0xd);
}
MS2_REPLACE_METHOD(0x1413C2590, CGuildManager, FUN_1413c2590, 702, 0xD91F084E);

// @0x1413c2860
void CGuildManager::FUN_1413c2860(CInPacket& packet)
{
    int level = static_cast<CInputStream&>(packet).vfunc_o8_1();
    FUN_1404d1140(level);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196c1d0();
}
MS2_REPLACE_METHOD(0x1413C2860, CGuildManager, FUN_1413c2860, 114, 0x5145F95F);

// The guild battle matching finished.
// @0x1413c28e0
void CGuildManager::FUN_1413c28e0(CInPacket& packet)
{
    bool matched = FUN_14028d780(static_cast<CInputStream&>(packet).vfunc_o8_1());
    CStringW message = FUN_14028de60(0x3bf);
    if (matched) {
        FUN_141276180(s_strGuildBattleMatchingSuccess, "");
        FUN_141276180(s_strGuildBattleMatchingNotice, "");
    } else {
        message = FUN_14028de60(0x3c0);
        FUN_141276180(s_strGuildBattleMatchingFail, "");
    }
    if (matched && FUN_140c9b8b0(FUN_1409a8b10())->m_promptArenaJoin) {
        if (m_targetGuildId == 0) {
            if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
                dialog->FUN_141974930();
        } else {
            CStringW text = FUN_14028de60(0x3c1);
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, text, 0, CStringW(s_strGuildArenaJoin));
            if (box.get()) {
                box->FUN_141a01ca0(0x1e, 1, FUN_14028de60(0x2b8));
                box->FUN_141a02460(1);
                box->FUN_141a02480(1);
                box->FUN_141a024a0(0);
                FUN_140d73c60(box);
            }
        }
    }
    FUN_1412751f0(message, 1, 1);
}
MS2_REPLACE_METHOD(0x1413C28E0, CGuildManager, FUN_1413c28e0, 879, 0xB537B89A);

// The guild battle season score changed.
// @0x1413c2c60
void CGuildManager::FUN_1413c2c60(CInPacket& packet)
{
    int score = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int wins = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int losses = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned oldScore = FUN_1404d0ff0();
    FUN_1404d1060(score);
    FUN_1404d12f0(wins);
    FUN_1404d13d0(losses);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196c1d0();
    Unk_GuildSeason* season = FUN_1404d3180();
    unsigned newScore = FUN_1404d0ff0();
    int oldTier = season->FUN_1404c6110(oldScore);
    int newTier = season->FUN_1404c6110(newScore);
    if (oldTier != newTier) {
        CStringW tierName = FUN_1401a9d70()->FUN_141811980(0x2d, newTier);
        CStringW message = FUN_14052bd00(0x3b8, tierName);
        FUN_1412751b0(message, 0xd);
    }
}
MS2_REPLACE_METHOD(0x1413C2C60, CGuildManager, FUN_1413c2c60, 480, 0x34BB3C11);

// A guild battle ended (won / lost against the named guild).
// @0x1413c2e50
void CGuildManager::FUN_1413c2e50(CInPacket& packet)
{
    bool won = FUN_14028d780(static_cast<CInputStream&>(packet).vfunc_o8_1());
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW message;
    if (guildName.GetLength() < 1)
        guildName = L"Unknown";
    if (won)
        message = FUN_14052bd00(0x3bb, guildName);
    else
        message = FUN_14052bd00(0x3bc, guildName);
    FUN_1412751b0(message, 0xd);
}
MS2_REPLACE_METHOD(0x1413C2E50, CGuildManager, FUN_1413c2e50, 354, 0x6F67FBA0);

// @0x1413c2fc0
void CGuildManager::FUN_1413c2fc0(CInPacket& packet)
{
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW message = FUN_14052bd00(0x3b9, guildName);
    FUN_1412751b0(message, 0xd);
    FUN_141276180(s_strGuildBattleApply, "");
}
MS2_REPLACE_METHOD(0x1413C2FC0, CGuildManager, FUN_1413c2fc0, 176, 0x2422FBEB);

// @0x1413c3080
void CGuildManager::FUN_1413c3080(CInPacket& packet)
{
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW message = FUN_14052bd00(0x3ba, guildName);
    FUN_1412751b0(message, 0xd);
}
MS2_REPLACE_METHOD(0x1413C3080, CGuildManager, FUN_1413c3080, 128, 0x1EA1580C);

// @0x1413c3110
void CGuildManager::FUN_1413c3110(CInPacket& packet)
{
    int value = static_cast<CInputStream&>(packet).vfunc_o8_3();
    FUN_1404d3600(value);
}
MS2_REPLACE_METHOD(0x1413C3110, CGuildManager, FUN_1413c3110, 78, 0x409DBFAD);

// A member used a guild skill.
// @0x1413c3170
void CGuildManager::FUN_1413c3170(CInPacket& packet)
{
    CStringW user = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CGuildSkill skill;
    skill.FUN_1404cba60(packet);
    MS2Ptr<CGuildSkill> current = FUN_1404d2640(skill.f18);
    if (current == 0)
        return;
    current->FUN_1404cb9a0(&skill);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196e590();
    if (!user.IsEmpty()) {
        Unk_PayloadPtr<CGuildXmlData::GuildSkill> skillData = FUN_1404f4530()->FUN_1404d74e0(skill.f18, skill.f1c);
        if (skillData == 0)
            return;
        CStringW skillName = FUN_1401a9d70()->FUN_141812290(skillData->f34, skillData->f38, CString("name"));
        FUN_1412751b0(FUN_1408f71a0(CStringW(L"s_guild_notify_use_skill_user"), user, skillName), 0xd);
    }
}
MS2_REPLACE_METHOD(0x1413C3170, CGuildManager, FUN_1413c3170, 735, 0xEF9B97BD);

// A guild skill was upgraded.
// @0x1413c3460
void CGuildManager::FUN_1413c3460(CInPacket& packet)
{
    CStringW user = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CGuildSkill skill;
    skill.FUN_1404cba60(packet);
    MS2Ptr<CGuildSkill> current = FUN_1404d2640(skill.f18);
    if (current == 0)
        return;
    current->FUN_1404cb9a0(&skill);
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skillData = FUN_1404f4530()->FUN_1404d74e0(skill.f18, skill.f1c);
    if (skillData == 0)
        return;
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        if (skillData->FUN_1404d4e60())
            dialog->FUN_14196e590();
        else if (skillData->FUN_1404d4e40())
            dialog->FUN_14196f830();
    }
    CStringW skillName = FUN_1401a9d70()->FUN_141812290(skillData->f34, skillData->f38, CString("name"));
    FUN_1412751b0(FUN_141081c60(CStringW(L"s_guild_notify_upgrade_skill"), user, skillName, &skill.f1c), 0xd);
}
MS2_REPLACE_METHOD(0x1413C3460, CGuildManager, FUN_1413c3460, 788, 0x690B1B5B);

// A member opened a guild event.
// @0x1413c3780
void CGuildManager::FUN_1413c3780(CInPacket& packet)
{
    CStringW user = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CGuildCustomEvent customEvent;
    customEvent.FUN_1404cbe70(packet);
    MS2Ptr<CGuildCustomEvent> current = FUN_1404d27b0(customEvent.f18);
    if (current == 0)
        return;
    current->FUN_1404cbde0(&customEvent);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141970900();
    Unk_PayloadPtr<CGuildXmlData::GuildEvent> eventData = FUN_1404f4530()->FUN_1404d7830(customEvent.f18);
    if (eventData == 0)
        return;
    CStringW eventName = FUN_1401a9d70()->FUN_141811980(3, eventData->f1c);
    FUN_1412751b0(FUN_1408f71a0(CStringW(L"s_guild_notify_open_event_user"), user, eventName), 0xd);
}
MS2_REPLACE_METHOD(0x1413C3780, CGuildManager, FUN_1413c3780, 593, 0xF683B753);

// The guild house was upgraded.
// @0x1413c39e0
void CGuildManager::FUN_1413c39e0(CInPacket& packet)
{
    CStringW user = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int level = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int theme = static_cast<CInputStream&>(packet).vfunc_o8_3();
    FUN_1404d1f40(level);
    FUN_1404d1fe0(theme);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        dialog->FUN_141971490();
        dialog->FUN_141971ac0();
    }
    if (UIGuildHouseUpgradeDialog* upgrade = Unk_GuildFindDialog<UIGuildHouseUpgradeDialog>(0x4f2e))
        upgrade->FUN_140e39da0();
    Unk_PayloadPtr<CGuildXmlData::GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(level, theme);
    if (house.get() != 0)
        FUN_1412751b0(FUN_140d26d90(CStringW(L"s_guild_notify_house_upgrade"), user, &level,
                                    FUN_1401a9d70()->FUN_141811980(0x36, house->f20)), 0xd);
}
MS2_REPLACE_METHOD(0x1413C39E0, CGuildManager, FUN_1413c39e0, 602, 0x7D39ABAA);

// A member changed the guild poster.
// @0x1413c3c40
void CGuildManager::FUN_1413c3c40(CInPacket& packet)
{
    __int64 characterId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CStringW user = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int posterId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    CStringW text = static_cast<CInputStream&>(packet).vfunc_o8_8();
    vfunc_2(characterId, user, posterId, text);
    if (!user.IsEmpty())
        FUN_1412751b0(FUN_1405c2690(CStringW(L"s_guild_notify_change_poster"), user), 0xd);
    FUN_1413baef0(posterId, 1);
}
MS2_REPLACE_METHOD(0x1413C3C40, CGuildManager, FUN_1413c3c40, 517, 0x91CCC9CF);

// @0x1413c3e50
void CGuildManager::FUN_1413c3e50(CInPacket& packet)
{
    ItemEntity item;
    item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
    FUN_1404d2cc0(&item);
    m_400 = false;
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141972520();
}
MS2_REPLACE_METHOD(0x1413C3E50, CGuildManager, FUN_1413c3e50, 139, 0xF70246D1);

// A guild npc was upgraded.
// MS2-FUNCTIONAL: CGuildInfo::FUN_1404d2860 is declared over guilddef_1's POD Unk_GuildRef, so its by-value
// Unk_PayloadPtr<CGuildNpc> argument is built in a named Unk_GuildRef instead of the exe's argument temporary.
// @0x1413c3ef0
void CGuildManager::FUN_1413c3ef0(CInPacket& packet)
{
    CStringW user = static_cast<CInputStream&>(packet).vfunc_o8_8();
    Unk_PayloadPtr<CGuildNpc> npc(new CGuildNpc());
    npc->FUN_1404cc440(packet);
    Unk_GuildRef copy;
    FUN_1404ec690(&copy, npc);
    FUN_1404d2860(&copy);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141971ac0();
    Unk_PayloadPtr<CGuildXmlData::GuildNpc> npcData = FUN_1404f4530()->FUN_1404d7b40((Unk_GuildNpcKind)npc->f18, npc->f1c);
    if (npcData.get() != 0)
        FUN_1412751b0(FUN_141081c60(CStringW(L"s_guild_notify_upgrade_npc"), user,
                                    FUN_1401a9d70()->FUN_141811980(0x3f, npcData->f30), &npc->f1c), 0xd);
}
MS2_REPLACE_METHOD(0x1413C3EF0, CGuildManager, FUN_1413c3ef0, 686, 0xEDFE702B);

// The weekly contribution was reset.
// @0x1413c41b0
void CGuildManager::FUN_1413c41b0(CInPacket& packet)
{
    ATL::CAtlArray<MS2Ptr<CGuildMember>> members;
    FUN_1404d0420(&members);
    for (unsigned i = 0; i < members.GetCount(); i++) {
        MS2Ptr<CGuildMember> member = members[i];
        if (member == 0)
            continue;
        member->fe8 = 0;
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
            dialog->FUN_141973b20(member->data.FUN_1404ca890());
    }
}
MS2_REPLACE_METHOD(0x1413C41B0, CGuildManager, FUN_1413c41b0, 325, 0x11E90540);

// The guild raid records were reset.
// @0x1413c4300
void CGuildManager::FUN_1413c4300(CInPacket& packet)
{
    ATL::CAtlArray<MS2Ptr<CGuildMember>> members;
    FUN_1404d0420(&members);
    for (unsigned i = 0; i < members.GetCount(); i++) {
        MS2Ptr<CGuildMember> member = members[i];
        if (member == 0)
            continue;
        member->raid.FUN_1404cab20();
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        dialog->FUN_141972fc0();
        dialog->FUN_141973220();
    }
}
MS2_REPLACE_METHOD(0x1413C4300, CGuildManager, FUN_1413c4300, 268, 0x954FD252);

// The guild vs-game ticket was (un)registered.
// @0x1413c4420
void CGuildManager::FUN_1413c4420(CInPacket& packet)
{
    f354 = static_cast<CInputStream&>(packet).vfunc_o8_0();
    bool notify = static_cast<CInputStream&>(packet).vfunc_o8_0();
    if (notify) {
        if (f354)
            FUN_1412751b0(FUN_14028b8e0(L"s_guild_notify_vsGame_register_ticket"), 3);
        else
            FUN_1412751b0(FUN_14028b8e0(L"s_guild_notify_vsGame_unregister_ticket"), 3);
    }
}
MS2_REPLACE_METHOD(0x1413C4420, CGuildManager, FUN_1413c4420, 340, 0x9CD6C29F);

// @0x1413c4580
void CGuildManager::FUN_1413c4580(CInPacket& packet)
{
    f354 = 0;
    FUN_1412752d0(L"s_guild_notify_vsGame_match_canceled", 1);
}
MS2_REPLACE_METHOD(0x1413C4580, CGuildManager, FUN_1413c4580, 86, 0xC7BF073C);

// The guild vs-game opened: ask whether to enter.
// @0x1413c45e0
// MS2-FUNCTIONAL: the exe frame is 0x20 larger with one more EH state around the message-box result (an extra
// pointer copy of the returned box); same calls and arguments.
void CGuildManager::FUN_1413c45e0(CInPacket& packet)
{
    f350 = static_cast<CInputStream&>(packet).vfunc_o8_3();
    f354 = 0;
    if (f350 == 0)
        return;
    MS2Ptr<CMsgBoxData> box = FUN_140d73f20(FUN_14028b8e0(L"s_guild_notify_vsGame_open"), 1);
    if (box.get()) {
        box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &CGuildManager::FUN_1413c7cb0));
        box->FUN_141a01ca0(0x1e, 1, FUN_14028de60(0x2b8));
        box->FUN_141a02460(1);
        box->FUN_141a02480(1);
        box->FUN_141a024a0(0);
        box->FUN_141a024c0();
        FUN_140d73c60(box);
    }
}
MS2_REPLACE_METHOD(0x1413C45E0, CGuildManager, FUN_1413c45e0, 650, 0x5088480F);

// @0x1413c4870
void CGuildManager::FUN_1413c4870(CInPacket& packet)
{
    if (UIPvPGuildTeamResultDialog* dialog = Unk_GuildFindDialog<UIPvPGuildTeamResultDialog>(0x4ec7))
        dialog->FUN_141341220(packet);
}
MS2_REPLACE_METHOD(0x1413C4870, CGuildManager, FUN_1413c4870, 57, 0x281C65DD);

// The guild vs-game reward.
// @0x1413c48b0
void CGuildManager::FUN_1413c48b0(CInPacket& packet)
{
    int kind = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int amount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    switch (kind) {
    case 1:
        FUN_1412751b0(FUN_1405c2690(CStringW(L"s_guild_notify_vsGame_reward_exp"), FUN_140763e10(amount)), 3);
        break;
    case 2:
        FUN_1412751b0(FUN_1405c2690(CStringW(L"s_guild_notify_vsGame_reward_fund"), FUN_140763e10(amount)), 3);
        break;
    }
}
MS2_REPLACE_METHOD(0x1413C48B0, CGuildManager, FUN_1413c48b0, 490, 0x79C88C57);

// @0x1413c4aa0
void CGuildManager::FUN_1413c4aa0(CInPacket& packet)
{
    int oldLevel = FUN_1404f4530()->FUN_1404d7130(f15c);
    f15c = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int newLevel = FUN_1404f4530()->FUN_1404d7130(f15c);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        dialog->FUN_14196e0a0();
        if (oldLevel != newLevel) {
            dialog->FUN_14196e590();
            dialog->FUN_141971ac0();
        }
    }
}
MS2_REPLACE_METHOD(0x1413C4AA0, CGuildManager, FUN_1413c4aa0, 183, 0x6737E8CD);

// @0x1413c4b60
void CGuildManager::FUN_1413c4b60(CInPacket& packet)
{
    f160 = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196e2c0();
}
MS2_REPLACE_METHOD(0x1413C4B60, CGuildManager, FUN_1413c4b60, 97, 0x89C61D47);

// @0x1413c4bd0
void CGuildManager::FUN_1413c4bd0(CInPacket& packet)
{
    f164 = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196e2c0();
}
MS2_REPLACE_METHOD(0x1413C4BD0, CGuildManager, FUN_1413c4bd0, 97, 0x0C093F26);

// Members removed while offline: an "expeled" entry shows a notice with the member's name.
// @0x1413c4c40
void CGuildManager::FUN_1413c4c40(CInPacket& packet)
{
    unsigned count = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (unsigned i = 0; i < count; i++) {
        CStringW unused;
        CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
        CStringW reason = static_cast<CInputStream&>(packet).vfunc_o8_8();
        __int64 time = static_cast<CInputStream&>(packet).vfunc_o8_4();
        if (FUN_1403b3c40(reason, L"expeled"))
            FUN_1412751b0(FUN_14052bd00(0x3ab, name), 0xd);
    }
}
MS2_REPLACE_METHOD(0x1413C4C40, CGuildManager, FUN_1413c4c40, 391, 0x8FF3CB79);

// @0x1413c4dd0
void CGuildManager::FUN_1413c4dd0(CInPacket& packet)
{
    FUN_140d73bc0(0x228, 0, 0, L"");
}
MS2_REPLACE_METHOD(0x1413C4DD0, CGuildManager, FUN_1413c4dd0, 72, 0x3D79C845);

// @0x1413c4e20
void CGuildManager::FUN_1413c4e20(CInPacket& packet)
{
    int kind = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int code = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int arg = static_cast<CInputStream&>(packet).vfunc_o8_3();
    FUN_1413c66f0(kind, code, arg);
}
MS2_REPLACE_METHOD(0x1413C4E20, CGuildManager, FUN_1413c4e20, 163, 0x616EE1A4);

// A guild penalty: notice with the remaining time.
// @0x1413c4ed0
void CGuildManager::FUN_1413c4ed0(CInPacket& packet)
{
    int kind = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 begin = static_cast<CInputStream&>(packet).vfunc_o8_4();
    __int64 end = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW remain = FUN_140a2fcd0(begin, end);
    FUN_141275260(0x421, 1, 1);
    FUN_1412751b0(remain, 0xd);
}
MS2_REPLACE_METHOD(0x1413C4ED0, CGuildManager, FUN_1413c4ed0, 289, 0x0A1CBAAD);

// Guild pvp history entries (keeps the newest 10).
// @0x1413c5000
void CGuildManager::FUN_1413c5000(CInPacket& packet)
{
    int count = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (int i = 0; i < count; i++) {
        int has = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (has == 1) {
            MS2Ptr<CGuildPVPHistoryData> history(new CGuildPVPHistoryData());
            history->FUN_1404c6a30(&packet);
            m_pvpHistory.push_back(history);
            if (m_pvpHistory.size() > 10)
                m_pvpHistory.pop_front();
            m_lastPvpHistoryId = history->fb8;
        }
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141974240();
}
MS2_REPLACE_METHOD(0x1413C5000, CGuildManager, FUN_1413c5000, 428, 0x307F6644);

// Guild pvp season history entries.
// @0x1413c51c0
void CGuildManager::FUN_1413c51c0(CInPacket& packet)
{
    if (!m_pvpSeasonHistory.empty())
        m_pvpSeasonHistory.clear();
    int count = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (int i = 0; i < count; i++) {
        int has = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (has == 1) {
            MS2Ptr<CGuildPVPSeasonHistoryData> history(new CGuildPVPSeasonHistoryData());
            history->FUN_1404d4490(&packet);
            m_pvpSeasonHistory.push_back(history);
        }
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_141974640();
}
MS2_REPLACE_METHOD(0x1413C51C0, CGuildManager, FUN_1413c51c0, 398, 0xC969639A);

// @0x1413c5360
void CGuildManager::FUN_1413c5360(CInPacket& packet)
{
    if (FUN_1413b6160() != 0)
        return;
    unsigned __int64 guildId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    if (guildId > 0) {
        FUN_1412751b0(FUN_14052bd00(0x3ce, guildName), 0xd);
        FUN_1413bc6a0();
    }
}
MS2_REPLACE_METHOD(0x1413C5360, CGuildManager, FUN_1413c5360, 218, 0xD82E497B);

// @0x1413c5440
void CGuildManager::FUN_1413c5440(CInPacket& packet)
{
    if (FUN_1413b6160() != 0)
        return;
    unsigned __int64 guildId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    if (guildId > 0) {
        FUN_1412751b0(FUN_14052bd00(0x3cf, guildName), 0xd);
        FUN_1413bc6a0();
    }
}
MS2_REPLACE_METHOD(0x1413C5440, CGuildManager, FUN_1413c5440, 218, 0xC3304083);

// The answer to a join request this guild's master sent.
// @0x1413c5520
void CGuildManager::FUN_1413c5520(CInPacket& packet)
{
    if (FUN_1413b6160() == 0)
        return;
    unsigned __int64 characterId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int accepted = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (characterId > 0) {
        if (accepted == 1)
            FUN_1412751b0(FUN_14052bd00(0x3d0, name), 0xd);
        else
            FUN_1412751b0(FUN_14052bd00(0x3d1, name), 0xd);
    }
}
MS2_REPLACE_METHOD(0x1413C5520, CGuildManager, FUN_1413c5520, 354, 0x86489381);

// The join requests sent to this guild.
// @0x1413c5690
void CGuildManager::FUN_1413c5690(CInPacket& packet)
{
    if (FUN_1413b6160() == 0)
        return;
    m_joinRequestsForGuild.RemoveAll();
    int count = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (int i = 0; i < count; i++) {
        int has = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (has != 0) {
            MS2Ptr<CGuildJoinRequestForGuild> request(new CGuildJoinRequestForGuild());
            request->FUN_1404c7940(&packet);
            m_joinRequestsForGuild.Add(request);
        }
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196da70();
    if (Unk_GuildDialog4e28* dialog = FUN_140938b90(0x4e28))
        dialog->FUN_1419381c0();
}
MS2_REPLACE_METHOD(0x1413C5690, CGuildManager, FUN_1413c5690, 424, 0x2F130CD7);

// The join requests this character sent.
// @0x1413c5840
void CGuildManager::FUN_1413c5840(CInPacket& packet)
{
    if (FUN_1413b6160() != 0)
        return;
    m_joinRequestsForChar.RemoveAll();
    int count = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (int i = 0; i < count; i++) {
        int has = static_cast<CInputStream&>(packet).vfunc_o8_1();
        if (has != 0) {
            MS2Ptr<CGuildJoinRequestForChar> request(new CGuildJoinRequestForChar());
            request->FUN_1404c7f90(&packet);
            m_joinRequestsForChar.Add(request);
        }
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
        dialog->FUN_14196d0c0(0);
        dialog->FUN_14196d660();
    }
}
MS2_REPLACE_METHOD(0x1413C5840, CGuildManager, FUN_1413c5840, 403, 0xDBB149BD);

// Guild search results.
// @0x1413c59e0
void CGuildManager::FUN_1413c59e0(CInPacket& packet)
{
    if (FUN_1413b6160() != 0)
        return;
    m_searchResults.RemoveAll();
    int count = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (count == 0) {
        FUN_140d73aa0(FUN_14028de60(0x3ca), 0, 0, L"");
    } else {
        for (int i = 0; i < count; i++) {
            int has = static_cast<CInputStream&>(packet).vfunc_o8_1();
            if (has != 0) {
                MS2Ptr<CSearchGuildJoin> result(new CSearchGuildJoin());
                result->FUN_1404c8a50(&packet);
                m_searchResults.Add(result);
            }
        }
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196d0c0(1);
}
MS2_REPLACE_METHOD(0x1413C59E0, CGuildManager, FUN_1413c59e0, 528, 0x4A55976C);

// A guild storage gift result.
// @0x1413c5c00
void CGuildManager::FUN_1413c5c00(CInPacket& packet)
{
    if (FUN_1413b6160() == 0)
        return;
    int result = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (result == 0) {
        CStringW receiver = static_cast<CInputStream&>(packet).vfunc_o8_8();
        FUN_1412751b0(FUN_1405c2690(CStringW(L"s_guild_storage_gift"), receiver), 0xd);
    } else if (result == 0x36) {
        int period = *FUN_1402056b0(&FUN_1401d3200()->m_guildStorageGiftNeedPeriod);
        FUN_1412751f0(FUN_14062b4f0(L"s_guild_storage_not_enough_gift_need_period", &period), 1, 1);
    }
}
MS2_REPLACE_METHOD(0x1413C5C00, CGuildManager, FUN_1413c5c00, 430, 0xA019B758);

// The guild storage history list (sent when the storage window opens).
// @0x1413c5dc0
void CGuildManager::FUN_1413c5dc0(CInPacket& packet)
{
    if (FUN_1413b6160() == 0)
        return;
    {
        m_400 = true;
        FUN_140506ca0(&storage.f38);
        int count = static_cast<CInputStream&>(packet).vfunc_o8_3();
        for (int i = 0; i < count; i++) {
            ItemEntity item;
            Unk_GuildHist from;
            Unk_GuildHist to;
            from.FUN_1404c5be0(packet);
            to.FUN_1404c5be0(packet);
            item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
            __int64 time = static_cast<CInputStream&>(packet).vfunc_o8_4();
            FUN_1404d2e90(&from, &to, &item, time);
        }
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
            dialog->FUN_1419729d0();
    }
}
MS2_REPLACE_METHOD(0x1413C5DC0, CGuildManager, FUN_1413c5dc0, 455, 0x4E448C8B);

// A join request this character sent was cancelled or answered.
// @0x1413c5f90
void CGuildManager::FUN_1413c5f90(CInPacket& packet)
{
    if (FUN_1413b6160() != 0)
        return;
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    __int64 requestId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int joined = static_cast<CInputStream&>(packet).vfunc_o8_1();
    for (size_t i = 0; i < m_joinRequestsForChar.GetCount(); i++) {
        MS2Ptr<CGuildJoinRequestForChar> request = m_joinRequestsForChar[i];
        if (request == 0)
            continue;
        if (request->f18 == requestId) {
            m_joinRequestsForChar.RemoveAt(i, 1);
            break;
        }
    }
    if (joined) {
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e4f);
    } else {
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f)) {
            dialog->FUN_14196d0c0(0);
            dialog->FUN_14196d660();
        }
    }
}
MS2_REPLACE_METHOD(0x1413C5F90, CGuildManager, FUN_1413c5f90, 489, 0x158A8056);

// A join request to this guild was cancelled or answered.
// @0x1413c6180
void CGuildManager::FUN_1413c6180(CInPacket& packet)
{
    if (FUN_1413b6160() == 0)
        return;
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    int accepted = static_cast<CInputStream&>(packet).vfunc_o8_1();
    __int64 requestId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    for (size_t i = 0; i < m_joinRequestsForGuild.GetCount(); i++) {
        MS2Ptr<CGuildJoinRequestForGuild> request = m_joinRequestsForGuild[i];
        if (request == 0)
            continue;
        if (request->f18 == requestId) {
            m_joinRequestsForGuild.RemoveAt(i, 1);
            break;
        }
    }
    Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f);
    if (dialog)
        dialog->FUN_14196da70();
    Unk_GuildDialog4e28* listDialog = FUN_140938b90(0x4e28);
    if (listDialog)
        listDialog->FUN_1419381c0();
    if (accepted)
        FUN_1412751b0(FUN_140632a60(0x3bd, guildName, name), 0xd);
    else
        FUN_1412751b0(FUN_140632a60(0x3be, guildName, name), 0xd);
}
MS2_REPLACE_METHOD(0x1413C6180, CGuildManager, FUN_1413c6180, 729, 0x82F01EB1);

// A new join request to this guild.
// @0x1413c6460
void CGuildManager::FUN_1413c6460(CInPacket& packet)
{
    if (FUN_1413b6160() == 0)
        return;
    MS2Ptr<CGuildJoinRequestForGuild> request(new CGuildJoinRequestForGuild());
    request->FUN_1404c7940(&packet);
    if (FUN_1413b6160() == 0)
        return;
    m_joinRequestsForGuild.Add(request);
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196da70();
    if (Unk_GuildDialog4e28* dialog = FUN_140938b90(0x4e28))
        dialog->FUN_1419381c0();
}
MS2_REPLACE_METHOD(0x1413C6460, CGuildManager, FUN_1413c6460, 272, 0x8310269E);

// A join request to this guild was withdrawn.
// @0x1413c6580
void CGuildManager::FUN_1413c6580(CInPacket& packet)
{
    if (FUN_1413b6160() == 0)
        return;
    __int64 requestId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    for (size_t i = 0; i < m_joinRequestsForGuild.GetCount(); i++) {
        MS2Ptr<CGuildJoinRequestForGuild> request = m_joinRequestsForGuild[i];
        if (request == 0)
            continue;
        if (request->f18 == requestId) {
            m_joinRequestsForGuild.RemoveAt(i, 1);
            break;
        }
    }
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196da70();
    if (Unk_GuildDialog4e28* dialog = FUN_140938b90(0x4e28))
        dialog->FUN_1419381c0();
}
MS2_REPLACE_METHOD(0x1413C6580, CGuildManager, FUN_1413c6580, 354, 0xB05B82C0);

// A player's guild name changed: update the name shown over them.
// @0x1413c7700
void CGuildManager::FUN_1413c7700(CInPacket& packet)
{
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    CStringW guildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    PC* pc = (PC*)FUN_1403ed2d0()->FUN_141bd1420(name);
    if (pc == 0)
        return;
    pc->vfunc_129(guildName);
}
MS2_REPLACE_METHOD(0x1413C7700, CGuildManager, FUN_1413c7700, 266, 0xB5100F2C);

// A player left their guild: clear the name shown over them.
// @0x1413c7810
void CGuildManager::FUN_1413c7810(CInPacket& packet)
{
    CStringW name = static_cast<CInputStream&>(packet).vfunc_o8_8();
    PC* pc = (PC*)FUN_1403ed2d0()->FUN_141bd1420(name);
    if (pc == 0)
        return;
    pc->vfunc_129(L"");
}
MS2_REPLACE_METHOD(0x1413C7810, CGuildManager, FUN_1413c7810, 227, 0x82EDFDF5);

// The local player's name ("" before the player exists).
// @0x1413c7c20
CStringW CGuildManager::FUN_1413c7c20()
{
    PC* pc = (PC*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return L"";
    return pc->vfunc_77();
}
MS2_REPLACE_METHOD(0x1413C7C20, CGuildManager, FUN_1413c7c20, 129, 0x9BBE6FF2);

// Adds members read from the packet (under the guild lock).
// MS2-FUNCTIONAL: the member handed to CGuildInfo::vfunc_0 is guilddef_1's POD Unk_GuildRef (the original passes
// the pointer by value), and the new member's pointer is the 16-byte payload pointer in the original (frame 0x10
// smaller here); same calls in the same order.
// @0x1413c7900
void CGuildManager::FUN_1413c7900(CInPacket& packet)
{
    Unk_140163940 guard(lock);
    if (guard != 0) {
        // the lock is not held
    } else {
        int count = static_cast<CInputStream&>(packet).vfunc_o8_1();
        for (int i = 0; i < count; i++) {
            MS2Ptr<CGuildMember> member(new CGuildMember());
            member->FUN_1404cb450(&packet);
            Unk_GuildRef copy;
            FUN_1404ec5b0(&copy, member);
            vfunc_0(&copy);
            FUN_1409f7c90()->FUN_14161cd60(member->data.f08);
        }
    }
}
MS2_REPLACE_METHOD(0x1413C7900, CGuildManager, FUN_1413c7900, 404, 0x35152723);

// Replaces the grade list with the grades in the packet.
// @0x1413c7aa0
void CGuildManager::FUN_1413c7aa0(CInPacket& packet)
{
    Unk_140163940 guard(lock);
    if (guard != 0) {
        // the lock is not held
    } else {
        fa0.RemoveAll();
        int count = static_cast<CInputStream&>(packet).vfunc_o8_1();
        fa0.SetCount(count, -1);
        for (int i = 0; i < count; i++) {
            Unk_PayloadPtr<CGuildGrade> grade(new CGuildGrade());
            grade->FUN_1404c71d0(packet);
            fa0.SetAt(i, grade);
        }
    }
}
MS2_REPLACE_METHOD(0x1413C7AA0, CGuildManager, FUN_1413c7aa0, 370, 0x00926961);

// @0x1413c7d40
void CGuildManager::FUN_1413c7d40(ATL::CAtlArray<MS2Ptr<CSearchGuildJoin>>& out) const
{
    for (size_t i = 0; i < m_searchResults.GetCount(); i++)
        out.Add(m_searchResults[i]);
}
MS2_REPLACE_METHOD(0x1413C7D40, CGuildManager, FUN_1413c7d40, 108, 0x1219FE27);

// A search result by guild name.
// @0x1413c7dc0
MS2Ptr<CSearchGuildJoin> CGuildManager::FUN_1413c7dc0(const CStringW& guildName) const
{
    for (size_t i = 0; i < m_searchResults.GetCount(); i++) {
        MS2Ptr<CSearchGuildJoin> result = m_searchResults.GetAt(i);
        if (FUN_14025cd60(result->f58, guildName))
            return result;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1413C7DC0, CGuildManager, FUN_1413c7dc0, 253, 0x45EEAA43);

// @0x1413c7ed0
void CGuildManager::FUN_1413c7ed0()
{
    m_searchResults.RemoveAll();
}
MS2_REPLACE_METHOD(0x1413C7ED0, CGuildManager, FUN_1413c7ed0, 33, 0x97C69940);

// @0x1413c7f00
void CGuildManager::FUN_1413c7f00(ATL::CAtlArray<MS2Ptr<CGuildJoinRequestForChar>>& out) const
{
    for (size_t i = 0; i < m_joinRequestsForChar.GetCount(); i++)
        out.Add(m_joinRequestsForChar[i]);
}
MS2_REPLACE_METHOD(0x1413C7F00, CGuildManager, FUN_1413c7f00, 108, 0xB8FF205B);

// @0x1413c7f80
void CGuildManager::FUN_1413c7f80(ATL::CAtlArray<MS2Ptr<CGuildJoinRequestForGuild>>& out) const
{
    for (size_t i = 0; i < m_joinRequestsForGuild.GetCount(); i++)
        out.Add(m_joinRequestsForGuild[i]);
}
MS2_REPLACE_METHOD(0x1413C7F80, CGuildManager, FUN_1413c7f80, 108, 0xBB3279F4);

// A guild error notice: the server's error code to its message (kind is not used).
// @0x1413c66f0
void CGuildManager::FUN_1413c66f0(int kind, int code, int arg)
{
    CStringW text;
    switch (code) {
    case 1:
        text = FUN_14028de60(0x403);
        break;
    case 3:
        text = FUN_14028de60(0x404);
        break;
    case 4:
        text = FUN_14028de60(0x405);
        break;
    case 5:
        text = FUN_14028de60(0x406);
        break;
    case 6:
        text = FUN_14028de60(0x407);
        break;
    case 7:
        text = FUN_14028de60(0x408);
        break;
    case 8:
        text = FUN_14028de60(0x409);
        break;
    case 0xa:
        text = FUN_14028de60(0x40a);
        break;
    case 0xb:
        text = FUN_14028de60(0x40b);
        break;
    case 0xc:
        text = FUN_14028de60(0x40c);
        break;
    case 0xd:
        text = FUN_14028de60(0x40d);
        break;
    case 0xe:
        text = FUN_14028de60(0x40e);
        break;
    case 0xf:
        text = FUN_14028de60(0x40f);
        break;
    case 0x10:
        text = FUN_14028de60(0x410);
        break;
    case 0x11:
        text = FUN_14028de60(0x411);
        break;
    case 0x12:
        text = FUN_14028de60(0x412);
        break;
    case 0x13:
        text = FUN_1408116a0(0x413, *FUN_1402056b0(&FUN_1401d3200()->m_guildCreateMinLevel));
        break;
    case 0x14:
        text = FUN_14028de60(0x414);
        break;
    case 0x15:
        text = FUN_14028de60(0x415);
        break;
    case 0x16:
        text = FUN_14028de60(0x416);
        break;
    case 0x17:
        text = FUN_14028de60(0x417);
        break;
    case 0x18:
        text = FUN_14028de60(0x418);
        break;
    case 0x19:
        text = FUN_14028de60(0x419);
        break;
    case 0x1a:
        text = FUN_14028de60(0x41a);
        break;
    case 0x1b:
        text = FUN_14028de60(0x41b);
        break;
    case 0x1c:
        text = FUN_14028de60(0x41c);
        break;
    case 0x1e:
        text = FUN_14028de60(0x41d);
        break;
    case 0x20:
        text = FUN_14028de60(0x41e);
        break;
    case 0x21:
        text = FUN_14028de60(0x41f);
        break;
    case 0x29:
        text = FUN_14028de60(0x424);
        break;
    case 0x22:
        text = FUN_14028de60(0x3a0);
        break;
    case 0x23:
        text = FUN_14028de60(0x3a1);
        break;
    case 0x24:
        text = FUN_14028de60(0x3a2);
        break;
    case 0x25:
        text = FUN_14028de60(0x3a3);
        break;
    case 0x26:
        text = FUN_14028de60(0x3a4);
        break;
    case 0x27:
        text = FUN_14028de60(0x3a5);
        break;
    case 0x2a:
        text = FUN_14028b8e0(L"s_guild_err_not_enough_guild_level");
        break;
    case 0x2b:
        text = FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund");
        break;
    case 0x2c:
        text = FUN_14028b8e0(L"s_guild_err_cannot_use_skill");
        break;
    case 0x2d:
        text = FUN_14028b8e0(L"s_guild_err_too_fast_to_search_by_name");
        break;
    case 0x2e:
        text = FUN_14028de60(0x3c2);
        break;
    case 0x2f:
        text = FUN_14028b8e0(L"s_guild_err_isNotVsGameTime");
        break;
    case 0x30:
        text = FUN_14062b4f0(L"s_guild_err_requireOnlineUserCount", &arg);
        break;
    default:
        text = FUN_14028de60(0x420);
        break;
    }
    FUN_1412751f0(text, 1, 1);
}
MS2_REPLACE_METHOD(0x1413C66F0, CGuildManager, FUN_1413c66f0, 3906, 0x24209A69);

// This character's join request to a guild.
// @0x1413c8000
MS2Ptr<CGuildJoinRequestForChar> CGuildManager::FUN_1413c8000(__int64 guildId) const
{
    for (size_t i = 0; i < m_joinRequestsForChar.GetCount(); i++) {
        MS2Ptr<CGuildJoinRequestForChar> request = m_joinRequestsForChar[i];
        if (request.get() && request->f20 == guildId)
            return request;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1413C8000, CGuildManager, FUN_1413c8000, 255, 0x48CD7B49);

// The vs-game entry prompt's result: enter on the first button.
// @0x1413c7cb0
bool CGuildManager::FUN_1413c7cb0(int result, const CMsgBoxData& box)
{
    if (result != 0)
        return true;
    if (box.FUN_141a04a80().m_nButton != 0)
        return true;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x78);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413C7CB0, CGuildManager, FUN_1413c7cb0, 130, 0x3FF8FC6D);
