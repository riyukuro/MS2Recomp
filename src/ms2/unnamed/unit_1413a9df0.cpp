// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 1 of unit_1413a9df0: the guide-condition classes ContinentCode,
// AnyOne, AllOf, AchieveExistTrophy, GuideOpen/GuideClear, ExistShortcut, UgcCollectMoney, CanObserveMode, MyPlayerLevel, Money,
// PlaceUgcCube/Item/ByIconType, InteractObject, LastClosedTextTip, ConstructSlot, Title, ServerTime, HasManufacture and the
// FieldId description (factories, names, loaders and checks). See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: unit_1413a9df0
// MS2-RANGE: 0x1413a9df0-0x1413acea0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <exception>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"


// This TU has its own copies of the StringFormat instances (the exe does not fold them), so each is a unit-local wrapper
// pinned to the copy the function calls.
// MS2-PIN: ?GcFmtId@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH@Z 0x140292a70
// MS2-PIN: ?GcFmtMinMax@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH@Z 0x1401ceea0
// MS2-PIN: ?GcFmtIntInt@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH1@Z 0x1406e7810
// MS2-PIN: ?GcFmtPos@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBM11@Z 0x140719e60
// MS2-PIN: ?GcFmtBool@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEB_N@Z 0x14136f150
// MS2-PIN: ?GcFmtSize@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEB_K@Z 0x1406c6bd0
// MS2-PIN: ?GcFmtStr@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBV12@@Z 0x1401e8510
__declspec(noinline) CStringW GcFmtId(const wchar_t* f, const int& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtMinMax(const wchar_t* f, const int& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtIntInt(const wchar_t* f, const int& a, const int& b) { return StringFormat(f, a, b); }
__declspec(noinline) CStringW GcFmtPos(const wchar_t* f, const float& a, const float& b, const float& c) { return StringFormat(f, a, b, c); }
__declspec(noinline) CStringW GcFmtBool(const wchar_t* f, const bool& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtSize(const wchar_t* f, const size_t& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtStr(const wchar_t* f, const CStringW& a) { return StringFormat(f, a); }

#include "ms2/unnamed/unit_1413a9df0.h"

// @0x1413a9df0
CStringW CGuideConditionFieldId::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"value({0}), range({1}-{2})", m_n20, reinterpret_cast<const unsigned&>(m_nRangeBeg), reinterpret_cast<const unsigned&>(m_nRangeEnd)));
    return str;
}

// @0x1413a9ec0
int CGuideConditionFieldId::vfunc_8()
{
    if (m_b1c)
        return 0;
    if (m_n20 != 0 && m_nRangeBeg == 0 && m_nRangeEnd == 0)
        return m_n20;
    return 0;
}

// @0x1413a9f10
ClassObject* CGuideConditionContinentCode::CreateObject()
{
    return new CGuideConditionContinentCode;
}

// @0x1413a9f70
CStringW CGuideConditionContinentCode::GetTypeName()
{
    return L"CGuideConditionContinentCode";
}

// @0x1413a9fc0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionContinentCode::vfunc_3()
{
    Unk_G9MapInfo info = FUN_1403ed2d0()->FUN_141bd30a0();
    if (info.FUN_140965240(0)) {
        FUN_1408850f0(&info);
        return 0;
    }
    int nContinent = FUN_140375350(info.FUN_140885340());
    int nResult = FUN_1413a5600(m_n20 == nContinent);
    FUN_1408850f0(&info);
    return nResult;
}

// @0x1413aa070
ClassObject* CGuideConditionAnyOne::CreateObject()
{
    return new CGuideConditionAnyOne;
}

// @0x1413aa0d0
CStringW CGuideConditionAnyOne::GetTypeName()
{
    return L"CGuideConditionAnyOne";
}

// @0x1413aa120
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionAnyOne::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("condition"); pChild != 0; pChild = pChild->FUN_140168650("condition")) {
        Unk_GcCondRef ref = FUN_1413a52c0(pChild);
        if (ref.FUN_141387b90())
            m_conds.FUN_141388460(ref);
    }
}

