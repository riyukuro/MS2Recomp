// characterability.h - PLACEHOLDER for the character ability table (RTTI .?AVCCharacterAbilityTable@@ 0xf0 bytes, with its rows
// CCharacterAbilityCategory 0x78 and CCharacterAbility 0x30). NOT an original header; names of members assumed from the xml
// attributes. Loads Table\CharacterAbilityCategory.xml and Table\CharacterAbility.xml. Recovered in ?\characterability.cpp.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

// One ability <ability id= categoryID= requireLevel= additionalEffectID= additionalEffectLevel=>.
class CCharacterAbility : public CPtred
{
public:
    CCharacterAbility();                                    // 0x1401df430
    virtual ~CCharacterAbility() {}                         //  0 0x1401df4a0 (??_G 0x1401e1450)
    unsigned int m_nId;                                     // +0x18 "id"
    unsigned int m_nCategoryId;                             // +0x1c "categoryID"
    unsigned short m_nRequireLevel;                         // +0x20 "requireLevel"
    unsigned short m_pad_22;
    unsigned int m_nAdditionalEffectId;                     // +0x24 "additionalEffectID"
    unsigned short m_nAdditionalEffectLevel;                // +0x28 "additionalEffectLevel"
};
MS2_CHECK_SIZE(CCharacterAbility, 0x30);

// One category <category id= name= tooltip=> with its abilities.
class CCharacterAbilityCategory : public CPtred
{
public:
    CCharacterAbilityCategory();                            // 0x1401df4d0
    virtual ~CCharacterAbilityCategory() {}                 //  0 0x1401df570 (??_G 0x1401e1490)
    unsigned int m_nId;                                     // +0x18 "id"
    CStringW m_strName;                                     // +0x20 "name"
    CStringW m_strTooltip;                                  // +0x28 "tooltip"
    ATL::CAtlMap<unsigned int, MS2Ptr<CCharacterAbility> > m_abilities;     // +0x30
};
MS2_CHECK_SIZE(CCharacterAbilityCategory, 0x78);

class CCharacterAbilityTable : public TSingleton<CCharacterAbilityTable>,
                               public CValidData<CCharacterAbilityTable>
{
public:
    CCharacterAbilityTable();                               // 0x1401df5e0
    virtual ~CCharacterAbilityTable();                      //  0 0x1401df700 (??_G 0x1401e14d0)
    int FUN_1401df7b0();                                    // (re)loads both files
    int LoadCharacterAbilityCategory();                                    // CharacterAbilityCategory.xml
    int LoadCharacterAbility();                                    // CharacterAbility.xml
    void FUN_1401e0350(ATL::CAtlList<MS2Ptr<CCharacterAbilityCategory> >* pOut);
    void FUN_1401e0450(ATL::CAtlList<MS2Ptr<CCharacterAbility> >* pOut);
    MS2Ptr<CCharacterAbilityCategory> FUN_1401e0560(int nId);
    MS2Ptr<CCharacterAbility> FUN_1401e0670(int nId);
    static void CheckInit();                                // 0x1401e1690
    static void SetInit(bool b);                            // 0x1401e3b00
    static bool s_bInit;                                    // 0x143aac650
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x10
    MS2Ptr<CCacheData> m_spCategoryCache;                   // +0x40
    MS2Ptr<CCacheData> m_spAbilityCache;                    // +0x50
    ATL::CAtlMap<unsigned int, MS2Ptr<CCharacterAbilityCategory> > m_categories;    // +0x60
    ATL::CAtlMap<unsigned int, MS2Ptr<CCharacterAbility> > m_abilities;             // +0xa8
};
MS2_CHECK_SIZE(CCharacterAbilityTable, 0xf0);
