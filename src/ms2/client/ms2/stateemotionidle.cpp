// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Actor states StateEmotion / StateEmotionIdle /
// StateTriggerEmotion / StateTriggerFollowNpc and their StateData payloads. See stateemotionidle.h.
// MS2-UNIT: client\ms2\stateemotionidle.cpp
// MS2-RANGE: 0x1417c3780-0x1417c6e40 .text$mn
// MS2-RANGE: 0x140101fe0-0x140102270 .text$di
// MS2-PIN: ??0?$MS2Ptr@VStateTriggerEmotionData@@@@QEAA@XZ 0x1417c5140
// MS2-PIN: ??8?$MS2Ptr@VStateDataTriggerFollowNpc@@@@QEBA_NPEAVStateDataTriggerFollowNpc@@@Z 0x1417c53b0
// MS2-PIN: ?get@?$MS2Ptr@VStateTriggerEmotionData@@@@QEBAPEAVStateTriggerEmotionData@@XZ 0x1417c5440
// MS2-PIN: ??C?$MS2Ptr@VStateTriggerEmotionData@@@@QEBAPEAVStateTriggerEmotionData@@XZ 0x1417c5470
// MS2-PIN: ??_GStateEmotionData@@UEAAPEAXI@Z 0x1417c5500
// MS2-PIN: ??8?$MS2Ptr@VStateEmotionIdleData@@@@QEBA_NPEAVStateEmotionIdleData@@@Z 0x1417c6bb0
// MS2-PIN: ??C?$MS2Ptr@VRideOffAction@@@@QEBAPEAVRideOffAction@@XZ 0x1417c6bf0
// MS2-PIN: ??C?$MS2Ptr@VStateEmotionIdleData@@@@QEBAPEAVStateEmotionIdleData@@XZ 0x1417c6c10
// MS2-PIN: ??_GStateEmotionIdle@@UEAAPEAXI@Z 0x1417c6c20
// MS2-PIN: ??_GStateEmotionIdleData@@UEAAPEAXI@Z 0x1417c6c60
// MS2-PIN: ??0?$MS2Ptr@VStateEmotionIdleData@@@@QEAA@PEAVStateEmotionIdleData@@@Z 0x1417c6a70
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateEmotionIdleData@@@@QEAAAEAV1@PEAVStateEmotionIdleData@@@Z 0x1417c6b40
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateDataTriggerFollowNpc@@@@QEAAAEAV1@PEAVStateDataTriggerFollowNpc@@@Z 0x1417c5260 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateEmotionData@@@@QEAAAEAV1@PEAVStateEmotionData@@@Z 0x1417c52d0 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateTriggerEmotionData@@@@QEAAAEAV1@PEAVStateTriggerEmotionData@@@Z 0x1417c5340 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VStateEmotionData@@@@QEBAPEAVStateEmotionData@@XZ 0x1417c5430 ; unique
// MS2-PIN: ??C?$MS2Ptr@VStateDataTriggerFollowNpc@@@@QEBAPEAVStateDataTriggerFollowNpc@@XZ 0x1417c5450 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VStateDataTriggerFollowNpc@@@@AEBAXPEAX@Z 0x1417c58a0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VStateEmotionData@@@@AEBAXPEAX@Z 0x1417c58d0 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VStateTriggerEmotionData@@@@AEBAXPEAX@Z 0x1417c5900 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VStateEmotionIdleData@@@@QEBAPEAVStateEmotionIdleData@@XZ 0x1417c6c00 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VStateEmotionIdleData@@@@AEBAXXZ 0x1417c6d30 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateemotionidle.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <egf/Entity.h>
#include <egf/FlatModel.h>

#include "stateemotionidle.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The unit includes the sort-name / skill / stun header statics a second time (without the condition object).
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";

// ---- unit-local placeholders ----

struct Vector3 { float x, y, z; };
extern Vector3 DAT_143b01a60;                    // the zero point

// StateData slots 1/2 argument: the state-sync record; +0x64 carries the emotion / npc id.
class Unk_StateDataArg
{
public:
    char m_pad_00[0x64];
    int m_n64;
};

// MS2Ptr<Unk_StateArg22> argument of slots 22/28 (a state request): +0x1c state sub id, +0x64 emotion id.
class Unk_StateArg22 : public CPtred
{
public:
    char m_pad_18[4];
    int m_n1c;
    char m_pad_20[0x44];
    int m_n64;
};
MS2_CHECK_OFFSET(Unk_StateArg22, m_n64, 0x64);

