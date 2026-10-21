// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MessengerData / GroupMessengerData: see messengerdata.h.
// MS2-UNIT: ?\messengerdata.cpp
// MS2-RANGE: 0x141480c70-0x141484920 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
//
// File name assumed (the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\messengerdata.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "messengerdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (names describe uses) ----

// An XML element (the messenger settings file): children by name, int / string attributes.
class Unk_MdXml
{
public:
    Unk_MdXml* FUN_140872ec0(const char* szName, bool bCreate);              // child element (created on request)
    int FUN_1408731e0(const char* szName, int* pValue);                     // read an int attribute
    void FUN_140873ca0(const char* szName, int nValue);                     // write an int attribute
    int FUN_140873420(const char* szName, CStringW* pValue);                // read a string attribute
    void FUN_1408740a0(const char* szName, CStringW* pValue);               // write a string attribute
};

// The client feature switches: 0x56 = club chat, 0x93 = dungeon help.
class Unk_MdFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_MdFeatures* FUN_140166410();

// The chat window's name service (+0x48 of the state).
class Unk_MdChat
{
public:
    int FUN_141a23d70(const CStringW& strName);                             // is a valid chat name
    CStringW FUN_141a258a0();                                               // the default chat name
};

// The state behind the messenger: the current chat name and the names tried in turn.
struct Unk_MdNames
{
    Unk_MdNames();                                                          // 0x141482990
    CStringW m_strCurrent;                                                  // +0x00
    ATL::CAtlList<CStringW> m_names;                                        // +0x08
    CStringW FUN_1414829e0();                                               // 0x1414829e0 the current name (picks one when none)
    CStringW FUN_141482a50();                                               // 0x141482a50 the first valid name of the list
    void FUN_141482b70();                                                   // 0x141482b70 forget everything
    void FUN_141482bb0();                                                   // 0x141482bb0 take the next name
    void FUN_141482c80(CStringW strName);                                   // 0x141482c80 make a name current
    void FUN_141482d30(CStringW strName);                                   // 0x141482d30 drop a name
};
struct Unk_MdState
{
    Unk_MdState();                                                          // 0x141482df0
    void FUN_141482e50();                                                   // 0x141482e50
    Unk_MdNames m_names;                                                    // +0x00
    int m_n38;                                                              // +0x38
    void* m_p40;                                                            // +0x40
    Unk_MdChat* m_pChat;                                                    // +0x48
    void* m_p50;                                                            // +0x50
};
MS2_CHECK_SIZE(Unk_MdState, 0x58);

// The 1439f7cbc "global" switch (all tabs share one screen look) and the shared look.
static int s_nGlobal = 1;                                                   // 0x1439f7cbc
static MessengerData::ScreenSetting s_screenGlobal;                         // 0x143adda48

// A player of the world: the name and the level-ish ushort sit in vftable slots 77 / 78 (MS2: slots proven from the callers).
class Unk_MdPlayer
{
public:
    virtual ~Unk_MdPlayer();                                                // vfunc_0
    virtual void vfunc_1();
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual CStringW vfunc_77();
    virtual unsigned short vfunc_78();
    CString FUN_1416612e0();                                                // the portrait image name
    __int64 FUN_141656a80();                                                // the portrait owner key
    int FUN_141654730();                                                    // the class (job) id
};
class Unk_MdPlayers { public: Unk_MdPlayer* FUN_141bd1530(__int64 nId); };
Unk_MdPlayers* FUN_1403ed2d0();

// Source records of the chat entries (partial layouts: only what the entry builders read).
class Unk_MdName { public: CString FUN_1408f1a60(); CStringW FUN_1408f19e0(); };   // a name box
class Unk_MdSrcA { public: int FUN_1401cc680(); __int64 FUN_1401cc230(); const CString& FUN_1401cc530(); CStringW FUN_1401cc1c0();
                   int FUN_1401cc210(); int FUN_1401cc290(); };
