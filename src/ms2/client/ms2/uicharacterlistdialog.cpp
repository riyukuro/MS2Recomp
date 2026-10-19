// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICharacterListDialog: see uicharacterlistdialog.h.
// MS2-UNIT: ?\uicharacterlistdialog.cpp
// MS2-RANGE: 0x140111400-0x140111600 .text$di
// MS2-RANGE: 0x1418e93f0-0x1418fafd0 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicharacterlistdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uicharacterlistdialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di) ---------------------------------------------------------------------------------------------

// @0x140111400
std::shared_ptr<UICharacterListDialog::DeleteReply> UICharacterListDialog::s_reply(nullptr);

// @0x140111430
static CStringW s_strChangeInvalidCharName(L"changeInvalidCharName");

#include "ms2/placeholder/header_statics_a.h"

// @0x1401115d0
static UICommon::CMyPCKeyInputController s_keyInput;

static int s_nOrder;                                    // 0x143af1980 the next CCharacterInfo order number

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

__int64 FUN_140869440();                                // the server time
class Unk_ClClock { public: unsigned FUN_141473390(); };
Unk_ClClock* FUN_14086d260();                           // the tick clock
class Unk_ClUgc
{
public:
    int FUN_14187f3b0();                                // mode (1: uploads disabled)
    void FUN_141880600(UICharacterListDialog::CharPtr spCharacter);   // upload a shot of a character as its profile image
    void FUN_141883380(CString strPath);                // a profile image was uploaded
};
Unk_ClUgc* FUN_14052d220();
CStringW FUN_14028b8e0(const CStringW& strKey);         // string table text
void FUN_140d73aa0(CStringW strMsg, int nType, void* pTarget, CStringW strTag);
// The generic reader of an item from a stream (the 0x141272280 object is an empty functor).
class Unk_ClItemReader
{
public:
    Unk_ClItemReader();                                 // 0x141272280
    MS2Ptr<CItem> FUN_1401fce40(CInputStream& s);
};
class Unk_ClPackets { public: void FUN_140da5180(int, Delegate<void(CInPacket&)>); void FUN_140da51e0(int, Delegate<void(CInPacket&)>); };
Unk_ClPackets* FUN_140bccd50();
class Unk_ClIdSet { public: void FUN_1403f19e0(); void FUN_140212bf0(unsigned __int64 nId); bool FUN_141315e50(); unsigned FUN_1403ed0f0(); bool FUN_1418f5a10(unsigned __int64 nId, unsigned* pnIndex); };
class Unk_ClUserInfo
{
public:
    char m_pad[0x20];
    CStringW m_str20;
    __int64 m_n28;
    char m_pad2[8];
    Unk_ClIdSet m_ids;
    void FUN_141260cb0();
    void FUN_141260e70();
};
class Unk_ClUserMgr { public: Unk_ClUserInfo* FUN_140cfd260(); void FUN_141242990(); };
Unk_ClUserMgr* FUN_1409a8b10();
unsigned char* FUN_140a58500(Unk_ClUserMgr* p);
unsigned char* FUN_140c58ac0(Unk_ClUserMgr* p);
void FUN_14125f670(unsigned char* p, unsigned char n, bool b);
void FUN_14125bd20(unsigned char* p, unsigned char n);
extern bool DAT_143ab2946;
extern unsigned short DAT_143ab2944;                    // the highest character level
extern bool DAT_143ab2942;
extern __int64 DAT_143ab2828;                           // the last picked character id
class Unk_InventoryCharacters
{
public:
    void FUN_1403416e0();                               // clear
    void FUN_1404bfb40(const unsigned __int64* pnId);   // erase
    void FUN_1416da690(const unsigned __int64* pnId);   // insert
};
extern Unk_InventoryCharacters DAT_143ab2a30;           // ids of the characters of the account
class Unk_GmEvtKey;
extern Unk_GmEvtKey DAT_143ab2fc0;

