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

bool FUN_1409b4d40(const Scaleform::GFx::Value& v);            // the value is set (not undefined / null)
CStringW FUN_1408767c0(const char* sz);                         // a UTF-8 text as a wide string
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);   // Value = v (an ASArray COMDAT)
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);           // Value = n (UInt)

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
void ASButtonBar::FUN_1422e2d50(MS2Ptr<ASDataProvider> spProvider)
{
    if (spProvider.get())
        FUN_1422e2db0(spProvider->FUN_1422bb870());
}

// Not hooked: v is copied into a by-value argument.
// @0x1422e2db0
void ASButtonBar::FUN_1422e2db0(const Scaleform::GFx::Value& v)
{
    FUN_1409adbe0("dataProvider", v);
}

// @0x1422e2e00
MS2Ptr<ASDataProvider> ASButtonBar::FUN_1422e2e00()
{
    return FUN_1422de460("dataProvider");
}
MS2_REPLACE_METHOD(0x1422E2E00, ASButtonBar, FUN_1422e2e00, 102, 0x837D2527);

// @0x1422e2e70
void ASButtonBar::FUN_1422e2e70(const CString& strName)
{
    FUN_1407cba60("itemRendererName", strName);
}
MS2_REPLACE_METHOD(0x1422E2E70, ASButtonBar, FUN_1422e2e70, 72, 0x3FB735DA);

// @0x1422e2ec0
void ASButtonBar::FUN_1422e2ec0(float f)
{
    FUN_1409c4a30("spacing", f);
}
MS2_REPLACE_METHOD(0x1422E2EC0, ASButtonBar, FUN_1422e2ec0, 43, 0x97E6E69D);

// @0x1422e2f00
float ASButtonBar::FUN_1422e2f00()
{
    return (float)FUN_1422baa20("spacing").GetNumber();
}
MS2_REPLACE_METHOD(0x1422E2F00, ASButtonBar, FUN_1422e2f00, 96, 0x57856D9E);

// @0x1422e2f70
void ASButtonBar::FUN_1422e2f70(const CString& strDirection)
{
    FUN_1407cba60("direction", strDirection);
}
MS2_REPLACE_METHOD(0x1422E2F70, ASButtonBar, FUN_1422e2f70, 72, 0xA35D62FF);

// @0x1422e2fc0
CString ASButtonBar::FUN_1422e2fc0()
{
    return FUN_1422baa20("direction").GetString();
}
MS2_REPLACE_METHOD(0x1422E2FC0, ASButtonBar, FUN_1422e2fc0, 123, 0xE6340C39);

// @0x1422e3050
void ASButtonBar::FUN_1422e3050(const CString& strAutoSize)
{
    FUN_1407cba60("autoSize", strAutoSize);
}
MS2_REPLACE_METHOD(0x1422E3050, ASButtonBar, FUN_1422e3050, 72, 0x13410844);

// @0x1422e30a0
CString ASButtonBar::FUN_1422e30a0()
{
    return FUN_1422baa20("autoSize").GetString();
}
MS2_REPLACE_METHOD(0x1422E30A0, ASButtonBar, FUN_1422e30a0, 123, 0x3E8F981B);

// @0x1422e3130
void ASButtonBar::FUN_1422e3130(float f)
{
    FUN_1409c4a30("buttonWidth", f);
}
MS2_REPLACE_METHOD(0x1422E3130, ASButtonBar, FUN_1422e3130, 43, 0x72FEE434);

// @0x1422e3170
float ASButtonBar::FUN_1422e3170()
{
    return (float)FUN_1422baa20("buttonWidth").GetNumber();
}
MS2_REPLACE_METHOD(0x1422E3170, ASButtonBar, FUN_1422e3170, 96, 0x094D4B6A);

// @0x1422e31e0
void ASButtonBar::FUN_1422e31e0(int nIndex)
{
    FUN_1407cb9c0("selectedIndex", nIndex);
}
MS2_REPLACE_METHOD(0x1422E31E0, ASButtonBar, FUN_1422e31e0, 40, 0x0E3A2053);

