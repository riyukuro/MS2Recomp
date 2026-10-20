// uiworldmapdialog.h - UIWorldMapDialog (RTTI .?AVUIWorldMapDialog@@, 0x280 bytes, UI id 0x4e42, swf "WorldMapDialog"):
// the world map window (map tiles of the selected world, field icons and tooltips, taxi / portal / cash taxi moves,
// field search, field missions). Owning unit: ?\uiworldmapdialog.cpp (0x141b53fc0-0x141b6db40, statics
// 0x14011f630-0x14011f750). Header name assumed from the unit path. Layout from the ctor and the v2525 snapshot
// (work/ext/v2525 include/ms2/client/UIWorldMapDialog.h, same layout); member and method names are invented unless noted.
// vftables: primary 0x142ff3368 (84 slots), IMessageListener-in-UIDialog 0x142ff3610. ??_G 0x141b69030.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <map>
#include <set>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiworldmap.h"

class AScript;
class ASTextInput;
class ASUIComponent;
class ASMovieClip;
class CQuestData;
template <class T> class Unk_FieldPtr;    // commonfiles/fieldmetatable.h
class ASData;
class ASObj;
class CInPacket;
class CMsgBoxData;
class MyPC;
class UIMsg;
class UISwfEntity;

class UIWorldMapDialog : public UIDialog
{
public:
    typedef std::vector<MS2Ptr<UIWorldMap::MapTile> > TileVector;

