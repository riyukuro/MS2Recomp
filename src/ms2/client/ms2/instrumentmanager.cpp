// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CInstrumentManager: the instrument play mode (packet 0x74)
// - keyboard notes, solo / ensemble / remote score performances played through the MIDI output, performer channels,
// distance volume and the score's motion events. See instrumentmanager.h. The v2525 snapshot's bodies
// (work/ext/v2525, tu/140d05970.cpp) were the reference; our decompile decided the check order and call shapes.
// No __FILE__ in the range: the unit name is guessed from the class.
// MS2-UNIT: ?\instrumentmanager.cpp
// MS2-RANGE: 0x1400d1dd0-0x1400d1f70 .text$di
// MS2-RANGE: 0x140d05a90-0x140d1ae30 .text$mn
// MS2-RANGE: 0x142ca4940-0x142ca49f0 .text$yd
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??$Unk_ImGetDialog@VUIPlayInstrumentDialog@@@@YAPEAVUIPlayInstrumentDialog@@H@Z 0x140d0c040
// MS2-PIN: ??$Unk_ImGetDialog@VUIWriteMusicDialog@@@@YAPEAVUIWriteMusicDialog@@H@Z 0x140d0c0e0
// MS2-PIN: ??_7CInstrumentManager@@6B?$TSingleton@VCInstrumentManager@@@@@ 0x142e26940
// MS2-PIN: ??$StringFormat@HHK@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH1AEBK@Z 0x140d0bcc0
// MS2-PIN: ??$?0AEAHAEBH$0A@@?$pair@HH@std@@QEAA@AEAHAEBH@Z 0x140d0b6c0
// MS2-PIN: ??$?0HH$0A@@?$pair@$$CBIH@std@@QEAA@$$QEAU?$pair@HH@1@@Z 0x140d0b9a0
// MS2-PIN: ??$?0II$0A@@?$pair@$$CBII@std@@QEAA@$$QEAU?$pair@II@1@@Z 0x140d0ba40
// MS2-PIN: ??$construct@U?$pair@$$CBIH@std@@U?$pair@HH@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@1@QEAU?$pair@$$CBIH@1@$$QEAU?$pair@HH@1@@Z 0x140d10ea0
// MS2-PIN: ??$construct@U?$pair@$$CBII@std@@U?$pair@II@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@QEAU?$pair@$$CBII@1@$$QEAU?$pair@II@1@@Z 0x140d10ef0
// MS2-PIN: ??$make_pair@AEAHAEAH@std@@YA?AU?$pair@HH@0@AEAH0@Z 0x140d117c0
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x140d0d020
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x140d0cf90
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@std@@V12@@2@AEBI@Z 0x140d19cc0
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBII@std@@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$00@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBII@1@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@@Z 0x140d0ff10
// MS2-PIN: ??$emplace@U?$pair@II@std@@@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$00@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@II@1@@Z 0x140d11240
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@1@$$QEA_N@Z 0x140d0bbd0
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$00@std@@@std@@IEBAAEBIAEBU?$pair@$$CBII@2@@Z 0x140d17c50
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x140d1ac50
// MS2-PIN: ??$?0AEAHAEAH$0A@@?$pair@HH@std@@QEAA@AEAH0@Z 0x140d0b250
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IURemoteVoice@CInstrumentManager@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@@4@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x140d0ca80
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IURemoteVoice@CInstrumentManager@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@@4@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIURemoteVoice@CInstrumentManager@@@1@PEAU?$_Tree_node@U?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@PEAX@1@@Z 0x140d0f2e0
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140d0bb80
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@IURemoteVoice@CInstrumentManager@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIURemoteVoice@CInstrumentManager@@@std@@@4@$0A@@std@@@std@@IEBAAEBIAEBU?$pair@$$CBIURemoteVoice@CInstrumentManager@@@2@@Z 0x140d17c30
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\instrumentmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "instrumentmanager.h"

#include <algorithm>
#include <vector>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/mmltoken.h"
#include "ms2/client/ms2/soundeventmgr.h"
#include "ms2/client/ms2/stateplayinstrumentdata.h"
#include "ms2/client/ms2/uiplayinstrumentdialog.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cinstrumentdatatable.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/uibuddyeventdispatcher.h"
#include "ms2/placeholder/uiwritemusicdialog.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (dynamic initializers 0x1400d1dd0..0x1400d1f40) ----
static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strNotThisPlace("system_notice_error_warningNotThisPlace");

// ---- unit-local views of exe objects ----

class Unk_ImBuffs { public: int FUN_1409701d0(int nKind); };      // an active buff of a kind

// A field actor (PC base): vtable slot 18 returns the world position.
class Unk_ImActor
{
public:
#define IM_V(n) virtual void vfunc_##n();
    IM_V(0) IM_V(1) IM_V(2) IM_V(3) IM_V(4) IM_V(5) IM_V(6) IM_V(7) IM_V(8) IM_V(9)
    IM_V(10) IM_V(11) IM_V(12) IM_V(13) IM_V(14) IM_V(15) IM_V(16) IM_V(17)
#undef IM_V
    virtual Vector3 vfunc_18();                                     // the position
    int FUN_14123c580();                                                    // the object id
    int FUN_14166c930();                                                    // the state id (0x2f = play instrument)
    StatePlayInstrument* FUN_14166ccb0();                                   // the play instrument state
    void FUN_14165ebb0(float fSpeed);                                       // the animation speed
    void FUN_14166cc40(int nSubState);                                      // set the sub state
    int FUN_14166cc80();                                                    // the sub state
    Unk_ImBuffs* FUN_1416749a0();                                           // the buffs
    __int64 FUN_141656a80();                                                // the account / buddy id
    bool FUN_141527280();                                                   // in a party
};

// The world service (singleton 0x1403ed2d0).
class Unk_ImWorld
{
public:
    Unk_ImActor* FUN_141bd0cc0();                                           // the local player
    Unk_ImActor* FUN_141bd1290(int nId);                                    // an actor by object id
    Unk_ImActor* FUN_141bd1530(__int64 nId);                                // an actor by character id
    bool FUN_141bcb150();                                                   // the field mutes the distance falloff
    int FUN_141bdb660(int nKind);                                           // the field forbids a feature
    void FUN_141bbae40(IWorldServiceCallback* pCallback);                  // register a callback
};
Unk_ImWorld* FUN_1403ed2d0();

// The UI service (dialog lookup / open).
class Unk_ImUIService
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
    void FUN_141adc530(int nId);
};
Unk_ImUIService* FUN_1403ed2b0();

// The auto play pane (UI class 0x4f07).
class Unk_ImAutoPlayPane : public UIDialog
{
public:
    void FUN_140fa5ba0(int nMode);
    void FUN_140fa64e0();                                                   // refresh
};
Unk_ImAutoPlayPane* FUN_140cdee10(int nId);

