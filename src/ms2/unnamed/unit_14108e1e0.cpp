// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The npc actor: CNpcVibrate (the hit shake, 0x14108e1e0..)
// and CNpc (RTTI CNpc -> PCBase, class id 0x06200028; vftables 0x142ea8b58 / 0x142ea8f68), followed by the COMDAT
// tail of the templates it instantiates. Layout: placeholder/cnpc.h (members 0xd40..0xf40 from the ctor 0x14108e420 /
// dtor 0x14108ef30). CNpc::ms_ClassInfo is registered in unit_1400e53e0. Names are the FUN_<va> / vfunc_<slot>
// spellings of the shared header unless the exe names them.
// MS2-UNIT: unit_14108e1e0
// MS2-RANGE: 0x14108e1e0-0x14109b6b0 .text$mn
// MS2-RANGE: 0x1400e56b0-0x1400e59d0 .text$di
// MS2-RANGE: 0x142cabd60-0x142cabe80 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSortTypeNames1@@YAXXZ 0x1400e56b0 ; probe
// MS2-PIN: ??__Es_strSkill1@@YAXXZ 0x1400e5770 ; probe
// MS2-PIN: ??__Es_strSkill2@@YAXXZ 0x1400e57a0 ; probe
// MS2-PIN: ??__Es_condition1@@YAXXZ 0x1400e57f0 ; prop
// MS2-PIN: ??__Es_strSortTypeNames2@@YAXXZ 0x1400e5840 ; probe
// MS2-PIN: ??__Es_strStun1@@YAXXZ 0x1400e5900 ; probe
// MS2-PIN: ??__Es_strStun2@@YAXXZ 0x1400e5930 ; probe
// MS2-PIN: ??__Es_condition2@@YAXXZ 0x1400e5980 ; prop
// MS2-PIN: ??$?4VNpcDataCli@@@?$MS2Ptr@VCNpcData@@@@QEAAAEAV0@AEBV?$MS2Ptr@VNpcDataCli@@@@@Z 0x141099b40 ; unique
// MS2-PIN: ??0?$MS2Ptr@VUnk_PCBaseComp_a78@@@@QEAA@AEBV0@@Z 0x141099e00 ; prop
// MS2-PIN: ??0?$MS2Ptr@VStateSpawnData@@@@QEAA@PEAVStateSpawnData@@@Z 0x141099e70 ; prop
// MS2-PIN: ??4?$MS2Ptr@VUnk_PCBaseComp_a58@@@@QEAAAEAV0@AEBV0@@Z 0x14109a150 ; prop
// MS2-PIN: ?IsNull@?$MS2Ptr@VNpcDataCli@@@@QEBA_NXZ 0x14109a230 ; unique
// MS2-PIN: ??8?$MS2Ptr@VUnk_PCBaseComp_a58@@@@QEBA_NPEAVUnk_PCBaseComp_a58@@@Z 0x14109a2e0 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VUnk_PCBaseComp_a58@@@@QEBAPEAVUnk_PCBaseComp_a58@@XZ 0x14109a390 ; prop
// MS2-PIN: ??C?$MS2Ptr@VUnk_PCBaseComp_a58@@@@QEBAPEAVUnk_PCBaseComp_a58@@XZ 0x14109a3d0 ; prop
// MS2-PIN: ?GetBaseMap@NiTexturingProperty@@QEAAPEAVMap@1@XZ 0x14109a6b0 ; unique
// MS2-PIN: ?GetClassDesc@CNpc@@UEBAPEBVClassInfo@efd@@XZ 0x14109a6e0 ; unique
// MS2-PIN: ?GetInstance@?$TSingleton@VCDPSMeterSystem@@@@SAPEAVCDPSMeterSystem@@XZ 0x14109a6f0 ; prop
// MS2-PIN: ?FUN_14109ac50@COptimizer@@QEAAXH@Z 0x14109ac50 ; unique
// MS2-PIN: ?TypeCast@CNpc@@UEBA_NIPEAPEAX@Z 0x14109ad20 ; unique
// MS2-PIN: ?TypeCast@CNpc@@UEBA_NIPEAPEBX@Z 0x14109ad70 ; unique
// MS2-PIN: ?UnitCross@Point3@efd@@QEBA?AV12@AEBV12@@Z 0x14109adc0 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_PCBaseComp_a98@@@@AEBAXXZ 0x14109af90 ; prop
// MS2-PIN: ?AddRef@?$MS2Ptr@VStateSpawnData@@@@AEBAXXZ 0x14109b080 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCDotDamageRecord@@@@AEBAXPEAX@Z 0x14109b1a0 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUnk_PCBaseComp_a98@@@@AEBAXPEAX@Z 0x14109b230 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VStateSpawnData@@@@AEBAXPEAX@Z 0x14109b320 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCDotDamageRecord@@@@AEAAXPEAX@Z 0x14109b520 ; unique
// MS2-PIN: ??__Fs_strSortTypeNames1@@YAXXZ 0x142cabd60 ; probe
// MS2-PIN: ??__Fs_strSkill1@@YAXXZ 0x142cabd90 ; probe
// MS2-PIN: ??__Fs_strSkill2@@YAXXZ 0x142cabdb0 ; probe
// MS2-PIN: ??__Fs_strSortTypeNames2@@YAXXZ 0x142cabdf0 ; probe
// MS2-PIN: ??__Fs_strStun1@@YAXXZ 0x142cabe20 ; probe
// MS2-PIN: ??__Fs_strStun2@@YAXXZ 0x142cabe40 ; probe
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CNpc@@6BIBase@efd@@@ 0x142ea8b58
// MS2-PIN: ??_7CNpc@@6BCallbackObject@NiActorManager@@@ 0x142ea8f68
// MS2-PIN: ??_7CNpcVibrate@@6B@ 0x142ea8b48
// The byte-identical MS2Ptr instantiations, told apart by the exe call graph (FUN_1410918e0's hit data, the splash
// record of vfunc_35) and the header statics' initializer order.
// MS2-PIN: ??0?$MS2Ptr@VStateHitData@@@@QEAA@PEAVStateHitData@@@Z 0x141099e40
// MS2-PIN: ?AddRef@?$MS2Ptr@VStateHitData@@@@AEBAXXZ 0x14109b050
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VStateHitData@@@@AEBAXPEAX@Z 0x14109b2f0
// MS2-PIN: ?Reference@?$MS2Ptr@VStateHitData@@@@CAXPEAVStateHitData@@@Z 0x14109b130
// MS2-PIN: ??1?$MS2Ptr@VStateHitData@@@@QEAA@XZ 0x141099f60
// MS2-PIN: ?Release@?$MS2Ptr@VStateHitData@@@@AEAAXXZ 0x14109b450
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VStateHitData@@@@AEAAXPEAX@Z 0x14109b610
// MS2-PIN: ??C?$MS2Ptr@VStateHitData@@@@QEBAPEAVStateHitData@@XZ 0x14109a3e0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCSplashDamageRecord@@@@AEBAXPEAX@Z 0x14109b200
// MS2-PIN: ?Reference@?$MS2Ptr@VCSplashDamageRecord@@@@CAXPEAVCSplashDamageRecord@@@Z 0x14109b0f0
// MS2-PIN: ??0?$MS2Ptr@VUnk_PCBaseComp_a58@@@@QEAA@AEBV0@@Z 0x141099dc0
// MS2-PIN: ??4?$MS2Ptr@VUnk_PCBaseComp_a78@@@@QEAAAEAV0@AEBV0@@Z 0x14109a190
// MS2-PIN: ??B?$SmartPointer@VCObjectShadow@@@efd@@QEBAPEAVCObjectShadow@@XZ 0x14109a360
// MS2-PIN: ?get@?$Unk_UmValuePtr@UUnk_UmDescRow@@@@QEBAPEAUUnk_UmDescRow@@XZ 0x14109a370
// MS2-PIN: ?get@?$MS2Ptr@VUnk_PCBaseComp_a88@@@@QEBAPEAVUnk_PCBaseComp_a88@@XZ 0x14109a380
// MS2-PIN: ?get@?$MS2Ptr@VStateHitData@@@@QEBAPEAVStateHitData@@XZ 0x14109a3a0
// MS2-PIN: ?get@?$MS2Ptr@VStateSpawnData@@@@QEBAPEAVStateSpawnData@@XZ 0x14109a3b0
// MS2-PIN: ??__Es_pointer1@@YAXXZ 0x1400e57d0
// MS2-PIN: ??__Es_pointer2@@YAXXZ 0x1400e5960
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\npc.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/stateidle.h"
#include "ms2/client/ms2/statewalk.h"
#include "ms2/client/ms2/statedead.h"
#include "ms2/client/ms2/stateskill.h"
#include "ms2/client/ms2/statehit.h"
#include "ms2/client/ms2/statestun.h"
#include "ms2/client/ms2/statetalk.h"
#include "ms2/client/ms2/statespawn.h"
#include "ms2/client/ms2/statesummon.h"
#include "ms2/client/ms2/randomtargeteffect.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/commonfiles/maid.h"
#include "ms2/placeholder/cusermaidmanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cpet.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/client/ms2/randomeffectparam.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/itemdatatable.h"
#include <NiTexturingProperty.h>
#include <NiMesh.h>
#include "ms2/commonfiles/skillattackdata.h"
#include "ms2/client/ms2/skillrecord.h"
#include "ms2/client/ms2/dpsmetersystem.h"
#include "ms2/client/ms2/additionalcli.h"
#include "ms2/client/ms2/additionalclilist.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class CEffectService;
CEffectService* FUN_1403ed280();                                    // the effect service
void FUN_1411a6060(CEffectService* pService, unsigned int nHandle); // stop an effect
int FUN_140768010(int nMax, int nMin);                              // random integer
float FUN_140768090();                                              // random float in [0, 1)

// ---- unit-local placeholders ----

// The lazily created per-actor components (pcbase.cpp names; the exe types are UIHpBar / UINameTag / UIEmoticon /
// UIBuffBalloon / UIChatBalloon ::Entity).
class Unk_PCBaseComp_a58 : public CPtred
{
public:
    void FUN_141992140(int bShow);
    void FUN_141992180(__int64 nCur, __int64 nMax);
};
class Unk_PCBaseComp_a78 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // refresh
    void FUN_141a5e4c0(int nFontSize);
    void FUN_141a5e500(int n);
    void FUN_141a5e540(CString strNode);                            // the node the tag follows
};
class Unk_PCBaseComp_a88 : public CPtred {};
class Unk_PCBaseComp_a98 : public CPtred {};
class Unk_PCBaseComp_aa8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();                                         // hide
    bool FUN_1418fb6b0();                                           // UIChatBalloon::Entity: showing
    int FUN_140f48d40();                                            // UIHudEntity::Entity: visible
};
MS2Ptr<Unk_PCBaseComp_a58> FUN_141992920(int nObjectId);           // new hp bar
MS2Ptr<Unk_PCBaseComp_a78> FUN_141a60da0(int nObjectId);           // new name tag
MS2Ptr<Unk_PCBaseComp_a88> FUN_14192fd40(int nObjectId);           // new emoticon
MS2Ptr<Unk_PCBaseComp_a98> FUN_14128ef70(int nObjectId);           // new buff balloon
MS2Ptr<Unk_PCBaseComp_aa8> FUN_1418fbdb0(int nObjectId);           // new chat balloon

// The actor's ground shadow (GameObject +0x58; unit_14160fb10).
class CObjectShadow : public NiRefObject
{
public:
    CObjectShadow(GameObject* pOwner, int nLodHi, int nLodLo, float fSize, float fAlpha);   // 0x14160fc90
    // @0x14109a720
    bool FUN_14109a720() { return m_bVisible; }
private:
    char m_pad_10[0x35 - sizeof(NiRefObject)];
    bool m_bVisible; char m_pad_36[0x58 - 0x36];                  // +0x35 (the exe allocates 0x58 at 0x141096664)
};

// The buffs (AdditionalCliList, pcbase.h's Unk_PCBaseBuffs view).
class Unk_PCBaseBuffs
{
public:
    float FUN_140970720();                                          // scale
};

class Unk_CapWorld { public: void FUN_141bc7d40(const egf::EntityID& kId); void FUN_141bc7fe0(const egf::EntityID& kId); void FUN_141bc8e00(); PCBase* FUN_141bd0cc0(); void FUN_141bc7ec0(const egf::EntityID& kId); void FUN_141bc7f10(const egf::EntityID& kId); };    // WorldService
Unk_CapWorld* FUN_1403ed2d0();
class COptimizer { public: int FUN_1409f7ea0(); void FUN_14161d010(const egf::EntityID& kId); void FUN_14161d070(const egf::EntityID& kId); void FUN_14109ac50(int n) { m_n68 = n; } int FUN_14109a9d0(); private: char m_pad[0x68]; int m_n68; };
COptimizer* FUN_1409f7c90();
class Unk_CsoSpawnMgr { public: Unk_PCBaseFxLib* FUN_1411bf1e0(); };
Unk_CsoSpawnMgr* FUN_140a50010();
class CLua { public: float CalcNpcAsiR(long long a, float b); };
CLua* FUN_1401c0db0();
bool FUN_14028d470(float a, float b);                               // a != b (with epsilon)
unsigned char FUN_140a7c8d0(NpcDataCli* pData);                     // NpcDataCli::GetNametag
int FUN_140a7c970(NpcDataCli* pData);                               // NpcDataCli::GetClassConstant

