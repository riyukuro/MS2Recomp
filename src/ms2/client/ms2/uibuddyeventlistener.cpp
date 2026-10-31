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
// MS2-PIN: ?CallConstructors@?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@CAXPEAPEAVUIBuddyEventListener@@_K@Z 0x1418d9f80 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@CAXPEAPEAVUIBuddyEventListener@@_K@Z 0x1418d9ff0 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@QEBA_KXZ 0x1418da070 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@AEAA_N_K@Z 0x1418da080 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@PEAVUIBuddyEventListener@@@ATL@@SAXPEAPEAVUIBuddyEventListener@@0_K@Z 0x1418da230 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@QEAAXXZ 0x1418da270 ; unique
// MS2-PIN: ?RemoveAt@?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@QEAAX_K0@Z 0x1418da290 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@QEAA_N_KH@Z 0x1418da380 ; unique
// MS2-PIN: ??0?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@QEAA@XZ 0x1418d9d40
// MS2-PIN: ??1?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@QEAA@XZ 0x1418d9db0
// MS2-PIN: ??A?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@QEAAAEAPEAVUIBuddyEventListener@@_K@Z 0x1418da030
// MS2-PIN: ?Add@?$CAtlArray@PEAVUIBuddyEventListener@@V?$CElementTraits@PEAVUIBuddyEventListener@@@ATL@@@ATL@@QEAA_KAEBQEAVUIBuddyEventListener@@@Z 0x1418d9ed0
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
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/homeblockmanager.h"
#include "ms2/client/ms2/uiservice.h"
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
// the exe reads the buddy level as an int
struct Unk_BdBuddyLevel { int FUN_1401cc210(); };
CInputKeyHandler* FUN_14025e7c0();

// "m_list": the buddy list.
class Unk_BdList : public ASDisplayObject
{
public:
    MS2Ptr<ASDataProvider> FUN_1422dcd80();                 // the data provider
};

class Unk_BdStream { public: virtual void vfunc_0(); virtual unsigned char vfunc_1(); };
class Unk_BuddyInput { public: virtual unsigned vfunc_0(); Unk_BdStream m_stream; int FUN_14070fe80(); void FUN_140715280(unsigned); };
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);

CommonString* FUN_14025e7d0();                              // the CommonString singleton
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
CString FUN_140719530(unsigned __int64 n);                  // number to string
unsigned __int64 FUN_140718350(const CString& str);         // string -> id
unsigned __int64 FUN_140718370(const CStringW& str);        // string -> id
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& aOut, const wchar_t* szDelim);
class Unk_BdEntityEvents { public: void FUN_1419308c0(UIEntityEventListener* p); void FUN_141930950(UIEntityEventListener* p); };
class Unk_LsEntityEvents* FUN_140c607b0();   // C3: was FUN_140c607b0

// A counted reference to a CProxyGameObject (the entity events hand it by value; the callee destroys it).
struct Unk_BdProxyRef;
Unk_BdProxyRef* FUN_140ac58f0(Unk_BdProxyRef* pDst, const void* pSrc);
void FUN_1406c70a0(Unk_BdProxyRef* p);
struct Unk_BdProxyRef
{
    Unk_BdProxyRef() : m_unk_00(0), m_p(0) {}
    Unk_BdProxyRef(const void* pSrc) { FUN_140ac58f0(this, pSrc); }
    Unk_BdProxyRef(const Unk_BdProxyRef& other) { FUN_140ac58f0(this, &other); }
    ~Unk_BdProxyRef() { FUN_1406c70a0(this); }
    CProxyGameObject* operator->() const { return m_p; }
    bool IsNull() const { return m_p == 0; }
    CProxyGameObject* get() const { return m_p; }
    void* m_unk_00;
    CProxyGameObject* m_p;
};
MS2_CHECK_SIZE(Unk_BdProxyRef, 16);

// The actor of an entity id (a PC); slot 77 (+0x268) is its name.
class Unk_BdActor
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void
    vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual
    void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
    virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void
    vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22();
    virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void
    vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31();
    virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void
    vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); virtual void vfunc_40();
    virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void
    vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49();
    virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void
    vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58();
    virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void
    vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
    virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71(); virtual void
    vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76();
    virtual CStringW vfunc_77();
};

// The world service: the actor map and the proxies.
class Unk_BdWorld : public WorldService
{
public:
    void FUN_141bc9c60(Unk_BdProxyRef* pOut, __int64 nId);      // the proxy of a character id
    MS2Ptr<CProxyGameObject> FUN_141bc9c60(unsigned __int64 nId);  // the same, as the exe's by-value return
    Unk_BdActor* FUN_141bd1530(unsigned __int64 nId);           // the actor of an entity id
};
void FUN_140ac5dd0(void* pMap, void** pos);                     // GetNext

// The UI manager and the dialog finder.
class Unk_BdUIManager { public: void FUN_141adc530(int nUiId); };
class UICommunityQueryDialog* FUN_140ae5a30(int);   // C3: was FUN_140ae5a30

// The popup menu on a character (UI id 0x4e39) and its parameter block (as in uipartysearchdialog.cpp).
class Unk_PopupMenuInfo
{
public:
    Unk_PopupMenuInfo(float x, float y, int nKind, int nMenuId, int a5, CString strKey, void* p);   // 0x140c302f0
    ~Unk_PopupMenuInfo();                                                                         // 0x140c304c0
private:
    float m_x, m_y;
    int m_a, m_b, m_c;
    void* m_str;
    void* m_p;
    __int64 m_28, m_30, m_38, m_40, m_48;
    __int64 m_50, m_58, m_60, m_68, m_70, m_78;
};
class Unk_BdMenu
{
public:
    void FUN_141a7eb60(const Unk_PopupMenuInfo& info, MS2Ptr<CProxyGameObject> spProxy, int nType);     // menu on a visible character
    void FUN_141a7f950(const Unk_PopupMenuInfo& info, __int64 nId);                               // menu on a buddy
    void FUN_141a7fc50(const Unk_PopupMenuInfo& info, __int64 nId);                               // menu on a home block
};
class Unk_PopupMenu* FUN_140c30140(int);   // C3: was FUN_140c30140

