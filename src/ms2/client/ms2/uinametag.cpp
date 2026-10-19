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
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The unit's statics: the name tag mode, then two copies of the shared header statics (the first one has the game
// object state name table between "stun" and the condition), then the key controller.
static int s_nNameTagMode;                                      // 0x143af45f0
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uinametag_gos.h"
#include "ms2/placeholder/header_statics_a.h"
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
double FUN_140f17ed0(const Scaleform::GFx::Value* pValue);                  // Value::GetNumber

// The client configuration row (FUN_1401d3200): +8 forces mode 2, +0x2c8 the default distance, +0x848 a seat offset.
struct Unk_NtCfgFloat { float FUN_1402bac70(); char m_pad[0x58]; };
struct Unk_NtCfg
{
    char m_pad_0000[8];
    unsigned char m_8;
    char m_pad_0009[0x2c8 - 9];
    Unk_NtCfgFloat m_2c8;
    char m_pad_0320[0x848 - 0x2c8 - sizeof(Unk_NtCfgFloat)];
    Unk_NtCfgFloat m_848;
};
Unk_NtCfg* FUN_1401d3200();
// The display flags (FUN_1409a8b10()->FUN_140b123b0()): which tags are shown for whom.
struct Unk_NtFlags { bool m_0; bool m_1; bool m_2; bool m_3; bool m_4; bool m_5; };
class Unk_NtFlagHolder { public: Unk_NtFlags* FUN_140b123b0(); };
Unk_NtFlagHolder* FUN_1409a8b10();

class Unk_NtUIScale;
Unk_NtUIScale* FUN_14025e7a0();                                             // ui scale service
float FUN_1422afec0(Unk_NtUIScale* pScale, int nLayer);                     // scale of a layer
NiPoint3* FUN_140ad0c10(NiPoint3* pt, float f);                             // efd::Point3::operator*=
float FUN_1412762d0(const NiPoint3& pt);
NiPoint3* FUN_14027dcf0(NiPoint3* pDst, const NiPoint3* pSrc);              // Point3::operator=
bool FUN_14028d470(float a, float b);                                       // a == b (within epsilon)
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned int nId);

// The camera option row held by the game context (+0x1e0: far fade enabled).
struct Unk_NtCamOption { char m_pad_000[0x1e0]; int m_1e0; };
class Unk_NtCamPtr
{
public:
    ~Unk_NtCamPtr() { FUN_140885ab0(); }                // 0x1408850f0 (another obj)
    Unk_NtCamOption* FUN_140885340() const;             // operator->
    void FUN_140885ab0();                               // release
    void* m_pad_00;
    Unk_NtCamOption* m_p;
};
struct Unk_NtSymbolRec { char m_pad_00[0x18]; CStringW m_18; CStringW m_20; };
class Unk_NtWorld
{
public:
    PCBase* FUN_141bd0cc0();                            // the local player
    Unk_NtCamPtr FUN_141bd30a0();
    Unk_NtSymbolRec* FUN_141bcab60(int n);
};
Unk_NtWorld* FUN_1403ed2d0();
class Unk_NtUIMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int); };
Unk_NtUIMgr* FUN_1403ed2b0();
bool FUN_140930110(int nActorId);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);

