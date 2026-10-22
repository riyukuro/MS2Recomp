// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMouseController: click-to-move / click-to-interact mouse control,
// plus the CMouseInteract subclasses' ctors, dtors and vfunc_6.
// MS2-UNIT: unit_140ad1860
// MS2-RANGE: 0x140ad1860-0x140ad5280 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VCMouseInteract@@@@QEAA@PEAVCMouseInteract@@@Z 0x140ad42c0 ; unique
// MS2-PIN: ??0CMouseInteractPortal@@QEAA@XZ 0x140ad43b0 ; prop
// MS2-PIN: ??0CMouseInteractTalkCancel@@QEAA@XZ 0x140ad43e0 ; unique
// MS2-PIN: ??0CMouseInteractWeaponObject@@QEAA@XZ 0x140ad4410 ; prop
// MS2-PIN: ?FUN_140ad4b30@CCameraMode@@QEAAMXZ 0x140ad4b30 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCMouseInteract@@@@AEBAXPEAX@Z 0x140ad50a0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?get@?$MS2Ptr@VCMouseInteract@@@@QEBAPEAVCMouseInteract@@XZ 0x140ad4760 ; manual
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_140ad1860.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/cameramode.h"
#include "ms2/client/ms2/targetlookcentercameramode.h"
#include "ms2/client/ms2/physxhelper.h"
#include <NiAVObject.h>
#include <ecr/SceneGraphService.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local stand-ins and unrecovered callees (names invented from use) ----------------------------------------------
extern Unk_StreamPoint DAT_143b01a60;                           // the zero point
extern unsigned DAT_143af62d4;                                  // client area width
extern unsigned DAT_143af62d8;                                  // client area height
extern RECT g_rcWindow;                                         // 0x143af7d48: last GetWindowRect of the game window
extern ecr::SceneGraphService* DAT_143ab9508;
class Unk_McEntityRules;
extern Unk_McEntityRules* DAT_143ab9510;
extern char DAT_143b059e8;                                      // service lookup cell

// Reference counted service objects: AddRef / Release are the first virtuals after the destructor.
class Unk_McRefObj
{
public:
    virtual ~Unk_McRefObj();
    virtual void vfunc_1();                                     // MS2: slot 1 AddRef
    virtual void vfunc_2();                                     // MS2: slot 2 Release
};

// Settings (feature flags) and input.
class Unk_McOptions { public: bool FUN_14036d570(int nId); };
Unk_McOptions* FUN_140166410();

class Unk_McCursor
{
public:
    int FUN_1422cef10();                                        // cursor kind
    void FUN_1422cee50(int nKind);
    void FUN_1422ceea0(const CStringW& strHint);
};
class Unk_McCursorPtr
{
public:
    ~Unk_McCursorPtr();                                         // 0x140a58400
    void* FUN_140a58470() const;                                // non-null test
    Unk_McCursor* FUN_140a584a0() const;                        // operator->
private:
    void* m_pad_00;
    Unk_McCursor* m_p;
};
class Unk_McInput
{
public:
    int FUN_1422aeed0(int nKey);                                // key / button state
    Unk_McCursorPtr FUN_1422b0370(int nSlot);                   // cursor widget
};
Unk_McInput* FUN_14025e7a0();

// Application window.
class Unk_McApp
{
public:
    int FUN_141b90e30(float* pfX, float* pfY);                  // cursor position inside the window
    RECT FUN_140ad4c30();                                       // client rectangle (inline getter)
};
Unk_McApp* FUN_140aadf80();

// The map data kept behind the world service's counted pointer.
struct Unk_McMapData
{
    char m_pad_00[0x154];
    float m_fRotation;                                          // +0x154 degrees around z
};
MS2_CHECK_OFFSET(Unk_McMapData, m_fRotation, 0x154);
class Unk_McMapPtr
{
public:
    ~Unk_McMapPtr();                                            // 0x1408850f0
    bool FUN_1408851f0() const;                                 // is null
    Unk_McMapData* FUN_140885340() const;                       // operator->
private:
    void* m_pad_00;
    Unk_McMapData* m_p;
};
Unk_McMapPtr FUN_140a55460(int nMapId);

// The player character (slots numbered as in PCBase).
class Unk_McState
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27();
    virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31();
    virtual void vfunc_32(); virtual void vfunc_33();
    virtual void vfunc_34();                                    // MS2: slot 34 (0x110) stop / interrupt the state
};
class Unk_McBuffSrc { public: int FUN_140970a40(); };
class Unk_McAttach : public Unk_McRefObj
{
public:
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
    virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual Unk_StreamPoint vfunc_18();                         // MS2: slot 18 (0x90) world position
};
class Unk_McPc
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17();
    virtual Unk_StreamPoint vfunc_18();                         // MS2: slot 18 (0x90) world position
    virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22();
    virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26();
    virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30();
    virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34();
    virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38();
    virtual void vfunc_39(); virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42();
    virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46();
    virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50();
    virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54();
    virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58();
    virtual void vfunc_59(int a, void* b, int c, int d);        // MS2: slot 59 (0x1d8)
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63();
    virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66();
    virtual void vfunc_67(Unk_StreamPoint* pA, Unk_StreamPoint* pB);   // MS2: slot 67 (0x218) two plane vectors
    int FUN_1416595b0();                                        // state flag
    int FUN_14166c930();                                        // action id
    Unk_McState* FUN_14166ccb0();                               // current state
    Unk_McBuffSrc* FUN_1416749a0();
    Unk_McPc* FUN_1416764a0();                                  // ridden character
    Unk_McAttach* FUN_141662440(int nSlot);                     // attachment (mount / vehicle)
    int FUN_141662490(unsigned nSlot);                          // slot occupied
    Unk_StreamPoint FUN_14123cc20();                            // facing vector
};

