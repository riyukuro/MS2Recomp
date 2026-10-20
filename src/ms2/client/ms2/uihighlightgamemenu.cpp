// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHighlightGameMenu: see uihighlightgamemenu.h.
// MS2-UNIT: ?\uihighlightgamemenu.cpp
// MS2-RANGE: 0x140c220d0-0x140c26440 .text$mn
// MS2-RANGE: 0x1400cc590-0x1400cc7a0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIHighlightGameMenu@@UEAAHXZ 0x140c25180 ; unique
// MS2-PIN: ?vfunc_3@UIItemEventListener@@UEAAXPEAX_N@Z 0x140c255d0 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihighlightgamemenu.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uihighlightgamemenu.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/placeholder/header_statics_a.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The key-input controller singleton of this unit.
static UICommon::CMyPCKeyInputController s_keyInputController;

// Two zero-initialised handles (static initialised by FUN_1401cd100(&DAT, 0)).
struct Unk_RegMarker {};
void FUN_1401cd100(void* h, int a);
static void* s_dat_143abe528;
static Unk_RegMarker s_init_143abe528 = (FUN_1401cd100(&s_dat_143abe528, 0), Unk_RegMarker());
static void* s_dat_143abe530;
static Unk_RegMarker s_init_143abe530 = (FUN_1401cd100(&s_dat_143abe530, 0), Unk_RegMarker());

static CString s_strSortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};

// ---- unit-local views of unrecovered callees -------------------------------------------------------------------------

typedef void* P;

// A 16-byte handle (item / record reference; ctor, dtor and accessors live outside this unit).
struct Unk_HlH
{
    void* m_unk_00;
    void* m_p;
};

class ASDialog : public ASDisplayObject {};

// The item / record tables (DAT_143ab2a90) and their callees.
class Unk_HlDb
{
public:
    Unk_HlH FUN_140a5e2e0(int nId);                         // item by id
    Unk_HlH FUN_140a5d680(__int64 nId);                     // item by instance id
    void FUN_140a60880(int nBag, ATL::CAtlArray<void*>& out);   // the items of a bag
    int FUN_140a65770(P pId);
};
extern Unk_HlDb DAT_143ab2a90;
extern char DAT_143ab2ee0[];
extern P DAT_143abd628;

class Unk_HlAS : public AScript
{
public:
    Scaleform::GFx::Value FUN_140bd2cb0(const char* szMethod, ASArray& arr);   // Invoke(name, array)
};
Unk_HlAS* FUN_1409ee290(MS2Ptr<AScript>* p);
bool FUN_140a467d0(const MS2Ptr<AScript>*);                 // has the AS object been released
void FUN_140614800(Scaleform::GFx::Value* v);               // ~Value
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);
CStringW FUN_1402a5170(const wchar_t* szFormat, const CString& a1);    // "{0}" formatter
CStringW FUN_14028b8e0(const CStringW& str);

class Unk_HlNotices
{
public:
    void FUN_140da4e40(CStringW name, Delegate<void(NotifyObject*)> cb);
    void FUN_140da4eb0(CStringW name, Delegate<void(NotifyObject*)> cb);
};
Unk_HlNotices* FUN_140939a10();

class Unk_HlOpt { public: bool FUN_14036e560(); };
Unk_HlOpt* FUN_140166410();

class Unk_HlItemSys { public: void FUN_1419cae20(void* pListener); void FUN_1419caeb0(void* pListener); };
Unk_HlItemSys* FUN_140a6a840();

P FUN_1403ed2d0();
// The local player: slot 78 returns the level.
class Unk_HlPc
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
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual unsigned short vfunc_78();
};
P FUN_141bd0cc0(P pWorld);
int FUN_1418dd0d0();

