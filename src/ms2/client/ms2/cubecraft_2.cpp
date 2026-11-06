// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See cubecraft_2.h.
// MS2-UNIT: client\ms2\cubecraft.cpp#2-core
// MS2-RANGE: 0x1410a8550-0x1410af930 .text$mn
// MS2-RANGE: 0x1400e5be0-0x1400e5dd0 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubecraft.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "cubecraft_2.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/objectdata.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cube.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/cubeguide.h"
#include "ms2/client/ms2/cubemapinformationservice_2.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "ms2/client/ms2/cubemotionmanager.h"
#include "ms2/commonfiles/ugcbuildvalidator.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cguidemanager.h"
#include <cmath>
#include "ms2/client/ms2/godmodeinfo.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include <io.h>
#include <NiNode.h>
#include <efd/ServiceManager.h>

// ---- unit-local placeholders and externals ----

// The world service singleton: the local player and the scene.
class Unk_C2World : public WorldService
{
public:
    PC* FUN_141bd0cc0();                                            // the local player
};

// A liftable object standing in the world (mirror of Unk_WsB_Lift in actionkeyobject.cpp).
class Unk_AkoLiftTarget : public CPtred
{
public:
    Vector3 FUN_1409673f0();                                // the position
    int FUN_1410af780() { return m_nId; }                          // 0x1410af780
    int m_nId;                                                      // +0x18
};
MS2_CHECK_OFFSET(Unk_AkoLiftTarget, m_nId, 0x18);

class CQuestManager;
void* FUN_140764020();   // C3: was FUN_140764020


class CLogString* GetLogString();   // C3: was FUN_140166440
void Unk_AdditionalLog(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat);
class UGCCubePalette* GetUGCCubePalette();

// The client string table holding the guide asset names.
class Unk_C2Config
{
public:
    char m_pad_00[0x1e8];
    CString m_strGuideBuild;        // +0x1e8
    CString m_strGuideMove;         // +0x1f0
    CString m_strGuideInventory;    // +0x1f8
};
MS2_CHECK_OFFSET(Unk_C2Config, m_strGuideInventory, 0x1f8);
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0

#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }

// A 24-byte reason / filter record (constructed from 0) handed to the cube service checks.
class Unk_C2Reason
{
public:
    Unk_C2Reason* FUN_14052be80(int nValue);
    void* m_pad[3];
};

// The cube grid service (class id 0x06100017), seen through the real CubeMapInformationService. Every member
// used here is CubeMapInformationService's own.
// C3: the former Unk_Service6100017 view is gone (it added no members):
//
//
    // C3: FUN_1410c6980 (may the cube be removed / moved) is CubeMapInformationService's own
    // C3: FUN_1410cdd80 (the sweep from ptFrom to ptTo is free) is CubeMapInformationService's own
    // C3: FUN_1410cdf60 (the column step is free) is CubeMapInformationService's own
//
class Unk_MyPCHousingSvc { public: void FUN_1410d6590(int nMessage); };   // show the build notice (calls cast the cube service)
//

// The client constants table: three consecutive 0x58-byte item-id constants at +0x39f0 (the guide effect items).
class Unk_C2ConstB { public: char m_pad[0x58]; };
int FUN_140ec2b60(void* pConst);
struct Unk_C2Consts
{
    char m_pad_00[0x39f0];
    Common::Constants::Value<int> m_effectA;     // +0x39f0
    Unk_C2ConstB m_effectB;     // +0x3a48
    Unk_C2ConstB m_effectC;     // +0x3aa0
    Common::Constants::Value<int> m_liftUp;      // +0x3af8
    Common::Constants::Value<int> m_liftDown;    // +0x3b50
};
MS2_CHECK_OFFSET(Unk_C2Consts, m_effectC, 0x3aa0);
MS2_CHECK_OFFSET(Unk_C2Consts, m_liftDown, 0x3b50);
extern int DAT_143ae0fb4;
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

Vector3 FUN_140a0b080(const Vector3& kFrom, const Vector3& kTo, const Vector3& kUp);   // C3: the definer's signature (0x140a0b080), look-at angles
void FUN_140b86230(const efd::Point3& kDegrees, NiMatrix3& out);

__int64 FUN_14028d0e0();
// The feature-flag holder and the UI manager (a flag at +10 is the shift key state).
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class Unk_C2UiMgr
{
public:
    char m_pad_00[10];
    bool m_bShift;                  // +0x0a
    bool FUN_1410af770() { return m_bShift; }
};
class UISwfEntityManager* FUN_140b632f0();   // C3: was FUN_140b632f0

class MyPC   // C3: member view for the former free stand-ins
{
public:
    bool FUN_1415302e0(int);
};
int FUN_1408a03c0(Unk_Int3 point);
int FUN_1408a13d0(NiPoint3 kPos);   // C3: ridee.cpp / mypc.cpp's declaration (0x1408a13d0)
efd::Point3 FUN_1408a15b0(Unk_Int3 cell, efd::Point3& ptCenter);   // fills the cell center
#include "ms2/placeholder/unk_1402a9d70.h"
// File statics of this TU (initialised by the .text$di entries; the hook build uses the exe's copies).
#ifndef MS2_HOOK_DLL
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400e5be0
static CString s_str143acf628("skill");                                                    // @0x1400e5ca0
static CString s_str143acf620("stun");                                                     // @0x1400e5cd0
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static egf::EntityID s_dat_143acf668(0);                                               // @0x1400e5d00
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);                          // @0x1400e5d20
static CString DAT_143acf6b8("system_notice_error_warningNoBuild");                        // @0x1400e5d70
static CString DAT_143acf6c0("ugc_moveblock");                                             // @0x1400e5da0
#else
extern CString DAT_143acf6b8;
extern CString DAT_143acf6c0;
#endif

// Stateless easing curves (the object is a dummy); the ease out is the shared Unk_EaseOut (fishingmanager.cpp).
struct Unk_EaseOut { float Evaluate(float t); };
struct Unk_C2Ease
{
    float FUN_1410af700(float t);       // 0x1410af700 ease in (1 - sqrt(1 - t^2))
};
void FUN_141275260(int nA, int nB, int nC);
int FUN_141276180(const CString& str, const CString& strArg);
void FUN_140291b70(float* pfDegrees);

class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
int FUN_140707bc0(int nId);

int FUN_1408a18d0(__int64);
Unk_Int3 FUN_1408a1430(NiPoint3 kPos);

// CCubeGuideWrapper's slot 2 as the exe calls it: the point goes by value (cubeguide.h spells it const NiPoint3&).
class Unk_C2GuideSlots
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(NiPoint3 kPos);
    virtual Vector3 vfunc_3();
};
// The lifted object of the player (position / facing through virtuals).
class Unk_C2Lift
{
public:
    virtual ~Unk_C2Lift();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual Vector3 vfunc_18();
    virtual void vfunc_19();
    virtual Vector3 vfunc_20();
};
class CGuideObject;
void FUN_1410a77e0(CGuideObject* pLift, float fStep);
int FUN_1410af7a0(PC* pPC);

void FUN_140710590(COutPacket&);
CString FUN_1410280d0(int, CString);
MS2Ptr<CItemData> FUN_14053f870(int);
int FUN_1407072e0(int);


NiAVObject* FUN_141b6efc0(egf::Entity*);

// Virtual call helper: calls vtable slot nSlot of an object whose class is unknown here.
template <class R, class... A>
inline R CallSlot(void* pObj, int nSlot, A... args)
{
    typedef R (*Fn)(void*, A...);
    return (*(Fn**)pObj)[nSlot](pObj, args...);
}
// The node attachment owner: slot 37 detaches the node and returns it as a smart pointer (dropped at once).
class Unk_C2NodeOwner
{
public:
    virtual ~Unk_C2NodeOwner();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual efd::SmartPointer<NiAVObject> vfunc_37(void* pNode);   // detach: returns the child (released by 0x1405a85c0)
};


CCubeMotionManager* GetCubeMotionManager();                        // the cube motion manager

