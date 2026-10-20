// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See aseffect.h.
// MS2-UNIT: ?\aseffect.cpp
// MS2-RANGE: 0x1409b2d70-0x1409b8e30 .text$mn
// MS2-RANGE: 0x1400c03c0-0x1400c06c0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??4?$MS2Ptr@VASTextField@@@@QEAAAEAV0@AEBV0@@Z 0x1409b4b80 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVASEffect@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1409b4fc0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVASEffect@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1409b5020 ; unique
// MS2-PIN: ??$Call@VASEffect@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVASEffect@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVASEffect@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1409b5050 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVASEffect@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1409b5080 ; unique
// MS2-PIN: memmove_s 0x1409b50e0 ; unique
// MS2-PIN: ??$?8V?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VASEffect@@@@@std@@@std@@@std@@V01@@std@@YA_NAEBV?$reverse_iterator@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VASEffect@@@@@std@@@std@@@std@@@0@0@Z 0x1409b6580 ; unique
// MS2-PIN: ??$?9V?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VASEffect@@@@@std@@@std@@@std@@V01@@std@@YA_NAEBV?$reverse_iterator@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VASEffect@@@@@std@@@std@@@std@@@0@0@Z 0x1409b65d0 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VASEffect@@@@QEBAPEAVASEffect@@XZ 0x1409b7070 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VASEffect@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VASEffect@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1409b76f0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??C?$MS2Ptr@VASTextField@@@@QEBAPEAVASTextField@@XZ 0x1409b4c70
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\aseffect.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <new>
#include "aseffect.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The header statics of this unit: header_statics_a.h's four, then the sort-name tables of two more headers.
static CString s_strChartSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- externals ----
extern Scaleform::GFx::Value DAT_143b0ae18;                     // the undefined value an effect clip starts from
void* FUN_1422bb8b0(int nMovieId);                              // the movie of a UI layer
void FUN_14256e8e0(void* pMovie, Scaleform::GFx::Value* pValue, const char* szClass, __int64 a, int b);   // movie->CreateObject
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);     // value is undefined
void FUN_1422c63f0(Scaleform::GFx::Value& value, int nGroup);   // unbind
void FUN_1422c6380(Scaleform::GFx::Value& value, int nGroup);   // bind
void FUN_1422bce70(Scaleform::GFx::Value*, const char*);        // Value::SetString
unsigned FUN_140869420();                                       // millisecond clock
float FUN_14028d280(unsigned);                                  // ms -> seconds
bool FUN_140930110(int nActorId);
int FUN_14123c580(void*);                                       // actor id
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1407196b0(unsigned);                               // number -> text
CStringW FUN_1406329c0(const wchar_t* pszFormat, float* pfArg); // "{0}" substitution of a float
class Unk_AsBuffInfo
{
public:
    bool FUN_140171890();               // true for a buff the player does not control (shown "none" bordered)
    bool FUN_140175290();               // no timer sweep
    CString FUN_1401756c0();            // copy of the icon path
};
MS2Ptr<ASMovieClip> FUN_1409b6610(int nMovieId, CString strClass, __int64 a1, int a2);   // new flash class object as a clip
int FUN_1409e2750(ASTooltip* pTip, Unk_AsBuffInfo* pInfo, int nOwnerLevel, unsigned nRemain);    // fill the buff tooltip

// ---- Delegate<void(const Params&)>: the out-of-line pieces (first used here) ----
typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> Unk_AsDelegate;

// @0x1409b49f0
template<> Unk_AsDelegate::DelegateImplBase::DelegateImplBase() {}

// @0x1409b4a10
template<> Unk_AsDelegate::~Delegate()
{
    if (m_pImpl)
        delete m_pImpl;
}

// @0x1409b4af0
// MS2-FUNCTIONAL: exe ~ASTooltip stores no vftable (ASTooltip own-vtable layout unknown)
ASTooltip::~ASTooltip() {}

// @0x1409b4b20
template<> Unk_AsDelegate::DelegateImplBase::~DelegateImplBase() {}

// @0x1409b2d70
ASEffect::ASEffect(MS2Ptr<Unk_AsBuff> spBuff)
    : ASMovieClip(DAT_143b0ae18, 2), m_buff(spBuff), m_94(), m_a0(), m_b0(), m_c0(), m_d0()
{
    m_e0 = 0;
    m_e4 = 0;
    m_e9 = true;
    m_e8 = m_buff->FUN_14096d7a0();
}