// @0x1413aa1d0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionAnyOne::vfunc_3()
{
    for (unsigned i = 0; i < m_conds.FUN_1413886d0(); ++i) {
        if (FUN_1413a5570(m_conds.FUN_141387b40(i).FUN_141387bb0()) != 0)
            return 1;
    }
    return 0;
}

// @0x1413aa250
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionAnyOne::vfunc_4()
{
    CGuideCondition::vfunc_4();
    for (unsigned i = 0; i < m_conds.FUN_1413886d0(); ++i)
        m_conds.FUN_141387b40(i).FUN_141387bb0()->vfunc_4();
}

// @0x1413aa2e0
ClassObject* CGuideConditionAllOf::CreateObject()
{
    return new CGuideConditionAllOf;
}

// @0x1413aa340
CStringW CGuideConditionAllOf::GetTypeName()
{
    return L"CGuideConditionAllOf";
}

// @0x1413aa390
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionAllOf::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("condition"); pChild != 0; pChild = pChild->FUN_140168650("condition")) {
        Unk_GcCondRef ref = FUN_1413a52c0(pChild);
        if (ref.FUN_141387b90())
            m_conds.FUN_141388460(ref);
    }
}

// @0x1413aa440
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
bool CGuideConditionAllOf::vfunc_6(Unk_GcCondList* pFailed)
{
    for (unsigned i = 0; i < m_conds.FUN_1413886d0(); ++i) {
        if (!m_conds.FUN_141387b40(i).FUN_141387bb0()->vfunc_6(pFailed))
            pFailed->FUN_141388460(m_conds.FUN_141387b40(i));
    }
    return true;
}

// @0x1413aa500
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionAllOf::vfunc_3()
{
    for (unsigned i = 0; i < m_conds.FUN_1413886d0(); ++i) {
        if (FUN_1413a5570(m_conds.FUN_141387b40(i).FUN_141387bb0()) == 0)
            return 0;
    }
    return 1;
}

// @0x1413aa580
ClassObject* CGuideConditionAchieveExistTrophy::CreateObject()
{
    return new CGuideConditionAchieveExistTrophy;
}

// @0x1413aa5e0
CStringW CGuideConditionAchieveExistTrophy::GetTypeName()
{
    return L"CGuideConditionAchieveExistTrophy";
}

// @0x1413aa630
void CGuideConditionAchieveExistTrophy::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1413b1d00(pElem, "achieveType", m_type);
}

// @0x1413aa680
int CGuideConditionAchieveExistTrophy::vfunc_3()
{
    return FUN_1413a55a0(FUN_140936740(FUN_1406c7600(), *reinterpret_cast<unsigned __int64*>(&m_type)));
}

// @0x1413aa6c0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionAchieveExistTrophy::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    if (m_type.m_bSet)
        str.Append(StringFormat(L"achieveType({0})", GcEnum<Unk_GcAchieveType>(m_type.m_nValue)));
    else
        str.Append(StringFormat(L"achieveType"));
    return str;
}

// @0x1413aa7e0
ClassObject* CGuideConditionGuideOpen::CreateObject()
{
    return new CGuideConditionGuideOpen;
}

// @0x1413aa840
CStringW CGuideConditionGuideOpen::GetTypeName()
{
    return L"CGuideConditionGuideOpen";
}

// @0x1413aa890
void CGuideConditionGuideOpen::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 13;
    m_nGuideId = 0;
    FUN_140873220(pElem, "id", reinterpret_cast<unsigned&>(m_nGuideId));
}

// @0x1413aa8f0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionGuideOpen::vfunc_3()
{
    Unk_G9GuideRef ref = FUN_1409331e0()->FUN_14138b990(m_nGuideId);
    if (ref.m_pEntry == 0) {
        FUN_141397db0(&ref);
        return 0;
    }
    int nResult = FUN_1413a5600(ref.FUN_141398900()->m_n1c != 0);
    FUN_141397db0(&ref);
    return nResult;
}

// @0x1413aa990
CStringW CGuideConditionGuideOpen::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtId(L"guideID({0})", m_nGuideId));
    return str;
}

