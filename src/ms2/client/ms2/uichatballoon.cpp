// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Image chat balloon HUD (world-anchored, UIHudEntity
// family), followed by a few unrelated UI helpers the linker placed at the end of the object.
// MS2-UNIT: ?\uichatballoon.cpp
// MS2-RANGE: 0x1418fafd0-0x1418fcee0 .text$mn
// MS2-RANGE: 0x140111600-0x1401117c0 .text$di
// MS2-RANGE: 0x142cbd330-0x142cbd3e0 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uichatballoon.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <imm.h>
#pragma comment(lib, "imm32.lib")
#include <string.h>
#include "uichatballoon.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The unit's statics: the shared header statics (a pointer handle sits between "stun" and the condition), then the
// confirmCommend string id.
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uichatballoon_ptr.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
static CStringW s_confirmCommend = L"confirmCommend";
extern CStringW DAT_143af1bc8;                                      // the game exit message tag (another unit's static)

// Unit-local declarations; the unidentified names describe uses rather than original class names.
struct Unk_CbCfgFloat { float FUN_1402bac70(); char m_pad[0x58]; };
struct Unk_CbCfgInt { int FUN_14025a620(); char m_pad[0x58]; };
struct Unk_CbCfg
{
    char m_pad_0000[0x270];
    Unk_CbCfgFloat m_270;
    char m_pad_02c8[0x8a0 - 0x270 - sizeof(Unk_CbCfgFloat)];
    Unk_CbCfgInt m_8a0;
};
Unk_CbCfg* FUN_1401d3200();
struct Unk_CbCfg2 { char m_pad[0x90]; CString m_90; };
Unk_CbCfg2* FUN_1401d31f0();                                        // the default profile image name
class Unk_CbUIScale { public: int FUN_1422b0f10(); };
Unk_CbUIScale* FUN_14025e7a0();                                     // ui scale service
float FUN_1422afec0(Unk_CbUIScale* pScale, int nLayer);             // scale of a layer
NiPoint3* FUN_140ad0c10(NiPoint3* pt, float f);                     // efd::Point3::operator*=
class Unk_CbEntity : public ASGameEntity
{
public:
    Scaleform::GFx::Value FUN_140ba9470(const char* szMethod, int a1, CString a2, bool a3);      // "createEntity"
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value a1, bool a2); // "updateEntity"
    Scaleform::GFx::Value& FUN_1422bb870();
};
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
bool FUN_140930110(int nActorId);

// The actor: the pc / npc / pet views and their data handles.
struct Unk_CbNpcInfo { char m_pad[0x90]; CString m_90; };
class Unk_CbNpcDataPtr
{
public:
    ~Unk_CbNpcDataPtr() { FUN_1406d5390(); }
    void FUN_1406d5390();                                           // release
    void* m_pad_00;
    void* m_p;
};
class Unk_CbInfoPtr                                                 // the converted handle (16 bytes)
{
public:
    ~Unk_CbInfoPtr() { FUN_14035e5b0(); }
    void FUN_1406cf850(Unk_CbNpcDataPtr* pSrc);                     // construct from the npc data handle
    bool FUN_140729ad0();                                           // is set
    Unk_CbNpcInfo* FUN_14035eb90();                                 // operator->
    void FUN_14035e5b0();                                           // release
    void* m_pad_00;
    void* m_p;
};
class Unk_CbPetPtr
{
public:
    ~Unk_CbPetPtr() { FUN_1406d5390(); }
    void FUN_1406d5390();
    void* m_pad_00;
    void* m_p;
};
class Unk_CbTmp24
{
public:
    ~Unk_CbTmp24() { FUN_1405a8650(); }
    void FUN_1405a8650();                                           // release
    bool FUN_1412722d0(int n);
    void* m_a; void* m_b; void* m_c;
};
class Unk_CbObj { public: Unk_CbTmp24 FUN_141270740(int n); };
class Unk_CbPet { public: Unk_CbNpcDataPtr FUN_140a4f1b0(); };
Unk_CbPet* FUN_1418fc490(PCBase* pActor);                           // the actor as a pet (queries class id 0x6200080)
class Unk_CbNpc : public PCBase
{
public:
    Unk_CbNpcDataPtr FUN_141093270();
};
class Unk_CbActor : public PCBase
{
public:
    int FUN_14166ce30();                                            // is dead
    float FUN_141670500();                                          // vertical offset
};
class Unk_CbPC : public Unk_CbActor
{
public:
    Unk_CbObj* FUN_14165f460();
    CString FUN_1416612e0();                                        // profile image name of the player
};
Unk_CbNpc* FUN_14096e110(PCBase* pActor);                           // the actor as an npc
void* FUN_14096e160(PCBase* pActor);                                // the actor as a monster
Unk_CbPC* FUN_140974230(PCBase* pActor);                            // the actor as a player
__int64 FUN_141656a80(PCBase* pPc);                                 // player account id
CString FUN_141028be0(__int64 nId, const CString& strName, int nFlag, CString strExtra);   // profile image path
CStringW FUN_14016a730(const char* sz, int nFlags);                 // FormatStringId(id) without arguments
struct Unk_CbFlags { bool m_0; bool m_1; };
class Unk_CbFlagHolder { public: Unk_CbFlags* FUN_14124ab20(); char* FUN_140e09150(); };
Unk_CbFlagHolder* FUN_1409a8b10();
class Unk_CbSvc1 { public: int FUN_140a18070(); };
Unk_CbSvc1* FUN_1409478c0();
void* FUN_1408e57f0();
int FUN_1422b9e00(void*);
int FUN_1422b9ea0(void*);
class Unk_CbUIMgr
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int);
    void FUN_141adc530(int nUiId);
    int FUN_141adbb00();
    void FUN_141adc750(int nUiId);
};
Unk_CbUIMgr* FUN_1403ed2b0();
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned int nId);


