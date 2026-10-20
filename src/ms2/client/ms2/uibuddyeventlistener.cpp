// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICommunityDialog / UICommunityQueryDialog: see uicommunitydialog.h.
// MS2-UNIT: ?\uibuddyeventlistener.cpp
// MS2-RANGE: 0x140110b20-0x140110f20 .text$di
// MS2-RANGE: 0x1418d3050-0x1418dcba0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@V?$Unk_PayloadPtr@VCBuddy@@@@V?$allocator@V?$Unk_PayloadPtr@VCBuddy@@@@@std@@@std@@@std@@QEAA@XZ 0x1418d8d90 ; unique
// MS2-PIN: ??0?$vector@V?$Unk_PayloadPtr@VCBuddy@@@@V?$allocator@V?$Unk_PayloadPtr@VCBuddy@@@@@std@@@std@@QEAA@XZ 0x1418d8e10 ; unique
// MS2-PIN: ??_EUICommunityDialog@@WBHI@EAAPEAXI@Z 0x1418d8ea0 ; unique
// MS2-PIN: ??_EUICommunityDialog@@WBIA@EAAPEAXI@Z 0x1418d8eac ; unique
// MS2-PIN: ??_EUICommunityDialog@@WBII@EAAPEAXI@Z 0x1418d8eb8 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUICommunityDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x1418d8ed0 ; unique
// MS2-PIN: ??_GUICommunityDialog@@UEAAPEAXI@Z 0x1418d8f10 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$Unk_BuddyPtr@VCBuddy@@@@V?$CElementTraits@V?$Unk_BuddyPtr@VCBuddy@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_BuddyPtr@VCBuddy@@@@_K@Z 0x1418d8f50 ; unique
// MS2-PIN: ?vfunc_48@UICommunityDialog@@UEAAHXZ 0x1418d8fb0 ; unique
// MS2-PIN: ?_Tidy@?$vector@V?$Unk_PayloadPtr@VCBuddy@@@@V?$allocator@V?$Unk_PayloadPtr@VCBuddy@@@@@std@@@std@@AEAAXXZ 0x1418d9000 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUICommunityDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1418d9110 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUICommunityDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x1418d9170 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICommunityDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1418d91f0 ; unique
// MS2-PIN: memmove_s 0x1418d9250 ; unique
// MS2-PIN: ?CallConstructors@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@CAXPEAPEAX_K@Z 0x1418d9f80 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@CAXPEAPEAX_K@Z 0x1418d9ff0 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEBA_KXZ 0x1418da070 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@AEAA_N_K@Z 0x1418da080 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@PEAX@ATL@@SAXPEAPEAX0_K@Z 0x1418da230 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAXXZ 0x1418da270 ; unique
// MS2-PIN: ?RemoveAt@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAX_K0@Z 0x1418da290 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA_N_KH@Z 0x1418da380 ; unique
// MS2-PIN: ??0?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x1418d9d40
// MS2-PIN: ??1?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x1418d9db0
// MS2-PIN: ??A?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAAEAPEAX_K@Z 0x1418da030
// MS2-PIN: ?Add@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA_KPEAX@Z 0x1418d9ed0
// MS2-PIN: ?vfunc_buddy_4@UIBuddyEventListener@@UEAAX_JH@Z 0x1418da220
// MS2-PIN: ?vfunc_buddy_10@UIBuddyEventListener@@UEAAX_JH@Z 0x140d13d50
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it). The unit also holds the bodies of
// UIBuddyEventListener and UIBuddyEventDispatcher (placeholders), which the exe links in the same obj.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibuddyeventlistener.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uicommunitydialog.h"
#include "uimessagebox.h"
#include "partymanager.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/uibuddyeventdispatcher.h"
#include "ms2/placeholder/uiugceventdispatcher.h"
#include "ms2/placeholder/uientityeventdispatcher.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "uimessageboxdata.h"
#include "homeblockmanager.h"
#include "uiinvitementoringdialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// The header statics: the shared list, the key controller, a second sort table, the sound key, the shared list again.
#include "ms2/placeholder/header_statics_a.h"
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_sortB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strPcInviteSuccess = "PC_InviteSuccess";
static CString s_sortC[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject {};
class UIPopUpMenu : public UIDialog {};


// The movie root of the dialog.
class Unk_BdScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_1422bb330(const char* szMethod);                                 // ASDialog::Invoke(method), result dropped
    Scaleform::GFx::Value FUN_1418dca10(const char* szMethod, int n, CStringW a1, CStringW a2);   // Invoke(method, int, text, text); both by value
    Scaleform::GFx::Value FUN_140c1c8c0(const char* szMethod, unsigned __int64 n);      // Invoke(method, id)
    Scaleform::GFx::Value FUN_1413127f0(const char* szMethod, CString a1, CString a2);  // Invoke(method, text, text); both by value
};

// The key state (singleton 0x14025e7c0).
class Unk_BdKeys { public: bool FUN_14116d9c0(int nKey, bool bDebugOnly, int nLevel); };
Unk_BdKeys* FUN_14025e7c0();

// "m_list": the buddy list.
class Unk_BdList : public ASDisplayObject
{
public:
    MS2Ptr<ASDataProvider> FUN_1422dcd80();                 // the data provider
};

class Unk_BdStream { public: virtual void vfunc_0(); virtual unsigned char vfunc_1(); };
class Unk_BuddyInput { public: virtual unsigned vfunc_0(); Unk_BdStream m_stream; int FUN_14070fe80(); void FUN_140715280(unsigned); };
AScript* FUN_1409ee240(MS2Ptr<AScript>* p);
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);

CommonString* FUN_14025e7d0();                              // the CommonString singleton
bool FUN_140a467d0(const MS2Ptr<AScript>* pScript);         // the movie root is not loaded
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
CString FUN_140719530(unsigned __int64 n);                  // number to string
unsigned __int64 FUN_140718350(const CString& str);         // string -> id
unsigned __int64 FUN_140718370(const CStringW& str);        // string -> id
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& aOut, const wchar_t* szDelim);
class Unk_BdEntityEvents { public: void FUN_1419308c0(UIEntityEventListener* p); void FUN_141930950(UIEntityEventListener* p); };
Unk_BdEntityEvents* FUN_140c607b0();

// A counted reference to a CProxyGameObject (the entity events hand it by value; the callee destroys it).
struct Unk_BdProxyRef;
Unk_BdProxyRef* FUN_140ac58f0(Unk_BdProxyRef* pDst, const void* pSrc);
void FUN_1406c70a0(Unk_BdProxyRef* p);
struct Unk_BdProxyRef
{
    Unk_BdProxyRef() : m_unk_00(0), m_p(0) {}
    Unk_BdProxyRef(const void* pSrc) { FUN_140ac58f0(this, pSrc); }
    ~Unk_BdProxyRef() { FUN_1406c70a0(this); }
    CProxyGameObject* operator->() const { return m_p; }
    bool IsNull() const { return m_p == 0; }
    void* m_unk_00;
    CProxyGameObject* m_p;
};
MS2_CHECK_SIZE(Unk_BdProxyRef, 16);

// The world service: the actor map and the proxies.
class Unk_BdWorld
{
public:
    void FUN_141bc9c60(Unk_BdProxyRef* pOut, __int64 nId);      // the proxy of a character id
    MS2Ptr<CProxyGameObject> FUN_141bc9c60(unsigned __int64 nId);  // the same, as the exe's by-value return
    void* FUN_141bc9fb0();                                      // the actor map
    void* FUN_141bd1530(unsigned __int64 nId);                  // the actor of an entity id
    int FUN_141bd3060();                                        // the map id
};
Unk_BdWorld* FUN_1403ed2d0();
void* FUN_140ac5e20(void* pMap);                                // GetStartPosition
void* FUN_140ac5ed0(void* pMap, void* pos);                     // GetValueAt
void FUN_140ac5dd0(void* pMap, void** pos);                     // GetNext

// The UI manager and the dialog finder.
class Unk_BdUIManager { public: void FUN_141adc530(int nUiId); };
Unk_BdUIManager* FUN_1403ed2b0();
UIDialog* FUN_140ae5a30(int nUiId);                             // the dialog of a UI id (or 0)

// The popup menu on a character (UI id 0x4e39) and its parameter block (as in uipartysearchdialog.cpp).
class Unk_BdMenuInfo
{
public:
    void FUN_140c302f0(float x, float y, int nKind, int nMenuId, int a5, CString strKey, void* p);
    void FUN_140c304c0();
    unsigned char m_pad[0x88];
};
MS2_CHECK_SIZE(Unk_BdMenuInfo, 0x88);
class Unk_BdMenu
{
public:
    void FUN_141a7eb60(Unk_BdMenuInfo& info, const Unk_BdProxyRef* pRef, int nType);     // menu on a visible character
    void FUN_141a7f950(Unk_BdMenuInfo& info, __int64 nId);                               // menu on a buddy
    void FUN_141a7fc50(Unk_BdMenuInfo& info, __int64 nId);                               // menu on a home block
};
Unk_BdMenu* FUN_140c30140(int nUiId);

