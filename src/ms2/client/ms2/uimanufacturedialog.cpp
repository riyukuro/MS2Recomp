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
#define MS2_TPTRVALUE_MOVE   // the recipe book entries are copied with the add-ref ctor (0x1406889c0)

#define MS2_ASUICOMPONENT_SLOTS   // ASUIComponent slot 24 (validateNow) for the "m_scrollList" refresh
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/mstime.h"

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
#include "ms2/placeholder/ascorelist.h"
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
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/maid.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/maidgradejockpottable.h"
#include "ms2/commonfiles/luautil.h"
#include "ms2/client/ms2/inventory.h"
#include <algorithm>
#include "ms2/placeholder/ascorelist.h"   // C3: ASCoreList::SetSelectedIndex
#include "uidailymissiondialog.h"   // C3: UIDailyMissionDialog::FUN_140c02900 (the "m_scrollList" getter)
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (dynamic initializers 0x1400ee810..0x1400ee9a0) ----
#ifndef MS2_HOOK_DLL
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
// A zero-initialised handle (static initialised by the ctor 0x1401cd100 on &DAT, 0).
struct Unk_UmRegMarker {};
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static void* s_dat_143ad7500;
static Unk_UmRegMarker s_init_143ad7500 = (reinterpret_cast<egf::EntityID*>(&s_dat_143ad7500)->egf::EntityID::EntityID(0), Unk_UmRegMarker());   // @0x1400ee930
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
#endif
class WorldService   // C3: view (worldservice.h adds egf::kENTITY_INVALID's dynamic initializer)
{
public:
    class Unk_WsC_GameObj* FUN_141bd1320(int id);   // C3: the real member (0x141bd1320, an object by id)
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    static class WorldService* GetInstance();
};

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObjectContainer
{
public:
    virtual void vfunc_2(int, int, int);                        // place the movie
};


// The maid npc: the maid record (placeholder/cnpc.h).
class CNpc { public: MS2Ptr<CMaid> FUN_141093800(); };

enum SAType;   // C3: the special ability type (commonfiles/additionalactionadditional.h)
// The local player (only its stats).
#include "ms2/client/ms2/equipment.h"   // CEquipment (was a local member view)
class Unk_UmPC { public: };
class PC { public: struct Unk_PCEquipSet* FUN_1416561a0(); };   // C3: the real member (0x1416561a0, the equip holder)

class Unk_MdBookTable* FUN_1412db940();   // C3: was FUN_1412db940

// The record of a running craft.
struct Unk_UmMfItem : public CPtred
{
    char m_pad_18[0x3c - 0x18];
    int m_3c;                                                   // +0x3c the manufacture time (seconds)
};

// The string table and the client constants.
class Unk_UmLevelInfo { public: };        // the player's manufacture level
struct Unk_UmLevels { char m_pad[0x5180]; Unk_UmLevelInfo m_5180; };   // FUN_1401d3200(): the constant slot at +0x5180
MS2_CHECK_OFFSET(Unk_UmLevels, m_5180, 0x5180);
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

template <class A> CStringW FormatStringId(int nId, const A& a);
#include "ms2/placeholder/blockformat.h"   // C3: BlockFormat<...> over FUN_14028dee0 by its real name (was BlockFormat(int, const ArgList&))
CStringW GetStringCommon(int nStringId);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
template <class A, class B> CStringW FormatStringId(int nId, const A& a, const B& b);
int FUN_14053feb0(int nItemId);                                 // default rarity of an item
    // the experience of one affinity grade
