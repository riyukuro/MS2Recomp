// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). World-anchored HUD widget base: UIHudEntity and its
// Entity / TimerEntity helpers (UIBanner, UIBuffBalloon, UIHpBar, UINameTag ... derive from them).
// MS2-UNIT: ?\uihudentity.cpp
// MS2-RANGE: 0x140f48b40-0x140f4ab90 .text$mn
// MS2-RANGE: 0x1400df730-0x1400df8c0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?__empty_global_delete@@YAXPEAX_K@Z 0x140f49510 ; unique
// MS2-PIN: ?__empty_global_delete@@YAXPEAX@Z 0x140f49530
// MS2-PIN: ??__Es_pointer1401cd100@@YAXXZ 0x1400df850
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihudentity.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uihudentity.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The unit's statics: the shared header statics (a pointer handle sits between "stun" and the condition).
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uichatballoon_ptr.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION

// Unit-local declarations; the unidentified names describe uses rather than original class names.
class Unk_HudActor : public PCBase
{
public:
    int FUN_14166c930();                                // action id
    int FUN_14166c960();                                // action id while the model is not loaded
    Unk_HudActor* FUN_1416764a0();                      // ridden character
    int FUN_141674bc0();
    NiAVObject* FUN_141675150(const CStringA& strNode); // the named node of the actor
    float FUN_140f4a450();          // distance used by Entity::vfunc_8
};
class Unk_HudWorld
{
public:
    Unk_HudActor* FUN_141bd1200(int nActorId);          // actor by id
};
Unk_HudWorld* FUN_1403ed2d0();
// 12-byte screen point with the out-of-line default ctor 0x1405522f0.
struct Unk_HudPoint3 { Unk_HudPoint3(); float x, y, z; };
class Unk_HudCamera
{
public:
    bool FUN_140af0700(const NiPoint3& ptWorld, Unk_HudPoint3& ptScreen);    // world -> screen; false when off screen
};
Unk_HudCamera* FUN_1409478c0();
class Unk_HudSub { public: char m_pad[8]; };
class Unk_HudFlags { public: char m_pad[8]; Unk_HudSub m_sub; };
Unk_HudFlags* FUN_14086d260();
void* FUN_140af8310(Unk_HudSub* p);
bool FUN_14207c4d0(void* p);
const NiPoint3* FUN_140947900(NiAVObject* pNode);       // world translation of the node
int FUN_141277f40();                                    // next UI layer
MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);   // new ASGameEntity(v, n)

// @0x140f48b40
UIHudEntity::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : m_18(nLayer), m_1c(nActorId), m_20(0), m_28("Eff_UI")
{
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_38 = FUN_140ba77e0(nLayer, clip);
    FUN_140f48dc0(0);
}

// @0x140f48c70
UIHudEntity::Entity::~Entity()
{
    m_38 = 0;
}

// @0x140f48ce0
void UIHudEntity::Entity::FUN_140f48ce0(int nActorId)
{
    m_1c = nActorId;
    m_20 = 0;
    m_30 = 0;
}

// @0x140f48d20
int UIHudEntity::Entity::FUN_140f48d20()
{
    return m_1c;
}

// @0x140f48d40
int UIHudEntity::Entity::FUN_140f48d40()
{
    return m_4c;
}

// @0x140f48d60
int UIHudEntity::Entity::FUN_140f48d60()
{
    return m_48;
}

// @0x140f48d80
void UIHudEntity::Entity::FUN_140f48d80()
{
    m_48 = 1;
}

// @0x140f48da0
void UIHudEntity::Entity::FUN_140f48da0()
{
    m_50 = 1;
}

// @0x140f48dc0
void UIHudEntity::Entity::FUN_140f48dc0(int bVisible)
{
    if (m_38.get())
        m_38->vfunc_3(bVisible);
}

// @0x140f4a450
float Unk_HudActor::FUN_140f4a450()
{
    return (float&)m_unk_bc;
}

// @0x140f48e20
float UIHudEntity::Entity::FUN_140f48e20()
{
    Unk_HudActor* pActor = (Unk_HudActor*)FUN_140f49330();
    if (pActor)
        return pActor->FUN_140f4a450();
    return 1e9f;
}

// @0x140f48e60
int UIHudEntity::Entity::FUN_140f48e60()
{
    return m_58;
}

// @0x140f48e80
void UIHudEntity::Entity::FUN_140f48e80(int n)
{
    if (m_58 != n)
    {
        if (n == 0)
            FUN_140f48d80();
        m_58 = n;
    }
}