// Housing quest-less globals.
extern NiRTTI DAT_143afa4d8;

// Timers of the cube craft (declared in timer.h): m_tPulse (+0x70), m_tSlide (+0xa8), m_tRotate (+0xe0).

// ---- the cube craft controller ----

// @0x1410a8550
Unk_PCCubeCraft::Unk_PCCubeCraft(PC* pOwner, int nMode, CubeItemInfo* pInfo)
    : m_fScale(1.0f), m_spGuide(0), m_spGuide2(0), m_spEffectA(0), m_spEffectB(0), m_spEffectC(0), m_spNode(0), m_svc((CubeMapInformationService*)0), m_spGod(0),
      m_bFirstMove(true), m_nCheck(1)
{
    m_bVisible = true;
    m_bPending = false;
    m_pOwner = pOwner;
    m_nMode = nMode;
    m_nHud = 1;
    m_fLift = 0.0f;
    m_spItem.AssignRaw(new CubeItemInfo());
    m_spItem->FUN_1408b3700(pInfo);
    m_spItem2.AssignRaw(new CubeItemInfo());
    m_spItem2->FUN_1408b3810();
    m_fYaw = 0.0f;
    m_fRotFrom = 0.0f;
    m_fRotTo = 0.0f;
    m_tRotate.FUN_1408687f0();
}

// @0x1410a8880
Unk_PCCubeCraft::~Unk_PCCubeCraft()
{
    FUN_1410add30();
    FUN_1410a9d60();
    ReleaseGuides();
    m_fLift = 0.0f;
    m_spItem = 0;
    m_spItem2 = 0;
    m_spGod = 0;
}

// @0x1410a8a20
void Unk_PCCubeCraft::SendRequestCubeMode0(int nValue)
{
    COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
    packet.Encode1(0);
    packet.Encode4(nValue);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1410A8A20, Unk_PCCubeCraft, SendRequestCubeMode0, 93, 0xA3979923);

// @0x1410a8a90
int Unk_PCCubeCraft::GetMode()
{
    return m_nMode;
}
MS2_REPLACE_METHOD(0x1410A8A90, Unk_PCCubeCraft, GetMode, 17, 0x9F576736);

// @0x1410a8ab0
int Unk_PCCubeCraft::FUN_1410a8ab0()
{
    return m_nMode == 2;
}
MS2_REPLACE_METHOD(0x1410A8AB0, Unk_PCCubeCraft, FUN_1410a8ab0, 47, 0x6497589C);

// Enters (bEnable) or leaves the build mode: scale pulse of the cube at the cell, guides and effect items.
// @0x1410a8af0
void Unk_PCCubeCraft::FUN_1410a8af0(bool bEnable)
{
    if (bEnable)
    {
        m_svc = egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>();
        m_tPulse.FUN_1408687f0();
        m_tSlide.FUN_1408687f0();
        m_bFirstMove = false;
        PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPC != 0 && pPC == m_pOwner)
        {
            m_fLift = 0.0f;
            Vector3 kFront;
            Vector3 kCell;
            if (((class PC*)(pPC))->IsCubeMode1() != 0)
            {
                Unk_C2Lift* pLift = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0());
                if (pLift != 0)
                    m_svc->FUN_1410b7ba0(reinterpret_cast<const Vector3&>(static_cast<const Vector3&>(pLift->vfunc_18())),
                        reinterpret_cast<const Vector3&>(static_cast<const Vector3&>(pLift->vfunc_20())), -200.0f, &kFront, 0);
            }
            else
            {
                m_svc->GetCellInFrontOfActor(pPC, m_fLift, &kFront, 1);
            }
            m_svc->GetCellPosition(kFront, &kCell);
            m_ptCell = kCell;
            int nValue = 0;
            m_svc->FUN_1410ce1e0(1, &nValue);
        }
        FUN_1410a9cc0();
        FUN_1410ad780();
        if (m_svc->HasCubeAtPoint(m_ptCell))
        {
            MS2Ptr<Cube> spCube(m_svc->GetCubeAtPoint(m_ptCell));
            spCube->entity->GetPropertyValue<float>(0x2d7cad2d, m_fScale);
            Vector3 kTop = m_ptCell;
            kTop.z = FLT_MAX;
            FUN_1410aa6f0(kTop, false);
        }
        if (pPC != 0 && pPC == m_pOwner)
        {
            if (((class Unk_C2Lift*)((class PC*)(m_pOwner))->FUN_1416625b0()) == 0 && m_spGod.operator==(0))
            {
                m_spGod.AssignRaw(new CGodModeInfo());
                m_spGod->FUN_141374b80(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(pPC->vfunc_18())));
            }
            if (m_spGod.get() != 0)
            {
                int nLevel = FUN_1408a18d0(((class PCBase*)(class PC*)(m_pOwner))->FUN_141656a80());
                m_spGod->FUN_141374d10(nLevel);
            }
        }
    }
    else
    {
        m_nCheck = 1;
        FUN_1410a9d60();
        ReleaseGuides();
        if (m_spGod.get() != 0)
            m_spGod = 0;
        if (m_svc->HasCubeAtPoint(m_ptCell))
        {
            MS2Ptr<Cube> spCube(m_svc->GetCubeAtPoint(m_ptCell));
            float fScale;
            spCube->entity->GetPropertyValue<float>(0x2d7cad2d, fScale);
            GetCubeMotionManager()->AddScale(spCube->entity->GetEntityID(), fScale, m_fScale, 200);
        }
        FUN_1410add30();
        PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPC != 0 && pPC == m_pOwner)
        {
            int nValue = 0;
            m_svc->FUN_1410ce1e0(0, &nValue);
        }
    }
    reinterpret_cast<Unk_C2World*>(WorldService::GetInstance())->FUN_141bd3920();
}

// Creates the placement guide (a NIF model) for the local player.
// @0x1410a92c0
void Unk_PCCubeCraft::FUN_1410a92c0()
{
    FUN_1410a9d60();
    PC* pLocal = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pLocal == 0)
        return;
    if (m_pOwner != pLocal)
        return;
    CString strAsset("");
    if (m_nMode == 0 || m_nMode == 2)
    {
        if (m_nCheck != 0)
            strAsset = ((class Unk_C2Config*)FUN_1401d31f0())->m_strGuideBuild;
        else
            strAsset = ((class Unk_C2Config*)FUN_1401d31f0())->m_strGuideMove;
    }
    else if (m_nMode == 1)
    {
        m_spItem->FUN_1408b3810();
        strAsset = ((class Unk_C2Config*)FUN_1401d31f0())->m_strGuideInventory;
    }
    else
    {
        return;
    }
    CNifCubeGuide* pGuide = new CNifCubeGuide();
    if (pGuide->FUN_1410afc10(strAsset))
        m_spGuide.AssignRaw(pGuide);
    if (m_spGuide == (CCubeGuideWrapper*)0)
    {
        MS2_ASSERT_AT(0x12d, !"Failed to create GuideCube");
        return;
    }
    else
    {
        NiNode* pRoot = TSingleton<CEffectService>::GetInstance()->GetLeastLoadedRoot();
        if (pRoot == 0)
            Unk_AdditionalLog(GetLogString(), 2, 0x13, L"SceneRoot NULL");
        m_spGuide->vfunc_10(pRoot, 0);
        m_spGuide->vfunc_8(0.5f);
        m_spGuide->vfunc_6(m_bVisible == 0);
        FUN_1410aa6f0(m_ptCell, false);
    }
}

