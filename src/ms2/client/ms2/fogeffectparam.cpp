// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\fogeffectparam.cpp
// MS2-RANGE: 0x1412208a0-0x141221290 .text$mn
// MS2-PIN: ??1CFogEffectParam@@UEAA@XZ 0x1412211b0
// MS2-PIN: ??_GCFogEffect@@UEAAPEAXI@Z 0x1412211d0
// MS2-PIN: ??_GCFogEffectParam@@UEAAPEAXI@Z 0x141221230
// MS2-PIN: ?GetRTTI@CFogEffect@@UEBAPEBVNiRTTI@@XZ 0x141221280
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\fogeffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "fogeffectparam.h"
#include <atlcoll.h>
#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/applyeffect.h"
#include "ms2/placeholder/cgameoption.h"
class TiXmlElement;
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view




class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};

// D3DCOLOR_XRGB (d3d9types.h), spelled out: the game does not include d3d9 here.
#define MS2_D3DCOLOR_XRGB(r, g, b) \
    ((unsigned int)((((0xff) & 0xff) << 24) | (((r) & 0xff) << 16) | (((g) & 0xff) << 8) | ((b) & 0xff)))

// Game TinyXML element: FirstChildElement.
// C3 #12: was a local TiXml view




// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp) and string helpers (commonfiles).
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
CString FUN_140188f50(const char* psz, int n);                                          // null-safe CString
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);   // split to uints
bool FUN_14028d470(float a, float b);                                                   // nearly equal

// Game clock (commonfiles singleton 0x14086d260): current time in seconds.

// Scene fog state (?\applyeffect.cpp manager, singleton 0x1409a8b00).
class ApplyEffect;

// Renderer wrapper (singleton 0x1409a8b10) -> back buffer (0x1409a8ac0) -> flag passed to the fog setter.
struct Unk_GraphicState;
bool FUN_14125e020(const Unk_GraphicState* p);                 // the fog flag (gameoptionstruct)
class Unk_AeGameOption { public: class Unk_AeGraphicOption* FUN_1409a8ac0(); };   // C3: unit-local view (def in applyeffect)

// @0x1412208a0
CFogEffectParam::CFogEffectParam()
    : CEffectParam(10), m_dwColor(0), m_fNear(100.0f), m_fFar(10000.0f)
{
}

// @0x141220910
void CFogEffectParam::vfunc_1(TiXmlElement* pNode)
{
    CEffectParam::vfunc_1(pNode);
    TiXmlElement* pFog = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("fog"));
    if (pFog)
    {
        ATL::CAtlArray<unsigned int> arrColor;
        CString strColor = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pFog))->Attribute("color"), 0);
        XmlSplit(strColor, arrColor, ",");
        m_dwColor = arrColor.GetCount() < 3 ? 0xffffffff
                                             : MS2_D3DCOLOR_XRGB(arrColor[0], arrColor[1], arrColor[2]);
        XmlGetAttr((class TiXmlElement*)(pFog), "near", m_fNear);
        XmlGetAttr((class TiXmlElement*)(pFog), "far", m_fFar);
    }
}
MS2_REPLACE_METHOD(0x141220910, CFogEffectParam, vfunc_1, 383, 0xBA161230);

// @0x141220aa0
// Not hooked: constructs CFogEffect with this unit's (DLL) constructor/vftable.
CEffectPtr CFogEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CFogEffect;
}

// @0x141220b40
CFogEffect::CFogEffect()
    : m_fNear(100.0f), m_fFar(10000.0f), m_dwColor(0)
{
}

// @0x141220bb0
CFogEffect::~CFogEffect()
{
}

