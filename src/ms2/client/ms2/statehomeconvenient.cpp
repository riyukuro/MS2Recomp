// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The housing convenience call state StateHomeConvenient and its
// StateData payload. See statehomeconvenient.h.
// MS2-UNIT: ?\statehomeconvenientdata.cpp
// MS2-RANGE: 0x140ddcf00-0x140dde050 .text$mn
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statehomeconvenientdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"

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
#include "hook/ms2hook.h"

// ---- unit-local placeholders ----

extern Vector3 DAT_143b01a60;                    // the zero point

// The state-sync record (Unk_StateArg22 in statemanager.h) as StateData slots 1/2 see it: +0x70 carries the kind.
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

// The casting bar request (FUN_1418e12f0): duration, label and a second text.
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

// The casting bar dialog (RTTI UICastingBar, found through FUN_140ac2270).
class UICastingBar : public UIObject
{
public:
    void FUN_1418e12f0(ICastingEventListener* pListener, const CStringW& strLabel, int nMs, bool bA, bool bB, const CStringW& strExtra);   // show
    void FUN_1418e1390();                                                          // cancel
};
UICastingBar* FUN_140ac2270(int nId);

CStringW GetStringCommon(int nId);                         // string table text of an id
int FUN_14028d260(float fSeconds);                       // seconds -> ms
unsigned FUN_140869420();                                // server tick
CString* FUN_140298f80(Common::Constants::Value<CString>* pValue);   // Value<CString>::Get as a free function
unsigned FUN_140ac2250(Common::Constants::Value<unsigned int>* pValue);   // Value<uint>::Read as a free function

// The doctor NPC script (1 = a script page shown by the NPC dialog service).
class Unk_HcNpcScript : public CPtred
{
public:
    char m_pad_18[0x40];
};
MS2Ptr<Unk_HcNpcScript> FUN_140856820(unsigned nNpcId, int nScriptId);   // by id and script (empty when unknown)
MS2Ptr<Unk_HcNpcScript> FUN_140856c50(unsigned nNpcId, int nMode);
class Unk_HcDialogMgr { public: int FUN_141b213f0(MS2Ptr<Unk_HcNpcScript> spScript, unsigned nNpcId, unsigned nMode, int nFlags); };
Unk_HcDialogMgr* FUN_140967100();
int FUN_141661aa0(MyPC* p);
class Unk_HcBuffMgr { public: Vector3 FUN_141683290(); };
Unk_HcBuffMgr* FUN_14166d240(PCBase* p);
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
bool FUN_1416749c0(PCBase* p);
void* FUN_14165f100(PCBase* p);
void FUN_14165f170(PCBase* p);

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
        return FUN_140ac2250(&static_cast<Client::Constants*>(FUN_1401d3200())->HomeBankCallDuration);
    case 3:
        return FUN_140ac2250(&static_cast<Client::Constants*>(FUN_1401d3200())->HomeDoctorCallDuration);
    }
    return FUN_140ac2250(&static_cast<Client::Constants*>(FUN_1401d3200())->HomeBankCallDuration);
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
        return efd::utf8string(static_cast<const char*>(*FUN_140298f80(&static_cast<Client::Constants*>(FUN_1401d3200())->HomeBankCallSequence)));
    case 3:
        return efd::utf8string(static_cast<const char*>(*FUN_140298f80(&static_cast<Client::Constants*>(FUN_1401d3200())->HomeDoctorCallSequence)));
    }
    return efd::utf8string("Object_React_A");
}

// @0x140ddd950
void StateHomeConvenient::Finish(double fTime)
{
    m_pOwner->FUN_14166dda0(0);
    switch (GetKind())
    {
    case 1:
    case 2:
        if (FUN_1417b8560())
        {
            UICastingBar* pBar = FUN_140ac2270(0x4e72);
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
                UICastingBar* pBar = FUN_140ac2270(0x4e72);
                if (pBar)
                    pBar->FUN_1418e1390();
                unsigned nNpc = *static_cast<Client::Constants*>(FUN_1401d3200())->HomeDoctorNpcID.Get();
                if (FUN_141661aa0(pRider) > 0)
                {
                    if (Unk_HcNpcScript* pScript = FUN_140856c50(nNpc, 1).get())
                        FUN_140967100()->FUN_141b213f0(MS2Ptr<Unk_HcNpcScript>(pScript), nNpc, 1, 0x12);
                }
                else
                {
                    int nScript = *static_cast<Client::Constants*>(FUN_1401d3200())->HomeDoctorScriptID1.Get();
                    if (Unk_HcNpcScript* pScript = FUN_140856820(nNpc, nScript).get())
                        FUN_140967100()->FUN_141b213f0(MS2Ptr<Unk_HcNpcScript>(pScript), nNpc, 2, 0);
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
    m_pOwner->FUN_14166dd20(GetAnimation(), 1.0f, false, false);
    int nStart = FUN_140869420();
    int nDuration = GetDuration();
    m_n44 = nStart;
    m_n48 = nStart + nDuration;
    PCBase* pPC = FUN_1417b8370();
    if (pPC)
    {
        m_n48 += 100;
        if (FUN_14165f100(pPC))
            FUN_14165f170(pPC);
    }
    if (FUN_1417b8560())
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
        {
            CStringW strExtra(L"");
            pBar->FUN_1418e12f0(0, GetLabel(), nDuration, false, true, strExtra);
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
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
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
    m_n44 += FUN_14028d260((float)fTime);
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
    Unk_HcBuffMgr* pMgr = FUN_14166d240(pPC);
    reinterpret_cast<Unk_HcSlots*>(pPC)->vfunc_22(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(pMgr->FUN_141683290())));
    if (FUN_1416749c0(m_pOwner))
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
