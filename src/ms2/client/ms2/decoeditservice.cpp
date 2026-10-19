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
#include <atlcoll.h>
#include <efd/MessageService.h>
#include <efd/ServiceManager.h>
#include <efd/Point3.h>
#include <NiMesh.h>
#include <NiMeshHWInstance.h>
#include <NiInstancingUtilities.h>
#include <NiShadowGenerator.h>
#include <NiMaterialLibrary.h>
#include "decoeditservice.h"
#include "worldservice.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- services reached through globals ----
WorldService* FUN_1403ed2d0();
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
    virtual void vfunc_19(Unk_NodePtr spNode, const egf::EntityID& kId);
};
Unk_DecoSceneSvc* FUN_1413f9870();
unsigned FUN_141bd3060(WorldService* pWorld);                       // the id of the current map
void* FUN_14086d260();                                              // the clock
double FUN_141473280(void* pClock);                                 // seconds
class Unk_DecoAnimObj { public: bool FUN_1409a20a0(int nSeq, float fSpeed, bool bLoop); };
struct Unk_DecoAnimHandle { Unk_DecoAnimObj* FUN_140998e90(); char m_pad[0x40]; };
struct Unk_DecoAnimRec { char m_pad0[8]; Unk_DecoAnimHandle m_hnd; char m_pad1[0x38]; int m_nSeq; };
class Unk_DecoAnimSvc
{
public:
    void FUN_1409a1fc0(egf::EntityID& kId, const efd::utf8string& strName, float fSpeed, bool bLoop);
    bool FUN_1411766b0(const egf::EntityID& kId, int nSeq, float fSpeed, bool bLoop);      // 0x1411766b0
    bool FUN_1409991a0(const egf::EntityID& kId, Unk_DecoAnimRec** ppRec);
};
Unk_DecoAnimSvc* FUN_1410a68d0();
class Unk_DecoAnimFx { public: void FUN_1409a1fc0(egf::EntityID& kId, void* pName, float fSpeed, bool bLoop); };
struct Unk_DecoModelCache { char m_pad[0x10]; };

// ---- entities ----
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);
const void* FUN_1408b76f0(const void* pEntity);
void* FUN_1408b6b20(void* pDst, const void* pSrc);
void FUN_140ae1e80(NiAVObject* pObject, float a, float b, float c, float d, egf::EntityID kId);
CString FUN_141b6ed00(const CString& strPath);
CString FUN_140298360(const char* pszPrefix, const CString& strPath);
char FUN_1402a5b40(const CString& a, const char* b);                // CString != C string

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
const NiTransform& FUN_140a33f90(NiAVObject* pObject);              // GetLocalTransform
const NiTransform& FUN_1409478e0(NiAVObject* pObject);              // GetWorldTransform
const NiPoint3& FUN_140e69200(NiAVObject* pObject);                 // GetTranslate
void FUN_140aacb60(NiAVObject* pObject, const NiTransform& xf);     // SetLocalTransform
void FUN_140a0b300(NiAVObject* pObject, bool bCulled);              // SetAppCulled
void FUN_141d591d0(NiAVObject* pObject);                            // refresh the dynamic effects of an object
char FUN_14106bee0(NiMeshModifier* pModifier);
NiMaterial* FUN_141d284a0(void* pTable);                            // material from a library table
extern char DAT_143ae51e8;                                          // material tables
extern char DAT_143ae5278;
extern NiRTTI DAT_143afbef0;                                        // the modifier type the overdraw material needs
const NiFixedString& FUN_140a0b280();                               // the POSITION semantic

// ---- xml (game TinyXML) ----
class Unk_TiXmlElement;
void* FUN_14086e090(void* pParent, Unk_TiXmlElement* pChild);       // LinkEndChild
void* FUN_14086e090(void* pParent, void* pChild);
void* FUN_14086f2f0(void* pMemory, const char* pszValue);           // Unk_TiXmlElement(value) on raw memory
class Unk_TiXmlElement                                              // the game's TiXmlElement (0x90 bytes)
{
public:
    Unk_TiXmlElement(const char* pszValue);                         // 0x14086f2f0
private:
    char m_pad[0x90];
};
MS2_CHECK_SIZE(Unk_TiXmlElement, 0x90);
void* FUN_140165cf0(void* pParent, const char* pszName);            // FirstChildElement
void* FUN_140168650(void* pElement, const char* pszName);           // NextSiblingElement
int FUN_1408733e0(void* pElement, const char* pszName, CString& rValue);
void FUN_140874050(void* pElement, const char* pszName, const CString& strValue);
void FUN_140874730(void* pElement, NiTransform* pXf);               // read the transform attributes
void FUN_140874b10(void* pElement, const NiTransform& xf);          // write them
bool FUN_1408710c0(void* pDocument, const char* pszFile);           // SaveFile

