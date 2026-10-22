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
    int FUN_141447340() const;                                  // can be picked up now
    int FUN_141447390(Unk_Entity* pEntity, bool bFixed, int nKind);   // bind the prop entity
    void FUN_141447410(Unk_Entity* pEntity);                    // bind and read the entity's properties
    void FUN_1414477f0(CString strA, CString strB, void* pArg);     // quest-mask check, mask 0
    void FUN_141447850(CString strA, CString strB, void* pArg);     // quest-mask check, mask 1
    void FUN_1414478b0(char bValue);                            // set +0xc0
    char FUN_1414478f0() const;                                 // +0xc0
    void FUN_141447910(char bOn);                               // lift-hint sound on/off
    void SetKind(int nKind);
    int GetKind() const;
    void FUN_141447aa0(char bValue);
    float GetRange() const;
    int GetState() const;
    void FUN_141447b00(int nState);                             // set state, collision group
    void FUN_141447c10();                                       // stop the cooldown
    Unk_StreamPoint FUN_141447c80() const;                      // +0xc4
    int FUN_141447cc0() const;                                  // +0xa8
    void FUN_141447ce0();
    bool FUN_141447d10() const;                                 // not fixed
    void FUN_141447d50(int nOn);
    void FUN_141447de0();                                       // refresh availability
    void FUN_141447ec0(char bActive);                           // highlight on/off
    void FUN_141448050(char bActive);

    int m_nState;                       // +0x18
    char m_bFixed;                      // +0x1c
    int m_nKind;                        // +0x20
    QuestMask m_maskA;                  // +0x28
    QuestMask m_maskB;                  // +0x68
    int m_nA8;                          // +0xa8
    CString m_strName;                  // +0xb0
    Unk_EntRef m_ent;                   // +0xb8
    char m_bC0;                         // +0xc0
    char m_bC1;                         // +0xc1
    char m_bC2;                         // +0xc2
    Unk_StreamPoint m_vC4;              // +0xc4
    Timer m_timer;                      // +0xd0
    char m_b108;                        // +0x108
    Unk_StreamPoint m_v10c;             // +0x10c
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
