// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNpcData (Xml/NpcData/<id>.xml), the value blocks of a row
// (model, stats, shapes, drop, ...), the region spawn classes (Table/NpcRegionSpawnData.xml) and the NpcDataTable that
// loads them, plus the container glue of those members (CAtlArray, std::vector, CAtlMap, std::bitset).
// MS2-UNIT: commonfiles\npcdata.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x1406c8680-0x1406dc170 .text$mn
// MS2-RANGE: 0x1400bb810-0x1400bb9a0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H$0A@@?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@$$QEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@$$QEAH@Z 0x1406cf6c0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCNpcData@@@@QEAA@$$QEAV0@@Z 0x1406cf850 ; unique
// MS2-PIN: ??$?8HH@std@@YA_NAEBU?$pair@HH@0@0@Z 0x1406cf930 ; unique
// MS2-PIN: ??$IsSameArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@@YA_NAEBV?$CAtlArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@V?$CElementTraits@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@@ATL@@0@Z 0x1406cfc90 ; unique
// MS2-PIN: ??$_Kfn@$$CBK_N@?$_Tmap_traits@K_NU?$less@K@std@@V?$allocator@U?$pair@$$CBK_N@std@@@2@$0A@@std@@SAAEBKAEBU?$pair@$$CBK_N@1@@Z 0x1406d3860 ; unique
// MS2-PIN: ??$_Try_emplace@AEBK$$V@?$map@K_NU?$less@K@std@@V?$allocator@U?$pair@$$CBK_N@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@std@@@std@@_N@1@AEBK@Z 0x1406d3b50 ; unique
// MS2-PIN: ??$copy@V?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@V?$insert_iterator@V?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@2@@std@@YA?AV?$insert_iterator@V?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@0@V?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@0@0V10@@Z 0x1406d3e90 ; unique
// MS2-PIN: ??$make_pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@YA?AU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@0@$$QEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@$$QEAH@Z 0x1406d42d0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCRegionSpawnResult@@@@QEAA@AEBV0@@Z 0x1406d46c0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCRegionSpawnResult@@@@QEAA@PEAVCRegionSpawnResult@@@Z 0x1406d4700 ; prop
// MS2-PIN: ??0?$Unk_BmPtr@VCNpcRegionSpawnData@@@@QEAA@AEBV0@@Z 0x1406d47e0 ; prop
// MS2-PIN: ??0?$Unk_BmPtr@VCNpcRegionSpawnData@@@@QEAA@AEBUUnk_BmNewTag@@@Z 0x1406d4820 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCCacheData@@@@QEAA@PEAVCCacheData@@@Z 0x1406d4850 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCRegionSpawnProb@@@@QEAA@H@Z 0x1406d48e0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCRegionSpawnProb@@@@QEAA@PEAVCRegionSpawnProb@@@Z 0x1406d4900 ; prop
// MS2-PIN: ??0?$MS2Ptr@VNodeCollision@CNpcData@@@@QEAA@AEBV0@@Z 0x1406d4980 ; prop
// MS2-PIN: ??0?$MS2Ptr@VNodeCollision@CNpcData@@@@QEAA@PEAVNodeCollision@CNpcData@@@Z 0x1406d49c0 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@@std@@@std@@@std@@QEAA@XZ 0x1406d4ac0 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@std@@@std@@QEAA@XZ 0x1406d4ae0 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x1406d4b40 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x1406d4ba0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x1406d4bc0 ; prop
// MS2-PIN: ??0?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@AEBU01@@Z 0x1406d4d50 ; unique
// MS2-PIN: ??1?$map@IV?$MS2Ptr@VCCacheData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@@3@@std@@QEAA@XZ 0x1406d5420 ; prop
// MS2-PIN: ??1?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@XZ 0x1406d5460 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCCacheData@@@@QEAAAEAV1@PEAVCCacheData@@@Z 0x1406d58f0 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCRegionSpawnProb@@@@V?$CElementTraits@V?$MS2Ptr@VCRegionSpawnProb@@@@@ATL@@@ATL@@QEBAAEBV?$MS2Ptr@VCRegionSpawnProb@@@@_K@Z 0x1406d5b40 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@1@XZ 0x1406d5d50 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBK_N@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1406d5ed0 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1406d5f30 ; prop
// MS2-PIN: ??_G?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAAPEAXI@Z 0x1406d61f0 ; unique
// MS2-PIN: ?Add@?$CAtlArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@V?$CElementTraits@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@@ATL@@QEAA_KAEBU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@Z 0x1406d6430 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCRegionSpawnResult@@@@V?$CElementTraits@V?$MS2Ptr@VCRegionSpawnResult@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCRegionSpawnResult@@@@@Z 0x1406d64e0 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCRegionSpawnProb@@@@V?$CElementTraits@V?$MS2Ptr@VCRegionSpawnProb@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCRegionSpawnProb@@@@@Z 0x1406d6590 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VNodeCollision@CNpcData@@@@V?$CElementTraits@V?$MS2Ptr@VNodeCollision@CNpcData@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VNodeCollision@CNpcData@@@@@Z 0x1406d6640 ; prop
// MS2-PIN: ?CallDestructors@?$CAtlArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@V?$CElementTraits@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@@ATL@@CAXPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@_K@Z 0x1406d6770 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@V?$CElementTraits@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@@ATL@@QEBA_KXZ 0x1406d6e20 ; prop
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VCRegionSpawnProb@@@@V?$CElementTraits@V?$MS2Ptr@VCRegionSpawnProb@@@@@ATL@@@ATL@@QEBA_KXZ 0x1406d6e40 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Unk_BmPtr@VCNpcRegionSpawnData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VCNpcRegionSpawnData@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1406d6f40 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@V?$CElementTraits@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@@ATL@@AEAA_N_K@Z 0x1406d7090 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCRegionSpawnResult@@@@V?$CElementTraits@V?$MS2Ptr@VCRegionSpawnResult@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x1406d7230 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VNodeCollision@CNpcData@@@@V?$CElementTraits@V?$MS2Ptr@VNodeCollision@CNpcData@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x1406d7570 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@ATL@@SAXPEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@0_K@Z 0x1406d8ff0 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCRegionSpawnResult@@@@@ATL@@SAXPEAV?$MS2Ptr@VCRegionSpawnResult@@@@0_K@Z 0x1406d9030 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VNodeCollision@CNpcData@@@@@ATL@@SAXPEAV?$MS2Ptr@VNodeCollision@CNpcData@@@@0_K@Z 0x1406d90b0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCRegionSpawnProb@@@@AEBAXPEAX@Z 0x1406d9fc0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VCCacheData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@PEAX@2@@Z 0x1406daac0 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@PEAX@2@_K@Z 0x1406db7a0 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@PEAX@2@_K@Z 0x1406db7d0 ; prop
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@std@@@std@@SAPEAU?$pair@$$CBIV?$MS2Ptr@VCCacheData@@@@@2@AEAU32@@Z 0x1406dbd30 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCCacheData@@@@AEAAXPEAX@Z 0x1406db0c0 ; merge-bind
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCNpcData@@@@AEAAXPEAX@Z 0x1406db200 ; merge-bind
// MS2-PIN: ??1NodeCollision@CNpcData@@UEAA@XZ 0x1406d5820
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBI_N@std@@PEAX@2@XZ 0x1406da210 ; manual
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBI_N@std@@PEAX@2@@Z 0x1406daaf0 ; manual
// MS2-PIN: ??1CNpcRegionSpawnData@@UEAA@XZ 0x1406d5570
// MS2-PIN: ??1CRegionSpawnProb@@UEAA@XZ 0x1406d5620
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\npcdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "npcdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <stdlib.h>

// The sort names of the item lists (header statics; the 8 name table first, as in the exe's initializer order).
static CStringA s_sortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CStringA s_sortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// Unrecovered helpers.
void FUN_14086f970(void* pElem, const char* pszName, double fValue);            // SetDoubleAttribute
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);               // SetAttribute(name, int)
void FUN_140874050(void* pElem, const char* pszName, const CStringA& strValue); // SetAttribute(name, string)
struct Unk_NpcPoint3
{
    Unk_NpcPoint3(const Unk_StreamPoint& pt);   // 0x14027dcf0
    float x, y, z;
};
void FUN_140874ad0(void* pElem, const char* pszName, const Unk_NpcPoint3& vValue);      // SetAttribute(name, "x, y, z")
void* FUN_14086e000(void* pParent, const void* pChild);                         // InsertEndChild
Unk_140165cf0* FUN_14028f8d0(Unk_140165cf0* pParent);                           // first child element
bool FUN_14028d470(float a, float b);                                           // approx equal

class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);      // 0x14086f2f0
    ~Unk_TiXmlElement();                        // 0x14086f450
private:
    void* m_data[0x12];
};

// @0x1406c8910
Unk_NpcModel::Unk_NpcModel() : m_fScale(1.0f), m_fAniSpeed(1.0f), m_nSpawnAlphaAnimation(1), m_vOffset(0.0f, 0.0f, 0.0f)
{
}

