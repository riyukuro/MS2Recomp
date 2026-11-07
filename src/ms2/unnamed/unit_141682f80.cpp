// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The player's movement controller (PCBase +0x6d8, see
// actionkeyobject.cpp): the move-key state tracker (which arrow/dash keys are down, which buffs block them) and the
// knock-back / forced-move direction it derives. Unit and member names are invented from use.
// MS2-UNIT: unit_141682f80
// MS2-RANGE: 0x141682f80-0x1416841a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/os.h"

// return types of the getters this unit calls
class CGameOption;
class CMouseController;
class CameraMgr;
class MS2InputService;
class Unk_140166410;
class Unk_Restrictions;
class Unk_SoundSink;
struct Unk_PmFixedItem;

// The shared Vector3 placeholder (was a local copy of it). Its declared (never called) default constructor keeps /GS from
// treating the locals as buffers, and the by-value FUN_140d8c2f0 result is built in place.
#include "ms2/placeholder/nipoint3.h"
//
//
//
//

// The controlled actor (PCBase); only the virtuals this unit calls matter.
class Unk_PCActor
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual int GetKind();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual int FUN_slot_1f8();
};

class Unk_PCTimer;      // the 0x38-byte key repeat timer at +8
class Unk_PCBuffTable;  // FUN_1409331e0 / FUN_1409331f0 singletons (buff block / buff lookup tables)
// the mouse click-to-move state; GetMove returns its direction by value
class CMouseController   // C3: member view for the former free stand-ins
{
public:
    void FUN_140ad2070();
    int FUN_140ad21f0();
    Vector3 GetMove();
};
class Unk_PCServices;
// the class's own unit defines s_instance / GetInstance out of line (explicit specializations): only declared here, so
// this obj does not instantiate a second copy (LNK2005 in the full-exe link)
template<> class TSingleton<CameraMgr> { public: static CameraMgr* s_instance; static CameraMgr* GetInstance(); };

// The movement controller (0x58).
class Unk_PCMove
{
public:
    bool FUN_141682f80(int nKey);
    bool FUN_141682fe0(int nKey);
    bool FUN_1416830b0(int nKey);
    bool FUN_141683100(int nKey);
    bool FUN_141683150(int nKey);
    bool FUN_141683200(int nKey);
    Vector3 FUN_141683290();
    Vector3 FUN_1416836d0();
    Vector3 FUN_141683900();
    bool FUN_1416839b0();
    void FUN_141683a90();
    bool FUN_141683ef0();
    int FUN_141684060(int nKey);
    bool FUN_1416840c0(int nKey);
    bool FUN_141684170(int nKey);

    Unk_PCActor* m_pOwner;                  // +0x00
    char m_timer[0x38];                     // +0x08
    Vector3 m_dir;                  // +0x40
    int m_moving;                           // +0x4c
    int m_ready;                            // +0x50
    int m_pad54;
};
MS2_CHECK_OFFSET(Unk_PCMove, m_dir, 0x40);
MS2_CHECK_OFFSET(Unk_PCMove, m_moving, 0x4c);
MS2_CHECK_OFFSET(Unk_PCMove, m_ready, 0x50);

extern int DAT_143af7d40;                   // input enabled
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60

// Out-of-unit callees.
void* FUN_14025e7c0();
class CInputKeyHandler   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14116dbf0(int*, int*, int*, bool, int);
    bool FUN_14116d7a0(unsigned nMask);
};
class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
class Unk_SoundSink* FUN_1409331f0();   // C3: was FUN_1409331f0
class CGuideManager   // C3: member view for the former free stand-ins
{
public:
    int IsRestricted(int);
};
int FUN_14138c930(Unk_PCBuffTable* p, int n);
class CKeyTable   // C3: member view for the former free stand-ins
{
public:
    int IsActionKeyDown(int);
    int IsActionKeyPressed(int);
    int IsActionKeyReleased(int);
    int FUN_14142c940(__int64 nAction, int nPriority);
    __int64 GetKeyAction(int nKey);                 // 0x14142d190
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void ResetIdleTimer();
    void* FUN_141bd0cc0();
    int FUN_141bdb5e0();
    static class WorldService* GetInstance();
};
class MS2InputService* FUN_140a58540();   // C3: was FUN_140a58540
class MS2InputService   // C3: member view for the former free stand-ins
{
public:
    bool IsKeyDownGated(int, int);
    bool WasKeyPressedGated(int);
    bool WasKeyReleasedGated(int);
    bool FUN_140d8c550();
    Vector3 GetLeftStickMoveDir();
};
struct Unk_GpState* FUN_140a58500(class Unk_GpSettings*);   // C3: was FUN_140a58500
int FUN_140a58520(void* p);
struct Unk_MagicRidee* FUN_141468360(struct Unk_MagicEntity*);   // C3: was FUN_141468360
class Ridee   // C3: member view for the former free stand-ins
{
public:
    class PCBase* GetRider();
};
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/additionalclilist.h"   // C3: AdditionalCliList (the local member view is gone)
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CFeatureManager   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14036d570(int);
};
struct Unk_PmFixedItem* FUN_140c8dac0();   // C3: was FUN_140c8dac0
class CInstrumentManager   // C3: member view for the former free stand-ins
{
public:
    bool IsEnsemble();
};
class PC { public: int FUN_1416596d0(); };   // C3: member view
class CameraMgr   // C3: member view for the former free stand-ins
{
public:
    bool FUN_140aed3e0();
};

