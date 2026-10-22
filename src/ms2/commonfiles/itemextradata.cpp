// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemExtraData and its decal / hair / cap subclasses: the
// per-item colouring state (EquipColorInfo slots, the cycling of multi-colour items, the random decal / hair / cap
// customisations picked from the item model), plus the std::vector<Unk_SocketPtr<EquipColorInfo>> glue.
// MS2-UNIT: ?\itemextradata.cpp
// MS2-RANGE: 0x140598b80-0x14059dcd0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?New@?$Unk_SocketRef@VEquipColorInfo@@@@SAPEAVEquipColorInfo@@PEAX@Z 0x14059c0e0 ; unique
// MS2-PIN: ??$_Uninitialized_move@PEAV?$Unk_SocketPtr@VEquipColorInfo@@@@PEAV1@V?$allocator@V?$Unk_SocketPtr@VEquipColorInfo@@@@@std@@@std@@YAPEAV?$Unk_SocketPtr@VEquipColorInfo@@@@QEAV1@0PEAV1@AEAV?$allocator@V?$Unk_SocketPtr@VEquipColorInfo@@@@@0@@Z 0x14059c830 ; unique
// MS2-PIN: ??A?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAAAEAH_K@Z 0x14059ce00 ; unique
// MS2-PIN: ??4?$Unk_SocketPtr@VEquipColorInfo@@@@QEAAAEAV0@AEBUUnk_SocketNew@@@Z 0x14059d0b0 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEBA_KXZ 0x14059d0e0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?AddRefImpl@?$Unk_SocketPtr@VEquipColorInfo@@@@AEBAXPEAX@Z 0x14059d250
// MS2-PIN: ?ReleaseImpl@?$Unk_SocketPtr@VEquipColorInfo@@@@AEAAXPEAX@Z 0x14059d710
// MS2-PIN: ?Create@?$Unk_SocketRef@VEquipColorInfo@@@@SAPEAVEquipColorInfo@@PEAX@Z 0x14059d2b0
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
int FUN_14059d150(float* p);
CItemDataTable* FUN_140281980();                                // the item table singleton
void FUN_140159b70(long hr);                                    // ATL throw
float FUN_14029dd40(float f);                                   // fabs
CStringW FUN_14028de60(int nId, void* a, void* b, int nFlag);   // string table text with two arguments

static bool FUN_14059d190(Unk_StreamPoint* p);
static inline const Unk_StreamPoint& AsPt(const efd::Point3& p) { return *(const Unk_StreamPoint*)&p; }

// ---- the float helpers of the unit ----

// @0x14059d930
static float FUN_14059d930(float f) { return FUN_14029dd40(f); }

// @0x14059bfe0
static int FUN_14059bfe0(float a, float b)
{
    if (FUN_14059d930(a - b) > 0.0001f)
        return 1;
    return 0;
}

// @0x14059c020
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x140598BF0, EquipColorInfo, FUN_140598bf0, 136, 0x0DAE7468);

// @0x140598c80
void EquipColorInfo::FUN_140598c80(CInputStream& is)
{
    for (int i = 0; i < 3; i++)
        m_aRgb[i] = is.vfunc_o8_3();
    m_n24 = is.vfunc_o8_3();
    m_n28 = is.vfunc_o8_3();
}
MS2_REPLACE_METHOD(0x140598C80, EquipColorInfo, FUN_140598c80, 126, 0x19A61ADF);

// @0x140598d10
void EquipColorInfo::FUN_140598d10(Unk_SocketPtr<EquipColorInfo> spSrc)
{
    if (spSrc == 0)
        return;
    for (unsigned i = 0; i < 3; i++)
        m_aRgb[i] = spSrc->m_aRgb[i];
    m_n24 = spSrc->m_n24;
    m_n28 = spSrc->m_n28;
    m_n2c = spSrc->m_n2c;
}
MS2_REPLACE_METHOD(0x140598D10, EquipColorInfo, FUN_140598d10, 196, 0xB205876E);