// The settings / features / browser dialog used by the VIP/GM button.
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CFeatureManager   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14036d570(int);
};
class UIWebBrowser* FUN_140c43790(int);   // C3: was FUN_140c43790
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
void FUN_141276180(const CString& strSound, const CString& strExtra);
int FUN_141276c80(const CStringW& str, bool bCheckSelf, CStringW& strOut);
CStringW FUN_14052bd00(int nId, const CStringW& strArg);
void FUN_14151f200();
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);       // case-insensitive equal
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* szText);

// The string tables and the text formatters (they return the text through the hidden out pointer).
CStringW GetStringCommon(int nStringId);
CStringW FUN_14093fa20(int nId, const CStringW& str, int* pnArg);
CStringW FUN_1408116a0(int nId, int* pnArg);
CStringW FUN_140811740(int nId, int* pnA, int* pnB);
CStringW FUN_140a228f0(int nId, int* pnArg, const CStringW& str);
CStringW FUN_140c348b0(int nId, short* pnArg, const CStringW& str);
CString FUN_141028be0(unsigned __int64 nId, const CStringA& strImage, int a, CString str);
CStringW FUN_1409796e0(int a, int b, int c, CStringW str);
unsigned __int64 FUN_141b71960(const char* sz);
CStringTable* GetStringTable();

void FUN_140710590(COutPacket& packet);
CString* FUN_140298f80(void* p);
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

void FUN_1422dc3b0(UICommunityDialog* pDialog, int nBigList);   // the list mode of the window
CString FUN_141028a90(CString str, int n);                      // an image path

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
int FUN_1418d3050(const CStringW& strMemo, CStringW& strResult)
{
    if (CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker())
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
int FUN_1418d8ac0(ASObj* pRow);

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
    if (!UIDialog::vfunc_65())
        return 0;
    return 1;
}

// @0x1418d33a0
void UICommunityDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    UIUGCEventDispatcher::GetInstance()->FUN_141b38c70(static_cast<UIUGCEventListener*>(this));
    TSingleton<UIBuddyEventDispatcher>::GetInstance()->FUN_1418d94e0(static_cast<UIBuddyEventListener*>(this));
    ((class Unk_BdEntityEvents*)FUN_140c607b0())->FUN_141930950(static_cast<UIEntityEventListener*>(this));
    m_19c = 0;
    m_198 = 0;
    m_194 = 0;
    m_1a0 = 0;
}

// @0x1418d34a0
void UICommunityDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (vfunc_55() != 0)
        return;
    if (m_198 != 0 && m_190 == 1)
        m_194 = FUN_1418d76c0();
    m_198 = 0;
    if (m_19c != 0)
    {
        if (MS2Ptr<Unk_BdList> spList = FUN_1409ee290(&m_30)->FUN_140accef0<Unk_BdList>("m_list"))
        {
            int nCount = spList->FUN_1422dcd80()->FUN_1422bc5d0();
            FUN_1418d77f0(m_194, nCount);
        }
    }
    m_19c = 0;
}

// @0x1418d3650
void UICommunityDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1418d6980();
    UIUGCEventDispatcher::GetInstance()->FUN_141b38be0(static_cast<UIUGCEventListener*>(this));
    TSingleton<UIBuddyEventDispatcher>::GetInstance()->FUN_1418d9450(static_cast<UIBuddyEventListener*>(this));
    ((class Unk_BdEntityEvents*)FUN_140c607b0())->FUN_1419308c0(static_cast<UIEntityEventListener*>(this));
}

// @0x1418d3720
int UICommunityDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (vfunc_55())
        return 0;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
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
        int nResult = pMsg->FUN_1422b8a10();
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
    if (static_cast<Unk_BuddyInput*>(p)->FUN_14070fe80() != 0x61)
        return;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    unsigned nPos = static_cast<Unk_BuddyInput*>(p)->vfunc_0();
    Unk_BuddyResponse response;
    response.FUN_1407a3cc0(*static_cast<Unk_BuddyInput*>(p));
    static_cast<Unk_BuddyInput*>(p)->FUN_140715280(nPos);
    switch (response.protocol)
    {
    case 1:
        if (m_190 != 0)
            FUN_1418d6430(m_190);
        break;
    case 0xe:
        if (m_190 == 1)
        {
            if (response.flag == 0)
            {
                m_198 = 1;
                m_19c = 1;
            }
            else if (response.flag == 1)
            {
                m_198 = 1;
                m_19c = 1;
            }
        }
        break;
    }
}

