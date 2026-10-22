// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPet (RTTI "CPet", class id 0x06200074; derives CNpc): the
// summoned / tamed pet actor. Its constructor registers the pet states, the per-frame update keeps the taming auras,
// the owner's drop pick-up skill (pet skills picked by hp percentage) and the idle animation going; the taming bar
// (UITamingBar::Entity) hangs off +0x1090. The dynamic initializers are the header statics of the market / condition
// tables (sort names, "skill", "stun", condition object) and the CPet::ms_ClassInfo registration. See placeholder/cpet.h.
// MS2-UNIT: unit_140b0f4c0
// MS2-RANGE: 0x1400c73d0-0x1400c7620 .text$di
// MS2-RANGE: 0x140b0f4c0-0x140b12780 .text$mn
// MS2-RANGE: 0x142ca08a0-0x142ca0960 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??8?$MS2Ptr@VEntity@UITamingBar@@@@QEBA_NPEAVEntity@UITamingBar@@@Z 0x140b12270 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetClassDesc@CPet@@UEBAPEBVClassInfo@efd@@XZ 0x140b12370
// MS2-PIN: ?TypeCast@CPet@@UEBA_NIPEAPEAX@Z 0x140b124b0
// MS2-PIN: ?TypeCast@CPet@@UEBA_NIPEAPEBX@Z 0x140b12500
// MS2-PIN: ??_7CPet@@6BIBase@efd@@@ 0x142dd98e0
// MS2-PIN: ??_7CPet@@6BCallbackObject@NiActorManager@@@ 0x142dd9cf8
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <ctype.h>
#include <egf/Entity.h>
#include <NiActorManager.h>

#include "ms2/placeholder/cpet.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/client/ms2/stateidle.h"
#include "ms2/client/ms2/statesummon.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/uichatballoon.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The world objects the owner / local player lookups hand out (worldservice.h only forward-declares the type).
class Unk_WsC_GameObj : public GameObject { };

// The pet table (item.cpp owns the real instance).
class Unk_PetRowTable : public CPtred { public: MS2Ptr<Unk_PetRow> FUN_1407290f0(int nPetId); };
Unk_PetRowTable* FUN_14052d210();                                           // the pet-data table

// The singletons.
WorldService* FUN_1403ed2d0();                                              // the world
CEffectService* FUN_1403ed280();                                            // the effect service

// The client settings: the pet option flags at +0x34 (+0x12 other users' pets, +0x13 the own pet).
struct Unk_PetOptFlags { char m_pad_00[0x12]; unsigned char m_bOther; unsigned char m_bOwn; };
struct Unk_PetClientSettings
{
    char m_pad_00[0x34];
    Unk_PetOptFlags m_flags;                                                // +0x34
    Unk_PetOptFlags* FUN_140b123b0() { return &m_flags; }                   // @0x140b123b0
};
Unk_PetClientSettings* FUN_1409a8b10();

// The game-mode flags of the client config (a blocked-action set at +8).
struct Unk_PetBanFlags { int FUN_1402c4c90(int nFlag); };
struct Unk_PetConfig { char m_pad_00[8]; Unk_PetBanFlags m_8; };
Unk_PetConfig* FUN_14025e7b0();

// The buffs of an actor.
class Unk_PCBaseBuffs { public: int FUN_140970020(int nBuffId, unsigned short nLevel, int a, int b); };

// The pet owner as a player: the equipped pet skin gem.
class Unk_OwnerPC : public PCBase { public: MS2Ptr<CGemPetSkin> FUN_14165df00(); };

