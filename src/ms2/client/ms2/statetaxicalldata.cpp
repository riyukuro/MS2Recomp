// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateTaxiCall, the actor state of a player calling a taxi (casting
// bar, the taxi effect at the player, the get-in / drive-away phases, the server request when the ride starts), and its
// payload StateTaxiCallData. See statetaxicalldata.h.
// MS2-UNIT: ?\statetaxicalldata.cpp
// MS2-RANGE: 0x140104af0-0x140104bd1 .text$di
// MS2-RANGE: 0x1417fcf30-0x1417fe410 .text$mn
// MS2-PIN: ??0Unk_TaxiReq@@QEAA@XZ 0x1417fe090
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statetaxicalldata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "statetaxicalldata.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <efd/utf8string.h>
#include <efd/Point3.h>
#include <efd/Matrix3.h>
#include <NiTransform.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (dynamic initializers 0x140104af0 / 0x140104b20) ----
static CString s_strTaxiCall = "PC_Taxi_Call";
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local stand-ins and unrecovered callees ----

class Unk_StateDataArg                                   // the state-sync record (slots 1/2 of StateData)
{
public:
    char m_pad_00[0x70];
    CString m_str70;                                     // +0x70 the taxi id as text
    char m_pad_78[0xb8 - 0x78];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);

CString FUN_1405a7e80(int n);                            // number -> text
float FUN_140768090();                                   // random 0..1
unsigned FUN_140869420();                                // millisecond clock
int FUN_14028d260(float f);                              // seconds -> ms
void FUN_141276180(CString* pTarget, const CString& str);
void* FUN_14165f100(PCBase* p);
void FUN_14165f170(PCBase* p);
int FUN_141b71c00(unsigned short n);

// The strings and constants singletons.
struct Unk_TcStrings
{
    char m_pad_00[0x368];
    CString m_strCall;                                   // +0x368
    CString m_strArrive;                                 // +0x370
    CString m_strLeave;                                  // +0x378
    char m_pad_380[8];
    CString m_strBestCall;                               // +0x388
    CString m_strBestArrive;                             // +0x390
    CString m_strBestLeave;                              // +0x398
};
MS2_CHECK_OFFSET(Unk_TcStrings, m_strBestLeave, 0x398);
Unk_TcStrings* FUN_1401d31f0();

// A Constants::Value<int> seen through its Read (the inline COMDAT 0x140ad5c50 lives in another unit).
class Unk_TcConstValue { public: int FUN_140ad5c50(); };
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
CStringW GetStringCommon(int nId);                         // string table text by id

// The actor's move-key state (PCBase::FUN_14166d240).
class Unk_TcBuffMgr { public: Unk_StreamPoint FUN_141683290(); };
Unk_TcBuffMgr* FUN_14166d240(PCBase* p);
bool FUN_1416749c0(PCBase* p);

// The effect request.
struct Unk_TcRot { float m_af[9]; };
struct Unk_TcXform
{
    Unk_TcRot m_rotate;
    float m_afTranslate[3];
    float m_fScale;
};
MS2_CHECK_SIZE(Unk_TcXform, 0x34);
struct Unk_TcRequest
{
    CString m_strName;                                   // +0
    int m_nKind;                                         // +8
    int m_pad_0c;
    void* m_pSlot10;
    NiTransform* m_pXform;                               // +0x18
    char m_pad_20[0x58];
};
MS2_CHECK_SIZE(Unk_TcRequest, 0x78);
class Unk_TcEffectMgr { public: void FUN_1411a4a00(Unk_TcRequest* pRequest); };
Unk_TcEffectMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_TcRequest* p);                    // construct
void FUN_1405a89e0(Unk_TcRequest* p);                    // destroy

// The world: the taxi stop entity near a position, its properties.
class Unk_TcEntity;
class Unk_TcWorld { public: Unk_TcEntity* FUN_141bcfd30(unsigned nHash, Unk_StreamPoint kPos, float fRange, int nA, int nB); };
Unk_TcWorld* FUN_1403ed2d0();
void FUN_1409618c0(Unk_TcEntity* pEntity, unsigned nHash, Unk_StreamPoint* pOut);   // property read (point)

// Point3 helpers (out-of-line in the exe).
Unk_StreamPoint FUN_1420834e0(const Unk_StreamPoint& v, const efd::Matrix3& m);   // efd::operator*(Point3, Matrix3)
void FUN_14097faa0(NiPoint3* pDst, const NiPoint3* pSrc);   // NiPoint3 assignment
extern Unk_StreamPoint DAT_143a08ce8;                       // the default direction

void FUN_140710590(COutPacket& packet);
void FUN_1401fe9e0(unsigned char* payload, COutputStream& stream);

// ---- StateTaxiCallData ----

// @0x1417fcf30
StateTaxiCallData::StateTaxiCallData()
{
    m_nTaxiId = 0;
}

// @0x1417fcf70
StateTaxiCallData::StateTaxiCallData(int nTaxiId)
{
    m_nTaxiId = nTaxiId;
}

