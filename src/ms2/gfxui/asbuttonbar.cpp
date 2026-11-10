// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASButtonBar, the CLIK ButtonBar (tab strip) wrapper of the
// GFx UI library.
// MS2-UNIT: ?\asbuttonbar.cpp
// MS2-RANGE: 0x1422e2cd0-0x1422e4490 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asbuttonbar.h. The entries are the AS objects of the "dataProvider" array
// (ASDataProvider::FUN_1422df140 = requestItemAt); the label lookups skip entries that are not valid values. The obj's
// COMDAT tail is the Invoke(method, Value, unsigned) instance 0x1422e4350 (AScript::FUN_1422e4350) and the scalar deleting dtor.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"

#include "hook/ms2hook.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ASCallback;

CStringW XmlWide(const char* sz);                         // a UTF-8 text as a wide string
void SetValue(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);   // Value = v (an ASArray COMDAT)
void SetUInt(Scaleform::GFx::Value* pValue, unsigned int n);           // Value = n (UInt)

// @0x1422e2cd0
ASButtonBar::ASButtonBar(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1422e2d20
ASButtonBar::~ASButtonBar()
{
}

// Not hooked: spProvider is destroyed by the callee.
// @0x1422e2d50
void ASButtonBar::SetDataProviderPtr(MS2Ptr<ASDataProvider> spProvider)
{
    if (spProvider.get())
        SetDataProvider(spProvider->GetValue());
}

// Not hooked: v is copied into a by-value argument.
// @0x1422e2db0
void ASButtonBar::SetDataProvider(const Scaleform::GFx::Value& v)
{
    FUN_1409adbe0("dataProvider", v);
}

// @0x1422e2e00
MS2Ptr<ASDataProvider> ASButtonBar::GetDataProvider()
{
    return FUN_1422de460<ASDataProvider>("dataProvider");
}
MS2_REPLACE_METHOD(0x1422E2E00, ASButtonBar, GetDataProvider, 102, 0x837D2527);

// @0x1422e2e70
void ASButtonBar::SetItemRendererName(const CString& strName)
{
    SetStringMember("itemRendererName", strName);
}
MS2_REPLACE_METHOD(0x1422E2E70, ASButtonBar, SetItemRendererName, 72, 0x3FB735DA);

// @0x1422e2ec0
void ASButtonBar::SetSpacing(float f)
{
    SetMemberFloat("spacing", f);
}
MS2_REPLACE_METHOD(0x1422E2EC0, ASButtonBar, SetSpacing, 43, 0x97E6E69D);

// @0x1422e2f00
float ASButtonBar::GetSpacing()
{
    return (float)GetMember("spacing").GetNumber();
}
MS2_REPLACE_METHOD(0x1422E2F00, ASButtonBar, GetSpacing, 96, 0x57856D9E);

// @0x1422e2f70
void ASButtonBar::SetDirection(const CString& strDirection)
{
    SetStringMember("direction", strDirection);
}
MS2_REPLACE_METHOD(0x1422E2F70, ASButtonBar, SetDirection, 72, 0xA35D62FF);

// @0x1422e2fc0
CString ASButtonBar::GetDirection()
{
    return GetMember("direction").GetString();
}
MS2_REPLACE_METHOD(0x1422E2FC0, ASButtonBar, GetDirection, 123, 0xE6340C39);

// @0x1422e3050
void ASButtonBar::SetAutoSize(const CString& strAutoSize)
{
    SetStringMember("autoSize", strAutoSize);
}
MS2_REPLACE_METHOD(0x1422E3050, ASButtonBar, SetAutoSize, 72, 0x13410844);

// @0x1422e30a0
CString ASButtonBar::GetAutoSize()
{
    return GetMember("autoSize").GetString();
}
MS2_REPLACE_METHOD(0x1422E30A0, ASButtonBar, GetAutoSize, 123, 0x3E8F981B);

// @0x1422e3130
void ASButtonBar::SetButtonWidth(float f)
{
    SetMemberFloat("buttonWidth", f);
}
MS2_REPLACE_METHOD(0x1422E3130, ASButtonBar, SetButtonWidth, 43, 0x72FEE434);

// @0x1422e3170
float ASButtonBar::GetButtonWidth()
{
    return (float)GetMember("buttonWidth").GetNumber();
}
MS2_REPLACE_METHOD(0x1422E3170, ASButtonBar, GetButtonWidth, 96, 0x094D4B6A);

// @0x1422e31e0
void ASButtonBar::SetSelectedIndex(int nIndex)
{
    SetIntMember("selectedIndex", nIndex);
}
MS2_REPLACE_METHOD(0x1422E31E0, ASButtonBar, SetSelectedIndex, 40, 0x0E3A2053);

// @0x1422e3210
int ASButtonBar::GetSelectedIndex()
{
    return GetMember("selectedIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422E3210, ASButtonBar, GetSelectedIndex, 88, 0xDB4B97FB);

// @0x1422e3270
void ASButtonBar::InvalidateSettings()
{
    Invoke("invalidateSettings");
}
MS2_REPLACE_METHOD(0x1422E3270, ASButtonBar, InvalidateSettings, 46, 0xF23C56FE);

// @0x1422e32b0
MS2Ptr<ASButton> ASButtonBar::GetButtonAt(int nIndex)
{
    Scaleform::GFx::Value v = Invoke("getButtonAt", nIndex);
    return MS2Ptr<ASButton>(new ASButton(v, m_nMovieId));
}
MS2_REPLACE_METHOD(0x1422E32B0, ASButtonBar, GetButtonAt, 198, 0xE4075A79);

// @0x1422e3380
unsigned ASButtonBar::GetItemCount()
{
    MS2Ptr<ASDataProvider> spProvider = GetDataProvider();
    if (spProvider.get())
        return spProvider->GetLength();
    return 0;
}
MS2_REPLACE_METHOD(0x1422E3380, ASButtonBar, GetItemCount, 114, 0x9038E735);

// @0x1422e3400
void ASButtonBar::ClearDataProvider()
{
    MS2Ptr<ASDataProvider> spProvider = GetDataProvider();
    if (spProvider.get())
        spProvider->Clear();
}
MS2_REPLACE_METHOD(0x1422E3400, ASButtonBar, ClearDataProvider, 83, 0x6E710504);

// @0x1422e3460
void ASButtonBar::AddItem(const ASObj& item)
{
    MS2Ptr<ASDataProvider> spProvider = GetDataProvider();
    if (spProvider.get())
        spProvider->PushObj(item);
}
MS2_REPLACE_METHOD(0x1422E3460, ASButtonBar, AddItem, 93, 0x213F3009);

// @0x1422e34d0
void ASButtonBar::AddLabelItem(const CStringW& strLabel)
{
    MS2Ptr<ASDataProvider> spProvider = GetDataProvider();
    if (spProvider.get()) {
        ASObj item(2);
        item.SetWStringMember("label", strLabel);
        spProvider->PushObj(item);
    }
}
MS2_REPLACE_METHOD(0x1422E34D0, ASButtonBar, AddLabelItem, 185, 0xE6038828);

// @0x1422e3590
void ASButtonBar::FUN_1422e3590(const CStringW& strLabel)
{
    MS2Ptr<ASDataProvider> spProvider = GetDataProvider();
    if (spProvider.get()) {
        for (unsigned __int64 i = 0; i < GetItemCount(); ++i) {
            AScript row = spProvider->GetItemAt((unsigned)i);
            if (row.GetValue().IsObject()) {
                Scaleform::GFx::Value v = row.GetMember("label");
                if (v.IsString()) {
                    if (strLabel == XmlWide(v.GetString())) {
                        SetSelectedIndex((int)i);
                        return;
                    }
                }
                if (v.IsStringW()) {
                    if (strLabel == v.GetStringW()) {
                        SetSelectedIndex((int)i);
                        return;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E3590, ASButtonBar, FUN_1422e3590, 505, 0x92EB0A6F);

// @0x1422e3790
CStringW ASButtonBar::GetSelectedLabel()
{
    return GetLabelAt(GetSelectedIndex());
}
MS2_REPLACE_METHOD(0x1422E3790, ASButtonBar, GetSelectedLabel, 71, 0x2A51A5A6);

// @0x1422e37e0
CStringW ASButtonBar::GetLabelAt(int nIndex)
{
    if (nIndex < 0)
        return L"";
    if (nIndex >= (int)GetItemCount())
        return L"";
    MS2Ptr<ASDataProvider> spProvider = GetDataProvider();
    if (spProvider.get()) {
        AScript row = spProvider->GetItemAt(nIndex);
        Scaleform::GFx::Value v = row.GetMember("label");
        if (v.IsString())
            return XmlWide(v.GetString());
        if (v.IsStringW())
            return v.GetStringW();
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1422E37E0, ASButtonBar, GetLabelAt, 529, 0x4CB6A1F5);

// @0x1422e3a00
void ASButtonBar::RemoveItemAt(int nIndex)
{
    MS2Ptr<ASDataProvider> spProvider = GetDataProvider();
    if (spProvider.get())
        spProvider->Splice(nIndex, 1);
}
MS2_REPLACE_METHOD(0x1422E3A00, ASButtonBar, RemoveItemAt, 97, 0xFB2142D9);

// @0x1422e3a70
void ASButtonBar::RemoveItemByLabel(const CStringW& strLabel)
{
    MS2Ptr<ASDataProvider> spProvider = GetDataProvider();
    if (spProvider.get()) {
        for (unsigned __int64 i = 0; i < GetItemCount(); ++i) {
            AScript row = spProvider->GetItemAt((unsigned)i);
            if (row.GetValue().IsObject()) {
                Scaleform::GFx::Value v = row.GetMember("label");
                if (v.IsString()) {
                    if (strLabel == XmlWide(v.GetString())) {
                        RemoveItemAt((int)i);
                        return;
                    }
                }
                if (v.IsStringW()) {
                    if (strLabel == v.GetStringW()) {
                        RemoveItemAt((int)i);
                        return;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E3A70, ASButtonBar, RemoveItemByLabel, 505, 0x203DC3CE);

// @0x1422e3c70
void ASButtonBar::FUN_1422e3c70(const CStringW& strOld, const CStringW& strNew)
{
    MS2Ptr<ASDataProvider> spProvider = GetDataProvider();
    if (spProvider.get()) {
        for (unsigned __int64 i = 0; i < GetItemCount(); ++i) {
            AScript row = spProvider->GetItemAt((unsigned)i);
            if (row.GetValue().IsObject()) {
                Scaleform::GFx::Value v = row.GetMember("label");
                if (v.IsString()) {
                    if (strOld == XmlWide(v.GetString())) {
                        row.SetWStringMember("label", strNew);
                        return;
                    }
                }
                if (v.IsStringW()) {
                    if (strOld == v.GetStringW()) {
                        row.SetWStringMember("label", strNew);
                        return;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E3C70, ASButtonBar, FUN_1422e3c70, 607, 0xB79646FE);

// @0x1422e3ee0
int ASButtonBar::FUN_1422e3ee0(const CString& strField, Scaleform::GFx::Value& vOut)
{
    if (GetSelectedIndex() < 0)
        return 0;
    if (GetSelectedIndex() >= (int)GetItemCount())
        return 0;
    MS2Ptr<ASDataProvider> spProvider = GetDataProvider();
    if (spProvider.get()) {
        AScript row = spProvider->GetItemAt(GetSelectedIndex());
        vOut = row.GetMember(strField);
        if (!vOut.IsNull())
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422E3EE0, ASButtonBar, FUN_1422e3ee0, 369, 0xBEFC5CC9);

// @0x1422e4060
void ASButtonBar::UpdateRendererAt(int nIndex)
{
    if (nIndex >= GetItemCount())
        return;
    MS2Ptr<ASButton> spButton = GetButtonAt(nIndex);
    if (spButton == 0 || spButton->IsUndefinedOrNull())
        return;
    FUN_1422e4350("updateRendererAt", spButton->GetValue(), (unsigned)nIndex);
    spButton->vfunc_24(false);
}
MS2_REPLACE_METHOD(0x1422E4060, ASButtonBar, UpdateRendererAt, 293, 0x0444936C);

// @0x1422e4190
void ASButtonBar::AddIndexChangeHandler(const ASCallback& onChange, void* pUser)
{
    AddEventListener("clikIndexChange", onChange, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422E4190, ASButtonBar, AddIndexChangeHandler, 113, 0xB9C8204A);

// @0x1422e4210
void ASButtonBar::RemoveIndexChangeHandler(const ASCallback& onChange)
{
    RemoveEventListener("clikIndexChange", onChange, false);
}
MS2_REPLACE_METHOD(0x1422E4210, ASButtonBar, RemoveIndexChangeHandler, 82, 0x8837210A);

// @0x1422e4270
void ASButtonBar::AddListIndexChangeHandler(const ASCallback& onMenu, void* pUser)
{
    AddEventListener("listIndexChange", onMenu, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422E4270, ASButtonBar, AddListIndexChangeHandler, 113, 0x24EA6C5E);

// @0x1422e42f0
void ASButtonBar::RemoveListIndexChangeHandler(const ASCallback& onMenu)
{
    RemoveEventListener("listIndexChange", onMenu, false);
}
MS2_REPLACE_METHOD(0x1422E42F0, ASButtonBar, RemoveListIndexChangeHandler, 82, 0xFFCAAB47);

// @0x1422e4350
Scaleform::GFx::Value AScript::FUN_1422e4350(const char* szMethod, Scaleform::GFx::Value a1, unsigned a2)
{
    ASArgList args;
    args.resize(2);
    SetValue(&args[0], a1);
    SetUInt(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

// MS2-PIN: ??_GASButtonBar@@UEAAPEAXI@Z 0x1422e4450
