// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPonyTailController: the customize controller of the
// hair-physics ponytail (equip slot 1). It drags the two pony parts of the hair around the head, mirrors the second
// part across the player's median plane and pushes the joint limits to PhysX (CPonyTailPhysXHelper).
// MS2-UNIT: client\ms2\ponytailphysxhelper.cpp
// MS2-RANGE: 0x1416916b0-0x141697140 .text$mn
// MS2-RANGE: 0x1400fbb30-0x1400fbf80 .text$di
// MS2-RANGE: 0x142cb4240-0x142cb43f0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??__Fs_unk1402a9d70@@YAXXZ 0x142cb42b0 ; hand: atexit of header-statics map
// MS2-PIN: ??__Fs_condition2@@YAXXZ 0x142cb4340 ; hand: atexit of s_condition2
// MS2-PIN: ??__Fs_condition3@@YAXXZ 0x142cb43d0 ; hand: atexit of s_condition3
// MS2-PIN: ?GetRTTI@CPonyTailController@@UEBAPEBVNiRTTI@@XZ 0x141695f00 ; manual
// MS2-FUNCTIONAL: extern-heavy; the exe's engine/PhysX/game helpers are opaque FUN_ externs, the long pose functions
// (vfunc_32, FUN_141694650) are restructured around a shared helper.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ponytailphysxhelper.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ponytailphysxhelper.h"
#include "ms2/placeholder/cponytailcontroller.h"
#include "gameobject.h"
#include "equipmodel.h"
#include "kfmmodel.h"
#include "ms2/placeholder/citem.h"
#include <atlcoll.h>
#include <set>
#include <efd/MemObject.h>
#include <efd/ILogger.h>
#include <efd/LoggerMacros.h>
#include <egf/EntityID.h>
#include <NiAVObject.h>
#include <NiNode.h>
#include <NiFixedString.h>
#include <NiFloatsExtraData.h>
#include <NiTransform.h>
#include <NiActorManager.h>
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxD6JointDesc.h>
#pragma pop_macro("max")
#pragma pop_macro("min")
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- exe data ----
extern char DAT_143afa4d8;          // NiNode::ms_RTTI
extern char DAT_143afa4f0;          // NiTexturingProperty::ms_RTTI
extern char DAT_143afa930;          // NiSourceTexture::ms_RTTI
extern char DAT_143afafe0;          // NiFloatsExtraData::ms_RTTI
extern char DAT_143afc8c0;          // RTTI of the joint-carrying scene component
extern char DAT_143afc898;          // assertions throw when set
extern char DAT_1439fc800;          // texture format preferences
extern Vector3 DAT_143b01a60;   // the zero point
extern Vector3 DAT_143a08cf8;   // the up axis
extern Vector3 DAT_143a08cd8;   // reference axis

// ---- out-of-unit callees ----

// Item data flags (item -> data struct -> flags).
struct Unk_PonyItemData
{
    unsigned char FUN_140547130();                              // customizing allowed
    unsigned char FUN_140547170();                              // right button allowed
};
struct Unk_PonyItem { Unk_PonyItemData* FUN_14053ec70(); };     // item -> its data

// The equipped item the controller edits (CPtred, held in MS2Ptr; ?\equipitem.cpp). Only the members this unit calls.
class CEquipItem : public CPtred
{
public:
    Unk_PonyItem* FUN_1411dc7f0();                              // the item
    MS2Ptr<CItem> GetItem();                              // the item object holding the proxy data
    int FUN_1411dc0d0();                                        // number of customizable parts
    void FUN_1411dcc80(CAtlArray<MS2Ptr<Unk_PickTarget> >& aParts);   // the item's model parts
    void FUN_1411dca30(int nSlot, CAtlArray<CString>& aParts);  // attach part names of an equip slot
};
void FUN_14059a1f0(Unk_UserProxyItemData* pData, int nValue);   // stores the pony preset
int FUN_14059a210(Unk_UserProxyItemData* pData);                // reads it

// The local player (a world actor).
class Unk_PonyPlayer : public GameObject
{
public:
    CString FUN_14166dc50();                                    // name of the current action
    MS2Ptr<CEquipItem> FUN_141655e10(int nSlot);                // the item equipped in a slot
    void FUN_14123d7a0(CString strName, int bOn);               // switches a named input mode
};
struct Unk_PonyWorld { Unk_PonyPlayer* FUN_141bd0cc0(); };      // the local player
Unk_PonyWorld* FUN_1403ed2d0();
struct Unk_PonyAnimSvc { NiActorManager* FUN_140999440(const egf::EntityID& kId); };   // loaded actor of an entity
Unk_PonyAnimSvc* FUN_141b6f910();
NiNode* FUN_1409f7cb0(NiActorManager* pActor);                  // the actor's scene root

// The app framework (+8 = the service manager) and the world scene.
struct Unk_PonyApp { char m_pad[8]; char m_manager[1]; double FUN_141473280(); };
Unk_PonyApp* FUN_14086d260();
void* FUN_140af8310(char* pManager);
struct Unk_PonyScene;
Unk_PonyScene* FUN_1403ed280();
NiNode* FUN_1411a6b10(Unk_PonyScene* pScene);                   // the root node the hair models are attached to
char* FUN_1401d3200();                                          // Client::Constants
float FUN_1402bac70(void* pValue);                              // Constants::Value<float>::get
float FUN_140a17940(float fValue, float fMin, float fMax);      // clamp

// The model facts of a part and the model's non-virtual helpers (?\equipmodel.cpp, ?\itemugcmesh.cpp).
struct Unk_PonyRanges { const Unk_CustomizeRange* FUN_140544f20(size_t nIndex); };
Unk_PonyRanges* FUN_141200a90(Unk_PickTarget* pPart);           // the part's customize ranges
void FUN_141200190(Unk_PickTarget* pPart, NiTransform* pXf);    // sets the part's local transform
void FUN_1412021a0(Unk_PickTarget* pPart, NiTransform* pOut);   // the part's local transform
void FUN_1412021f0(Unk_PickTarget* pPart, NiTransform* pOut);   // the part's world transform
void FUN_1412024f0(Unk_PickTarget* pPart, NiPoint3* pPos, NiPoint3* pEuler, float* pScale, NiPoint3* pA, NiPoint3* pB,
                   void* pUnused);                              // the part's attach pose
