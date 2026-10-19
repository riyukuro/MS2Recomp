// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMailListDialog: see uimaillistdialog.h.
// MS2-UNIT: ?\uimaillistdialog.cpp
// MS2-RANGE: 0x140116000-0x140116360 .text$di
// MS2-RANGE: 0x1419e3510-0x1419ee140 .text$mn
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
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
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

class UIMailSendDialog;
void FUN_1419ecbb0(UIMailSendDialog* pDlg, CMailInfo* pReplyTo);   // UIMailSendDialog: start a reply

extern CUserMail g_143ab2ee0;                                       // the user's mails
extern int DAT_143af37b0;                                           // the mail list needs a refresh (scenestategame.cpp)
extern int DAT_143af37b4;                                           // a mail was removed
extern __int64 DAT_143af37b8;                                       // the mail to open

UIMailSendDialog* FUN_141742fb0(int nUiType);                       // the open send dialog
CStringW FUN_141b71910(__int64 n);                                  // number -> text
unsigned __int64 FUN_140718370(const CStringW& text);               // text -> number
CStringW FUN_14016a730(const char* psz, int n);                     // multibyte -> wide
CStringW FUN_14028de60(int nStrId);                                 // string table text by id
CStringW FUN_14028b8e0(const CStringW& strKey);                     // string table text by key
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

// The mail is an ad mail (kind 200).
// @0x1419ead90
bool FUN_1419ead90(CMailInfo* pMail)
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
// @0x1419ea470
bool FUN_1419ea470(const CUserMail::MailPtr& spMail)
{
    return spMail.get() == 0;
}

// ---- UIMailListDialog ----

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
CString UIMailListDialog::vfunc_1()
{
    return "MailListDialog";
}

// @0x1419e3680
int UIMailListDialog::vfunc_65()
{
    return UIDialog::vfunc_65() != 0;
}

// @0x1419e36b0
void UIMailListDialog::vfunc_67()
{
    FUN_1419e6b70();
    UIDialog::vfunc_67();
    m_bRefresh = false;
}

// @0x1419e36f0
void UIMailListDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_mapChecked.RemoveAll();
    m_nPage = 0;
    FUN_1419e73f0();
    FUN_1419e90d0();
}

// @0x1419e3750
void UIMailListDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
}

// @0x1419e3780
int UIMailListDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    return UIDialog::OnMessage(pSender, pMsg) != 0;
}

// @0x1419e4de0
void UIMailListDialog::vfunc_15()
{
    if (!m_30.IsNull())
    {
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
            FUN_1419e90d0();
    }
}

// @0x1419e4f10
void UIMailListDialog::FUN_1419e4f10()
{
    ATL::CAtlList<CUserMail::MailPtr> mails(10);
    FUN_1419e6d20(mails);
    int nPages = (int)FUN_140bf4fd0((float)mails.GetCount() / 14.0f);
    int nMin = 1;
    const int& nLast = (std::max)(nMin, nPages);
    if (nLast <= m_nPage)
    {
        m_nPage = nLast - 1;
        FUN_1419e73f0();
    }
    FUN_1419e5190();
    FUN_1419e5a10(0);
}

// @0x1419e5000
void UIMailListDialog::FUN_1419e5000(__int64 nMailId)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
        pDlg->FUN_140acd130("readMail", FUN_141b71910(nMailId));
    FUN_1419e5900();
}

// @0x1419e50b0
void UIMailListDialog::FUN_1419e50b0(__int64 nMailId)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg)
        pDlg->FUN_140acd130("receiveMail", FUN_141b71910(nMailId));
}

// @0x1419e5150
void UIMailListDialog::FUN_1419e5150()
{
    m_bRefresh = true;
    m_timer.FUN_140268840();
}

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

// @0x1419e61c0
void UIMailListDialog::FUN_1419e61c0(__int64 nMailId)
{
    CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(nMailId).get();
    if (pMail != 0 && pMail->FUN_140691110() == 0)
    {
        COutPacket packet(0x2d, 0);
        packet.Encode1(2);
        packet.Encode8(pMail->FUN_140690350());
        FUN_140710590(packet);
    }
}

// @0x1419e6290
void UIMailListDialog::FUN_1419e6290(__int64 nMailId)
{
    CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(nMailId).get();
    if (pMail != 0 && pMail->FUN_140690b80() != 0)
    {
        COutPacket packet(0x2d, 0);
        packet.Encode1(0xb);
        packet.Encode8(pMail->FUN_140690350());
        FUN_140710590(packet);
    }
}

// @0x1419e6360
void UIMailListDialog::FUN_1419e6360(__int64 nMailId)
{
    CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(nMailId).get();
    if (pMail != 0)
    {
        UIMailSendDialog* pSend = FUN_141742fb0(0x4e4a);
        if (pSend != 0)
            FUN_1419ecbb0(pSend, pMail);
        CUIService::GetInstance()->FUN_141adc750((eUIClassID)0x4e4a);
    }
}

// @0x1419e6b70
void UIMailListDialog::FUN_1419e6b70()
{
    for (int i = 0; i < 5; i++)
    {
        CStringA strKey;
        strKey.Format("%s.%d", (const char*)vfunc_1(), i);
        FUN_1414728e0(strKey);
    }
}

// @0x1419e6c30
__int64 UIMailListDialog::FUN_1419e6c30()
{
    if (m_30 == 0)
        return 0;
    CStringA strId = FUN_140b63540(m_30->Invoke("getMailID"));
    if (strId.GetLength() == 0)
        return 0;
    return atoi(strId);
}

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
    float fPages = FUN_140bf4fd0((float)nCount / 14.0f);
    if (nPage < 0 || (int)fPages <= nPage)
        return 0;
    return 1;
}

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