// Creates the guide owned by the player's current item (NIF, KFM or fitting doll).
// @0x1410a9630
void Unk_PCCubeCraft::FUN_1410a9630()
{
    ReleaseGuides();
    if (!m_spItem)
        return;
    FUN_1410af0c0();
    FUN_1410af1f0();
    CString strNif("");
    CString strKfm("");
    int nItemId = m_spItem->itemId;
    MS2Ptr<CItemData> spData = FUN_14053f870(m_spItem->itemId);
    if (spData.operator==(0))
        return;
    strKfm = spData->install.preset;
    strNif = spData->install.asset;
    if (FUN_1410ad6a0(nItemId) != 0)
    {
        CFittingDollCubeGuide* pGuide = new CFittingDollCubeGuide();
        if (pGuide->FUN_1410b0ba0(1, m_pOwner->FUN_14123c580(), nItemId))
            m_spGuide2.AssignRaw(pGuide);
    }
    else if (strKfm.GetLength() == 0)
    {
        CNifCubeGuide* pGuide = new CNifCubeGuide();
        if (pGuide->FUN_1410afc10(strNif))
            m_spGuide2.AssignRaw(pGuide);
    }
    else
    {
        CKfmCubeGuide* pGuide = new CKfmCubeGuide();
        if (pGuide->FUN_1410b1120(strKfm))
            m_spGuide2.AssignRaw(pGuide);
    }
    if (m_spGuide2.get())
    {
        NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(m_pOwner->FUN_14123c410()));
        m_spGuide2->vfunc_9(0.5f);
        NiNode* pPoint = NiDynamicCast(NiNode, pRoot->GetObjectByName("Extra_Point01"));
        m_spGuide2->vfunc_10(pPoint, 1);
        m_spGuide2->vfunc_12();
    }
    if ((m_spGuide2.get() ? true : false) && m_spItem->FUN_1408b3860() == 1)
    {
        {
            CString strLook = FUN_1410280d0(2, m_spItem->look->m_strUrl);
            if (_access(strLook, 0) != 0)
            {
                TSingleton<CUgcManager>::GetInstance()->FUN_1418845a0(m_spItem.get(), 0);
            }
            m_spGuide2->vfunc_15(m_spItem.get());
        }
    }
}

// @0x1410a9cc0
void Unk_PCCubeCraft::FUN_1410a9cc0()
{
    ReleaseGuides();
    FUN_1410a9d60();
    FUN_1410ae380(m_ptCell);
    FUN_1410a92c0();
    if (((class PC*)(m_pOwner))->IsCubeMode2() != 0 && (m_nMode == 0 || m_nMode == 2))
        FUN_1410a9630();
}
MS2_REPLACE_METHOD(0x1410A9CC0, Unk_PCCubeCraft, FUN_1410a9cc0, 142, 0xECF33D2D);

// @0x1410a9d60
void Unk_PCCubeCraft::FUN_1410a9d60()
{
    m_fYaw = 0.0f;
    if (m_spNode != 0)
    {
        Unk_C2NodeOwner* pOwner = ((class Unk_C2NodeOwner*)((class NiAVObject*)(m_spNode.operator->()))->GetParent());
        if (pOwner != 0)
        {
            pOwner->vfunc_37(m_spNode.operator NiNode*());
            m_spNode = (NiNode*)0;
        }
    }
    if (m_spGuide.get() != 0)
    {
        m_spGuide->vfunc_11();
        m_spGuide = 0;
    }
}

// @0x1410a9e70
void Unk_PCCubeCraft::ReleaseGuides()
{
    if (m_spGuide2.get() != 0)
    {
        m_spGuide2->vfunc_11();
        m_spGuide2 = 0;
    }
    ReleaseGuide3();
}
MS2_REPLACE_METHOD(0x1410A9E70, Unk_PCCubeCraft, ReleaseGuides, 103, 0xEEC9DFD1);

// @0x1410a9ee0
void Unk_PCCubeCraft::UpdateGuidePositions()
{
    PC* pLocal = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pLocal == 0)
        return;
    if (m_spGuide.get() != 0)
        reinterpret_cast<Unk_C2GuideSlots*>(m_spGuide.operator->())->vfunc_2((const NiPoint3&)m_ptCell);
    if (m_spGuide3.get() != 0)
    {
        NiPoint3 kLift = (const NiPoint3&)m_ptCell;
        kLift.z += 150.0f;
        reinterpret_cast<Unk_C2GuideSlots*>(m_spGuide3.operator->())->vfunc_2(kLift);
    }
}

// @0x1410aa010
bool Unk_PCCubeCraft::FUN_1410aa010()
{
    return m_spGuide2.get() != 0;
}
MS2_REPLACE_METHOD(0x1410AA010, Unk_PCCubeCraft, FUN_1410aa010, 59, 0x41CA4560);

// @0x1410aa060
void Unk_PCCubeCraft::AdjustLift(unsigned char bUp)
{
    if (bUp)
        m_fLift = m_fLift + 150.0f;
    else
        m_fLift = m_fLift - 150.0f;
}
MS2_REPLACE_METHOD(0x1410AA060, Unk_PCCubeCraft, AdjustLift, 77, 0x1406CA40);

// @0x1410aa0c0
void Unk_PCCubeCraft::RequestCube(CubeItemInfo* pInfo)
{
    m_bPending = true;
    if (GetMode() == 1)
    {
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.Encode1(0);
        packet.Encode4(0);
        FUN_140710590(packet);
    }
    if (pInfo == 0)
        pInfo = new CubeItemInfo();
    COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
    packet.Encode1(1);
    pInfo->FUN_1408b39c0(packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1410AA0C0, Unk_PCCubeCraft, RequestCube, 284, 0x96046D34);

// @0x1410aa1f0
int Unk_PCCubeCraft::FUN_1410aa1f0()
{
    if (m_nMode == 2)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1410AA1F0, Unk_PCCubeCraft, FUN_1410aa1f0, 29, 0x025309F5);

// @0x1410aa220
int Unk_PCCubeCraft::FUN_1410aa220()
{
    if (m_nMode == 0 || m_nMode == 1)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1410AA220, Unk_PCCubeCraft, FUN_1410aa220, 43, 0x14DCE7FB);

// @0x1410aa260
int Unk_PCCubeCraft::FUN_1410aa260()
{
    Unk_Int3 kCell = FUN_1408a1430((const NiPoint3&)m_ptCell);
    int i;
    for (i = 1; i <= 6; i = i + 1)
    {
        kCell.z = kCell.z - 1;
        MS2Ptr<Cube> spCube(m_svc->GetCubeAtCell(kCell));
        if (spCube == (Cube*)0)
            break;
        if (spCube->field44 != 2)
            break;
    }
    if (i == 6)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1410AA260, Unk_PCCubeCraft, FUN_1410aa260, 272, 0x18CE5B06);

// @0x1410aa380
void Unk_PCCubeCraft::SetGuideVisible(bool bVisible)
{
    if (GetMode() == 1)
        return;
    m_bVisible = bVisible;
    if (m_spGuide.get() != 0)
        m_spGuide->vfunc_6(bVisible == 0);
}
MS2_REPLACE_METHOD(0x1410AA380, Unk_PCCubeCraft, SetGuideVisible, 142, 0xEBE2C83D);

// @0x1410aa420
bool Unk_PCCubeCraft::FUN_1410aa420()
{
    if (m_spGuide == (CCubeGuideWrapper*)0)
        return false;
    return m_spGuide->vfunc_7() == 0;
}
MS2_REPLACE_METHOD(0x1410AA420, Unk_PCCubeCraft, FUN_1410aa420, 109, 0x35F71F79);

// @0x1410aa4a0
void Unk_PCCubeCraft::SetGuide2Visible(bool bVisible)
{
    if (m_spGuide2.get() != 0)
        m_spGuide2->vfunc_6(bVisible == 0);
}
MS2_REPLACE_METHOD(0x1410AA4A0, Unk_PCCubeCraft, SetGuide2Visible, 109, 0x13D950CB);

// @0x1410aa520
Vector3 Unk_PCCubeCraft::GetPtCell()
{
    return m_ptCell;
}
MS2_REPLACE_METHOD(0x1410AA520, Unk_PCCubeCraft, GetPtCell, 41, 0xA7FB2F5C);

// @0x1410aa550
void Unk_PCCubeCraft::SetMode(int nMode)
{
    m_nMode = nMode;
    FUN_1410a9cc0();
}
MS2_REPLACE_METHOD(0x1410AA550, Unk_PCCubeCraft, SetMode, 43, 0x78B171A4);

// @0x1410aa590
void Unk_PCCubeCraft::FUN_1410aa590()
{
    m_tPulse.FUN_140868750(200);
}
MS2_REPLACE_METHOD(0x1410AA590, Unk_PCCubeCraft, FUN_1410aa590, 36, 0x1378C28C);

// @0x1410aa5c0
void Unk_PCCubeCraft::SetCurrentItem(CubeItemInfo* pInfo)
{
    m_bPending = false;
    if (pInfo == 0)
    {
        m_spItem->FUN_1408b3810();
        return;
    }
    if (m_spItem->instanceId == pInfo->instanceId && m_spItem->itemId == pInfo->itemId)
        return;
    m_spItem->FUN_1408b3700(pInfo);
    FUN_1410a9cc0();
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC != 0 && pPC == m_pOwner)
        reinterpret_cast<CubeHolderManager*>(GetUGCCubePalette())->FUN_1410b5280(m_spItem);
}
MS2_REPLACE_METHOD(0x1410AA5C0, Unk_PCCubeCraft, SetCurrentItem, 292, 0x60E1D7B8);

