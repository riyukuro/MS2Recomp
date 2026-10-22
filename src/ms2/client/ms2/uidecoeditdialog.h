// uidecoeditdialog.h - UIDecoEditDialog (RTTI .?AVUIDecoEditDialog@@, 0x178 bytes, UIDialog, UI id 0x4e2c,
// swf "DecoEditDialog"): the housing "deco" painting editor's window. The movie lists the DecoEditService's
// layers ("m_layers") and brushes ("m_brushes") and reports the user's edits ("OnSave", "OnLayerInsert", "OnBrush..."),
// which are forwarded to the service. Owning unit: ?\uidecoeditdialog.cpp (0x14191b380-0x14191c7c0, dir client\ms2);
// header name assumed from the unit path.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"

class Unk_DeList;
struct Unk_DeVec2;

class UIDecoEditDialog : public UIDialog
{
public:
    UIDecoEditDialog();                                         // 0x14191b380
    virtual ~UIDecoEditDialog() = default;                      //  0 0x14191c4f0 (??_G 0x14191c5f0)
    virtual CString GetTypeName();                                  //  1 0x14191b3d0 "DecoEditDialog"
    virtual void OnLoadInit();                                  // 20 0x14191b490 fill the layer and brush lists
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x14191b860 the movie's edit events
    virtual int vfunc_48() { return 0x4e2c; }                   // 48 0x14191c6a0
    virtual int vfunc_65();                                     // 65 0x14191b420
    virtual void vfunc_67();                                    // 67 0x14191b460

    void FUN_14191bd30(CString strFile);                        // OnAssetChange: pick the model file of the layer
    void FUN_14191c060(CString strName);                        // OnLayerInsert
    void FUN_14191c0d0(CString strName);                        // OnLayerDelete
    void FUN_14191c140(CString strName);                        // OnLayerChange
    void FUN_14191c1b0(int nBrush);                             // OnBrushChange
    void FUN_14191c1e0(float fRadius);                          // OnBrushRadiusChange
    void FUN_14191c230(float fDensity);                         // OnBrushDensityChange
    void FUN_14191c280(Unk_DeVec2 vScale);                      // OnBrushScaleChange
    void FUN_14191c2d0(Unk_DeVec2 vRotation);                   // OnBrushRotationChange

    MS2Ptr<Unk_DeList> FUN_140c02900(const CString& strName);   // bind a list child
};
MS2_CHECK_SIZE(UIDecoEditDialog, 0x178);
