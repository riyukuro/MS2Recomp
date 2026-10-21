// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIManufactureDialog ("ManufactureDialog", UI type 0x4ec0, 0x220 bytes) is
// the maid manufacture window: the recipe list of the maid npc ("m_scrollList"), the selected recipe with its product and its
// ingredients, the running craft with its progress gauge, and the receive / cancel / jackpot requests (CManufactureManager,
// manufacturemanager.cpp, sends them and calls the result handlers of this unit). See uimanufacturedialog.h.
// MS2-UNIT: ?\uimanufacturedialog.cpp
// MS2-RANGE: 0x1400ee810-0x1400ee9d0 .text$di
// MS2-RANGE: 0x1412e24f0-0x1412e84b0 .text$mn
// MS2-GUESS-LOOKALIKES
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimanufacturedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uimanufacturedialog.h"

#include <atlcoll.h>
#include <atltime.h>
#include <vector>
#include <stdlib.h>

#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>

#include "ms2/ms2format.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uitalkcinematic.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmanufacturemanager.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (dynamic initializers 0x1400ee810..0x1400ee9a0) ----
#ifndef MS2_HOOK_DLL
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
// A zero-initialised handle (static initialised by FUN_1401cd100(&DAT, 0)).
struct Unk_UmRegMarker {};
void FUN_1401cd100(void* h, int a);
static void* s_dat_143ad7500;
static Unk_UmRegMarker s_init_143ad7500 = (FUN_1401cd100(&s_dat_143ad7500, 0), Unk_UmRegMarker());
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
#endif

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObjectContainer
{
public:
    virtual void vfunc_2(int, int, int);                        // place the movie
    int FUN_1422c13b0();                                        // width
};

// The maid record (CMaid) behind a maid npc: only the fields used here.
class Unk_UmMaid : public CPtred
{
public:
    int FUN_14067dd10();                                        // the mood (0, 1, other)
    int FUN_14067dca0();                                        // the affinity is at its maximum
    char m_pad_18[0x34 - 0x18];
    int m_34;                                                   // +0x34 the maid (npc table key)
    char m_pad_38[0x50 - 0x38];
    int m_50;                                                   // +0x50 the affinity experience
    int m_54;                                                   // +0x54 the affinity grade
    char m_pad_58[0x60 - 0x58];
    int m_60;                                                   // +0x60
};
MS2_CHECK_OFFSET(Unk_UmMaid, m_34, 0x34);
MS2_CHECK_OFFSET(Unk_UmMaid, m_60, 0x60);

// The maid npc (CNpc): the maid record.
class Unk_MfNpc { public: MS2Ptr<Unk_UmMaid> FUN_141093800(); };

// The local player (only its stats).
class Unk_UmEquipSet { public: float FUN_1411e1110(int nStat); };
class Unk_UmPC { public: Unk_UmEquipSet* FUN_1416561a0(); };

class Unk_UmWorld
{
public:
    Unk_UmPC* FUN_141bd0cc0();                                  // the local player
    Unk_MfNpc* FUN_141bd1320(int nActorId);                     // an actor by object id
};
Unk_UmWorld* FUN_1403ed2d0();

// The exe's 16 byte smart pointer to a boxed payload (the table rows are boxed in a TPtredDummy; the pointer points at the
// payload, 0x18 behind the CPtred base). Same as the one of the manufacture manager.
template <class T> class Unk_UmValuePtr
{
public:
    Unk_UmValuePtr() : m_pad(0), m_p(0) {}
    Unk_UmValuePtr(const Unk_UmValuePtr& o) : m_pad(0), m_p(o.m_p) { AddRef(); }
    ~Unk_UmValuePtr() { Release(); }
    Unk_UmValuePtr& operator=(const Unk_UmValuePtr& o) { o.AddRef(); Release(); m_p = o.m_p; return *this; }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
    bool IsNull() const { return m_p == 0; }
private:
    static CPtred* Base(T* p) { return reinterpret_cast<CPtred*>(reinterpret_cast<char*>(p) - sizeof(CPtred)); }
    void AddRef() const { if (m_p) CPtred::AddRefPtred(Base(m_p)); }
    void Release()
    {
        if (m_p)
        {
            if (CPtred::ReleasePtred(Base(m_p)) == 0)
            {
                CPtred::AddRefPtred(Base(m_p));
                CPtred::DeletePtred(Base(m_p));
            }
            m_p = 0;
        }
    }
    void* m_pad;
    T* m_p;
};

// The maid description table (the maid's name).
struct Unk_UmDescRow
{
    char m_pad_00[0x10];
    CStringW m_10;                                              // +0x10 the maid's name
};
class Unk_UmDescTable { public: Unk_UmValuePtr<Unk_UmDescRow> FUN_14067f780(int nMsgId); };
Unk_UmDescTable* FUN_1409eed10();