// The settings / features / browser dialog used by the VIP/GM button.
void* FUN_140166410();
bool FUN_14036d570(void* pFeatures, int nFeature);
void* FUN_140c43790(int nUiId);
void FUN_14135ec00(void* pBrowser, const CString& strUrl, bool b);

// Message boxes and the home-visit/actor helpers.
CStringW FUN_1406c6bd0(const wchar_t* pszFormat, const __int64& nArg);          // "{0}" formatter
void FUN_1418fde20(__int64 nId0, __int64 nId1, int nValue, const CStringW& strArg, Delegate<bool(int, const CMsgBoxData&)> cb);
int FUN_1418fd330(__int64 nOwner);
int FUN_1418fd530(__int64 nCharId);
int FUN_1418fd740(__int64 nParam, __int64 nId, int nType);
void FUN_141275260(int nId, int a, int b);
void FUN_140961010(int nId, int a, int b, const CStringW& strArg);
void FUN_1412751f0(const CStringW& strMsg, int a, int b);
void FUN_141276180(CString* pKey, CString strSuffix);
int FUN_141276c80(const CStringW& str, int a, CStringW& strOut);
CStringW FUN_14052bd00(int nId, const CStringW& strArg);
void FUN_14151f200();
int FUN_1403b3c40(const CStringW& str, const wchar_t* psz);       // case-insensitive equal
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* szText);

// The string tables and the text formatters (they return the text through the hidden out pointer).
CStringW FUN_14028de60(int nStringId);
CStringW FUN_14093fa20(int nId, const CStringW& str, int* pnArg);
CStringW FUN_1408116a0(int nId, int* pnArg);
CStringW FUN_140811740(int nId, int* pnA, int* pnB);
CStringW FUN_140a228f0(int nId, int* pnArg, const CStringW& str);
CStringW FUN_140c348b0(int nId, short* pnArg, const CStringW& str);
CString FUN_141028be0(unsigned __int64 nId, const CStringA* pstrImage, int a, const CString& str);
CStringW FUN_1409796e0(int a, int b, int c, const CStringW& str);
unsigned __int64 FUN_141b71960(const char* sz);
CStringTable* FUN_1401a9d70();

void FUN_140710590(COutPacket& packet);
CString* FUN_140298f80(void* p);
char* FUN_1401d3200();

CPartyManager* FUN_1409670d0();
void FUN_1422dc3b0(UICommunityDialog* pDialog, int nBigList);   // the list mode of the window
CString FUN_141028a90(CString str, int n);                      // an image path
bool FUN_140ac5f40(void* pMap);                                 // the actor map is empty

// The UI message posted to the query dialog (ASData + type, 0x50 bytes).
class Unk_BdUIMsg : public UIMsg
{
public:
    Unk_BdUIMsg();                                              // 0x1422e4490
    ~Unk_BdUIMsg();                                             // 0x140c30570
    void FUN_1422b7f70(int n);
    void* m_pad[10];
};

#ifndef MS2_HOOK_DLL
extern template class MS2Ptr<CBanTextChecker>;
#endif

// @0x140110b20 (dynamic initializer of s_strSortTypeNames)
// @0x140110be0 (s_strSkill)
// @0x140110c10 (s_strStun)
// @0x140110c40 (s_unk1402a9d70)
// @0x140110c90 (s_keyInput)
// @0x140110cc0 (s_sortB)
// @0x140110d80 (s_strPcInviteSuccess)
// @0x140110db0 (s_sortC)
// @0x140110e70 (s_strSkill2)
// @0x140110ea0 (s_strStun2)
// @0x140110ed0 (s_unk1402a9d70b)

// @0x1418d3050
int FUN_1418d3050(const CStringW& strMemo)
{
    CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker().get();
    if (pChecker != 0)
    {
        CStringW strMessage;
        if (pChecker->FUN_140226220(strMemo, strMessage) != 0)
        {
            FUN_140d73aa0(strMessage, 0, 0, CStringW(L"communityBanMemoFail"));
            return 0;
        }
    }
    return 1;
}

// ---- UICommunityDialog ----

// Unit-local free functions (the row builders and the manager wrappers).
class Unk_BdTrophy { public: int FUN_140267c10(); int FUN_140267d70(int n); };
void FUN_1418d7af0(ASObj* pObj, void* pTrophy);
int FUN_1418d7b90(ASObj* pRow, CBuddyManager::Ptr spBuddy, int nTab);
int FUN_1418d8540(ASObj* pRow, Unk_BdProxyRef ref, int bNew);
bool FUN_1418d8ac0(ASObj* pRow);
CBuddyManager* FUN_14097a780();
HomeBlockManager* FUN_1414a5830();
UIBuddyEventDispatcher* FUN_140a4a7b0();
CBuddyManager* FUN_1418d8f90();
CBuddyManager* FUN_1418dcb70();

// @0x1418d3190
UICommunityDialog::UICommunityDialog()
    : m_190(0)
    , m_194(0)
    , m_198(0)
    , m_19c(0)
    , m_1a0(0)
{
    m_7c = 1;
    FUN_141924170(1);
}

// @0x1418d32c0
UICommunityDialog::~UICommunityDialog()
{
}

// @0x1418d3370
int UICommunityDialog::vfunc_65()
{
    return UIDialog::vfunc_65() != 0;
}

// @0x1418d33a0
void UICommunityDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    UIUGCEventDispatcher::GetInstance()->FUN_141b38c70(static_cast<UIUGCEventListener*>(this));
    FUN_140a4a7b0()->FUN_1418d94e0(static_cast<UIBuddyEventListener*>(this));
    FUN_140c607b0()->FUN_141930950(static_cast<UIEntityEventListener*>(this));
    m_19c = 0;
    m_198 = 0;
    m_194 = 0;
    m_1a0 = 0;
}

// @0x1418d34a0
void UICommunityDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (vfunc_55() == 0)
    {
        if (m_198 != 0 && m_190 == 1)
            m_194 = FUN_1418d76c0();
        m_198 = 0;
        if (m_19c != 0)
        {
            MS2Ptr<Unk_BdList> spList = m_30->FUN_140accef0<Unk_BdList>(CString("m_list"));
            if (spList.get() != 0)
            {
                MS2Ptr<ASDataProvider> spData = spList->FUN_1422dcd80();
                FUN_1418d77f0(m_194, spData->FUN_1422bc5d0());
            }
        }
        m_19c = 0;
    }
}

// @0x1418d3650
void UICommunityDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1418d6980();
    UIUGCEventDispatcher::GetInstance()->FUN_141b38be0(static_cast<UIUGCEventListener*>(this));
    FUN_140a4a7b0()->FUN_1418d9450(static_cast<UIBuddyEventListener*>(this));
    FUN_140c607b0()->FUN_1419308c0(static_cast<UIEntityEventListener*>(this));
}

// @0x1418d3720
int UICommunityDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (vfunc_55())
        return 0;
    if (FUN_140a467d0(&m_30))
        return 0;
    if (pMsg->FUN_1422e4520())
        return 0;
    if (dynamic_cast<UIPopUpMenu*>(pSender))
    {
        CString strCmd = pMsg->FUN_1422b8d30();
        if (_stricmp("editMemo", strCmd) == 0)
        {
            unsigned __int64 nId = FUN_140718350(pMsg->FUN_1422b8d30());
            if (m_30.get() != 0)
                static_cast<Unk_BdScript*>(m_30.operator->())->FUN_140c1c8c0("editMemo", nId);
            return 1;
        }
    }
    else if (dynamic_cast<UIMessageBox*>(pSender))
    {
        pMsg->FUN_1422b8a10();
        CStringW strText = pMsg->FUN_1422b8f40();
        if (strText.Find(L"communityBanMemoFail", 0) != -1)
        {
            ATL::CAtlArray<CStringW> parts;
            FUN_14025a680(strText, parts, L",");
            if (parts.GetCount() > 1)
            {
                unsigned __int64 nId = FUN_140718370(parts.GetAt(1));
                if (nId > 0)
                    static_cast<Unk_BdScript*>(m_30.operator->())->FUN_140c1c8c0("editMemoFail", nId);
                return 1;
            }
        }
    }
    return 0;
}

