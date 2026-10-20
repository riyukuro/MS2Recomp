// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASCoreList, the wrapper of the CLIK CoreList component (the
// base of the list / tile list wrappers): selection, data provider, row count, label lookups and item listeners.
// MS2-UNIT: ?\ascorelist.cpp
// MS2-RANGE: 0x1422dcbe0-0x1422de590 .text$mn
// MS2-PIN: ??_GASCoreList@@UEAAPEAXI@Z 0x1422de550
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Unit
// boundaries: the previous obj's tail ends at 0x1422dcbe0; ASInteractiveObject's ctor starts the next obj (after this
// obj's memmove_s-less COMDAT tail) at 0x1422de680. The class is declared in src/ms2/placeholder/ascorelist.h. The tail
// holds the "dataProvider" binder AScript::FUN_1422de460<ASDataProvider>, MS2Ptr<ASDataProvider>::MS2Ptr(int) / get
// and the scalar deleting dtor.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "hook/ms2hook.h"

// new ASDataProvider(v, nMovieId) in an MS2Ptr (inline COMDAT, first emitted in uiwritemusicdialog.cpp).
MS2Ptr<ASDataProvider> FUN_140ff6b60(int nMovieId, Scaleform::GFx::Value& v);
// Text conversions (the CP_ACP helpers of the string utilities; the int is the code page / flags, 0 here).
CStringW FUN_1408767c0(const char* sz);                                 // CStringW from a narrow string
CStringW FUN_14016a730(const char* sz, int n);                          // narrow -> wide
CString FUN_14016a600(const wchar_t* sz, int n);                        // wide -> narrow
CString FUN_1409a23d0(const char* sz, int n);                           // CString from a narrow string

// @0x1422dcbe0
ASCoreList::ASCoreList(int nMovieId)
    : ASUIComponent(nMovieId)
{
}

// @0x1422dcc20
ASCoreList::ASCoreList(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1422dcc70
ASCoreList::~ASCoreList()
{
}

// @0x1422dcca0
void ASCoreList::FUN_1422dcca0(int nIndex)
{
    FUN_1407cb9c0("selectedIndex", nIndex);
}
MS2_REPLACE_METHOD(0x1422DCCA0, ASCoreList, FUN_1422dcca0, 40, 0xA4D98BED);

// @0x1422dccd0
int ASCoreList::FUN_1422dccd0()
{
    return FUN_1422baa20("selectedIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422DCCD0, ASCoreList, FUN_1422dccd0, 88, 0x868A3740);

// @0x1422dcd30
void ASCoreList::vfunc_25(const Scaleform::GFx::Value& data)
{
    FUN_1409adbe0("dataProvider", data);
}
MS2_REPLACE_METHOD(0x1422DCD30, ASCoreList, vfunc_25, 71, 0x8F03E154);

// @0x1422dcd80
MS2Ptr<ASDataProvider> ASCoreList::FUN_1422dcd80()
{
    return FUN_1422de460<ASDataProvider>("dataProvider");
}
MS2_REPLACE_METHOD(0x1422DCD80, ASCoreList, FUN_1422dcd80, 102, 0x78BAC401);

// @0x1422dcdf0
void ASCoreList::FUN_1422dcdf0(Scaleform::GFx::Value list)
{
    FUN_1409adbe0("itemRendererList", list);
}

// @0x1422dce60
void ASCoreList::FUN_1422dce60(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser)
{
    FUN_1422c3600("listIndexChange", cb, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DCE60, ASCoreList, FUN_1422dce60, 113, 0x57168289);

// @0x1422dcee0
void ASCoreList::FUN_1422dcee0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    FUN_1422c3820("listIndexChange", cb, false);
}
MS2_REPLACE_METHOD(0x1422DCEE0, ASCoreList, FUN_1422dcee0, 82, 0x0DA72E52);

// @0x1422dcf40
void ASCoreList::FUN_1422dcf40(int nCount)
{
    ASDataProvider provider(2);
    for (unsigned i = 0; i < (unsigned)nCount; i++)
        provider.FUN_1422bc050(Scaleform::GFx::Value());
    vfunc_25(provider.FUN_1422bb890());
}
MS2_REPLACE_METHOD(0x1422DCF40, ASCoreList, FUN_1422dcf40, 186, 0xEC17C3DB);

// @0x1422dd000
void ASCoreList::FUN_1422dd000(unsigned nRows)
{
    FUN_1409c0d20("rowCount", nRows);
}
MS2_REPLACE_METHOD(0x1422DD000, ASCoreList, FUN_1422dd000, 40, 0x53A95978);

// @0x1422dd030
unsigned ASCoreList::FUN_1422dd030()
{
    return FUN_1422baa20("rowCount").GetUInt();
}
MS2_REPLACE_METHOD(0x1422DD030, ASCoreList, FUN_1422dd030, 88, 0xFDCD74D5);

// @0x1422dd090
void ASCoreList::vfunc_23()
{
    Invoke("invalidateSelectedIndex");
}
MS2_REPLACE_METHOD(0x1422DD090, ASCoreList, vfunc_23, 46, 0xC115623E);

// @0x1422dd0d0
void ASCoreList::FUN_1422dd0d0(int nIndex)
{
    Invoke("scrollToIndex", nIndex);
}
MS2_REPLACE_METHOD(0x1422DD0D0, ASCoreList, FUN_1422dd0d0, 55, 0x4A289BC8);

// @0x1422dd110
void ASCoreList::FUN_1422dd110()
{
    Invoke("scrollToSelected");
}
MS2_REPLACE_METHOD(0x1422DD110, ASCoreList, FUN_1422dd110, 46, 0x219EFD1F);

// @0x1422dd150
unsigned ASCoreList::FUN_1422dd150()
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0)
        return spProvider->FUN_1422bc5d0();
    return 0;
}
MS2_REPLACE_METHOD(0x1422DD150, ASCoreList, FUN_1422dd150, 114, 0xB2513273);

// @0x1422dd1d0
void ASCoreList::FUN_1422dd1d0()
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0)
        spProvider->FUN_1422df120();
}
MS2_REPLACE_METHOD(0x1422DD1D0, ASCoreList, FUN_1422dd1d0, 83, 0xC4AB9264);

