// interactobject.h - CInteractObject, the client-side behaviour of a world object the player can press the interact
// key on (gathering nodes, telescopes, notice boards, guild posters, watch towers, ...), and its eight subclasses.
// Owning unit: ?\interactobject.cpp (0x1413fd240-0x1414043e0). Header name assumed from the unit path; class names are
// the exe's (RTTI). The object is created for a map entity (vfunc_1 binds the entity and its row of the interact
// table, CInteractObjectData), keeps an effect (marker) for its current state and a packet-sending use path.
// Vftables: CInteractObject 0x142f0d2b8, Mesh 0x142f0d348, Telescope 0x142f0d3d8, UI 0x142f0d468, DisplayImage
// 0x142f0d4f8, Gathering 0x142f0d588, GuildPoster 0x142f0d618, BillBoard 0x142f0d6a8, WatchTower 0x142f0d738,
// Delegate<void(NotifyObject*)>::DelegateImpl<pair<CInteractTelescopeObject*, ...>> 0x142f0d7c8.
#pragma once
#include <afx.h>
#include <atlstr.h>
#include <NxPhysics.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cinteractobjectdata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/cubespawnobject.h"

struct Unk_InteractMsg;         // the message handed to vfunc_2 (a stream sits at +8)
class Unk_PhysPropObj;          // prop object behind a physics prop pointer
class Unk_IoRankPtr;            // smart pointer to a ranking entry (declared in interactobject.cpp)

// What a mouse hover over the object shows: the cursor kind and the hint text (+0x28).
struct Unk_InteractCursor
{
    int m_nCursor;              // +0x00 the row's cursor type
    int m_pad_04[9];
    CStringW m_strHint;         // +0x28
};

// Smart pointer to the prop object of a mesh interact object (the same shape as the one physxhelper.cpp declares).
class Unk_InteractPropPtr
{
public:
    Unk_InteractPropPtr(int nNull);                             // 0x140ae1340
    ~Unk_InteractPropPtr();                                     // 0x140ae16b0
    void FUN_140ae17e0(Unk_PhysPropObj* p);                     // assign (0 releases)
    Unk_PhysPropObj* FUN_140ae1920() const;                     // the object
private:
    Unk_PhysPropObj* m_p;
};
MS2_CHECK_SIZE(Unk_InteractPropPtr, 8);

class CInteractObject : public CPtred
{
public:
    CInteractObject();                                          // 0x1413fd240
    virtual ~CInteractObject();                                 // 0x1413fd380 (deleting 0x141403e10)

    virtual int vfunc_1(Unk_Entity* pEntity, int nState);       // 1  0x1413fd460 bind the entity and its table row
    virtual void vfunc_2(Unk_InteractMsg* pMsg);                // 2  0x1413fd6b0
    virtual void vfunc_3(int nState);                           // 3  0x1413fd6d0 switch the displayed state
    virtual int vfunc_4();                                      // 4  0x1413fd740 may the local player use it
    virtual int vfunc_5();                                      // 5  0x141403ff0 kind id (1 mesh .. 9 watch tower)
    virtual void vfunc_6(Unk_InteractCursor* pOut);             // 6  0x1413fd9b0 cursor kind and hint text
    virtual int vfunc_7();                                      // 7  0x141404070 state is the second one
    virtual void vfunc_8();                                     // 8  0x1413fe370 send "use" (packet 0x31 / 0xb)
    virtual void vfunc_9();                                     // 9  0x1413fe430
    virtual void vfunc_10();                                    // 10 0x1413fe440 send "use" (packet 0x31 / 0xc)
    virtual void vfunc_11();                                    // 11 0x1413fe580 per-frame update
    virtual void vfunc_12();                                    // 12 0x1413fe5d0 spawn the placed particle
    virtual CString vfunc_13();                                 // 13 0x1413fe7d0 asset name of the current state
    virtual void vfunc_14(int n);                               // 14 0x1414040c0
    virtual int vfunc_15();                                     // 15 0x141403f90
    virtual int vfunc_16();                                     // 16 0x141403f10

