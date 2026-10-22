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
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cube.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/cubeguide.h"
#include "ms2/client/ms2/cubemapinformationservice_2.h"
#include "ms2/client/ms2/cubemotionmanager.h"
#include "ms2/commonfiles/ugcbuildvalidator.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/cconditioncommon.h"
#include <io.h>
#include <NiNode.h>
#include <efd/ServiceManager.h>

// ---- unit-local placeholders and externals ----

// The world service singleton: the local player and the scene.
class Unk_C2World
{
public:
    PC* FUN_141bd0cc0();                                            // the local player
    void FUN_141bd3920();                                           // refresh after a build mode change
    void FUN_141bc5980(void* pOut);                                 // copy the lift list into *pOut (std::vector<MS2Ptr<Unk_C2LiftObj>>)
};
Unk_C2World* FUN_1403ed2d0();

// A liftable object standing in the world (mirror of Unk_WsB_Lift in actionkeyobject.cpp).
class Unk_C2LiftObj : public CPtred
{
public:
    Unk_StreamPoint FUN_1409673f0();                                // the position
    int FUN_1410af780() { return m_nId; }                          // 0x1410af780
    int m_nId;                                                      // +0x18
};
MS2_CHECK_OFFSET(Unk_C2LiftObj, m_nId, 0x18);

class CQuestManager;
CQuestManager* FUN_140764020();
void FUN_1416cb8b0(CQuestManager* pMgr, ATL::CAtlArray<Unk_PayloadPtr<CQuest>>& out, int nState, int nType, int nChapter);

class Unk_C2SceneMgr
{
public:
    NiNode* FUN_1411a6b10();                                        // the scene root
};
Unk_C2SceneMgr* FUN_1403ed280();

class Unk_C2Log;
Unk_C2Log* FUN_140166440();
void FUN_1401859c0(Unk_C2Log* pLog, int nLevel, int nCategory, const wchar_t* pszFormat);

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
Unk_C2Config* FUN_1401d31f0();

struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;

// A 24-byte reason / filter record (constructed from 0) handed to the cube service checks.
class Unk_C2Reason
{
public:
    Unk_C2Reason* FUN_14052be80(int nValue);
    char m_pad[24];
};

// The cube grid service (class id 0x06100017); mirror of the one in actionkeyobject.cpp.
class Unk_Service6100017 : public efd::ISystemService
{
public:
    Unk_StreamPoint FUN_1410b7ad0(PC* pActor, float fDist, Unk_StreamPoint* pOut, int bSnap);   // the cell in front of the actor
    Unk_StreamPoint FUN_1410b7a20(Unk_StreamPoint pt, Unk_StreamPoint* pOut);                   // the cell position of a point
    Unk_StreamPoint FUN_1410b7ba0(Unk_StreamPoint ptFrom, Unk_StreamPoint ptTo, float fDist, Unk_StreamPoint* pOut, int bSnap);
    bool FUN_1410b7e80(Unk_StreamPoint pt);                                                     // a cube stands at a cell position
    Cube* FUN_1410b8a60(Unk_Int3 point);                                                      // the cube at a grid point
    Cube* FUN_1410b8ab0(Unk_StreamPoint pt);                                                    // the cube at a cell position
    void FUN_1410ce1e0(int nKind, int* pValue);
    int FUN_1410c6980(Cube* pCube, int nKind, Unk_C2Reason& rReason, __int64 nOwner, int nMode);   // may the cube be removed / moved
    int FUN_1410cdd80(Unk_StreamPoint ptFrom, Unk_StreamPoint ptTo, float fDist, Unk_Int3 kDir);   // the sweep from ptFrom to ptTo is free
    void FUN_1410d6590(int nMessage);                                                           // show the build notice
    int FUN_1410cdf60(Unk_Int3 kFrom, Unk_Int3 kDir);                                           // the column step is free
    int FUN_1410ba5f0(Unk_Int3 kGrid, Unk_StreamPoint kRef);                                    // the cell index of a grid point
    float FUN_1410ba440(int nCell);                                                             // the height of a cell
};
Unk_Service6100017* FUN_1401cd040(Unk_EntityAppFramework* pFramework);

// The client constants table: three consecutive 0x58-byte item-id constants at +0x39f0 (the guide effect items).
class Unk_C2ConstA { public: unsigned FUN_140536a30(); char m_pad[0x58]; };
class Unk_C2ConstB { public: int FUN_140ec2b60(); char m_pad[0x58]; };
class Unk_C2ConstI { public: int* FUN_1402056b0(); char m_pad[0x58]; };
struct Unk_C2Consts
{
    char m_pad_00[0x39f0];
    Unk_C2ConstA m_effectA;     // +0x39f0
    Unk_C2ConstB m_effectB;     // +0x3a48
    Unk_C2ConstB m_effectC;     // +0x3aa0
    Unk_C2ConstI m_liftUp;      // +0x3af8
    Unk_C2ConstI m_liftDown;    // +0x3b50
};
MS2_CHECK_OFFSET(Unk_C2Consts, m_effectC, 0x3aa0);
MS2_CHECK_OFFSET(Unk_C2Consts, m_liftDown, 0x3b50);
extern int DAT_143ae0fb4;
Unk_C2Consts* FUN_1401d3200();

efd::Point3 FUN_140a0b080(const efd::Point3& kFrom, const efd::Point3& kTo, const efd::Point3& kUp);   // look-at angles
void FUN_140b86230(const efd::Point3& kDegrees, NiMatrix3& out);

__int64 FUN_14028d0e0();
// The feature-flag holder and the UI manager (a flag at +10 is the shift key state).
class Unk_C2Features { public: bool FUN_14036e510(); };
Unk_C2Features* FUN_140166410();
class Unk_C2UiMgr
{
public:
    char m_pad_00[10];
    char m_bShift;                  // +0x0a
    char FUN_1410af770() { return m_bShift; }
};
Unk_C2UiMgr* FUN_140b632f0();
float FUN_14166da40(PC* pPC);

bool FUN_1415302e0(PC* pPC, int nItemId);
int FUN_1408b4f20(Cube* pCube);
int FUN_1408b38c0(CubeItemInfo* pA, CubeItemInfo* pB);
void FUN_1408b39c0(CubeItemInfo* pInfo, COutPacket& packet);   // encode the cube
int FUN_1408a03c0(Unk_Int3 point);
int FUN_1408a13d0(efd::Point3 kPos);
Unk_StreamPoint FUN_1408a15b0(Unk_Int3 cell, Unk_StreamPoint& ptCenter);   // fills the cell center
int FUN_141659690(PC* pPC);
int FUN_14166c930(PC* pPC);
__int64 FUN_14166d240(PC* pPC);
float FUN_14096b1c0(float f);
#include "ms2/placeholder/unk_1402a9d70.h"
// File statics of this TU (initialised by the .text$di entries; the hook build uses the exe's copies).
#ifndef MS2_HOOK_DLL
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400e5be0
static CString s_str143acf628("skill");                                                    // @0x1400e5ca0
static CString s_str143acf620("stun");                                                     // @0x1400e5cd0
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };           // ctor 0x1401cd100
static Unk_Handle1401cd100 s_dat_143acf668(0);                                             // @0x1400e5d00
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);                          // @0x1400e5d20
static CString DAT_143acf6b8("system_notice_error_warningNoBuild");                        // @0x1400e5d70
static CString DAT_143acf6c0("ugc_moveblock");                                             // @0x1400e5da0
#else
extern CString DAT_143acf6b8;
extern CString DAT_143acf6c0;
#endif
extern CCubeMotionManager* DAT_143acf6c8;

