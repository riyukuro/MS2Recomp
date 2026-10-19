// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIServerListDialog / CMultiServer / CMultiServerChannel: see
// uiserverlistdialog.h.
// MS2-UNIT: ?\uiserverlistdialog.cpp
// MS2-RANGE: 0x14011d080-0x14011d200 .text$di
// MS2-RANGE: 0x141ad0c80-0x141ad8bc0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiserverlistdialog.cpp"    // assumed

#include <afx.h>
#include <algorithm>
#include <vector>
#include "ms2/placeholder/ms2stdafx.h"
#include "uiserverlistdialog.h"
#include "serverlisttable.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/notifyobject.h"
#include "uiscenelobbyselect.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (the exe runs them in this order: "gameexit", the sort-name table, "skill", "stun", the key input) ----
// The shared header_statics_a.h would also construct the condition after "stun"; this unit's .text$di has none.
static CStringW s_strGameExit(L"gameexit");                                             // @0x14011d080
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x14011d0b0
static CString s_strSkill = "skill";                                                    // @0x14011d170
static CString s_strStun = "stun";                                                      // @0x14011d1a0
static UICommon::CMyPCKeyInputController s_keyInputController;                          // @0x14011d1d0

// ---- unit-local views of exe objects ----

// The stored login options (FUN_1409a8b10 -> FUN_140cfd260).
class Unk_SlOptions
{
public:
    void FUN_141260a30(const CStringW& strServer);              // remember the server name
    void FUN_141260ab0(int nChannel);                           // remember the channel
    void FUN_141260b60(const CStringW& strName);                // remember the login name
    void FUN_141260c00(const __int64* pnCharId);                // remember the character id

    void* m_00;                                                 // +0x00
    CStringW m_strServer;                                       // +0x08
    CString m_strChannel;                                       // +0x10 text of the channel (atoi)
    void* m_18; void* m_20;
    __int64 m_nCharId;                                          // +0x28 the chosen character (compared in FUN_141ad2c50)
    char m_30;
    char m_bLocaledName;                                        // +0x31
};
class Unk_SlOptionsHolder { public: Unk_SlOptions* FUN_140cfd260(); void FUN_141242570(); };
Unk_SlOptionsHolder* FUN_1409a8b10();

// The packet handler table.
class Unk_SlPackets { public: void FUN_140da5180(int, Delegate<void(CInPacket&)>); void FUN_140da51e0(int, Delegate<void(CInPacket&)>); };
Unk_SlPackets* FUN_140bccd50();
void FUN_140166410();
void FUN_14036e640(CString str);

// The login network (a 73-slot interface; only the slots this unit calls are typed).
class Unk_SlLogin
{
public:
    virtual void vfunc_0();
    virtual int vfunc_1();                                      //  1 the login mode (1 = lobby)
    virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
    virtual void vfunc_7();                                     //  7 0x38: start loading
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(int nChannel, int n);                 // 20 0xa0
    virtual void vfunc_21();
    virtual void vfunc_22(int nStep, const char* szName);       // 22 0xb0 "LoginStep1" / "GameLoading"
    virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27();
    virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32();
    virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37();
    virtual void vfunc_38(); virtual void vfunc_39(); virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42();
    virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47();
    virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52();
    virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57();
    virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62();
    virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
    virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71();
    virtual void vfunc_72();                                    // 72 0x240
};
Unk_SlLogin* FUN_140d86260();

