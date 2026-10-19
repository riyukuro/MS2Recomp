// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemExtraData and its decal / hair / cap subclasses: the
// per-item colouring state (EquipColorInfo slots, the cycling of multi-colour items, the random decal / hair / cap
// customisations picked from the item model), plus the std::vector<Unk_SocketPtr<EquipColorInfo>> glue.
// MS2-UNIT: ?\itemextradata.cpp
// MS2-RANGE: 0x140598b80-0x14059dcd0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemextradata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/citemextradata.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/characterdecaldata.h"
#include "ms2/placeholder/itemcustom.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "itemdata.h"
#include "itemdatatable.h"
#include "ms2/ms2recover.h"
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----
unsigned FUN_140869420();                                       // the tick count
bool FUN_14059d150(float* p);
CItemDataTable* FUN_140281980();                                // the item table singleton
void FUN_140159b70(long hr);                                    // ATL throw
float FUN_14029dd40(float f);                                   // fabs

static bool FUN_14059d190(Unk_StreamPoint* p);
static inline const Unk_StreamPoint& AsPt(const efd::Point3& p) { return *(const Unk_StreamPoint*)&p; }

// ---- the float helpers of the unit ----

// @0x14059d930
static float FUN_14059d930(float f) { return FUN_14029dd40(f); }

// @0x14059bfe0
static bool FUN_14059bfe0(float a, float b)
{
    return FUN_14059d930(a - b) > 0.0001f;
}

// @0x14059c020
static bool FUN_14059c020(const Unk_StreamPoint& a, const Unk_StreamPoint& b)
{
    return FUN_14059d930(a.x - b.x) > 0.0001f || FUN_14059d930(a.y - b.y) > 0.0001f || FUN_14059d930(a.z - b.z) > 0.0001f;
}

// ---- EquipColorInfo ----

// @0x140598b80
EquipColorInfo::EquipColorInfo()
{
    m_n24 = -1;
    m_n28 = 0;
    m_n2c = 0;
    memset(m_aRgb, 0, sizeof(m_aRgb));
}

// @0x140598bf0
void EquipColorInfo::FUN_140598bf0(COutputStream& os)
{
    for (int i = 0; i < 3; i++)
        os.vfunc_o10_3(m_aRgb[i]);
    os.vfunc_o10_3(m_n24);
    os.vfunc_o10_3(m_n28);
}

// @0x140598c80
void EquipColorInfo::FUN_140598c80(CInputStream& is)
{
    for (int i = 0; i < 3; i++)
        m_aRgb[i] = is.vfunc_o8_3();
    m_n24 = is.vfunc_o8_3();
    m_n28 = is.vfunc_o8_3();
}

// @0x140598d10
void EquipColorInfo::FUN_140598d10(Unk_SocketPtr<EquipColorInfo> spSrc)
{
    if (spSrc == 0)
        return;
    for (int i = 0; i < 3; i++)
        m_aRgb[i] = spSrc->m_aRgb[i];
    m_n24 = spSrc->m_n24;
    m_n28 = spSrc->m_n28;
    m_n2c = spSrc->m_n2c;
}

// @0x140598de0
void EquipColorInfo::FUN_140598de0(const ItemColorEx& kColor, int nDelay)
{
    for (int i = 0; i < 3; i++)
        m_aRgb[i] = kColor.m_aValues[i];
    m_n24 = kColor.m_nColor;
    m_n28 = kColor.m_nId;
    m_n2c = nDelay;
}

// ---- CItemExtraData ----

// @0x140598e60
CItemExtraData::CItemExtraData()
{
    m_nIndex = 0;
    m_nPick = -1;
    m_bMulti = false;
    m_nNextTick = FUN_140869420();
    m_nKind = 0;
    m_spColor = Unk_SocketNew(0);
}

// @0x140598f20
CItemExtraData::~CItemExtraData()
{
}

