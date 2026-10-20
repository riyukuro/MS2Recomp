// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The game dictionary window ("GameDictionaryDialog", UI id
// 0x4f0b): the npc / monster / item rows with a search box, and the detail page of the selected row.
// MS2-UNIT: ?\uigamedictionarydialog.cpp
// MS2-RANGE: 0x140f447d0-0x140f48b40 .text$mn
// MS2-RANGE: 0x1400df5c0-0x1400df730 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400df680 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400df6b0 ; probe
// MS2-PIN: ??0?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@UEntry@UIGameDictionaryDialog@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@UEntry@UIGameDictionaryDialog@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@UEntry@UIGameDictionaryDialog@@@std@@@1@@Z 0x140f47a80 ; prop
// MS2-PIN: ??0?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$shared_ptr@UUnk_DictData@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@V?$shared_ptr@UUnk_DictData@@@std@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$shared_ptr@UUnk_DictData@@@std@@@std@@@1@@Z 0x140f47ac0 ; unique
// MS2-PIN: ??0?$_List_iterator@V?$_List_val@U?$_List_simple_types@UEntry@UIGameDictionaryDialog@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@UEntry@UIGameDictionaryDialog@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@UEntry@UIGameDictionaryDialog@@@std@@@1@@Z 0x140f47b00 ; unique
// MS2-PIN: ?vfunc_48@UIGameDictionaryDialog@@UEAAHXZ 0x140f48280 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7ASObj@@6B@ 0x142db7e28
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigamedictionarydialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uigamedictionarydialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <atlcoll.h>
#include <memory>

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The AS controls of the movie. Slot 24 is the one the dialog calls (select / refresh).
class Unk_DictCtl : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(int n);
};
// "m_items": the rows list.
class Unk_DictList : public Unk_DictCtl
{
public:
    void FUN_1422dd1d0();                                   // clear
    void FUN_1422dcca0(int n);                              // select the row
    void FUN_1422dd230(const ASObj& row);                   // append a row
    ASArray FUN_1422dcd80();                                // the data provider
};
// "m_tab": the tab strip.
class Unk_DictTab : public Unk_DictCtl
{
public:
    void FUN_1422e31e0(int n);                              // select
};
// "m_inputSearch": the search text input.
class Unk_DictInput : public ASDisplayObject
{
public:
    void FUN_1422e0ab0(const CStringW& str);                // set the text
    CStringW FUN_1422e0b00();                               // the text
};
int FUN_1422c76c0(Unk_DictInput* p);                        // the input has the focus
class ASDialog : public ASDisplayObject {};

// The dictionary data: three rows tables (npc / monster / item), each a list of shared rows.
struct Unk_DictData
{
    int m_id;                                               // +0x00
    int m_level;                                            // +0x04 monster level
    int m_grade;                                            // +0x08 item grade
    int m_invisibleLevel;                                   // +0x0c
    unsigned m_fieldId;                                     // +0x10
};
class Unk_DictManager { public: std::list<std::shared_ptr<Unk_DictData> > FUN_1403b7af0(int nKind); };
Unk_DictManager* FUN_140541580();
CStringW FUN_1401aa6a0(int nNpcId);                         // npc name

// The platform: request answers.
class Unk_DictPlatform
{
public:
#define DC_V(n) virtual void vfunc_##n();
    DC_V(0) DC_V(1) DC_V(2) DC_V(3) DC_V(4) DC_V(5) DC_V(6) DC_V(7) DC_V(8) DC_V(9)
    DC_V(10) DC_V(11) DC_V(12) DC_V(13) DC_V(14) DC_V(15) DC_V(16) DC_V(17) DC_V(18) DC_V(19)
    DC_V(20) DC_V(21) DC_V(22) DC_V(23) DC_V(24) DC_V(25) DC_V(26) DC_V(27) DC_V(28) DC_V(29)
    DC_V(30) DC_V(31) DC_V(32) DC_V(33) DC_V(34) DC_V(35) DC_V(36)
    virtual int vfunc_37(void* pRequest);
#undef DC_V
};
Unk_DictPlatform* FUN_140d86260();