// The network, the scenes and the application objects.
class Unk_SlNetwork
{
public:
    void FUN_1415383a0(CString strHost, unsigned short nPort, int a, int b, int c);   // connect
    void FUN_1415388a0();                                       // disconnect
};
Unk_SlNetwork* FUN_140714f90();
class Unk_SlSceneApp { public: };
void* FUN_140aa6d30();
int FUN_1417e2610(void* pObj);
void FUN_1417e25a0(void* pObj, unsigned n);
class Unk_SlWindow { public: HWND FUN_14209c720(); };
class Unk_SlApp { public: };
Unk_SlWindow* FUN_140aadf80();
void* FUN_1403ed2d0();
void FUN_141bca1e0(void* pObj);
void* FUN_1403ed2b0();
void FUN_141adc5d0(void* pObj, int nId);
void* FUN_140939a10();
void FUN_140da4fe0(void* pObj, MS2Ptr<NotifyObject> spNotify);
CServerListTable* FUN_1414a5790();
int FUN_1406c34c0();                                            // the Nexon platform is active
int FUN_14092f640();
CStringW FUN_14028de60(int nStringId);                          // string table text by id
CStringW FUN_1408116a0(int nId, const int& n);                  // formatted notice text
void FUN_140d73aa0(CStringW strText, int a, int b, CStringW strTag);
extern CStringW DAT_143af62c0;
extern CString DAT_143ab29d8;
extern CString DAT_143ab2a28;
extern int DAT_143ab2914;
extern int DAT_143ab285c;
extern int DAT_143ab2858;
extern int DAT_1439f4a7c;
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs, UIDialog* pDialog);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& a);    // set a Value from an AS object
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);                // set an Int value
class Unk_SlKeys { public: char FUN_14116d890(int nKey); };
Unk_SlKeys* FUN_14025e7c0();

class Unk_SlBanner { public: void FUN_141031260(); void FUN_1410312d0(); };
Unk_SlBanner* FUN_141876420(int nId);
class Unk_SlRanking { public: void FUN_140b2c7d0(); };
Unk_SlRanking* FUN_140b2e980();
class Unk_SlLobby { public: void FUN_14174f470(); };
Unk_SlLobby* FUN_140f30370();
const int* FUN_1404eb7e0(const int* a, const int* b);           // std::max<int>
const int* FUN_1402fbd20(const int* a, const int* b);           // std::min<int>
UIServerListDialog* FUN_14136f520(int nId);                     // the dialog by UI id

// The login request (encoded by 0x1401f9020; ctor / dtor in uilogindialog.cpp).
void* FUN_14067c020(void* pId);                                 // zero-inits the 16-byte id
struct Unk_LoginMachineId
{
    Unk_LoginMachineId() { FUN_14067c020(this); }
    unsigned char m_data[16];
};
struct Unk_LoginRequest
{
    Unk_LoginRequest();                                         // 0x1419e2f80
    ~Unk_LoginRequest();                                        // 0x1419e3060
    unsigned m_nType;                                           // +0x00
    CString m_strId;                                            // +0x08
    CString m_strPassword;                                      // +0x10
    unsigned m_nLoginType;                                      // +0x18
    Unk_LoginMachineId m_machineId;                             // +0x1c
    int m_n2c;                                                  // +0x2c
    int m_n30;                                                  // +0x30
    CString m_strRegion;                                        // +0x38
};
MS2_CHECK_SIZE(Unk_LoginRequest, 0x40);
void FUN_1401f9020(Unk_LoginRequest* pRequest, COutPacket* pOut);
class Unk_LoginMachine
{
public:
    const Unk_LoginMachineId& FUN_140d4fdf0();
    int FUN_140d4fe10();
};
Unk_LoginMachine* FUN_140aadf70();
void FUN_14067c080(Unk_LoginMachineId* pDst, const Unk_LoginMachineId& src);
int FUN_1406516a0();
int FUN_1406516b0();                                            // the language / region id
CString FUN_1406521f0(int nRegion);
CString FUN_1401d2b10(const CString& a, const CString& b);      // a + b
CString FUN_140652030(int n);
void FUN_140710590(COutPacket& packet);                         // send the packet