// @0x1406c8990
// MS2-FUNCTIONAL: frame is 2 bytes larger in the exe (the zero Unk_StreamPoint temp / Unk_NpcPoint3 temp placement)
void Unk_NpcModel::WriteXml(Unk_140165cf0* pParent) const
{
    static Unk_NpcModel s_default;
    if (*this != s_default)
    {
        Unk_TiXmlElement elem("model");
        if (m_strKfm != "")
            FUN_140874050(&elem, "kfm", m_strKfm);
        if (m_fScale != 1.0f)
            FUN_14086f970(&elem, "scale", m_fScale);
        if (m_fAniSpeed != 1.0f)
            FUN_14086f970(&elem, "anispeed", m_fAniSpeed);
        if (m_nSpawnAlphaAnimation != 1)
            FUN_140873ca0(&elem, "spawnAlphaAnimation", m_nSpawnAlphaAnimation);
        if (m_vOffset.FUN_140552700(Unk_StreamPoint(0.0f, 0.0f, 0.0f)))
            FUN_140874ad0(&elem, "offset", Unk_NpcPoint3(m_vOffset));
        FUN_14086e000(pParent, &elem);
    }
}

// @0x1406c8ba0
bool Unk_NpcModel::operator!=(const Unk_NpcModel& o) const
{
    if (m_strKfm != o.m_strKfm)
        return true;
    if (m_fScale != o.m_fScale)
        return true;
    if (m_fAniSpeed != o.m_fAniSpeed)
        return true;
    if (m_nSpawnAlphaAnimation != o.m_nSpawnAlphaAnimation)
        return true;
    if (m_vOffset.FUN_140552700(o.m_vOffset))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C8BA0, Unk_NpcModel, operator!=, 159, 0xC1CD1821);

// Container comparisons (true = same).
template <class T> bool IsSameArray(const ATL::CAtlArray<T>& a, const ATL::CAtlArray<T>& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (unsigned i = 0; i < a.GetCount(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
template <class T> bool IsSameArray(const ATL::CAtlArray<MS2Ptr<T> >& a, const ATL::CAtlArray<MS2Ptr<T> >& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (unsigned i = 0; i < a.GetCount(); i++)
    {
        if (*a[i] != *b[i])
            return false;
    }
    return true;
}
template <class T> bool IsSameVector(const std::vector<T>& a, const std::vector<T>& b)
{
    if (a.size() != b.size())
        return false;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

// @0x1406c8c50
Unk_NpcStat::Unk_NpcStat() : m_fScaleStatRate(0), m_nScaleBaseTap(0), m_nScaleBaseDef(0), m_fScaleBaseSpaRate(0)
{
    memset(m_aBase, 0, sizeof(m_aBase));
}

// @0x1406c8cc0
bool Unk_NpcStat::operator!=(const Unk_NpcStat& o) const
{
    for (int i = 0; i < 35; i++)
    {
        if (m_aBase[i] != o.m_aBase[i])
            return true;
    }
    if (m_fScaleStatRate != o.m_fScaleStatRate)
        return true;
    if (m_nScaleBaseTap != o.m_nScaleBaseTap)
        return true;
    if (m_nScaleBaseDef != o.m_nScaleBaseDef)
        return true;
    if (m_fScaleBaseSpaRate != o.m_fScaleBaseSpaRate)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C8CC0, Unk_NpcStat, operator!=, 200, 0x2D2B2069);

// @0x1406c8d90
float Unk_NpcStat::GetScaleStatRate() const
{
    return m_fScaleStatRate;
}
MS2_REPLACE_METHOD(0x1406C8D90, Unk_NpcStat, GetScaleStatRate, 19, 0x85525161);

// @0x1406c8db0
__int64 Unk_NpcStat::GetScaleBaseTap() const
{
    return m_nScaleBaseTap;
}
MS2_REPLACE_METHOD(0x1406C8DB0, Unk_NpcStat, GetScaleBaseTap, 18, 0xCF8A5890);

// @0x1406c8dd0
__int64 Unk_NpcStat::GetScaleBaseDef() const
{
    return m_nScaleBaseDef;
}
MS2_REPLACE_METHOD(0x1406C8DD0, Unk_NpcStat, GetScaleBaseDef, 18, 0x9A51AD78);

// @0x1406c8df0
float Unk_NpcStat::GetScaleBaseSpaRate() const
{
    return m_fScaleBaseSpaRate;
}
MS2_REPLACE_METHOD(0x1406C8DF0, Unk_NpcStat, GetScaleBaseSpaRate, 19, 0x0F765159);

// @0x1406c8e10
Unk_NpcSkill::Unk_NpcSkill()
{
}

// @0x1406c8e60
bool Unk_NpcSkill::operator!=(const Unk_NpcSkill& o) const
{
    if (m_aIds != o.m_aIds)
        return true;
    if (m_aLevels != o.m_aLevels)
        return true;
    if (m_aProbs != o.m_aProbs)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C8E60, Unk_NpcSkill, operator!=, 124, 0xCA3B4011);

// @0x1406c8ef0
bool Unk_NpcSkill::IsEmpty() const
{
    return m_aIds.empty();
}
MS2_REPLACE_METHOD(0x1406C8EF0, Unk_NpcSkill, IsEmpty, 27, 0x2A07118A);

// @0x1406c8f20
std::pair<unsigned, unsigned short> Unk_NpcSkill::GetSkill(size_t nIndex) const
{
    if (nIndex >= m_aIds.size())
        return std::pair<unsigned, unsigned short>();
    unsigned short nLevel = 1;
    if (nIndex < m_aLevels.size())
        nLevel = m_aLevels[nIndex];
    return std::pair<unsigned, unsigned short>(m_aIds[nIndex], nLevel);
}
MS2_REPLACE_METHOD(0x1406C8F20, Unk_NpcSkill, GetSkill, 166, 0x4AF7E218);

// @0x1406c8fd0
size_t Unk_NpcSkill::GetCount() const
{
    return m_aIds.size();
}
MS2_REPLACE_METHOD(0x1406C8FD0, Unk_NpcSkill, GetCount, 27, 0x78AA60A3);

// @0x1406c9000
Unk_NpcShape::Unk_NpcShape()
    : m_fWidth(0), m_fHeight(0), m_fDepth(0), m_nWidthOffset(0), m_nDepthOffset(0), m_nHeightOffset(0)
{
}

// @0x1406c9080
void Unk_NpcShape::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406C9080, Unk_NpcShape, WriteXml, 11, 0x02239C70);

// @0x1406c90a0
bool Unk_NpcShape::operator!=(const Unk_NpcShape& o) const
{
    if (m_strShape != o.m_strShape)
        return true;
    if (m_fWidth != o.m_fWidth)
        return true;
    if (m_fHeight != o.m_fHeight)
        return true;
    if (m_fDepth != o.m_fDepth)
        return true;
    if (m_nWidthOffset != o.m_nWidthOffset)
        return true;
    if (m_nDepthOffset != o.m_nDepthOffset)
        return true;
    if (m_nHeightOffset != o.m_nHeightOffset)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C90A0, Unk_NpcShape, operator!=, 194, 0xE683F9A6);

// @0x1406c9170
CNpcData::NodeCollision::NodeCollision() : m_vVolume(0.0f, 0.0f, 0.0f), m_vOffset(0.0f, 0.0f, 0.0f)
{
}

// @0x1406c9200
void CNpcData::NodeCollision::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406C9200, CNpcData::NodeCollision, WriteXml, 11, 0x02239C70);

// @0x1406c9220
bool CNpcData::NodeCollision::operator!=(const NodeCollision& o) const
{
    if (m_strTargetNode != o.m_strTargetNode)
        return true;
    if (m_vVolume.FUN_140552700(o.m_vVolume))
        return true;
    if (m_vOffset.FUN_140552700(o.m_vOffset))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C9220, CNpcData::NodeCollision, operator!=, 132, 0xC32A42A1);

// @0x1406c92b0
Unk_NpcCapsule::Unk_NpcCapsule() : m_fRadius(0), m_fHeight(0), m_nIgnore(0)
{
}

// @0x1406c92f0
void Unk_NpcCapsule::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406C92F0, Unk_NpcCapsule, WriteXml, 11, 0x02239C70);

// @0x1406c9310
bool Unk_NpcCapsule::operator!=(const Unk_NpcCapsule& o) const
{
    if (m_fRadius != o.m_fRadius)
        return true;
    if (m_fHeight != o.m_fHeight)
        return true;
    if (m_nIgnore != o.m_nIgnore)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C9310, Unk_NpcCapsule, operator!=, 83, 0x95407360);

// @0x1406c9370
Unk_NpcPush::Unk_NpcPush() : m_fBack(0), m_fUp(0), m_fKnockback(0)
{
}

// @0x1406c93b0
void Unk_NpcPush::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406C93B0, Unk_NpcPush, WriteXml, 11, 0x02239C70);

// @0x1406c93d0
bool Unk_NpcPush::operator!=(const Unk_NpcPush& o) const
{
    if (m_fBack != o.m_fBack)
        return true;
    if (m_fUp != o.m_fUp)
        return true;
    if (m_fKnockback != o.m_fKnockback)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C93D0, Unk_NpcPush, operator!=, 86, 0x1A6E711F);

// @0x1406c9430
Unk_NpcDead::Unk_NpcDead() : m_fTime(0), m_nRevival(0), m_nCount(0), m_fLifeTime(0), m_nExtendRoomTime(0)
{
}

// @0x1406c94b0
void Unk_NpcDead::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406C94B0, Unk_NpcDead, WriteXml, 11, 0x02239C70);

