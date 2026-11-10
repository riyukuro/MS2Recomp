// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The housing convenience call state StateHomeConvenient and its
// StateData payload. See statehomeconvenient.h.
// MS2-UNIT: ?\statehomeconvenientdata.cpp
// MS2-RANGE: 0x140ddcf00-0x140dde050 .text$mn
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statehomeconvenientdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>

#include <new>
#include <stdlib.h>

#include "statehomeconvenient.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/icastingeventlistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/scriptptr.h"
#include "ms2/placeholder/uitalkmanager.h"   // C3: UITalkManager::FUN_141b213f0 (MS2Ptr<CTalkScript>)
#include "hook/ms2hook.h"

// ---- unit-local placeholders ----

#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60

// The state-sync record (StateSyncObject in statemanager.h) as StateData slots 1/2 see it: +0x70 carries the kind.
class Unk_StateDataArg
{
public:
    char m_pad_00[0x70];
    CString m_str70;                                    // +0x70
    char m_pad_78[0xb8 - 0x78];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);

CString FUN_1405a7e80(int n);                           // int -> decimal string
void FUN_140710590(COutPacket& packet);                 // send

// The casting bar request (UICastingBar::StartCastingText, 0x1418e12f0): duration, label and a second text.
struct Unk_HcCastInfo
{
    Unk_HcCastInfo()
        : m_nDuration(0), m_b4(false), m_b5(true), m_f8(0.0f), m_fC(1.0f), m_n10(0)
    {
        m_str20 = "yellow";
        m_str18 = "show";
    }                                                    // 0x140ac2eb0
    ~Unk_HcCastInfo() {}                                 // 0x140ac3070
    int m_nDuration;                                     // +0x00
    bool m_b4;                                           // +0x04
    bool m_b5;                                           // +0x05
    float m_f8;                                          // +0x08
    float m_fC;                                          // +0x0c (1.0)
    int m_n10;                                           // +0x10
    CStringW m_str18;                                    // +0x18 "show"
    CStringW m_str20;                                    // +0x20 "yellow"
    CStringW m_str28;                                    // +0x28 label
    CStringW m_str30;                                    // +0x30
};
MS2_CHECK_SIZE(Unk_HcCastInfo, 0x38);

// The casting bar dialog (RTTI UICastingBar, found through GetCastingBar).
class UICastingBar : public UIObject
{
public:
    void StartCastingText(class ICastingEventListener* pListener, const CStringW& strLabel, int nMs, bool bA, bool bB, const CStringW& strExtra);   // show
    void FUN_1418e1390();                                                          // cancel
};
UICastingBar* GetCastingBar(int nId);

CStringW GetStringCommon(int nId);                         // string table text of an id
__int64 FUN_14028d260(float fSeconds);                       // seconds -> ms  (C3: the definition's __int64 return, read as int)
unsigned long GetTickCountMs2();   // C3: was FUN_140869420

// The doctor NPC talk script (1 = a script page shown by the NPC dialog service). C3: the definers' types (talkscript.cpp).
Unk_ScriptPtr<CTalkScript> FUN_140856820(int nNpcId, int nTalkId);   // by id and script (empty when unknown)
Unk_ScriptPtr<CTalkScript> FUN_140856c50(int nNpcId, int nMode);
class Unk_PCMove { public: Vector3 GetMoveDirection(); };   // C3: view of the real class (unit_141682f80)
class Unk_HcBuffMgr { public: };
// the owner's vtable seen with the by-value point parameters of vfunc_22 and vfunc_68
class Unk_HcSlots
{
public:
#define MS2_HC_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_HC_SLOTS(0, 1, 2, 3, 4) MS2_HC_SLOTS(5, 6, 7, 8, 9) MS2_HC_SLOTS(10, 11, 12, 13, 14) MS2_HC_SLOTS(15, 16, 17, 18, 19)
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kPos);                                // 22 0x14123c3a0
    virtual void vfunc_23(); virtual void vfunc_24();
    MS2_HC_SLOTS(25, 26, 27, 28, 29) MS2_HC_SLOTS(30, 31, 32, 33, 34) MS2_HC_SLOTS(35, 36, 37, 38, 39)
    MS2_HC_SLOTS(40, 41, 42, 43, 44) MS2_HC_SLOTS(45, 46, 47, 48, 49) MS2_HC_SLOTS(50, 51, 52, 53, 54)
    MS2_HC_SLOTS(55, 56, 57, 58, 59) MS2_HC_SLOTS(60, 61, 62, 63, 64)