// @0x1422dd230
void ASCoreList::FUN_1422dd230(const ASObj& item)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0)
        spProvider->FUN_1422bbf00(item);
}
MS2_REPLACE_METHOD(0x1422DD230, ASCoreList, FUN_1422dd230, 93, 0x32872065);

// @0x1422dd2a0
void ASCoreList::FUN_1422dd2a0(const CString& strLabel)
{
    FUN_1422dd310(FUN_14016a730(strLabel, 0));
}
MS2_REPLACE_METHOD(0x1422DD2A0, ASCoreList, FUN_1422dd2a0, 97, 0x1403C126);

// @0x1422dd310
void ASCoreList::FUN_1422dd310(const CStringW& strLabel)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0) {
        AScript item(2);
        item.FUN_1407cbb20("label", strLabel);
        spProvider->FUN_1422bbf00(item);
    }
}
MS2_REPLACE_METHOD(0x1422DD310, ASCoreList, FUN_1422dd310, 185, 0x2E2BB395);

// @0x1422dd3d0
void ASCoreList::FUN_1422dd3d0(const CString& strLabel)
{
    FUN_1422dd440(FUN_14016a730(strLabel, 0));
}
MS2_REPLACE_METHOD(0x1422DD3D0, ASCoreList, FUN_1422dd3d0, 97, 0xFB42E999);

// @0x1422dd440
void ASCoreList::FUN_1422dd440(const CStringW& strLabel)
{
    FUN_1422ddb40("label", strLabel);
}
MS2_REPLACE_METHOD(0x1422DD440, ASCoreList, FUN_1422dd440, 79, 0x7B589F68);

// @0x1422dd4a0
CString ASCoreList::FUN_1422dd4a0()
{
    return FUN_14016a600(FUN_1422dd520(), 0);
}
MS2_REPLACE_METHOD(0x1422DD4A0, ASCoreList, FUN_1422dd4a0, 120, 0xCECA77F3);

// @0x1422dd520
CStringW ASCoreList::FUN_1422dd520()
{
    if (FUN_1422dccd0() < 0)
        return L"";
    if (FUN_1422dccd0() >= (int)FUN_1422dd150())
        return L"";
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0) {
        AScript item = spProvider->FUN_1422df140(FUN_1422dccd0());
        Scaleform::GFx::Value label = item.FUN_1422baa20("label");
        if (label.IsString())
            return FUN_1408767c0(label.GetString());
        if (label.IsStringW())
            return label.GetStringW();
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1422DD520, ASCoreList, FUN_1422dd520, 563, 0x2F910C4C);

// @0x1422dd760
bool ASCoreList::FUN_1422dd760(AScript& item)
{
    if (FUN_1422dccd0() < 0)
        return false;
    if (FUN_1422dccd0() >= (int)FUN_1422dd150())
        return false;
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0) {
        item = spProvider->FUN_1422df140(FUN_1422dccd0());
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422DD760, ASCoreList, FUN_1422dd760, 270, 0x7C7A42D0);

