// The payload of the skill use packet (0x20 mode 0): written by FUN_1401fd510 / read by FUN_1401fd6e0
// (unit_1401f9eb0.cpp, which reads it as raw bytes); filled by StateSkill::FUN_1417ebc00 (stateskill.cpp, whose COMDATs
// the ctor 0x1417f5990 / dtor 0x1417f5b40 / point ctor 0x1417f5940 are).
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"

// The 12-byte position of the util helpers (util.cpp's Unk_UtilFloat3; FUN_141b6dff0 copies one).
struct Unk_UtilFloat3
{
    float x, y, z;
};

// A position of the payload (0x14027db40 is the shared (x, y, z) ctor).
struct Unk_SkillUseVec3
{
    Unk_SkillUseVec3(float fX, float fY, float fZ);         // 0x14027db40
    Unk_SkillUseVec3(const Unk_UtilFloat3& v) : x(v.x), y(v.y), z(v.z) {}   // 0x1417f5940
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_SkillUseVec3, 0xc);

struct Unk_SkillUsePayload
{
    Unk_SkillUsePayload()                                   // 0x1417f5990
        : m_nCastId(0), m_nTick(0), m_nSkillId(0), m_nLevel(0), m_nMotion(0), m_ptPos(0, 0, 0), m_ptDir(0, 0, 0),
          m_ptRot(0, 0, 0), m_fCooldown(0), m_nElapsed(0), m_bAE(false), m_n48(0), m_bAttached(false), m_nAttachId(0),
          m_n60(0)
    {
    }

    __int64 m_nCastId;                                      // +0x00
    int m_nTick;                                            // +0x08
    int m_nSkillId;                                         // +0x0c
    short m_nLevel;                                         // +0x10
    unsigned char m_nMotion;                                // +0x12
    Unk_SkillUseVec3 m_ptPos;                               // +0x14
    Unk_SkillUseVec3 m_ptDir;                               // +0x20
    Unk_SkillUseVec3 m_ptRot;                               // +0x2c
    float m_fCooldown;                                      // +0x38
    int m_nElapsed;                                         // +0x3c the client's elapsed time
    bool m_bAE;                                             // +0x40 CSkillRecord +0xae
    __int64 m_n48;                                          // +0x48 CSkillRecord::FUN_1417599c0
    bool m_bAttached;                                       // +0x50 the cast is attached to an npc node (feature 0xae)
    int m_nAttachId;                                        // +0x54 the npc's object id
    CString m_strAttachNode;                                // +0x58 the node name
    __int64 m_n60;                                          // +0x60 CSkillRecord::FUN_1417599e0 (the cooldown key)
};
MS2_CHECK_OFFSET(Unk_SkillUsePayload, m_ptPos, 0x14);
MS2_CHECK_OFFSET(Unk_SkillUsePayload, m_fCooldown, 0x38);
MS2_CHECK_OFFSET(Unk_SkillUsePayload, m_n48, 0x48);
MS2_CHECK_OFFSET(Unk_SkillUsePayload, m_strAttachNode, 0x58);
MS2_CHECK_SIZE(Unk_SkillUsePayload, 0x68);
