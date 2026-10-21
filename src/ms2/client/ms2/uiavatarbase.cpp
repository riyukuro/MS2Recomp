// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uiavatarbase.h.
// MS2-UNIT: ?\uiavatarbase.cpp
// MS2-RANGE: 0x14010fe10-0x140110080 .text$di
// MS2-RANGE: 0x1418b7a10-0x1418c34c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAHAEAH$0A@@?$pair@I_K@std@@QEAA@AEAH0@Z 0x1418bfd10 ; unique
// MS2-PIN: ??$?0AEAU?$pair@I_K@std@@AEAV?$MS2Ptr@VCAvatarPackageEquip@@@@$0A@@?$pair@$$CBU?$pair@I_K@std@@V?$MS2Ptr@VCAvatarPackageEquip@@@@@std@@QEAA@AEAU?$pair@I_K@1@AEAV?$MS2Ptr@VCAvatarPackageEquip@@@@@Z 0x1418bfea0 ; unique
// MS2-PIN: ??$?0AEAHAEAJ$0A@@?$pair@I_K@std@@QEAA@AEAHAEAJ@Z 0x1418bff00 ; unique
// MS2-PIN: ??$forward@AEAV?$MS2Ptr@VCAvatarPackageEquip@@@@@std@@YAAEAV?$MS2Ptr@VCAvatarPackageEquip@@@@AEAV1@@Z 0x1418c0e90 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@I_K@std@@V?$MS2Ptr@VCAvatarPackageEquip@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@I_K@std@@V?$MS2Ptr@VCAvatarPackageEquip@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1418c0ea0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCLimitCharRotate@ItemPreviewCommon@@@@QEAA@PEAVCLimitCharRotate@ItemPreviewCommon@@@Z 0x1418c10a0 ; prop
// MS2-PIN: ?FUN_1418c14b0@Unk_UabColorElem@@QEBA_NXZ 0x1418c14b0 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@U?$pair@I_K@std@@V?$CElementTraits@U?$pair@I_K@std@@@ATL@@@ATL@@CAXPEAU?$pair@I_K@std@@_K@Z 0x1418c1af0 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCItemData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemData@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItemData@@@@_K@Z 0x1418c1b70 ; order
// MS2-PINS-END tplpin
// MS2-PIN: ??0?$CAtlArray@U?$pair@I_K@std@@V?$CElementTraits@U?$pair@I_K@std@@@ATL@@@ATL@@QEAA@XZ 0x1418c0f60
// MS2-PIN: ??1?$CAtlArray@U?$pair@I_K@std@@V?$CElementTraits@U?$pair@I_K@std@@@ATL@@@ATL@@QEAA@XZ 0x1418c1300
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCustomize@@@@QEAAAEAV1@PEAVCustomize@@@Z 0x1418c1440
// MS2-PIN: ??C?$MS2Ptr@VCAvatarPackageEquip@@@@QEBAPEAVCAvatarPackageEquip@@XZ 0x1418c15a0
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItem@@@@_K@Z 0x1418c1b30
// MS2-PIN: ??C?$MS2Ptr@VCItemData@@@@QEBAPEAVCItemData@@XZ 0x1418c1bb0
// MS2-PIN: ??7?$MS2Ptr@VCItemData@@@@QEBA_NXZ 0x1418c1d60
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCItemData@@@@@ATL@@SAXPEAV?$MS2Ptr@VCItemData@@@@0_K@Z 0x1418c1d90
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiavatarbase.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiavatarbase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <atlcoll.h>
#include <NiAVObject.h>
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/avatarcube.h"
#include "ms2/placeholder/mstime.h"

// ---- .text$di statics ---------------------------------------------------------------------------------------------

static CString s_strBuyTypeNames[8] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // 0x14010fe10
#include "ms2/placeholder/header_statics_a.h"                  // 0x14010fee0, 0x14010ffa0, 0x14010ffd0, 0x140110000
static CString s_strCap = "Cap";                                // 0x140110050

// ---- unit-local types ---------------------------------------------------------------------------------------------

// The model view of the UI (UIRenderView : NiRefObject, ?\uimodelview.cpp); only the slots used here are named.
class UIRenderView : public NiRefObject
{
public:
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float fStep);                                  // 5 0x28 zoom in
    virtual void vfunc_6(float fStep);                                  // 6 0x30 zoom out
    virtual void vfunc_7(float fX, float fY, float fZ, int bUpdate,
                         const Unk_StreamPoint* pPivot, const Unk_StreamPoint* pPivotBase);   // 7 0x38 drags the camera
    virtual void vfunc_8(float f);
    virtual void vfunc_9(float f);
};
class UIModelView : public UIRenderView
{
public:
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(const Unk_NiPoint3& kPivot);                  // 17 0x88 sets the orbit pivot
};

// The rotation limit of the drag (0x30 bytes, ctor 0x141b49c00, limit 0x141b49d40).
namespace ItemPreviewCommon
{
class CLimitCharRotate : public CPtred
{
public:
    CLimitCharRotate(float fSpeed, float fMax);                         // 0x141b49c00
    float FUN_141b49d40(float fAngle, float fRef, float fAngleY, float fBaseY);   // limits the rotation
    float m_f18, m_f1c;
    int m_n20, m_n24, m_n28, m_n2c;
};
}
MS2_CHECK_SIZE(ItemPreviewCommon::CLimitCharRotate, 0x30);

// The world manager (singleton FUN_1403ed2d0).
class Unk_UabWorld
{
public:
    GameObject* FUN_141bd1180(int nId);                                 // 0x141bd1180 NULL when the id is free
    void FUN_141bbbcf0(unsigned int nId, int bImmediate);               // 0x141bbbcf0 destroys the object
    PCBase* FUN_141bd1290(int nId);                                     // 0x141bd1290 the PC of an id
    int FUN_141bbb1e0(GameObject* pObj, int bFullInit, unsigned nCamera);   // 0x141bbb1e0 registers an object
    PCBase* FUN_141bd0cc0();                                            // 0x141bd0cc0 the local player
};
Unk_UabWorld* FUN_1403ed2d0();

// The game clock (singleton FUN_14086d260).
class Unk_UabClock;
Unk_UabClock* FUN_14086d260();
double FUN_141473280(Unk_UabClock* pClock);

NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                        // the scene root of an entity
const Unk_StreamPoint& FUN_140e69200(NiAVObject* pNode);                // local translation
Unk_NiMatrix3* FUN_1410b23c0(NiAVObject* pNode);                        // local rotation
void FUN_140981070(NiAVObject* pNode, const Unk_NiPoint3& kPos);        // SetTranslate
void FUN_140ddcca0(NiAVObject* pNode, const Unk_NiMatrix3* pRot);       // SetRotate
void FUN_1410a7800(NiAVObject* pNode, float fX, float fY, float fZ);    // SetTranslate(x, y, z)
Unk_NiPoint3 FUN_14027dcf0(const Unk_StreamPoint& kPt);                 // NiPoint3(const efd::Point3&)
void FUN_1420849a0(Unk_NiMatrix3* pMat);                                // MakeIdentity
float FUN_14059d930(float f);                                           // fabs
void* FUN_140166440();                                                  // the log
void FUN_140e68a40(void* pLog, int nLevel, int nLine, const wchar_t* szFmt,
                   const float* pA, const float* pB, const float* pC);  // formatted log (3 arguments)
void FUN_1418c1dd0(NiAVObject* pNode, Unk_NiMatrix3* pRot, const Unk_NiPoint3& kPivot, const Unk_NiPoint3& kPos);   // rotates about a pivot
const Unk_StreamPoint* FUN_140947900(NiAVObject* pNode);                // world translate
void* FUN_140994490(NiAVObject* pNode);                                 // GetWorldBound
const Unk_StreamPoint* FUN_140980350(void* pBound);                     // bound centre
int FUN_141b48430(int nKind);                                           // camera set of a kind
float FUN_141b48480(int nSet, int nIndex);                              // default angle
void FUN_1408995b0(Unk_GoModelKey* pKey);                               // Unk_GoModelKey()
extern Unk_StreamPoint DAT_143b01a60;                                   // the zero point

// The swf entity the avatar is dragged onto, and its point (the width / height are ints here).
struct Unk_UabPoint { int x; int y; };
class Unk_UISwfEntity_25
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual Unk_UabPoint* vfunc_5(Unk_UabPoint* pOut);
};
UIRenderView* FUN_140e66980(int nWidth, int nHeight, GameObject* pObj, float fScale);   // creates the view of an object
void FUN_141ab7200(UIRenderView* pView, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg);

// ---- UIAvatarBase -------------------------------------------------------------------------------------------------

// @0x1418b7a10
UIAvatarBase::UIAvatarBase()
    : m_nKind(0), m_bLoaded(0), m_nObjectId(0), m_spView(0),
      m_kAngle(DAT_143b01a60), m_kAngleBase(DAT_143b01a60), m_kPos(DAT_143b01a60), m_kPosBase(DAT_143b01a60),
      m_kPivotBase(DAT_143b01a60), m_kPivot(DAT_143b01a60),
      m_nMode(0), m_fMoveStep(0.7f), m_fRotStep(0.2f), m_fZoomStep(30.0f), m_nState(0), m_nLocked(0),
      m_bWheelCamera(false), m_pListener(0)
{
}

// @0x1418b7c00
UIAvatarBase::~UIAvatarBase()
{
    m_spView = 0;
    m_pListener = 0;
    if (m_nObjectId > 0)
        FUN_1403ed2d0()->FUN_141bbbcf0(m_nObjectId, 0);
    m_nObjectId = 0;
}

// @0x1418b7cd0
void UIAvatarBase::vfunc_1(IUIAvatarEventListener* pListener)
{
    m_pListener = pListener;
}
MS2_REPLACE_METHOD(0x1418B7CD0, UIAvatarBase, vfunc_1, 28, 0x7D973C77);

// @0x1418b7d00
void UIAvatarBase::vfunc_2()
{
}

// @0x1418b7d10
void UIAvatarBase::vfunc_3()
{
}

// @0x1418b7d20
void UIAvatarBase::vfunc_4(__int64 nItemUid)
{
}

// @0x1418b7d40
void UIAvatarBase::vfunc_5()
{
    if (FUN_1418b9b80() == 0)
        return;
    if (m_spView)
        m_spView->vfunc_5(m_fZoomStep);
}
MS2_REPLACE_METHOD(0x1418B7D40, UIAvatarBase, vfunc_5, 103, 0xD0149146);

// @0x1418b7db0
void UIAvatarBase::vfunc_6()
{
    if (FUN_1418b9b80() == 0)
        return;
    if (m_spView)
        m_spView->vfunc_6(m_fZoomStep);
}
MS2_REPLACE_METHOD(0x1418B7DB0, UIAvatarBase, vfunc_6, 103, 0x89FCB062);

// @0x1418b7e20
void UIAvatarBase::vfunc_7(float n)
{
    if (FUN_1418b9b80() == 0)
        return;
    if (m_spView)
        m_spView->vfunc_9(n);
}
MS2_REPLACE_METHOD(0x1418B7E20, UIAvatarBase, vfunc_7, 102, 0x8C6A2478);

// @0x1418b7e90
void UIAvatarBase::vfunc_8(float n)
{
    if (FUN_1418b9b80() == 0)
        return;
    if (m_spView)
        m_spView->vfunc_8(n);
}
MS2_REPLACE_METHOD(0x1418B7E90, UIAvatarBase, vfunc_8, 102, 0x80C33D6C);

// @0x1418b7f00
void UIAvatarBase::vfunc_10(int dx, int dy, int dz, int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj == 0)
        return;
    NiAVObject* pNode = FUN_141b6efc0(pObj->FUN_14123c410());
    if (pNode == 0)
        return;
    float fY = (float)dx * m_fRotStep;
    float fX = (float)dy * m_fRotStep;
    float fZ = -((float)dz * m_fRotStep);
    Unk_StreamPoint kDelta(fX, fY, fZ);
    Unk_StreamPoint kNewPos = kDelta.FUN_14097fd50(m_kPosBase);
    float fLimit = m_kPivot.z;
    Unk_StreamPoint kTarget = kDelta.FUN_14097fd50(m_kPivotBase);
    if (fLimit < m_kPos.FUN_140965c40(kTarget).FUN_140967ac0())
    {
        float fClamp;
        if (fLimit < FUN_14059d930(m_kPos.x - kTarget.x))
        {
            fClamp = fLimit;
            if (0.0f < m_kPos.x - kTarget.x)
                fClamp = -fLimit;
            kTarget.x = m_kPos.x + fClamp;
        }
        if (fLimit < FUN_14059d930(m_kPos.y - kTarget.y))
        {
            fClamp = fLimit;
            if (0.0f < m_kPos.y - kTarget.y)
                fClamp = -fLimit;
            kTarget.y = m_kPos.y + fClamp;
        }
        if (fLimit < FUN_14059d930(m_kPos.z - kTarget.z))
        {
            fClamp = fLimit;
            if (0.0f < m_kPos.z - kTarget.z)
                fClamp = -fLimit;
            kTarget.z = m_kPos.z + fClamp;
        }
        Unk_StreamPoint kRotated = FUN_1410b23c0(pNode)->FUN_140a00720(m_kPivot);
        kNewPos = kTarget.FUN_14097fd50(m_kPivot).FUN_140965c40(kRotated);
    }
    FUN_140981070(pNode, FUN_14027dcf0(kNewPos));
    if (bUpdate)
        pNode->Update((float)FUN_141473280(FUN_14086d260()), true);
}

