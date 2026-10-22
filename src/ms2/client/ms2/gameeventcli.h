// gameeventcli.h - the client side of the GameEvent family: one GameEvent<Name>Cli per event, which opens, refreshes or
// closes the matching dialog on start (OnStart) / end (vfunc_6). Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is `client\ms2\gameeventcli.cpp` (0x140ce28a0-0x140ceaa70 .text$mn, 0x1400d0b50-0x1400d1640
// .text$di). Header name assumed. The Cli classes add no storage of their own (TrafficOptimizerCli excepted).
#pragma once

#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/commonfiles/gameeventdtreward.h"
#include "ms2/commonfiles/gameeventstringboard.h"
#include "ms2/commonfiles/attendgiftdatagroup.h"

class NotifyObject;
class Unk_140165cf0;


// One <v> of the worldmap icon event's xml (the field icon the UGC portal map shows); 0x40 bytes, vftable 0x142d41d40-ish.
class EventIconInfo : public CPtred
{
public:
    EventIconInfo();                            // 0x140ce8dd0
    int Load(Unk_140165cf0* pElem);             // 0x140cea090
    unsigned m_nFieldId;                        // +0x18 "fieldID"
    CStringW m_strIconFrame;                    // +0x20 "iconFrame"
    CStringW m_strEventStr;                     // +0x28 "eventStr"
    int m_nOffsetX;                             // +0x30 "offsetX"
    int m_nOffsetY;                             // +0x34 "offsetY"
    float m_fScale;                             // +0x38 "scale"
};

class GameEventOntimeCli : public GameEventOntime
{
public:
    GameEventOntimeCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventGameMenuPopupCli : public GameEventGameMenuPopup
{
public:
    GameEventGameMenuPopupCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventEventFieldPopupCli : public GameEventEventFieldPopup
{
public:
    GameEventEventFieldPopupCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventDTRewardCli : public GameEventDTReward
{
public:
    GameEventDTRewardCli();
    void OnNotifyGameStart(NotifyObject* pNotify);   // 0x140ce2ff0
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventSaleAutoFishingCli : public GameEventSaleAutoFishing
{
public:
    GameEventSaleAutoFishingCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventSaleAutoPlayInstrumentCli : public GameEventSaleAutoPlayInstrument
{
public:
    GameEventSaleAutoPlayInstrumentCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventAttendGiftCli : public GameEventAttendGift
{
public:
    GameEventAttendGiftCli();
    bool FUN_140ce3510();
    bool FUN_140ce35c0();
    unsigned FUN_140ce3660();
    unsigned FUN_140ce3690();
    MS2Ptr<ItemGift> FUN_140ce3710(unsigned nDay);
    int FUN_140ce36d0();
    CStringW FUN_140ce37a0();
    CStringA FUN_140ce3850();
    int FUN_140ce38a0();
    unsigned FUN_140ce38c0();
    __int64 FUN_140ce38e0();
    int FUN_140ce3900();
    unsigned FUN_140ce3920();
    int FUN_140ce3960();
    int FUN_140ce3980();
    int FUN_140ce39a0();
    int FUN_140ce3a00();
    int FUN_140ce3a20();
    bool FUN_140ce3a80();
    CMsTime FUN_140ce3aa0();
    CMsTime FUN_140ce3ae0();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
    virtual void vfunc_10();
};

class GameEventCashAttendCli : public GameEventCashAttend
{
public:
    GameEventCashAttendCli();
    bool FUN_140ce3d90();
    bool FUN_140ce3da0();
    unsigned FUN_140ce3e40();
    unsigned FUN_140ce3e90();
    int FUN_140ce3ed0();
    CStringW FUN_140ce3f10();
    CStringW FUN_140ce3f70();
    AttendGiftDataGroupPtr FUN_140ce3fc0(unsigned nDay);
    CMsTime FUN_140ce4050();
    CMsTime FUN_140ce4090();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
    virtual void vfunc_10();
};

class GameEventTrafficOptimizerCli : public GameEventTrafficOptimizer
{
public:
    GameEventTrafficOptimizerCli();
    ATL::CAtlArray<unsigned> m_values;      // +0xd0 the 7 traffic limits
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
    virtual void vfunc_4(Unk_GEIn* in);
};

class GameEventItemBuffCli : public GameEventItemBuff
{
public:
    GameEventItemBuffCli();
    void FUN_140ce4580(NotifyObject* pNotify);   // the return-user buff notice
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventDungeonExtraRewardCli : public GameEventDungeonExtraReward
{
public:
    GameEventDungeonExtraRewardCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventMeratMarketNoticeCli : public GameEventMeratMarketNotice
{
public:
    GameEventMeratMarketNoticeCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventUpdateStringCli : public GameEventUpdateString
{
public:
    GameEventUpdateStringCli();
    void FUN_140ce4c60(Unk_140165cf0* pElem);
    void FUN_140ce4c90(Unk_140165cf0* pElem);
    void FUN_140ce4cc0(Unk_140165cf0* pElem);
    void FUN_140ce4cf0(Unk_140165cf0* pElem);
    void FUN_140ce4d20(Unk_140165cf0* pElem);
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventWorldmapIconCli : public GameEventWorldmapIcon
{
public:
    GameEventWorldmapIconCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventStringBoardCli : public GameEventStringBoard
{
public:
    GameEventStringBoardCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventSnowmanCli : public GameEventSnowman
{
public:
    GameEventSnowmanCli();
    void FUN_140ce56a0(NotifyObject* pNotify);   // the game started
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventRpsCli : public GameEventRps
{
public:
    GameEventRpsCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventCoupleDanceCli : public GameEventCoupleDance
{
public:
    GameEventCoupleDanceCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

class GameEventCustomTriggerStringCli : public GameEventCustomTriggerString
{
public:
    GameEventCustomTriggerStringCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};

struct Unk_CliPkt;

class GameEventBurningLevelupCli : public GameEventBurningLevelup
{
public:
    GameEventBurningLevelupCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
    virtual void vfunc_10(NotifyObject*);   // 0x140ce65f0 NotifyChangeMyLevel handler
    bool FUN_140ce64e0(short nLevel);
    void FUN_140ce7250(Unk_CliPkt&);
};

class GameEventLongTermAttendGiftCli : public GameEventLongTermAttendGift
{
public:
    GameEventLongTermAttendGiftCli();
    virtual CStringW vfunc_1();
    virtual void OnStart();
    virtual void vfunc_6();
};
