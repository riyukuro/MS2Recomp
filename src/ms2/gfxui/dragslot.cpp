// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). DragSlot, the drag & drop item slot base of the GFx UI
// library (NotifyContext::BindData + ITooltip).
// MS2-UNIT: ?\dragslot.cpp
// MS2-RANGE: 0x1422cc350-0x1422cc8f0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/gfxui/dragslot.h. The obj's COMDAT tail is the ITooltip ctor, the scalar deleting dtor,
// the efd RTTI slots 2-4 and the "<bag name>.<index>" slot name helper 0x1422cc860.
#include "ms2/placeholder/ms2stdafx.h"

#include "dragslot.h"

#include "hook/ms2hook.h"

// @0x1422cc350
DragSlot::DragSlot(const CString& strName, int nIndex)
    : NotifyContext::BindData(strName)
{
    m_nIndex = nIndex;
    m_bDragging = 0;
}

// @0x1422cc3d0
DragSlot::~DragSlot()
{
}

// @0x1422cc410
int DragSlot::GetIndex()
{
    return m_nIndex;
}

// @0x1422cc430
int DragSlot::vfunc_10()
{
    FUN_1422c8be0();
    return 1;
}
MS2_REPLACE_METHOD(0x1422CC430, DragSlot, vfunc_10, 29, 0x31838FF1);

// @0x1422cc460
int DragSlot::vfunc_11()
{
    FUN_1422c8b50();
    return 1;
}
MS2_REPLACE_METHOD(0x1422CC460, DragSlot, vfunc_11, 29, 0xCB1A51CE);

// @0x1422cc490
int DragSlot::vfunc_12()
{
    return vfunc_10();
}
MS2_REPLACE_METHOD(0x1422CC490, DragSlot, vfunc_12, 30, 0x43E76099);

// @0x1422cc4c0
void DragSlot::vfunc_5()
{
    if (m_bDragging)
        vfunc_21();
}
MS2_REPLACE_METHOD(0x1422CC4C0, DragSlot, vfunc_5, 47, 0x975C4C12);

// @0x1422cc500
int DragSlot::vfunc_13()
{
    return vfunc_10();
}
MS2_REPLACE_METHOD(0x1422CC500, DragSlot, vfunc_13, 30, 0x43E76099);

// @0x1422cc530
int DragSlot::vfunc_14()
{
    return vfunc_10();
}
MS2_REPLACE_METHOD(0x1422CC530, DragSlot, vfunc_14, 30, 0x43E76099);

// @0x1422cc560
int DragSlot::vfunc_15()
{
    return vfunc_10();
}
MS2_REPLACE_METHOD(0x1422CC560, DragSlot, vfunc_15, 30, 0x43E76099);

// @0x1422cc590
int DragSlot::vfunc_16()
{
    return vfunc_10();
}
MS2_REPLACE_METHOD(0x1422CC590, DragSlot, vfunc_16, 30, 0x43E76099);

// @0x1422cc5c0
int DragSlot::vfunc_17()
{
    return vfunc_12();
}
MS2_REPLACE_METHOD(0x1422CC5C0, DragSlot, vfunc_17, 30, 0x93680E89);

// @0x1422cc5f0
int DragSlot::vfunc_18(void* p)
{
    return 1;
}

// @0x1422cc610
int DragSlot::vfunc_19()
{
    return 0;
}

// @0x1422cc620
int DragSlot::vfunc_20()
{
    m_bDragging = 1;
    return 1;
}
MS2_REPLACE_METHOD(0x1422CC620, DragSlot, vfunc_20, 26, 0xC0A2C3C1);

// @0x1422cc640
int DragSlot::vfunc_21()
{
    m_bDragging = 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1422CC640, DragSlot, vfunc_21, 26, 0x7A26F76C);

// @0x1422cc660
int DragSlot::vfunc_7(void* p)
{
    return vfunc_10();
}
MS2_REPLACE_METHOD(0x1422CC660, DragSlot, vfunc_7, 35, 0xBD437922);

// @0x1422cc690
int DragSlot::vfunc_0(void* p)
{
    return 0;
}

// @0x1422cc6b0
CStringW DragSlot::vfunc_22()
{
    return L"";
}
MS2_REPLACE_METHOD(0x1422CC6B0, DragSlot, vfunc_22, 61, 0x234E2048);

// @0x1422cc700
void DragSlot::vfunc_23(void* p)
{
}

// @0x1422cc720
void DragSlot::vfunc_24(void* p)
{
}

// The slot name of index nIndex of the bag strName (DragSlotBag::vfunc_15's format; called by the game bags).
// @0x1422cc860
CString FUN_1422cc860(const CString& strName, int nIndex)
{
    CString str;
    str.Format("%s.%d", (const char*)strName, nIndex);
    return str;
}

// MS2-PIN: ??0ITooltip@@QEAA@XZ 0x1422cc730
// MS2-PIN: ??_GDragSlot@@UEAAPEAXI@Z 0x1422cc750
// MS2-PIN: ??_7DragSlot@@6BBindData@NotifyContext@@@ 0x14310c908
