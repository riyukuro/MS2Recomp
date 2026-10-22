// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See cubespawnobject.h.
// MS2-UNIT: ?\cubespawnobject.cpp
// MS2-RANGE: 0x140a4e690-0x140a50440 .text$mn
// MS2-RANGE: 0x1400c3a20-0x1400c3bb0 .text$di
// MS2-RANGE: 0x142c9f2b0-0x142c9f340 .text$yd
// MS2-PIN: ??0?$MS2Ptr@VUnk_HpBarFx@@@@QEAA@H@Z 0x140a4fc50
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCStateManager@@@@QEAAAEAV1@PEAVCStateManager@@@Z 0x140a4fd30
// MS2-PIN: ??4?$MS2Ptr@VUnk_HpBarFx@@@@QEAAAEAV0@AEBV0@@Z 0x140a4fde0
// MS2-PIN: ?get@?$MS2Ptr@VUnk_NpcData@@@@QEBAPEAVUnk_NpcData@@XZ 0x140a4ff10
// MS2-PIN: ??C?$MS2Ptr@VCStateManager@@@@QEBAPEAVCStateManager@@XZ 0x140a4ff20
// MS2-PIN: ?vfunc_114@PCBase@@UEAAXPEAX@Z 0x140a4ffb0
// MS2-PIN: ?GetClassDesc@CubeSpawnObject@@UEBAPEBVClassInfo@efd@@XZ 0x140a50000
// MS2-PIN: ?TypeCast@CubeSpawnObject@@UEBA_NIPEAPEAX@Z 0x140a500c0
// MS2-PIN: ?TypeCast@CubeSpawnObject@@UEBA_NIPEAPEBX@Z 0x140a50110
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_HpBarFx@@@@AEBAXXZ 0x140a501c0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCStateManager@@@@AEBAXPEAX@Z 0x140a50260
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUnk_HpBarFx@@@@AEBAXPEAX@Z 0x140a502c0
// MS2-PIN: ??_7CubeSpawnObject@@6BIBase@efd@@@ 0x142dc7b40
// MS2-PIN: ??_7CubeSpawnObject@@6BCallbackObject@NiActorManager@@@ 0x142dc7f30
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubespawnobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "cubespawnobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

// A part of the npc row's model part list (+0x588).
class Unk_NpcPartList
{
public:
    size_t FUN_14078cd60();                                         // count
    const CEffectDummy& FUN_140789540(size_t i);                    // GetAt
};

// Npc table row (NpcData xml). Only the members this unit reads.
class Unk_NpcData : public CPtred
{
public:
    int FUN_1406cce20();                                            // npc id
    bool FUN_140a7c8d0();                                           // shows its name

    char m_pad_18[0x38];
    CString m_strModel;                                             // +0x50 animation (kfm) name
    float m_fScale;                                                 // +0x58
    char m_pad_5c[8];
    efd::Point3 m_offset;                                           // +0x64 spawn offset
    char m_pad_70[0x44];
    int m_nB4;                                                      // +0xb4 display id override
    char m_pad_b8[0x588 - 0xb8];
    Unk_NpcPartList m_parts;                                        // +0x588
};
MS2_CHECK_OFFSET(Unk_NpcData, m_strModel, 0x50);
MS2_CHECK_OFFSET(Unk_NpcData, m_offset, 0x64);
MS2_CHECK_OFFSET(Unk_NpcData, m_nB4, 0xb4);
MS2_CHECK_OFFSET(Unk_NpcData, m_parts, 0x588);

class Unk_NpcTable
{
public:
    MS2Ptr<Unk_NpcData> FUN_140a7cab0(int nNpcId);
};
Unk_NpcTable* FUN_1406d6e90();

// MS2Ptr<Unk_NpcData> members instantiated by earlier objs (the rest are this obj's COMDATs).
template <> void MS2Ptr<Unk_NpcData>::Reference(Unk_NpcData* p);         // 0x1406d9f40
template <> void MS2Ptr<Unk_NpcData>::Release();                          // 0x1406db080
template <> MS2Ptr<Unk_NpcData>::~MS2Ptr();                               // 0x1406d5390
template <> Unk_NpcData* MS2Ptr<Unk_NpcData>::operator->() const;         // 0x140965990
template <> bool MS2Ptr<Unk_NpcData>::operator==(Unk_NpcData* p) const;   // 0x1409f90f0