// Stateless easing curves (the object is a dummy).
struct Unk_C2Ease
{
    float FUN_140cd8c20(float t);       // ease out
    float FUN_1410af700(float t);       // 0x1410af700 ease in (1 - sqrt(1 - t^2))
};
void FUN_141275260(int nA, int nB, int nC);
int FUN_141276180(const CString& str, const CString& strArg);
bool FUN_14053d6f0(CItemData* pData);
void FUN_140291b70(float* pfDegrees);

__int64 FUN_141656ad0(PC* pPC);
void* FUN_1409331e0();
void FUN_14138bf00(void* pQuestManager, int nKind, int nValue, int nFlag);
int FUN_1416595d0(PC* pPC);
int FUN_140707bc0(int nId);
class Unk_C2Row;
struct Unk_C2RowPtr
{
    Unk_C2Row* FUN_140708ea0();
    void FUN_140708b20();
    void* m_pA;
    void* m_pB;
};
Unk_C2RowPtr* FUN_140704ec0(Unk_C2RowPtr* pOut, int nId);
int FUN_141659610(PC* pPC);
int FUN_141659650(PC* pPC);
int FUN_141656750(PC* pPC);
int FUN_141656a80(PC* pPC);

class CGodModeInfo : public CPtred
{
public:
    CGodModeInfo();
    void FUN_141374d10(int n);
    void FUN_141374b80(efd::Point3 kPos);
    void FUN_141374d40(efd::Point3 kPos);
    void FUN_141374dd0(__int64 nValue);
    char m_pad_18[0x30 - 0x18];
};
MS2_CHECK_SIZE(CGodModeInfo, 0x30);
int FUN_1408a18d0(int);
Unk_Int3 FUN_1408a1430(NiPoint3 kPos);

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
    virtual Unk_StreamPoint vfunc_18();
    virtual void vfunc_19();
    virtual Unk_StreamPoint vfunc_20();
    void FUN_1410a77e0(float fStep);
};
Unk_C2Lift* FUN_1416625b0(PC* pPC);
int FUN_1410af7a0(PC* pPC);

void FUN_1408b3810(CubeItemInfo*);
void FUN_1408b39c0(CubeItemInfo* pInfo, COutPacket& packet);
void FUN_140710590(COutPacket&);
CString FUN_1410280d0(int, CString);
MS2Ptr<CItemData> FUN_14053f870(int);
int FUN_1407072e0(int);

class Unk_C2DownloadMgr;
class Unk_GuideDownloadId
{
public:
    Unk_GuideDownloadId() {}
    unsigned __int64 value;
};
void FUN_1401cd100(Unk_GuideDownloadId*, int);
void FUN_1418845a0(Unk_C2DownloadMgr*, CubeItemInfo*, const Unk_GuideDownloadId&);
Unk_C2DownloadMgr* FUN_14052d220();

NiAVObject* FUN_141b6efc0(egf::Entity*);

// Virtual call helper: calls vtable slot nSlot of an object whose class is unknown here.
template <class R, class... A>
inline R CallSlot(void* pObj, int nSlot, A... args)
{
    typedef R (*Fn)(void*, A...);
    return (*(Fn**)pObj)[nSlot](pObj, args...);
}
// The node attachment owner (FUN_140a0b000(node)) answers vtable slot 37 with a handle that FUN_1405a85c0 releases.
struct Unk_C2Handle { void* m_pA; void* m_pB; };
// The node attachment owner: slot 37 detaches the node and returns a handle.
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
    virtual void vfunc_37(Unk_C2Handle* pOut, void* pNode);
};
Unk_C2NodeOwner* FUN_140a0b000(void* pNode);
void FUN_1405a85c0(Unk_C2Handle* pHandle);

CubeHolderManager* FUN_140ef0b20();                      // the cube palette holder

int FUN_140961880(egf::Entity* pEntity, unsigned uPropId, float* pOut);     // read a float property (0 = ok)
const egf::EntityID* FUN_1408b76f0(egf::Entity* pEntity);
CCubeMotionManager* GetCubeMotionManager();                        // the cube motion manager

// Housing quest-less globals.
extern efd::Point3 DAT_143a08cf8;                               // up vector
extern NiRTTI DAT_143afa4d8;

// Timers of the cube craft (declared in timer.h): m_tPulse (+0x70), m_tSlide (+0xa8), m_tRotate (+0xe0).

// ---- the cube craft controller ----

// @0x1410a8550
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
Unk_PCCubeCraft::Unk_PCCubeCraft(PC* pOwner, int nMode, CubeItemInfo* pInfo)
    : m_spGuide(0), m_spGuide2(0), m_spEffectA(0), m_spEffectB(0), m_spEffectC(0), m_spNode(0), m_svc((Unk_Service6100017*)0), m_spGod(0)
{
    m_fScale = 1.0f;
    m_bFirstMove = true;
    m_nCheck = 1;
    m_bVisible = true;
    m_bPending = false;
    m_pOwner = pOwner;
    m_nMode = nMode;
    m_nHud = 1;
    m_fLift = 0.0f;
    m_spItem.AssignRaw(new CubeItemInfo());
    m_spItem->FUN_1408b3700(pInfo);
    m_spItem2.AssignRaw(new CubeItemInfo());
    FUN_1408b3810(m_spItem2.operator->());
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
    FUN_1410a9e70();
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
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410a8af0(bool bEnable)
{
    if (!bEnable)
    {
        m_nCheck = 1;
        FUN_1410a9d60();
        FUN_1410a9e70();
        if (m_spGod.get() != 0)
            m_spGod = 0;
        if (m_svc->FUN_1410b7e80(m_ptCell))
        {
            MS2Ptr<Cube> spCube(m_svc->FUN_1410b8ab0(m_ptCell));
            float fScale;
            FUN_140961880(spCube->entity, 0x2d7cad2d, &fScale);
            egf::EntityID kId = *FUN_1408b76f0(spCube->entity);
            GetCubeMotionManager()->AddScale(kId, fScale, m_fScale, 200);
        }
        FUN_1410add30();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0 && pPC == m_pOwner)
        {
            int nValue = 0;
            m_svc->FUN_1410ce1e0(0, &nValue);
        }
    }
    else
    {
        m_svc = FUN_1401cd040(&DAT_143b059e8);
        m_tPulse.FUN_1408687f0();
        m_tSlide.FUN_1408687f0();
        m_bFirstMove = false;
        PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0 && pPC == m_pOwner)
        {
            m_fLift = 0.0f;
            Unk_StreamPoint kFront;
            Unk_StreamPoint kCell;
            if (FUN_141659610(pPC) == 0)
            {
                Unk_StreamPoint kTmp;
                m_svc->FUN_1410b7ad0(pPC, m_fLift, &kFront, 1);
            }
            else
            {
                Unk_C2Lift* pLift = FUN_1416625b0(pPC);
                if (pLift != 0)
                {
                    Unk_StreamPoint kRear = pLift->vfunc_20();
                    Unk_StreamPoint kHead = pLift->vfunc_18();
                    m_svc->FUN_1410b7ba0(kHead, kRear, -200.0f, &kFront, 0);
                }
            }
            m_svc->FUN_1410b7a20(kFront, &kCell);
            m_ptCell = kCell;
            int nValue = 0;
            m_svc->FUN_1410ce1e0(1, &nValue);
        }
        FUN_1410a9cc0();
        FUN_1410ad780();
        if (m_svc->FUN_1410b7e80(m_ptCell))
        {
            MS2Ptr<Cube> spCube(m_svc->FUN_1410b8ab0(m_ptCell));
            FUN_140961880(spCube->entity, 0x2d7cad2d, &m_fScale);
            Unk_StreamPoint kTop = m_ptCell;
            kTop.z = FLT_MAX;
            FUN_1410aa6f0(kTop, 0);
        }
        if (pPC != 0 && pPC == m_pOwner)
        {
            if (FUN_1416625b0(m_pOwner) == 0 && m_spGod == (CGodModeInfo*)0)
            {
                m_spGod.AssignRaw(new CGodModeInfo());
                m_spGod->FUN_141374b80(pPC->vfunc_18());
            }
            if (m_spGod.get() != 0)
                m_spGod->FUN_141374d10(FUN_1408a18d0(FUN_141656a80(m_pOwner)));
        }
    }
    FUN_1403ed2d0()->FUN_141bd3920();
}