// The recipe books (a maid's recipes and their grades).
struct Unk_UmRecipeRef { int m_id; int m_level; };              // one entry of a maid's recipe book
class Unk_UmRecipeArr
{
public:
    size_t FUN_14068acc0() const;                               // count
    Unk_UmValuePtr<Unk_UmRecipeRef> FUN_140689a50(size_t n);
};
class Unk_UmBook
{
public:
    Unk_UmRecipeArr& FUN_140689bf0();
    Unk_UmRecipeArr& FUN_140689c20();
};
class Unk_UmBookTable
{
public:
    Unk_UmValuePtr<Unk_UmBook> FUN_140685da0(int nBookId);
    int FUN_140685e60(int nBookId, int nRecipeId, int* pnGrade);   // the grade a recipe needs
};
Unk_UmBookTable* FUN_1412db940();

// A recipe ingredient.
struct Unk_UmIngredient
{
    int FUN_140684c40();                                        // item id
    int FUN_140684c80();                                        // group
    int m_nCount;                                               // +0x00
    int m_nRarity;                                              // +0x04
    unsigned m_nItemId;                                         // +0x08
    int m_nGroup;                                               // +0x0c
};

// A manufacture recipe.
struct Unk_UmRecipe
{
    char m_pad_00[0x1c];
    int m_1c;                                                   // +0x1c the meso a craft needs
    unsigned m_20[3];                                           // +0x20 the craft time per mood
    int m_2c;                                                   // +0x2c the meso cost
    char m_pad_30[0x38 - 0x30];
    std::vector<Unk_UmValuePtr<Unk_UmIngredient> > m_38;        // +0x38 the ingredients
    int m_50;                                                   // +0x50 the result item id
    int m_54;                                                   // +0x54 the result amount
    int m_58;                                                   // +0x58 the result rarity
};
MS2_CHECK_OFFSET(Unk_UmRecipe, m_38, 0x38);
MS2_CHECK_OFFSET(Unk_UmRecipe, m_50, 0x50);
class Unk_UmRecipeTable { public: Unk_UmValuePtr<Unk_UmRecipe> FUN_1406855c0(int nRecipeId); };
Unk_UmRecipeTable* FUN_1409eed30();

// The record of a running craft.
struct Unk_UmMfItem : public CPtred
{
    char m_pad_18[0x3c - 0x18];
    int m_3c;                                                   // +0x3c the manufacture time (seconds)
    int FUN_1409eedf0();                                        // the recipe id
    __int64 FUN_140694170();                                    // the time it is ready
};
class Unk_UmMfBook { public: int FUN_140d51370(__int64 nKey, MS2Ptr<Unk_UmMfItem>& out); };
Unk_UmMfBook* FUN_1409eed40();

// The string table and the client constants.
struct Unk_UmStrings { CStringW FUN_141811980(int, int); };
Unk_UmStrings* FUN_1401a9d70();
struct Unk_UmLevels { char m_pad[0x5180]; int m_5180; };
class Unk_UmLevelInfo { public: int* FUN_1402056b0(); };        // the player's manufacture level
Unk_UmLevelInfo* FUN_1401d3200();

CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_1408116a0(int nStringId, const int& nArg);
CStringW FUN_14028de60(int nStringId);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringW FUN_14093fa20(int nStringId, const CStringW& strArg, const int& nArg);
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& strArg0, const CStringW& strArg1);
const int& FUN_1404eb7e0(const int& a, const int& b);           // std::max<int>
int FUN_14053feb0(int nItemId);                                 // default rarity of an item
class Unk_UmMaidCost { public: int FUN_14067ed30(int nGrade); };    // the experience of one affinity grade
Unk_UmMaidCost* FUN_14067e910();
class Unk_UmCrafts { public: unsigned FUN_14047b7c0(float fRate, int nValue); unsigned FUN_14047b860(float fRate, unsigned nValue); };
Unk_UmCrafts* FUN_1401c0d90();
unsigned FUN_140869420();                                       // millisecond clock
__int64 FUN_140869440();                                        // the server time
ATL::CTime FUN_1406c47a0(__int64 nTime);
bool FUN_1406c4c60(const ATL::CTime& tReady, const ATL::CTime& tNow);   // still waiting
CStringW FUN_1412e1e50(ATL::CTimeSpan span, int bShort, int bSuffix);
CStringW FUN_1418fec90(int nCurrency, __int64 nAmount, int nArg);
class Unk_UmLua { public: int FUN_1406769f0(unsigned nSeconds); };
Unk_UmLua* FUN_1401c0db0();
class Unk_UmFeatures { public: bool FUN_14036d710(int nFeature); };
Unk_UmFeatures* FUN_140166410();
int FUN_14116d720(void* pHook);
void* FUN_14025e7c0();                                          // the client's text-hook object
int FUN_1412dd760(Unk_UmMfItem* pItem);                         // the manufacture time of a record
void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW strTag);   // pop the system message
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_141415450(const CString& strKey, MS2Ptr<CItem> spItem, int a, int b, int c);
void FUN_141415600(const CString& strKey);
void FUN_14151f200();
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, int n);
UITalkCinematic* FUN_140a7b2b0(int nId);                        // a dialog by UI id

