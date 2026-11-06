// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\decoeditservice.cpp
// MS2-RANGE: 0x1400e6d40-0x1400e7190 .text$di
// MS2-RANGE: 0x14116f6a0-0x141177ee0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@H@ATL@@SA_NAEBH0@Z 0x141171290 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VEditBrush@@@@UUnk_BrushKeyTraits@@V?$CElementTraits@V?$MS2Ptr@VEditBrush@@@@@ATL@@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x141171790 ; unique
// MS2-PIN: ?GetRefCount@DecoEditService@@UEBAIXZ 0x141171880 ; unique
// MS2-PIN: ?TypeCast@DecoEditService@@UEBA_NIPEAPEAX@Z 0x141173a40 ; unique
// MS2-PIN: ?TypeCast@DecoEditService@@UEBA_NIPEAPEBX@Z 0x141173a90 ; unique
// MS2-PIN: ?FindPos@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@PEAVNiNode@@@@QEBAPEAXAEBQEAVNiNode@@PEAX@Z 0x141175b30 ; unique
// MS2-PIN: ?GetNext@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@PEAVNiNode@@@@QEBAAEBQEAVNiNode@@AEAPEAX@Z 0x141175c50 ; unique
// MS2-PIN: ?TypeCast@DecoItem@@UEBA_NIPEAPEAX@Z 0x1411767a0 ; unique
// MS2-PIN: ?TypeCast@DecoItem@@UEBA_NIPEAPEBX@Z 0x1411767f0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_cat@@YAXXZ 0x1400e6e80
// MS2-PIN: ??__Es_pointer@@YAXXZ 0x1400e6eb0
// MS2-PIN: ??__Es_pointer2@@YAXXZ 0x1400e7060
// MS2-PIN: memmove_s 0x141173de0
// MS2-PIN: ??1?$SmartPointer@VNiMeshHWInstance@@@efd@@QEAA@XZ 0x141175490
// MS2-PIN: ??BAtomicRefCount@efd@@QEAAIXZ 0x141171aa0
// MS2-PIN: ??C?$SmartPointer@VNiDataStream@@@efd@@QEBAPEAVNiDataStream@@XZ 0x1411778c0
// MS2-PIN: ??_7DecoEditService@@6BISystemService@efd@@@ 0x142eb4e58
// MS2-PIN: ??_7?$TSingleton@VDecoEditService@@@@6B@ 0x142eb4e48
// MS2-PIN: ??_7DecoEditService@@6B?$TSingleton@VDecoEditService@@@@@ 0x142eb4f28
// MS2-PIN: ??_7DecoItem@@6BIBase@efd@@@ 0x142eb5268
// MS2-PIN: ??_7DecoItem@@6BCallbackObject@NiActorManager@@@ 0x142eb5438
// DecoEditService, DecoItem and DecoLayer: the housing deco editor (see decoeditservice.h). The container glue of the
// exe (CRBMap / CAtlMap / CAtlArray / MS2Ptr / SmartPointer instances and the NiShadowGenerator inline members) comes
// from the real templates here.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\decoeditservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/os.h"
#include <atlcoll.h>
#include <efd/MessageService.h>
#include <efd/ServiceManager.h>
#include <efd/Point3.h>
#include <NiMesh.h>
#include <NiMeshHWInstance.h>
#include <NiInstancingUtilities.h>
#include <NiActorManager.h>
#include <NiShadowGenerator.h>
#include <NiMaterialLibrary.h>
#include <NiSkinningMeshModifier.h>   // C3: NiSkinningMeshModifier::ms_RTTI
#include <efd/Point2.h>   // C3: efd::Point2::ZERO
#include "decoeditservice.h"
#include "worldservice.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/windowservice.h"

// ---- services reached through globals ----
efd::MessageService* FUN_1413f9830();
// The scene service (slot 19 hands a scene graph to the world for a game object's key).
class Unk_DecoSceneSvc
{
public:
    virtual void vfunc_0();   virtual void vfunc_1();   virtual void vfunc_2();   virtual void vfunc_3();
    virtual void vfunc_4();   virtual void vfunc_5();   virtual void vfunc_6();   virtual void vfunc_7();
    virtual void vfunc_8();   virtual void vfunc_9();   virtual void vfunc_10();  virtual void vfunc_11();
    virtual void vfunc_12();  virtual void vfunc_13();  virtual void vfunc_14();  virtual void vfunc_15();
    virtual void vfunc_16();  virtual void vfunc_17();  virtual void vfunc_18();
    virtual void vfunc_19(NiNodePtr spNode, egf::EntityID kId);
};
void* FUN_1413f9870();   // C3: was FUN_1413f9870
class CMainSystem;
class CMainSystem   // C3: member view for the former free stand-ins
{
public:
    double FUN_141473280();
};
class Unk_DecoAnimObj;
struct Unk_DecoAnimHandle { char m_pad[0x40]; };
struct Unk_DecoAnimRec { char m_pad0[8]; Unk_DecoAnimHandle m_hnd; int m_nSeq; };   // m_nSeq +0x48 (FUN_1411766b0)
// The animation service (animationmanager.cpp); play by name is its member.
class Unk_AnimSvc { public: bool FUN_1409a1fc0(const egf::EntityID& entityID, const efd::utf8string& sequenceName, float fBlend, bool bForce);
    bool FUN_1411766b0(const egf::EntityID& kId, unsigned int nSeq, float fSpeed, bool bLoop); };   // 0x1411766b0 (C3: MS2's 4-arg AnimationService::SetTargetAnimation by id, like FUN_1409a1fc0 by name)
