// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateCashCall, the actor state of a player calling an air taxi /
// helicopter / bank with a cash item (casting bar, the vehicle effect at the player, the request when the ride starts), and
// its payload StateCashCallData. See statecashcalldata.h. The MS2Ptr<StateCashCallData> instantiations the exe keeps in this
// unit's tail come out of ms2ptr_impl.h. w276; modelled on statetaxicalldata.cpp (the same state family).
// MS2-UNIT: ?\statecashcalldata.cpp
// MS2-RANGE: 0x1410229d0-0x141024250 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?get@?$MS2Ptr@VStateCashCallData@@@@QEBAPEAVStateCashCallData@@XZ 0x141024000 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statecashcalldata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "statecashcalldata.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include <efd/utf8string.h>
#include <efd/Point3.h>
#include <efd/Matrix3.h>
#include <NiTransform.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local stand-ins and unrecovered callees ----

class Unk_StateDataArg                                   // the state-sync record (slots 1/2 of StateData)
{
public:
    char m_pad_00[0x70];
    CString m_str70;                                     // +0x70 the call type as text
    char m_pad_78[0xb8 - 0x78];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);

CString FUN_1405a7e80(int n);                            // number -> text
int FUN_140718170(const CString& str);                   // text -> number
unsigned FUN_140869420();                                // millisecond clock
int FUN_14028d260(float f);                              // seconds -> ms
char FUN_1401c0090(const CString& a, const CString& b);  // strings are equal
void* FUN_14165f100(PCBase* p);
void FUN_14165f170(PCBase* p);
void FUN_140710590(COutPacket& packet);
CStringW GetStringCommon(int nId);                         // string table text by id
CStringW FUN_14052bd00(int nId, const CStringW& strArg);   // formatted system text
void FUN_1412751f0(CStringW strText, int a, int b);      // system notice

// The strings singleton (FUN_1401d31f0): the station / effect names per call type.
struct Unk_CcStrings
{
    char m_pad_000[0x3a0];
    CString m_str3a0;                                    // +0x3a0
    CString m_str3a8;                                    // +0x3a8
    CString m_str3b0;                                    // +0x3b0
    CString m_str3b8;                                    // +0x3b8
};
MS2_CHECK_OFFSET(Unk_CcStrings, m_str3b8, 0x3b8);
Unk_CcStrings* FUN_1401d31f0();

// A Constants::Value<int> seen through its Read (the inline COMDAT 0x140ad5c50 lives in another unit).
class Unk_CcConstValue { public: int FUN_140ad5c50(); };
float* FUN_140298f40(void* pOption);

// The casting bar dialog (RTTI UICastingBar, found through FUN_140ac2270).
class ICastingEventListener;
class UICastingBar : public UIObject
{
public:
    void FUN_1418e12f0(ICastingEventListener* pListener, const CStringW& strText, int nDuration, bool bA, bool bB,
        const CStringW& strLabel);                       // show
    void FUN_1418e1390();                                // cancel
};
UICastingBar* FUN_140ac2270(int nId);

// The actor's move-key state (PCBase::FUN_14166d240).
class Unk_CcBuffMgr { public: Unk_StreamPoint FUN_141683290(); };
Unk_CcBuffMgr* FUN_14166d240(PCBase* p);
bool FUN_1416749c0(PCBase* p);

// The player inventory (global 0x143ab2a90): item lookup by uid and the item's name.
class Unk_CcInventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid);                         // the item with that uid
    int FUN_140a63880(CItem* pItem, const CStringW& strName);              // the item's name
};
extern Unk_CcInventory DAT_143ab2a90;

