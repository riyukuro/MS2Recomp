// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPvPObserverDialog: see uipvpobserverdialog.h.
// MS2-UNIT: ?\uipvpobserverdialog.cpp
// MS2-RANGE: 0x141a911b0-0x141a92ed0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipvpobserverdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uipvpobserverdialog.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASDialog : public ASDisplayObject { };

class Unk_PoEffectSvc                                           // the effect manager
{
public:
    unsigned FUN_1411a49c0(NoticeMessage& kRequest);            // start an effect
    void FUN_1411a6060(unsigned nId);                           // stop it
};
Unk_PoEffectSvc* FUN_1403ed280();

class Unk_PoMe : public PC                                      // the local player (MyPC)
{
public:
    void FUN_14152a4a0(PCBase* pTarget);                        // observe pTarget
    void FUN_14152a960();                                       // stop observing
    void FUN_14152a640(int nTeam);                              // observe a guild team
};

class Unk_PoWorld                                               // the world service
{
public:
    Unk_PoMe* FUN_141bd0cc0();                                      // the local player
    PC* FUN_141bd1530(__int64 nCharId);                         // a player by character id
    bool FUN_141bc6fb0(unsigned* pnHour, unsigned* pnMin, int* pnC, int* pnFlag) const;     // the match countdown
};
Unk_PoWorld* FUN_1403ed2d0();

struct Unk_PoConfig
{
    char m_pad_00[0x2f0];
    CString m_strCountdownEffect;                               // +0x2f0
};
Unk_PoConfig* FUN_1401d31f0();

class Unk_PoCameraUI                                            // the spectator camera buttons (UI 0x4e32)
{
public:
    void FUN_1419139d0(int bShow);
    void FUN_1419139f0(__int64 nCharId);
};
Unk_PoCameraUI* FUN_140b624b0(int nUiId);

bool FUN_140a467d0(const MS2Ptr<AScript>*);                     // has the AS object been released
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, void* pUnused);
void FUN_14151f200();

int FUN_141654730(PCBase* pPC);                                 // the job level
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1408116a0(int nStringId, const int* pnArg);
CStringW FUN_14062b4f0(CStringW strKey, const int* pnArg);
CString FUN_141028be0(__int64 nCharacterId, const CString& strKey, int nKind, CString strExt);   // a UGC profile path
CStringW FUN_14016a730(const char* sz, int nCodePage);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141a911b0
UIPvPObserverDialog::UIPvPObserverDialog()
{
    FUN_141924170(0);
    FUN_141925e70(0, 1);
    m_1d4 = false;
    m_1c8 = 0;
}

// @0x141a91260
UIPvPObserverDialog::~UIPvPObserverDialog()
{
}

// @0x141a912a0
CString UIPvPObserverDialog::GetTypeName()
{
    return "PvPObserverDialog";
}

// @0x141a912f0
int UIPvPObserverDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    m_1cc = 0;
    return 1;
}

// @0x141a91330
void UIPvPObserverDialog::vfunc_67()
{
    if (m_1d0 != 0) {
        FUN_1403ed280()->FUN_1411a6060(m_1d0);
        m_1d0 = 0;
    }
    if (m_1d5 != false) {
        Unk_PoCameraUI* pCamera = FUN_140b624b0(0x4e32);
        if (pCamera != 0) {
            pCamera->FUN_1419139d0(0);
            __int64 nNone = 0;
            pCamera->FUN_1419139f0(nNone);
        }
    }
    UIDialog::vfunc_67();
    Unk_PoMe* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    pPC->FUN_14152a960();
}

