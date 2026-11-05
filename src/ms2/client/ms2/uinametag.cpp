// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Name tags above characters, npcs and pets (world-anchored,
// UIHudEntity family). Mode 1 shows name/guild/symbol, mode 2 a debug dump of the actor's stats.
// MS2-UNIT: ?\uinametag.cpp
// MS2-RANGE: 0x141a5e3c0-0x141a623e0 .text$mn
// MS2-RANGE: 0x140119150-0x140119e20 .text$di
// MS2-RANGE: 0x142cc0e50-0x142cc0f90 .text$yd
// MS2-PIN: ??0?$MS2Ptr@VEntity@UINameTag@@@@QEAA@$$QEAV0@@Z 0x141a621a0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VEntity@UINameTag@@@@QEAA@PEAVEntity@UINameTag@@@Z 0x141a621d0 ; prop
// MS2-PIN: ??__Fs_unk1402a9d70@@YAXXZ 0x142cc0ec0
// MS2-PIN: ??__Fcondition@Unk_NameTagStatics@@YAXXZ 0x142cc0f50
// MS2-PIN: ??_GEntity@UINameTag@@UEAAPEAXI@Z 0x141a62230
// MS2-PIN: ??_GUINameTag@@UEAAPEAXI@Z 0x141a62270
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uinametag.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <math.h>
#include "uinametag.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/placeholder/crideedata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/ms2format.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern "C" double (__cdecl* __imp_ceil)(double);              // the exe imports ceil from the UCRT

// The unit's statics: the name tag mode, then two copies of the shared header statics (the first one has the game
// object state name table between "stun" and the condition), then the key controller.
static int s_nNameTagMode;                                      // 0x143af45f0
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uinametag_gos.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/client/ms2/additionalclilist.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/cpet.h"
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include "ms2/placeholder/cbreakableobject.h"
#pragma pop_macro("max")
#pragma pop_macro("min")
#include "ms2/commonfiles/npcdata.h"
#include "ms2/commonfiles/pvpinfo.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<float>::Read
#undef MS2_STATICS_A_BEFORE_CONDITION
namespace Unk_NameTagStatics {
static CString sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString skill = "skill";
static CString stun = "stun";
static Unk_1402a9d70 condition(17, 0.75f, 0.25f, 2.25f, 10);
}
static UICommon::CMyPCKeyInputController s_keyController;

int FUN_141a60d30();                                                        // the name tag mode
void FUN_141a60f40();                                                       // mark every tag dirty
const char* FUN_141a61590(int nState, const std::pair<const char*, Unk_RequireState>* pTable);   // state name

// Unit-local declarations; the unidentified names describe uses rather than original class names.

// The client configuration row (FUN_1401d3200): +8 forces mode 2, +0x2c8 the default distance, +0x848 a seat offset.
// The name tag clip as the exe calls it: createEntity takes the flag as a bool.
class Unk_NtClip : public ASGameEntity
{
public:
};
class Unk_BannerClip   // C3: unit-local view (defs in uibanner); the entity clip's create / update calls
{
public:
    Scaleform::GFx::Value FUN_140ba9470(const char* szMethod, int a1, CString a2, bool a3);      // "createEntity"
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value a1, bool a2); // "updateEntity"
};

struct Unk_NtCfgFloat { char m_pad[0x58]; };
struct Unk_NtCfg
{
    char m_pad_0000[8];
    unsigned char m_8;
    char m_pad_0009[0x2c8 - 9];
    Unk_NtCfgFloat m_2c8;
    char m_pad_0320[0x848 - 0x2c8 - sizeof(Unk_NtCfgFloat)];
    Unk_NtCfgFloat m_848;
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
// The display flags (CGameOption::FUN_140b123b0, viewed as Unk_NtFlags): which tags are shown for whom.
struct Unk_NtFlags { bool m_0; bool m_1; bool m_2; bool m_3; bool m_4; bool m_5; };

class Unk_NtUIScale;
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: was FUN_14025e7a0
class GFxManager   // C3: member view for the former free stand-ins
{
public:
    float FUN_1422afec0(int);
};
float FUN_1412762d0(const NiPoint3& pt);
bool FUN_14028d470(float a, float b);                                       // a == b (within epsilon)
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned int nId);
bool FUN_1417ddbf0(const efd::ClassInfo* pInfo, int nId);           // statemanager.cpp: exact-class check (entry 0 only)