class Unk_SSG09a700 { public: MS2Ptr<CMaid> FUN_14127e400(__int64 nUid); };   // the field maids (before the user's own)
extern void* DAT_143ace478;                                         // TSingleton<CFieldMaidManager>::s_instance
// @0x14109a700
static Unk_SSG09a700* FUN_14109a700()
{
    return (Unk_SSG09a700*)DAT_143ace478;
}
class Unk_ArcMoverView { public: bool FUN_14160c1c0() const; CStringA FUN_14160c1e0() const; void FUN_14160bf90(float fTime, efd::Point3& kPos, float* pYaw); };   // Unk_NpcBeam getters
class Unk_1401aa6a0 : public CStringW { public: Unk_1401aa6a0(int nNpcId); };   // the npc name of the string table
class Unk_Svc7476c0 { public: unsigned char FUN_14074e030(int nNpcId); };
Unk_Svc7476c0* FUN_1407476c0();
class Unk_PortalQuestTable { public: int FUN_140764c90(CNpc* pNpc); };
class Unk_SingletonObj;
extern Unk_SingletonObj* DAT_143ab0d68;                             // TSingleton<CQuestMaskTable>::s_instance
// @0x14109a710
static Unk_PortalQuestTable* FUN_14109a710()
{
    return (Unk_PortalQuestTable*)DAT_143ab0d68;
}
class Unk_MmNpcTable { public: MS2Ptr<NpcDataCli> FUN_140a7cab0(int nNpcId); };
Unk_MmNpcTable* FUN_1406d6e90();
class UIDamageText { public: void FUN_141912a80(GameObject* pObj, int nValue, int n); };
UIDamageText* FUN_140b624b0(int nUiId);
class CStringTable { public: CStringW FUN_141811980(int nKind, int nId); };
CStringTable* GetStringTable();
#ifdef __clang__
CStringA FUN_140298360(const char* psz, const CStringA& str);   // the exe's operator+(const char*, const CStringA&)
#endif
// The views of pc.cpp: the world's object relation, the effect service's hit sounds / event effects, the local player.
class Unk_PCWorld { public: int FUN_141bd19d0(int nObjectId); };   // the relation of an object (1: the local player)
class Unk_PCFxMgr
{
public:
    void FUN_1411a5770(int nKind, PCBase* pTarget);                 // play an event effect on an actor
    unsigned FUN_1411a5580(int nMaterial, int nKind, int nRelation, const NiPoint3& kPos, float fVolume);   // hit sound
};
class MyPC { public: void FUN_14152e240(unsigned n); int FUN_14152e280(unsigned n); };
struct Unk_WsC_NpcAnim;
// The world service: the spawn animation of a spawn id (worldservice.h).
class WorldService { public: int FUN_141bcfff0(int id, Unk_WsC_NpcAnim* out); };
// The green / blue of the hit colour boost (npc.cpp data; the red is the npc's DamagedColorScale).
static float DAT_1439f6ff4 = 0.1f;
static float DAT_1439f6ff8 = 0.1f;
float FUN_14028d3a0(float fValue);                                  // * 0.01 (game units -> PhysX)
float FUN_140968970(float f);                                       // sqrtf
struct Unk_ICCEntityLoader;
Unk_ICCEntityLoader* FUN_141b6f910();
NiActorManager* FUN_140999440(void* pLoader, const egf::EntityID& kId);   // the actor manager of an entity's model
// The collision groups the dead bodies cycle through (so neighbouring corpses don't collide).
static unsigned s_aDeadGroupMask[] = { 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000, 0x10000, 0x20000 };
static int s_nDeadGroupMask = 8;
static int s_nDeadActorSerial;
NxVec3 FUN_140ae1df0(const Unk_StreamPoint* pPoint);               // game point -> PhysX point
// The maid description table (the row's +0x08 is the maid npc's title); the 16 byte row pointer of the maid tables
// (uimanufacturedialog.cpp), its members are COMDATs of other units.
template <class T> class Unk_UmValuePtr
{
public:
    ~Unk_UmValuePtr();                                              // 0x140680b50
    T* operator->() const;                                          // 0x1406810d0
    // @0x14109a370
    T* get() const { return m_p; }
private:
    void* m_pad;
    T* m_p;
};
struct Unk_UmDescRow
{
    char m_pad_00[0x8];
    CStringW m_08;                                                  // +0x08
};
class Unk_UmDescTable { public: Unk_UmValuePtr<Unk_UmDescRow> FUN_14067f780(int nMsgId); };
Unk_UmDescTable* FUN_1409eed10();
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);
void FUN_141567330(NiAVObject* pObj, bool b);
void FUN_1412751b0(const CStringW& str, int nLevel);              // debug log
void FUN_1410943b0(PCBase* pActor, int n);
// Talk scripts (FUN_140856fa0(npc id, n), as in cubespawnobject.cpp); the pointer members are COMDATs of other objs.
class Unk_ScriptContent
{
public:
    char m_pad[0x18];
    CStringW m_strText;                                             // +0x18
    CString m_strSound;                                             // +0x20
};
struct Unk_ScriptContentPtr
{
    Unk_ScriptContent* FUN_14078f3d0() const;                       // operator->
    void* m_00;
    void* m_p;
};
class Unk_ScriptContentArray
{
public:
    size_t FUN_14078fae0() const;                                   // GetCount
    const Unk_ScriptContentPtr& FUN_140a4ffc0(size_t i) const;      // GetAt
    const Unk_ScriptContentPtr& FUN_14078f350(size_t i) const;      // GetAt (other instance)
    Unk_ScriptContentPtr* m_pData;
    size_t m_nSize;
};
class Unk_TalkScript
{
public:
    char m_pad[0x68];
    Unk_ScriptContentArray m_contents;                              // +0x68
};
struct Unk_TalkScriptPtr
{
    ~Unk_TalkScriptPtr();                                           // 0x14078f140
    Unk_TalkScript* FUN_14078f3a0() const;                          // get
    Unk_TalkScript* FUN_14085a610() const;                          // operator->
    void* m_00;
    void* m_p;
};
Unk_TalkScriptPtr FUN_140856fa0(int nNpcId, int n);
class Unk_CinNpc;
class Unk_CinNameFilter { public: void FUN_1416fb400(CStringW& name, Unk_CinNpc* npc); };
Unk_CinNameFilter* FUN_1403b4750();
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);                  // the item data of an id
CString FUN_140cc2ba0(const CString& strRoot, const CString& strFile);   // path join
void FUN_1401d3700(CString& str);                                   // fixes up a resource path
// The nif / texture cache (nifeffectparam.h).
class CNifLoadingService
{
public:
    efd::SmartPointer<NiAVObject> Load(CString strPath, bool bFlag, int nClass, int nMyRefs, int nOtherRefs);
    efd::SmartPointer<NiTexture> GetTexture(CString strPath, int nClass);
};
CNifLoadingService* FUN_140a0afd0();
// Depth-first walker over a scene graph (util.cpp).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);                              // 0x14098cb80
    ~Unk_SceneWalker();                                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
void FUN_14123fbf0(Unk_PCBaseBody* pBody, unsigned short nGroup);  // collision group

class Unk_Svc764020;
Unk_Svc764020* FUN_140764020();
void FUN_1416d12d0(Unk_Svc764020* pMgr, int nNpcId, Unk_QmNpcQuestState* pState, int n);   // fill the npc's quest icon
class Unk_PCBaseCompEmoView : public Unk_PCBaseComp_a88 { public: void FUN_14192f910(); };     // UIEmoticon::Entity refresh
class Unk_CscWorld { public: PCBase* FUN_141bd1200(int nObjectId); };
const efd::Point3& FUN_140947900(void* pAVObject);                  // world translate of the node
const NiMatrix3& FUN_141024c90(void* pAVObject);                    // world rotate of the node
// The object vfunc_26 places at the actor every frame (as in gameobject.cpp).
class Unk_GoAttachment
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(NiPoint3 kPos, NiPoint3 kDir, float fScale);
};
void FUN_1411a4f40(CEffectService* pService, CStringA strEffect, const efd::Point3& kPos);   // play an effect at a point
class Unk_EmoNpcTable { public: int FUN_14035b0a0(int nNpcType); };
Unk_EmoNpcTable* FUN_140764010();
class Unk_FactoryApp;
Unk_FactoryApp* FUN_1403ed2b0();
const CStringA& FUN_141adc5d0(Unk_FactoryApp* pApp, int nUiId); // close a ui
const CStringA& FUN_141adc530(Unk_FactoryApp* pApp, int nUiId); // open a ui
int FUN_140de2860(void* pStore);
void FUN_140de2b50(void* pStore);
class Unk_SSGMisc2d80 { public: void FUN_140de2a00(); };
extern Unk_SSGMisc2d80 DAT_143ab2d80;
extern int DAT_143abdc30;                                           // the npc id of the last 0x4f50 dialog
class Unk_EmoCfgFloat { public: float* FUN_140967520(const float* pDefault); };

class Unk_PoEffectSvc { public: unsigned FUN_1411a49c0(NoticeMessage& kQuery); unsigned FUN_1411a4a00(NoticeMessage& kQuery); };
class Unk_PortalQuestTable2 { public: int FUN_140764ef0(CNpc* pNpc); };
class WorldService;
PCBase* FUN_141bd1290(WorldService* pWorld, int nObjectId);

CPhysXHelper* FUN_1409f7ca0();

class Unk_PopupTimerCfg;
Unk_PopupTimerCfg* FUN_140a36020(void* pValue);                    // Value<MS2Tick>::Get
int FUN_140a35ca0(Unk_PopupTimerCfg* pTick);                        // MS2Tick -> ms
class Unk_UisSceneMgr;
Unk_UisSceneMgr* FUN_1408e57f0();
int FUN_1422b9ea0(Unk_UisSceneMgr* pMgr);                           // a full-screen ui is open
class Unk_TalkMgrView { public: void FUN_141b20790(int nObjectId, int nFriendly); };   // UITalkManager: monologue
Unk_TalkMgrView* FUN_140967100();
class UITalkManager { public: int GetTalking(); };                // a talk is open
int FUN_14028d260(float f);                                         // float -> int (ms)
float FUN_14028d5b0(float fAngle);                                  // normalise an angle
float FUN_14059d930(float f);                                       // fabs
extern int DAT_143ae2b4c;                                           // the optimizer's turn-smoothing option

// (a CMaid member in the exe: the maid arrives as this)
struct Unk_NpcMaid : CMaid { CStringW FUN_14109a730(); };

// The maid's profile title.
// @0x14109a730
CStringW Unk_NpcMaid::FUN_14109a730()
{
    return m_profile.title;
}

// @0x14109a9d0
int COptimizer::FUN_14109a9d0()
{
    return DAT_143ae2b4c;
}

// @0x14109ac70
static float FUN_14109ac70(float f)
{
    float fSign;
    if (f > 0.0f)
        fSign = 1.0f;
    else
        fSign = (f < 0.0f) ? -1.0f : 0.0f;
    return fSign;
}

// @0x14109a9e0
static int FUN_14109a9e0()
{
    return rand();
}

// @0x14109ace0
static float FUN_14109ace0()
{
    return -1.0f + (2.0f * (float)FUN_14109a9e0()) / 32767.0f;
}

class CCameraMode { public: virtual ~CCameraMode(); };
class CTargetCameraMode : public CCameraMode {};
class CBossTargetCamera : public CTargetCameraMode { public: void FUN_140a38550(int nObjectId); };
class Unk_NpcCamera { public: int FUN_140af7e30(); CCameraMode* FUN_140af2520(); };   // CameraMgr (inline getters)
Unk_NpcCamera* FUN_1409478c0();
class GameObjectController { public: void FUN_14123fd30(unsigned int nFlags); };
class Unk_PCBaseCompEmoView2 : public Unk_PCBaseComp_a88
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // refresh
    void FUN_140f49470();                                           // UIHudEntity::TimerEntity: restart
    void FUN_14192f8b0(int n);
    void FUN_14192f8d0(const CString& strIcon);
};
class UIUpperHpBar { public: void FUN_141b4c510(CNpc* pNpc, int nTargetId); };
UIUpperHpBar* FUN_14096e340(int nUiId);
extern int g_upperTargetId;                                         // 0x143ab2864

class Unk_NpcShadowMgr { public: int FUN_141376880(int nKind); int FUN_1413769d0(int nKind); };   // shadow lod options
Unk_NpcShadowMgr* FUN_140ae1c00();
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);                         // the common npc row
class SkillDataTableCli;
SkillDataTableCli* FUN_1401958b0();
void FUN_140aae720(SkillDataTableCli* pTable, unsigned int nSkillId, unsigned short nLevel, int nFlags);   // preload a skill
class Unk_PCBaseFxLibView { public: void FUN_1411be510(int nNpcId, CString strUnused); };   // preload the npc's effects
int FUN_14082f1a0(int nStat);                                       // the stat is 64-bit

struct Unk_ICCApp;
Unk_ICCApp* FUN_14086d260();
class CMainSystem;
double FUN_141473280(CMainSystem* pSystem);                         // the frame time
int FUN_140869420();                                                // tick count (ms)
unsigned int FUN_140a7d630(Common::Constants::Value<Unk_ConstColor>* pValue);
CItem* FUN_14052cd70(MS2Ptr<CItem>* pItem);                         // get
struct Unk_UgcTable;
Unk_UgcTable* FUN_140281980();
unsigned int FUN_1405569f0(Unk_UgcTable* pTable, int nGrade);       // the grade's name color
class Unk_NameTagView : public Unk_PCBaseComp_a78 { public: int FUN_141a5e690(); void FUN_140f48dc0(int bShow); };

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };   // zero-initialised pointer holder (0x1401cd100)

// ---- header statics (two copies: the unit holds two objs' initializers) ----