// The list control helpers (item rank drop down) and the dialogs polled by FUN_1418fcb70.
class Unk_CbCtl
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(int n);
    void FUN_1422dfc10();                                           // clear
    unsigned int FUN_1422dfb90();                                   // item count
    void FUN_1422dfc70(ASObj& obj);                                 // add an item
    void FUN_1422df5f0(unsigned int n);
    void FUN_1422df690(int n);
};
class Unk_CbList
{
public:
    char FUN_140bc03e0(int n);
    Unk_CbCtl* FUN_140bc0530();
    void FUN_140bbfda0();                                           // end the update
};
struct Unk_CbListGuard
{
    Unk_CbListGuard(Unk_CbList* p) : m_p(p) {}
    ~Unk_CbListGuard() { m_p->FUN_140bbfda0(); }
    Unk_CbList* m_p;
};
struct Unk_CbItemData { int FUN_14053c5a0(); };
class Unk_CbItemPtr
{
public:
    ~Unk_CbItemPtr() { FUN_1401b50d0(); }
    void FUN_14053f870(int nItemId);                                // construct from the item id
    char FUN_1401b5240(int n);
    Unk_CbItemData* FUN_1401b52a0();
    void FUN_1401b50d0();
    void* m_pad_00;
    void* m_p;
};
class Unk_CbStrSvc { public: CStringW FUN_141813150(int nId); };
Unk_CbStrSvc* FUN_1401a9d70();
class Unk_CbDlgA { public: int FUN_1419102c0(); };
class Unk_CbDlgB { public: int FUN_141959a20(); };
Unk_CbDlgA* FUN_14138fd50(int nUiId);
Unk_CbDlgB* FUN_14136f3e0(int nUiId);
class Unk_CbPtr                                                     // a 16 byte smart pointer passed by value
{
public:
    Unk_CbPtr(int n) { FUN_140203510(n); }
    ~Unk_CbPtr() { FUN_1401bfde0(); }
    void FUN_140203510(int n);                                      // construct (null)
    void FUN_1401bfde0();                                           // release
    void* m_pad_00;
    void* m_p;
};
class Unk_CbSvc2 { public: int FUN_140954150(); void FUN_140cdadb0(Unk_CbPtr tag); };
Unk_CbSvc2* FUN_140953f20();
int FUN_141274ff0();
int FUN_141275080();
void FUN_141274f50();
void* FUN_14209c720(void*);
void* FUN_140aadf80();
int FUN_141b710a0(unsigned __int64 nChar);
int FUN_14151f6e0();
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);

// @0x1418fafd0
UIChatBalloon::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : TimerEntity(nLayer, clip, nActorId), m_a0(0), m_a8(""), m_b0(L"")
{
    m_64 = FUN_1401d3200()->m_8a0.FUN_14025a620();
    m_54 = FUN_1401d3200()->m_270.FUN_1402bac70();
}