struct Unk_NtSymbolRec { char m_pad_00[0x18]; CStringW m_18; CStringW m_20; };
class Unk_NtWorld
{
public:
    PCBase* FUN_141bd0cc0();                            // the local player
};
class Unk_NtUIMgr { public: };
bool FUN_140930110(int nActorId);

// Per-actor components (PCBase members outside the header) and the smart pointers they hand out.
struct Unk_NtNpcData
{
    char m_pad_00[0x7c];
    int m_7c;                                           // rank
    char m_pad_80[0xd8 - 0x80];
    __int64 m_d8[0x1b];                                 // stats (index = stat id)
};
class Unk_NtNpc : public CNpc
{
public:
};
class Unk_NtPet : public CPet
{
public:
};
extern template class MS2Ptr<Unk_PCLinkFD8>;              // the mount seat record (pc.cpp)
class Unk_NtSeatSub { public: };
// PC with its virtuals after slot 132 (PC itself declares 124..132).
class Unk_NtPC : public PC
{
public:
    // slots 133-146 are declared by PC (placeholder/fittingdollpc.h)
};
CStringW FUN_141b720b0(int nTitle, __int64 nPc);
class Ridee : public PCBase { public: MS2SvrPtr<CRideeData> GetData(); };   // C3: member view
class Unk_NtItemMgr
{
public:
    int FUN_1406c5b00(unsigned short nId, int nKind);
    CStringW FUN_1406c6360(unsigned short nId, PC* pPc, int n);
};
class Unk_NtMgr* FUN_14131e120();   // C3: was FUN_14131e120
CStringW FUN_140b8f730(const Vector3& kPos);   // "x,y,z" (unit_140b8e760_clientdatetimehelpers.cpp)
CStringW FUN_14016a730(const char* sz, int n);
CStringW GetStringCommon(int nStringId);

// @0x141a5e3c0
UINameTag::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : UIHudEntity::Entity(nLayer, clip, nActorId)
    , m_60(0x12)
    , m_64(0xffffff)
    , m_68(0)
    , m_70("")
    , m_78(1)
    , m_7c(1)
{
    m_54 = 1500.0f;
}

// @0x141a5e480
UINameTag::Entity::~Entity()
{
}

// @0x141a5e4c0
void UINameTag::Entity::FUN_141a5e4c0(int nFontSize)
{
    if (nFontSize == 0)
        return;
    if (m_60 != nFontSize)
    {
        m_60 = nFontSize;
        m_48 = 1;
    }
}

// @0x141a5e500
void UINameTag::Entity::FUN_141a5e500(int nColor)
{
    if (m_64 != nColor)
    {
        m_64 = nColor;
        m_48 = 1;
    }
}

// @0x141a5e540
void UINameTag::Entity::FUN_141a5e540(CString strNode)
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return;
    m_28 = strNode;
    m_20 = ((class PCBase*)(class PCBase*)(pActor))->FUN_141675150(m_28);
}

// @0x141a5e5d0
int UINameTag::Entity::FUN_141a5e5d0(Unk_NtPos* pPos)
{
    if (m_38.get() != 0 && FUN_140f48d40() != 0)
    {
        m_38->GetPosition(&pPos->x, &pPos->y);
        pPos->x -= (double)m_68 * 0.5;
        return 1;
    }
    return 0;
}

// @0x141a5e690
int UINameTag::Entity::FUN_141a5e690()
{
    if (m_38.get())
        return m_38->GetVisible();
    return 0;
}

