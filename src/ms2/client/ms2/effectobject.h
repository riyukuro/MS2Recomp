// effectobject.h - CEffectObject (efd RTTI "CEffectObject", class id 0x06200082): a GameObject that plays a
// Gamebryo animation (kfm) as a skill/prop effect, optionally attached to a PC (the owning player is looked up by
// m_nOwnerId in the WorldService). Owning unit: ?\effectobject.cpp (0x140a53740-0x140a54160). Header name assumed.
// Size 0x148 (operator delete size in the scalar deleting dtor). vftable 0x142dc86f0 (57 slots), CallbackObject
// vftable 0x142dc88c0. efd: TypeCast 0x140a54060/0x140a54010, GetClassDesc 0x140a53f70, ??_G 0x140a53f10,
// ClassInfo 0x143ab73c0 (setup 0x140a53fb0, registration 0x1400c3eb0).
#pragma once
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/nipoint3.h"

class NiControllerSequence;
class NiFixedString;

class CEffectObject : public GameObject
{
    EE_DECLARE_CLASS1(CEffectObject, 0x06200082, GameObject);

public:
    CEffectObject();                                        // 0x140a53740
    virtual ~CEffectObject();                               // 0x140a537a0

    virtual void vfunc_12();                                // 12 0x140a53cf0
    virtual void vfunc_21(efd::Point3 kDir);                // 21 0x140a53b70
    virtual void vfunc_53(float f);                         // 53 0x140a53d30

    // Binds the effect to owner nOwnerId and loads strModel (urn:gamebryo-animation:<name>); the string is by value
    // (the callee destroys it). Always returns 1.
    int Init(int nOwnerId, CString strModel, float fScale);       // 0x140a53880
    // Starts the named sequence on this effect's actor manager and seeks it to the text key's time.
    void FUN_140a539d0(const NiFixedString& kSeqName, float fSpeed, const NiFixedString& kTextKey);  // 0x140a539d0
    void FUN_140a53b30(efd::Point3 kDir);                   // 0x140a53b30 GameObject::vfunc_21 without the owner check

public:
    MS2_LAYOUT_FRIEND;
    int m_nOwnerId;                                         // +0x140 id of the owning actor in the WorldService
    int m_pad_144;                                          // +0x144
};
MS2_CHECK_SIZE(CEffectObject, 0x148);
MS2_CHECK_OFFSET(CEffectObject, m_nOwnerId, 0x140);