// @0x141682f80
bool Unk_PCMove::FUN_141682f80(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!FUN_141684170(nKey))
        return false;
    return ((class MS2InputService*)(void*)(((void*)FUN_140a58540())))->IsKeyDownGated(nKey, 0);
}

// @0x141682fe0
bool Unk_PCMove::FUN_141682fe0(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    int nX;
    int nY;
    int nZ;
    if (((class CInputKeyHandler*)(class Unk_PCServices*)(reinterpret_cast<Unk_PCServices*>(FUN_14025e7c0())))->FUN_14116dbf0(&nX, &nY, &nZ, false, 0)) {
        if (nKey == 0x493e8 && 0 < nZ)
            return true;
        else if (nKey == 0x493e9 && nZ < 0)
            return true;
    }
    if (!FUN_1416840c0(nKey))
        return false;
    if (((class CKeyTable*)(class Unk_PCBuffTable*)(reinterpret_cast<Unk_PCBuffTable*>(((class Unk_PCBuffTable*)FUN_1409331f0()))))->IsActionKeyDown(nKey) != 0) {
        if (((void*)WorldService::GetInstance()) != 0)
            ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->ResetIdleTimer();
        return true;
    }
    return false;
}

// @0x1416830b0
bool Unk_PCMove::FUN_1416830b0(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!FUN_141684170(nKey))
        return false;
    return ((class MS2InputService*)(void*)(((void*)FUN_140a58540())))->WasKeyPressedGated(nKey);
}