// @0x140f48ed0
MS2Ptr<ASGameEntity> UIHudEntity::Entity::FUN_140f48ed0()
{
    return m_38;
}

// @0x140f48f20
void UIHudEntity::Entity::vfunc_1()
{
    m_1c = 0;
    m_28 = "Eff_UI";
    m_20 = 0;
    m_30 = 0;
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_58 = 0;
}

// @0x140f48fb0
void UIHudEntity::Entity::vfunc_2()
{
    m_48 = 1;
    m_4c = 1;
}

// @0x140f48fe0
void UIHudEntity::Entity::vfunc_3()
{
    m_48 = 0;
    m_4c = 0;
}

// @0x140f49010
void UIHudEntity::Entity::vfunc_4()
{
    FUN_140f48dc0(0);
    vfunc_1();
}

// @0x140f49040
void UIHudEntity::Entity::vfunc_5()
{
    if (m_38.get())
        m_38->vfunc_3(1);
    m_48 = 0;
}

// @0x140f490b0
// MS2-FUNCTIONAL: the cl output differs from the exe only in the layout of the nested ridden-actor tests (+9 bytes)
int UIHudEntity::Entity::vfunc_8(int n)
{
    if (m_50 != 0)
        return 0;
    if (FUN_140f48e20() > m_54)
        return 1;
    Unk_HudActor* pActor = (Unk_HudActor*)FUN_140f49330();
    if (pActor == 0)
        return 1;
    int nAction = pActor->FUN_14123bea0() ? pActor->FUN_14166c930() : pActor->FUN_14166c960();
    switch (nAction)
    {
    case 0x3f:
        return 1;
    }
    if (pActor->FUN_14123c660() && n == 0)
    {
        Unk_HudActor* pRidden = pActor->FUN_1416764a0();
        if (pRidden)
        {
            if (pRidden->FUN_14123c660())
                return 1;
        }
    }
    if (pActor->FUN_141674bc0() && n == 0)
        return 1;
    return 0;
}

// @0x140f491d0
float UIHudEntity::Entity::vfunc_9()
{
    return 0.0f;
}

// @0x140f491e0
// MS2-FUNCTIONAL: the exe converts the vfunc_18 result through an out-of-line NiPoint3(const Point3&) COMDAT; the cl output returns it directly
NiPoint3 UIHudEntity::Entity::vfunc_10()
{
    Unk_HudActor* pActor = (Unk_HudActor*)FUN_140f49330();
    if (pActor == 0)
        return NiPoint3::ZERO;
    int bChanged = 0;
    if (pActor->FUN_14123c660() != 0)
    {
        Unk_HudActor* pRidden = pActor->FUN_1416764a0();
        if (pRidden != 0)
        {
            bChanged = 1;
            pActor = pRidden;
        }
    }
    if (m_30 != pActor)
        bChanged = 1;
    if (m_20 == 0 || bChanged)
    {
        m_20 = pActor->FUN_141675150(m_28);
        m_30 = pActor;
    }
    if (m_20 == 0)
        return pActor->vfunc_18();
    return *FUN_140947900(m_20);
}

// @0x140f49330
PCBase* UIHudEntity::Entity::FUN_140f49330()
{
    return (PCBase*)FUN_1403ed2d0()->FUN_141bd1200(m_1c);
}

// @0x140f49360
UIHudEntity::TimerEntity::TimerEntity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : Entity(nLayer, clip, nActorId), m_60(0), m_64(0)
{
    m_38 = FUN_140ba77e0(nLayer, clip);
}

// @0x140f49430
UIHudEntity::TimerEntity::~TimerEntity()
{
}

// @0x140f49470
void UIHudEntity::TimerEntity::FUN_140f49470()
{
    m_60 = 1;
}

// @0x140f49490
void UIHudEntity::TimerEntity::vfunc_2()
{
    Entity::vfunc_2();
    m_68.FUN_140868750(m_64);
}

// @0x140f494d0
void UIHudEntity::TimerEntity::vfunc_3()
{
    Entity::vfunc_3();
    m_60 = 0;
    m_68.FUN_140868820();
}

// @0x140f49540
int UIHudEntity::TimerEntity::vfunc_8(int n)
{
    if (m_60 == 0 && m_68.FUN_140868ba0() == 0)
        return 1;
    return Entity::vfunc_8(n);
}

// @0x140f49590
UIHudEntity::UIHudEntity()
    : m_68(0), m_70(""), m_78(10), m_a8(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_28 = FUN_141277f40();
}