// The chat balloon component (uichatballoon.cpp: FUN_1418fbdb0(object id)).
class Unk_PCBaseComp_aa8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual int vfunc_8(int n);                                     // can show a balloon
};
MS2Ptr<Unk_PCBaseComp_aa8> FUN_1418fbdb0(int nObjectId);
template <> void MS2Ptr<Unk_PCBaseComp_aa8>::Reference(Unk_PCBaseComp_aa8* p);   // 0x1405aaca0
template <> void MS2Ptr<Unk_PCBaseComp_aa8>::Release();                          // 0x1405ab4d0
template <> MS2Ptr<Unk_PCBaseComp_aa8>::~MS2Ptr();                               // 0x1405a8980
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::get() const;         // 0x1405a8eb0
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::operator->() const;  // 0x1405a8f40

// Housing object gauge effect.
class Unk_HpBarFx : public CPtred
{
public:
    void FUN_1419933e0();
    void FUN_141993420(int a, int b, int c, int d);
    void FUN_141992140(int bShow);
    int FUN_141992160();                                            // shown
};
MS2Ptr<Unk_HpBarFx> FUN_1419936d0(int nObjectId);
void FUN_141993750(int nObjectId);

class Unk_Entity
{
public:
    void FUN_1409618c0(unsigned int uiPropId, efd::Point3& out);    // point property
};

// The state machine and the two states this actor registers.
class CStateManager : public CPtred
{
public:
    CStateManager(PCBase* pOwner);                                  // 0x1417da7a0
    void FUN_1417daeb0(int nId, class Unk_CsoState* pState);        // AddState
private:
    char m_pad_18[0x98 - 0x18];
};
class Unk_CsoState
{
    char m_pad[0x40];
};
class StateIdleSpawnObject : public Unk_CsoState
{
public:
    StateIdleSpawnObject(CubeSpawnObject* pOwner);                  // 0x140ac1e20
private:
    char m_pad_40[8];
};
class StateInterActionSpawnObject : public Unk_CsoState
{
public:
    StateInterActionSpawnObject(CubeSpawnObject* pOwner);           // 0x140ac1c30
};

// Talk scripts (FUN_140856fa0(npc id, n)); the pointer members are COMDATs of other objs.
class Unk_ScriptContent
{
public:
    char m_pad[0x18];
    CStringW m_strText;                                             // +0x18
    CString m_strSound;                                             // +0x20
};
struct Unk_ScriptContentPtr
{
    Unk_ScriptContent* FUN_14078f3d0() const;                       // operator->
    void* m_00;
    void* m_p;
};
class Unk_ScriptContentArray
{
public:
    size_t FUN_14078fae0() const;                                   // GetCount
    // @0x140a4ffc0 (CAtlArray GetAt, COMDAT first instantiated here)
    const Unk_ScriptContentPtr& FUN_140a4ffc0(size_t i) const
    {
        if (i >= m_nSize)
            FUN_140159b70(E_INVALIDARG);
        return m_pData[i];
    }
    const Unk_ScriptContentPtr& FUN_14078f350(size_t i) const;      // GetAt (other instance)
    static void FUN_140159b70(HRESULT hr);                          // AtlThrow

    Unk_ScriptContentPtr* m_pData;
    size_t m_nSize;
};
class Unk_TalkScript
{
public:
    char m_pad[0x68];
    Unk_ScriptContentArray m_contents;                              // +0x68
};
struct Unk_TalkScriptPtr
{
    ~Unk_TalkScriptPtr();                                           // 0x14078f140
    Unk_TalkScript* FUN_14078f3a0() const;                          // get
    Unk_TalkScript* FUN_14085a610() const;                          // operator->
    void* m_00;
    void* m_p;
};
Unk_TalkScriptPtr FUN_140856fa0(int nNpcId, int n);