    UIWorldMapDialog();                                                     // 0x141b53fc0
    virtual ~UIWorldMapDialog();                                            //  0 0x141b54250 (??_G 0x141b69030)
    virtual CString vfunc_1();                                              //  1 0x141b54350 "WorldMapDialog"
    virtual int vfunc_13();                                                 // 13 0x141b54650 the Enter key in the search box
    virtual void OnLoadComplete();                                          // 22 0x141b54920
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b55300
    virtual int vfunc_48() { return 0x4e42; }                               // 48 0x141b69530 the ui id
    virtual int vfunc_53(void* pCfg);                                       // 53 0x141b55120 save the "setting" block
    virtual int vfunc_54(void* pCfg);                                       // 54 0x141b551c0 load the "setting" block
    virtual int vfunc_65();                                                 // 65 0x141b543a0 open
    virtual void vfunc_67();                                                // 67 0x141b54430 close
    virtual void vfunc_72();                                                // 72 0x141b54620
    virtual void vfunc_79(void* p);                                         // 79 0x141b54d50 packets 0x84 / 0x85
    virtual void vfunc_80(void* p);                                         // 80 0x141b54f00 the "m_fieldSearch" request answer
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);               // IMessageListener 0 0x141b56a20

    void FUN_141b56c30(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141b56c30 the boss icon tooltip
    int FUN_141b57410();                                                    // 0x141b57410 the field to show
    void FUN_141b57580(CInPacket* pPacket);                                 // 0x141b57580 packet 0x84 mode 0: the tiles
    void FUN_141b57620(CInPacket* pPacket);                                 // 0x141b57620 packet 0x84 mode 1: additional infos
    void FUN_141b57660();                                                   // 0x141b57660 select the pending field
    void FUN_141b57740();                                                   // 0x141b57740 apply the pending search text
    void FUN_141b57870();                                                   // 0x141b57870 build the tiles of the world
    void FUN_141b58200();                                                   // 0x141b58200
    void FUN_141b58220();                                                   // 0x141b58220 update the additional infos
    void FUN_141b58350(MS2Ptr<UIWorldMap::MapTile> spTile);                 // 0x141b58350 "updateAdditional"
    void FUN_141b58670(unsigned int nFieldId, int nQuestId, short nLevel, int bRelated);   // 0x141b58670 add a quest line
    void FUN_141b58830(unsigned int nFieldId, int nNpcField, int nNpcId, int nKind, int nQuestId, short nLevel, int nState);   // 0x141b58830 add an npc quest line
    void FUN_141b58e80();                                                   // 0x141b58e80 request the tiles (packet 0x4a)
    void FUN_141b58f00();                                                   // 0x141b58f00
    void FUN_141b58f80();                                                   // 0x141b58f80
    void FUN_141b5cea0(ATL::CAtlMap<int, MS2Ptr<CQuestData> >& starts, ATL::CAtlMap<int, MS2Ptr<CQuestData> >& completes,
        Unk_FieldPtr<ATL::CAtlList<unsigned int> > spNpcs, unsigned short nLevel, unsigned short nRange);   // 0x141b5cea0 the quests the npcs start / complete
    void FUN_141b59840();                                                   // 0x141b59840 party member icons
    void FUN_141b59a80();                                                   // 0x141b59a80 buddy icons
    void FUN_141b59d40();                                                   // 0x141b59d40 quest icons
    void FUN_141b5a290();                                                   // 0x141b5a290 dungeon icons
    void FUN_141b5a550(int nFieldId);                                       // 0x141b5a550 take the taxi
    void FUN_141b5aa70(int nFieldId);                                       // 0x141b5aa70 take the cash taxi
    bool FUN_141b5ad60(int nButton, const CMsgBoxData& data);               // 0x141b5ad60 the taxi fare prompt
    bool FUN_141b5ae00(int nButton, const CMsgBoxData& data);               // 0x141b5ae00 the merat air taxi prompt
    bool FUN_141b5aec0(int nButton, const CMsgBoxData& data);               // 0x141b5aec0 the cash taxi prompt
    void FUN_141b5af80(int n);                                              // 0x141b5af80 (TaxiStationAction)
    int FUN_141b5afe0(int nFieldId);                                        // 0x141b5afe0 move by portal (packet 0x54)
    void FUN_141b5b190();                                                   // 0x141b5b190 flush the queued tiles
    CStringW FUN_141b5b380(MS2Ptr<UIWorldMap::MapTile> spTile);             // 0x141b5b380 the tile tooltip
    void FUN_141b5b790(MS2Ptr<UIWorldMap::MapTile> spTile);                 // 0x141b5b790 "createMap"
    void FUN_141b5bc70(int nFieldId);                                       // 0x141b5bc70 select a field once open
    void FUN_141b5bcc0(CStringW strText);                                   // 0x141b5bcc0 search once open
    void FUN_141b5bd30();                                                   // 0x141b5bd30 the display settings changed
    void FUN_141b5be10();                                                   // 0x141b5be10
    void FUN_141b5c230();                                                   // 0x141b5c230 the field mission mode
    void FUN_141b5c2b0(int nRound, ASObj* pObj);                            // 0x141b5c2b0 the field mission rewards
    void FUN_141b5cbc0();                                                   // 0x141b5cbc0 request the mission reward (packet 0x29)
    void FUN_141b5cc40(int nRound);                                         // 0x141b5cc40 "m_fieldMission"
    MS2Ptr<UIWorldMap::MapTile> FUN_141b5d120();                            // 0x141b5d120 the current tile
    void FUN_141b5d390();
    void FUN_141b5d4b0(MS2Ptr<UIWorldMap::MapTile> spTile, ASObj* pObj);    // 0x141b5d4b0 the tile part of "createMap"
    void FUN_141b5e160(MS2Ptr<UIWorldMap::IconInfo> spIcon, ASObj* pObj);   // 0x141b5e160
    void FUN_141b5e330(MS2Ptr<UIWorldMap::IconInfo> spIcon, ASObj* pObj);   // 0x141b5e330
    void FUN_141b5e580(MS2Ptr<UIWorldMap::IconInfo> spIcon, ASObj* pObj);   // 0x141b5e580
    void FUN_141b5e9e0(MS2Ptr<UIWorldMap::IconInfo> spIcon, ASObj* pObj);   // 0x141b5e9e0
    void FUN_141b5ec30(MS2Ptr<UIWorldMap::IconInfo> spIcon, ASObj* pObj);   // 0x141b5ec30
    void FUN_141b5ee80(MS2Ptr<UIWorldMap::MapTile> spTile, ASObj* pObj);    // 0x141b5ee80
    void FUN_141b5f540(MS2Ptr<UIWorldMap::MapTile> spTile, ASObj* pObj);    // 0x141b5f540
    void FUN_141b5f740(MS2Ptr<UIWorldMap::MapTile> spTile, ASObj* pObj);    // 0x141b5f740                                                   // 0x141b5d390 the radio button mode changed
    void FUN_141b5faa0(MS2Ptr<UIWorldMap::AddtionalInfo> spInfo, ASObj* pObj);   // 0x141b5faa0 mode 1 additional info
    void FUN_141b5fb80(MS2Ptr<UIWorldMap::AddtionalInfo> spInfo, ASObj* pObj);   // 0x141b5fb80 mode 2 additional info
    void FUN_141b60000(MS2Ptr<UIWorldMap::AddtionalInfo> spInfo, ASObj* pObj);   // 0x141b60000 mode 3 additional info
    void FUN_141b60170(MS2Ptr<UIWorldMap::AddtionalInfo> spInfo, ASObj* pObj);   // 0x141b60170 mode 4 additional info
    void FUN_141b602f0();                                                   // 0x141b602f0 apply the searched field
    void FUN_141b60490(CStringW strText);                                   // 0x141b60490 search a field by name
    void FUN_141b605e0(CStringW strName);                                   // 0x141b605e0
    int FUN_141b602a0(int nFieldId);                                        // 0x141b602a0 the field shown for a field
    bool FUN_141b60b40(int nFrom, int nTo);                                 // 0x141b60b40 the fields are linked by a portal
    void FUN_141b60c40(int nFieldId, bool b);                               // 0x141b60c40
    void FUN_141b60d40(CStringW strText);                                   // 0x141b60d40
    void FUN_141b60e90(int nFieldId, MyPC* pPlayer);                        // 0x141b60e90 the cash taxi prompt
    void FUN_141b614c0(MyPC* pPlayer);                                      // 0x141b614c0 the cash taxi prompts (vip, meso, advanced ticket)
    void FUN_141b61ff0(int nFieldId);                                       // 0x141b61ff0 select a tile
    bool FUN_141b5af30(int nButton, const CMsgBoxData& data);               // 0x141b5af30 the mission attack prompt

    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);      // 0x140ba7930 movie clip child lookup (a UIDialog member)
    MS2Ptr<ASUIComponent> FUN_140c02990(const CString& strName);            // 0x140c02990 GetChild<ASUIComponent> (template COMDAT of another unit)
    MS2Ptr<ASTextInput> FUN_140e35bd0(const CString& strName);              // 0x140e35bd0 text input child lookup (UIDialog template COMDAT)

    int FUN_141b69340() { return m_nWorld; }                                // 0x141b69340
    int FUN_141b69690() { return m_nField; }                                // 0x141b69690