class Unk_DecoAnimSvc : public Unk_AnimSvc {};   // C3: its FUN_1409991a0 was AnimationService::ContainsEntity (0x1409991a0), see below
#include <egmAnimation/AnimationService.h>
// The animation service's protected actor table, opened up like reactor.cpp's Unk_RxAnimAccess.
struct Unk_DecoAnimAccess : egmAnimation::AnimationService
{ using AnimationService::ActorEntry; using AnimationService::ContainsEntity; };
class Unk_AnimSvc* FUN_1410a68d0();   // C3: was FUN_1410a68d0
struct Unk_DecoModelCache { char m_pad[0x10]; };

// ---- entities ----
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);
const void* FUN_1408b76f0(const void* pEntity);
void* FUN_1408b6b20(void* pDst, const void* pSrc);
void FUN_140ae1e80(NiAVObject* pObject, float a, float b, float c, float d, egf::EntityID kId);
CString FUN_141b6ed00(const CString& strPath);

// ---- scene helpers ----
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);                              // 0x14098cb80
    ~Unk_NodeQueue();                                               // 0x14098cf00
    NiAVObject* Next(bool bAddChildren);                            // 0x14098e0d0
private:
    ATL::CAtlList<NiAVObject*> m_list;
};
MS2_CHECK_SIZE(Unk_NodeQueue, 0x30);
void FUN_140aacb60(NiAVObject* pObject, const NiTransform& xf);     // SetLocalTransform
extern NiFixedString DAT_143ae51e8;                                          // material tables
extern NiFixedString DAT_143ae5278;

// ---- xml (game TinyXML) ----
class TiXmlElement                                                  // the game's TiXmlElement (0x90 bytes)
{
public:
    TiXmlElement(const char* pszValue);                             // 0x14086f2f0
private:
    char m_pad[0x90];
};
MS2_CHECK_SIZE(TiXmlElement, 0x90);
class TiXmlNode   // C3: member view for the former FUN_14086e090 stand-in
{
public:
    class TiXmlNode* LinkEndChild(class TiXmlNode*);
};
class Unk_XmlNode   // C3: member view for the former free stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
void XmlSetAttr(class TiXmlElement*, const char*, const CString&);   // C3: was FUN_140874050
int XmlGetAttr(class TiXmlElement*, class NiTransform&);   // C3: was FUN_140874730
void XmlSetAttr(class TiXmlElement*, class NiTransform const&);   // C3: was FUN_140874b10

// ---- cursor ray ----
// (the ray origin / direction are NiPoint3)
struct Unk_PickXY { float x, y; };                                  // cursor position
struct Unk_DecoCursor : public CWindowService { };
void* FUN_140aadf80();   // C3: was FUN_140aadf80
class CPhysXHelper { public: int RayCastFromPoint(Vector3 ptFrom, Vector3& ptHit, Vector3 ptDir, float fLen, int nMask); };   // physxhelper.h (NxMath.h needs NOMINMAX)
struct Unk_DecoCamera : public CameraMgr { };
class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: was FUN_1409f7ca0