// @0x1422e3210
int ASButtonBar::FUN_1422e3210()
{
    return FUN_1422baa20("selectedIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422E3210, ASButtonBar, FUN_1422e3210, 88, 0xDB4B97FB);

// @0x1422e3270
void ASButtonBar::FUN_1422e3270()
{
    Invoke("invalidateSettings");
}
MS2_REPLACE_METHOD(0x1422E3270, ASButtonBar, FUN_1422e3270, 46, 0xF23C56FE);

// @0x1422e32b0
MS2Ptr<ASButton> ASButtonBar::FUN_1422e32b0(int nIndex)
{
    Scaleform::GFx::Value v = Invoke("getButtonAt", nIndex);
    return MS2Ptr<ASButton>(new ASButton(v, m_nMovieId));
}
MS2_REPLACE_METHOD(0x1422E32B0, ASButtonBar, FUN_1422e32b0, 198, 0xE4075A79);

// @0x1422e3380
unsigned ASButtonBar::FUN_1422e3380()
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422e2e00();
    if (spProvider.get())
        return spProvider->FUN_1422bc5d0();
    return 0;
}
MS2_REPLACE_METHOD(0x1422E3380, ASButtonBar, FUN_1422e3380, 114, 0x9038E735);

// @0x1422e3400
void ASButtonBar::FUN_1422e3400()
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422e2e00();
    if (spProvider.get())
        spProvider->FUN_1422df120();
}
MS2_REPLACE_METHOD(0x1422E3400, ASButtonBar, FUN_1422e3400, 83, 0x6E710504);

// @0x1422e3460
void ASButtonBar::FUN_1422e3460(const ASObj& item)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422e2e00();
    if (spProvider.get())
        spProvider->FUN_1422bbf00(item);
}
MS2_REPLACE_METHOD(0x1422E3460, ASButtonBar, FUN_1422e3460, 93, 0x213F3009);

// @0x1422e34d0
void ASButtonBar::FUN_1422e34d0(const CStringW& strLabel)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422e2e00();
    if (spProvider.get()) {
        ASObj item(2);
        item.FUN_1407cbb20("label", strLabel);
        spProvider->FUN_1422bbf00(item);
    }
}
MS2_REPLACE_METHOD(0x1422E34D0, ASButtonBar, FUN_1422e34d0, 185, 0xE6038828);