// @0x1413aaa40
int CGuideConditionGuideOpen::vfunc_8()
{
    return 0;
}

// @0x1413aaa50
ClassObject* CGuideConditionGuideClear::CreateObject()
{
    return new CGuideConditionGuideClear;
}

// @0x1413aaab0
CStringW CGuideConditionGuideClear::GetTypeName()
{
    return L"CGuideConditionGuideClear";
}

// @0x1413aab00
void CGuideConditionGuideClear::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 2;
    m_nGuideId = 0;
    FUN_140873220(pElem, "id", reinterpret_cast<unsigned&>(m_nGuideId));
}

// @0x1413aab60
int CGuideConditionGuideClear::vfunc_3()
{
    return FUN_1413a5600(FUN_1409331e0()->FUN_14138caa0(m_nGuideId));
}

// @0x1413aaba0
CStringW CGuideConditionGuideClear::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtId(L"guideID({0})", m_nGuideId));
    return str;
}

// @0x1413aac50
int CGuideConditionGuideClear::vfunc_8()
{
    if (m_b1c)
        return 0;
    return m_nGuideId;
}

// @0x1413aac80
ClassObject* CGuideConditionExistShortcut::CreateObject()
{
    return new CGuideConditionExistShortcut;
}

// @0x1413aace0
CStringW CGuideConditionExistShortcut::GetTypeName()
{
    return L"CGuideConditionExistShortcut";
}

// @0x1413aad30
void CGuideConditionExistShortcut::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nSlotIndex = 0;
    m_nSkillId = 0;
    FUN_140873220(pElem, "slotIndex", reinterpret_cast<unsigned&>(m_nSlotIndex));
    FUN_140873220(pElem, "skillID", reinterpret_cast<unsigned&>(m_nSkillId));
}

// @0x1413aadb0
int CGuideConditionExistShortcut::vfunc_3()
{
    int nSkill = FUN_14142dc50(FUN_1409331f0(), m_nSlotIndex);
    return FUN_1413a5600(nSkill == m_nSkillId);
}

// @0x1413aae10
CStringW CGuideConditionExistShortcut::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtIntInt(L"slotIndex({0}), skillID({1})", m_nSlotIndex, m_nSkillId));
    return str;
}

// @0x1413aaed0
ClassObject* CGuideConditionUgcCollectMoney::CreateObject()
{
    return new CGuideConditionUgcCollectMoney;
}

// @0x1413aaf30
CStringW CGuideConditionUgcCollectMoney::GetTypeName()
{
    return L"CGuideConditionUgcCollectMoney";
}

// @0x1413aaf80
int CGuideConditionUgcCollectMoney::vfunc_3()
{
    return 0 < FUN_140d56470(FUN_140939a00());
}

// @0x1413aafc0
ClassObject* CGuideConditionCanObserveMode::CreateObject()
{
    return new CGuideConditionCanObserveMode;
}

// @0x1413ab020
CStringW CGuideConditionCanObserveMode::GetTypeName()
{
    return L"CGuideConditionCanObserveMode";
}

// @0x1413ab070
int CGuideConditionCanObserveMode::vfunc_3()
{
    void* pDialog = FUN_1413b1c60("PartyDialog");
    if (pDialog == 0)
        return 0;
    return FUN_1413a55a0(FUN_141a75840(pDialog));
}

// @0x1413ab0e0
ClassObject* CGuideConditionMyPlayerLevel::CreateObject()
{
    return new CGuideConditionMyPlayerLevel;
}

// @0x1413ab140
CStringW CGuideConditionMyPlayerLevel::GetTypeName()
{
    return L"CGuideConditionMyPlayerLevel";
}

// @0x1413ab190
void CGuideConditionMyPlayerLevel::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 4;
}

// @0x1413ab1d0
int CGuideConditionMyPlayerLevel::vfunc_3()
{
    Unk_G9Player* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    return FUN_1413a5600(pPC->vfunc_78() >= m_n20);
}

// @0x1413ab240
int CGuideConditionMyPlayerLevel::vfunc_8()
{
    return 0;
}