// ---- static initializers (.text$di, in this order) ----
// @0x1400e6d40
EE_IMPLEMENT_CONCRETE_CLASS_INFO(DecoEditService);
// @0x1400e6d60
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/decoeditservice_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
// @0x1400e6f20
EE_IMPLEMENT_CONCRETE_CLASS_INFO(DecoItem);
// @0x1400e6f40
static CString s_aSortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static egf::EntityID s_pointer2(0);
static Unk_1402a9d70 s_unk1402a9d702(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static CString s_strSkill4 = "skill";
static CString s_strStun4 = "stun";

// @0x141170c60
inline TSingleton<DecoEditService>::TSingleton() { s_instance = static_cast<DecoEditService*>(this); }

// ---------------------------------------------------------------------------------------------------------------
// DecoEditService
// ---------------------------------------------------------------------------------------------------------------

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x14116f6a0
DecoEditService::DecoEditService()
    : m_nBrush(2), m_spLayer(0), m_mapLayers(10), m_mapBrushes(17, 0.75f, 0.25f, 2.25f, 10)
{
}
#endif

// @0x14116f7b0
DecoEditService::~DecoEditService()
{
}

// @0x14116f850
const char* DecoEditService::GetDisplayName() const
{
    return "DecoEditService";
}
MS2_REPLACE_METHOD(0x14116F850, DecoEditService, GetDisplayName, 13, 0xA86FEE41);

// @0x14116f870
EditBrush* DecoEditService::GetBrush()
{
    MS2Ptr<EditBrush> spBrush(0);
    if (m_mapBrushes.Lookup(m_nBrush, spBrush))
        return spBrush.get();
    return 0;
}
MS2_REPLACE_METHOD(0x14116F870, DecoEditService, GetBrush, 130, 0xCDB9BBF4);

// @0x14116f900
void DecoEditService::SetBrush(int nBrush)
{
    MS2Ptr<EditBrush> spBrush(0);
    if (m_mapBrushes.Lookup(nBrush, spBrush))
        spBrush->vfunc_1();
    m_nBrush = nBrush;
}
MS2_REPLACE_METHOD(0x14116F900, DecoEditService, SetBrush, 127, 0xD9372A8C);

// @0x14116f990
CString DecoEditService::GetXmlPath()
{
    CString strFile;
    strFile.Format("%08d_deco.xml", ((class WorldService*)(WorldService::GetInstance()))->FUN_141bd3060());
    CString strPath;
    strPath.Format("./Data/Xml/Map/%s", (const char*)strFile);
    return strPath;
}
MS2_REPLACE_METHOD(0x14116F990, DecoEditService, GetXmlPath, 181, 0x02760527);

// @0x14116fa50
DecoLayer* DecoEditService::GetLayer()
{
    return m_spLayer.get();
}
MS2_REPLACE_METHOD(0x14116FA50, DecoEditService, GetLayer, 31, 0xEE0FB540);

// @0x14116fa80
bool DecoEditService::AddLayer(CString strName)
{
    MS2Ptr<DecoLayer> spLayer(0);
    if (m_mapLayers.Lookup(strName, spLayer))
        return true;
    {
        MS2Ptr<DecoLayer> spNew(new DecoLayer(strName));
        m_mapLayers.SetAt(strName, spNew);
    }
    return SelectLayer(strName);
}
MS2_REPLACE_METHOD(0x14116FA80, DecoEditService, AddLayer, 380, 0xA7F4EE64);

// @0x14116fc10
bool DecoEditService::RemoveLayer(CString strName)
{
    MS2Ptr<DecoLayer> spLayer(0);
    if (m_mapLayers.Lookup(strName, spLayer))
    {
        if (m_spLayer == spLayer.get())
            m_spLayer = 0;
    }
    return m_mapLayers.RemoveKey(strName);
}
MS2_REPLACE_METHOD(0x14116FC10, DecoEditService, RemoveLayer, 181, 0x9DBAF165);

// @0x14116fcd0
bool DecoEditService::SelectLayer(CString strName)
{
    if (m_mapLayers.Lookup(strName, m_spLayer))
        return true;
    return true;
}
MS2_REPLACE_METHOD(0x14116FCD0, DecoEditService, SelectLayer, 110, 0x87070A29);

// @0x14116fd50
void DecoEditService::SaveXml()
{
    TiXmlDocument doc;
    ((class TiXmlNode*)(void*)(&doc))->LinkEndChild((class TiXmlNode*)(new TiXmlElement("ms2")));
    void* pElement = ((void*)((class Unk_XmlNode*)(void*)(&doc))->FirstChild("ms2"));
    if (pElement != 0)
    {
        for (POSITION pos = m_mapLayers.GetHeadPosition(); pos; m_mapLayers.GetNext(pos))
        {
            MS2Ptr<DecoLayer> spLayer = m_mapLayers.GetValueAt(pos);
            if (spLayer.get() != 0)
                spLayer->SaveXml(static_cast<TiXmlElement*>(pElement));
        }
    }
    doc.SaveFile(GetXmlPath());
}

// @0x14116fef0
void DecoEditService::LoadXml()
{
    m_mapLayers.RemoveAll();
    TiXmlDocument doc;
    bool bLoaded = doc.LoadFile(GetXmlPath(), TIXML_ENCODING_UNKNOWN);
    if (bLoaded)
    {
        void* pRoot = ((void*)((class Unk_XmlNode*)(void*)(&doc))->FirstChild("ms2"));
        if (pRoot == 0)
            return;
        for (void* pLayerXml = ((void*)((class Unk_XmlNode*)(void*)(pRoot))->FirstChild("layer")); pLayerXml != 0; pLayerXml = ((void*)((class Unk_XmlNode*)(void*)(pLayerXml))->NextSibling("layer")))
        {
            CString strName;
            CString strAsset;
            XmlGetAttr((class TiXmlElement*)(pLayerXml), "name", strName);
            XmlGetAttr((class TiXmlElement*)(pLayerXml), "asset", strAsset);
            AddLayer(strName);
            SelectLayer(strName);
            DecoLayer* pLayer = GetLayer();
            if (pLayer != 0)
            {
                for (void* pItemXml = ((void*)((class Unk_XmlNode*)(void*)(pLayerXml))->FirstChild("layer")); pItemXml != 0; pItemXml = ((void*)((class Unk_XmlNode*)(void*)(pItemXml))->NextSibling("layer")))
                {
                    DecoItem* pItem = pLayer->AddItem();
                    if (pItem != 0)
                    {
                        for (void* pGrass = ((void*)((class Unk_XmlNode*)(void*)(pItemXml))->FirstChild("grass")); pGrass != 0; pGrass = ((void*)((class Unk_XmlNode*)(void*)(pGrass))->NextSibling("grass")))
                        {
                            NiTransform xf;
                            XmlGetAttr((class TiXmlElement*)(pGrass), *(class NiTransform*)(&xf));
                            pItem->AddTransform(xf);
                        }
                    }
                }
                pLayer->SetAsset(strAsset);
            }
        }
        RefreshLayers();
    }
}
MS2_REPLACE_METHOD(0x14116FEF0, DecoEditService, LoadXml, 834, 0x679A22EB);

// @0x141170240
void DecoEditService::CollectLayers(ATL::CAtlArray<MS2Ptr<DecoLayer> >& aOut)
{
    for (POSITION pos = m_mapLayers.GetHeadPosition(); pos; m_mapLayers.GetNext(pos))
    {
        MS2Ptr<DecoLayer> spLayer = m_mapLayers.GetValueAt(pos);
        if (spLayer.get() != 0)
            aOut.Add(spLayer);
    }
}
MS2_REPLACE_METHOD(0x141170240, DecoEditService, CollectLayers, 161, 0x9A6414F8);

// @0x1411702f0
void DecoEditService::RefreshLayers()
{
    for (POSITION pos = m_mapLayers.GetHeadPosition(); pos; m_mapLayers.GetNext(pos))
    {
        MS2Ptr<DecoLayer> spLayer = m_mapLayers.GetValueAt(pos);
        if (spLayer.get() != 0)
            spLayer->Refresh();
    }
}
MS2_REPLACE_METHOD(0x1411702F0, DecoEditService, RefreshLayers, 159, 0x85365DB6);

// @0x1411703a0
void DecoEditService::ApplyBrush()
{
    MS2Ptr<EditBrush> spBrush(0);
    if (m_mapBrushes.Lookup(m_nBrush, spBrush))
        spBrush->vfunc_3();
}
MS2_REPLACE_METHOD(0x1411703A0, DecoEditService, ApplyBrush, 116, 0x08B8EAE5);

// @0x141170420
void DecoEditService::SetLayersCulled(int bVisible)
{
    for (POSITION pos = m_mapLayers.GetHeadPosition(); pos; m_mapLayers.GetNext(pos))
    {
        MS2Ptr<DecoLayer> spLayer = m_mapLayers.GetValueAt(pos);
        if (spLayer.get() != 0)
            spLayer->SetCulled(bVisible);
    }
}
MS2_REPLACE_METHOD(0x141170420, DecoEditService, SetLayersCulled, 167, 0xA6E0B546);

// @0x1411704d0
bool DecoEditService::AddTransform(const NiTransform& xf)
{
    DecoLayer* pLayer = GetLayer();
    if (pLayer == 0)
        return false;
    return pLayer->AddTransform(xf);
}
MS2_REPLACE_METHOD(0x1411704D0, DecoEditService, AddTransform, 61, 0x47FC5A4B);

// @0x141170520
void DecoEditService::CollectNear(NiPoint3 pt, float fRadius, ATL::CAtlArray<NiMeshHWInstance*>& aOut)
{
    DecoLayer* pLayer = GetLayer();
    if (pLayer == 0)
        return;
    pLayer->CollectNear(pt, fRadius, aOut);
}

// @0x141170590
efd::AsyncResult DecoEditService::OnInit()
{
    m_mapBrushes.SetAt(0, new PaintBrush);
    m_mapBrushes.SetAt(1, new NoiseBrush);
    FUN_1413f9830()->Subscribe(this, s_cat, 0, false);
    WorldService::GetInstance()->FUN_141bbae40(static_cast<IWorldServiceCallback*>(this));
    return efd::AsyncResult_Complete;
}

// @0x141170730
efd::AsyncResult DecoEditService::OnTick()
{
    MS2Ptr<EditBrush> spBrush(0);
    if (m_mapBrushes.Lookup(m_nBrush, spBrush))
    {
        Unk_PickXY kCursor = *reinterpret_cast<const Unk_PickXY*>(&efd::Point2::ZERO);
        if (((struct Unk_DecoCursor*)FUN_140aadf80())->GetCursorClientPos(&kCursor.x, &kCursor.y) != 0)
        {
            if (reinterpret_cast<Unk_DecoCamera*>(TSingleton<CameraMgr>::GetInstance())->FUN_140a18070() != 0)
            {
                NiPoint3 kOrigin;
                NiPoint3 kDir;
                if (reinterpret_cast<Unk_DecoCamera*>(TSingleton<CameraMgr>::GetInstance())->ScreenToRay(*reinterpret_cast<const NiPoint2*>(&kCursor), kOrigin, kDir) != 0)
                {
                    Vector3 kHit;
                    if (((CPhysXHelper*)FUN_1409f7ca0())->RayCastFromPoint(Vector3(reinterpret_cast<const Vector3&>(kOrigin)), kHit, Vector3(reinterpret_cast<const Vector3&>(kDir)), 10000.0f, 0x201) != 0)
                    {
                        spBrush->SetPtPos(kHit);
                        spBrush->vfunc_2();
                    }
                }
            }
        }
    }
    return efd::AsyncResult_Pending;
}

// @0x141170930
efd::AsyncResult DecoEditService::OnShutdown()
{
    m_mapBrushes.RemoveAll();
    m_mapLayers.RemoveAll();
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD(0x141170930, DecoEditService, OnShutdown, 53, 0xAE3E3C41);

// IWorldServiceCallback slot 1: a map was entered, load its layers.
// @0x141170970
void DecoEditService::vfunc_1(int nMap)
{
    LoadXml();
}
// IWorldServiceCallback subobject is at +0x18: the exe override receives that pointer.
MS2_REPLACE_METHOD_VIA(0x141170970, DecoEditService, IWorldServiceCallback, vfunc_1, 35, 0xAFAF1C62);

// IWorldServiceCallback slot 4: the map was left.
// @0x1411709a0
void DecoEditService::vfunc_4(int nMap)
{
    m_spLayer = 0;
    m_mapLayers.RemoveAll();
}
MS2_REPLACE_METHOD_VIA(0x1411709A0, DecoEditService, IWorldServiceCallback, vfunc_4, 54, 0x87E564D5);

// ---------------------------------------------------------------------------------------------------------------
// DecoItem
// ---------------------------------------------------------------------------------------------------------------

MS2_EMIT_CRT_MEMMOVE_S();

// @0x141173f00
DecoItem::DecoItem() : m_bKfm(false)
{
    m_str88 = "DecoItemKFM";
}

// @0x141173f90
DecoItem::DecoItem(const ATL::CAtlArray<NiTransform>& aXf) : m_bKfm(false)
{
    for (unsigned i = 0; i < aXf.GetCount(); i++)
        AddTransform(aXf[i]);
}

// @0x141174060
DecoItem::~DecoItem()
{
}

// @0x1411740b0
bool DecoItem::SaveXml(TiXmlElement* pParent)
{
    NiAVObject* pObject;
    if (pParent == 0)
        return false;
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        ATL::CAtlArray<NiTransform> aXf;
        Unk_NodeQueue kQueue(pRoot);
        while ((pObject = kQueue.Next(true)) != 0)
        {
            NiMeshHWInstance* pInstance = NiDynamicCast(NiMeshHWInstance, pObject);
            if (pInstance != 0)
            {
                if (!ContainsTransform(((class NiAVObject*)(pInstance))->GetLocalTransform(), aXf))
                    aXf.Add(((class NiAVObject*)(pInstance))->GetLocalTransform());
            }
        }
        for (unsigned i = 0; i < aXf.GetCount(); i++)
        {
            TiXmlElement* pGrass = new TiXmlElement("grass");
            ((class TiXmlNode*)(void*)(pParent))->LinkEndChild((class TiXmlNode*)(pGrass));
            XmlSetAttr((class TiXmlElement*)(pGrass), aXf[i]);
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x1411740B0, DecoItem, SaveXml, 458, 0x173BAD7A);

// @0x141174280
void DecoItem::Refresh()
{
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        pRoot->Update((float)((class CMainSystem*)(void*)(reinterpret_cast<void*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
        pRoot->UpdateNodeBound();
        pRoot->UpdateProperties();
        pRoot->UpdateEffects();
        ((class Unk_DecoSceneSvc*)FUN_1413f9870())->vfunc_19(NiNodePtr(pRoot), FUN_14123c460());
    }
}

// @0x141174380
void DecoItem::SetCulled(int bVisible)
{
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        Unk_NodeQueue kQueue(pRoot);
        NiAVObject* pObject;
        while ((pObject = kQueue.Next(true)) != 0)
        {
            NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
            if (pMesh != 0)
                ((class NiAVObject*)(class NiAVObject*)(pMesh))->SetAppCulled(bVisible == 0);
        }
    }
}
MS2_REPLACE_METHOD(0x141174380, DecoItem, SetCulled, 202, 0xE69FA90E);

// @0x141174450
void DecoItem::SetModel(const CString& strModel)
{
    FUN_14123bb80(strModel);
}

// @0x1411744a0
CString DecoItem::GetModel()
{
    return FUN_14123bbd0();
}
MS2_REPLACE_METHOD(0x1411744A0, DecoItem, GetModel, 58, 0x1334FF9C);

// @0x1411744e0
void DecoItem::ApplyInstancing()
{
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        EnableInstancing(pRoot, 1000, m_bKfm);
        Refresh();
    }
}
MS2_REPLACE_METHOD(0x1411744E0, DecoItem, ApplyInstancing, 98, 0x8936CEED);

// @0x141174550
void DecoItem::vfunc_53(float f)
{
    GameObject::vfunc_53(f);
    if (m_aXf.IsEmpty())
        return;
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        for (unsigned i = 0; i < m_aXf.GetCount(); i++)
        {
            Unk_NodeQueue kQueue(pRoot);
            NiAVObject* pObject;
            while ((pObject = kQueue.Next(true)) != 0)
            {
                NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
                if (pMesh != 0)
                {
                    NiNode* pParent = pMesh->GetParent();
                    if (pParent != 0)
                    {
                        NiPointer<NiMeshHWInstance> spInstance = new (efd::MemHint(efd::MemHint::NONE)) NiMeshHWInstance;
                        if (NiInstancingUtilities::AddMeshInstance(pMesh, spInstance))
                        {
                            spInstance->SetLocalTransform(m_aXf[i]);
                            pParent->AttachChild(spInstance, true);
                            pParent->AttachChild(pMesh, true);
                        }
                    }
                }
            }
        }
        Refresh();
        m_aXf.RemoveAll();
    }
}

// @0x1411747f0
bool DecoItem::IsEditable()
{
    return true;
}
MS2_REPLACE_METHOD(0x1411747F0, DecoItem, IsEditable, 8, 0x71679366);

// @0x141174800
bool DecoItem::LoadNif(CString strAsset)
{
    if (m_unk_80 != 0)
        return true;
    m_bKfm = false;
    m_str88 = "DecoItemNIF";
    SetModel("urn:gamebryo-scenegraph:" + FUN_141b6ed00(strAsset));
    if (!WorldService::GetInstance()->FUN_141bbb1e0(this, 0, 1))
        return false;
    return false;
}

// @0x141174930
bool DecoItem::LoadKfm(CString strAsset)
{
    if (m_unk_80 != 0)
        return true;
    m_bKfm = true;
    m_str88 = "DecoItemKFM";
    FUN_14123bb80("urn:gamebryo-animation:" + FUN_141b6ed00(strAsset));
    if (!WorldService::GetInstance()->FUN_141bbb1e0(this, 0, 1))
        return false;
    return false;
}

// @0x141174a50
bool DecoItem::AddTransform(const NiTransform& xf)
{
    if (!ContainsTransform(xf, m_aXf))
    {
        m_aXf.Add(xf);
        return true;
    }
    return false;
}

// @0x141174ab0
void DecoItem::CollectNear(NiPoint3 pt, float fRadius, ATL::CAtlArray<NiMeshHWInstance*>& aOut)
{
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        Unk_NodeQueue kQueue(pRoot);
        NiAVObject* pObject;
        while ((pObject = kQueue.Next(true)) != 0)
        {
            NiMeshHWInstance* pInstance = NiDynamicCast(NiMeshHWInstance, pObject);
            if (pInstance != 0)
            {
                if (((const Vector3&)((class NiAVObject*)(pInstance))->GetTranslate()).FUN_140965c40((const Vector3&)pt).FUN_140967ac0() < fRadius)
                    aOut.Add(pInstance);
            }
        }
    }
}

// @0x141174bb0
void DecoItem::CollectTransforms(ATL::CAtlArray<NiTransform>& aOut)
{
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        Unk_NodeQueue kQueue(pRoot);
        NiAVObject* pObject;
        while ((pObject = kQueue.Next(true)) != 0)
        {
            NiMeshHWInstance* pInstance = NiDynamicCast(NiMeshHWInstance, pObject);
            if (pInstance != 0)
                aOut.Add(((class NiAVObject*)(pInstance))->GetWorldTransform());
        }
    }
}
MS2_REPLACE_METHOD(0x141174BB0, DecoItem, CollectTransforms, 186, 0xECD1BF5B);