// Emotion table row (looked up by emotion id).
class Unk_EmoRow : public CPtred
{
public:
    int FUN_1407e9a60();                                 // row kind (0xe = emotion)
    CString FUN_1407e9cb0();                             // animation name
    char m_pad_18[0x18];
    int m_n30;                                           // +0x30 animation speed
};

class RideOffAction : public CPtred
{
public:
    char m_pad_18[0x10];
    int m_n28;                                           // +0x28
    int m_n2c;                                           // +0x2c
};
class RideOffActionTakeLR : public RideOffAction
{
public:
    RideOffActionTakeLR(int n);                          // 0x14077f9d0
};

// Buff container of an actor.
class Unk_BuffMgr
{
public:
    Vector3 FUN_141683290();                     // knock-back direction
    bool FUN_141683100(int nBuff);
    bool FUN_141682fe0(int nBuff);
};

// Config constants singleton (FUN_1401d3200): the idle delay at +0xa00 and the idle-emotion chance at +0x29c8.
class Unk_IdleDelay { public: unsigned FUN_14025a620(); };
class Unk_IdleChance { public: unsigned FUN_140536a30(); };
class Unk_IdleConsts
{
public:
    char m_pad0[0xa00];
    Unk_IdleDelay m_delay;
    char m_pad1[0x29c8 - 0xa01];
    Unk_IdleChance m_chance;
};

class Unk_Skills { public: int FUN_141768fb0(int nSkill, unsigned short nLevel); };
class Unk_AnimName { public: char m_pad[0x10]; };       // efd::utf8string stand-in (ctor 0x1409989e0, dtor 0x1408a8900)

// The animation service lookup (cached actor manager of a model key) and the sequence table.
class Unk_FNAnimSvc { public: NiActorManager* FUN_140999440(const Unk_GoModelKey& key); };
Unk_FNAnimSvc* FUN_141b6f910();
void* FUN_140999740(NiActorManager* pMgr, unsigned nSeq);
const char* FUN_142087e50(const void* pFixed);

// Casts of the actor class ids.
void* FUN_141468360(PCBase* p);                          // owner as Ridee (class id 0x6200045)
PCBase* FUN_141706540(void* pRidee);                     // the Ridee's rider
short FUN_141093510(PCBase* p);                          // CNpc animation key (+0xde8)

// MyPC / PCBase non-virtual helpers (free-function form: `this` is the first argument).
void* FUN_14165f100(PCBase* p);
void FUN_14165f170(PCBase* p);
void FUN_141670330(PCBase* p, float f);
void FUN_141670360(PCBase* p, float f);
void FUN_14166ef10(PCBase* p, const CString& strAnim, bool b, int n1, int n2);
bool FUN_14166f790(PCBase* p, const CString& strKey, CString& strOut, int nKind);
void FUN_14166f8f0(PCBase* p, int n, int b);
void FUN_14166dd20(PCBase* p, Unk_AnimName* pName, float fSpeed, bool bA, bool bB);
Unk_BuffMgr* FUN_14166d240(PCBase* p);
bool FUN_1416749c0(PCBase* p);
int FUN_141671a30(PCBase* p);
bool FUN_1415248d0(MyPC* p, int n1, int n2);
int FUN_14152c280(MyPC* p, RideOffAction* pAction);
egf::Entity* FUN_141659af0(MyPC* p, int n);
void* FUN_1416764a0(PCBase* p);
Unk_Skills* FUN_141523bc0(MyPC* p);
void FUN_14166d970(PCBase* p, NiPoint3 kDir);
void FUN_141657c80(PCBase* p, bool b);

void* FUN_1401958b0();
void FUN_1407ee1d0(void* pTable, MS2Ptr<Unk_EmoRow>* pOut, int nEmotion);
void FUN_1409989e0(Unk_AnimName* p, const char* psz);
void FUN_1408a8900(Unk_AnimName* p);
unsigned FUN_140869420();
void* FUN_1403ed2d0();
PCBase* FUN_141bd1320(void* pMgr, int nNpc);
Unk_IdleConsts* FUN_1401d3200();
unsigned FUN_140768010(unsigned nMax, unsigned nMin);
unsigned __int64 FUN_140767ff0();
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);
void FUN_1402c2890(ATL::CAtlArray<CStringA>&);                          // RemoveAll
void FUN_14122e3e0(ATL::CAtlArray<CStringA>&, const ATL::CAtlArray<CStringA>&);   // Copy
size_t FUN_1401662c0(ATL::CAtlArray<CStringA>&);                        // GetCount
CStringA& FUN_140164930(ATL::CAtlArray<CStringA>&, size_t i);           // GetAt

