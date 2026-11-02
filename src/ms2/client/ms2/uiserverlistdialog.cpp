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
#include "ms2/client/ms2/uiattendgiftdialog.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/client/ms2/scenestatemulti.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/blindmanager.h"
#include "ms2/client/ms2/gamerankingcli.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/serverlisttable.h"
#include "ms2/client/ms2/uiservice.h"  // C3: CUIService::FUN_141adc5d0
#include "ms2/placeholder/packethandlermanager.h"  // C3: PacketHandlerManager::RegisterHandler/UnregisterHandler
#include <efd/Win32/Win32PlatformService.h>  // C3: efd::Win32PlatformService::GetWindowRef
#include <algorithm>
#include "ms2/placeholder/cgameoption.h"  // C3: CGameOption::LoadAccountOption
#include "ms2/commonfiles/featuremanager.h"  // C3: CFeatureManager::SetServerTypeName
#include "ms2/client/ms2/statemanager.h"  // C3: TSingleton<CStateService>
#include "ms2/commonfiles/serverpacketdef.h"  // C3: Unk_SPDF::FUN_1407a4740
#include "ms2/guess/machineidmanager.h"  // C3: CMachineIDManager::GetID/GetValue
#include "ms2/placeholder/blockformat.h"  // C3: BlockFormat<int> calls FUN_14028dee0

// ---- statics (the exe runs them in this order: "gameexit", the sort-name table, "skill", "stun", the key input) ----
// The shared header_statics_a.h would also construct the condition after "stun"; this unit's .text$di has none.
#ifndef MS2_HOOK_DLL   // s_strGameExit: the exe's object at 0x143af62c0, which other units reach as DAT_143af62c0 (the hook DLL binds it)
CStringW DAT_143af62c0(L"gameexit");                                             // @0x14011d080
#else
extern CStringW DAT_143af62c0;
#endif
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x14011d0b0
static CString s_strSkill = "skill";                                                    // @0x14011d170
static CString s_strStun = "stun";                                                      // @0x14011d1a0
static UICommon::CMyPCKeyInputController s_keyInputController;                          // @0x14011d1d0

// ---- unit-local views of exe objects ----

// The stored login options (CGameOption -> Unk_LgSettings::FUN_140cfd260), gameoptionstruct.cpp's Unk_GsConnect.
// C3: its setters are gameoptionstruct.cpp's free functions on the record.
struct Unk_GsConnect;
void FUN_141260a30(Unk_GsConnect* p, const CStringW& strWorldName);    // remember the server name
void FUN_141260ab0(Unk_GsConnect* p, int nChannel);                    // remember the channel
void FUN_141260b60(Unk_GsConnect* p, const CString& strUserName);      // remember the login name (CStringA)
void FUN_141260c00(Unk_GsConnect* p, const unsigned __int64& nCharSN); // remember the character id
class Unk_SlOptions
{
public:
    void* m_00;                                                 // +0x00
    CStringW m_strServer;                                       // +0x08
    CString m_strChannel;                                       // +0x10 text of the channel (atoi)
    void* m_18; void* m_20;
    __int64 m_nCharId;                                          // +0x28 the chosen character (compared in FUN_141ad2c50)
    char m_30;
    unsigned char m_bLocaledName;                               // +0x31
};
class Unk_LgSettings { public: CStringW* FUN_140cfd260(); };   // C3: gameoptionlanguage.cpp's view of CGameOption

// The packet handler table.
class Unk_SlPackets { public: void FUN_140da5180(int, Delegate<void(CInPacket&)>); void FUN_140da51e0(int, Delegate<void(CInPacket&)>); };
class Unk_140bccd50* FUN_140bccd50();   // C3: was FUN_140bccd50
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410

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
void* FUN_140d86260();   // C3: was FUN_140d86260

// The network, the scenes and the application objects.
class CNetworkService { public: int ConnectTo(CString, int, int, int, int); void SendRequestQuitAndDisconnect(); };   // networkservice.h's service (its header redeclares FUN_140d86260)
CNetworkService* FUN_140714f90();
class Unk_SlSceneApp { public: };
class Unk_SlApp { public: };
void* FUN_140aadf80();   // C3: was FUN_140aadf80
void FUN_141bca1e0(void* pObj);
class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10
class NotifySystem { public: void Post(MS2Ptr<NotifyObject> spNotify); };   // the notify system (FUN_140939a10)
int FUN_1406c34c0();                                            // the Nexon platform is active
int FUN_14092f640();
CStringW GetStringCommon(int nStringId);                          // string table text by id
void FUN_140d73aa0(CStringW strText, int a, void* pListener, CStringW strTag);
extern CStringW DAT_143af62c0;
extern CString DAT_143ab29d8;
extern CString DAT_143ab2a28;
extern int DAT_143ab2914;
extern int DAT_143ab285c;
extern int DAT_143ab2858;
extern int DAT_1439f4a7c;
int FUN_1418fc760(char const*, void*, int, void*);   // C3: was FUN_1418fc760
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& a);    // set a Value from an AS object
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);                // set an Int value
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

