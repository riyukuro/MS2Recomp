// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CProxyGameObject: the world's per-field-object proxy.
// MS2-UNIT: unit_1416c1cc0
// MS2-RANGE: 0x1416c1cc0-0x1416c2c00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\proxygameobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/questmasktable.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/commonfiles/ugcmapdata.h"
#include "ms2/client/ms2/npcdatacli.h"
#include <efd/ISystemService.h>
#include <egf/FlatModel.h>

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
extern __int64 DAT_143ab2828;                                       // the "self" object pointer
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(int*)&egf::g_bapiContext)          // C3: was extern int DAT_143b059e8

class Unk_ProxyTarget                                               // what handle +0x18 points at
{
public:
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
    void* m_key;                                                    // +0x18 (its address is passed on)
    void* m_pad_20; void* m_pad_28; void* m_pad_30; void* m_pad_38; void* m_pad_40; void* m_pad_48;
    void* m_pad_50; void* m_pad_58; void* m_pad_60; void* m_pad_68; void* m_pad_70; void* m_pad_78;
    void* m_pad_80; void* m_pad_88; void* m_pad_90; void* m_pad_98; void* m_pad_a0; void* m_pad_a8;
    void* m_pad_b0; void* m_pad_b8; void* m_pad_c0; void* m_pad_c8; void* m_pad_d0; void* m_pad_d8;
    void* m_pad_e0; void* m_pad_e8; void* m_pad_f0; void* m_pad_f8; void* m_pad_100; void* m_pad_108;
    void* m_pad_110; void* m_pad_118; void* m_pad_120; void* m_pad_128; void* m_pad_130; void* m_pad_138;
    void* m_pad_140; void* m_pad_148; void* m_pad_150; void* m_pad_158;
    int m_160;                                                      // type; 8 = special
};
MS2_CHECK_OFFSET(Unk_ProxyTarget, m_key, 0x18);
MS2_CHECK_OFFSET(Unk_ProxyTarget, m_160, 0x160);
class Unk_Entity1411cf440 { };
class Unk_Mgr1409670f0 { };
class EntityWorldManager   // C3: member view for the former free stand-ins
{
public:
    class egf::Entity* FindEntity(class egf::EntityID const&);
};
template <> NpcDataCli* MS2Ptr<NpcDataCli>::operator->() const;
template <> MS2Ptr<NpcDataCli>& MS2Ptr<NpcDataCli>::operator=(int);
template <> MS2Ptr<NpcDataCli>& MS2Ptr<NpcDataCli>::operator=(const MS2Ptr<NpcDataCli>&);
template <> NpcDataCli* MS2Ptr<NpcDataCli>::get() const;
template <> inline MS2Ptr<CPortal>::MS2Ptr();                    // 0x1416c2ba0 (defined below; inline: worldservice units instantiate ms2ptr_impl.h's copy)

class Unk_Tbl1403ed2d0 { };                                         // object table
class Unk_PosObject                                                 // MS2: slot 18 is GetPosition
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17();
    virtual Vector3 vfunc_18();
};


CStringW FUN_1401aa6a0(int id);
class CubeMapInformationService : public efd::ISystemService { };
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
int FUN_1408a0d30(int, struct Unk_UGCGroup&, int);   // C3: was FUN_1408a0d30
class CAddressTable   // C3: static member view for the former free stand-ins
{
public:
    static CStringW FormatChecked(int, int, int, CStringW);
};

class Unk_NpcTableCli* GetNpcDataTableCli();   // C3: was GetNpcDataTableCli
class Unk_Svc764020 { };
void* FUN_140764020();   // C3: was FUN_140764020
//class CQuestManager   // C3: member view for the former free stand-ins
//{
//public:
//    int FUN_1416d12d0(int, struct Unk_QmNpcQuestState*, int);
//};
class Unk_Svc6c7600 { };
class Unk_NametagTrophy* GetAchieveManager();   // C3: was GetAchieveManager
class CAchieveManager   // C3: member view for the former free stand-ins
{
public:
    struct Unk_AchieveTab* GetTally();
};

// @0x1416c1cc0
CProxyGameObject::CProxyGameObject()
{
    m_18 = 0;
    m_28 = 0;
    m_proxyId = 0;
    m_40 = 0;
    m_48 = 0;
    kind = 0;
    m_6c = DAT_143b01a60;
    m_78 = 0;
    m_84 = 0;
    m_80 = 0;
    m_a8 = 0;
    m_dc = 0;
    m_ac = 1;
    m_b4 = 0;
    m_b8 = 0;
    m_bc = 0;
    m_c8 = 0;
    m_7c = 0;
    m_cc = 0;
    reinterpret_cast<Unk_IntTriple&>(m_d0).Clear();
    m_88.m_wantText = 1;
    m_e0 = 0;
    m_e4 = 0;
}

// @0x1416c1f00
CProxyGameObject::~CProxyGameObject()
{
    m_18 = 0;
    m_28 = 0;
}

