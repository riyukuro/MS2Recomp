// uiitemsocketsystemdialog.h - UIItemSocketSystemDialog (RTTI .?AVUIItemSocketSystemDialog@@, 0x1a8 bytes, UIModalDialog,
// UI id 0x4f0a, swf "ItemSocketSystemDialog"): the socket system window. A tab strip over five pages (gemstone upgrade,
// gemstone put on / off, socket unlock, and the feature-gated socket transfer and gemstone swap), held in a vector
// indexed by the tab id. The packet 0xde is forwarded to the shown page. Owning unit: ?\uiitemsocketsystemdialog.cpp
// (0x140f68da0-0x140f6c680, dir client\ms2); header name assumed from the unit path; member names are invented.
#pragma once
#include <afx.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "uimodaldialog.h"

class ItemSocketSystemPageBase;
class CInPacket;

class UIItemSocketSystemDialog : public UIModalDialog
{
public:
    UIItemSocketSystemDialog();                                 // 0x140f68da0
    virtual ~UIItemSocketSystemDialog();                        //  0 0x140f68ed0 (??_G 0x140f6b270)
    virtual CString GetTypeName();                                  //  1 0x140f68fc0 "ItemSocketSystemDialog"
    virtual void OnLoadComplete();                              // 22 0x140f69010 fill the tab strip
    virtual void vfunc_26();                                    // 26 0x140f69920 release the pages
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140f694a0 OnChangeTab
    virtual int vfunc_48();                                     // 48 0x140f6b2b0 0x4f0a
    virtual int vfunc_65();                                     // 65 0x140f69670 open: create the pages
    virtual void vfunc_67();                                    // 67 0x140f69620 close: hide the page
    virtual void vfunc_72();                                    // 72 0x140f695d0 tell the page

    void FUN_140f699f0(const int& nTab);                        // 0x140f699f0 "changeTab"
    void FUN_140f69a60(int nTab);                               // 0x140f69a60 show the page of a tab
    void FUN_140f69b50(CInPacket& packet);                      // 0x140f69b50 packet 0xde: to the shown page
    void FUN_140f69c10(const int& nTab);                        // 0x140f69c10 select a tab

private:
    MS2_LAYOUT_FRIEND;
    ItemSocketSystemPageBase* m_pPage;                          // +0x180 the shown page
    std::vector<ItemSocketSystemPageBase*> m_pages;             // +0x188 the pages by tab id
    int m_nTab;                                                 // +0x1a0 the selected tab
};
MS2_CHECK_SIZE(UIItemSocketSystemDialog, 0x1a8);
MS2_CHECK_OFFSET(UIItemSocketSystemDialog, m_pPage, 0x180);
MS2_CHECK_OFFSET(UIItemSocketSystemDialog, m_pages, 0x188);
MS2_CHECK_OFFSET(UIItemSocketSystemDialog, m_nTab, 0x1a0);
