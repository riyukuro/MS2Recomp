// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CCapRotationController, the customize controller of the
// cap (hat) rotation gizmo. Unit ?\caprotationcontroller.cpp (0x140b00540-0x140b03040): the controller, the MS2Ptr /
// std::set<NiAVObjectPtr> glue it instantiates first, and the CItemCustomizeController inline virtuals (vftable
// 0x142f0f790 slots that nobody else emits, see itemcustomizecontroller_1.h).
// MS2-UNIT: ?\caprotationcontroller.cpp
// MS2-RANGE: 0x140b00540-0x140b03040 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_37@CItemCustomizeController@@UEAAXXZ 0x140b02be0 ; unique
// MS2-PIN: ?vfunc_18@CItemCustomizeController@@UEAAMXZ 0x140b02bf0 ; unique
// MS2-PIN: ?vfunc_27@CItemCustomizeController@@UEAAHXZ 0x140b02c00 ; unique
// MS2-PIN: ?vfunc_40@CItemCustomizeController@@UEAAMXZ 0x140b02c10 ; unique
// MS2-PIN: ?vfunc_17@CItemCustomizeController@@UEAAHXZ 0x140b02c20 ; unique
// MS2-PIN: ?vfunc_21@CItemCustomizeController@@UEAAMXZ 0x140b02c40 ; unique
// MS2-PIN: ?vfunc_22@CItemCustomizeController@@UEAAMH@Z 0x140b02c60 ; unique
// MS2-PIN: ?vfunc_20@CItemCustomizeController@@UEAAMXZ 0x140b02cc0 ; unique
// MS2-PIN: ?vfunc_19@CItemCustomizeController@@UEAAMXZ 0x140b02cd0 ; unique
// MS2-PIN: ?vfunc_25@CItemCustomizeController@@UEAAXPEAM0@Z 0x140b02ce0 ; unique
// MS2-PIN: ?vfunc_26@CItemCustomizeController@@UEAAXHPEAM0@Z 0x140b02d10 ; unique
// MS2-PIN: ?vfunc_5@CItemCustomizeController@@UEAAXXZ 0x140b02d50 ; unique
// MS2-PIN: ?vfunc_14@CItemCustomizeController@@UEAAXM@Z 0x140b02d70 ; unique
// MS2-PIN: ?vfunc_15@CItemCustomizeController@@UEAAXHM@Z 0x140b02d80 ; unique
// MS2-PIN: ?vfunc_10@CItemCustomizeController@@UEAAXM@Z 0x140b02db0 ; unique
// MS2-PIN: ?vfunc_9@CItemCustomizeController@@UEAAXH@Z 0x140b02dc0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@2@XZ 0x140b02e90 ; unique
// MS2-PIN: ??8?$MS2Ptr@UUnk_PickTarget@@@@QEBA_NPEAUUnk_PickTarget@@@Z 0x140b02970 ; manual (identical group)
// MS2-PIN: ??C?$MS2Ptr@UUnk_PickTarget@@@@QEBAPEAUUnk_PickTarget@@XZ 0x140b02a50 ; manual (identical group)
// MS2-PIN: ?GetRTTI@CCapRotationController@@UEBAPEBVNiRTTI@@XZ 0x140b02c30 ; manual
// MS2-PIN: ?vfunc_16@CItemCustomizeController@@UEAAXXZ 0x140b02d60 ; manual (vftable slot 16)
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\caprotationcontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "caprotationcontroller.h"
#include "ms2/placeholder/citem.h"
#include <efd/MemObject.h>
#include <NiMesh.h>
#include <NiTransform.h>
#include <NiFixedString.h>
#include <set>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- exe data ----
extern Vector3 DAT_143b01a60;       // the zero point
extern Unk_EfdMatrix3 DAT_143a09600;        // the identity matrix
extern Vector3 DAT_143a08cf8;       // the up axis
struct Unk_PickXY { float x, y; };          // cursor position
extern Unk_PickXY DAT_143b02320;            // initial value of the cursor position

// ---- unit-local views of exe objects ----

// 3-float point whose default ctor is the efd::Point3 one (0x1405522f0); used for the camera ray.
struct Unk_GVec3 : public Vector3
{
    Unk_GVec3();                                                // 0x1405522f0
};