// The client platform: performance start / end reports (vtable slots 52 / 53).
class Unk_ImPlatform
{
public:
#define IM_V(n) virtual void vfunc_##n();
    IM_V(0) IM_V(1) IM_V(2) IM_V(3) IM_V(4) IM_V(5) IM_V(6) IM_V(7) IM_V(8) IM_V(9)
    IM_V(10) IM_V(11) IM_V(12) IM_V(13) IM_V(14) IM_V(15) IM_V(16) IM_V(17) IM_V(18) IM_V(19)
    IM_V(20) IM_V(21) IM_V(22) IM_V(23) IM_V(24) IM_V(25) IM_V(26) IM_V(27) IM_V(28) IM_V(29)
    IM_V(30) IM_V(31) IM_V(32) IM_V(33) IM_V(34) IM_V(35) IM_V(36) IM_V(37) IM_V(38) IM_V(39)
    IM_V(40) IM_V(41) IM_V(42) IM_V(43) IM_V(44) IM_V(45) IM_V(46) IM_V(47) IM_V(48) IM_V(49)
    IM_V(50) IM_V(51)
#undef IM_V
    virtual void vfunc_52(__int64 nScoreUid, int bRemote);                 // a performance started
    virtual void vfunc_53(__int64 nScoreUid, int bRemote);                 // a performance ended
};
Unk_ImPlatform* FUN_140d86260();

// The item event dispatcher (slot 3: an item changed).
class Unk_ImItemEvents
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(CItem* pItem, int n);
};
Unk_ImItemEvents* FUN_140a6a840();

// The player inventory (global at 0x143ab2a90): item lookup by uid.
class Unk_ImInventory { public: MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid); };
extern Unk_ImInventory DAT_143ab2a90;
class Unk_ItemEquipData { public: bool FUN_14053cd10(); };

// CommonResource: +0x598 the ensemble notice effect file.
class Unk_ImResource
{
public:
    char m_pad[0x598];
    CString m_strEnsembleEffect;                                            // +0x598
};
Unk_ImResource* FUN_1401d31f0();
class Unk_ImEffectService { public: unsigned FUN_1411a4a00(Unk_EffectTarget& kTarget); };
Unk_ImEffectService* FUN_1403ed280();

class Unk_ImConfig { public: bool FUN_14036d570(int nFeature); };          // a feature is enabled
Unk_ImConfig* FUN_140166410();
class Unk_ImFiles { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_ImFiles* FUN_140166420();
class Unk_ImLog { public: void FUN_14015eb90(int nLevel, int nFlags, const wchar_t* pszFormat, const CString& strArg); };
Unk_ImLog* FUN_140166440();
class Unk_ImDebug;
Unk_ImDebug* FUN_14025e7c0();
bool FUN_14116d720(Unk_ImDebug* pDebug);                                    // the debug mode is on

class Unk_ImXmlNode;
Unk_ImXmlNode* FUN_140165cf0(void* pNode, const char* pszName);            // first child element
Unk_ImXmlNode* FUN_140168650(Unk_ImXmlNode* pNode, const char* pszName);    // next sibling element
int FUN_1408733e0(Unk_ImXmlNode* pNode, const char* pszName, CString* pstrValue);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);

void FUN_14125fe20(Unk_SoundState* pSound);                                 // reapply the sound volumes
int FUN_141260310(Unk_SoundState* pSound);                                  // the instrument volume
unsigned FUN_140869420();                                                   // the client clock (ms)
int FUN_141472bc0();                                                        // the server clock bias
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
CStringW FUN_1409eec40(int nId);                                            // system notice text
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);  // message box
void FUN_1412751f0(const CStringW& str, int a, int b);                      // notice
void FUN_1412751b0(const CStringW& str, int nType);                         // system chat notice
int FUN_141276180(const CString& strChannel, const CString& strArg);        // the notice log
void FUN_1402c8940(const CString& strText, std::vector<CString>& out, const char* pszSep);   // split
void FUN_1401ffdc0(void* pScore, COutPacket* pPacket);                      // write a composed score

extern Vector3 DAT_143b01a60;                                       // the zero point

// ---- CInstrumentManager::Voice / RemoteVoice / Slot ----

// @0x140d05a90
void CInstrumentManager::Voice::Reset()
{
    m_channel = 0;
    m_owner = 0;
    m_program = 0;
    m_percussion = 0;
    m_position = DAT_143b01a60;
}

// @0x140d05af0
void CInstrumentManager::Voice::Assign(const Voice& o)
{
    m_channel = o.m_channel;
    m_owner = o.m_owner;
    m_program = o.m_program;
    m_percussion = o.m_percussion;
    m_position = o.m_position;
}

// @0x140d05b70
void CInstrumentManager::RemoteVoice::Init()
{
    Reset();
    m_active = true;
}

// @0x140d05ba0
void CInstrumentManager::Slot::Init()
{
    Reset();
    m_used = false;
    m_volume = -1;
}

// ---- CInstrumentManager ----

// @0x140d05be0
CInstrumentManager::CInstrumentManager()
    : m_flags(0), m_instrument(0), m_instrumentUid(0), m_scoreUid(0), m_ensemble(false), m_playing(false),
      m_performing(false), m_refs(0), m_remote(false), m_baseTime(0x7fffffff), m_muted(false), m_volume(0)
{
    if (!FUN_140166410()->FUN_14036d570(10))
        return;
    m_midi.Open();
    for (int i = 0; i < 0x10; i++)
        m_slots[i].Init();
    m_remoteVoices.clear();
    FUN_1403ed2d0()->FUN_141bbae40(this);
    TSingleton<UIBuddyEventDispatcher>::GetInstance()->FUN_1418d9450(this);
}

// @0x140d05e50
CInstrumentManager::~CInstrumentManager()
{
    m_midi.Close();
    TSingleton<UIBuddyEventDispatcher>::GetInstance()->FUN_1418d94e0(this);
}

// @0x140d05f70
void CInstrumentManager::vfunc_1(int nMap)
{
    m_baseTime = FUN_140869420() - FUN_141472bc0();
    unsigned nResult = 0;
    if (!m_midi.IsOpen())
        nResult = m_midi.Open();
}

// @0x140d05fe0
void CInstrumentManager::vfunc_4(int nMap)
{
    Clear();
    m_performing = false;
    m_ensemble = false;
    FUN_14125fe20(TSingleton<CGameOption>::GetInstance()->FUN_140d13c70());
}

// @0x140d06030
void CInstrumentManager::vfunc_buddy_4(__int64 nId, int n)
{
    UpdateVolume(false);
    CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4b70(nId);
    if (spBuddy == 0)
        return;
    Unk_ImActor* pActor = FUN_1403ed2d0()->FUN_141bd1530(spBuddy->FUN_1401cc230());
    if (pActor == 0)
        return;
    if (pActor->FUN_14166c930() != 0x2f)
        return;
    StatePlayInstrument* pState = pActor->FUN_14166ccb0();
    pState->FUN_140ddfc00();
}

