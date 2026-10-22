// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uidevelopdialog.h.
// MS2-UNIT: ?\uidevelopdialog.cpp
// MS2-RANGE: 0x1412920b0-0x141294100 .text$mn
// MS2-RANGE: 0x1400eca70-0x1400ecca0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIDevelopDialog@@UEAAHXZ 0x141293c90 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: memmove_s 0x141293fe0
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidevelopdialog.cpp"
// The exe's memmove_s copy is a plain call (no /Oi expansion): the pragma must precede the inline definitions.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include "uidevelopdialog.h"

#include <efd/ServiceManager.h>
#include <efd/IBase.h>
#include <efd/utf8string.h>
#include <ecrPhysX/PropService.h>
#include <egmVisualizers/PropertyVisualizationService.h>
#include <NiPhysXScene.h>

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/hardwareinstancingservice.h"
#include "ms2/placeholder/meshinstancing.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders ----

// The game's effect manager (FUN_1403ed280()).
class Unk_DevEffectMgr
{
public:
    bool FUN_1411a7830();               // effects enabled
    void FUN_1411a7850(bool bOn);
};
Unk_DevEffectMgr* FUN_1403ed280();

// The world (FUN_1403ed2d0()).
class Unk_DevList                       // ATL::CAtlList<efd::SmartPointer<..>> of world objects
{
public:
    Unk_DevList(int nBlock);            // 0x140963ae0
    ~Unk_DevList();                     // 0x1409647c0
    void* FUN_140967000();              // head position
    efd::SmartPointer<efd::IBase>& FUN_140a01110(void* pos);
    void FUN_1409671f0(void** pPos);    // next
private:
    void* m_raw[7];
};
class Unk_DevWorld
{
public:
    PCBase* FUN_141bd0cc0();                                            // the local player
    void* FUN_141bd36d0();                                              // npc tree
    void FUN_141bd2db0(Unk_DevList* pOut, int (*pfnFilter)(void*));     // collect the objects the filter accepts
};
Unk_DevWorld* FUN_1403ed2d0();
static_assert(sizeof(Unk_DevList) == 0x38 && __alignof(Unk_DevList) == 8, "list");
int FUN_141274b80(void* pObj);          // object filter (getexp.cpp)


// The class of the objects FUN_1412937d0 extracts from the world list (a game object).
struct Unk_DevObj : public efd::IBase
{
    static const efd::ClassID CLASS_ID = 0x6200011;
};

// An npc's data record handle (2 pointers); record fields at +0x2d8 / +0x2dc. The npc hands out a Tmp that is copied into
// the Data handle.
struct Unk_DevDataTmp
{
    ~Unk_DevDataTmp();                                  // 0x1406d5390
    void* m_a;
    void* m_b;
};
struct Unk_DevData
{
    Unk_DevData(const Unk_DevDataTmp& o);               // 0x1406cf850
    ~Unk_DevData();                                     // 0x14035e5b0
    bool FUN_1406a9050(int n);
    char* FUN_14035eb90();                              // the record
    void* m_a;
    void* m_b;
};
class Unk_DevNpc : public PCBase
{
public:
    Unk_DevDataTmp FUN_141093270();                     // the npc's data record handle
};

// The npc map iterator and the npc size setters.
struct Unk_DevExtent { float cx, cy; };
void* FUN_1406d6e90();
void FUN_140a7cbe0(void* p);
void* FUN_140a7b840(void* pMap);
void* FUN_140a7b8e0(void* pMap, void* pos);
PCBase* FUN_140a7b650(void* pEntry);
void FUN_140a7b860(void* pMap, void** pPos);
Unk_DevExtent* FUN_140a0a600(Unk_DevExtent* pOut, float cx, float cy);
class Unk_DevBody;
void FUN_141670d50(PCBase* pNpc, Unk_DevExtent kExtent);
Unk_DevBody* FUN_14166d220(PCBase* pNpc);
void FUN_141240520(Unk_DevBody* pBody, float cx, float cy);

class Unk_DevDebugInfo;
extern Unk_DevDebugInfo* DAT_143ad03d0;
void FUN_14116cd50(Unk_DevDebugInfo* p);