// @0x141683100
bool Unk_PCMove::FUN_141683100(int nKey)
{
    if (!FUN_1416840c0(nKey))
        return false;
    if (((class CKeyTable*)(class Unk_PCBuffTable*)(reinterpret_cast<Unk_PCBuffTable*>(((class Unk_PCBuffTable*)FUN_1409331f0()))))->IsActionKeyPressed(nKey) != 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x141683100, Unk_PCMove, FUN_141683100, 70, 0x1110430A);

// @0x141683150
bool Unk_PCMove::FUN_141683150(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!FUN_141683ef0())
        return true;
    if (FUN_14138c930(reinterpret_cast<Unk_PCBuffTable*>(((class Unk_PCBuffTable*)FUN_1409331e0())), FUN_141684060(nKey)) != 0)
        return false;
    if (FUN_141684060(nKey) == 0x493e1) {
        if (((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bdb5e0() != 0)
            return false;
    }
    return ((class MS2InputService*)(void*)(((void*)FUN_140a58540())))->WasKeyReleasedGated(nKey);
}

// @0x141683200
bool Unk_PCMove::FUN_141683200(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!FUN_141683ef0())
        return true;
    if (FUN_14138c930(reinterpret_cast<Unk_PCBuffTable*>(((class Unk_PCBuffTable*)FUN_1409331e0())), nKey) != 0)
        return false;
    if (nKey == 0x493e1) {
        if (((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bdb5e0() != 0)
            return false;
    }
    if (((class CKeyTable*)(class Unk_PCBuffTable*)(reinterpret_cast<Unk_PCBuffTable*>(((class Unk_PCBuffTable*)FUN_1409331f0()))))->IsActionKeyReleased(nKey) != 0)
        return true;
    return false;
}

// @0x141683290
Vector3 Unk_PCMove::FUN_141683290()
{
    Vector3 kDir = DAT_143b01a60;
    if (((class CGuideManager*)(class Unk_PCBuffTable*)(reinterpret_cast<Unk_PCBuffTable*>(((class Unk_PCBuffTable*)FUN_1409331e0()))))->IsRestricted(0x15) != 0 || ((class CGuideManager*)(class Unk_PCBuffTable*)(reinterpret_cast<Unk_PCBuffTable*>(((class Unk_PCBuffTable*)FUN_1409331e0()))))->IsRestricted(0x14) != 0) {
        return kDir;
    }
    if (FUN_141682fe0(0x30d43)) {
        kDir.x = 1.0f;
    } else if (FUN_141682fe0(0x30d44)) {
        kDir.x = -1.0f;
    }
    if (FUN_141682fe0(0x30d41)) {
        kDir.y = 1.0f;
    } else if (FUN_141682fe0(0x30d42)) {
        kDir.y = -1.0f;
    }
    if (FUN_141682fe0(0x30d45)) {
        kDir.x = 1.0f;
        kDir.y = 1.0f;
    } else if (FUN_141682fe0(0x30d46)) {
        kDir.x = -1.0f;
        kDir.y = 1.0f;
    } else if (FUN_141682fe0(0x30d47)) {
        kDir.x = 1.0f;
        kDir.y = -1.0f;
    } else if (FUN_141682fe0(0x30d48)) {
        kDir.x = -1.0f;
        kDir.y = -1.0f;
    }
    int bFlipped = 0;
    if (m_pOwner != 0) {
        Unk_PCActor* pActor = m_pOwner;
        Unk_PCActor* pBase = ((class Unk_PCActor*)FUN_141468360((struct Unk_MagicEntity*)(m_pOwner)));
        if (pBase != 0)
            pActor = ((class Unk_PCActor*)((class Ridee*)(class Unk_PCActor*)(pBase))->GetRider());
        if (pActor != 0) {
            if (reinterpret_cast<AdditionalCliList*>(reinterpret_cast<PCBase*>(pActor)->FUN_1416749a0())->FUN_140970a40() != 0)
                bFlipped = 1;
        }
    }
    if (TSingleton<CMouseController>::GetInstance() != 0) {
        if (TSingleton<CMouseController>::GetInstance()->FUN_140ad21f0() != 0) {
            if (reinterpret_cast<const efd::Point3&>(kDir) == reinterpret_cast<const efd::Point3&>(DAT_143b01a60))
                *reinterpret_cast<efd::Point3*>(&kDir) = *reinterpret_cast<const efd::Point3*>(&static_cast<const Vector3&>(TSingleton<CMouseController>::GetInstance()->GetMove()));
        } else {
            TSingleton<CMouseController>::GetInstance()->FUN_140ad2070();
        }
    }
    if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0xb5)) {
        if (*static_cast<bool*>(((void*)FUN_140a58500((class Unk_GpSettings*)(TSingleton<CGameOption>::GetInstance())))) != 0) {
            if (!FUN_141683ef0()) {
                return DAT_143b01a60;
            }
            if (!((class MS2InputService*)(void*)(((void*)FUN_140a58540())))->FUN_140d8c550()) {
                return DAT_143b01a60;
            }
            if (FUN_140a58520(((void*)FUN_140a58540())) != 0) {
                if (FUN_1416839b0()) {
                    return DAT_143b01a60;
                }
            } else {
                Vector3 kCur = FUN_140a58540()->GetLeftStickMoveDir();
                if (reinterpret_cast<const efd::Point3&>(kCur) != reinterpret_cast<const efd::Point3&>(DAT_143b01a60))
                    *reinterpret_cast<efd::Point3*>(&kDir) = *reinterpret_cast<const efd::Point3*>(&static_cast<const Vector3&>(kCur));
            }
        }
    }
    if (bFlipped)
        reinterpret_cast<efd::Point3&>(kDir) *= -1.0f;
    return kDir;
}

// @0x1416836d0
Vector3 Unk_PCMove::FUN_1416836d0()
{
    Vector3 kDir = DAT_143b01a60;
    if (FUN_141683100(0x30d43)) {
        kDir.x = 1.0f;
    } else if (FUN_141683100(0x30d44)) {
        kDir.x = -1.0f;
    }
    if (FUN_141683100(0x30d41)) {
        kDir.y = 1.0f;
    } else if (FUN_141683100(0x30d42)) {
        kDir.y = -1.0f;
    }
    if (FUN_141683100(0x30d45)) {
        kDir.x = 1.0f;
        kDir.y = 1.0f;
    } else if (FUN_141683100(0x30d46)) {
        kDir.x = -1.0f;
        kDir.y = 1.0f;
    } else if (FUN_141683100(0x30d47)) {
        kDir.x = 1.0f;
        kDir.y = -1.0f;
    } else if (FUN_141683100(0x30d48)) {
        kDir.x = -1.0f;
        kDir.y = -1.0f;
    }
    if (m_pOwner != 0) {
        Unk_PCActor* pActor = m_pOwner;
        Unk_PCActor* pBase = ((class Unk_PCActor*)FUN_141468360((struct Unk_MagicEntity*)(m_pOwner)));
        if (pBase != 0)
            pActor = ((class Unk_PCActor*)((class Ridee*)(class Unk_PCActor*)(pBase))->GetRider());
        if (pActor != 0) {
            if (reinterpret_cast<AdditionalCliList*>(reinterpret_cast<PCBase*>(pActor)->FUN_1416749a0())->FUN_140970a40() != 0)
                reinterpret_cast<efd::Point3&>(kDir) *= -1.0f;
        }
    }
    return kDir;
}

// @0x141683900
Vector3 Unk_PCMove::FUN_141683900()
{
    if (!FUN_141683ef0()) {
        return DAT_143b01a60;
    }
    if (!FUN_1416839b0() && (m_moving != 0 || reinterpret_cast<Timer*>(m_timer)->FUN_140868ba0() != 0)) {
        return m_dir;
    } else {
        return FUN_141683290();
    }
}

// @0x1416839b0
bool Unk_PCMove::FUN_1416839b0()
{
    if (FUN_141682f80(reinterpret_cast<CKeyTable*>(FUN_1409331f0())->FUN_14142c940(0x30d41, 2)))
        return true;
    if (FUN_141682f80(reinterpret_cast<CKeyTable*>(FUN_1409331f0())->FUN_14142c940(0x30d42, 2)))
        return true;
    if (FUN_141682f80(reinterpret_cast<CKeyTable*>(FUN_1409331f0())->FUN_14142c940(0x30d43, 2)))
        return true;
    if (FUN_141682f80(reinterpret_cast<CKeyTable*>(FUN_1409331f0())->FUN_14142c940(0x30d44, 2)))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1416839B0, Unk_PCMove, FUN_1416839b0, 207, 0x4ABC09D2);

// @0x141683a90
void Unk_PCMove::FUN_141683a90()
{
    int nDelay = 0x32;
    m_moving = 0;
    if ((FUN_141683200(0x30d43) && FUN_141682fe0(0x30d41)) || (FUN_141683200(0x30d41) && FUN_141682fe0(0x30d43))) {
        m_dir.x = 1.0f;
        m_dir.y = 1.0f;
        reinterpret_cast<Timer*>(m_timer)->FUN_140868750(nDelay);
    } else if ((FUN_141683200(0x30d43) && FUN_141682fe0(0x30d42)) || (FUN_141683200(0x30d42) && FUN_141682fe0(0x30d43))) {
        m_dir.x = 1.0f;
        m_dir.y = -1.0f;
        reinterpret_cast<Timer*>(m_timer)->FUN_140868750(nDelay);
    } else if ((FUN_141683200(0x30d44) && FUN_141682fe0(0x30d41)) || (FUN_141683200(0x30d41) && FUN_141682fe0(0x30d44))) {
        m_dir.x = -1.0f;
        m_dir.y = 1.0f;
        reinterpret_cast<Timer*>(m_timer)->FUN_140868750(nDelay);
    } else if ((FUN_141683200(0x30d44) && FUN_141682fe0(0x30d42)) || (FUN_141683200(0x30d42) && FUN_141682fe0(0x30d44))) {
        m_dir.x = -1.0f;
        m_dir.y = -1.0f;
        reinterpret_cast<Timer*>(m_timer)->FUN_140868750(nDelay);
    } else if ((FUN_141683200(0x30d43) || FUN_141683200(0x30d44) || FUN_141683200(0x30d41) || FUN_141683200(0x30d42)) && reinterpret_cast<Timer*>(m_timer)->FUN_140868ba0() != 0) {
        reinterpret_cast<Timer*>(m_timer)->FUN_1408687f0();
        m_moving = 1;
    } else if ((FUN_141683200(0x30d43) || FUN_141683200(0x30d44)) && (FUN_141683200(0x30d41) || FUN_141683200(0x30d42))) {
        reinterpret_cast<Timer*>(m_timer)->FUN_1408687f0();
    } else if (FUN_141683100(0x30d43) || FUN_141683100(0x30d44) || FUN_141683100(0x30d41) || FUN_141683100(0x30d42)) {
        reinterpret_cast<Timer*>(m_timer)->FUN_1408687f0();
    }
    if (m_pOwner != 0) {
        Unk_PCActor* pActor = m_pOwner;
        Unk_PCActor* pBase = ((class Unk_PCActor*)FUN_141468360((struct Unk_MagicEntity*)(m_pOwner)));
        if (pBase != 0)
            pActor = ((class Unk_PCActor*)((class Ridee*)(class Unk_PCActor*)(pBase))->GetRider());
        if (pActor != 0) {
            if (reinterpret_cast<AdditionalCliList*>(reinterpret_cast<PCBase*>(pActor)->FUN_1416749a0())->FUN_140970a40() != 0)
                reinterpret_cast<efd::Point3&>(m_dir) *= -1.0f;
        }
    }
}

// @0x141683ef0
bool Unk_PCMove::FUN_141683ef0()
{
    if (m_pOwner == 0)
        return false;
    Unk_PCActor* pSelf = ((class Unk_PCActor*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (m_pOwner->GetKind() != 0x6200045 && pSelf != m_pOwner && reinterpret_cast<PCBase*>(m_pOwner)->FUN_141671b20() == 0
        && m_pOwner->GetKind() != 0x6200064 && m_pOwner->GetKind() != 0x6200081)
        return false;
    if (reinterpret_cast<PCBase*>(pSelf)->IsDead() != 0)
        return false;
    if (reinterpret_cast<CInputKeyHandler*>(FUN_14025e7c0())->FUN_14116d7a0(0xf))
        return false;
    if (m_pOwner->FUN_slot_1f8() == 0)
        return false;
    if (m_ready == 0) {
        if (reinterpret_cast<AdditionalCliList*>(reinterpret_cast<PCBase*>(m_pOwner)->FUN_1416749a0())->FUN_1409709b0() != 0)
            return false;
    }
    if (pSelf == m_pOwner && reinterpret_cast<PC*>(pSelf)->FUN_1416596d0() != 0)
        return false;
    if (!((class CameraMgr*)(void*)(TSingleton<CameraMgr>::GetInstance()))->FUN_140aed3e0())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x141683EF0, Unk_PCMove, FUN_141683ef0, 361, 0xC6E837A1);

// @0x141684060
int Unk_PCMove::FUN_141684060(int nKey)
{
    __int64 nAction = reinterpret_cast<CKeyTable*>(FUN_1409331f0())->GetKeyAction(nKey);
    return (int)nAction;
}
MS2_REPLACE_METHOD(0x141684060, Unk_PCMove, FUN_141684060, 44, 0x77C6DB8A);

// @0x1416840c0
bool Unk_PCMove::FUN_1416840c0(int nKey)
{
    if (!FUN_141683ef0() && nKey != 0x493e8 && nKey != 0x493e9)
        return false;
    if (FUN_14138c930(reinterpret_cast<Unk_PCBuffTable*>(((class Unk_PCBuffTable*)FUN_1409331e0())), nKey) != 0)
        return false;
    if (nKey == 0x493e8 || nKey == 0x493e9) {
        if (((class CInstrumentManager*)(void*)(((void*)FUN_140c8dac0())))->IsEnsemble())
            return false;
    }
    if (nKey == 0x493e1) {
        if (((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bdb5e0() != 0)
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416840C0, Unk_PCMove, FUN_1416840c0, 161, 0x5769705B);

// @0x141684170
bool Unk_PCMove::FUN_141684170(int nKey)
{
    return FUN_1416840c0(FUN_141684060(nKey));
}
MS2_REPLACE_METHOD(0x141684170, Unk_PCMove, FUN_141684170, 44, 0x56BEA03B);

// The preceding constructors and header statics belong to this controller TU.
// MS2-RANGE: 0x141682e90-0x141682f80 .text$mn
// MS2-RANGE: 0x1400fb790-0x1400fb920 .text$di
#include "ms2/placeholder/unk_1402a9d70.h"

static CString s_moveSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_moveSkill("skill");
static CString s_moveStun("stun");
static Unk_1402a9d70 s_moveCondition(17, .75f, .25f, 2.25f, 10);

// @0x141682e90
Unk_PCBaseBuffTracker::Unk_PCBaseBuffTracker()
{
    m_p00 = 0;
    m_n50 = 0;
    m_pos40 = *reinterpret_cast<const efd::Point3*>(&DAT_143b01a60);
}

// @0x141682f30
Unk_PCBaseBuffTracker::~Unk_PCBaseBuffTracker()
{
}

// @0x141682f60
void FUN_141682f60(void* tracker, PCBase* owner)
{
    static_cast<Unk_PCMove*>(tracker)->m_pOwner = reinterpret_cast<Unk_PCActor*>(owner);
}

// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400fb8b0
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb40e0-0x142cb4170 .text$yd
