// cinteractobjectdata.h - PLACEHOLDER for CInteractObjectData (RTTI .?AVCInteractObjectData@@, 0x320 bytes), one
// <interact> row of Table/InteractObject.xml (+ InteractObject_mastery.xml); every CInteractObject
// (client/ms2/interactobject.h) keeps a MS2Ptr to its row. NOT an original header. Owner: ?\interactobjectdata.cpp
// (ctor 0x14051caa0, dtor 0x14051cd40, deleting dtor 0x140521340, loader 0x14051ce70). Bases: CCacheData (+0),
// CValidData<CInteractObjectData> (+0x28). The layout is the loader's: one nested struct per child element, each with
// its own inline ctor/dtor COMDAT (0x140520880-0x140521250); the names are the xml attribute names.
#pragma once

#include <utility>
#include <vector>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/portaldata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cvaliddata.h"

class Unk_140165cf0;

// One <conditionAdditionalEffect> entry: first = the effect "id", second = its "level". The exe's element is a
// std::pair<unsigned, unsigned short> (its non-trivial operator= picks the element-wise vector glue); the derived
// struct keeps that codegen and the name other units pin.
struct Unk_InteractReqItem : std::pair<unsigned, unsigned short>
{
    Unk_InteractReqItem(unsigned& nId, unsigned short& nLevel) : std::pair<unsigned, unsigned short>(nId, nLevel) {}
};
MS2_CHECK_SIZE(Unk_InteractReqItem, 8);

// "type" of an <interact> (1 mesh, 2, 3, 4 web, 5, 6, 8 bill board, 9; 0 rejects the row).
enum Unk_InteractObjectType { Unk_InteractObjectType_None = 0 };
// <mastery> "type"
enum Unk_InteractMasteryType { Unk_InteractMasteryType_None = 0 };
// <reward> "expType" / "firstExpType"
enum Unk_InteractExpType
{
    Unk_InteractExpType_Telescope = 3,
    Unk_InteractExpType_RareChest = 4,
    Unk_InteractExpType_RareChestFirst = 5,
    Unk_InteractExpType_NormalChest = 6,
    Unk_InteractExpType_DungeonBoss = 8,
    Unk_InteractExpType_None = 0x30,
};

