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
// The condition lists are the exe's CAtlArray<MS2Ptr<CGuideCondition>> (count / [] / Add are its members).
#define GE_CONDS(list) reinterpret_cast<ATL::CAtlArray<MS2Ptr<CGuideCondition> >&>(list)   // m_arr is at +0


// This TU has its own copies of the StringFormat instances (the exe does not fold them), so each is a unit-local wrapper
// pinned to the copy the function calls.
// MS2-PIN: ?GcFmtId@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH@Z 0x140292a70
// MS2-PIN: ?GcFmtMinMax@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH@Z 0x1401ceea0
// MS2-PIN: ?GcFmtIntInt@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH1@Z 0x1406e7810
// MS2-PIN: ?GcFmtPos@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBM11@Z 0x140719e60
// MS2-PIN: ?GcFmtBool@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEB_N@Z 0x14136f150
// MS2-PIN: ?GcFmtSize@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEB_K@Z 0x1406c6bd0
// MS2-PIN: ?GcFmtStr@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBV12@@Z 0x1401e8510
// MS2-PIN: ??0CMsTime@@QEAA@HHHHHH@Z 0x1406c47d0
// MS2-PIN: ??0?$MS2Ptr@VASDisplayObject@@@@QEAA@H@Z 0x140d02f80
// MS2-PIN: ?FUN_140d01be0@@YA?AV?$MS2Ptr@VASDisplayObject@@@@HAEBVValue@GFx@Scaleform@@@Z 0x140d01be0
// GcFmtId and GcFmtIntInt: the exe's copies are StringFormat<unsigned int> / <unsigned int, unsigned int> (make_type<unsigned
// int>), so the int ids are formatted as unsigned.
__declspec(noinline) CStringW GcFmtId(const wchar_t* f, const int& a) { return StringFormat(f, reinterpret_cast<const unsigned&>(a)); }
__declspec(noinline) CStringW GcFmtMinMax(const wchar_t* f, const int& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtIntInt(const wchar_t* f, const int& a, const int& b)
{
    return StringFormat(f, reinterpret_cast<const unsigned&>(a), reinterpret_cast<const unsigned&>(b));
}
__declspec(noinline) CStringW GcFmtPos(const wchar_t* f, const float& a, const float& b, const float& c) { return StringFormat(f, a, b, c); }
__declspec(noinline) CStringW GcFmtBool(const wchar_t* f, const bool& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtSize(const wchar_t* f, const size_t& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtStr(const wchar_t* f, const CStringW& a) { return StringFormat(f, a); }

#include "ms2/unnamed/unit_1413a9df0.h"
class CFieldData { public: int GetContinentCode(); };   // C3: member views
class Cube { public: int FUN_1408b4f20(); };
struct Unk_NullableInt { int* GetValue(); bool m_bSet; int m_nValue; };
class CAchieveManager { public: int HasCompletedOfType(Unk_NullableInt nType); };
class CKeyTable { public: int GetQuickSlotSkillId(unsigned nSlot); };
class CMeratMarketMan { public: __int64 FUN_140d56470(); };
class UIPartyDialog { public: int IsObserveModeAvailable(); };
class UIGuideEvent { public: int GetLastTip(); };
#include "ms2/commonfiles/os.h"
class CManufactureManager { public: int HasManufacture(); };
struct Unk_ImNullableInt { bool HasValue() const; bool m_bSet; int m_nValue; };
class CubeMapInformationService { public: class Cube* FindCubeByItemId(int nItemId); int HasCubeWithIconCode(int nCategory); int CountCubes(); class Cube* GetCubeAtPoint(Vector3 pos); };
__int64 GetServerTime();
int XmlGetAttr(class TiXmlElement*, char const*, int&);
int XmlGetAttr(class TiXmlElement*, char const*, CMsTime&);
int XmlQuery(class TiXmlElement*, char const*, bool&);
class Unk_GcSmartRef { public: void* FUN_1413b4130() const; };
class CGuideEntity : public CPtred {};   // C3: handle pointees
class CFieldDataCli : public CPtred {};
// (the world's interact object is the CInteractObject view of unit_1413a9df0.h)
class CGuideManager { public: MS2Ptr<CGuideEntity> FindEntity(int nId); bool IsCleared(int nId); };
#include "ms2/placeholder/citemdata.h"
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
class CItemData;   // C3: MS2Ptr<CItemData>::operator->
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

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
int CGuideConditionContinentCode::vfunc_3()
{
    MS2Ptr<CFieldDataCli> info = WorldService::GetInstance()->FUN_141bd30a0();
    if (info.operator==(0))
        return 0;
    return ApplyNotBool(m_n20 == reinterpret_cast<CFieldData*>(info.operator->())->GetContinentCode());
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
void CGuideConditionAnyOne::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    for (TiXmlElement* pChild = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("condition")); pChild != 0; pChild = ((class TiXmlElement*)((class Unk_XmlNode*)(pChild))->NextSibling("condition"))) {
        MS2Ptr<CGuideCondition> ref = FUN_1413a52c0(pChild);
        if (ref.get())
            GE_CONDS(m_conds).Add(ref);
    }
}

// @0x1413aa1d0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionAnyOne::vfunc_3()
{
    for (unsigned i = 0; i < GE_CONDS(m_conds).GetCount(); ++i) {
        if (EvaluateCondition(GE_CONDS(m_conds)[i].operator->()) != 0)
            return 1;
    }
    return 0;
}

// @0x1413aa250
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionAnyOne::vfunc_4()
{
    CGuideCondition::vfunc_4();
    for (unsigned i = 0; i < GE_CONDS(m_conds).GetCount(); ++i)
        GE_CONDS(m_conds)[i]->vfunc_4();
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
void CGuideConditionAllOf::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    for (TiXmlElement* pChild = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("condition")); pChild != 0; pChild = ((class TiXmlElement*)((class Unk_XmlNode*)(pChild))->NextSibling("condition"))) {
        MS2Ptr<CGuideCondition> ref = FUN_1413a52c0(pChild);
        if (ref.get())
            GE_CONDS(m_conds).Add(ref);
    }
}

// @0x1413aa440
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
bool CGuideConditionAllOf::vfunc_6(Unk_GcCondList* pFailed)
{
    for (unsigned i = 0; i < GE_CONDS(m_conds).GetCount(); ++i) {
        if (!GE_CONDS(m_conds)[i]->vfunc_6(pFailed))
            reinterpret_cast<ATL::CAtlArray<MS2Ptr<CGuideCondition> >*>(pFailed)->Add(GE_CONDS(m_conds)[i]);
    }
    return true;
}

// @0x1413aa500
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionAllOf::vfunc_3()
{
    for (unsigned i = 0; i < GE_CONDS(m_conds).GetCount(); ++i) {
        if (EvaluateCondition(GE_CONDS(m_conds)[i].operator->()) == 0)
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
void CGuideConditionAchieveExistTrophy::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1413b1d00(pElem, "achieveType", m_type);
}

// @0x1413aa680
int CGuideConditionAchieveExistTrophy::vfunc_3()
{
    return ApplyNot(reinterpret_cast<CAchieveManager*>(GetAchieveManager())->HasCompletedOfType(*reinterpret_cast<Unk_NullableInt*>(&m_type)));
}

// @0x1413aa6c0
CStringW CGuideConditionAchieveExistTrophy::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    if (Unk_GcIntIsNull(&m_type))
        str.Append(StringFormat(L"achieveType"));
    else
        str.Append(StringFormat(L"achieveType({0})", *reinterpret_cast<Unk_GcAchieveType*>(reinterpret_cast<Unk_NullableInt*>(&m_type)->GetValue())));
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
void CGuideConditionGuideOpen::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 13;
    m_nGuideId = 0;
    XmlGetAttr((class TiXmlElement*)(pElem), "id", reinterpret_cast<unsigned&>(m_nGuideId));
}

// @0x1413aa8f0
int CGuideConditionGuideOpen::vfunc_3()
{
    MS2Ptr<CGuideEntity> ref = reinterpret_cast<CGuideManager*>(FUN_1409331e0())->FindEntity(m_nGuideId);
    if (reinterpret_cast<Unk_GcSmartRef*>(&ref)->FUN_1413b4130())
        return ApplyNotBool(reinterpret_cast<Unk_G9GuideEntry*>(ref.operator->())->m_n1c != 0);
    return 0;
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
void CGuideConditionGuideClear::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 2;
    m_nGuideId = 0;
    XmlGetAttr((class TiXmlElement*)(pElem), "id", reinterpret_cast<unsigned&>(m_nGuideId));
}

// @0x1413aab60
int CGuideConditionGuideClear::vfunc_3()
{
    return ApplyNotBool(reinterpret_cast<CGuideManager*>(FUN_1409331e0())->IsCleared(m_nGuideId));
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
void CGuideConditionExistShortcut::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nSlotIndex = 0;
    m_nSkillId = 0;
    XmlGetAttr((class TiXmlElement*)(pElem), "slotIndex", reinterpret_cast<unsigned&>(m_nSlotIndex));
    XmlGetAttr((class TiXmlElement*)(pElem), "skillID", reinterpret_cast<unsigned&>(m_nSkillId));
}

// @0x1413aadb0
int CGuideConditionExistShortcut::vfunc_3()
{
    int nSkill = reinterpret_cast<CKeyTable*>(GetKeyTable())->GetQuickSlotSkillId(m_nSlotIndex);
    return ApplyNotBool(nSkill == m_nSkillId);
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
    return 0 < reinterpret_cast<CMeratMarketMan*>(GetMeratMarketMan())->FUN_140d56470();
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
    return ApplyNot(reinterpret_cast<UIPartyDialog*>(pDialog)->IsObserveModeAvailable());
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
void CGuideConditionMyPlayerLevel::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 4;
}

// @0x1413ab1d0
int CGuideConditionMyPlayerLevel::vfunc_3()
{
    Unk_G9Player* pPC = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    return ApplyNotBool(pPC->vfunc_78() >= m_n20);
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
    return ApplyNotBool(DAT_143ab2898 >= m_n20);
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
void CGuideConditionPlaceUgcCube::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nItemId = 0;
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "itemId", m_nItemId);
    FUN_1413b1d00(pElem, "minCount", m_min);
    FUN_1413b1d00(pElem, "maxCount", m_max);
}

