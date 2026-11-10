// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uiavatarbase.h.
// MS2-UNIT: ?\uiavatarbase.cpp
// MS2-RANGE: 0x14010fe10-0x140110080 .text$di
// MS2-RANGE: 0x1418b7a10-0x1418c34c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAIAEAH$0A@@?$pair@I_K@std@@QEAA@AEAIAEAH@Z 0x1418bfd10 ; unique
// MS2-PIN: ??$?0AEAU?$pair@I_K@std@@AEAV?$MS2Ptr@VCAvatarPackageEquip@@@@$0A@@?$pair@$$CBU?$pair@I_K@std@@V?$MS2Ptr@VCAvatarPackageEquip@@@@@std@@QEAA@AEAU?$pair@I_K@1@AEAV?$MS2Ptr@VCAvatarPackageEquip@@@@@Z 0x1418bfea0 ; unique
// MS2-PIN: ??$?0AEAHAEAJ$0A@@?$pair@I_K@std@@QEAA@AEAHAEAJ@Z 0x1418bff00 ; unique
// MS2-PIN: ??$forward@AEAV?$MS2Ptr@VCAvatarPackageEquip@@@@@std@@YAAEAV?$MS2Ptr@VCAvatarPackageEquip@@@@AEAV1@@Z 0x1418c0e90 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@I_K@std@@V?$MS2Ptr@VCAvatarPackageEquip@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@I_K@std@@V?$MS2Ptr@VCAvatarPackageEquip@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1418c0ea0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCLimitCharRotate@ItemPreviewCommon@@@@QEAA@PEAVCLimitCharRotate@ItemPreviewCommon@@@Z 0x1418c10a0 ; prop
// MS2-PIN: ?IsNull@Unk_UabColorElem@@QEBA_NXZ 0x1418c14b0 ; unique
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
#define MS2_SVRPTR_ASSIGN_INT   // `m_spRow = 0` calls the exe's operator=(int) COMDAT (0x1409fac90)
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Matrix3.h>   // C3: efd::Matrix3::FromEulerAnglesXYZ
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
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cmainsystem.h"  // C3: was a local member view
#include "ms2/client/ms2/equipment.h"  // C3: was a local member view
#include "ms2/client/ms2/customize.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/placeholder/clientconstants.h"
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
                         const Vector3* pPivot, const Vector3* pPivotBase);   // 7 0x38 drags the camera
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
    virtual void vfunc_17(const NiPoint3& kPivot);                  // 17 0x88 sets the orbit pivot
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

// The game clock (singleton FUN_14086d260).
class Unk_UabClock;

NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                        // the scene root of an entity
void SetTranslate(NiAVObject* pNode, float fX, float fY, float fZ);    // SetTranslate(x, y, z)
float FUN_14059d930(float f);                                           // fabs
class CLogString* GetLogString();   // C3: was FUN_140166440
template <class A, class B, class C>
void Unk_EquipLog(CLogString* log, int level, int category, const wchar_t* format, const A& a, const B& b, const C& c);  // equipment.cpp, 3-argument log
void FUN_1418c1dd0(NiAVObject* pNode, Unk_NiMatrix3* pRot, const Unk_NiPoint3& kPivot, const Unk_NiPoint3& kPos);   // rotates about a pivot
int GetPreviewKind(int nKind);                                           // camera set of a kind
float FUN_141b48480(int nSet, int nIndex);                              // default angle
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60

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
UIRenderView* CreateModelView(int nWidth, int nHeight, GameObject* pObj, float fScale);   // creates the view of an object
int FUN_141ab7200(UIRenderView* pView, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg);

// ---- UIAvatarBase -------------------------------------------------------------------------------------------------

// @0x1418b7a10
UIAvatarBase::UIAvatarBase()
    : m_nKind(0), m_bLoaded(0), m_nObjectId(0), m_spView(0),
      m_kAngle(DAT_143b01a60), m_kAngleBase(DAT_143b01a60), m_kPos(DAT_143b01a60), m_kPosBase(DAT_143b01a60),
      m_kPivotBase(DAT_143b01a60), m_kPivot(DAT_143b01a60),
      m_nMode(0), m_fMoveStep(0.35f), m_fRotStep(0.2f), m_fZoomStep(30.0f), m_nState(0), m_nLocked(0),
      m_bWheelCamera(false), m_pListener(0)
{
}

// @0x1418b7c00
UIAvatarBase::~UIAvatarBase()
{
    m_spView = 0;
    m_pListener = 0;
    if (m_nObjectId > 0)
        WorldService::GetInstance()->FUN_141bbbcf0(m_nObjectId, 0);
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
    if (IsLoaded() == 0)
        return;
    if (m_spView)
        m_spView->vfunc_5(m_fZoomStep);
}
MS2_REPLACE_METHOD(0x1418B7D40, UIAvatarBase, vfunc_5, 103, 0xD0149146);

// @0x1418b7db0
void UIAvatarBase::vfunc_6()
{
    if (IsLoaded() == 0)
        return;
    if (m_spView)
        m_spView->vfunc_6(m_fZoomStep);
}
MS2_REPLACE_METHOD(0x1418B7DB0, UIAvatarBase, vfunc_6, 103, 0x89FCB062);

// @0x1418b7e20
void UIAvatarBase::vfunc_7(float n)
{
    if (IsLoaded() == 0)
        return;
    if (m_spView)
        m_spView->vfunc_9(n);
}
MS2_REPLACE_METHOD(0x1418B7E20, UIAvatarBase, vfunc_7, 102, 0x8C6A2478);

// @0x1418b7e90
void UIAvatarBase::vfunc_8(float n)
{
    if (IsLoaded() == 0)
        return;
    if (m_spView)
        m_spView->vfunc_8(n);
}
MS2_REPLACE_METHOD(0x1418B7E90, UIAvatarBase, vfunc_8, 102, 0x80C33D6C);

// @0x1418b7f00
void UIAvatarBase::vfunc_10(int dx, int dy, int dz, int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->GetEntity());
        if (!pNode)
            return;
        float fY = (float)dx * m_fRotStep;
        float fX = (float)dy * m_fRotStep;
        float fZ = -((float)dz * m_fRotStep);
        Vector3 kDelta(fX, fY, fZ);
        efd::Point3 kNewPos = reinterpret_cast<const efd::Point3&>(kDelta) + reinterpret_cast<const efd::Point3&>(m_kPosBase);
        float fLimit = m_kPivot.z;
        efd::Point3 kTarget = reinterpret_cast<const efd::Point3&>(kDelta) + reinterpret_cast<const efd::Point3&>(m_kPivotBase);
        if ((m_kPos - reinterpret_cast<Vector3&>(kTarget)).Length() > fLimit)
        {
            if (FUN_14059d930(m_kPos.x - kTarget.x) > fLimit)
            {
                float fClamp = m_kPos.x - kTarget.x > 0.0f ? -fLimit : fLimit;
                kTarget.x = m_kPos.x + fClamp;
            }
            if (FUN_14059d930(m_kPos.y - kTarget.y) > fLimit)
            {
                float fClamp = m_kPos.y - kTarget.y > 0.0f ? -fLimit : fLimit;
                kTarget.y = m_kPos.y + fClamp;
            }
            if (FUN_14059d930(m_kPos.z - kTarget.z) > fLimit)
            {
                float fClamp = m_kPos.z - kTarget.z > 0.0f ? -fLimit : fLimit;
                kTarget.z = m_kPos.z + fClamp;
            }
            reinterpret_cast<Vector3&>(kNewPos) = (reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(reinterpret_cast<Vector3&>(kTarget)) + reinterpret_cast<const efd::Point3&>(m_kPivot))) - reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Matrix3&>(((class NiAVObject*)(class NiAVObject*)(pNode))->GetRotate()) * reinterpret_cast<const efd::Point3&>(m_kPivot))));
        }
        ((class NiAVObject*)(class NiAVObject*)(pNode))->SetTranslate(*(class NiPoint3 const*)&static_cast<struct Unk_NiPoint3 const&>(reinterpret_cast<Vector3&>(kNewPos)));
        if (bUpdate)
            pNode->Update((float)((class CMainSystem*)(class Unk_UabClock*)(((class Unk_UabClock*)TSingleton<CMainSystem>::GetInstance())))->GetGameTime(), true);
    }
}

// @0x1418b8300
void UIAvatarBase::vfunc_11(int dx, int dy, int dz, int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    float fX = -((float)dx * m_fMoveStep);
    float fY = -((float)dy * m_fMoveStep);
    float fZ = -((float)dz * m_fMoveStep);
    Vector3 kDelta(fX, fY, fZ);
    float fWrapX = kDelta.x;
    float fWrapY = kDelta.y;
    float fWrapZ = kDelta.z;
    NormalizeAngle(&fWrapX);
    NormalizeAngle(&fWrapY);
    NormalizeAngle(&fWrapZ);
    SetVector3(&m_kAngleBase, fWrapX, fWrapY, fWrapZ);
    if (m_spView)
        m_spView->vfunc_7(fX, fY, fZ, bUpdate, &m_kPivot, &m_kPivotBase);
}
MS2_REPLACE_METHOD(0x1418B8300, UIAvatarBase, vfunc_11, 439, 0xE0EE83C6);

