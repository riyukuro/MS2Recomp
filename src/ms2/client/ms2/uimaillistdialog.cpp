// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMailListDialog: see uimaillistdialog.h.
// MS2-UNIT: ?\uimaillistdialog.cpp
// MS2-RANGE: 0x140116000-0x140116360 .text$di
// MS2-RANGE: 0x1419e3510-0x1419ee140 .text$mn
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUIMailListDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@6B@ 0x142fbefc0
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUIMailListDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@6B@ 0x142fbefe8
// MS2-PIN: ??1TMailAdBillDataParam@@UEAA@XZ 0x1419ea450
// MS2-PIN: ?IsNull@?$MS2Ptr@VCMailInfo@@@@QEBA_NXZ 0x1419ea470
// MS2-PIN: ?Maximum@?$CRBTree@_JV?$MS2Ptr@VCMailInfo@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMailInfo@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1419eaf40
// MS2-PIN: ?Predecessor@?$CRBTree@_JV?$MS2Ptr@VCMailInfo@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCMailInfo@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1419eb2d0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMailListDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419ebc60
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMailListDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419ebc00
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimaillistdialog.cpp"    // assumed

// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"

#include "uimaillistdialog.h"
#include "uidailymissiondialog.h"   // C3: UIDailyMissionDialog::FUN_140c02870 (the tab strip lookup)

#include <stdlib.h>
#include <algorithm>
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/client/ms2/networkservice.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/usermail.h"
#include "ms2/commonfiles/commonpricerecord.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/client/ms2/uimarketbilldialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/cmailtypes.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/weddingmanager.h"   // C3: TSingleton<> needs the class
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Check (0x140268870)
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce090
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/formatstringid.h"

template <> MS2Ptr<ASTextInput> UISwfEntity::GetChild<ASTextInput>(const CString& strName);   // 0x140e35bd0, owned by uiinventorydialog

template <> MS2Ptr<ASScrollingList> UISwfEntity::GetChild<ASScrollingList>(const CString& strName);   // 0x140c02900, owned by uiinventorydialog

// ---- statics of the unit's headers (two copies of the merat market sort names / key controller block) ----

static CString s_strSortTypeNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strSortTypeNamesLike2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput2;

// ---- unit-local views of exe objects ----

// The SWF dialog object handed around by the UI library (the exe's dynamic_cast target).
class ASDialog : public ASDisplayObject
{
public:
    virtual void vfunc_2(int, int, int);
    Scaleform::GFx::Value FUN_140ba4cc0(const char* szMethod, const ASObj& a1);      // invoke with an object
};

// The page buttons of the movie ("m_prev" / "m_next").
template <> MS2Ptr<ASButton> UISwfEntity::GetChild<ASButton>(const CString& strName);   // 0x140bb4b10, owned by uiinventorydialog
// "m_checkAll".

class Unk_PopupMenuInfo
{
public:
    Unk_PopupMenuInfo(float x, float y, int a, int b, int c, CString str, void* p);   // 0x140c302f0
    ~Unk_PopupMenuInfo() {}                                         // 0x140c304c0
private:
    struct Unk_PmA                                                  // ctor 0x140c30440, dtor 0x140c30550
    {
        Unk_PmA() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(0) {}
        void* m_00; void* m_08; CStringW m_10; int m_18; void* m_20;
    };
    struct Unk_PmB                                                  // ctor 0x140c303c0, dtor 0x140c30510
    {
        Unk_PmB() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(L"") {}
        void* m_00; int m_08; CStringW m_10; void* m_18; CStringW m_20;
    };
    float m_x, m_y;
    int m_a, m_b, m_c;
    CString m_str;
    void* m_p;
    Unk_PmA m_infoA;
    Unk_PmB m_infoB;
};
class UIPopUpMenu { public: void FUN_141a7f090(const Unk_PopupMenuInfo& info, const CStringW& strName, unsigned __int64 nSerial, void* p, int b, int c); };
class Unk_PopupMenu* FindPopupMenu(int nId);                              // the open popup menu dialog
class Unk_InventoryStateManager* GetBlockManager();   // C3: was GetBlockManager
void FUN_140a30ad0(const BlockPtr& spBlock, int nAction, unsigned __int64 n);     // the "blocked" notice


extern CUserMail g_143ab2ee0;                                       // the user's mails
extern int DAT_143af37b0;                                           // the mail list needs a refresh (scenestategame.cpp)
extern int DAT_143af37b4;                                           // a mail was removed
extern __int64 DAT_143af37b8;                                       // the mail to open

template <class T> T* Unk_SSGGetDialog(int nId);                     // scenestategame.cpp (0x141742fb0 for the send dialog)
CStringW FUN_141b71910(__int64 n);                                  // number -> text
unsigned __int64 ParseUInt64W(const CStringW& text);               // text -> number
CStringW FUN_14016a730(const char* psz, int n);                     // multibyte -> wide
CStringW GetStringCommon(int nStrId);                                 // string table text by id
CStringW GetStringCommonByKey(const CStringW& strKey);                     // string table text by key
void FUN_14025a680(CStringW& text, ATL::CAtlArray<CStringW>& out, const wchar_t* pszSep);   // split
void ShowMessageBox(CStringW text, int nType, void* pListener, CStringW tag);       // notice box
void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW tag);          // notice box by string id
MS2Ptr<CMsgBoxData> CreateMessageBox(int nType, CStringW text, void* pListener, CStringW tag);   // create a message box
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* pListener, CStringW tag);      // create one by string id
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                        // show it
void FUN_141275260(int nStrId, int nA, int nB);                     // system notice
float Ceil(float f);                                       // ceil
void RemoveMailItemSlot(const CStringA& strKey);                         // drop a registered item tooltip
void CreateMailItemSlot(const CStringA& strKey, MS2Ptr<CItem> spItem, int nCount, int nSlot);   // register an item tooltip
CStringW FUN_1409404f0(__int64 n);                                  // an amount as text
CStringW FUN_1418fec00(int nPayType, __int64 nAmount, bool bIcon);  // a price as text
int GetPayType(int nPriceType);                                  // price kind -> pay type
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                       // the item data of an id
UIMarketBillDialog* FindMarketBillDialog(int nUiType);                     // the open dialog of a UI id
class WorldService   // C3: member view for the former free stand-ins
{
public:
    static WorldService* GetInstance();
    void* GetLocalPlayer();
};
__int64 GetServerTime();                                            // the server time

class PCBase;

// C3: the wedding ticket mail goes to WeddingManager::ReadTicketMail(MS2Ptr<CMailInfo>, AScript*)
// (placeholder/weddingmanager.h, 0x141b873c0); CUserMail::MailPtr is MS2Ptr<CMailInfo>.
//

// ---- UIMailSendDialog's views ----

// "m_receiver" / "m_title": the text inputs (the receiver one gets the name candidates).
// "m_buddys": the buddy name dropdown (slot 24 refreshes it).
template <> MS2Ptr<ASDropdownMenu> UISwfEntity::GetChild<ASDropdownMenu>(const CString& strName);   // 0x140c28560, owned by uiinventorydialog
// The send request (receiver, title, content), written by FUN_1401fc2a0 (three wide strings).
struct Unk_MailSendInfo
{
    CStringW m_strReceiver;
    CStringW m_strTitle;
    CStringW m_strContent;
};
void FUN_1401fc2a0(unsigned char* payload, COutputStream& stream);   // unit_1401f9eb0.h
// CommonString as the send dialog calls it: the ban word checker.
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
int FUN_1418fccc0(int nMsg, unsigned __int64 wParam, unsigned __int64 lParam, CStringW* pStr);   // the key edits the text
CStringW FUN_1413fa9b0(const CStringW& str);                        // lower case
CStringW XmlWide(const char* psz);                            // UTF-8 -> wide
void ShowSystemNotice(const CStringW& text, int nA, int nB);           // system notice text
extern __int64 DAT_143ab2828;                                       // the own character id