class Unk_McWorld
{
public:
    Unk_McPc* FUN_141bd0cc0();                                  // the local player
    float FUN_141bcfc50();                                      // camera scale of the local player
    int FUN_141bd3060();                                        // current map id
    Unk_McMapPtr FUN_141bd30a0();                               // current map data
    int FUN_141bdb5e0();                                        // local player locked
};
Unk_McWorld* FUN_1403ed2d0();

// Counted pointer to the attachment: AddRef in the ctor, Release in the dtor.
class Unk_McAttachPtr
{
public:
    // @0x140ad4230
    Unk_McAttachPtr(Unk_McAttach* p)
    {
        m_p = p;
        if (m_p)
            m_p->vfunc_1();
    }
    // @0x140ad4540
    ~Unk_McAttachPtr()
    {
        if (m_p)
            m_p->vfunc_2();
    }
    // @0x140ad4750
    Unk_McAttach* FUN_140ad4750() const { return m_p; }
    // @0x140ad4770
    Unk_McAttach* FUN_140ad4770() const { return m_p; }
private:
    Unk_McAttach* m_p;
};

// Physics service pointer (found in the service lookup cell).
class Unk_McPhysSvc : public Unk_McRefObj { public: void* FUN_1410b8e60(void* pEntity); };
class Unk_McPhysSvcPtr
{
public:
    // (same code as the attachment pointer's ctor 0x140ad4230; ICF folded)
    Unk_McPhysSvcPtr(Unk_McPhysSvc* p)
    {
        m_p = p;
        if (m_p)
            m_p->vfunc_1();
    }
    ~Unk_McPhysSvcPtr();                                        // 0x1401cd150
    Unk_McPhysSvc* FUN_1401cd1a0() const;                       // operator->
private:
    Unk_McPhysSvc* m_p;
};
Unk_McPhysSvc* FUN_1401cd040(char* pCell);

// Entity instancing service: the object that knows which entities are hidden.
class Unk_McInstancing
{
public:
    bool FUN_1411c6a50(const egf::EntityID& id);                // entity not hidden
    // @0x140ad4bb0
    int FUN_140ad4bb0() const { return m_nHidden; }
    char m_pad_00[0xd0];
    int m_nHidden;                                              // +0xd0
};
MS2_CHECK_OFFSET(Unk_McInstancing, m_nHidden, 0xd0);
class Unk_McInstSvc : public Unk_McRefObj { public: Unk_McInstancing* FUN_1413d66b0(egf::Entity* pEntity); };
class Unk_McInstSvcPtr
{
public:
    Unk_McInstSvcPtr(Unk_McInstSvc* p)
    {
        m_p = p;
        if (m_p)
            m_p->vfunc_1();
    }
    ~Unk_McInstSvcPtr();                                        // 0x14098cc60
    Unk_McInstSvc* FUN_14098d0e0() const;                       // operator->
private:
    Unk_McInstSvc* m_p;
};
Unk_McInstSvc* FUN_14098c5b0(char* pCell);

class Unk_McEntityRules { public: bool FUN_1418638d0(egf::Entity* pEntity); };
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);
void FUN_1408a20a0(egf::Entity* pEntity, unsigned nHash, bool* pbOut);
const egf::EntityID* FUN_1408b76f0(egf::Entity* pEntity);
egf::EntityID* FUN_1408b6b20(egf::EntityID* pDst, const egf::EntityID* pSrc);
class Unk_McEntityMgr;
Unk_McEntityMgr* FUN_1409670f0();
egf::Entity* FUN_1411cf440(Unk_McEntityMgr* pMgr, const egf::EntityID& id);

// The picked-object list returned by the scene pick.
struct Unk_McPickHit
{
    NiAVObject* FUN_140a17cb0();                                // scene graph node
    // @0x140ad4bd0
    Unk_StreamPoint* FUN_140ad4bd0() { return &m_pt; }
    void* m_pad_00;
    void* m_pad_08;
    Unk_StreamPoint m_pt;                                       // +0x10 hit point
};
MS2_CHECK_OFFSET(Unk_McPickHit, m_pt, 0x10);
class Unk_McPickVec
{
public:
    unsigned FUN_140a17ea0();                                   // count
    Unk_McPickHit* FUN_140a17d70(unsigned nIndex);
};
class Unk_McPickResult { public: Unk_McPickVec* FUN_140a17e00(); };
class Unk_PickListPtr
{
public:
    ~Unk_PickListPtr();                                         // 0x140a16120
    void* FUN_140a16c00() const;                                // non-null test
    Unk_McPickResult* FUN_140a16c30() const;                    // operator->
private:
    void* m_pad_00;
    Unk_McPickResult* m_p;
};

// Camera: the ray under the cursor.
bool FUN_140af0520(Unk_CameraManager* pCam, const Unk_Point2& pt, Unk_StreamPoint* pOrigin, Unk_StreamPoint* pDir);

// Math helpers.
bool FUN_14028d470(float a, float b);                           // approx equal
float FUN_140966f00(Unk_StreamPoint a, Unk_StreamPoint b);      // distance
Unk_StreamPoint FUN_1420834e0(const Unk_StreamPoint& v, const Unk_EfdMatrix3& m);   // efd::operator*(Point3, Matrix3)

