// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIRandomCoupon: see uirandomcoupon.h.
// MS2-UNIT: unit_140bfe4b0
// MS2-RANGE: 0x140bfe4b0-0x140bff060 .text$mn
// MS2-RANGE: 0x1400cb830-0x1400cba40 .text$di
// MS2-PIN: ??_GUIRandomCoupon@@UEAAPEAXI@Z 0x140bfeef0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uirandomcoupon.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uirandomcoupon.h"

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- header statics (.text$di): the market sort names, the key controller and the dialog's keys ----
// @0x1400cb830
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400cb8f0
static UICommon::CMyPCKeyInputController s_keyInputController;
// @0x1400cb920
static CString s_jobCode = "jobCode";
// @0x1400cb950
static CString s_sortValue = "sortValue";
// @0x1400cb980
static CString s_tabIndex = "tabIndex";
// @0x1400cb9b0
static CString s_strCoupon1 = "System_Random_Coupon_01";
// @0x1400cb9e0
static CString s_strCoupon2 = "System_Random_Coupon_02";
// @0x1400cba10
static CString s_strCoupon3 = "System_Random_Coupon_03";

// ---- unit-local placeholders (unrecovered helpers; promote to src/ms2/placeholder/ when shared) ----

class Unk_RcProduct : public CPtred { public: char m_pad_18[0x10]; };

// The Merat market dialog (ui id 0x4ec1): takes the picked product.
class UIMeratMarketDialog : public UIObject
{
public:
    char m_pad_68[0x10];
};
void FUN_14130ea00(UIMeratMarketDialog* pDlg, MS2Ptr<Unk_RcProduct> spProduct);
UIMeratMarketDialog* FUN_140bfed50(int nId);                        // find the dialog (dynamic_cast)

// The UI manager: the lookup of a dialog by its ui id.
class Unk_RcUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nUiId); };
Unk_RcUIManager* FUN_1403ed2b0();

// The input keys.
class Unk_RcKeys
{
public:
    bool FUN_14116d840();
    bool FUN_14116d9c0(int nKey, int a, int b);
};
Unk_RcKeys* FUN_14025e7c0();

bool FUN_140a467d0(const MS2Ptr<AScript>* p);                       // has the AS object been released
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);     // Value = n (UInt)
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
int FUN_141276180(const CString& str, const CString& strArg);       // play a sound
void FUN_141901470(int n, int nUiId);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// MS2-FUNCTIONAL: ASArgList setup codegen differs; same behavior
// @0x140bfedf0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, unsigned int a1, unsigned int a2, CStringW a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3.GetString());
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140bfe4b0
UIRandomCoupon::UIRandomCoupon()
{
    m_2c = 0x23;
    m_nMode = 0;
    m_nA = 0;
    m_nCoupon = 1;
    m_strName.Empty();
    m_spProduct = 0;
    m_bButtonShown = 0;
}

// @0x140bfe590
UIRandomCoupon::~UIRandomCoupon()
{
}

// @0x140bfe600
CString UIRandomCoupon::vfunc_1()
{
    return "RandomCoupon";
}

// @0x140bfe650
void UIRandomCoupon::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    if (m_nMode == 1)
        m_30->Invoke("setPaybackPick", (unsigned int)m_nA, (unsigned int)m_nCoupon, m_strName);
    else
        m_30->Invoke("setSalePick", (unsigned int)m_nA, (unsigned int)m_nCoupon, m_strName);
}

// @0x140bfe7c0
void UIRandomCoupon::vfunc_26()
{
    UIObject::vfunc_26();
}

// MS2-FUNCTIONAL: branch layout of the nested method-name chain differs; same behavior
// @0x140bfe7e0
int UIRandomCoupon::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onVibrate") == 0)
        return 1;
    if (_stricmp(szMethod, "onEffectPick") == 0)
        return 1;
    if (_stricmp(szMethod, "onButtonShow") == 0)
    {
        m_bButtonShown = 1;
        if (m_spProduct.get())
        {
            UIMeratMarketDialog* pDlg = FUN_140bfed50(0x4ec1);
            if (pDlg)
                FUN_14130ea00(pDlg, m_spProduct);
        }
        return 1;
    }
    if (_stricmp(szMethod, "onHide") == 0)
    {
        vfunc_3();
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: branch layout of the key/close checks differs; same behavior
// @0x140bfe930
int UIRandomCoupon::vfunc_13()
{
    if (FUN_140a467d0(&m_30))
        return 0;
    if (!FUN_14025e7c0()->FUN_14116d840())
    {
        if (!FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
            return 0;
    }
    if (m_bButtonShown)
        m_30->Invoke("playClose");
    return 1;
}

// @0x140bfe9e0
void UIRandomCoupon::vfunc_43()
{
    if (m_30.get())
        m_30->Invoke("alignment");
}

// @0x140bfea40
void UIRandomCoupon::vfunc_2()
{
    UIHeadUpDisplay::vfunc_2();
    FUN_140bfec40();
    FUN_141901470(0, 0x4f99);
    FUN_140b632f0()->FUN_1422d4780(this, 4);
}

// @0x140bfea90
void UIRandomCoupon::vfunc_3()
{
    UIHeadUpDisplay::vfunc_3();
    FUN_140bfeae0();
    FUN_141901470(1, 0x4f99);
    FUN_140b632f0()->FUN_1422d4840(this, 4);
}

// @0x140bfeae0
void UIRandomCoupon::FUN_140bfeae0()
{
    m_nMode = 0;
    m_nA = 0;
    m_nCoupon = 1;
    m_strName.Empty();
    m_spProduct = 0;
    m_bButtonShown = 0;
}

// @0x140bfeb50
void UIRandomCoupon::FUN_140bfeb50(int nMode, int nA, int nB, CStringW strName)
{
    if (nMode == 0)
        return;
    m_nMode = nMode;
    m_nA = nA;
    m_nCoupon = nB;
    m_strName = strName;
    vfunc_2();
}

// @0x140bfebf0
void UIRandomCoupon::FUN_140bfebf0(MS2Ptr<Unk_RcProduct> spProduct)
{
    m_spProduct = spProduct;
}

// MS2-FUNCTIONAL: branch layout / temporaries of the coupon-kind chain differ; same behavior
#ifndef MS2_HOOK_DLL
// @0x140bfec40
void UIRandomCoupon::FUN_140bfec40()
{
    if (m_nCoupon == 1)
        FUN_141276180(s_strCoupon1, "");
    else if (m_nCoupon == 2)
        FUN_141276180(s_strCoupon2, "");
    else if (m_nCoupon == 3)
        FUN_141276180(s_strCoupon3, "");
    else
        FUN_141276180(s_strCoupon1, "");
}
#endif

// MS2-FUNCTIONAL: dynamic_cast / ref release codegen differs; same behavior
// @0x140bfed50
UIMeratMarketDialog* FUN_140bfed50(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> ref = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (ref.get())
            return dynamic_cast<UIMeratMarketDialog*>(ref.get());
    }
    return 0;
}

// @0x140bfef40
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
