// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIEpProgress, the ep popup entity.
// MS2-UNIT: ?\uiepprogress.cpp
// MS2-RANGE: 0x141931550-0x141931eb0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uiepprogress.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

class Unk_EpStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);           // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);           // unregister
};
Unk_EpStatusMgr* FUN_140aa6d40();

struct Unk_EpCfgData { char m_pad_00[5]; unsigned char m_bEnabled; };
class Unk_EpCfgHolder { public: Unk_EpCfgData* FUN_141248630(); };
Unk_EpCfgHolder* FUN_1409a8b10();
class Unk_EpScene { public: int FUN_1422b9e00(); };                 // current scene id
Unk_EpScene* FUN_1408e57f0();

// The target's name-tag anchor record.
class Unk_PopupTarget : public CPtred
{
public:
    int FUN_141a5e690();                                            // has an anchor
    void FUN_141a5e5d0(Unk_PopupPos* pPos);                         // the anchor position
};
Unk_PopupOwner* FUN_14096e160(Unk_PopupOwner* pOwner);

// The popup clip: ASGameEntity plus the helpers this unit calls.
class Unk_EpEntity : public ASGameEntity
{
public:
    int FUN_1422c1340();                                            // clip width
    Scaleform::GFx::Value FUN_141931d80(const char* szMethod, int a1, int a2, int a3);
};
MS2Ptr<ASGameEntity> FUN_140ba77e0(int nUiId, const Scaleform::GFx::Value& root);
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, int n);

// @0x141931550
UIEpProgress::UIEpProgress(Unk_PopupOwner* pOwner) : UIPopupEntity(pOwner)
{
    m_90 = 9999999;
    m_94 = 1500.0f;
    FUN_1422dbf00(3, 0, 0);
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
}

// @0x141931640
UIEpProgress::~UIEpProgress()
{
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
}

// @0x1419316f0
CString UIEpProgress::GetTypeName()
{
    return "EpProgress";
}

// @0x141931740
void UIEpProgress::vfunc_54(int nMode)
{
    UIPopupEntity::vfunc_54(nMode);
}

// @0x141931770
void UIEpProgress::vfunc_55()
{
    UIPopupEntity::vfunc_55();
}

// @0x141931790
void UIEpProgress::vfunc_52()
{
    UIPopupEntity::vfunc_52();
}

// @0x1419317b0
// MS2-FUNCTIONAL: the MS2Ptr temporary of vfunc_82 spills one extra stack slot in the exe (frame 0x08 smaller)
void UIEpProgress::vfunc_53(Unk_PopupPos pos)
{
    if (m_30.IsNull() || vfunc_9() == 0)
        return;
    {
        MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pClip.get())
        {
            Unk_PopupPos pt = pos;
            Unk_PopupOwner* pActor = FUN_14096e160(m_68);
            if (pActor)
            {
                Unk_PopupTarget* pTarget = pActor->vfunc_82();
                if (pTarget && pTarget->FUN_141a5e690() != 0)
                {
                    pTarget->FUN_141a5e5d0(&pt);
                    int nWidth = static_cast<Unk_EpEntity*>(pClip.operator->())->FUN_1422c1340();
                    pt.x = pt.x - (nWidth * 0.5 + 10.0);
                }
            }
            pt.y = pt.y - 10.0f;
            pClip->FUN_1422c00f0(pt.x, pt.y);
        }
    }
}

// @0x1419319a0
int UIEpProgress::vfunc_57(int nForce)
{
    if (UIPopupEntity::vfunc_57(nForce) != 0)
        return 1;
    if (FUN_1408e57f0()->FUN_1422b9e00() != 0x620001d)
        return 1;
    if (FUN_1409a8b10()->FUN_141248630()->m_bEnabled == 0)
        return 1;
    return 0;
}

// @0x141931a10
float UIEpProgress::vfunc_59()
{
    if (m_68 != 0)
        return m_68->vfunc_89();
    return 0.0f;
}

// @0x141931a50
void UIEpProgress::vfunc_oa0_5(int a1, int a2)
{
    unsigned int nOld = m_e0;
    m_e0 = a1;
    if (nOld <= (unsigned int)a1)
        return;
    if (FUN_1409a8b10()->FUN_141248630()->m_bEnabled == 0)
        return;
    if (vfunc_56() == 0)
        vfunc_54(0);
    MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pClip.get())
        static_cast<Unk_EpEntity*>(pClip.operator->())->FUN_141931d80("setEP", nOld, a1, a2);
}

// @0x141931bd0
void UIEpProgress::FUN_141931bd0(int nEp, int a2)
{
    int nOld = m_e0;
    m_e0 = nEp;
    if (FUN_1409a8b10()->FUN_141248630()->m_bEnabled == 0)
        return;
    if (vfunc_56() == 0)
        vfunc_54(0);
    MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pClip.get())
        static_cast<Unk_EpEntity*>(pClip.operator->())->FUN_141931d80("setEP", nOld, nEp, a2);
}

// @0x141931d10
void UIEpProgress::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

// @0x141931d80
Scaleform::GFx::Value Unk_EpEntity::FUN_141931d80(const char* szMethod, int a1, int a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    FUN_1422bcd10(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x1419316F0, UIEpProgress, GetTypeName, 61, 0x3AEDFE10);
MS2_REPLACE_METHOD(0x141931740, UIEpProgress, vfunc_54, 32, 0xC5E4F3FF);
MS2_REPLACE_METHOD(0x141931770, UIEpProgress, vfunc_55, 24, 0x6CDCD363);
MS2_REPLACE_METHOD(0x141931790, UIEpProgress, vfunc_52, 24, 0xF5EBB716);
MS2_REPLACE_METHOD(0x1419317B0, UIEpProgress, vfunc_53, 477, 0xA84B719B);
MS2_REPLACE_METHOD(0x1419319A0, UIEpProgress, vfunc_57, 100, 0x8D040A68);
MS2_REPLACE_METHOD(0x141931A10, UIEpProgress, vfunc_59, 58, 0xEA534D49);
MS2_REPLACE_METHOD_VIA(0x141931A50, UIEpProgress, UIStatusEventListener, vfunc_oa0_5, 378, 0x33D3D48A);
MS2_REPLACE_METHOD(0x141931BD0, UIEpProgress, FUN_141931bd0, 312, 0xB346147F);
MS2_REPLACE_METHOD(0x141931D10, UIEpProgress, vfunc_41, 99, 0x6F975494);
MS2_REPLACE_METHOD(0x141931D80, Unk_EpEntity, FUN_141931d80, 207, 0x0818BD0B);
