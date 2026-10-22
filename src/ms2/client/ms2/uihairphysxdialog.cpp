// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Hair physics editor (UIHairPhysxDialog, UI id 0x4e6f): tunes
// the PhysX joints and the pose of the player's two pony-tail hair models and prints them as item xml lines. The range
// ends with the radio GetChild COMDAT, the Delegate glue of its three buttons and the CRBMap<CString, NiPoint4> glue of
// the saved joints.
// MS2-UNIT: ?\uihairphysxdialog.cpp
// MS2-RANGE: 0x141980ed0-0x141986b50 .text$mn
// MS2-RANGE: 0x140114680-0x140114820 .text$di
// MS2-RANGE: 0x142cbe880-0x142cbe930 .text$yd
// MS2-PIN: ??_GUIHairPhysxDialog@@UEAAPEAXI@Z 0x141985a10
// MS2-PIN: ??1UIHairPhysxDialog@@UEAA@XZ 0x141985920
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihairphysxdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uihairphysxdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include <NiMatrix3.h>
#include <efd/utf8string.h>
#include <egf/EntityID.h>
#include <ecrPhysX/PropService.h>
#include <efdPhysX/PhysXSDKManager.h>
#include <NiPhysXProp.h>
#include <NiPhysXPropDesc.h>
#include <NiPhysXActorDesc.h>
#include <NiPhysXD6JointDesc.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ecrcameraservice.h"
#include "ms2/placeholder/itemcustom.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/itempickinghelper.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/commonfiles/item.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- local stand-ins for classes whose units are not recovered yet ----

// The AS controls of the page (all are AS UI components).
class Unk_HpxRadio : public ASUIComponent
{
public:
    bool FUN_1422ce0e0();                                       // is selected
};
class Unk_HpxSlider : public ASUIComponent
{
public:
    void FUN_1422ce5f0(float fValue);                           // set the value
};
class Unk_HpxInput : public ASUIComponent
{
public:
    void FUN_1422e0a60(const CString& strText);                 // set the text
};
class Unk_HpxCombo : public ASUIComponent
{
public:
    virtual void vfunc_16();                                    // 16..23 (ASUIComponent slots)
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);                       // 24 validateNow
    unsigned int FUN_1422df5f0(unsigned int nRows);             // visible rows
    void FUN_1422df690(int nRow);                               // select a row
    unsigned int FUN_1422dfb90();                               // row count
    void FUN_1422dfc10();                                       // remove all rows
    void FUN_1422dfce0(const CStringW& strLabel);               // add a row
    CStringW FUN_1422dfe00();                                   // the selected label
};

// The exe's NiPhysXPropDesc keeps its joint array at +0x30 (the engine header has another layout); the same view as
// equipmodelforceapplier.cpp's, whose accessors were first emitted there.
class Unk_WindPropDesc
{
public:
    unsigned GetActorCount() const;                             // 0x14120ac30
    NiPhysXActorDescPtr GetActorAt(unsigned uiIndex);           // 0x14120abd0
};

// The custom data of the worn hair item (CItem::FUN_140527870): the pose per row of the item model.
class Unk_HpxHairData : public Unk_UserProxyItemData
{
public:
    char m_pad_18[0x40];
    float m_afScale[2];                                         // +0x58
    efd::Point3 m_akPos[2];                                     // +0x60
    efd::Point3 m_akRot[2];                                     // +0x78 euler degrees
};
MS2_CHECK_OFFSET(Unk_HpxHairData, m_afScale, 0x58);
MS2_CHECK_OFFSET(Unk_HpxHairData, m_akPos, 0x60);
MS2_CHECK_OFFSET(Unk_HpxHairData, m_akRot, 0x78);

class Unk_HpxWorld { public: PCBase* FUN_141bd0cc0(); };       // the player (NULL outside the game)
Unk_HpxWorld* FUN_1403ed2d0();
class Unk_HpxUIMgr
{
public:
    void FUN_141adc530(int nId);                                // open
    void FUN_141adc5d0(int nId);                                // close
};
Unk_HpxUIMgr* FUN_1403ed2b0();
class Unk_HpxEquipSet { public: void FUN_1411e9190(int bOnlyPonytail); };
Unk_HpxEquipSet* FUN_1416561a0(PCBase* pPc);
int FUN_14123c580(PCBase* pPc);                                 // object id
void FUN_141901390(int bRelease, int nLayer);                   // the player key input layer
void FUN_141695f10(PCBase* pPlayer, Unk_PickTarget** ppFirst, Unk_PickTarget** ppSecond);   // the two pony parts
CKfmModel* FUN_1411de170(Unk_PickTarget* pPart);                // the part's model as a .kfm model
void FUN_1412021a0(CEquipModel* pModel, NiTransform* pXform);   // the model transform
Unk_BSCamera* FUN_140cd47b0(int nId);
Unk_ServiceManager* FUN_1413f9850();                            // the framework's service manager
extern char DAT_143b059e8;                                      // the app framework
ecrPhysX::PropService* FUN_1412938c0(char* pFramework);
efd::utf8string FUN_1414d7990(const efd::utf8string& strName);  // the scene name of a PhysX scene key
class CPhysXHelper
{
public:
    void FUN_14168a540(int n);                                  // lock the scene
    void* FUN_1416892a0(int nScene);                            // the scene
    void FUN_14168a570();                                       // unlock
};
CPhysXHelper* FUN_1409f7ca0();
CString FUN_14016a600(const wchar_t* psz, int nCodePage);       // narrow a wide string
CStringW FUN_14016a730(const char* psz, int nCodePage);         // widen a narrow string

