// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See gameobject.h.
// MS2-UNIT: client\ms2\gameobject.cpp
// MS2-RANGE: 0x14123b2b0-0x14123f2d0 .text$mn
// MS2-RANGE: 0x1400ea350-0x1400ea4e0 .text$di
// MS2-RANGE: 0x142cade80-0x142cadf10 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@IHU?$less@I@std@@V?$allocator@U?$pair@$$CBIH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x14123e550 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCAnimationManager@@@@QEAA@XZ 0x14123eb30 ; unique
// MS2-PIN: ??0?$MS2Ptr@VUnk_GoField@@@@QEAA@XZ 0x14123eb50 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCAnimationManager@@@@QEAAAEAV1@PEAVCAnimationManager@@@Z 0x14123ec40 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x14123ee60 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14123ee90 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GGameObject@@UEAAPEAXI@Z 0x14123edd0
// MS2-PIN: ??0GameObject@@QEAA@XZ 0x14123b2b0
// (functional: the exe's traits fold the constant SIZE_MAX / 24 in; this STL calls the tag-dispatched helper)
// MS2-PIN: ?max_size@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@@std@@SA_KAEBV?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@@Z 0x14123f250
// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400ea350
// MS2-PIN: ??0?$SmartPointer@VCObjectShadow@@@efd@@QEAA@PEAVCObjectShadow@@@Z 0x14123ea80
// MS2-PIN: ?GetClassDesc@GameObject@@UEBAPEBVClassInfo@efd@@XZ 0x14123ee30
// MS2-PIN: ?TypeCast@GameObject@@UEBA_NIPEAPEAX@Z 0x14123ef50
// MS2-PIN: ?TypeCast@GameObject@@UEBA_NIPEAPEBX@Z 0x14123efa0
// MS2-PIN: ??_7GameObject@@6BIBase@efd@@@ 0x142ec6070
// MS2-PIN: ??_7GameObject@@6BCallbackObject@NiActorManager@@@ 0x142ec6240
// (0x14123f2d0-0x14123f5b0, the PhysX controller holder, belongs to the next obj: unit_14123f5b0.)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gameobject.h"
#include <list>
#include <efd/utf8string.h>
#include <efd/AssetID.h>
#include <efd/Matrix3.h>
#include <egf/FlatModel.h>
#include <NiMatrix3.h>
#include <NiNode.h>
#include <NiAlphaProperty.h>
#include <NiBooleanExtraData.h>
#include <NiFixedString.h>
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/animationmanager.h"
#include "ms2/unnamed/unit_14176f2a0.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

// The client constants table (FUN_1401d3200). Each value is a 0x58-byte record.
class Unk_GoCfgValue
{
public:
    float FUN_1402bac70();
    const float& FUN_140298f40();
    char m_pad[0x58];
};
struct Unk_GoConfig
{
    char m_pad[0xa58];
    Unk_GoCfgValue m_kUpdateRate;       // +0xa58 mesh update passes per second
    Unk_GoCfgValue m_kUpdateDuration;   // +0xab0
};
MS2_CHECK_OFFSET(Unk_GoConfig, m_kUpdateDuration, 0xab0);
Unk_GoConfig* FUN_1401d3200();
void FUN_14108c240(CMeshUpdateGate* pGate, float fInterval);

// The field object a position resolves to (CPtred-counted; held at GameObject+0x60).
class Unk_GoField : public CPtred
{
public:
    virtual void vfunc_1();
    virtual int vfunc_2(NiPoint3 kPos);                  // contains kPos?
    virtual void vfunc_3();
    virtual NiPoint3 vfunc_4(const NiPoint3& kPos);      // kPos snapped to the field
    unsigned __int64 m_nFieldId;                         // +0x18
};
MS2_CHECK_OFFSET(Unk_GoField, m_nFieldId, 0x18);

// The world service (FUN_1403ed2d0).
class Unk_GoWorld
{
public:
    int FUN_141bd19d0(int nId);
    MS2Ptr<Unk_GoField> FUN_141bd3210(NiPoint3 kPos);
    MS2Ptr<Unk_GoField> FUN_141bd3430(unsigned __int64 nFieldId);
    int FUN_141bdb5c0();
};
Unk_GoWorld* FUN_1403ed2d0();

// The object vfunc_26 places at the actor every frame.
class Unk_GoAttachment
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(NiPoint3 kPos, NiPoint3 kDir, float fScale);
};

// The list of objects updated every frame (0x143ab5c68).
class Unk_GoUpdateList
{
public:
    // @0x14123ee80
    static Unk_GoUpdateList* FUN_14123ee80() { return ms_pInstance; }
    void FUN_140a0d130(GameObject* pObject);
    void FUN_140a0d190(GameObject* pObject);
    static Unk_GoUpdateList* ms_pInstance;
};

class Unk_GoModeSvc { public: int FUN_1409f7ea0(); };
Unk_GoModeSvc* FUN_1409f7c90();
int FUN_140ddcc90(Unk_GoModeSvc* pSvc);

class Unk_GoAnimSvc
{
public:
    NiActorManager* FUN_140999440(const egf::EntityID& kId);
    void FUN_1409fad80(egf::EntityID kId, bool b);
};
Unk_GoAnimSvc* FUN_141b6f910();

// The camera manager and its PvP mode.
class Unk_GoCamMode { public: void FUN_1416c5b00(int nId); };
class Unk_GoCamera
{
public:
    int FUN_140af7e30();
    Unk_GoCamMode* FUN_140af2520();
};
Unk_GoCamera* FUN_1409478c0();
struct Unk_GoCamEvent
{
    char m_pad[0x28];
    int m_nTarget;          // +0x28
    int m_nOwner;           // +0x2c
};