// @0x1413ab490
int CGuideConditionPlaceUgcCube::vfunc_3()
{
    if (m_nItemId != 0 && reinterpret_cast<CubeMapInformationService*>(Unk_AkoHouseSvc::GetInstance())->FindCubeByItemId(m_nItemId) == 0)
        return ApplyNot(0);
    if (reinterpret_cast<const Unk_ImNullableInt*>(&m_min)->HasValue() || reinterpret_cast<const Unk_ImNullableInt*>(&m_max)->HasValue()) {
        int nCount = reinterpret_cast<CubeMapInformationService*>(Unk_AkoHouseSvc::GetInstance())->CountCubes();
        if (reinterpret_cast<const Unk_ImNullableInt*>(&m_min)->HasValue() && nCount < *FUN_1413989f0(&m_min))
            return ApplyNot(0);
        if (reinterpret_cast<const Unk_ImNullableInt*>(&m_max)->HasValue() && nCount > *FUN_1413989f0(&m_max))
            return ApplyNot(0);
    }
    return ApplyNot(1);
}

// @0x1413ab5b0
CStringW CGuideConditionPlaceUgcCube::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtId(L"itemID({0})", m_nItemId));
    if (reinterpret_cast<const Unk_ImNullableInt*>(&m_min)->HasValue())
        str.Append(GcFmtMinMax(L", minCount({0})", *FUN_1413989f0(&m_min)));
    if (reinterpret_cast<const Unk_ImNullableInt*>(&m_max)->HasValue())
        str.Append(GcFmtMinMax(L", maxCount({0})", *FUN_1413989f0(&m_max)));
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
void CGuideConditionPlaceUgcCubeItem::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1413b1e70(pElem, "pos", m_pos);
    FUN_1413b1ed0(pElem, "isAttachable", m_attachable);
}