class Unk_MdSrcB
{
public:
    bool FUN_141637c20();
    unsigned char m_pad_00[0x28];
    Unk_MdName m_name;                                                      // +0x28
    __int64 m_nId;                                                          // +0x30
    unsigned char m_pad_38[0x24];
    unsigned short m_time[2];                                               // +0x5c
    unsigned char m_pad_60[8];
    int m_nJob;                                                             // +0x68
};
class Unk_MdNameC { public: CString FUN_1404ca980(); CStringW FUN_1404ca890(); };   // the other name box
class Unk_MdSrcC
{
public:
    unsigned char m_pad_00[0x20];
    Unk_MdNameC m_name;                                                     // +0x20
    __int64 m_nId;                                                          // +0x28
    unsigned char m_pad_30[4];
    int m_nClass;                                                           // +0x34
    unsigned char m_pad_38[4];
    unsigned short m_time[2];                                               // +0x3c
    unsigned char m_pad_40[0x118];
    int m_nState;                                                           // +0x158
};
class Unk_MdSrcD
{
public:
    int FUN_14137b160();
    unsigned char m_pad_00[0x18];
    Unk_MdName m_name;                                                      // +0x18
    __int64 m_nId;                                                          // +0x20
    unsigned char m_pad_28[0x24];
    unsigned short m_time[2];                                               // +0x4c
    unsigned char m_pad_50[8];
    int m_nJob;                                                             // +0x58
};
class Unk_MdItemTexts { public: CStringW FUN_141811980(int n, int nId); };  // text by kind and id
Unk_MdItemTexts* FUN_1401a9d70();
class Unk_MdClassTable { public: };
Unk_MdClassTable* FUN_1401d7a50();
int FUN_140644bb0(Unk_MdClassTable* p, int nClass);                         // class id -> text id
CString FUN_141028be0(__int64 nId, const CString& strName, int bNoDownload, CString strUrl);   // the local file of an image
struct Unk_MdTime { unsigned short m_nTime; unsigned short m_pad; };
CStringW FUN_140c348b0(int chSep, const void* pTime, const CStringW& strText);   // "<time> <text>"
CStringW FUN_140a228f0(int chSep, const void* pTime, const CStringW& strText);   // same, for the other source

struct Unk_MdEntry
{
    Unk_MdEntry();                                                          // 0x141482fb0
    Unk_MdEntry(__int64 nId);                                               // 0x141483040
    Unk_MdEntry(Unk_MdSrcA& src);                                           // 0x141483300
    Unk_MdEntry(Unk_MdSrcB& src);                                           // 0x141483580
    Unk_MdEntry(Unk_MdSrcC& src);                                           // 0x141483830
    Unk_MdEntry(Unk_MdSrcD& src);                                           // 0x141483af0
    unsigned FUN_141483d80();                                               // 0x141483d80 the kind
    __int64 FUN_141483da0();                                                // 0x141483da0 the sender id
    CStringW FUN_141483dc0();                                               // 0x141483dc0 the image
    CStringW FUN_141483e10();                                               // 0x141483e10 the name
    CStringW FUN_141483e60();                                               // 0x141483e60 the info line
    unsigned m_nKind;                                                       // +0x00
    __int64 m_nId;                                                          // +0x08
    CStringW m_strImage;                                                    // +0x10
    CStringW m_strName;                                                     // +0x18
    CStringW m_strInfo;                                                     // +0x20
};
MS2_CHECK_SIZE(Unk_MdEntry, 0x28);

// The group chat registry: a room by kind, a member by name (counted handles 0x141381160 / 0x14137c280).
class Unk_MdMember { public: unsigned char m_pad[0x18]; Unk_MdName m_name; __int64 m_nOwner; };
class Unk_MdMemberPtr
{
public:
    ~Unk_MdMemberPtr();                                                     // 0x14137c280
    bool FUN_14137c360(int n);                                              // is null
    Unk_MdMember* FUN_14137c3b0();                                          // operator->
    void* m_p[2];                                                           // 16-byte counted handle (exe stack slot)
};
class Unk_MdRoom { public: Unk_MdMemberPtr FUN_14137ba10(CStringW strName); };
class Unk_MdRoomPtr
{
public:
    ~Unk_MdRoomPtr();                                                       // 0x141381160
    bool FUN_141381230(int n);                                              // is null
    Unk_MdRoom* FUN_141381280();                                            // operator->
    void* m_p[2];                                                           // 16-byte counted handle (exe stack slot)
};
class Unk_MdRooms { public: Unk_MdRoomPtr FUN_14137e630(int nKind); };
extern Unk_MdRooms* g_pRooms;                                               // 0x143ad8ba8
Unk_MdRooms* FUN_141484720();

// @0x141480c70
MessengerData::NoticeSetting::NoticeSetting()
{
    m_nAll = 1; m_nUser = 1; m_nTrade = 1; m_nCommunity = 1; m_nFriend = 1;
    m_nGuild = 1; m_nClub = 1; m_nParty = 1; m_nMentoring = 1; m_nEtc = 1;
}