// The mail is an ad mail (kind 200).
// @0x1419ead90
int IsAdMail(CMailInfo* pMail)
{
    return pMail->GetKind() == 200;
}

// The ad mail is sold out.
// @0x1419eadd0
int IsAdSoldOut(CMailInfo* pMail)
{
    return pMail->m_n130;
}

// The text translator of the system mails (sender / title keys -> text).
CStringW GetDaysLeftString(CMailInfo* pMail, int bTooltip);             // the "days left" text of a row

// @0x1419ea470: MS2Ptr<CMailInfo>::IsNull (usermail.h)

// The meso of the mail (the plain sum while unclaimed plus the meso benefit).
// @0x1419e9160
__int64 GetMesoAmount(CMailInfo* pMail)
{
    __int64 nTotal = 0;
    if (pMail->GetRangeB0Begin() != 0 && pMail->GetRangeB0Claim() == 0)
        nTotal = nTotal + pMail->GetRangeB0Begin();
    Unk_CommonPriceRecord rec;
    if (pMail->FindBenefit(0, 0, reinterpret_cast<Unk_MailBenefit*>(&rec)) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    return nTotal;
}
MS2_REPLACE(0x1419E9160, GetMesoAmount, 148, 0x1A71F3E1); // GetMesoAmount

// The merat of the mail (the four merat benefit kinds).
// @0x1419e9200
__int64 GetMeratAmount(CMailInfo* pMail)
{
    __int64 nTotal = 0;
    if (pMail->GetRangeC0Begin() != 0 && pMail->FUN_140690e60() == 0)
        nTotal = nTotal + pMail->GetRangeC0Begin();
    Unk_CommonPriceRecord rec;
    if (pMail->FindBenefit(2, 0, reinterpret_cast<Unk_MailBenefit*>(&rec)) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    if (pMail->FindBenefit(2, 1, reinterpret_cast<Unk_MailBenefit*>(&rec)) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    if (pMail->FindBenefit(2, 2, reinterpret_cast<Unk_MailBenefit*>(&rec)) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    if (pMail->FindBenefit(2, 3, reinterpret_cast<Unk_MailBenefit*>(&rec)) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    return nTotal;
}
MS2_REPLACE(0x1419E9200, GetMeratAmount, 331, 0x58E184B6); // GetMeratAmount

// The red merat of the mail.
// @0x1419e9360
__int64 GetMeratRedAmount(CMailInfo* pMail)
{
    __int64 nTotal = 0;
    if (pMail->FUN_140690ed0() != 0 && pMail->FUN_140690ef0() == 0)
        nTotal = nTotal + pMail->FUN_140690ed0();
    Unk_CommonPriceRecord rec;
    if (pMail->FindBenefit(8, 0, reinterpret_cast<Unk_MailBenefit*>(&rec)) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    return nTotal;
}
MS2_REPLACE(0x1419E9360, GetMeratRedAmount, 151, 0xE2DAA05F); // GetMeratRedAmount

// A benefit amount as price text.
// @0x1419e9400
CStringW FUN_1419e9400(int nPriceType, __int64 nAmount)
{
    int nPayType = GetPayType(nPriceType);
    return FUN_1418fec00(nPayType, nAmount, false);
}
MS2_REPLACE(0x1419E9400, FUN_1419e9400, 82, 0xFF1E0FE6); // FUN_1419e9400

// The other benefits (not meso / merat kinds 2 and 8) as "token1".."tokenN" members.
// @0x1419e9460
void FUN_1419e9460(CMailInfo* pMail, ASObj& info)
{
    Unk_MailBenefitList& list = pMail->GetBenefits();
    int nCount = reinterpret_cast<Unk_CommonPriceRecordList&>(list).GetCount();
    if (0 < nCount)
    {
        ATL::CAtlArray<Unk_MailBenefit>& benefits = list.m_array;
        int nToken = 1;
        for (int i = 0; i < nCount; i++)
        {
            Unk_MailBenefit& benefit = benefits.GetAt(i);
            if (benefit.m_nType == 2)
                continue;
            if (benefit.m_nType == 8)
                continue;
            if (benefit.m_nSub != 0)
                continue;
            __int64 nAmount = reinterpret_cast<Unk_CommonPriceRecord&>(benefit).GetAvailableAmount();
            if (nAmount == 0)
                continue;
            CStringW strPrice = FUN_1419e9400(benefit.m_nType, nAmount);
            CStringA strKey = StringFormat("token{0}", nToken);
            nToken++;
            info.SetWStringMember(strKey, CStringW(strPrice));
        }
    }
}
MS2_REPLACE(0x1419E9460, FUN_1419e9460, 362, 0xB651066D); // FUN_1419e9460

// The "days left" text of a row (bTooltip: the long form).
// @0x1419e95d0
CStringW GetDaysLeftString(CMailInfo* pMail, int bTooltip)
{
    CMsTime now(GetServerTime());
    CMsTime expire(pMail->GetExpireTime());
    if (now > expire)
        return GetStringCommon(0x80b);
    ATL::CTimeSpan span = expire - now;
    CStringW str;
    if (span.GetDays() < 1)
    {
        if (bTooltip != 0)
        {
            __int64 nMinutes = span.GetTotalSeconds() / 60 % 60;
            __int64 nHours = span.GetTotalSeconds() / 3600;
            str = FormatStringId(0x80a, nHours, nMinutes);
        }
        else
        {
            str = GetStringCommon(0x809);
        }
    }
    else
    {
        int nStrId = bTooltip ? 0x808 : 0x807;
        str = FormatStringId(nStrId, span.GetDays());
    }
    return str;
}
MS2_REPLACE(0x1419E95D0, GetDaysLeftString, 624, 0x1F41E57F); // GetDaysLeftString

// ---- UIMailListDialog ----

// @0x1419e3510
UIMailListDialog::UIMailListDialog()
    : m_mapChecked(17, 0.75f, 0.25f, 2.25f, 10), m_bRefresh(false)
{
    SetTweenEnabled(1);
    m_nPage = 0;
}

// @0x1419e35e0
UIMailListDialog::~UIMailListDialog()
{
}

// @0x1419e3630
CString UIMailListDialog::GetTypeName()
{
    return "MailListDialog";
}
MS2_REPLACE_METHOD(0x1419E3630, UIMailListDialog, GetTypeName, 61, 0xDC6C2DCB); // UIMailListDialog::vfunc_1

// @0x1419e3680
int UIMailListDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1419E3680, UIMailListDialog, vfunc_65, 37, 0xFEA3F0C1); // UIMailListDialog::vfunc_65

// @0x1419e36b0
void UIMailListDialog::vfunc_67()
{
    ClearAttachmentTooltips();
    UIDialog::vfunc_67();
    m_bRefresh = false;
}
MS2_REPLACE_METHOD(0x1419E36B0, UIMailListDialog, vfunc_67, 46, 0x574EDA7E); // UIMailListDialog::vfunc_67

// @0x1419e36f0
void UIMailListDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_mapChecked.RemoveAll();
    m_nPage = 0;
    UpdatePageText();
    SendMailMode0();
}
MS2_REPLACE_METHOD(0x1419E36F0, UIMailListDialog, OnLoadComplete, 78, 0x5B61BC99); // UIMailListDialog::OnLoadComplete

// @0x1419e3750
void UIMailListDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
}
MS2_REPLACE_METHOD(0x1419E3750, UIMailListDialog, vfunc_79, 34, 0xABDD3A3E); // UIMailListDialog::vfunc_79

// @0x1419e3780
int UIMailListDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    return 0;
}

// @0x1419e4de0
void UIMailListDialog::vfunc_15()
{
    if (m_30.IsNull())
        return;
    if (DAT_143af37b0 != 0)
    {
        DAT_143af37b0 = 0;
        RefreshMailList();
        __int64 nOpen = FUN_1419e6c30();
        if (nOpen != 0)
            SetMailInfo(nOpen);
    }
    if (DAT_143af37b8 != 0)
    {
        SetMailInfo(DAT_143af37b8);
        DAT_143af37b8 = 0;
    }
    if (DAT_143af37b4 != 0)
    {
        OnMailRemoved();
        DAT_143af37b4 = 0;
        FUN_141275260(0x22a, 1, 1);
    }
    if (m_bRefresh && m_timer.Check(1000) != 0)
        SendMailMode0();
}
MS2_REPLACE_METHOD(0x1419E4DE0, UIMailListDialog, vfunc_15, 252, 0x4FCFDE97); // UIMailListDialog::vfunc_15

// An empty member (no caller and no vftable slot in the exe; the parameter is pointer-sized).
// @0x1419e4ef0
void UIMailListDialog::FUN_1419e4ef0(void* p)
{
}
MS2_REPLACE_METHOD(0x1419E4EF0, UIMailListDialog, FUN_1419e4ef0, 11, 0x02239C70); // FUN_1419e4ef0

// @0x1419e4f10
void UIMailListDialog::OnMailRemoved()
{
    ATL::CAtlList<CUserMail::MailPtr> mails(10);
    GetTabMails(mails);
    int nLast = (std::max)(1, (int)Ceil((float)mails.GetCount() / 14.0f));
    if (m_nPage >= nLast)
    {
        m_nPage = nLast - 1;
        UpdatePageText();
    }
    RefreshMailList();
    SetMailInfo(0);
}
MS2_REPLACE_METHOD(0x1419E4F10, UIMailListDialog, OnMailRemoved, 227, 0x6B05EF4E); // OnMailRemoved

// @0x1419e5000
void UIMailListDialog::OnReadMail(__int64 nMailId)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
        static_cast<AScript*>(pDlg)->Invoke("readMail", FUN_141b71910(nMailId));
    UpdateMailCount();
}
MS2_REPLACE_METHOD(0x1419E5000, UIMailListDialog, OnReadMail, 167, 0xCFAD7E71); // OnReadMail

// @0x1419e50b0
void UIMailListDialog::OnReceiveMail(__int64 nMailId)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
        static_cast<AScript*>(pDlg)->Invoke("receiveMail", FUN_141b71910(nMailId));
}
MS2_REPLACE_METHOD(0x1419E50B0, UIMailListDialog, OnReceiveMail, 154, 0x92C96AA2); // OnReceiveMail

