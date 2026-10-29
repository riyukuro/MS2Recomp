// nifmodel.h - CNifModel: CEquipModel loaded from a .nif (size 0x128). Owning unit: ?\nifmodel.cpp
// (0x141565560-0x141567000, dir client\ms2). vftable overrides slots 0-19, 28, 29 of CEquipModel.
#pragma once
#include "ms2/client/ms2/equipmodel.h"

class CNifModel : public CEquipModel
{
public:
    CNifModel(MS2Ptr<Unk_EquipModelOwner> spOwner, void* p18, void* p20);   // 0x141565560
    // virtual ~CNifModel();  implicit (no vftable store in the exe): 0x141566d10, ??_G 0x141566d40

    EE_DECLARE_CLASS1(CNifModel, 0x06200049, CEquipModel);   // slots 1-3 (0x141566d80/0x141566e40/0x141566e90), ms_ClassInfo 0x143ae2440
public:
    virtual int vfunc_4(CString strPath);                   // 0x141565700 load
    virtual void vfunc_5();                                 // 0x141565880
    virtual int vfunc_6();                                  // 0x1415658a0
    virtual int vfunc_7();                                  // 0x1415659e0
    virtual int vfunc_8();                                  // 0x141565ab0
    virtual int vfunc_9();                                  // 0x141565ac0
    virtual void vfunc_10();                                // 0x141565ae0
    virtual void vfunc_11();                                // 0x141565cb0
    virtual void vfunc_12();                                // 0x141565eb0
    virtual void vfunc_13();                                // 0x141566110
    virtual void* vfunc_14();                               // 0x1415665d0
    virtual int vfunc_15();                                 // 0x1415664f0
    virtual void vfunc_16();                                // 0x141566600
    virtual void vfunc_17();                                // 0x141566640
    virtual void vfunc_18();                                // 0x141566890
    virtual void vfunc_19(double fTime);                    // 0x1415668a0
    virtual void vfunc_28(void* pPos, void* pMatrix3, float fScale);   // 0x141566aa0
    virtual void vfunc_29(void* pPos, void* pRotDeg, float fScale);    // 0x1415669c0

public:
    MS2_LAYOUT_FRIEND;
    int m_i118;      // +0x118 pending flag (set by FUN_141566cb0, cleared by vfunc_19)
    int m_i11c;      // +0x11c 1 when the owner's type is 2 (gated by DAT_143ae2b38)
    void* m_p120;    // +0x120 the "FA_Skin" child
};
MS2_CHECK_SIZE(CNifModel, 0x128);
