// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIExpBar, the HUD experience bar.
// MS2-UNIT: ?\uiexpbar.cpp
// MS2-RANGE: 0x141931eb0-0x141933270 .text$mn
// MS2-RANGE: 0x140113280-0x140113330 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uiexpbar.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>
#include <algorithm>

// ---- unit-local views of exe objects ----

class Unk_ExpCfg
{
public:
    unsigned int* FUN_1401d7c10();                                  // the value
};
class Unk_ExpGlobals
{
public:
    char m_pad_0000[0x6b00];
    Unk_ExpCfg m_6b00;
};
Unk_ExpGlobals* FUN_1401d3200();

class Unk_ExpStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);           // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);           // unregister
};
Unk_ExpStatusMgr* FUN_140aa6d40();
class Unk_ExpUIMgr { public: void FUN_141adc750(int nUiId); };      // opens a ui
Unk_ExpUIMgr* FUN_1403ed2b0();
struct Unk_ExpCfgData { char m_pad_00[8]; unsigned char m_bShowPoint; };
class Unk_ExpCfgHolder { public: Unk_ExpCfgData* FUN_140b123b0(); };
Unk_ExpCfgHolder* FUN_1409a8b10();
class Unk_ExpUiScale { public: float FUN_1422afec0(int nUiId); };
Unk_ExpUiScale* FUN_14025e7a0();
class Unk_ExpDebug { public: bool FUN_14116d720(); };
Unk_ExpDebug* FUN_14025e7c0();
class Unk_ExpTextFilter { public: void FUN_1416fb340(CStringW& strText); };
Unk_ExpTextFilter* FUN_1403b4750();
class Unk_ExpLevelTable { public: __int64 FUN_140353610(unsigned short nLevel); };
Unk_ExpLevelTable* FUN_1404a1bb0();
int FUN_1412755a0();
bool FUN_140184310(const CString& str, const char* psz);            // str == psz
CStringW FUN_1409404f0(__int64 n);                                  // the number as text
CStringW FUN_140632a60(int nId, const CStringW& a, const CStringW& b);   // string-table text with two arguments
CStringW FUN_14052bd00(int nId, const CStringW& a);                 // string-table text with one argument
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, unsigned int n);

extern __int64 DAT_143ab28a0;                                       // current exp
extern __int64 DAT_143ab28a8;                                       // rest exp
extern unsigned int DAT_143af62d4;                                  // base height of the bar

// The mount row of the player (opaque table row): +0x6c is nonzero while riding.
struct Unk_ExpMountRow { char m_pad_00[0x6c]; int m_6c; };
class Unk_ExpMountPtr
{
public:
    ~Unk_ExpMountPtr();                                             // 0x140788ed0
    Unk_ExpMountRow* FUN_1407895d0() const;                         // operator->
    void* m_pad_00;
    Unk_ExpMountRow* m_p;
};
class Unk_ExpHolder { public: Unk_ExpMountPtr FUN_141707750(); };
class Unk_ExpHolderRef                                              // 8-byte reference to the holder
{
public:
    Unk_ExpHolderRef(Unk_ExpHolder* p);                             // 0x140963df0
    ~Unk_ExpHolderRef();                                            // 0x1409648b0
    bool operator!=(Unk_ExpHolder* p) const;                        // 0x140ba7bb0
    Unk_ExpHolder* FUN_140975bc0() const;                           // operator->
    Unk_ExpHolder* m_p;
};
class Unk_ExpActor : public PC { public: Unk_ExpHolder* FUN_1416764a0(); };
class Unk_ExpWorld { };
Unk_ExpWorld* FUN_1403ed2d0();
Unk_ExpActor* FUN_141bd0cc0(Unk_ExpWorld* pWorld);                  // the local player

