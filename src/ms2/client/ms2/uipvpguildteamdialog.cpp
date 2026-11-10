// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPvPGuildTeamDialog: see uipvpguildteamdialog.h.
// MS2-UNIT: ?\uipvpguildteamdialog.cpp
// MS2-RANGE: 0x141339640-0x1413405b0 .text$mn
// MS2-RANGE: 0x1400ef900-0x1400efc20 .text$di
// MS2-RANGE: 0x142cb00b0-0x142cb0210 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEA_J@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@_JV?$MS2Ptr@VASUIComponent@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VASUIComponent@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VASUIComponent@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEA_J@1@$$QEAV?$tuple@$$V@1@@Z 0x14133ca20 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEB_J@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@_JV?$MS2Ptr@VASUIComponent@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VASUIComponent@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_JV?$MS2Ptr@VASUIComponent@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEB_J@1@$$QEAV?$tuple@$$V@1@@Z 0x14133caf0 ; unique
// MS2-PIN: ??$_Try_emplace@AEB_J$$V@?$map@_JV?$MS2Ptr@VASUIComponent@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VASUIComponent@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$MS2Ptr@VASUIComponent@@@@@std@@@std@@@std@@@std@@_N@1@AEB_J@Z 0x14133e0b0 ; unique
// MS2-PIN: ??$try_emplace@$$V@?$map@_JV?$MS2Ptr@VASUIComponent@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VASUIComponent@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$MS2Ptr@VASUIComponent@@@@@std@@@std@@@std@@@std@@_N@1@$$QEA_J@Z 0x14133e760 ; unique
// MS2-PIN: ??A?$map@_JV?$MS2Ptr@VASUIComponent@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$MS2Ptr@VASUIComponent@@@@@std@@@3@@std@@QEAAAEAV?$MS2Ptr@VASUIComponent@@@@$$QEA_J@Z 0x14133ed30 ; unique
// MS2-PIN: ?vfunc_48@UIPvPGuildTeamDialog@@UEAAHXZ 0x14133f180 ; unique
// MS2-PIN: ??__Es_keyInputController@@YAXXZ 0x1400efa70 ; manual (look-alike of the ATL module initializers)
// MS2-PIN: ??__Es_keyInputController2@@YAXXZ 0x1400efbf0 ; manual
// MS2-PIN: ??__Fs_keyInputController@@YAXXZ 0x142cb0140 ; manual
// MS2-PIN: ??__Fs_keyInputController2@@YAXXZ 0x142cb01f0 ; manual
// MS2-PIN: ?data@?$SmartPointer@VMyPC@@@efd@@QEBAPEAVMyPC@@XZ 0x14133ede0 ; manual
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it). The COMDAT tail: the uiswfentity.inl child
// lookup for ASUIComponent, map<__int64, MS2Ptr<ASUIComponent>>, the round info's vector<__int64> helpers and one
// AScript::Invoke overload.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipvpguildteamdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uipvpguildteamdialog.h"

#include <efd/SmartPointer.h>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/fittingdollpc.h"   // C3: PC::FUN_141654730/FUN_141656be0
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce090
#include "ms2/placeholder/cproxygameobject.h"  // C3: UIPopUpMenu::FUN_141a7eb60 takes MS2Ptr<CProxyGameObject>
class UIMassiveEvent { public: void FUN_1419f6a70(int, class ATL::CStringT<wchar_t, class StrTraitMFC_DLL<wchar_t, class ATL::ChTraitsCRT<wchar_t>>>, int); };
// ---- header statics (dynamic initializers 0x1400ef900..) ----
#ifndef MS2_HOOK_DLL
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
#endif
static CString s_strSemiLose = "GuildBattle_SemiLose";             // the result sounds
static CString s_strSemiWin = "GuildBattle_SemiWin";
static CString s_strWinGame = "PC_win_game";
#ifndef MS2_HOOK_DLL
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInputController2;
#endif

// ---- unit-local views of exe types ----