// The player's inventory (owned counts) and the account id.
class Unk_MfInventory
{
public:
    unsigned FUN_140a5f180(int nItemId, int nRarity);           // owned count of the item (group 0)
    unsigned FUN_140a5f780(int nGroup, int nRarity);            // owned count of the group
};
class Unk_MfCubeService : public efd::ISystemService { public: int FUN_1410d2fb0(__int64 nAccountId, int nMeso, int* pnCode); };
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
Unk_MfCubeService* FUN_1401cd040(Unk_EntityAppFramework* pFramework);
extern Unk_EntityAppFramework DAT_143b059e8;
extern Unk_MfInventory DAT_143ab2a90;
extern __int64 DAT_143ab2820;

// The wallet check of the network callbacks object (slots 40 / 41: the player can pay the amount with meso / merat).
class Unk_UmWallet
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual bool vfunc_40(__int64 nAmount);
    virtual bool vfunc_41(__int64 nAmount);
};
Unk_UmWallet* FUN_140d86260();

// The list child "m_scrollList" of the movie (slot 24 refreshes it).
class Unk_UmCtl : public AScript
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
class Unk_UmList : public Unk_UmCtl
{
public:
    void FUN_1422dd1d0();                                       // clear
    void FUN_1422dcca0(int n);                                  // select the row
    void FUN_1422dd230(const ASObj& row);                       // append a row
};

// ---- the Invoke wrappers this unit owns (inline COMDATs) ----

