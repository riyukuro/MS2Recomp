// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxMovieDamage, the GFx movie of the damage numbers: see
// gfxmoviedamage.h. w541.
// MS2-UNIT: ?\gfxmoviedamage.cpp
// MS2-RANGE: 0x140b60ff0-0x140b64c30 .text$mn
// MS2-RANGE: 0x1400c81c0-0x1400c8430 .text$di
// MS2-RANGE: 0x142ca0bd0-0x142ca0cc0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_2@GFxMovieDamage@@UEAAPEAXXZ 0x140b634b0 ; unique
// MS2-PINS-END tplpin
//
// The unit name is assumed (no __FILE__ string); the directory follows work/map/units.tsv (client\ms2).
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "gfxmoviedamage.h"
#include "uidamagetext.h"
#include "uiservice.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/uidamagefont.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asmoviecliploader.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- file statics (.text$di) ----
// The ids of the loaded fonts, saved by FUN_140b622b0 (vfunc_11) and reloaded by FUN_140b621a0 (mutable: the functions
// that read it are not hooked).
static ATL::CAtlArray<unsigned> s_arrSavedFontIds;                                  // 0x143abb070 @0x1400c81c0
const NiRTTI GFxMovieDamage::ms_RTTI("GFxMovieDamage", &GFxMovieEventHandler::ms_RTTI);   // 0x143abb060 @0x1400c81f0
#ifndef MS2_HOOK_DLL
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/gfxmoviedamage_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
// A second "skill"/"stun" pair and null handle after the condition (another included header).
static CString s_strSkill2 = "skill";                                               // 0x143abb140
static CString s_strStun2 = "stun";                                                 // 0x143abb138
static Unk_Handle1401cd100 s_dat_143abb130(0);                                      // @0x1400c8410
#endif

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
unsigned int FUN_1407181d0(const CString& s);                       // the font id of a font name
CString FUN_140719210(long n);                                      // number text
__int64 FUN_140869440();                                            // the current server time
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);                 // the value is set

class Unk_DmgGFxUIManager
{
public:
    void FUN_1422b0790(int nMovieId);
};
Unk_DmgGFxUIManager* FUN_14025e7a0();

class Unk_DmgSceneManager
{
public:
    int FUN_1422b9dc0();                                            // the current scene id
};
Unk_DmgSceneManager* FUN_1408e57f0();

// The UISwfEntityManager slots the movie calls (vftable 0x143112518; see gfxmoviepostdisplay.cpp). The swf key and the AS
// root object are taken by value (the callee destroys them).
class Unk_DmgSwfEntityManagerSlots
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(CString strKey, Scaleform::GFx::Value vRoot);              // 0x1422d2870 swf "loadInit"
    virtual void vfunc_8(CString strKey, Scaleform::GFx::Value vRoot);
    virtual void vfunc_9(CString strKey, Scaleform::GFx::Value vRoot, float fTime); // 0x1422d2a30 swf "loadComplete"
};

extern UISwfEntityManager* DAT_143abb058;                          // the UISwfEntityManager instance

// ---- COMDAT helpers of this unit ----
// @0x140b632f0 the UISwfEntityManager instance (inline getter)
UISwfEntityManager* FUN_140b632f0()
{
    return DAT_143abb058;
}

// @0x140b62550 the text of a font id
CString FUN_140b62550(unsigned nId)
{
    return FUN_140719210(nId);
}