class Unk_PgtWorld                                                  // the world service
{
public:
    MyPC* FUN_141bd0cc0();                                          // the local player
    // FUN_141bc9d60 (the proxy of a visible character by name, the popup menu target): WorldService's own member
};

class Unk_PgtGuildSvc                                               // the guild service: the own guild at +8
{
public:
    void* m_pad_00;
    CGuildInfo m_info;
};

struct Unk_PgtConfig
{
    char m_pad_00[0xa0];
    CString m_strMarkServer;                                        // +0xa0 passed to the guild mark URL builder
};
class Unk_SingletonObj* GetCommonResource();   // C3: was GetCommonResource

// C3: Unk_140acd6e0 (the button view) is ASButton itself.
//
//
//
//

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

class Unk_RewardOtherDialog : public UIDialog { public: void FUN_1419f6a70(int nType, CStringW strText, int nTime); };
class UIMassiveEvent* FUN_140e01890(int);   // C3: was FUN_140e01890

class Unk_PopupMenuInfo
{
public:
    Unk_PopupMenuInfo(float x, float y, int a, int b, int c, CString str, void* p);
    ~Unk_PopupMenuInfo();
private:
    // 0x80 bytes as scalars (an array would add a /GS cookie the exe's frame lacks)
    void* m_00; void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40;
    void* m_48; void* m_50; void* m_58; void* m_60; void* m_68; void* m_70; void* m_78;
};
class Unk_PopupMenu;
class UIPopUpMenu
{
public:
    void FUN_141a7eb60(const Unk_PopupMenuInfo& info, MS2Ptr<CProxyGameObject> spProxy, int nType);
};
Unk_PopupMenu* FindPopupMenu(int nUiId);

void SetChildText(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
CStringW FUN_140719630(int n);                                      // the number as text
CStringW GetStringCommon(int nStringId);
int FUN_141276180(const CString& strSound, const CString& strArg); // play a UI sound
int GetServerTick();   // C3: was GetServerTick
int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4);
bool FUN_141b70f50(const CStringW& a, const CStringW& b);           // the names are equal
CString FUN_14016a600(const wchar_t* sz, int nCodePage);
CStringW FUN_14016a730(const char* sz, int nCodePage);
CString FUN_141029590(unsigned __int64 nId, const CString& strKey, const CString& strName, CString strExtra);
MS2Ptr<ASDisplayObjectContainer> CreateDisplayObjectContainer(int nMovieId, const Scaleform::GFx::Value& v);
template <class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);

// The recursive getChildByName of uiswfentity.inl.
class Unk_ASChildFinder : public ASDisplayObjectContainer
{
public:
    template <class T> MS2Ptr<T> FindButton(const CString& strName);
    template <class T> MS2Ptr<T> FUN_14133c5f0(const Scaleform::GFx::Value& v, const CString& strName);
};

#define UIPVPGUILDTEAM_INL_ASSERT_0()                                                                              \
    (void)((!!(0)) || (_wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\uiswfentity.inl", 23), 0))

// @0x141339640
UIPvPGuildTeamDialog::UIPvPGuildTeamDialog()
{
    SetTweenEnabled(0);
    SetFlag(0, 1);
}

// @0x141339780
UIPvPGuildTeamDialog::~UIPvPGuildTeamDialog()
{
}

// @0x141339880
CString UIPvPGuildTeamDialog::GetTypeName()
{
    return "PvPGuildTeamDialog";
}
MS2_REPLACE_METHOD(0x141339880, UIPvPGuildTeamDialog, GetTypeName, 61, 0x9135AD1C);

// @0x1413398d0
int UIPvPGuildTeamDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1413398D0, UIPvPGuildTeamDialog, vfunc_65, 37, 0x4ECE15AC);

// @0x141339900
void UIPvPGuildTeamDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    pPC->StopObserving();
}
MS2_REPLACE_METHOD(0x141339900, UIPvPGuildTeamDialog, vfunc_67, 62, 0xA2383290);