// The effect request.
struct Unk_CcRot { float m_af[9]; };
struct Unk_CcXform
{
    Unk_CcRot m_rotate;
    float m_afTranslate[3];
    float m_fScale;
};
MS2_CHECK_SIZE(Unk_CcXform, 0x34);
struct Unk_CcRequest
{
    CString m_strName;                                   // +0
    int m_nKind;                                         // +8
    int m_pad_0c;
    void* m_pSlot10;
    NiTransform* m_pXform;                               // +0x18
    char m_pad_20[0x58];
};
MS2_CHECK_SIZE(Unk_CcRequest, 0x78);
class Unk_CcEffectMgr { public: void FUN_1411a4a00(Unk_CcRequest* pRequest); };
Unk_CcEffectMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_CcRequest* p);                    // construct
void FUN_1405a89e0(Unk_CcRequest* p);                    // destroy

// Point3 helpers (out-of-line in the exe).
Unk_StreamPoint FUN_1420834e0(const Unk_StreamPoint& v, const efd::Matrix3& m);   // efd::operator*(Point3, Matrix3)
void FUN_14097faa0(NiPoint3* pDst, const NiPoint3* pSrc);   // NiPoint3 assignment
extern Unk_StreamPoint DAT_143a08ce8;                       // the default direction
extern Unk_StreamPoint DAT_143b01a60;                       // the zero point

// ---- StateCashCallData ----

// @0x1410229d0
StateCashCallData::StateCashCallData()
{
    m_nCallType = 0;
    m_nItemUid = 0;
    m_nPrice = 0;
}

// @0x141022a30
StateCashCallData::StateCashCallData(int nCallType, __int64 nItemUid, int nPrice)
{
    m_nCallType = nCallType;
    m_nItemUid = nItemUid;
    m_nPrice = nPrice;
}

// @0x141022aa0
void StateCashCallData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_str70 = FUN_1405a7e80(m_nCallType);
}
MS2_REPLACE_METHOD(0x141022AA0, StateCashCallData, vfunc_1, 111, 0xD956D9B6);

// @0x141022b20
void StateCashCallData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nCallType = FUN_140718170(p->m_str70);
}
MS2_REPLACE_METHOD(0x141022B20, StateCashCallData, vfunc_2, 59, 0xC35DD492);

// @0x141023f00
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
StateCashCallData::~StateCashCallData()
{
}

// ---- StateCashCall ----

// @0x141022b70
StateCashCall::StateCashCall(PCBase* pOwner)
    : State(pOwner), m_nStart(0), m_nElapsed(0), m_nEnd(0), m_bSent(0)
{
}

// @0x141022c00
StateCashCall::~StateCashCall()
{
    m_bSent = 0;
}