// @0x140598f70
int CItemExtraData::vfunc_1(const CItemExtraData* pOther)
{
    return FUN_14059d140() == pOther->FUN_14059d140() && FUN_140599830(pOther) && vfunc_2(pOther);
}

// @0x140598ff0
int CItemExtraData::vfunc_2(const CItemExtraData* pOther)
{
    return FUN_14059d140() == pOther->FUN_14059d140() && m_nPick == pOther->m_nPick;
}

// @0x140599050
void CItemExtraData::vfunc_4(void* p)
{
    CItemData* pData = (CItemData*)p;
    if (pData->FUN_14053e370())
    {
        m_bMulti = true;
        FUN_1405993b0(pData->FUN_14053e3c0());
    }
    FUN_140599ab0(pData);
    m_nPick = -1;
}

// @0x1405990c0
void CItemExtraData::vfunc_3(const CItemExtraData* pOther)
{
    if (pOther != 0)
    {
        unsigned nCount = 1;
        if (pOther->m_bMulti)
            nCount = (unsigned)pOther->m_colors.size();
        for (unsigned i = 0; i < nCount; i++)
            FUN_14059a230(i)->FUN_140598d10(pOther->FUN_14059a230(i));
    }
    m_nPick = pOther->m_nPick;
}

// @0x1405991e0
void CItemExtraData::vfunc_5(COutputStream& os)
{
    FUN_14059a230(0)->FUN_140598bf0(os);
}

// @0x140599250
void CItemExtraData::vfunc_6(CInputStream& is)
{
    m_nPick = -1;
    FUN_14059a230(0)->FUN_140598c80(is);
}

// @0x1405992d0
void CItemExtraData::vfunc_7(COutputStream& os)
{
    FUN_14059a230(0)->FUN_140598bf0(os);
}

// @0x140599340
void CItemExtraData::vfunc_8(CInputStream& is)
{
    FUN_14059a230(0)->FUN_140598c80(is);
}

// @0x1405993b0
void CItemExtraData::FUN_1405993b0(unsigned nCount)
{
    m_colors.clear();
    for (unsigned i = 0; i < nCount; i++)
        m_colors.push_back(ColorPtr(new EquipColorInfo));
}

// @0x140599480
bool CItemExtraData::FUN_140599480(const ItemColorEx& kColor, MS2Ptr<CItemData> spData)
{
    return FUN_140599510(kColor, spData) == 1;
}

// @0x140599510
int CItemExtraData::FUN_140599510(const ItemColorEx& kColor, MS2Ptr<CItemData> spData)
{
    int nResult = 1;
    for (unsigned i = 0; i < 3; i++)
    {
        if (FUN_14059a230(0)->m_aRgb[i] != kColor.m_aValues[i])
        {
            nResult = 0;
            break;
        }
    }
    if (nResult != 0 || kColor.m_nId != 100000000)
        return nResult;
    if (!(spData == 0))
    {
        if (spData.get() == 0)
            return nResult;
        if (!spData->FUN_14053d020())
            return nResult;
    }
    bool bSame = FUN_14059a230(0)->m_aRgb[0] == kColor.m_n30 && FUN_14059a230(0)->m_aRgb[1] == kColor.m_aValues[1]
        && FUN_14059a230(0)->m_aRgb[2] == kColor.m_n34;
    if (bSame)
        nResult = 1;
    return nResult;
}

// @0x140599830
int CItemExtraData::FUN_140599830(const CItemExtraData* pOther)
{
    if (FUN_14059d140() != pOther->FUN_14059d140())
        return 0;
    EquipColorInfo* pOtherColor = pOther->FUN_14059a230(0).operator->();
    for (unsigned i = 0; i < 3; i++)
    {
        if (FUN_14059a230(0)->m_aRgb[i] != pOtherColor->m_aRgb[i])
            return 0;
    }
    return 1;
}