// ---- cursor ray ----
// an efd::Point3 with the default constructor 0x1405522f0 (zero)
struct Unk_DecoPoint3
{
    Unk_DecoPoint3();                                               // 0x1405522f0
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_DecoPoint3, 12);
struct Unk_PickXY { float x, y; };                                  // cursor position
extern Unk_PickXY DAT_143b02320;                                    // initial value of the cursor position
struct Unk_DecoCursor { int FUN_141b90e30(float* pX, float* pY); };
Unk_DecoCursor* FUN_140aadf80();
struct Unk_DecoCamera
{
    int FUN_140a18070();                                            // camera ready
    bool FUN_140af0520(const Unk_PickXY& kCursor, Unk_DecoPoint3* pOrigin, Unk_DecoPoint3* pDir);    // cursor ray
};
Unk_DecoCamera* FUN_1409478c0();
struct Unk_DecoCollision
{
    int FUN_14168a230(Unk_DecoPoint3 ptFrom, Unk_StreamPoint& ptHit, Unk_DecoPoint3 ptDir, float fLen, int nMask);
};
Unk_DecoCollision* FUN_1409f7ca0();

// ---- the lights (NiShadowGenerator, see lightunaffectednode.h) ----
class Unk_LUNLight : public NiShadowGenerator {};
struct Unk_LUNList;
Unk_LUNList* FUN_140afe770();
void* FUN_140afe720(Unk_LUNList* list);                             // head position
Unk_LUNLight** FUN_140afe730(Unk_LUNList* list, void** pos);        // advance, returns entry
Unk_LUNLight* FUN_140afe6c0(Unk_LUNLight** entry);                  // entry -> light

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
static Unk_1401cd100 s_pointer2(NULL);
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
    strFile.Format("%08d_deco.xml", FUN_141bd3060(FUN_1403ed2d0()));
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
// MS2-FUNCTIONAL: the exe's `new` of the xml element adds one more EH unwind state than the spelled-out allocation here
void DecoEditService::SaveXml()
{
    TiXmlDocument doc;
    void* pMemRoot = ::operator new(0x90);
    void* pRoot = pMemRoot ? FUN_14086f2f0(pMemRoot, "ms2") : 0;
    FUN_14086e090(&doc, pRoot);
    void* pElement = FUN_140165cf0(&doc, "ms2");
    if (pElement != 0)
    {
        for (POSITION pos = m_mapLayers.GetHeadPosition(); pos; m_mapLayers.GetNext(pos))
        {
            MS2Ptr<DecoLayer> spLayer = m_mapLayers.GetValueAt(pos);
            if (spLayer.get() != 0)
                spLayer->SaveXml(static_cast<Unk_TiXmlElement*>(pElement));
        }
    }
    FUN_1408710c0(&doc, GetXmlPath());
}