void FUN_1412029d0(Unk_PickTarget* pPart, CString* pOut);       // name of the part's scene node
void FUN_141200e30(Unk_PickTarget* pPart, int n);
NiAVObject* FUN_1411673f0(Unk_PickTarget* pPart, const CString* pNodeName);   // the part's attach node
float FUN_141422340(Unk_PickTarget* pPart, int nIndex);         // customize value nIndex of the part
void FUN_1414225d0(MS2Ptr<Unk_PickTarget> spPart, int nIndex, float fValue);   // stores value nIndex
void FUN_141422840(Unk_PickTarget* pPart, const Vector3& kPos, const Vector3& kEuler, float fScale);
void FUN_141422950(const NiTransform& kXf, Vector3* pEuler);   // transform -> euler angles (degrees)
Unk_PickPartInfo* FUN_141200ab0(Unk_PickTarget* pPart);

// Preset list inside the part facts (+0x58).
struct Unk_PonyPresets;
bool FUN_14059da70(Unk_PonyPresets* p);                         // empty
int FUN_1401e5720(Unk_PonyPresets* p);                          // count
void* FUN_14059ce40(Unk_PonyPresets* p, size_t nIndex);         // element holder
#define PONY_PRESETS(pInfo) ((Unk_PonyPresets*)((char*)(pInfo) + 0x58)) // the part info's preset array
struct Unk_PonyPresetEntry { char m_pad[0x18]; Vector3 m_kPos; Vector3 m_kEuler; };
Unk_PonyPresetEntry* FUN_14059cf20(void* pHolder);                             // element data

// Geometry / scene helpers.
float FUN_140a00f20(const Vector3& a, const Vector3& b);   // Dot
void FUN_140a01250(Vector3 ptRot, Vector3* pForward, Vector3* pRight);   // basis from a z rotation
Vector3 FUN_140a0b080(const Vector3& kEnd, const Vector3& kStart, const Vector3& kUp);   // euler of a look-at
void FUN_1420849a0(Unk_EfdMatrix3* p);                          // efd::Matrix3::MakeIdentity
void* FUN_1409478e0(void* pNode);                               // the node's world transform
void* FUN_14098d8d0(const void* pRTTI, const void* pObject);    // dynamic cast (NULL-safe)
char FUN_14098df90(const void* pRTTI, const void* pObject);     // IsKindOf
char FUN_1401c0090(const CString& a, const CString& b);         // CString ==
char FUN_1402a5b40(const CString& a, const char* b);            // CString == C string
NiAVObject* FUN_141167cf0(const CString& strName);              // scene node by name

// Texture lookup of the hair (control map).
void* FUN_14106be30(void* pProp, int nMap);                     // NiTexturingProperty map
void* FUN_14106b9b0(void* pProp);                               // NiTexturingProperty base texture
void* FUN_140d89f40(void* pMap);                                // the map's texture
const NiFixedString& FUN_14116f570(void* pTexture);             // the texture's file name
CString FUN_14038f6d0(const CString& strBase, const char* pszSuffix);   // path concatenation
bool FUN_1420b1540(const char* pszPath, int n);                 // efd::File::Access: the file exists
void* FUN_141d33230(NiFixedString* pName, void* pFormat, int a, int b, bool c);   // NiSourceTexture::Create

// PhysX glue (?\kfmmodel.cpp, ?\equipmodelforceapplier.cpp, client\ms2\physxhelper.cpp).
class CPhysXHelper;
CPhysXHelper* FUN_1409f7ca0();
void FUN_14168a540(CPhysXHelper* h, int n);
void FUN_14168a570(CPhysXHelper* h);
CKfmModel* FUN_1411de170(Unk_PickTarget* pPart);                // the part's model as a .kfm model
void* FUN_14120a240(void* pServices);                           // PropService
unsigned FUN_14120ade0(void* pSvc, const void* pId);
void* FUN_14120ae30(void* pSvc, const void* pId, unsigned nIndex);
void* FUN_14120aed0(void* p);
unsigned FUN_14120ac30(void* p);
void* FUN_14120abd0(void* p, void* pOut, unsigned nIndex);
void* FUN_14120a6e0(void* p);
void FUN_14120a600(void* p);
void* FUN_141ef6110(void* pComponent);                          // the component's joint
void* FUN_141d17b40(void* pNode, void* pName);                  // extra data by name
float FUN_141d57ca0(void* pExtra, int nIndex);                  // NiFloatsExtraData value
Unk_EfdMatrix3* FUN_141024c90(NiObjectNET* pNode);              // the node's rotation
int FUN_1409a8f90(const float* pf);                             // is finite
void* FUN_140a44830();
void FUN_1401ce2f0(void* pLog, const char* pszFormat, ...);   // printf-style log (variadic: the double goes in r8 too)

// The joint of a hair part (an NxD6Joint wrapper): slot 23 = name, 25 = loadFromDesc, 26 = saveToDesc.
class Unk_PonyJoint
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22();
    virtual const char* vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(const NxD6JointDesc& kDesc);
    virtual void vfunc_26(NxD6JointDesc& kDesc);
};

// One joint entry of the part facts (0x18 bytes): the joint name, its limit and the euler angles of its axis.
struct Unk_PonyJointEntry
{
    CString m_strName;
    float m_fLimit;
    float m_fEulerX, m_fEulerY, m_fEulerZ;
};
MS2_CHECK_SIZE(Unk_PonyJointEntry, 0x18);

// The loaded meshes of a part model: std::set<NiAVObjectPtr> at +0xf8 (equipmodel.h), iterated by the shared
// iterator wrappers (the iterator is 8 bytes; begin/end return it through a hidden pointer).
typedef std::set<efd::SmartPointer<NiAVObject> > Unk_MeshSet;   // the part's mesh objects
Unk_MeshSet* FUN_141201c90(Unk_PickTarget* pPart);

static inline const NiPoint3& N3(const Vector3& p) { return reinterpret_cast<const NiPoint3&>(p); }
static inline Vector3 SPV(const NiPoint3& p) { return Vector3(p.x, p.y, p.z); }
static inline Vector3& SP(Unk_FcPoint3& p) { return reinterpret_cast<Vector3&>(p); }