// @0x141174c70
void DecoItem::PlayAnim(const efd::utf8string& strName, float fSpeed, bool bLoop)
{
    Unk_DecoAnimSvc* pAnim = ((class Unk_DecoAnimSvc*)FUN_1410a68d0());
    if (pAnim != 0)
        pAnim->FUN_1409a1fc0(FUN_14123c460(), strName, fSpeed, bLoop);
}

// @0x141174ce0
void DecoItem::PlayAnim(int nSeq, float fSpeed, bool bLoop)
{
    Unk_DecoAnimSvc* pAnim = ((class Unk_DecoAnimSvc*)FUN_1410a68d0());
    if (pAnim != 0)
        pAnim->FUN_1411766b0(FUN_14123c460(), nSeq, fSpeed, bLoop);
}

// @0x141174d50
void DecoItem::vfunc_9(void* p)
{
    GameObject::vfunc_9(p);
    vfunc_19(NiPoint3(0.0f, 0.0f, 0.0f));
    vfunc_21(NiPoint3(0.0f, 0.0f, 0.0f));
}

// @0x141174e40
int DecoItem::vfunc_10()
{
    if (GameObject::vfunc_10() == 0)
        return 0;
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        const NiTPointerList<NiShadowGeneratorPtr>& kList = NiShadowManager::GetShadowGenerators();
        NiTListIterator pos = kList.GetHeadPos();
        while (pos != 0)
        {
            NiShadowGenerator* pLight = kList.GetNext(pos);
            pLight->AttachUnaffectedCasterNode(pRoot);
            pLight->AttachUnaffectedReceiverNode(pRoot);
        }
    }
    Refresh();
    return 1;
}
MS2_REPLACE_METHOD(0x141174E40, DecoItem, vfunc_10, 189, 0x029A4475);