// The reply of the enter-game packet (opcode 10); defined in networkservice.cpp (ctor 0x141540de0, dtor 0x141541170).
struct Unk_NetworkLoginResult {
    Unk_NetworkLoginResult();
    void FUN_1407a4740(CInputStream&);
    int result,error;__int64 id;CStringW message;__int64 a18;int zone,zoneFlag;bool flag;__int64 a30,start,end;int value,a4c;__int64 a50;
};
MS2_CHECK_SIZE(Unk_NetworkLoginResult,0x58);
class Unk_SlClientInfo { public: void FUN_141473690(__int64 tServer); };
Unk_SlClientInfo* FUN_14086d260();
void FUN_141b70390();
class Unk_SlBlind { public: void FUN_140a250a0(); };
Unk_SlBlind* FUN_1409c1730();
extern __int64 DAT_143ab2820;
extern int DAT_143ab2834;
extern __int64 DAT_143ab2838;
extern char DAT_143ab284b;

// The sort order of the server list (0x141ad5e00): by server id.
struct Unk_SlServerOrder
{
    // @0x141ad5e00
    bool operator()(const MS2Ptr<CMultiServer>& lhs, const MS2Ptr<CMultiServer>& rhs) const
    {
        return lhs->m_nId < rhs->m_nId;
    }
};

// The notice posted when the chosen character changes.
class NotifyChangeMyPC : public NotifyObject
{
public:
    NotifyChangeMyPC();                                         // 0x141ad5990
    virtual CStringW vfunc_1();                                 // 0x140db45b0 (unit_140da50e0.cpp)
};
MS2_CHECK_SIZE(NotifyChangeMyPC, 0x18);

// The enter-game request body (encoded by 0x1401f9e60).
struct Unk_SlEnterRequest
{
    Unk_SlEnterRequest() : m_nCharId(0), m_nChannel(0) {}       // 0x141ad59c0
    __int64 m_nCharId;                                          // +0x00
    int m_nChannel;                                             // +0x08
};
void FUN_1401f9e60(Unk_SlEnterRequest* pRequest, COutPacket* pOut);
class ASDialog : public ASDisplayObject { public: };
class Unk_SlWorld { public: void FUN_141bca1e0(); int FUN_141bd9870(); };

// AScript with the "buildServerList" invoke shape (array, int, int, int, int).
class Unk_SlScript : public AScript
{
public:
    // @0x141ad3800
    Scaleform::GFx::Value FUN_141ad3800(const char* szMethod, const ASArray& arr, int a, int b, int c, int d);
    Scaleform::GFx::Value FUN_140e813f0(const char* szMethod, const ASArray& arr, int n);   // regionlist's copy of the same shape
};

// @0x141ad3800
Scaleform::GFx::Value Unk_SlScript::FUN_141ad3800(const char* szMethod, const ASArray& arr, int a, int b, int c, int d)
{
    ASArgList args;
    args.FUN_1409b2800(5);
    FUN_1422bce40(args.FUN_1409b1f70(0), arr);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a);
    FUN_1422bccb0(args.FUN_1409b1f70(2), b);
    FUN_1422bccb0(args.FUN_1409b1f70(3), c);
    FUN_1422bccb0(args.FUN_1409b1f70(4), d);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- the dialog ----

// @0x141ad0c80
UIServerListDialog::UIServerListDialog()
    : m_nServerId(-1), m_nChannel(-1), m_nConnecting(0), m_nSceneId(0), m_servers(10)
{
    m_80 = 0;
    m_strServer = FUN_1409a8b10()->FUN_140cfd260()->m_strServer;
    FUN_141925e70(0, 1);
    FUN_140bccd50()->FUN_140da5180(11, Delegate<void(CInPacket&)>(this, &UIServerListDialog::ReceiveServerList));
}

// @0x141ad0e30
UIServerListDialog::~UIServerListDialog()
{
    FUN_140bccd50()->FUN_140da51e0(11, Delegate<void(CInPacket&)>(this, &UIServerListDialog::ReceiveServerList));
}

// @0x141ad0f30
CString UIServerListDialog::vfunc_1()
{
    return "ServerListDialog";
}

