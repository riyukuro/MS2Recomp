// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\beameffectparam.cpp
// MS2-RANGE: 0x140a0c300-0x140a0cd30 .text$mn
// MS2-PIN: ??1BeamDirectionCurveInfo@@UEAA@XZ 0x140a0caf0
// MS2-PIN: ??1BeamInfo@@UEAA@XZ 0x140a0cb10
// MS2-PIN: ??1BeamPointCurveInfo@@UEAA@XZ 0x140a0cb30
// MS2-PIN: ??_GBeamDirectionCurveInfo@@UEAAPEAXI@Z 0x140a0cc30
// MS2-PIN: ??_GBeamInfo@@UEAAPEAXI@Z 0x140a0cc70
// MS2-PIN: ??_GBeamPointCurveInfo@@UEAAPEAXI@Z 0x140a0ccb0
// MS2-PIN: ??_GCBeamEffectParam@@UEAAPEAXI@Z 0x140a0ccf0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\beameffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "beameffectparam.h"
#include "beameffect.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Game TinyXML element: FirstChildElement.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);
};

// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp) and string helpers.
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nOut);
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
int FUN_140874670(Unk_140165cf0* pNode, const char* pszName, Vector3& kOut);
float FUN_1401973d0(Unk_140165cf0* pNode, const char* pszName, float fDefault);
CString FUN_140188f50(const char* psz, int n);                                          // null-safe CString
int FUN_1401788f0(Unk_140165cf0* pNode, const char* pszName, ATL::CAtlArray<CString>& arr);   // split to list

// @0x140a0c300
CBeamEffectParam::CBeamEffectParam()
    : CEffectParam(0x15), m_fWidth(10.0f), m_nQuality(4), m_nAlphaMode(0), m_pBeamInfo(0)
{
}

// @0x140a0c890
static int FUN_140a0c890(const CString& str)
{
    if (str.IsEmpty())
        return 0;
    if (str.CompareNoCase("pointCurve") == 0)
    {
        return 1;
    }
    else
    {
        if (str.CompareNoCase("directionCurve") == 0)
        {
            return 2;
        }
    }
    return 0;
}

// @0x140a0c900
// The exe copy is a commonfiles	inyxmlhelper.h template instance (line 250: assert(FALSE) for an unsupported type
// stays behind as a dead branch).
static int FUN_140a0c900(Unk_140165cf0* pNode, const char* pszName, int& nOut)
{
    if (0)
    {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CString str;
    int r = FUN_1408733e0(pNode, pszName, str);
    if (r != 0)
        return r;
    nOut = FUN_140a0c890(str);
    return r;
}

// @0x140a0c3a0
// Not hooked: constructs BeamPointCurveInfo / BeamDirectionCurveInfo with this unit's (DLL) constructors and vftables.
void CBeamEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1401788f0(pNode, "texturePath", m_arrTexturePath);
    if (m_arrTexturePath.IsEmpty())
        return;
    FUN_140873360(pNode, "width", m_fWidth);
    FUN_1408731e0(pNode, "quality", m_nQuality);
    CString strAlpha = FUN_140188f50(FUN_14086f4b0(pNode, "alphaMode"), 0);
    if (strAlpha.GetLength() > 0)
    {
        if (strAlpha.CompareNoCase("SWOOSH") == 0)
            m_nAlphaMode = 0;
        if (strAlpha.CompareNoCase("STANDARD") == 0)
            m_nAlphaMode = 1;
        if (strAlpha.CompareNoCase("ADD") == 0)
            m_nAlphaMode = 2;
    }
    Unk_140165cf0* pBeam = pNode->FUN_140165cf0("beamInfo");
    if (pBeam == 0)
        return;
    int nType = 0;
    FUN_140a0c900(pBeam, "type", nType);
    switch (nType)
    {
    case 1:
        m_pBeamInfo.AssignRaw(new BeamPointCurveInfo);
        break;
    case 2:
        m_pBeamInfo.AssignRaw(new BeamDirectionCurveInfo);
        break;
    default:
        m_pBeamInfo = 0;
        (void)((!!(0)) || (_wassert(L"0", _CRT_WIDE(MS2_THIS_FILE), 0x49), 0));
        break;
    }
    if (!m_pBeamInfo)
        return;
    if (!m_pBeamInfo->vfunc_1(pBeam))
        return;
}

// @0x140a0c6d0
// Not hooked: constructs CBeamEffect with its (exe) constructor.
CEffectPtr CBeamEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CBeamEffect;
}

// @0x140a0c770
bool BeamInfo::vfunc_1(Unk_140165cf0* pNode)
{
    if (pNode == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140A0C770, BeamInfo, vfunc_1, 25, 0x4C645368);

// @0x140a0c790
bool BeamPointCurveInfo::vfunc_1(Unk_140165cf0* pNode)
{
    if (pNode == 0)
        return false;
    if (!BeamInfo::vfunc_1(pNode))
        return false;
    if (FUN_140874670(pNode, "passThroughPoint", m_kPassThroughPoint) != 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140A0C790, BeamPointCurveInfo, vfunc_1, 96, 0xE8CF1295);

// @0x140a0c800
bool BeamDirectionCurveInfo::vfunc_1(Unk_140165cf0* pNode)
{
    if (pNode == 0)
        return false;
    if (!BeamInfo::vfunc_1(pNode))
        return false;
    m_fDirectionRate = FUN_1401973d0(pNode, "directionRate", 0.5f);
    m_fLengthRate = FUN_1401973d0(pNode, "lengthRate", 0.5f);
    return true;
}
MS2_REPLACE_METHOD(0x140A0C800, BeamDirectionCurveInfo, vfunc_1, 129, 0x7B02794D);

// @0x140a0ca10
BeamDirectionCurveInfo::BeamDirectionCurveInfo()
    : BeamInfo(2), m_fDirectionRate(0.0f), m_fLengthRate(0.0f)
{
}

// @0x140a0ca60
BeamInfo::BeamInfo(long nType)
    : m_nType(nType)
{
}

// @0x140a0caa0
BeamPointCurveInfo::BeamPointCurveInfo()
    : BeamInfo(1)
{
}