// The item data of the equipped cap (?\itemdatastruct.cpp); only the flags this unit reads.
struct Unk_CapItemData
{
    unsigned char FUN_140547130();                              // customizing allowed
    unsigned char FUN_140547150();                              // right button allowed
    char FUN_1405471b0();                                       // the item is a rotatable cap
};
struct Unk_CapItem
{
    Unk_CapItemData* FUN_14053ec70();                           // item -> its data
    int FUN_14053c620();                                        // item kind (0xd = cap)
};

// The model record of the cap item (CItem::FUN_140527870); only the three fields this unit writes.
struct Unk_CapModelData
{
    char m_pad_00[0x58];
    float m_fScale;                                             // +0x58 world scale of the cap node
    char m_pad_5c[0x18];
    Vector3 m_kOffset;                                  // +0x74 world offset of the cap node
    Vector3 m_kEuler;                                   // +0x80 euler angles (degrees) of the cap
};
MS2_CHECK_SIZE(Unk_CapModelData, 0x8c);

// The model facts of the part: euler limits sit at +0x70 / +0x7c.
struct Unk_CapPartInfo
{
    char m_pad_00[0x70];
    Vector3 m_kMin;                                     // +0x70
    Vector3 m_kMax;                                     // +0x7c
};
MS2_CHECK_SIZE(Unk_CapPartInfo, 0x88);

class CEquipItem : public CPtred
{
public:
    Unk_CapItem* FUN_1411dc7f0();                               // the item
    MS2Ptr<CItem> GetItem();                              // the item object holding the model record
    void FUN_1411dca30(int nSlot, CAtlArray<CString>& aParts);  // attach part names of an equip slot
    MS2Ptr<Unk_PickTarget> FUN_1411dc950(const CString& strPart);   // the model of one part
};

struct Unk_CapEntityKey { unsigned __int64 m_id; };

// The local player (virtual slot 20 returns its rotation in degrees).
class Unk_CapPlayer
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual Vector3 vfunc_20();                         // rotation (x, y, z degrees)
    Unk_CapEntityKey& FUN_14123c460(Unk_CapEntityKey& kOut);    // the entity key
    float FUN_14123c260();                                      // model scale
};
struct Unk_CapWorld { Unk_CapPlayer* FUN_141bd0cc0(); };        // the local player
Unk_CapWorld* FUN_1403ed2d0();
void* FUN_1416561a0(Unk_CapPlayer* pPlayer);                    // the player's customize state
void FUN_1411e5c10(void* pState);                               // applies the customization

struct Unk_CapEntityLoader
{
    void* FUN_140999440(const Unk_CapEntityKey& kEntity);       // the entity's loaded scene, NULL while loading
};
Unk_CapEntityLoader* FUN_141b6f910();

struct Unk_CapCursor { int FUN_141b90e30(float* pX, float* pY); };   // cursor position in pixels
Unk_CapCursor* FUN_140aadf80();

struct Unk_CapCamera
{
    int FUN_140a18070();                                        // camera ready
    char FUN_140af0520(const Unk_PickXY& kCursor, Vector3* pOrigin, Vector3* pDir);   // cursor ray
};
Unk_CapCamera* FUN_1409478c0();

struct Unk_CapInput { char FUN_14116d950(int nKey, int nA, int nB); };   // key state
Unk_CapInput* FUN_14025e7c0();

float FUN_140a17940(float fValue, float fMin, float fMax);      // clamp
float FUN_140a34650(float fCos);                                // acos
void FUN_140968990(Unk_NiPoint3* p);                            // efd::Point3::Unitize
void FUN_142084020(Unk_EfdMatrix3* p, float fY, float fX, float fZ);   // efd::Matrix3::FromEulerAnglesYXZ
void FUN_140a33310(void* pQuat);                                // efd::Quaternion::Quaternion()
void FUN_14209bc90(void* pQuat, float fAngle, const Vector3* pAxis);   // efd::Quaternion::FromAngleAxis
void FUN_140a34450(const void* pQuat, Unk_EfdMatrix3* pMat);   // efd::Quaternion::ToRotation
char FUN_14147aa60(const Vector3& kOrigin, const Vector3& kDir, const Vector3& kCenter,
                   float fRadius, Vector3* pHit);       // ray / sphere hit