// @0x140599970
int CItemExtraData::FUN_140599970(const CItemExtraData* pOther)
{
    if (FUN_14059d130() != pOther->FUN_14059d130())
        return 0;
    EquipColorInfo* pOtherColor = pOther->FUN_14059a230(0).operator->();
    for (unsigned i = 0; i < 3; i++)
    {
        if (FUN_14059a230(0)->m_aRgb[i] != pOtherColor->m_aRgb[i])
            return 0;
    }
    return 1;
}

ItemModelHead* FUN_14053ec70(CItemData* pData);

// @0x140599ab0
void CItemExtraData::FUN_140599ab0(CItemData* pData)
{
    if (pData != 0 && pData->FUN_14053e260() != 0)
    {
        for (unsigned i = 0; i < FUN_14053ec70(pData)->FUN_140547330(); i++)
        {
            int nIndex = pData->FUN_14053e2b0(i);
            int nPalette = pData->FUN_14053e260();
            MS2Ptr<ItemColorEx> spColor = FUN_140281980()->GetPaletteColorOrRandom(nPalette, nIndex);
            if (spColor.get() != 0)
                FUN_140599bc0(spColor.operator->(), 0, pData->FUN_14053e310(i), i);
        }
    }
}

// @0x140599bc0
void CItemExtraData::FUN_140599bc0(const ItemColorEx* pColor, char bExtra, int nDelay, unsigned nSlot)
{
    FUN_14059a230(nSlot)->FUN_140598de0(*pColor, nDelay);
    if (bExtra != 0)
    {
        FUN_14059a230(nSlot)->m_aRgb[0] = pColor->m_n30;
        FUN_14059a230(nSlot)->m_aRgb[2] = pColor->m_n34;
    }
}

// @0x140599d10
void CItemExtraData::FUN_140599d10(ATL::CAtlArray<int>& aValues, unsigned nSlot)
{
    size_t nCount = aValues.GetCount() < 3 ? aValues.GetCount() : 3;
    for (size_t i = 0; i < nCount; i++)
        FUN_14059a230(nSlot)->m_aRgb[i] = aValues[i];
    FUN_14059a230(nSlot)->m_n24 = -1;
    FUN_14059a230(nSlot)->m_n28 = 0;
}

// @0x140599ea0
void CItemExtraData::FUN_140599ea0(int nIndex, const int& nValue, unsigned nSlot)
{
    if (nIndex > -1 && nIndex < 3)
    {
        FUN_14059a230(nSlot)->m_aRgb[nIndex] = nValue;
        FUN_14059a230(nSlot)->m_n24 = -1;
        FUN_14059a230(nSlot)->m_n28 = 0;
    }
}

// @0x140599fd0
int CItemExtraData::FUN_140599fd0(unsigned nIndex)
{
    if (nIndex < 3)
        return FUN_14059a2c0()->m_aRgb[nIndex];
    return 0;
}

// @0x14059a040
int CItemExtraData::FUN_14059a040(unsigned nSlot)
{
    return FUN_14059a230(nSlot)->m_n24;
}

// @0x14059a0b0
int CItemExtraData::FUN_14059a0b0(unsigned nSlot)
{
    return FUN_14059a230(nSlot)->m_n28;
}

// @0x14059a120
int CItemExtraData::FUN_14059a120()
{
    return FUN_14059a2c0()->m_n2c;
}

// @0x14059a180
int* CItemExtraData::FUN_14059a180(unsigned nSlot)
{
    return FUN_14059a230(nSlot)->m_aRgb;
}

// @0x14059a1f0
void CItemExtraData::FUN_14059a1f0(int n)
{
    m_nPick = n;
}

// @0x14059a210
int CItemExtraData::FUN_14059a210()
{
    return m_nPick;
}

// @0x14059a230
CItemExtraData::ColorPtr CItemExtraData::FUN_14059a230(unsigned nSlot) const
{
    if (!m_bMulti)
        return m_spColor;
    return m_colors[nSlot];
}

// @0x14059a2c0
CItemExtraData::ColorPtr CItemExtraData::FUN_14059a2c0()
{
    if (!m_bMulti)
        return m_spColor;
    return m_colors[m_nIndex];
}

