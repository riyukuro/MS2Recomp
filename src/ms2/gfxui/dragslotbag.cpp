// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). DragSlotBag, the container of named DragSlots
// ("<bag name>.<index>") of the GFx UI library.
// MS2-UNIT: ?\dragslotbag.cpp
// MS2-RANGE: 0x1422cc8f0-0x1422cdda0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Unit
// boundaries: the ctor 0x1422cc8f0 follows DragSlot's COMDAT tail (its slot name helper 0x1422cc860); ASButton's ctor
// starts the next obj at 0x1422cdda0. The obj's COMDAT tail is the std::map<int, CString> insert / erase / find
// instances, the efd DynamicCast<DragSlot> pair, the scalar deleting dtor and the efd RTTI slots 2-4. The class is
// declared in src/ms2/gfxui/dragslot.h.
#define MS2_THIS_FILE "dragslotbag.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "dragslot.h"
#include "notifyhandler.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

typedef std::pair<const int, CString> SlotEntry;      // m_slots value type

// @0x1422cc8f0
DragSlotBag::DragSlotBag(const CString& strName)
    : NotifyContext::BindData(strName)
{
}

// @0x1422cc950
DragSlotBag::~DragSlotBag()
{
}

// @0x1422cc990
void DragSlotBag::vfunc_10(int nCount)
{
    for (int i = 0; i < nCount; i++)
        FUN_1422ccb50(i);
}
MS2_REPLACE_METHOD(0x1422CC990, DragSlotBag, vfunc_10, 64, 0x9024D7ED);

// @0x1422cc9e0
void DragSlotBag::FUN_1422cc9e0()
{
    for (SlotEntry slot : m_slots)
        Unk_NotifyContext::FUN_1422c8f70(slot.second);
    m_slots.clear();
}
MS2_REPLACE_METHOD(0x1422CC9E0, DragSlotBag, FUN_1422cc9e0, 165, 0xA833FB3F);

// @0x1422cca90
void DragSlotBag::FUN_1422cca90()
{
    for (SlotEntry slot : m_slots) {
        DragSlot* pSlot = FUN_1422cd0f0(slot.second);
        if (pSlot != NULL)
            pSlot->FUN_1422c8be0();
    }
}
MS2_REPLACE_METHOD(0x1422CCA90, DragSlotBag, FUN_1422cca90, 176, 0x722B8396);

// @0x1422ccb50
void DragSlotBag::FUN_1422ccb50(int nIndex)
{
    DragSlot* pSlot = vfunc_16(nIndex);
    if (pSlot != NULL) {
        Unk_NotifyContext::FUN_1422c8f10(pSlot->FUN_1422c89f0(), pSlot);
        m_slots.insert(std::make_pair(nIndex, pSlot->FUN_1422c89f0()));
    }
}
MS2_REPLACE_METHOD(0x1422CCB50, DragSlotBag, FUN_1422ccb50, 263, 0xA744F978);

// @0x1422ccc60
void DragSlotBag::FUN_1422ccc60(int nIndex)
{
    FUN_1422cccc0(vfunc_15(nIndex), nIndex);
}
MS2_REPLACE_METHOD(0x1422CCC60, DragSlotBag, FUN_1422ccc60, 79, 0x08086750);

// @0x1422cccc0
void DragSlotBag::FUN_1422cccc0(CString strName, int nIndex)
{
    Unk_NotifyContext::FUN_1422c8f70(strName);
    m_slots.erase(nIndex);
}

// @0x1422ccd20
size_t DragSlotBag::FUN_1422ccd20()
{
    return m_slots.size();
}
MS2_REPLACE_METHOD(0x1422CCD20, DragSlotBag, FUN_1422ccd20, 31, 0x8299EAD7);

// @0x1422ccd50
void DragSlotBag::vfunc_11(void* p)
{
    for (SlotEntry slot : m_slots) {
        DragSlot* pSlot = efd::DynamicCast<DragSlot>(FUN_1422cd0f0(slot.second));
        if (pSlot != NULL)
            pSlot->vfunc_23(p);
    }
}
MS2_REPLACE_METHOD(0x1422CCD50, DragSlotBag, vfunc_11, 206, 0x38300B5F);

// @0x1422cce30
void DragSlotBag::vfunc_12(void* p)
{
    for (SlotEntry slot : m_slots) {
        DragSlot* pSlot = efd::DynamicCast<DragSlot>(FUN_1422cd0f0(slot.second));
        if (pSlot != NULL)
            pSlot->vfunc_24(p);
    }
}
MS2_REPLACE_METHOD(0x1422CCE30, DragSlotBag, vfunc_12, 206, 0x569339EF);

// @0x1422ccf10
void DragSlotBag::vfunc_13(int i)
{
    DragSlot* pSlot = FUN_1422cd070(i);
    if (pSlot != NULL)
        pSlot->vfunc_11();
}
MS2_REPLACE_METHOD(0x1422CCF10, DragSlotBag, vfunc_13, 61, 0x9CDBD180);

// @0x1422ccf60
void DragSlotBag::vfunc_14(int i)
{
    DragSlot* pSlot = FUN_1422cd070(i);
    if (pSlot != NULL)
        pSlot->vfunc_10();
}
MS2_REPLACE_METHOD(0x1422CCF60, DragSlotBag, vfunc_14, 61, 0x9D72C623);

// @0x1422ccfb0
CString DragSlotBag::FUN_1422ccfb0(int nIndex) const
{
    std::map<int, CString>::const_iterator it = m_slots.find(nIndex);
    if (it != m_slots.end())
        return CString(it->second);
    return CString("");
}
MS2_REPLACE_METHOD(0x1422CCFB0, DragSlotBag, FUN_1422ccfb0, 181, 0xB4ED29CE);

// @0x1422cd070
DragSlot* DragSlotBag::FUN_1422cd070(int nIndex)
{
    return efd::DynamicCast<DragSlot>(FUN_1422cd0f0(vfunc_15(nIndex)));
}
MS2_REPLACE_METHOD(0x1422CD070, DragSlotBag, FUN_1422cd070, 112, 0x7DCE208C);

// @0x1422cd0f0
DragSlot* DragSlotBag::FUN_1422cd0f0(const CString& strName)
{
    return efd::DynamicCast<DragSlot>(Unk_NotifyContext::FUN_1422c8e90(strName));
}
MS2_REPLACE_METHOD(0x1422CD0F0, DragSlotBag, FUN_1422cd0f0, 37, 0x1257B5EC);

// @0x1422cd120
CString DragSlotBag::vfunc_15(int i)
{
    return FUN_1422cc860(FUN_1422c89f0(), i);
}
MS2_REPLACE_METHOD(0x1422CD120, DragSlotBag, vfunc_15, 118, 0xE30FB8C9);

// @0x1422cd1a0
DragSlot* DragSlotBag::vfunc_16(int n)
{
    return NULL;
}

// @0x1422cd1c0
void DragSlotBag::FUN_1422cd1c0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    Scaleform::GFx::Movie* pMovie = params.pMovie;
    if (pMovie != NULL) {
        pMovie->CreateArray(params.pRetVal);
        for (SlotEntry slot : m_slots) {
            Scaleform::GFx::Value name;
            pMovie->CreateString(&name, slot.second);
            params.pRetVal->PushBack(name);
        }
    }
}
MS2_REPLACE_METHOD(0x1422CD1C0, DragSlotBag, FUN_1422cd1c0, 277, 0xA8EBF66A);

// MS2-PIN: ??_GDragSlotBag@@UEAAPEAXI@Z 0x1422cda80