// The pet-skill service (skill table, skill service, pet food table).
class Unk_SkillObj : public CPtred { public: bool FUN_140804450(); };
class Unk_PetSkillElem : public CPtred { public: int m_nSkillId; unsigned short m_nLevel; };
class Unk_PetSkillLevel : public CPtred { public: char m_pad_18[0x98 - sizeof(CPtred)]; std::vector<MS2Ptr<Unk_PetSkillElem> > m_vElems; };
class Unk_PetSkillTable { public: MS2Ptr<Unk_PetSkillLevel> FUN_1407ee2f0(int nSkillId, unsigned short nLevel); };
Unk_PetSkillTable* FUN_1401958b0();
class Unk_ItemEquipData : public CItemData { public: int FUN_140526810(unsigned short nLevel); };
struct Unk_PetFoodRule { int m_nKey; float m_fRate; int m_nItemId; };       // key +0, rate +4, item +8
class Unk_PetSkillSvcInner { public: char m_pad_00[0x68]; CAtlMap<int, Unk_PetFoodRule> m_map; MS2Ptr<Unk_ItemEquipData> FUN_140c892c0(int nItemId); int FUN_140c89220(int nItemId); };
class Unk_PetSkillSvc { };
Unk_PetSkillSvc* FUN_140535320();
Unk_PetSkillSvcInner* FUN_140c8b450(Unk_PetSkillSvc* p);
Unk_PetSkillSvcInner* FUN_140c8b430(Unk_PetSkillSvc* p);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// The pet animation table.
class Unk_PetAnimLine : public CPtred { public: CStringW m_strText; CString m_strEffect; };
struct Unk_PetAnimLines
{
    void* m_p00;
    MS2Ptr<Unk_PetAnimLine>* m_pData;                                       // +8
    bool FUN_140b123c0() const { return m_pData == 0; }                     // @0x140b123c0
    const MS2Ptr<Unk_PetAnimLine>& FUN_140a4ffc0(unsigned __int64 nIdx) const;
};
class Unk_PetAnimRow : public CPtred { public: char m_pad_18[0x68 - sizeof(CPtred)]; Unk_PetAnimLines m_lines; };
MS2Ptr<Unk_PetAnimRow> FUN_140856fa0(int nNpcId, int nAnimId);

// The lua state / grade tables, the string table, the notices.
class Unk_LuaState;
Unk_LuaState* FUN_1401c0db0();
int FUN_140678b50(Unk_LuaState* pLua, unsigned short nGrade);               // grade -> effect id
void FUN_140291d10(int nFxId);
CString FUN_140291c10(int nFxId);
int FUN_14028d260(float fTime);
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& arg0, const CStringW& arg1);
struct Unk_PetStrings { CStringW FUN_141811980(int nTable, int nId); };
Unk_PetStrings* FUN_1401a9d70();
void FUN_1412751f0(const CStringW& str, int a, int b);
bool FUN_14028d470(float a, float b);

// Pet-related helpers of other units.
COptimizer* FUN_1409f7c90();                                                // the optimizer
int FUN_140b11c20(CAtlMap<int, Unk_PetFoodRule>* pMap, PCBase* pPC);
int FUN_140b118f0(int nItemId, PCBase* pPC);
unsigned FUN_140b119c0(int nItemId, PCBase* pPC);

bool FUN_140a7c8d0(CNpcData* pData);                                        // the npc shows its name
void* FUN_140a58500(Unk_PetClientSettings* p);
void* FUN_1408e57f0();
int FUN_1422b9ea0(void* p);
unsigned FUN_140a35ca0(MS2Tick* p);
MS2Tick* FUN_140a36020(const void* pValue);                                 // Value<MS2Tick>::Get
CString* FUN_140298f80(const void* pValue);                                 // Value<CString>::Get
void FUN_14123fbf0(Unk_PCBaseBody* pBody, unsigned short nGroup);  // collision group
void FUN_141191330(Unk_WsC_GameObj* pField, int nId);
void FUN_141190900(Unk_WsC_GameObj* pField, int nId);
PCBase* FUN_1409613d0(GameObject* p);

// The field object of an actor keeps an item pointer at +0x1a0.
struct Unk_PetFieldObj { char m_pad_00[0x1a0]; MS2Ptr<CItem> m_spItem; };
// @0x140b12380
inline void* FUN_140b12380(Unk_WsC_GameObj* pField) { return reinterpret_cast<Unk_PetFieldObj*>(pField)->m_spItem.get(); }

