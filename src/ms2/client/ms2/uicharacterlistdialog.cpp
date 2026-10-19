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
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/fittingdollpc.h"
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
class Unk_ClIdSet { public: void FUN_1403f19e0(); void FUN_140212bf0(unsigned __int64 nId); };
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
class Unk_ClUserMgr { public: Unk_ClUserInfo* FUN_140cfd260(); };
Unk_ClUserMgr* FUN_1409a8b10();
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
class Unk_ClWorld { public: void* FUN_141bd0cc0(); };
Unk_ClWorld* FUN_1403ed2d0();
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
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