// @0x141174f10
int DecoItem::vfunc_11()
{
    if (GameObject::vfunc_11() == 0)
        return 0;
    ApplyInstancing();
    if (m_bKfm)
    {
        PlayAnim("Idle_A", 1.0f, false);
        FUN_140ae1e80(FUN_141b6efc0(FUN_14123c410()), 0.0f, 1.0f, 0.0f, 0.5f, egf::kENTITY_INVALID);
    }
    return 1;
}

// @0x141175030
void DecoItem::vfunc_12()
{
    GameObject::vfunc_12();
}
MS2_REPLACE_METHOD(0x141175030, DecoItem, vfunc_12, 24, 0xE77ABCEA);

// @0x141175050
void DecoItem::vfunc_14()
{
    GameObject::vfunc_14();
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        const NiTPointerList<NiShadowGeneratorPtr>& kList = NiShadowManager::GetShadowGenerators();
        NiTListIterator pos = kList.GetHeadPos();
        while (pos != 0)
        {
            NiShadowGenerator* pLight = kList.GetNext(pos);
            pLight->DetachUnaffectedCasterNode(pRoot);
            pLight->DetachUnaffectedReceiverNode(pRoot);
        }
    }
}
MS2_REPLACE_METHOD(0x141175050, DecoItem, vfunc_14, 163, 0xC614A242);