// @0x1418fb0b0
UIChatBalloon::Entity::~Entity()
{
}

// @0x1418fb110
void UIChatBalloon::Entity::vfunc_2()
{
    TimerEntity::vfunc_2();
}

// @0x1418fb130
void UIChatBalloon::Entity::vfunc_3()
{
    TimerEntity::vfunc_3();
    vfunc_7();
}

// @0x1418fb160
void UIChatBalloon::Entity::vfunc_4()
{
    UIHudEntity::Entity::vfunc_4();
    m_a8 = "";
    m_b0 = L"";
    m_a0 = 0;
}

// MS2-FUNCTIONAL: frame layout of the temporaries differs (16 bytes larger)
// @0x1418fb1c0
void UIChatBalloon::Entity::vfunc_5()
{
    UIHudEntity::Entity::vfunc_5();
    if (FUN_1409478c0()->FUN_140a18070() == 0)
        return;
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return;
    if (m_38.get() == 0)
        return;
    Unk_CbPC* pPc = FUN_140974230(pActor);
    if (pPc != 0)
    {
        if (pPc->FUN_14165f460()->FUN_141270740(3).FUN_1412722d0(0))
            m_a8.Empty();
    }
    ASObj obj(m_18);
    obj.FUN_1407cbb20("text", m_b0);
    obj.FUN_1407cbb20("imgPath", FUN_14016a730((const char*)FUN_1418fb7e0(), 0));
    obj.FUN_1407cbbe0("bNpc", FUN_14087ddc0(pActor ? pActor->GetClassDesc() : 0, 0x6200028));
    const char* szSkin;
    if (((Unk_CbActor*)pActor)->FUN_14166ce30() == 0)
        szSkin = (const char*)m_a8;
    else
        szSkin = "dead";
    obj.FUN_1409c0dc0("skin", szSkin);
    m_38->Invoke("open", obj);
}

// @0x1418fb4a0
void UIChatBalloon::Entity::vfunc_6(NiPoint3* pPos)
{
    if (m_38.get() != 0)
    {
        FUN_140ad0c10(pPos, FUN_1422afec0(FUN_14025e7a0(), m_18));
        pPos->y = pPos->y + vfunc_9();
        m_38->FUN_1422c00f0(pPos->x - 110.0f, pPos->y - 90.0f);
    }
}

// @0x1418fb580
void UIChatBalloon::Entity::vfunc_7()
{
    if (m_38.get() != 0)
        m_38->Invoke("close");
}

// @0x1418fb5e0
int UIChatBalloon::Entity::vfunc_8(int n)
{
    if (FUN_1422b9e00(FUN_1408e57f0()) != 0x620001d)
    {
        if (FUN_1422b9ea0(FUN_1408e57f0()) == 0)
            return 1;
    }
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return 1;
    if (FUN_1418fbbf0() == 0)
        return 1;
    return TimerEntity::vfunc_8(((Unk_CbActor*)pActor)->FUN_14166ce30());
}

// @0x1418fb670
float UIChatBalloon::Entity::vfunc_9()
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return 0.0f;
    return ((Unk_CbActor*)pActor)->FUN_141670500();
}

// @0x1418fb6b0
bool UIChatBalloon::Entity::FUN_1418fb6b0()
{
    return m_a0;
}

// @0x1418fb6d0
void UIChatBalloon::Entity::FUN_1418fb6d0()
{
    m_a0 = 1;
}

// @0x1418fb6f0
void UIChatBalloon::Entity::FUN_1418fb6f0(const CString& strSkin)
{
    m_a8 = strSkin;
}

// @0x1418fb730
void UIChatBalloon::Entity::FUN_1418fb730(const CStringW& strText)
{
    m_b0 = strText;
}

// @0x1418fb790
__int64 UIChatBalloon::Entity::FUN_1418fb790()
{
    Unk_CbPC* pPc = FUN_140974230(FUN_140f49330());
    if (pPc != 0)
        return FUN_141656a80(pPc);
    return 0;
}