// The menu table (see uigamepadmenudialog.cpp) and the inventory / socket dialogs.
class Unk_HlMenu
{
public:
    char m_pad_00[0x30];
    char m_tail[8];                                         // +0x30
    char m_pad_38[0x30];
    int m_nUiId;                                            // +0x68
};
struct Unk_HlMenuRef { void* m_unk_00; Unk_HlMenu* m_p; };
P FUN_140c1d2f0();
void FUN_140cf7470(P pDb, Unk_HlMenuRef* pOut, CString strName);
P FUN_140c1cd90(Unk_HlMenuRef* p);
Unk_HlMenu* FUN_140c1cda0(Unk_HlMenuRef* p);
void FUN_140c1ccf0(Unk_HlMenuRef* p);
char FUN_14098d930(void* pTail);
void FUN_14098d150(void* pTail);
P FUN_1403ed2b0();
int FUN_141adc940(P pUi, int nId);
void FUN_141adc750(P pUi, int nId);
UIDialog* FUN_1405344f0(int nId);
void FUN_141999d40(UIDialog* p, int n);
void FUN_140d1bd60(Unk_HlH item, int n);
void FUN_141adcea0(P pUi, Unk_HlH* pOut, int nId);
char FUN_140534e80(Unk_HlH* p);
P FUN_1403ed9e0(Unk_HlH* p);
void FUN_1403e5630(Unk_HlH* p);
void FUN_140f69c10(P pDlg, int* pArg);
P FUN_140c24650();
int FUN_140c25190();

char FUN_140ba28d0(void* p, int n);
P FUN_140ba7c60(MS2Ptr<AScript>* p);

// item handles / records
void FUN_140203510(Unk_HlH* p, int n);
P FUN_1402034d0(Unk_HlH* dst, P src);
void FUN_1401bfde0(Unk_HlH* p);
char FUN_1401c0050(Unk_HlH* p, int n);
P FUN_1401c0180(Unk_HlH* p);
P FUN_14052cd70(Unk_HlH* p);
void FUN_140692c90(Unk_HlH* dst, Unk_HlH* src);
void FUN_1401bf970(void* pRec, P pItemInfo);
void FUN_1401b50d0(void* pRec);
char FUN_1402ffd90(void* pRec);
P FUN_1401b52a0(void* pRec);
P FUN_140527840(P p);
P FUN_1405279c0(P p);
char FUN_14053d840(P p);
char FUN_140621340(P p);

// the player
P FUN_141654730(P);
int FUN_140644b80(P, int);
P FUN_1401d7a50();
int FUN_14152e970(P, int);
P FUN_1401c0db0();
unsigned FUN_14067a8d0(P, unsigned);
P FUN_1416546d0(P);
unsigned FUN_140639b40(P, int);
P FUN_1401d3200();
unsigned* FUN_1401d7c10(void* p);
P FUN_1409a8b10();
P FUN_140b123b0(P);
void FUN_140bc1730(P);
int FUN_140caa1a0(P);

// lists, arrays, item records
void FUN_1408850d0(void*);
void FUN_1405a85f0(void*);
P FUN_1416561a0(P);
void FUN_1411e1ce0(P, void*, int);
void FUN_1411dc7a0(P, Unk_HlH*);
P FUN_140a69ee0(void*, unsigned __int64);
unsigned __int64 FUN_140720ca0(void*);
P FUN_1405a8ed0(void*);
void FUN_14034ed30(void*);
void FUN_1401855a0(void*, int);
P FUN_1408e5180(void*);
void FUN_1408e4ea0(void*);
void FUN_140885680(void*, P*);
P FUN_140885670(void*);
P FUN_140885600(void*, P);
void FUN_140884f30(void*, P);
void FUN_140884ed0(void*, int);
void FUN_1405b2540(void*);
char FUN_140534e50(Unk_HlH*);
int FUN_140529070(P);
__int64 FUN_140526a50(P);
P FUN_14034ef20(void*);
int FUN_141654700(P);
void FUN_14152e2f0(P, Unk_HlH*, Unk_HlH);
P FUN_1409eece0();
char FUN_1409edd90(void*, int);
unsigned __int64 FUN_1408e57c0(P);
void FUN_1408e4be0(void*, P);
int FUN_1408e48b0(void*);
P FUN_1408e3700(void*);
int FUN_1408e3520(void*);
int FUN_1408d1f60(void*, int, int);
void FUN_14086a880(void*, int);
P FUN_140869440();
void FUN_140720b80(void*, Unk_HlH*);
void FUN_1406c47a0(void*, P);
int FUN_140691130(P);
int FUN_140690370(P);
P FUN_14062c280();
P FUN_1405b2650(void*);
char FUN_1405b2610(void*, void*);                         // MS2Ptr == (null ptr argument)
void FUN_1405b1a60(P, void*, int);
int FUN_14058df90(P, P);
char FUN_140545da0(void*, int);
int FUN_14053c620(P);
__int64 FUN_140528ae0(P);
unsigned FUN_140527710(P);
int FUN_1405276c0(P);
int FUN_140527030(P);
int FUN_140526fc0(P);
int FUN_140526bd0(P);
int FUN_1405258b0(P);
int FUN_140408410(void*, int*);
P FUN_14034f780();
char FUN_14034eee0(void*, const wchar_t*);
char FUN_14034eeb0(void*);
void FUN_14034e360(P, void*, int);
__int64 FUN_140282020(void*);
unsigned __int64 FUN_140186270(void*);
int* FUN_140184510(void*, unsigned __int64);