// @0x141a5e6e0
void UINameTag::Entity::vfunc_1()
{
    UIHudEntity::Entity::vfunc_1();
    m_60 = 0x12;
    m_64 = 0xffffff;
    m_68 = 0;
    m_70 = "";
    m_78 = 1;
    m_7c = 1;
}

// @0x141a5e760
void UINameTag::Entity::vfunc_2()
{
    UIHudEntity::Entity::vfunc_2();
}

// @0x141a5e780
void UINameTag::Entity::vfunc_3()
{
    UIHudEntity::Entity::vfunc_3();
    m_68 = 0;
}

// @0x141a5e7b0
void UINameTag::Entity::vfunc_4()
{
    UIHudEntity::Entity::vfunc_4();
    m_60 = 0x12;
    m_64 = 0xffffff;
    m_68 = 0;
    m_70 = "";
}

// @0x141a5e810
void UINameTag::Entity::vfunc_5()
{
    UIHudEntity::Entity::vfunc_5();
    if (FUN_141a60d30() == 1)
        FUN_141a5ff60();
    else if (FUN_141a60d30() == 2)
        FUN_141a5f080();
    if (m_38.get() != 0)
    {
        Scaleform::GFx::Value width = m_38->Invoke("getTextWidth");
        m_68 = (unsigned int)__imp_ceil(((Scaleform::GFx::Value*)(void*)(&width))->GetNumber());
    }
}

// @0x141a5e8d0
void UINameTag::Entity::vfunc_6(NiPoint3* pPos)
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return;
    if (m_38.get() != 0)
    {
        if (FUN_141a60d30() == 2)
            FUN_141a5f080();
        *pPos *= ((class GFxManager*)(class Unk_NtUIScale*)(((class Unk_NtUIScale*)FUN_14025e7a0())))->FUN_1422afec0(m_18);
        pPos->y += vfunc_9();
        float fDist = FUN_140f48e20();
        bool bNear = !(700.0f < fDist) || WorldService::GetInstance()->FUN_141bd30a0()->m_nGlobalNameTag != 0;
        if (bNear)
            m_38->SetAlpha(100.0f);
        else
            m_38->SetAlpha((m_54 - fDist) * 0.05f + 40.0f);
        if (FUN_14028d470(reinterpret_cast<AdditionalCliList*>(pActor->FUN_1416749a0())->ComputeAlphaBlending(), 0.0f))
            m_38->SetAlpha(0.0f);
        float fY = pPos->y;
        fY += FUN_1412762d0(vfunc_10());
        m_38->SetPositionFloat(pPos->x, fY);
    }
}

// @0x141a5eb80
void UINameTag::Entity::vfunc_7()
{
    if (m_38.get() != 0)
        m_38->vfunc_3(0);
}

// @0x141a5ebe0
int UINameTag::Entity::vfunc_8(int n)
{
    if (FUN_141a60d30() == 0)
        return 1;
    {
        PCBase* pPlayer = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPlayer == 0)
            return 1;
    }
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return 1;
    switch (((class PCBase*)(class PCBase*)(pActor))->GetCurStateId())
    {
    case 0x3f:
        return 1;
    }
    if (FUN_141a60920() == 0)
        return 1;
    Ridee* pHolder = ((class Ridee*)((class PCBase*)(class PCBase*)(pActor))->FUN_1416764a0());
    if (pHolder != 0)
    {
        MS2SvrPtr<CRideeData> spMount = pHolder->GetData();
        bool bMounted = ((CRideeData*)spMount ? true : false) && spMount->FUN_140784970()->m_nNameTagHide != 0;
        if (bMounted)
            return 1;
    }
    return UIHudEntity::Entity::vfunc_8(((class PCBase*)(class PCBase*)(pActor))->IsDead());
}