void FUN_141422950(const NiTransform& kXf, Vector3* pEuler);   // transform -> euler angles (degrees)
void FUN_140aacaa0(NiAVObject* pNode, const NiTransform& kXf);  // sets the node's transform
NiTransform* FUN_140a33f90(NiAVObject* pNode);                  // the node's transform
NiTransform* FUN_140a33de0(const NiTransform* pThis, void* pOut, const NiTransform* pOther);   // NiTransform::operator*
void FUN_140aacb60(NiAVObject* pNode, const NiTransform* pXf);  // sets the node's local transform
void FUN_14097fad0(NiPoint3* pDst, const NiPoint3* pSrc);       // NiPoint3 assignment
// efd::Matrix3::Inverse() (0x1420845e0): a member that returns the matrix by value.
struct Unk_CapMatrix : public Unk_EfdMatrix3 { Unk_EfdMatrix3 FUN_1420845e0() const; };
const NiFixedString& FUN_1409a8b90(NiAVObject* pNode);          // node name
const Vector3& FUN_140947900(NiAVObject* pNode);        // world translate
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);   // dynamic cast (NULL-safe)

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class). Next(bDescend) yields the next NiAVObject.
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);

// The loaded meshes of a part model: a std::set<NiAVObjectPtr> (equipmodel.h).
typedef std::set<NiAVObjectPtr> Unk_MeshSet;
Unk_MeshSet* FUN_141201c90(Unk_PickTarget* pPart);

// Listener at +0xa0: slots 1, 3 and 5 are called by the controller (the base class only knows slot 0).
class Unk_CapListener : public Unk_ItemCustomizeListener
{
public:
    virtual void vfunc_1(CItemCustomizeController* pController) = 0;
    virtual void vfunc_2() = 0;
    virtual void vfunc_3(CItemCustomizeController* pController, float fValue) = 0;
    virtual void vfunc_4() = 0;
    virtual void vfunc_5(CItemCustomizeController* pController, Unk_PickTarget* pPart) = 0;
};

// The RTTI of the class is created by a static initializer outside this unit (0x143ab9d08).

// @0x140b00540
CCapRotationController::CCapRotationController()
    : m_spMesh(0)
    , m_spPart(0)
    , m_fSpeed(0.5f)
    , m_fRadius(0.0f)
    , m_kDragDir(DAT_143b01a60)
    , m_kMinEuler(DAT_143b01a60)
    , m_kMaxEuler(DAT_143b01a60)
    , m_kCurEuler(DAT_143b01a60)
    , m_kInitEuler(DAT_143b01a60)
    , m_kInitRot(DAT_143a09600)
{
    m_bUseButton2 = 1;
}

// @0x140b006a0
CCapRotationController::~CCapRotationController()
{
    m_spMesh = 0;
    m_spPart = 0;
}

// @0x140b00730
int CCapRotationController::vfunc_3()
{
    if (InitPart() == 0)
        return 0;
    Unk_CapItem* pItem = m_spEquipItem->FUN_1411dc7f0();
    if (pItem == 0)
        return 0;
    ResetHighlight();
    Unk_CapItemData* pData = pItem->FUN_14053ec70();
    m_bUseButton1 = 1;
    m_bUseButton2 = pData->FUN_140547150();
    m_bEnabled = pData->FUN_140547130();
    return 1;
}

// @0x140b007e0
void CCapRotationController::vfunc_6()
{
    SetPartEuler(m_kInitEuler);
}

// @0x140b00830
int CCapRotationController::vfunc_29()
{
    Unk_CapPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    CAtlArray<CString> aParts;
    m_spEquipItem->FUN_1411dca30(m_nSlot, aParts);
    m_spPicker->ClearTargets();
    if (aParts.GetCount() > 0)
    {
        MS2Ptr<Unk_PickTarget> spPart = m_spEquipItem->FUN_1411dc950(aParts.GetAt(0));
        m_spPicker->AddTarget(spPart.get());
    }
    return 1;
}

