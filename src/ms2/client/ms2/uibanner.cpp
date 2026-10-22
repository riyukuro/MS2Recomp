// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Banner HUD (world-anchored, UIHudEntity family) and its
// click listeners (RPS game, couple dance); the listeners' GetTypeName bodies are in uibannereventlistener.cpp.
// MS2-UNIT: client\ms2\uibanner.cpp
// MS2-RANGE: 0x140ba8280-0x140bac2f0 .text$mn
// MS2-RANGE: 0x1400c9ba0-0x1400c9d30 .text$di
// MS2-RANGE: 0x142ca15f0-0x142ca1680 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1UIBannerEventListener@@UEAA@XZ 0x140ba9ce0 ; prop
// MS2-PIN: ??_GUIBannerEventListener@@UEAAPEAXI@Z 0x140ba9f30 ; prop
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@W4BannerType@UIBanner@@@ATL@@SAHAEBW4BannerType@UIBanner@@0@Z 0x140baa0c0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VEntity@UIHudEntity@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VEntity@UIHudEntity@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140baa5c0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibanner.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uibanner.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The unit's statics: the shared header statics.
#include "ms2/placeholder/header_statics_a.h"

// Unit-local declarations; the unidentified names describe uses rather than original class names.
class Unk_BannerClip : public ASGameEntity
{
public:
    Scaleform::GFx::Value FUN_140ba9470(const char* szMethod, int nActorId, CString strCache, bool bFlag);   // "createEntity"
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value clip, bool bFlag);       // "updateEntity"
    Scaleform::GFx::Value& FUN_1422bb870();
    void FUN_1422c00f0(float x, float y);
};
class Unk_BannerASObj : public ASObj
{
public:
    void FUN_140ba9670(const char* szName, int n);                                  // set an int member
};
struct Unk_BannerCfgFloat { float FUN_1402bac70(); char m_pad[0x58]; };
struct Unk_BannerCfg
{
    char m_pad_0000[0x320];
    Unk_BannerCfgFloat m_320;
};
Unk_BannerCfg* FUN_1401d3200();
class Unk_BannerUIScale;
Unk_BannerUIScale* FUN_14025e7a0();                                         // ui scale service
float FUN_1422afec0(Unk_BannerUIScale* pScale, int nLayer);                 // scale of a layer
NiPoint3* FUN_140ad0c10(NiPoint3* pt, float f);                             // efd::Point3::operator*=
class Unk_BannerMgr;
Unk_BannerMgr* FUN_1409478c0();                                             // singleton accessor
int FUN_140a18070(Unk_BannerMgr*);
class Unk_BannerActor : public PCBase
{
public:
    int FUN_14166ce30();
    float FUN_141670500();
};
PCBase* FUN_140974230(PCBase*);
NiAVObject* FUN_141675150(PCBase* pActor, const CString& strNode);          // the actor's node of that name
bool FUN_140930110(int nActorId);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
UIBanner* FUN_1409614b0(int nUiId);                                         // the ui object of that id
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);          // Value = n
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);          // Value = sz
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);                  // Value = b
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v); // Value = v (callee destroys)

// @0x140ba8280
UIBanner::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : UIHudEntity::Entity(nLayer, clip, nActorId)
{
    m_60 = 0;
    m_54 = FUN_1401d3200()->m_320.FUN_1402bac70();
}

// @0x140ba8310
UIBanner::Entity::~Entity()
{
}

// @0x140ba8340
void UIBanner::Entity::vfunc_2()
{
    FUN_140ba8740("Eff_Foot_World");
    UIHudEntity::Entity::vfunc_2();
}
MS2_REPLACE_METHOD(0x140ba8340, UIBanner::Entity, vfunc_2, 72, 0x40A934B1);

// @0x140ba8390
void UIBanner::Entity::vfunc_3()
{
    UIHudEntity::Entity::vfunc_3();
    vfunc_7();
}

