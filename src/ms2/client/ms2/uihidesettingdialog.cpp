// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHideSettingDialog: see uihidesettingdialog.h.
// MS2-UNIT: ?\uihidesettingdialog.cpp
// MS2-RANGE: 0x141986d90-0x14198aca0 .text$mn
// MS2-RANGE: 0x1401148e0-0x140114a70 .text$di
// MS2-RANGE: 0x142cbe960-0x142cbe9f0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIHideSettingDialog@@UEAAHXZ 0x1419897e0 ; unique
// MS2-PINS-END tplpin
//
// Split off the unit map's low-confidence ?\uiheadupdisplay.cpp run (0x141986b50-0x141991700): this CU starts with the
// SwfInfo ctor after UIHeadUpDisplay's inline vfunc_48 and ends before UIHouseMarkEntity's ctor. File name assumed (the
// class name; the exe has no assert path for it). The COMDAT tail: the UI lookups by type id (GetUI<T>), the
// CAtlMap<CString, MS2Ptr<SwfInfo>> of the entries, MS2Ptr<SwfInfo> and the three vector<MS2Ptr<AScript>> list groups.
// MS2-PIN: ?GetValueAt@?$CAtlMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@USwfInfo@UIHideSettingDialogDef@@@@V?$CStringElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@USwfInfo@UIHideSettingDialogDef@@@@@2@@ATL@@QEAAAEAV?$MS2Ptr@USwfInfo@UIHideSettingDialogDef@@@@PEAU__POSITION@@@Z 0x1419897f0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@USwfInfo@UIHideSettingDialogDef@@@@AEBAXPEAX@Z 0x14198a4a0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihidesettingdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uihidesettingdialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uiswfentitymanager.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <string.h>
#include <vector>

#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uihidesettingdialog_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION

// ---- unit-local placeholders ----

// The UI manager (singleton): UIs by type id and their hidden/shown state.
class Unk_1403ed2b0
{
public:
    void FUN_141adc530(int nId);                                    // show the UI nId
    void FUN_141adc5d0(int nId);                                    // hide the UI nId
    int FUN_141adc940(int nId);                                     // nonzero: the UI nId is hidden
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                        // the UI of type nId (NULL if not created)
};
Unk_1403ed2b0* FUN_1403ed2b0();

// The key input state (singleton).
class Unk_14025e7c0 { public: bool FUN_14116d9c0(int nKey, int a, int b); };
Unk_14025e7c0* FUN_14025e7c0();

// The UI of type nId as a T (inline header template; one COMDAT per T: 0x141988290 UISwfEntity, 0x1419881f0
// UIHeadUpDisplay).
template <class T>
inline T* FUN_GetUI(int nId)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>(p.operator->());
    }
    return 0;
}

using UIHideSettingDialogDef::SwfInfo;

// @0x141986d90
SwfInfo::SwfInfo()
    : m_nId(0), m_nType(2)
{
}

// @0x141986df0
void SwfInfo::FUN_141986df0(ASObj& obj, bool bSelected)
{
    obj.FUN_1407cbb20("name", m_strName);
    obj.FUN_1407cbb20("label", m_strName);
    obj.FUN_1407cbbe0("selected", bSelected);
}
MS2_REPLACE_METHOD(0x141986DF0, SwfInfo, FUN_141986df0, 167, 0xAFD655E5);

// @0x141986ea0
UIHideSettingDialog::UIHideSettingDialog()
{
    m_40 = 1;
}

// @0x141986f30
UIHideSettingDialog::~UIHideSettingDialog()
{
    m_178.RemoveAll();
}

// @0x141986fa0
CString UIHideSettingDialog::GetTypeName()
{
    return "HideSettingDialog";
}
MS2_REPLACE_METHOD(0x141986FA0, UIHideSettingDialog, GetTypeName, 61, 0x2D4C293C);

// @0x141986ff0
void UIHideSettingDialog::vfunc_10()
{
    m_178.RemoveAll();
}
MS2_REPLACE_METHOD(0x141986FF0, UIHideSettingDialog, vfunc_10, 33, 0x8D2D82B0);

// Not hooked: FUN_141987f50 creates SwfInfo objects (their vftable/RTTI would be the DLL's).
// @0x141987020
void UIHideSettingDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_178.IsEmpty()) {
        FUN_141987f50(0x4e51, L"");
        FUN_141987f50(0x4e32, L"");
        FUN_141987f50(0x4e3c, L"");
        FUN_141987f50(0x4e3d, L"");
        FUN_141987f50(0x4ebe, L"");
        FUN_141987f50(0x4e41, L"");
        FUN_141987f50(0x4e27, L"");
        FUN_141987f50(0x4f66, L"");
        FUN_141987f50(0x4e5d, L"");
        FUN_141987f50(0x4e28, L"");
        FUN_141987f50(0x4e5f, L"");
        FUN_141987f50(0x4e61, L"");
        FUN_141987f50(0x4e29, L"");
        FUN_141987f50(0x4e45, L"");
        FUN_141987f50(0x4f5e, L"");
        FUN_141987f50(0x4f75, L"");
        FUN_141987f50(0x4e43, L"");
    }
    FUN_141987990();
}