// Per-actor components (PCBase members outside the header) and the smart pointers they hand out.
struct Unk_NtNpcData
{
    char m_pad_00[0x7c];
    int m_7c;                                           // rank
    char m_pad_80[0xf8 - 0x80];
    __int64 m_f8;
    char m_pad_100[0x148 - 0x100];
    __int64 m_148; __int64 m_150; __int64 m_158;
    char m_pad_160[0x170 - 0x160];
    __int64 m_170; __int64 m_178; __int64 m_180;
    char m_pad_188[0x190 - 0x188];
    __int64 m_190; __int64 m_198; __int64 m_1a0; __int64 m_1a8;
    int FUN_1406cd0d0();
};
class Unk_NtNpcDataPtr
{
public:
    ~Unk_NtNpcDataPtr() { FUN_1406d5390(); }            // 0x1406d5390 (another obj)
    Unk_NtNpcData* FUN_140965990() const;               // operator->
    void FUN_1406d5390();                               // release
    void* m_pad_00;
    Unk_NtNpcData* m_p;
};
class Unk_NtNpc : public PCBase
{
public:
    Unk_NtNpcDataPtr FUN_141093270();
    CStringW FUN_141093980();                           // sub title
};
class Unk_NtPet
{
public:
    unsigned short FUN_140b10fe0();                     // taming level
    unsigned int FUN_140b109f0();                       // tamer oid
    __int64 FUN_140b10c00();                            // taming point
};
struct Unk_NtMountSeat { int FUN_140f48d40(); };
class Unk_NtMountSeatPtr
{
public:
    ~Unk_NtMountSeatPtr() { FUN_141666960(); }
    void* FUN_1416676b0() const;                        // get
    Unk_NtMountSeat* FUN_141667740() const;             // operator->
    void FUN_141666960();                               // release
    void* m_pad_00;
    Unk_NtMountSeat* m_p;
};
struct Unk_NtTeam { bool FUN_140743610(); int FUN_140743710(); };
class Unk_NtTeamPtr
{
public:
    ~Unk_NtTeamPtr() { FUN_140964aa0(); }
    void* FUN_140965810() const;                        // get
    Unk_NtTeam* FUN_140965970() const;                  // operator->
    void FUN_140964aa0();                               // release
    void* m_pad_00;
    Unk_NtTeam* m_p;
};
class Unk_NtSeatSub { public: NiPoint3* FUN_140adf8e0(void* pTmp24); };
// PC with its virtuals after slot 132 (PC itself declares 124..132).
class Unk_NtPC : public PC
{
public:
    // slots 133-146 are declared by PC (placeholder/fittingdollpc.h)
    Unk_NtMountSeatPtr FUN_141657730();
    Unk_NtTeamPtr FUN_140967420();
};
Unk_NtPC* FUN_140974230(PCBase* pActor);                // the actor as a player
Unk_NtNpc* FUN_14096e110(PCBase* pActor);               // the actor as an npc
Unk_NtPet* FUN_1409ffc60(PCBase* pActor);               // the actor as a pet
Unk_NtSeatSub* FUN_14165ca20(PC* pPc);
int FUN_14166c930(PCBase* pActor);                      // game object state
int FUN_14166ce30(PCBase* pActor);                      // dead
__int64 FUN_141670a00(PCBase* pActor, int nStat);
__int64 FUN_141670a30(PCBase* pActor, int nStat);
NiAVObject* FUN_141675150(PCBase* pActor, const CString& strNode);
class Unk_NtSub { public: float FUN_140970720(); };
Unk_NtSub* FUN_1416749a0(PCBase* pActor);
int FUN_141661c50(PC* pPc);                             // title id
CStringW* FUN_141656be0(PC* pPc);                       // guild name
__int64 FUN_141661e00(PC* pPc);
int FUN_141661e20(PC* pPc);
int FUN_141661e40(PC* pPc, int* pnGrade, int* pnRank);
int FUN_141678320(PC* pPc);
CStringW FUN_141b720b0(int nTitle, PC* pPc);
struct Unk_NtMountInfo3 { char m_pad[0x68]; int m_68; };
class Unk_NtMountInfoPtr
{
public:
    ~Unk_NtMountInfoPtr() { FUN_140788ea0(); }
    Unk_NtMountInfo3* FUN_1407895c0() const;            // operator->
    void FUN_140788ea0();                               // release
    void* m_pad_00;
    Unk_NtMountInfo3* m_p;
};
struct Unk_NtMountInfo { Unk_NtMountInfoPtr FUN_140784970(); };
class Unk_NtMountPtr
{
public:
    ~Unk_NtMountPtr() { FUN_140788ed0(); }
    void* FUN_1409f78a0() const;                        // get
    Unk_NtMountInfo* FUN_1407895d0() const;             // operator->
    void FUN_140788ed0();                               // release
    void* m_pad_00;
    Unk_NtMountInfo* m_p;
};
class Unk_NtMountHolder { public: Unk_NtMountPtr FUN_141707750(); };
Unk_NtMountHolder* FUN_1416764a0(PCBase* pActor);
class Unk_NtItemMgr
{
public:
    int FUN_1406c5b00(__int64 nId, int nKind);
    CStringW FUN_1406c6360(__int64 nId, PC* pPc, int n);
};
Unk_NtItemMgr* FUN_14131e120();
CStringW FUN_140b8f730(const NiPoint3& pt);
CStringW FUN_14016a730(const char* sz, int n);
CStringW FUN_14028de60(int nStringId);

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
    m_20 = FUN_141675150(pActor, m_28);
}

