// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The maid windows of the home manufacturing: the recipe list of
// a maid ("MaidRecipeListDialog", UI id 0x4ecb), the manufacture progress window ("ManufactureStatus", 0x4ec9) and the
// merat designer edit tool ("MDEditDialog", 0x4ebf, exports the merat shop tables), with the shop xml loaders they share.
// MS2-UNIT: ?\uimaidrecipelistdialog.cpp
// MS2-RANGE: 0x1412daa40-0x1412e24f0 .text$mn
// MS2-RANGE: 0x1400ee2f0-0x1400ee810 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIMaidRecipeListDialog@@UEAAHXZ 0x1412db950 ; unique
// MS2-PIN: ??_GUIManufactureStatus@@UEAAPEAXI@Z 0x1412dd6c0 ; prop
// MS2-PIN: ?vfunc_48@UIManufactureStatus@@UEAAHXZ 0x1412dd770 ; unique
// MS2-PIN: ??7?$MS2Ptr@VCMeratMarketPremiumProduct@@@@QEBA_NXZ 0x1412e1840 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCMeratMarketPremiumProduct@@@@QEBAPEAVCMeratMarketPremiumProduct@@XZ 0x1412e1890 ; unique
// MS2-PIN: ?vfunc_48@UIMDEditDialog@@UEAAHXZ 0x1412e1aa0 ; unique
// MS2-PINS-END tplpin
// File name assumed (the class name; the exe has no assert path for it).
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimaidrecipelistdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uimaidrecipelistdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/tixmlprinter.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <atlcoll.h>
#include <atltime.h>
#include <shellapi.h>

// ---- statics (.text$di in this order) -------------------------------------------------------------------------------

static CString s_aSortNamesA[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static UICommon::CMyPCKeyInputController s_keyInputA;
static CString s_aSortNamesB[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static UICommon::CMyPCKeyInputController s_keyInputB;
static CString s_strIconPath = "iconPath";
static CString s_strItemName = "itemName";
static CString s_aPremiumSortNames[] = { "None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd" };
static CString s_aSortNamesC[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static CString s_strDesignersHomeLayout = "designersHomeLayout.xml";
static CString s_strMeratHomeLayout = "meratHomeLayout.xml";
static CString s_strPremiumHomeLayout = "premiumHomeLayout.xml";
static UIMDEditDialogCommon::CShop s_shop;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_MdUiRef { public: ~Unk_MdUiRef(); private: void* m_pad; void* m_p; };    // the UI manager's handle of a dialog
class Unk_MdUiMgr
{
public:
    Unk_MdUiRef FUN_141adcea0(int nUiId);                   // find a dialog by id
    int FUN_141adc890(int nUiId);                           // is it open
    void FUN_141adc530(int nUiId);                          // open it
};
Unk_MdUiMgr* FUN_1403ed2b0();
UIObject* FUN_1403e8a70(Unk_MdUiRef* pRef);                 // the held object, 0 = none
UIObject* FUN_1403ed9e0(Unk_MdUiRef* pRef);                 // the dialog

// The 16 byte table handles (a pad and the pointer): the destructors and copies are COMDATs of other units.
template <class T> class Unk_MdPtr
{
public:
    Unk_MdPtr();
    Unk_MdPtr(const Unk_MdPtr& o);
    ~Unk_MdPtr();
    // @0x1412db890
    bool operator!() const { return m_p == 0; }
    // @0x1412db8c0
    bool operator==(T* p) const { return m_p == p; }
    T* operator->() const { return m_p; }
    T* get() const { return m_p; }
private:
    void* m_pad;
    T* m_p;
};

// The AS list control "m_scrollList" (slot 24 refreshes it).
class Unk_MdCtl : public AScript
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
class Unk_MdList : public Unk_MdCtl
{
public:
    void FUN_1422dd1d0();                                   // clear
    void FUN_1422dcca0(int n);                              // select the row
    void FUN_1422dd230(const ASObj& row);                   // append a row
};
class ASDialog : public ASDisplayObject {};

// The tables of the maid recipes and the maid books.
struct Unk_MdRecipeRef { int m_id; int m_level; };          // one entry of a maid's recipe book
class Unk_MdRecipeArr
{
public:
    size_t FUN_14068acc0() const;                           // count
    Unk_MdPtr<Unk_MdRecipeRef>& FUN_140689a50(size_t n);
};
class Unk_MdBook                                            // the recipes of a maid
{
public:
    Unk_MdRecipeArr& FUN_140689bf0();
    Unk_MdRecipeArr& FUN_140689c20();
};
class Unk_MdBookTable { public: Unk_MdPtr<Unk_MdBook> FUN_140685da0(int nBookId); };
extern Unk_MdBookTable* g_pMaidBooks;                       // the recipe books
// @0x1412db940
Unk_MdBookTable* FUN_1412db940() { return g_pMaidBooks; }
struct Unk_MdBookInfo : public CPtred                       // the book's maid
{
    char m_pad_18[8];
    CStringW m_20;                                          // title
};
class Unk_MdBookInfos { public: Unk_MdPtr<Unk_MdBookInfo> FUN_14067f780(int nBookId); };
Unk_MdBookInfos* FUN_1409eed10();
struct Unk_MdRecipe : public CPtred                         // a manufacture recipe
{
    char m_pad_18[0x38];
    int m_50;                                               // the result item id
    int m_54;                                               // the result rarity
    int m_58;                                               // the result amount
};
class Unk_MdRecipeTable { public: Unk_MdPtr<Unk_MdRecipe> FUN_1406855c0(int nRecipeId); };
Unk_MdRecipeTable* FUN_1409eed30();
struct Unk_MdLevels { char m_pad[0x5180]; int m_5180; };
class Unk_MdLevelInfo { public: int* FUN_1402056b0(); };    // the player's manufacture level
Unk_MdLevelInfo* FUN_1401d3200();

CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_1408116a0(int nStringId, const int& nArg);
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& nArg);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
struct Unk_MdStrings { CStringW FUN_141811980(int, int); };
Unk_MdStrings* FUN_1401a9d70();

// Item records and the item bag (the key is the AS name of a bag the movie draws the icons from).
class Unk_MdItemData : public CPtred
{
public:
    CString FUN_14053fdd0();                                // the icon path
};
class Unk_MdItemPtr { public: Unk_MdItemPtr(); ~Unk_MdItemPtr(); Unk_MdItemData* get() const; Unk_MdItemData* operator->() const; };
Unk_MdItemPtr FUN_14053f870(int nItemId);
void FUN_141415450(const CString& strKey, MS2Ptr<CItem> spItem, int a, int b, int c);
void FUN_141415600(const CString& strKey);
MS2Ptr<CItem> FUN_1402034d0(const MS2Ptr<CItem>& sp);
void FUN_14151f200();
int FUN_1418fc760(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, void* a4);

// ---- the Invoke wrappers this unit owns (inline COMDATs) ----

void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned long long n);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// @0x1412db770
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CString a1, unsigned __int64 a2, CString a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    FUN_1422bce00(args.FUN_1409b1f70(1), a2);
    FUN_1422bce70(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1412e13f0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, Scaleform::GFx::Value a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- UIMaidRecipeListDialog -----------------------------------------------------------------------------------------

// @0x1412daa40
UIMaidRecipeListDialog::UIMaidRecipeListDialog()
    : m_178(0)
{
    FUN_141924170(1);
}

// @0x1412daae0
UIMaidRecipeListDialog::~UIMaidRecipeListDialog()
{
}

// @0x1412dab30
CString UIMaidRecipeListDialog::GetTypeName()
{
    return CString("MaidRecipeListDialog");
}

// @0x1412dab80
int UIMaidRecipeListDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x1412dabb0
void UIMaidRecipeListDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_178 = 0;
    for (size_t i = 0; i < m_188.GetCount(); i++)
        FUN_141415600(m_188[i]);
}

// @0x1412dac40
// MS2-FUNCTIONAL: frame layout of the string temporaries and the handle copies differs
void UIMaidRecipeListDialog::FUN_1412dac40()
{
    if (m_30.IsNull() || m_178 == 0)
        return;
    Unk_MdPtr<Unk_MdBook> spBook = FUN_1412db940()->FUN_140685da0(m_178);
    if (spBook == 0)
        return;
    Unk_MdPtr<Unk_MdBookInfo> spInfo = FUN_1409eed10()->FUN_14067f780(m_178);
    if (!spInfo)
        return;
    FUN_140cfee80(FUN_1422dbc00(), CString("m_txtTitle"), FUN_14052bd00(0x7c7, spInfo->m_20));
    MS2Ptr<Unk_MdList> spList = FUN_140c02900<Unk_MdList>(CString("m_scrollList"));
    if (spList.get() != 0)
    {
        spList->FUN_1422dd1d0();
        for (size_t i = 0; i < spBook->FUN_140689bf0().FUN_14068acc0(); i++)
        {
            Unk_MdPtr<Unk_MdRecipeRef> spRef = spBook->FUN_140689c20().FUN_140689a50(i);
            if (!spRef)
                continue;
            Unk_MdPtr<Unk_MdRecipe> spRecipe = FUN_1409eed30()->FUN_1406855c0(spRef->m_id);
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
            spList->FUN_1422dd230(row);
            int nItemId = spRecipe->m_50;
            int nRarity = spRecipe->m_58;
            int nAmount = spRecipe->m_54;
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->FUN_14052b130(nItemId, nRarity, 0))
            {
                spItem->FUN_140526c70(nAmount);
                CString strKey;
                strKey.Format("%s.%d", (const char*)GetTypeName(), (int)(i + 1));
                FUN_141415450(strKey, spItem, (int)i, 0x415, 0x800);
                m_30->Invoke("bind", CString(strKey), i + 1, spItem->FUN_140528590());
                m_188.Add(strKey);
            }
        }
        spList->vfunc_24(1);
        spList->FUN_1422dcca0(1);
    }
    m_30->Invoke("resetList");
}