// @0x1413ab870
int CGuideConditionPlaceUgcCubeItem::vfunc_3()
{
    if (Unk_GcVec3IsNull(&m_pos))
        return 0;
    void* pCube = reinterpret_cast<CubeMapInformationService*>(Unk_AkoHouseSvc::GetInstance())->GetCubeAtPoint(m_pos.GetValue());
    if (pCube == 0)
        return ApplyNot(0);
    if (Unk_GcBoolHasValue(&m_attachable)) {
        MS2Ptr<CItemData> item = FUN_14053f870(reinterpret_cast<Cube*>(pCube)->FUN_1408b4f20());
        bool bAttach = reinterpret_cast<Unk_G9ItemRec*>(item.operator->())->m_nValue != 0;
        if (bAttach != m_attachable.GetValue())
            return ApplyNot(0);
    }
    return ApplyNot(1);
}

// @0x1413ab9e0
CStringW CGuideConditionPlaceUgcCubeItem::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    if (Unk_GcVec3HasValue(&m_pos))
        str.Append(GcFmtPos(L"pos({0},{1},{2})", static_cast<const Unk_GcOptVec3&>(m_pos).GetValue().x, static_cast<const Unk_GcOptVec3&>(m_pos).GetValue().y,
            static_cast<const Unk_GcOptVec3&>(m_pos).GetValue().z));   // the exe calls the const GetValue 0x1413b4140 here
    if (Unk_GcBoolHasValue(&m_attachable))
        str.Append(GcFmtBool(L"isAttachable({0})", m_attachable.GetValue()));
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
void CGuideConditionPlaceUgcCubeByIconType::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nIconType = 0;
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "iconType", m_nIconType);
}