// @0x140b00960
// MS2-FUNCTIONAL: local/temp layout differs from exe (frame size, CString temps); behavior equivalent
void CCapRotationController::vfunc_28()
{
    Unk_CapItem* pItem = m_spEquipItem->FUN_1411dc7f0();
    if (pItem != 0)
    {
        Unk_CapItemData* pData = pItem->FUN_14053ec70();
        if (pData->FUN_1405471b0() != 0)
        {
            m_aPartNames.RemoveAll();
            m_aPartNames.Add(CString("CP"));
            m_aPartNames.Add(CString("CP:0"));
            m_aPartNames.Add(CString("CP:1"));
            m_aPartNames.Add(CString("CP:2"));
            m_aPartNames.Add(CString("CPA:0"));
            m_aPartNames.Add(CString("Editable Mesh"));
            m_aMeshNames.RemoveAll();
            m_aMeshNames.Add(CString("HR"));
            m_aMeshNames.Add(CString("HR1"));
            m_aMeshNames.Add(CString("HR2"));
            m_aMeshNames.Add(CString("HR:0"));
            m_aMeshNames.Add(CString("HR:1"));
            m_aMeshNames.Add(CString("HR:2"));
            m_aMeshNames.Add(CString("HR0:0"));
            m_aMeshNames.Add(CString("HR1:1"));
        }
    }
}

// @0x140b00d30
// MS2-FUNCTIONAL: local/temp layout differs from exe (frame size, CString temps); behavior equivalent
void CCapRotationController::vfunc_30(const NiPoint3& kPos)
{
    if (m_spMesh)
    {
        Unk_CapPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
        {
            Unk_EfdMatrix3 kRotZ;
            kRotZ.FUN_142084c10((pPlayer->vfunc_20().z * 3.1415927f) / 180.0f);
            Vector3 kPoint = reinterpret_cast<const Vector3&>(kPos);
            m_kDragDir = kPoint.FUN_140965c40(FUN_140947900(m_spMesh.operator->()));
            m_fRadius = m_kDragDir.FUN_140968990();
            m_kDragDir = kRotZ.FUN_140a00720(m_kDragDir);
            m_kCurEuler = GetPartEuler();
            if (m_pListener != 0)
                static_cast<Unk_CapListener*>(m_pListener)->vfunc_1(this);
        }
    }
}

// @0x140b00f20
// MS2-FUNCTIONAL: local/temp layout differs from exe (frame size, CString temps); behavior equivalent
void CCapRotationController::vfunc_31()
{
    if (m_spMesh)
    {
        Unk_CapPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
        {
            Unk_PickXY kCursor = DAT_143b02320;
            if (FUN_140aadf80()->FUN_141b90e30(&kCursor.x, &kCursor.y) != 0)
            {
                if (FUN_1409478c0()->FUN_140a18070() != 0)
                {
                    Unk_GVec3 kOrigin;
                    Unk_GVec3 kDir;
                    if (FUN_1409478c0()->FUN_140af0520(kCursor, &kOrigin, &kDir) != 0)
                    {
                        Unk_GVec3 kHit;
                        const Vector3& kCenter = FUN_140947900(m_spMesh.operator->());
                        FUN_14147aa60(kOrigin, kDir, kCenter, m_fRadius, &kHit);
                        Vector3 kDelta = kHit.FUN_140965c40(FUN_140947900(m_spMesh.operator->()));
                        kDelta.FUN_140968990();
                        Unk_EfdMatrix3 kRotZ;
                        kRotZ.FUN_142084c10((pPlayer->vfunc_20().z * 3.1415927f) / 180.0f);
                        kDelta = kRotZ.FUN_140a00720(kDelta);
                        Vector3 kAxis = m_kDragDir.FUN_140a00e10(kDelta);
                        kAxis.FUN_140968990();
                        float fAngle = SafeAcos(m_kDragDir.FUN_140a00f20(kDelta));
                        char kQuat[16];
                        FUN_140a33310(kQuat);
                        FUN_14209bc90(kQuat, fAngle, &kAxis);
                        Unk_EfdMatrix3 kRot;
                        FUN_140a34450(kQuat, &kRot);
                        kRot = kRot.FUN_140a33480(m_kInitRot);
                        Vector3 kEuler;
                        kRot.FUN_142085840(kEuler.x, kEuler.y, kEuler.z);
                        kEuler.x = WrapAngle((kEuler.x * 180.0f) / 3.1415927f, m_kMinEuler.x, m_kMaxEuler.x);
                        kEuler.y = WrapAngle((kEuler.y * 180.0f) / 3.1415927f, m_kMinEuler.y, m_kMaxEuler.y);
                        kEuler.z = m_kCurEuler.z;
                        SetPartEuler(kEuler);
                    }
                }
            }
        }
    }
}