// @0x1418d3a70
void UICommunityDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    Unk_BuddyInput* pIn = static_cast<Unk_BuddyInput*>(p);
    if (pIn->FUN_14070fe80() == 0x61 && FUN_140a467d0(&m_30) == 0)
    {
        unsigned nPos = pIn->vfunc_0();
        Unk_BuddyResponse response;
        response.FUN_1407a3cc0(*reinterpret_cast<Unk_BuddyInput*>(pIn));
        pIn->FUN_140715280(nPos);
        if (response.protocol == 1)
        {
            if (m_190 != 0)
                FUN_1418d6430(m_190);
        }
        else if (response.protocol == 0xe && m_190 == 1)
        {
            if (response.flag == 0 || response.flag == 1)
            {
                m_198 = 1;
                m_19c = 1;
            }
        }
    }
}

// @0x1418d3bf0
CString UICommunityDialog::vfunc_1()
{
    return CString("CommunityDialog");
}

// @0x1418d3c40
int UICommunityDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (m_1a0 == 0)
        return 0;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
    {
        if (m_30.get() != 0)
        {
            CString strId = FUN_140719530(m_1a0);
            m_30->Invoke("endEditBanMemo", strId);
        }
        return 1;
    }
    return 0;
}

// A request to the buddy manager: protocol and the id taken from the first argument.
static int Unk_BdSendRequest(UICommunityDialog* pDialog, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, unsigned char nProtocol)
{
    ASData data;
    if (!data.FUN_1422b9620(pArgs, nArgs))
        return 0;
    Unk_BuddyRequest request;
    request.protocol = nProtocol;
    request.id = FUN_140718350(data.FUN_1422b8d30());
    FUN_1418d8f90()->FUN_140ae4820(request);
    return 1;
}

// MS2-FUNCTIONAL: the exe expands the AS callbacks inline with one set of ASData/CString temporaries per branch
// @0x1418d3d70
int UICommunityDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnChangeTab", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            FUN_1418d69f0(data.FUN_1422b8a10());
            return 1;
        }
    }
    else
    {
        if (_stricmp("OnAddBan", szMethod) == 0)
        {
            FUN_1418d6ed0(0, 2);
            return 1;
        }
        if (_stricmp("OnAddBuddy", szMethod) == 0)
        {
            FUN_1418d6ed0(0, 1);
            return 1;
        }
        if (_stricmp("OnAcceptBuddy", szMethod) == 0)
        {
            if (Unk_BdSendRequest(this, pArgs, nArgs, 3))
                return 1;
        }
        else if (_stricmp("OnDeclineBuddy", szMethod) == 0)
        {
            if (Unk_BdSendRequest(this, pArgs, nArgs, 4))
                return 1;
        }
        else if (_stricmp("OnDeleteBuddy", szMethod) == 0)
        {
            if (Unk_BdSendRequest(this, pArgs, nArgs, 7))
                return 1;
        }
        else if (_stricmp("OnCancelBuddy", szMethod) == 0)
        {
            if (Unk_BdSendRequest(this, pArgs, nArgs, 0x11))
                return 1;
        }
        else if (_stricmp("onHomeVisit", szMethod) == 0)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs))
            {
                __int64 nId = 0;
                int nKind;
                CStringW strName;
                unsigned __int64 nTarget = FUN_140718350(data.FUN_1422b8d30());
                CBuddyManager::Ptr spBuddy = FUN_1418d8f90()->FUN_140ae4b70(nTarget);
                if (spBuddy.get() == 0)
                {
                    nId = nTarget;
                    nKind = 8;
                    void* pActor = FUN_1403ed2d0()->FUN_141bd1530(nId);
                    if (pActor != 0)
                    {
                        typedef CStringW* (*PfnName)(void*, CStringW*);
                        CStringW strTemp;
                        (*reinterpret_cast<PfnName*>(*reinterpret_cast<char**>(pActor) + 0x268))(pActor, &strTemp);
                        strName = strTemp;
                    }
                }
                else
                {
                    nId = spBuddy->FUN_1401cc230();
                    nKind = 7;
                    strName = spBuddy->FUN_1401cc1c0();
                }
                spBuddy = CBuddyManager::Ptr();
                if (FUN_1418fd330(nId) != 0)
                {
                    FUN_1418fde20(0, nId, nKind, strName,
                        Delegate<bool(int, const CMsgBoxData&)>(this, &UICommunityDialog::FUN_1418d6390));
                    return 1;
                }
            }
        }
        else if (_stricmp("OnBuddyPopupMenu", szMethod) == 0)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs))
            {
                float fX = data.FUN_1422b8c10();
                float fY = data.FUN_1422b8c10();
                unsigned __int64 nTarget = FUN_140718350(data.FUN_1422b8d30());
                if (m_190 == 0)
                {
                    Unk_BdProxyRef ref;
                    FUN_1403ed2d0()->FUN_141bc9c60(&ref, nTarget);
                    Unk_BdMenu* pMenu = ref.IsNull() ? 0 : FUN_140c30140(0x4e39);
                    if (pMenu != 0)
                    {
                        Unk_BdMenuInfo info;
                        info.FUN_140c302f0(fX, fY, 3, 0x3f3fe, 1, CString(""), 0);
                        pMenu->FUN_141a7eb60(info, &ref, 8);
                        info.FUN_140c304c0();
                        return 1;
                    }
                }
                else if (m_190 == 4)
                {
                    HomeBlockManager::HomePtr spHome = FUN_1414a5830()->FUN_140a47490(nTarget);
                    Unk_BdMenu* pMenu = spHome.get() == 0 ? 0 : FUN_140c30140(0x4e39);
                    if (pMenu != 0)
                    {
                        Unk_BdMenuInfo info;
                        info.FUN_140c302f0(fX, fY, 3, 0x20046, 1, CString(""), 0);
                        pMenu->FUN_141a7fc50(info, nTarget);
                        info.FUN_140c304c0();
                        return 1;
                    }
                }
                else
                {
                    CBuddyManager::Ptr spBuddy = FUN_1418d8f90()->FUN_140ae4b70(nTarget);
                    Unk_BdMenu* pMenu = spBuddy.get() == 0 ? 0 : FUN_140c30140(0x4e39);
                    if (pMenu != 0)
                    {
                        Unk_BdMenuInfo info;
                        info.FUN_140c302f0(fX, fY, 3, 0x63fe, 1, CString(""), 0);
                        pMenu->FUN_141a7f950(info, nTarget);
                        info.FUN_140c304c0();
                        return 1;
                    }
                }
                return 1;
            }
        }
        else if (_stricmp("OnEditBanMemo", szMethod) == 0)
        {
            ASData data;
            if (!data.FUN_1422b9620(pArgs, nArgs))
                return 1;
            m_1a0 = 0;
            CStringW strName = data.FUN_1422b8f40();
            CStringW strMemo = data.FUN_1422b8f40();
            __int64 nId = FUN_140718350(data.FUN_1422b8d30());
            CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker().get();
            if (pChecker != 0)
            {
                CStringW strMessage;
                if (pChecker->FUN_140226220(strMemo, strMessage) != 0)
                {
                    CStringW strTag = FUN_1406c6bd0(L"communityBanMemoFail,{0}", nId);
                    FUN_140d73aa0(strMessage, 0, static_cast<IMessageListener*>(this), strTag);
                    return 1;
                }
            }
            if (m_190 == 3)
            {
                Unk_BuddyRequest request;
                request.protocol = 10;
                request.name = strName;
                request.memo = strMemo;
                request.id = nId;
                FUN_1418d8f90()->FUN_140ae4820(request);
            }
            else if (m_190 == 4)
            {
                FUN_1414a5830()->FUN_140a47c80(nId, strMemo);
            }
            return 1;
        }
        else if (_stricmp("OnEditBanMemoStart", szMethod) == 0)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs))
                m_1a0 = FUN_140718350(data.FUN_1422b8d30());
            return 1;
        }
        else if (_stricmp("OnEditBanMemoEnd", szMethod) == 0)
        {
            m_1a0 = 0;
            return 1;
        }
        else if (_stricmp("OnVIPGMClick", szMethod) == 0)
        {
            if (!FUN_14036d570(FUN_140166410(), 0x82))
                return 1;
            void* pBrowser = FUN_140c43790(0x4e6a);
            if (pBrowser != 0)
                FUN_14135ec00(pBrowser, CString(*FUN_140298f80(reinterpret_cast<char*>(FUN_1401d3200()) + 0x8838)), true);
            COutPacket packet(0x97, 0);
            packet.vfunc_o10_1(5);
            packet.vfunc_o10_1(1);
            FUN_140710590(packet);
            return 1;
        }
    }
    return 0;
}

