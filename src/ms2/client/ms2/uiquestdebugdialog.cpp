// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Quest debug dialog; incomplete recovery.
// MS2-UNIT: client\ms2\uiquestdebugdialog.cpp
// MS2-RANGE: 0x141a92ed0-0x141a993a0 .text$mn
// MS2-RANGE: 0x14011afa0-0x14011b110 .text$di
// MS2-RANGE: 0x142cc1830-0x142cc18b5 .text$yd
// MS2-PIN: ?vfunc_48@UIQuestDebugDialog@@UEAAHXZ 0x141a99240
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquestdebugdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiquestdebugdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <vector>
#include <algorithm>

// Unit-local declarations, pending recovery of the quest data and AS wrapper units.
class Unk_QuestDebugManager
{
public:
    void FUN_141aa87c0(UIQuestEventListener*);
    void FUN_141aa8850(UIQuestEventListener*);
    void FUN_14074cf20(ATL::CAtlArray<int>&);
    void FUN_14074cfd0(int, ATL::CAtlArray<unsigned int>&);
    void FUN_14074cad0(ATL::CAtlArray<Unk_QuestDebugPtr<Unk_QuestDebugData>>&, int);
    int FUN_14074e510(unsigned int);
    void FUN_14074cca0(ATL::CAtlArray<Unk_QuestDebugPtr<Unk_QuestDebugData>>&, int);
};
Unk_QuestDebugManager* FUN_140bfc4b0();
Unk_QuestDebugManager* FUN_1407476c0();
class Unk_QuestDebugCheck { public: unsigned char FUN_1422ce0e0(); };
class Unk_QuestDebugInput { public: CStringW FUN_1422e0b00(); };
class Unk_QuestDebugText { public: void FUN_1422c4cd0(const CStringW&); };
class Unk_QuestDebugAS : public AScript
{
public:
    Unk_QuestDebugAS(int);
    virtual ~Unk_QuestDebugAS();
    void FUN_1407cbb20(const char*, CStringW);
    void FUN_1409c0d20(const char*, unsigned int);
    void FUN_1407cb9c0(const char*, int);
    void FUN_1409c48f0(const char*, unsigned short);
    void FUN_1409c1180(const char*, unsigned __int64);
    void FUN_1407cbbe0(const char*, bool);
};
class Unk_QuestDebugArray : public AScript
{
public:
    Unk_QuestDebugArray(int);
    virtual ~Unk_QuestDebugArray();
    void FUN_1422bbf00(const Unk_QuestDebugAS&);
};
class Unk_QuestDebugList
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool);
    void FUN_1422dd1d0();
    void FUN_1422dd230(const Unk_QuestDebugAS&);
    void FUN_1422dcca0(int);
};
class Unk_QuestDebugBinding
{
public:
    Unk_QuestDebugPtr<Unk_QuestDebugList> FUN_140bc7340(const CString&, Unk_QuestDebugPtr<Unk_QuestDebugList>&);
};
CString FUN_140bc6280(const char*, const char*, const char*, const int&, const char*);
class Unk_QuestDebugLocalizer { public: CStringW FUN_1422b0570(const CString&); };
Unk_QuestDebugLocalizer* FUN_14025e7a0();
class Unk_QuestDebugAccess { public: bool FUN_14116d9c0(int, int, int); };
Unk_QuestDebugAccess* FUN_14025e7c0();
class ASData : public CPtred
{
public:
    ASData();
    virtual ~ASData();
    int FUN_1422b8b10();
    int FUN_1422b9620(const Scaleform::GFx::Value*, unsigned int);
    int FUN_1422b8a10();
    CStringW FUN_1422b8f40();
private:
    void* p18; void* p20; void* p28; void* p30; void* p38; void* p40;
};
MS2_CHECK_SIZE(ASData, 0x48);
bool FUN_140184310(const CString&, const char*);
class Unk_QuestDebugHandle
{
public:
    Unk_QuestDebugHandle(const Unk_QuestDebugHandle&);
    ~Unk_QuestDebugHandle();
    void* FUN_1402a5cb0();
    // @0x141a99100
    void* FUN_141a99100() const { return m_p; }
private:
    void* m_0;
    void* m_p;
};
class Unk_QuestDebugCond
{
public:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68; void* m_70; void* m_78; void* m_80; void* m_88; void* m_90;
    Unk_QuestDebugHandle codes;
    void* m_a8; void* m_b0; void* m_b8; void* m_c0; void* m_c8; void* m_d0; void* m_d8; void* m_e0; void* m_e8; void* m_f0; void* m_f8; void* m_100; void* m_108; void* m_110;
    Unk_QuestDebugHandle targets;
};
MS2_CHECK_OFFSET(Unk_QuestDebugCond, codes, 0x98);
MS2_CHECK_OFFSET(Unk_QuestDebugCond, targets, 0x118);
class Unk_QuestDebugCondList
{
public:
    size_t FUN_14075ae80();
    Unk_QuestDebugCond* FUN_140759290(size_t);
};
class Unk_QuestDebugData
{
public:
    unsigned int FUN_14074b030();
    int m_0;
    int m_4;
    int m_8;
    int m_c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int standardLevel;
    int chapter;
    unsigned char m_2c, autoStart, m_2e, m_2f;
    bool locked;
    unsigned char m_31;
    unsigned short m_32;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    unsigned short acceptLevel;
    unsigned short m_5a;
    int m_5c;
    void* m_60;
    void* m_68;
    void* m_70;
    void* m_78;
    void* m_80;
    void* m_88;
    void* m_90;
    void* m_98;
    void* m_a0;
    void* m_a8;
    void* m_b0;
    void* m_b8;
    void* m_c0;
    void* m_c8;
    void* m_d0;
    void* m_d8;
    void* m_e0;
    void* m_e8;
    void* m_f0;
    void* m_f8;
    void* m_100;
    ATL::CAtlArray<unsigned int> required;
    ATL::CAtlArray<unsigned int> selectable;
    void* m_148;
    void* m_150;
    void* m_158;
    void* m_160;
    void* m_168;
    void* m_170;
    void* m_178;
    void* m_180;
    void* m_188;
    void* m_190;
    void* m_198;
    void* m_1a0;
    void* m_1a8;
    void* m_1b0;
    void* m_1b8;
    void* m_1c0;
    void* m_1c8;
    void* m_1d0;
    void* m_1d8;
    void* m_1e0;
    void* m_1e8;
    void* m_1f0;
    void* m_1f8;
    void* m_200;
    void* m_208;
    void* m_210;
    void* m_218;
    void* m_220;
    void* m_228;
    void* m_230;
    void* m_238;
    void* m_240;
    void* m_248;
    void* m_250;
    void* m_258;
    void* m_260;
    void* m_268;
    void* m_270;
    void* m_278;
    void* m_280;
    void* m_288;
    void* m_290;
    void* m_298;
    void* m_2a0;
    void* m_2a8;
    void* m_2b0;
    void* m_2b8;
    void* m_2c0;
    void* m_2c8;
    void* m_2d0;
    void* m_2d8;
    void* m_2e0;
    unsigned int beginNpc, endNpc;
    void* m_2f0; void* m_2f8; void* m_300; void* m_308; void* m_310; void* m_318; void* m_320; void* m_328;
    void* m_330; void* m_338; void* m_340; void* m_348; void* m_350; void* m_358; void* m_360; void* m_368;
    void* m_370; void* m_378; void* m_380;
    Unk_QuestDebugCondList conds;
};
MS2_CHECK_OFFSET(Unk_QuestDebugData, standardLevel, 0x24);
MS2_CHECK_OFFSET(Unk_QuestDebugData, locked, 0x30);
MS2_CHECK_OFFSET(Unk_QuestDebugData, acceptLevel, 0x58);
MS2_CHECK_OFFSET(Unk_QuestDebugData, required, 0x108);
MS2_CHECK_OFFSET(Unk_QuestDebugData, selectable, 0x128);
MS2_CHECK_OFFSET(Unk_QuestDebugData, beginNpc, 0x2e8);
MS2_CHECK_OFFSET(Unk_QuestDebugData, conds, 0x388);
Unk_QuestDebugPtr<Unk_QuestDebugData> FUN_14074bc40(unsigned int);
CStringW FUN_1416e4df0(unsigned int);
CStringW FUN_1416e5900(unsigned int, int);
CStringW FUN_1416e7fb0(int);
CStringW FUN_1401aa6a0(int);
CStringW FUN_14028de60(int);
unsigned __int64 FUN_140761ba0(unsigned int, int);
unsigned __int64 FUN_140761cc0(unsigned int, int);
void FUN_1416e5890(int, ATL::CAtlArray<CStringW>&);
int FUN_1416e6100(int, int);
class Unk_QuestDebugPlayer { public: void* FUN_141bd0cc0(); };
Unk_QuestDebugPlayer* FUN_1403ed2d0();
class Unk_QuestDebugState
{
public:
    int FUN_140745630(unsigned int);
    int FUN_140745590(unsigned int);
};
class Unk_QuestDebugGlobal { public: void* m_0; void* m_8; Unk_QuestDebugState state; };
Unk_QuestDebugGlobal* FUN_140764020();
CStringW FUN_1401ceea0(const wchar_t*, const int&);
class Unk_QuestDebugTime
{
public:
    Unk_QuestDebugTime(__int64);
    int GetSecond() const;
    int GetMinute() const;
    int GetHour() const;
private:
    __int64 m_0, m_8;
};
class Unk_QuestDebugDesc { public: void FUN_1422e0ab0(const CStringW&); };
class Unk_QuestDebugFile
{
public:
    Unk_QuestDebugFile();
    ~Unk_QuestDebugFile();
    void FUN_1402989b0(const char*, unsigned int, unsigned int, unsigned int, unsigned int, void*, void*);
    void FUN_140299dc0(const char*, int, int);
    void FUN_1402988c0();
private:
    void* m_0; void* m_8;
};
class Unk_QuestDebugMap
{
public:
    __int64 FUN_140166af0();
    const CString& FUN_1401664c0(__int64);
    const CString& FUN_140166c40(__int64);
    void FUN_1401665d0(__int64*);
};
void FUN_140761f00(const CStringW&, int);
CStringW FUN_140ba7890(const wchar_t*, const unsigned __int64&);
CStringW FUN_1402758a0(const wchar_t*, const CStringW&, const unsigned int&);
CStringW FUN_140292a70(const wchar_t*, const unsigned int&);
CString FUN_140513200(const char*, const unsigned int&);
CString FUN_140540050(const char*, const CString&);
CString FUN_14016a600(const wchar_t*, int);
CStringW FUN_14016a730(const char*, int);
void FUN_1412751b0(const CStringW&, int);
CString FUN_14086c880(const char*, const int&, const int&, const int&);
__int64 FUN_140869440();
class Unk_QuestDebugMap;
CStringW FUN_141a97770(Unk_QuestDebugMap*);
// Comparator's by-value intrusive pointers reproduce the original cleanup states.
struct Unk_QuestDebugSort
{
    unsigned int standard;
    // @0x141a99110
    bool operator()(Unk_QuestDebugPtr<Unk_QuestDebugData> a, Unk_QuestDebugPtr<Unk_QuestDebugData> b) const
    {
        unsigned short left, right;
        if (standard) { left = (unsigned short)a->standardLevel; right = (unsigned short)b->standardLevel; }
        else { left = a->acceptLevel; right = b->acceptLevel; }
        if (!left) left = 100;
        if (!right) right = 100;
        return left < right;
    }
};