// @0x141175100
bool DecoItem::ContainsTransform(const NiTransform& xf, const ATL::CAtlArray<NiTransform>& aXf)
{
    for (unsigned i = 0; i < aXf.GetCount(); i++)
    {
        const NiTransform& kXf = aXf[i];
        if (kXf.m_Translate != xf.m_Translate)
            continue;
        return true;
    }
    return false;
}

// @0x141175190
bool DecoItem::PrepareMesh(NiMesh* pMesh, bool bOverdraw)
{
    if (pMesh == 0)
        return false;
    if (pMesh->FindStreamRef(NiCommonSemantics::POSITION(), 0, NiDataStreamElement::F_UNKNOWN) != 0)
    {
        pMesh->ApplyAndSetActiveMaterial(NiMaterialLibrary::CreateMaterial(*(class NiFixedString const*)(&DAT_143ae51e8)), 0xffffffff);
    }
    else
    {
        NiMeshModifier* pModifier = pMesh->GetModifierByType(&NiSkinningMeshModifier::ms_RTTI);
        if (pModifier != 0)
        {
            if (!((class NiSkinningMeshModifier*)(class NiMeshModifier*)(pModifier))->GetSoftwareSkinned() && bOverdraw)
                pMesh->ApplyAndSetActiveMaterial(NiMaterialLibrary::CreateMaterial(*(class NiFixedString const*)(&DAT_143ae5278)), 0xffffffff);
        }
    }
    return true;
}