void* FUN_1412018c0(void* self);
class Unk_PonyPlayer;
void FUN_141695f10(Unk_PonyPlayer* pPlayer, Unk_PickTarget** ppFirst, Unk_PickTarget** ppSecond);
// ---- static initializers (.text$di) ----
#ifndef MS2_HOOK_DLL
#include "ms2/placeholder/header_statics_a.h"
static CString s_sortNames2[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill2("skill");
static CString s_stun2("stun");
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_sortNames3[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill3("skill");
static CString s_stun3("stun");
static Unk_1402a9d70 s_condition3(17, 0.75f, 0.25f, 2.25f, 10);
#endif

// ---- the pony part ----

// @0x1416916b0
Unk_PonyPart::Unk_PonyPart()
{
    Reset();
}

// @0x141691740
void Unk_PonyPart::Reset()
{
    m_fValue = 0;
    m_kAnchor = Unk_NiPoint3(DAT_143a08cf8);
    m_kRest.MakeIdentity();
    m_kStart.MakeIdentity();
    m_kPose.MakeIdentity();
    m_spModel = 0;
}

// @0x1416917d0
void Unk_PonyPart::Swap(Unk_PonyPart& kOther)
{
    float fValue = kOther.m_fValue;
    NiPoint3 kAnchor = reinterpret_cast<NiPoint3&>(kOther.m_kAnchor);
    NiTransform kRest = kOther.m_kRest;
    NiTransform kStart = kOther.m_kStart;
    NiTransform kPose = kOther.m_kPose;
    MS2Ptr<Unk_PickTarget> spModel = kOther.m_spModel;
    kOther.m_fValue = m_fValue;
    reinterpret_cast<NiPoint3&>(kOther.m_kAnchor) = reinterpret_cast<NiPoint3&>(m_kAnchor);
    kOther.m_kRest = m_kRest;
    kOther.m_kStart = m_kStart;
    kOther.m_kPose = m_kPose;
    kOther.m_spModel = m_spModel;
    m_fValue = fValue;
    reinterpret_cast<NiPoint3&>(m_kAnchor) = kAnchor;
    m_kRest = kRest;
    m_kStart = kStart;
    m_kPose = kPose;
    m_spModel = spModel;
}

// @0x141695df0
Unk_PonyPart::~Unk_PonyPart()
{
}

// ---- the controller ----

// @0x141691a20
CPonyTailController::CPonyTailController()
{
    m_bBusy = 0;
    m_nValue = -1;
    m_bEnabled = 1;
    m_bUseButton1 = 1;
}

// @0x141691ad0
CPonyTailController::~CPonyTailController()
{
}

// @0x141691b40
int CPonyTailController::vfunc_3()
{
    FUN_141694650();
    ReadValues();
    if ((bool)m_kFirst.m_spModel.get())
    {
        if (reinterpret_cast<CEquipModel*>(m_kFirst.m_spModel.operator->())->vfunc_9() != 0)
        {
            FUN_141695220();
            m_kFirst.m_kStart.m_fScale = vfunc_21();
            m_kSecond.m_kStart.m_fScale = vfunc_21();
            FUN_1416955b0(1, 0, &CPonyTailController::FUN_141694fb0, 0);
        }
    }
    m_fSensitivity = FUN_1402bac70(FUN_1401d3200() + 0x2e98);
    m_bEnabled = m_spEquipItem->FUN_1411dc7f0()->FUN_14053ec70()->FUN_140547130();
    m_bUseButton1 = m_spEquipItem->FUN_1411dc7f0()->FUN_14053ec70()->FUN_140547170();
    return 1;
}

// @0x141691d30
void CPonyTailController::vfunc_5()
{
    if (m_spEquipItem.get())
    {
        Unk_UserProxyItemData* pData = ((CItem*)m_spEquipItem->GetItem())->FUN_140527870();
        if (pData)
            FUN_14059a1f0(pData, m_nValue);
    }
}

// @0x141691de0
// MS2-FUNCTIONAL: loop over the two parts is unrolled in the exe
void CPonyTailController::vfunc_6()
{
    ReadValues();
    Unk_PonyAnimSvc* pSvc = FUN_141b6f910();
    Unk_PonyPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (m_bBusy != 0)
        FUN_1416955b0(0, 0, &CPonyTailController::FUN_141694fb0, 0);
    egf::EntityID kId;
    pPlayer->FUN_14123c460(kId);
    NiActorManager* pActor = pSvc->FUN_140999440(kId);
    if (pActor == 0)
        return;
    Unk_PonyPart* apPart[2] = {&m_kFirst, &m_kSecond};
    for (int i = 0; i < 2; i++)
    {
        MS2Ptr<Unk_PickTarget> spPart = apPart[i]->m_spModel;
        if (spPart.get() == 0)
            continue;
        CString strName;
        FUN_1412029d0(spPart.operator->(), &strName);
        NiAVObject* pObj = FUN_1409f7cb0(pActor)->GetObjectByName(NiFixedString((const char*)strName));
        if (FUN_14098df90(&DAT_143afa4d8, pObj) != 0)
        {
            FUN_141200190(spPart.operator->(), &apPart[i]->m_kRest);
            NiPoint3 kPos, kEuler, kA, kB;
            spPart->FUN_141202480(&kPos, &kEuler, &kA, &kB, &apPart[i]->m_kRest);
            reinterpret_cast<CEquipModel*>(spPart.operator->())->vfunc_24(kPos);
            reinterpret_cast<CEquipModel*>(spPart.operator->())->vfunc_26(kEuler);
            reinterpret_cast<CEquipModel*>(spPart.operator->())->vfunc_31();
        }
    }
}

// @0x1416923e0
float CPonyTailController::vfunc_19()
{
    return vfunc_23()->m_fMin;
}

// @0x141692410
float CPonyTailController::vfunc_20()
{
    return vfunc_23()->m_fMax;
}

// @0x141692440
const Unk_CustomizeRange* CPonyTailController::vfunc_23()
{
    Unk_PonyPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        MS2Ptr<Unk_PickTarget> spFirst = m_kFirst.m_spModel;
        if (spFirst.get())
            return FUN_141200a90(spFirst.operator->())->FUN_140544f20(0);
        MS2Ptr<Unk_PickTarget> spSecond = m_kSecond.m_spModel;
        if (spSecond.get())
            return FUN_141200a90(spSecond.operator->())->FUN_140544f20(0);
    }
    return CItemCustomizeController::vfunc_23();
}

// @0x141692560
void CPonyTailController::vfunc_25(float* pfMin, float* pfMax)
{
    const Unk_CustomizeRange* pRange = vfunc_23();
    *pfMin = pRange->m_fMin;
    *pfMax = pRange->m_fMax;
}

// @0x1416925c0
int CPonyTailController::vfunc_17()
{
    return m_nValue;
}

// @0x1416925e0
void CPonyTailController::vfunc_14(float fValue)
{
    Unk_PonyPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (m_bBusy != 0)
        return;
    MS2Ptr<Unk_PickTarget> spFirst = m_kFirst.m_spModel;
    if (spFirst == (Unk_PickTarget*)0)
        return;
    const Unk_CustomizeRange* pRange = vfunc_23();
    m_afValue[m_nCurIndex] = FUN_140a17940(fValue, pRange->m_fMin, pRange->m_fMax);
    float fCur = vfunc_21();
    if (FUN_141422340(spFirst.get(), 0) == fCur)
        return;
    m_n98 = 1;
    FUN_141695220();
    m_kFirst.m_kStart.m_fScale = fCur;
    m_kSecond.m_kStart.m_fScale = fCur;
    FUN_1414225d0(spFirst, 0, fCur);
    FUN_1416955b0(1, 0, &CPonyTailController::FUN_141694fb0, 0);
    if (m_pListener)
        static_cast<Unk_PonyListener*>(m_pListener)->vfunc_2(this, fCur, 0);
}

// @0x141692850
void CPonyTailController::vfunc_9(int nIndex)
{
    if (m_spEquipItem == (CEquipItem*)0)
        return;
    if (m_spEquipItem->FUN_1411dc0d0() == 0)
        return;
    FUN_141695220();
    FUN_1416955b0(0, 1, &CPonyTailController::FUN_141695120, nIndex);
    m_nValue = nIndex;
    Unk_UserProxyItemData* pData;
    Unk_UserProxyItemData* pCopy = pData = ((CItem*)m_spEquipItem->GetItem())->FUN_140527870();
    if (pData)
        FUN_14059a1f0(pData, nIndex);
}

// @0x1416929b0
int CPonyTailController::vfunc_29()
{
    Unk_PonyPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    Unk_PickTarget* pFirst = 0;
    Unk_PickTarget* pSecond = 0;
    FUN_141694ea0(&pFirst, &pSecond);
    m_kFirst.Reset();
    m_kSecond.Reset();
    if (pFirst)
        m_spPicker->AddTarget(pFirst);
    if (pFirst && pSecond)
        m_spPicker->AddTarget(pSecond);
    return 1;
}

// @0x141692a90
void CPonyTailController::vfunc_28()
{
    m_aPartNames.RemoveAll();
    m_aPartNames.Add(CString("HR_Pony"));
    m_aMeshNames.RemoveAll();
    m_aMeshNames.Add(CString("HR"));
}

// @0x141692b40
float CPonyTailController::vfunc_40()
{
    return m_fSensitivity;
}

// @0x141692b60
void CPonyTailController::vfunc_37()
{
    NiAVObject* pNode = FUN_141167cf0("HR");
    if (pNode == 0)
        return;
    void* pTexProp = 0;
    pTexProp = FUN_14098d8d0(&DAT_143afa4f0, pNode->GetProperty(8));
    if (pTexProp == 0)
        return;
    void* pMap = FUN_14106be30(pTexProp, 0);
    if (pMap)
    {
        m_kControlMap.FUN_141068540(FUN_14098d8d0(&DAT_143afa930, FUN_140d89f40(pMap)));
    }
    else
    {
        void* pSrc = FUN_14098d8d0(&DAT_143afa930, FUN_14106b9b0(pTexProp));
        CString strPath((const char*)FUN_14116f570(pSrc));
        int nDot = strPath.ReverseFind('.');
        strPath = strPath.Left(nDot);
        if (pSrc != 0)
        {
            CString strControl = FUN_14038f6d0(strPath, "_control.dds");
            Unk_PonyHandle kTemp;
            if (FUN_1420b1540((const char*)strControl, 0))
            {
                NiFixedString kName((const char*)strControl);
                m_kControlMap.FUN_141068540(FUN_141d33230(&kName, &DAT_1439fc800, 0, 0, true));
            }
        }
    }
}

// The position of a point mirrored across the plane through kOrigin (with its z taken from the point) whose normal is
// kAxis.
// @0x141695bc0
Vector3 CPonyTailController::FUN_141695bc0(const Vector3& kOrigin, const Vector3& kPoint,
                                                   const Vector3& kAxis)
{
    Vector3 kPlane = kOrigin;
    kPlane.z = kPoint.z;
    kPlane = kPoint.FUN_140965c40(kPlane);
    return kPoint.FUN_140965c40(kAxis.FUN_14097fc90(2.0f).FUN_14097fc90(FUN_140a00f20(kPlane, kAxis)));
}

// Applies the pose of a drag to one part: the look-at (kind 1) or the surface frame (other kinds) of the part's
// model at kPos with the direction kDir.
static void ApplyPartPose(CPonyTailController* pThis, Unk_PonyPart& kPart, Unk_PickTarget* pPart, const Vector3& kPos,
                          const Vector3& kDir, int nPickIndex)
{
    CEquipModel* pModel = reinterpret_cast<CEquipModel*>(pPart);
    int nKind = FUN_141200ab0(pPart)->m_nKind;
    Unk_NiMatrix3 mRot;
    if (nKind == 1)
    {
        Vector3 kTip = kPos.FUN_14097fd50(kDir.FUN_14097fc90(10.0f));
        Vector3 kEuler = FUN_140a0b080(kPos, kTip, DAT_143a08cf8);
        kEuler.z = kEuler.z + 90.0f;
        Vector3 kRad = kEuler.FUN_14097fc90(3.1415927f).FUN_140ae9180(180.0f);
        mRot.FUN_142083d40(kRad.x, kRad.y, kRad.z);
    }
    else
    {
        Vector3 kN = kDir;
        kN.FUN_140968990();
        Vector3 kUp = kN.FUN_140a00e10(DAT_143a08cf8).FUN_1409f7960();
        kUp.FUN_140968990();
        Vector3 kFwd = kN.FUN_140a00e10(kUp);
        kFwd.FUN_140968990();
        Unk_NiPoint3 cN(kN), cU(kUp), cF(kFwd);
        Unk_NiMatrix3 mBasis(cN, cU, cF);
        if (nKind == 2)
        {
            Unk_EfdMatrix3 mTurn;
            FUN_1420849a0(&mTurn);
            if (pThis->m_spPicker.operator CItemPickingHelper*() && pThis->m_spPicker->GetPickedIndex() == nPickIndex)
                mTurn.FUN_14107cc40(3.1415927f, kFwd);
            mRot = Unk_NiMatrix3(mTurn.FUN_140a33480(mBasis));
        }
        else
        {
            mRot = mBasis;
        }
    }
    kPart.m_kPose.m_fScale = pModel->vfunc_21();
    memcpy(&kPart.m_kPose.m_Rotate, &mRot, sizeof(mRot));
    reinterpret_cast<NiPoint3&>(kPart.m_kPose.m_Translate) = N3(kPos);
    pModel->vfunc_30((void*)&kPos, &mRot, kPart.m_kPose.m_fScale);
}

// @0x141692db0
void CPonyTailController::vfunc_30(const NiPoint3& kPos)
{
    Unk_PonyAnimSvc* pSvc = FUN_141b6f910();
    Unk_PonyPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
        pPlayer->FUN_14123d7a0(CString("TailController"), 1);
    NiActorManager* pActor = 0;
    if (pSvc != 0 && pPlayer != 0)
    {
        egf::EntityID kId;
        pPlayer->FUN_14123c460(kId);
        pActor = pSvc->FUN_140999440(kId);
    }
    if (m_spPicker.operator CItemPickingHelper*())
    {
        if (m_spPicker->GetPickedTarget() == m_kSecond.m_spModel.get())
            m_kFirst.Swap(m_kSecond);
    }
    if (pActor != 0)
    {
        Unk_PonyPart* apPart[2] = {&m_kFirst, &m_kSecond};
        for (int i = 0; i < 2; i++)
        {
            MS2Ptr<Unk_PickTarget> spPart = apPart[i]->m_spModel;
            if (spPart.get() == 0)
                continue;
            CString strName;
            FUN_1412029d0(spPart.operator->(), &strName);
            if (FUN_1409f7cb0(pActor)->GetObjectByName(NiFixedString((const char*)strName)) != 0)
                FUN_1412021f0(spPart.operator->(), &apPart[i]->m_kPose);
        }
    }
    FUN_141695220();
    m_nValue = 0;
    if (m_kFirst.m_spModel.get())
    {
        Unk_PickPartInfo* pInfo = FUN_141200ab0(m_kFirst.m_spModel.operator->());
        if (pInfo != 0)
            m_nValue = FUN_1401e5720((Unk_PonyPresets*)((char*)pInfo + 0x58));
    }
    if (m_pListener)
        static_cast<Unk_PonyListener*>(m_pListener)->vfunc_1(this);
}

// @0x141693210
// MS2-FUNCTIONAL: the two part branches share ApplyPartPose
void CPonyTailController::vfunc_32(const NiPoint3& kHit, const NiPoint3& kNormal, const NiPoint2& kUV, float fValue)
{
    Unk_PonyPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (FUN_1402a5b40(pPlayer->FUN_14166dc50(), "Equip_Change_Idle_A") != 0)
        return;
    Unk_PonyAnimSvc* pSvc = FUN_141b6f910();
    egf::EntityID kId;
    pPlayer->FUN_14123c460(kId);
    if (pSvc->FUN_140999440(kId) == 0)
        return;
    MS2Ptr<Unk_PickTarget> spFirst = m_kFirst.m_spModel;
    if (spFirst.get() == 0)
        return;
    float fThreshold = (float)*(int*)((char*)FUN_141200ab0(spFirst.operator->()) + 0x50) / 255.0f;
    if (!(fThreshold < fValue))
        return;
    const Vector3& kHitPt = reinterpret_cast<const Vector3&>(kHit);
    const Vector3& kNormalPt = reinterpret_cast<const Vector3&>(kNormal);
    ApplyPartPose(this, m_kFirst, spFirst.operator->(), kHitPt, kNormalPt, 0);
    reinterpret_cast<NiPoint3&>(m_kFirst.m_kAnchor) = kNormal;
    CPonyTailPhysXHelper::UpdateModelPhysXValues(spFirst.get(), (char*)FUN_141200ab0(spFirst.operator->()) + 0xb8);

    MS2Ptr<Unk_PickTarget> spSecond = m_kSecond.m_spModel;
    if (spSecond.get() == 0)
        return;
    Vector3 kForward, kRight;
    FUN_140a01250(Vector3(pPlayer->vfunc_20().x, pPlayer->vfunc_20().y, pPlayer->vfunc_20().z), &kForward, &kRight);
    Vector3 kAnchor = SP(m_kFirst.m_kAnchor);
    Vector3 kPlayerPos = SPV(pPlayer->vfunc_18());
    Vector3 kMirror = FUN_141695bc0(kPlayerPos, kHitPt, kRight);
    Vector3 kTip = kHitPt.FUN_14097fd50(kAnchor.FUN_14097fc90(10.0f));
    kPlayerPos = SPV(pPlayer->vfunc_18());
    Vector3 kMirrorTip = FUN_141695bc0(kPlayerPos, kTip, kRight);
    SP(m_kSecond.m_kAnchor) = kMirrorTip.FUN_140965c40(kMirror);
    SP(m_kSecond.m_kAnchor).FUN_140968990();
    ApplyPartPose(this, m_kSecond, spSecond.operator->(), kMirror, SP(m_kSecond.m_kAnchor), 1);
    CPonyTailPhysXHelper::UpdateModelPhysXValues(spSecond.get(), (char*)FUN_141200ab0(spSecond.operator->()) + 0xb8);
}

// @0x141694380
void CPonyTailController::vfunc_33()
{
    Unk_PonyPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
        pPlayer->FUN_14123d7a0(CString("TailController"), 0);
    MS2Ptr<Unk_PickTarget> spFirst = m_kFirst.m_spModel;
    if (spFirst.get())
        reinterpret_cast<CEquipModel*>(spFirst.operator->())->vfunc_28(&m_kFirst.m_kPose.m_Translate, &m_kFirst.m_kPose.m_Rotate, m_kFirst.m_kPose.m_fScale);
    MS2Ptr<Unk_PickTarget> spSecond = m_kSecond.m_spModel;
    if (spSecond.get())
        reinterpret_cast<CEquipModel*>(spSecond.operator->())->vfunc_28(&m_kSecond.m_kPose.m_Translate, &m_kSecond.m_kPose.m_Rotate, m_kSecond.m_kPose.m_fScale);
    FUN_1416955b0(0, 0, &CPonyTailController::FUN_141694fb0, 0);
    if (m_spEquipItem.get())
    {
        Unk_UserProxyItemData* pData;
        Unk_UserProxyItemData* pCopy = pData = ((CItem*)m_spEquipItem->GetItem())->FUN_140527870();
        if (pData)
        {
            m_nValue = -1;
            FUN_14059a1f0(pData, -1);
        }
    }
}

// @0x141694650
void CPonyTailController::FUN_141694650()
{
    Unk_PonyPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0 || m_spEquipItem == (CEquipItem*)0)
        return;
    Unk_PickTarget* pFirst = 0;
    Unk_PickTarget* pSecond = 0;
    FUN_141694ea0(&pFirst, &pSecond);
    m_kFirst.Reset();
    m_kSecond.Reset();
    m_kFirst.m_spModel.AssignRaw(pFirst);
    m_kSecond.m_spModel.AssignRaw(pSecond);
    m_kFirst.m_fValue = 180.0f;
    m_kSecond.m_fValue = 0;
    if (m_kFirst.m_spModel.get())
    {
        CEquipModel* pModel = reinterpret_cast<CEquipModel*>(m_kFirst.m_spModel.operator->());
        if (pModel->vfunc_9() != 0)
        {
            NiPoint3 kPos, kEuler, kAnchor, kUnused;
            m_kFirst.m_spModel->FUN_141202480(&kPos, &kEuler, &kAnchor, &kUnused, 0);
            pModel->vfunc_24(kPos);
            pModel->vfunc_26(kEuler);
            FUN_1412021a0(m_kFirst.m_spModel.operator->(), &m_kFirst.m_kRest);
            m_kFirst.m_kAnchor = Unk_NiPoint3(reinterpret_cast<Vector3&>(kAnchor));
        }
    }
    if (m_kFirst.m_spModel.get() && m_kSecond.m_spModel.get())
    {
        CEquipModel* pModel1 = reinterpret_cast<CEquipModel*>(m_kFirst.m_spModel.operator->());
        CEquipModel* pModel2 = reinterpret_cast<CEquipModel*>(m_kSecond.m_spModel.operator->());
        if (pModel1->vfunc_9() != 0 && pModel2->vfunc_9() != 0)
        {
            m_kSecond.m_kAnchor = Unk_NiPoint3(DAT_143b01a60);
            Vector3 kForward, kRight;
            FUN_140a01250(SPV(pPlayer->vfunc_20()), &kForward, &kRight);
            Vector3 kPlayerPos = SPV(pPlayer->vfunc_18());
            Vector3 kPartPos = SPV(pModel1->vfunc_23());
            Vector3 kMirror = FUN_141695bc0(kPlayerPos, kPartPos, kRight);
            pModel2->vfunc_24(N3(kMirror));
            Vector3 kTip = SPV(pModel1->vfunc_23())
                                       .FUN_14097fd50(SP(m_kFirst.m_kAnchor).FUN_14097fc90(10.0f));
            kPlayerPos = SPV(pPlayer->vfunc_18());
            Vector3 kMirrorTip = FUN_141695bc0(kPlayerPos, kTip, kRight);
            m_kSecond.m_kAnchor = Unk_NiPoint3(kMirrorTip.FUN_140965c40(kMirror));
            SP(m_kSecond.m_kAnchor).FUN_140968990();
            Vector3 kLookAt = kMirror.FUN_14097fd50(SP(m_kSecond.m_kAnchor).FUN_14097fc90(10.0f));
            Vector3 kEuler = FUN_140a0b080(kMirror, kLookAt, DAT_143a08cf8);
            kEuler.z = kEuler.z + 90.0f;
            pModel2->vfunc_26(N3(kEuler));
            FUN_1412021a0(m_kSecond.m_spModel.operator->(), &m_kSecond.m_kRest);
        }
    }
    Unk_UserProxyItemData* pData = ((CItem*)m_spEquipItem->GetItem())->FUN_140527870();
    if (pData)
        m_nValue = FUN_14059a210(pData);
}