class Unk_ClMovie : public AScript { public: Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int nIndex, CStringW strText); };
void FUN_1412761e0(MS2Ptr<AScript>* pScript, int nFlag);            // lock the movie input
CString FUN_141028a90(CString str, int nFlag);
CStringW FUN_14052bd00(int nStringId, const CStringW& str);         // the string table text with an argument
CStringW FUN_141b708a0(unsigned nSeconds, bool bShowSeconds);       // a time span as text
CStringW FUN_1418f5e20(int nStringId, const CStringW& str, int* pnCode);
void FUN_140cfefe0(Scaleform::GFx::Value& root, CString strChild, CString strLabel, CStringW strText);   // set the label text of a child
void FUN_140710590(COutPacket& packet);                 // send
class Unk_ClPopupInfo                                   // 0x30 bytes: the popup answer of the server
{
public:
    Unk_ClPopupInfo();                                  // 0x141540eb0
    ~Unk_ClPopupInfo();                                 // 0x141541190
    void FUN_1407a4c60(CInPacket* pPacket);
    char m_bEmpty;
    char m_pad[0x2f];
};
class Unk_ClInput { public: bool FUN_14116d890(int nKey); };
Unk_ClInput* FUN_14025e7c0();
class ASDialog : public ASDisplayObject { public: int FUN_1422c6740(); };
class Unk_ClButton : public ASDisplayObject { public: void FUN_1422c1fe0(int n); };
bool FUN_141900750(ASObj* pObj);                        // fill the initData object
class Unk_ClUgcEvents { public: void FUN_141b38be0(UIUGCEventListener* p); void FUN_141b38c70(UIUGCEventListener* p); };
Unk_ClUgcEvents* FUN_140bc09f0();
class Unk_ClScene { public: void FUN_14174f470(); };
Unk_ClScene* FUN_140f30370();
class Unk_ClUIMgr { public: void FUN_141adc530(int nId); int FUN_141adc890(int nId); void FUN_141adc5d0(int nId); };
Unk_ClUIMgr* FUN_1403ed2b0();
class Unk_ClFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_ClFeatures* FUN_140166410();
bool FUN_14036e6c0();
int FUN_1406516b0();                                    // the language id
class Unk_ClNet                                         // the network service (slots 0..22)
{
public:
    virtual void vfunc_0();
    virtual int vfunc_1();
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
    virtual void vfunc_22(int nId, const char* szName);
};
Unk_ClNet* FUN_140d86260();
void FUN_14151f200();
int FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& arrOut, const wchar_t* szDelim, int nExpected);   // split
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);         // equal
__int64 FUN_140718370(const CStringW& str);                         // parse an id
struct Unk_ClId { __int64 m_a; __int64 m_b; };
class Unk_ClWorld { public: void* FUN_141bd0cc0(); void FUN_141bbbc60(const Unk_ClId* pId, int n); };
Unk_ClWorld* FUN_1403ed2d0();
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
class Unk_ClEvtMgr { public: bool FUN_14047bb90(); };
Unk_ClEvtMgr* FUN_1401c0d90();
class Unk_GmEvtKey { public: bool FUN_140482280(int nKey, unsigned* pnValue); };
class Unk_ClApp { public: HWND FUN_14209c720(); };
Unk_ClApp* FUN_140aadf80();
class Unk_ClMsgState { public: int FUN_1422b9da0(); };
Unk_ClMsgState* FUN_1408e57f0();
void FUN_1401cd100(Unk_ClId* pId, __int64 nId);
void* FUN_140876480(void* pkOut, int nCategory);        // returns the mem category
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCategory);
bool FUN_14107b7e0(unsigned nSlot, const Unk_UserProxy* pState, MyPC* pPC);   // build the preview PC
__int64 FUN_141656a80(MyPC* pPC);
__int64 FUN_14123c500(MyPC* pPC);
void FUN_141b70290();
void* FUN_140c43790(int nId);
void FUN_14135ec00(void* pBrowser, const CString& strUrl, bool b);
void* FUN_140714f90();
void FUN_1415388a0(void* p);
bool FUN_1407cce10(const Scaleform::GFx::Value* pValue);
MS2Ptr<ASMovieClip> FUN_1409b40c0(int nMovieId, const Scaleform::GFx::Value& value);
struct Unk_ClTime { __int64 m_a; __int64 m_b; };
Unk_ClTime FUN_1406c47a0(__int64 nTime);
CStringW FUN_14083bdc0(const Unk_ClTime& time, int n, CStringW strSep1, CStringW strSep2);
CStringW FUN_1405c2690(CStringW strKey, CStringW strArg);
extern int DAT_143ab285c;
extern int DAT_143ab2860;

// ---- CCharacterInfo -------------------------------------------------------------------------------------------------

// @0x1418e93f0
UICharacterListDialog::CCharacterInfo::CCharacterInfo()
{
    m_nSeconds = 0;
    m_nStarted = 0;
    m_nDeleteTime = 0;
    m_nOrder = 0;
}

// @0x1418e94b0
UICharacterListDialog::CCharacterInfo::~CCharacterInfo()
{
}

// @0x1418e9520
// MS2-FUNCTIONAL: the temps / null-check shape of the three `new CItem` loops (frame 0x188 in the exe) is not reproduced
void UICharacterListDialog::CCharacterInfo::Read(CInPacket& packet)
{
    m_state.FUN_1408eeb60(&packet);
    CInputStream& s = packet;
    m_text368 = s.vfunc_o8_6();
    if (FUN_14052d220()->FUN_14187f3b0() == 1)
        m_text368 = "";
    FUN_1418e9fa0(s.vfunc_o8_4());
    int nCount = s.vfunc_o8_1();
    for (int i = 0; i < nCount; ++i)
    {
        int nId = s.vfunc_o8_3();
        __int64 nUid = s.vfunc_o8_4();
        int nRank = s.vfunc_o8_1();
        int nAmount = s.vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nId, nAmount, 0))
            break;
        spItem->FUN_140526c10(nRank);
        spItem->FUN_140524eb0(s);
        spItem->FUN_140526a70(nUid);
        m_state.m_220.Add(spItem);
    }
    nCount = s.vfunc_o8_1();
    Unk_ClItemReader reader;
    for (int i = 0; i < nCount; ++i)
    {
        MS2Ptr<CItem> spItem = reader.FUN_1401fce40(s);
        if (!(spItem == 0))
            m_state.m_240.Add(spItem);
    }
    if (s.vfunc_o8_0())
    {
        __int64 nFirst = s.vfunc_o8_4();
        __int64 nSecond = s.vfunc_o8_4();
        m_state.m_280 = nFirst;
        m_state.m_288 = nSecond;
        nCount = s.vfunc_o8_1();
        if (nCount != 0)
        {
            for (int i = 0; i < nCount; ++i)
            {
                int nId = s.vfunc_o8_3();
                __int64 nUid = s.vfunc_o8_4();
                int nRank = s.vfunc_o8_1();
                int nAmount = s.vfunc_o8_3();
                MS2Ptr<CItem> spItem(new CItem);
                if (!spItem->FUN_140523c40(nId, nAmount, 0))
                    return;
                spItem->FUN_140526c10(nRank);
                spItem->FUN_140524eb0(s);
                spItem->FUN_140526a70(nUid);
                spItem->FUN_14052a130(2);
                m_state.m_260.Add(spItem);
            }
        }
    }
}

