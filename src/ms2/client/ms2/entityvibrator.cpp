// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CEntityVibrator: shakes a world entity, then drops a physics box.
// MS2-UNIT: client\ms2\entityvibrator.cpp
// MS2-RANGE: 0x1411cb290-0x1411ce0f4 .text$mn
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\entityvibrator.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <math.h>
#include "entityvibrator.h"
#include "physxhelper.h"
#include <efd/ILogger.h>
#include <efd/LoggerMacros.h>
#include <efd/AssetID.h>
#include <efd/EEMath.h>
#include <efd/utf8string.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/cubemapinformationservice_1.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "ms2/client/ms2/skillrecord.h"
#include <efd/SmartPointer.h>   // C3: efd::SmartPointer<CubeMapInformationService>::operator->
class NoticeMessage   // C3: unit-local view (ctor 0x140a52ef0, dtor 0x1405a89e0, 0x70 bytes)
{
public:
    NoticeMessage();
    ~NoticeMessage();
    void* m_storage[14];
};
#include <efd/ISystemService.h>
#include <NiAVObject.h>   // C3: NiAVObject::GetTranslate, GetRotate
// The ref'd service (class id 0x06100017) the framework hands out; buddy.cpp keeps the same view.
// C3: Unk_Service6100017 was CubeMapInformationService (cubemapinformationservice_3.h)
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
#define DAT_143a08ce8 (*(Vector3*)&efd::Point3::UNIT_Y) // C3: was extern Vector3 DAT_143a08ce8; (0, 1, 0)
#define g_143a08cf8 (*(const Vector3*)&efd::Point3::UNIT_Z)                           // (0, 0, 1)
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 egf::g_bapiContext
extern int DAT_143ad1b20;                                           // running actor counter
extern int DAT_1439f7060;                                           // number of collision masks (8)
extern unsigned DAT_1439f7040[];                                    // the collision masks
extern unsigned char DAT_143afc898;                                          // assertions throw when set
extern "C" float (__cdecl* __imp_sinf)(float);                      // the exe calls the CRT import

class Unk_VibZoneMap : public ATL::CRBMap<CString, CString> { };   // C3: unit-local view
class Unk_VibZone
{
public:
    char m_pad_00[0x58];
    Unk_VibZoneMap m_map;                                           // +0x58 model name -> effect name
};
class Unk_VibParams                                                 // the skill record fields read here
{
public:
    char m_pad_00[0x18];
    unsigned m_18;                                                  // start time
    char m_pad_1c[0x34];
    Vector3 m_50;                                           // impact point
};

// The entity: property accessors by hash.
void FUN_14098c6e0(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0

class Unk_Entity
{
public:
    void FUN_140a38a50(unsigned nProp, const Vector3& rValue);
};

//
// FindCubeByEntityRef (0x1410b8be0) takes the id by value: this caller copies it.


class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: the physics service getter (real return type)
int FUN_140768010(int nRange, int nBase);                           // random number in [nBase, nBase + nRange)
float FUN_140768090();                                              // random 0..1
float FUN_14109ace0();                                              // random 0..1
__int64 FUN_14028d260(float f);                                     // seconds -> milliseconds
bool Unk_IsFinite(const efd::Point3& kPoint);   // C3: was FUN_140a33ff0(const Vector3*); all components finite
void FUN_140de8bd0(egf::Entity* pEntity, unsigned nProp, efd::AssetID* pValue);


Unk_Int3 FUN_1408a1430(NiPoint3 pt);                        // point -> cube cell (C3: actionkeyobject.cpp's declaration)
//
CubeMapInformationService* GetCubeMapService();   // C3: was FUN_1410b27c0

// 3x3 matrix with column setters.
struct Unk_VibMat : Unk_NiMatrix3
{
    Unk_VibMat() {}
    Unk_VibMat(const Unk_EfdMatrix3& m) : Unk_NiMatrix3(m) {}
};
// Rotation, translation and scale (0x34 bytes).
struct Unk_VibXform
{
    Unk_VibXform() {}
    Unk_NiMatrix3 m_rot;
    NiPoint3 m_trans;
    float m_scale;
};
MS2_CHECK_SIZE(Unk_VibXform, 0x34);
class Unk_VibObj                                                    // the entity's scene graph root
{
public:
};
class NiAVObject;
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);

