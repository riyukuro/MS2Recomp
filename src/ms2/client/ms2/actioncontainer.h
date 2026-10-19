// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\actioncontainer.h (name assumed: the
// unit name; the exe asserts only in actioncontainer.cpp and commonfiles\datatable.h).
//
// The player character action names (Table\PCActionData.xml): a group maps the 75 action types (ActionType) to a list of
// animation names. The default group (groupID 0) lists every type; a custom group overrides some types and falls back to
// the default one. PCActionDataTable is the TSingleton that loads the file (CGameApp::InitInstance creates it).
// RTTI .?AVPCActionList@@ (0x30 bytes), .?AVPCActionGroup@@ (abstract, 0x18), .?AVPCActionGroupDefault@@ (0x30),
// .?AVPCActionGroupCustom@@ (0x38), .?AVPCActionDataTable@@ (0x60).
// Names: invented from use (the exe has no names for the methods; slots follow the vftable order).
#pragma once

#include <afx.h>

#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/datatable.h"

class Unk_140165cf0;

// The number of action types ActionType can return (75 itself means "unknown").
const int kPCActionTypes = 75;

// The animation names of one action type.
class PCActionList : public CPtred
{
public:
    PCActionList();                                         // 0x140948420
    void Load(Unk_140165cf0* pNode);                        // 0x140948470 the <names> attribute
    int RandomIndex();                                      // -1 when empty
    CStringA RandomName();
    CStringA Name(unsigned nIndex);
    unsigned __int64 Count();
    std::vector<CStringA>& Values();
private:
    MS2_LAYOUT_FRIEND;
    std::vector<CStringA> m_names;                          // +0x18
};
MS2_CHECK_SIZE(PCActionList, 0x30);

class PCActionGroup : public CPtred
{
public:
    PCActionGroup();                                        // 0x14094d9f0
    virtual int Id() = 0;                                   //  1
    virtual void LoadXml(Unk_140165cf0* pNode) = 0;         //  2
    virtual unsigned __int64 Count(int nType) const = 0;          //  3
    virtual int RandomIndex(int nType) const = 0;                 //  4
    virtual CStringA RandomName(int nType) const = 0;             //  5
    virtual CStringA Name(int nType, unsigned nIndex) const = 0;  //  6
    virtual std::vector<CStringA>& Values(int nType) const = 0;   //  7
};
MS2_CHECK_SIZE(PCActionGroup, 0x18);

class PCActionGroupDefault : public PCActionGroup
{
public:
    PCActionGroupDefault();                                 // 0x140948690
    virtual int Id();
    virtual void LoadXml(Unk_140165cf0* pNode);
    virtual unsigned __int64 Count(int nType) const;
    virtual int RandomIndex(int nType) const;
    virtual CStringA RandomName(int nType) const;
    virtual CStringA Name(int nType, unsigned nIndex) const;
    virtual std::vector<CStringA>& Values(int nType) const;
private:
    MS2_LAYOUT_FRIEND;
    std::vector<MS2Ptr<PCActionList> > m_lists;             // +0x18 indexed by action type
};
MS2_CHECK_SIZE(PCActionGroupDefault, 0x30);

class PCActionGroupCustom : public PCActionGroup
{
public:
    explicit PCActionGroupCustom(PCActionGroup* pFallback); // 0x140948af0
    virtual int Id();
    virtual void LoadXml(Unk_140165cf0* pNode);
    virtual unsigned __int64 Count(int nType) const;
    virtual int RandomIndex(int nType) const;
    virtual CStringA RandomName(int nType) const;
    virtual CStringA Name(int nType, unsigned nIndex) const;
    virtual std::vector<CStringA>& Values(int nType) const;
private:
    MS2_LAYOUT_FRIEND;
    unsigned m_nId;                                         // +0x18 groupID
    std::map<int, MS2Ptr<PCActionList> > m_lists;           // +0x20 the overridden types
    PCActionGroup* m_pFallback;                             // +0x30 the default group
};
MS2_CHECK_SIZE(PCActionGroupCustom, 0x38);

class PCActionDataTable : public TSingleton<PCActionDataTable>, public DataTable<PCActionGroup>
{
public:
    PCActionDataTable();                                    // 0x140949170
    virtual ~PCActionDataTable();
    virtual void Add(MS2Ptr<PCActionGroup> spRow);          // 0x1409492b0
    virtual void Loaded();                                  // 0x1409493a0
    virtual MS2Ptr<PCActionGroup> Create(Unk_140165cf0* pNode);   // 0x1409493b0
    MS2Ptr<PCActionGroup> Find(int nId);               // 0x1409494e0 the group, the default group when unknown
private:
    MS2_LAYOUT_FRIEND;
    std::map<int, MS2Ptr<PCActionGroup> > m_groups;         // +0x40 the custom groups by id
    MS2Ptr<PCActionGroup> m_spDefault;                      // +0x50
};
MS2_CHECK_SIZE(PCActionDataTable, 0x60);

int ReadAction(Unk_140165cf0* pNode, const char* szName, int* pnType);   // 0x14094a400 the action type attribute
int ActionType(const CStringA& strName);                    // 0x140949600 the action type of a name, kPCActionTypes when unknown