template <class T> T* Unk_UgcGetDialog(int nId);
CSceneStateMulti* FUN_140f30370();
void* FUN_14136f520(int);   // C3: was FUN_14136f520

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
void FUN_1401f9020(struct Unk_LoginA*, class COutputStream*);   // C3: was FUN_1401f9020
void* FUN_140aadf70();   // C3: was FUN_140aadf70
void FUN_14067c080(Unk_LoginMachineId* pDst, const Unk_LoginMachineId& src);
int FUN_1406516a0();
int FUN_1406516b0();                                            // the language / region id
CString FUN_1406521f0(int nRegion);
CString FUN_1401d2b10(const CString& a, const CString& b);      // a + b (clang: operator+ needs the MFC CopyChars import)
CString FUN_140652030(int n);
void FUN_140710590(COutPacket& packet);                         // send the packet

// The reply of the enter-game packet (opcode 10); defined in networkservice.cpp (ctor 0x141540de0, dtor 0x141541170).
struct Unk_NetworkLoginResult {
    Unk_NetworkLoginResult();
    int result,error;__int64 id;CStringW message;__int64 a18;int zone,zoneFlag;bool flag;__int64 a30,start,end;int value,a4c;__int64 a50;
};
MS2_CHECK_SIZE(Unk_NetworkLoginResult,0x58);
void FUN_141b70390();
class Unk_MeratBlindManager* FUN_1409c1730();   // C3: ugcmanager_4.cpp's return type
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
    virtual CStringW GetTypeName();                                 // 0x140db45b0 (unit_140da50e0.cpp)
};
MS2_CHECK_SIZE(NotifyChangeMyPC, 0x18);

// The enter-game request body (encoded by 0x1401f9e60).
struct Unk_SlEnterRequest
{
    Unk_SlEnterRequest() : m_nCharId(0), m_nChannel(0) {}       // 0x141ad59c0
    __int64 m_nCharId;                                          // +0x00
    int m_nChannel;                                             // +0x08
};
void FUN_1401f9e60(struct Unk_LoginPing*, class COutputStream*);   // C3: was FUN_1401f9e60
class ASDialog : public ASDisplayObject { public: };

// AScript with the "buildServerList" invoke shape (array, int, int, int, int).
class Unk_SlScript : public AScript
{
public:
    // @0x141ad3800
    Scaleform::GFx::Value FUN_141ad3800(const char* szMethod, const ASArray& arr, int a, int b, int c, int d);
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
    m_strServer = reinterpret_cast<Unk_SlOptions*>(reinterpret_cast<Unk_LgSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140cfd260())->m_strServer;
    FUN_141925e70(0, 1);
    ((class PacketHandlerManager*)FUN_140bccd50())->RegisterHandler(11, Delegate<void(CInPacket&)>(this, &UIServerListDialog::ReceiveServerList));
}

// @0x141ad0e30
UIServerListDialog::~UIServerListDialog()
{
    ((class PacketHandlerManager*)FUN_140bccd50())->UnregisterHandler(11, Delegate<void(CInPacket&)>(this, &UIServerListDialog::ReceiveServerList));
}

// @0x141ad0f30
CString UIServerListDialog::GetTypeName()
{
    return "ServerListDialog";
}

// @0x141ad0f80
size_t UIServerListDialog::FUN_141ad0f80()
{
    if (ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> >::CPair* pPair = m_servers.Lookup(GetServer()))
        return pPair->m_value->m_channels.GetCount();
    return 0;
}

// @0x141ad1010
int UIServerListDialog::GetServerId()
{
    return m_nServerId;
}

// @0x141ad1030
CStringW UIServerListDialog::GetServer()
{
    return m_strServer;
}