// @0x1412db4c0
void UIMaidRecipeListDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1412dac40();
}

// @0x1412db4f0
void UIMaidRecipeListDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_141923680(1);
}

// @0x1412db520
int UIMaidRecipeListDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
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
    return 0;
}

// @0x1412db5c0
void UIMaidRecipeListDialog::vfunc_43()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0)
        pDlg->vfunc_2(5, (int)m_17c.x, (int)m_17c.y);
}

// @0x1412db660
void UIMaidRecipeListDialog::FUN_1412db660(int nBook, float fX, float fY)
{
    m_178 = nBook;
    m_17c = efd::Point3(fX, fY, 0.0f);
}

// @0x1412db6c0
void UIMaidRecipeListDialog::FUN_1412db6c0()
{
    {
        MS2Ptr<ASMovieClip> spClip(dynamic_cast<ASMovieClip*>(static_cast<AScript*>(m_30)));
        if (spClip.get() != 0)
            spClip->FUN_1422c00f0(m_17c.x, m_17c.y);
    }
    FUN_1412dac40();
}

// ---- UIManufactureStatus --------------------------------------------------------------------------------------------

// The maids of the player: a list of records (+ the manufacture item each maid works on).
struct Unk_MdMaidRec : public CPtred
{
    CStringW FUN_1409eeda0();                               // the name the player gave the maid
    char m_pad_18[8];
    __int64 m_20;                                           // +0x20 key of the item it works on
    char m_pad_28[0xc];
    int m_34;                                               // +0x34 the maid (npc table key)
    char m_pad_38[0x14];
    int m_4c;                                               // +0x4c state
};
struct Unk_MdMaidItem : public CPtred
{
    char m_pad_18[0x24];
    int m_3c;                                               // +0x3c the manufacture time (seconds)
    int FUN_1409eedf0();                                    // the recipe id
    __int64 FUN_140694170();                                // the time it is ready
};
class Unk_MdMaidItems { public: int FUN_140d51370(__int64 nKey, MS2Ptr<Unk_MdMaidItem>& out); };
Unk_MdMaidItems* FUN_1409eed40();
class Unk_MdMaidList
{
public:
    struct Node { Node* m_pNext; MS2Ptr<Unk_MdMaidRec> m_data; };
    void* FUN_1412dd700();                                  // 0x1412dd700 head position
    void* FUN_1412dd720(void*& pos);                        // 0x1412dd720 next
    MS2Ptr<Unk_MdMaidRec>& FUN_1412dd780(void* pos);        // 0x1412dd780 the record at a position
private:
    Node* m_pHead;
};
void* FUN_14127f9a0(Unk_MdMaidList* pList, Unk_MdMaidList::Node* pNode);
void* FUN_1412807f0(Unk_MdMaidList* pList, void* pos);
class Unk_MdMaidOwner;
Unk_MdMaidOwner* FUN_1409eed60();
Unk_MdMaidList* FUN_14127eff0(Unk_MdMaidOwner* pOwner);
void FUN_140159b70(long hr);                                // AtlThrow
unsigned FUN_140869420();                                   // millisecond clock
__int64 FUN_140869440();                                    // the server time
ATL::CTime FUN_1406c47a0(__int64 nTime);
bool FUN_1406c4c60(const ATL::CTime& tReady, const ATL::CTime& tNow);   // still waiting
CStringW FUN_1412e1e50(ATL::CTimeSpan span, int bShort, int bSuffix);
int FUN_14028cb70(const CStringW& strText, ATL::CAtlArray<CStringW>& arrOut, const wchar_t* pszSep, int nExpected);
CStringW FUN_1401aa6a0(int nNpcId);
struct Unk_MdNpcData : public CPtred
{
    char m_pad_18[0x78];
    CString m_90;                                           // +0x90 the portrait
};
struct Unk_MdNpcInfo : public CPtred
{
    int m_8_;
};
class Unk_MdNpcInfos { public: Unk_MdPtr<Unk_MdNpcInfo> FUN_14067f180(int nMaidKey); };
Unk_MdNpcInfos* FUN_1409eed20();
MS2Ptr<Unk_MdNpcData> FUN_1406cd330(int nNpcId);
UIMaidRecipeListDialog* FUN_1412dd5a0(int nUiId);
void* FUN_1422bb8b0(int nMovieId);                          // the movie of a UI layer
void FUN_14256e3e0(void* pMovie, Scaleform::GFx::Value* pValue);    // movie->CreateArray

// A GFx::Value that the string-value builders construct themselves (no ctor call); the dtor is Value's (0x140614800).
struct Unk_MdValue
{
    ~Unk_MdValue();
    void* m_pInterface;                                     // +0x00
    int m_type;                                             // +0x08 6 string, 7 wide string
    const void* m_pValue;                                   // +0x10
    void* m_aux;                                            // +0x18
};
// @0x1412dd640
Unk_MdValue* FUN_1412dd640(Unk_MdValue* pOut, const char* sz)
{
    pOut->m_pInterface = 0;
    pOut->m_type = 6;
    pOut->m_pValue = sz;
    return pOut;
}
// @0x1412dd680
Unk_MdValue* FUN_1412dd680(Unk_MdValue* pOut, const wchar_t* sz)
{
    pOut->m_pInterface = 0;
    pOut->m_type = 7;
    pOut->m_pValue = sz;
    return pOut;
}
void FUN_1409f08d0(Scaleform::GFx::Value* pArray, const Unk_MdValue& v);   // push to a GFx array

// @0x1412dd700
void* Unk_MdMaidList::FUN_1412dd700()
{
    return FUN_14127f9a0(this, m_pHead);
}

// @0x1412dd720
void* Unk_MdMaidList::FUN_1412dd720(void*& pos)
{
    void* pOld = pos;
    pos = FUN_1412807f0(this, pOld);
    return pOld;
}

// @0x1412dd760
int FUN_1412dd760(Unk_MdMaidItem* pItem)
{
    return pItem->m_3c;
}

// @0x1412dd780
MS2Ptr<Unk_MdMaidRec>& Unk_MdMaidList::FUN_1412dd780(void* pos)
{
    do                                                      // ATLENSURE(pos != NULL)
    {
        int nCond = !!(pos != 0);
        do {} while (0);
        if (!nCond)
            FUN_140159b70(0x80004005);
    } while (0);
    return static_cast<Node*>(pos)->m_data;
}

// @0x1412dba80
UIManufactureStatus::UIManufactureStatus()
{
    m_198 = 0;
    m_19c = 0;
    FUN_141924170(1);
}

// @0x1412dbb10
UIManufactureStatus::~UIManufactureStatus()
{
}

// @0x1412dbb60
CString UIManufactureStatus::GetTypeName()
{
    return CString("ManufactureStatus");
}

// @0x1412dbbb0
int UIManufactureStatus::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x1412dbbe0
void UIManufactureStatus::vfunc_67()
{
    m_198 = 0;
    m_19c = 0;
    UIDialog::vfunc_67();
    for (size_t i = 0; i < m_178.GetCount(); i++)
        FUN_141415600(m_178[i]);
}