// @0x1418e9cb0
unsigned __int64 UICharacterListDialog::CCharacterInfo::FUN_1418e9cb0()
{
    return m_state.m_8;
}

// @0x1418e9cd0
CStringW UICharacterListDialog::CCharacterInfo::FUN_1418e9cd0()
{
    return m_state.FUN_1408f19e0();
}

// @0x1418e9d20
void UICharacterListDialog::CCharacterInfo::FUN_1418e9d20(const CStringW& strName)
{
    m_state.FUN_1408f07e0(strName);
}

// @0x1418e9d50
Unk_UserProxy* UICharacterListDialog::CCharacterInfo::FUN_1418e9d50()
{
    return &m_state;
}

// @0x1418e9d70
const Unk_UserProxy* UICharacterListDialog::CCharacterInfo::FUN_1418e9d70() const
{
    return &m_state;
}

// @0x1418e9d90
CString UICharacterListDialog::CCharacterInfo::FUN_1418e9d90()
{
    return m_text368;
}

// @0x1418e9de0
void UICharacterListDialog::CCharacterInfo::FUN_1418e9de0(CString str)
{
    m_text368 = str;
}

// @0x1418e9e30
void UICharacterListDialog::CCharacterInfo::FUN_1418e9e30(CString str)
{
    m_text370 = str;
}

// @0x1418e9e80
CString UICharacterListDialog::CCharacterInfo::FUN_1418e9e80()
{
    return m_text370;
}

// @0x1418e9ed0
void UICharacterListDialog::CCharacterInfo::FUN_1418e9ed0(unsigned nSeconds)
{
    m_nSeconds = nSeconds;
    if (nSeconds > 0)
        m_nStarted = FUN_14086d260()->FUN_141473390();
    else
        m_nStarted = 0;
}

// @0x1418e9f30
int UICharacterListDialog::CCharacterInfo::FUN_1418e9f30()
{
    if (m_nStarted > 0 && m_nSeconds > 0)
    {
        unsigned nPassed = (FUN_14086d260()->FUN_141473390() - m_nStarted) / 1000;
        return m_nSeconds - nPassed;
    }
    return 0;
}

// @0x1418e9fa0
int UICharacterListDialog::CCharacterInfo::FUN_1418e9fa0(__int64 nDeleteTime)
{
    m_nDeleteTime = nDeleteTime;
    __int64 nNow = FUN_140869440();
    int nSeconds = 0;
    if (nNow < m_nDeleteTime)
        nSeconds = (int)(m_nDeleteTime - nNow);
    FUN_1418e9ed0(nSeconds);
    return nSeconds;
}

// @0x1418ea020
__int64 UICharacterListDialog::CCharacterInfo::FUN_1418ea020()
{
    return m_nDeleteTime;
}

// @0x1418ea040
void UICharacterListDialog::CCharacterInfo::FUN_1418ea040(int nOrder)
{
    m_nOrder = nOrder;
}

// @0x1418ea060
int UICharacterListDialog::CCharacterInfo::FUN_1418ea060()
{
    return m_nOrder;
}

// @0x1418ea080
int UICharacterListDialog::CCharacterInfo::FUN_1418ea080()
{
    return ++s_nOrder;
}

// @0x1418ea0a0
void UICharacterListDialog::CCharacterInfo::FUN_1418ea0a0()
{
    s_nOrder = 0;
}

// ---- CDeleteCharacterInfo -------------------------------------------------------------------------------------------

// @0x1418ea0c0
UICharacterListDialog::CDeleteCharacterInfo::CDeleteCharacterInfo(CharPtr spCharacter, MS2Ptr<ASMovieClip> spMovie)
    : m_spCharacter(spCharacter), m_spMovie(spMovie)
{
}

// @0x1418ea150
UICharacterListDialog::CDeleteCharacterInfo::~CDeleteCharacterInfo()
{
    m_spCharacter = 0;
    m_spMovie = 0;
}

// @0x1418ea1e0
UICharacterListDialog::DeleteReply::DeleteReply(unsigned char nResult, const CStringW& str1, const CStringW& str2, const CStringW& str3)
    : m_nResult(0)
{
    m_nResult = nResult;
    m_str8 = str1;
    m_str10 = str2;
    m_str18 = str3;
}

// ---- UICharacterListDialog ------------------------------------------------------------------------------------------