// @0x1419e5150
void UIMailListDialog::RequestRefresh()
{
    m_bRefresh = true;
    m_timer.Init();
}
MS2_REPLACE_METHOD(0x1419E5150, UIMailListDialog, RequestRefresh, 45, 0xA826AB8A); // RequestRefresh

// @0x1419e5900
void UIMailListDialog::UpdateMailCount()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
    {
        int nUser = 0;
        int nSystem = 0;
        for (int nKind = 1; nKind < 4; nKind++)
            nUser += g_143ab2ee0.CountUnreadMailsByKind(nKind);
        for (int nKind = 100; nKind < 0x71; nKind++)
            nSystem += g_143ab2ee0.CountUnreadMailsByKind(nKind);
        pDlg->FUN_1409ba0d0("onMailCount", nUser, nSystem);
    }
}
MS2_REPLACE_METHOD(0x1419E5900, UIMailListDialog, UpdateMailCount, 258, 0x4973165E); // UpdateMailCount

// @0x1419e5a10
void UIMailListDialog::SetMailInfo(__int64 nMailId)
{
    ClearAttachmentTooltips();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
    {
        ASObj info(2);
        {
            CUserMail::MailPtr spMail = g_143ab2ee0.FindMailById(nMailId);
            if (spMail.get() != 0)
            {
                CStringW strSender = spMail->GetSenderName();
                CStringW strTitle = spMail->GetTitle();
                CStringW strContent = spMail->GetContent();
                int nKind = spMail->GetKind();
                if (nKind >= 100 && nKind < 0x71)
                {
                    TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectAndValueWords(strSender);
                    TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectAndValueWords(strTitle);
                    TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectAndValueWords(strContent);
                }
                if (nKind == 0x70)
                {
                    ASObj wedding(2);
                    TSingleton<WeddingManager>::GetInstance()->ReadTicketMail(CUserMail::MailPtr(spMail), &wedding);
                    info.FUN_1409eb270("wedding", wedding);
                }
                info.SetWStringMember("sender", CStringW(strSender));
                info.SetWStringMember("title", CStringW(strTitle));
                info.SetWStringMember("content", CStringW(strContent));
                info.SetIntMember("attachment", spMail->HasAttachment());
                info.SetStringMember("state", GetMailStateName(CUserMail::MailPtr(spMail)));
                info.SetIntMember("binding", BindAttachmentTooltips(spMail.get()));
                info.SetWStringMember("date", spMail->GetDateString());
                __int64 nMeso = GetMesoAmount(spMail.get());
                __int64 nMerat = GetMeratAmount(spMail.get());
                __int64 nMeratRed = GetMeratRedAmount(spMail.get());
                if (0 < nMeso)
                    info.SetWStringMember("meso", FUN_1409404f0(nMeso));
                if (0 < nMerat)
                    info.SetWStringMember("merat", FUN_1409404f0(nMerat));
                if (0 < nMeratRed)
                    info.SetWStringMember("meratRed", FUN_1409404f0(nMeratRed));
                FUN_1419e9460(spMail.get(), info);
                switch (spMail->GetKind())
                {
                case 3:
                    info.SetBoolMember("disableReply", true);
                    break;
                case 200:
                    info.SetWStringMember("productName", spMail->GetAdProductName());
                    info.SetStringMember("price", Unk_SocketFormat("{0}", spMail->FUN_140692510()));
                    info.SetStringMember("salePrice", Unk_SocketFormat("{0}", spMail->FUN_1406925a0()));
                    info.SetIntMember("expired", spMail->FUN_140692630());
                    break;
                default:
                    if (spMail->GetKind() >= 1 && spMail->GetKind() < 4)
                        info.SetBoolMember("visibleUserMailIcon", true);
                    break;
                }
            }
        }
        m_30->Invoke("setMailInfo", info);
    }
}
MS2_REPLACE_METHOD(0x1419E5A10, UIMailListDialog, SetMailInfo, 1959, 0xC519097B); // SetMailInfo

// @0x1419e61c0
void UIMailListDialog::SendMailMode2(__int64 nMailId)
{
    CMailInfo* pMail = g_143ab2ee0.FindMailById(nMailId).get();
    if (pMail == 0)
        return;
    if (pMail->GetReadTime() == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Mail), 0);
        packet.Encode1(2);
        packet.Encode8(pMail->GetId());
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x1419E61C0, UIMailListDialog, SendMailMode2, 199, 0x9CBB1495); // SendMailMode2

// @0x1419e6290
void UIMailListDialog::SendMailMode11(__int64 nMailId)
{
    CMailInfo* pMail = g_143ab2ee0.FindMailById(nMailId).get();
    if (pMail == 0)
        return;
    if (pMail->FUN_140690b80() == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Mail), 0);
    packet.Encode1(0xb);
    packet.Encode8(pMail->GetId());
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1419E6290, UIMailListDialog, SendMailMode11, 200, 0x09F47CCF); // SendMailMode11

// @0x1419e6360
void UIMailListDialog::ReplyToMail(__int64 nMailId)
{
    CMailInfo* pMail = g_143ab2ee0.FindMailById(nMailId).get();
    if (pMail == 0)
        return;
    UIMailSendDialog* pSend = Unk_SSGGetDialog<UIMailSendDialog>(0x4e4a);
    if (pSend != 0)
        pSend->SetReplyMail(pMail);
    CUIService::GetInstance()->ToggleDialog((eUIClassID)0x4e4a);
}
MS2_REPLACE_METHOD(0x1419E6360, UIMailListDialog, ReplyToMail, 156, 0x946298AD); // ReplyToMail