// @0x1418b8300
void UIAvatarBase::vfunc_11(int dx, int dy, int dz, int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    float fX = -((float)dx * m_fMoveStep);
    float fY = -((float)dy * m_fMoveStep);
    float fZ = -((float)dz * m_fMoveStep);
    Unk_StreamPoint kDelta(fX, fY, fZ);
    float fWrapX = kDelta.x;
    float fWrapY = kDelta.y;
    float fWrapZ = kDelta.z;
    FUN_1418bf270(&fWrapX);
    FUN_1418bf270(&fWrapY);
    FUN_1418bf270(&fWrapZ);
    FUN_1418ba200(&m_kAngleBase, fWrapX, fWrapY, fWrapZ);
    if (m_spView)
        m_spView->vfunc_7(fX, fY, fZ, bUpdate, &m_kPivot, &m_kPivotBase);
}
MS2_REPLACE_METHOD(0x1418B8300, UIAvatarBase, vfunc_11, 439, 0xE0EE83C6);

// @0x1418b84c0
void UIAvatarBase::vfunc_12(const Unk_StreamPoint& kDelta, Unk_StreamPoint& kRot)
{
    if (m_spRotLimit == 0)
        return;
    if (kRot.y != 0.0f)
        kRot.y = m_spRotLimit->FUN_141b49d40(kRot.y, kDelta.y, m_kAngle.y, m_kAngleBase.y);
}
MS2_REPLACE_METHOD(0x1418B84C0, UIAvatarBase, vfunc_12, 151, 0x9A7F514C);

// @0x1418b8560
void UIAvatarBase::vfunc_14(int dx, int dy, int dz, int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->FUN_14123c410());
        if (pNode == 0)
            return;
        float fZ = -((float)dz * m_fMoveStep);
        if (90.0f < m_kAngle.y && m_kAngle.y < 270.0f)
            fZ = -fZ;
        Unk_StreamPoint kDelta(-((float)dx * m_fMoveStep), -((float)dy * m_fMoveStep), fZ);
        Unk_StreamPoint kRot = kDelta.FUN_14097fd50(m_kAngle);
        vfunc_12(kDelta, kRot);
        vfunc_13(kRot.x, kRot.y, kRot.z, &m_kPivot, &m_kPivotBase, bUpdate);
    }
}

// @0x1418b8750
void UIAvatarBase::vfunc_13(float rx, float ry, float rz, const Unk_StreamPoint* pPivot, const Unk_StreamPoint* pPos, int bUpdate)
{
    float fRx = rx;
    float fRy = ry;
    float fRz = rz;
    if (FUN_1418b9b80() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->FUN_14123c410());
        if (pNode)
        {
            FUN_1418bf270(&fRx);
            FUN_1418bf270(&fRy);
            FUN_1418bf270(&fRz);
            FUN_1418ba200(&m_kAngleBase, fRx, fRy, fRz);
            if (FUN_140166440())
                FUN_140e68a40(FUN_140166440(), 0xb, 0x135, L"avatarDegree: {0}, {1}, {2}", &m_kAngleBase.x, &m_kAngleBase.y, &m_kAngleBase.z);
            Unk_NiMatrix3 kRot;
            FUN_1420849a0(&kRot);
            float fRadX = (fRx * 3.1415927f) / 180.0f;
            float fRadY = (fRy * 3.1415927f) / 180.0f;
            float fRadZ = (fRz * 3.1415927f) / 180.0f;
            kRot.FUN_142083d40(fRadX, fRadY, fRadZ);
            FUN_1418c1dd0(pNode, &kRot, FUN_14027dcf0(*pPivot), FUN_14027dcf0(*pPos));
            if (bUpdate)
                pNode->Update((float)FUN_141473280(FUN_14086d260()), true);
        }
    }
}

// @0x1418b89f0
void UIAvatarBase::vfunc_15(float rx, float ry, float rz, int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->FUN_14123c410());
        if (pNode)
        {
            const Unk_StreamPoint& kPos = FUN_140e69200(pNode);
            vfunc_13(rx, ry, rz, &m_kPivot, &kPos, bUpdate);
            FUN_1418ba250(&m_kAngle, &m_kAngleBase);
        }
    }
}

// @0x1418b8b00
void UIAvatarBase::vfunc_16(int n, int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj != 0)
    {
        Unk_StreamPoint kAngle = Unk_StreamPoint(0.0f, (float)n * m_fMoveStep, 0.0f).FUN_14097fd50(m_kAngle);
        FUN_1418bf270(&kAngle.y);
        vfunc_20(kAngle.x, kAngle.y, kAngle.z, bUpdate);
        FUN_1418ba250(&m_kAngleBase, &kAngle);
    }
}

// @0x1418b8c20
void UIAvatarBase::vfunc_17(float f, int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    if (vfunc_23())
    {
        Unk_StreamPoint kAngle(0.0f, f, 0.0f);
        FUN_1418bf270(&kAngle.y);
        vfunc_20(kAngle.x, kAngle.y, kAngle.z, bUpdate);
        FUN_1418ba250(&m_kAngle, &kAngle);
        FUN_1418ba250(&m_kAngleBase, &m_kAngle);
    }
}

// @0x1418b8d00
void UIAvatarBase::vfunc_18(int n, int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    if (vfunc_23())
    {
        Unk_StreamPoint kAngle = Unk_StreamPoint(0.0f, 0.0f, (float)n * m_fMoveStep).FUN_14097fd50(m_kAngle);
        FUN_1418bf270(&kAngle.z);
        vfunc_20(kAngle.x, kAngle.y, kAngle.z, bUpdate);
        FUN_1418ba250(&m_kAngleBase, &kAngle);
    }
}

// @0x1418b8e20
void UIAvatarBase::vfunc_19(float f, int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    if (vfunc_23())
    {
        Unk_StreamPoint kAngle(0.0f, 0.0f, f);
        FUN_1418bf270(&kAngle.z);
        vfunc_20(kAngle.x, kAngle.y, kAngle.z, bUpdate);
        FUN_1418ba250(&m_kAngle, &kAngle);
        FUN_1418ba250(&m_kAngleBase, &m_kAngle);
    }
}

// @0x1418b8f00
void UIAvatarBase::vfunc_20(float x, float y, float z, int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    Unk_StreamPoint kAngle(x, y, z);
    vfunc_12(DAT_143b01a60, kAngle);
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->FUN_14123c410());
        if (pNode)
        {
            Unk_NiMatrix3 kRot;
            FUN_1420849a0(&kRot);
            float fRadX;
            if (x <= 0.0f)
                fRadX = 0.0f;
            else
                fRadX = (x * 3.1415927f) / 180.0f;
            float fRadY;
            if (y <= 0.0f)
                fRadY = 0.0f;
            else
                fRadY = (y * 3.1415927f) / 180.0f;
            float fRadZ;
            if (z <= 0.0f)
                fRadZ = 0.0f;
            else
                fRadZ = (z * 3.1415927f) / 180.0f;
            kRot.FUN_142083d40(fRadX, fRadY, fRadZ);
            FUN_140ddcca0(pNode, &kRot);
            if (bUpdate)
                pNode->Update((float)FUN_141473280(FUN_14086d260()), true);
        }
    }
}

// @0x1418b9140
void UIAvatarBase::vfunc_9(float x, float y, float z, int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj == 0)
        return;
    NiAVObject* pNode = FUN_141b6efc0(pObj->FUN_14123c410());
    if (pNode == 0)
        return;
    FUN_1410a7800(pNode, x, y, z);
    if (bUpdate)
        pNode->Update((float)FUN_141473280(FUN_14086d260()), true);
}

// @0x1418b9200
void UIAvatarBase::vfunc_21(UIRenderView* pView)
{
    if (m_spView)
        m_spView = 0;
    m_spView = pView;
    vfunc_29(pView != 0);
}
MS2_REPLACE_METHOD(0x1418B9200, UIAvatarBase, vfunc_21, 131, 0x297A6C92);

// @0x1418b9290
void UIAvatarBase::vfunc_22()
{
}
MS2_REPLACE_METHOD(0x1418B9290, UIAvatarBase, vfunc_22, 6, 0xA9AF6E37);

// @0x1418b92a0
GameObject* UIAvatarBase::vfunc_23()
{
    return vfunc_24();
}
MS2_REPLACE_METHOD(0x1418B92A0, UIAvatarBase, vfunc_23, 33, 0xFA59B52F);

// @0x1418b92d0
GameObject* UIAvatarBase::vfunc_24()
{
    if (m_nObjectId > 0)
        return FUN_1403ed2d0()->FUN_141bd1180(m_nObjectId);
    return 0;
}
MS2_REPLACE_METHOD(0x1418B92D0, UIAvatarBase, vfunc_24, 50, 0xB89C59A3);

// @0x1418b9310
int UIAvatarBase::vfunc_25()
{
    return m_nObjectId;
}
MS2_REPLACE_METHOD(0x1418B9310, UIAvatarBase, vfunc_25, 14, 0xD26D6807);

// @0x1418b9330
Unk_GoModelKey* UIAvatarBase::vfunc_26(Unk_GoModelKey* pKey)
{
    GameObject* pObj = vfunc_24();
    if (pObj != 0)
    {
        pObj->FUN_14123c460(*pKey);
        return pKey;
    }
    FUN_1408995b0(pKey);
    return pKey;
}

// @0x1418b9390
int UIAvatarBase::vfunc_27(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (FUN_1418b9b80() == 0)
        return 0;
    if (_stricmp("OnAvatarMouseDown", szEvent) == 0)
    {
        ASData kData;
        if (kData.FUN_1422b9620(pArgs, nArgs))
        {
            int nButton = kData.FUN_1422b8a10();
            if (FUN_1418ba160(nButton) != 0)
            {
                if (m_nLocked == 0 && m_nMode == 2)
                {
                    FUN_1418ba120(0);
                    return 1;
                }
                FUN_1418b9c10();
            }
            return 1;
        }
    }
    else
    {
        if (_stricmp("OnAvatarMouseWheel", szEvent) == 0)
        {
            ASData kData;
            if (kData.FUN_1422b9620(pArgs, nArgs))
            {
                if (kData.FUN_1422b8a10() < 1)
                    vfunc_6();
                else
                    vfunc_5();
            }
            return 1;
        }
        if (_stricmp("OnAvatarMouseMove", szEvent) == 0)
        {
            ASData kData;
            if (kData.FUN_1422b9620(pArgs, nArgs))
            {
                int nDx = kData.FUN_1422b8a10();
                int nDy = kData.FUN_1422b8a10();
                int nButton = kData.FUN_1422b8a10();
                int nMode = FUN_1418ba140();
                if (FUN_1418ba1a0(nButton) != nMode)
                    return 1;
                if (abs(nDx) > 2 || abs(nDy) > 2)
                {
                    if (m_nLocked == 0 || nMode != 2)
                    {
                        if (nMode == 1)
                            vfunc_14(0, nDy, nDx, 1);
                        else if (nMode == 3)
                            vfunc_11(0, nDy, nDx, 0);
                    }
                    else
                        vfunc_10(nDx, 0, nDy, 0);
                }
            }
            return 1;
        }
    }
    return 0;
}

// @0x1418b9730
void UIAvatarBase::vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg)
{
    GameObject* pObj = vfunc_24();
    if (pObj)
    {
        Unk_UabPoint kPtA;
        Unk_UabPoint kPtB;
        Unk_UISwfEntity_25* pEntA = spTarget.get();
        Unk_UISwfEntity_25* pEntB = spTarget.get();
        UIRenderView* pView = FUN_140e66980(pEntB->vfunc_5(&kPtB)->x, pEntA->vfunc_5(&kPtA)->y, pObj, 0.9f);
        if (pView)
        {
            FUN_141ab7200(pView, TPtr<Unk_UISwfEntity_25>(spTarget), pArg);
            vfunc_21(pView);
        }
    }
}
MS2_REPLACE_METHOD(0x1418B9730, UIAvatarBase, vfunc_28, 321, 0x52FA4849);