void* FUN_1401c0d90();
__int64 GetServerTime();                                        // the server time
// FUN_1406c47a0/4760 are CMsTime ctors (16 bytes: Init 0x1406c5270 stores the zone flag at +8); 8-byte ATL::CTime
// locals had that byte written past them (rt1 stackovf.py).
CStringW FUN_1412e1e50(ATL::CTimeSpan span, int bShort, int bSuffix);
CStringW FUN_1418fec90(int nCurrency, __int64 nAmount, int nArg);
class Unk_BmPriceMgr* FUN_1401c0db0();   // C3: was FUN_1401c0db0
class Unk_140166410* FUN_140166410();
class CInputKeyHandler   // C3: member view for the former free stand-ins
{
public:
    bool IsDebugMode();
};
void* FUN_14025e7c0();                                          // the client's text-hook object
int FUN_1412dd760(struct Unk_MdMaidItem*);   // C3: was FUN_1412dd760
void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW strTag);   // pop the system message
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_141415450(const CString& strKey, MS2Ptr<CItem> spItem, int a, int b, int c);
void FUN_141415600(const CString& strKey);
void FUN_14151f200();
int FUN_1418fc760(const char* szMethod, void* pArgs, int nArgs, void* p);
UITalkCinematic* FUN_140a7b2b0(int nId);                        // a dialog by UI id

// The player's inventory (owned counts) and the account id.
// The cube map service (cubemapinformationservice_3.h; its include adds egf::kENTITY_INVALID's dynamic initializer).
class CubeMapInformationService : public efd::ISystemService { public: int FUN_1410d2fb0(__int64 nOwnerId, int nCategory, int* pnCount); };
class Unk_MfCubeService : public CubeMapInformationService { };
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
//
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 egf::g_bapiContext
extern Unk_Inventory g_143ab2a90;   // C3: the real global (0x143ab2a90)
extern __int64 DAT_143ab2820;

// The wallet check of the network callbacks object (slots 40 / 41: the player can pay the amount with meso / merat).
class Unk_UmWallet
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual bool vfunc_40(__int64 nAmount);
    virtual bool vfunc_41(__int64 nAmount);
};
void* FUN_140d86260();   // ms2actormanager.cpp: the client platform


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
CString UIManufactureDialog::GetTypeName()
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
int UIManufactureDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    else if (_stricmp("OnSelectedList", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            m_nSelected = data.PopInt();
            FUN_1412e5c90();
        }
        return 1;
    }
    else if (_stricmp("OnCraft", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nIndex = data.PopInt();
            FUN_1412e5dd0(nIndex);
        }
        return 1;
    }
    else if (_stricmp("OnCraftAdmin", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nIndex = data.PopInt();
            FUN_1412e5f70(nIndex);
        }
        return 1;
    }
    else if (_stricmp("onRecieve", szMethod) == 0)
    {
        OnRecieve();
        return 1;
    }
    else if (_stricmp("onRecieveOrCancel", szMethod) == 0)
    {
        if (m_nState == 2)
            OnRecieve();
        else if (m_nState == 1)
            FUN_140d73bc0(0x7b7, 1, static_cast<IMessageListener*>(this), CStringW(L"OnCancel"));
    }
    else if (_stricmp("onRecieveByMerat", szMethod) == 0)
    {
        OnRecieveByMerat();
        return 1;
    }
    else if (_stricmp("onRecieveJackpot", szMethod) == 0)
    {
        OnRecieveJackpot();
        return 1;
    }
    return 0;
}

// @0x1412e2cf0
int UIManufactureDialog::vfunc_13()
{
    if (vfunc_55() != 0)
        return 0;
    return 0;
}

