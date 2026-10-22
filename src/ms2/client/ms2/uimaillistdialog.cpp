// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMailListDialog: see uimaillistdialog.h.
// MS2-UNIT: ?\uimaillistdialog.cpp
// MS2-RANGE: 0x140116000-0x140116360 .text$di
// MS2-RANGE: 0x1419e3510-0x1419ee140 .text$mn
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUIMailListDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@6B@ 0x142fbefc0
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUIMailListDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@6B@ 0x142fbefe8
// MS2-PIN: ??1TMailAdBillDataParam@@UEAA@XZ 0x1419ea450
// MS2-PIN: ?Maximum@?$CRBTree@_JV?$Unk_MailPtr@VCMailInfo@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$Unk_MailPtr@VCMailInfo@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1419eaf40
// MS2-PIN: ?Predecessor@?$CRBTree@_JV?$Unk_MailPtr@VCMailInfo@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$Unk_MailPtr@VCMailInfo@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1419eb2d0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMailListDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419ebc60
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMailListDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419ebc00
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimaillistdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uimaillistdialog.h"

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
    Scaleform::GFx::Value FUN_140acd130(const char* szMethod, CStringW a1);          // invoke with a string
    Scaleform::GFx::Value FUN_1409ba0d0(const char* szMethod, int a1, int a2);       // invoke with two ints
    Scaleform::GFx::Value FUN_140ba4cc0(const char* szMethod, const ASObj& a1);      // invoke with an object
};

// The page buttons of the movie.
class Unk_MlButton : public ASDisplayObject { public: void FUN_1422c1fe0(unsigned int bEnabled); };
// "m_checkAll".
class Unk_MlCheckBox : public ASDisplayObject { public: void FUN_1422ce090(int bSelected); };
// "m_tab".
class Unk_MlTab : public ASDisplayObject { public: int FUN_1422e3210(); };

// The mail list control of the movie (the AS list with clear / append / select).
class Unk_MlList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dcca0(int nIndex);                                 // select a row (-1: none)
    void FUN_1422dd1d0();                                           // clear
    void FUN_1422dd230(const ASObj& row);                           // append a row
};

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
class Unk_PopupMenu { public: void FUN_141a7f090(const Unk_PopupMenuInfo& info, const CStringW& strName, unsigned __int64 nSerial, void* p, int b, int c); };
Unk_PopupMenu* FUN_140c30140(int nId);                              // the open popup menu dialog
CBlockManager* FUN_140a6a830();
void FUN_140a30ad0(const BlockPtr& spBlock, int nAction, unsigned __int64 n);     // the "blocked" notice


extern CUserMail g_143ab2ee0;                                       // the user's mails
extern int DAT_143af37b0;                                           // the mail list needs a refresh (scenestategame.cpp)
extern int DAT_143af37b4;                                           // a mail was removed
extern __int64 DAT_143af37b8;                                       // the mail to open

UIMailSendDialog* FUN_141742fb0(int nUiType);                       // the open send dialog
CStringW FUN_141b71910(__int64 n);                                  // number -> text
unsigned __int64 FUN_140718370(const CStringW& text);               // text -> number
CStringW FUN_14016a730(const char* psz, int n);                     // multibyte -> wide
CStringW GetStringCommon(int nStrId);                                 // string table text by id
CStringW GetStringCommonByKey(const CStringW& strKey);                     // string table text by key
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& nArg);  // StringFormat<int>
void FUN_14025a680(const CStringW& text, ATL::CAtlArray<CStringW>& out, const wchar_t* pszSep);   // split
void FUN_140d73aa0(CStringW text, int nType, void* pListener, CStringW tag);       // notice box
void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW tag);          // notice box by string id
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pListener, CStringW tag);   // create a message box
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* pListener, CStringW tag);      // create one by string id
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                        // show it
void FUN_141275260(int nStrId, int nA, int nB);                     // system notice
float FUN_140bf4fd0(float f);                                       // ceil
const char* FUN_140b63540(const Scaleform::GFx::Value& v);          // Value::GetString
void FUN_1414728e0(const CStringA& strKey);                         // drop a registered item tooltip
void FUN_1414727e0(const CStringA& strKey, MS2Ptr<CItem> spItem, int nCount, int nSlot);   // register an item tooltip
CStringW FUN_1409404f0(__int64 n);                                  // an amount as text
CStringW FUN_1418fec00(int nPayType, __int64 nAmount, int n);       // a price as text
int FUN_1403bae00(int nPriceType);                                  // price kind -> pay type
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                       // the item data of an id
CStringTable* GetStringTable();                                      // the string table singleton
UIMarketBillDialog* FUN_140b09580(int nUiType);                     // the open dialog of a UI id
// FUN_1403ed2d0 (the world) is declared by usermail.h as Unk_MailSession*.
PCBase* FUN_141bd0cc0(Unk_MailSession* pWorld);                     // the local player
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);    // pRetVal = v
__int64 FUN_140869440();                                            // the server time
CStringW FormatStringId(int nId, const fmt::ArgList& args);         // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)

class PCBase;

// The wedding manager (WeddingManager, placeholder/weddingmanager.h) as this unit calls it: ReadTicketMail with the
// mail pointer type of CUserMail.
class Unk_MlWedding { public: void FUN_141b873c0(Unk_MailPtr<CMailInfo> spMail, AScript* pOut); };
Unk_MlWedding* FUN_1409eed90();                                     // TSingleton<WeddingManager>::GetInstance

// ---- UIMailSendDialog's views ----

// "m_receiver" / "m_title": the text inputs (the receiver one gets the name candidates).
class Unk_MsInput : public ASTextInput
{
};
// "m_buddys": the buddy name dropdown (an AS component like m_list: slot 24 refreshes it).
class Unk_MsCombo : public Unk_MlList
{
public:
    void FUN_1422dfc10();                                           // remove every entry
    void FUN_1422dfce0(const CStringW& strLabel);                   // append an entry
};
// The send request (receiver, title, content), written by FUN_1401fc2a0 (three wide strings).
struct Unk_MailSendInfo
{
    CStringW m_strReceiver;
    CStringW m_strTitle;
    CStringW m_strContent;
    void FUN_1401fc2a0(COutPacket& packet);
};
// CommonString as the send dialog calls it: the ban word checker.
class Unk_MsStrings { public: MS2Ptr<CBanTextChecker> FUN_140229a50(); };
Unk_MsStrings* FUN_14025e7d0();                                     // TSingleton<CommonString>::GetInstance
CInputKeyHandler* FUN_14025e7c0();                                  // TSingleton<CInputKeyHandler>::GetInstance
UIStatusEventDispatcher* FUN_140aa6d40();                           // TSingleton<UIStatusEventDispatcher>::GetInstance
int FUN_1418fccc0(int nMsg, unsigned __int64 wParam, unsigned __int64 lParam, CStringW* pStr);   // the key edits the text
CStringW FUN_1413fa9b0(const CStringW& str);                        // lower case
CStringW FUN_1408767c0(const char* psz);                            // UTF-8 -> wide
void FUN_1412751f0(const CStringW& text, int nA, int nB);           // system notice text
extern __int64 DAT_143ab2828;                                       // the own character id