// @0x140d06130
void CInstrumentManager::vfunc_buddy_7(__int64 nId)
{
    UpdateVolume(false);
    Unk_ImActor* pActor = FUN_1403ed2d0()->FUN_141bd1530(nId);
    if (pActor == 0)
        return;
    if (pActor->FUN_14166c930() != 0x2f)
        return;
    StatePlayInstrument* pState = pActor->FUN_14166ccb0();
    pState->FUN_140ddfc00();
}

// The scene dialog lookup template (instances pinned: 0x140d0c040 / 0x140d0c0e0).
template <class T> T* Unk_ImGetDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// @0x140d061b0
// MS2-FUNCTIONAL: 3.8 KB packet dispatch, not byte-matched
void CInstrumentManager::OnPacket(CInPacket& packet)
{
    unsigned char nType = packet.ReadUInt8();
    if (nType == 0)
    {
        // a performer's program
        int nKey = packet.ReadInt32();
        int nOwner = packet.ReadInt32();
        Vector3 ptPos = packet.ReadVector3();
        int nProgram = packet.ReadInt32();
        int nPercussion = packet.ReadInt32();
        Voice voice;
        voice.m_channel = nKey;
        voice.m_owner = nOwner;
        voice.m_position = ptPos;
        voice.m_program = nProgram;
        voice.m_percussion = nPercussion;
        Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMe != 0 && pMe->FUN_14123c580() == nOwner)
            nKey = 0;
        int nSlot = GetSlot(nKey, voice);
        if (nSlot != 0x10)
        {
            CMidiMessage msg;
            msg.ProgramChange(nSlot, nProgram);
            m_midi.SendMessage(nSlot, msg.m_msg);
            UpdateVolume(false);
        }
    }
    else if (nType == 1)
    {
        // a performer's keyboard note
        int nKey = packet.ReadInt32();
        int nOwner = packet.ReadInt32();
        unsigned nMsg = packet.ReadInt32();
        Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMe != 0 && pMe->FUN_14123c580() == nOwner)
            nKey = 0;
        if (IsBlocked(nOwner) != true)
        {
            int nSlot = FindSlot(nKey);
            if (nSlot != 0x10)
                m_midi.SendMessage(nSlot, nMsg);
        }
    }
    else if (nType == 3)
    {
        // a score performance starts
        unsigned char nKind = packet.ReadUInt8();
        int nKey = packet.ReadInt32();
        int nOwner = packet.ReadInt32();
        Vector3 ptPos = packet.ReadVector3();
        int nStart = packet.ReadInt32();
        int nProgram = packet.ReadInt32();
        int nPercussion = packet.ReadInt32();
        bool bRemote = packet.ReadBool();
        Voice voice;
        voice.m_channel = nKey;
        voice.m_owner = nOwner;
        voice.m_position = ptPos;
        voice.m_program = nProgram;
        voice.m_percussion = nPercussion;
        Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMe != 0 && pMe->FUN_14123c580() == nOwner)
            nKey = 0;
        int nSlot = GetSlot(nKey, voice);
        if (nSlot != 0x10)
        {
            if (m_baseTime == 0x7fffffff)
                m_baseTime = FUN_140869420() - FUN_141472bc0();
            nStart = nStart + 300 + m_baseTime;
            int nEnd = 0;
            if (nKind == 0)
            {
                CString strName = packet.ReadUnicodeStringA();
                nEnd = PlayScoreFile(strName, nStart, nProgram, nPercussion, nSlot, nKey, nOwner);
            }
            else if (nKind == 1)
            {
                CString strText = packet.ReadString();
                nEnd = PlayScoreText(strText, nStart, nProgram, nPercussion, nSlot, nKey, nOwner);
            }
            PlayEvents();
            OnPerformStart(nOwner, nStart, nEnd, bRemote);
        }
    }
    else if (nType == 6)
    {
        // the ensemble was cancelled
        UIPlayInstrumentDialog* pDialog = Unk_ImGetDialog<UIPlayInstrumentDialog>(0x4eec);
        if (pDialog != 0)
            pDialog->FUN_14100e9a0(1);
        SetPcState(0x7d);
    }
    else if (nType == 2 || nType == 4)
    {
        // a performer stopped (4: the score performance ended)
        int nKey = packet.ReadInt32();
        int nOwner = packet.ReadInt32();
        Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMe != 0 && pMe->FUN_14123c580() == nOwner)
            nKey = 0;
        int nSlot = FindSlot(nKey);
        if (nSlot != 0x10)
        {
            ResetChannel(nSlot, nKey);
            RemoveSlot(nKey);
            if (nType == 4)
                OnPerformEnd(nOwner);
        }
    }
    else if (nType == 8)
    {
        // a composed score item
        __int64 nUid = packet.ReadInt64();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem.get())
        {
            spItem->FUN_140524eb0(packet);
            FUN_140a6a840()->vfunc_3(spItem.get(), 0);
            UIWriteMusicDialog* pDialog = Unk_ImGetDialog<UIWriteMusicDialog>(0x4eed);
            if (pDialog != 0)
                pDialog->FUN_140fefd00(MS2Ptr<CItem>(spItem));
        }
    }
    else if (nType == 9)
    {
        __int64 nUid = packet.ReadInt64();
        int nValue = packet.ReadInt32();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem.get())
        {
            spItem->FUN_140527320(nValue);
            FUN_140a6a840()->vfunc_3(spItem.get(), 0);
        }
    }
    else if (nType == 10)
    {
        // the score text of an item
        __int64 nUid = packet.ReadInt64();
        CString strScore = packet.ReadString();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem.get())
        {
            UIWriteMusicDialog* pDialog = Unk_ImGetDialog<UIWriteMusicDialog>(0x4eed);
            if (pDialog != 0)
                pDialog->FUN_140ff0260(nUid, strScore);
        }
    }
    else if (nType == 14)
    {
        // the ensemble effect over a performer
        int nId = packet.ReadInt32();
        Unk_ImActor* pActor = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pActor != 0)
        {
            Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pMe != 0)
            {
                Unk_EffectTarget kTarget;
                kTarget.m_strName = FUN_1401d31f0()->m_strEnsembleEffect;
                kTarget.m_nKind = pActor == pMe ? 1 : 3;
                kTarget.FUN_140a53190(pActor->FUN_14123c580());
                FUN_1403ed280()->FUN_1411a4a00(kTarget);
            }
        }
    }
    else if (nType == 17)
    {
        // the compose result
        unsigned char nResult = packet.ReadUInt8();
        UIWriteMusicDialog* pWrite = Unk_ImGetDialog<UIWriteMusicDialog>(0x4eed);
        if (pWrite != 0)
            pWrite->FUN_140ff0090(nResult);
        UIPlayInstrumentDialog* pDialog = Unk_ImGetDialog<UIPlayInstrumentDialog>(0x4eec);
        if (pDialog != 0)
            pDialog->FUN_14100e9a0(1);
    }
}