static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer2(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- CNpcVibrate ----

// @0x14108e1e0
CNpcVibrate::CNpcVibrate()
{
    m_fStart = 0.0f;
    m_fEnd = 0.0f;
    m_fAmp = 0.0f;
    m_bActive = 0;
}

// @0x14108e250
CNpcVibrate::~CNpcVibrate()
{
}

// @0x14108e280
int CNpcVibrate::IsActive()
{
    return m_bActive;
}

// @0x14108e2a0
void CNpcVibrate::FUN_14108e2a0(float fStart, float fEnd, float fAmp)
{
    m_fStart = fStart;
    m_fEnd = fEnd;
    m_fAmp = fAmp;
    m_bActive = 1;
}

// @0x14108e300
void CNpcVibrate::FUN_14108e300(float fTime, efd::Point3& kPos)
{
    if (m_bActive != 0) {
        if (m_fEnd <= fTime) {
            m_bActive = 0;
        } else {
            efd::Point3 kOffset = efd::Point3::ZERO;
            unsigned int nX = FUN_140768010(2, 0);
            unsigned int nY = FUN_140768010(2, 0);
            kOffset.x = FUN_140768090();
            kOffset.x = kOffset.x * ((float)nX - 0.5f) * 2.0f;
            kOffset.y = FUN_140768090();
            kOffset.y = kOffset.y * ((float)nY - 0.5f) * 2.0f;
            kOffset.Unitize();
            kPos += kOffset * m_fAmp;
        }
    }
}

// ---- CNpc ----

// @0x14108e420
CNpc::CNpc()
    : m_pD60(0), m_pD68(0), m_cEAC(0), m_nEB0(0), m_nEB4(0), m_nOwnerId(0), m_nEC0(0), m_nEC4(0), m_spF28(0), m_cF38(0)
{
    m_spSkillRow = 0;
    m_nD80 = 3;
    m_nD84 = 4;
    m_bUnkB8 = 1;
    m_nDAC = 0;
    m_unk_b0 = 1;
    m_posD40 = efd::Point3::ZERO;
    m_spNpcData = 0;
    m_unkD88.MakeIdentity();
    m_spStateMgr.AssignRaw(new CStateManager(this));
    m_spStateMgr->FUN_1417daeb0(1, new StateIdleNPC(this));
    m_spStateMgr->FUN_1417daeb0(2, new StateWalkNPC(this));
    m_spStateMgr->FUN_1417daeb0(0xc, new StateDeadNPC(this));
    m_spStateMgr->FUN_1417daeb0(6, new StateJumpNpc(this));
    m_spStateMgr->FUN_1417daeb0(0x10, new StateSkill(this));
    m_spStateMgr->FUN_1417daeb0(0xd, new StateHitNPC(this));
    m_spStateMgr->FUN_1417daeb0(0x12, new StateStun(this));
    m_spStateMgr->FUN_1417daeb0(0x16, new StateTalkNpc(this));
    m_spStateMgr->FUN_1417daeb0(0x11, new StateSpawn(this));
    m_spStateMgr->FUN_1417daeb0(0x17, new StateRegen(this));
    m_spStateMgr->FUN_1417daeb0(0x23, new StatePuppetNpc(this));
    m_spStateMgr->FUN_1417daeb0(0x38, new StateSummonPortal(this));
    m_f164 = FUN_1401d3200()->OffsetNpcHpbar.Read();
    m_f168 = FUN_1401d3200()->OffsetNpcChatballoon.Read();
    m_f16c = FUN_1401d3200()->OffsetNpcNametag.Read();
    m_f170 = 0.0f;
    m_f174 = 0.0f;
    m_f178 = FUN_1401d3200()->OffsetNpcDamagenumber.Read();
    m_nDE0 = 0;
    m_nDE4 = 0;
    m_nE60 = 0;
    m_nE10 = 0;
    m_cE40 = 0;
    m_nE48 = 0;
    m_nE14 = 0;
    m_cE50 = 0;
    m_nE54 = 0;
    m_nE58 = 0;
    m_nEA8 = 0;
    m_spC40 = 0;
    m_nDE8 = 0;
    m_nEB8 = 0;
    m_nEE0 = 0;
    m_nF20 = 0;
}

// @0x14108ef30
CNpc::~CNpc()
{
    if (m_nE54 > 0)
        FUN_1411a6060(FUN_1403ed280(), m_nE54);
    FUN_141095140();
}

// @0x14108f0a0
int CNpc::vfunc_10()
{
    if (PCBase::vfunc_10() == 0)
        return 0;
    if (FUN_141092ff0()) {
        if (FUN_1409478c0()->FUN_140af7e30() == 0x12) {
            CBossTargetCamera* pCamera = dynamic_cast<CBossTargetCamera*>(FUN_1409478c0()->FUN_140af2520());
            if (pCamera != NULL)
                pCamera->FUN_140a38550(FUN_14123c580());
        }
        FUN_1403ed2d0()->FUN_141bc7ec0(FUN_14123c460());
        FUN_1409f7c90()->FUN_14161d010(FUN_14123c460());
        if ((m_spNpcData->m_nClass == 3 || m_spNpcData->m_nClass == 4) && vfunc_116() == 0)
            FUN_1409f7c90()->FUN_14109ac50(0);
    }
    m_strED0 = m_spNpcData->m_dead.GetRandomDefaultAction();
    reinterpret_cast<GameObjectController*>(m_unk_150)->FUN_14123fd30(0x38d);
    vfunc_126(m_unk_15c == 0, 0);
    FUN_141094e60();
    if (m_unk_15c == 0) {
        FUN_141096730();
        if (!m_spNpcData->m_strKeepEffect.IsEmpty()) {
            NoticeMessage kQuery;
            kQuery.m_strName = m_spNpcData->m_strKeepEffect;
            kQuery.SetActor(FUN_14123c580());
            kQuery.m_nObject = m_spNpcData->IsBoss() ? 6 : 5;
            m_nE54 = reinterpret_cast<Unk_PoEffectSvc*>(FUN_1403ed280())->FUN_1411a49c0(kQuery);
        }
        if (!m_spNpcData->m_strCreateEffect.IsEmpty()) {
            NoticeMessage kQuery;
            kQuery.m_strName = m_spNpcData->m_strCreateEffect;
            kQuery.SetActor(FUN_14123c580());
            kQuery.m_nObject = m_spNpcData->IsBoss() ? 6 : 5;
            reinterpret_cast<Unk_PoEffectSvc*>(FUN_1403ed280())->FUN_1411a4a00(kQuery);
        }
        FUN_1410947e0();
    }
    Unk_PCBaseCompEmoView2* pEmoticon = static_cast<Unk_PCBaseCompEmoView2*>(vfunc_83().get());
    if (pEmoticon != NULL) {
        if (m_spNpcData->m_strIcon.IsEmpty()) {
            if (0 < m_spNpcData->GetKind()) {
                pEmoticon->FUN_140f49470();
                pEmoticon->FUN_14192f8b0(0);
                pEmoticon->vfunc_2();
            }
        } else if (m_spNpcData->m_strIcon != "empty") {
            pEmoticon->FUN_140f49470();
            pEmoticon->FUN_14192f8b0(0);
            pEmoticon->FUN_14192f8d0(m_spNpcData->m_strIcon);
            pEmoticon->vfunc_2();
        }
        FUN_141093c80();
    }
    UIUpperHpBar* pUpper;
    if (m_spNpcData->HasPropertyTag(4) == true && (pUpper = FUN_14096e340(0x4e3d)) != NULL && FUN_14166ce30() == 0)
        pUpper->FUN_141b4c510(this, g_upperTargetId);
    return 1;
}

// @0x14108f710
void CNpc::vfunc_12()
{
    PCBase::vfunc_12();
    for (unsigned __int64 i = 0; i < m_spNpcData->m_effectDummies.size(); i++)
        FUN_141674ef0(m_spNpcData->m_effectDummies[i]);
    if (FUN_14028d470(FUN_1416749a0()->FUN_140970720(), 1.0f)) {
        if (GetNpcData()->m_model.m_nSpawnAlphaAnimation != 0)
            vfunc_40(0.0f, 1.0f, 0.0f, 0.5f);
    }
    vfunc_119();
    FUN_141675980();
    vfunc_82();
    if (!GetNpcData()->HasPropertyTag(2))
        return;
    if (!(FUN_14166ce30() == 0 && vfunc_80().get() != 0))
        return;
    vfunc_80()->FUN_141992140(1);
    vfunc_80()->FUN_141992180(FUN_141670a00(4), FUN_141670a30(4));
}

// @0x14108fb00
void CNpc::vfunc_14()
{
    if (FUN_141092ff0() != 0) {
        FUN_1403ed2d0()->FUN_141bc7f10(FUN_14123c460());
        FUN_1409f7c90()->FUN_14161d070(FUN_14123c460());
    }
    FUN_1410979a0();
    FUN_141099ab0();
    PCBase::vfunc_14();
}

// @0x14108fbb0
void CNpc::vfunc_45(float f)
{
    GameObject::vfunc_45(f);
}

// @0x14108fbe0
float CNpc::vfunc_46(const efd::Point3& kPos)
{
    return GameObject::vfunc_46(kPos);
}

// @0x14108fc10
void CNpc::vfunc_47(bool b)
{
    if (m_spNpcData->IsBossNpc())
        GameObject::vfunc_47(false);
    else
        GameObject::vfunc_47(b);
}

// @0x14108fc70
void CNpc::vfunc_27(ATL::CAtlArray<Unk_GoAnchorPtr>& kArr)
{
    reinterpret_cast<ATL::CAtlArray<MS2Ptr<CBoxCollision> >&>(kArr).Copy(m_arrE68);
}

// @0x14108fcb0
void CNpc::vfunc_28(void* p)
{
    static_cast<ATL::CAtlArray<MS2Ptr<CBoxCollision> >*>(p)->Copy(m_arrE88);
}

// @0x14108fcf0
int CNpc::vfunc_58()
{
    if (GetNpcData()->IsBoss())
        return 6;
    return 5;
}

// @0x14108fd60
Unk_PCBaseFxLib* CNpc::vfunc_70()
{
    return FUN_140a50010()->FUN_1411bf1e0();
}

// @0x14108fd90
int CNpc::vfunc_64()
{
    return m_spNpcData->m_nHitImmune;
}

// @0x14108fdc0
int CNpc::vfunc_78()
{
    if (m_nE58 != 0)
        return (unsigned short)m_nE58;
    return m_spNpcData->GetLevel();
}

// MS2-FUNCTIONAL: the exe returns vfunc_78() / 0 in eax (PCBase declares the slot void).
// @0x14108fe10
void CNpc::vfunc_79()
{
    if (m_spNpcData == 0)
        return;
    if (m_spNpcData->HasPropertyTag(3))
        return;
    vfunc_78();
}

// The hp bar (created when the npc row shows one).
// @0x14108fe90
MS2Ptr<Unk_PCBaseComp_a58> CNpc::vfunc_80()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0 && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a58>(0);
    if (m_spA58 == 0) {
        bool bHpBar = GetNpcData()->m_bHpBar;
        if (bHpBar) {
            if ((m_spA58 = FUN_141992920(m_unk_70)).get() != 0)
                m_spA58->FUN_141992140(0);
        }
    }
    return m_spA58;
}

// The name tag.
// @0x141090030
MS2Ptr<Unk_PCBaseComp_a78> CNpc::vfunc_82()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0 && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a78>(0);
    if (m_spA78.get() == 0) {
        if (FUN_140a7c8d0(GetNpcData().operator->())) {
            if ((m_spA78 = FUN_141a60da0(m_unk_70)).get() != 0) {
                m_spA78->FUN_141a5e4c0(GetNpcData()->GetUnknown12());
                m_spA78->FUN_141a5e500(FUN_140a7c970(GetNpcData().operator->()));
                m_spA78->vfunc_2();
            }
        }
        return m_spA78;
    }
    return m_spA78;
}

// The buff balloon.
// @0x1410902f0
MS2Ptr<Unk_PCBaseComp_a98> CNpc::vfunc_84()
{
    if (m_spA98 == 0)
        m_spA98 = FUN_14128ef70(m_unk_70);
    return m_spA98;
}

// The emoticon.
// @0x1410903b0
MS2Ptr<Unk_PCBaseComp_a88> CNpc::vfunc_83()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0 && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a88>(0);
    if (m_spA88.IsNull() && vfunc_116() > 0)
        m_spA88 = FUN_14192fd40(m_unk_70);
    return m_spA88;
}

// The chat balloon.
// @0x1410904c0
MS2Ptr<Unk_PCBaseComp_aa8> CNpc::vfunc_85()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0 && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_aa8>(0);
    if (m_spAA8 == 0)
        m_spAA8 = FUN_1418fbdb0(m_unk_70);
    return m_spAA8;
}

// @0x1410905c0
const char* CNpc::vfunc_123(int n)
{
    if (n == 0x34 && !m_strED0.IsEmpty())
        return m_strED0;
    return PCBase::vfunc_123(n);
}

// MS2-FUNCTIONAL: the last argument is a 12-byte point passed by value (PCBase declares it void*).
// @0x141090620
void CNpc::vfunc_111(void* p, int a, int b, void* q)
{
    if (FUN_14166ce30() != 0 && GetNpcData()->GetCorpseHitAble() != 0)
        return;
    efd::Point3 kPos = *static_cast<efd::Point3*>(q);
    PCBase::vfunc_111(p, a, b, &kPos);
}

// @0x141090740
void CNpc::vfunc_112(void* p, int n)
{
    if (FUN_14166ce30() != 0 && GetNpcData()->GetCorpseHitAble() != 0)
        return;
    PCBase::vfunc_112(p, n);
}

// @0x141090820
void CNpc::vfunc_113(void* p)
{
    PCBase::vfunc_113(p);
}

// @0x141090850
float CNpc::vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut)
{
    *pOut = 0;
    float fRate = 1.0f;
    float fSpeed = 1.0f;
    if (vfunc_65() != 0) {
        if (0.0f < b)
            fRate = a / b;
    } else if (0.0f < c) {
        fRate = a / c;
    }
    if (nFlag == 0)
        fSpeed = vfunc_97();
    if (m_unk_968 != 0)
        fRate = 1.0f;
    return d * fRate * fSpeed;
}

// @0x141090950
float CNpc::vfunc_98(float f)
{
    return FUN_1401c0db0()->CalcNpcAsiR(FUN_141670a00(0xd), f);
}

// @0x141090ba0
int CNpc::vfunc_116()
{
    return m_spNpcData->GetFriendly();
}

// @0x141090bd0
CStringW CNpc::vfunc_77()
{
    if (vfunc_128())
        return FUN_141093310();
    if (!m_strW918.IsEmpty())
        return m_strW918;
    if (m_spNpcData.get() == 0)
        return L"";
    return FUN_141093310();
}

// @0x141090cd0
void CNpc::vfunc_32(bool b)
{
    if (m_spShadow && m_spShadow->FUN_14109a720()) {
        if (FUN_140f4a450() < 200000.0f)
            vfunc_93(false);
    }
    PCBase::vfunc_32(b);
}

// @0x141090d60 (vfunc_124) - see below

// @0x1410916a0
void CNpc::vfunc_126(int a, int b)
{
    if (!(!m_spNpcData.IsNull() && (m_nEB8 == 0 || b != 0)))
        return;
    if (a == 0 || m_spNpcData->m_capsule.m_nIgnore != 0)
        FUN_14123fbf0(m_unk_150, 5);
    else
        FUN_14123fbf0(m_unk_150, 4);
}

// @0x141091740
int CNpc::vfunc_127()
{
    return 1;
}

// @0x141091760
int CNpc::vfunc_128()
{
    return (unsigned __int64)m_nE48 > 0 ? 1 : 0;
}

// The index of a value in an array (-1: none).
// @0x141099bd0
static int FUN_141099bd0(const ATL::CAtlArray<int>& arr, const int& nValue)
{
    for (int i = 0; i < (int)arr.GetCount(); i++) {
        if (arr[i] == nValue)
            return i;
    }
    return -1;
}

