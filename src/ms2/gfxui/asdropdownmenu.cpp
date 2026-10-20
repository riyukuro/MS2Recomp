// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASDropdownMenu, the CLIK DropdownMenu wrapper of the GFx UI
// library.
// MS2-UNIT: ?\asdropdownmenu.cpp
// MS2-RANGE: 0x1422df570-0x1422e07c0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asdropdownmenu.h. The rows of the "dataProvider" array are AS objects
// (ASDataProvider::FUN_1422df140 = requestItemAt); the lookups skip rows that are not valid values.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdropdownmenu.h"

#include "hook/ms2hook.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ASCallback;

bool FUN_1409b4d40(const Scaleform::GFx::Value& v);            // the value is set (not undefined / null)
CStringW FUN_1408767c0(const char* sz);                         // a UTF-8 text as a wide string

// @0x1422df570
ASDropdownMenu::ASDropdownMenu(const Scaleform::GFx::Value& v, int nMovieId)
    : ASButton(v, nMovieId)
{
}

// @0x1422df5c0
ASDropdownMenu::~ASDropdownMenu()
{
}

// @0x1422df5f0
void ASDropdownMenu::FUN_1422df5f0(unsigned nRows)
{
    FUN_1409c0d20("menuRowCount", nRows);
}
MS2_REPLACE_METHOD(0x1422DF5F0, ASDropdownMenu, FUN_1422df5f0, 40, 0x7A0CCA4B);

// @0x1422df620
unsigned ASDropdownMenu::FUN_1422df620()
{
    return (unsigned)FUN_1422baa20("menuRowCount").GetNumber();
}
MS2_REPLACE_METHOD(0x1422DF620, ASDropdownMenu, FUN_1422df620, 93, 0x40B7F249);

// @0x1422df690
void ASDropdownMenu::FUN_1422df690(int nIndex)
{
    FUN_1407cb9c0("selectedIndex", nIndex);
}
MS2_REPLACE_METHOD(0x1422DF690, ASDropdownMenu, FUN_1422df690, 40, 0x7A1DE66E);

