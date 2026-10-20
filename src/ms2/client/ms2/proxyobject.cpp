// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CProxyObject and its proxy manager: see proxyobject.h. w422.
// MS2-UNIT: unit_1416c2c00
// MS2-RANGE: 0x1416c2c00-0x1416c4de0 .text$mn
// MS2-RANGE: 0x1400fe440-0x1400fe730 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CProxyObject@@6BIBase@efd@@@ 0x142f54c98
// MS2-PIN: ??_7CProxyObject@@6BCallbackObject@NiActorManager@@@ 0x142f54e68
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\proxyobject.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "proxyobject.h"
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The ClassInfo initializer is the first dynamic initializer of the object, ahead of the shared header statics.
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CProxyObject);

// The header statics follow in the exe's order (the object's initializers start inside one copy of the shared header
// statics and end inside another: skill, stun, handle | sort names, skill, stun, handle, condition | sort names).
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100
static CString s_skill1 = "skill";                                  // @0x1400fe460
static CString s_stun1 = "stun";                                    // @0x1400fe490
static Unk_Handle1401cd100 s_handle1(0);                            // @0x1400fe4c0
static CString s_sortNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400fe4e0
static CString s_skill2 = "skill";                                  // @0x1400fe5a0
static CString s_stun2 = "stun";                                    // @0x1400fe5d0
static Unk_Handle1401cd100 s_handle2(0);                            // @0x1400fe600
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);      // @0x1400fe620
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400fe670

// ---- unit-local placeholders and externals ----

class WorldService;
WorldService* FUN_1403ed2d0();
int FUN_141bbb1e0(WorldService* pWorld, GameObject* pObject, int bFullInit, unsigned nCameraArg);   // register an object
void FUN_141bbb7f0(WorldService* pWorld, GameObject* pObject, int bImmediate);                    // unregister an object

NiAVObject* FUN_141b6efc0(void* pEntity);                           // the scene root of an entity
void FUN_141567760(NiAVObject* pRoot);
void FUN_141567330(NiAVObject* pRoot, bool bShadow);
void FUN_14098c6e0(egf::Entity* pEntity, unsigned nProperty, bool* pbValue);   // write a bool property
const char* FUN_14099ad40(efd::AssetID* pAsset);
extern int DAT_1439f825c;                                           // the running id of the proxies (counts down)

class Unk_PxEntMgr;
Unk_PxEntMgr* FUN_1409670f0();
struct Unk_PxEntIter { void* m_a; void* m_b; };
void FUN_1411ce5a0(Unk_PxEntMgr* pMgr, Unk_PxEntIter* pIter);
bool FUN_1411ce5f0(Unk_PxEntMgr* pMgr, Unk_PxEntIter* pIter, egf::Entity** ppOut);
egf::Entity* FUN_1411cf440(Unk_PxEntMgr* pMgr, const egf::EntityID& id);
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);
void FUN_1409618c0(egf::Entity* pEntity, unsigned nProperty, Unk_StreamPoint* pOut);   // reads a point property
void FUN_140961880(egf::Entity* pEntity, unsigned nProperty, float* pOut);
int FUN_140998250(egf::Entity* pEntity, unsigned nProperty, efd::AssetID* pOut);   // 0 = read
const egf::EntityID* FUN_1408b76f0(egf::Entity* pEntity);

class Unk_PxServiceMgr;
struct Unk_PxApp
{
    void* m_pad_00;
    efd::SmartPointer<Unk_PxServiceMgr> m_spServiceManager;         // +0x08
};
Unk_PxApp* FUN_14086d260();
Unk_PxServiceMgr* FUN_140af8310(efd::SmartPointer<Unk_PxServiceMgr>* pSmart);    // operator->
void* FUN_140998330(Unk_PxServiceMgr* pMgr);                        // a system service (NULL when absent)

