// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDecoEditDialog: see uidecoeditdialog.h.
// MS2-UNIT: ?\uidecoeditdialog.cpp
// MS2-RANGE: 0x14191b380-0x14191c7c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??1UIDecoEditDialog@@UEAA@XZ 0x14191c4f0
// MS2-PIN: ??_GUIDecoEditDialog@@UEAAPEAXI@Z 0x14191c5f0
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidecoeditdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uidecoeditdialog.h"
#include <atlcoll.h>
#include <stdlib.h>
#include <NiMesh.h>
#include <NiNode.h>
#include "ms2/client/ms2/decoeditservice.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"


// ---- unit-local views of exe objects ----

// "m_layers" / "m_brushes": a list of rows or names.
class Unk_DeList : public ASDisplayObject
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bVisible);
    void FUN_1422dd230(const ASObj& row);                       // append a row
    void FUN_1422dcca0(int nIndex);                             // select a row
    void FUN_1422dd2a0(const CString& strName);                 // append a name
};

class ASDialog : public ASDisplayObject
{
};

// The movie root with the one-string Invoke.
class Unk_DeScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_14191c3d0(const char* szMethod, const wchar_t* pszArg);
};

// A 2D vector built in place (the scale / rotation of a brush).
struct Unk_DeVec2
{
    float m_x;
    float m_y;
    Unk_DeVec2* FUN_140a0a600(float x, float y);
};

// The brush interface: slots 6-9 with the types the dialog passes.
class Unk_DeBrush
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void vfunc_6(float fRadius);
    virtual void vfunc_7(float fDensity);
    virtual void vfunc_8(Unk_DeVec2 vScale);
    virtual void vfunc_9(Unk_DeVec2 vRotation);
};

DecoEditService* FUN_1411987a0();                                       // the deco edit service
AScript* FUN_140ba7c60(void* pRef);                                     // the movie root
CString FUN_140188f50(const char* psz, int nCodePage);                  // narrow string from a char*
CString FUN_1401d4330(const wchar_t* psz, int nCodePage);               // narrow string from a wide one
bool FUN_1401647e0(const CString& a, const CString& b);                 // case-insensitive equal
CStringW FUN_141b6e360(const CStringW& strInitialDir, const wchar_t* pszFilter, const CStringW& strDefaultFile);   // open-file dialog
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_14191c320(CStringW& strPath);                                 // drop the "Model" prefix of a path
bool FUN_14191c510(CString& strA, const wchar_t* pszB);                // strA equals pszB

// @0x14191b380
UIDecoEditDialog::UIDecoEditDialog()
{
    m_40 = 1;
}

// @0x14191b3d0
CString UIDecoEditDialog::GetTypeName()
{
    return "DecoEditDialog";
}

// MS2-FUNCTIONAL: the vfunc call result is kept in a temp differently
// @0x14191b420
int UIDecoEditDialog::vfunc_65()
{
    int nResult = UIDialog::vfunc_65();
    if (nResult != 0)
        FUN_1411987a0()->SetBrush(0);
    return nResult != 0;
}

// @0x14191b460
void UIDecoEditDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_1411987a0()->SetBrush(2);
}

// MS2-FUNCTIONAL: MS2Ptr/CAtlArray temporaries and the list calls are laid out differently
// @0x14191b490
void UIDecoEditDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    ASDialog* pDialog = dynamic_cast<ASDialog*>(FUN_140ba7c60(&m_30));
    if (pDialog)
    {
        MS2Ptr<Unk_DeList> spLayers = FUN_140c02900("m_layers");
        if (spLayers.get() != 0)
        {
            ATL::CAtlArray<MS2Ptr<DecoLayer> > aLayers;
            FUN_1411987a0()->CollectLayers(aLayers);
            for (unsigned int i = 0; i < aLayers.GetCount(); i++)
            {
                DecoLayer* pLayer = aLayers[i].get();
                if (pLayer)
                {
                    ASObj row(2);
                    row.FUN_1407cba60("label", pLayer->GetName());
                    row.FUN_1407cba60("asset", pLayer->GetAsset());
                    spLayers->FUN_1422dd230(row);
                }
            }
            spLayers->vfunc_24(true);
            spLayers->FUN_1422dcca0(0);
        }
        spLayers = 0;
        MS2Ptr<Unk_DeList> spBrushes = FUN_140c02900("m_brushes");
        if (spBrushes.get() != 0)
        {
            spBrushes->FUN_1422dd2a0("PaintBrush");
            spBrushes->FUN_1422dd2a0("NoiseBrush");
            spBrushes->vfunc_24(true);
            spBrushes->FUN_1422dcca0(0);
        }
    }
}