// @0x140598de0
void EquipColorInfo::FUN_140598de0(const ItemColorEx& kColor, int nDelay)
{
    for (unsigned i = 0; i < 3; i++)
        m_aRgb[i] = kColor.m_aValues[i];
    m_n24 = kColor.m_nColor;
    m_n28 = kColor.m_nId;
    m_n2c = nDelay;
}
MS2_REPLACE_METHOD(0x140598DE0, EquipColorInfo, FUN_140598de0, 118, 0xE7C7D198);

// ---- CItemExtraData ----

// @0x140598e60
CItemExtraData::CItemExtraData()
    : m_nIndex(0), m_nPick(-1), m_bMulti(false), m_nNextTick(FUN_140869420()), m_nKind(0)
{
    m_spColor = Unk_SocketNew(0);
}

// @0x140598f20
CItemExtraData::~CItemExtraData()
{
}

// @0x140598f70
int CItemExtraData::vfunc_1(const CItemExtraData* pOther)
{
    if (FUN_14059d140() != pOther->FUN_14059d140())
        return 0;
    if (!FUN_140599830(pOther))
        return 0;
    if (!vfunc_2(pOther))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140598F70, CItemExtraData, vfunc_1, 112, 0x51C8CF20);

// @0x140598ff0
int CItemExtraData::vfunc_2(const CItemExtraData* pOther)
{
    if (FUN_14059d140() != pOther->FUN_14059d140())
        return 0;
    if (m_nPick != pOther->m_nPick)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140598FF0, CItemExtraData, vfunc_2, 82, 0x373D0EFF);

// @0x140599050
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
void CItemExtraData::vfunc_4(CItemData* pData)
{
    if (pData->FUN_14053e370())
    {
        m_bMulti = true;
        FUN_1405993b0(pData->FUN_14053e3c0());
    }
    FUN_140599ab0(pData);
    m_nPick = -1;
}
MS2_REPLACE_METHOD(0x140599050, CItemExtraData, vfunc_4, 94, 0xAE5B03FD);

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
MS2_REPLACE_METHOD(0x1405990C0, CItemExtraData, vfunc_3, 275, 0x665E5687);

// @0x1405991e0
void CItemExtraData::vfunc_5(COutputStream& os)
{
    FUN_14059a230(0)->FUN_140598bf0(os);
}
MS2_REPLACE_METHOD(0x1405991E0, CItemExtraData, vfunc_5, 95, 0x1F21C654);

// @0x140599250
void CItemExtraData::vfunc_6(CInputStream& is)
{
    m_nPick = -1;
    FUN_14059a230(0)->FUN_140598c80(is);
}
MS2_REPLACE_METHOD(0x140599250, CItemExtraData, vfunc_6, 107, 0x28DE9ABA);

// @0x1405992d0
void CItemExtraData::vfunc_7(COutputStream& os)
{
    FUN_14059a230(0)->FUN_140598bf0(os);
}
MS2_REPLACE_METHOD(0x1405992D0, CItemExtraData, vfunc_7, 95, 0x21DC447E);

// @0x140599340
void CItemExtraData::vfunc_8(CInputStream& is)
{
    FUN_14059a230(0)->FUN_140598c80(is);
}
MS2_REPLACE_METHOD(0x140599340, CItemExtraData, vfunc_8, 95, 0xB13713E5);

// @0x1405993b0
// MS2-FUNCTIONAL: the temporary for the new slot takes a larger frame; same calls
void CItemExtraData::FUN_1405993b0(unsigned nCount)
{
    m_colors.clear();
    for (unsigned i = 0; i < nCount; i++)
        m_colors.push_back(ColorPtr(new EquipColorInfo));
}
MS2_REPLACE_METHOD(0x1405993B0, CItemExtraData, FUN_1405993b0, 187, 0xD8265443);

// @0x140599480
bool CItemExtraData::FUN_140599480(const ItemColorEx& kColor, MS2Ptr<CItemData> spData)
{
    return FUN_140599510(kColor, spData) == 1;
}
MS2_REPLACE_METHOD(0x140599480, CItemExtraData, FUN_140599480, 130, 0x05239006);

// @0x140599510
// MS2-FUNCTIONAL: local slot numbering of the && temporaries differs; same compares
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
MS2_REPLACE_METHOD(0x140599510, CItemExtraData, FUN_140599510, 789, 0xBFB0C7A2);