// @0x1418d5150
void UICommunityDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (_stricmp("getTrophyTooltip", strMethod) == 0)
    {
        void* pTrophy = 0;
        if (m_190 == 0)
        {
            unsigned __int64 nId = FUN_141b71960(pArgs->FUN_1422b8d30());
            MS2Ptr<CProxyGameObject> spProxy = FUN_1403ed2d0()->FUN_141bc9c60(nId);
            if (spProxy.get())
                pTrophy = spProxy->FUN_1416c2950();
        }
        else
        {
            unsigned __int64 nId = FUN_141b71960(pArgs->FUN_1422b8d30());
            CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4b70(nId);
            if (spBuddy.get() != 0)
                pTrophy = spBuddy->FUN_1401cc330();
        }
        if (pTrophy != 0)
        {
            ASObj obj(2);
            FUN_1418d7af0(&obj, pTrophy);
            *pRetVal = obj.FUN_1422bb870();
        }
    }
}

// @0x1418d5340
void UICommunityDialog::vfunc_ugc_1(void* p, CString str)
{
    if (vfunc_55())
        return;
    if (p == 0)
        return;
    CString strId;
    if (m_190 == 0)
    {
        strId = FUN_140719530((unsigned __int64)p);
    }
    else
    {
        CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4880((__int64)p);
        if (spBuddy.get() != 0)
            strId = FUN_140719530(spBuddy->id);
    }
    if (!strId.IsEmpty())
    {
        static_cast<Unk_BdScript*>(m_30.operator->())->FUN_1413127f0("updateBuddyProfile", CString(strId), FUN_141028a90(CString(str), 0));
    }
}

// @0x1418d55e0
void UICommunityDialog::vfunc_buddy_2(__int64 nId)
{
    if (m_190 == 2)
    {
        m_19c = 1;
        FUN_1418d7240(nId);
    }
    else
        FUN_1418d6f80(2, 1, -1);
}

// @0x1418d5650
void UICommunityDialog::vfunc_buddy_1(__int64 nId)
{
    if (m_190 == 2)
    {
        m_19c = 1;
        FUN_1418d71d0(m_190, nId);
    }
    else
        FUN_1418d6f80(2, 1, 1);
}

// @0x1418d56d0
void UICommunityDialog::vfunc_buddy_3(__int64 nId)
{
    if (m_190 == 1)
    {
        FUN_1418d71d0(m_190, nId);
    }
    else if (m_190 == 2)
    {
        m_19c = 1;
        FUN_1418d7240(nId);
        FUN_1418d6f80(1, 1, 1);
    }
    else
        FUN_1418d6f80(1, 1, 1);
}

// @0x1418d5790
void UICommunityDialog::vfunc_buddy_4(__int64 nId, int n)
{
    if (m_190 == 3)
    {
        FUN_1418d71d0(m_190, nId);
    }
    else
    {
        FUN_1418d6f80(3, 1, 1);
        if (n != 0)
        {
            if (m_190 == 1)
            {
                m_198 = 1;
                FUN_1418d7240(nId);
            }
            else
                FUN_1418d6f80(1, 1, -1);
        }
    }
}

// @0x1418d5860
void UICommunityDialog::vfunc_buddy_5(__int64 nId)
{
    if (m_190 == 1 || m_190 == 2)
    {
        m_198 = 1;
        FUN_1418d7240(nId);
    }
    else
        FUN_1418d6f80(1, 1, -1);
}

// @0x1418d58e0
void UICommunityDialog::vfunc_buddy_6(__int64 nId)
{
    if (m_190 == 3)
        FUN_1418d7240(nId);
    else
        FUN_1418d6f80(3, 1, -1);
}

// @0x1418d5950
void UICommunityDialog::vfunc_buddy_8(__int64 nId)
{
    if (m_190 == 1)
        FUN_1418d7240(nId);
    else
        FUN_1418d6f80(1, 1, -1);
}

// @0x1418d59c0
void UICommunityDialog::vfunc_buddy_9(__int64 nId)
{
    CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4b70(nId);
    if (spBuddy.get() != 0)
    {
        bool bUpdate;
        if (spBuddy->FUN_1401cc5d0() != 0 && m_190 == 2)
            bUpdate = true;
        else if (spBuddy->FUN_1401cc5f0() != 0 && m_190 == 1)
            bUpdate = true;
        else if (spBuddy->FUN_1401cc5b0() != 0 && m_190 == 3)
            bUpdate = true;
        else
            bUpdate = false;
        if (bUpdate)
            FUN_1418d73b0(m_190, CBuddyManager::Ptr(spBuddy));
    }
}

// @0x1418d5ae0
void UICommunityDialog::vfunc_buddy_11(__int64 nId)
{
    if (m_190 != 3)
        return;
    CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4b70(nId);
    if (spBuddy == NULL)
        return;
    if (spBuddy->FUN_1401cc5b0() == 0)
        return;
    CString strId = FUN_140719530(nId);
    m_30->FUN_140c38f00("updateBanMemo", CString(strId), CStringW(spBuddy->memo));
}

// @0x1418d5c60
void UICommunityDialog::vfunc_buddy_12(__int64 nId)
{
    if (m_190 != 4)
        return;
    HomeBlockManager::BuddyPtr spBuddy = FUN_1414a5830()->FUN_140a477f0(nId);
    if (spBuddy == NULL)
        return;
    FUN_1418d6430(4);
}

// @0x1418d5cf0
void UICommunityDialog::vfunc_buddy_13(__int64 nId)
{
    if (m_190 != 4)
        return;
    HomeBlockManager::HomePtr spHome = FUN_1414a5830()->FUN_140a47490(nId);
    if (spHome == NULL)
        return;
    CString strId = FUN_140719530(spHome->m_18);
    static_cast<Unk_BdScript*>(m_30.operator->())->FUN_1413127f0("updateBanMemo", CString(strId), CString(spHome->m_50));
}

// @0x1418d5e50
void UICommunityDialog::vfunc_buddy_14()
{
    if (m_190 == 4)
        FUN_1418d6430(4);
}

// MS2-FUNCTIONAL: UIEntityEventListener hands the actor as a by-value MS2Ptr<CProxyGameObject> (callee-destroyed, IsNull/operator-> COMDATs); the placeholder base (uientityeventlistener.h, 18 users) declares void*, so the param is reached through a cast local - retyping the shared vtable slot is a cross-unit change
// @0x1418d5e90
void UICommunityDialog::vfunc_3(void* pActor)
{
    Unk_BdProxyRef* pRef = static_cast<Unk_BdProxyRef*>(pActor);
    if (!pRef->IsNull() && vfunc_55() == 0 && (*pRef)->FUN_1416c2040() != 0)
    {
        if (m_190 == 0)
        {
            ASObj obj(2);
            if (FUN_1418d8540(&obj, Unk_BdProxyRef(pRef), 1) != 0)
            {
                m_19c = 1;
                m_30->Invoke("addBuddy", obj.FUN_1422bb870());
            }
        }
        else
            FUN_1418d6f80(0, 1, 1);
    }
    FUN_1406c70a0(pRef);
}

// MS2-FUNCTIONAL: UIEntityEventListener hands the actor as a by-value MS2Ptr<CProxyGameObject> (callee-destroyed, IsNull/operator-> COMDATs); the placeholder base (uientityeventlistener.h, 18 users) declares void*, so the param is reached through a cast local - retyping the shared vtable slot is a cross-unit change
// @0x1418d6060
void UICommunityDialog::vfunc_4(void* pActor)
{
    Unk_BdProxyRef* pRef = static_cast<Unk_BdProxyRef*>(pActor);
    if (!pRef->IsNull() && vfunc_55() == 0 && (*pRef)->FUN_1416c2040() != 0)
    {
        if (m_190 == 0)
        {
            m_19c = 1;
            CString strId = FUN_140719530((unsigned __int64)(*pRef)->FUN_1416c22f0());
            m_30->Invoke("removeBuddy", CString(strId));
        }
    }
    FUN_1406c70a0(pRef);
}

// MS2-FUNCTIONAL: UIEntityEventListener hands the actor as a by-value MS2Ptr<CProxyGameObject> (callee-destroyed, IsNull/operator-> COMDATs); the placeholder base (uientityeventlistener.h, 18 users) declares void*, so the param is reached through a cast local - retyping the shared vtable slot is a cross-unit change
// @0x1418d61d0
void UICommunityDialog::vfunc_5(void* pActor, int n)
{
    Unk_BdProxyRef* pRef = static_cast<Unk_BdProxyRef*>(pActor);
    if (!pRef->IsNull() && vfunc_55() == 0 && m_190 == 0 && n != 0)
    {
        if ((n & ~3) > 0)
        {
            ASObj obj(2);
            if (FUN_1418d8540(&obj, Unk_BdProxyRef(pRef), 0) != 0)
                m_30->Invoke("updateBuddy", obj.FUN_1422bb870());
        }
    }
    FUN_1406c70a0(pRef);
}

// @0x1418d6390
bool UICommunityDialog::FUN_1418d6390(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
        FUN_1418fd740(data.FUN_141a02ed0(0, 0), data.FUN_141a02ed0(1, 0), data.FUN_141a02e50(2, 0));
    return true;
}

