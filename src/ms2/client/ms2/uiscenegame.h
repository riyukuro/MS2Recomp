// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiscenegame.h (name assumed).
//
// The in-game scene family: UISceneGame (id 0x620000c) owns six sub-scenes and registers them in its UISceneEntity child
// list (+0x78): UISceneGamePlay (0x620001d, the HUD), UISceneGameBeautyShop (0x620001f), UISceneGameCinematicTalk
// (0x6200031), UISceneGameScreenShot (0x6200020), UISceneGameCinematicCutScene (0x6200041) and UISceneGameCinematicPlay
// (0x620007f, recovered in uiscenegamecinematicplay.cpp). Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are
// non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <egf/EntityID.h>

#include "ms2/ms2layout.h"
#include "ms2/gfxui/uiswfentity.h"

struct Unk_StreamPoint;
class NotifyObject;

class Unk_GsRef { public: void FUN_14015b020(); int FUN_140159bc0(); void FUN_140159ba0(); };

// The 16-byte intrusive smart pointer (pointee at +8) of a scene in the child list (ctor 0x141ac79a0, copy 0x141ac7960,
// dtor 0x141ac7a00).
template<class T> class Unk_ScenePtr {
public:
    Unk_ScenePtr() : p(0) {}
    Unk_ScenePtr(T* value) : p(value) { AddRef(); }
    Unk_ScenePtr(const Unk_ScenePtr& o) : p(o.p) { AddRef(); }
    ~Unk_ScenePtr() { Release(); }
    Unk_ScenePtr& operator=(const Unk_ScenePtr& o) { o.AddRef(); Release(); p = o.p; return *this; }
    T* get() const { return p; }
    T* operator->() const { return p; }
private:
    void AddRef() const { if(p) AddRefImpl(0); }
    static void AddRefObject(T* value) { reinterpret_cast<Unk_GsRef*>(value)->FUN_14015b020(); }
    void AddRefImpl(void*) const { AddRefObject(p); }
    void Release() { if(p) { ReleaseImpl(0); p=0; } }
    void ReleaseImpl(void*) { if(reinterpret_cast<Unk_GsRef*>(p)->FUN_140159bc0()==0) { AddRefObject(p); reinterpret_cast<Unk_GsRef*>(p)->FUN_140159ba0(); } }
    void* pad_00; T* p;
};

class UISceneEntity;
typedef ATL::CAtlList<Unk_ScenePtr<UISceneEntity> > Unk_GsSceneList;

// UISceneEntity (0xa8): the base of every UI scene; the unit-local view this scene family needs (see uiscenelobbyselect.h).
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

    void FUN_1422e7950();                                       // 0x1422e7950 the presentation ref has changed
    void FUN_1422e7a40(int nSceneId);                           // 0x1422e7a40

public:
    char m_pad68[4];
    int m_6c;                                                   // +0x6c the scene entity id
    char m_pad70[8];
    Unk_GsSceneList m_78;                                       // +0x78 the child scenes
};
MS2_CHECK_SIZE(UISceneEntity, 0xa8);
MS2_CHECK_OFFSET(UISceneEntity, m_78, 0x78);

class UISceneGame : public UISceneEntity
{
public:
    UISceneGame();                                              // 0x141ac6fa0 (m_6c = 0x620000c)
    virtual ~UISceneGame();                                     //  0 0x141ac7310 (??_G 0x141ac7a30)
    virtual CString vfunc_1();                                  //  1 0x141ac7350 "SceneGame"
    virtual int vfunc_13();                                     // 13 0x141ac7650
    virtual int vfunc_14();                                     // 14 0x141ac7830
    virtual void vfunc_15();                                    // 15 0x141ac7620
    virtual void vfunc_48(int n);                               // 48 0x141ac73a0
    virtual void vfunc_49(int n);                               // 49 0x141ac74f0
    virtual void vfunc_55();                                    // 55 0x141ac78a0
    virtual void vfunc_56();                                    // 56 0x141ac78f0
};
MS2_CHECK_SIZE(UISceneGame, 0xa8);

class UISceneGameBeautyShop : public UISceneEntity
{
public:
    UISceneGameBeautyShop();                                    // 0x141ac7ec0 (m_6c = 0x620001f)
    virtual ~UISceneGameBeautyShop();                           //  0 0x141ac7f60 (??_G 0x141ac92d0)
    virtual CString vfunc_1();                                  //  1 0x141ac7fc0 "SceneGameBeautyShop"
    virtual int vfunc_13();                                     // 13 0x141ac8340
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141ac8370
    virtual void vfunc_48(int n);                               // 48 0x141ac8010
    virtual void vfunc_49(int n);                               // 49 0x141ac8130
    virtual void vfunc_50();                                    // 50 0x141ac8290
    virtual void vfunc_52();                                    // 52 0x141ac8310
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141ac84a0

    void FUN_141ac8660();                                       // 0x141ac8660 camera: back to the follow mode
    void FUN_141ac8710();                                       // 0x141ac8710
    void FUN_141ac87b0();                                       // 0x141ac87b0 camera: beauty shop view
    void FUN_141ac8900();                                       // 0x141ac8900
    void FUN_141ac8b00(Unk_StreamPoint* pPos, Unk_StreamPoint* pLook, Unk_StreamPoint* pOut);   // 0x141ac8b00
    void FUN_141ac8e70(int nDialogMode);                        // 0x141ac8e70 m_a8 = n
    void FUN_141ac8e90();                                       // 0x141ac8e90
    void FUN_141ac9270();                                       // 0x141ac9270

private:
    MS2_LAYOUT_FRIEND;
    int m_a8;                                                   // +0xa8
    int m_ac;                                                   // +0xac the open dialog (UI id)
    int m_b0;                                                   // +0xb0 npc object id
    int m_b4;                                                   // +0xb4 npc object id
    CString m_b8;                                               // +0xb8 cube id
};
MS2_CHECK_SIZE(UISceneGameBeautyShop, 0xc0);
MS2_CHECK_OFFSET(UISceneGameBeautyShop, m_b8, 0xb8);