// Creates the placement guide (a NIF model) for the local player.
// @0x1410a92c0
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410a92c0()
{
    FUN_1410a9d60();
    PC* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal != 0 && m_pOwner == pLocal)
    {
        CString strAsset("");
        if (m_nMode == 0 || m_nMode == 2)
        {
            if (m_nCheck == 0)
                strAsset = FUN_1401d31f0()->m_strGuideMove;
            else
                strAsset = FUN_1401d31f0()->m_strGuideBuild;
        }
        else
        {
            if (m_nMode != 1)
                return;
            FUN_1408b3810(m_spItem.operator->());
            strAsset = FUN_1401d31f0()->m_strGuideInventory;
        }
        CNifCubeGuide* pGuide = new CNifCubeGuide();
        if (pGuide->FUN_1410afc10(strAsset))
            m_spGuide.AssignRaw(pGuide);
        if (m_spGuide == (CCubeGuideWrapper*)0)
        {
            MS2_ASSERT_AT(0x12d, !"Failed to create GuideCube");
        }
        else
        {
            NiNode* pRoot = FUN_1403ed280()->FUN_1411a6b10();
            if (pRoot == 0)
                FUN_1401859c0(FUN_140166440(), 2, 0x13, L"SceneRoot NULL");
            m_spGuide->vfunc_10(pRoot, 0);
            m_spGuide->vfunc_8(0.5f);
            m_spGuide->vfunc_6(m_bVisible == 0);
            FUN_1410aa6f0(m_ptCell, 0);
        }
    }
}

// Creates the guide owned by the player's current item (NIF, KFM or fitting doll).
// @0x1410a9630
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410a9630()
{
    FUN_1410a9e70();
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
    if (FUN_1410ad6a0(nItemId) == 0)
    {
        if (strKfm.GetLength() == 0)
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
    }
    else
    {
        CFittingDollCubeGuide* pGuide = new CFittingDollCubeGuide();
        if (pGuide->FUN_1410b0ba0(1, m_pOwner->FUN_14123c580(), nItemId))
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
    if (m_spGuide2.get())
    {
        if (m_spItem->FUN_1408b3860() == 1)
        {
            CString strLook = FUN_1410280d0(2, m_spItem->look->m_strUrl);
            if (_access(strLook, 0) != 0)
            {
                Unk_GuideDownloadId kId;
                FUN_1401cd100(&kId, 0);
                FUN_1418845a0(FUN_14052d220(), m_spItem.get(), kId);
            }
            m_spGuide2->vfunc_15(m_spItem.get());
        }
    }
}

// @0x1410a9cc0
void Unk_PCCubeCraft::FUN_1410a9cc0()
{
    FUN_1410a9e70();
    FUN_1410a9d60();
    FUN_1410ae380(m_ptCell);
    FUN_1410a92c0();
    if (FUN_141659650(m_pOwner) != 0 && (m_nMode == 0 || m_nMode == 2))
        FUN_1410a9630();
}
MS2_REPLACE_METHOD(0x1410A9CC0, Unk_PCCubeCraft, FUN_1410a9cc0, 142, 0xECF33D2D);

// @0x1410a9d60
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410a9d60()
{
    m_fYaw = 0.0f;
    if (m_spNode != 0)
    {
        Unk_C2NodeOwner* pOwner = FUN_140a0b000(FUN_1409475f0(&m_spNode));
        if (pOwner != 0)
        {
            Unk_C2Handle kHandle;
            pOwner->vfunc_37(&kHandle, FUN_1409475d0(&m_spNode));
            FUN_1405a85c0(&kHandle);
            FUN_1409f76f0(&m_spNode, 0);
        }
    }
    if (m_spGuide.get() != 0)
    {
        m_spGuide->vfunc_11();
        m_spGuide = 0;
    }
}

// @0x1410a9e70
void Unk_PCCubeCraft::FUN_1410a9e70()
{
    if (m_spGuide2.get() != 0)
    {
        m_spGuide2->vfunc_11();
        m_spGuide2 = 0;
    }
    FUN_1410af0d0();
}
MS2_REPLACE_METHOD(0x1410A9E70, Unk_PCCubeCraft, FUN_1410a9e70, 103, 0xEEC9DFD1);

// @0x1410a9ee0
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410a9ee0()
{
    PC* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal == 0)
        return;
    if (m_spGuide.get() != 0)
        m_spGuide->vfunc_2(NiPoint3((const NiPoint3&)m_ptCell));
    if (m_spGuide3.get() != 0)
    {
        NiPoint3 kLift = (const NiPoint3&)m_ptCell;
        kLift.z += 150.0f;
        m_spGuide3->vfunc_2(NiPoint3(kLift));
    }
}

// @0x1410aa010
bool Unk_PCCubeCraft::FUN_1410aa010()
{
    return m_spGuide2.get() != 0;
}
MS2_REPLACE_METHOD(0x1410AA010, Unk_PCCubeCraft, FUN_1410aa010, 59, 0x41CA4560);

// @0x1410aa060
void Unk_PCCubeCraft::FUN_1410aa060(unsigned char bUp)
{
    if (bUp)
        m_fLift = m_fLift + 150.0f;
    else
        m_fLift = m_fLift - 150.0f;
}
MS2_REPLACE_METHOD(0x1410AA060, Unk_PCCubeCraft, FUN_1410aa060, 77, 0x1406CA40);

// @0x1410aa0c0
void Unk_PCCubeCraft::FUN_1410aa0c0(CubeItemInfo* pInfo)
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
    FUN_1408b39c0(pInfo, packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1410AA0C0, Unk_PCCubeCraft, FUN_1410aa0c0, 284, 0x96046D34);

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
        MS2Ptr<Cube> spCube(m_svc->FUN_1410b8a60(kCell));
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
void Unk_PCCubeCraft::FUN_1410aa380(bool bVisible)
{
    if (GetMode() == 1)
        return;
    m_bVisible = bVisible;
    if (m_spGuide.get() != 0)
        m_spGuide->vfunc_6(bVisible == 0);
}
MS2_REPLACE_METHOD(0x1410AA380, Unk_PCCubeCraft, FUN_1410aa380, 142, 0xEBE2C83D);