// Client configuration (FUN_1401d3200).
struct Unk_CsoConfigFloat
{
    float FUN_1402bac70();
    char m_pad[0x58];
};
struct Unk_CsoConstants
{
    void FUN_1402b7560(const char* pszMsg);
    // @0x140a50020
    const CStringW& FUN_140a50020()
    {
        if (!m_bSet)
            FUN_1402b7560("constants is not set");
        return m_strMe;
    }
    void* m_00;
    bool m_bSet;                                                    // +0x08
    char m_pad_09[0x47];
    CStringW m_strMe;                                               // +0x50
};
struct Unk_CsoConfig
{
    char m_pad_0[0x588];
    Unk_CsoConfigFloat m_588;
    Unk_CsoConfigFloat m_5e0;
    Unk_CsoConfigFloat m_638;
    Unk_CsoConfigFloat m_690;
    Unk_CsoConfigFloat m_6e8;
    char m_pad_740[0x94a8 - 0x740];
    Unk_CsoConstants m_94a8;
};
MS2_CHECK_OFFSET(Unk_CsoConfig, m_6e8, 0x6e8);
MS2_CHECK_OFFSET(Unk_CsoConfig, m_94a8, 0x94a8);
Unk_CsoConfig* FUN_1401d3200();

class Unk_CsoUserMgr
{
public:
    bool FUN_1404793a0(const CStringW& strName);
};
Unk_CsoUserMgr* FUN_1401c0d90();

class Unk_CsoGameMode
{
public:
    int FUN_1409f7ea0();
};
Unk_CsoGameMode* FUN_1409f7c90();

class Unk_CsoGameCtx
{
public:
    void FUN_1411a4f40(CString strSound, const NiPoint3& kPos);
};
Unk_CsoGameCtx* FUN_1403ed280();

class Unk_CsoSpawnMgr
{
public:
    Unk_PCBaseFxLib* FUN_1411bf1e0();
};
extern Unk_CsoSpawnMgr* DAT_143ab6dc8;
// @0x140a50010
inline Unk_CsoSpawnMgr* FUN_140a50010() { return DAT_143ab6dc8; }

CString FUN_1409a2360(const char* psz, int n);
// ATL operator==(const CStringW&, const CStringW&): this copy (0x140164830) is not the one the symbol table names.
bool FUN_140164830(const CStringW& a, const CStringW& b);
CStringW FUN_1401aa6a0(int nId);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CubeSpawnObject);

// ---- the unit's header statics ----
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140a4e690
CubeSpawnObject::CubeSpawnObject()
    : m_nAnimState(0), m_pD48(0), m_mapAnim(17, .75f, .25f, 2.25f, 10), m_spNpc(0), m_entity(0), m_spFx(0),
      m_nGaugeA(300), m_nGaugeB(500), m_strOwner(L"")
{
    m_str88 = "GameObject";
    m_spStateMgr.AssignRaw(new CStateManager(this));
    m_spStateMgr->FUN_1417daeb0(1, new StateIdleSpawnObject(this));
    m_spStateMgr->FUN_1417daeb0(0x19, new StateInterActionSpawnObject(this));
    m_f164 = FUN_1401d3200()->m_588.FUN_1402bac70();
    m_f168 = FUN_1401d3200()->m_690.FUN_1402bac70();
    m_f16c = FUN_1401d3200()->m_5e0.FUN_1402bac70();
    m_f170 = 0.0f;
    m_f174 = 0.0f;
    m_f178 = FUN_1401d3200()->m_6e8.FUN_1402bac70();
    m_mapAnim.SetAt(0x5a, "Idle_A");
    m_mapAnim.SetAt(0x62, "Grow_A");
    m_mapAnim.SetAt(99, "Full_A");
    m_mapAnim.SetAt(100, "Gift_A");
    m_mapAnim.SetAt(0x65, "Play_A");
    m_mapAnim.SetAt(0x66, "Hungry_A");
    m_mapAnim.SetAt(0x67, "Eat_A");
}

// @0x140a4ebe0
CubeSpawnObject::~CubeSpawnObject()
{
    m_spNpc = 0;
    m_entity = 0;
    if (m_spFx.get())
    {
        FUN_141993750(FUN_14123c580());
        m_spFx = 0;
    }
}