// @0x1412dbc70
void UIManufactureStatus::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1412dc480();
}

// @0x1412dbca0
void UIManufactureStatus::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (vfunc_55() == 0)
        m_30.IsNull();
}

// @0x1412dbd00
// MS2-FUNCTIONAL: frame layout of the string temporaries and the handle copies differs
void UIManufactureStatus::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_30.IsNull() || m_19c == 0)
        return;
    if (m_198 + 1000 > FUN_140869420())
        return;
    m_198 = FUN_140869420();
    bool bWorking = false;
    int nIndex = 0;
    Unk_MdMaidList* pList = FUN_14127eff0(FUN_1409eed60());
    for (void* pos = pList->FUN_1412dd700(); pos != 0; pList->FUN_1412dd720(pos))
    {
        MS2Ptr<Unk_MdMaidRec> spRec = pList->FUN_1412dd780(pos);
        if (spRec.IsNull())
            continue;
        if (spRec->m_4c < 1)
            continue;
        int nPercent = 0;
        CStringW strRemain = L"";
        MS2Ptr<Unk_MdMaidItem> spItem(0);
        if (FUN_1409eed40()->FUN_140d51370(spRec->m_20, spItem) != 0)
        {
            Unk_MdPtr<Unk_MdRecipe> spRecipe = FUN_1409eed30()->FUN_1406855c0(spItem->FUN_1409eedf0());
            if (spRecipe.get() != 0)
            {
                ATL::CTime tReady = FUN_1406c47a0(spItem->FUN_140694170());
                ATL::CTime tNow = FUN_1406c47a0(FUN_140869440());
                if (!FUN_1406c4c60(tReady, tNow))
                {
                    nPercent = 100;
                    strRemain = FUN_14028de60(0x7b8);
                }
                else
                {
                    ATL::CTimeSpan span = tReady - tNow;
                    int nTotal = FUN_1412dd760(spItem.operator->());
                    int nSeconds = (int)span.GetTotalSeconds();
                    if (nSeconds > 0 && nTotal > 0)
                    {
                        nPercent = 100 - (nSeconds * 100) / nTotal;
                        strRemain = FUN_1412e1e50(span, 0, 1);
                    }
                    bWorking = true;
                }
                m_30->Invoke("updateProgress", nIndex, nPercent, CStringW(strRemain));
            }
        }
        nIndex++;
    }
    if (!bWorking)
        m_19c = 0;
}

// @0x1412dc170
int UIManufactureStatus::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
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
    if (_stricmp("OnRecipe", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nBook = data.FUN_1422b8b10();
            float fX = data.FUN_1422b8c10();
            float fY = data.FUN_1422b8c10();
            if (nBook > 0)
            {
                UIMaidRecipeListDialog* pList = FUN_1412dd5a0(0x4ecb);
                if (pList != 0)
                {
                    pList->FUN_1412db660(nBook, fX, fY);
                    if (FUN_1403ed2b0()->FUN_141adc890(0x4ecb) == 0)
                        FUN_1403ed2b0()->FUN_141adc530(0x4ecb);
                    else
                        pList->FUN_1412db6c0();
                }
            }
        }
        return 1;
    }
    return 0;
}

// @0x1412dc340
void UIManufactureStatus::vfunc_43()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
    if (pDlg != 0)
        pDlg->vfunc_2(5, 100, 0x28);
}

// @0x1412dc3c0
void FUN_1412dc3c0(UIManufactureStatus* pDlg)
{
    if (pDlg->m_30.IsNull())
        return;
    for (size_t i = 0; i < pDlg->m_178.GetCount(); i++)
        FUN_141415600(pDlg->m_178[i]);
    pDlg->m_30->Invoke("destoryAll");
    pDlg->FUN_1412dc480();
}

// @0x1412dc480
// MS2-FUNCTIONAL: frame layout of the string temporaries and the handle copies differs
void UIManufactureStatus::FUN_1412dc480()
{
    if (m_30.IsNull())
        return;
    void* pMovie = FUN_1422bb8b0(m_28);
    if (pMovie == 0)
        return;
    ASObj data(2);
    Scaleform::GFx::Value aMaidID, aMaidName, aState, aPortrait, aBindID, aItemName, aPercent, aRemain;
    FUN_14256e3e0(pMovie, &aMaidID);
    FUN_14256e3e0(pMovie, &aMaidName);
    FUN_14256e3e0(pMovie, &aState);
    FUN_14256e3e0(pMovie, &aPortrait);
    FUN_14256e3e0(pMovie, &aBindID);
    FUN_14256e3e0(pMovie, &aItemName);
    FUN_14256e3e0(pMovie, &aPercent);
    FUN_14256e3e0(pMovie, &aRemain);
    int nIndex = 0;
    int nCount = 0;
    Unk_MdMaidList* pList = FUN_14127eff0(FUN_1409eed60());
    for (void* pos = pList->FUN_1412dd700(); pos != 0; pList->FUN_1412dd720(pos))
    {
        MS2Ptr<Unk_MdMaidRec> spRec = pList->FUN_1412dd780(pos);
        if (spRec.IsNull())
            continue;
        if (spRec->m_4c < 1)
            continue;
        nCount++;
        int nState = 0;
        CString strBind = "";
        CStringW strItemName = L"";
        int nPercent = 0;
        CStringW strRemain = L"";
        MS2Ptr<Unk_MdMaidItem> spItem(0);
        if (FUN_1409eed40()->FUN_140d51370(spRec->m_20, spItem) == 0)
        {
            nState = 0;
        }
        else
        {
            nState = 2;
            Unk_MdPtr<Unk_MdRecipe> spRecipe = FUN_1409eed30()->FUN_1406855c0(spItem->FUN_1409eedf0());
            if (spRecipe.get() != 0)
            {
                strItemName = FUN_1401a9d70()->FUN_141811980(1, spRecipe->m_50);
                MS2Ptr<CItem> spItemObj(new CItem());
                if (spItemObj->FUN_14052b130(spRecipe->m_50, spRecipe->m_58, 0))
                {
                    spItemObj->FUN_140526c70(spRecipe->m_54);
                    strBind.Format("ManufactureStatusPanel_.%d", nIndex + 1);
                    FUN_141415450(strBind, FUN_1402034d0(spItemObj), nIndex, 0x415, 0x800);
                    m_178.Add(strBind);
                }
                ATL::CTime tReady = FUN_1406c47a0(spItem->FUN_140694170());
                ATL::CTime tNow = FUN_1406c47a0(FUN_140869440());
                if (!FUN_1406c4c60(tReady, tNow))
                {
                    nPercent = 100;
                    strRemain = FUN_14028de60(0x7b8);
                }
                else
                {
                    ATL::CTimeSpan span = tReady - tNow;
                    int nTotal = FUN_1412dd760(spItem.operator->());
                    int nSeconds = (int)span.GetTotalSeconds();
                    if (nSeconds > 0 && nTotal > 0)
                    {
                        nPercent = 100 - (nSeconds * 100) / nTotal;
                        strRemain = FUN_1412e1e50(span, 0, 1);
                    }
                    m_19c = 1;
                }
            }
        }
        CStringW strPortrait = L"";
        CStringW strMaidName = L"";
        Unk_MdPtr<Unk_MdNpcInfo> spMaid = FUN_1409eed20()->FUN_14067f180(spRec->m_34);
        if (spMaid.get() != 0)
        {
            MS2Ptr<Unk_MdNpcData> spNpc = FUN_1406cd330(spMaid->m_8_);
            if (spNpc.get() != 0)
                strPortrait = spNpc->m_90;
            if (spRec->FUN_1409eeda0().IsEmpty())
                strMaidName = FUN_1401aa6a0(spMaid->m_8_);
            else
                strMaidName = spRec->FUN_1409eeda0();
        }
        Unk_MdValue v;
        FUN_1409f08d0(&aPortrait, *FUN_1412dd680(&v, strPortrait));
        FUN_1409f08d0(&aMaidID, *FUN_1412dd680(&v, FUN_1401ceea0(L"{0}", spRec->m_34)));
        FUN_1409f08d0(&aMaidName, *FUN_1412dd680(&v, strMaidName));
        FUN_1409f08d0(&aState, *FUN_1412dd680(&v, FUN_1401ceea0(L"{0}", nState)));
        FUN_1409f08d0(&aBindID, *FUN_1412dd640(&v, strBind));
        FUN_1409f08d0(&aItemName, *FUN_1412dd680(&v, strItemName));
        FUN_1409f08d0(&aPercent, *FUN_1412dd680(&v, FUN_1401ceea0(L"{0}", nPercent)));
        FUN_1409f08d0(&aRemain, *FUN_1412dd680(&v, strRemain));
        nIndex++;
    }
    data.FUN_1409c0d20("count", nCount);
    data.FUN_1409adbe0("maidID", aMaidID);
    data.FUN_1409adbe0("maidName", aMaidName);
    data.FUN_1409adbe0("state", aState);
    data.FUN_1409adbe0("portrait", aPortrait);
    data.FUN_1409adbe0("bindID", aBindID);
    data.FUN_1409adbe0("itemName", aItemName);
    data.FUN_1409adbe0("percent", aPercent);
    data.FUN_1409adbe0("remain", aRemain);
    m_30->Invoke("setData", data);
}