// Anchor handles collected by vfunc_27 (16-byte smart handle over the array element).
struct Unk_GoFloat3 { float x, y, z; };
class Unk_GoAnchorPose { public: const Unk_GoFloat3* FUN_140a01180(); };
class Unk_GoAnchor
{
public:
    char m_pad[0xb4];
    Unk_GoAnchorPose m_kPose;   // +0xb4
};
class Unk_GoAnchorPtr
{
public:
    Unk_GoAnchorPtr(const Unk_GoAnchorPtr& o);   // 0x140a00180
    ~Unk_GoAnchorPtr();                 // 0x140a00490
    bool FUN_140a00660(int n) const;    // == NULL
    Unk_GoAnchor* FUN_140ae1940() const;
    void* m_pad[2];
};
efd::Point3 FUN_141b6e150(const Unk_GoFloat3* p);
float FUN_140966f00(NiPoint3 a, efd::Point3 b);

// Scene picking (FUN_1413f98f0).
struct Unk_GoPickHit { efd::Point3* FUN_140ad4bd0(); };
class Unk_GoPickVec
{
public:
    unsigned int FUN_140a17ea0();
    Unk_GoPickHit* FUN_140a17d70(unsigned int nIndex);
};
class Unk_GoPickList { public: Unk_GoPickVec* FUN_140a17e00(); };
class Unk_GoPickListPtr
{
public:
    Unk_GoPickListPtr(Unk_GoPickList* p);   // 0x140a152b0
    ~Unk_GoPickListPtr();                   // 0x140a16120
    Unk_GoPickList* FUN_140a16c00() const;
    Unk_GoPickList* FUN_140a16c30() const;
    void* m_pad[2];
};
class Unk_GoPicker
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual Unk_GoPickList* vfunc_16(const efd::Point3& kOrigin, const efd::Point3& kDir, NiAVObject* pRoot,
        bool b, bool b2, bool b3);
};
Unk_GoPicker* FUN_1413f98f0();

// The shadow mesh (efd::SmartPointer at +0x58; the real class is CObjectShadow : CMesh, unit_14160fb10).
class CObjectShadow : public NiRefObject
{
public:
    void FUN_14160fe10(bool b);
    void FUN_14160fe70(bool b);
    void FUN_14160feb0(int n, const NiPoint3& kPos, const efd::Point3& kUp, float f, bool b);
};

// Scene graph walk (same iterator as cubecraft_1.cpp).
class Unk_CubeSceneIterator
{
public:
    Unk_CubeSceneIterator(NiAVObject* pRoot);
    ~Unk_CubeSceneIterator();
    NiAVObject* FUN_14098e0d0(bool bDescend);
private:
    ATL::CAtlList<NiAVObject*> m_kPending;
};
MS2_CHECK_SIZE(Unk_CubeSceneIterator, 0x30);
extern NiFixedString DAT_143ae50b0;     // extra data key (alpha blending)

// entity helpers
const egf::EntityID* FUN_1408b76f0(egf::Entity* pEntity);
unsigned __int64 FUN_140affe40(egf::Entity* pEntity);   // egf::Entity::GetEntityIDValue
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);
void FUN_1414737d0(egf::Entity* pEntity);
int FUN_1409618c0(egf::Entity* pEntity, unsigned int nProp, efd::Point3* pOut);
void FUN_140a38a50(egf::Entity* pEntity, unsigned int nProp, const efd::Point3& kValue);
void FUN_1409457c0(egf::Entity* pEntity, unsigned int nProp, const float& fValue);
void FUN_14098c6e0(egf::Entity* pEntity, unsigned int nProp, const bool& bValue);
void FUN_140de8bd0(egf::Entity* pEntity, unsigned int nProp, efd::AssetID* pValue);
void FUN_140de0cb0(efd::AssetID* pAsset, const efd::utf8string& strUrn);
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);
bool FUN_140a33ff0(const efd::Point3& kPos);
bool FUN_1409943d0(NiAVObject* pObject);
void FUN_14098f4d0(NiAVObject* pObject, bool b);
void FUN_14098b3e0(NiAVObject* pObject, float f, bool b);
void FUN_140ae1e80(NiAVObject* pObject, float a, float b, float c, float d, egf::EntityID kId);
void FUN_140291bc0(efd::Point3* pAngles);

#define GO_ENTITY() static_cast<egf::Entity*>(m_unk_80)
#define GO_CAMEVENT(p) static_cast<Unk_GoCamEvent*>(p)

// ---- .text$mn ----

// @0x14123b2b0
GameObject::GameObject()
    : m_unk_18(0.0), m_dUnk20(0.5), m_pos28(FLT_MAX, FLT_MAX, FLT_MAX), m_pos34(FLT_MAX, FLT_MAX, FLT_MAX),
      m_unk_40(0), m_spShadow(0), m_unk_70(0), m_kEntityID(egf::kENTITY_INVALID), m_unk_80(0),
      m_pos98(static_cast<const NiPoint3&>(efd::Point3::ZERO)), m_fScaleA4(1.0f), m_fScaleA8(1.0f),
      m_fScaleAC(1.0f), m_unk_b0(0), m_unk_b4(0), m_bUnkB8(true), m_unk_bc(0), m_unk_c0(0), m_unk_c4(0),
      m_unk_c8(0), m_unk_cc(0), m_unk_d0(0), m_mapD8(10), m_unk_108(0), m_bUnk10C(false), m_fUnk110(20.0f),
      m_fUnk114(100.0f), m_unk_118(0), m_unk_11c(0), m_bUnk138(true)
{
    m_spAnimMgr.AssignRaw(new CAnimationManager(this));
    m_pUnk130 = new CMeshUpdateGate;
    float fRate = FUN_1401d3200()->m_kUpdateRate.FUN_1402bac70();
    if (fRate <= 0.0f)
        fRate = 60.0f;
    FUN_14108c240(m_pUnk130, 1.0f / fRate);
    m_pUnk130->FUN_14123ef30(FUN_1401d3200()->m_kUpdateDuration.FUN_1402bac70());
}

// Deleting helper of the mesh update gate (its destructor is FUN_14176f390).
// @0x14123ed90
void* FUN_14123ed90(CMeshUpdateGate* pGate, unsigned int nFlags)
{
    pGate->FUN_14176f390();
    if (nFlags & 1)
        operator delete(pGate, sizeof(CMeshUpdateGate));
    return pGate;
}

