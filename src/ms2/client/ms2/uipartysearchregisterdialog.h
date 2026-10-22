// uipartysearchregisterdialog.h - UIPartySearchRegisterDialog (RTTI .?AVUIPartySearchRegisterDialog@@, 0x228 bytes,
// UI id 0x4edb, swf "PartySearchRegisterDialog"): the modal dialog that registers (or removes) the local party in the
// party search. Child controls: m_maxUserCountCombo, m_inputTitle, m_checkAllowAutoJoin, m_btnRegister, m_btnRemove.
// Owning unit: client\ms2\uipartysearchregisterdialog.cpp (0x141320660-0x141322c00). Header name assumed from the
// unit path (w13).
#pragma once
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/gfxvalue.h"
#include <atlcoll.h>

class Unk_PsCombo;
class Unk_PsInput;
class Unk_PsCheck;
class Unk_PsButton;

// One title the dialog remembers: the text and the "allow auto join" flag. Layout: 0x10.
struct Unk_PsRegState
{
    Unk_PsRegState();                   // 0x141322880 text empty, flag 1
    ~Unk_PsRegState();                  // 0x1413228d0
    void FUN_141322970();               // reset: empty text, flag 1

    CStringW m_text;                    // +0x00
    unsigned char m_flag;               // +0x08 allow auto join
};
MS2_CHECK_SIZE(Unk_PsRegState, 0x10);

class UIPartySearchRegisterDialog : public UIModalDialog
{
public:
    UIPartySearchRegisterDialog();                              // 0x141320660
    virtual ~UIPartySearchRegisterDialog();                     //  0 0x1413207b0 (??_G 0x141322930)
    virtual CString GetTypeName();                                  //  1 0x1413208b0 "PartySearchRegisterDialog"
    virtual int vfunc_13();                                     // 13 0x141321960 enter / tab key: "onProcessKey"
    virtual void OnLoadInit();                                  // 20 0x1413209d0 UIObject::OnLoadInit(); vfunc_47(0)
    virtual void OnLoadComplete();                              // 22 0x141320a10 bind the controls, fill the combo
    virtual void vfunc_26();                                    // 26 0x1413218d0 unbind the controls
    virtual int vfunc_48() { return 0x4edb; }                   // 48 0x1413229a0
    virtual void vfunc_67();                                    // 67 0x141320900 close: forget the typed state
    virtual int vfunc_73();                                     // 73 0x141320940 can open (party search not blocked)
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141321b30 remove / modify answers

    void FUN_141321cc0(CStringW* pText, unsigned char nAutoJoin, Unk_PsRegState* pState);   // remember a registered title
    void FUN_141321d30();                                       // forget the registered title (m_190)
    void FUN_141321d60();                                       // fill the random title list (string ids 0xc48-0xc4c)
    CStringW FUN_141321f10(CStringW strArg, int nArg);          // a random title formatted with the argument
    int FUN_141322020();                                        // field id of the selected combo row (10 = default)
    int FUN_1413220d0(Unk_PsRegState* pState, int bSilent);     // validate and send the registration; 1 = sent
    int FUN_141322380(int nValue);                              // combo row of the value, -1 if absent
    void FUN_141322400(const Scaleform::GFx::FunctionHandler::Params&);   // register button
    void FUN_141322520(const Scaleform::GFx::FunctionHandler::Params&);   // remove button

private:
    MS2_LAYOUT_FRIEND;
    Unk_PsRegState m_180;                                       // +0x180 the title being registered
    Unk_PsRegState m_190;                                       // +0x190 the title last registered
    Unk_PsRegState m_1a0;                                       // +0x1a0
    MS2Ptr<Unk_PsCombo> m_1b0;                                  // +0x1b0 m_maxUserCountCombo
    MS2Ptr<Unk_PsInput> m_1c0;                                  // +0x1c0 m_inputTitle
    MS2Ptr<Unk_PsCheck> m_1d0;                                  // +0x1d0 m_checkAllowAutoJoin
    MS2Ptr<Unk_PsButton> m_1e0;                                 // +0x1e0 m_btnRegister
    MS2Ptr<Unk_PsButton> m_1f0;                                 // +0x1f0 m_btnRemove
    ATL::CAtlArray<CStringW> m_200;                             // +0x200 random title templates
    CStringW m_220;                                             // +0x220
};
MS2_CHECK_SIZE(UIPartySearchRegisterDialog, 0x228);
MS2_CHECK_OFFSET(UIPartySearchRegisterDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIPartySearchRegisterDialog, m_1b0, 0x1b0);
MS2_CHECK_OFFSET(UIPartySearchRegisterDialog, m_200, 0x200);
MS2_CHECK_OFFSET(UIPartySearchRegisterDialog, m_220, 0x220);