// @0x1409b2ec0
ASEffect::~ASEffect()
{
    if (IsLoaded())
    {
        FUN_1422c63f0(m_value, 2);
        Invoke("clearIcon");
    }
}

// @0x1409b2fb0
// MS2-FUNCTIONAL: temporary/frame layout of the child binders differs (frame 0x168 vs 0x128)
void ASEffect::BindChildren()
{
    if (!IsLoaded())
    {
        void* pMovie = FUN_1422bb8b0(m_nMovieId);
        if (pMovie != 0)
        {
            FUN_14256e8e0(pMovie, &m_value, "export_additional_effect", 0, 0);
            if (FUN_1409b0390(&m_value) == 0)
            {
                m_a0 = FUN_1409b4560(CString("m_cooldown"));
                m_b0 = FUN_1409b4560(CString("m_buffBorder"));
                m_c0 = FUN_1409b4620(CString("m_textField"));
                m_d0 = FUN_1409b4620(CString("m_textCountField"));
                FUN_1422c3180(CString("GetTooltipCallback"), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ASEffect::GetTooltip));
                FUN_1422c6380(m_value, 2);
            }
        }
    }
}

// @0x1409b3300
bool ASEffect::IsLoaded()
{
    return m_value.IsObject();
}
MS2_REPLACE_METHOD(0x1409B3300, ASEffect, IsLoaded, 31, 0x038F4D4C);

// @0x1409b3330
// MS2-FUNCTIONAL: source shape differs (frame/branch order of the cooldown sweep)
void ASEffect::Update()
{
    if (IsLoaded() && m_e8)
    {
        UpdateIcon();
        unsigned nElapsed = FUN_140869420() - m_90;
        if (nElapsed < 500)
        {
            nElapsed = nElapsed * 60;
            unsigned nFrame = nElapsed / 1000;
            if (m_a0->FUN_1422c2300() != nFrame)
                m_a0->vfunc_14(nFrame);
        }
        else
        {
            if (m_buff->m_1c != m_buff->m_20)
            {
                if (!m_buff->FUN_14096d810()->FUN_140175290())
                {
                    float fRemain = FUN_14028d280(m_buff->FUN_14096d2e0());
                    if (fRemain <= 0.0f)
                    {
                        m_e8 = false;
                        if (m_a0->FUN_1422c2300() != 0x95)
                            m_a0->vfunc_14(0x95);
                        m_c0->FUN_1422c4cd0(CStringW(L""));
                        return;
                    }
                    float fTotal = FUN_14028d280(m_buff->FUN_14096d330());
                    int nFrame = (int)(((fTotal - fRemain) * 120.0f) / fTotal + 30.0f);
                    if (m_a0->FUN_1422c2300() != nFrame)
                        m_a0->vfunc_14(nFrame);
                    if (m_94.FUN_140268870(100) == 0)
                        return;
                    m_c0->FUN_1422c4cd0(FormatRemain(fRemain));
                    return;
                }
            }
            if (m_a0->FUN_1422c2300() != 0x1e)
                m_a0->vfunc_14(0x1e);
        }
    }
}

// @0x1409b3700
void ASEffect::SetE0(int n)
{
    m_e0 = n;
}
MS2_REPLACE_METHOD(0x1409B3700, ASEffect, SetE0, 25, 0xC884F68F);

// @0x1409b3720
void ASEffect::SetE4(int n)
{
    m_e4 = n;
}
MS2_REPLACE_METHOD(0x1409B3720, ASEffect, SetE4, 25, 0x2DE8A103);

// @0x1409b3740
void ASEffect::SetBuff(MS2Ptr<Unk_AsBuff> spBuff)
{
    m_buff = spBuff;
    m_e9 = true;
    m_e8 = m_buff->FUN_14096d7a0();
}

// @0x1409b37c0
void ASEffect::SetStartTime(int nTime)
{
    m_90 = nTime;
}
MS2_REPLACE_METHOD(0x1409B37C0, ASEffect, SetStartTime, 25, 0xDF53FE3F);

