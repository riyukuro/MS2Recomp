// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Quest debug dialog; incomplete recovery.
// MS2-UNIT: client\ms2\uiquestdebugdialog.cpp
// MS2-RANGE: 0x141a92ed0-0x141a993a0 .text$mn
// MS2-RANGE: 0x14011afa0-0x14011b110 .text$di
// MS2-RANGE: 0x142cc1830-0x142cc18b5 .text$yd
// MS2-PIN: ?vfunc_48@UIQuestDebugDialog@@UEAAHXZ 0x141a99240
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquestdebugdialog.cpp"
// The ASUIComponent slot list (validateNow = 24) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "uiquestdebugdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include <vector>
#include <algorithm>
#include "ms2/placeholder/cquestmanagercommon.h"
#include "ms2/placeholder/cinputkeyhandler.h"  // C3: CInputKeyHandler::FUN_14116d9c0
#include "ms2/placeholder/astextinput.h"   // C3: ASTextInput::FUN_1422e0b00
#include "ms2/placeholder/astextarea.h"   // C3: MS2Ptr<ASTextArea> (GetChild<ASTextArea> COMDAT 0x140c26f60)
#include "ms2/placeholder/asbutton.h"   // C3: ASButton::FUN_1422ce0e0
#include "ms2/placeholder/ascorelist.h"   // C3: ASCoreList::SetSelectedIndex
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/mstime.h"
#include <atlfile.h>

// Unit-local declarations, pending recovery of the quest data and AS wrapper units.
class UIQuestEventDispatcher* FUN_140bfc4b0();   // C3: was FUN_140bfc4b0
class GFxManager { public: CStringW Localize(const CString& strKey); };   // C3: the real member (0x1422b0570, a $-key's localized string)
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: the GFxManager (calls cast back)
class Unk_QuestDebugAccess : public CInputKeyHandler {};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
// The exe's non-null test of a condition parameter's CConditionDictPtr (0x141a99100), a separate copy of get().
class Unk_QuestDebugHandle
{
public:
    // @0x141a99100
    void* FUN_141a99100() const { return m_p; }
private:
    void* m_0;
    void* m_p;
};
MS2Ptr<CQuestData> FUN_14074bc40(int);
int FUN_14074b030(CQuestData*);
CStringW FUN_1416e4df0(int);
CStringW FUN_1416e5900(int, bool);
CStringW FUN_1416e7fb0(int);
CStringW FUN_1401aa6a0(int);
CStringW GetStringCommon(int);
__int64 FUN_140761ba0(int, int);
__int64 FUN_140761cc0(int, int);
void FUN_1416e5890(int, ATL::CAtlArray<CStringW>&);
int FUN_1416e6100(int, int);
class Unk_QuestDebugState
{
public:
};
class Unk_QuestDebugGlobal { public: void* m_0; void* m_8; Unk_QuestDebugState state; };
void* FUN_140764020();   // C3: was FUN_140764020
class Unk_QuestDebugMap : public ATL::CAtlMap<CString, CString, ATL::CStringElementTraitsI<CString>> {};
void FUN_140761f00(const CStringW&, int);
extern template CStringW StringFormat<CStringW, unsigned int>(const wchar_t*, const CStringW&, const unsigned int&);
extern template CStringW StringFormat<unsigned int>(const wchar_t*, const unsigned int&);
template <class T> CString Unk_SocketFormat(const char* szFormat, const T& n);   // C3: was FUN_140513200
CString FUN_14016a600(const wchar_t*, int);
CStringW FUN_14016a730(const char*, int);
void FUN_1412751b0(const CStringW&, int);
__int64 GetServerTime();
class Unk_QuestDebugMap;
CStringW FUN_141a97770(Unk_QuestDebugMap*);
// Comparator's by-value intrusive pointers reproduce the original cleanup states.
struct Unk_QuestDebugSort
{
    unsigned int standard;
    // @0x141a99110
    bool operator()(MS2Ptr<CQuestData> a, MS2Ptr<CQuestData> b) const
    {
        unsigned short left, right;
        if (standard) { left = (unsigned short)a->m_level; right = (unsigned short)b->m_level; }
        else { left = a->m_require.m_level; right = b->m_require.m_level; }
        if (!left) left = 100;
        if (!right) right = 100;
        return left < right;
    }
};

