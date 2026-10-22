// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPvPTeamScoreDialog: see uipvpteamscoredialog.h.
// MS2-UNIT: ?\uipvpteamscoredialog.cpp
// MS2-RANGE: 0x1413466b0-0x141346a40 .text$mn
// MS2-PIN: ??_GUIPvPTeamScoreDialog@@UEAAPEAXI@Z 0x1413469f0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipvpteamscoredialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uipvpteamscoredialog.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

struct Unk_PvPTeamScoreService;                                 // the game-mode service (0x140f97ef0)
Unk_PvPTeamScoreService* FUN_140f97ef0();
void FUN_141346600(Unk_PvPTeamScoreService* pService, int* pFirst, int* pSecond);   // 0x141346600 the two scores

bool FUN_140a467d0(const MS2Ptr<AScript>*);                     // has the AS object been released
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, void* pUnused);
void* FUN_1403ed2b0();                                          // the UI service
int FUN_141adc750(void* pUI, int nUiId);                        // open a UI by id

// FUN_141346960 is a free function, so it reaches the dialog's protected AS pointer (UISwfEntity::m_30 at +0x30)
// through this layout view.
struct Unk_ScoreDialogAS { char m_pad_00[0x30]; MS2Ptr<AScript> m_30; };

// @0x1413466b0
UIPvPTeamScoreDialog::UIPvPTeamScoreDialog()
{
    FUN_141925e70(1, 1);
}

// @0x141346720
UIPvPTeamScoreDialog::~UIPvPTeamScoreDialog()
{
}

// @0x141346760
CString UIPvPTeamScoreDialog::GetTypeName()
{
    return "PvPTeamScoreDialog";
}
MS2_REPLACE_METHOD(0x141346760, UIPvPTeamScoreDialog, GetTypeName, 61, 0xB946B4CD);

// @0x1413467b0
void UIPvPTeamScoreDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141346960(this);
}
MS2_REPLACE_METHOD(0x1413467B0, UIPvPTeamScoreDialog, OnLoadComplete, 34, 0x67D65772);

// @0x1413467e0
int UIPvPTeamScoreDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnShowResult", szMethod) == 0) {
        FUN_141adc750(FUN_1403ed2b0(), 0x4ed2);
        return 1;
    }
    if (_stricmp("OnClose", szMethod) == 0) {
        vfunc_67();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1413467E0, UIPvPTeamScoreDialog, vfunc_28, 197, 0xABE1B534);

// @0x1413468b0
void UIPvPTeamScoreDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(2, 0, -250);
}

// @0x141346960
void FUN_141346960(UIPvPTeamScoreDialog* pDialog)
{
    if (FUN_140a467d0(&((Unk_ScoreDialogAS*)pDialog)->m_30))
        return;
    int nFirst = 0;
    int nSecond = 0;
    FUN_141346600(FUN_140f97ef0(), &nFirst, &nSecond);
    ((Unk_ScoreDialogAS*)pDialog)->m_30->FUN_1409ba0d0("updateScore", nFirst, nSecond);
}
MS2_REPLACE(0x141346960, FUN_141346960, 139, 0xF8C6A11B);

// @0x141346a30
int UIPvPTeamScoreDialog::vfunc_48()
{
    return 0x4ed3;
}