// @0x140f49670
UIHudEntity::~UIHudEntity()
{
}

// @0x140f496f0
CString UIHudEntity::vfunc_1()
{
    return "HudEntity";
}

// @0x140f49740
void UIHudEntity::FUN_140f49740()
{
    CAtlList<PCBase*> lstActors(10);
    for (POSITION pos = m_a8.GetStartPosition(); pos != 0; m_a8.GetNext(pos))
    {
        const int& nActorId = m_a8.GetKeyAt(pos);
        PCBase* pActor = (PCBase*)FUN_1403ed2d0()->FUN_141bd1200(nActorId);
        if (pActor == 0)
            continue;
        lstActors.AddTail(pActor);
    }
    for (POSITION pos = lstActors.GetHeadPosition(); pos != 0; lstActors.GetNext(pos))
    {
        PCBase* pActor = lstActors.GetAt(pos);
        pActor->vfunc_16();
    }
    m_78.RemoveAll();
    m_a8.RemoveAll();
}

// @0x140f49890
int UIHudEntity::FUN_140f49890(int nActorId)
{
    if (FUN_14207c4d0(FUN_140af8310(&FUN_14086d260()->m_sub)))
        return 1;
    Unk_HudActor* pActor = FUN_1403ed2d0()->FUN_141bd1200(nActorId);
    if (pActor == 0)
        return 1;
    return 0;
}

// @0x140f49900
void UIHudEntity::vfunc_26()
{
    FUN_140f49740();
    UIObject::vfunc_26();
}

// @0x140f49930
void UIHudEntity::vfunc_10()
{
    FUN_140f49740();
}

// @0x140f49950
void UIHudEntity::vfunc_15()
{
    UISwfEntity::vfunc_15();
    for (POSITION pos = m_a8.GetStartPosition(); pos != 0; m_a8.GetNext(pos))
    {
        const int& nActorId = m_a8.GetKeyAt(pos);
        Unk_HudActor* pActor = FUN_1403ed2d0()->FUN_141bd1200(nActorId);
        if (pActor == 0)
            continue;
        MS2Ptr<Entity>& spEntity = m_a8.GetValueAt(pos);
        if (spEntity == 0)
            continue;
        if (spEntity->FUN_140f48d40() == 0)
            continue;
        Unk_HudPoint3 ptScreen;
        if (!FUN_1409478c0()->FUN_140af0700(spEntity->vfunc_10(), ptScreen))
        {
            if (spEntity->FUN_140f48e60() == 0)
            {
                spEntity->FUN_140f48e80(1);
                spEntity->vfunc_7();
            }
            continue;
        }
        if (spEntity->vfunc_8(0) != 0)
        {
            if (spEntity->FUN_140f48e60() == 0)
            {
                spEntity->FUN_140f48e80(1);
                spEntity->vfunc_7();
            }
            continue;
        }
        if (spEntity->FUN_140f48e60() == 1)
            spEntity->FUN_140f48e80(0);
        if (spEntity->FUN_140f48d60() != 0)
            spEntity->vfunc_5();
        spEntity->vfunc_6((NiPoint3*)&ptScreen);
    }
}

// @0x140f49c00
void UIHudEntity::FUN_140f49c00(int nActorId)
{
    MS2Ptr<Entity> spEntity(0);
    if (m_a8.Lookup(nActorId, spEntity))
    {
        spEntity->vfunc_4();
        m_a8.RemoveKey(nActorId);
        m_78.AddTail(spEntity);
    }
}

// @0x140f49cb0
void UIHudEntity::FUN_140f49cb0(int nActorId)
{
    MS2Ptr<Entity> spEntity(0);
    if (m_a8.Lookup(nActorId, spEntity))
        spEntity->FUN_140f48d80();
}

// @0x140f49d20
void UIHudEntity::FUN_140f49d20()
{
    for (POSITION pos = m_a8.GetStartPosition(); pos != 0; m_a8.GetNext(pos))
    {
        MS2Ptr<Entity> spEntity(m_a8.GetValueAt(pos));
        if (spEntity == 0)
            continue;
        spEntity->FUN_140f48d80();
    }
}

// @0x140f49de0
void UIHudEntity::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

// @0x140f4a710
int UIHudEntity::vfunc_48()
{
    return 0x4ee2;
}