// @0x14123b770
GameObject::~GameObject()
{
    m_spAnimMgr = 0;
    if (m_pUnk130)
    {
        // delete m_pUnk130 (the gate's destructor is the plain member FUN_14176f390)
        CMeshUpdateGate* pTmp = m_pUnk130;
        CMeshUpdateGate* pGate = pTmp;
        pGate ? FUN_14123ed90(pGate, 1) : 0;
        m_pUnk130 = 0;
    }
}

// @0x14123b8d0
void GameObject::vfunc_9(void* p)
{
    FUN_14123c430(p);
    FUN_14123bc20(FUN_14123bbd0());
    FUN_14123e350();
    FUN_14123e3a0();
    FUN_14123c280(m_fScaleAC);
    vfunc_23(m_unk_b0);
}
MS2_REPLACE_METHOD(0x14123b8d0, GameObject, vfunc_9, 152, 0x2EFE6F3D);

// @0x14123b970
int GameObject::vfunc_10()
{
    vfunc_49();
    m_unk_b4 = 1;
    return 1;
}
MS2_REPLACE_METHOD(0x14123b970, GameObject, vfunc_10, 53, 0xF0E29504);

// @0x14123b9b0
int GameObject::vfunc_11()
{
    return 1;
}
MS2_REPLACE_METHOD(0x14123b9b0, GameObject, vfunc_11, 11, 0x30025ED0);

// @0x14123b9d0
void GameObject::vfunc_12()
{
    m_unk_c8 = 1;
}
MS2_REPLACE_METHOD(0x14123b9d0, GameObject, vfunc_12, 21, 0xA80730FC);

// @0x14123b9f0
void GameObject::vfunc_13(void* a, efd::Category cat)
{
    m_unk_cc = 1;
    if (m_pUnk130)
        m_pUnk130->FUN_14176f710();
}
MS2_REPLACE_METHOD(0x14123b9f0, GameObject, vfunc_13, 91, 0x2139380C);

// @0x14123ba60
void GameObject::vfunc_14()
{
    if (m_bUnk10C)
    {
        Unk_GoUpdateList::FUN_14123ee80()->FUN_140a0d190(this);
        m_bUnk10C = false;
    }
    m_spAnimMgr->FUN_14099e7d0(this);
    if (m_unk_80)
    {
        FUN_1414737d0(GO_ENTITY());
        m_unk_80 = 0;
    }
    m_kEntityID = egf::kENTITY_INVALID;
}
MS2_REPLACE_METHOD(0x14123ba60, GameObject, vfunc_14, 162, 0x67AF8109);

// @0x14123bb10
void GameObject::vfunc_15()
{
}
MS2_REPLACE_METHOD(0x14123bb10, GameObject, vfunc_15, 6, 0xA9AF6E37);

// @0x14123bb20
void GameObject::vfunc_16()
{
}
MS2_REPLACE_METHOD(0x14123bb20, GameObject, vfunc_16, 6, 0xA9AF6E37);

// @0x14123bb30
void GameObject::FUN_14123bb30(float f)
{
    if (m_unk_b4 == 0)
        return;
    vfunc_53(f);
}
MS2_REPLACE_METHOD(0x14123bb30, GameObject, FUN_14123bb30, 61, 0x081C24E6);

// @0x14123bb80
void GameObject::FUN_14123bb80(CString str)
{
    m_str90 = str;
}
MS2_REPLACE_METHOD(0x14123bb80, GameObject, FUN_14123bb80, 65, 0xF7EFFA72);

// @0x14123bbd0
CString GameObject::FUN_14123bbd0()
{
    return m_str90;
}
MS2_REPLACE_METHOD(0x14123bbd0, GameObject, FUN_14123bbd0, 68, 0x381273B0);

// @0x14123bc20
void GameObject::FUN_14123bc20(CString str)
{
    if (str.IsEmpty())
        return;
    if (m_unk_80)
    {
        FUN_14123bb80(str);
        efd::AssetID kAsset;
        FUN_140de0cb0(&kAsset, (const char*)FUN_14123bbd0());
        if (FUN_1408a9bd0(GO_ENTITY())->ContainsModel("Mesh"))
            FUN_140de8bd0(GO_ENTITY(), 0x770e5fc6, &kAsset);
        else if (FUN_1408a9bd0(GO_ENTITY())->ContainsModel("Actor"))
            FUN_140de8bd0(GO_ENTITY(), 0x12383cea, &kAsset);
    }
}
MS2_REPLACE_METHOD(0x14123bc20, GameObject, FUN_14123bc20, 552, 0xB514144E);

// @0x14123be50
CString GameObject::FUN_14123be50()
{
    return m_str88;
}
MS2_REPLACE_METHOD(0x14123be50, GameObject, FUN_14123be50, 68, 0x38D869C2);

// @0x14123bea0
int GameObject::FUN_14123bea0()
{
    return m_unk_b4;
}
MS2_REPLACE_METHOD(0x14123bea0, GameObject, FUN_14123bea0, 17, 0xBA29CEEF);

// The position snapped to the field it lies in (the last field is cached in m_spField).
// @0x14123bec0
NiPoint3 GameObject::vfunc_17()
{
    NiPoint3 kPos = vfunc_18();
    if (m_unk_80)
        FUN_1409618c0(GO_ENTITY(), 0xfd95ca52, &kPos);
    if (m_spField.get())
    {
        Unk_GoField* pField = m_spField.operator->();
        if (FUN_1403ed2d0()->FUN_141bd3430(pField->m_nFieldId).get())
        {
            if (m_spField->vfunc_2(kPos))
                return kPos;
        }
    }
    m_spField = 0;
    MS2Ptr<Unk_GoField> spField = FUN_1403ed2d0()->FUN_141bd3210(kPos);
    if (spField.get() != 0)
    {
        m_spField = spField;
        return m_spField->vfunc_4(kPos);
    }
    return kPos;
}
MS2_REPLACE_METHOD(0x14123bec0, GameObject, vfunc_17, 594, 0xC7027869);

