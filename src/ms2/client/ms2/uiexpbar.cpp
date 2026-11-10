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
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/commonfiles/exptable.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cgameoption.h"
#include <string.h>
#include <algorithm>
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include "ms2/placeholder/crideedata.h"

// ---- unit-local views of exe objects ----

class Unk_ExpCfg
{
public:
};
class Unk_ExpGlobals
{
public:
    char m_pad_0000[0x6b00];
    Unk_ExpCfg m_6b00;
};
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())

struct Unk_ExpCfgData { char m_pad_00[8]; unsigned char m_bShowPoint; };
// FUN_14025e7a0 (the GFxManager singleton, 0x14025e7a0) is declared in gfxmanager.h
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
void* GetExpTable();   // C3: was GetExpTable
int FUN_1412755a0();
CStringW FUN_1409404f0(__int64 n);                                  // the number as text
template <class A, class B> CStringW FormatStringId(int nId, const A& a, const B& b);   // string-table text with two arguments
template <class A> CStringW FormatStringId(int nId, const A& a);                 // string-table text with one argument
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

extern __int64 DAT_143ab28a0;                                       // current exp
extern __int64 DAT_143ab28a8;                                       // rest exp
extern unsigned int DAT_143af62d4;                                  // base height of the bar

class Unk_ExpActor : public PC { };
class Ridee : public PCBase { public: MS2SvrPtr<CRideeData> GetData(); };   // C3: member view
class Unk_ExpWorld { };

// The bar clip: ASGameEntity declares only slots 0..5; slot 25 is "validateNow".
class Unk_ExpEntity : public ASGameEntity
{
public:
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24();
    virtual void vfunc_25();
    Scaleform::GFx::Value Invoke(const char* szMethod, float a1, float a2, CStringW a3, unsigned int a4);
};

template <> bool MS2Ptr<AScript>::operator==(AScript* p) const;
template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);
MS2Ptr<ASGameEntity> CreateGameEntity(int nUiId, const Scaleform::GFx::Value& root);

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
    LoadSwf(0xf, 0, 0);
}

// @0x141932020
void UIExpBar::vfunc_3()
{
    if (FUN_1412755a0())
        return;
    FUN_1422dc080();
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
}

// @0x141932080
void UIExpBar::UpdateExp(const unsigned int& nFlags)
{
    if (m_30 == 0)
        return;
    if (nFlags == 0)
        return;
    __int64 nCur = GetCurrentExp();
    __int64 nMax = GetNextLevelExp();
    __int64 nRest = GetRestExp();
    float fCur = (float)(nCur * 100) / (float)nMax;
    float fRest = (float)(nRest * 100) / (float)nMax;
    CStringW strText;
    if ((nFlags & 1) != 0)
        strText = FormatStringId<CStringW>(0x98e, StringFormat(L"{0:.2f}", fCur));
    static_cast<Unk_ExpEntity*>(m_30.operator->())->Invoke("setExp", fCur, fRest, CStringW(strText), nFlags);
}

