// kfmmodel.h - CKfmModel: CEquipModel loaded from a .kfm (animated NiActorManager model driven by an egf entity).
// Owning unit: ?\kfmmodel.cpp (0x14143d580-0x141443550 .text$mn + 5 .text$di). Header name assumed. Size 0x140:
// CEquipModel (0x118) + NiActorManager::CallbackObject at +0x118 (vftable 0x142e... second table), then the
// per-model state below. vfptr slots 0-19 / 22 / 24 / 26 / 28-32 override CEquipModel, slots 33-34 are new.
#pragma once
#include <vector>
#include <NiActorManager.h>
#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <efd/AssetID.h>
#include <efd/Matrix3.h>
#include <efd/utf8string.h>
#include <efd/SmartPointer.h>

#include "ms2/client/ms2/equipmodel.h"

// The per-model configuration record behind CEquipModel::m_unk_20 (ctor arg 3; the equip-model factory owns it).
// Only the members CKfmModel touches are named; sizes of the gaps are the offsets between them.
struct Unk_KfmPonyTail
{
    CString m_strBone;          // +0x00 bone / joint name the pony-tail joint hangs on
    float m_fDamping;           // +0x08 (FUN_141440110)
    float m_fX;                 // +0x0c (FUN_1414401b0)
    float m_fY;                 // +0x10
    float m_fZ;                 // +0x14
};
MS2_CHECK_SIZE(Unk_KfmPonyTail, 0x18);

struct Unk_KfmConfig
{
    char m_pad_00[8];                       // +0x00
    CString m_strNodeSet;                   // +0x08 node-set name (FUN_141422110 key)
    char m_pad_10[0x14];                    // +0x10
    int m_bPhysics;                         // +0x24 pony-tail physics enabled
    char m_pad_28[4];                       // +0x28
    int m_bHead;                            // +0x2c head model (bone-attached nodes)
    char m_pad_30[0x14];                    // +0x30
    float m_fScale;                         // +0x44
    int m_nIndex;                           // +0x48 row index in the pos / rot tables
    char m_pad_4c[0x54];                    // +0x4c
    std::vector<CString> m_arrAnimNames;    // +0xa0 animation names (index -> "0", "1", ... property key)
    Unk_KfmPonyTail m_aPonyTail[4];         // +0xb8
};
MS2_CHECK_OFFSET(Unk_KfmConfig, m_bPhysics, 0x24);
MS2_CHECK_OFFSET(Unk_KfmConfig, m_fScale, 0x44);
MS2_CHECK_OFFSET(Unk_KfmConfig, m_arrAnimNames, 0xa0);
MS2_CHECK_OFFSET(Unk_KfmConfig, m_aPonyTail, 0xb8);

// Pony-tail physics helper owned (intrusively counted) by the model; the model ticks it once per update.
class Unk_KfmPhysics : public NiRefObject
{
public:
    virtual void Update(double fTime);                      // slot 2 (after ~NiRefObject, DeleteThis)
};

class CKfmModel : public CEquipModel, public NiActorManager::CallbackObject
{
public:
    CKfmModel(MS2Ptr<Unk_EquipModelOwner> spOwner, void* p18, void* p20);   // 0x14143d580
    virtual ~CKfmModel();                                                    // 0x14143d680, ??_G 0x141442670

