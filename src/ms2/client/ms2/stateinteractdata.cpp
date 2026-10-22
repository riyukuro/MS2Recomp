// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateInteractData, the interact-object / npc / auto-mining states
// StateInteraction, StateInteractionNpc and StateAutoInteraction (stateinteraction.h) with the std::vector<MS2Ptr<CInteractObject>>
// and MS2Ptr<...Data> glue they instantiate, and the header statics of the .text$di part.
// MS2-UNIT: ?\stateinteractdata.cpp
// MS2-RANGE: 0x140102e00-0x140102fd0 .text$di
// MS2-RANGE: 0x1417d0be0-0x1417d5160 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateAutoInteractionData@@@@QEAAAEAV1@PEAVStateAutoInteractionData@@@Z 0x1417d45c0 ; prop
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateInteractData@@@@QEAAAEAV1@PEAVStateInteractData@@@Z 0x1417d4630 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VStateInteractNpcData@@@@QEAAAEAV1@PEAVStateInteractNpcData@@@Z 0x1417d46a0 ; prop
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateinteractdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <io.h>
#include <string>
#include "ms2/client/ms2/interactobject.h"
#include <float.h>
#include <errno.h>
#include <string.h>
#include <new>
#include <atlcoll.h>

#include "stateinteraction.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/smartpushtable.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders ----

extern Unk_StreamPoint DAT_143b01a60;                    // the zero point

// A PCBase seen through its slot 18 (the position, returned as the 12-byte point of the FUN_ operators).
class Unk_SiPos
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
UICastingBar* FUN_140ac2270(int nId);

void* FUN_14165f100(PCBase* p);
void FUN_14165f170(PCBase* p);
class Unk_SiBuffMgr { public: Unk_StreamPoint FUN_141683290(); };
Unk_SiBuffMgr* FUN_14166d240(PCBase* p);
bool FUN_1416749c0(PCBase* p);
CStringW GetStringCommonByKey(const CStringW& str);
CString FUN_1409a2360(const char* psz, int nCodePage);   // CString from a narrow string (0 = default code page)

// A npc seen through the two members this unit reads.
class Unk_SiNpc : public CNpc
{
public:
    float FUN_140f4a450();                               // the distance to the local player
    void FUN_141094730();                                // face the local player
};

// The world manager: the interact objects and the actors.
class Unk_SiWorld
{
public:
    MS2Ptr<CInteractObject> FUN_141bc6090(Unk_StreamPoint pt, int nSkipDisabled);   // the interactable object at a point
    MS2Ptr<CInteractObject> FUN_141bc66b0(const CString& strName);                  // an interact object by name
    void FUN_141bc5fb0(void* pOut, int nCategory);                                  // the interact objects of a kind
    void* FUN_141bd0cc0();                                                          // the local player
    Unk_SiNpc* FUN_141bd1320(int nActorId);                                         // an actor by object id
};
Unk_SiWorld* FUN_1403ed2d0();

// The effect manager (a request is the exe's 0x78-byte record: name +0, owner +8, transform +0x18).
struct Unk_SiXform
{
    Unk_EfdMatrix3 m_rotate;
    float m_afTranslate[3];
    float m_fScale;
};
MS2_CHECK_SIZE(Unk_SiXform, 0x34);
void* FUN_140a332d0(Unk_SiXform* p);
void FUN_14097faa0(float* pDst, const Unk_NiPoint3* pSrc);
struct Unk_SiFxRequest
{
    CString m_strName;
    int m_nOwnerId;
    int m_pad_0c;
    void* m_pSlot10;
    Unk_SiXform* m_pXform;
    char m_pad_20[0x58];
};
MS2_CHECK_SIZE(Unk_SiFxRequest, 0x78);
class Unk_SiFxMgr
{
public:
    int FUN_1411a49c0(Unk_SiFxRequest* pRequest);
    void FUN_1411a6060(int nHandle);
};
Unk_SiFxMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_SiFxRequest* p);
void FUN_1405a89e0(Unk_SiFxRequest* p);

