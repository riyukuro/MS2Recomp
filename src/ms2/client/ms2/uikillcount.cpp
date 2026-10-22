// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIKillCount.
// MS2-UNIT: ?\uikillcount.cpp
// MS2-RANGE: 0x1419df070-0x1419df870 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uikillcount.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

// The settings singleton: the minimum shown kill count at +0xc1e0.
class Unk_KcInt { public: int FUN_14025a620(); };
class Unk_KcGlobals
{
public:
    char m_pad_0000[0xc1e0];
    Unk_KcInt m_c1e0;
};
Unk_KcGlobals* FUN_1401d3200();

int FUN_141277f40();                                                // next UI layer (unused here)
bool FUN_140a467d0(const MS2Ptr<AScript>*);                         // has the AS object been released
unsigned int FUN_140869420();                                       // the tick
class Unk_KcWorld { };
Unk_KcWorld* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(Unk_KcWorld* pWorld);                         // the local player
PCBase* FUN_14096e110(void* pObject);                               // the actor behind an object (NULL if none)
CStringW GetStringCommonByKey(const CStringW& strKey);                     // string table text
MS2Ptr<ASGameEntity> FUN_140ba77e0(int nUiId, const Scaleform::GFx::Value& root);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcda0(Scaleform::GFx::Value* pValue, double n);

// The movie's root: "show" takes (count, count, bonus).
class Unk_KcScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_1419df740(const char* szMethod, int a1, int a2, double a3);
};

// The root as an ASGameEntity: slot 25 is "validateNow" (ASGameEntity declares only slots 0..5).
class Unk_KcEntity : public ASGameEntity
{
public:
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24();
    virtual void vfunc_25();
};

// @0x1419df070
UIKillCount::UIKillCount()
{
    m_nShown = 0;
    m_nMinShow = 0;
    m_58 = 0;
    m_nMinShow = FUN_1401d3200()->m_c1e0.FUN_14025a620();
    m_2c = 0x14;
}

// @0x1419df130
UIKillCount::~UIKillCount()
{
}

// @0x1419df180
CString UIKillCount::GetTypeName()
{
    return "KillCount";
}

// @0x1419df1d0
void UIKillCount::vfunc_2()
{
    UIHeadUpDisplay::vfunc_2();
}

// @0x1419df1f0
void UIKillCount::vfunc_3()
{
    m_nShown = 0;
    UIHeadUpDisplay::vfunc_3();
}

// @0x1419df220
void UIKillCount::FUN_1419df220()
{
    if (m_nShown == 0)
        return;
    if (m_30.get())
        m_30.operator->()->Invoke("hide");
    m_nShown = 0;
}

// MS2-FUNCTIONAL: the exe loads the player's vtable into a temp before the vfunc_78 call (mine calls through the pointer)
// @0x1419df2a0
void UIKillCount::FUN_1419df2a0(void* pKilled)
{
    PCBase* pMob = FUN_14096e110(pKilled);
    if (pMob != 0)
    {
        __int64 nMax = pMob->FUN_141670a60(4);
        __int64 nCur = pMob->FUN_141670a00(4);
        if (0 < nMax && nCur == 0)
        {
            if (pMob->FUN_14166ce30() == 0)
            {
                PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
                if (pPlayer != 0)
                {
                    unsigned short nMobLevel = pMob->vfunc_78();
                    if (m_kill.FUN_14064c5f0(pPlayer->vfunc_78(), nMobLevel) != 0)
                        FUN_1419df580();
                }
            }
        }
    }
}

// @0x1419df3a0
void UIKillCount::vfunc_43()
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
        static_cast<Unk_KcEntity*>(pEntity.operator->())->vfunc_25();
}

// @0x1419df440
int UIKillCount::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: the exe materialises m_30's null test as a bool temp before the && (no source form found)
// @0x1419df490
void UIKillCount::vfunc_15()
{
    if (m_30.get() && 0 < m_nShown)
    {
        if (m_kill.FUN_14064c840(FUN_140869420()) == 0)
            FUN_1419df220();
    }
    UISwfEntity::vfunc_15();
}

// @0x1419df510
void UIKillCount::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

// @0x1419df580
void UIKillCount::FUN_1419df580()
{
    if (FUN_140a467d0(&m_30))
        return;
    int nCount = m_kill.FUN_14064c800();
    if (0 < m_nShown && m_nShown > nCount)
    {
        FUN_1419df220();
        return;
    }
    if (nCount < m_nMinShow)
        return;
    m_nShown = nCount;
    static_cast<Unk_KcScript*>(m_30.operator->())->FUN_1419df740("show", m_kill.FUN_14064c710(), nCount, m_kill.FUN_14064c6e0());
    FUN_1419df6a0();
}

// @0x1419df6a0
void UIKillCount::FUN_1419df6a0()
{
    CStringW strKey = m_kill.FUN_14064c740();
    if (!strKey.IsEmpty())
    {
        PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pPlayer != 0)
            pPlayer->FUN_14166fff0(GetStringCommonByKey(strKey));
    }
}

// @0x1419df740
Scaleform::GFx::Value Unk_KcScript::FUN_1419df740(const char* szMethod, int a1, int a2, double a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcda0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x1419DF180, UIKillCount, GetTypeName, 61, 0xDD8FB31B);
MS2_REPLACE_METHOD(0x1419DF1D0, UIKillCount, vfunc_2, 24, 0xB52C074C);
MS2_REPLACE_METHOD(0x1419DF1F0, UIKillCount, vfunc_3, 39, 0x061EB3D3);
MS2_REPLACE_METHOD(0x1419DF220, UIKillCount, FUN_1419df220, 114, 0xF6132C6B);
MS2_REPLACE_METHOD(0x1419DF2A0, UIKillCount, FUN_1419df2a0, 243, 0xBE09A6B2);
MS2_REPLACE_METHOD(0x1419DF3A0, UIKillCount, vfunc_43, 146, 0xFE5648CE);
MS2_REPLACE_METHOD(0x1419DF440, UIKillCount, vfunc_28, 67, 0x50ABE63D);
MS2_REPLACE_METHOD(0x1419DF490, UIKillCount, vfunc_15, 116, 0x0BC74B31);
MS2_REPLACE_METHOD(0x1419DF510, UIKillCount, vfunc_41, 99, 0x18E52093);
MS2_REPLACE_METHOD(0x1419DF580, UIKillCount, FUN_1419df580, 272, 0x416394CB);
MS2_REPLACE_METHOD(0x1419DF6A0, UIKillCount, FUN_1419df6a0, 147, 0x9B449C28);