// @0x1418d6410
void FUN_1418d6410(UICommunityDialog* pDialog)
{
    pDialog->m_190 = 0;
}

// MS2-FUNCTIONAL: the exe keeps the five tab counters in one zeroed local block; the classification tree is the same
// @0x1418d6430
void UICommunityDialog::FUN_1418d6430(int nTab)
{
    if (FUN_140a467d0(&m_30) != 0)
        return;
    m_19c = 1;
    if (nTab == 0)
        FUN_1418d6a90();
    int bSkip = (nTab == 0);
    if (nTab == 4)
    {
        FUN_1418d6d00();
        bSkip = 1;
    }
    ASArray arr(2);
    ATL::CAtlArray<CBuddyManager::Ptr> buddies;
    FUN_1418d8f90()->FUN_140ae4df0(buddies);
    int nOnline = 0;
    __int64 aCount[5] = {0, 0, 0, 0, 0};
    if (buddies.GetCount() != 0)
    {
        for (size_t i = 0; i < buddies.GetCount(); i++)
        {
            CBuddyManager::Ptr spBuddy(buddies[i]);
            if (spBuddy.get() == 0)
                continue;
            int bInclude = 0;
            if (spBuddy->FUN_1401cc660() == 0)
            {
                if (spBuddy->FUN_1401cc5f0() == 0)
                {
                    if (spBuddy->FUN_1401cc5d0() == 0)
                    {
                        if (spBuddy->FUN_1401cc5b0() != 0)
                        {
                            if (spBuddy->FUN_1401cc4d0() != 0)
                                aCount[3]++;
                            bInclude = (nTab == 3);
                        }
                    }
                    else
                    {
                        aCount[2]++;
                        bInclude = (nTab == 2);
                    }
                }
                else
                {
                    if (spBuddy->FUN_1401cc680() != 0)
                        nOnline++;
                    if (spBuddy->FUN_1401cc4d0() != 0)
                        aCount[1]++;
                    bInclude = (nTab == 1);
                }
            }
            else
                bInclude = (nTab == 1);
            if (bInclude != 0)
            {
                ASObj row(2);
                FUN_1418d7b90(&row, CBuddyManager::Ptr(spBuddy), nTab);
                arr.FUN_1422bc050(row.FUN_1422bb870());
            }
        }
    }
    m_194 = nOnline;
    if (bSkip == 0)
        m_30->FUN_140bd2cb0("buildBuddyList", arr);
    for (int i = 0; i < 5; i++)
        FUN_1418d6f80(i, aCount[i] != 0, (int)aCount[i]);
}

// @0x1418d6930
void UICommunityDialog::FUN_1418d6930(int nTab)
{
    if (nTab >= 0 && nTab < 5)
        m_190 = nTab;
}

// @0x1418d6960
int UICommunityDialog::FUN_1418d6960()
{
    return m_190;
}

// @0x1418d6980
void UICommunityDialog::FUN_1418d6980()
{
    if (FUN_140a467d0(&m_30) == 0)
        m_30->Invoke("initData", m_190);
}

// @0x1418d69f0
void UICommunityDialog::FUN_1418d69f0(int nTab)
{
    if (FUN_140a467d0(&m_30) == 0 && nTab >= 0 && nTab < 5)
    {
        FUN_1422dc3b0(nTab == 3 || nTab == 4);
        m_190 = nTab;
        FUN_1418d6430(nTab);
    }
}

// @0x1418d6a90
void UICommunityDialog::FUN_1418d6a90()
{
    ASArray arr(2);
    ASObj vipRow(2);
    if (FUN_1418d8ac0(&vipRow) != 0)
        arr.FUN_1422bc050(vipRow.FUN_1422bb870());
    void* pMap = FUN_1403ed2d0()->FUN_141bc9fb0();
    if (!FUN_140ac5f40(pMap))
    {
        for (void* pos = FUN_140ac5e20(pMap); pos != 0; FUN_140ac5dd0(pMap, &pos))
        {
            Unk_BdProxyRef ref(FUN_140ac5ed0(pMap, pos));
            if (!ref.IsNull())
            {
                if (ref->FUN_1416c2040() != 0 || ref->FUN_1416c1ff0() != 0)
                {
                    ASObj row(2);
                    if (FUN_1418d8540(&row, Unk_BdProxyRef(&ref), 0) != 0)
                        arr.FUN_1422bc050(row.FUN_1422bb870());
                }
            }
        }
    }
    m_30->FUN_140bd2cb0("buildBuddyList", arr);
}

// @0x1418d6d00
void UICommunityDialog::FUN_1418d6d00()
{
    if (FUN_140a467d0(&m_30) != 0)
        return;
    ASArray arr(2);
    std::vector<HomeBlockManager::BuddyPtr> vecBuddies;
    FUN_1414a5830()->FUN_140a47670(vecBuddies);
    for (std::vector<HomeBlockManager::BuddyPtr>::iterator it = vecBuddies.begin(); it != vecBuddies.end(); ++it)
    {
        CBuddyManager::Ptr spBuddy(it->get());
        ASObj row(2);
        FUN_1418d7b90(&row, CBuddyManager::Ptr(spBuddy), 4);
        arr.FUN_1422bc050(row.FUN_1422bb870());
    }
    m_30->FUN_140bd2cb0("buildBuddyList", arr);
}

// @0x1418d6ed0
void UICommunityDialog::FUN_1418d6ed0(int nA, int nB)
{
    Unk_BdUIMsg msg;
    msg.FUN_1422b7f70(nA);
    msg.FUN_1422b7f70(nB);
    UIDialog* pDialog = FUN_140ae5a30(0x4e4e);
    if (pDialog != 0)
        pDialog->OnMessage(this, &msg);
}

// @0x1418d6f80
void UICommunityDialog::FUN_1418d6f80(int nTab, int nNew, int nCount)
{
    if (m_30.get() != 0)
        m_30->Invoke("setNew", nTab, nNew, nCount);
}

// @0x1418d7000
void UICommunityDialog::FUN_1418d7000(int nTab, CBuddyManager::Ptr spBuddy)
{
    if (FUN_140a467d0(&m_30) != 0)
        return;
    if (spBuddy.get() == 0)
        return;
    ASObj row(2);
    FUN_1418d7b90(&row, CBuddyManager::Ptr(spBuddy), nTab);
    if (m_190 == 1)
    {
        if (spBuddy->FUN_1401cc5f0() != 0 && spBuddy->FUN_1401cc680() != 0)
        {
            m_194++;
            m_19c = 1;
        }
    }
    m_30->Invoke("addBuddy", row.FUN_1422bb870());
}

// @0x1418d71d0
void UICommunityDialog::FUN_1418d71d0(int nTab, __int64 nId)
{
    if (FUN_140a467d0(&m_30) == 0)
        FUN_1418d7000(nTab, FUN_14097a780()->FUN_140ae4b70(nId));
}

// @0x1418d7240
void UICommunityDialog::FUN_1418d7240(__int64 nId)
{
    if (FUN_140a467d0(&m_30) != 0)
        return;
    CString strId = FUN_140719530(nId);
    if (m_190 == 1)
    {
        CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4b70(nId);
        if (spBuddy.get() != 0)
        {
            if (spBuddy->FUN_1401cc5f0() != 0 && spBuddy->FUN_1401cc680() != 0)
            {
                m_194--;
                m_19c = 1;
            }
        }
    }
    m_30->Invoke("removeBuddy", CString(strId));
}

// @0x1418d73b0
void UICommunityDialog::FUN_1418d73b0(int nTab, CBuddyManager::Ptr spBuddy)
{
    if (FUN_140a467d0(&m_30) == 0)
    {
        ASObj row(2);
        FUN_1418d7b90(&row, CBuddyManager::Ptr(spBuddy), nTab);
        m_30->Invoke("updateBuddy", row.FUN_1422bb870());
    }
}

// @0x1418d74f0
void UICommunityDialog::FUN_1418d74f0(__int64 nId)
{
    if (FUN_140a467d0(&m_30) != 0)
        return;
    CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4b70(nId);
    if (spBuddy.get() != 0)
    {
        CString strId = FUN_140719530(nId);
        CString strImage = FUN_141028be0(spBuddy->FUN_1401cc230(), spBuddy->FUN_1401cc530(), 1, CString(""));
        static_cast<Unk_BdScript*>(m_30.operator->())->FUN_1413127f0("updateBuddyProfile", CString(strId), strImage);
    }
}