// @0x1418b84c0
void UIAvatarBase::vfunc_12(const Vector3& kDelta, Vector3& kRot)
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
    if (IsLoaded() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->GetEntity());
        if (pNode == 0)
            return;
        float fX = -((float)dx * m_fMoveStep);
        float fY = -((float)dy * m_fMoveStep);
        float fZ = -((float)dz * m_fMoveStep);
        if (90.0f < m_kAngle.y && m_kAngle.y < 270.0f)
            fZ = -fZ;
        Vector3 kDelta(fX, fY, fZ);
        efd::Point3 kRot = reinterpret_cast<const efd::Point3&>(kDelta) + reinterpret_cast<const efd::Point3&>(m_kAngle);
        vfunc_12(kDelta, reinterpret_cast<Vector3&>(kRot));
        vfunc_13(kRot.x, kRot.y, kRot.z, &m_kPivot, &m_kPivotBase, bUpdate);
    }
}

// @0x1418b8750
void UIAvatarBase::vfunc_13(float rx, float ry, float rz, const Vector3* pPivot, const Vector3* pPos, int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->GetEntity());
        if (!pNode)
            return;
        NormalizeAngle(&rx);
        NormalizeAngle(&ry);
        NormalizeAngle(&rz);
        SetVector3(&m_kAngleBase, rx, ry, rz);
        if (((void*)GetLogString()))
            Unk_EquipLog(GetLogString(), 0xb, 0x135, L"avatarDegree: {0}, {1}, {2}", m_kAngleBase.x, m_kAngleBase.y, m_kAngleBase.z);
        Unk_NiMatrix3 kRot;
        ((efd::Matrix3*)(struct Unk_NiMatrix3*)(&kRot))->MakeIdentity();
        float fRadX = (rx * 3.1415927f) / 180.0f;
        float fRadY = (ry * 3.1415927f) / 180.0f;
        float fRadZ = (rz * 3.1415927f) / 180.0f;
        reinterpret_cast<efd::Matrix3*>(&kRot)->FromEulerAnglesXYZ(fRadX, fRadY, fRadZ);
        FUN_1418c1dd0(pNode, &kRot, *pPivot, *pPos);
        if (bUpdate)
            pNode->Update((float)((class CMainSystem*)(class Unk_UabClock*)(((class Unk_UabClock*)TSingleton<CMainSystem>::GetInstance())))->GetGameTime(), true);
    }
}

// @0x1418b89f0
void UIAvatarBase::vfunc_15(float rx, float ry, float rz, int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->GetEntity());
        if (!pNode)
            return;
        const Vector3& kPos = reinterpret_cast<const Vector3&>(pNode->GetTranslate());
        vfunc_13(rx, ry, rz, &m_kPivot, &kPos, bUpdate);
        CopyVector3(&m_kAngle, &m_kAngleBase);
    }
}

// @0x1418b8b00
void UIAvatarBase::vfunc_16(int n, int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj != 0)
    {
        float fStep = (float)n * m_fMoveStep;
        efd::Point3 kAngle = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, fStep, 0.0f))) + reinterpret_cast<const efd::Point3&>(m_kAngle);
        NormalizeAngle(&kAngle.y);
        vfunc_20(kAngle.x, kAngle.y, kAngle.z, bUpdate);
        CopyVector3(&m_kAngleBase, reinterpret_cast<Vector3*>(&kAngle));
    }
}

// @0x1418b8c20
void UIAvatarBase::vfunc_17(float f, int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj != 0)
    {
        Vector3 kAngle(0.0f, f, 0.0f);
        NormalizeAngle(&kAngle.y);
        vfunc_20(kAngle.x, kAngle.y, kAngle.z, bUpdate);
        CopyVector3(&m_kAngle, &kAngle);
        CopyVector3(&m_kAngleBase, &m_kAngle);
    }
}

// @0x1418b8d00
void UIAvatarBase::vfunc_18(int n, int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj != 0)
    {
        float fStep = (float)n * m_fMoveStep;
        efd::Point3 kAngle = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, fStep))) + reinterpret_cast<const efd::Point3&>(m_kAngle);
        NormalizeAngle(&kAngle.z);
        vfunc_20(kAngle.x, kAngle.y, kAngle.z, bUpdate);
        CopyVector3(&m_kAngleBase, reinterpret_cast<Vector3*>(&kAngle));
    }
}

// @0x1418b8e20
void UIAvatarBase::vfunc_19(float f, int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj != 0)
    {
        Vector3 kAngle(0.0f, 0.0f, f);
        NormalizeAngle(&kAngle.z);
        vfunc_20(kAngle.x, kAngle.y, kAngle.z, bUpdate);
        CopyVector3(&m_kAngle, &kAngle);
        CopyVector3(&m_kAngleBase, &m_kAngle);
    }
}

// @0x1418b8f00
void UIAvatarBase::vfunc_20(float x, float y, float z, int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    Vector3 kAngle(x, y, z);
    vfunc_12(DAT_143b01a60, kAngle);
    GameObject* pObj = vfunc_23();
    if (!pObj)
        return;
    NiAVObject* pNode = FUN_141b6efc0(pObj->GetEntity());
    if (!pNode)
        return;
    Unk_NiMatrix3 kRot;
    ((efd::Matrix3*)(struct Unk_NiMatrix3*)(&kRot))->MakeIdentity();
    float fRadX = x > 0.0f ? (x * 3.1415927f) / 180.0f : 0.0f;
    float fRadY = y > 0.0f ? (y * 3.1415927f) / 180.0f : 0.0f;
    float fRadZ = z > 0.0f ? (z * 3.1415927f) / 180.0f : 0.0f;
    reinterpret_cast<efd::Matrix3*>(&kRot)->FromEulerAnglesXYZ(fRadX, fRadY, fRadZ);
    ((class NiAVObject*)(class NiAVObject*)(pNode))->SetRotate(*(class NiMatrix3 const*)(&kRot));
    if (bUpdate)
        pNode->Update((float)((class CMainSystem*)(class Unk_UabClock*)(((class Unk_UabClock*)TSingleton<CMainSystem>::GetInstance())))->GetGameTime(), true);
}

// @0x1418b9140
void UIAvatarBase::vfunc_9(float x, float y, float z, int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj == 0)
        return;
    NiAVObject* pNode = FUN_141b6efc0(pObj->GetEntity());
    if (pNode == 0)
        return;
    SetTranslate(pNode, x, y, z);
    if (bUpdate)
        pNode->Update((float)((class CMainSystem*)(class Unk_UabClock*)(((class Unk_UabClock*)TSingleton<CMainSystem>::GetInstance())))->GetGameTime(), true);
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
        return reinterpret_cast<GameObject*>(WorldService::GetInstance()->FindObjectById(m_nObjectId));
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
egf::EntityID UIAvatarBase::vfunc_26()
{
    GameObject* pObj = vfunc_24();
    if (pObj != 0)
    {
        return pObj->GetEntityID();
    }
    return egf::EntityID();
}

// @0x1418b9390
int UIAvatarBase::vfunc_27(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (IsLoaded() == 0)
        return 0;
    if (_stricmp("OnAvatarMouseDown", szEvent) == 0)
    {
        ASData kData;
        if (kData.SetArgsIfAny(pArgs, nArgs))
        {
            int nButton = kData.PopInt();
            if (SetModeFromButton(nButton) != 0)
            {
                if (m_nLocked == 0 && m_nMode == 2)
                {
                    SetMode(0);
                    return 1;
                }
                FUN_1418b9c10();
            }
            return 1;
        }
    }
    else if (_stricmp("OnAvatarMouseWheel", szEvent) == 0)
    {
        ASData kData;
        if (kData.SetArgsIfAny(pArgs, nArgs))
        {
            int nWheel = kData.PopInt();
            if (nWheel > 0)
                vfunc_5();
            else
                vfunc_6();
        }
        return 1;
    }
    else if (_stricmp("OnAvatarMouseMove", szEvent) == 0)
    {
        ASData kData;
        if (kData.SetArgsIfAny(pArgs, nArgs))
        {
            int nDx = kData.PopInt();
            int nDy = kData.PopInt();
            int nButton = kData.PopInt();
            int nMode = GetMode();
            if (GetModeForButton(nButton) != nMode)
                return 1;
            if (abs(nDx) > 2 || abs(nDy) > 2)
            {
                if (m_nLocked != 0 && nMode == 2)
                    vfunc_10(nDx, 0, nDy, 0);
                else if (nMode == 1)
                    vfunc_14(0, nDy, nDx, 1);
                else if (nMode == 3)
                    vfunc_11(0, nDy, nDx, 0);
            }
        }
        return 1;
    }
    return 0;
}

