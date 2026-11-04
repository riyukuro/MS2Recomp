// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiscenelobbyselect.h (name assumed).
//
// The lobby scene family (ids 0x620000d lobby, 0x620001a server select, 0x620001b character select, 0x620001c character
// create). UISceneLobby owns the three sub-scenes and registers them in its UISceneEntity child list (+0x78). Names:
// virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/sceneptr.h"

class Unk_LsBackground;

// UISceneEntity (0xa8): the base of every UI scene; the unit-local view this scene family needs (see uiscenemodeselect.h).
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
    virtual int vfunc_62();
    virtual int vfunc_63();
    virtual void vfunc_64();

    int FUN_1422e7950();                                        // 0x1422e7950 the presentation ref has changed
    void FUN_1422e7a40(int nSceneId);                           // 0x1422e7a40

public:
    char m_pad68[4];
    int m_6c;                                                   // +0x6c the scene entity id
    char m_pad70[8];
    ATL::CAtlList<Unk_ScenePtr<UISceneEntity> > m_78;           // +0x78 the child scenes
};
MS2_CHECK_SIZE(UISceneEntity, 0xa8);
MS2_CHECK_OFFSET(UISceneEntity, m_78, 0x78);

class UISceneLobby : public UISceneEntity
{
public:
    UISceneLobby();                                             // 0x141acd890 (m_6c = 0x620000d)
    virtual ~UISceneLobby();                                    //  0 0x141acda60 (??_G 0x141acdf10)
    virtual CString GetTypeName();                                  //  1 0x141acdaa0 "SceneLobby"
    virtual int vfunc_13();                                     // 13 0x141acdc70
    virtual int vfunc_14();                                     // 14 0x141acde00
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141acde60
    virtual void vfunc_48(int n);                               // 48 0x141acdaf0
    virtual void vfunc_49(int n);                               // 49 0x141acdc20
};
MS2_CHECK_SIZE(UISceneLobby, 0xa8);

class UISceneLobbyCreate : public UISceneEntity
{
public:
    UISceneLobbyCreate();                                       // 0x141acdf50 (m_6c = 0x620001c)
    virtual ~UISceneLobbyCreate();                              //  0 0x141acdfa0 (??_G 0x141ace210)
    virtual CString GetTypeName();                                  //  1 0x141acdfe0 "SceneLobbyCreate"
    virtual void vfunc_12();                                    // 12 0x141ace1b0
    virtual void OnLoadComplete();                              // 22 0x141ace030
    virtual void vfunc_48(int n);                               // 48 0x141ace0b0
    virtual void vfunc_49(int n);                               // 49 0x141ace0e0
};
MS2_CHECK_SIZE(UISceneLobbyCreate, 0xa8);

class Unk_LsCharSelect;
class UISceneLobbySelect : public UISceneEntity
{
public:
    UISceneLobbySelect();                                       // 0x141ace250 (m_6c = 0x620001b)
    virtual ~UISceneLobbySelect();                              //  0 0x141ace2b0 (??_G 0x141ace6f0)
    virtual CString GetTypeName();                                  //  1 0x141ace2f0 "SceneLobbySelect"
    virtual void vfunc_12();                                    // 12 0x141ace4d0
    virtual void OnLoadInit();                                  // 20 0x141ace520
    virtual void vfunc_48(int n);                               // 48 0x141ace340
    virtual void vfunc_49(int n);                               // 49 0x141ace370
    virtual void vfunc_57();                                    // 57 0x141ace600
    virtual void vfunc_58();                                    // 58 0x141ace470
    virtual int vfunc_62();                                     // 62 0x141ace620
    virtual int vfunc_63();                                     // 63 0x141ace670
    virtual void vfunc_64();                                    // 64 0x141ace6c0
private:
    MS2_LAYOUT_FRIEND;
    Unk_LsCharSelect* m_a8;                                     // +0xa8 the character select dialog
};
MS2_CHECK_SIZE(UISceneLobbySelect, 0xb0);
MS2_CHECK_OFFSET(UISceneLobbySelect, m_a8, 0xa8);

class UISceneLobbyServer : public UISceneEntity
{
public:
    UISceneLobbyServer();                                       // 0x141ace730 (m_6c = 0x620001a)
    virtual ~UISceneLobbyServer();                              //  0 0x141ace780 (??_G 0x141acea70)
    virtual CString GetTypeName();                                  //  1 0x141ace7c0 "SceneLobbyServer"
    virtual void OnLoadInit();                                  // 20 0x141ace8b0
    virtual void vfunc_48(int n);                               // 48 0x141ace810
    virtual void vfunc_49(int n);                               // 49 0x141ace840
    virtual void vfunc_55();                                    // 55 0x141ace970
    virtual void vfunc_60(MS2Ptr<AScript> spBackground);        // 60 0x141ace900
    virtual void vfunc_64();                                    // 64 0x141ace9a0

    void FUN_141ace9e0();                                       // 0x141ace9e0
};
MS2_CHECK_SIZE(UISceneLobbyServer, 0xa8);
