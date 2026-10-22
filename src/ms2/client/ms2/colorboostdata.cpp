// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See colorboostdata.h.
// MS2-UNIT: ?\colorboostdata.cpp
// MS2-RANGE: 0x14109b6b0-0x14109c630 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\colorboostdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "colorboostdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include <NiAVObject.h>

// ---- out-of-unit callees and the slider values (statics defined elsewhere) ----
class Unk_CbApp { public: double FUN_141473280(); };                // the application time
Unk_CbApp* FUN_14086d260();
float FUN_140a0fde0(float a, float b);                              // min
NiAVObject* FUN_141b6ef70(egf::EntityID id);                        // the actor's scene graph
void FUN_141b6fae0(NiAVObject* pRoot, float fValue);                // set the colour scale of a scene graph
extern float g_1439f7024, g_1439f7028, g_1439f702c, g_1439f7030, g_1439f7034;

// @0x14109b6b0
CColorBoostData::CColorBoostData(float fColorScale, float fDuration, float fAccumRatio)
{
    m_b08 = false;
    m_f10 = fColorScale;
    m_f14 = fDuration;
    m_f18 = fAccumRatio;
    m_f1c = 0.0f;
    m_f0c = (float)FUN_14086d260()->FUN_141473280();
}

// @0x14109bfa0
CColorBoostData::CColorBoostData(const CColorBoostData& kOther)
{
    m_b08 = kOther.m_b08;
    m_f0c = kOther.m_f0c;
    m_f10 = kOther.m_f10;
    m_f14 = kOther.m_f14;
    m_f18 = kOther.m_f18;
    m_f1c = kOther.m_f1c;
}

// @0x14109b750
CColorBoostData::~CColorBoostData()
{
}

// MS2-FUNCTIONAL: the exe keeps an extra local for the duration and a single-exit return flag
// @0x14109b770
bool CColorBoostData::FUN_14109b770(float* pfScale, int nIndex)
{
    float fElapsed = (float)FUN_14086d260()->FUN_141473280() - m_f0c;
    if (fElapsed > m_f14)
        return false;
    float fRemain = 1.0f - fElapsed / m_f14;
    if (!m_b08)
    {
        float fTarget = FUN_140a0fde0(*pfScale + m_f10, ((float)nIndex * m_f18 + 1.0f) * m_f10 + 1.0f);
        m_f1c = fTarget - *pfScale;
        m_b08 = true;
    }
    *pfScale = *pfScale + m_f1c * fRemain;
    return true;
}
MS2_REPLACE_METHOD(0x14109b770, CColorBoostData, FUN_14109b770, 325, 0xFE3D2DE6);

// @0x14109bd60
CColorBoostManager::CColorBoostManager()
    : m_boosts(10)
{
    m_fScale = 1.0f;
}

// @0x14109bdc0
CColorBoostManager::~CColorBoostManager()
{
}

// @0x14109be00
void CColorBoostManager::FUN_14109be00(const CColorBoostData& kData)
{
    m_boosts.AddTail(kData);
}
MS2_REPLACE_METHOD(0x14109be00, CColorBoostManager, FUN_14109be00, 41, 0x46E65FB3);

// @0x14109be30
void CColorBoostManager::FUN_14109be30(const egf::EntityID& kId)
{
    float fScale = 1.0f;
    POSITION pos = m_boosts.GetHeadPosition();
    int nIndex = 0;
    while (pos != NULL)
    {
        POSITION posCur = pos;
        CColorBoostData& kBoost = m_boosts.GetNext(pos);
        int nCur = nIndex;
        unsigned int bAlive = kBoost.FUN_14109b770(&fScale, nCur);
        nIndex++;
        if (bAlive == 0)
            m_boosts.RemoveAt(posCur);
    }
    if (fScale != m_fScale)
    {
        FUN_141b6fae0(FUN_141b6ef70(kId), fScale);
        m_fScale = fScale;
    }
}
MS2_REPLACE_METHOD(0x14109be30, CColorBoostManager, FUN_14109be30, 264, 0x52222E06);

// @0x14109b900
UIColorBoostDialog::UIColorBoostDialog()
{
    m_40 = 1;
}

// @0x14109b950
UIColorBoostDialog::~UIColorBoostDialog()
{
}

// @0x14109b990
CString UIColorBoostDialog::GetTypeName()
{
    return "ColorBoostDialog";
}
MS2_REPLACE_METHOD(0x14109b990, UIColorBoostDialog, GetTypeName, 61, 0x7A8C8FC9);

// @0x14109b9e0
void UIColorBoostDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASObj obj(2);
    obj.FUN_1409c4a30("npcColorScale", g_1439f7024);
    obj.FUN_1409c4a30("npcDuration", g_1439f7028);
    obj.FUN_1409c4a30("pcColorScale", g_1439f702c);
    obj.FUN_1409c4a30("pcDuration", g_1439f7030);
    obj.FUN_1409c4a30("accumRatio", g_1439f7034);
    m_30->Invoke("initData", obj.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x14109b9e0, UIColorBoostDialog, OnLoadComplete, 307, 0x638D874A);

// @0x14109bb20
int UIColorBoostDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onChangeSliderNPC", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            g_1439f7024 = data.FUN_1422b8c10();
            g_1439f7028 = data.FUN_1422b8c10();
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderPC", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            g_1439f702c = data.FUN_1422b8c10();
            g_1439f7030 = data.FUN_1422b8c10();
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderAccumRatio", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            g_1439f7034 = data.FUN_1422b8c10();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14109bb20, UIColorBoostDialog, vfunc_28, 484, 0x591C44DC);