class CInteractObjectData : public CCacheData, public CValidData<CInteractObjectData>
{
public:
    // <mesh>
    struct Mesh
    {
        Mesh() : m_nNormalCollision(1), m_nReactableCollision(1), m_shapeDimension(150.0f, 150.0f, 150.0f) {}
        int m_nNormalCollision;         // +0x00 mesh collision switch handed to the box controller
        int m_nReactableCollision;      // +0x04
        Unk_PDVec3 m_shapeDimension;    // +0x08 box controller dimensions (cm)
        CString m_strReactObjectAni;    // +0x18 asset of the mesh object
    };
    // <ui>
    struct Ui
    {
        CString m_strSwf;               // +0x00 UI dialog name (CInteractUIObject)
        CString m_strValue;             // +0x08
    };
    // <validate>
    struct Validate
    {
        Validate() : m_nFieldId(0), m_fInteractionDistance(0) {}
        int m_nFieldId;                 // +0x00
        float m_fInteractionDistance;   // +0x04 the UI object closes when the player is farther than this
    };
    // <gathering>
    struct Gathering
    {
        Gathering() : m_nReceipeId(0) {}
        int m_nReceipeId;               // +0x00 gathering table id (CInteractGatheringObject)
    };
    // <user>
    struct User
    {
        ATL::CAtlArray<CString> m_aReactAni;    // +0x00 "reactAni" (comma list)
        CString m_strFailAni;           // +0x20
        CString m_strSuccessAni;        // +0x28
    };
    // An exp reward: <reward> "expType"/"relativeExpRate" (and the "first" pair).
    struct ExpInfo
    {
        ExpInfo() : m_eType(Unk_InteractExpType_None), m_fRate(0) {}
        void Load(Unk_140165cf0* pElem, const char* pszType, const char* pszRate);  // 0x14051c920
        int IsValid();                  // 0x14051ca60
        Unk_InteractExpType m_eType;    // +0x00 (uiminimapentity.cpp: 3 builds a telescope)
        float m_fRate;                  // +0x04
    };
    // <reward>
    struct Reward
    {
        Reward() : m_nExp(0) {}
        __int64 m_nExp;                 // +0x00
        ExpInfo m_exp;                  // +0x08
        ExpInfo m_firstExp;             // +0x10
    };
    // <skill>
    struct Skill
    {
        Skill() : m_nCode(0), m_nLevel(0), m_nFriendly(-1), m_nCount(1), m_nInterval(0), m_nProp(10000) {}
        unsigned m_nCode;               // +0x00
        unsigned short m_nLevel;        // +0x04
        int m_nFriendly;                // +0x08
        int m_nCount;                   // +0x0c
        unsigned m_nInterval;           // +0x10
        unsigned m_nProp;               // +0x14
    };
    // An additional effect: <additionalEffect><modify> and the <invoke> list entries.
    struct AdditionalEffect
    {
        AdditionalEffect() : m_nCode(0), m_nLevel(0), m_nProp(10000), m_nModifyTime(0) {}
        unsigned m_nCode;               // +0x00
        unsigned short m_nLevel;        // +0x04
        int m_nProp;                    // +0x08
        int m_nModifyTime;              // +0x0c
    };
    // <effect>
    struct Effect
    {
        CString m_strNormal;            // +0x00 effect asset for the first state
        CString m_strReactable;         // +0x08 effect asset for the second state
        CString m_strInteraction;       // +0x10
        QuestMask m_maskNormal;         // +0x18 quest condition of the first state
        QuestMask m_maskReactable;      // +0x58 quest condition of the second state
        QuestMask m_maskInteraction;    // +0x98
        CString m_strSuccess;           // +0xd8 effect asset of the placed particle
    };
    // <item>
    struct Item
    {
        Item() : m_nCode(0), m_nRank(0), m_nConsume(0), m_nCheckCount(0) {}
        unsigned m_nCode;               // +0x00 item the player must carry
        int m_nRank;                    // +0x04 rarity (0: the item's default)
        unsigned m_nConsume;            // +0x08
        int m_nCheckCount;              // +0x0c
    };
    // <conditionAdditionalEffect>
    struct ConditionEffectList
    {
        ConditionEffectList() { m_aItem.clear(); }
        std::vector<Unk_InteractReqItem> m_aItem;
    };
    // <drop>
    struct Drop
    {
        Drop() : m_nObjectLevel(0), m_nObjectDropRank(1), m_nDropHeight(0), m_nDropDistance(0) {}
        int m_nObjectLevel;             // +0x00 -1: "mapLevel"
        int m_nObjectDropRank;          // +0x04
        int m_nDropHeight;              // +0x08 height a dropped item starts from (0: default)
        int m_nDropDistance;            // +0x0c distance a dropped item flies (0: default)
        std::vector<unsigned> m_aGlobalDropBoxId;       // +0x10
        std::vector<unsigned> m_aIndividualDropBoxId;   // +0x28
    };
    // <room>
    struct Room
    {
        Room() : m_nPrivateRoomId(0), m_nPortalLifeTime(0), m_nPartyPortal(0), m_nBossNpcId(0), m_nHideBossName(0) {}
        int m_nPrivateRoomId;           // +0x00
        unsigned m_nPortalLifeTime;     // +0x04
        int m_nPartyPortal;             // +0x08
        unsigned m_nBossNpcId;          // +0x0c
        int m_nHideBossName;            // +0x10
    };
    // <homePrivilege>
    struct HomePrivilege
    {
        HomePrivilege() : m_nCheck(0) {}
        int m_nCheck;                   // +0x00 extra requirement id (0: none)
    };
    // <webOpen>
    struct WebOpen
    {
        WebOpen() : m_nType(1) {}
        CString m_strUrl;               // +0x00
        int m_nType;                    // +0x08
    };
    // <displayURL>
    struct DisplayUrl
    {
        CString m_strIndirectUrl;       // +0x00 web address of the display image
        int m_nType;                    // +0x08 1 guild, 2/4/5 character, 3 guild score (not initialized)
    };
    // <display>
    struct Display
    {
        Display() : m_nNotice(0) {}
        CString m_strMinimapIcon;       // +0x00 minimap icon (uiminimapentity.cpp: AddNamed)
        int m_nNotice;                  // +0x08
    };
    // <arena>
    struct Arena
    {
        Arena() : m_nCanInteractTeamId(0) {}
        int m_nCanInteractTeamId;       // +0x00
    };
    // <portal>
    struct Portal
    {
        Portal() : m_nTargetPortalId(0) {}
        int m_nTargetPortalId;          // +0x00
    };
    // <guild>
    struct Guild
    {
        Guild() : m_nHousePosterId(0) {}
        int m_nHousePosterId;           // +0x00 guild poster id
    };
    // <weapon>
    struct Weapon
    {
        Weapon() : m_nWeaponItemId(0) {}
        unsigned m_nWeaponItemId;       // +0x00
    };
    // <mastery>
    struct Mastery
    {
        Mastery() : m_eType(Unk_InteractMasteryType_None), m_nValue(0) {}
        Unk_InteractMasteryType m_eType;    // +0x00
        int m_nValue;                   // +0x04
    };
    // One <spawn> entry (the attributes are parallel comma lists).
    struct Spawn
    {
        Spawn() : m_nCode(0), m_nRadius(0), m_nCount(0), m_nProp(0), m_nLifeTime(0) {}
        int m_nCode;                    // +0x00
        int m_nRadius;                  // +0x04
        int m_nCount;                   // +0x08
        int m_nProp;                    // +0x0c
        int m_nLifeTime;                // +0x10
    };