// @0x1418ea2b0
// MS2-FUNCTIONAL: the exe frame is 0x10 smaller (one fewer temp around the delegate / s_reply reset)
UICharacterListDialog::UICharacterListDialog()
    : m_180(0), m_1c0(0), m_1c8(0), m_1d0(0), m_1d4(0), m_1d8(0), m_1dc(0), m_1e0(0), m_1e4(0), m_1e8(0),
      m_1f0(10), m_220(0), m_221(0), m_224(0), m_228(0)
{
    m_80 = 0;
    Unk_ClUserInfo* pInfo = FUN_1409a8b10()->FUN_140cfd260();
    m_198 = pInfo->m_str20;
    m_1a0 = pInfo->m_n28;
    FUN_141925e70(0, 1);
    FUN_140bccd50()->FUN_140da5180(0xc, Delegate<void(CInPacket&)>(this, &UICharacterListDialog::FUN_1418ed880));
    s_reply = nullptr;
}

// @0x1418ea5d0
UICharacterListDialog::~UICharacterListDialog()
{
    FUN_140bccd50()->FUN_140da51e0(0xc, Delegate<void(CInPacket&)>(this, &UICharacterListDialog::FUN_1418ed880));
}

// @0x1418ea740
CString UICharacterListDialog::vfunc_1()
{
    return "CharacterListDialog";
}

// @0x1418ea790
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
int UICharacterListDialog::vfunc_65()
{
    if (DAT_143ab2946 != 0)
    {
        DAT_143ab2946 = 0;
        CStringW strKey(L"s_delete_account_cancel_login_success");
        FUN_140d73aa0(FUN_14028b8e0(strKey), 0, 0, L"");
    }
    return UIDialog::vfunc_65() != 0;
}

// @0x1418ea860
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    CInPacket* pPacket = (CInPacket*)p;
    int nOpcode = pPacket->FUN_14070fe80();
    if (nOpcode == 0xc)
    {
        if (pPacket->vfunc_o8_1() == 7)
        {
            MS2Ptr<AScript> spScript(m_30);
            FUN_1412761e0(&spScript, 1);
            int nCode = pPacket->vfunc_o8_3();
            unsigned __int64 nId = pPacket->vfunc_o8_4();
            CStringW strText = pPacket->vfunc_o8_8();
            if (nCode == 1)
            {
                unsigned nIndex = 0;
                CharPtr spCharacter = FindCharacter(nId, &nIndex);
                if (spCharacter == 0)
                    return;
                spCharacter->FUN_1418e9d20(strText);
                static_cast<Unk_ClMovie*>(m_30.operator->())->FUN_14129cce0("updateCharacterName", nIndex, CStringW(strText));
            }
            else if (nCode == 2)
                FUN_140d73aa0(FUN_14052bd00(0x2a, strText), 0, 0, L"");
            else if (nCode == 6)
                FUN_140d73aa0(FUN_14052bd00(0x29, strText), 0, 0, L"");
            else
                FUN_140d73aa0(FUN_1418f5e20(0x2c, strText, &nCode), 0, 0, L"");
        }
    }
    else if (nOpcode == 0xe)
    {
        Unk_ClPopupInfo info;
        info.FUN_1407a4c60(pPacket);
        if (info.m_bEmpty == 0)
        {
            COutPacket packet(0x14, 0);
            FUN_140710590(packet);
        }
        else
            ShowPopup();
    }
    else if (nOpcode == 0x132)
        FUN_1418f2620(p);
    else if (nOpcode == 0x133)
        FUN_1418f2820(p);
}

// @0x1418ead80
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (vfunc_55() == 0 && !m_30.IsNull() && !m_1f0.IsEmpty())
    {
        POSITION pos = m_1f0.GetHeadPosition();
        while (pos != 0)
        {
            DeletePtr spInfo = m_1f0.GetAt(pos);
            if (spInfo.get() != 0)
            {
                MS2Ptr<ASMovieClip> spMovie(spInfo->m_spMovie);
                if (spMovie.get() != 0)
                {
                    int nLeft = spInfo->m_spCharacter->FUN_1418e9f30();
                    if (nLeft == 0)
                    {
                        m_1f0.RemoveAt(pos);
                        spMovie->Invoke("readyDelete");
                        return;
                    }
                    CStringW strText = FUN_14052bd00(3, FUN_141b708a0(nLeft, 0));
                    FUN_140cfefe0(spMovie->FUN_1422bb870(), "m_delete", "m_label", strText);
                }
            }
            m_1f0.GetNext(pos);
        }
    }
}

// @0x1418eb0a0
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::vfunc_72()
{
    if (m_238.FUN_140268870(500) == 0)
        return;
    std::shared_ptr<DeleteReply> spReply(s_reply);
    if (spReply != nullptr)
    {
        s_reply = std::shared_ptr<DeleteReply>(nullptr);
        HandleDeleteReply(spReply->m_nResult, spReply->m_str8, spReply->m_str10, spReply->m_str18);
    }
}

