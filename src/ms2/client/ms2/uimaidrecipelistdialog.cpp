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
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#define MS2_TPTRVALUE_MOVE   // the recipe book entries are copied with the add-ref ctor (0x1406889c0)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/astilelist.h"
#include "ms2/placeholder/mstime.h"
#include "uimaidrecipelistdialog.h"
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
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/commonfiles/shopcategorytable.h"
#include "ms2/commonfiles/maid.h"
#include "ms2/commonfiles/maidgradejockpottable.h"
#include "ms2/placeholder/cmanufacturemanager.h"
#include "ms2/placeholder/cusermaidmanager.h"
#include <atlcoll.h>
#include <atltime.h>
#include <shellapi.h>
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
#include "ms2/commonfiles/timeutil.h"  // C3: GetTickCountMs2
#include "ms2/ms2format.h"   // C3: StringFormat<int> (was FUN_1401ceea0)
#include "ms2/commonfiles/npcdata.h"  // C3: CNpcData (FindNpcData)

template <> MS2Ptr<ASScrollingList> UISwfEntity::GetChild<ASScrollingList>(const CString& strName);   // 0x140c02900, owned by uiinventorydialog
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class CItemData;   // C3: MS2Ptr<CItemData>::operator->
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

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
    virtual void vfunc_24(bool bInvalidate);               // 24 0x1422c80c0 validateNow
};
class ASDialog : public ASDisplayObject {};

// The tables of the maid recipes and the maid books.







class Unk_MdBookTable {};

// @0x1412db940
Unk_MdBookTable* GetMaidRecipeGroupTable() { return reinterpret_cast<Unk_MdBookTable*>(TSingleton<CMaidRecipeGroupTable>::s_instance); }
class Unk_MdLevelInfo {};    // the player's manufacture level
struct Unk_MdLevels { char m_pad[0x5180]; Unk_MdLevelInfo m_5180; };   // FUN_1401d3200(): the constant slot at +0x5180
MS2_CHECK_OFFSET(Unk_MdLevels, m_5180, 0x5180);
class Unk_SingletonObj1;   // C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())

template <typename T> CStringW FormatStringId(int nStringId, const T& arg);
template <typename T> CStringW BlockFormat(int nStringId, const T& arg);
CStringW GetStringCommon(int nStringId);
void SetChildText(const Scaleform::GFx::Value& root, CString strName, CStringW strText);

// Item records and the item bag (the key is the AS name of a bag the movie draws the icons from).
class Unk_MdItemData : public CPtred
{
public:
    CString FUN_14053fdd0();                                // the icon path
};
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
void CreateItemInfoSlot(const CString& strKey, MS2Ptr<CItem> spItem, int a, int b, int c);
void DestroyItemInfoSlot(const CString& strKey);

void FUN_14151f200();
int FUN_1418fc760(const char* szEvent, void* pArgs, int nArgs, void* a4);

// ---- the Invoke wrappers this unit owns (inline COMDATs) ----