// MS2-FUNCTIONAL: this/arg evaluation order (arg temps) differs
// @0x141a5e5d0
int UINameTag::Entity::FUN_141a5e5d0(float* pPos)
{
    if (m_38.get() != 0 && FUN_140f48d40() != 0)
    {
        m_38->FUN_1422c0f60(pPos + 0, pPos + 1);
        *pPos = (float)((double)*pPos - (double)m_68 * 0.5);
        return 1;
    }
    return 0;
}

// @0x141a5e690
int UINameTag::Entity::FUN_141a5e690()
{
    if (m_38.get())
        return m_38->FUN_1422bfca0();
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

// MS2-FUNCTIONAL: ceil is the CRT import call in the exe, an intrinsic here
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
        m_68 = (unsigned int)ceil(FUN_140f17ed0(&width));
    }
}

// MS2-FUNCTIONAL: same ceil/double temp codegen differences as vfunc_5
// @0x141a5e8d0
void UINameTag::Entity::vfunc_6(NiPoint3* pPos)
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return;
    if (m_38.get() == 0)
        return;
    if (FUN_141a60d30() == 2)
        FUN_141a5f080();
    FUN_140ad0c10(pPos, FUN_1422afec0(FUN_14025e7a0(), m_18));
    pPos->y = pPos->y + vfunc_9();
    float fDist = FUN_140f48e20();
    bool bNear = !(700.0f < fDist) || FUN_1403ed2d0()->FUN_141bd30a0().FUN_140885340()->m_1e0 != 0;
    if (bNear)
        m_38->FUN_1422bfe00(100.0f);
    else
        m_38->FUN_1422bfe00((float)((m_54 - fDist) * 0.05 + 40.0));
    if (FUN_14028d470(FUN_1416749a0(pActor)->FUN_140970720(), 0.0f))
        m_38->FUN_1422bfe00(0.0f);
    float fY = pPos->y;
    float fSeat = FUN_1412762d0(vfunc_10());
    m_38->FUN_1422c00f0(pPos->x, fY + fSeat);
}

// @0x141a5eb80
void UINameTag::Entity::vfunc_7()
{
    if (m_38.get() != 0)
        m_38->vfunc_3(0);
}

// MS2-FUNCTIONAL: smart-pointer temp layout differs from the exe
// @0x141a5ebe0
int UINameTag::Entity::vfunc_8(int n)
{
    if (FUN_141a60d30() == 0)
        return 1;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 1;
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return 1;
    if (FUN_14166c930(pActor) == 0x3f)
        return 1;
    if (FUN_141a60920() == 0)
        return 1;
    Unk_NtMountHolder* pHolder = FUN_1416764a0(pActor);
    if (pHolder != 0)
    {
        Unk_NtMountPtr spMount = pHolder->FUN_141707750();
        if (spMount.FUN_1409f78a0() != 0 && spMount.FUN_1407895d0()->FUN_140784970().FUN_1407895c0()->m_68 != 0)
            return 1;
    }
    return UIHudEntity::Entity::vfunc_8(FUN_14166ce30(pActor));
}

// MS2-FUNCTIONAL: NiPoint3 return/GS cookie frame layout differs
// @0x141a5edb0
NiPoint3 UINameTag::Entity::vfunc_10()
{
    PC* pPc = dynamic_cast<PC*>(FUN_140f49330());
    Unk_NtSeatSub* pSeat = 0;
    if (pPc == 0 || (pSeat = FUN_14165ca20(pPc)) == 0)
        return UIHudEntity::Entity::vfunc_10();
    NiPoint3 base = UIHudEntity::Entity::vfunc_10();
    char tmp[24];
    NiPoint3 pos;
    FUN_14027dcf0(&pos, pSeat->FUN_140adf8e0(tmp));
    pos.z = base.z;
    return pos;
}