// @0x1409b37e0
bool ASEffect::IsBuffType()
{
    return m_buff->FUN_14096d810()->FUN_140171890();
}
MS2_REPLACE_METHOD(0x1409B37E0, ASEffect, IsBuffType, 49, 0xE1E26C20);

// @0x1409b3820
bool ASEffect::IsTimed()
{
    return m_e8;
}
MS2_REPLACE_METHOD(0x1409B3820, ASEffect, IsTimed, 18, 0x02E7B34D);

// @0x1409b3840
bool ASEffect::IsOwnerAlive()
{
    if (m_buff == 0)
        return false;
    if (m_buff->FUN_14096d280() == 0)
        return false;
    if (FUN_140930110(FUN_14123c580(m_buff->FUN_14096d280())) == 1)
        return false;
    if (FUN_140930110(m_buff->m_18) == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1409B3840, ASEffect, IsOwnerAlive, 179, 0xC4BB8535);

// @0x1409b3900
void ASEffect::FUN_1409b3900()
{
    m_buff->FUN_14096d260();
}
MS2_REPLACE_METHOD(0x1409B3900, ASEffect, FUN_1409b3900, 41, 0x66FBE713);

// @0x1409b3930
int ASEffect::GetE4()
{
    return m_e4;
}
MS2_REPLACE_METHOD(0x1409B3930, ASEffect, GetE4, 17, 0x798679FF);

// @0x1409b3950
void ASEffect::GetTooltip(const Scaleform::GFx::FunctionHandler::Params& params)
{
    ASTooltip tip(2);
    FUN_1409e2750(&tip, m_buff->FUN_14096d810(), m_e0, m_buff->FUN_14096d2e0());
    *params.pRetVal = tip.FUN_1422bb870();
}

// @0x1409b3a20
// MS2-FUNCTIONAL: source shape differs (frame/branch order of the icon refresh)
void ASEffect::UpdateIcon()
{
    if (IsLoaded() && m_e9)
    {
        if (!m_buff->FUN_14096d810()->FUN_140171890())
        {
            if (!IsOwnerAlive())
                m_b0->vfunc_15(CString("red"));
            else
                m_b0->vfunc_15(CString("yellow"));
        }
        else
            m_b0->vfunc_15(CString("none"));

        if (m_buff->m_24 < 2)
        {
            if (m_buff->m_24 < 2)
                m_d0->FUN_1422c4cd0(CStringW(L""));
        }
        else
            m_d0->FUN_1422c4cd0(FUN_1407196b0(m_buff->m_24));
        m_c0->FUN_1422c4cd0(CStringW(L""));
        Invoke("setIcon", m_buff->FUN_14096d810()->FUN_1401756c0());
        m_e9 = false;
    }
}

// @0x1409b3d50
CStringW ASEffect::FormatRemain(float fSeconds)
{
    int n = (int)fSeconds;
    if (n >= 86400)
    {
        n = n / 86400;
        return StringFormat(L"{0}{1}", n, FUN_14028de60(0x5ce));
    }
    else if (n >= 3600)
    {
        n = n / 3600;
        return StringFormat(L"{0}{1}", n, FUN_14028de60(0x5cd));
    }
    else if (n >= 60)
    {
        n = n / 60;
        return StringFormat(L"{0}{1}", n, FUN_14028de60(0x5ca));
    }
    else if (n > 0)
    {
        return StringFormat(L"{0}{1}", n, FUN_14028de60(0x5cb));
    }
    return FUN_1406329c0(L"{0:.1f}", &fSeconds);
}

// @0x1409b40c0
MS2Ptr<ASMovieClip> FUN_1409b40c0(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASMovieClip> sp(new ASMovieClip(v, nMovieId));
    return sp;
}

// @0x1409b41a0
MS2Ptr<ASTextField> FUN_1409b41a0(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASTextField> sp(new ASTextField(v, nMovieId));
    return sp;
}

// @0x1409b4560
MS2Ptr<ASMovieClip> AScript::FUN_1409b4560(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return FUN_1409b40c0(m_nMovieId, v);
    return MS2Ptr<ASMovieClip>(0);
}

// @0x1409b4620
MS2Ptr<ASTextField> AScript::FUN_1409b4620(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return FUN_1409b41a0(m_nMovieId, v);
    return MS2Ptr<ASTextField>(0);
}

// @0x1409b46e0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CString a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1409b5200
ASEffectManager::ASEffectManager(const Scaleform::GFx::Value& v, int nMovieId)
    : ASMovieClip(v, nMovieId), m_80(), m_90(), m_a0(7), m_a4(10), m_a8(true), m_ac(0x14), m_b0(false), m_b1(false),
      m_b8(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_80 = FUN_1409b6610(m_nMovieId, CString("flash.display.MovieClip"), 0, 0);
    m_90 = FUN_1409b6610(m_nMovieId, CString("flash.display.MovieClip"), 0, 0);
    FUN_1422c6900(m_80->FUN_1422bb870());
    FUN_1422c6900(m_90->FUN_1422bb870());
}

// @0x1409b5580
ASEffectManager::~ASEffectManager()
{
}

// @0x1409b5610
void ASEffectManager::Update()
{
    for (POSITION pos = m_b8.GetStartPosition(); pos != 0; m_b8.GetNext(pos))
    {
        MS2Ptr<ASEffect> spEffect = m_b8.GetValueAt(pos);
        if (!spEffect->IsLoaded())
            Attach(spEffect);
        if (!spEffect->IsTimed())
            continue;
        spEffect->Update();
        if (!spEffect->IsTimed())
            m_a8 = true;
    }
    if (m_a8)
    {
        Layout(m_100, false);
        Layout(m_110, m_b1);
        m_a8 = false;
    }
}

// @0x1409b57b0
void ASEffectManager::SetPosA(int x, int y)
{
    if (m_80.get() != 0)
        m_80->FUN_1422bffe0(x, y);
}
MS2_REPLACE_METHOD(0x1409B57B0, ASEffectManager, SetPosA, 83, 0xD504B5F3);

// @0x1409b5810
void ASEffectManager::SetPosB(int x, int y)
{
    if (m_90.get() != 0)
        m_90->FUN_1422bffe0(x, y);
}
MS2_REPLACE_METHOD(0x1409B5810, ASEffectManager, SetPosB, 83, 0xD8F076D3);

// @0x1409b5870
void ASEffectManager::SetE0(int n)
{
    m_a0 = n;
}
MS2_REPLACE_METHOD(0x1409B5870, ASEffectManager, SetE0, 25, 0x9EB3CF4F);

// @0x1409b5890
void ASEffectManager::SetMax(int n)
{
    m_a4 = n;
}
MS2_REPLACE_METHOD(0x1409B5890, ASEffectManager, SetMax, 25, 0x041453C3);

// @0x1409b58b0
void ASEffectManager::SetColumns(int n)
{
    m_ac = n;
}
MS2_REPLACE_METHOD(0x1409B58B0, ASEffectManager, SetColumns, 25, 0x395024DB);

// @0x1409b58d0
void ASEffectManager::SetUp(bool b)
{
    m_b0 = b;
}
MS2_REPLACE_METHOD(0x1409B58D0, ASEffectManager, SetUp, 26, 0x7B86FC45);

// @0x1409b58f0
void ASEffectManager::SetFilter(bool b)
{
    if (m_b1 == b)
        return;
    m_a8 = true;
    m_b1 = b;
}
MS2_REPLACE_METHOD(0x1409B58F0, ASEffectManager, SetFilter, 61, 0xDE8229EC);

// @0x1409b5940
void ASEffectManager::AddEffect(MS2Ptr<Unk_AsBuff> spBuff)
{
    MS2Ptr<ASEffect> spEffect(new ASEffect(spBuff));
    spEffect->SetE0(m_a0);
    spEffect->SetStartTime(FUN_140869420());
    spEffect->SetE4(spBuff->FUN_14096d350());
    m_b8.SetAt(spBuff->FUN_14096d260(), spEffect);
}

// @0x1409b5aa0
void ASEffectManager::UpdateEffect(MS2Ptr<Unk_AsBuff> spBuff)
{
    MS2Ptr<ASEffect> spEffect;
    if (m_b8.Lookup(spBuff->FUN_14096d260(), spEffect))
        spEffect->SetBuff(spBuff);
    m_a8 = true;
}

// @0x1409b5b60
void ASEffectManager::RemoveEffect(int nBuffId)
{
    MS2Ptr<ASEffect> spEffect;
    if (m_b8.Lookup(nBuffId, spEffect))
    {
        if (spEffect->IsLoaded())
            Detach(spEffect);
        m_b8.RemoveKey(nBuffId);
    }
}

// @0x1409b5c20
void ASEffectManager::Clear()
{
    ATL::CAtlArray<int> ids;
    for (POSITION pos = m_b8.GetStartPosition(); pos != 0; m_b8.GetNext(pos))
    {
        int nId = m_b8.GetKeyAt(pos);
        ids.Add(nId);
    }
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        int nId = ids[i];
        RemoveEffect(nId);
    }
}

