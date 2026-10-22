// uiloadingprogress.h - UILoadingProgress (RTTI .?AVUILoadingProgress@@, 0x80 bytes, UIObject + IWorldServiceCallback at
// +0x68; "LoadingProgress" swf, ui id 0x3ed) and its subclass UILoadingProgressLobby (the lobby variant, "LoadingProgressLobby").
// The full-screen loading bar shown between maps. Owning unit: ?\uiloadingprogress.cpp (0x1419df870-0x1419e0cb0). Header
// name assumed from the unit path. Member names are invented from use.
#pragma once
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/postprocesseffect.h"
#include "ms2/placeholder/tptr.h"

class Unk_UISwfEntity_25;

class UILoadingProgress : public UIObject, public IWorldServiceCallback
{
public:
    UILoadingProgress();                                            // 0x1419df870
    virtual ~UILoadingProgress();                                   //  0 0x1419df960 (??_G 0x1419e0ad0)
    virtual CString GetTypeName();                                      //  1 0x1419dfa10 "LoadingProgress"
    virtual void vfunc_2();                                         //  2 0x1419e0130 load the swf with this UI's layer
    virtual void vfunc_3();                                         //  3 0x1419e0160
    virtual void vfunc_16();                                        // 16 0x1419e0280 drop the background texture
    virtual bool vfunc_17();                                        // 17 0x1419e02b0 rebuild the background texture
    virtual void OnLoadComplete();                                  // 22 0x1419e02e0
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);   // 25 0x1419e03a0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419e0320
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x1419e0550 movie loaded: m_30 = movie clip
    // @0x1419e0b50
    virtual int vfunc_48() { return 0x3ed; }                        // 48
    virtual int vfunc_52();                                         // 52 0x1419e05c0 false on the login / char-select scenes
    // IWorldServiceCallback slot 2 (the subobject is at +0x68): the map load failed
    virtual void vfunc_2(int nMap, CString strMessage);             //  o68 slot 2 0x1419e0180 "loadFail"

    void FUN_1419dfa60(int nMap);                                   // start the progress bar (nMap: the target map, 0 = current)
    void FUN_1419dfd90();                                           // stop the progress bar
    bool FUN_1419dfe70();                                           // the map has its own loading screen
    void FUN_1419dff50(const CStringW& strMsg, int a, int b);       // "progress" text
    void FUN_1419e0050(const CStringW& strMsg);                     // "setMoveChannelMessage"
    int FUN_1419e04b0();                                            // the map id (0 on the scene 0x620000d)
    int FUN_1419e04f0();                                            // the target map id
    bool FUN_1419e0630();                                           // m_74 != 0
    CString FUN_1419e0650();                                        // the map's mask image path
    CString FUN_1419e0710();                                        // the map's loading image path
    void FUN_1419e07a0();                                           // draw the background texture into the back buffer
    void FUN_1419e08b0(int nWidth, int nHeight);                    // create the background texture

private:
    int m_70;                                                       // +0x70 the previous target map
    int m_74;                                                       // +0x74 the current target map
    Unk_PPSmartA m_78;                                              // +0x78 the background texture (NiRenderedTexture smart pointer)
};
MS2_CHECK_SIZE(UILoadingProgress, 0x80);

class UILoadingProgressLobby : public UILoadingProgress
{
public:
    UILoadingProgressLobby();                                       // 0x1419e0920
    virtual ~UILoadingProgressLobby();                              //  0 0x1419e0990 (??_G 0x1419e0b10)
    virtual CString GetTypeName();                                      //  1 0x1419e09e0 "LoadingProgressLobby"
    virtual CString vfunc_7();                                      //  7 0x1419e0a30 "LoadingProgress" (the swf name)
    // @0x1419e0b60
    virtual int vfunc_48() { return 0x3ef; }                        // 48
    virtual int vfunc_52();                                         // 52 0x1419e0a80 always false
};
MS2_CHECK_SIZE(UILoadingProgressLobby, 0x80);