// The mail is an ad mail (kind 200).
// @0x1419ead90
int FUN_1419ead90(CMailInfo* pMail)
{
    return pMail->FUN_140690370() == 200;
}

// The ad mail is sold out.
// @0x1419eadd0
int FUN_1419eadd0(CMailInfo* pMail)
{
    return pMail->m_n130;
}

// The text translator of the system mails (sender / title keys -> text).
class Unk_MlTextFilter { public: void FUN_1416fb300(CStringW& str); };
Unk_MlTextFilter* FUN_1403b4750();
CStringW FUN_1419e95d0(CMailInfo* pMail, int bTooltip);             // the "days left" text of a row

// The mail pointer is empty.
// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419ea470
int FUN_1419ea470(const CUserMail::MailPtr& spMail)
{
    return spMail.get() == 0;
}

// The meso of the mail (the plain sum while unclaimed plus the meso benefit).
// @0x1419e9160
__int64 FUN_1419e9160(CMailInfo* pMail)
{
    __int64 nTotal = 0;
    if (pMail->FUN_140690db0() != 0 && pMail->FUN_140690dd0() == 0)
        nTotal = nTotal + pMail->FUN_140690db0();
    Unk_CommonPriceRecord rec;
    if (pMail->FUN_140690fa0(0, 0, &rec) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    return nTotal;
}
MS2_REPLACE(0x1419E9160, FUN_1419e9160, 148, 0x1A71F3E1); // FUN_1419e9160

// The merat of the mail (the four merat benefit kinds).
// @0x1419e9200
__int64 FUN_1419e9200(CMailInfo* pMail)
{
    __int64 nTotal = 0;
    if (pMail->FUN_140690e40() != 0 && pMail->FUN_140690e60() == 0)
        nTotal = nTotal + pMail->FUN_140690e40();
    Unk_CommonPriceRecord rec;
    if (pMail->FUN_140690fa0(2, 0, &rec) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    if (pMail->FUN_140690fa0(2, 1, &rec) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    if (pMail->FUN_140690fa0(2, 2, &rec) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    if (pMail->FUN_140690fa0(2, 3, &rec) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    return nTotal;
}
MS2_REPLACE(0x1419E9200, FUN_1419e9200, 331, 0x58E184B6); // FUN_1419e9200

// The red merat of the mail.
// @0x1419e9360
__int64 FUN_1419e9360(CMailInfo* pMail)
{
    __int64 nTotal = 0;
    if (pMail->FUN_140690ed0() != 0 && pMail->FUN_140690ef0() == 0)
        nTotal = nTotal + pMail->FUN_140690ed0();
    Unk_CommonPriceRecord rec;
    if (pMail->FUN_140690fa0(8, 0, &rec) == true)
        nTotal = nTotal + rec.GetAvailableAmount();
    return nTotal;
}
MS2_REPLACE(0x1419E9360, FUN_1419e9360, 151, 0xE2DAA05F); // FUN_1419e9360

// A benefit amount as price text.
// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e9400
CStringW FUN_1419e9400(int nPriceType, __int64 nAmount)
{
    return FUN_1418fec00(FUN_1403bae00(nPriceType), nAmount, 0);
}
MS2_REPLACE(0x1419E9400, FUN_1419e9400, 82, 0xFF1E0FE6); // FUN_1419e9400

// The other benefits (not meso / merat kinds 2 and 8) as "token1".."tokenN" members.
// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e9460
void FUN_1419e9460(CMailInfo* pMail, ASObj& info)
{
    Unk_MailBenefitList& list = pMail->FUN_1419ea9a0();
    int nCount = list.FUN_14026a4b0();
    if (0 < nCount)
    {
        ATL::CAtlArray<Unk_MailBenefit>& benefits = list.m_array;
        int nToken = 1;
        for (int i = 0; i < nCount; i++)
        {
            Unk_MailBenefit& benefit = benefits.GetAt(i);
            if (benefit.m_nType != 2 && benefit.m_nType != 8 && benefit.m_nSub == 0)
            {
                __int64 nAmount = benefit.FUN_14026a1f0();
                if (nAmount != 0)
                {
                    CStringW strPrice = FUN_1419e9400(benefit.m_nType, nAmount);
                    CStringA strKey = StringFormat("token{0}", nToken);
                    nToken++;
                    info.FUN_1407cbb20(strKey, CStringW(strPrice));
                }
            }
        }
    }
}
MS2_REPLACE(0x1419E9460, FUN_1419e9460, 362, 0xB651066D); // FUN_1419e9460

// The "days left" text of a row (bTooltip: the long form).
// @0x1419e95d0
CStringW FUN_1419e95d0(CMailInfo* pMail, int bTooltip)
{
    CMsTime now(FUN_140869440());
    CMsTime expire(pMail->FUN_140691160());
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
MS2_REPLACE(0x1419E95D0, FUN_1419e95d0, 624, 0x1F41E57F); // FUN_1419e95d0

// ---- UIMailListDialog ----

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e3510
UIMailListDialog::UIMailListDialog()
    : m_mapChecked(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_bRefresh = false;
    FUN_141924170(1);
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

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e3680
int UIMailListDialog::vfunc_65()
{
    return UIDialog::vfunc_65() != 0;
}
MS2_REPLACE_METHOD(0x1419E3680, UIMailListDialog, vfunc_65, 37, 0xFEA3F0C1); // UIMailListDialog::vfunc_65

// @0x1419e36b0
void UIMailListDialog::vfunc_67()
{
    FUN_1419e6b70();
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
    FUN_1419e73f0();
    SendMailMode0();
}
MS2_REPLACE_METHOD(0x1419E36F0, UIMailListDialog, OnLoadComplete, 78, 0x5B61BC99); // UIMailListDialog::OnLoadComplete

// @0x1419e3750
void UIMailListDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
}
MS2_REPLACE_METHOD(0x1419E3750, UIMailListDialog, vfunc_79, 34, 0xABDD3A3E); // UIMailListDialog::vfunc_79

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e3780
int UIMailListDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    return UIDialog::OnMessage(pSender, pMsg) != 0;
}

// @0x1419e4de0
void UIMailListDialog::vfunc_15()
{
    if (m_30.IsNull())
        return;
    if (DAT_143af37b0 != 0)
    {
        DAT_143af37b0 = 0;
        FUN_1419e5190();
        __int64 nOpen = FUN_1419e6c30();
        if (nOpen != 0)
            FUN_1419e5a10(nOpen);
    }
    if (DAT_143af37b8 != 0)
    {
        FUN_1419e5a10(DAT_143af37b8);
        DAT_143af37b8 = 0;
    }
    if (DAT_143af37b4 != 0)
    {
        FUN_1419e4f10();
        DAT_143af37b4 = 0;
        FUN_141275260(0x22a, 1, 1);
    }
    if (m_bRefresh && m_timer.FUN_140268870(1000) != 0)
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
void UIMailListDialog::FUN_1419e4f10()
{
    ATL::CAtlList<CUserMail::MailPtr> mails(10);
    FUN_1419e6d20(mails);
    int nLast = (std::max)(1, (int)FUN_140bf4fd0((float)mails.GetCount() / 14.0f));
    if (m_nPage >= nLast)
    {
        m_nPage = nLast - 1;
        FUN_1419e73f0();
    }
    FUN_1419e5190();
    FUN_1419e5a10(0);
}
MS2_REPLACE_METHOD(0x1419E4F10, UIMailListDialog, FUN_1419e4f10, 227, 0x6B05EF4E); // FUN_1419e4f10

// @0x1419e5000
void UIMailListDialog::FUN_1419e5000(__int64 nMailId)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
        pDlg->FUN_140acd130("readMail", FUN_141b71910(nMailId));
    FUN_1419e5900();
}
MS2_REPLACE_METHOD(0x1419E5000, UIMailListDialog, FUN_1419e5000, 167, 0xCFAD7E71); // FUN_1419e5000

// @0x1419e50b0
void UIMailListDialog::FUN_1419e50b0(__int64 nMailId)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
        pDlg->FUN_140acd130("receiveMail", FUN_141b71910(nMailId));
}
MS2_REPLACE_METHOD(0x1419E50B0, UIMailListDialog, FUN_1419e50b0, 154, 0x92C96AA2); // FUN_1419e50b0

// @0x1419e5150
void UIMailListDialog::FUN_1419e5150()
{
    m_bRefresh = true;
    m_timer.FUN_140268840();
}
MS2_REPLACE_METHOD(0x1419E5150, UIMailListDialog, FUN_1419e5150, 45, 0xA826AB8A); // FUN_1419e5150

// @0x1419e5900
void UIMailListDialog::FUN_1419e5900()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
    {
        int nUser = 0;
        int nSystem = 0;
        for (int nKind = 1; nKind < 4; nKind++)
            nUser += g_143ab2ee0.FUN_1408e3f00(nKind);
        for (int nKind = 100; nKind < 0x71; nKind++)
            nSystem += g_143ab2ee0.FUN_1408e3f00(nKind);
        pDlg->FUN_1409ba0d0("onMailCount", nUser, nSystem);
    }
}
MS2_REPLACE_METHOD(0x1419E5900, UIMailListDialog, FUN_1419e5900, 258, 0x4973165E); // FUN_1419e5900

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e5a10
void UIMailListDialog::FUN_1419e5a10(__int64 nMailId)
{
    FUN_1419e6b70();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
    {
        ASObj info(2);
        {
            CUserMail::MailPtr spMail = g_143ab2ee0.FUN_1408e3720(nMailId);
            if (spMail.get() != 0)
            {
                CStringW strSender = spMail->FUN_140690410();
                CStringW strTitle = spMail->FUN_1406905b0();
                CStringW strContent = spMail->FUN_140690600();
                int nKind = spMail->FUN_140690370();
                if (99 < nKind && nKind < 0x71)
                {
                    FUN_1403b4750()->FUN_1416fb300(strSender);
                    FUN_1403b4750()->FUN_1416fb300(strTitle);
                    FUN_1403b4750()->FUN_1416fb300(strContent);
                }
                if (nKind == 0x70)
                {
                    ASObj wedding(2);
                    FUN_1409eed90()->FUN_141b873c0(CUserMail::MailPtr(spMail), &wedding);
                    info.FUN_1409eb270("wedding", wedding);
                }
                info.FUN_1407cbb20("sender", CStringW(strSender));
                info.FUN_1407cbb20("title", CStringW(strTitle));
                info.FUN_1407cbb20("content", CStringW(strContent));
                info.FUN_1407cb9c0("attachment", spMail->FUN_140691220());
                info.FUN_1407cba60("state", FUN_1419e7260(CUserMail::MailPtr(spMail)));
                info.FUN_1407cb9c0("binding", FUN_1419e67a0(spMail.get()));
                info.FUN_1407cbb20("date", spMail->FUN_1406922d0());
                __int64 nMeso = FUN_1419e9160(spMail.get());
                __int64 nMerat = FUN_1419e9200(spMail.get());
                __int64 nMeratRed = FUN_1419e9360(spMail.get());
                if (0 < nMeso)
                    info.FUN_1407cbb20("meso", FUN_1409404f0(nMeso));
                if (0 < nMerat)
                    info.FUN_1407cbb20("merat", FUN_1409404f0(nMerat));
                if (0 < nMeratRed)
                    info.FUN_1407cbb20("meratRed", FUN_1409404f0(nMeratRed));
                FUN_1419e9460(spMail.get(), info);
                int nKind2 = spMail->FUN_140690370();
                if (nKind2 == 3)
                {
                    info.FUN_1407cbbe0("disableReply", true);
                }
                else if (nKind2 == 200)
                {
                    info.FUN_1407cbb20("productName", spMail->FUN_1419eab80());
                    __int64 nPrice = spMail->FUN_140692510();
                    info.FUN_1407cba60("price", StringFormat("{0}", nPrice));
                    __int64 nSalePrice = spMail->FUN_1406925a0();
                    info.FUN_1407cba60("salePrice", StringFormat("{0}", nSalePrice));
                    info.FUN_1407cb9c0("expired", spMail->FUN_140692630());
                }
                else if (0 < spMail->FUN_140690370() && spMail->FUN_140690370() < 4)
                {
                    info.FUN_1407cbbe0("visibleUserMailIcon", true);
                }
            }
        }
        m_30->Invoke("setMailInfo", info);
    }
}
MS2_REPLACE_METHOD(0x1419E5A10, UIMailListDialog, FUN_1419e5a10, 1959, 0xC519097B); // FUN_1419e5a10

// @0x1419e61c0
void UIMailListDialog::SendMailMode2(__int64 nMailId)
{
    CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(nMailId).get();
    if (pMail == 0)
        return;
    if (pMail->FUN_140691110() == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Mail), 0);
        packet.Encode1(2);
        packet.Encode8(pMail->FUN_140690350());
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x1419E61C0, UIMailListDialog, SendMailMode2, 199, 0x9CBB1495); // SendMailMode2

// @0x1419e6290
void UIMailListDialog::SendMailMode11(__int64 nMailId)
{
    CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(nMailId).get();
    if (pMail == 0)
        return;
    if (pMail->FUN_140690b80() == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Mail), 0);
    packet.Encode1(0xb);
    packet.Encode8(pMail->FUN_140690350());
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1419E6290, UIMailListDialog, SendMailMode11, 200, 0x09F47CCF); // SendMailMode11

// @0x1419e6360
void UIMailListDialog::FUN_1419e6360(__int64 nMailId)
{
    CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(nMailId).get();
    if (pMail == 0)
        return;
    UIMailSendDialog* pSend = FUN_141742fb0(0x4e4a);
    if (pSend != 0)
        pSend->FUN_1419ecbb0(pMail);
    CUIService::GetInstance()->ToggleDialog((eUIClassID)0x4e4a);
}
MS2_REPLACE_METHOD(0x1419E6360, UIMailListDialog, FUN_1419e6360, 156, 0x946298AD); // FUN_1419e6360

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e67a0
unsigned UIMailListDialog::FUN_1419e67a0(CMailInfo* pMail)
{
    if (pMail == 0)
        return 0;
    unsigned nCount = 0;
    if (FUN_1419ead90(pMail) != 0)
    {
        for (int i = 0; i < 5; i++)
        {
            MS2Ptr<CMailAdItem> spAd = pMail->FUN_140692480(i);
            if (spAd)
            {
                CItem* pItem = new CItem();
                if (pItem->FUN_14052b130(spAd->m_n18, spAd->m_n20, 0) != 0)
                {
                    pItem->FUN_140526c70(spAd->m_n1c);
                    CStringA strKey;
                    strKey.Format("%s.%d", (const char*)GetTypeName(), nCount);
                    FUN_1414727e0(strKey, MS2Ptr<CItem>(pItem), spAd->m_n24, i);
                    nCount++;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            Unk_MailAttachPtr spAttach = pMail->FUN_140690790(i);
            if (spAttach.get() != 0 && spAttach->m_nTime == 0)
            {
                CStringA strKey;
                strKey.Format("%s.%d", (const char*)GetTypeName(), nCount);
                FUN_1414727e0(strKey, spAttach->m_item, spAttach->m_n20, i);
                nCount++;
            }
        }
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x1419E67A0, UIMailListDialog, FUN_1419e67a0, 957, 0x72309694); // FUN_1419e67a0

// @0x1419e6b70
void UIMailListDialog::FUN_1419e6b70()
{
    for (int i = 0; i < 5; i++)
    {
        CStringA strKey;
        strKey.Format("%s.%d", (const char*)GetTypeName(), i);
        FUN_1414728e0(strKey);
    }
}
MS2_REPLACE_METHOD(0x1419E6B70, UIMailListDialog, FUN_1419e6b70, 174, 0x75771166); // FUN_1419e6b70

// @0x1419e6c30
__int64 UIMailListDialog::FUN_1419e6c30()
{
    if (m_30 == 0)
        return 0;
    CStringA strId = FUN_140b63540(m_30->Invoke("getMailID"));
    if (strId.GetLength() != 0)
        return atoi(strId);
    return 0;
}
MS2_REPLACE_METHOD(0x1419E6C30, UIMailListDialog, FUN_1419e6c30, 234, 0x978463E6); // FUN_1419e6c30

// @0x1419e6ec0
int UIMailListDialog::FUN_1419e6ec0(Unk_MailPtr<CMailInfo> spMail)
{
    if (FUN_1419e7fd0() == 1)
    {
        for (int nKind = 1; nKind < 4; nKind++)
        {
            if (spMail->FUN_140690370() == nKind)
                return 1;
        }
    }
    else
    {
        for (int nKind = 100; nKind < 0x71; nKind++)
        {
            if (spMail->FUN_140690370() == nKind)
                return 1;
        }
        if (FUN_1419ead90(spMail.get()) != 0)
            return 1;
    }
    return 0;
}

// @0x1419e6fe0
int UIMailListDialog::FUN_1419e6fe0(int nPage)
{
    int nCount = 0;
    if (FUN_1419e7fd0() == 1)
    {
        for (int nKind = 1; nKind < 4; nKind++)
            nCount += g_143ab2ee0.FUN_1408e3dd0(nKind);
    }
    else
    {
        for (int nKind = 100; nKind < 0x71; nKind++)
            nCount += g_143ab2ee0.FUN_1408e3dd0(nKind);
    }
    int nPages = (int)FUN_140bf4fd0((float)nCount / 14.0f);
    if (nPage < 0 || nPage >= nPages)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1419E6FE0, UIMailListDialog, FUN_1419e6fe0, 210, 0xE322023D); // FUN_1419e6fe0

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e70c0
int UIMailListDialog::FUN_1419e70c0(CStringW strIds)
{
    ATL::CAtlArray<CStringW> aIds;
    FUN_14025a680(strIds, aIds, L",");
    if (aIds.GetCount() == 0)
        return 0;
    ATL::CAtlArray<CStringW> aUnused;
    for (size_t i = 0; i < aIds.GetCount(); i++)
    {
        unsigned __int64 nId = FUN_140718370(aIds[i]);
        CUserMail::MailPtr spMail = g_143ab2ee0.FUN_1408e3720(nId);
        if (spMail.get() != 0 && spMail->FUN_140691220() != 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419E70C0, UIMailListDialog, FUN_1419e70c0, 395, 0xB40CDF74); // FUN_1419e70c0

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e7260
CStringA UIMailListDialog::FUN_1419e7260(Unk_MailPtr<CMailInfo> spMail)
{
    if (FUN_1419ead90(spMail.operator->()) == 0)
    {
        if (spMail->FUN_140690370() == 0x70)
            return "wedding_invitation";
        if (spMail->FUN_140691220() == 0)
            return "non_attached";
        return "attached";
    }
    if (FUN_1419eadd0(spMail.operator->()) == 0)
        return "ad_attached";
    return "ad";
}

// @0x1419e73f0
void UIMailListDialog::FUN_1419e73f0()
{
    if (MS2Ptr<ASTextField> spPage = FUN_140bb4cf0("m_page"))
    {
        int nShown = m_nPage + 1;
        spPage->FUN_1422c4cd0(FUN_1401ceea0(L"{0}", nShown));
    }
}
MS2_REPLACE_METHOD(0x1419E73F0, UIMailListDialog, FUN_1419e73f0, 225, 0x8A7532B9); // FUN_1419e73f0

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e7fd0
int UIMailListDialog::FUN_1419e7fd0()
{
    MS2Ptr<Unk_MlTab> spTab = FUN_140c02870("m_tab");
    if (spTab.get() == 0)
        return -1;
    return spTab->FUN_1422e3210();
}
MS2_REPLACE_METHOD(0x1419E7FD0, UIMailListDialog, FUN_1419e7fd0, 166, 0x6BAF5A08); // FUN_1419e7fd0

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e8b70
bool UIMailListDialog::FUN_1419e8b70(Scaleform::GFx::Value* pRetVal, ASData& data, MS2Ptr<TMarketBillDataParam> spParam)
{
    if (m_30 == 0)
        return false;
    if (spParam == 0)
        return false;
    ASObj obj(data.FUN_1422b9260(), 2);
    if (obj.FUN_1422ba9a0())
        return false;
    MS2Ptr<TMailAdBillDataParam> spMailParam(dynamic_cast<TMailAdBillDataParam*>(spParam.get()));
    if (spMailParam == 0)
        return true;
    CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(spMailParam->m_nMailId).get();
    if (pMail == 0)
        return true;
    MS2Ptr<ASBillData> spBill = spParam->FUN_140eaba00(data.FUN_1422b8b10());
    if (spBill == 0)
        return false;
    MS2Ptr<ASMailAdBillData> spAdBill(dynamic_cast<ASMailAdBillData*>(spBill.get()));
    if (spAdBill == 0)
        return false;
    MS2Ptr<CMailAdItem> spAd = pMail->FUN_140692480(spAdBill->vfunc_5());
    if (spAd == 0)
        return false;
    ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 0x20, 2);
    if (tip.FUN_1409e1770(spAd->m_n18, spAd->m_n20) != 0)
        FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
    return true;
}

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e90d0
void UIMailListDialog::SendMailMode0()
{
    if (m_30 == 0)
        return;
    if (FUN_1422dc430() != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Mail), 0);
        packet.Encode1(0);
        FUN_140710590(packet);
        m_bRefresh = false;
    }
}
MS2_REPLACE_METHOD(0x1419E90D0, UIMailListDialog, SendMailMode0, 128, 0xBD218E6E); // SendMailMode0

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e37d0
int UIMailListDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onSelectMail", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            __int64 nMailId = atoi(data.FUN_1422b8d30());
            FUN_1419e5a10(nMailId);
            SendMailMode2(nMailId);
        }
        return 1;
    }
    else if (_stricmp("onSendMail", szMethod) == 0)
    {
        BlockPtr spBlock = FUN_140a6a830()->FindBlockedAction(0xb);
        if (spBlock.get() == 0)
        {
            CUIService::GetInstance()->OpenDialog((eUIClassID)0x4e4a);
            return 1;
        }
        FUN_140a30ad0(spBlock, 0xb, 0);
        return 1;
    }
    else if (_stricmp("onSelectTab", szMethod) == 0)
    {
        m_nPage = 0;
        FUN_1419e5190();
        FUN_1419e5a10(0);
        FUN_1419e73f0();
        m_mapChecked.RemoveAll();
    }
    else if (_stricmp("onRecieveAll", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            __int64 nMailId = atoi(data.FUN_1422b8d30());
            SendMailMode11(nMailId);
        }
    }
    else if (_stricmp("onReply", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            __int64 nMailId = atoi(data.FUN_1422b8d30());
            FUN_1419e6360(nMailId);
        }
    }
    else if (_stricmp("onRemove", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            __int64 nMailId = atoi(data.FUN_1422b8d30());
            FUN_1419e6410(nMailId);
        }
    }
    else if (_stricmp("onPrevPage", szMethod) == 0)
    {
        if (FUN_1419e6fe0(m_nPage - 1) != 0)
        {
            m_nPage = m_nPage - 1;
            FUN_1419e5190();
            FUN_1419e73f0();
            m_mapChecked.RemoveAll();
            if (MS2Ptr<Unk_MlCheckBox> spCheck = FUN_140e52670("m_checkAll"))
                spCheck->FUN_1422ce090(0);
        }
    }
    else if (_stricmp("onNextPage", szMethod) == 0)
    {
        if (FUN_1419e6fe0(m_nPage + 1) != 0)
        {
            m_nPage = m_nPage + 1;
            FUN_1419e5190();
            FUN_1419e73f0();
            m_mapChecked.RemoveAll();
            if (MS2Ptr<Unk_MlCheckBox> spCheck = FUN_140e52670("m_checkAll"))
                spCheck->FUN_1422ce090(0);
        }
    }
    else if (_stricmp("onReadList", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strIds = FUN_14016a730(data.FUN_1422b8d30(), 0);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommon(0x22d), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->FUN_140b76940(CStringW(strIds));
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::SendMailMode18));
                FUN_140d73c60(spBox);
            }
        }
    }
    else if (_stricmp("onDeleteList", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strIds = FUN_14016a730(data.FUN_1422b8d30(), 0);
            if (FUN_1419e70c0(CStringW(strIds)) == 0)
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommon(0x22e), 0, CStringW(L""));
                if (spBox.get() != 0)
                {
                    spBox->FUN_140b76940(CStringW(strIds));
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::FUN_1419e7940));
                    FUN_140d73c60(spBox);
                }
            }
            else
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x19, 0x231, 0, CStringW(L""));
                if (spBox.get() != 0)
                {
                    spBox->FUN_141a01800(1);
                    spBox->FUN_141a024e0(GetStringCommon(0x232), 0);
                    spBox->FUN_140b76940(CStringW(strIds));
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::FUN_1419e7940));
                    FUN_140d73c60(spBox);
                }
            }
        }
    }
    else if (_stricmp("onReceiveList", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strIds = FUN_14016a730(data.FUN_1422b8d30(), 0);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommon(0x22f), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->FUN_140b76940(CStringW(strIds));
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::SendMailMode19));
                FUN_140d73c60(spBox);
            }
        }
    }
    else if (_stricmp("onClickMailCheckbox", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            unsigned __int64 nMailId = FUN_140718370(data.FUN_1422b8f40());
            int bChecked = data.FUN_1422b8a90();
            m_mapChecked.SetAt(nMailId, bChecked);
        }
    }
    else if (_stricmp("onRClickMailSender", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) == 0)
            return 0;
        unsigned __int64 nMailId = FUN_140718370(data.FUN_1422b8f40());
        CStringW strSender = data.FUN_1422b8f40();
        float fX = data.FUN_1422b8c10();
        float fY = data.FUN_1422b8c10();
        CUserMail::MailPtr spMail = g_143ab2ee0.FUN_1408e3720(nMailId);
        if (FUN_1419ea470(spMail))
            return 0;
        if (spMail->FUN_140690370() != 1)
            return 0;
        Unk_PopupMenu* pMenu = FUN_140c30140(0x4e39);
        if (pMenu == 0)
            return 0;
        Unk_PopupMenuInfo info(fX, fY, 3, 0x50, 0, "", 0);
        pMenu->FUN_141a7f090(info, strSender, 0, 0, 0, 1);
        return 0;
    }
    else if (_stricmp("onBuyAd", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            unsigned __int64 nMailId = FUN_140718370(data.FUN_1422b8f40());
            FUN_1419e8080(nMailId);
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419E37D0, UIMailListDialog, vfunc_28, 5626, 0x102D767A); // UIMailListDialog::vfunc_28

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e6410
void UIMailListDialog::FUN_1419e6410(__int64 nMailId)
{
    if (nMailId == 0)
    {
        FUN_140d73bc0(0x23d, 0, 0, CStringW(L""));
        return;
    }
    CUserMail::MailPtr spMail = g_143ab2ee0.FUN_1408e3720(nMailId);
    if (spMail == 0)
        return;
    int nStrId = 0x235;
    if (FUN_1419ead90(spMail.operator->()) == 0)
    {
        if (spMail->FUN_140691220() != 0)
            nStrId = 0x237;
    }
    else
    {
        if (spMail->FUN_140692630() != 0)
        {
            COutPacket packet(static_cast<int>(SendOp::Mail), 0);
            packet.Encode1(0xd);
            packet.Encode4(1);
            packet.Encode8(spMail->FUN_140690350());
            FUN_140710590(packet);
            return;
        }
        if (FUN_1419eadd0(spMail.operator->()) == 0)
            nStrId = 0x236;
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommon(nStrId), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->FUN_140b76940(FUN_141b71910(nMailId));
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::SendMailMode13));
        FUN_140d73c60(spBox);
    }
}
MS2_REPLACE_METHOD(0x1419E6410, UIMailListDialog, FUN_1419e6410, 902, 0xCFF9DD01); // FUN_1419e6410

