// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDamageEffect.
// MS2-UNIT: ?\uidamageeffect.cpp
// MS2-RANGE: 0x141910480-0x141910bf0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uidamageeffect.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

class Unk_DmgStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);           // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);           // unregister
};
Unk_DmgStatusMgr* FUN_140aa6d40();

// The local player's stats: slot 4 = HP.
class Unk_DmgPlayer
{
public:
    __int64 FUN_141670a00(int nStat);                               // current value
    __int64 FUN_141670a30(int nStat);                               // maximum value
};
class Unk_DmgWorld { };
Unk_DmgWorld* FUN_1403ed2d0();
Unk_DmgPlayer* FUN_141bd0cc0(Unk_DmgWorld* pWorld);                 // the local player

// The settings singleton: two float options at +0xc818 and +0xc870.
class Unk_DmgFloatVar { public: float FUN_1402bac70(); };
class Unk_DmgGlobals
{
public:
    char m_pad_0000[0xc818];
    Unk_DmgFloatVar m_c818;
    char m_pad_c819[0xc870 - 0xc819];
    Unk_DmgFloatVar m_c870;
};
Unk_DmgGlobals* FUN_1401d3200();

class Unk_DmgCfgInfo { public: char m_pad_00[0xc]; int m_0c; };
void* FUN_1409a8b10();
Unk_DmgCfgInfo* FUN_140e09150(void* pCfg);

int FUN_141277f40();                                                // next UI layer
bool FUN_140a467d0(const MS2Ptr<AScript>*);                         // has the AS object been released

// The movie's root: "init" takes (float, int).
class Unk_DmgScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_1418cc380(const char* szMethod, float a1, int a2);
};

// The root as an ASGameEntity: slot 25 is "validateNow" (ASGameEntity declares only slots 0..5).
class Unk_DmgEntity : public ASGameEntity
{
public:
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24();
    virtual void vfunc_25();
};

// @0x141910480
UIDamageEffect::UIDamageEffect()
{
    m_nLowHp = 0;
    m_fLowHpPercent = 30.0f;
    m_fOption80 = 10.0f;
    m_58 = 0;
    m_2c = 1;
    m_28 = FUN_141277f40();
}

// @0x141910550
UIDamageEffect::~UIDamageEffect()
{
}

// @0x1419105b0
CString UIDamageEffect::vfunc_1()
{
    return "DamageEffect";
}

// @0x141910600
void UIDamageEffect::vfunc_3()
{
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    m_nLowHp = 0;
    UIHeadUpDisplay::vfunc_3();
}

// @0x141910660
void UIDamageEffect::FUN_141910660()
{
    if (FUN_140a467d0(&m_30))
        return;
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    m_30.operator->()->Invoke("onHide");
    m_nLowHp = 0;
}

// @0x141910700
void UIDamageEffect::FUN_141910700()
{
    if (FUN_140a467d0(&m_30))
        return;
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    Unk_DmgPlayer* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0)
        vfunc_oa0_3(pPlayer->FUN_141670a00(4), pPlayer->FUN_141670a30(4));
}

// @0x1419107d0
void UIDamageEffect::vfunc_oa0_3(int a1, int a2)
{
    if (FUN_140a467d0(&m_30))
        return;
    float fPercent = a2 == 0 ? 100.0f : ((float)(unsigned int)a1 * 100.0f) / (float)(unsigned int)a2;
    unsigned int nLow = (fPercent <= m_fLowHpPercent);
    if (nLow != (unsigned int)m_nLowHp || nLow != 0)
    {
        m_nLowHp = nLow;
        m_30.operator->()->Invoke("changeHP", fPercent);
    }
}

// @0x1419108e0
void UIDamageEffect::vfunc_43()
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
        static_cast<Unk_DmgEntity*>(pEntity.operator->())->vfunc_25();
}

// MS2-FUNCTIONAL: the exe loads this+0x30 straight into rcx for the m_30 operator-> call (mine goes through rax)
// @0x141910980
void UIDamageEffect::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_141910ab0();
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    Unk_DmgCfgInfo* pInfo = FUN_140e09150(FUN_1409a8b10());
    static_cast<Unk_DmgScript*>(m_30.operator->())->FUN_1418cc380("init", m_fLowHpPercent, pInfo->m_0c);
    Unk_DmgPlayer* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0)
        vfunc_oa0_3(pPlayer->FUN_141670a00(4), pPlayer->FUN_141670a30(4));
}

// @0x141910ab0
void UIDamageEffect::FUN_141910ab0()
{
    m_fLowHpPercent = FUN_1401d3200()->m_c818.FUN_1402bac70();
    m_fOption80 = FUN_1401d3200()->m_c870.FUN_1402bac70();
}

// @0x141910b10
void UIDamageEffect::FUN_141910b10(void*, void* a1)
{
}

// @0x141910b30
void UIDamageEffect::FUN_141910b30(float fAlpha)
{
    if (m_30.get())
        m_30.operator->()->Invoke("setAlpha", fAlpha);
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x1419105B0, UIDamageEffect, vfunc_1, 61, 0xCFA2E7B1);
MS2_REPLACE_METHOD(0x141910600, UIDamageEffect, vfunc_3, 87, 0x02DD1D34);
MS2_REPLACE_METHOD(0x141910660, UIDamageEffect, FUN_141910660, 150, 0x8989260B);
MS2_REPLACE_METHOD(0x141910700, UIDamageEffect, FUN_141910700, 193, 0xC2DF0EFB);
MS2_REPLACE_METHOD_VIA(0x1419107D0, UIDamageEffect, UIStatusEventListener, vfunc_oa0_3, 252, 0x87219CBE);
MS2_REPLACE_METHOD(0x1419108E0, UIDamageEffect, vfunc_43, 146, 0xA032B3CD);
MS2_REPLACE_METHOD(0x141910980, UIDamageEffect, OnLoadComplete, 298, 0xB8AF37B7);
MS2_REPLACE_METHOD(0x141910B30, UIDamageEffect, FUN_141910b30, 95, 0x606F3A5A);
MS2_REPLACE_METHOD(0x141910AB0, UIDamageEffect, FUN_141910ab0, 75, 0x13C75809);

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x140111f00-0x140112070 .text$di
// MS2-RANGE: 0x142cbd6e0-0x142cbd770 .text$yd
#include "ms2/placeholder/header_statics_a.h"