// @0x1410ac960
void Unk_PCCubeCraft::FUN_1410ac960()
{
    if (m_spGuide2.get() != 0)
        m_spGuide2->vfunc_1();
}
MS2_REPLACE_METHOD(0x1410AC960, Unk_PCCubeCraft, FUN_1410ac960, 74, 0xC5A8022D);

// @0x1410ad5f0
bool Unk_PCCubeCraft::GetPending()
{
    return m_bPending;
}
MS2_REPLACE_METHOD(0x1410AD5F0, Unk_PCCubeCraft, GetPending, 18, 0xCF5C7FCF);

// @0x1410ad610
int Unk_PCCubeCraft::FUN_1410ad610()
{
    return m_spItem->itemId;
}
MS2_REPLACE_METHOD(0x1410AD610, Unk_PCCubeCraft, FUN_1410ad610, 34, 0x96CAF674);

// @0x1410ad640
__int64 Unk_PCCubeCraft::FUN_1410ad640()
{
    return m_spItem->instanceId;
}
MS2_REPLACE_METHOD(0x1410AD640, Unk_PCCubeCraft, FUN_1410ad640, 35, 0xAB9BBB62);

// @0x1410ad670
CubeItemInfo* Unk_PCCubeCraft::FUN_1410ad670()
{
    return m_spItem.get();
}
MS2_REPLACE_METHOD(0x1410AD670, Unk_PCCubeCraft, FUN_1410ad670, 31, 0x62AC54AE);