    EE_DECLARE_CLASS1(CKfmModel, 0x0620004a, CEquipModel);   // slots 1-3 (0x141442890/0x141442960/0x1414429b0)

public:
    virtual int vfunc_4(CString strPath);                   // 0x14143d730 load
    virtual void vfunc_5();                                 // 0x14143da90
    virtual int vfunc_6();                                  // 0x14143db00
    virtual int vfunc_7();                                  // 0x14143e090
    virtual int vfunc_8();                                  // 0x14143e190
    virtual int vfunc_9();                                  // 0x14143e1b0
    virtual void vfunc_10();                                // 0x14143e240
    virtual void vfunc_11();                                // 0x14143e3e0
    virtual void vfunc_12();                                // 0x14143e670
    virtual void vfunc_13();                                // 0x14143e900
    virtual void* vfunc_14();                               // 0x14143ee10
    virtual int vfunc_15();                                 // 0x14143ed00
    virtual void vfunc_16();                                // 0x14143ee70
    virtual void vfunc_17();                                // 0x14143eee0
    virtual void vfunc_18();                                // 0x14143f110
    virtual void vfunc_19(double fTime);                    // 0x14143f140
    virtual void vfunc_22(float f);                         // 0x14143f970
    virtual void vfunc_24(const NiPoint3& p);               // 0x14143f9f0
    virtual void vfunc_26(const NiPoint3& p);               // 0x14143fa80
    virtual void vfunc_28(void* pPos, void* pMatrix3, float fScale);   // 0x14143fc70
    virtual void vfunc_29(void* pPos, void* pRotDeg, float fScale);   // 0x14143fb10
    virtual void vfunc_30(void* pPos, void* pRot, float fScale);       // 0x14143fd30
    virtual void vfunc_31();                                // 0x14143fe10
    virtual void vfunc_32(int n);                           // 0x14143f2a0
    virtual int vfunc_33();                                 // 0x14143e0d0
    virtual void vfunc_34();                                // 0x14143e160

    // NiActorManager::CallbackObject (second vftable at +0x118; dtor thunk 0x141442600)
    virtual void AnimActivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x1414406d0
    virtual void AnimDeactivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x1414406f0
    virtual void AnimCompleted(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x141440710
    virtual void TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x141440730
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x1414408c0

    // non-virtual members
    egf::EntityPtr GetEntity();                         // 0x14143ff20 copy of the entity pointer
    egf::EntityID FUN_14143ff70();                          // 0x14143ff70 id of the model entity (0 when none)
    efd::AssetID FUN_14143fff0();                           // 0x14143fff0 asset id property of the entity
    NiActorManager* FUN_1414400d0();                        // 0x1414400d0 actor manager of the entity
    void FUN_141440110(const CString& strBone, float f);    // 0x141440110
    void FUN_1414401b0(const CString& strBone, float x, float y, float z);   // 0x1414401b0
    void FUN_141440270(unsigned int nSeq);                  // 0x141440270
    void FUN_141440380(const CString& strA, const CString& strB, const efd::utf8string& kDefault, float fBlend,
        bool b);                                            // 0x141440380 play first existing animation
    void FUN_1414408e0();                                   // 0x1414408e0 (re)create the entity
    void FUN_1414409f0();                                   // 0x1414409f0 destroy the entity
    void FUN_141440a70();                                   // 0x141440a70 copy animation names into the entity
    void FUN_141440bc0();                                   // 0x141440bc0 pony-tail joint positions
    bool FUN_141440f20();                                   // 0x141440f20 scale is 1.0
    void FUN_141440f60();                                   // 0x141440f60 apply the node scale to the model
    void FUN_14143f3d0();                                   // 0x14143f3d0 rescale the physics joints

public:
    MS2_LAYOUT_FRIEND;
    int m_nUpdateHR;                                // +0x120 (vfunc_10 pending)
    int m_nUpdateTransform;                         // +0x124 (vfunc_11 pending)
    unsigned char m_bPhysicsLoaded;                 // +0x128 set by vfunc_33
    egf::EntityPtr m_spEntity;                      // +0x130
    efd::SmartPointer<Unk_KfmPhysics> m_pPhysics;   // +0x138 intrusive-counted physics helper (FUN_1414423d0 assigns)
};
MS2_CHECK_SIZE(CKfmModel, 0x140);
MS2_CHECK_OFFSET(CKfmModel, m_nUpdateHR, 0x120);
MS2_CHECK_OFFSET(CKfmModel, m_spEntity, 0x130);
MS2_CHECK_OFFSET(CKfmModel, m_pPhysics, 0x138);