// @0x1410aa420
bool Unk_PCCubeCraft::FUN_1410aa420()
{
    if (m_spGuide == (CCubeGuideWrapper*)0)
        return false;
    return m_spGuide->vfunc_7() == 0;
}
MS2_REPLACE_METHOD(0x1410AA420, Unk_PCCubeCraft, FUN_1410aa420, 109, 0x35F71F79);

// @0x1410aa4a0
void Unk_PCCubeCraft::FUN_1410aa4a0(bool bVisible)
{
    if (m_spGuide2.get() != 0)
        m_spGuide2->vfunc_6(bVisible == 0);
}
MS2_REPLACE_METHOD(0x1410AA4A0, Unk_PCCubeCraft, FUN_1410aa4a0, 109, 0x13D950CB);

// @0x1410aa520
Unk_StreamPoint Unk_PCCubeCraft::GetPtCell()
{
    return m_ptCell;
}
MS2_REPLACE_METHOD(0x1410AA520, Unk_PCCubeCraft, GetPtCell, 41, 0xA7FB2F5C);

// @0x1410aa550
void Unk_PCCubeCraft::FUN_1410aa550(int nMode)
{
    m_nMode = nMode;
    FUN_1410a9cc0();
}
MS2_REPLACE_METHOD(0x1410AA550, Unk_PCCubeCraft, FUN_1410aa550, 43, 0x78B171A4);

// @0x1410aa590
void Unk_PCCubeCraft::FUN_1410aa590()
{
    m_tPulse.FUN_140868750(200);
}
MS2_REPLACE_METHOD(0x1410AA590, Unk_PCCubeCraft, FUN_1410aa590, 36, 0x1378C28C);

// @0x1410aa5c0
void Unk_PCCubeCraft::FUN_1410aa5c0(CubeItemInfo* pInfo)
{
    m_bPending = false;
    if (pInfo == 0)
    {
        FUN_1408b3810(m_spItem.operator->());
        return;
    }
    if (m_spItem->instanceId == pInfo->instanceId && m_spItem->itemId == pInfo->itemId)
        return;
    m_spItem->FUN_1408b3700(pInfo);
    FUN_1410a9cc0();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0 && pPC == m_pOwner)
        FUN_140ef0b20()->FUN_1410b5280(m_spItem);
}
MS2_REPLACE_METHOD(0x1410AA5C0, Unk_PCCubeCraft, FUN_1410aa5c0, 292, 0x60E1D7B8);

// @0x1410ac960
void Unk_PCCubeCraft::FUN_1410ac960()
{
    if (m_spGuide2.get() != 0)
        m_spGuide2->vfunc_1();
}
MS2_REPLACE_METHOD(0x1410AC960, Unk_PCCubeCraft, FUN_1410ac960, 74, 0xC5A8022D);

// @0x1410ad5f0
char Unk_PCCubeCraft::GetPending()
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
void Unk_PCCubeCraft::FUN_1410af0d0()
{
    if (m_spGuide3.get() != 0)
    {
        m_spGuide3->vfunc_11();
        m_spGuide3 = 0;
    }
}
MS2_REPLACE_METHOD(0x1410AF0D0, Unk_PCCubeCraft, FUN_1410af0d0, 99, 0xA27E20ED);

// @0x1410af140
void Unk_PCCubeCraft::FUN_1410af140()
{
    efd::Point3 kAngles = FUN_140a0b080((const efd::Point3&)m_ptOffset, (const efd::Point3&)m_ptCell, DAT_143a08cf8);
    NiMatrix3 kRot;
    FUN_140b86230(kAngles, kRot);
    m_spGuide3->vfunc_4(kRot);
}
MS2_REPLACE_METHOD(0x1410AF140, Unk_PCCubeCraft, FUN_1410af140, 165, 0xDD10B97A);

// @0x1410add30
void Unk_PCCubeCraft::FUN_1410add30()
{
    if (m_pOwner == 0)
        return;
    if (FUN_141656750(m_pOwner) == 0)
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
    if (!m_spEffectA->FUN_140523c40(FUN_1401d3200()->m_effectA.FUN_140536a30(), 1, 0))
    {
        m_spEffectA = 0;
        return;
    }
    m_spEffectA->FUN_140526b30(m_pOwner->FUN_14123c580());
    m_spEffectA->FUN_140526a70(FUN_14028d0e0());
    m_spEffectA->FUN_140526c10(6);
    m_spEffectA->FUN_14052a130(5);
    m_pOwner->vfunc_127(m_spEffectA.get(), 0);
    if (FUN_141659610(m_pOwner) == 0)
        return;
    m_spEffectB.AssignRaw(new CItem);
    if (!m_spEffectB->FUN_140523c40(FUN_1401d3200()->m_effectB.FUN_140ec2b60(), 1, 0))
    {
        m_spEffectB = 0;
        return;
    }
    m_spEffectB->FUN_140526b30(m_pOwner->FUN_14123c580());
    m_spEffectB->FUN_140526a70(FUN_14028d0e0());
    m_spEffectB->FUN_140526c10(4);
    m_spEffectB->FUN_14052a130(5);
    m_pOwner->vfunc_127(m_spEffectB.get(), 0);
    m_spEffectC.AssignRaw(new CItem);
    if (!m_spEffectC->FUN_140523c40(FUN_1401d3200()->m_effectC.FUN_140ec2b60(), 1, 0))
    {
        m_spEffectC = 0;
        return;
    }
    m_spEffectC->FUN_140526b30(m_pOwner->FUN_14123c580());
    m_spEffectC->FUN_140526a70(FUN_14028d0e0());
    m_spEffectC->FUN_140526c10(5);
    m_spEffectC->FUN_14052a130(5);
    m_pOwner->vfunc_127(m_spEffectC.get(), 0);
}
MS2_REPLACE_METHOD(0x1410AD780, Unk_PCCubeCraft, FUN_1410ad780, 1450, 0xC4517146);

// @0x1410aa6f0
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410aa6f0(Unk_StreamPoint kPos, char bNoUpdate)
{
    if (!m_spGuide.operator==(0))
        return;
    char bMoved = kPos.FUN_140552700(m_ptCell);
    if (bMoved != 0)
    {
        if (m_svc->FUN_1410b7e80(kPos))
        {
            MS2Ptr<Cube> spOld(m_svc->FUN_1410b8ab0(kPos));
            float fScale;
            FUN_140961880(spOld->entity, 0x2d7cad2d, &fScale);
            egf::EntityID kId = *FUN_1408b76f0(spOld->entity);
            GetCubeMotionManager()->AddScale(kId, fScale, m_fScale, 200);
        }
    }
    MS2Ptr<Cube> spCell(m_svc->FUN_1410b8ab0(m_ptCell));
    if (spCell.get() == 0)
    {
        char bShift = FUN_140b632f0()->FUN_1410af770();
        if (bShift == 0)
            FUN_1410aa380(true);
    }
    else
    {
        char bGrow = 0;
        char bShift = FUN_140b632f0()->FUN_1410af770();
        if (bShift == 0)
            FUN_1410aa380(true);
        if (bMoved != 0)
        {
            float fCur;
            FUN_140961880(spCell->entity, 0x2d7cad2d, &fCur);
            Unk_CmScale kScale;
            egf::EntityID kId = *FUN_1408b76f0(spCell->entity);
            if (GetCubeMotionManager()->FUN_14115b4c0(kId, kScale))
                m_fScale = kScale.m_fTo;
            else
                m_fScale = fCur;
            if (bGrow == 0)
            {
                if (FUN_140166410()->FUN_14036e510() && m_bVisible)
                {
                    float fTo = m_fScale - 0.05f;
                    egf::EntityID kId2 = *FUN_1408b76f0(spCell->entity);
                    GetCubeMotionManager()->AddScale(kId2, fCur, fTo, 200);
                }
            }
            else
            {
                float fTo = m_fScale + 0.05f;
                egf::EntityID kId3 = *FUN_1408b76f0(spCell->entity);
                GetCubeMotionManager()->AddScale(kId3, fCur, fTo, 200);
            }
        }
    }
    MS2Ptr<CItemData> spData = FUN_14053f870(FUN_1410ad610());
    NiPoint3 kAngles = m_pOwner->vfunc_20();
    float fHeading = FUN_14166da40(m_pOwner);
    kAngles.z = (float)(int)((fHeading + 89.0f) / 90.0f) * 90.0f + m_fYaw;
    NiMatrix3 kRot;
    FUN_140b86230(kAngles, kRot);
    m_spGuide->vfunc_4(kRot);
    if (m_spGuide3.get() != 0)
        FUN_1410af140();
    if (bNoUpdate == 0)
        FUN_1410a9ee0();
}

