// uitokenpocketdialog.h - UITokenPocketDialog (RTTI .?AVUITokenPocketDialog@@, 0x210 bytes, UIDialog, UI id 0x4ece, swf
// "TokenPocketDialog"): the token pocket box. One slot per token kind the feature set enables (honor, karma, lu, habi,
// reverse coin, mentor / mentee token, star point, meso market token): an icon, the amount text and a tooltip. The amounts
// refresh on the "NotifyChangedTokenMoney" notice.
// Owning unit: ?\uitokenpocketdialog.cpp. Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASUIComponent;
class ASMovieClip;
class NotifyObject;

class UITokenPocketDialog : public UIDialog
{
public:
    UITokenPocketDialog();                                      // 0x1413518a0
    virtual ~UITokenPocketDialog();                             //  0 0x1413519b0 (??_G 0x1413532a0)
    virtual CString GetTypeName();                                  //  1 0x141351aa0 "TokenPocketDialog"
    virtual void OnLoadComplete();                              // 22 0x141351af0 build the token slots
    virtual void vfunc_26();                                    // 26 0x1413522f0 drop the slots, stop listening
    virtual void vfunc_43();                                    // 43 0x1413524b0 place the movie
    virtual int vfunc_48() { return 0x4ece; }                   // 48 0x1413532e0

    void FUN_141352530(NotifyObject* pNotify);                  // "NotifyChangedTokenMoney" handler
    void FUN_141352560();                                       // refresh the amount texts
    MS2Ptr<ASUIComponent> FUN_141352cf0(int nTokenKind, CStringW strTooltip);   // add one token slot
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);  // 0x140ba7930 bind a movie clip child (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                                  // +0x178 the next slot's y (starts at 0x32, +0x17 per slot)
    MS2Ptr<ASUIComponent> m_180;                                // +0x180 honor token
    MS2Ptr<ASUIComponent> m_190;                                // +0x190 karma
    MS2Ptr<ASUIComponent> m_1a0;                                // +0x1a0 lu
    MS2Ptr<ASUIComponent> m_1b0;                                // +0x1b0 habi
    MS2Ptr<ASUIComponent> m_1c0;                                // +0x1c0 reverse coin
    MS2Ptr<ASUIComponent> m_1d0;                                // +0x1d0 mentor token
    MS2Ptr<ASUIComponent> m_1e0;                                // +0x1e0 mentee token
    MS2Ptr<ASUIComponent> m_1f0;                                // +0x1f0 star point
    MS2Ptr<ASUIComponent> m_200;                                // +0x200 meso market token
};
MS2_CHECK_SIZE(UITokenPocketDialog, 0x210);