MS2_REPLACE_METHOD(0x140F48CE0, UIHudEntity::Entity, FUN_140f48ce0, 48, 0x06FE79C7);
MS2_REPLACE_METHOD(0x140F48D20, UIHudEntity::Entity, FUN_140f48d20, 14, 0x8AEE455B);
MS2_REPLACE_METHOD(0x140F48D40, UIHudEntity::Entity, FUN_140f48d40, 14, 0xAA28048B);
MS2_REPLACE_METHOD(0x140F48D60, UIHudEntity::Entity, FUN_140f48d60, 14, 0x921EE467);
MS2_REPLACE_METHOD(0x140F48D80, UIHudEntity::Entity, FUN_140f48d80, 18, 0xA1EAFB60);
MS2_REPLACE_METHOD(0x140F48DA0, UIHudEntity::Entity, FUN_140f48da0, 18, 0xC9FC9738);
MS2_REPLACE_METHOD(0x140F48DC0, UIHudEntity::Entity, FUN_140f48dc0, 82, 0xB9B1360D);
MS2_REPLACE_METHOD(0x140F48E20, UIHudEntity::Entity, FUN_140f48e20, 57, 0xD5BDBBC9);
MS2_REPLACE_METHOD(0x140F48E60, UIHudEntity::Entity, FUN_140f48e60, 14, 0x7245C177);
MS2_REPLACE_METHOD(0x140F48E80, UIHudEntity::Entity, FUN_140f48e80, 61, 0xAC46794A);
MS2_REPLACE_METHOD(0x140F48ED0, UIHudEntity::Entity, FUN_140f48ed0, 65, 0xAC0C111B);
MS2_REPLACE_METHOD(0x140F48F20, UIHudEntity::Entity, vfunc_1, 125, 0x54701646);
MS2_REPLACE_METHOD(0x140F48FB0, UIHudEntity::Entity, vfunc_2, 30, 0x8414F033);
MS2_REPLACE_METHOD(0x140F48FE0, UIHudEntity::Entity, vfunc_3, 30, 0xF9D0E48B);
MS2_REPLACE_METHOD(0x140F49010, UIHudEntity::Entity, vfunc_4, 42, 0x3206CDA7);
MS2_REPLACE_METHOD(0x140F49040, UIHudEntity::Entity, vfunc_5, 91, 0x457DAC51);
MS2_REPLACE_METHOD(0x140F491D0, UIHudEntity::Entity, vfunc_9, 9, 0x4FE1E1A5);
MS2_REPLACE_METHOD(0x140F49330, UIHudEntity::Entity, FUN_140f49330, 35, 0x4533FD0D);
MS2_REPLACE_METHOD(0x140F49470, UIHudEntity::TimerEntity, FUN_140f49470, 18, 0x0F5B4D48);
MS2_REPLACE_METHOD(0x140F49490, UIHudEntity::TimerEntity, vfunc_2, 49, 0xECE3B11A);
MS2_REPLACE_METHOD(0x140F494D0, UIHudEntity::TimerEntity, vfunc_3, 53, 0x7A3F1DE3);
MS2_REPLACE_METHOD(0x140F49540, UIHudEntity::TimerEntity, vfunc_8, 71, 0x85C8D817);
MS2_REPLACE_METHOD(0x140F496F0, UIHudEntity, vfunc_1, 61, 0xC2A38782);
MS2_REPLACE_METHOD(0x140F49740, UIHudEntity, FUN_140f49740, 330, 0xBEBB3CC4);
MS2_REPLACE_METHOD(0x140F49890, UIHudEntity, FUN_140f49890, 96, 0x34967673);
MS2_REPLACE_METHOD(0x140F49900, UIHudEntity, vfunc_26, 34, 0x672D7B21);
MS2_REPLACE_METHOD(0x140F49930, UIHudEntity, vfunc_10, 24, 0x9852ECEC);
MS2_REPLACE_METHOD(0x140F49950, UIHudEntity, vfunc_15, 674, 0x94F669F7);
MS2_REPLACE_METHOD(0x140F49C00, UIHudEntity, FUN_140f49c00, 162, 0x189FE50E);
MS2_REPLACE_METHOD(0x140F49CB0, UIHudEntity, FUN_140f49cb0, 104, 0xEF230F17);
MS2_REPLACE_METHOD(0x140F49D20, UIHudEntity, FUN_140f49d20, 184, 0xFAF64041);
MS2_REPLACE_METHOD(0x140F49DE0, UIHudEntity, vfunc_41, 99, 0x358639C0);
MS2_REPLACE_METHOD(0x140F4A710, UIHudEntity, vfunc_48, 11, 0x9DE4F97B);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9770-0x142ca9800 .text$yd