// @0x141339950
void UIPvPGuildTeamDialog::vfunc_72()
{
    unsigned nNow = GetServerTick();
    if (m_nEndTime < nNow)
        return;
    FUN_14133b900(m_nEndTime);
}
MS2_REPLACE_METHOD(0x141339950, UIPvPGuildTeamDialog, vfunc_72, 63, 0xCE747CCF);

// @0x1413399a0
void UIPvPGuildTeamDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_1f0 = 0;
    m_spComponent = FUN_141926e30<ASUIComponent>("m_pvpGuildTeamComponent");
    if (m_spComponent == 0)
        return;
    for (int i = 0; i < 3; i++) {
        CString strLeft = StringFormat<int>("m_leftPlayer{0}", i + 1);
        m_spLeftPlayers[i] = m_spComponent->FUN_140accfb0<ASUIComponent>(strLeft);
        CString strRight = StringFormat<int>("m_rightPlayer{0}", i + 1);
        m_spRightPlayers[i] = m_spComponent->FUN_140accfb0<ASUIComponent>(strRight);
    }
    if (m_info.m_nGuildIdA != 0)
        FUN_14133a4a0(m_info);
    if (m_round.m_nRound != 0) {
        ShowRound(m_round);
        m_round.Reset();
    }
}
MS2_REPLACE_METHOD(0x1413399A0, UIPvPGuildTeamDialog, OnLoadComplete, 673, 0x832E2D90);

// @0x141339c50
void UIPvPGuildTeamDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_spComponent = 0;
    for (int i = 0; i < 3; i++) {
        m_spLeftPlayers[i] = 0;
        m_spRightPlayers[i] = 0;
    }
    m_slots.clear();
}
MS2_REPLACE_METHOD(0x141339C50, UIPvPGuildTeamDialog, vfunc_26, 157, 0x09D09D57);

// @0x141339d00
void UIPvPGuildTeamDialog::vfunc_79(void* pData)
{
    UIDialog::vfunc_79(pData);
    if (((CInPacket*)pData)->FUN_14070fe80() != 0x9a)
        return;
    int nType = (unsigned char)((CInPacket*)pData)->ReadUInt8();
    if (nType == 's') {
        Unk_PvPGuildRoundInfo info;
        info.m_nRound = ((CInPacket*)pData)->ReadInt32();
        info.m_nEndTime = ((CInPacket*)pData)->ReadInt32();
        int nUnused = ((CInPacket*)pData)->ReadInt32();
        int nCount = ((CInPacket*)pData)->ReadInt32();
        info.m_characters.reserve(nCount);
        for (int i = 0; i < nCount; i++) {
            __int64 nCharId = ((CInPacket*)pData)->ReadInt64();
            info.m_characters.push_back(nCharId);
        }
        info.m_scoreA.m_nGuildId = ((CInPacket*)pData)->ReadInt64();
        info.m_scoreA.m_nScore = ((CInPacket*)pData)->ReadInt32();
        info.m_scoreB.m_nGuildId = ((CInPacket*)pData)->ReadInt64();
        info.m_scoreB.m_nScore = ((CInPacket*)pData)->ReadInt32();
        ShowRound(info);
    }
    else if (nType == 't') {
        __int64 nWinner = ((CInPacket*)pData)->ReadInt64();
        if (nWinner == 0) {
            Unk_RewardOtherDialog* pDlg = ((class Unk_RewardOtherDialog*)FUN_140e01890(0x4e4c));
            if (pDlg != 0)
                ((class UIMassiveEvent*)(((class UIMassiveEvent*)(pDlg))))->FUN_1419f6a70(4, GetStringCommon(0x3fc), 4000);
        }
        else if (nWinner == reinterpret_cast<Unk_PgtGuildSvc*>(TSingleton<CGuildManager>::GetInstance())->m_info.GetGuildId()) {
            Unk_RewardOtherDialog* pDlg = ((class Unk_RewardOtherDialog*)FUN_140e01890(0x4e4c));
            if (pDlg != 0) {
                ((class UIMassiveEvent*)(((class UIMassiveEvent*)(pDlg))))->FUN_1419f6a70(2, GetStringCommon(0x3fd), 4000);
                FUN_141276180(s_strWinGame, "");
                FUN_141276180(s_strSemiWin, "");
            }
        }
        else {
            Unk_RewardOtherDialog* pDlg = ((class Unk_RewardOtherDialog*)FUN_140e01890(0x4e4c));
            if (pDlg != 0) {
                ((class UIMassiveEvent*)(((class UIMassiveEvent*)(pDlg))))->FUN_1419f6a70(0, GetStringCommon(0x3fe), 4000);
                FUN_141276180(s_strSemiLose, "");
            }
        }
        StopObserving();
    }
}
MS2_REPLACE_METHOD(0x141339D00, UIPvPGuildTeamDialog, vfunc_79, 1285, 0x3522EB7A);

