// uiregionlistdialog.h - UIRegionListDialog (RTTI .?AVUIRegionListDialog@@, 0x1a8 bytes, UIDialog, UI id 0x4eef, swf
// "RegionListDialog"): the server region pop-down of the login scene. It lists the regions the login server offers
// (id, label, icon, status), remembers the chosen region id in the client settings and, when the Nexon platform is
// active, resolves the region's host name to the login ip. Owning unit: ?\uiregionlistdialog.cpp. Header name assumed from
// the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/fieldmetatable.h"

// One region of the list (the value inside a TPtredDummy box). Field names are invented.
struct Unk_RlRegion
{
    CStringW m_id;                                              // +0x00 the region key kept in the settings
    CStringW m_label;                                           // +0x08
    CString m_host;                                             // +0x10 the login host name
    CString m_image;                                            // +0x18 icon file name
    int m_status;                                               // +0x20
};
MS2_CHECK_OFFSET(Unk_RlRegion, m_host, 0x10);
MS2_CHECK_OFFSET(Unk_RlRegion, m_image, 0x18);
MS2_CHECK_OFFSET(Unk_RlRegion, m_status, 0x20);
typedef Unk_FieldPtr<Unk_RlRegion> Unk_RlPtr;

class UIRegionListDialog : public UIDialog
{
public:
    UIRegionListDialog();                                       // 0x140e80220
    virtual ~UIRegionListDialog();                              //  0 0x140e80330 (??_G 0x140e81730)
    virtual CString GetTypeName();                                  //  1 0x140e803a0 "RegionListDialog"
    virtual void OnLoadComplete();                              // 22 0x140e803f0
    virtual int vfunc_13();                                     // 13 0x140e80430 the enter key
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e804b0
    virtual int vfunc_48() { return 0x4eef; }                   // 48 0x140e81bb0

    void FUN_140e80620();                                       // OK: keep the chosen region and close
    void FUN_140e80740();                                       // forget the chosen region (Nexon platform)
    Unk_RlPtr FUN_140e807c0();                                  // the region saved in the settings
    void FUN_140e808b0();                                       // the movie's "popdown"
    void FUN_140e80910();                                       // the movie's "popup"
    Unk_RlPtr FUN_140e809b0(int nUnused);                       // the first region (the int is ignored)
    void FUN_140e80a40();                                       // move the saved region to the front
    void FUN_140e80c30();                                       // hand the list to the movie ("buildRegionList")
    bool FUN_140e80f10(CStringW strRegion);                     // choose a region; false when it is unknown
    Unk_RlPtr FUN_140e810d0(CStringW strRegion);                // find a region by id
    void FUN_140e811d0();                                       // a region was selected in the movie
    void OnEndPopdown();                                       // the pop-down ended
    void FUN_140e812e0(const CStringW& strRegion);              // pick the region (or the first one) as the setting

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<Unk_RlPtr> m_regions;                        // +0x178
    int m_nUnused198;                                           // +0x198 0
    int m_nSelected;                                            // +0x19c 0 (second argument of "buildRegionList")
    CStringW m_strSaved;                                        // +0x1a0 the region id read from the settings
};
MS2_CHECK_SIZE(UIRegionListDialog, 0x1a8);
MS2_CHECK_OFFSET(UIRegionListDialog, m_regions, 0x178);
MS2_CHECK_OFFSET(UIRegionListDialog, m_nSelected, 0x19c);
MS2_CHECK_OFFSET(UIRegionListDialog, m_strSaved, 0x1a0);