// The effect manager and the request it takes (constructed / destroyed out of line).
struct Unk_McRot { float m_af[9]; };
struct Unk_McXform
{
    Unk_McRot m_rotate;
    float m_afTranslate[3];
    float m_fScale;
};
MS2_CHECK_SIZE(Unk_McXform, 0x34);
struct Unk_McRequest
{
    CString m_strName;                                          // +0
    int m_nOwnerId;                                             // +8
    int m_pad_0c;
    void* m_pSlot10;
    Unk_McXform* m_pXform;                                      // +0x18
    char m_pad_20[0x58];
};
MS2_CHECK_SIZE(Unk_McRequest, 0x78);
class Unk_McEffectMgr { public: void FUN_1411a4a00(Unk_McRequest* pRequest); };
Unk_McEffectMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_McRequest* p);                           // construct
void FUN_1405a89e0(Unk_McRequest* p);                           // destroy
void* FUN_140a332d0(Unk_McXform* p);                            // NiTransform default ctor
void FUN_1420849a0(Unk_McRot* p);                               // efd::Matrix3::MakeIdentity
void FUN_14097fad0(float* pDst, const Unk_NiPoint3* pSrc);      // NiPoint3 assignment

// Game-wide constants table (the pick range of the cursor).
struct Unk_McConstUInt { char m_pad_00[0x58]; };
struct Unk_McConstTable
{
    char m_pad_00[0xe668];
    Unk_McConstUInt m_pickRange;                                // +0xe668
};
MS2_CHECK_OFFSET(Unk_McConstTable, m_pickRange, 0xe668);
Unk_McConstTable* FUN_1401d3200();
unsigned* FUN_1401d7c10(Unk_McConstUInt* pSlot);

// The physics helper (singleton) and the camera manager's mode holder.
CPhysXHelper* FUN_1409f7ca0();
struct Unk_McModeRef
{
    long long FUN_1409f2180() const;                            // non-null test
    CCameraMode* FUN_1409f21a0() const;                         // operator->
    void* m_pad_00;
    CCameraMode* m_p;
};
struct Unk_McCameraView                                         // the part of the camera manager used here
{
    char m_pad_00[0x118];
    Unk_McModeRef m_mode;                                       // +0x118 current camera mode
};
MS2_CHECK_OFFSET(Unk_McCameraView, m_mode, 0x118);

ecr::SceneGraphService* FUN_140ad4ba0();
Unk_McEntityRules* FUN_140ad4b90();
void FUN_140ad4ff0(Unk_CameraManager* pCam, float fValue);

// Convert between the point types of the pick helpers and the mouse ray.
static void ToVec3(Unk_Vec3& dst, const Unk_StreamPoint& src)
{
    dst.x = src.x;
    dst.y = src.y;
    dst.z = src.z;
}
static Unk_StreamPoint FromVec3(const Unk_Vec3& src)
{
    return Unk_StreamPoint(src.x, src.y, src.z);
}

// @0x140ad1860
CMouseController::CMouseController()
{
    MS2Ptr<CMouseInteract> spTalkCancel(new CMouseInteractTalkCancel);
    m_arrInteract.Add(spTalkCancel);
    MS2Ptr<CMouseInteract> spTaxi(new CMouseInteractTaxi);
    m_arrInteract.Add(spTaxi);
    MS2Ptr<CMouseInteract> spUgcBanner(new CMouseInteractUgcBanner);
    m_arrInteract.Add(spUgcBanner);
    MS2Ptr<CMouseInteract> spWeapon(new CMouseInteractWeaponObject);
    m_arrInteract.Add(spWeapon);
    MS2Ptr<CMouseInteract> spPortal(new CMouseInteractPortal);
    m_arrInteract.Add(spPortal);
    MS2Ptr<CMouseInteract> spObject(new CMouseInteractObject);
    m_arrInteract.Add(spObject);
    MS2Ptr<CMouseInteract> spNpc(new CMouseInteractNpc);
    m_arrInteract.Add(spNpc);
    FUN_140ad2070();
    FUN_140ad40b0();
    m_nMode = 0;
    m_fLastDist = 0;
    m_nIgnoreRelease = 0;
}

// @0x140ad1d20
CMouseController::~CMouseController()
{
    FUN_140ad40b0();
    m_arrInteract.RemoveAll();
}

// @0x140ad1da0
void CMouseController::FUN_140ad1da0(int nMsg, int nX, int nY)
{
    if (m_nMode == 0)
        return;
    if (nMsg == 0x2a3)
    {
        FUN_140ad22d0();
        return;
    }
    int nKey = FUN_14025e7a0()->FUN_1422aeed0(2);
    if (nMsg == 0x201)
        m_nIgnoreRelease = nKey;
    if (nKey != 0)
    {
        if (nMsg == 0x202 && m_nMode != 1)
            FUN_140ad23f0(nX, nY);
        return;
    }
    if (nMsg == 0x202 && m_nIgnoreRelease != 0)
        return;
    if (FUN_140ad3dd0(nX, nY) == 0)
        return;
    switch (nMsg)
    {
    case 0x201:
        FUN_140ad2660(nX, nY);
        break;
    case 0x202:
        FUN_140ad23f0(nX, nY);
        break;
    case 0x200:
        FUN_140ad26d0(nX, nY);
        break;
    }
}
MS2_REPLACE_METHOD(0x140AD1DA0, CMouseController, FUN_140ad1da0, 320, 0x6E449FA6);

// @0x140ad1ef0
void CMouseController::FUN_140ad1ef0()
{
    if (m_nMode == 0)
        return;
    FUN_140ad2d80();
    FUN_140ad3040();
}
MS2_REPLACE_METHOD(0x140AD1EF0, CMouseController, FUN_140ad1ef0, 47, 0x65FA4324);

