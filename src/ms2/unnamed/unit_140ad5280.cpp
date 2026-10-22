// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateTreeWatering: the actor state of a player watering a
// housing tree (casting bar, watering animation, server notice when the cast finished) and its payload.
// MS2-UNIT: unit_140ad5280
// MS2-RANGE: 0x140ad5280-0x140ad5df0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_140ad5280.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <efd/utf8string.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local stand-ins and unrecovered callees ----

extern Unk_StreamPoint DAT_143b01a60;                    // the zero point

// A Constants::Value<int> seen through its Read (the inline COMDAT 0x140ad5c50 of this obj; Get is FUN_1402056b0).
class Unk_SSGConstValue { public: int* FUN_1402056b0(); int FUN_140ad5c50(); };

class Unk_StateDataArg                                   // the state-sync record (slots 1/2 of StateData)
{
public:
    char m_pad_00[0x70];
    CString m_str70;                                     // +0x70 the watering animation name
    char m_pad_78[0xb8 - 0x78];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);

// The casting bar dialog (RTTI UICastingBar, found through FUN_140ac2270).
class UICastingBar : public UIObject
{
public:
    void FUN_1418e12f0(ICastingEventListener* pListener, const CStringW& strText, int nDuration, bool bA, bool bB,
        const CStringW& strLabel);                       // show
    void FUN_1418e1390();                                // cancel
};
UICastingBar* FUN_140ac2270(int nId);
CStringW GetStringCommon(int nId);                         // string table text by id
void* FUN_14165f100(PCBase* p);
void FUN_14165f170(PCBase* p);
class Unk_TwBuffMgr { public: Unk_StreamPoint FUN_141683290(); };
Unk_TwBuffMgr* FUN_14166d240(PCBase* p);
bool FUN_1416749c0(PCBase* p);

// @0x140ad5c50
int Unk_SSGConstValue::FUN_140ad5c50()
{
    return *FUN_1402056b0();
}

// ---- StateTreeWateringData ----

// @0x140ad5280
StateTreeWateringData::StateTreeWateringData(CString strAnim) : m_strAnim(strAnim)
{
}

// @0x140ad52f0
StateTreeWateringData::~StateTreeWateringData()
{
}

// @0x140ad5330
void StateTreeWateringData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_str70 = m_strAnim;
}

// @0x140ad5380
void StateTreeWateringData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_strAnim = p->m_str70;
}

// ---- StateTreeWatering ----

// @0x140ad53d0
StateTreeWatering::StateTreeWatering(PCBase* pOwner)
    : State(pOwner), m_spWatering(new StateTreeWateringData(CString()))
{
    m_n48 = 0;
}

// @0x140ad54c0
StateTreeWatering::~StateTreeWatering()
{
}

// @0x140ad5510
void StateTreeWatering::vfunc_4(StateData* pData)
{
    m_n48 = 0;
    State::vfunc_4(pData);
    int nTextId;
    int nDuration = reinterpret_cast<Unk_SSGConstValue*>(&static_cast<Client::Constants*>(FUN_1401d3200())->SummonRideeDuration)->FUN_140ad5c50();
    nTextId = 0;
    if (m_n10 == 0xa0)
        nTextId = 0xd1b;
    if (m_n10 == 0xa1)
    {
        nDuration = static_cast<Client::Constants*>(FUN_1401d3200())->TreewateringEmotion.Read();
        nTextId = 0xd1c;
    }
    MS2Ptr<StateTreeWateringData> spData(dynamic_cast<StateTreeWateringData*>(pData));
    if (spData.get() != 0)
        m_spWatering = spData;
    MyPC* pRider = FUN_1417b84b0();
    if (pRider != 0)
    {
        if (FUN_14165f100(pRider) != 0)
            FUN_14165f170(pRider);
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
        {
            CStringW strLabel(L"");
            pBar->FUN_1418e12f0(static_cast<ICastingEventListener*>(this), GetStringCommon(nTextId), nDuration, false,
                true, strLabel);
        }
    }
}

// @0x140ad5730
void StateTreeWatering::vfunc_7(int n)
{
    if (FUN_1417b8370() != 0)
    {
        FUN_1417b8370()->vfunc_23(0);
        FUN_1417b8370()->vfunc_59(n, 0, 0, 0);
    }
}

// @0x140ad57b0
void StateTreeWatering::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Unk_StreamPoint kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
}

// @0x140ad5830
void StateTreeWatering::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_pOwner->FUN_14166e0a0();
    if (FUN_1417b8560())
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
            pBar->FUN_1418e1390();
    }
}

// @0x140ad58a0
// MS2-FUNCTIONAL: the exe lays the state-point copies out in different stack slots (kPos above kArg)
void StateTreeWatering::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
        return;
    if (m_n48 != 0)
    {
        if (m_n10 == 0xa0)
        {
            COutPacket kPacket(static_cast<int>(SendOp::TreeWatering), 0);
            kPacket.WriteUInt8(0);
            FUN_140710590(kPacket);
        }
        if (m_n10 == 0xa1)
        {
            COutPacket kPacket(static_cast<int>(SendOp::TreeWatering), 0);
            kPacket.WriteUInt8(1);
            FUN_140710590(kPacket);
        }
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    Unk_TwBuffMgr* pBuff = FUN_14166d240(pRider);
    Unk_StreamPoint kPos = pBuff->FUN_141683290();
    Unk_StreamPoint kArg = kPos;
    pRider->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
    if (FUN_1416749c0(m_pOwner) != 0)
        pRider->vfunc_59(2, 0, 0, 0);
    else
        FUN_1417b9460();
}

// @0x140ad5a80
void StateTreeWatering::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    if (m_n10 == 0xa0)
    {
        efd::utf8string kName((const char*)m_spWatering->m_strAnim);
        m_pOwner->FUN_14166dd20(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
    if (m_n10 == 0xa1)
    {
        efd::utf8string kName((const char*)m_spWatering->m_strAnim);
        m_pOwner->FUN_14166dd20(kName, m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x140ad5be0
void StateTreeWatering::vfunc_6()
{
    if (FUN_1417b8560())
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x140ad5c30
void StateTreeWatering::OnCastingFinished()
{
    m_n48 = 1;
}

// @0x140ad5d40
MS2Ptr<StateData> StateTreeWatering::vfunc_27()
{
    return MS2Ptr<StateData>(new StateTreeWateringData(CString()));
}

// @0x140ad5de0
int StateTreeWatering::vfunc_1()
{
    return 0x3e;
}

MS2_EMIT_CRT_MEMMOVE_S();