// @0x1418b9880 (secondary vftable: the listener slots)
int UIAvatarBase::vfunc_0(GameObject* pObj)
{
    if (pObj && m_nObjectId == pObj->FUN_14123c580())
    {
        FUN_1418b9b60(1);
        vfunc_22();
        FUN_1418b9e40();
        if (m_pListener)
            m_pListener->vfunc_o178_1(this);
        return 1;
    }
    return 0;
}

// @0x1418b9970
int UIAvatarBase::vfunc_2(GameObject* pObj)
{
    if (pObj && m_nObjectId == pObj->FUN_14123c580())
    {
        if (m_pListener)
            m_pListener->vfunc_o178_0(this);
        return 1;
    }
    return 0;
}

// @0x1418b9a00
int UIAvatarBase::vfunc_3(GameObject* pObj)
{
    if (pObj && m_nObjectId == pObj->FUN_14123c580())
    {
        FUN_1418b9b60(0);
        return 1;
    }
    return 0;
}

// @0x1418b9a60
int UIAvatarBase::vfunc_4(GameObject* pObj)
{
    if (pObj && m_nObjectId == pObj->FUN_14123c580())
    {
        FUN_1418b9b60(1);
        if (m_pListener)
            m_pListener->vfunc_o178_2(this);
        FUN_1418b9e40();
        return 1;
    }
    return 0;
}

// @0x1418b9b20
void UIAvatarBase::vfunc_29(int n)
{
    m_nState = n;
}
MS2_REPLACE_METHOD(0x1418B9B20, UIAvatarBase, vfunc_29, 25, 0x79F379CB);

// @0x1418b9b40
int UIAvatarBase::FUN_1418b9b40()
{
    return m_nState;
}
MS2_REPLACE_METHOD(0x1418B9B40, UIAvatarBase, FUN_1418b9b40, 17, 0x444DCEE7);

// @0x1418b9b60
void UIAvatarBase::FUN_1418b9b60(int bLoaded)
{
    m_bLoaded = bLoaded;
}
MS2_REPLACE_METHOD(0x1418B9B60, UIAvatarBase, FUN_1418b9b60, 22, 0x5ED7A56F);

// @0x1418b9b80
int UIAvatarBase::FUN_1418b9b80()
{
    return m_bLoaded;
}
MS2_REPLACE_METHOD(0x1418B9B80, UIAvatarBase, FUN_1418b9b80, 14, 0xBA6447E3);

// @0x1418b9ba0
int UIAvatarBase::FUN_1418b9ba0()
{
    return m_nKind;
}
MS2_REPLACE_METHOD(0x1418B9BA0, UIAvatarBase, FUN_1418b9ba0, 14, 0xA25B27BF);

// @0x1418b9bc0
efd::SmartPointer<UIRenderView> UIAvatarBase::FUN_1418b9bc0()
{
    return m_spView;
}
MS2_REPLACE_METHOD(0x1418B9BC0, UIAvatarBase, FUN_1418b9bc0, 65, 0x23CF6EC9);

// @0x1418b9c10
void UIAvatarBase::FUN_1418b9c10()
{
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->FUN_14123c410());
        if (pNode)
        {
            Unk_NiMatrix3* pRot = FUN_1410b23c0(pNode);
            FUN_1418ba250(&m_kAngle, &m_kAngleBase);
            const Unk_StreamPoint& kPos = FUN_140e69200(pNode);
            m_kPosBase = kPos;
            if (m_kAngleBase.FUN_140552700(DAT_143b01a60))
                FUN_1418ba4a0(pRot, &kPos, &m_kPos);
            else
                m_kPos = m_kPosBase;
            if (m_spView)
            {
                UIModelView* pModelView = dynamic_cast<UIModelView*>((UIRenderView*)m_spView);
                if (pModelView)
                    pModelView->vfunc_17(FUN_14027dcf0(kPos.FUN_14097fd50(m_kPivot)));
            }
        }
    }
}

// @0x1418b9df0
void UIAvatarBase::FUN_1418b9df0(bool bAngle, bool bPosition)
{
    if (bAngle)
        FUN_1418ba340(0);
    if (bPosition)
        FUN_1418ba280(0);
}
MS2_REPLACE_METHOD(0x1418B9DF0, UIAvatarBase, FUN_1418b9df0, 65, 0xB30BF4F3);

// @0x1418b9e40
void UIAvatarBase::FUN_1418b9e40()
{
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->FUN_14123c410());
        if (pNode)
        {
            m_kPos = FUN_140e69200(pNode);
            m_kPosBase = m_kPos;
            m_kPivotBase = m_kPos;
            float fBody = 0.0f;
            NiFixedString kName("Eff_Body");
            NiAVObject* pBody = pNode->GetObjectByName(kName);
            if (pBody)
                fBody = FUN_140947900(pBody)->FUN_140965c40(m_kPos).FUN_140967ac0();
            float fHeight = FUN_140980350(FUN_140994490(pNode))->z - m_kPos.z;
            float fExtra = fHeight - fBody;
            if (0.0f < fBody && 25.0f < fExtra)
                fHeight = fBody + 25.0f;
            m_kPivot = Unk_StreamPoint(0.0f, 0.0f, fHeight);
            NiPoint3 kRaw = pObj->vfunc_20();
            Unk_StreamPoint kAngle(kRaw.x, kRaw.y, kRaw.z);
            FUN_1410b23c0(pNode)->FUN_142085840(kAngle.x, kAngle.y, kAngle.z);
            kAngle.x = (kAngle.x * 180.0f) / 3.1415927f;
            kAngle.y = (kAngle.y * 180.0f) / 3.1415927f;
            kAngle.z = (kAngle.z * 180.0f) / 3.1415927f;
            FUN_1418bf1e0(&kAngle);
            m_kAngle = kAngle;
            m_kAngleBase = kAngle;
        }
    }
}

// @0x1418ba120
void UIAvatarBase::FUN_1418ba120(int nMode)
{
    m_nMode = nMode;
}
MS2_REPLACE_METHOD(0x1418BA120, UIAvatarBase, FUN_1418ba120, 25, 0xE467F5FB);

// @0x1418ba140
int UIAvatarBase::FUN_1418ba140()
{
    return m_nMode;
}
MS2_REPLACE_METHOD(0x1418BA140, UIAvatarBase, FUN_1418ba140, 17, 0xD9D952B7);

// @0x1418ba160
int UIAvatarBase::FUN_1418ba160(int nButton)
{
    m_nMode = FUN_1418ba1a0(nButton);
    return m_nMode;
}
MS2_REPLACE_METHOD(0x1418BA160, UIAvatarBase, FUN_1418ba160, 54, 0x8F49F212);

// @0x1418ba1a0
int UIAvatarBase::FUN_1418ba1a0(int nButton)
{
    if (nButton == 0)
        return 2;
    else if (nButton == 1)
        return m_bWheelCamera ? 3 : 1;
    return 0;
}

// @0x1418ba200
void UIAvatarBase::FUN_1418ba200(Unk_StreamPoint* pDst, float x, float y, float z)
{
    pDst->x = x;
    pDst->y = y;
    pDst->z = z;
}
MS2_REPLACE_METHOD(0x1418BA200, UIAvatarBase, FUN_1418ba200, 70, 0x3C835994);

// @0x1418ba250
void UIAvatarBase::FUN_1418ba250(Unk_StreamPoint* pDst, const Unk_StreamPoint* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE_METHOD(0x1418BA250, UIAvatarBase, FUN_1418ba250, 39, 0xE8027097);

// @0x1418ba280
void UIAvatarBase::FUN_1418ba280(int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    if (vfunc_23())
    {
        vfunc_9(m_kPos.x, m_kPos.y, m_kPos.z, bUpdate);
        m_kPosBase = m_kPos;
        m_kPivotBase = m_kPos;
    }
}

// @0x1418ba340
void UIAvatarBase::FUN_1418ba340(int bUpdate)
{
    if (FUN_1418b9b80() == 0)
        return;
    Unk_StreamPoint kAngle;
    FUN_1418ba410(&kAngle);
    vfunc_9(kAngle.x, kAngle.y, kAngle.z, 0);
    int nSet = FUN_141b48430(FUN_1418b9ba0());
    vfunc_19(FUN_141b48480(nSet, 0), bUpdate);
}
MS2_REPLACE_METHOD(0x1418BA340, UIAvatarBase, FUN_1418ba340, 160, 0xB1D02095);

// @0x1418ba3f0
void UIAvatarBase::FUN_1418ba3f0(int n)
{
    m_nLocked = n;
}
MS2_REPLACE_METHOD(0x1418BA3F0, UIAvatarBase, FUN_1418ba3f0, 25, 0x9EB3CF4F);

// @0x1418ba410
void UIAvatarBase::FUN_1418ba410(Unk_StreamPoint* pOut)
{
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->FUN_14123c410());
        if (pNode == 0)
            return;
        Unk_NiMatrix3* pRot = FUN_1410b23c0(pNode);
        FUN_1418ba4a0(pRot, &FUN_140e69200(pNode), pOut);
    }
}

// @0x1418ba4a0
void UIAvatarBase::FUN_1418ba4a0(Unk_NiMatrix3* pRot, const Unk_StreamPoint* pPos, Unk_StreamPoint* pOut)
{
    if (m_kAngleBase.FUN_140552700(DAT_143b01a60))
    {
        Unk_StreamPoint kRotated = pRot->FUN_140a00720(m_kPivot);
        *pOut = pPos->FUN_140965c40(m_kPivot).FUN_14097fd50(kRotated);
    }
    else
        *pOut = *pPos;
}

// ---- UIAvatarPC ---------------------------------------------------------------------------------------------------

// The pc record UIAvatarPC mirrors (avatarpc.cpp).
class Unk_PCArg125 : public CPtred
{
public:
    char m_pad_18[0x18];
    unsigned __int64 m_nPcId;                                           // +0x30
};

// The character customize of the preview (0x88, ctor 0x140cd1570); only the members used here are named.
class Customize : public CPtred
{
public:
    Customize(int nObjectId, int nZero, bool bFlag);                    // 0x140cd1570
    void FUN_140cd1c90(CItem* pItem);                                   // equips an item
    void FUN_140cd1d50(int nValue);
    void FUN_140cd1e80();                                               // clears the items
    void FUN_140cd1ed0(CItem* pItem);                                   // unequips an item
    void FUN_140cd1f30(int nValue);
    void FUN_140cd1f90(CItem* pItem);
    void FUN_140cd20c0();                                               // resets
    void FUN_140cd23e0(MS2Ptr<CItem> spItem, int nValue);
    void FUN_140cd3480(int nValue, int nMode);
private:
    char m_unk_18[0x70];
};
MS2_CHECK_SIZE(Customize, 0x88);

// The equipment record of an inventory slot and the player that owns the inventory.
class Unk_UabEquip : public CPtred
{
public:
    CItem* FUN_1411dc870();                                             // the equipped item
};
class Unk_UabPlayer : public PCBase
{
public:
    MS2Ptr<CItem> FUN_141655b80(__int64 nItemUid);                      // item of an uid
    MS2Ptr<Unk_UabEquip> FUN_141655cf0(int nSlot);                      // equipped item of a slot
    MS2Ptr<Unk_UabEquip> FUN_141655c90(int nSlot);                      // equipped item of a slot (second table)
};
Unk_UabPlayer* FUN_14099eef0(GameObject* pObj);                         // the PC of an object (NULL if it is none)
AvatarPC* FUN_140a535c0(GameObject* pObj);                              // the AvatarPC of an object (NULL if it is none)

// The client constants used by the rotation limit.
struct Unk_UabCfgFloat { float FUN_1402bac70(); char m_pad[0x54]; };
struct Unk_UabCfgInt { int* FUN_1402056b0(); char m_pad[0x54]; };
struct Unk_UabConfig { char m_pad0[0xc6b8]; Unk_UabCfgFloat m_fRotateSpeed; Unk_UabCfgInt m_nRotateMax; };
Unk_UabConfig* FUN_1401d3200();
float FUN_1418bffd0(Unk_UabCfgInt* pValue);                             // the int value as a float

