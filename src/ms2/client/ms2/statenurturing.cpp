// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The housing-cube pet states StateNurturing,
// StateInterActionSpawnObject and StateIdleSpawnObject, the ICastingEventListener ctor. See statenurturing.h.
// MS2-UNIT: ?\statenurturing.cpp
// MS2-RANGE: 0x140ac08e0-0x140ac3b40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ?OnCastingFinished@ICastingEventListener@@UEAAXXZ 0x140ac3240
// MS2-PIN: ?Read@?$Value@I@Constants@Common@@QEAAIXZ 0x140ac2250
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statenurturing.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <float.h>
#include <errno.h>
#include <string.h>

#include "statenurturing.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/cubespawnobject.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders ----

extern Unk_StreamPoint DAT_143b01a60;                    // the zero point

// A PCBase seen through its slot 18 (the position, returned as the 12-byte point of the FUN_ operators).
class Unk_NuPos
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
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
    virtual Unk_StreamPoint vfunc_18();
};

// The casting bar request (FUN_1418e12b0): duration, flags, speed and four texts (+0x28 the label).
struct Unk_CastInfo
{
    Unk_CastInfo();                                      // 0x140ac2eb0
    ~Unk_CastInfo();                                     // 0x140ac3070
    int m_nDuration;                                     // +0x00
    bool m_b4;                                           // +0x04
    bool m_b5;                                           // +0x05 (set)
    float m_f8;                                          // +0x08
    float m_fC;                                          // +0x0c (1.0)
    int m_n10;                                           // +0x10
    CStringW m_str18;                                    // +0x18 "show"
    CStringW m_str20;                                    // +0x20 "yellow"
    CStringW m_str28;                                    // +0x28 label
    CStringW m_str30;                                    // +0x30
};
MS2_CHECK_SIZE(Unk_CastInfo, 0x38);

// The casting bar dialog (RTTI UICastingBar, found through FUN_140ac2270).
class UICastingBar : public UIObject
{
public:
    void FUN_1418e12b0(ICastingEventListener* pListener, Unk_CastInfo& kInfo);   // show
    void FUN_1418e1390();                                                        // cancel
};

// The use-request of one cube (id + count), serialized by FUN_1401fc610.
struct Unk_FcUseInfo
{
    Unk_FcUseInfo();                                     // 0x140ac2e80
    ~Unk_FcUseInfo();                                    // 0x140ac3050
    CString m_strId;                                     // +0x00
    int m_nCount;                                        // +0x08
    int m_nPad0c;
};
void FUN_1401fc610(Unk_FcUseInfo* pInfo, COutPacket* pPacket);   // serialize

// The UI manager: a UI object by dialog id, held in a counted reference (uses FUN_141adcea0 of the UI service).
class Unk_NuUiRef
{
public:
    ~Unk_NuUiRef();                                      // 0x1403e5630
    UIObject* FUN_1403e8a70() const;
private:
    void* unknown;
    UIObject* object;
};
MS2_CHECK_SIZE(Unk_NuUiRef, 0x10);
class Unk_NuUiMgr { public: Unk_NuUiRef FUN_141adcea0(int nId); };
Unk_NuUiMgr* FUN_1403ed2b0();
UIObject* FUN_1403ed9e0(Unk_NuUiRef& ref);
UICastingBar* FUN_140ac2270(int nId);

void* FUN_14165f100(PCBase* p);
void FUN_14165f170(PCBase* p);
class Unk_NuBuffMgr { public: Unk_StreamPoint FUN_141683290(); };
Unk_NuBuffMgr* FUN_14166d240(PCBase* p);
bool FUN_1416749c0(PCBase* p);
int FUN_1408a1360(Unk_StreamPoint a, Unk_StreamPoint b);
CStringW GetStringCommonByKey(const CStringW& str);
CFunctionCubeService* FUN_1409670b0();

// ---- the casting bar lookup ----

// @0x140ac2270
UICastingBar* FUN_140ac2270(int nId)
{
    if (FUN_1403ed2b0())
    {
        Unk_NuUiRef ref = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UICastingBar*>(FUN_1403ed9e0(ref));
    }
    return 0;
}
MS2_REPLACE(0x140AC2270, FUN_140ac2270, 147, 0x24834FA8);

// ---- Unk_FcUseInfo ----

// @0x140ac2e80
Unk_FcUseInfo::Unk_FcUseInfo() : m_nCount(0) {}