// @0x141480d00
int MessengerData::NoticeSetting::FUN_141480d00(Unk_MdXml* pXml)
{
    Unk_MdXml* pNotice = pXml->FUN_140872ec0("Notice", true);
    if (pNotice != 0)
    {
    pNotice->FUN_1408731e0("all", &m_nAll);
    pNotice->FUN_1408731e0("user", &m_nUser);
    pNotice->FUN_1408731e0("trade", &m_nTrade);
    pNotice->FUN_1408731e0("community", &m_nCommunity);
    pNotice->FUN_1408731e0("friend", &m_nFriend);
    pNotice->FUN_1408731e0("guild", &m_nGuild);
    pNotice->FUN_1408731e0("club", &m_nClub);
    pNotice->FUN_1408731e0("party", &m_nParty);
    pNotice->FUN_1408731e0("mentoring", &m_nMentoring);
    pNotice->FUN_1408731e0("etc", &m_nEtc);
    int nAll;
    if (m_nUser == 0 && m_nTrade == 0 && m_nCommunity == 0 && m_nFriend == 0 && m_nGuild == 0 && m_nClub == 0 && m_nParty == 0 && m_nMentoring == 0 && m_nEtc == 0)
        nAll = 0;
    else
        nAll = 1;
    m_nAll = nAll;
        return 1;
    }
    return 0;
}

// @0x141480ef0
int MessengerData::NoticeSetting::FUN_141480ef0(Unk_MdXml* pXml)
{
    Unk_MdXml* pNotice = pXml->FUN_140872ec0("Notice", true);
    if (pNotice)
    {
        pNotice->FUN_140873ca0("all", m_nAll);
        pNotice->FUN_140873ca0("user", m_nUser);
        pNotice->FUN_140873ca0("trade", m_nTrade);
        pNotice->FUN_140873ca0("community", m_nCommunity);
        pNotice->FUN_140873ca0("friend", m_nFriend);
        pNotice->FUN_140873ca0("guild", m_nGuild);
        pNotice->FUN_140873ca0("club", m_nClub);
        pNotice->FUN_140873ca0("party", m_nParty);
        pNotice->FUN_140873ca0("mentoring", m_nMentoring);
        pNotice->FUN_140873ca0("etc", m_nEtc);
        return 1;
    }
    return 0;
}

// @0x141481040
int MessengerData::NoticeSetting::FUN_141481040(int nType)
{
    if (nType >= 10 && nType <= 0x12)
    {
        if (m_nAll == 0)
            return 1;
        if (nType == 10)
            return m_nUser == 0;
        if (nType == 0xb)
            return m_nCommunity == 0;
        if (nType == 0xc)
            return m_nFriend == 0;
        if (nType == 0xd)
            return m_nGuild == 0;
        if (nType == 0xe)
            return m_nParty == 0;
        if (nType == 0xf)
            return m_nClub == 0;
        if (nType == 0x10)
            return m_nMentoring == 0;
        if (nType == 0x11)
            return m_nEtc == 0;
        if (nType == 0x12)
            return m_nTrade == 0;
    }
    return 0;
}

// @0x141481210
MessengerData::SystemSetting::SystemSetting()
{
    m_nAll = 1; m_nEvent = 1; m_nNotice = 1;
}

// @0x141481250
int MessengerData::SystemSetting::FUN_141481250(Unk_MdXml* pXml)
{
    Unk_MdXml* pSystem = pXml->FUN_140872ec0("System", true);
    if (pSystem != 0)
    {
    pSystem->FUN_1408731e0("all", &m_nAll);
    pSystem->FUN_1408731e0("event", &m_nEvent);
    pSystem->FUN_1408731e0("notice", &m_nNotice);
    int nAll;
    if (m_nEvent == 0 && m_nNotice == 0)
        nAll = 0;
    else
        nAll = 1;
    m_nAll = nAll;
        return 1;
    }
    return 0;
}

// @0x141481320
int MessengerData::SystemSetting::FUN_141481320(Unk_MdXml* pXml)
{
    Unk_MdXml* pSystem = pXml->FUN_140872ec0("System", true);
    if (pSystem)
    {
        pSystem->FUN_140873ca0("all", m_nAll);
        pSystem->FUN_140873ca0("event", m_nEvent);
        pSystem->FUN_140873ca0("notice", m_nNotice);
        return 1;
    }
    return 0;
}

// @0x1414813b0
int MessengerData::SystemSetting::FUN_1414813b0(int nType)
{
    if (nType == 0x13 || nType == 0x14)
    {
        if (m_nAll == 0)
            return 1;
        if (nType == 0x13)
            return m_nEvent == 0;
        if (nType == 0x14)
            return m_nNotice == 0;
    }
    return 0;
}

// @0x141481440
MessengerData::ScreenSetting::ScreenSetting()
{
    m_nFontSize = 0x11; m_nBackgroundAlpha = 0x32; m_nShowDamage = 1;
}