// @0x1410ad6a0
int Unk_PCCubeCraft::FUN_1410ad6a0(int nItemId)
{
    if (m_nMode == 0 || m_nMode == 2)
    {
        if (nItemId == 0)
            return 0;
        MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
        if (spData.operator==(0))
            return 0;
        if (spData->install.objCode != 0)
            return FUN_1407072e0(spData->install.objCode);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1410AD6A0, Unk_PCCubeCraft, FUN_1410ad6a0, 203, 0xC8401064);

// @0x1410af0c0
void Unk_PCCubeCraft::FUN_1410af0c0()
{
}
MS2_REPLACE_METHOD(0x1410AF0C0, Unk_PCCubeCraft, FUN_1410af0c0, 6, 0xA9AF6E37);

// @0x1410af0d0
void Unk_PCCubeCraft::ReleaseGuide3()
{
    if (m_spGuide3.get() != 0)
    {
        m_spGuide3->vfunc_11();
        m_spGuide3 = 0;
    }
}
MS2_REPLACE_METHOD(0x1410AF0D0, Unk_PCCubeCraft, ReleaseGuide3, 99, 0xA27E20ED);

// @0x1410af140
void Unk_PCCubeCraft::UpdateGuide3Rotation()
{
    Vector3 kAngles = FUN_140a0b080(m_ptOffset, m_ptCell, reinterpret_cast<const Vector3&>(efd::Point3::UNIT_Z));
    NiMatrix3 kRot;
    FUN_140b86230(reinterpret_cast<efd::Point3&>(kAngles), kRot);
    m_spGuide3->vfunc_4(kRot);
}
MS2_REPLACE_METHOD(0x1410AF140, Unk_PCCubeCraft, UpdateGuide3Rotation, 165, 0xDD10B97A);

// @0x1410add30
void Unk_PCCubeCraft::FUN_1410add30()
{
    if (m_pOwner == 0)
        return;
    if (((class PC*)(m_pOwner))->FUN_141656750() == 0)
        return;
    if (m_spEffectA.get() != 0)
        m_pOwner->vfunc_128(m_spEffectA.get(), 0);
    if (m_spEffectB.get() != 0)
        m_pOwner->vfunc_128(m_spEffectB.get(), 0);
    if (m_spEffectC.get() != 0)
        m_pOwner->vfunc_128(m_spEffectC.get(), 0);
    m_spEffectA = 0;
    m_spEffectB = 0;
    m_spEffectC = 0;
}
MS2_REPLACE_METHOD(0x1410ADD30, Unk_PCCubeCraft, FUN_1410add30, 406, 0xD4BBE5C0);

// @0x1410ad780
void Unk_PCCubeCraft::FUN_1410ad780()
{
    if (m_pOwner == 0)
        return;
    m_spEffectA.AssignRaw(new CItem);
    if (!m_spEffectA->FUN_140523c40(((struct Unk_C2Consts*)FUN_1401d3200())->m_effectA.Read(), 1, 0))
    {
        m_spEffectA = 0;
        return;
    }
    m_spEffectA->SetObjectId(m_pOwner->FUN_14123c580());
    m_spEffectA->SetItemUid(FUN_14028d0e0());
    m_spEffectA->FUN_140526c10(6);
    m_spEffectA->FUN_14052a130(5);
    m_pOwner->vfunc_127(m_spEffectA.get(), 0);
    if (((class PC*)(m_pOwner))->IsCubeMode1() == 0)
        return;
    m_spEffectB.AssignRaw(new CItem);
    if (!m_spEffectB->FUN_140523c40(FUN_140ec2b60(&((struct Unk_C2Consts*)FUN_1401d3200())->m_effectB), 1, 0))
    {
        m_spEffectB = 0;
        return;
    }
    m_spEffectB->SetObjectId(m_pOwner->FUN_14123c580());
    m_spEffectB->SetItemUid(FUN_14028d0e0());
    m_spEffectB->FUN_140526c10(4);
    m_spEffectB->FUN_14052a130(5);
    m_pOwner->vfunc_127(m_spEffectB.get(), 0);
    m_spEffectC.AssignRaw(new CItem);
    if (!m_spEffectC->FUN_140523c40(FUN_140ec2b60(&((struct Unk_C2Consts*)FUN_1401d3200())->m_effectC), 1, 0))
    {
        m_spEffectC = 0;
        return;
    }
    m_spEffectC->SetObjectId(m_pOwner->FUN_14123c580());
    m_spEffectC->SetItemUid(FUN_14028d0e0());
    m_spEffectC->FUN_140526c10(5);
    m_spEffectC->FUN_14052a130(5);
    m_pOwner->vfunc_127(m_spEffectC.get(), 0);
}
MS2_REPLACE_METHOD(0x1410AD780, Unk_PCCubeCraft, FUN_1410ad780, 1450, 0xC4517146);

// @0x1410aa6f0
void Unk_PCCubeCraft::FUN_1410aa6f0(Vector3 kPos, bool bNoUpdate)
{
    if (m_spGuide.operator==(0))
        return;
    bool bMoved = reinterpret_cast<const efd::Point3&>(kPos) != reinterpret_cast<const efd::Point3&>(m_ptCell);
    if (bMoved)
    {
        if (m_svc->HasCubeAtPoint(kPos))
        {
            MS2Ptr<Cube> spOld(m_svc->GetCubeAtPoint(kPos));
            float fScale;
            spOld->entity->GetPropertyValue<float>(0x2d7cad2d, fScale);
            GetCubeMotionManager()->AddScale(spOld->entity->GetEntityID(), fScale, m_fScale, 200);
        }
    }
    MS2Ptr<Cube> spCell(m_svc->GetCubeAtPoint(m_ptCell));
    if (spCell.get() != 0)
    {
        bool bGrow = false;
        if (bGrow)
            SetGuideVisible(false);
        else
        {
            bool bShift = ((class Unk_C2UiMgr*)FUN_140b632f0())->FUN_1410af770();
            if (!bShift)
                SetGuideVisible(true);
        }
        if (bMoved)
        {
            float fCur;
            spCell->entity->GetPropertyValue<float>(0x2d7cad2d, fCur);
            Unk_CmScale kScale;
            if (GetCubeMotionManager()->FUN_14115b4c0(spCell->entity->GetEntityID(), kScale))
                m_fScale = kScale.m_fTo;
            else
                m_fScale = fCur;
            if (bGrow)
            {
                GetCubeMotionManager()->AddScale(spCell->entity->GetEntityID(), fCur, m_fScale + 0.05f, 200);
            }
            else if (((class CFeatureManager*)FUN_140166410())->IsRegionCN() && m_bVisible)
            {
                GetCubeMotionManager()->AddScale(spCell->entity->GetEntityID(), fCur, m_fScale - 0.05f, 200);
            }
        }
    }
    else
    {
        bool bShift = ((class Unk_C2UiMgr*)FUN_140b632f0())->FUN_1410af770();
        if (!bShift)
            SetGuideVisible(true);
    }
    MS2Ptr<CItemData> spData = FUN_14053f870(FUN_1410ad610());
    NiPoint3 kAngles = m_pOwner->vfunc_20();
    kAngles.z = ((class PCBase*)(class PC*)(m_pOwner))->GetTargetYaw();
    kAngles.z = (float)(int)((kAngles.z + 89.0f) / 90.0f) * 90.0f;
    kAngles.z += m_fYaw;
    NiMatrix3 kRot;
    FUN_140b86230(kAngles, kRot);
    m_spGuide->vfunc_4(kRot);
    if (m_spGuide3.get() != 0)
        UpdateGuide3Rotation();
    if (!bNoUpdate)
        UpdateGuidePositions();
}

// @0x1410aad50
void Unk_PCCubeCraft::FUN_1410aad50()
{
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    if (((class PC*)(pPC))->IsCubeMode1() != 0 && ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0()) == 0)
        return;
    if (GetMode() == 1)
    {
        reinterpret_cast<Unk_MyPCHousingSvc*>(m_svc.operator->())->FUN_1410d6590(0x39);
        return;
    }
    if (m_spGuide.operator==(0))
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(FUN_1410ad610());
    if (!spData)
        return;
    if (GetMode() != 2)
    {
        if (((class MyPC*)(class PC*)(pPC))->FUN_1415302e0(FUN_1410ad610()))
        {
            reinterpret_cast<Unk_MyPCHousingSvc*>(m_svc.operator->())->FUN_1410d6590(0x58);
            return;
        }
    }
    if (((class CItemData*)(spData.operator->()))->HasCubeTextureMesh())
    {
        CubeItemInfo* pCur = FUN_1410ad670();
        if (pCur != 0 && pCur->FUN_1408b3860() == 0)
        {
            reinterpret_cast<Unk_MyPCHousingSvc*>(m_svc.operator->())->FUN_1410d6590(0x62);
            return;
        }
    }
    MS2Ptr<Cube> spCell(m_svc->GetCubeAtPoint(m_ptCell));
    if (GetMode() == 2 && spData->install.attachable != 0)
    {
        FUN_1410aded0();
    }
    else
    {
        if (!spCell)
        {
            Vector3 kEuler;
            if (((class PC*)(pPC))->IsCubeMode1() != 0)
            {
                Unk_C2Lift* pLift = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0());
                kEuler = pLift->vfunc_20();
                kEuler.z = kEuler.z + spData->install.staticAngle;
            }
            else
            {
                NiMatrix3 kRot = m_spGuide->vfunc_5();
                kRot.ToEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
                reinterpret_cast<efd::Point3&>(kEuler) *= -57.295776f;
            }
            if (kEuler.z < 0.0)   // the exe compares in double
                kEuler.z = (float)(int)((kEuler.z - 89.0f) / 90.0f) * 90.0f;
            else
                kEuler.z = (float)(int)((kEuler.z + 89.0f) / 90.0f) * 90.0f;
            FUN_140291b70(&kEuler.z);
            CubeItemInfo kInfo(*m_spItem.get());
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.Encode1(10);
            packet.Encode4(FUN_1408a13d0((const NiPoint3&)m_ptCell));
            kInfo.FUN_1408b39c0(packet);
            packet.WriteFloat(kEuler.z);
            FUN_140710590(packet);
        }
        else
        {
            if (((class Cube*)(spCell.operator->()))->FUN_1408b4f20() != FUN_1410ad610() || ((class CubeItemInfo*)(spCell->item.operator->()))->FUN_1408b38c0((class CubeItemInfo const*)(FUN_1410ad670())) == 0)
            {
                Vector3 kEuler;
                if (((class PC*)(pPC))->IsCubeMode1() != 0)
                {
                    Unk_C2Lift* pLift = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0());
                    kEuler = pLift->vfunc_20();
                    kEuler.z = kEuler.z + spData->install.staticAngle;
                }
                else
                {
                    NiMatrix3 kRot = m_spGuide->vfunc_5();
                    kRot.ToEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
                    reinterpret_cast<efd::Point3&>(kEuler) *= -57.295776f;
                }
                if (kEuler.z < 0.0)   // the exe compares in double
                    kEuler.z = (float)(int)((kEuler.z - 89.0f) / 90.0f) * 90.0f;
                else
                    kEuler.z = (float)(int)((kEuler.z + 89.0f) / 90.0f) * 90.0f;
                Unk_Int3 kGrid = FUN_1408a1430((const NiPoint3&)m_ptCell);
                CubeItemInfo kInfo(*m_spItem.get());
                COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
                packet.Encode1(0xf);
                packet.Encode4(FUN_1408a03c0(kGrid));
                kInfo.FUN_1408b39c0(packet);
                packet.WriteFloat(kEuler.z);
                FUN_140710590(packet);
            }
            else
            {
                if (((class Cube*)(spCell.operator->()))->FUN_1408b4f20() == FUN_1410ad610())
                {
                    if (((class PC*)(pPC))->FUN_141659690() != 0)
                    {
                        FUN_141275260(0x6c9, 1, 1);
                        FUN_141276180(DAT_143acf6b8, "");
                    }
                    else
                    {
                        reinterpret_cast<Unk_MyPCHousingSvc*>(m_svc.operator->())->FUN_1410d6590(0x35);
                    }
                }
            }
        }
    }
}

// @0x1410ab5a0
void Unk_PCCubeCraft::FUN_1410ab5a0()
{
    FUN_1410ab5c0(true);
}
MS2_REPLACE_METHOD(0x1410AB5A0, Unk_PCCubeCraft, FUN_1410ab5a0, 26, 0x3243A98E);