// @0x141022c50
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
void StateCashCall::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spCash.AssignRaw(dynamic_cast<StateCashCallData*>(pData));
    if (m_spCash == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        m_n10 = 0x6b;
        {
            efd::utf8string kName = GetEffectName();
            m_pOwner->FUN_14166dd20(kName, 1.0f, false, false);
        }
        unsigned nNow = FUN_140869420();
        int nDuration = GetDuration();
        m_nStart = nNow;
        m_nElapsed = nNow;
        m_nEnd = nNow + nDuration;
        MyPC* pMyPC = FUN_1417b84b0();
        if (pMyPC != 0)
        {
            m_nEnd = m_nEnd + 100;
            if (FUN_14165f100(pMyPC) != 0)
                FUN_14165f170(pMyPC);
            UICastingBar* pBar = FUN_140ac2270(0x4e72);
            if (pBar != 0)
            {
                CStringW strLabel(L"");
                pBar->FUN_1418e12f0(0, GetCastText(), nDuration, false, true, strLabel);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141022C50, StateCashCall, vfunc_4, 644, 0xFB5BD6EC);

// @0x141022ee0
void StateCashCall::vfunc_7(int n)
{
    if (FUN_1417b8370() != 0)
    {
        FUN_1417b8370()->vfunc_23(0);
        FUN_1417b8370()->vfunc_59(n, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x141022EE0, StateCashCall, vfunc_7, 121, 0x7C5C2825);

// @0x141022f60
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
void StateCashCall::vfunc_5(int n)
{
    if (FUN_1417b8560() != 0)
    {
        if (m_bSent == 0)
        {
            if (m_spCash.get() != 0)
            {
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_spCash->m_nItemUid);
                if (spItem.get() != 0)
                {
                    CStringW strName = FUN_14052bd00(0xa0, spItem->FUN_140527b10());
                    FUN_1412751f0(strName, 1, 1);
                }
            }
        }
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
            pBar->FUN_1418e1390();
    }
    State::vfunc_5(n);
    if (FUN_1417b8370() != 0)
        FUN_1417b8370()->vfunc_23(0);
    m_bSent = 0;
}
MS2_REPLACE_METHOD(0x141022F60, StateCashCall, vfunc_5, 412, 0x78998610);

// @0x141023110
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
void StateCashCall::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Unk_StreamPoint kPoint = DAT_143b01a60;
    m_pOwner->vfunc_68(&kPoint, fTime, 0, 0, 0);
    m_nElapsed += FUN_14028d260((float)fTime);
    if (m_nElapsed >= m_nEnd)
    {
        if (m_n10 == 0x6b)
            OnCastEnd(fTime);
        else if (m_n10 == 0x6c)
            OnArrived(fTime);
        else if (m_n10 == 0x6d)
            OnLeave(fTime);
        else
            vfunc_7(1);
    }
}
MS2_REPLACE_METHOD(0x141023110, StateCashCall, vfunc_3, 277, 0xCDE0070E);

// @0x141023230
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
void StateCashCall::vfunc_8(double fTime)
{
    if (m_n10 != 0x6b)
        return;
    State::vfunc_8(fTime);
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
        return;
    Unk_StreamPoint kPos = FUN_14166d240(pRider)->FUN_141683290();
    Unk_StreamPoint kArg = kPos;
    pRider->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
    if (FUN_1416749c0(m_pOwner) != 0)
        pRider->vfunc_59(2, 0, 0, 0);
    else
        FUN_1417b9460();
}
MS2_REPLACE_METHOD(0x141023230, StateCashCall, vfunc_8, 245, 0x6E288686);

// @0x141023330
void StateCashCall::vfunc_6()
{
    if (FUN_1417b8370() != 0 && m_n10 != 0x69)
        vfunc_7(1);
}
MS2_REPLACE_METHOD(0x141023330, StateCashCall, vfunc_6, 61, 0x06E3DF1C);

// @0x141023380
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
int StateCashCall::GetCallType()
{
    if (m_spCash.get() != 0)
        return m_spCash->m_nCallType;
    else
        return 0;
}
MS2_REPLACE_METHOD(0x141023380, StateCashCall, GetCallType, 60, 0xB49FCAB5);

// @0x1410233d0
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
void StateCashCall::OnCastEnd(double fTime)
{
    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
            pBar->FUN_1418e1390();
    }
    CString strEffect = GetStationName();
    if (strEffect.IsEmpty())
    {
        SetPhase(0x6d, 100);
    }
    else
    {
        SpawnEffect(strEffect);
        int nWait = 0xc80;
        if (FUN_1401c0090(strEffect, FUN_1401d31f0()->m_str3a0) != 0)
            nWait = 1000;
        SetPhase(0x6c, nWait);
    }
    m_pOwner->FUN_14166dda0(0);
}
MS2_REPLACE_METHOD(0x1410233D0, StateCashCall, OnCastEnd, 243, 0x173C3302);

// @0x1410234d0
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
void StateCashCall::OnArrived(double fTime)
{
    int nWait = 100;
    int nType = GetCallType();
    if (0 < nType && nType <= 3)
    {
        PCBase* pPC = FUN_1417b8370();
        if (pPC != 0)
            pPC->vfunc_23(1);
        nWait = 1000;
    }
    SetPhase(0x6d, nWait);
}
MS2_REPLACE_METHOD(0x1410234D0, StateCashCall, OnArrived, 133, 0xCF0259D6);

// @0x141023560
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
void StateCashCall::OnLeave(double fTime)
{
    int nWait = 100;
    SendRequest();
    int nType = GetCallType();
    if (0 < nType)
    {
        if (nType < 5)
        {
            nWait = 3000;
        }
        else if (nType == 5)
        {
            nWait = FUN_14028d260(*FUN_140298f40(&static_cast<Client::Constants*>(FUN_1401d3200())->CashCallMedicLeaveDelay));
            if (FUN_1417b8560() != 0)
            {
                CStringW strNotice = GetStringCommon(0x98);
                FUN_1412751f0(strNotice, 1, 1);
            }
        }
    }
    SetPhase(0x6e, nWait);
}
MS2_REPLACE_METHOD(0x141023560, StateCashCall, OnLeave, 227, 0x9331AA79);

// @0x141023650
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
void StateCashCall::SendRequest()
{
    if (FUN_1417b8560() != 0 && !m_spCash.IsNull())
    {
        if (m_spCash->m_nItemUid == 0)
        {
            if (m_spCash->m_nCallType == 2 || m_spCash->m_nCallType == 1)
            {
                COutPacket kPacket(static_cast<int>(SendOp::RequestTaxi), 0);
                kPacket.vfunc_o10_1(3);
                kPacket.vfunc_o10_3(m_spCash->m_nPrice);
                FUN_140710590(kPacket);
            }
            else if (m_spCash->m_nCallType == 3)
            {
                COutPacket kPacket(static_cast<int>(SendOp::RequestTaxi), 0);
                kPacket.vfunc_o10_1(4);
                kPacket.vfunc_o10_3(m_spCash->m_nPrice);
                FUN_140710590(kPacket);
            }
        }
        else
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_spCash->m_nItemUid);
            if (spItem.get() != 0)
                DAT_143ab2a90.FUN_140a63880(spItem.get(), StringFormat(L"{0}", m_spCash->m_nPrice));
        }
        m_bSent = 1;
    }
}
MS2_REPLACE_METHOD(0x141023650, StateCashCall, SendRequest, 568, 0x7AACEB9C);