// @0x141694ea0
void CPonyTailController::FUN_141694ea0(Unk_PickTarget** ppFirst, Unk_PickTarget** ppSecond)
{
    Unk_PonyPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    Unk_PickTarget* pA = 0;
    Unk_PickTarget* pB = 0;
    ::FUN_141695f10(pPlayer, &pA, &pB);
    if ((bool)m_spPicker.operator CItemPickingHelper*() && pB)
    {
        if (m_spPicker->GetPickedTarget() == pB)
        {
            if (ppFirst)
                *ppFirst = pB;
            if (ppSecond)
                *ppSecond = pA;
            return;
        }
    }
    if (ppFirst)
        *ppFirst = pA;
    if (ppSecond)
        *ppSecond = pB;
}

// @0x141694fb0
void CPonyTailController::FUN_141694fb0(MS2Ptr<Unk_PickTarget> spPart, NiNode* pRoot, int nValue, int nSecond,
                                        Vector3& kPos, Vector3& kEuler, float& fScale)
{
    if ((bool)spPart.get() && pRoot != 0)
    {
        NiTransform kInverse;
        ((NiTransform*)FUN_1409478e0(pRoot))->Invert(kInverse);
        NiTransform kLocal = FUN_141695ca0(spPart.get());
        kLocal = kInverse * kLocal;
        kPos = reinterpret_cast<const Vector3&>(kLocal.m_Translate);
        FUN_141422950(kLocal, &kEuler);
        fScale = kLocal.m_fScale;
    }
    else
    {
        kPos = kEuler = DAT_143b01a60;
        fScale = 0;
    }
}

