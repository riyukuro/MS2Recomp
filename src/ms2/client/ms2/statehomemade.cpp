// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The homemade-cube harvest state StateHomemade and the
// std::vector<MS2Ptr<CHomemadeCubeObject>> glue it instantiates. See statehomemade.h.
// MS2-UNIT: ?\statehomemade.cpp
// MS2-RANGE: 0x140ca4360-0x140ca6fc0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$construct@V?$MS2Ptr@VCHomemadeCubeObject@@@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCHomemadeCubeObject@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCHomemadeCubeObject@@@@@1@QEAV?$MS2Ptr@VCHomemadeCubeObject@@@@AEAV3@@Z 0x140ca5f30 ; unique
// MS2-PIN: ??$construct@V?$MS2Ptr@VCHomemadeCubeObject@@@@AEBV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2Ptr@VCHomemadeCubeObject@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2Ptr@VCHomemadeCubeObject@@@@@1@QEAV?$MS2Ptr@VCHomemadeCubeObject@@@@AEBV3@@Z 0x140ca5f80 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateHomemadeData@@@@QEAAAEAV1@PEAVStateHomemadeData@@@Z 0x140ca63a0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VStateHomemadeData@@@@QEBAPEAVStateHomemadeData@@XZ 0x140ca6480 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statehomemade.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <float.h>
#include <errno.h>
#include <string.h>
#include <new>

