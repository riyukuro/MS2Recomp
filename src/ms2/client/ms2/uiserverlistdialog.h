// uiserverlistdialog.h - UIServerListDialog (RTTI .?AVUIServerListDialog@@, 0x1c0 bytes, UIDialog, UI id 0x4ef0, swf
// "ServerListDialog"): the server / channel pick list of the login scene. It receives the server list packet
// (opcode 11), keeps the servers (CMultiServer, with their channels CMultiServerChannel) by name, hands the list to the
// movie ("buildServerList" / "buildChannelList"), and connects to a random address of the chosen server
// ("requestConnect"). Owning unit: ?\uiserverlistdialog.cpp. Header name assumed from the unit path; member names are
// invented from use unless the exe has a string for them.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class ASArray;
class CInPacket;
class CMsgBoxData;
class UISceneLobbyServer;

// RTTI .?AVCMultiServerChannel@@ (0x28 bytes): one channel of a server; the load fields are filled elsewhere.
class CMultiServerChannel : public CPtred
{
public:
    CMultiServerChannel();                                      // 0x141ad5800
    virtual ~CMultiServerChannel();                             //  0 0x141ad5c00 (??_G 0x141ad5f30)
    int HasLowerLoad(float fLimit) const;                       // 0x141ad6790 (m_20 != 0 && fLimit > m_1c / m_20)

    int m_nId;                                                  // +0x18 channel id (packet reader 0x141ad1150)
    int m_n1c;                                                  // +0x1c
    int m_n20;                                                  // +0x20
};
MS2_CHECK_SIZE(CMultiServerChannel, 0x28);

// RTTI .?AVCMultiServer@@ (0xa8 bytes): one login server with its addresses and channels.
class CMultiServer : public CPtred
{
public:
    CMultiServer();                                             // 0x141ad5740
    virtual ~CMultiServer();                                    //  0 0x141ad5ba0 (??_G 0x141ad5ef0)

    int m_nId;                                                  // +0x18
    CStringW m_strName;                                         // +0x20
    ATL::CAtlArray<CString> m_addresses;                        // +0x28 (Add 0x140165270)
    ATL::CAtlArray<unsigned short> m_ports;                     // +0x48 (Add 0x140185440)
    int m_nCharacterCount;                                      // +0x68 "charCnt"
    int m_n6c;                                                  // +0x6c
    int m_n70;                                                  // +0x70
    int m_nTrafficPercent;                                      // +0x74 "trafficPercent"
    ATL::CRBMap<int, MS2Ptr<CMultiServerChannel> > m_channels;  // +0x78 by channel id (SetAt 0x141ad7be0)
};
MS2_CHECK_SIZE(CMultiServer, 0xa8);
MS2_CHECK_OFFSET(CMultiServer, m_channels, 0x78);

class UIServerListDialog : public UIDialog
{
public:
    UIServerListDialog();                                       // 0x141ad0c80
    virtual ~UIServerListDialog();                              //  0 0x141ad0e30 (??_G 0x141ad6030)
    virtual CString vfunc_1();                                  //  1 0x141ad0f30 "ServerListDialog"
    virtual int vfunc_13();                                     // 13 0x141ad19b0 the enter key
    virtual void OnLoadComplete();                              // 22 0x141ad16b0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141ad1a30
    virtual int vfunc_48() { return 0x4ef0; }                   // 48 0x141ad6460
    static eUIClassID GetUIClassID() { return (eUIClassID)0x4ef0; }   // 0x141a4b240 (COMDAT in uiminimapentity.cpp)
    virtual void vfunc_67();                                    // 67 0x141ad1cc0
    virtual void vfunc_79(void* pPacket);                       // 79 0x141ad1080 (CInPacket*)
    virtual void ReceiveServerList(CInPacket& packet);          // 84 0x141ad1150 (new virtual; packet 11 handler)
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141ad1810

    size_t FUN_141ad0f80();                                     // channel count of the chosen server
    int FUN_141ad1010();                                        // m_nServerId
    CStringW FUN_141ad1030();                                   // m_strServer
    void FUN_141ad1d20();                                       // hand the server list to the movie
    void FUN_141ad2380();                                       // connect to a random address of the chosen server
    void FUN_141ad2560(int nChannel);                           // pick the channel and connect
    void FUN_141ad25a0(CStringW strServer);                     // the movie selected a server
    void FUN_141ad28f0(void* pPacket);                        // login result handler (opcode 9)
    void FUN_141ad2b50(CInPacket* pPacket);                       // login result handler (opcode 10)
    int FUN_141ad2c50(__int64 nCharId, __int64 n3);                // enter the game with the chosen character
    void FUN_141ad2ea0(int nChannel);                           // m_nChannel = n, stored in the settings
    void FUN_141ad2ef0();                                       // the connect failed: "failConnect"
    void FUN_141ad2f60(ASArray& array, int* pnSelected, int nSelectedChannel);   // channel list of the chosen server
    void FUN_141ad3030(const ATL::CAtlArray<int>& channels);    // replace the channel set of the chosen server
    int FUN_141ad31b0();                                        // m_nChannel
    void FUN_141ad31d0();                                       // the pop-down ended
    bool FUN_141ad3260(int nButton, const CMsgBoxData& data);   // message box answer: cancel the login (packet 0x6d)
    void FUN_141ad3310();                                       // "popdown"
    void FUN_141ad3370(ASArray& array, int* pnSelected, int nSelectedChannel, MS2Ptr<CMultiServer> server);   // channels

private:
    MS2_LAYOUT_FRIEND;
    CStringW m_strServer;                                       // +0x178 the chosen server's name
    int m_nServerId;                                            // +0x180
    int m_nChannel;                                             // +0x184 the chosen channel id
    int m_nConnecting;                                          // +0x188
    int m_nSceneId;                                             // +0x18c scene that opened the dialog (0x6200009 / 0x620001b)
    ATL::CRBMap<CStringW, MS2Ptr<CMultiServer> > m_servers;     // +0x190 by server name
};
MS2_CHECK_SIZE(UIServerListDialog, 0x1c0);
MS2_CHECK_OFFSET(UIServerListDialog, m_strServer, 0x178);
MS2_CHECK_OFFSET(UIServerListDialog, m_nChannel, 0x184);
MS2_CHECK_OFFSET(UIServerListDialog, m_servers, 0x190);