// @0x141a91400
void UIPvPObserverDialog::vfunc_72()
{
    int nFlag = 0;
    unsigned nHour = 0;
    unsigned nMin = 0;
    int nC = 0;
    FUN_1403ed2d0()->FUN_141bc6fb0(&nHour, &nMin, &nC, &nFlag);
    if (nFlag != 0 && nHour == 0 && nMin == 0) {
        vfunc_67();
    }
    else {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0) {
            CString strTime;
            strTime.Format("%02d%02d", nHour, nMin);
            pDialog->Invoke("setTime", strTime);
        }
        if (nHour == 0 && nMin == 0) {
            if (m_1d0 != 0) {
                FUN_1403ed280()->FUN_1411a6060(m_1d0);
                m_1d0 = 0;
            }
        }
        else if (m_1cc == 0 && (nHour == 0 && (int)nMin <= 10)) {
            NoticeMessage kRequest;
            kRequest.m_strName = FUN_1401d31f0()->m_strCountdownEffect;
            kRequest.m_nObject = 0;
            m_1d0 = FUN_1403ed280()->FUN_1411a49c0(kRequest);
            m_1cc = 1;
        }
    }
}

// @0x141a91640
void UIPvPObserverDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141a91b40();
}

// @0x141a91670
// MS2-FUNCTIONAL: the exe returns the bool of FUN_140a467d0 (movzx eax,al); UIDialog's slot 79 is void
void UIPvPObserverDialog::vfunc_79(void* pData)
{
    UIDialog::vfunc_79(pData);
    if (vfunc_55() == 0)
        FUN_140a467d0(&m_30);
}

// @0x141a916d0
// MS2-FUNCTIONAL: the exe's end jumps differ by one jmp (a single result variable; two attempts did not reproduce it)
int UIPvPObserverDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    Unk_PoMe* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return 0;
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0) {
        vfunc_67();
        return 1;
    }
    else {
        if (_stricmp("onObserveLeft", szMethod) == 0) {
            PC* pTarget = FUN_1403ed2d0()->FUN_141bd1530(m_178.m_nCharId);
            if (pTarget != 0)
                pMe->FUN_14152a4a0(pTarget);
        }
        else if (_stricmp("onObserveRight", szMethod) == 0) {
            PC* pTarget = FUN_1403ed2d0()->FUN_141bd1530(m_1a0.m_nCharId);
            if (pTarget != 0)
                pMe->FUN_14152a4a0(pTarget);
        }
        else if (_stricmp("onObserveCenter", szMethod) == 0) {
            pMe->FUN_14152a640(m_1c8);
        }
        return 0;
    }
}

// @0x141a91860
void UIPvPObserverDialog::vfunc_43()
{
    UIDialog::vfunc_43();
}