// @0x141481480
int MessengerData::ScreenSetting::FUN_141481480(Unk_MdXml* pXml)
{
    Unk_MdXml* pScreen = pXml->FUN_140872ec0("Screen", true);
    if (pScreen)
    {
        int nFontSize = 0;
        int nAlpha = 0;
        pScreen->FUN_1408731e0("fontSize", &nFontSize);
        pScreen->FUN_1408731e0("backgroundAlpha", &nAlpha);
        pScreen->FUN_1408731e0("showDamage", &m_nShowDamage);
        m_nFontSize = nFontSize;
        m_nBackgroundAlpha = nAlpha;
        return 1;
    }
    return 0;
}

// @0x141481540
int MessengerData::ScreenSetting::FUN_141481540(Unk_MdXml* pXml)
{
    Unk_MdXml* pScreen = pXml->FUN_140872ec0("Screen", true);
    if (pScreen)
    {
        pScreen->FUN_140873ca0("fontSize", m_nFontSize);
        pScreen->FUN_140873ca0("backgroundAlpha", m_nBackgroundAlpha);
        pScreen->FUN_140873ca0("showDamage", m_nShowDamage);
        return 1;
    }
    return 0;
}

// @0x1414815d0
MessengerData::RequireSetting::RequireSetting()
{
    m_nAll = 1; m_nMeso = 1; m_nMerat = 1; m_nToken = 1; m_nItem = 1; m_nExperience = 1; m_nAuth = 1;
}

// @0x141481640
int MessengerData::RequireSetting::FUN_141481640(Unk_MdXml* pXml)
{
    Unk_MdXml* pRequire = pXml->FUN_140872ec0("Require", true);
    if (pRequire != 0)
    {
    pRequire->FUN_1408731e0("all", &m_nAll);
    pRequire->FUN_1408731e0("meso", &m_nMeso);
    pRequire->FUN_1408731e0("merat", &m_nMerat);
    pRequire->FUN_1408731e0("token", &m_nToken);
    pRequire->FUN_1408731e0("item", &m_nItem);
    pRequire->FUN_1408731e0("experience", &m_nExperience);
    pRequire->FUN_1408731e0("auth", &m_nAuth);
    int nAll;
    if (m_nMeso == 0 && m_nMerat == 0 && m_nItem == 0 && m_nExperience == 0 && m_nToken == 0 && m_nAuth == 0)
        nAll = 0;
    else
        nAll = 1;
    m_nAll = nAll;
        return 1;
    }
    return 0;
}

// @0x1414817b0
int MessengerData::RequireSetting::FUN_1414817b0(Unk_MdXml* pXml)
{
    Unk_MdXml* pRequire = pXml->FUN_140872ec0("Require", true);
    if (pRequire)
    {
        pRequire->FUN_140873ca0("all", m_nAll);
        pRequire->FUN_140873ca0("meso", m_nMeso);
        pRequire->FUN_140873ca0("merat", m_nMerat);
        pRequire->FUN_140873ca0("token", m_nToken);
        pRequire->FUN_140873ca0("item", m_nItem);
        pRequire->FUN_140873ca0("experience", m_nExperience);
        pRequire->FUN_140873ca0("auth", m_nAuth);
        return 1;
    }
    return 0;
}

// @0x1414818b0
int MessengerData::RequireSetting::FUN_1414818b0(int nType)
{
    if (nType == 5 || nType == 6 || nType == 8 || nType == 9 || nType == 7 || nType == 0x1c)
    {
        if (m_nAll == 0)
            return 1;
        if (nType == 5)
            return m_nMeso == 0;
        if (nType == 6)
            return m_nMerat == 0;
        if (nType == 7)
            return m_nToken == 0;
        if (nType == 8)
            return m_nExperience == 0;
        if (nType == 9)
            return m_nItem == 0;
        if (nType == 0x1c)
            return m_nAuth == 0;
    }
    return 0;
}

// @0x141481a10
MessengerData::SubjectSetting::SubjectSetting()
{
    m_nAll = 1; m_nSuper = 1; m_nWorld = 1; m_nChannel = 1; m_nSocial = 1; m_nParty = 1;
    m_nGuild = 1; m_nWhisper = 1; m_nClub = 1; m_nPartyInvite = 1; m_nDungeonHelp = 1;
}