// @0x14059a350
int CItemExtraData::FUN_14059a350()
{
    if (!m_bMulti)
        return 0;
    if (m_nNextTick < FUN_140869420())
    {
        m_nNextTick = FUN_140869420() + FUN_14059a120();
        int nCount = (int)m_colors.size();
        m_nIndex++;
        if (nCount <= m_nIndex)
            m_nIndex = 0;
        return 1;
    }
    return 0;
}

// @0x14059d130
int CItemExtraData::FUN_14059d130() const
{
    return m_nKind;
}

// @0x14059d140
int CItemExtraData::FUN_14059d140() const
{
    return m_nKind;
}

// ---- CDecalExtraData ----

// @0x14059a400
CDecalExtraData::CDecalExtraData()
{
    m_nKind = 1;
    m_f64 = 0;
    m_f60 = 0;
    m_f5c = 0;
    m_f58 = 0;
}

// The decal block's values (inline accessors of CharacterDecalData).
// @0x14059d0f0
static float FUN_14059d0f0(CharacterDecalData* p) { return p->unknown28; }
// @0x14059d100
static float FUN_14059d100(CharacterDecalData* p) { return p->unknown2c; }
// @0x14059d110
static float FUN_14059d110(CharacterDecalData* p) { return p->unknown20; }
// @0x14059d120
static float FUN_14059d120(CharacterDecalData* p) { return p->unknown24; }

// @0x14059a480
void CDecalExtraData::vfunc_4(void* p)
{
    CItemExtraData::vfunc_4(p);
    CItemData* pData = (CItemData*)p;
    CharacterDecalData* pDecal = pData->FUN_14053eba0()->FUN_14054b6b0();
    if (pDecal != 0)
    {
        m_f58 = FUN_14059d110(pDecal);
        m_f5c = FUN_14059d120(pDecal);
        m_f64 = FUN_14059d0f0(pDecal);
        m_f60 = FUN_14059d100(pDecal);
        std::vector<MS2Ptr<ItemCustom> >* pList = pDecal->FUN_1401e41c0();
        if (!pList->empty())
        {
            int nCount = (int)pList->size();
            int r = rand();
            m_nPick = r % nCount;
            MS2Ptr<ItemCustom>& spCustom = (*pList)[r % nCount];
            m_f58 = spCustom->unknown18.x;
            m_f5c = spCustom->unknown18.y;
            m_f64 = spCustom->unknown24.z;
        }
        if (pData->FUN_14053eba0()->FUN_14054b3d0() != 0)
            m_f60 = pData->FUN_14053eba0()->FUN_14054b2f0(0)->FUN_1405450f0(0);
    }
}

// @0x14059a620
void CDecalExtraData::vfunc_3(const CItemExtraData* p)
{
    CItemExtraData::vfunc_3(p);
    const CDecalExtraData* pOther = (const CDecalExtraData*)p;
    if (pOther != 0)
    {
        m_f58 = pOther->m_f58;
        m_f5c = pOther->m_f5c;
        m_f60 = pOther->m_f60;
        m_f64 = pOther->m_f64;
    }
}

// @0x14059a6b0
void CDecalExtraData::vfunc_5(COutputStream& os)
{
    CItemExtraData::vfunc_5(os);
    os.vfunc_o10_5(m_f58);
    os.vfunc_o10_5(m_f5c);
    os.vfunc_o10_5(m_f60);
    os.vfunc_o10_5(m_f64);
}

// @0x14059a740
void CDecalExtraData::vfunc_6(CInputStream& is)
{
    CItemExtraData::vfunc_6(is);
    m_f58 = is.vfunc_o8_5();
    m_f5c = is.vfunc_o8_5();
    m_f60 = is.vfunc_o8_5();
    m_f64 = is.vfunc_o8_5();
}