// @0x14123c120
NiPoint3 GameObject::vfunc_18()
{
    return static_cast<const NiPoint3&>(m_pos28);
}
MS2_REPLACE_METHOD(0x14123c120, GameObject, vfunc_18, 41, 0xAB9D4550);

// @0x14123c150
void GameObject::vfunc_19(efd::Point3 kPos)
{
    if (m_pos28 != kPos)
    {
        if (!FUN_140a33ff0(kPos))
            return;
        m_pos28 = kPos;
        FUN_14123e350();
    }
}
MS2_REPLACE_METHOD(0x14123c150, GameObject, vfunc_19, 99, 0xF1D17081);

// @0x14123c1c0
NiPoint3 GameObject::vfunc_20()
{
    return static_cast<const NiPoint3&>(m_pos34);
}
MS2_REPLACE_METHOD(0x14123c1c0, GameObject, vfunc_20, 41, 0xAC0E8FEC);

// @0x14123c1f0
void GameObject::vfunc_21(efd::Point3 kDir)
{
    if (m_pos34 != kDir)
    {
        if (!FUN_140a33ff0(kDir))
            return;
        m_pos34 = kDir;
        FUN_14123e3a0();
    }
}
MS2_REPLACE_METHOD(0x14123c1f0, GameObject, vfunc_21, 99, 0x27605541);

// @0x14123c260
float GameObject::FUN_14123c260()
{
    return m_fScaleA4;
}
MS2_REPLACE_METHOD(0x14123c260, GameObject, FUN_14123c260, 19, 0xB6274854);

// @0x14123c280
void GameObject::FUN_14123c280(float f)
{
    m_fScaleA4 = f;
    if (m_unk_80)
        FUN_1409457c0(GO_ENTITY(), 0x2d7cad2d, m_fScaleA4);
}
MS2_REPLACE_METHOD(0x14123c280, GameObject, FUN_14123c280, 90, 0xCE9E2EE6);

// @0x14123c2e0
float GameObject::FUN_14123c2e0()
{
    return m_fScaleAC;
}
MS2_REPLACE_METHOD(0x14123c2e0, GameObject, FUN_14123c2e0, 19, 0x80EB773C);

// @0x14123c300
void GameObject::FUN_14123c300(float f)
{
    m_fScaleAC = f;
}
MS2_REPLACE_METHOD(0x14123c300, GameObject, FUN_14123c300, 31, 0x08E280B0);

// @0x14123c330
void GameObject::FUN_14123c330(float f)
{
    m_fScaleA8 = f;
}
MS2_REPLACE_METHOD(0x14123c330, GameObject, FUN_14123c330, 31, 0xA37ED63C);

// @0x14123c360
NiPoint3 GameObject::FUN_14123c360()
{
    return m_pos98;
}
MS2_REPLACE_METHOD(0x14123c360, GameObject, FUN_14123c360, 44, 0x9A487272);

// @0x14123c3a0
void GameObject::vfunc_22(const efd::Point3& kPos)
{
    static_cast<efd::Point3&>(m_pos98) = kPos;
}
MS2_REPLACE_METHOD(0x14123c3a0, GameObject, vfunc_22, 43, 0x831329CD);

// @0x14123c3e0
void GameObject::FUN_14123c3e0(const egf::EntityID& kId)
{
    m_kEntityID = kId;
}
MS2_REPLACE_METHOD(0x14123c3e0, GameObject, FUN_14123c3e0, 41, 0x9FCDB103);

// @0x14123c410
egf::Entity* GameObject::FUN_14123c410()
{
    return GO_ENTITY();
}
MS2_REPLACE_METHOD(0x14123c410, GameObject, FUN_14123c410, 18, 0x841B6891);

// @0x14123c430
void GameObject::FUN_14123c430(void* pEntity)
{
    m_unk_80 = pEntity;
}
MS2_REPLACE_METHOD(0x14123c430, GameObject, FUN_14123c430, 28, 0xF376627F);

// @0x14123c460
egf::EntityID GameObject::FUN_14123c460()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0)
        return m_kEntityID;
    return m_unk_80 != 0 ? *FUN_1408b76f0(GO_ENTITY()) : egf::kENTITY_INVALID;
}

// @0x14123c500
unsigned __int64 GameObject::FUN_14123c500()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0)
        return m_kEntityID.GetValue();
    return m_unk_80 != 0 ? FUN_140affe40(GO_ENTITY()) : egf::kENTITY_INVALID.GetValue();
}

// @0x14123c580
int GameObject::FUN_14123c580()
{
    return m_unk_70;
}
MS2_REPLACE_METHOD(0x14123c580, GameObject, FUN_14123c580, 14, 0x81E2A10F);

// @0x14123c5a0
void GameObject::FUN_14123c5a0(int nId)
{
    m_unk_70 = nId;
}
MS2_REPLACE_METHOD(0x14123c5a0, GameObject, FUN_14123c5a0, 22, 0x161CE143);

// @0x14123c5c0
void GameObject::vfunc_23(int n)
{
    m_unk_b0 = n;
    if (m_unk_80)
    {
        if (m_unk_40 != 0 && n == 0)
        {
            if (FUN_140ddcc90(FUN_1409f7c90()) == 0)
                return;
        }
        bool bHide = n == 0 ? true : false;
        FUN_14098c6e0(GO_ENTITY(), 0xa0b6b179, bHide);
    }
}
MS2_REPLACE_METHOD(0x14123c5c0, GameObject, vfunc_23, 140, 0x130E38CD);

// @0x14123c660
int GameObject::FUN_14123c660()
{
    return m_unk_b0;
}
MS2_REPLACE_METHOD(0x14123c660, GameObject, FUN_14123c660, 17, 0x1F8D7963);

// @0x14123c680
void GameObject::FUN_14123c680(bool b)
{
    if (m_bUnk10C != b)
    {
        m_bUnk10C = b;
        if (b)
            Unk_GoUpdateList::FUN_14123ee80()->FUN_140a0d130(this);
        else
            Unk_GoUpdateList::FUN_14123ee80()->FUN_140a0d190(this);
    }
}
MS2_REPLACE_METHOD(0x14123c680, GameObject, FUN_14123c680, 102, 0x86FCEE12);

