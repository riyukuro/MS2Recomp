// cpriortycutting.h - PLACEHOLDER for IEquipmentCutting (RTTI, 0x10, vftable 0x142ec0578) and CPriortyCutting (RTTI,
// 0x18, vftable 0x142ec0598): the equipment's model part cutting (CEquipment +0x40). The owning unit unit_1411ff4c0.cpp
// keeps its own copy of these declarations. NOT an original header.
#pragma once
#include <NiRefObject.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class CEquipItem;
class MyPC;

// The equipment as the cutting sees it (CEquipment derives this empty view).
struct Unk_CuttingTarget
{
    void FUN_1411e2e40(ATL::CAtlList<MS2Ptr<CEquipItem> >& kOut);     // 0x1411e2e40 the worn items
    MyPC* FUN_1411e0ee0();                                          // 0x1411e0ee0 the owning PC
    void FUN_1411e8d20(const CString& strName);                     // 0x1411e8d20 hide the model part
};

class IEquipmentCutting : public NiRefObject
{
public:
    IEquipmentCutting();                // 0x1411ff6e0
    virtual ~IEquipmentCutting();       // 0x1411ff710
    virtual void vfunc_2() = 0;
};
MS2_CHECK_SIZE(IEquipmentCutting, 0x10);

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