int FUN_141658e60(PCBase* pPc);                                         // the state of a PC
CItemData* FUN_140527840(CItem* pItem);                                 // the item data of an item
int FUN_14053c5c0(CItemData* pData);                                    // the item type (0x19 = cube item set)
bool FUN_14053d2b0(CItemData* pData);
bool FUN_14053d460(CItemData* pData);
bool FUN_14053cc00(CItemData* pData);
bool FUN_1405729c0(const ATL::CAtlArray<MS2Ptr<CItemData> >* pArray);      // array is empty
MS2Ptr<CItemData> FUN_1403bb3b0(const MS2Ptr<CItemData>& sp);

// The ingredient table row of a skin colour (FUN_140281980 / avatarpc.cpp).
struct Unk_UabPresetRow { char m_pad_00[0x3c]; unsigned m_nColorA; int m_n40; unsigned m_nColorB; };
class Unk_UabPresetPtr
{
public:
    ~Unk_UabPresetPtr() { FUN_14056c2d0(); }
    void FUN_14056c2d0();                                               // release
    Unk_UabPresetRow* FUN_14059cf00() const;                            // get
    Unk_UabPresetRow* FUN_14056d570() const;                            // operator->
    bool FUN_14056cf90(int n) const;                                    // operator==(NULL)
    Unk_UabPresetRow* FUN_14056d630() const;                            // the row
    void* m_pad_00;
    Unk_UabPresetRow* m_p;
};
class Unk_UabColorSet;
class Unk_UabIngTable { public: Unk_UabPresetPtr FUN_1405587f0(int nId, int n); Unk_UabColorSet FUN_140558ad0(int nId); };
Unk_UabIngTable* FUN_140281980();
void FUN_141423cf0(__int64 nItemUid, Unk_UabPresetRow* pRow, AvatarPC* pAvatar, int n);   // plays the effect of a row on an item
Unk_CharEquip FUN_141b6dea0(unsigned uColor);                           // colour value -> equip record

// Item data -> customize range (the morph range of the first section).
struct Unk_UabRangeList { int FUN_1405451a0(); };
struct Unk_UabSection { Unk_UabRangeList* FUN_14054b2f0(int nKind); };
Unk_UabSection* FUN_14053eba0(CItemData* pData);
int FUN_141420a30(int nRange, CItem* pItem, Unk_UabPlayer* pPlayer);    // the customize id of an item

// Avatar state helpers.
void FUN_14166cc40(PCBase* pPc, int nParam);                            // sets the action parameter
void FUN_14166ce70(PCBase* pPc, int nValue);
void FUN_141653f00(PCBase* pPc);
bool FUN_14096ad40(const efd::utf8string& str);                         // string is empty
CString FUN_1409a2360(const char* psz, int n);                          // converts the string

// @0x1418ba570
UIAvatarPC::UIAvatarPC(PC* pSource, bool bFlag)
    : m_spCustomize(0), m_bFlag(bFlag), m_nPose(0), m_nAction(1), m_nActionParam(10)
{
    m_nKind = 1;
    AvatarPC* pAvatar = FUN_1409f3410(pSource);
    if (pAvatar)
    {
        pAvatar->FUN_1409f5040(this);
        m_nObjectId = pAvatar->FUN_14123c580();
        FUN_1418bd780(pSource, pAvatar);
    }
}

// @0x1418ba6b0
UIAvatarPC::UIAvatarPC(int nGender, bool bFlag)
    : m_spCustomize(0), m_bFlag(bFlag), m_nPose(0), m_nAction(1), m_nActionParam(10)
{
    m_nKind = 1;
    AvatarPC* pAvatar = FUN_1409f3650(nGender, 10000);
    if (pAvatar)
    {
        pAvatar->FUN_1409f5040(this);
        m_nObjectId = pAvatar->FUN_14123c580();
        FUN_1418bd780(0, pAvatar);
    }
}

// @0x1418ba7f0
UIAvatarPC::UIAvatarPC(MS2Ptr<Unk_PCArg125> spSrc, bool bFlag)
    : m_spCustomize(0), m_bFlag(bFlag), m_nPose(0), m_nAction(1), m_nActionParam(10)
{
    m_nKind = 1;
    AvatarPC* pAvatar = FUN_1409f3fd0(spSrc);
    if (pAvatar)
    {
        pAvatar->FUN_1409f5040(this);
        m_nObjectId = pAvatar->FUN_14123c580();
        FUN_1418bd780(0, pAvatar);
    }
}

// @0x1418ba950
UIAvatarPC::~UIAvatarPC()
{
    m_spCustomize = 0;
    m_mapPackages.clear();
}

// @0x1418ba9f0
void UIAvatarPC::vfunc_1(IUIAvatarEventListener* pListener)
{
    UIAvatarBase::vfunc_1(pListener);
    m_spRotLimit.AssignRaw(new ItemPreviewCommon::CLimitCharRotate(FUN_1401d3200()->m_fRotateSpeed.FUN_1402bac70(),
                                                                   FUN_1418bffd0(&FUN_1401d3200()->m_nRotateMax)));
}

// @0x1418baab0
void UIAvatarPC::vfunc_2()
{
    UIAvatarBase::vfunc_2();
    if (m_spCustomize.get())
        m_spCustomize->FUN_140cd20c0();
    m_mapPackages.clear();
}
MS2_REPLACE_METHOD(0x1418BAAB0, UIAvatarPC, vfunc_2, 94, 0x5098D0EE);

// @0x1418bab20
void UIAvatarPC::vfunc_21(UIRenderView* pView)
{
    UIAvatarBase::vfunc_21(pView);
    AvatarPC* pAvatar = FUN_140a535c0(vfunc_24());
    if (pAvatar)
    {
        pAvatar->vfunc_147((UIModelView*)pView);   // MS2: slot 147
        pAvatar->FUN_141087220(pView == 0);
    }
}
MS2_REPLACE_METHOD(0x1418BAB20, UIAvatarPC, vfunc_21, 133, 0x31E4CE77);

// @0x1418babb0
GameObject* UIAvatarPC::vfunc_23()
{
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar && pAvatar->FUN_1409f4f20())
    {
        unsigned nRideeId = pAvatar->FUN_1409f6450();
        if (nRideeId > 0)
            return FUN_1403ed2d0()->FUN_141bd1180(nRideeId);
    }
    return UIAvatarBase::vfunc_24();
}

// @0x1418bac20
int UIAvatarPC::vfunc_27(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIAvatarBase::vfunc_27(szEvent, pArgs, nArgs))
        return 1;
    if (_stricmp("OnAvatarSkinColor", szEvent) == 0)
    {
        ASData kData;
        if (kData.FUN_1422b9620(pArgs, nArgs))
        {
            int nColorA = kData.FUN_1422b8b10();
            int nColorB = kData.FUN_1422b8b10();
            Unk_CharEquip kEquip1 = FUN_141b6dea0(nColorB);
            Unk_CharEquip kEquip0 = FUN_141b6dea0(nColorA);
            FUN_1418bca10(kEquip0, kEquip1);
        }
        return 1;
    }
    if (_stricmp("OnAvatarClickPose", szEvent) == 0)
    {
        ASData kData;
        if (kData.FUN_1422b9620(pArgs, nArgs))
            FUN_1418bd860(kData.FUN_1422b8a10());
        return 1;
    }
    return 0;
}

// @0x1418bae00
int UIAvatarPC::vfunc_0(GameObject* pObj)
{
    m_spCustomize.AssignRaw(new Customize(vfunc_25(), 0, m_bFlag));
    int nResult = UIAvatarBase::vfunc_0(pObj);
    FUN_1418bc790(m_nAction, m_nActionParam);
    return nResult;
}

// @0x1418baef0
void UIAvatarPC::FUN_1418baef0(int nValue)
{
    if (m_spCustomize.get())
        m_spCustomize->FUN_140cd1d50(nValue);
}
MS2_REPLACE_METHOD(0x1418BAEF0, UIAvatarPC, FUN_1418baef0, 73, 0x234AD161);

// @0x1418baf40
void UIAvatarPC::FUN_1418baf40(CItem* pItem)
{
    if (m_spCustomize.get())
        m_spCustomize->FUN_140cd1c90(pItem);
}
MS2_REPLACE_METHOD(0x1418BAF40, UIAvatarPC, FUN_1418baf40, 75, 0x86EAC9CE);

// @0x1418bafa0
void UIAvatarPC::FUN_1418bafa0(CItem* pItem, int nEffect)
{
    if (m_spCustomize == 0)
        return;
    m_spCustomize->FUN_140cd1c90(pItem);
    if (0 < nEffect)
    {
        AvatarPC* pAvatar = FUN_140a535c0(vfunc_24());
        if (pAvatar == 0)
            return;
        Unk_UabPresetPtr kRow = FUN_140281980()->FUN_1405587f0(nEffect, 0);
        if (kRow.FUN_14056cf90(0))
            return;
        FUN_141423cf0(pItem->FUN_140526a50(), kRow.FUN_14056d630(), pAvatar, 0);
    }
}

// @0x1418bb0c0
bool UIAvatarPC::FUN_1418bb0c0(CItem* pItem)
{
    return FUN_1418bb0f0(pItem, 0);
}

bool FUN_1418bf430(MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems, ATL::CAtlArray<MS2Ptr<CItemData> >* pOthers);   // walks the drops of a cube item set
void FUN_140526c10(CItem* pItem, int nCustomizeId);
void FUN_140526b30(CItem* pItem, int nObjectId);
Unk_InventoryEquipSlot FUN_140526c30(CItem* pItem);                                        // the equip slot of an item
int FUN_141420f10(CItemData* pData, AvatarPC* pAvatar);                 // the customize id of an item data
__int64 FUN_14028d0e0();                                                // next item uid
MS2_REPLACE_METHOD(0x1418BB0C0, UIAvatarPC, FUN_1418bb0c0, 37, 0xF0568DFA);

// @0x1418bb0f0
bool UIAvatarPC::FUN_1418bb0f0(CItem* pItem, int nEffect)
{
    if (m_spCustomize == 0)
        return false;
    if (pItem)
    {
        MS2Ptr<CItemData> spData(FUN_140527840(pItem));
        if (!(spData == 0))
        {
            if (FUN_14053c5c0(spData.operator->()) == 0x19)
            {
                ATL::CAtlArray<MS2Ptr<CItemData> > kItems;
                ATL::CAtlArray<MS2Ptr<CItemData> > kOthers;
                if (FUN_1418bf430(MS2Ptr<CItemData>(spData), &kItems, &kOthers))
                    return FUN_1418bb2a0(MS2Ptr<CItemData>(spData), nEffect, &kItems);
                return false;
            }
        }
    }
    return false;
}

// The exe's map::insert(pair&&) hands the pair straight to _Insert_nohint (this STL routes it through emplace), so the
// protected tree op is reached through a layout-identical view of m_mapPackages.
typedef std::pair<const Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> > Unk_AvPackagePair;
class Unk_AvPackageMapView : public std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >
{
public:
    std::pair<iterator, bool> FUN_1418c0f00(Unk_AvPackagePair&& kPair);     // 0x1418c0f00
};

// @0x1418bb2a0
bool UIAvatarPC::FUN_1418bb2a0(MS2Ptr<CItemData> spData, int nEffect, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems)
{
    if (m_spCustomize == 0)
        return false;
    if (spData == 0)
        return false;
    if (FUN_14053c5c0(spData.operator->()) != 0x19)
        return false;
    if (FUN_1405729c0(pItems))
        return false;
    int nId = spData->FUN_14053c510();
    int nZero = 0;
    Unk_AvPackageKey kKey(nId, nZero);
    return FUN_1418bb3f0(&kKey, nEffect, pItems);
}