// @0x141a5edb0
NiPoint3 UINameTag::Entity::vfunc_10()
{
    if (PC* pPc = dynamic_cast<PC*>(FUN_140f49330()))
    {
        if (Unk_NtSeatSub* pSeat = (Unk_NtSeatSub*)pPc->FUN_14165ca20())
        {
            NiPoint3 base = UIHudEntity::Entity::vfunc_10();
            NiPoint3 pos(((CBreakableObject*)pSeat)->GetPtPos());
            pos.z = base.z;
            return pos;
        }
    }
    return UIHudEntity::Entity::vfunc_10();
}

// @0x141a5eea0
float UINameTag::Entity::vfunc_9()
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return 0.0f;
    Unk_NtPC* pPc = reinterpret_cast<Unk_NtPC*>(efd::DynamicCast<PC, PCBase>(pActor));
    if (pPc != 0)
    {
        bool bSeated = ((class PCBase*)(class PCBase*)(pPc))->IsDead() != 0 && (pPc->FUN_141657730().get() ? true : false)
            && reinterpret_cast<UIHudEntity::Entity*>(pPc->FUN_141657730().operator->())->FUN_140f48d40() != 0;
        if (bSeated)
            return reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_NtCfg*)FUN_1401d3200())->m_848)->Read();
    }
    if (pActor != 0)
        return pActor->vfunc_89();
    return 0.0f;
}

// @0x141a5f040
void UINameTag::Entity::FUN_141a5f040(const CString& strSkin)
{
    m_70 = strSkin;
    FUN_140f48d80();
}

#ifndef MS2_HOOK_DLL
// @0x141a5f080
void UINameTag::Entity::FUN_141a5f080()
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return;
    if (m_38.get() != 0)
    {
        m_38->SetAlpha(100.0f);
        ASObj obj(m_18);
        CStringW strInfo;
        CStringW strStats;
        Unk_NtPC* pPc = reinterpret_cast<Unk_NtPC*>(efd::DynamicCast<PC, PCBase>(pActor));
        if (pPc != 0)
        {
            __int64 nHp, nMaxHp, nStr, nInt, nDex, nLuk, nPen, nPap, nMap;
            nHp = ((class PCBase*)(class PCBase*)(pPc))->FUN_141670a00(4);
            nMaxHp = ((class PCBase*)(class PCBase*)(pPc))->FUN_141670a30(4);
            nPap = ((class PCBase*)(class PCBase*)(pPc))->FUN_141670a00(0x17);
            nMap = ((class PCBase*)(class PCBase*)(pPc))->FUN_141670a00(0x18);
            nStr = ((class PCBase*)(class PCBase*)(pPc))->FUN_141670a00(0);
            nDex = ((class PCBase*)(class PCBase*)(pPc))->FUN_141670a00(1);
            nLuk = ((class PCBase*)(class PCBase*)(pPc))->FUN_141670a00(3);
            nPen = ((class PCBase*)(class PCBase*)(pPc))->FUN_141670a00(0x1f);
            nInt = ((class PCBase*)(class PCBase*)(pPc))->FUN_141670a00(2);
            strStats = StringFormat(L"hp:{0}/{1} str:{2} int:{3} dex:{4} luk:{5} pen:{6} pap:{7} map:{8}",
                                    nHp, nMaxHp, nStr, nInt, nDex, nLuk, nPen, nPap, nMap);
            strInfo = StringFormat(L"{0} state:[{1}] pos:[{2}] rot:[{3}] {4}",
                                   pPc->vfunc_77(),
                                   FUN_14016a730(FUN_141a61590(((class PCBase*)(class PCBase*)(pPc))->GetCurStateId(), s_gosNames), 0),
                                   FUN_140b8f730(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pPc->vfunc_18()))),
                                   FUN_140b8f730(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pPc->vfunc_20()))),
                                   pPc->vfunc_134());
        }
        else if (Unk_NtNpc* pNpc = reinterpret_cast<Unk_NtNpc*>(efd::DynamicCast<CNpc, PCBase>(pActor)))
        {
            __int64 nHp, nMaxHp, nPap, nMap, nNdd, nPar, nMar, nAtp, nEvp, nAbp, nMsp, nCar;
            nHp = ((class PCBase*)(class PCBase*)(pNpc))->FUN_141670a00(4);
            nPap = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0x17];
            nMap = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0x18];
            nNdd = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0x14];
            nPar = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0x19];
            nMar = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0x1a];
            nAtp = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0xf];
            nEvp = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0x10];
            nAbp = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0x15];
            nMsp = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0xe];
            nCar = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0x13];
            nMaxHp = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_d8[0x4];
            strStats = StringFormat(L"hp:{0}/{1} pap:{2} map:{3} ndd:{4} par:{5} mar:{6} atp:{7} evp:{8}, abp:{9}, msp:{10}, car:{11}",
                                    nHp, nMaxHp, nPap, nMap, nNdd, nPar, nMar, nAtp, nEvp, nAbp, nMsp, nCar);
            int aRankStr[9] = {0x573, 0xaf, 0xb0, 0xb1, 0xb3, 0xb5, 0xb4, 0xb2};
            unsigned short nLevel = (unsigned short)pNpc->vfunc_78();
            int nRank = reinterpret_cast<Unk_NtNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_7c;
            strInfo.Format(L"name:[%s] state:[%s] lv:%d rank:[%s]",
                           (LPCWSTR)pNpc->vfunc_77(),
                           (LPCWSTR)FUN_14016a730(FUN_141a61590(((class PCBase*)(class PCBase*)(pNpc))->GetCurStateId(), s_gosNames), 0),
                           (unsigned int)nLevel,
                           (LPCWSTR)GetStringCommon(aRankStr[nRank]));
            bool bShop = reinterpret_cast<CNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->GetShopId() > 0;
            if (bShop)
                strInfo.AppendFormat(L" shopID:[%d]", reinterpret_cast<CNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->GetShopId());
            Unk_NtPet* pPet = static_cast<Unk_NtPet*>(efd::DynamicCast<CPet>(pActor));
            if (pPet != 0)
                strInfo.AppendFormat(L" tamingLevel:[%d], tamerOID:[%d], tamingPoint:[%d]",
                                     pPet->GetGrade(), pPet->GetKind(), pPet->GetTamingPoint());
        }
        obj.FUN_1407cb9c0("visibleSymbol", m_7c);
        obj.FUN_1407cb9c0("visibleName", m_78);
        obj.FUN_1407cbb20("name", strInfo);
        obj.FUN_1407cbb20("guild", strStats);
        obj.FUN_1409c0d20("fontSize", m_60);
        obj.FUN_1409c0d20("fontColor", m_64);
        m_38->Invoke("setData", obj);
    }
}
#endif