// The 16-byte handle FUN_1409e7dc0 looks the movie root up with.
MS2Ptr<AScript> FUN_1409e7dc0(int nLayer, const Scaleform::GFx::Value& v);
void FUN_1409c4a30(AScript* pRoot, const char* szName, float f);

extern char DAT_143b059e8;              // the game framework (service lookup cell)
efd::ServiceManager* FUN_1413f9850();
void* FUN_1401cd190(void* p);
ecrPhysX::PropService* FUN_14120a240(efd::ServiceManager* pServices);
HardwareInstancingService* FUN_14098c5b0(char*);
unsigned FUN_1413d7eb0(HardwareInstancingService*);
MeshInstancing* FUN_1413d7ef0(HardwareInstancingService*, int nIndex, bool bOne);
void FUN_1413f9c40(bool b);
void* FUN_14086d260();
void FUN_1414730a0(void* p, float f);
void FUN_14123c280(void* pObj, float f);
void FUN_14123c330(void* pObj, float f);

efd::utf8string FUN_1414d7990(const efd::utf8string& kName);
CStringW FUN_1401ceea0(const wchar_t* sz, const int& n);
CStringW FUN_14016a730(const char* sz, int n);
const char* FUN_1408ac310(const efd::utf8string& s);
struct Unk_DevInstView { efd::utf8string FUN_14147d2f0(); };   // MeshInstancing member (this=rcx, hidden return=rdx)

// ---- statics (the same header statics as header_statics_a.h, in another order) ----
#ifndef MS2_HOOK_DLL
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyController;
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1412920b0
UIDevelopDialog::UIDevelopDialog()
{
    m_bShowInstancing = true;
    m_bOneInstancing = false;
    m_bPropertyVisualizer = false;
    m_fDropItemHeight = 50.0f;
    m_fDropItemPeriod = 2.0f;
    m_40 = 1;
}

// @0x141292150
UIDevelopDialog::~UIDevelopDialog()
{
}

// @0x141292190
CString UIDevelopDialog::GetTypeName()
{
    return "DevelopDialog";
}

// ---- PropService access (engine inline functions emitted here) ----
// @0x1412938c0
// MS2-FUNCTIONAL: 3 bytes shorter than exe (cast/pointer-arg form unresolved)
ecrPhysX::PropService* FUN_1412938c0(char* pCell)
{
    return FUN_14120a240(reinterpret_cast<efd::ServiceManager*>(FUN_1401cd190(pCell)));
}

// @0x141293bf0
inline efd::Bool ecrPhysX::PropService::GetDebugRender(const efd::utf8string& sceneName)
{
    NiPhysXScene* pScene = GetScene(sceneName);
    if (pScene)
        return pScene->GetDebugRender();
    return false;
}

// @0x1412938a0
egmVisualizers::PropertyVisualizationService* FUN_1412938a0()
{
    return FUN_1413f9850()->GetSystemServiceAs<egmVisualizers::PropertyVisualizationService>();
}

// @0x141292ca0
void UIDevelopDialog::FUN_141292ca0(const CString& strName, const CStringW& strText)
{
    MS2Ptr<ASTextField> spText = GetChild<ASTextField>(strName);
    if (spText.get())
        spText->FUN_1422c4cd0(strText);
}

// @0x1412921e0
void UIDevelopDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASObj obj(2);
    bool bPhysXDebug = false;
    ecrPhysX::PropService* pProps = FUN_1412938c0(&DAT_143b059e8);
    if (pProps != 0)
    {
        efd::utf8string kName("PhysXDefaultSceneName");
        kName = FUN_1414d7990(kName);
        bPhysXDebug = pProps->GetDebugRender(kName);
    }
    obj.FUN_1407cbbe0("physXDebugRender", bPhysXDebug);
    obj.FUN_1407cbbe0("enableEffect", FUN_1403ed280()->FUN_1411a7830());
    obj.FUN_1407cbbe0("showInstancing", m_bShowInstancing);
    obj.FUN_1407cbbe0("reloadMagicData", false);
    obj.FUN_1409c4a30("gameSpeed", 1.0f);
    obj.FUN_1407cbbe0("oneInstancing", m_bOneInstancing);
    obj.FUN_1409c4a30("dropItemHeight", m_fDropItemHeight);
    obj.FUN_1409c4a30("dropItemPeriod", m_fDropItemPeriod);
    obj.FUN_1407cbbe0("propertyVisualizer", m_bPropertyVisualizer);
    unsigned nInstancing = 1;
    {
        efd::SmartPointer<HardwareInstancingService> spInstancing(FUN_14098c5b0(&DAT_143b059e8));
        if ((HardwareInstancingService*)spInstancing != 0)
            nInstancing = FUN_1413d7eb0(spInstancing.operator->());
        obj.FUN_1407cb9c0("instancingMax", nInstancing);
        obj.FUN_1407cb9c0("instancing", nInstancing);
    }
    m_30->Invoke("initData", obj.FUN_1422bb870());
}

