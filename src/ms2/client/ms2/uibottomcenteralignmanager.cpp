// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBottomCenterAlignManager, the TSingleton that stacks
// the bottom-centre notice dialogs (UIHighlightGameMenu and UIRecallScrollNotifyDialog) by shifting the second one up
// by the height of the first.
// MS2-UNIT: ?\uibottomcenteralignmanager.cpp
// MS2-RANGE: 0x140bc16c0-0x140bc1b00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibottomcenteralignmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/uibottomcenteralignmanager.h"
#include "ms2/placeholder/uihighlightgamemenu.h"
#include "ms2/placeholder/uirecallscrollnotifydialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uiservice.h"


// @0x140bc16c0
UIBottomCenterAlignManager::UIBottomCenterAlignManager()
{
}

// @0x140bc1700
UIBottomCenterAlignManager::~UIBottomCenterAlignManager()
{
}

// @0x140bc17d0
UIHighlightGameMenu* GetHighlightGameMenu(int nId)
{
    if (TSingleton<CUIService>::GetInstance())
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (ref.get())
            return dynamic_cast<UIHighlightGameMenu*>(ref.operator UIObject*());
    }
    return 0;
}

// @0x140bc1870
UIRecallScrollNotifyDialog* GetRecallScrollNotifyDialog(int nId)
{
    if (TSingleton<CUIService>::GetInstance())
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (ref.get())
            return dynamic_cast<UIRecallScrollNotifyDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// @0x140bc1730
void UIBottomCenterAlignManager::FUN_140bc1730()
{
    int nOffset = 0;
    UIHighlightGameMenu* pMenu = GetHighlightGameMenu(0x4f75);
    if (pMenu && pMenu->IsActive())
        nOffset -= 60;
    UIRecallScrollNotifyDialog* pRecall = GetRecallScrollNotifyDialog(0x4edd);
    if (pRecall && pRecall->IsActive())
    {
        pRecall->SetOffset(nOffset);
        pRecall->vfunc_43();
        nOffset -= 60;
    }
}

// @0x140bc19e0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