// @0x1419e7fd0
int UIMailListDialog::FUN_1419e7fd0()
{
    MS2Ptr<Unk_MlTab> spTab = FUN_140c02870("m_tab");
    if (spTab.get() == 0)
        return -1;
    return spTab->FUN_1422e3210();
}

// @0x1419e90d0
void UIMailListDialog::FUN_1419e90d0()
{
    if (m_30 == 0)
        return;
    if (FUN_1422dc430() != 0)
    {
        COutPacket packet(0x2d, 0);
        packet.Encode1(0);
        FUN_140710590(packet);
        m_bRefresh = false;
    }
}

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
            FUN_1419e61c0(nMailId);
        }
        return 1;
    }
    else if (_stricmp("onSendMail", szMethod) == 0)
    {
        BlockPtr spBlock = FUN_140a6a830()->FindBlockedAction(0xb);
        if (spBlock.get() == 0)
        {
            CUIService::GetInstance()->FUN_141adc530((eUIClassID)0x4e4a);
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
            FUN_1419e6290(nMailId);
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
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14028de60(0x22d), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->FUN_140b76940(CStringW(strIds));
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::FUN_1419e7640));
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
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14028de60(0x22e), 0, CStringW(L""));
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
                    spBox->FUN_141a024e0(FUN_14028de60(0x232), 0);
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
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14028de60(0x22f), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->FUN_140b76940(CStringW(strIds));
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::FUN_1419e77c0));
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
            COutPacket packet(0x2d, 0);
            packet.Encode1(0xd);
            packet.Encode4(1);
            packet.Encode8(spMail->FUN_140690350());
            FUN_140710590(packet);
            return;
        }
        if (FUN_1419eadd0(spMail.operator->()) == 0)
            nStrId = 0x236;
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14028de60(nStrId), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->FUN_140b76940(FUN_141b71910(nMailId));
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMailListDialog::FUN_1419e7c80));
        FUN_140d73c60(spBox);
    }
}

// @0x1419e6d20
void UIMailListDialog::FUN_1419e6d20(ATL::CAtlList<CUserMail::MailPtr>& out)
{
    ATL::CRBMultiMap<__int64, CUserMail::MailPtr> byTime(10);
    CUserMail::MailArray& mails = g_143ab2ee0.FUN_1408e3700();
    for (size_t i = 0; i < mails.GetCount(); i++)
    {
        CUserMail::MailPtr spMail = mails[i];
        if (FUN_1419e6ec0(CUserMail::MailPtr(spMail)) != 0)
        {
            if (FUN_1419ead90(spMail.operator->()) == 0)
                byTime.Insert(spMail->FUN_1406911c0(), spMail);
            else
                out.AddTail(spMail);
        }
    }
    for (POSITION pos = byTime.GetHeadPosition(); pos != 0; byTime.GetNext(pos))
    {
        CUserMail::MailPtr spMail = byTime.GetValueAt(pos);
        out.AddTail(spMail);
    }
}

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

// @0x1419e7640
bool UIMailListDialog::FUN_1419e7640(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        CStringW strIds = data.FUN_141a02fd0(0, CStringW());
        ATL::CAtlArray<__int64> aIds;
        FUN_1419e7ea0(CStringW(strIds), aIds, 0);
        COutPacket packet(0x2d, 0);
        packet.Encode1(0x12);
        packet.Encode4((int)aIds.GetCount());
        for (size_t i = 0; i < aIds.GetCount(); i++)
            packet.Encode8(aIds[i]);
        FUN_140710590(packet);
    }
    return true;
}

// @0x1419e77c0
bool UIMailListDialog::FUN_1419e77c0(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        CStringW strIds = data.FUN_141a02fd0(0, CStringW());
        ATL::CAtlArray<__int64> aIds;
        FUN_1419e7ea0(CStringW(strIds), aIds, 0);
        COutPacket packet(0x2d, 0);
        packet.Encode1(0x13);
        packet.Encode4((int)aIds.GetCount());
        for (size_t i = 0; i < aIds.GetCount(); i++)
            packet.Encode8(aIds[i]);
        FUN_140710590(packet);
    }
    return true;
}

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
                FUN_140d73aa0(FUN_14028b8e0(strKey), 0, 0, CStringW(L""));
                return true;
            }
        }
        COutPacket packet(0x2d, 0);
        packet.Encode1(0xd);
        packet.Encode4((int)aIds.GetCount());
        for (size_t i = 0; i < aIds.GetCount(); i++)
            packet.Encode8(aIds[i]);
        FUN_140710590(packet);
    }
    return true;
}

// @0x1419e7c80
bool UIMailListDialog::FUN_1419e7c80(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        __int64 nMailId = FUN_140718370(data.FUN_141a02fd0(0, CStringW()));
        if (FUN_1419e74e0(nMailId) == 0)
        {
            CMailInfo* pMail = g_143ab2ee0.FUN_1408e3720(nMailId).get();
            if (pMail != 0)
            {
                COutPacket packet(0x2d, 0);
                packet.Encode1(0xd);
                packet.Encode4(1);
                packet.Encode8(pMail->FUN_140690350());
                FUN_140710590(packet);
            }
        }
        else
        {
            CStringW strKey(L"s_itemlock_mail_remove");
            FUN_140d73aa0(FUN_14028b8e0(strKey), 0, 0, CStringW(L""));
        }
    }
    return true;
}

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
            if (spMail->FUN_140691220() == 0 || bSkipAttached == 0)
                aIds.Add(nMailId);
        }
    }
}

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
    COutPacket packet(0x2d, 0);
    packet.Encode1(0xc);
    packet.Encode8(pMail->FUN_140690350());
    FUN_140710590(packet);
    return true;
}