// @0x1412924f0
int UIDevelopDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onClickReloadNpcExtent", szMethod) == 0) {
        OnClickReloadNpcExtent();
        return 1;
    }
    else if (_stricmp("onClickClearDebugInfo", szMethod) == 0) {
        OnClickClearDebugInfo();
        return 1;
    }
    else if (_stricmp("onClickResetGameSpeed", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            FUN_141292f50(data);
        }
        return 1;
    }
    else if (_stricmp("OnCheckPhysXDebugRender", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            bool bOn = data.FUN_1422b8a90();
            FUN_141293010(bOn);
        }
        return 1;
    }
    else if (_stricmp("OnCheckEnableEffect", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            bool bOn = data.FUN_1422b8a90();
            FUN_141293150(bOn);
        }
        return 1;
    }
    else if (_stricmp("OnCheckReloadMagicData", szMethod) == 0) {
        return 1;
    }
    else if (_stricmp("OnCheckPropertyVisualizer", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            bool bOn = data.FUN_1422b8a90();
            FUN_1412931c0(bOn);
        }
        return 1;
    }
    else if (_stricmp("OnCheckShowInstancing", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            bool bOn = data.FUN_1422b8a90();
            FUN_141293180(bOn);
        }
        return 1;
    }
    else if (_stricmp("OnCheckOneInstancing", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            bool bOn = data.FUN_1422b8a90();
            int nValue = data.FUN_1422b8a10();
            FUN_141293210(bOn, nValue);
        }
        return 1;
    }
    else if (_stricmp("OnChangeSliderGameSpeed", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            float fValue = data.FUN_1422b8c10();
            FUN_141293360(fValue);
        }
        return 1;
    }
    else if (_stricmp("OnChangeSliderDropItemScale", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            float fValue = data.FUN_1422b8c10();
            FUN_1412932a0(fValue);
        }
        return 1;
    }
    else if (_stricmp("OnChangeSliderCharacterScale", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            float fValue = data.FUN_1422b8c10();
            FUN_141293390(fValue);
        }
        return 1;
    }
    else if (_stricmp("OnChangeSliderInstancing", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nValue = data.FUN_1422b8a10();
            FUN_1412933f0(nValue);
        }
        return 1;
    }
    else if (_stricmp("OnClickApplyDropItemHeight", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            float fValue = data.FUN_1422b8c10();
            FUN_141293680(fValue);
        }
        return 1;
    }
    else if (_stricmp("OnClickApplyDropItemPeriod", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            float fValue = data.FUN_1422b8c10();
            FUN_141293730(fValue);
        }
        return 1;
    }
    return 0;
}

// @0x141292d10
void UIDevelopDialog::OnClickReloadNpcExtent()
{
    FUN_140a7cbe0(FUN_1406d6e90());
    void* pMap = FUN_1403ed2d0()->FUN_141bd36d0();
    for (void* pos = FUN_140a7b840(pMap); pos != 0; FUN_140a7b860(pMap, &pos))
    {
        PCBase* pNpc = FUN_140a7b650(FUN_140a7b8e0(pMap, pos));
        if (pNpc != 0)
        {
            Unk_DevData kData(static_cast<Unk_DevNpc*>(pNpc)->FUN_141093270());
            if (kData.FUN_1406a9050(0) != 0)
                continue;
            Unk_DevExtent kSize;
            FUN_141670d50(pNpc, *FUN_140a0a600(&kSize, *(float*)(kData.FUN_14035eb90() + 0x2d8),
                                               *(float*)(kData.FUN_14035eb90() + 0x2dc)));
            FUN_141240520(FUN_14166d220(pNpc), *(float*)(kData.FUN_14035eb90() + 0x2d8),
                          *(float*)(kData.FUN_14035eb90() + 0x2dc));
            NiPoint3 kPos = pNpc->vfunc_18();
            kPos.z += *(float*)(kData.FUN_14035eb90() + 0x2dc);
            pNpc->vfunc_19(*reinterpret_cast<efd::Point3*>(&kPos));
        }
    }
}

