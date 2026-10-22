// liftabletarget.h - CLiftableTarget (RTTI .?AVCLiftableTarget@@, 0x48 bytes, vftable 3 slots) and its two kinds
// CLiftableTargetBox / CLiftableTargetGuide: the world marker a lifted prop is carried to. Derives CPtred. Owning unit:
// ?\liftabletarget.cpp (0x141448190-0x141448b90). Header name assumed. Method names are FUN_ addresses.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/cubespawnobject.h"

class CLiftableTarget : public CPtred
{
public:
    CLiftableTarget();                                          // 0x141448190
    virtual ~CLiftableTarget();                                 //  0 0x141448230 (??_G 0x141448b50)
    virtual int vfunc_1(Unk_EntRef ent);                        //  1 0x1414482a0 read the target's properties from its entity
    virtual CString vfunc_2() = 0;                              //  2 the marker's effect name

    void FUN_1414483e0();                                       // show the marker while a matching quest step is open
    void FUN_141448750();                                       // start the marker effect
    void FUN_141448920();                                       // stop the marker effect

    int m_nId;                          // +0x18 target id (property 0x79ec600a)
    Vector3 m_vPos;             // +0x1c position (property 0xfd95ca52)
    Vector3 m_vRot;             // +0x28 rotation in degrees (property 0x68c7c29d)
    Unk_EntRef m_ent;                   // +0x38
    int m_nFx;                          // +0x40 effect handle
};
MS2_CHECK_SIZE(CLiftableTarget, 0x48);

class CLiftableTargetBox : public CLiftableTarget
{
public:
    virtual CString vfunc_2();                                  //  2 0x141448970 the box effect name
};
MS2_CHECK_SIZE(CLiftableTargetBox, 0x48);

class CLiftableTargetGuide : public CLiftableTarget
{
public:
    virtual int vfunc_1(Unk_EntRef ent);                        //  1 0x1414489c0 + the guide effect name (property 0x86adffcf)
    virtual CString vfunc_2();                                  //  2 0x141448b00 m_strGuide

    CString m_strGuide;                 // +0x48
};
MS2_CHECK_SIZE(CLiftableTargetGuide, 0x50);
