// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\cameramoveeffectparam.cpp
// MS2-RANGE: 0x140afe800-0x140afef30 .text$mn
// MS2-PIN: ??0Unk_CamMoveBits@@QEAA@XZ 0x140afed60
// MS2-PIN: ??1CCameraMoveEffectParam@@UEAA@XZ 0x140afed80
// MS2-PIN: ??_GCCameraMoveEffect@@UEAAPEAXI@Z 0x140afedd0
// MS2-PIN: ??_GCCameraMoveEffectParam@@UEAAPEAXI@Z 0x140afee30
// MS2-PIN: ?GetRTTI@CCameraMoveEffect@@UEBAPEBVNiRTTI@@XZ 0x140afee80
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cameramoveeffectparam.cpp"
// No ms2stdafx.h: this unit calls _stricmp through the IAT (call [__imp__stricmp]).
#include <afx.h>
#include <afxwin.h>
#include "cameramoveeffectparam.h"
#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Game TinyXML element: FirstChildElement.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);
};

// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp).
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);
int FUN_1408730a0(Unk_140165cf0* pNode, const char* pszName, bool& bOut);
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
int FUN_140874670(Unk_140165cf0* pNode, const char* pszName, Unk_StreamPoint& kOut);

// Game clock (commonfiles singleton 0x14086d260): current time in seconds.
class Unk_GameClock
{
public:
    double FUN_141473280();
};
Unk_GameClock* FUN_14086d260();

// Camera manager (singleton 0x1409478c0): camera-path playback.
class Unk_CameraManager
{
public:
    int FUN_140a18070();                                        // camera ready
    void FUN_140af0e40(const CCameraMoveEffectParam* pParam);   // play the param's camera path
};
Unk_CameraManager* FUN_1409478c0();

// @0x140afe800
CCameraMoveEffectParam::CCameraMoveEffectParam()
    : CEffectParam(0x11), m_strFilePath(""), m_kTranslate(0.0f, 0.0f, 0.0f), m_kRotation(0.0f, 0.0f, 0.0f),
      m_bAttachToNode(true), m_bApplyNodeTransform(false), m_strParentNode("")
{
}

// @0x140afe8f0
void CCameraMoveEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1408733e0(pNode, "filePath", m_strFilePath);
    bool bUpdateTranslate = false;
    bool bUpdateRotation = false;
    Unk_140165cf0* pTransform = pNode->FUN_140165cf0("transform");
    if (pTransform)
    {
        FUN_140874670(pTransform, "translate", m_kTranslate);
        FUN_140874670(pTransform, "rotation", m_kRotation);
    }
    Unk_140165cf0* pAttach = pNode->FUN_140165cf0("attachInfo");
    if (pAttach)
    {
        const char* pszAttach = FUN_14086f4b0(pAttach, "attachToNode");
        if (pszAttach)
        {
            m_bAttachToNode = _stricmp(pszAttach, "true") == 0;
            if (m_bAttachToNode)
            {
                bUpdateTranslate = true;
                bUpdateRotation = true;
            }
        }
        FUN_1408730a0(pAttach, "applyNodeTransform", m_bApplyNodeTransform);
        FUN_1408733e0(pAttach, "parentNode", m_strParentNode);
    }
    Unk_140165cf0* pUpdate = pNode->FUN_140165cf0("update");
    if (pUpdate)
    {
        FUN_1408730a0(pUpdate, "translate", bUpdateTranslate);
        FUN_1408730a0(pUpdate, "rotation", bUpdateRotation);
    }
    if (bUpdateTranslate)
        m_update.FUN_140314670(0, true);
    if (bUpdateRotation)
        m_update.FUN_140314670(1, true);
}
MS2_REPLACE_METHOD(0x140afe8f0, CCameraMoveEffectParam, vfunc_1, 502, 0xF46663CF);

// @0x140afeaf0
// Not hooked: constructs CCameraMoveEffect with this unit's (DLL) constructor/vftable.
CEffectPtr CCameraMoveEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CCameraMoveEffect;
}

// @0x140afeb90
bool CCameraMoveEffectParam::vfunc_7(Unk_EffectTarget* p)
{
    if (CEffectParam::vfunc_7(p))
        return true;
    if (p->m_nKind == 3)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140afeb90, CCameraMoveEffectParam, vfunc_7, 62, 0x7156C6B8);

// @0x140afebe0
CCameraMoveEffect::CCameraMoveEffect()
{
}

// @0x140afec20
CCameraMoveEffect::~CCameraMoveEffect()
{
}

// @0x140afec50
bool CCameraMoveEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CCameraMoveEffectParam* pMove = static_cast<const CCameraMoveEffectParam*>(pParam);
    if (FUN_1409478c0()->FUN_140a18070() && pMove->m_strFilePath.GetLength() > 0)
    {
        FUN_1409478c0()->FUN_140af0e40(pMove);
        m_fDuration = 0.0f;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140afec50, CCameraMoveEffect, vfunc_3, 137, 0xF230EF3A);

// @0x140afece0
bool CCameraMoveEffect::vfunc_9()
{
    double dNow = FUN_14086d260()->FUN_141473280();
    return dNow < m_dStartTime + m_fDuration;
}
MS2_REPLACE_METHOD(0x140afece0, CCameraMoveEffect, vfunc_9, 95, 0x14569701);

// @0x140afed50
void CCameraMoveEffect::vfunc_7()
{
}

// @0x140afee70
int CCameraMoveEffect::vfunc_12()
{
    return 0x11;
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x140afed50, CCameraMoveEffect, vfunc_7, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x140afee70, CCameraMoveEffect, vfunc_12, 11, 0x1A761180);