// The quest manager: does the quest state satisfy a mask.
class Unk_SiQuestEval
{
public:
    virtual void vf00() = 0; virtual void vf01() = 0; virtual void vf02() = 0; virtual void vf03() = 0;
    virtual void vf04() = 0; virtual void vf05() = 0; virtual void vf06() = 0; virtual void vf07() = 0;
    virtual void vf08() = 0; virtual void vf09() = 0; virtual void vf10() = 0; virtual void vf11() = 0;
    virtual void vf12() = 0; virtual void vf13() = 0; virtual void vf14() = 0; virtual void vf15() = 0;
    virtual void vf16() = 0; virtual void vf17() = 0; virtual void vf18() = 0; virtual void vf19() = 0;
    virtual void vf20() = 0; virtual void vf21() = 0; virtual void vf22() = 0;
    virtual int CheckMask(const QuestMask* pMask) = 0;          // 23
};
struct Unk_SiQuestMgr
{
    char m_pad_00[0x10];
    void* m_pEvalVptr;
    Unk_SiQuestEval* Eval() { return reinterpret_cast<Unk_SiQuestEval*>(&m_pEvalVptr); }
};
Unk_SiQuestMgr* FUN_140764020();

MS2Ptr<CInteractObjectData> FUN_14051f670(int nId);

// The equipment of a player: the worn item of a slot.
class Unk_SiEquip { public: MS2Ptr<CGemBase> FUN_141270740(int nSlot); };
Unk_SiEquip* FUN_14165f460(PCBase* p);

// The pieces of the interact row this unit reads (offsets proven by the callers).
class Unk_SiRowNames { public: CString FUN_14051c870(); };           // +0xc8: the reaction animation name
#define SiRowOff(p, off) (reinterpret_cast<char*>(p) + (off))
#define SiRowNames(p) reinterpret_cast<Unk_SiRowNames*>(SiRowOff(p, 0xc8))
#define SiRowMask(p) reinterpret_cast<const QuestMask*>(SiRowOff(p, 0x1d0))
#define SiRowEffect(p) (*reinterpret_cast<CString*>(SiRowOff(p, 0x148)))
#define SiRowAnimA(p) (*reinterpret_cast<CString*>(SiRowOff(p, 0xf0)))
#define SiRowAnimB(p) (*reinterpret_cast<CString*>(SiRowOff(p, 0xe8)))

// The sync record StateData slots 1 / 2 read and write (object id at +0x64, the animation text at +0x70).
struct Unk_SiSyncRecord
{
    char m_pad_00[0x64];
    int m_nObjectId;
    char m_pad_68[8];
    CString m_strAnim;
};

void* FUN_1409331e0();
void FUN_14138bf00(void* pSvc, int nKind, int nId, int nFlag);

struct Unk_RegMarker {};

// ---- dynamic initializers (.text$di) ----

// @0x140102e00
static CString s_stun0("stun");

#ifndef MS2_HOOK_DLL
// @0x140102e30
#include "ms2/placeholder/unk_1402a9d70.h"
static Unk_1402a9d70 s_marker0(17, 0.75f, 0.25f, 2.25f, 10);   // atexit thunk FUN_142cb7730
#endif

// @0x140102e80
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x140102f40
static CString s_skill("skill");

// @0x140102f70
static CString s_stun("stun");

#ifndef MS2_HOOK_DLL
// @0x140102fa0
static Unk_1402a9d70 s_marker1(17, 0.75f, 0.25f, 2.25f, 10);   // atexit thunk FUN_142cb77c0
#endif

// ---- StateInteractData ----

// @0x1417d0be0
StateInteractData::StateInteractData() : m_nObjectId(0), m_nFlag(0) {}

// @0x1417d0c50
StateInteractData::~StateInteractData() {}

// @0x1417d0cb0
void StateInteractData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    reinterpret_cast<Unk_SiSyncRecord*>(p)->m_nObjectId = m_nObjectId;
    reinterpret_cast<Unk_SiSyncRecord*>(p)->m_strAnim = m_strAnim;
}

// @0x1417d0d10
void StateInteractData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nObjectId = reinterpret_cast<Unk_SiSyncRecord*>(p)->m_nObjectId;
    m_strAnim = reinterpret_cast<Unk_SiSyncRecord*>(p)->m_strAnim;
}

// ---- StateInteraction ----

// @0x1417d0d70
StateInteraction::StateInteraction(PCBase* pOwner) : State(pOwner), m_n48(0) {}