// @0x141ad1080
void UIServerListDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    switch (static_cast<CInPacket*>(pPacket)->FUN_14070fe80())
    {
    case 9:
        FUN_141ad28f0(pPacket);
        break;
    case 10:
        FUN_141ad2b50(static_cast<CInPacket*>(pPacket));
        break;
    case 12:
        if (static_cast<CInPacket*>(pPacket)->ReadUInt8() == 3)
        {
            m_nSceneId = 0x620001b;
            m_nConnecting = 0;
            OnSceneLogin();
        }
        break;
    }
}

// @0x141ad1150
void UIServerListDialog::ReceiveServerList(CInPacket& packet)
{
    m_servers.RemoveAll();
    FUN_140166410();
    CFeatureManager::SetServerTypeName(packet.ReadString());
    int nCount = packet.ReadUInt8();
    if (nCount == 0) {
    } else {
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<CMultiServer> server(new CMultiServer);
            int nId = packet.ReadInt32();
            server->m_nId = nId;
            server->m_strName = packet.ReadUnicodeString();
            unsigned nCharacters = packet.ReadUInt8();
            server->m_nCharacterCount = nCharacters;
            unsigned nAddresses = (unsigned short)packet.ReadInt16();
            for (int j = 0; j < (int)nAddresses; j++) {
                server->m_addresses.Add(packet.ReadUnicodeStringA());
                server->m_ports.Add(packet.ReadInt16());
            }
            int nTraffic = packet.ReadInt32();
            server->m_nTrafficPercent = nTraffic;
            unsigned nChannels = (unsigned short)packet.ReadInt16();
            for (int j = 0; j < (int)nChannels; j++) {
                MS2Ptr<CMultiServerChannel> channel(new CMultiServerChannel);
                unsigned nChannelId = (unsigned short)packet.ReadInt16();
                channel->m_nId = nChannelId;
                server->m_channels.SetAt(channel->m_nId, channel);
            }
            m_servers.SetAt(server->m_strName, server);
        }
    }
    FUN_141260b60((Unk_GsConnect*)reinterpret_cast<Unk_SlOptions*>(reinterpret_cast<Unk_LgSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140cfd260()), DAT_143ab29d8);
}

// @0x141ad16b0
void UIServerListDialog::OnLoadComplete()
{
    m_nConnecting = 0;
    UIDialog::OnLoadComplete();
    int nChannel = atoi(reinterpret_cast<Unk_SlOptions*>(reinterpret_cast<Unk_LgSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140cfd260())->m_strChannel);
    int nMin = 1;
    m_nChannel = std::max<int>(nMin, nChannel);
    FUN_141ad1d20();
    if (((class Unk_SlLogin*)FUN_140d86260())->vfunc_1() == 1) {
        UIBannerAdvertisingDialog* pBanner = Unk_UgcGetDialog<UIBannerAdvertisingDialog>(0x4eca);
        if (pBanner != 0)
            pBanner->FUN_141031260();
    } else {
        if (DAT_143ab285c != 0) {
            CSceneStateMulti* pLobby = FUN_140f30370();
            if (pLobby != 0)
                pLobby->FUN_14174f470();
        } else {
            FUN_141ad2560(m_nChannel);
        }
        vfunc_8(0);
    }
    if (TSingleton<CGameRankingCli>::GetInstance() != 0)
        TSingleton<CGameRankingCli>::GetInstance()->Clear();
    ((class Unk_SlLogin*)FUN_140d86260())->vfunc_22(0x2bd, "LoginStep1");
}

// @0x141ad1810
int UIServerListDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UISceneLobbyServer*>(pSender) != 0) {
        CString strMethod = pMsg->FUN_1422b8d30();
        if ((const char*)(strMethod = "OnReset") != 0) {
            m_strServer = reinterpret_cast<Unk_SlOptions*>(reinterpret_cast<Unk_LgSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140cfd260())->m_strServer;
            m_nServerId = -1;
            int nChannel = atoi(reinterpret_cast<Unk_SlOptions*>(reinterpret_cast<Unk_LgSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140cfd260())->m_strChannel);
            int nMin = 1;
            m_nChannel = std::max<int>(nMin, nChannel);
            return 1;
        } else {
            if (FUN_1406c34c0() == 1)
                ((class Unk_SlLogin*)FUN_140d86260())->vfunc_72();
        }
    }
    return 0;
}

// @0x141ad19b0
int UIServerListDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d890(false))
    {
        m_30->Invoke("onEnterKey");
        return 1;
    }
    return 0;
}