// @0x140ad1f30
void CMouseController::FUN_140ad1f30(int nOldAction, int nNewAction)
{
    if (m_nMode == 1 || m_nMode == 0)
        return;
    if (nNewAction == 0x10 || nNewAction == 0x2d)
    {
        if (m_nMode == 2)
            FUN_140ad22d0();
    }
    else if (nOldAction == 0x1d || nOldAction == 8)
    {
        m_tmMove.FUN_140268840();
        m_vMove = FUN_140ad3260(m_vDown);
    }
    else if (nNewAction == 0x1d || nNewAction == 8)
    {
        m_vMove = FUN_140ad3400(m_vDown);
    }
}
MS2_REPLACE_METHOD(0x140AD1F30, CMouseController, FUN_140ad1f30, 314, 0x60D963FA);

// @0x140ad2070
void CMouseController::FUN_140ad2070()
{
    m_vMove = DAT_143b01a60;
    m_vDown = DAT_143b01a60;
    m_vDir = DAT_143b01a60;
    m_fLastDist = 0;
    m_fAccumDist = 0;
}
MS2_REPLACE_METHOD(0x140AD2070, CMouseController, FUN_140ad2070, 112, 0x653E3984);

// @0x140ad20f0
int CMouseController::FUN_140ad20f0(int bEnable)
{
    if (!FUN_140166410()->FUN_14036d570(0xaf))
        return 0;
    m_nMode = bEnable ? 1 : 0;
    float fScale = FUN_1403ed2d0()->FUN_141bcfc50();
    if (Unk_CameraManager::FUN_1409478c0()->FUN_140ad4b40() != fScale)
        FUN_140ad4ff0(Unk_CameraManager::FUN_1409478c0(), fScale);
    if (bEnable == 0)
    {
        FUN_140ad2070();
        FUN_140ad40b0();
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140AD20F0, CMouseController, FUN_140ad20f0, 174, 0xFAD91CFF);

// @0x140ad21b0
int CMouseController::FUN_140ad21b0()
{
    return m_nMode != 0;
}
MS2_REPLACE_METHOD(0x140AD21B0, CMouseController, FUN_140ad21b0, 44, 0x126CFED4);

// @0x140ad21f0
int CMouseController::FUN_140ad21f0()
{
    return m_vMove.FUN_140552700(DAT_143b01a60);
}
MS2_REPLACE_METHOD(0x140AD21F0, CMouseController, FUN_140ad21f0, 41, 0xF33D26B7);

// @0x140ad2220
int CMouseController::FUN_140ad2220()
{
    return 0.0f < m_vMove.y;
}
MS2_REPLACE_METHOD(0x140AD2220, CMouseController, FUN_140ad2220, 47, 0x23BA3BF4);

// @0x140ad2260
int CMouseController::FUN_140ad2260()
{
    return m_vMove.y < 0.0f;
}
MS2_REPLACE_METHOD(0x140AD2260, CMouseController, FUN_140ad2260, 47, 0x6343EA31);

// @0x140ad22a0
Unk_StreamPoint CMouseController::FUN_140ad22a0()
{
    return m_vMove;
}
MS2_REPLACE_METHOD(0x140AD22A0, CMouseController, FUN_140ad22a0, 41, 0x23DA3C24);

// @0x140ad22d0
void CMouseController::FUN_140ad22d0()
{
    FUN_140ad2070();
    m_nMode = 1;
}
MS2_REPLACE_METHOD(0x140AD22D0, CMouseController, FUN_140ad22d0, 36, 0x7D4F70F3);

// @0x140ad2300
// MS2-FUNCTIONAL: effect request / transform stand-ins; frame layout differs
void CMouseController::FUN_140ad2300(Unk_StreamPoint pt)
{
    Unk_McXform xf;
    FUN_140a332d0(&xf);
    xf.m_fScale = 1.0f;
    FUN_1420849a0(&xf.m_rotate);
    Unk_NiPoint3 niPt(pt);
    FUN_14097fad0(xf.m_afTranslate, &niPt);
    Unk_McRequest request;
    FUN_140a52ef0(&request);
    request.m_strName = "CH/Common/Eff_mouse_click.xml";
    request.m_pXform = &xf;
    request.m_nOwnerId = 0;
    FUN_1403ed280()->FUN_1411a4a00(&request);
    FUN_1405a89e0(&request);
}
MS2_REPLACE_METHOD(0x140AD2300, CMouseController, FUN_140ad2300, 226, 0x8DCAE37A);

// @0x140ad23f0
// MS2-FUNCTIONAL: transliterated from the decompile
void CMouseController::FUN_140ad23f0(int nX, int nY)
{
    m_nMode = 2;
    Unk_McPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0 || pPc->FUN_1416595b0() == 1)
        return;
    int nAction = pPc->FUN_14166c930();
    Unk_StreamPoint pt = DAT_143b01a60;
    if (FUN_140ad3550(nX, nY, &pt) == 0)
    {
        if (nAction == 0x1e)
            pt = FUN_140ad3a60(nX, nY);
        else
            pt = FUN_140ad3740(nX, nY);
        if (pt.FUN_140552690(DAT_143b01a60))
        {
            FUN_140ad22d0();
            return;
        }
    }
    FUN_140ad4000(&pt);
    m_fLastDist = 0;
    FUN_140ad2300(pt);
    if (nAction == 8 || nAction == 0x1d)
        m_vMove = FUN_140ad3400(pt);
    else
        m_vMove = FUN_140ad3260(pt);
    Unk_McState* pState = pPc->FUN_14166ccb0();
    if (pState != 0 && nAction == 8)
        pState->vfunc_34();
}
MS2_REPLACE_METHOD(0x140AD23F0, CMouseController, FUN_140ad23f0, 609, 0x030EFF74);

