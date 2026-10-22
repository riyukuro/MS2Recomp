// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 4 of unit_1413a9df0: the destructors of the CGuideCondition*
// subclasses (implicit, emitted through the anchors below) and the Nullable / array helpers the conditions use.
// The scalar deleting destructor of the base class (0x1413b4200) belongs with the base class constructor and destructor
// (guide entity unit) and is not part of this range.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_1413a9df0#4
// MS2-RANGE: 0x1413b35e0-0x1413b4200 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1CGuideConditionSubJobCode@@UEAA@XZ 0x1413b3f00 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <assert.h>
#include <new>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/ms2recover.h"

// A reference holder with an owner pointer and a value (the guide entry reference the conditions read).
class Unk_GcSmartRef
{
public:
    Unk_GcSmartRef& FUN_1413b40b0(Unk_GcSmartRef& rhs);     // 0x1413b40b0 assignment
    void* FUN_1413b4130() const;                            // 0x1413b4130 the held value
    void FUN_140d03270();
    void FUN_140d03410();
    void* m_p0;
    void* m_p8;
};
MS2_CHECK_SIZE(Unk_GcSmartRef, 0x10);


// @0x1413b4010
Unk_GcOptInt& Unk_GcOptInt::operator=(const int& nValue)
{
    m_nValue = nValue;
    m_bSet = true;
    return *this;
}

// @0x1413b4040
Unk_GcOptVec3& Unk_GcOptVec3::operator=(const Vector3& pt)
{
    reinterpret_cast<Vector3&>(m_x) = pt;
    m_bSet = true;
    return *this;
}

// @0x1413b4080
Unk_GcOptBool& Unk_GcOptBool::operator=(const bool& bValue)
{
    m_bValue = bValue;
    m_bSet = true;
    return *this;
}

// @0x1413b40b0
Unk_GcSmartRef& Unk_GcSmartRef::FUN_1413b40b0(Unk_GcSmartRef& rhs)
{
    rhs.FUN_140d03270();
    FUN_140d03410();
    m_p8 = rhs.m_p8;
    return *this;
}

// @0x1413b4130
void* Unk_GcSmartRef::FUN_1413b4130() const
{
    return m_p8;
}