// @0x140d07080
void CInstrumentManager::Update()
{
    UpdateVolume(false);
    PlayEvents();
}

// @0x140d070b0
void CInstrumentManager::Stop()
{
    m_instrument = 0;
    m_instrumentUid = 0;
    m_scoreUid = 0;
    SetEnsemble(false);
    StopPerform();
    UIPlayInstrumentDialog* pDialog = Unk_ImGetDialog<UIPlayInstrumentDialog>(0x4eec);
    if (pDialog != 0)
        pDialog->FUN_14100c1e0();
}

// @0x140d07130
void CInstrumentManager::SetInstrument(int nInstrument, __int64 nItemUid)
{
    m_instrument = nInstrument;
    m_instrumentUid = nItemUid;
    UIPlayInstrumentDialog* pDialog = Unk_ImGetDialog<UIPlayInstrumentDialog>(0x4eec);
    if (pDialog != 0)
        pDialog->SetInstrument(m_instrument);
    FUN_1403ed2b0()->FUN_141adc530(0x4eec);
}

// @0x140d071b0
int CInstrumentManager::CanPlayEnsemble()
{
    Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return 0;
    return pMe->FUN_1416749a0()->FUN_1409701d0(4);
}

// @0x140d07200
bool CInstrumentManager::SetPcState(int nState)
{
    Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return false;
    if (pMe->FUN_14166c930() == 0x2f)
    {
        pMe->FUN_14166cc40(nState);
        return true;
    }
    return false;
}

// @0x140d07260
void CInstrumentManager::SetEnsemble(bool bEnsemble)
{
    if (!FUN_140166410()->FUN_14036d570(10))
        return;
    if (m_ensemble == bEnsemble)
        return;
    if (bEnsemble)
    {
        m_ensemble = true;
        SetPcState(0x7d);
    }
    else
    {
        m_ensemble = false;
        m_playing = false;
        COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
        packet.Encode1(2);
        FUN_140710590(packet);
        SetPcState(0x7d);
    }
}

// @0x140d07330
bool CInstrumentManager::IsEnsemble() { return m_ensemble; }
// @0x140d07350
bool CInstrumentManager::IsPerforming() { return m_performing; }
// @0x140d07370
bool CInstrumentManager::IsRemote() { return m_remote; }
// @0x140d07390
int CInstrumentManager::GetRefs() { return m_refs; }

// @0x140d073b0
// MS2-FUNCTIONAL: not byte-matched
void CInstrumentManager::NoteOn(int nNote)
{
    if (!m_ensemble)
        return;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_instrumentUid);
    if (spItem == 0)
        return;
    if (!spItem->FUN_140528980())
    {
        FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_play_instrument_invalid_instrument")), 1, 1);
        return;
    }
    if (FUN_1403ed2d0()->FUN_141bdb660(3) != 0)
    {
        FUN_1412751f0(FUN_1409eec40(0x62), 1, 1);
        FUN_141276180(s_strNotThisPlace, CString(""));
        return;
    }
    Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    MS2Ptr<CInstrumentCategoryData> spCategory = TSingleton<CInstrumentDataTable>::GetInstance()->GetInstrumentCategory(m_instrument);
    if (spCategory == 0)
        return;
    Voice voice;
    voice.m_channel = 0;
    voice.m_owner = pMe->FUN_14123c580();
    voice.m_position = pMe->vfunc_18();
    voice.m_program = spCategory->m_nGMId;
    voice.m_percussion = spCategory->m_nPercussionId;
    int nSlot = GetSlot(0, voice);
    if (!m_playing)
    {
        m_playing = true;
        COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
        packet.Encode1(0);
        packet.Encode8(spItem->FUN_140526a50());
        FUN_140710590(packet);
        CMidiMessage msg;
        msg.ProgramChange(nSlot, spCategory->m_nGMId);
        m_midi.SendMessage(nSlot, msg.m_msg);
        SetPcState(0x7e);
    }
    if (voice.m_percussion != 0)
        nNote = voice.m_percussion;
    CMidiMessage msg;
    msg.NoteOn(nSlot, nNote, 100);
    m_midi.SendMessage(nSlot, msg.m_msg);
    COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
    packet.Encode1(1);
    packet.Encode4(msg.m_msg);
    FUN_140710590(packet);
}

// @0x140d07840
void CInstrumentManager::NoteOff(int nNote)
{
    MS2Ptr<CInstrumentCategoryData> spCategory = TSingleton<CInstrumentDataTable>::GetInstance()->GetInstrumentCategory(m_instrument);
    if (spCategory == 0)
        return;
    if (spCategory->m_nPercussionId != 0)
        return;
    CMidiMessage msg;
    msg.NoteOff(0, nNote, 0);
    m_midi.SendMessage(0, msg.m_msg);
    COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
    packet.Encode1(1);
    packet.Encode4(msg.m_msg);
    FUN_140710590(packet);
}

// @0x140d07960
// MS2-FUNCTIONAL: not byte-matched
bool CInstrumentManager::PlayScore(__int64 nScoreUid)
{
    MS2Ptr<CItem> spScore = DAT_143ab2a90.FUN_140a5d680(nScoreUid);
    if (spScore == 0 || !spScore->FUN_140528980())
    {
        FUN_140d73aa0(GetStringCommonByKey(CStringW(L"s_play_instrument_invalid_music_score")), 0, 0, CStringW(L""));
        return false;
    }
    MS2Ptr<CItem> spInstrument = DAT_143ab2a90.FUN_140a5d680(m_instrumentUid);
    if (spInstrument == 0 || !spInstrument->FUN_140528980())
    {
        FUN_140d73aa0(GetStringCommonByKey(CStringW(L"s_play_instrument_invalid_instrument")), 0, 0, CStringW(L""));
        return false;
    }
    Unk_ItemEquipData* pData = spScore->FUN_140527840();
    if (pData == 0 || !pData->FUN_14053cd10())
        return false;
    if (FUN_1403ed2d0()->FUN_141bdb660(3) != 0)
    {
        FUN_1412751f0(FUN_1409eec40(0x62), 1, 1);
        FUN_141276180(s_strNotThisPlace, CString(""));
        return false;
    }
    m_scoreUid = nScoreUid;
    COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
    packet.Encode1(3);
    packet.Encode8(spInstrument->FUN_140526a50());
    packet.Encode8(nScoreUid);
    FUN_140710590(packet);
    return true;
}