// @0x1419e67a0
unsigned UIMailListDialog::BindAttachmentTooltips(CMailInfo* pMail)
{
    if (pMail == 0)
        return 0;
    unsigned nCount = 0;
    if (IsAdMail(pMail) != 0)
    {
        for (int i = 0; i < 5; i++)
        {
            MS2Ptr<CMailAdItem> spAd = pMail->GetAd(i);
            if (spAd)
            {
                CItem* pItem = new CItem();
                if (pItem->FUN_14052b130(spAd->m_n18, spAd->m_n20, 0) != 0)
                {
                    pItem->SetCountClamped(spAd->m_n1c);
                    CStringA strKey;
                    strKey.Format("%s.%d", (const char*)GetTypeName(), nCount);
                    CreateMailItemSlot(strKey, MS2Ptr<CItem>(pItem), spAd->m_n24, i);
                    nCount++;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            Unk_MailAttachPtr spAttach = pMail->GetAttachment(i);
            if ((spAttach.get() != 0 ? true : false) && spAttach->m_nTime == 0)
            {
                CStringA strKey;
                strKey.Format("%s.%d", (const char*)GetTypeName(), nCount);
                CreateMailItemSlot(strKey, spAttach->m_item, spAttach->m_n20, i);
                nCount++;
            }
        }
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x1419E67A0, UIMailListDialog, BindAttachmentTooltips, 957, 0x72309694); // BindAttachmentTooltips

// @0x1419e6b70
void UIMailListDialog::ClearAttachmentTooltips()
{
    for (int i = 0; i < 5; i++)
    {
        CStringA strKey;
        strKey.Format("%s.%d", (const char*)GetTypeName(), i);
        RemoveMailItemSlot(strKey);
    }
}
MS2_REPLACE_METHOD(0x1419E6B70, UIMailListDialog, ClearAttachmentTooltips, 174, 0x75771166); // ClearAttachmentTooltips

// @0x1419e6c30
__int64 UIMailListDialog::FUN_1419e6c30()
{
    if (m_30 == 0)
        return 0;
    CStringA strId = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(m_30->Invoke("getMailID")))->GetString();
    if (strId.GetLength() != 0)
        return atoi(strId);
    return 0;
}
MS2_REPLACE_METHOD(0x1419E6C30, UIMailListDialog, FUN_1419e6c30, 234, 0x978463E6); // FUN_1419e6c30

// @0x1419e6ec0
int UIMailListDialog::IsMailInCurrentTab(MS2Ptr<CMailInfo> spMail)
{
    if (GetSelectedTab() == 1)
    {
        for (int nKind = 1; nKind < 4; nKind++)
        {
            if (spMail->GetKind() == nKind)
                return 1;
        }
    }
    else
    {
        for (int nKind = 100; nKind < 0x71; nKind++)
        {
            if (spMail->GetKind() == nKind)
                return 1;
        }
        if (IsAdMail(spMail.get()) != 0)
            return 1;
    }
    return 0;
}

// @0x1419e6fe0
int UIMailListDialog::IsPageValid(int nPage)
{
    int nCount = 0;
    if (GetSelectedTab() == 1)
    {
        for (int nKind = 1; nKind < 4; nKind++)
            nCount += g_143ab2ee0.GetMailCountByKind(nKind);
    }
    else
    {
        for (int nKind = 100; nKind < 0x71; nKind++)
            nCount += g_143ab2ee0.GetMailCountByKind(nKind);
    }
    int nPages = (int)Ceil((float)nCount / 14.0f);
    if (nPage < 0 || nPage >= nPages)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1419E6FE0, UIMailListDialog, IsPageValid, 210, 0xE322023D); // IsPageValid

// @0x1419e70c0
int UIMailListDialog::FUN_1419e70c0(CStringW strIds)
{
    ATL::CAtlArray<CStringW> aIds;
    FUN_14025a680(strIds, aIds, L",");
    if (aIds.GetCount() == 0)
        return 0;
    ATL::CAtlArray<unsigned __int64> aUnused;
    for (size_t i = 0; i < aIds.GetCount(); i++)
    {
        unsigned __int64 nId = ParseUInt64W(aIds[i]);
        CUserMail::MailPtr spMail = g_143ab2ee0.FindMailById(nId);
        if (spMail.get() != 0 && spMail->HasAttachment() != 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419E70C0, UIMailListDialog, FUN_1419e70c0, 395, 0xB40CDF74); // FUN_1419e70c0

// @0x1419e7260
CStringA UIMailListDialog::GetMailStateName(MS2Ptr<CMailInfo> spMail)
{
    if (IsAdMail(spMail.operator->()) != 0)
    {
        if (IsAdSoldOut(spMail.operator->()) != 0)
            return "ad";
        return "ad_attached";
    }
    else
    {
        if (spMail->GetKind() == 0x70)
            return "wedding_invitation";
        if (spMail->HasAttachment() != 0)
            return "attached";
        return "non_attached";
    }
}

// @0x1419e73f0
void UIMailListDialog::UpdatePageText()
{
    if (MS2Ptr<ASTextField> spPage = GetChild<ASTextField>("m_page"))
    {
        int nShown = m_nPage + 1;
        spPage->SetTextW(StringFormat<int>(L"{0}", nShown));
    }
}
MS2_REPLACE_METHOD(0x1419E73F0, UIMailListDialog, UpdatePageText, 225, 0x8A7532B9); // UpdatePageText

// @0x1419e7fd0
int UIMailListDialog::GetSelectedTab()
{
    if (MS2Ptr<ASButtonBar> spTab = reinterpret_cast<UIDailyMissionDialog*>(this)->GetButtonBar("m_tab"))
        return spTab.operator->()->GetSelectedIndex();
    return -1;
}
MS2_REPLACE_METHOD(0x1419E7FD0, UIMailListDialog, GetSelectedTab, 166, 0x6BAF5A08); // GetSelectedTab

// @0x1419e8b70
bool UIMailListDialog::FUN_1419e8b70(Scaleform::GFx::Value* pRetVal, ASData& data, MS2Ptr<TMarketBillDataParam> spParam)
{
    if (m_30 == 0)
        return false;
    if (spParam == 0)
        return false;
    Scaleform::GFx::Value vArg = data.PopValue();
    ASObj obj(vArg, 2);
    if (obj.IsUndefinedOrNull())
        return false;
    MS2Ptr<TMailAdBillDataParam> spMailParam(dynamic_cast<TMailAdBillDataParam*>(spParam.get()));
    if (spMailParam == 0)
        return true;
    __int64 nMailId = spMailParam->m_nMailId;
    CMailInfo* pMail = g_143ab2ee0.FindMailById(nMailId).get();
    if (pMail == 0)
        return true;
    int nBillIndex = data.PopUInt();
    MS2Ptr<ASBillData> spBill = spParam->GetBill(nBillIndex);
    if (spBill == 0)
        return false;
    MS2Ptr<ASMailAdBillData> spAdBill(dynamic_cast<ASMailAdBillData*>(spBill.get()));
    if (spAdBill == 0)
        return false;
    MS2Ptr<CMailAdItem> spAd = pMail->GetAd(spAdBill->vfunc_5());
    if (spAd == 0)
        return false;
    PCBase* pPlayer = ((class PCBase*)WorldService::GetInstance()->GetLocalPlayer());
    ASTooltip tip(pPlayer, 0x20, 2);
    if (tip.FUN_1409e1770(spAd->m_n18, spAd->m_n20) != 0)
        *pRetVal = tip.GetValue();
    return true;
}

// @0x1419e90d0
void UIMailListDialog::SendMailMode0()
{
    if (m_30 == 0 || FUN_1422dc430() == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Mail), 0);
    packet.Encode1(0);
    FUN_140710590(packet);
    m_bRefresh = false;
}
MS2_REPLACE_METHOD(0x1419E90D0, UIMailListDialog, SendMailMode0, 128, 0xBD218E6E); // SendMailMode0

// @0x1419e37d0
int UIMailListDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    else if (_stricmp("onSelectMail", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            __int64 nMailId = atoi(data.FUN_1422b8d30());
            SetMailInfo(nMailId);
            SendMailMode2(nMailId);
        }
        return 1;
    }
    else if (_stricmp("onSendMail", szMethod) == 0)
    {
        {
            BlockPtr spBlock = ((class CBlockManager*)GetBlockManager())->FindBlockedAction(0xb);
            if (spBlock.get() != 0)
            {
                FUN_140a30ad0(spBlock, 0xb, 0);
                return 1;
            }
        }
        CUIService::GetInstance()->OpenDialog((eUIClassID)0x4e4a);
        return 1;
    }
    else if (_stricmp("onSelectTab", szMethod) == 0)
    {
        m_nPage = 0;
        RefreshMailList();
        SetMailInfo(0);
        UpdatePageText();
        m_mapChecked.RemoveAll();
    }
    else if (_stricmp("onRecieveAll", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            __int64 nMailId = atoi(data.FUN_1422b8d30());
            SendMailMode11(nMailId);
        }
    }
    else if (_stricmp("onReply", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            __int64 nMailId = atoi(data.FUN_1422b8d30());
            ReplyToMail(nMailId);
        }
    }
    else if (_stricmp("onRemove", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            __int64 nMailId = atoi(data.FUN_1422b8d30());
            FUN_1419e6410(nMailId);
        }
    }
    else if (_stricmp("onPrevPage", szMethod) == 0)
    {
        if (IsPageValid(m_nPage - 1) != 0)
        {
            m_nPage = m_nPage - 1;
            RefreshMailList();
            UpdatePageText();
            m_mapChecked.RemoveAll();
            if (MS2Ptr<ASCheckBox> spCheck = GetChild<ASCheckBox>("m_checkAll"))
                spCheck->SetSelected(0);
        }
    }
    else if (_stricmp("onNextPage", szMethod) == 0)
    {
        if (IsPageValid(m_nPage + 1) != 0)
        {
            m_nPage = m_nPage + 1;
            RefreshMailList();
            UpdatePageText();
            m_mapChecked.RemoveAll();
            if (MS2Ptr<ASCheckBox> spCheck = GetChild<ASCheckBox>("m_checkAll"))
                spCheck->SetSelected(0);
        }
    }
    else if (_stricmp("onReadList", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            CStringW strIds = FUN_14016a730(data.FUN_1422b8d30(), 0);
            MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, GetStringCommon(0x22d), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->AddStringArg(CStringW(strIds));
                spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::SendMailMode18));
                FUN_140d73c60(spBox);
            }
        }
    }
    else if (_stricmp("onDeleteList", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            CStringW strIds = FUN_14016a730(data.FUN_1422b8d30(), 0);
            if (FUN_1419e70c0(CStringW(strIds)) != 0)
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x19, 0x231, 0, CStringW(L""));
                if (spBox.get() != 0)
                {
                    spBox->SetButtonPreset(1);
                    spBox->SetCheckbox0(GetStringCommon(0x232), 0);
                    spBox->AddStringArg(CStringW(strIds));
                    spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::FUN_1419e7940));
                    FUN_140d73c60(spBox);
                }
            }
            else
            {
                MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, GetStringCommon(0x22e), 0, CStringW(L""));
                if (spBox.get() != 0)
                {
                    spBox->AddStringArg(CStringW(strIds));
                    spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::FUN_1419e7940));
                    FUN_140d73c60(spBox);
                }
            }
        }
    }
    else if (_stricmp("onReceiveList", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            CStringW strIds = FUN_14016a730(data.FUN_1422b8d30(), 0);
            MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, GetStringCommon(0x22f), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->AddStringArg(CStringW(strIds));
                spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::SendMailMode19));
                FUN_140d73c60(spBox);
            }
        }
    }
    else if (_stricmp("onClickMailCheckbox", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            unsigned __int64 nMailId = ParseUInt64W(data.FUN_1422b8f40());
            int bChecked = data.PopBool();
            m_mapChecked.SetAt(nMailId, bChecked);
        }
    }
    else if (_stricmp("onRClickMailSender", szMethod) == 0)
    {
        do
        {
            ASData data;
            if (data.SetArgsIfAny(pArgs, nArgs) == 0)
                break;
            unsigned __int64 nMailId = ParseUInt64W(data.FUN_1422b8f40());
            CStringW strSender = data.FUN_1422b8f40();
            float fX = data.PopFloat();
            float fY = data.PopFloat();
            CUserMail::MailPtr spMail = g_143ab2ee0.FindMailById(nMailId);
            if (spMail.IsNull())
                break;
            if (spMail->GetKind() != 1)
                break;
            UIPopUpMenu* pMenu = (UIPopUpMenu*)FindPopupMenu(0x4e39);
            if (pMenu == 0)
                break;
            Unk_PopupMenuInfo info(fX, fY, 3, 0x50, 0, "", 0);
            pMenu->FUN_141a7f090(info, strSender, 0, 0, 0, 1);
        } while (0);
    }
    else if (_stricmp("onBuyAd", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            unsigned __int64 nMailId = ParseUInt64W(data.FUN_1422b8f40());
            OnBuyAd(nMailId);
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419E37D0, UIMailListDialog, vfunc_28, 5626, 0x102D767A); // UIMailListDialog::vfunc_28

// @0x1419e6410
void UIMailListDialog::FUN_1419e6410(__int64 nMailId)
{
    if (nMailId == 0)
    {
        FUN_140d73bc0(0x23d, 0, 0, CStringW(L""));
        return;
    }
    CUserMail::MailPtr spMail = g_143ab2ee0.FindMailById(nMailId);
    if (spMail == 0)
        return;
    int nStrId = 0x235;
    if (IsAdMail(spMail.operator->()) != 0)
    {
        if (spMail->FUN_140692630() != 0)
        {
            COutPacket packet(static_cast<int>(SendOp::Mail), 0);
            packet.Encode1(0xd);
            packet.Encode4(1);
            packet.Encode8(spMail->GetId());
            FUN_140710590(packet);
            return;
        }
        if (IsAdSoldOut(spMail.operator->()) == 0)
            nStrId = 0x236;
    }
    else
    {
        if (spMail->HasAttachment() != 0)
            nStrId = 0x237;
    }
    MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, GetStringCommon(nStrId), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->AddStringArg(FUN_141b71910(nMailId));
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::SendMailMode13));
        FUN_140d73c60(spBox);
    }
}
MS2_REPLACE_METHOD(0x1419E6410, UIMailListDialog, FUN_1419e6410, 902, 0xCFF9DD01); // FUN_1419e6410