// @0x14133a210
void UIPvPGuildTeamDialog::FUN_14133a210(CInPacket* pPacket)
{
    m_info.m_nGuildIdA = pPacket->ReadInt64();
    m_info.m_strNameA = pPacket->ReadUnicodeString();
    m_info.m_strMarkA = pPacket->ReadUnicodeString();
    m_info.m_nGuildIdB = pPacket->ReadInt64();
    m_info.m_strNameB = pPacket->ReadUnicodeString();
    m_info.m_strMarkB = pPacket->ReadUnicodeString();
    if (m_30 == 0)
        return;
    FUN_14133a4a0(m_info);
}
MS2_REPLACE_METHOD(0x14133A210, UIPvPGuildTeamDialog, FUN_14133a210, 644, 0xF1814EFA);

// @0x14133a4a0
void UIPvPGuildTeamDialog::FUN_14133a4a0(const Unk_PvPGuildTeamInfo& info)
{
    if (IsOwnGuildId(info.m_nGuildIdA)) {
        SetChildText(FUN_1422dbc00(), "m_leftGuildName", info.m_strNameA);
        SetChildText(FUN_1422dbc00(), "m_rightGuildName", info.m_strNameB);
    }
    else {
        SetChildText(FUN_1422dbc00(), "m_leftGuildName", info.m_strNameB);
        SetChildText(FUN_1422dbc00(), "m_rightGuildName", info.m_strNameA);
    }
    SetGuildMark(info.m_nGuildIdA, info.m_strMarkA);
    SetGuildMark(info.m_nGuildIdB, info.m_strMarkB);
}
MS2_REPLACE_METHOD(0x14133A4A0, UIPvPGuildTeamDialog, FUN_14133a4a0, 756, 0x0A595080);