// @0x140d07f00
// MS2-FUNCTIONAL: not byte-matched
bool CInstrumentManager::PlayEnsemble(__int64 nScoreUid)
{
    Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return false;
    if (!pMe->FUN_141527280())
    {
        FUN_140d73aa0(GetStringCommonByKey(CStringW(L"s_play_instrument_ui_need_party_for_ensemble")), 0, 0, CStringW(L""));
        return false;
    }
    MS2Ptr<CItem> spInstrument = DAT_143ab2a90.FUN_140a5d680(m_instrumentUid);
    if (spInstrument == 0 || !spInstrument->FUN_140528980())
    {
        FUN_140d73aa0(GetStringCommonByKey(CStringW(L"s_play_instrument_invalid_instrument")), 0, 0, CStringW(L""));
        return false;
    }
    MS2Ptr<CItem> spScore = DAT_143ab2a90.FUN_140a5d680(nScoreUid);
    if (spScore == 0 || !spScore->FUN_140528980())
    {
        FUN_140d73aa0(GetStringCommonByKey(CStringW(L"s_play_instrument_invalid_music_score")), 0, 0, CStringW(L""));
        return false;
    }
    Unk_ItemEquipData* pData = spScore->FUN_140527840();
    if (pData == 0 || !pData->FUN_14053cd10())
        return false;
    if (FUN_1403ed2d0()->FUN_141bdb660(3) != 0)
    {
        FUN_1412751f0(FUN_1409eec40(0x62), 1, 1);
        FUN_141276180(s_strNotThisPlace, CString(""));
        return false;
    }
    m_scoreUid = nScoreUid;
    COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
    packet.Encode1(5);
    packet.Encode8(spInstrument->FUN_140526a50());
    packet.Encode8(nScoreUid);
    FUN_140710590(packet);
    SetPcState(0x80);
    return true;
}

// @0x140d085a0
bool CInstrumentManager::StopEnsemble()
{
    COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
    packet.Encode1(6);
    FUN_140710590(packet);
    return true;
}

// @0x140d08600
void CInstrumentManager::StopPerform()
{
    if (!m_performing)
        return;
    COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
    packet.Encode1(4);
    FUN_140710590(packet);
}

// @0x140d08660
// MS2-FUNCTIONAL: not byte-matched
unsigned CInstrumentManager::ParseLine(int nChannel, int nProgram, int nPercussion, Unk_MidiTrack* pTrack,
                                       Unk_ImScoreEvents* pEvents, unsigned nTime, unsigned nNow, const CString& strMml,
                                       bool bFirst)
{
    if (m_programOverride.HasValue())
        nProgram = m_programOverride.Value();
    double dCursor = (double)nTime;
    if (nPercussion != 0 && !bFirst)
        return (unsigned)dCursor;

    MMLParser parser;
    parser.SetText(strMml);
    parser.Parse();
    std::vector<MS2Ptr<MMLToken> >& tokens = parser.m_tokens;
    bool bNoteSeen = false;
    for (unsigned __int64 i = 0; i < tokens.size(); i++)
    {
        if (bFirst && tokens[i]->m_nType == 5)
        {
            // a motion event: (kind, value)
            const int& nValue = tokens[i]->m_nValue;
            std::pair<int, int> event(tokens[i]->m_nPitch, nValue);
            unsigned nWhen = (unsigned)dCursor;
            if (tokens[i]->m_nPitch == 0 && !bNoteSeen && (double)nNow < dCursor)
                nWhen = nNow;
            pEvents->insert(std::make_pair(nWhen, event));
        }
        else if (tokens[i]->m_nType == 2)
        {
            // a control change (only the sustain pedal unless debugging)
            if (tokens[i]->m_nPitch != 0x40 && !FUN_14116d720(FUN_14025e7c0()))
                continue;
            if (tokens[i]->m_nPitch != 0x40 || nProgram < 0x40 || nProgram > 0x4f)
            {
                CMidiMessage msg;
                MMLToken* pToken = tokens[i].operator->();
                msg.ControlChange(nChannel, tokens[i]->m_nPitch, pToken->m_nValue);
                pTrack->insert(std::make_pair((unsigned)dCursor, msg.m_msg));
            }
        }
        else if (tokens[i]->m_nType == 4)
        {
            CMidiMessage msg;
            MMLToken* pToken = tokens[i].operator->();
            msg.PitchBend(nChannel, tokens[i]->m_nPitch, pToken->m_nValue);
            pTrack->insert(std::make_pair((unsigned)dCursor, msg.m_msg));
        }
        else
        {
            bNoteSeen = true;
            if ((double)nNow <= dCursor)
            {
                if (tokens[i]->m_nType == 1)
                {
                    dCursor = dCursor + tokens[i]->m_dTime;
                }
                else if (tokens[i]->m_nType == 0)
                {
                    if (tokens[i]->m_dTime > 1.0)
                    {
                        int nNote = tokens[i]->m_nPitch;
                        if (nPercussion != 0)
                            nNote = nPercussion;
                        CMidiMessage on;
                        on.NoteOn(nChannel, nNote, tokens[i]->m_nValue);
                        pTrack->insert(std::make_pair((unsigned)dCursor, on.m_msg));
                        dCursor = dCursor + tokens[i]->m_dTime;
                        if (nPercussion == 0)
                        {
                            CMidiMessage off;
                            off.NoteOff(nChannel, nNote, 0);
                            pTrack->insert(std::make_pair((unsigned)dCursor - 1, off.m_msg));
                        }
                    }
                }
            }
            else
            {
                dCursor = dCursor + tokens[i]->m_dTime;
            }
        }
    }
    return (unsigned)dCursor;
}

// @0x140d08d10
// MS2-FUNCTIONAL: not byte-matched
int CInstrumentManager::PlayScoreFile(const CString& strName, int nTime, int nProgram, int nPercussion, int nChannel,
                                      int nKey, unsigned nOwner)
{
    if (m_programOverride.HasValue())
        nProgram = m_programOverride.Value();
    CString strPath = FUN_14071a5b0(CString("MusicScore"), strName);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_ImXmlNode* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    int nLast = nTime;
    Unk_MidiTrack track;
    if (m_events.find(nOwner) != m_events.end())
        m_events.erase(nOwner);
    Unk_ImScoreEvents empty;
    m_events[nOwner] = empty;
    Unk_ImScoreEvents* pEvents = &m_events[nOwner];
    unsigned nNow = FUN_140869420();
    bool bFirst = true;
    for (Unk_ImXmlNode* pNode = FUN_140165cf0(pRoot, "harmony"); pNode != 0; pNode = FUN_140168650(pNode, "harmony"))
    {
        CString strChord;
        FUN_1408733e0(pNode, "chord", &strChord);
        strChord.Remove(' ');
        strChord.Remove('\n');
        strChord.Remove('\t');
        int nEnd = ParseLine(nChannel, nProgram, nPercussion, &track, pEvents, nTime, nNow, strChord, bFirst);
        nLast = (std::max)(nLast, nEnd);
        bFirst = false;
    }
    int nElapsed = nLast - nTime;
    int nMin = nElapsed / 1000 / 60;
    int nSec = nElapsed / 1000 % 60;
    if (FUN_14116d720(FUN_14025e7c0()))
        FUN_1412751b0(StringFormat(L"[디버그용] 악보 시간 {0}분 {1}초 ({2} msec)", nMin, nSec, (unsigned long)nElapsed), 0x11);
    if (nPercussion == 0)
    {
        m_midi.SetChannelTrack(nChannel, track);
        CMidiMessage msg;
        msg.ProgramChange(nChannel, nProgram);
        m_midi.SendMessage(nChannel, msg.m_msg);
    }
    else
    {
        m_midi.SetTrack(nKey, track);
    }
    UpdateVolume(true);
    return nLast;
}