// @0x141ad0f80
size_t UIServerListDialog::FUN_141ad0f80()
{
    ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> >::CPair* pPair = m_servers.Lookup(FUN_141ad1030());
    if (pPair == 0)
        return 0;
    return pPair->m_value->m_channels.GetCount();
}

// @0x141ad1010
int UIServerListDialog::FUN_141ad1010()
{
    return m_nServerId;
}

// @0x141ad1030
CStringW UIServerListDialog::FUN_141ad1030()
{
    return m_strServer;
}

// @0x141ad1080
void UIServerListDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    CInPacket* pIn = static_cast<CInPacket*>(pPacket);
    int nOpcode = pIn->FUN_14070fe80();
    if (nOpcode == 9) {
        FUN_141ad28f0(pPacket);
    } else if (nOpcode == 10) {
        FUN_141ad2b50(pIn);
    } else if (nOpcode == 12 && pIn->vfunc_o8_1() == 3) {
        m_nSceneId = 0x620001b;
        m_nConnecting = 0;
        FUN_141ad3310();
    }
}

// @0x141ad1150
void UIServerListDialog::ReceiveServerList(CInPacket& packet)
{
    m_servers.RemoveAll();
    FUN_140166410();
    FUN_14036e640(packet.vfunc_o8_7());
    unsigned char nCount = packet.vfunc_o8_1();
    if (nCount != 0) {
        for (int i = 0; i < (int)nCount; i++) {
            MS2Ptr<CMultiServer> server(new CMultiServer);
            int nId = packet.vfunc_o8_3();
            server->m_nId = nId;
            server->m_strName = packet.vfunc_o8_8();
            unsigned nCharacters = packet.vfunc_o8_1();
            server->m_nCharacterCount = nCharacters;
            unsigned nAddresses = (unsigned short)packet.vfunc_o8_2();
            for (int j = 0; j < (int)nAddresses; j++) {
                server->m_addresses.Add(packet.vfunc_o8_6());
                server->m_ports.Add(packet.vfunc_o8_2());
            }
            int nTraffic = packet.vfunc_o8_3();
            server->m_nTrafficPercent = nTraffic;
            unsigned nChannels = (unsigned short)packet.vfunc_o8_2();
            for (int j = 0; j < (int)nChannels; j++) {
                MS2Ptr<CMultiServerChannel> channel(new CMultiServerChannel);
                unsigned nChannelId = (unsigned short)packet.vfunc_o8_2();
                channel->m_nId = nChannelId;
                server->m_channels.SetAt(channel->m_nId, channel);
            }
            m_servers.SetAt(server->m_strName, server);
        }
    }
    FUN_1409a8b10()->FUN_140cfd260()->FUN_141260b60(CStringW(DAT_143ab29d8));
}

// @0x141ad16b0
void UIServerListDialog::OnLoadComplete()
{
    m_nConnecting = 0;
    UIDialog::OnLoadComplete();
    int nChannel[2];
    nChannel[0] = atoi(FUN_1409a8b10()->FUN_140cfd260()->m_strChannel);
    nChannel[1] = 1;
    m_nChannel = *FUN_1404eb7e0(&nChannel[1], &nChannel[0]);
    FUN_141ad1d20();
    if (FUN_140d86260()->vfunc_1() == 1) {
        Unk_SlBanner* pBanner = FUN_141876420(0x4eca);
        if (pBanner != 0)
            pBanner->FUN_141031260();
    } else {
        if (DAT_143ab285c == 0) {
            FUN_141ad2560(m_nChannel);
        } else {
            Unk_SlLobby* pLobby = FUN_140f30370();
            if (pLobby != 0)
                pLobby->FUN_14174f470();
        }
        vfunc_8(0);
    }
    if (FUN_140b2e980() != 0)
        FUN_140b2e980()->FUN_140b2c7d0();
    FUN_140d86260()->vfunc_22(0x2bd, "LoginStep1");
}