// @0x1417d0e10
StateInteraction::~StateInteraction() {}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d0e70
void StateInteraction::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n48 = 0;
    m_spInteract.AssignRaw(dynamic_cast<StateInteractData*>(pData));
    if (m_spInteract == 0)
    {
        m_spInteract.AssignRaw(new StateInteractData);
        MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc6090(reinterpret_cast<Unk_SiPos*>(m_pOwner)->vfunc_18(), 0);
        if (spObject.get())
            m_spInteract->m_nObjectId = spObject->GetRowId();
    }
    MS2Ptr<CInteractObjectData> spRow = FUN_14051f670(m_spInteract->m_nObjectId);
    if (m_n10 == 0x8a)
    {
        FUN_1417d22f0(MS2Ptr<CInteractObjectData>(spRow));
        FUN_1417d25e0(MS2Ptr<CInteractObjectData>(spRow));
        MyPC* pPC = FUN_1417b84b0();
        if (pPC)
        {
            if (FUN_14165f100(pPC))
                FUN_14165f170(pPC);
            Unk_CastInfo kInfo;
            MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc6090(reinterpret_cast<Unk_SiPos*>(m_pOwner)->vfunc_18(), 1);
            if (spObject.IsNull())
            {
                m_pOwner->vfunc_59(1, 0, 0, 0);
                return;
            }
            if (spObject->vfunc_5() == 6)
            {
                m_aObjects.clear();
                ATL::CAtlArray<MS2Ptr<CInteractObject> > aObjects;
                FUN_1403ed2d0()->FUN_141bc5fb0(&aObjects, 6);
                for (size_t i = 0; i < aObjects.GetCount(); i++)
                {
                    if (aObjects[i]->vfunc_4() != 0)
                    {
                        float fDist = aObjects[i]->GetPos().FUN_140965c40(reinterpret_cast<Unk_SiPos*>(pPC)->vfunc_18()).FUN_140967ac0();
                        if (fDist <= *static_cast<Client::Constants*>(FUN_1401d3200())->MasteryObjectInteractionDistance.Get())
                            m_aObjects.push_back(aObjects[i]);
                    }
                }
                if (m_aObjects.size() == 0)
                    return;
                SendInteractObjectMode11();
            }
            else
                spObject->vfunc_8();
            spObject->vfunc_6(reinterpret_cast<Unk_InteractCursor*>(&kInfo));
            UICastingBar* pBar = FUN_140ac2270(0x4e72);
            if (pBar)
                pBar->FUN_1418e12b0(this, kInfo);
        }
    }
    else if (m_n10 == 0x8b)
    {
        efd::utf8string strAnim("");
        if (spRow.get())
        {
            strAnim = (const char*)FUN_1409a2360(SiRowAnimA(spRow.get()), 0);
            if (strAnim.length() != 0)
                m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
        }
    }
    else if (m_n10 == 0x8c)
    {
        efd::utf8string strAnim("");
        if (spRow.get())
        {
            strAnim = (const char*)FUN_1409a2360(SiRowAnimB(spRow.get()), 0);
            if (strAnim.length() != 0)
                m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
        }
    }
}

// @0x1417d1700
void StateInteraction::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Unk_StreamPoint kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
}

// @0x1417d1780
void StateInteraction::vfunc_5(int n)
{
    if (m_n10 == 0x8a && m_n48 == 0)
    {
        if (m_spInteract.get())
        {
            MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc66b0(m_spInteract->m_strObjectId);
            if (spObject.get())
                spObject->vfunc_9();
        }
    }
    State::vfunc_5(n);
    if (FUN_1417b8560() != 0 && m_n10 == 0x8a)
    {
        if (m_nEffect != 0)
            FUN_1403ed280()->FUN_1411a6060(m_nEffect);
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
            pBar->FUN_1418e1390();
    }
}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d18c0
void StateInteraction::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        if (m_n10 == 0x8d && m_spInteract.get())
        {
            MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc66b0(m_spInteract->m_strObjectId);
            if (spObject.get())
            {
                if (spObject->vfunc_4() != 0)
                {
                    MS2Ptr<StateInteractData> spNew(new StateInteractData);
                    spNew->m_nObjectId = spObject->GetRowId();
                    spNew->m_strObjectId = spObject->GetName();
                    pPC->vfunc_59(0x19, spNew.get(), 0x8a, 0);
                }
            }
        }
        if (m_spInteract.get())
        {
            MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc66b0(m_spInteract->m_strObjectId);
            if (spObject.get())
            {
                if (m_n48 == 0)
                {
                    float fRange = spObject->GetRow()->m_validate.m_fInteractionDistance;
                    float fDist = spObject->GetPos().FUN_140965c40(reinterpret_cast<Unk_SiPos*>(pPC)->vfunc_18()).FUN_140967ac0();
                    if (fRange < fDist)
                    {
                        pPC->vfunc_59(1, 0, 0, 0);
                        return;
                    }
                }
                else
                    FUN_1417d2230(spObject.get());
            }
            if (m_n48 != 0)
            {
                pPC->vfunc_59(1, 0, 0, 0);
                return;
            }
        }
        Unk_SiBuffMgr* pBuff = FUN_14166d240(pPC);
        Unk_StreamPoint kPos = pBuff->FUN_141683290();
        Unk_StreamPoint kArg = kPos;
        pPC->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
        if (FUN_1416749c0(m_pOwner))
            pPC->vfunc_59(2, 0, 0, 0);
        else
            FUN_1417b9460();
    }
}