// @0x1406c94d0
bool Unk_NpcDead::operator!=(const Unk_NpcDead& o) const
{
    if (m_fTime != o.m_fTime)
        return true;
    if (!IsSameArray(m_aDefaultAction, o.m_aDefaultAction))
        return true;
    if (!IsSameArray(m_aUpAction, o.m_aUpAction))
        return true;
    if (m_nRevival != o.m_nRevival)
        return true;
    if (m_nCount != o.m_nCount)
        return true;
    if (m_fLifeTime != o.m_fLifeTime)
        return true;
    if (m_nExtendRoomTime != o.m_nExtendRoomTime)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C94D0, Unk_NpcDead, operator!=, 215, 0xE88C2CDA);

// @0x1406c95b0
CStringA Unk_NpcDead::GetRandomDefaultAction() const
{
    if (m_aDefaultAction.IsEmpty())
        return CStringA("Dead_A");
    return m_aDefaultAction[rand() % m_aDefaultAction.GetCount()];
}
MS2_REPLACE_METHOD(0x1406C95B0, Unk_NpcDead, GetRandomDefaultAction, 187, 0x535C337B);

// @0x1406c9680
CStringA Unk_NpcDead::GetRandomUpAction() const
{
    if (m_aUpAction.IsEmpty())
        return CStringA("");
    return m_aUpAction[rand() % m_aUpAction.GetCount()];
}
MS2_REPLACE_METHOD(0x1406C9680, Unk_NpcDead, GetRandomUpAction, 187, 0x4813A881);

// @0x1406c9750
Unk_NpcNormal::Unk_NpcNormal() : m_nMoveArea(0)
{
}

// @0x1406c9790
void Unk_NpcNormal::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406C9790, Unk_NpcNormal, WriteXml, 11, 0x02239C70);

// @0x1406c97b0
bool Unk_NpcNormal::operator!=(const Unk_NpcNormal& o) const
{
    if (!IsSameArray(m_aActions, o.m_aActions))
        return true;
    if (m_nMoveArea != o.m_nMoveArea)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C97B0, Unk_NpcNormal, operator!=, 72, 0xA260A079);

// @0x1406c9800
Unk_NpcDrop::Unk_NpcDrop() : m_fDropHeight(0), m_fDropDistanceBase(50.0f), m_nDropDistanceRandom(100), m_fFireVelocity(100.0f)
{
}

// @0x1406c98b0
void Unk_NpcDrop::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406C98B0, Unk_NpcDrop, WriteXml, 11, 0x02239C70);

// @0x1406c98d0
bool Unk_NpcDrop::operator!=(const Unk_NpcDrop& o) const
{
    if (m_fDropHeight != o.m_fDropHeight)
        return true;
    if (m_fDropDistanceBase != o.m_fDropDistanceBase)
        return true;
    if (m_nDropDistanceRandom != o.m_nDropDistanceRandom)
        return true;
    if (m_fFireVelocity != o.m_fFireVelocity)
        return true;
    if (!IsSameVector(m_aGlobalDropBoxId, o.m_aGlobalDropBoxId))
        return true;
    if (!IsSameVector(m_aGlobalDeadDropBoxId, o.m_aGlobalDeadDropBoxId))
        return true;
    if (!IsSameVector(m_aIndividualDropBoxId, o.m_aIndividualDropBoxId))
        return true;
    if (!IsSameVector(m_aGlobalHitDropBoxId, o.m_aGlobalHitDropBoxId))
        return true;
    if (!IsSameVector(m_aIndividualHitDropBoxId, o.m_aIndividualHitDropBoxId))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C98D0, Unk_NpcDrop, operator!=, 316, 0x6D427D59);

// @0x1406c9a20
void Unk_NpcDrop::GetGlobalDropBoxIds(std::set<unsigned>& setIds) const
{
    std::copy(m_aGlobalDropBoxId.begin(), m_aGlobalDropBoxId.end(), std::inserter(setIds, setIds.end()));
    std::copy(m_aGlobalDeadDropBoxId.begin(), m_aGlobalDeadDropBoxId.end(), std::inserter(setIds, setIds.end()));
    std::copy(m_aGlobalHitDropBoxId.begin(), m_aGlobalHitDropBoxId.end(), std::inserter(setIds, setIds.end()));
}
MS2_REPLACE_METHOD(0x1406C9A20, Unk_NpcDrop, GetGlobalDropBoxIds, 470, 0x368A125F);

// @0x1406c9c00
void Unk_NpcDrop::GetIndividualDropBoxIds(std::set<unsigned>& setIds) const
{
    std::copy(m_aIndividualDropBoxId.begin(), m_aIndividualDropBoxId.end(), std::inserter(setIds, setIds.end()));
    std::copy(m_aIndividualHitDropBoxId.begin(), m_aIndividualHitDropBoxId.end(), std::inserter(setIds, setIds.end()));
}
MS2_REPLACE_METHOD(0x1406C9C00, Unk_NpcDrop, GetIndividualDropBoxIds, 311, 0xC5CD9288);

// @0x1406c9d40
Unk_NpcCorpse::Unk_NpcCorpse() : m_nHitAble(0), m_fOffsetNametag(0), m_fAdded(0)
{
}

// @0x1406c9dc0
void Unk_NpcCorpse::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406C9DC0, Unk_NpcCorpse, WriteXml, 11, 0x02239C70);

// @0x1406c9de0
bool Unk_NpcCorpse::operator!=(const Unk_NpcCorpse& o) const
{
    if (m_nHitAble != o.m_nHitAble)
        return true;
    if (m_shape != o.m_shape)
        return true;
    if (!IsSameArray(m_aRotation, o.m_aRotation))
        return true;
    if (m_strCorpseEffect != o.m_strCorpseEffect)
        return true;
    if (m_fOffsetNametag != o.m_fOffsetNametag)
        return true;
    if (m_fAdded != o.m_fAdded)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C9DE0, Unk_NpcCorpse, operator!=, 205, 0xD6CD118D);

// @0x1406d4dc0
Unk_NpcEffect::Unk_NpcEffect()
{
}

// @0x1406c9ec0
void Unk_NpcEffect::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406C9EC0, Unk_NpcEffect, WriteXml, 11, 0x02239C70);

// @0x1406c9ee0
bool Unk_NpcEffect::operator!=(const Unk_NpcEffect& o) const
{
    if (!IsSameArray(m_aCodes, o.m_aCodes))
        return true;
    if (!IsSameArray(m_aLevels, o.m_aLevels))
        return true;
    if (!IsSameVector(m_aGroups, o.m_aGroups))
        return true;
    if (!IsSameArray(m_aRewardCodes, o.m_aRewardCodes))
        return true;
    if (!IsSameArray(m_aRewardLevels, o.m_aRewardLevels))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406C9EE0, Unk_NpcEffect, operator!=, 201, 0x5587FF37);

// @0x1406c9fb0
Unk_NpcInteract::Unk_NpcInteract() : m_nCastingTime(0), m_nCoolTime(0), m_bShowCastingBar(true)
{
}

// @0x1406ca010
void Unk_NpcInteract::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406CA010, Unk_NpcInteract, WriteXml, 11, 0x02239C70);

// @0x1406ca030
bool Unk_NpcInteract::operator!=(const Unk_NpcInteract& o) const
{
    if (m_nCastingTime != o.m_nCastingTime)
        return true;
    if (m_nCoolTime != o.m_nCoolTime)
        return true;
    if (m_strFunction != o.m_strFunction)
        return true;
    if (m_strCastingAnimation != o.m_strCastingAnimation)
        return true;
    if (m_bShowCastingBar != o.m_bShowCastingBar)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406CA030, Unk_NpcInteract, operator!=, 163, 0x1ACA6C39);

// @0x1406ca0e0
Unk_NpcLookAt::Unk_NpcLookAt() : m_n0(0), m_n1(0), m_b0(false), m_b1(false)
{
}

// @0x1406ca120
void Unk_NpcLookAt::WriteXml(Unk_140165cf0*) const
{
}
MS2_REPLACE_METHOD(0x1406CA120, Unk_NpcLookAt, WriteXml, 11, 0x02239C70);

// @0x1406ca140
bool Unk_NpcLookAt::operator!=(const Unk_NpcLookAt& o) const
{
    if (m_n0 != o.m_n0)
        return true;
    if (m_n1 != o.m_n1)
        return true;
    if (m_b0 != o.m_b0)
        return true;
    if (m_b1 != o.m_b1)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406CA140, Unk_NpcLookAt, operator!=, 107, 0xE0F5C242);

// @0x1406ca1c0
CNpcData::CNpcData()
    : m_nId(0), m_nFriendly(0), m_nLevel(1), m_nKind(0), m_nRace(0), m_nAttackGroup(0), m_nDefenseGroup(0), m_nShopId(0),
      m_bMinimap(true), m_nDefenceMaterial(0), m_nHitImmune(0), m_nAbnormalImmune(0), m_nClass(1),
      m_bRotationDisabled(false), m_bCarePathToEnemy(false), m_bTalkAni(true), m_bBossNotifyDefault(false),
      m_bBossNotify(false), m_bInstallNpc(false), m_fDamagedColorScale(2.0f), m_fDamagedVibrateDuration(0),
      m_fDamagedVibrateAmp(0), m_fCheckCameraDistance(0), m_fExtraCameraDistance(0), m_fBossSoundDistance(2000.0f),
      m_fBossSoundEndDistance(3000.0f), m_nEmotionId(0), m_bLookAtMyPCWhenTalking(true), m_bUseTalkMotion(true),
      m_nCustomExp(-1), m_fShadowScale(0), m_fRotationSpeed(0), m_fWalkSpeed(0), m_fRunSpeed(0)
{
}