#undef MS2_HC_SLOTS
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
    virtual bool vfunc_68(efd::Point3 kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
};

// ---- StateHomeConvenientData ----

// @0x140ddcf00
StateHomeConvenientData::StateHomeConvenientData() : m_nKind(0) {}

// @0x140ddcf40
StateHomeConvenientData::StateHomeConvenientData(int nKind) : m_nKind(nKind) {}

// @0x140ddcf90
void StateHomeConvenientData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_str70 = FUN_1405a7e80(m_nKind);
}

// @0x140ddd010
void StateHomeConvenientData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nKind = FUN_140718170(p->m_str70);
}

// ---- StateHomeConvenient ----

// @0x140ddd060
StateHomeConvenient::StateHomeConvenient(PCBase* pOwner) : State(pOwner), m_n40(0) {}

// @0x140ddd0d0
StateHomeConvenient::~StateHomeConvenient()
{
    m_n40 = 0;
}

// @0x140ddd6f0
int StateHomeConvenient::GetKind()
{
    if (m_spHome.get())
        return m_spHome->m_nKind;
    return 0;
}

// @0x140ddd740
int StateHomeConvenient::GetDuration()
{
    switch (GetKind())
    {
    case 1:
    case 2:
        return static_cast<Client::Constants*>(GetClientConstants())->HomeBankCallDuration.Read();
    case 3:
        return static_cast<Client::Constants*>(GetClientConstants())->HomeDoctorCallDuration.Read();
    }
    return static_cast<Client::Constants*>(GetClientConstants())->HomeBankCallDuration.Read();
}

// @0x140ddd7c0
CStringW StateHomeConvenient::GetLabel()
{
    switch (GetKind())
    {
    case 1:
    case 2:
        return GetStringCommon(0x65f);
    case 3:
        return GetStringCommon(0x663);
    }
    return GetStringCommon(0);
}

// @0x140ddd870
efd::utf8string StateHomeConvenient::GetAnimation()
{
    switch (GetKind())
    {
    case 1:
        return efd::utf8string(static_cast<const char*>(*static_cast<Client::Constants*>(GetClientConstants())->HomeBankCallSequence.Get()));
    case 3:
        return efd::utf8string(static_cast<const char*>(*static_cast<Client::Constants*>(GetClientConstants())->HomeDoctorCallSequence.Get()));
    }
    return efd::utf8string("Object_React_A");
}

// @0x140ddd950
void StateHomeConvenient::Finish(double fTime)
{
    m_pOwner->PlayAnimationById(0);
    switch (GetKind())
    {
    case 1:
    case 2:
        if (FUN_1417b8560())
        {
            UICastingBar* pBar = GetCastingBar(0x4e72);
            if (pBar)
                pBar->FUN_1418e1390();
            COutPacket packet(static_cast<int>(SendOp::RequestHomeBank), 0);
            packet.WriteUInt8((unsigned char)GetKind());
            FUN_140710590(packet);
            m_n40 = 1;
        }
        SetSub(0x89, 0);
        break;
    case 3:
        {
            MyPC* pRider = FUN_1417b84b0();
            if (pRider)
            {
                UICastingBar* pBar = GetCastingBar(0x4e72);
                if (pBar)
                    pBar->FUN_1418e1390();
                unsigned nNpc = *static_cast<Client::Constants*>(GetClientConstants())->HomeDoctorNpcID.Get();
                if (((class PC*)(class MyPC*)(pRider))->FUN_141661aa0() > 0)
                {
                    if (CTalkScript* pScript = FUN_140856c50(nNpc, 1).get())
                        TSingleton<UITalkManager>::GetInstance()->BeginTalkWithoutNpc(MS2Ptr<CTalkScript>(pScript), nNpc, 1, 0x12);
                }
                else
                {
                    int nScript = *static_cast<Client::Constants*>(GetClientConstants())->HomeDoctorScriptID1.Get();
                    if (CTalkScript* pScript = FUN_140856820(nNpc, nScript).get())
                        TSingleton<UITalkManager>::GetInstance()->BeginTalkWithoutNpc(MS2Ptr<CTalkScript>(pScript), nNpc, 2, 0);
                }
                m_n40 = 1;
            }
            SetSub(0x89, 0);
        }
        break;
    }
}