// The request (search box) objects.
class Unk_DictRequest
{
public:
    Unk_DictRequest(int nId);                               // 0x1401baa00
    Unk_DictRequest(const void* pSource);                   // 0x1401baaa0
    ~Unk_DictRequest();                                     // 0x1401baaf0
    void FUN_1401bac80(const CString& strName, CStringW strValue, int n);
    int FUN_1401bab90(const CString& strName, void* pOut);
private:
    char m_pad[0x38];
};
struct Unk_DictRequestValue
{
    Unk_DictRequestValue();                                 // 0x1401ba840
    ~Unk_DictRequestValue();                                // 0x1401ba940
    char m_pad_00[8];
    CStringW m_text;                                        // +0x08
    char m_pad_10[8];
    int m_code;                                             // +0x18
    char m_pad_1c[0x1c];
};

// Input state, the movie manager, the player and the text hooks.
class Unk_DictInputState { public: char FUN_14116d9c0(int a, int b, int c); };
Unk_DictInputState* FUN_14025e7c0();
class Unk_DictUiMgr { public: int FUN_1422d4e20(const CString& strKey); };
Unk_DictUiMgr* FUN_140b632f0();
class Unk_DictPlayerMgr { public: void* FUN_141bd0cc0(); };
Unk_DictPlayerMgr* FUN_1403ed2d0();
class Unk_DictTextHook { public: void FUN_1416fbf20(CStringW& str); };
Unk_DictTextHook* FUN_1403b4750();
CStringW FUN_14028de60(int nStringId);                      // common string by id
CStringW FUN_14028b8e0(const CStringW& strKey);             // common string by key
CStringW FUN_1409eec40(int nStringId);
void FUN_140d73aa0(const CStringW& str, int a, int b, CStringW strExtra);
int FUN_14083fec0(CStringW strText, CStringW strSearch);    // find the search text (-1 = none)
struct Unk_DictStrings { CStringW FUN_141811980(int, int); };
Unk_DictStrings* FUN_1401a9d70();

// The string formatters (key by value: the callee destroys it).
CStringW FUN_140292a70(const wchar_t* szFormat, const unsigned& a);
CStringW FUN_1406e7810(const wchar_t* szFormat, const unsigned& a, const unsigned& b);
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a);
CStringW FUN_1401d0080(const CStringW& a, const CStringW& b);    // a + b (the exe's operator+; clang would import MFC CopyChars)
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& a);
CStringW FUN_14052b9d0(CStringW strKey, const unsigned short& nLevel, const CStringW& strGrade);
CStringW FUN_1406cd420(int nKind);                          // the function name of an npc kind
CStringW FUN_14083dc40(const wchar_t* szFormat, const int& a, const int& b);
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);

// ---- the unit's own helpers -----------------------------------------------------------------------------------------

// @0x140f47270
// MS2-FUNCTIONAL: the exe reads the AS value member inline (add 0x20), we call the accessor
// By-value tooltip: the callee destroys it.
void FUN_140f47270(AScript* pScript, const char* szName, ASTooltip tooltip)
{
    ASData data;
    data.FUN_1422b83f0(tooltip.FUN_1422bb890());
    FUN_1407cd930(&pScript->FUN_1422bb870(), szName, data.FUN_1422b9260());
}

// @0x140f47320
// MS2-FUNCTIONAL: the exe reads the AS value member inline (add 0x20), we call the accessor
void FUN_140f47320(AScript* pScript, const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&pScript->FUN_1422bb870(), szName, data.FUN_1422b9260());
}

// @0x140f48210
CStringW FUN_140f48210(int nHour, int nMinute)
{
    CStringW strTime = FUN_14083dc40(L"{0:02d}:{1:02d}", nHour, nMinute);
    return strTime;
}

// @0x140f47d70
UIGameDictionaryDialog::Entry::Entry()
{
    m_levelOrGrade = 0;
    m_0c = 0;
    m_id = 0;
    m_type = 1;
    m_invisibleLevel = 0;
    m_fieldId = 0;
}

// @0x140f48150
bool UIGameDictionaryDialog::Entry::operator<(const Entry& other) const
{
    if (other.m_name.Compare(m_name) > 0)
        return true;
    return false;
}

