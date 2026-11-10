// uihairphysxdialog.h - the hair physics editor (RTTI UIHairPhysxDialog, UI id 0x4e6f, swf "HairPhysxDialog"): tunes
// the PhysX joints (soft / axis per joint, "m_joints" combo) and the transform (position / rotation, "m_transformX..Z")
// of the two pony-tail hair models of the player (left = first part, right = second part, "m_left" radio), mirrors
// the left side onto the right one ("m_mirror"), resets to the loaded pose ("m_reset") and prints the result as the
// item xml lines ("m_transform" text). NOT an original header (the unit is ?\uihairphysxdialog.cpp). Member and helper
// names are invented from use.
//
// Layout: UIDialog (0x178) + IItemCustomizeEventListener at +0x178 (vftables 0x142fafc70 / 0x142faff18 /
// 0x142faff28), size 0x2e8 (operator new in CUIService::RegisterDialogs 0x141adf580).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiTransform.h>
#include <NiPoint4.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/client/ms2/uibeautyshopstyledialog.h"     // IItemCustomizeEventListener, Customize, Unk_BSCamera
#include "ms2/client/ms2/kfmmodel.h"                    // CKfmModel, Unk_KfmPonyTail

class CItemData;
class ItemCustom;
class CEquipItem;
class ASTextField;
class UICameraEditDialog;
class ASRadioButton;        // a radio button child ("m_left", "m_position", "m_rotation")
class Unk_RankInput;         // a text input child ("m_transformX" ...)
class Unk_IbDropdown;         // a combo box child ("m_joints")

// The model facts behind CEquipModel+0x20 as this dialog reads them (CKfmModel names the same record Unk_KfmConfig):
// +0x48 the row index of the item's hair pose, +0x58 the per-row <custom> nodes of the item model, +0xb8 the four
// pony-tail joints.
struct Unk_HpxModelConfig
{
    char m_pad_00[0x48];
    int m_nIndex;                               // +0x48
    char m_pad_4c[0xc];
    std::vector<MS2Ptr<ItemCustom> > m_customs; // +0x58 the per-row <custom> nodes
    char m_pad_70[0x48];
    Unk_KfmPonyTail m_aJoints[4];               // +0xb8 name, soft, axis x/y/z
};
MS2_CHECK_OFFSET(Unk_HpxModelConfig, m_nIndex, 0x48);
MS2_CHECK_OFFSET(Unk_HpxModelConfig, m_customs, 0x58);
MS2_CHECK_OFFSET(Unk_HpxModelConfig, m_aJoints, 0xb8);

// A pony-tail hair model of the player (a CKfmModel; the CEquipModel members it calls are declared here).
class Unk_HpxModel : public CKfmModel
{
public:
};

class UIHairPhysxDialog : public UIDialog, public IItemCustomizeEventListener
{
public:
    UIHairPhysxDialog();                                // 0x141980ed0
    virtual ~UIHairPhysxDialog() = default;             // 0x141985920 (??_G 0x141985a10)
    virtual CString GetTypeName();
    virtual void vfunc_15();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    // @0x141985ca0
    virtual int vfunc_48() { return 0x4e6f; }

    // IItemCustomizeEventListener overrides: the customize controller changed the hair
    virtual int vfunc_4(void* p1, void* p2);
    virtual int vfunc_5(void* p1, void* p2);

    void FUN_141981060();                               // refresh the transform inputs (unused copy of UpdateTransformInputs)
    void SetPhysXDebugRender(int nDebug);                     // "eventPhysDebug": PhysX debug render
    void SetOnlyPonytail(int nOnly);                      // "eventOnlyPonytail"
    void EventSelectModel();                               // "eventSelectModel"
    void EventSelectTransform();                               // "eventSelectTransform"
    void FUN_141982440(const CString& strJoint);        // "eventJointsList"
    void FUN_141982480(float fSoft);                    // "eventJointsSoft"
    void SetPonyTailOffset(float fX, float fY, float fZ);   // "eventJointsAxis"
    void FUN_1419826e0(float fX, float fY, float fZ);   // "eventTransformValue"
    void FUN_141982860(const Scaleform::GFx::FunctionHandler::Params& params);    // "m_save" (empty)
    void ResetTransforms(const Scaleform::GFx::FunctionHandler::Params& params);    // "m_reset"
    void FUN_141982940(const Scaleform::GFx::FunctionHandler::Params& params);    // "m_mirror"
    void RestoreJoints();                               // restore the joints of both models from the saved maps
    void SaveJoints();                               // save the joints of both models into the maps
    int FUN_1419833e0();                                // the edited side: 2 = "m_left" checked, else 1
    int GetTransformMode();                                // the transform mode: 1 position, 2 rotation, 0 none
    CString GetSelectedJoint();                            // the joint selected in "m_joints"
    void FillJointList();                               // fill "m_joints"
    void FUN_141983af0();                               // refresh "m_softSlider"
    void FUN_141983c60();                               // refresh "m_x/y/zSlider"
    void UpdateTransformInputs();                               // refresh "m_transformX/Y/Z"
    void UpdateTransformText();                               // print the xml lines into "m_transform"
    int GetModelForSide(int nSide, Unk_HpxModel** ppModel);
    int FUN_141984af0(int nSide, Unk_HpxModel** ppLeft, Unk_HpxModel** ppRight);   // 0 both, 1 left, 2 right
    void FUN_141984c30(Unk_HpxModel* pModel, const CString& strJoint, float* pSoft);
    void GetJointOffset(Unk_HpxModel* pModel, const CString& strJoint, float* pX, float* pY, float* pZ);
    void FUN_141984da0(const NiMatrix3& kRot, efd::Point3& kDeg);           // euler angles in degrees
    void SetModelPosition(Unk_HpxModel* pModel, NiPoint3 kPos);            // move the model
    void SetModelRotation(Unk_HpxModel* pModel, NiPoint3 kDeg);            // rotate the model
    void SetModelTransform(Unk_HpxModel* pModel, const NiTransform& kXform);    // apply a whole transform


private:
    MS2_LAYOUT_FRIEND;
    NiTransform m_190;                                  // +0x190 left model pose when the page opened
    NiTransform m_1c4;                                  // +0x1c4 right model pose
    ATL::CRBMap<CString, NiPoint4> m_1f8;               // +0x1f8 left joints: soft, axis x/y/z
    ATL::CRBMap<CString, NiPoint4> m_228;               // +0x228 right joints
    NiTransform m_258[2];                               // +0x258 (unused)
    MS2Ptr<Customize> m_2c0;                            // +0x2c0 the customize controller
    UICameraEditDialog* m_2d0;                           // +0x2d0 the camera (UI 0x4ef2's object)
    MS2Ptr<CItemData> m_2d8;                            // +0x2d8 (unused)
};
MS2_CHECK_SIZE(UIHairPhysxDialog, 0x2e8);
MS2_CHECK_OFFSET(UIHairPhysxDialog, m_190, 0x190);
MS2_CHECK_OFFSET(UIHairPhysxDialog, m_1c4, 0x1c4);
MS2_CHECK_OFFSET(UIHairPhysxDialog, m_1f8, 0x1f8);
MS2_CHECK_OFFSET(UIHairPhysxDialog, m_228, 0x228);
MS2_CHECK_OFFSET(UIHairPhysxDialog, m_258, 0x258);
MS2_CHECK_OFFSET(UIHairPhysxDialog, m_2c0, 0x2c0);
MS2_CHECK_OFFSET(UIHairPhysxDialog, m_2d0, 0x2d0);
MS2_CHECK_OFFSET(UIHairPhysxDialog, m_2d8, 0x2d8);