// @0x1406ca570
CNpcData::~CNpcData()
{
}

// @0x1406ca6b0
bool CNpcData::operator!=(const CNpcData& o) const
{
    if (m_model != o.m_model)
        return true;
    if (m_strStringId != o.m_strStringId)
        return true;
    if (m_nFriendly != o.m_nFriendly)
        return true;
    if (m_nAttackGroup != o.m_nAttackGroup)
        return true;
    if (m_nDefenseGroup != o.m_nDefenseGroup)
        return true;
    if (m_nKind != o.m_nKind)
        return true;
    if (m_nShopId != o.m_nShopId)
        return true;
    if (m_bMinimap != o.m_bMinimap)
        return true;
    if (m_nDefenceMaterial != o.m_nDefenceMaterial)
        return true;
    if (m_nHitImmune != o.m_nHitImmune)
        return true;
    if (m_nAbnormalImmune != o.m_nAbnormalImmune)
        return true;
    if (m_nLevel != o.m_nLevel)
        return true;
    if (m_nClass != o.m_nClass)
        return true;
    if (m_strRankIcon != o.m_strRankIcon)
        return true;
    if (m_bRotationDisabled != o.m_bRotationDisabled)
        return true;
    if (m_bCarePathToEnemy != o.m_bCarePathToEnemy)
        return true;
    if (m_bBossNotify != o.m_bBossNotify)
        return true;
    if (m_nEmotionId != o.m_nEmotionId)
        return true;
    if (m_bInstallNpc != o.m_bInstallNpc)
        return true;
    if (m_strPortrait != o.m_strPortrait)
        return true;
    if (m_bTalkAni != o.m_bTalkAni)
        return true;
    if (m_fDamagedColorScale != o.m_fDamagedColorScale)
        return true;
    if (m_fDamagedVibrateDuration != o.m_fDamagedVibrateDuration)
        return true;
    if (m_fDamagedVibrateAmp != o.m_fDamagedVibrateAmp)
        return true;
    if (m_fCheckCameraDistance != o.m_fCheckCameraDistance)
        return true;
    if (m_fExtraCameraDistance != o.m_fExtraCameraDistance)
        return true;
    if (m_fBossSoundDistance != o.m_fBossSoundDistance)
        return true;
    if (m_fBossSoundEndDistance != o.m_fBossSoundEndDistance)
        return true;
    if (m_bLookAtMyPCWhenTalking != o.m_bLookAtMyPCWhenTalking)
        return true;
    if (m_bUseTalkMotion != o.m_bUseTalkMotion)
        return true;
    if (m_fShadowScale != o.m_fShadowScale)
        return true;
    if (m_fRotationSpeed != o.m_fRotationSpeed)
        return true;
    if (m_fWalkSpeed != o.m_fWalkSpeed)
        return true;
    if (m_fRunSpeed != o.m_fRunSpeed)
        return true;
    if (m_stat != o.m_stat)
        return true;
    if (m_distance != o.m_distance)
        return true;
    if (m_skill != o.m_skill)
        return true;
    if (m_effect != o.m_effect)
        return true;
    if (m_interact != o.m_interact)
        return true;
    if (m_lookAt != o.m_lookAt)
        return true;
    if (m_collision != o.m_collision)
        return true;
    if (!IsSameArray(m_aNodeCollision, o.m_aNodeCollision))
        return true;
    if (!IsSameArray(m_aNodeServerCollision, o.m_aNodeServerCollision))
        return true;
    if (m_corpse != o.m_corpse)
        return true;
    if (m_capsule != o.m_capsule)
        return true;
    if (m_dead != o.m_dead)
        return true;
    if (m_push != o.m_push)
        return true;
    if (m_nCustomExp != o.m_nCustomExp)
        return true;
    if (m_normal != o.m_normal)
        return true;
    if (m_drop != o.m_drop)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406CA6B0, CNpcData, operator!=, 1820, 0xEB2C3925);

// @0x1406cade0
bool CNpcData::Load(Unk_140165cf0* pRoot)
{
    FUN_140873220(pRoot, "id", (unsigned&)m_nId);
    if (m_nId == 0)
        return false;
    Unk_140165cf0* pElem = FUN_14028f8d0(pRoot);
    if (!pElem)
        return false;
    return LoadXml(pElem);
}
MS2_REPLACE_METHOD(0x1406CADE0, CNpcData, Load, 111, 0x3008DAC9);

// @0x1406cce20
int CNpcData::GetId() const
{
    return m_nId;
}
MS2_REPLACE_METHOD(0x1406CCE20, CNpcData, GetId, 14, 0x72E52537);

// @0x1406cce40
CStringA CNpcData::GetStringId() const
{
    return m_strStringId;
}
MS2_REPLACE_METHOD(0x1406CCE40, CNpcData, GetStringId, 66, 0x931AA26A);

// @0x1406cce90
bool CNpcData::IsStationary() const
{
    return (FUN_14028d470(m_fRunSpeed, 0) && FUN_14028d470(m_fWalkSpeed, 0)) ? 1 : 0;
}
MS2_REPLACE_METHOD(0x1406CCE90, CNpcData, IsStationary, 93, 0x31FC3BCA);

// @0x1406ccf00
bool CNpcData::IsMinimap() const
{
    return m_bMinimap;
}
MS2_REPLACE_METHOD(0x1406CCF00, CNpcData, IsMinimap, 15, 0x43A40A0D);

// @0x1406ccf20
int CNpcData::GetCorpseHitAble() const
{
    return m_corpse.m_nHitAble;
}
MS2_REPLACE_METHOD(0x1406CCF20, CNpcData, GetCorpseHitAble, 17, 0x9CF347CF);

// @0x1406ccf40
bool CNpcData::IsBoss() const
{
    if (GetFriendly() == 0 && m_nClass >= 3)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406CCF40, CNpcData, IsBoss, 45, 0x872717FB);

// @0x1406ccf80
bool CNpcData::IsShopKind() const
{
    if (m_nKind == 1 || (m_nKind > 10 && m_nKind < 30))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406CCF80, CNpcData, IsShopKind, 45, 0x39A5BA10);

// @0x1406ccfc0
int CNpcData::GetFriendly() const
{
    return m_nFriendly;
}
MS2_REPLACE_METHOD(0x1406CCFC0, CNpcData, GetFriendly, 14, 0x8AEE455B);

// @0x1406ccfe0
int CNpcData::GetAttackGroup() const
{
    return m_nAttackGroup;
}
MS2_REPLACE_METHOD(0x1406CCFE0, CNpcData, GetAttackGroup, 14, 0x9A8B24F3);

// @0x1406cd000
int CNpcData::GetDefenseGroup() const
{
    return m_nDefenseGroup;
}
MS2_REPLACE_METHOD(0x1406CD000, CNpcData, GetDefenseGroup, 14, 0xB2976B17);

// @0x1406cd020
int CNpcData::GetKind() const
{
    return m_nKind;
}
MS2_REPLACE_METHOD(0x1406CD020, CNpcData, GetKind, 14, 0x6A78E4AB);

// @0x1406cd040
int CNpcData::GetClass() const
{
    return m_nClass;
}
MS2_REPLACE_METHOD(0x1406CD040, CNpcData, GetClass, 14, 0xCA01277B);

// @0x1406cd060
unsigned short CNpcData::GetLevel() const
{
    return m_nLevel;
}
MS2_REPLACE_METHOD(0x1406CD060, CNpcData, GetLevel, 15, 0xAA111D44);

// @0x1406cd080
CStringA CNpcData::GetEmptyString(int) const
{
    return CStringA("");
}
MS2_REPLACE_METHOD(0x1406CD080, CNpcData, GetEmptyString, 66, 0x980CABC8);

// @0x1406cd0d0
unsigned CNpcData::GetShopId() const
{
    return m_nShopId;
}
MS2_REPLACE_METHOD(0x1406CD0D0, CNpcData, GetShopId, 14, 0xCAA08B3B);

// @0x1406cd0f0
int CNpcData::GetNpcType() const
{
    if (IsShopKind())
        return 1;
    if (m_nKind >= 30 && m_nKind < 40)
        return 4;
    return m_nKind;
}
MS2_REPLACE_METHOD(0x1406CD0F0, CNpcData, GetNpcType, 75, 0xB3C18CA0);

// @0x1406cd150
int CNpcData::GetNpcTypeGroup() const
{
    switch (GetNpcType())
    {
    case 0x50:
        return 11;
    case 0x51:
        return 13;
    case 0x52:
    case 0x55:
        return 14;
    case 0x54:
        return 15;
    case 4:
        return 10;
    case 0x1f5:
        return 16;
    case 0x57:
        return 2;
    default:
        return 3;
    }
}
MS2_REPLACE_METHOD(0x1406CD150, CNpcData, GetNpcTypeGroup, 161, 0x8908A403);

// @0x1406cd200
bool CNpcData::HasPropertyTag(int nTag) const
{
    if (nTag >= 31)
        return false;
    return m_propertyTags.test(nTag);
}
MS2_REPLACE_METHOD(0x1406CD200, CNpcData, HasPropertyTag, 51, 0x9A077415);

// @0x1406cd240
bool CNpcData::IsRace(int nRace) const
{
    return m_nRace == nRace;
}
MS2_REPLACE_METHOD(0x1406CD240, CNpcData, IsRace, 52, 0x52B27C1F);