// @0x1410ab5c0
void Unk_PCCubeCraft::FUN_1410ab5c0(bool bNotice)
{
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    Vector3 kCell = m_ptCell;
    if (m_spGuide.operator==(0))
    {
        Vector3 kFront;
        Vector3 kOut;
        if (((class PC*)(pPC))->IsCubeMode1() != 0)
        {
            Unk_C2Lift* pLift = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0());
            if (pLift != 0)
                m_svc->FUN_1410b7ba0(pLift->vfunc_18(), pLift->vfunc_20(), -200.0f, &kFront, 0);
        }
        else
        {
            m_svc->GetCellInFrontOfActor(pPC, m_fLift, &kFront, 1);
        }
        m_svc->GetCellPosition(kFront, &kOut);
    }
    if (GetMode() == 1 || GetMode() == 0 || GetMode() == 2)
    {
        if (m_svc->HasCubeAtPoint(kCell))
        {
            MS2Ptr<Cube> spCube(m_svc->GetCubeAtPoint(kCell));
            if (m_svc->FUN_1410c6980(spCube.get(), spCube->field44, 0, ((class PC*)(pPC))->FUN_141656ad0(), 3) == 0)
            {
                reinterpret_cast<Unk_MyPCHousingSvc*>(m_svc.operator->())->FUN_1410d6590(0x1b);
                return;
            }
            Unk_CmRotate kRot;
            if (GetCubeMotionManager()->FUN_14115b500(spCube->entity->GetEntityID(), kRot))
                return;
            Unk_Int3 kGrid = FUN_1408a1430((const NiPoint3&)kCell);
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.Encode1(0xe);
            packet.Encode4(FUN_1408a03c0(kGrid));
            packet.WriteBool(bNotice);
            FUN_140710590(packet);
        }
        else
        {
            reinterpret_cast<Unk_MyPCHousingSvc*>(m_svc.operator->())->FUN_1410d6590(0x1a);
        }
    }
}

// @0x1410abb40
void Unk_PCCubeCraft::FUN_1410abb40()
{
    if (GetMode() == 2)
        return;
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    Vector3 kCell = m_ptCell;
    if (m_spGuide.operator==(0))
    {
        Vector3 kFront;
        Vector3 kSpare;
        if (((class PC*)(pPC))->IsCubeMode1() != 0)
        {
            Unk_C2Lift* pLift = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0());
            if (pLift != 0)
                m_svc->FUN_1410b7ba0(reinterpret_cast<const Vector3&>(static_cast<const Vector3&>(pLift->vfunc_18())),
                    reinterpret_cast<const Vector3&>(static_cast<const Vector3&>(pLift->vfunc_20())), -200.0f, &kFront, 0);
        }
        else
        {
            m_svc->GetCellInFrontOfActor(pPC, m_fLift, &kFront, 1);
        }
        m_svc->GetCellPosition(kFront, &kCell);
    }
    if (m_svc->HasCubeAtPoint(kCell))
    {
        MS2Ptr<Cube> spCube(m_svc->GetCubeAtPoint(m_ptCell));
        Unk_Int3 kGrid = FUN_1408a1430((const NiPoint3&)kCell);
        bool bTake = true;
        if (!bTake && spCube->field60 != 0)
        {
            if (m_svc->FUN_1410c6980(spCube.get(), spCube->field44, 0, ((class PC*)(pPC))->FUN_141656ad0(), 4) == 0)
            {
                reinterpret_cast<Unk_MyPCHousingSvc*>(m_svc.operator->())->FUN_1410d6590(0x28);
                return;
            }
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.Encode1(0xd);
            packet.Encode4(FUN_1408a03c0(kGrid));
            FUN_140710590(packet);
        }
        else
        {
            if (m_svc->FUN_1410c6980(spCube.get(), spCube->field44, 0, ((class PC*)(pPC))->FUN_141656ad0(), 4) == 0)
            {
                reinterpret_cast<Unk_MyPCHousingSvc*>(m_svc.operator->())->FUN_1410d6590(0x28);
                return;
            }
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.Encode1(0xc);
            packet.Encode4(FUN_1408a03c0(kGrid));
            FUN_140710590(packet);
        }
        if (spCube->field44 == 2)
        {
            reinterpret_cast<CGuideManager*>(FUN_1409331e0())->AddTrigger((CGuideManager::TriggerType)7, ((class Cube*)(spCube.operator->()))->FUN_1408b4f20(), 0);
        }
    }
    else
    {
        reinterpret_cast<Unk_MyPCHousingSvc*>(m_svc.operator->())->FUN_1410d6590(0x14);
    }
}

// @0x1410ac1c0
void Unk_PCCubeCraft::FUN_1410ac1c0()
{
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    unsigned nFirst = 0;
    unsigned nSecond = 0;
    FUN_1410ae960(&nFirst, &nSecond);
    if (nFirst == 0)
    {
        FUN_141275260(0x6f4, 1, 1);
    }
    else
    {
        AdjustLift(1);
        if (FUN_1410af7a0(pPC) != 0)
        {
            Unk_C2Lift* pLift = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0());
            Unk_Int3 kDir(0, 0, 1);
            efd::SmartPointer<CubeMapInformationService> spSvc = egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>();
            if (spSvc->FUN_1410cdd80(pLift->vfunc_18(), pLift->vfunc_20(), 200.0f, kDir) != 0)
                FUN_1410a77e0(reinterpret_cast<CGuideObject*>(pLift), 6.0f);
        }
    }
}
MS2_REPLACE_METHOD(0x1410AC1C0, Unk_PCCubeCraft, FUN_1410ac1c0, 438, 0x354524C7);

// @0x1410ac380
void Unk_PCCubeCraft::FUN_1410ac380()
{
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    unsigned nFirst = 0;
    unsigned nSecond = 0;
    FUN_1410ae960(&nFirst, &nSecond);
    if (nSecond == 0)
    {
        FUN_141275260(0x6f5, 1, 1);
    }
    else
    {
        AdjustLift(0);
        if (FUN_1410af7a0(pPC) != 0)
        {
            Unk_C2Lift* pLift = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0());
            Unk_Int3 kDir(0, 0, -2);
            efd::SmartPointer<CubeMapInformationService> spSvc = egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>();
            if (spSvc->FUN_1410cdd80(pLift->vfunc_18(), pLift->vfunc_20(), 200.0f, kDir) != 0)
                FUN_1410a77e0(reinterpret_cast<CGuideObject*>(pLift), -6.0f);
        }
    }
}
MS2_REPLACE_METHOD(0x1410AC380, Unk_PCCubeCraft, FUN_1410ac380, 438, 0x73645A07);

// @0x1410af7a0
int FUN_1410af7a0(PC* pPC)
{
    return ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0()) != 0;
}
MS2_REPLACE(0x1410AF7A0, FUN_1410af7a0, 51, 0xD550EB77);

// @0x1410ac540
void Unk_PCCubeCraft::FUN_1410ac540()
{
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    if (((class PC*)(pPC))->IsInCubeMode() == 0)
        return;
    Vector3 kCell = m_ptCell;
    if (m_spGuide.operator==(0))
    {
        Vector3 kFront;
        Vector3 kSpare;
        if (((class PC*)(pPC))->IsCubeMode1() != 0)
        {
            Unk_C2Lift* pLift = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0());
            if (pLift != 0)
                m_svc->FUN_1410b7ba0(pLift->vfunc_18(), pLift->vfunc_20(), -200.0f, &kFront, 0);
        }
        else
        {
            m_svc->GetCellInFrontOfActor(pPC, m_fLift, &kFront, 1);
        }
        m_svc->GetCellPosition(kFront, &kSpare);
    }
    if (GetMode() == 3)
        return;
    if (!m_svc->HasCubeAtPoint(kCell))
        return;
    MS2Ptr<Cube> spCube(m_svc->GetCubeAtPoint(kCell));
    if (spCube.operator==(0))
        return;
    if (FUN_140707bc0(spCube->fieldB4) == 0)
        return;
    CObjectData* pRow = FUN_140704ec0(spCube->fieldB4).get();
    if (pRow == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
    packet.Encode1(0xd);
    packet.Encode4(FUN_1408a13d0((const NiPoint3&)kCell));
    FUN_140710590(packet);
}

