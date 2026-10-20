// cinteractobjectdata.h - PLACEHOLDER for CInteractObjectData (RTTI .?AVCInteractObjectData@@, 0x320 bytes), the
// row of the interact-object table that every CInteractObject (client/ms2/interactobject.h) keeps a MS2Ptr to.
// NOT an original header. Owner of the class: ?\interactobjectdata.cpp (ctor 0x14051caa0, dtor 0x14051cd40, deleting
// dtor 0x140521340). Only the members that interactobject.cpp reads are named (all offsets proven from its callers);
// the gaps are scalar padding. Bases: CCacheData (+0), CValidData<CInteractObjectData> (+0x28). It is never
// constructed outside its owner, so the ctor and dtor are declared only.
#pragma once

#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/portaldata.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

// One required item of an interact object: the item id and its rarity (the std::vector at +0x228 holds them).
struct Unk_InteractReqItem
{
    unsigned m_nItemId;                 // +0x00
    unsigned short m_nRarity;           // +0x04
    unsigned short m_pad_06;
};
MS2_CHECK_SIZE(Unk_InteractReqItem, 8);

class CInteractObjectData : public CCacheData, public CValidData<CInteractObjectData>
{
public:
    CInteractObjectData();              // 0x14051caa0
    virtual ~CInteractObjectData();     // 0x14051cd40

    // Inline members of the original header (their COMDATs are in scenestategame.cpp's range).
    // @0x1417486f0
    int FUN_1417486f0() { return m_nKind == 1; }    // a mesh object
    // @0x1417486c0
    int FUN_1417486c0() { return m_nKind == 8; }    // a bill board

    int m_nBanMapType;                  // +0x30 map type in which the object may not be used
    int m_nKind;                        // +0x34 object kind (1 mesh, 8 bill board; scenestategame 0x63 mode 9)
    QuestMask m_maskUse;                // +0x38 quest condition to use the object at all
    int m_nFirstUseNotice;              // +0x78 announce the first use (scenestategame 0x63 mode 13)
    int m_pad_7c;
    int m_nShowCollisionA;              // +0x80 mesh collision switch handed to the box controller
    int m_nShowCollisionB;              // +0x84
    float m_fBoxX;                      // +0x88 box controller dimensions (cm)
    float m_fBoxY;                      // +0x8c
    float m_fBoxZ;                      // +0x90
    int m_pad_94;
    CString m_strMeshPathA;             // +0x98 asset to show the mesh object
    CString m_strUiName;                // +0xa0 UI dialog name (CInteractUIObject)
    CString m_strUiTitle;               // +0xa8
    int m_pad_b0;
    float m_fRange;                     // +0xb4 UI object closes when the player is farther than this
    int m_nGatherId;                    // +0xb8 gathering table id (CInteractGatheringObject)
    int m_nRespawnTime;                 // +0xbc milliseconds
    int m_nCursorType;                  // +0xc0
    int m_pad_c4[17];                   // +0xc4 .. +0x108 (sub-objects not read by interactobject.cpp)
    int m_nMinimapKind;                 // +0x108 3: a telescope (uiminimapentity.cpp: BuildTelescope)
    int m_pad_10c[11];                  // +0x10c .. +0x138
    CString m_strModelA;                // +0x138 effect asset for the first state
    CString m_strModelB;                // +0x140 effect asset for the second state
    int m_pad_148[2];
    QuestMask m_maskStateA;             // +0x150 quest condition of the first state
    QuestMask m_maskStateB;             // +0x190 quest condition of the second state
    int m_pad_1d0[16];                  // +0x1d0 .. +0x210
    CString m_strEffect;                // +0x210 effect asset of the placed particle
    int m_nCostItemId;                  // +0x218 item the player must carry
    int m_nCostItemRarity;              // +0x21c rarity (0: the item's default)
    unsigned m_nCostItemLevel;          // +0x220 minimum level of that item
    int m_pad_224;
    std::vector<Unk_InteractReqItem> m_aReqItem;   // +0x228 items of which the player needs one
    int m_pad_240[2];                   // +0x240 .. +0x248
    int m_nDropHeight;                  // +0x248 height a dropped item starts from (0: default)
    int m_nDropBase;                    // +0x24c distance a dropped item flies (0: default)
    int m_pad_250[17];                  // +0x250 .. +0x294
    int m_nNeedCond;                    // +0x294 extra requirement id (0: none)
    int m_pad_298[4];
    CString m_strUrl;                   // +0x2a8 web address of the display image
    int m_nImageType;                   // +0x2b0 1 guild, 2/4/5 character, 3 guild score
    int m_pad_2b4;
    CString m_strMinimapIcon;           // +0x2b8 minimap icon (uiminimapentity.cpp: AddNamed)
    int m_pad_2c0[2];
    int m_nNeedValue;                   // +0x2c8
    int m_pad_2cc;
    int m_nPosterId;                    // +0x2d0 guild poster id
    int m_pad_2d4;
    int m_nGatherNeedA;                 // +0x2d8
    int m_nGatherNeedB;                 // +0x2dc
    int m_pad_2e0[16];                  // +0x2e0 two CAtlArray<void*>
};
MS2_CHECK_SIZE(CInteractObjectData, 0x320);
MS2_CHECK_OFFSET(CInteractObjectData, m_nBanMapType, 0x30);
MS2_CHECK_OFFSET(CInteractObjectData, m_maskUse, 0x38);
MS2_CHECK_OFFSET(CInteractObjectData, m_nShowCollisionA, 0x80);
MS2_CHECK_OFFSET(CInteractObjectData, m_strMeshPathA, 0x98);
MS2_CHECK_OFFSET(CInteractObjectData, m_fRange, 0xb4);
MS2_CHECK_OFFSET(CInteractObjectData, m_nCursorType, 0xc0);
MS2_CHECK_OFFSET(CInteractObjectData, m_nMinimapKind, 0x108);
MS2_CHECK_OFFSET(CInteractObjectData, m_strModelA, 0x138);
MS2_CHECK_OFFSET(CInteractObjectData, m_maskStateA, 0x150);
MS2_CHECK_OFFSET(CInteractObjectData, m_maskStateB, 0x190);
MS2_CHECK_OFFSET(CInteractObjectData, m_strEffect, 0x210);
MS2_CHECK_OFFSET(CInteractObjectData, m_aReqItem, 0x228);
MS2_CHECK_OFFSET(CInteractObjectData, m_nNeedCond, 0x294);
MS2_CHECK_OFFSET(CInteractObjectData, m_strUrl, 0x2a8);
MS2_CHECK_OFFSET(CInteractObjectData, m_nGatherNeedB, 0x2dc);