// @0x1409b5d10
void ASEffectManager::InsertSorted(std::list<MS2Ptr<ASEffect> >& list, MS2Ptr<ASEffect> spEffect)
{
    std::list<MS2Ptr<ASEffect> >::reverse_iterator it = list.rbegin();
    for (; it != list.rend(); it++)
    {
        MS2Ptr<ASEffect> spCur = *it;
        if (spCur->GetE4() >= spEffect->GetE4())
            break;
    }
    list.insert(it.base(), spEffect);
}

// @0x1409b5e30
void ASEffectManager::Remove(std::list<MS2Ptr<ASEffect> >& list, MS2Ptr<ASEffect> spEffect)
{
    for (std::list<MS2Ptr<ASEffect> >::iterator it = list.begin(); it != list.end(); it++)
    {
        if (*it == spEffect.get())
        {
            list.erase(it);
            return;
        }
    }
}

// @0x1409b5f10
void ASEffectManager::Layout(std::list<MS2Ptr<ASEffect> >& list, bool bFilter)
{
    int nShown = 0;
    for (std::list<MS2Ptr<ASEffect> >::iterator it = list.begin(); it != list.end(); it++)
    {
        MS2Ptr<ASEffect> spEffect = *it;
        if (spEffect == 0)
            continue;
        if (!spEffect->IsTimed())
        {
            spEffect->vfunc_3(0);
            continue;
        }
        if (bFilter && !spEffect->IsOwnerAlive())
        {
            spEffect->vfunc_3(0);
            continue;
        }
        if (nShown < m_a4)
        {
            int nCol = nShown % m_ac;
            int nRow = nShown / m_ac;
            int x = nCol * 0x2a;
            int y = nRow * 0x2a;
            if (m_b0)
                y = nRow * -0x2a;
            spEffect->vfunc_3(1);
            spEffect->FUN_1422bffe0(x, y);
            nShown++;
        }
        else
            spEffect->vfunc_3(0);
    }
}