// @0x1418d3bf0
CString UICommunityDialog::GetTypeName()
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
    else if (_stricmp("OnAddBan", szMethod) == 0)
    {
        FUN_1418d6ed0(0, 2);
        return 1;
    }
    else if (_stricmp("OnAddBuddy", szMethod) == 0)
    {
        FUN_1418d6ed0(0, 1);
        return 1;
    }
    else if (_stricmp("OnAcceptBuddy", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            Unk_BuddyRequest request;
            request.protocol = 3;
            request.id = FUN_140718350(data.FUN_1422b8d30());
            FUN_1418d8f90()->FUN_140ae4820(request);
            return 1;
        }
    }
    else if (_stricmp("OnDeclineBuddy", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            Unk_BuddyRequest request;
            request.protocol = 4;
            request.id = FUN_140718350(data.FUN_1422b8d30());
            FUN_1418d8f90()->FUN_140ae4820(request);
            return 1;
        }
    }
    else if (_stricmp("OnDeleteBuddy", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            Unk_BuddyRequest request;
            request.protocol = 7;
            request.id = FUN_140718350(data.FUN_1422b8d30());
            FUN_1418d8f90()->FUN_140ae4820(request);
            return 1;
        }
    }
    else if (_stricmp("OnCancelBuddy", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            Unk_BuddyRequest request;
            request.protocol = 0x11;
            request.id = FUN_140718350(data.FUN_1422b8d30());
            FUN_1418d8f90()->FUN_140ae4820(request);
            return 1;
        }
    }
    else if (_stricmp("onHomeVisit", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            __int64 nId = 0;
            int nKind = 0;
            unsigned __int64 nTarget = FUN_140718350(data.FUN_1422b8d30());
            CStringW strName;
            {
                CBuddyManager::Ptr spBuddy = FUN_1418d8f90()->FUN_140ae4b70(nTarget);
                if (spBuddy.get() != 0)
                {
                    nId = spBuddy->FUN_1401cc230();
                    nKind = 7;
                    strName = spBuddy->FUN_1401cc1c0();
                }
                else
                {
                    nId = nTarget;
                    nKind = 8;
                    Unk_BdActor* pActor = reinterpret_cast<Unk_BdWorld*>(WorldService::GetInstance())->FUN_141bd1530(nId);
                    if (pActor != 0)
                        strName = pActor->vfunc_77();
                }
            }
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
                MS2Ptr<CProxyGameObject> spProxy = reinterpret_cast<Unk_BdWorld*>(WorldService::GetInstance())->FUN_141bc9c60(nTarget);
                if (spProxy)
                {
                    Unk_BdMenu* pMenu = ((class Unk_BdMenu*)FUN_140c30140(0x4e39));
                    if (pMenu != 0)
                    {
                        Unk_PopupMenuInfo info(fX, fY, 3, 0x3f3fe, 1, "", 0);
                        pMenu->FUN_141a7eb60(info, spProxy, 8);
                        return 1;
                    }
                }
            }
            else if (m_190 == 4)
            {
                HomeBlockManager::HomePtr spHome = TSingleton<HomeBlockManager>::GetInstance()->FUN_140a47490(nTarget);
                if (spHome.get() != 0)
                {
                    Unk_BdMenu* pMenu = ((class Unk_BdMenu*)FUN_140c30140(0x4e39));
                    if (pMenu != 0)
                    {
                        Unk_PopupMenuInfo info(fX, fY, 3, 0x20046, 1, "", 0);
                        pMenu->FUN_141a7fc50(info, nTarget);
                        return 1;
                    }
                }
            }
            else
            {
                CBuddyManager::Ptr spBuddy = FUN_1418d8f90()->FUN_140ae4b70(nTarget);
                if (spBuddy.get() != 0)
                {
                    Unk_BdMenu* pMenu = ((class Unk_BdMenu*)FUN_140c30140(0x4e39));
                    if (pMenu != 0)
                    {
                        Unk_PopupMenuInfo info(fX, fY, 3, 0x63fe, 1, "", 0);
                        pMenu->FUN_141a7f950(info, nTarget);
                        return 1;
                    }
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
        CString strId = data.FUN_1422b8d30();
        __int64 nId = FUN_140718350(strId);
        if (CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker())
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
            TSingleton<HomeBlockManager>::GetInstance()->FUN_140a47c80(nId, strMemo);
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
        if (!((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x82))
            return 1;
        void* pBrowser = ((void*)FUN_140c43790(0x4e6a));
        if (pBrowser != 0)
        {
            CString strUrl = *FUN_140298f80(reinterpret_cast<char*>(((char*)FUN_1401d3200())) + 0x8838);
            FUN_14135ec00(pBrowser, strUrl, true);
        }
        COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
        packet.WriteUInt8(5);
        packet.WriteUInt8(1);
        FUN_140710590(packet);
        return 1;
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
            MS2Ptr<CProxyGameObject> spProxy = reinterpret_cast<Unk_BdWorld*>(WorldService::GetInstance())->FUN_141bc9c60(nId);
            if (spProxy.get())
                pTrophy = spProxy->FUN_1416c2950();
        }
        else
        {
            unsigned __int64 nId = FUN_141b71960(pArgs->FUN_1422b8d30());
            CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4b70(nId);
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
        CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4880((__int64)p);
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
    CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4b70(nId);
    if (spBuddy.get() != 0)
    {
        int bUpdate = (spBuddy->FUN_1401cc5d0() != 0 && m_190 == 2) || (spBuddy->FUN_1401cc5f0() != 0 && m_190 == 1)
            || (spBuddy->FUN_1401cc5b0() != 0 && m_190 == 3);
        if (bUpdate != 0)
            FUN_1418d73b0(m_190, CBuddyManager::Ptr(spBuddy));
    }
}

// @0x1418d5ae0
void UICommunityDialog::vfunc_buddy_11(__int64 nId)
{
    if (m_190 != 3)
        return;
    CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4b70(nId);
    if (spBuddy == NULL)
        return;
    int bBanned = spBuddy->FUN_1401cc5b0();
    if (bBanned == 0)
        return;
    CString strId = FUN_140719530(nId);
    m_30->FUN_140c38f00("updateBanMemo", CString(strId), CStringW(spBuddy->memo));
}

// @0x1418d5c60
void UICommunityDialog::vfunc_buddy_12(__int64 nId)
{
    if (m_190 != 4)
        return;
    HomeBlockManager::BuddyPtr spBuddy = TSingleton<HomeBlockManager>::GetInstance()->FUN_140a477f0(nId);
    if (spBuddy == NULL)
        return;
    FUN_1418d6430(4);
}

// @0x1418d5cf0
void UICommunityDialog::vfunc_buddy_13(__int64 nId)
{
    if (m_190 != 4)
        return;
    HomeBlockManager::HomePtr spHome = TSingleton<HomeBlockManager>::GetInstance()->FUN_140a47490(nId);
    if (spHome == NULL)
        return;
    CString strId = FUN_140719530(spHome->m_18);
    static_cast<Unk_BdScript*>(m_30.operator->())->FUN_1413127f0("updateBanMemo", CString(strId), CString(spHome->m_50));
}

// @0x1418d5e50
void UICommunityDialog::vfunc_buddy_14()
{
    if (m_190 != 4)
        return;
    FUN_1418d6430(4);
}

// @0x1418d5e90
void UICommunityDialog::vfunc_3(MS2Ptr<CProxyGameObject> spActor)
{
    if (reinterpret_cast<Unk_BdProxyRef*>(&spActor)->IsNull() || vfunc_55() != 0
        || (*reinterpret_cast<Unk_BdProxyRef*>(&spActor))->FUN_1416c2040() == 0)
    {
        return;
    }
    if (m_190 == 0)
    {
        ASObj obj(2);
        if (FUN_1418d8540(&obj, static_cast<const void*>(&spActor), 1) != 0)
        {
            m_19c = 1;
            m_30->Invoke("addBuddy", obj.FUN_1422bb870());
        }
    }
    else
        FUN_1418d6f80(0, 1, 1);
}

// @0x1418d6060
void UICommunityDialog::vfunc_4(MS2Ptr<CProxyGameObject> spActor)
{
    if (reinterpret_cast<Unk_BdProxyRef*>(&spActor)->IsNull() || vfunc_55() != 0
        || (*reinterpret_cast<Unk_BdProxyRef*>(&spActor))->FUN_1416c2040() == 0)
    {
        return;
    }
    if (m_190 != 0)
    {
        return;
    }
    m_19c = 1;
    {
        CString strId = FUN_140719530((unsigned __int64)(*reinterpret_cast<Unk_BdProxyRef*>(&spActor))->FUN_1416c22f0());
        m_30->Invoke("removeBuddy", CString(strId));
    }
}

// @0x1418d61d0
void UICommunityDialog::vfunc_5(MS2Ptr<CProxyGameObject> spActor, int n)
{
    if (reinterpret_cast<Unk_BdProxyRef*>(&spActor)->IsNull() || vfunc_55() != 0)
    {
        return;
    }
    if (m_190 != 0 || n == 0)
    {
        return;
    }
    n &= ~2;
    n &= ~1;
    if (n > 0)
    {
        ASObj obj(2);
        if (FUN_1418d8540(&obj, static_cast<const void*>(&spActor), 0) != 0)
            m_30->Invoke("updateBuddy", obj.FUN_1422bb870());
    }
}

// @0x1418d6390
bool UICommunityDialog::FUN_1418d6390(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        __int64 nParam = data.FUN_141a02ed0(0, 0);
        __int64 nId = data.FUN_141a02ed0(1, 0);
        int nType = data.FUN_141a02e50(2, 0);
        FUN_1418fd740(nParam, nId, nType);
    }
    return true;
}

// @0x1418d6410
void FUN_1418d6410(UICommunityDialog* pDialog)
{
    pDialog->m_190 = 0;
}

// @0x1418d6430
void UICommunityDialog::FUN_1418d6430(int nTab)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    int bSkip = 0;
    m_19c = 1;
    if (nTab == 0)
    {
        FUN_1418d6a90();
        bSkip = 1;
    }
    if (nTab == 4)
    {
        FUN_1418d6d00();
        bSkip = 1;
    }
    ASArray arr(2);
    ATL::CAtlArray<CBuddyManager::Ptr> buddies;
    FUN_1418d8f90()->FUN_140ae4df0(buddies);
    size_t nOnline = 0;
    size_t aCount[5] = {};
    if (!buddies.IsEmpty())
    {
        size_t nCount = buddies.GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            CBuddyManager::Ptr spBuddy(buddies[i]);
            if (spBuddy.get() != 0)
            {
                int bInclude = 0;
                if (spBuddy->FUN_1401cc660() != 0)
                {
                    bInclude = (nTab == 1);
                }
                else if (spBuddy->FUN_1401cc5f0() != 0)
                {
                    if (spBuddy->FUN_1401cc680() != 0)
                        nOnline++;
                    if (spBuddy->FUN_1401cc4d0() != 0)
                        aCount[1]++;
                    bInclude = (nTab == 1);
                }
                else if (spBuddy->FUN_1401cc5d0() != 0)
                {
                    aCount[2]++;
                    bInclude = (nTab == 2);
                }
                else if (spBuddy->FUN_1401cc5b0() != 0)
                {
                    if (spBuddy->FUN_1401cc4d0() != 0)
                        aCount[3]++;
                    bInclude = (nTab == 3);
                }
                if (bInclude == 0)
                    continue;
                ASObj row(2);
                FUN_1418d7b90(&row, CBuddyManager::Ptr(spBuddy), nTab);
                arr.FUN_1422bc050(row.FUN_1422bb870());
            }
        }
    }
    m_194 = (int)nOnline;
    if (bSkip == 0)
        m_30->FUN_140bd2cb0("buildBuddyList", arr);
    for (int i = 0; i < 5; i++)
        FUN_1418d6f80(i, aCount[i] > 0, (int)aCount[i]);
}