// MS2-FUNCTIONAL: smart-pointer handle temporaries/cleanup layout differs
// @0x1418fb7e0
CString UIChatBalloon::Entity::FUN_1418fb7e0()
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return CString("");
    CString strUnused1;
    CString strUnused2;
    Unk_CbNpc* pNpc = FUN_14096e110(pActor);
    if (pNpc == 0)
    {
        Unk_CbPC* pPc = FUN_140974230(pActor);
        if (pPc != 0)
            return FUN_141028be0(FUN_141656a80(pPc), pPc->FUN_1416612e0(), 1, CString(""));
        Unk_CbPet* pPet = FUN_1418fc490(pActor);
        if (pPet != 0)
        {
            Unk_CbInfoPtr info;
            {
                Unk_CbNpcDataPtr data = pPet->FUN_140a4f1b0();
                info.FUN_1406cf850(&data);
            }
            if (info.FUN_140729ad0() != 0)
            {
                CString str(info.FUN_14035eb90()->m_90);
                if (str.GetLength() != 0)
                    return str;
            }
        }
    }
    else
    {
        Unk_CbInfoPtr info;
        {
            Unk_CbNpcDataPtr data = pNpc->FUN_141093270();
            info.FUN_1406cf850(&data);
        }
        if (info.FUN_140729ad0() != 0)
        {
            CString str(info.FUN_14035eb90()->m_90);
            if (str.GetLength() != 0)
                return str;
        }
    }
    return FUN_1401d31f0()->m_90;
}

// @0x1418fbbf0
int UIChatBalloon::Entity::FUN_1418fbbf0()
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return 0;
    void* pMonster = FUN_14096e160(pActor);
    if (pMonster != 0)
    {
        return FUN_1409a8b10()->FUN_14124ab20()->m_0;
    }
    else
    {
        Unk_CbPC* pPc = FUN_140974230(pActor);
        if (pPc != 0)
            return FUN_1409a8b10()->FUN_14124ab20()->m_1;
    }
    return 1;
}

// @0x1418fbc80
UIChatBalloon::UIChatBalloon()
{
    m_70 = "imageballoon_Ani";
}

// @0x1418fbcf0
UIChatBalloon::~UIChatBalloon()
{
}

// @0x1418fbd30
CString UIChatBalloon::vfunc_1()
{
    return CString("PopupImageBalloon");
}

// @0x1418fbd80
void UIChatBalloon::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_1418fbe70(m_68);
}

// @0x1418fc4e0
UIChatBalloon* FUN_1418fc4e0(int nUiId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (p.get())
            return dynamic_cast<UIChatBalloon*>((UIObject*)p);
    }
    return 0;
}

// @0x1418fbdb0
MS2Ptr<UIChatBalloon::Entity> FUN_1418fbdb0(int nActorId)
{
    UIChatBalloon* pBalloon = FUN_1418fc4e0(0x4e2e);
    if (pBalloon != 0)
        return MS2Ptr<UIChatBalloon::Entity>(pBalloon->FUN_1418fc050(nActorId));
    return MS2Ptr<UIChatBalloon::Entity>(0);
}

// @0x1418fbe30
void FUN_1418fbe30(int nActorId)
{
    UIChatBalloon* pBalloon = FUN_1418fc4e0(0x4e2e);
    if (pBalloon)
        pBalloon->FUN_140f49c00(nActorId);
}


// @0x1418fbe70
void UIChatBalloon::FUN_1418fbe70(unsigned int nCount)
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


