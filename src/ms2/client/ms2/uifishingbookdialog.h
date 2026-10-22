// uifishingbookdialog.h - UIFishingBookDialog (RTTI .?AVUIFishingBookDialog@@, 0x180 bytes: UIDialog 0x178 + two ints,
// UI type 0x4ee6, swf "FishingBookDialog"): the fishing book. A tab bar (all / lake / sea ...), a page of 20 fish slots
// ("m_bag"), a page counter ("m_page") and the fisher grade panel with the mastery gauge. Owning unit:
// ?\uifishingbookdialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

typedef ATL::CAtlArray<int> FbIdArray;

struct Unk_FbListRef;
struct Unk_FbTextRef;

class UIFishingBookDialog : public UIDialog
{
public:
    UIFishingBookDialog();                                      // 0x140f41250
    virtual ~UIFishingBookDialog() = default;                      //  0 0x140f43c90 (??_G 0x140f43d30)
    virtual CString GetTypeName();                                  //  1 0x140f412e0 "FishingBookDialog"
    virtual void OnLoadComplete();                              // 22 0x140f41330 tab 0, page 0, "m_bag" scroll top
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140f41440 onChangeFish / onTabChange / onPrevPage / onNextPage
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140f416b0 "getTooltip": mastery gauge tooltip
    virtual void vfunc_67();                                    // 67 0x140f41940 close: clear the "new" mark of every fish
    virtual int vfunc_48() { return 0x4ee6; }                   // 48 0x140f43de0

    void FUN_140f41a10();                                       // 0x140f41a10 "setFisher": title, grade and mastery gauge
    void FUN_140f41e90();                                       // 0x140f41e90 "setTabNew": which tabs hold a new fish
    void FUN_140f42100(int nFishId);                            // 0x140f42100 "setFish": the detail panel of one fish
    void FUN_140f42790(int nTab);                               // 0x140f42790 "m_bag": fill the current page
    void FUN_140f419e0();                                       // 0x140f419e0 refresh the current tab
    int FUN_140f42cd0(int nPage);                               // 0x140f42cd0 is the page index valid
    void FUN_140f42d90(FbIdArray& rIds);   // 0x140f42d90 fish ids of the current tab
    int FUN_140f42ed0();                                        // 0x140f42ed0 the title id of the best fisher title owned
    CStringW FUN_140f432e0(int nTitleId);                       // 0x140f432e0 title text
    int FUN_140f43330(int nFishId);                             // 0x140f43330 fish is known
    int FUN_140f43380(int nFishId);                             // 0x140f43380 fish (or its parent) holds a new mark
    int FUN_140f434b0(int nFishId);                             // 0x140f434b0 parent fish id
    int FUN_140f43540(int nFishId);                             // 0x140f43540 medal of the fish
    int FUN_140f43610(int nFishId);                             // 0x140f43610 total catch count
    int FUN_140f436f0(int nFishId);                             // 0x140f436f0 big-size catch count
    int FUN_140f437d0(int nFishId);                             // 0x140f437d0 best record

    Unk_FbListRef FUN_140ba4b70(const CString& strName);        // list control child
    Unk_FbTextRef FUN_140bb4cf0(const CString& strName);        // text field child

private:
    MS2_LAYOUT_FRIEND;
    int m_nPage;                                                // +0x178
    int m_nTab;                                                 // +0x17c
};
MS2_CHECK_SIZE(UIFishingBookDialog, 0x180);
MS2_CHECK_OFFSET(UIFishingBookDialog, m_nPage, 0x178);