// @0x140ac3050
Unk_FcUseInfo::~Unk_FcUseInfo() {}

// ---- Unk_CastInfo ----

// @0x140ac2eb0
Unk_CastInfo::Unk_CastInfo()
    : m_nDuration(0), m_b4(false), m_b5(true), m_f8(0.0f), m_fC(1.0f), m_n10(0)
{
    m_str20 = "yellow";
    m_str18 = "show";
}

// @0x140ac3070
Unk_CastInfo::~Unk_CastInfo() {}

// ---- ICastingEventListener ----

// @0x140ac2e60
ICastingEventListener::ICastingEventListener() {}

// ---- StateNurturing ----

// @0x140ac08e0
StateNurturing::StateNurturing(PCBase* pOwner) : State(pOwner), m_n48(0) {}

// @0x140ac0980
StateNurturing::~StateNurturing() {}

// @0x140ac3230
int StateNurturing::vfunc_1() { return 0x40; }

// @0x140ac09e0
void StateNurturing::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n48 = 0;
    m_pOwner->FUN_14166dd20(FUN_140ac13a0(), 1.0f, false, false);
    PCBase* pPC = FUN_1417b8370();
    MyPC* pRider = FUN_1417b84b0();
    if (pPC && FUN_14165f100(pPC))
        FUN_14165f170(pPC);
    if (pRider)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
        {
            Unk_CastInfo kInfo;
            FUN_140ac1480(&kInfo);
            pBar->FUN_1418e12b0(this, kInfo);
        }
    }
    if (pPC)
    {
        m_spTarget = 0;
        m_aCubes.clear();
        ATL::CAtlArray<MS2Ptr<CNurturingCubeObject> > aCubes;
        FUN_1409670b0()->FUN_141232810(aCubes);
        float fNearest = FLT_MAX;
        for (size_t i = 0; i < aCubes.GetCount(); i++)
        {
            MS2Ptr<CNurturingCubeObject> spCube = aCubes[i];
            float fDist = reinterpret_cast<Unk_NuPos*>(pPC)->vfunc_18().FUN_140965c40(spCube->FUN_141226d00()).FUN_140967ac0();
            bool bUsable = fDist < *static_cast<Client::Constants*>(FUN_1401d3200())->MasteryObjectInteractionDistance.Get();
            if (FUN_1408a1360(reinterpret_cast<Unk_NuPos*>(pPC)->vfunc_18(), spCube->FUN_141226d00()) == 0)
                bUsable = false;
            if (spCube->FUN_140967140() != static_cast<unsigned char>(bUsable))
                spCube->FUN_1412277d0(bUsable);
            if (bUsable)
            {
                if (pRider)
                {
                    if (!spCube->FUN_14122bda0())
                        continue;
                    m_aCubes.push_back(spCube);
                }
                if (fDist < fNearest)
                {
                    m_spTarget = spCube;
                    fNearest = fDist;
                }
            }
        }
        if (m_spTarget)
        {
            efd::SmartPointer<CubeSpawnObject> spPet = m_spTarget->GetValue();
            if (spPet)
                spPet->vfunc_59(0x19, 0, m_n10, 0);
        }
    }
    if (pRider)
        SendFunctionCubeMode4();
}
MS2_REPLACE_METHOD(0x140AC09E0, StateNurturing, vfunc_4, 1311, 0xC5A62994);

// @0x140ac0f10
void StateNurturing::vfunc_7(int n)
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC)
    {
        pPC->vfunc_23(0);
        pPC->vfunc_59(n, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x140AC0F10, StateNurturing, vfunc_7, 99, 0xCE581364);

// @0x140ac0f80
void StateNurturing::vfunc_5(int n)
{
    if (FUN_1417b8560())
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
            pBar->FUN_1418e1390();
    }
    State::vfunc_5(n);
    PCBase* pPC = FUN_1417b8370();
    if (pPC)
    {
        pPC->vfunc_23(0);
        MS2Ptr<CNurturingCubeObject> spTarget = m_spTarget;
        if (spTarget)
        {
            efd::SmartPointer<CubeSpawnObject> spPet = spTarget->GetValue();
            if (spPet)
                spPet->vfunc_59(1, 0, 0xa2, 0);
        }
    }
}
MS2_REPLACE_METHOD(0x140AC0F80, StateNurturing, vfunc_5, 306, 0x16327DE0);