// @0x141220be0
CFogEffect* CFogEffect::FUN_141220be0(void* pUnused, const CFogEffectParam* pParam)
{
    if (pParam)
    {
        CFogEffect* pEffect = new (efd::MemHint(efd::MemHint::NONE)) CFogEffect;
        TSingleton<ApplyEffect>::GetInstance()->GetFog(&pEffect->m_fNearFrom, &pEffect->m_fFarFrom, &pEffect->m_dwColorFrom);
        pEffect->m_dStartTime = TSingleton<CMainSystem>::GetInstance()->FUN_141473280() + pParam->m_fStartDelay;
        pEffect->m_fDuration = pParam->m_fDuration;
        pEffect->m_b2c = pParam->m_b30;
        pEffect->m_fNear = pParam->m_fNear;
        pEffect->m_fFar = pParam->m_fFar;
        pEffect->m_dwColor = pParam->m_dwColor;
        if (FUN_14028d470(pParam->m_fStartDelay, 0.0f))
            pEffect->vfunc_4();
        return pEffect;
    }
    return NULL;
}

// @0x141220d90
bool CFogEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CFogEffectParam* pFog = static_cast<const CFogEffectParam*>(pParam);
    TSingleton<ApplyEffect>::GetInstance()->GetFog(&m_fNearFrom, &m_fFarFrom, &m_dwColorFrom);
    m_fNear = pFog->m_fNear;
    m_fFar = pFog->m_fFar;
    m_dwColor = pFog->m_dwColor;
    if (FUN_14028d470(pFog->m_fStartDelay, 0.0f))
        vfunc_4();
    return true;
}
MS2_REPLACE_METHOD(0x141220d90, CFogEffect, vfunc_3, 246, 0xD585E041);

// @0x141220e90
bool CFogEffect::vfunc_9()
{
    if (CEffect::vfunc_9())
    {
        FUN_141220f50();
        FUN_141220f60(TSingleton<CMainSystem>::GetInstance()->FUN_141473280());
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x141220e90, CFogEffect, vfunc_9, 73, 0xDF8F6F44);

// @0x141220ee0
void CFogEffect::vfunc_7()
{
    TSingleton<ApplyEffect>::GetInstance()->SetFogRange(FUN_14125e020((const Unk_GraphicState*)((class Unk_AeGameOption*)(TSingleton<CGameOption>::GetInstance()))->FUN_1409a8ac0()), m_fNear, m_fFar, m_dwColor);
}
MS2_REPLACE_METHOD(0x141220ee0, CFogEffect, vfunc_7, 92, 0x1780D1FA);

// @0x141220f50
void CFogEffect::FUN_141220f50()
{
}

// @0x141220f60
void CFogEffect::FUN_141220f60(double dNow)
{
    double dElapsed = dNow - m_dStartTime;
    double t = dElapsed / m_fDuration;
    float fNear = (float)((1.0 - t) * m_fNearFrom + t * m_fNear);
    float fFar = (float)((1.0 - t) * m_fFarFrom + t * m_fFar);
    unsigned char r = (unsigned char)((1.0 - t) * ((m_dwColorFrom >> 16) & 0xff) + t * ((m_dwColor >> 16) & 0xff));
    unsigned char g = (unsigned char)((1.0 - t) * ((m_dwColorFrom >> 8) & 0xff) + t * ((m_dwColor >> 8) & 0xff));
    unsigned char b = (unsigned char)((1.0 - t) * (m_dwColorFrom & 0xff) + t * (m_dwColor & 0xff));
    unsigned int dwColor = MS2_D3DCOLOR_XRGB(r, g, b);
    TSingleton<ApplyEffect>::GetInstance()->SetFogRange(FUN_14125e020((const Unk_GraphicState*)((class Unk_AeGameOption*)(TSingleton<CGameOption>::GetInstance()))->FUN_1409a8ac0()), fNear, fFar, dwColor);
}
MS2_REPLACE_METHOD(0x141220f60, CFogEffect, FUN_141220f60, 579, 0xAA2C7DF0);

// @0x141221270
int CFogEffect::vfunc_12()
{
    return 10;
}
