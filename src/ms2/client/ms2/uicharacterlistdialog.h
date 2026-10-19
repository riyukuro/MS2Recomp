// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicharacterlistdialog.h (name assumed:
// the class name; the exe has no assert path for it).
//
// UICharacterListDialog ("CharacterListDialog"): the character picker shown after login. The server sends the list of
// characters (packet opcode 0xc, handled by OnPacketCharacterList), each a CCharacterInfo (a user proxy plus the
// equipped items); the dialog lists them in the movie, creates / deletes / renames characters and enters the world.
// Pending deletions (CDeleteCharacterInfo) tick down in vfunc_15. RTTI .?AVUICharacterListDialog@@, 0x240 bytes,
// vftables at +0 (UIDialog), +0x18 (IMessageListener) and +0x178 (UIUGCEventListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; members are invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include <memory>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/userproxy.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/uiugceventlistener.h"

class ASMovieClip;
class CInPacket;
class COutPacket;
class CMsgBoxData;

// The interval check of the delete-reply poll (0x140517b00 ctor, 0x140268870 "the interval elapsed").
class Unk_ClTimer
{
public:
    Unk_ClTimer();                                          // 0x140517b00
    int FUN_140268870(int nInterval);                       // true once the interval elapsed
private:
    unsigned m_nInterval;
    unsigned m_nLastTick;
};
MS2_CHECK_SIZE(Unk_ClTimer, 8);

class UICharacterListDialog : public UIDialog, public UIUGCEventListener
{
public:
    // One character of the list (0x390 bytes).
    class CCharacterInfo : public CPtred
    {
    public:
        CCharacterInfo();                                   // 0x1418e93f0
        virtual ~CCharacterInfo();                          //  0 0x1418e94b0
        void Read(CInPacket& packet);                       // 0x1418e9520 the proxy, the items and the delete time
        unsigned __int64 FUN_1418e9cb0();                   // the character id
        CStringW FUN_1418e9cd0();                           // the character name
        void FUN_1418e9d20(const CStringW& strName);        // set the character name
        Unk_UserProxy* FUN_1418e9d50();                     // the proxy
        const Unk_UserProxy* FUN_1418e9d70() const;
        CString FUN_1418e9d90();                            // m_text368
        void FUN_1418e9de0(CString str);                    // set m_text368
        void FUN_1418e9e30(CString str);                    // set m_text370
        CString FUN_1418e9e80();                            // m_text370
        void FUN_1418e9ed0(unsigned nSeconds);                   // seconds until the deletion, started now
        int FUN_1418e9f30();                                // seconds left
        int FUN_1418e9fa0(__int64 nDeleteTime);             // set the delete time and derive the seconds
        __int64 FUN_1418ea020();                            // the delete time
        void FUN_1418ea040(int nOrder);
        int FUN_1418ea060();
        static int FUN_1418ea080();                         // next order number
        static void FUN_1418ea0a0();                        // reset the order numbers

        Unk_UserProxy m_state;                              // +0x18
        CString m_text368;                                  // +0x368
        CString m_text370;                                  // +0x370
        unsigned m_nSeconds;                                // +0x378
        unsigned m_nStarted;                                // +0x37c
        __int64 m_nDeleteTime;                              // +0x380
        int m_nOrder;                                       // +0x388
    };
    typedef MS2Ptr<CCharacterInfo> CharPtr;

    // A character waiting for its deletion, with the movie clip showing it.
    class CDeleteCharacterInfo : public CPtred
    {
    public:
        CDeleteCharacterInfo(CharPtr spCharacter, MS2Ptr<ASMovieClip> spMovie);     // 0x1418ea0c0
        virtual ~CDeleteCharacterInfo();                    //  0 0x1418ea150

        CharPtr m_spCharacter;                              // +0x18
        MS2Ptr<ASMovieClip> m_spMovie;                      // +0x28
    };
    typedef MS2Ptr<CDeleteCharacterInfo> DeletePtr;

    // The answer of the delete request (result, three texts), handed over by a packet.
    struct DeleteReply
    {
        DeleteReply(unsigned char nResult, const CStringW& str1, const CStringW& str2, const CStringW& str3);   // 0x1418ea1e0
        unsigned char m_nResult;                            // +0x00
        CStringW m_str8;                                    // +0x08
        CStringW m_str10;                                   // +0x10
        CStringW m_str18;                                   // +0x18
    };
    static std::shared_ptr<DeleteReply> s_reply;            // 0x143af1a68

    UICharacterListDialog();                                // 0x1418ea2b0
    virtual ~UICharacterListDialog();                       //  0 0x1418ea5d0
    virtual CString vfunc_1();                              //  1 0x1418ea740 "CharacterListDialog"
    virtual int vfunc_4();                                  //  4 0x1418ed190
    virtual int vfunc_5();                                  //  5 0x1418ed2d0
    virtual int vfunc_13();                                 // 13 0x1418eb930
    virtual void vfunc_15();                                // 15 0x1418ead80 tick the pending deletions
    virtual void OnLoadComplete();                          // 22 0x1418eb1c0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1418eba00
    virtual int vfunc_65();                                 // 65 0x1418ea790
    virtual void vfunc_67();                                // 67 0x1418ed080
    virtual void vfunc_72();                                // 72 0x1418eb0a0 the delete reply poll
    virtual void vfunc_79(void* p);                         // 79 0x1418ea860
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x1418eb540
    virtual void vfunc_ugc_1(void* p, CString str);         // UGC 1 0x1418ed310

    void FUN_1418ed880(CInPacket& packet);                  // 0xc the character list

    int m_180;                                              // +0x180
    CharPtr m_188;                                          // +0x188 the selected character
    CStringW m_198;                                         // +0x198
    __int64 m_1a0;                                          // +0x1a0
    std::vector<CharPtr> m_1a8;                             // +0x1a8 the characters
    __int64 m_1c0;                                          // +0x1c0
    __int64 m_1c8;                                          // +0x1c8
    int m_1d0;                                              // +0x1d0
    int m_1d4;                                              // +0x1d4
    int m_1d8;                                              // +0x1d8
    int m_1dc;                                              // +0x1dc
    int m_1e0;                                              // +0x1e0
    int m_1e4;                                              // +0x1e4
    unsigned char m_1e8;                                    // +0x1e8
    ATL::CAtlList<DeletePtr> m_1f0;                         // +0x1f0 the pending deletions
    unsigned char m_220;                                    // +0x220
    unsigned char m_221;                                    // +0x221
    int m_224;                                              // +0x224
    MS2Ptr<CMsgBoxData> m_228;                              // +0x228
    Unk_ClTimer m_238;                                      // +0x238 delete reply poll
};
