// separatenode.h - Unk_SeparateNode (exe symbols ??0Unk_SeparateNode@@...; RTTI name "SeparateNode"): a NiNode that
// keeps its world transform separated from the parent's - UpdateWorldData resets the world transform and then copies
// only the parent components (translate / rotate / scale) whose bit is set in a 1-byte bitset<3>. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\separatenode.cpp` (.text$mn 0x141751290-0x1417516d0,
// .text$di 0x140100860-0x140100890). Header name assumed; member and method names invented.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ninode.h"
#include "ms2/client/ms2/lighteffectparam.h"    // Unk_LightUpdateBits (bitset<3>: ctor 0x140afed60, operator[] 0x14144b330)

class NiCloningProcess;

void FUN_14097fad0(float* pDst, const float* pSrc);         // 0x14097fad0: NiPoint3 assignment

// 0x138 bytes. vftable 0x142f60d20 (overrides slots 0 ddtor, 2 GetRTTI, 3 CreateClone, 32 UpdateWorldData). The exe's
// 1-byte member is its own Unk_CamMoveBits (same commonfiles bitset<3> as Unk_LightUpdateBits; only that type's
// out-of-line ctor/operator[] are emitted, so reuse it here). Implicit dtor 0x1417514c0, ??_G 0x141751660.
class Unk_SeparateNode : public NiNode
{
public:
    // The exe mangles this ctor as `...@EEE@Z` (three unsigned char); declaring the params `bool` is what reproduces
    // its bytes (it forwards the raw argument to Unk_BitRef::operator=(bool) with no normalization).
    Unk_SeparateNode(bool b0, bool b1, bool b2);                           // 0x141751380
    Unk_SeparateNode(Unk_LightUpdateBits kBits);                             // 0x141751470
    virtual ~Unk_SeparateNode();                                             // 0x1417514c0
    virtual const NiRTTI* GetRTTI() const;                                   // slot 2, 0x1417516c0
    virtual NiObject* CreateClone(NiCloningProcess& kCloning);               // slot 3, 0x141751290
    virtual void UpdateWorldData();                                          // slot 32, 0x1417514f0
    void CopyMembers(NiNode* pkDest, NiCloningProcess& kCloning);            // 0x141751340
    static const NiRTTI ms_RTTI;                                             // 0x143ae95a8

    Unk_LightUpdateBits m_kBits;                                             // +0x130: which parent components to keep
};
MS2_CHECK_SIZE(Unk_SeparateNode, 0x138);
MS2_CHECK_OFFSET(Unk_SeparateNode, m_kBits, 0x130);