// @0x14059a7d0
int CDecalExtraData::vfunc_2(const CItemExtraData* p)
{
    const CDecalExtraData* pOther = (const CDecalExtraData*)p;
    if (!CItemExtraData::vfunc_2(p))
        return 0;
    return !FUN_14059bfe0(m_f58, pOther->m_f58) && !FUN_14059bfe0(m_f5c, pOther->m_f5c) && !FUN_14059bfe0(m_f60, pOther->m_f60)
        && !FUN_14059bfe0(m_f64, pOther->m_f64);
}

// ---- CHairExtraData ----

// @0x14059a8a0
CHairExtraData::CHairExtraData()
{
    m_nKind = 2;
    for (int i = 0; i < 2; i++)
    {
        m_fScale[i] = 0;
        m_aPt1[i].x = 0;
        m_aPt1[i].y = 0;
        m_aPt1[i].z = 0;
        m_aPt2[i].x = 0;
        m_aPt2[i].y = 0;
        m_aPt2[i].z = 0;
    }
    m_bUseScale = 0;
    m_bUsePt2 = 0;
    m_bUsePt1 = 0;
}

// @0x14059aa20
void CHairExtraData::FUN_14059aa20()
{
    for (int i = 0; i < 2; i++)
    {
        float f;
        if (m_fScale[i] >= 0.0f)
            f = m_fScale[i];
        else
            f = 0;
        m_fScale[i] = f;
    }
}

// @0x14059aaa0
void CHairExtraData::vfunc_4(void* p)
{
    CItemExtraData::vfunc_4(p);
    CItemData* pData = (CItemData*)p;
    if (pData->FUN_14053eba0()->FUN_14054b3d0() != 0)
    {
        const ModelGroup* pGroup = pData->FUN_14053eba0()->FUN_14054b2f0(0);
        int nPick = -1;
        int nSlot = 0;
        for (size_t i = 0; i < pGroup->FUN_1405450c0() && nSlot < 2; i++)
        {
            const ModelPart* pPart = pGroup->FUN_140544fe0(i);
            if (pPart->pony != 0 && !pPart->customs.empty())
            {
                size_t nCount = pPart->customs.size();
                if (nPick == -1)
                {
                    int r = rand();
                    nPick = (int)((unsigned __int64)(__int64)r % nCount);
                }
                m_nPick = nPick;
                MS2Ptr<ItemCustom> spCustom = pPart->customs[nPick];
                m_aPt1[nSlot] = AsPt(spCustom.get()->unknown18);
                m_aPt2[nSlot] = AsPt(spCustom.get()->unknown24);
                nSlot++;
            }
        }
        for (int i = 0; i < 2; i++)
            m_fScale[i] = pGroup->FUN_140544f20(i)->FUN_140544c20();
        FUN_14059aa20();
        m_bUseScale = 1;
        m_bUsePt2 = 1;
        m_bUsePt1 = 1;
        m_bUseScale = FUN_14053ec70(pData)->FUN_140547130();
        m_bUsePt1 = FUN_14053ec70(pData)->FUN_140547170();
        m_bUsePt2 = m_bUsePt1;
    }
}

// @0x14059ad20
void CHairExtraData::vfunc_3(const CItemExtraData* p)
{
    CItemExtraData::vfunc_3(p);
    const CHairExtraData* pOther = (const CHairExtraData*)p;
    if (pOther != 0)
    {
        for (unsigned i = 0; i < 2; i++)
        {
            m_fScale[i] = pOther->m_fScale[i];
            m_aPt1[i] = pOther->m_aPt1[i];
            m_aPt2[i] = pOther->m_aPt2[i];
        }
        m_bUseScale = pOther->m_bUseScale;
        m_bUsePt2 = pOther->m_bUsePt2;
        m_bUsePt1 = pOther->m_bUsePt1;
    }
    FUN_14059aa20();
}

// @0x14059ae50
void CHairExtraData::vfunc_5(COutputStream& os)
{
    CItemExtraData::vfunc_5(os);
    for (int i = 0; i < 2; i++)
    {
        os.vfunc_o10_5(m_fScale[i]);
        os.vfunc_o10_10(m_aPt1[i]);
        os.vfunc_o10_10(m_aPt2[i]);
    }
}

