// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_140987430
// MS2-RANGE: 0x140987430-0x140987b20 .text$mn
// MS2-PIN: ??0?$SmartPointer@VCEffect@@@efd@@QEAA@PEAVCEffect@@@Z 0x1409878c0
// MS2-PIN: ??1CEffectParam@@UEAA@XZ 0x140987960
// MS2-PIN: ??_GCAfterImageEffectParam@@UEAAPEAXI@Z 0x140987990
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\effectservice.cpp"
#include <vcruntime_string.h>
#include <afx.h>
#include <afxwin.h>
#include "afterimageeffectparam.h"
#include "afterimageitem.h"
#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class Unk_140165cf0;

// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp); they return 0 on success.
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nOut);
int FUN_1408730a0(Unk_140165cf0* pNode, const char* pszName, bool& bOut);
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);

// "#RRGGBB"-style string to colour.
Unk_AfterImageColor FUN_140db93e0(const CString& str);
extern efd::ColorA DAT_143a09670;                               // default colour

// @0x140987430
CAfterImageEffectParam::CAfterImageEffectParam()
    : CEffectParam(0x16), m_nImageSize(0x100), m_bLightenMode(true), m_kColor(1.0f, 1.0f, 1.0f, 1.0f), m_nTimeInterval(250), m_fMoveInterval(100.0f), m_nTimeLife(1000)
{
}

// @0x1409874f0
CAfterImageEffectParam::~CAfterImageEffectParam()
{
}

// @0x140987520
void CAfterImageEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    if (FUN_1408731e0(pNode, "imageSize", m_nImageSize))
        m_nImageSize = 0x100;
    if (FUN_1408730a0(pNode, "lightenMode", m_bLightenMode))
        m_bLightenMode = true;
    CString strColor;
    if (!FUN_1408733e0(pNode, "color", strColor))
    {
        m_kColor = FUN_140db93e0(strColor);
    }
    else
    {
        Unk_AfterImageColor kDefault(DAT_143a09670);
        m_kColor = kDefault;
    }
    float fTimeLife = 1.0f;
    if (FUN_140873360(pNode, "timeLife", fTimeLife))
        fTimeLife = 1.0f;
    m_nTimeLife = (unsigned)(fTimeLife * 1000.0f);
    float fTimeInterval = 0.2f;
    if (FUN_140873360(pNode, "timeInterval", fTimeInterval))
        fTimeInterval = 0.2f;
    m_nTimeInterval = (unsigned)(fTimeInterval * 1000.0f);
    if (FUN_140873360(pNode, "moveInterval", m_fMoveInterval))
        m_fMoveInterval = 100.0f;
}
MS2_REPLACE_METHOD(0x140987520, CAfterImageEffectParam, vfunc_1, 527, 0x29700881);

// @0x140987740
// Not hooked: constructs CAfterImageEffect (exe ctor) through this unit's vftable-less call.
// MS2-FUNCTIONAL: the exe keeps the Ref ctor result in an extra stack slot before passing it (frame 0x88 vs 0x78).
CEffectPtr CAfterImageEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CAfterImageEffect(Unk_AfterImageRef(this));
}

// @0x140987900
Unk_AfterImageRef::Unk_AfterImageRef(CAfterImageEffectParam* pParam)
{
    m_pParam = pParam;
    FUN_140981190();
}

// 0x140987930 is NiColorA(const efd::ColorA&) (Gamebryo inline, emitted by
// `Unk_AfterImageColor kDefault(DAT_143a09670)` above)
//
//
//

// @0x140987810
const Unk_AfterImageColor* CAfterImageEffectParam::GetColor() const
{
    return &m_kColor;
}

// @0x140987830
int CAfterImageEffectParam::GetImageSize() const
{
    return m_nImageSize;
}

// @0x140987850
unsigned CAfterImageEffectParam::GetTimeInterval() const
{
    return m_nTimeInterval;
}

// @0x140987870
unsigned CAfterImageEffectParam::GetTimeLife() const
{
    return m_nTimeLife;
}

// @0x140987890
float CAfterImageEffectParam::GetMoveInterval() const
{
    return m_fMoveInterval;
}

// @0x1409878b0
bool CAfterImageEffectParam::GetLightenMode() const
{
    return m_bLightenMode;
}

// @0x1409879d0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// @0x140987af0
CRuntimeClass* FUN_140987af0()
{
    return CDialog::GetThisClass();
}