// @0x1413ab250
ClassObject* CGuideConditionMoney::CreateObject()
{
    return new CGuideConditionMoney;
}

// @0x1413ab2b0
CStringW CGuideConditionMoney::GetTypeName()
{
    return L"CGuideConditionMoney";
}

// @0x1413ab300
int CGuideConditionMoney::vfunc_3()
{
    return FUN_1413a5600(DAT_143ab2898 >= m_n20);
}

// @0x1413ab350
ClassObject* CGuideConditionPlaceUgcCube::CreateObject()
{
    return new CGuideConditionPlaceUgcCube;
}

// @0x1413ab3b0
CStringW CGuideConditionPlaceUgcCube::GetTypeName()
{
    return L"CGuideConditionPlaceUgcCube";
}

// @0x1413ab400
void CGuideConditionPlaceUgcCube::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nItemId = 0;
    FUN_1408731e0(pElem, "itemId", m_nItemId);
    FUN_1413b1d00(pElem, "minCount", m_min);
    FUN_1413b1d00(pElem, "maxCount", m_max);
}

// @0x1413ab490
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionPlaceUgcCube::vfunc_3()
{
    if (m_nItemId != 0 && FUN_1409670e0()->FUN_1410b9850(m_nItemId) == 0)
        return FUN_1413a55a0(0);
    if (m_min.m_bSet || m_max.m_bSet) {
        int nCount = FUN_1409670e0()->FUN_1410b9a50();
        if (m_min.m_bSet && nCount < m_min.m_nValue)
            return FUN_1413a55a0(0);
        if (m_max.m_bSet && m_max.m_nValue < nCount)
            return FUN_1413a55a0(0);
    }
    return FUN_1413a55a0(1);
}

// @0x1413ab5b0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionPlaceUgcCube::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtId(L"itemID({0})", m_nItemId));
    if (m_min.m_bSet)
        str.Append(GcFmtMinMax(L", minCount({0})", m_min.m_nValue));
    if (m_max.m_bSet)
        str.Append(GcFmtMinMax(L", maxCount({0})", m_max.m_nValue));
    return str;
}

// @0x1413ab750
ClassObject* CGuideConditionPlaceUgcCubeItem::CreateObject()
{
    return new CGuideConditionPlaceUgcCubeItem;
}

// @0x1413ab7b0
CStringW CGuideConditionPlaceUgcCubeItem::GetTypeName()
{
    return L"CGuideConditionPlaceUgcCubeItem";
}

// @0x1413ab800
void CGuideConditionPlaceUgcCubeItem::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1413b1e70(pElem, "pos", m_pos);
    FUN_1413b1ed0(pElem, "isAttachable", m_attachable);
}

// @0x1413ab870
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionPlaceUgcCubeItem::vfunc_3()
{
    if (!m_pos.m_bSet)
        return 0;
    Unk_StreamPoint pos(m_pos.m_x, m_pos.m_y, m_pos.m_z);
    void* pCube = FUN_1409670e0()->FUN_1410b8ab0(pos);
    if (pCube == 0)
        return FUN_1413a55a0(0);
    if (m_attachable.m_bSet) {
        Unk_G9ItemRef item = FUN_14053f870(FUN_1408b4f20(pCube));
        int nAttach = item.FUN_1401b52a0()->m_nValue;
        if ((nAttach != 0) != m_attachable.m_bValue) {
            int nResult = FUN_1413a55a0(0);
            item.FUN_1401b50d0();
            return nResult;
        }
        item.FUN_1401b50d0();
    }
    return FUN_1413a55a0(1);
}

// @0x1413ab9e0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionPlaceUgcCubeItem::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    if (m_pos.m_bSet)
        str.Append(GcFmtPos(L"pos({0},{1},{2})", m_pos.m_x, m_pos.m_y, m_pos.m_z));
    if (m_attachable.m_bSet)
        str.Append(GcFmtBool(L"isAttachable({0})", m_attachable.m_bValue));
    return str;
}

// @0x1413abb80
ClassObject* CGuideConditionPlaceUgcCubeByIconType::CreateObject()
{
    return new CGuideConditionPlaceUgcCubeByIconType;
}