// @0x1416c1ff0
int CProxyGameObject::IsSelf()
{
    int r;
    if (m_40 != 0 && m_40 == DAT_143ab2828) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C1FF0, CProxyGameObject, IsSelf, 63, 0x2E42A744);

// @0x1416c2040
int CProxyGameObject::IsOtherPlayer()
{
    int r;
    if (m_40 != 0 && m_40 != DAT_143ab2828) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C2040, CProxyGameObject, IsOtherPlayer, 63, 0x117FEF14);

// @0x1416c2090
int CProxyGameObject::FUN_1416c2090()
{
    int r;
    if (m_78 != 0 && m_84 == 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C2090, CProxyGameObject, FUN_1416c2090, 58, 0xA0774B98);

// @0x1416c20d0
int CProxyGameObject::HasPortal()
{
    int r;
    if (((void*)m_18.get())) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C20D0, CProxyGameObject, HasPortal, 58, 0x7AD39F1A);

// @0x1416c2110
int CProxyGameObject::FUN_1416c2110()
{
    if (HasPortal() == 0) {
        return 0;
    }
    Unk_Entity1411cf440* ent = ((class Unk_Entity1411cf440*)((class EntityWorldManager*)(class Unk_Mgr1409670f0*)(((class Unk_Mgr1409670f0*)TSingleton<EntityWorldManager>::GetInstance())))->FindEntity(*(class egf::EntityID const*)(&reinterpret_cast<Unk_ProxyTarget*>(m_18.operator->())->m_key)));
    if (ent != 0) {
        if (((class egf::FlatModel*)((egf::Entity*)(class Unk_Entity1411cf440*)(ent))->GetModel())->ContainsModel(0x7b35ceec)) {
            return 1;
        }
        if (reinterpret_cast<Unk_ProxyTarget*>(m_18.operator->())->m_160 == 8) {
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416C2110, CProxyGameObject, FUN_1416c2110, 167, 0x29EA4E0A);

// @0x1416c21c0
int CProxyGameObject::FUN_1416c21c0()
{
    int r;
    if (m_84 != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C21C0, CProxyGameObject, FUN_1416c21c0, 47, 0x5A0ED176);

// @0x1416c2200
Unk_ProxyValue88* CProxyGameObject::GetQuestState()
{
    return &m_88;
}
MS2_REPLACE_METHOD(0x1416C2200, CProxyGameObject, GetQuestState, 17, 0xEADCA25B);

// @0x1416c2220
MS2Ptr<NpcDataCli> CProxyGameObject::GetNpcData()
{
    return MS2Ptr<NpcDataCli>(m_28);
}
MS2_REPLACE_METHOD(0x1416C2220, CProxyGameObject, GetNpcData, 65, 0xD6E756B3);

// @0x1416c2270
Vector3 CProxyGameObject::GetPosition()
{
    Unk_PosObject* obj = ((class Unk_PosObject*)((class WorldService*)(class Unk_Tbl1403ed2d0*)(reinterpret_cast<Unk_Tbl1403ed2d0*>(WorldService::GetInstance())))->FindObjectById(m_proxyId));
    if (obj != 0) {
        return obj->vfunc_18();
    } else {
        return m_6c;
    }
}
MS2_REPLACE_METHOD(0x1416C2270, CProxyGameObject, GetPosition, 114, 0x6DB7BE40);

// @0x1416c22f0
void* CProxyGameObject::GetCharacterId()
{
    return reinterpret_cast<void*>(m_40);
}
MS2_REPLACE_METHOD(0x1416C22F0, CProxyGameObject, GetCharacterId, 15, 0x8B0075C1);

// @0x1416c2310
void* CProxyGameObject::FUN_1416c2310()
{
    return reinterpret_cast<void*>(m_48);
}
MS2_REPLACE_METHOD(0x1416C2310, CProxyGameObject, FUN_1416c2310, 15, 0x5AEB0F79);

// @0x1416c2330
unsigned short CProxyGameObject::GetLevel()
{
    return m_a8;
}
MS2_REPLACE_METHOD(0x1416C2330, CProxyGameObject, GetLevel, 18, 0xCD1B1572);

// @0x1416c2350
int CProxyGameObject::GetTemplateId()
{
    return m_78;
}
MS2_REPLACE_METHOD(0x1416C2350, CProxyGameObject, GetTemplateId, 14, 0xB1F80757);

// @0x1416c2370
int CProxyGameObject::FUN_1416c2370()
{
    return m_ac;
}
MS2_REPLACE_METHOD(0x1416C2370, CProxyGameObject, FUN_1416c2370, 17, 0x84EDFDD7);

// @0x1416c2390
int CProxyGameObject::GetJobCode()
{
    return m_b0;
}
MS2_REPLACE_METHOD(0x1416C2390, CProxyGameObject, GetJobCode, 17, 0x1F8D7963);

// @0x1416c23b0
CStringW CProxyGameObject::GetName()
{
    if (FUN_1416c2090() != 0) {
        {
            CStringW name = FUN_1401aa6a0(m_78);
            bool found = (!name.IsEmpty() && ((const MS2Ptr<NpcDataCli>&)GetNpcData())->GetNametag() != 0);
            if (found) {
                return name;
            }
        }
    } else {
        return m_58;
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1416C23B0, CProxyGameObject, GetName, 352, 0xD3390841);

// @0x1416c2520
CString CProxyGameObject::GetPortraitPath()
{
    return m_50;
}
MS2_REPLACE_METHOD(0x1416C2520, CProxyGameObject, GetPortraitPath, 66, 0x998DDC8A);

// @0x1416c2570
CStringW CProxyGameObject::GetTodayMemo()
{
    if (IsSelf() != 0) {
        return reinterpret_cast<PC*>(WorldService::GetInstance()->GetLocalPlayer())->GetName();
    }
    return m_60;
}
MS2_REPLACE_METHOD(0x1416C2570, CProxyGameObject, GetTodayMemo, 133, 0x325768ED);

// @0x1416c2600
CStringW CProxyGameObject::FUN_1416c2600()
{
    if (IsSelf() != 0) {
        return reinterpret_cast<MyPC*>(WorldService::GetInstance()->GetLocalPlayer())->GetHomeAddress();
    } else {
        {
            MS2Ptr<CBuddy> h = TSingleton<CBuddyManager>::GetInstance()->FindByAccount(m_40);
            if (((void*)h.get()) != 0) {
                m_b4 = h.operator->()->FUN_1401cc3e0();
                m_c0 = h.operator->()->GetHomeName();
                m_b8 = h.operator->()->FUN_1401cc3a0();
                m_bc = h.operator->()->FUN_1401cc3c0();
            }
        }
        if (m_b4 > 0) {
            efd::SmartPointer<CubeMapInformationService> ptr(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
            Unk_UGCGroup work;
            CStringW unused;
            if (FUN_1408a0d30(m_b8, work, m_b4) != 0) {
                return CAddressTable::FormatChecked(m_b4, m_b8, m_bc, m_c0);
            }
        } else {
            return m_c0;
        }
    }
    return L"";
}
MS2_REPLACE_METHOD(0x1416C2600, CProxyGameObject, FUN_1416c2600, 775, 0x4AA42C46);

// @0x1416c2920
int CProxyGameObject::GetTrophyTotal()
{
    return reinterpret_cast<Unk_IntTriple&>(m_d0).Sum();
}
MS2_REPLACE_METHOD(0x1416C2920, CProxyGameObject, GetTrophyTotal, 33, 0x5153CC8C);

// @0x1416c2950
Unk_ProxyValueD0* CProxyGameObject::GetTally()
{
    if (IsSelf() != 0) {
        return ((Unk_ProxyValueD0*)((class CAchieveManager*)(class Unk_Svc6c7600*)(((class Unk_Svc6c7600*)GetAchieveManager())))->GetTally());
    }
    return &m_d0;
}
MS2_REPLACE_METHOD(0x1416C2950, CProxyGameObject, GetTally, 54, 0x83FAF988);

// @0x1416c2990
int CProxyGameObject::SetTemplateId(int nTemplateId)
{
    m_78 = nTemplateId;
    m_28 = reinterpret_cast<NpcDataTableCli*>(GetNpcDataTableCli())->Find(m_78);
    m_dc = TSingleton<QuestDataTable>::GetInstance()->HasNpcQuests(nTemplateId);
    m_e0 = TSingleton<CQuestMaskTable>::GetInstance()->HasNpcMaskHere(nTemplateId);
    UpdateQuestState();
    int r;
    if (m_28.get()) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
MS2_REPLACE_METHOD(0x1416C2990, CProxyGameObject, SetTemplateId, 224, 0xA8CBDA0F);

// @0x1416c2a80
void CProxyGameObject::UpdateQuestState()
{
    if (FUN_1416c2090() == 0) {
        return;
    }
    if (m_dc != 0) {
        ((class CQuestManager*)(class Unk_Svc764020*)(((class Unk_Svc764020*)FUN_140764020())))->GetNpcQuestState(m_78, &m_88, 0);
    }
    if (m_e0 != 0) {
        m_e4 = TSingleton<CQuestMaskTable>::GetInstance()->CheckNpcHere(m_78);
    } else {
        m_e4 = 1;
    }
}
MS2_REPLACE_METHOD(0x1416C2A80, CProxyGameObject, UpdateQuestState, 157, 0x48E7C890);

// @0x1416c2b30
bool CProxyGameObject::IsVisibleOnMinimap()
{
    return m_e4 == 1;
}
MS2_REPLACE_METHOD(0x1416C2B30, CProxyGameObject, IsVisibleOnMinimap, 48, 0x552AC3F2);

// @0x1416c2b70
bool CProxyGameObject::FUN_1416c2b70()
{
    return m_e0 == 1;
}
MS2_REPLACE_METHOD(0x1416C2B70, CProxyGameObject, FUN_1416c2b70, 48, 0x4BF83D4E);

// @0x1416c2ba0
template <> inline MS2Ptr<CPortal>::MS2Ptr()
{
    m_p = 0;
}