// @0x14123c6f0
MS2Ptr<CAnimationManager> GameObject::FUN_14123c6f0()
{
    return m_spAnimMgr;
}

// @0x14123c740
Unk_GoAttachment* GameObject::vfunc_26()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14123c740, GameObject, vfunc_26, 8, 0x7F371472);

// @0x14123c750
void GameObject::vfunc_27(ATL::CAtlArray<Unk_GoAnchorPtr>& kArr)
{
}
MS2_REPLACE_METHOD(0x14123c750, GameObject, vfunc_27, 11, 0x02239C70);

// @0x14123c770
void GameObject::vfunc_28(void* p)
{
}
MS2_REPLACE_METHOD(0x14123c770, GameObject, vfunc_28, 11, 0x02239C70);

// The anchor point nearest to pTarget.
// @0x14123c790
int GameObject::vfunc_29(GameObject* pTarget, efd::Point3* pOut)
{
    if (pTarget == 0)
        return 0;
    ATL::CAtlArray<Unk_GoAnchorPtr> kAnchors;
    if (kAnchors.IsEmpty())
        vfunc_27(kAnchors);
    if (kAnchors.IsEmpty())
        return 0;
    float fMin = FLT_MAX;
    NiPoint3 kBest(efd::Point3::ZERO);
    for (unsigned int i = 0; i < kAnchors.GetCount(); i++)
    {
        Unk_GoAnchorPtr spAnchor(kAnchors[i]);
        if (spAnchor.FUN_140a00660(0))
            continue;
        NiPoint3 kPt(FUN_141b6e150(spAnchor.FUN_140ae1940()->m_kPose.FUN_140a01180()));
        float fDist = FUN_140966f00(pTarget->vfunc_18(), kPt);
        if (fMin > fDist)
        {
            fMin = fDist;
            kBest = kPt;
        }
    }
    *pOut = kBest;
    return 1;
}
MS2_REPLACE_METHOD(0x14123c790, GameObject, vfunc_29, 596, 0xDD12B2AC);

// @0x14123c9f0
NiPoint3 GameObject::vfunc_30(GameObject* pTarget)
{
    if (pTarget == 0)
        return static_cast<const NiPoint3&>(efd::Point3::ZERO);
    efd::Point3 kPos(0.0f, 0.0f, 0.0f);
    if (vfunc_29(pTarget, &kPos) != 0)
        return static_cast<const NiPoint3&>(kPos);
    return vfunc_18();
}
MS2_REPLACE_METHOD(0x14123c9f0, GameObject, vfunc_30, 173, 0xE3707CF8);

// @0x14123cad0
void GameObject::vfunc_31(bool b)
{
    if (m_spShadow)
        m_spShadow->FUN_14160fe10(b);
}
MS2_REPLACE_METHOD(0x14123cad0, GameObject, vfunc_31, 70, 0x1DC06002);

// @0x14123cb20
void GameObject::FUN_14123cb20(bool b)
{
    if (m_spShadow)
        m_spShadow->FUN_14160fe70(b == 0);
}
MS2_REPLACE_METHOD(0x14123cb20, GameObject, FUN_14123cb20, 91, 0xF9AE430E);

// @0x14123cb90
void GameObject::vfunc_32(bool b)
{
    if (m_spShadow)
        m_spShadow->FUN_14160feb0(1, vfunc_18(), efd::Point3::UNIT_Z, 0.0f, b);
}
MS2_REPLACE_METHOD(0x14123cb90, GameObject, vfunc_32, 129, 0x9697C5E7);

// @0x14123cc20
efd::Point3 GameObject::FUN_14123cc20()
{
    return FUN_14123cc80(vfunc_20());
}
MS2_REPLACE_METHOD(0x14123cc20, GameObject, FUN_14123cc20, 85, 0xE0517171);

// @0x14123cc80
efd::Point3 GameObject::FUN_14123cc80(NiPoint3 kRot)
{
    efd::Point3 kDir = -efd::Point3::UNIT_Y;
    efd::Matrix3 kMat;
    kMat.MakeZRotation(-kRot.z * 3.1415927f / 180.0f);
    kDir = kMat * kDir;
    return kDir;
}

// @0x14123cd50
float GameObject::FUN_14123cd50(efd::Point3 kDir)
{
    kDir.z = 0.0f;
    kDir.Unitize();
    NiMatrix3 kMat;
    efd::Point3 kBack = -kDir;
    efd::Point3 kSide = kBack.UnitCross(efd::Point3::UNIT_Z);
    efd::Point3 kAngles;
    kMat.SetCol(0, kSide);
    kMat.SetCol(1, kBack);
    kMat.SetCol(2, efd::Point3::UNIT_Z);
    kMat.ToEulerAnglesXYZ(kAngles.x, kAngles.y, kAngles.z);
    kAngles.z = -(kAngles.z * 180.0f / 3.1415927f);
    FUN_140291bc0(&kAngles);
    return kAngles.z;
}

// @0x14123ce70
float GameObject::FUN_14123ce70(efd::Point3 kDir)
{
    return -(FUN_14123cd50(kDir) * 3.1415927f / 180.0f);
}

// @0x14123cec0
unsigned __int64 GameObject::FUN_14123cec0()
{
    static unsigned int s_nSerial;
    unsigned __int64 nHigh = (unsigned int)m_unk_70;
    unsigned __int64 nId = (nHigh << 32) | ++s_nSerial;
    return nId;
}

// @0x14123cf10
void GameObject::vfunc_33(void* a, void* b)
{
    if (FUN_1409478c0()->FUN_140af7e30() == 0xd)
    {
        int nOwner = FUN_1403ed2d0()->FUN_141bd19d0(GO_CAMEVENT(a)->m_nOwner);
        if (nOwner == 1)
        {
            int nTarget = FUN_1403ed2d0()->FUN_141bd19d0(GO_CAMEVENT(a)->m_nTarget);
            Unk_GoCamMode* pMode = FUN_1409478c0()->FUN_140af2520();
            if (nTarget)
                pMode->FUN_1416c5b00(GO_CAMEVENT(a)->m_nTarget);
        }
    }
}
MS2_REPLACE_METHOD(0x14123cf10, GameObject, vfunc_33, 142, 0x65BBC4C2);