// ---- StateEmotionData ----

// @0x1417c3780
StateEmotionData::StateEmotionData()
{
    m_nEmotion = 0;
}

// @0x1417c37c0
StateEmotionData::StateEmotionData(long nEmotion)
{
    m_nEmotion = nEmotion;
}

// @0x1417c3810
void StateEmotionData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_n64 = m_nEmotion;
}

// @0x1417c3850
void StateEmotionData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nEmotion = p->m_n64;
}

// ---- StateEmotion ----

// @0x1417c3890
StateEmotion::StateEmotion(PCBase* pOwner) : State(pOwner)
{
    m_n10 = 0;
}

// @0x1417c3920
StateEmotion::~StateEmotion()
{
}

// @0x1417c3990
void StateEmotion::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        if (FUN_14165f100(pPC))
            FUN_14165f170(pPC);
    }
    m_spData2.AssignRaw(dynamic_cast<StateEmotionData*>(pData));
    if (m_spData2 == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        MS2Ptr<Unk_EmoRow> spRow;
        FUN_1407ee1d0(FUN_1401958b0(), &spRow, m_spData2->m_nEmotion);
        if (!(spRow == 0))
        {
            if (spRow->FUN_1407e9a60() == 0xe)
            {
                m_strAnim = spRow->FUN_1407e9cb0();
                FUN_141670330(m_pOwner, (float)spRow->m_n30);
                FUN_141670360(m_pOwner, (float)spRow->m_n30);
                FUN_14166ef10(m_pOwner, m_strAnim, true, 0, 0);
                FUN_1417b92a0();
                m_strLoop.Empty();
                if (FUN_14166f790(m_pOwner, m_strAnim, m_strLoop, 0))
                {
                    Unk_AnimName kName;
                    FUN_1409989e0(&kName, m_strLoop);
                    FUN_14166dd20(m_pOwner, &kName, 1.0f, true, false);
                    FUN_1408a8900(&kName);
                }
            }
        }
    }
}

// @0x1417c3cb0
void StateEmotion::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_n10 = 0;
    FUN_141670330(m_pOwner, 0.0f);
    FUN_141670360(m_pOwner, 0.0f);
    if (n != 0xf)
        FUN_14166f8f0(m_pOwner, 0, 1);
}

// @0x1417c3d30
int StateEmotion::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0 || m_spData2 == 0)
        return 0;
    if (m_spData2->m_nEmotion == p->m_n64)
        return 0;
    return 1;
}

// @0x1417c3e00
// MS2-FUNCTIONAL: slot 22 of GameObject takes the point by value in the exe (second 12-byte copy), but the shared
// header declares it void*.
void StateEmotion::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        Unk_BuffMgr* pBuff = FUN_14166d240(pPC);
        Vector3 kPos = pBuff->FUN_141683290();
        Vector3 kArg = kPos;
        pPC->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
        if (!FUN_1416749c0(m_pOwner))
        {
            if (!pBuff->FUN_141683100(0x30d41))
            {
                if (!pBuff->FUN_141683100(0x30d42))
                {
                    if (FUN_141671a30(pPC) == 0 || !pBuff->FUN_141682fe0(0x493e1))
                    {
                        if (!pBuff->FUN_141682fe0(0x493e5))
                            FUN_1417b9460();
                        else
                            pPC->vfunc_59(3, 0, 0, 0);
                    }
                    else
                    {
                        pPC->vfunc_59(6, 0, 0x25, 0);
                    }
                }
                else
                {
                    FUN_1415248d0(pPC, 2, 0);
                }
            }
            else
            {
                FUN_1415248d0(pPC, 1, 0);
            }
        }
        else
        {
            pPC->vfunc_59(2, 0, 0, 0);
        }
    }
}