// @0x1409b6170
void ASEffectManager::Attach(MS2Ptr<ASEffect> spEffect)
{
    spEffect->BindChildren();
    if (spEffect->IsBuffType())
    {
        m_80->FUN_1422c6900(spEffect->FUN_1422bb870());
        InsertSorted(m_100, spEffect);
    }
    else
    {
        m_90->FUN_1422c6900(spEffect->FUN_1422bb870());
        InsertSorted(m_110, spEffect);
    }
    m_a8 = true;
}

// @0x1409b6370
void ASEffectManager::Detach(MS2Ptr<ASEffect> spEffect)
{
    if (spEffect->IsBuffType())
    {
        m_80->FUN_1422c6b70(spEffect->FUN_1422bb870());
        Remove(m_100, spEffect);
    }
    else
    {
        m_90->FUN_1422c6b70(spEffect->FUN_1422bb870());
        Remove(m_110, spEffect);
    }
    m_a8 = true;
}

// @0x1409b6610
MS2Ptr<ASMovieClip> FUN_1409b6610(int nMovieId, CString strClass, __int64 a1, int a2)
{
    void* pMovie = FUN_1422bb8b0(nMovieId);
    if (pMovie == 0)
        return MS2Ptr<ASMovieClip>(0);
    Scaleform::GFx::Value v;
    FUN_14256e8e0(pMovie, &v, strClass, a1, a2);
    if (FUN_1409b0390(&v) != 0)
        return MS2Ptr<ASMovieClip>(0);
    MS2Ptr<ASMovieClip> sp(new ASMovieClip(v, nMovieId));
    return sp;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9d9b0-0x142c9daa0 .text$yd