// @0x141175250
void DecoItem::EnableInstancing(NiNode* pRoot, unsigned nCount, bool bOverdraw)
{
    Unk_NodeQueue kQueue(pRoot);
    NiAVObject* pObject;
    while ((pObject = kQueue.Next(true)) != 0)
    {
        NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
        if (pMesh != 0 && PrepareMesh(pMesh, bOverdraw))
            NiInstancingUtilities::EnableMeshInstancing(pMesh, nCount, 0, 0, 0x10000, true, false, true, 0, 0, NiDataStreamElement::F_UINT32_1);
    }
}
MS2_REPLACE(0x141175250, DecoItem::EnableInstancing, 227, 0x9323A03E);

// @0x141175340
void DecoItem::UpdateEffects(NiNode* pRoot)
{
    if (pRoot == 0)
        return;
    Unk_NodeQueue kQueue(pRoot);
    NiAVObject* pObject;
    while ((pObject = kQueue.Next(true)) != 0)
    {
        NiDynamicEffect* pEffect = NiDynamicCast(NiDynamicEffect, pObject);
        if (pEffect != 0)
        {
            ((class NiDynamicEffect*)(class NiAVObject*)(pEffect))->DetachAllAffectedNodes();
            pEffect->UpdateEffects();
        }
    }
}
MS2_REPLACE(0x141175340, DecoItem::UpdateEffects, 142, 0xB8110BF2);

// ---------------------------------------------------------------------------------------------------------------
// DecoLayer
// ---------------------------------------------------------------------------------------------------------------

// @0x141176960
DecoLayer::DecoLayer(CString strName) : m_strName(strName), m_strAsset("")
{
}

// @0x1411769f0
DecoLayer::~DecoLayer()
{
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
    {
        WorldService::GetInstance()->FUN_141bbbc60(m_aItems[i]->FUN_14123c460(), 0);
    }
    m_aItems.RemoveAll();
}

// @0x141176b10
bool DecoLayer::SaveXml(TiXmlElement* pParent)
{
    if (pParent == 0)
        return false;
    TiXmlElement* pLayer = new TiXmlElement("layer");
    ((class TiXmlNode*)(void*)(pParent))->LinkEndChild((class TiXmlNode*)(pLayer));
    XmlSetAttr((TiXmlElement*)pLayer, "name", GetName());
    XmlSetAttr((TiXmlElement*)pLayer, "asset", GetAsset());
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
    {
        DecoItem* pItem = m_aItems[i];
        if (pItem != 0)
        {
            TiXmlElement* pItemXml = new TiXmlElement("layer");
            ((class TiXmlNode*)(void*)(pLayer))->LinkEndChild((class TiXmlNode*)(pItemXml));
            pItem->SaveXml(static_cast<TiXmlElement*>(pItemXml));
        }
    }
    return true;
}