// @0x1418d76c0
int UICommunityDialog::FUN_1418d76c0()
{
    ATL::CAtlArray<CBuddyManager::Ptr> buddies;
    FUN_1418d8f90()->FUN_140ae4df0(buddies);
    int nOnline = 0;
    if (buddies.GetCount() != 0)
    {
        for (size_t i = 0; i < buddies.GetCount(); i++)
        {
            CBuddyManager::Ptr spBuddy(buddies[i]);
            if (spBuddy.get() != 0)
            {
                if (spBuddy->FUN_1401cc5f0() != 0 && spBuddy->FUN_1401cc680() != 0)
                    nOnline++;
            }
        }
    }
    return nOnline;
}

// @0x1418d77f0
void UICommunityDialog::FUN_1418d77f0(int nOnline, int nTotal)
{
    CStringW strText;
    if (m_190 == 0)
    {
        int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
        strText = FUN_14093fa20(0x60e, FUN_1401a9d70()->FUN_141811980(3, nMapId), &nTotal);
    }
    else if (m_190 == 2)
        strText = FUN_1408116a0(0x60f, &nTotal);
    else if (m_190 == 3)
        strText = FUN_1408116a0(0x610, &nTotal);
    else if (m_190 == 1)
        strText = FUN_140811740(0x612, &nOnline, &nTotal);
    else if (m_190 == 4)
        strText = FUN_1408116a0(0x611, &nTotal);
    m_30->Invoke("setOnline", CStringW(strText));
}

// @0x1418d7af0
void FUN_1418d7af0(ASObj* pObj, void* pTrophy)
{
    Unk_BdTrophy* pScore = static_cast<Unk_BdTrophy*>(pTrophy);
    pObj->FUN_1407cb9c0("total", pScore->FUN_140267c10());
    pObj->FUN_1407cb9c0("combat", pScore->FUN_140267d70(0));
    pObj->FUN_1407cb9c0("life", pScore->FUN_140267d70(2));
    pObj->FUN_1407cb9c0("adventure", pScore->FUN_140267d70(1));
}

// MS2-FUNCTIONAL: the exe keeps one set of string temporaries per member; the member order and the values are the same
// @0x1418d7b90
int FUN_1418d7b90(ASObj* pRow, CBuddyManager::Ptr spBuddy, int nTab)
{
    if (spBuddy.get() == 0)
        return 0;
    pRow->FUN_1407cbb20("charname", spBuddy->FUN_1401cc1c0());
    CString strAccount = FUN_140719530(spBuddy->FUN_1401cc2f0());
    __int64 nId = spBuddy->FUN_1401cc230();
    pRow->FUN_1407cba60("buddysn", CString(strAccount));
    pRow->FUN_1407cba60("imgpath", FUN_141028be0(nId, spBuddy->FUN_1401cc530(), 1, CString("")));
    int nWaiting = spBuddy->FUN_1401cc660();
    pRow->FUN_1407cb9c0("isWaiting", nWaiting);
    int bOffline = (spBuddy->FUN_1401cc680() == 0 || nWaiting != 0) ? 0 : 1;
    pRow->FUN_1407cbbe0("offline", bOffline == 0);
    pRow->FUN_1407cb9c0("trophyTotal", static_cast<Unk_BdTrophy*>(static_cast<void*>(spBuddy->FUN_1401cc330()))->FUN_140267c10());
    pRow->FUN_1407cb9c0("homeVisitEnable", FUN_1418fd530(nId));
    CStringW strState;
    if (bOffline == 0)
    {
        if (nWaiting == 0)
            strState = FUN_14028de60(0x60d);
        else
            strState = FUN_14028de60(0x60b);
    }
    else
    {
        int nMapId = spBuddy->FUN_1401cc270();
        int nChannel = spBuddy->FUN_1401cc310();
        if (nChannel == 0)
        {
            strState = FUN_1401a9d70()->FUN_141811980(3, nMapId);
        }
        else
        {
            int nChannel2 = spBuddy->FUN_1401cc310();
            strState = FUN_140a228f0(0x60c, &nChannel2, FUN_1401a9d70()->FUN_141811980(3, nMapId));
        }
    }
    MS2Ptr<CPartyMember> spMember = FUN_1409670d0()->FUN_14162afc0(nId);
    pRow->FUN_1407cb9c0("isParty", spMember.get() != 0);
    spMember = MS2Ptr<CPartyMember>();
    pRow->FUN_1407cbb20("state", CStringW(strState));
    short nLevel = spBuddy->FUN_1401cc210();
    int nJob = spBuddy->FUN_1401cc2b0();
    pRow->FUN_1407cbb20("charinfo", FUN_140a228f0(0x20, (int*)&nLevel, FUN_1401a9d70()->FUN_141811980(6, nJob)));
    pRow->FUN_1407cb9c0("isNew", spBuddy->FUN_1401cc4f0());
    pRow->FUN_1407cb9c0("recv", nTab == 2);
    if (nTab == 2)
    {
        pRow->FUN_1407cbb20("msg", CStringW(*spBuddy->FUN_1401cc550()));
    }
    else if (nTab == 1)
    {
        CStringW strAddress = spBuddy->FUN_1401cc350();
        int nPart2 = spBuddy->FUN_1401cc3c0();
        int nPart1 = spBuddy->FUN_1401cc3a0();
        int nPart0 = spBuddy->FUN_1401cc3e0();
        pRow->FUN_1407cbb20("address", FUN_1409796e0(nPart0, nPart1, nPart2, strAddress));
        pRow->FUN_1407cbb20("todaymemo", CStringW(*spBuddy->FUN_1401cc570()));
    }
    else
    {
        pRow->FUN_1407cbb20("memo", CStringW(*spBuddy->FUN_1401cc590()));
    }
    return 1;
}

// @0x1418d8540
int FUN_1418d8540(ASObj* pRow, Unk_BdProxyRef ref, int bNew)
{
    if (ref.IsNull())
        return 0;
    pRow->FUN_1407cbbe0("isPlayerInfo", true);
    pRow->FUN_1407cbb20("charname", ref->FUN_1416c23b0());
    __int64 nId = (__int64)ref->FUN_1416c22f0();
    CString strId = FUN_140719530(nId);
    pRow->FUN_1407cba60("buddysn", CString(strId));
    CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4880(nId);
    int bBuddy = (!spBuddy.operator!() && spBuddy->FUN_1401cc5f0() != 0) ? 1 : 0;
    pRow->FUN_1407cb9c0("isBuddy", bBuddy);
    MS2Ptr<CPartyMember> spMember = FUN_1409670d0()->FUN_14162afc0(nId);
    pRow->FUN_1407cb9c0("isParty", spMember.get() != 0);
    spMember = MS2Ptr<CPartyMember>();
    CString strImage = ref->FUN_1416c2520();
    pRow->FUN_1407cba60("imgpath", FUN_141028be0(nId, &strImage, 1, CString("")));
    short nLevel = (short)ref->FUN_1416c2330();
    int nJob = ref->FUN_1416c2390();
    pRow->FUN_1407cbb20("charinfo", FUN_140c348b0(0x20, &nLevel, FUN_1401a9d70()->FUN_141811980(6, nJob)));
    pRow->FUN_1407cb9c0("offline", 0);
    pRow->FUN_1407cbb20("address", ref->FUN_1416c2600());
    pRow->FUN_1407cbb20("todaymemo", ref->FUN_1416c2570());
    pRow->FUN_1407cb9c0("isNew", bNew);
    pRow->FUN_1407cb9c0("trophyTotal", static_cast<Unk_BdTrophy*>(static_cast<void*>(ref->FUN_1416c2950()))->FUN_140267c10());
    pRow->FUN_1407cb9c0("homeVisitEnable", FUN_1418fd530(nId));
    pRow->FUN_1407cbbe0("isVIPGM", false);
    return 1;
}

// @0x1418d8ac0
bool FUN_1418d8ac0(ASObj* pRow)
{
    bool bVip = FUN_14036d570(FUN_140166410(), 0x82);
    if (bVip)
        pRow->FUN_1407cbbe0("isVIPGM", true);
    return bVip;
}

// ---- UIBuddyEventListener / UIBuddyEventDispatcher (placeholders; bodies of this obj) ----

unsigned __int64* FUN_140a4b820(void* it);
unsigned __int64* FUN_140a4b860(void* it);

// @0x1418d90d0
unsigned __int64 FUN_1418d90d0(void* it)
{
    return *FUN_140a4b820(it);
}

// @0x1418d90f0
unsigned __int64 FUN_1418d90f0(void* it)
{
    return *FUN_140a4b860(it);
}

// @0x1418d9370
UIBuddyEventListener::UIBuddyEventListener()
{
}

// @0x1418d9390
UIBuddyEventListener::~UIBuddyEventListener()
{
}

// @0x1418d93b0
UIBuddyEventDispatcher::UIBuddyEventDispatcher()
{
}

// @0x1418d9400
UIBuddyEventDispatcher::~UIBuddyEventDispatcher()
{
    m_8.RemoveAll();
}

