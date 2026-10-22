// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed from the unit path.
//
// Texture animations (?\textureanimationdata.cpp): CTextureAnimationData is the parsed <texture> list of an animation
// XML (file / control / delay per frame, the loop start frame); CTextureAnimation plays one on a node of a character:
// it keeps the per-frame base and map textures, a TextureLayer registered with the world's TextureLayerManager and the
// clock. UITextureDensityDialog is a debug dialog ("TextureDensityDialog") for the texture density processor.
// TextureLayer / TextureLayerManager are the Layer / LayerManager subclasses of the world's texture layer system.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <vector>
#include <NiAVObject.h>
#include <NiTexturingProperty.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/postprocesseffect.h"      // Unk_PPSmartC (texture handle)
#include "ms2/placeholder/uidialog.h"
#include "ms2/client/ms2/layer.h"
#include "ms2/client/ms2/itempickinghelper.h"       // Unk_PickMeshPtr (scene node pointer)

class Unk_140165cf0;     // game TinyXML element
class PCBase;

// One <texture> element of the animation XML (0x18 bytes). The control texture is optional.
struct Unk_TextureFrame
{
    Unk_TextureFrame();                                         // 0x141847510
    ~Unk_TextureFrame();                                        // 0x141849de0
    void Load(Unk_140165cf0* pNode);                   // read "file", "control" and "delay"
    void FUN_1418475d0(const CString& strDir, int nFlags);      // load the textures into the resource manager
    bool FUN_1418476e0(const CString& strDir);                  // both textures are loaded
    void FUN_141847880(const CString& strDir);                  // queue the textures in the file preload
    CString FUN_141847960(const CString& strDir);               // resource path of the base texture
    CString FUN_141847a60(const CString& strDir);               // resource path of the control (map) texture, "" if none
    bool FUN_141847bb0();                                       // has a control texture
    int GetDelay();                                        // delay of the frame (ms)

    CString m_strFile;                  // +0x00 "file"
    CString m_strControl;               // +0x08 "control"
    int m_nDelay;                       // +0x10 "delay"
};
MS2_CHECK_SIZE(Unk_TextureFrame, 0x18);

// 0x48 bytes, RTTI .?AVCTextureAnimationData@@ (one vftable slot: the CPtred destructor).
class CTextureAnimationData : public CPtred
{
public:
    CTextureAnimationData();                                    // 0x141847c20
    virtual ~CTextureAnimationData() = default;                 //  0 0x141849da0 (implicit) (??_G 0x14184a090)

    int FUN_141847c90(int nTime);                               // frame index at the given time
    bool FUN_141847e30(Unk_140165cf0* pNode);                   // parse "target" and the <texture> list; false when empty
    int FUN_141847fe0(const CString& strDir);                   // all frames loaded
    void FUN_141848080(const CString& strDir, int nFlags);      // load all frames
    Unk_PPSmartC FUN_141848110(unsigned int nFrame, const CString& strDir);   // base texture of a frame
    Unk_PPSmartC FUN_141848200(unsigned int nFrame, const CString& strDir);   // control texture of a frame

public:
    CString m_strTarget;                                        // +0x18 "target" (node name; default "Scene Root"-style first face part)
    int m_nLoopFrame;                                           // +0x20 frame the animation loops back to (-1: none)
    ATL::CAtlArray<Unk_TextureFrame> m_arrFrames;               // +0x28
};
MS2_CHECK_SIZE(CTextureAnimationData, 0x48);
MS2_CHECK_OFFSET(CTextureAnimationData, m_arrFrames, 0x28);

// 0x88 bytes, RTTI .?AVCTextureAnimation@@. The player of a CTextureAnimationData on a character (PCBase +0x638).
class CTextureAnimation : public CPtred
{
public:
    explicit CTextureAnimation(PCBase* pOwner);                 // 0x1418482f0
    virtual ~CTextureAnimation();                               //  0 0x1418483e0 (??_G 0x14184a050)