// @0x14191b860
int UIDecoEditDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("OnSave", szMethod) == 0)
    {
        FUN_1411987a0()->SaveXml();
    }
    else if (_stricmp("OnCancel", szMethod) == 0)
    {
        FUN_1411987a0()->LoadXml();
    }
    else if (_stricmp("OnAssetChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14191bd30(data.FUN_1422b8d30());
    }
    else if (_stricmp("OnLayerInsert", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14191c060(data.FUN_1422b8d30());
    }
    else if (_stricmp("OnLayerDelete", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14191c0d0(data.FUN_1422b8d30());
    }
    else if (_stricmp("OnLayerChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14191c140(data.FUN_1422b8d30());
    }
    else if (_stricmp("OnBrushChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14191c1b0(data.FUN_1422b8a10());
    }
    else if (_stricmp("OnBrushRadiusChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14191c1e0(data.FUN_1422b8c10());
    }
    else if (_stricmp("OnBrushDensityChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14191c230(data.FUN_1422b8c10());
    }
    else if (_stricmp("OnBrushScaleChange", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            float fX = data.FUN_1422b8c10();
            float fY = data.FUN_1422b8c10();
            Unk_DeVec2 vScale;
            FUN_14191c280(*vScale.FUN_140a0a600(fX, fY));
        }
    }
    else if (_stricmp("OnBrushRotationChange", szMethod) == 0 && data.FUN_1422b9620(pArgs, nArgs) != 0)
    {
        float fX = data.FUN_1422b8c10();
        float fY = data.FUN_1422b8c10();
        Unk_DeVec2 vRotation;
        FUN_14191c2d0(*vRotation.FUN_140a0a600(fX, fY));
    }
    return 0;
}

// MS2-FUNCTIONAL: path buffers, CStringW temps and the open-file dialog arguments are laid out differently (frame size)
// @0x14191bd30
void UIDecoEditDialog::FUN_14191bd30(CString strFile)
{
    WCHAR szCurrentDir[MAX_PATH] = {0};
    CString strName = FUN_140188f50(strFile, 0);
    GetCurrentDirectoryW(MAX_PATH, szCurrentDir);
    CStringW strPath = FUN_141b6e360(CStringW(L"./Data/Resource/Model/"), L"", CStringW(L""));
    if (!strPath.IsEmpty())
    {
        if (SetCurrentDirectoryW(szCurrentDir))
        {
            wchar_t szFile[256] = {0};
            wchar_t szExt[256] = {0};
            _wsplitpath_s(strPath, 0, 0, 0, 0, szFile, 256, szExt, 256);
            FUN_14191c320(strPath);
            CString strAsset = FUN_1401d4330(strPath, 0);
            ASDialog* pDialog = dynamic_cast<ASDialog*>(FUN_140ba7c60(&m_30));
            if (pDialog)
            {
                DecoLayer* pLayer = FUN_1411987a0()->GetLayer();
                if (pLayer)
                {
                    if (FUN_14191c510(strName, szFile))
                        pLayer->ChangeAsset(strAsset);
                    pLayer->SetAsset(strAsset);
                }
                reinterpret_cast<Unk_DeScript*>(pDialog)->FUN_14191c3d0("setAsset", szFile);
            }
        }
    }
}

// @0x14191c060
void UIDecoEditDialog::FUN_14191c060(CString strName)
{
    FUN_1411987a0()->AddLayer(strName);
}

// @0x14191c0d0
void UIDecoEditDialog::FUN_14191c0d0(CString strName)
{
    FUN_1411987a0()->RemoveLayer(strName);
}

// @0x14191c140
void UIDecoEditDialog::FUN_14191c140(CString strName)
{
    FUN_1411987a0()->SelectLayer(strName);
}

// @0x14191c1b0
void UIDecoEditDialog::FUN_14191c1b0(int nBrush)
{
    FUN_1411987a0()->SetBrush(nBrush);
}

// @0x14191c1e0
void UIDecoEditDialog::FUN_14191c1e0(float fRadius)
{
    Unk_DeBrush* pBrush = reinterpret_cast<Unk_DeBrush*>(FUN_1411987a0()->GetBrush());
    if (pBrush)
        pBrush->vfunc_6(fRadius);
}

// @0x14191c230
void UIDecoEditDialog::FUN_14191c230(float fDensity)
{
    Unk_DeBrush* pBrush = reinterpret_cast<Unk_DeBrush*>(FUN_1411987a0()->GetBrush());
    if (pBrush)
        pBrush->vfunc_7(fDensity);
}

// @0x14191c280
void UIDecoEditDialog::FUN_14191c280(Unk_DeVec2 vScale)
{
    Unk_DeBrush* pBrush = reinterpret_cast<Unk_DeBrush*>(FUN_1411987a0()->GetBrush());
    if (pBrush)
        pBrush->vfunc_8(vScale);
}

// @0x14191c2d0
void UIDecoEditDialog::FUN_14191c2d0(Unk_DeVec2 vRotation)
{
    Unk_DeBrush* pBrush = reinterpret_cast<Unk_DeBrush*>(FUN_1411987a0()->GetBrush());
    if (pBrush)
        pBrush->vfunc_9(vRotation);
}

// MS2-FUNCTIONAL: CStringW temporaries of Mid/Format are laid out differently
// @0x14191c320
void FUN_14191c320(CStringW& strPath)
{
    int nModel = strPath.Find(L"Model", 0);
    if (nModel != -1)
        strPath.Format(L"%s", strPath.Mid(nModel + 6).GetString());
}

// @0x14191c3d0
Scaleform::GFx::Value Unk_DeScript::FUN_14191c3d0(const char* szMethod, const wchar_t* pszArg)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcea0(args.FUN_1409b1f70(0), pszArg);
    return FUN_1422bb8f0(szMethod, args);
}

// MS2-FUNCTIONAL: the exe has no EH state for the temporary CString (frame 0x38)
// @0x14191c510
bool FUN_14191c510(CString& strA, const wchar_t* pszB)
{
    CString strB(pszB, strA.GetManager());
    return FUN_1401647e0(strA, strB);
}

// @0x14191c6b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