// @0x1412dd450
int UIManufactureStatus::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (strTag.Find(L"confirmName", 0) == 0 && nResult == 0)
        {
            ATL::CAtlArray<CStringW> arr;
            if (FUN_14028cb70(strTag, arr, L",", 2) == 0)
                return 0;
        }
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x1412dd5a0
UIMaidRecipeListDialog* FUN_1412dd5a0(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_MdUiRef ref = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (FUN_1403e8a70(&ref))
            return dynamic_cast<UIMaidRecipeListDialog*>(FUN_1403ed9e0(&ref));
    }
    return 0;
}

// ---- UIMDEditDialog -------------------------------------------------------------------------------------------------

class Unk_MdItemInfo
{
public:
    CStringA FUN_14053fdd0();                               // the icon path
    bool FUN_14053e130();                                   // a cash item
    bool FUN_14053cf90();                                   // a skin item
};
class Unk_MdItemRef
{
public:
    ~Unk_MdItemRef();                                       // 0x1401b50d0
    void* FUN_140203c60();                                  // the item data (0 = no such item)
    Unk_MdItemInfo* FUN_1401b52a0();
    bool FUN_1402ffd90();                                   // the item is hidden
private:
    void* m_pad;
    void* m_p;
};
Unk_MdItemRef FUN_14053f870(unsigned nItemId);
// Scaleform's String (a pointer to a ref counted node with two tag bits).
struct Unk_SfAtomic
{
    static int ExchangeAdd_Sync(int* p, int n);             // 0x1412e1960
    static int ExchangeAdd_NoSync(int* p, int n);           // 0x1412e1990
};
// @0x1412e1960
int Unk_SfAtomic::ExchangeAdd_Sync(int* p, int n)
{
    union { int c; int t; } u;                              // Scaleform's AtomicOps C2T_union
    u.c = n;
    u.t = ExchangeAdd_NoSync(p, u.t);
    return u.c;
}
// @0x1412e1990
int Unk_SfAtomic::ExchangeAdd_NoSync(int* p, int n)
{
    return _InterlockedExchangeAdd((long*)p, n);
}
void FUN_140a5c4c0(void* pNode);                            // free a string node
struct Unk_SfStringData
{
    void Release();                                         // 0x1412e1ab0
    unsigned __int64 m_size;                                // +0x00
    int m_nRef;                                             // +0x08
    char m_str[1];                                          // +0x0c
};
// @0x1412e1ab0
void Unk_SfStringData::Release()
{
    if ((Unk_SfAtomic::ExchangeAdd_Sync(&m_nRef, -1) - 1) == 0)
        FUN_140a5c4c0(this);
}
class Unk_SfString
{
public:
    ~Unk_SfString();                                        // 0x1412e1770
    const char* ToCStr() const;                             // 0x1412e1870
    Unk_SfStringData* GetData() const;                      // 0x1412e1a70
private:
    unsigned __int64 m_tagged;
};
// @0x1412e1a70
Unk_SfStringData* Unk_SfString::GetData() const
{
    union { Unk_SfStringData* pData; unsigned __int64 nBits; } u;   // String::DataDescUnion
    u.nBits = m_tagged;
    u.nBits = u.nBits & ~3ull;
    return u.pData;
}
// @0x1412e1770
Unk_SfString::~Unk_SfString()
{
    GetData()->Release();
}
// @0x1412e1870
const char* Unk_SfString::ToCStr() const
{
    return GetData()->m_str;
}
Unk_SfString FUN_142576d50(const Scaleform::GFx::Value& v);     // the string of a value
unsigned FUN_141b71a10(const char* sz);                     // string -> number
CStringW FUN_141b71990(unsigned nItemId);                   // the number as text
CStringW FUN_141b71910(__int64 n);
CStringW FUN_14086cfc0(unsigned nStringId, const int& nArg);
int FUN_14086d270(ATL::CTimeSpan* pSpan);                   // the minutes part   // a string of the string table with an argument
CStringW FUN_14061ad70(const CStringW& a, const wchar_t* sz);  // a + sz
CStringW FUN_1401d0080(const CStringW& a, const CStringW& b);  // a + b
CStringW FUN_14028de60(unsigned nStringId);
void FUN_140d73aa0(CStringW strText, int nType, void* pListener, CStringW strTag);   // message box
void FUN_14151f200();
int FUN_14083d890(CStringW str);                     // show a notice

// The AS controls the edit window binds.
class Unk_MdText : public AScript { public: void FUN_1422c4cd0(CStringW str); };
class Unk_MdShopList : public Unk_MdList {};
class Unk_MdShopPanel : public AScript {};
MS2Ptr<ASObj> FUN_1409e7dc0(int nUiId, Scaleform::GFx::Value v);   // the AS object of a row/dialog by the value
struct Unk_MdChildFinder { template <class T> MS2Ptr<T> FUN_1409b4620(const CString& strName); };   // text child of a panel (AScript member)
MS2Ptr<Unk_MdShopList> FUN_140accef0_(AScript* p);

struct Unk_MdColors;                                        // the palette of the designer colours
Unk_MdColors* FUN_1412788b0(void* pArray);
size_t FUN_14059d0e0(Unk_MdColors* p);
unsigned* FUN_141278750(Unk_MdColors* p, size_t i);
int FUN_1412e1080(int nMode, AScript* pData);               // export the merat tables
UIMDEditDialog* FUN_1412df350(UIMDEditDialog* p);
void FUN_1412df370();
int FUN_1412dfc20();

// The merat table (CMeratMarketPremium) and the products as the edit tool reads them.
CMeratMarketPremium* FUN_1406f2370();
bool FUN_1406ab310(CAtlMap<int, MS2Ptr<CMeratMarketPremiumProduct> >* pMap, int nId, MS2Ptr<CMeratMarketPremiumProduct>& spOut);
CAtlMap<int, MS2Ptr<CMeratMarketPremiumProduct> >* FUN_1406a3470(CMeratMarketPremium* p);
CAtlArray<MS2Ptr<CMeratMarketPremiumProduct> >* FUN_1406a3490(CMeratMarketPremium* p);
MS2Ptr<CMeratMarketPremiumProduct> FUN_1406a32d0(CMeratMarketPremium* p, int nId);
bool FUN_1409e1770(ASTooltip* pTip, unsigned nItemId, int nGrade);
void FUN_1409c69b0(ASTooltip* pTip, const CStringW& str);
void FUN_1409c4990_(ASObj* p);


int FUN_1412dffb0(CString strPath, int nMode, AScript* pTarget);
int FUN_1412dfe70(CString strMode, AScript* pTarget);
int FUN_1412dfa90(AScript* pTarget);
struct Unk_MdSingleton;
Unk_MdSingleton* FUN_1406aa4b0();
void FUN_1406a9940();
void FUN_1407cb390(Unk_MdSingleton* p, int n);
void FUN_141215500();
void FUN_1406a27b0(CMeratMarketPremium* p);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
CString FUN_141b6e500(CString strDir, const char* szExt, CString strDefault);   // pick a file
bool FUN_140184310(const CString& str, const char* sz);     // the text is sz
int FUN_1408738d0(Unk_140165cf0* pElem, const char* pszName, unsigned& nOut);

// @0x1412dd900
UIMDEditDialog::UIMDEditDialog()
{
    m_180 = 0;
    m_184 = 0;
    m_188 = 0;
    m_40 = 1;
    FUN_141924170(1);
    FUN_1422dc3b0(1);
}

// @0x1412dd9b0
UIMDEditDialog::~UIMDEditDialog()
{
}

// @0x1412dd9f0
CString UIMDEditDialog::GetTypeName()
{
    return CString("MDEditDialog");
}