CString FUN_14038f6d0(const CString& str, const char* psz);     // ATL::operator+ (the exe copy; clang lacks the MFC CopyChars import)

template <class T> inline T Unk_HpxMin(T a, T b) { return a < b ? a : b; }

// ---- static initializers (.text$di) ----
// (the statics of header_statics_a.h and cmypckeyinputcontroller.h)
#ifndef MS2_HOOK_DLL
static UICommon::CMyPCKeyInputController s_keyInputController;
#endif

// ---- UIHairPhysxDialog ----

// @0x141980ed0
UIHairPhysxDialog::UIHairPhysxDialog()
    : m_1f8(10), m_228(10), m_2c0(0), m_2d0(0), m_2d8(0)
{
    m_40 = 1;
}

// @0x141981010
CString UIHairPhysxDialog::GetTypeName()
{
    return CString("HairPhysxDialog");
}
MS2_REPLACE_METHOD(0x141981010, UIHairPhysxDialog, GetTypeName, 61, 0x89D6505E);

// @0x141981060
void UIHairPhysxDialog::FUN_141981060()
{
    int nMode = FUN_1419834a0();
    if (nMode != 0)
    {
        Unk_HpxModel* pLeft = 0;
        Unk_HpxModel* pRight = 0;
        Unk_HpxModel* pModel = 0;
        FUN_141984af0(FUN_1419833e0(), &pLeft, &pRight);
        pModel = pLeft ? pLeft : pRight;
        if (pModel)
        {
            NiTransform kXform;
            FUN_1412021a0(pModel, &kXform);
            FUN_141985210(pModel, kXform);
            NiPoint3 kValue(0.0f, 0.0f, 0.0f);
            if (nMode == 1)
                kValue = kXform.m_Translate;
            else if (nMode == 2)
                FUN_141984da0(kXform.m_Rotate, kValue);
            if (MS2Ptr<Unk_HpxInput> sp = FUN_140e35bd0("m_transformX"))
            {
                CString str;
                str.Format("%f", kValue.x);
                sp->FUN_1422e0a60(str);
            }
            if (MS2Ptr<Unk_HpxInput> sp = FUN_140e35bd0("m_transformY"))
            {
                CString str;
                str.Format("%f", kValue.y);
                sp->FUN_1422e0a60(str);
            }
            if (MS2Ptr<Unk_HpxInput> sp = FUN_140e35bd0("m_transformZ"))
            {
                CString str;
                str.Format("%f", kValue.z);
                sp->FUN_1422e0a60(str);
            }
        }
        FUN_141984360();
    }
}
MS2_REPLACE_METHOD(0x141981060, UIHairPhysxDialog, FUN_141981060, 1000, 0x6D0AE5BC);

// @0x141981450
void UIHairPhysxDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925fa0("m_dragBar");
    FUN_141925ec0("m_closeButton");
    FUN_1419264e0("m_reset", Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIHairPhysxDialog::FUN_141982880));
    FUN_1419264e0("m_mirror", Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIHairPhysxDialog::FUN_141982940));
    FUN_1419264e0("m_save", Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIHairPhysxDialog::FUN_141982860));
    PCBase* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
    {
        pPc->FUN_14166d8e0(efd::Point3(0.0f, -1.0f, 0.0f));
        pPc->vfunc_59(0xe, 0, 0, 0);
        FUN_141901390(0, 0x3eb);
        m_2c0.AssignRaw(new Customize(FUN_14123c580(pPc), static_cast<IItemCustomizeEventListener*>(this), 0));
        m_2c0->FUN_140cd2530(6);
        m_2c0->FUN_140cd25c0(1);
        FUN_1403ed2b0()->FUN_141adc530(0x4ef2);
        m_2d0 = FUN_140cd47b0(0x4ef2);
        m_190.MakeIdentity();
        m_1c4.MakeIdentity();
        Unk_HpxModel* pLeft = 0;
        Unk_HpxModel* pRight = 0;
        FUN_141984af0(0, &pLeft, &pRight);
        if (pLeft)
            FUN_1412021a0(pLeft, &m_190);
        if (pRight)
            FUN_1412021a0(pRight, &m_1c4);
        FUN_141983010();
        FUN_141983f50();
        FUN_141983730();
        FUN_141983c60();
        FUN_141983af0();
        FUN_141984360();
    }
}
MS2_REPLACE_METHOD(0x141981450, UIHairPhysxDialog, OnLoadComplete, 1441, 0xDB01EB2F);

// @0x141981a00
void UIHairPhysxDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    PCBase* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
    {
        pPc->FUN_14166d8e0(efd::Point3(0.0f, -1.0f, 0.0f));
        pPc->vfunc_59(1, 0, 0, 0);
        FUN_141901390(1, 0x3eb);
    }
    ecrPhysX::PropService* pService = FUN_1412938c0(&DAT_143b059e8);
    if (pService)
    {
        efd::utf8string strScene("PhysXItemSceneName");
        strScene = FUN_1414d7990(strScene);
        pService->SetDebugRender(strScene, false);
    }
    if (m_2c0.get() != 0)
    {
        m_2c0->FUN_140cd24a0(6);
        m_2c0 = 0;
    }
    m_2d0 = 0;
    FUN_1403ed2b0()->FUN_141adc5d0(0x4ef2);
}
MS2_REPLACE_METHOD(0x141981A00, UIHairPhysxDialog, vfunc_26, 473, 0x9AD1B8E0);