// @0x1417fcfc0
void StateTaxiCallData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_str70 = FUN_1405a7e80(m_nTaxiId);
}

// @0x1417fd040
void StateTaxiCallData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nTaxiId = FUN_1407181d0(p->m_str70);
}

// MS2-FUNCTIONAL: the exe's dtor does not store the vftable before the base dtor call
// @0x1417fe0f0
StateTaxiCallData::~StateTaxiCallData()
{
}

// ---- StateTaxiCall ----

// @0x1417fd090
StateTaxiCall::StateTaxiCall(PCBase* pOwner) : State(pOwner)
{
    m_nStart = 0;
    m_nElapsed = 0;
    m_nEnd = 0;
    m_bSurprise = false;
}

// @0x1417fd150
StateTaxiCall::~StateTaxiCall()
{
}

// @0x1417fd1d0
void StateTaxiCall::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spData.AssignRaw(dynamic_cast<StateTaxiCallData*>(pData));
    if (m_spData == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        m_n10 = 0x65;
        MyPC* pMyPC = FUN_1417b84b0();
        if (pMyPC != 0)
        {
            if (FUN_14165f100(pMyPC) != 0)
                FUN_14165f170(pMyPC);
        }
        unsigned nNow = FUN_140869420();
        efd::utf8string kName("Object_React_B");
        m_nStart = nNow;
        m_nElapsed = nNow;
        m_strCall = FUN_1401d31f0()->m_strCall;
        m_strArrive = FUN_1401d31f0()->m_strArrive;
        m_strLeave = FUN_1401d31f0()->m_strLeave;
        int nDuration = reinterpret_cast<Unk_TcConstValue*>(&static_cast<Client::Constants*>(FUN_1401d3200())->TaxiCallDuration)->FUN_140ad5c50();
        if (FUN_141b71c00((unsigned short)m_pOwner->vfunc_78()) != 0)
        {
            nDuration = reinterpret_cast<Unk_TcConstValue*>(&static_cast<Client::Constants*>(FUN_1401d3200())->TaxiCallBestDriverDuration)->FUN_140ad5c50();
            m_strCall = FUN_1401d31f0()->m_strBestCall;
            m_strArrive = FUN_1401d31f0()->m_strBestArrive;
            m_strLeave = FUN_1401d31f0()->m_strBestLeave;
        }
        m_nEnd = nNow + nDuration;
        m_bSurprise = 0.9f < FUN_140768090();
        m_pOwner->FUN_14166dd20(kName, 1.0f, false, false);
        if (FUN_1417b8560() != 0)
        {
            UICastingBar* pBar = FUN_140ac2270(0x4e72);
            if (pBar != 0)
            {
                CStringW strLabel(L"");
                pBar->FUN_1418e12f0(0, GetStringCommon(0x64b), nDuration, false, true, strLabel);
            }
            CString strEmpty("");
            FUN_141276180(&s_strTaxiCall, strEmpty);
        }
    }
}

// @0x1417fd5b0
void StateTaxiCall::vfunc_7(int)
{
    if (FUN_1417b8370() != 0)
        FUN_1417b8370()->vfunc_23(0);
}

// @0x1417fd600
void StateTaxiCall::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
            pBar->FUN_1418e1390();
    }
    if (FUN_1417b8370() != 0)
        FUN_1417b8370()->vfunc_23(0);
}

// @0x1417fd690
void StateTaxiCall::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    m_nElapsed += FUN_14028d260((float)fTime);
    if (m_nElapsed >= m_nEnd)
    {
        switch (m_n10)
        {
        case 0x65:
        {
            FUN_1417fdbc0(0x66, FUN_14028d260(1.9f));
            FUN_1417fdc00(m_strCall);
            m_pOwner->FUN_14166dda0(0);
            if (m_bSurprise)
            {
                CString strAnim("suprise_A");
                m_pOwner->FUN_14166ef10(strAnim, 1, 0, false);
            }
            break;
        }
        case 0x66:
        {
            FUN_1417fdbc0(0x67, FUN_14028d260(0.45f));
            FUN_1417fdc00(m_strArrive);
            break;
        }
        case 0x67:
        {
            FUN_1417fdbc0(0x68, FUN_14028d260(0.45f));
            FUN_1417b8370()->vfunc_23(1);
            break;
        }
        case 0x68:
        {
            FUN_1417fdbc0(0x69, FUN_14028d260(1.0f));
            FUN_1417fdc00(m_strLeave);
            break;
        }
        case 0x69:
        {
            FUN_1417fdbc0(0x6a, FUN_14028d260(3.0f));
            if (FUN_1417b8560() != 0)
            {
                Unk_TaxiReq kReq;
                kReq.m_nTaxiId = m_spData->m_nTaxiId;
                kReq.m_nCost = 100000000;
                COutPacket kPacket(0x48, 0);
                kPacket.vfunc_o10_1(1);
                FUN_1401fe9e0((unsigned char*)&kReq, kPacket);
                FUN_140710590(kPacket);
            }
            break;
        }
        default:
        {
            FUN_1417b8370()->vfunc_23(0);
            FUN_1417b8370()->vfunc_59(1, 0, 0, 0);
            break;
        }
        }
    }
}