class UISceneGameCinematicCutScene : public UISceneEntity
{
public:
    UISceneGameCinematicCutScene();                             // 0x141ac9430 (m_6c = 0x6200041)
    virtual ~UISceneGameCinematicCutScene();                    //  0 0x141ac9480 (??_G 0x141ac9770)
    virtual CString vfunc_1();                                  //  1 0x141ac94c0 "SceneGameCinematicCutScene"
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141ac9720
    virtual bool vfunc_47();                                    // 47 0x141ac9510
    virtual void vfunc_48(int n);                               // 48 0x141ac9520
    virtual void vfunc_49(int n);                               // 49 0x141ac9620
    virtual void vfunc_52();                                    // 52 0x141ac9700
    virtual void vfunc_54();                                    // 54 0x141ac96d0
    virtual int vfunc_65();                                     // 65 0x141ac97b0 0x4e58
};
MS2_CHECK_SIZE(UISceneGameCinematicCutScene, 0xa8);

class UISceneGameCinematicTalk : public UISceneEntity
{
public:
    UISceneGameCinematicTalk();                                 // 0x141ac97c0 (m_6c = 0x6200031)
    virtual ~UISceneGameCinematicTalk();                        //  0 0x141ac9810
    virtual CString vfunc_1();                                  //  1 0x141ac9850 "SceneGameCinematicTalk"
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141ac9ab0
    virtual void vfunc_48(int n);                               // 48 0x141ac98a0
    virtual void vfunc_49(int n);                               // 49 0x141ac99b0
    virtual void vfunc_52();                                    // 52 0x141ac9a90
    virtual int vfunc_65();                                     // 65 0x141ac9c00 0x4e3f
private:
    MS2_LAYOUT_FRIEND;
    int m_a8;                                                   // +0xa8
    int m_ac;                                                   // +0xac
    float m_b0;                                                 // +0xb0
    int m_b4;                                                   // +0xb4
};
MS2_CHECK_SIZE(UISceneGameCinematicTalk, 0xb8);

// A UI id (a plain enum: ATL passes enum elements by reference, unlike int, which the exe's Add(0x141accb50) shows).
enum Unk_GsUiId { Unk_GsUiId_Max = 0x7fffffff };

class UISceneGamePlay : public UISceneEntity
{
public:
    UISceneGamePlay();                                          // 0x141ac9d30 (m_6c = 0x620001d)
    virtual ~UISceneGamePlay();                                 //  0 0x141ac9e80 (??_G 0x141accb10)
    virtual CString vfunc_1();                                  //  1 0x141ac9ed0 "SceneGamePlay"
    virtual void vfunc_11();                                    // 11 0x141aca1a0
    virtual int vfunc_13();                                     // 13 0x141aca270 the debug hotkeys
    virtual int vfunc_14();                                     // 14 0x141aca2b0
    virtual void vfunc_15();                                    // 15 0x141aca3b0
    virtual void vfunc_34(void* p, float x, float y);           // 34 0x141aca480
    virtual void vfunc_48(int n);                               // 48 0x141ac9f20
    virtual void vfunc_49(int n);                               // 49 0x141aca0d0
    virtual void vfunc_55();                                    // 55 0x141aca4e0
    virtual void vfunc_56();                                    // 56 0x141aca500
    virtual void vfunc_58();                                    // 58 0x141aca570

    void FUN_141aca840(int nUiId);                              // 0x141aca840 remember a dialog to close on the next show
    void FUN_141acc510(NotifyObject* pNotify);                  // 0x141acc510 NotifyChangeEnableFeature handler

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<Unk_GsUiId> m_a8;                            // +0xa8 (0x20)
    int m_c8;                                                   // +0xc8
    int m_cc;                                                   // +0xcc
};
MS2_CHECK_SIZE(UISceneGamePlay, 0xd0);

class UISceneGameScreenShot : public UISceneEntity
{
public:
    UISceneGameScreenShot();                                    // 0x141acd1c0 (m_6c = 0x6200020)
    virtual ~UISceneGameScreenShot();                           //  0 0x141acd820 (??_G 0x141acd850)
    virtual CString vfunc_1();                                  //  1 0x141acd230 ""
    virtual int vfunc_13();                                     // 13 0x141acd750
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141acd7d0
    virtual bool vfunc_47();                                    // 47 0x141acd280
    virtual void vfunc_48(int n);                               // 48 0x141acd290 hide the character entities
    virtual void vfunc_49(int n);                               // 49 0x141acd5e0 show them again
    virtual void vfunc_57();                                    // 57 0x141acd730
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<egf::EntityID> m_a8;                          // +0xa8 the hidden entities (0x30)
};
MS2_CHECK_SIZE(UISceneGameScreenShot, 0xd8);

// UISceneGameCinematicPlay (0xa8) is recovered in uiscenegamecinematicplay.cpp; only its ctor is used here.
class UISceneGameCinematicPlay : public UISceneEntity
{
public:
    UISceneGameCinematicPlay();                                 // 0x140e84cd0
    virtual ~UISceneGameCinematicPlay();
};
MS2_CHECK_SIZE(UISceneGameCinematicPlay, 0xa8);
