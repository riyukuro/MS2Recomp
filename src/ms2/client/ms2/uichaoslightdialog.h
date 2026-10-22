// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
//
// UIChaosLightDialog: a debug dialog (UI type 0x4eac, "ChaosLightDialog") with sliders for the chaos light effect
// (fresnel boost / exponent, dimmer, colour) and an apply checkbox. Edits a ChaosLightEffectParam that overrides the
// param of every chaos light effect while "apply" is on (ChaosLightEffect::vfunc_3 takes the override then).
// RTTI .?AVUIChaosLightDialog@@, 0x188 bytes, vftables 0x142ea2640 (84 slots) and 0x142ea28e8 (IMessageListener at +0x18).
// This unit also holds the ChaosLightEffect functions (effect XML type 0xe; class in chaoslighteffect.h) and the
// node walker class the texture-layer effects share.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/chaoslighteffect.h"
#include <NiNode.h>

class ASData;

// Breadth-first walk over a node's subtree (0x30 bytes). Shared with TextureOverrideEffect (its own declaration).
class Unk_NodeWalker
{
public:
    Unk_NodeWalker(NiAVObject* pRoot);                              // 0x141043760
    ~Unk_NodeWalker();                                              // 0x1410439e0
    NiAVObject* FUN_1410446c0(bool bChildren);                      // 0x1410446c0 next node, NULL at the end
    void FUN_1410447b0(NiAVObject* pRoot);                          // 0x1410447b0 restart at pRoot
    void FUN_141044210(NiNode* pNode);                              // 0x141044210 queue the children
private:
    ATL::CAtlList<NiAVObject*> m_list;
};
MS2_CHECK_SIZE(Unk_NodeWalker, 0x30);

const ChaosLightEffectParam* FUN_141041e90();                       // 0x141041e90 the override param
void FUN_141041ea0(const ChaosLightEffectParam* pParam);            // 0x141041ea0 set it, refresh the running effects
void FUN_1410420a0(bool bApply);                                    // 0x1410420a0 apply flag
bool FUN_1410420c0();                                               // 0x1410420c0

class UIChaosLightDialog : public UIDialog
{
public:
    UIChaosLightDialog();                                                                           // 0x141040a30
    virtual ~UIChaosLightDialog();                                                                  //  0 0x141040af0
    virtual CString GetTypeName();                                                                      //  1 0x141040b40
    virtual void OnLoadComplete();                                                                  // 22 0x141040b90
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x141040d20
    virtual int vfunc_48() { return 0x4eac; }                                                       // 48 (COMDAT 0x141041370)

    void FUN_1410411e0(bool bApply);    // 0x1410411e0 set the apply flag; on: push the edited param to the running effects

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ChaosLightEffectParam> m_spParam;    // +0x178 the edited param (starts with the defaults)
};
MS2_CHECK_SIZE(UIChaosLightDialog, 0x188);
MS2_CHECK_OFFSET(UIChaosLightDialog, m_spParam, 0x178);
