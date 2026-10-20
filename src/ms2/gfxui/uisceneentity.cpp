// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISceneEntity, the base of the UI scenes. See
// uisceneentity.h.
// MS2-UNIT: ?\uisceneentity.cpp
// MS2-RANGE: 0x1422e7770-0x1422e8920 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// COMDAT tail: the ASScene creation helper and MS2Ptr<ASScene> members vfunc_41 instantiates, CAtlList::IsEmpty.
// MS2-PIN: ??_GUISceneEntity@@UEAAPEAXI@Z 0x1422e87a0
#include "ms2/placeholder/ms2stdafx.h"

#include "uisceneentity.h"
#include "asscene.h"
#include "ms2/placeholder/gfxservice.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// new T(v, nMovieId) wrapped in an MS2Ptr (the same helper as assprite.cpp's; one COMDAT per T)
template <class T> inline MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

// @0x1422e7770
UISceneEntity::UISceneEntity()
    : m_68(0), m_6c(0), m_70(0), m_78(10)
{
    FUN_1422dc2f0(0);
    m_2c = 0xc;
    FUN_140b632f0()->FUN_1422d0c10(MS2Ptr<UISceneEntity>(this));
}

// @0x1422e7850
UISceneEntity::~UISceneEntity()
{
    FUN_1422dc080();
    m_78.RemoveAll();
}

// @0x1422e78d0
CString UISceneEntity::vfunc_1()
{
    return "SceneEntity";
}
MS2_REPLACE_METHOD(0x1422e78d0, UISceneEntity, vfunc_1, 61, 0xDB1893F8);

// @0x1422e7920
bool UISceneEntity::vfunc_47()
{
    return true;
}
MS2_REPLACE_METHOD(0x1422e7920, UISceneEntity, vfunc_47, 8, 0x71679366);

// @0x1422e7930
int UISceneEntity::FUN_1422e7930()
{
    return m_68;
}
MS2_REPLACE_METHOD(0x1422e7930, UISceneEntity, FUN_1422e7930, 14, 0xD1D12A47);

// @0x1422e7950
int UISceneEntity::FUN_1422e7950()
{
    return m_6c;
}
MS2_REPLACE_METHOD(0x1422e7950, UISceneEntity, FUN_1422e7950, 14, 0x69D980EB);

// @0x1422e7970
int UISceneEntity::FUN_1422e7970()
{
    return m_70;
}
MS2_REPLACE_METHOD(0x1422e7970, UISceneEntity, FUN_1422e7970, 14, 0x81E2A10F);

