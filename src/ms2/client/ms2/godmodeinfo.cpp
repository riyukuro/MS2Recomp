// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CGodModeInfo: the debug "god mode" marker the client
// cube code (cubecraft_1/2.cpp) pokes from the key handler. It creates a UIDebugTooltip ("Consturction Group") at a
// position + 150 up, writes the mode index into it, and mirrors every index change to the server (packet 0x37,
// sub-op 0x13). Also holds this unit's MS2Ptr<UIDebugTooltip> instantiation copies (the exe emits them in the first
// obj that used them) and the unit's unreferenced CRT memmove_s copy.
// MS2-UNIT: ?\godmodeinfo.cpp
// MS2-RANGE: 0x141374a90-0x141375250 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\godmodeinfo.cpp"
// The exe's 12-byte point copies are plain rep movsb (no /Oi expansion); the pragma must precede the inline copies.
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <new>
#include <string.h>

#include "ms2/client/ms2/godmodeinfo.h"
#include "ms2/client/ms2/uidebugtooltip.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

// ---- callees outside this unit ----

// The "debug layer enabled" flag (written by the debug key handler).
extern int DAT_143ae0fb4;                                   // 0x143ae0fb4
// Is `nKey` (a VK code) currently held in the input state of `pInput`?
bool FUN_1416830b0(void* pInput, int nKey);                 // 0x1416830b0
// Clamps the mode index to the table range.
int FUN_140ad02c0(int nValue, int nMin);                    // 0x140ad02c0

// ---- CGodModeInfo ----

// @0x141374a90
CGodModeInfo::CGodModeInfo() : m_n18(0), m_spTooltip(0)
{
}

// Drops the tooltip: unregister it from the manager, then release the reference.
// @0x141374af0
CGodModeInfo::~CGodModeInfo()
{
    if (m_spTooltip.get() != 0)
    {
        m_spTooltip->FUN_14191aa70();
        m_spTooltip = 0;
    }
}

// Creates the tooltip at `kPos`, anchors it there and fills in the current index.
// @0x141374b80
void CGodModeInfo::FUN_141374b80(Unk_StreamPoint kPos)
{
    m_spTooltip.AssignRaw(new UIDebugTooltip(CString("Consturction Group")));
    // The anchor is materialised in a local: the exe's call site copies the 12 bytes before the pass.
    alignas(16) Unk_StreamPoint ptAnchor = kPos;
    m_spTooltip->FUN_14191aae0(ptAnchor);
    CStringW strText;
    strText.Format(L"%d", m_n18);
    m_spTooltip->FUN_14191ab10(strText);
    m_spTooltip->FUN_14191aa10();
}

// @0x141374d10
void CGodModeInfo::FUN_141374d10(int n)
{
    m_n18 = n;
    SendRequestCube();
}

// Moves the tooltip 150 units above `kPos`.
// @0x141374d40
void CGodModeInfo::FUN_141374d40(Unk_StreamPoint kPos)
{
    if (m_spTooltip.get() != 0)
    {
        Unk_StreamPoint ptMoved = kPos.FUN_14097fd50(Unk_StreamPoint(0.0f, 0.0f, 150.0f));
        // MS2-FUNCTIONAL: the exe's FUN_14191aae0 takes the point by value, so its call site copies the operator+
        // result into the outgoing argument slot (rep movsb into [rsp+0x20], the sret living at [rsp+0x3c]); the
        // committed header binds that callee as const&, so the copy is an explicit local instead and MSVC sizes the
        // slots the other way round (sret [rsp+0x20], copy [rsp+0x30]). Instruction-by-instruction identical
        // otherwise; 49 bytes differ in which 12-byte slot is which.
        alignas(16) Unk_StreamPoint ptAnchor = ptMoved;
        m_spTooltip->FUN_14191aae0(ptAnchor);
    }
}

// '-' steps the index down, 'x' steps it up; a change is clamped and pushed.
// @0x141374dd0
void CGodModeInfo::FUN_141374dd0(void* pInput)
{
    if (DAT_143ae0fb4 != 0 && (bool)m_spTooltip.get())
    {
        int nValue = m_n18;
        if (FUN_1416830b0(pInput, 0x7d))
            nValue--;
        if (FUN_1416830b0(pInput, 0x78))
            nValue++;
        if (nValue != m_n18)
        {
            m_n18 = FUN_140ad02c0(nValue, 0);
            SendRequestCube();
        }
    }
}

// Pushes the index: the tooltip text, then the 0x37/0x13 packet.
// @0x141374ea0
void CGodModeInfo::SendRequestCube()
{
    if (DAT_143ae0fb4 != 0)
    {
        if (m_spTooltip.get() != 0)
        {
            CStringW strText;
            strText.Format(L"%d", m_n18);
            m_spTooltip->FUN_14191ab10(strText);
        }
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.vfunc_o10_1(0x13);
        packet.vfunc_o10_3(m_n18);
        FUN_140710590(packet);
    }
}