// @0x141ad1810
int UIServerListDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UISceneLobbyServer*>(pSender) != 0) {
        CString strMethod = pMsg->FUN_1422b8d30();
        strMethod = "OnReset";
        if ((const char*)strMethod != 0) {
            m_strServer = FUN_1409a8b10()->FUN_140cfd260()->m_strServer;
            m_nServerId = -1;
            int nChannel[2];
            nChannel[0] = atoi(FUN_1409a8b10()->FUN_140cfd260()->m_strChannel);
            nChannel[1] = 1;
            m_nChannel = *FUN_1404eb7e0(&nChannel[1], &nChannel[0]);
            return 1;
        }
        if (FUN_1406c34c0() == 1)
            FUN_140d86260()->vfunc_72();
    }
    return 0;
}

// @0x141ad19b0
int UIServerListDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (FUN_14025e7c0()->FUN_14116d890(0) == 0)
        return 0;
    m_30->Invoke("onEnterKey");
    return 1;
}

// @0x141ad1a30
int UIServerListDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, this) != 0)
        return 1;
    if (_stricmp("OnSceneLogin", szMethod) == 0) {
        m_nSceneId = 0x6200009;
        FUN_141ad3310();
        return 1;
    }
    if (_stricmp("OnSelectServer", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            FUN_141ad25a0(data.FUN_1422b8f40());
            return 1;
        }
    } else if (_stricmp("OnConnectServer", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            m_strServer = data.FUN_1422b8f40();
            FUN_141ad2560(data.FUN_1422b8a10());
            return 1;
        }
    } else if (_stricmp("OnEndPopdown", szMethod) == 0) {
        FUN_141ad31d0();
        return 1;
    }
    return 0;
}

// @0x141ad1cc0
void UIServerListDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_nSceneId = 0;
    m_nConnecting = 0;
    Unk_SlBanner* pBanner = FUN_141876420(0x4eca);
    if (pBanner != 0)
        pBanner->FUN_1410312d0();
}

// @0x141ad1d20
void UIServerListDialog::FUN_141ad1d20()
{
    ASArray array(2);
    int nSelectedId = -1;
    int nSelectedIndex = -1;
    if (!m_servers.IsEmpty()) {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0) {
            std::vector<MS2Ptr<CMultiServer> > servers;
            POSITION pos = m_servers.GetHeadPosition();
            while (pos != 0) {
                servers.push_back(m_servers.GetValueAt(pos));
                m_servers.GetNext(pos);
            }
            std::sort(servers.begin(), servers.end(), Unk_SlServerOrder());
            int nCount = (int)servers.size();
            for (int i = 0; i < nCount; i++) {
                MS2Ptr<CMultiServer> server(servers[i]);
                if (server.get() != 0) {
                    if (server->m_strName == m_strServer) {
                        nSelectedId = server->m_nId;
                        nSelectedIndex = i;
                        int nChannels = (int)server->m_channels.GetCount();
                        int nOne = 1;
                        m_nChannel = *FUN_1404eb7e0(&nOne, FUN_1402fbd20(&m_nChannel, &nChannels));
                    }
                    CServerListTable::InfoPtr info = FUN_1414a5790()->GetServer(server->m_nId);
                    if (info == 0)
                        info = FUN_1414a5790()->GetFirstServer();
                    if (info.get() == 0) {
                        int nNoticeArg = 99999;
                        FUN_140d73aa0(FUN_1408116a0(0x20e, nNoticeArg), 0, 0, DAT_143af62c0);
                    } else {
                        ASObj row(2);
                        row.FUN_1407cbb20("label", info->m_strName);
                        row.FUN_1407cba60("icon", info->m_strIcon);
                        row.FUN_1407cbb20("id", server->m_strName);
                        row.FUN_1407cb9c0("charCnt", server->m_nCharacterCount);
                        row.FUN_1407cb9c0("trafficPercent", server->m_nTrafficPercent);
                        array.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
                    }
                }
            }
        }
    }
    m_nServerId = nSelectedId;
    static_cast<Unk_SlScript*>(m_30.operator->())->FUN_141ad3800("buildServerList", array, nSelectedIndex, m_nChannel, 1, 1);
}

