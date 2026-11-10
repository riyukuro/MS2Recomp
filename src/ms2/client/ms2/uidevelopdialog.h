// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
//
// UIDevelopDialog: the debug "DevelopDialog" (Debug_UI swf, UI type 0x4eb1) with check boxes for PhysX debug
// rendering, effects, mesh instancing and property visualisation, game speed / scale sliders and the drop-item
// height / period inputs. RTTI .?AVUIDevelopDialog@@, 0x188 bytes (vftables 0x142f5c1f8 and the IMessageListener one
// at +0x18).
// Names: virtuals are Ghidra's vfunc_<slot> where the base does so; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASData;

class UIDevelopDialog : public UIDialog
{
public:
    UIDevelopDialog();                                                                              // 0x1412920b0
    virtual ~UIDevelopDialog();                                                                     //  0 0x141292150
    virtual CString GetTypeName();                                                                      //  1 0x141292190
    virtual void OnLoadComplete();                                                                  // 22 0x1412921e0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x1412924f0
    virtual int vfunc_48() { return 0x4eb1; }                                                       // 48 (COMDAT 0x141293c90)

    void SetChildText(const CString& strName, const CStringW& strText);    // set the text of a child text field
    void OnClickReloadNpcExtent();               // "onClickReloadNpcExtent": resize every npc to its data record extent
    void OnClickClearDebugInfo();               // "onClickClearDebugInfo"
    void OnClickResetGameSpeed(ASData& data);   // "onClickResetGameSpeed": the AS side's defaultSpeed = 1
    void OnCheckPhysXDebugRender(bool bOn);       // "OnCheckPhysXDebugRender": both PhysX scenes
    void OnCheckEnableEffect(bool bOn);       // "OnCheckEnableEffect"
    void OnCheckShowInstancing(bool bOn);       // "OnCheckShowInstancing"
    void OnCheckPropertyVisualizer(bool bOn);       // "OnCheckPropertyVisualizer"
    void OnCheckOneInstancing(bool bOn, int nIndex);   // "OnCheckOneInstancing"
    void OnChangeSliderDropItemScale(float fScale);   // "OnChangeSliderDropItemScale"
    void OnChangeSliderGameSpeed(float fSpeed);   // "OnChangeSliderGameSpeed"
    void OnChangeSliderCharacterScale(float fScale);   // "OnChangeSliderCharacterScale"
    void OnChangeSliderInstancing(int nIndex);     // "OnChangeSliderInstancing"
    void OnClickApplyDropItemHeight(float fHeight);  // "OnClickApplyDropItemHeight"
    void OnClickApplyDropItemPeriod(float fPeriod);  // "OnClickApplyDropItemPeriod"

private:
    MS2_LAYOUT_FRIEND;
    bool m_bShowInstancing;             // +0x178
    bool m_bOneInstancing;              // +0x179
    bool m_bPropertyVisualizer;         // +0x17a
    float m_fDropItemHeight;            // +0x17c
    float m_fDropItemPeriod;            // +0x180
};
MS2_CHECK_SIZE(UIDevelopDialog, 0x188);