// reference-counted record at player+0x1120 (copy, release)
struct Unk_HlRef { void* m_unk_00; P m_p; };
P FUN_14015b020(P p);
int FUN_140159bc0(P p);
void FUN_140159ba0(P p);
void FUN_140159b70(unsigned nHr);

// ---- tiny in-unit helpers ---------------------------------------------------------------------------------------------

// @0x140c24ef0
P FUN_140c24ef0()
{
    return DAT_143abd628;
}

// @0x140c25190
int FUN_140c25190()
{
    return 0x4f0a;
}

// @0x140c25e30
void FUN_140c25e30(P p)
{
    FUN_14015b020(p);
}

// @0x140c25e50
void FUN_140c25e50(Unk_HlRef* p)
{
    FUN_140c25e30(p->m_p);
}

// @0x140c25e00
void FUN_140c25e00(Unk_HlRef* p)
{
    if (p->m_p != 0)
        FUN_140c25e50(p);
}

// @0x140c25ec0
void FUN_140c25ec0(Unk_HlRef* p)
{
    if (FUN_140159bc0(p->m_p) == 0)
    {
        FUN_140c25e30(p->m_p);
        FUN_140159ba0(p->m_p);
    }
}

// @0x140c25e80
void FUN_140c25e80(Unk_HlRef* p)
{
    if (p->m_p != 0)
    {
        FUN_140c25ec0(p);
        p->m_p = 0;
    }
}

// @0x140c24a50
void FUN_140c24a50(Unk_HlRef* p)
{
    FUN_140c25e80(p);
}

// @0x140c24af0
P FUN_140c24af0(Unk_HlRef* p)
{
    return p->m_p;
}

// @0x140c24920
Unk_HlRef* FUN_140c24920(Unk_HlRef* pDst, Unk_HlRef* pSrc)
{
    pDst->m_p = pSrc->m_p;
    FUN_140c25e00(pDst);
    return pDst;
}

// @0x140c25130
Unk_HlRef* FUN_140c25130(P pPlayer, Unk_HlRef* pOut)
{
    FUN_140c24920(pOut, (Unk_HlRef*)((char*)pPlayer + 0x1120));
    return pOut;
}

// @0x140c25330
bool FUN_140c25330(void* p)
{
    return *(__int64*)((char*)p + 0x10) == 0;
}

// @0x140c24ea0
P FUN_140c24ea0(__int64* pArr, unsigned __int64 n)
{
    if ((unsigned __int64)pArr[1] <= n)
        FUN_140159b70(0x80070057);
    return (P)(n * 0x10 + *pArr);
}

// ---- the bit set ------------------------------------------------------------------------------------------------------

extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);
#define HL_BITSET_ASSERT(line) _wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl", line)

// @0x140c249d0
void Unk_HlBitRef::FUN_140c249d0(Unk_HlBits* pBits, int nPos)
{
    m_pBits = pBits;
    m_nPos = nPos;
}

// @0x140c24ac0
bool Unk_HlBitRef::FUN_140c24ac0()
{
    return m_pBits->FUN_140c261e0(m_nPos);
}

// @0x140c25f10
Unk_HlBitRef Unk_HlBits::FUN_140c25f10(int nPos)
{
    Unk_HlBitRef ref;
    ref.FUN_140c249d0(this, nPos);
    return ref;
}

// @0x140c260a0
Unk_HlBits& Unk_HlBits::FUN_140c260a0(int nPos, bool bSet)
{
    if (nPos != 0)
        HL_BITSET_ASSERT(0xf3);
    if (!bSet)
        (&m_b)[nPos / 8] &= ~(unsigned char)(1 << (nPos % 8));
    else
        (&m_b)[nPos / 8] |= (unsigned char)(1 << (nPos % 8));
    return *this;
}

// @0x140c261e0
bool Unk_HlBits::FUN_140c261e0(int nPos) const
{
    if (nPos == 0)
        return (m_b & 1) != 0;
    HL_BITSET_ASSERT(0x194);
    return false;
}