// @0x1418fc050
UIChatBalloon::Entity* UIChatBalloon::FUN_1418fc050(int nActorId)
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
            Scaleform::GFx::Value v = ((Unk_CbEntity*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
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
                    if (FUN_140930110(nOld) || bNew)
                    {
                        MS2Ptr<ASGameEntity> pOldClip = pEntity->FUN_140f48ed0();
                        if (pOldClip.get())
                            ((Unk_CbEntity*)pClip.operator->())->FUN_140ba9570("updateEntity", ((Unk_CbEntity*)pOldClip.operator->())->FUN_1422bb870(), bNew);
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

// @0x1418fc580 is the MS2Ptr<UIChatBalloon::Entity> pointer constructor (COMDAT).

// @0x1418fc490
Unk_CbPet* FUN_1418fc490(PCBase* pActor)
{
    Unk_CbPet* pPet = 0;
    if (pActor != 0 && pActor->TypeCast(0x6200080, (void**)&pPet))
        return pPet;
    else
        return 0;
}

// @0x1418fc630 is UIChatBalloon::vfunc_48 (inline in the header).

// @0x1418fc760
int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4)
{
    if (_stricmp("OnGameExit", szEvent) == 0)
    {
        FUN_140d73bc0(0x288, 0x17, 0, DAT_143af1bc8);
        return 1;
    }
    else if (_stricmp("OnGameOption", szEvent) == 0)
    {
        FUN_1403ed2b0()->FUN_141adc530(0x4ef3);
        return 1;
    }
    return 0;
}

// @0x1418fc810
int FUN_1418fc810()
{
    if (FUN_14151f6e0() != 0)
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: unrecovered list control helpers; temporary layout differs
// @0x1418fc840
void FUN_1418fc840(Unk_CbList* pList, int nItemId, int nSelRank)
{
    Unk_CbListGuard guard(pList);
    if (pList->FUN_140bc03e0(0) != 0)
        return;
    pList->FUN_140bc0530()->FUN_1422dfc10();
    Unk_CbItemPtr item;
    item.FUN_14053f870(nItemId);
    if (item.FUN_1401b5240(0) != 0)
        return;
    int nSel = 0;
    if (item.FUN_1401b52a0()->FUN_14053c5a0() == 0)
    {
        for (int nRank = 1; nRank < 7; nRank++)
        {
            ASObj row(2);
            row.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141813150(nRank));
            row.FUN_1407cb9c0("itemRank", nRank);
            if (nRank == nSelRank)
                nSel = pList->FUN_140bc0530()->FUN_1422dfb90();
            pList->FUN_140bc0530()->FUN_1422dfc70(row);
        }
    }
    else
    {
        ASObj row(2);
        row.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141813150(item.FUN_1401b52a0()->FUN_14053c5a0()));
        row.FUN_1409adc90("itemRank", item.FUN_1401b52a0()->FUN_14053c5a0());
        pList->FUN_140bc0530()->FUN_1422dfc70(row);
        nSel = 0;
    }
    unsigned int nCount = pList->FUN_140bc0530()->FUN_1422dfb90();
    if (nCount < 2)
        nCount = 1;
    pList->FUN_140bc0530()->FUN_1422df5f0(nCount);
    pList->FUN_140bc0530()->FUN_1422df690(nSel);
    pList->FUN_140bc0530()->vfunc_24(1);
}

// MS2-FUNCTIONAL: by-value smart pointer argument is copied here (rep movs) but constructed in place in the exe
// @0x1418fcb70
int FUN_1418fcb70()
{
    if (FUN_14025e7a0()->FUN_1422b0f10() != 0)
        return 1;
    Unk_CbDlgA* pA = FUN_14138fd50(0x4e7e);
    if (pA != 0 && pA->FUN_1419102c0() != 0)
        return 0;
    Unk_CbDlgB* pB = FUN_14136f3e0(0x4e53);
    if (pB != 0 && pB->FUN_141959a20() != 0)
        return 1;
    if (FUN_1403ed2b0()->FUN_141adbb00() != 0)
        return 0;
    if (FUN_141274ff0() == 0)
    {
        if (FUN_140953f20()->FUN_140954150() != 0)
        {
            FUN_140953f20()->FUN_140cdadb0(Unk_CbPtr(0));
            return 1;
        }
        if (FUN_141275080() == 0)
            return 0;
        FUN_1403ed2b0()->FUN_141adc750(0x4e21);
    }
    else
    {
        if (*FUN_1409a8b10()->FUN_140e09150() == 0)
            return 0;
        FUN_141274f50();
    }
    return 1;
}

// MS2-FUNCTIONAL: IME composition branch layout differs
// @0x1418fccc0
int FUN_1418fccc0(int nMsg, unsigned __int64 wParam, unsigned __int64 lParam, CStringW* pStr)
{
    if (nMsg == 0x10f)
    {
        HIMC hImc = ImmGetContext((HWND)FUN_14209c720(FUN_140aadf80()));
        if (hImc == 0)
            return 0;
        DWORD nLen = 0;
        wchar_t buf[256];
        memset(buf, 0, sizeof(buf));
        if ((lParam & 0x2000) == 0)
        {
            if (wParam != 8 && wParam != 0x1b)
                return 0;
        }
        else
        {
            if ((lParam & 0x800) == 0)
            {
                if ((lParam & 8) == 0)
                    return 0;
                nLen = ImmGetCompositionStringW(hImc, 8, 0, 0);
                if (0 < (int)nLen)
                    ImmGetCompositionStringW(hImc, 8, buf, nLen);
            }
            else
            {
                nLen = ImmGetCompositionStringW(hImc, 0x800, 0, 0);
                if (0 < (int)nLen)
                    ImmGetCompositionStringW(hImc, 0x800, buf, nLen);
            }
            ImmReleaseContext((HWND)FUN_14209c720(FUN_140aadf80()), hImc);
            *pStr += buf;
        }
    }
    else
    {
        wchar_t ch = (wchar_t)wParam;
        if (FUN_141b710a0(wParam & 0xffff) == 0)
        {
            if (ch != L'\b' && ch != L'\x1b')
                return 0;
            pStr->Delete(pStr->GetLength() - 1, 1);
        }
        else
            *pStr += ch;
    }
    return 1;
}

MS2_REPLACE_METHOD(0x1418FB110, UIChatBalloon::Entity, vfunc_2, 24, 0xD99F307F);
MS2_REPLACE_METHOD(0x1418FB130, UIChatBalloon::Entity, vfunc_3, 40, 0x4188D2C9);
MS2_REPLACE_METHOD(0x1418FB160, UIChatBalloon::Entity, vfunc_4, 90, 0x1B57BBD7);
MS2_REPLACE_METHOD(0x1418FB4A0, UIChatBalloon::Entity, vfunc_6, 212, 0xD389CA99);
MS2_REPLACE_METHOD(0x1418FB580, UIChatBalloon::Entity, vfunc_7, 83, 0xFA93D56D);
MS2_REPLACE_METHOD(0x1418FB5E0, UIChatBalloon::Entity, vfunc_8, 135, 0x642C9030);
MS2_REPLACE_METHOD(0x1418FB670, UIChatBalloon::Entity, vfunc_9, 52, 0x0155C013);
MS2_REPLACE_METHOD(0x1418FB6B0, UIChatBalloon::Entity, FUN_1418fb6b0, 18, 0xF7802F75);
MS2_REPLACE_METHOD(0x1418FB6D0, UIChatBalloon::Entity, FUN_1418fb6d0, 18, 0xC170A023);
MS2_REPLACE_METHOD(0x1418FB6F0, UIChatBalloon::Entity, FUN_1418fb6f0, 44, 0x6ADBAFF3);
MS2_REPLACE_METHOD(0x1418FB730, UIChatBalloon::Entity, FUN_1418fb730, 44, 0x13DDB988);
MS2_REPLACE_METHOD(0x1418FB790, UIChatBalloon::Entity, FUN_1418fb790, 59, 0x882B5198);
MS2_REPLACE_METHOD(0x1418FBBF0, UIChatBalloon::Entity, FUN_1418fbbf0, 129, 0x2C48873E);
MS2_REPLACE_METHOD(0x1418FBD30, UIChatBalloon, vfunc_1, 61, 0xCDA04F5F);
MS2_REPLACE_METHOD(0x1418FBD80, UIChatBalloon, OnLoadComplete, 42, 0x22489B16);
MS2_REPLACE_METHOD(0x1418FBE70, UIChatBalloon, FUN_1418fbe70, 465, 0x931A0B41);
MS2_REPLACE_METHOD(0x1418FC050, UIChatBalloon, FUN_1418fc050, 1082, 0x633302C0);
MS2_REPLACE(0x1418FBDB0, FUN_1418fbdb0, 122, 0xB7D52CC5);
MS2_REPLACE(0x1418FBE30, FUN_1418fbe30, 50, 0x0CB147FD);
MS2_REPLACE(0x1418FC4E0, FUN_1418fc4e0, 147, 0x4BF21D95);
MS2_REPLACE(0x1418FC490, FUN_1418fc490, 73, 0xCB6B9CB0);
MS2_REPLACE(0x1418FC760, FUN_1418fc760, 161, 0x7370E97D);
MS2_REPLACE(0x1418FC810, FUN_1418fc810, 27, 0x8EBD5165);

MS2_EMIT_CRT_MEMMOVE_S();
// MS2-PIN: ??__Es_pointer1401cd100@@YAXXZ 0x140111720 ; header static (uichatballoon_ptr.h) dynamic initializer
