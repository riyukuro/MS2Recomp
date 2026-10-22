// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIQuestPostBoxDialog: see uiquestpostboxdialog.h.
// MS2-UNIT: ?\uiquestpostboxdialog.cpp
// MS2-RANGE: 0x140e7f2e0-0x140e7fd50 .text$mn
// MS2-PIN: ??_GUIQuestPostBoxDialog@@UEAAPEAXI@Z 0x140e7fd00
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquestpostboxdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiquestpostboxdialog.h"

#include <stdlib.h>
#include <atlcoll.h>
#include "uiquesteventlistener.h"                       // UIQuestEventDispatcher
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The list control of the movie (the AS list with clear / append).
class Unk_PostBoxList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                               // clear
    void FUN_1422dd230(const ASObj& row);               // append a row
};

// A CQuest as handed to the listener: the CQuestCommon base sits at +0x18 (after CPtred).
struct Unk_PbQuestView { void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_vftable_common; };

// A 16-byte script handle: ctor (id, 100) 0x1408564b0, null test 0x14085a420, copy 0x140859bc0, dtor 0x14078f140.
class Unk_PbScript
{
public:
    Unk_PbScript(int nId, int n);
    Unk_PbScript(const Unk_PbScript& o);
    ~Unk_PbScript();
    bool FUN_14085a420() const;
private:
    void* m_0; void* m_8;
};
MS2_CHECK_SIZE(Unk_PbScript, 0x10);

// The npc talk manager (singleton accessor 0x140967100).
class Unk_PbTalkMgr { public: void FUN_141b213f0(Unk_PbScript script, int nNpc, int n4, int n0); };
Unk_PbTalkMgr* FUN_140967100();

CQuestManager* FUN_140764020();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
int FUN_14074b030(CQuestData* pData);
int FUN_14074bc90(unsigned nQuestId);                   // quest kind: 0 epic, 2 event, else world
unsigned short FUN_14074bd10(int nQuestId);             // quest level
CStringW FUN_1416e5900(unsigned nQuestId, int n);       // quest title
CStringW FUN_1409e88d0(int nStringId, const unsigned short& n);    // formatted string table entry
UIQuestEventDispatcher* FUN_140bfc4b0();
int FUN_140e7fc90(const void* pa, const void* pb);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140e7f2e0
UIQuestPostBoxDialog::UIQuestPostBoxDialog()
{
    m_80 = 0;
    m_88 = 1;
    m_58 = 1;
    FUN_141924170(1);
}

// @0x140e7f390
UIQuestPostBoxDialog::~UIQuestPostBoxDialog() {}

// @0x140e7f400
CString UIQuestPostBoxDialog::GetTypeName() { return "QuestPostBoxDialog"; }
MS2_REPLACE_METHOD(0x140E7F400, UIQuestPostBoxDialog, GetTypeName, 61, 0x56EF1E4C);

// @0x140e7f450
int UIQuestPostBoxDialog::vfunc_65() { if (!UIDialog::vfunc_65()) return 0; return 1; }
MS2_REPLACE_METHOD(0x140E7F450, UIQuestPostBoxDialog, vfunc_65, 37, 0x65811C24);

// @0x140e7f480
void UIQuestPostBoxDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140bfc4b0()->FUN_141aa8850(this);
}
MS2_REPLACE_METHOD(0x140E7F480, UIQuestPostBoxDialog, vfunc_67, 77, 0x335B0AE4);

// @0x140e7f4e0
void UIQuestPostBoxDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140e7f660();
    FUN_140bfc4b0()->FUN_141aa87c0(this);
}
MS2_REPLACE_METHOD(0x140E7F4E0, UIQuestPostBoxDialog, OnLoadComplete, 87, 0x783BB0F8);

// @0x140e7f540
int UIQuestPostBoxDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    ASData unused;
    if (!_stricmp("onSelectPost", szMethod)) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nQuest = data.FUN_1422b8b10();
            FUN_140e7f920(nQuest);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E7F540, UIQuestPostBoxDialog, vfunc_28, 268, 0x60E4B318);

// MS2-FUNCTIONAL: qsort count argument is loaded through rcx in the exe (mov rcx,[n]; mov rdx,rcx), no source form found.
// @0x140e7f660
void UIQuestPostBoxDialog::FUN_140e7f660()
{
    if (MS2Ptr<Unk_PostBoxList> list = FUN_140c02900("m_list")) {
        list->FUN_1422dd1d0();
        ATL::CAtlArray<unsigned> quests;
        FUN_140764020()->FUN_1416d0920(quests);
        size_t nCount = quests.GetCount();
        qsort(quests.GetData(), (size_t)nCount, 4, FUN_140e7fc90);
        for (size_t i = 0; i < quests.GetCount(); ++i) {
            unsigned nQuest = quests[i];
            ASObj row(2);
            row.FUN_1407cbb20("label", FUN_1416e5900(nQuest, 0));
            row.FUN_1407cbb20("level", FUN_1409e88d0(0x459, FUN_14074bd10(nQuest)));
            row.FUN_1409c0d20("id", nQuest);
            row.FUN_1407cba60("icon", FUN_140e7fb90(nQuest));
            list->FUN_1422dd230(row);
        }
        list->vfunc_24(true);
    }
}

// @0x140e7f920
void UIQuestPostBoxDialog::FUN_140e7f920(int nQuest)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(nQuest);
    if (data.IsNull()) return;
    Unk_PbScript script(FUN_14074b030(data.operator->()), 100);
    if (script.FUN_14085a420()) return;
    FUN_140967100()->FUN_141b213f0(script, data->m_2e8, 4, 0);
}
MS2_REPLACE_METHOD(0x140E7F920, UIQuestPostBoxDialog, FUN_140e7f920, 282, 0x7DFA22B7);

// @0x140e7fa40
void UIQuestPostBoxDialog::vfunc_o178_1(void* pQuest)
{
    if (pQuest == 0) return;
    if (((CQuestCommon*)&((Unk_PbQuestView*)pQuest)->m_vftable_common)->GetData().IsNull()) return;
    if (!((CQuestCommon*)&((Unk_PbQuestView*)pQuest)->m_vftable_common)->GetData()->m_33) return;
    vfunc_67();
}
MS2_REPLACE_METHOD_VIA(0x140E7FA40, UIQuestPostBoxDialog, UIQuestEventListener, vfunc_o178_1, 320, 0x6D6D449C);

// @0x140e7fb90
CString UIQuestPostBoxDialog::FUN_140e7fb90(int nQuest)
{
    switch (FUN_14074bc90(nQuest)) {
    case 0: return "epic";
    case 2: return "event";
    default: return "world";
    }
}
MS2_REPLACE_METHOD(0x140E7FB90, UIQuestPostBoxDialog, FUN_140e7fb90, 167, 0x6346681A);

// @0x140e7fc40
int FUN_140e7fc40(unsigned nQuest)
{
    switch (FUN_14074bc90(nQuest)) {
    case 0: return 1;
    case 2: return 2;
    default: return 3;
    }
}

// MS2-FUNCTIONAL: the exe loads the first count into ecx before the compare; no source form found.
// @0x140e7fc90
int FUN_140e7fc90(const void* pa, const void* pb)
{
    const unsigned* pA = (const unsigned*)pa;
    const unsigned* pB = (const unsigned*)pb;
    int nA = FUN_140e7fc40(*pA);
    int nResult;
    if (nA < FUN_140e7fc40(*pB)) nResult = -1;
    else nResult = 1;
    return nResult;
}