// @0x141ad2380
void UIServerListDialog::FUN_141ad2380()
{
    if (m_strServer.IsEmpty())
        return;
    ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> >::CPair* pPair = m_servers.Lookup(m_strServer);
    if (pPair == 0)
        return;
    CMultiServer* pServer = pPair->m_value.get();
    if (pServer->m_addresses.IsEmpty())
        return;
    int nIndex = rand();
    nIndex = nIndex % (int)pServer->m_addresses.GetCount();
    CString strHost = pServer->m_addresses[nIndex];
    unsigned short nPort = pServer->m_ports[nIndex];
    FUN_140714f90()->FUN_1415383a0(strHost, nPort, 1, 1, 0);
    m_nConnecting = 1;
    m_30->Invoke("requestConnect");
}

// @0x141ad2560
void UIServerListDialog::FUN_141ad2560(int nChannel)
{
    if (m_nConnecting == 0) {
        FUN_141ad2ea0(nChannel);
        FUN_141ad2380();
    }
}

// @0x141ad25a0
void UIServerListDialog::FUN_141ad25a0(CStringW strServer)
{
    ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> >::CPair* pPair = m_servers.Lookup(strServer);
    if (pPair == 0)
        return;
    CMultiServer* pServer = pPair->m_value.get();
    if (pServer == 0)
        return;
    if (m_strServer == strServer)
        m_nChannel = 1;
    m_strServer = strServer;
    int nOne = 1;
    m_nServerId = *FUN_1404eb7e0(&pServer->m_nId, &nOne);
    int bSelected = 0;
    int nSelectedIndex = -1;
    ASArray array(2);
    MS2Ptr<CMultiServer> server(pServer);
    FUN_141ad3370(array, &nSelectedIndex, m_nChannel, server);
    static_cast<Unk_SlScript*>(m_30.operator->())->FUN_140e813f0("buildChannelList", array, nSelectedIndex);
    if (bSelected != 0) {
        float fLimit = 1.0f;
        bool bFound = false;
        ATL::CRBMap<int, MS2Ptr<CMultiServerChannel> >::CPair* pChannel = pServer->m_channels.Lookup(m_nChannel);
        if (pChannel != 0) {
            CMultiServerChannel* pCh = pChannel->m_value.get();
            if (pCh != 0) {
                if (pCh->HasLowerLoad(fLimit) != 0) {
                    m_nChannel = pCh->m_nId;
                    bFound = true;
                }
            }
        }
        if (!bFound) {
            POSITION pos = pServer->m_channels.GetHeadPosition();
            while (pos != 0) {
                CMultiServerChannel* pCh = pServer->m_channels.GetValueAt(pos).get();
                if (pCh != 0) {
                    if (pCh->HasLowerLoad(fLimit) != 0) {
                        m_nChannel = pCh->m_nId;
                        bFound = true;
                        break;
                    }
                }
                pServer->m_channels.GetNext(pos);
            }
        }
        if (!bFound)
            m_nChannel = 1;
    }
}

// @0x141ad28f0
void UIServerListDialog::FUN_141ad28f0(void* pPacket)
{
    int nScene = FUN_1417e2610(FUN_140aa6d30());
    if (nScene != 0x620000d)
        return;
    if (FUN_1406c34c0() == 0) {
        Unk_LoginRequest request;
        request.m_nType = 2;
        request.m_strId = DAT_143ab29d8;
        request.m_strPassword = DAT_143ab2a28;
        request.m_nLoginType = m_nChannel;
        FUN_14067c080(&request.m_machineId, FUN_140aadf70()->FUN_140d4fdf0());
        request.m_n2c = FUN_140aadf70()->FUN_140d4fe10();
        request.m_n30 = DAT_143ab2858;
        request.m_strRegion = FUN_140652030(FUN_1406516a0());
        if (FUN_1409a8b10()->FUN_140cfd260()->m_bLocaledName == 1)
            request.m_strId = FUN_1401d2b10(DAT_143ab29d8, FUN_1406521f0(FUN_1406516b0()));
        COutPacket packet(3, 0);
        FUN_1401f9020(&request, &packet);
        FUN_140710590(packet);
    } else {
        FUN_140d86260()->vfunc_20(m_nChannel, 2);
    }
}