// @0x141981be0
void UIHairPhysxDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (!(m_2c0 == 0))
    {
        m_2c0->FUN_140cd1bf0();
        if (m_2d0)
            m_2d0->FUN_1418dda30(m_2c0->FUN_140cd27f0() == 0);
    }
}
MS2_REPLACE_METHOD(0x141981BE0, UIHairPhysxDialog, vfunc_15, 166, 0x55D7B316);

// @0x141981c90
int UIHairPhysxDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) == 0)
    {
        ASData data;
        if (_stricmp("eventSelectModel", szMethod) == 0)
        {
            EventSelectModel();
            return 1;
        }
        if (_stricmp("eventJointsList", szMethod) == 0)
        {
            if (data.FUN_1422b9620(pArgs, nArgs))
                FUN_141982440(data.FUN_1422b8d30());
            return 1;
        }
        if (_stricmp("eventJointsSoft", szMethod) == 0)
        {
            if (data.FUN_1422b9620(pArgs, nArgs))
                FUN_141982480(data.FUN_1422b8c10());
            return 1;
        }
        if (_stricmp("eventJointsAxis", szMethod) == 0)
        {
            if (data.FUN_1422b9620(pArgs, nArgs))
            {
                float fX = data.FUN_1422b8c10();
                float fY = data.FUN_1422b8c10();
                float fZ = data.FUN_1422b8c10();
                FUN_141982590(fX, fY, fZ);
            }
            return 1;
        }
        if (_stricmp("eventPhysDebug", szMethod) == 0)
        {
            if (data.FUN_1422b9620(pArgs, nArgs))
                FUN_1419821d0(data.FUN_1422b8a10());
            return 1;
        }
        if (_stricmp("eventOnlyPonytail", szMethod) == 0)
        {
            if (data.FUN_1422b9620(pArgs, nArgs))
                FUN_141982350(data.FUN_1422b8a10());
            return 1;
        }
        if (_stricmp("eventSelectTransform", szMethod) == 0)
        {
            EventSelectTransform();
            return 1;
        }
        if (_stricmp("eventTransformValue", szMethod) == 0)
        {
            if (data.FUN_1422b9620(pArgs, nArgs))
            {
                float fX = data.FUN_1422b8c10();
                float fY = data.FUN_1422b8c10();
                float fZ = data.FUN_1422b8c10();
                FUN_1419826e0(fX, fY, fZ);
            }
            return 1;
        }
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141981C90, UIHairPhysxDialog, vfunc_28, 1075, 0xAC3BAF19);

// @0x1419820f0
int UIHairPhysxDialog::vfunc_4(void* p1, void* p2)
{
    FUN_141983f50();
    FUN_141983c60();
    FUN_141983af0();
    FUN_141984360();
    return 1;
}

// @0x141982160
int UIHairPhysxDialog::vfunc_5(void* p1, void* p2)
{
    FUN_141983f50();
    FUN_141983c60();
    FUN_141983af0();
    FUN_141984360();
    return 1;
}

// @0x1419821d0
void UIHairPhysxDialog::FUN_1419821d0(int nDebug)
{
    bool bDebug = nDebug != 0;
    const bool bActive = bDebug;
    ecrPhysX::PropService* pService = FUN_1412938c0(&DAT_143b059e8);
    if (pService)
    {
        efd::utf8string strScene("PhysXItemSceneName");
        strScene = FUN_1414d7990(strScene);
        pService->SetDebugRender(strScene, bActive);
        FUN_1409f7ca0()->FUN_14168a540(1);
        void* pScene = FUN_1409f7ca0()->FUN_1416892a0(1);
        if (pScene != 0)
        {
            NxPhysicsSDK* pSDK = efdPhysX::PhysXSDKManager::GetManager()->m_pPhysXSDK;
            if (pSDK != 0)
                pSDK->setParameter(NX_VISUALIZATION_SCALE, bActive ? 0.3f : 0.0f);
        }
        FUN_1409f7ca0()->FUN_14168a570();
    }
}
MS2_REPLACE_METHOD(0x1419821D0, UIHairPhysxDialog, FUN_1419821d0, 377, 0x16028B66);

// @0x141982350
void UIHairPhysxDialog::FUN_141982350(int nOnly)
{
    PCBase* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
    {
        if (nOnly)
            FUN_1416561a0(pPc)->FUN_1411e9190(1);
        else
            FUN_1416561a0(pPc)->FUN_1411e9190(0);
    }
}
MS2_REPLACE_METHOD(0x141982350, UIHairPhysxDialog, FUN_141982350, 98, 0xDC50BC62);

// @0x1419823c0
void UIHairPhysxDialog::EventSelectModel()
{
    FUN_141983f50();
    FUN_141983730();
    FUN_141983c60();
    FUN_141983af0();
    FUN_141984360();
}
MS2_REPLACE_METHOD(0x1419823C0, UIHairPhysxDialog, EventSelectModel, 64, 0x4014818E);

// @0x141982410
void UIHairPhysxDialog::EventSelectTransform()
{
    FUN_141983f50();
    FUN_141984360();
}
MS2_REPLACE_METHOD(0x141982410, UIHairPhysxDialog, EventSelectTransform, 34, 0xF0C7D14D);

// @0x141982440
void UIHairPhysxDialog::FUN_141982440(const CString& strJoint)
{
    FUN_141983c60();
    FUN_141983af0();
    FUN_141984360();
}
MS2_REPLACE_METHOD(0x141982440, UIHairPhysxDialog, FUN_141982440, 49, 0x902484C5);