// @0x1413abc90
int CGuideConditionPlaceUgcCubeByIconType::vfunc_3()
{
    if (reinterpret_cast<CubeMapInformationService*>(Unk_AkoHouseSvc::GetInstance())->HasCubeWithIconCode(m_nIconType) == 0)
        return ApplyNot(0);
    return ApplyNot(1);
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
void CGuideConditionInteractObject::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "interactId", m_nInteractId);
    XmlGetAttr((class TiXmlElement*)(pElem), "distance", m_fDistance);
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "state", m_nState);
}

// @0x1413abec0
int CGuideConditionInteractObject::vfunc_3()
{
    Unk_G9Player* pPC = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    CInteractObject* pObj = WorldService::GetInstance()->FUN_141bc6510(pPC->vfunc_18(), m_nInteractId).operator CInteractObject*();
    if (pObj == 0)
        return 0;
    float fDist = (pPC->vfunc_18() - pObj->GetPos()).Length();
    if (fDist > m_fDistance)
        return ApplyNot(0);
    if (pObj->GetState() != m_nState)
        return ApplyNot(0);
    return ApplyNot(1);
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
void CGuideConditionLastClosedTextTip::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nEntityId = 0;
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "entityId", m_nEntityId);
    if (m_nEntityId == 0)
        throw std::exception(StringFormat("lastClosedToolTip entityId == 0"));
}

// @0x1413ac290
int CGuideConditionLastClosedTextTip::vfunc_3()
{
    void* pDialog = FindGuideEvent(0x4e53);
    if (pDialog != 0)
        return ApplyNotBool(m_nEntityId == reinterpret_cast<UIGuideEvent*>(pDialog)->GetLastTip());
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
void CGuideConditionConstructSlot::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nSlotIdx = 0;
    m_bIndoor = false;
    m_bOutdoor = false;
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "slotIdx", m_nSlotIdx);
    XmlQuery(reinterpret_cast<TiXmlElement*>(pElem), "isIndoor", m_bIndoor);
    XmlQuery(reinterpret_cast<TiXmlElement*>(pElem), "isOutdoor", m_bOutdoor);
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
    Unk_G9Player* pPC = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    return ApplyNotBool(reinterpret_cast<ATL::CAtlArray<unsigned>&>(DAT_143ab3268).GetCount() > 0);
}

// @0x1413ac700
void CGuideConditionTitle::vfunc_5()
{
    Unk_G9Player* pPC = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    size_t nCount = reinterpret_cast<ATL::CAtlArray<unsigned>&>(DAT_143ab3268).GetCount();
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
void CGuideConditionServerTime::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "dateTime", m_time);
}

// @0x1413ac890
int CGuideConditionServerTime::vfunc_3()
{
    CMsTime now(GetServerTime());
    return ApplyNotBool(m_time <= now);
}

// @0x1413ac8e0
void CGuideConditionServerTime::vfunc_5()
{
    CMsTime now(GetServerTime());
    m_time = CMsTime(2015, 4, 21, 16, 0, 0);
    CStringW strNow = FUN_14083bdc0(now, true, CStringW(L"/"), CStringW(L":"));
    CStringW strTarget = FUN_14083bdc0(m_time, true, CStringW(L"/"), CStringW(L":"));
    FUN_1412751b0(GcFmtStr(L"curTime={0}", strNow), 0x14);
    FUN_1412751b0(GcFmtStr(L"targetTime={0}", strTarget), 0x14);
    FUN_1412751b0(GcFmtStr(L"(passed)={0}", FUN_140719730(m_time <= now)), 0x14);
}

// @0x1413acbe0
CStringW CGuideConditionServerTime::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtStr(L"dateTime({0})", FUN_14083bdc0(m_time.Get(), true, CStringW(L"/"), CStringW(L":"))));
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
    return TSingleton<CManufactureManager>::GetInstance()->HasManufacture();
}

// @0x1413ace40
ClassObject* CGuideConditionHasMoney::CreateObject()
{
    return new CGuideConditionHasMoney;
}