// @0x140c262e0
void Unk_HlBits::FUN_140c262e0()
{
}

// @0x140c26280
void Unk_HlBits::FUN_140c26280(char nFill)
{
    for (int i = 0; -1 < i; --i)
        (&m_b)[i] = nFill;
    if (nFill != 0)
        FUN_140c262e0();
}

// @0x140c24770
void Unk_HlBits::FUN_140c24770()
{
    FUN_140c26280(0);
}

// @0x140c261c0
void Unk_HlBits::FUN_140c261c0()
{
    FUN_140c26280((char)0xff);
}

// @0x140c26080
void Unk_HlBits::FUN_140c26080()
{
    FUN_140c26280(0);
}

// ---- the dialog -------------------------------------------------------------------------------------------------------

// @0x140c220d0
UIHighlightGameMenu::UIHighlightGameMenu()
    : m_actions(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_timer.FUN_140517b00();
    m_nScrollItem = 0;
    m_nTargetItem = 0;
    m_nCount = 0;
    m_nMargin = 0;
    m_bActive = false;
    m_bitsGem.FUN_140c24770();
    m_bitsSocket.FUN_140c24770();
    m_2c = 0xe;
    FUN_141925e70(0, 1);
    m_actions.SetAt("characterinfo", &UIHighlightGameMenu::FUN_140c236f0);
    m_actions.SetAt("skillbook", &UIHighlightGameMenu::FUN_140c234d0);
    m_actions.SetAt("inven", &UIHighlightGameMenu::FUN_140c231b0);
    m_actions.SetAt("class", &UIHighlightGameMenu::FUN_140c235d0);
    if (FUN_140166410()->FUN_14036e560())
        m_actions.SetAt("enchantscroll", &UIHighlightGameMenu::FUN_140c237a0);
    m_actions.SetAt("gemstone", &UIHighlightGameMenu::FUN_140c23f10);
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyGameStart"),
        Delegate<void(NotifyObject*)>(this, &UIHighlightGameMenu::FUN_140c24470));
}

// @0x140c22550
UIHighlightGameMenu::~UIHighlightGameMenu()
{
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyGameStart"),
        Delegate<void(NotifyObject*)>(this, &UIHighlightGameMenu::FUN_140c24470));
}

// @0x140c22690
CString UIHighlightGameMenu::vfunc_1()
{
    return "HighlightGameMenu";
}

// @0x140c226e0
void UIHighlightGameMenu::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140c22700
void UIHighlightGameMenu::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    FUN_140c22f50();
}

// @0x140c22760
void UIHighlightGameMenu::vfunc_43()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->vfunc_2(2, 8, m_nMargin - (FUN_1418dd0d0() + 0x24));
}

// @0x140c22800
int UIHighlightGameMenu::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "enchantscroll") == 0)
    {
        Unk_HlH item = DAT_143ab2a90.FUN_140a5d680(m_nScrollItem);
        if (FUN_14052cd70(&item) != 0)
        {
            FUN_140d1bd60(item, 0);
            UIDialog* pInv = FUN_1405344f0(0x4e2d);
            if (pInv != 0)
            {
                FUN_141999d40(pInv, 0);
                if (pInv->FUN_141924630() == 0)
                    pInv->FUN_141924680();
            }
        }
        FUN_1401bfde0(&item);
        return 1;
    }
    if (_stricmp(szMethod, "gemstone") == 0)
    {
        P pDlg = FUN_140c24650();
        if (pDlg != 0)
        {
            int nArg = 1;
            FUN_140f69c10(pDlg, &nArg);
        }
        return 1;
    }
    Unk_HlMenuRef spMenu;
    FUN_140cf7470(FUN_140c1d2f0(), &spMenu, CString(szMethod));
    if (FUN_140c1cd90(&spMenu) == 0)
    {
        FUN_140c1ccf0(&spMenu);
        return 0;
    }
    if (FUN_140c1cda0(&spMenu)->m_nUiId == 0x4e2d)
    {
        if (FUN_141adc940(FUN_1403ed2b0(), 0x4e2d) != 0)
        {
            UIDialog* pInv = FUN_1405344f0(0x4e2d);
            if (pInv != 0)
                FUN_141999d40(pInv, 0);
        }
    }
    if (FUN_14098d930(FUN_140c1cda0(&spMenu)->m_tail) == 0)
        FUN_14098d150(FUN_140c1cda0(&spMenu)->m_tail);
    else if (FUN_140c1cda0(&spMenu)->m_nUiId != 0)
        FUN_141adc750(FUN_1403ed2b0(), FUN_140c1cda0(&spMenu)->m_nUiId);
    FUN_140c1ccf0(&spMenu);
    return 1;
}