// @0x1418b9730
void UIAvatarBase::vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg, void* pUnused)
{
    GameObject* pObj = vfunc_24();
    if (pObj)
    {
        Unk_UabPoint kPtA;
        Unk_UabPoint kPtB;
        Unk_UISwfEntity_25* pEntA = spTarget.get();
        Unk_UISwfEntity_25* pEntB = spTarget.get();
        UIRenderView* pView = CreateModelView(pEntB->vfunc_5(&kPtB)->x, pEntA->vfunc_5(&kPtA)->y, pObj, 0.9f);
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
    if (pObj && m_nObjectId == pObj->GetObjectId())
    {
        SetLoaded(1);
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
    if (pObj && m_nObjectId == pObj->GetObjectId())
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
    if (pObj && m_nObjectId == pObj->GetObjectId())
    {
        SetLoaded(0);
        return 1;
    }
    return 0;
}

// @0x1418b9a60
int UIAvatarBase::vfunc_4(GameObject* pObj)
{
    if (pObj && m_nObjectId == pObj->GetObjectId())
    {
        SetLoaded(1);
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
int UIAvatarBase::GetState()
{
    return m_nState;
}
MS2_REPLACE_METHOD(0x1418B9B40, UIAvatarBase, GetState, 17, 0x444DCEE7);

// @0x1418b9b60
void UIAvatarBase::SetLoaded(int bLoaded)
{
    m_bLoaded = bLoaded;
}
MS2_REPLACE_METHOD(0x1418B9B60, UIAvatarBase, SetLoaded, 22, 0x5ED7A56F);

// @0x1418b9b80
int UIAvatarBase::IsLoaded()
{
    return m_bLoaded;
}
MS2_REPLACE_METHOD(0x1418B9B80, UIAvatarBase, IsLoaded, 14, 0xBA6447E3);

// @0x1418b9ba0
int UIAvatarBase::GetKind()
{
    return m_nKind;
}
MS2_REPLACE_METHOD(0x1418B9BA0, UIAvatarBase, GetKind, 14, 0xA25B27BF);

// @0x1418b9bc0
efd::SmartPointer<UIRenderView> UIAvatarBase::GetView()
{
    return m_spView;
}
MS2_REPLACE_METHOD(0x1418B9BC0, UIAvatarBase, GetView, 65, 0x23CF6EC9);

// @0x1418b9c10
void UIAvatarBase::FUN_1418b9c10()
{
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->GetEntity());
        if (!pNode)
            return;
        Unk_NiMatrix3* pRot = ((struct Unk_NiMatrix3*)&((class NiAVObject*)(class NiAVObject*)(pNode))->GetRotate());
        CopyVector3(&m_kAngle, &m_kAngleBase);
        const Vector3& kPos = reinterpret_cast<const Vector3&>(pNode->GetTranslate());
        m_kPosBase = kPos;
        if (reinterpret_cast<const efd::Point3&>(m_kAngleBase) != reinterpret_cast<const efd::Point3&>(DAT_143b01a60))
            FUN_1418ba4a0(pRot, &kPos, &m_kPivotBase);
        else
            m_kPivotBase = m_kPosBase;
        if (m_spView)
        {
            UIModelView* pModelView = dynamic_cast<UIModelView*>((UIRenderView*)m_spView);
            if (pModelView)
            {
                NiPoint3 kWorldPivot = reinterpret_cast<const efd::Point3&>(kPos) + reinterpret_cast<const efd::Point3&>(m_kPivot);
                pModelView->vfunc_17(kWorldPivot);
            }
        }
    }
}

// @0x1418b9df0
void UIAvatarBase::ResetView(bool bAngle, bool bPosition)
{
    if (bAngle)
        FUN_1418ba340(0);
    if (bPosition)
        ApplyPosition(0);
}
MS2_REPLACE_METHOD(0x1418B9DF0, UIAvatarBase, ResetView, 65, 0xB30BF4F3);

// @0x1418b9e40
void UIAvatarBase::FUN_1418b9e40()
{
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->GetEntity());
        if (!pNode)
            return;
        m_kPos = reinterpret_cast<const Vector3&>(pNode->GetTranslate());
        m_kPosBase = m_kPos;
        m_kPivotBase = m_kPos;
        float fBody = 0.0f;
        NiAVObject* pBody;
        NiAVObject* pFound = pBody = pNode->GetObjectByName("Eff_Body");
        if (pBody)
            fBody = (*((Vector3 const*)&((class NiAVObject*)(class NiAVObject*)(pBody))->GetWorldTranslate()) - m_kPos).Length();
        void* pBound = ((void*)&((class NiAVObject*)(class NiAVObject*)(pNode))->GetWorldBound());
        float fHeight = ((Vector3 const*)&((class NiBound*)(void*)(pBound))->GetCenter())->z - m_kPos.z;
        float fExtra = fHeight - fBody;
        if (fBody > 0.0f && fExtra > 25.0f)
            fHeight = fBody + 25.0f;
        m_kPivot = Vector3(0.0f, 0.0f, fHeight);
        NiPoint3 kAngle = pObj->vfunc_20();
        Unk_NiMatrix3* pRot = ((struct Unk_NiMatrix3*)&((class NiAVObject*)(class NiAVObject*)(pNode))->GetRotate());
        reinterpret_cast<const efd::Matrix3*>(pRot)->ToEulerAnglesXYZ(static_cast<efd::Point3&>(kAngle).x, static_cast<efd::Point3&>(kAngle).y, static_cast<efd::Point3&>(kAngle).z);
        kAngle.x = (kAngle.x * 180.0f) / 3.1415927f;
        kAngle.y = (kAngle.y * 180.0f) / 3.1415927f;
        kAngle.z = (kAngle.z * 180.0f) / 3.1415927f;
        NormalizeAngles(reinterpret_cast<Vector3*>(&kAngle));
        m_kAngle = reinterpret_cast<const Vector3&>(kAngle);
        m_kAngleBase = reinterpret_cast<const Vector3&>(kAngle);
    }
}

// @0x1418ba120
void UIAvatarBase::SetMode(int nMode)
{
    m_nMode = nMode;
}
MS2_REPLACE_METHOD(0x1418BA120, UIAvatarBase, SetMode, 25, 0xE467F5FB);

// @0x1418ba140
int UIAvatarBase::GetMode()
{
    return m_nMode;
}
MS2_REPLACE_METHOD(0x1418BA140, UIAvatarBase, GetMode, 17, 0xD9D952B7);

// @0x1418ba160
int UIAvatarBase::SetModeFromButton(int nButton)
{
    m_nMode = GetModeForButton(nButton);
    return m_nMode;
}
MS2_REPLACE_METHOD(0x1418BA160, UIAvatarBase, SetModeFromButton, 54, 0x8F49F212);

// @0x1418ba1a0
int UIAvatarBase::GetModeForButton(int nButton)
{
    if (nButton == 0)
        return 2;
    else if (nButton == 1)
        return m_bWheelCamera ? 3 : 1;
    return 0;
}

// @0x1418ba200
void UIAvatarBase::SetVector3(Vector3* pDst, float x, float y, float z)
{
    pDst->x = x;
    pDst->y = y;
    pDst->z = z;
}
MS2_REPLACE_METHOD(0x1418BA200, UIAvatarBase, SetVector3, 70, 0x3C835994);

// @0x1418ba250
void UIAvatarBase::CopyVector3(Vector3* pDst, const Vector3* pSrc)
{
    *pDst = *pSrc;
}
MS2_REPLACE_METHOD(0x1418BA250, UIAvatarBase, CopyVector3, 39, 0xE8027097);

// @0x1418ba280
void UIAvatarBase::ApplyPosition(int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    GameObject* pObj = vfunc_23();
    if (pObj != 0)
    {
        vfunc_9(m_kPos.x, m_kPos.y, m_kPos.z, bUpdate);
        m_kPosBase = m_kPos;
        m_kPivotBase = m_kPos;
    }
}

// @0x1418ba340
void UIAvatarBase::FUN_1418ba340(int bUpdate)
{
    if (IsLoaded() == 0)
        return;
    Vector3 kAngle;
    FUN_1418ba410(&kAngle);
    vfunc_9(kAngle.x, kAngle.y, kAngle.z, 0);
    int nSet = GetPreviewKind(GetKind());
    vfunc_19(FUN_141b48480(nSet, 0), bUpdate);
}
MS2_REPLACE_METHOD(0x1418BA340, UIAvatarBase, FUN_1418ba340, 160, 0xB1D02095);

// @0x1418ba3f0
void UIAvatarBase::SetLocked(int n)
{
    m_nLocked = n;
}
MS2_REPLACE_METHOD(0x1418BA3F0, UIAvatarBase, SetLocked, 25, 0x9EB3CF4F);

// @0x1418ba410
void UIAvatarBase::FUN_1418ba410(Vector3* pOut)
{
    GameObject* pObj = vfunc_23();
    if (pObj)
    {
        NiAVObject* pNode = FUN_141b6efc0(pObj->GetEntity());
        if (pNode == 0)
            return;
        Unk_NiMatrix3* pRot = ((struct Unk_NiMatrix3*)&((class NiAVObject*)(class NiAVObject*)(pNode))->GetRotate());
        FUN_1418ba4a0(pRot, reinterpret_cast<const Vector3*>(&pNode->GetTranslate()), pOut);
    }
}

// @0x1418ba4a0
void UIAvatarBase::FUN_1418ba4a0(Unk_NiMatrix3* pRot, const Vector3* pPos, Vector3* pOut)
{
    if (reinterpret_cast<const efd::Point3&>(m_kAngleBase) != reinterpret_cast<const efd::Point3&>(DAT_143b01a60))
        *pOut = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((*pPos - m_kPivot))) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Matrix3&>(*pRot) * reinterpret_cast<const efd::Point3&>(m_kPivot)))))));
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