// @0x1410aded0
void Unk_PCCubeCraft::FUN_1410aded0()
{
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    MS2Ptr<Cube> spCube(m_svc->GetCubeAtPoint(m_ptCell));
    Unk_Int3 kGrid = FUN_1408a1430((const NiPoint3&)m_ptCell);
    Vector3 kPos;
    int nCell = 0;
    if (((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0()) != 0)
        kPos = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0())->vfunc_20();
    else
        kPos = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pPC->vfunc_20()));
    nCell = m_svc->FUN_1410ba5f0(kGrid, kPos);
    kPos.z = m_svc->DirectionToAngle(nCell);
    CubeItemInfo kInfo(*m_spItem.operator->());
    if (!spCube)
    {
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.Encode1(0xb);
        packet.Encode4(FUN_1408a03c0(kGrid));
        kInfo.FUN_1408b39c0(packet);
        packet.WriteFloat(kPos.z);
        packet.Encode1((unsigned char)nCell);
        FUN_140710590(packet);
    }
    else if (((class Cube*)(spCube.operator->()))->FUN_1408b4f20() != FUN_1410ad610()
        || ((class CubeItemInfo*)(spCube->item.operator->()))->FUN_1408b38c0((class CubeItemInfo const*)(FUN_1410ad670())) == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.Encode1(0x10);
        packet.Encode4(FUN_1408a03c0(kGrid));
        kInfo.FUN_1408b39c0(packet);
        packet.WriteFloat(kPos.z);
        packet.Encode1((unsigned char)nCell);
        FUN_140710590(packet);
    }
    else if (((class Cube*)(spCube.operator->()))->FUN_1408b4f20() == FUN_1410ad610())
    {
        if (((class PC*)(pPC))->FUN_141659690() != 0)
        {
            FUN_141275260(0x6c9, 1, 1);
            FUN_141276180(DAT_143acf6b8, "");
        }
        else
        {
            reinterpret_cast<Unk_MyPCHousingSvc*>(m_svc.operator->())->FUN_1410d6590(0x35);
        }
    }
}

// @0x1410ae380
void Unk_PCCubeCraft::FUN_1410ae380(Vector3 kPos)
{
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    if (m_nMode == 2)
    {
        m_nCheck = 1;
        return;
    }
    if (m_nMode == 0 || m_nMode == 2)
    {
        Unk_Int3 kGrid = FUN_1408a1430((const NiPoint3&)kPos);
        MS2Ptr<CItemData> spData = FUN_14053f870(FUN_1410ad610());
        if (!spData)
            return;
        MS2Ptr<Cube> spCube(m_svc->GetCubeAtPoint(m_ptCell));
        if (GetMode() == 2 && spData->install.attachable != 0)
        {
            Vector3 kFoot;
            if (((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0()) != 0)
                kFoot = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0())->vfunc_20();
            else
                kFoot = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pPC->vfunc_20()));
            int nCell = m_svc->FUN_1410ba5f0(kGrid, kFoot);
            if (!spCube)
            {
                unsigned nErr;
                CUGCBuildValidatorCli kValidator(static_cast<const Unk_CubePoint&>(kGrid), FUN_1410ad670(), nCell);
                m_nCheck = kValidator.vfunc_37(&nErr);
            }
            else if (((class Cube*)(spCube.operator->()))->FUN_1408b4f20() != FUN_1410ad610()
                || ((class CubeItemInfo*)(spCube->item.operator->()))->FUN_1408b38c0((class CubeItemInfo const*)(FUN_1410ad670())) == 0)
            {
                unsigned nErr;
                CUGCBuildValidatorCli kValidator(static_cast<const Unk_CubePoint&>(kGrid), FUN_1410ad670(), nCell);
                m_nCheck = kValidator.vfunc_39(&nErr);
            }
            else if (((class Cube*)(spCube.operator->()))->FUN_1408b4f20() == FUN_1410ad610())
            {
                m_nCheck = 0;
            }
        }
        else
        {
            if (!spCube)
            {
                unsigned nErr;
                CUGCBuildValidatorCli kValidator(static_cast<const Unk_CubePoint&>(kGrid), FUN_1410ad670());
                m_nCheck = kValidator.vfunc_36(&nErr);
            }
            else if (((class Cube*)(spCube.operator->()))->FUN_1408b4f20() != FUN_1410ad610()
                || ((class CubeItemInfo*)(spCube->item.operator->()))->FUN_1408b38c0((class CubeItemInfo const*)(FUN_1410ad670())) == 0)
            {
                unsigned nErr;
                CUGCBuildValidatorCli kValidator(static_cast<const Unk_CubePoint&>(kGrid), FUN_1410ad670());
                m_nCheck = kValidator.vfunc_38(&nErr);
            }
            else if (((class Cube*)(spCube.operator->()))->FUN_1408b4f20() == FUN_1410ad610())
            {
                m_nCheck = 0;
            }
        }
    }
    else
    {
        m_nCheck = 0;
    }
}

// @0x1410ae960
void Unk_PCCubeCraft::FUN_1410ae960(unsigned* pLeft, unsigned* pRight)
{
    *pRight = 0;
    *pLeft = 0;
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    Vector3 kFloor;
    m_svc->GetCellInFrontOfActor(pPC, 0, &kFloor, 1);
    Unk_Int3 kFloorGrid = FUN_1408a1430((const NiPoint3&)kFloor);
    Vector3 kTop;
    m_svc->GetCellInFrontOfActor(pPC, m_fLift, &kTop, 1);
    Unk_Int3 kTopGrid = FUN_1408a1430((const NiPoint3&)kTop);
    if (GetMode() == 2)
    {
        *pLeft = kTopGrid.z - kFloorGrid.z < *((struct Unk_C2Consts*)FUN_1401d3200())->m_liftUp.Get();
        *pRight = kFloorGrid.z - kTopGrid.z < *((struct Unk_C2Consts*)FUN_1401d3200())->m_liftDown.Get();
        if (DAT_143ae0fb4 != 0)
        {
            *pRight = 1;
            *pLeft = 1;
        }
    }
    else
    {
        if (FUN_1410af7a0(pPC) != 0)
        {
            Unk_C2Lift* pLift = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0());
            Unk_Int3 kUp(0, 0, 1);
            *pLeft = m_svc->FUN_1410cdd80(pLift->vfunc_18(), pLift->vfunc_20(), 200.0f, kUp);
            Unk_Int3 kDown(0, 0, -2);
            *pRight = m_svc->FUN_1410cdd80(pLift->vfunc_18(), pLift->vfunc_20(), 200.0f, kDown);
        }
        else
        {
            Unk_Int3 kUp(0, 0, 1);
            *pLeft = m_svc->FUN_1410cdf60(kTopGrid, kUp);
            Unk_Int3 kDown(0, 0, -1);
            *pRight = m_svc->FUN_1410cdf60(kTopGrid, kDown);
        }
    }
    if (DAT_143ae0fb4 != 0)
    {
        *pRight = 1;
        *pLeft = 1;
    }
}

// @0x1410aeec0
void Unk_PCCubeCraft::FUN_1410aeec0(const Vector3& kPos)
{
    Cube* pCube = 0;
    Unk_Int3 kCell = FUN_1408a1430((const NiPoint3&)kPos);
    kCell.z = kCell.z - 1;
    pCube = m_svc->GetCubeAtCell(kCell);
    if (pCube == 0)
    {
        FUN_1408a15b0(kCell, reinterpret_cast<efd::Point3&>(const_cast<Vector3&>(kPos)));
    }
    else
    {
        kCell.z = kCell.z + 1;
        pCube = m_svc->GetCubeAtCell(kCell);
        if (pCube == 0)
        {
            FUN_1408a15b0(kCell, reinterpret_cast<efd::Point3&>(const_cast<Vector3&>(kPos)));
        }
        else
        {
            kCell.z = kCell.z + 1;
            pCube = m_svc->GetCubeAtCell(kCell);
            if (pCube == 0)
                FUN_1408a15b0(kCell, reinterpret_cast<efd::Point3&>(const_cast<Vector3&>(kPos)));
        }
    }
}
MS2_REPLACE_METHOD(0x1410AEEC0, Unk_PCCubeCraft, FUN_1410aeec0, 494, 0x9CC59312);