// @0x141ad2b50
void UIServerListDialog::FUN_141ad2b50(CInPacket* pPacket)
{
    Unk_NetworkLoginResult reply;
    reply.FUN_1407a4740(*pPacket);
    if (reply.result == 0) {
        FUN_14086d260()->FUN_141473690(reply.a18);
        CMsTime::SetTimeZone(reply.zone, reply.zoneFlag);
        DAT_143ab2820 = reply.id;
        DAT_1439f4a7c = m_nChannel;
        DAT_143ab2834 = reply.a4c;
        DAT_143ab2838 = reply.a50;
        FUN_141b70390();
        FUN_1409a8b10()->FUN_141242570();
        FUN_1409c1730()->FUN_140a250a0();
    } else {
        FUN_141ad2ef0();
    }
}

// @0x141ad2c50
int UIServerListDialog::FUN_141ad2c50(__int64 nCharId, __int64 n3)
{
    int nChannel = m_nChannel;
    if (nChannel == 0)
        nChannel = FUN_14092f640();
    DAT_1439f4a7c = nChannel;
    static_cast<Unk_SlWorld*>(FUN_1403ed2d0())->FUN_141bca1e0();
    Unk_SlEnterRequest request;
    request.m_nCharId = nCharId;
    request.m_nChannel = nChannel;
    COutPacket packet(9, 0);
    packet.vfunc_o10_1(0);
    FUN_1401f9e60(&request, &packet);
    FUN_140710590(packet);
    Unk_SlOptions* pOptions = FUN_1409a8b10()->FUN_140cfd260();
    if (pOptions != 0) {
        if (pOptions->m_nCharId != nCharId)
            FUN_140da4fe0(FUN_140939a10(), MS2Ptr<NotifyObject>(new NotifyChangeMyPC));
        pOptions->FUN_141260c00(&nCharId);
        pOptions->FUN_141260a30(FUN_141ad1030());
        if (nChannel != 0)
            pOptions->FUN_141260ab0(nChannel);
    }
    FUN_140d86260()->vfunc_7();
    FUN_140d86260()->vfunc_22(0x2c6, "GameLoading");
    return 1;
}

// @0x141ad2ea0
void UIServerListDialog::FUN_141ad2ea0(int nChannel)
{
    m_nChannel = nChannel;
    if (nChannel != 0)
        FUN_1409a8b10()->FUN_140cfd260()->FUN_141260ab0(nChannel);
}

// @0x141ad2ef0
void UIServerListDialog::FUN_141ad2ef0()
{
    if (vfunc_55() == 0) {
        m_nConnecting = 0;
        m_30->Invoke("failConnect");
    }
}

// @0x141ad2f60
void UIServerListDialog::FUN_141ad2f60(ASArray& array, int* pnSelected, int nSelectedChannel)
{
    ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> >::CPair* pPair = m_servers.Lookup(FUN_141ad1030());
    if (pPair != 0)
        FUN_141ad3370(array, pnSelected, nSelectedChannel, MS2Ptr<CMultiServer>(pPair->m_value));
}

// @0x141ad3030
void UIServerListDialog::FUN_141ad3030(const ATL::CAtlArray<int>& channels)
{
    ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> >::CPair* pPair = m_servers.Lookup(FUN_141ad1030());
    if (pPair != 0) {
        pPair->m_value->m_channels.RemoveAll();
        for (unsigned i = 0; i < channels.GetCount(); i++) {
            int nId = channels[i];
            MS2Ptr<CMultiServerChannel> channel(new CMultiServerChannel);
            channel->m_nId = nId;
            pPair->m_value->m_channels.SetAt(nId, channel);
        }
    }
}