// @0x1406cd280
bool CNpcData::HasEventTag(int nTag) const
{
    if (nTag >= 6)
        return false;
    return m_eventTags.test(nTag);
}
MS2_REPLACE_METHOD(0x1406CD280, CNpcData, HasEventTag, 51, 0xDF75FC8C);

// @0x1406cd2c0
bool CNpcData::HasSkill() const
{
    return m_skill.m_aIds.size() > 0;
}
MS2_REPLACE_METHOD(0x1406CD2C0, CNpcData, HasSkill, 61, 0x6BCE268B);

// @0x1406cd310
int CNpcData::GetRace() const
{
    return m_nRace;
}
MS2_REPLACE_METHOD(0x1406CD310, CNpcData, GetRace, 14, 0x828204CF);

// --- Table/NpcRegionSpawnData.xml and the NpcData xml cache ---------------------------------------------------------

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_1402804e0(void*, unsigned __int64, unsigned __int64, int, const wchar_t*);
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
int FUN_1408731e0(Unk_140165cf0*, const char*, int&);
int FUN_1408733e0(Unk_140165cf0*, const char*, CString&);
int FUN_140873420(Unk_140165cf0*, const char*, CStringW&);
CStringW FUN_1401bf530(Unk_140165cf0* pElem, const char* pszName, CStringW strDefault);
void FUN_14025a680(CStringW& src, ATL::CAtlArray<CStringW>& out, const wchar_t* pszSep);
bool FUN_14025cd60(const CStringW&, const CStringW&);
void FUN_1403992a0(CString pattern, CString directory, std::vector<CString>& output, CString exclude, bool localOnly);
void* FUN_140166410();
bool FUN_14036d4b0(void*, const CStringW&);
struct Unk_NdFeature { CString FUN_14036d8e0(); };
bool FUN_1401647e0(const CString&, const CString&);
float FUN_14028d2e0();
CStringW FUN_140298ea0(CStringW strKey);
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);

// The weight table of the black market's rarity roll, reused for the region spawn weights (0x143aac4c8).
class Unk_NpcWeightMgr { public: int FUN_1406762d0(int nMain, int nSub, int nRare, int nDiff); };
Unk_NpcWeightMgr* FUN_1401c0db0();

class Unk_NpcTableCli { public: MS2Ptr<CNpcData> FUN_140a7cab0(int nNpcId); };
class Unk_SingletonObj;
extern Unk_SingletonObj* DAT_143ab06f0;                         // the exe's NpcDataTableCli singleton (0x1406d6e90 returns it)

// How often a query's main / sub tags hit one region spawn row.
struct Unk_RegionTagHit
{
    int m_nMain;
    int m_nSub;
};

// @0x1406c8680
CNpcRegionSpawnData::CNpcRegionSpawnData()
    : m_nNpcId(0), m_nMaxSpawnCount(0), m_nGroupSpawnCount(0), m_nRareDegree(0), m_nDifficulty(0)
{
}

// MS2-PIN: ??0CRegionSpawnProb@@QEAA@XZ 0x1406d4fe0
// MS2-FUNCTIONAL: the exe stores m_pSpawn with a different Unk_BmPtr assignment sequence
CRegionSpawnProb::CRegionSpawnProb()
{
    m_pSpawn = 0;
    m_fRate = 0.0f;
    m_fWeight = 0.0f;
}

// @0x1406d5060
CRegionSpawnResult::CRegionSpawnResult()
{
    m_nMaxDifficulty = 0;
    m_nMinDifficulty = 0;
    m_nUnused = 0;
}

// @0x1406d5650
CRegionSpawnResult::~CRegionSpawnResult()
{
    m_aProb.RemoveAll();
}

// @0x1406c8730
// MS2-FUNCTIONAL: the exe frame is 0x10 larger (one more MS2Ptr temp on the return paths)
MS2Ptr<CRegionSpawnProb> CRegionSpawnResult::Pick() const
{
    if (m_aProb.IsEmpty())
        return MS2Ptr<CRegionSpawnProb>(0);
    if (m_aProb.GetCount() == 1)
        return m_aProb[0];
    float fRoll = FUN_14028d2e0();
    float fSum = 0.0f;
    for (int i = 0; i < (int)m_aProb.GetCount(); i++)
    {
        if (fSum <= fRoll && fRoll <= fSum + m_aProb[i]->m_fRate)
            return m_aProb[i];
        fSum += m_aProb[i]->m_fRate;
    }
    return m_aProb[m_aProb.GetCount() - 1];
}

// @0x1406cd330
// MS2-FUNCTIONAL: the exe moves the lookup result through a second MS2Ptr temp (frame 0x10 larger)
Unk_NpcTableCli* FUN_1406d6e90();
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId)
{
    if (nNpcId == 0)
        return MS2Ptr<CNpcData>(0);
    MS2Ptr<CNpcData> pData = FUN_1406d6e90()->FUN_140a7cab0(nNpcId);
    return pData;
}

// @0x1406d6e90
Unk_NpcTableCli* FUN_1406d6e90()
{
    return reinterpret_cast<Unk_NpcTableCli*>(DAT_143ab06f0);
}
MS2_REPLACE(0x1406D6E90, FUN_1406d6e90, 8, 0x5738B5AB);

// @0x1406cd420
// MS2-FUNCTIONAL: string dictionary lookups: the exe keeps the CStringW temps in a different frame order
CStringW FUN_1406cd420(int nNpcType)
{
    if (nNpcType == 2)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_bank"));
    if (nNpcType >= 11 && nNpcType <= 29)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_shop"));
    if (nNpcType >= 31 && nNpcType <= 39)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_beautyshop"));
    if (nNpcType == 0x50)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_job"));
    if (nNpcType == 0x51)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_doctor"));
    if (nNpcType == 0x52)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_transfer"));
    if (nNpcType == 0x57)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_enchant"));
    return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_normal"));
}

// @0x1406cd750
CNpcDataTable::CNpcDataTable()
{
    LoadNpcCache();
    LoadRegionSpawn();
}

// @0x1406cd840
// MS2-FUNCTIONAL: frame/temp order of the MS2Ptr and CString temps differs; callee ICF copies resolve to other VAs
MS2Ptr<CRegionSpawnResult> CNpcDataTable::FindSpawnResult(CStringW strTags, int nMinDifficulty, int nMaxDifficulty)
{
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        for (int i = 0; i < (int)m_aResult.GetCount(); i++)
        {
            MS2Ptr<CRegionSpawnResult> pResult = m_aResult[i];
            if (FUN_14025cd60(pResult->m_strTag, strTags) && pResult->m_nMaxDifficulty == nMaxDifficulty &&
                pResult->m_nMinDifficulty == nMinDifficulty)
                return pResult;
        }
    }

    ATL::CAtlArray<CStringW> aTags;
    FUN_14025a680(strTags, aTags, L",");
    for (int i = 0; i < (int)aTags.GetCount(); i++)
        aTags[i].Trim();

    ATL::CRBMap<unsigned, Unk_RegionTagHit> mapHit(10);
    for (int nGroup = 0; nGroup < 2; nGroup++)
    {
        for (int j = 0; j < (int)aTags.GetCount(); j++)
        {
            Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > pIds;
            {
                Unk_CriticalSectionLock lock(m_lock, 1);
                m_mapTag[nGroup].Lookup(aTags[j], pIds);
            }
            if (pIds.get() != 0)
            {
                for (int k = 0; k < (int)pIds->GetCount(); k++)
                {
                    unsigned nNpcId = (*pIds)[k];
                    Unk_BmPtr<CNpcRegionSpawnData> pData = GetRegionSpawnData(nNpcId);
                    if (!(pData == 0))
                    {
                        if (nMaxDifficulty < pData->m_nDifficulty)
                            continue;
                        if (pData->m_nDifficulty < nMinDifficulty)
                            continue;
                        ATL::CRBMap<unsigned, Unk_RegionTagHit>::CPair* pHit = mapHit.Lookup(nNpcId);
                        if (pHit == 0)
                        {
                            Unk_RegionTagHit hit;
                            hit.m_nMain = nGroup == 0;
                            hit.m_nSub = nGroup != 0;
                            mapHit.SetAt(nNpcId, hit);
                        }
                        else if (nGroup == 0)
                            pHit->m_value.m_nMain++;
                        else
                            pHit->m_value.m_nSub++;
                    }
                }
            }
        }
    }

    MS2Ptr<CRegionSpawnResult> pResult(new CRegionSpawnResult);
    pResult->m_nMaxDifficulty = nMaxDifficulty;
    pResult->m_nMinDifficulty = nMinDifficulty;
    pResult->m_strTag = strTags;
    float fTotal = 0.0f;
    for (POSITION pos = mapHit.GetHeadPosition(); pos != 0; mapHit.GetNext(pos))
    {
        unsigned nNpcId = mapHit.GetKeyAt(pos);
        Unk_RegionTagHit hit = mapHit.GetValueAt(pos);
        Unk_BmPtr<CNpcRegionSpawnData> pData = GetRegionSpawnData(nNpcId);
        if (!(pData == 0))
        {
            if (hit.m_nMain == 0 && hit.m_nSub == 0)
                continue;
            if (hit.m_nMain == (int)pData->m_aTags[0].GetCount())
            {
                MS2Ptr<CRegionSpawnProb> pProb(new CRegionSpawnProb);
                pProb->m_pSpawn = pData;
                int nDiff = nMaxDifficulty - pData->m_nDifficulty;
                pProb->m_fWeight = (float)FUN_1401c0db0()->FUN_1406762d0(hit.m_nMain, hit.m_nSub, pData->m_nRareDegree, nDiff);
                fTotal += pProb->m_fWeight;
                pResult->m_aProb.Add(pProb);
            }
        }
    }
    for (int i = 0; i < (int)pResult->m_aProb.GetCount(); i++)
        pResult->m_aProb[i]->m_fRate = pResult->m_aProb[i]->m_fWeight / fTotal;
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        m_aResult.Add(pResult);
    }
    return pResult;
}