// @0x1417c3fe0
// MS2-FUNCTIONAL: slot 68 takes the move point by value in the exe, but the shared header declares void*.
void StateEmotion::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_spData2 == 0)
        return;
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        Unk_Skills* pSkills = FUN_141523bc0(pPC);
        if (pSkills->FUN_141768fb0(m_spData2->m_nEmotion, 1) == 0)
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
            return;
        }
    }
    if (m_strLoop.IsEmpty())
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        Vector3 kMove = DAT_143b01a60;
        m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
    }
}

// @0x1417c4150
void StateEmotion::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (!FUN_14166f790(m_pOwner, m_strAnim, m_strLoop, 1))
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        StateEmotionData* pData = new StateEmotionData(m_spData2->m_nEmotion);
        m_pOwner->vfunc_59(0xf, pData, 0, 0);
    }
}

// @0x1417c4270
bool StateEmotion::vfunc_28(MS2Ptr<Unk_StateArg22> p)
{
    bool bRet;
    if (m_spData2 == 0)
        bRet = true;
    else
        bRet = m_spData2->m_nEmotion != p->m_n64;
    return bRet;
}

// @0x1417c4320
int StateEmotion::FUN_1417c4320()
{
    if (m_spData2.get() == 0)
        return 0;
    return m_spData2->m_nEmotion;
}

// ---- StateTriggerEmotionData ----

// @0x1417c4370
StateTriggerEmotionData::StateTriggerEmotionData()
{
    m_nMode = 0;
    m_nFlag = 0;
    m_nValue = 0;
    m_bLoop = false;
}

// @0x1417c5230
StateTriggerEmotionData::~StateTriggerEmotionData()
{
}

// ---- StateTriggerEmotion ----

// @0x1417c43e0
StateTriggerEmotion::StateTriggerEmotion(PCBase* pOwner) : State(pOwner)
{
    m_nIndex = 0;
    m_nFlag = 0;
    m_nMode = 0;
    m_nDuration = 0;
    m_nStart = 0;
    m_n10 = 0;
    m_nIndex = 0;
    m_nFlag = 0;
}

// @0x1417c44b0
StateTriggerEmotion::~StateTriggerEmotion()
{
}

// @0x1417c4500
void StateTriggerEmotion::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        if (FUN_14165f100(pPC))
            FUN_14165f170(pPC);
    }
    FUN_1402c2890(m_aEmotions);
    m_nIndex = 0;
    m_spData2.AssignRaw(dynamic_cast<StateTriggerEmotionData*>(pData));
    if (m_spData2.get() != 0)
    {
        m_nMode = m_spData2->m_nMode;
        m_nDuration = m_spData2->m_nValue;
        FUN_14122e3e0(m_aEmotions, m_spData2->m_aEmotions);
        m_nFlag = m_spData2->m_nFlag;
    }
    if (m_nFlag != 0)
    {
        MyPC* pPC2 = FUN_1417b84b0();
        if (pPC2)
            FUN_141657c80(pPC2, true);
    }
    if (FUN_1401662c0(m_aEmotions) != 0)
    {
        const char* pszName = FUN_140164930(m_aEmotions, 0);
        Unk_AnimName kName;
        FUN_1409989e0(&kName, pszName);
        FUN_14166dd20(m_pOwner, &kName, 1.0f, m_spData2->m_bLoop, false);
        FUN_1408a8900(&kName);
    }
    m_nStart = FUN_140869420();
}

// @0x1417c4770
void StateTriggerEmotion::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_nFlag = 0;
}

// @0x1417c47b0
int StateTriggerEmotion::vfunc_16()
{
    return m_nFlag;
}

// @0x1417c47d0
void StateTriggerEmotion::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (m_nMode == 0)
    {
        m_nIndex = m_nIndex + 1;
        int nCount = (int)FUN_1401662c0(m_aEmotions);
        if (m_nIndex < nCount)
        {
            const char* pszName = FUN_140164930(m_aEmotions, m_nIndex);
            Unk_AnimName kName;
            FUN_1409989e0(&kName, pszName);
            FUN_14166dd20(m_pOwner, &kName, 1.0f, false, false);
            FUN_1408a8900(&kName);
        }
        else
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
        }
    }
    else
    {
        unsigned nNow = FUN_140869420();
        if (nNow < (unsigned)(m_nStart + m_nDuration))
        {
            if (FUN_1401662c0(m_aEmotions) != 0)
            {
                const char* pszName = FUN_140164930(m_aEmotions, 0);
                Unk_AnimName kName;
                FUN_1409989e0(&kName, pszName);
                FUN_14166dd20(m_pOwner, &kName, 1.0f, false, false);
                FUN_1408a8900(&kName);
            }
        }
        else
        {
            m_pOwner->vfunc_59(1, 0, 0, 0);
        }
    }
}