// The client constants used by the rotation limit.
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
float FUN_1418bffd0(Common::Constants::Value<int>* pValue);                             // the int value as a float

MS2Ptr<CItemData> FUN_1403bb3b0(const MS2Ptr<CItemData>& sp);

int FUN_141423cf0(__int64, struct Unk_UgcExtra const&, struct Unk_UgcPlayer*, int);   // C3: was FUN_141423cf0
Unk_CharEquip FUN_141b6dea0(unsigned uColor);                           // colour value -> equip record

unsigned int FUN_141420a30(unsigned int, class CItem*, class AvatarPC*);   // C3: was FUN_141420a30

// Avatar state helpers.
CString FUN_1409a2360(const char* psz, int n);                          // converts the string

// @0x1418ba570
UIAvatarPC::UIAvatarPC(PC* pSource, bool bFlag)
    : m_spCustomize(0), m_bFlag(bFlag), m_nPose(0), m_nAction(1), m_nActionParam(10)
{
    m_nKind = 1;
    AvatarPC* pAvatar = CreateAvatarFromPC(pSource);
    if (pAvatar)
    {
        pAvatar->SetListener(this);
        m_nObjectId = pAvatar->GetObjectId();
        FUN_1418bd780(pSource, pAvatar);
    }
}

// @0x1418ba6b0
UIAvatarPC::UIAvatarPC(int nGender, bool bFlag)
    : m_spCustomize(0), m_bFlag(bFlag), m_nPose(0), m_nAction(1), m_nActionParam(10)
{
    m_nKind = 1;
    AvatarPC* pAvatar = CreatePreviewAvatar(nGender, 10000);
    if (pAvatar)
    {
        pAvatar->SetListener(this);
        m_nObjectId = pAvatar->GetObjectId();
        FUN_1418bd780(0, pAvatar);
    }
}

// @0x1418ba7f0
UIAvatarPC::UIAvatarPC(MS2Ptr<Unk_PCArg125> spSrc, bool bFlag)
    : m_spCustomize(0), m_bFlag(bFlag), m_nPose(0), m_nAction(1), m_nActionParam(10)
{
    m_nKind = 1;
    AvatarPC* pAvatar = CreateAvatarFromPCRecord(spSrc);
    if (pAvatar)
    {
        pAvatar->SetListener(this);
        m_nObjectId = pAvatar->GetObjectId();
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
    m_spRotLimit.AssignRaw(new ItemPreviewCommon::CLimitCharRotate(GetClientConstants()->UgcshopCharRotateStartDegreeY.Read(),
                                                                   FUN_1418bffd0(&GetClientConstants()->UgcshopCharRotateEndDegreeY)));
}

// @0x1418baab0
void UIAvatarPC::vfunc_2()
{
    UIAvatarBase::vfunc_2();
    if (m_spCustomize.get())
        m_spCustomize->RestoreAll();
    m_mapPackages.clear();
}
MS2_REPLACE_METHOD(0x1418BAAB0, UIAvatarPC, vfunc_2, 94, 0x5098D0EE);

// @0x1418bab20
void UIAvatarPC::vfunc_21(UIRenderView* pView)
{
    UIAvatarBase::vfunc_21(pView);
    AvatarPC* pAvatar = efd::DynamicCast<AvatarPC>(vfunc_24());
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
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar && pAvatar->FUN_1409f4f20())
    {
        unsigned nRideeId = pAvatar->GetRideeObjectId();
        if (nRideeId > 0)
            return reinterpret_cast<GameObject*>(WorldService::GetInstance()->FindObjectById(nRideeId));
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
        if (kData.SetArgsIfAny(pArgs, nArgs))
        {
            int nColorA = kData.PopUInt();
            int nColorB = kData.PopUInt();
            FUN_1418bca10(FUN_141b6dea0(nColorA), FUN_141b6dea0(nColorB));
        }
        return 1;
    }
    else if (_stricmp("OnAvatarClickPose", szEvent) == 0)
    {
        ASData kData;
        if (kData.SetArgsIfAny(pArgs, nArgs))
        {
            int nPose = kData.PopInt();
            SetPose(nPose);
        }
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
void UIAvatarPC::EquipItemId(int nValue)
{
    if (m_spCustomize.get())
        m_spCustomize->EquipItemId(nValue);
}
MS2_REPLACE_METHOD(0x1418BAEF0, UIAvatarPC, EquipItemId, 73, 0x234AD161);

// @0x1418baf40
void UIAvatarPC::EquipItem(CItem* pItem)
{
    if (m_spCustomize.get())
        m_spCustomize->EquipItem(pItem);
}
MS2_REPLACE_METHOD(0x1418BAF40, UIAvatarPC, EquipItem, 75, 0x86EAC9CE);

// @0x1418bafa0
void UIAvatarPC::FUN_1418bafa0(CItem* pItem, int nEffect)
{
    if (m_spCustomize == 0)
        return;
    m_spCustomize->EquipItem(pItem);
    if (0 < nEffect)
    {
        AvatarPC* pAvatar = efd::DynamicCast<AvatarPC>(vfunc_24());
        if (pAvatar == 0)
            return;
        MS2Ptr<ItemColorEx> kRow = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColor(nEffect, 0);
        if (kRow == 0)
            return;
        FUN_141423cf0(pItem->GetItemUid(), *(struct Unk_UgcExtra const*)&(*kRow), (struct Unk_UgcPlayer*)(pAvatar), 0);
    }
}

// @0x1418bb0c0
bool UIAvatarPC::FUN_1418bb0c0(CItem* pItem)
{
    return FUN_1418bb0f0(pItem, 0);
}

bool FUN_1418bf430(MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems, ATL::CAtlArray<MS2Ptr<CItemData> >* pOthers);   // walks the drops of a cube item set
int FUN_141420f10(CItemData* pData, AvatarPC* pAvatar);                 // the customize id of an item data
__int64 GenerateUniqueId();                                                // next item uid
MS2_REPLACE_METHOD(0x1418BB0C0, UIAvatarPC, FUN_1418bb0c0, 37, 0xF0568DFA);

// @0x1418bb0f0
bool UIAvatarPC::FUN_1418bb0f0(CItem* pItem, int nEffect)
{
    if (m_spCustomize == 0 || pItem == 0)
        return false;
    MS2Ptr<CItemData> spData(((class CItemData*)((class CItem*)(class CItem*)(pItem))->FUN_140527840()));
    if (spData == 0 || ((class CItemData*)(class CItemData*)(spData.operator->()))->GetType() != 0x19)
        return false;
    ATL::CAtlArray<MS2Ptr<CItemData> > kItems;
    ATL::CAtlArray<MS2Ptr<CItemData> > kOthers;
    if (!FUN_1418bf430(MS2Ptr<CItemData>(spData), &kItems, &kOthers))
        return false;
    return FUN_1418bb2a0(MS2Ptr<CItemData>(spData), nEffect, &kItems);
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
    if (((class CItemData*)(class CItemData*)(spData.operator->()))->GetType() != 0x19)
        return false;
    if (((ATL::CAtlArray<MS2Ptr<CItemData>, ATL::CElementTraits<MS2Ptr<CItemData>>>*)(void*)(pItems))->IsEmpty())
        return false;
    unsigned nId = spData->GetItemId();
    int nZero = 0;
    Unk_AvPackageKey kKey(nId, nZero);
    return FUN_1418bb3f0(&kKey, nEffect, pItems);
}

// MS2-FUNCTIONAL: 2050 vs 2090 bytes: the exe destroys the per-slot MS2Ptr<CItemData>/MS2Ptr<CItem> temporaries on early-continue paths (4 more dtor calls) and indexes the equip list through Unk_PtItemList::FUN_140c3c720 (MS2Ptr<CEquipItem>&) instead of CAtlArray<MS2Ptr<CItem>>::operator[]; loop restructure pending
// @0x1418bb3f0
bool UIAvatarPC::FUN_1418bb3f0(Unk_AvPackageKey* pKey, int nEffect, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems)
{
    if (m_spCustomize == 0 || ((ATL::CAtlArray<MS2Ptr<CItemData>, ATL::CElementTraits<MS2Ptr<CItemData>>>*)(void*)(pItems))->IsEmpty())
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
        if (spItemData == 0)
            continue;
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem == 0)
            continue;
        spItem->FUN_140523c40(spItemData->GetItemId(), 1, 0);
        int nCustomizeId = FUN_141420f10(spItemData.get(), GetAvatarPC());
        ((class CItem*)(class CItem*)(spItem.operator->()))->FUN_140526c10(nCustomizeId);
        spItem->SetItemUid(GenerateUniqueId());
        ((class CItem*)(class CItem*)(spItem.operator->()))->SetObjectId(vfunc_25());
        if (FUN_1418bd350(&kItemKey, nCustomizeId))
            kKeys.Add(kItemKey);
        kNewItems.Add(spItem);
    }
    if (!kKeys.IsEmpty())
    {
        for (size_t i = 0; i < kKeys.GetCount(); i++)
            FUN_1418bc500(&kKeys[i]);
    }
    for (size_t i = 0; i < kNewItems.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem(kNewItems[i]);
        if (spItem == 0 || ((class CItemData*)((class CItem*)(class CItem*)(spItem.operator->()))->FUN_140527840()) == 0)
            continue;
        FUN_1418bafa0(spItem.get(), nEffect);
        MS2Ptr<CItemData> spData(((class CItemData*)((class CItem*)(class CItem*)(spItem.operator->()))->FUN_140527840()));
        if (((class CItemData*)(class CItemData*)(spData.operator->()))->FUN_14053d2b0())
        {
            spNew->FUN_1418bf9b0((Unk_InventoryEquipSlot)8, MS2Ptr<CItem>(spItem));
            spNew->FUN_1418bf9b0((Unk_InventoryEquipSlot)9, MS2Ptr<CItem>(spItem));
        }
        else if (((class CItemData*)(class CItemData*)(spData.operator->()))->FUN_14053d460())
        {
            spNew->FUN_1418bf9b0((Unk_InventoryEquipSlot)4, MS2Ptr<CItem>(spItem));
            spNew->FUN_1418bf9b0((Unk_InventoryEquipSlot)5, MS2Ptr<CItem>(spItem));
        }
        else
            spNew->FUN_1418bf9b0((Unk_InventoryEquipSlot)spItem.operator->()->FUN_140526c30(), MS2Ptr<CItem>(spItem));
    }
    static_cast<Unk_AvPackageMapView&>(m_mapPackages).FUN_1418c0f00(Unk_AvPackagePair(*pKey, spNew));
    return !spNew->IsEmpty();
}

