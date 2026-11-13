// stormbar.h - Mushking Royale restore: UIStormBar (GMS 0x4f67, vftable 0x175863c, here MS2_UI_STORMBAR, swf "StormBar").
// NOT recovered KMS code; ported from the GMS 2019 x86 client. Branch restore/mushking only.
// Included by stormbar.cpp and survivalkilllogdialog.cpp (field-leave close).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class UIStormBar : public UIDialog
{
public:
    UIStormBar();                                   // GMS 0x899300
    virtual ~UIStormBar();
    virtual CString GetTypeName();                  // 1 (GMS 0x8992c0) "StormBar"
    virtual void OnLoadComplete();                  // 22 (GMS 0x899560) replay the countdown
    virtual void vfunc_43();                        // 43 (GMS 0x8994a0) dock
    virtual int vfunc_48() { return 0x4fc7; }       // 48 (GMS 0x899870) MS2_UI_STORMBAR
    virtual int vfunc_65();                         // 65 open
    virtual void vfunc_72();                        // 72 (GMS 0x899640) tick: "update"

    void SetZone(int nCurR, const float* pCur, int nNextR, const float* pNext);   // GMS 0x899380
    void ClearZone() { m_bZone = false; }
    void SetCountdown(int nSeconds);                // GMS 0x8992f0 (+ "setStopWatch" when loaded)

private:
    bool m_bZone;               // GMS +0x48 a zone is set
    int m_nCountdown;           // GMS +0x4c kept until the movie is loaded
    int m_nDist;                // GMS +0x54 round(max(0, |cur - next| + curR - nextR))
    int m_nCurR;                // GMS +0x58
    float m_cur[3];             // GMS +0x5c
    int m_nNextR;               // GMS +0x68
    float m_next[3];            // GMS +0x6c
    int m_nFieldId;             // the field the game runs in (close on leave)
};