// @0x141982480
void UIHairPhysxDialog::FUN_141982480(float fSoft)
{
    Unk_HpxModel* pLeft = 0;
    Unk_HpxModel* pRight = 0;
    FUN_141984af0(FUN_1419833e0(), &pLeft, &pRight);
    if (pLeft)
        pLeft->FUN_141440110(FUN_141983600(), fSoft);
    if (pRight)
        pRight->FUN_141440110(FUN_141983600(), fSoft);
    FUN_141984360();
}
MS2_REPLACE_METHOD(0x141982480, UIHairPhysxDialog, FUN_141982480, 252, 0xAC6F6B42);

// @0x141982590
void UIHairPhysxDialog::FUN_141982590(float fX, float fY, float fZ)
{
    Unk_HpxModel* pLeft = 0;
    Unk_HpxModel* pRight = 0;
    FUN_141984af0(FUN_1419833e0(), &pLeft, &pRight);
    if (pLeft)
        pLeft->FUN_1414401b0(FUN_141983600(), fX, fY, fZ);
    if (pRight)
        pRight->FUN_1414401b0(FUN_141983600(), fX, fY, fZ);
    FUN_141984360();
}
MS2_REPLACE_METHOD(0x141982590, UIHairPhysxDialog, FUN_141982590, 318, 0x2ACD60EE);

// @0x1419826e0
void UIHairPhysxDialog::FUN_1419826e0(float fX, float fY, float fZ)
{
    int nMode = FUN_1419834a0();
    if (nMode != 0)
    {
        Unk_HpxModel* pLeft = 0;
        Unk_HpxModel* pRight = 0;
        FUN_141984af0(FUN_1419833e0(), &pLeft, &pRight);
        Unk_HpxModel* pModel = pLeft ? pLeft : pRight;
        if (pModel)
        {
            if (nMode == 1)
                FUN_141984e50(pModel, NiPoint3(fX, fY, fZ));
            else if (nMode == 2)
                FUN_141985000(pModel, NiPoint3(fX, fY, fZ));
        }
        FUN_141984360();
    }
}
MS2_REPLACE_METHOD(0x1419826E0, UIHairPhysxDialog, FUN_1419826e0, 373, 0xC0C45CF2);

// @0x141982860
void UIHairPhysxDialog::FUN_141982860(const Scaleform::GFx::FunctionHandler::Params& params)
{
}

// @0x141982880
void UIHairPhysxDialog::FUN_141982880(const Scaleform::GFx::FunctionHandler::Params& params)
{
    Unk_HpxModel* pLeft = 0;
    Unk_HpxModel* pRight = 0;
    FUN_141984af0(0, &pLeft, &pRight);
    if (pLeft)
        FUN_141985210(pLeft, m_190);
    if (pRight)
        FUN_141985210(pRight, m_1c4);
    FUN_141982dc0();
    FUN_141983f50();
    FUN_141983c60();
    FUN_141983af0();
    FUN_141984360();
}
MS2_REPLACE_METHOD(0x141982880, UIHairPhysxDialog, FUN_141982880, 183, 0xCBB2EE24);

// @0x141982940
// "m_mirror": copies the joints of the edited side onto the other side, the axes mirrored through the median plane.
void UIHairPhysxDialog::FUN_141982940(const Scaleform::GFx::FunctionHandler::Params& params)
{
    Unk_HpxModel* pSrc = 0;
    Unk_HpxModel* pDst = 0;
    Unk_HpxModel* pLeft = 0;
    Unk_HpxModel* pRight = 0;
    if (FUN_141984af0(0, &pLeft, &pRight))
    {
        if (FUN_1419833e0() == 2)
        {
            pSrc = pRight;
            pDst = pLeft;
        }
        else
        {
            pSrc = pLeft;
            pDst = pRight;
        }
        NiMatrix3 kMirror;
        kMirror.SetRow(0, 1.0f, 0.0f, 0.0f);
        kMirror.SetRow(1, 0.0f, 1.0f, 0.0f);
        kMirror.SetRow(2, 0.0f, 0.0f, -1.0f);
        POSITION pos = m_1f8.GetHeadPosition();
        while (pos)
        {
            const CString& strJoint = m_1f8.GetKeyAt(pos);
            float fSoft = 0;
            FUN_141984c30(pSrc, strJoint, &fSoft);
            pDst->FUN_141440110(strJoint, fSoft);
            float fX = 0.0f;
            float fY = 0.0f;
            float fZ = 0.0f;
            FUN_141984cd0(pSrc, strJoint, &fX, &fY, &fZ);
            NiMatrix3 kRot;
            kRot.FromEulerAnglesXYZ(fX * 3.1415927f / 180.0f, fY * 3.1415927f / 180.0f, fZ * 3.1415927f / 180.0f);
            NiMatrix3 kAxes = kMirror * kRot;
            NiPoint3 kAxisX(efd::Point3::ZERO);
            kAxes.GetCol(0, kAxisX);
            kAxisX.Unitize();
            NiPoint3 kAxisZ(-kAxisX.Cross(efd::Point3::UNIT_Z));
            kAxes.GetCol(2, kAxisZ);
            kAxisZ.Unitize();
            NiPoint3 kAxisY(kAxisX.Cross(kAxisZ));
            kAxes.GetCol(1, kAxisY);
            kAxisY.Unitize();
            kAxes = NiMatrix3(kAxisX, kAxisY, kAxisZ);
            NiPoint3 kEuler(efd::Point3::ZERO);
            FUN_141984da0(kAxes, kEuler);
            pDst->FUN_1414401b0(strJoint, kEuler.x, kEuler.y, kEuler.z);
            m_1f8.GetNext(pos);
        }
        FUN_141983f50();
        FUN_141983c60();
        FUN_141983af0();
        FUN_141984360();
    }
}
MS2_REPLACE_METHOD(0x141982940, UIHairPhysxDialog, FUN_141982940, 1141, 0xDC0B463A);