__int64 GetServerTime();                                                // the server time

// @0x1418bbc20
void UIAvatarPC::FUN_1418bbc20(int nValue)
{
    if (m_spCustomize.get())
        m_spCustomize->UnequipId(nValue);
}
MS2_REPLACE_METHOD(0x1418BBC20, UIAvatarPC, FUN_1418bbc20, 73, 0xA926B992);

// @0x1418bbc70
void UIAvatarPC::FUN_1418bbc70(CItem* pItem)
{
    if (m_spCustomize.get())
        m_spCustomize->UnequipUid((__int64)pItem);
}
MS2_REPLACE_METHOD(0x1418BBC70, UIAvatarPC, FUN_1418bbc70, 75, 0x8526D769);

// @0x1418bbcd0
void UIAvatarPC::FUN_1418bbcd0(CItem* pItem)
{
    if (m_spCustomize.get())
        m_spCustomize->Unequip(pItem);
}
MS2_REPLACE_METHOD(0x1418BBCD0, UIAvatarPC, FUN_1418bbcd0, 75, 0xB39DF306);

// @0x1418bbd30
void UIAvatarPC::UnequipSlot(int nSlot)
{
    if (m_spCustomize == 0)
        return;
    PC* pPlayer = efd::DynamicCast<PC>(vfunc_24());
    if (!pPlayer)
        return;
    MS2Ptr<CEquipItem> spEquip = pPlayer->GetEquipItemLayer1(nSlot);
    if (spEquip.get())
        FUN_1418bbc70((CItem*)spEquip->GetItemUid());
    MS2Ptr<CEquipItem> spEquip2 = pPlayer->GetEquipItemLayer0(nSlot);
    if (spEquip2.get())
        FUN_1418bbc70((CItem*)spEquip2->GetItemUid());
}

// @0x1418bbe40
void UIAvatarPC::ClearPreview()
{
    if (m_spCustomize.get())
        m_spCustomize->ClearPreview();
    m_mapPackages.clear();
}
MS2_REPLACE_METHOD(0x1418BBE40, UIAvatarPC, ClearPreview, 84, 0xF86CA209);

// @0x1418bbea0
bool UIAvatarPC::FUN_1418bbea0(Unk_AvPackageKey* pKey)
{
    if (m_spCustomize == 0 || m_mapPackages.empty())
        return false;
    MS2Ptr<CAvatarPackageEquip> spPackage(0);
    if (m_mapPackages.find(*pKey) == m_mapPackages.end())
        return false;
    if ((spPackage.get() ? true : false) && spPackage->FUN_1418bfa00(this))
        m_mapPackages.erase(*pKey);
    return true;
}

// @0x1418bbfe0
bool UIAvatarPC::FUN_1418bbfe0()
{
    if (m_spCustomize == 0 || m_mapPackages.empty())
        return false;
    for (std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator it = m_mapPackages.begin();
         it != m_mapPackages.end(); ++it)
    {
        MS2Ptr<CAvatarPackageEquip> spPackage(it->second);
        if (spPackage == 0)
            continue;
        spPackage->FUN_1418bfa00(this);
    }
    m_mapPackages.clear();
    return true;
}

// @0x1418bc110
void UIAvatarPC::FUN_1418bc110(MS2Ptr<CItem> spItem)
{
    if (IsLoaded() == 0)
        return;
    if (spItem == 0 || !((class CItemData*)((class CItem*)(class CItem*)(spItem.operator->()))->FUN_140527840()))
        return;
    if (!((class CItemData*)(class CItemData*)(((class CItemData*)((class CItem*)(class CItem*)(spItem.operator->()))->FUN_140527840())))->FUN_14053cc00())
        return;
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar)
        pAvatar->EquipItem(MS2Ptr<CItem>(spItem));
}

// @0x1418bc210
void UIAvatarPC::vfunc_3()
{
    UIAvatarBase::vfunc_3();
    if (m_spCustomize.get())
        m_spCustomize->RestoreAll();
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
    PC* pPlayer = efd::DynamicCast<PC>(vfunc_24());
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
    if (pItem == 0)
        return;
    PC* pPlayer = efd::DynamicCast<PC>(vfunc_24());
    if (pPlayer == 0)
        return;
    if (m_spCustomize.get())
    {
        m_spCustomize->Unequip(pItem);
        int nCustomizeId = FUN_141420a30(((class CItemData*)(class CItemData*)(((class CItemData*)((class CItem*)(class CItem*)(pItem))->FUN_140527840())))->GetModelOrEmpty()->GetGroup(0)->GetType(), pItem, (class AvatarPC*)(pPlayer));
        MS2Ptr<CItemData> spData(((class CItemData*)((class CItem*)(class CItem*)(pItem))->FUN_140527840()));
        if (spData.get())
            m_spCustomize->ApplyItem(MS2Ptr<CItem>(pItem), nCustomizeId);
    }
}

// @0x1418bc500
void UIAvatarPC::FUN_1418bc500(Unk_AvPackageKey* pKey)
{
    if (m_spCustomize == 0 || m_mapPackages.empty())
        return;
    std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator it = m_mapPackages.find(*pKey);
    if (it != m_mapPackages.end())
    {
        MS2Ptr<CAvatarPackageEquip> spPackage(it->second);
        if ((spPackage.get() ? true : false) && spPackage->FUN_1418bfb00(this))
            m_mapPackages.erase(*pKey);
    }
}

// @0x1418bc630
void UIAvatarPC::FUN_1418bc630()
{
    if (m_mapPackages.empty())
        return;
    for (std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator it = m_mapPackages.begin();
         it != m_mapPackages.end(); ++it)
    {
        MS2Ptr<CAvatarPackageEquip> spPackage(it->second);
        if (spPackage == 0)
            continue;
        spPackage->FUN_1418bfb00(this);
    }
    m_mapPackages.clear();
}

// @0x1418bc740
int UIAvatarPC::GetGender()
{
    PCBase* pPc = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1290(m_nObjectId));
    if (pPc != 0)
        return ((class PC*)(class PCBase*)(pPc))->GetGender();
    return 3;
}