// @0x141a5ff60
void UINameTag::Entity::FUN_141a5ff60()
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return;
    if (m_38.get() != 0)
    {
        m_38->SetAlpha(100.0f);
        ASObj obj(m_18);
        CStringW strName;
        CStringW strGuild;
        strName = pActor->vfunc_77();
        Unk_NtPC* pPc = reinterpret_cast<Unk_NtPC*>(efd::DynamicCast<PC, PCBase>(pActor));
        if (pPc != 0)
        {
            strGuild = L"";
            if (pPc->FUN_141656be0().GetLength() > 0)
                strGuild = StringFormat(L"<{0}>", pPc->FUN_141656be0());
            if (((class PC*)(class PC*)(pPc))->FUN_141661c50() != 0)
                strName = StringFormat(L"{0} {1}", FUN_141b720b0(((class PC*)(class PC*)(pPc))->FUN_141661c50(), (__int64)pPc), strName);
            bool bSymbol = false;
            if (Unk_NtSymbolRec* pRec = reinterpret_cast<Unk_NtSymbolRec*>(WorldService::GetInstance()->FindFieldProperty(5)))
            {
                Unk_NtSymbolRec& rec = *pRec;
                if (((class PCBase*)(class PC*)(pPc))->FUN_141678320() == 1)
                {
                    obj.FUN_1407cbb20("symbol", rec.m_18);
                    bSymbol = true;
                }
                else if (((class PCBase*)(class PC*)(pPc))->FUN_141678320() == 2)
                {
                    obj.FUN_1407cbb20("symbol", rec.m_20);
                    bSymbol = true;
                }
            }
            bool bTeam = !bSymbol && ((CPvPInfo*)pPc->FUN_140967420() ? true : false)
                         && pPc->FUN_140967420()->FUN_140743610();
            if (bTeam)
            {
                bool bRed = pPc->FUN_140967420()->GetPoint() == 0xc9;
                if (bRed)
                {
                    obj.FUN_1409c0dc0("symbol", "red_team");
                    bSymbol = true;
                }
                else
                {
                    bool bBlue = pPc->FUN_140967420()->GetPoint() == 0xca;
                    if (bBlue)
                    {
                        obj.FUN_1409c0dc0("symbol", "blue_team");
                        bSymbol = true;
                    }
                }
            }
            if (!bSymbol)
            {
                unsigned short nId = ((class PCBase*)(class PC*)(pPc))->FUN_141661e00();
                if (((class Unk_NtItemMgr*)FUN_14131e120())->FUN_1406c5b00(nId, 2) != 0)
                {
                    int nGrade, nRank;
                    if (((class PC*)(class PC*)(pPc))->FUN_141661e40(&nGrade, &nRank) != 0)
                    {
                        obj.FUN_1409c0dc0("symbol", "enchant");
                        obj.FUN_1407cb9c0("grade", nGrade);
                        obj.FUN_1409adc90("rank", nRank);
                    }
                }
                else if (((class PCBase*)(class PC*)(pPc))->FUN_141661e20() != 0)
                {
                    const CStringW& strIcon = ((class Unk_NtItemMgr*)FUN_14131e120())->FUN_1406c6360(nId, pPc, 0);
                    obj.FUN_1407cbb20("symbol", strIcon);
                    if (((class Unk_NtItemMgr*)FUN_14131e120())->FUN_1406c5b00(nId, 1) != 0)
                        obj.FUN_1409c48f0("level", (short)pPc->vfunc_78());
                    else if (((class Unk_NtItemMgr*)FUN_14131e120())->FUN_1406c5b00(nId, 0xb) != 0)
                        obj.FUN_1409c0d20("level", pPc->vfunc_141());
                }
            }
        }
        else if (Unk_NtNpc* pNpc = reinterpret_cast<Unk_NtNpc*>(efd::DynamicCast<CNpc, PCBase>(pActor)))
        {
            strGuild = pNpc->FUN_141093980();
        }
        obj.FUN_1407cb9c0("visibleSymbol", m_7c);
        obj.FUN_1407cb9c0("visibleName", m_78);
        obj.FUN_1407cbb20("name", strName);
        obj.FUN_1407cbb20("guild", strGuild);
        obj.FUN_1409c0d20("fontSize", m_60);
        obj.FUN_1409c0d20("fontColor", m_64);
        obj.FUN_1407cba60("skin", m_70);
        m_38->Invoke("setData", obj);
    }
}