// The bar clip: ASGameEntity declares only slots 0..5; slot 25 is "validateNow".
class Unk_ExpEntity : public ASGameEntity
{
public:
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24();
    virtual void vfunc_25();
    void FUN_1422c0e80(float fScale);                               // set the scale
    Scaleform::GFx::Value FUN_141932fd0(const char* szMethod, float a1, float a2, CStringW a3, unsigned int a4);
};

template <> bool MS2Ptr<AScript>::operator==(AScript* p) const;
template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);
MS2Ptr<ASGameEntity> FUN_140ba77e0(int nUiId, const Scaleform::GFx::Value& root);

// @0x141931eb0
UIExpBar::UIExpBar()
{
    m_2c = 0xf;
}

// @0x141931f30
UIExpBar::~UIExpBar()
{
}

// @0x141931f90
CString UIExpBar::GetTypeName()
{
    return "ExpBar";
}

// @0x141931fe0
void UIExpBar::vfunc_2()
{
    if (FUN_1412755a0())
        return;
    FUN_1422dbf00(0xf, 0, 0);
}

// @0x141932020
void UIExpBar::vfunc_3()
{
    if (FUN_1412755a0())
        return;
    FUN_1422dc080();
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
}

// @0x141932080
void UIExpBar::FUN_141932080(const unsigned int& nFlags)
{
    if (m_30 == 0)
        return;
    if (nFlags == 0)
        return;
    __int64 nCur = FUN_1419322a0();
    __int64 nMax = FUN_1419322e0();
    __int64 nRest = FUN_141932340();
    float fCur = (float)(nCur * 100) / (float)nMax;
    float fRest = (float)(nRest * 100) / (float)nMax;
    CStringW strText;
    if ((nFlags & 1) != 0)
        strText = FUN_14052bd00(0x98e, StringFormat(L"{0:.2f}", fCur));
    static_cast<Unk_ExpEntity*>(m_30.operator->())->FUN_141932fd0("setExp", fCur, fRest, CStringW(strText), nFlags);
}

// @0x1419322a0
__int64 UIExpBar::FUN_1419322a0()
{
    Unk_ExpActor* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    return DAT_143ab28a0;
}

// MS2-FUNCTIONAL: the exe widens the level through an extra movzx before the call.
// @0x1419322e0
__int64 UIExpBar::FUN_1419322e0()
{
    Unk_ExpActor* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    unsigned short nLevel = pPlayer->vfunc_78();
    return FUN_1404a1bb0()->FUN_140353610(nLevel);
}

// @0x141932340
__int64 UIExpBar::FUN_141932340()
{
    Unk_ExpActor* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    return DAT_143ab28a8;
}

// @0x141932380
void UIExpBar::FUN_141932380(int nVisible)
{
    if (MS2Ptr<ASMovieClip> spPoint = GetChild<ASMovieClip>("m_point"))
        spPoint->vfunc_3(nVisible);
}

// @0x141932430
void UIExpBar::FUN_141932430()
{
    int nVisible = 1;
    Unk_ExpActor* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    Unk_ExpHolderRef spHolder(pPlayer->FUN_1416764a0());
    if (spHolder != 0)
    {
        bool bMounted = spHolder.FUN_140975bc0()->FUN_141707750().FUN_1407895d0()->m_6c != 0 ? 1 : 0;
        if (bMounted)
            nVisible = 0;
    }
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
        pEntity->vfunc_3(nVisible);
}

// @0x1419325b0
void UIExpBar::vfunc_43()
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
    {
        static_cast<Unk_ExpEntity*>(pEntity.operator->())->FUN_1422c0e80((float)DAT_143af62d4 * FUN_14025e7a0()->FUN_1422afec0(m_28));
        static_cast<Unk_ExpEntity*>(pEntity.operator->())->vfunc_25();
    }
}

// @0x1419326a0
void UIExpBar::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    unsigned int nFlags = 3;
    FUN_141932080(nFlags);
    FUN_141932380(FUN_1409a8b10()->FUN_140b123b0()->m_bShowPoint);
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    FUN_141932430();
}