// @0x140ad2660
void CMouseController::FUN_140ad2660(int nX, int nY)
{
    Unk_McPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    if (pPc->FUN_1416595b0() == 1)
        return;
    m_nMode = 3;
    m_tmHold.FUN_140268840();
}
MS2_REPLACE_METHOD(0x140AD2660, CMouseController, FUN_140ad2660, 97, 0xBF848A36);

// @0x140ad26d0
void CMouseController::FUN_140ad26d0(int nX, int nY)
{
    if (m_nMode != 3)
        return;
    if (m_tmHold.FUN_140268870(100) == 0)
        return;
    if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) == 0)
    {
        m_nMode = 1;
        return;
    }
    float fHalfWidth = (float)DAT_143af62d4 / 2.0f;
    float fHalfHeight = (float)DAT_143af62d8 / 2.0f;
    Unk_StreamPoint v;
    v.x = (float)nX - fHalfWidth;
    v.y = (float)nY - fHalfHeight;
    v.z = 0;
    v.x *= -1.0f;
    v.y *= -1.0f;
    v.FUN_140968990();
    m_vMove = v;
    m_vDown = DAT_143b01a60;
    m_vDir = DAT_143b01a60;
    m_fLastDist = 0;
}
MS2_REPLACE_METHOD(0x140AD26D0, CMouseController, FUN_140ad26d0, 346, 0x463D5B7F);

// @0x140ad2830
// MS2-FUNCTIONAL: transliterated from the decompile
void CMouseController::FUN_140ad2830()
{
    Unk_McPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    if (FUN_1403ed2d0()->FUN_141bdb5e0() != 0 || FUN_140ad3d60() != 0)
        return;
    int nAction = pPc->FUN_14166c930();
    if (!(nAction == 2 || (0x1a < nAction && (nAction < 0x1d || nAction == 0x21))))
        return;
    if (m_tmMove.FUN_140268870(100) == 0)
        return;
    Unk_RayCastInfo info;
    Unk_StreamPoint vUp(0.0f, 0.0f, 75.0f);
    info.m_origin = pPc->vfunc_18().FUN_14097fd50(vUp);
    info.m_dir = pPc->FUN_14123cc20();
    info.m_maxDist = 50.0f;
    info.m_groups = 0x201;
    if (!FUN_1409f7ca0()->CastRay(&info, 0))
        return;
    Unk_McPhysSvcPtr spPhys(FUN_1401cd040(&DAT_143b059e8));
    void* pHit = spPhys.FUN_1401cd1a0()->FUN_1410b8e60(info.m_hitEntity);
    if (pHit != 0)
    {
        Unk_McState* pState = pPc->FUN_14166ccb0();
        if (pState == 0)
            return;
        int nAction2 = pPc->FUN_14166c930();
        if (nAction2 == 2 || nAction2 == 0x1b)
        {
            pState->vfunc_34();
        }
        else if (nAction2 == 0x21)
        {
            Unk_McPc* pRidden = pPc->FUN_1416764a0();
            if (pRidden != 0)
                pRidden->FUN_14166ccb0()->vfunc_34();
        }
    }
}
MS2_REPLACE_METHOD(0x140AD2830, CMouseController, FUN_140ad2830, 636, 0x99999D1E);

// @0x140ad2ac0
// MS2-FUNCTIONAL: transliterated from the decompile
int CMouseController::FUN_140ad2ac0(int nX, int nY, CStringW* pStrHint)
{
    if (m_nMode == 0)
        return 0;
    Unk_StreamPoint vOrigin;
    Unk_StreamPoint vDir;
    Unk_Point2 ptCursor((float)nX, (float)nY);
    if (!FUN_140af0520(Unk_CameraManager::FUN_1409478c0(), ptCursor, &vOrigin, &vDir))
        return 0;
    Unk_McPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    Unk_StreamPoint vPos = pPc->vfunc_18();
    Unk_MouseRay ray = {};
    ToVec3(ray.vOrigin, vOrigin);
    ToVec3(ray.vEnd, vDir);
    for (unsigned long long i = 0; i < m_arrInteract.GetCount(); i++)
    {
        MS2Ptr<CMouseInteract> sp = m_arrInteract[(size_t)i];
        if (sp->vfunc_1(&ray) == 0)
            continue;
        float fDist = FUN_140966f00(vPos, FromVec3(ray.vPick));
        if (fDist <= (float)*FUN_1401d7c10(&FUN_1401d3200()->m_pickRange))
        {
            *pStrHint = ray.strCursor;
            return sp->vfunc_6();
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140AD2AC0, CMouseController, FUN_140ad2ac0, 690, 0x84CA9624);

// @0x140ad2d80
// MS2-FUNCTIONAL: transliterated from the decompile
void CMouseController::FUN_140ad2d80()
{
    if (!FUN_140166410()->FUN_14036d570(0xe2))
        return;
    if (m_tmPick.FUN_140268870(100) != 0)
    {
        float fX, fY;
        if (FUN_140aadf80()->FUN_141b90e30(&fX, &fY) != 0 && FUN_140ad3dd0((int)fX, (int)fY) != 0)
        {
            CStringW strHint;
            int nKind = 0;
            if (FUN_14025e7a0()->FUN_1422aeed0(2) == 0)
            {
                if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0)
                    nKind = FUN_140ad2ac0((int)fX, (int)fY, &strHint);
            }
            Unk_McCursorPtr spCursor = FUN_14025e7a0()->FUN_1422b0370(6);
            if (spCursor.FUN_140a58470() != 0)
            {
                int nCurrent = spCursor.FUN_140a584a0()->FUN_1422cef10();
                if (nCurrent == 0 || nCurrent == 0xb)
                {
                    int nWanted = 0;
                    if (nKind != 0)
                        nWanted = 0xb;
                    if (nCurrent != nWanted)
                        spCursor.FUN_140a584a0()->FUN_1422cee50(nWanted);
                    if (strHint.GetLength() != 0)
                        spCursor.FUN_140a584a0()->FUN_1422ceea0(strHint);
                }
            }
        }
    }
    Unk_McPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc != 0 && m_spCurrent.get() != 0)
    {
        if (m_spCurrent->vfunc_3() != 0)
        {
            pPc->vfunc_59(1, 0, 0, 0);
            m_spCurrent->vfunc_4();
            FUN_140ad22d0();
            FUN_140ad40b0();
        }
    }
}
MS2_REPLACE_METHOD(0x140AD2D80, CMouseController, FUN_140ad2d80, 686, 0xB16D7996);