// @0x140b01310
// MS2-FUNCTIONAL: local/temp layout differs from exe (frame size, CString temps); behavior equivalent
void CCapRotationController::vfunc_32(const NiPoint3& kHit, const NiPoint3& kNormal, const NiPoint2& kUV, float fValue)
{
    Unk_CapPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    Unk_CapEntityLoader* pLoader;
    if (pPlayer != 0 && !(m_spPart == (Unk_PickTarget*)0) && (pLoader = FUN_141b6f910()) != 0)
    {
        Unk_CapEntityKey kKey;
        void* pScene = pLoader->FUN_140999440(pPlayer->FUN_14123c460(kKey));
        if (pScene != 0)
        {
            Unk_CapModelData* pData = reinterpret_cast<Unk_CapModelData*>(
                m_spEquipItem->GetItem()->FUN_140527870());
            if (pData != 0)
            {
                Unk_CapItem* pItem = m_spEquipItem->FUN_1411dc7f0();
                if (pItem != 0)
                {
                    if (pItem->FUN_14053ec70()->FUN_1405471b0() != 0)
                    {
                        if (FUN_14025e7c0()->FUN_14116d950(0x1d, 0, 0) == 0)
                        {
                            Vector3 kN = reinterpret_cast<const Vector3&>(kNormal);
                            kN.FUN_140968990();
                            Vector3 kSide = kN.FUN_140a00e10(DAT_143a08cf8).FUN_1409f7960();
                            kSide.FUN_140968990();
                            Unk_NiPoint3 kUp(kN.FUN_140a00e10(kSide));
                            FUN_140968990(&kUp);
                            Unk_NiMatrix3 kFix;
                            FUN_142084020(&kFix, 1.5707964f, 3.1415927f, 0.0f);
                            NiTransform kXf;
                            kXf.m_fScale = pPlayer->FUN_14123c260();
                            Unk_NiMatrix3 kBasis(Unk_NiPoint3(kN), Unk_NiPoint3(kSide), kUp);
                            Unk_NiMatrix3 kRot(kBasis.FUN_140a33480(kFix));
                            reinterpret_cast<Unk_NiMatrix3&>(kXf.m_Rotate) = kRot;
                            FUN_14097fad0(&kXf.m_Translate, &kHit);
                            Unk_MeshSet* pSet = FUN_141201c90(m_spPart.operator->());
                            Unk_MeshSet::const_iterator itEnd = pSet->end();
                            Unk_MeshSet::const_iterator it = pSet->begin();
                            while (it != itEnd)
                            {
                                NiAVObjectPtr spNode(*it);
                                FUN_140aacaa0(spNode.operator->(), kXf);
                                spNode.operator->()->UpdateWorldData();
                                NiTransform kWorld = *FUN_140a33f90(spNode.operator->());
                                pData->m_fScale = kWorld.m_fScale;
                                pData->m_kOffset = reinterpret_cast<const Vector3&>(kWorld.m_Translate);
                                FUN_141422950(kWorld, &pData->m_kEuler);
                                m_spPart->FUN_141200160(pData->m_kOffset);
                                m_spPart->FUN_141200100(pData->m_kEuler);
                                ++it;
                            }
                        }
                        else
                        {
                            vfunc_31();
                        }
                    }
                }
            }
        }
    }
}

// @0x140b01870
void CCapRotationController::vfunc_33()
{
    UpdateRotationMatrix();
    Unk_CapPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
        FUN_1411e5c10(FUN_1416561a0(pPlayer));
    if (m_pListener != 0)
        static_cast<Unk_CapListener*>(m_pListener)->vfunc_5(this, m_spPart.get());
}

// @0x140b01920
void CCapRotationController::vfunc_34(const NiPoint3& kPos)
{
    FUN_140aadf80()->FUN_141b90e30(&m_kDragStart.x, &m_kDragStart.y);
    m_kCurEuler = GetPartEuler();
}