void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned long long n);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// @0x1412e7f30
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, CStringW a2, CStringW a3, CStringW a4, int a5, bool a6)
{
    ASArgList args;
    args.FUN_1409b2800(6);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    FUN_1422bcea0(args.FUN_1409b1f70(3), a4);
    FUN_1422bccb0(args.FUN_1409b1f70(4), a5);
    FUN_1422bcce0(args.FUN_1409b1f70(5), a6);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1412e80d0
inline Scaleform::GFx::Value AScript::FUN_1412e80d0(const char* szMethod, CStringW a1, CStringW a2, CStringW a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1412e8210
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, unsigned __int64 a1, CString a2, CStringW a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce00(args.FUN_1409b1f70(0), a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// The common string of a table id, formatted ("{0} {1}"): the instances of this unit are FUN_1412e71a0 (int, L"", int),
// FUN_1412e7520 (int, int, int), FUN_1412e78a0 (unsigned, CStringW, unsigned) and FUN_1412e7c20 (CStringW, unsigned).
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
template CStringW FUN_14028dee0<CStringW, unsigned>(int, const CStringW&, const unsigned&);

// The instance with a wide literal argument (FUN_1412e71a0): its argument type helper is the wide-formatter ArgType copy of
// the exe (140b1f1d0), see wcformat.h.
#define UM_WC_REF(n) fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(v##n)
template <FMT_GEN(3, FMT_MAKE_TEMPLATE_ARG)>
inline CStringW FUN_14028dee0_wc(int nId, FMT_GEN(3, FMT_MAKE_ARG))
{
    const fmt::internal::ArgArray<3>::Type array = {FMT_GEN(3, UM_WC_REF)};
    return FUN_14028dee0(nId, fmt::ArgList(fmt::internal::wc_make_type(FMT_GEN(3, FMT_MAKE_REF2)), array));
}
template CStringW FUN_14028dee0_wc<int, wchar_t[1], int>(int, const int&, const wchar_t(&)[1], const int&);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1412e24f0
UIManufactureDialog::UIManufactureDialog()
    : m_nNpcId(0), m_nManufactureId(0), m_nSelected(0), m_194(0), m_nState(0), m_nLastTick(0), m_mapRecipes(10)
{
    m_2c = 0xc;
    FUN_1422dc3b0(1);
    FUN_141924170(1);
}

// @0x1412e2660
UIManufactureDialog::~UIManufactureDialog()
{
}

// @0x1412e2730
CString UIManufactureDialog::vfunc_1()
{
    return CString("ManufactureDialog");
}

// @0x1412e2780
void UIManufactureDialog::vfunc_67()
{
    m_nNpcId = 0;
    m_nManufactureId = 0;
    m_nSelected = 0;
    m_nState = 0;
    m_nLastTick = 0;
    m_mapRecipes.RemoveAll();
    for (size_t i = 0; i < m_aRowKeys.GetCount(); i++)
        FUN_141415600(m_aRowKeys[i]);
    for (size_t j = 0; j < m_aIngredientKeys.GetCount(); j++)
        FUN_141415600(m_aIngredientKeys[j]);
    FUN_141415600(m_strProductKey);
    FUN_141415600(m_strProgressKey);
    vfunc_47(1);
    UIDialog::vfunc_67();
}

// @0x1412e28f0
void UIManufactureDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    vfunc_47(0);
}

// @0x1412e2930
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
int UIManufactureDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    if (_stricmp("OnSelectedList", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_nSelected = data.FUN_1422b8a10();
            FUN_1412e5c90();
        }
        return 1;
    }
    if (_stricmp("OnCraft", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_1412e5dd0(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnCraftAdmin", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_1412e5f70(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("onRecieve", szMethod) == 0)
    {
        FUN_1412e6250();
        return 1;
    }
    if (_stricmp("onRecieveOrCancel", szMethod) == 0)
    {
        if (m_nState == 2)
            FUN_1412e6250();
        else if (m_nState == 1)
            FUN_140d73bc0(0x7b7, 1, static_cast<IMessageListener*>(this), CStringW(L"OnCancel"));
        return 0;
    }
    if (_stricmp("onRecieveByMerat", szMethod) == 0)
    {
        FUN_1412e63b0();
        return 1;
    }
    if (_stricmp("onRecieveJackpot", szMethod) == 0)
    {
        FUN_1412e66f0();
        return 1;
    }
    return 0;
}

// @0x1412e2cf0
int UIManufactureDialog::vfunc_13()
{
    vfunc_55();
    return 0;
}

// @0x1412e2d30
void UIManufactureDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    UITalkCinematic* pRef;
    if (pDialog != 0 && (pRef = FUN_140a7b2b0(0x4e40)) != 0)
    {
        int nX = pRef->FUN_141b1d3d0();
        int nY = pRef->FUN_141b1d460() - 0x14;
        if (nX != -1 && nY != -1)
        {
            pDialog->vfunc_2(5, nY, nX - pDialog->FUN_1422c13b0() - 2);
            return;
        }
    }
    ASDialog* pDefault = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDefault != 0)
        pDefault->vfunc_2(1, 0, 0);
}

// @0x1412e2e70
int UIManufactureDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        ATL::CAtlArray<CStringW> kArr;
        FUN_14151f200();
        if (nResult == 0 && FUN_1403b3c40(strTag, L"OnCancel"))
        {
            FUN_1412e69a0();
            return 1;
        }
        return 1;
    }
    return 0;
}

// @0x1412e2fc0
void UIManufactureDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_194 = 0;
    FUN_1412e34c0();
    FUN_1412e3990(1);
    FUN_1412e4240();
}

// @0x1412e3010
// MS2-FUNCTIONAL: frame layout of the string temporaries and the handle copies differs
void UIManufactureDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_30.IsNull() || m_nState != 1 || m_nLastTick + 1000 > FUN_140869420())
        return;
    m_nLastTick = FUN_140869420();
    MS2Ptr<Unk_UmMfItem> spItem(0);
    if (FUN_1409eed40()->FUN_140d51370(m_nManufactureId, spItem) == 0)
        return;
    ATL::CTime tReady = FUN_1406c47a0(spItem->FUN_140694170());
    ATL::CTime tNow = FUN_1406c47a0(FUN_140869440());
    ATL::CTimeSpan span = tReady - tNow;
    if (!FUN_1406c4c60(tReady, tNow))
    {
        m_nState = 2;
        m_30->Invoke("setProgress", m_nState, FUN_14116d720(FUN_14025e7c0()) ? true : false);
        m_30->Invoke("updateProgressGauge", FUN_14028de60(0x7b8), 1000);
    }
    else
    {
        unsigned __int64 nSeconds = span.GetTotalSeconds();
        int nLeft = FUN_1401c0db0()->FUN_1406769f0((unsigned)nSeconds);
        int nCurrency = 3;
        if (FUN_140166410()->FUN_14036d710(0x102))
            nCurrency = 10;
        m_30->Invoke("setItemMeratLabel", FUN_14052bd00(0x7ba, FUN_1418fec90(nCurrency, (__int64)nLeft, 0)));
        int nTotal = FUN_1412dd760(spItem.operator->());
        __int64 nRemain = span.GetTotalSeconds();
        int nPermille = 0;
        if (0 < nTotal)
            nPermille = 1000 - ((int)nRemain * 1000) / nTotal;
        m_30->Invoke("updateProgressGauge", FUN_1412e1e50(span, 0, 1), nPermille);
    }
}