// @0x1413abbe0
CStringW CGuideConditionPlaceUgcCubeByIconType::GetTypeName()
{
    return L"CGuideConditionPlaceUgcCubeByIconType";
}

// @0x1413abc30
void CGuideConditionPlaceUgcCubeByIconType::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nIconType = 0;
    FUN_1408731e0(pElem, "iconType", m_nIconType);
}

// @0x1413abc90
int CGuideConditionPlaceUgcCubeByIconType::vfunc_3()
{
    if (FUN_1409670e0()->FUN_1410b9950(m_nIconType) == 0)
        return FUN_1413a55a0(0);
    return FUN_1413a55a0(1);
}

// @0x1413abce0
CStringW CGuideConditionPlaceUgcCubeByIconType::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtMinMax(L"iconType({0})", m_nIconType));
    return str;
}

// @0x1413abd90
ClassObject* CGuideConditionInteractObject::CreateObject()
{
    return new CGuideConditionInteractObject;
}

// @0x1413abdf0
CStringW CGuideConditionInteractObject::GetTypeName()
{
    return L"CGuideConditionInteractObject";
}

// @0x1413abe40
void CGuideConditionInteractObject::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1408731e0(pElem, "interactId", m_nInteractId);
    FUN_140873360(pElem, "distance", m_fDistance);
    FUN_1408731e0(pElem, "state", m_nState);
}

// @0x1413abec0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionInteractObject::vfunc_3()
{
    Unk_G9Player* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    Unk_StreamPoint posPC = pPC->vfunc_18();
    Unk_G9ObjRef ref = FUN_1403ed2d0()->FUN_141bc6510(posPC, m_nInteractId);
    Unk_G9Obj* pObj = static_cast<Unk_G9Obj*>(ref.FUN_1409657e0());
    FUN_1409649b0(&ref);
    if (pObj == 0)
        return 0;
    Unk_StreamPoint posObj = pObj->FUN_1409673c0();
    float fDist = pPC->vfunc_18().FUN_140965c40(posObj).FUN_140967ac0();
    if (fDist <= m_fDistance)
        return FUN_1413a55a0(FUN_1413b5600(pObj) == m_nState);
    return FUN_1413a55a0(0);
}

// @0x1413ac050
CStringW CGuideConditionInteractObject::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"interactID({0}), interactID({1}), interactID({2})", m_nInteractId, m_fDistance, m_nState));
    return str;
}

// @0x1413ac120
ClassObject* CGuideConditionLastClosedTextTip::CreateObject()
{
    return new CGuideConditionLastClosedTextTip;
}

// @0x1413ac180
CStringW CGuideConditionLastClosedTextTip::GetTypeName()
{
    return L"CGuideConditionLastClosedTextTip";
}

// @0x1413ac1d0
void CGuideConditionLastClosedTextTip::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nEntityId = 0;
    FUN_1408731e0(pElem, "entityId", m_nEntityId);
    if (m_nEntityId == 0)
        throw std::exception(FUN_141388650("lastClosedToolTip entityId == 0"));
}

// @0x1413ac290
int CGuideConditionLastClosedTextTip::vfunc_3()
{
    void* pDialog = FUN_14136f3e0(0x4e53);
    if (pDialog != 0)
        return FUN_1413a5600(m_nEntityId == FUN_14195b950(pDialog));
    return 0;
}

// @0x1413ac2f0
CStringW CGuideConditionLastClosedTextTip::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtMinMax(L"entityID({0})", m_nEntityId));
    return str;
}

// @0x1413ac3a0
ClassObject* CGuideConditionConstructSlot::CreateObject()
{
    return new CGuideConditionConstructSlot;
}

// @0x1413ac400
CStringW CGuideConditionConstructSlot::GetTypeName()
{
    return L"CGuideConditionConstructSlot";
}

// @0x1413ac450
void CGuideConditionConstructSlot::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nSlotIdx = 0;
    m_bIndoor = false;
    m_bOutdoor = false;
    FUN_1408731e0(pElem, "slotIdx", m_nSlotIdx);
    FUN_1408736d0(pElem, "isIndoor", m_bIndoor);
    FUN_1408736d0(pElem, "isOutdoor", m_bOutdoor);
}