// @0x140c22ae0
void UIHighlightGameMenu::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_timer.FUN_140268870(1000) != 0)
        FUN_140c22f50();
}

// @0x140c22b30
void UIHighlightGameMenu::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    CStringW strKey = FUN_1402a5170(L"s_highlightgamemenu_{0}", pArgs->FUN_1422b8d30());
    ASTooltip tip(1, 2);
    if (tip.FUN_1409e26b0(FUN_14028b8e0(strKey)) != 0)
    {
        tip.FUN_1409c6dc0(1);
        tip.FUN_1409c6e00(0);
        tip.FUN_1409c6e30(0);
        FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
    }
}

// @0x140c22c60
void UIHighlightGameMenu::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
}

// @0x140c22d00
void UIHighlightGameMenu::vfunc_5(void* pItem, int nCount)
{
    if (FUN_140ba28d0(&m_30, 0) == 0 && nCount != 0 && pItem != 0)
    {
        if (FUN_14053d840(FUN_140527840(pItem)) != 0)
            m_bitsGem.FUN_140c260a0(0, true);
    }
}

// @0x140c22d80
void UIHighlightGameMenu::vfunc_2(void* pItem)
{
    if (FUN_140ba28d0(&m_30, 0) == 0 && pItem != 0)
    {
        if (FUN_14053d840(FUN_140527840(pItem)) != 0)
            m_bitsGem.FUN_140c260a0(0, true);
    }
}

// @0x140c22df0
void UIHighlightGameMenu::vfunc_21(void* pItem)
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        if (m_bitsSocket.FUN_140c25f10(0).FUN_140c24ac0() != true && pItem != 0 && FUN_1405279c0(pItem) != 0)
        {
            if (FUN_140621340(FUN_1405279c0(pItem)) != 0)
                m_bitsGem.FUN_140c260a0(0, true);
        }
    }
}

// @0x140c22ea0
void UIHighlightGameMenu::vfunc_22(void* pItem)
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        if (m_bitsSocket.FUN_140c25f10(0).FUN_140c24ac0() && pItem != 0 && FUN_1405279c0(pItem) != 0)
        {
            if (FUN_140621340(FUN_1405279c0(pItem)) != 0)
                m_bitsGem.FUN_140c260a0(0, true);
        }
    }
}

// @0x140c22f50
void UIHighlightGameMenu::FUN_140c22f50()
{
    if (FUN_140a467d0(&m_30))
        return;
    Unk_HlPc* pPc = (Unk_HlPc*)FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    unsigned nLevel = pPc->vfunc_78();
    if (nLevel < *FUN_1401d7c10((char*)FUN_1401d3200() + 0xe558))
        return;
    ASArray names(2);
    if (*((char*)FUN_140b123b0(FUN_1409a8b10()) + 0x15) == 0)
    {
        POSITION pos = m_actions.GetStartPosition();
        while (pos != 0)
        {
            Action pAction = m_actions.GetValueAt(pos);
            if ((this->*pAction)() != 0)
                names.FUN_1422bbf70(m_actions.GetKeyAt(pos));
            m_actions.GetNext(pos);
        }
    }
    int nCount = names.FUN_1422bc5d0();
    if (m_nCount != nCount)
    {
        m_nCount = nCount;
        m_bActive = m_nCount != 0;
        if (FUN_140c24ef0() != 0)
            FUN_140bc1730(FUN_140c24ef0());
    }
    FUN_1409ee290(&m_30)->FUN_140bd2cb0("setMenu", names);
}