// Applies a sync block of the npc: the animation (or a jump arc), the position / rotation / velocity, then the state
// change when the state serial moved on.
// MS2-FUNCTIONAL: written from the decompile
// @0x1410918e0
void CNpc::FUN_1410918e0(CByteBuffer& buf)
{
    if (m_unk_b4 == 0)
        return;
    CInputStream& in = buf;
    CString strAnim;
    unsigned char nFlags = in.ReadUInt8();
    int bRotate = (nFlags & 1) == 1;
    int bEmotion = (nFlags & 2) == 2;
    Unk_StreamPoint ptPos = in.ReadVector3Short();
    efd::Point3 kPos = reinterpret_cast<const efd::Point3&>(ptPos);
    float fRotZ = in.ReadShortDiv10();
    Unk_StreamPoint ptVel = in.ReadVector3Short();
    efd::Point3 kVel = reinterpret_cast<const efd::Point3&>(ptVel);
    float fSpeed = in.ReadShortDivScaled(100);
    int nOwnerActor = 0;
    if (FUN_141092ff0())
        nOwnerActor = in.ReadInt32();
    int nState = in.ReadUInt8();
    m_nDE8 = in.ReadInt16();
    unsigned nSerial = (unsigned short)in.ReadInt16();
    if ((short)m_nDE8 == -2) {
        strAnim = "Jump_A";
    } else if ((short)m_nDE8 == -3) {
        strAnim = "Jump_B";
    } else {
        egf::EntityID kId;
        efd::SmartPointer<NiActorManager> spManager = FUN_140999440(FUN_141b6f910(), FUN_14123c460(kId));
        if (spManager != 0) {
            int nSeq = (short)m_nDE8;
            NiSequenceData* pSeq = spManager->GetSequenceData(nSeq);
            if (pSeq != NULL)
                strAnim = (const char*)pSeq->GetName();
        }
    }
    kPos.z = kPos.z + 4.0f;
    bool bPlace = true;
    if (!strAnim.IsEmpty()) {
        if ((short)m_nDE8 == -2 || (short)m_nDE8 == -3) {
            if (in.ReadUInt8() == 0) {
                Unk_StreamPoint ptTo = in.ReadVector3();
                efd::Point3 kTo = reinterpret_cast<const efd::Point3&>(ptTo);
                kTo.z = kTo.z + 2.0f;
                m_unkDB0.Set(kPos, kTo, strAnim);
                FUN_14166dd20(efd::utf8string((const char*)strAnim), fSpeed, true, false);
            } else {
                Unk_StreamPoint ptFrom = in.ReadVector3();
                Unk_StreamPoint ptTo = in.ReadVector3();
                float fWidth = in.ReadFloat();
                float fScale = in.ReadFloat();
                efd::Point3 kTo = reinterpret_cast<const efd::Point3&>(ptTo);
                kTo.z = kTo.z + 2.0f;
                m_unkDB0.Set(reinterpret_cast<const efd::Point3&>(ptFrom), kTo, fWidth, fScale, strAnim);
            }
        } else {
            if (strAnim.Find("Run_", 0) == 0) {
                float fRunSpeed = GetNpcData()->m_model.m_fAniSpeed * vfunc_97();
                fSpeed = fRunSpeed;
                float fDist = (static_cast<const efd::Point3&>(vfunc_18()) - kPos).Length();
                if (30.0f < fDist) {
                    efd::Point3 kAhead = kPos + kVel * 0.3f;
                    float fFromSelf = (kAhead - static_cast<const efd::Point3&>(vfunc_18())).Length();
                    float fFromPos = (kAhead - kPos).Length();
                    float fRatio = fFromSelf / fFromPos;
                    if (fRatio < 2.0f) {
                        float fMax = 1.2f;
                        float fScale = std::min(fMax, fRatio);
                        float fMin = 0.8f;
                        fScale = std::max(fMin, fScale);
                        if (1.03f < fScale || fScale < 0.97f) {
                            fSpeed = fSpeed * fRatio;
                            kVel *= fScale;
                            bPlace = false;
                        }
                    }
                }
            }
            if (reinterpret_cast<AdditionalCliList*>(FUN_1416749a0())->FUN_1409709b0() == 0 && nState != 0x11) {
                FUN_141092d40(CString(strAnim));
                FUN_14166dd20(efd::utf8string((const char*)strAnim), fSpeed, false, false);
            }
        }
    }
    FUN_141094ff0(nOwnerActor);
    FUN_14166ce70(bEmotion);
    if (!reinterpret_cast<Unk_ArcMoverView*>(&m_unkDB0)->FUN_14160c1c0() && m_pD60 == NULL) {
        if (FUN_14166c930() == 0xd)
            kPos.z = static_cast<const efd::Point3&>(vfunc_18()).z;
        if (!bPlace)
            FUN_14166d260();
        else
            vfunc_19(kPos);
        FUN_14166d8b0(fRotZ);
        if (bRotate)
            vfunc_21(efd::Point3(0.0f, 0.0f, fRotZ));
    }
    m_posD40 = kVel;
    if (nSerial == (unsigned)m_nDAC)
        return;
    m_nDAC = nSerial;
    if (nState == 0x11) {
        int nSpawn = in.ReadInt32();
        if (nSpawn != 0 && FUN_14166c930() != nState) {
            MS2Ptr<StateSpawnData> spData(new StateSpawnData);
            if (reinterpret_cast<WorldService*>(FUN_1403ed2d0())->FUN_141bcfff0(nSpawn,
                    reinterpret_cast<Unk_WsC_NpcAnim*>(spData.get())) != 0) {
                vfunc_59(nState, spData.get(), 0, 0);
                return;
            }
        }
    } else if (nState == 0x16) {
        int nTalking = reinterpret_cast<UITalkManager*>(FUN_140967100())->GetTalking();
        if (FUN_14166cc80() == 0x49 && nTalking == 0) {
            if (GetNpcData()->m_bLookAtMyPCWhenTalking) {
                CQuestManager* pQuest = reinterpret_cast<CQuestManager*>(FUN_140764020());
                if (pQuest->FUN_1416d0610() != 0) {
                    Unk_StreamPoint ptTarget = reinterpret_cast<CQuestManager*>(FUN_140764020())->FUN_1416d0690();
                    if (reinterpret_cast<const efd::Point3&>(ptTarget) != efd::Point3::ZERO)
                        FUN_14166d2d0(reinterpret_cast<const efd::Point3&>(ptTarget), 0);
                }
            }
            return;
        }
        if (FUN_14166cc80() == 0x48 && nTalking != 0) {
            if (GetNpcData()->m_bLookAtMyPCWhenTalking) {
                PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pPlayer != NULL)
                    FUN_14166d2d0(static_cast<const efd::Point3&>(pPlayer->vfunc_18()), 0);
            }
            return;
        }
        vfunc_59(nState, 0, 0, 1);
        return;
    } else if (nState == 0x38) {
        if (reinterpret_cast<CQuestManager*>(FUN_140764020())->FUN_1416d0610() != 0) {
            if (GetNpcData()->m_bLookAtMyPCWhenTalking) {
                Unk_StreamPoint ptTarget = reinterpret_cast<CQuestManager*>(FUN_140764020())->FUN_1416d0690();
                if (reinterpret_cast<const efd::Point3&>(ptTarget) != efd::Point3::ZERO)
                    FUN_14166d2d0(reinterpret_cast<const efd::Point3&>(ptTarget), 0);
            }
        }
    } else if (nState == 0xd) {
        MS2Ptr<StateHitData> spData(new StateHitData);
        spData->m_f1c = in.ReadFloat();
        spData->m_f24 = in.ReadFloat();
        spData->m_f28 = in.ReadFloat();
        spData->m_n2c = in.ReadUInt8() != 0;
        FUN_14166dd20(efd::utf8string((const char*)strAnim), fSpeed, true, false);
        vfunc_59(nState, spData.get(), 0, 1);
        return;
    } else if (nState == 0x12 || reinterpret_cast<AdditionalCliList*>(FUN_1416749a0())->FUN_1409709b0() != 0) {
        return;
    }
    ATL::CAtlArray<int> aSkip;
    int nNone = 0;
    aSkip.Add(nNone);
    if (FUN_141099bd0(aSkip, nState) == -1)
        vfunc_59(nState, 0, 0, 0);
}

// @0x141092c50
void CNpc::FUN_141092c50(CInPacket& packet)
{
    unsigned char nMode = packet.ReadUInt8();
    if (nMode == 0)
        FUN_141095240(packet.ReadInt64());
    else if (nMode == 1)
        m_nF20 = packet.ReadInt32();
    else if (nMode == 2)
        m_nF20 = 0;
}

// @0x141092d20
bool CNpc::vfunc_68(void* a, double t, int b, unsigned c, int d)
{
    return false;
}

// @0x141092d40
void CNpc::FUN_141092d40(CString strAnim)
{
    if (m_cEAC == 0)
        return;
    if (FUN_14166dc50() != "Bore_A" && strAnim == "Bore_A") {
        m_nEB0++;
        FUN_1412751b0(StringFormat(L"OnPreStartAnimation Bore ani:{0} / emo:{1}", (unsigned&)m_nEB0, (unsigned&)m_nEB4), 0x14);
    }
    if (FUN_14166dc50() == "Bore_A" && strAnim != "Bore_A")
        FUN_1412751b0(StringFormat(L"Not Bore!! {0}/{1}", (unsigned&)m_nEB0, (unsigned&)m_nEB4), 0x14);
}

// @0x141092fa0
int CNpc::FUN_141092fa0()
{
    if (m_spNpcData.get() != 0)
        return m_spNpcData->GetId();
    return 0;
}

// @0x141092ff0
int CNpc::FUN_141092ff0()
{
    return m_spNpcData->IsBoss();
}

// @0x141093030
int CNpc::FUN_141093030()
{
    int nKind = FUN_1410934c0();
    if (nKind == 4 || nKind == 6)
        return 1;
    return 0;
}

// @0x141093070
bool CNpc::FUN_141093070()
{
    return m_spNpcData->IsMinimap();
}

// @0x1410930a0
int CNpc::FUN_1410930a0()
{
    if (FUN_141670a00(4) != 0)
        return 0;
    if (FUN_14166c930() != 0xc)
        return 0;
    bool bNoHit = GetNpcData()->GetCorpseHitAble() == 0;
    if (bNoHit)
        return 0;
    return 1;
}

// @0x141093160
int CNpc::FUN_141093160()
{
    if (m_spNpcData.get() != 0 && m_spNpcData->GetKind() == 2)
        return 1;
    return 0;
}

// @0x1410931c0
int CNpc::FUN_1410931c0()
{
    if (m_spNpcData.get() != 0 && m_spNpcData->GetKind() == 3)
        return 1;
    return 0;
}

// @0x141093220
int CNpc::FUN_141093220()
{
    if (m_spNpcData.get() != 0)
        return m_spNpcData->IsShopKind();
    return 0;
}

// @0x141093270
MS2Ptr<NpcDataCli> CNpc::GetNpcData()
{
    return m_spNpcData;
}

// @0x1410932c0
void CNpc::FUN_1410932c0(bool b)
{
    NiAVObject* pObj = FUN_141b6efc0(FUN_14123c410());
    if (pObj != NULL)
        FUN_141567330(pObj, b);
}

// @0x141093310
CStringW CNpc::FUN_141093310()
{
    if (vfunc_128()) {
        MS2Ptr<CMaid> spMaid = FUN_14109a700()->FUN_14127e400(m_nE48);
        if (spMaid.IsNull())
            spMaid = CUserMaidManager::GetInstance()->GetMaid(m_nE48);
        if (spMaid.get() != 0 && !spMaid->FUN_1409eeda0().IsEmpty())
            return spMaid->FUN_1409eeda0();
    }
    return Unk_1401aa6a0(FUN_141092fa0());
}

// @0x1410934c0
int CNpc::FUN_1410934c0()
{
    if (m_spNpcData == 0)
        return 0;
    return m_spNpcData->m_nClass;
}

// @0x141093510
unsigned short CNpc::FUN_141093510()
{
    return m_nDE8;
}

// @0x141093530
CStringA CNpc::FUN_141093530()
{
    if (!reinterpret_cast<Unk_ArcMoverView*>(&m_unkDB0)->FUN_14160c1c0())
        return CStringA();
    return reinterpret_cast<Unk_ArcMoverView*>(&m_unkDB0)->FUN_14160c1e0();
}

// @0x1410935b0
void CNpc::vfunc_66(int n)
{
    PCBase::vfunc_66(n);
    if (n != 0)
    {
        if (FUN_14166ce30() == 0 && (vfunc_80().get() ? true : false))
            vfunc_80()->FUN_141992180(FUN_141670a00(4), FUN_141670a30(4));
        FUN_1410943b0(this, 1);
    }
}

// @0x141093760
int CNpc::FUN_141093760()
{
    if (m_spNpcData.get() != 0)
        return m_spNpcData->GetNpcType();
    return 0;
}

// @0x1410937b0
int CNpc::FUN_1410937b0()
{
    if (m_spNpcData.get() != 0)
        return m_spNpcData->GetKind();
    return 0;
}

// @0x141093800
MS2Ptr<CMaid> CNpc::FUN_141093800()
{
    if (!vfunc_128())
        return MS2Ptr<CMaid>(0);
    MS2Ptr<CMaid> spMaid = FUN_14109a700()->FUN_14127e400(m_nE48);
    if (spMaid.IsNull())
        spMaid = CUserMaidManager::GetInstance()->GetMaid(m_nE48);
    return spMaid;
}

// @0x141093910
void CNpc::FUN_141093910()
{
    if (0 < m_nE60) {
        UIDamageText* pText = FUN_140b624b0(0x4e32);
        if (pText != NULL)
            pText->FUN_141912a80(this, (int)m_nE60, 0);
    }
    m_nE60 = 0;
}

// The name shown for the npc: a maid's own title, else the title of its maid row, else the npc name string.
// MS2-FUNCTIONAL: the maid temporaries live in different stack slots
// @0x141093980
CStringW CNpc::FUN_141093980()
{
    if (FUN_141093800().get() != 0) {
        if (!static_cast<Unk_NpcMaid*>(FUN_141093800().operator->())->FUN_14109a730().IsEmpty())
            return static_cast<Unk_NpcMaid*>(FUN_141093800().operator->())->FUN_14109a730();
        Unk_UmValuePtr<Unk_UmDescRow> spDesc = FUN_1409eed10()->FUN_14067f780(FUN_141093800()->m_nMaidId);
        if (spDesc.get() != 0)
            return spDesc->m_08;
    }
    return GetStringTable()->FUN_141811980(10, FUN_141092fa0());
}

