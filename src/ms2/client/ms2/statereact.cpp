// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateReact / StateReactData: the actor state of a player
// reacting to another actor (animation at the target, casting bar for type 0x9f) and its payload. See statereact.h.
// MS2-UNIT: client\ms2\statereact.cpp
// MS2-RANGE: 0x140b8d3e0-0x140b8e760 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statereact.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <float.h>
#include <errno.h>
#include <string.h>
#include <efd/utf8string.h>

#include "statereact.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/reactordata.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

extern Vector3 DAT_143b01a60;                    // the zero point

class Unk_StateDataArg                                   // the state-sync record (slots 1/2 of StateData)
{
public:
    char m_pad_00[0x64];
    int m_n64;                                           // +0x64 the reaction id
    char m_pad_68[0x70 - 0x68];
    CString m_str70;                                     // +0x70 the animation name
    char m_pad_78[0xb8 - 0x78];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_n64, 0x64);
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);

// An actor looked up by its name (8 bytes: the counted pointer).
class Unk_ReactRef
{
public:
    Unk_ReactRef(const Unk_ReactRef& o);                 // 0x140963d50
    ~Unk_ReactRef();                                     // 0x140964830
    PCBase* FUN_140965770() const;                       // the actor, 0 when gone
    PCBase* FUN_1409658b0() const;                       // the actor
    bool operator==(int n) const;                        // 0x1409651c0
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_ReactRef, 8);

class Unk_ReactWorld { public: Unk_ReactRef FUN_141bc6eb0(const CString& strName); };

// The time-limited behaviour table row of an actor (+0x5c the reach).
class Unk_ReactRestart : public CPtred
{
public:
    char m_pad_18[0x5c - 0x18];
    float m_fReach;                                      // +0x5c
};
// An actor seen through its restart-table pointer (+0x160).
class Unk_ReactActor : public PCBase
{
public:
    MS2Ptr<Unk_ReactRestart> FUN_140966e50();            // copy of the pointer at +0x160
};

// The casting bar request (see statenurturing.cpp): duration, flags, speed and four texts.
struct Unk_CastInfo
{
    Unk_CastInfo();                                      // 0x140ac2eb0
    ~Unk_CastInfo();                                     // 0x140ac3070
    int m_nDuration;                                     // +0x00
    bool m_b4;                                           // +0x04
    bool m_b5;                                           // +0x05
    float m_f8;                                          // +0x08
    float m_fC;                                          // +0x0c
    int m_n10;                                           // +0x10
    CStringW m_str18;                                    // +0x18
    CStringW m_str20;                                    // +0x20
    CStringW m_str28;                                    // +0x28
    CStringW m_str30;                                    // +0x30
};
MS2_CHECK_SIZE(Unk_CastInfo, 0x38);

class UICastingBar : public UIObject
{
public:
    void FUN_1418e12b0(ICastingEventListener* pListener, Unk_CastInfo& kInfo);   // show
    void FUN_1418e1390();                                                        // cancel
};
UICastingBar* FUN_140ac2270(int nId);
class Unk_ReactBuffMgr { public: Vector3 FUN_141683290(); };
// PCBase vtable view: slots 22 and 68 take the point by value (the exe copies it to a 16-aligned temp)
class Unk_ReactSlots
{
public:
#define MS2_SR_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_SR_SLOTS(0, 1, 2, 3, 4) MS2_SR_SLOTS(5, 6, 7, 8, 9) MS2_SR_SLOTS(10, 11, 12, 13, 14) MS2_SR_SLOTS(15, 16, 17, 18, 19)
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kPos);                                // 22 0x14123c3a0
    virtual void vfunc_23(); virtual void vfunc_24();
    MS2_SR_SLOTS(25, 26, 27, 28, 29) MS2_SR_SLOTS(30, 31, 32, 33, 34) MS2_SR_SLOTS(35, 36, 37, 38, 39)
    MS2_SR_SLOTS(40, 41, 42, 43, 44) MS2_SR_SLOTS(45, 46, 47, 48, 49) MS2_SR_SLOTS(50, 51, 52, 53, 54)
    MS2_SR_SLOTS(55, 56, 57, 58, 59) MS2_SR_SLOTS(60, 61, 62, 63, 64)