// the proxy manager: the proxies by entity id
class Unk_ProxyMgr
{
public:
    Unk_ProxyMgr();                                                 // 0x1416c3150
    ~Unk_ProxyMgr();                                                // 0x1416c3190
    efd::SmartPointer<CProxyObject> FUN_1416c31c0(efd::AssetID asset, efd::Point3 kPos, efd::Point3 kRot, float fRadius);   // create a proxy and add it to the world
    void FUN_1416c33c0(int bEnable);                                // rebuild the proxies of the map's marker entities
    void FUN_1416c3670();                                           // remove every proxy from the world
    void FUN_1416c3730();                                           // draw the collision shape of every proxy
    efd::SmartPointer<egf::Entity> FUN_1416c37e0(efd::SmartPointer<egf::Entity> spEntity);   // the entity whose proxy shows spEntity

private:
    ATL::CRBMap<egf::EntityID, efd::SmartPointer<CProxyObject> > m_proxies;   // +0x00
    int m_nEnabled;                                                 // +0x30
};

// @0x1416c4b60
void CTwoCircleCollision::FUN_1416c4b60(float fMin)
{
    m_fInnerRadius = fMin;
}

// @0x1416c4bf0
void CTwoCircleCollision::FUN_1416c4bf0(float fMax)
{
    m_fOuterRadius = fMax;
}

// @0x1416c2c00
CProxyObject::CProxyObject()
{
    m_pCollision = 0;
}

// @0x1416c2c60
CProxyObject::~CProxyObject()
{
    if (m_pCollision != 0)
    {
        delete m_pCollision;
        m_pCollision = 0;
    }
}

// @0x1416c2d10
int CProxyObject::vfunc_11()
{
    NiAVObject* pRoot = FUN_141b6efc0(m_unk_80);
    if (pRoot != 0)
    {
        FUN_141567760(pRoot);
        FUN_141567330(pRoot, false);
    }
    bool bVisible = false;
    FUN_14098c6e0(static_cast<egf::Entity*>(m_unk_80), 0x90d6d437, &bVisible);
    return 1;
}

// @0x1416c2d80
void CProxyObject::vfunc_19(efd::Point3 kPos)
{
    GameObject::vfunc_19(kPos);
    if (m_pCollision != 0)
        m_pCollision->vfunc_3(Unk_StreamPoint(kPos.x, kPos.y, kPos.z), Unk_StreamPoint(0, 0, 0), 1.0f);
}

// @0x1416c3ee0
Unk_GoAttachment* CProxyObject::vfunc_26()
{
    return reinterpret_cast<Unk_GoAttachment*>(m_pCollision);
}

// @0x1416c2e70
// MS2-FUNCTIONAL: temporaries/frame layout differ from the exe
int CProxyObject::FUN_1416c2e70(efd::AssetID asset, efd::Point3 kPos, efd::Point3 kRot, float fRadius)
{
    m_str88 = "DropItemNIF";
    vfunc_19(kPos);
    vfunc_21(kRot);
    FUN_14123bb80(CString(FUN_14099ad40(&asset)));
    --DAT_1439f825c;
    FUN_14123c5a0(DAT_1439f825c);
    if (fRadius != 0.0f)
    {
        if (m_pCollision != 0)
            delete m_pCollision;
        m_pCollision = new CTwoCircleCollision();
        m_pCollision->FUN_1416c4b60(1.0f);
        m_pCollision->FUN_1416c4bf0(fRadius);
        m_pCollision->vfunc_3(Unk_StreamPoint(kPos.x, kPos.y, kPos.z), Unk_StreamPoint(kRot.x, kRot.y, kRot.z), 1.0f);
    }
    return 1;
}

// ---- Unk_ProxyMgr ----

// @0x1416c3150
Unk_ProxyMgr::Unk_ProxyMgr()
    : m_proxies(10)
{
    m_nEnabled = 0;
}

// @0x1416c3190
Unk_ProxyMgr::~Unk_ProxyMgr()
{
}