// @0x1419e6d20
void UIMailListDialog::FUN_1419e6d20(ATL::CAtlList<CUserMail::MailPtr>& out)
{
    ATL::CRBMultiMap<__int64, CUserMail::MailPtr> byTime(10);
    CUserMail::MailArray& mails = g_143ab2ee0.FUN_1408e3700();
    for (size_t i = 0; i < mails.GetCount(); i++)
    {
        CUserMail::MailPtr spMail = mails.GetAt(i);
        if (FUN_1419e6ec0(CUserMail::MailPtr(spMail)) != 0)
        {
            if (FUN_1419ead90(spMail.operator->()) != 0)
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
MS2_REPLACE_METHOD(0x1419E6D20, UIMailListDialog, FUN_1419e6d20, 400, 0x6E86303A); // FUN_1419e6d20

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e74e0
int UIMailListDialog::FUN_1419e74e0(__int64 nMailId)
{
    CUserMail::MailPtr spMail = g_143ab2ee0.FUN_1408e3720(nMailId);
    if (spMail.get() != 0)
    {
        for (int i = 0; i < 5; i++)
        {
            Unk_MailAttachPtr spAttach = spMail->FUN_140690790(i);
            if (spAttach.get() != 0 && spAttach->m_nTime < 1 && spAttach->m_item.get() != 0 &&
                spAttach->m_item->FUN_140528e20())
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419E74E0, UIMailListDialog, FUN_1419e74e0, 335, 0xE1BB44D8); // FUN_1419e74e0

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e7640
bool UIMailListDialog::SendMailMode18(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        CStringW strIds = data.FUN_141a02fd0(0, CStringW());
        ATL::CAtlArray<__int64> aIds;
        FUN_1419e7ea0(CStringW(strIds), aIds, 0);
        COutPacket packet(static_cast<int>(SendOp::Mail), 0);
        packet.Encode1(0x12);
        packet.Encode4((int)aIds.GetCount());
        for (size_t i = 0; i < aIds.GetCount(); i++)
            packet.Encode8(aIds[i]);
        FUN_140710590(packet);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1419E7640, UIMailListDialog, SendMailMode18, 377, 0x270B2582); // SendMailMode18

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e77c0
bool UIMailListDialog::SendMailMode19(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        CStringW strIds = data.FUN_141a02fd0(0, CStringW());
        ATL::CAtlArray<__int64> aIds;
        FUN_1419e7ea0(CStringW(strIds), aIds, 0);
        COutPacket packet(static_cast<int>(SendOp::Mail), 0);
        packet.Encode1(0x13);
        packet.Encode4((int)aIds.GetCount());
        for (size_t i = 0; i < aIds.GetCount(); i++)
            packet.Encode8(aIds[i]);
        FUN_140710590(packet);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1419E77C0, UIMailListDialog, SendMailMode19, 377, 0x97E3EE98); // SendMailMode19

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e7940
bool UIMailListDialog::FUN_1419e7940(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        CStringW strIds = data.FUN_141a02fd0(0, CStringW());
        CStringW strInput = data.FUN_141a02d50();
        int nTrue = strInput.Find(L"true", 0);
        ATL::CAtlArray<__int64> aIds;
        FUN_1419e7ea0(CStringW(strIds), aIds, nTrue == -1);
        for (size_t i = 0; i < aIds.GetCount(); i++)
        {
            if (FUN_1419e74e0(aIds[i]) != 0)
            {
                CStringW strKey(L"s_itemlock_mail_remove");
                FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
                return true;
            }
        }
        COutPacket packet(static_cast<int>(SendOp::Mail), 0);
        packet.Encode1(0xd);
        packet.Encode4((int)aIds.GetCount());
        for (size_t i = 0; i < aIds.GetCount(); i++)
            packet.Encode8(aIds[i]);
        FUN_140710590(packet);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1419E7940, UIMailListDialog, FUN_1419e7940, 812, 0x6BFE17E1); // FUN_1419e7940

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e7c80
bool UIMailListDialog::SendMailMode13(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        __int64 nMailId = FUN_140718370(data.FUN_141a02fd0(0, CStringW()));
        if (FUN_1419e74e0(nMailId) == 0)
        {
            CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(nMailId).get();
            if (pMail != 0)
            {
                COutPacket packet(static_cast<int>(SendOp::Mail), 0);
                packet.Encode1(0xd);
                packet.Encode4(1);
                packet.Encode8(pMail->FUN_140690350());
                FUN_140710590(packet);
            }
        }
        else
        {
            CStringW strKey(L"s_itemlock_mail_remove");
            FUN_140d73aa0(GetStringCommonByKey(strKey), 0, 0, CStringW(L""));
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x1419E7C80, UIMailListDialog, SendMailMode13, 534, 0x573E56A5); // SendMailMode13

// @0x1419e7ea0
void UIMailListDialog::FUN_1419e7ea0(CStringW strIds, ATL::CAtlArray<__int64>& aIds, int bSkipAttached)
{
    ATL::CAtlArray<CStringW> aTexts;
    FUN_14025a680(strIds, aTexts, L",");
    for (size_t i = 0; i < aTexts.GetCount(); i++)
    {
        __int64 nMailId = FUN_140718370(aTexts[i]);
        CUserMail::MailPtr spMail = g_143ab2ee0.FUN_1408e3720(nMailId);
        if (spMail.get() != 0)
        {
            if (spMail->FUN_140691220() != 0 && bSkipAttached != 0)
                continue;
            aIds.Add(nMailId);
        }
    }
}
MS2_REPLACE_METHOD(0x1419E7EA0, UIMailListDialog, FUN_1419e7ea0, 291, 0x201EBD4F); // FUN_1419e7ea0

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e5190
void UIMailListDialog::FUN_1419e5190()
{
    __int64 nOpen = FUN_1419e6c30();
    int nSelect = -1;
    if (MS2Ptr<Unk_MlList> spList = FUN_140c02900("m_list"))
    {
        spList->FUN_1422dd1d0();
        ATL::CAtlList<CUserMail::MailPtr> mails(10);
        FUN_1419e6d20(mails);
        int nIndex = -1;
        int nRow = 0;
        for (POSITION pos = mails.GetHeadPosition(); pos != 0; mails.GetNext(pos))
        {
            nIndex++;
            if (m_nPage * 14 <= nIndex)
            {
                if (m_nPage * 14 + 14 <= nIndex)
                    break;
                CMailInfo* pMail = mails.GetAt(pos).get();
                if (pMail->FUN_140691180() == 0)
                {
                    int bSelect = 0;
                    m_mapChecked.Lookup(pMail->FUN_140690350(), bSelect);
                    CStringW strSender = pMail->FUN_140690410();
                    CStringW strTitle = pMail->FUN_1406905b0();
                    int nKind = pMail->FUN_140690370();
                    if (99 < nKind && nKind < 0x71)
                    {
                        FUN_1403b4750()->FUN_1416fb300(strSender);
                        FUN_1403b4750()->FUN_1416fb300(strTitle);
                    }
                    ASObj row(2);
                    row.FUN_1407cbb20("mailSN", FUN_141b71910(pMail->FUN_140690350()));
                    row.FUN_1407cbb20("sender", CStringW(strSender));
                    row.FUN_1407cbb20("content", CStringW(strTitle));
                    row.FUN_1407cbb20("date", FUN_1419e95d0(pMail, 0));
                    row.FUN_1407cbb20("dateTooltip", FUN_1419e95d0(pMail, 1));
                    row.FUN_1407cb9c0("read", pMail->FUN_140691130());
                    row.FUN_1407cb9c0("attachment", pMail->FUN_140691220());
                    row.FUN_1407cb9c0("select", bSelect);
                    row.FUN_1407cb9c0("adMail", FUN_1419ead90(pMail));
                    row.FUN_1407cb9c0("adSoldout", FUN_1419eadd0(pMail));
                    row.FUN_1407cb9c0("adExpired", pMail->FUN_140692630());
                    spList->FUN_1422dd230(row);
                    if (pMail->FUN_140690350() == nOpen)
                        nSelect = nRow;
                    nRow++;
                }
            }
        }
        spList->vfunc_24(true);
        spList->FUN_1422dcca0(nSelect);
    }
    FUN_1419e5900();
    if (MS2Ptr<Unk_MlButton> spPrev = FUN_140bb4b10("m_prev"))
        spPrev->FUN_1422c1fe0(FUN_1419e6fe0(m_nPage - 1));
    if (MS2Ptr<Unk_MlButton> spNext = FUN_140bb4b10("m_next"))
        spNext->FUN_1422c1fe0(FUN_1419e6fe0(m_nPage + 1));
    if (MS2Ptr<Unk_MlCheckBox> spCheck = FUN_140e52670("m_checkAll"))
        spCheck->FUN_1422ce090(0);
}
MS2_REPLACE_METHOD(0x1419E5190, UIMailListDialog, FUN_1419e5190, 1889, 0x75FE8B86); // FUN_1419e5190

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419e8080
bool UIMailListDialog::FUN_1419e8080(unsigned __int64 nMailId)
{
    MS2Ptr<TMailAdBillDataParam> spParam = FUN_1419e8620("mailAd");
    if (spParam == 0)
        return false;
    UIMarketBillDialog* pBillDialog = FUN_140b09580(0x4f17);
    if (pBillDialog == 0)
        return false;
    CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(nMailId).get();
    if (pMail == 0)
        return false;
    unsigned int nPrice = (unsigned int)pMail->FUN_1406925a0();
    if (!FUN_140d86260()->vfunc_40(nPrice))
    {
        CUIService::GetInstance()->FUN_141add1f0();
        return false;
    }
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = spParam->m_bills;
    for (size_t i = 0; i < 5; i++)
    {
        MS2Ptr<CMailAdItem> spAd = pMail->FUN_140692480((int)i);
        if (spAd == 0)
            continue;
        MS2Ptr<CItemData> spItemData = FUN_14053f870(spAd->m_n18);
        if (spItemData == 0)
            continue;
        MS2Ptr<ASMailAdBillData> spBill(new ASMailAdBillData());
        spBill->FUN_1409ab990(spItemData, spAd->m_n20);
        spBill->FUN_1409aba80(GetStringTable()->FUN_141811980(1, spAd->m_n18));
        spBill->FUN_1409abad0(FUN_1418fec00(3, spAd->m_n38, 0), spAd->m_n38);
        spBill->FUN_1409abcd0(3);
        spBill->FUN_1419eb8f0((int)i);
        bills.Add(spBill);
    }
    spParam->m_nMailId = nMailId;
    spParam->FUN_140eab9a0(nPrice);
    MS2Ptr<TMarketBillDataParam> spBase(spParam);
    pBillDialog->FUN_140ea7770(spBase);
    CUIService::GetInstance()->OpenDialog((eUIClassID)0x4f17);
    return true;
}
MS2_REPLACE_METHOD(0x1419E8080, UIMailListDialog, FUN_1419e8080, 1421, 0x80A67988); // FUN_1419e8080

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

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
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
    CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(spMailParam->m_nMailId).get();
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
    packet.Encode8(pMail->FUN_140690350());
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
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}
MS2_REPLACE_METHOD(0x1419ec300, UIMailSendDialog, vfunc_65, 189, 0xCD1EEC7C); // UIMailSendDialog::vfunc_65

// @0x1419ec3d0
void UIMailSendDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_spReply = 0;
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
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
        if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
        {
            pDlg->Invoke("onEnterKey");
            return 1;
        }
        else if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0))
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
    g_143ab2ee0.FUN_1408e3ff0(0);
    g_143ab2ee0.FUN_1408e45e0();
    FUN_1419ecbf0();
}
MS2_REPLACE_METHOD(0x1419ec570, UIMailSendDialog, OnLoadComplete, 60, 0x1D20BAF1); // UIMailSendDialog::OnLoadComplete

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419ec5c0
void UIMailSendDialog::vfunc_79(void* p)
{
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    UIDialog::vfunc_79(p);
    if (!(pPacket->FUN_14070fe80() == 0x54 && pPacket->ReadUInt8() == 0x14))
        return;
    pPacket->ReadUInt8();
    unsigned char nResult = pPacket->ReadUInt8();
    if ((nResult == 1 || nResult == 0x19) && m_30.get() != 0)
        m_30->Invoke("selectRecvName");
}
MS2_REPLACE_METHOD(0x1419ec5c0, UIMailSendDialog, vfunc_79, 313, 0x0F2F7896); // UIMailSendDialog::vfunc_79

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419ec700
int UIMailSendDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnSend", szMethod) == 0)
    {
        OnSend();
        return 1;
    }
    if (_stricmp("onLimitInput", szMethod) == 0)
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
    MS2Ptr<Unk_MsInput> spInput = FUN_140e35bd0("m_receiver");
    if (spInput.IsNull())
        return 0;
    if (spInput->FUN_1422c76c0() == 0)
        return 0;
    CStringW strText = spInput->FUN_1422e0b00();
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
                row.FUN_1407cbb20("label", CStringW(names.GetValueAt(pos)));
                candidates.FUN_1422bbf00(row);
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
void UIMailSendDialog::FUN_1419ecb80()
{
    vfunc_67();
}
MS2_REPLACE_METHOD(0x1419ecb80, UIMailSendDialog, FUN_1419ecb80, 33, 0xC3D85B89); // FUN_1419ecb80

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419ecbb0
void UIMailSendDialog::FUN_1419ecbb0(CMailInfo* pReplyTo)
{
    if (pReplyTo != 0)
        m_spReply.AssignRaw(pReplyTo);
}
MS2_REPLACE_METHOD(0x1419ecbb0, UIMailSendDialog, FUN_1419ecbb0, 53, 0x661A5E70); // FUN_1419ecbb0

// @0x1419ecbf0
void UIMailSendDialog::FUN_1419ecbf0()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
    {
        ASObj data(2);
        if (m_spReply.get() != 0)
        {
            CStringW strContent;
            strContent = FormatStringId(0x806, m_spReply->FUN_140690410(), m_spReply->FUN_1406922d0(),
                                        m_spReply->FUN_1406905b0(), m_spReply->FUN_140690600());
            CStringW strTitle;
            strTitle = FormatStringId(0x805, m_spReply->FUN_1406905b0());
            data.FUN_1407cbb20("receiver", m_spReply->FUN_140690410());
            data.FUN_1407cbb20("title", CStringW(strTitle));
            data.FUN_1407cbb20("content", CStringW(strContent));
        }
        pDlg->Invoke("setData", data);
    }
}
MS2_REPLACE_METHOD(0x1419ecbf0, UIMailSendDialog, FUN_1419ecbf0, 1036, 0x5596C3DA); // FUN_1419ecbf0

// @0x1419ed010
void UIMailSendDialog::FUN_1419ed010()
{
    if (MS2Ptr<Unk_MsCombo> spCombo = FUN_140c28560("m_buddys"))
    {
        spCombo->FUN_1422dfc10();
        ATL::CAtlArray<CBuddyManager::Ptr> buddies;
        CBuddyManager::GetInstance()->FUN_140ae4df0(buddies);
        for (size_t i = 0; i < buddies.GetCount(); i++)
        {
            CBuddyManager::Ptr spBuddy = buddies[i];
            spCombo->FUN_1422dfce0(spBuddy->FUN_1401cc1c0());
        }
        spCombo->vfunc_24(true);
    }
}
MS2_REPLACE_METHOD(0x1419ed010, UIMailSendDialog, FUN_1419ed010, 411, 0x080B07AD); // FUN_1419ed010

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419ed1c0
void UIMailSendDialog::OnSend()
{
    Unk_MailSendInfo info;
    FUN_1419ed410(info.m_strReceiver);
    FUN_1419ed4e0(info.m_strTitle);
    FUN_1419ed6b0(info.m_strContent);
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
    if (100 < info.m_strTitle.GetLength())
    {
        FUN_141275260(0x244, 1, 1);
        return;
    }
    if (info.m_strContent.GetLength() < 0x7d1)
    {
        CBanTextChecker* pChecker = FUN_14025e7d0()->FUN_140229a50();
        if (pChecker != 0)
        {
            CStringW strMessage;
            if (pChecker->FUN_140225c90(info.m_strTitle, strMessage) != 0 ||
                pChecker->FUN_140225de0(info.m_strContent, strMessage) != 0)
            {
                FUN_1412751f0(strMessage, 1, 1);
                return;
            }
        }
        COutPacket packet(static_cast<int>(SendOp::Mail), 0);
        packet.Encode1(1);
        info.FUN_1401fc2a0(packet);
        FUN_140710590(packet);
        return;
    }
    FUN_141275260(0x244, 1, 1);
}
MS2_REPLACE_METHOD(0x1419ed1c0, UIMailSendDialog, OnSend, 577, 0x7046C796); // OnSend

// @0x1419ed410
void UIMailSendDialog::FUN_1419ed410(CStringW& strReceiver)
{
    if (MS2Ptr<Unk_MsInput> spInput = FUN_140e35bd0("m_receiver"))
        strReceiver = spInput->FUN_1422e0b00();
}
MS2_REPLACE_METHOD(0x1419ed410, UIMailSendDialog, FUN_1419ed410, 201, 0xDBD71167); // FUN_1419ed410

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419ed4e0
void UIMailSendDialog::FUN_1419ed4e0(CStringW& strTitle)
{
    {
        if (MS2Ptr<Unk_MsInput> spInput = FUN_140e35bd0("m_title"))
        {
            if (MS2Ptr<ASTextField> spField = spInput->FUN_1409b4620("textField"))
                strTitle = spField->FUN_1422c4da0();
        }
    }
    CBanTextChecker* pChecker = FUN_14025e7d0()->FUN_140229a50();
    if (pChecker != 0)
        pChecker->FilterReservedWords(strTitle);
}
MS2_REPLACE_METHOD(0x1419ed4e0, UIMailSendDialog, FUN_1419ed4e0, 456, 0x8C5487D1); // FUN_1419ed4e0

// MS2-FUNCTIONAL: not byte-exact yet (branch/temp layout differs; left for the permuter lane)
// @0x1419ed6b0
void UIMailSendDialog::FUN_1419ed6b0(CStringW& strContent)
{
    if (m_30.IsNull())
        return;
    strContent = FUN_1408767c0(FUN_140b63540(m_30->Invoke("getContent")));
    CBanTextChecker* pChecker = FUN_14025e7d0()->FUN_140229a50();
    if (pChecker != 0)
        pChecker->FilterReservedWords(strContent);
}
MS2_REPLACE_METHOD(0x1419ed6b0, UIMailSendDialog, FUN_1419ed6b0, 301, 0x8AB017F2); // FUN_1419ed6b0

// @0x1419ed7f0
void UIMailSendDialog::FUN_1419ed7f0(ATL::CAtlMap<unsigned __int64, CStringW>& names)
{
    ATL::CAtlArray<CBuddyManager::Ptr> buddies;
    CBuddyManager::GetInstance()->FUN_140ae4df0(buddies);
    for (size_t i = 0; i < buddies.GetCount(); i++)
        names.SetAt(buddies[i]->FUN_1401cc230(), buddies[i]->FUN_1401cc1c0());
    ATL::CAtlArray<MS2Ptr<CGuildMember> > members;
    CGuildManager::GetInstance()->FUN_1404d0420(&members);
    for (size_t i = 0; i < members.GetCount(); i++)
    {
        if (members[i]->data.f08 != DAT_143ab2828)
            names.SetAt(members[i]->data.f08, members[i]->data.FUN_1404ca890());
    }
}
MS2_REPLACE_METHOD(0x1419ed7f0, UIMailSendDialog, FUN_1419ed7f0, 497, 0x23AD5823); // FUN_1419ed7f0
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbf2c0-0x142cbf3f0 .text$yd
