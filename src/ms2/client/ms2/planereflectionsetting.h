// planereflectionsetting.h - CPlaneReflectionSetting: Gamebryo built-in model (egf::IBuiltinModelImpl) holding the
// parameters of one planar reflection (enable flag and two vectors).
// Owning unit: ?\planereflectionsetting.cpp (0x14168b4a0-0x1416916b0 + .di 0x1400fbab0-0x1400fbb00, dir client\ms2).
// Property ids are the model-data ids from the game's flat-model definitions (names unknown, so hex-named); the exe
// has them in .rdata at 0x142f4d590 (sorted by value, as in the generated id header).
#pragma once
#include "ms2/ms2layout.h"
#include <egf/IBuiltinModelImpl.h>
#include <egf/BuiltinModelHelper.h>
#include <efd/Point3.h>

static const efd::ClassID kCLASSID_CPlaneReflectionSetting = 0x06200017u;

static const egf::PropertyID kPropertyID_CPlaneReflectionSetting_01FB08FF = 0x01FB08FFu;
static const egf::PropertyID kPropertyID_CPlaneReflectionSetting_1A9FD6A7 = 0x1A9FD6A7u;
static const egf::PropertyID kPropertyID_CPlaneReflectionSetting_2683E9EC = 0x2683E9ECu;

// 0x40 bytes. vftables 0x142f4da30 (IBuiltinModelImpl side) and 0x142f4dac0 (+0x10).
class CPlaneReflectionSetting : public egf::IBuiltinModelImpl
{
    EE_DECLARE_CLASS1(CPlaneReflectionSetting, kCLASSID_CPlaneReflectionSetting, egf::IBuiltinModelImpl);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;

    EE_DECLARE_BUILTINMODEL_PROPERTIES

        EE_BUILTINMODELPROPERTY(CPlaneReflectionSetting, kPropertyID_CPlaneReflectionSetting_2683E9EC, bool, CPlaneReflectionSetting, m_bEnable)
        EE_BUILTINMODELPROPERTY(CPlaneReflectionSetting, kPropertyID_CPlaneReflectionSetting_01FB08FF, efd::Point3, CPlaneReflectionSetting, m_vA)
        EE_BUILTINMODELPROPERTY(CPlaneReflectionSetting, kPropertyID_CPlaneReflectionSetting_1A9FD6A7, efd::Point3, CPlaneReflectionSetting, m_vB)

    EE_END_BUILTINMODEL_PROPERTIES;

public:
    CPlaneReflectionSetting();                      // 0x14168b4a0
    virtual ~CPlaneReflectionSetting();             // 0x14168b530

    bool m_bEnable;                                 // +0x24
    efd::Point3 m_vA;                               // +0x28
    efd::Point3 m_vB;                               // +0x34

    bool IsEnabled() { return m_bEnable; }      // inline, emitted in postprocessingservice.cpp
    efd::Point3& FUN_1416b0e20() { return m_vA; }    // inline, emitted in postprocessingservice.cpp
    efd::Point3& FUN_1416b0de0() { return m_vB; }    // inline, emitted in postprocessingservice.cpp
};
MS2_CHECK_SIZE(CPlaneReflectionSetting, 0x40);
MS2_CHECK_OFFSET(CPlaneReflectionSetting, m_bEnable, 0x24);
MS2_CHECK_OFFSET(CPlaneReflectionSetting, m_vB, 0x34);