// @0x1406ce1d0
Unk_BmPtr<CNpcRegionSpawnData> CNpcDataTable::GetRegionSpawnData(int nNpcId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    Unk_BmPtr<CNpcRegionSpawnData> pData(nullptr);
    m_mapSpawn.Lookup(nNpcId, pData);
    return pData;
}
MS2_REPLACE_METHOD(0x1406CE1D0, CNpcDataTable, GetRegionSpawnData, 157, 0x462B29AE);

// @0x1406ce280
// MS2-FUNCTIONAL: MS2Ptr temp placement; the ICF copies of the CRBMap/Unk_BmBoxPtr glue resolve to other VAs
void CNpcDataTable::IndexRegionSpawn(Unk_BmPtr<CNpcRegionSpawnData> pData)
{
    if (!(pData == 0))
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        for (int nGroup = 0; nGroup < 2; nGroup++)
        {
            for (int i = 0; i < (int)pData->m_aTags[nGroup].GetCount(); i++)
            {
                CStringW strTag = pData->m_aTags[nGroup][i];
                Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > pIds;
                if (!m_mapTag[nGroup].Lookup(strTag, pIds))
                {
                    pIds = Unk_BmNewTag(0);
                    m_mapTag[nGroup].SetAt(strTag, pIds);
                }
                pIds->Add(pData->m_nNpcId);
            }
        }
    }
}

// @0x1406ce4a0
// MS2-FUNCTIONAL: frame order of the CCacheData temps; map ICF copies resolve to other VAs
void CNpcDataTable::LoadNpcCache()
{
    std::vector<CString> aFiles;
    FUN_140166420();
    FUN_1403992a0(CString(".xml"), CString("./Data/Xml/NpcData/"), aFiles, CString(""), false);
    for (std::vector<CString>::iterator it = aFiles.begin(); it != aFiles.end(); ++it)
    {
        int nNpcId = GetIdFromPath(*it);
        m_mapLoaded[nNpcId] = false;
        CCacheData* pCache = new CCacheData(CString(*it));
        m_mapCache[nNpcId].AssignRaw(pCache);
    }
}

// @0x1406ce6d0
// MS2-FUNCTIONAL: frame order of the xml string temps; ICF copies of the Unk_BmPtr glue resolve to other VAs
void CNpcDataTable::LoadRegionSpawn()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("NpcRegionSpawnData.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        FUN_1402804e0(FUN_140166440(), 0, 0, 0xc, L"NpcDataTable.cpp:Init : File not found NpcRegionSpawnData.xml");
        return;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("NpcRegionSpawnData"); pNode != 0;
         pNode = pNode->FUN_140168650("NpcRegionSpawnData"))
    {
        CStringW strFeature;
        CString strLocale;
        FUN_140873420(pNode, "feature", strFeature);
        FUN_1408733e0(pNode, "locale", strLocale);
        bool bSkip = !strLocale.IsEmpty() && FUN_1401647e0(strLocale, reinterpret_cast<Unk_NdFeature*>(FUN_140166410())->FUN_14036d8e0());
        if (bSkip)
            continue;
        if (!FUN_14036d4b0(FUN_140166410(), strFeature))
            continue;
        Unk_BmPtr<CNpcRegionSpawnData> pData(Unk_BmNewTag(0));
        pData->m_nNpcId = atoi(FUN_14086f4b0(pNode, "npcID"));
        CStringW strMain = FUN_1401bf530(pNode, "mainTags", CStringW(L""));
        FUN_14025a680(strMain, pData->m_aTags[0], L",");
        CStringW strSub = FUN_1401bf530(pNode, "subTags", CStringW(L""));
        FUN_14025a680(strSub, pData->m_aTags[1], L",");
        for (int nGroup = 0; nGroup < 2; nGroup++)
            for (int i = 0; i < (int)pData->m_aTags[nGroup].GetCount(); i++)
                pData->m_aTags[nGroup][i].Trim();
        FUN_1408731e0(pNode, "maxSpawnCount", pData->m_nMaxSpawnCount);
        FUN_1408731e0(pNode, "groupSpawnCount", pData->m_nGroupSpawnCount);
        FUN_1408731e0(pNode, "rareDegree", pData->m_nRareDegree);
        FUN_1408731e0(pNode, "difficulty", pData->m_nDifficulty);
        {
            Unk_CriticalSectionLock lock(m_lock, 1);
            m_mapSpawn.SetAt(pData->m_nNpcId, pData);
        }
        IndexRegionSpawn(pData);
    }
}

// @0x1406ced30
int CNpcDataTable::GetIdFromPath(const CStringA& strPath)
{
    char szName[256];
    _splitpath(strPath, 0, 0, szName, 0);
    return atoi(szName);
}
MS2_REPLACE_METHOD(0x1406CED30, CNpcDataTable, GetIdFromPath, 112, 0x47CCD196);

// @0x1406cedb0
// MS2-FUNCTIONAL: frame/temp order of the lock and MS2Ptr; map<unsigned,...> find ICF copies resolve to other VAs
bool CNpcDataTable::NeedsLoad(int nNpcId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<unsigned, MS2Ptr<CCacheData> >::iterator it = m_mapCache.find(nNpcId);
    if (it == m_mapCache.end())
        return false;
    MS2Ptr<CCacheData> pCache = it->second;
    if (pCache == 0)
        return false;
    if (FUN_1401d1320(pCache.get()) != 0)
        return true;
    std::map<unsigned long, bool>::iterator itLoaded = m_mapLoaded.find(nNpcId);
    if (itLoaded == m_mapLoaded.end())
        return false;
    return itLoaded->second != true;
}

// @0x1406cefb0
static int Unk_ParsePropertyTag(const CStringA& strTag)
{
    if (strTag.IsEmpty())
        return 0;
    if (strTag.CompareNoCase("big_hp_bar") == 0)
        return 1;
    if (strTag.CompareNoCase("always_display_hp_bar") == 0)
        return 2;
    if (strTag.CompareNoCase("hide_hpbar_level") == 0)
        return 3;
    if (strTag.CompareNoCase("always_display_upper_hp_bar") == 0)
        return 4;
    if (strTag.CompareNoCase("damaged_hp_upper_hp_bar") == 0)
        return 5;
    if (strTag.CompareNoCase("ignore_pc") == 0)
        return 6;
    if (strTag.CompareNoCase("ai_wander_freely") == 0)
        return 7;
    if (strTag.CompareNoCase("dummy_npc") == 0)
        return 8;
    if (strTag.CompareNoCase("no_regen_hp") == 0)
        return 9;
    if (strTag.CompareNoCase("keep_battle") == 0)
        return 10;
    if (strTag.CompareNoCase("no_die") == 0)
        return 11;
    if (strTag.CompareNoCase("always_full_hp") == 0)
        return 12;
    if (strTag.CompareNoCase("event_icon") == 0)
        return 13;
    if (strTag.CompareNoCase("atp_formula_01") == 0)
        return 14;
    if (strTag.CompareNoCase("cube_shape_size") == 0)
        return 15;
    if (strTag.CompareNoCase("battle_on_spawn") == 0)
        return 16;
    if (strTag.CompareNoCase("fixed_big_monster") == 0)
        return 17;
    if (strTag.CompareNoCase("no_revise_stat") == 0)
        return 18;
    if (strTag.CompareNoCase("terrain_physx") == 0)
        return 19;
    if (strTag.CompareNoCase("immune_debuff") == 0)
        return 20;
    if (strTag.CompareNoCase("record_damage") == 0)
        return 21;
    if (strTag.CompareNoCase("no_send_proxy") == 0)
        return 22;
    if (strTag.CompareNoCase("ignore_check_target_by_additional") == 0)
        return 23;
    if (strTag.CompareNoCase("rarely_move_on_wander") == 0)
        return 24;
    if (strTag.CompareNoCase("back_to_on_battle_end") == 0)
        return 25;
    if (strTag.CompareNoCase("ignore_talk_distance") == 0)
        return 26;
    if (strTag.CompareNoCase("no_update_target_on_patrol") == 0)
        return 27;
    if (strTag.CompareNoCase("no_event_drop") == 0)
        return 28;
    if (strTag.CompareNoCase("collision_position") == 0)
        return 29;
    if (strTag.CompareNoCase("can_die_by_npc") == 0)
        return 30;
    MS2_ASSERT_AT(0x3a, 0);
    return 0;
}
MS2_REPLACE(0x1406CEFB0, Unk_ParsePropertyTag, 1023, 0x6D7FA8CF);