// MS2-FUNCTIONAL: smart-pointer temp slots and state map differ
// @0x141a5eea0
float UINameTag::Entity::vfunc_9()
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return 0.0f;
    Unk_NtPC* pPc = FUN_140974230(pActor);
    if (pPc != 0)
    {
        if (FUN_14166ce30(pPc) != 0 && pPc->FUN_141657730().FUN_1416676b0() != 0
            && pPc->FUN_141657730().FUN_141667740()->FUN_140f48d40() != 0)
            return FUN_1401d3200()->m_848.FUN_1402bac70();
    }
    if (pActor == 0)
        return 0.0f;
    return pActor->vfunc_89();
}

// @0x141a5f040
void UINameTag::Entity::FUN_141a5f040(const CString& strSkin)
{
    m_70 = strSkin;
    FUN_140f48d80();
}

// MS2-FUNCTIONAL: big format/AS-object function; local and temporary layout differs from the exe
#ifndef MS2_HOOK_DLL
// @0x141a5f080
void UINameTag::Entity::FUN_141a5f080()
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0 || m_38.get() == 0)
        return;
    m_38->FUN_1422bfe00(100.0f);
    ASObj obj(m_18);
    CStringW strInfo;
    CStringW strStats;
    Unk_NtPC* pPc = FUN_140974230(pActor);
    if (pPc == 0)
    {
        Unk_NtNpc* pNpc = FUN_14096e110(pActor);
        if (pNpc != 0)
        {
            __int64 nHp, nMaxHp, nPap, nMap, nNdd, nPar, nMar, nAtp, nEvp, nAbp, nMsp, nCar;
            nHp = FUN_141670a00(pNpc, 4);
            nPap = pNpc->FUN_141093270().FUN_140965990()->m_190;
            nMap = pNpc->FUN_141093270().FUN_140965990()->m_198;
            nNdd = pNpc->FUN_141093270().FUN_140965990()->m_178;
            nPar = pNpc->FUN_141093270().FUN_140965990()->m_1a0;
            nMar = pNpc->FUN_141093270().FUN_140965990()->m_1a8;
            nAtp = pNpc->FUN_141093270().FUN_140965990()->m_150;
            nEvp = pNpc->FUN_141093270().FUN_140965990()->m_158;
            nAbp = pNpc->FUN_141093270().FUN_140965990()->m_180;
            nMsp = pNpc->FUN_141093270().FUN_140965990()->m_148;
            nCar = pNpc->FUN_141093270().FUN_140965990()->m_170;
            nMaxHp = pNpc->FUN_141093270().FUN_140965990()->m_f8;
            strStats = StringFormat(L"hp:{0}/{1} pap:{2} map:{3} ndd:{4} par:{5} mar:{6} atp:{7} evp:{8}, abp:{9}, msp:{10}, car:{11}",
                                    nHp, nMaxHp, nPap, nMap, nNdd, nPar, nMar, nAtp, nEvp, nAbp, nMsp, nCar);
            int aRankStr[9] = {0x573, 0xaf, 0xb0, 0xb1, 0xb3, 0xb5, 0xb4, 0xb2};
            unsigned short nLevel = (unsigned short)pNpc->vfunc_78();
            int nRank = pNpc->FUN_141093270().FUN_140965990()->m_7c;
            strInfo.Format(L"name:[%s] state:[%s] lv:%d rank:[%s]",
                           (LPCWSTR)pNpc->vfunc_77(),
                           (LPCWSTR)FUN_14016a730(FUN_141a61590(FUN_14166c930(pNpc), s_gosNames), 0),
                           (unsigned int)nLevel,
                           (LPCWSTR)FUN_14028de60(aRankStr[nRank]));
            bool bShop = pNpc->FUN_141093270().FUN_140965990()->FUN_1406cd0d0() != 0;
            if (bShop)
            {
                unsigned int nShop = pNpc->FUN_141093270().FUN_140965990()->FUN_1406cd0d0();
                strInfo.AppendFormat(L" shopID:[%d]", nShop);
            }
            Unk_NtPet* pPet = FUN_1409ffc60(pActor);
            if (pPet != 0)
                strInfo.AppendFormat(L" tamingLevel:[%d], tamerOID:[%d], tamingPoint:[%d]",
                                     pPet->FUN_140b10fe0(), pPet->FUN_140b109f0(), pPet->FUN_140b10c00());
        }
    }
    else
    {
        __int64 nHp, nMaxHp, nStr, nInt, nDex, nLuk, nPen, nPap, nMap;
        nHp = FUN_141670a00(pPc, 4);
        nMaxHp = FUN_141670a30(pPc, 4);
        nPap = FUN_141670a00(pPc, 0x17);
        nMap = FUN_141670a00(pPc, 0x18);
        nStr = FUN_141670a00(pPc, 0);
        nDex = FUN_141670a00(pPc, 1);
        nLuk = FUN_141670a00(pPc, 3);
        nPen = FUN_141670a00(pPc, 0x1f);
        nInt = FUN_141670a00(pPc, 2);
        strStats = StringFormat(L"hp:{0}/{1} str:{2} int:{3} dex:{4} luk:{5} pen:{6} pap:{7} map:{8}",
                                nHp, nMaxHp, nStr, nInt, nDex, nLuk, nPen, nPap, nMap);
        strInfo = StringFormat(L"{0} state:[{1}] pos:[{2}] rot:[{3}] {4}",
                               pPc->vfunc_77(),
                               FUN_14016a730(FUN_141a61590(FUN_14166c930(pPc), s_gosNames), 0),
                               FUN_140b8f730(pPc->vfunc_18()),
                               FUN_140b8f730(pPc->vfunc_20()),
                               pPc->vfunc_134());
    }
    obj.FUN_1407cb9c0("visibleSymbol", m_7c);
    obj.FUN_1407cb9c0("visibleName", m_78);
    obj.FUN_1407cbb20("name", strInfo);
    obj.FUN_1407cbb20("guild", strStats);
    obj.FUN_1409c0d20("fontSize", m_60);
    obj.FUN_1409c0d20("fontColor", m_64);
    m_38->Invoke("setData", obj);
}
#endif