// @0x1416c31c0
// MS2-FUNCTIONAL: temporaries/frame layout differ from the exe
efd::SmartPointer<CProxyObject> Unk_ProxyMgr::FUN_1416c31c0(efd::AssetID asset, efd::Point3 kPos, efd::Point3 kRot, float fRadius)
{
    efd::SmartPointer<CProxyObject> spProxy(EE_NEW CProxyObject());
    if (spProxy->FUN_1416c2e70(asset, kPos, kRot, fRadius) != 0
        && FUN_141bbb1e0(FUN_1403ed2d0(), spProxy, 0, 1) != 0)
        return spProxy;
    return efd::SmartPointer<CProxyObject>(0);
}

// @0x1416c33c0
// MS2-FUNCTIONAL: temporaries/frame layout differ from the exe
void Unk_ProxyMgr::FUN_1416c33c0(int bEnable)
{
    m_nEnabled = bEnable;
    FUN_1416c3670();
    if (bEnable == 0)
        return;
    if (FUN_140998330(FUN_140af8310(&FUN_14086d260()->m_spServiceManager)) == 0)
        return;
    Unk_PxEntIter iter;
    FUN_1411ce5a0(FUN_1409670f0(), &iter);
    egf::Entity* pEntity = 0;
    while (FUN_1411ce5f0(FUN_1409670f0(), &iter, &pEntity))
    {
        egf::FlatModel* pModel = FUN_1408a9bd0(pEntity);
        if (!pModel->ContainsModel(0xbd4f8e8e) && !pModel->ContainsModel(0x48ccc02d) && pModel->ContainsModel(0x9eca2f69))
        {
            Unk_StreamPoint kPos;
            Unk_StreamPoint kRot;
            FUN_1409618c0(pEntity, 0xfd95ca52, &kPos);
            FUN_1409618c0(pEntity, 0x68c7c29d, &kRot);
            float fRadius = 0.0f;
            FUN_140961880(pEntity, 0xa12005f8, &fRadius);
            efd::AssetID asset;
            if (FUN_140998250(pEntity, 0x74bd51ee, &asset) == 0)
            {
                efd::SmartPointer<CProxyObject> spProxy = FUN_1416c31c0(asset, efd::Point3(kPos.x, kPos.y, kPos.z), efd::Point3(kRot.x, kRot.y, kRot.z), fRadius);
                if (spProxy != 0)
                    m_proxies.SetAt(*FUN_1408b76f0(pEntity), spProxy);
            }
        }
    }
}

// @0x1416c3670
void Unk_ProxyMgr::FUN_1416c3670()
{
    for (POSITION pos = m_proxies.GetHeadPosition(); pos != 0; m_proxies.GetNext(pos))
    {
        efd::SmartPointer<CProxyObject> spProxy = m_proxies.GetValueAt(pos);
        FUN_141bbb7f0(FUN_1403ed2d0(), spProxy, 0);
    }
    m_proxies.RemoveAll();
}

// @0x1416c3730
void Unk_ProxyMgr::FUN_1416c3730()
{
    for (POSITION pos = m_proxies.GetHeadPosition(); pos != 0; m_proxies.GetNext(pos))
    {
        CProxyObject* pProxy = m_proxies.GetValueAt(pos);
        if (pProxy != 0 && pProxy->vfunc_26() != 0)
            reinterpret_cast<CTwoCircleCollision*>(pProxy->vfunc_26())->vfunc_1();
    }
}

// @0x1416c37e0
efd::SmartPointer<egf::Entity> Unk_ProxyMgr::FUN_1416c37e0(efd::SmartPointer<egf::Entity> spEntity)
{
    for (POSITION pos = m_proxies.GetHeadPosition(); pos != 0; m_proxies.GetNext(pos))
    {
        CProxyObject* pProxy = m_proxies.GetValueAt(pos);
        if (pProxy->FUN_14123c460() == *FUN_1408b76f0(spEntity))
            return efd::SmartPointer<egf::Entity>(FUN_1411cf440(FUN_1409670f0(), m_proxies.GetKeyAt(pos)));
    }
    return efd::SmartPointer<egf::Entity>(0);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb57b0-0x142cb58b0 .text$yd