// @0x1412dda40
int UIMDEditDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() != 0)
    {
        FUN_1412dfc20();
        return 1;
    }
    return 0;
}

// @0x1412dda70
void UIMDEditDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
    m_180 = 0;
    m_184 = 0;
    m_188 = 0;
}

// @0x1412ddac0
void UIMDEditDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
}

// @0x1412ddaf0
void UIMDEditDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
}

// @0x1412ddb10
void UIMDEditDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    ASArray colors(2);
    Unk_MdColors* pColors = FUN_1412788b0(reinterpret_cast<char*>(FUN_1401d3200()) + 0xb378);
    for (size_t i = 0; i < FUN_14059d0e0(pColors); i++)
    {
        ASObj color(2);
        unsigned nColor = *FUN_141278750(pColors, i);
        color.FUN_1409c4990("realColor", nColor | 0xff000000);
        color.FUN_1409c4990("visibleColor", nColor | 0xff000000);
        colors.FUN_1422bc050(color.FUN_1422bb870());
    }
    m_30->Invoke("initData", colors.FUN_1422bb870());
}

// @0x1412ddcd0
int UIMDEditDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    return 0;
}

// @0x1412ddd00
int UIMDEditDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (nResult == 0 && strTag.Find(L"exportMerat", 0) != -1)
        {
            Scaleform::GFx::Value vExport = m_30->Invoke("getExportData");
            MS2Ptr<ASObj> spData = FUN_1409e7dc0(m_28, vExport);
            if (!spData.IsNull())
            {
                FUN_1412df350(this);
                if (FUN_1412e1080(m_28, spData.get()) != 0)
                    FUN_1412df370();
            }
        }
        return 1;
    }
    return 0;
}

// ---- UIMDEditDialog: AS callbacks -----------------------------------------------------------------------------------

// The layout entry of a home xml <item> (12 bytes).
struct Unk_MdLayoutItem
{
    int m_sn;                                               // +0x00 the product sn
    int m_index;                                            // +0x04 the slot
    bool m_visible;                                         // +0x08
    bool m_category;                                        // +0x09
    bool m_editable;                                        // +0x0a
};
static int s_nHomeMode;                                     // 0 merat home, 3 designers home

void FUN_1412e1d20(int nMode);
#ifndef MS2_HOOK_DLL
// @0x1412e1d20
void FUN_1412e1d20(int nMode)
{
    s_nHomeMode = nMode;
}
#endif

// @0x1412e1630
Unk_MdLayoutItem* FUN_1412e1630(Unk_MdLayoutItem* p)
{
    p->m_sn = 0;
    p->m_index = -1;
    p->m_visible = false;
    p->m_category = false;
    p->m_editable = false;
    return p;
}

// @0x1412df3b0
int FUN_1412df3b0(const CStringW& str)
{
    if (!str.IsEmpty())
        return _wtoi(str);
    return 0;
}

void FUN_1412e1bd0(Unk_MdLayoutItem* p, Unk_140165cf0* pElem);
#ifndef MS2_HOOK_DLL
// @0x1412e1bd0
void FUN_1412e1bd0(Unk_MdLayoutItem* p, Unk_140165cf0* pElem)
{
    CStringA strSn;
    FUN_1408733e0(pElem, "sn", strSn);
    p->m_sn = FUN_1412df3b0(CStringW(strSn));
    FUN_1408731e0(pElem, "index", p->m_index);
    FUN_1408730a0(pElem, "visible", p->m_visible);
    FUN_1408730a0(pElem, "category", p->m_category);
    if (s_nHomeMode == 0)
        p->m_editable = p->m_index > 9;
    else if (s_nHomeMode == 1 || s_nHomeMode == 2)
        p->m_editable = true;
    else if (s_nHomeMode == 3)
        p->m_editable = false;
}
#endif

// @0x1412df350
UIMDEditDialog* FUN_1412df350(UIMDEditDialog* p)
{
    return p;
}

// @0x1412df370
void FUN_1412df370()
{
    ShellExecuteA(0, "open", "MS2Util.exe", 0, 0, 1);
}

// @0x1412df3f0
CString FUN_1412df3f0(unsigned n)
{
    CString str;
    str.Format("%d", n);
    return str;
}

// @0x1412df470
CString FUN_1412df470(__int64 n)
{
    CString str;
    str.Format("%I64d", n);
    return str;
}

// One row of the shop list as the movie wants it. Returns 0 when the product is gone.
// @0x1412df4f0
int FUN_1412df4f0(MS2Ptr<CMeratMarketPremiumProduct> spProduct, ASObj* pRow)
{
    if (!spProduct)
        return 0;
    CMeratMarketPremiumProduct* pProduct = spProduct.get();
    pRow->FUN_1407cba60("sn", FUN_1412df3f0(pProduct->m_nId));
    unsigned nItemId = pProduct->m_nItemId;
    pRow->FUN_1409c0d20("itemID", nItemId);
    pRow->FUN_1407cb9c0("itemGrade", pProduct->m_nGrade);
    Unk_MdItemRef item = FUN_14053f870(nItemId);
    if (item.FUN_140203c60() != 0)
    {
        pRow->FUN_1407cba60("iconPath", item.FUN_1401b52a0()->FUN_14053fdd0());
        pRow->FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, nItemId));
        pRow->FUN_1407cb9c0("disable", 0);
    }
    pRow->FUN_1409c1180("price", spProduct->GetPriceOf(0));
    pRow->FUN_1409c1180("salePrice", spProduct->GetSalePriceOf(0));
    pRow->FUN_1407cb9c0("priceDay", spProduct->GetB4(0));
    pRow->FUN_1407cb9c0("saleTag", pProduct->m_nSaleTag);
    pRow->FUN_1407cb9c0("isBlind", 0);
    pRow->FUN_1409c0e60("seller", L"");
    pRow->FUN_1407cb9c0("ugctag", 0);
    ASTooltip tip(4, 2);
    if (FUN_1409e1770(&tip, nItemId, pProduct->m_nGrade) != 0)
    {
        FUN_1409c69b0(&tip, FUN_14028de60(0x758));
        pRow->FUN_1409adbe0("tooltip", tip.FUN_1422bb870());
    }
    return 1;
}

// A row of the home layout (an empty slot when the product is unknown).
// @0x1412df8b0
int FUN_1412df8b0(ASObj* pRow, MS2Ptr<CMeratMarketPremiumProduct> spProduct, Unk_MdLayoutItem* pItem)
{
    if (spProduct.IsNull())
    {
        pRow->FUN_1407cbbe0("category", pItem->m_category);
        pRow->FUN_1409c0e60("itemName", L"");
        pRow->FUN_1407cb9c0("salePrice", 0);
        pRow->FUN_1407cb9c0("price", 0);
        pRow->FUN_1409c0dc0("iconPath", "");
        pRow->FUN_1407cbbe0("empty", true);
        CStringW strEmpty = L"";
        strEmpty = L"\xad11\xace0 \xad6c\xc778\xc911(\xba54\xb7ff)";
        pRow->FUN_1407cbb20("emptyText", strEmpty);
    }
    else
    {
        FUN_1412df4f0(spProduct, pRow);
        pRow->FUN_1407cbbe0("category", pItem->m_category);
    }
    return 1;
}

// @0x1412dfbd0
int FUN_1412dfbd0()
{
    if (FUN_1406aa4b0() == 0)
        FUN_1406a9940();
    else
        FUN_1407cb390(FUN_1406aa4b0(), 0);
    if (FUN_1406f2370() == 0)
        FUN_141215500();
    FUN_1406a27b0(FUN_1406f2370());
    return 1;
}

// @0x1412dfc20
int FUN_1412dfc20()
{
    FUN_1412dfbd0();
    return 1;
}

// @0x1412dfe60
int FUN_1412dfe60()
{
    return 0;
}

// Load a shop xml into a CShop (only the <item visible="1"> rows).
// @0x1412dfc40
int FUN_1412dfc40(CString strPath, UIMDEditDialogCommon::CShop* pShop)
{
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return 0;
    for (Unk_140165cf0* pItem = pRoot->FUN_140165cf0("item"); pItem != 0; pItem = pItem->FUN_140168650("item"))
    {
        bool bVisible = false;
        FUN_1408730a0(pItem, "visible", bVisible);
        if (!bVisible)
            continue;
        MS2Ptr<CMeratMarketPremiumProduct> spProduct(new CMeratMarketPremiumProduct());
        if (spProduct.IsNull())
            continue;
        spProduct->LoadXml(pItem);
        pShop->m_products.Add(spProduct);
        pShop->m_productMap.SetAt(spProduct->m_nId, spProduct);
    }
    return 1;
}