    // Inline members of the original header (their COMDATs live in other units' ranges).
    MS2Ptr<CInteractObjectData> FUN_140966e00();                // 0x140966e00 copy of the row pointer
    CString FUN_140967060();                                    // 0x140967060 copy of the name
    int FUN_140967110();                                        // 0x140967110 id of the entity's template
    Unk_StreamPoint FUN_1409673c0();                            // 0x1409673c0 position copy
    Unk_StreamPoint FUN_1417d4940();                            // 0x1417d4940 rotation copy (stateinteractdata.cpp)
    int FUN_1413b5600();                                        // 0x1413b5600 the interact state (0: usable; uiminimapentity.cpp)
    // @0x140967150
    int FUN_140967150() { return m_nVisible; }
    // @0x14174a4a0
    void FUN_14174a4a0(const CString& strName) { m_strName = strName; }
    // @0x14174a4d0
    void FUN_14174a4d0() { m_bSpawned = 1; }
    // @0x141c04fc0
    unsigned char FUN_141c04fc0() { return m_bSpawned; }   // WorldService 0x141bbfb50 (?\worldservice.cpp#6)

    Unk_EntRef FUN_1413fd890();                                 // copy of the entity handle
    egf::EntityID FUN_1413fd8e0();                              // id of the entity (0 when unbound)
    unsigned __int64 FUN_1413fd960();                           // 64-bit id of the entity (0 when unbound)
    void FUN_1413fda50();                                       // (re)create the state effect
    void FUN_1413fdc50();                                       // destroy the state effect
    void FUN_1413fdca0(unsigned char bVisible);                 // show / hide the entity's actor
    int FUN_1413fdd80();                                        // the player has enough of the required item count
    int FUN_1413fde40();                                        // the player carries the required item
    int FUN_1413fdfc0();                                        // the use condition (quest mask) is met
    int FUN_1413fe040();                                        // the player meets the extra requirement
    int FUN_1413fe120();                                        // the player's guild-less requirement is met
    int FUN_1413fe220();                                        // the player owns one of the required items
    void FUN_1413fe500();                                       // refresh the effect after a state change
    QuestMask* FUN_1413fe8a0();                                 // quest mask of the current state
    void FUN_1413fe910();                                       // register with the highlight manager
    void FUN_1413fe9a0(int nDelay);                             // unregister (now, or after nDelay ms)

    Unk_EntRef m_ent;                                           // +0x18 the map entity
    CString m_strName;                                          // +0x20 name of the entity's template
    int m_nState;                                               // +0x28 current state (0 / 1 / 2)
    int m_nShownState;                                          // +0x2c state the effect was created for (3: none)
    int m_nEffect;                                              // +0x30 handle of the state effect
    int m_nParticle;                                            // +0x34 handle of the placed particle
    MS2Ptr<CInteractObjectData> m_spRow;                        // +0x38
    int m_nRowId;                                               // +0x48 id of the table row
    Unk_StreamPoint m_vPos;                                     // +0x4c entity position
    Unk_StreamPoint m_vRot;                                     // +0x58 entity rotation, degrees
    int m_nVisible;                                             // +0x64
    unsigned char m_bHighlight;                                 // +0x68 registered with the highlight manager
    Timer m_timer;                                              // +0x70
    unsigned char m_bSpawned;                                   // +0xa8 created by the field (scenestategame 0x63)
    char m_pad_a9[7];
};
MS2_CHECK_SIZE(CInteractObject, 0xb0);
MS2_CHECK_OFFSET(CInteractObject, m_ent, 0x18);
MS2_CHECK_OFFSET(CInteractObject, m_strName, 0x20);
MS2_CHECK_OFFSET(CInteractObject, m_spRow, 0x38);
MS2_CHECK_OFFSET(CInteractObject, m_vPos, 0x4c);
MS2_CHECK_OFFSET(CInteractObject, m_timer, 0x70);

// An object with a mesh the player can bump into: gives it a box actor of the row's size.
class CInteractMeshObject : public CInteractObject
{
public:
    CInteractMeshObject();                                      // 0x1413fea90
    virtual ~CInteractMeshObject();                             // 0x1413feb40 (deleting 0x141403dd0)

    virtual int vfunc_1(Unk_Entity* pEntity, int nState);       // 0x1413febf0
    virtual void vfunc_2(Unk_InteractMsg* pMsg);                // 0x141404060
    virtual void vfunc_3(int nState);                           // 0x1413fef20
    virtual int vfunc_4();                                      // 0x1413ff0f0
    virtual int vfunc_5();                                      // 0x141403fe0
    virtual void vfunc_8();                                     // 0x1413ff110
    virtual void vfunc_9();                                     // 0x1413ff140