// @0x1418bc790
void UIAvatarPC::FUN_1418bc790(int nState, int nParam)
{
    GameObject* pObj = vfunc_24();
    if (pObj != 0)
    {
        AvatarPC* pAvatar = GetAvatarPC();
        if (pAvatar)
        {
            int nMode = pAvatar->GetType();
            if (nMode == 1)
                FUN_1418bca60(nState, nParam);
            else
            {
                if (pAvatar->GetCurStateId() != nState)
                    pAvatar->vfunc_59(nState, 0, 0, 0);
                ((class PCBase*)(class PCBase*)(pAvatar))->FUN_14166cc40(nParam);
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
        AvatarPC* pAvatar = efd::DynamicCast<AvatarPC>(pObj);
        if (pAvatar)
            ((class PCBase*)(class PCBase*)(pAvatar))->FUN_14166cc40(nParam);
    }
}
MS2_REPLACE_METHOD(0x1418BC860, UIAvatarPC, FUN_1418bc860, 87, 0x23A51193);

// @0x1418bc8c0
void UIAvatarPC::SetSkinColor(int nSkin, int /*nUnused*/)
{
    if (nSkin == 0)
        return;
    Unk_CharEquip kColor0;
    Unk_CharEquip kColor1;
    {
        MS2Ptr<ItemColorEx> kRow = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColor(nSkin, 0);
        if (kRow.get())
        {
            kColor0 = FUN_141b6dea0(kRow.operator->()->m_aValues[0]);
            kColor1 = FUN_141b6dea0(kRow.operator->()->m_aValues[2]);
        }
    }
    FUN_1418bca10(kColor0, kColor1);
}

// @0x1418bca10
void UIAvatarPC::FUN_1418bca10(Unk_CharEquip kColor0, Unk_CharEquip kColor1)
{
    AvatarPC* pAvatar = GetAvatarPC();
    if (!pAvatar)
        return;
    pAvatar->FUN_1409f41d0(kColor0, kColor1);
}

// @0x1418bca60
void UIAvatarPC::FUN_1418bca60(int nState, int nParam)
{
    AvatarPC* pAvatar = GetAvatarPC();
    if (!pAvatar)
        return;
    if (pAvatar->GetCurStateId() != nState)
        pAvatar->vfunc_59(nState, 0, 0, 0);
    if (nState == 1)
    {
        ((class PCBase*)(class PCBase*)(pAvatar))->FUN_14166cc40(nParam);
        if (nParam == 10)
        {
            efd::utf8string kIdle("Idle_A");
            pAvatar->PlayAnimation(kIdle, 1.0f, false, false);
        }
        else if (nParam == 0xb)
        {
            efd::utf8string kIdle("Idle_B");
            pAvatar->PlayAnimation(kIdle, 1.0f, false, false);
        }
    }
    else if (nState == 0xe)
    {
        ((class PCBase*)(class PCBase*)(pAvatar))->SetEmotion(1);
        ((class PC*)(class PCBase*)(pAvatar))->UpdateWeaponAction();
        efd::utf8string kName((const char*)FUN_1409a2360((const char*)pAvatar->vfunc_60(), 0));
        if (((efd::utf8string*)&static_cast<class efd::utf8string const&>(kName))->empty())
        {
            efd::utf8string kSword("Sword");
            pAvatar->PlayAnimation(kSword, 1.0f, false, false);
        }
        else
        {
            kName.erase(kName.length() - 1, 1);
            pAvatar->PlayAnimation(kName, 1.0f, false, false);
        }
    }
}

// @0x1418bcd20
bool UIAvatarPC::SetPoseIndex(int nPose)
{
    if (nPose < 0)
        return false;
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar)
    {
        int nIndex = nPose;
        return ApplyPose(nIndex);
    }
    return false;
}

// @0x1418bcd80
bool UIAvatarPC::ApplyPose(int nPose)
{
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar)
    {
        int nState = 1;
        int nParam = 10;
        switch (nPose)
        {
        case 0:
            nState = 1;
            nParam = 10;
            break;
        case 1:
            nState = 1;
            nParam = 0xb;
            break;
        case 2:
            nState = 0xe;
            nParam = 0x55;
            break;
        case 3:
            nState = 1;
            nParam = 0x16;
            break;
        }
        if (IsLoaded())
            FUN_1418bc790(nState, nParam);
        else
        {
            m_nAction = nState;
            m_nActionParam = nParam;
        }
        return true;
    }
    return false;
}

// @0x1418bce80
void UIAvatarPC::FUN_1418bce80(int nValue)
{
    if (IsLoaded() == 0)
        return;
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar)
        pAvatar->FUN_14166ed70(nValue);
}
MS2_REPLACE_METHOD(0x1418BCE80, UIAvatarPC, FUN_1418bce80, 71, 0x16AEDF01);

// @0x1418bced0
void UIAvatarPC::FUN_1418bced0(MS2Ptr<CItemData> spData)
{
    if (IsLoaded() == 0)
        return;
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar)
        pAvatar->FUN_1409f42a0(MS2Ptr<CItemData>(spData));
}
MS2_REPLACE_METHOD(0x1418BCED0, UIAvatarPC, FUN_1418bced0, 133, 0x1531DAE4);

// @0x1418bcf60
void UIAvatarPC::FUN_1418bcf60(int nSkillId, short nLevel)
{
    if (IsLoaded() == 0)
        return;
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar)
        pAvatar->PlaySkill(nSkillId, nLevel);
}
MS2_REPLACE_METHOD(0x1418BCF60, UIAvatarPC, FUN_1418bcf60, 83, 0xDC9E76BB);

// @0x1418bcfc0
void UIAvatarPC::FUN_1418bcfc0(MS2Ptr<CItemData> spData)
{
    if (IsLoaded() == 0)
        return;
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar)
        pAvatar->PlayInstrument(MS2Ptr<CItemData>(spData));
}
MS2_REPLACE_METHOD(0x1418BCFC0, UIAvatarPC, FUN_1418bcfc0, 133, 0xDDA4CAF5);

// @0x1418bd050
void UIAvatarPC::FUN_1418bd050(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem)
{
    if (IsLoaded() == 0)
        return;
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar)
        pAvatar->ShowRidee(MS2Ptr<CItemData>(spData), MS2Ptr<CItem>(spItem));
}
MS2_REPLACE_METHOD(0x1418BD050, UIAvatarPC, FUN_1418bd050, 238, 0x27EC8CD8);

// @0x1418bd150
void UIAvatarPC::FUN_1418bd150(unsigned int a, unsigned int b)
{
    if (!IsLoaded())
        return;
    vfunc_20(0.0f, 0.0f, 0.0f, 1);
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar)
        pAvatar->FUN_1409f4cf0(a, b);
}

// @0x1418bd1d0
AvatarPC* UIAvatarPC::GetAvatarPC()
{
    return efd::DynamicCast<AvatarPC>(vfunc_24());
}
MS2_REPLACE_METHOD(0x1418BD1D0, UIAvatarPC, GetAvatarPC, 41, 0xF3F5DAB3);

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
bool UIAvatarPC::HasPackages()
{
    return !m_mapPackages.empty();
}
MS2_REPLACE_METHOD(0x1418BD300, UIAvatarPC, HasPackages, 63, 0xFA23326B);

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
MS2Ptr<Customize> UIAvatarPC::GetCustomize()
{
    return m_spCustomize;
}
MS2_REPLACE_METHOD(0x1418BD710, UIAvatarPC, GetCustomize, 67, 0xBAB44D00);

// @0x1418bd760
int UIAvatarPC::GetPose()
{
    return m_nPose;
}
MS2_REPLACE_METHOD(0x1418BD760, UIAvatarPC, GetPose, 17, 0x38E3250F);

// @0x1418bd780
void UIAvatarPC::FUN_1418bd780(PC* pSource, AvatarPC* pAvatar)
{
    if (pAvatar == 0)
        return;
    __int64 nNow = GetServerTime();
    CMsTime kZero((__time64_t)0);
    CMsTime kNow(nNow);
    ((class CEquipment*)(void*)(((void*)((class PC*)(class AvatarPC*)(pAvatar))->GetEquipment())))->SetLayerPeriod(kNow, kZero);
}

// @0x1418bd7f0
void UIAvatarPC::SetEnabled(bool bEnabled)
{
    AvatarPC* pAvatar = GetAvatarPC();
    if (pAvatar == 0)
        return;
    pAvatar->SetEnabled(bEnabled);
}

// @0x1418bd830
void UIAvatarPC::ReapplyPose()
{
    SetPose(m_nPose);
}
MS2_REPLACE_METHOD(0x1418BD830, UIAvatarPC, ReapplyPose, 35, 0xCAA1BF50);

// @0x1418bd860
void UIAvatarPC::SetPose(int nPose)
{
    FUN_1418ba340(0);
    SetPoseIndex(nPose);
    m_nPose = nPose;
    if (m_pListener)
        m_pListener->vfunc_o178_3(this);
}

// ---- UIAvatarCube / UIAvatarRidee / UIAvatarPet -------------------------------------------------------------------

MS2_REPLACE_METHOD(0x1418BD860, UIAvatarPC, SetPose, 109, 0xB0325FFA);

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
    AvatarCube* pCube = CreateAvatarCube(m_pItemData);
    if (pCube)
    {
        if (WorldService::GetInstance()->FUN_141bbb1e0(pCube, 0, 1))
        {
            m_nObjectId = pCube->GetObjectId();
            pCube->SetListener(this);
        }
    }
}
MS2_REPLACE_METHOD(0x1418BD9A0, UIAvatarCube, vfunc_1, 161, 0x5E232546);

// @0x1418bda50
void UIAvatarCube::vfunc_21(UIRenderView* pView)
{
    UIAvatarBase::vfunc_21(pView);
    AvatarCube* pCube = efd::DynamicCast<AvatarCube>(vfunc_24());
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
    AvatarCube* pCube = efd::DynamicCast<AvatarCube>(vfunc_24());
    if (pCube)
        pCube->vfunc_58(MS2Ptr<CItemData>(0), MS2Ptr<CItem>(0));
}
MS2_REPLACE_METHOD(0x1418BDAE0, UIAvatarCube, FUN_1418bdae0, 195, 0x801587E0);

// @0x1418bdbb0
void UIAvatarCube::vfunc_22()
{
    float fAngle = FUN_141b48480(GetPreviewKind(GetKind()), 0);
    vfunc_19(fAngle, 0);
}
MS2_REPLACE_METHOD(0x1418BDBB0, UIAvatarCube, vfunc_22, 74, 0x7F20A675);