// @0x140f447d0
UIGameDictionaryDialog::UIGameDictionaryDialog()
{
    m_178 = 0;
    m_180 = L"";
    m_17c = 0;
    FUN_1422dc3b0(1);
}

// @0x140f44890
UIGameDictionaryDialog::~UIGameDictionaryDialog()
{
}

// @0x140f44900
CString UIGameDictionaryDialog::vfunc_1()
{
    return CString("GameDictionaryDialog");
}

// @0x140f44950
int UIGameDictionaryDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140f44980
void UIGameDictionaryDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140f449a0
// MS2-FUNCTIONAL: frame layout of the child-handle temporaries differs
void UIGameDictionaryDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140f452e0();
    MS2Ptr<Unk_DictInput> spInput = FUN_140e35bd0(CString("m_inputSearch"));
    if (spInput.get() != 0)
        spInput->FUN_1422e0ab0(m_180);
    MS2Ptr<Unk_DictTab> spTab = FUN_140c02870(CString("m_tab"));
    if (spTab.get() != 0)
        spTab->FUN_1422e31e0(m_178);
    if (m_17c != 0)
    {
        MS2Ptr<Unk_DictList> spItems = FUN_140c02900(CString("m_items"));
        if (spItems.get() != 0)
        {
            if (spItems->FUN_1422dcd80().FUN_1422bc5d0() != 0)
            {
                spItems->FUN_1422dcca0(0);
                spItems->vfunc_24(1);
            }
            m_17c = 0;
        }
    }
}

// @0x140f44c70
// MS2-FUNCTIONAL: frame layout of the string temporaries differs
int UIGameDictionaryDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    ASData data;
    if (_stricmp("OnSearchItem", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140f46c90(data.FUN_1422b8f40());
    }
    else if (_stricmp("OnChangeTab", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_178 = data.FUN_1422b8a10();
            m_180 = data.FUN_1422b8f40();
            FUN_140f45870();
        }
    }
    else if (_stricmp("OnItemChange", szMethod) == 0 && data.FUN_1422b9620(pArgs, nArgs) != 0)
    {
        int nId = data.FUN_1422b8a10();
        int nType = data.FUN_1422b8a10();
        CStringW strName = data.FUN_1422b8f40();
        int nGrade = data.FUN_1422b8a10();
        FUN_140f45c20(nId, nType, CStringW(strName), nGrade);
    }
    return 1;
}

// @0x140f44f20
// MS2-FUNCTIONAL: frame layout of the temporaries differs
int UIGameDictionaryDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() == 0)
    {
        if (vfunc_55() == 0 && !m_30.IsNull())
        {
            ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
            if (pDlg != 0)
            {
                if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
                {
                    if (FUN_140b632f0() != 0)
                    {
                        CString strKey(m_20);
                        if (FUN_140b632f0()->FUN_1422d4e20(strKey) == 0)
                            return 0;
                    }
                    MS2Ptr<Unk_DictInput> spInput = FUN_140e35bd0(CString("m_inputSearch"));
                    if (spInput.get() != 0)
                    {
                        if (FUN_1422c76c0(spInput.operator->()) != 0)
                            FUN_140f46c90(spInput->FUN_1422e0b00());
                    }
                    return 1;
                }
            }
        }
        return 0;
    }
    return 1;
}

// @0x140f45140
void UIGameDictionaryDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
}

// @0x140f45180
// MS2-FUNCTIONAL: frame layout of the request temporaries differs
void UIGameDictionaryDialog::vfunc_80(void* pRequest)
{
    Unk_DictRequest request(pRequest);
    Unk_DictRequestValue value;
    if (request.FUN_1401bab90("m_inputSearch", &value) == 1)
    {
        if (value.m_code == 0)
        {
            m_180 = value.m_text;
            FUN_140f45870();
        }
        else
        {
            m_180 = L"";
            FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, CStringW(L""));
        }
    }
}