// @0x1417d1db0
void StateInteraction::vfunc_6()
{
    if (FUN_1417b8560() != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d1e00
void StateInteraction::EndOfSequence(NiActorManager*, unsigned int, NiControllerSequence*, float)
{
    if (FUN_1417b8560() == 0)
        return;
    if (m_n10 != 0x8b && m_n10 != 0x8c)
        return;
    if (FUN_1417d2880() != 0)
    {
        m_n10 = 0x8d;
        m_pOwner->FUN_14166dda0(0);
    }
    else
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417d1eb0
bool StateInteraction::vfunc_25(int, void*) { return false; }

// @0x1417d1ed0
void StateInteraction::SendInteractObjectMode11()
{
    COutPacket kPacket(static_cast<int>(SendOp::InteractObject), 0);
    kPacket.vfunc_o10_1(0xb);
    kPacket.vfunc_o10_3(static_cast<int>(m_aObjects.size()));
    for (size_t i = 0; i < m_aObjects.size(); i++)
        kPacket.vfunc_o10_7(m_aObjects[i]->GetName());
    FUN_140710590(kPacket);
    for (size_t i = 0; i < m_aObjects.size(); i++)
    {
        CInteractMeshObject* pMesh = dynamic_cast<CInteractMeshObject*>(m_aObjects[i].get());
        if (pMesh)
            pMesh->FUN_1413ff840();
    }
}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d2070
void StateInteraction::SendInteractObjectMode12()
{
    std::vector<MS2Ptr<CInteractObject> > aUsable;
    for (size_t i = 0; i < m_aObjects.size(); i++)
    {
        if (m_aObjects[i]->vfunc_4() != 0)
            aUsable.push_back(m_aObjects[i]);
    }
    COutPacket kPacket(static_cast<int>(SendOp::InteractObject), 0);
    kPacket.vfunc_o10_1(0xc);
    kPacket.vfunc_o10_3(static_cast<int>(aUsable.size()));
    for (size_t i = 0; i < aUsable.size(); i++)
        kPacket.vfunc_o10_7(aUsable[i]->GetName());
    FUN_140710590(kPacket);
}

// @0x1417d2210
void StateInteraction::OnCastingFinished() { m_n48 = 1; }

// @0x1417d2230
void StateInteraction::FUN_1417d2230(CInteractObject* pObject)
{
    if (pObject->vfunc_5() == 6)
    {
        void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return;
        if (m_aObjects.size() == 0)
            return;
        SendInteractObjectMode12();
        m_aObjects.clear();
    }
    else
        pObject->vfunc_10();
    FUN_14138bf00(FUN_1409331e0(), 9, pObject->GetRowId(), 0);
}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d22f0
void StateInteraction::FUN_1417d22f0(MS2Ptr<CInteractObjectData> spRow)
{
    if (!(spRow == 0))
    {
        if (FUN_1417b8560() == 0)
            return;
        if (FUN_140764020()->Eval()->CheckMask(SiRowMask(spRow.get())) != 0)
        {
            MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc6090(reinterpret_cast<Unk_SiPos*>(m_pOwner)->vfunc_18(), 1);
            if (spObject.get())
            {
                Unk_StreamPoint kRot = spObject->GetRot();
                Unk_SiXform kXform;
                FUN_140a332d0(&kXform);
                Unk_StreamPoint kUp(0.0f, 0.0f, 1.0f);
                Unk_StreamPoint kPos = spObject->GetPos().FUN_14097fd50(kUp);
                Unk_NiPoint3 kNiPos(kPos);
                FUN_14097faa0(kXform.m_afTranslate, &kNiPos);
                kXform.m_rotate.FUN_142083d40((kRot.x * 3.1415927f) / 180.0f, (kRot.y * 3.1415927f) / 180.0f,
                                              (kRot.z * 3.1415927f) / 180.0f);
                kXform.m_fScale = 1.0f;
                Unk_SiFxRequest kRequest;
                FUN_140a52ef0(&kRequest);
                kRequest.m_strName = SiRowEffect(spRow.get());
                kRequest.m_nOwnerId = 0;
                kRequest.m_pXform = &kXform;
                m_nEffect = FUN_1403ed280()->FUN_1411a49c0(&kRequest);
                FUN_1405a89e0(&kRequest);
            }
        }
    }
}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d25e0
void StateInteraction::FUN_1417d25e0(MS2Ptr<CInteractObjectData> spRow)
{
    efd::utf8string strAnim("");
    if (m_spInteract.get() && m_spInteract->m_strAnim.GetLength() > 0)
    {
        strAnim = (const char*)FUN_1409a2360(m_spInteract->m_strAnim, 0);
        m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
        return;
    }
    if (spRow.get() == 0)
    {
        efd::utf8string strReact("Object_React_A");
        m_pOwner->FUN_14166dd20(strReact, 1.0f, false, false);
    }
    else
    {
        CString strName = SiRowNames(spRow.get())->FUN_14051c870();
        if (strName.GetLength() > 0)
        {
            m_spInteract->m_strAnim = strName;
            strAnim = (const char*)FUN_1409a2360(strName, 0);
            m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
        }
    }
}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d2880
int StateInteraction::FUN_1417d2880()
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return 0;
    MS2Ptr<CGemBase> spGem = FUN_14165f460(pPC)->FUN_141270740(9);
    if (spGem.IsNull())
        return 0;
    if (m_spInteract.IsNull())
        return 0;
    if (m_spInteract->m_nFlag == 0)
        return 0;
    MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc66b0(m_spInteract->m_strObjectId);
    if (spObject.IsNull())
        return 0;
    return spObject->vfunc_16() != 0;
}

// ---- StateInteractionNpc ----

// @0x1417d2a50
StateInteractionNpc::StateInteractionNpc(PCBase* pOwner) : State(pOwner)
{
    m_n48 = 0;
}

// @0x1417d2ae0
StateInteractionNpc::~StateInteractionNpc() {}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d2b30
void StateInteractionNpc::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n48 = 0;
    efd::utf8string strAnim("Object_React_A");
    Unk_CastInfo kInfo;
    m_spNpc.AssignRaw(dynamic_cast<StateInteractNpcData*>(pData));
    if (m_spNpc.get())
    {
        Unk_SiNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_spNpc->m_nNpc);
        if (pNpc)
        {
            MS2Ptr<CNpcData> spNpcData = MS2Ptr<CNpcData>(pNpc->GetNpcData());
            if (spNpcData.get())
            {
                kInfo.m_nDuration = spNpcData->m_interact.m_nCastingTime;
                kInfo.m_b5 = spNpcData->m_interact.m_bShowCastingBar;
                if (spNpcData->m_interact.m_strCastingAnimation.GetLength() > 0)
                    strAnim = (const char*)FUN_1409a2360(spNpcData->m_interact.m_strCastingAnimation, 0);
            }
        }
    }
    m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        if (FUN_14165f100(pPC))
            FUN_14165f170(pPC);
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
            pBar->FUN_1418e12b0(this, kInfo);
    }
}