// Effect play request (0x70 bytes; ctor 0x140a52ef0, dtor 0x1405a89e0).
struct Unk_VibEffectReq
{
    Unk_VibEffectReq();
    ~Unk_VibEffectReq();
    CString m_name;                                                 // +0x00
    int m_type;                                                     // +0x08
    int m_pad_0c;
    void* m_pad_10;
    Unk_VibXform* m_pXform;                                         // +0x18
    void* m_pad_20; void* m_pad_28; void* m_pad_30; void* m_pad_38;
    void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58;
    void* m_pad_60; void* m_pad_68;
};
MS2_CHECK_SIZE(Unk_VibEffectReq, 0x70);

// NiMatrix3 with the column getter (0x1411ce070); the column is an NxVec3 (ctor(x, y, z) 0x140a00350).
struct Unk_VibNiMat : Unk_NiMatrix3
{
    NxVec3 FUN_1411ce070(int nCol) const;
};

// @0x1411cb290
CEntityVibrator::CEntityVibrator(Unk_Entity* pEntity)
    : m_entity(0)
{
    FUN_1411cd570(pEntity);
}

// @0x1411cb390
CEntityVibrator::CEntityVibrator(Unk_Entity* pEntity, MS2Ptr<CSkillRecord> params, CString strModel, unsigned char nMode)
    : m_entity(0)
{
    FUN_1411cd570(pEntity);
    m_2c = reinterpret_cast<Unk_VibParams*>(params.operator->())->m_18;
    m_70 = reinterpret_cast<Unk_VibParams*>(params.operator->())->m_50;
    m_30 = (unsigned)TSingleton<CMainSystem>::GetInstance()->FUN_141473390();
    int nLimit = 0;
    m_entity.operator egf::Entity*()->GetPropertyValue(0xf5d61d2b, nLimit);
    if (m_90 > 0 && params.operator->()->GetBrokenOffence() > nLimit) {
        m_7c = 1;
        CubeMapInformationService* pCubeSvc = GetCubeMapService();
        Unk_CubeHeightIndex* pCube = pCubeSvc->FUN_1410b9e70();
        Unk_Int3 cell = FUN_1408a1430(reinterpret_cast<const NiPoint3&>(m_ac));
        pCube->FUN_1410b25a0(cell.x, cell.y, cell.z);
        if (m_ab != 0) {
            bool bOff = false;
            FUN_14098c6e0((class Unk_CachedEntity*)(m_entity.operator egf::Entity*()), 0x9004569a, bOff);
        }
    } else {
        m_7c = 0;
        m_2c = (unsigned)TSingleton<CMainSystem>::GetInstance()->FUN_141473390();
    }
    if (m_7c != 0) {
        MakePhysxActor(params);
    }
    Unk_VibObj* pObj = reinterpret_cast<Unk_VibObj*>(FUN_141b6efc0(reinterpret_cast<egf::Entity*>(pEntity)));
    if (pObj != 0) {
        Unk_VibXform xf;
        xf.m_scale = 1.0f;
        xf.m_trans = reinterpret_cast<NiAVObject*>(pObj)->GetTranslate();
        xf.m_rot = reinterpret_cast<const Unk_NiMatrix3&>(reinterpret_cast<NiAVObject*>(pObj)->GetRotate());
        {
            efd::utf8string strFx;
            reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue(0xdd2ac78a, strFx);
            NoticeMessage req;   // C3: was Unk_VibEffectReq
            ((Unk_VibEffectReq&)(req)).m_name = strFx.c_str();
            ((Unk_VibEffectReq&)(req)).m_type = 7;
            ((Unk_VibEffectReq&)(req)).m_pXform = &xf;
            TSingleton<CEffectService>::GetInstance()->FUN_1411a4a00(reinterpret_cast<Unk_EffectTarget&>(req));
        }
        Unk_VibZone* pZone = reinterpret_cast<Unk_VibZone*>(params.operator->()->GetMotionData());
        if (pZone != 0) {
            efd::utf8string strKey;
            reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue(0x82e054a5, strKey);
            CString strFound;
            bool bFound;
            {
                CString strLookup(strKey.c_str());
                bFound = pZone->m_map.Lookup(strLookup, strFound);
            }
            if (bFound) {
                Unk_VibXform xf2;
                xf2.m_scale = 1.0f;
                xf2.m_trans = reinterpret_cast<NiAVObject*>(pObj)->GetTranslate();
                xf2.m_rot = reinterpret_cast<const Unk_NiMatrix3&>(reinterpret_cast<NiAVObject*>(pObj)->GetRotate());
                efd::utf8string strFx2;
                reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue(0xdd2ac78a, strFx2);
                NoticeMessage req2;   // C3: was Unk_VibEffectReq
                ((Unk_VibEffectReq&)(req2)).m_name = strFound;
                ((Unk_VibEffectReq&)(req2)).m_type = 7;
                ((Unk_VibEffectReq&)(req2)).m_pXform = &xf2;
                TSingleton<CEffectService>::GetInstance()->FUN_1411a4a00(reinterpret_cast<Unk_EffectTarget&>(req2));
            }
        }
    }
    FUN_1411cddc0(strModel, nMode);
}