// @0x140b120b0 the efd cast of a world object to a player
inline PCBase* FUN_140b120b0(GameObject* p)
{
    PCBase* pResult = 0;
    if (p != 0 && p->TypeCast(0x6200003, (void**)&pResult))
        return pResult;
    else
        return 0;
}
MS2Ptr<UITamingBar::Entity> FUN_140e97f80(int nActorId);
void FUN_140e98000(int nActorId);
void FUN_140939a10();
bool FUN_140da4fe0(void* a, void* b);

// The chat balloon component the actor owns (+0xaa8 of PCBase).
class Unk_PCBaseComp_aa8 : public UIChatBalloon::Entity { };

// ---- header statics ------------------------------------------------------------------------------------------------

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CPet);

static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- the actor ----------------------------------------------------------------------------------------------------------

// @0x140b0f4c0
// MS2-FUNCTIONAL: the new[] of the states and the member initialisation order are source-level guesses
CPet::CPet()
    : CNpc()
    , m_nPetId(0)
    , m_nF44(1)
    , m_spRow(0)
    , m_info()
    , m_timer1030()
    , m_tm1068()
    , m_nKind(0)
    , m_nTamingPoint(0)
    , m_nGrade(0)
    , m_nGradeFx(1)
    , m_nFxOther(0)
    , m_nFxMax(0)
    , m_spBar(0)
{
    m_nTargetId = 0;
    if (m_spStateMgr.get() != 0)
    {
        m_spStateMgr->FUN_1417daeb0(1, new StateIdlePet(this));
        m_spStateMgr->FUN_1417daeb0(0x30, new StateSummonRevive(this));
        m_spStateMgr->FUN_1417daeb0(0x31, new StateSummonExpire(this));
        m_spStateMgr->FUN_1417daeb0(0x32, new StateSummonItemPick(this));
    }
    m_timer1030.FUN_140868750(1000);
}

// @0x140b0f840
CPet::~CPet()
{
    if (m_nFxOther != 0)
        FUN_1403ed280()->FUN_1411a6060(m_nFxOther);
    if (m_nFxMax != 0)
        FUN_1403ed280()->FUN_1411a6060(m_nFxMax);
}

// @0x140b0f930
int CPet::vfunc_124(int nNpcId)
{
    if (CNpc::vfunc_124(nNpcId) == 0)
        return 0;
    return 1;
}

// @0x140b0f970
void CPet::vfunc_126(int a, int b)
{
    FUN_14123fbf0(m_unk_150, 5);
}

// @0x140b0f9b0
int CPet::vfunc_116()
{
    return 1;
}

// The size ratio of the pet to its npc row decides the animation speed scale.
// @0x140b0f9d0
float CPet::vfunc_97()
{
    float fResult = 1.0f;
    float fBase = 1.0f;
    if (m_spNpcData.get() != 0)
        fBase = m_spNpcData->m_model.m_fScale;
    float fCur = m_fScaleAC;
    if (!FUN_14028d470(m_fScaleA8, 1.0f))
        fCur = m_fScaleA8;
    if (fCur != fBase)
    {
        if (fCur < fBase / 2.0f)
            fResult = 1.5f;
        else if (fCur >= fBase / 2.0f && fCur < fBase)
            fResult = 2.0f - fCur / fBase;
        else if (fCur > fBase && fCur <= fBase * 2.0f)
            fResult = 1.0f - (fCur - fBase) / (fBase * 2.0f);
        else if (fCur > fBase * 2.0f)
            fResult = 0.5f;
    }
    return fResult;
}

// @0x140b0fb90
void CPet::vfunc_53(float f)
{
    CNpc::vfunc_53(f);
    if (m_timer1030.FUN_140868c00() != 0)
    {
        m_timer1030.FUN_140868750(1000);
        if (FUN_14123c660() != FUN_140b10150())
        {
            vfunc_23(FUN_140b10150());
            bool bShow = FUN_140b10150() == 0;
            FUN_14123cb20(bShow);
        }
    }
    FUN_140b11180();
    FUN_140b11320(f);
    FUN_140b10400();
    FUN_140b10510();
}