// @0x140599830
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x140599830, CItemExtraData, FUN_140599830, 300, 0x11708C7C);

// @0x140599970
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x140599970, CItemExtraData, FUN_140599970, 300, 0xF1923389);

ItemModelHead* FUN_14053ec70(CItemData* pData);

// @0x140599ab0
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x140599AB0, CItemExtraData, FUN_140599ab0, 258, 0x31D11ED4);

// @0x140599bc0
void CItemExtraData::FUN_140599bc0(const ItemColorEx* pColor, bool bExtra, int nDelay, unsigned nSlot)
{
    FUN_14059a230(nSlot)->FUN_140598de0(*pColor, nDelay);
    if (bExtra)
    {
        FUN_14059a230(nSlot)->m_aRgb[0] = pColor->m_n30;
        FUN_14059a230(nSlot)->m_aRgb[2] = pColor->m_n34;
    }
}
MS2_REPLACE_METHOD(0x140599BC0, CItemExtraData, FUN_140599bc0, 316, 0x47C410E4);

// @0x140599d10
void CItemExtraData::FUN_140599d10(ATL::CAtlArray<int>& aValues, unsigned nSlot)
{
    size_t nCount = aValues.GetCount() < 3 ? aValues.GetCount() : 3;
    for (size_t i = 0; i < nCount; i++)
        FUN_14059a230(nSlot)->m_aRgb[i] = aValues[i];
    FUN_14059a230(nSlot)->m_n24 = -1;
    FUN_14059a230(nSlot)->m_n28 = 0;
}
MS2_REPLACE_METHOD(0x140599D10, CItemExtraData, FUN_140599d10, 383, 0x5601278D);

// @0x140599ea0
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
void CItemExtraData::FUN_140599ea0(int nIndex, const int& nValue, unsigned nSlot)
{
    if (nIndex >= 0 && nIndex < 3)
    {
        FUN_14059a230(nSlot)->m_aRgb[nIndex] = nValue;
        FUN_14059a230(nSlot)->m_n24 = -1;
        FUN_14059a230(nSlot)->m_n28 = 0;
    }
}
MS2_REPLACE_METHOD(0x140599EA0, CItemExtraData, FUN_140599ea0, 287, 0x2890776D);

// @0x140599fd0
int CItemExtraData::FUN_140599fd0(unsigned nIndex)
{
    if (nIndex >= 3)
        return 0;
    return FUN_14059a2c0()->m_aRgb[nIndex];
}
MS2_REPLACE_METHOD(0x140599FD0, CItemExtraData, FUN_140599fd0, 104, 0x96D99435);

// @0x14059a040
int CItemExtraData::FUN_14059a040(unsigned nSlot)
{
    return FUN_14059a230(nSlot)->m_n24;
}
MS2_REPLACE_METHOD(0x14059A040, CItemExtraData, FUN_14059a040, 93, 0x09AAFA23);

// @0x14059a0b0
int CItemExtraData::FUN_14059a0b0(unsigned nSlot)
{
    return FUN_14059a230(nSlot)->m_n28;
}
MS2_REPLACE_METHOD(0x14059A0B0, CItemExtraData, FUN_14059a0b0, 93, 0x45D820B0);

// @0x14059a120
int CItemExtraData::FUN_14059a120()
{
    return FUN_14059a2c0()->m_n2c;
}
MS2_REPLACE_METHOD(0x14059A120, CItemExtraData, FUN_14059a120, 84, 0xF34D474C);

// @0x14059a180
int* CItemExtraData::FUN_14059a180(unsigned nSlot)
{
    return FUN_14059a230(nSlot)->m_aRgb;
}
MS2_REPLACE_METHOD(0x14059A180, CItemExtraData, FUN_14059a180, 96, 0x21C9BAD5);

// @0x14059a1f0
void CItemExtraData::SetPick(int n)
{
    m_nPick = n;
}
MS2_REPLACE_METHOD(0x14059A1F0, CItemExtraData, SetPick, 22, 0x6E748507);

