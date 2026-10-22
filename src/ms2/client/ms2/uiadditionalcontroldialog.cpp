// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIAdditionalControlDialog: see uiadditionalcontroldialog.h.
// MS2-UNIT: ?\uiadditionalcontroldialog.cpp
// MS2-RANGE: 0x1418b25f0-0x1418b57f0 .text$mn
// MS2-RANGE: 0x14010fbc0-0x14010fe10 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalData@@@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalData@@@@@std@@@0@AEAV10@@Z 0x1418b4c70 ; prop
// MS2-PIN: ??A?$CAtlArray@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@std@@V?$CElementTraits@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@std@@@ATL@@@ATL@@QEAAAEAU?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@std@@_K@Z 0x1418b53b0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GUIAdditionalControlDialog@@UEAAPEAXI@Z 0x1418b5260
// MS2-PIN: ??1UIAdditionalControlDialog@@UEAA@XZ 0x1418b50b0
// MS2-PIN: ?begin@?$vector@V?$MS2Ptr@VAdditionalData@@@@V?$allocator@V?$MS2Ptr@VAdditionalData@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalData@@@@@std@@@std@@@2@XZ 0x1418b5600
// MS2-PIN: ?end@?$vector@V?$MS2Ptr@VAdditionalData@@@@V?$allocator@V?$MS2Ptr@VAdditionalData@@@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VAdditionalData@@@@@std@@@std@@@2@XZ 0x1418b56c0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiadditionalcontroldialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiadditionalcontroldialog.h"

#include <algorithm>
#include <utility>
#include <vector>

#include "ms2/client/ms2/statemanager_statics.h"
#include "ms2/commonfiles/additionalactionadditional.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/unnamed/unit_1401f9eb0.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the statics of the shared header (two sort-name tables, "skill", "stun", the null handle, the condition object) ----
static CString s_sortNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local placeholders (unrecovered helpers) ----

// The effect list of the movie ("m_effects" / "m_contextMenu"): an AS list control.
class Unk_AcList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(bool bVisible);
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                   // clear
    void FUN_1422dd230(const ASObj& row);                   // append a row
    int FUN_1422dd150();                                    // row count
    CStringW FUN_1422dd520();                               // label of the selected row
    void FUN_1422c79e0(int nWidth, int nHeight);            // setSize
    void FUN_1422de0e0(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb, int n);   // change handler
};

// The click event of a list row (ctor 0x1422e2740, dtor 0x140f83bb0: symbols-manual.tsv).
class ASListEvent
{
public:
    ASListEvent(const Scaleform::GFx::FunctionHandler::Params& params);
    ~ASListEvent();
    Scaleform::GFx::Value FUN_1422e2780();                  // the row object
    char m_pad[0x40];
};
class Unk_AcRow : public ASObj
{
public:
    CStringW FUN_1422bb2b0(const char* szName);             // a member as text
};

// The skill table (FUN_1401958b0).
class Unk_AcSkillTable
{
public:
    std::vector<MS2Ptr<AdditionalData> > FUN_140ab0080();                          // every additional row
    MS2Ptr<AdditionalLevelData> FUN_140aafef0(unsigned nId, unsigned short nLevel);
};
Unk_AcSkillTable* FUN_1401958b0();

class Unk_AcStringMgr { public: CStringW FUN_1422b0570(const CString& strKey); };
Unk_AcStringMgr* FUN_14025e7a0();
CStringTable* GetStringTable();
CInputKeyHandler* FUN_14025e7c0();
CStringW FUN_14083f330(const CStringW& str, wchar_t chBegin, wchar_t chEnd);      // the text between two characters
int FUN_140718200(CStringW* text);                                                 // text to number

// The request of packet 0x5c (add effect): FUN_1401fd400 writes it.
struct Unk_AcEffectReq
{
    Unk_AcEffectReq() : m_nId(0), m_nLevel(0), m_fValue(0) {}   // 0x1418b5020
    unsigned m_nId;                                             // +0x00
    unsigned short m_nLevel;                                    // +0x04
    float m_fValue;                                             // +0x08
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1418b25f0
UIAdditionalControlDialog::UIAdditionalControlDialog()
    : m_pList(0)
{
    m_40 = 1;
    FUN_1422dc3b0(1);
}

// @0x1418b2670
CString UIAdditionalControlDialog::GetTypeName()
{
    return "AdditionalEffectControlDialog";
}

// @0x1418b26c0
void UIAdditionalControlDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_1418b3620();
}