// @0x1412e3480
void UIManufactureDialog::FUN_1412e3480(int nNpcId, unsigned __int64 nManufactureId)
{
    m_nNpcId = nNpcId;
    m_nManufactureId = nManufactureId;
}

// @0x1412e34c0
void UIManufactureDialog::FUN_1412e34c0()
{
    if (m_30.IsNull())
        return;
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    Unk_UmValuePtr<Unk_UmDescRow> spDesc = FUN_1409eed10()->FUN_14067f780(spMaid->m_34);
    if (spDesc.IsNull())
        return;
    CStringW strName = FUN_14052bd00(0x7af, spDesc->m_10);
    CStringW strMood;
    if (spMaid->FUN_14067dd10() == 0)
        strMood = FUN_14028de60(0x79f);
    else if (spMaid->FUN_14067dd10() == 1)
        strMood = FUN_14028de60(0x7a0);
    else
        strMood = FUN_14028de60(0x7a1);
    CStringW strGrade = FUN_14093fa20(0x7b0, strMood, spMaid->m_54);
    int nNeed = FUN_14067e910()->FUN_14067ed30(spMaid->m_54);
    int nOne = 1;
    int nMax = FUN_1404eb7e0(nOne, nNeed);
    CStringW strExp = FUN_14028dee0(0x7b1, spMaid->m_50, spMaid->m_60, nMax);
    if (spMaid->FUN_14067dca0() != 0)
        strExp = FUN_1408116a0(0x7b2, spMaid->m_50);
    m_30->FUN_1412e80d0("setTitle", CStringW(strName), CStringW(strGrade), CStringW(strExp));
}

// @0x1412e3990
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIManufactureDialog::FUN_1412e3990(int bSelect)
{
    if (m_30.IsNull())
        return;
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    Unk_UmValuePtr<Unk_UmBook> spBook = FUN_1412db940()->FUN_140685da0(spMaid->m_34);
    if (spBook.get() == 0)
        return;
    MS2Ptr<Unk_UmList> spList = FUN_140c02900<Unk_UmList>(CString("m_scrollList"));
    if (spList.get() == 0)
        return;
    spList->FUN_1422dd1d0();
    int nFirst = 0;
    for (size_t i = 0; i < spBook->FUN_140689bf0().FUN_14068acc0(); i++)
    {
        Unk_UmValuePtr<Unk_UmRecipeRef> spRef = spBook->FUN_140689c20().FUN_140689a50(i);
        if (spRef.IsNull())
            continue;
        Unk_UmValuePtr<Unk_UmRecipe> spRecipe = FUN_1409eed30()->FUN_1406855c0(spRef->m_id);
        if (spRecipe.get() == 0)
            continue;
        ASObj row(2);
        row.FUN_140e846b0("id", i + 1);
        row.FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, spRecipe->m_50));
        row.FUN_1407cb9c0("recipeID", spRef->m_id);
        if (*FUN_1401d3200()->FUN_1402056b0() < spRef->m_level)
            row.FUN_1407cbb20("require", FUN_1408116a0(0x7ab, spRef->m_level));
        else
            row.FUN_1407cbb20("require", FUN_1408116a0(0x7aa, spRef->m_level));
        m_mapRecipes.SetAt((int)i, spRef->m_id);
        bool bAvailable = spRef->m_level <= spMaid->m_54;
        if (bAvailable)
            nFirst = (int)i;
        row.FUN_1407cb9c0("available", bAvailable);
        spList->FUN_1422dd230(row);
        int nItemId = spRecipe->m_50;
        int nRarity = spRecipe->m_58;
        int nAmount = spRecipe->m_54;
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b130(nItemId, nRarity, 0))
        {
            spItem->FUN_140526c70(nAmount);
            int nFlags;
            if (bAvailable)
                nFlags = 0x415;
            else
                nFlags = 0x2415;
            CString strKey;
            strKey.Format("%s.%d", (const char*)vfunc_1(), i + 1);
            FUN_141415450(strKey, spItem, (int)i, nFlags, 0x800);
            m_30->Invoke("bind", CString(strKey), i + 1, spItem->FUN_140528590());
            m_aRowKeys.Add(strKey);
        }
    }
    spList->vfunc_24(1);
    if (bSelect != 0)
    {
        spList->FUN_1422dcca0(nFirst);
        m_nSelected = nFirst;
        FUN_1412e48a0();
    }
}