// @0x14059af30
void CHairExtraData::vfunc_6(CInputStream& is)
{
    CItemExtraData::vfunc_6(is);
    CHairExtraData kTemp;
    for (int i = 0; i < 2; i++)
    {
        kTemp.m_fScale[i] = is.vfunc_o8_5();
        kTemp.m_aPt1[i] = is.vfunc_o8_10();
        kTemp.m_aPt2[i] = is.vfunc_o8_10();
    }
    for (int i = 0; i < 2; i++)
    {
        if (!FUN_14059d190(&kTemp.m_aPt1[i]))
            return;
        if (!FUN_14059d190(&kTemp.m_aPt2[i]))
            return;
        if (!FUN_14059d150(&kTemp.m_fScale[i]))
            return;
    }
    for (int i = 0; i < 2; i++)
    {
        if (m_bUseScale != 0)
            m_fScale[i] = kTemp.m_fScale[i];
        if (m_bUsePt1 != 0)
            m_aPt1[i] = kTemp.m_aPt1[i];
        if (m_bUsePt2 != 0)
            m_aPt2[i] = kTemp.m_aPt2[i];
    }
    FUN_14059aa20();
}

// @0x14059b1e0
int CHairExtraData::vfunc_2(const CItemExtraData* p)
{
    const CHairExtraData* pOther = (const CHairExtraData*)p;
    if (!CItemExtraData::vfunc_2(p))
        return 0;
    for (int i = 0; i < 2; i++)
    {
        if (FUN_14059bfe0(m_fScale[i], pOther->m_fScale[i]))
            return 0;
        if (FUN_14059c020(m_aPt1[i], pOther->m_aPt1[i]))
            return 0;
        if (FUN_14059c020(m_aPt2[i], pOther->m_aPt2[i]))
            return 0;
    }
    return 1;
}

// ---- CCapExtraData ----

// @0x14059b350
CCapExtraData::CCapExtraData()
{
    m_nKind = 3;
    for (int i = 0; i < 1; i++)
    {
        m_aPt[0].x = 0;
        m_aPt[0].y = 0;
        m_aPt[0].z = 0;
        m_aPt[1].x = 0;
        m_aPt[1].y = 0;
        m_aPt[1].z = 0;
        m_aPt[2].x = 0;
        m_aPt[2].y = 0;
        m_aPt[2].z = 0;
        m_aPt[3].x = 0;
        m_aPt[3].y = 0;
        m_aPt[3].z = 0;
    }
    m_f58 = 0;
}

// @0x14059b580
void CCapExtraData::vfunc_4(void* p)
{
    CItemExtraData::vfunc_4(p);
    CItemData* pData = (CItemData*)p;
    if (pData->FUN_14053eba0()->FUN_14054b3d0() != 0)
    {
        const ModelGroup* pGroup = pData->FUN_14053eba0()->FUN_14054b2f0(0);
        bool bDone = false;
        while (!bDone)
        {
            if (pGroup->FUN_1405450c0() != 0)
            {
                const ModelPart* pPart = pGroup->FUN_140544fe0(0);
                if (!pPart->customs.empty())
                {
                    int r = rand();
                    int nCount = (int)pPart->customs.size();
                    MS2Ptr<ItemCustom> spCustom = pPart->customs[r % nCount];
                    m_aPt[0] = AsPt(spCustom.get()->unknown18);
                    m_aPt[1] = AsPt(spCustom.get()->unknown24);
                    m_nPick = r % nCount;
                }
                if (!pPart->points.empty())
                {
                    int r = rand();
                    int nCount = (int)pPart->points.size();
                    m_aPt[3] = AsPt(pPart->points[r % nCount]);
                }
            }
            bDone = true;
        }
        m_f58 = pGroup->FUN_140544f20(0)->FUN_140544c20();
    }
}