// @0x1418bdc00
void UIAvatarCube::SetItemData(CItemData* pData)
{
    m_pItemData = pData;
    AvatarCube* pCube = efd::DynamicCast<AvatarCube>(vfunc_24());
    if (pCube)
        pCube->vfunc_58(MS2Ptr<CItemData>(m_pItemData), MS2Ptr<CItem>(0));
}
MS2_REPLACE_METHOD(0x1418BDC00, UIAvatarCube, SetItemData, 209, 0x64AD802E);

// @0x1418bdce0
void UIAvatarCube::vfunc_3()
{
    UIAvatarBase::vfunc_3();
    AvatarCube* pCube = efd::DynamicCast<AvatarCube>(vfunc_24());
    if (pCube)
        pCube->FUN_141085250();
}
MS2_REPLACE_METHOD(0x1418BDCE0, UIAvatarCube, vfunc_3, 74, 0xAFF49725);

// @0x1418bdd30
void UIAvatarCube::vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg, void* pUnused)
{
    GameObject* pObj = vfunc_24();
    if (pObj)
    {
        Unk_UabPoint kPtA;
        Unk_UabPoint kPtB;
        Unk_UISwfEntity_25* pEntA = spTarget.get();
        Unk_UISwfEntity_25* pEntB = spTarget.get();
        UIRenderView* pView = CreateModelView(pEntB->vfunc_5(&kPtB)->x, pEntA->vfunc_5(&kPtA)->y, pObj, 0.9f);
        if (pView)
        {
            FUN_141ab7200(pView, TPtr<Unk_UISwfEntity_25>(spTarget), pArg);
            vfunc_21(pView);
        }
    }
}
MS2_REPLACE_METHOD(0x1418BDD30, UIAvatarCube, vfunc_28, 321, 0x8AD39274);

// @0x1418bde80
AvatarCube* UIAvatarCube::GetAvatarCube()
{
    return efd::DynamicCast<AvatarCube>(vfunc_24());
}
MS2_REPLACE_METHOD(0x1418BDE80, UIAvatarCube, GetAvatarCube, 41, 0xE9AF397A);

// @0x1418bdeb0
UIAvatarRidee::UIAvatarRidee()
    : m_pItemData(0), m_spRow(nullptr)
{
}

// @0x1418bdf30
UIAvatarRidee::UIAvatarRidee(MS2Ptr<CItemData> spData)
    : m_pItemData(spData.get()), m_spRow(nullptr)
{
    m_nKind = 3;
}