// @0x141a60920
int UINameTag::Entity::FUN_141a60920()
{
    PCBase* pPlayer = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return 0;
    if (FUN_1417ddbf0(pActor ? pActor->GetClassDesc() : 0, 0x6200004))   // the exe uses the exact-class check here
    {
        FUN_141a60b90(reinterpret_cast<Unk_NtFlags*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_1, reinterpret_cast<Unk_NtFlags*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_0);
        return m_78 != 0 || m_7c != 0;
    }
    else if (Unk_NtPC* pPc = reinterpret_cast<Unk_NtPC*>(efd::DynamicCast<PC, PCBase>(pActor)))
    {
        if (pPlayer->vfunc_122(pPc) == 0)
        {
            FUN_141a60b90(reinterpret_cast<Unk_NtFlags*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_1, reinterpret_cast<Unk_NtFlags*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_2);
        }
        else
        {
            FUN_141a60b90(reinterpret_cast<Unk_NtFlags*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_1, reinterpret_cast<Unk_NtFlags*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_3);
        }
        return m_78 != 0 || m_7c != 0;
    }
    else if (Unk_NtPet* pPet = static_cast<Unk_NtPet*>(efd::DynamicCast<CPet>(pActor)))
    {
        return 1;
    }
    else if (Unk_NtNpc* pNpc = reinterpret_cast<Unk_NtNpc*>(efd::DynamicCast<CNpc, PCBase>(pActor)))
    {
        if (pNpc->vfunc_116() == 0)
            return reinterpret_cast<Unk_NtFlags*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_5;
        else
            return reinterpret_cast<Unk_NtFlags*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_4;
    }
    return 0;
}