#include "statehomemade.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statedata.h"
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
class Unk_HmPos
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
struct Unk_HmCastInfo
{
    Unk_HmCastInfo()
        : m_nDuration(0), m_b4(false), m_b5(true), m_f8(0.0f), m_fC(1.0f), m_n10(0)
    {
        m_str20 = "yellow";
        m_str18 = "show";
    }                                                    // 0x140ac2eb0
    ~Unk_HmCastInfo() {}                                 // 0x140ac3070
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
MS2_CHECK_SIZE(Unk_HmCastInfo, 0x38);

// The casting bar dialog (RTTI UICastingBar, found through FUN_140ac2270).
class UICastingBar : public UIObject
{
public:
    void FUN_1418e12b0(ICastingEventListener* pListener, Unk_HmCastInfo& kInfo);   // show
    void FUN_1418e1390();                                                          // cancel
};
UICastingBar* FUN_140ac2270(int nId);

// The use-request of one cube (id + count), serialized by FUN_1401fc610.
struct Unk_HmUseInfo
{
    Unk_HmUseInfo() : m_nCount(0) {}                     // 0x140ac2e80
    ~Unk_HmUseInfo() {}                                  // 0x140ac3050
    CString m_strId;                                     // +0x00
    int m_nCount;                                        // +0x08
    int m_nPad0c;
};
void FUN_1401fc610(Unk_HmUseInfo* pInfo, COutPacket* pPacket);   // serialize

// The cursor manager scales a duration (shared with the interact objects).
class Unk_HmCursorMgr { public: int FUN_1404240e0(int n); };
Unk_HmCursorMgr* FUN_1403ef660(void* p);
void* FUN_140302b00();

// The gathering table service: how the cube's kind may be gathered.
class Unk_HmGatherMgr { public: int FUN_14066bc40(int nId); };
Unk_HmGatherMgr* FUN_1409670c0();

// The equipment of a player: the worn item of a slot.
class Unk_HmEquip { public: MS2Ptr<CGemBase> FUN_141270740(int nSlot); };
Unk_HmEquip* FUN_14165f460(PCBase* p);

void* FUN_14165f100(PCBase* p);
void FUN_14165f170(PCBase* p);
class Unk_HmBuffMgr { public: Unk_StreamPoint FUN_141683290(); };
Unk_HmBuffMgr* FUN_14166d240(PCBase* p);
bool FUN_1416749c0(PCBase* p);
int FUN_1408a1360(Unk_StreamPoint a, Unk_StreamPoint b);
CStringW GetStringCommonByKey(const CStringW& str);
CFunctionCubeService* FUN_1409670b0();
__int64 FUN_141656ad0(PCBase* p);

// The homemade cube seen through the data copy this unit inlines (its COMDAT sits at 0x140ca6580).
class Unk_HmCube : public CHomemadeCubeObject
{
public:
    // @0x140ca6580
    MS2Ptr<FunctionCubeData> FUN_140ca6580() { return m_spData; }
};

// ---- StateHomemade ----

// @0x140ca4360
StateHomemade::StateHomemade(PCBase* pOwner) : State(pOwner), m_n48(0) {}

// @0x140ca4400
StateHomemade::~StateHomemade() {}

// @0x140ca4460
// MS2-FUNCTIONAL: the exe's temporary lifetimes around the cast info and the animation name differ (3 more EH states, larger frame)
void StateHomemade::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n48 = 0;
    m_pOwner->FUN_14166dd20(FUN_140ca4e50(), 1.0f, false, false);
    m_spHarvest.AssignRaw(dynamic_cast<StateHomemadeData*>(pData));
    PCBase* pPC = FUN_1417b8370();
    if (pPC && FUN_14165f100(pPC))
        FUN_14165f170(pPC);
    MyPC* pRider = FUN_1417b84b0();
    if (pRider && m_n10 == 0x8f)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
        {
            Unk_HmCastInfo kInfo;
            FUN_140ca4f30(&kInfo);
            pBar->FUN_1418e12b0(this, kInfo);
        }
        m_aCubes.clear();
        ATL::CAtlArray<MS2Ptr<CHomemadeCubeObject> > aCubes;
        FUN_1409670b0()->FUN_141232660(aCubes, FUN_141656ad0(pRider));
        for (size_t i = 0; i < aCubes.GetCount(); i++)
        {
            if (aCubes[i]->FUN_141229000(0) != 0)
            {
                float fDist = reinterpret_cast<Unk_HmPos*>(m_pOwner)->vfunc_18().FUN_140965c40(aCubes[i]->FUN_141226d00()).FUN_140967ac0();
                if (fDist <= *static_cast<Client::Constants*>(FUN_1401d3200())->MasteryObjectInteractionDistance.Get())
                {
                    Unk_StreamPoint kCube = aCubes[i]->FUN_141226d00();
                    Unk_StreamPoint kRider = reinterpret_cast<Unk_HmPos*>(pRider)->vfunc_18();
                    if (FUN_1408a1360(kRider, kCube) != 0)
                        m_aCubes.push_back(aCubes[i]);
                }
            }
        }
        if (m_aCubes.size() != 0)
            SendFunctionCubeMode4();
    }
}
MS2_REPLACE_METHOD(0x140CA4460, StateHomemade, vfunc_4, 1105, 0xF92EE577);

// @0x140ca48c0
void StateHomemade::vfunc_7(int n)
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC)
    {
        pPC->vfunc_23(0);
        pPC->vfunc_59(n, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x140CA48C0, StateHomemade, vfunc_7, 99, 0x8E32E008);

// @0x140ca4930
void StateHomemade::vfunc_5(int n)
{
    if (FUN_1417b8560())
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
            pBar->FUN_1418e1390();
    }
    State::vfunc_5(n);
    m_spHarvest = 0;
    if (FUN_1417b8370())
    {
        PCBase* pPC = FUN_1417b8370();
        pPC->vfunc_23(0);
    }
}
MS2_REPLACE_METHOD(0x140CA4930, StateHomemade, vfunc_5, 149, 0x2AE037AA);

// @0x140ca49d0
void StateHomemade::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    MyPC* pPC;
    Unk_StreamPoint kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
    if (m_n48 != 0)
    {
        pPC = FUN_1417b84b0();
        if (pPC)
        {
            UICastingBar* pBar = FUN_140ac2270(0x4e72);
            if (pBar)
                pBar->FUN_1418e1390();
            SendFunctionCubeMode5();
        }
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x140CA49D0, StateHomemade, vfunc_3, 245, 0x5E8FBA71);