// @0x1418b26f0
void UIAdditionalControlDialog::vfunc_26()
{
    m_pList = 0;
}

// MS2-FUNCTIONAL: branch layout / temp order differs from the exe
// @0x1418b2720
int UIAdditionalControlDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() == 0) {
        if (!FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0)) {
            if (!FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0)) {
                if (!FUN_14025e7c0()->FUN_14116d840())
                    return 0;
                vfunc_67();
                return 1;
            }
            if (m_30.get() != 0)
                m_30->Invoke("onTabKey");
            return 1;
        }
        if (m_30.get() != 0)
            m_30->Invoke("onEnterKey");
        return 1;
    }
    return 1;
}

// MS2-FUNCTIONAL: branch layout / temp order differs from the exe
// @0x1418b2860
int UIAdditionalControlDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    ASData data;
    if (_stricmp("OnGroupChange", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CStringW strSearch(L"");
            FUN_1418b2e80(data.FUN_1422b8d30(), strSearch);
        }
        return 1;
    } else if (_stricmp("OnAddEffect", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            unsigned nId = data.FUN_1422b8b10();
            unsigned short nLevel = data.FUN_1422b8b10();
            double dValue = data.FUN_1422b8ca0();
            MS2Ptr<AdditionalLevelData> spLevel = FUN_1401958b0()->FUN_140aafef0(nId, nLevel);
            if (spLevel.get() != 0) {
                Unk_AcEffectReq req;
                req.m_nId = nId;
                req.m_nLevel = nLevel;
                req.m_fValue = (float)dValue;
                COutPacket packet(static_cast<int>(SendOp::RequestAdditionalEffect), 0);
                packet.vfunc_o10_1(0);
                FUN_1401fd400((unsigned char*)&req, packet);
                FUN_140710590(packet);
            }
        }
        return 1;
    } else if (_stricmp("OnResetEffect", szMethod) == 0) {
        COutPacket packet(static_cast<int>(SendOp::RequestAdditionalEffect), 0);
        packet.vfunc_o10_1(1);
        FUN_140710590(packet);
    } else if (_stricmp("OnSearchItem", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CString strGroup("");
            FUN_1418b2e80(strGroup, data.FUN_1422b8f40());
        }
        return 1;
    }
    return 0;
}

// The context menu click: "openXml" opens Data/Xml/Additional/NNN.xml of the selected effect.
// MS2-FUNCTIONAL: branch layout / temp order differs from the exe
// @0x1418b2c20
void UIAdditionalControlDialog::FUN_1418b2c20(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0 || m_pList == 0)
        return;
    ASListEvent evt(params);
    Scaleform::GFx::Value target = evt.FUN_1422e2780();
    ASObj row(target, 2);
    if (row.FUN_1422ba9a0())
        return;
    CStringW strFunc = ((Unk_AcRow*)&row)->FUN_1422bb2b0("func");
    if (strFunc.IsEmpty())
        return;
    unsigned nId = FUN_1418b3ac0();
    if (nId == 0)
        return;
    CString strPath;
    strPath.Format("./Data/Xml/Additional/%03d.xml", nId / 100000ULL);
    strPath.Replace('/', '\\');
    if (strFunc.CompareNoCase(L"openXml") == 0)
        ShellExecuteA(0, "open", strPath, 0, 0, 1);
    else
        strFunc.CompareNoCase(L"openFolder");
}