// @0x140d092c0
// MS2-FUNCTIONAL: not byte-matched
int CInstrumentManager::PlayScoreText(const CString& strText, int nTime, int nProgram, int nPercussion, int nChannel,
                                      int nKey, unsigned nOwner)
{
    if (m_programOverride.HasValue())
        nProgram = m_programOverride.Value();
    std::vector<CString> lines;
    FUN_1402c8940(strText, lines, ":");
    int nLast = nTime;
    Unk_MidiTrack track;
    if (m_events.find(nOwner) != m_events.end())
        m_events.erase(nOwner);
    Unk_ImScoreEvents empty;
    m_events[nOwner] = empty;
    Unk_ImScoreEvents* pEvents = &m_events[nOwner];
    unsigned nNow = FUN_140869420();
    for (unsigned __int64 i = 0; i < lines.size(); i++)
    {
        int nEnd = ParseLine(nChannel, nProgram, nPercussion, &track, pEvents, nTime, nNow, lines[i], i == 0);
        nLast = (std::max)(nLast, nEnd);
    }
    if (FUN_14116d720(FUN_14025e7c0()))
    {
        int nElapsed = nLast - nTime;
        int nMin = nElapsed / 1000 / 60;
        int nSec = nElapsed / 1000 % 60;
        FUN_1412751b0(StringFormat(L"[디버그용] 악보 시간 {0}분 {1}초 ({2} msec)", nMin, nSec, (unsigned long)nElapsed), 0x11);
    }
    if (nPercussion == 0)
    {
        m_midi.SetChannelTrack(nChannel, track);
        CMidiMessage msg;
        msg.ProgramChange(nChannel, nProgram);
        m_midi.SendMessage(nChannel, msg.m_msg);
    }
    else
    {
        m_midi.SetTrack(nKey, track);
    }
    UpdateVolume(true);
    return nLast;
}

// @0x140d09710
void CInstrumentManager::OnPerformStart(int nOwner, int nStart, int nEnd, bool bRemote)
{
    Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe != 0 && pMe->FUN_14123c580() == nOwner)
    {
        FUN_140d86260()->vfunc_52(m_scoreUid, bRemote == true ? 1 : 0);
        m_performing = true;
        m_remote = bRemote;
        if (pMe->FUN_14166c930() != 0x2f)
        {
            StopPerform();
            return;
        }
        UIPlayInstrumentDialog* pDialog = Unk_ImGetDialog<UIPlayInstrumentDialog>(0x4eec);
        if (pDialog != 0)
            pDialog->FUN_14100d260(nStart, nEnd);
        if (m_remote)
        {
            SetPcState(0x81);
        }
        else
        {
            SetPcState(0x7f);
            Unk_ImAutoPlayPane* pPane;
            if (CanPlayEnsemble() != 0 && (pPane = FUN_140cdee10(0x4f07)) != 0 && pPane->FUN_141924630() == 0)
            {
                pPane->FUN_140fa5ba0(5);
                pPane->FUN_141924680();
            }
        }
    }
    AddRef();
}

// @0x140d098a0
void CInstrumentManager::OnPerformEnd(int nOwner)
{
    Unk_ImActor* pActor = FUN_1403ed2d0()->FUN_141bd1290(nOwner);
    if (pActor != 0)
        pActor->FUN_14165ebb0(1.0f);
    Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe != 0 && pMe->FUN_14123c580() == nOwner)
    {
        FUN_140d86260()->vfunc_53(m_scoreUid, m_remote == true ? 1 : 0);
        m_performing = false;
        m_scoreUid = 0;
        UIPlayInstrumentDialog* pDialog = Unk_ImGetDialog<UIPlayInstrumentDialog>(0x4eec);
        if (pDialog != 0)
            pDialog->FUN_14100d600();
        SetPcState(0x7d);
        m_remote = false;
    }
    Release();
}

// @0x140d099c0
// MS2-FUNCTIONAL: not byte-matched
bool CInstrumentManager::PreviewScore(const CString& strText, int nCategory, int nOffset, int* pnDuration)
{
    MS2Ptr<CInstrumentCategoryData> spCategory = TSingleton<CInstrumentDataTable>::GetInstance()->GetCategory(nCategory);
    if (spCategory == 0)
        return false;
    Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return false;
    int nProgram = spCategory->m_nGMId;
    Voice voice;
    voice.m_channel = 0;
    voice.m_owner = pMe->FUN_14123c580();
    voice.m_position = pMe->vfunc_18();
    voice.m_program = nProgram;
    voice.m_percussion = spCategory->m_nPercussionId;
    int nSlot = GetSlot(0, voice);
    unsigned nNow = FUN_140869420();
    unsigned nEnd = PlayScoreText(strText, nNow - nOffset, nProgram, voice.m_percussion, nSlot, 0, pMe->FUN_14123c580());
    *pnDuration = nEnd - (nNow - nOffset);
    if (nEnd > nNow)
        return true;
    return false;
}

// @0x140d09bc0
void CInstrumentManager::StopPreview()
{
    int nSlot = FindSlot(0);
    if (nSlot == 0x10)
        return;
    ResetChannel(nSlot, 0);
    RemoveSlot(0);
}

// @0x140d09c10
void CInstrumentManager::SendCompose(void* pScore)
{
    COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
    packet.Encode1(8);
    FUN_1401ffdc0(pScore, &packet);
    FUN_140710590(packet);
}

bool FUN_1407105c0(COutPacket& packet, int nCount, int nMs);                // throttled send

// @0x140d09c80
void CInstrumentManager::SendScoreText(__int64 nItemUid)
{
    COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
    packet.Encode1(10);
    packet.Encode8(nItemUid);
    FUN_1407105c0(packet, 10, 3000);
}

// @0x140d09cf0
void CInstrumentManager::AddFlags(unsigned nFlags)
{
    if ((m_flags & nFlags) == nFlags)
        return;
    m_flags |= nFlags;
    AddRef();
}

// @0x140d09d40
void CInstrumentManager::RemoveFlags(unsigned nFlags)
{
    if ((m_flags & nFlags) == nFlags)
    {
        Release();
        m_flags &= ~nFlags;
    }
}