    CInteractObjectData();              // 0x14051caa0
    virtual ~CInteractObjectData();     // 0x14051cd40

    bool Load(Unk_140165cf0* pElem);    // 0x14051ce70
    int FUN_14051f270();                // the <quest> mask has entries

    // The table: every row by "id" (the loaders read both files).
    static void LoadAll();                                          // 0x14051f2b0
    static MS2Ptr<CInteractObjectData> Get(int nId);               // 0x14051f670 (reloads a changed file)
    static void GetAll(ATL::CAtlArray<MS2Ptr<CInteractObjectData> >& aOut);   // 0x14051f800
    static void CheckInit();                                        // 0x140521650 (inline in the owner unit)
    static void SetInit(bool bInit);                                // 0x140522ce0 (inline in the owner unit)
    static ATL::CAtlMap<int, MS2Ptr<CInteractObjectData> > s_table;    // 0x143aaf120
    static CLockCriticalSection s_lock;                             // 0x143aaf0e8
    static bool s_bInit;                                            // 0x143aaf0a1

    // Inline members of the original header (their COMDATs are in scenestategame.cpp's range).
    // @0x1417486f0
    int FUN_1417486f0() { return m_eType == 1; }    // a mesh object
    // @0x1417486c0
    int FUN_1417486c0() { return m_eType == 8; }    // a bill board
    // The interact object factory's kind tests (WorldService 0x141bcda90; COMDATs in ?\worldservice.cpp#6).
    // @0x141c05790
    int FUN_141c05790() { return m_eType == 2; }
    // @0x141c057c0
    int FUN_141c057c0() { return m_eType == 3; }
    // @0x141c05820
    int FUN_141c05820() { return m_eType == 4; }    // a web object (CInteractWebObject)
    // @0x141c04f90
    int FUN_141c04f90() { return m_eType == 5; }
    // @0x141c051c0
    int FUN_141c051c0() { return m_eType == 6; }
    // @0x141c057f0
    int FUN_141c057f0() { return m_eType == 9; }