// MS2-FUNCTIONAL: branch layout / temp order differs from the exe
// @0x1418b2e80
void UIAdditionalControlDialog::FUN_1418b2e80(const CString& strGroup, const CStringW& strSearch)
{
    MS2Ptr<Unk_AcList> list = FUN_140c02900("m_effects");
    if (!list)
        return;
    list->FUN_1422dd1d0();
    std::vector<MS2Ptr<AdditionalData> > vecData = FUN_1401958b0()->FUN_140ab0080();
    std::sort(vecData.begin(), vecData.end(), [](const MS2Ptr<AdditionalData>& a, const MS2Ptr<AdditionalData>& b) {
        return a->GetID() < b->GetID();
    });
    size_t nCount = vecData.size();
    for (size_t i = 0; i < nCount; ++i) {
        MS2Ptr<AdditionalData> data = vecData[i];
        if (!data)
            continue;
        unsigned nId = data->GetID();
        std::vector<MS2Ptr<AdditionalLevelData> > levels;
        data->GetLevels(levels);
        for (MS2Ptr<AdditionalLevelData> level : levels) {
            CStringW strLabel;
            CStringW strUnused;
            int nPassive = 0;
            CStringW strName = GetStringTable()->FUN_141812290(nId, level->GetLevel(), CString("name"));
            strLabel.Format(L"[%ld] [Lv.%d] %s", nId, level->GetLevel(), (LPCWSTR)strName);
            if (level->m_nKeepCondition == 99) {
                strLabel.Append(FUN_14025e7a0()->FUN_1422b0570("$s_additionaleffect_control_dialog_name_passive"));
                nPassive = 1;
            }
            if (!level->IsBuff())
                strLabel.Append(FUN_14025e7a0()->FUN_1422b0570("$s_additionaleffect_control_dialog_name_debuff"));
            else
                strLabel.Append(FUN_14025e7a0()->FUN_1422b0570("$s_additionaleffect_control_dialog_name_buff"));
            ASObj row(2);
            row.FUN_1407cbb20("label", strLabel);
            row.FUN_1409c0d20("effectCode", nId);
            row.FUN_1409c48f0("effectLevel", level->GetLevel());
            row.FUN_1407cb9c0("isPassive", nPassive);
            if (strSearch.IsEmpty()) {
                if (strGroup == "BF") {
                    if (level->IsBuff())
                        list->FUN_1422dd230(row);
                }
                if (strGroup == "DF") {
                    if (!level->IsBuff())
                        list->FUN_1422dd230(row);
                }
            } else if (strLabel.Find(strSearch, 0) != -1) {
                list->FUN_1422dd230(row);
            }
        }
    }
    list->vfunc_24(true);
}

// MS2-FUNCTIONAL: branch layout / temp order differs from the exe
// @0x1418b3620
void UIAdditionalControlDialog::FUN_1418b3620()
{
    if (m_pList = FUN_140c02900("m_contextMenu")) {
        bool bFlag = GetFileSystem()->FUN_140398190();
        m_pList->vfunc_3(!bFlag);
        if (!bFlag) {
            ATL::CAtlArray<std::pair<CStringW, CStringW> > items;
            items.Add(std::pair<CStringW, CStringW>(L"$s_additionaleffect_control_dialog_open_xml", L"openXml"));
            items.Add(std::pair<CStringW, CStringW>(L"$s_additionaleffect_control_dialog_open_folder", L"openFolder"));
            for (size_t i = 0; i < items.GetCount(); ++i) {
                if (!items[i].first.IsEmpty()) {
                    ASObj row(2);
                    row.FUN_1407cbb20("label", items[i].first);
                    row.FUN_1407cbb20("func", items[i].second);
                    m_pList->FUN_1422dd230(row);
                }
            }
            m_pList->FUN_1422c79e0(0x78, m_pList->FUN_1422dd150() * 0x1a);
            m_pList->vfunc_24(true);
            Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb(this, &UIAdditionalControlDialog::FUN_1418b2c20);
            m_pList->FUN_1422de0e0(cb, 0);
        } else {
            m_pList = 0;
        }
    }
}

// @0x1418b3ac0
unsigned UIAdditionalControlDialog::FUN_1418b3ac0()
{
    MS2Ptr<Unk_AcList> list = FUN_140c02900("m_effects");
    if (!list)
        return 0;
    CStringW strLabel = list->FUN_1422dd520();
    if (strLabel.IsEmpty())
        return 0;
    CStringW strId = FUN_14083f330(strLabel, L'[', L']');
    return FUN_140718200(&strId);
}

// @0x1418b50b0
UIAdditionalControlDialog::~UIAdditionalControlDialog()
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbc890-0x142cbc950 .text$yd