// @0x140c231b0
bool UIHighlightGameMenu::FUN_140c231b0()
{
    Unk_HlPc* pPc = (Unk_HlPc*)FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    ATL::CAtlArray<void*> bag;
    DAT_143ab2a90.FUN_140a60880(0, bag);
    char limit[16];
    FUN_1406c47a0(limit, FUN_140869440());
    FUN_14086a880(limit, 0xfffffff6);
    for (unsigned __int64 i = 0; i < FUN_140720ca0(&bag); ++i)
    {
        Unk_HlH item;
        FUN_1402034d0(&item, FUN_140a69ee0(&bag, i));
        if (FUN_140528ae0(FUN_1401c0180(&item)) < FUN_140282020(limit))
        {
            FUN_1401bfde0(&item);
            continue;
        }
        if (DAT_143ab2a90.FUN_140a65770(FUN_14052cd70(&item)) != 0)
        {
            FUN_1401bfde0(&item);
            continue;
        }
        char rec[16];
        FUN_1401bf970(rec, FUN_140527840(FUN_1401c0180(&item)));
        if (FUN_1402ffd90(rec) != 0)
        {
            FUN_1401b50d0(rec);
            FUN_1401bfde0(&item);
            continue;
        }
        int nEquip = FUN_141654700(pPc);
        if (FUN_140545da0((char*)FUN_1401b52a0(rec) + 0x138, nEquip) == 0)
        {
            FUN_1401b50d0(rec);
            FUN_1401bfde0(&item);
            continue;
        }
        Unk_HlH worn;
        FUN_14152e2f0(pPc, &worn, item);
        if (FUN_140534e50(&worn) != 0)
        {
            FUN_1401bfde0(&worn);
            FUN_1401b50d0(rec);
            FUN_1401bfde0(&item);
            return true;
        }
        int nNew = FUN_140529070(FUN_1401c0180(&item));
        int nOld = FUN_140529070(FUN_1401c0180(&worn));
        if (nOld < nNew)
        {
            FUN_1401bfde0(&worn);
            FUN_1401b50d0(rec);
            FUN_1401bfde0(&item);
            return true;
        }
        FUN_1401bfde0(&worn);
        FUN_1401b50d0(rec);
        FUN_1401bfde0(&item);
    }
    return false;
}

// @0x140c234d0
bool UIHighlightGameMenu::FUN_140c234d0()
{
    Unk_HlPc* pPc = (Unk_HlPc*)FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc != 0)
    {
        int nMax = FUN_140644b80(FUN_1401d7a50(), FUN_141654730(pPc) != 0);
        for (int i = 1; i <= nMax; ++i)
        {
            if (FUN_14152e970(pPc, i) != 0)
            {
                if (i != 1)
                    return true;
                unsigned short nLevel = pPc->vfunc_78();
                unsigned nNeed = FUN_14067a8d0(FUN_1401c0db0(), nLevel);
                if (FUN_140639b40(FUN_1416546d0(pPc), 1) < nNeed)
                    return true;
            }
        }
    }
    return false;
}

// @0x140c235d0
bool UIHighlightGameMenu::FUN_140c235d0()
{
    if (FUN_1408e3520(DAT_143ab2ee0) != 0)
        return true;
    if (FUN_1408e48b0(DAT_143ab2ee0) != 0)
    {
        P pArr = FUN_1408e3700(DAT_143ab2ee0);
        for (unsigned __int64 i = 0; i < FUN_1408e57c0(pArr); ++i)
        {
            char h[16];
            FUN_1408e4be0(h, FUN_140c24ea0((__int64*)pArr, i));
            if (FUN_140690370(FUN_1408e5180(h)) >= 100 && FUN_140690370(FUN_1408e5180(h)) < 0x71
                && FUN_140691130(FUN_1408e5180(h)) == 0)
            {
                FUN_1408e4ea0(h);
                return true;
            }
            FUN_1408e4ea0(h);
        }
    }
    return false;
}

// @0x140c236f0
bool UIHighlightGameMenu::FUN_140c236f0()
{
    Unk_HlPc* pPc = (Unk_HlPc*)FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    Unk_HlRef ref;
    int nPoint = FUN_140caa1a0(FUN_140c24af0(FUN_140c25130(pPc, &ref)));
    FUN_140c24a50(&ref);
    return nPoint != 0;
}

#define HL_END_IT() do { FUN_1401b50d0(h148); FUN_1401bfde0(&it); } while (0)