// @0x1417fd9e0
// MS2-FUNCTIONAL: the exe copies the state point with a rep movsb and keeps rsi / rdi; cl lays the temps out differently
void StateTaxiCall::vfunc_8(double fTime)
{
    if (m_n10 == 0x65)
    {
        State::vfunc_8(fTime);
        MyPC* pRider = FUN_1417b84b0();
        if (pRider != 0)
        {
            Unk_StreamPoint kPos = FUN_14166d240(pRider)->FUN_141683290();
            Unk_StreamPoint kArg = kPos;
            pRider->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
            if (FUN_1416749c0(m_pOwner) != 0)
                pRider->vfunc_59(2, 0, 0, 0);
            else
                FUN_1417b9460();
        }
    }
}

// @0x1417fdae0
void StateTaxiCall::vfunc_6()
{
    if (FUN_1417b8370() != 0 && m_n10 != 0x69)
    {
        FUN_1417b8370()->vfunc_59(1, 0, 0, 0);
        FUN_1417b8370()->vfunc_23(0);
    }
}

// @0x1417fdb70
int StateTaxiCall::FUN_1417fdb70()
{
    if (m_spData.get() != 0)
        return m_spData->m_nTaxiId;
    return 0;
}

// @0x1417fdbc0
void StateTaxiCall::FUN_1417fdbc0(int nState, int nAdd)
{
    m_n10 = nState;
    m_nEnd += nAdd;
}

// @0x1417fdc00
// MS2-FUNCTIONAL: transliterated from the decompile (effect request / transform stand-ins)
void StateTaxiCall::FUN_1417fdc00(const CString& strEffect)
{
    Unk_StreamPoint kPos;
    Unk_StreamPoint kRot;
    NiTransform xf;
    PCBase* pPC = FUN_1417b8370();
    NiPoint3 kOwnerNi = pPC->vfunc_18();
    Unk_StreamPoint kOwner = reinterpret_cast<Unk_StreamPoint&>(kOwnerNi);
    float fRange = *FUN_140298f40(&static_cast<Client::Constants*>(FUN_1401d3200())->TaxiStationFindDistance) + 100.0f;
    Unk_TcEntity* pStop = FUN_1403ed2d0()->FUN_141bcfd30(0x85359406, kOwner, fRange, 1, 0);
    if (pStop == 0)
    {
        NiPoint3 kDirNi = pPC->vfunc_20();
        kRot = reinterpret_cast<Unk_StreamPoint&>(kDirNi);
        efd::Matrix3 kMat;
        kMat.MakeZRotation((kRot.z * 3.1415927f) / 180.0f);
        Unk_StreamPoint kDir = FUN_1420834e0(DAT_143a08ce8.FUN_1409f7960(), kMat);
        xf.MakeIdentity();
        Unk_StreamPoint kAhead = kDir.FUN_14097fc90(150.0f);
        NiPoint3 kNowNi = pPC->vfunc_18();
        Unk_StreamPoint kSum = reinterpret_cast<Unk_StreamPoint&>(kNowNi).FUN_14097fd50(kAhead);
        FUN_14097faa0(&xf.m_Translate, reinterpret_cast<const NiPoint3*>(&kSum));
    }
    else
    {
        FUN_1409618c0(pStop, 0xfd95ca52, &kPos);
        FUN_1409618c0(pStop, 0x68c7c29d, &kRot);
        efd::Matrix3 kMat;
        kMat.MakeZRotation((kRot.z * 3.1415927f) / 180.0f);
        Unk_StreamPoint kDir = FUN_1420834e0(DAT_143a08ce8, kMat);
        xf.MakeIdentity();
        Unk_StreamPoint kAhead = kDir.FUN_14097fc90(150.0f).FUN_14097fc90(2.0f);
        Unk_StreamPoint kSum = kPos.FUN_14097fd50(kAhead);
        FUN_14097faa0(&xf.m_Translate, reinterpret_cast<const NiPoint3*>(&kSum));
    }
    float fAngle = ((180.0f - kRot.z) * 3.1415927f) / 180.0f;
    if (!m_bSurprise)
        fAngle = fAngle - 1.5707964f;
    xf.m_Rotate.FromEulerAnglesXYZ(0.0f, 0.0f, fAngle);
    Unk_TcRequest request;
    FUN_140a52ef0(&request);
    request.m_strName = strEffect;
    request.m_nKind = (FUN_1417b8560() == 0) ? 3 : 1;
    request.m_pXform = &xf;
    FUN_1403ed280()->FUN_1411a4a00(&request);
    FUN_1405a89e0(&request);
}

// @0x1417fe260
MS2Ptr<StateData> StateTaxiCall::vfunc_27()
{
    return MS2Ptr<StateData>(new StateTaxiCallData());
}

// @0x1417fe2e0
int StateTaxiCall::vfunc_20()
{
    return 1;
}

// @0x1417fe2f0
int StateTaxiCall::vfunc_1()
{
    return 0x25;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb8280-0x142cb82a0 .text$yd