// @0x141a60b90
void UINameTag::Entity::FUN_141a60b90(int nVisibleSymbol, int nVisibleName)
{
    if (m_7c != nVisibleSymbol)
        FUN_140f48d80();
    m_7c = nVisibleSymbol;
    if (m_78 != nVisibleName)
        FUN_140f48d80();
    m_78 = nVisibleName;
}

// @0x141a60c00
UINameTag::UINameTag()
{
    m_70 = "NameTag";
}

// @0x141a60c70
UINameTag::~UINameTag()
{
}

// @0x141a60cb0
CString UINameTag::GetTypeName()
{
    return CString("NameTag");
}

// @0x141a60d00
void UINameTag::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_141a60f70(m_68);
}

#ifndef MS2_HOOK_DLL
// @0x141a60d30
int FUN_141a60d30()
{
    return s_nNameTagMode;
}
#endif

void FUN_141a60d40(int nMode);
#ifndef MS2_HOOK_DLL
// @0x141a60d40
void FUN_141a60d40(int nMode)
{
    if (((struct Unk_NtCfg*)FUN_1401d3200())->m_8 != 0)
    {
        if (s_nNameTagMode != 2)
            FUN_141a60f40();
        s_nNameTagMode = 2;
    }
    else
    {
        if (s_nNameTagMode != nMode)
            FUN_141a60f40();
        s_nNameTagMode = nMode;
    }
}
#endif

// @0x141a62100
UINameTag* FUN_141a62100(int nUiId)
{
    if (reinterpret_cast<Unk_NtUIMgr*>(TSingleton<CUIService>::GetInstance()))
    {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (p.get())
            return dynamic_cast<UINameTag*>((UIObject*)p);
    }
    return 0;
}

// @0x141a60da0
MS2Ptr<UINameTag::Entity> FUN_141a60da0(int nActorId)
{
    UINameTag* pTag = FUN_141a62100(0x4e5a);
    if (pTag != 0)
    {
        MS2Ptr<UINameTag::Entity> pEntity(pTag->FUN_141a61150(nActorId));
        if (pEntity.IsNull())
            return MS2Ptr<UINameTag::Entity>(0);
        pEntity->vfunc_1();
        pEntity->FUN_140f48ce0(nActorId);
        return pEntity;
    }
    return MS2Ptr<UINameTag::Entity>(0);
}

// @0x141a60ec0
void FUN_141a60ec0(int nActorId)
{
    UINameTag* pTag = FUN_141a62100(0x4e5a);
    if (pTag)
        pTag->FUN_140f49c00(nActorId);
}

// @0x141a60f00
void FUN_141a60f00(int nActorId)
{
    UINameTag* pTag = FUN_141a62100(0x4e5a);
    if (pTag)
        pTag->FUN_140f49cb0(nActorId);
}

// @0x141a60f40
void FUN_141a60f40()
{
    UINameTag* pTag = FUN_141a62100(0x4e5a);
    if (pTag)
        pTag->FUN_140f49d20();
}