// @0x140b624b0 the open UI object of a ui id cast to T (COMDAT per T)
template <class T> T* Unk_DmgFindUI(int nId)
{
    if (CUIService::GetInstance())
    {
        MS2Ptr<UIObject> p = CUIService::GetInstance()->FUN_141adcea0((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// @0x140b62400
MS2Ptr<ASStage> FUN_140b62400(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASStage> sp(new ASStage(v, nMovieId));
    return sp;
}

// @0x140b62350
MS2Ptr<ASMovieClipLoader> FUN_140b62350(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASMovieClipLoader> sp(new ASMovieClipLoader(v, nMovieId));
    return sp;
}

// @0x140b60ff0
GFxMovieDamage::GFxMovieDamage()
{
    m_18 = 1;
    FUN_1422be380(0);
}

// @0x140b610f0
GFxMovieDamage::~GFxMovieDamage()
{
    vfunc_11();
}

// @0x140b61190
void GFxMovieDamage::vfunc_11()
{
    FUN_140b622b0();
    m_90.RemoveAll();
    m_d8.RemoveAll();
    m_128 = 0;
    m_120.Empty();
}

// @0x140b61200
void GFxMovieDamage::vfunc_4(void* pMovie, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (nArgs < 1)
        return;
    GFxMovie::vfunc_4(pMovie, szEvent, pArgs, nArgs);
    if (_stricmp("initializeClass", szEvent) == 0)
    {
        if (nArgs > 1)
        {
            Scaleform::GFx::Value vStage(pArgs[0]);
            Scaleform::GFx::Value vLoader(pArgs[1]);
            Scaleform::GFx::Value vThird(pArgs[2]);
            FUN_1422be510(FUN_140b62400(m_18, vStage));
            FUN_1422be5b0(FUN_140b62350(m_18, vLoader));
            FUN_14025e7a0()->FUN_1422b0790(m_18);
        }
        m_128.AssignRaw(Unk_DmgFindUI<UIDamageText>(0x4e32));
        FUN_140b62270();
    }
    else
    {
        const char* szName = pArgs[0].GetString();
        if (_stricmp("loadInit", szName) == 0)
        {
            Scaleform::GFx::Value vRoot(pArgs[1]);
            if (FUN_1409b4d40(vRoot))
                ((Unk_DmgSwfEntityManagerSlots*)FUN_140b632f0())->vfunc_7(szEvent, vRoot);
        }
        else if (_stricmp("loadComplete", szName) == 0)
        {
            Scaleform::GFx::Value vRoot(pArgs[1]);
            if (FUN_1409b4d40(vRoot))
                ((Unk_DmgSwfEntityManagerSlots*)FUN_140b632f0())->vfunc_9(szEvent, vRoot, 0.0f);
            if (m_128.get())
            {
                MS2Ptr<AScript> spRoot = m_128->FUN_1422dba00();
                if (spRoot.get() && szEvent != m_120)
                {
                    MS2Ptr<UIDamageFont> spFont(dynamic_cast<UIDamageFont*>(FUN_140b632f0()->GetUISwfEntity(szEvent).get()));
                    if (spFont.get())
                        m_128->FUN_1419134a0(spFont->m_strName);
                    else
                        FUN_140b621a0();
                }
            }
        }
    }
}

// @0x140b617d0
int GFxMovieDamage::vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam)
{
    return 0;
}

// @0x140b617f0
void GFxMovieDamage::vfunc_8(float fTime)
{
    GFxMovie::vfunc_8(fTime);
    if (!m_d8.IsEmpty())
    {
        POSITION pos = m_d8.GetStartPosition();
        if (pos)
        {
            MS2Ptr<UIDamageFont> spFont = m_d8.GetValueAt(pos);
            if (spFont.get())
                spFont->FUN_1422dbd70(spFont->FUN_1422db750(), 1);
            m_d8.RemoveAtPos(pos);
        }
    }
}

// @0x140b61900
bool GFxMovieDamage::FUN_140b61900(const CString& strFont)
{
    if (m_128 == 0 || !m_128->FUN_1422dc430())
        return false;
    unsigned nId = FUN_1407181d0(strFont);
    if (nId == 0)
        return false;
    MS2Ptr<UIDamageFont> spFont(0);
    if (m_90.Lookup(nId, spFont))
    {
        spFont->FUN_140e0dc30();
        return true;
    }
    if (!m_d8.IsEmpty())
        m_d8.RemoveKey(nId);
    MS2Ptr<TDamageFontAttr> spAttr(new TDamageFontAttr);
    spAttr->m_18 = nId;
    spFont.AssignRaw(new UIDamageFont(strFont, spAttr));
    spFont->FUN_1422dbf00(spFont->FUN_1422db750(), 0, 0);
    m_90.SetAt(nId, spFont);
    return true;
}

// @0x140b61b80
bool GFxMovieDamage::FUN_140b61b80(const CString& strFont)
{
    unsigned nId = FUN_1407181d0(strFont);
    if (nId == 0)
        return false;
    if (!m_90.IsEmpty() && m_90.Lookup(nId))
        return true;
    if (m_d8.Lookup(nId))
        return true;
    MS2Ptr<UIDamageFont> spFont(new UIDamageFont(strFont, MS2Ptr<TDamageFontAttr>(0)));
    m_d8.SetAt(nId, spFont);
    return true;
}

// @0x140b61ce0
void GFxMovieDamage::FUN_140b61ce0()
{
    if (FUN_1422bd0f0())
    {
        Scaleform::GFx::Movie* pMovie = FUN_1422bd0f0();
        pMovie->ForceCollectGarbage();
    }
    if (m_128 == 0)
        return;
    m_128->FUN_1419135c0();
    if (m_90.IsEmpty())
        return;
    // The limits are set twice (defaults 10 fonts / 600 s, then 0 / 60 s).
    size_t nMinCount = 10;
    __int64 nLifeTime = 600;
    nMinCount = 0;
    nLifeTime = 60;
    if (m_90.GetCount() > nMinCount)
    {
        ATL::CAtlArray<MS2Ptr<UIDamageFont> > arrExpired;
        __int64 nNow = FUN_140869440();
        for (POSITION pos = m_90.GetStartPosition(); pos; m_90.GetNext(pos))
        {
            MS2Ptr<UIDamageFont> spFont = m_90.GetValueAt(pos);
            if (spFont == 0 || spFont->FUN_140e0dca0() == 0)
                continue;
            if (spFont->FUN_140e0dca0() + nLifeTime < nNow)
                arrExpired.Add(spFont);
        }
        if (!arrExpired.IsEmpty())
        {
            size_t nCount = arrExpired.GetCount();
            for (size_t i = 0; i < nCount; ++i)
            {
                MS2Ptr<UIDamageFont> spFont = arrExpired.GetAt(i);
                if (spFont == 0)
                    continue;
                m_90.RemoveKey(spFont->FUN_140e0dbe0());
                m_128->FUN_141913530(spFont->m_strName);
                spFont->FUN_1422dc080();
            }
        }
    }
}

// @0x140b62010
bool GFxMovieDamage::FUN_140b62010(const CString& strFont)
{
    unsigned nId = FUN_1407181d0(strFont);
    if (nId == 0)
        return false;
    MS2Ptr<UIDamageFont> spFont(0);
    if (m_90.Lookup(nId, spFont))
    {
        spFont->FUN_140e0dc30();
        return true;
    }
    if (m_d8.Lookup(nId))
        return true;
    spFont.AssignRaw(new UIDamageFont(strFont, MS2Ptr<TDamageFontAttr>(0)));
    m_d8.SetAt(nId, spFont);
    return true;
}

// @0x140b621a0
bool GFxMovieDamage::FUN_140b621a0()
{
    if (!s_arrSavedFontIds.IsEmpty())
    {
        size_t nCount = s_arrSavedFontIds.GetCount();
        for (size_t i = 0; i < nCount; ++i)
        {
            unsigned nId = s_arrSavedFontIds.GetAt(i);
            FUN_140b61900(FUN_140b62550(nId));
        }
        s_arrSavedFontIds.RemoveAll();
    }
    return true;
}

// @0x140b62270
void GFxMovieDamage::FUN_140b62270()
{
    if (FUN_1408e57f0()->FUN_1422b9dc0() == 0x620000c)
        CUIService::GetInstance()->FUN_141add040((eUIClassID)0x4e32);
}

// @0x140b622b0
void GFxMovieDamage::FUN_140b622b0()
{
    if (!m_90.IsEmpty())
    {
        for (POSITION pos = m_90.GetStartPosition(); pos; m_90.GetNext(pos))
        {
            unsigned nId = m_90.GetKeyAt(pos);
            if (nId == 0)
                continue;
            s_arrSavedFontIds.Add(nId);
        }
    }
}

// The UCRT's `static __inline memcpy_s` copy of this TU (corecrt_memcpy_s.h; the exe calls memset/memcpy here) at the end
// of the COMDAT tail, kept alive by the pointer below (same body as weddingrewarditem.cpp).
#pragma function(memcpy, memset)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode) \
    { int _Expr_val = !!(expr); if (!(_Expr_val)) { errno = errorcode; _invalid_parameter_noinfo(); return errorcode; } }
// @0x140b64ae0
static __inline errno_t ms2_memcpy_s_copy(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0) return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    if (src == NULL || dstSize < srcSize) {
        memset(dst, 0, dstSize);
        MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
        MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
        return EINVAL;
    }
    memcpy(dst, src, srcSize);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy;
#pragma intrinsic(memcpy, memset)   // the template instances (InitHashTable, Rehash) are compiled at the end of the TU

// Not hooked: the ctor/dtor, vfunc_11 / FUN_140b622b0 / FUN_140b621a0 (they use the unit's static s_arrSavedFontIds) and
// vfunc_4 (it calls FUN_140b621a0), the COMDAT helpers, and the 23-byte vfunc_14.
MS2_REPLACE_METHOD(0x140B61900, GFxMovieDamage, FUN_140b61900, 627, 0xD3375340);
MS2_REPLACE_METHOD(0x140B61B80, GFxMovieDamage, FUN_140b61b80, 336, 0x94B9CE48);
MS2_REPLACE_METHOD(0x140B62010, GFxMovieDamage, FUN_140b62010, 380, 0xD66059DA);
MS2_REPLACE_METHOD(0x140B61CE0, GFxMovieDamage, FUN_140b61ce0, 797, 0xA95A7281);
MS2_REPLACE_METHOD(0x140B617F0, GFxMovieDamage, vfunc_8, 251, 0x28A50C75);
MS2_REPLACE_METHOD(0x140B62270, GFxMovieDamage, FUN_140b62270, 52, 0x60F444E0);