// @0x141293c30
Unk_DevDebugInfo* FUN_141293c30()
{
    return DAT_143ad03d0;
}

// @0x141292f20
void UIDevelopDialog::OnClickClearDebugInfo()
{
    FUN_14116cd50(FUN_141293c30());
}

// @0x141292f50
void UIDevelopDialog::FUN_141292f50(ASData& data)
{
    Scaleform::GFx::Value kValue = data.FUN_1422b9260();
    MS2Ptr<AScript> spRoot = FUN_1409e7dc0(m_28, kValue);
    if (!spRoot)
        return;
    float fSpeed = 1.0f;
    FUN_1409c4a30(spRoot.operator->(), "defaultSpeed", 1.0f);
}

// @0x141293010
void UIDevelopDialog::FUN_141293010(bool bOn)
{
    ecrPhysX::PropService* pProps = FUN_1412938c0(&DAT_143b059e8);
    if (pProps != 0)
    {
        efd::utf8string kName("PhysXDefaultSceneName");
        kName = FUN_1414d7990(kName);
        pProps->SetDebugRender(kName, bOn);
        kName = "PhysXItemSceneName";
        kName = FUN_1414d7990(kName);
        pProps->SetDebugRender(kName, bOn);
    }
}

// @0x141293150
void UIDevelopDialog::FUN_141293150(bool bOn)
{
    FUN_1403ed280()->FUN_1411a7850(bOn);
}

// @0x141293180
void UIDevelopDialog::FUN_141293180(bool bOn)
{
    m_bShowInstancing = bOn;
    FUN_1413f9c40(m_bShowInstancing);
}

// @0x1412931c0
void UIDevelopDialog::FUN_1412931c0(bool bOn)
{
    egmVisualizers::PropertyVisualizationService* pService = FUN_1412938a0();
    if (pService != 0)
    {
        if (bOn)
            pService->EnableVisualization();
        else
            pService->DisableVisualization(false);
    }
}

// @0x141293210
void UIDevelopDialog::FUN_141293210(bool bOn, int nIndex)
{
    m_bOneInstancing = bOn;
    efd::SmartPointer<HardwareInstancingService> spInstancing(FUN_14098c5b0(&DAT_143b059e8));
    if ((HardwareInstancingService*)spInstancing != 0)
        FUN_1413d7ef0(spInstancing.operator->(), nIndex, m_bOneInstancing);
}

// @0x1412932a0
void UIDevelopDialog::FUN_1412932a0(float fScale)
{
    Unk_DevList list(10);
    FUN_1403ed2d0()->FUN_141bd2db0(&list, FUN_141274b80);
    for (void* pos = list.FUN_140967000(); pos != 0; list.FUN_1409671f0(&pos))
    {
        Unk_DevObj* pObj = efd::DynamicCast<Unk_DevObj>(list.FUN_140a01110(pos));
        if (pObj != 0)
            FUN_14123c280(pObj, fScale);
    }
}

// @0x141293360
void UIDevelopDialog::FUN_141293360(float fSpeed)
{
    FUN_1414730a0(FUN_14086d260(), fSpeed);
}

// @0x141293390
void UIDevelopDialog::FUN_141293390(float fScale)
{
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        FUN_14123c330(pPlayer, fScale);
        FUN_14123c280(pPlayer, fScale);
    }
}