// @0x14059a210
int CItemExtraData::GetPick()
{
    return m_nPick;
}
MS2_REPLACE_METHOD(0x14059A210, CItemExtraData, GetPick, 14, 0x8AEE455B);

// @0x14059a230
CItemExtraData::ColorPtr CItemExtraData::FUN_14059a230(unsigned nSlot) const
{
    if (m_bMulti)
        return m_colors[nSlot];
    else
        return m_spColor;
}
MS2_REPLACE_METHOD(0x14059A230, CItemExtraData, FUN_14059a230, 134, 0xCF0149B8);

// @0x14059a2c0
CItemExtraData::ColorPtr CItemExtraData::FUN_14059a2c0()
{
    if (m_bMulti)
        return m_colors[m_nIndex];
    else
        return m_spColor;
}
MS2_REPLACE_METHOD(0x14059A2C0, CItemExtraData, FUN_14059a2c0, 135, 0x5AAF8249);

// @0x14059a350
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
bool CItemExtraData::FUN_14059a350()
{
    if (!m_bMulti)
        return false;
    if (m_nNextTick < FUN_140869420())
    {
        m_nNextTick = FUN_140869420() + FUN_14059a120();
        int nCount = (int)m_colors.size();
        m_nIndex++;
        if (nCount <= m_nIndex)
            m_nIndex = 0;
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14059A350, CItemExtraData, FUN_14059a350, 156, 0x2C345355);

// @0x14059d130
int CItemExtraData::FUN_14059d130() const
{
    return m_nKind;
}
MS2_REPLACE_METHOD(0x14059D130, CItemExtraData, FUN_14059d130, 14, 0xD26D6807);

// @0x14059d140
int CItemExtraData::FUN_14059d140() const
{
    return m_nKind;
}
MS2_REPLACE_METHOD(0x14059D140, CItemExtraData, FUN_14059d140, 14, 0xD26D6807);

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
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
void CDecalExtraData::vfunc_4(CItemData* pData)
{
    CItemExtraData::vfunc_4(pData);
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
MS2_REPLACE_METHOD(0x14059A480, CDecalExtraData, vfunc_4, 408, 0x409B00C4);

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
MS2_REPLACE_METHOD(0x14059A620, CDecalExtraData, vfunc_3, 132, 0x0AD8B5F4);

// @0x14059a6b0
void CDecalExtraData::vfunc_5(COutputStream& os)
{
    CItemExtraData::vfunc_5(os);
    os.vfunc_o10_5(m_f58);
    os.vfunc_o10_5(m_f5c);
    os.vfunc_o10_5(m_f60);
    os.vfunc_o10_5(m_f64);
}
MS2_REPLACE_METHOD(0x14059A6B0, CDecalExtraData, vfunc_5, 138, 0x6ECA11DA);

// @0x14059a740
void CDecalExtraData::vfunc_6(CInputStream& is)
{
    CItemExtraData::vfunc_6(is);
    m_f58 = is.vfunc_o8_5();
    m_f5c = is.vfunc_o8_5();
    m_f60 = is.vfunc_o8_5();
    m_f64 = is.vfunc_o8_5();
}
MS2_REPLACE_METHOD(0x14059A740, CDecalExtraData, vfunc_6, 138, 0x8D92BBDB);

// @0x14059a7d0
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
int CDecalExtraData::vfunc_2(const CItemExtraData* p)
{
    const CDecalExtraData* pOther = (const CDecalExtraData*)p;
    if (!CItemExtraData::vfunc_2(p))
        return 0;
    return !FUN_14059bfe0(m_f58, pOther->m_f58) && !FUN_14059bfe0(m_f5c, pOther->m_f5c) && !FUN_14059bfe0(m_f60, pOther->m_f60)
        && !FUN_14059bfe0(m_f64, pOther->m_f64);
}
MS2_REPLACE_METHOD(0x14059A7D0, CDecalExtraData, vfunc_2, 192, 0x5E8EF508);

// ---- CHairExtraData ----

// @0x14059a8a0
CHairExtraData::CHairExtraData()
{
    m_nKind = 2;
    for (int i = 0; i < 2; i++)
    {
        m_fScale[i] = 0;
        m_aPt1[i].z = 0;
        m_aPt1[i].y = 0;
        m_aPt1[i].x = 0;
        m_aPt2[i].z = 0;
        m_aPt2[i].y = 0;
        m_aPt2[i].x = 0;
    }
    m_bUseScale = 0;
    m_bUsePt2 = 0;
    m_bUsePt1 = 0;
}

// @0x14059aa20
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x14059AA20, CHairExtraData, FUN_14059aa20, 111, 0x557560E6);

// @0x14059aaa0
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
void CHairExtraData::vfunc_4(CItemData* pData)
{
    CItemExtraData::vfunc_4(pData);
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
MS2_REPLACE_METHOD(0x14059AAA0, CHairExtraData, vfunc_4, 619, 0x92D8C0B2);

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
MS2_REPLACE_METHOD(0x14059AD20, CHairExtraData, vfunc_3, 283, 0xE6629404);

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
MS2_REPLACE_METHOD(0x14059AE50, CHairExtraData, vfunc_5, 208, 0x03EF954E);

// @0x14059af30
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x14059AF30, CHairExtraData, vfunc_6, 678, 0x0721B862);

// @0x14059b1e0
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x14059B1E0, CHairExtraData, vfunc_2, 348, 0xD1770D42);