// @0x1418eb1c0
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASObj initData(2);
    if (FUN_141900750(&initData))
        m_30->Invoke("initData", initData.FUN_1422bb870());
    RefreshLobby();
    FUN_140bc09f0()->FUN_141b38be0(this);
    if (DAT_143ab285c != 0 && DAT_143ab2860 == 3)
    {
        Unk_ClScene* pScene = FUN_140f30370();
        if (pScene != 0)
            pScene->FUN_14174f470();
    }
    if (FUN_1418ed650())
        FUN_1403ed2b0()->FUN_141adc530(0x4f2a);
    FUN_1418f0400();
    if (FUN_1406516b0() == 3)
        AttachHealthGame();
    MS2Ptr<Unk_ClButton> spDelete = FUN_140bb4b10("m_deleteAccount");
    if (spDelete.get() != 0)
    {
        if (!FUN_140166410()->FUN_14036d570(0x112))
            spDelete->vfunc_4(0);
    }
    MS2Ptr<Unk_ClButton> spServer = FUN_140bb4b10("m_serverlist");
    if (spServer.get() != 0)
    {
        int nVisible = FUN_140d86260()->vfunc_1();
        FUN_140166410();
        if (FUN_14036e6c0())
            nVisible = 1;
        spServer->FUN_1422c1fe0(nVisible);
        spServer->vfunc_3(nVisible);
    }
    FUN_140d86260()->vfunc_22(0x2be, "LoginStep2");
}

// @0x1418eb540
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
int UICharacterListDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() != 0 || dynamic_cast<UIMessageBox*>(pSender) == 0)
        return 0;
    int nResult = pMsg->FUN_1422b8a10();
    CStringW strTag = pMsg->FUN_1422b8f40();
    if (nResult == 0)
    {
        FUN_14151f200();
        CAtlArray<CStringW> arrTag;
        if (FUN_14028cb70(strTag, arrTag, L",", 2) == 1)
        {
            CStringW strCommand(arrTag[0]);
            if (!FUN_1403b3c40(strCommand, L"deletePC"))
            {
                if (!FUN_1403b3c40(strCommand, L"revivalChar"))
                {
                    if (FUN_1403b3c40(strCommand, L"finalDelete"))
                    {
                        unsigned __int64 nId = FUN_140718370(arrTag[1]);
                        if (nId != 0)
                            CheckDelete(nId);
                    }
                }
                else
                {
                    unsigned __int64 nId = FUN_140718370(arrTag[1]);
                    if (nId != 0)
                        CancelDelete(FindCharacter(nId));
                }
            }
            else
            {
                CStringW strAnswer(arrTag[1]);
                if (!strAnswer.IsEmpty())
                {
                    PC* pPC = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
                    if (pPC != 0)
                    {
                        if (strAnswer.CompareNoCase(pPC->vfunc_77()) == 0)
                        {
                            FUN_1418f13d0();
                            return 1;
                        }
                    }
                }
                FUN_140d73bc0(0x18, 0, 0, L"");
            }
        }
    }
    else
        FUN_14151f200();
    return 1;
}

// @0x1418eb930
int UICharacterListDialog::vfunc_13()
{
    if (m_1dc == 0 || m_90.IsNull())
        return 0;
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (FUN_14025e7c0()->FUN_14116d890(0))
    {
        if (m_90->FUN_1422c6740() != 0)
            m_90->Invoke("onEnterKey");
        return 1;
    }
    return 0;
}

// @0x1418ed080
void UICharacterListDialog::vfunc_67()
{
    FUN_140bc09f0()->FUN_141b38c70(this);
    if (FUN_1403ed2b0()->FUN_141adc890(0x4f2a) != 0)
        FUN_1403ed2b0()->FUN_141adc5d0(0x4f2a);
    UIDialog::vfunc_67();
    m_1dc = 0;
    m_1d8 = 0;
    m_180 = 0;
    m_1d4 = 0;
    m_188 = 0;
    FUN_1418ee370();
    m_1f0.RemoveAll();
    CCharacterInfo::FUN_1418ea0a0();
    m_220 = 0;
    m_228 = 0;
}

// @0x1418ed190
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
int UICharacterListDialog::vfunc_4()
{
    int nResult = UIDialog::vfunc_4();
    if (m_30 == 0)
    {
        Unk_ClUserInfo* pInfo = FUN_1409a8b10()->FUN_140cfd260();
        pInfo->m_ids.FUN_1403f19e0();
        size_t nCount = m_1a8.size();
        for (size_t i = 0; i < nCount; ++i)
        {
            CharPtr spCharacter = m_1a8[i];
            if (!(spCharacter == 0))
                pInfo->m_ids.FUN_140212bf0(spCharacter->FUN_1418e9cb0());
        }
        FUN_1409a8b10()->FUN_140cfd260()->FUN_141260cb0();
    }
    return nResult;
}

// @0x1418ed2d0
int UICharacterListDialog::vfunc_5()
{
    int nResult = UIDialog::vfunc_5();
    FUN_1409a8b10()->FUN_140cfd260()->FUN_141260e70();
    return nResult;
}

// @0x1418ed310
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::vfunc_ugc_1(void* p, CString str)
{
    if (vfunc_55() == 0)
    {
        unsigned nIndex = 0;
        CharPtr spCharacter = FindCharacter((unsigned __int64)p, &nIndex);
        if (spCharacter.get() != 0)
        {
            spCharacter->FUN_1418e9de0(str);
            m_30->FUN_140e6b140("updateProfile", nIndex, FUN_141028a90(str, 1));
        }
    }
}