// @0x1419e6d20
void UIMailListDialog::GetTabMails(ATL::CAtlList<CUserMail::MailPtr>& out)
{
    ATL::CRBMultiMap<__int64, CUserMail::MailPtr> byTime(10);
    CUserMail::MailArray& mails = g_143ab2ee0.GetMails();
    for (size_t i = 0; i < mails.GetCount(); i++)
    {
        CUserMail::MailPtr spMail = mails.GetAt(i);
        if (IsMailInCurrentTab(CUserMail::MailPtr(spMail)) != 0)
        {
            if (IsAdMail(spMail.operator->()) != 0)
                out.AddTail(spMail);
            else
                byTime.Insert(spMail->FUN_1406911c0(), spMail);
        }
    }
    for (POSITION pos = byTime.GetTailPosition(); pos != 0; byTime.GetPrev(pos))
    {
        CUserMail::MailPtr spMail = byTime.GetValueAt(pos);
        out.AddTail(spMail);
    }
}
MS2_REPLACE_METHOD(0x1419E6D20, UIMailListDialog, GetTabMails, 400, 0x6E86303A); // GetTabMails

// @0x1419e74e0
int UIMailListDialog::HasLockedAttachment(__int64 nMailId)
{
    CUserMail::MailPtr spMail = g_143ab2ee0.FindMailById(nMailId);
    if (spMail.get() != 0)
    {
        for (int i = 0; i < 5; i++)
        {
            Unk_MailAttachPtr spAttach = spMail->GetAttachment(i);
            if (spAttach.get() != 0)
            {
                if (spAttach->m_nTime > 0)
                    continue;
                if ((spAttach->m_item.get() ? true : false) && spAttach->m_item->FUN_140528e20())
                    return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419E74E0, UIMailListDialog, HasLockedAttachment, 335, 0xE1BB44D8); // HasLockedAttachment

// @0x1419e7640
bool UIMailListDialog::SendMailMode18(int nButton, const CMsgBoxData& data)
{
    if (nButton != 0)
        return true;
    CStringW strIds = data.FUN_141a02fd0(0, CStringW());
    ATL::CAtlArray<__int64> aIds;
    ParseMailIds(CStringW(strIds), aIds, 0);
    COutPacket packet(static_cast<int>(SendOp::Mail), 0);
    packet.Encode1(0x12);
    packet.Encode4((int)aIds.GetCount());
    for (size_t i = 0; i < aIds.GetCount(); i++)
        packet.Encode8(aIds[i]);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1419E7640, UIMailListDialog, SendMailMode18, 377, 0x270B2582); // SendMailMode18

// @0x1419e77c0
bool UIMailListDialog::SendMailMode19(int nButton, const CMsgBoxData& data)
{
    if (nButton != 0)
        return true;
    CStringW strIds = data.FUN_141a02fd0(0, CStringW());
    ATL::CAtlArray<__int64> aIds;
    ParseMailIds(CStringW(strIds), aIds, 0);
    COutPacket packet(static_cast<int>(SendOp::Mail), 0);
    packet.Encode1(0x13);
    packet.Encode4((int)aIds.GetCount());
    for (size_t i = 0; i < aIds.GetCount(); i++)
        packet.Encode8(aIds[i]);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1419E77C0, UIMailListDialog, SendMailMode19, 377, 0x97E3EE98); // SendMailMode19

// @0x1419e7940
bool UIMailListDialog::FUN_1419e7940(int nButton, const CMsgBoxData& data)
{
    if (nButton != 0)
        return true;
    CStringW strIds = data.FUN_141a02fd0(0, CStringW());
    CStringW strInput = data.FUN_141a02d50();
    int bFound = strInput.Find(L"true", 0) != -1 ? 1 : 0;
    ATL::CAtlArray<__int64> aIds;
    ParseMailIds(CStringW(strIds), aIds, bFound == 0 ? 1 : 0);
    for (size_t i = 0; i < aIds.GetCount(); i++)
    {
        if (HasLockedAttachment(aIds[i]) != 0)
        {
            ShowMessageBox(GetStringCommonByKey(L"s_itemlock_mail_remove"), 0, 0, CStringW(L""));
            return true;
        }
    }
    COutPacket packet(static_cast<int>(SendOp::Mail), 0);
    packet.Encode1(0xd);
    packet.Encode4((int)aIds.GetCount());
    for (size_t i = 0; i < aIds.GetCount(); i++)
        packet.Encode8(aIds[i]);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1419E7940, UIMailListDialog, FUN_1419e7940, 812, 0x6BFE17E1); // FUN_1419e7940

// @0x1419e7c80
bool UIMailListDialog::SendMailMode13(int nButton, const CMsgBoxData& data)
{
    if (nButton != 0)
        return true;
    __int64 nMailId = ParseUInt64W(data.FUN_141a02fd0(0, CStringW()));
    if (HasLockedAttachment(nMailId) != 0)
    {
        ShowMessageBox(GetStringCommonByKey(L"s_itemlock_mail_remove"), 0, 0, L"");
        return true;
    }
    if (CMailInfo* pMail = g_143ab2ee0.FindMailById(nMailId).get())
    {
        COutPacket packet(static_cast<int>(SendOp::Mail), 0);
        packet.Encode1(0xd);
        packet.Encode4(1);
        packet.Encode8(pMail->GetId());
        FUN_140710590(packet);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1419E7C80, UIMailListDialog, SendMailMode13, 534, 0x573E56A5); // SendMailMode13

// @0x1419e7ea0
void UIMailListDialog::ParseMailIds(CStringW strIds, ATL::CAtlArray<__int64>& aIds, int bSkipAttached)
{
    ATL::CAtlArray<CStringW> aTexts;
    FUN_14025a680(strIds, aTexts, L",");
    for (size_t i = 0; i < aTexts.GetCount(); i++)
    {
        __int64 nMailId = ParseUInt64W(aTexts[i]);
        CUserMail::MailPtr spMail = g_143ab2ee0.FindMailById(nMailId);
        if (spMail.get() != 0)
        {
            if (spMail->HasAttachment() != 0 && bSkipAttached != 0)
                continue;
            aIds.Add(nMailId);
        }
    }
}
MS2_REPLACE_METHOD(0x1419E7EA0, UIMailListDialog, ParseMailIds, 291, 0x201EBD4F); // ParseMailIds

// @0x1419e5190
void UIMailListDialog::RefreshMailList()
{
    __int64 nOpen = FUN_1419e6c30();
    int nSelect = -1;
    if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_list"))
    {
        spList->FUN_1422dd1d0();
        ATL::CAtlList<CUserMail::MailPtr> mails(10);
        GetTabMails(mails);
        int nIndex = -1;
        int nRow = 0;
        for (POSITION pos = mails.GetHeadPosition(); pos != 0; mails.GetNext(pos))
        {
            nIndex++;
            if (nIndex < m_nPage * 14)
                continue;
            if (nIndex >= m_nPage * 14 + 14)
                break;
            CMailInfo* pMail = mails.GetAt(pos).get();
            if (pMail->IsExpired() != 0)
                continue;
            int bSelect = 0;
            m_mapChecked.Lookup(pMail->GetId(), bSelect);
            CStringW strSender = pMail->GetSenderName();
            CStringW strTitle = pMail->GetTitle();
            int nKind = pMail->GetKind();
            if (nKind >= 100 && nKind < 0x71)
            {
                TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectAndValueWords(strSender);
                TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectAndValueWords(strTitle);
            }
            ASObj row(2);
            row.SetWStringMember("mailSN", FUN_141b71910(pMail->GetId()));
            row.SetWStringMember("sender", CStringW(strSender));
            row.SetWStringMember("content", CStringW(strTitle));
            row.SetWStringMember("date", GetDaysLeftString(pMail, 0));
            row.SetWStringMember("dateTooltip", GetDaysLeftString(pMail, 1));
            row.SetIntMember("read", pMail->IsRead());
            row.SetIntMember("attachment", pMail->HasAttachment());
            row.SetIntMember("select", bSelect);
            row.SetIntMember("adMail", IsAdMail(pMail));
            row.SetIntMember("adSoldout", IsAdSoldOut(pMail));
            row.SetIntMember("adExpired", pMail->FUN_140692630());
            spList->AddItem(row);
            if (pMail->GetId() == nOpen)
                nSelect = nRow;
            nRow++;
        }
        spList->vfunc_24(true);
        spList->SetSelectedIndex(nSelect);
    }
    UpdateMailCount();
    if (MS2Ptr<ASButton> spPrev = GetChild<ASButton>("m_prev"))
        spPrev->SetEnabled(IsPageValid(m_nPage - 1));
    if (MS2Ptr<ASButton> spNext = GetChild<ASButton>("m_next"))
        spNext->SetEnabled(IsPageValid(m_nPage + 1));
    if (MS2Ptr<ASCheckBox> spCheck = GetChild<ASCheckBox>("m_checkAll"))
        spCheck->SetSelected(0);
}
MS2_REPLACE_METHOD(0x1419E5190, UIMailListDialog, RefreshMailList, 1889, 0x75FE8B86); // RefreshMailList

// @0x1419e8080
bool UIMailListDialog::OnBuyAd(unsigned __int64 nMailId)
{
    MS2Ptr<TMailAdBillDataParam> spParam = FUN_1419e8620("mailAd");
    if (spParam == 0)
        return false;
    UIMarketBillDialog* pBillDialog = FindMarketBillDialog(0x4f17);
    if (pBillDialog == 0)
        return false;
    CMailInfo* pMail = g_143ab2ee0.FindMailById(nMailId).get();
    if (pMail == 0)
        return false;
    unsigned int nPrice = (unsigned int)pMail->FUN_1406925a0();
    if (!FUN_140d86260()->vfunc_40(nPrice))
    {
        CUIService::GetInstance()->FUN_141add1f0();
        return false;
    }
    int nCurrency = 3;
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = spParam->m_bills;
    for (size_t i = 0; i < 5; i++)
    {
        MS2Ptr<CMailAdItem> spAd = pMail->GetAd((int)i);
        if (spAd == 0)
            continue;
        MS2Ptr<CItemData> spItemData = FUN_14053f870(spAd->m_n18);
        if (spItemData == 0)
            continue;
        MS2Ptr<ASMailAdBillData> spBill(new ASMailAdBillData());
        spBill->SetIconFromItem(spItemData, spAd->m_n20);
        spBill->SetItemName(TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spAd->m_n18));
        spBill->SetSalePrice(FUN_1418fec00(nCurrency, spAd->m_n38, false), spAd->m_n38);
        spBill->SetPayType(nCurrency);
        spBill->SetSlot((int)i);
        bills.Add(spBill);
    }
    spParam->m_nMailId = nMailId;
    spParam->SetFixedPrice(nPrice);
    MS2Ptr<TMarketBillDataParam> spBase(spParam);
    pBillDialog->SetParam(spBase);
    CUIService::GetInstance()->OpenDialog((eUIClassID)0x4f17);
    return true;
}
MS2_REPLACE_METHOD(0x1419E8080, UIMailListDialog, OnBuyAd, 1421, 0x80A67988); // OnBuyAd

// @0x1419e8620
MS2Ptr<TMailAdBillDataParam> UIMailListDialog::FUN_1419e8620(const CStringA& strMovie)
{
    MS2Ptr<TMailAdBillDataParam> sp(new TMailAdBillDataParam());
    if (sp == 0)
        return MS2Ptr<TMailAdBillDataParam>(0);
    sp->m_nDialogId = vfunc_48();
    sp->m_strMovie = strMovie;
    sp->m_nCurrency = 3;
    sp->m_dgBuy = TMarketBillDataParam::BuyCallback(this, &UIMailListDialog::FUN_1419e88b0);
    sp->m_dgTooltip = TMarketBillDataParam::TooltipCallback(this, &UIMailListDialog::FUN_1419e8b70);
    return sp;
}
MS2_REPLACE_METHOD(0x1419E8620, UIMailListDialog, FUN_1419e8620, 648, 0x2D1FC9B0); // FUN_1419e8620

// @0x1419e88b0
bool UIMailListDialog::FUN_1419e88b0(MS2Ptr<TMarketBillDataParam> spParam, const TMarketBillDataParam::PaymentMap& mapPay)
{
    if (m_30 == 0)
        return true;
    if (spParam == 0)
        return true;
    MS2Ptr<TMailAdBillDataParam> spMailParam(dynamic_cast<TMailAdBillDataParam*>(spParam.operator->()));
    if (spMailParam == 0)
        return true;
    __int64 nMailId = spMailParam->m_nMailId;
    CMailInfo* pMail = g_143ab2ee0.FindMailById(nMailId).get();
    if (pMail == 0)
        return true;
    if (pMail->FUN_140690b80() == 0)
        return true;
    unsigned int nPrice = (unsigned int)pMail->FUN_1406925a0();
    if (!FUN_140d86260()->vfunc_40(nPrice))
    {
        CUIService::GetInstance()->FUN_141add1f0();
        return false;
    }
    COutPacket packet(static_cast<int>(SendOp::Mail), 0);
    packet.Encode1(0xc);
    packet.Encode8(pMail->GetId());
    FUN_140710590(packet);
    return true;
}

// ---- UIMailSendDialog ----

// @0x1419ec180
UIMailSendDialog::UIMailSendDialog()
{
    FUN_1422dc3b0(1);
    m_164 = 1;
}

// @0x1419ec230
UIMailSendDialog::~UIMailSendDialog()
{
}

// @0x1419ec2b0
CString UIMailSendDialog::GetTypeName()
{
    return "MailSendDialog";
}
MS2_REPLACE_METHOD(0x1419ec2b0, UIMailSendDialog, GetTypeName, 61, 0x58655699); // UIMailSendDialog::vfunc_1

// @0x1419ec300
int UIMailSendDialog::vfunc_65()
{
    if (vfunc_55() == 0)
    {
        if (m_30.get() != 0)
            m_30->Invoke("setTopMostLayer");
        return 1;
    }
    if (UIDialog::vfunc_65() == 0)
        return 0;
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}
MS2_REPLACE_METHOD(0x1419ec300, UIMailSendDialog, vfunc_65, 189, 0xCD1EEC7C); // UIMailSendDialog::vfunc_65

// @0x1419ec3d0
void UIMailSendDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_spReply = 0;
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
}
MS2_REPLACE_METHOD(0x1419ec3d0, UIMailSendDialog, vfunc_67, 98, 0xFA732006); // UIMailSendDialog::vfunc_67

// @0x1419ec440
int UIMailSendDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (vfunc_55() != 0)
        return 0;
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
    {
        if (((class CInputKeyHandler*)FUN_14025e7c0())->WasKeyPressed(0x1c, 0, 0))
        {
            pDlg->Invoke("onEnterKey");
            return 1;
        }
        else if (((class CInputKeyHandler*)FUN_14025e7c0())->WasKeyPressed(0xf, 0, 0))
        {
            pDlg->Invoke("onTabKey");
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419ec440, UIMailSendDialog, vfunc_13, 294, 0x5CA7E770); // UIMailSendDialog::vfunc_13

// @0x1419ec570
void UIMailSendDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    g_143ab2ee0.ResetSendDraft(0);
    g_143ab2ee0.UpdateSendFee();
    SetReplyData();
}
MS2_REPLACE_METHOD(0x1419ec570, UIMailSendDialog, OnLoadComplete, 60, 0x1D20BAF1); // UIMailSendDialog::OnLoadComplete

// @0x1419ec5c0
void UIMailSendDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    switch (static_cast<CInPacket*>(p)->GetOpcode()) {
    case 0x54: {
        int nMode = static_cast<CInPacket*>(p)->ReadUInt8();
        if (nMode == 0x14) {
            static_cast<CInPacket*>(p)->ReadUInt8();
            int nResult = static_cast<CInPacket*>(p)->ReadUInt8();
            switch (nResult) {
            case 1:
            case 0x19:
                if (m_30.get() != 0)
                    m_30->Invoke("selectRecvName");
                break;
            }
        }
        break;
    }
    }
}
MS2_REPLACE_METHOD(0x1419ec5c0, UIMailSendDialog, vfunc_79, 313, 0x0F2F7896); // UIMailSendDialog::vfunc_79

// @0x1419ec700
int UIMailSendDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnSend", szMethod) == 0)
    {
        OnSend();
        return 1;
    } else if (_stricmp("onLimitInput", szMethod) == 0)
        FUN_141275260(0x256, 1, 1);
    return 0;
}
MS2_REPLACE_METHOD(0x1419ec700, UIMailSendDialog, vfunc_28, 147, 0xE807937F); // UIMailSendDialog::vfunc_28