    void MakeNxBoxController();                                 // 0x1413ff170 create the box actor
    void FUN_1413ff5f0();                                       // release the box actor
    void FUN_1413ff690(const CString& strAsset);                // show the asset on the entity (model / sound)
    void FUN_1413ff800(int nCollision);                         // box actor on / off
    void FUN_1413ff840();                                       // play the use asset of the row
    void FUN_1413ff8a0();                                       // play the second asset

    NxActor* m_pActor;                                          // +0xb0 the box actor
    Unk_InteractPropPtr m_spProp;                               // +0xb8
    unsigned char m_nAssetType;                                 // +0xc0 1: AssetID properties, 2: utf8 properties
    CString m_strAssetA;                                        // +0xc8
    CString m_strAssetB;                                        // +0xd0
};
MS2_CHECK_SIZE(CInteractMeshObject, 0xd8);
MS2_CHECK_OFFSET(CInteractMeshObject, m_pActor, 0xb0);
MS2_CHECK_OFFSET(CInteractMeshObject, m_spProp, 0xb8);
MS2_CHECK_OFFSET(CInteractMeshObject, m_strAssetA, 0xc8);

// A telescope: plays the "looking through it" cinematic (post effect, system sound) while the player uses it.
class CInteractTelescopeObject : public CInteractObject
{
public:
    CInteractTelescopeObject();                                 // 0x1413ff8d0
    virtual ~CInteractTelescopeObject();                        // 0x1413ff920 (deleting 0x141403e50)

    virtual void vfunc_2(Unk_InteractMsg* pMsg);                // 0x1413ff980 enter the cinematic
    virtual int vfunc_5();                                      // 0x141404000

    void OnCutSceneSkip(NotifyObject* pNotify);                 // 0x1413fff60 leave the cinematic

    int m_bActive;                                              // +0xb0
    int m_pad_b4;
};
MS2_CHECK_SIZE(CInteractTelescopeObject, 0xb8);

// An object that opens a UI dialog (named by the row) while the player stays close.
class CInteractUIObject : public CInteractObject
{
public:
    CInteractUIObject();                                        // 0x1414001e0
    virtual ~CInteractUIObject();                               // 0x141400230 (deleting 0x141403e90)

    virtual void vfunc_2(Unk_InteractMsg* pMsg);                // 0x141400260 open the dialog
    virtual int vfunc_5();                                      // 0x141404010
    virtual void vfunc_11();                                    // 0x1414003c0 close it when the player walks away

    int m_nDialogId;                                            // +0xb0
    int m_pad_b4;
};
MS2_CHECK_SIZE(CInteractUIObject, 0xb8);

// An object that shows a web image (guild / character ranking portrait) fetched by a worker thread.
class CInteractDisplayImage : public CInteractObject
{
public:
    CInteractDisplayImage();                                    // 0x141400520
    virtual ~CInteractDisplayImage();                           // 0x141400600 (deleting 0x141403d10)

    virtual int vfunc_1(Unk_Entity* pEntity, int nState);       // 0x141400670
    virtual int vfunc_5();                                      // 0x141403fb0

    void FUN_141400800(const CStringW& strGuild);               // cache the data of one guild / character
    void FUN_141401380(Unk_IoRankPtr spRank);     // take the data from a ranking entry
    void FUN_1414017b0(const CString& strFile);                 // load the image file into the entity
    CStringW FUN_141402060();                                   // caption of the image
    int FUN_1414021c0();                                        // rank number of the image
    int FUN_1414022a0();                                        // trophy count of the image
    static UINT GetURLFromIndirectURL(LPVOID pParam);           // 0x141401920 worker thread
    static UINT GetURLFromGameRanking(LPVOID pParam);           // 0x141401c20 worker thread

