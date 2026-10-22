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

// Unrecovered helpers (the UI service lookup the other UI units use).
class Unk_CommandUIRef {
public:
    ~Unk_CommandUIRef();
    UIObject* FUN_1403e8a70() const;
private: void* unknown; UIObject* object;
};
MS2_CHECK_SIZE(Unk_CommandUIRef,0x10);
class Unk_UIService { public: Unk_CommandUIRef FUN_141adcea0(int nId); };   // dialog by id
Unk_UIService* FUN_1403ed2b0();                             // the UI service
UIObject* FUN_1403ed9e0(Unk_CommandUIRef&);

// @0x140bc16c0
UIBottomCenterAlignManager::UIBottomCenterAlignManager()
{
}

// @0x140bc1700
UIBottomCenterAlignManager::~UIBottomCenterAlignManager()
{
}

// @0x140bc17d0
UIHighlightGameMenu* FUN_140bc17d0(int nId)
{
    if (FUN_1403ed2b0())
    {
        Unk_CommandUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UIHighlightGameMenu*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

// @0x140bc1870
UIRecallScrollNotifyDialog* FUN_140bc1870(int nId)
{
    if (FUN_1403ed2b0())
    {
        Unk_CommandUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UIRecallScrollNotifyDialog*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

// @0x140bc1730
void UIBottomCenterAlignManager::FUN_140bc1730()
{
    int nOffset = 0;
    UIHighlightGameMenu* pMenu = FUN_140bc17d0(0x4f75);
    if (pMenu && pMenu->IsActive())
        nOffset -= 60;
    UIRecallScrollNotifyDialog* pRecall = FUN_140bc1870(0x4edd);
    if (pRecall && pRecall->IsActive())
    {
        pRecall->SetOffset(nOffset);
        pRecall->vfunc_43();
        nOffset -= 60;
    }
}

// @0x140bc19e0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