// @0x1410aad50
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410aad50()
{
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (FUN_141659610(pPC) != 0 && FUN_1416625b0(pPC) == 0)
        return;
    if (GetMode() == 1)
    {
        m_svc->FUN_1410d6590(0x39);
        return;
    }
    if (m_spGuide.operator==(0))
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(FUN_1410ad610());
    if (!spData)
        return;
    if (GetMode() != 2)
    {
        if (FUN_1415302e0(pPC, FUN_1410ad610()))
        {
            m_svc->FUN_1410d6590(0x58);
            return;
        }
    }
    if (FUN_14053d6f0(spData.operator->()))
    {
        CubeItemInfo* pCur = FUN_1410ad670();
        if (pCur != 0 && pCur->FUN_1408b3860() == 0)
        {
            m_svc->FUN_1410d6590(0x62);
            return;
        }
    }
    MS2Ptr<Cube> spCell(m_svc->FUN_1410b8ab0(m_ptCell));
    if (GetMode() == 2 && spData->install.attachable != 0)
    {
        FUN_1410aded0();
    }
    else
    {
        if (!(!spCell))
        {
            int nCubeItem = FUN_1408b4f20(spCell.operator->());
            if (nCubeItem == FUN_1410ad610())
            {
                CubeItemInfo* pCur = FUN_1410ad670();
                if (FUN_1408b38c0(spCell->item.operator->(), pCur) != 0)
                {
                    int nSame = FUN_1408b4f20(spCell.operator->());
                    if (nSame == FUN_1410ad610())
                    {
                        if (FUN_141659690(pPC) == 0)
                        {
                            m_svc->FUN_1410d6590(0x35);
                        }
                        else
                        {
                            FUN_141275260(0x6c9, 1, 1);
                            FUN_141276180(DAT_143acf6b8, CString(""));
                        }
                    }
                    return;
                }
            }
            Unk_StreamPoint kEuler;
            if (FUN_141659610(pPC) == 0)
            {
                NiMatrix3 kRot = m_spGuide->vfunc_5();
                kRot.ToEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
                kEuler.FUN_140ad0c10(-57.29578f);
            }
            else
            {
                Unk_C2Lift* pLift = FUN_1416625b0(pPC);
                kEuler = pLift->vfunc_20();
                kEuler.z = kEuler.z + spData->install.staticAngle;
            }
            if (0.0f <= kEuler.z)
                kEuler.z = kEuler.z + 89.0f;
            else
                kEuler.z = kEuler.z - 89.0f;
            kEuler.z = (float)(int)(kEuler.z / 90.0f) * 90.0f;
            Unk_Int3 kGrid = FUN_1408a1430((const NiPoint3&)m_ptCell);
            CubeItemInfo kInfo(*m_spItem.get());
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.Encode1(0xf);
            packet.Encode4(FUN_1408a03c0(kGrid));
            FUN_1408b39c0(&kInfo, packet);
            packet.WriteFloat(kEuler.z);
            FUN_140710590(packet);
        }
        else
        {
            Unk_StreamPoint kEuler;
            if (FUN_141659610(pPC) == 0)
            {
                NiMatrix3 kRot = m_spGuide->vfunc_5();
                kRot.ToEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
                kEuler.FUN_140ad0c10(-57.29578f);
            }
            else
            {
                Unk_C2Lift* pLift = FUN_1416625b0(pPC);
                kEuler = pLift->vfunc_20();
                kEuler.z = kEuler.z + spData->install.staticAngle;
            }
            if (0.0f <= kEuler.z)
                kEuler.z = kEuler.z + 89.0f;
            else
                kEuler.z = kEuler.z - 89.0f;
            kEuler.z = (float)(int)(kEuler.z / 90.0f) * 90.0f;
            FUN_140291b70(&kEuler.z);
            CubeItemInfo kInfo(*m_spItem.get());
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.Encode1(10);
            packet.Encode4(FUN_1408a13d0((const efd::Point3&)m_ptCell));
            FUN_1408b39c0(&kInfo, packet);
            packet.WriteFloat(kEuler.z);
            FUN_140710590(packet);
        }
    }
}

// @0x1410ab5a0
void Unk_PCCubeCraft::FUN_1410ab5a0()
{
    FUN_1410ab5c0(1);
}
MS2_REPLACE_METHOD(0x1410AB5A0, Unk_PCCubeCraft, FUN_1410ab5a0, 26, 0x3243A98E);

// @0x1410ab5c0
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410ab5c0(unsigned char bNotice)
{
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    Unk_StreamPoint kCell = m_ptCell;
    if (m_spGuide.operator==(0))
    {
        Unk_StreamPoint kFront;
        Unk_StreamPoint kOut;
        if (FUN_141659610(pPC) == 0)
        {
            m_svc->FUN_1410b7ad0(pPC, m_fLift, &kFront, 1);
        }
        else
        {
            Unk_C2Lift* pLift = FUN_1416625b0(pPC);
            if (pLift != 0)
            {
                Unk_StreamPoint kRear = pLift->vfunc_20();
                Unk_StreamPoint kHead = pLift->vfunc_18();
                m_svc->FUN_1410b7ba0(kHead, kRear, -200.0f, &kFront, 0);
            }
        }
        m_svc->FUN_1410b7a20(kFront, &kOut);
    }
    if (GetMode() == 1 || GetMode() == 0 || GetMode() == 2)
    {
        if (!m_svc->FUN_1410b7e80(kCell))
        {
            m_svc->FUN_1410d6590(0x1a);
        }
        else
        {
            MS2Ptr<Cube> spCube(m_svc->FUN_1410b8ab0(kCell));
            Unk_C2Reason kReason;
            kReason.FUN_14052be80(0);
            if (m_svc->FUN_1410c6980(spCube.get(), spCube->field44, kReason, FUN_141656ad0(pPC), 3) == 0)
            {
                m_svc->FUN_1410d6590(0x1b);
            }
            else
            {
                Unk_CmRotate kRot;
                egf::EntityID kId = *FUN_1408b76f0(spCube->entity);
                if (!GetCubeMotionManager()->FUN_14115b500(kId, kRot))
                {
                    Unk_Int3 kGrid = FUN_1408a1430((const NiPoint3&)kCell);
                    COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
                    packet.Encode1(0xe);
                    packet.Encode4(FUN_1408a03c0(kGrid));
                    packet.WriteBool(bNotice != 0);
                    FUN_140710590(packet);
                }
            }
        }
    }
}