// @0x14133a7a0
void UIPvPGuildTeamDialog::ShowRound(const Unk_PvPGuildRoundInfo& info)
{
    if (m_30 == 0) {
        m_round = info;
        return;
    }
    CStringW strRound = StringFormat(L"ROUND {0}", info.m_nRound);
    SetChildText(FUN_1422dbc00(), "m_roundText", strRound);
    m_nEndTime = info.m_nEndTime;
    FUN_14133b900(m_nEndTime);
    for (int i = 0; i < 3; i++) {
        if (m_spLeftPlayers[i].get() != 0)
            m_spLeftPlayers[i]->Invoke("hideInfo");
        if (m_spRightPlayers[i].get() != 0)
            m_spRightPlayers[i]->Invoke("hideInfo");
    }
    m_slots.clear();
    if (m_nEndTime != 0) {
        int nLeft = 0;
        int nRight = 0;
        __int64 nMyCharId = 0;
        efd::SmartPointer<MyPC> spPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (spPC.data() != 0)
            nMyCharId = ((class PCBase*)(class PCBase*)(spPC.operator->()))->FUN_141656a80();
        bool bPlaying = false;
        for (size_t i = 0; i < info.m_characters.size(); i++) {
            if (info.m_characters[i] != 0 && info.m_characters[i] == nMyCharId)
                bPlaying = true;
        }
        for (size_t i = 0; i < info.m_characters.size(); i++) {
            const __int64& nCharId = info.m_characters[i];
            PCBase* pPC = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(nCharId));
            if (pPC == 0)
                continue;
            if (IsOwnGuildName(reinterpret_cast<PC*>(pPC)->GetGuildName())) {
                if (nLeft >= 3)
                    continue;
                FillPlayerSlot(m_spLeftPlayers[nLeft], pPC, bPlaying);
                nLeft++;
            }
            else {
                if (nRight >= 3)
                    continue;
                FillPlayerSlot(m_spRightPlayers[nRight], pPC, bPlaying);
                nRight++;
            }
        }
    }
    else {
        m_spComponent->Invoke("clearTime");
    }
    if (IsOwnGuildId(info.m_scoreA.m_nGuildId)) {
        SetChildText(FUN_1422dbc00(), "m_leftGuildScore", FUN_140719630(info.m_scoreA.m_nScore));
        SetChildText(FUN_1422dbc00(), "m_rightGuildScore", FUN_140719630(info.m_scoreB.m_nScore));
    }
    else {
        SetChildText(FUN_1422dbc00(), "m_leftGuildScore", FUN_140719630(info.m_scoreB.m_nScore));
        SetChildText(FUN_1422dbc00(), "m_rightGuildScore", FUN_140719630(info.m_scoreA.m_nScore));
    }
}
MS2_REPLACE_METHOD(0x14133A7A0, UIPvPGuildTeamDialog, ShowRound, 2054, 0x9313CBEC);

// @0x14133afb0
void UIPvPGuildTeamDialog::FUN_14133afb0(unsigned __int64 nCharId, __int64 nHp, __int64 nMaxHp)
{
    if (m_slots.find(nCharId) == m_slots.end())
        return;
    MS2Ptr<ASUIComponent> spSlot = m_slots[nCharId];
    spSlot->Invoke("setHpBar", nHp, nMaxHp);
}
MS2_REPLACE_METHOD(0x14133AFB0, UIPvPGuildTeamDialog, FUN_14133afb0, 250, 0xC4868C3B);

// @0x14133b0b0
void UIPvPGuildTeamDialog::ClearObservedPlayer()
{
    m_strObserved = "";
    UpdateObserveButtons(0);
}
MS2_REPLACE_METHOD(0x14133B0B0, UIPvPGuildTeamDialog, ClearObservedPlayer, 53, 0x7C50C4B6);

// @0x14133b0f0
void UIPvPGuildTeamDialog::SetGuildMark(__int64 nGuildId, const CStringW& strMark)
{
    if (!m_30)
        return;
    if (nGuildId == 0)
        return;
    if (m_info.m_nGuildIdA != nGuildId && m_info.m_nGuildIdB != nGuildId)
        return;
    CStringW strUrl;
    strUrl = FUN_14016a730(FUN_141029590(nGuildId, FUN_14016a600(strMark, 0), "", ((struct Unk_PgtConfig*)GetCommonResource())->m_strMarkServer), 0);
    if (IsOwnGuildId(nGuildId))
        m_spComponent->Invoke("setLeftGuildMark", strUrl);
    else
        m_spComponent->Invoke("setRightGuildMark", strUrl);
}
MS2_REPLACE_METHOD(0x14133B0F0, UIPvPGuildTeamDialog, SetGuildMark, 755, 0x71123AE4);