// @0x1419ec7a0
void UIMailSendDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
}
MS2_REPLACE_METHOD(0x1419EC7A0, UIMailSendDialog, vfunc_45, 21, 0x3C2C5B86); // UIMailSendDialog::vfunc_45

// @0x1419ec7c0
int UIMailSendDialog::vfunc_74(int nMsg, void* p2, void* p3)
{
    if (nMsg != 0x10f && nMsg != 0x102)
        return 0;
    if (m_30.IsNull())
        return 0;
    if (vfunc_55() != 0)
        return 0;
    MS2Ptr<ASTextInput> spInput = GetChild<ASTextInput>("m_receiver");
    if (spInput.IsNull())
        return 0;
    if (spInput->GetFocused() == 0)
        return 0;
    CStringW strText = spInput->GetText();
    if (FUN_1418fccc0(nMsg, (unsigned __int64)p2, (unsigned __int64)p3, &strText) == 0)
        return 0;
    strText.TrimRight();
    CStringW strLower = FUN_1413fa9b0(strText);
    ASDataProvider candidates(2);
    if (0 < strLower.GetLength())
    {
        ATL::CAtlMap<unsigned __int64, CStringW> names;
        FUN_1419ed7f0(names);
        for (POSITION pos = names.GetStartPosition(); pos != 0; names.GetNext(pos))
        {
            CStringW strName = FUN_1413fa9b0(names.GetValueAt(pos));
            if (strName.Find(strLower, 0) != -1)
            {
                ASObj row(2);
                row.SetWStringMember("label", CStringW(names.GetValueAt(pos)));
                candidates.PushObj(row);
            }
        }
    }
    spInput->Invoke("setCandidates", candidates);
    return 0;
}
MS2_REPLACE_METHOD(0x1419ec7c0, UIMailSendDialog, vfunc_74, 937, 0x10F4EE17); // UIMailSendDialog::vfunc_74