// @0x1410abb40
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410abb40()
{
    if (GetMode() == 2)
        return;
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    Unk_StreamPoint kCell = m_ptCell;
    if (m_spGuide.operator==(0))
    {
        Unk_StreamPoint kFront;
        Unk_StreamPoint kSpare;
        if (FUN_141659610(pPC) == 0)
        {
            m_svc->FUN_1410b7ad0(pPC, m_fLift, &kFront, 1);
        }
        else
        {
            Unk_C2Lift* pLift = FUN_1416625b0(pPC);
            if (pLift != 0)
            {
                Unk_StreamPoint kRear = pLift->vfunc_20();
                Unk_StreamPoint kHead = pLift->vfunc_18();
                m_svc->FUN_1410b7ba0(kHead, kRear, -200.0f, &kFront, 0);
            }
        }
        m_svc->FUN_1410b7a20(kFront, &kCell);
    }
    if (!m_svc->FUN_1410b7e80(kCell))
    {
        m_svc->FUN_1410d6590(0x14);
    }
    else
    {
        MS2Ptr<Cube> spCube(m_svc->FUN_1410b8ab0(m_ptCell));
        Unk_Int3 kGrid = FUN_1408a1430((const NiPoint3&)kCell);
        Unk_C2Reason kReason;
        kReason.FUN_14052be80(0);
        if (m_svc->FUN_1410c6980(spCube.get(), spCube->field44, kReason, FUN_141656ad0(pPC), 4) == 0)
        {
            m_svc->FUN_1410d6590(0x28);
        }
        else
        {
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.Encode1(0xc);
            packet.Encode4(FUN_1408a03c0(kGrid));
            FUN_140710590(packet);
            if (spCube->field44 == 2)
            {
                int nItem = FUN_1408b4f20(spCube.operator->());
                FUN_14138bf00(FUN_1409331e0(), 7, nItem, 0);
            }
        }
    }
}

// @0x1410ac1c0
void Unk_PCCubeCraft::FUN_1410ac1c0()
{
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
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
        FUN_1410aa060(1);
        if (FUN_1410af7a0(pPC) != 0)
        {
            Unk_C2Lift* pLift = FUN_1416625b0(pPC);
            Unk_Int3 kDir(0, 0, 1);
            efd::SmartPointer<Unk_Service6100017> spSvc = FUN_1401cd040(&DAT_143b059e8);
            if (spSvc->FUN_1410cdd80(pLift->vfunc_18(), pLift->vfunc_20(), 200.0f, kDir) != 0)
                pLift->FUN_1410a77e0(6.0f);
        }
    }
}
MS2_REPLACE_METHOD(0x1410AC1C0, Unk_PCCubeCraft, FUN_1410ac1c0, 438, 0x354524C7);

// @0x1410ac380
void Unk_PCCubeCraft::FUN_1410ac380()
{
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
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
        FUN_1410aa060(0);
        if (FUN_1410af7a0(pPC) != 0)
        {
            Unk_C2Lift* pLift = FUN_1416625b0(pPC);
            Unk_Int3 kDir(0, 0, -2);
            efd::SmartPointer<Unk_Service6100017> spSvc = FUN_1401cd040(&DAT_143b059e8);
            if (spSvc->FUN_1410cdd80(pLift->vfunc_18(), pLift->vfunc_20(), 200.0f, kDir) != 0)
                pLift->FUN_1410a77e0(-6.0f);
        }
    }
}
MS2_REPLACE_METHOD(0x1410AC380, Unk_PCCubeCraft, FUN_1410ac380, 438, 0x73645A07);

// @0x1410af7a0
int FUN_1410af7a0(PC* pPC)
{
    return FUN_1416625b0(pPC) != 0;
}
MS2_REPLACE(0x1410AF7A0, FUN_1410af7a0, 51, 0xD550EB77);

// @0x1410ac540
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410ac540()
{
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0 || FUN_1416595d0(pPC) == 0)
        return;
    Unk_StreamPoint kCell = m_ptCell;
    if (m_spGuide.operator==(0))
    {
        Unk_StreamPoint kFront;
        Unk_StreamPoint kSpare;
        if (FUN_141659610(pPC) == 0)
        {
            m_svc->FUN_1410b7ad0(pPC, m_fLift, &kFront, 1);
        }
        else
        {
            Unk_C2Lift* pLift = FUN_1416625b0(pPC);
            if (pLift != 0)
            {
                Unk_StreamPoint kRear = pLift->vfunc_20();
                Unk_StreamPoint kHead = pLift->vfunc_18();
                m_svc->FUN_1410b7ba0(kHead, kRear, -200.0f, &kFront, 0);
            }
        }
        m_svc->FUN_1410b7a20(kFront, &kSpare);
    }
    if (GetMode() == 3)
        return;
    if (!m_svc->FUN_1410b7e80(kCell))
        return;
    MS2Ptr<Cube> spCube(m_svc->FUN_1410b8ab0(kCell));
    if (spCube.operator==(0))
        return;
    if (FUN_140707bc0(spCube->fieldB4) == 0)
        return;
    Unk_C2RowPtr kRow;
    FUN_140704ec0(&kRow, spCube->fieldB4);
    Unk_C2Row* pRow = kRow.FUN_140708ea0();
    kRow.FUN_140708b20();
    if (pRow == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
    packet.Encode1(0xd);
    packet.Encode4(FUN_1408a13d0((const efd::Point3&)kCell));
    FUN_140710590(packet);
}

// @0x1410aded0
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410aded0()
{
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    MS2Ptr<Cube> spCube(m_svc->FUN_1410b8ab0(m_ptCell));
    Unk_Int3 kGrid = FUN_1408a1430((const NiPoint3&)m_ptCell);
    Unk_StreamPoint kPos;
    Unk_C2Lift* pLift = FUN_1416625b0(pPC);
    if (pLift == 0)
    {
        NiPoint3 kRear = pPC->vfunc_20();
        kPos = (const Unk_StreamPoint&)kRear;
    }
    else
        kPos = pLift->vfunc_20();
    int nCell = m_svc->FUN_1410ba5f0(kGrid, kPos);
    float fHeight = m_svc->FUN_1410ba440(nCell);
    CubeItemInfo kInfo(*m_spItem.operator->());
    if (!(!spCube))
    {
        if (FUN_1408b4f20(spCube.operator->()) == FUN_1410ad610()
            && FUN_1408b38c0(spCube->item.operator->(), FUN_1410ad670()) != 0)
        {
            if (FUN_1408b4f20(spCube.operator->()) == FUN_1410ad610())
            {
                if (FUN_141659690(pPC) == 0)
                {
                    m_svc->FUN_1410d6590(0x35);
                }
                else
                {
                    FUN_141275260(0x6c9, 1, 1);
                    FUN_141276180(DAT_143acf6b8, CString(""));
                }
            }
            return;
        }
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.Encode1(0x10);
        packet.Encode4(FUN_1408a03c0(kGrid));
        FUN_1408b39c0(&kInfo, packet);
        packet.WriteFloat(fHeight);
        packet.Encode1((unsigned char)nCell);
        FUN_140710590(packet);
    }
    else
    {
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.Encode1(0xb);
        packet.Encode4(FUN_1408a03c0(kGrid));
        FUN_1408b39c0(&kInfo, packet);
        packet.WriteFloat(fHeight);
        packet.Encode1((unsigned char)nCell);
        FUN_140710590(packet);
    }
}