// --- CNpcData::LoadXml ------------------------------------------------------------------------------------------------
bool FUN_1403d8350(Unk_140165cf0* pElem, const char* pszName, int& nOut);               // npc class reader
unsigned FUN_14021c7c0(const CString& str);                                             // the id of a string key
int FUN_14021bc30(const CStringA& strName);                                             // event tag by name
const CString& FUN_14082efb0(int nStat);                                                // xml name of the nStat-th stat
bool FUN_14036d570(void* pOptions, int nFeature);                                       // feature id check
void FUN_1406a6d70(void* pLog, int a, int b, int c, const wchar_t* pszFormat, const int& nArg);
void FUN_140177a80(void* pLog, int a, int b, const wchar_t* pszFormat, const int& nArg);
void FUN_140177e10(const CStringA& str, ATL::CAtlArray<unsigned>& rOut, const char* pszSep);
void FUN_140177db0(const CString& str, ATL::CAtlArray<unsigned short>& out, const char* szDelimiter);
void FUN_1402c8940(const CString& str, std::vector<CString>& vec, const char* pszDelim);
void FUN_140178270(const CStringA& str, std::vector<int>& rOut, const char* pszSep);
int FUN_1401788f0(Unk_140165cf0*, const char*, ATL::CAtlArray<CStringA>&);
int FUN_140178570(Unk_140165cf0*, const char*, ATL::CAtlArray<int>&);
int FUN_140178770(Unk_140165cf0*, const char*, std::vector<unsigned>&);
int FUN_1403759c0(Unk_140165cf0*, const char*, std::vector<short>&);
int FUN_140874670(Unk_140165cf0* pElem, const char* pszName, Unk_StreamPoint& ptOut);
CString FUN_14016a5c0(const char* psz, int n);
void FUN_14015f050(const CString& str, ATL::CAtlArray<CString>& arr, const char* pszDelim);

// The boss notify table (the pc bang style handle table): a handle lookup by (mode, npc id), then a per-node test.
struct Unk_BossNotifyHandle { ~Unk_BossNotifyHandle(); unsigned long long m_a, m_b; };    // dtor 0x1403b87a0
struct Unk_BossNotifyNode { char FUN_1403b8910(int n); };
class Unk_BossNotifyMgr
{
public:
    Unk_BossNotifyNode* FUN_1403b7c40(Unk_BossNotifyHandle* pOut, int nMode, int nNpcId);
    void FUN_1403b7d30(int nNpcId, int nClass);
};
Unk_BossNotifyMgr* FUN_140541580();

// @0x1406cfaa0
static int FUN_1406cfaa0(Unk_140165cf0* pElem, const char* pszName, std::vector<CString>& rOut)
{
    CStringA str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
    if (nRet == 0)
        FUN_1402c8940(str, rOut, ",");
    return nRet;
}
MS2_REPLACE(0x1406CFAA0, FUN_1406cfaa0, 121, 0x2DA8BB28);

// @0x1406cfb20
// MS2-FUNCTIONAL: the exe inlines the CStringA default ctor (stringmgr assert) and duplicates the dtor on both paths
static int FUN_1406cfb20(Unk_140165cf0* pElem, const char* pszName, int& nOut)
{
    CStringA str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
    if (nRet == 0)
        nOut = FUN_14021c7c0(str);
    return nRet;
}