// @0x1411cb9f0
CEntityVibrator::~CEntityVibrator()
{
    ReleaseActor();
}

// @0x1411cba60
int CEntityVibrator::FUN_1411cba60()
{
    if (m_7c != 0) {
        unsigned nNow = (unsigned)TSingleton<CMainSystem>::GetInstance()->FUN_141473390();
        const unsigned kMinDelay = 3000;   // the exe stores these three locals (the uses below fold them)
        const float kDropHeight = 3.0f;
        const unsigned kDropTime = 500;
        if (m_90 < kMinDelay) {
            m_90 = kMinDelay;
        }
        if (m_68 != 0) {
            int bLate = nNow > m_30 + 3000U;
            if (m_68->isSleeping() || bLate) {
                ReleaseActor();
            } else {
                FUN_1411cd0c0();
            }
        }
        if (m_88 == 0) {
            m_88 = (nNow > (unsigned)(m_2c + m_90));
            if (m_88 != 0 && m_94 > 0) {
                WorldService::GetInstance()->FUN_141bd8e30(m_entity.operator->()->GetEntityID(), false, 0.1f);
            }
        }
        if (m_80 == 0) {
            m_80 = (nNow > (unsigned)(m_2c + m_90 + m_94));
            if (m_a9) {
                m_80 = 0;
            }
            if (m_80 != 0) {
                if (m_94 > 0 || m_aa) {
                    WorldService::GetInstance()->FUN_141bd8e30(m_entity.operator->()->GetEntityID(), true, 0.0f);
                    m_aa = false;
                    if (m_ab) {
                        FUN_14098c6e0((class Unk_CachedEntity*)(m_entity.operator->()), 0x9004569a, m_ab);
                    }
                }
                SetRotation(m_54);
                m_8c = nNow;
            }
        }
        if (m_80 != 0) {
            if (m_8c > nNow) {
                m_8c = nNow;
            }
            Vector3 ptDrop(0.0f, 0.0f, m_98.z * kDropHeight);
            Vector3 ptStart = (m_48 - ptDrop);
            float fK = ((float)(nNow - m_8c) / kDropTime > 1.0f) ? 1.0f : (float)(nNow - m_8c) / kDropTime;
            SetPosition(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptStart) + reinterpret_cast<const efd::Point3&>(ptDrop) * fK)));
            if (1.0f <= fK) {
                SetPosition(m_48);
                SetRotation(m_54);
                efd::SmartPointer<CubeMapInformationService> com(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
                if ((CubeMapInformationService*)com != 0) {
                    reinterpret_cast<CubeMapInformationService*>(com.operator->())->FUN_1410c5570(reinterpret_cast<egf::EntityPtr&>(m_entity));
                }
                if (!m_a8) {
                    if (((CPhysXHelper*)FUN_1409f7ca0())->FUN_141689a10(m_entity.operator egf::Entity*())) {
                        ((CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(m_entity.operator egf::Entity*(), 0, 0, 1);
                    }
                }
                CubeMapInformationService* pCube = GetCubeMapService();
                if (pCube->FindCubeByEntityRef(m_entity.operator->()->GetEntityID()) != 0) {
                    Unk_CubeHeightIndex* pSub = pCube->FUN_1410b9e70();
                    Unk_Int3 cell = FUN_1408a1430(reinterpret_cast<const NiPoint3&>(m_ac));
                    pSub->FUN_1410b2510(cell.x, cell.y, cell.z);
                }
                return 0;
            }
        }
        return 1;
    } else {
        unsigned nNow = (unsigned)TSingleton<CMainSystem>::GetInstance()->FUN_141473390();
        if (nNow < m_2c) {
            return 1;
        } else if (nNow < m_34) {
            float fFade = 1.0f;
            if (nNow >= m_38) {
                fFade = 1.0f - (float)((unsigned)(nNow - m_38) / (unsigned)(m_34 - m_38));
            }
            float fScale = (fFade * (1.0f - m_28) + m_28) * m_24;
            float fT = (float)(nNow - m_2c) / (float)(unsigned)(m_34 - m_2c);
            float fOffset = __imp_sinf(fT * m_20 * 2.0f * 3.1415927f + m_64) * fScale;
            if (m_60 != (fOffset < 0.0f)) {
                float fA = ((float)(unsigned)FUN_140768010(2, 0) - 0.5f) * 2.0f;
                float fB = ((float)(unsigned)FUN_140768010(2, 0) - 0.5f) * 2.0f;
                m_3c.x = FUN_140768090() * fA;
                m_3c.y = FUN_140768090() * fB;
                m_3c.Unitize();
                m_60 = (fOffset < 0.0f);
            }
            SetPosition(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_48) + reinterpret_cast<const efd::Point3&>(m_3c) * fOffset)));
            return 1;
        } else {
            SetPosition(m_48);
            SetRotation(m_54);
            return 0;
        }
    }
}
MS2_REPLACE_METHOD(0x1411CBA60, CEntityVibrator, FUN_1411cba60, 2806, 0xCBF39D64);