// MS2-FUNCTIONAL: big format/AS-object function; local and temporary layout differs from the exe
// @0x141a5ff60
void UINameTag::Entity::FUN_141a5ff60()
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return;
    if (m_38.get() == 0)
        return;
    m_38->FUN_1422bfe00(100.0f);
    ASObj obj(m_18);
    CStringW strName;
    CStringW strGuild;
    strName = pActor->vfunc_77();
    Unk_NtPC* pPc = FUN_140974230(pActor);
    if (pPc == 0)
    {
        Unk_NtNpc* pNpc = FUN_14096e110(pActor);
        if (pNpc != 0)
            strGuild = pNpc->FUN_141093980();
    }
    else
    {
        strGuild = L"";
        if (FUN_141656be0(pPc)->GetLength() > 0)
            strGuild = StringFormat(L"<{0}>", *FUN_141656be0(pPc));
        if (FUN_141661c50(pPc) != 0)
            strName = StringFormat(L"{0} {1}", FUN_141b720b0(FUN_141661c50(pPc), pPc), strName);
        bool bSymbol = false;
        Unk_NtSymbolRec* pRec = FUN_1403ed2d0()->FUN_141bcab60(5);
        if (pRec != 0)
        {
            if (FUN_141678320(pPc) == 1)
            {
                obj.FUN_1407cbb20("symbol", pRec->m_18);
                bSymbol = true;
            }
            else if (FUN_141678320(pPc) == 2)
            {
                obj.FUN_1407cbb20("symbol", pRec->m_20);
                bSymbol = true;
            }
        }
        bool bTeam = !bSymbol && pPc->FUN_140967420().FUN_140965810() != 0
                     && pPc->FUN_140967420().FUN_140965970()->FUN_140743610();
        if (bTeam)
        {
            int nTeam = pPc->FUN_140967420().FUN_140965970()->FUN_140743710();
            if (nTeam == 0xc9)
            {
                obj.FUN_1409c0dc0("symbol", "red_team");
                bSymbol = true;
            }
            else
            {
                nTeam = pPc->FUN_140967420().FUN_140965970()->FUN_140743710();
                if (nTeam == 0xca)
                {
                    obj.FUN_1409c0dc0("symbol", "blue_team");
                    bSymbol = true;
                }
            }
        }
        if (!bSymbol)
        {
            __int64 nId = FUN_141661e00(pPc);
            if (FUN_14131e120()->FUN_1406c5b00(nId, 2) == 0)
            {
                if (FUN_141661e20(pPc) != 0)
                {
                    CStringW strIcon = FUN_14131e120()->FUN_1406c6360(nId, pPc, 0);
                    obj.FUN_1407cbb20("symbol", strIcon);
                    if (FUN_14131e120()->FUN_1406c5b00(nId, 1) == 0)
                    {
                        if (FUN_14131e120()->FUN_1406c5b00(nId, 0xb) != 0)
                            obj.FUN_1409c0d20("level", pPc->vfunc_141());
                    }
                    else
                        obj.FUN_1409c48f0("level", (short)pPc->vfunc_78());
                }
            }
            else
            {
                int nGrade, nRank;
                if (FUN_141661e40(pPc, &nGrade, &nRank) != 0)
                {
                    obj.FUN_1409c0dc0("symbol", "enchant");
                    obj.FUN_1407cb9c0("grade", nGrade);
                    obj.FUN_1409adc90("rank", nRank);
                }
            }
        }
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

// MS2-FUNCTIONAL: config flag chain temp layout differs
// @0x141a60920
bool UINameTag::Entity::FUN_141a60920()
{
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return false;
    if (FUN_14087ddc0(pActor ? pActor->GetClassDesc() : 0, 0x6200004))
    {
        bool bName = FUN_1409a8b10()->FUN_140b123b0()->m_0;
        FUN_141a60b90(FUN_1409a8b10()->FUN_140b123b0()->m_1, bName);
        return !(m_78 == 0 && m_7c == 0);
    }
    Unk_NtPC* pPc = FUN_140974230(pActor);
    if (pPc != 0)
    {
        bool bName;
        if (pPlayer->vfunc_122(pPc) == 0)
        {
            bName = FUN_1409a8b10()->FUN_140b123b0()->m_2;
            FUN_141a60b90(FUN_1409a8b10()->FUN_140b123b0()->m_1, bName);
        }
        else
        {
            bName = FUN_1409a8b10()->FUN_140b123b0()->m_3;
            FUN_141a60b90(FUN_1409a8b10()->FUN_140b123b0()->m_1, bName);
        }
        return !(m_78 == 0 && m_7c == 0);
    }
    if (FUN_1409ffc60(pActor) != 0)
        return true;
    Unk_NtNpc* pNpc = FUN_14096e110(pActor);
    if (pNpc == 0)
        return false;
    if (pNpc->vfunc_116() == 0)
        return FUN_1409a8b10()->FUN_140b123b0()->m_5;
    return FUN_1409a8b10()->FUN_140b123b0()->m_4;
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
CString UINameTag::vfunc_1()
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
    if (FUN_1401d3200()->m_8 != 0)
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
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
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
            if (FUN_1409b0390(&v) == 0)
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

// MS2-FUNCTIONAL: local/EH-state layout differs (as in UIShieldBar::FUN_140e86610)
// @0x141a61150
UINameTag::Entity* UINameTag::FUN_141a61150(int nActorId)
{
    if (FUN_140f49890(nActorId) != 0)
        return 0;
    FUN_140f49c00(nActorId);
    MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pClip.get())
    {
        if (m_78.IsEmpty())
        {
            FUN_140930110(nActorId);
            Scaleform::GFx::Value v = pClip->FUN_140ba9470("createEntity", nActorId, m_70, 0);
            if (FUN_1409b0390(&v) == 0)
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
                    bool bOld = FUN_140930110(nOld);
                    if (bOld || bNew)
                    {
                        MS2Ptr<ASGameEntity> pOldClip = pEntity->FUN_140f48ed0();
                        if (pOldClip.get())
                            pClip->FUN_140ba9570("updateEntity", pOldClip->FUN_1422bb870(), bNew);
                    }
                }
                pEntity->FUN_140f48ce0(nActorId);
                m_a8.SetAt(nActorId, pEntity);
                return (Entity*)pEntity.get();
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