// @0x1417d2e70
void StateInteractionNpc::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
            pBar->FUN_1418e1390();
    }
}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d2ed0
void StateInteractionNpc::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC)
    {
        if (m_spNpc.get())
        {
            Unk_SiNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_spNpc->m_nNpc);
            if (pNpc)
            {
                if (m_n48 == 0)
                {
                    float fDist = pNpc->FUN_140f4a450();
                    if (*static_cast<Client::Constants*>(FUN_1401d3200())->InteractionDistance.Get() < fDist)
                    {
                        pPC->vfunc_59(1, 0, 0, 0);
                        return;
                    }
                }
                else
                    pNpc->FUN_141094730();
            }
            if (m_n48 != 0)
            {
                pPC->vfunc_59(2, 0, 0, 0);
                return;
            }
        }
        Unk_SiBuffMgr* pBuff = FUN_14166d240(pPC);
        Unk_StreamPoint kPos = pBuff->FUN_141683290();
        Unk_StreamPoint kArg = kPos;
        pPC->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
        if (FUN_1416749c0(m_pOwner))
            pPC->vfunc_59(2, 0, 0, 0);
        else
            FUN_1417b9460();
    }
}

// @0x1417d30d0
void StateInteractionNpc::vfunc_6()
{
    if (FUN_1417b8560() != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417d3120
void StateInteractionNpc::OnCastingFinished() { m_n48 = 1; }

// ---- StateAutoInteraction ----

// @0x1417d3140
StateAutoInteraction::StateAutoInteraction(PCBase* pOwner) : State(pOwner)
{
    m_n48 = 0;
}

// @0x1417d31d0
StateAutoInteraction::~StateAutoInteraction() {}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d3220
void StateAutoInteraction::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n48 = 0;
    efd::utf8string strAnim = FUN_1417d36b0();
    m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
    m_spAuto.AssignRaw(dynamic_cast<StateAutoInteractionData*>(pData));
    PCBase* pPC = FUN_1417b8370();
    if (pPC)
    {
        if (FUN_14165f100(pPC))
            FUN_14165f170(pPC);
    }
    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
        {
            Unk_CastInfo kInfo;
            FUN_1417d3700(&kInfo);
            pBar->FUN_1418e12b0(this, kInfo);
        }
    }
}

