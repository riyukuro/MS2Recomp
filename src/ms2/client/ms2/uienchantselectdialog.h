// uienchantselectdialog.h - UIEnchantSelectDialog (RTTI .?AVUIEnchantSelectDialog@@, 0x198 bytes, UIDialog, UI id 0x4e91,
// swf "EnchantSelectDialog"): asks which enchant npc to talk to (lottery / expMode). Both buttons
// ("m_type1Button" / "m_type2Button") share one click handler; "m_recommendType2" is a marker clip shown by a feature flag.
// Owning unit: ?\uienchantselectdialog.cpp. Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class Unk_EsButton;
class ASMovieClip;

class UIEnchantSelectDialog : public UIDialog
{
public:
    UIEnchantSelectDialog();                                    // 0x140e291e0
    virtual ~UIEnchantSelectDialog();                           //  0 0x140e29270 (??_G 0x140e29de0)
    virtual CString GetTypeName();                                  //  1 0x140e29310 "EnchantSelectDialog"
    virtual void OnLoadComplete();                              // 22 0x140e29410 hook the two buttons
    virtual int vfunc_48() { return 0x4e91; }                                  // 48 0x140e29e20
    virtual void vfunc_67();                                    // 67 0x140e29360

    void FUN_140e29860(const Scaleform::GFx::FunctionHandler::Params& params);   // a button was clicked

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_EsButton> FUN_140bc6d10(const CString& strName, MS2Ptr<Unk_EsButton>& out);   // 0x140bc6d10 returns by value (hidden return pointer)
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);

    MS2Ptr<Unk_EsButton> m_type1Button;                         // +0x178 "m_type1Button"
    MS2Ptr<Unk_EsButton> m_type2Button;                         // +0x188 "m_type2Button"
};
MS2_CHECK_SIZE(UIEnchantSelectDialog, 0x198);