// @0x1412dfa90
int FUN_1412dfa90(AScript* pTarget)
{
    CString strPath = FUN_14071a5b0("Table/Server", s_strMeratHomeLayout);
    FUN_1412dffb0(strPath, 0, pTarget);
    strPath = FUN_14071a5b0("Table/Server", s_strDesignersHomeLayout);
    FUN_1412dffb0(strPath, 3, pTarget);
    return 1;
}

// @0x1412dfe70
int FUN_1412dfe70(CString strMode, AScript* pTarget)
{
    CString strPath = FUN_141b6e500("./Data/Xml/Table/Server", "xml", "");
    int nMode = 5;
    if (FUN_140184310(strMode, "m_meratHome"))
        nMode = 0;
    else if (FUN_140184310(strMode, "m_designersHome"))
        nMode = 3;
    if (nMode == 5)
        return 0;
    return FUN_1412dffb0(strPath, nMode, pTarget);
}

// Load a home layout xml and send the rows and the categories to the movie ("buildHome").
// @0x1412dffb0
int FUN_1412dffb0(CString strPath, int nMode, AScript* pTarget)
{
    if (strPath.IsEmpty())
        return 0;
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return 0;
    FUN_1412e1d20(nMode);
    ASArray items(2);
    for (Unk_140165cf0* pItem = pRoot->FUN_140165cf0("item"); pItem != 0; pItem = pItem->FUN_140168650("item"))
    {
        Unk_MdLayoutItem entry;
        FUN_1412e1630(&entry);
        FUN_1412e1bd0(&entry, pItem);
        MS2Ptr<CMeratMarketPremiumProduct> spProduct(0);
        if (entry.m_sn > 0)
            spProduct = FUN_1406a32d0(FUN_1406f2370(), entry.m_sn);
        ASObj row(2);
        FUN_1412df8b0(&row, spProduct, &entry);
        items.FUN_1422bc050(row.FUN_1422bb870());
    }
    ASArray categories(2);
    int nCategory = 0;
    for (Unk_140165cf0* pCat = pRoot->FUN_140165cf0("category"); pCat != 0; pCat = pCat->FUN_140168650("category"))
    {
        ASObj row(2);
        CStringW strName;
        FUN_140873420(pCat, "name", strName);
        ATL::CAtlArray<int> arrIndexes;
        CString strIndexes;
        FUN_1408733e0(pCat, "indexes", strIndexes);
        XmlSplit(strIndexes, arrIndexes, ",");
        unsigned nColorIndex = 0;
        FUN_1408738d0(pCat, "colorIndex", nColorIndex);
        int nStringId = -1;
        FUN_1408731e0(pCat, "stringId", nStringId);
        row.FUN_1407cbb20("name", strName);
        ASArray indexes(2);
        for (size_t i = 0; i < arrIndexes.GetCount(); i++)
            indexes.FUN_1422bbc60(arrIndexes[i]);
        row.FUN_1409adbe0("indexes", indexes.FUN_1422bb870());
        row.FUN_1409c4990("color", 0xffffff);
        row.FUN_1409c0d20("colorIndex", nColorIndex);
        if (nStringId == -1)
            nStringId = nCategory;
        row.FUN_1407cb9c0("stringId", nStringId);
        categories.FUN_1422bc050(row.FUN_1422bb870());
        nCategory++;
    }
    pTarget->Invoke("buildHome", items.FUN_1422bb870(), categories.FUN_1422bb870(), nMode);
    return 1;
}

// ---- UIMDEditDialog: the shop list, the xml export ----------------------------------------------------------------------

// The AS controls of the shop list.
struct Unk_MdAsRows { ~Unk_MdAsRows(); ASArray* FUN_140be3d00(); };     // dtor 0x140be3520
Unk_MdAsRows FUN_140ff6b60(int nMode, Scaleform::GFx::Value& v);
void FUN_1409c1770(AScript* p, const char* szName, Scaleform::GFx::Value& out);
class Unk_MdRowObj : public ASObj { public: Unk_MdRowObj(ASArray* pArr, unsigned nIndex); };     // 0x1422df140 the element as an object
struct Unk_MdMemberText { CStringW FUN_1422bb2b0(const char* szName); }; // a member as text
int FUN_1409c17e0(const Scaleform::GFx::Value& v);          // the value as int
bool FUN_1409c1720(const Scaleform::GFx::Value& v);         // the value as bool
int FUN_1409c1750(const Scaleform::GFx::Value& v);
bool FUN_1409b0390(const Scaleform::GFx::Value& v);         // the value is undefined
CString FUN_1409a2360(const char* sz, int bUtf8);
CString FUN_14016a5c0(const CString& strPath, int n);

// Unit-local views of the TinyXML nodes that are written (the exe's classes are not recovered).
struct Unk_MdXmlElement { Unk_MdXmlElement(const char* szName); ~Unk_MdXmlElement(); char m_pad[0x120]; };
struct Unk_MdXmlDeclaration { Unk_MdXmlDeclaration(const char* szVersion, const char* szEncoding, const char* szStandalone); ~Unk_MdXmlDeclaration(); char m_pad[0x90]; };
struct Unk_MdXmlComment { Unk_MdXmlComment(const char* sz); ~Unk_MdXmlComment(); char m_pad[0x70]; };
void FUN_14086e000(void* pParent, void* pChild);            // LinkEndChild
void FUN_1408740a0(Unk_MdXmlElement* p, const char* szName, const CStringW& str);
void FUN_140873dc0(Unk_MdXmlElement* p, const char* szName, int n);
void FUN_140873ca0(Unk_MdXmlElement* p, const char* szName, int n);
void FUN_140873bc0(Unk_MdXmlElement* p, const char* szName, bool b);
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* szPath);    // SaveFile
CString FUN_1406a4a00();                                    // the path of meratHomeLayout.xml
CString FUN_1406a4a70();                                    // the path of premiumHomeLayout.xml
CString FUN_1406a4ae0();                                    // the path of designersHomeLayout.xml
struct Unk_MdHomeDocs;
int FUN_1406a4fc0(CString& strOut, Unk_MdHomeDocs* pDocs);  // build the sql script from the three documents

// The three home documents and the product sns of the merat and the premium home.
struct Unk_MdHomeDocs
{
    Unk_MdHomeDocs();                                       // 0x1412e1670
    ~Unk_MdHomeDocs();                                      // 0x1412e17a0
    TiXmlDocument m_docMerat;
    ATL::CAtlList<int> m_snsMerat;
    TiXmlDocument m_docPremium;
    ATL::CAtlList<int> m_snsPremium;
    TiXmlDocument m_docDesigners;
};

// @0x1412e1670
Unk_MdHomeDocs::Unk_MdHomeDocs()
    : m_snsMerat(10), m_snsPremium(10)
{
}

// @0x1412e17a0
Unk_MdHomeDocs::~Unk_MdHomeDocs()
{
}