// @0x1418ed4e0
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::FUN_1418ed4e0(unsigned __int64 nId, CString str)
{
    if (FindCharacter(nId).get() != 0)
        FUN_14052d220()->FUN_141883380(CString(str));
}

// @0x1418ed5a0
void UICharacterListDialog::FUN_1418ed5a0(unsigned __int64 nId, CString str)
{
    CharPtr spCharacter = FindCharacter(nId);
    if (spCharacter.get() != 0)
        spCharacter->FUN_1418e9de0(CString(str));
}

// @0x1418ed650
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
bool UICharacterListDialog::FUN_1418ed650()
{
    if (!FUN_1401c0d90()->FUN_14047bb90())
        return false;
    unsigned nValue = 0;
    if (!DAT_143ab2fc0.FUN_140482280(900, &nValue))
        return true;
    return false;
}

// @0x1418ed880
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::FUN_1418ed880(CInPacket& packet)
{
    unsigned char nMode = packet.vfunc_o8_1();
    if (nMode == 3)
    {
        DAT_143ab2a30.FUN_1403416e0();
        m_1a8.clear();
        FUN_1418ee370();
    }
    else if (nMode == 4)
    {
        m_220 = packet.vfunc_o8_0();
        if (vfunc_55() == 0 && FUN_1422dc430() == 1)
            RefreshLobby();
        else if (FUN_1408e57f0()->FUN_1422b9da0() == 0x620000c)
            PostMessageA(FUN_140aadf80()->FUN_14209c720(), 0x4c8, 0, 0);
    }
    else if (nMode == 0)
    {
        int nCount = packet.vfunc_o8_1();
        ReadCharacters(nCount, packet);
        if (FUN_1408e57f0()->FUN_1422b9da0() == 0x620000d)
            PostMessageA(FUN_140aadf80()->FUN_14209c720(), 0x4c8, 0, 0);
        RefreshSelection();
    }
    else if (nMode == 1)
    {
        ReadCharacters(1, packet);
        if (!m_1a8.empty())
        {
            int nLast = (int)m_1a8.size() - 1;
            CharPtr spCharacter = m_1a8[nLast];
            if (spCharacter.get() != 0)
            {
                SelectCharacter(spCharacter->FUN_1418e9cb0());
                m_1e0 = 1;
                FUN_1418ef980(spCharacter->FUN_1418e9cb0());
            }
            if (vfunc_55() == 0)
                OpenSelectedCharacter();
            else
                FUN_14052d220()->FUN_141880600(CharPtr(spCharacter));
        }
        RefreshSelection();
    }
    else if (nMode == 2)
    {
        int nError = packet.vfunc_o8_3();
        unsigned __int64 nId = packet.vfunc_o8_4();
        int nIndex = -1;
        if (nError == 0)
            nIndex = EraseCharacter(nId);
        if (vfunc_55() == 0)
        {
            if (nIndex < 0)
            {
                CharPtr spCharacter = FindCharacter(nId, (unsigned*)&nIndex);
                if (spCharacter.get() != 0)
                    spCharacter->FUN_1418e9ed0(0);
                ShowDeleteError(nError);
                SetDeleteState(nIndex, nId);
            }
            else
                CharacterRemoved(nId, nIndex);
        }
        m_1d8 = 0;
        RefreshSelection();
    }
    else if (nMode == 5)
    {
        if (vfunc_55() == 0)
        {
            unsigned __int64 nId = packet.vfunc_o8_4();
            int nError = packet.vfunc_o8_3();
            __int64 nDeleteTime = packet.vfunc_o8_4();
            if (nError == 0)
            {
                unsigned nIndex = 0xffffffff;
                CharPtr spCharacter = FindCharacter(nId, &nIndex);
                if (spCharacter.get() != 0)
                {
                    int nSeconds = spCharacter->FUN_1418e9fa0(nDeleteTime);
                    if (nDeleteTime > 0 && m_30.get() != 0)
                    {
                        Scaleform::GFx::Value value = m_30->FUN_1409ba0d0("requestDelete", nIndex, nSeconds);
                        if (FUN_1407cce10(&value))
                        {
                            MS2Ptr<ASMovieClip> spMovie = FUN_1409b40c0(m_28, value);
                            if (spMovie.get() != 0)
                                AddPending(CharPtr(spCharacter), MS2Ptr<ASMovieClip>(spMovie));
                        }
                    }
                }
            }
            else if (nError == 10)
            {
                CStringW strText = L"";
                strText = FUN_1405c2690(L"s_char_err_next_delete_char_date", FUN_14083bdc0(FUN_1406c47a0(nDeleteTime), 1, L"/", L":"));
                FUN_140d73aa0(CStringW(strText), 0, 0, L"");
            }
            else
                ShowDeleteError(nError);
        }
        m_1d8 = 0;
    }
    else if (nMode == 6 && vfunc_55() == 0)
    {
        unsigned __int64 nId = packet.vfunc_o8_4();
        int nError = packet.vfunc_o8_3();
        if (nError == 0)
        {
            unsigned nIndex = 0xffffffff;
            CharPtr spCharacter = FindCharacter(nId, &nIndex);
            if (spCharacter.get() != 0)
            {
                spCharacter->FUN_1418e9fa0(0);
                SetDeleteState(nIndex, nId);
            }
        }
        else
            ShowDeleteError(nError);
    }
}