// @0x1422e3590
void ASButtonBar::FUN_1422e3590(const CStringW& strLabel)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422e2e00();
    if (spProvider.get()) {
        for (unsigned __int64 i = 0; i < FUN_1422e3380(); ++i) {
            AScript row = spProvider->FUN_1422df140((unsigned)i);
            if (FUN_1409b4d40(row.FUN_1422bb870())) {
                Scaleform::GFx::Value v = row.FUN_1422baa20("label");
                if (v.IsString()) {
                    if (strLabel == FUN_1408767c0(v.GetString())) {
                        FUN_1422e31e0((int)i);
                        return;
                    }
                }
                if (v.IsStringW()) {
                    if (strLabel == v.GetStringW()) {
                        FUN_1422e31e0((int)i);
                        return;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E3590, ASButtonBar, FUN_1422e3590, 505, 0x92EB0A6F);

// @0x1422e3790
CStringW ASButtonBar::FUN_1422e3790()
{
    return FUN_1422e37e0(FUN_1422e3210());
}
MS2_REPLACE_METHOD(0x1422E3790, ASButtonBar, FUN_1422e3790, 71, 0x2A51A5A6);

// @0x1422e37e0
CStringW ASButtonBar::FUN_1422e37e0(int nIndex)
{
    if (nIndex < 0)
        return L"";
    if (nIndex >= (int)FUN_1422e3380())
        return L"";
    MS2Ptr<ASDataProvider> spProvider = FUN_1422e2e00();
    if (spProvider.get()) {
        AScript row = spProvider->FUN_1422df140(nIndex);
        Scaleform::GFx::Value v = row.FUN_1422baa20("label");
        if (v.IsString())
            return FUN_1408767c0(v.GetString());
        if (v.IsStringW())
            return v.GetStringW();
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1422E37E0, ASButtonBar, FUN_1422e37e0, 529, 0x4CB6A1F5);

// @0x1422e3a00
void ASButtonBar::FUN_1422e3a00(int nIndex)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422e2e00();
    if (spProvider.get())
        spProvider->FUN_1422bc660(nIndex, 1);
}
MS2_REPLACE_METHOD(0x1422E3A00, ASButtonBar, FUN_1422e3a00, 97, 0xFB2142D9);

// @0x1422e3a70
void ASButtonBar::FUN_1422e3a70(const CStringW& strLabel)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422e2e00();
    if (spProvider.get()) {
        for (unsigned __int64 i = 0; i < FUN_1422e3380(); ++i) {
            AScript row = spProvider->FUN_1422df140((unsigned)i);
            if (FUN_1409b4d40(row.FUN_1422bb870())) {
                Scaleform::GFx::Value v = row.FUN_1422baa20("label");
                if (v.IsString()) {
                    if (strLabel == FUN_1408767c0(v.GetString())) {
                        FUN_1422e3a00((int)i);
                        return;
                    }
                }
                if (v.IsStringW()) {
                    if (strLabel == v.GetStringW()) {
                        FUN_1422e3a00((int)i);
                        return;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422E3A70, ASButtonBar, FUN_1422e3a70, 505, 0x203DC3CE);

// @0x1422e3c70
void ASButtonBar::FUN_1422e3c70(const CStringW& strOld, const CStringW& strNew)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422e2e00();
    if (spProvider.get()) {
        for (unsigned __int64 i = 0; i < FUN_1422e3380(); ++i) {
            AScript row = spProvider->FUN_1422df140((unsigned)i);
            if (FUN_1409b4d40(row.FUN_1422bb870())) {
                Scaleform::GFx::Value v = row.FUN_1422baa20("label");
                if (v.IsString()) {
                    if (strOld == FUN_1408767c0(v.GetString())) {
                        row.FUN_1407cbb20("label", strNew);
                        return;
                    }
                }
                if (v.IsStringW()) {
                    if (strOld == v.GetStringW()) {
                        row.FUN_1407cbb20("label", strNew);
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
    if (FUN_1422e3210() < 0)
        return 0;
    if (FUN_1422e3210() >= (int)FUN_1422e3380())
        return 0;
    MS2Ptr<ASDataProvider> spProvider = FUN_1422e2e00();
    if (spProvider.get()) {
        AScript row = spProvider->FUN_1422df140(FUN_1422e3210());
        vOut = row.FUN_1422baa20(strField);
        if (!vOut.IsNull())
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422E3EE0, ASButtonBar, FUN_1422e3ee0, 369, 0xBEFC5CC9);

// @0x1422e4060
void ASButtonBar::FUN_1422e4060(int nIndex)
{
    if (nIndex >= FUN_1422e3380())
        return;
    MS2Ptr<ASButton> spButton = FUN_1422e32b0(nIndex);
    if (spButton == 0 || spButton->FUN_1422ba9a0())
        return;
    FUN_1422e4350("updateRendererAt", spButton->FUN_1422bb870(), (unsigned)nIndex);
    spButton->vfunc_24(false);
}
MS2_REPLACE_METHOD(0x1422E4060, ASButtonBar, FUN_1422e4060, 293, 0x0444936C);

// @0x1422e4190
void ASButtonBar::FUN_1422e4190(const ASCallback& onChange, void* pUser)
{
    FUN_1422c3600("clikIndexChange", onChange, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422E4190, ASButtonBar, FUN_1422e4190, 113, 0xB9C8204A);

// @0x1422e4210
void ASButtonBar::FUN_1422e4210(const ASCallback& onChange)
{
    FUN_1422c3820("clikIndexChange", onChange, false);
}
MS2_REPLACE_METHOD(0x1422E4210, ASButtonBar, FUN_1422e4210, 82, 0x8837210A);

// @0x1422e4270
void ASButtonBar::FUN_1422e4270(const ASCallback& onMenu, void* pUser)
{
    FUN_1422c3600("listIndexChange", onMenu, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422E4270, ASButtonBar, FUN_1422e4270, 113, 0x24EA6C5E);

// @0x1422e42f0
void ASButtonBar::FUN_1422e42f0(const ASCallback& onMenu)
{
    FUN_1422c3820("listIndexChange", onMenu, false);
}
MS2_REPLACE_METHOD(0x1422E42F0, ASButtonBar, FUN_1422e42f0, 82, 0xFFCAAB47);

// @0x1422e4350
Scaleform::GFx::Value AScript::FUN_1422e4350(const char* szMethod, Scaleform::GFx::Value a1, unsigned a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// MS2-PIN: ??_GASButtonBar@@UEAAPEAXI@Z 0x1422e4450