protected:
    MS2_LAYOUT_FRIEND;
    int m_nWorld;                                       // +0x178 the selected world
    int m_nField;                                       // +0x17c the field the map is centred on
    MS2Ptr<UIWorldMap::MapTile> m_spTile;               // +0x180 the current tile
    int m_190;                                          // +0x190 the taxi target field ("OnTaxi")
    int m_194;                                          // +0x194
    int m_198;                                          // +0x198 the portal target field ("OnPortal")
    int m_nMode;                                        // +0x19c the radio button mode ("setInitalRadioBtn")
    std::set<unsigned int> m_1a0;                       // +0x1a0
    std::list<MS2Ptr<UIWorldMap::MapTile> > m_tiles;    // +0x1b0 the tiles queued for the movie
    int m_1c0;                                          // +0x1c0
    int m_1c4;                                          // +0x1c4
    int m_1c8;                                          // +0x1c8 the pending field to select
    CStringW m_strSearch;                               // +0x1d0 the pending search text
    UIWorldMap::DisplaySetting m_display;               // +0x1d8
    int m_islandIndex[2];                               // +0x208 "getCachedIslandIndex"
    int m_210;                                          // +0x210 the field mission mode
    int m_214;                                          // +0x214 the mission attack mode ("missionAttack")
    int m_218;                                          // +0x218 the sky fortress mode
    ATL::CAtlArray<unsigned int> m_npcIds;              // +0x220 WorldmapSpecialFunctionNpcID
    ATL::CAtlArray<CString> m_npcFrames;                // +0x240 WorldmapSpecialFunctionNpcFrame
    ATL::CAtlArray<CString> m_npcTooltips;              // +0x260 WorldmapSpecialFunctionNpcTooltip
};
MS2_CHECK_SIZE(UIWorldMapDialog, 0x280);
MS2_CHECK_OFFSET(UIWorldMapDialog, m_spTile, 0x180);
MS2_CHECK_OFFSET(UIWorldMapDialog, m_nMode, 0x19c);
MS2_CHECK_OFFSET(UIWorldMapDialog, m_1a0, 0x1a0);
MS2_CHECK_OFFSET(UIWorldMapDialog, m_tiles, 0x1b0);
MS2_CHECK_OFFSET(UIWorldMapDialog, m_strSearch, 0x1d0);
MS2_CHECK_OFFSET(UIWorldMapDialog, m_display, 0x1d8);
MS2_CHECK_OFFSET(UIWorldMapDialog, m_islandIndex, 0x208);
MS2_CHECK_OFFSET(UIWorldMapDialog, m_npcIds, 0x220);
MS2_CHECK_OFFSET(UIWorldMapDialog, m_npcTooltips, 0x260);