// @0x140ad3040
// MS2-FUNCTIONAL: transliterated from the decompile
void CMouseController::FUN_140ad3040()
{
    Unk_McPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0 || m_nMode == 1)
        return;
    if (pPc->FUN_1416595b0() == 1 && m_nMode == 2)
    {
        FUN_140ad22d0();
        return;
    }
    if (m_vDown.FUN_140552700(DAT_143b01a60))
    {
        Unk_StreamPoint vPos = FUN_140ad3c70();
        const Unk_StreamPoint& vTarget = (pPc->FUN_1416749a0()->FUN_140970a40() == 0) ? m_vDown : m_vDir;
        float fDist = vPos.FUN_140965c40(vTarget).FUN_140967ac0();
        if (fDist <= m_fLastDist || m_fLastDist == 0.0f)
        {
            m_fAccumDist = 0;
        }
        else
        {
            if (fDist < 75.0f)
            {
                FUN_140ad22d0();
                return;
            }
            if (pPc->FUN_14166c930() != 6)
                m_fAccumDist = m_fAccumDist + (fDist - m_fLastDist);
            if (15.0f < m_fAccumDist)
            {
                FUN_140ad22d0();
                return;
            }
        }
        m_fLastDist = fDist;
    }
    FUN_140ad2830();
}
MS2_REPLACE_METHOD(0x140AD3040, CMouseController, FUN_140ad3040, 524, 0xF761C44F);

// @0x140ad3260
// MS2-FUNCTIONAL: transliterated from the decompile
Unk_StreamPoint CMouseController::FUN_140ad3260(Unk_StreamPoint pt)
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return DAT_143b01a60;
    Unk_McMapPtr spMap = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spMap.FUN_1408851f0())
        return DAT_143b01a60;
    Unk_StreamPoint v = pt.FUN_140965c40(FUN_140ad3c70());
    v.x = v.x * -1.0f;
    v.FUN_140968990();
    Unk_NiMatrix3 rot;
    rot.FUN_142084c10(((spMap.FUN_140885340()->m_fRotation * 3.1415927f) / 180.0f) * -1.0f);
    return FUN_1420834e0(v, rot);
}
MS2_REPLACE_METHOD(0x140AD3260, CMouseController, FUN_140ad3260, 401, 0x0F977D87);

// @0x140ad3400
Unk_StreamPoint CMouseController::FUN_140ad3400(Unk_StreamPoint pt)
{
    Unk_McPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    Unk_StreamPoint vFacing = pPc->FUN_14123cc20();
    Unk_StreamPoint vPos = FUN_140ad3c70();
    Unk_StreamPoint v = DAT_143b01a60;
    if (FUN_14028d470(vFacing.x, 1.0f))
    {
        v = DAT_143b01a60;
        v.x = pt.y - vPos.y;
        v.y = pt.z - vPos.z;
        v.FUN_140968990();
    }
    else
    {
        v.x = pt.x - vPos.x;
        v.y = pt.z - vPos.z;
        v.x *= -1.0f;
        v.FUN_140968990();
    }
    return v;
}
MS2_REPLACE_METHOD(0x140AD3400, CMouseController, FUN_140ad3400, 319, 0xC44D571F);