// @0x140ac10c0
void StateNurturing::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Unk_StreamPoint kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
    if (m_n48 != 0)
    {
        MyPC* pRider = FUN_1417b84b0();
        if (pRider)
        {
            UICastingBar* pBar = FUN_140ac2270(0x4e72);
            if (pBar)
                pBar->FUN_1418e1390();
            SendFunctionCubeMode5();
        }
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x140AC10C0, StateNurturing, vfunc_3, 245, 0xD3F33937);

// MS2-FUNCTIONAL: stack-slot/temporary placement of the Unk_StreamPoint copies differs
// @0x140ac11c0
void StateNurturing::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        Unk_NuBuffMgr* pBuff = FUN_14166d240(pPC);
        Unk_StreamPoint kPos = pBuff->FUN_141683290();
        Unk_StreamPoint kArg = kPos;
        pPC->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
        if (FUN_1416749c0(m_pOwner))
            pPC->vfunc_59(2, 0, 0, 0);
    }
}

// @0x140ac12a0
void StateNurturing::OnCastingFinished() { m_n48 = 1; }

// @0x140ac12c0
void StateNurturing::EndOfSequence(NiActorManager*, unsigned int, NiControllerSequence*, float)
{
    if (m_pOwner)
    {
        m_pOwner->FUN_14166dd20(FUN_140ac13a0(), 1.0f, true, false);
    }
}
MS2_REPLACE_METHOD(0x140AC12C0, StateNurturing, EndOfSequence, 163, 0xB108BB78);

// @0x140ac1370
unsigned StateNurturing::FUN_140ac1370()
{
    unsigned nDuration = static_cast<Client::Constants*>(FUN_1401d3200())->NurturingDuration.Read();
    return nDuration;
}
MS2_REPLACE_METHOD(0x140AC1370, StateNurturing, FUN_140ac1370, 41, 0x32A092A2);

// MS2-FUNCTIONAL: by-value utf8string return flag pattern differs
// @0x140ac13a0
efd::utf8string StateNurturing::FUN_140ac13a0()
{
    if (m_n10 == 0xa7)
        return efd::utf8string("Functobj_Gift_A01");
    else if (m_n10 == 0xa5)
        return efd::utf8string("Functobj_Feed_A01");
    else if (m_n10 == 0xa6)
        return efd::utf8string("Functobj_Play_A01");
    else
        return efd::utf8string("Object_React_C");
}

// MS2-FUNCTIONAL: branch layout and stack slots differ
// @0x140ac1480
void StateNurturing::FUN_140ac1480(Unk_CastInfo* pInfo)
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        pInfo->m_nDuration = FUN_140ac1370();
        if (m_n10 == 0xa7)
            pInfo->m_str28 = GetStringCommonByKey(CStringW(L"s_action_nurturing_gifting"));
        else if (m_n10 == 0xa5)
            pInfo->m_str28 = GetStringCommonByKey(CStringW(L"s_action_nurturing_eating"));
        else if (m_n10 == 0xa6)
            pInfo->m_str28 = GetStringCommonByKey(CStringW(L"s_action_nurturing_playing"));
    }
}

// @0x140ac1650
MS2Ptr<CNurturingCubeObject> StateNurturing::FUN_140ac1650()
{
    PCBase* pPC = FUN_1417b8370();
    if (!pPC)
        return MS2Ptr<CNurturingCubeObject>(0);
    ATL::CAtlArray<MS2Ptr<CNurturingCubeObject> > aCubes;
    FUN_1409670b0()->FUN_141232810(aCubes);
    float fNearest = FLT_MAX;
    MS2Ptr<CNurturingCubeObject> spNearest(0);
    for (size_t i = 0; i < aCubes.GetCount(); i++)
    {
        MS2Ptr<CNurturingCubeObject> spCube = aCubes[i];
        float fDist = reinterpret_cast<Unk_NuPos*>(pPC)->vfunc_18().FUN_140965c40(spCube->FUN_141226d00()).FUN_140967ac0();
        bool bUsable = fDist < *static_cast<Client::Constants*>(FUN_1401d3200())->MasteryObjectInteractionDistance.Get();
        if (FUN_1408a1360(reinterpret_cast<Unk_NuPos*>(pPC)->vfunc_18(), spCube->FUN_141226d00()) == 0)
            bUsable = false;
        if (spCube->FUN_140967140() != static_cast<unsigned char>(bUsable))
            spCube->FUN_1412277d0(bUsable);
        if (bUsable && fDist < fNearest)
        {
            spNearest = spCube;
            fNearest = fDist;
        }
    }
    return spNearest;
}
MS2_REPLACE_METHOD(0x140AC1650, StateNurturing, FUN_140ac1650, 723, 0xEE67D063);