// @0x141695120
void CPonyTailController::FUN_141695120(MS2Ptr<Unk_PickTarget> spPart, NiNode* pRoot, int nIndex, int nSecond,
                                        Vector3& kPos, Vector3& kEuler, float& fScale)
{
    Unk_PickPartInfo* pInfo = FUN_141200ab0(spPart.operator->());
    if (pInfo != 0)
    {
        if (FUN_14059da70(PONY_PRESETS(pInfo)) == 0)
        {
            if (nIndex < FUN_1401e5720(PONY_PRESETS(pInfo)))
            {
                Unk_PonyPresetEntry* pEntry = FUN_14059cf20(FUN_14059ce40(PONY_PRESETS(pInfo), nIndex));
                kPos = pEntry->m_kPos;
                kEuler = pEntry->m_kEuler;
            }
        }
    }
    fScale = vfunc_21();
}

// @0x141695220
void CPonyTailController::FUN_141695220()
{
    if (m_bBusy == 0 && (!(m_kFirst.m_spModel == (Unk_PickTarget*)0) || !(m_kSecond.m_spModel == (Unk_PickTarget*)0)))
    {
        FUN_1416952c0(&m_kFirst);
        FUN_1416952c0(&m_kSecond);
        m_bBusy = 1;
    }
}