// @0x140d09d90
bool CInstrumentManager::HasOtherFlags(unsigned nFlags)
{
    if (m_flags == 0)
        return false;
    if ((m_flags & ~nFlags) != 0)
        return true;
    return false;
}

// @0x140d09dd0
bool CInstrumentManager::IsBlocked(int nOwner)
{
    Unk_ImActor* pActor = FUN_1403ed2d0()->FUN_141bd1290(nOwner);
    if (pActor == 0)
        return false;
    CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4880(pActor->FUN_141656a80());
    if (spBuddy == 0)
        return false;
    if (spBuddy->FUN_1401cc5b0() == 0)
        return false;
    return true;
}

// @0x140d09eb0
void CInstrumentManager::Clear()
{
    if (!m_midi.IsOpen())
        return;
    for (std::map<unsigned, int>::iterator it = m_slotIndex.begin(), itEnd = m_slotIndex.end(); it != itEnd; ++it)
    {
        ResetChannel(it->second, it->first);
        m_events.erase(reinterpret_cast<unsigned&>(m_slots[it->second].m_owner));
        m_slots[it->second].Init();
    }
    m_remoteVoices.clear();
    m_refs = 0;
    m_flags = 0;
    m_slotIndex.clear();
    m_events.clear();
    m_midi.StopTimer();
}

// @0x140d0a030
void CInstrumentManager::ResetChannel(int nSlot, int nKey)
{
    if (nSlot == 9)
        m_midi.RemoveTrack(nKey);
    else
        m_midi.ClearChannel(nSlot);
}

// @0x140d0a080
int CInstrumentManager::FindSlot(unsigned nKey)
{
    int nSlot = 0x10;
    std::map<unsigned, int>::iterator it = m_slotIndex.find(nKey);
    if (it != m_slotIndex.end())
        nSlot = it->second;
    return nSlot;
}

// @0x140d0a100
int CInstrumentManager::GetSlot(unsigned nKey, Voice& voice)
{
    int nSlot = 0x10;
    std::map<unsigned, int>::iterator it = m_slotIndex.find(nKey);
    if (it != m_slotIndex.end())
        nSlot = it->second;
    else
        nSlot = AllocSlot(nKey, voice);
    return nSlot;
}

// @0x140d0a1a0
int CInstrumentManager::AllocSlot(int nKey, Voice& voice)
{
    int nSlot = 0x10;
    if (voice.IsRemote())
    {
        RemoteVoice remote;
        remote.Assign(voice);
        nSlot = AddRemote(nKey, remote);
        return nSlot;
    }
    if (nKey == 0)
    {
        nSlot = 0;
    }
    else
    {
        for (int i = 0; i <= 0xb; i++)
        {
            if (i == 0)
                continue;
            if (i == 9)
                continue;
            if (m_slots[i].m_used == true)
                continue;
            nSlot = i;
            break;
        }
    }
    if (nSlot == 0x10)
        return nSlot;
    Slot slot;
    slot.Assign(voice);
    m_slots[nSlot] = slot;
    m_slots[nSlot].m_used = true;
    MapSlot(nKey, nSlot);
    return nSlot;
}

// @0x140d0a310
int CInstrumentManager::AddRemote(int nKey, RemoteVoice& voice)
{
    int nSlot = 9;
    m_remoteVoices.insert(std::make_pair(nKey, voice));
    MapSlot(nKey, nSlot);
    return nSlot;
}

// @0x140d0a380
void CInstrumentManager::MapSlot(int nKey, int nSlot)
{
    m_slotIndex.insert(std::make_pair(nKey, nSlot));
    m_midi.StartTimer();
}

// @0x140d0a3e0
void CInstrumentManager::RemoveSlot(unsigned nKey)
{
    std::map<unsigned, int>::iterator it = m_slotIndex.find(nKey);
    if (it != m_slotIndex.end() && it->second < 0x10)
    {
        m_events.erase(reinterpret_cast<unsigned&>(m_slots[it->second].m_owner));
        m_slots[it->second].Init();
        m_remoteVoices.erase(nKey);
        m_slotIndex.erase(nKey);
    }
    if (m_slotIndex.empty())
        m_midi.StopTimer();
}

// @0x140d0a510
void CInstrumentManager::Mute()
{
    m_muted = true;
    if (!m_midi.IsOpen())
        return;
    UpdateVolume(true);
}

// @0x140d0a560
void CInstrumentManager::Unmute()
{
    m_muted = false;
    if (!m_midi.IsOpen())
        return;
    UpdateVolume(true);
}

// @0x140d0a5b0
// MS2-FUNCTIONAL: not byte-matched
void CInstrumentManager::UpdateVolume(bool bForce)
{
    if (!m_midi.IsOpen())
        return;
    Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    for (int i = 0; i < 0x10; i++)
    {
        if (!m_slots[i].m_used || i == 9)
            continue;
        int nVolume = FUN_141260310(TSingleton<CGameOption>::GetInstance()->FUN_140d13c70());
        if (m_muted)
        {
            nVolume = 0;
        }
        else if (IsBlocked(m_slots[i].m_owner) == true)
        {
            nVolume = 0;
        }
        else if (FUN_1403ed2d0()->FUN_141bcb150() != true)
        {
            Vector3* pPos = &m_slots[i].m_position;
            float fDistance = pMe->vfunc_18().FUN_140965c40(*pPos).FUN_140967ac0();
            Client::Constants* pConst = Client::Constants::GetInstance();
            if (*pConst->MusicListenInRadius.Get() <= fDistance)
            {
                if (fDistance <= *Client::Constants::GetInstance()->MusicListenOutRadius.Get())
                {
                    float fOut = *Client::Constants::GetInstance()->MusicListenOutRadius.Get();
                    float fIn = *Client::Constants::GetInstance()->MusicListenInRadius.Get();
                    float fRange = fOut - fIn;
                    float fRatio = (fRange - (fDistance - *Client::Constants::GetInstance()->MusicListenInRadius.Get())) / fRange;
                    nVolume = (int)((float)nVolume * fRatio);
                }
                else
                {
                    nVolume = 0;
                }
            }
        }
        if (bForce || m_slots[i].m_volume != nVolume)
        {
            m_slots[i].m_volume = nVolume;
            CMidiMessage msg;
            msg.FUN_140d75600(i, ScaleVolume(nVolume, m_slots[i].m_program));
            m_midi.SendMessage(i, msg.m_msg);
        }
    }
    if (m_remoteVoices.size() != 0)
    {
        int nVolume = FUN_141260310(TSingleton<CGameOption>::GetInstance()->FUN_140d13c70());
        if (m_muted)
            nVolume = 0;
        if (bForce == true || m_slots[9].m_volume != nVolume)
        {
            m_slots[9].m_volume = nVolume;
            CMidiMessage msg;
            msg.FUN_140d75600(9, nVolume);
            m_midi.SendMessage(9, msg.m_msg);
        }
        for (std::map<unsigned, RemoteVoice>::iterator it = m_remoteVoices.begin(); it != m_remoteVoices.end(); ++it)
        {
            RemoteVoice* pVoice = &it->second;
            bool bActive = true;
            Unk_ImActor* pActor = FUN_1403ed2d0()->FUN_141bd1290(pVoice->m_owner);
            if (pActor != 0)
            {
                CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4880(pActor->FUN_141656a80());
                if (spBuddy.get() != 0 && spBuddy->FUN_1401cc5b0() != 0)
                    bActive = false;
            }
            if (!FUN_1403ed2d0()->FUN_141bcb150())
            {
                float fDistance = pMe->vfunc_18().FUN_140965c40(pVoice->m_position).FUN_140967ac0();
                float* pfIn = Client::Constants::GetInstance()->MusicListenInRadius.Get();
                float fLimit = (*pfIn + *Client::Constants::GetInstance()->MusicListenOutRadius.Get()) / 2.0f;
                if (fDistance > fLimit)
                    bActive = false;
            }
            if (pVoice->m_active != bActive)
            {
                pVoice->m_active = bActive;
                m_midi.SetTrackEnabled(it->first, bActive);
            }
        }
    }
}

