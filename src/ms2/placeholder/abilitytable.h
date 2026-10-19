// abilitytable.h - PLACEHOLDER for the character ability table rows (read from the exe's ability table singleton).
// NOT an original header. Names assumed. Shared by CCharacterAbilityManager and UICharacterAbilityDialog.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

// One ability (skill) of a category.
class Unk_CaAbilityRow : public CPtred
{
public:
    int m_nId;                                          // +0x18
    int m_nCategory;                                    // +0x1c
    unsigned short m_nRequireLevel;                     // +0x20
    unsigned short m_pad_22;
    int m_nSkillId;                                     // +0x24
    unsigned short m_nSkillLevel;                       // +0x28
};

// The abilities of a category, as the not-yet-recovered table unit stores them (CAtlList of 0x30 bytes).
class Unk_CaAbilityList
{
public:
    int FUN_1401e2540() const;                          // empty
    POSITION FUN_1401e2140() const;                     // head position
    const MS2Ptr<Unk_CaAbilityRow>& FUN_1401e2220(POSITION pos) const;   // GetAt (returns pos->m_element by reference)
    void FUN_1401e1ec0(POSITION& pos) const;           // next
    char m_pad[0x30];
};

// One category of abilities.
class Unk_CaCategoryRow : public CPtred
{
public:
    int m_nId;                                          // +0x18
    int m_pad_1c;
    CStringW m_strName;                                 // +0x20 sent with "buildCategory"
    CStringW m_strTooltip;                              // +0x28 shown in the tooltip of the category icon
    Unk_CaAbilityList m_abilities;                      // +0x30
};

// The ability table (singleton of the exe).
class Unk_CaTable
{
public:
    MS2Ptr<Unk_CaCategoryRow> FUN_1401e0560(int nId);
    MS2Ptr<Unk_CaAbilityRow> FUN_1401e0670(int nId);
    void FUN_1401e0350(ATL::CAtlList<MS2Ptr<Unk_CaCategoryRow> >* pOut);
    void FUN_1401e0450(ATL::CAtlList<MS2Ptr<Unk_CaAbilityRow> >* pOut);
};