// @0x140dddc90
void StateHomeConvenient::SetSub(int nSub, int nAddTime)
{
    m_n10 = nSub;
    m_n48 += nAddTime;
}

// @0x140ddd120
void StateHomeConvenient::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spHome.AssignRaw(dynamic_cast<StateHomeConvenientData*>(pData));
    if (m_spHome == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    m_n10 = 0x88;
    m_pOwner->PlayAnimation(GetAnimation(), 1.0f, false, false);
    int nStart = GetTickCountMs2();
    int nDuration = GetDuration();
    m_n44 = nStart;
    m_n48 = nStart + nDuration;
    PCBase* pPC = FUN_1417b8370();
    if (pPC)
    {
        m_n48 += 100;
        if (((void*)((class PC*)(class PCBase*)(pPC))->GetHeldItem()))
            ((class PC*)(class PCBase*)(pPC))->SendRequestCube();
    }
    if (FUN_1417b8560())
    {
        UICastingBar* pBar = GetCastingBar(0x4e72);
        if (pBar)
        {
            CStringW strExtra(L"");
            pBar->StartCastingText(0, GetLabel(), nDuration, false, true, strExtra);
        }
    }
}

// @0x140ddd3b0
void StateHomeConvenient::vfunc_7(int n)
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC)
    {
        pPC->vfunc_23(0);
        pPC->vfunc_59(n, 0, 0, 0);
    }
}

// @0x140ddd420
void StateHomeConvenient::vfunc_5(int n)
{
    if (FUN_1417b8560())
    {
        UICastingBar* pBar = GetCastingBar(0x4e72);
        if (pBar)
            pBar->FUN_1418e1390();
    }
    State::vfunc_5(n);
    if (FUN_1417b8370())
    {
        PCBase* pPC = FUN_1417b8370();
        pPC->vfunc_23(0);
    }
    m_n40 = 0;
}

// @0x140ddd4c0
void StateHomeConvenient::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    reinterpret_cast<Unk_HcSlots*>(m_pOwner)->vfunc_68(reinterpret_cast<const efd::Point3&>(DAT_143b01a60), fTime, 0, 0, 0);
    m_n44 += (int)FUN_14028d260((float)fTime);
    if ((unsigned)m_n44 >= (unsigned)m_n48)
    {
        switch (m_n10)
        {
        case 0x88:
            Finish(fTime);
            break;
        default:
            vfunc_7(1);
            break;
        }
    }
}

// @0x140ddd5b0
void StateHomeConvenient::vfunc_8(double fTime)
{
    if (m_n10 != 0x88)
        return;
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (!pPC)
        return;
    Unk_HcBuffMgr* pMgr = ((class Unk_HcBuffMgr*)((class PCBase*)(class PCBase*)(pPC))->FUN_14166d240());
    reinterpret_cast<Unk_HcSlots*>(pPC)->vfunc_22(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Unk_PCMove*>(pMgr)->GetMoveDirection())));
    if (((class PCBase*)(class PCBase*)(m_pOwner))->FUN_1416749c0())
        pPC->vfunc_59(2, 0, 0, 0);
    else
        FUN_1417b9460();
}

// @0x140ddd6b0
void StateHomeConvenient::vfunc_6()
{
    if (FUN_1417b8370())
        vfunc_7(1);
}

// @0x140dddeb0
MS2Ptr<StateData> StateHomeConvenient::vfunc_27()
{
    return MS2Ptr<StateData>(new StateHomeConvenientData());
}

// @0x140dddf30
int StateHomeConvenient::vfunc_1() { return 0x36; }
