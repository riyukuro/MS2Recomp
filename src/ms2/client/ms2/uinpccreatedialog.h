// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uinpccreatedialog.h (name assumed: the
// exe has no __FILE__ string for this unit).
//
// UINpcCreateDialog ("NpcCreateDialog", UI type 0x4e46, RTTI .?AVUINpcCreateDialog@@, 0x1c0 bytes): the debug "create an
// npc" list. The npc ids come from every <npc id=".."/> of the xml files in ./Data/Xml/NpcData/; the movie sends
// "OnNpcCreate" / "OnSummonPet" (the npc is created through a packet), "OnReleasePet" and "OnMoveToNpc" (walk or
// teleport to the field the npc lives in) and "OnSearchNpc" (a filter text that refills "m_npcList"). Bases: UIDialog
// at +0 and the UIEntityEventListener at +0x178 (it cancels a pending move once the npc is reached). Names: virtuals
// are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiupperhpbar.h"        // UIEntityEventListener
#include "ms2/placeholder/ascript.h"

class Unk_NpcList;

// One row of the npc list: the id text (the file's npc id), the lower-cased name with the spaces removed (what the
// filter matches) and the line shown in the list.
struct Unk_NpcEntry
{
    CStringW m_strId;
    CStringW m_strSearch;
    CStringW m_strLine;
};
MS2_CHECK_SIZE(Unk_NpcEntry, 0x18);

// The id strings read from the xml files: a vector-like wrapper whose ctor / dtor / accessors live outside this unit.
class Unk_NpcFileList
{
public:
    Unk_NpcFileList();                                  // 0x1403e3920
    ~Unk_NpcFileList();                                 // 0x1403e5850
    unsigned __int64 FUN_14041af10() const;             // count
    CStringW& FUN_1405e99b0(unsigned __int64 i);        // operator[]
    void FUN_14041ada0(const CStringW& str);            // push_back
    void FUN_141a6dd40();                               // clear
private:
    std::vector<CStringW> m_v;
};
MS2_CHECK_SIZE(Unk_NpcFileList, 0x18);

class UINpcCreateDialog : public UIDialog, public UIEntityEventListener
{
public:
    UINpcCreateDialog();                                // 0x141a6a470
    virtual ~UINpcCreateDialog();                       //  0 0x141a6a590 (??_G 0x141a6d600)
    virtual CString vfunc_1();                          //  1 0x141a6a680 "NpcCreateDialog"
    virtual int vfunc_13();                             // 13 0x141a6a730 enter / tab / escape keys
    virtual void OnLoadComplete();                      // 22 0x141a6a6d0 read the npc files, then fill the list
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                        // 28 0x141a6a870
    virtual int vfunc_48() { return 0x4e46; }           // 48 0x141a6d640 UI type id
    virtual void vfunc_1(void* pEvt);                   // UIEntityEventListener 1 0x141a6b030
    virtual void vfunc_3(void* pActor);                 // UIEntityEventListener 3 0x141a6b1a0

    void ReadNpcFromFile();                               // read the npc ids of the xml files
    CStringW FUN_141a6b6a0(int nType, int bFriendly);   // npc kind name
    void FUN_141a6b800();                               // log + preload every npc
    void FUN_141a6b8f0();                               // build m_entries
    void FUN_141a6be40(const CStringW& strFilter);      // refill "m_npcList"
    MS2Ptr<Unk_NpcList> FUN_140c02900(const CString& strName);     // bind a list child of the movie

private:
    MS2_LAYOUT_FRIEND;
    Unk_NpcFileList m_files;                            // +0x180 the npc ids
    int m_nPendingNpc;                                  // +0x198 npc to walk to (0 = none)
    bool m_bFilesRead;                                  // +0x19c
    bool m_bEntriesBuilt;                               // +0x19d
    CStringW m_strFilter;                               // +0x1a0 the last search filter
    std::vector<Unk_NpcEntry> m_entries;                // +0x1a8
};
MS2_CHECK_SIZE(UINpcCreateDialog, 0x1c0);