// @0x1418d6930
void UICommunityDialog::FUN_1418d6930(int nTab)
{
    if (nTab < 0 || nTab >= 5)
        return;
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
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    m_30->Invoke("initData", m_190);
}

// @0x1418d69f0
void UICommunityDialog::FUN_1418d69f0(int nTab)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    if (nTab < 0 || nTab >= 5)
        return;
    bool bShow = nTab == 3 || nTab == 4;
    FUN_1422dc3b0(bShow);
    m_190 = nTab;
    FUN_1418d6430(nTab);
}

// @0x1418d6a90
void UICommunityDialog::FUN_1418d6a90()
{
    ASArray arr(2);
    ASObj vipRow(2);
    if (FUN_1418d8ac0(&vipRow) != 0)
        arr.FUN_1422bc050(vipRow.FUN_1422bb870());
    int nCount = 0;
    void* pMap = reinterpret_cast<Unk_BdWorld*>(WorldService::GetInstance())->FUN_141bc9fb0();
    if (!((ATL::CAtlMap<unsigned int, MS2Ptr<CProxyGameObject>, ATL::CElementTraits<unsigned int>, ATL::CElementTraits<MS2Ptr<CProxyGameObject>>>*)(void*)(pMap))->IsEmpty())
    {
        for (void* pos = ((void*)((ATL::CAtlMap<unsigned int, MS2Ptr<CProxyGameObject>, ATL::CElementTraits<unsigned int>, ATL::CElementTraits<MS2Ptr<CProxyGameObject>>>*)(void*)(pMap))->GetStartPosition()); pos != 0; FUN_140ac5dd0(pMap, &pos))
        {
            Unk_BdProxyRef ref(((void*)&((ATL::CAtlMap<unsigned int, MS2Ptr<CProxyGameObject>, ATL::CElementTraits<unsigned int>, ATL::CElementTraits<MS2Ptr<CProxyGameObject>>>*)(void*)(pMap))->GetValueAt((struct __POSITION*)(pos))));
            if (ref.get() != 0 && (ref->FUN_1416c2040() != 0 || ref->FUN_1416c1ff0() != 0))
            {
                ASObj row(2);
                if (FUN_1418d8540(&row, ref, 0) != 0)
                {
                    arr.FUN_1422bc050(row.FUN_1422bb870());
                    nCount++;
                }
            }
        }
    }
    m_30->FUN_140bd2cb0("buildBuddyList", arr);
}