// @0x14123cfb0
void GameObject::vfunc_34(void* p)
{
    if (FUN_1409478c0()->FUN_140af7e30() == 0xd)
    {
        int nOwner = FUN_1403ed2d0()->FUN_141bd19d0(GO_CAMEVENT(p)->m_nOwner);
        if (nOwner == 1)
        {
            int nTarget = FUN_1403ed2d0()->FUN_141bd19d0(GO_CAMEVENT(p)->m_nTarget);
            Unk_GoCamMode* pMode = FUN_1409478c0()->FUN_140af2520();
            if (nTarget)
                pMode->FUN_1416c5b00(GO_CAMEVENT(p)->m_nTarget);
        }
    }
}
MS2_REPLACE_METHOD(0x14123cfb0, GameObject, vfunc_34, 137, 0x1D49A21A);

// @0x14123d040
void GameObject::vfunc_35(void* p)
{
    if (FUN_1409478c0()->FUN_140af7e30() == 0xd && GO_CAMEVENT(p)->m_nOwner != 0)
    {
        int nOwner = FUN_1403ed2d0()->FUN_141bd19d0(GO_CAMEVENT(p)->m_nOwner);
        if (nOwner == 1)
        {
            int nTarget = FUN_1403ed2d0()->FUN_141bd19d0(GO_CAMEVENT(p)->m_nTarget);
            Unk_GoCamMode* pMode = FUN_1409478c0()->FUN_140af2520();
            if (nTarget)
                pMode->FUN_1416c5b00(GO_CAMEVENT(p)->m_nTarget);
        }
    }
}
MS2_REPLACE_METHOD(0x14123d040, GameObject, vfunc_35, 148, 0xA2DEDA48);

// World position of the node named *pStr (a by-value CString the callee destroys; cubecraft_1.cpp passes raw
// storage), falling back to vfunc_18().
// @0x14123d0e0
// MS2-FUNCTIONAL: the by-value CString is a void* slot parameter (shared with cubecraft_1.cpp) destroyed by hand.
int GameObject::vfunc_36(void* pStr, void* b)
{
    CString& str = *static_cast<CString*>(pStr);
    efd::Point3* pOut = static_cast<efd::Point3*>(b);
    if (!str.IsEmpty())
    {
        NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410());
        if (pRoot)
        {
            NiAVObject* pObject = pRoot->GetObjectByName(NiFixedString((const char*)str));
            NiNode* pNode;
            if (pObject && (pNode = NiDynamicCast(NiNode, pObject)) != 0)
            {
                *pOut = pNode->GetWorldTransform().m_Translate;
                str.~CString();
                return 1;
            }
        }
    }
    *pOut = vfunc_18();
    str.~CString();
    return 0;
}
MS2_REPLACE_METHOD(0x14123d0e0, GameObject, vfunc_36, 310, 0x4308DCD8);

// @0x14123d220
NiPoint3 GameObject::vfunc_37()
{
    return static_cast<const NiPoint3&>(efd::Point3::ZERO);
}
MS2_REPLACE_METHOD(0x14123d220, GameObject, vfunc_37, 42, 0x4A7F4E8E);

// Picks the scene along -kDir from kPos: the hit within fRange nearest to kPos (kPos when nothing is hit).
// @0x14123d250
// MS2-FUNCTIONAL: stack slot order of the locals differs from the exe.
NiPoint3 GameObject::vfunc_38(const efd::Point3& kDir, const efd::Point3& kPos, float fRange)
{
    float fDistance = fRange;
    if (kDir == efd::Point3::ZERO)
        return static_cast<const NiPoint3&>(kPos);
    Unk_GoPicker* pPicker = FUN_1413f98f0();
    if (pPicker == 0)
        return static_cast<const NiPoint3&>(kPos);
    NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410());
    if (pRoot == 0)
        return static_cast<const NiPoint3&>(kPos);
    efd::Point3 kStart = kPos + -kDir * fDistance;
    Unk_GoPickListPtr spList(pPicker->vfunc_16(kStart, kDir, pRoot, true, false, false));
    if (spList.FUN_140a16c00() == 0)
        return static_cast<const NiPoint3&>(kPos);
    Unk_GoPickVec* pHits = spList.FUN_140a16c30()->FUN_140a17e00();
    if (pHits->FUN_140a17ea0() == 0)
        return static_cast<const NiPoint3&>(kPos);
    NiPoint3 kBest = static_cast<const NiPoint3&>(*pHits->FUN_140a17d70(0)->FUN_140ad4bd0());
    float fMin = FLT_MAX;
    for (unsigned int i = 0; i < pHits->FUN_140a17ea0(); i++)
    {
        Unk_GoPickHit* pHit = pHits->FUN_140a17d70(i);
        efd::Point3* pPt = pHit->FUN_140ad4bd0();
        if ((kStart - *pPt).Length() <= fDistance)
        {
            float fDist = (kPos - *pPt).Length();
            if (fDist < fMin)
            {
                static_cast<efd::Point3&>(kBest) = *pPt;
                fMin = fDist;
            }
        }
    }
    return kBest;
}
MS2_REPLACE_METHOD(0x14123d250, GameObject, vfunc_38, 837, 0x21B187EE);

// @0x14123d5a0
void GameObject::AnimActivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
}

// @0x14123d5c0
void GameObject::AnimDeactivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
}

// @0x14123d5e0
void GameObject::AnimCompleted(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
}

// @0x14123d600
void GameObject::TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject, NiControllerSequence* pkSeq,
    float fEventTime)
{
}

// @0x14123d620
void GameObject::EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
}

// @0x14123d640
void GameObject::vfunc_39()
{
}
MS2_REPLACE_METHOD(0x14123d640, GameObject, vfunc_39, 6, 0xA9AF6E37);