// @0x1416952c0
void CPonyTailController::FUN_1416952c0(Unk_PonyPart* pPart)
{
    MS2Ptr<Unk_PickTarget> spPart = pPart->m_spModel;
    if (spPart == (Unk_PickTarget*)0)
        return;
    NiPoint3 kA = reinterpret_cast<NiPoint3&>(DAT_143b01a60);
    NiPoint3 kB = reinterpret_cast<NiPoint3&>(DAT_143b01a60);
    NiPoint3 kC = reinterpret_cast<NiPoint3&>(DAT_143b01a60);
    NiPoint3 kD = reinterpret_cast<NiPoint3&>(DAT_143b01a60);
    float fScale = 1.0f;
    FUN_1412024f0(spPart.operator->(), &kB, &kC, &fScale, &kA, &kD, 0);
    FUN_1412021a0(spPart.operator->(), &pPart->m_kStart);
    FUN_141200e30(spPart.operator->(), 0);
    reinterpret_cast<CEquipModel*>(spPart.operator->())->vfunc_29(&kB, &kC, fScale);
    if (*(int*)((char*)FUN_141200ab0(spPart.operator->()) + 0x20) != 0)
    {
        NiNode* pScene = FUN_1411a6b10(FUN_1403ed280());
        float fTime = (float)FUN_14086d260()->FUN_141473280();
        Unk_MeshSet* pSet = FUN_141201c90(spPart.operator->());
        Unk_MeshSet& kSet = *pSet;
        Unk_MeshSet::iterator itEnd = kSet.end();
        for (Unk_MeshSet::iterator it = kSet.begin(); it != itEnd; ++it)
        {
            efd::SmartPointer<NiAVObject> spMesh = *it;
            pScene->AttachChild((NiAVObject*)spMesh, true);
            spMesh->Update(fTime, true);
        }
    }
}