// @0x141481ab0
int MessengerData::SubjectSetting::FUN_141481ab0(Unk_MdXml* pXml)
{
    Unk_MdXml* pSubject = pXml->FUN_140872ec0("Subject", true);
    if (pSubject != 0)
    {
    pSubject->FUN_1408731e0("all", &m_nAll);
    pSubject->FUN_1408731e0("super", &m_nSuper);
    pSubject->FUN_1408731e0("world", &m_nWorld);
    pSubject->FUN_1408731e0("channel", &m_nChannel);
    pSubject->FUN_1408731e0("social", &m_nSocial);
    pSubject->FUN_1408731e0("party", &m_nParty);
    pSubject->FUN_1408731e0("guild", &m_nGuild);
    pSubject->FUN_1408731e0("whisper", &m_nWhisper);
    if (FUN_140166410()->FUN_14036d570(0x56) == 1)
        pSubject->FUN_1408731e0("club", &m_nClub);
    pSubject->FUN_1408731e0("partyInvite", &m_nPartyInvite);
    if (FUN_140166410()->FUN_14036d570(0x93) != 0)
        pSubject->FUN_1408731e0("dungeonHelp", &m_nDungeonHelp);
    int nAll;
    if (m_nSuper == 0 && m_nWorld == 0 && m_nChannel == 0 && m_nSocial == 0 && m_nParty == 0 && m_nGuild == 0 && m_nWhisper == 0 && m_nClub == 0 && m_nPartyInvite == 0 && m_nDungeonHelp == 0)
        nAll = 0;
    else
        nAll = 1;
    m_nAll = nAll;
        return 1;
    }
    return 0;
}

// @0x141481cf0
int MessengerData::SubjectSetting::FUN_141481cf0(Unk_MdXml* pXml)
{
    Unk_MdXml* pSubject = pXml->FUN_140872ec0("Subject", true);
    if (pSubject != 0)
    {
    pSubject->FUN_140873ca0("all", m_nAll);
    pSubject->FUN_140873ca0("super", m_nSuper);
    pSubject->FUN_140873ca0("world", m_nWorld);
    pSubject->FUN_140873ca0("channel", m_nChannel);
    pSubject->FUN_140873ca0("social", m_nSocial);
    pSubject->FUN_140873ca0("party", m_nParty);
    pSubject->FUN_140873ca0("guild", m_nGuild);
    pSubject->FUN_140873ca0("whisper", m_nWhisper);
    if (FUN_140166410()->FUN_14036d570(0x56) == 1)
        pSubject->FUN_140873ca0("club", m_nClub);
    pSubject->FUN_140873ca0("partyInvite", m_nPartyInvite);
    if (FUN_140166410()->FUN_14036d570(0x93) == 1)
        pSubject->FUN_140873ca0("dungeonHelp", m_nDungeonHelp);
        return 1;
    }
    return 0;
}

// @0x141481e90
int MessengerData::SubjectSetting::FUN_141481e90(int nType)
{
    if (nType == 0x1d)
        return 0;
    if (nType == 0x17 || nType == 0x15 || nType == 0x16 || nType == 1 || nType == 2 || nType == 3 || nType == 0x18 || nType == 0x1a || nType == 0x19 || nType == 0x1b || nType == 4)
    {
        if (m_nAll == 0)
            return 1;
        if (nType == 0x17)
            return m_nSuper == 0;
        if (nType == 0x15)
            return m_nWorld == 0;
        if (nType == 0x16)
            return m_nChannel == 0;
        if (nType == 1)
            return m_nSocial == 0;
        if (nType == 2)
            return m_nParty == 0;
        if (nType == 3 || nType == 0x18)
            return m_nGuild == 0;
        if (nType == 4)
            return m_nWhisper == 0;
        if (nType == 0x1a)
            return m_nClub == 0;
        if (nType == 0x19)
            return m_nPartyInvite == 0;
        if (nType == 0x1b)
            return m_nDungeonHelp == 0;
    }
    return 0;
}

// @0x1414820e0
MessengerData::PanelSetting::PanelSetting()
{
}

// @0x141482150
int MessengerData::PanelSetting::FUN_141482150()
{
    return s_nGlobal;
}

// @0x141482170
MessengerData::NoticeSetting* MessengerData::PanelSetting::FUN_141482170()
{
    return &m_notice;
}

// @0x141482190
MessengerData::SystemSetting* MessengerData::PanelSetting::FUN_141482190()
{
    return &m_system;
}

// @0x1414821b0
MessengerData::ScreenSetting* MessengerData::PanelSetting::FUN_1414821b0()
{
    if (s_nGlobal)
        return &s_screenGlobal;
    return &m_screen;
}

// @0x1414821e0
MessengerData::RequireSetting* MessengerData::PanelSetting::FUN_1414821e0()
{
    return &m_require;
}

// @0x141482200
MessengerData::SubjectSetting* MessengerData::PanelSetting::FUN_141482200()
{
    return &m_subject;
}