// @0x140c237a0
bool UIHighlightGameMenu::FUN_140c237a0()
{
    Unk_HlPc* pPc = (Unk_HlPc*)FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    m_nScrollItem = 0;
    m_nTargetItem = 0;
    ATL::CAtlArray<void*> ids;
    FUN_1401855a0(&ids, 0x1d90b9a);
    FUN_1401855a0(&ids, 0x1d90b9b);
    FUN_1401855a0(&ids, 0x1d90b9c);
    Unk_HlH scroll;
    FUN_140203510(&scroll, 0);
    for (unsigned __int64 i = 0; i < FUN_140186270(&ids); ++i)
    {
        Unk_HlH found = DAT_143ab2a90.FUN_140a5e2e0(*FUN_140184510(&ids, i));
        if (FUN_14052cd70(&found) != 0)
        {
            FUN_140692c90(&scroll, &found);
            FUN_1401bfde0(&found);
            break;
        }
        FUN_1401bfde0(&found);
    }
    if (FUN_1401c0050(&scroll, 0) != 0)
    {
        FUN_1401bfde0(&scroll);
        return false;
    }
    char rec[16];
    FUN_1401bf970(rec, FUN_140527840(FUN_1401c0180(&scroll)));
    if (FUN_1402ffd90(rec) != 0 || FUN_14034eee0((char*)FUN_1401b52a0(rec) + 0x290, L"EnchantScroll") != 0)
    {
        FUN_1401b50d0(rec);
        FUN_1401bfde0(&scroll);
        return false;
    }
    int nKind = FUN_1408d1f60((char*)FUN_1401b52a0(rec) + 0x2b0, 0, 0);
    char ench[16];
    FUN_14034e360(FUN_14034f780(), ench, nKind);
    if (FUN_14034eeb0(ench) != 0)
    {
        FUN_14034ed30(ench);
        FUN_1401b50d0(rec);
        FUN_1401bfde0(&scroll);
        return false;
    }
    ATL::CAtlArray<void*> items;
    DAT_143ab2a90.FUN_140a60880(0, items);
    char list[0x40];
    FUN_140884ed0(list, 10);
    FUN_1411e1ce0(FUN_1416561a0(pPc), list, 0);
    for (P pos = FUN_140885670(list); pos != 0; FUN_140885680(list, &pos))
    {
        char h78[16];
        FUN_140884f30(h78, FUN_140885600(list, pos));
        Unk_HlH v;
        FUN_1411dc7a0(FUN_1405a8ed0(h78), &v);
        if (FUN_140534e50(&v) == 0)
            FUN_140720b80(&items, &v);
        FUN_1401bfde0(&v);
        FUN_1405a85f0(h78);
    }
    for (unsigned __int64 j = 0; j < FUN_140720ca0(&items); ++j)
    {
        Unk_HlH it;
        char h148[16];
        FUN_1402034d0(&it, FUN_140a69ee0(&items, j));
        FUN_1401bf970(h148, FUN_140527840(FUN_1401c0180(&it)));
        if (FUN_1402ffd90(h148) != 0)
        {
            HL_END_IT();
            continue;
        }
        if (FUN_140527710(FUN_1401c0180(&it)) < 0x32 || FUN_140526bd0(FUN_1401c0180(&it)) != 3)
        {
            HL_END_IT();
            continue;
        }
        int nId = FUN_14053c620(FUN_1401b52a0(h148));
        if (FUN_140408410((char*)FUN_14034ef20(ench) + 0x38, &nId) == -1)
        {
            HL_END_IT();
            continue;
        }
        P pId = FUN_14052cd70(&it);
        if (FUN_14058df90(FUN_1409eece0(), pId) == 0)
        {
            HL_END_IT();
            continue;
        }
        if (FUN_140526fc0(FUN_1401c0180(&it)) < *(int*)((char*)FUN_14034ef20(ench) + 0x1c)
            && FUN_140527030(FUN_1401c0180(&it)) == 0)
        {
            m_nScrollItem = FUN_140526a50(FUN_1401c0180(&scroll));
            m_nTargetItem = FUN_140526a50(FUN_1401c0180(&it));
            HL_END_IT();
            FUN_1408850d0(list);
            FUN_14034ed30(ench);
            FUN_1401b50d0(rec);
            FUN_1401bfde0(&scroll);
            return true;
        }
        HL_END_IT();
    }
    FUN_1408850d0(list);
    FUN_14034ed30(ench);
    FUN_1401b50d0(rec);
    FUN_1401bfde0(&scroll);
    return false;
}