// @0x1416955b0
void CPonyTailController::FUN_1416955b0(int nMode, int nIndex, Unk_PonyPoseFn pFn, int nValue)
{
    if (m_bBusy == 0)
        return;
    FUN_141695710(&m_kFirst, nMode, nIndex, pFn, nValue, 0);
    FUN_141695710(&m_kSecond, nMode, nIndex, pFn, nValue, 1);
    vfunc_39(nIndex != 0 ? true : false);
    m_bBusy = 0;
}

// @0x141695710
void CPonyTailController::FUN_141695710(Unk_PonyPart* pPart, int nMode, int nIndex, Unk_PonyPoseFn pFn, int nValue,
                                        int bSecond)
{
    Unk_PonyAnimSvc* pSvc = FUN_141b6f910();
    Unk_PonyPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    egf::EntityID kId;
    pPlayer->FUN_14123c460(kId);
    NiActorManager* pActor = pSvc->FUN_140999440(kId);
    if (pActor == 0)
        return;
    MS2Ptr<Unk_PickTarget> spPart = pPart->m_spModel;
    if (spPart == (Unk_PickTarget*)0)
        return;
    CString strName;
    FUN_1412029d0(spPart.operator->(), &strName);
    NiAVObject* pObj = FUN_1409f7cb0(pActor)->GetObjectByName(NiFixedString((const char*)strName));
    if (pObj == 0)
        return;
    if (FUN_14098df90(&DAT_143afa4d8, pObj) == 0)
        return;
    NiNode* pRoot = (NiNode*)FUN_14098d8d0(&DAT_143afa4d8, pObj);
    NiAVObject* pNode = FUN_1411673f0(spPart.operator->(), (const CString*)((char*)FUN_141200ab0(spPart.operator->()) + 8));
    if (pNode == 0)
        return;
    Vector3 kPos, kEuler;
    kEuler = DAT_143b01a60;
    kPos = kEuler;
    float fScale = 0;
    if (nMode == 0)
    {
        if (pFn)
            (this->*pFn)(spPart, pRoot, nValue, bSecond, kPos, kEuler, fScale);
    }
    else
    {
        kPos = reinterpret_cast<const Vector3&>(pPart->m_kStart.m_Translate);
        FUN_141422950(pPart->m_kStart, &kEuler);
        fScale = pPart->m_kStart.m_fScale;
    }
    FUN_141422840(spPart.operator->(), kPos, kEuler, fScale);
    if (m_pListener)
        static_cast<Unk_PonyListener*>(m_pListener)->vfunc_5(this, spPart.get());
    pRoot->AttachChild(pNode, true);
    reinterpret_cast<CEquipModel*>(spPart.operator->())->vfunc_31();
}

// @0x141695ca0
NiTransform CPonyTailController::FUN_141695ca0(Unk_PickTarget* pModel)
{
    NiTransform kXf;
    kXf.m_Translate = NiPoint3(static_cast<const efd::Point3&>(reinterpret_cast<CEquipModel*>(pModel)->vfunc_23()));
    NiPoint3 kEuler = reinterpret_cast<CEquipModel*>(pModel)->vfunc_25();
    reinterpret_cast<Unk_NiMatrix3&>(kXf.m_Rotate).FUN_142083d40(kEuler.x * 3.1415927f / 180.0f, kEuler.y * 3.1415927f / 180.0f, kEuler.z * 3.1415927f / 180.0f);
    kXf.m_fScale = reinterpret_cast<CEquipModel*>(pModel)->vfunc_21();
    return kXf;
}

// @0x141695e20
// (MS2Ptr<Unk_PickTarget>::AssignRaw is emitted inline: m_p swap)

// @0x141695ea0 is the scalar deleting destructor of CPonyTailController (compiler-generated)

// @0x141695f00 is CPonyTailController::GetRTTI (pinned above)

// @0x141695f10
void FUN_141695f10(Unk_PonyPlayer* pPlayer, Unk_PickTarget** ppFirst, Unk_PickTarget** ppSecond)
{
    if (pPlayer == 0)
        return;
    MS2Ptr<CEquipItem> spItem = pPlayer->FUN_141655e10(1);
    if (spItem.IsNull())
        return;
    if (spItem->GetItem() == (CItem*)0)
        return;
    CString strPart1;
    CString strPart2;
    CAtlArray<CString> aNames;
    spItem->FUN_1411dca30(1, aNames);
    if (aNames.GetCount() > 1)
        strPart1 = aNames[1];
    if (aNames.GetCount() > 2)
        strPart2 = aNames[2];
    CAtlArray<MS2Ptr<Unk_PickTarget> > aParts;
    spItem->FUN_1411dcc80(aParts);
    MS2Ptr<Unk_PickTarget> spA(0);
    for (size_t i = 0; i < aParts.GetCount(); i++)
    {
        if (FUN_1401c0090(strPart1, *(const CString*)FUN_141200ab0(aParts[i].operator->())) != 0)
        {
            spA = aParts[i];
            break;
        }
    }
    MS2Ptr<Unk_PickTarget> spB(0);
    for (size_t i = 0; i < aParts.GetCount(); i++)
    {
        if (FUN_1401c0090(strPart2, *(const CString*)FUN_141200ab0(aParts[i].operator->())) != 0)
        {
            if (spA.get() != aParts[i].get())
            {
                spB = aParts[i];
                break;
            }
        }
    }
    if (ppFirst)
        *ppFirst = spA.get();
    if (ppSecond)
        *ppSecond = spB.get();
}

// ---- PhysX glue ----

// @0x141696cf0
float FUN_141696cf0(const float* pValues, const Unk_PonyJointEntry* pEntry)
{
    float fT = pEntry->m_fLimit;
    if (fT <= 0.0f)
        return pValues[2] * -fT + pValues[1] * (fT + 1.0f);
    return pValues[0] * fT + pValues[1] * (1.0f - fT);
}