// @0x1410ae380
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410ae380(Unk_StreamPoint kPos)
{
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (m_nMode == 2)
    {
        m_nCheck = 1;
        return;
    }
    if (m_nMode != 0 && m_nMode != 2)
    {
        m_nCheck = 0;
        return;
    }
    Unk_Int3 kGrid = FUN_1408a1430((const NiPoint3&)kPos);
    Unk_CubePoint kPoint;
    kPoint.x = kGrid.x;
    kPoint.y = kGrid.y;
    kPoint.z = kGrid.z;
    MS2Ptr<CItemData> spData = FUN_14053f870(FUN_1410ad610());
    if (spData.operator==(0))
        return;
    MS2Ptr<Cube> spCube(m_svc->FUN_1410b8ab0(m_ptCell));
    unsigned nErr;
    if (GetMode() == 2 && spData->install.attachable != 0)
    {
        Unk_StreamPoint kFoot;
        Unk_C2Lift* pLift = FUN_1416625b0(pPC);
        if (pLift == 0)
        {
            NiPoint3 kRear = pPC->vfunc_20();
            kFoot = (const Unk_StreamPoint&)kRear;
        }
        else
        {
            kFoot = pLift->vfunc_20();
        }
        int nCell = m_svc->FUN_1410ba5f0(kGrid, kFoot);
        if (!(!spCube))
        {
            if (FUN_1408b4f20(spCube.operator->()) == FUN_1410ad610()
                && FUN_1408b38c0(spCube->item.operator->(), FUN_1410ad670()) != 0)
            {
                if (FUN_1408b4f20(spCube.operator->()) == FUN_1410ad610())
                    m_nCheck = 0;
                return;
            }
            CUGCBuildValidatorCli kValidator(kPoint, FUN_1410ad670(), nCell);
            m_nCheck = kValidator.vfunc_39(&nErr);
        }
        else
        {
            CUGCBuildValidatorCli kValidator(kPoint, FUN_1410ad670(), nCell);
            m_nCheck = kValidator.vfunc_37(&nErr);
        }
    }
    else
    {
        if (!(!spCube))
        {
            if (FUN_1408b4f20(spCube.operator->()) == FUN_1410ad610()
                && FUN_1408b38c0(spCube->item.operator->(), FUN_1410ad670()) != 0)
            {
                if (FUN_1408b4f20(spCube.operator->()) == FUN_1410ad610())
                    m_nCheck = 0;
                return;
            }
            CUGCBuildValidatorCli kValidator(kPoint, FUN_1410ad670());
            m_nCheck = kValidator.vfunc_38(&nErr);
        }
        else
        {
            CUGCBuildValidatorCli kValidator(kPoint, FUN_1410ad670());
            m_nCheck = kValidator.vfunc_36(&nErr);
        }
    }
}

// @0x1410ae960
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410ae960(unsigned* pLeft, unsigned* pRight)
{
    *pRight = 0;
    *pLeft = 0;
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    Unk_StreamPoint kFloor;
    m_svc->FUN_1410b7ad0(pPC, 0, &kFloor, 1);
    Unk_Int3 kFloorGrid = FUN_1408a1430((const NiPoint3&)kFloor);
    Unk_StreamPoint kTop;
    m_svc->FUN_1410b7ad0(pPC, m_fLift, &kTop, 1);
    Unk_Int3 kTopGrid = FUN_1408a1430((const NiPoint3&)kTop);
    if (GetMode() == 2)
    {
        *pLeft = kTopGrid.z - kFloorGrid.z < *FUN_1401d3200()->m_liftUp.FUN_1402056b0();
        *pRight = kFloorGrid.z - kTopGrid.z < *FUN_1401d3200()->m_liftDown.FUN_1402056b0();
        if (DAT_143ae0fb4 != 0)
        {
            *pRight = 1;
            *pLeft = 1;
        }
    }
    else
    {
        if (FUN_1410af7a0(pPC) == 0)
        {
            Unk_Int3 kUp(0, 0, 1);
            *pLeft = m_svc->FUN_1410cdf60(kTopGrid, kUp);
            Unk_Int3 kDown(0, 0, -1);
            *pRight = m_svc->FUN_1410cdf60(kTopGrid, kDown);
        }
        else
        {
            Unk_C2Lift* pLift = FUN_1416625b0(pPC);
            Unk_Int3 kUp(0, 0, 1);
            Unk_StreamPoint kRear = pLift->vfunc_20();
            Unk_StreamPoint kHead = pLift->vfunc_18();
            *pLeft = m_svc->FUN_1410cdd80(kHead, kRear, 200.0f, kUp);
            Unk_Int3 kDown(0, 0, -2);
            kRear = pLift->vfunc_20();
            kHead = pLift->vfunc_18();
            *pRight = m_svc->FUN_1410cdd80(kHead, kRear, 200.0f, kDown);
        }
        if (DAT_143ae0fb4 != 0)
        {
            *pRight = 1;
            *pLeft = 1;
        }
    }
}

// @0x1410aeec0
void Unk_PCCubeCraft::FUN_1410aeec0(const Unk_StreamPoint& kPos)
{
    Cube* pCube = 0;
    Unk_Int3 kCell = FUN_1408a1430((const NiPoint3&)kPos);
    kCell.z = kCell.z - 1;
    pCube = m_svc->FUN_1410b8a60(kCell);
    if (pCube == 0)
    {
        FUN_1408a15b0(kCell, const_cast<Unk_StreamPoint&>(kPos));
    }
    else
    {
        kCell.z = kCell.z + 1;
        pCube = m_svc->FUN_1410b8a60(kCell);
        if (pCube == 0)
        {
            FUN_1408a15b0(kCell, const_cast<Unk_StreamPoint&>(kPos));
        }
        else
        {
            kCell.z = kCell.z + 1;
            pCube = m_svc->FUN_1410b8a60(kCell);
            if (pCube == 0)
                FUN_1408a15b0(kCell, const_cast<Unk_StreamPoint&>(kPos));
        }
    }
}
MS2_REPLACE_METHOD(0x1410AEEC0, Unk_PCCubeCraft, FUN_1410aeec0, 494, 0x9CC59312);

