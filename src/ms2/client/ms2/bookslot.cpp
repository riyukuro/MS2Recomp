// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). BookSlot and BookSlotBag (the skill book window's slots).
// MS2-UNIT: ?\bookslot.cpp
// MS2-RANGE: 0x140a365c0-0x140a376e0 .text$mn
// MS2-RANGE: 0x1400c3320-0x1400c34f0 .text$di
// MS2-PIN: ??_7BookSlot@@6BBindData@NotifyContext@@@ 0x142dc56a0 ; hand: primary vftable
// MS2-PIN: ?TypeCast@BookSlot@@UEBA_NIPEAPEAX@Z 0x140a36a70 ; hand
// MS2-PIN: ?TypeCast@BookSlot@@UEBA_NIPEAPEBX@Z 0x140a36ac0 ; hand
// MS2-PIN: ?TypeCast@BookSlotBag@@UEBA_NIPEAPEAX@Z 0x140a37640 ; hand
// MS2-PIN: ?TypeCast@BookSlotBag@@UEBA_NIPEAPEBX@Z 0x140a37690 ; hand
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\bookslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "bookslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class JobSkill : public CPtred
{
public:
    unsigned GetID();                                   // 0x140637cc0
};

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

BookSlotBag* FUN_140a37100(NotifyContext::BindData* p);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(BookSlot);
EE_IMPLEMENT_CONCRETE_CLASS_INFO(BookSlotBag);

// Header-defined statics (same in every obj that includes the shared item header; here with the null handle before
// the condition object).
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/statemanager_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION

// @0x140a365c0
BookSlot::BookSlot(const CString& strName, int nIndex, MS2Ptr<JobSkill> spSkill)
    : MS2DragSlot(strName, nIndex), m_spSkill(spSkill)
{
}

// @0x140a36650
BookSlot::~BookSlot()
{
}

// @0x140a366a0
unsigned BookSlot::FUN_140a366a0()
{
    if (m_spSkill.get() != 0)
        return ((JobSkill*)m_spSkill)->GetID();
    return 0;
}

// @0x140a366f0
int BookSlot::vfunc_11()
{
    m_spSkill = 0;
    return DragSlot::vfunc_11();
}

// @0x140a36730
int BookSlot::vfunc_18(void* p)
{
    if (p != 0)
        static_cast<DragSlot*>(p)->vfunc_10();
    vfunc_10();
    return 1;
}

// @0x140a36780 (ITooltip::vfunc_0)
int BookSlot::vfunc_0(void* p)
{
    return 1;
}

// @0x140a367a0
int BookSlot::vfunc_8(void* p)
{
    if (!m_spSkill)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c4360(reinterpret_cast<Unk_SlotSkillInfo*>(m_spSkill.get()), 0x401) != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140a36c30
void FUN_140a36c30(const CString& strName, std::vector<MS2Ptr<JobSkill> >& skills)
{
    BookSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) BookSlotBag(strName, skills);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10((int)skills.size());
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140a36d00
void FUN_140a36d00(const CString& strName)
{
    BookSlotBag* pBag = FUN_140a37100(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x140a36d50
BookSlotBag::BookSlotBag(const CString& strName, std::vector<MS2Ptr<JobSkill> >& skills)
    : DragSlotBag(strName)
{
    for (auto& spSkill : skills)
        m_skills.Add(spSkill);
}

// @0x140a36e20
BookSlotBag::~BookSlotBag()
{
}

// @0x140a36e60
CString BookSlotBag::vfunc_15(int nIndex)
{
    CString str;
    str.Format("%s.%d", (const char*)FUN_1422c89f0(), (unsigned)nIndex);
    return str;
}

// @0x140a36f20
DragSlot* BookSlotBag::vfunc_16(int nIndex)
{
    return new (efd::MemHint(efd::MemHint::NONE)) BookSlot(vfunc_15(nIndex), nIndex, FUN_140a37060(nIndex));
}

// @0x140a37060
MS2Ptr<JobSkill> BookSlotBag::FUN_140a37060(int nIndex)
{
    if (m_skills.GetCount() <= (size_t)nIndex)
        return MS2Ptr<JobSkill>(0);
    return m_skills[nIndex];
}

// @0x140a37100
BookSlotBag* FUN_140a37100(NotifyContext::BindData* p)
{
    BookSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200052, (void**)&pBag))
        return pBag;
    else
        return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9f040-0x142c9f0d0 .text$yd
