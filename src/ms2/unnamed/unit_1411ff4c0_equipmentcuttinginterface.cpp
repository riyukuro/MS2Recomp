// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The equipment-cutting interface and its "priority" implementation
// (hides the model parts named by the <cutting> lists of every worn item), the vector<CString> iterator glue it needs and
// this TU's copy of the CRT memcpy_s. The CU name is unknown (queue guess ?\priortycutting.cpp); class names are RTTI.
// MS2-UNIT: unit_1411ff4c0
// MS2-RANGE: 0x1411ff4c0-0x1411ffa10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?begin@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x1411ff800 ; unique
// MS2-PIN: ?end@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x1411ff860 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: memcpy_s 0x1411ff8c0
#define MS2_THIS_FILE ""
// The exe's memcpy_s is a plain call (no /Oi expansion); the pragma must precede the inline copy.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <vcruntime_string.h>
#include <vector>
#include <NiRefObject.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class MyPC;

// The equip holder the cutting works on (+8 is the owning PC); names invented.
struct Unk_CuttingTarget
{
    void FUN_1411e2e40(ATL::CAtlList<MS2Ptr<CEquipItem> >& kOut);     // 0x1411e2e40 the worn items
    MyPC* FUN_1411e0ee0();                                          // 0x1411e0ee0 the owning PC
    void FUN_1411e8d20(const CString& strName);                     // 0x1411e8d20 hide the model part
};
class PC   // C3: member view for the former free stand-ins
{
public:
    int FUN_141658e60();
};
CItemData* FUN_1411dc7f0_1(CEquipItem* pEquip);                     // CEquipItem::FUN_1411dc7f0 seen as the item data

// The cutting interface: slot 2 is pure (0x10 bytes, vftable 0x142ec0578).
class IEquipmentCutting : public NiRefObject
{
public:
    IEquipmentCutting();                // 0x1411ff6e0
    virtual ~IEquipmentCutting();       // 0x1411ff710
    virtual void vfunc_2() = 0;
};
MS2_CHECK_SIZE(IEquipmentCutting, 0x10);

// Hides, for every worn item, the model parts named by its <cutting> list (0x18 bytes, vftable 0x142ec0598).
class CPriortyCutting : public IEquipmentCutting
{
public:
    explicit CPriortyCutting(Unk_CuttingTarget* pTarget);       // 0x1411ff4c0
    virtual ~CPriortyCutting();                                  // 0x1411ff510
    virtual void vfunc_2();                                      // 0x1411ff540
private:
    Unk_CuttingTarget* m_pTarget;                                // +0x10
};
MS2_CHECK_SIZE(CPriortyCutting, 0x18);

// @0x1411ff4c0
CPriortyCutting::CPriortyCutting(Unk_CuttingTarget* pTarget)
    : IEquipmentCutting()
{
    m_pTarget = pTarget;
}

// @0x1411ff510
CPriortyCutting::~CPriortyCutting()
{
}

// @0x1411ff540
void CPriortyCutting::vfunc_2()
{
    ATL::CAtlList<MS2Ptr<CEquipItem> > equipped(10);
    m_pTarget->FUN_1411e2e40(equipped);
    unsigned nGender = ((class PC*)(class MyPC*)(m_pTarget->FUN_1411e0ee0()))->FUN_141658e60();
    POSITION pos = equipped.GetHeadPosition();
    while (pos != 0) {
        MS2Ptr<CEquipItem> equip(equipped.GetNext(pos));
        if (!equip) {
            continue;
        }
        ItemModelData* pModel = FUN_1411dc7f0_1(equip.get())->FUN_14053eba0();
        std::vector<CString>* pNames = pModel->FUN_14054b2c0(nGender);
        std::vector<CString>& names = *pNames;
        std::vector<CString>::iterator itEnd = names.end();
        for (std::vector<CString>::iterator it = names.begin(); it != itEnd; ++it) {
            CString strName(*it);
            m_pTarget->FUN_1411e8d20(strName);
        }
    }
}

// @0x1411ff6e0
IEquipmentCutting::IEquipmentCutting()
{
}

// @0x1411ff710
IEquipmentCutting::~IEquipmentCutting()
{
}

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