// @0x14123d650
void GameObject::vfunc_40(float a, float b, float c, float d)
{
    NiAVObject* pNode = FUN_141b6efc0(FUN_14123c410());
    FUN_14123e020(pNode);
    FUN_140ae1e80(pNode, a, b, c, d, FUN_14123c460());
}
MS2_REPLACE_METHOD(0x14123d650, GameObject, vfunc_40, 143, 0x0302EAEA);

// @0x14123d6f0
void GameObject::vfunc_42(float f, bool b)
{
    NiAVObject* pNode = FUN_141b6efc0(FUN_14123c410());
    FUN_14123e020(pNode);
    FUN_14098b3e0(pNode, f, b);
}
MS2_REPLACE_METHOD(0x14123d6f0, GameObject, vfunc_42, 85, 0xA5B4AB6E);

// @0x14123d750
void GameObject::vfunc_41(NiAVObject* pNode, float f, bool b)
{
    FUN_14123e020(pNode);
    FUN_14098b3e0(pNode, f, b);
}
MS2_REPLACE_METHOD(0x14123d750, GameObject, vfunc_41, 67, 0x6912863A);

// @0x14123d7a0
void GameObject::FUN_14123d7a0(CString strKey, int nValue)
{
    int nOld = FUN_14123d870();
    m_mapD8.SetAt(strKey, nValue);
    int nNew = FUN_14123d870();
    if (nOld != nNew)
        FUN_141b6f910()->FUN_1409fad80(FUN_14123c460(), nNew != 0);
}
MS2_REPLACE_METHOD(0x14123d7a0, GameObject, FUN_14123d7a0, 188, 0x5CCD18FC);

// @0x14123d870
int GameObject::FUN_14123d870()
{
    int nValue = 0;
    for (POSITION pos = m_mapD8.GetHeadPosition(); pos != NULL; m_mapD8.GetNext(pos))
    {
        nValue = m_mapD8.GetValueAt(pos);
        if (nValue != 0)
            return nValue;
    }
    return nValue;
}
MS2_REPLACE_METHOD(0x14123d870, GameObject, FUN_14123d870, 129, 0x0E8C2EF0);

// @0x14123d900
void GameObject::FUN_14123d900()
{
    m_mapD8.RemoveAll();
    NiPointer<NiActorManager> spManager = FUN_141b6f910()->FUN_140999440(FUN_14123c460());
    if (spManager)
        FUN_141b6f910()->FUN_1409fad80(FUN_14123c460(), false);
}
MS2_REPLACE_METHOD(0x14123d900, GameObject, FUN_14123d900, 177, 0x5BE69BE5);

// @0x14123d9c0
void GameObject::vfunc_43(float f)
{
    m_unk_108 = f;
}
MS2_REPLACE_METHOD(0x14123d9c0, GameObject, vfunc_43, 31, 0xD80D89BD);

// @0x14123d9f0
void GameObject::vfunc_44(void* p)
{
    static_cast<std::list<NiAVObject*, efd::CustomAllocator<NiAVObject*> >*>(p)->push_back(
        FUN_141b6efc0(FUN_14123c410()));
}
MS2_REPLACE_METHOD(0x14123d9f0, GameObject, vfunc_44, 57, 0x43B2AF2D);

// @0x14123da30
float GameObject::vfunc_46(const efd::Point3& kPos)
{
    m_unk_c4 = (kPos - vfunc_18()).Length();
    return m_unk_c4;
}
MS2_REPLACE_METHOD(0x14123da30, GameObject, vfunc_46, 95, 0xE935AB49);

// @0x14123daa0
float GameObject::FUN_14123daa0(const efd::Point3& kPos)
{
    m_unk_bc = (kPos - vfunc_18()).Length();
    return m_unk_bc;
}
MS2_REPLACE_METHOD(0x14123daa0, GameObject, FUN_14123daa0, 95, 0x1729EB62);

// @0x14123db10
void GameObject::vfunc_47(bool b)
{
    if (!b)
        m_pUnk130->FUN_14176f680(GO_ENTITY());
    m_bUnk138 = b;
}
MS2_REPLACE_METHOD(0x14123db10, GameObject, vfunc_47, 72, 0x2A6660BA);

// @0x14123db60
float GameObject::FUN_14123db60(const efd::Point3& kPos)
{
    m_unk_c0 = (kPos - vfunc_18()).Length();
    return m_unk_c0;
}
MS2_REPLACE_METHOD(0x14123db60, GameObject, FUN_14123db60, 95, 0x9D7BA30B);

// @0x14123dbd0
int GameObject::FUN_14123dbd0()
{
    return m_unk_c8;
}
MS2_REPLACE_METHOD(0x14123dbd0, GameObject, FUN_14123dbd0, 17, 0x690E246B);

// @0x14123dbf0
int GameObject::FUN_14123dbf0()
{
    return m_unk_cc;
}
MS2_REPLACE_METHOD(0x14123dbf0, GameObject, FUN_14123dbf0, 17, 0x03AA79F7);

// @0x14123dc10
int GameObject::vfunc_48()
{
    return m_unk_d0;
}
MS2_REPLACE_METHOD(0x14123dc10, GameObject, vfunc_48, 17, 0x9E46CF83);

// @0x14123dc30
int GameObject::FUN_14123dc30(unsigned int nKey)
{
    std::map<unsigned int, int>::iterator it = m_map120.find(nKey);
    if (it == m_map120.end())
        return 0;
    return it->second;
}
MS2_REPLACE_METHOD(0x14123dc30, GameObject, FUN_14123dc30, 108, 0x2B882049);

// @0x14123dcb0
void GameObject::FUN_14123dcb0(unsigned int nKey, int nValue)
{
    m_unk_11c = nValue;
    m_map120[nKey] = nValue;
}
MS2_REPLACE_METHOD(0x14123dcb0, GameObject, FUN_14123dcb0, 68, 0x4E9D9E8D);

// @0x14123dd00
void GameObject::vfunc_49()
{
}
MS2_REPLACE_METHOD(0x14123dd00, GameObject, vfunc_49, 6, 0xA9AF6E37);