// @0x140ca4ad0
// MS2-FUNCTIONAL: the exe holds the buffer manager's returned point in the upper frame slot and copies it down to the argument slot
void StateHomemade::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    if (m_n10 == 0x92 && FUN_140ca4fd0(1) != 0 && m_spHarvest.get() != 0)
    {
        MS2Ptr<StateHomemadeData> spData(new StateHomemadeData(m_spHarvest->m_n24, CString(m_spHarvest->m_str), m_spHarvest->m_n20));
        pPC->vfunc_59(0x37, spData.get(), 0x8f, 0);
    }
    Unk_HmBuffMgr* pBuff = FUN_14166d240(pPC);
    Unk_StreamPoint kPos = pBuff->FUN_141683290();
    Unk_StreamPoint kArg = kPos;
    pPC->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
    if (FUN_1416749c0(m_pOwner))
        pPC->vfunc_59(2, 0, 0, 0);
}
MS2_REPLACE_METHOD(0x140CA4AD0, StateHomemade, vfunc_8, 600, 0xE8474A38);

// @0x140ca4d30
void StateHomemade::OnCastingFinished() { m_n48 = 1; }
MS2_REPLACE_METHOD(0x140CA4D30, StateHomemade, OnCastingFinished, 18, 0x0C6F59A0);

