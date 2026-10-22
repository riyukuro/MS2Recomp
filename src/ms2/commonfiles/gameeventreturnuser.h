// GameEventReturnUser (RTTI .?AVGameEventReturnUser@@, registered by name "GameEventReturnUser"; 0xf0 bytes), the
// returning-user event: it carries the mentoring context (the mentor / mentee setup) that the lobby hands to the
// game rule at start. Header name assumed from the unit path.
#pragma once
#include "gameevent.h"
#include "gameeventcontext.h"

class Unk_RuAux;

class GameEventReturnUser : public GameEvent {
public:
    GameEventReturnUser();                      // 0x14041cc00
    virtual CStringW vfunc_1();                 // 0x14041cbb0
    virtual void vfunc_2();                     // 0x14041ccf0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x14041cd00
    virtual void vfunc_4(Unk_GEIn* in);         // 0x14041cd50
    virtual void OnStart();                     // 0x14041cda0
    virtual void vfunc_6();                     // 0x14041ce30
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_RuAux> m_d0;                     // +0xd0 (never filled in this unit)
    MS2Ptr<MentoringContext> m_e0;              // +0xe0
};
MS2_CHECK_SIZE(GameEventReturnUser, 0xf0);
