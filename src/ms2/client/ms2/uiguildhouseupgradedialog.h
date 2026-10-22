// uiguildhouseupgradedialog.h - UIGuildHouseUpgradeDialog (RTTI .?AVUIGuildHouseUpgradeDialog@@, UIDialog, ui id 0x4f2e):
// the guild house theme / level upgrade window. Owning unit: ?\uiguildhouseupgradedialog.cpp (0x140e39790-0x140e3efd0;
// header name assumed from the unit path).
//
// The tab strip (m_tab) selects the house level, the theme list (m_themeList) the theme of that level; m_upgradeButton
// raises the guild house to the selected level / theme through the guild manager after a confirmation box. m_themes
// maps a level to the themes the guild xml offers for it (built by FUN_140e3a770).
#pragma once

#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"

class CMsgBoxData;
class Unk_MentorTab;
class Unk_LdItemBag;
class Unk_140acd6e0;

class UIGuildHouseUpgradeDialog : public UIDialog
{
public:
    UIGuildHouseUpgradeDialog();                                    // 0x140e39790
    virtual ~UIGuildHouseUpgradeDialog();                           //  0 0x140e39830 (??_G 0x140e3da10)
    virtual CString GetTypeName();                                      //  1 0x140e39d50 "GuildHouseUpgradeDialog"
    virtual void vfunc_26();                                        // 26 0x140e398c0 drops the theme map
    virtual void vfunc_67();                                        // 67 0x140e39900 close: forget the controls
    virtual void OnLoadComplete();                                  // 22 0x140e39960
    // @0x140e3da50
    virtual int vfunc_48() { return 0x4f2e; }                       // 48

    void FUN_140e39da0();                                           // show the selected theme (title, button, areas, facilities, preview)
    bool FUN_140e3a6b0(int nButton, const CMsgBoxData& data);       // theme change confirmed
    bool FUN_140e3a720(int nButton, const CMsgBoxData& data);       // upgrade confirmed
    void FUN_140e3a770();                                           // fill the tab strip / theme map from the guild xml
    void FUN_140e3a910(const Scaleform::GFx::FunctionHandler::Params& params);   // tab clicked: fill the theme list
    void FUN_140e3abc0(const Scaleform::GFx::FunctionHandler::Params& params);   // theme clicked
    void FUN_140e3abf0(const Scaleform::GFx::FunctionHandler::Params& params);   // upgrade button clicked

    template <class T> MS2Ptr<T> FUN_140e3b650(const CString& strName, MS2Ptr<T>& out);   // bind the tab strip
    template <class T> MS2Ptr<T> FUN_140e3b6e0(const CString& strName, MS2Ptr<T>& out);   // bind the theme list
    template <class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out);   // bind a button (0x140bc6d10)

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_MentorTab> m_tab;                                    // +0x178 "m_tab" house level strip
    MS2Ptr<Unk_LdItemBag> m_themeList;                              // +0x188 "m_themeList"
    MS2Ptr<Unk_140acd6e0> m_upgradeButton;                          // +0x198 "m_upgradeButton"
    std::map<int, std::vector<int> > m_themes;                      // +0x1a8 level -> theme ids
};
MS2_CHECK_SIZE(UIGuildHouseUpgradeDialog, 0x1b8);
MS2_CHECK_OFFSET(UIGuildHouseUpgradeDialog, m_tab, 0x178);
MS2_CHECK_OFFSET(UIGuildHouseUpgradeDialog, m_themes, 0x1a8);