// @0x140f452e0
// MS2-FUNCTIONAL: frame layout of the list temporaries differs
void UIGameDictionaryDialog::FUN_140f452e0()
{
    m_188.clear();
    if (FUN_140541580() == 0)
        return;
    std::list<std::shared_ptr<Unk_DictData> > npcs = FUN_140541580()->FUN_1403b7af0(1);
    for (std::list<std::shared_ptr<Unk_DictData> >::iterator it = npcs.begin(); it != npcs.end(); ++it)
    {
        std::shared_ptr<Unk_DictData> spData = *it;
        if (spData == nullptr)
            continue;
        Entry entry;
        entry.m_name = FUN_1401aa6a0(spData->m_id);
        entry.m_id = spData->m_id;
        entry.m_type = 1;
        if (!entry.m_name.IsEmpty())
            m_188.push_back(entry);
    }
    std::list<std::shared_ptr<Unk_DictData> > monsters = FUN_140541580()->FUN_1403b7af0(2);
    for (std::list<std::shared_ptr<Unk_DictData> >::iterator it = monsters.begin(); it != monsters.end(); ++it)
    {
        std::shared_ptr<Unk_DictData> spData = *it;
        if (spData == nullptr)
            continue;
        Entry entry;
        entry.m_name = FUN_1401aa6a0(spData->m_id);
        entry.m_id = spData->m_id;
        entry.m_type = 2;
        entry.m_levelOrGrade = spData->m_level;
        entry.m_invisibleLevel = spData->m_invisibleLevel;
        entry.m_fieldId = spData->m_fieldId;
        if (!entry.m_name.IsEmpty())
            m_188.push_back(entry);
    }
    std::list<std::shared_ptr<Unk_DictData> > items = FUN_140541580()->FUN_1403b7af0(3);
    for (std::list<std::shared_ptr<Unk_DictData> >::iterator it = items.begin(); it != items.end(); ++it)
    {
        std::shared_ptr<Unk_DictData> spData = *it;
        if (spData == nullptr)
            continue;
        Entry entry;
        entry.m_name = FUN_1401a9d70()->FUN_141811980(1, spData->m_id);
        entry.m_id = spData->m_id;
        entry.m_type = 3;
        entry.m_levelOrGrade = spData->m_grade;
        if (!entry.m_name.IsEmpty())
            m_188.push_back(entry);
    }
    m_188.sort();
}

// @0x140f45870
// MS2-FUNCTIONAL: frame layout of the list temporaries differs
void UIGameDictionaryDialog::FUN_140f45870()
{
    MS2Ptr<Unk_DictList> spItems = FUN_140c02900(CString("m_items"));
    if (!spItems.IsNull())
        return;
    spItems->FUN_1422dd1d0();
    spItems->FUN_1422dcca0(-1);
    unsigned nMask = FUN_140f46e40(m_178);
    CStringW strUnused;
    std::list<Entry> unused;
    int bFound = 0;
    for (std::list<Entry>::iterator it = m_188.begin(); it != m_188.end(); ++it)
    {
        Entry entry = *it;
        if ((FUN_140f46e40(entry.m_type) & nMask) != 0)
        {
            if (FUN_14083fec0(CStringW(m_180), CStringW(entry.m_name)) != -1)
            {
                ASObj item(2);
                item.FUN_1407cbb20("label", CStringW(entry.m_name));
                item.FUN_1407cb9c0("id", entry.m_id);
                item.FUN_1407cb9c0("itemGrade", entry.m_levelOrGrade);
                FUN_140f47320(&item, "type", entry.m_type);
                spItems->FUN_1422dd230(item);
                bFound = 1;
            }
        }
    }
    spItems->vfunc_24(1);
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0)
        pDlg->Invoke("searchResult", bFound);
}

// @0x140f46e40
unsigned UIGameDictionaryDialog::FUN_140f46e40(int nTab)
{
    switch (nTab)
    {
    case 0:
        return 7;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 4;
    default:
        return 7;
    }
}