// @0x1411766b0
bool Unk_AnimSvc::FUN_1411766b0(const egf::EntityID& kId, unsigned int nSeq, float fSpeed, bool bLoop)
{
    Unk_DecoAnimRec* pRec;
    if (!reinterpret_cast<Unk_DecoAnimAccess*>(this)->ContainsEntity(kId, reinterpret_cast<Unk_DecoAnimAccess::ActorEntry*&>(pRec)))
        return false;
    pRec->m_nSeq = nSeq;
    Unk_DecoAnimObj* pObj = (Unk_DecoAnimObj*)reinterpret_cast<efd::SmartPointer<NiActorManager>&>(pRec->m_hnd).operator NiActorManager*();
    if (pObj == 0)
        return false;
    return reinterpret_cast<NiActorManager*>(pObj)->SetTargetAnimation(nSeq, fSpeed, bLoop);
}

// @0x141176840
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);

// @0x141176d30
void DecoLayer::Refresh()
{
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
    {
        if (m_aItems[i])
            m_aItems[i]->Refresh();
    }
}

// @0x141176dc0
void DecoLayer::SetCulled(int bVisible)
{
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
    {
        if (m_aItems[i])
            m_aItems[i]->SetCulled(bVisible);
    }
}

// @0x141176e60
CString DecoLayer::GetName()
{
    return m_strName;
}
MS2_REPLACE_METHOD(0x141176E60, DecoLayer, GetName, 66, 0xBAEDB7BA);

// @0x141176eb0
CString DecoLayer::GetAsset()
{
    return m_strAsset;
}
MS2_REPLACE_METHOD(0x141176EB0, DecoLayer, GetAsset, 66, 0x869FB423);

// @0x141176f00
bool DecoLayer::IsKfm(CString strAsset)
{
    int nPos = strAsset.Find(".kfm", 0);
    if (nPos != -1)
        return true;
    return false;
}

// @0x141176f70
bool DecoLayer::SetAsset(CString strAsset)
{
    m_strAsset = strAsset;
    DecoItem* pItem = GetEditableItem();
    if (pItem != 0)
        return IsKfm(strAsset) ? pItem->LoadKfm(strAsset) : pItem->LoadNif(strAsset);
    return false;
}

// @0x1411770b0
bool DecoLayer::ChangeAsset(CString strAsset)
{
    if (m_strAsset != "")
    {
        m_strAsset = strAsset;
        ATL::CAtlArray<efd::SmartPointer<DecoItem> > aOld;
        for (unsigned i = 0; i < m_aItems.GetCount(); i++)
            aOld.Add(m_aItems[i]);
        m_aItems.RemoveAll();
        for (unsigned i = 0; i < aOld.GetCount(); i++)
        {
            ATL::CAtlArray<NiTransform> aXf;
            aOld[i]->CollectTransforms(aXf);
            WorldService::GetInstance()->FUN_141bbbc60(aOld[i]->FUN_14123c460(), 0);
            DecoItem* pItem = AddItem(aXf);
            if (pItem != 0)
                IsKfm(GetAsset()) ? pItem->LoadKfm(GetAsset()) : pItem->LoadNif(GetAsset());
        }
        aOld.RemoveAll();
        return true;
    }
    m_strAsset = strAsset;
    return false;
}

// @0x1411773c0
DecoItem* DecoLayer::AddItem()
{
    DecoItem* pItem = new (efd::MemHint(efd::MemHint::NONE)) DecoItem;
    {
        efd::SmartPointer<DecoItem> spItem(pItem);
        m_aItems.Add(spItem);
    }
    return pItem;
}

// @0x141177470
DecoItem* DecoLayer::AddItem(const ATL::CAtlArray<NiTransform>& aXf)
{
    DecoItem* pItem = new (efd::MemHint(efd::MemHint::NONE)) DecoItem(aXf);
    {
        efd::SmartPointer<DecoItem> spItem(pItem);
        m_aItems.Add(spItem);
    }
    return pItem;
}

// @0x141177530
bool DecoLayer::AddTransform(const NiTransform& xf)
{
    DecoItem* pItem = GetEditableItem();
    if (pItem != 0)
        return pItem->AddTransform(xf);
    return false;
}

// @0x141177580
void DecoLayer::CollectNear(NiPoint3 pt, float fRadius, ATL::CAtlArray<NiMeshHWInstance*>& aOut)
{
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
    {
        DecoItem* pItem = m_aItems[i];
        if (pItem != 0)
            pItem->CollectNear(pt, fRadius, aOut);
    }
}

// @0x141177640
DecoItem* DecoLayer::GetEditableItem()
{
    if (m_aItems.GetCount() < 1)
        return AddItem();
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
    {
        DecoItem* pItem = m_aItems[i];
        if (pItem != 0 && pItem->IsEditable())
            return pItem;
    }
    return m_aItems.GetAt(0);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cac760-0x142cac920 .text$yd