// @0x1422dd880
void ASCoreList::FUN_1422dd880(const CString& strMember, int nValue)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0) {
        for (unsigned __int64 i = 0; i < FUN_1422dd150(); i++) {
            AScript item = spProvider->FUN_1422df140((unsigned)i);
            if (item.FUN_1422bb870().IsObject()) {
                Scaleform::GFx::Value v = item.FUN_1422baa20(strMember);
                if (v.IsString() && nValue == (int)v.GetInt()) {
                    FUN_1422dcca0((int)i);
                    return;
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422DD880, ASCoreList, FUN_1422dd880, 342, 0x49ECAC2A);

// @0x1422dd9e0
void ASCoreList::FUN_1422dd9e0(const CString& strMember, int nValue)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0) {
        for (unsigned __int64 i = 0; i < FUN_1422dd150(); i++) {
            AScript item = spProvider->FUN_1422df140((unsigned)i);
            if (item.FUN_1422bb870().IsObject()) {
                Scaleform::GFx::Value v = item.FUN_1422baa20(strMember);
                if (v.IsString() && nValue == (int)v.GetUInt()) {
                    FUN_1422dcca0((int)i);
                    return;
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422DD9E0, ASCoreList, FUN_1422dd9e0, 342, 0x477F9403);

// @0x1422ddb40
void ASCoreList::FUN_1422ddb40(const CString& strMember, const CStringW& strValue)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0) {
        for (unsigned __int64 i = 0; i < FUN_1422dd150(); i++) {
            AScript item = spProvider->FUN_1422df140((unsigned)i);
            if (item.FUN_1422bb870().IsObject()) {
                Scaleform::GFx::Value v = item.FUN_1422baa20(strMember);
                if (v.IsString()) {
                    if (strValue == FUN_1408767c0(v.GetString())) {
                        FUN_1422dcca0((int)i);
                        return;
                    }
                }
                if (v.IsStringW()) {
                    if (strValue == v.GetStringW()) {
                        FUN_1422dcca0((int)i);
                        return;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422DDB40, ASCoreList, FUN_1422ddb40, 520, 0x13C98F26);

// @0x1422ddd50
void ASCoreList::FUN_1422ddd50(int nIndex)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0)
        spProvider->FUN_1422bc660(nIndex, 1);
}
MS2_REPLACE_METHOD(0x1422DDD50, ASCoreList, FUN_1422ddd50, 97, 0x39902CE9);

// @0x1422dddc0
void ASCoreList::FUN_1422dddc0(const CString& strLabel)
{
    MS2Ptr<ASDataProvider> spProvider = FUN_1422dcd80();
    if (spProvider.get() != 0) {
        for (unsigned __int64 i = 0; i < FUN_1422dd150(); i++) {
            AScript item = spProvider->FUN_1422df140((unsigned)i);
            if (item.FUN_1422bb870().IsObject()) {
                Scaleform::GFx::Value v = item.FUN_1422baa20("label");
                if (v.IsString()) {
                    if (strLabel == FUN_1409a23d0(v.GetString(), 0)) {
                        FUN_1422ddd50((int)i);
                        return;
                    }
                }
                if (v.IsStringW()) {
                    if (strLabel == FUN_14016a600(v.GetStringW(), 0)) {
                        FUN_1422ddd50((int)i);
                        return;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1422DDDC0, ASCoreList, FUN_1422dddc0, 555, 0xE915060C);

// @0x1422de000
void ASCoreList::FUN_1422de000(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser)
{
    FUN_1422c3600("itemPress", cb, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DE000, ASCoreList, FUN_1422de000, 113, 0x675E77BD);

// @0x1422de080
void ASCoreList::FUN_1422de080(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    FUN_1422c3820("itemPress", cb, false);
}
MS2_REPLACE_METHOD(0x1422DE080, ASCoreList, FUN_1422de080, 82, 0xAACC32D8);

// @0x1422de0e0
void ASCoreList::FUN_1422de0e0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser)
{
    FUN_1422c3600("itemClick", cb, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DE0E0, ASCoreList, FUN_1422de0e0, 113, 0x37ABE2EC);

// @0x1422de160
void ASCoreList::FUN_1422de160(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    FUN_1422c3820("itemClick", cb, false);
}
MS2_REPLACE_METHOD(0x1422DE160, ASCoreList, FUN_1422de160, 82, 0xA41ABAA3);

// @0x1422de1c0
void ASCoreList::FUN_1422de1c0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser)
{
    FUN_1422c3600("itemRollOver", cb, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DE1C0, ASCoreList, FUN_1422de1c0, 113, 0xC1476786);

// @0x1422de240
void ASCoreList::FUN_1422de240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    FUN_1422c3820("itemRollOver", cb, false);
}
MS2_REPLACE_METHOD(0x1422DE240, ASCoreList, FUN_1422de240, 82, 0xF83CB564);

// @0x1422de2a0
void ASCoreList::FUN_1422de2a0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser)
{
    FUN_1422c3600("itemRollOut", cb, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DE2A0, ASCoreList, FUN_1422de2a0, 113, 0x51B02349);

// @0x1422de320
void ASCoreList::FUN_1422de320(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    FUN_1422c3820("itemRollOut", cb, false);
}
MS2_REPLACE_METHOD(0x1422DE320, ASCoreList, FUN_1422de320, 82, 0x2A8A2D84);

// @0x1422de380
void ASCoreList::FUN_1422de380(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser)
{
    FUN_1422c3600("itemDoubleClick", cb, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DE380, ASCoreList, FUN_1422de380, 113, 0x8F06040A);

// @0x1422de400
void ASCoreList::FUN_1422de400(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    FUN_1422c3820("itemDoubleClick", cb, false);
}
MS2_REPLACE_METHOD(0x1422DE400, ASCoreList, FUN_1422de400, 82, 0xB39E0A2C);

// @0x1422de460
template <class T> MS2Ptr<T> AScript::FUN_1422de460(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return FUN_140ff6b60(m_nMovieId, v);
    return MS2Ptr<T>(0);
}