// @0x1406cae60
// MS2-FUNCTIONAL: 8 KB loader; the xml reads are in the exe's order, the frame/temporary layout is not matched
bool CNpcData::LoadXml(Unk_140165cf0* pElem)
{
    FUN_1408733e0(pElem, "stringID", m_strStringId);
    FUN_1408731e0(pElem, "friendly", m_nFriendly);
    FUN_1408731e0(pElem, "npcAttackGroup", m_nAttackGroup);
    FUN_1408731e0(pElem, "npcDefenseGroup", m_nDefenseGroup);
    FUN_1408731e0(pElem, "kind", m_nKind);
    FUN_140873220(pElem, "shopId", m_nShopId);
    FUN_1408730a0(pElem, "minimap", m_bMinimap);
    FUN_1408731e0(pElem, "defenceMaterial", m_nDefenceMaterial);
    FUN_1408731e0(pElem, "hitImmune", m_nHitImmune);
    FUN_1408731e0(pElem, "abnormalImmune", m_nAbnormalImmune);
    FUN_1408731a0(pElem, "level", m_nLevel);
    FUN_1403d8350(pElem, "class", m_nClass);
    FUN_1408730a0(pElem, "rotationDisabled", m_bRotationDisabled);
    FUN_1408730a0(pElem, "carePathToEnemy", m_bCarePathToEnemy);
    FUN_1408733e0(pElem, "rankIcon", m_strRankIcon);
    FUN_1408730a0(pElem, "talkAni", m_bTalkAni);
    FUN_140873360(pElem, "damagedColorScale", m_fDamagedColorScale);
    FUN_140873360(pElem, "damagedVibrateDuration", m_fDamagedVibrateDuration);
    FUN_140873360(pElem, "damagedVibrateAmp", m_fDamagedVibrateAmp);
    FUN_1408733e0(pElem, "portrait", m_strPortrait);
    FUN_140873360(pElem, "checkCameraDistance", m_fCheckCameraDistance);
    FUN_140873360(pElem, "extraCameraDistance", m_fExtraCameraDistance);
    FUN_140873360(pElem, "bossSoundDistance", m_fBossSoundDistance);
    FUN_140873360(pElem, "bossSoundEndDistance", m_fBossSoundEndDistance);
    if (FUN_14036d570(FUN_140166410(), 0x2f))
    {
        if (FUN_140541580() == 0)
            m_bBossNotifyDefault = 0;
        else if (GetFriendly() < 1)
        {
            Unk_BossNotifyHandle handle;
            Unk_BossNotifyNode* pNode = FUN_140541580()->FUN_1403b7c40(&handle, 2, GetId());
            m_bBossNotifyDefault = pNode->FUN_1403b8910(0);
            FUN_140541580()->FUN_1403b7d30(GetId(), m_nClass);
        }
        else
        {
            Unk_BossNotifyHandle handle;
            Unk_BossNotifyNode* pNode = FUN_140541580()->FUN_1403b7c40(&handle, 1, GetId());
            m_bBossNotifyDefault = pNode->FUN_1403b8910(0);
        }
    }
    FUN_1408730a0(pElem, "bossNotify", m_bBossNotify);
    FUN_140873220(pElem, "emotionID", m_nEmotionId);
    FUN_1408730a0(pElem, "installNpc", m_bInstallNpc);
    FUN_1406cfb20(pElem, "raceString", m_nRace);
    FUN_1408732e0(pElem, "customExp", m_nCustomExp);
    FUN_1408730a0(pElem, "lookAtMyPCWhenTalking", m_bLookAtMyPCWhenTalking);
    FUN_1408730a0(pElem, "useTalkMotion", m_bUseTalkMotion);

    std::vector<CString> propertyTags;
    FUN_1406cfaa0(pElem, "propertyTags", propertyTags);
    MS2_FOR_EACH(CStringA strTag, propertyTags)
    {
        int nTag = Unk_ParsePropertyTag(strTag);
        if (nTag != 0)
            m_propertyTags.set(nTag, true);
    }
    std::vector<CString> eventTags;
    FUN_1406cfaa0(pElem, "eventTags", eventTags);
    MS2_FOR_EACH(CStringA strTag, eventTags)
    {
        int nTag = FUN_14021bc30(strTag);
        if (nTag != 0)
            m_eventTags.set(nTag, true);
    }

    Unk_140165cf0* pChild = pElem->FUN_140165cf0("model");
    if (pChild)
    {
        FUN_1408733e0(pChild, "kfm", m_model.m_strKfm);
        FUN_140873360(pChild, "scale", m_model.m_fScale);
        FUN_140873360(pChild, "anispeed", m_model.m_fAniSpeed);
        FUN_1408731e0(pChild, "spawnAlphaAnimation", m_model.m_nSpawnAlphaAnimation);
        FUN_140874670(pChild, "offset", m_model.m_vOffset);
        FUN_140873360(pChild, "shadowScale", m_fShadowScale);
        FUN_140873360(pChild, "rotationSpeed", m_fRotationSpeed);
        FUN_140873360(pChild, "walkSpeed", m_fWalkSpeed);
        FUN_140873360(pChild, "runSpeed", m_fRunSpeed);
    }
    pChild = pElem->FUN_140165cf0("stat");
    if (pChild)
    {
        for (int i = 0; i < 0x23; ++i)
        {
            CString strName = FUN_14082efb0(i);
            if (!strName.IsEmpty())
                FUN_1408732e0(pChild, strName, m_stat.m_aBase[i]);
        }
        if (FUN_14036d570(FUN_140166410(), 0xb2))
        {
            FUN_140873360(pChild, "scaleStatRate_2", m_stat.m_fScaleStatRate);
            FUN_1408732e0(pChild, "scaleBaseTap_2", m_stat.m_nScaleBaseTap);
            FUN_1408732e0(pChild, "scaleBaseDef_2", m_stat.m_nScaleBaseDef);
            FUN_140873360(pChild, "scaleBaseSpaRate_2", m_stat.m_fScaleBaseSpaRate);
        }
        else if (FUN_14036d570(FUN_140166410(), 0xb1))
        {
            FUN_140873360(pChild, "scaleStatRate_1", m_stat.m_fScaleStatRate);
            FUN_1408732e0(pChild, "scaleBaseTap_1", m_stat.m_nScaleBaseTap);
            FUN_1408732e0(pChild, "scaleBaseDef_1", m_stat.m_nScaleBaseDef);
            FUN_140873360(pChild, "scaleBaseSpaRate_1", m_stat.m_fScaleBaseSpaRate);
        }
    }
    pChild = pElem->FUN_140165cf0("distance");
    if (pChild)
    {
        FUN_140873360(pChild, "avoid", m_distance.m_a);
        FUN_140873360(pChild, "sight", m_distance.m_b);
        FUN_140873360(pChild, "sightHeightUP", m_distance.m_c);
        FUN_140873360(pChild, "sightHeightDown", m_distance.m_d);
        FUN_140873360(pChild, "customLastSightRadius", m_distance.m_e);
        FUN_140873360(pChild, "customLastSightHeightUp", m_distance.m_f);
        FUN_140873360(pChild, "customLastSightHeightDown", m_distance.m_g);
    }
    pChild = pElem->FUN_140165cf0("skill");
    if (pChild)
    {
        FUN_140178770(pChild, "ids", m_skill.m_aIds);
        FUN_1403759c0(pChild, "levels", reinterpret_cast<std::vector<short>&>(m_skill.m_aLevels));
        FUN_140178770(pChild, "probs", m_skill.m_aProbs);
    }
    pChild = pElem->FUN_140165cf0("additionalEffect");
    if (pChild)
    {
        FUN_140177e10(FUN_14015f710(pChild, "codes", CString("")), m_effect.m_aCodes, ",");
        FUN_140177db0(FUN_14015f710(pChild, "levels", CString("")), m_effect.m_aLevels, ",");
        CString strGroup = FUN_14015f710(pChild, "group", CString(""));
        std::vector<CString> groups;
        FUN_1402c8940(strGroup, groups, ":");
        for (size_t i = 0; i < groups.size(); ++i)
        {
            std::vector<int> pair;
            FUN_140178270(groups[i], pair, ",");
            if (pair.size() == 2)
                m_effect.m_aGroups.push_back(std::pair<int, int>(pair[0], pair[1]));
        }
        FUN_140177e10(FUN_14015f710(pChild, "rewardCodes", CString("")), m_effect.m_aRewardCodes, ",");
        FUN_140177db0(FUN_14015f710(pChild, "rewardLevels", CString("")), m_effect.m_aRewardLevels, ",");
    }
    pChild = pElem->FUN_140165cf0("interact");
    if (pChild)
    {
        FUN_1408733e0(pChild, "interactFunction", m_interact.m_strFunction);
        FUN_1408733e0(pChild, "interactCastingAnimation", m_interact.m_strCastingAnimation);
        FUN_140873220(pChild, "interactCastingTime", m_interact.m_nCastingTime);
        FUN_140873220(pChild, "interactCoolTime", m_interact.m_nCoolTime);
        FUN_1408730a0(pChild, "interactIsShowCastingBar", m_interact.m_bShowCastingBar);
    }
    pChild = pElem->FUN_140165cf0("collision");
    if (pChild)
    {
        FUN_1408733e0(pChild, "shape", m_collision.m_strShape);
        FUN_140873360(pChild, "width", m_collision.m_fWidth);
        FUN_140873360(pChild, "depth", m_collision.m_fDepth);
        FUN_140873360(pChild, "height", m_collision.m_fHeight);
        FUN_1408731e0(pChild, "widthOffset", m_collision.m_nWidthOffset);
        FUN_1408731e0(pChild, "depthOffset", m_collision.m_nDepthOffset);
        FUN_1408731e0(pChild, "heightOffset", m_collision.m_nHeightOffset);
    }
    pChild = pElem->FUN_140165cf0("nodeCollisions");
    if (pChild)
    {
        Unk_140165cf0* nodes = pChild->FUN_140165cf0("collision");
        for (Unk_XmlElementIterator it = begin(nodes), itEnd = end(nodes); it != itEnd; ++it)
        {
            Unk_140165cf0* pNode = *it;
            MS2Ptr<NodeCollision> spNode(new NodeCollision);
            FUN_1408733e0(pNode, "targetNode", spNode->m_strTargetNode);
            FUN_140874670(pNode, "volume", spNode->m_vVolume);
            FUN_140874670(pNode, "offset", spNode->m_vOffset);
            m_aNodeCollision.Add(spNode);
        }
    }
    pChild = pElem->FUN_140165cf0("nodeServerCollisions");
    if (pChild)
    {
        Unk_140165cf0* nodes = pChild->FUN_140165cf0("collision");
        for (Unk_XmlElementIterator it = begin(nodes), itEnd = end(nodes); it != itEnd; ++it)
        {
            Unk_140165cf0* pNode = *it;
            MS2Ptr<NodeCollision> spNode(new NodeCollision);
            FUN_140874670(pNode, "volume", spNode->m_vVolume);
            FUN_140874670(pNode, "offset", spNode->m_vOffset);
            m_aNodeServerCollision.Add(spNode);
        }
    }
    pChild = pElem->FUN_140165cf0("capsule");
    if (pChild)
    {
        FUN_140873360(pChild, "radius", m_capsule.m_fRadius);
        FUN_140873360(pChild, "height", m_capsule.m_fHeight);
        FUN_1408731e0(pChild, "ignore", m_capsule.m_nIgnore);
        if (m_capsule.m_fRadius <= 0.0f || m_capsule.m_fHeight <= 0.0f)
        {
            int nId = GetId();
            FUN_1406a6d70(FUN_140166440(), 0, 0, 0x16, L"NpcID={0}, Capsule.radius, Capsule.height는 0보다 커야합니다.", nId);
        }
    }
    pChild = pElem->FUN_140165cf0("dead");
    if (pChild)
    {
        FUN_140873360(pChild, "time", m_dead.m_fTime);
        FUN_1401788f0(pChild, "defaultaction", m_dead.m_aDefaultAction);
        FUN_1401788f0(pChild, "upaction", m_dead.m_aUpAction);
        FUN_140873220(pChild, "revival", m_dead.m_nRevival);
        FUN_1408731e0(pChild, "count", m_dead.m_nCount);
        FUN_140873360(pChild, "lifeTime", m_dead.m_fLifeTime);
        FUN_1408732a0(pChild, "extendRoomTime", m_dead.m_nExtendRoomTime);
    }
    pChild = pElem->FUN_140165cf0("push");
    if (pChild)
    {
        FUN_140873360(pChild, "back", m_push.m_fBack);
        FUN_140873360(pChild, "up", m_push.m_fUp);
        FUN_140873360(pChild, "knockback", m_push.m_fKnockback);
    }
    pChild = pElem->FUN_140165cf0("normal");
    if (pChild == 0)
    {
        int nProb = 1;
        m_normal.m_aActions.Add(std::make_pair("Idle_A", nProb));
        m_normal.m_nMoveArea = 200;
    }
    else
    {
        CString strAction = FUN_14015f710(pChild, "action", CString(""));
        CString strProb = FUN_14015f710(pChild, "prob", CString(""));
        ATL::CAtlArray<CString> actions;
        ATL::CAtlArray<unsigned> probs;
        FUN_14015f050(strAction, actions, ",");
        FUN_140177e10(strProb, probs, ",");
        if (probs.GetCount() < actions.GetCount())
        {
            int nId = GetId();
            FUN_140177a80(FUN_140166440(), 1, 0x13, L"입력한 값의 갯수가 맞지 않습니다. NpcID {0} [normal : prob < action]", nId);
            probs.SetCount(actions.GetCount(), -1);
        }
        for (unsigned i = 0; i < actions.GetCount(); ++i)
            m_normal.m_aActions.Add(std::make_pair(CStringA(FUN_14016a5c0(actions[i], 0)), (int)probs[i]));
        if (FUN_1408731e0(pChild, "movearea", m_normal.m_nMoveArea) != 0)
            m_normal.m_nMoveArea = 200;
    }
    pChild = pElem->FUN_140165cf0("dropiteminfo");
    if (pChild)
    {
        FUN_140178770(pChild, "globalDropBoxId", m_drop.m_aGlobalDropBoxId);
        FUN_140178770(pChild, "globalDeadDropBoxId", m_drop.m_aGlobalDeadDropBoxId);
        FUN_140178770(pChild, "individualDropBoxId", m_drop.m_aIndividualDropBoxId);
        FUN_140178770(pChild, "globalHitDropBoxId", m_drop.m_aGlobalHitDropBoxId);
        FUN_140178770(pChild, "individualHitDropBoxId", m_drop.m_aIndividualHitDropBoxId);
        FUN_140873360(pChild, "dropHeight", m_drop.m_fDropHeight);
        FUN_140873360(pChild, "dropDistanceBase", m_drop.m_fDropDistanceBase);
        FUN_1408731e0(pChild, "dropDistanceRandom", m_drop.m_nDropDistanceRandom);
        FUN_140873360(pChild, "fireVelocity", m_drop.m_fFireVelocity);
    }
    pElem->FUN_140165cf0("lookattarget");
    pChild = pElem->FUN_140165cf0("corpse");
    if (pChild)
    {
        FUN_140873360(pChild, "width", m_corpse.m_shape.m_fWidth);
        FUN_140873360(pChild, "height", m_corpse.m_shape.m_fHeight);
        FUN_140873360(pChild, "depth", m_corpse.m_shape.m_fDepth);
        FUN_140873360(pChild, "added", m_corpse.m_fAdded);
        FUN_140873360(pChild, "offsetNametag", m_corpse.m_fOffsetNametag);
        FUN_1408731e0(pChild, "hitAble", m_corpse.m_nHitAble);
        FUN_140178570(pChild, "rotation", m_corpse.m_aRotation);
        FUN_1408733e0(pChild, "corpseEffect", m_corpse.m_strCorpseEffect);
    }
    return true;
}
