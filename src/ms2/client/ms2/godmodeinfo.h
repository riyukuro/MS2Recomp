// godmodeinfo.h - CGodModeInfo (RTTI .?AVCGodModeInfo@@, 0x30 bytes, vftable 0x142efb228, 1 slot): the client-side
// debug "god mode" marker. It owns a UIDebugTooltip anchored 150 above a position that shows the current mode index,
// and sends the index to the server (0x37/0x13) whenever it changes. NOT an original header (name from the vftable
// symbol, layout from the ctor 0x141374a90 and the scalar deleting dtor 0x141375100). Base CPtred (ctor 0x140159740).
// Owning unit ?\godmodeinfo.cpp (0x141374a90-0x141375250). cubecraft_1/2.cpp declare the same class locally.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"

class UIDebugTooltip;

class CGodModeInfo : public CPtred
{
public:
    CGodModeInfo();                                     // 0x141374a90
    virtual ~CGodModeInfo();                            // 0x141374af0 (??_G 0x141375100)

    void FUN_141374b80(Unk_StreamPoint kPos);           // 0x141374b80 create the tooltip at kPos
    void FUN_141374d10(int n);                          // 0x141374d10 set the index and push it
    void FUN_141374d40(Unk_StreamPoint kPos);           // 0x141374d40 anchor the tooltip at kPos + (0, 0, 150)
    void FUN_141374dd0(void* pInput);                   // 0x141374dd0 '-' (0x7d) / 'x' (0x78) step the index
    void SendRequestCube();                               // 0x141374ea0 refresh the text and send 0x37/0x13

    int m_n18;                                          // +0x18 the mode index
    int m_pad_1c;
    MS2Ptr<UIDebugTooltip> m_spTooltip;                 // +0x20 the anchor text object
};
MS2_CHECK_SIZE(CGodModeInfo, 0x30);
MS2_CHECK_OFFSET(CGodModeInfo, m_n18, 0x18);
MS2_CHECK_OFFSET(CGodModeInfo, m_spTooltip, 0x20);