// @0x140b0fca0
float CPet::vfunc_89()
{
    float fRow = 0.0f;
    if (m_spRow.get() != 0)
        fRow = m_spRow->m_fScaleBonus;
    do
    {
        Unk_OwnerPC* pOwner = static_cast<Unk_OwnerPC*>(FUN_141094f60());
        if (pOwner == 0)
            break;
        CGemPetSkin* pGem = pOwner->FUN_14165df00().get();
        if (pGem == 0)
            break;
        MS2Ptr<Unk_PetRow> spRow = FUN_14052d210()->FUN_1407290f0(pGem->m_nPetId);
        if (spRow.IsNull())
            break;
        fRow = spRow->m_fScaleBonus;
    } while (0);
    return m_f16c + m_f170 + fRow;
}

// @0x140b0fdf0
void CPet::vfunc_16()
{
    PCBase::vfunc_16();
    m_spBar = 0;
    FUN_140e98000(m_unk_70);
}

// @0x140b0fe30
// MS2-FUNCTIONAL: the deferred world callback wrapper (CDllIsolationWrapperBase) is not recovered
void CPet::vfunc_125(int n)
{
    m_unk_15c = 1;
    FUN_1410932c0(0);
    FUN_1403ed2d0()->FUN_141bbbcf0(FUN_14123c580(), 1);
}

// @0x140b0ff40
void CPet::vfunc_52(double fTime)
{
    float fScale = m_unk_748.FUN_1409705d0();
    if (GetKind() != 0)
        fScale = fScale * 2.0f;
    FUN_14123c330(fScale);
    float fRatio = FUN_14123c260() / GetScaleAC();
    if (fRatio != m_fScaleA8)
    {
        int bDown = m_fScaleA8 - fRatio > 0.0f ? 0 : 1;
        float fStep = 3.0f * (float)fTime;
        if (bDown)
            fStep = -fStep;
        fRatio = fRatio + fStep;
        if (bDown)
        {
            if (fRatio < m_fScaleA8)
                fRatio = m_fScaleA8;
        }
        else
        {
            if (fRatio > m_fScaleA8)
                fRatio = m_fScaleA8;
        }
        FUN_14123c280(fRatio * GetScaleAC());
    }
}

// @0x140b100f0
int CPet::vfunc_58()
{
    PCBase* pOwner = FUN_141094f60();
    if (pOwner != 0 && pOwner->GetClassID() == 0x6200004)
        return 2;
    return 4;
}

// @0x140b10140
int CPet::vfunc_128()
{
    return 0;
}

// @0x140b10150
int CPet::FUN_140b10150()
{
    PCBase* pOwner = FUN_141094f60();
    if (pOwner == 0)
        return 0;
    if (FUN_1409a8b10()->FUN_140b123b0()->m_bOwn != 0 && pOwner->GetClassID() == 0x6200004)
        return 1;
    else if (FUN_1409a8b10()->FUN_140b123b0()->m_bOther != 0 && pOwner->GetClassID() != 0x6200004)
        return 1;
    if (FUN_14166cad0())
        return 1;
    return 0;
}

// @0x140b10210
void CPet::FUN_140b10210(int nPetId)
{
    m_nPetId = nPetId;
    m_spRow = FUN_14052d210()->FUN_1407290f0(nPetId);
}

// @0x140b10290
int CPet::GetPetId()
{
    return m_nPetId;
}

// @0x140b102b0
MS2Ptr<Unk_PetRow> CPet::GetRow()
{
    return m_spRow;
}

// @0x140b10300
int CPet::FUN_140b10300()
{
    return m_nF44;
}

// @0x140b10320
PCBase* CPet::FUN_140b10320()
{
    return FUN_140b120b0(FUN_1403ed2d0()->FUN_141bd1290(m_nOwnerId));
}