// Write one home xml from the movie's rows (and collect the product sns).
// @0x1412e06f0
bool FUN_1412e06f0(CString strPath, int nMode, AScript* pData, ATL::CAtlList<int>* pSns, TiXmlDocument* pDoc)
{
    if (strPath.IsEmpty())
        return false;
    Scaleform::GFx::Value vItems;
    FUN_1409c1770(pData, "itemList", vItems);
    Unk_MdAsRows items = FUN_140ff6b60(nMode, vItems);
    Scaleform::GFx::Value vCategories;
    FUN_1409c1770(pData, "categoryList", vCategories);
    Unk_MdAsRows categories = FUN_140ff6b60(nMode, vCategories);
    Unk_MdXmlDeclaration decl("1.0", "utf-8", "");
    FUN_14086e000(pDoc, &decl);
    Unk_MdXmlComment comment(FUN_1409a2360("\x20\xc6\xc4\xbd\xcc\xc7\xd8\xbc\xad\x20\xbb\xe7\xbf\xeb\xc7\xcf\xb4\xc2\x20\xb5\xa5\xc0\xcc\xc5\xcd\xc0\xcc\xb4\xcf\x20\xc1\xf7\xc1\xa2\x20\xbc\xf6\xc1\xa4\xc7\xcf\xc1\xf6\x20\xb8\xb6\xbc\xbc\xbf\xe4\x20", 0));
    FUN_14086e000(pDoc, &comment);
    Unk_MdXmlElement root("ms2");
    unsigned nItems = items.FUN_140be3d00()->FUN_1422bc5d0();
    for (unsigned i = 0; i < nItems; i++)
    {
        Unk_MdRowObj row(items.FUN_140be3d00(), i);
        Unk_MdXmlElement item("item");
        int nSn = FUN_1412df3b0(reinterpret_cast<Unk_MdMemberText*>(&row)->FUN_1422bb2b0("sn"));
        FUN_1408740a0(&item, "sn", reinterpret_cast<Unk_MdMemberText*>(&row)->FUN_1422bb2b0("sn"));
        FUN_140873dc0(&item, "index", FUN_1409c17e0(row.FUN_1422baa20("index")));
        FUN_140873bc0(&item, "visible", FUN_1409c1720(row.FUN_1422baa20("visible")));
        FUN_140873bc0(&item, "category", FUN_1409c1720(row.FUN_1422baa20("category")));
        if (pSns != 0)
            pSns->AddTail(nSn);
        FUN_14086e000(&root, &item);
    }
    unsigned nCategories = categories.FUN_140be3d00()->FUN_1422bc5d0();
    for (unsigned i = 0; i < nCategories; i++)
    {
        Unk_MdRowObj row(categories.FUN_140be3d00(), i);
        Unk_MdXmlElement category("category");
        Scaleform::GFx::Value vId = row.FUN_1422baa20("stringId");
        int nStringId = i;
        if (!FUN_1409b0390(vId))
            nStringId = FUN_1409c1750(row.FUN_1422baa20("stringId"));
        FUN_140873ca0(&category, "stringId", nStringId);
        FUN_1408740a0(&category, "name", reinterpret_cast<Unk_MdMemberText*>(&row)->FUN_1422bb2b0("name"));
        FUN_1408740a0(&category, "indexes", reinterpret_cast<Unk_MdMemberText*>(&row)->FUN_1422bb2b0("indexes"));
        FUN_140873dc0(&category, "colorIndex", FUN_1409c17e0(row.FUN_1422baa20("colorIndex")));
        FUN_14086e000(&root, &category);
    }
    FUN_14086e000(pDoc, &root);
    return FUN_1408710c0(pDoc, FUN_14016a5c0(strPath, 0));
}

// The sql script entry of one xml (a tb_game_variable row).
void FUN_140299dc0(void* pFile, const char* sz, int nLen, int n);
CString FUN_1406a7260(const char* szFormat, const CString& a0, const int& a1, const CString& a2, const CString& a3,
                      const CString& a4, const int& a5, const CString& a6, const int& a7, const CString& a8,
                      const CString& a9, const CString& a10, const int& a11);
// @0x1412e0eb0
int FUN_1412e0eb0(TiXmlDocument* pNode, const CString& strName, const CString& strDesc, void* pFile)
{
    CString strFormat = "IF EXISTS (SELECT * FROM dbo.tb_game_variable WHERE s_name = \'{0}\')\rBEGIN\rUPDATE dbo.tb_game_variable\rSET s_group = {1}, s_name = \'{2}\', s_value = \'{3}\', s_desc = \'{4}\', s_use = {5}\rWHERE s_name = \'{6}\'\rEND\rELSE\rBEGIN\rINSERT INTO dbo.tb_game_variable(s_group, s_name, s_value, s_desc, s_use) VALUES({7}, \'{8}\', \'{9}\', \'{10}\', {11});\rEND\r\n\n";
    TiXmlPrinter printer;
    pNode->Accept(&printer);
    int nGroup = 1;
    CString strXml = printer.CStr();
    int nUse = 1;
    CString strSql = FUN_1406a7260(strFormat, strName, nGroup, strName, strXml, strDesc, nUse, strName, nGroup,
                                   strName, strXml, strDesc, nUse);
    FUN_140299dc0(pFile, strSql, strSql.GetLength(), 0);
    return 1;
}

// Export the merat tables: write the three home xmls and show the sql.
// @0x1412e1080
int FUN_1412e1080(int nMode, AScript* pData)
{
    Scaleform::GFx::Value vMerat = pData->FUN_1422baa20("meratHome");
    Scaleform::GFx::Value vPremium = pData->FUN_1422baa20("premiumHome");
    Scaleform::GFx::Value vDesigners = pData->FUN_1422baa20("designersHome");
    Unk_MdHomeDocs docs;
    CString strPath = FUN_1406a4a00();
    FUN_1412e06f0(strPath, nMode, reinterpret_cast<AScript*>(&vMerat), &docs.m_snsMerat, &docs.m_docMerat);
    strPath = FUN_1406a4a70();
    FUN_1412e06f0(strPath, nMode, reinterpret_cast<AScript*>(&vPremium), &docs.m_snsPremium, &docs.m_docPremium);
    strPath = FUN_1406a4ae0();
    FUN_1412e06f0(strPath, nMode, reinterpret_cast<AScript*>(&vDesigners), 0, &docs.m_docDesigners);
    CString strSql;
    if (FUN_1406a4fc0(strSql, &docs) == 0)
        return 0;
    FUN_14083d890(CStringW(strSql));
    return 1;
}

// @0x1412dea90
void UIMDEditDialog::FUN_1412dea90(CStringW strSearch)
{
    MS2Ptr<Unk_MdShopPanel> spPanel = FUN_140f880c0<Unk_MdShopPanel>(CString("m_shopItemList"));
    if (!spPanel)
        return;
    MS2Ptr<Unk_MdShopList> spList = spPanel->FUN_140accef0<Unk_MdShopList>(CString("m_itemList"));
    if (!spList)
        return;
    MS2Ptr<Unk_MdText> spName = reinterpret_cast<Unk_MdChildFinder*>(spPanel.get())->FUN_1409b4620<Unk_MdText>(CString("m_name"));
    if (spName.get() != 0)
        spName->FUN_1422c4cd0(CStringW(m_180 == 2 ? L"\xce90\xc2dc\xc0f5" : L"\xba54\xb7ff\xc0f5"));
    ATL::CAtlArray<MS2Ptr<CMeratMarketPremiumProduct> >* pProducts;
    if (m_180 == 2)
        pProducts = &s_shop.m_products;
    else
        pProducts = FUN_1406a3490(FUN_1406f2370());
    spList->Invoke("resetRenderer");
    for (size_t i = 0; i < pProducts->GetCount(); i++)
    {
        MS2Ptr<CMeratMarketPremiumProduct> spProduct = (*pProducts)[i];
        if (spProduct.IsNull())
            continue;
        if (spProduct->m_bVisible == 0)
            continue;
        unsigned nItemId = spProduct->m_nItemId;
        Unk_MdItemRef item = FUN_14053f870(nItemId);
        if (item.FUN_1402ffd90())
            continue;
        CStringW strLabel;
        CStringW strFormat = L"[%s] %s";
        if (item.FUN_1401b52a0()->FUN_14053e130())
            strLabel.Format(strFormat, L"CASH", (const wchar_t*)FUN_1401a9d70()->FUN_141811980(1, nItemId));
        else if (item.FUN_1401b52a0()->FUN_14053cf90())
            strLabel.Format(strFormat, L"SKIN", (const wchar_t*)FUN_1401a9d70()->FUN_141811980(1, nItemId));
        else
            strLabel.Format(strFormat, L"GAME", (const wchar_t*)FUN_1401a9d70()->FUN_141811980(1, nItemId));
        CStringW strCode = FUN_141b71990(nItemId);
        ASObj row(2);
        row.FUN_1407cbb20("field", strLabel);
        row.FUN_1407cbb20("code", strCode);
        row.FUN_1409c0d20("itemID", nItemId);
        row.FUN_1409c1180("price", spProduct->GetPriceOf(0));
        row.FUN_1409c1180("salePrice", spProduct->GetSalePriceOf(0));
        row.FUN_1407cb9c0("saleTag", spProduct->m_nSaleTag);
        row.FUN_1407cb9c0("priceDay", spProduct->GetB4(0));
        row.FUN_1407cbb20("sn", FUN_141b71910(spProduct->m_nId));
        if (!strSearch.IsEmpty())
        {
            if (strLabel.Find(strSearch, 0) == -1)
            {
                CStringW strId = FUN_141b71990(nItemId);
                if (strId.Find(strSearch, 0) == -1)
                    continue;
            }
        }
        spList->FUN_1422dd230(row);
    }
    spList->vfunc_24(1);
}