// @0x141023890
void StateCashCall::SetPhase(int nPhase, int nAdd)
{
    m_n10 = nPhase;
    m_nEnd += nAdd;
}
MS2_REPLACE_METHOD(0x141023890, StateCashCall, SetPhase, 47, 0xD4E241C4);

// @0x1410238d0
// MS2-FUNCTIONAL: transliterated from the decompile (effect request / transform stand-ins)
void StateCashCall::SpawnEffect(const CString& strEffect)
{
    Unk_StreamPoint kPos;
    Unk_StreamPoint kRot;
    NiTransform xf;
    PCBase* pPC = FUN_1417b8370();
    NiPoint3 kDirNi = pPC->vfunc_20();
    kRot = reinterpret_cast<Unk_StreamPoint&>(kDirNi);
    efd::Matrix3 kMat;
    kMat.MakeZRotation((kRot.z * 3.1415927f) / 180.0f);
    Unk_StreamPoint kDir = FUN_1420834e0(DAT_143a08ce8.FUN_1409f7960(), kMat);
    xf.MakeIdentity();
    Unk_StreamPoint kAhead = kDir.FUN_14097fc90(150.0f);
    NiPoint3 kNowNi = FUN_1417b8370()->vfunc_18();
    Unk_StreamPoint kSum = reinterpret_cast<Unk_StreamPoint&>(kNowNi).FUN_14097fd50(kAhead);
    FUN_14097faa0(&xf.m_Translate, reinterpret_cast<const NiPoint3*>(&kSum));
    float fAngle = ((180.0f - kRot.z) * 3.1415927f) / 180.0f - 1.5707964f;
    xf.m_Rotate.FromEulerAnglesXYZ(0.0f, 0.0f, fAngle);
    Unk_CcRequest request;
    FUN_140a52ef0(&request);
    request.m_strName = strEffect;
    request.m_nKind = (FUN_1417b8560() == 0) ? 3 : 1;
    request.m_pXform = &xf;
    FUN_1403ed280()->FUN_1411a4a00(&request);
    FUN_1405a89e0(&request);
}
MS2_REPLACE_METHOD(0x1410238D0, StateCashCall, SpawnEffect, 623, 0x4B23E957);