    void FUN_1418484a0(MS2Ptr<CTextureAnimationData> spData, const CString& strDir);   // start playing
    void FUN_141848650();                                       // stop: remove the layer, reset the clock
    bool FUN_141848740(int nElapsed);                           // advance the clock; false when finished
    void FUN_141848890(unsigned int nFrame);                    // show a frame
    Unk_PPSmartC FUN_141848bb0(unsigned int nFrame);            // cached base texture of a frame
    Unk_PPSmartC FUN_141848dc0(unsigned int nFrame);            // cached control texture of a frame
    NiAVObject* FUN_141849060(const CString& strName);          // find the target node of the owner
    unsigned int FUN_141849150();                               // frame count
    void FUN_141849190();                                       // load every frame's textures
    void FUN_141849210();                                       // queue every frame in the file preload

public:
    PCBase* m_pOwner;                                           // +0x18
    MS2Ptr<CTextureAnimationData> m_spData;                     // +0x20
    std::vector<Unk_PPSmartC> m_vecBase;                        // +0x30 base texture per frame (lazy)
    std::vector<Unk_PPSmartC> m_vecMap;                         // +0x48 control texture per frame (lazy)
    CString m_strDir;                                           // +0x60 texture directory
    int m_nFrame;                                               // +0x68 shown frame (-1: none)
    int m_nState;                                               // +0x6c 0 idle, 1 loading, 2 playing
    int m_nTime;                                                // +0x70 clock (ms)
    NiPointer<class TextureLayer> m_spLayer;                    // +0x78
    Unk_PickMeshPtr m_spNode;                                   // +0x80 target node
};
MS2_CHECK_SIZE(CTextureAnimation, 0x88);
MS2_CHECK_OFFSET(CTextureAnimation, m_spNode, 0x80);

// Debug dialog for the texture density processor ("TextureDensityDialog", UI type 0x4eaa), 0x180 bytes.
class UITextureDensityDialog : public UIDialog
{
public:
    UITextureDensityDialog();                                   // 0x14184ac20
    virtual ~UITextureDensityDialog();                          //  0 0x14184aca0 (??_G 0x14184aff0)
    virtual CString vfunc_1();                                  //  1 0x14184ad50
    virtual void OnLoadComplete();                              // 22 0x14184ace0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14184ada0
    virtual int vfunc_48() { return 0x4eaa; }                   // 48 (COMDAT 0x14184b030)

public:
    bool m_bEnable;                                             // +0x178 "onCheckEnable"
    int m_nMode;                                                // +0x17c "onChangeRadio"
};
MS2_CHECK_SIZE(UITextureDensityDialog, 0x180);
MS2_CHECK_OFFSET(UITextureDensityDialog, m_bEnable, 0x178);

// 0x30 bytes. Vftable: the Layer slots, 18 = the texturing property the layer works on, 19 apply (set the textures).
// Created by the world's TextureLayerManager (kind 0: from a texturing property) or by CTextureAnimation (kind 1).
class TextureLayer : public Layer
{
public:
    TextureLayer(int nKind, NiProperty* pTexturing, void* pBase, void* pMap);   // 0x14184b040
    virtual ~TextureLayer() = default;                          //  0 0x14184b370 (implicit) (??_G 0x14184b3c0)
    virtual NiAVObject* vfunc_18();                             // 18 0x14184b110 the texturing property (a property, not a node)
    virtual void vfunc_19();                                    // 19 0x14184b1a0 apply the base / map textures
    void FUN_14184b140(void* pBase);                            // replace the base texture
    void FUN_14184b170(void* pMap);                             // replace the map texture

public:
    Unk_PPSmartC m_spBase;                                      // +0x18 base texture
    Unk_PPSmartC m_spMap;                                       // +0x20 map texture (shader map 0)
    NiPointer<NiTexturingProperty> m_spTexturing;               // +0x28
};
MS2_CHECK_SIZE(TextureLayer, 0x30);
typedef NiPointer<TextureLayer> TextureLayerPtr;

// The world's texture layer manager (WorldService +0x810; ctor 0x141bf48f0 COMDAT elsewhere), 0x20 bytes.
class TextureLayerManager : public LayerManager
{
public:
    virtual NiPointer<Layer> vfunc_18(NiAVObject* pObject);     // 18 0x14184b230 a TextureLayer for the node's texturing property
};
MS2_CHECK_SIZE(TextureLayerManager, 0x20);