// @0x141ad1a30
int UIServerListDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)(pArgs), nArgs, (void*)(this)) != 0)
        return 1;
    if (_stricmp("OnSceneLogin", szMethod) == 0) {
        m_nSceneId = 0x6200009;
        OnSceneLogin();
        return 1;
    } else if (_stricmp("OnSelectServer", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            FUN_141ad25a0(data.FUN_1422b8f40());
            return 1;
        }
    } else if (_stricmp("OnConnectServer", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            m_strServer = data.FUN_1422b8f40();
            int nChannel = data.FUN_1422b8a10();
            FUN_141ad2560(nChannel);
            return 1;
        }
    } else if (_stricmp("OnEndPopdown", szMethod) == 0) {
        OnEndPopdown();
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
    UIBannerAdvertisingDialog* pBanner = Unk_UgcGetDialog<UIBannerAdvertisingDialog>(0x4eca);
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
            for (POSITION pos = m_servers.GetHeadPosition(); pos != 0; m_servers.GetNext(pos))
                servers.push_back(m_servers.GetValueAt(pos));
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
                        m_nChannel = std::max<int>(nOne, std::min<int>(m_nChannel, nChannels));
                    }
                    CServerListTable::InfoPtr info = TSingleton<CServerListTable>::GetInstance()->GetServer(server->m_nId);
                    if (info == 0)
                        info = TSingleton<CServerListTable>::GetInstance()->GetFirstServer();
                    if (info.get() != 0) {
                        ASObj row(2);
                        row.FUN_1407cbb20("label", info->m_strName);
                        row.FUN_1407cba60("icon", info->m_strIcon);
                        row.FUN_1407cbb20("id", server->m_strName);
                        row.FUN_1407cb9c0("charCnt", server->m_nCharacterCount);
                        row.FUN_1407cb9c0("trafficPercent", server->m_nTrafficPercent);
                        array.PushValue(Scaleform::GFx::Value(row.FUN_1422bb870()));
                    } else {
                        FUN_140d73aa0(BlockFormat<int>(0x20e, 99999), 0, 0, DAT_143af62c0);
                    }
                }
            }
        }
    }
    int bShow = 0;
    int bEnable = 0;
    bShow = 1;
    bEnable = 1;
    m_nServerId = nSelectedId;
    static_cast<Unk_SlScript*>(m_30.operator->())->FUN_141ad3800("buildServerList", array, nSelectedIndex, m_nChannel, bShow, bEnable);
}

// @0x141ad2380
void UIServerListDialog::FUN_141ad2380()
{
    if (m_strServer.IsEmpty())
        return;
    if (ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> >::CPair* pPair = m_servers.Lookup(m_strServer)) {
        CMultiServer* pServer = pPair->m_value.get();
        if (!pServer->m_addresses.IsEmpty()) {
            int nIndex = rand() % (int)pServer->m_addresses.GetCount();
            CString strHost = pServer->m_addresses[nIndex];
            int nPort = pServer->m_ports[nIndex];
            FUN_140714f90()->ConnectTo(strHost, nPort, 1, 1, 0);
            m_nConnecting = 1;
            m_30->Invoke("requestConnect");
        }
    }
}

// @0x141ad2560
void UIServerListDialog::FUN_141ad2560(int nChannel)
{
    if (m_nConnecting != 0)
        return;
    FUN_141ad2ea0(nChannel);
    FUN_141ad2380();
}

// @0x141ad25a0
void UIServerListDialog::FUN_141ad25a0(CStringW strServer)
{
    if (ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> >::CPair* pPair = m_servers.Lookup(strServer)) {
        CMultiServer* pServer = pPair->m_value.get();
        if (pServer != 0) {
            if (m_strServer != strServer)
                m_nChannel = 1;
            m_strServer = strServer;
            int nOne = 1;
            m_nServerId = std::max<int>(pServer->m_nId, nOne);
            int bSelected = 1;
            bSelected = 0;
            int nSelectedIndex = -1;
            ASArray array(2);
            FUN_141ad3370(array, &nSelectedIndex, m_nChannel, MS2Ptr<CMultiServer>(pServer));
            static_cast<Unk_SlScript*>(m_30.operator->())->Invoke("buildChannelList", array, nSelectedIndex);
            if (bSelected != 0) {
                float fLimit = 1.0f;
                int bFound = 0;
                ATL::CRBMap<int, MS2Ptr<CMultiServerChannel> >::CPair* pChannel = pServer->m_channels.Lookup(m_nChannel);
                if (pChannel != 0) {
                    CMultiServerChannel* pCh = pChannel->m_value.get();
                    if (pCh != 0) {
                        if (pCh->HasLowerLoad(fLimit) != 0) {
                            m_nChannel = pCh->m_nId;
                            bFound = 1;
                        }
                    }
                }
                if (bFound == 0) {
                    for (POSITION pos = pServer->m_channels.GetHeadPosition(); pos != 0; pServer->m_channels.GetNext(pos)) {
                        CMultiServerChannel* pCh = pServer->m_channels.GetValueAt(pos).get();
                        if (pCh != 0) {
                            if (pCh->HasLowerLoad(fLimit) != 0) {
                                m_nChannel = pCh->m_nId;
                                bFound = 1;
                                break;
                            }
                        }
                    }
                }
                if (bFound == 0)
                    m_nChannel = 1;
            }
        }
    }
}