// @0x140b10360
PCBase* CPet::FUN_140b10360()
{
    return FUN_1409613d0(FUN_1403ed2d0()->FUN_141bd1290(m_nOwnerId));
}

// @0x140b103a0
CCPetInfoPacket::Info* CPet::FUN_140b103a0()
{
    return &m_info;
}

// @0x140b103c0
void CPet::FUN_140b103c0(void* p)
{
    m_info.FUN_1401ffd00(p);
}

// @0x140b10400
void CPet::FUN_140b10400()
{
    PCBase* pOwner = FUN_141094f60();
    if (pOwner == 0)
        return;
    if (pOwner->GetClassID() != 0x6200004)
        return;
    if (m_spRow == 0)
        return;
    if (m_tm1068.FUN_140268870(100) == 0)
        return;
    if (vfunc_65() == 0)
        return;
    Unk_WsC_GameObj* pField = FUN_1403ed2d0()->FUN_141bd1a50(static_cast<Unk_WsC_GameObj*>(static_cast<GameObject*>(this)));
    if (pField == 0)
        return;
    void* pItem = FUN_140b12380(pField);
    if (pItem == 0)
        return;
    FUN_141191330(pField, FUN_14123c580());
    FUN_141190900(pField, FUN_14123c580());
}

// @0x140b10510
// MS2-FUNCTIONAL: the Unk_EffectTarget locals are destroyed through the shared COMDAT 0x1405a89e0
void CPet::FUN_140b10510()
{
    if (FUN_140b10c20() == 0)
    {
        if (m_nFxMax != 0)
        {
            FUN_1403ed280()->FUN_1411a6060(m_nFxMax);
            m_nFxMax = 0;
        }
    }
    else if (m_nFxMax == 0)
    {
        void* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pLocal != 0)
        {
            if (static_cast<PCBase*>(pLocal)->FUN_14123c580() == GetKind())
            {
                Unk_EffectTarget kTarget;
                kTarget.m_strName = *FUN_140298f80(&Client::Constants::GetInstance()->PetTamingMaxPointEffect);
                kTarget.m_nKind = 0;
                kTarget.FUN_140a53190(FUN_14123c580());
                m_nFxMax = FUN_1403ed280()->FUN_1411a49c0(kTarget);
            }
        }
    }
    if (GetOwnerId() == 0 && GetKind() != 0)
    {
        if (m_nFxOther == 0)
        {
            void* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pLocal != 0)
            {
                Unk_EffectTarget kTarget;
                if (GetKind() == static_cast<PCBase*>(pLocal)->FUN_14123c580())
                    kTarget.m_strName = FUN_140291c10(m_nGradeFx);
                else
                    kTarget.m_strName = *FUN_140298f80(&Client::Constants::GetInstance()->PetTrapAreaEffectOtherUser);
                kTarget.m_nKind = 0;
                kTarget.FUN_140a53190(FUN_14123c580());
                m_nFxOther = FUN_1403ed280()->FUN_1411a49c0(kTarget);
            }
        }
    }
    else if (m_nFxOther != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nFxOther);
        m_nFxOther = 0;
    }
}

// @0x140b107f0
void CPet::FUN_140b107f0(int nKind)
{
    m_nKind = nKind;
    void* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal != 0)
    {
        if (static_cast<PCBase*>(pLocal)->FUN_14123c580() == m_nKind)
        {
            bool bShow = FUN_14166ce30() == 0 && (vfunc_129().get() != 0 ? true : false);
            if (bShow)
            {
                vfunc_129()->FUN_140e97ca0(1);
                vfunc_129()->FUN_140e97ce0(GetTamingPoint());
            }
        }
    }
}

// @0x140b109f0
int CPet::GetKind()
{
    return m_nKind;
}

