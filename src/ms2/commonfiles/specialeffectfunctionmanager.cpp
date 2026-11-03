// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSpecialEffectFunctionManager: id -> special effect
// function registry (CSEReduceSkillGroupCooltime is the only function registered).
// MS2-UNIT: ?\specialeffectfunctionmanager.cpp
// MS2-RANGE: 0x140827580-0x1408290b0 .text$mn
// MS2-PIN: ??_GCSEReduceSkillGroupCooltime@@UEAAPEAXI@Z 0x140827fe0
// MS2-PIN: ??_GCSpecialEffectFunction@@UEAAPEAXI@Z 0x140828020
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\specialeffectfunctionmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "specialeffectfunctionmanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

float FUN_140718480(const CStringW& strValue);     // packetlogger.cpp

// @0x140827580
bool CSpecialEffectFunction::vfunc_1(CSpecialEffectCtx*)
{
    return true;
}
MS2_REPLACE_METHOD(0x140827580, CSpecialEffectFunction, vfunc_1, 13, 0xC078F4D1);

// @0x1408275a0
bool CSEReduceSkillGroupCooltime::vfunc_1(CSpecialEffectCtx* pCtx)
{
    CSEReduceSkillGroupCooltimeCtx* pReduce = dynamic_cast<CSEReduceSkillGroupCooltimeCtx*>(pCtx);
    if (pReduce == 0)
        return false;
    int nGroupId = 0;
    nGroupId = pReduce->GetInt(L"groupID", &nGroupId);
    if (pReduce->m_nGroupId != nGroupId)
        return false;
    float fRate = 0;
    fRate = pReduce->GetFloat(L"reduceRate", &fRate);
    pReduce->m_fReduceRate = pReduce->m_fReduceRate + fRate;
    return true;
}

// @0x140827800
CSpecialEffectFunctionManager::CSpecialEffectFunctionManager() : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
    Register(4, FunctionPtr(new CSEReduceSkillGroupCooltime()));
}

// @0x140827910
CSpecialEffectFunctionManager::~CSpecialEffectFunctionManager()
{
    m_map.RemoveAll();
}

// @0x140827970
bool CSpecialEffectFunctionManager::Execute(CSpecialEffectCtx* pCtx)
{
    if (pCtx == 0)
        return false;
    FunctionPtr pFunction(0);
    if (!m_map.Lookup(pCtx->m_nKind, pFunction))
        return false;
    return pFunction->vfunc_1(pCtx);
}
MS2_REPLACE_METHOD(0x140827970, CSpecialEffectFunctionManager, Execute, 167, 0x59DCB6FE);

// @0x1408276a0
float CXmlData::FUN_1408276a0(const CStringW& strName, float* pfDefault)
{
    CStringW strValue;
    if (!reinterpret_cast<Unk_SEAttrMap*>(m_unknown18)->FUN_1403ef5f0(strName, strValue))
        return *pfDefault;
    return FUN_140718480(strValue);
}