// @0x1411cc570
void CEntityVibrator::MakePhysxActor(MS2Ptr<CSkillRecord> params)
{
    if (!Unk_IsFinite(reinterpret_cast<const efd::Point3&>(m_70))) {
        EE_LOG_AT(0x12, efd::ILogger::kERR1, ("CEntityVibrator::MakePhysxActor"), MS2_THIS_FILE, 0xc3);
        if (DAT_143afc898 != 0) {
            throw 13;
        }
        return;
    }
    NxScene* pScene = ((CPhysXHelper*)FUN_1409f7ca0())->FUN_14168a1c0();
    if (pScene != 0) {
        if (!m_a8) {
            if (((CPhysXHelper*)FUN_1409f7ca0())->FUN_141689a10(m_entity.operator egf::Entity*())) {
                ((CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(m_entity.operator egf::Entity*(), 5, 0, 1);
            }
        }
        efd::SmartPointer<CubeMapInformationService> com(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
        if ((CubeMapInformationService*)com != 0) {
            reinterpret_cast<CubeMapInformationService*>(com.operator->())->RemovePhysXActor(reinterpret_cast<const Unk_CMISEntityRef&>(m_entity.operator->()->GetEntityID()));
        }
        DAT_143ad1b20 = DAT_143ad1b20 + 1;
        int nMask = DAT_143ad1b20 % DAT_1439f7060;
        float fMass = 1.0f;
        float fDistance = 1.0f;
        float fDensity = 1.0f;
        float fScale = 1.5f;
        float fHeight = 0.1f;
        float fParam = params.operator->()->GetBrokenForce();
        if (fParam != 0.0f) {
            fScale = fParam;
        }
        if (0.0f < m_a4) {
            fScale = fScale * m_a4;
        }
        efd::Matrix3 rot;
        rot.MakeIdentity();
        rot.MakeZRotation(FUN_14109ace0() * 1.5707964f * 0.7f);
        NxVec3 vGravity;
        pScene->getGravity(vGravity);
        float fFall = -vGravity.z;
        float fTime = efd::Sqrt((fMass * fHeight * 2.0f) / fFall);
        float fVz = fTime * fFall;
        fVz = 0.0f;
        efd::Matrix3 basis;
        basis.MakeIdentity();
        Vector3 ptDir = (m_48 - m_70);
        ptDir.Unitize();
        efd::Point3 ptSide = reinterpret_cast<const efd::Point3&>(ptDir).UnitCross(reinterpret_cast<const efd::Point3&>(g_143a08cf8));
        efd::Point3 ptNeg = -ptSide.UnitCross(reinterpret_cast<const efd::Point3&>(g_143a08cf8));
        basis.SetCol(0, ptSide);
        basis.SetCol(1, reinterpret_cast<const efd::Point3&>(ptNeg));
        basis.SetCol(2, reinterpret_cast<const efd::Point3&>(g_143a08cf8));
        efd::Matrix3 comb = basis * rot;
        efd::Point3 vel = (comb * reinterpret_cast<const efd::Point3&>(DAT_143a08ce8)) * ((fDistance * fScale) / (fTime * 2.0f));
        Vector3 vSize = m_98;
        vSize -= Vector3(1.0f, 1.0f, 1.0f);
        NxBoxShapeDesc boxDesc;
        boxDesc.dimensions.set(vSize.x, vSize.y, vSize.z);
        boxDesc.dimensions = boxDesc.dimensions * 0.01f * 0.5f;
        boxDesc.groupsMask.bits0 = DAT_1439f7040[nMask];
        NxBodyDesc bodyDesc;
        bodyDesc.angularDamping = 0.0f;
        bodyDesc.linearDamping = 0.0f;
        bodyDesc.linearVelocity = NxVec3(vel.x, vel.y, fVz);
        bodyDesc.massLocalPose.t = NxVec3(0.0f, 0.0f, boxDesc.dimensions.z);
        if (!bodyDesc.linearVelocity.isFinite()) {
            EE_LOG_AT(0x12, efd::ILogger::kERR1, ("CEntityVibrator::MakePhysxActor bodyDesc.linearVelocity.isFinite()"), MS2_THIS_FILE, 0x118);
            if (DAT_143afc898 != 0) {
                throw 13;
            }
            return;
        }
        NxActorDesc actorDesc;
        actorDesc.shapes.pushBack(&boxDesc);
        actorDesc.body = &bodyDesc;
        actorDesc.density = fDensity;
        Vector3 ptPos = m_48;
        actorDesc.globalPose.t = NxVec3(ptPos.x, ptPos.y, ptPos.z);
        actorDesc.globalPose.t = actorDesc.globalPose.t * 0.01f;
        actorDesc.globalPose.t.z = actorDesc.globalPose.t.z + boxDesc.dimensions.z + 0.05f;
        actorDesc.globalPose.M.rotZ((m_54.z * 3.1415927f) / 180.0f);
        ((CPhysXHelper*)FUN_1409f7ca0())->FUN_14168a540(0);
        m_68 = pScene->createActor(actorDesc);
        if (m_68 != 0) {
            m_68->setName("CEntityVibrator::MakePhysxActor");
            unsigned nShapes = m_68->getNbShapes();
            NxShape* const* ppShapes = m_68->getShapes();
            for (unsigned i = 0; i < nShapes; i = i + 1) {
                NxShape* pShape = ppShapes[i];
                pShape->setGroup(10);
            }
        }
        ((CPhysXHelper*)FUN_1409f7ca0())->FUN_14168a570();
    }
}
MS2_REPLACE_METHOD(0x1411CC570, CEntityVibrator, MakePhysxActor, 2745, 0x0AC715A7);

// @0x1411cd040
void CEntityVibrator::ReleaseActor()
{
    if (m_68 != 0) {
        NxScene* pScene = ((CPhysXHelper*)FUN_1409f7ca0())->FUN_14168a1c0();
        if (pScene != 0) {
            ((CPhysXHelper*)FUN_1409f7ca0())->FUN_14168a540(0);
            pScene->releaseActor(*m_68);
            ((CPhysXHelper*)FUN_1409f7ca0())->FUN_14168a570();
            m_68 = 0;
        }
    }
}
MS2_REPLACE_METHOD(0x1411CD040, CEntityVibrator, ReleaseActor, 118, 0xD620F7BF);

// @0x1411cd0c0
void CEntityVibrator::FUN_1411cd0c0()
{
    if (m_68 != 0) {
        Vector3 ptBox = m_98;
        NxMat34 pose = m_68->getGlobalPose();
        Vector3 ptPos(pose.t.x, pose.t.y, pose.t.z);
        reinterpret_cast<efd::Point3&>(ptPos) *= 100.0f;
        NxVec3 col0 = reinterpret_cast<const Unk_VibNiMat&>(pose.M).FUN_1411ce070(0);
        NxVec3 col1 = reinterpret_cast<const Unk_VibNiMat&>(pose.M).FUN_1411ce070(1);
        NxVec3 col2 = reinterpret_cast<const Unk_VibNiMat&>(pose.M).FUN_1411ce070(2);
        Unk_VibMat rot;
        ((efd::Matrix3*)(struct Unk_NiMatrix3*)(&rot))->SetCol(0, col0.x, col0.y, col0.z);
        ((efd::Matrix3*)(struct Unk_NiMatrix3*)(&rot))->SetCol(1, col1.x, col1.y, col1.z);
        ((efd::Matrix3*)(struct Unk_NiMatrix3*)(&rot))->SetCol(2, col2.x, col2.y, col2.z);
        Vector3 ptUp;
        reinterpret_cast<const efd::Matrix3&>(rot).GetCol(2, reinterpret_cast<efd::Point3&>(ptUp));
        reinterpret_cast<efd::Point3&>(ptUp) = -reinterpret_cast<const efd::Point3&>(ptUp);
        ptPos = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptPos) + reinterpret_cast<const efd::Point3&>(ptUp) * (ptBox.z * 0.5f)));
        Vector3 ptEuler;
        if (((efd::Matrix3*)(struct Unk_NiMatrix3*)(&rot))->ToEulerAnglesXYZ(ptEuler.x, ptEuler.y, ptEuler.z)) {
            reinterpret_cast<efd::Point3&>(ptEuler) *= -57.295776f;
            SetRotation(ptEuler);
        }
        SetPosition(ptPos);
    }
}
MS2_REPLACE_METHOD(0x1411CD0C0, CEntityVibrator, FUN_1411cd0c0, 740, 0x0D133312);