// @0x1410af1f0
void Unk_PCCubeCraft::FUN_1410af1f0()
{
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    if (pPC != m_pOwner)
        return;
    ATL::CAtlArray<MS2Ptr<CQuest>> quests;
    reinterpret_cast<CQuestManager*>(FUN_140764020())->GetQuestsFiltered(quests, 1, 0xb, -1);
    int nLiftId = 0;
    for (size_t i = 0; i < quests.GetCount(); ++i)
    {
        MS2Ptr<CQuest> spQuest(quests[i]);
        if (spQuest.IsNull())
            continue;
        MS2Ptr<CQuestData> spData = spQuest->GetData();
        for (size_t j = 0; j < spData->m_conditions.GetCount(); ++j)
        {
            if (spData->m_conditions[j]->m_nType != 0x9c)
                continue;
            if (spData->m_conditions[j]->m_code.Matches((unsigned)FUN_1410ad610()) == 0)
                continue;
            if (spData->m_conditions[j]->m_target.GetIdCount() != 1)
                continue;
            nLiftId = (int)spData->m_conditions[j]->m_target.GetFirstValue();
        }
        if (nLiftId != 0)
            break;
    }
    if (nLiftId == 0)
        return;
    std::vector<MS2Ptr<Unk_AkoLiftTarget>> aLifts;
    reinterpret_cast<Unk_C2World*>(WorldService::GetInstance())->FUN_141bc5980(&aLifts);
    for (size_t k = 0; k < aLifts.size(); ++k)
    {
        MS2Ptr<Unk_AkoLiftTarget> spLift = aLifts[k];
        if (spLift->FUN_1410af780() != nLiftId)
            continue;
        m_svc->GetCellPosition(spLift->FUN_1409673f0(), &m_ptOffset);
        break;
    }
}

// @0x1410ac9b0
void Unk_PCCubeCraft::FUN_1410ac9b0()
{
    if (m_spGuide.operator==(0))
        return;
    m_spGuide->vfunc_1();
    if (m_spGuide3.get() != 0)
        m_spGuide3->vfunc_1();
    PC* pPC = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == m_pOwner)
    {
        if (((class PCBase*)(class PC*)(pPC))->GetCurStateId() == 0x10)
        {
            SetGuideVisible(false);
            SetGuide2Visible(false);
            m_nHud = 0;
            return;
        }
        else if (m_nHud == 0)
        {
            SetGuideVisible(true);
            SetGuide2Visible(true);
            m_nHud = 1;
        }
        Vector3 kFront;
        Vector3 kDown;
        if (((class PC*)(pPC))->IsCubeMode1() != 0)
        {
            Unk_C2Lift* pLift = ((class Unk_C2Lift*)((class PC*)(pPC))->FUN_1416625b0());
            if (pLift != 0)
                m_svc->FUN_1410b7ba0(pLift->vfunc_18(), pLift->vfunc_20(), -200.0f, &kFront, 0);
        }
        else
        {
            m_svc->GetCellInFrontOfActor(pPC, m_fLift, &kFront, 1);
            if (((class PC*)(pPC))->FUN_141659690() != 0)
                FUN_1410aeec0(kFront);
        }
        m_svc->GetCellPosition(kFront, &kDown);
        if (true)
        {
            int nOldCheck = m_nCheck;
            FUN_1410ae380(m_ptCell);
            if (nOldCheck != m_nCheck)
                FUN_1410a92c0();
        }
        if (reinterpret_cast<const efd::Point3&>(kDown) != reinterpret_cast<const efd::Point3&>(m_ptCell))
        {
            Vector3 kOld = m_ptCell;
            m_ptLast = reinterpret_cast<Unk_C2GuideSlots*>(m_spGuide.operator->())->vfunc_3();
            m_ptCell = kDown;
            m_tSlide.FUN_140868750(200);
            bool bSameColumn = false;
            if (kOld.x == m_ptCell.x && kOld.y == m_ptCell.y && kOld.z != m_ptCell.z)
                bSameColumn = true;
            FUN_1410aa6f0(kOld, bSameColumn);
            if (((class PC*)(pPC))->FUN_141659690() == 0 && m_bFirstMove != 0)
                FUN_141276180(DAT_143acf6c0, "");
            if (m_bFirstMove == 0)
                m_bFirstMove = 1;
        }
        if ((GetMode() == 0 || GetMode() == 2)
            && (m_tRotate.FUN_140868ba0() != 0 || m_tRotate.FUN_140868c00() != 0))
        {
            float fEase = Unk_EaseOut().Evaluate(m_tRotate.FUN_140868940());
            float fYaw = m_fRotFrom + (m_fRotTo - m_fRotFrom) * fEase;
            Vector3 kAngles;
            NiMatrix3 kCur = m_spGuide->vfunc_5();
            kCur.ToEulerAnglesXYZ(kAngles.x, kAngles.y, kAngles.z);
            kAngles.x = kAngles.x * -57.295776f;
            kAngles.y = kAngles.y * -57.295776f;
            kAngles.z = fYaw;
            NiMatrix3 kRot;
            FUN_140b86230((const efd::Point3&)kAngles, kRot);
            m_spGuide->vfunc_4(kRot);
            if (m_tRotate.FUN_140868c00() != 0)
                m_tRotate.FUN_1408687f0();
        }
        if (m_tSlide.FUN_140868ba0() != 0 || m_tSlide.FUN_140868c00() != 0)
        {
            float fEase = Unk_EaseOut().Evaluate(m_tSlide.FUN_140868940());
            Vector3 kDelta = m_ptCell.FUN_140965c40(m_ptLast);
            float fLen = kDelta.FUN_140967ac0();
            kDelta.FUN_140968990();
            kDown = m_ptLast.FUN_14097fd50(kDelta.FUN_14097fc90(fEase).FUN_14097fc90(fLen));
            reinterpret_cast<Unk_C2GuideSlots*>(m_spGuide.operator->())->vfunc_2((const NiPoint3&)kDown);
            if (m_spGuide3.get() != 0)
            {
                Vector3 kUp = kDown;
                kUp.z = kUp.z + 150.0f;
                reinterpret_cast<Unk_C2GuideSlots*>(m_spGuide3.operator->())->vfunc_2((const NiPoint3&)kUp);
            }
            if (m_tSlide.FUN_140868c00() != 0)
                m_tSlide.FUN_1408687f0();
        }
        if (m_tPulse.FUN_140868ba0() != 0 || m_tPulse.FUN_140868c00() != 0)
        {
            if (m_tPulse.FUN_140868940() <= 0.5f)
            {
                float fIn = Unk_EaseOut().Evaluate(m_tPulse.FUN_140868940() * 2.0f);
                float fScale = 1.0f + 0.20000005f * fIn;
                m_spGuide->vfunc_9(fScale);
            }
            else
            {
                float fOut = Unk_C2Ease().FUN_1410af700((m_tPulse.FUN_140868940() - 0.5f) * 2.0f);
                float fScale = 1.2f + -0.20000005f * fOut;
                m_spGuide->vfunc_9(fScale);
                if (m_tPulse.FUN_140868c00() != 0)
                    m_tPulse.FUN_1408687f0();
            }
        }
        if (m_spGod.get() != 0)
        {
            m_spGod->FUN_141374d40(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pPC->vfunc_18())));
            m_spGod->FUN_141374dd0(((PCBase*)pPC)->FUN_14166d240());
        }
    }
}

// @0x1410af700
float Unk_C2Ease::FUN_1410af700(float t)
{
    if (!(0.0f <= t))
        return 0.0f;
    if (t > 1.0f)
        return 1.0f;
    return 1.0f - sqrt(1.0f - t * t);
}
MS2_REPLACE_METHOD(0x1410AF700, Unk_C2Ease, FUN_1410af700, 112, 0x6C45E1EF);

// @0x1410af790
CCubeMotionManager* GetCubeMotionManager()
{
    return TSingleton<CCubeMotionManager>::s_instance;
}
MS2_REPLACE(0x1410AF790, GetCubeMotionManager, 8, 0xEA0FC2F5);

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy).
// @0x1410af7e0
#pragma function(memset, memcpy)
static __inline errno_t ms2_memcpy_s_copy(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
#pragma intrinsic(memset, memcpy)
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cabf10-0x142cabfe0 .text$yd