#undef MS2_SR_SLOTS
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
    virtual bool vfunc_68(efd::Point3 kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
};
CString FUN_1409a2360(const char* psz, int nCodePage);          // 0x1409a2360
void FUN_140b78d90(PCBase* pActor, Unk_CastInfo* pInfo);           // fill the casting request from the actor
void FUN_140b799a0(PCBase* pActor);                                // the actor reacts
class Unk_ReactClips : public CPtred                                             // the animation table row of a reaction
{
public:
    CString FUN_14076b060();                                       // the 0x9e animation
    CString FUN_14076b110();                                       // the 0x9f animation
};
class Unk_ReactTable { public: MS2Ptr<Unk_ReactClips> FUN_14076bbd0(int nId); };

// ---- StateReactData ----

// @0x140b8d3e0
StateReactData::StateReactData(int nId, CString strTarget, CString strAnim) : m_nId(nId), m_strTarget(strTarget), m_strAnim(strAnim)
{
}

// @0x140b8d480
StateReactData::~StateReactData()
{
}

// @0x140b8d4e0
void StateReactData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_n64 = m_nId;
    p->m_str70 = m_strAnim;
}

// @0x140b8d540
void StateReactData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nId = p->m_n64;
    m_strAnim = p->m_str70;
}

// ---- StateReact ----

// @0x140b8d5a0
StateReact::StateReact(PCBase* pOwner) : State(pOwner), m_n48(0)
{
}

// @0x140b8d630
StateReact::~StateReact()
{
}

// @0x140b8d680
void StateReact::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n48 = 0;
    m_spData.AssignRaw(dynamic_cast<StateReactData*>(pData));
    if (m_spData == 0)
    {
        MS2_ASSERT_AT(0x3d, 0);
        return;
    }
    if (FUN_140b8e030())
    {
        switch (m_n10)
        {
            break;
        case 0x9f:
            {
                MyPC* pRider = FUN_1417b84b0();
                if (pRider == 0)
                    return;
                if (((void*)(reinterpret_cast<PC*>(pRider)->FUN_14165f100())) != 0)
                    reinterpret_cast<PC*>(pRider)->SendRequestCube();
                Unk_CastInfo kInfo;
                Unk_ReactRef kRef = reinterpret_cast<Unk_ReactWorld*>(WorldService::GetInstance())->FUN_141bc6eb0(m_spData->m_strTarget);
                if (kRef == 0)
                {
                    m_pOwner->vfunc_59(1, 0, 0, 0);
                    return;
                }
                FUN_140b78d90(kRef.FUN_1409658b0(), &kInfo);
                UICastingBar* pBar = FUN_140ac2270(0x4e72);
                if (pBar == 0)
                    return;
                pBar->FUN_1418e12b0(this, kInfo);
            }
        }
    }
}

// @0x140b8d900
void StateReact::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    reinterpret_cast<Unk_ReactSlots*>(m_pOwner)->vfunc_68(reinterpret_cast<const efd::Point3&>(DAT_143b01a60), fTime, 0, 0, 0);
    if (FUN_1417b8560() == 0)
        return;
    switch (m_n10)
    {
        break;
    case 0x9f:
        FUN_140b8ded0();
        break;
    default:
        break;
    }
}

// @0x140b8d9c0
void StateReact::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (FUN_1417b8560() == 0)
        return;
    switch (m_n10)
    {
        break;
    case 0x9f:
        {
            UICastingBar* pBar = FUN_140ac2270(0x4e72);
            if (pBar == 0)
                return;
            pBar->FUN_1418e1390();
        }
        break;
    default:
        break;
    }
}

