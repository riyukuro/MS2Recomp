// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIAdventureLevelExpBar.
// MS2-UNIT: unit_140ba6b20
// MS2-RANGE: 0x140ba6b20-0x140ba7d90 .text$mn
// MS2-RANGE: 0x1400c9a30-0x1400c9ba0 .text$di
// MS2-FUNCTIONAL: 6cf0 is behaviour-equivalent; the exe loads nLevel into ecx for the setPoint max-level compare (cmp ecx,eax vs our cmp [mem],eax).
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIAdventureLevelExpBar@@UEAAHXZ 0x140ba7c70 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_140ba6b20.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>

// ---- unit-local views of exe objects ----

// The settings singleton (FUN_1401d3200): the exp-per-level value at +0x91e8 and the level cap at +0x9298.
class Unk_AdvCfgExp
{
public:
    unsigned int* FUN_1401d7c10();                                  // the value
    __int64 FUN_140ba77c0();                                        // the value, widened
};
class Unk_AdvCfgLevel
{
public:
    unsigned short FUN_140ba4b30();
};
class Unk_AdvGlobals
{
public:
    char m_pad_0000[0x91e8];
    Unk_AdvCfgExp m_91e8;
    char m_pad_91e9[0x9298 - 0x91e9];
    Unk_AdvCfgLevel m_9298;
};
Unk_AdvGlobals* FUN_1401d3200();

class Unk_AdvFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_AdvFeatures* FUN_140166410();
class Unk_AdvStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);           // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);           // unregister
};
Unk_AdvStatusMgr* FUN_140aa6d40();
class Unk_AdvUIMgr { public: void FUN_141adc750(int nUiId); };      // opens a ui
Unk_AdvUIMgr* FUN_1403ed2b0();
struct Unk_AdvCfgData { char m_pad_00[8]; unsigned char m_bShowPoint; };
class Unk_AdvCfg { public: Unk_AdvCfgData* FUN_140b123b0(); };
Unk_AdvCfg* FUN_1409a8b10();
class Unk_AdvUiScale { public: float FUN_1422afec0(int nUiId); };
Unk_AdvUiScale* FUN_14025e7a0();
class Unk_AdvTextFilter { public: void FUN_1416fb340(CStringW& strText); };
Unk_AdvTextFilter* FUN_1403b4750();
int FUN_1412755a0();
int FUN_1418dd0c0();                                                // height of the exp bar
bool FUN_140184310(const CString& str, const char* psz);            // str == psz
CStringW FUN_1409404f0(__int64 n);                                  // the number as text
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);   // string-table text with two arguments
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);

extern __int64 DAT_143ab2958;                                       // current exp
extern unsigned int DAT_143ab2960;                                  // adventure level threshold
extern __int64 DAT_143ab2968;
extern unsigned int DAT_143af62d4;                                  // base height of the bar

// The mount row of the player (opaque table row): +0x6c is nonzero while riding.
struct Unk_AdvMountRow { char m_pad_00[0x6c]; int m_6c; };
class Unk_AdvMountPtr
{
public:
    ~Unk_AdvMountPtr();                                             // 0x140788ed0
    Unk_AdvMountRow* FUN_1407895d0() const;                         // operator->
    void* m_pad_00;
    Unk_AdvMountRow* m_p;
};
class Unk_AdvHolder { public: Unk_AdvMountPtr FUN_141707750(); };
class Unk_AdvHolderRef                                              // 8-byte reference to the holder
{
public:
    Unk_AdvHolderRef(Unk_AdvHolder* p);                             // 0x140963df0
    ~Unk_AdvHolderRef();                                            // 0x1409648b0
    bool operator!=(Unk_AdvHolder* p) const;                        // 0x140ba7bb0
    Unk_AdvHolder* FUN_140975bc0() const;                           // operator->
    Unk_AdvHolder* m_p;
};
class Unk_AdvActor : public PC { public: Unk_AdvHolder* FUN_1416764a0(); };
class Unk_AdvWorld { };
Unk_AdvWorld* FUN_1403ed2d0();
Unk_AdvActor* FUN_141bd0cc0(Unk_AdvWorld* pWorld);                  // the local player

// The bar clip: ASGameEntity declares only slots 0..5; slot 25 is "validateNow".
class Unk_AdvEntity : public ASGameEntity
{
public:
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24();
    virtual void vfunc_25();
    void FUN_1422c0e80(float fScale);                               // set the scale
    Scaleform::GFx::Value FUN_140ba79c0(const char* szMethod, float a1, float a2, CStringW a3, bool a4);
};