// @0x140a4ed00
int CubeSpawnObject::vfunc_124(int nNpcId, Unk_EntRef ent, int nGaugeA, int nGaugeB, const CStringW& strOwner)
{
    m_spNpc = FUN_1406d6e90()->FUN_140a7cab0(nNpcId);
    if (m_spNpc == NULL)
        return 0;
    m_entity = ent;
    m_nGaugeA = nGaugeA;
    m_nGaugeB = nGaugeB;
    m_strOwner = strOwner;
    CString strPath;
    strPath.Format("urn:gamebryo-animation:%s", (const char*)m_spNpc->m_strModel);
    FUN_14123bb80(strPath);
    m_fScaleAC = m_spNpc->m_fScale;
    FUN_14123c280(m_spNpc->m_fScale);
    CStringW strName = FUN_1401aa6a0(m_spNpc->FUN_1406cce20());
    if (!strName.IsEmpty())
    {
        if (m_spNpc->FUN_140a7c8d0())
            vfunc_76(strName);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140a4ed00, CubeSpawnObject, vfunc_124, 700, 0x45FDEF8A);

// @0x140a4efd0
int CubeSpawnObject::vfunc_116()
{
    return 1;
}

// @0x140a4eff0
int CubeSpawnObject::vfunc_69()
{
    if (m_spNpc == NULL)
        return 0;
    if (m_spNpc->m_nB4 != 0)
        return m_spNpc->m_nB4;
    return m_spNpc->FUN_1406cce20();
}
MS2_REPLACE_METHOD(0x140a4eff0, CubeSpawnObject, vfunc_69, 128, 0xCE493C67);

// @0x140a4f080
Unk_PCBaseFxLib* CubeSpawnObject::vfunc_70()
{
    return FUN_140a50010()->FUN_1411bf1e0();
}
MS2_REPLACE_METHOD(0x140a4f080, CubeSpawnObject, vfunc_70, 27, 0xC7E44435);

// @0x140a4f0b0
MS2Ptr<Unk_PCBaseComp_aa8> CubeSpawnObject::vfunc_85()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && !FUN_14123dbd0())
        return MS2Ptr<Unk_PCBaseComp_aa8>(0);
    if (m_spAA8 == NULL)
        m_spAA8 = FUN_1418fbdb0(m_unk_70);
    return m_spAA8;
}
MS2_REPLACE_METHOD(0x140a4f0b0, CubeSpawnObject, vfunc_85, 236, 0x2B063CFF);

// @0x140a4f1b0
MS2Ptr<Unk_NpcData> CubeSpawnObject::GetNpc()
{
    return m_spNpc;
}
MS2_REPLACE_METHOD(0x140a4f1b0, CubeSpawnObject, GetNpc, 67, 0x3741EA17);

// @0x140a4f200
void CubeSpawnObject::FUN_140a4f200(void* p)
{
    m_pD48 = p;
}
MS2_REPLACE_METHOD(0x140a4f200, CubeSpawnObject, FUN_140a4f200, 28, 0x3CB6144A);

// @0x140a4f230
void CubeSpawnObject::FUN_140a4f230(int a, int b)
{
    if (m_spFx.get())
        m_spFx->FUN_141993420(m_nGaugeA, m_nGaugeB, a, b);
}
MS2_REPLACE_METHOD(0x140a4f230, CubeSpawnObject, FUN_140a4f230, 110, 0xC1319B93);

// @0x140a4f2b0
void CubeSpawnObject::FUN_140a4f2b0(unsigned int nState)
{
    CString strAnim("");
    if (m_mapAnim.Lookup(nState, strAnim))
        FUN_14166dd20(efd::utf8string(FUN_1409a2360(strAnim, 0)), 1.0f, false, false);
    m_nAnimState = nState;
}
MS2_REPLACE_METHOD(0x140a4f2b0, CubeSpawnObject, FUN_140a4f2b0, 301, 0x4DD60614);