// @0x141093c20
unsigned int CNpc::FUN_141093c20()
{
    return m_questState.m_questId;
}

// @0x141093c40
int CNpc::FUN_141093c40()
{
    return m_questState.m_icon;
}

// @0x141093c60
int CNpc::FUN_141093c60()
{
    return m_questState.m_state;
}

// Refreshes the npc's quest icon state and the emoticon when it changed.
// @0x141093c80
void CNpc::FUN_141093c80()
{
    m_nE10 = 0;
    int nIcon = m_questState.m_icon;
    int nState = m_questState.m_state;
    if (!GetNpcData().IsNull() && vfunc_116() != 0 && m_cE40 != 0) {
        m_questState.FUN_1409669c0();
        FUN_1416d12d0(FUN_140764020(), FUN_141092fa0(), &m_questState, 0);
        if (nIcon != m_questState.m_icon || nState != m_questState.m_state) {
            if (vfunc_83().get() != 0)
                static_cast<Unk_PCBaseCompEmoView*>(vfunc_83().operator->())->FUN_14192f910();
        }
    }
}

// @0x141093e90
void CNpc::FUN_141093e90()
{
    m_nE10 = 1;
}

// Turns toward the owner actor's model node.
// @0x141093eb0
void CNpc::FUN_141093eb0()
{
    if (m_nF20 == 0)
        return;
    PCBase* pOwner = reinterpret_cast<Unk_CscWorld*>(FUN_1403ed2d0())->FUN_141bd1200(m_nF20);
    if (pOwner != NULL) {
        efd::SmartPointer<NiAVObject> spNode = pOwner->FUN_141675930();
        if (spNode != 0) {
            efd::Point3 kPos = FUN_140947900(spNode.operator->());
            vfunc_19(kPos);
        }
    }
}

// @0x141093fa0
void CNpc::FUN_141093fa0()
{
    if (m_spNpcData.get() != 0)
        FUN_1411a4f40(FUN_1403ed280(), m_spNpcData->m_strSoundStart, vfunc_18());
}

// @0x141094050
void CNpc::FUN_141094050()
{
    if (MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = vfunc_85())
        spBalloon->vfunc_3();
    if (m_spNpcData.get() != 0)
        FUN_1411a4f40(FUN_1403ed280(), m_spNpcData->m_strSoundEnd, vfunc_18());
}

// The ui an npc type opens on talk (0: none).
// @0x141094170
int CNpc::FUN_141094170()
{
    int nType = FUN_141093760();
    switch (nType)
    {
    case 3:
        return 0x4e4a;
    case 2:
        return 0x4e47;
    case 1:
        return 0x4e3b;
    case 0x56:
        return 0x4e97;
    case 0x58:
        return 0x4f55;
    default:
        if (FUN_140764010()->FUN_14035b0a0(nType) != 0)
            return 0x4f50;
        return 0;
    }
}

// @0x141094200
int CNpc::FUN_141094200()
{
    int nUiId = FUN_141094170();
    if (nUiId == 0x4e4a) {
        FUN_141adc5d0(FUN_1403ed2b0(), 0x4e4a);
        FUN_141adc5d0(FUN_1403ed2b0(), 0x4e49);
    } else if (nUiId == 0x4e47) {
        if (FUN_140de2860(&DAT_143ab2d80) == 0) {
            FUN_140de2b50(&DAT_143ab2d80);
            return 0x4e47;
        }
        DAT_143ab2d80.FUN_140de2a00();
    } else if (nUiId == 0x4f50) {
        DAT_143abdc30 = FUN_141092fa0();
    }
    FUN_141adc530(FUN_1403ed2b0(), nUiId);
    return nUiId;
}

// @0x1410942c0
void CNpc::FUN_1410942c0()
{
    int nUiId = FUN_141094170();
    if (nUiId != 0)
        FUN_141adc5d0(FUN_1403ed2b0(), nUiId);
}

// In talk range of the camera (always for property tag 0x1a).
// @0x141094300
bool CNpc::FUN_141094300()
{
    if (m_spNpcData->HasPropertyTag(0x1a))
        return true;
    float fDefault = 400.0f;
    float* pRange = reinterpret_cast<Unk_EmoCfgFloat*>((char*)FUN_1401d3200() + 0x218)->FUN_140967520(&fDefault);
    float fRange = *pRange + m_spNpcData->m_capsule.m_fRadius;
    if (FUN_140f4a450() > fRange)
        return false;
    return true;
}

// Shows the npc's talk script line n: the balloon text (names filled in for a maid) and the line's sound, then restarts
// the monologue timer.
// @0x1410943b0
void FUN_1410943b0(PCBase* pActor, int n)
{
    CNpc* pNpc = static_cast<CNpc*>(pActor);
    Unk_TalkScriptPtr spScript = FUN_140856fa0(pNpc->FUN_141092fa0(), n);
    if (spScript.FUN_14078f3a0() != 0) {
        if (spScript.FUN_14085a610()->m_contents.FUN_14078fae0() != 0) {
            CStringW strText = spScript.FUN_14085a610()->m_contents.FUN_140a4ffc0(0).FUN_14078f3d0()->m_strText;
            if (strText.GetLength() > 0) {
                if (pNpc->vfunc_128())
                    FUN_1403b4750()->FUN_1416fb400(strText, reinterpret_cast<Unk_CinNpc*>(pNpc));
                pNpc->FUN_14166fff0(strText);
            }
            if (spScript.FUN_14085a610()->m_contents.FUN_140a4ffc0(0).FUN_14078f3d0()->m_strSound.GetLength() > 0)
                FUN_1411a4f40(FUN_1403ed280(),
                    spScript.FUN_14085a610()->m_contents.FUN_14078f350(0).FUN_14078f3d0()->m_strSound, pNpc->vfunc_18());
        }
    }
    pNpc->FUN_141099580();
}

// @0x1410945c0
void CNpc::vfunc_43(float f)
{
    GameObject::vfunc_43(f);
    if (f > 0.0f) {
        vfunc_126(0, 0);
    } else {
        if (FUN_14166ce30() == 0)
            vfunc_126(1, 0);
    }
}

// The emotion id of the npc row (the npc id when the row has none).
// @0x141094640
int CNpc::vfunc_69()
{
    MS2Ptr<CNpcData> spData;
    spData = GetNpcData();
    if (spData == 0)
        return 0;
    if (spData->m_nEmotionId != 0)
        return spData->m_nEmotionId;
    return spData->GetId();
}

// @0x141094730
void CNpc::SendInteractNpc()
{
    COutPacket packet(static_cast<int>(SendOp::InteractNpc), 0);
    packet.WriteInt32(FUN_14123c580());
    FUN_140710590(packet);
}

// @0x141094790
void CNpc::FUN_141094790(__int64 nUid)
{
    m_nE48 = nUid;
}

// @0x1410947c0
__int64 CNpc::FUN_1410947c0()
{
    return m_nE48;
}

// Hangs the reward item box (the item's grade box with the item icon) under "Eff_UI" once.
// @0x1410947e0
void CNpc::FUN_1410947e0()
{
    if (m_nEA8 == 0 || m_spC40 != 0)
        return;
    CString strUnused;
    MS2Ptr<CItemData> spItem = FUN_14053f870(m_nEA8);
    if (spItem == 0)
        return;
    CString strNif = CItemDataTable::GetInstance()->GetGradeNif((ItemGradeKey)1);
    strNif += ".nif";
    m_spC40 = FUN_140a0afd0()->Load(FUN_140cc2ba0(CString("Item"), strNif), false, 5, 0, 0);
    efd::SmartPointer<NiNode> spRoot = (NiNode*)FUN_141675150(CString("Eff_UI"));
    {
        Unk_SceneWalker kWalker(m_spC40);
        NiAVObject* pObj;
        while ((pObj = kWalker.Next(true)) != 0) {
            NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObj);
            if (pRender != 0 && pRender->GetName() == "Editable Mesh")
                pRender->SetName(NiFixedString("Item_Box"));
        }
    }
    if (spRoot != 0 && m_spC40 != 0) {
        spRoot->AttachChild(m_spC40, false);
        NiAVObject* pIcon = m_spC40->GetObjectByName(NiFixedString("Item_Icon:0"));
        if (pIcon != 0 && NiIsExactKindOf(NiMesh, pIcon)) {
            NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pIcon->GetProperty(8));
            NiTexturingProperty::Map* pMap;
            if (pTexturing != 0 && (pMap = pTexturing->GetBaseMap()) != 0) {
                CString strIcon = spItem->FUN_14053fdd0();
                FUN_1401d3700(strIcon);
                if (!strIcon.IsEmpty())
                    pMap->SetTexture(FUN_140a0afd0()->GetTexture(CString(strIcon), 5));
            }
        }
        m_spC40->UpdateEffects();
        m_spC40->UpdateProperties();
    }
}

// @0x141094dc0
void CNpc::FUN_141094dc0(__int64 n)
{
    m_nE60 = n;
}

// @0x141094df0
void CNpc::FUN_141094df0(__int64 n)
{
    m_nE60 += n;
}

// @0x141094e20
__int64 CNpc::FUN_141094e20()
{
    return m_nE60;
}

// @0x141094e40
void CNpc::FUN_141094e40(bool b)
{
    m_cEAC = b;
}

// Hides the npc while its portal quest condition fails.
// @0x141094e60
void CNpc::FUN_141094e60()
{
    if (m_nEB8 == 0)
        return;
    if (m_unk_b4 == 0)
        return;
    int bCollide;
    if (reinterpret_cast<Unk_PortalQuestTable2*>(FUN_14109a710())->FUN_140764ef0(this) == 0) {
        FUN_14166ca20(5);
    } else {
        FUN_14166ca80(5);
        if (m_unk_15c == 0) {
            bCollide = 1;
            goto done;
        }
    }
    bCollide = 0;
done:
    vfunc_126(bCollide, 1);
}

// @0x141094f20
void CNpc::SetOwnerId(int nOwnerId)
{
    m_nOwnerId = nOwnerId;
}

// @0x141094f40
int CNpc::GetOwnerId()
{
    return m_nOwnerId;
}

// @0x141094f60
PCBase* CNpc::FUN_141094f60()
{
    return FUN_141bd1290(reinterpret_cast<WorldService*>(FUN_1403ed2d0()), m_nOwnerId);
}

// @0x141094f90
void CNpc::FUN_141094f90(CString strEffect)
{
    m_strEC8 = strEffect;
    FUN_141095140();
    FUN_141095050();
}

// @0x141094ff0
void CNpc::FUN_141094ff0(int nActor)
{
    int nOld = m_nEC0;
    m_nEC0 = nActor;
    if (m_nEC0 != nOld) {
        FUN_141095140();
        FUN_141095050();
    }
}

// Attaches the +0xec8 effect to the +0xec0 actor.
// @0x141095050
void CNpc::FUN_141095050()
{
    PCBase* pActor = FUN_141bd1290(reinterpret_cast<WorldService*>(FUN_1403ed2d0()), m_nEC0);
    if (pActor == NULL)
        return;
    if (m_strEC8.GetLength() < 1)
        return;
    NoticeMessage kQuery;
    kQuery.m_strName = m_strEC8;
    kQuery.m_nObject = 6;
    kQuery.SetActor(pActor->FUN_14123c580());
    kQuery.m_bFlag31 = true;
    m_nEC4 = reinterpret_cast<Unk_PoEffectSvc*>(FUN_1403ed280())->FUN_1411a49c0(kQuery);
}

// @0x141095140
void CNpc::FUN_141095140()
{
    if (m_nEC4 != 0)
        FUN_1411a6060(FUN_1403ed280(), m_nEC4);
    m_nEC4 = 0;
}

// @0x141095190
void CNpc::FUN_141095190(const CString& strKfm)
{
    m_strED8 = strKfm;
}

// @0x1410951d0
void CNpc::FUN_1410951d0(const CString& strKfm)
{
    FUN_141095190(strKfm);
#ifdef __clang__
    // clang emits an unavailable MFC CopyChars import for operator+; call the exe's operator+.
    FUN_14123bc20(FUN_140298360("urn:gamebryo-animation:", m_strED8));
#else
    FUN_14123bc20("urn:gamebryo-animation:" + m_strED8);
#endif
}

// @0x141095240
void CNpc::FUN_141095240(__int64 n)
{
    m_nEE0 = n;
}

// @0x141095270
__int64 CNpc::FUN_141095270()
{
    return m_nEE0;
}

// @0x141095290
void CNpc::FUN_141095290(int n)
{
    m_nF20 = n;
}

// @0x1410952b0
void CNpc::FUN_1410952b0(bool b)
{
    m_cF38 = b;
}

// @0x1410952d0
bool CNpc::FUN_1410952d0()
{
    return m_cF38;
}

// Builds the npc's collision: the body box ("box" shape) and one box per node collision of the npc row (green, bound
// to model nodes) and per server node collision (orange, placed at the actor), then the terrain actor.
// MS2-FUNCTIONAL: the box temporaries live in different stack slots
// @0x141096730
void CNpc::FUN_141096730()
{
    if (m_spNpcData->m_collision.m_strShape == "box") {
        const Unk_NpcShape& kShape = m_spNpcData->m_collision;
        efd::Point3 kSize(m_spNpcData->m_collision.m_fWidth, m_spNpcData->m_collision.m_fDepth * 0.5f, kShape.m_fHeight);
        efd::Point3 kOffset(0.0f, m_spNpcData->m_collision.m_fDepth * 0.5f, 0.0f);
        FUN_141670fd0(kSize, kOffset);
    }
    if (!m_spNpcData->m_aNodeCollision.IsEmpty()) {
        for (unsigned i = 0; i < m_spNpcData->m_aNodeCollision.GetCount(); i++) {
            MS2Ptr<CNpcData::NodeCollision> spNode = m_spNpcData->m_aNodeCollision[i];
            if (spNode == 0)
                continue;
            MS2Ptr<CBoxCollision> spBox(new CBoxCollision);
            spBox->m_strName = spNode->m_strTargetNode;
            Unk_StreamPoint ptBox(spNode->m_vVolume.x, spNode->m_vVolume.y * 0.5f, spNode->m_vVolume.z);
            Unk_StreamPoint ptSize(0.0f, spNode->m_vVolume.y * 0.5f, 0.0f);
            spBox->m_ptBox = ptBox;
            spBox->m_ptSize = ptSize;
            spBox->m_ptDir = spNode->m_vOffset;
            spBox->m_kColor = NiColorA(0.0f, 1.0f, 0.0f, 1.0f);
            spBox->vfunc_4();
            m_arrE68.Add(spBox);
        }
    }
    if (!m_spNpcData->m_aNodeServerCollision.IsEmpty()) {
        for (unsigned i = 0; i < m_spNpcData->m_aNodeServerCollision.GetCount(); i++) {
            MS2Ptr<CNpcData::NodeCollision> spNode = m_spNpcData->m_aNodeServerCollision[i];
            if (spNode == 0)
                continue;
            MS2Ptr<CBoxCollision> spBox(new CBoxCollision);
            Unk_StreamPoint ptBox(spNode->m_vVolume.x, spNode->m_vVolume.y * 0.5f, spNode->m_vVolume.z);
            Unk_StreamPoint ptSize(0.0f, spNode->m_vVolume.y * 0.5f, 0.0f);
            spBox->m_ptBox = ptBox;
            spBox->m_ptSize = ptSize;
            spBox->m_ptDir = spNode->m_vOffset;
            spBox->m_kColor = NiColorA(1.0f, 0.5f, 0.0f, 1.0f);
            spBox->vfunc_4();
            m_arrE88.Add(spBox);
        }
    }
    NxTerrainPhsyx();
}