// @0x140b10a10
void CPet::FUN_140b10a10(unsigned __int64 nPoint)
{
    bool bRename = false;
    if (m_nTamingPoint != nPoint)
    {
        if (nPoint == *Client::Constants::GetInstance()->TamingPetMaxPoint.Get())
        {
            void* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pLocal != 0 && static_cast<PCBase*>(pLocal)->FUN_14123c580() == GetKind())
                FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_pet_msg_taming_max_point")), 1, 1);
            bRename = true;
            goto Store;
        }
    }
    if (FUN_140b10c20() != 0)
    {
        if (nPoint != *Client::Constants::GetInstance()->TamingPetMaxPoint.Get())
            bRename = true;
    }
Store:
    m_nTamingPoint = nPoint;
    if (bRename)
        FUN_140b10c80(CStringW(L""));
    if (m_spBar.get() != 0)
        m_spBar->FUN_140e97d70(m_nTamingPoint);
}

// @0x140b10c00
unsigned __int64 CPet::GetTamingPoint()
{
    return m_nTamingPoint;
}

// @0x140b10c20
int CPet::FUN_140b10c20()
{
    return *Client::Constants::GetInstance()->TamingPetMaxPoint.Get() == GetTamingPoint();
}

// @0x140b10c80
// MS2-FUNCTIONAL: the temporaries of the prefix / format lookups are sequenced differently
void CPet::FUN_140b10c80(CStringW str)
{
    CStringW strName(str);
    if (strName.IsEmpty())
        strName = FUN_1401a9d70()->FUN_141811980(0x3b, m_nPetId);
    if (!strName.IsEmpty())
    {
        if (FUN_140a7c8d0(m_spNpcData.get()) != 0)
        {
            if (GetOwnerId() == 0)
            {
                CStringW strPrefix;
                if (FUN_140b10c20() == 0)
                    strPrefix = GetStringCommonByKey(CStringW(L"s_pet_tamingnpc_default_perfix_name"));
                else
                    strPrefix = GetStringCommonByKey(CStringW(L"s_pet_tamingnpc_max_perfix_name"));
                strName = FUN_140656190(GetStringCommonByKey(CStringW(L"s_pet_tamingnpc_name")), strPrefix, strName);
            }
            vfunc_76(strName);
        }
    }
}

// @0x140b10f90
void CPet::FUN_140b10f90(unsigned short nGrade)
{
    m_nGrade = nGrade;
    m_nGradeFx = FUN_140678b50(FUN_1401c0db0(), m_nGrade);
}

// @0x140b10fe0
unsigned short CPet::GetGrade()
{
    return m_nGrade;
}

// @0x140b11000
int CPet::GetGradeFx()
{
    return m_nGradeFx;
}

// @0x140b11020
void CPet::FUN_140b11020()
{
    FUN_140291d10(m_nGradeFx);
}

// @0x140b11050
MS2Ptr<UITamingBar::Entity> CPet::vfunc_129()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0 && FUN_14123dbd0() == 0)
        return MS2Ptr<UITamingBar::Entity>(0);
    if (m_spBar == 0)
    {
        if (!(m_spBar = FUN_140e97f80(m_unk_70)).IsNull())
            m_spBar->FUN_140e97ca0(0);
    }
    return m_spBar;
}

// @0x140b11180
// MS2-FUNCTIONAL: the temporaries of the item-data lookups
int CPet::FUN_140b11180()
{
    PCBase* pOwner = FUN_140b10360();
    if (pOwner == 0)
        return 0;
    if (pOwner->FUN_14166ce30() != 0)
        return 0;
    if (FUN_14025e7b0()->m_8.FUN_1402c4c90(3) == 1)
        return 0;
    if (m_tm10a8.FUN_140268870(1000) != 0)
    {
        int nItemId = FUN_140b11c20(&FUN_140c8b450(FUN_140535320())->m_map, pOwner);
        if (nItemId == 0)
            return 0;
        MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
        if (spData == 0)
            return 0;
        short nLevel = spData->FUN_14053dc40();
        int nSkillId = spData->FUN_14053dc20();
        if (FUN_140b11810(pOwner->FUN_14166c930(), nSkillId, nLevel) != 0)
        {
            if (FUN_140c8b430(FUN_140535320())->FUN_140c89220(nItemId) != 0)
                return 1;
        }
    }
    return 0;
}