unsigned __int64 FUN_1418d90d0(void* it);
unsigned __int64 FUN_1418d90f0(void* it);

// @0x1418d6d00
void UICommunityDialog::FUN_1418d6d00()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    ASArray arr(2);
    std::vector<HomeBlockManager::BuddyPtr> vecBuddies;
    TSingleton<HomeBlockManager>::GetInstance()->FUN_140a47670(vecBuddies);
    // a range-for over raw element pointers (begin/end are 0x1418d90d0 / 0x1418d90f0)
    std::vector<HomeBlockManager::BuddyPtr>& range = vecBuddies;
    HomeBlockManager::BuddyPtr* pIt = (HomeBlockManager::BuddyPtr*)FUN_1418d90d0(&range);
    HomeBlockManager::BuddyPtr* pEnd = (HomeBlockManager::BuddyPtr*)FUN_1418d90f0(&range);
    for (; pIt != pEnd; ++pIt)
    {
        // HomeBlockManager::BuddyPtr and CBuddyManager::Ptr are the exe's one smart pointer type
        CBuddyManager::Ptr spBuddy(reinterpret_cast<const CBuddyManager::Ptr&>(*pIt));
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
    UIDialog* pDialog = ((class UIDialog*)FUN_140ae5a30(0x4e4e));
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
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    if (!spBuddy)
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
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    FUN_1418d7000(nTab, TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4b70(nId));
}

// @0x1418d7240
void UICommunityDialog::FUN_1418d7240(__int64 nId)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    CString strId = FUN_140719530(nId);
    if (m_190 == 1)
    {
        CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4b70(nId);
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
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    ASObj row(2);
    FUN_1418d7b90(&row, CBuddyManager::Ptr(spBuddy), nTab);
    m_30->Invoke("updateBuddy", row.FUN_1422bb870());
}

// @0x1418d74f0
void UICommunityDialog::FUN_1418d74f0(__int64 nId)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4b70(nId);
    if (spBuddy.get() != 0)
    {
        CString strId = FUN_140719530(nId);
        static_cast<Unk_BdScript*>(m_30.operator->())->FUN_1413127f0("updateBuddyProfile", CString(strId),
            FUN_141028be0(spBuddy->FUN_1401cc230(), *spBuddy->FUN_1401cc530(), 1, CString("")));
    }
}

// @0x1418d76c0
int UICommunityDialog::FUN_1418d76c0()
{
    ATL::CAtlArray<CBuddyManager::Ptr> buddies;
    FUN_1418d8f90()->FUN_140ae4df0(buddies);
    size_t nOnline = 0;
    if (!buddies.IsEmpty())
    {
        size_t nCount = buddies.GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            CBuddyManager::Ptr spBuddy(buddies[i]);
            if (spBuddy.get() != 0 && spBuddy->FUN_1401cc5f0() != 0 && spBuddy->FUN_1401cc680() != 0)
                nOnline++;
        }
    }
    return (int)nOnline;
}