// @0x141982dc0
void UIHairPhysxDialog::FUN_141982dc0()
{
    Unk_HpxModel* pLeft = 0;
    Unk_HpxModel* pRight = 0;
    FUN_141984af0(0, &pLeft, &pRight);
    if (pLeft && pRight)
    {
        POSITION pos = m_1f8.GetHeadPosition();
        while (pos)
        {
            const CString& strJoint = m_1f8.GetKeyAt(pos);
            const NiPoint4& kJoint = m_1f8.GetValueAt(pos);
            pLeft->FUN_141440110(strJoint, kJoint.m_afPt[0]);
            pLeft->FUN_1414401b0(strJoint, kJoint.m_afPt[1], kJoint.m_afPt[2], kJoint.m_afPt[3]);
            m_1f8.GetNext(pos);
        }
        POSITION pos2 = m_228.GetHeadPosition();
        while (pos2)
        {
            const CString& strJoint = m_228.GetKeyAt(pos2);
            const NiPoint4& kJoint = m_228.GetValueAt(pos2);
            pRight->FUN_141440110(strJoint, kJoint.m_afPt[0]);
            pRight->FUN_1414401b0(strJoint, kJoint.m_afPt[1], kJoint.m_afPt[2], kJoint.m_afPt[3]);
            m_228.GetNext(pos2);
        }
    }
}
MS2_REPLACE_METHOD(0x141982DC0, UIHairPhysxDialog, FUN_141982dc0, 581, 0x6D16A6F2);

