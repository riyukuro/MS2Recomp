// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Profile image popup HUD (world-anchored, UIHudEntity family).
// MS2-UNIT: ?\uipopupprofileimage.cpp
// MS2-RANGE: 0x141a8f3a0-0x141a904f0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipopupprofileimage.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uipopupprofileimage.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <errno.h>
#include <string.h>

// Unit-local declarations; the unidentified names describe uses rather than original class names.
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::get() const;         // 0x1405a8eb0
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::operator->() const;  // 0x1405a8f40
template <> MS2Ptr<Unk_PCBaseComp_aa8>::~MS2Ptr();                               // 0x1405a8980
class Unk_PopupEntity : public ASGameEntity
{
public:
    Scaleform::GFx::Value FUN_140ba9470(const char* szMethod, int a1, CString a2, bool a3);      // "createEntity"
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value a1, bool a2); // "updateEntity"
    Scaleform::GFx::Value& FUN_1422bb870();
    void FUN_1422c00f0(float x, float y);
    void FUN_1422c0290(float cx, float cy);
};
struct Unk_PopupCfgInt { int* FUN_1402056b0(); void* m_unknown; };
struct Unk_PopupCfgB60 { void* m_unknown; };
struct Unk_PopupCfg
{
    char m_pad_0000[0xb08];
    Unk_PopupCfgInt m_b08;
    char m_pad_0b10[0xb60 - 0xb08 - sizeof(Unk_PopupCfgInt)];
    Unk_PopupCfgB60 m_b60;
    char m_pad_0b68[0xcc0 - 0xb60 - sizeof(Unk_PopupCfgB60)];
    Unk_PopupCfgInt m_cc0;
};
Unk_PopupCfg* FUN_1401d3200();
class Unk_PopupUIScale;
Unk_PopupUIScale* FUN_14025e7a0();                                          // ui scale service
float FUN_1422afec0(Unk_PopupUIScale* pScale, int nLayer);                  // scale of a layer
NiPoint3* FUN_140ad0c10(NiPoint3* pt, float f);                             // efd::Point3::operator*=
float FUN_1412762d0(const NiPoint3& pt);
class Unk_PopupActor : public PCBase
{
public:
    int FUN_14166ce30();
    CString FUN_1416612e0();                                                 // profile image name of the player
};
class Unk_PopupSvc { public: void FUN_1416979e0(__int64 nId); };
Unk_PopupSvc* FUN_1414a5750();
void* FUN_1408e57f0();
int FUN_1422b9e00(void*);
PCBase* FUN_140974230(PCBase*);
__int64 FUN_141656a80(PCBase*);
CString FUN_141028be0(__int64 nId, const CString& strName, int nFlag, CString strExtra);   // profile image path
CStringW FUN_14016a730(const char* sz, int nFlags);                         // FormatStringId(id) without arguments
bool FUN_140930110(int nActorId);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
class Unk_PopupUIMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int); };
Unk_PopupUIMgr* FUN_1403ed2b0();
class Unk_PopupInfoAS : public AScript
{
public:
    Unk_PopupInfoAS(int nMovieId);
    void FUN_1407cb9c0(const char* szMember, int nValue);
    void FUN_1407cbb20(const char* szMember, CStringW strValue);
};
class Unk_PopupTimerCfg;
Unk_PopupTimerCfg* FUN_140a36020(Unk_PopupCfgB60*);
int FUN_140a35ca0(Unk_PopupTimerCfg*);
UIPopupProfileImage* FUN_141a90250(int nUiId);
int FUN_141a8fc10(Unk_PopupCfgB60* pCfg);

// @0x141a8f3a0
UIPopupProfileImage::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : TimerEntity(nLayer, clip, nActorId)
{
    m_a0 = 0;
    m_64 = FUN_141a8fc10(&FUN_1401d3200()->m_b60);
    m_54 = (float)*FUN_1401d3200()->m_cc0.FUN_1402056b0();
}

// @0x141a8f450
UIPopupProfileImage::Entity::~Entity()
{
}

// @0x141a8f480
void UIPopupProfileImage::Entity::vfunc_2()
{
    TimerEntity::vfunc_2();
}

// @0x141a8f4a0
void UIPopupProfileImage::Entity::vfunc_3()
{
    TimerEntity::vfunc_3();
    if (m_38.get())
        m_38->Invoke("close");
}

// @0x141a8f510
void UIPopupProfileImage::Entity::vfunc_4()
{
    UIHudEntity::Entity::vfunc_4();
    m_a0 = 0;
}

// @0x141a8f540
void UIPopupProfileImage::Entity::vfunc_5()
{
    UIHudEntity::Entity::vfunc_5();
    PCBase* pPc = FUN_140974230((PCBase*)FUN_140f49330());
    if (pPc == 0)
        return;
    if (m_38.get() != 0)
    {
        Unk_PopupInfoAS info(m_18);
        CString strPath = FUN_141028be0(FUN_141656a80(pPc), ((Unk_PopupActor*)pPc)->FUN_1416612e0(), 1, CString(""));
        info.FUN_1407cbb20("imgPath", FUN_14016a730((const char*)strPath, 0));
        info.FUN_1407cb9c0("dead", ((Unk_PopupActor*)pPc)->FUN_14166ce30());
        m_38->Invoke("open", info);
        float fScale = (float)*FUN_1401d3200()->m_b08.FUN_1402056b0();
        float fSize = (fScale / 64.0f) * 100.0f;
        ((Unk_PopupEntity*)m_38.operator->())->FUN_1422c0290(fSize, fSize);
    }
}