// Creates the dead body's PhysX actor (+0xd60): a box pushed back / up by the killing skill's knockback (scaled by the
// npc's push values, randomised by NPCRandomDeadPushRate, turned by the hit direction), then picks the dead animation
// (the "up" one when pushed up and the model has it).
// MS2-FUNCTIONAL: the PhysX descriptor / matrix temporaries live in different stack slots
// @0x141096f00
void CNpc::MakeDeadPhysXActor()
{
    s_nDeadActorSerial++;
    int nGroup = s_nDeadActorSerial % s_nDeadGroupMask;
    float fBackScale = 1.0f;
    float fUpScale = 1.0f;
    float fDensity = 1.0f;
    float fBack = 0.0f;
    float fUp = 0.2f;
    float fPushBack = 0.0f;
    float fPushUp = 0.0f;
    efd::Matrix3 kRot;
    kRot.MakeIdentity();
    if (m_spSkillRow.get() != 0) {
        fPushUp = FUN_14028d3a0(m_spSkillRow->GetSkill()->m_block170.m_fUp) * m_spNpcData->m_push.m_fUp;
        fPushBack = FUN_14028d3a0(m_spSkillRow->GetSkill()->m_block170.m_fBack) * m_spNpcData->m_push.m_fBack;
        static float s_fRate = FUN_1401d3200()->NPCRandomDeadPushRate.Read();
        fPushBack = fPushBack * (FUN_14109ace0() * s_fRate + 1.0f);
        fPushUp = fPushUp * (FUN_14109ace0() * s_fRate + 1.0f);
        if (FUN_14028d470(fPushBack, 0.0f) && FUN_14028d470(fPushUp, 0.0f))
            return;
        if (m_nD80 == 2) {
            int nRange = 3;
            float fStep = 30.0f;
            int nStep = rand() % nRange < 2 ? 1 : rand() % nRange;
            float fAngle = (float)nStep * fStep;
            kRot.MakeZRotation((fAngle * 3.1415927f) / 180.0f);
        } else if (m_nD80 == 1) {
            int nRange = 3;
            float fStep = 30.0f;
            int nStep = rand() % nRange < 2 ? 1 : rand() % nRange;
            float fAngle = (float)nStep * fStep;
            kRot.MakeZRotation((-fAngle * 3.1415927f) / 180.0f);
        } else if (m_nD80 == 3) {
            int nRange = 3;
            float fStep = 30.0f;
            int nStep = rand() % nRange;
            float fAngle = (float)nStep * fStep;
            if (rand() % 2 != 0)
                fAngle = -fAngle;
            kRot.MakeZRotation((fAngle * 3.1415927f) / 180.0f);
        }
    }
    fBack = fBack + fPushBack;
    fUp = fUp + fPushUp;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    if (pScene == NULL)
        return;
    FUN_1410979a0();
    NxVec3 kGravity;
    pScene->getGravity(kGravity);
    float fGravity = -kGravity.z;
    float fTime = FUN_140968970((fUpScale * fUp * 2.0f) / fGravity);
    float fUpSpeed = fTime * fGravity;
    efd::Matrix3 kDir = m_unkD88 * kRot;
    float fBackSpeed = (fBackScale * fBack) / (fTime * 2.0f);
    efd::Point3 kVel = (kDir * efd::Point3::UNIT_Y) * fBackSpeed;
    NxBodyDesc kBodyDesc;
    kBodyDesc.angularDamping = 0.0f;
    kBodyDesc.linearDamping = 0.0f;
    kBodyDesc.linearVelocity = NxVec3(kVel.x, kVel.y, fUpSpeed);
    kBodyDesc.flags |= NX_BF_FROZEN_ROT;
    NxBoxShapeDesc kBoxDesc;
    kBoxDesc.dimensions.set(m_spNpcData->m_collision.m_fWidth, m_spNpcData->m_collision.m_fDepth,
        m_spNpcData->m_collision.m_fHeight);
    kBoxDesc.dimensions = kBoxDesc.dimensions * 0.01f * 0.5f;
    kBoxDesc.groupsMask.bits0 = s_aDeadGroupMask[nGroup];
    NxActorDesc kActorDesc;
    kActorDesc.shapes.pushBack(&kBoxDesc);
    kActorDesc.body = &kBodyDesc;
    kActorDesc.density = fDensity;
    efd::Point3 kPos = vfunc_18();
    kActorDesc.globalPose.t = NxVec3(kPos.x, kPos.y, kPos.z);
    kActorDesc.globalPose.t = kActorDesc.globalPose.t * 0.01f;
    kActorDesc.globalPose.t.z += kBoxDesc.dimensions.z + 0.05f;
    kActorDesc.globalPose.M.rotZ((vfunc_20().z * 3.1415927f) / 180.0f);
    FUN_1409f7ca0()->FUN_14168a540(0);
    m_pD60 = pScene->createActor(kActorDesc);
    if (m_pD60 != NULL)
        m_pD60->setName("CNpc::MakeDeadPhysXActor");
    FUN_1409f7ca0()->FUN_14168a570();
    FUN_141097b40(6);
    CString strAnim = m_spNpcData->m_dead.GetRandomDefaultAction();
    if (0.0f < fPushUp) {
        CString strUp = m_spNpcData->m_dead.GetRandomUpAction();
        if (!strUp.IsEmpty()) {
            egf::EntityID kId;
            efd::SmartPointer<NiActorManager> spManager = FUN_140999440(FUN_141b6f910(), FUN_14123c460(kId));
            if (spManager != 0) {
                if (spManager->FindSequenceID((const char*)strUp) != (NiActorManager::SequenceID)0xfffffffe)
                    strAnim = strUp;
            }
        }
    }
    m_strED0 = strAnim;
}

// Releases the dead body's PhysX actor.
// @0x1410979a0
void CNpc::FUN_1410979a0()
{
    if (m_pD60 != NULL) {
        NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
        if (pScene != NULL) {
            FUN_1409f7ca0()->FUN_14168a540(0);
            pScene->releaseActor(*m_pD60);
            FUN_1409f7ca0()->FUN_14168a570();
            m_pD60 = NULL;
        }
    }
}

// Moves the npc to its dead body's PhysX pose.
// @0x141097a30
void CNpc::FUN_141097a30()
{
    if (m_pD60 == NULL)
        return;
    NxMat34 kPose = m_pD60->getGlobalPose();
    efd::Point3 kPos(kPose.t.x, kPose.t.y, kPose.t.z);
    kPos *= 100.0f;
    kPos.z = kPos.z - m_spNpcData->m_collision.m_fHeight * 0.5f;
    GameObject::vfunc_19(kPos);
}

// Moves the dead body's shapes to a collision group.
// @0x141097b40
void CNpc::FUN_141097b40(unsigned short nGroup)
{
    if (m_nD84 == nGroup)
        return;
    if (m_pD60 == NULL)
        return;
    FUN_1409f7ca0()->FUN_14168a540(0);
    unsigned int nShapes = m_pD60->getNbShapes();
    NxShape* const* ppShapes = m_pD60->getShapes();
    for (unsigned int i = 0; i < nShapes; i++)
    {
        NxShape* pShape = ppShapes[i];
        pShape->setGroup(nGroup);
    }
    FUN_1409f7ca0()->FUN_14168a570();
}

// A hit: the hit numbers, buff triggers, the boss camera, the hit effect / colour / shake / sound, the knockback record
// (+0xd70 / +0xd80), the hit direction basis (+0xd88), the death (corpse actor, boss kill effects), the dps meter.
// MS2-FUNCTIONAL: written from the decompile
// @0x141097c40
void CNpc::vfunc_33(void* a, void* b)
{
    CDamageRecord* pRecord = static_cast<CDamageRecord*>(a);
    float fNow = (float)FUN_141473280(reinterpret_cast<CMainSystem*>(FUN_14086d260()));
    efd::Point3 kHitDir = *static_cast<efd::Point3*>(b);
    GameObject::vfunc_33(a, &kHitDir);
    FUN_141671c20(MS2Ptr<CDamageRecord>(pRecord));
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    int nOwnerRel = reinterpret_cast<Unk_PCWorld*>(FUN_1403ed2d0())->FUN_141bd19d0(pRecord->m_nOwnerId);
    bool bBoss = GetNpcData()->IsBoss();
    SkillAttackData* pAttack = pRecord->FUN_14175a8b0();
    if (pAttack != 0 && pAttack->m_damage.m_nInvokeEffectDisable == 0)
        m_unk_748.FUN_14096fb20(1);
    if (bBoss && nOwnerRel == 1) {
        if (FUN_1409478c0()->FUN_140af7e30() == 0x12) {
            CBossTargetCamera* pCamera = dynamic_cast<CBossTargetCamera*>(FUN_1409478c0()->FUN_140af2520());
            if (pCamera != NULL)
                pCamera->FUN_140a38550(FUN_14123c580());
        }
    }
    if (pRecord->FUN_14175ac30() < 0) {
        FUN_141098fb0(1);
        FUN_14166ccb0()->vfunc_6();
        if (nOwnerRel == 1) {
            FUN_141673f70(m_spNpcData->m_fDamagedColorScale, DAT_1439f6ff4, DAT_1439f6ff8);
            float fAmp = m_spNpcData->m_fDamagedVibrateAmp;
            if (pAttack != 0)
                fAmp = fAmp * pAttack->m_damage.m_fDamagedVibrateRatio;
            if (0.0f < m_spNpcData->m_fDamagedVibrateDuration && 0.0f < fAmp)
                m_vibrate.FUN_14108e2a0(fNow, fNow + m_spNpcData->m_fDamagedVibrateDuration, fAmp);
            if (bBoss)
                reinterpret_cast<MyPC*>(pPlayer)->FUN_14152e240(FUN_14123c580());
        }
        m_spSkillRow = pRecord->m_spLevel;
        m_nD80 = pRecord->FUN_14175a8b0()->m_nDirection;
        if (pPlayer != NULL && pRecord->m_nOwnerId != pPlayer->FUN_14123c580()) {
            Common::Constants::Value<float>* pVolume;
            if (nOwnerRel == 1 || nOwnerRel == 2)
                pVolume = &FUN_1401d3200()->VolumeNpcToMyPc;
            else
                pVolume = &FUN_1401d3200()->VolumeNpcToPc;
            float fVolume = pVolume->Read();
            NiPoint3 kPos = vfunc_18();
            reinterpret_cast<Unk_PCFxMgr*>(FUN_1403ed280())->FUN_1411a5580(pRecord->FUN_14175ad50(),
                m_spNpcData->m_nDefenceMaterial, nOwnerRel, kPos, fVolume);
        }
    }
    if (kHitDir != efd::Point3::ZERO) {
        efd::Point3 kRight = kHitDir.UnitCross(efd::Point3::UNIT_Z);
        efd::Point3 kForward = -kRight.UnitCross(efd::Point3::UNIT_Z);
        m_unkD88.SetCol(0, kRight);
        m_unkD88.SetCol(1, kForward);
        m_unkD88.SetCol(2, efd::Point3::UNIT_Z);
    } else {
        m_unkD88.MakeIdentity();
    }
    if (FUN_14166ce30() == 0 && FUN_141670a00(4) == 0) {
        MakeDeadPhysXActor();
        vfunc_125(1);
        if (nOwnerRel == 1) {
            if (bBoss)
                reinterpret_cast<Unk_PCFxMgr*>(FUN_1403ed280())->FUN_1411a5770(2, pPlayer);
        } else if (pPlayer != NULL && bBoss && pPlayer->FUN_14166ce30() == 0) {
            if (FUN_140f4a450() <= *Client::Constants::GetInstance()->BossKillSoundRange.Get()) {
                if (reinterpret_cast<MyPC*>(pPlayer)->FUN_14152e280(FUN_14123c580()) != 0)
                    reinterpret_cast<Unk_PCFxMgr*>(FUN_1403ed280())->FUN_1411a5770(1, pPlayer);
            }
        }
    }
    CDPSMeterSystem::GetInstance()->OnDamage(MS2Ptr<CDamageRecord>(pRecord));
    vfunc_113(pRecord);
}