// @0x140b8da40
void StateReact::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
        return;
    if ((StateReactData*)m_spData != 0)
    {
        Unk_ReactRef kRef = reinterpret_cast<Unk_ReactWorld*>(WorldService::GetInstance())->FUN_141bc6eb0(m_spData->m_strTarget);
        if (kRef.FUN_140965770() != 0)
        {
            if (m_n48 != 0)
            {
                FUN_140b8dfd0(kRef);
            }
            else
            {
                float fReach = static_cast<Unk_ReactActor*>(kRef.FUN_1409658b0())->FUN_140966e50().get() != 0 ? static_cast<Unk_ReactActor*>(kRef.FUN_1409658b0())->FUN_140966e50()->m_fReach : 0.0f;
                PCBase* pTarget = kRef.FUN_1409658b0();
                if (reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pTarget->vfunc_18())).FUN_140965c40(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pRider->vfunc_18()))).FUN_140967ac0() > fReach)
                {
                    pRider->vfunc_59(1, 0, 0, 0);
                    return;
                }
            }
        }
        if (m_n48 != 0)
        {
            pRider->vfunc_59(1, 0, 0, 0);
            return;
        }
    }
    Unk_ReactBuffMgr* pMgr = ((Unk_ReactBuffMgr*)(reinterpret_cast<PCBase*>(pRider)->FUN_14166d240()));
    reinterpret_cast<Unk_ReactSlots*>(pRider)->vfunc_22(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pMgr->FUN_141683290())));
    if (reinterpret_cast<PCBase*>(m_pOwner)->FUN_1416749c0() != 0)
        pRider->vfunc_59(2, 0, 0, 0);
    else
        FUN_1417b9460();
}

// @0x140b8dde0
void StateReact::vfunc_6()
{
    if (FUN_1417b8560() != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x140b8de30
void StateReact::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq, float fEventTime)
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
        return;
    switch (m_n10)
    {
    case 0x9e:
        pRider->vfunc_59(1, 0, 0, 0);
        break;
    }
}

// @0x140b8deb0
bool StateReact::vfunc_25(int n, void* p)
{
    return false;
}

// @0x140b8ded0
void StateReact::FUN_140b8ded0()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
        return;
    if (!m_spData)
        return;
    Unk_ReactWorld* pWorld = reinterpret_cast<Unk_ReactWorld*>(WorldService::GetInstance());
    if (pWorld == 0)
        return;
    Unk_ReactRef kRef = pWorld->FUN_141bc6eb0(m_spData->m_strTarget);
    if (kRef.FUN_140965770() == 0)
    {
        pRider->vfunc_59(1, 0, 0, 0);
        return;
    }
}

// @0x140b8dfb0
void StateReact::OnCastingFinished()
{
    m_n48 = 1;
}

// @0x140b8dfd0
void StateReact::FUN_140b8dfd0(Unk_ReactRef kRef)
{
    switch (m_n10)
    {
        break;
    case 0x9f:
        FUN_140b799a0(kRef.FUN_1409658b0());
        break;
    }
}

// @0x140b8e030
bool StateReact::FUN_140b8e030()
{
    if (m_spData == 0)
        return false;
    MS2Ptr<Unk_ReactClips> spClips = reinterpret_cast<Unk_ReactTable*>(TSingleton<CReactorDataTable>::GetInstance())->FUN_14076bbd0(m_spData->m_nId);
    if (spClips.IsNull())
    {
        MS2_ASSERT_AT(0x6e, 0);
        return false;
    }
    efd::utf8string kName("");
    if (m_spData->m_strAnim.GetLength() > 0)
    {
        kName = (const char*)FUN_1409a2360(m_spData->m_strAnim, 0);
        m_pOwner->FUN_14166dd20(kName, 1.0f, false, false);
    }
    else
    {
        CString strAnim("");
        switch (m_n10)
        {
        case 0x9e:
            strAnim = spClips->FUN_14076b060();
            break;
        case 0x9f:
            strAnim = spClips->FUN_14076b110();
            break;
        }
        if (strAnim.GetLength() > 0)
        {
            kName = (const char*)FUN_1409a2360(strAnim, 0);
            m_spData->m_strAnim = strAnim;
            m_pOwner->FUN_14166dd20(kName, 1.0f, false, false);
        }
    }
    return true;
}

// @0x140b8e560
MS2Ptr<StateData> StateReact::vfunc_27()
{
    return MS2Ptr<StateData>(new StateReactData(0, CString(), CString()));
}

// @0x140b8e630
int StateReact::vfunc_1()
{
    return 0x3d;
}

MS2_EMIT_CRT_MEMMOVE_S();

// Shared header statics: this TU's .text$di initializers and their atexit thunks (gap2 orphan di sweep).
// MS2-RANGE: 0x1400c93b0-0x1400c9520 .text$di
// MS2-RANGE: 0x142ca12a0-0x142ca1330 .text$yd
#include "ms2/placeholder/header_statics_a.h"
