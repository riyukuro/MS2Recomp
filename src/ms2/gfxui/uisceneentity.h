// uisceneentity.h - UISceneEntity (RTTI .?AVUISceneEntity@@, base UISwfEntity, 0xa8 bytes, vftable 0x143116158 with 65
// slots, IMessageListener-in-UISceneEntity 0x143116368): the base of every UI scene (login, lobby, game, ...). A scene
// has child scenes (sub-scenes, +0x78) of which one is active at a time; GFxSceneService switches scenes and sub-scenes
// through slots 48/49 and forwards the world events (slots 52..59) to the current scene, which forwards them to its
// active child. Code in ?\uisceneentity.cpp (src/ms2/gfxui/uisceneentity.cpp). Header name and directory assumed.
//
// Several client units (uiscenegame.h, uiscenelobbyselect.h, uiscenelogin.h, ...) still declare their own unit-local
// views of this class; new code should include this header instead.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/gfxui/uiswfentity.h"

class UISceneEntity : public UISwfEntity
{
public:
    UISceneEntity();                                                // 0x1422e7770 (registers with UISwfEntityManager)
    virtual ~UISceneEntity();                                       //  0 0x1422e7850 (scalar deleting 0x1422e87a0)
    virtual CString GetTypeName();                                      //  1 0x1422e78d0 "SceneEntity"
    virtual void OnLoadInit();                                      // 20 0x1422e7d90 base, then vfunc_50 (enter)
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1422e8470
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x1422e85b0 m_30 = a new ASScene of the root
    virtual void vfunc_43();                                        // 43 0x1422e84c0 ASScene::UpdateAlignment
    virtual bool vfunc_47();                                        // 47 0x1422e7920 load the swf when shown (true)
    virtual int vfunc_48(int nPrevSceneId);                         // 48 0x1422e7b20 shown (replacing nPrevSceneId); returns the id
    virtual int vfunc_49(int nNextSceneId);                         // 49 0x1422e7bd0 hidden: leave, unload, hide the active child
    virtual void vfunc_50();                                        // 50 0x1422e7cd0 ASScene::Enter
    virtual void vfunc_51();                                        // 51 0x1422e7d30 ASScene::Leave
    virtual void vfunc_52();                                        // 52..54, 57, 58: forwarded to the active child
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();                                        // 55 0x1422e8010 ASScene::WorldLoadComplete, then the child
    virtual void vfunc_56();                                        // 56 0x1422e8110 ASScene::WorldUnLoadComplete, then the child
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59(void* p, int a, int b);                   // 59 0x1422e8390 forwarded to the active child
    virtual void vfunc_60(MS2Ptr<AScript> spBackground);            // 60 0x1422e8530 the scene's background AS object (no-op)
    virtual void vfunc_61(MS2Ptr<AScript> spBackground, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 61 0x1422e8560 (no-op)
    virtual int vfunc_62();                                         // 62 0x1422e8590 (0)
    virtual int vfunc_63();                                         // 63 0x1422e85a0 (0)
    virtual void vfunc_64() {}                                      // 64 (folded empty body 0x140e84f90)

    int FUN_1422e7930();                                            // 0x1422e7930 m_68
    int FUN_1422e7950();                                            // 0x1422e7950 m_6c the scene entity id
    int FUN_1422e7970();                                            // 0x1422e7970 m_70 shown
    int FUN_1422e7990(int nSceneId);                                // 0x1422e7990 has a child scene of the id
    void FUN_1422e7a40(int nSceneId);                               // 0x1422e7a40 switch the sub-scene (GFxSceneService)
    UISceneEntity* FUN_1422e7a70(int nSceneId);                     // 0x1422e7a70 the child scene of the id

public:
    int m_68;                                                       // +0x68 the scene it replaced when shown (0 while hidden)
    int m_6c;                                                       // +0x6c the scene entity id
    int m_70;                                                       // +0x70 shown
    ATL::CAtlList<MS2Ptr<UISceneEntity> > m_78;                     // +0x78 the child scenes
};
MS2_CHECK_OFFSET(UISceneEntity, m_68, 0x68);
MS2_CHECK_OFFSET(UISceneEntity, m_78, 0x78);
MS2_CHECK_SIZE(UISceneEntity, 0xa8);