// ---- StateDataTriggerFollowNpc ----

// @0x1417c49e0
StateDataTriggerFollowNpc::StateDataTriggerFollowNpc(long nNpc)
{
    m_nNpc = nNpc;
}

// @0x1417c4a30
void StateDataTriggerFollowNpc::vfunc_1(Unk_StateDataArg* p)
{
    p->m_n64 = m_nNpc;
}

// @0x1417c4a60
void StateDataTriggerFollowNpc::vfunc_2(Unk_StateDataArg* p)
{
    m_nNpc = p->m_n64;
}

// ---- StateTriggerFollowNpc ----

// @0x1417c4a90
StateTriggerFollowNpc::StateTriggerFollowNpc(PCBase* pOwner) : State(pOwner)
{
    m_nAnim = 0;
}

// @0x1417c4b00
StateTriggerFollowNpc::~StateTriggerFollowNpc()
{
}

// @0x1417c4b40
void StateTriggerFollowNpc::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    PCBase* pPC = FUN_1417b8370();
    if (pPC)
    {
        if (FUN_14165f100(pPC))
            FUN_14165f170(pPC);
    }
    m_spData2.AssignRaw(dynamic_cast<StateDataTriggerFollowNpc*>(pData));
    if (m_spData2 == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        m_nAnim = 0;
        if (FUN_141bd1320(FUN_1403ed2d0(), m_spData2->m_nNpc) == 0)
            m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}

// @0x1417c4c90
// MS2-FUNCTIONAL: the animation-name lookup skips the actor-manager smart pointer's AddRef/Release pair; the
// slot 19/21 by-value point copies are written as plain by-value calls.
void StateTriggerFollowNpc::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    PCBase* pActor = m_pOwner;
    void* pRidee = FUN_141468360(m_pOwner);
    if (pRidee)
        pActor = FUN_141706540(pRidee);
    PCBase* pNpc = FUN_141bd1320(FUN_1403ed2d0(), m_spData2->m_nNpc);
    if (pNpc == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        m_pOwner->vfunc_19(pNpc->vfunc_18());
        FUN_14166d970(m_pOwner, pNpc->vfunc_20());
        short nAnim = FUN_141093510(pNpc);
        if (nAnim != 0 && m_nAnim != nAnim)
        {
            m_nAnim = nAnim;
            CString strAnim;
            if (m_nAnim == -2 || m_nAnim == -3)
            {
                strAnim = "Jump_Down_A";
            }
            else
            {
                Unk_GoModelKey kKey;
                Unk_GoModelKey& rKey = pActor->FUN_14123c460(kKey);
                NiActorManager* pMgr = FUN_141b6f910()->FUN_140999440(rKey);
                if (pMgr != 0)
                {
                    int nSeq = (int)m_nAnim;
                    void* pSeq = FUN_140999740(pMgr, nSeq);
                    if (pSeq != 0)
                        strAnim = FUN_142087e50((char*)pSeq + 0x10);
                }
            }
            if (!strAnim.IsEmpty())
            {
                Unk_AnimName kName;
                FUN_1409989e0(&kName, strAnim);
                FUN_14166dd20(m_pOwner, &kName, 1.0f, false, false);
                FUN_1408a8900(&kName);
            }
        }
    }
}

// @0x1417c4fe0
bool StateTriggerFollowNpc::vfunc_25(int n, void* p)
{
    if (!State::vfunc_25(n, p))
        return false;
    StateDataTriggerFollowNpc* pData = dynamic_cast<StateDataTriggerFollowNpc*>((StateData*)p);
    if (pData == 0)
        return false;
    if (m_spData2->m_nNpc == pData->m_nNpc)
        return true;
    else
        return false;
}

// @0x1417c5600
MS2Ptr<StateData> StateEmotion::vfunc_27()
{
    return MS2Ptr<StateData>(new StateEmotionData);
}