// @0x1418ee370
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::FUN_1418ee370()
{
    if (m_1c0 != 0)
    {
        Unk_ClId kId;
        FUN_1401cd100(&kId, m_1c0);
        FUN_1403ed2d0()->FUN_141bbbc60(&kId, 0);
    }
    m_1c0 = 0;
    m_1c8 = 0;
    m_1d0 = 0;
}

// @0x1418ee400
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::FUN_1418ee400(int nIndex)
{
    FUN_1418ee470(FUN_1418f0730(nIndex));
}

// @0x1418ee470
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::FUN_1418ee470(CharPtr spCharacter)
{
    m_180 = 0;
    CharPtr spPreview(spCharacter);
    if (spPreview.get() == 0)
    {
        FUN_1418ee370();
        FUN_1418f1d00();
    }
    else
    {
        unsigned nSlot = FindFreePreviewSlot();
        FUN_1418ee5c0(spPreview->FUN_1418e9d70(), nSlot);
        FUN_1403ed2b0()->FUN_141adc530(0x4ef2);
        DAT_143ab2828 = spPreview->FUN_1418e9cb0();
        FUN_141b70290();
        FUN_1409a8b10()->FUN_141242990();
        FUN_14125f670(FUN_140a58500(FUN_1409a8b10()), *FUN_140a58500(FUN_1409a8b10()), false);
        FUN_14125bd20(FUN_140c58ac0(FUN_1409a8b10()), *FUN_140c58ac0(FUN_1409a8b10()));
    }
}

// @0x1418ee5c0
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::FUN_1418ee5c0(const Unk_UserProxy* pState, unsigned nSlot)
{
    FUN_1418ee370();
    if (pState->m_8 != 0)
    {
        int tmp[4];
        MyPC* pPC = 0;
        void* pMem = FUN_14208a860(0x1808, *(unsigned*)FUN_140876480(tmp, 0));
        if (pMem != 0)
            pPC = new (pMem) MyPC;
        if (pPC != 0)
        {
            m_1d0 = 1;
            if (FUN_14107b7e0(nSlot, pState, pPC) != 0)
            {
                m_1e4 = 1;
                __int64 nId = FUN_141656a80(pPC);
                m_1c0 = FUN_14123c500(pPC);
                SelectCharacter(nId);
                m_1c8 = nId;
                FUN_1418f1d00();
            }
        }
    }
}

// @0x1418ee700
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::HidePopups()
{
    FUN_1403ed2b0()->FUN_141adc5d0(0x4ef2);
    FUN_1403ed2b0()->FUN_141adc5d0(0x4ef3);
    FUN_1403ed2b0()->FUN_141adc5d0(0x4e6a);
    m_30->Invoke("popdown");
    MS2Ptr<AScript> spScript(m_30);
    FUN_1412761e0(&spScript, 0);
}

// @0x1418ee7b0
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::ReadCharacters(int nCount, CInPacket& packet)
{
    if (0 < nCount)
    {
        for (int i = 0; i < nCount; ++i)
        {
            CharPtr spCharacter(new CCharacterInfo);
            spCharacter->Read(packet);
            spCharacter->FUN_1418ea040(CCharacterInfo::FUN_1418ea080());
            m_1a8.push_back(spCharacter);
            unsigned __int64 nId = spCharacter->FUN_1418e9cb0();
            DAT_143ab2a30.FUN_1416da690(&nId);
        }
    }
}

// @0x1418ee8f0
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
int UICharacterListDialog::EraseCharacter(unsigned __int64 nId)
{
    DAT_143ab2a30.FUN_1404bfb40(&nId);
    if (!m_1a8.empty())
    {
        int nIndex = 0;
        for (std::vector<CharPtr>::iterator it = m_1a8.begin(); it != m_1a8.end(); ++it)
        {
            CharPtr spCharacter(*it);
            if (spCharacter.get() != 0 && spCharacter->FUN_1418e9cb0() == nId)
            {
                m_1a8.erase(it);
                return nIndex;
            }
            ++nIndex;
        }
    }
    return -1;
}

// @0x1418eea70
UICharacterListDialog::CharPtr UICharacterListDialog::FindCharacter(unsigned __int64 nId)
{
    unsigned nIndex = 0xffffffff;
    return FindCharacter(nId, &nIndex);
}

// @0x1418eead0
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
UICharacterListDialog::CharPtr UICharacterListDialog::FindCharacter(unsigned __int64 nId, unsigned* pnIndex)
{
    if (!m_1a8.empty())
    {
        for (unsigned i = 0; i < m_1a8.size(); ++i)
        {
            if (m_1a8[i]->FUN_1418e9cb0() == nId)
            {
                *pnIndex = i;
                return CharPtr(m_1a8[i]);
            }
        }
        return CharPtr(0);
    }
    return CharPtr(0);
}