// @0x140b11320
void CPet::FUN_140b11320(float fTime)
{
    if (FUN_1422b9ea0(FUN_1408e57f0()) != 0)
        return;
    MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = vfunc_85();
    if (spBalloon.IsNull())
        return;
    if (spBalloon->FUN_1418fb6b0())
        return;
    m_nIdleMs += FUN_14028d260(fTime);
    if (spBalloon->FUN_140f48d40() != 0)
    {
        if ((unsigned)m_nIdleMs >= FUN_140a35ca0(FUN_140a36020(&Client::Constants::GetInstance()->MonologueShowTime)))
        {
            spBalloon->vfunc_3();
            m_nTargetId = 0;
            m_nIdleMs = 0;
        }
    }
}

// @0x140b11460
int CPet::vfunc_127()
{
    if (FUN_140b10150() != 0)
        return 0;
    PCBase* pOwner = FUN_141094f60();
    if (pOwner == 0)
        return 0;
    if (FUN_1409a8b10()->FUN_140b123b0()->m_bOther != 0 && pOwner->GetClassID() != 0x6200004)
        return 0;
    return 1;
}

// @0x140b114e0
// MS2-FUNCTIONAL: the nested null checks of the animation row lookup
void CPet::FUN_140b114e0(int nAnimId)
{
    if (m_nTargetId != nAnimId && vfunc_127() != 0)
    {
        MS2Ptr<Unk_PetAnimRow> spRow = FUN_140856fa0(FUN_141092fa0(), nAnimId);
        if (!spRow.IsNull())
        {
            if (!spRow->m_lines.FUN_140b123c0())
            {
                MS2Ptr<Unk_PetAnimLine> spLine = spRow->m_lines.FUN_140a4ffc0(0);
                if (!(spLine == 0))
                {
                    CStringW strText(spLine->m_strText);
                    if (strText.GetLength() > 0)
                    {
                        FUN_14166fff0(CStringW(strText));
                        m_nTargetId = nAnimId;
                        m_nIdleMs = 0;
                    }
                    if (spRow->m_lines.FUN_140a4ffc0(0)->m_strEffect.GetLength() > 0)
                    {
                        NiPoint3 kPos = vfunc_18();
                        FUN_1403ed280()->FUN_1411a4f40(CString(spRow->m_lines.FUN_140a4ffc0(0)->m_strEffect), kPos);
                    }
                }
            }
        }
    }
}

// @0x140b11760
void CPet::FUN_140b11760(CString strEffect)
{
    Unk_EffectTarget kTarget;
    kTarget.m_strName = strEffect;
    kTarget.m_nKind = vfunc_58();
    kTarget.FUN_140a53190(FUN_14123c580());
    FUN_1403ed280()->FUN_1411a49c0(kTarget);
}

// @0x140b11810
int CPet::FUN_140b11810(int nSkillType, unsigned nSkillId, unsigned short nLevel)
{
    if (nSkillType == 5)
        return 0;
    if (nSkillType == 0x1f)
        return 0;
    if (nSkillType == 0x12)
    {
        MS2Ptr<Unk_PetSkillLevel> spLevel = FUN_1401958b0()->FUN_1407ee2f0(nSkillId, nLevel);
        if (spLevel.get() != 0 ? true : false)
        {
            if (reinterpret_cast<Unk_SkillObj*>(spLevel.operator->())->FUN_140804450() != 0)
                return 0;
        }
    }
    return 1;
}

// @0x140b118f0
// MS2-FUNCTIONAL: the cooldown test reaches the skill system through the MyPC view
int FUN_140b118f0(int nItemId, PCBase* pPC)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return 0;
    int nSkillId = spData->FUN_14053dc20();
    if (static_cast<MyPC*>(pPC)->FUN_141523bc0()->FUN_141765fe0(nSkillId, 0) > 0.0f)
        return 1;
    return 0;
}