    CString m_strUrl;                                           // +0xb0 resolved image address
    CWinThread* m_pThread;                                      // +0xb8
    CStringW m_strGuildName;                                    // +0xc0
    int m_nGuildRank;                                           // +0xc8 (also: rank of a guild)
    int m_nGuildTrophy;                                         // +0xcc
    int m_nGuildScore;                                          // +0xd0
    int m_pad_d4;
    CStringW m_strCharName;                                     // +0xd8
    int m_nCharRank;                                            // +0xe0
    int m_nCharTrophy;                                          // +0xe4
    int m_nCharBuildPoint;                                      // +0xe8
    int m_nCharScore;                                           // +0xec
};
MS2_CHECK_SIZE(CInteractDisplayImage, 0xf0);

// A gathering node: shown until used, hidden for the respawn time, reports the use to the server.
class CInteractGatheringObject : public CInteractMeshObject
{
public:
    CInteractGatheringObject();                                 // 0x1414023b0
    virtual ~CInteractGatheringObject();                        // 0x141402400 (deleting 0x141403d50)

    virtual int vfunc_1(Unk_Entity* pEntity, int nState);       // 0x141402430
    virtual void vfunc_2(Unk_InteractMsg* pMsg);                // 0x141402490 a player used the node
    virtual int vfunc_5();                                      // 0x141403fc0
    virtual void vfunc_6(Unk_InteractCursor* pOut);             // 0x1414027c0
    virtual int vfunc_7();                                      // 0x141402940
    virtual void vfunc_11();                                    // 0x141402750 respawn when the time is up
    virtual CString vfunc_13();                                 // 0x1414028c0
    virtual void vfunc_14(int n);                               // 0x1414040a0 set the respawn tick
    virtual int vfunc_15();                                     // 0x141403f70
    virtual int vfunc_16();                                     // 0x141402ad0

    int FUN_141402b40();                                        // the node can be used (gathering table check)
    int FUN_141402c50();                                        // milliseconds until the node respawns
    int FUN_141402c90();                                        // BOOL: the gathering id is a valid node

    int m_nRespawnTick;                                         // +0xd8 tick at which the node comes back (0: present)
    int m_pad_dc;
};
MS2_CHECK_SIZE(CInteractGatheringObject, 0xe0);

// A guild poster: shows the guild's emblem file.
class CInteractGuildPosterObject : public CInteractObject
{
public:
    CInteractGuildPosterObject();                               // 0x141402cf0
    virtual ~CInteractGuildPosterObject();                      // 0x141402d30 (deleting 0x141403d90)

    virtual int vfunc_1(Unk_Entity* pEntity, int nState);       // 0x141402d60
    virtual int vfunc_5();                                      // 0x141403fd0
    virtual void vfunc_10();                                    // 0x141402dd0

    int FUN_141402e60();                                        // the poster id of the row
    void FUN_141402eb0(unsigned char bShow);                    // fetch and show the poster
    void FUN_141403180(CStringW strFile);                       // load the poster file into the entity
};
MS2_CHECK_SIZE(CInteractGuildPosterObject, 0xb0);

// A billboard: a mesh object that hides while the field billboard is up.
class CInteractBillBoardObject : public CInteractMeshObject
{
public:
    CInteractBillBoardObject();                                 // 0x1414032e0
    virtual ~CInteractBillBoardObject();                        // 0x141403340 (deleting 0x141403cd0)

    virtual int vfunc_4();                                      // 0x141403390
    virtual int vfunc_5();                                      // 0x141403fa0

    __int64 m_nBoard;                                           // +0xd8
    CStringW m_strText;                                         // +0xe0
};
MS2_CHECK_SIZE(CInteractBillBoardObject, 0xe8);

// A watch tower: its marker only shows when the local player is closer than 2000 units.
class CInteractWatchTowerObject : public CInteractMeshObject
{
public:
    CInteractWatchTowerObject();                                // 0x141403400
    virtual ~CInteractWatchTowerObject();                       // 0x141403440 (deleting 0x141403ed0)

    virtual int vfunc_1(Unk_Entity* pEntity, int nState);       // 0x141403470
    virtual void vfunc_3(int nState);                           // 0x1414034e0
    virtual int vfunc_4();                                      // 0x1414034d0
    virtual int vfunc_5();                                      // 0x141404020
    virtual int vfunc_7();                                      // 0x1414034c0
    virtual void vfunc_11();                                    // 0x1414035d0

    unsigned char m_bNear;                                      // +0xd8
    int m_pad_dc;
};
MS2_CHECK_SIZE(CInteractWatchTowerObject, 0xe0);