// @0x1422df6c0
int ASDropdownMenu::FUN_1422df6c0()
{
    return FUN_1422baa20("selectedIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422DF6C0, ASDropdownMenu, FUN_1422df6c0, 88, 0x496FF0DA);

// Not hooked: v is copied into a by-value argument.
// @0x1422df720
void ASDropdownMenu::FUN_1422df720(const Scaleform::GFx::Value& v)
{
    FUN_1409adbe0("dataProvider", v);
}

// @0x1422df770
MS2Ptr<ASDataProvider> ASDropdownMenu::FUN_1422df770()
{
    return FUN_1422de460("dataProvider");
}
MS2_REPLACE_METHOD(0x1422DF770, ASDropdownMenu, FUN_1422df770, 102, 0xE0511B08);

// @0x1422df7e0
void ASDropdownMenu::FUN_1422df7e0(const CStringW& strField)
{
    FUN_1407cbb20("labelField", strField);
}
MS2_REPLACE_METHOD(0x1422DF7E0, ASDropdownMenu, FUN_1422df7e0, 72, 0xE38F5BD2);

// @0x1422df830
CStringW ASDropdownMenu::FUN_1422df830()
{
    return FUN_1422baa20("labelField").GetStringW();
}
MS2_REPLACE_METHOD(0x1422DF830, ASDropdownMenu, FUN_1422df830, 123, 0x9014A7E4);

// @0x1422df8c0
void ASDropdownMenu::FUN_1422df8c0(const CStringW& strScrollBar)
{
    FUN_1407cbb20("scrollBar", strScrollBar);
}
MS2_REPLACE_METHOD(0x1422DF8C0, ASDropdownMenu, FUN_1422df8c0, 72, 0xF873AC3B);

// @0x1422df910
CStringW ASDropdownMenu::FUN_1422df910()
{
    return FUN_1422baa20("scrollBar").GetStringW();
}
MS2_REPLACE_METHOD(0x1422DF910, ASDropdownMenu, FUN_1422df910, 123, 0x95D5B205);

// @0x1422df9a0
void ASDropdownMenu::FUN_1422df9a0(const ASCallback& cb, void* pUser)
{
    FUN_1422c3600("listIndexChange", cb, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DF9A0, ASDropdownMenu, FUN_1422df9a0, 113, 0x34C5E2DF);

// @0x1422dfa20
void ASDropdownMenu::FUN_1422dfa20(const ASCallback& cb)
{
    FUN_1422c3820("listIndexChange", cb, false);
}
MS2_REPLACE_METHOD(0x1422DFA20, ASDropdownMenu, FUN_1422dfa20, 82, 0x9C5252F7);

// @0x1422dfa80
void ASDropdownMenu::FUN_1422dfa80(const CStringW& strTitle)
{
    FUN_1407cbb20("title", strTitle);
}
MS2_REPLACE_METHOD(0x1422DFA80, ASDropdownMenu, FUN_1422dfa80, 72, 0xBB1E7B75);

// @0x1422dfad0
void ASDropdownMenu::FUN_1422dfad0()
{
    Invoke("open");
}
MS2_REPLACE_METHOD(0x1422DFAD0, ASDropdownMenu, FUN_1422dfad0, 46, 0x00D306D2);

// @0x1422dfb10
void ASDropdownMenu::FUN_1422dfb10()
{
    Invoke("close");
}
MS2_REPLACE_METHOD(0x1422DFB10, ASDropdownMenu, FUN_1422dfb10, 46, 0x60A05DC3);

// @0x1422dfb50
void ASDropdownMenu::vfunc_23()
{
    Invoke("invalidateSelectedIndex");
}
MS2_REPLACE_METHOD(0x1422DFB50, ASDropdownMenu, vfunc_23, 46, 0xB1A1A358);

// @0x1422dfb90
unsigned ASDropdownMenu::FUN_1422dfb90()
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422df770();
    if (spProvider.get())
        return spProvider->FUN_1422bc5d0();
    return 0;
}
MS2_REPLACE_METHOD(0x1422DFB90, ASDropdownMenu, FUN_1422dfb90, 114, 0x8F92B07F);

// @0x1422dfc10
void ASDropdownMenu::FUN_1422dfc10()
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422df770();
    if (spProvider.get())
        spProvider->FUN_1422df120();
}
MS2_REPLACE_METHOD(0x1422DFC10, ASDropdownMenu, FUN_1422dfc10, 83, 0xE63C0AA2);

// @0x1422dfc70
void ASDropdownMenu::FUN_1422dfc70(const ASObj& row)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422df770();
    if (spProvider.get())
        spProvider->FUN_1422bbf00(row);
}
MS2_REPLACE_METHOD(0x1422DFC70, ASDropdownMenu, FUN_1422dfc70, 93, 0xAF8585F2);

// @0x1422dfce0
void ASDropdownMenu::FUN_1422dfce0(const CStringW& strLabel)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422df770();
    if (spProvider.get()) {
        ASObj row(2);
        row.FUN_1407cbb20("label", strLabel);
        spProvider->FUN_1422bbf00(row);
    }
}
MS2_REPLACE_METHOD(0x1422DFCE0, ASDropdownMenu, FUN_1422dfce0, 185, 0xB5C5021F);

// @0x1422dfda0
void ASDropdownMenu::FUN_1422dfda0(const CStringW& strLabel)
{
    FUN_1422e0300("label", strLabel);
}
MS2_REPLACE_METHOD(0x1422DFDA0, ASDropdownMenu, FUN_1422dfda0, 79, 0x37057D01);