// @0x1417c5680
MS2Ptr<StateData> StateTriggerEmotion::vfunc_27()
{
    return MS2Ptr<StateData>(new StateTriggerEmotionData);
}

// @0x1417c5700
MS2Ptr<StateData> StateTriggerFollowNpc::vfunc_27()
{
    return MS2Ptr<StateData>(new StateDataTriggerFollowNpc(0));
}

// @0x1417c5780
int StateEmotion::vfunc_1()
{
    return 0xb;
}

// @0x1417c5790
int StateTriggerEmotion::vfunc_1()
{
    return 0x35;
}

// @0x1417c57a0
int StateTriggerFollowNpc::vfunc_1()
{
    return 0x46;
}

// ---- StateEmotionIdleData ----

// @0x1417c5ae0
StateEmotionIdleData::StateEmotionIdleData()
{
    m_nEmotion = 0;
}

// @0x1417c5b20
StateEmotionIdleData::StateEmotionIdleData(long nEmotion)
{
    m_nEmotion = nEmotion;
}

// @0x1417c5b70
void StateEmotionIdleData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_n64 = m_nEmotion;
}

// @0x1417c5bb0
void StateEmotionIdleData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nEmotion = p->m_n64;
}

// ---- StateEmotionIdle ----

// @0x1417c5bf0
StateEmotionIdle::StateEmotionIdle(PCBase* pOwner) : State(pOwner)
{
}

// @0x1417c5c90
StateEmotionIdle::~StateEmotionIdle()
{
}

// @0x1417c5d10
void StateEmotionIdle::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_timer.FUN_1408687f0();
    m_n10 = 0x6f;
    m_spData2.AssignRaw(dynamic_cast<StateEmotionIdleData*>(pData));
    if (m_spData2 == 0)
    {
        MS2_ASSERT_AT(0x3d, 0);
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        MS2Ptr<Unk_EmoRow> spRow;
        FUN_1407ee1d0(FUN_1401958b0(), &spRow, m_spData2->m_nEmotion);
        if (!(spRow == 0))
        {
            if (spRow->FUN_1407e9a60() == 0xe)
            {
                m_strAnim = spRow->FUN_1407e9cb0();
                FUN_14166ef10(m_pOwner, m_strAnim, true, 0, 0);
                FUN_141670330(m_pOwner, (float)spRow->m_n30);
                FUN_141670360(m_pOwner, (float)spRow->m_n30);
                m_strNext.Empty();
                if (FUN_14166f790(m_pOwner, m_strAnim, m_strNext, 1))
                {
                    Unk_AnimName kName;
                    FUN_1409989e0(&kName, m_strNext);
                    FUN_14166dd20(m_pOwner, &kName, 1.0f, true, false);
                    FUN_1408a8900(&kName);
                }
                FUN_1417b92a0();
                return;
            }
        }
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}

// @0x1417c6070
// MS2-FUNCTIONAL: slot 68 takes the move point by value in the exe, but the shared header declares void*.
void StateEmotionIdle::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_spData2 == 0)
    {
        MyPC* pPC = FUN_1417b84b0();
        if (pPC)
        {
            Unk_Skills* pSkills = FUN_141523bc0(pPC);
            if (pSkills->FUN_141768fb0(m_spData2->m_nEmotion, 1) == 0)
            {
                m_pOwner->vfunc_59(1, 0, 0, 0);
                return;
            }
        }
        Vector3 kMove = DAT_143b01a60;
        m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
    }
}

// @0x1417c61a0
void StateEmotionIdle::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_spData2 = 0;
    m_strAnim = "";
    FUN_14166f8f0(m_pOwner, 0, 1);
    FUN_141670330(m_pOwner, 0.0f);
    FUN_141670360(m_pOwner, 0.0f);
}

