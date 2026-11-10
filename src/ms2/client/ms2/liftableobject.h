// liftableobject.h - CLiftableObject (RTTI .?AVCLiftableObject@@, vftable 0x142f13bd8, 1 slot): the client-side state of a
// world prop the player can pick up and carry (lift cursor, highlight effect, cooldown timer). Derives CPtred only.
// Owning unit: ?\liftableobject.cpp (0x141447080-0x141448190). Header name assumed. Method names are FUN_ addresses.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/commonfiles/portaldata.h"
#include "ms2/client/ms2/cubespawnobject.h"

class CLiftableObject : public CPtred
{
public:
    CLiftableObject();                                          // 0x141447080
    virtual ~CLiftableObject();                                 //  0 0x1414471b0 (??_G 0x141448150)

    CString GetName() const;                              // the name key
    void SetName(CString strName);                        // set the name key
    int CanLift() const;                                  // can be picked up now
    int Init(Unk_Entity* pEntity, bool bFixed, int nKind);   // bind the prop entity
    void BindEntity(Unk_Entity* pEntity);                    // bind and read the entity's properties
    void FUN_1414477f0(CString strA, CString strB);                   // quest-mask check, mask 0
    void FUN_141447850(CString strA, CString strB);                   // quest-mask check, mask 1
    void SetLiftEnabled(bool bValue);                            // set +0xc0
    bool IsLiftEnabled() const;                                 // +0xc0
    void SetEffectEnabled(bool bOn);                               // lift-hint sound on/off
    void SetKind(int nKind);
    int GetKind() const;
    void FUN_141447aa0(bool bValue);
    float GetRange() const;
    int GetState() const;
    void SetState(int nState);                             // set state, collision group
    void FUN_141447c10();                                       // stop the cooldown
    Vector3 GetPosition() const;                      // +0xc4
    int FUN_141447cc0() const;                                  // +0xa8
    Unk_Entity* GetEntity();
    int IsNotFixed() const;                                 // not fixed
    void SetHighlight(int nOn);
    void UpdateConditions();                                       // refresh availability
    void SetActive(bool bActive);                           // highlight on/off
    void FUN_141448050(bool bActive);

    int m_nState;                       // +0x18
    bool m_bFixed;                      // +0x1c
    int m_nKind;                        // +0x20
    QuestMask m_maskA;                  // +0x28
    QuestMask m_maskB;                  // +0x68
    int m_nA8;                          // +0xa8
    CString m_strName;                  // +0xb0
    egf::EntityPtr m_ent;                   // +0xb8
    bool m_bC0;                         // +0xc0
    bool m_bC1;                         // +0xc1
    bool m_bC2;                         // +0xc2
    Vector3 m_vC4;              // +0xc4
    Timer m_timer;                      // +0xd0
    bool m_b108;                        // +0x108
    Vector3 m_v10c;             // +0x10c
    float m_fRange;                     // +0x118
    int m_nEffect;                      // +0x11c
};
MS2_CHECK_SIZE(CLiftableObject, 0x120);
MS2_CHECK_OFFSET(CLiftableObject, m_maskA, 0x28);
MS2_CHECK_OFFSET(CLiftableObject, m_strName, 0xb0);
MS2_CHECK_OFFSET(CLiftableObject, m_ent, 0xb8);
MS2_CHECK_OFFSET(CLiftableObject, m_bC0, 0xc0);
MS2_CHECK_OFFSET(CLiftableObject, m_vC4, 0xc4);
MS2_CHECK_OFFSET(CLiftableObject, m_timer, 0xd0);
MS2_CHECK_OFFSET(CLiftableObject, m_v10c, 0x10c);
MS2_CHECK_OFFSET(CLiftableObject, m_nEffect, 0x11c);