// @0x140ad3550
// MS2-FUNCTIONAL: transliterated from the decompile; the ray holds Unk_Vec3 members
int CMouseController::FUN_140ad3550(int nX, int nY, Unk_StreamPoint* pOut)
{
    if (!FUN_140166410()->FUN_14036d570(0xe2))
        return 0;
    FUN_140ad40b0();
    Unk_StreamPoint vOrigin;
    Unk_StreamPoint vDir;
    Unk_Point2 ptCursor((float)nX, (float)nY);
    if (!FUN_140af0520(Unk_CameraManager::FUN_1409478c0(), ptCursor, &vOrigin, &vDir))
        return 0;
    Unk_MouseRay ray = {};
    ToVec3(ray.vOrigin, vOrigin);
    ToVec3(ray.vEnd, vDir);
    for (unsigned long long i = 0; i < m_arrInteract.GetCount(); i++)
    {
        MS2Ptr<CMouseInteract> sp = m_arrInteract[(size_t)i];
        if (sp->vfunc_2(&ray) != 0)
        {
            m_spCurrent = sp;
            *pOut = FromVec3(ray.vPick);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140AD3550, CMouseController, FUN_140ad3550, 488, 0x5FC70789);

// @0x140ad3740
// MS2-FUNCTIONAL: transliterated from the decompile
Unk_StreamPoint CMouseController::FUN_140ad3740(int nX, int nY)
{
    Unk_PickListPtr spPick = Unk_CameraManager::FUN_1409478c0()->FUN_140af0850((float)nX, (float)nY, true, true, false, 0);
    if (spPick.FUN_140a16c00() == 0)
        return DAT_143b01a60;
    if (spPick.FUN_140a16c30()->FUN_140a17e00() == 0)
        return DAT_143b01a60;
    int bSpecialMap = FUN_140ad4140(FUN_1403ed2d0()->FUN_141bd3060());
    for (unsigned i = 0; i < spPick.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17ea0(); i++)
    {
        Unk_McPickHit* pHit = spPick.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17d70(i);
        egf::Entity* pEntity = FUN_140ad4ba0()->GetEntityFromSceneGraphNode(pHit->FUN_140a17cb0());
        if (pEntity == 0)
            continue;
        bool bClickable = false;
        if (FUN_1408a9bd0(pEntity)->ContainsModel(0xd8dea70d))
        {
            bClickable = true;
        }
        else if (FUN_1408a9bd0(pEntity)->ContainsModel(0x74b363a7))
        {
            bClickable = true;
        }
        else if (bSpecialMap != 0)
        {
            if (FUN_1408a9bd0(pEntity)->ContainsModel(0xb30dd8f0))
            {
                if (FUN_1408a9bd0(pEntity)->ContainsModel(0xee17343a))
                    continue;
                bClickable = true;
            }
        }
        if (bClickable && FUN_140ad3e80(pEntity))
            return *spPick.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17d70(i)->FUN_140ad4bd0();
    }
    return DAT_143b01a60;
}
MS2_REPLACE_METHOD(0x140AD3740, CMouseController, FUN_140ad3740, 794, 0xD0619D77);

// @0x140ad3a60
// MS2-FUNCTIONAL: transliterated from the decompile
Unk_StreamPoint CMouseController::FUN_140ad3a60(int nX, int nY)
{
    Unk_McPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return DAT_143b01a60;
    Unk_StreamPoint vDir;
    Unk_StreamPoint vOrigin;
    Unk_Point2 ptCursor((float)nX, (float)nY);
    if (FUN_140af0520(Unk_CameraManager::FUN_1409478c0(), ptCursor, &vOrigin, &vDir))
    {
        Unk_StreamPoint vA;
        Unk_StreamPoint vB;
        pPc->vfunc_67(&vA, &vB);
        Unk_StreamPoint vNormal = vA.FUN_140a00e10(vB);
        Unk_StreamPoint vPos = pPc->vfunc_18();
        float fDen = vNormal.FUN_140a00f20(vDir);
        if (fDen != 0.0f)
        {
            float fNum = vNormal.FUN_140a00f20(vPos.FUN_140965c40(vOrigin));
            return vOrigin.FUN_14097fd50(FUN_1409ab5c0(fNum / fDen, vDir));
        }
    }
    return DAT_143b01a60;
}
MS2_REPLACE_METHOD(0x140AD3A60, CMouseController, FUN_140ad3a60, 514, 0x7514812C);

// @0x140ad3c70
Unk_StreamPoint CMouseController::FUN_140ad3c70()
{
    Unk_McPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return DAT_143b01a60;
    Unk_McAttachPtr spAttach(pPc->FUN_141662440(1));
    if (spAttach.FUN_140ad4750() != 0)
        return spAttach.FUN_140ad4770()->vfunc_18();
    return pPc->vfunc_18();
}
MS2_REPLACE_METHOD(0x140AD3C70, CMouseController, FUN_140ad3c70, 231, 0x6697DFE8);

// @0x140ad3d60
int CMouseController::FUN_140ad3d60()
{
    Unk_McPc* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    for (unsigned long long i = 0; i < 3; i++)
    {
        if (pPc->FUN_141662490((unsigned)i) != 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140AD3D60, CMouseController, FUN_140ad3d60, 105, 0x8AC838E7);

// @0x140ad3dd0
int CMouseController::FUN_140ad3dd0(int nX, int nY)
{
    if (nX < 0)
        return 0;
    if (nY < 0)
        return 0;
    RECT rc = FUN_140aadf80()->FUN_140ad4c30();
    int nWidth = rc.right - rc.left;
    if (nX > nWidth)
        return 0;
    int nHeight = rc.bottom - rc.top;
    if (nY > nHeight)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140AD3DD0, CMouseController, FUN_140ad3dd0, 156, 0x1F80C246);

// @0x140ad3e80
// MS2-FUNCTIONAL: transliterated from the decompile
bool CMouseController::FUN_140ad3e80(egf::Entity* pEntity)
{
    bool bFlagA = false;
    bool bResult = false;
    FUN_1408a20a0(pEntity, 0x23f9860e, &bFlagA);
    if (bFlagA)
    {
        Unk_McInstSvcPtr spSvc(FUN_14098c5b0(&DAT_143b059e8));
        Unk_McInstancing* pInst = spSvc.FUN_14098d0e0()->FUN_1413d66b0(pEntity);
        if (pInst != 0 && pInst->FUN_140ad4bb0() == 0)
        {
            bResult = pInst->FUN_1411c6a50(egf::EntityID(*FUN_1408b76f0(pEntity))) ? false : true;
        }
        else
        {
            bResult = FUN_140ad4b90()->FUN_1418638d0(pEntity);
        }
    }
    else
    {
        FUN_1408a20a0(pEntity, 0xa0b6b179, &bResult);
    }
    return bResult;
}
MS2_REPLACE_METHOD(0x140AD3E80, CMouseController, FUN_140ad3e80, 288, 0x978EA17D);

// @0x140ad3fb0
bool CMouseController::FUN_140ad3fb0(const egf::EntityID& id)
{
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), id);
    if (pEntity == 0)
        return false;
    return FUN_140ad3e80(pEntity);
}
MS2_REPLACE_METHOD(0x140AD3FB0, CMouseController, FUN_140ad3fb0, 69, 0xA918C04A);

// @0x140ad4000
void CMouseController::FUN_140ad4000(const Unk_StreamPoint* pPoint)
{
    m_vDown = *pPoint;
    Unk_StreamPoint vPos = FUN_140ad3c70();
    Unk_StreamPoint vDelta;
    vDelta.x = vPos.x - m_vDown.x;
    vDelta.y = vPos.y - m_vDown.y;
    vDelta.z = 0;
    m_vDir = vPos.FUN_14097fd50(vDelta);
}
MS2_REPLACE_METHOD(0x140AD4000, CMouseController, FUN_140ad4000, 156, 0xDC0D59A1);

// @0x140ad40b0
void CMouseController::FUN_140ad40b0()
{
    m_spCurrent = 0;
    for (unsigned long long i = 0; i < m_arrInteract.GetCount(); i++)
        m_arrInteract[(size_t)i]->vfunc_5();
}
MS2_REPLACE_METHOD(0x140AD40B0, CMouseController, FUN_140ad40b0, 134, 0xECB67440);

// @0x140ad4140
int CMouseController::FUN_140ad4140(int nMapId)
{
    Unk_McMapPtr spMap = FUN_140a55460(nMapId);
    if (spMap.FUN_1408851f0())
        return 0;
    switch (nMapId)
    {
    case 0x1e8625:
    case 0x3199c37:
    case 0x3199c4a:
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140AD4140, CMouseController, FUN_140ad4140, 169, 0x2DEBDE78);

// @0x140ad4340
// @0x140ad4370
// @0x140ad43b0
// @0x140ad43e0
// @0x140ad4410
// (the CMouseInteract subclasses' implicit ctors are emitted by the `new` expressions above)

// @0x140ad4440
Unk_RayCastInfo::Unk_RayCastInfo()
{
    m_maxDist = 0;
    m_groups = -1;
    m_20 = 0;
    m_28 = 0;
    m_hitEntity = 0;
    m_hitActor = 0;
    m_hitShape = 0;
    m_hitDist = 0;
}

// @0x140ad45d0
CMouseInteractNpc::~CMouseInteractNpc()
{
}

// @0x140ad45f0
CMouseInteractObject::~CMouseInteractObject()
{
}

// @0x140ad4620
CMouseInteractPortal::~CMouseInteractPortal()
{
}

// @0x140ad4640
CMouseInteractTalkCancel::~CMouseInteractTalkCancel()
{
}

// @0x140ad4660
CMouseInteractWeaponObject::~CMouseInteractWeaponObject()
{
}

// @0x140ad4b40
float Unk_CameraManager::FUN_140ad4b40()
{
    if (reinterpret_cast<Unk_McCameraView*>(this)->m_mode.FUN_1409f2180() != 0)
        return reinterpret_cast<Unk_McCameraView*>(this)->m_mode.FUN_1409f21a0()->FUN_140ad4b30();
    return 0.0f;
}
MS2_REPLACE_METHOD(0x140AD4B40, Unk_CameraManager, FUN_140ad4b40, 70, 0x8A6FD2BB);

// @0x140ad4b90
Unk_McEntityRules* FUN_140ad4b90()
{
    return DAT_143ab9510;
}

// @0x140ad4ba0
ecr::SceneGraphService* FUN_140ad4ba0()
{
    return DAT_143ab9508;
}

// @0x140ad4be0
int CMouseInteractNpc::vfunc_6()
{
    return 1;
}
MS2_REPLACE_METHOD(0x140AD4BE0, CMouseInteractNpc, vfunc_6, 11, 0x30025ED0);

// @0x140ad4bf0
int CMouseInteractObject::vfunc_6()
{
    return 3;
}
MS2_REPLACE_METHOD(0x140AD4BF0, CMouseInteractObject, vfunc_6, 11, 0xA6B3D596);

// @0x140ad4c00
int CMouseInteractPortal::vfunc_6()
{
    return 2;
}
MS2_REPLACE_METHOD(0x140AD4C00, CMouseInteractPortal, vfunc_6, 11, 0x620C90F9);

// @0x140ad4c10
int CMouseInteractTalkCancel::vfunc_6()
{
    return 6;
}
MS2_REPLACE_METHOD(0x140AD4C10, CMouseInteractTalkCancel, vfunc_6, 11, 0xFCA8E685);

// @0x140ad4c20
int CMouseInteractWeaponObject::vfunc_6()
{
    return 7;
}
MS2_REPLACE_METHOD(0x140AD4C20, CMouseInteractWeaponObject, vfunc_6, 11, 0x41502B22);

// @0x140ad4c30
RECT Unk_McApp::FUN_140ad4c30()
{
    return g_rcWindow;
}

// @0x140ad4ff0
void FUN_140ad4ff0(Unk_CameraManager* pCam, float fValue)
{
    if (reinterpret_cast<Unk_McCameraView*>(pCam)->m_mode.FUN_1409f2180() != 0)
    {
        CCameraMode* pMode = reinterpret_cast<Unk_McCameraView*>(pCam)->m_mode.FUN_1409f21a0();
        pMode->vfunc_11(fValue);
    }
}
MS2_REPLACE(0x140AD4FF0, FUN_140ad4ff0, 90, 0xA264B5C2);
