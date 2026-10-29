// userconditioneventdata.h - CUserConditionEventData (RTTI .?AVCUserConditionEventData@@, 0xb8 bytes): one <event> row of
// the user condition event table (Table/userConditionEvent.xml: <event id gameEventID><condition/><notify .../><mail .../>
// </event>). A cached data record (CCacheData +0, CValidData +0x28). A fired event can notify the player (text + attached
// items) and/or send a system mail (attached items, meso, merat). Owning unit: ?\userconditioneventdata.cpp. Header name
// assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

class CConditionCommonData;

// One <attachment job itemID itemRank itemCount/> entry, 0x14 bytes (the validity check keeps only known items).
struct Unk_UceAttachment
{
    Unk_UceAttachment();                    // 0x1408d3470
    int m_nJob;                             // +0x00 "job"
    unsigned m_nItemId;                     // +0x04 "itemID"
    int m_nItemRank;                        // +0x08 "itemRank" (1 by default)
    unsigned m_nItemCount;                  // +0x0c "itemCount"
    int m_pad_10;
};
MS2_CHECK_SIZE(Unk_UceAttachment, 0x14);

// <mail context useMail meso merat>, 0x38 bytes.
struct Unk_UceMail
{
    Unk_UceMail();                          // 0x1408d3550
    int m_nUseMail;                         // +0x00 "useMail"
    int m_nContext;                         // +0x04 "context"
    ATL::CAtlArray<Unk_UceAttachment> m_attachments;    // +0x08
    __int64 m_nMeso;                        // +0x28 "meso"
    __int64 m_nMerat;                       // +0x30 "merat"
};
MS2_CHECK_SIZE(Unk_UceMail, 0x38);

// <notify preview useNotify descKey descArg>, 0x38 bytes.
struct Unk_UceNotify
{
    Unk_UceNotify();                        // 0x1408d35b0
    int m_nUseNotify;                       // +0x00 "useNotify"
    int m_nPreview;                         // +0x04 "preview"
    CString m_strDescKey;                   // +0x08 "descKey"
    CString m_strDescArg;                   // +0x10 "descArg"
    ATL::CAtlArray<Unk_UceAttachment> m_attachments;    // +0x18
};
MS2_CHECK_SIZE(Unk_UceNotify, 0x38);

class CUserConditionEventData : public CCacheData, public CValidData<CUserConditionEventData>
{
public:
    typedef MS2Ptr<CUserConditionEventData> Ptr;

    CUserConditionEventData();                  // 0x1408d24c0
    virtual ~CUserConditionEventData();         // 0x1408d25b0 (??_G 0x1408d3890)

    static Ptr GetEvent(int nId);               // 0x1408d3090 the row by id (reloads when the file changed)
    static void GetAllEvents(ATL::CAtlArray<Ptr>& out);     // 0x1408d2fc0 every row, after a reload check
    static void Load();                         // 0x1408d2640 reads the xml into the map
    static void CheckInit();                    // 0x1408d3a70
    static void SetInit(bool b);                // 0x1408d4d30

    static bool s_bInit;                        // 0x143ab2528

    int m_nId;                                  // +0x30 "id"
    int m_nGameEventId;                         // +0x34 "gameEventID"
    Unk_UceMail m_mail;                         // +0x38
    Unk_UceNotify m_notify;                     // +0x70
    MS2Ptr<CConditionCommonData> m_spCondition; // +0xa8
};
MS2_CHECK_SIZE(CUserConditionEventData, 0xb8);
MS2_CHECK_OFFSET(CUserConditionEventData, m_mail, 0x38);
MS2_CHECK_OFFSET(CUserConditionEventData, m_notify, 0x70);
MS2_CHECK_OFFSET(CUserConditionEventData, m_spCondition, 0xa8);