// @0x141696de0
void FUN_141696de0(NxJointLimitSoftDesc* pLimit, float fValue)
{
    if (FUN_1409a8f90(&fValue) == 0)
    {
        if (DAT_143afc898 != 0)
        {
            FUN_1401ce2f0(FUN_140a44830(), "UpdateJointLimitSoftDesc() %f", (double)fValue);
            throw 13;
        }
    }
    else
    {
        pLimit->value = fValue;
        pLimit->spring = 0;
        pLimit->damping = 0;
        pLimit->restitution = 0;
    }
}

// @0x141696ea0
void FUN_141696ea0(NxD6JointDesc* pDesc, float fValue)
{
    FUN_141696de0(&pDesc->linearLimit, fValue);
    FUN_141696de0(&pDesc->swing1Limit, fValue);
    FUN_141696de0(&pDesc->swing2Limit, fValue);
    FUN_141696de0(&pDesc->twistLimit.low, fValue);
    FUN_141696de0(&pDesc->twistLimit.high, fValue);
}

// @0x141696f40
void FUN_141696f40(const Unk_EfdMatrix3* pSrc, NxMat33* pDst)
{
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            (*pDst)(r, c) = pSrc->m_afEntry[r][c];
}

// @0x1416962d0
void CPonyTailPhysXHelper::UpdateModelPhysXValues(Unk_PickTarget* pModel, const void* pJoints)
{
    const Unk_PonyJointEntry* pEntries = (const Unk_PonyJointEntry*)pJoints;
    if (pModel == 0)
        return;
    CKfmModel* pKfm = FUN_1411de170(pModel);
    if (pKfm == 0)
        return;
    void* pProp = FUN_14120a240(FUN_140af8310(FUN_14086d260()->m_manager));
    egf::EntityID kId1 = pKfm->FUN_14143ff70();
    unsigned nJoints = FUN_14120ade0(pProp, &kId1);
    NiObjectNET* pNode = (NiObjectNET*)FUN_1412018c0(pModel);
    if (pNode == 0)
        return;
    Vector3 kReference = FUN_141024c90(pNode)->FUN_140a00720(DAT_143a08cd8);
    (void)kReference;
    for (unsigned i = 0; i < nJoints; i++)
    {
        egf::EntityID kId2 = pKfm->FUN_14143ff70();
        void* pInfo = FUN_14120ae30(pProp, &kId2, i);
        if (pInfo == 0)
            continue;
        void* pSet = FUN_14120aed0(pInfo);
        if (pSet == 0)
            continue;
        unsigned nCount = FUN_14120ac30(pSet);
        for (unsigned j = 0; j < nCount; j++)
        {
            alignas(8) char hnd[8];
            void* pH = FUN_14120abd0(pSet, hnd, j);
            void* pComp = FUN_14098d8d0(&DAT_143afc8c0, FUN_14120a6e0(pH));
            FUN_14120a600(hnd);
            if (pComp == 0)
                continue;
            Unk_PonyJoint* pJoint = (Unk_PonyJoint*)FUN_141ef6110(pComp);
            if (pJoint == 0)
                continue;
            CString strName(pJoint->vfunc_23());
            unsigned k = 0;
            while (k < 4 && FUN_1401c0090(strName, pEntries[k].m_strName) == 0)
                k++;
            if (k >= 4)
                continue;
            NxD6JointDesc kDesc;
            pJoint->vfunc_26(kDesc);
            FUN_141696ea0(&kDesc, pEntries[k].m_fLimit);
            Unk_NiMatrix3 mRot;
            mRot.FUN_142083d40(pEntries[k].m_fEulerX * 3.1415927f / 180.0f, pEntries[k].m_fEulerY * 3.1415927f / 180.0f,
                               pEntries[k].m_fEulerZ * 3.1415927f / 180.0f);
            NxMat33 mAxis;
            FUN_141696f40(&mRot, &mAxis);
            kDesc.localAxis[0] = mAxis * NxVec3(0, 0, 1);
            kDesc.localNormal[0] = mAxis * NxVec3(1, 0, 0);
            CString strBase(pJoint->vfunc_23());
            for (int l = 0; l < 2; l++)
            {
                CString strKey;
                strKey.Format("%s%d", (const char*)strBase, l);
                NiFixedString kFixed((const char*)strKey);
                NiFloatsExtraData* pExtra = (NiFloatsExtraData*)FUN_14098d8d0(&DAT_143afafe0, FUN_141d17b40(pNode, &kFixed));
                kFixed = NiFixedString();
                if (pExtra == 0)
                {
                    float v[3] = {kDesc.localAnchor[l].x, kDesc.localAnchor[l].y, kDesc.localAnchor[l].z};
                    pExtra = EE_NEW NiFloatsExtraData(3, v);
                    pNode->AddExtraData(NiFixedString((const char*)strKey), pExtra);
                    kDesc.localAnchor[l] = kDesc.localAnchor[l] * reinterpret_cast<CEquipModel*>(pModel)->vfunc_21();
                }
                else
                {
                    kDesc.localAnchor[l].x = FUN_141d57ca0(pExtra, 0) * reinterpret_cast<CEquipModel*>(pModel)->vfunc_21();
                    kDesc.localAnchor[l].y = FUN_141d57ca0(pExtra, 1) * reinterpret_cast<CEquipModel*>(pModel)->vfunc_21();
                    kDesc.localAnchor[l].z = FUN_141d57ca0(pExtra, 2) * reinterpret_cast<CEquipModel*>(pModel)->vfunc_21();
                }
            }
            bool bBad = false;
            for (int l = 0; l < 2; l++)
            {
                if (!kDesc.localAnchor[l].isFinite() || !kDesc.localNormal[l].isFinite() || !kDesc.localAxis[l].isFinite())
                {
                    bBad = true;
                    break;
                }
            }
            if (!bBad)
            {
                FUN_14168a540(FUN_1409f7ca0(), 1);
                pJoint->vfunc_25(kDesc);
                FUN_14168a570(FUN_1409f7ca0());
            }
            else
            {
                EE_LOG_AT(0x12, 1, ("CPonyTailPhysXHelper::UpdateModelPhysXValues"), MS2_THIS_FILE, 0xc5);
                if (DAT_143afc898 != 0)
                    throw 13;
            }
        }
    }
}

// NiImplementRTTI(CPonyTailController, CItemCustomizeController): its initializer sits just before this TU's .text$di
// range. The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x1400fbb00-0x1400fbb30 .text$di
#ifndef MS2_HOOK_DLL
// @0x1400fbb00
const NiRTTI CPonyTailController::ms_RTTI("CPonyTailController", &CItemCustomizeController::ms_RTTI);
#endif