// @0x141ad28f0
void UIServerListDialog::FUN_141ad28f0(void* pPacket)
{
    int nScene = TSingleton<CStateService>::GetInstance()->FUN_1417e2610();
    if (nScene != 0x620000d)
        return;
    if (FUN_1406c34c0() != 0) {
        ((class Unk_SlLogin*)FUN_140d86260())->vfunc_20(m_nChannel, 2);
    } else {
        Unk_LoginRequest request;
        request.m_nType = 2;
        request.m_strId = DAT_143ab29d8;
        request.m_strPassword = DAT_143ab2a28;
        request.m_nLoginType = m_nChannel;
        FUN_14067c080(&request.m_machineId, *reinterpret_cast<const Unk_LoginMachineId*>(reinterpret_cast<CMachineIDManager*>(FUN_140aadf70())->GetID()));
        request.m_n2c = reinterpret_cast<CMachineIDManager*>(FUN_140aadf70())->GetValue();
        request.m_n30 = DAT_143ab2858;
        request.m_strRegion = FUN_140652030(FUN_1406516a0());
        if (reinterpret_cast<Unk_SlOptions*>(reinterpret_cast<Unk_LgSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140cfd260())->m_bLocaledName == 1)
            request.m_strId = FUN_1401d2b10(DAT_143ab29d8, FUN_1406521f0(FUN_1406516b0()));
        COutPacket packet(static_cast<int>(SendOp::ResponseLogin), 0);
        FUN_1401f9020((struct Unk_LoginA*)(&request), (class COutputStream*)(&packet));
        FUN_140710590(packet);
    }
}

// @0x141ad2b50
void UIServerListDialog::FUN_141ad2b50(CInPacket* pPacket)
{
    Unk_NetworkLoginResult reply;
    reinterpret_cast<Unk_SPDF*>(&reply)->FUN_1407a4740(&static_cast<CInputStream&>(*pPacket));
    int nResult = reply.result;
    if (nResult != 0)
    {
        FUN_141ad2ef0();
        return;
    }
    {
        TSingleton<CMainSystem>::GetInstance()->SyncServerTime(reply.a18);
        CMsTime::SetTimeZone(reply.zone, reply.zoneFlag);
        DAT_143ab2820 = reply.id;
        DAT_1439f4a7c = m_nChannel;
        DAT_143ab2834 = reply.a4c;
        DAT_143ab2838 = reply.a50;
        FUN_141b70390();
        TSingleton<CGameOption>::GetInstance()->LoadAccountOption();
        ((BlindManager*)FUN_1409c1730())->Load();
    }
}

// @0x141ad2c50
int UIServerListDialog::FUN_141ad2c50(__int64 nCharId, __int64 n3)
{
    int nChannel = m_nChannel;
    if (nChannel == 0)
        nChannel = FUN_14092f640();
    DAT_1439f4a7c = nChannel;
    static_cast<WorldService*>(((void*)WorldService::GetInstance()))->FUN_141bca1e0();
    Unk_SlEnterRequest request;
    request.m_nCharId = nCharId;
    request.m_nChannel = nChannel;
    COutPacket packet(static_cast<int>(SendOp::CharacterManagement), 0);
    packet.WriteUInt8(0);
    FUN_1401f9e60((struct Unk_LoginPing*)(&request), (class COutputStream*)(&packet));
    FUN_140710590(packet);
    Unk_SlOptions* pOptions = reinterpret_cast<Unk_SlOptions*>(reinterpret_cast<Unk_LgSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140cfd260());
    if (pOptions != 0) {
        if (pOptions->m_nCharId != nCharId)
            ((class NotifySystem*)(void*)FUN_140939a10())->Post(MS2Ptr<NotifyObject>(new NotifyChangeMyPC));
        FUN_141260c00((Unk_GsConnect*)pOptions, reinterpret_cast<const unsigned __int64&>(nCharId));
        FUN_141260a30((Unk_GsConnect*)pOptions, GetServer());
        if (nChannel != 0)
            FUN_141260ab0((Unk_GsConnect*)pOptions, nChannel);
    }
    ((class Unk_SlLogin*)FUN_140d86260())->vfunc_7();
    ((class Unk_SlLogin*)FUN_140d86260())->vfunc_22(0x2c6, "GameLoading");
    return 1;
}