// @0x140ba83c0
void UIBanner::Entity::vfunc_4()
{
    UIHudEntity::Entity::vfunc_4();
}

// @0x140ba83e0
void UIBanner::Entity::vfunc_5()
{
    UIHudEntity::Entity::vfunc_5();
    if (FUN_140a18070(FUN_1409478c0()) == 0)
        return;
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return;
    if (m_38 == 0)
        return;
    ASObj info(m_18);
    ((Unk_BannerASObj&)info).FUN_140ba9670("type", m_60);
    info.FUN_1409c0d20("gameOID", pActor->FUN_14123c580());
    m_38->Invoke("open", info.FUN_1422bb870());
}

// @0x140ba8540
void UIBanner::Entity::vfunc_6(NiPoint3* pPos)
{
    if (m_38.get() != 0)
    {
        float fScale = FUN_1422afec0(FUN_14025e7a0(), m_18);
        FUN_140ad0c10(pPos, fScale);
        ((Unk_BannerClip*)m_38.operator->())->FUN_1422c00f0(pPos->x - 110.0f, pPos->y);
    }
}

// @0x140ba85e0
void UIBanner::Entity::vfunc_7()
{
    if (m_38.get() != 0)
        m_38->Invoke("close");
}

// @0x140ba8640
int UIBanner::Entity::vfunc_8(int n)
{
    Unk_BannerActor* pActor = (Unk_BannerActor*)FUN_140f49330();
    if (pActor == 0)
        return 1;
    return UIHudEntity::Entity::vfunc_8(pActor->FUN_14166ce30());
}

// @0x140ba8690
float UIBanner::Entity::vfunc_9()
{
    Unk_BannerActor* pActor = (Unk_BannerActor*)FUN_140f49330();
    if (pActor == 0)
        return 0.0f;
    return pActor->FUN_141670500();
}

// @0x140ba86d0
PCBase* UIBanner::Entity::FUN_140ba86d0()
{
    return FUN_140974230(FUN_140f49330());
}

// @0x140ba8700
int UIBanner::Entity::FUN_140ba8700()
{
    return m_60;
}

// @0x140ba8720
void UIBanner::Entity::FUN_140ba8720(int nType)
{
    m_60 = nType;
}

// @0x140ba8740
void UIBanner::Entity::FUN_140ba8740(CString strNode)
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return;
    m_28 = strNode;
    m_20 = FUN_141675150(pActor, m_28);
}

// @0x140ba87d0
UIBanner::UIBanner()
    : m_f0(10)
{
    m_70 = "banner_body";
    {
        MS2Ptr<UIBannerEventListener> sp(new UIBannerEventListenerRpsGame());
        m_f0.SetAt(BANNER_RPS_GAME, sp);
    }
    {
        MS2Ptr<UIBannerEventListener> sp(new UIBannerEventListenerCoupleDance());
        m_f0.SetAt(BANNER_COUPLE_DANCE, sp);
    }
}

// @0x140ba8990
UIBanner::~UIBanner()
{
}

// @0x140ba89e0
CString UIBanner::GetTypeName()
{
    return "Banner";
}
MS2_REPLACE_METHOD(0x140ba89e0, UIBanner, GetTypeName, 61, 0x7A49F62A);

// @0x140ba8a30
void UIBanner::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140ba8db0(m_68);
}
MS2_REPLACE_METHOD(0x140ba8a30, UIBanner, OnLoadComplete, 42, 0x41B42FD6);

// @0x140ba8a60
int UIBanner::vfunc_28(const char* szName, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szName, pArgs, nArgs))
        return 1;
    if (_stricmp(szName, "onClick") == 0)
    {
        ASData data;
        if (!data.FUN_1422b9620(pArgs, nArgs))
        {
            MS2_ASSERT_AT(185, 0);
            return 0;
        }
        int nActorId = data.FUN_1422b8b10();
        FUN_140ba8b80(nActorId);
        return 1;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140ba8a60, UIBanner, vfunc_28, 282, 0x6AEAD8CB);

