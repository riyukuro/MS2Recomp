// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiscenegamecinematicplay.h (name
// assumed: the .cpp's __FILE__ string is not in the exe for this unit).
//
// UISceneGameCinematicPlay ("SceneGameCinematicPlay", UI type 0x4e59, RTTI .?AVUISceneGameCinematicPlay@@, 0xa8 bytes):
// the scene entity that plays the in-game cinematic 0x620007f (m_6c) - the cut scene the story quests launch. It has no
// fields of its own; showing it (vfunc_48) switches the scene's world/presentation to the cinematic and hiding it
// (vfunc_49) switches back. Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/gfxui/uiswfentity.h"

// UISceneEntity (0xa8): the base of every UI scene (the primary vtable carries 19 extra slots, 47..65). The exe's
// UIScene*.cpp units are not recovered yet (see the stand-in declarations in ms2.cpp, mypc.cpp, scenestategame.cpp);
// this is the shape the subclass below needs: the new slots, and the entity id at +0x6c.
class UISceneEntity : public UISwfEntity
{
public:
    UISceneEntity();                                            // 0x1422e7770
    virtual ~UISceneEntity();                                   //  0 0x1422e7850
    virtual void OnLoadInit();                                  // 20 0x1422e7d90 the base's
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1422e8470
    virtual void vfunc_41(const Scaleform::GFx::Value& root);   // 41 0x1422e85b0
    virtual void vfunc_43();                                    // 43 0x1422e84c0
    virtual bool vfunc_47();                                    // 47
    virtual void vfunc_48(int n);                               // 48 0x1422e7b20 show
    virtual void vfunc_49(int n);                               // 49 0x1422e7bd0 hide
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();                                    // 52 0x1422e7dd0
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64() {}                                  // 64 0x140e84f90 emitted from this unit
    virtual int vfunc_65() { return 0; }       // slot 65: no exe body (was a bogus symbols.tsv data row)

    void FUN_1422e7950();                                       // 0x1422e7950 the presentation ref has changed

public:
    char m_pad68[4];
    int m_6c;                                                   // +0x6c the scene entity id (this scene's: 0x620007f)
    char m_pad70[0x38];
};
MS2_CHECK_SIZE(UISceneEntity, 0xa8);

class UISceneGameCinematicPlay : public UISceneEntity
{
public:
    UISceneGameCinematicPlay();                                 // 0x140e84cd0 (m_6c = 0x620007f)
    virtual ~UISceneGameCinematicPlay();                        //  0 0x140e84d20 (??_G 0x140e84f40)
    virtual CString GetTypeName();                                  //  1 0x140e84d60 "SceneGameCinematicPlay"
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e84ef0
    virtual bool vfunc_47();                                    // 47 0x140e84db0 returns false
    virtual void vfunc_48(int n);                               // 48 0x140e84dc0 show: cinematic presentation on
    virtual void vfunc_49(int n);                               // 49 0x140e84e30 hide: cinematic presentation off
    virtual void vfunc_52();                                    // 52 0x140e84ed0 the base's
    virtual void vfunc_54();                                    // 54 0x140e84ea0 the scene manager's "camera off"
    virtual int vfunc_65() { return 0x4e59; }                   // 65 0x140e84f80 UI type id
};
MS2_CHECK_SIZE(UISceneGameCinematicPlay, 0xa8);