// @0x1419ecb70
void UIMailSendDialog::vfunc_15()
{
}
MS2_REPLACE_METHOD(0x1419ECB70, UIMailSendDialog, vfunc_15, 6, 0xA9AF6E37); // UIMailSendDialog::vfunc_15

// @0x1419ecb80
void UIMailSendDialog::Close()
{
    vfunc_67();
}
MS2_REPLACE_METHOD(0x1419ecb80, UIMailSendDialog, Close, 33, 0xC3D85B89); // Close

// @0x1419ecbb0
void UIMailSendDialog::SetReplyMail(CMailInfo* pReplyTo)
{
    if (pReplyTo == 0)
        return;
    m_spReply.AssignRaw(pReplyTo);
}
MS2_REPLACE_METHOD(0x1419ecbb0, UIMailSendDialog, SetReplyMail, 53, 0x661A5E70); // SetReplyMail

// @0x1419ecbf0
void UIMailSendDialog::SetReplyData()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
    {
        ASObj data(2);
        if (m_spReply.get() != 0)
        {
            CStringW strContent;
            strContent = FormatStringId(0x806, m_spReply->GetSenderName(), m_spReply->GetDateString(),
                                        m_spReply->GetTitle(), m_spReply->GetContent());
            CStringW strTitle;
            strTitle = FormatStringId(0x805, m_spReply->GetTitle());
            data.SetWStringMember("receiver", m_spReply->GetSenderName());
            data.SetWStringMember("title", CStringW(strTitle));
            data.SetWStringMember("content", CStringW(strContent));
        }
        pDlg->Invoke("setData", data);
    }
}
MS2_REPLACE_METHOD(0x1419ecbf0, UIMailSendDialog, SetReplyData, 1036, 0x5596C3DA); // SetReplyData