// @0x1418d77f0
void UICommunityDialog::FUN_1418d77f0(int nOnline, int nTotal)
{
    CStringW strText;
    if (m_190 == 0)
    {
        int nMapId = reinterpret_cast<Unk_BdWorld*>(WorldService::GetInstance())->FUN_141bd3060();
        strText = FUN_14093fa20(0x60e, GetStringTable()->FUN_141811980(3, nMapId), &nTotal);
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
    pObj->FUN_1407cb9c0("total", static_cast<Unk_BdTrophy*>(pTrophy)->FUN_140267c10());
    pObj->FUN_1407cb9c0("combat", static_cast<Unk_BdTrophy*>(pTrophy)->FUN_140267d70(0));
    pObj->FUN_1407cb9c0("life", static_cast<Unk_BdTrophy*>(pTrophy)->FUN_140267d70(2));
    pObj->FUN_1407cb9c0("adventure", static_cast<Unk_BdTrophy*>(pTrophy)->FUN_140267d70(1));
}

// @0x1418d7b90
int FUN_1418d7b90(ASObj* pRow, CBuddyManager::Ptr spBuddy, int nTab)
{
    if (!spBuddy)
        return 0;
    {
        pRow->FUN_1407cbb20("charname", spBuddy->FUN_1401cc1c0());
        CString strAccount = FUN_140719530(spBuddy->FUN_1401cc2f0());
        __int64 nId = spBuddy->FUN_1401cc230();
        pRow->FUN_1407cba60("buddysn", CString(strAccount));
        CString strImgPath = FUN_141028be0(nId, *spBuddy->FUN_1401cc530(), 1, CString(""));
        pRow->FUN_1407cba60("imgpath", CString(strImgPath));
        int nWaiting = spBuddy->FUN_1401cc660();
        pRow->FUN_1407cb9c0("isWaiting", nWaiting);
        int bOnline = (spBuddy->FUN_1401cc680() == 0 || nWaiting != 0) ? 0 : 1;
        pRow->FUN_1407cbbe0("offline", bOnline == 0);
        pRow->FUN_1407cb9c0("trophyTotal", static_cast<Unk_BdTrophy*>(static_cast<void*>(spBuddy->FUN_1401cc330()))->FUN_140267c10());
        pRow->FUN_1407cb9c0("homeVisitEnable", FUN_1418fd530(nId));
        CStringW strState;
        if (bOnline != 0)
        {
            int nMapId = spBuddy->FUN_1401cc270();
            int nChannel = spBuddy->FUN_1401cc310();
            if (nChannel == 0)
            {
                strState = GetStringTable()->FUN_141811980(3, nMapId);
            }
            else
            {
                int nChannel2 = spBuddy->FUN_1401cc310();
                strState = FUN_140a228f0(0x60c, &nChannel2, GetStringTable()->FUN_141811980(3, nMapId));
            }
        }
        else if (nWaiting != 0)
        {
            strState = GetStringCommon(0x60b);
        }
        else
        {
            strState = GetStringCommon(0x60d);
        }
        int bParty = TSingleton<CPartyManager>::GetInstance()->FUN_14162afc0(nId).get() != 0;
        pRow->FUN_1407cb9c0("isParty", bParty);
        pRow->FUN_1407cbb20("state", CStringW(strState));
        int nLevel = reinterpret_cast<Unk_BdBuddyLevel*>(spBuddy.operator->())->FUN_1401cc210();
        CStringW strCharInfo = FUN_140a228f0(0x20, &nLevel, GetStringTable()->FUN_141811980(6, spBuddy->FUN_1401cc2b0()));
        pRow->FUN_1407cbb20("charinfo", CStringW(strCharInfo));
        pRow->FUN_1407cb9c0("isNew", spBuddy->FUN_1401cc4f0());
        pRow->FUN_1407cb9c0("recv", nTab == 2);
        if (nTab == 2)
        {
            pRow->FUN_1407cbb20("msg", CStringW(*spBuddy->FUN_1401cc550()));
        }
        else if (nTab == 1)
        {
            pRow->FUN_1407cbb20("address", FUN_1409796e0(spBuddy->FUN_1401cc3e0(), spBuddy->FUN_1401cc3a0(), spBuddy->FUN_1401cc3c0(), spBuddy->FUN_1401cc350()));
            pRow->FUN_1407cbb20("todaymemo", CStringW(*spBuddy->FUN_1401cc570()));
        }
        else
        {
            pRow->FUN_1407cbb20("memo", CStringW(*spBuddy->FUN_1401cc590()));
        }
        return 1;
    }
    return 0;
}

// @0x1418d8540
int FUN_1418d8540(ASObj* pRow, Unk_BdProxyRef ref, int bNew)
{
    if (ref.IsNull())
        return 0;
    {
        pRow->FUN_1407cbbe0("isPlayerInfo", true);
        pRow->FUN_1407cbb20("charname", ref->FUN_1416c23b0());
        __int64 nId = (__int64)ref->FUN_1416c22f0();
        CString strId = FUN_140719530(nId);
        pRow->FUN_1407cba60("buddysn", CString(strId));
        CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4880(nId);
        int bBuddy = (!spBuddy.operator!() && spBuddy->FUN_1401cc5f0() != 0) ? 1 : 0;
        pRow->FUN_1407cb9c0("isBuddy", bBuddy);
        int bParty = TSingleton<CPartyManager>::GetInstance()->FUN_14162afc0(nId).get() != 0;
        pRow->FUN_1407cb9c0("isParty", bParty);
        pRow->FUN_1407cba60("imgpath", FUN_141028be0(nId, ref->FUN_1416c2520(), 1, CString("")));
        short nLevel = (short)ref->FUN_1416c2330();
        CStringW strCharInfo = FUN_140c348b0(0x20, &nLevel, GetStringTable()->FUN_141811980(6, ref->FUN_1416c2390()));
        pRow->FUN_1407cbb20("charinfo", CStringW(strCharInfo));
        pRow->FUN_1407cb9c0("offline", 0);
        pRow->FUN_1407cbb20("address", ref->FUN_1416c2600());
        pRow->FUN_1407cbb20("todaymemo", ref->FUN_1416c2570());
        pRow->FUN_1407cb9c0("isNew", bNew);
        pRow->FUN_1407cb9c0("trophyTotal", static_cast<Unk_BdTrophy*>(static_cast<void*>(ref->FUN_1416c2950()))->FUN_140267c10());
        pRow->FUN_1407cb9c0("homeVisitEnable", FUN_1418fd530(nId));
        pRow->FUN_1407cbbe0("isVIPGM", false);
    }
    return 1;
}

// @0x1418d8ac0
int FUN_1418d8ac0(ASObj* pRow)
{
    if (!((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x82))
        return 0;
    pRow->FUN_1407cbbe0("isVIPGM", true);
    return 1;
}

// ---- UIBuddyEventListener / UIBuddyEventDispatcher (placeholders; bodies of this obj) ----


// @0x1418d90d0
unsigned __int64 FUN_1418d90d0(void* it)
{
    return *((unsigned __int64*)&((std::_Vector_alloc<std::_Vec_base_types<Unk_PayloadPtr<CBuddy>, std::allocator<Unk_PayloadPtr<CBuddy>>>>*)(void*)(it))->_Myfirst());
}

// @0x1418d90f0
unsigned __int64 FUN_1418d90f0(void* it)
{
    return *((unsigned __int64*)&((std::_Vector_alloc<std::_Vec_base_types<Unk_PayloadPtr<CBuddy>, std::allocator<Unk_PayloadPtr<CBuddy>>>>*)(void*)(it))->_Mylast());
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
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_1(nId);
    }
}

// @0x1418d9600
void UIBuddyEventDispatcher::vfunc_2(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_2(nId);
    }
}