// @0x1412933f0
// MS2-FUNCTIONAL: temp/reference-slot layout of the chained CString/utf8string temporaries differs (26 bytes)
void UIDevelopDialog::FUN_1412933f0(int nIndex)
{
    efd::SmartPointer<HardwareInstancingService> spInstancing(FUN_14098c5b0(&DAT_143b059e8));
    if ((HardwareInstancingService*)spInstancing != 0)
    {
        MeshInstancing* pInstancing = FUN_1413d7ef0(spInstancing.operator->(), nIndex, m_bOneInstancing);
        if (pInstancing != 0)
        {
            int nCount = 0;
            if (pInstancing != 0)
                nCount = pInstancing->FUN_14147cf40();
            FUN_141292ca0("m_modelName", FUN_14016a730(FUN_1408ac310(reinterpret_cast<Unk_DevInstView*>(pInstancing)->FUN_14147d2f0()), 0));
            FUN_141292ca0("m_modelCount", FUN_1401ceea0(L"{0}", nCount));
        }
        else
        {
            FUN_141292ca0("m_modelName", L"none");
            FUN_141292ca0("m_modelCount", L"0");
        }
    }
}

// @0x141293680
void UIDevelopDialog::FUN_141293680(float fHeight)
{
    float fValue = fHeight;
    m_fDropItemHeight = fValue;
    Unk_DevList list(10);
    FUN_1403ed2d0()->FUN_141bd2db0(&list, FUN_141274b80);
    for (void* pos = list.FUN_140967000(); pos != 0; list.FUN_1409671f0(&pos))
    {
    }
}

// @0x141293730
void UIDevelopDialog::FUN_141293730(float fPeriod)
{
    float fValue = fPeriod;
    m_fDropItemPeriod = fValue;
    Unk_DevList list(10);
    FUN_1403ed2d0()->FUN_141bd2db0(&list, FUN_141274b80);
    for (void* pos = list.FUN_140967000(); pos != 0; list.FUN_1409671f0(&pos))
    {
    }
}

// memmove_s is emitted only when referenced; the unit's original caller is not recovered.
extern "C" errno_t Unk_DevMoveUser(void* d, size_t n, const void* s, size_t c) { return memmove_s(d, n, s, c); }

MS2_REPLACE_METHOD(0x141292190, UIDevelopDialog, GetTypeName, 61, 0x4FD270B2);
MS2_REPLACE_METHOD(0x141292CA0, UIDevelopDialog, FUN_141292ca0, 103, 0xBC29E5C6);
MS2_REPLACE_METHOD(0x1412921E0, UIDevelopDialog, OnLoadComplete, 766, 0xD1127567);
MS2_REPLACE_METHOD(0x1412924F0, UIDevelopDialog, vfunc_28, 1880, 0x9BE36AD3);
MS2_REPLACE_METHOD(0x141292D10, UIDevelopDialog, OnClickReloadNpcExtent, 516, 0x628568E3);
MS2_REPLACE_METHOD(0x141292F20, UIDevelopDialog, OnClickClearDebugInfo, 27, 0x392AD279);
MS2_REPLACE_METHOD(0x141292F50, UIDevelopDialog, FUN_141292f50, 177, 0xB6B56AC3);
MS2_REPLACE_METHOD(0x141293010, UIDevelopDialog, FUN_141293010, 308, 0x29055F34);
MS2_REPLACE_METHOD(0x141293150, UIDevelopDialog, FUN_141293150, 36, 0x43D1CDB9);
MS2_REPLACE_METHOD(0x141293180, UIDevelopDialog, FUN_141293180, 51, 0x93D57A67);
MS2_REPLACE_METHOD(0x1412931C0, UIDevelopDialog, FUN_1412931c0, 69, 0x3B519A77);
MS2_REPLACE_METHOD(0x141293210, UIDevelopDialog, FUN_141293210, 135, 0x3B865883);
MS2_REPLACE_METHOD(0x1412932A0, UIDevelopDialog, FUN_1412932a0, 177, 0xF15F58BE);
MS2_REPLACE_METHOD(0x141293360, UIDevelopDialog, FUN_141293360, 39, 0xF7BF200F);
MS2_REPLACE_METHOD(0x141293390, UIDevelopDialog, FUN_141293390, 78, 0x082773F1);
MS2_REPLACE_METHOD(0x141293680, UIDevelopDialog, FUN_141293680, 159, 0xD7516B3E);
MS2_REPLACE_METHOD(0x141293730, UIDevelopDialog, FUN_141293730, 159, 0x34F6DB2E);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caedd0-0x142caee90 .text$yd