// @0x1418bdfd0
UIAvatarRidee::UIAvatarRidee(MS2SvrPtr<CRideeData> spRow)
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
        AvatarRidee* pRidee = CreateAvatarRideeFromItem(MS2Ptr<CItemData>(m_pItemData), MS2Ptr<CItem>(0));
        if (pRidee)
        {
            if (WorldService::GetInstance()->FUN_141bbb1e0(pRidee, 0, 1))
            {
                m_nObjectId = pRidee->GetObjectId();
                pRidee->SetListener(this);
            }
        }
    }
    else
    {
        if (m_spRow != 0)
        {
            AvatarRidee* pRidee = CreateAvatarRideeFromRow(m_spRow);
            if (pRidee)
            {
                if (WorldService::GetInstance()->FUN_141bbb1e0(pRidee, 0, 1))
                {
                    m_nObjectId = pRidee->GetObjectId();
                    pRidee->SetListener(this);
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
    AvatarRidee* pRidee = efd::DynamicCast<AvatarRidee>(vfunc_24());
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
    AvatarRidee* pRidee = efd::DynamicCast<AvatarRidee>(vfunc_24());
    if (pRidee)
        pRidee->vfunc_58(MS2Ptr<CItemData>(0), MS2Ptr<CItem>(0));
}
MS2_REPLACE_METHOD(0x1418BE340, UIAvatarRidee, FUN_1418be340, 195, 0x8032C0BF);

// @0x1418be410
void UIAvatarRidee::vfunc_22()
{
    float fAngle = FUN_141b48480(GetPreviewKind(GetKind()), 0);
    vfunc_19(fAngle, 0);
}
MS2_REPLACE_METHOD(0x1418BE410, UIAvatarRidee, vfunc_22, 74, 0x28660A3D);

// @0x1418be460
void UIAvatarRidee::SetItemData(CItemData* pData)
{
    m_pItemData = pData;
    m_spRow = 0;
    AvatarRidee* pRidee = efd::DynamicCast<AvatarRidee>(vfunc_24());
    if (pRidee == 0)
        vfunc_1(m_pListener);
    else
        pRidee->vfunc_58(MS2Ptr<CItemData>(m_pItemData), MS2Ptr<CItem>(0));
}
MS2_REPLACE_METHOD(0x1418BE460, UIAvatarRidee, SetItemData, 272, 0x7DA47DB9);

// @0x1418be580
void UIAvatarRidee::SetRow(MS2SvrPtr<CRideeData> spRow)
{
    m_spRow = spRow;
    m_pItemData = 0;
    AvatarRidee* pRidee = efd::DynamicCast<AvatarRidee>(vfunc_24());
    if (pRidee)
        pRidee->FUN_1409f9ea0(m_spRow);
}
MS2_REPLACE_METHOD(0x1418BE580, UIAvatarRidee, SetRow, 173, 0xEC2CAD68);

// @0x1418be640
void UIAvatarRidee::vfunc_3()
{
    UIAvatarBase::vfunc_3();
    AvatarRidee* pRidee = efd::DynamicCast<AvatarRidee>(vfunc_24());
    if (pRidee)
        pRidee->FUN_141085250();
}
MS2_REPLACE_METHOD(0x1418BE640, UIAvatarRidee, vfunc_3, 74, 0x8E78E814);

// @0x1418be690
void UIAvatarRidee::vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg, void* pUnused)
{
    GameObject* pObj = vfunc_24();
    if (pObj)
    {
        Unk_UabPoint kPtA;
        Unk_UabPoint kPtB;
        Unk_UISwfEntity_25* pEntA = spTarget.get();
        Unk_UISwfEntity_25* pEntB = spTarget.get();
        UIRenderView* pView = CreateModelView(pEntB->vfunc_5(&kPtB)->x, pEntA->vfunc_5(&kPtA)->y, pObj, 0.9f);
        if (pView)
        {
            FUN_141ab7200(pView, TPtr<Unk_UISwfEntity_25>(spTarget), pArg);
            vfunc_21(pView);
        }
    }
}
MS2_REPLACE_METHOD(0x1418BE690, UIAvatarRidee, vfunc_28, 321, 0x92186B9C);

// @0x1418be7e0
AvatarRidee* UIAvatarRidee::GetAvatarRidee()
{
    return efd::DynamicCast<AvatarRidee>(vfunc_24());
}
MS2_REPLACE_METHOD(0x1418BE7E0, UIAvatarRidee, GetAvatarRidee, 41, 0xCB75113F);

// @0x1418be810
MS2SvrPtr<CRideeData> UIAvatarRidee::GetRow()
{
    return m_spRow;
}
MS2_REPLACE_METHOD(0x1418BE810, UIAvatarRidee, GetRow, 67, 0xAA3AAE8D);

// @0x1418be860 (secondary vftable: the listener slot 4)
int UIAvatarRidee::vfunc_4(GameObject* pObj)
{
    int nRet = UIAvatarBase::vfunc_4(pObj);
    float fAngle = FUN_141b48480(GetPreviewKind(GetKind()), 0);
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
    AvatarPet* pPet = CreateAvatarPet(m_pItemData);
    if (pPet)
    {
        if (WorldService::GetInstance()->FUN_141bbb1e0(pPet, 0, 1))
        {
            m_nObjectId = pPet->GetObjectId();
            pPet->SetListener(this);
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
    float fAngle = FUN_141b48480(GetPreviewKind(GetKind()), 0);
    vfunc_19(fAngle, 0);
}
MS2_REPLACE_METHOD(0x1418BEB80, UIAvatarPet, vfunc_22, 74, 0xAE818566);

// @0x1418bebd0
void UIAvatarPet::SetItemData(CItemData* pData)
{
    m_pItemData = pData;
    AvatarPet* pPet = efd::DynamicCast<AvatarPet>(vfunc_24());
    if (pPet)
        pPet->vfunc_62(MS2Ptr<CItemData>(m_pItemData));
}
MS2_REPLACE_METHOD(0x1418BEBD0, UIAvatarPet, SetItemData, 137, 0x8EA560C1);

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
void UIAvatarPet::vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg, void* pUnused)
{
    GameObject* pObj = vfunc_24();
    if (pObj)
    {
        Unk_UabPoint kPtA;
        Unk_UabPoint kPtB;
        Unk_UISwfEntity_25* pEntA = spTarget.get();
        Unk_UISwfEntity_25* pEntB = spTarget.get();
        UIRenderView* pView = CreateModelView(pEntB->vfunc_5(&kPtB)->x, pEntA->vfunc_5(&kPtA)->y, pObj, 0.9f);
        if (pView)
        {
            FUN_141ab7200(pView, TPtr<Unk_UISwfEntity_25>(spTarget), pArg);
            vfunc_21(pView);
        }
    }
}
MS2_REPLACE_METHOD(0x1418BECB0, UIAvatarPet, vfunc_28, 321, 0xDF6EE08F);

// @0x1418bee00
AvatarPet* UIAvatarPet::GetAvatarPet()
{
    return efd::DynamicCast<AvatarPet>(vfunc_24());
}

// ---- the skin colour list ------------------------------------------------------------------------------------------


// Layout of the MS2Ptr<ItemColorEx> handle, for the exe's null test.
class Unk_UabColorElem
{
public:
    bool IsNull() const { return m_p == 0; }             // 0x1418c14b0 null test
    void* m_pad_00;
    ItemColorEx* m_p;
};

struct Unk_UabColor3 { float x; float y; float z; };
unsigned int FUN_141b6df90(struct Unk_UtilFloat3 const*);   // C3: was FUN_141b6df90
MS2_REPLACE_METHOD(0x1418BEE00, UIAvatarPet, GetAvatarPet, 41, 0x51CA81FA);

// @0x1418bee30
// MS2-FUNCTIONAL: skin colour list; stack frame / array-indexed colour reads not byte-matched
void FUN_1418bee30(ASObj* pObj, int nSkinTable)
{
    ASArray kColors(2);
    int nSelected = 0;
    Unk_BmBoxPtr<CColorPaletteInfo::ColorArray> kSet = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColors(nSkinTable);
    if (kSet.get() != 0)
    {
        size_t nCount = kSet.operator->()->GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            MS2Ptr<ItemColorEx> kElem(kSet.operator->()->GetAt(i));
            if (reinterpret_cast<const Unk_UabColorElem*>(&kElem)->IsNull())
                continue;
            ASObj kObj(2);
            kObj.FUN_1409c4990("color0", kElem.operator->()->m_aValues[0]);
            kObj.FUN_1409c4990("color1", kElem.operator->()->m_aValues[2]);
            unsigned long nColor = kElem.operator->()->m_n38;
            kObj.FUN_1409c4990("realColor", nColor);
            kObj.FUN_1409c4990("visibleColor", nColor);
            kColors.PushValue(Scaleform::GFx::Value(kObj.GetValue()));
        }
    }
    PCBase* pPlayer = ((PCBase*)WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer)
    {
        ASObj kObj(2);
        unsigned long nColor0 = FUN_141b6df90((struct Unk_UtilFloat3 const*)(((struct Unk_UabColor3 const*)&((class PC*)(class PCBase*)(pPlayer))->FUN_141659220(0))));
        kObj.FUN_1409c4990("color0", nColor0);
        kObj.FUN_1409c4990("color1", FUN_141b6df90((struct Unk_UtilFloat3 const*)(((struct Unk_UabColor3 const*)&((class PC*)(class PCBase*)(pPlayer))->FUN_141659220(1)))));
        unsigned long nColor = nColor0;
        kObj.FUN_1409c4990("realColor", nColor);
        kObj.FUN_1409c4990("visibleColor", nColor);
        kColors.PushValue(Scaleform::GFx::Value(kObj.GetValue()));
    }
    pObj->FUN_1409adbe0("skinColors", Scaleform::GFx::Value(kColors.GetValue()));
    pObj->SetIntMember("skinColorSelectedIndex", nSelected);
}

// ---- angle wraps --------------------------------------------------------------------------------------------------

// @0x1418bf1e0
void NormalizeAngles(Vector3* pAngles)
{
    NormalizeAngle(&pAngles->x);
    NormalizeAngle(&pAngles->y);
    NormalizeAngle(&pAngles->z);
}

// @0x1418bf230
void FUN_1418bf230(float* pX, float* pY, float* pZ)
{
    NormalizeAngle(pX);
    NormalizeAngle(pY);
    NormalizeAngle(pZ);
}

// @0x1418bf270
void NormalizeAngle(float* pAngle)
{
    if (*pAngle < 0.0f)
        *pAngle = *pAngle + 360.0f;
    else if (360.0f < *pAngle)
        *pAngle = *pAngle - 360.0f;
}

// @0x1418bf2e0
void NormalizeAngleInt(int* pAngle)
{
    if (*pAngle < 0)
        *pAngle = *pAngle + 360;
    else if (360 < *pAngle)
        *pAngle = *pAngle - 360;
}

// @0x1418bf330
void FUN_1418bf330(Vector3* pAngles)
{
    WrapAngleRadians(&pAngles->x);
    WrapAngleRadians(&pAngles->y);
    WrapAngleRadians(&pAngles->z);
}

// @0x1418bf380
void FUN_1418bf380(float* pX, float* pY, float* pZ)
{
    WrapAngleRadians(pX);
    WrapAngleRadians(pY);
    WrapAngleRadians(pZ);
}

// @0x1418bf3c0
void WrapAngleRadians(float* pAngle)
{
    if (*pAngle < 0.0f)
        *pAngle = *pAngle + 6.2831855f;
    else if (6.2831855f < *pAngle)
        *pAngle = *pAngle - 6.2831855f;
}

// ---- the cube item set drop walk ----------------------------------------------------------------------------------

MS2Ptr<CItemData> FUN_14053f870(int nItemId);

bool FUN_1418bf500(int nDepth, MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems, ATL::CAtlArray<MS2Ptr<CItemData> >* pOthers);

// @0x1418bf430
bool FUN_1418bf430(MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems, ATL::CAtlArray<MS2Ptr<CItemData> >* pOthers)
{
    if (spData == 0)
        return false;
    int nDepth = 0;
    FUN_1418bf500(nDepth, spData, pItems, pOthers);
    return !((ATL::CAtlArray<MS2Ptr<CItemData>, ATL::CElementTraits<MS2Ptr<CItemData>>>*)(void*)(pItems))->IsEmpty();
}

// @0x1418bf500
bool FUN_1418bf500(int nDepth, MS2Ptr<CItemData> spData, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems, ATL::CAtlArray<MS2Ptr<CItemData> >* pOthers)
{
    if (nDepth > 3)
        return false;
    ++nDepth;
    if (spData == 0)
        return false;
    int nItemId = spData->GetItemId();
    int nGroup = ((struct ItemFunction*)(void*)(&spData->function.name))->FUN_14054a460();
    if (nGroup == 0)
        return false;
    std::vector<ItemDropResult> kDrops;
    TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(nGroup, kDrops);
    std::vector<ItemDropResult>::iterator it = kDrops.begin();
    ATL::CAtlMap<int, MS2Ptr<CItemData> > kUnused;
    for (; it != kDrops.end(); ++it)
    {
        ItemDropResult kDrop = *it;
        if (nItemId == kDrop.m_itemId)
            continue;
        MS2Ptr<CItemData> spItem = FUN_14053f870(kDrop.m_itemId);
        if (!spItem)
            continue;
        if (((class CItemData*)(class CItemData*)(spItem.operator->()))->GetType() != 0x19)
        {
            if (((class CItemData*)(class CItemData*)(spItem.operator->()))->FUN_14053cbc0())
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
void FUN_1418bf800(unsigned nKey, Unk_AvPackageKey* pOut)
{
    int nZero = 0;
    *pOut = Unk_AvPackageKey(nKey, nZero);
}

// A merat equip entry (asequipicon.h forward declares it): +0x28 the state, +0x48 the id.
class Unk_MeratEquipEntry : public CPtred
{
public:
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
    if (reinterpret_cast<CMeratMarketProduct*>(spEntry.operator->())->IsUgc() != 0)
        return;
    if (reinterpret_cast<CMeratMarketProduct*>(spEntry.operator->())->IsPremium() != 0)
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
bool CAvatarPackageEquip::IsEmpty()
{
    return m_mapItems.IsEmpty();
}
MS2_REPLACE_METHOD(0x1418BFCC0, CAvatarPackageEquip, IsEmpty, 31, 0xABDCEF43);

// @0x1418bffd0
float FUN_1418bffd0(Common::Constants::Value<int>* pValue)
{
    return (float)*pValue->Get();
}

// @0x1418c0f00
std::pair<std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> >::iterator, bool> Unk_AvPackageMapView::FUN_1418c0f00(Unk_AvPackagePair&& kPair)
{
    return _Insert_nohint(false, std::move(kPair), std::_Not_a_node_tag());
}

// @0x1418c1410
// (implicit: the compiler-generated dtor, see the header)

// @0x1418c1dd0
// Writes the node's local transform inline: m_kLocal.m_Rotate (+0x50) = *pRot, m_kLocal.m_Translate (+0x74) =
// kPos + kPivot - *pRot * kPivot.
void FUN_1418c1dd0(NiAVObject* pNode, Unk_NiMatrix3* pRot, const Unk_NiPoint3& kPivot, const Unk_NiPoint3& kPos)
{
    *reinterpret_cast<Unk_NiMatrix3*>(reinterpret_cast<char*>(pNode) + 0x50) = *pRot;
    *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(pNode) + 0x74) = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(
        reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(
        (reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(kPos) + reinterpret_cast<const efd::Point3&>(kPivot))) - reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Matrix3&>(*pRot) * reinterpret_cast<const efd::Point3&>(kPivot))))
))));
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbc950-0x142cbca30 .text$yd