// @0x1418d9690
void UIBuddyEventDispatcher::vfunc_3(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_3(nId);
    }
}

// @0x1418d9720
void UIBuddyEventDispatcher::vfunc_4(__int64 nId, int n)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_4(nId, n);
    }
}

// @0x1418d97b0
void UIBuddyEventDispatcher::vfunc_5(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_5(nId);
    }
}

// @0x1418d9840
void UIBuddyEventDispatcher::vfunc_6(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_6(nId);
    }
}

// @0x1418d98d0
void UIBuddyEventDispatcher::vfunc_7(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_7(nId);
    }
}

// @0x1418d9960
void UIBuddyEventDispatcher::vfunc_8(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_8(nId);
    }
}

// @0x1418d99f0
void UIBuddyEventDispatcher::vfunc_9(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_9(nId);
    }
}

// @0x1418d9a80
void UIBuddyEventDispatcher::vfunc_10(__int64 nId, int n)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_10(nId, n);
    }
}

// @0x1418d9b10
void UIBuddyEventDispatcher::vfunc_11(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_11(nId);
    }
}

// @0x1418d9ba0
void UIBuddyEventDispatcher::vfunc_12(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_12(nId);
    }
}

// @0x1418d9c30
void UIBuddyEventDispatcher::vfunc_13(__int64 nId)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_13(nId);
    }
}

// @0x1418d9cc0
void UIBuddyEventDispatcher::vfunc_14()
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIBuddyEventListener* pListener = m_8[i];
        if (pListener)
            pListener->vfunc_buddy_14();
    }
}

// ---- helper functions ----

// @0x1418d8f90
CBuddyManager* UICommunityDialog::FUN_1418d8f90()
{
    return TSingleton<CBuddyManager>::GetInstance();
}

// @0x1418dcb70
CBuddyManager* UICommunityQueryDialog::FUN_1418dcb70()
{
    return TSingleton<CBuddyManager>::GetInstance();
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
    if (!UIDialog::vfunc_65())
        return 0;
    return 1;
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
    if (static_cast<Unk_BuddyInput*>(p)->FUN_14070fe80() == 0x61)
    {
        unsigned nPos = static_cast<Unk_BuddyInput*>(p)->vfunc_0();
        Unk_BuddyResponse response;
        response.FUN_1407a3cc0(*static_cast<Unk_BuddyInput*>(p));
        static_cast<Unk_BuddyInput*>(p)->FUN_140715280(nPos);
        switch (response.protocol)
        {
        case 2:
        case 5:
        case 10:
        case 12:
            FUN_1418dba00(response);
            break;
        }
    }
    else if (static_cast<Unk_BuddyInput*>(p)->FUN_14070fe80() == 0x138)
    {
        unsigned nPos = static_cast<Unk_BuddyInput*>(p)->vfunc_0();
        int nResult = (&static_cast<Unk_BuddyInput*>(p)->m_stream)->vfunc_1();
        static_cast<Unk_BuddyInput*>(p)->FUN_140715280(nPos);
        switch (nResult)
        {
        case 2:
        case 3:
        case 5:
            vfunc_67();
            break;
        }
    }
}

// @0x1418da870
CString UICommunityQueryDialog::GetTypeName()
{
    return CString("CommunityQueryDialog");
}

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

// @0x1418daa70
int UICommunityQueryDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520())
        return 0;
    if (dynamic_cast<UIPopUpMenu*>(pSender) || dynamic_cast<UICommunityDialog*>(pSender) || dynamic_cast<UIInviteMentoringDialog*>(pSender))
    {
        int nResult = pMsg->FUN_1422b8a10();
        m_180 = pMsg->FUN_1422b8a10();
        m_188 = pMsg->FUN_1422b8f40();
        m_190 = FUN_140718350(pMsg->FUN_1422b8d30());
        m_198 = FUN_140718350(pMsg->FUN_1422b8d30());
        if (nResult == 0)
        {
            if (m_180 == 0 || m_180 >= 9)
                return 1;
            if (vfunc_55() != 0)
            {
                reinterpret_cast<Unk_BdUIManager*>(TSingleton<CUIService>::GetInstance())->FUN_141adc530(vfunc_48());
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
    else if (dynamic_cast<UIMessageBox*>(pSender))
    {
        int nButton = pMsg->FUN_1422b8a10();
        if (nButton == 0)
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
                if (CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker())
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
                if (CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker())
                {
                    CStringW strMessage;
                    if (pChecker->FUN_140226220(m_1a0, strMessage) == 0)
                        TSingleton<HomeBlockManager>::GetInstance()->FUN_140a46f00(m_198, CStringW(m_1a0.Trim()));
                    else
                        FUN_140d73aa0(strMessage, 0, 0, CStringW(L""));
                }
            }
            else if (FUN_1403b3c40(strTag, L"delHomeBlock"))
            {
                TSingleton<HomeBlockManager>::GetInstance()->FUN_140a47060(m_190);
            }
        }
        else if (((MS2Ptr<AScript>*)(void*)(&m_30))->get() != 0)
        {
            static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("errorName");
        }
        FUN_14151f200();
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
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
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
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    CStringW strName;
    if (m_180 == 1)
    {
        strName = GetStringCommon(0x60a);
    }
    else if (m_180 == 4)
    {
        if (m_190 > 0)
        {
            CBuddyManager::Ptr spBuddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4b70(m_190);
            if (spBuddy.get() != 0)
                strName = *spBuddy->FUN_1401cc590();
        }
    }
    else if (m_180 == 5 && m_190 > 0)
    {
        HomeBlockManager::HomePtr spHome = TSingleton<HomeBlockManager>::GetInstance()->FUN_140a47490(m_190);
        if (spHome.get() != 0)
            strName = spHome->m_50;
    }
    static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1418dca10("initData", m_180, CStringW(m_188), CStringW(strName));
    vfunc_8(1);
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
        case 7:
            FUN_140961010(0x61d, 1, 1, response.name);
            break;
        case 8:
            FUN_140961010(0x61e, 1, 1, response.name);
            break;
        case 6:
            FUN_140961010(0x61b, 1, 1, response.name);
            break;
        case 9:
        case 0xb:
            FUN_140961010(0x602, 1, 1, response.name);
            break;
        default:
            FUN_141275260(0x613, 1, 1);
        }
        if (((MS2Ptr<AScript>*)(void*)(&m_30))->get() != 0)
            static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("errorName");
    }
    FUN_1418db6d0();
}