// ---- CCapExtraData ----

// @0x14059b350
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
CCapExtraData::CCapExtraData()
{
    m_nKind = 3;
    for (int i = 0; i < 1; i++)
    {
        m_aPt[0].z = 0;
        m_aPt[0].y = 0;
        m_aPt[0].x = 0;
        m_aPt[1].z = 0;
        m_aPt[1].y = 0;
        m_aPt[1].x = 0;
        m_aPt[2].z = 0;
        m_aPt[2].y = 0;
        m_aPt[2].x = 0;
        m_aPt[3].z = 0;
        m_aPt[3].y = 0;
        m_aPt[3].x = 0;
    }
    m_f58 = 0;
}

// @0x14059b580
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
void CCapExtraData::vfunc_4(CItemData* pData)
{
    CItemExtraData::vfunc_4(pData);
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
MS2_REPLACE_METHOD(0x14059B580, CCapExtraData, vfunc_4, 558, 0x209EDBB1);

// @0x14059b7c0
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x14059B7C0, CCapExtraData, vfunc_3, 294, 0x015D4E75);

// @0x14059b8f0
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x14059B8F0, CCapExtraData, vfunc_5, 291, 0x1817F2EB);

// @0x14059ba20
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x14059BA20, CCapExtraData, vfunc_6, 878, 0x7C8BC079);

// @0x14059bda0
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
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
MS2_REPLACE_METHOD(0x14059BDA0, CCapExtraData, vfunc_2, 560, 0xFEDE7F42);

// ---- finite checks and the bounds-checked / small glue (inline COMDATs of the original) ----

// @0x14059d150
int FUN_14059d150(float* p)
{
    if (_fpclass((double)*p) & 0x207)
        return 0;
    else
        return 1;
}

// @0x14059d190
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
static bool FUN_14059d190(Unk_StreamPoint* p)
{
    return (_fpclass((double)p->x) & 0x207) == 0 && (_fpclass((double)p->y) & 0x207) == 0 && (_fpclass((double)p->z) & 0x207) == 0;
}

// The colour hint text of a palette group (no caller in the unit; the arguments are passed through).
// @0x14059dbe0
// MS2-FUNCTIONAL: MSVC /Od temp and branch layout of the inlined smart-pointer / vector / point copies differs; same operations in the same order
CStringW FUN_14059dbe0(int nGroup, void* a, void* b)
{
    if (nGroup == 1)
        return FUN_14028de60(0xd52, a, b, 0);
    else if (nGroup == 2)
        return FUN_14028de60(0xd53, a, b, 0);
    else if (nGroup == 3)
        return FUN_14028de60(0xd54, a, b, 0);
    else if (nGroup == 4)
        return FUN_14028de60(0xd55, a, b, 0);
    else
        return FUN_14028de60(0xd52, a, b, 0);
}

template class std::vector<Unk_SocketPtr<EquipColorInfo> >;