// MS2-FUNCTIONAL: the exe's CAtlArray<void*>::Add takes the element by reference (older ATL); ours takes it by value
// @0x1418d9450
void UIBuddyEventDispatcher::FUN_1418d9450(UIBuddyEventListener* pListener)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        if (pListener == m_8[i])
            return;
    }
    m_8.Add(pListener);
}

// @0x1418d94e0
void UIBuddyEventDispatcher::FUN_1418d94e0(UIBuddyEventListener* pListener)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        if (pListener == m_8[i])
        {
            m_8.RemoveAt(i, 1);
            return;
        }
    }
}

// @0x1418d9570
void UIBuddyEventDispatcher::vfunc_1(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_1(nId);
    }
}

// @0x1418d9600
void UIBuddyEventDispatcher::vfunc_2(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_2(nId);
    }
}

// @0x1418d9690
void UIBuddyEventDispatcher::vfunc_3(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_3(nId);
    }
}

// @0x1418d9720
void UIBuddyEventDispatcher::vfunc_4(__int64 nId, int n)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_4(nId, n);
    }
}

// @0x1418d97b0
void UIBuddyEventDispatcher::vfunc_5(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_5(nId);
    }
}

// @0x1418d9840
void UIBuddyEventDispatcher::vfunc_6(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_6(nId);
    }
}

// @0x1418d98d0
void UIBuddyEventDispatcher::vfunc_7(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_7(nId);
    }
}

// @0x1418d9960
void UIBuddyEventDispatcher::vfunc_8(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_8(nId);
    }
}

// @0x1418d99f0
void UIBuddyEventDispatcher::vfunc_9(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_9(nId);
    }
}

// @0x1418d9a80
void UIBuddyEventDispatcher::vfunc_10(__int64 nId, int n)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_10(nId, n);
    }
}

// @0x1418d9b10
void UIBuddyEventDispatcher::vfunc_11(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_11(nId);
    }
}

// @0x1418d9ba0
void UIBuddyEventDispatcher::vfunc_12(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_12(nId);
    }
}

// @0x1418d9c30
void UIBuddyEventDispatcher::vfunc_13(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_13(nId);
    }
}

// @0x1418d9cc0
void UIBuddyEventDispatcher::vfunc_14()
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = static_cast<UIBuddyEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_buddy_14();
    }
}

// ---- helper functions ----

// @0x1418d8f90
CBuddyManager* FUN_1418d8f90()
{
    return FUN_14097a780();
}

// @0x1418dcb70
CBuddyManager* FUN_1418dcb70()
{
    return FUN_14097a780();
}

// ---- UICommunityQueryDialog ----

// @0x1418da510
UICommunityQueryDialog::UICommunityQueryDialog()
    : m_180(0)
    , m_190(0)
{
    m_80 = 0;
    m_58 = 0;
    FUN_141924170(1);
    FUN_1422dc3b0(1);
}

// @0x1418da5e0
UICommunityQueryDialog::~UICommunityQueryDialog()
{
}

// @0x1418da650
int UICommunityQueryDialog::vfunc_65()
{
    return UIDialog::vfunc_65() != 0;
}

// @0x1418da680
void UICommunityQueryDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
    FUN_1418db6d0();
}

// @0x1418da6b0
void UICommunityQueryDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    FUN_1418db750();
}

// @0x1418da6e0
void UICommunityQueryDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    Unk_BuddyInput* pIn = static_cast<Unk_BuddyInput*>(p);
    if (pIn->FUN_14070fe80() == 0x61)
    {
        unsigned nPos = pIn->vfunc_0();
        Unk_BuddyResponse response;
        response.FUN_1407a3cc0(*pIn);
        pIn->FUN_140715280(nPos);
        if (response.protocol == 2 || response.protocol == 5 || response.protocol == 10 || response.protocol == 12)
            FUN_1418dba00(response);
    }
    else if (pIn->FUN_14070fe80() == 0x138)
    {
        unsigned nPos = pIn->vfunc_0();
        Unk_BdStream* pStream = &pIn->m_stream;
        unsigned char nResult = pStream->vfunc_1();
        pIn->FUN_140715280(nPos);
        if (nResult > 1 && (nResult < 4 || nResult == 5))
            vfunc_67();
    }
}

// @0x1418da870
CString UICommunityQueryDialog::vfunc_1()
{
    return CString("CommunityQueryDialog");
}

// MS2-FUNCTIONAL: the exe expands the AS callbacks inline with its own ASData/CString temporaries
// @0x1418da8c0
int UICommunityQueryDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnOk", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nMode = data.FUN_1422b8a10();
            m_188 = data.FUN_1422b8f40();
            m_1a0 = data.FUN_1422b8f40();
            FUN_1418dbcb0(nMode);
            return 1;
        }
    }
    else if (_stricmp("OnCancel", szMethod) == 0)
    {
        vfunc_67();
    }
    return 0;
}

// MS2-FUNCTIONAL: the exe expands the message box texts and the button branches inline
// @0x1418daa70
int UICommunityQueryDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520() == 0)
    {
        if (!dynamic_cast<UIPopUpMenu*>(pSender) && !dynamic_cast<UICommunityDialog*>(pSender) && !dynamic_cast<UIInviteMentoringDialog*>(pSender))
        {
            if (dynamic_cast<UIMessageBox*>(pSender))
            {
                if (pMsg->FUN_1422b8a10() == 0)
                {
                    CStringW strTag = pMsg->FUN_1422b8f40();
                    if (FUN_1403b3c40(strTag, L"delBuddy"))
                    {
                        Unk_BuddyRequest request;
                        request.protocol = 7;
                        request.id = m_190;
                        FUN_1418dcb70()->FUN_140ae4820(request);
                    }
                    else if (FUN_1403b3c40(strTag, L"delBanBuddy"))
                    {
                        Unk_BuddyRequest request;
                        request.protocol = 6;
                        request.id = m_190;
                        FUN_1418dcb70()->FUN_140ae4820(request);
                    }
                    else if (FUN_1403b3c40(strTag, L"banBuddy"))
                    {
                        CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker().get();
                        if (pChecker != 0)
                        {
                            CStringW strMessage;
                            if (pChecker->FUN_140226220(m_1a0, strMessage) == 0)
                            {
                                Unk_BuddyRequest request;
                                request.protocol = 5;
                                request.name = m_188;
                                request.memo = m_1a0.Trim();
                                request.id = m_190;
                                FUN_1418dcb70()->FUN_140ae4820(request);
                            }
                            else
                            {
                                FUN_140d73aa0(strMessage, 0, 0, CStringW(L""));
                            }
                        }
                    }
                    else if (FUN_1403b3c40(strTag, L"homeBlock"))
                    {
                        CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker().get();
                        if (pChecker != 0)
                        {
                            CStringW strMessage;
                            if (pChecker->FUN_140226220(m_1a0, strMessage) == 0)
                                FUN_1414a5830()->FUN_140a46f00(m_198, CStringW(m_1a0.Trim()));
                            else
                                FUN_140d73aa0(strMessage, 0, 0, CStringW(L""));
                        }
                    }
                    else if (FUN_1403b3c40(strTag, L"delHomeBlock"))
                    {
                        FUN_1414a5830()->FUN_140a47060(m_190);
                    }
                }
                else if (FUN_1409ee240(&m_30) != 0)
                {
                    static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("errorName");
                }
                FUN_14151f200();
            }
        }
        else
        {
            int nResult = pMsg->FUN_1422b8a10();
            m_180 = pMsg->FUN_1422b8a10();
            m_188 = pMsg->FUN_1422b8f40();
            m_190 = FUN_140718350(pMsg->FUN_1422b8d30());
            m_198 = FUN_140718350(pMsg->FUN_1422b8d30());
            if (nResult == 0)
            {
                if (m_180 == 0 || m_180 > 8)
                    return 1;
                if (vfunc_55() != 0)
                {
                    FUN_1403ed2b0()->FUN_141adc530(vfunc_48());
                    return 1;
                }
            }
            else if (nResult == 1)
            {
                if (m_180 == 6)
                    FUN_140d73aa0(FUN_14052bd00(0x5f8, m_188), 1, static_cast<IMessageListener*>(this), CStringW(L"delBuddy"));
                else if (m_180 == 7)
                    FUN_140d73aa0(FUN_14052bd00(0x5f9, m_188), 1, static_cast<IMessageListener*>(this), CStringW(L"delBanBuddy"));
                else if (m_180 == 8)
                    FUN_140d73aa0(FUN_14052bd00(0x5fa, m_188), 1, static_cast<IMessageListener*>(this), CStringW(L"delHomeBlock"));
            }
        }
    }
    return 0;
}