// @0x1413b4140
const Vector3& Unk_GcOptVec3::GetValue() const
{
    if (!m_bSet)
        _wassert(L"m_isValueSet", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\nullable.h", 0x6a);
    return reinterpret_cast<const Vector3&>(m_x);
}

// @0x1413b4180
Vector3& Unk_GcOptVec3::GetValue()
{
    if (!m_bSet)
        _wassert(L"m_isValueSet", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\nullable.h", 0x5c);
    return reinterpret_cast<Vector3&>(m_x);
}

// @0x1413b41c0
bool& Unk_GcOptBool::GetValue()
{
    if (!m_bSet)
        _wassert(L"m_isValueSet", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\nullable.h", 0x5c);
    return m_bValue;
}

// @0x1413b38a0
CGuideConditionDialog::~CGuideConditionDialog()
{
}

// Anchors: the destructors and the array accessor are COMDATs of this range; the destructors are implicit.
template<class T> void Unk_GcDtorAnchor(T* p)
{
    p->T::~T();
}
template void Unk_GcDtorAnchor<CGuideConditionAchieveExistTrophy>(CGuideConditionAchieveExistTrophy*);
template void Unk_GcDtorAnchor<CGuideConditionAchieveTab>(CGuideConditionAchieveTab*);
template void Unk_GcDtorAnchor<CGuideConditionActionInput>(CGuideConditionActionInput*);
template void Unk_GcDtorAnchor<CGuideConditionAllOf>(CGuideConditionAllOf*);
template void Unk_GcDtorAnchor<CGuideConditionAnyOne>(CGuideConditionAnyOne*);
template void Unk_GcDtorAnchor<CGuideConditionBattleState>(CGuideConditionBattleState*);
template void Unk_GcDtorAnchor<CGuideConditionButtonSelected>(CGuideConditionButtonSelected*);
template void Unk_GcDtorAnchor<CGuideConditionCanObserveMode>(CGuideConditionCanObserveMode*);
template void Unk_GcDtorAnchor<CGuideConditionChatEmoticon>(CGuideConditionChatEmoticon*);
template void Unk_GcDtorAnchor<CGuideConditionConstructMode>(CGuideConditionConstructMode*);
template void Unk_GcDtorAnchor<CGuideConditionConstructSlot>(CGuideConditionConstructSlot*);
template void Unk_GcDtorAnchor<CGuideConditionConstructable>(CGuideConditionConstructable*);
template void Unk_GcDtorAnchor<CGuideConditionContinentCode>(CGuideConditionContinentCode*);
template void Unk_GcDtorAnchor<CGuideConditionContract>(CGuideConditionContract*);
template void Unk_GcDtorAnchor<CGuideConditionCountInDoorInstallItem>(CGuideConditionCountInDoorInstallItem*);
template void Unk_GcDtorAnchor<CGuideConditionCountItem>(CGuideConditionCountItem*);
template void Unk_GcDtorAnchor<CGuideConditionCubeHolderSelectItem>(CGuideConditionCubeHolderSelectItem*);
template void Unk_GcDtorAnchor<CGuideConditionDead>(CGuideConditionDead*);
template void Unk_GcDtorAnchor<CGuideConditionDesignItem>(CGuideConditionDesignItem*);
template void Unk_GcDtorAnchor<CGuideConditionEnterDungeon>(CGuideConditionEnterDungeon*);
template void Unk_GcDtorAnchor<CGuideConditionEquipItem>(CGuideConditionEquipItem*);
template void Unk_GcDtorAnchor<CGuideConditionEquipSkill>(CGuideConditionEquipSkill*);
template void Unk_GcDtorAnchor<CGuideConditionExistItem>(CGuideConditionExistItem*);
template void Unk_GcDtorAnchor<CGuideConditionExistShortcut>(CGuideConditionExistShortcut*);
template void Unk_GcDtorAnchor<CGuideConditionFalse>(CGuideConditionFalse*);
template void Unk_GcDtorAnchor<CGuideConditionFieldId>(CGuideConditionFieldId*);
template void Unk_GcDtorAnchor<CGuideConditionGameScene>(CGuideConditionGameScene*);
template void Unk_GcDtorAnchor<CGuideConditionGuideClear>(CGuideConditionGuideClear*);
template void Unk_GcDtorAnchor<CGuideConditionGuideOpen>(CGuideConditionGuideOpen*);
template void Unk_GcDtorAnchor<CGuideConditionGuildPvpPeriod>(CGuideConditionGuildPvpPeriod*);
template void Unk_GcDtorAnchor<CGuideConditionHasManufacture>(CGuideConditionHasManufacture*);
template void Unk_GcDtorAnchor<CGuideConditionHasMoney>(CGuideConditionHasMoney*);
template void Unk_GcDtorAnchor<CGuideConditionHasStatPoint>(CGuideConditionHasStatPoint*);
template void Unk_GcDtorAnchor<CGuideConditionHomeMode>(CGuideConditionHomeMode*);
template void Unk_GcDtorAnchor<CGuideConditionInput>(CGuideConditionInput*);
template void Unk_GcDtorAnchor<CGuideConditionInteractObject>(CGuideConditionInteractObject*);
template void Unk_GcDtorAnchor<CGuideConditionInteractable>(CGuideConditionInteractable*);
template void Unk_GcDtorAnchor<CGuideConditionInventoryTab>(CGuideConditionInventoryTab*);
template void Unk_GcDtorAnchor<CGuideConditionIsMyHome>(CGuideConditionIsMyHome*);
template void Unk_GcDtorAnchor<CGuideConditionJobCode>(CGuideConditionJobCode*);
template void Unk_GcDtorAnchor<CGuideConditionJoinGuild>(CGuideConditionJoinGuild*);
template void Unk_GcDtorAnchor<CGuideConditionLastClosedTextTip>(CGuideConditionLastClosedTextTip*);
template void Unk_GcDtorAnchor<CGuideConditionMasteryMainTabIndex>(CGuideConditionMasteryMainTabIndex*);
template void Unk_GcDtorAnchor<CGuideConditionMasterySubTabIndex>(CGuideConditionMasterySubTabIndex*);
template void Unk_GcDtorAnchor<CGuideConditionMentoringPage>(CGuideConditionMentoringPage*);
template void Unk_GcDtorAnchor<CGuideConditionMenuExpand>(CGuideConditionMenuExpand*);
template void Unk_GcDtorAnchor<CGuideConditionMoney>(CGuideConditionMoney*);
template void Unk_GcDtorAnchor<CGuideConditionMovement>(CGuideConditionMovement*);
template void Unk_GcDtorAnchor<CGuideConditionMyPlayerLevel>(CGuideConditionMyPlayerLevel*);
template void Unk_GcDtorAnchor<CGuideConditionNext>(CGuideConditionNext*);
template void Unk_GcDtorAnchor<CGuideConditionPlaceUgcCube>(CGuideConditionPlaceUgcCube*);
template void Unk_GcDtorAnchor<CGuideConditionPlaceUgcCubeByIconType>(CGuideConditionPlaceUgcCubeByIconType*);
template void Unk_GcDtorAnchor<CGuideConditionPlaceUgcCubeItem>(CGuideConditionPlaceUgcCubeItem*);
template void Unk_GcDtorAnchor<CGuideConditionPlayInstrumentHasSelectItem>(CGuideConditionPlayInstrumentHasSelectItem*);
template void Unk_GcDtorAnchor<CGuideConditionPlayInstrumentTabIndex>(CGuideConditionPlayInstrumentTabIndex*);
template void Unk_GcDtorAnchor<CGuideConditionPlayingInstrument>(CGuideConditionPlayingInstrument*);
template void Unk_GcDtorAnchor<CGuideConditionPortalEnable>(CGuideConditionPortalEnable*);
template void Unk_GcDtorAnchor<CGuideConditionPosition>(CGuideConditionPosition*);
template void Unk_GcDtorAnchor<CGuideConditionQuestComplete>(CGuideConditionQuestComplete*);
template void Unk_GcDtorAnchor<CGuideConditionQuestProgress>(CGuideConditionQuestProgress*);
template void Unk_GcDtorAnchor<CGuideConditionQuestSatisfied>(CGuideConditionQuestSatisfied*);
template void Unk_GcDtorAnchor<CGuideConditionRealEstateExpireDays>(CGuideConditionRealEstateExpireDays*);
template void Unk_GcDtorAnchor<CGuideConditionReturnPortal>(CGuideConditionReturnPortal*);
template void Unk_GcDtorAnchor<CGuideConditionSelectItemEnchant>(CGuideConditionSelectItemEnchant*);
template void Unk_GcDtorAnchor<CGuideConditionServerTime>(CGuideConditionServerTime*);
template void Unk_GcDtorAnchor<CGuideConditionState>(CGuideConditionState*);
template void Unk_GcDtorAnchor<CGuideConditionSubJobCode>(CGuideConditionSubJobCode*);
template void Unk_GcDtorAnchor<CGuideConditionSummonPet>(CGuideConditionSummonPet*);
template void Unk_GcDtorAnchor<CGuideConditionTimeout>(CGuideConditionTimeout*);
template void Unk_GcDtorAnchor<CGuideConditionTitle>(CGuideConditionTitle*);
template void Unk_GcDtorAnchor<CGuideConditionTrigger>(CGuideConditionTrigger*);
template void Unk_GcDtorAnchor<CGuideConditionUgcCollectMoney>(CGuideConditionUgcCollectMoney*);
template void Unk_GcDtorAnchor<CGuideConditionUgcManagementTab>(CGuideConditionUgcManagementTab*);
template void Unk_GcDtorAnchor<CGuideConditionUgcProductExpireDays>(CGuideConditionUgcProductExpireDays*);

Unk_GuideCube& Unk_GcCubeAnchor(ATL::CAtlArray<Unk_GuideCube>& arr, size_t i)
{
    return arr.GetAt(i);
}