// MS2-FUNCTIONAL: 2050 vs 2090 bytes: the exe destroys the per-slot MS2Ptr<CItemData>/MS2Ptr<CItem> temporaries on early-continue paths (4 more dtor calls) and indexes the equip list through Unk_PtItemList::FUN_140c3c720 (MS2Ptr<CEquipItem>&) instead of CAtlArray<MS2Ptr<CItem>>::operator[]; loop restructure pending
// @0x1418bb3f0
bool UIAvatarPC::FUN_1418bb3f0(Unk_AvPackageKey* pKey, int nEffect, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems)
{
    if (m_spCustomize == 0)
        return false;
    if (FUN_1405729c0(pItems))
        return false;
    MS2Ptr<CAvatarPackageEquip> spOld = FUN_1418bd200(pKey);
    if (spOld.get())
        return true;
    MS2Ptr<CAvatarPackageEquip> spNew(new CAvatarPackageEquip());
    if (spNew == 0)
        return false;
    Unk_AvPackageKey kItemKey;
    ATL::CAtlArray<Unk_AvPackageKey> kKeys;
    ATL::CAtlArray<MS2Ptr<CItem> > kNewItems;
    size_t nCount = pItems->GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CItemData> spItemData((*pItems)[i]);
        if (!(spItemData == 0))
        {
            MS2Ptr<CItem> spItem(new CItem());
            if (!(spItem == 0))
            {
                spItem->FUN_140523c40(spItemData->FUN_14053c510(), 1, 0);
                int nCustomizeId = FUN_141420f10(spItemData.get(), FUN_1418bd1d0());
                FUN_140526c10(spItem.operator->(), nCustomizeId);
                spItem->FUN_140526a70(FUN_14028d0e0());
                FUN_140526b30(spItem.operator->(), vfunc_25());
                if (FUN_1418bd350(&kItemKey, nCustomizeId))
                    kKeys.Add(kItemKey);
                kNewItems.Add(spItem);
            }
        }
    }
    if (!kKeys.IsEmpty())
    {
        for (size_t i = 0; i < kKeys.GetCount(); i++)
            FUN_1418bc500(&kKeys[i]);
    }
    for (size_t i = 0; i < kNewItems.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem(kNewItems[i]);
        if (!(spItem == 0))
        {
            if (FUN_140527840(spItem.operator->()))
            {
                FUN_1418bafa0(spItem.get(), nEffect);
                MS2Ptr<CItemData> spData(FUN_140527840(spItem.operator->()));
                if (!FUN_14053d2b0(spData.operator->()))
                {
                    if (!FUN_14053d460(spData.operator->()))
                        spNew->FUN_1418bf9b0(FUN_140526c30(spItem.operator->()), MS2Ptr<CItem>(spItem));
                    else
                    {
                        spNew->FUN_1418bf9b0((Unk_InventoryEquipSlot)4, MS2Ptr<CItem>(spItem));
                        spNew->FUN_1418bf9b0((Unk_InventoryEquipSlot)5, MS2Ptr<CItem>(spItem));
                    }
                }
                else
                {
                    spNew->FUN_1418bf9b0((Unk_InventoryEquipSlot)8, MS2Ptr<CItem>(spItem));
                    spNew->FUN_1418bf9b0((Unk_InventoryEquipSlot)9, MS2Ptr<CItem>(spItem));
                }
            }
        }
    }
    static_cast<Unk_AvPackageMapView&>(m_mapPackages).FUN_1418c0f00(Unk_AvPackagePair(*pKey, spNew));
    return !spNew->FUN_1418bfcc0();
}

void* FUN_1416561a0(AvatarPC* pAvatar);                                 // the state record of an avatar
void FUN_1411ea620(void* pRecord, CMsTime kNow, CMsTime kZero);         // refreshes the state record
__int64 FUN_140869440();                                                // the server time

// @0x1418bbc20
void UIAvatarPC::FUN_1418bbc20(int nValue)
{
    if (m_spCustomize.get())
        m_spCustomize->FUN_140cd1f30(nValue);
}
MS2_REPLACE_METHOD(0x1418BBC20, UIAvatarPC, FUN_1418bbc20, 73, 0xA926B992);

// @0x1418bbc70
void UIAvatarPC::FUN_1418bbc70(CItem* pItem)
{
    if (m_spCustomize.get())
        m_spCustomize->FUN_140cd1f90(pItem);
}
MS2_REPLACE_METHOD(0x1418BBC70, UIAvatarPC, FUN_1418bbc70, 75, 0x8526D769);

// @0x1418bbcd0
void UIAvatarPC::FUN_1418bbcd0(CItem* pItem)
{
    if (m_spCustomize.get())
        m_spCustomize->FUN_140cd1ed0(pItem);
}
MS2_REPLACE_METHOD(0x1418BBCD0, UIAvatarPC, FUN_1418bbcd0, 75, 0xB39DF306);

// @0x1418bbd30
void UIAvatarPC::FUN_1418bbd30(int nSlot)
{
    if (m_spCustomize == 0)
        return;
    Unk_UabPlayer* pPlayer = FUN_14099eef0(vfunc_24());
    if (pPlayer)
    {
        MS2Ptr<Unk_UabEquip> spEquip = pPlayer->FUN_141655cf0(nSlot);
        if (spEquip.get())
            FUN_1418bbc70(spEquip->FUN_1411dc870());
        MS2Ptr<Unk_UabEquip> spEquip2 = pPlayer->FUN_141655c90(nSlot);
        if (spEquip2.get())
            FUN_1418bbc70(spEquip2->FUN_1411dc870());
    }
}

// @0x1418bbe40
void UIAvatarPC::FUN_1418bbe40()
{
    if (m_spCustomize.get())
        m_spCustomize->FUN_140cd1e80();
    m_mapPackages.clear();
}
MS2_REPLACE_METHOD(0x1418BBE40, UIAvatarPC, FUN_1418bbe40, 84, 0xF86CA209);

// @0x1418bbea0
bool UIAvatarPC::FUN_1418bbea0(Unk_AvPackageKey* pKey)
{
    if (m_spCustomize == 0)
        return false;
    if (m_mapPackages.empty())
        return false;
    MS2Ptr<CAvatarPackageEquip> spPackage(0);
    if (m_mapPackages.find(*pKey) == m_mapPackages.end())
        return false;
    if (spPackage.get())
    {
        if (spPackage->FUN_1418bfa00(this))
            m_mapPackages.erase(*pKey);
    }
    return true;
}

// @0x1418bbfe0
bool UIAvatarPC::FUN_1418bbfe0()
{
    if (m_spCustomize == 0)
        return false;
    if (m_mapPackages.empty())
        return false;
    for (std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator it = m_mapPackages.begin();
         it != m_mapPackages.end(); ++it)
    {
        MS2Ptr<CAvatarPackageEquip> spPackage(it->second);
        if (!(spPackage == 0))
            spPackage->FUN_1418bfa00(this);
    }
    m_mapPackages.clear();
    return true;
}

// @0x1418bc110
void UIAvatarPC::FUN_1418bc110(MS2Ptr<CItem> spItem)
{
    if (FUN_1418b9b80() == 0)
        return;
    if (spItem == 0 || !FUN_140527840(spItem.operator->()))
        return;
    if (!FUN_14053cc00(FUN_140527840(spItem.operator->())))
        return;
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar)
        pAvatar->FUN_1409f4d80(MS2Ptr<CItem>(spItem));
}

// @0x1418bc210
void UIAvatarPC::vfunc_3()
{
    UIAvatarBase::vfunc_3();
    if (m_spCustomize.get())
        m_spCustomize->FUN_140cd20c0();
    m_mapPackages.clear();
}
MS2_REPLACE_METHOD(0x1418BC210, UIAvatarPC, vfunc_3, 94, 0x2E4D8367);

// @0x1418bc280
void UIAvatarPC::FUN_1418bc280(int nValue)
{
    if (m_spCustomize.get())
        m_spCustomize->FUN_140cd3480(nValue, 0x2711);
}
MS2_REPLACE_METHOD(0x1418BC280, UIAvatarPC, FUN_1418bc280, 79, 0x40AEB62A);

// @0x1418bc2e0
void UIAvatarPC::vfunc_4(__int64 nItemUid)
{
    Unk_UabPlayer* pPlayer = FUN_14099eef0(vfunc_24());
    if (pPlayer == 0)
        return;
    MS2Ptr<CItem> spItem = pPlayer->FUN_141655b80(nItemUid);
    if (spItem.IsNull())
        return;
    FUN_1418bc380(spItem.get());
}

// @0x1418bc380
void UIAvatarPC::FUN_1418bc380(CItem* pItem)
{
    if (pItem)
    {
        Unk_UabPlayer* pPlayer = FUN_14099eef0(vfunc_24());
        if (pPlayer && m_spCustomize.get())
        {
            m_spCustomize->FUN_140cd1ed0(pItem);
            int nRange = FUN_14053eba0(FUN_140527840(pItem))->FUN_14054b2f0(0)->FUN_1405451a0();
            int nCustomizeId = FUN_141420a30(nRange, pItem, pPlayer);
            MS2Ptr<CItemData> spData(FUN_140527840(pItem));
            if (spData.get())
                m_spCustomize->FUN_140cd23e0(MS2Ptr<CItem>(pItem), nCustomizeId);
        }
    }
}

// @0x1418bc500
void UIAvatarPC::FUN_1418bc500(Unk_AvPackageKey* pKey)
{
    if (m_spCustomize == 0)
        return;
    if (m_mapPackages.empty())
        return;
    std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator it = m_mapPackages.find(*pKey);
    if (it != m_mapPackages.end())
    {
        MS2Ptr<CAvatarPackageEquip> spPackage(it->second);
        if (spPackage.get())
        {
            if (spPackage->FUN_1418bfb00(this))
                m_mapPackages.erase(*pKey);
        }
    }
}

// @0x1418bc630
void UIAvatarPC::FUN_1418bc630()
{
    if (!m_mapPackages.empty())
    {
        for (std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator it = m_mapPackages.begin();
             it != m_mapPackages.end(); ++it)
        {
            MS2Ptr<CAvatarPackageEquip> spPackage(it->second);
            if (!(spPackage == 0))
                spPackage->FUN_1418bfb00(this);
        }
        m_mapPackages.clear();
    }
}

// @0x1418bc740
int UIAvatarPC::FUN_1418bc740()
{
    PCBase* pPc = FUN_1403ed2d0()->FUN_141bd1290(m_nObjectId);
    if (pPc != 0)
        return FUN_141658e60(pPc);
    return 3;
}

// @0x1418bc790
void UIAvatarPC::FUN_1418bc790(int nState, int nParam)
{
    GameObject* pObj = vfunc_24();
    if (pObj != 0)
    {
        AvatarPC* pAvatar = FUN_1418bd1d0();
        if (pAvatar)
        {
            int nMode = pAvatar->FUN_1409f62a0();
            if (nMode == 1)
                FUN_1418bca60(nState, nParam);
            else
            {
                if (pAvatar->FUN_14166c930() != nState)
                    pAvatar->vfunc_59(nState, 0, 0, 0);
                FUN_14166cc40(pAvatar, nParam);
            }
        }
    }
}

// @0x1418bc860
void UIAvatarPC::FUN_1418bc860(int nParam)
{
    GameObject* pObj = vfunc_24();
    if (pObj)
    {
        AvatarPC* pAvatar = FUN_140a535c0(pObj);
        if (pAvatar)
            FUN_14166cc40(pAvatar, nParam);
    }
}
MS2_REPLACE_METHOD(0x1418BC860, UIAvatarPC, FUN_1418bc860, 87, 0x23A51193);

// @0x1418bc8c0
void UIAvatarPC::FUN_1418bc8c0(int nSkin)
{
    if (nSkin != 0)
    {
        Unk_CharEquip kColor0;
        Unk_CharEquip kColor1;
        {
            Unk_UabPresetPtr kRow = FUN_140281980()->FUN_1405587f0(nSkin, 0);
            if (kRow.FUN_14059cf00())
            {
                kColor0 = FUN_141b6dea0(kRow.FUN_14056d570()->m_nColorA);
                kColor1 = FUN_141b6dea0(kRow.FUN_14056d570()->m_nColorB);
            }
        }
        FUN_1418bca10(kColor0, kColor1);
    }
}

// @0x1418bca10
void UIAvatarPC::FUN_1418bca10(Unk_CharEquip kColor0, Unk_CharEquip kColor1)
{
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar)
        pAvatar->FUN_1409f41d0(kColor0, kColor1);
}

// @0x1418bca60
void UIAvatarPC::FUN_1418bca60(int nState, int nParam)
{
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar)
    {
        if (pAvatar->FUN_14166c930() != nState)
            pAvatar->vfunc_59(nState, 0, 0, 0);
        if (nState == 1)
        {
            FUN_14166cc40(pAvatar, nParam);
            if (nParam == 10)
                pAvatar->FUN_14166dd20(efd::utf8string("Idle_A"), 1.0f, false, false);
            else if (nParam == 0xb)
                pAvatar->FUN_14166dd20(efd::utf8string("Idle_B"), 1.0f, false, false);
        }
        else if (nState == 0xe)
        {
            FUN_14166ce70(pAvatar, 1);
            FUN_141653f00(pAvatar);
            efd::utf8string kName((const char*)FUN_1409a2360((const char*)pAvatar->vfunc_60(), 0));
            if (!FUN_14096ad40(kName))
            {
                kName.erase(kName.length() - 1, 1);
                pAvatar->FUN_14166dd20(kName, 1.0f, false, false);
            }
            else
                pAvatar->FUN_14166dd20(efd::utf8string("Sword"), 1.0f, false, false);
        }
    }
}