// @0x140b019a0
// MS2-FUNCTIONAL: local/temp layout differs from exe (frame size, CString temps); behavior equivalent
void CCapRotationController::vfunc_35()
{
    Unk_CapPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        Unk_PickXY kCursor = DAT_143b02320;
        if (FUN_140aadf80()->FUN_141b90e30(&kCursor.x, &kCursor.y) != 0)
        {
            if (FUN_1409478c0()->FUN_140a18070() != 0)
            {
                Unk_GVec3 kOrigin;
                Unk_GVec3 kDir;
                if (FUN_1409478c0()->FUN_140af0520(kCursor, &kOrigin, &kDir) != 0)
                {
                    float fDelta = (m_kDragStart.x - kCursor.x) * m_fSpeed;
                    float fYaw = m_kCurEuler.z + fDelta;
                    float fWrapped = WrapAngle(fYaw, m_kMinEuler.z, m_kMaxEuler.z);
                    Vector3 kEuler(m_kCurEuler.x, m_kCurEuler.y, fWrapped);
                    SetPartEuler(kEuler);
                    if (m_pListener != 0)
                        static_cast<Unk_CapListener*>(m_pListener)->vfunc_3(this, fYaw);
                }
            }
        }
    }
}

// @0x140b01b80
void CCapRotationController::vfunc_36()
{
    UpdateRotationMatrix();
}

// @0x140b01bb0
// MS2-FUNCTIONAL: local/temp layout differs from exe (frame size, CString temps); behavior equivalent
int CCapRotationController::InitPart()
{
    if (!m_spEquipItem)
        return 0;
    CAtlArray<CString> aParts;
    m_spEquipItem->FUN_1411dca30(m_nSlot, aParts);
    if (aParts.IsEmpty())
        return 0;
    m_spPart = m_spEquipItem->FUN_1411dc950(aParts.GetAt(0));
    if (m_spPart == (Unk_PickTarget*)0)
        return 0;
    const Unk_CapPartInfo* pInfo = reinterpret_cast<const Unk_CapPartInfo*>(m_spPart->FUN_141200ab0());
    m_kMinEuler = pInfo->m_kMin;
    m_kMaxEuler = reinterpret_cast<const Unk_CapPartInfo*>(m_spPart->FUN_141200ab0())->m_kMax;
    Unk_MeshSet* pSet = FUN_141201c90(m_spPart.operator->());
    Unk_MeshSet::const_iterator itEnd = pSet->end();
    Unk_MeshSet::const_iterator it = pSet->begin();
    while (it != itEnd)
    {
        NiAVObjectPtr spNode(*it);
        Unk_SceneWalker walker(spNode.operator NiAVObject*());
        NiAVObject* pObject;
        while ((pObject = walker.Next(true)) != 0)
        {
            NiMesh* pMesh = (NiMesh*)FUN_14098d8d0(&NiMesh::ms_RTTI, pObject);
            if (pMesh != 0)
                m_spMesh = pMesh;
        }
        ++it;
    }
    if (m_spMesh == 0)
        return 0;
    m_kInitEuler = UpdateRotationMatrix();
    m_aPartNames.RemoveAll();
    m_aPartNames.Add(CString((const char*)FUN_1409a8b90(m_spMesh.operator->())));
    return 1;
}

// @0x140b01fa0
void CCapRotationController::ResetHighlight()
{
    if (m_spMesh == 0)
        return;
    CAtlArray<CString> aParts;
    m_spEquipItem->FUN_1411dca30(m_nSlot, aParts);
    if (aParts.IsEmpty())
        return;
    Unk_PickTarget* pPart = m_spEquipItem->FUN_1411dc950(aParts.GetAt(0)).get();
    if (pPart != 0)
        pPart->FUN_1411679d0(0.0f, 0.0f, 0);
}

// @0x140b020d0
Vector3 CCapRotationController::UpdateRotationMatrix()
{
    Vector3 kEuler = GetPartEuler();
    m_kInitRot.FUN_142083d40((kEuler.x * 3.1415927f) / 180.0f, (kEuler.y * 3.1415927f) / 180.0f,
                             (kEuler.z * 3.1415927f) / 180.0f);
    return kEuler;
}