// @0x1419322a0
__int64 UIExpBar::GetCurrentExp()
{
    Unk_ExpActor* pPlayer = ((class Unk_ExpActor*)((class WorldService*)(class Unk_ExpWorld*)(reinterpret_cast<Unk_ExpWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    return DAT_143ab28a0;
}

// The level return is passed inline, which gives the exe its extra movzx.
// @0x1419322e0
__int64 UIExpBar::GetNextLevelExp()
{
    Unk_ExpActor* pPlayer = ((class Unk_ExpActor*)((class WorldService*)(class Unk_ExpWorld*)(reinterpret_cast<Unk_ExpWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;

    return ((class CExpTable*)GetExpTable())->GetNextExp(pPlayer->vfunc_78());
}

// @0x141932340
__int64 UIExpBar::GetRestExp()
{
    Unk_ExpActor* pPlayer = ((class Unk_ExpActor*)((class WorldService*)(class Unk_ExpWorld*)(reinterpret_cast<Unk_ExpWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    return DAT_143ab28a8;
}

// @0x141932380
void UIExpBar::SetPointVisible(int nVisible)
{
    if (MS2Ptr<ASMovieClip> spPoint = GetChild<ASMovieClip>("m_point"))
        spPoint->vfunc_3(nVisible);
}

// @0x141932430
void UIExpBar::FUN_141932430()
{
    int nVisible = 1;
    Unk_ExpActor* pPlayer = ((class Unk_ExpActor*)((class WorldService*)(class Unk_ExpWorld*)(reinterpret_cast<Unk_ExpWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    efd::SmartPointer<Ridee> spHolder(reinterpret_cast<Ridee*>(pPlayer->GetRidee()));
    if (spHolder != (Ridee*)0)
    {
        bool bMounted = spHolder->GetData()->m_basic.m_nHidePCInfo != 0 ? 1 : 0;
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
        reinterpret_cast<ASDisplayObject*>(pEntity.operator->())->SetWidthFloat((float)DAT_143af62d4 * GetGFxManager()->GetMovieScale(m_28));
        static_cast<Unk_ExpEntity*>(pEntity.operator->())->vfunc_25();
    }
}

// @0x1419326a0
void UIExpBar::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    unsigned int nFlags = 3;
    UpdateExp(nFlags);
    SetPointVisible(reinterpret_cast<Unk_ExpCfgData*>(TSingleton<CGameOption>::GetInstance()->GetStatus())->m_bShowPoint);
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    FUN_141932430();
}

// @0x141932730
void UIExpBar::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if ((strMethod == "getExp"))
    {
        CStringW strText;
        strText = FormatStringId<CStringW, CStringW>(0x769, FUN_1409404f0(GetCurrentExp()), FUN_1409404f0(GetNextLevelExp()));
        if (0 < DAT_143ab28a8)
        {
            Unk_ExpActor* pPlayer = ((class Unk_ExpActor*)((class WorldService*)(class Unk_ExpWorld*)(reinterpret_cast<Unk_ExpWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
            if (pPlayer == 0)
                return;
            unsigned short nLevel = (unsigned short)pPlayer->vfunc_78();
            __int64 nNeed = ((class CExpTable*)GetExpTable())->GetNextExp(nLevel);
            float fPct = (float)((DAT_143ab28a0 + DAT_143ab28a8) * 100) / (float)nNeed;
            float fShow = (std::min)(100.0f, fPct);
            if (DAT_143ab28a8 != 0)
                fShow = (std::max)(0.01f, fShow);
            unsigned int nUnit = *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_ExpGlobals*)GetClientConstants())->m_6b00)->Get() / 100;
            strText += FUN_14028dfa0(CStringW(L"s_tooltip_rest_exp"), nLevel, fShow, nUnit);
            if (((class CInputKeyHandler*)FUN_14025e7c0())->IsDebugMode())
                strText += StringFormat(L"[{0}]", DAT_143ab28a8);
        }
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strText);
        ASObj obj(2);
        obj.SetWStringMember("text", CStringW(strText));
        *pRetVal = obj.GetValue();
    }
}

// @0x141932b10
int UIExpBar::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnClickBar", szMethod) == 0)
    {
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4efa)));
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
    m_30 = CreateGameEntity(m_28, root);
}

// @0x141932fd0
Scaleform::GFx::Value Unk_ExpEntity::Invoke(const char* szMethod, float a1, float a2, CStringW a3, unsigned int a4)
{
    ASArgList args;
    args.resize(4);
    FUN_1422bcd70(&args[0], a1);
    FUN_1422bcd70(&args[1], a2);
    FUN_1422bcea0(&args[2], (const wchar_t*)a3);
    FUN_1422bccb0(&args[3], a4);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE_METHOD(0x141931F90, UIExpBar, GetTypeName, 61, 0x38CC8AA4);
MS2_REPLACE_METHOD(0x141931FE0, UIExpBar, vfunc_2, 46, 0xA490E680);
MS2_REPLACE_METHOD(0x141932020, UIExpBar, vfunc_3, 86, 0x1EC264F5);
MS2_REPLACE_METHOD(0x141932080, UIExpBar, UpdateExp, 535, 0xDDCE3C5D);
MS2_REPLACE_METHOD(0x1419322A0, UIExpBar, GetCurrentExp, 51, 0x7FC928F5);
MS2_REPLACE_METHOD(0x1419322E0, UIExpBar, GetNextLevelExp, 89, 0x619D63E5);
MS2_REPLACE_METHOD(0x141932340, UIExpBar, GetRestExp, 51, 0x43E56209);
MS2_REPLACE_METHOD(0x141932380, UIExpBar, SetPointVisible, 163, 0xE72325D6);
MS2_REPLACE_METHOD(0x141932430, UIExpBar, FUN_141932430, 363, 0xC0C8D117);
MS2_REPLACE_METHOD(0x1419325B0, UIExpBar, vfunc_43, 230, 0x39FC6097);
MS2_REPLACE_METHOD(0x1419326A0, UIExpBar, OnLoadComplete, 137, 0xB17D5AA5);
MS2_REPLACE_METHOD(0x141932730, UIExpBar, vfunc_45, 977, 0x4AF454E6);
MS2_REPLACE_METHOD(0x141932B10, UIExpBar, vfunc_28, 113, 0x94852F62);
MS2_REPLACE_METHOD(0x141932BC0, UIExpBar, vfunc_41, 99, 0x9DAE5CE0);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbdf40-0x142cbdfa0 .text$yd