// @0x1418dbcb0
void UICommunityQueryDialog::FUN_1418dbcb0(int nMode)
{
    switch (nMode)
    {
    case 1:
    {
        if (FUN_1418dc540(m_188) != 0)
            return;
        CStringW strMemo(m_1a0.Trim());
        if (CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker())
        {
            CStringW strMessage;
            if (pChecker->FUN_140226260(strMemo, strMessage) == 0)
            {
                Unk_BuddyRequest request;
                request.protocol = 2;
                request.name = m_188;
                request.memo = strMemo;
                FUN_1418dcb70()->FUN_140ae4820(request);
                CString strExtra("");
                FUN_141276180(s_strPcInviteSuccess, strExtra);
            }
            else
            {
                FUN_140d73aa0(strMessage, 0, 0, CStringW(L""));
            }
        }
    }
    break;
    case 2:
    {
        if (FUN_1418dc7f0(m_188) != 0)
            return;
        CStringW strMemo(m_1a0.Trim());
        CStringW strResult;
        if (FUN_1418d3050(strMemo, strResult) != 0)
            FUN_140d73aa0(FUN_14052bd00(0x5fb, m_188), 1, static_cast<IMessageListener*>(this), CStringW(L"banBuddy"));
    }
    break;
    case 3:
    {
        if (FUN_1418dc410(m_188) != 0)
            return;
        CStringW strMemo(m_1a0.Trim());
        CStringW strResult;
        if (FUN_1418d3050(strMemo, strResult) != 0)
            FUN_140d73aa0(FUN_14052bd00(0x5fc, m_188), 1, static_cast<IMessageListener*>(this), CStringW(L"homeBlock"));
    }
    break;
    case 4:
    {
        if (FUN_1418dc410(m_188) != 0)
            return;
        CStringW strMemo(m_1a0.Trim());
        CStringW strResult;
        if (FUN_1418d3050(strMemo, strResult) != 0)
        {
            Unk_BuddyRequest request;
            request.protocol = 10;
            request.name = m_188;
            request.memo = strMemo;
            request.id = m_190;
            FUN_1418dcb70()->FUN_140ae4820(request);
        }
    }
    break;
    case 5:
    {
        if (FUN_1418dc410(m_188) != 0)
            return;
        CStringW strMemo(m_1a0.Trim());
        CStringW strResult;
        if (FUN_1418d3050(strMemo, strResult) != 0)
            TSingleton<HomeBlockManager>::GetInstance()->FUN_140a47c80(m_190, CStringW(strMemo)); // the exe passes the buddy id (+0x190) and the trimmed memo
    }
    break;
    default:
        vfunc_67();
        break;
    }
}

// @0x1418dc410
int UICommunityQueryDialog::FUN_1418dc410(const CStringW& str)
{
    int bRejected = 0;
    if (m_188.IsEmpty())
    {
        FUN_141275260(0x615, 1, 1);
        bRejected = 1;
    }
    if (bRejected == 0)
    {
        CStringW strOut;
        int nResult = FUN_141276c80(str, true, strOut);
        if (nResult != 0)
        {
            int nMsg = nResult == 10 ? 0x616 : 0x614;
            FUN_141275260(nMsg, 1, 1);
            bRejected = 1;
        }
    }
    if (bRejected != 0 && ((MS2Ptr<AScript>*)(void*)(&m_30))->get() != 0)
        static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("errorName");
    return bRejected;
}

// @0x1418dc540
int UICommunityQueryDialog::FUN_1418dc540(const CStringW& str)
{
    if (FUN_1418dc410(str) != 0)
        return 1;
    int bRejected = 0;
    {
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
    }
    if (bRejected != 0 && ((MS2Ptr<AScript>*)(void*)(&m_30))->get() != 0)
        static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("errorName");
    return bRejected;
}

// @0x1418dc7f0
int UICommunityQueryDialog::FUN_1418dc7f0(const CStringW& str)
{
    if (FUN_1418dc410(str) != 0)
        return 1;
    int bRejected = 0;
    {
        CBuddyManager::Ptr spBuddy = FUN_1418dcb70()->FUN_140ae4950(str);
        if (spBuddy.get() != 0)
        {
            if (spBuddy->FUN_1401cc5b0() != 0)
            {
                FUN_140961010(0x620, 1, 1, spBuddy->FUN_1401cc1c0());
                bRejected = 1;
            }
        }
    }
    if (bRejected != 0 && ((MS2Ptr<AScript>*)(void*)(&m_30))->get() != 0)
        static_cast<Unk_BdScript*>(FUN_1409ee290(&m_30))->FUN_1422bb330("errorName");
    return bRejected;
}

// @0x1418dc940
int FUN_1418dc940(void* p, const CStringW& str, void* pUnused)
{
    int bRejected = 0;
    if (CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker())
    {
        CStringW strMessage;
        if (pChecker->FUN_140226260(str, strMessage) != 0)
        {
            FUN_1412751f0(strMessage, 1, 1);
            bRejected = 1;
        }
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