// @0x141a91880
int UIPvPObserverDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0) {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x141a91940
void UIPvPObserverDialog::FUN_141a91940(const Unk_PvPObsInfo& info)
{
    m_178.m_nCharId = info.m_a.m_nCharId;
    m_178.m_nHp = info.m_a.m_nHp;
    m_178.m_nMaxHp = info.m_a.m_nMaxHp;
    m_178.m_nWins = info.m_a.m_nWins;
    m_1a0.m_nCharId = info.m_b.m_nCharId;
    m_1a0.m_nHp = info.m_b.m_nHp;
    m_1a0.m_nMaxHp = info.m_b.m_nMaxHp;
    m_1a0.m_nWins = info.m_b.m_nWins;
    m_1c8 = 0;
    m_1d4 = false;
    FUN_141a91b40();
}

// @0x141a91a30
void UIPvPObserverDialog::FUN_141a91a30(const Unk_PvPObsInfo& info)
{
    m_178.m_nCharId = info.m_a.m_nCharId;
    m_178.m_nHp = info.m_a.m_nHp;
    m_178.m_nMaxHp = info.m_a.m_nMaxHp;
    m_178.m_nWins = info.m_a.m_nWins;
    m_178.m_nRating = info.m_a.m_nRating;
    m_1a0.m_nCharId = info.m_b.m_nCharId;
    m_1a0.m_nHp = info.m_b.m_nHp;
    m_1a0.m_nMaxHp = info.m_b.m_nMaxHp;
    m_1a0.m_nWins = info.m_b.m_nWins;
    m_1a0.m_nRating = info.m_b.m_nRating;
    m_1c8 = info.m_nCenter;
    m_1d4 = true;
    FUN_141a91b40();
}

// Send both fighters to the movie: names, status (win count or duel rating), job level and portrait, the hp bars, the
// camera buttons and the win marks.
// @0x141a91b40
// MS2-FUNCTIONAL: 4 KB of CStringW temporaries; frame/temporary order differs from the exe (14 bytes)
void UIPvPObserverDialog::FUN_141a91b40()
{
    Unk_PoMe* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe != 0 && !FUN_140a467d0(&m_30)) {
        CStringW strNameA(L"");
        CStringW strNameB(L"");
        CStringW strJobA(L"");
        CStringW strJobB(L"");
        CStringW strProfileA(L"");
        CStringW strProfileB(L"");
        CStringW strStatusA(L"");
        CStringW strStatusB(L"");
        bool bObservableA = false;
        PC* pA = FUN_1403ed2d0()->FUN_141bd1530(m_178.m_nCharId);
        if (pA != 0) {
            strNameA.Format(L"%s", (LPCWSTR)pA->vfunc_77());
            if (m_1d4 == false) {
                strStatusA = (m_178.m_nWins < 1) ? FUN_14028de60(0x89b) : FUN_1408116a0(0x89a, &m_178.m_nWins);
            }
            else {
                strStatusA = FUN_14062b4f0(CStringW(L"s_rank_duel_ui_rating"), &m_178.m_nRating);
            }
            strJobA.Format(L"_%d", FUN_141654730(pA));
            strProfileA = FUN_14016a730(FUN_141028be0(pA->FUN_141656a80(), pA->FUN_1416612e0(), 1, CString("")), 0);
            bObservableA = pMe->vfunc_122(pA) != 0;
        }
        __int64 nCharIdB = 0;
        bool bObservableB = false;
        PC* pB = FUN_1403ed2d0()->FUN_141bd1530(m_1a0.m_nCharId);
        if (pB != 0) {
            strNameB.Format(L"%s", (LPCWSTR)pB->vfunc_77());
            if (m_1d4 == false) {
                strStatusB = (m_1a0.m_nWins < 1) ? FUN_14028de60(0x89b) : FUN_1408116a0(0x89a, &m_1a0.m_nWins);
            }
            else {
                strStatusB = FUN_14062b4f0(CStringW(L"s_rank_duel_ui_rating"), &m_1a0.m_nRating);
            }
            strJobB.Format(L"_%d", FUN_141654730(pB));
            strProfileB = FUN_14016a730(FUN_141028be0(pB->FUN_141656a80(), pB->FUN_1416612e0(), 1, CString("")), 0);
            bObservableB = pMe->vfunc_122(pB) != 0;
            nCharIdB = pB->FUN_141656a80();
        }
        m_30->Invoke("setName", strNameA, strNameB);
        m_30->Invoke("setStatus", strStatusA, strStatusB);
        m_30->Invoke("setJob", strJobA, strJobB);
        m_30->Invoke("setProfile", strProfileA, strProfileB);
        FUN_141a92b10(m_178.m_nCharId, m_178.m_nHp, m_178.m_nMaxHp);
        FUN_141a92b10(m_1a0.m_nCharId, m_1a0.m_nHp, m_1a0.m_nMaxHp);
        m_1d5 = true;
        if (m_178.m_nCharId == pMe->FUN_141656a80() || m_1a0.m_nCharId == pMe->FUN_141656a80())
            m_1d5 = false;
        m_30->Invoke("setCameraEnable", m_1d5);
        m_30->Invoke("setDuelMode", m_1d4);
        bool bCenter;
        if (m_1d5 == false || m_1c8 == 0)
            bCenter = false;
        else
            bCenter = true;
        m_30->Invoke("setCenterCameraEnable", bCenter);
        if (m_178.m_nShownWins != m_178.m_nWins) {
            m_30->FUN_14184af30("setWinMark", true, m_178.m_nWins);
            m_178.m_nShownWins = m_178.m_nWins;
        }
        if (m_1a0.m_nShownWins != m_1a0.m_nWins) {
            m_30->FUN_14184af30("setWinMark", false, m_1a0.m_nWins);
            m_1a0.m_nShownWins = m_1a0.m_nWins;
        }
        if (m_1d5 != false) {
            Unk_PoCameraUI* pCamera = FUN_140b624b0(0x4e32);
            if (pCamera != 0) {
                pCamera->FUN_1419139d0(1);
                if (!bObservableA && !bObservableB)
                    pCamera->FUN_1419139f0(nCharIdB);
            }
        }
    }
}