// The null tests of m_30 / the holder come from other units.
template <> bool MS2Ptr<AScript>::operator==(AScript* p) const;
template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);
MS2Ptr<ASGameEntity> FUN_140ba77e0(int nUiId, const Scaleform::GFx::Value& root);
struct Unk_AdvPtrView { void* m_pad_00; void* m_p; };

// @0x140ba6b20
UIAdventureLevelExpBar::UIAdventureLevelExpBar()
{
    m_2c = 0x10;
}

// @0x140ba6ba0
UIAdventureLevelExpBar::~UIAdventureLevelExpBar()
{
}

// @0x140ba6c00
CString UIAdventureLevelExpBar::vfunc_1()
{
    return "AdventureLevelExpBar";
}

// @0x140ba6c50
void UIAdventureLevelExpBar::vfunc_2()
{
    if (FUN_1412755a0())
        return;
    FUN_1422dbf00(0x10, 0, 0);
}

// @0x140ba6c90
void UIAdventureLevelExpBar::vfunc_3()
{
    if (FUN_1412755a0())
        return;
    FUN_1422dc080();
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
}

// @0x140ba6cf0
void UIAdventureLevelExpBar::FUN_140ba6cf0(__int64 nGain)
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity == 0)
        return;
    Unk_AdvActor* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    float fCur = (float)(FUN_140ba6fa0() * 100) / (float)FUN_140ba6fc0();
    float fNext = (float)(FUN_140ba6ff0() * 100) / (float)FUN_140ba6fc0();
    if (nGain < 0)
        nGain = 0;
    if (nGain > FUN_140ba6fc0() - FUN_140ba6fa0())
        nGain = FUN_140ba6fc0() - FUN_140ba6fa0();
    int nLevel = (unsigned short)pPlayer->vfunc_78();
    static_cast<Unk_AdvEntity*>(pEntity.operator->())->FUN_140ba79c0("setPoint", fCur, fNext, StringFormat(L"0", nGain), nLevel >= FUN_1401d3200()->m_9298.FUN_140ba4b30());
}

// @0x140ba6fa0
__int64 UIAdventureLevelExpBar::FUN_140ba6fa0()
{
    return DAT_143ab2958;
}

// @0x140ba6fc0
__int64 UIAdventureLevelExpBar::FUN_140ba6fc0()
{
    return FUN_1401d3200()->m_91e8.FUN_140ba77c0();
}

// @0x140ba6ff0
__int64 UIAdventureLevelExpBar::FUN_140ba6ff0()
{
    Unk_AdvActor* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    if ((unsigned int)pPlayer->vfunc_141() <= DAT_143ab2960)
        return FUN_140ba6fc0();
    if (pPlayer->vfunc_141() == (int)(DAT_143ab2960 + 1))
        return DAT_143ab2968;
    return 0;
}

// @0x140ba7080
void UIAdventureLevelExpBar::FUN_140ba7080(int nVisible)
{
    if (MS2Ptr<ASMovieClip> spPoint = GetChild<ASMovieClip>("m_point"))
        spPoint->vfunc_3(nVisible);
}

// @0x140ba7130
void UIAdventureLevelExpBar::FUN_140ba7130()
{
    int nVisible = 1;
    Unk_AdvActor* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    Unk_AdvHolderRef spHolder(pPlayer->FUN_1416764a0());
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

// @0x140ba72b0
void UIAdventureLevelExpBar::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    if (FUN_140166410()->FUN_14036d570(0xbd) == false)
    {
        vfunc_3();
    }
    else
    {
        FUN_140ba6cf0(0);
        FUN_140ba7080(FUN_1409a8b10()->FUN_140b123b0()->m_bShowPoint);
        FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
        FUN_140ba7130();
    }
}

// @0x140ba7360
void UIAdventureLevelExpBar::vfunc_43()
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
    {
        static_cast<Unk_AdvEntity*>(pEntity.operator->())->FUN_1422c0e80((float)DAT_143af62d4 * FUN_14025e7a0()->FUN_1422afec0(m_28));
        pEntity->Invoke("setExpBarHeight", (unsigned int)FUN_1418dd0c0());
        static_cast<Unk_AdvEntity*>(pEntity.operator->())->vfunc_25();
    }
}