// A DoT tick: the tick numbers, buff triggers, the boss camera, the buff's sound, the death, the dps meter.
// MS2-FUNCTIONAL: written from the decompile
// @0x141098390
void CNpc::vfunc_34(void* p)
{
    CDotDamageRecord* pRecord = static_cast<CDotDamageRecord*>(p);
    GameObject::vfunc_34(p);
    FUN_141672020(MS2Ptr<CDotDamageRecord>(pRecord));
    m_unk_748.FUN_14096fb20(0);
    int nOwnerRel = reinterpret_cast<Unk_PCWorld*>(FUN_1403ed2d0())->FUN_141bd19d0(pRecord->m_nOwnerId);
    bool bBoss = GetNpcData()->IsBoss();
    if (bBoss && nOwnerRel == 1) {
        if (FUN_1409478c0()->FUN_140af7e30() == 0x12) {
            CBossTargetCamera* pCamera = dynamic_cast<CBossTargetCamera*>(FUN_1409478c0()->FUN_140af2520());
            if (pCamera != NULL)
                pCamera->FUN_140a38550(FUN_14123c580());
        }
    }
    MS2Ptr<AdditionalCli> spBuff = m_unk_748.FUN_14096fc80(pRecord->m_nEffectLevel);
    if (!spBuff.IsNull()) {
        int nMaterial = spBuff->FUN_14096d810()->m_dotDamage.m_nSoundMaterial;
        if (nMaterial != 0) {
            Common::Constants::Value<float>* pVolume;
            if (nOwnerRel == 1 || nOwnerRel == 2)
                pVolume = &FUN_1401d3200()->VolumeNpcToMyPc;
            else
                pVolume = &FUN_1401d3200()->VolumeNpcToPc;
            float fVolume = pVolume->Read();
            NiPoint3 kPos = vfunc_18();
            reinterpret_cast<Unk_PCFxMgr*>(FUN_1403ed280())->FUN_1411a5580(nMaterial, m_spNpcData->m_nDefenceMaterial,
                nOwnerRel, kPos, fVolume);
        }
    }
    if (FUN_14166ce30() == 0 && FUN_141670a00(4) == 0) {
        vfunc_125(1);
        PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (nOwnerRel == 1) {
            if (pPlayer != NULL && GetNpcData()->IsBoss())
                reinterpret_cast<Unk_PCFxMgr*>(FUN_1403ed280())->FUN_1411a5770(2, pPlayer);
        } else if (pPlayer != NULL && GetNpcData()->IsBoss() && pPlayer->FUN_14166ce30() == 0) {
            if (FUN_140f4a450() <= *Client::Constants::GetInstance()->BossKillSoundRange.Get()) {
                if (reinterpret_cast<MyPC*>(pPlayer)->FUN_14152e280(FUN_14123c580()) != 0)
                    reinterpret_cast<Unk_PCFxMgr*>(FUN_1403ed280())->FUN_1411a5770(1, pPlayer);
            }
        }
    }
    CDPSMeterSystem::GetInstance()->OnDotDamage(MS2Ptr<CDotDamageRecord>(pRecord));
    vfunc_113(pRecord);
}

// A splash hit: like vfunc_33 without the shake / hit direction (the hit numbers as a normal hit for npcs with
// property tag 0x1d).
// MS2-FUNCTIONAL: written from the decompile
// @0x141098940
void CNpc::vfunc_35(void* p)
{
    CSplashDamageRecord* pRecord = static_cast<CSplashDamageRecord*>(p);
    GameObject::vfunc_35(p);
    if (m_spNpcData.get() != 0 && m_spNpcData->HasPropertyTag(0x1d))
        FUN_141671c20(MS2Ptr<CDamageRecord>(pRecord));
    else
        FUN_1416721d0(MS2Ptr<CSplashDamageRecord>(pRecord));
    int nOwnerRel = reinterpret_cast<Unk_PCWorld*>(FUN_1403ed2d0())->FUN_141bd19d0(pRecord->m_nOwnerId);
    SkillAttackData* pAttack = pRecord->FUN_14175a8b0();
    if (pAttack != 0 && pAttack->m_damage.m_nInvokeEffectDisable == 0)
        m_unk_748.FUN_14096fb20(1);
    bool bBoss = GetNpcData()->IsBoss();
    if (bBoss && nOwnerRel == 1) {
        if (FUN_1409478c0()->FUN_140af7e30() == 0x12) {
            CBossTargetCamera* pCamera = dynamic_cast<CBossTargetCamera*>(FUN_1409478c0()->FUN_140af2520());
            if (pCamera != NULL)
                pCamera->FUN_140a38550(FUN_14123c580());
        }
    }
    if (pRecord->FUN_14175ac30() < 0) {
        FUN_141098fb0(1);
        FUN_14166ccb0()->vfunc_6();
        Common::Constants::Value<float>* pVolume;
        if (nOwnerRel == 1 || nOwnerRel == 2)
            pVolume = &FUN_1401d3200()->VolumeNpcToMyPc;
        else
            pVolume = &FUN_1401d3200()->VolumeNpcToPc;
        float fVolume = pVolume->Read();
        NiPoint3 kPos = vfunc_18();
        reinterpret_cast<Unk_PCFxMgr*>(FUN_1403ed280())->FUN_1411a5580(pRecord->FUN_14175ad50(),
            m_spNpcData->m_nDefenceMaterial, nOwnerRel, kPos, fVolume);
        m_spSkillRow = pRecord->m_spLevel;
        m_nD80 = pRecord->FUN_14175a8b0()->m_nDirection;
    }
    if (FUN_14166ce30() == 0 && FUN_141670a00(4) == 0) {
        MakeDeadPhysXActor();
        vfunc_125(1);
        PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (nOwnerRel == 1) {
            if (pPlayer != NULL && GetNpcData()->IsBoss())
                reinterpret_cast<Unk_PCFxMgr*>(FUN_1403ed280())->FUN_1411a5770(2, pPlayer);
        } else if (pPlayer != NULL && GetNpcData()->IsBoss() && pPlayer->FUN_14166ce30() == 0) {
            if (FUN_140f4a450() <= *Client::Constants::GetInstance()->BossKillSoundRange.Get()) {
                if (reinterpret_cast<MyPC*>(pPlayer)->FUN_14152e280(FUN_14123c580()) != 0)
                    reinterpret_cast<Unk_PCFxMgr*>(FUN_1403ed280())->FUN_1411a5770(1, pPlayer);
            }
        }
    }
    CDPSMeterSystem::GetInstance()->OnSplashDamage(MS2Ptr<CSplashDamageRecord>(pRecord));
    vfunc_113(pRecord);
}

// Plays the dead (0) / damage (1) effect of the npc row.
// @0x141098fb0
void CNpc::FUN_141098fb0(int nKind)
{
    CString strEffect;
    if (nKind == 0)
        strEffect = m_spNpcData->m_strDeadEffect;
    else if (nKind == 1)
        strEffect = m_spNpcData->m_strDamageEffect;
    if (!strEffect.IsEmpty()) {
        NoticeMessage kQuery;
        kQuery.m_strName = strEffect;
        kQuery.m_nObject = GetNpcData()->IsBoss() ? 6 : 5;
        kQuery.SetActor(FUN_14123c580());
        reinterpret_cast<Unk_PoEffectSvc*>(FUN_1403ed280())->FUN_1411a4a00(kQuery);
    }
    if (nKind == 0 && m_nE54 > 0) {
        FUN_1411a6060(FUN_1403ed280(), m_nE54);
        m_nE54 = 0;
    }
}

// Turns toward the target yaw (+0x934) at the row's rotation speed.
// @0x141099170
void CNpc::FUN_141099170(float fTime)
{
    efd::Point3 kRot = vfunc_20();
    if (!(FUN_1409f7c90()->FUN_14109a9d0() == 0 || !FUN_14028d470(kRot.z, m_f934)))
        return;
    FUN_14166d8b0(FUN_14028d5b0(m_f934));
    float fDelta = FUN_14028d5b0(m_f934 - kRot.z);
    float fSpeed = FUN_14059d930(fDelta);
    fSpeed = fSpeed / 0.1f;
    if (m_spNpcData->m_fRotationSpeed < fSpeed)
        fSpeed = m_spNpcData->m_fRotationSpeed;
    fTime = FUN_14109ac70(fDelta) * fSpeed * fTime;
    if (FUN_14059d930(fTime) < FUN_14059d930(fDelta))
        kRot.z = kRot.z + fTime;
    else
        kRot.z = m_f934;
    kRot.z = FUN_14028d5b0(kRot.z);
    vfunc_21(kRot);
}

// The idle monologue balloon timer.
// @0x141099370
void CNpc::FUN_141099370(float fTime)
{
    if (FUN_1422b9ea0(FUN_1408e57f0()) == 0 && m_questState.m_state == 4) {
        MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = vfunc_85();
        if (spBalloon.IsNull())
            return;
        if (spBalloon->FUN_1418fb6b0())
            return;
        int nRandom = FUN_140a35ca0(FUN_140a36020(&FUN_1401d3200()->MonologueRandom));
        if (spBalloon->FUN_140f48d40() == 0) {
            m_nDE0 += FUN_14028d260(fTime);
            unsigned int nElapsed = m_nDE0;
            int nDelay = m_nDE4;
            if ((unsigned int)(FUN_140a35ca0(FUN_140a36020(&FUN_1401d3200()->MonologueInterval)) + nRandom) <= nElapsed + nDelay) {
                FUN_140967100()->FUN_141b20790(FUN_14123c580(), vfunc_116());
                FUN_141099580();
            }
        } else {
            m_nDE0 += FUN_14028d260(fTime);
            if ((unsigned int)FUN_140a35ca0(FUN_140a36020(&FUN_1401d3200()->MonologueShowTime)) <= (unsigned int)m_nDE0) {
                spBalloon->vfunc_3();
                FUN_141099580();
            }
        }
    }
}

// @0x141099580
void CNpc::FUN_141099580()
{
    m_nDE0 = 0;
    unsigned int nRandom = FUN_140a35ca0(FUN_140a36020(&FUN_1401d3200()->MonologueRandom));
    if (nRandom != 0) {
        int nObjectId = FUN_14123c580();
        Unk_Random kRandom(nObjectId * FUN_140768010(nRandom, 0));
        m_nDE4 = kRandom.FUN_1407684c0() % nRandom;
    }
}

// Sets the npc up from its table row: model, name, collision size, quest flag and the random-target effect.
// MS2-FUNCTIONAL: behaviour-equivalent (the exe keeps the name / ridee temporaries in other frame slots)
// @0x141090d60
int CNpc::vfunc_124(int nNpcId)
{
    m_posD40 = efd::Point3::ZERO;
    m_spNpcData = FUN_1406d6e90()->FUN_140a7cab0(nNpcId);
    if (m_spNpcData.IsNull())
        return 0;
    if (m_strED8.IsEmpty())
        FUN_141095190(m_spNpcData->m_model.m_strKfm);
    if (m_strED8.IsEmpty())
        return 0;
#ifdef __clang__
    // clang emits an unavailable MFC CopyChars import for operator+; call the exe's operator+.
    FUN_14123bb80(FUN_140298360("urn:gamebryo-animation:", m_strED8));
#else
    FUN_14123bb80("urn:gamebryo-animation:" + m_strED8);
#endif
    Unk_1401aa6a0 strName(m_spNpcData->GetId());
    if (!strName.IsEmpty() && FUN_140a7c8d0(m_spNpcData.operator->()))
        vfunc_76(CStringW(strName));
    FUN_141670d50(efd::Point2(m_spNpcData->m_capsule.m_fRadius, m_spNpcData->m_capsule.m_fHeight));
    vfunc_59(0, 0, 0, 0);
    m_fScaleAC = m_spNpcData->m_model.m_fScale;
    if (m_spNpcData->GetFriendly() != 0)
        m_cE40 = FUN_1407476c0()->FUN_14074e030(nNpcId);
    m_nEB8 = FUN_14109a710()->FUN_140764c90(this);
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != NULL) {
        efd::Point3 kPos = pPlayer->vfunc_18();
        efd::SmartPointer<Ridee> spRidee(pPlayer->FUN_1416764a0());
        if (spRidee != 0)
            kPos = spRidee->vfunc_18();
        FUN_14123daa0(kPos);
    }
    FUN_141099580();
    m_timerEE8.FUN_1408687f0();
    m_spF28.AssignRaw(new CRandomTargetEffect(this));
    return 1;
}

// Dies: the dead state, the dead effect / sound and the corpse collision box.
// MS2-FUNCTIONAL: behaviour-equivalent (one temporary less in the exe)
// @0x141091210
void CNpc::vfunc_125(int bShow)
{
    m_unk_15c = 1;
    FUN_141099ab0();
    bool bBoss = false;
    if (bShow == 0 && FUN_141092ff0())
        bBoss = true;
    vfunc_59(0xc, new StateDeadNPCData(bBoss), 0, 0);
    if (bShow != 0) {
        FUN_141098fb0(0);
        if (m_spNpcData.get() != 0)
            FUN_1411a4f40(FUN_1403ed280(), m_spNpcData->m_strSoundDead, vfunc_18());
    }
    if (GetNpcData()->GetCorpseHitAble() != 0) {
        const Unk_NpcCorpse& kCorpse = m_spNpcData->m_corpse;
        efd::Point3 kSize(m_spNpcData->m_corpse.m_shape.m_fWidth, m_spNpcData->m_corpse.m_shape.m_fDepth,
            m_spNpcData->m_corpse.m_shape.m_fHeight);
        efd::Point3 kOffset(0.0f, m_spNpcData->m_corpse.m_fAdded, 0.0f);
        FUN_141670fd0(kSize, kOffset);
        m_f16c = m_spNpcData->m_corpse.m_fOffsetNametag;
        MS2Ptr<Unk_PCBaseComp_a78> spTag = vfunc_82();
        if (spTag.get() != 0)
            spTag->FUN_141a5e540("Eff_Body");
    }
    if (FUN_141092ff0())
        FUN_1403ed2d0()->FUN_141bc7f10(FUN_14123c460());
    if (m_nEA8 != 0)
        FUN_141678f50();
    m_timerEE8.FUN_140868750(Client::Constants::GetInstance()->NameColorDeadDuration.Read());
}

// Places the collision boxes: the model-bound boxes at their named nodes, the free boxes at the actor, and the corpse
// attachment at the actor turned by the corpse rotation of the dead animation.
// MS2-FUNCTIONAL: the Point3/NiPoint3 temporaries are built in a different order
// @0x141095bd0
void CNpc::vfunc_50()
{
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != NULL) {
        for (unsigned i = 0; i < m_arrE68.GetCount(); i++) {
            MS2Ptr<CBoxCollision> spBox = m_arrE68[i];
            if (spBox.get() == 0)
                continue;
            NiAVObject* pNode = pRoot->GetObjectByName(NiFixedString((const char*)spBox->m_strName));
            if (pNode != NULL) {
                CBoxCollision* pBox = spBox.operator->();
                const NiMatrix3& kRot = FUN_141024c90(pNode);
                Unk_StreamPoint ptPos = *reinterpret_cast<const Unk_StreamPoint*>(&FUN_140947900(pNode));
                pBox->vfunc_2(ptPos, kRot, 1.0f);
            }
        }
    }
    for (unsigned i = 0; i < m_arrE88.GetCount(); i++) {
        MS2Ptr<CBoxCollision> spBox = m_arrE88[i];
        if (spBox.get() == 0)
            continue;
        CBoxCollision* pBox = spBox.operator->();
        float fScale = FUN_14123c260();
        efd::Point3 kDir = vfunc_20();
        efd::Point3 kPos = static_cast<const efd::Point3&>(vfunc_18()) + efd::Point3(0.0f, 0.0f, m_unk_108);
        pBox->vfunc_3(Unk_StreamPoint(kPos), Unk_StreamPoint(kDir), fScale);
    }
    if (FUN_14166ce30() != 0 && GetNpcData()->GetCorpseHitAble() != 0) {
        Unk_GoAttachment* pAttachment = vfunc_26();
        if (pAttachment != NULL && FUN_14166c930() == 0xc) {
            State* pState = FUN_14166ccb0();
            const CStringA& strAnim = *reinterpret_cast<const CStringA*>(reinterpret_cast<const char*>(pState) + 0x40);
            int nIndex = 0;
            if (strAnim == "Dead_A")
                nIndex = 0;
            else if (strAnim == "Dead_B")
                nIndex = 1;
            else if (strAnim == "Dead_C")
                nIndex = 2;
            int nCount = (int)m_spNpcData->m_corpse.m_aRotation.GetCount();
            if (nCount != 0) {
                if (nIndex >= nCount)
                    nIndex = nCount - 1;
                int nRot = m_spNpcData->m_corpse.m_aRotation[nIndex];
                efd::Point3 kDir = static_cast<const efd::Point3&>(vfunc_20()) + efd::Point3(0.0f, 0.0f, (float)nRot);
                efd::Point3 kPos = static_cast<const efd::Point3&>(vfunc_18()) + efd::Point3(0.0f, 0.0f, m_unk_108);
                pAttachment->vfunc_3(NiPoint3(kPos), NiPoint3(kDir), 1.0f);
            }
        }
    } else {
        GameObject::vfunc_50();
    }
}