// @0x141a99090
template<> inline MS2Ptr<ASScrollingList>& MS2Ptr<ASScrollingList>::AssignRaw(ASScrollingList* p)
{
    MS2Ptr tmp(p);
    ASScrollingList* old = m_p;
    m_p = tmp.m_p;
    tmp.m_p = old;
    return *this;
}

// @0x141a92ed0
UIQuestDebugDialog::UIQuestDebugDialog()
{
    m_refresh = 0;
    m_40 = 1;
    FUN_1422dc3b0(1);
    ((class UIQuestEventDispatcher*)FUN_140bfc4b0())->FUN_141aa87c0(this);
}
// @0x141a92fd0
UIQuestDebugDialog::~UIQuestDebugDialog()
{
    ((class UIQuestEventDispatcher*)FUN_140bfc4b0())->FUN_141aa8850(this);
}
// @0x141a930a0
CString UIQuestDebugDialog::GetTypeName() { return "QuestDebugDialog"; }
MS2_REPLACE_METHOD(0x141A930A0, UIQuestDebugDialog, GetTypeName, 61, 0x98C8DB38);

// @0x141a930f0
void UIQuestDebugDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    do {
    m_30->FUN_140bc7340("m_quests", m_quests);
    if (m_quests == 0) {
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(40), __FUNCTION__));
    }
    } while (0);
    m_refresh = 0;
    m_chapter = 0;
    FUN_141a95010();
    FUN_141a95310(m_chapter, 0);
}
MS2_REPLACE_METHOD(0x141A930F0, UIQuestDebugDialog, OnLoadComplete, 487, 0x8DFD3C19);

// @0x141a93300
void UIQuestDebugDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_quests.AssignRaw(0);
}
MS2_REPLACE_METHOD(0x141A93300, UIQuestDebugDialog, vfunc_26, 45, 0x6E6AEC38);