// @0x1417c6230
// MS2-FUNCTIONAL: slot 22 of GameObject takes the point by value in the exe (second 12-byte copy), but the shared
// header declares it void*.
void StateEmotionIdle::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC && m_pOwner->vfunc_63() != 0)
    {
        Unk_BuffMgr* pBuff = FUN_14166d240(m_pOwner);
        Vector3 kPos = pBuff->FUN_141683290();
        Vector3 kArg = kPos;
        m_pOwner->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
        if (pPC == 0 || !pBuff->FUN_141683100(0x30d41))
        {
            if (pPC == 0 || !pBuff->FUN_141683100(0x30d42))
            {
                if (FUN_141671a30(m_pOwner) == 0 || !pBuff->FUN_141682fe0(0x493e1))
                {
                    if (!FUN_1416749c0(m_pOwner))
                    {
                        if (!pBuff->FUN_141682fe0(0x493e5))
                            FUN_1417b9460();
                        else
                            m_pOwner->vfunc_59(3, 0, 0, 0);
                    }
                    else
                    {
                        m_pOwner->vfunc_59(2, 0, 0, 0);
                    }
                }
                else
                {
                    m_pOwner->vfunc_59(6, 0, 0x25, 0);
                }
            }
            else
            {
                FUN_1415248d0(pPC, 2, 0);
            }
        }
        else
        {
            egf::Entity* pEntity = FUN_141659af0(pPC, 1);
            if (pEntity != 0)
            {
                if (FUN_1416764a0(pPC) == 0)
                {
                    FUN_1415248d0(pPC, 1, 0);
                }
                else
                {
                    MS2Ptr<RideOffAction> spAction(new RideOffActionTakeLR(1));
                    spAction->m_n28 = 1;
                    if (FUN_1408a9bd0(pEntity)->ContainsModel(0xbadf0a13))
                    {
                        spAction->m_n2c = 0xbadf0a13;
                    }
                    else if (FUN_1408a9bd0(pEntity)->ContainsModel(0xc13e30c8))
                    {
                        spAction->m_n2c = 0xc13e30c8;
                    }
                    FUN_14152c280(pPC, spAction.get());
                }
            }
        }
        if (FUN_1416749c0(m_pOwner))
            m_pOwner->vfunc_59(2, 0, 0, 0);
        if (m_timer.FUN_140868c00() == 0)
        {
            if (m_timer.FUN_140868ba0() == 0)
                m_timer.FUN_140868750(FUN_1401d3200()->m_delay.FUN_14025a620());
        }
        else
        {
            m_timer.FUN_1408687f0();
            static unsigned s_nChance = FUN_1401d3200()->m_chance.FUN_140536a30();
            if (FUN_140768010(100, 0) <= s_nChance)
            {
                CString strTmp;
                unsigned nCount = FUN_14166f790(m_pOwner, m_strAnim, strTmp, 2) ? 1 : 0;
                if (FUN_14166f790(m_pOwner, m_strAnim, strTmp, 3))
                    nCount = nCount + 1;
                if (FUN_14166f790(m_pOwner, m_strAnim, strTmp, 4))
                    nCount = nCount + 1;
                if (nCount != 0)
                {
                    int nPick = (int)((FUN_140767ff0() & 0xffffffff) % (unsigned __int64)nCount);
                    m_n10 = nPick + 0x70;
                    m_strNext.Empty();
                }
            }
        }
    }
}

// @0x1417c6810
void StateEmotionIdle::vfunc_9(double fTime)
{
    int nKind = 1;
    int nState = m_n10;
    if (nState == 0x6f)
        nKind = 1;
    else if (nState == 0x70)
        nKind = 2;
    else if (nState == 0x71)
        nKind = 3;
    else if (nState == 0x72)
        nKind = 4;
    if (FUN_14166f790(m_pOwner, m_strAnim, m_strNext, nKind))
    {
        Unk_AnimName kName;
        FUN_1409989e0(&kName, m_strNext);
        FUN_14166dd20(m_pOwner, &kName, 1.0f, false, false);
        FUN_1408a8900(&kName);
    }
}

// @0x1417c6940
void StateEmotionIdle::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (m_n10 != 0x6f)
    {
        m_n10 = 0x6f;
        m_strNext.Empty();
    }
}

// @0x1417c6990
int StateEmotionIdle::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0)
        return 0;
    if (m_n10 == p->m_n1c)
        return 0;
    return 1;
}

// @0x1417c6a30
int StateEmotionIdle::FUN_1417c6a30()
{
    if (m_spData2.get() == 0)
        return 0;
    return m_spData2->m_nEmotion;
}

// @0x1417c6ca0
MS2Ptr<StateData> StateEmotionIdle::vfunc_27()
{
    return MS2Ptr<StateData>(new StateEmotionIdleData);
}

// @0x1417c6d20
int StateEmotionIdle::vfunc_1()
{
    return 0xf;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb71b0-0x142cb72b0 .text$yd