// @0x140ac1930
void StateNurturing::SendFunctionCubeMode4()
{
    COutPacket kPacket(static_cast<int>(SendOp::FunctionCube), 0);
    kPacket.WriteUInt8(4);
    kPacket.WriteInt32(static_cast<int>(m_aCubes.size()));
    for (size_t i = 0; i < m_aCubes.size(); i++)
    {
        Unk_FcUseInfo kInfo;
        kInfo.m_strId = m_aCubes[i]->FUN_141226bd0();
        kInfo.m_nCount = 1;
        FUN_1401fc610(&kInfo, &kPacket);
    }
    FUN_140710590(kPacket);
}
MS2_REPLACE_METHOD(0x140AC1930, StateNurturing, SendFunctionCubeMode4, 307, 0x073FD4BB);

// @0x140ac1a70
void StateNurturing::SendFunctionCubeMode5()
{
    std::vector<MS2Ptr<CNurturingCubeObject> > aUsable;
    for (size_t i = 0; i < m_aCubes.size(); i++)
    {
        if (!m_aCubes[i]->FUN_14122bda0())
            continue;
        aUsable.push_back(m_aCubes[i]);
    }
    COutPacket kPacket(static_cast<int>(SendOp::FunctionCube), 0);
    kPacket.WriteUInt8(5);
    kPacket.WriteInt32(static_cast<int>(aUsable.size()));
    for (size_t i = 0; i < aUsable.size(); i++)
    {
        Unk_FcUseInfo kInfo;
        kInfo.m_strId = aUsable[i]->FUN_141226bd0();
        kInfo.m_nCount = 1;
        FUN_1401fc610(&kInfo, &kPacket);
    }
    FUN_140710590(kPacket);
}
MS2_REPLACE_METHOD(0x140AC1A70, StateNurturing, SendFunctionCubeMode5, 437, 0x753987F1);

// ---- StateInterActionSpawnObject ----

// @0x140ac1c30
StateInterActionSpawnObject::StateInterActionSpawnObject(CubeSpawnObject* pOwner) : State(pOwner) {}

// @0x140ac1c70
StateInterActionSpawnObject::~StateInterActionSpawnObject() {}

// @0x140ac3220
int StateInterActionSpawnObject::vfunc_1() { return 0x19; }

// @0x140ac1ca0
void StateInterActionSpawnObject::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    CubeSpawnObject* pCube = FUN_140ac1de0();
    if (pCube)
    {
        if (m_n10 == 0xa7)
            pCube->FUN_140a4f2b0(100);
        else if (m_n10 == 0xa5)
            pCube->FUN_140a4f2b0(0x67);
        else if (m_n10 == 0xa6)
            pCube->FUN_140a4f2b0(0x65);
    }
}
MS2_REPLACE_METHOD(0x140AC1CA0, StateInterActionSpawnObject, vfunc_4, 148, 0x1EA41B91);

// @0x140ac1d40
void StateInterActionSpawnObject::vfunc_5(int n)
{
    State::vfunc_5(n);
    CubeSpawnObject* pCube = FUN_140ac1de0();
    if (pCube)
    {
        if (m_n10 == 0xa7)
            pCube->FUN_140a4f3f0(100);
        else if (m_n10 == 0xa5)
            pCube->FUN_140a4f3f0(0x67);
        else if (m_n10 == 0xa6)
            pCube->FUN_140a4f3f0(0x65);
    }
}
MS2_REPLACE_METHOD(0x140AC1D40, StateInterActionSpawnObject, vfunc_5, 146, 0xFF86A32D);

// @0x140ac1de0
CubeSpawnObject* StateInterActionSpawnObject::FUN_140ac1de0()
{
    return dynamic_cast<CubeSpawnObject*>(m_pOwner);
}
MS2_REPLACE_METHOD(0x140AC1DE0, StateInterActionSpawnObject, FUN_140ac1de0, 52, 0x990330BD);

// ---- StateIdleSpawnObject ----

// @0x140ac1e20
StateIdleSpawnObject::StateIdleSpawnObject(CubeSpawnObject* pOwner) : State(pOwner)
{
    m_n10 = 0xa2;
}