// @0x140f46c90
// MS2-FUNCTIONAL: frame layout of the request temporaries differs
void UIGameDictionaryDialog::FUN_140f46c90(CStringW strSearch)
{
    if (strSearch.IsEmpty())
    {
        m_180 = L"";
        FUN_140f45870();
        return;
    }
    Unk_DictRequest request(0x4f0b);
    request.FUN_1401bac80("m_inputSearch", CStringW(strSearch), 0);
    int nResult = FUN_140d86260()->vfunc_37(&request);
    if (nResult == 1)
    {
        m_180 = strSearch;
        FUN_140f45870();
    }
    else if (nResult == 2)
        return;
    else
        return;
}

// @0x140f46ea0
// MS2-FUNCTIONAL: frame layout of the child-handle temporaries differs
void UIGameDictionaryDialog::FUN_140f46ea0(int nTab, CStringW strSearch, int bSelectFirst)
{
    m_17c = bSelectFirst;
    m_180 = strSearch;
    MS2Ptr<Unk_DictInput> spInput = FUN_140e35bd0(CString("m_inputSearch"));
    if (spInput.get() != 0)
        spInput->FUN_1422e0ab0(m_180);
    if (vfunc_55() == 0)
    {
        MS2Ptr<Unk_DictTab> spTab = FUN_140c02870(CString("m_tab"));
        if (spTab.get() != 0)
        {
            if (m_178 == nTab)
                FUN_140f45870();
            else
                spTab->FUN_1422e31e0(nTab);
        }
        if (m_17c != 0)
        {
            MS2Ptr<Unk_DictList> spItems = FUN_140c02900(CString("m_items"));
            if (spItems.get() != 0)
            {
                if (spItems->FUN_1422dcd80().FUN_1422bc5d0() != 0)
                {
                    spItems->FUN_1422dcca0(0);
                    spItems->vfunc_24(1);
                }
                m_17c = 0;
            }
        }
    }
    m_178 = nTab;
}