#ifndef MS2_HOOK_DLL
// @0x141482220
int MessengerData::PanelSetting::FUN_141482220(Unk_MdXml* pXml)
{
    Unk_MdXml* pPanel = pXml->FUN_140872ec0("PanelSetting", true);
    if (pPanel != 0)
    {
        pPanel->FUN_1408731e0("global", &s_nGlobal);
        if (m_notice.FUN_141480d00(pPanel) == 0)
            return 0;
        if (m_system.FUN_141481250(pPanel) == 0)
            return 0;
        if (m_screen.FUN_141481480(pPanel) == 0)
            return 0;
        if (m_require.FUN_141481640(pPanel) == 0)
            return 0;
        if (m_subject.FUN_141481ab0(pPanel) == 0)
            return 0;
        if (s_nGlobal != 0 && s_screenGlobal.FUN_141481480(pPanel) == 0)
            return 0;
        return 1;
    }
    return 0;
}
#endif

#ifndef MS2_HOOK_DLL
// @0x141482340
int MessengerData::PanelSetting::FUN_141482340(Unk_MdXml* pXml)
{
    Unk_MdXml* pPanel = pXml->FUN_140872ec0("PanelSetting", true);
    if (pPanel != 0)
    {
        pPanel->FUN_140873ca0("global", s_nGlobal);
        if (m_notice.FUN_141480ef0(pPanel) == 0)
            return 0;
        if (m_system.FUN_141481320(pPanel) == 0)
            return 0;
        if (m_screen.FUN_141481540(pPanel) == 0)
            return 0;
        if (m_require.FUN_1414817b0(pPanel) == 0)
            return 0;
        if (m_subject.FUN_141481cf0(pPanel) == 0)
            return 0;
        if (s_nGlobal != 0 && s_screenGlobal.FUN_141481540(pPanel) == 0)
            return 0;
        return 1;
    }
    return 0;
}
#endif

// @0x141482460
int MessengerData::PanelSetting::FUN_141482460(int nType)
{
    if (m_notice.FUN_141481040(nType) != 0)
        return 1;
    if (m_system.FUN_1414813b0(nType) != 0)
        return 1;
    if (m_require.FUN_1414818b0(nType) != 0)
        return 1;
    if (m_subject.FUN_141481e90(nType) != 0)
        return 1;
    return 0;
}

// @0x141482500
MessengerData::TalkLog::TalkLog()
    : m_strMsg("")
{
    m_nKind = 0;
}

// @0x141482570
MessengerData::TalkLog::TalkLog(CStringW strMsg, int nKind)
    : m_strMsg(strMsg)
{
    m_nKind = nKind;
}

// @0x1414825f0
MessengerData::ReportLog::ReportLog(CStringW strName, CStringW strMsg)
    : m_strName(strName), m_strMsg(strMsg)
{
}

// @0x141482680
MessengerData::TalkTab::TalkTab()
    : m_nClose(1), m_nDetach(1), m_nAdditive(0), m_strName("")
{
}

// @0x141482710
MessengerData::TalkTab::TalkTab(CStringW strName, int nClose, int nDetach, int nAdditive)
    : m_nClose(nClose), m_nDetach(nDetach), m_nAdditive(nAdditive), m_strName(strName)
{
}

// @0x1414827c0
int MessengerData::TalkTab::FUN_1414827c0(Unk_MdXml* pXml)
{
    pXml->FUN_140873420("tabName", &m_strName);
    pXml->FUN_1408731e0("close", &m_nClose);
    pXml->FUN_1408731e0("detach", &m_nDetach);
    pXml->FUN_1408731e0("additive", &m_nAdditive);
    if (m_strName.IsEmpty())
        return 0;
    return m_panel.FUN_141482220(pXml);
}

// @0x141482880
int MessengerData::TalkTab::FUN_141482880(Unk_MdXml* pXml)
{
    pXml->FUN_1408740a0("tabName", &m_strName);
    pXml->FUN_140873ca0("close", m_nClose);
    pXml->FUN_140873ca0("detach", m_nDetach);
    pXml->FUN_140873ca0("additive", m_nAdditive);
    bool bEmpty = m_strName.IsEmpty();
    int nResult;
    if (bEmpty)
        nResult = 0;
    else
        nResult = m_panel.FUN_141482340(pXml);
    return nResult;
}

// @0x141482940
CStringW MessengerData::TalkTab::FUN_141482940()
{
    return m_strName;
}

// @0x141482990
Unk_MdNames::Unk_MdNames()
    : m_strCurrent(""), m_names(10)
{
}

