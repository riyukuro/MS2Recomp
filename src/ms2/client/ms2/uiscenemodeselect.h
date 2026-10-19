// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiscenemodeselect.h (name assumed).
//
// UISceneModeSelect ("SceneModeSelect", RTTI .?AVUISceneModeSelect@@, 0xa8 bytes): the scene entity (id 0x6200085) shown
// on the game-mode select screen. It has no fields of its own. Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are
// non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/gfxui/uiswfentity.h"

// UISceneEntity (0xa8): the base of every UI scene; the unit-local view this scene needs (see uiscenegamecinematicplay.h
// for the same base; vfunc_60 takes the AS object by value here).
class UISceneEntity : public UISwfEntity
{
public:
    UISceneEntity();                                            // 0x1422e7770
    virtual ~UISceneEntity();                                   //  0 0x1422e7850
    virtual void OnLoadInit();                                  // 20
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1422e8470
    virtual void vfunc_41(const Scaleform::GFx::Value& root);   // 41
    virtual void vfunc_43();                                    // 43
    virtual bool vfunc_47();                                    // 47
    virtual void vfunc_48(int n);                               // 48 0x1422e7b20 show
    virtual void vfunc_49(int n);                               // 49 0x1422e7bd0 hide
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60(MS2Ptr<AScript> spBackground);        // 60 the scene's background AS object
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual int vfunc_65() { return 0; }       // slot 65: no exe body (was a bogus symbols.tsv data row)

    void FUN_1422e7950();                                       // 0x1422e7950 the presentation ref has changed

public:
    char m_pad68[4];
    int m_6c;                                                   // +0x6c the scene entity id
    char m_pad70[0x38];
};
MS2_CHECK_SIZE(UISceneEntity, 0xa8);

class UISceneModeSelect : public UISceneEntity
{
public:
    UISceneModeSelect();                                        // 0x140e84fa0 (m_6c = 0x6200085)
    virtual ~UISceneModeSelect();                               //  0 0x140e84ff0 (??_G 0x140e854c0)
    virtual CString vfunc_1();                                  //  1 0x140e85030 "SceneModeSelect"
    virtual CString vfunc_7();                                  //  7 0x140e85080 "SceneEmpty"
    virtual int vfunc_13();                                     // 13 0x140e851e0
    virtual void vfunc_15();                                    // 15 0x140e851c0
    virtual void OnLoadComplete();                              // 22 0x140e85240
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e85350
    virtual void vfunc_48(int n);                               // 48 0x140e850d0 show: stop the intro movie
    virtual void vfunc_49(int n);                               // 49 0x140e85150 hide
    virtual void vfunc_55();                                    // 55 0x140e85190
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   //  IMessageListener 0 0x140e85300
};
MS2_CHECK_SIZE(UISceneModeSelect, 0xa8);