// @0x1417d33e0
void StateAutoInteraction::vfunc_5(int n)
{
    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar)
            pBar->FUN_1418e1390();
    }
    State::vfunc_5(n);
}

// @0x1417d3440
void StateAutoInteraction::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_n48 != 0)
    {
        if (FUN_1417b8560() != 0)
        {
            UICastingBar* pBar = FUN_140ac2270(0x4e72);
            if (pBar)
                pBar->FUN_1418e1390();
            if (m_spAuto.get())
            {
                COutPacket kPacket(static_cast<int>(SendOp::SmartPush), 0);
                kPacket.vfunc_o10_3(m_spAuto->m_n18);
                kPacket.vfunc_o10_3(m_spAuto->m_n1c);
                kPacket.vfunc_o10_3(m_spAuto->m_n20);
                kPacket.vfunc_o10_0(true);
                FUN_140710590(kPacket);
            }
        }
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d35b0
void StateAutoInteraction::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    Unk_SiBuffMgr* pBuff = FUN_14166d240(pPC);
    Unk_StreamPoint kPos = pBuff->FUN_141683290();
    Unk_StreamPoint kArg = kPos;
    pPC->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
    if (FUN_1416749c0(m_pOwner))
        pPC->vfunc_59(2, 0, 0, 0);
}

// @0x1417d3690
void StateAutoInteraction::OnCastingFinished() { m_n48 = 1; }

// @0x1417d36b0
efd::utf8string StateAutoInteraction::FUN_1417d36b0()
{
    return efd::utf8string("Object_React_C");
}

// MS2-FUNCTIONAL: branch layout / stack-slot placement differs from the exe; calls and semantics are equivalent
// @0x1417d3700
void StateAutoInteraction::FUN_1417d3700(Unk_CastInfo* pInfo)
{
    if (m_spAuto.get())
    {
        CSmartPushTable::DataPtr spRow = CSmartPushTable::GetInstance()->GetData(m_spAuto->m_n18);
        if (spRow.get())
        {
            switch (spRow->m_nActionValue)
            {
            case 3: pInfo->m_str28 = GetStringCommonByKey(CStringW(L"s_mastery_automining_progress")); break;
            case 4: pInfo->m_str28 = GetStringCommonByKey(CStringW(L"s_mastery_autogathering_progress")); break;
            case 5: pInfo->m_str28 = GetStringCommonByKey(CStringW(L"s_mastery_autobreeding_progress")); break;
            case 6: pInfo->m_str28 = GetStringCommonByKey(CStringW(L"s_mastery_autofarming_progress")); break;
            }
            pInfo->m_nDuration = 2000;
        }
    }
}

// ---- the rest ----

// @0x1417d48c0
MS2Ptr<StateData> StateInteraction::vfunc_27()
{
    return MS2Ptr<StateData>(new StateInteractData);
}

// @0x1417d4940
Unk_StreamPoint CInteractObject::GetRot()
{
    return m_vRot;
}

// @0x1417d4970
int StateAutoInteraction::vfunc_1() { return 0x39; }

// @0x1417d4980
int StateInteraction::vfunc_1() { return 0x19; }

// @0x1417d4990
int StateInteractionNpc::vfunc_1() { return 0x1a; }

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb7710-0x142cb7730 .text$yd
// MS2-RANGE: 0x142cb7750-0x142cb77c0 .text$yd
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142cb7730-0x142cb7750 .text$yd
// MS2-RANGE: 0x142cb77c0-0x142cb77e0 .text$yd