// @0x1412e2d30
void UIManufactureDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    UITalkCinematic* pRef;
    if (pDialog != 0 && (pRef = FUN_140a7b2b0(0x4e40)) != 0)
    {
        int nX = pRef->GetLowerCutGlobalY();
        int nY = pRef->GetIllustGlobalX() - 0x14;
        if (nX != -1 && nY != -1)
        {
            pDialog->vfunc_2(5, nY, nX - pDialog->GetHeightCeil() - 2);
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
        int nResult = pMsg->PopInt();
        CStringW strTag = pMsg->FUN_1422b8f40();
        ATL::CAtlArray<CStringW> kArr;
        FUN_14151f200();
        if (nResult == 0 && strTag == L"OnCancel")
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
void UIManufactureDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_30.IsNull())
        return;
    if (m_nState != 1)
        return;
    int nInterval = 1000;
    if (m_nLastTick + nInterval > GetTickCountMs2())
        return;
    m_nLastTick = GetTickCountMs2();
    MS2Ptr<Unk_UmMfItem> spItem(0);
    if (TSingleton<CManufactureManager>::GetInstance()->Lookup(m_nManufactureId, reinterpret_cast<MS2Ptr<CManufacture>&>(spItem)) == 0)
        return;
    CMsTime tReady(reinterpret_cast<CManufacture*>(spItem.operator->())->FUN_140694170());
    CMsTime tNow(GetServerTime());
    ATL::CTimeSpan span = tReady - tNow;
    if (tReady > tNow)
    {
        int nLeft = ((class CLua*)FUN_1401c0db0())->CalcManufactureCompleteByMerat(span.GetTotalSeconds());
        int nCurrency = 3;
        if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d710(0x102))
            nCurrency = 10;
        m_30->Invoke("setItemMeratLabel", FormatStringId<CStringW>(0x7ba, FUN_1418fec90(nCurrency, (__int64)nLeft, 0)));
        int nTotal = FUN_1412dd760((struct Unk_MdMaidItem*)(spItem.operator->()));
        int nRemain = span.GetTotalSeconds();
        int nPermille = 0;
        if (0 < nTotal)
            nPermille = 1000 - (nRemain * 1000) / nTotal;
        CStringW strTime = FUN_1412e1e50(span, 0, 1);
        m_30->Invoke("updateProgressGauge", strTime, nPermille);
    }
    else
    {
        m_nState = 2;
        m_30->Invoke("setProgress", m_nState, ((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->IsDebugMode());
        m_30->Invoke("updateProgressGauge", GetStringCommon(0x7b8), 1000);
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
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    TPtrValue<MaidDesc> spDesc = TSingleton<CMaidDescTable>::GetInstance()->Find(spMaid->m_nMaidId);
    if (!spDesc)
        return;
    CStringW strName = FormatStringId<CStringW>(0x7af, spDesc->specialty);
    CStringW strMood;
    if (reinterpret_cast<CMaid*>(spMaid.operator->())->GetMoodGrade() == 0)
        strMood = GetStringCommon(0x79f);
    else if (reinterpret_cast<CMaid*>(spMaid.operator->())->GetMoodGrade() == 1)
        strMood = GetStringCommon(0x7a0);
    else
        strMood = GetStringCommon(0x7a1);
    CStringW strGrade = FormatStringId<CStringW, int>(0x7b0, strMood, spMaid->m_nOrder);
    int nNeed = TSingleton<CMaidExpTable>::GetInstance()->GetExp(spMaid->m_nOrder);
    int nOne = 1;
    int nMax = std::max<int>(nOne, nNeed);
    CStringW strExp = FUN_14028dee0(0x7b1, spMaid->m_nMood, spMaid->m_nExp, nMax);
    if (reinterpret_cast<CMaid*>(spMaid.operator->())->IsAffinityLevelAtMax() != 0)
        strExp = BlockFormat<int>(0x7b2, spMaid->m_nMood);
    m_30->FUN_1412e80d0("setTitle", CStringW(strName), CStringW(strGrade), CStringW(strExp));
}

// @0x1412e3990
void UIManufactureDialog::FUN_1412e3990(int bSelect)
{
    if (m_30.IsNull())
        return;
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    CMaidRecipeGroupTable::RecipeList spBook = ((class CMaidRecipeGroupTable*)FUN_1412db940())->Find(spMaid->m_nMaidId);
    if (spBook == 0)
        return;
    if (MS2Ptr<ASScrollingList> spList = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02900("m_scrollList"))   // the list getter of UIDailyMissionDialog
    {
        spList->FUN_1422dd1d0();
        int nFirst = 0;
        for (size_t i = 0; i < spBook->GetCount(); i++)
        {
            TPtrValue<RecipeLevel> spRef = (*spBook)[i];
            if (!spRef)
                continue;
            MS2Ptr<CMaidRecipe> spRecipe = TSingleton<CMaidRecipeTable>::GetInstance()->Find(spRef->recipeId);
            if (spRecipe.get() != 0)
            {
                ASObj row(2);
                row.FUN_140e846b0("id", i + 1);
                row.FUN_1407cbb20("itemName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spRecipe->productItemId));
                row.FUN_1407cb9c0("recipeID", spRef->recipeId);
                if (spRef->requireLevel > *reinterpret_cast<Common::Constants::Value<int>*>(&reinterpret_cast<Unk_UmLevels*>(((class Unk_UmLevelInfo*)FUN_1401d3200()))->m_5180)->Get())   // exe: add rax, 0x5180
                    row.FUN_1407cbb20("require", BlockFormat<int>(0x7ab, spRef->requireLevel));
                else
                    row.FUN_1407cbb20("require", BlockFormat<int>(0x7aa, spRef->requireLevel));
                m_mapRecipes.SetAt((int)i, spRef->recipeId);
                int bAvailable = spRef->requireLevel <= spMaid->m_nOrder;
                if (bAvailable != 0)
                    nFirst = (int)i;
                row.FUN_1407cb9c0("available", bAvailable);
                spList.get()->AddItem(row);
                int nItemId = spRecipe->productItemId;
                int nRarity = spRecipe->productRank;
                int nAmount = spRecipe->productCount;
                MS2Ptr<CItem> spItem(new CItem());
                if (spItem->FUN_14052b130(nItemId, nRarity, 0))
                {
                    spItem->SetCountClamped(nAmount);
                    int nFlags = 0;
                    if (bAvailable != 0)
                        nFlags = 0x415;
                    else
                        nFlags = 0x2415;
                    CString strKey;
                    strKey.Format("%s.%d", (const char*)GetTypeName(), i + 1);
                    FUN_141415450(strKey, spItem, (int)i, nFlags, 0x800);
                    m_30->Invoke("bind", CString(strKey), i + 1, spItem->FUN_140528590());
                    m_aRowKeys.Add(strKey);
                }
            }
        }
        spList->vfunc_24(true);
        if (bSelect != 0)
        {
            spList->SetSelectedIndex(nFirst);
            m_nSelected = nFirst;
            FUN_1412e48a0();
        }
    }
}

// @0x1412e4240
void UIManufactureDialog::FUN_1412e4240()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<Unk_UmMfItem> spMf(0);
    if (TSingleton<CManufactureManager>::GetInstance()->Lookup(m_nManufactureId, reinterpret_cast<MS2Ptr<CManufacture>&>(spMf)) != 0)
    {
        MS2Ptr<CMaidRecipe> spRecipe = TSingleton<CMaidRecipeTable>::GetInstance()->Find(reinterpret_cast<CManufacture*>(spMf.operator->())->FUN_1409eedf0());
        if (spRecipe.get() != 0)
        {
            CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spRecipe->productItemId);
            int nItemId = spRecipe->productItemId;
            int nRarity = spRecipe->productRank;
            int nAmount = spRecipe->productCount;
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->FUN_14052b130(nItemId, nRarity, 0))
            {
                spItem->SetCountClamped(nAmount);
                m_strProgressKey.Format("%s_prgress", (const char*)GetTypeName());
                FUN_141415600(m_strProgressKey);
                FUN_141415450(m_strProgressKey, spItem, 0, 0x415, 0x800);
                m_30->FUN_140c38f00("bindProgress", CString(m_strProgressKey), CStringW(strName));
            }
            CMsTime tReady(reinterpret_cast<CManufacture*>(spMf.operator->())->FUN_140694170());
            CMsTime tNow(GetServerTime());
            ATL::CTimeSpan span = tReady - tNow;
            int nLeft = ((class CLua*)FUN_1401c0db0())->CalcManufactureCompleteByMerat(span.GetTotalSeconds());
            int nCurrency = 3;
            if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d710(0x102))
                nCurrency = 10;
            m_30->Invoke("setItemMeratLabel", FormatStringId<CStringW>(0x7ba, FUN_1418fec90(nCurrency, (__int64)nLeft, 0)));
            if (tReady > tNow)
                m_nState = 1;
            else
                m_nState = 2;
        }
        else
            m_nState = 0;
    }
    else
        m_nState = 0;
    m_30->Invoke("setProgress", m_nState, ((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->IsDebugMode());
    m_30->Invoke("updateProgressGauge", GetStringCommon(0x7b8), 1000);
}

// @0x1412e48a0
void UIManufactureDialog::FUN_1412e48a0()
{
    if (m_30.IsNull())
        return;
    Unk_UmPC* pPlayer = ((Unk_UmPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nRecipeId = 0;
    if (!m_mapRecipes.Lookup(m_nSelected, nRecipeId))
        return;
    MS2Ptr<CMaidRecipe> spRecipe = TSingleton<CMaidRecipeTable>::GetInstance()->Find(nRecipeId);
    if (spRecipe.get() != 0)
    {
        int nGrade = 0;
        if (((class CMaidRecipeGroupTable*)FUN_1412db940())->GetRequireLevel(spMaid->m_nMaidId, nRecipeId, nGrade) == 0)
            return;
        int bAvailable = 1;
        if (nGrade > spMaid->m_nOrder)
            bAvailable = 0;
        if (m_nState != 0)
            bAvailable = 0;
        unsigned nMeso = ((CGameRule*)FUN_1401c0d90())->FUN_14047b7c0(reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPlayer)->FUN_1416561a0())->GetAbilityRate((SAType)0x3e), spRecipe->maidExp);
        CStringW strGrade = BlockFormat<int>(0x7aa, nGrade);
        CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spRecipe->productItemId);
        ATL::CTimeSpan span((unsigned __int64)spRecipe->leadTimes[reinterpret_cast<CMaid*>(spMaid.operator->())->GetMoodGrade()]);
        CStringW strTime = FUN_1412e1e50(span, 1, 0);
        CStringW strCost = FUN_14028dee0(0x7ac, strTime, nMeso);
        m_30->Invoke("selectItem", m_nSelected, CStringW(strName), CStringW(strGrade), CStringW(strCost), bAvailable, ((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->IsDebugMode());
        int nItemId = spRecipe->productItemId;
        int nRarity = spRecipe->productRank;
        int nAmount = spRecipe->productCount;
        MS2Ptr<CItem> spProduct(new CItem());
        if (spProduct->FUN_14052b130(nItemId, nRarity, 0))
        {
            spProduct->SetCountClamped(nAmount);
            m_strProductKey.Format("%s_product", (const char*)GetTypeName());
            FUN_141415450(m_strProductKey, spProduct, 0, 0x415, 0x800);
            m_30->Invoke("bindProduct", CString(m_strProductKey));
        }
        for (size_t i = 0; i < m_aIngredientKeys.GetCount(); i++)
            FUN_141415600(m_aIngredientKeys[i]);
        std::vector<CStringW> aUnused;
        for (size_t k = 0; k < spRecipe->ingredients.size(); k++)
        {
            TPtrValue<MaidIngredient> spIngredient = spRecipe->ingredients[k];
            if (!spIngredient)
                continue;
            int nIngItem = spIngredient->GetItemId();
            int nGroup = spIngredient->GetItemStringId();
            MS2Ptr<CItemData> spData = FUN_14053f870(nIngItem);
            if (spData == 0)
                continue;
            int nIngRarity = spData->FUN_14053cbc0() ? spIngredient->field04 : FUN_14053feb0(nIngItem);
            unsigned nNeeded = ((CGameRule*)FUN_1401c0d90())->FUN_14047b860(reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPlayer)->FUN_1416561a0())->GetAbilityRate((SAType)0x3f), spIngredient->count);
            MS2Ptr<CItem> spIngItem(new CItem());
            if (spIngItem->FUN_14052b130(nIngItem, nIngRarity, 0))
            {
                spIngItem->SetCountClamped(nNeeded);
                CString strKey;
                strKey.Format("%s_Ingredient.%d", (const char*)GetTypeName(), k + 1);
                FUN_141415450(strKey, spIngItem, (int)k, 0x415, 0x800);
                m_aIngredientKeys.Add(strKey);
                unsigned nHave = 0;
                if (nGroup == 0)
                    nHave = g_143ab2a90.FUN_140a5f180(nIngItem, 0);
                else
                    nHave = g_143ab2a90.FUN_140a5f780(nGroup, 0);
                CStringW strBreak(L"");
                if (nHave >= 10000 || (nHave >= 1000 && nNeeded >= 100))
                    strBreak = L"\n";
                CStringW strCount(L"");
                if (nHave >= nNeeded)
                    strCount = FUN_14028dee0(0x7ad, nHave, strBreak, nNeeded);
                else
                    strCount = FUN_14028dee0(0x7ae, nHave, strBreak, nNeeded);
                m_30->Invoke("ingredients", (unsigned __int64)(k + 1), CString(strKey), CStringW(strCount));
            }
        }
        if (spRecipe->workbenchType > 0)
        {
            int nRow = (int)(spRecipe->ingredients.size() + 1);
            int nMesoCost = spRecipe->workbenchType;
            int nCode = 0;
            efd::SmartPointer<Unk_MfCubeService> spService(((class Unk_MfCubeService*)egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>()));
            int nResult = spService->FUN_1410d2fb0(DAT_143ab2820, nMesoCost, &nCode);
            CStringW strMesoText(L"");
            if (nMesoCost == 0x1c)
                strMesoText = nResult != 0 ? GetStringCommon(0x7bb) : GetStringCommon(0x7bc);
            else if (nMesoCost == 0x1d)
                strMesoText = nResult != 0 ? GetStringCommon(0x7bd) : GetStringCommon(0x7be);
            else if (nMesoCost == 0x1e)
                strMesoText = nResult != 0 ? GetStringCommon(0x7bf) : GetStringCommon(0x7c0);
            CStringW strMesoCount(L"");
            if (nResult != 0)
            {
                int nOne = 1;
                strMesoCount = FUN_14028dee0_wc(0x7ad, nCode, L"", nOne);
            }
            else
            {
                int nOne = 1;
                strMesoCount = FUN_14028dee0_wc(0x7ae, nCode, L"", nOne);
            }
            m_30->Invoke("workbench", nRow, CStringW(strMesoCount), CStringW(strMesoText));
        }
    }
}