// @0x141a93340
int UIQuestDebugDialog::vfunc_28(const char* method, const Scaleform::GFx::Value* args, unsigned int count)
{
    UIDialog::vfunc_28(method, args, count);
    ASData data;
    if (_stricmp("OnChapterChange", method) == 0) {
        if (data.SetArgsIfAny(args, count)) {
            m_chapter = data.PopInt();
            FUN_141a95010();
            FUN_141a95310(m_chapter, 0);
        }
        return 1;
    } else if (_stricmp("OnSearchItem", method) == 0) {
        FUN_141a95010();
        FUN_141a95310(0, 1);
    } else if (_stricmp("OnModifyQuest", method) == 0) {
        if (data.SetArgsIfAny(args, count)) {
            int id;
            CStringW quest = data.FUN_1422b8f40();
            id = data.PopUInt();
            FUN_140761f00(quest, id);
        }
        return 1;
    } else if (_stricmp("OnChangeQuest", method) == 0) {
        if (data.SetArgsIfAny(args, count)) {
            unsigned int id = data.PopUInt();
            MS2Ptr<CQuestData> quest = FUN_14074bc40(id);
            if (quest.IsNull()) return 1;
            void* actor = WorldService::GetInstance()->FUN_141bd0cc0();
            if (!actor) return 1;
            if (MS2Ptr<ASTextArea> desc = GetChild<ASTextArea>("m_desc")) {
                CStringW text;
                CStringW expLabel = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_quest_debug_desc_exp");
                CStringW mesoLabel = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_quest_debug_desc_meso");
                CStringW statLabel = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_quest_debug_desc_stat_point");
                CStringW skillLabel = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_quest_debug_desc_skill_point");
                text += StringFormat<__int64>(expLabel, FUN_140761ba0(id, 1));
                text += StringFormat<__int64>(mesoLabel, FUN_140761cc0(id, 1));
                if (quest->m_require.m_quest.GetCount()) {
                    text += L"\nPreceding Quest\n";
                    for (size_t i = 0; i < quest->m_require.m_quest.GetCount(); ++i) {
                        unsigned int reqId = quest->m_require.m_quest[i];
                        text += StringFormat<CStringW, unsigned int>(L"{0}({1})\n", FUN_1416e4df0(reqId), reqId);
                    }
                }
                if (quest->m_2e8 != 0) {
                    CStringW label = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_quest_debug_desc_start_npc");
                    text += StringFormat<CStringW, unsigned int>(label, FUN_1401aa6a0(quest->m_2e8), reinterpret_cast<unsigned&>(quest->m_2e8));
                }
                if (quest->m_2ec != 0) {
                    CStringW label = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_quest_debug_desc_complate_npc");
                    text += StringFormat<CStringW, unsigned int>(label, FUN_1401aa6a0(quest->m_2ec), reinterpret_cast<unsigned&>(quest->m_2ec));
                }
                size_t condCount = quest->m_conditions.GetCount();
                for (size_t i = 0; i < condCount; ++i) {
                    MS2Ptr<CConditionCommonData> cond = quest->m_conditions[i];
                    if (cond.IsNull()) continue;
                    {
                        CConditionDictPtr codes(cond.operator->()->m_code.m_dict);
                        if (reinterpret_cast<Unk_QuestDebugHandle&>(codes).FUN_141a99100()) {
                            text += L"\n[Codes]\n";
                            text += FUN_141a97770((Unk_QuestDebugMap*)codes.get());
                        }
                    }
                    {
                        CConditionDictPtr targets(cond.operator->()->m_target.m_dict);
                        if (reinterpret_cast<Unk_QuestDebugHandle&>(targets).FUN_141a99100()) {
                            text += L"\n[Targets]\n";
                            text += FUN_141a97770((Unk_QuestDebugMap*)targets.get());
                        }
                    }
                }
                desc->SetTextW(text);
            }
        }
    } else if (_stricmp("onReqQuest", method) == 0) {
        if (data.SetArgsIfAny(args, count)) {
            unsigned int id = data.PopUInt();
            MS2Ptr<CQuestData> quest = FUN_14074bc40(id);
            if (quest.get()) {
                CStringW list;
                for (size_t i = 0; i < quest->m_require.m_quest.GetCount(); ++i) {
                    if (reinterpret_cast<CQuestManagerCommon*>(&((class Unk_QuestDebugGlobal*)FUN_140764020())->state)->FUN_140745590(quest->m_require.m_quest[i]) == 0) {
                        if (list.GetLength() != 0) list += L",";
                        list += StringFormat<unsigned int>(L"{0}", quest->m_require.m_quest[i]);
                    }
                }
                if (list.GetLength() != 0) FUN_140761f00(list, 2);
            }
        }
    } else if (_stricmp("onXml", method) == 0) {
        if (data.SetArgsIfAny(args, count)) {
            unsigned int id = data.PopUInt();
            CString path;
            path.Format("./Data/Xml/Quest/%08d.xml", id);
            path.Replace('/', '\\');
            ShellExecuteA(NULL, "open", path, NULL, NULL, 1);
        }
    } else if (_stricmp("onExcel", method) == 0) {
        if (data.SetArgsIfAny(args, count)) {
            unsigned int id = data.PopUInt();
            char dir[260] = {0};
            if (GetEnvironmentVariableA("MS2EXCEL", dir, 260) > 0) {
                CString file;
                if (id < 20000000) file = "Quest_Nam2.xlsx";
                else if (id < 30000000) file = "Quest_Jang.xlsx";
                else if (id < 40000000) file = "Quest_Son.xlsx";
                else if (id < 50000000) file = "Quest_Goo.xlsx";
                else if (id < 60000000) file = "Quest_Park.xlsx";
                else if (id < 70000000) file = "Quest_Chun.xlsx";
                else if (id < 72000000) file = "Quest_DailyMission.xlsx";
                else if (id < 73000000) file = "fieldMission.xlsx";
                else if (id < 80000000) file = "Quest_Guild.xlsx";
                else if (id < 90000000) file = "Quest\\kr\\Quest_EventKR.xlsx";
                else if (id < 91000000) file = "Quest_Guide.xlsx";
                else file = "Quest_FameContents.xlsx";
                CString args2;
                args2.Format("%s\\%s", dir, (const char*)file);
                ShellExecuteA(NULL, "open", "Excel.exe", args2, NULL, 1);
            }
        }
    } else if (_stricmp("onExport", method) == 0) {
        CMsTime now(GetServerTime());
        int second = now.GetSecond();
        int minute = now.GetMinute();
        int hour = now.GetHour();
        CString fileName = StringFormat<int, int, int>(".\\log\\client\\quest_export_{0:02d}{1:02d}{2:02d}.csv", hour, minute, second);
        ATL::CAtlFile file;
        file.Create(fileName, 0x40000000, 3, 2, 0x80, NULL, NULL);
        CString csv("id,name,require,locking,standardlevel,requirelevel,feature,beginnpc,completenpc\n");
        for (size_t n = 0; n < m_ids.GetCount(); ++n) {
            unsigned int id = m_ids[n];
            MS2Ptr<CQuestData> quest = FUN_14074bc40(id);
            if (quest.IsNull()) continue;
            CString require;
            for (size_t i = 0; i < quest->m_require.m_quest.GetCount(); ++i) {
                require += Unk_SocketFormat<unsigned>("{0} ", quest->m_require.m_quest[i]);
            }
            CString name = StringFormat<CString>("\"{0}\"", FUN_14016a600(FUN_1416e4df0(id), 0));
            CString state;
            if (quest->m_30) state = "locking";
            else {
                if (TSingleton<QuestDataTable>::GetInstance()->FUN_14074e510(id)) state = "not acceptable";
                else state = "acceptable";
            }
            CString feature;
            csv += StringFormat("{0},{1},{2},{3},{4},{5},{6},{7}\n", id, name, require, state, quest->m_level, quest->m_require.m_level, reinterpret_cast<unsigned&>(quest->m_2e8), reinterpret_cast<unsigned&>(quest->m_2ec));
        }
        file.Write((const char*)csv, csv.GetLength(), (DWORD*)0);
        file.Close();
        FUN_1412751b0(FUN_14016a730(fileName, 0), 0x14);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141A93340, UIQuestDebugDialog, vfunc_28, 5937, 0x25607CCF);

// @0x141a94a90
int UIQuestDebugDialog::vfunc_13()
{
    if (UIDialog::vfunc_13()) return 1;
    if (((class Unk_QuestDebugAccess*)FUN_14025e7c0())->FUN_14116d9c0(28, 0, 0)) {
        if (m_30.get()) m_30->Invoke("onEnterKey");
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141A94A90, UIQuestDebugDialog, vfunc_13, 144, 0xF971780A);

// @0x141a94b30
void UIQuestDebugDialog::vfunc_45(Scaleform::GFx::Value* out, const CString& method, ASData* args)
{
    UIObject::vfunc_45(out, method, args);
    if (method == "getRequire") {
        unsigned int id = args->PopUInt();
        ASArray array(2);
        {
            auto quest = FUN_14074bc40(id);
            if (quest.get()) {
                for (size_t i = 0; i < quest->m_require.m_quest.GetCount(); ++i) {
                    unsigned int reqId = quest->m_require.m_quest[i];
                    auto required = FUN_14074bc40(reqId);
                    if (required.get()) {
                        ASObj data(2);
                        data.FUN_1407cbb20("name", FUN_1416e4df0(reqId));
                        data.FUN_1409c0d20("id", reqId);
                        data.FUN_1407cb9c0("locking", quest->m_30 != 0);
                        data.FUN_1407cb9c0("selectable", 0);
                        array.PushObj(data);
                    }
                }
                for (size_t i = 0; i < quest->m_require.m_selectableQuest.GetCount(); ++i) {
                    unsigned int reqId = quest->m_require.m_selectableQuest[i];
                    auto required = FUN_14074bc40(reqId);
                    if (required.get()) {
                        ASObj data(2);
                        data.FUN_1407cbb20("name", FUN_1416e4df0(reqId));
                        data.FUN_1409c0d20("id", reqId);
                        data.FUN_1407cb9c0("locking", quest->m_30 != 0);
                        data.FUN_1407cb9c0("selectable", 1);
                        array.PushObj(data);
                    }
                }
            }
        }
        *out = array.FUN_1422bb870();
    }
}
MS2_REPLACE_METHOD(0x141A94B30, UIQuestDebugDialog, vfunc_45, 978, 0x1971147F);

// @0x141a94f10
void UIQuestDebugDialog::vfunc_15()
{
    if (m_refresh) {
        m_refresh = 0;
        FUN_141a95310(m_chapter, 0);
    }
}
MS2_REPLACE_METHOD(0x141A94F10, UIQuestDebugDialog, vfunc_15, 67, 0xB7A4B153);

// @0x141a94f60
void UIQuestDebugDialog::vfunc_o178_1(void*) { m_refresh = 1; }
MS2_REPLACE_METHOD_VIA(0x141A94F60, UIQuestDebugDialog, UIQuestEventListener, vfunc_o178_1, 23, 0xEBF3D5C3);

// @0x141a94f80
void UIQuestDebugDialog::vfunc_o178_2(void*) { m_refresh = 1; }
MS2_REPLACE_METHOD_VIA(0x141A94F80, UIQuestDebugDialog, UIQuestEventListener, vfunc_o178_2, 23, 0xEBF3D5C3);

// @0x141a94fa0
void UIQuestDebugDialog::vfunc_o178_3(void*) { m_refresh = 1; }
MS2_REPLACE_METHOD_VIA(0x141A94FA0, UIQuestDebugDialog, UIQuestEventListener, vfunc_o178_3, 23, 0xEBF3D5C3);

// @0x141a94fc0
void UIQuestDebugDialog::vfunc_o178_7(int, int) { m_refresh = 1; }
MS2_REPLACE_METHOD_VIA(0x141A94FC0, UIQuestDebugDialog, UIQuestEventListener, vfunc_o178_7, 27, 0x4B5299BE);

// @0x141a94ff0
void UIQuestDebugDialog::vfunc_o178_8(void*) { m_refresh = 1; }
MS2_REPLACE_METHOD_VIA(0x141A94FF0, UIQuestDebugDialog, UIQuestEventListener, vfunc_o178_8, 23, 0xEBF3D5C3);

// @0x141a95010
void UIQuestDebugDialog::FUN_141a95010()
{
    if (vfunc_55()) return;
    CStringW filter = FUN_141a966a0(1);
    ATL::CAtlArray<int> chapters;
    TSingleton<QuestDataTable>::GetInstance()->GetChapterIds(chapters);
    if (MS2Ptr<ASScrollingList> list = GetChild<ASScrollingList>("m_chapter")) {
        list->FUN_1422dd1d0();
        for (size_t i = 0; i < chapters.GetCount(); ++i) {
            ASObj data(2);
            CString unused;
            CStringW label = FUN_1416e7fb0(chapters[i]);
            if (filter.GetLength() && label.GetLength() > 0) {
                if (label.Find(filter) == -1) continue;
            }
            if (FUN_141a96870(chapters[i])) label += " (lock)";
            data.FUN_1407cbb20("label", label);
            data.FUN_1407cb9c0("id", chapters[i]);
            list->AddItem(data);
        }
        list->vfunc_24(1);
    }
}
MS2_REPLACE_METHOD(0x141A95010, UIQuestDebugDialog, FUN_141a95010, 756, 0x3863A7EE);

// @0x141a95310
void UIQuestDebugDialog::FUN_141a95310(int chapter, int search)
{
    if (vfunc_55()) return;
    if ((ASScrollingList*)m_quests) m_quests->SetSelectedIndex(-1);
    void* actor = WorldService::GetInstance()->FUN_141bd0cc0();
    if (!actor) return;
    int minLevel = 0;
    if (MS2Ptr<ASTextInput> input = GetChild<ASTextInput>("m_searchLevelMin")) minLevel = _wtoi(input->GetText());
    int maxLevel = 0;
    if (MS2Ptr<ASTextInput> input = GetChild<ASTextInput>("m_searchLevelMax")) maxLevel = _wtoi(input->GetText());
    unsigned int standard = 0;
    if (MS2Ptr<ASCheckBox> check = FUN_140e52670("m_checkStandardLv")) standard = check->FUN_1422ce0e0();
    // The count formatter is a separate unrecovered COMDAT; its call and two array arguments are retained below.
    if (MS2Ptr<ASTextField> text = GetChild<ASTextField>("m_count")) {
        ATL::CAtlArray<MS2Ptr<CQuestData>> available, completed;
        TSingleton<QuestDataTable>::GetInstance()->CollectQuestsByType(available, 0);
        TSingleton<QuestDataTable>::GetInstance()->CollectQuestsByType(completed, 1);
        TSingleton<QuestDataTable>::GetInstance()->CollectQuestsByType(completed, 2);
        TSingleton<QuestDataTable>::GetInstance()->CollectQuestsByType(available, 6);
        TSingleton<QuestDataTable>::GetInstance()->CollectQuestsByType(available, 8);
        TSingleton<QuestDataTable>::GetInstance()->CollectQuestsByType(available, 9);
        CStringW format = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_quest_debug_textfield_count");
        text->SetTextW(StringFormat(format, available.GetCount(), completed.GetCount()));
    }
    unsigned int progress = 0, complete = 0, autoStart = 0, exceptLocking = 0;
    if (MS2Ptr<ASCheckBox> check = FUN_140e52670("m_checkAutoStart")) autoStart = check->FUN_1422ce0e0();
    if (MS2Ptr<ASCheckBox> check = FUN_140e52670("m_checkProgress")) progress = check->FUN_1422ce0e0();
    if (MS2Ptr<ASCheckBox> check = FUN_140e52670("m_checkComplete")) complete = check->FUN_1422ce0e0();
    if (MS2Ptr<ASCheckBox> check = FUN_140e52670("m_checkExceptLocking")) exceptLocking = check->FUN_1422ce0e0();
    CStringW filter = FUN_141a966a0(0);
    std::vector<MS2Ptr<CQuestData>> quests;
    if (chapter) {
        ATL::CAtlArray<unsigned int> ids;
        TSingleton<QuestDataTable>::GetInstance()->GetQuestIdsByChapter(chapter, ids);
        for (size_t i = 0; i < ids.GetCount(); ++i) {
            unsigned int id = ids[i];
            quests.push_back(FUN_14074bc40(id));
        }
    } else {
        ATL::CAtlArray<MS2Ptr<CQuestData>> all;
        TSingleton<QuestDataTable>::GetInstance()->CollectQuestsByType(all, 11);
        TSingleton<QuestDataTable>::GetInstance()->CollectType3QuestsByGuideType(all, 0);
        for (size_t i = 0; i < all.GetCount(); ++i) {
            auto quest = all[i];
            unsigned int id = FUN_14074b030(quest.operator->());
            CStringW name, idText;
            idText.Format(L"%d", id);
            name = FUN_1416e5900(id, false);
            if (!FUN_141a96960(id, name, idText, filter)) continue;
            if (progress || complete) {
                int keep = 0;
                if (progress) { if (reinterpret_cast<CQuestManagerCommon*>(&((class Unk_QuestDebugGlobal*)FUN_140764020())->state)->IsQuestActive(id)) keep = 1; }
                if (complete) { if (reinterpret_cast<CQuestManagerCommon*>(&((class Unk_QuestDebugGlobal*)FUN_140764020())->state)->FUN_140745590(id)) keep = 1; }
                if (!keep) continue;
            }
            if (autoStart && !quest->m_2d) continue;
            if (exceptLocking && quest->m_30) continue;
            if (standard) {
                if (minLevel && minLevel > quest->m_level) continue;
                if (maxLevel && maxLevel < quest->m_level) continue;
            } else {
                if (minLevel && minLevel > quest->m_require.m_level) continue;
                if (maxLevel && maxLevel < quest->m_require.m_level) continue;
            }
            quests.push_back(quest);
        }
        std::sort(quests.begin(), quests.end(), Unk_QuestDebugSort{standard});
    }
    int count = 0;
    m_ids.RemoveAll();
    if (MS2Ptr<ASScrollingList> list = GetChild<ASScrollingList>("m_quests")) {
        list->FUN_1422dd1d0();
        for (auto it = quests.begin(); it != quests.end(); ++it) {
            auto quest = *it;
            CStringW state = GetStringCommon(FUN_141a96c30(FUN_14074b030(quest.operator->()), quest));
            if (!search && chapter && chapter != quest->m_28) continue;
            ++count;
            unsigned int id = FUN_14074b030(quest.operator->());
            CStringW name = FUN_1416e5900(id, false);
            ASObj data(2);
            data.FUN_1409c0d20("id", id);
            data.FUN_1407cb9c0("standardLv", quest->m_level);
            data.FUN_1409c48f0("acceptLv", quest->m_require.m_level);
            data.FUN_1409c1180("exp", FUN_140761ba0(id, 1));
            data.FUN_1409c1180("meso", FUN_140761cc0(id, 1));
            data.FUN_1407cbb20("name", name);
            data.FUN_1407cbb20("npc", FUN_1401aa6a0(quest->m_2e8));
            data.FUN_1407cbb20("req", FUN_1401aa6a0(quest->m_2ec));
            data.FUN_1407cbb20("state", state);
            data.FUN_1407cbbe0("locking", reinterpret_cast<bool&>(quest->m_30));
            list->AddItem(data);
            m_ids.Add(id);
        }
        list->vfunc_24(1);
    }
    if (MS2Ptr<ASTextField> text = GetChild<ASTextField>("m_currentCount")) text->SetTextW(StringFormat<int>(L"Search count : {0}", count));
}
MS2_REPLACE_METHOD(0x141A95310, UIQuestDebugDialog, FUN_141a95310, 4998, 0x217DF313);

// @0x141a966a0
CStringW UIQuestDebugDialog::FUN_141a966a0(unsigned int mode)
{
    unsigned int checked = 0;
    if (MS2Ptr<ASCheckBox> check = FUN_140e52670("m_checkFilter")) checked = check->FUN_1422ce0e0();
    CStringW text;
    if (checked == mode) {
        if (MS2Ptr<ASTextInput> input = GetChild<ASTextInput>("m_searchInput")) text = input->GetText();
    }
    return text;
}
MS2_REPLACE_METHOD(0x141A966A0, UIQuestDebugDialog, FUN_141a966a0, 452, 0x063564E3);

// @0x141a96870
int UIQuestDebugDialog::FUN_141a96870(int chapter)
{
    ATL::CAtlArray<unsigned int> ids;
    TSingleton<QuestDataTable>::GetInstance()->GetQuestIdsByChapter(chapter, ids);
    for (size_t i = 0; i < ids.GetCount(); ++i) {
        auto quest = FUN_14074bc40(ids[i]);
        if (!quest->m_30) return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141A96870, UIQuestDebugDialog, FUN_141a96870, 219, 0x629DE2A2);

// @0x141a96960
int UIQuestDebugDialog::FUN_141a96960(int id, CStringW& name, CStringW& idText, const CStringW& filter)
{
    if (!filter.GetLength()) return 1;
    if (name.Find(filter) != -1) return 1;
    if (idText.Find(filter) != -1) return 1;
    auto quest = FUN_14074bc40(id);
    if (quest.IsNull()) return 0;
    CStringW beginNpc = FUN_1401aa6a0(quest->m_2e8);
    if (beginNpc.Find(filter) != -1) return 1;
    CStringW endNpc = FUN_1401aa6a0(quest->m_2ec);
    if (endNpc.Find(filter) != -1) return 1;
    ATL::CAtlArray<CStringW> texts;
    FUN_1416e5890(id, texts);
    for (size_t i = 0; i < texts.GetCount(); ++i) {
        if (texts[i].Find(filter) != -1) return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141A96960, UIQuestDebugDialog, FUN_141a96960, 699, 0x6A48A5B4);

// @0x141a96c30
int UIQuestDebugDialog::FUN_141a96c30(int id, MS2Ptr<CQuestData> quest)
{
    return FUN_1416e6100(id, 0);
}
MS2_REPLACE_METHOD(0x141A96C30, UIQuestDebugDialog, FUN_141a96c30, 61, 0x9564E575);


// @0x141a97770
CStringW FUN_141a97770(Unk_QuestDebugMap* map)
{
    CStringW out;
    for (POSITION pos = map->GetStartPosition(); pos != 0; map->GetNext(pos)) {
        CString key = map->GetKeyAt(pos);
        CString value = map->GetValueAt(pos);
        out += StringFormat(L"k:{0}, v:{1}\n", key, value);
    }
    return out;
}
MS2_REPLACE(0x141A97770, FUN_141a97770, 312, 0x948EFF51);

MS2_EMIT_CRT_MEMMOVE_S();