// @0x1418db5b0
int UICommunityQueryDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (vfunc_55() != 0)
        return 0;
    if (FUN_140a467d0(&m_30) != 0)
        return 0;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
    {
        static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("onEnterKey");
        return 1;
    }
    else if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0))
    {
        static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("onTabKey");
        return 1;
    }
    return 0;
}

// @0x1418db6d0
void UICommunityQueryDialog::FUN_1418db6d0()
{
    m_188 = L"";
    m_1a0 = L"";
    m_190 = 0;
    m_198 = 0;
    m_180 = 0;
}

// @0x1418db750
void UICommunityQueryDialog::FUN_1418db750()
{
    if (FUN_140a467d0(&m_30) == 0)
    {
        CStringW strName;
        if (m_180 == 1)
        {
            strName = FUN_14028de60(0x60a);
        }
        else if (m_180 == 4)
        {
            if (m_190 != 0)
            {
                CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4b70(m_190);
                if (spBuddy.get() != 0)
                    strName = *spBuddy->FUN_1401cc590();
            }
        }
        else if (m_180 == 5 && m_190 != 0)
        {
            HomeBlockManager::HomePtr spHome = FUN_1414a5830()->FUN_140a47490(m_190);
            if (spHome.get() != 0)
                strName = spHome->m_50;
        }
        static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1418dca10("initData", m_180, CStringW(m_188), CStringW(strName));
        vfunc_8(1);
    }
}

// @0x1418dba00
void UICommunityQueryDialog::FUN_1418dba00(Unk_BuddyResponse& response)
{
    if (response.result == 0)
    {
        vfunc_67();
    }
    else if (response.result == 10)
    {
        vfunc_67();
    }
    else
    {
        CString strUnused;
        if (response.result == 9)
            vfunc_67();
        switch (response.result)
        {
        case 1:
            FUN_141275260(0x614, 1, 1);
            break;
        case 2:
            FUN_140961010(0x622, 1, 1, response.name);
            break;
        case 3:
            FUN_140961010(0x621, 1, 1, response.name);
            break;
        case 4:
            FUN_140961010(0x617, 1, 1, response.name);
            break;
        case 5:
            FUN_140961010(0x61c, 1, 1, response.name);
            break;
        case 6:
            FUN_140961010(0x61b, 1, 1, response.name);
            break;
        case 7:
            FUN_140961010(0x61d, 1, 1, response.name);
            break;
        case 8:
            FUN_140961010(0x61e, 1, 1, response.name);
            break;
        case 9:
        case 0xb:
            FUN_140961010(0x602, 1, 1, response.name);
            break;
        default:
            FUN_141275260(0x613, 1, 1);
        }
        if (FUN_1409ee240(&m_30) != 0)
            static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("errorName");
    }
    FUN_1418db6d0();
}

// MS2-FUNCTIONAL: the exe expands each mode branch with its own CStringW temporaries
// @0x1418dbcb0
void UICommunityQueryDialog::FUN_1418dbcb0(int nMode)
{
    if (nMode == 1)
    {
        if (FUN_1418dc540(m_188) == 0)
        {
            CStringW strMemo(m_1a0.Trim());
            CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker().get();
            if (pChecker != 0)
            {
                CStringW strMessage;
                if (pChecker->FUN_140226260(strMemo, strMessage) == 0)
                {
                    Unk_BuddyRequest request;
                    request.protocol = 2;
                    request.name = m_188;
                    request.memo = strMemo;
                    FUN_1418dcb70()->FUN_140ae4820(request);
                    FUN_141276180(&s_strPcInviteSuccess, CString(""));
                }
                else
                {
                    FUN_140d73aa0(strMessage, 0, 0, CStringW(L""));
                }
            }
        }
    }
    else if (nMode == 2)
    {
        if (FUN_1418dc7f0(m_188) == 0)
        {
            CStringW strMemo(m_1a0.Trim());
            if (FUN_1418d3050(strMemo) != 0)
                FUN_140d73aa0(FUN_14052bd00(0x5fb, m_188), 1, static_cast<IMessageListener*>(this), CStringW(L"banBuddy"));
        }
    }
    else if (nMode == 3)
    {
        if (FUN_1418dc410(m_188) == 0)
        {
            CStringW strMemo(m_1a0.Trim());
            if (FUN_1418d3050(strMemo) != 0)
                FUN_140d73aa0(FUN_14052bd00(0x5fc, m_188), 1, static_cast<IMessageListener*>(this), CStringW(L"homeBlock"));
        }
    }
    else if (nMode == 4)
    {
        if (FUN_1418dc410(m_188) == 0)
        {
            CStringW strMemo(m_1a0.Trim());
            if (FUN_1418d3050(strMemo) != 0)
            {
                Unk_BuddyRequest request;
                request.protocol = 10;
                request.name = m_188;
                request.memo = strMemo;
                request.id = m_190;
                FUN_1418dcb70()->FUN_140ae4820(request);
            }
        }
    }
    else if (nMode == 5)
    {
        if (FUN_1418dc410(m_188) == 0)
        {
            CStringW strMemo(m_1a0.Trim());
            if (FUN_1418d3050(strMemo) != 0)
                FUN_1414a5830()->FUN_140a47c80(m_198, CStringW(m_188));
        }
    }
    else
    {
        vfunc_67();
    }
}

// @0x1418dc410
int UICommunityQueryDialog::FUN_1418dc410(const CStringW& str)
{
    bool bRejected = false;
    if (m_188.IsEmpty())
    {
        FUN_141275260(0x615, 1, 1);
        bRejected = true;
    }
    else
    {
        CStringW strOut;
        int nResult = FUN_141276c80(str, 1, strOut);
        if (nResult != 0)
        {
            FUN_141275260(nResult == 10 ? 0x616 : 0x614, 1, 1);
            bRejected = true;
        }
    }
    if (bRejected && FUN_1409ee240(&m_30) != 0)
        static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("errorName");
    return bRejected;
}

// MS2-FUNCTIONAL: the exe expands the four message branches with their own CStringW temporaries
// @0x1418dc540
int UICommunityQueryDialog::FUN_1418dc540(const CStringW& str)
{
    int bRejected;
    if (FUN_1418dc410(str) == 0)
    {
        bRejected = 0;
        CBuddyManager::Ptr spBuddy = FUN_1418dcb70()->FUN_140ae4950(str);
        if (spBuddy.get() != 0)
        {
            if (spBuddy->FUN_1401cc5b0() != 0)
            {
                FUN_140961010(0x619, 1, 1, spBuddy->FUN_1401cc1c0());
                bRejected = 1;
            }
            else if (spBuddy->FUN_1401cc660() != 0)
            {
                FUN_140961010(0x622, 1, 1, spBuddy->FUN_1401cc1c0());
                bRejected = 1;
            }
            else if (spBuddy->FUN_1401cc5d0() != 0)
            {
                FUN_140961010(0x61a, 1, 1, spBuddy->FUN_1401cc1c0());
                bRejected = 1;
            }
            else
            {
                FUN_140961010(0x621, 1, 1, spBuddy->FUN_1401cc1c0());
                bRejected = 1;
            }
        }
        if (bRejected != 0 && FUN_1409ee240(&m_30) != 0)
            static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("errorName");
    }
    else
    {
        bRejected = 1;
    }
    return bRejected;
}

// @0x1418dc7f0
int UICommunityQueryDialog::FUN_1418dc7f0(const CStringW& str)
{
    int bRejected;
    if (FUN_1418dc410(str) == 0)
    {
        bRejected = 0;
        CBuddyManager::Ptr spBuddy = FUN_1418dcb70()->FUN_140ae4950(str);
        if (spBuddy.get() != 0)
        {
            if (spBuddy->FUN_1401cc5b0() != 0)
            {
                FUN_140961010(0x620, 1, 1, spBuddy->FUN_1401cc1c0());
                bRejected = 1;
            }
        }
        if (bRejected != 0 && FUN_1409ee240(&m_30) != 0)
            static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("errorName");
    }
    else
    {
        bRejected = 1;
    }
    return bRejected;
}

// @0x1418dc940
bool FUN_1418dc940(void* p, const CStringW& str)
{
    bool bRejected = false;
    CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker().get();
    if (pChecker != 0)
    {
        CStringW strMessage;
        bRejected = pChecker->FUN_140226260(str, strMessage) != 0;
        if (bRejected)
            FUN_1412751f0(strMessage, 1, 1);
    }
    return bRejected;
}

// @0x1418dca10
Scaleform::GFx::Value Unk_BdScript::FUN_1418dca10(const char* szMethod, int n, CStringW a1, CStringW a2)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), n);
    FUN_1422bcea0(args.FUN_1409b1f70(1), (const wchar_t*)a1);
    FUN_1422bcea0(args.FUN_1409b1f70(2), (const wchar_t*)a2);
    return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(szMethod, args);
}

// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbcef0-0x142cbd080 .text$yd