// @0x1412e5c90
void UIManufactureDialog::FUN_1412e5c90()
{
    if (m_30.IsNull())
        return;
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    FUN_1412e48a0();
    CStringW strText = CManufactureManager::GetInstance()->GetMaidText(0, reinterpret_cast<Unk_MfNpc*>(pNpc));
    UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
    if (pTalk != 0)
        pTalk->FUN_141b1a8e0(strText, "", "");
}

// @0x1412e5dd0
void UIManufactureDialog::FUN_1412e5dd0(int nRow)
{
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nRecipeId = 0;
    if (!m_mapRecipes.Lookup(nRow, nRecipeId))
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest4(m_nManufactureId, nRecipeId, &nResult);
    if (nResult != 1)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, reinterpret_cast<Unk_MfNpc*>(pNpc));
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e5f70
void UIManufactureDialog::FUN_1412e5f70(int nRow)
{
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nRecipeId = 0;
    if (!m_mapRecipes.Lookup(nRow, nRecipeId))
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest5(m_nManufactureId, nRecipeId, &nResult);
    if (nResult != 1)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, reinterpret_cast<Unk_MfNpc*>(pNpc));
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e6110
void UIManufactureDialog::FUN_1412e6110(int nResult)
{
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, reinterpret_cast<Unk_MfNpc*>(pNpc));
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
void UIManufactureDialog::OnRecieve()
{
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest6(m_nManufactureId, &nResult);
    if (FUN_1412e7170(nResult) == 0)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, reinterpret_cast<Unk_MfNpc*>(pNpc));
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e63b0
void UIManufactureDialog::OnRecieveByMerat()
{
    MS2Ptr<Unk_UmMfItem> spMf(0);
    if (TSingleton<CManufactureManager>::GetInstance()->Lookup(m_nManufactureId, reinterpret_cast<MS2Ptr<CManufacture>&>(spMf)) == 0)
        return;
    CMsTime tReady(reinterpret_cast<CManufacture*>(spMf.operator->())->FUN_140694170());
    CMsTime tNow(GetServerTime());
    ATL::CTimeSpan span = tReady - tNow;
    __int64 nCost = ((class CLua*)FUN_1401c0db0())->CalcManufactureCompleteByMerat(span.GetTotalSeconds());
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d710(0x102))
    {
        if (!((Unk_UmWallet*)FUN_140d86260())->vfunc_41(nCost) && !((Unk_UmWallet*)FUN_140d86260())->vfunc_40(nCost))
        {
            FUN_141275260(0x35, 1, 1);
            return;
        }
    }
    else
    {
        if (!((Unk_UmWallet*)FUN_140d86260())->vfunc_40(nCost))
        {
            FUN_141275260(0x35, 1, 1);
            return;
        }
    }
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest7(m_nManufactureId, &nResult);
    if (FUN_1412e7170(nResult) == 0)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, reinterpret_cast<Unk_MfNpc*>(pNpc));
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e66f0
void UIManufactureDialog::OnRecieveJackpot()
{
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest9(m_nManufactureId, &nResult);
    if (FUN_1412e7170(nResult) == 0)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, reinterpret_cast<Unk_MfNpc*>(pNpc));
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e6850
void UIManufactureDialog::FUN_1412e6850(int nResult)
{
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, reinterpret_cast<Unk_MfNpc*>(pNpc));
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
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    int nResult;
    CManufactureManager::GetInstance()->SendRequest10(m_nManufactureId, &nResult);
    if (nResult != 4)
    {
        CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, reinterpret_cast<Unk_MfNpc*>(pNpc));
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
            pTalk->FUN_141b1a8e0(strText, "", "");
    }
}