// @0x141ad31b0
int UIServerListDialog::FUN_141ad31b0()
{
    return m_nChannel;
}

// @0x141ad31d0
void UIServerListDialog::FUN_141ad31d0()
{
    if (m_nSceneId == 0x6200009) {
        FUN_140714f90()->FUN_1415388a0();
        FUN_1417e25a0(FUN_140aa6d30(), 0x6200009);
    } else if (m_nSceneId == 0x620001b && FUN_140f30370() != 0) {
        HWND hWnd = FUN_140aadf80()->FUN_14209c720();
        PostMessageA(hWnd, 0x4c8, 0, 0);
    }
}

// @0x141ad3260
bool UIServerListDialog::FUN_141ad3260(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0) {
        COutPacket packet(0x6d, 0);
        packet.vfunc_o10_1(1);
        FUN_140710590(packet);
        UIServerListDialog* pDialog = FUN_14136f520(0x4ef0);
        if (pDialog != 0)
            pDialog->FUN_141ad2ef0();
        DAT_143ab2858 = 0;
        DAT_143ab285c = 0;
        DAT_143ab284b = 0;
    }
    return true;
}

// @0x141ad3310
void UIServerListDialog::FUN_141ad3310()
{
    FUN_141adc5d0(FUN_1403ed2b0(), 0x4ef3);
    m_30->Invoke("popdown");
}

// @0x141ad3370
void UIServerListDialog::FUN_141ad3370(ASArray& array, int* pnSelected, int nSelectedChannel, MS2Ptr<CMultiServer> server)
{
    if (server.get() != 0) {
        int nIndex = 0;
        ATL::CRBMap<int, MS2Ptr<CMultiServerChannel> >* pChannels = &server->m_channels;
        if (!pChannels->IsEmpty()) {
            CStringW strPattern(L"{0} {1}");
            CStringW strChannel = FUN_14028de60(0x579);
            POSITION pos = pChannels->GetHeadPosition();
            while (pos != 0) {
                MS2Ptr<CMultiServerChannel> channel(pChannels->GetValueAt(pos));
                if (channel.get() != 0) {
                    int nId = channel->m_nId;
                    int nLimit = static_cast<Unk_SlWorld*>(FUN_1403ed2d0())->FUN_141bd9870();
                    if (DAT_143ab2914 > 49 || nId == nSelectedChannel || nId <= nLimit) {
                        ASObj row(2);
                        row.FUN_1407cb9c0("id", nId);
                        CStringW strLabel = StringFormat((const wchar_t*)strPattern, strChannel, nId);
                        row.FUN_1407cbb20("label", strLabel);
                        row.FUN_1407cbb20("labelDropdown", strLabel);
                        if (nId == nSelectedChannel)
                            *pnSelected = nIndex;
                        array.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
                        nIndex++;
                    }
                }
                pChannels->GetNext(pos);
            }
        }
    }
}

// @0x141ad5740
CMultiServer::CMultiServer()
    : m_nId(0), m_nCharacterCount(0), m_n6c(0), m_n70(0), m_nTrafficPercent(0), m_channels(10)
{
}

// @0x141ad5800
CMultiServerChannel::CMultiServerChannel()
    : m_nId(0), m_n1c(0), m_n20(0)
{
}

// @0x141ad5990
NotifyChangeMyPC::NotifyChangeMyPC()
{
}

// @0x141ad5ba0
CMultiServer::~CMultiServer()
{
}

// @0x141ad5c00
CMultiServerChannel::~CMultiServerChannel()
{
}

// @0x141ad6460 is UIServerListDialog::vfunc_48 (inline in the header).

// @0x141ad6790
int CMultiServerChannel::HasLowerLoad(float fLimit) const
{
    if (m_n20 == 0 || fLimit <= (float)m_n1c / (float)m_n20)
        return 0;
    return 1;
}

MS2_EMIT_CRT_MEMMOVE_S();
