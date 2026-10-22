// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPvPRankingDialog: see uipvprankingdialog.h.
// MS2-UNIT: ?\uipvprankingdialog.cpp
// MS2-RANGE: 0x141342f10-0x1413439a0 .text$mn
// MS2-PIN: ??_GUIPvPRankingDialog@@UEAAPEAXI@Z 0x1413437a0
// MS2-PIN: ?FUN_141343860@Unk_PvPRankEntry@@QEAA_NXZ 0x141343860
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipvprankingdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uipvprankingdialog.h"

#include "ms2/ms2format.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/uimessagebox.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe types ----

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

class Unk_PvPRankWorld                                              // the world service
{
public:
    MyPC* FUN_141bd0cc0();                                          // the local player
    PCBase* FUN_141bd1530(__int64 nCharId);                         // a player by character id
};
Unk_PvPRankWorld* FUN_1403ed2d0();

// One row of the ranking.
class Unk_PvPRankEntry
{
public:
    bool FUN_141343860()                                            // 0x141343860 the player has a rank
    {
        if (0 < m_nRank)
            return true;
        return false;
    }

    __int64 m_nCharId;                  // +0x00
    CStringW m_strName;                 // +0x08
    int m_nScore;                       // +0x10
    int m_pad_14;
    __int64 m_pad_18;
    __int64 m_nRank;                    // +0x20
};

class Unk_PvPRankTable                                              // the ranking list (at +8 of the service)
{
public:
    int FUN_141017f40(__int64 nCharId);                             // the rank of a character
    Unk_PvPRankEntry* FUN_141017fb0(int nRank);                     // the row of a rank
};

class Unk_PvPRankService                                            // the game-mode service
{
public:
    int FUN_1413437e0(__int64 nCharId) { return m_table.FUN_141017f40(nCharId); }          // 0x1413437e0
    Unk_PvPRankEntry* FUN_141343810(int nRank) { return m_table.FUN_141017fb0(nRank); }    // 0x141343810
private:
    void* m_pad_00;
    Unk_PvPRankTable m_table;
};
Unk_PvPRankService* FUN_140f97ef0();

bool FUN_140a467d0(const MS2Ptr<AScript>*);
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& n);
int FUN_141654730(PCBase* pPC);                                     // the job
__int64 FUN_141656a80(PCBase* pPC);                                 // the character id
int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4);
void* FUN_1403ed2b0();                                              // the UI service
int FUN_141adc940(void* pUI, int nUiId);
void FUN_141adc530(void* pUI, int nUiId);
void FUN_14151f200();

// @0x141342f10
UIPvPRankingDialog::UIPvPRankingDialog()
{
    FUN_141925e70(1, 1);
}

// @0x141342f80
UIPvPRankingDialog::~UIPvPRankingDialog()
{
}

// @0x141342fc0
CString UIPvPRankingDialog::GetTypeName()
{
    return "PvPRankingDialog";
}
MS2_REPLACE_METHOD(0x141342FC0, UIPvPRankingDialog, GetTypeName, 61, 0xF3499979);

// @0x141343010
int UIPvPRankingDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x141343010, UIPvPRankingDialog, vfunc_65, 37, 0xEBF47894);

// @0x141343040
void UIPvPRankingDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x141343040, UIPvPRankingDialog, vfunc_67, 24, 0xE8E54004);

// @0x141343060
void UIPvPRankingDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1413432b0();
}
MS2_REPLACE_METHOD(0x141343060, UIPvPRankingDialog, OnLoadComplete, 34, 0xDC8B582D);

// MS2-FUNCTIONAL: the exe override returns the callee's bool (movzx) from a void slot
// @0x141343090
void UIPvPRankingDialog::vfunc_79(void* pData)
{
    UIDialog::vfunc_79(pData);
    if (vfunc_55() == 0)
        FUN_140a467d0(&m_30);
}

// MS2-FUNCTIONAL: cl reserves 0x10 more frame than the exe (two extra 8-byte slots)
// @0x1413430f0
bool UIPvPRankingDialog::FUN_1413430f0(ASObj* pObj, int nRank, Unk_PvPRankEntry* pEntry)
{
    if (pEntry == 0) {
        return false;
    } else {
        PCBase* pPC = FUN_1403ed2d0()->FUN_141bd1530(pEntry->m_nCharId);
        pObj->FUN_1407cb9c0("rank", nRank);
        CStringW strRank(L"-");
        if (pEntry->FUN_141343860())
            strRank = FUN_1401ceea0(L"{0}", nRank);
        pObj->FUN_1407cbb20("rankText", strRank);
        pObj->FUN_1407cbb20("charName", pEntry->m_strName);
        pObj->FUN_1407cb9c0("score", pEntry->m_nScore);
        if (pPC != 0)
            pObj->FUN_140bd0d90("job", FUN_141654730(pPC));
        return true;
    }
}

// @0x1413432b0
void UIPvPRankingDialog::FUN_1413432b0()
{
    if (FUN_140a467d0(&m_30))
        return;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    for (int nRank = 1; nRank <= 3; nRank++) {
        Unk_PvPRankEntry* pEntry = FUN_140f97ef0()->FUN_141343810(nRank);
        if (pEntry == 0)
            continue;
        ASObj obj(2);
        if (!FUN_1413430f0(&obj, nRank, pEntry))
            continue;
        m_30->Invoke("updateMember", obj.FUN_1422bb870());
    }
    int nMyRank = FUN_140f97ef0()->FUN_1413437e0(FUN_141656a80(pPC));
    Unk_PvPRankEntry* pEntry = FUN_140f97ef0()->FUN_141343810(nMyRank);
    if (pEntry != 0) {
        ASObj obj(2);
        if (FUN_1413430f0(&obj, nMyRank, pEntry) == true)
            m_30->Invoke("updateMe", obj.FUN_1422bb870());
    }
}
MS2_REPLACE_METHOD(0x1413432B0, UIPvPRankingDialog, FUN_1413432b0, 624, 0x8B14ECC9);

// @0x141343530
int UIPvPRankingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnShowResult", szMethod) == 0) {
        if (FUN_141adc940(FUN_1403ed2b0(), 0x4e9b) != 0)
            FUN_141adc530(FUN_1403ed2b0(), 0x4e9b);
        return 1;
    }
    if (_stricmp("OnClose", szMethod) == 0) {
        vfunc_67();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141343530, UIPvPRankingDialog, vfunc_28, 219, 0x7526F642);

// @0x141343620
void UIPvPRankingDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    if (m_78 == 0) {
        MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (spEntity.get() != 0)
            spEntity->vfunc_2(5, 0, 100);
    }
}
// (vfunc_43 / OnMessage use dynamic_cast to RTTI classes the DLL does not own: no hook)

// @0x1413436e0
int UIPvPRankingDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
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

// @0x141343840
int UIPvPRankingDialog::vfunc_48()
{
    return 0x4e9a;
}

// @0x141343850
int UIPvPRankingDialog::vfunc_52()
{
    return 1;
}

MS2_EMIT_CRT_MEMMOVE_S();