// @0x1419ed010
void UIMailSendDialog::FUN_1419ed010()
{
    if (MS2Ptr<ASDropdownMenu> spCombo = GetChild<ASDropdownMenu>("m_buddys"))
    {
        spCombo->ClearItems();
        ATL::CAtlArray<CBuddyManager::Ptr> buddies;
        CBuddyManager::GetInstance()->GetAllBuddies(buddies);
        for (size_t i = 0; i < buddies.GetCount(); i++)
        {
            CBuddyManager::Ptr spBuddy = buddies[i];
            spCombo->AddItemLabel(spBuddy->GetName());
        }
        spCombo->vfunc_24(true);
    }
}
MS2_REPLACE_METHOD(0x1419ed010, UIMailSendDialog, FUN_1419ed010, 411, 0x080B07AD); // FUN_1419ed010

// @0x1419ed1c0
void UIMailSendDialog::OnSend()
{
    Unk_MailSendInfo info;
    GetReceiverText(info.m_strReceiver);
    GetTitleText(info.m_strTitle);
    GetContentText(info.m_strContent);
    if (info.m_strTitle.GetLength() == 0)
    {
        FUN_141275260(0x247, 1, 1);
        return;
    }
    if (info.m_strContent.GetLength() == 0)
    {
        FUN_141275260(0x248, 1, 1);
        return;
    }
    if (info.m_strTitle.GetLength() > 100)
    {
        FUN_141275260(0x244, 1, 1);
        return;
    }
    if (info.m_strContent.GetLength() > 2000)
    {
        FUN_141275260(0x244, 1, 1);
        return;
    }
    if (CBanTextChecker* pChecker = TSingleton<CommonString>::GetInstance()->GetChecker())
    {
        CStringW strMessage;
        if (pChecker->CheckMailTitleText(info.m_strTitle, strMessage) != 0 ||
            pChecker->CheckContentText(info.m_strContent, strMessage) != 0)
        {
            ShowSystemNotice(strMessage, 1, 1);
            return;
        }
    }
    COutPacket packet(static_cast<int>(SendOp::Mail), 0);
    packet.Encode1(1);
    FUN_1401fc2a0(reinterpret_cast<unsigned char*>(&info), packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1419ed1c0, UIMailSendDialog, OnSend, 577, 0x7046C796); // OnSend

// @0x1419ed410
void UIMailSendDialog::GetReceiverText(CStringW& strReceiver)
{
    if (MS2Ptr<ASTextInput> spInput = GetChild<ASTextInput>("m_receiver"))
        strReceiver = spInput->GetText();
}
MS2_REPLACE_METHOD(0x1419ed410, UIMailSendDialog, GetReceiverText, 201, 0xDBD71167); // GetReceiverText

// @0x1419ed4e0
void UIMailSendDialog::GetTitleText(CStringW& strTitle)
{
    {
        if (MS2Ptr<ASTextInput> spInput = GetChild<ASTextInput>("m_title"))
        {
            if (MS2Ptr<ASTextField> spField = spInput->FUN_1409b4620("textField"))
                strTitle = spField->GetTextW();
        }
    }
    if (CBanTextChecker* pChecker = TSingleton<CommonString>::GetInstance()->GetChecker())
        pChecker->FilterReservedWords(strTitle);
}
MS2_REPLACE_METHOD(0x1419ed4e0, UIMailSendDialog, GetTitleText, 456, 0x8C5487D1); // GetTitleText

// @0x1419ed6b0
void UIMailSendDialog::GetContentText(CStringW& strContent)
{
    if (m_30.IsNull())
        return;
    strContent = XmlWide(((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(m_30->Invoke("getContent")))->GetString());
    CBanTextChecker* pChecker;
    CBanTextChecker* pDead = pChecker = TSingleton<CommonString>::GetInstance()->GetChecker();
    if (pChecker != 0)
        pChecker->FilterReservedWords(strContent);
}
MS2_REPLACE_METHOD(0x1419ed6b0, UIMailSendDialog, GetContentText, 301, 0x8AB017F2); // GetContentText

// @0x1419ed7f0
void UIMailSendDialog::FUN_1419ed7f0(ATL::CAtlMap<unsigned __int64, CStringW>& names)
{
    ATL::CAtlArray<CBuddyManager::Ptr> buddies;
    CBuddyManager::GetInstance()->GetAllBuddies(buddies);
    for (size_t i = 0; i < buddies.GetCount(); i++)
        names.SetAt(buddies[i]->FUN_1401cc230(), buddies[i]->GetName());
    ATL::CAtlArray<MS2Ptr<CGuildMember> > members;
    CGuildManager::GetInstance()->GetMembers(&members);
    for (size_t i = 0; i < members.GetCount(); i++)
    {
        if (members[i]->data.f08 != DAT_143ab2828)
            names.SetAt(members[i]->data.f08, members[i]->data.GetName());
    }
}
MS2_REPLACE_METHOD(0x1419ed7f0, UIMailSendDialog, FUN_1419ed7f0, 497, 0x23AD5823); // FUN_1419ed7f0
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbf2c0-0x142cbf3f0 .text$yd