    unsigned m_nId;                     // +0x30 "id" (the table key)
    Unk_InteractObjectType m_eType;     // +0x34 "type"
    QuestMask m_maskUse;                // +0x38 <quest> condition to use the object at all
    int m_nCollection;                  // +0x78 "collection" (scenestategame 0x63 mode 13 announces the first use)
    unsigned m_nReactCount;             // +0x7c "reactCount"
    Mesh m_mesh;                        // +0x80
    Ui m_ui;                            // +0xa0
    Validate m_validate;                // +0xb0
    Gathering m_gathering;              // +0xb8
    unsigned m_nResetTime;              // +0xbc <time> milliseconds
    unsigned m_nReactTime;              // +0xc0
    unsigned m_nHideTime;               // +0xc4
    User m_user;                        // +0xc8
    Reward m_reward;                    // +0xf8
    Skill m_skill;                      // +0x110
    AdditionalEffect m_modify;          // +0x128 <additionalEffect><modify>
    Effect m_effect;                    // +0x138
    Item m_item;                        // +0x218
    ConditionEffectList m_aReqItem;     // +0x228 <conditionAdditionalEffect>
    Drop m_drop;                        // +0x240
    Room m_room;                        // +0x280
    HomePrivilege m_homePrivilege;      // +0x294
    WebOpen m_webOpen;                  // +0x298
    DisplayUrl m_displayUrl;            // +0x2a8
    Display m_display;                  // +0x2b8
    Arena m_arena;                      // +0x2c8
    Portal m_portal;                    // +0x2cc
    Guild m_guild;                      // +0x2d0
    Weapon m_weapon;                    // +0x2d4
    Mastery m_mastery;                  // +0x2d8
    ATL::CAtlArray<Spawn> m_aSpawn;     // +0x2e0
    ATL::CAtlArray<AdditionalEffect> m_aInvoke;     // +0x300 <additionalEffect><invoke>
};
MS2_CHECK_SIZE(CInteractObjectData, 0x320);
MS2_CHECK_SIZE(CInteractObjectData::Mesh, 0x20);
MS2_CHECK_SIZE(CInteractObjectData::User, 0x30);
MS2_CHECK_SIZE(CInteractObjectData::Reward, 0x18);
MS2_CHECK_SIZE(CInteractObjectData::Skill, 0x18);
MS2_CHECK_SIZE(CInteractObjectData::Effect, 0xe0);
MS2_CHECK_SIZE(CInteractObjectData::Drop, 0x40);
MS2_CHECK_SIZE(CInteractObjectData::Room, 0x14);
MS2_CHECK_SIZE(CInteractObjectData::Spawn, 0x14);
MS2_CHECK_OFFSET(CInteractObjectData, m_nId, 0x30);
MS2_CHECK_OFFSET(CInteractObjectData, m_maskUse, 0x38);
MS2_CHECK_OFFSET(CInteractObjectData, m_mesh, 0x80);
MS2_CHECK_OFFSET(CInteractObjectData, m_ui, 0xa0);
MS2_CHECK_OFFSET(CInteractObjectData, m_validate, 0xb0);
MS2_CHECK_OFFSET(CInteractObjectData, m_nReactTime, 0xc0);
MS2_CHECK_OFFSET(CInteractObjectData, m_user, 0xc8);
MS2_CHECK_OFFSET(CInteractObjectData, m_reward, 0xf8);
MS2_CHECK_OFFSET(CInteractObjectData, m_skill, 0x110);
MS2_CHECK_OFFSET(CInteractObjectData, m_effect, 0x138);
MS2_CHECK_OFFSET(CInteractObjectData, m_item, 0x218);
MS2_CHECK_OFFSET(CInteractObjectData, m_aReqItem, 0x228);
MS2_CHECK_OFFSET(CInteractObjectData, m_drop, 0x240);
MS2_CHECK_OFFSET(CInteractObjectData, m_room, 0x280);
MS2_CHECK_OFFSET(CInteractObjectData, m_homePrivilege, 0x294);
MS2_CHECK_OFFSET(CInteractObjectData, m_displayUrl, 0x2a8);
MS2_CHECK_OFFSET(CInteractObjectData, m_display, 0x2b8);
MS2_CHECK_OFFSET(CInteractObjectData, m_mastery, 0x2d8);
MS2_CHECK_OFFSET(CInteractObjectData, m_aSpawn, 0x2e0);
MS2_CHECK_OFFSET(CInteractObjectData, m_aInvoke, 0x300);