// @0x1412e4240
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIManufactureDialog::FUN_1412e4240()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<Unk_UmMfItem> spMf(0);
    if (FUN_1409eed40()->FUN_140d51370(m_nManufactureId, spMf) == 0)
        m_nState = 0;
    else
    {
        Unk_UmValuePtr<Unk_UmRecipe> spRecipe = FUN_1409eed30()->FUN_1406855c0(spMf->FUN_1409eedf0());
        if (spRecipe.get() == 0)
            m_nState = 0;
        else
        {
            CStringW strName = FUN_1401a9d70()->FUN_141811980(1, spRecipe->m_50);
            int nItemId = spRecipe->m_50;
            int nRarity = spRecipe->m_58;
            int nAmount = spRecipe->m_54;
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->FUN_14052b130(nItemId, nRarity, 0))
            {
                spItem->FUN_140526c70(nAmount);
                m_strProgressKey.Format("%s_prgress", (const char*)vfunc_1());
                FUN_141415600(m_strProgressKey);
                FUN_141415450(m_strProgressKey, spItem, 0, 0x415, 0x800);
                m_30->FUN_140c38f00("bindProgress", CString(m_strProgressKey), CStringW(strName));
            }
            ATL::CTime tReady = FUN_1406c47a0(spMf->FUN_140694170());
            ATL::CTime tNow = FUN_1406c47a0(FUN_140869440());
            ATL::CTimeSpan span = tReady - tNow;
            unsigned __int64 nSeconds = span.GetTotalSeconds();
            int nLeft = FUN_1401c0db0()->FUN_1406769f0((unsigned)nSeconds);
            int nCurrency = 3;
            if (FUN_140166410()->FUN_14036d710(0x102))
                nCurrency = 10;
            m_30->Invoke("setItemMeratLabel", FUN_14052bd00(0x7ba, FUN_1418fec90(nCurrency, (__int64)nLeft, 0)));
            if (!FUN_1406c4c60(tReady, tNow))
                m_nState = 2;
            else
                m_nState = 1;
        }
    }
    m_30->Invoke("setProgress", m_nState, FUN_14116d720(FUN_14025e7c0()) ? true : false);
    m_30->Invoke("updateProgressGauge", FUN_14028de60(0x7b8), 1000);
}