// @0x1411cd3b0
void CEntityVibrator::FUN_1411cd3b0()
{
    SetPosition(m_48);
    SetRotation(m_54);
    if (m_7c != 0) {
        efd::SmartPointer<CubeMapInformationService> com(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
        if ((CubeMapInformationService*)com != 0) {
            reinterpret_cast<CubeMapInformationService*>(com.operator->())->FUN_1410c5570(reinterpret_cast<egf::EntityPtr&>(m_entity));
        }
        if (!m_a8) {
            if (((CPhysXHelper*)FUN_1409f7ca0())->FUN_141689a10(m_entity.operator egf::Entity*())) {
                ((CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(m_entity.operator egf::Entity*(), 0, 0, 1);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1411CD3B0, CEntityVibrator, FUN_1411cd3b0, 405, 0xC3AADB72);

// @0x1411cd550
int CEntityVibrator::FUN_1411cd550()
{
    return m_7c;
}
MS2_REPLACE_METHOD(0x1411CD550, CEntityVibrator, FUN_1411cd550, 14, 0xCA01277B);

// @0x1411cd570
void CEntityVibrator::FUN_1411cd570(Unk_Entity* pEntity)
{
    m_2c = (unsigned)TSingleton<CMainSystem>::GetInstance()->FUN_141473390();
    m_entity = reinterpret_cast<egf::Entity*>(pEntity);
    m_3c = DAT_143b01a60;
    m_60 = 1;
    m_68 = 0;
    m_7c = 0;
    m_80 = 0;
    m_a9 = false;
    m_aa = false;
    m_88 = 0;
    m_8c = 0;
    m_a4 = 1.0f;
    m_ab = false;
    m_entity.operator->()->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(m_48));
    m_entity.operator->()->GetPropertyValue<efd::Point3>(0x68c7c29d, (efd::Point3&)(m_54));
    m_ac = m_48;
    m_b8 = m_54;
    m_entity.operator->()->GetPropertyValue(0x4e98cfb7, m_20);
    m_entity.operator->()->GetPropertyValue(0xd993099, m_24);
    m_entity.operator->()->GetPropertyValue(0xbd4a4f13, m_28);
    float fSecA = 0.0f;
    m_entity.operator->()->GetPropertyValue(0x68bb3f0f, fSecA);
    float fSecB = 0.0f;
    m_entity.operator->()->GetPropertyValue(0x597dcc01, fSecB);
    m_entity.operator->()->GetPropertyValue(0x80448caa, m_a4);
    m_34 = (int)FUN_14028d260(fSecB) + m_2c;
    m_38 = (int)FUN_14028d260(fSecA) + m_2c;
    if (m_28 < 0.0f) {
        m_28 = 0.0f;
    }
    if (1.0f < m_28) {
        m_28 = 1.0f;
    }
    m_64 = FUN_140768090() * 6.2831855f;
    m_entity.operator->()->GetPropertyValue<efd::Point3>(0x9dc22aea, (efd::Point3&)(m_98));
    m_entity.operator->()->GetPropertyValue(0x7e5f4195, m_a8);
    int nTimeA = 0;
    m_entity.operator->()->GetPropertyValue(0x4764b338, nTimeA);
    m_94 = nTimeA;
    int nTimeB = 0;
    m_entity.operator->()->GetPropertyValue(0x292206c1, nTimeB);
    m_90 = nTimeB;
    m_entity.operator->()->GetPropertyValue(0x9004569a, m_ab);
    m_d0 = 0;
}
MS2_REPLACE_METHOD(0x1411CD570, CEntityVibrator, FUN_1411cd570, 1251, 0xF0018A6D);

// @0x1411cda60
void CEntityVibrator::SetPosition(Vector3 pos)
{
    if (reinterpret_cast<const efd::Point3&>(m_ac) != reinterpret_cast<const efd::Point3&>(pos)) {
        if (!Unk_IsFinite(reinterpret_cast<const efd::Point3&>(pos))) {
            return;
        }
        m_ac = pos;
        m_entity.operator->()->SetPropertyValue<efd::Point3>(0xfd95ca52, reinterpret_cast<const efd::Point3&>(m_ac));
    }
}
MS2_REPLACE_METHOD(0x1411CDA60, CEntityVibrator, SetPosition, 144, 0x24E4DCF5);

// @0x1411cdb00
void CEntityVibrator::SetRotation(Vector3 rot)
{
    if (reinterpret_cast<const efd::Point3&>(m_b8) != reinterpret_cast<const efd::Point3&>(rot)) {
        if (!Unk_IsFinite(reinterpret_cast<const efd::Point3&>(rot))) {
            return;
        }
        m_b8 = rot;
        m_entity.operator->()->SetPropertyValue<efd::Point3>(0x68c7c29d, reinterpret_cast<const efd::Point3&>(m_b8));
    }
}
MS2_REPLACE_METHOD(0x1411CDB00, CEntityVibrator, SetRotation, 144, 0xD81E790E);

// @0x1411cdba0
void CEntityVibrator::FUN_1411cdba0()
{
    if (m_entity == (egf::Entity*)0) return;
    if (!m_a8) {
        if (((CPhysXHelper*)FUN_1409f7ca0())->FUN_141689a10(m_entity.operator egf::Entity*())) {
            ((CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(m_entity.operator egf::Entity*(), 5, 0, 1);
        }
    }
    WorldService::GetInstance()->FUN_141bd8e30(m_entity.operator->()->GetEntityID(), false, 0.1f);
    if (m_ab) {
        FUN_14098c6e0((class Unk_CachedEntity*)(m_entity.operator->()), 0x9004569a, m_ab);
    }
    m_7c = 1;
    m_a9 = true;
    CubeMapInformationService* pSvc = GetCubeMapService();
    Unk_CubeHeightIndex* pSub = pSvc->FUN_1410b9e70();
    Unk_Int3 cell = FUN_1408a1430(reinterpret_cast<const NiPoint3&>(m_ac));
    pSub->FUN_1410b25a0(cell.x, cell.y, cell.z);
}
MS2_REPLACE_METHOD(0x1411CDBA0, CEntityVibrator, FUN_1411cdba0, 489, 0x0468E30C);

// @0x1411cdd90
void CEntityVibrator::FUN_1411cdd90()
{
    m_a9 = false;
    m_aa = true;
}
MS2_REPLACE_METHOD(0x1411CDD90, CEntityVibrator, FUN_1411cdd90, 30, 0x1214F241);

// @0x1411cddc0
void CEntityVibrator::FUN_1411cddc0(CString strModel, unsigned char nMode)
{
    if (m_entity == (egf::Entity*)0) return;
    if (strModel.GetLength() != 0) {
        if (m_c8.Compare(strModel) != 0) {
            efd::AssetID asset;
            CString strUrn = "urn:gamebryo-scenegraph:" + strModel;
            {
                efd::utf8string strTmp((const char*)strUrn);
                asset = strTmp;
            }
            bool bHas;
            {
                efd::utf8string strMesh("Mesh");
                bHas = m_entity.operator->()->GetModel()->ContainsModel(strMesh);
            }
            if (bHas) {
                FUN_140de8bd0(m_entity.operator->(), 0x770e5fc6, &asset);
                m_c8 = strModel;
            }
        }
    }
    m_d0 = nMode;
    if (m_d0 == 1) {
        bool bOn = true;
        FUN_14098c6e0((class Unk_CachedEntity*)(m_entity.operator->()), 0xa0b6b179, bOn);
    }
    if (m_d0 == 2) {
        bool bOff = false;
        FUN_14098c6e0((class Unk_CachedEntity*)(m_entity.operator->()), 0xa0b6b179, bOff);
    }
}
MS2_REPLACE_METHOD(0x1411CDDC0, CEntityVibrator, FUN_1411cddc0, 614, 0x02DD91E3);

// @0x1411ce070
NxVec3 Unk_VibNiMat::FUN_1411ce070(int nCol) const
{
    return NxVec3(m_afEntry[0][nCol], m_afEntry[1][nCol], m_afEntry[2][nCol]);
}
MS2_REPLACE_METHOD(0x1411CE070, Unk_VibNiMat, FUN_1411ce070, 132, 0x73C3E33A);