// @0x1413ac4f0
int CGuideConditionConstructSlot::vfunc_3()
{
    return 1;
}

// @0x1413ac510
void CGuideConditionConstructSlot::vfunc_5()
{
    
}

// @0x1413ac520
CStringW CGuideConditionConstructSlot::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"slotIdx({0}), isIndoor({1}), isOutDoor({2})", m_nSlotIdx, m_bIndoor, m_bOutdoor));
    return str;
}

// @0x1413ac5f0
ClassObject* CGuideConditionTitle::CreateObject()
{
    return new CGuideConditionTitle;
}

// @0x1413ac650
CStringW CGuideConditionTitle::GetTypeName()
{
    return L"CGuideConditionTitle";
}

// @0x1413ac6a0
int CGuideConditionTitle::vfunc_3()
{
    Unk_G9Player* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    return FUN_1413a5600(DAT_143ab3268.FUN_140186270() > 0);
}

// @0x1413ac700
void CGuideConditionTitle::vfunc_5()
{
    Unk_G9Player* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    size_t nCount = DAT_143ab3268.FUN_140186270();
    FUN_1412751b0(GcFmtSize(L"CGuideConditionTitle> titleCount={0}", nCount), 0x14);
}

// @0x1413ac790
ClassObject* CGuideConditionServerTime::CreateObject()
{
    return new CGuideConditionServerTime;
}

// @0x1413ac7f0
CStringW CGuideConditionServerTime::GetTypeName()
{
    return L"CGuideConditionServerTime";
}

// @0x1413ac840
void CGuideConditionServerTime::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_140873600(pElem, "dateTime", m_time);
}

// @0x1413ac890
int CGuideConditionServerTime::vfunc_3()
{
    // the exe does not run the default constructor here (the epoch setter fills the whole object)
    struct { void* m_p0; void* m_p1; } rawNow;
    reinterpret_cast<Unk_GcTime&>(rawNow).FUN_1406c47a0(FUN_140869440());
    return FUN_1413a5600(m_time.FUN_1406c4cc0(reinterpret_cast<Unk_GcTime&>(rawNow)));
}

// @0x1413ac8e0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionServerTime::vfunc_5()
{
    Unk_GcTime now;
    now.FUN_1406c47a0(FUN_140869440());
    Unk_GcTime target;
    target.FUN_1406c47d0(2015, 4, 21, 16, 0, 0);
    m_time.FUN_1406c4930(target);
    CStringW strNow = FUN_14083bdc0(now, 1, CStringW(L"/"), CStringW(L":"));
    CStringW strTarget = FUN_14083bdc0(m_time, 1, CStringW(L"/"), CStringW(L":"));
    FUN_1412751b0(GcFmtStr(L"curTime={0}", strNow), 0x14);
    FUN_1412751b0(GcFmtStr(L"targetTime={0}", strTarget), 0x14);
    bool bPassed = m_time.FUN_1406c4cc0(now);
    FUN_1412751b0(GcFmtStr(L"(passed)={0}", FUN_140719730(bPassed)), 0x14);
}

// @0x1413acbe0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionServerTime::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    Unk_GcTime t;
    t.FUN_1406c47a0(m_time.FUN_140282020());
    CStringW strTime = FUN_14083bdc0(t, 1, CStringW(L"/"), CStringW(L":"));
    str.Append(GcFmtStr(L"dateTime({0})", strTime));
    return str;
}

// @0x1413acd60
ClassObject* CGuideConditionHasManufacture::CreateObject()
{
    return new CGuideConditionHasManufacture;
}

// @0x1413acdc0
CStringW CGuideConditionHasManufacture::GetTypeName()
{
    return L"CGuideConditionHasManufacture";
}

// @0x1413ace10
int CGuideConditionHasManufacture::vfunc_3()
{
    return FUN_140d513c0(FUN_1409eed40());
}

// @0x1413ace40
ClassObject* CGuideConditionHasMoney::CreateObject()
{
    return new CGuideConditionHasMoney;
}
