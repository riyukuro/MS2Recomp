// cgamemenutable.h - CGameMenuTable / CGameMenuDef / CGameMenuItem (RTTI names), the game menu definitions and the
// menu trees read from Table/gameMenu.xml. Recovered with the second original TU inside units.tsv's
// client\ms2\gameeventmanagercli.cpp range (0x140cf08d0-0x140cfad00); NOT an original header (its name is assumed).
// Member names are invented from their use (uigamemenudialog / uigamepadmenudialog read them).
#pragma once

#include <atlcoll.h>
#include <atlstr.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/tfunctor.h"

class Unk_140165cf0;
class NotifyGameEventChanged;

// How a menu tree node decides that it is shown (gameMenu.xml "filterType").
enum EGameMenuFilter
{
    GAMEMENU_FILTER_NONE = 0,
    GAMEMENU_FILTER_EVENT_ID = 1,       // "eventID": the game event m_nFilterEventId is running
    GAMEMENU_FILTER_EVENT_TYPE = 2,     // "eventType": an event named m_strFilterValue is running
    GAMEMENU_FILTER_ATTEND_GIFT = 3,    // "attendGift"
    GAMEMENU_FILTER_CASH_ATTEND = 4,    // "cashAttend"
    GAMEMENU_FILTER_SEASON = 5,         // "season": the season m_strFilterValue is open
};

// The menu trees of gameMenu.xml ("menuSet" type).
enum EGameMenuSet
{
    GAMEMENU_SET_GAME = 0,              // "game"
    GAMEMENU_SET_GAMEPAD = 1,           // "gamePad"
    GAMEMENU_SET_MUSHKING_ROYAL = 2,    // "mushkingRoyal"
    GAMEMENU_SET_MUSHKING_ROYAL_PAD = 3,   // "mushkingRoyalPad"
    GAMEMENU_SET_COUNT = 4,
};

// One menu entry (0x70, vftable 0x142e23bc8): what the button shows and does.
class CGameMenuDef : public CPtred
{
public:
    // @0x140cf8fa0
    CGameMenuDef() : m_nId(0), m_28(0), m_nKeyBind(0), m_nUiId(0) {}

    int m_nId;                                              // +0x18
    CString m_strName;                                      // +0x20 "worldmap", ...
    int m_28;                                               // +0x28
    TFunctor<void, EmptyParam> m_onClick;                   // +0x30
    TFunctor<int, EmptyParam> m_hasNew;                     // +0x38
    TFunctor<int, EmptyParam> m_isEnabled;                  // +0x40
    CStringW m_strTooltip;                                  // +0x48 string key
    CStringW m_strDisabledTooltip;                          // +0x50 string key
    int m_nKeyBind;                                         // +0x58 key table command
    CString m_strLabel;                                     // +0x60 "$s_gamemenu_btn_..."
    int m_nUiId;                                            // +0x68 dialog opened by the entry
};
MS2_CHECK_SIZE(CGameMenuDef, 0x70);

// One node of a menu tree (0x60, vftable 0x142e23b80).
class CGameMenuItem : public CPtred
{
public:
    CGameMenuItem();                                        // 0x140cf08d0
    void Load(Unk_140165cf0* pElem);                        // 0x140cf0970
    bool HasId(int nId);                                    // 0x140cf0b50 this node or a descendant is the entry
    bool IsVisible();                                       // 0x140cf0bf0 the filter passes
    bool IsAffectedBy(NotifyGameEventChanged* pNotify);     // 0x140cf0e90 the event change touches this subtree

    int m_nId;                                              // +0x18 CGameMenuDef id
    ATL::CAtlArray<MS2Ptr<CGameMenuItem> > m_children;      // +0x20
    int m_nRow;                                             // +0x40
    int m_nCol;                                             // +0x44
    int m_nOnlyRPG;                                         // +0x48
    EGameMenuFilter m_eFilterType;                          // +0x4c
    CStringW m_strFilterValue;                              // +0x50
    int m_nFilterEventId;                                   // +0x58 m_strFilterValue as a number
};
MS2_CHECK_SIZE(CGameMenuItem, 0x60);

// The table (0xb8, vftable 0x142e23be8): entry id -> definition, and the four menu trees.
class CGameMenuTable : public TSingleton<CGameMenuTable>
{
public:
    CGameMenuTable();                                       // 0x140cf0fd0
    virtual ~CGameMenuTable();                              // 0x140cf1060
    int Init();                                             // 0x140cf10d0
    int RegisterDefs();                                     // 0x140cf1110
    int LoadXml();                                          // 0x140cf6ef0
    int IsChild(int nId, EGameMenuSet eSet) const;         // 0x140cf71f0 the entry is not a top level node
    int IsAffectedBy(NotifyGameEventChanged* pNotify, EGameMenuSet eSet) const;   // 0x140cf7250
    int FindTopId(int nId, EGameMenuSet eSet) const;        // 0x140cf72f0 the top level node holding the entry
    int FindIdByUiId(int nUiId);                            // 0x140cf73a0
    MS2Ptr<CGameMenuDef> FindByName(CString strName);       // 0x140cf7470
    MS2Ptr<CGameMenuDef> FindByUiId(int nUiId);             // 0x140cf7590
    MS2Ptr<CGameMenuDef> Find(int nId);                     // 0x140cf7690
    void GetTopItems(ATL::CAtlArray<MS2Ptr<CGameMenuItem> >& out, EGameMenuSet eSet) const;   // 0x140cf7710
    MS2Ptr<CGameMenuItem> FindTopItem(int nId, EGameMenuSet eSet) const;    // 0x140cf77a0
    MS2Ptr<CGameMenuItem> FindItem(int nId, EGameMenuSet eSet) const;       // 0x140cf78a0 top level or one below

    ATL::CRBMap<int, MS2Ptr<CGameMenuDef>, ATL::CDefaultElementTraits<int> > m_defs;   // +0x08 (key by const&)
    ATL::CAtlArray<MS2Ptr<CGameMenuItem> > m_sets[GAMEMENU_SET_COUNT];   // +0x38
};
MS2_CHECK_SIZE(CGameMenuTable, 0xb8);

EGameMenuFilter ParseGameMenuFilter(const CStringA& str);  // 0x140cf7a60
EGameMenuSet ParseGameMenuSet(const CStringA& str);        // 0x140cf7b30