// @0x140a4f3f0
void CubeSpawnObject::FUN_140a4f3f0(int n)
{
    if (m_spNpc == NULL)
        return;
    if (!FUN_140a4f690())
        return;
    Unk_TalkScriptPtr spScript = FUN_140856fa0(m_spNpc->FUN_1406cce20(), n);
    if (spScript.FUN_14078f3a0())
    {
        if (spScript.FUN_14085a610()->m_contents.FUN_14078fae0() > 0)
        {
            MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = vfunc_85();
            if (spBalloon.get() ? true : false)
            {
                if (spBalloon->vfunc_8(0))
                {
                    CStringW strText = spScript.FUN_14085a610()->m_contents.FUN_140a4ffc0(0).FUN_14078f3d0()->m_strText;
                    if (strText.GetLength() > 0)
                        FUN_14166fff0(strText);
                    if (spScript.FUN_14085a610()->m_contents.FUN_140a4ffc0(0).FUN_14078f3d0()->m_strSound.GetLength() > 0)
                        FUN_1403ed280()->FUN_1411a4f40(
                            spScript.FUN_14085a610()->m_contents.FUN_14078f350(0).FUN_14078f3d0()->m_strSound,
                            vfunc_18());
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140a4f3f0, CubeSpawnObject, FUN_140a4f3f0, 655, 0x7F90AEE9);

// @0x140a4f690
int CubeSpawnObject::FUN_140a4f690()
{
    if (FUN_140164830(m_strOwner, FUN_1401d3200()->m_94a8.FUN_140a50020()))
        return false;
    return FUN_1401c0d90()->FUN_1404793a0(FUN_1401d3200()->m_94a8.FUN_140a50020());
}
MS2_REPLACE_METHOD(0x140a4f690, CubeSpawnObject, FUN_140a4f690, 112, 0x1E480BE2);

// @0x140a4f710
void CubeSpawnObject::vfunc_9(void* p)
{
    PCBase::vfunc_9(p);
    if ((m_entity.FUN_1408a9090() ? true : false) && (m_spNpc.get() ? true : false))
    {
        efd::Point3 kPos = efd::Point3::ZERO;
        efd::Point3 kDir = efd::Point3::ZERO;
        m_entity.FUN_1408a9280()->FUN_1409618c0(0xfd95ca52, kPos);
        m_entity.FUN_1408a9280()->FUN_1409618c0(0x68c7c29d, kDir);
        kPos = kPos + m_spNpc->m_offset;
        vfunc_19(kPos);
        vfunc_21(kDir);
        vfunc_59(1, NULL, 0, 0);
        if (FUN_140a4f690())
        {
            if ((m_spFx = FUN_1419936d0(FUN_14123c580())).get())
            {
                m_spFx->FUN_1419933e0();
                m_spFx->FUN_141992140(FUN_140a4f690());
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140a4f710, CubeSpawnObject, vfunc_9, 718, 0x44CD5478);

// @0x140a4f9f0
void CubeSpawnObject::vfunc_12()
{
    PCBase::vfunc_12();
    for (size_t i = 0; i < m_spNpc->m_parts.FUN_14078cd60(); i++)
        FUN_141674ef0(m_spNpc->m_parts.FUN_140789540(i));
    vfunc_59(1, NULL, 0xa8, 0);
}
MS2_REPLACE_METHOD(0x140a4f9f0, CubeSpawnObject, vfunc_12, 182, 0x080792C4);

// @0x140a4fab0
int CubeSpawnObject::vfunc_11()
{
    if (!GameObject::vfunc_11())
        return 0;
    vfunc_109(0);
    return 1;
}
MS2_REPLACE_METHOD(0x140a4fab0, CubeSpawnObject, vfunc_11, 58, 0x3360C81A);

// @0x140a4faf0
void CubeSpawnObject::vfunc_53(float f)
{
    PCBase::vfunc_53(f);
    if (m_spFx.get())
    {
        if (FUN_140a4f690())
        {
            if (!m_spFx->FUN_141992160())
                m_spFx->FUN_141992140(1);
        }
        else
        {
            if (m_spFx->FUN_141992160())
                m_spFx->FUN_141992140(0);
        }
    }
}
MS2_REPLACE_METHOD(0x140a4faf0, CubeSpawnObject, vfunc_53, 203, 0x5C3E9953);