// @0x1414829e0
CStringW Unk_MdNames::FUN_1414829e0()
{
    if (m_strCurrent.IsEmpty())
        FUN_141482bb0();
    return m_strCurrent;
}

Unk_MdState* FUN_141482e80();

// @0x141482a50
CStringW Unk_MdNames::FUN_141482a50()
{
    if (FUN_141482e80()->m_pChat != 0)
    {
        POSITION pos = m_names.GetHeadPosition();
        while (pos != 0)
        {
            CStringW strName = m_names.GetNext(pos);
            if (FUN_141482e80()->m_pChat->FUN_141a23d70(strName) != 0)
                return strName;
        }
        return FUN_141482e80()->m_pChat->FUN_141a258a0();
    }
    return FUN_1414829e0();
}

// @0x141482b70
void Unk_MdNames::FUN_141482b70()
{
    m_strCurrent = "";
    m_names.RemoveAll();
}

// @0x141482bb0
void Unk_MdNames::FUN_141482bb0()
{
    if (m_names.IsEmpty() == 0)
    {
        m_strCurrent = m_names.RemoveTail();
    }
    else
    {
        if (FUN_141482e80()->m_pChat != 0)
            m_strCurrent = FUN_141482e80()->m_pChat->FUN_141a258a0();
    }
}

// @0x141482c80
void Unk_MdNames::FUN_141482c80(CStringW strName)
{
    if (strName.IsEmpty())
        return;
    FUN_141482d30(CStringW(strName));
    m_names.AddTail(strName);
    m_strCurrent = strName;
}

// @0x141482d30
void Unk_MdNames::FUN_141482d30(CStringW strName)
{
    for (POSITION pos = m_names.Find(strName, 0); pos != 0; pos = m_names.Find(strName, pos))
        m_names.RemoveAt(pos);
    if (m_strCurrent == strName)
        m_strCurrent = L"";
}

// @0x141482df0
Unk_MdState::Unk_MdState()
{
    m_n38 = 0;
    m_p40 = 0;
    m_pChat = 0;
    m_p50 = 0;
}

// @0x141482e50
void Unk_MdState::FUN_141482e50()
{
    m_n38 = 0;
    m_p40 = 0;
}

#ifndef MS2_HOOK_DLL
// @0x141482e80
Unk_MdState* FUN_141482e80()
{
    static Unk_MdState s_state;
    return &s_state;
}
#endif

// @0x141482f00
int FUN_141482f00(int nType)
{
    if (nType == 0x10 || nType == 0x19)
        return 0x17;
    if (nType == 0xb || nType == 0x16)
        return 0x15;
    if (nType == 0xc)
        return 0x16;
    if (nType == 8)
        return 3;
    if (nType == 0x12)
        return 0x18;
    if (nType == 7)
        return 2;
    if (nType == 3)
        return 4;
    if (nType == 4)
        return 4;
    if (nType == 0xf)
        return 0x11;
    if (nType == 0x14)
        return 0x1a;
    return 1;
}

// @0x141482fb0
Unk_MdEntry::Unk_MdEntry()
    : m_nKind(0), m_nId(0), m_strImage(L""), m_strName(L""), m_strInfo(L"")
{
}

// @0x141483040
Unk_MdEntry::Unk_MdEntry(__int64 nId)
{
    Unk_MdPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1530(nId);
    if (pPlayer == 0)
        return;
    m_nKind = 1;
    m_nId = nId;
    m_strImage = (const char*)FUN_141028be0(pPlayer->FUN_141656a80(), pPlayer->FUN_1416612e0(), 1, "");
    m_strName = pPlayer->vfunc_77();
    unsigned short nLevel = pPlayer->vfunc_78();
    m_strInfo = FUN_140c348b0(0x20, &nLevel, FUN_1401a9d70()->FUN_141811980(6, pPlayer->FUN_141654730()));
}

// @0x141483300
Unk_MdEntry::Unk_MdEntry(Unk_MdSrcA& src)
{
    m_nKind = src.FUN_1401cc680();
    m_nId = src.FUN_1401cc230();
    m_strImage = (const char*)FUN_141028be0(m_nId, src.FUN_1401cc530(), 1, "");
    m_strName = src.FUN_1401cc1c0();
    int nTime = src.FUN_1401cc210();
    m_strInfo = FUN_140a228f0(0x20, &nTime, FUN_1401a9d70()->FUN_141811980(6, FUN_140644bb0(FUN_1401d7a50(), src.FUN_1401cc290())));
}