// @0x141983010
void UIHairPhysxDialog::FUN_141983010()
{
    Unk_ServiceManager* pServices = FUN_1413f9850();
    ecrPhysX::PropService* pService;
    if (pServices != 0 && (pService = pServices->GetSystemServiceAs<ecrPhysX::PropService>()) != 0)
    {
        Unk_PickTarget* pPart = 0;
        FUN_141695f10(FUN_1403ed2d0()->FUN_141bd0cc0(), &pPart, 0);
        CKfmModel* pKfm = FUN_1411de170(pPart);
        if (pKfm != 0)
        {
            NiPhysXProp* pProp = pService->GetPropAt(pKfm->FUN_14143ff70(), 0);
            Unk_WindPropDesc* pDesc;
            if (pProp != 0 && (pDesc = reinterpret_cast<Unk_WindPropDesc*>(pProp->GetSnapshot())) != 0)
            {
                Unk_HpxModel* pLeft = 0;
                Unk_HpxModel* pRight = 0;
                FUN_141984af0(0, &pLeft, &pRight);
                if (pLeft != 0 && pRight != 0)
                {
                    m_1f8.RemoveAll();
                    m_228.RemoveAll();
                    for (unsigned i = 0; i < pDesc->GetActorCount(); i++)
                    {
                        NiPhysXD6JointDesc* pJointDesc = NiDynamicCast(NiPhysXD6JointDesc, pDesc->GetActorAt(i));
                        NxD6Joint* pJoint;
                        if (pJointDesc != 0 && (pJoint = pJointDesc->GetJoint()) != 0)
                        {
                            const CString& strJoint = CString(pJoint->getName());
                            NiPoint4 kLeft;
                            FUN_141984c30(pLeft, strJoint, &kLeft.m_afPt[0]);
                            FUN_141984cd0(pLeft, strJoint, &kLeft.m_afPt[1], &kLeft.m_afPt[2], &kLeft.m_afPt[3]);
                            m_1f8.SetAt(strJoint, kLeft);
                            NiPoint4 kRight;
                            FUN_141984c30(pRight, strJoint, &kRight.m_afPt[0]);
                            FUN_141984cd0(pRight, strJoint, &kRight.m_afPt[1], &kRight.m_afPt[2], &kRight.m_afPt[3]);
                            m_228.SetAt(strJoint, kRight);
                        }
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141983010, UIHairPhysxDialog, FUN_141983010, 956, 0x2238A039);

// @0x1419833e0
int UIHairPhysxDialog::FUN_1419833e0()
{
    if (MS2Ptr<Unk_HpxRadio> sp = GetChild<Unk_HpxRadio>("m_left"))
    {
        if (sp->FUN_1422ce0e0())
            return 2;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419833E0, UIHairPhysxDialog, FUN_1419833e0, 177, 0x46A0B2A6);

// @0x1419834a0
int UIHairPhysxDialog::FUN_1419834a0()
{
    if (MS2Ptr<Unk_HpxRadio> sp = GetChild<Unk_HpxRadio>("m_position"))
    {
        if (sp->FUN_1422ce0e0())
            return 1;
    }
    if (MS2Ptr<Unk_HpxRadio> sp = GetChild<Unk_HpxRadio>("m_rotation"))
    {
        if (sp->FUN_1422ce0e0())
            return 2;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419834A0, UIHairPhysxDialog, FUN_1419834a0, 344, 0xEAC2138C);

// @0x141983600
// MS2-FUNCTIONAL: CString returned by value from inside the scope of the combo handle
CString UIHairPhysxDialog::FUN_141983600()
{
    if (MS2Ptr<Unk_HpxCombo> sp = FUN_140c28560("m_joints"))
        return FUN_14016a600(sp->FUN_1422dfe00(), 0);
    return CString("");
}
MS2_REPLACE_METHOD(0x141983600, UIHairPhysxDialog, FUN_141983600, 296, 0xB2F98612);

// @0x141983730
void UIHairPhysxDialog::FUN_141983730()
{
    Unk_ServiceManager* pServices = FUN_1413f9850();
    ecrPhysX::PropService* pService;
    if (pServices != 0 && (pService = pServices->GetSystemServiceAs<ecrPhysX::PropService>()) != 0)
    {
        Unk_PickTarget* pPart = 0;
        FUN_141695f10(FUN_1403ed2d0()->FUN_141bd0cc0(), &pPart, 0);
        CKfmModel* pKfm = FUN_1411de170(pPart);
        if (pKfm != 0)
        {
            NiPhysXProp* pProp = pService->GetPropAt(pKfm->FUN_14143ff70(), 0);
            Unk_WindPropDesc* pDesc;
            if (pProp != 0 && (pDesc = reinterpret_cast<Unk_WindPropDesc*>(pProp->GetSnapshot())) != 0)
            {
                ATL::CAtlArray<CString> arrJoints;
                for (unsigned i = 0; i < pDesc->GetActorCount(); i++)
                {
                    NiPhysXD6JointDesc* pJointDesc = NiDynamicCast(NiPhysXD6JointDesc, pDesc->GetActorAt(i));
                    NxD6Joint* pJoint;
                    if (pJointDesc != 0 && (pJoint = pJointDesc->GetJoint()) != 0)
                        arrJoints.Add(CString(pJoint->getName()));
                }
                if (MS2Ptr<Unk_HpxCombo> sp = FUN_140c28560("m_joints"))
                {
                    sp->FUN_1422dfc10();
                    for (unsigned j = 0; j < arrJoints.GetCount(); j++)
                        sp->FUN_1422dfce0(FUN_14016a730(arrJoints[j], 0));
                    unsigned int nRows = Unk_HpxMin(sp->FUN_1422dfb90(), 4u);
                    sp->FUN_1422df5f0(nRows);
                    sp->FUN_1422df690(0);
                    sp->vfunc_24(true);
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141983730, UIHairPhysxDialog, FUN_141983730, 947, 0xFE2C3C62);

// @0x141983af0
void UIHairPhysxDialog::FUN_141983af0()
{
    Unk_HpxModel* pLeft = 0;
    Unk_HpxModel* pRight = 0;
    Unk_HpxModel* pModel = 0;
    FUN_141984af0(FUN_1419833e0(), &pLeft, &pRight);
    pModel = pLeft ? pLeft : pRight;
    if (pModel)
    {
        float fSoft = 0;
        FUN_141984c30(pModel, FUN_141983600(), &fSoft);
        if (MS2Ptr<Unk_HpxSlider> sp = FUN_140faff90("m_softSlider"))
            sp->FUN_1422ce5f0(fSoft);
    }
}
MS2_REPLACE_METHOD(0x141983AF0, UIHairPhysxDialog, FUN_141983af0, 362, 0x950C0FA3);

// @0x141983c60
void UIHairPhysxDialog::FUN_141983c60()
{
    Unk_HpxModel* pLeft = 0;
    Unk_HpxModel* pRight = 0;
    Unk_HpxModel* pModel = 0;
    FUN_141984af0(FUN_1419833e0(), &pLeft, &pRight);
    pModel = pLeft ? pLeft : pRight;
    if (pModel)
    {
        float fX = 0;
        float fY = 0;
        float fZ = 0;
        FUN_141984cd0(pModel, FUN_141983600(), &fX, &fY, &fZ);
        if (MS2Ptr<Unk_HpxSlider> sp = FUN_140faff90("m_xSlider"))
            sp->FUN_1422ce5f0(fX);
        if (MS2Ptr<Unk_HpxSlider> sp = FUN_140faff90("m_ySlider"))
            sp->FUN_1422ce5f0(fY);
        if (MS2Ptr<Unk_HpxSlider> sp = FUN_140faff90("m_zSlider"))
            sp->FUN_1422ce5f0(fZ);
    }
}
MS2_REPLACE_METHOD(0x141983C60, UIHairPhysxDialog, FUN_141983c60, 746, 0x967CAEDD);

// @0x141983f50
void UIHairPhysxDialog::FUN_141983f50()
{
    PCBase* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    int nSide;
    int nMode;
    if (pPc != 0 && (nSide = FUN_1419833e0()) != 0 && (nMode = FUN_1419834a0()) != 0)
    {
        NiPoint3 kValue(0.0f, 0.0f, 0.0f);
        Unk_HpxModel* pLeft = 0;
        Unk_HpxModel* pRight = 0;
        Unk_HpxModel* pModel = 0;
        FUN_141984af0(FUN_1419833e0(), &pLeft, &pRight);
        pModel = pLeft ? pLeft : pRight;
        if (pModel)
        {
            NiTransform kXform;
            FUN_1412021a0(pModel, &kXform);
            if (nMode == 1)
                kValue = kXform.m_Translate;
            else if (nMode == 2)
                FUN_141984da0(kXform.m_Rotate, kValue);
        }
        if (MS2Ptr<Unk_HpxInput> sp = FUN_140e35bd0("m_transformX"))
        {
            CString str;
            str.Format("%f", kValue.x);
            sp->FUN_1422e0a60(str);
        }
        if (MS2Ptr<Unk_HpxInput> sp = FUN_140e35bd0("m_transformY"))
        {
            CString str;
            str.Format("%f", kValue.y);
            sp->FUN_1422e0a60(str);
        }
        if (MS2Ptr<Unk_HpxInput> sp = FUN_140e35bd0("m_transformZ"))
        {
            CString str;
            str.Format("%f", kValue.z);
            sp->FUN_1422e0a60(str);
        }
    }
}
MS2_REPLACE_METHOD(0x141983F50, UIHairPhysxDialog, FUN_141983f50, 1023, 0xF0152227);

// @0x141984360
void UIHairPhysxDialog::FUN_141984360()
{
    Unk_ServiceManager* pServices = FUN_1413f9850();
    ecrPhysX::PropService* pService;
    if (pServices != 0 && (pService = pServices->GetSystemServiceAs<ecrPhysX::PropService>()) != 0)
    {
        Unk_HpxModel* pModel = 0;
        FUN_141984a10(FUN_1419833e0(), &pModel);
        if (pModel != 0)
        {
            NiPhysXProp* pProp = pService->GetPropAt(pModel->FUN_14143ff70(), 0);
            Unk_WindPropDesc* pDesc;
            if (pProp != 0 && (pDesc = reinterpret_cast<Unk_WindPropDesc*>(pProp->GetSnapshot())) != 0)
            {
                if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_transform"))
                {
                    spText->FUN_1422c4c80("");
                    for (unsigned i = 0; i < pDesc->GetActorCount(); i++)
                    {
                        NiPhysXD6JointDesc* pJointDesc = NiDynamicCast(NiPhysXD6JointDesc, pDesc->GetActorAt(i));
                        NxD6Joint* pJoint;
                        if (pJointDesc != 0 && (pJoint = pJointDesc->GetJoint()) != 0)
                        {
                            float fSoft = 0.0f;
                            float fX = 0.0f;
                            float fY = 0.0f;
                            float fZ = 0.0f;
                            const CString& strJoint = CString(pJoint->getName());
                            FUN_141984c30(pModel, strJoint, &fSoft);
                            FUN_141984cd0(pModel, strJoint, &fX, &fY, &fZ);
                            CString strLine;
                            strLine.Format("<jointangle name=\"%s\" soft=\"%0.2f\" posz=\"%0.2f\" zero=\"%0.2f\" negz=\"%0.2f\"/>",
                                (const char*)strJoint, fSoft, fX, fY, fZ);
                            spText->FUN_1422c5a50(FUN_14038f6d0(strLine, "\n"));
                        }
                    }
                    if (pModel != 0)
                    {
                        Unk_HpxHairData* pData = static_cast<Unk_HpxHairData*>(pModel->FUN_141200a40()->GetItem()->FUN_140527870());
                        if (pData != 0)
                        {
                            int nIndex = pModel->FUN_141200ab0()->m_nIndex;
                            float fScale = pData->m_afScale[nIndex];
                            efd::Point3 kPos = pData->m_akPos[nIndex];
                            efd::Point3 kRot = pData->m_akRot[nIndex];
                            CString strLine;
                            strLine.Format("<random position=\"%0.2f,%0.2f,%0.2f\" rotation=\"%0.2f,%0.2f,%0.2f\" scale=\"%0.2f\"/>",
                                kPos.x, kPos.y, kPos.z, kRot.x, kRot.y, kRot.z, fScale);
                            spText->FUN_1422c5a50(FUN_14038f6d0(strLine, "\n"));
                        }
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141984360, UIHairPhysxDialog, FUN_141984360, 1698, 0x448B5BB9);

// @0x141984a10
int UIHairPhysxDialog::FUN_141984a10(int nSide, Unk_HpxModel** ppModel)
{
    PCBase* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    Unk_PickTarget* pFirst = 0;
    Unk_PickTarget* pSecond = 0;
    FUN_141695f10(pPc, &pFirst, &pSecond);
    switch (nSide)
    {
    case 0:
    case 1:
        if (ppModel)
            *ppModel = static_cast<Unk_HpxModel*>(FUN_1411de170(pFirst));
        if (*ppModel)
            return 1;
        break;
    case 2:
        if (ppModel)
            *ppModel = static_cast<Unk_HpxModel*>(FUN_1411de170(pSecond));
        if (*ppModel)
            return 1;
        break;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141984A10, UIHairPhysxDialog, FUN_141984a10, 217, 0xD88E4BED);

// @0x141984af0
int UIHairPhysxDialog::FUN_141984af0(int nSide, Unk_HpxModel** ppLeft, Unk_HpxModel** ppRight)
{
    PCBase* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    Unk_PickTarget* pFirst = 0;
    Unk_PickTarget* pSecond = 0;
    FUN_141695f10(pPc, &pFirst, &pSecond);
    switch (nSide)
    {
    case 1:
        if (ppLeft)
            *ppLeft = static_cast<Unk_HpxModel*>(FUN_1411de170(pFirst));
        if (*ppLeft)
            return 1;
        break;
    case 2:
        if (ppRight)
            *ppRight = static_cast<Unk_HpxModel*>(FUN_1411de170(pSecond));
        if (*ppRight)
            return 1;
        break;
    case 0:
        if (ppLeft)
            *ppLeft = static_cast<Unk_HpxModel*>(FUN_1411de170(pFirst));
        if (ppRight)
            *ppRight = static_cast<Unk_HpxModel*>(FUN_1411de170(pSecond));
        if (*ppLeft && *ppRight)
            return 1;
        break;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141984AF0, UIHairPhysxDialog, FUN_141984af0, 311, 0x619DC50A);

// @0x141984c30
void UIHairPhysxDialog::FUN_141984c30(Unk_HpxModel* pModel, const CString& strJoint, float* pSoft)
{
    if (pModel)
    {
        for (unsigned i = 0; i < 4; i++)
        {
            Unk_KfmPonyTail* pJoint = &pModel->FUN_141200ab0()->m_aJoints[i];
            if (pJoint->m_strBone == strJoint)
            {
                *pSoft = pJoint->m_fDamping;
                return;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141984C30, UIHairPhysxDialog, FUN_141984c30, 145, 0xAF64A6AC);

// @0x141984cd0
void UIHairPhysxDialog::FUN_141984cd0(Unk_HpxModel* pModel, const CString& strJoint, float* pX, float* pY, float* pZ)
{
    if (pModel)
    {
        for (unsigned i = 0; i < 4; i++)
        {
            Unk_KfmPonyTail* pJoint = &pModel->FUN_141200ab0()->m_aJoints[i];
            if (pJoint->m_strBone == strJoint)
            {
                *pX = pJoint->m_fX;
                *pY = pJoint->m_fY;
                *pZ = pJoint->m_fZ;
                return;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141984CD0, UIHairPhysxDialog, FUN_141984cd0, 189, 0x72DECEFB);

// @0x141984da0
void UIHairPhysxDialog::FUN_141984da0(const NiMatrix3& kRot, NiPoint3& kDeg)
{
    kRot.ToEulerAnglesXYZ(kDeg.x, kDeg.y, kDeg.z);
    kDeg.x = kDeg.x * 180.0f / 3.1415927f;
    kDeg.y = kDeg.y * 180.0f / 3.1415927f;
    kDeg.z = kDeg.z * 180.0f / 3.1415927f;
}
MS2_REPLACE_METHOD(0x141984DA0, UIHairPhysxDialog, FUN_141984da0, 169, 0x94E53925);

// @0x141984e50
void UIHairPhysxDialog::FUN_141984e50(Unk_HpxModel* pModel, NiPoint3 kPos)
{
    if (pModel)
    {
        Unk_HpxHairData* pData = static_cast<Unk_HpxHairData*>(pModel->FUN_141200a40()->GetItem()->FUN_140527870());
        if (pData)
        {
            int nIndex = pModel->FUN_141200ab0()->m_nIndex;
            NiTransform kXform;
            FUN_1412021a0(pModel, &kXform);
            pData->m_akPos[nIndex] = kPos;
            kXform.m_Translate = kPos;
            pModel->FUN_141202240(kXform);
            Unk_HpxModelConfig* pConfig = pModel->FUN_141200ab0();
            if (pConfig)
                pConfig->m_customs.FUN_14059ce40(nIndex)->unknown18 = kPos;
        }
    }
}
MS2_REPLACE_METHOD(0x141984E50, UIHairPhysxDialog, FUN_141984e50, 423, 0x0E4E740D);

// @0x141985000
void UIHairPhysxDialog::FUN_141985000(Unk_HpxModel* pModel, NiPoint3 kDeg)
{
    if (pModel)
    {
        Unk_HpxHairData* pData = static_cast<Unk_HpxHairData*>(pModel->FUN_141200a40()->GetItem()->FUN_140527870());
        if (pData)
        {
            int nIndex = pModel->FUN_141200ab0()->m_nIndex;
            NiTransform kXform;
            FUN_1412021a0(pModel, &kXform);
            pData->m_akRot[nIndex] = kDeg;
            float fX = kDeg.x * 3.1415927f / 180.0f;
            kXform.m_Rotate.FromEulerAnglesXYZ(fX, kDeg.y * 3.1415927f / 180.0f, kDeg.z * 3.1415927f / 180.0f);
            pModel->FUN_141202240(kXform);
            Unk_HpxModelConfig* pConfig = pModel->FUN_141200ab0();
            if (pConfig)
                pConfig->m_customs.FUN_14059ce40(nIndex)->unknown24 = kDeg;
        }
    }
}
MS2_REPLACE_METHOD(0x141985000, UIHairPhysxDialog, FUN_141985000, 522, 0x08D88F3F);

// @0x141985210
void UIHairPhysxDialog::FUN_141985210(Unk_HpxModel* pModel, const NiTransform& kXform)
{
    if (pModel)
    {
        Unk_HpxHairData* pData = static_cast<Unk_HpxHairData*>(pModel->FUN_141200a40()->GetItem()->FUN_140527870());
        if (pData)
        {
            int nIndex = pModel->FUN_141200ab0()->m_nIndex;
            NiPoint3 kDeg;
            FUN_141984da0(kXform.m_Rotate, kDeg);
            pData->m_akRot[nIndex] = kDeg;
            pData->m_akPos[nIndex] = kXform.m_Translate;
            pModel->FUN_141202240(kXform);
        }
    }
}
MS2_REPLACE_METHOD(0x141985210, UIHairPhysxDialog, FUN_141985210, 333, 0xCBB33673);

// The radio GetChild COMDAT (0x1419854a0; UISwfEntity::GetChild<T>, uiswfentity.inl).
template <class T> MS2Ptr<T> UISwfEntity::GetChild(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<T>(0);
    return m_30->FUN_140e159f0<T>(strName);
}
