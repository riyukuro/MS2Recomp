// portal.h - CPortal (RTTI .?AVCPortal@@, CPtred, 0x1b8 bytes): the client-side object of one map portal (field portal,
// dungeon lobby/room portal, event portal, massive portal ...). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13);
// the unit is client\ms2\portal.cpp (0x14169afb0-0x14169d920). Header name assumed from the unit path; member names are
// invented from their use. vftable: slot 0 only (the deleting destructor 0x14169d5d0).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/cameratargetboundingbox.h"
#include "ms2/commonfiles/portaldata.h"
#include <afx.h>
#include <atlstr.h>
#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <efd/SmartPointer.h>

class UIDebugTooltip;

// The oriented box of a portal (the same helper values as CCameraTargetBoundingBox: bounds, world box, pose and inverse
// pose). The portal keeps one at +0x50; its member functions are separate out-of-line functions of this unit.
struct Unk_PortalBox
{
    Unk_PortalBox();                                                    // 0x14169afb0
    ~Unk_PortalBox();                                                   // 0x14169b020
    int FUN_14169b080(egf::Entity* pEntity);                           // read size / position / rotation from the entity
    int FUN_14169b2e0(const Vector3* pPoint);                  // is the point inside the box

    Unk_CtbBounds3 m_bounds;                                            // +0x00 local box
    Unk_CtbObb m_obb;                                                   // +0x18 the box in world space
    Unk_CtbMat34 m_pose;                                                // +0x54
    Unk_CtbMat34 m_inverse;                                             // +0x84
};
MS2_CHECK_SIZE(Unk_PortalBox, 0xb4);
MS2_CHECK_OFFSET(Unk_PortalBox, m_obb, 0x18);
MS2_CHECK_OFFSET(Unk_PortalBox, m_pose, 0x54);
MS2_CHECK_OFFSET(Unk_PortalBox, m_inverse, 0x84);

class CPortal : public CPtred
{
public:
    CPortal();                                                          // 0x14169b350
    virtual ~CPortal();                                                 //  0 0x14169b520 (??_G 0x14169d5d0)

    // @0x14169b650 read the "model" / "theme" strings and the position from the entity (the entity is passed by value)
    bool FUN_14169b650(efd::SmartPointer<egf::Entity> spEntity);
    bool FUN_14169b890();                                               // create the tooltip above the portal
    bool FUN_14169ba90();                                               // load the theme image onto Theme_Image_Plane
    void FUN_14169bd40();                                               // per-frame: countdown text and event timer
    void FUN_14169c280();                                               // refresh the tooltip and the image by type
    int FUN_14169c330();                                                // both content switches enabled
    CStringW FUN_14169c3b0();                                           // action string of the portal type
    CString FUN_14169c5f0();                                            // portal kind name ("portal", "dungeon", ...)
    CStringW FUN_14169cae0();                                           // display name
    int FUN_14169cc40();                                                // quest-npc table lookup for this portal
    void FUN_14169cc70(const Vector3& pos, const Vector3& rot);   // move the entity, reload the box
    void FUN_14169cd50(int bShown, int bGlow);                          // show / glow flags on the entity
    void FUN_14169ce50(int bShown, int bGlow, int bExtra);              // same with a third flag
    void FUN_14169cf90(int bShown);
    void FUN_14169d050(int bGlow);
    void FUN_14169d0e0();                                               // initial flags
    bool FUN_14169d160();                                               // entity "shown" flag
    bool FUN_14169d1d0();                                               // shown flag and the extra flag
    int FUN_14169d280();                                                // entity int property 0xa162d321
    Vector3 FUN_14169d2f0();                                    // entity position (zero point when the entity is gone)
    void FUN_14169d3a0();                                               // scale the entity of type 0x10 by 1.5

    egf::EntityID m_idEntity;                                           // +0x18
    int m_nId;                                                          // +0x20 portal / room id
    int m_unk_24;
    int m_unk_28;
    Vector3 m_pos2c;                                            // +0x2c
    Vector3 m_pos38;                                            // +0x38
    Vector3 m_pos44;                                            // +0x44
    Unk_PortalBox m_box;                                                // +0x50
    QuestMask m_questMask;                                              // +0x108
    int m_unk_148;                                                      // +0x148 (string-table argument of the tooltip)
    int m_unk_14c;
    int m_unk_150;
    int m_unk_154;
    __int64 m_unk_158;
    int m_nType;                                                        // +0x160 portal type
    unsigned m_nEndTime;                                                // +0x164 countdown target (0 = none)
    CStringW m_strTime;                                                 // +0x168 last countdown text
    unsigned m_nEventTime;                                              // +0x170 event deadline (0 = none)
    CStringW m_strTip;                                                  // +0x178 tooltip format argument
    CString m_strImage;                                                 // +0x180 theme image path
    int m_unk_188;
    bool m_b18c;
    CStringW m_strFeature;                                              // +0x190 content switch names
    CStringW m_strLocale;                                               // +0x198
    MS2Ptr<UIDebugTooltip> m_tooltip;                                   // +0x1a0
    int m_bFlash;                                                       // +0x1b0
};
MS2_CHECK_SIZE(CPortal, 0x1b8);
MS2_CHECK_OFFSET(CPortal, m_idEntity, 0x18);
MS2_CHECK_OFFSET(CPortal, m_nId, 0x20);
MS2_CHECK_OFFSET(CPortal, m_pos2c, 0x2c);
MS2_CHECK_OFFSET(CPortal, m_box, 0x50);
MS2_CHECK_OFFSET(CPortal, m_questMask, 0x108);
MS2_CHECK_OFFSET(CPortal, m_nType, 0x160);
MS2_CHECK_OFFSET(CPortal, m_strTime, 0x168);
MS2_CHECK_OFFSET(CPortal, m_strTip, 0x178);
MS2_CHECK_OFFSET(CPortal, m_strImage, 0x180);
MS2_CHECK_OFFSET(CPortal, m_strFeature, 0x190);
MS2_CHECK_OFFSET(CPortal, m_tooltip, 0x1a0);
MS2_CHECK_OFFSET(CPortal, m_bFlash, 0x1b0);
