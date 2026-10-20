// weaponattachtransformnode.h - WeaponAttachTransformNode (ms_RTTI 0x143af77a8, base LightUnaffectedNode; 0x188 bytes): the
// dummy node an equipped weapon hangs off. Mode 0 follows the parent like a plain node; otherwise the node sits at a base
// offset (m_kBasePos: z in the parent's frame, x/y in the follow node's frame) with a fixed base rotation (optionally turned
// by the follow node's world rotation). With m_bUseMovement the world transform then trails through the INodeMovement
// (a COrbMovement by default). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed from the unit
// path, member names invented from the use. equipmodel.cpp still overlays this class as Unk_AttachDummy.
#pragma once
#include <NiPoint3.h>
#include <NiMatrix3.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"                        // MS2Ptr<T>
#include "ms2/client/ms2/lightunaffectednode.h"

class INodeMovement;

class WeaponAttachTransformNode : public LightUnaffectedNode
{
public:
    WeaponAttachTransformNode();                            // 0x141b76c30
    virtual ~WeaponAttachTransformNode();                   // 0x141b76d50 (??_G 0x141b771e0)
    virtual const NiRTTI* GetRTTI() const;                  // 0x141b77240
    virtual NiObject* CreateClone(NiCloningProcess& kCloning);   // 0x141b76a90
    virtual void UpdateWorldData();                         // 0x141b76dc0
    void CopyMembers(WeaponAttachTransformNode* pkDest, NiCloningProcess& kCloning);   // 0x141b76b30
    static const NiRTTI ms_RTTI;                            // 0x143af77a8 (constructed in unit_14011fb10)

    void SetMovement(INodeMovement* pMovement);             // 0x141b771b0
    // Out-of-line setters (identical-code folded with other TUs' setters, hence the far addresses).
    void SetFollowNode(NiAVObject* pNode);                  // 0x141207f40
    void SetMode(int nMode);                                // 0x141205a60
    void SetUseMovement(int bUse);                          // 0x141205a40
    void SetBasePosition(const NiPoint3& kPos);             // 0x141207fd0
    void SetBaseRotate(const NiMatrix3& kRotate);           // 0x141207f70

    NiAVObject* m_pFollow;                                  // +0x138 the node whose world rotation turns the base offset
    MS2Ptr<INodeMovement> m_spMovement;                     // +0x140
    int m_nMode;                                            // +0x150 0 = plain child node
    int m_bUseMovement;                                     // +0x154
    NiPoint3 m_kBasePos;                                    // +0x158
    NiMatrix3 m_kBaseRotate;                                // +0x164
};
MS2_CHECK_SIZE(WeaponAttachTransformNode, 0x188);
MS2_CHECK_OFFSET(WeaponAttachTransformNode, m_pFollow, 0x138);
MS2_CHECK_OFFSET(WeaponAttachTransformNode, m_spMovement, 0x140);
MS2_CHECK_OFFSET(WeaponAttachTransformNode, m_nMode, 0x150);
MS2_CHECK_OFFSET(WeaponAttachTransformNode, m_kBasePos, 0x158);
MS2_CHECK_OFFSET(WeaponAttachTransformNode, m_kBaseRotate, 0x164);