// @0x1410af1f0
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410af1f0()
{
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0 || pPC != m_pOwner)
        return;
    ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
    FUN_1416cb8b0(FUN_140764020(), quests, 1, 0xb, -1);
    int nLiftId = 0;
    for (size_t i = 0; i < quests.GetCount(); ++i)
    {
        Unk_PayloadPtr<CQuest> spQuest(quests[i]);
        if (!(!spQuest))
        {
            MS2Ptr<CQuestData> spData = spQuest->GetData();
            for (size_t j = 0; j < spData->m_conditions.GetCount(); ++j)
            {
                MS2Ptr<CConditionCommonData> spCond = spData->m_conditions[j];
                if (spCond->m_nType == 0x9c)
                {
                    unsigned __int64 nItem = (unsigned)FUN_1410ad610();
                    if (spCond->m_code.Matches(nItem) != 0)
                    {
                        if (spCond->m_target.GetIdCount() == 1)
                            nLiftId = (int)spCond->m_target.GetFirstValue();
                    }
                }
            }
            if (nLiftId != 0)
                break;
        }
    }
    if (nLiftId == 0)
        return;
    std::vector<MS2Ptr<Unk_C2LiftObj>> aLifts;
    FUN_1403ed2d0()->FUN_141bc5980(&aLifts);
    for (size_t k = 0; k < aLifts.size(); ++k)
    {
        MS2Ptr<Unk_C2LiftObj> spLift = aLifts[k];
        if (spLift->FUN_1410af780() == nLiftId)
        {
            m_svc->FUN_1410b7a20(spLift->FUN_1409673f0(), &m_ptOffset);
            break;
        }
    }
}

// @0x1410ac9b0
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order and temporaries differ from the exe
void Unk_PCCubeCraft::FUN_1410ac9b0()
{
    if (m_spGuide.operator==(0))
        return;
    m_spGuide->vfunc_1();
    if (m_spGuide3.get() != 0)
        m_spGuide3->vfunc_1();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != m_pOwner)
        return;
    if (FUN_14166c930(pPC) == 0x10)
    {
        FUN_1410aa380(false);
        FUN_1410aa4a0(false);
        m_nHud = 0;
        return;
    }
    if (m_nHud == 0)
    {
        FUN_1410aa380(true);
        FUN_1410aa4a0(true);
        m_nHud = 1;
    }
    Unk_StreamPoint kFront;
    Unk_StreamPoint kDown;
    if (FUN_141659610(pPC) == 0)
    {
        m_svc->FUN_1410b7ad0(pPC, m_fLift, &kFront, 1);
        if (FUN_141659690(pPC) != 0)
            FUN_1410aeec0(kFront);
    }
    else
    {
        Unk_C2Lift* pLift = FUN_1416625b0(pPC);
        if (pLift != 0)
        {
            Unk_StreamPoint kRear = pLift->vfunc_20();
            Unk_StreamPoint kHead = pLift->vfunc_18();
            m_svc->FUN_1410b7ba0(kHead, kRear, -200.0f, &kFront, 0);
        }
    }
    m_svc->FUN_1410b7a20(kFront, &kDown);
    int nOldCheck = m_nCheck;
    FUN_1410ae380(m_ptCell);
    if (nOldCheck != m_nCheck)
        FUN_1410a92c0();
    if (kDown.FUN_140552700(m_ptCell))
    {
        Unk_StreamPoint kOld = m_ptCell;
        NiPoint3 kGuidePos = m_spGuide->vfunc_3();
        m_ptLast = (const Unk_StreamPoint&)kGuidePos;
        m_ptCell = kDown;
        m_tSlide.FUN_140868750(200);
        char bSameColumn = 0;
        if (kOld.x == m_ptCell.x && kOld.y == m_ptCell.y && kOld.z != m_ptCell.z)
            bSameColumn = 1;
        FUN_1410aa6f0(kOld, bSameColumn);
        if (FUN_141659690(pPC) == 0 && m_bFirstMove != 0)
            FUN_141276180(DAT_143acf6c0, CString(""));
        if (m_bFirstMove == 0)
            m_bFirstMove = 1;
    }
    Unk_C2Ease kEase;
    if ((GetMode() == 0 || GetMode() == 2)
        && (m_tRotate.FUN_140868ba0() != 0 || m_tRotate.FUN_140868c00() != 0))
    {
        float fRatio = m_tRotate.FUN_140868940();
        float fEase = kEase.FUN_140cd8c20(fRatio);
        float fYaw = m_fRotFrom + (m_fRotTo - m_fRotFrom) * fEase;
        Unk_StreamPoint kAngles;
        NiMatrix3 kCur = m_spGuide->vfunc_5();
        kCur.ToEulerAnglesXYZ(kAngles.x, kAngles.y, kAngles.z);
        kAngles.x = kAngles.x * -57.29578f;
        kAngles.y = kAngles.y * -57.29578f;
        kAngles.z = fYaw;
        NiMatrix3 kRot;
        FUN_140b86230((const efd::Point3&)kAngles, kRot);
        m_spGuide->vfunc_4(kRot);
        if (m_tRotate.FUN_140868c00() != 0)
            m_tRotate.FUN_1408687f0();
    }
    if (m_tSlide.FUN_140868ba0() != 0 || m_tSlide.FUN_140868c00() != 0)
    {
        float fRatio = m_tSlide.FUN_140868940();
        float fEase = kEase.FUN_140cd8c20(fRatio);
        Unk_StreamPoint kDelta = m_ptCell.FUN_140965c40(m_ptLast);
        float fLen = kDelta.FUN_140967ac0();
        kDelta.FUN_140968990();
        Unk_StreamPoint kStep = kDelta.FUN_14097fc90(fEase);
        kStep = kStep.FUN_14097fc90(fLen);
        kDown = m_ptLast.FUN_14097fd50(kStep);
        m_spGuide->vfunc_2((const NiPoint3&)kDown);
        if (m_spGuide3.get() != 0)
        {
            Unk_StreamPoint kUp = kDown;
            kUp.z = kUp.z + 150.0f;
            m_spGuide3->vfunc_2((const NiPoint3&)kUp);
        }
        if (m_tSlide.FUN_140868c00() != 0)
            m_tSlide.FUN_1408687f0();
    }
    if (m_tPulse.FUN_140868ba0() != 0 || m_tPulse.FUN_140868c00() != 0)
    {
        float fRatio = m_tPulse.FUN_140868940();
        if (fRatio > 0.5f)
        {
            float fOut = kEase.FUN_1410af700((m_tPulse.FUN_140868940() - 0.5f) * 2.0f);
            m_spGuide->vfunc_9(fOut * -0.20000005f + 1.2f);
            if (m_tPulse.FUN_140868c00() != 0)
                m_tPulse.FUN_1408687f0();
        }
        else
        {
            float fIn = kEase.FUN_140cd8c20(m_tPulse.FUN_140868940() * 2.0f);
            m_spGuide->vfunc_9(fIn * 0.20000005f + 1.0f);
        }
    }
    if (m_spGod.get() != 0)
    {
        m_spGod->FUN_141374d40(pPC->vfunc_18());
        m_spGod->FUN_141374dd0(FUN_14166d240(pPC));
    }
}

// @0x1410af700
float Unk_C2Ease::FUN_1410af700(float t)
{
    if (!(0.0f <= t))
        return 0.0f;
    if (t > 1.0f)
        return 1.0f;
    return 1.0f - FUN_14096b1c0(1.0f - t * t);
}
MS2_REPLACE_METHOD(0x1410AF700, Unk_C2Ease, FUN_1410af700, 112, 0x6C45E1EF);

// @0x1410af790
CCubeMotionManager* GetCubeMotionManager()
{
    return DAT_143acf6c8;
}
MS2_REPLACE(0x1410AF790, GetCubeMotionManager, 8, 0xEA0FC2F5);

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy).
// @0x1410af7e0
// MS2-FUNCTIONAL: unreferenced CRT memcpy_s copy: frame saves rsi/rdi, source spelling differs
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
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cabf10-0x142cabfe0 .text$yd