// @0x1418bcd20
bool UIAvatarPC::FUN_1418bcd20(int nPose)
{
    if (nPose < 0)
        return false;
    if (FUN_1418bd1d0() == 0)
        return false;
    return FUN_1418bcd80(nPose);
}

// @0x1418bcd80
bool UIAvatarPC::FUN_1418bcd80(int nPose)
{
    if (FUN_1418bd1d0() == 0)
        return false;
    int nState = 1;
    int nParam = 10;
    if (nPose == 0)
    {
        nState = 1;
        nParam = 10;
    }
    else if (nPose == 1)
    {
        nState = 1;
        nParam = 0xb;
    }
    else if (nPose == 2)
    {
        nState = 0xe;
        nParam = 0x55;
    }
    else if (nPose == 3)
    {
        nState = 1;
        nParam = 0x16;
    }
    if (FUN_1418b9b80() == 0)
    {
        m_nAction = nState;
        m_nActionParam = nParam;
    }
    else
        FUN_1418bc790(nState, nParam);
    return true;
}

// @0x1418bce80
void UIAvatarPC::FUN_1418bce80(int nValue)
{
    if (FUN_1418b9b80() == 0)
        return;
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar)
        pAvatar->FUN_14166ed70(nValue);
}
MS2_REPLACE_METHOD(0x1418BCE80, UIAvatarPC, FUN_1418bce80, 71, 0x16AEDF01);

// @0x1418bced0
void UIAvatarPC::FUN_1418bced0(MS2Ptr<CItemData> spData)
{
    if (FUN_1418b9b80() == 0)
        return;
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar)
        pAvatar->FUN_1409f42a0(MS2Ptr<CItemData>(spData));
}
MS2_REPLACE_METHOD(0x1418BCED0, UIAvatarPC, FUN_1418bced0, 133, 0x1531DAE4);

// @0x1418bcf60
void UIAvatarPC::FUN_1418bcf60(int nSkillId, short nLevel)
{
    if (FUN_1418b9b80() == 0)
        return;
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar)
        pAvatar->FUN_1409f43d0(nSkillId, nLevel);
}
MS2_REPLACE_METHOD(0x1418BCF60, UIAvatarPC, FUN_1418bcf60, 83, 0xDC9E76BB);

// @0x1418bcfc0
void UIAvatarPC::FUN_1418bcfc0(MS2Ptr<CItemData> spData)
{
    if (FUN_1418b9b80() == 0)
        return;
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar)
        pAvatar->FUN_1409f45a0(MS2Ptr<CItemData>(spData));
}
MS2_REPLACE_METHOD(0x1418BCFC0, UIAvatarPC, FUN_1418bcfc0, 133, 0xDDA4CAF5);

// @0x1418bd050
void UIAvatarPC::FUN_1418bd050(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem)
{
    if (FUN_1418b9b80() == 0)
        return;
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar)
        pAvatar->FUN_1409f4750(MS2Ptr<CItemData>(spData), MS2Ptr<CItem>(spItem));
}
MS2_REPLACE_METHOD(0x1418BD050, UIAvatarPC, FUN_1418bd050, 238, 0x27EC8CD8);

// @0x1418bd150
void UIAvatarPC::FUN_1418bd150(unsigned int a, unsigned int b)
{
    if (!FUN_1418b9b80())
        return;
    vfunc_20(0.0f, 0.0f, 0.0f, 1);
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar)
        pAvatar->FUN_1409f4cf0(a, b);
}

// @0x1418bd1d0
AvatarPC* UIAvatarPC::FUN_1418bd1d0()
{
    return FUN_140a535c0(vfunc_24());
}
MS2_REPLACE_METHOD(0x1418BD1D0, UIAvatarPC, FUN_1418bd1d0, 41, 0xF3F5DAB3);

// @0x1418bd200
MS2Ptr<CAvatarPackageEquip> UIAvatarPC::FUN_1418bd200(Unk_AvPackageKey* pKey)
{
    if (m_mapPackages.empty())
        return MS2Ptr<CAvatarPackageEquip>(0);
    std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator it = m_mapPackages.find(*pKey);
    if (it != m_mapPackages.end())
        return it->second;
    return MS2Ptr<CAvatarPackageEquip>(0);
}
MS2_REPLACE_METHOD(0x1418BD200, UIAvatarPC, FUN_1418bd200, 237, 0x0D60A8AD);

// @0x1418bd300
bool UIAvatarPC::FUN_1418bd300()
{
    return !m_mapPackages.empty();
}
MS2_REPLACE_METHOD(0x1418BD300, UIAvatarPC, FUN_1418bd300, 63, 0xFA23326B);

// @0x1418bd350
bool UIAvatarPC::FUN_1418bd350(Unk_AvPackageKey* pKeyOut, int nItemId)
{
    if (m_mapPackages.empty() || nItemId == 0)
        return false;
    MS2Ptr<CItem> spFound(0);
    for (std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator it = m_mapPackages.begin();
         it != m_mapPackages.end(); ++it)
    {
        MS2Ptr<CAvatarPackageEquip> spPackage(it->second);
        if (spPackage == 0)
            continue;
        spFound = spPackage->FUN_1418bfc00((Unk_InventoryEquipSlot)nItemId);
        if (spFound.get())
        {
            *pKeyOut = it->first;
            return true;
        }
    }
    return false;
}

// @0x1418bd510
MS2Ptr<CItem> UIAvatarPC::FUN_1418bd510(int nItemId)
{
    if (m_mapPackages.empty() || nItemId == 0)
        return MS2Ptr<CItem>(0);
    MS2Ptr<CItem> spFound(0);
    for (std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator it = m_mapPackages.begin();
         it != m_mapPackages.end(); ++it)
    {
        MS2Ptr<CAvatarPackageEquip> spPackage(it->second);
        if (spPackage == 0)
            continue;
        spFound = spPackage->FUN_1418bfc00((Unk_InventoryEquipSlot)nItemId);
        if (spFound.get())
            return spFound;
    }
    return MS2Ptr<CItem>(0);
}

// @0x1418bd710
MS2Ptr<Customize> UIAvatarPC::FUN_1418bd710()
{
    return m_spCustomize;
}
MS2_REPLACE_METHOD(0x1418BD710, UIAvatarPC, FUN_1418bd710, 67, 0xBAB44D00);

// @0x1418bd760
int UIAvatarPC::FUN_1418bd760()
{
    return m_nPose;
}
MS2_REPLACE_METHOD(0x1418BD760, UIAvatarPC, FUN_1418bd760, 17, 0x38E3250F);

// @0x1418bd780
void UIAvatarPC::FUN_1418bd780(PC* pSource, AvatarPC* pAvatar)
{
    if (pAvatar == 0)
        return;
    __int64 nNow = FUN_140869440();
    CMsTime kZero((__time64_t)0);
    CMsTime kNow(nNow);
    FUN_1411ea620(FUN_1416561a0(pAvatar), kNow, kZero);
}

// @0x1418bd7f0
void UIAvatarPC::FUN_1418bd7f0(bool bEnabled)
{
    AvatarPC* pAvatar = FUN_1418bd1d0();
    if (pAvatar == 0)
        return;
    pAvatar->FUN_1409f6540(bEnabled);
}

// @0x1418bd830
void UIAvatarPC::FUN_1418bd830()
{
    FUN_1418bd860(m_nPose);
}
MS2_REPLACE_METHOD(0x1418BD830, UIAvatarPC, FUN_1418bd830, 35, 0xCAA1BF50);

// @0x1418bd860
void UIAvatarPC::FUN_1418bd860(int nPose)
{
    FUN_1418ba340(0);
    FUN_1418bcd20(nPose);
    m_nPose = nPose;
    if (m_pListener)
        m_pListener->vfunc_o178_3(this);
}

// ---- UIAvatarCube / UIAvatarRidee / UIAvatarPet -------------------------------------------------------------------

AvatarCube* FUN_1418a49c0(GameObject* pObj);                            // efd::DynamicCast<AvatarCube>
AvatarRidee* FUN_1418a4a10(GameObject* pObj);                           // efd::DynamicCast<AvatarRidee>
MS2_REPLACE_METHOD(0x1418BD860, UIAvatarPC, FUN_1418bd860, 109, 0xB0325FFA);

// @0x1418bd8e0
UIAvatarCube::UIAvatarCube(CItemData* pData)
    : m_pItemData(pData)
{
    m_nKind = 2;
}

// @0x1418bd950
UIAvatarCube::~UIAvatarCube()
{
    m_pItemData = 0;
}

// @0x1418bd9a0
void UIAvatarCube::vfunc_1(IUIAvatarEventListener* pListener)
{
    UIAvatarBase::vfunc_1(pListener);
    AvatarCube* pCube = FUN_1409f2670(m_pItemData);
    if (pCube)
    {
        if (FUN_1403ed2d0()->FUN_141bbb1e0(pCube, 0, 1))
        {
            m_nObjectId = pCube->FUN_14123c580();
            pCube->FUN_141085ab0(this);
        }
    }
}
MS2_REPLACE_METHOD(0x1418BD9A0, UIAvatarCube, vfunc_1, 161, 0x5E232546);

// @0x1418bda50
void UIAvatarCube::vfunc_21(UIRenderView* pView)
{
    UIAvatarBase::vfunc_21(pView);
    AvatarCube* pCube = FUN_1418a49c0(vfunc_24());
    if (pCube)
    {
        pCube->FUN_141084d00(static_cast<UIModelView*>(pView));
        pCube->FUN_1410853e0(pView == 0);
    }
}
MS2_REPLACE_METHOD(0x1418BDA50, UIAvatarCube, vfunc_21, 124, 0xE8384573);

// @0x1418bdae0
void UIAvatarCube::FUN_1418bdae0(void* pUnused)
{
    vfunc_3();
    AvatarCube* pCube = FUN_1418a49c0(vfunc_24());
    if (pCube)
        pCube->vfunc_58(MS2Ptr<CItemData>(0), MS2Ptr<CItem>(0));
}
MS2_REPLACE_METHOD(0x1418BDAE0, UIAvatarCube, FUN_1418bdae0, 195, 0x801587E0);

// @0x1418bdbb0
void UIAvatarCube::vfunc_22()
{
    float fAngle = FUN_141b48480(FUN_141b48430(FUN_1418b9ba0()), 0);
    vfunc_19(fAngle, 0);
}
MS2_REPLACE_METHOD(0x1418BDBB0, UIAvatarCube, vfunc_22, 74, 0x7F20A675);

// @0x1418bdc00
void UIAvatarCube::FUN_1418bdc00(CItemData* pData)
{
    m_pItemData = pData;
    AvatarCube* pCube = FUN_1418a49c0(vfunc_24());
    if (pCube)
        pCube->vfunc_58(MS2Ptr<CItemData>(m_pItemData), MS2Ptr<CItem>(0));
}
MS2_REPLACE_METHOD(0x1418BDC00, UIAvatarCube, FUN_1418bdc00, 209, 0x64AD802E);

// @0x1418bdce0
void UIAvatarCube::vfunc_3()
{
    UIAvatarBase::vfunc_3();
    AvatarCube* pCube = FUN_1418a49c0(vfunc_24());
    if (pCube)
        pCube->FUN_141085250();
}
MS2_REPLACE_METHOD(0x1418BDCE0, UIAvatarCube, vfunc_3, 74, 0xAFF49725);

// @0x1418bdd30
void UIAvatarCube::vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg)
{
    GameObject* pObj = vfunc_24();
    if (pObj)
    {
        Unk_UabPoint kPtA;
        Unk_UabPoint kPtB;
        Unk_UISwfEntity_25* pEntA = spTarget.get();
        Unk_UISwfEntity_25* pEntB = spTarget.get();
        UIRenderView* pView = FUN_140e66980(pEntB->vfunc_5(&kPtB)->x, pEntA->vfunc_5(&kPtA)->y, pObj, 0.9f);
        if (pView)
        {
            FUN_141ab7200(pView, TPtr<Unk_UISwfEntity_25>(spTarget), pArg);
            vfunc_21(pView);
        }
    }
}
MS2_REPLACE_METHOD(0x1418BDD30, UIAvatarCube, vfunc_28, 321, 0x8AD39274);

// @0x1418bde80
AvatarCube* UIAvatarCube::FUN_1418bde80()
{
    return FUN_1418a49c0(vfunc_24());
}
MS2_REPLACE_METHOD(0x1418BDE80, UIAvatarCube, FUN_1418bde80, 41, 0xE9AF397A);