// @0x1412ddec0
int UIMDEditDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("getItemData", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            MS2Ptr<ASObj> spObj = FUN_1409e7dc0(m_28, data.FUN_1422b9260());
            if (!spObj.IsNull())
            {
                int nSn = FUN_1412df3b0(reinterpret_cast<Unk_MdMemberText*>(spObj.get())->FUN_1422bb2b0("sn"));
                unsigned nItemId = FUN_141b71a10(FUN_142576d50(spObj->FUN_1422baa20("itemID")).ToCStr());
                Unk_MdItemRef item = FUN_14053f870(nItemId);
                if (item.FUN_140203c60() == 0)
                {
                    spObj->FUN_1409c0dc0(s_strIconPath, "");
                    spObj->FUN_1409c0dc0(s_strItemName, "");
                    spObj->FUN_1407cb9c0("salePrice", 0);
                    spObj->FUN_1407cb9c0("saleTag", 0);
                    spObj->FUN_1407cb9c0("price", 0);
                    ASTooltip tip(4, 2);
                    spObj->FUN_1409adbe0("tooltip", tip.FUN_1422bb870());
                }
                else
                {
                    spObj->FUN_1407cba60(s_strIconPath, item.FUN_1401b52a0()->FUN_14053fdd0());
                    spObj->FUN_1407cbb20(s_strItemName, FUN_1401a9d70()->FUN_141811980(1, nItemId));
                    CAtlMap<int, MS2Ptr<CMeratMarketPremiumProduct> >* pMap;
                    if (m_180 == 2)
                        pMap = &s_shop.m_productMap;
                    else
                        pMap = FUN_1406a3470(FUN_1406f2370());
                    MS2Ptr<CMeratMarketPremiumProduct> spProduct(0);
                    if (FUN_1406ab310(pMap, nSn, spProduct))
                    {
                        spObj->FUN_1409c1180("salePrice", spProduct->GetSalePriceOf(0));
                        spObj->FUN_1407cb9c0("saleTag", spProduct->m_nSaleTag);
                        spObj->FUN_1409c1180("price", spProduct->GetPriceOf(0));
                        spObj->FUN_1407cb9c0("priceDay", spProduct->GetB4(0));
                    }
                    ASTooltip tip(4, 2);
                    if (FUN_1409e1770(&tip, nItemId, 0) != 0)
                        spObj->FUN_1409adbe0("tooltip", tip.FUN_1422bb870());
                }
            }
        }
        return 1;
    }
    if (_stricmp("onClickExportDBScript", szMethod) == 0)
    {
        if (m_180 == 1)
            FUN_140d73aa0(CStringW(L"\xc544\xb798 \xb370\xc774\xd0c0 \xd30c\xc77c\xc744 \xc0dd\xc131\xd569\xb2c8\xb2e4.\n1. \xc5d1\xc140 shop_merat.xlsx \n=> shop_merat.xml\n2. shop_merat.xml\nmeratHomeLayout.xml\npremiumHomeLayout.xml\ndesignersHomeLayout.xml\n=> merat_products.sql\n\n\xba54\xb7ff\xc0f5 \xd648\n\xd504\xb9ac\xbbf8\xc5c4\xc0f5 \xd648\n\xb514\xc790\xc774\xb108\xc2a4\xc0f5 \xd648\n\n\xc704\xc758 \xd648\xb4e4\xc744 \xbaa8\xb450 \xd3b8\xc9d1\xd55c \xd6c4\xc5d0 \xac00\xb2a5\xd569\xb2c8\xb2e4.\n\xacc4\xc18d \xd558\xc2dc\xaca0\xc2b5\xb2c8\xae4c?"), 1, static_cast<IMessageListener*>(this), CStringW(L"exportMerat"));
        else
            FUN_1412dfe60();
        return 1;
    }
    if (_stricmp("onClickImportLayout", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0 && !m_30.IsNull())
            FUN_1412dfe70(data.FUN_1422b8d30(), m_30.get());
        return 1;
    }
    if (_stricmp("onClickMeratShopXml", szMethod) == 0)
    {
        if (!m_30.IsNull() && m_180 == 1)
        {
            FUN_1412df350(this);
            FUN_1412dfbd0();
        }
        return 1;
    }
    if (_stricmp("onClickOpenMS2Util", szMethod) == 0)
    {
        FUN_1412df370();
        return 1;
    }
    if (_stricmp("onClickItemSearch", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_1412dea90(data.FUN_1422b8f40());
        return 1;
    }
    if (_stricmp("onChangeMode", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CString strMode = data.FUN_1422b8d30();
            strMode.MakeLower();
            int nOld = m_180;
            if (strMode.Find("cash", 0) < 0)
            {
                m_180 = 1;
                if (!m_30.IsNull() && m_188 == 0)
                {
                    FUN_1412dfa90(m_30.get());
                    m_188 = 1;
                }
            }
            else
            {
                m_180 = 2;
                if (m_184 == 0)
                    m_184 = 1;
            }
            if (nOld != m_180)
                FUN_1412dea90(CStringW(L""));
        }
        return 1;
    }
    if (_stricmp("onClickToDBScript", szMethod) == 0)
        return 1;
    return 0;
}

// ---- CShop ---------------------------------------------------------------------------------------------------------------

// @0x1412e15b0
UIMDEditDialogCommon::CShop::CShop()
{
}

// @0x1412e1730
UIMDEditDialogCommon::CShop::~CShop()
{
}

// UCRT memmove_s: the static inline copies that the container glue of this unit pulled in (three of them)
// @0x1412db960
static __inline errno_t ms2_md_memmove_s_a(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0)
        return 0;
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memmove(d, s, ssz);
    return 0;
}
// @0x1412dd7e0
static __inline errno_t ms2_md_memmove_s_b(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0)
        return 0;
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memmove(d, s, ssz);
    return 0;
}
// @0x1412e1d30
static __inline errno_t ms2_md_memmove_s_c(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0)
        return 0;
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memmove(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMdMemmoveS[3])(void*, size_t, const void*, size_t) =
    { &ms2_md_memmove_s_a, &ms2_md_memmove_s_b, &ms2_md_memmove_s_c };

// The remaining time as text ("1 hour 2 min 3 sec"); bShort drops the zero parts, bSuffix appends the "left" word.
// @0x1412e1e50
// MS2-FUNCTIONAL: frame layout of the string temporaries differs
CStringW FUN_1412e1e50(ATL::CTimeSpan span, int bShort, int bSuffix)
{
    CStringW strRet;
    int nHours = (int)span.GetTotalHours();
    int nMinutes = FUN_14086d270(&span);
    int nSeconds = span.GetSeconds();
    if (bShort == 0)
    {
        if (nHours == 0 && nMinutes == 0)
            strRet = FUN_14086cfc0(0x7b5, nSeconds);
        else if (nHours == 0)
            strRet = FUN_1401d0080(FUN_14061ad70(FUN_14086cfc0(0x7b4, nMinutes), L" "), FUN_14086cfc0(0x7b5, nSeconds));
        else
            strRet = FUN_1401d0080(FUN_14061ad70(FUN_1401d0080(FUN_14061ad70(FUN_14086cfc0(0x7b3, nHours), L" "),
                                                               FUN_14086cfc0(0x7b4, nMinutes)), L" "),
                                   FUN_14086cfc0(0x7b5, nSeconds));
    }
    else
    {
        CStringW strHours = L"";
        if (nHours > 0)
            strHours = FUN_14086cfc0(0x7b3, nHours);
        CStringW strMinutes = L"";
        if (nMinutes > 0)
            strMinutes = FUN_14086cfc0(0x7b4, nMinutes);
        CStringW strSeconds = L"";
        if (nSeconds > 0)
            strSeconds = FUN_14086cfc0(0x7b5, nSeconds);
        strRet = FUN_1401d0080(FUN_1401d0080(strHours, strMinutes), strSeconds);
    }
    if (bSuffix != 0)
        strRet = FUN_1401d0080(strRet, FUN_14028de60(0x7b6));
    return strRet;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caf7d0-0x142caf7f0 .text$yd
// MS2-RANGE: 0x142caf820-0x142caf840 .text$yd
// MS2-RANGE: 0x142caf880-0x142caf8b0 .text$yd
// MS2-RANGE: 0x142caf940-0x142caf960 .text$yd
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142caf7a0-0x142caf7d0 .text$yd
// MS2-RANGE: 0x142caf7f0-0x142caf820 .text$yd
// MS2-RANGE: 0x142caf840-0x142caf880 .text$yd
// MS2-RANGE: 0x142caf8b0-0x142caf940 .text$yd
// MS2-RANGE: 0x142caf960-0x142caf9c0 .text$yd