// @0x141483580
Unk_MdEntry::Unk_MdEntry(Unk_MdSrcB& src)
{
    m_nKind = (src.FUN_141637c20() == 0);
    m_nId = src.m_nId;
    m_strImage = (const char*)FUN_141028be0(m_nId, src.m_name.FUN_1408f1a60(), 1, "");
    m_strName = src.m_name.FUN_1408f19e0();
    m_strInfo = FUN_140c348b0(0x20, src.m_time, FUN_1401a9d70()->FUN_141811980(6, src.m_nJob));
}

// @0x141483830
Unk_MdEntry::Unk_MdEntry(Unk_MdSrcC& src)
{
    m_nKind = (src.m_nState == 0);
    m_nId = src.m_nId;
    m_strImage = (const char*)FUN_141028be0(m_nId, src.m_name.FUN_1404ca980(), 1, "");
    m_strName = src.m_name.FUN_1404ca890();
    m_strInfo = FUN_140c348b0(0x20, src.m_time, FUN_1401a9d70()->FUN_141811980(6, FUN_140644bb0(FUN_1401d7a50(), src.m_nClass)));
}

// @0x141483af0
Unk_MdEntry::Unk_MdEntry(Unk_MdSrcD& src)
{
    m_nKind = src.FUN_14137b160();
    m_nId = src.m_nId;
    m_strImage = (const char*)FUN_141028be0(m_nId, src.m_name.FUN_1408f1a60(), 1, "");
    m_strName = src.m_name.FUN_1408f19e0();
    m_strInfo = FUN_140c348b0(0x20, src.m_time, FUN_1401a9d70()->FUN_141811980(6, src.m_nJob));
}

// @0x141483d80
unsigned Unk_MdEntry::FUN_141483d80()
{
    return m_nKind;
}

// @0x141483da0
__int64 Unk_MdEntry::FUN_141483da0()
{
    return m_nId;
}

// @0x141483dc0
CStringW Unk_MdEntry::FUN_141483dc0()
{
    return m_strImage;
}

// @0x141483e10
CStringW Unk_MdEntry::FUN_141483e10()
{
    return m_strName;
}

// @0x141483e60
CStringW Unk_MdEntry::FUN_141483e60()
{
    return m_strInfo;
}

// @0x141483eb0
GroupMessengerData::TalkLog::TalkLog()
    : m_strName(""), m_strMsg("")
{
    m_nKind = 0;
    m_nA = 0;
    m_nB = 0;
}

// @0x141483f50
GroupMessengerData::TalkLog::TalkLog(int nKind, CStringW strName, CStringW strMsg)
    : m_strName(strName), m_strMsg(strMsg)
{
    m_nKind = nKind;
    m_nA = 0;
    m_nB = 0;
}

// @0x141484010
GroupMessengerData::TalkLog::TalkLog(int nKind, CStringW strName, CStringW strMsg, int nA, int nB)
    : m_strName(strName), m_strMsg(strMsg)
{
    m_nKind = nKind;
    m_nA = nA;
    m_nB = nB;
}

CString FUN_1414842b0(int nKind, CStringW strName);

// @0x1414840d0
__int64 FUN_1414840d0(GroupMessengerData::TalkLog* pLog)
{
    Unk_MdRoomPtr room = FUN_141484720()->FUN_14137e630(pLog->m_nKind);
    if (room.FUN_141381230(0))
        return 0;
    Unk_MdMemberPtr member = room.FUN_141381280()->FUN_14137ba10(CStringW(pLog->m_strMsg));
    if (member.FUN_14137c360(0))
        return 0;
    return member.FUN_14137c3b0()->m_nOwner;
}

// @0x141484200
CString FUN_141484200(GroupMessengerData::TalkLog* pLog)
{
    return FUN_1414842b0(pLog->m_nKind, CStringW(pLog->m_strMsg));
}

// @0x141484270
void FUN_141484270(GroupMessengerData::TalkLog* pLog)
{
    pLog->m_nB = 0;
}

// @0x141484290
int FUN_141484290(GroupMessengerData::TalkLog* pLog)
{
    return pLog->m_nB;
}

// @0x1414842b0
CString FUN_1414842b0(int nKind, CStringW strName)
{
    Unk_MdRoomPtr room = FUN_141484720()->FUN_14137e630(nKind);
    if (room.FUN_141381230(0) != 0)
        return CString("");
    Unk_MdMemberPtr member = room.FUN_141381280()->FUN_14137ba10(CStringW(strName));
    if (member.FUN_14137c360(0) != 0)
        return CString("");
    return FUN_141028be0(member.FUN_14137c3b0()->m_nOwner, member.FUN_14137c3b0()->m_name.FUN_1408f1a60(), 1, "");
}

// @0x141484720
Unk_MdRooms* FUN_141484720()
{
    return g_pRooms;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2920-0x142cb2940 .text$yd