// @0x140f45c20
// MS2-FUNCTIONAL: large detail-page function: frame layout and temporary order differ
void UIGameDictionaryDialog::FUN_140f45c20(int nId, int nType, CStringW strName, int nGrade)
{
    for (std::list<Entry>::iterator it = m_188.begin(); it != m_188.end(); ++it)
    {
        Entry entry = *it;
        if (entry.m_id == nId && entry.m_type == nType && entry.m_name == strName && entry.m_levelOrGrade == nGrade)
        {
            ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
            if (pDlg != 0)
            {
                ASObj detail(2);
                detail.FUN_1407cbb20("name", CStringW(entry.m_name));
                detail.FUN_1407cb9c0("id", entry.m_id);
                detail.FUN_1407cb9c0("itemGrade", entry.m_levelOrGrade);
                FUN_140f47320(&detail, "type", entry.m_type);
                if (entry.m_type == 1)
                {
                    CNpcData* pNpc = FUN_1406cd330(entry.m_id);
                    if (pNpc != 0)
                    {
                        unsigned nField = 0;
                        unsigned nOutdoor = 0;
                        CStringW strMaps;
                        CFieldMetaTable::GetInstance()->FUN_1406fb700(entry.m_id, &nField);
                        CFieldMetaTable::GetInstance()->FUN_1406fc110(nField, &nOutdoor);
                        if (nOutdoor == 0)
                            strMaps = FUN_140292a70(L"$map:{0}$", nField);
                        else
                            strMaps = FUN_1406e7810(L"$map:{0}$ > $map:{1}$", nField, nOutdoor);
                        CStringW strContent = FUN_1408f71a0(CStringW(L"s_gamedictionary_npc_content"), strMaps, FUN_1406cd420(pNpc->GetKind()));
                        FUN_1403b4750()->FUN_1416fbf20(strContent);
                        strContent.Replace(L"#5c2b00", L"#a0a0a0");
                        detail.FUN_1407cbb20("content", CStringW(strContent));
                        detail.FUN_1407cba60("iconPath", CStringA(pNpc->m_strPortrait));
                    }
                }
                else if (entry.m_type == 2)
                {
                    CNpcData* pNpc = FUN_1406cd330(entry.m_id);
                    if (pNpc != 0)
                    {
                        int aGradeNames[8] = { 0x573, 0xaf, 0xb0, 0xb1, 0xb3, 0xb5, 0xb4, 0xb2 };
                        char aUnused[4];
                        memset(aUnused, 0, sizeof(aUnused));
                        unsigned short nLevel = pNpc->GetLevel();
                        CStringW strMini;
                        if (entry.m_invisibleLevel == 0)
                            strMini = FUN_14052b9d0(CStringW(L"s_gamedictionary_monster_mini_info"), nLevel, FUN_14028de60(aGradeNames[nGrade]));
                        else
                            strMini = FUN_1405c2690(CStringW(L"s_gamedictionary_monster_mini_info_invisible_level"), FUN_14028de60(aGradeNames[nGrade]));
                        detail.FUN_1407cbb20("npcInfo", CStringW(strMini));
                        CStringW strRace = FUN_1401a9d70()->FUN_141811980(0x11, pNpc->GetRace());
                        CStringW strMaps;
                        ATL::CAtlList<unsigned> fields(10);
                        CFieldMetaTable::GetInstance()->FUN_1406fb3a0(entry.m_id, fields);
                        if (entry.m_fieldId == 0)
                        {
                            POSITION pos = fields.GetHeadPosition();
                            while (pos != 0)
                            {
                                unsigned nFieldId = fields.GetAt(pos);
                                if (nFieldId != (unsigned)entry.m_id)
                                {
                                    if (strMaps.IsEmpty())
                                        strMaps = FUN_140292a70(L"$map:{0}$", nFieldId);
                                    else
                                        strMaps = FUN_1401d0080(strMaps, FUN_140292a70(L", $map:{0}$", nFieldId));
                                }
                                fields.GetNext(pos);
                            }
                        }
                        else
                            strMaps = FUN_140292a70(L"$map:{0}$", entry.m_fieldId);
                        if (pNpc->m_nClass == 4)
                        {
                            CMsTime time;
                            if (CFieldMetaTable::GetInstance()->FUN_1406fc620(entry.m_id, time) != 0)
                            {
                                int nMinute = time.GetMinute();
                                CStringW strClock = FUN_140f48210(time.GetHour(), nMinute);
                                CStringW strGuarantee = FUN_14028b8e0(CStringW(L"s_spawnnpc_guarantee"));
                                strMaps += L" ";
                                strMaps += FUN_1401e8510(strGuarantee, strClock);
                            }
                        }
                        CStringW strContent;
                        if (strMaps.IsEmpty())
                            strContent = FUN_1408f71a0(CStringW(L"s_gamedictionary_monster_content"), strRace, FUN_14028de60(0x573));
                        else
                            strContent = FUN_1408f71a0(CStringW(L"s_gamedictionary_monster_content"), strRace, strMaps);
                        FUN_1403b4750()->FUN_1416fbf20(strContent);
                        strContent.Replace(L"#5c2b00", L"#a0a0a0");
                        detail.FUN_1407cbb20("content", CStringW(strContent));
                        detail.FUN_1407cba60("iconPath", CStringA(pNpc->m_strPortrait));
                    }
                }
                else if (entry.m_type == 3)
                {
                    MS2Ptr<CItem> spItem(new CItem);
                    bool bValid = spItem.get() != 0;
                    if (bValid)
                    {
                        if (spItem->FUN_14052b130(entry.m_id, entry.m_levelOrGrade, 0) != 0)
                        {
                            void* pOwner = FUN_1403ed2d0()->FUN_141bd0cc0();
                            if (pOwner != 0)
                            {
                                ASTooltip tip(pOwner, 0x800, 2);
                                tip.FUN_1409e0d40(spItem.get());
                                FUN_140f47270(&detail, "tooltipData", tip);
                                detail.FUN_1407cba60("iconPath", spItem->FUN_140528590());
                            }
                        }
                    }
                }
                pDlg->Invoke("setDetailInfo", detail);
                return;
            }
        }
    }
}

// @0x140f47c60
// MS2-FUNCTIONAL: the exe's copy goes straight to AScript's copy constructor (0x1409bb7b0), not through ASObj's.
ASTooltip::ASTooltip(const ASTooltip& o)
    : ASObj(o)
    , m_40(o.m_40)
    , m_48(o.m_48)
    , m_50(o.m_50)
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca96e0-0x142ca9770 .text$yd
