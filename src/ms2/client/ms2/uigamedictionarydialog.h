// uigamedictionarydialog.h - the game dictionary window (RTTI UIGameDictionaryDialog, UI id 0x4f0b): a searchable list
// of the npcs, monsters and items of the game with a detail page. NOT an original header (the unit is
// ?\uigamedictionarydialog.cpp). Member names are invented from use.
#pragma once
#include <afx.h>
#include <list>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uidialog.h"

class ASData;
class Unk_DictList;
class Unk_DictTab;
class Unk_DictInput;

class UIGameDictionaryDialog : public UIDialog
{
public:
    // One row of the dictionary (0x20 bytes): an npc (type 1), a monster (2) or an item (3).
    struct Entry
    {
        Entry();                                            // 0x140f47d70
        bool operator<(const Entry& other) const;           // 0x140f48150 (the sort order: by name)

        CStringW m_name;                                    // +0x00
        int m_id;                                           // +0x08
        int m_0c;                                           // +0x0c
        int m_levelOrGrade;                                 // +0x10 monster level / item grade
        int m_type;                                         // +0x14 1 npc, 2 monster, 3 item
        int m_invisibleLevel;                               // +0x18
        unsigned m_fieldId;                                 // +0x1c the fixed field of a monster (0 = look it up)
    };

    UIGameDictionaryDialog();                               // 0x140f447d0
    virtual ~UIGameDictionaryDialog();                      // 0x140f44890
    virtual CString vfunc_1();
    virtual int vfunc_13();
    virtual void OnLoadComplete();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
    virtual int vfunc_48() { return 0x4f0b; }
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void vfunc_80(void* pRequest);

    void FUN_140f45870();                                   // fill the list with the rows of the tab that match the search
    void FUN_140f452e0();                                   // collect the rows (npcs, monsters, items), sorted by name
    void FUN_140f45c20(int nId, int nType, CStringW strName, int nGrade);   // the detail page of a row
    void FUN_140f46c90(CStringW strSearch);                 // search request
    unsigned FUN_140f46e40(int nTab);                       // the row types of a tab (bit mask)
    void FUN_140f46ea0(int nTab, CStringW strSearch, int bSelectFirst);     // open on a tab with a search text

    MS2Ptr<Unk_DictList> FUN_140c02900(const CString& strName);     // bind a list child
    MS2Ptr<Unk_DictTab> FUN_140c02870(const CString& strName);      // bind a tab child
    MS2Ptr<Unk_DictInput> FUN_140e35bd0(const CString& strName);    // find the search input

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                              // +0x178 the tab (0 all, 1 npcs, 2 monsters, 3 items)
    int m_17c;                                              // +0x17c select the first row once the list is up
    CStringW m_180;                                         // +0x180 the search text
    std::list<Entry> m_188;                                 // +0x188 the rows
};
MS2_CHECK_SIZE(UIGameDictionaryDialog::Entry, 0x20);
MS2_CHECK_SIZE(UIGameDictionaryDialog, 0x198);
MS2_CHECK_OFFSET(UIGameDictionaryDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIGameDictionaryDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIGameDictionaryDialog, m_188, 0x188);