// @0x1422e7990
int UISceneEntity::FUN_1422e7990(int nSceneId)
{
    if (m_78.IsEmpty())
        return 0;
    for (POSITION pos = m_78.GetHeadPosition(); pos != NULL; m_78.GetNext(pos))
    {
        UISceneEntity* pScene = m_78.GetAt(pos).get();
        if (pScene != NULL && pScene->FUN_1422e7950() == nSceneId)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422e7990, UISceneEntity, FUN_1422e7990, 170, 0xDE2075E7);

// @0x1422e7a40
void UISceneEntity::FUN_1422e7a40(int nSceneId)
{
    FUN_1408e57f0()->FUN_1422b9fd0(nSceneId);
}
MS2_REPLACE_METHOD(0x1422e7a40, UISceneEntity, FUN_1422e7a40, 35, 0x8C34759F);

// @0x1422e7a70
UISceneEntity* UISceneEntity::FUN_1422e7a70(int nSceneId)
{
    if (m_78.IsEmpty())
        return NULL;
    for (POSITION pos = m_78.GetHeadPosition(); pos != NULL; m_78.GetNext(pos))
    {
        UISceneEntity* pScene = m_78.GetAt(pos).get();
        if (pScene != NULL && pScene->FUN_1422e7950() == nSceneId)
            return pScene;
    }
    return NULL;
}
MS2_REPLACE_METHOD(0x1422e7a70, UISceneEntity, FUN_1422e7a70, 170, 0xC2BEE5B5);

// @0x1422e7b20
int UISceneEntity::vfunc_48(int nPrevSceneId)
{
    m_68 = nPrevSceneId;
    m_70 = 1;
    if (vfunc_47())
        FUN_1422dbf80(FUN_1422db790(), m_2c, 0, 0);
    return m_6c;
}
MS2_REPLACE_METHOD(0x1422e7b20, UISceneEntity, vfunc_48, 162, 0x9BCF70F6);

// @0x1422e7bd0
int UISceneEntity::vfunc_49(int nNextSceneId)
{
    m_68 = 0;
    m_70 = 0;
    vfunc_51();
    FUN_1422dc080();
    if (!m_78.IsEmpty())
    {
        for (POSITION pos = m_78.GetHeadPosition(); pos != NULL; m_78.GetNext(pos))
        {
            UISceneEntity* pScene = m_78.GetAt(pos).get();
            if (pScene != NULL && pScene->FUN_1422e7970())
            {
                pScene->vfunc_49(0);
                break;
            }
        }
    }
    return m_6c;
}
MS2_REPLACE_METHOD(0x1422e7bd0, UISceneEntity, vfunc_49, 243, 0xB475F817);

// @0x1422e7cd0
void UISceneEntity::vfunc_50()
{
    ASScene* pScene = dynamic_cast<ASScene*>((AScript*)m_30);
    if (pScene != NULL)
        pScene->Enter();
}
MS2_REPLACE_METHOD(0x1422e7cd0, UISceneEntity, vfunc_50, 86, 0xF5A0547E);

// @0x1422e7d30
void UISceneEntity::vfunc_51()
{
    ASScene* pScene = dynamic_cast<ASScene*>((AScript*)m_30);
    if (pScene != NULL)
        pScene->Leave();
}
MS2_REPLACE_METHOD(0x1422e7d30, UISceneEntity, vfunc_51, 86, 0xAF42B64B);

// @0x1422e7d90
void UISceneEntity::OnLoadInit()
{
    UISwfEntity::OnLoadInit();
    vfunc_50();
}
MS2_REPLACE_METHOD(0x1422e7d90, UISceneEntity, OnLoadInit, 43, 0x25A79FDC);

// The active child scene gets the call (at most one is shown).
#define MS2_FORWARD_TO_ACTIVE_CHILD(call)                                               \
    if (m_78.IsEmpty())                                                                 \
        return;                                                                         \
    for (POSITION pos = m_78.GetHeadPosition(); pos != NULL; m_78.GetNext(pos))         \
    {                                                                                   \
        UISceneEntity* pScene = m_78.GetAt(pos).get();                                  \
        if (pScene != NULL && pScene->FUN_1422e7970())                                  \
        {                                                                               \
            pScene->call;                                                               \
            return;                                                                     \
        }                                                                               \
    }

// @0x1422e7dd0
void UISceneEntity::vfunc_52()
{
    MS2_FORWARD_TO_ACTIVE_CHILD(vfunc_52())
}
MS2_REPLACE_METHOD(0x1422e7dd0, UISceneEntity, vfunc_52, 177, 0x2C449BB3);

// @0x1422e7e90
void UISceneEntity::vfunc_53()
{
    MS2_FORWARD_TO_ACTIVE_CHILD(vfunc_53())
}
MS2_REPLACE_METHOD(0x1422e7e90, UISceneEntity, vfunc_53, 177, 0xBDA954E9);

// @0x1422e7f50
void UISceneEntity::vfunc_54()
{
    MS2_FORWARD_TO_ACTIVE_CHILD(vfunc_54())
}
MS2_REPLACE_METHOD(0x1422e7f50, UISceneEntity, vfunc_54, 177, 0x16B79F86);

// @0x1422e8010
void UISceneEntity::vfunc_55()
{
    ASScene* pAS = dynamic_cast<ASScene*>((AScript*)m_30);
    if (pAS != NULL)
        pAS->WorldLoadComplete();
    MS2_FORWARD_TO_ACTIVE_CHILD(vfunc_55())
}
MS2_REPLACE_METHOD(0x1422e8010, UISceneEntity, vfunc_55, 249, 0xF53C0F31);

// @0x1422e8110
void UISceneEntity::vfunc_56()
{
    ASScene* pAS = dynamic_cast<ASScene*>((AScript*)m_30);
    if (pAS != NULL)
        pAS->WorldUnLoadComplete();
    MS2_FORWARD_TO_ACTIVE_CHILD(vfunc_56())
}
MS2_REPLACE_METHOD(0x1422e8110, UISceneEntity, vfunc_56, 249, 0x4F0A940E);

// @0x1422e8210
void UISceneEntity::vfunc_57()
{
    MS2_FORWARD_TO_ACTIVE_CHILD(vfunc_57())
}
MS2_REPLACE_METHOD(0x1422e8210, UISceneEntity, vfunc_57, 177, 0x414D67AE);

// @0x1422e82d0
void UISceneEntity::vfunc_58()
{
    MS2_FORWARD_TO_ACTIVE_CHILD(vfunc_58())
}
MS2_REPLACE_METHOD(0x1422e82d0, UISceneEntity, vfunc_58, 177, 0xF3377239);

// @0x1422e8390
void UISceneEntity::vfunc_59(void* p, int a, int b)
{
    MS2_FORWARD_TO_ACTIVE_CHILD(vfunc_59(p, a, b))
}
MS2_REPLACE_METHOD(0x1422e8390, UISceneEntity, vfunc_59, 207, 0x73CA2D24);

#undef MS2_FORWARD_TO_ACTIVE_CHILD

// @0x1422e8470
int UISceneEntity::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1422e8470, UISceneEntity, vfunc_28, 67, 0x88A97A08);

// @0x1422e84c0
void UISceneEntity::vfunc_43()
{
    ASScene* pScene = dynamic_cast<ASScene*>((AScript*)m_30);
    if (pScene != NULL)
        pScene->vfunc_25();
}
MS2_REPLACE_METHOD(0x1422e84c0, UISceneEntity, vfunc_43, 95, 0xF3BBA43B);

// @0x1422e8530
void UISceneEntity::vfunc_60(MS2Ptr<AScript> spBackground)
{
}

// @0x1422e8560
void UISceneEntity::vfunc_61(MS2Ptr<AScript> spBackground, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
}

// @0x1422e8590
int UISceneEntity::vfunc_62()
{
    return 0;
}

// @0x1422e85a0
int UISceneEntity::vfunc_63()
{
    return 0;
}

// @0x1422e85b0
void UISceneEntity::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = Unk_ASCreate<ASScene>(m_28, root);
}
MS2_REPLACE_METHOD(0x1422e85b0, UISceneEntity, vfunc_41, 99, 0xEFA5A4CE);