// @0x141a60f70
void UINameTag::FUN_141a60f70(unsigned int nCount)
{
    MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pClip.get())
    {
        for (unsigned int i = 0; i < nCount; i++)
        {
            Scaleform::GFx::Value v = pClip->Invoke("createCache", m_70);
            if (((Scaleform::GFx::Value*)(void*)(&v))->IsUndefined() == 0)
            {
                Entity* p = new Entity(m_28, v, 0);
                if (p)
                {
                    MS2Ptr<UIHudEntity::Entity> sp(p);
                    m_78.AddTail(sp);
                }
            }
        }
    }
}

// @0x141a61150
UINameTag::Entity* UINameTag::FUN_141a61150(int nActorId)
{
    if (FUN_140f49890(nActorId) != 0)
        return 0;
    {
    FUN_140f49c00(nActorId);
    MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pClip.get())
    {
        if (m_78.IsEmpty())
        {
            bool bFlag = FUN_140930110(nActorId);
            bFlag = false;
            Scaleform::GFx::Value v = ((Unk_BannerClip*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
            if (((Scaleform::GFx::Value*)(void*)(&v))->IsUndefined() == 0)
            {
                Entity* p = new Entity(m_28, v, nActorId);
                if (p)
                {
                    {
                        MS2Ptr<UIHudEntity::Entity> sp(p);
                        m_a8.SetAt(nActorId, sp);
                    }
                    return p;
                }
            }
        }
        else
        {
            MS2Ptr<UIHudEntity::Entity> pEntity = m_78.RemoveHead();
            if (pEntity.get())
            {
                int nOld = pEntity->FUN_140f48d20();
                if (nActorId != nOld)
                {
                    bool bNew = FUN_140930110(nActorId);
                    if (FUN_140930110(nOld) || bNew)
                    {
                        MS2Ptr<ASGameEntity> pOldClip = pEntity->FUN_140f48ed0();
                        if (pOldClip.get())
                            ((Unk_BannerClip*)pClip.operator->())->FUN_140ba9570("updateEntity", pOldClip->FUN_1422bb870(), bNew);
                    }
                }
                pEntity->FUN_140f48ce0(nActorId);
                m_a8.SetAt(nActorId, pEntity);
                return (Entity*)pEntity.get();
            }
        }
    }
    }
    return 0;
}

// @0x141a61590
const char* FUN_141a61590(int nState, const std::pair<const char*, Unk_RequireState>* pTable)
{
    for (int i = 0; i < 69u + 0 * sizeof(int*) ; i++)
    {
        if (nState == pTable[i].second)
            return pTable[i].first;
    }
    return 0;
}

MS2_REPLACE_METHOD(0x141A5E4C0, UINameTag::Entity, FUN_141a5e4c0, 57, 0xAFDEE4A2);
MS2_REPLACE_METHOD(0x141A5E500, UINameTag::Entity, FUN_141a5e500, 48, 0xD563652D);
MS2_REPLACE_METHOD(0x141A5E540, UINameTag::Entity, FUN_141a5e540, 129, 0x8640AC16);
MS2_REPLACE_METHOD(0x141A5E690, UINameTag::Entity, FUN_141a5e690, 68, 0xABE14A43);
MS2_REPLACE_METHOD(0x141A5E6E0, UINameTag::Entity, vfunc_1, 109, 0xC4D51A90);
MS2_REPLACE_METHOD(0x141A5E760, UINameTag::Entity, vfunc_2, 24, 0x321BB5DE);
MS2_REPLACE_METHOD(0x141A5E780, UINameTag::Entity, vfunc_3, 36, 0x43CEE922);
MS2_REPLACE_METHOD(0x141A5E7B0, UINameTag::Entity, vfunc_4, 85, 0x8182DC69);
MS2_REPLACE_METHOD(0x141A5EB80, UINameTag::Entity, vfunc_7, 76, 0x7661064C);
MS2_REPLACE_METHOD(0x141A5F040, UINameTag::Entity, FUN_141a5f040, 52, 0xDF9AEB02);
MS2_REPLACE_METHOD(0x141A60B90, UINameTag::Entity, FUN_141a60b90, 95, 0x9C373B15);

MS2_EMIT_CRT_MEMMOVE_S();
