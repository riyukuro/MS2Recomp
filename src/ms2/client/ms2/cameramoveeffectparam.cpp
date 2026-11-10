// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\cameramoveeffectparam.cpp
// MS2-RANGE: 0x140afe800-0x140afef30 .text$mn
// MS2-PIN: ??0?$Unk_Bitset@$02@@QEAA@XZ 0x140afed60
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
#include "ms2/client/ms2/camera.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/commonfiles/tinyxml.h"  // C3: was a local member view
// C3: m_update is bitset.h's Unk_Bitset<3> (Set 0x140314670)
//
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};

// Game TinyXML element: FirstChildElement.
// C3 #12: was a local TiXml view




// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp).
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, const char*, efd::Point3&);   // C3: was FUN_140874670 (0x140874670, xmlattr's Point3 reader)

// Game clock (commonfiles singleton 0x14086d260): current time in seconds.

// Camera manager (singleton 0x1409478c0): camera-path playback.

// @0x140afe800
CCameraMoveEffectParam::CCameraMoveEffectParam()
    : CEffectParam(0x11), m_strFilePath(""), m_kTranslate(0.0f, 0.0f, 0.0f), m_kRotation(0.0f, 0.0f, 0.0f),
      m_bAttachToNode(true), m_bApplyNodeTransform(false), m_strParentNode("")
{
}

// @0x140afe8f0
void CCameraMoveEffectParam::vfunc_1(TiXmlElement* pNode)
{
    CEffectParam::vfunc_1(pNode);
    XmlGetAttr((class TiXmlElement*)(pNode), "filePath", m_strFilePath);
    bool bUpdateTranslate = false;
    bool bUpdateRotation = false;
    TiXmlElement* pTransform = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("transform"));
    if (pTransform)
    {
        XmlGetAttr((class TiXmlElement*)(pTransform), "translate", reinterpret_cast<efd::Point3&>(m_kTranslate));
        XmlGetAttr((class TiXmlElement*)(pTransform), "rotation", reinterpret_cast<efd::Point3&>(m_kRotation));
    }
    TiXmlElement* pAttach = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("attachInfo"));
    if (pAttach)
    {
        const char* pszAttach = ((class TiXmlElement*)(class TiXmlElement*)(pAttach))->Attribute("attachToNode");
        if (pszAttach)
        {
            m_bAttachToNode = _stricmp(pszAttach, "true") == 0;
            if (m_bAttachToNode)
            {
                bUpdateTranslate = true;
                bUpdateRotation = true;
            }
        }
        XmlGetAttr((class TiXmlElement*)(pAttach), "applyNodeTransform", m_bApplyNodeTransform);
        XmlGetAttr((class TiXmlElement*)(pAttach), "parentNode", m_strParentNode);
    }
    TiXmlElement* pUpdate = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("update"));
    if (pUpdate)
    {
        XmlGetAttr((class TiXmlElement*)(pUpdate), "translate", bUpdateTranslate);
        XmlGetAttr((class TiXmlElement*)(pUpdate), "rotation", bUpdateRotation);
    }
    if (bUpdateTranslate)
        m_update.Set(0, true);
    if (bUpdateRotation)
        m_update.Set(1, true);
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
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() && pMove->m_strFilePath.GetLength() > 0)
    {
        TSingleton<CameraMgr>::GetInstance()->FUN_140af0e40(pMove);
        m_fDuration = 0.0f;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140afec50, CCameraMoveEffect, vfunc_3, 137, 0xF230EF3A);

// @0x140afece0
bool CCameraMoveEffect::vfunc_9()
{
    double dNow = TSingleton<CMainSystem>::GetInstance()->GetGameTime();
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