// @0x140ba8b80
void UIBanner::FUN_140ba8b80(int nActorId)
{
    MS2Ptr<UIBanner::Entity> pEntity(FUN_140ba93d0(nActorId));
    if (pEntity == 0)
    {
        MS2_ASSERT_AT(203, 0);
        return;
    }
    MS2Ptr<UIBannerEventListener> pListener;
    BannerType nType = (BannerType)pEntity->FUN_140ba8700();
    if (!m_f0.Lookup(nType, pListener))
    {
        MS2_ASSERT_AT(210, 0);
        return;
    }
    pListener->vfunc_1(pEntity);
}
MS2_REPLACE_METHOD(0x140ba8b80, UIBanner, FUN_140ba8b80, 352, 0x1E3BCB61);

// @0x140ba8cf0
MS2Ptr<UIBanner::Entity> FUN_140ba8cf0(int nActorId)
{
    UIBanner* pBanner = FUN_1409614b0(0x4e30);
    if (pBanner == 0)
        return MS2Ptr<UIBanner::Entity>(0);
    return MS2Ptr<UIBanner::Entity>(pBanner->FUN_140ba8f90(nActorId));
}
MS2_REPLACE(0x140ba8cf0, FUN_140ba8cf0, 122, 0x80FEF9E4);

// @0x140ba8d70
void FUN_140ba8d70(int nActorId)
{
    UIBanner* pBanner = FUN_1409614b0(0x4e30);
    if (pBanner == 0)
        return;
    pBanner->FUN_140f49c00(nActorId);
}
MS2_REPLACE(0x140ba8d70, FUN_140ba8d70, 52, 0xD7D31162);

// @0x140ba8db0
void UIBanner::FUN_140ba8db0(unsigned int nCount)
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
MS2_REPLACE_METHOD(0x140ba8db0, UIBanner, FUN_140ba8db0, 465, 0x46BBE4C9);

// @0x140ba8f90
UIBanner::Entity* UIBanner::FUN_140ba8f90(int nActorId)
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
            Scaleform::GFx::Value v = ((Unk_BannerClip*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
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
                            ((Unk_BannerClip*)pClip.operator->())->FUN_140ba9570("updateEntity", ((Unk_BannerClip*)pOldClip.operator->())->FUN_1422bb870(), bNew);
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
MS2_REPLACE_METHOD(0x140ba8f90, UIBanner, FUN_140ba8f90, 1082, 0x21E1404E);

// @0x140ba93d0
UIBanner::Entity* UIBanner::FUN_140ba93d0(int nActorId)
{
    if (FUN_140f49890(nActorId) != 0)
        return 0;
    MS2Ptr<UIHudEntity::Entity> p(0);
    if (!m_a8.Lookup(nActorId, p))
        return 0;
    return (Entity*)p.get();
}
MS2_REPLACE_METHOD(0x140ba93d0, UIBanner, FUN_140ba93d0, 153, 0x8291A101);

// @0x140ba9470
Scaleform::GFx::Value Unk_BannerClip::FUN_140ba9470(const char* szMethod, int nActorId, CString strCache, bool bFlag)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcd10(args.FUN_1409b1f70(0), nActorId);
    FUN_1422bce70(args.FUN_1409b1f70(1), strCache);
    FUN_1422bcce0(args.FUN_1409b1f70(2), bFlag);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ba9570
Scaleform::GFx::Value Unk_BannerClip::FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value clip, bool bFlag)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcc70(args.FUN_1409b1f70(0), clip);
    FUN_1422bcce0(args.FUN_1409b1f70(1), bFlag);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ba9670
void Unk_BannerASObj::FUN_140ba9670(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140baa6b0
int UIBanner::vfunc_48()
{
    return 0x4e30;
}

MS2_EMIT_CRT_MEMMOVE_S();