// @0x1412e48a0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIManufactureDialog::FUN_1412e48a0()
{
    if (m_30.IsNull())
        return;
    Unk_UmPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nRecipeId = 0;
    if (!m_mapRecipes.Lookup(m_nSelected, nRecipeId))
        return;
    Unk_UmValuePtr<Unk_UmRecipe> spRecipe = FUN_1409eed30()->FUN_1406855c0(nRecipeId);
    if (spRecipe.get() == 0)
        return;
    int nGrade = 0;
    if (FUN_1412db940()->FUN_140685e60(spMaid->m_34, nRecipeId, &nGrade) == 0)
        return;
    int bAvailable = 1;
    if (spMaid->m_54 < nGrade)
        bAvailable = 0;
    if (m_nState != 0)
        bAvailable = 0;
    float fCraftRate = pPlayer->FUN_1416561a0()->FUN_1411e1110(0x3e);
    unsigned nMeso = FUN_1401c0d90()->FUN_14047b7c0(fCraftRate, spRecipe->m_2c);
    CStringW strGrade = FUN_1408116a0(0x7aa, nGrade);
    CStringW strName = FUN_1401a9d70()->FUN_141811980(1, spRecipe->m_50);
    ATL::CTimeSpan span((unsigned __int64)spRecipe->m_20[spMaid->FUN_14067dd10()]);
    CStringW strTime = FUN_1412e1e50(span, 1, 0);
    CStringW strCost = FUN_14028dee0(0x7ac, strTime, nMeso);
    m_30->Invoke("selectItem", m_nSelected, CStringW(strName), CStringW(strGrade), CStringW(strCost), bAvailable, FUN_14116d720(FUN_14025e7c0()) ? true : false);
    int nItemId = spRecipe->m_50;
    int nRarity = spRecipe->m_58;
    int nAmount = spRecipe->m_54;
    MS2Ptr<CItem> spProduct(new CItem());
    if (spProduct->FUN_14052b130(nItemId, nRarity, 0))
    {
        spProduct->FUN_140526c70(nAmount);
        m_strProductKey.Format("%s_product", (const char*)vfunc_1());
        FUN_141415450(m_strProductKey, spProduct, 0, 0x415, 0x800);
        m_30->Invoke("bindProduct", CString(m_strProductKey));
    }
    for (size_t i = 0; i < m_aIngredientKeys.GetCount(); i++)
        FUN_141415600(m_aIngredientKeys[i]);
    std::vector<CStringW> aUnused;
    for (size_t k = 0; k < spRecipe->m_38.size(); k++)
    {
        Unk_UmValuePtr<Unk_UmIngredient> spIngredient = spRecipe->m_38[k];
        if (spIngredient.IsNull())
            continue;
        int nIngItem = spIngredient->FUN_140684c40();
        int nGroup = spIngredient->FUN_140684c80();
        MS2Ptr<CItemData> spData = FUN_14053f870(nIngItem);
        if (spData.get() == 0)
            continue;
        int nIngRarity;
        if (!spData->FUN_14053cbc0())
            nIngRarity = FUN_14053feb0(nIngItem);
        else
            nIngRarity = spIngredient->m_nRarity;
        float fSaveRate = pPlayer->FUN_1416561a0()->FUN_1411e1110(0x3f);
        unsigned nNeeded = FUN_1401c0d90()->FUN_14047b860(fSaveRate, spIngredient->m_nCount);
        MS2Ptr<CItem> spIngItem(new CItem());
        if (spIngItem->FUN_14052b130(nIngItem, nIngRarity, 0))
        {
            spIngItem->FUN_140526c70(nNeeded);
            CString strKey;
            strKey.Format("%s_Ingredient.%d", (const char*)vfunc_1(), k + 1);
            FUN_141415450(strKey, spIngItem, (int)k, 0x415, 0x800);
            m_aIngredientKeys.Add(strKey);
            unsigned nHave = 0;
            if (nGroup == 0)
                nHave = DAT_143ab2a90.FUN_140a5f180(nIngItem, 0);
            else
                nHave = DAT_143ab2a90.FUN_140a5f780(nGroup, 0);
            CStringW strBreak(L"");
            if (nHave > 9999 || (nHave > 999 && nNeeded > 99))
                strBreak = L"\n";
            CStringW strCount(L"");
            if (nHave < nNeeded)
                strCount = FUN_14028dee0(0x7ae, nHave, strBreak, nNeeded);
            else
                strCount = FUN_14028dee0(0x7ad, nHave, strBreak, nNeeded);
            m_30->Invoke("ingredients", (unsigned __int64)(k + 1), CString(strKey), CStringW(strCount));
        }
    }
    if (0 < spRecipe->m_1c)
    {
        int nRow = (int)spRecipe->m_38.size() + 1;
        int nMesoCost = spRecipe->m_1c;
        int nCode = 0;
        efd::SmartPointer<Unk_MfCubeService> spService(FUN_1401cd040(&DAT_143b059e8));
        int nResult = spService->FUN_1410d2fb0(DAT_143ab2820, nMesoCost, &nCode);
        CStringW strMesoText(L"");
        if (nMesoCost == 0x1c)
        {
            if (nResult == 0)
                strMesoText = FUN_14028de60(0x7bc);
            else
                strMesoText = FUN_14028de60(0x7bb);
        }
        else if (nMesoCost == 0x1d)
        {
            if (nResult == 0)
                strMesoText = FUN_14028de60(0x7be);
            else
                strMesoText = FUN_14028de60(0x7bd);
        }
        else if (nMesoCost == 0x1e)
        {
            if (nResult == 0)
                strMesoText = FUN_14028de60(0x7c0);
            else
                strMesoText = FUN_14028de60(0x7bf);
        }
        CStringW strMesoCount(L"");
        if (nResult == 0)
        {
            int nOne = 1;
            strMesoCount = FUN_14028dee0_wc(0x7ae, nCode, L"", nOne);
        }
        else
        {
            int nOne = 1;
            strMesoCount = FUN_14028dee0_wc(0x7ad, nCode, L"", nOne);
        }
        m_30->Invoke("workbench", nRow, CStringW(strMesoText), CStringW(strMesoCount));
    }
}

// @0x1412e5c90
void UIManufactureDialog::FUN_1412e5c90()
{
    if (m_30.IsNull())
        return;
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    FUN_1412e48a0();
    CStringW strText = CManufactureManager::GetInstance()->GetMaidText(0, pNpc);
    UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
    if (pTalk != 0)
        pTalk->FUN_141b1a8e0(strText, "", "");
}

// @0x1412e5dd0
void UIManufactureDialog::FUN_1412e5dd0(int nRow)
{
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nRecipeId = 0;
    if (!m_mapRecipes.Lookup(nRow, nRecipeId))
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest4(m_nManufactureId, nRecipeId, &nResult);
    if (nResult != 1)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, pNpc);
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e5f70
void UIManufactureDialog::FUN_1412e5f70(int nRow)
{
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nRecipeId = 0;
    if (!m_mapRecipes.Lookup(nRow, nRecipeId))
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest5(m_nManufactureId, nRecipeId, &nResult);
    if (nResult != 1)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, pNpc);
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e6110
void UIManufactureDialog::FUN_1412e6110(int nResult)
{
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, pNpc);
    UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
    if (pTalk != 0)
        pTalk->FUN_141b1a8e0(strText, "", "");
    if (nResult == 1)
    {
        FUN_1412e4240();
        FUN_1412e48a0();
    }
}

