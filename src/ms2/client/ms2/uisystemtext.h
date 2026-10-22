// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uisystemtext.h (name assumed from the unit
// path: the .cpp's __FILE__ string is not in the exe for this unit).
//
// UISystemText ("SystemText", UI type from FUN_141277f50 = 3, RTTI .?AVUISystemText@@, 0x98 bytes): the HUD system
// messages (warning / info / quest / GM / field name / letter / emergency / interact / guild megaphone lines). A message
// shown before the movie is loaded is parked in m_70 / m_78 and replayed by OnLoadComplete. The timed "other" messages
// are remembered in a map (type -> expiry tick) and cleared by vfunc_15. Names: virtuals are Ghidra's vfunc_<slot>;
// FUN_<va> are non-virtual members; fields are invented.
#pragma once

#include <afx.h>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"

class UISystemText : public UIHeadUpDisplay
{
public:
    UISystemText();                                                 // 0x141b15900 (m_28 = 3, m_2c = 0x24)
    virtual ~UISystemText();                                        //  0 0x141b159b0 (??_G 0x141b189f0)
    virtual CString GetTypeName();                                      //  1 0x141b15a20 "SystemText"
    virtual void vfunc_2();                                         //  2 0x141b15e60 show (the base's)
    virtual void vfunc_3();                                         //  3 0x141b15e80 hide, forget the parked message
    virtual void OnLoadComplete();                                  // 22 0x141b15a70 replay the parked message
    virtual void vfunc_15();                                        // 15 0x141b15b50 expire the timed messages
    virtual void vfunc_43();                                        // 43 0x141b15ca0 place the movie below the upper hp bar
    virtual int vfunc_48() { return 0x4e41; }                       // 48 0x141b18a30 UI type id

    void FUN_141b15ec0(const CStringW& strText, int nType, int nOption);   // show a message
    void FUN_141b16270(const CStringW& strText, int nType, int nDuration);  // show a timed message

private:
    MS2_LAYOUT_FRIEND;
    int m_70;                                                       // +0x70 parked message type (0 = none)
    CStringW m_78;                                                  // +0x78 parked message text
    unsigned int m_80;                                              // +0x80 parked message expiry tick
    std::map<int, unsigned int> m_88;                               // +0x88 timed messages: type -> expiry tick
};
MS2_CHECK_SIZE(UISystemText, 0x98);
MS2_CHECK_OFFSET(UISystemText, m_70, 0x70);
MS2_CHECK_OFFSET(UISystemText, m_78, 0x78);
MS2_CHECK_OFFSET(UISystemText, m_80, 0x80);
MS2_CHECK_OFFSET(UISystemText, m_88, 0x88);