// @0x141932730
void UIExpBar::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (FUN_140184310(strMethod, "getExp"))
    {
        CStringW strText;
        strText = FUN_140632a60(0x769, FUN_1409404f0(FUN_1419322a0()), FUN_1409404f0(FUN_1419322e0()));
        if (0 < DAT_143ab28a8)
        {
            Unk_ExpActor* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
            if (pPlayer == 0)
                return;
            unsigned short nLevel = (unsigned short)pPlayer->vfunc_78();
            __int64 nNeed = FUN_1404a1bb0()->FUN_140353610(nLevel);
            float fPct = (float)((DAT_143ab28a0 + DAT_143ab28a8) * 100) / (float)nNeed;
            float fShow = (std::min)(100.0f, fPct);
            if (DAT_143ab28a8 != 0)
                fShow = (std::max)(0.01f, fShow);
            unsigned int nUnit = *FUN_1401d3200()->m_6b00.FUN_1401d7c10() / 100;
            strText += FUN_14028dfa0(CStringW(L"s_tooltip_rest_exp"), nLevel, fShow, nUnit);
            if (FUN_14025e7c0()->FUN_14116d720())
                strText += StringFormat(L"[{0}]", DAT_143ab28a8);
        }
        FUN_1403b4750()->FUN_1416fb340(strText);
        ASObj obj(2);
        obj.FUN_1407cbb20("text", CStringW(strText));
        *pRetVal = obj.FUN_1422bb870();
    }
}

// @0x141932b10
int UIExpBar::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnClickBar", szMethod) == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4efa);
        return 1;
    }
    return 0;
}

// @0x141932b90
void UIExpBar::vfunc_oa0_20(int a1)
{
    FUN_141932430();
}

// @0x141932bc0
void UIExpBar::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

// @0x141932fd0
Scaleform::GFx::Value Unk_ExpEntity::FUN_141932fd0(const char* szMethod, float a1, float a2, CStringW a3, unsigned int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcd70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), (const wchar_t*)a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE_METHOD(0x141931F90, UIExpBar, GetTypeName, 61, 0x38CC8AA4);
MS2_REPLACE_METHOD(0x141931FE0, UIExpBar, vfunc_2, 46, 0xA490E680);
MS2_REPLACE_METHOD(0x141932020, UIExpBar, vfunc_3, 86, 0x1EC264F5);
MS2_REPLACE_METHOD(0x141932080, UIExpBar, FUN_141932080, 535, 0xDDCE3C5D);
MS2_REPLACE_METHOD(0x1419322A0, UIExpBar, FUN_1419322a0, 51, 0x7FC928F5);
MS2_REPLACE_METHOD(0x1419322E0, UIExpBar, FUN_1419322e0, 89, 0x619D63E5);
MS2_REPLACE_METHOD(0x141932340, UIExpBar, FUN_141932340, 51, 0x43E56209);
MS2_REPLACE_METHOD(0x141932380, UIExpBar, FUN_141932380, 163, 0xE72325D6);
MS2_REPLACE_METHOD(0x141932430, UIExpBar, FUN_141932430, 363, 0xC0C8D117);
MS2_REPLACE_METHOD(0x1419325B0, UIExpBar, vfunc_43, 230, 0x39FC6097);
MS2_REPLACE_METHOD(0x1419326A0, UIExpBar, OnLoadComplete, 137, 0xB17D5AA5);
MS2_REPLACE_METHOD(0x141932730, UIExpBar, vfunc_45, 977, 0x4AF454E6);
MS2_REPLACE_METHOD(0x141932B10, UIExpBar, vfunc_28, 113, 0x94852F62);
MS2_REPLACE_METHOD(0x141932BC0, UIExpBar, vfunc_41, 99, 0x9DAE5CE0);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbdf40-0x142cbdfa0 .text$yd