// @0x141a8f790
void UIPopupProfileImage::Entity::vfunc_6(NiPoint3* pPos)
{
    if (m_38.get())
    {
        FUN_140ad0c10(pPos, FUN_1422afec0(FUN_14025e7a0(), m_18));
        pPos->y = pPos->y + vfunc_9();
        pPos->y = pPos->y + FUN_1412762d0(vfunc_10());
        ((Unk_PopupEntity*)m_38.operator->())->FUN_1422c00f0(pPos->x, pPos->y);
    }
}

// @0x141a8f880
void UIPopupProfileImage::Entity::vfunc_7()
{
    PCBase* pPc = FUN_140974230((PCBase*)FUN_140f49330());
    if (pPc != 0)
        FUN_1414a5750()->FUN_1416979e0(FUN_141656a80(pPc));
    if (m_38.get())
        m_38->Invoke("close");
}

// @0x141a8f920
int UIPopupProfileImage::Entity::vfunc_8(int n)
{
    PCBase* pActor = (PCBase*)FUN_140f49330();
    if (pActor == 0)
        return 1;
    if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001e)
        return 1;
    MS2Ptr<Unk_PCBaseComp_aa8> sp = pActor->vfunc_85();
    if ((bool)sp.get() && ((UIHudEntity::Entity*)(void*)sp.operator->())->FUN_140f48d40() != 0)
        return 1;
    return TimerEntity::vfunc_8(((Unk_PopupActor*)pActor)->FUN_14166ce30());
}

// @0x141a8fa20
UIPopupProfileImage::UIPopupProfileImage()
{
    m_70 = "profile_ugc_balloon";
}

// @0x141a8fa90
UIPopupProfileImage::~UIPopupProfileImage()
{
}

// @0x141a8fad0
CString UIPopupProfileImage::GetTypeName()
{
    return CString("PopupProfileImage");
}

// @0x141a8fb20
void UIPopupProfileImage::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_141a8fc30(m_68);
}

// @0x141a8fb50
MS2Ptr<UIPopupProfileImage::Entity> FUN_141a8fb50(int nActorId)
{
    UIPopupProfileImage* pBar = FUN_141a90250(0x4e57);
    if (pBar != 0)
        return MS2Ptr<UIPopupProfileImage::Entity>(pBar->FUN_141a8fe10(nActorId));
    return MS2Ptr<UIPopupProfileImage::Entity>(0);
}

// @0x141a8fbd0
void FUN_141a8fbd0(int nActorId)
{
    UIPopupProfileImage* pBar = FUN_141a90250(0x4e57);
    if (pBar)
        pBar->FUN_140f49c00(nActorId);
}

// @0x141a8fc10
int FUN_141a8fc10(Unk_PopupCfgB60* pCfg)
{
    return FUN_140a35ca0(FUN_140a36020(pCfg));
}

// @0x141a8fc30
void UIPopupProfileImage::FUN_141a8fc30(unsigned int nCount)
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

// @0x141a8fe10
UIPopupProfileImage::Entity* UIPopupProfileImage::FUN_141a8fe10(int nActorId)
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
                Scaleform::GFx::Value v = ((Unk_PopupEntity*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
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
                                ((Unk_PopupEntity*)pClip.operator->())->FUN_140ba9570("updateEntity", ((Unk_PopupEntity*)pOldClip.operator->())->FUN_1422bb870(), bNew);
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

// @0x141a90250
UIPopupProfileImage* FUN_141a90250(int nUiId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (p.get())
            return dynamic_cast<UIPopupProfileImage*>((UIObject*)p);
    }
    return 0;
}


MS2_REPLACE_METHOD(0x141a8f480, UIPopupProfileImage::Entity, vfunc_2, 24, 0x10224322);
MS2_REPLACE_METHOD(0x141a8f4a0, UIPopupProfileImage::Entity, vfunc_3, 93, 0x6BCF359D);
MS2_REPLACE_METHOD(0x141a8f510, UIPopupProfileImage::Entity, vfunc_4, 39, 0x041577FD);
MS2_REPLACE_METHOD(0x141a8f540, UIPopupProfileImage::Entity, vfunc_5, 573, 0x0175674A);
MS2_REPLACE_METHOD(0x141a8f790, UIPopupProfileImage::Entity, vfunc_6, 222, 0x799310FB);
MS2_REPLACE_METHOD(0x141a8f880, UIPopupProfileImage::Entity, vfunc_7, 150, 0x5B169D16);
MS2_REPLACE_METHOD(0x141a8f920, UIPopupProfileImage::Entity, vfunc_8, 237, 0x9E45985A);
MS2_REPLACE_METHOD(0x141a8fad0, UIPopupProfileImage, GetTypeName, 61, 0x1BDBEEAF);
MS2_REPLACE_METHOD(0x141a8fb20, UIPopupProfileImage, OnLoadComplete, 42, 0x847DFC92);
MS2_REPLACE(0x141a8fbd0, FUN_141a8fbd0, 50, 0xAAA7E206);
MS2_REPLACE_METHOD(0x141a8fc30, UIPopupProfileImage, FUN_141a8fc30, 465, 0x4AFBC44B);
MS2_REPLACE_METHOD(0x141a8fe10, UIPopupProfileImage, FUN_141a8fe10, 1082, 0x94AFF1DF);
MS2_REPLACE(0x141a90250, FUN_141a90250, 147, 0x93E5FB49);

// The UCRT's `static __inline memcpy_s` (corecrt_memcpy_s.h), emitted because the original TU kept an unreferenced copy.
#pragma function(memcpy, memset)
static __inline errno_t ms2_memcpy_s_copy(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy;