// @0x1412e6250
void UIManufactureDialog::FUN_1412e6250()
{
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest6(m_nManufactureId, &nResult);
    if (FUN_1412e7170(nResult) == 0)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, pNpc);
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e63b0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIManufactureDialog::FUN_1412e63b0()
{
    MS2Ptr<Unk_UmMfItem> spMf(0);
    if (FUN_1409eed40()->FUN_140d51370(m_nManufactureId, spMf) == 0)
        return;
    ATL::CTime tReady = FUN_1406c47a0(spMf->FUN_140694170());
    ATL::CTime tNow = FUN_1406c47a0(FUN_140869440());
    ATL::CTimeSpan span = tReady - tNow;
    unsigned __int64 nSeconds = span.GetTotalSeconds();
    __int64 nCost = FUN_1401c0db0()->FUN_1406769f0((unsigned)nSeconds);
    if (!FUN_140166410()->FUN_14036d710(0x102))
    {
        if (!FUN_140d86260()->vfunc_40(nCost))
        {
            FUN_141275260(0x35, 1, 1);
            return;
        }
    }
    else
    {
        if (!FUN_140d86260()->vfunc_41(nCost))
        {
            if (!FUN_140d86260()->vfunc_40(nCost))
            {
                FUN_141275260(0x35, 1, 1);
                return;
            }
        }
    }
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest7(m_nManufactureId, &nResult);
    if (FUN_1412e7170(nResult) == 0)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, pNpc);
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e66f0
void UIManufactureDialog::FUN_1412e66f0()
{
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest9(m_nManufactureId, &nResult);
    if (FUN_1412e7170(nResult) == 0)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, pNpc);
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e6850
void UIManufactureDialog::FUN_1412e6850(int nResult)
{
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, pNpc);
    UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
    if (pTalk != 0)
        pTalk->FUN_141b1a8e0(strText, "", "");
    if (FUN_1412e7170(nResult) != 0)
    {
        FUN_1412e4240();
        FUN_1412e48a0();
    }
}

// @0x1412e69a0
void UIManufactureDialog::FUN_1412e69a0()
{
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest10(m_nManufactureId, &nResult);
    if (nResult != 4)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, pNpc);
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e6af0
void UIManufactureDialog::FUN_1412e6af0(int nResult)
{
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, pNpc);
    UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
    if (pTalk != 0)
        pTalk->FUN_141b1a8e0(strText, "", "");
    if (nResult == 4)
    {
        FUN_1412e4240();
        FUN_1412e48a0();
    }
}

// @0x1412e6c30
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIManufactureDialog::FUN_1412e6c30(int nItemId, int nRarity, int nAmount, int nExp, int nBonus, int nJackpot, int nMerat)
{
    if (m_30.IsNull())
        return;
    Unk_MfNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return;
    MS2Ptr<Unk_UmMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (!spItem->FUN_140523c40(nItemId, nRarity, 0))
        return;
    spItem->FUN_140526c70(nAmount);
    Unk_TalkItemList aItems;
    aItems.FUN_140720b80(spItem);
    UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
    if (pTalk == 0)
        return;
    CStringW strExp(L"");
    CStringW strBonus(L"");
    if (nExp < 1)
    {
        if (nExp < 0)
        {
            int nAbs = abs(nExp);
            strExp = FUN_1408116a0(0x7c5, nAbs);
        }
    }
    else
        strExp = FUN_1408116a0(0x7c4, nExp);
    if (nBonus != 0)
    {
        if (nMerat == 0)
            strBonus = FUN_1408116a0(0x7c2, nBonus);
        else
            strBonus = FUN_140656190(L"{0} {1}", FUN_1408116a0(0x7c2, nBonus), FUN_1408116a0(0x7c3, spMaid->m_54));
    }
    pTalk->FUN_141b1b000(aItems, nJackpot == 0 ? FUN_14028de60(0x7b8) : FUN_14028de60(0x7b9), strExp, strBonus, nJackpot);
}

// @0x1412e7170
int UIManufactureDialog::FUN_1412e7170(int nResult)
{
    if (nResult == 2 || nResult == 3)
        return 1;
    return 0;
}

// The three CStringW/CString formatters are COMDATs of this unit (FMT_VARIADIC instances of FUN_14028dee0 above).

// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caf9c0-0x142cafa70 .text$yd