// @0x14059b7c0
void CCapExtraData::vfunc_3(const CItemExtraData* p)
{
    CItemExtraData::vfunc_3(p);
    const CCapExtraData* pOther = (const CCapExtraData*)p;
    if (pOther != 0)
    {
        bool bDone = false;
        while (!bDone)
        {
            m_aPt[0] = pOther->m_aPt[0];
            m_aPt[1] = pOther->m_aPt[1];
            m_aPt[2] = pOther->m_aPt[2];
            m_aPt[3] = pOther->m_aPt[3];
            bDone = true;
        }
        m_f58 = pOther->m_f58;
    }
}

// @0x14059b8f0
void CCapExtraData::vfunc_5(COutputStream& os)
{
    CItemExtraData::vfunc_5(os);
    for (int i = 0; i < 1; i++)
    {
        os.vfunc_o10_10(m_aPt[0]);
        os.vfunc_o10_10(m_aPt[1]);
        os.vfunc_o10_10(m_aPt[2]);
        os.vfunc_o10_10(m_aPt[3]);
    }
    os.vfunc_o10_5(m_f58);
}

// @0x14059ba20
void CCapExtraData::vfunc_6(CInputStream& is)
{
    CItemExtraData::vfunc_6(is);
    CCapExtraData kTemp;
    for (int i = 0; i < 1; i++)
    {
        kTemp.m_aPt[0] = is.vfunc_o8_10();
        kTemp.m_aPt[1] = is.vfunc_o8_10();
        kTemp.m_aPt[2] = is.vfunc_o8_10();
        kTemp.m_aPt[3] = is.vfunc_o8_10();
    }
    kTemp.m_f58 = is.vfunc_o8_5();
    for (int i = 0; i < 1; i++)
    {
        if (!FUN_14059d190(&kTemp.m_aPt[0]))
            return;
        if (!FUN_14059d190(&kTemp.m_aPt[1]))
            return;
        if (!FUN_14059d190(&kTemp.m_aPt[2]))
            return;
        if (!FUN_14059d190(&kTemp.m_aPt[3]))
            return;
    }
    if (!FUN_14059d150(&kTemp.m_f58))
        return;
    for (int i = 0; i < 1; i++)
    {
        m_aPt[0] = kTemp.m_aPt[0];
        m_aPt[1] = kTemp.m_aPt[1];
        m_aPt[2] = kTemp.m_aPt[2];
        m_aPt[3] = kTemp.m_aPt[3];
    }
    m_f58 = kTemp.m_f58;
}

// @0x14059bda0
int CCapExtraData::vfunc_2(const CItemExtraData* p)
{
    const CCapExtraData* pOther = (const CCapExtraData*)p;
    if (!CItemExtraData::vfunc_2(p))
        return 0;
    if (FUN_14059bfe0(m_f58, pOther->m_f58))
        return 0;
    for (int i = 0; i < 1; i++)
    {
        if (FUN_14059c020(m_aPt[0], pOther->m_aPt[0]))
            return 0;
        if (FUN_14059c020(m_aPt[1], pOther->m_aPt[1]))
            return 0;
        if (FUN_14059c020(m_aPt[2], pOther->m_aPt[2]))
            return 0;
        if (FUN_14059c020(m_aPt[3], pOther->m_aPt[3]))
            return 0;
    }
    return 1;
}

// ---- finite checks and the bounds-checked / small glue (inline COMDATs of the original) ----

// @0x14059d150
bool FUN_14059d150(float* p)
{
    return (_fpclass((double)*p) & 0x207) == 0;
}

// @0x14059d190
static bool FUN_14059d190(Unk_StreamPoint* p)
{
    return (_fpclass((double)p->x) & 0x207) == 0 && (_fpclass((double)p->y) & 0x207) == 0 && (_fpclass((double)p->z) & 0x207) == 0;
}

template class std::vector<Unk_SocketPtr<EquipColorInfo> >;