// @0x140c23f10
bool UIHighlightGameMenu::FUN_140c23f10()
{
    if (!m_bitsGem.FUN_140c25f10(0).FUN_140c24ac0() && !m_bitsSocket.FUN_140c25f10(0).FUN_140c24ac0())
        return false;
    Unk_HlPc* pPc = (Unk_HlPc*)FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    m_bitsGem.FUN_140c260a0(0, false);
    char list[0x40];
    FUN_140884ed0(list, 10);
    FUN_1411e1ce0(FUN_1416561a0(pPc), list, 0);
    FUN_1411e1ce0(FUN_1416561a0(pPc), list, 1);
    if (FUN_140c25330(list) == 0)
    {
        unsigned nMask = 0;
        for (P pos = FUN_140885670(list); pos != 0; FUN_140885680(list, &pos))
        {
            char h[16];
            FUN_140884f30(h, FUN_140885600(list, pos));
            bool bSkip;
            if (FUN_1409edd90(h, 0) == 0)
            {
                Unk_HlH tmp;
                FUN_1411dc7a0(FUN_1405a8ed0(h), &tmp);
                bSkip = FUN_1401c0050(&tmp, 0) != 0;
                FUN_1401bfde0(&tmp);
            }
            else
                bSkip = true;
            if (bSkip)
            {
                FUN_1405a85f0(h);
                continue;
            }
            Unk_HlH it;
            FUN_1411dc7a0(FUN_1405a8ed0(h), &it);
            if (FUN_1405279c0(FUN_1401c0180(&it)) != 0 && FUN_140621340(FUN_1405279c0(FUN_1401c0180(&it))) != 0)
            {
                nMask |= FUN_1405258b0(FUN_1401c0180(&it)) == 0 ? 7 : 8;
                FUN_1401bfde0(&it);
                FUN_1405a85f0(h);
                if (nMask < 0xf)
                    continue;
                break;
            }
            FUN_1401bfde0(&it);
            FUN_1405a85f0(h);
        }
        if (nMask != 0)
        {
            ATL::CAtlArray<void*> gems;
            DAT_143ab2a90.FUN_140a60880(6, gems);
            for (unsigned __int64 k = 0; k < FUN_140720ca0(&gems); ++k)
            {
                Unk_HlH g;
                FUN_1402034d0(&g, FUN_140a69ee0(&gems, k));
                if (FUN_1401c0050(&g, 0) == 0 && FUN_140527840(FUN_1401c0180(&g)) != 0
                    && FUN_14053d840(FUN_140527840(FUN_1401c0180(&g))) != 0)
                {
                    int nId = FUN_1405276c0(FUN_1401c0180(&g));
                    char rec[16];
                    FUN_1405b1a60(FUN_14062c280(), rec, nId);
                    if (FUN_1405b2610(rec, 0) == 0 && (*(unsigned*)((char*)FUN_1405b2650(rec) + 0x28) & nMask) != 0)
                    {
                        m_bitsSocket.FUN_140c260a0(0, true);
                        FUN_1405b2540(rec);
                        FUN_1401bfde0(&g);
                        FUN_1408850d0(list);
                        return true;
                    }
                    FUN_1405b2540(rec);
                }
                FUN_1401bfde0(&g);
            }
        }
    }
    m_bitsSocket.FUN_140c260a0(0, false);
    FUN_1408850d0(list);
    return false;
}

// @0x140c22ce0
bool UIHighlightGameMenu::FUN_140c22ce0()
{
    return m_bActive;
}

// @0x140c244b0
void UIHighlightGameMenu::FUN_140c244b0(int* pPos, bool bSet)
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
        m_bitsSocket.FUN_140c260a0(*pPos, bSet);
}

// @0x140c26320
int FUN_140c26320(void* pDst, size_t nDstSize, const void* pSrc, size_t nCount)
{
    if (nCount == 0)
        return 0;
    if (pDst == 0 || pSrc == 0)
    {
        *_errno() = EINVAL;
        _invalid_parameter_noinfo();
        return EINVAL;
    }
    if (nDstSize < nCount)
    {
        *_errno() = ERANGE;
        _invalid_parameter_noinfo();
        return ERANGE;
    }
    memmove(pDst, pSrc, nCount);
    return 0;
}

// @0x140c24470
void UIHighlightGameMenu::FUN_140c24470(NotifyObject* pObj)
{
    m_bitsGem.FUN_140c261c0();
    m_bitsSocket.FUN_140c26080();
}

// @0x140c24650
P FUN_140c24650()
{
    P pUi = FUN_1403ed2b0();
    if (pUi == 0)
        return 0;
    Unk_HlH h;
    FUN_141adcea0(pUi, &h, FUN_140c25190());
    if (FUN_140534e80(&h) == 0)
    {
        P p = (P)dynamic_cast<UIDialog*>((UIObject*)FUN_1403ed9e0(&h));
        FUN_1403e5630(&h);
        return p;
    }
    FUN_1403e5630(&h);
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca2700-0x142ca27e0 .text$yd