// @0x14123dd10
void GameObject::vfunc_50()
{
    Unk_GoAttachment* pAttachment = vfunc_26();
    if (pAttachment)
    {
        efd::Point3 kOffset(0.0f, 0.0f, 0.0f);
        vfunc_51(&kOffset);
        pAttachment->vfunc_3(static_cast<const efd::Point3&>(vfunc_18()) + kOffset,
            static_cast<const efd::Point3&>(vfunc_20()), FUN_14123c260());
    }
}
MS2_REPLACE_METHOD(0x14123dd10, GameObject, vfunc_50, 341, 0x6736174B);

// @0x14123de70
void GameObject::vfunc_51(efd::Point3* pOffset)
{
    pOffset->y = 0.0f;
    pOffset->x = 0.0f;
    pOffset->z = m_unk_108;
}
MS2_REPLACE_METHOD(0x14123de70, GameObject, vfunc_51, 59, 0xEB312823);

// Eases the scale toward m_fScaleA8 (3 units per second).
// @0x14123dec0
void GameObject::vfunc_52(double fTime)
{
    float fScale = FUN_14123c260() / FUN_14123c2e0();
    if (fScale != m_fScaleA8)
    {
        int bShrink = m_fScaleA8 - fScale > 0.0f ? 0 : 1;
        float fStep = 3.0f * (float)fTime;
        if (bShrink)
            fStep = -fStep;
        fScale += fStep;
        if (bShrink)
        {
            if (fScale < m_fScaleA8)
                fScale = m_fScaleA8;
        }
        else if (fScale > m_fScaleA8)
        {
            fScale = m_fScaleA8;
        }
        FUN_14123c280(fScale * FUN_14123c2e0());
    }
}
MS2_REPLACE_METHOD(0x14123dec0, GameObject, vfunc_52, 337, 0x99EC682A);

// Tags every mesh under pNode with whether it alpha-blends (extra data DAT_143ae50b0).
// @0x14123e020
void GameObject::FUN_14123e020(NiAVObject* pNode)
{
    FUN_14098f4d0(pNode, false);
    Unk_CubeSceneIterator iterator(pNode);
    while (NiAVObject* pObject = iterator.FUN_14098e0d0(true))
    {
        if (FUN_1409943d0(pObject))
        {
            NiBooleanExtraData* pData = NiDynamicCast(NiBooleanExtraData, pObject->GetExtraData(DAT_143ae50b0));
            if (pData == 0)
            {
                NiAlphaProperty* pAlpha = NiDynamicCast(NiAlphaProperty, pObject->GetProperty(NiProperty::ALPHA));
                bool bBlend = pAlpha != 0 && pAlpha->GetAlphaBlending();
                pObject->AddExtraData(DAT_143ae50b0, NiNew NiBooleanExtraData(bBlend));
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14123e020, GameObject, FUN_14123e020, 376, 0x00D89935);

// @0x14123e1a0
void GameObject::vfunc_53(float f)
{
    vfunc_54(f);
    vfunc_50();
    vfunc_32(false);
    vfunc_52((double)f);
}
MS2_REPLACE_METHOD(0x14123e1a0, GameObject, vfunc_53, 113, 0x1AAE6014);

// @0x14123e220
void GameObject::vfunc_54(float f)
{
    if (m_unk_40 != 0 && FUN_140ddcc90(FUN_1409f7c90()) == 0)
    {
        vfunc_56(f);
        return;
    }
    int nMode = FUN_1403ed2d0()->FUN_141bdb5c0();
    float fDuration = 0.0f;
    switch (nMode)
    {
    case 0:
        fDuration = FUN_140f4a450();
        break;
    case 1:
        fDuration = FUN_14123ee40();
        break;
    case 2:
        fDuration = FUN_14123ee40() - FUN_1401d3200()->m_kUpdateDuration.FUN_140298f40();
        break;
    default:
        MS2_ASSERT_AT(0x180, FALSE);
    }
    vfunc_55(f, fDuration);
}
MS2_REPLACE_METHOD(0x14123e220, GameObject, vfunc_54, 289, 0x2B63C729);

// @0x14123e350
void GameObject::FUN_14123e350()
{
    if (m_unk_80)
        FUN_140a38a50(GO_ENTITY(), 0xfd95ca52, m_pos28);
}
MS2_REPLACE_METHOD(0x14123e350, GameObject, FUN_14123e350, 63, 0xC3F81B0A);

// @0x14123e3a0
void GameObject::FUN_14123e3a0()
{
    if (m_unk_80)
        FUN_140a38a50(GO_ENTITY(), 0x68c7c29d, m_pos34);
}
MS2_REPLACE_METHOD(0x14123e3a0, GameObject, FUN_14123e3a0, 63, 0x23D8992C);

// @0x14123e3f0
bool GameObject::vfunc_56(float f)
{
    if (m_bUnk138)
        return m_pUnk130->FUN_14176f410(GO_ENTITY(), f);
    return false;
}
MS2_REPLACE_METHOD(0x14123e3f0, GameObject, vfunc_56, 75, 0xC944CF1B);

// @0x14123e450
bool GameObject::vfunc_55(float a, float b)
{
    if (m_bUnk138)
        return m_pUnk130->FUN_14176f500(GO_ENTITY(), a, b);
    return false;
}
MS2_REPLACE_METHOD(0x14123e450, GameObject, vfunc_55, 87, 0x9DAFC821);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(GameObject);

// The GameObject class info and a second set of the shared header statics (.text$di 0x1400ea210-0x1400ea350 and their
// atexit thunks; gap2 orphan di sweep). The statics sit next to egf::kENTITY_INVALID (0x143ad4c70, initializer
// 0x1400ea350) in .bss, apart from the header_statics_a.h set above (0x143ad50c0..), so this unit's .text$di may span
// two original TUs. GameObject::ms_ClassInfo is the EE_IMPLEMENT_CONCRETE_CLASS_INFO above.
// MS2-RANGE: 0x1400ea210-0x1400ea350 .text$di
// MS2-RANGE: 0x142cade10-0x142cade80 .text$yd
static CString s_strSortTypeNames0[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill0("skill");
static CString s_strStun0("stun");