// @0x1418eec00
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
int UICharacterListDialog::RemovePending(unsigned __int64 nId)
{
    if (nId != 0)
    {
        POSITION pos = m_1f0.GetHeadPosition();
        while (pos != 0)
        {
            DeletePtr spInfo = m_1f0.GetAt(pos);
            if (spInfo.get() != 0 && spInfo.get() != 0)
            {
                if (spInfo->m_spCharacter.get() != 0 && spInfo->m_spCharacter->FUN_1418e9cb0() == nId)
                {
                    m_1f0.RemoveAt(pos);
                    return 1;
                }
            }
            m_1f0.GetNext(pos);
        }
    }
    return 0;
}

// @0x1418eed70
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
int UICharacterListDialog::AddPending(CharPtr spCharacter, MS2Ptr<ASMovieClip> spMovie)
{
    if (spCharacter.get() != 0 && spMovie.get() != 0)
    {
        DeletePtr spFound = FindPending(spCharacter->FUN_1418e9cb0());
        if (spFound.get() != 0)
        {
            spFound->m_spCharacter = spCharacter;
            spFound->m_spMovie = spMovie;
            return 1;
        }
        DeletePtr spNew(new CDeleteCharacterInfo(spCharacter, spMovie));
        if (spNew.get() != 0)
        {
            m_1f0.AddTail(spNew);
            return 1;
        }
    }
    return 0;
}

// @0x1418ef000
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
UICharacterListDialog::DeletePtr UICharacterListDialog::FindPending(unsigned __int64 nId)
{
    if (nId != 0)
    {
        POSITION pos = m_1f0.GetHeadPosition();
        while (pos != 0)
        {
            DeletePtr spInfo = m_1f0.GetAt(pos);
            if (spInfo.get() != 0 && spInfo.get() != 0)
            {
                if (spInfo->m_spCharacter.get() != 0 && spInfo->m_spCharacter->FUN_1418e9cb0() == nId)
                    return DeletePtr(spInfo);
            }
            m_1f0.GetNext(pos);
        }
    }
    return DeletePtr(0);
}

// @0x1418ef190
void UICharacterListDialog::SetDeleteState(int nIndex, unsigned __int64 nId)
{
    RemovePending(nId);
    if (m_30.get() != 0)
        m_30->Invoke("cancelDelete", nIndex);
}

// @0x1418ef210
void UICharacterListDialog::FUN_1418ef210(int nIndex, unsigned __int64 nId)
{
    RemovePending(nId);
    if (m_30.get() != 0)
        m_30->Invoke("cancelDelete", nIndex);
}

// @0x1418ef290
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::SortCharacters()
{
    Unk_ClIdSet* pIds = &FUN_1409a8b10()->FUN_140cfd260()->m_ids;
    if (!pIds->FUN_141315e50() && !m_1a8.empty())
    {
        CCharacterInfo::FUN_1418ea0a0();
        ATL::CAtlArray<CharPtr> arrOrder;
        arrOrder.SetCount(pIds->FUN_1403ed0f0(), -1);
        for (size_t i = 0; i < m_1a8.size(); ++i)
        {
            CharPtr spCharacter(m_1a8[i]);
            if (!(spCharacter == 0))
            {
                unsigned nIndex = 0;
                if (!pIds->FUN_1418f5a10(spCharacter->FUN_1418e9cb0(), &nIndex))
                    arrOrder.Add(spCharacter);
                else
                    arrOrder.SetAt(nIndex, spCharacter);
            }
        }
        for (size_t j = 0; j < arrOrder.GetCount(); ++j)
        {
            CharPtr spCharacter(arrOrder[j]);
            if (!(spCharacter == 0))
                spCharacter->FUN_1418ea040(CCharacterInfo::FUN_1418ea080());
        }
        std::sort(m_1a8.begin(), m_1a8.end(), OrderCharacters);
    }
}

// @0x1418ef520
void UICharacterListDialog::SelectCharacter(unsigned __int64 nId)
{
    m_1a0 = nId;
    m_198.Empty();
}

// @0x1418ef560
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::RefreshSelection()
{
    DAT_143ab2944 = 1;
    for (size_t i = 0; i < m_1a8.size(); ++i)
    {
        CharPtr spCharacter(m_1a8[i]);
        if (DAT_143ab2944 < spCharacter->FUN_1418e9d70()->m_34)
            DAT_143ab2944 = spCharacter->FUN_1418e9d70()->m_34;
    }
}

// @0x1418ef630
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::FUN_1418ef630()
{
    if (!DAT_143ab2942)
        FUN_140d86260()->vfunc_22(0x3f2, "GameEnd");
    FUN_1415388a0(FUN_140714f90());
    PostQuitMessage(0);
}

// @0x1418ef690
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::FUN_1418ef690(CString strUrl)
{
    void* pBrowser = FUN_140c43790(0x4e6a);
    if (pBrowser != 0)
        FUN_14135ec00(pBrowser, strUrl, false);
}

// @0x1418ef890
// MS2-FUNCTIONAL: not byte-identical (temps / frame layout)
void UICharacterListDialog::FUN_1418ef890(unsigned __int64 nId)
{
    if (!m_30.IsNull() == false && nId != 0)
    {
        unsigned nIndex = 0;
        if (!(FindCharacter(nId, &nIndex) == 0))
            m_30->Invoke("attachBurningLevelupIcon", (int)nIndex);
    }
}