// @0x141023b50
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
efd::utf8string StateCashCall::GetEffectName()
{
    int nType = GetCallType();
    if (nType == 4)
        return efd::utf8string("BlackMarketHelicopter_A");
    else if (nType == 5)
        return efd::utf8string("EmergencyHelicopter_A");
    else if (nType == 6)
        return efd::utf8string("Object_React_A");
    else
        return efd::utf8string("AirTaxi_A");
}
MS2_REPLACE_METHOD(0x141023B50, StateCashCall, GetEffectName, 202, 0x0E80E190);

// @0x141023c20
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
int StateCashCall::GetDuration()
{
    int nDuration = reinterpret_cast<Unk_CcConstValue*>(&static_cast<Client::Constants*>(FUN_1401d3200())->TaxiCallDuration)->FUN_140ad5c50();
    int nType = GetCallType();
    if (nType == 1)
    {
        nDuration = reinterpret_cast<Unk_CcConstValue*>(&static_cast<Client::Constants*>(FUN_1401d3200())->AirTaxiMesoCallDuration)->FUN_140ad5c50();
    }
    else if (1 < nType)
    {
        if (nType < 4)
            nDuration = reinterpret_cast<Unk_CcConstValue*>(&static_cast<Client::Constants*>(FUN_1401d3200())->AirTaxiCashCallDuration)->FUN_140ad5c50();
        else if (nType == 6)
            nDuration = reinterpret_cast<Unk_CcConstValue*>(&static_cast<Client::Constants*>(FUN_1401d3200())->BankCallDuration)->FUN_140ad5c50();
    }
    if (FUN_1417b84b0() == 0)
        nDuration = nDuration - 200;
    return nDuration;
}
MS2_REPLACE_METHOD(0x141023C20, StateCashCall, GetDuration, 186, 0xDC4F1236);

// @0x141023ce0
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
CStringW StateCashCall::GetCastText()
{
    int nType = GetCallType();
    if (nType == 6)
        return GetStringCommon(0x65a);
    return GetStringCommon(0x64c);
}
MS2_REPLACE_METHOD(0x141023CE0, StateCashCall, GetCastText, 106, 0x45FDE91C);

// @0x141023d50
// MS2-FUNCTIONAL: behaviour-equivalent; branch / temporary layout differs from the exe (permuter candidate)
CString StateCashCall::GetStationName()
{
    int nType = GetCallType();
    if (nType == 1)
        return FUN_1401d31f0()->m_str3a8;
    if (1 < nType)
    {
        if (nType < 4)
            return FUN_1401d31f0()->m_str3a0;
        if (nType == 4)
            return FUN_1401d31f0()->m_str3b8;
        if (nType == 5)
            return FUN_1401d31f0()->m_str3b0;
    }
    return CString("");
}
MS2_REPLACE_METHOD(0x141023D50, StateCashCall, GetStationName, 298, 0x0867ED29);

// @0x1410240a0
MS2Ptr<StateData> StateCashCall::vfunc_27()
{
    return MS2Ptr<StateData>(new StateCashCallData());
}

// @0x141024120
int StateCashCall::vfunc_20()
{
    return 1;
}

// @0x141024130
int StateCashCall::vfunc_1()
{
    return 0x2a;
}

MS2_EMIT_CRT_MEMMOVE_S();