// @0x140ba74a0
void UIAdventureLevelExpBar::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (FUN_140184310(strMethod, "getExp"))
    {
        CStringW strText = FUN_1408f71a0(L"s_tooltip_adventure_exp", FUN_1409404f0(FUN_140ba6fa0()), FUN_1409404f0(FUN_140ba6fc0()));
        FUN_1403b4750()->FUN_1416fb340(strText);
        ASObj obj(2);
        obj.FUN_1407cbb20("text", CStringW(strText));
        *pRetVal = obj.FUN_1422bb870();
    }
}

// @0x140ba7630
void UIAdventureLevelExpBar::vfunc_oa0_20(int a1)
{
    FUN_140ba7130();
}

// @0x140ba7660
int UIAdventureLevelExpBar::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnClickBar", szMethod) == 0)
    {
        if (FUN_140166410()->FUN_14036d570(0xfb))
            FUN_1403ed2b0()->FUN_141adc750(0x4f67);
        else
            FUN_1403ed2b0()->FUN_141adc750(0x4f87);
        return 1;
    }
    return 0;
}

// @0x140ba7710
void UIAdventureLevelExpBar::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

// @0x140ba77c0
__int64 Unk_AdvCfgExp::FUN_140ba77c0()
{
    return *FUN_1401d7c10();
}

// @0x140ba77e0
MS2Ptr<ASGameEntity> FUN_140ba77e0(int nUiId, const Scaleform::GFx::Value& root)
{
    MS2Ptr<ASGameEntity> pEntity(new ASGameEntity(root, nUiId));
    return pEntity;
}

// @0x140ba7ae0
MS2Ptr<ASGameEntity>& FUN_140ba7ae0(MS2Ptr<ASGameEntity>& kDst, MS2Ptr<ASGameEntity>& kSrc)
{
    reinterpret_cast<Unk_AdvPtrView&>(kDst).m_p = reinterpret_cast<Unk_AdvPtrView&>(kSrc).m_p;
    reinterpret_cast<Unk_AdvPtrView&>(kSrc).m_p = 0;
    return kDst;
}

// @0x140ba7930
template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<ASMovieClip>(0);
    return m_30->FUN_1409b4560(strName);
}

// @0x140ba79c0
Scaleform::GFx::Value Unk_AdvEntity::FUN_140ba79c0(const char* szMethod, float a1, float a2, CStringW a3, bool a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcd70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), (const wchar_t*)a3);
    FUN_1422bcce0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ba7bb0
bool Unk_AdvHolderRef::operator!=(Unk_AdvHolder* p) const
{
    return m_p != p;
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE_METHOD(0x140BA6C00, UIAdventureLevelExpBar, vfunc_1, 61, 0x03DBAB78);
MS2_REPLACE_METHOD(0x140BA6C50, UIAdventureLevelExpBar, vfunc_2, 46, 0x50B56EF6);
MS2_REPLACE_METHOD(0x140BA6C90, UIAdventureLevelExpBar, vfunc_3, 86, 0x5CC41CD8);
MS2_REPLACE_METHOD(0x140BA6CF0, UIAdventureLevelExpBar, FUN_140ba6cf0, 667, 0x4F7A655A);
MS2_REPLACE_METHOD(0x140BA6FA0, UIAdventureLevelExpBar, FUN_140ba6fa0, 13, 0x31C12830);
MS2_REPLACE_METHOD(0x140BA6FC0, UIAdventureLevelExpBar, FUN_140ba6fc0, 33, 0xD9472748);
MS2_REPLACE_METHOD(0x140BA6FF0, UIAdventureLevelExpBar, FUN_140ba6ff0, 125, 0x8CB7B8DE);
MS2_REPLACE_METHOD(0x140BA7080, UIAdventureLevelExpBar, FUN_140ba7080, 163, 0x8CCBB6DC);
MS2_REPLACE_METHOD(0x140BA7130, UIAdventureLevelExpBar, FUN_140ba7130, 363, 0xBB4BD534);
MS2_REPLACE_METHOD(0x140BA72B0, UIAdventureLevelExpBar, OnLoadComplete, 169, 0x23076E24);
MS2_REPLACE_METHOD(0x140BA7360, UIAdventureLevelExpBar, vfunc_43, 302, 0x59D7B96F);
MS2_REPLACE_METHOD(0x140BA74A0, UIAdventureLevelExpBar, vfunc_45, 393, 0xC541FAD8);
MS2_REPLACE_METHOD(0x140BA7660, UIAdventureLevelExpBar, vfunc_28, 158, 0x9E0791F5);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca1560-0x142ca15f0 .text$yd