// @0x14133b3f0
int UIPvPGuildTeamDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("onObserve", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            CStringW strName = data.FUN_1422b8f40();
            if (FUN_141b70f50(strName, m_strObserved))
                StopObserving();
            else
                ObservePlayer(strName);
            return 1;
        }
        return 1;
    }
    else if (_stricmp("OnGuildMemberPopupMenu", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            float x = data.PopFloat();
            float y = data.PopFloat();
            CStringW strName = data.FUN_1422b8f40();
            Unk_PopupMenu* pMenu = FindPopupMenu(0x4e39);
            if (pMenu != 0) {
                MS2Ptr<CProxyGameObject> spTarget = WorldService::GetInstance()->FindProxyObjectByName(strName);
                if (spTarget.get() != 0) {
                    Unk_PopupMenuInfo info(x, y, 3, 0x3f3fe, 1, "", NULL);
                    reinterpret_cast<UIPopUpMenu*>(pMenu)->FUN_141a7eb60(info, spTarget, 0xb);
                }
            }
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14133B3F0, UIPvPGuildTeamDialog, vfunc_28, 888, 0xB3BD732E);

// @0x14133b780
void UIPvPGuildTeamDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(1, 0, 0x1e);
}

// @0x14133b830
bool UIPvPGuildTeamDialog::IsOwnGuildName(CStringW strGuildName)
{
    if (strGuildName == reinterpret_cast<Unk_PgtGuildSvc*>(TSingleton<CGuildManager>::GetInstance())->m_info.GetGuildName())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14133B830, UIPvPGuildTeamDialog, IsOwnGuildName, 138, 0x70BF04D1);

// @0x14133b8c0
bool UIPvPGuildTeamDialog::IsOwnGuildId(__int64 nGuildId)
{
    if (nGuildId == reinterpret_cast<Unk_PgtGuildSvc*>(TSingleton<CGuildManager>::GetInstance())->m_info.GetGuildId())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14133B8C0, UIPvPGuildTeamDialog, IsOwnGuildId, 49, 0x684ADF7F);

// @0x14133b900
void UIPvPGuildTeamDialog::FUN_14133b900(unsigned nEndTime)
{
    if (GetServerTick() > nEndTime) {
        CStringW strTime(L"0000");
        m_spComponent->Invoke("setTime", strTime);
    }
    else {
        unsigned nRemain = nEndTime - GetServerTick();
        int nSec = nRemain / 1000;
        int nMin = nSec / 60;
        int nRest = nSec % 60;
        CStringW strTime;
        strTime.Format(L"%02d%02d", nMin, nRest);
        m_spComponent->Invoke("setTime", strTime);
    }
}
MS2_REPLACE_METHOD(0x14133B900, UIPvPGuildTeamDialog, FUN_14133b900, 423, 0xE91E54AA);

// @0x14133bab0
void UIPvPGuildTeamDialog::FillPlayerSlot(MS2Ptr<ASUIComponent> spSlot, PCBase* pPC, bool bPlaying)
{
    m_slots[((class PCBase*)(class PCBase*)(pPC))->FUN_141656a80()] = spSlot;
    const CStringW& strName = pPC->vfunc_77();
    int nLevel = reinterpret_cast<PC*>(pPC)->GetSubJob();
    __int64 nHp = pPC->FUN_141670a00(4);
    __int64 nMaxHp = pPC->FUN_141670a30(4);
    spSlot->Invoke("showCharInfo", strName, FUN_140719630(nLevel), nHp, nMaxHp);
    int bObserved = 0;
    if (FUN_141b70f50(strName, m_strObserved))
        bObserved = 1;
    MS2Ptr<ASButton> spButton = spSlot->FUN_140acce30<ASButton>("m_observeButton");
    if (spButton == 0)
        return;
    if (bPlaying) {
        reinterpret_cast<ASMovieClip*>(spButton.operator->())->SetEnabled(0);
    }
    else {
        reinterpret_cast<ASMovieClip*>(spButton.operator->())->SetEnabled(1);
        reinterpret_cast<ASButton*>(spButton.operator->())->SetSelected(bObserved);
    }
}
MS2_REPLACE_METHOD(0x14133BAB0, UIPvPGuildTeamDialog, FillPlayerSlot, 710, 0x4FB65197);