// @0x1418bdeb0
UIAvatarRidee::UIAvatarRidee()
    : m_pItemData(0), m_spRow(0)
{
}

// @0x1418bdf30
UIAvatarRidee::UIAvatarRidee(MS2Ptr<CItemData> spData)
    : m_pItemData(spData.get()), m_spRow(0)
{
    m_nKind = 3;
}

// @0x1418bdfd0
UIAvatarRidee::UIAvatarRidee(Unk_RideePtr spRow)
    : m_pItemData(0), m_spRow(spRow)
{
}

// @0x1418be060
UIAvatarRidee::~UIAvatarRidee()
{
}

// @0x1418be0b0
void UIAvatarRidee::vfunc_1(IUIAvatarEventListener* pListener)
{
    UIAvatarBase::vfunc_1(pListener);
    if (m_pItemData != 0)
    {
        AvatarRidee* pRidee = FUN_1409f92d0(MS2Ptr<CItemData>(m_pItemData), MS2Ptr<CItem>(0));
        if (pRidee)
        {
            if (FUN_1403ed2d0()->FUN_141bbb1e0(pRidee, 0, 1))
            {
                m_nObjectId = pRidee->FUN_14123c580();
                pRidee->FUN_141085ab0(this);
            }
        }
    }
    else
    {
        if (m_spRow.get() != 0)
        {
            AvatarRidee* pRidee = FUN_1409f9430(m_spRow);
            if (pRidee)
            {
                if (FUN_1403ed2d0()->FUN_141bbb1e0(pRidee, 0, 1))
                {
                    m_nObjectId = pRidee->FUN_14123c580();
                    pRidee->FUN_141085ab0(this);
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1418BE0B0, UIAvatarRidee, vfunc_1, 504, 0x1341BC9B);

// @0x1418be2b0
void UIAvatarRidee::vfunc_21(UIRenderView* pView)
{
    UIAvatarBase::vfunc_21(pView);
    AvatarRidee* pRidee = FUN_1418a4a10(vfunc_24());
    if (pRidee)
    {
        pRidee->FUN_141084d00(static_cast<UIModelView*>(pView));
        pRidee->FUN_1410853e0(pView == 0);
    }
}
MS2_REPLACE_METHOD(0x1418BE2B0, UIAvatarRidee, vfunc_21, 124, 0x1A084943);

// @0x1418be340
void UIAvatarRidee::FUN_1418be340(void* pUnused)
{
    vfunc_3();
    AvatarRidee* pRidee = FUN_1418a4a10(vfunc_24());
    if (pRidee)
        pRidee->vfunc_58(MS2Ptr<CItemData>(0), MS2Ptr<CItem>(0));
}
MS2_REPLACE_METHOD(0x1418BE340, UIAvatarRidee, FUN_1418be340, 195, 0x8032C0BF);

// @0x1418be410
void UIAvatarRidee::vfunc_22()
{
    float fAngle = FUN_141b48480(FUN_141b48430(FUN_1418b9ba0()), 0);
    vfunc_19(fAngle, 0);
}
MS2_REPLACE_METHOD(0x1418BE410, UIAvatarRidee, vfunc_22, 74, 0x28660A3D);

// @0x1418be460
void UIAvatarRidee::FUN_1418be460(CItemData* pData)
{
    m_pItemData = pData;
    m_spRow = 0;
    AvatarRidee* pRidee = FUN_1418a4a10(vfunc_24());
    if (pRidee == 0)
        vfunc_1(m_pListener);
    else
        pRidee->vfunc_58(MS2Ptr<CItemData>(m_pItemData), MS2Ptr<CItem>(0));
}
MS2_REPLACE_METHOD(0x1418BE460, UIAvatarRidee, FUN_1418be460, 272, 0x7DA47DB9);

// @0x1418be580
void UIAvatarRidee::FUN_1418be580(Unk_RideePtr spRow)
{
    m_spRow = spRow;
    m_pItemData = 0;
    AvatarRidee* pRidee = FUN_1418a4a10(vfunc_24());
    if (pRidee)
        pRidee->FUN_1409f9ea0(m_spRow);
}
MS2_REPLACE_METHOD(0x1418BE580, UIAvatarRidee, FUN_1418be580, 173, 0xEC2CAD68);

// @0x1418be640
void UIAvatarRidee::vfunc_3()
{
    UIAvatarBase::vfunc_3();
    AvatarRidee* pRidee = FUN_1418a4a10(vfunc_24());
    if (pRidee)
        pRidee->FUN_141085250();
}
MS2_REPLACE_METHOD(0x1418BE640, UIAvatarRidee, vfunc_3, 74, 0x8E78E814);

// @0x1418be690
void UIAvatarRidee::vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg)
{
    GameObject* pObj = vfunc_24();
    if (pObj)
    {
        Unk_UabPoint kPtA;
        Unk_UabPoint kPtB;
        Unk_UISwfEntity_25* pEntA = spTarget.get();
        Unk_UISwfEntity_25* pEntB = spTarget.get();
        UIRenderView* pView = FUN_140e66980(pEntB->vfunc_5(&kPtB)->x, pEntA->vfunc_5(&kPtA)->y, pObj, 0.9f);
        if (pView)
        {
            FUN_141ab7200(pView, TPtr<Unk_UISwfEntity_25>(spTarget), pArg);
            vfunc_21(pView);
        }
    }
}
MS2_REPLACE_METHOD(0x1418BE690, UIAvatarRidee, vfunc_28, 321, 0x92186B9C);

// @0x1418be7e0
AvatarRidee* UIAvatarRidee::FUN_1418be7e0()
{
    return FUN_1418a4a10(vfunc_24());
}
MS2_REPLACE_METHOD(0x1418BE7E0, UIAvatarRidee, FUN_1418be7e0, 41, 0xCB75113F);

// @0x1418be810
Unk_RideePtr UIAvatarRidee::FUN_1418be810()
{
    return m_spRow;
}
MS2_REPLACE_METHOD(0x1418BE810, UIAvatarRidee, FUN_1418be810, 67, 0xAA3AAE8D);

// @0x1418be860 (secondary vftable: the listener slot 4)
int UIAvatarRidee::vfunc_4(GameObject* pObj)
{
    int nRet = UIAvatarBase::vfunc_4(pObj);
    float fAngle = FUN_141b48480(FUN_141b48430(FUN_1418b9ba0()), 0);
    vfunc_19(fAngle, 0);
    return nRet;
}

// @0x1418be8f0
UIAvatarPet::UIAvatarPet(CItemData* pData)
    : m_pItemData(pData)
{
    m_nKind = 4;
}

// @0x1418be960
UIAvatarPet::~UIAvatarPet()
{
    m_pItemData = 0;
}

// @0x1418be9b0
void UIAvatarPet::vfunc_1(IUIAvatarEventListener* pListener)
{
    UIAvatarBase::vfunc_1(pListener);
    AvatarPet* pPet = FUN_1409f8510(m_pItemData);
    if (pPet)
    {
        if (FUN_1403ed2d0()->FUN_141bbb1e0(pPet, 0, 1))
        {
            m_nObjectId = pPet->FUN_14123c580();
            pPet->FUN_141085ab0(this);
        }
    }
}
MS2_REPLACE_METHOD(0x1418BE9B0, UIAvatarPet, vfunc_1, 161, 0xFCBE2185);

// @0x1418bea60
void UIAvatarPet::vfunc_21(UIRenderView* pView)
{
    UIAvatarBase::vfunc_21(pView);
    AvatarPet* pPet = efd::DynamicCast<AvatarPet>(vfunc_24());
    if (pPet)
    {
        pPet->FUN_141084d00(static_cast<UIModelView*>(pView));
        pPet->FUN_1410853e0(pView == 0);
    }
}
MS2_REPLACE_METHOD(0x1418BEA60, UIAvatarPet, vfunc_21, 124, 0xC88C6F9A);

// @0x1418beaf0
void UIAvatarPet::FUN_1418beaf0(void* pUnused)
{
    vfunc_3();
    AvatarPet* pPet = efd::DynamicCast<AvatarPet>(vfunc_24());
    if (pPet)
        pPet->vfunc_62(MS2Ptr<CItemData>(0));
}
MS2_REPLACE_METHOD(0x1418BEAF0, UIAvatarPet, FUN_1418beaf0, 126, 0x9094177A);

// @0x1418beb80
void UIAvatarPet::vfunc_22()
{
    float fAngle = FUN_141b48480(FUN_141b48430(FUN_1418b9ba0()), 0);
    vfunc_19(fAngle, 0);
}
MS2_REPLACE_METHOD(0x1418BEB80, UIAvatarPet, vfunc_22, 74, 0xAE818566);

// @0x1418bebd0
void UIAvatarPet::FUN_1418bebd0(CItemData* pData)
{
    m_pItemData = pData;
    AvatarPet* pPet = efd::DynamicCast<AvatarPet>(vfunc_24());
    if (pPet)
        pPet->vfunc_62(MS2Ptr<CItemData>(m_pItemData));
}
MS2_REPLACE_METHOD(0x1418BEBD0, UIAvatarPet, FUN_1418bebd0, 137, 0x8EA560C1);

// @0x1418bec60
void UIAvatarPet::vfunc_3()
{
    UIAvatarBase::vfunc_3();
    AvatarPet* pPet = efd::DynamicCast<AvatarPet>(vfunc_24());
    if (pPet)
        pPet->FUN_141085250();
}
MS2_REPLACE_METHOD(0x1418BEC60, UIAvatarPet, vfunc_3, 74, 0xFAED7883);

// @0x1418becb0
void UIAvatarPet::vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg)
{
    GameObject* pObj = vfunc_24();
    if (pObj)
    {
        Unk_UabPoint kPtA;
        Unk_UabPoint kPtB;
        Unk_UISwfEntity_25* pEntA = spTarget.get();
        Unk_UISwfEntity_25* pEntB = spTarget.get();
        UIRenderView* pView = FUN_140e66980(pEntB->vfunc_5(&kPtB)->x, pEntA->vfunc_5(&kPtA)->y, pObj, 0.9f);
        if (pView)
        {
            FUN_141ab7200(pView, TPtr<Unk_UISwfEntity_25>(spTarget), pArg);
            vfunc_21(pView);
        }
    }
}
MS2_REPLACE_METHOD(0x1418BECB0, UIAvatarPet, vfunc_28, 321, 0xDF6EE08F);

// @0x1418bee00
AvatarPet* UIAvatarPet::FUN_1418bee00()
{
    return efd::DynamicCast<AvatarPet>(vfunc_24());
}

// ---- the skin colour list ------------------------------------------------------------------------------------------

// One row of the skin colour table (+0x38 colour, +0x3c / +0x44 the two tints).
struct Unk_UabColorRow { char m_pad_00[0x38]; unsigned long m_nColor; unsigned long m_nColor0; int m_n40; unsigned long m_nColor1; };
MS2_CHECK_OFFSET(Unk_UabColorRow, m_nColor0, 0x3c);
MS2_CHECK_OFFSET(Unk_UabColorRow, m_nColor1, 0x44);
class Unk_UabColorElem
{
public:
    Unk_UabColorElem(Unk_UabColorRow* pRow);                    // 0x14056a550
    ~Unk_UabColorElem();                                        // 0x14056c2d0
    Unk_UabColorRow* FUN_14056d570() const;                     // operator->
    bool FUN_1418c14b0() const { return m_p == 0; }             // 0x1418c14b0 null test
    void* m_pad_00;
    Unk_UabColorRow* m_p;
};
class Unk_UabColorList { public: size_t FUN_140570e10(); Unk_UabColorRow* FUN_140570dd0(size_t n); };
class Unk_UabColorSet
{
public:
    ~Unk_UabColorSet();                                         // 0x14056c240
    void* FUN_14056d460() const;
    Unk_UabColorList* FUN_14056d540() const;
    void* m_pad_00;
    void* m_p;
};

struct Unk_UabColor3 { float x; float y; float z; };
const Unk_UabColor3* FUN_141659220(PCBase* pPlayer, int nIndex);        // colour of an equip slot of a player
unsigned FUN_141b6df90(const Unk_UabColor3* pColor);                    // colour -> packed value
MS2_REPLACE_METHOD(0x1418BEE00, UIAvatarPet, FUN_1418bee00, 41, 0x51CA81FA);

// @0x1418bee30
// MS2-FUNCTIONAL: skin colour list; stack frame / array-indexed colour reads not byte-matched
void FUN_1418bee30(ASObj* pObj, int nSkinTable)
{
    ASArray kColors(2);
    int nSelected = 0;
    Unk_UabColorSet kSet = FUN_140281980()->FUN_140558ad0(nSkinTable);
    if (kSet.FUN_14056d460() != 0)
    {
        size_t nCount = kSet.FUN_14056d540()->FUN_140570e10();
        for (size_t i = 0; i < nCount; i++)
        {
            Unk_UabColorElem kElem(kSet.FUN_14056d540()->FUN_140570dd0(i));
            if (!kElem.FUN_1418c14b0())
            {
                ASObj kObj(2);
                kObj.FUN_1409c4990("color0", kElem.FUN_14056d570()->m_nColor0);
                kObj.FUN_1409c4990("color1", kElem.FUN_14056d570()->m_nColor1);
                unsigned long nColor = kElem.FUN_14056d570()->m_nColor;
                kObj.FUN_1409c4990("realColor", nColor);
                kObj.FUN_1409c4990("visibleColor", nColor);
                kColors.FUN_1422bc050(Scaleform::GFx::Value(kObj.FUN_1422bb870()));
            }
        }
    }
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer)
    {
        ASObj kObj(2);
        unsigned long nColor0 = FUN_141b6df90(FUN_141659220(pPlayer, 0));
        kObj.FUN_1409c4990("color0", nColor0);
        unsigned long nColor1 = FUN_141b6df90(FUN_141659220(pPlayer, 1));
        kObj.FUN_1409c4990("color1", nColor1);
        kObj.FUN_1409c4990("realColor", nColor0);
        kObj.FUN_1409c4990("visibleColor", nColor0);
        kColors.FUN_1422bc050(Scaleform::GFx::Value(kObj.FUN_1422bb870()));
    }
    pObj->FUN_1409adbe0("skinColors", Scaleform::GFx::Value(kColors.FUN_1422bb870()));
    pObj->FUN_1407cb9c0("skinColorSelectedIndex", nSelected);
}

// ---- angle wraps --------------------------------------------------------------------------------------------------

// @0x1418bf1e0
void FUN_1418bf1e0(Unk_StreamPoint* pAngles)
{
    FUN_1418bf270(&pAngles->x);
    FUN_1418bf270(&pAngles->y);
    FUN_1418bf270(&pAngles->z);
}

// @0x1418bf230
void FUN_1418bf230(float* pX, float* pY, float* pZ)
{
    FUN_1418bf270(pX);
    FUN_1418bf270(pY);
    FUN_1418bf270(pZ);
}

// @0x1418bf270
void FUN_1418bf270(float* pAngle)
{
    if (*pAngle < 0.0f)
        *pAngle = *pAngle + 360.0f;
    else if (360.0f < *pAngle)
        *pAngle = *pAngle - 360.0f;
}

// @0x1418bf2e0
void FUN_1418bf2e0(int* pAngle)
{
    if (*pAngle < 0)
        *pAngle = *pAngle + 360;
    else if (360 < *pAngle)
        *pAngle = *pAngle - 360;
}

// @0x1418bf330
void FUN_1418bf330(Unk_StreamPoint* pAngles)
{
    FUN_1418bf3c0(&pAngles->x);
    FUN_1418bf3c0(&pAngles->y);
    FUN_1418bf3c0(&pAngles->z);
}

// @0x1418bf380
void FUN_1418bf380(float* pX, float* pY, float* pZ)
{
    FUN_1418bf3c0(pX);
    FUN_1418bf3c0(pY);
    FUN_1418bf3c0(pZ);
}

// @0x1418bf3c0
void FUN_1418bf3c0(float* pAngle)
{
    if (*pAngle < 0.0f)
        *pAngle = *pAngle + 6.2831855f;
    else if (6.2831855f < *pAngle)
        *pAngle = *pAngle - 6.2831855f;
}

// ---- the cube item set drop walk ----------------------------------------------------------------------------------

// ItemDropResult (0x70 bytes, polymorphic): the item id sits at +0x20. Its copy ctor / dtor are bound by symbols-manual.
class Unk_UabDrop
{
public:
    Unk_UabDrop(const Unk_UabDrop& o);                          // 0x1402fe810
    ~Unk_UabDrop();                                             // 0x1402ffb40
    virtual unsigned vfunc_0();
    virtual int vfunc_1();
    virtual unsigned vfunc_2();
    __int64 m_08, m_10, m_18;
    int m_nItemId;                                              // +0x20
    int m_24;
    __int64 m_28, m_30, m_38, m_40, m_48, m_50, m_58, m_60, m_68;
};
MS2_CHECK_SIZE(Unk_UabDrop, 0x70);
MS2_CHECK_OFFSET(Unk_UabDrop, m_nItemId, 0x20);
class Unk_UabDropTable { public: void FUN_1402ea4c0(int nGroup, std::vector<Unk_UabDrop>& kOut); };
Unk_UabDropTable* FUN_1405a1fd0();
int FUN_14054a460(CStringW* pFunction);                         // the drop group id of an item function
bool FUN_14053cbc0(CItemData* pData);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

bool FUN_1418bf500(int nDepth, MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems, ATL::CAtlArray<MS2Ptr<CItemData> >* pOthers);

// @0x1418bf430
bool FUN_1418bf430(MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems, ATL::CAtlArray<MS2Ptr<CItemData> >* pOthers)
{
    if (spData == 0)
        return false;
    int nDepth = 0;
    FUN_1418bf500(nDepth, spData, pItems, pOthers);
    return !FUN_1405729c0(pItems);
}

// @0x1418bf500
bool FUN_1418bf500(int nDepth, MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems, ATL::CAtlArray<MS2Ptr<CItemData> >* pOthers)
{
    if (nDepth > 3)
        return false;
    ++nDepth;
    if (spData == 0)
        return false;
    int nItemId = spData->FUN_14053c510();
    int nGroup = FUN_14054a460(&spData->function.name);
    if (nGroup == 0)
        return false;
    std::vector<Unk_UabDrop> kDrops;
    FUN_1405a1fd0()->FUN_1402ea4c0(nGroup, kDrops);
    std::vector<Unk_UabDrop>::iterator it = kDrops.begin();
    ATL::CAtlMap<int, MS2Ptr<CItemData> > kUnused;
    for (; it != kDrops.end(); ++it)
    {
        Unk_UabDrop kDrop = *it;
        if (nItemId == kDrop.m_nItemId)
            continue;
        MS2Ptr<CItemData> spItem = FUN_14053f870(kDrop.m_nItemId);
        if (!spItem)
            continue;
        if (FUN_14053c5c0(spItem.operator->()) != 0x19)
        {
            if (FUN_14053cbc0(spItem.operator->()))
                pItems->Add(spItem);
            else
                pOthers->Add(spItem);
        }
        else
            FUN_1418bf500(nDepth, spItem, pItems, pOthers);
    }
    return true;
}

// ---- package keys ---------------------------------------------------------------------------------------------------

// @0x1418bf800
void FUN_1418bf800(int nKey, Unk_AvPackageKey* pOut)
{
    int nZero = 0;
    *pOut = Unk_AvPackageKey(nKey, nZero);
}

// A merat equip entry (asequipicon.h forward declares it): +0x28 the state, +0x48 the id.
class Unk_MeratEquipEntry : public CPtred
{
public:
    int FUN_1406ab1d0();                                        // state == 1
    int FUN_1406ab1a0();                                        // state == 0
    char m_pad_18[0x10];
    int m_nState;                                               // +0x28
    char m_pad_2c[0x1c];
    long m_nId;                                                 // +0x48
};

// @0x1418bf850
void FUN_1418bf850(MS2Ptr<Unk_MeratEquipEntry> spEntry, Unk_AvPackageKey* pOut)
{
    if (spEntry == 0)
        return;
    if (spEntry->FUN_1406ab1d0() != 0)
        return;
    if (spEntry->FUN_1406ab1a0() != 0)
    {
        int nZero = 0;
        *pOut = Unk_AvPackageKey(nZero, spEntry->m_nId);
    }
}

// ---- CAvatarPackageEquip --------------------------------------------------------------------------------------------

// @0x1418bf910
CAvatarPackageEquip::CAvatarPackageEquip()
{
}

// @0x1418bf980
void CAvatarPackageEquip::FUN_1418bf980()
{
    m_mapItems.RemoveAll();
}
MS2_REPLACE_METHOD(0x1418BF980, CAvatarPackageEquip, FUN_1418bf980, 31, 0x3AF2174B);

// @0x1418bf9b0
void CAvatarPackageEquip::FUN_1418bf9b0(Unk_InventoryEquipSlot nSlot, MS2Ptr<CItem> spItem)
{
    m_mapItems.SetAt(nSlot, spItem);
}
MS2_REPLACE_METHOD(0x1418BF9B0, CAvatarPackageEquip, FUN_1418bf9b0, 70, 0x2C9D4196);

// @0x1418bfa00
bool CAvatarPackageEquip::FUN_1418bfa00(UIAvatarPC* pOwner)
{
    if (m_mapItems.IsEmpty())
        return true;
    for (POSITION pos = m_mapItems.GetStartPosition(); pos != 0; m_mapItems.GetNext(pos))
    {
        MS2Ptr<CItem> spItem = m_mapItems.GetValueAt(pos);
        if (spItem == 0)
            continue;
        pOwner->FUN_1418bbcd0(spItem.get());
    }
    m_mapItems.RemoveAll();
    return true;
}
MS2_REPLACE_METHOD(0x1418BFA00, CAvatarPackageEquip, FUN_1418bfa00, 238, 0xE1975375);

// @0x1418bfb00
bool CAvatarPackageEquip::FUN_1418bfb00(UIAvatarPC* pOwner)
{
    if (m_mapItems.IsEmpty())
        return true;
    for (POSITION pos = m_mapItems.GetStartPosition(); pos != 0; m_mapItems.GetNext(pos))
    {
        MS2Ptr<CItem> spItem = m_mapItems.GetValueAt(pos);
        if (spItem == 0)
            continue;
        pOwner->FUN_1418bc380(spItem.get());
    }
    m_mapItems.RemoveAll();
    return true;
}
MS2_REPLACE_METHOD(0x1418BFB00, CAvatarPackageEquip, FUN_1418bfb00, 238, 0x1CF66422);

// @0x1418bfc00
MS2Ptr<CItem> CAvatarPackageEquip::FUN_1418bfc00(Unk_InventoryEquipSlot nSlot)
{
    if (m_mapItems.IsEmpty())
        return MS2Ptr<CItem>(0);
    MS2Ptr<CItem> spItem;
    m_mapItems.Lookup(nSlot, spItem);
    return spItem;
}
MS2_REPLACE_METHOD(0x1418BFC00, CAvatarPackageEquip, FUN_1418bfc00, 174, 0xD1003DF3);

// @0x1418bfcc0
bool CAvatarPackageEquip::FUN_1418bfcc0()
{
    return m_mapItems.IsEmpty();
}
MS2_REPLACE_METHOD(0x1418BFCC0, CAvatarPackageEquip, FUN_1418bfcc0, 31, 0xABDCEF43);

// @0x1418bffd0
float FUN_1418bffd0(Unk_UabCfgInt* pValue)
{
    return (float)*pValue->FUN_1402056b0();
}

// @0x1418c0f00
std::pair<std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator, bool> Unk_AvPackageMapView::FUN_1418c0f00(Unk_AvPackagePair&& kPair)
{
    return _Insert_nohint(false, std::move(kPair), std::_Not_a_node_tag());
}

// @0x1418c1410
CAvatarPackageEquip::~CAvatarPackageEquip()
{
}

// @0x1418c1dd0
// MS2-FUNCTIONAL: sets the rotation and the translation through the SetRotate / SetTranslate wrappers (the exe writes the node's local transform inline)
void FUN_1418c1dd0(NiAVObject* pNode, Unk_NiMatrix3* pRot, const Unk_NiPoint3& kPivot, const Unk_NiPoint3& kPos)
{
    Unk_StreamPoint kPivotPt(kPivot.x, kPivot.y, kPivot.z);
    Unk_StreamPoint kPosPt(kPos.x, kPos.y, kPos.z);
    FUN_140ddcca0(pNode, pRot);
    Unk_StreamPoint kRotated = pRot->FUN_140a00720(kPivotPt);
    Unk_StreamPoint kShift = kPosPt.FUN_14097fd50(kPivotPt);
    FUN_140981070(pNode, FUN_14027dcf0(kShift.FUN_140965c40(kRotated)));
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbc950-0x142cbca30 .text$yd