void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned long long n);
void SetValue(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// @0x1412db770
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CString a1, unsigned __int64 a2, CString a3)
{
    ASArgList args;
    args.resize(3);
    FUN_1422bce70(&args[0], a1);
    FUN_1422bce00(&args[1], a2);
    FUN_1422bce70(&args[2], a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1412e13f0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, Scaleform::GFx::Value a2, int a3)
{
    ASArgList args;
    args.resize(3);
    SetValue(&args[0], a1);
    SetValue(&args[1], a2);
    FUN_1422bccb0(&args[2], a3);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- UIMaidRecipeListDialog -----------------------------------------------------------------------------------------

// @0x1412daa40
UIMaidRecipeListDialog::UIMaidRecipeListDialog()
    : m_178(0)
{
    SetTweenEnabled(1);
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
        DestroyItemInfoSlot(m_188[i]);
}

// @0x1412dac40
void UIMaidRecipeListDialog::FillRecipeList()
{
    if (m_30.IsNull())
        return;
    if (m_178 == 0)
        return;
    CMaidRecipeGroupTable::RecipeList spBook = reinterpret_cast<CMaidRecipeGroupTable*>(GetMaidRecipeGroupTable())->Find(m_178);
    if (spBook == 0)
        return;
    TPtrValue<MaidDesc> spInfo = TSingleton<CMaidDescTable>::GetInstance()->Find(m_178);
    if (!spInfo)
        return;
    SetChildText(FUN_1422dbc00(), CString("m_txtTitle"), FormatStringId<CStringW>(0x7c7, spInfo->specialty));
    if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_scrollList"))
    {
        spList->FUN_1422dd1d0();
        for (size_t i = 0; i < spBook->GetCount(); i++)
        {
            TPtrValue<RecipeLevel> spRef = (*spBook)[i];
            if (!spRef)
                continue;
            MS2Ptr<CMaidRecipe> spRecipe = TSingleton<CMaidRecipeTable>::GetInstance()->Find(spRef->recipeId);
            if (spRecipe.get())
            {
                ASObj row(2);
                row.FUN_140e846b0("id", i + 1);
                row.SetWStringMember("itemName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spRecipe->productItemId));
                row.SetIntMember("recipeID", spRef->recipeId);
                if (spRef->requireLevel > *reinterpret_cast<Common::Constants::Value<int>*>(&reinterpret_cast<Unk_MdLevels*>(GetClientConstants())->m_5180)->Get())   // exe: add rax, 0x5180
                    row.SetWStringMember("require", BlockFormat<int>(0x7ab, spRef->requireLevel));
                else
                    row.SetWStringMember("require", BlockFormat<int>(0x7aa, spRef->requireLevel));
                spList->AddItem(row);
                int nItemId = spRecipe->productItemId;
                int nRarity = spRecipe->productRank;
                int nAmount = spRecipe->productCount;
                MS2Ptr<CItem> spItem(new CItem());
                if (spItem->FUN_14052b130(nItemId, nRarity, 0))
                {
                    spItem->SetCountClamped(nAmount);
                    int nSlotType = 0x415;
                    CString strKey;
                    strKey.Format("%s.%d", (const char*)GetTypeName(), i + 1);
                    CreateItemInfoSlot(strKey, spItem, (int)i, nSlotType, 0x800);
                    m_30->Invoke("bind", CString(strKey), i + 1, spItem->GetIconPath());
                    m_188.Add(strKey);
                }
            }
        }
        spList->vfunc_24(true);
        spList->SetSelectedIndex(1);
    }
    m_30->Invoke("resetList");
}

// @0x1412db4c0
void UIMaidRecipeListDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FillRecipeList();
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
    if (FUN_1418fc760(szMethod, (void*)pArgs, (int)nArgs, 0) != 0)
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
            spClip->SetPositionFloat(m_17c.x, m_17c.y);
    }
    FillRecipeList();
}

// ---- UIManufactureStatus --------------------------------------------------------------------------------------------














class Unk_MdMaidOwner;

__int64 GetServerTime();                                    // the server time
// FUN_1406c47a0/4760 are CMsTime ctors (16 bytes: Init 0x1406c5270 stores the zone flag at +8); 8-byte ATL::CTime
// locals had that byte written past them (rt1 stackovf.py).
CStringW FUN_1412e1e50(ATL::CTimeSpan span, int bShort, int bSuffix);
int FUN_14028cb70(const CStringW& strText, ATL::CAtlArray<CStringW>& arrOut, const wchar_t* pszSep, int nExpected);
CStringW FUN_1401aa6a0(int nNpcId);
MS2Ptr<CNpcData> FindNpcData(int nNpcId);
UIMaidRecipeListDialog* GetMaidRecipeListDialog(int nUiId);
Scaleform::GFx::Movie* GetMovie(int nMovieId);                          // the movie of a UI layer









































// @0x1412dd760
int FUN_1412dd760(struct Unk_MdMaidItem* pItem)
{
    return reinterpret_cast<CManufacture*>(pItem)->m_3c;
}














// @0x1412dba80
UIManufactureStatus::UIManufactureStatus()
{
    m_198 = 0;
    m_19c = 0;
    SetTweenEnabled(1);
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
        DestroyItemInfoSlot(m_178[i]);
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
    if (vfunc_55() == 0 && m_30.IsNull())
    {
    }
}

// @0x1412dbd00
void UIManufactureStatus::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_30.IsNull())
        return;
    if (m_19c == 0)
        return;
    int nInterval = 1000;
    if (m_198 + nInterval > GetTickCountMs2())
        return;
    m_198 = GetTickCountMs2();
    int bWorking = 0;
    int nIndex = 0;
    CUserMaidManager::MaidMap* pList = TSingleton<CUserMaidManager>::GetInstance()->GetMaidMap();
    for (POSITION pos = pList->GetHeadPosition(); pos != 0; pList->GetNext(pos))
    {
        MS2Ptr<CMaid> spRec = pList->GetValueAt(pos);
        if (spRec.IsNull())
            continue;
        if (spRec->m_n4c <= 0)
            continue;
        int nPercent = 0;
        CStringW strRemain = L"";
        MS2Ptr<CManufacture> spItem(0);
        if (TSingleton<CManufactureManager>::GetInstance()->Lookup(spRec->m_nId, spItem) != 0)
        {
            MS2Ptr<CMaidRecipe> spRecipe = TSingleton<CMaidRecipeTable>::GetInstance()->Find(spItem->FUN_1409eedf0());
            if (spRecipe.get() != 0)
            {
                CMsTime tReady(spItem->FUN_140694170());
                CMsTime tNow(GetServerTime());
                if (tReady > tNow)
                {
                    ATL::CTimeSpan span = tReady - tNow;
                    int nTotal = FUN_1412dd760(reinterpret_cast<struct Unk_MdMaidItem*>(spItem.operator->()));
                    int nSeconds = (int)span.GetTotalSeconds();
                    if (nSeconds > 0 && nTotal > 0)
                    {
                        nPercent = 100 - (nSeconds * 100) / nTotal;
                        strRemain = FUN_1412e1e50(span, 0, 1);
                    }
                    bWorking = 1;
                }
                else
                {
                    nPercent = 100;
                    strRemain = GetStringCommon(0x7b8);
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
    if (FUN_1418fc760(szMethod, (void*)pArgs, (int)nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    else if (_stricmp("OnRecipe", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nBook = data.PopUInt();
            float fX = data.PopFloat();
            float fY = data.PopFloat();
            if (nBook > 0)
            {
                UIMaidRecipeListDialog* pList = GetMaidRecipeListDialog(0x4ecb);
                if (pList != 0)
                {
                    pList->FUN_1412db660(nBook, fX, fY);
                    if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->IsDialogOpen((eUIClassID)(0x4ecb))) != 0)
                        pList->FUN_1412db6c0();
                    else
                        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4ecb)));
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
        DestroyItemInfoSlot(pDlg->m_178[i]);
    pDlg->m_30->Invoke("destoryAll");
    pDlg->FUN_1412dc480();
}

// @0x1412dc480
void UIManufactureStatus::FUN_1412dc480()
{
    if (m_30.IsNull())
        return;
    Scaleform::GFx::Movie* pMovie = GetMovie(m_28);
    if (pMovie == 0)
        return;
    ASObj data(2);
    Scaleform::GFx::Value aMaidID;
    pMovie->CreateArray(&aMaidID);
    Scaleform::GFx::Value aMaidName;
    pMovie->CreateArray(&aMaidName);
    Scaleform::GFx::Value aState;
    pMovie->CreateArray(&aState);
    Scaleform::GFx::Value aPortrait;
    pMovie->CreateArray(&aPortrait);
    Scaleform::GFx::Value aBindID;
    pMovie->CreateArray(&aBindID);
    Scaleform::GFx::Value aItemName;
    pMovie->CreateArray(&aItemName);
    Scaleform::GFx::Value aPercent;
    pMovie->CreateArray(&aPercent);
    Scaleform::GFx::Value aRemain;
    pMovie->CreateArray(&aRemain);
    int nIndex = 0;
    int nCount = 0;
    CUserMaidManager::MaidMap* pList = TSingleton<CUserMaidManager>::GetInstance()->GetMaidMap();
    for (POSITION pos = pList->GetHeadPosition(); pos != 0; pList->GetNext(pos))
    {
        MS2Ptr<CMaid> spRec = pList->GetValueAt(pos);
        if (spRec.IsNull())
            continue;
        if (spRec->m_n4c <= 0)
            continue;
        nCount++;
        int nState = 0;
        CString strBind = "";
        CStringW strItemName = L"";
        int nPercent = 0;
        CStringW strRemain = L"";
        MS2Ptr<CManufacture> spItem(0);
        if (TSingleton<CManufactureManager>::GetInstance()->Lookup(spRec->m_nId, spItem) != 0)
        {
            nState = 2;
            MS2Ptr<CMaidRecipe> spRecipe = TSingleton<CMaidRecipeTable>::GetInstance()->Find(spItem->FUN_1409eedf0());
            if (spRecipe.get() != 0)
            {
                strItemName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spRecipe->productItemId);
                int nItemId = spRecipe->productItemId;
                int nRank = spRecipe->productRank;
                int nAmount = spRecipe->productCount;
                MS2Ptr<CItem> spItemObj(new CItem());
                if (spItemObj->FUN_14052b130(nItemId, nRank, 0))
                {
                    spItemObj->SetCountClamped(nAmount);
                    strBind.Format("ManufactureStatusPanel_.%d", nIndex + 1);
                    CreateItemInfoSlot(strBind, spItemObj, nIndex, 0x415, 0x800);
                    m_178.Add(strBind);
                }
                CMsTime tReady(spItem->FUN_140694170());
                CMsTime tNow(GetServerTime());
                if (tReady > tNow)
                {
                    ATL::CTimeSpan span = tReady - tNow;
                    int nTotal = FUN_1412dd760(reinterpret_cast<struct Unk_MdMaidItem*>(spItem.operator->()));
                    int nSeconds = (int)span.GetTotalSeconds();
                    if (nSeconds > 0 && nTotal > 0)
                    {
                        nPercent = 100 - (nSeconds * 100) / nTotal;
                        strRemain = FUN_1412e1e50(span, 0, 1);
                    }
                    m_19c = 1;
                }
                else
                {
                    nPercent = 100;
                    strRemain = GetStringCommon(0x7b8);
                }
            }
        }
        else
        {
            nState = 0;
        }
        CStringW strPortrait = L"";
        CStringW strMaidName = L"";
        TPtrValue<MaidInfo> spMaid = TSingleton<CMaidInfoTable>::GetInstance()->Find(spRec->m_nMaidId);
        if (spMaid.get() != 0)
        {
            {
                MS2Ptr<CNpcData> spNpc = FindNpcData(spMaid->npcId);
                if (spNpc.get() != 0)
                    strPortrait = spNpc->m_strPortrait;
            }
            if (spRec->FUN_1409eeda0().IsEmpty())
                strMaidName = FUN_1401aa6a0(spMaid->npcId);
            else
                strMaidName = spRec->FUN_1409eeda0();
        }
        aPortrait.PushBack(Scaleform::GFx::Value(strPortrait));
        aMaidID.PushBack(Scaleform::GFx::Value(StringFormat<int>(L"{0}", spRec->m_nMaidId)));
        aMaidName.PushBack(Scaleform::GFx::Value(strMaidName));
        aState.PushBack(Scaleform::GFx::Value(StringFormat<int>(L"{0}", nState)));
        aBindID.PushBack(Scaleform::GFx::Value(strBind));
        aItemName.PushBack(Scaleform::GFx::Value(strItemName));
        aPercent.PushBack(Scaleform::GFx::Value(StringFormat<int>(L"{0}", nPercent)));
        aRemain.PushBack(Scaleform::GFx::Value(strRemain));
        nIndex++;
    }
    data.SetMemberUInt("count", nCount);
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
        int nResult = pMsg->PopInt();
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
UIMaidRecipeListDialog* GetMaidRecipeListDialog(int nUiId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (ref.get())
            return dynamic_cast<UIMaidRecipeListDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// ---- UIMDEditDialog -------------------------------------------------------------------------------------------------

class Unk_MdItemInfo : public CItemData
{
};
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
// The string of a value (Scaleform::GFx::Value::ToString() const, sfr_gfx_01i): a const member, so this is in rcx and the
// String return slot in rdx.
struct Unk_SfValueView { Unk_SfString FUN_142576d50() const; };
// The view's name is the SDK member (always in the full link), so this unit binds it.
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:?FUN_142576d50@Unk_SfValueView@@QEBA?AVUnk_SfString@@XZ=?ToString@Value@GFx@Scaleform@@QEBA?AVString@3@XZ")
#endif
int ParseInt(const char* sz);                     // string -> number
CStringW FUN_141b71990(unsigned nItemId);                   // the number as text
CStringW FUN_141b71910(__int64 n);
// a string of the string table with an argument
CStringW GetStringCommon(unsigned nStringId);
void ShowMessageBox(CStringW strText, int nType, void* pListener, CStringW strTag);   // message box
void FUN_14151f200();
bool FUN_14083d890(CStringW str);                     // show a notice

// The AS controls the edit window binds.
class Unk_MdText : public ASTextField { public: };
class Unk_MdShopPanel : public AScript {};
MS2Ptr<AScript> FUN_1409e7dc0(int nUiId, const Scaleform::GFx::Value& v);   // the AS object of a row/dialog by the value

template <class T> struct Unk_McValue { T* FUN_1412788b0(); };   // the palette of the designer colours


int ExportMeratTables(int nMode, AScript* pData);               // export the merat tables
UIMDEditDialog* FUN_1412df350(UIMDEditDialog* p);
int FUN_1412dfc20();

// The merat table (CMeratMarketPremium) and the products as the edit tool reads them.


void FUN_1409c4990_(ASObj* p);


int LoadHomeLayout(CString strPath, int nMode, AScript* pTarget);
int FUN_1412dfe70(const CString& strMode, AScript* pTarget);
int LoadHomeLayouts(AScript* pTarget);
void FUN_1401d3700(CString& s);                             // lower-cases in place
struct Unk_MdSingleton;
CMeratMarketPremium* GetMeratMarketPremium();
CString GetXmlPath(const CString& strDir, const CString& strFile);
CString FUN_141b6e500(const CString& strDir, const char* szExt, const CString& strDefault);   // pick a file
int XmlQuery(class TiXmlElement*, char const*, unsigned int&);

// @0x1412dd900
UIMDEditDialog::UIMDEditDialog()
{
    m_180 = 0;
    m_184 = 0;
    m_188 = 0;
    m_40 = 1;
    SetTweenEnabled(1);
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
    ATL::CAtlArray<int>* pColors = reinterpret_cast<Unk_McValue<ATL::CAtlArray<int> >*>(reinterpret_cast<char*>(GetClientConstants()) + 0xb378)->FUN_1412788b0();
    for (size_t i = 0; i < pColors->GetCount(); i++)
    {
        ASObj color(2);
        unsigned nColor = (*pColors)[i];
        nColor |= 0xff000000;
        color.FUN_1409c4990("realColor", nColor);
        color.FUN_1409c4990("visibleColor", nColor);
        colors.PushValue(color.GetValue());
    }
    m_30->Invoke("initData", colors.GetValue());
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
        int nResult = pMsg->PopInt();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (nResult == 0 && strTag.Find(L"exportMerat", 0) != -1)
        {
            Scaleform::GFx::Value vExport = m_30->Invoke("getExportData");
            MS2Ptr<AScript> spData = FUN_1409e7dc0(m_28, vExport);
            if (spData.get())
            {
                FUN_1412df350(this);
                if (ExportMeratTables(m_28, &*spData) != 0)
                    RunMS2Util();
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
    Unk_MdLayoutItem();                                     // 0x1412e1630
    int m_sn;                                               // +0x00 the product sn
    int m_index;                                            // +0x04 the slot
    bool m_visible;                                         // +0x08
    bool m_category;                                        // +0x09
    bool m_editable;                                        // +0x0a
};
static int s_nHomeMode = 5;                                 // 0x1439f735c: 0 merat home, 3 designers home (5 until set)

void SetHomeMode(int nMode);
#ifndef MS2_HOOK_DLL
// @0x1412e1d20
void SetHomeMode(int nMode)
{
    s_nHomeMode = nMode;
}
#endif

// @0x1412e1630
Unk_MdLayoutItem::Unk_MdLayoutItem()
{
    m_sn = 0;
    m_index = -1;
    m_visible = false;
    m_category = false;
    m_editable = false;
}

// @0x1412df3b0
int ToInt(const CStringW& str)
{
    if (!str.IsEmpty())
        return _wtoi(str);
    return 0;
}

void LoadLayoutItem(Unk_MdLayoutItem* p, TiXmlElement* pElem);
#ifndef MS2_HOOK_DLL
// @0x1412e1bd0
void LoadLayoutItem(Unk_MdLayoutItem* p, TiXmlElement* pElem)
{
    CStringA strSn;
    XmlGetAttr((class TiXmlElement*)(pElem), "sn", strSn);
    p->m_sn = ToInt(CStringW(strSn));
    XmlGetAttr((class TiXmlElement*)(pElem), "index", reinterpret_cast<int&>(p->m_index));
    XmlGetAttr((class TiXmlElement*)(pElem), "visible", reinterpret_cast<bool&>(p->m_visible));
    XmlGetAttr((class TiXmlElement*)(pElem), "category", reinterpret_cast<bool&>(p->m_category));
    if (s_nHomeMode == 0)
        p->m_editable = p->m_index >= 10;
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
void UIMDEditDialog::RunMS2Util()
{
    ShellExecuteA(0, "open", "MS2Util.exe", 0, 0, 1);
}

// @0x1412df3f0
CString ToString(unsigned n)
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
int FillProductRow(MS2Ptr<CMeratMarketPremiumProduct> spProduct, ASObj* pRow)
{
    if (!spProduct)
        return 0;
    CMeratMarketPremiumProduct* pProduct = spProduct.get();
    pRow->SetStringMember("sn", ToString(pProduct->m_nId));
    unsigned nItemId = pProduct->m_nItemId;
    pRow->SetMemberUInt("itemID", pProduct->m_nItemId);
    pRow->SetIntMember("itemGrade", pProduct->m_nGrade);
    {
        MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
        if (item.get() != 0)
        {
            pRow->SetStringMember("iconPath", reinterpret_cast<Unk_MdItemInfo*>(item.operator->())->GetIconPath());
            pRow->SetWStringMember("itemName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
            pRow->SetIntMember("disable", 0);
        }
    }
    pRow->FUN_1409c1180("price", spProduct->GetPriceOf(0));
    pRow->FUN_1409c1180("salePrice", spProduct->GetSalePriceOf(0));
    pRow->SetIntMember("priceDay", spProduct->GetB4(0));
    pRow->SetIntMember("saleTag", pProduct->m_nSaleTag);
    pRow->SetIntMember("isBlind", 0);
    pRow->FUN_1409c0e60("seller", L"");
    pRow->SetIntMember("ugctag", 0);
    {
        ASTooltip tip(4, 2);
        if (tip.FUN_1409e1770(nItemId, pProduct->m_nGrade) != 0)
        {
            tip.SetEnablePuton(GetStringCommon(0x758));
            pRow->FUN_1409adbe0("tooltip", tip.GetValue());
        }
    }
    return 1;
}

// A row of the home layout (an empty slot when the product is unknown).
// @0x1412df8b0
int FUN_1412df8b0(ASObj* pRow, MS2Ptr<CMeratMarketPremiumProduct> spProduct, Unk_MdLayoutItem* pItem)
{
    if (spProduct.get() != 0)
    {
        FillProductRow(spProduct, pRow);
        pRow->SetBoolMember("category", pItem->m_category);
    }
    else
    {
        pRow->SetBoolMember("category", pItem->m_category);
        pRow->FUN_1409c0e60("itemName", L"");
        pRow->SetIntMember("salePrice", 0);
        pRow->SetIntMember("price", 0);
        pRow->FUN_1409c0dc0("iconPath", "");
        pRow->SetBoolMember("empty", true);
        CStringW strEmpty = L"";
        int nHome = 0;  // the merat home (3 = the designers' home)
        if (nHome == 0)
            strEmpty = L"\xad11\xace0 \xad6c\xc778\xc911(\xba54\xb7ff)";
        else if (nHome == 3)
            strEmpty = L"\xad11\xace0 \xad6c\xc778\xc911(ugc)";
        pRow->SetWStringMember("emptyText", strEmpty);
    }
    return 1;
}

// @0x1412dfbd0
int FUN_1412dfbd0()
{
    if (reinterpret_cast<Unk_MdSingleton*>(TSingleton<CShopCategoryTable>::GetInstance()) == 0)
        CShopCategoryTable::CreateInstance();
    else
        TSingleton<CShopCategoryTable>::GetInstance()->Reload(false);
    if (TSingleton<CMeratMarketPremium>::GetInstance() == 0)
        GetMeratMarketPremium();
    TSingleton<CMeratMarketPremium>::GetInstance()->Init();
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
int FUN_1412dfc40(const CString& strPath, UIMDEditDialogCommon::CShop* pShop)
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return 0;
    TiXmlElement* pRoot = (TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2");
    if (pRoot == 0)
        return 0;
    for (TiXmlElement* pItem = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("item")); pItem != 0; pItem = ((class TiXmlElement*)((class Unk_XmlNode*)(pItem))->NextSibling("item")))
    {
        bool bVisible = false;
        XmlGetAttr((class TiXmlElement*)(pItem), "visible", reinterpret_cast<bool&>(bVisible));
        if (!bVisible)
            continue;
        MS2Ptr<CMeratMarketPremiumProduct> spProduct(new CMeratMarketPremiumProduct());
        if (spProduct.get() != 0) {
            spProduct->LoadXml(pItem);
            pShop->m_products.Add(spProduct);
            pShop->m_productMap.SetAt(spProduct->m_nId, spProduct);
        }
    }
    return 1;
}

// @0x1412dfa90
int LoadHomeLayouts(AScript* pTarget)
{
    CString strPath = GetXmlPath("Table/Server", s_strMeratHomeLayout);
    LoadHomeLayout(strPath, 0, pTarget);
    strPath = GetXmlPath("Table/Server", s_strDesignersHomeLayout);
    LoadHomeLayout(strPath, 3, pTarget);
    return 1;
}

// @0x1412dfe70
int FUN_1412dfe70(const CString& strMode, AScript* pTarget)
{
    CString strPath = FUN_141b6e500("./Data/Xml/Table/Server", "xml", "");
    int nMode = 5;
    if ((strMode == "m_meratHome"))
        nMode = 0;
    else if ((strMode == "m_designersHome"))
        nMode = 3;
    if (nMode == 5)
        return 0;
    return LoadHomeLayout(strPath, nMode, pTarget);
}

// Load a home layout xml and send the rows and the categories to the movie ("buildHome").
// @0x1412dffb0
int LoadHomeLayout(CString strPath, int nMode, AScript* pTarget)
{
    if (!strPath.IsEmpty())
    {
        TiXmlDocument doc;
        if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
            return 0;
        TiXmlElement* pRoot = (TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2");
        if (pRoot == 0)
            return 0;
        CString strUnused1;                                      // two strings the exe constructs and never uses
        CString strUnused2;
        SetHomeMode(nMode);
        ASArray items(2);
        for (TiXmlElement* pItem = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("item")); pItem != 0; pItem = ((class TiXmlElement*)((class Unk_XmlNode*)(pItem))->NextSibling("item")))
        {
            Unk_MdLayoutItem entry;
            LoadLayoutItem(&entry, pItem);
            MS2Ptr<CMeratMarketPremiumProduct> spProduct(0);
            if (entry.m_sn > 0)
                spProduct = TSingleton<CMeratMarketPremium>::GetInstance()->FindProduct(entry.m_sn);
            ASObj row(2);
            FUN_1412df8b0(&row, spProduct, &entry);
            items.PushValue(row.GetValue());
        }
        ASArray categories(2);
        int nCategory = 0;
        for (TiXmlElement* pCat = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("category")); pCat != 0; pCat = ((class TiXmlElement*)((class Unk_XmlNode*)(pCat))->NextSibling("category")))
        {
            ASObj row(2);
            CStringW strName;
            XmlGetAttr((class TiXmlElement*)(pCat), "name", strName);
            ATL::CAtlArray<int> arrIndexes;
            CString strIndexes;
            XmlGetAttr((class TiXmlElement*)(pCat), "indexes", strIndexes);
            XmlSplitImpl(strIndexes, arrIndexes, ",");
            unsigned nColorIndex = 0;
            XmlQuery(reinterpret_cast<TiXmlElement*>(pCat), "colorIndex", nColorIndex);
            int nStringId = -1;
            XmlGetAttr((class TiXmlElement*)(pCat), "stringId", reinterpret_cast<int&>(nStringId));
            row.SetWStringMember("name", strName);
            ASArray indexes(2);
            for (size_t i = 0; i < arrIndexes.GetCount(); i++)
                indexes.PushInt(arrIndexes.GetAt(i));
            row.FUN_1409adbe0("indexes", indexes.GetValue());
            int nColor = 0xffffff;
            row.FUN_1409c4990("color", nColor);
            row.SetMemberUInt("colorIndex", nColorIndex);
            if (nStringId == -1)
                nStringId = nCategory;
            row.SetIntMember("stringId", nStringId);
            categories.PushValue(row.GetValue());
            nCategory++;
        }
        pTarget->Invoke("buildHome", items.GetValue(), categories.GetValue(), nMode);
        return 1;
    }
    return 0;
}

// ---- UIMDEditDialog: the shop list, the xml export ----------------------------------------------------------------------

// The AS controls of the shop list.

MS2Ptr<ASDataProvider> FUN_140ff6b60(int nMode, Scaleform::GFx::Value& v);



 // a member as text
CString FUN_1409a2360(const char* sz, int bUtf8);
CString ToCString(const char* psz, int n);

// Unit-local views of the TinyXML nodes that are written (the exe's classes are not recovered).
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view
// C3 #12: was a local TiXml view
class TiXmlDeclaration : public TiXmlNode { public: TiXmlDeclaration(const char* szVersion, const char* szEncoding, const char* szStandalone); virtual ~TiXmlDeclaration(); void* m_pad[4]; };   // C3 #12: 0x70, over the 0x50 shared TiXmlNode
class TiXmlComment : public TiXmlNode { public: TiXmlComment(const char* sz); virtual ~TiXmlComment(); };   // C3: view with the real virtual dtor; 0x50 = the shared TiXmlNode (C3 #12)
void XmlSetAttr(class TiXmlElement*, char const*, CStringW const&);
void XmlSetAttr(class TiXmlElement*, char const*, unsigned long);
void XmlSetAttr(class TiXmlElement*, char const*, bool);
void XmlSetAttr(class TiXmlElement*, char const*, int);
CString GetMeratHomeLayoutPath();                                    // the path of meratHomeLayout.xml
CString GetPremiumHomeLayoutPath();                                    // the path of premiumHomeLayout.xml
CString GetDesignersHomeLayoutPath();                                    // the path of designersHomeLayout.xml
struct Unk_MdHomeDocs;
int FUN_1406a4fc0(TiXmlDocument* pDoc, ATL::CAtlList<int>* pList);  // build the sql script from the three documents

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
int FUN_1412e06f0(CString strPath, int nMode, AScript* pData, ATL::CAtlList<int>* pSns, TiXmlDocument* pDoc)
{
    if (!strPath.IsEmpty())
    {
        Scaleform::GFx::Value vItems;
        reinterpret_cast<const Scaleform::GFx::Value*>(pData)->GetMember("itemList", &vItems);
        MS2Ptr<ASDataProvider> items = FUN_140ff6b60(nMode, vItems);
        Scaleform::GFx::Value vCategories;
        reinterpret_cast<const Scaleform::GFx::Value*>(pData)->GetMember("categoryList", &vCategories);
        MS2Ptr<ASDataProvider> categories = FUN_140ff6b60(nMode, vCategories);
        TiXmlDeclaration decl("1.0", "utf-8", "");
        reinterpret_cast<TiXmlNode*>(pDoc)->InsertEndChild(decl);
        reinterpret_cast<TiXmlNode*>(pDoc)->InsertEndChild(TiXmlComment(FUN_1409a2360("\x20\xc6\xc4\xbd\xcc\xc7\xd8\xbc\xad\x20\xbb\xe7\xbf\xeb\xc7\xcf\xb4\xc2\x20\xb5\xa5\xc0\xcc\xc5\xcd\xc0\xcc\xb4\xcf\x20\xc1\xf7\xc1\xa2\x20\xbc\xf6\xc1\xa4\xc7\xcf\xc1\xf6\x20\xb8\xb6\xbc\xbc\xbf\xe4\x20", 0)));
        {
            TiXmlElement root("ms2");
            unsigned nCount = items->GetLength();
            for (unsigned i = 0; i < nCount; i++)
            {
                AScript row = items->FUN_1422df140(i);
                TiXmlElement item("item");
                int nSn = ToInt(reinterpret_cast<AScript*>(&row)->GetWString("sn"));
                XmlSetAttr(&item, "sn", reinterpret_cast<AScript*>(&row)->GetWString("sn"));
                XmlSetAttr(&item, "index", (unsigned long)row.GetMember("index").GetUInt());
                XmlSetAttr(&item, "visible", row.GetMember("visible").GetBool());
                XmlSetAttr(&item, "category", row.GetMember("category").GetBool());
                if (pSns != 0)
                    pSns->AddTail(nSn);
                reinterpret_cast<TiXmlNode*>(&root)->InsertEndChild(item);
            }
            nCount = categories->GetLength();
            for (unsigned i = 0; i < nCount; i++)
            {
                AScript row = categories->FUN_1422df140(i);
                TiXmlElement category("category");
                Scaleform::GFx::Value vId = row.GetMember("stringId");
                int nStringId = i;
                if (!((const Scaleform::GFx::Value&)(vId)).IsUndefined())
                    nStringId = row.GetMember("stringId").GetInt();
                XmlSetAttr(&category, "stringId", nStringId);
                XmlSetAttr(&category, "name", reinterpret_cast<AScript*>(&row)->GetWString("name"));
                XmlSetAttr(&category, "indexes", reinterpret_cast<AScript*>(&row)->GetWString("indexes"));
                XmlSetAttr(&category, "colorIndex", (unsigned long)row.GetMember("colorIndex").GetUInt());
                reinterpret_cast<TiXmlNode*>(&root)->InsertEndChild(category);
            }
            reinterpret_cast<TiXmlNode*>(pDoc)->InsertEndChild(root);
        }
        return pDoc->SaveFile(ToCString(strPath, 0));
    }
    return 0;
}

// The sql script entry of one xml (a tb_game_variable row).
#include <atlfile.h>



// @0x1412e0eb0
int WriteGameVariableSql(TiXmlDocument* pNode, const CString& strName, const CString& strDesc, void* pFile)
{
    CString strFormat = "IF EXISTS (SELECT * FROM dbo.tb_game_variable WHERE s_name = \'{0}\')\rBEGIN\rUPDATE dbo.tb_game_variable\rSET s_group = {1}, s_name = \'{2}\', s_value = \'{3}\', s_desc = \'{4}\', s_use = {5}\rWHERE s_name = \'{6}\'\rEND\rELSE\rBEGIN\rINSERT INTO dbo.tb_game_variable(s_group, s_name, s_value, s_desc, s_use) VALUES({7}, \'{8}\', \'{9}\', \'{10}\', {11});\rEND\r\n\n";
    TiXmlPrinter printer;
    pNode->Accept(&printer);
    int nGroup = 1;
    CString strXml = printer.CStr();
    int nUse = 1;
    CString strSql = StringFormat<CString, int, CString, CString, CString, int, CString, int, CString, CString, CString, int>(strFormat, strName, nGroup, strName, strXml, strDesc, nUse, strName, nGroup,
                                   strName, strXml, strDesc, nUse);
    reinterpret_cast<ATL::CAtlFile*>(pFile)->Write(strSql, strSql.GetLength(), (DWORD*)0);
    return 1;
}

// Export the merat tables: write the three home xmls and show the sql.
// @0x1412e1080
int ExportMeratTables(int nMode, AScript* pData)
{
    Scaleform::GFx::Value vMerat = pData->GetMember("meratHome");
    Scaleform::GFx::Value vPremium = pData->GetMember("premiumHome");
    Scaleform::GFx::Value vDesigners = pData->GetMember("designersHome");
    Unk_MdHomeDocs docs;
    TiXmlDocument* pDocMerat = &docs.m_docMerat;
    CString strPath = GetMeratHomeLayoutPath();
    FUN_1412e06f0(strPath, nMode, reinterpret_cast<AScript*>(&vMerat), &docs.m_snsMerat, pDocMerat);
    TiXmlDocument* pDocPremium = &docs.m_docPremium;
    strPath = GetPremiumHomeLayoutPath();
    FUN_1412e06f0(strPath, nMode, reinterpret_cast<AScript*>(&vPremium), &docs.m_snsPremium, pDocPremium);
    TiXmlDocument* pDocDesigners = &docs.m_docDesigners;
    strPath = GetDesignersHomeLayoutPath();
    FUN_1412e06f0(strPath, nMode, reinterpret_cast<AScript*>(&vDesigners), 0, pDocDesigners);
    CString strSql;
    if (FUN_1406a4fc0(reinterpret_cast<TiXmlDocument*>(&strSql), reinterpret_cast<ATL::CAtlList<int>*>(&docs)) != 0)
    {
        FUN_14083d890(CStringW(strSql));
        return 1;
    }
    return 0;
}

// @0x1412dea90
void UIMDEditDialog::FUN_1412dea90(const CStringW& strSearch)
{
    MS2Ptr<Unk_MdShopPanel> spPanel = FUN_140f880c0<Unk_MdShopPanel>("m_shopItemList");
    if (!spPanel)
        return;
    MS2Ptr<ASTileList> spList = spPanel->FUN_140accef0<ASTileList>("m_itemList");
    if (!spList)
        return;
    if (MS2Ptr<ASTextField> spName = reinterpret_cast<AScript*>(spPanel.get())->FUN_1409b4620("m_name"))
        reinterpret_cast<ASTextField*>(spName.operator->())->SetTextW(m_180 == 2 ? L"\xce90\xc2dc\xc0f5" : L"\xba54\xb7ff\xc0f5");
    ATL::CAtlArray<MS2Ptr<CMeratMarketPremiumProduct> >& rProducts = m_180 == 2 ? s_shop.m_products : *TSingleton<CMeratMarketPremium>::GetInstance()->GetProducts();
    spList->Invoke("resetRenderer");
    for (size_t i = 0; i < rProducts.GetCount(); i++)
    {
        MS2Ptr<CMeratMarketPremiumProduct> spProduct = rProducts[i];
        if (spProduct.get())
        {
            if (spProduct->m_bVisible == 0)
                continue;
            unsigned nItemId = spProduct->m_nItemId;
            MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
            if (item.IsNull())
                continue;
            CStringW strLabel;
            CStringW strFormat = L"[%s] %s";
            if (reinterpret_cast<Unk_MdItemInfo*>(item.operator->())->IsCashItem())
                strLabel.Format(strFormat, L"CASH", (const wchar_t*)TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
            else if (reinterpret_cast<Unk_MdItemInfo*>(item.operator->())->HasSkinType())
                strLabel.Format(strFormat, L"SKIN", (const wchar_t*)TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
            else
                strLabel.Format(strFormat, L"GAME", (const wchar_t*)TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
            CStringW strCode = FUN_141b71990(nItemId);
            ASObj row(2);
            row.SetWStringMember("field", strLabel);
            row.SetWStringMember("code", strCode);
            row.SetMemberUInt("itemID", nItemId);
            row.FUN_1409c1180("price", spProduct->GetPriceOf(0));
            row.FUN_1409c1180("salePrice", spProduct->GetSalePriceOf(0));
            row.SetIntMember("saleTag", spProduct->m_nSaleTag);
            row.SetIntMember("priceDay", spProduct->GetB4(0));
            row.SetWStringMember("sn", FUN_141b71910(spProduct->m_nId));
            if (strSearch.IsEmpty())
                spList->AddItem(row);
            else
            {
                if (strLabel.Find(strSearch, 0) == -1)
                {
                    CStringW strId = FUN_141b71990(nItemId);
                    if (strId.Find(strSearch, 0) == -1)
                        continue;
                }
                spList->AddItem(row);
            }
        }
    }
    spList->vfunc_24(true);
}

// @0x1412ddec0
int UIMDEditDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("getItemData", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            Scaleform::GFx::Value vRow = data.PopValue();
            MS2Ptr<AScript> spObj = FUN_1409e7dc0(m_28, vRow);
            if (spObj.get())
            {
                int nSn = ToInt(spObj.operator->()->GetWString("sn"));
                unsigned nItemId = ParseInt(reinterpret_cast<const Unk_SfValueView&>(static_cast<const Scaleform::GFx::Value&>(spObj->GetMember("itemID"))).FUN_142576d50().ToCStr());
                MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
                if (item.get() != 0)
                {
                    static_cast<ASObj*>(spObj.operator->())->SetStringMember(s_strIconPath, reinterpret_cast<Unk_MdItemInfo*>(item.operator->())->GetIconPath());
                    static_cast<ASObj*>(spObj.operator->())->SetWStringMember(s_strItemName, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
                    CAtlMap<int, MS2Ptr<CMeratMarketPremiumProduct> >& rMap = m_180 == 2 ? s_shop.m_productMap : *TSingleton<CMeratMarketPremium>::GetInstance()->GetProductMap();
                    MS2Ptr<CMeratMarketPremiumProduct> spProduct(0);
                    if (rMap.Lookup(nSn, spProduct))
                    {
                        static_cast<ASObj*>(spObj.operator->())->FUN_1409c1180("salePrice", spProduct->GetSalePriceOf(0));
                        static_cast<ASObj*>(spObj.operator->())->SetIntMember("saleTag", spProduct->m_nSaleTag);
                        static_cast<ASObj*>(spObj.operator->())->FUN_1409c1180("price", spProduct->GetPriceOf(0));
                        static_cast<ASObj*>(spObj.operator->())->SetIntMember("priceDay", spProduct->GetB4(0));
                    }
                    ASTooltip tip(4, 2);
                    if (tip.FUN_1409e1770(nItemId, 0) != 0)
                        static_cast<ASObj*>(spObj.operator->())->FUN_1409adbe0("tooltip", tip.GetValue());
                }
                else
                {
                    static_cast<ASObj*>(spObj.operator->())->FUN_1409c0dc0(s_strIconPath, "");
                    static_cast<ASObj*>(spObj.operator->())->FUN_1409c0dc0(s_strItemName, "");
                    static_cast<ASObj*>(spObj.operator->())->SetIntMember("salePrice", 0);
                    static_cast<ASObj*>(spObj.operator->())->SetIntMember("saleTag", 0);
                    static_cast<ASObj*>(spObj.operator->())->SetIntMember("price", 0);
                    ASTooltip tip(4, 2);
                    static_cast<ASObj*>(spObj.operator->())->FUN_1409adbe0("tooltip", tip.GetValue());
                }
            }
        }
        return 1;
    }
    else if (_stricmp("onClickExportDBScript", szMethod) == 0)
    {
        if (m_180 == 1)
            ShowMessageBox(CStringW(L"\xc544\xb798 \xb370\xc774\xd0c0 \xd30c\xc77c\xc744 \xc0dd\xc131\xd569\xb2c8\xb2e4.\n1. \xc5d1\xc140 shop_merat.xlsx \n=> shop_merat.xml\n2. shop_merat.xml\nmeratHomeLayout.xml\npremiumHomeLayout.xml\ndesignersHomeLayout.xml\n=> merat_products.sql\n\n\xba54\xb7ff\xc0f5 \xd648\n\xd504\xb9ac\xbbf8\xc5c4\xc0f5 \xd648\n\xb514\xc790\xc774\xb108\xc2a4\xc0f5 \xd648\n\n\xc704\xc758 \xd648\xb4e4\xc744 \xbaa8\xb450 \xd3b8\xc9d1\xd55c \xd6c4\xc5d0 \xac00\xb2a5\xd569\xb2c8\xb2e4.\n\xacc4\xc18d \xd558\xc2dc\xaca0\xc2b5\xb2c8\xae4c?"), 1, static_cast<IMessageListener*>(this), CStringW(L"exportMerat"));
        else
            FUN_1412dfe60();
        return 1;
    }
    else if (_stricmp("onClickImportLayout", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0 && m_30.get())
        {
            CString strFile = data.FUN_1422b8d30();
            FUN_1412dfe70(strFile, &*m_30);
        }
        return 1;
    }
    else if (_stricmp("onClickMeratShopXml", szMethod) == 0)
    {
        if (m_30.get() && m_180 == 1)
        {
            FUN_1412df350(this);
            FUN_1412dfbd0();
        }
        return 1;
    }
    else if (_stricmp("onClickOpenMS2Util", szMethod) == 0)
    {
        RunMS2Util();
        return 1;
    }
    else if (_stricmp("onClickItemSearch", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            CStringW strSearch = data.FUN_1422b8f40();
            FUN_1412dea90(strSearch);
        }
        return 1;
    }
    else if (_stricmp("onChangeMode", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            CString strMode = data.FUN_1422b8d30();
            FUN_1401d3700(strMode);
            int nOld = m_180;
            if (strMode.Find("cash", 0) >= 0)
            {
                m_180 = 2;
                if (m_184 == 0)
                    m_184 = 1;
            }
            else
            {
                m_180 = 1;
                if ((m_30.get() ? true : false) && m_188 == 0)
                {
                    LoadHomeLayouts(&*m_30);
                    m_188 = 1;
                }
            }
            if (nOld != m_180)
                FUN_1412dea90(L"");
        }
        return 1;
    }
    else if (_stricmp("onClickToDBScript", szMethod) == 0)
        return 1;
    return 0;
}

// ---- CShop ---------------------------------------------------------------------------------------------------------------

// @0x1412e15b0
UIMDEditDialogCommon::CShop::CShop()
{
}

// @0x1412e1730 ~CShop is implicit: the exe dtor never resets the vptr.

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
CStringW FUN_1412e1e50(ATL::CTimeSpan span, int bShort, int bSuffix)
{
    int nHours = (int)span.GetTotalHours();
    int nMinutes = span.GetMinutes();
    int nSeconds = span.GetSeconds();
    CStringW strRet;
    if (bShort != 0)
    {
        CStringW strHours = L"";
        if (nHours > 0)
            strHours = FormatStringId<long>(0x7b3, reinterpret_cast<const long&>(nHours));
        CStringW strMinutes = L"";
        if (nMinutes > 0)
            strMinutes = FormatStringId<long>(0x7b4, reinterpret_cast<const long&>(nMinutes));
        CStringW strSeconds = L"";
        if (nSeconds > 0)
            strSeconds = FormatStringId<long>(0x7b5, reinterpret_cast<const long&>(nSeconds));
        strRet = strHours + strMinutes + strSeconds;
    }
    else
    {
        if (nHours == 0 && nMinutes == 0)
            strRet = FormatStringId<long>(0x7b5, reinterpret_cast<const long&>(nSeconds));
        else if (nHours == 0)
            strRet = FormatStringId<long>(0x7b4, reinterpret_cast<const long&>(nMinutes)) + L" " + FormatStringId<long>(0x7b5, reinterpret_cast<const long&>(nSeconds));
        else
            strRet = FormatStringId<long>(0x7b3, reinterpret_cast<const long&>(nHours)) + L" " + FormatStringId<long>(0x7b4, reinterpret_cast<const long&>(nMinutes)) + L" " + FormatStringId<long>(0x7b5, reinterpret_cast<const long&>(nSeconds));
    }
    if (bSuffix != 0)
        strRet = strRet + GetStringCommon(0x7b6);
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
// MS2-PIN: ?GetHeadPosition@?$CRBTree@_KV?$MS2Ptr@VCMaid@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMaid@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x1412dd700 ; C3: real map walk
// MS2-PIN: ?GetNext@?$CRBTree@_KV?$MS2Ptr@VCMaid@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMaid@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x1412dd720 ; C3: real map walk
// MS2-PIN: ?GetValueAt@?$CRBTree@_KV?$MS2Ptr@VCMaid@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMaid@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VCMaid@@@@PEAU__POSITION@@@Z 0x1412dd780 ; C3: real map walk