// @0x141987450
int UIHideSettingDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0)) {
        if (m_30.get())
            m_30->Invoke("onEnterKey");
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141987450, UIHideSettingDialog, vfunc_13, 144, 0xEB361A20);

// @0x1419874f0
int UIHideSettingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    if (!_stricmp("OnConfirm", szMethod)) {
        ASData data;
        data.FUN_1422b9620(pArgs, nArgs);
        return 1;
    } else if (!_stricmp("OnCheck", szMethod)) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            bool bChecked = data.FUN_1422b8a90();
            CString strName = data.FUN_1422b8d30();
            ATL::CAtlMap<CString, MS2Ptr<SwfInfo>, ATL::CStringElementTraits<CString> >::CPair* pPair = m_178.Lookup(strName);
            if (pPair) {
                MS2Ptr<SwfInfo> info = pPair->m_value;
                if ((SwfInfo*)info) {
                    if (info->m_nType == 0) {
                        UIHeadUpDisplay* pHud = FUN_GetUI<UIHeadUpDisplay>(info->m_nId);
                        if (pHud) {
                            if (bChecked) {
                                FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(pHud));
                                pHud->vfunc_3();
                            } else {
                                FUN_140b632f0()->FUN_1422d0cd0(MS2Ptr<UISwfEntity>(pHud));
                                pHud->vfunc_2();
                            }
                        }
                    } else if (info->m_nType == 1) {
                        int nId = info->m_nId;
                        UISwfEntity* pEntity = FUN_GetUI<UISwfEntity>(nId);
                        if (pEntity) {
                            if (bChecked) {
                                FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(pEntity));
                                FUN_1403ed2b0()->FUN_141adc5d0(nId);
                            } else {
                                FUN_140b632f0()->FUN_1422d0cd0(MS2Ptr<UISwfEntity>(pEntity));
                                FUN_1403ed2b0()->FUN_141adc530(nId);
                            }
                        }
                    } else {
                        int nId = info->m_nId;
                        UISwfEntity* pEntity = FUN_GetUI<UISwfEntity>(nId);
                        if (pEntity) {
                            if (bChecked)
                                FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(pEntity));
                            else
                                FUN_140b632f0()->FUN_1422d0cd0(MS2Ptr<UISwfEntity>(pEntity));
                        }
                    }
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419874F0, UIHideSettingDialog, vfunc_28, 1160, 0xE5C8B991);

// @0x141987990
void UIHideSettingDialog::FUN_141987990()
{
    if (m_30.get()) {
        std::vector<MS2Ptr<AScript> > lists[3];
        for (POSITION pos = m_178.GetStartPosition(); pos; m_178.GetNext(pos)) {
            MS2Ptr<SwfInfo> info = m_178.GetValueAt(pos);
            if (info == 0)
                continue;
            MS2Ptr<AScript> obj(new AScript(FUN_1422db730()));
            if (obj == 0)
                continue;
            bool bSelected = false;
            if (info->m_nType == 1) {
                if (FUN_1403ed2b0()->FUN_141adc940(info->m_nId))
                    bSelected = true;
            } else {
                UISwfEntity* pEntity = FUN_GetUI<UISwfEntity>(info->m_nId);
                if (!pEntity || pEntity->FUN_1422dba00() == 0)
                    bSelected = true;
            }
            info->FUN_141986df0((ASObj&)*obj, bSelected);
            lists[info->m_nType].push_back(obj);
        }
        ASArray all(2);
        for (int i = 0; i < 3; i++) {
            ASObj group(2);
            group.FUN_1407cb9c0("type", i);
            {
                ASArray list(2);
                const std::vector<MS2Ptr<AScript> >& entries = lists[i];
                for (size_t j = 0; j < entries.size(); j++)
                    list.FUN_1422bc050(entries[j]->FUN_1422bb870());
                group.FUN_1409adbe0("list", list.FUN_1422bb870());
            }
            all.FUN_1422bc050(group.FUN_1422bb870());
        }
        m_30->Invoke("buildList", all.FUN_1422bb870());
    }
}
MS2_REPLACE_METHOD(0x141987990, UIHideSettingDialog, FUN_141987990, 1456, 0x4BE9B7A9);

// @0x141987f50
void UIHideSettingDialog::FUN_141987f50(int nId, const CStringW& strLabel)
{
    MS2Ptr<SwfInfo> info(new SwfInfo);
    if (info == 0)
        return;
    UISwfEntity* pEntity = FUN_GetUI<UISwfEntity>(nId);
    if (!pEntity)
        return;
    info->m_nId = nId;
    if (strLabel.IsEmpty())
        info->m_strName = (const char*)pEntity->GetTypeName();
    else
        info->m_strName = strLabel;
    if (UIDialog* pDialog = dynamic_cast<UIDialog*>(pEntity))
        info->m_nType = 1;
    else if (UIHeadUpDisplay* pHud = dynamic_cast<UIHeadUpDisplay*>(pEntity))
        info->m_nType = 0;
    m_178.SetAt((const char*)pEntity->GetTypeName(), info);
}