// @0x1422dfe00
CStringW ASDropdownMenu::FUN_1422dfe00()
{
    if (FUN_1422df6c0() < 0)
        return L"";
    if (FUN_1422df6c0() >= (int)FUN_1422dfb90())
        return L"";
    MS2Ptr<ASDataProvider> spProvider = FUN_1422df770();
    if (spProvider.get()) {
        AScript row = spProvider->FUN_1422df140(FUN_1422df6c0());
        Scaleform::GFx::Value v = row.FUN_1422baa20("label");
        if (v.IsString())
            return FUN_1408767c0(v.GetString());
        if (v.IsStringW())
            return v.GetStringW();
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1422DFE00, ASDropdownMenu, FUN_1422dfe00, 563, 0x9C3F8B63);

// @0x1422e0040
void ASDropdownMenu::FUN_1422e0040(const CString& strField, int nValue)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422df770();
    if (spProvider.get()) {
        for (unsigned __int64 i = 0; i < FUN_1422dfb90(); ++i) {
            AScript row = spProvider->FUN_1422df140((unsigned)i);
            if (FUN_1409b4d40(row.FUN_1422bb870())) {
                Scaleform::GFx::Value v = row.FUN_1422baa20(strField);
                if (v.IsString() && nValue == v.GetInt()) {
                    FUN_1422df690((int)i);
                    return;
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E0040, ASDropdownMenu, FUN_1422e0040, 342, 0x34ED6EFB);

// @0x1422e01a0
void ASDropdownMenu::FUN_1422e01a0(const CString& strField, unsigned nValue)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422df770();
    if (spProvider.get()) {
        for (unsigned __int64 i = 0; i < FUN_1422dfb90(); ++i) {
            AScript row = spProvider->FUN_1422df140((unsigned)i);
            if (FUN_1409b4d40(row.FUN_1422bb870())) {
                Scaleform::GFx::Value v = row.FUN_1422baa20(strField);
                if (v.IsString() && nValue == v.GetUInt()) {
                    FUN_1422df690((int)i);
                    return;
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E01A0, ASDropdownMenu, FUN_1422e01a0, 342, 0xFF4CC8CB);

// @0x1422e0300
void ASDropdownMenu::FUN_1422e0300(const CString& strField, const CStringW& strValue)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422df770();
    if (spProvider.get()) {
        for (unsigned __int64 i = 0; i < FUN_1422dfb90(); ++i) {
            AScript row = spProvider->FUN_1422df140((unsigned)i);
            if (FUN_1409b4d40(row.FUN_1422bb870())) {
                Scaleform::GFx::Value v = row.FUN_1422baa20(strField);
                if (v.IsString()) {
                    if (strValue == FUN_1408767c0(v.GetString())) {
                        FUN_1422df690((int)i);
                        return;
                    }
                }
                if (v.IsStringW()) {
                    if (strValue == v.GetStringW()) {
                        FUN_1422df690((int)i);
                        return;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E0300, ASDropdownMenu, FUN_1422e0300, 520, 0xB3466B0E);

// @0x1422e0510
void ASDropdownMenu::FUN_1422e0510(int nIndex)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422df770();
    if (spProvider.get())
        spProvider->FUN_1422bc660(nIndex, 1);
}
MS2_REPLACE_METHOD(0x1422E0510, ASDropdownMenu, FUN_1422e0510, 97, 0x17543C3E);

// @0x1422e0580
void ASDropdownMenu::FUN_1422e0580(const CStringW& strLabel)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422df770();
    if (spProvider.get()) {
        for (unsigned __int64 i = 0; i < FUN_1422dfb90(); ++i) {
            AScript row = spProvider->FUN_1422df140((unsigned)i);
            if (FUN_1409b4d40(row.FUN_1422bb870())) {
                Scaleform::GFx::Value v = row.FUN_1422baa20("label");
                if (v.IsString()) {
                    if (strLabel == FUN_1408767c0(v.GetString())) {
                        FUN_1422e0510((int)i);
                        return;
                    }
                }
                if (v.IsStringW()) {
                    if (strLabel == v.GetStringW()) {
                        FUN_1422e0510((int)i);
                        return;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E0580, ASDropdownMenu, FUN_1422e0580, 505, 0xB5CB57B9);

// MS2-PIN: ??_GASDropdownMenu@@UEAAPEAXI@Z 0x1422e0780