// The attachment offset: toward the owner object when bound to one, else the npc's collision offset turned to its
// facing.
// MS2-FUNCTIONAL: the Point3 temporaries are built in a different order
// @0x141096340
void CNpc::vfunc_51(efd::Point3* pOffset)
{
    if (m_nF20 != 0) {
        PCBase* pTarget = reinterpret_cast<Unk_CscWorld*>(FUN_1403ed2d0())->FUN_141bd1200(m_nF20);
        if (pTarget != NULL) {
            efd::Point3 kSelf = vfunc_18();
            *pOffset = static_cast<const efd::Point3&>(pTarget->vfunc_18()) - kSelf;
            return;
        }
    }
    if (m_spNpcData->m_collision.m_nWidthOffset == 0 && m_spNpcData->m_collision.m_nDepthOffset == 0 &&
        m_spNpcData->m_collision.m_nHeightOffset == 0) {
        GameObject::vfunc_51(pOffset);
        return;
    }
    pOffset->x = (float)m_spNpcData->m_collision.m_nWidthOffset;
    pOffset->y = (float)m_spNpcData->m_collision.m_nDepthOffset;
    pOffset->z = (float)m_spNpcData->m_collision.m_nHeightOffset + m_unk_108;
    float fYaw = FUN_14123ce70(FUN_14123cc20());
    efd::Matrix3 kRot;
    kRot.MakeZRotation(fYaw + 3.1415927f);
    *pOffset = kRot * *pOffset;
}

// @0x1410965d0
void CNpc::vfunc_49()
{
    Unk_NpcShadowMgr* pMgr = FUN_140ae1c00();
    int nKind = FUN_141092ff0() ? 3 : 2;
    int nLodHi = pMgr->FUN_141376880(nKind);
    int nLodLo = pMgr->FUN_1413769d0(nKind);
    m_spShadow = NiNew CObjectShadow(this, nLodHi, nLodLo, m_spNpcData->m_fShadowScale, 1.0f);
    FUN_14123cb20(m_bUnkB8);
}

// The npc's stats from a packet.
// @0x1410909a0
void CNpc::vfunc_90(void* p)
{
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    if (pPacket->ReadUInt8() == 1) {
        unsigned char nStat = pPacket->ReadUInt8();
        for (int i = 0; i < 3; i++) {
            __int64 nValue;
            if (FUN_14082f1a0(nStat) == 0)
                nValue = (unsigned int)pPacket->ReadInt32();
            else
                nValue = pPacket->ReadInt64();
            FUN_141670540(i, nStat, nValue);
        }
    } else {
        for (int i = 0; i < 3; i++) {
            FUN_141670540(i, 4, pPacket->ReadInt64());
            FUN_141670540(i, 0xd, pPacket->ReadInt32());
        }
    }
}

// Preloads an npc's skills and effects.
// @0x1410917a0
void FUN_1410917a0(unsigned int nNpcId)
{
    MS2Ptr<CNpcData> spData = FUN_1406cd330(nNpcId);
    if (spData.get() != 0) {
        for (unsigned __int64 i = 0; i < spData->m_skill.GetCount(); i++) {
            std::pair<unsigned int, unsigned short> kSkill = spData->m_skill.GetSkill(i);
            FUN_140aae720(FUN_1401958b0(), kSkill.first, kSkill.second, 4);
        }
        reinterpret_cast<Unk_PCBaseFxLibView*>(FUN_140a50010()->FUN_1411bf1e0())->FUN_1411be510(spData->GetId(), "");
    }
}

// Creates the npc's body actor (+0xd68): a box of the npc's collision size standing on its position, turned to its
// facing, for npcs with property tag 0x13 and a "box" shape.
// MS2-FUNCTIONAL: the PhysX descriptor temporaries live in different stack slots
// @0x141099640
void CNpc::NxTerrainPhsyx()
{
    if (m_pD68 != NULL)
        return;
    if (!GetNpcData()->HasPropertyTag(0x13))
        return;
    if (m_spNpcData->m_collision.m_strShape != "box")
        return;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    if (pScene == NULL)
        return;
    NxVec3 kUnused;
    Unk_StreamPoint ptSelf(vfunc_18());
    kUnused = FUN_140ae1df0(&ptSelf);
    NxBoxShapeDesc kBoxDesc;
    kBoxDesc.dimensions.set(m_spNpcData->m_collision.m_fWidth, m_spNpcData->m_collision.m_fDepth,
        m_spNpcData->m_collision.m_fHeight);
    kBoxDesc.dimensions = kBoxDesc.dimensions * 0.01f * 0.5f;
    kBoxDesc.groupsMask.bits0 = 0xffffffff;
    kBoxDesc.shapeFlags &= ~0x120000;
    NxActorDesc kActorDesc;
    kActorDesc.shapes.pushBack(&kBoxDesc);
    efd::Point3 kPos = vfunc_18();
    kActorDesc.globalPose.t = NxVec3(kPos.x, kPos.y, kPos.z);
    kActorDesc.globalPose.t = kActorDesc.globalPose.t * 0.01f;
    kActorDesc.globalPose.t.z += kBoxDesc.dimensions.z;
    kActorDesc.globalPose.M.rotZ((vfunc_20().z * 3.1415927f) / 180.0f);
    FUN_1409f7ca0()->FUN_14168a540(0);
    m_pD68 = pScene->createActor(kActorDesc);
    if (m_pD68 != NULL) {
        m_pD68->setName("CNpc::NxTerrainPhsyx");
        unsigned int nShapes = m_pD68->getNbShapes();
        NxShape* const* ppShapes = m_pD68->getShapes();
        for (unsigned int i = 0; i < nShapes; i++)
            ppShapes[i]->setGroup(0);
    }
    FUN_1409f7ca0()->FUN_14168a570();
}

// Releases the npc's body actor (+0xd68).
// @0x141099ab0
void CNpc::FUN_141099ab0()
{
    if (m_pD68 != NULL) {
        NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
        if (pScene != NULL) {
            FUN_1409f7ca0()->FUN_14168a540(0);
            pScene->releaseActor(*m_pD68);
            FUN_1403ed2d0()->FUN_141bc8e00();
            FUN_1409f7ca0()->FUN_14168a570();
            m_pD68 = NULL;
        }
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent (frame layout of the temporaries differs)
// @0x1410952f0
void CNpc::vfunc_53(float fTime)
{
    PCBase::vfunc_53(fTime);
    float fNow = (float)FUN_141473280(reinterpret_cast<CMainSystem*>(FUN_14086d260()));
    if (FUN_141092ff0() && m_unk_15c == 0 && m_spNpcData.get() != 0) {
        if (m_spNpcData->m_fBossSoundDistance < m_unk_c4) {
            if (m_spNpcData->m_fBossSoundEndDistance <= m_unk_c4)
                FUN_1403ed2d0()->FUN_141bc7fe0(FUN_14123c460());
        } else {
            FUN_1403ed2d0()->FUN_141bc7d40(FUN_14123c460());
        }
    }
    if (m_pD60 == NULL) {
        if (!reinterpret_cast<Unk_ArcMoverView*>(&m_unkDB0)->FUN_14160c1c0()) {
            vfunc_19(vfunc_18() + m_posD40 * fTime);
        } else {
            efd::Point3 kPos;
            float fYaw = FUN_14166da40();
            reinterpret_cast<Unk_ArcMoverView*>(&m_unkDB0)->FUN_14160bf90(fTime, kPos, &fYaw);
            vfunc_19(kPos);
            FUN_14166d8b0(fYaw);
        }
    }
    FUN_141099170(fTime);
    FUN_141097a30();
    FUN_141099370(fTime);
    if (m_cE40 != 0 && 1000 < (unsigned int)(FUN_140869420() - m_nE14)) {
        m_nE14 = FUN_140869420();
        m_nE10 = 1;
    }
    if (m_nE10 != 0)
        FUN_141093c80();
    if (m_spA78.get() == 0) {
        if (reinterpret_cast<char&>(FUN_1401d3200()->m_unk8) != 0) {
            if ((m_spA78 = FUN_141a60da0(m_unk_70)).get() != 0) {
                m_spA78->FUN_141a5e4c0(GetNpcData()->GetUnknown12());
                m_spA78->FUN_141a5e500(FUN_140a7c970(GetNpcData().operator->()));
                m_spA78->vfunc_2();
            }
        }
    } else if (vfunc_116() != 2) {
        PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != NULL) {
            if (vfunc_122(pPlayer) == 0) {
                unsigned int nColor = FUN_140a7d630(&Client::Constants::GetInstance()->NameTagColorFriendly);
                if (EE_DYNAMIC_CAST(CPet, this) != NULL) {
                    PC* pOwner = static_cast<PC*>(FUN_141094f60());
                    if (pOwner != NULL) {
                        MS2Ptr<CItem> spItem = pOwner->FUN_141663450();
                        if (FUN_14052cd70(&spItem) != NULL && FUN_14052cd70(&spItem) != NULL)
                            nColor = FUN_1405569f0(FUN_140281980(), ((CItem*)spItem)->FUN_140526bd0());
                    }
                }
                m_spA78->FUN_141a5e500(nColor);
            } else {
                Unk_NameTagView* pTag = static_cast<Unk_NameTagView*>(m_spA78.operator->());
                if (m_timerEE8.FUN_140868c00() != 0 && pTag->FUN_141a5e690() != 0) {
                    static_cast<Unk_NameTagView*>(m_spA78.operator->())->FUN_140f48dc0(0);
                    m_timerEE8.FUN_1408687f0();
                } else if (FUN_14166ce30() == 0) {
                    m_spA78->FUN_141a5e500(FUN_140a7c970(GetNpcData().operator->()));
                } else {
                    m_spA78->FUN_141a5e500(FUN_140a7d630(&Client::Constants::GetInstance()->NameTagColorDead));
                }
            }
        }
    }
    if (m_vibrate.IsActive() != 0) {
        efd::Point3 kPos = vfunc_18();
        m_vibrate.FUN_14108e300(fNow, kPos);
        if (m_unk_80 != NULL)
            static_cast<egf::Entity*>(m_unk_80)->SetPropertyValue<efd::Point3>(0xfd95ca52, kPos);
    }
    FUN_141093eb0();
    if (m_spF28.get() != 0)
        m_spF28->UpdatePosition();
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x14108e280, CNpcVibrate, IsActive, 14, 0xBA6447E3);
MS2_REPLACE_METHOD(0x14108e2a0, CNpcVibrate, FUN_14108e2a0, 84, 0xA436AECD);
MS2_REPLACE_METHOD(0x14108e300, CNpcVibrate, FUN_14108e300, 277, 0xC450E9F6);
MS2_REPLACE_METHOD(0x14108f710, CNpc, vfunc_12, 997, 0x8D05F8E6);
MS2_REPLACE_METHOD(0x14108fb00, CNpc, vfunc_14, 160, 0x34B1B2A3);
MS2_REPLACE_METHOD(0x14108fbb0, CNpc, vfunc_45, 36, 0x08D9B0FF);
MS2_REPLACE_METHOD(0x14108fbe0, CNpc, vfunc_46, 34, 0xB9AE0A23);
MS2_REPLACE_METHOD(0x14108fc10, CNpc, vfunc_47, 81, 0x4433FDF5);
MS2_REPLACE_METHOD(0x14108fc70, CNpc, vfunc_27, 43, 0x918D017B);
MS2_REPLACE_METHOD(0x14108fcb0, CNpc, vfunc_28, 43, 0xC885DE6A);
MS2_REPLACE_METHOD(0x14108fcf0, CNpc, vfunc_58, 106, 0x87EA4118);
MS2_REPLACE_METHOD(0x14108fd60, CNpc, vfunc_70, 27, 0x6F2695DD);
MS2_REPLACE_METHOD(0x14108fd90, CNpc, vfunc_64, 36, 0x31F5C0FB);
MS2_REPLACE_METHOD(0x14108fdc0, CNpc, vfunc_78, 69, 0x5BE0B2C9);
MS2_REPLACE_METHOD(0x14108fe10, CNpc, vfunc_79, 108, 0x30CFE54B);
MS2_REPLACE_METHOD(0x1410905c0, CNpc, vfunc_123, 88, 0xA9741235);
MS2_REPLACE_METHOD(0x141090620, CNpc, vfunc_111, 273, 0x6CFBD455);
MS2_REPLACE_METHOD(0x141090740, CNpc, vfunc_112, 205, 0x9B1B4B55);
MS2_REPLACE_METHOD(0x141090820, CNpc, vfunc_113, 34, 0x9D7D93EF);
MS2_REPLACE_METHOD(0x141090850, CNpc, vfunc_115, 240, 0x58B2EA27);
MS2_REPLACE_METHOD(0x141090950, CNpc, vfunc_98, 67, 0x88B0A27C);
MS2_REPLACE_METHOD(0x141090ba0, CNpc, vfunc_116, 41, 0xAB31C0EC);
MS2_REPLACE_METHOD(0x141090cd0, CNpc, vfunc_32, 127, 0x66546BAB);