// @0x1412e6af0
void UIManufactureDialog::FUN_1412e6af0(int nResult)
{
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    CStringW strText = CManufactureManager::GetInstance()->GetMaidText(nResult, reinterpret_cast<Unk_MfNpc*>(pNpc));
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
void UIManufactureDialog::FUN_1412e6c30(int nItemId, int nRarity, int nAmount, int nExp, int nBonus, int nJackpot, int nMerat)
{
    if (m_30.IsNull())
        return;
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nNpcId));
    if (pNpc == 0)
        return;
    MS2Ptr<CMaid> spMaid = pNpc->FUN_141093800();
    if (spMaid.IsNull())
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_140523c40(nItemId, nRarity, 0))
    {
        spItem->SetCountClamped(nAmount);
        Unk_TalkItemList aItems;
        aItems.Add(spItem);
        UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
        if (pTalk != 0)
        {
            CStringW strExp(L"");
            CStringW strBonus(L"");
            if (nExp > 0)
                strExp = BlockFormat<int>(0x7c4, nExp);
            else if (nExp < 0)
            {
                int nAbs = abs(nExp);
                strExp = BlockFormat<int>(0x7c5, nAbs);
            }
            if (nBonus != 0)
            {
                if (nMerat != 0)
                    strBonus = StringFormat(L"{0} {1}", BlockFormat<int>(0x7c2, nBonus), BlockFormat<int>(0x7c3, spMaid->m_nOrder));
                else
                    strBonus = BlockFormat<int>(0x7c2, nBonus);
            }
            pTalk->FUN_141b1b000(aItems, nJackpot != 0 ? GetStringCommon(0x7b9) : GetStringCommon(0x7b8), strExp, strBonus, nJackpot);
        }
    }
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