// @0x14116fef0
void DecoEditService::LoadXml()
{
    m_mapLayers.RemoveAll();
    TiXmlDocument doc;
    bool bLoaded = doc.FUN_140870fc0(GetXmlPath(), 0);
    if (bLoaded)
    {
        void* pRoot = FUN_140165cf0(&doc, "ms2");
        if (pRoot == 0)
            return;
        for (void* pLayerXml = FUN_140165cf0(pRoot, "layer"); pLayerXml != 0; pLayerXml = FUN_140168650(pLayerXml, "layer"))
        {
            CString strName;
            CString strAsset;
            FUN_1408733e0(pLayerXml, "name", strName);
            FUN_1408733e0(pLayerXml, "asset", strAsset);
            AddLayer(strName);
            SelectLayer(strName);
            DecoLayer* pLayer = GetLayer();
            if (pLayer != 0)
            {
                for (void* pItemXml = FUN_140165cf0(pLayerXml, "layer"); pItemXml != 0; pItemXml = FUN_140168650(pItemXml, "layer"))
                {
                    DecoItem* pItem = pLayer->AddItem();
                    if (pItem != 0)
                    {
                        for (void* pGrass = FUN_140165cf0(pItemXml, "grass"); pGrass != 0; pGrass = FUN_140168650(pGrass, "grass"))
                        {
                            NiTransform xf;
                            FUN_140874730(pGrass, &xf);
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
void DecoEditService::CollectNear(Unk_StreamPoint pt, float fRadius, ATL::CAtlArray<NiMeshHWInstance*>& aOut)
{
    DecoLayer* pLayer = GetLayer();
    if (pLayer != 0)
        pLayer->CollectNear(pt, fRadius, aOut);
}

// @0x141170590
efd::AsyncResult DecoEditService::OnInit()
{
    {
        MS2Ptr<EditBrush> spPaint(new PaintBrush);
        int nKey = 0;
        m_mapBrushes.SetAt(nKey, spPaint);
    }
    {
        MS2Ptr<EditBrush> spNoise(new NoiseBrush);
        int nKey = 1;
        m_mapBrushes.SetAt(nKey, spNoise);
    }
    FUN_1413f9830()->Subscribe(this, s_cat, 0, false);
    FUN_1403ed2d0()->FUN_141bbae40(this ? static_cast<IWorldServiceCallback*>(this) : 0);
    return efd::AsyncResult_Complete;
}

// @0x141170730
efd::AsyncResult DecoEditService::OnTick()
{
    MS2Ptr<EditBrush> spBrush(0);
    if (m_mapBrushes.Lookup(m_nBrush, spBrush))
    {
        Unk_PickXY kCursor = DAT_143b02320;
        if (FUN_140aadf80()->FUN_141b90e30(&kCursor.x, &kCursor.y) != 0)
        {
            if (FUN_1409478c0()->FUN_140a18070() != 0)
            {
                Unk_DecoPoint3 kOrigin;
                Unk_DecoPoint3 kDir;
                if (FUN_1409478c0()->FUN_140af0520(kCursor, &kOrigin, &kDir) != 0)
                {
                    Unk_StreamPoint kHit;
                    if (FUN_1409f7ca0()->FUN_14168a230(Unk_DecoPoint3(kOrigin), kHit, Unk_DecoPoint3(kDir), 10000.0f, 0x201) != 0)
                    {
                        spBrush->FUN_1411974a0(kHit);
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
bool DecoItem::SaveXml(Unk_TiXmlElement* pParent)
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
                if (!ContainsTransform(FUN_140a33f90(pInstance), aXf))
                    aXf.Add(FUN_140a33f90(pInstance));
            }
        }
        for (unsigned i = 0; i < aXf.GetCount(); i++)
        {
            Unk_TiXmlElement* pGrass = new Unk_TiXmlElement("grass");
            FUN_14086e090(pParent, pGrass);
            FUN_140874b10(pGrass, aXf[i]);
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x1411740B0, DecoItem, SaveXml, 458, 0x173BAD7A);

// @0x141174280
// MS2-FUNCTIONAL: the exe's scene call takes a node reference and an entity id that need no caller-side cleanup (no unwind info)
void DecoItem::Refresh()
{
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        pRoot->Update((float)FUN_141473280(FUN_14086d260()), true);
        pRoot->UpdateNodeBound();
        pRoot->UpdateProperties();
        pRoot->UpdateEffects();
        egf::EntityID kId;
        FUN_1413f9870()->vfunc_19(Unk_NodePtr(pRoot), FUN_14123c460(kId));
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
                FUN_140a0b300(pMesh, bVisible == 0);
        }
    }
}
MS2_REPLACE_METHOD(0x141174380, DecoItem, SetCulled, 202, 0xE69FA90E);

// @0x141174450
void DecoItem::SetModel(CString strModel)
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
    if (pRoot == 0)
        return;
    for (unsigned i = 0; i < m_aXf.GetCount(); i++)
    {
        Unk_NodeQueue kQueue(pRoot);
        NiAVObject* pObject;
        while ((pObject = kQueue.Next(true)) != 0)
        {
            NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
            if (pMesh != 0 && pMesh->GetParent() != 0)
            {
                NiNode* pParent = pMesh->GetParent();
                NiPointer<NiMeshHWInstance> spInstance = new (efd::MemHint(efd::MemHint::NONE)) NiMeshHWInstance;
                if (NiInstancingUtilities::AddMeshInstance(pMesh, spInstance))
                {
                    FUN_140aacb60(spInstance, m_aXf[i]);
                    pParent->AttachChild(spInstance, true);
                    pParent->AttachChild(pMesh, true);
                }
            }
        }
    }
    Refresh();
    m_aXf.RemoveAll();
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
    if (FUN_14123c410() != 0)
        return true;
    m_bKfm = false;
    m_str88 = "DecoItemNIF";
    SetModel(FUN_140298360("urn:gamebryo-scenegraph:", FUN_141b6ed00(strAsset)));
    FUN_1403ed2d0()->FUN_141bbb1e0(this, 0, 1);
    return false;
}

// @0x141174930
bool DecoItem::LoadKfm(CString strAsset)
{
    if (FUN_14123c410() != 0)
        return true;
    m_bKfm = true;
    m_str88 = "DecoItemKFM";
    SetModel(FUN_140298360("urn:gamebryo-animation:", FUN_141b6ed00(strAsset)));
    FUN_1403ed2d0()->FUN_141bbb1e0(this, 0, 1);
    return false;
}

// @0x141174a50
bool DecoItem::AddTransform(const NiTransform& xf)
{
    bool bKnown = ContainsTransform(xf, m_aXf);
    if (!bKnown)
        m_aXf.Add(xf);
    return !bKnown;
}

// @0x141174ab0
void DecoItem::CollectNear(Unk_StreamPoint pt, float fRadius, ATL::CAtlArray<NiMeshHWInstance*>& aOut)
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
                Unk_StreamPoint kDelta = *(const Unk_StreamPoint*)&FUN_140e69200(pInstance);
                kDelta = kDelta.FUN_140965c40(pt);
                if (kDelta.FUN_140967ac0() < fRadius)
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
                aOut.Add(FUN_1409478e0(pInstance));
        }
    }
}
MS2_REPLACE_METHOD(0x141174BB0, DecoItem, CollectTransforms, 186, 0xECD1BF5B);

// @0x141174c70
void DecoItem::PlayAnim(const char* pszName, float fSpeed, bool bLoop)
{
    Unk_DecoAnimSvc* pAnim = FUN_1410a68d0();
    if (pAnim != 0)
    {
        egf::EntityID kId = FUN_14123c460();
        pAnim->FUN_1409a1fc0(kId, efd::utf8string(pszName), fSpeed, bLoop);
    }
}

// @0x141174ce0
void DecoItem::PlayAnim(int nSeq, float fSpeed, bool bLoop)
{
    Unk_DecoAnimSvc* pAnim = FUN_1410a68d0();
    if (pAnim != 0)
    {
        egf::EntityID kId = FUN_14123c460();
        pAnim->FUN_1411766b0(kId, nSeq, fSpeed, bLoop);
    }
}

// @0x141174d50
void DecoItem::vfunc_9(void* p)
{
    GameObject::vfunc_9(p);
    vfunc_19(efd::Point3(0.0f, 0.0f, 0.0f));
    vfunc_21(efd::Point3(0.0f, 0.0f, 0.0f));
}

// @0x141174e40
int DecoItem::vfunc_10()
{
    if (GameObject::vfunc_10() == 0)
        return 0;
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0)
    {
        Unk_LUNList* pList = FUN_140afe770();
        void* pos = FUN_140afe720(pList);
        while (pos != 0)
        {
            Unk_LUNLight* pLight = FUN_140afe6c0(FUN_140afe730(pList, &pos));
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
        Unk_LUNList* pList = FUN_140afe770();
        void* pos = FUN_140afe720(pList);
        while (pos != 0)
        {
            Unk_LUNLight* pLight = FUN_140afe6c0(FUN_140afe730(pList, &pos));
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
        if (!(aXf[i].m_Translate != xf.m_Translate))
            return true;
    }
    return false;
}

// @0x141175190
bool DecoItem::PrepareMesh(NiMesh* pMesh, bool bOverdraw)
{
    if (pMesh == 0)
        return false;
    if (pMesh->FindStreamRef(FUN_140a0b280(), 0, NiDataStreamElement::F_UNKNOWN) == 0)
    {
        NiMeshModifier* pModifier = pMesh->GetModifierByType(&DAT_143afbef0);
        if (pModifier != 0)
        {
            if (FUN_14106bee0(pModifier) == 0 && bOverdraw)
                pMesh->ApplyAndSetActiveMaterial(FUN_141d284a0(&DAT_143ae5278), 0xffffffff);
        }
    }
    else
    {
        pMesh->ApplyAndSetActiveMaterial(FUN_141d284a0(&DAT_143ae51e8), 0xffffffff);
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
            FUN_141d591d0(pEffect);
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
        egf::EntityID kId;
        m_aItems[i]->FUN_14123c460(kId);
        FUN_1403ed2d0()->FUN_141bbbc60(kId.GetValue(), 0);
    }
    m_aItems.RemoveAll();
}

// @0x141176b10
bool DecoLayer::SaveXml(Unk_TiXmlElement* pParent)
{
    if (pParent == 0)
        return false;
    Unk_TiXmlElement* pLayer = new Unk_TiXmlElement("layer");
    FUN_14086e090(pParent, pLayer);
    FUN_140874050(pLayer, "name", GetName());
    FUN_140874050(pLayer, "asset", GetAsset());
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
    {
        DecoItem* pItem = m_aItems[i];
        if (pItem != 0)
        {
            Unk_TiXmlElement* pItemXml = new Unk_TiXmlElement("layer");
            FUN_14086e090(pLayer, pItemXml);
            pItem->SaveXml(static_cast<Unk_TiXmlElement*>(pItemXml));
        }
    }
    return true;
}

// @0x1411766b0
bool Unk_DecoAnimSvc::FUN_1411766b0(const egf::EntityID& kId, int nSeq, float fSpeed, bool bLoop)
{
    Unk_DecoAnimRec* pRec;
    if (!FUN_1409991a0(kId, &pRec))
        return false;
    pRec->m_nSeq = nSeq;
    Unk_DecoAnimObj* pObj = pRec->m_hnd.FUN_140998e90();
    if (pObj == 0)
        return false;
    return pObj->FUN_1409a20a0(nSeq, fSpeed, bLoop);
}

// @0x141176840
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);

// @0x141176d30
void DecoLayer::Refresh()
{
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
    {
        if (m_aItems[i] != 0)
            m_aItems[i]->Refresh();
    }
}

// @0x141176dc0
void DecoLayer::SetCulled(int bVisible)
{
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
    {
        if (m_aItems[i] != 0)
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
    return strAsset.Find(".kfm", 0) != -1;
}

// @0x141176f70
bool DecoLayer::SetAsset(CString strAsset)
{
    m_strAsset = strAsset;
    DecoItem* pItem = GetEditableItem();
    if (pItem == 0)
        return false;
    if (IsKfm(strAsset))
        return pItem->LoadKfm(strAsset);
    return pItem->LoadNif(strAsset);
}

// @0x1411770b0
bool DecoLayer::ChangeAsset(CString strAsset)
{
    if (!FUN_1402a5b40(m_strAsset, ""))
    {
        m_strAsset = strAsset;
        return false;
    }
    m_strAsset = strAsset;
    ATL::CAtlArray<efd::SmartPointer<DecoItem> > aOld;
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
        aOld.Add(m_aItems[i]);
    m_aItems.RemoveAll();
    for (unsigned i = 0; i < aOld.GetCount(); i++)
    {
        ATL::CAtlArray<NiTransform> aXf;
        aOld[i]->CollectTransforms(aXf);
        egf::EntityID kId;
        aOld[i]->FUN_14123c460(kId);
        FUN_1403ed2d0()->FUN_141bbbc60(kId.GetValue(), 0);
        DecoItem* pItem = AddItem(aXf);
        if (pItem != 0)
        {
            if (IsKfm(GetAsset()))
                pItem->LoadKfm(GetAsset());
            else
                pItem->LoadNif(GetAsset());
        }
    }
    aOld.RemoveAll();
    return true;
}

// @0x1411773c0
DecoItem* DecoLayer::AddItem()
{
    DecoItem* pItem = new (efd::MemHint(efd::MemHint::NONE)) DecoItem;
    m_aItems.Add(efd::SmartPointer<DecoItem>(pItem));
    return pItem;
}

// @0x141177470
DecoItem* DecoLayer::AddItem(const ATL::CAtlArray<NiTransform>& aXf)
{
    DecoItem* pItem = new (efd::MemHint(efd::MemHint::NONE)) DecoItem(aXf);
    m_aItems.Add(efd::SmartPointer<DecoItem>(pItem));
    return pItem;
}

// @0x141177530
bool DecoLayer::AddTransform(const NiTransform& xf)
{
    DecoItem* pItem = GetEditableItem();
    if (pItem == 0)
        return false;
    return pItem->AddTransform(xf);
}

// @0x141177580
void DecoLayer::CollectNear(Unk_StreamPoint pt, float fRadius, ATL::CAtlArray<NiMeshHWInstance*>& aOut)
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
    if (m_aItems.GetCount() == 0)
        return AddItem();
    for (unsigned i = 0; i < m_aItems.GetCount(); i++)
    {
        DecoItem* pItem = m_aItems[i];
        if (pItem != 0 && pItem->IsEditable())
            return pItem;
    }
    return m_aItems.GetAt(0);
}