// @0x141ad2ea0
void UIServerListDialog::FUN_141ad2ea0(int nChannel)
{
    m_nChannel = nChannel;
    if (nChannel != 0)
        FUN_141260ab0((Unk_GsConnect*)reinterpret_cast<Unk_SlOptions*>(reinterpret_cast<Unk_LgSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140cfd260()), nChannel);
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
    if (ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> >::CPair* pPair = m_servers.Lookup(GetServer()))
        FUN_141ad3370(array, pnSelected, nSelectedChannel, MS2Ptr<CMultiServer>(pPair->m_value));
}

// @0x141ad3030
void UIServerListDialog::FUN_141ad3030(const ATL::CAtlArray<int>& channels)
{
    if (ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> >::CPair* pPair = m_servers.Lookup(GetServer())) {
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
int UIServerListDialog::GetChannel()
{
    return m_nChannel;
}

// @0x141ad31d0
void UIServerListDialog::OnEndPopdown()
{
    switch (m_nSceneId)
    {
    case 0x620001b:
    {
        CSceneStateMulti* pMulti = FUN_140f30370();
        if (pMulti != 0)
            PostMessageA(((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef(), 0x4c8, 0, 0);
        break;
    }
    case 0x6200009:
        FUN_140714f90()->SendRequestQuitAndDisconnect();
        TSingleton<CStateService>::GetInstance()->FUN_1417e25a0(0x6200009);
        break;
    }
}

// @0x141ad3260
bool UIServerListDialog::FUN_141ad3260(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0) {
        COutPacket packet(static_cast<int>(SendOp::WaitingTicket), 0);
        packet.WriteUInt8(1);
        FUN_140710590(packet);
        UIServerListDialog* pDialog = ((class UIServerListDialog*)FUN_14136f520(0x4ef0));
        if (pDialog != 0)
            pDialog->FUN_141ad2ef0();
        DAT_143ab2858 = 0;
        DAT_143ab285c = 0;
        DAT_143ab284b = 0;
    }
    return true;
}

// @0x141ad3310
void UIServerListDialog::OnSceneLogin()
{
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4ef3);
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
            CStringW strChannel = GetStringCommon(0x579);
            for (POSITION pos = pChannels->GetHeadPosition(); pos != 0; pChannels->GetNext(pos)) {
                MS2Ptr<CMultiServerChannel> channel(pChannels->GetValueAt(pos));
                if (channel.get() != 0) {
                    int nId = channel->m_nId;
                    int nLimit = static_cast<WorldService*>(((void*)WorldService::GetInstance()))->FUN_141bd9870();
                    if (DAT_143ab2914 < 50 && nId != nSelectedChannel && nId > nLimit)
                        continue;
                    ASObj row(2);
                    row.FUN_1407cb9c0("id", nId);
                    CStringW strLabel = StringFormat((const wchar_t*)strPattern, strChannel, nId);
                    row.FUN_1407cbb20("label", strLabel);
                    row.FUN_1407cbb20("labelDropdown", strLabel);
                    if (nId == nSelectedChannel)
                        *pnSelected = nIndex;
                    array.PushValue(Scaleform::GFx::Value(row.FUN_1422bb870()));
                    nIndex++;
                }
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

// @0x141ad5ba0 ~CMultiServer and @0x141ad5c00 ~CMultiServerChannel are implicit: the exe dtors never reset the vptr.

// @0x141ad6460 is UIServerListDialog::vfunc_48 (inline in the header).

// @0x141ad6790
int CMultiServerChannel::HasLowerLoad(float fLimit) const
{
    if (m_n20 != 0)
    {
        float fLoad = (float)m_n1c / (float)m_n20;
        if (fLoad < fLimit)
        {
            fLimit = fLoad;
            return 1;
        }
    }
    return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc25c0-0x142cc2670 .text$yd
