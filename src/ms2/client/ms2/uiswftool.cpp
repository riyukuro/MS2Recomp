// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISwfTool is the "SwfTool" debug UI object (UI type id
// 0x4e54): on load it asks its movie root for the "alignment" and "enter" ActionScript members (the swf tool's own
// layout entries), and it has no members or state of its own. The unit also holds its unreferenced CRT memmove_s
// copy (0x141b129b0).
// MS2-UNIT: ?\uiswftool.cpp
// MS2-RANGE: 0x141b127f0-0x141b12ad0 .text$mn
// MS2-PIN: ??_7UISwfTool@@6B@ 0x142fe67f8 ; order
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiswftool.cpp"    // assumed
// The exe's memmove_s is a plain call (no /Oi expansion); the pragma must precede the inline copy below.
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include <errno.h>
#include <new>
#include <string.h>
#include <vcruntime_string.h>

#include "uiswftool.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x141b127f0
UISwfTool::UISwfTool()
{
}

// @0x141b12840
UISwfTool::~UISwfTool()
{
}

// @0x141b12880
CString UISwfTool::GetTypeName()
{
    return "SwfTool";
}

// The movie root, once loaded, is asked to lay itself out for the tool (the two AS members the swf exposes).
// @0x141b128d0
void UISwfTool::vfunc_43()
{
    if (m_30.get() != 0)
    {
        m_30.operator->()->Invoke("alignment");
        m_30.operator->()->Invoke("enter");
    }
}

// @0x141b129a0
int UISwfTool::vfunc_48()
{
    return 0x4e54;
}

// The UCRT's `static __inline memmove_s` of this TU (unreferenced copy).
// @0x141b129b0
MS2_EMIT_CRT_MEMMOVE_S();