// @0x141a92b10
void UIPvPObserverDialog::FUN_141a92b10(__int64 nCharId, __int64 nHp, __int64 nMaxHp)
{
    if (FUN_140a467d0(&m_30))
        return;
    {
        if (nCharId == m_178.m_nCharId) {
            m_178.m_nHp = nHp;
            m_178.m_nMaxHp = nMaxHp;
            m_30->Invoke("setHpBarLeft", nHp, nMaxHp);
        }
        else if (nCharId == m_1a0.m_nCharId) {
            m_1a0.m_nHp = nHp;
            m_1a0.m_nMaxHp = nMaxHp;
            m_30->Invoke("setHpBarRight", nHp, nMaxHp);
        }
    }
}

// @0x141a92c80
void UIPvPObserverDialog::FUN_141a92c80()
{
    if (FUN_140a467d0(&m_30))
        return;
    m_30->Invoke("startClosingUI");
}

// @0x141a92ce0
int UIPvPObserverDialog::FUN_141a92ce0()
{
    return m_1c8;
}

MS2_REPLACE_METHOD(0x141A912A0, UIPvPObserverDialog, GetTypeName, 61, 0x608284E6);
MS2_REPLACE_METHOD(0x141A912F0, UIPvPObserverDialog, vfunc_65, 52, 0x37F5FFE4);
MS2_REPLACE_METHOD(0x141A91330, UIPvPObserverDialog, vfunc_67, 190, 0xE956ECE4);
MS2_REPLACE_METHOD(0x141A91400, UIPvPObserverDialog, vfunc_72, 570, 0x4751A3AB);
MS2_REPLACE_METHOD(0x141A91640, UIPvPObserverDialog, OnLoadComplete, 34, 0x2B174B87);
MS2_REPLACE_METHOD(0x141A916D0, UIPvPObserverDialog, vfunc_28, 384, 0x5B1E5705);
MS2_REPLACE_METHOD(0x141A91860, UIPvPObserverDialog, vfunc_43, 24, 0x08A31BBC);
MS2_REPLACE_METHOD_VIA(0x141A91880, UIPvPObserverDialog, IMessageListener, OnMessage, 182, 0xFDE2C41D);
MS2_REPLACE_METHOD(0x141A91940, UIPvPObserverDialog, FUN_141a91940, 219, 0x224A9917);
MS2_REPLACE_METHOD(0x141A91A30, UIPvPObserverDialog, FUN_141a91a30, 261, 0xF0809880);
MS2_REPLACE_METHOD(0x141A91B40, UIPvPObserverDialog, FUN_141a91b40, 4032, 0x28CD3BE5);
MS2_REPLACE_METHOD(0x141A92B10, UIPvPObserverDialog, FUN_141a92b10, 350, 0xB93A02BF);
MS2_REPLACE_METHOD(0x141A92C80, UIPvPObserverDialog, FUN_141a92c80, 87, 0x28D78CEB);
MS2_REPLACE_METHOD(0x141A92CE0, UIPvPObserverDialog, FUN_141a92ce0, 17, 0x3B399D22);

MS2_EMIT_CRT_MEMMOVE_S();