// @0x140d0ac40
int CInstrumentManager::ScaleVolume(int nVolume, int nProgram)
{
    if (nProgram >= 0x40 && nProgram <= 0x4f)
        return (int)((float)nVolume * 0.8f);
    return nVolume;
}

// @0x140d0ac80
void CInstrumentManager::PlayEvents()
{
    unsigned nNow = FUN_140869420();
    std::map<unsigned, Unk_ImScoreEvents>::iterator it = m_events.begin();
    std::map<unsigned, Unk_ImScoreEvents>::iterator itEnd = m_events.end();
    while (it != itEnd)
    {
        Unk_ImActor* pActor = FUN_1403ed2d0()->FUN_141bd1290(it->first);
        if (pActor == 0)
        {
            std::map<unsigned, Unk_ImScoreEvents>::iterator itErase = it;
            ++it;
            m_events.erase(itErase);
            continue;
        }
        Unk_ImScoreEvents::iterator itEvent = it->second.begin();
        Unk_ImScoreEvents::iterator itEventEnd = it->second.end();
        for (; itEvent != itEventEnd; ++itEvent)
        {
            if (itEvent->first > nNow)
                break;
            std::pair<int, int>* pEvent = &itEvent->second;
            if (pActor->FUN_14166c930() != 0x2f)
                return;
            if (pEvent->first == 0)
            {
                float fTempo = (float)pEvent->second / 120.0f;
                pActor->FUN_14165ebb0(fTempo);
            }
            else if (pEvent->first == 1)
            {
                StatePlayInstrument* pState = pActor->FUN_14166ccb0();
                pState->FUN_140de0410(pEvent->second);
            }
        }
        if (itEvent != it->second.begin())
            it->second.erase(it->second.begin(), itEvent);
        ++it;
    }
}

// @0x140d0af00
void CInstrumentManager::AddRef()
{
    m_refs++;
    if (m_refs == 1 && TSingleton<CGameOption>::GetInstance()->FUN_140d13c70()->m_b30 == true)
        TSingleton<CSoundEventMgr>::GetInstance()->FUN_14177dea0(2, 300);
    UpdateVolume(false);
}

// @0x140d0af70
void CInstrumentManager::Release()
{
    m_refs--;
    if (m_refs < 0)
        m_refs = 0;
    if (m_refs > m_refs)
        m_refs = m_refs;
    FUN_14125fe20(TSingleton<CGameOption>::GetInstance()->FUN_140d13c70());
    if (m_refs == 0 && TSingleton<CGameOption>::GetInstance()->FUN_140d13c70()->m_b30 == true)
        TSingleton<CSoundEventMgr>::GetInstance()->FUN_14177ddf0(2, 5000);
    UpdateVolume(false);
}

// @0x140d0b030
void CInstrumentManager::CheckPlayState()
{
    Unk_ImActor* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    if (pMe->FUN_14166c930() != 0x2f)
        return;
    if (pMe->FUN_14166cc80() == 0x80)
    {
        StopEnsemble();
    }
    else
    {
        UIPlayInstrumentDialog* pDialog = Unk_ImGetDialog<UIPlayInstrumentDialog>(0x4eec);
        if (pDialog != 0)
            pDialog->FUN_14100e9a0(pDialog->GetMode());
    }
}

// @0x140d0b0c0
int CInstrumentManager::GetVolume() { return m_volume; }

// @0x140d0b0e0
void CInstrumentManager::SetVolume(int nVolume)
{
    m_volume = nVolume;
    Unk_ImAutoPlayPane* pPane = FUN_140cdee10(0x4f07);
    if (pPane != 0)
        pPane->FUN_140fa64e0();
}

// ---- inline COMDATs first emitted here ----

// @0x140d11940
Unk_ImNullableInt::Unk_ImNullableInt() : m_isValueSet(false) {}

// @0x140d123b0
CMidiMessage::CMidiMessage() : m_unk8(0), m_msg(0) {}

// @0x140d123f0
CInstrumentManager::RemoteVoice::RemoteVoice() { Init(); }

// @0x140d12420
CInstrumentManager::Voice::Voice() { Reset(); }

// @0x140d12450
CInstrumentManager::Slot::Slot() { Init(); }

// @0x140d13c40
CSoundEventMgr* TSingleton<CSoundEventMgr>::GetInstance() { return s_instance; }

// @0x140d13c50
int UIPlayInstrumentDialog::GetMode() { return m_nMode; }

// @0x140d13c70
Unk_SoundState* CGameOption::FUN_140d13c70() { return &m_sound; }

// @0x140d13c90
bool CInstrumentManager::Voice::IsRemote() const { return m_percussion != 0; }

// @0x140d13d80
void UIPlayInstrumentDialog::SetInstrument(int nInstrument) { m_nInstrument = nInstrument; }

// @0x140d1a9d0
bool Unk_ImNullableInt::HasValue() const { return m_isValueSet; }

// @0x140d1acd0
int& Unk_ImNullableInt::Value()
{
    (void)((!!m_isValueSet) || (_wassert(L"m_isValueSet", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\nullable.h", 0x41), 0));
    return m_value;
}
// fx25: the const _Eqrange (0x140d0cd50) builds its pair<const_iterator,const_iterator> via the look-alike 0x140d0b3a0 (the table maps it with the iterator twin 0x140d0b4e0)
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$multimap@IU?$pair@HH@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIU?$pair@HH@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$multimap@IU?$pair@HH@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIU?$pair@HH@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$multimap@IU?$pair@HH@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIU?$pair@HH@std@@@std@@@2@@std@@@std@@@std@@@std@@@1@0@Z 0x140d0b3a0