// @0x140ac1e90
StateIdleSpawnObject::~StateIdleSpawnObject() {}

// @0x140ac3210
int StateIdleSpawnObject::vfunc_1() { return 1; }

// @0x140ac1ec0
void StateIdleSpawnObject::vfunc_2(int n)
{
    State::vfunc_2(n);
    if (n == 0xa8)
    {
        CubeSpawnObject* pCube = FUN_140ac21e0();
        if (pCube)
        {
            pCube->FUN_140a4f2b0(0x62);
            pCube->FUN_140a4f3f0(0x62);
        }
    }
}
MS2_REPLACE_METHOD(0x140AC1EC0, StateIdleSpawnObject, vfunc_2, 95, 0x555B3AAA);

// @0x140ac1f30
void StateIdleSpawnObject::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    CubeSpawnObject* pCube = FUN_140ac21e0();
    if (!pCube)
        return;
    if (pCube->FUN_140a4f690() != 0)
    {
        switch (m_n10)
        {
        case 0xa2:
            m_n10 = 0xa3;
            pCube->FUN_140a4f2b0(99);
            pCube->FUN_140a4f3f0(99);
            break;
        case 0xa8:
            pCube->FUN_140a4f2b0(0x62);
            pCube->FUN_140a4f3f0(0x62);
            break;
        }
    }
    else
    {
        m_n10 = 0xa3;
        pCube->FUN_140a4f2b0(99);
        pCube->FUN_140a4f3f0(99);
    }
}
MS2_REPLACE_METHOD(0x140AC1F30, StateIdleSpawnObject, vfunc_4, 228, 0xED8B4C01);

// @0x140ac2020
void StateIdleSpawnObject::vfunc_5(int n)
{
    State::vfunc_5(n);
}
MS2_REPLACE_METHOD(0x140AC2020, StateIdleSpawnObject, vfunc_5, 32, 0xB391CF41);

// @0x140ac2050
void StateIdleSpawnObject::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    CubeSpawnObject* pCube = FUN_140ac21e0();
    if (pCube)
    {
        if (m_timer.FUN_140268870(60000))
        {
            switch (m_n10)
            {
            case 0xa2:
                pCube->FUN_140a4f3f0(0x5a);
                break;
            case 0xa4:
                pCube->FUN_140a4f3f0(0x66);
                break;
            case 0xa3:
                pCube->FUN_140a4f3f0(99);
                break;
            }
        }
        if (pCube->FUN_140a4f690() != 0)
        {
            if (m_n10 != 0xa8 && m_n10 != 0xa3)
            {
                m_n10 = 0xa3;
                pCube->FUN_140a4f2b0(99);
                pCube->FUN_140a4f3f0(99);
            }
        }
        else if (m_n10 != 0xa3)
        {
            m_n10 = 0xa3;
            pCube->FUN_140a4f2b0(99);
            pCube->FUN_140a4f3f0(99);
        }
    }
}
MS2_REPLACE_METHOD(0x140AC2050, StateIdleSpawnObject, vfunc_3, 324, 0xE6C74D45);

// @0x140ac21a0
void StateIdleSpawnObject::EndOfSequence(NiActorManager*, unsigned int, NiControllerSequence*, float)
{
    if (m_n10 == 0xa8)
        m_n10 = 0xa2;
}
MS2_REPLACE_METHOD(0x140AC21A0, StateIdleSpawnObject, EndOfSequence, 47, 0x29DCDDED);

// @0x140ac21e0
CubeSpawnObject* StateIdleSpawnObject::FUN_140ac21e0()
{
    return dynamic_cast<CubeSpawnObject*>(m_pOwner);
}
MS2_REPLACE_METHOD(0x140AC21E0, StateIdleSpawnObject, FUN_140ac21e0, 52, 0x81C5DAE1);

// The UCRT header-inline memcpy_s (corecrt_memcpy_s.h) closes the obj's COMDAT tail; the exe calls memset/memcpy here.
#pragma function(memcpy, memset)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode) \
    { int _Expr_val = !!(expr); if (!(_Expr_val)) { errno = errorcode; _invalid_parameter_noinfo(); return errorcode; } }
// @0x140ac3a20
errno_t FUN_140ac3a20(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0) return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    if (src == NULL || dstSize < srcSize) {
        memset(dst, 0, dstSize);
        MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
        MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
        return EINVAL;
    }
    memcpy(dst, src, srcSize);
    return 0;
}
