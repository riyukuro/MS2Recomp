// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiitembillboarddialog.h (name assumed:
// the .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIItemBillBoardDialog is the dialog of the special "item billboard" (an advertisement that a player installs in a field
// with a billboard item and that other players can look at, UI type 0x4f4f, RTTI .?AVUIItemBillBoardDialog@@, 0x260 bytes,
// vftables as every UIDialog). It has two faces:
//   - the customer view (m_bInstall == 0): the title, description, owner name and creation time of the billboard of
//     m_info, a "home" button (opens the owner's home) and, for the staff, a "remove" button (packet 0x9e);
//   - the advertiser view (m_bInstall == 1): the install form (title / description input, "home" check box) used to put
//     the billboard item m_nItemUid into the field; confirming asks the server through the item inventory.
// The server answers with packet 0x105 (6: the billboard info; 7: the result of an install).
// Member and method names are invented where the exe has no name (vfunc_N / FUN_<va> otherwise).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/billboardinfo.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/uidialog.h"

class CInPacket;
class CMsgBoxData;

// A button of the movie ("m_homeButton" / "m_removeButton" / "m_installButton"): an AS display object.
class Unk_BbButton : public ASDisplayObject
{
public:
    void FUN_1422c1fe0(int bEnabled);                                                               // enable / disable
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& callback, int flags);   // click callback
};

class WorldService;

class UIItemBillBoardDialog : public UIDialog
{
public:
    UIItemBillBoardDialog();                                                // 0x140c308c0
    virtual ~UIItemBillBoardDialog();                                       //  0 0x140c30a70 (??_G 0x140c354a0)

    virtual CString vfunc_1();                                              //  1 0x140c30bd0 "ItemBillBoardDialog"
    virtual void OnLoadComplete();                                          // 22 0x140c30c20
    virtual int vfunc_48() { return 0x4f4f; }                               // 48 UI type id (COMDAT 0x140c354e0)
    virtual int vfunc_65();                                                 // 65 0x140c31fa0
    virtual void vfunc_67();                                                // 67 0x140c31fd0 close

    void FUN_140c32020(CInPacket& packet);                                  // packet 0x105: the billboard info / the install result
    __int64 FUN_140c322b0();                                                // the owner of the shown billboard (0 when not shown)
    void FUN_140c32300();                                                   // close the dialog and forget the item
    void FUN_140c32360(__int64 nItemUid);                                   // show the install form for a billboard item
    bool FUN_140c323f0();                                                   // checks that a billboard may be installed here
    void FUN_140c337c0();                                                   // forget the movie clips and buttons
    void FUN_140c33840(const Scaleform::GFx::FunctionHandler::Params& params);   // the install button
    void FUN_140c33fa0(const Scaleform::GFx::FunctionHandler::Params& params);   // the home button
    void SendItemBillboard(const Scaleform::GFx::FunctionHandler::Params& params);   // the remove button
    bool FUN_140c34050(int nResult, const CMsgBoxData& data);               // the install confirmation box result

private:
    MS2_LAYOUT_FRIEND;
    BillBoardInfo m_info;                                                   // +0x178 the shown billboard
    bool m_bInstall;                                                        // +0x200 1: the install form, 0: a shown billboard
    __int64 m_nItemUid;                                                     // +0x208 the billboard item being installed
    MS2Ptr<ASMovieClip> m_customerMovie;                                    // +0x210 "customerMovie"
    MS2Ptr<ASMovieClip> m_advertiserMovie;                                  // +0x220 "advertiserMovie"
    MS2Ptr<Unk_BbButton> m_homeButton;                                      // +0x230 "m_homeButton"
    MS2Ptr<Unk_BbButton> m_removeButton;                                    // +0x240 "m_removeButton"
    MS2Ptr<Unk_BbButton> m_installButton;                                   // +0x250 "m_installButton"
};
MS2_CHECK_SIZE(UIItemBillBoardDialog, 0x260);
MS2_CHECK_OFFSET(UIItemBillBoardDialog, m_info, 0x178);
MS2_CHECK_OFFSET(UIItemBillBoardDialog, m_bInstall, 0x200);
MS2_CHECK_OFFSET(UIItemBillBoardDialog, m_nItemUid, 0x208);
MS2_CHECK_OFFSET(UIItemBillBoardDialog, m_customerMovie, 0x210);
MS2_CHECK_OFFSET(UIItemBillBoardDialog, m_advertiserMovie, 0x220);
MS2_CHECK_OFFSET(UIItemBillBoardDialog, m_homeButton, 0x230);
MS2_CHECK_OFFSET(UIItemBillBoardDialog, m_removeButton, 0x240);
MS2_CHECK_OFFSET(UIItemBillBoardDialog, m_installButton, 0x250);