// @0x140ca4d50
void StateHomemade::EndOfSequence(NiActorManager*, unsigned int, NiControllerSequence*, float)
{
    if (m_n10 != 0x8f)
    {
        if (FUN_140ca4fd0(0) != 0)
        {
            m_n10 = 0x92;
            m_pOwner->FUN_14166dda0(0);
        }
        else
            m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x140CA4D50, StateHomemade, EndOfSequence, 135, 0x0486B9B6);

// @0x140ca4de0
bool StateHomemade::vfunc_25(int, void*) { return false; }
MS2_REPLACE_METHOD(0x140CA4DE0, StateHomemade, vfunc_25, 17, 0xFFB1988B);

// @0x140ca4e00
int StateHomemade::FUN_140ca4e00()
{
    unsigned nDuration = static_cast<Client::Constants*>(FUN_1401d3200())->HarvestDuration.Read();
    return FUN_1403ef660(FUN_140302b00())->FUN_1404240e0(nDuration);
}
MS2_REPLACE_METHOD(0x140CA4E00, StateHomemade, FUN_140ca4e00, 62, 0xFE21669A);

// @0x140ca4e50
efd::utf8string StateHomemade::FUN_140ca4e50()
{
    if (m_n10 == 0x8f)
        return efd::utf8string("Object_React_C");
    if (m_n10 == 0x90)
        return efd::utf8string("Breed_End_A");
    if (m_n10 == 0x91)
        return efd::utf8string("Breed_End_B");
    return efd::utf8string("Breed_Idle_A");
}
MS2_REPLACE_METHOD(0x140CA4E50, StateHomemade, FUN_140ca4e50, 210, 0xF4D23BAD);

// @0x140ca4f30
void StateHomemade::FUN_140ca4f30(Unk_HmCastInfo* pInfo)
{
    pInfo->m_nDuration = FUN_140ca4e00();
    CStringW strLabel(L"s_action_harvesting");
    pInfo->m_str28 = GetStringCommonByKey(strLabel);
}
MS2_REPLACE_METHOD(0x140CA4F30, StateHomemade, FUN_140ca4f30, 141, 0x30E1B0EA);

// @0x140ca4fd0
// MS2-FUNCTIONAL: the exe's cube loop carries more temporaries (26 vs 16 EH state transitions); layout and calls are equivalent
int StateHomemade::FUN_140ca4fd0(int nMode)
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
        return 0;
    MS2Ptr<CGemBase> spGem = FUN_14165f460(pRider)->FUN_141270740(9);
    if (!spGem)
        return 0;
    ATL::CAtlArray<MS2Ptr<CHomemadeCubeObject> > aCubes;
    FUN_1409670b0()->FUN_141232660(aCubes, FUN_141656ad0(pRider));
    for (size_t i = 0; i < aCubes.GetCount(); i++)
    {
        MS2Ptr<CHomemadeCubeObject> spCube = aCubes[i];
        if (nMode == 0 || spCube->FUN_141229000(1) != 0)
        {
            float fDist = reinterpret_cast<Unk_HmPos*>(m_pOwner)->vfunc_18().FUN_140965c40(spCube->FUN_141226d00()).FUN_140967ac0();
            if (fDist <= *static_cast<Client::Constants*>(FUN_1401d3200())->MasteryObjectInteractionDistance.Get())
            {
                Unk_StreamPoint kCube = spCube->FUN_141226d00();
                Unk_StreamPoint kRider = reinterpret_cast<Unk_HmPos*>(pRider)->vfunc_18();
                if (FUN_1408a1360(kRider, kCube) != 0)
                {
                    if (!static_cast<Unk_HmCube*>(spCube.get())->FUN_140ca6580())
                    {
                        int nKind = static_cast<Unk_HmCube*>(spCube.get())->FUN_140ca6580()->m_n100;
                        if (FUN_1409670c0()->FUN_14066bc40(nKind) != 3)
                            return 1;
                    }
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CA4FD0, StateHomemade, FUN_140ca4fd0, 969, 0x67B2332E);

// @0x140ca53b0
void StateHomemade::SendFunctionCubeMode4()
{
    COutPacket kPacket(0x2e, 0);
    kPacket.vfunc_o10_1(4);
    kPacket.vfunc_o10_3(static_cast<int>(m_aCubes.size()));
    for (size_t i = 0; i < m_aCubes.size(); i++)
    {
        Unk_HmUseInfo kInfo;
        kInfo.m_strId = m_aCubes[i]->FUN_141226bd0();
        kInfo.m_nCount = 1;
        FUN_1401fc610(&kInfo, &kPacket);
    }
    FUN_140710590(kPacket);
}
MS2_REPLACE_METHOD(0x140CA53B0, StateHomemade, SendFunctionCubeMode4, 307, 0x455AA292);

// @0x140ca54f0
void StateHomemade::SendFunctionCubeMode5()
{
    std::vector<MS2Ptr<CHomemadeCubeObject> > aUsable;
    for (size_t i = 0; i < m_aCubes.size(); i++)
    {
        if (m_aCubes[i]->FUN_141229000(0) == 0)
            continue;
        aUsable.push_back(m_aCubes[i]);
    }
    COutPacket kPacket(0x2e, 0);
    kPacket.vfunc_o10_1(5);
    kPacket.vfunc_o10_3(static_cast<int>(aUsable.size()));
    for (size_t i = 0; i < aUsable.size(); i++)
    {
        Unk_HmUseInfo kInfo;
        kInfo.m_strId = aUsable[i]->FUN_141226bd0();
        kInfo.m_nCount = 1;
        FUN_1401fc610(&kInfo, &kPacket);
    }
    FUN_140710590(kPacket);
}
MS2_REPLACE_METHOD(0x140CA54F0, StateHomemade, SendFunctionCubeMode5, 442, 0xC4006477);

// @0x140ca64d0
MS2Ptr<StateData> StateHomemade::vfunc_27()
{
    return MS2Ptr<StateData>(new StateHomemadeData(0, CString(), 0));
}
MS2_REPLACE_METHOD(0x140CA64D0, StateHomemade, vfunc_27, 162, 0x538ECED7);

// @0x140ca65d0
int StateHomemade::vfunc_1() { return 0x37; }
MS2_REPLACE_METHOD(0x140CA65D0, StateHomemade, vfunc_1, 11, 0x00ACD632);