// @0x140b02180
// MS2-FUNCTIONAL: struct-return copy / temp layout differs (imul copy)
Vector3 CCapRotationController::GetPartEuler()
{
    MS2Ptr<CEquipItem> spItem = m_spPart->FUN_141200a40();
    if (spItem == (CEquipItem*)0)
        return DAT_143b01a60;
    if (spItem->FUN_1411dc7f0()->FUN_14053c620() != 0xd)
        return DAT_143b01a60;
    Unk_CapModelData* pData = reinterpret_cast<Unk_CapModelData*>(spItem->GetItem()->FUN_140527870());
    if (pData == 0)
        return DAT_143b01a60;
    return pData->m_kEuler;
}

// @0x140b02310
// MS2-FUNCTIONAL: struct-return copy / temp layout differs (imul copy)
void CCapRotationController::SetPartEuler(Vector3 kEuler)
{
    MS2Ptr<CEquipItem> spItem = m_spPart->FUN_141200a40();
    if (!(spItem == (CEquipItem*)0))
    {
        if (spItem->FUN_1411dc7f0()->FUN_14053c620() == 0xd)
        {
            Unk_CapModelData* pData = reinterpret_cast<Unk_CapModelData*>(spItem->GetItem()->FUN_140527870());
            if (pData != 0)
            {
                Vector3 kCur = pData->m_kEuler;
                Unk_NiMatrix3 kNew;
                Unk_NiMatrix3 kOld;
                float fNewX = (kEuler.x * 3.1415927f) / 180.0f;
                kNew.FUN_142083d40(fNewX, (kEuler.y * 3.1415927f) / 180.0f, (kEuler.z * 3.1415927f) / 180.0f);
                float fOldX = (kCur.x * 3.1415927f) / 180.0f;
                kOld.FUN_142083d40(fOldX, (kCur.y * 3.1415927f) / 180.0f, (kCur.z * 3.1415927f) / 180.0f);
                NiTransform kDelta;
                kDelta.MakeIdentity();
                reinterpret_cast<Unk_NiMatrix3&>(kDelta.m_Rotate) =
                    Unk_NiMatrix3(reinterpret_cast<const Unk_CapMatrix&>(kOld).FUN_1420845e0().FUN_140a33480(kNew));
                Unk_MeshSet* pSet = FUN_141201c90(m_spPart.operator->());
                Unk_MeshSet::const_iterator itEnd = pSet->end();
                Unk_MeshSet::const_iterator it = pSet->begin();
                while (it != itEnd)
                {
                    NiAVObjectPtr spNode(*it);
                    alignas(8) char kTmp[sizeof(NiTransform)];
                    NiTransform* pCombined = FUN_140a33de0(FUN_140a33f90(spNode.operator->()), kTmp, &kDelta);
                    FUN_140aacb60(spNode.operator->(), pCombined);
                    ++it;
                }
                m_spPart->FUN_141200100(kEuler);
                pData->m_kEuler = kEuler;
            }
        }
    }
}

// @0x140b02730
float CCapRotationController::WrapAngle(float fDegrees, float fMin, float fMax)
{
    if (fDegrees < -180.0f)
        fDegrees += 360.0f;
    else if (fDegrees > 180.0f)
        fDegrees -= 360.0f;
    return FUN_140a17940(fDegrees, fMin, fMax);
}

// @0x140b02b90
float CCapRotationController::SafeAcos(float fCos)
{
    if (-1.0f < fCos)
    {
        if (fCos < 1.0f)
            return FUN_140a34650(fCos);
        else
            return 0.0f;
    }
    else
    {
        return 3.1415927f;
    }
}

MS2_REPLACE_METHOD(0x140b00730, CCapRotationController, vfunc_3, 158, 0x277C7D13);
MS2_REPLACE_METHOD(0x140b007e0, CCapRotationController, vfunc_6, 60, 0x208A7CE6);
MS2_REPLACE_METHOD(0x140b00830, CCapRotationController, vfunc_29, 297, 0xA43FDCA1);
MS2_REPLACE_METHOD(0x140b01870, CCapRotationController, vfunc_33, 168, 0x366268CD);
MS2_REPLACE_METHOD(0x140b01920, CCapRotationController, vfunc_34, 116, 0xFF52E400);
MS2_REPLACE_METHOD(0x140b01b80, CCapRotationController, vfunc_36, 29, 0x19792AB8);
MS2_REPLACE_METHOD(0x140b01fa0, CCapRotationController, ResetHighlight, 285, 0x4EBD6AA5);