// @0x14133bd80
void UIPvPGuildTeamDialog::ObservePlayer(CStringW strName)
{
    efd::SmartPointer<MyPC> spPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (spPC == 0)
        return;
    m_strObserved = strName;
    PCBase* pTarget = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1420(m_strObserved));
    if (pTarget == 0) {
        StopObserving();
        return;
    }
    spPC->StartObserving(pTarget);
    UpdateObserveButtons(pTarget);
}
MS2_REPLACE_METHOD(0x14133BD80, UIPvPGuildTeamDialog, ObservePlayer, 304, 0x8BA07BA2);

// @0x14133bec0
void UIPvPGuildTeamDialog::StopObserving()
{
    efd::SmartPointer<MyPC> spPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (spPC == 0)
        return;
    m_strObserved = "";
    spPC->StopObserving();
    UpdateObserveButtons(0);
}
MS2_REPLACE_METHOD(0x14133BEC0, UIPvPGuildTeamDialog, StopObserving, 149, 0x63734D08);

// @0x14133bf60
void UIPvPGuildTeamDialog::UpdateObserveButtons(PCBase* pTarget)
{
    std::map<unsigned __int64, MS2Ptr<ASUIComponent> >::iterator it = m_slots.begin();
    std::map<unsigned __int64, MS2Ptr<ASUIComponent> >::iterator itEnd = m_slots.end();
    for (; it != itEnd; ++it) {
        MS2Ptr<ASButton> spButton = it->second->FUN_140acce30<ASButton>("m_observeButton");
        if (spButton == 0)
            continue;
        if (pTarget != 0 && it->first == ((class PCBase*)(class PCBase*)(pTarget))->FUN_141656a80())
            reinterpret_cast<ASButton*>(spButton.operator->())->SetSelected(1);
        else
            reinterpret_cast<ASButton*>(spButton.operator->())->SetSelected(0);
    }
}
MS2_REPLACE_METHOD(0x14133BF60, UIPvPGuildTeamDialog, UpdateObserveButtons, 323, 0x506F141D);

// ---- COMDATs ----

// @0x14133c460
template <class T> MS2Ptr<T> Unk_ASChildFinder::FindButton(const CString& strName)
{
    return FUN_14133c5f0<T>(m_value, strName);
}

// @0x14133c4b0
template <class T> MS2Ptr<T> UIDialog::FUN_141926e30(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<T>(0);
    MS2Ptr<ASDisplayObjectContainer> spContainer(dynamic_cast<ASDisplayObjectContainer*>((AScript*)m_30));
    if (spContainer == 0) {
        UIPVPGUILDTEAM_INL_ASSERT_0();
        return MS2Ptr<T>(0);
    }
    return static_cast<Unk_ASChildFinder*>(spContainer.operator->())->FindButton<T>(strName);
}

// @0x14133c5f0
template <class T> MS2Ptr<T> Unk_ASChildFinder::FUN_14133c5f0(const Scaleform::GFx::Value& v, const CString& strName)
{
    MS2Ptr<ASDisplayObjectContainer> spObj = CreateDisplayObjectContainer(m_nMovieId, v);
    if (!spObj->HasMember("getChildByName"))
        return MS2Ptr<T>(0);
    Scaleform::GFx::Value child = spObj->GetChildByName(strName);
    if (child.IsObject())
        return Unk_ASCreate<T>(m_nMovieId, child);
    if (!spObj->HasMember("numChildren"))
        return MS2Ptr<T>(0);
    int nCount = spObj->GetNumChildren();
    for (int i = 0; i < nCount; i++) {
        Scaleform::GFx::Value sub = spObj->GetChildAt(i);
        if (!sub.IsObject())
            continue;
        MS2Ptr<T> spFound = FUN_14133c5f0<T>(sub, strName);
        if (spFound.get() != 0)
            return spFound;
    }
    return MS2Ptr<T>(0);
}

// @0x14133c8c0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, CStringW a2, __int64 a3, __int64 a4)
{
    ASArgList args;
    args.resize(4);
    FUN_1422bcea0(&args[0], a1);
    FUN_1422bcea0(&args[1], a2);
    FUN_1422bcdd0(&args[2], a3);
    FUN_1422bcdd0(&args[3], a4);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();  // memmove_s 0x141340490
