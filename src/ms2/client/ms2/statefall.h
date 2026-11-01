// statefall.h - StateFall (type 5): the actor state of a player in free fall (after leaving a ride or walking off a
// ledge). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\statefall.cpp`
// (0x1417c6e40-0x1417c7be0 .text$mn, dir client\ms2). Header name assumed; member names invented from their use.
// Derives State (ms2/placeholder/state.h); the payload is StateFallData (statedata.h).
#pragma once
#include <efd/utf8string.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include <egf/Entity.h>
#include <afx.h>

// Callees shared with StateFallDamage (unit-local views of unrecovered code).
// The ridee's record string getter: the animation prefix of the fall (a CString built in place).
class Unk_FallRec { public: CString FUN_1411eabd0(); };
CString FUN_14038f6d0(const CString& str, const char* psz);                // 0x14038f6d0 concatenation

// The animation service: resolves an animation name to a sequence id (-2 when the model has none).
class Unk_FallAnimSvc { public: int FUN_140999490(const egf::EntityID& kId, const efd::utf8string& strName);
    void FUN_1409fad80(const egf::EntityID& kId, bool bFlag); };
Unk_FallAnimSvc* FUN_141b6f910();


// 0x60. m_strAnim is the fall animation (owner slot 123 name 5), optionally prefixed by the ridee's record string.
class StateFall : public State
{
public:
    StateFall(PCBase* pOwner);                              // 0x1417c6e40
    virtual ~StateFall();                                   // 0x1417c6eb0 (??_G 0x1417c7a60)
    virtual int vfunc_1();                                  // 1  0x1417c7ab0: 5
    virtual void vfunc_3(double fTime);                     // 3  0x1417c73c0 (air control)
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417c6ef0 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417c7330 (leave)
    virtual void vfunc_8(double fTime);                     // 8  0x1417c7550 (landing on a ridee / climb)
    virtual void vfunc_9(double fTime);                     // 9  0x1417c77e0 (landing)
    virtual int vfunc_15();                                 // 15 0x1417c7aa0: 1
    virtual int vfunc_19();                                 // 19 0x1417c7ac0: 0

    efd::utf8string m_strAnim;                              // +0x40
};
MS2_CHECK_SIZE(StateFall, 0x60);
MS2_CHECK_OFFSET(StateFall, m_strAnim, 0x40);