// @0x141a92ed0
UIQuestDebugDialog::UIQuestDebugDialog()
{
    m_refresh = 0;
    m_40 = 1;
    FUN_1422dc3b0(1);
    FUN_140bfc4b0()->FUN_141aa87c0(this);
}
// @0x141a92fd0
UIQuestDebugDialog::~UIQuestDebugDialog()
{
    FUN_140bfc4b0()->FUN_141aa8850(this);
}
// @0x141a930a0
CString UIQuestDebugDialog::GetTypeName() { return "QuestDebugDialog"; }
MS2_REPLACE_METHOD(0x141A930A0, UIQuestDebugDialog, GetTypeName, 61, 0x98C8DB38);

// @0x141a930f0
void UIQuestDebugDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    do {
    reinterpret_cast<Unk_QuestDebugBinding*>(m_30.operator->())->FUN_140bc7340("m_quests", m_quests);
    if (m_quests == 0) {
            throw new GfxExceptionSwfLoad(FUN_140bc6280("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(40), __FUNCTION__));
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
    m_quests = 0;
}
MS2_REPLACE_METHOD(0x141A93300, UIQuestDebugDialog, vfunc_26, 45, 0x6E6AEC38);

// @0x141a93340
int UIQuestDebugDialog::vfunc_28(const char* method, const Scaleform::GFx::Value* args, unsigned int count)
{
    UIDialog::vfunc_28(method, args, count);
    ASData data;
    if (_stricmp("OnChapterChange", method) == 0) {
        if (data.FUN_1422b9620(args, count)) {
            m_chapter = data.FUN_1422b8a10();
            FUN_141a95010();
            FUN_141a95310(m_chapter, 0);
        }
        return 1;
    } else if (_stricmp("OnSearchItem", method) == 0) {
        FUN_141a95010();
        FUN_141a95310(0, 1);
    } else if (_stricmp("OnModifyQuest", method) == 0) {
        if (data.FUN_1422b9620(args, count)) {
            int id;
            CStringW quest = data.FUN_1422b8f40();
            id = data.FUN_1422b8b10();
            FUN_140761f00(quest, id);
        }
        return 1;
    } else if (_stricmp("OnChangeQuest", method) == 0) {
        if (data.FUN_1422b9620(args, count)) {
            unsigned int id = data.FUN_1422b8b10();
            Unk_QuestDebugPtr<Unk_QuestDebugData> quest = FUN_14074bc40(id);
            if (!quest) return 1;
            void* actor = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (!actor) return 1;
            if (Unk_QuestDebugPtr<Unk_QuestDebugDesc> desc = FUN_140c26f60("m_desc")) {
                CStringW text;
                CStringW expLabel = FUN_14025e7a0()->FUN_1422b0570("$s_quest_debug_desc_exp");
                CStringW mesoLabel = FUN_14025e7a0()->FUN_1422b0570("$s_quest_debug_desc_meso");
                CStringW statLabel = FUN_14025e7a0()->FUN_1422b0570("$s_quest_debug_desc_stat_point");
                CStringW skillLabel = FUN_14025e7a0()->FUN_1422b0570("$s_quest_debug_desc_skill_point");
                text += FUN_140ba7890(expLabel, FUN_140761ba0(id, 1));
                text += FUN_140ba7890(mesoLabel, FUN_140761cc0(id, 1));
                if (quest->required.GetCount()) {
                    text += L"\nPreceding Quest\n";
                    for (size_t i = 0; i < quest->required.GetCount(); ++i) {
                        unsigned int reqId = quest->required[i];
                        text += FUN_1402758a0(L"{0}({1})\n", FUN_1416e4df0(reqId), reqId);
                    }
                }
                if (quest->beginNpc != 0) {
                    CStringW label = FUN_14025e7a0()->FUN_1422b0570("$s_quest_debug_desc_start_npc");
                    text += FUN_1402758a0(label, FUN_1401aa6a0(quest->beginNpc), quest->beginNpc);
                }
                if (quest->endNpc != 0) {
                    CStringW label = FUN_14025e7a0()->FUN_1422b0570("$s_quest_debug_desc_complate_npc");
                    text += FUN_1402758a0(label, FUN_1401aa6a0(quest->endNpc), quest->endNpc);
                }
                size_t condCount = quest->conds.FUN_14075ae80();
                for (size_t i = 0; i < condCount; ++i) {
                    Unk_QuestDebugPtr<Unk_QuestDebugCond> cond = quest->conds.FUN_140759290(i);
                    if (!cond) continue;
                    {
                        Unk_QuestDebugHandle codes(cond->codes);
                        if (codes.FUN_141a99100()) {
                            text += L"\n[Codes]\n";
                            text += FUN_141a97770((Unk_QuestDebugMap*)codes.FUN_1402a5cb0());
                        }
                    }
                    {
                        Unk_QuestDebugHandle targets(cond->targets);
                        if (targets.FUN_141a99100()) {
                            text += L"\n[Targets]\n";
                            text += FUN_141a97770((Unk_QuestDebugMap*)targets.FUN_1402a5cb0());
                        }
                    }
                }
                desc->FUN_1422e0ab0(text);
            }
        }
    } else if (_stricmp("onReqQuest", method) == 0) {
        if (data.FUN_1422b9620(args, count)) {
            unsigned int id = data.FUN_1422b8b10();
            Unk_QuestDebugPtr<Unk_QuestDebugData> quest = FUN_14074bc40(id);
            if (quest) {
                CStringW list;
                for (size_t i = 0; i < quest->required.GetCount(); ++i) {
                    if (FUN_140764020()->state.FUN_140745590(quest->required[i]) == 0) {
                        if (list.GetLength() != 0) list += L",";
                        list += FUN_140292a70(L"{0}", quest->required[i]);
                    }
                }
                if (list.GetLength() != 0) FUN_140761f00(list, 2);
            }
        }
    } else if (_stricmp("onXml", method) == 0) {
        if (data.FUN_1422b9620(args, count)) {
            unsigned int id = data.FUN_1422b8b10();
            CString path;
            path.Format("./Data/Xml/Quest/%08d.xml", id);
            path.Replace('/', '\\');
            ShellExecuteA(NULL, "open", path, NULL, NULL, 1);
        }
    } else if (_stricmp("onExcel", method) == 0) {
        if (data.FUN_1422b9620(args, count)) {
            unsigned int id = data.FUN_1422b8b10();
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
        Unk_QuestDebugTime now(FUN_140869440());
        int second = now.GetSecond();
        int minute = now.GetMinute();
        int hour = now.GetHour();
        CString fileName = FUN_14086c880(".\\log\\client\\quest_export_{0:02d}{1:02d}{2:02d}.csv", hour, minute, second);
        Unk_QuestDebugFile file;
        file.FUN_1402989b0(fileName, 0x40000000, 3, 2, 0x80, NULL, NULL);
        CString csv("id,name,require,locking,standardlevel,requirelevel,feature,beginnpc,completenpc\n");
        for (size_t n = 0; n < m_ids.GetCount(); ++n) {
            unsigned int id = m_ids[n];
            Unk_QuestDebugPtr<Unk_QuestDebugData> quest = FUN_14074bc40(id);
            if (!quest) continue;
            CString require;
            for (size_t i = 0; i < quest->required.GetCount(); ++i) {
                require += FUN_140513200("{0} ", quest->required[i]);
            }
            CString name = FUN_140540050("\"{0}\"", FUN_14016a600(FUN_1416e4df0(id), 0));
            CString state;
            if (quest->locked) state = "locking";
            else {
                if (FUN_1407476c0()->FUN_14074e510(id)) state = "not acceptable";
                else state = "acceptable";
            }
            CString feature;
            csv += StringFormat("{0},{1},{2},{3},{4},{5},{6},{7}\n", id, name, require, state, quest->standardLevel, quest->acceptLevel, quest->beginNpc, quest->endNpc);
        }
        file.FUN_140299dc0(csv, csv.GetLength(), 0);
        file.FUN_1402988c0();
        FUN_1412751b0(FUN_14016a730(fileName, 0), 0x14);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141A93340, UIQuestDebugDialog, vfunc_28, 5937, 0x25607CCF);

// @0x141a94a90
int UIQuestDebugDialog::vfunc_13()
{
    if (UIDialog::vfunc_13()) return 1;
    if (FUN_14025e7c0()->FUN_14116d9c0(28, 0, 0)) {
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
    if (FUN_140184310(method, "getRequire")) {
        unsigned int id = args->FUN_1422b8b10();
        Unk_QuestDebugArray array(2);
        {
            auto quest = FUN_14074bc40(id);
            if ((Unk_QuestDebugData*)quest) {
                for (size_t i = 0; i < quest->required.GetCount(); ++i) {
                    unsigned int reqId = quest->required[i];
                    auto required = FUN_14074bc40(reqId);
                    if ((Unk_QuestDebugData*)required) {
                        Unk_QuestDebugAS data(2);
                        data.FUN_1407cbb20("name", FUN_1416e4df0(reqId));
                        data.FUN_1409c0d20("id", reqId);
                        data.FUN_1407cb9c0("locking", quest->locked != 0);
                        data.FUN_1407cb9c0("selectable", 0);
                        array.FUN_1422bbf00(data);
                    }
                }
                for (size_t i = 0; i < quest->selectable.GetCount(); ++i) {
                    unsigned int reqId = quest->selectable[i];
                    auto required = FUN_14074bc40(reqId);
                    if ((Unk_QuestDebugData*)required) {
                        Unk_QuestDebugAS data(2);
                        data.FUN_1407cbb20("name", FUN_1416e4df0(reqId));
                        data.FUN_1409c0d20("id", reqId);
                        data.FUN_1407cb9c0("locking", quest->locked != 0);
                        data.FUN_1407cb9c0("selectable", 1);
                        array.FUN_1422bbf00(data);
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
    FUN_1407476c0()->FUN_14074cf20(chapters);
    if (Unk_QuestDebugPtr<Unk_QuestDebugList> list = FUN_140c02900("m_chapter")) {
        list->FUN_1422dd1d0();
        for (size_t i = 0; i < chapters.GetCount(); ++i) {
            Unk_QuestDebugAS data(2);
            CString unused;
            CStringW label = FUN_1416e7fb0(chapters[i]);
            if (filter.GetLength() && label.GetLength() > 0) {
                if (label.Find(filter) == -1) continue;
            }
            if (FUN_141a96870(chapters[i])) label += " (lock)";
            data.FUN_1407cbb20("label", label);
            data.FUN_1407cb9c0("id", chapters[i]);
            list->FUN_1422dd230(data);
        }
        list->vfunc_24(1);
    }
}
MS2_REPLACE_METHOD(0x141A95010, UIQuestDebugDialog, FUN_141a95010, 756, 0x3863A7EE);

// @0x141a95310
void UIQuestDebugDialog::FUN_141a95310(int chapter, int search)
{
    if (vfunc_55()) return;
    if ((Unk_QuestDebugList*)m_quests) m_quests->FUN_1422dcca0(-1);
    void* actor = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!actor) return;
    int minLevel = 0;
    if (Unk_QuestDebugPtr<Unk_QuestDebugInput> input = FUN_140e35bd0("m_searchLevelMin")) minLevel = _wtoi(input->FUN_1422e0b00());
    int maxLevel = 0;
    if (Unk_QuestDebugPtr<Unk_QuestDebugInput> input = FUN_140e35bd0("m_searchLevelMax")) maxLevel = _wtoi(input->FUN_1422e0b00());
    unsigned int standard = 0;
    if (Unk_QuestDebugPtr<Unk_QuestDebugCheck> check = FUN_140e52670("m_checkStandardLv")) standard = check->FUN_1422ce0e0();
    // The count formatter is a separate unrecovered COMDAT; its call and two array arguments are retained below.
    if (Unk_QuestDebugPtr<Unk_QuestDebugText> text = FUN_140bb4cf0("m_count")) {
        ATL::CAtlArray<Unk_QuestDebugPtr<Unk_QuestDebugData>> available, completed;
        FUN_1407476c0()->FUN_14074cad0(available, 0);
        FUN_1407476c0()->FUN_14074cad0(completed, 1);
        FUN_1407476c0()->FUN_14074cad0(completed, 2);
        FUN_1407476c0()->FUN_14074cad0(available, 6);
        FUN_1407476c0()->FUN_14074cad0(available, 8);
        FUN_1407476c0()->FUN_14074cad0(available, 9);
        CStringW format = FUN_14025e7a0()->FUN_1422b0570("$s_quest_debug_textfield_count");
        text->FUN_1422c4cd0(StringFormat(format, available.GetCount(), completed.GetCount()));
    }
    unsigned int progress = 0, complete = 0, autoStart = 0, exceptLocking = 0;
    if (Unk_QuestDebugPtr<Unk_QuestDebugCheck> check = FUN_140e52670("m_checkAutoStart")) autoStart = check->FUN_1422ce0e0();
    if (Unk_QuestDebugPtr<Unk_QuestDebugCheck> check = FUN_140e52670("m_checkProgress")) progress = check->FUN_1422ce0e0();
    if (Unk_QuestDebugPtr<Unk_QuestDebugCheck> check = FUN_140e52670("m_checkComplete")) complete = check->FUN_1422ce0e0();
    if (Unk_QuestDebugPtr<Unk_QuestDebugCheck> check = FUN_140e52670("m_checkExceptLocking")) exceptLocking = check->FUN_1422ce0e0();
    CStringW filter = FUN_141a966a0(0);
    std::vector<Unk_QuestDebugPtr<Unk_QuestDebugData>> quests;
    if (chapter) {
        ATL::CAtlArray<unsigned int> ids;
        FUN_1407476c0()->FUN_14074cfd0(chapter, ids);
        for (size_t i = 0; i < ids.GetCount(); ++i) {
            unsigned int id = ids[i];
            quests.push_back(FUN_14074bc40(id));
        }
    } else {
        ATL::CAtlArray<Unk_QuestDebugPtr<Unk_QuestDebugData>> all;
        FUN_1407476c0()->FUN_14074cad0(all, 11);
        FUN_1407476c0()->FUN_14074cca0(all, 0);
        for (size_t i = 0; i < all.GetCount(); ++i) {
            auto quest = all[i];
            unsigned int id = quest->FUN_14074b030();
            CStringW name, idText;
            idText.Format(L"%d", id);
            name = FUN_1416e5900(id, 0);
            if (!FUN_141a96960(id, name, idText, filter)) continue;
            if (progress || complete) {
                int keep = 0;
                if (progress) { if (FUN_140764020()->state.FUN_140745630(id)) keep = 1; }
                if (complete) { if (FUN_140764020()->state.FUN_140745590(id)) keep = 1; }
                if (!keep) continue;
            }
            if (autoStart && !quest->autoStart) continue;
            if (exceptLocking && quest->locked) continue;
            if (standard) {
                if (minLevel && minLevel > quest->standardLevel) continue;
                if (maxLevel && maxLevel < quest->standardLevel) continue;
            } else {
                if (minLevel && minLevel > quest->acceptLevel) continue;
                if (maxLevel && maxLevel < quest->acceptLevel) continue;
            }
            quests.push_back(quest);
        }
        std::sort(quests.begin(), quests.end(), Unk_QuestDebugSort{standard});
    }
    int count = 0;
    m_ids.RemoveAll();
    if (Unk_QuestDebugPtr<Unk_QuestDebugList> list = FUN_140c02900("m_quests")) {
        list->FUN_1422dd1d0();
        for (auto it = quests.begin(); it != quests.end(); ++it) {
            auto quest = *it;
            CStringW state = FUN_14028de60(FUN_141a96c30(quest->FUN_14074b030(), quest));
            if (!search && chapter && chapter != quest->chapter) continue;
            ++count;
            unsigned int id = quest->FUN_14074b030();
            CStringW name = FUN_1416e5900(id, 0);
            Unk_QuestDebugAS data(2);
            data.FUN_1409c0d20("id", id);
            data.FUN_1407cb9c0("standardLv", quest->standardLevel);
            data.FUN_1409c48f0("acceptLv", quest->acceptLevel);
            data.FUN_1409c1180("exp", FUN_140761ba0(id, 1));
            data.FUN_1409c1180("meso", FUN_140761cc0(id, 1));
            data.FUN_1407cbb20("name", name);
            data.FUN_1407cbb20("npc", FUN_1401aa6a0(quest->beginNpc));
            data.FUN_1407cbb20("req", FUN_1401aa6a0(quest->endNpc));
            data.FUN_1407cbb20("state", state);
            data.FUN_1407cbbe0("locking", quest->locked);
            list->FUN_1422dd230(data);
            m_ids.Add(id);
        }
        list->vfunc_24(1);
    }
    if (Unk_QuestDebugPtr<Unk_QuestDebugText> text = FUN_140bb4cf0("m_currentCount")) text->FUN_1422c4cd0(FUN_1401ceea0(L"Search count : {0}", count));
}
MS2_REPLACE_METHOD(0x141A95310, UIQuestDebugDialog, FUN_141a95310, 4998, 0x217DF313);

// @0x141a966a0
CStringW UIQuestDebugDialog::FUN_141a966a0(unsigned int mode)
{
    unsigned int checked = 0;
    if (Unk_QuestDebugPtr<Unk_QuestDebugCheck> check = FUN_140e52670("m_checkFilter")) checked = check->FUN_1422ce0e0();
    CStringW text;
    if (checked == mode) {
        if (Unk_QuestDebugPtr<Unk_QuestDebugInput> input = FUN_140e35bd0("m_searchInput")) text = input->FUN_1422e0b00();
    }
    return text;
}
MS2_REPLACE_METHOD(0x141A966A0, UIQuestDebugDialog, FUN_141a966a0, 452, 0x063564E3);

// @0x141a96870
int UIQuestDebugDialog::FUN_141a96870(int chapter)
{
    ATL::CAtlArray<unsigned int> ids;
    FUN_1407476c0()->FUN_14074cfd0(chapter, ids);
    for (size_t i = 0; i < ids.GetCount(); ++i) {
        auto quest = FUN_14074bc40(ids[i]);
        if (!quest->locked) return 0;
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
    if (!quest) return 0;
    CStringW beginNpc = FUN_1401aa6a0(quest->beginNpc);
    if (beginNpc.Find(filter) != -1) return 1;
    CStringW endNpc = FUN_1401aa6a0(quest->endNpc);
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
int UIQuestDebugDialog::FUN_141a96c30(int id, Unk_QuestDebugPtr<Unk_QuestDebugData> quest)
{
    return FUN_1416e6100(id, 0);
}
MS2_REPLACE_METHOD(0x141A96C30, UIQuestDebugDialog, FUN_141a96c30, 61, 0x9564E575);


// @0x141a97770
CStringW FUN_141a97770(Unk_QuestDebugMap* map)
{
    CStringW out;
    for (__int64 pos = map->FUN_140166af0(); pos != 0; map->FUN_1401665d0(&pos)) {
        CString key = map->FUN_1401664c0(pos);
        CString value = map->FUN_140166c40(pos);
        out += StringFormat(L"k:{0}, v:{1}\n", key, value);
    }
    return out;
}
MS2_REPLACE(0x141A97770, FUN_141a97770, 312, 0x948EFF51);

MS2_EMIT_CRT_MEMMOVE_S();