// @0x140b119c0
unsigned FUN_140b119c0(int nItemId, PCBase* pPC)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData.IsNull())
        return 0;
    unsigned short nLevel = spData->FUN_14053dc40();
    int nSkillId = spData->FUN_14053dc20();
    MS2Ptr<Unk_PetSkillLevel> spLevel = FUN_1401958b0()->FUN_1407ee2f0(nSkillId, nLevel);
    if (spLevel.IsNull())
        return 0;
    std::vector<MS2Ptr<Unk_PetSkillElem> >& vElems = spLevel->m_vElems;
    for (std::vector<MS2Ptr<Unk_PetSkillElem> >::iterator it = vElems.begin(); it != vElems.end(); ++it)
    {
        if (it->get() != 0)
        {
            if ((*it)->m_nSkillId == 0)
                return 0;
            return pPC->FUN_1416749a0()->FUN_140970020((*it)->m_nSkillId, (*it)->m_nLevel, 0, 1) ? 1 : 0;
        }
    }
    return 0;
}

// @0x140b11c20
int FUN_140b11c20(CAtlMap<int, Unk_PetFoodRule>* pMap, PCBase* pPC)
{
    if (pPC->FUN_141676a10() == 0)
        return 0;
    __int64 nMax = pPC->FUN_141670a30(4);
    __int64 nCur = pPC->FUN_141670a00(4);
    if (nCur == 0 || nMax == 0)
        return 0;
    float fPercent = (float)(((double)nCur / (double)nMax) * 100.0);
    int nBest = 0;
    float fBest = 100.0f;
    for (POSITION pos = pMap->GetStartPosition(); pos != 0; pMap->GetNext(pos))
    {
        const Unk_PetFoodRule& kRule = pMap->GetAt(pos)->m_value;
        if (kRule.m_nItemId != 0 && kRule.m_fRate >= 1.0f)
        {
            MS2Ptr<Unk_ItemEquipData> spData = FUN_140c8b430(FUN_140535320())->FUN_140c892c0(kRule.m_nItemId);
            if (!spData.IsNull())
            {
                if (spData->FUN_140526810(pPC->vfunc_78()) != 0)
                {
                    if (FUN_140b118f0(kRule.m_nItemId, pPC) == 0 && FUN_140b119c0(kRule.m_nItemId, pPC) == 0)
                    {
                        if (fPercent <= kRule.m_fRate && kRule.m_fRate < fBest)
                        {
                            nBest = kRule.m_nItemId;
                            fBest = kRule.m_fRate;
                        }
                    }
                }
            }
        }
    }
    return nBest;
}

// @0x140b11e90
int FUN_140b11e90(CAtlMap<int, Unk_PetFoodRule>* pMap, PCBase* pPC)
{
    if (pPC->FUN_141676a10() == 0)
        return 0;
    __int64 nMax = pPC->FUN_141670a30(4);
    __int64 nCur = pPC->FUN_141670a00(4);
    if (nCur == 0 || nMax == 0)
        return 0;
    float fPercent = ((float)nCur / (float)nMax) * 100.0f;
    int nBest = 0;
    float fBest = 100.0f;
    for (POSITION pos = pMap->GetStartPosition(); pos != 0; pMap->GetNext(pos))
    {
        const Unk_PetFoodRule& kRule = pMap->GetAt(pos)->m_value;
        if (kRule.m_nItemId != 0 && kRule.m_fRate >= 1.0f)
        {
            MS2Ptr<Unk_ItemEquipData> spData = FUN_140c8b430(FUN_140535320())->FUN_140c892c0(kRule.m_nItemId);
            if (spData.get() != 0)
            {
                if (spData->FUN_140526810(pPC->vfunc_78()) == 0)
                    continue;
            }
            if (fPercent <= kRule.m_fRate && kRule.m_fRate < fBest)
            {
                nBest = kRule.m_nItemId;
                fBest = kRule.m_fRate;
            }
        }
    }
    return nBest;
}

MS2_EMIT_CRT_MEMMOVE_S();
