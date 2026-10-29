// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\interactobject.cpp
// MS2-RANGE: 0x1400f5200-0x1400f5230 .text$di
// MS2-RANGE: 0x1413fd240-0x1414043e0 .text$mn
// MS2-RANGE: 0x142cb1720-0x142cb1740 .text$yd
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@UUnk_InteractReqItem@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@UUnk_InteractReqItem@@@std@@@0@AEAV10@@Z 0x141403920
// MS2-PIN: ?begin@?$vector@UUnk_InteractReqItem@@V?$allocator@UUnk_InteractReqItem@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_InteractReqItem@@@std@@@std@@@2@XZ 0x1414040e0
// MS2-PIN: ?end@?$vector@UUnk_InteractReqItem@@V?$allocator@UUnk_InteractReqItem@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_InteractReqItem@@@std@@@std@@@2@XZ 0x1414041a0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCInteractTelescopeObject@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141404140
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\interactobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <io.h>
#include <string>
#include "interactobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "notifychangebuff.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/masterytable.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/gfxui/uiswfentity.h"
#include "physxhelper.h"
#include <efd/AssetID.h>
#include <efd/Point3.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <NiTexture.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cwinhttpclient.h"

// MS2-FUNCTIONAL: unit-wide; the bodies lean on many unrecovered services (world, effect, ranking, url and quest managers) that are
// declared as FUN_<va> externs with approximated signatures, and on out-of-line COMDATs of other objs, so only the trivial
// virtuals and the smart-pointer / iterator COMDATs are expected to be byte-identical.

// ---- the unit's header static (.text$di 0x1400f5200, atexit thunk 0x142cb1720): the sound name played when a telescope is used ----
#ifndef MS2_HOOK_DLL
static CString s_strUseTelescope("PC_use_telescope");       // 0x143ad97b8
#else
extern CString s_strUseTelescope;
#endif

// ---- exe callees (unit-local stand-ins) ----
// @0x141404030
static bool FUN_141404030(CInteractObjectData::ConditionEffectList& reqItem)
{
    if (reqItem.m_aItem.empty())
        return false;
    return true;
}
class Unk_IoPlayerBase
{
public:
    virtual void vf00() = 0; virtual void vf01() = 0; virtual void vf02() = 0; virtual void vf03() = 0;
    virtual void vf04() = 0; virtual void vf05() = 0; virtual void vf06() = 0; virtual void vf07() = 0;
    virtual void vf08() = 0; virtual void vf09() = 0; virtual void vf10() = 0; virtual void vf11() = 0;
    virtual void vf12() = 0; virtual void vf13() = 0; virtual void vf14() = 0; virtual void vf15() = 0;
    virtual void vf16() = 0; virtual void vf17() = 0;
    virtual Vector3 GetPosition() = 0;                      // 18
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
    virtual void vf25() = 0;
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    virtual void vf28() = 0;
    virtual void vf29() = 0;
    virtual void vf30() = 0;
    virtual void vf31() = 0;
    virtual void vf32() = 0;
    virtual void vf33() = 0;
    virtual void vf34() = 0;
    virtual void vf35() = 0;
    virtual void vf36() = 0;
    virtual void vf37() = 0;
    virtual void vf38() = 0;
    virtual void vf39() = 0;
    virtual void vf40() = 0;
    virtual void vf41() = 0;
    virtual void vf42() = 0;
    virtual void vf43() = 0;
    virtual void vf44() = 0;
    virtual void vf45() = 0;
    virtual void vf46() = 0;
    virtual void vf47() = 0;
    virtual void vf48() = 0;
    virtual void vf49() = 0;
    virtual void vf50() = 0;
    virtual void vf51() = 0;
    virtual void vf52() = 0;
    virtual void vf53() = 0;
    virtual void vf54() = 0;
    virtual void vf55() = 0;
    virtual void vf56() = 0;
    virtual void vf57() = 0;
    virtual void vf58() = 0;
    virtual void SendState(int nKind, void* pData, int nMsg, int nZero) = 0;   // 59
};
class Unk_IoInvView { public: int FUN_140970020(unsigned nItemId, unsigned short nRarity, int a, int b); };
#include "ms2/placeholder/chomeprivilege.h"
class Unk_IoHomeInfo : public CPtred {};                    // the player's home info held by MyPC (0x140967420)
class Unk_IoPlayer : public Unk_IoPlayerBase
{
public:
    MS2Ptr<CHomePrivilege> FUN_140967010();                 // MyPC::FUN_140967010
    MS2Ptr<Unk_IoHomeInfo> FUN_140967420();                 // MyPC::FUN_140967420
    int FUN_1416627d0(int nItemId);                         // number of items of that id
    unsigned FUN_141662750(int nItemId);                    // level of the item
    Unk_IoInvView* FUN_1416749a0();                         // equip / inventory view
    int FUN_14123c580();
    Unk_Entity* FUN_141529900();
    Vector3 FUN_1416767d0();                // position
};
struct Unk_IoCutData
{
    char m_pad_000[0x1fd];
    unsigned char m_b1fd;
    char m_pad_1fe[2];
    int m_n200;
    float m_n204;
    float m_n208;
    unsigned char m_b20c;
    char m_pad_20d[3];
    unsigned m_n210;
    float m_n214;
    float m_n218;
    float m_n21c;
};
struct Unk_IoCutRef
{
    ~Unk_IoCutRef() { FUN_1408850f0(); }
    void* m_pad_00;
    Unk_IoCutData* m_p;
    Unk_IoCutData* FUN_1409657a0() const;
    Unk_IoCutData* FUN_140885340() const;
    void FUN_1408850f0();
};
struct Unk_IoRanking
{
    int m_nRank;                // +0x00
    int m_pad_04;
    int m_nScore;               // +0x08
    char m_pad_0c[0x14];
    unsigned __int64 m_u20;     // +0x20 guild serial
    char m_pad_28[8];
    unsigned __int64 m_u30;     // +0x30 character serial
    CStringW m_str38;           // +0x38 character name
    char m_pad_40[8];
    CStringW m_str48;           // +0x48 guild name
    char m_pad_50[0x28];
    CStringW m_str78;           // +0x78 image key
};
MS2_CHECK_SIZE(Unk_IoRanking, 0x80);
class Unk_IoRankPtr
{
public:
    Unk_IoRankPtr() : m_pad(0), m_p(0) {}
    Unk_IoRankPtr(const Unk_IoRankPtr& o) : m_pad(0), m_p(0) { *this = o; }
    ~Unk_IoRankPtr();                                           // 0x140b2da40
    Unk_IoRankPtr& operator=(const Unk_IoRankPtr& o);           // 0x141403ae0
    bool operator==(Unk_IoRanking* p) const;                    // 0x141403b50
    void FUN_140b312e0();                                       // add a reference
    void FUN_140b31640();                                       // release the reference
    void FUN_140b2da40();                                       // drop the pointer
    Unk_IoRanking* FUN_140b2e1e0() const;                       // the ranking entry
    int FUN_140efcde0() const;                                  // holds an entry
    void* m_pad;
    Unk_IoRanking* m_p;
};
// @0x141403ae0
inline Unk_IoRankPtr& Unk_IoRankPtr::operator=(const Unk_IoRankPtr& o)
{
    const_cast<Unk_IoRankPtr&>(o).FUN_140b312e0();
    FUN_140b31640();
    m_p = o.m_p;
    return *this;
}
// @0x141403b50
inline bool Unk_IoRankPtr::operator==(Unk_IoRanking* p) const { return m_p == p; }
class Unk_IoWorld
{
public:
    Unk_IoPlayer* FUN_141bd0cc0();
    unsigned FUN_141bd3060();
    Unk_IoCutRef FUN_141bd30a0();
    void FUN_141bc8e00();
    void FUN_141bdb030(CString strKey, CStringW strUrl);
    void FUN_141bdb0f0(CString strKey, Unk_IoRankPtr spRank);
};
Unk_IoWorld* FUN_1403ed2d0();
class Unk_IoFxMgr
{
public:
    int FUN_1411a49c0(NoticeMessage* pRequest);
    void FUN_1411a6060(int nHandle);
};
Unk_IoFxMgr* FUN_1403ed280();
class Unk_IoQuestEval
{
public:
    virtual void vf00() = 0; virtual void vf01() = 0; virtual void vf02() = 0; virtual void vf03() = 0;
    virtual void vf04() = 0; virtual void vf05() = 0; virtual void vf06() = 0; virtual void vf07() = 0;
    virtual void vf08() = 0; virtual void vf09() = 0; virtual void vf10() = 0; virtual void vf11() = 0;
    virtual void vf12() = 0; virtual void vf13() = 0; virtual void vf14() = 0; virtual void vf15() = 0;
    virtual void vf16() = 0; virtual void vf17() = 0; virtual void vf18() = 0; virtual void vf19() = 0;
    virtual void vf20() = 0; virtual void vf21() = 0; virtual void vf22() = 0;
    virtual int CheckMask(const QuestMask* pMask) = 0;          // 23
};
struct Unk_IoQuestMgr
{
    char m_pad_00[0x10];
    void* m_pEvalVptr;
};
Unk_IoQuestMgr* FUN_140764020();
extern QuestMask DAT_143aacd50;                                 // empty mask

class Unk_IoSession
{
public:
    unsigned char FUN_14036d570(int n);
    bool FUN_14036e4c0();
};
class Unk_IoMapRules { public: unsigned char FUN_1407d05e0(unsigned nMapId, int nBanType); };
class Unk_IoGameCtx { public: Unk_IoMapRules* FUN_1403f3230(); };
void* FUN_140302b00();
Unk_IoMapRules* FUN_1403f3230(void* pCtx);
void FUN_141275260(int, int, int);
void FUN_141276180(const CString&, const CString&);
Unk_IoSession* FUN_140166410();
class Unk_IoCfg { public: int FUN_1402c4c90(int n); };
struct Unk_IoCfgHolder { char m_pad_00[8]; Unk_IoCfg m_cfg; };
Unk_IoCfgHolder* FUN_14025e7b0();
void* FUN_140cc18a0();
void FUN_141b794e0(void* pSvc, CString& strOut, const char* szUrl);   // resolve the url macros (exe: this, out, url)
MS2Ptr<CInteractObjectData> FUN_14051f670(int nId);
class Unk_IoHintSvc { public: CStringW FUN_141811980(int nKind, int nId); };
Unk_IoHintSvc* FUN_1401a9d70();
CPhysXHelper* FUN_1409f7ca0();

// item inventory
class Unk_IoInventory { public: MS2Ptr<CItem> FUN_140a5e5c0(int nItemId, int nRarity); };
extern Unk_IoInventory DAT_143ab2a90;
int FUN_14053feb0(int nItemId);

// condition helpers
struct Unk_IoRefOwner;
int FUN_140743710(Unk_IoHomeInfo* p);

// entity and property access
int FUN_1409618c0(Unk_Entity* e, unsigned nHash, Vector3* pOut);
int FUN_1408a2020(Unk_Entity* e, unsigned nHash, int* pOut);
int FUN_1408a20a0(Unk_Entity* e, unsigned nHash, bool* pOut);
int FUN_140961880(Unk_Entity* e, unsigned nHash, float* pOut);   // float property
struct Unk_IoColour   // efd::Color-like rgb (no ctor; non-POD so it is not a /GS buffer)
{
    Unk_IoColour& operator=(const Unk_IoColour&);
    float x, y, z;
};
int FUN_140b27ec0(Unk_Entity* e, unsigned nHash, Unk_IoColour* pOut);
int FUN_1408a2060(Unk_Entity* e, unsigned nHash, efd::utf8string* pOut);
int FUN_140998250(Unk_Entity* e, unsigned nHash, efd::AssetID* pOut);
void FUN_14098c6e0(Unk_Entity* e, unsigned nHash, unsigned char* pValue);
void FUN_140de8bd0(Unk_Entity* e, unsigned nHash, efd::AssetID* pValue);
const egf::EntityID* FUN_1408b76f0(Unk_Entity* e);
egf::EntityID* FUN_1408b6b20(egf::EntityID* pDst, const egf::EntityID* pSrc);
void FUN_1401cd100(egf::EntityID* pDst, int n);
unsigned __int64 FUN_140affe40(Unk_Entity* e);
egf::FlatModel* FUN_1408a9bd0(Unk_Entity* e);
CString FUN_141b70dd0(Unk_Entity* e);
void FUN_1401d3700(CString* p);
void FUN_141b71e70(egf::EntityID id, bool bEnable, unsigned uColor, bool bSkipEffectRoot);    // util.cpp
const char* FUN_1408ac310(efd::utf8string* p);
const char* FUN_14099ad40(efd::AssetID* p);
void FUN_1409989e0(efd::utf8string* p, const char* psz);
void FUN_140de0cb0(efd::AssetID* pDst, efd::utf8string* pStr);
void FUN_1408a8900(efd::utf8string* p);
class Unk_IoSoundMgr { public: bool FUN_1409a1fc0(const egf::EntityID& id, const efd::utf8string& strName, float fVol, bool bLoop); };
Unk_IoSoundMgr* FUN_141b6f910();

// physics prop object of a mesh interact object
// efd::MemHint, passed by value to the MemObject operator new
struct Unk_IoMemHint
{
    Unk_IoMemHint(int nCat);                                    // 0x140876480
    int m_nBits;
};
// egfPhysX::EntityActorData (a MemObject); the owner is a by-value SmartPointer<Entity> that the ctor releases
class Unk_PhysPropObj
{
public:
    Unk_PhysPropObj(Unk_EntRef owner);                          // 0x14225f250
    static void* operator new(size_t cb, Unk_IoMemHint hint);   // 0x14208a860 efd::MemObject::operator new
    static void operator delete(void* p, Unk_IoMemHint hint);   // 0x14097f700 efd::MemObject::operator delete
    void* m_pad[0x98 / 8];
};
// A model name as a real efd::utf8string temporary (ctor 0x1409989e0, dtor 0x1408a8900).
class Unk_IoModelName
{
public:
    Unk_IoModelName(const char* psz);
    ~Unk_IoModelName();
    alignas(8) char m_pad[0x20];    // a char buffer: a /GS buffer, as the exe's utf8string temporaries are
};
struct Unk_IoFlatModel
{
    bool FUN_14211e1f0(const Unk_IoModelName& name) const;   // egf::FlatModel::ContainsModel(const efd::utf8string&)
};


// notices
class Unk_IoNotices
{
public:
    void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify);
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> dlg);
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> dlg);
};
Unk_IoNotices* FUN_140939a10();

// highlight manager
class Unk_IoHighlight { public: void FUN_1414f11d0(Unk_Entity* e); void FUN_1414f1240(Unk_Entity* e); };
Unk_IoHighlight* FUN_140ad4ba0();

// post effect / system sound / ui
class Unk_IoPostFx
{
public:
    void FUN_1409a4450(unsigned char bOn, float a, float b, unsigned nColor);          // exe: xmm2/xmm3
    void FUN_1409a46a0(unsigned char bOn, unsigned* pColor, float a, float b, float c);   // exe: xmm3 + 2 stack floats
};
Unk_IoPostFx* FUN_1409a8b00();
Unk_IoPostFx* FUN_1409a8b10();
unsigned char* FUN_140a58500(Unk_IoPostFx* p);
class Unk_IoCamLock { public: void FUN_141863460(float fFade); };
Unk_IoCamLock* FUN_140ad4b90();
void* FUN_1408e57f0();
void FUN_1422b9fd0(void* pSound, unsigned nId);
void FUN_1406c4340(float* pDst, float a, float b, float c);
class Unk_IoHelp { public: void FUN_141907f80(int n, CStringW str); void FUN_141907d60(int n, CStringW a, CStringW b); };
Unk_IoHelp* FUN_14136f290(int nId);
CStringW GetStringCommon(int nStringId);
CStringW GetStringCommonByKey(const CStringW& str);
struct Unk_IoGuideTable { CStringW FUN_14142d760(int nId, int n); };   // member (this=rcx, hidden return=rdx)
Unk_IoGuideTable* FUN_1409331f0();
class Unk_IoUiMgr { public: void FUN_141adc530(int n); int FUN_141adc940(int n); void FUN_141adc5d0(int n); };
Unk_IoUiMgr* FUN_1403ed2b0();
class Unk_IoUiCreator { public: MS2Ptr<UISwfEntity> FUN_1422d41b0(const CString& strName); };
Unk_IoUiCreator* FUN_140b632f0();
UISwfEntity* FUN_140b634c0(const MS2Ptr<UISwfEntity>& sp);
unsigned FUN_140869420();

// gathering and tables
void FUN_140e59bb0(void* p, CInteractObject* pObject);
void* FUN_14122d430(int nId);
class Unk_IoGatherChk { public: int FUN_140b6d330(int nId); int FUN_140b6d470(int nId); };
Unk_IoGatherChk* FUN_140e5ca20();
class Unk_IoGatherCount { public: void FUN_140450290(int nId, int* pOut); void FUN_140458df0(int nId, int nValue); };
extern Unk_IoGatherCount DAT_143ab3150;
class Unk_IoCursorMgr { public: int FUN_1404240e0(int n); CStringW FUN_140424150(); };
Unk_IoCursorMgr* FUN_1403ef660(void* p);
class Unk_IoBoardSvc;
Unk_IoBoardSvc* FUN_140d271c0(int nId);
__int64 FUN_140c322b0(Unk_IoBoardSvc* p);
class Unk_IoStream
{
public:
    virtual void vf0(); virtual void vf1();
    virtual unsigned short ReadShort(); // 2
    virtual int ReadInt();              // 3
};
struct Unk_InteractMsg
{
    void* m_pad_00;
    Unk_IoStream m_stream;          // +0x08
};

// state interact data sent to the world
class Unk_IoStateData : public CPtred
{
public:
    Unk_IoStateData();              // 0x1417d0be0 (StateInteractData ctor)
    int m_nId;                      // +0x18
    int m_pad_1c;
    CString m_strName;              // +0x20
    char m_pad_28[8];
    int m_nFlag;                    // +0x30
    int m_pad_34;
};
MS2_CHECK_SIZE(Unk_IoStateData, 0x38);
struct Unk_IoStateSp
{
    Unk_IoStateSp(Unk_IoStateData* pData);  // 0x140964220
    ~Unk_IoStateSp();                       // 0x140964bc0
    void* m_pad;
    Unk_IoStateData* m_p;
};
Unk_IoStateData* FUN_1409659d0(Unk_IoStateSp* p);
void* FUN_140965870(Unk_IoStateSp* p);

// ================================================================================================================
// CInteractObject
// ================================================================================================================

// @0x1413fd240
CInteractObject::CInteractObject()
    : m_ent(0)
    , m_strName()
    , m_nState(0)
    , m_nShownState(3)
{
    m_spRow = 0;
    m_ent = 0;
    m_nEffect = 0;
    m_nRowId = 0;
    m_nParticle = 0;
    m_nVisible = 0;
    m_bHighlight = 1;
    m_timer.FUN_1408687f0();
    m_bSpawned = 0;
}

// @0x1413fd380
CInteractObject::~CInteractObject()
{
    FUN_1413fdc50();
    if (m_nParticle != 0)
        FUN_1403ed280()->FUN_1411a6060(m_nParticle);
    m_spRow = 0;
    m_ent = 0;
}

// @0x1413fd460
int CInteractObject::vfunc_1(Unk_Entity* pEntity, int nState)
{
    if (pEntity == 0)
        return 0;
    m_ent.FUN_1408b6ec0(pEntity);
    FUN_1409618c0(pEntity, 0xfd95ca52, &m_vPos);
    FUN_1409618c0(pEntity, 0x68c7c29d, &m_vRot);
    FUN_1408a2020(pEntity, 0xd460e9bc, &m_nRowId);
    m_spRow = FUN_14051f670(m_nRowId);
    if (!m_spRow)
        return 0;
    m_strName = FUN_141b70dd0(pEntity);
    FUN_1401d3700(&m_strName);
    if (m_strName.GetLength() == 0)
        return 0;
    vfunc_3(nState);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyAddInteract(this)));
    return 1;
}

// @0x1413fd6b0
void CInteractObject::vfunc_2(Unk_InteractMsg*)
{
}

// @0x1413fd6d0
void CInteractObject::vfunc_3(int nState)
{
    if (m_ent.FUN_1408b70b0(0))
        return;
    if (m_spRow == 0)
        return;
    m_nState = nState;
    FUN_1413fe500();
}

// @0x1413fd740
int CInteractObject::vfunc_4()
{
    if (m_nState != 1)
        return 0;
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow == 0)
        return 0;
    unsigned nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    if (FUN_1403f3230(FUN_140302b00())->FUN_1407d05e0(nMapId, m_spRow->m_nId) == 1)
    {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    if (!FUN_1413fe040())
        return 0;
    if (!FUN_1413fe120())
        return 0;
    if (!FUN_1413fe220())
        return 0;
    if (!FUN_1413fdfc0())
        return 0;
    if (!FUN_1413fde40())
        return 0;
    if (!FUN_1413fdd80())
        return 0;
    return 1;
}

// @0x1413fd890
Unk_EntRef CInteractObject::GetEnt()
{
    return m_ent;
}

// @0x1413fd8e0
egf::EntityID CInteractObject::FUN_1413fd8e0()
{
    if (m_ent.FUN_1408b70b0(0))
        return egf::EntityID(0);
    return *FUN_1408b76f0(m_ent.FUN_1408a9280());
}

// @0x1413fd960
unsigned __int64 CInteractObject::FUN_1413fd960()
{
    if (m_ent.FUN_1408b70b0(0))
        return 0;
    return FUN_140affe40(m_ent.FUN_1408a9280());
}

// @0x1413fd9b0
void CInteractObject::vfunc_6(Unk_InteractCursor* pOut)
{
    pOut->m_strHint = FUN_1401a9d70()->FUN_141811980(0xb, GetRowId());
    pOut->m_nCursor = m_spRow->m_nReactTime;
}

// @0x1413fda50
void CInteractObject::FUN_1413fda50()
{
    if (m_nShownState == m_nState)
        return;
    FUN_1413fdc50();
    CString strAsset = vfunc_13();
    if (strAsset.GetLength() != 0)
    {
        NiTransform xf;
        xf.m_Translate = reinterpret_cast<const efd::Point3&>(m_vPos) + efd::Point3(0.0f, 0.0f, 1.0f);
        xf.m_Rotate.FromEulerAnglesXYZ((m_vRot.x * 3.1415927f) / 180.0f, (m_vRot.y * 3.1415927f) / 180.0f,
                                       (m_vRot.z * 3.1415927f) / 180.0f);
        xf.m_fScale = 1.0f;
        NoticeMessage request;
        request.m_strName = strAsset;
        request.m_nObject = 0;
        request.m_p18 = &xf;
        m_nEffect = FUN_1403ed280()->FUN_1411a49c0(&request);
        m_nShownState = m_nState;
    }
}

// @0x1413fdc50
void CInteractObject::FUN_1413fdc50()
{
    if (m_nEffect != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
        m_nShownState = 3;
    }
}

// @0x1413fdca0
void CInteractObject::FUN_1413fdca0(unsigned char bVisible)
{
    if (m_ent.FUN_1408a9090() == 0)
        return;
    m_nVisible = bVisible;
    if (bVisible != 0)
        FUN_141b71e70(*FUN_1408b76f0(m_ent.FUN_1408a9280()), true, 1, false);
    else
        FUN_141b71e70(*FUN_1408b76f0(m_ent.FUN_1408a9280()), false, 1, false);
}

// @0x1413fdd80
int CInteractObject::FUN_1413fdd80()
{
    if (!m_spRow)
        return 0;
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow->m_mastery.m_eType != 0)
    {
        int nItemId = m_spRow->m_mastery.m_eType;
        int nNeed = m_spRow->m_mastery.m_nValue;
        if (pPlayer->FUN_1416627d0(nItemId) < nNeed)
            return 0;
    }
    return 1;
}

// @0x1413fde40
int CInteractObject::FUN_1413fde40()
{
    if (!m_spRow)
        return 0;
    if (m_spRow->m_item.m_nCode != 0)
    {
        int nRarity = m_spRow->m_item.m_nRank;
        if (nRarity == 0)
            nRarity = FUN_14053feb0(m_spRow->m_item.m_nCode);
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e5c0(m_spRow->m_item.m_nCode, nRarity);
        if (!spItem)
            return 0;
        if ((unsigned)((CItem*)spItem)->FUN_140526c50() < m_spRow->m_item.m_nConsume)
            return 0;
        if (((CItem*)spItem)->FUN_140526bd0() != nRarity)
            return 0;
    }
    return 1;
}

// @0x1413fdfc0
int CInteractObject::FUN_1413fdfc0()
{
    if (m_spRow == 0)
        return 0;
    Unk_IoQuestEval* pEval = reinterpret_cast<Unk_IoQuestEval*>(&FUN_140764020()->m_pEvalVptr);
    return pEval->CheckMask(&m_spRow->m_maskUse);
}

// @0x1413fe040
int CInteractObject::FUN_1413fe040()
{
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow == 0)
        return 0;
    if (m_spRow->m_homePrivilege.m_nCheck == 0)
        return 1;
    return pPlayer->FUN_140967010()->FUN_14050d890(GetRowId());
}

// @0x1413fe120
int CInteractObject::FUN_1413fe120()
{
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow == 0)
        return 0;
    int nNeed = m_spRow->m_arena.m_nCanInteractTeamId;
    if (nNeed == 0)
        return 1;
    bool bSame = FUN_140743710(pPlayer->FUN_140967420().operator->()) == nNeed;
    if (bSame)
        return 1;
    return 0;
}

// @0x1413fe220
int CInteractObject::FUN_1413fe220()
{
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow == 0)
        return 0;
    if (!FUN_141404030(m_spRow->m_aReqItem))
        return 1;
    std::vector<Unk_InteractReqItem>& aReq = m_spRow->m_aReqItem.m_aItem;
    std::vector<Unk_InteractReqItem>::const_iterator itEnd = aReq.end();
    for (std::vector<Unk_InteractReqItem>::const_iterator it = aReq.begin(); it != itEnd; ++it)
    {
        Unk_InteractReqItem req = Unk_InteractReqItem(*it);
        if (pPlayer->FUN_1416749a0()->FUN_140970020(req.first, req.second, 0, 1) == 1)
            return 1;
    }
    return 0;
}

// @0x1413fe370
void CInteractObject::vfunc_8()
{
    if (vfunc_4() != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::InteractObject), 0);
        packet.WriteUInt8(0xb);
        packet.WriteInt32(1);
        packet.WriteString(GetName());
        FUN_140710590(packet);
    }
}

// @0x1413fe430
void CInteractObject::vfunc_9()
{
}

// @0x1413fe440
void CInteractObject::vfunc_10()
{
    if (vfunc_4() != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::InteractObject), 0);
        packet.WriteUInt8(0xc);
        packet.WriteInt32(1);
        packet.WriteString(GetName());
        FUN_140710590(packet);
    }
}

// @0x1413fe500
void CInteractObject::FUN_1413fe500()
{
    if (FUN_1413fdfc0() == 0 ||
        reinterpret_cast<Unk_IoQuestEval*>(&FUN_140764020()->m_pEvalVptr)->CheckMask(FUN_1413fe8a0()) == 0)
        FUN_1413fdc50();
    else
        FUN_1413fda50();
}

// @0x1413fe580
void CInteractObject::vfunc_11()
{
    if (m_timer.FUN_140868c00() != 0)
    {
        m_timer.FUN_1408687f0();
        FUN_1413fe9a0(0);
    }
}

// @0x1413fe5d0
void CInteractObject::vfunc_12()
{
    if (m_spRow->m_effect.m_strSuccess.GetLength() != 0)
    {
        NiTransform xf;
        xf.m_Translate = reinterpret_cast<const efd::Point3&>(m_vPos) + efd::Point3(0.0f, 0.0f, 1.0f);
        xf.m_Rotate.FromEulerAnglesXYZ((m_vRot.x * 3.1415927f) / 180.0f, (m_vRot.y * 3.1415927f) / 180.0f,
                                       (m_vRot.z * 3.1415927f) / 180.0f);
        xf.m_fScale = 1.0f;
        NoticeMessage request;
        request.m_strName = m_spRow->m_effect.m_strSuccess;
        request.m_nObject = 1;
        request.m_p18 = &xf;
        Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
            request.SetActor(pPlayer->FUN_14123c580());
        m_nParticle = FUN_1403ed280()->FUN_1411a49c0(&request);
    }
}

// @0x1413fe7d0
CString CInteractObject::vfunc_13()
{
    switch (m_nState)
    {
    case 0:
        return m_spRow->m_effect.m_strNormal;
    case 1:
        return m_spRow->m_effect.m_strReactable;
    }
    return CString();
}

// @0x1413fe8a0
QuestMask* CInteractObject::FUN_1413fe8a0()
{
    switch (m_nState)
    {
    case 0:
        return &m_spRow->m_effect.m_maskNormal;
    case 1:
        return &m_spRow->m_effect.m_maskReactable;
    }
    return &DAT_143aacd50;
}

// @0x1413fe910
void CInteractObject::FUN_1413fe910()
{
    if (m_bHighlight != 0)
        return;
    if (m_ent.FUN_1408b70b0(0))
        return;
    if (vfunc_5() == 8)
        return;
    FUN_140ad4ba0()->FUN_1414f11d0(m_ent.FUN_1408a9090());
    m_bHighlight = 1;
}

// @0x1413fe9a0
void CInteractObject::FUN_1413fe9a0(int nDelay)
{
    if (m_bHighlight == 0)
        return;
    if (m_ent.FUN_1408b70b0(0))
        return;
    if (vfunc_5() == 8)
        return;
    bool bFlag = false;
    if (FUN_1408a20a0(m_ent.FUN_1408a9280(), 0x2e0ec6f3, &bFlag) == 0 && bFlag)
        return;
    if (nDelay != 0)
    {
        m_timer.FUN_140868750(nDelay);
    }
    else
    {
        FUN_140ad4ba0()->FUN_1414f1240(m_ent.FUN_1408a9090());
        m_bHighlight = 0;
    }
}

// ================================================================================================================
// CInteractMeshObject
// ================================================================================================================

// @0x1413fea90
CInteractMeshObject::CInteractMeshObject()
    : m_spProp(0)
    , m_strAssetA()
    , m_strAssetB()
{
    m_pActor = 0;
    m_spProp.FUN_140ae17e0(0);
}

// @0x1413feb40
CInteractMeshObject::~CInteractMeshObject()
{
    FUN_1413ff5f0();
    m_pActor = 0;
    m_spProp.FUN_140ae17e0(0);
}

// @0x1413febf0
int CInteractMeshObject::vfunc_1(Unk_Entity* pEntity, int nState)
{
    m_spProp.FUN_140ae17e0(new (Unk_IoMemHint(0)) Unk_PhysPropObj(pEntity));
    if (((Unk_IoFlatModel*)FUN_1408a9bd0(pEntity))->FUN_14211e1f0("MS2InteractMesh"))
    {
        efd::AssetID idA;
        efd::AssetID idB;
        FUN_140998250(pEntity, 0x770e5fc6, &idA);
        FUN_140998250(pEntity, 0xae1cf70e, &idB);
        m_strAssetA = FUN_14099ad40(&idA);
        m_strAssetB = FUN_14099ad40(&idB);
        m_nAssetType = 1;
    }
    else if (((Unk_IoFlatModel*)FUN_1408a9bd0(pEntity))->FUN_14211e1f0("MS2InteractActor"))
    {
        efd::utf8string strA;
        efd::utf8string strB;
        FUN_1408a2060(pEntity, 0x3ff293c8, &strA);
        FUN_1408a2060(pEntity, 0x63c7b14a, &strB);
        m_strAssetA = FUN_1408ac310(&strA);
        m_strAssetB = FUN_1408ac310(&strB);
        m_nAssetType = 2;
    }
    else
        return 0;
    return CInteractObject::vfunc_1(pEntity, nState);
}

// @0x1413fef20
void CInteractMeshObject::vfunc_3(int nState)
{
    CInteractObject::vfunc_3(nState);
    if (m_spRow == 0)
        return;
    if (m_ent.FUN_1408b70b0(0))
        return;
    if (m_nState == 0)
    {
        FUN_1413fe910();
        FUN_1413fe9a0(5000);
    }
    else if (m_nState == 1)
    {
        FUN_1413fe910();
        FUN_1413fe9a0(5000);
    }
    else
    {
        FUN_1413fe9a0(0);
    }
    if (m_nState == 2)
    {
        unsigned char bFlag = 0;
        FUN_14098c6e0(m_ent.FUN_1408a9280(), 0xa0b6b179, &bFlag);
        return;
    }
    unsigned char bFlag = 1;
    FUN_14098c6e0(m_ent.FUN_1408a9280(), 0xa0b6b179, &bFlag);
    unsigned bFirst = m_nState == 0;
    CString* pAsset = bFirst != 0 ? &m_strAssetA : &m_strAssetB;
    FUN_1413ff690(*pAsset);
    int nCollision;
    if (bFirst != 0)
        nCollision = m_spRow->m_mesh.m_nNormalCollision;
    else
        nCollision = m_spRow->m_mesh.m_nReactableCollision;
    FUN_1413ff800(nCollision);
}

// @0x1413ff0f0
int CInteractMeshObject::vfunc_4()
{
    return CInteractObject::vfunc_4();
}

// @0x1413ff110
void CInteractMeshObject::vfunc_8()
{
    CInteractObject::vfunc_8();
    FUN_1413ff840();
}

// @0x1413ff140
void CInteractMeshObject::vfunc_9()
{
    CInteractObject::vfunc_9();
    FUN_1413ff8a0();
}

void FUN_140ae1df0(const Vector3& src, NxVec3& dst);   // copy a Vector3 into an NxVec3

// @0x1413ff170
void CInteractMeshObject::MakeNxBoxController()
{
    if (m_pActor != 0)
        return;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    if (pScene == 0)
        return;
    NxVec3 ptPos;
    FUN_140ae1df0(m_vPos, ptPos);
    NxBoxShapeDesc box;
    box.dimensions.set(m_spRow->m_mesh.m_shapeDimension.x, m_spRow->m_mesh.m_shapeDimension.y, m_spRow->m_mesh.m_shapeDimension.z);
    box.dimensions = box.dimensions * 0.01f * 0.5f;
    box.groupsMask.bits0 = 0xffffffff;
    box.shapeFlags &= 0xffedffff;
    NxActorDesc actorDesc;
    actorDesc.body = NULL;
    actorDesc.shapes.pushBack(&box);
    Vector3 vPos = m_vPos;
    actorDesc.globalPose.t = NxVec3(vPos.x, vPos.y, vPos.z);
    actorDesc.globalPose.t = actorDesc.globalPose.t * 0.01f;
    actorDesc.globalPose.t.z += box.dimensions.z;
    actorDesc.globalPose.M.rotZ((m_vRot.z * 3.1415927f) / 180.0f);
    NxVec3 vSet(m_vPos.x, m_vPos.y, m_vPos.z);
    vSet = vSet * 0.01f;
    vSet.z += m_spRow->m_mesh.m_shapeDimension.z * 0.01f * 0.5f;
    FUN_1409f7ca0()->FUN_14168a540(0);
    m_pActor = pScene->createActor(actorDesc);
    if (m_pActor != 0)
    {
        m_pActor->setName("CInteractMeshObject::MakeNxBoxController");
        NxU32 nShapes = m_pActor->getNbShapes();
        NxShape* const* ppShapes = m_pActor->getShapes();
        for (NxU32 i = 0; i < nShapes; ++i)
        {
            NxShape* pShape = ppShapes[i];
            pShape->setGroup(0);   // exe: NxShape slot 2 [rax+0x10] with edx=0, not setFlag
        }
        m_pActor->userData = m_spProp.FUN_140ae1920();
        m_pActor->setGlobalPosition(vSet);
    }
    FUN_1409f7ca0()->FUN_14168a570();
}

// @0x1413ff5f0
void CInteractMeshObject::FUN_1413ff5f0()
{
    if (m_pActor != 0)
    {
        NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
        if (pScene != 0)
        {
            FUN_1409f7ca0()->FUN_14168a540(0);
            pScene->releaseActor(*m_pActor);
            FUN_1403ed2d0()->FUN_141bc8e00();
            FUN_1409f7ca0()->FUN_14168a570();
            m_pActor = 0;
        }
    }
}

// @0x1413ff690
void CInteractMeshObject::FUN_1413ff690(const CString& strAsset)
{
    if (m_nAssetType == 1)
    {
        efd::AssetID id;
        id.SetURN((const char*)strAsset);
        FUN_140de8bd0(m_ent.FUN_1408a9280(), 0x770e5fc6, &id);
    }
    else if (m_nAssetType == 2)
    {
        efd::utf8string str(strAsset);
        FUN_141b6f910()->FUN_1409a1fc0(*FUN_1408b76f0(m_ent.FUN_1408a9280()), str, 1.0f, false);
    }
}

// @0x1413ff800
void CInteractMeshObject::FUN_1413ff800(int nCollision)
{
    if (nCollision != 0)
        MakeNxBoxController();
    else
        FUN_1413ff5f0();
}

// @0x1413ff840
void CInteractMeshObject::FUN_1413ff840()
{
    if (m_spRow->m_mesh.m_strReactObjectAni.GetLength() > 0)
        FUN_1413ff690(m_spRow->m_mesh.m_strReactObjectAni);
}

// @0x1413ff8a0
void CInteractMeshObject::FUN_1413ff8a0()
{
    FUN_1413ff690(m_strAssetB);
}

// ================================================================================================================
// CInteractTelescopeObject
// ================================================================================================================

// @0x1413ff8d0
CInteractTelescopeObject::CInteractTelescopeObject()
{
    m_bActive = 0;
}

// @0x1413ff920
CInteractTelescopeObject::~CInteractTelescopeObject()
{
    if (m_bActive != 0)
        OnCutSceneSkip(0);
}

// @0x1413ff980
void CInteractTelescopeObject::vfunc_2(Unk_InteractMsg* pMsg)
{
    CInteractObject::vfunc_2(pMsg);
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    m_ent.FUN_1408b6ec0(pPlayer->FUN_141529900());
    if (m_ent.FUN_1408a9090() != 0)
    {
        m_bActive = 1;
        FUN_141276180(s_strUseTelescope, "");
        FUN_1422b9fd0(FUN_1408e57f0(), 0x6200041);
        CStringW strDesc;
        Unk_IoHelp* pHelp = FUN_14136f290(0x4e52);
        if (pHelp != 0)
        {
            CStringW strTitle = GetStringCommon(0x666);
            if (*FUN_140a58500(FUN_1409a8b10()) != 0)
                strTitle = FUN_1409331f0()->FUN_14142d760(0x49409, 2);
            pHelp->FUN_141907f80(9, strDesc);
            pHelp->FUN_141907d60(3, strTitle, GetStringCommon(0x667));
            FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyCutSceneCinematicSkip"),
                                           Delegate<void(NotifyObject*)>(this, &CInteractTelescopeObject::OnCutSceneSkip));
        }
        Unk_IoColour colA;
        Unk_IoColour colB;
        FUN_1406c4340(&colA.x, 0.0f, 0.0f, 0.0f);
        FUN_1406c4340(&colB.x, 0.0f, 0.0f, 0.0f);
        bool bFilter;
        bool bColor;
        float nFilterA, nFilterB, nColA, nColB, nColC;
        FUN_1408a20a0(m_ent.FUN_1408a9280(), 0x4c87bc48, &bFilter);
        FUN_140b27ec0(m_ent.FUN_1408a9280(), 0x22a89b35, &colA);
        FUN_140961880(m_ent.FUN_1408a9280(), 0x65832be6, &nFilterA);
        FUN_140961880(m_ent.FUN_1408a9280(), 0xf8696656, &nFilterB);
        unsigned nFilterColor = ((int)(colA.x * 255.0f) & 0xffU) << 16 | 0xff000000 | ((int)(colA.y * 255.0f) & 0xffU) << 8 |
                                ((int)(colA.z * 255.0f) & 0xffU);
        FUN_1408a20a0(m_ent.FUN_1408a9280(), 0x554eb57d, &bColor);
        FUN_140b27ec0(m_ent.FUN_1408a9280(), 0x85eb5e6b, &colB);
        FUN_140961880(m_ent.FUN_1408a9280(), 0x2c1b71fe, &nColA);
        FUN_140961880(m_ent.FUN_1408a9280(), 0xc55896f7, &nColB);
        FUN_140961880(m_ent.FUN_1408a9280(), 0xc9603b18, &nColC);
        unsigned nColor = ((int)(colB.x * 255.0f) & 0xffU) << 16 | 0xff000000 | ((int)(colB.y * 255.0f) & 0xffU) << 8 |
                          ((int)(colB.z * 255.0f) & 0xffU);
        FUN_1409a8b00()->FUN_1409a4450(bFilter, nFilterA, nFilterB, nFilterColor);
        FUN_1409a8b00()->FUN_1409a46a0(bColor, &nColor, nColA, nColB, nColC);
    }
}

// @0x1413fff60
void CInteractTelescopeObject::OnCutSceneSkip(NotifyObject*)
{
    FUN_140ad4b90()->FUN_141863460(0.0f);
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
    Unk_IoCutRef ref = FUN_1403ed2d0()->FUN_141bd30a0();
    if (ref.FUN_1409657a0() != 0)
    {
        FUN_1409a8b00()->FUN_1409a4450(ref.FUN_140885340()->m_b1fd, ref.FUN_140885340()->m_n204, ref.FUN_140885340()->m_n208,
                                       ref.FUN_140885340()->m_n200);
        FUN_1409a8b00()->FUN_1409a46a0(ref.FUN_140885340()->m_b20c, &ref.FUN_140885340()->m_n210, ref.FUN_140885340()->m_n214,
                                       ref.FUN_140885340()->m_n218, ref.FUN_140885340()->m_n21c);
    }
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyCutSceneCinematicSkip"),
                                   Delegate<void(NotifyObject*)>(this, &CInteractTelescopeObject::OnCutSceneSkip));
    m_bActive = 0;
}

// ================================================================================================================
// CInteractUIObject
// ================================================================================================================

// @0x1414001e0
CInteractUIObject::CInteractUIObject()
{
    m_nDialogId = 0;
}

// @0x141400230
CInteractUIObject::~CInteractUIObject()
{
}

// @0x141400260
void CInteractUIObject::vfunc_2(Unk_InteractMsg* pMsg)
{
    CInteractObject::vfunc_2(pMsg);
    UIDialog* pDialog = dynamic_cast<UIDialog*>(FUN_140b634c0(FUN_140b632f0()->FUN_1422d41b0(m_spRow->m_ui.m_strSwf)));
    if (pDialog != 0)
    {
        if (m_spRow->m_ui.m_strValue.GetLength() != 0)
            pDialog->FUN_1419265e0(m_spRow->m_ui.m_strValue);
        FUN_1403ed2b0()->FUN_141adc530(pDialog->vfunc_48());
        m_nDialogId = pDialog->vfunc_48();
    }
}

// @0x1414003c0
void CInteractUIObject::vfunc_11()
{
    CInteractObject::vfunc_11();
    if (m_nDialogId == 0)
        return;
    if (FUN_1403ed2b0()->FUN_141adc940(m_nDialogId) != 0)
    {
        m_nDialogId = 0;
        return;
    }
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
    {
        FUN_1403ed2b0()->FUN_141adc5d0(m_nDialogId);
        return;
    }
    float fRange = GetRow()->m_validate.m_fInteractionDistance;
    if (pPlayer->FUN_1416767d0().FUN_140965c40(GetPos()).FUN_140967ac0() > fRange)
        FUN_1403ed2b0()->FUN_141adc5d0(m_nDialogId);
}

// ================================================================================================================
// CInteractDisplayImage
// ================================================================================================================

// @0x141400520
CInteractDisplayImage::CInteractDisplayImage()
    : m_strUrl()
    , m_strGuildName()
    , m_strCharName()
{
    m_pThread = 0;
    m_nGuildRank = 0;
    m_nGuildTrophy = 0;
    m_nGuildScore = 0;
    m_nCharTrophy = 0;
    m_nCharBuildPoint = 0;
    m_nCharScore = 0;
}

// @0x141400600
CInteractDisplayImage::~CInteractDisplayImage()
{
}

// @0x141400670
int CInteractDisplayImage::vfunc_1(Unk_Entity* pEntity, int nState)
{
    if (CInteractObject::vfunc_1(pEntity, nState) == 0)
        return 0;
    if (FUN_14025e7b0()->m_cfg.FUN_1402c4c90(0x32) == 0 && FUN_140166410()->FUN_14036d570(0x3f) == 1)
        m_pThread = AfxBeginThread(GetURLFromGameRanking, this, 0, 0, 0, 0);
    else if (FUN_140166410()->FUN_14036e4c0())
    {
        m_strUrl = "";
        FUN_141b794e0(FUN_140cc18a0(), m_strUrl, (const char*)m_spRow->m_displayUrl.m_strIndirectUrl);
        if (m_strUrl.GetLength() > 0)
            m_pThread = AfxBeginThread(GetURLFromIndirectURL, this, 0, 0, 0, 0);
    }
    return 1;
}

// ---- worker thread / url stand-ins ----
struct Unk_IoThreadScope { char m_buf[0x40]; };
void FUN_141b6de20();
void FUN_141b721f0(Unk_IoThreadScope* p, CString strName);
void FUN_141b722b0(Unk_IoThreadScope* p);
CStringW Unk_ArcWide(const wchar_t* sz, int n);              // 0x140efe330
// The scoped log line of util.cpp ("<tag> begin" / "<tag> end").
class Unk_UtilLogScope
{
public:
    Unk_UtilLogScope(CStringA kTag);                            // 0x141b721f0
    ~Unk_UtilLogScope();                                        // 0x141b722b0
private:
    DWORD m_dwThread;
    CStringA m_kTag;
};

// ---- ranking / xml / image stand-ins used by the display image ----
class TiXmlElement
{
public:
    TiXmlElement(const char* pszName);                                      // 0x14086f2f0
    ~TiXmlElement();                                                        // 0x14086f450
    void* m_buf[0x90 / 8];
};
typedef TiXmlElement Unk_IoXmlElem;
const char* FUN_1408782b0(Unk_IoXmlElem* p, const char* pszXml, void* pData, int nEncoding);   // Parse
CString FUN_14015f710(Unk_IoXmlElem* p, const char* pszName, CString strDefault);
CStringW FUN_1401bf530(Unk_IoXmlElem* p, const char* pszName, CStringW strDefault);
int FUN_140197350(Unk_IoXmlElem* p, const char* pszName, int nDefault);
int FUN_140873320(Unk_IoXmlElem* p, const char* pszName, unsigned __int64* pOut);
// @0x1414038e0
static unsigned __int64 FUN_1414038e0(Unk_IoXmlElem* p, const char* pszName, unsigned __int64 nDefault)
{
    unsigned __int64 nValue;
    if (FUN_140873320(p, pszName, &nValue) != 0)
        return nDefault;
    return nValue;
}
CString FUN_140390ea0(const wchar_t* psz, unsigned nCodePage);
CStringW FUN_14016a730(const char* psz, unsigned nCodePage);
CString FUN_14016a600(const wchar_t* psz, unsigned nCodePage);
CString FUN_141029590(unsigned __int64 nId, const CString& strKey, const CString& strName, CString strExtra);
CString FUN_141028be0(unsigned __int64 nId, const CString& strPortrait, int nFlag, CString strExtra);
CString FUN_1410299f0(unsigned __int64 nA, const CString& strB, int nId, const CString& strName, unsigned char bFlag);
class Unk_IoPosterSvc { public: CStringW FUN_1404d2220(int nId); };
unsigned __int64 FUN_1404ccbd0(Unk_IoPosterSvc* p);
struct Unk_IoPosterHolder { char m_pad_00[8]; Unk_IoPosterSvc m_svc; };
Unk_IoPosterHolder* FUN_1403ed290();

NiTexturePtr FUN_14186bd30(const CStringW& strPath, int nSize, bool bPng);   // LoadUgcTexture
class Unk_IoTexMgr
{
public:
    void FUN_141888770(Unk_EntRef ent, NiTexture* pTex);
    NiTexturePtr FUN_1418897a0();
    void FUN_141880230(CString strName, int nPosterId);
};
Unk_IoTexMgr* FUN_14052d220();
class Unk_IoPosterChk { public: bool FUN_140a25840(int n, CStringW str); };
Unk_IoPosterChk* FUN_1409c1730();

// ranking
struct Unk_IoRankKey { char m_buf[0x10]; };
struct Unk_IoRankParam { char m_pad_00[0x18]; Unk_IoRankKey m_key; char m_pad_28[0x20]; };
MS2_CHECK_SIZE(Unk_IoRankParam, 0x48);
Unk_IoRankParam* FUN_140b3dd70(Unk_IoRankParam* p);
void FUN_140b436f0(Unk_IoRankParam* p);
void FUN_140b356e0(Unk_IoRankKey* p);
void FUN_140b35780(Unk_IoRankKey* p);
void FUN_140b35820(Unk_IoRankKey* pDst, Unk_IoRankKey* pSrc);
class Unk_IoRankSvc
{
public:
    void FUN_140b2b870(Unk_IoRankKey* pKey, int nType, int a, int b, int c);
    void FUN_140b2b1e0(Unk_IoRankPtr* pOut, Unk_IoRankKey* pKey, int nIndex, int nFlag);
    void FUN_140b2bf30(Unk_IoRankParam* pParam);
};
Unk_IoRankSvc* FUN_140b2e980();

// @0x141400800
void CInteractDisplayImage::FUN_141400800(const CStringW& strName)
{
    MS2Ptr<CInteractObjectData> spRow = GetRow();
    if (spRow == 0)
        return;
    CString strKey = FUN_140390ea0(strName, 0);
    if (spRow->m_displayUrl.m_nType == 1 || m_spRow->m_displayUrl.m_nType == 3)
    {
        Unk_IoXmlElem elem("guild");
        const char* pEnd = FUN_1408782b0(&elem, strKey, 0, 1);
        if (pEnd == 0)
            return;
        CString strMark = FUN_14015f710(&elem, "mark", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strGuildName = FUN_1401bf530(&elem, "name", CStringW(L""));
        m_nGuildRank = FUN_140197350(&elem, "rank", 0);
        m_nGuildTrophy = FUN_140197350(&elem, "trophy", 0);
        m_nGuildScore = FUN_140197350(&elem, "score", 0);
        if (strMark.GetLength() < 1 || nSn < 1)
            return;
        CString strPath = FUN_141029590(nSn, strMark, GetName(), CString(""));
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
    }
    else if (spRow->m_displayUrl.m_nType == 2)
    {
        Unk_IoXmlElem elem("character");
        const char* pEnd = FUN_1408782b0(&elem, strKey, 0, 1);
        if (pEnd == 0)
            return;
        CString strPortrait = FUN_14015f710(&elem, "portrait", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strCharName = FUN_1401bf530(&elem, "name", CStringW(L""));
        m_nCharTrophy = FUN_140197350(&elem, "trophy", 0);
        m_nCharRank = FUN_140197350(&elem, "rank", 0);
        CString strPath = FUN_141028be0(nSn, strPortrait, 1, GetName());
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
    }
    else if (spRow->m_displayUrl.m_nType == 4)
    {
        Unk_IoXmlElem elem("character");
        const char* pEnd = FUN_1408782b0(&elem, strKey, 0, 1);
        if (pEnd == 0)
            return;
        CString strPortrait = FUN_14015f710(&elem, "portrait", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strCharName = FUN_1401bf530(&elem, "name", CStringW(L""));
        m_nCharBuildPoint = FUN_140197350(&elem, "build_point", 0);
        m_nCharRank = FUN_140197350(&elem, "rank", 0);
        CString strPath = FUN_141028be0(nSn, strPortrait, 1, GetName());
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
    }
    else if (spRow->m_displayUrl.m_nType == 5)
    {
        Unk_IoXmlElem elem("character");
        const char* pEnd = FUN_1408782b0(&elem, strKey, 0, 1);
        if (pEnd == 0)
            return;
        CString strPortrait = FUN_14015f710(&elem, "portrait", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strCharName = FUN_1401bf530(&elem, "name", CStringW(L""));
        m_nCharScore = FUN_140197350(&elem, "score", 0);
        m_nCharRank = FUN_140197350(&elem, "rank", 0);
        CString strPath = FUN_141028be0(nSn, strPortrait, 1, GetName());
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
    }
}

// @0x141401380
void CInteractDisplayImage::FUN_141401380(Unk_IoRankPtr spRank)
{
    MS2Ptr<CInteractObjectData> spRow = GetRow();
    if (spRow == 0)
        return;
    if (spRank == 0)
        return;
    CString strKey = FUN_14016a600(spRank.FUN_140b2e1e0()->m_str78, 0);
    unsigned __int64 nGuildSn = spRank.FUN_140b2e1e0()->m_u20;
    unsigned __int64 nCharSn = spRank.FUN_140b2e1e0()->m_u30;
    m_strGuildName = spRank.FUN_140b2e1e0()->m_str48;
    m_nGuildRank = spRank.FUN_140b2e1e0()->m_nRank;
    m_nGuildTrophy = spRank.FUN_140b2e1e0()->m_nScore;
    m_nGuildScore = spRank.FUN_140b2e1e0()->m_nScore;
    m_strCharName = spRank.FUN_140b2e1e0()->m_str38;
    m_nCharTrophy = spRank.FUN_140b2e1e0()->m_nScore;
    m_nCharRank = spRank.FUN_140b2e1e0()->m_nRank;
    m_nCharBuildPoint = spRank.FUN_140b2e1e0()->m_nScore;
    m_nCharScore = spRank.FUN_140b2e1e0()->m_nScore;
    CString strPath("");
    switch (spRow->m_displayUrl.m_nType)
    {
    case 1:
    case 3:
        strPath = FUN_141029590(nGuildSn, strKey, GetName(), CString(""));
        break;
    case 2:
    case 4:
    case 5:
        strPath = FUN_141028be0(nCharSn, strKey, 1, GetName());
        break;
    }
    if (strPath.GetLength() > 0)
        FUN_1414017b0(strPath);
}

// @0x1414017b0
void CInteractDisplayImage::FUN_1414017b0(const CString& strFile)
{
    CStringW strPath = FUN_14016a730(strFile, 0);
    if (m_ent.FUN_1408a9090() == 0)
        return;
    NiTexturePtr spTexA(0);
    if (_waccess(strPath, 0) == 0)
    {
        NiTexturePtr spTex = FUN_14186bd30(strPath, 0x100, false);
        if (spTex == 0)
            return;
        FUN_14052d220()->FUN_141888770(m_ent, spTex);
    }
}

// @0x141401920
UINT CInteractDisplayImage::GetURLFromIndirectURL(LPVOID pParam)
{
    FUN_141b6de20();
    Unk_UtilLogScope scope(CString("CInteractDisplayImage::GetURLFromIndirectURL"));
    CInteractDisplayImage* pThis = static_cast<CInteractDisplayImage*>(pParam);
    if (pThis == 0)
        return 0;
    CString strName = pThis->GetName();
    std::wstring strUrl(CStringW(FUN_14016a730(pThis->m_strUrl, 0)));
    CWinHttpClient client(strUrl);
    if (client.FUN_140920cf0(L"GET", false))
    {
        if (client.FUN_140922f20() != 0)
            return 0;
        std::wstring strBody = client.GetResponseContent();
        CStringW strResult = Unk_ArcWide(strBody.c_str(), 0);
        if (FUN_1403ed2d0() != 0)
            FUN_1403ed2d0()->FUN_141bdb030(CString(strName), CStringW(strResult));
    }
    return 0;
}

// @0x141401c20
UINT CInteractDisplayImage::GetURLFromGameRanking(LPVOID pParam)
{
    CInteractDisplayImage* pThis = static_cast<CInteractDisplayImage*>(pParam);
    FUN_141b6de20();
    Unk_IoThreadScope scope;
    FUN_141b721f0(&scope, CString("CInteractDisplayImage::GetURLFromGameRanking"));
    if (pThis == 0)
    {
        FUN_141b722b0(&scope);
        return 0;
    }
    CString strName = pThis->GetName();
    int nImageType = pThis->m_spRow->m_displayUrl.m_nType;
    int nRankType = 0;
    CString strUrl(pThis->m_spRow->m_displayUrl.m_strIndirectUrl);
    CString strTag("rank=");
    int nPos = strUrl.Find(strTag, 0);
    char chRank = pThis->m_spRow->m_displayUrl.m_strIndirectUrl.GetAt(nPos + strTag.GetLength());
    if (nImageType == 1)
        nRankType = 1;
    else if (nImageType == 2)
        nRankType = 2;
    else if (nImageType == 3)
        nRankType = 5;
    else if (nImageType == 4)
        nRankType = 6;
    else if (nImageType == 5)
        nRankType = 4;
    Unk_IoRankKey key;
    FUN_140b356e0(&key);
    FUN_140b2e980()->FUN_140b2b870(&key, nRankType, 0, 0, 0);
    Unk_IoRankPtr spRank;
    FUN_140b2e980()->FUN_140b2b1e0(&spRank, &key, chRank - '0', 1);
    if (spRank == 0)
    {
        Unk_IoRankParam param;
        FUN_140b3dd70(&param);
        FUN_140b35820(&param.m_key, &key);
        FUN_140b2e980()->FUN_140b2bf30(&param);
        int nTry = 0;
        do
        {
            if (4 < nTry)
                break;
            Sleep(1000);
            Unk_IoRankPtr spTemp;
            FUN_140b2e980()->FUN_140b2b1e0(&spTemp, &key, chRank - '0', 0);
            spRank = spTemp;
            ++nTry;
        } while (spRank.FUN_140efcde0() == 0);
        FUN_140b436f0(&param);
    }
    if (spRank.FUN_140efcde0() != 0 && FUN_1403ed2d0() != 0)
    {
        Unk_IoRankPtr spCopy(spRank);
        FUN_1403ed2d0()->FUN_141bdb0f0(CString(strName), spCopy);
    }
    FUN_140b35780(&key);
    FUN_141b722b0(&scope);
    return 0;
}

// @0x141402060
CStringW CInteractDisplayImage::FUN_141402060()
{
    if (m_spRow == 0)
        return CStringW();
    if (m_spRow->m_displayUrl.m_nType == 1 || m_spRow->m_displayUrl.m_nType == 3)
        return m_strGuildName;
    else if (m_spRow->m_displayUrl.m_nType == 2 || m_spRow->m_displayUrl.m_nType == 4 || m_spRow->m_displayUrl.m_nType == 5)
        return m_strCharName;
    return CStringW();
}

// @0x1414021c0
int CInteractDisplayImage::FUN_1414021c0()
{
    if (m_spRow == 0)
        return 0;
    if (m_spRow->m_displayUrl.m_nType == 1 || m_spRow->m_displayUrl.m_nType == 3)
        return m_nGuildRank;
    else if (m_spRow->m_displayUrl.m_nType == 2 || m_spRow->m_displayUrl.m_nType == 4 || m_spRow->m_displayUrl.m_nType == 5)
        return m_nCharRank;
    return 0;
}

// @0x1414022a0
int CInteractDisplayImage::FUN_1414022a0()
{
    if (m_spRow == 0)
        return 0;
    if (m_spRow->m_displayUrl.m_nType == 1)
        return m_nGuildTrophy;
    else if (m_spRow->m_displayUrl.m_nType == 2)
        return m_nCharTrophy;
    else if (m_spRow->m_displayUrl.m_nType == 3)
        return m_nGuildScore;
    else if (m_spRow->m_displayUrl.m_nType == 4)
        return m_nCharBuildPoint;
    else if (m_spRow->m_displayUrl.m_nType == 5)
        return m_nCharScore;
    return 0;
}

// ================================================================================================================
// CInteractGatheringObject
// ================================================================================================================

// @0x1414023b0
CInteractGatheringObject::CInteractGatheringObject()
{
    m_nRespawnTick = 0;
}

// @0x141402400
CInteractGatheringObject::~CInteractGatheringObject()
{
}

// @0x141402430
int CInteractGatheringObject::vfunc_1(Unk_Entity* pEntity, int nState)
{
    CInteractMeshObject::vfunc_1(pEntity, nState);
    void* pTable = FUN_14122d430(0x4f3a);
    if (pTable != 0)
        FUN_140e59bb0(pTable, this);
    return 1;
}

// @0x141402490
void CInteractGatheringObject::vfunc_2(Unk_InteractMsg* pMsg)
{
    CInteractMeshObject::vfunc_2(pMsg);
    int sType = (&pMsg->m_stream)->ReadShort();
    int nCount = (&pMsg->m_stream)->ReadInt();
    vfunc_3(0);
    m_nRespawnTick = FUN_140869420() + m_spRow->m_nResetTime;
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        Unk_IoStateSp spData(new Unk_IoStateData);
        FUN_1409659d0(&spData)->m_nId = GetRowId();
        FUN_1409659d0(&spData)->m_strName = GetName();
        FUN_1409659d0(&spData)->m_nFlag = 1;
        int nMsg;
        if (sType == 0)
            nMsg = 0x8b;
        else
            nMsg = 0x8c;
        pPlayer->SendState(0x19, FUN_140965870(&spData), nMsg, 0);
    }
    int nGatherId = m_spRow->m_gathering.m_nReceipeId;
    if (nGatherId != 0 && sType == 0)
    {
        int nHave = 0;
        DAT_143ab3150.FUN_140450290(nGatherId, &nHave);
        DAT_143ab3150.FUN_140458df0(nGatherId, nHave + nCount);
    }
}

// @0x141402750
void CInteractGatheringObject::vfunc_11()
{
    CInteractObject::vfunc_11();
    if (m_nRespawnTick != 0)
    {
        if ((unsigned)m_nRespawnTick <= FUN_140869420())
        {
            vfunc_3(1);
            m_nRespawnTick = 0;
        }
    }
}

// @0x1414027c0
void CInteractGatheringObject::vfunc_6(Unk_InteractCursor* pOut)
{
    CInteractObject::vfunc_6(pOut);
    pOut->m_nCursor = FUN_1403ef660(FUN_140302b00())->FUN_1404240e0(pOut->m_nCursor);
    pOut->m_strHint = GetStringCommonByKey(L"s_action_gathering");
    pOut->m_strHint += FUN_1403ef660(FUN_140302b00())->FUN_140424150();
}

// @0x1414028c0
CString CInteractGatheringObject::vfunc_13()
{
    if (FUN_141402c90() == 0)
        return CString("");
    return CInteractObject::vfunc_13();
}

// @0x141402940
int CInteractGatheringObject::vfunc_7()
{
    if (CInteractObject::vfunc_7() == 0)
        return 0;
    if (vfunc_15() != 0)
        return 0;
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow->m_gathering.m_nReceipeId != 0)
    {
        CMasteryTable::ReceipePtr spReceipe = CMasteryTable::GetInstance()->Find(m_spRow->m_gathering.m_nReceipeId);
        if (!spReceipe)
            return 0;
        if (pPlayer->FUN_141662750(spReceipe->m_nType) < spReceipe->m_nRequireMastery)
            return 0;
        if (FUN_140e5ca20()->FUN_140b6d330(m_spRow->m_gathering.m_nReceipeId) == 0)
            return 0;
    }
    return 1;
}

// @0x141402ad0
int CInteractGatheringObject::vfunc_16()
{
    if (FUN_141402c90() == 0)
        return 0;
    if (CMasteryTable::GetInstance()->LimitState(m_spRow->m_gathering.m_nReceipeId) == 3)
        return 0;
    return 1;
}

// @0x141402b40
int CInteractGatheringObject::FUN_141402b40()
{
    if (vfunc_15() != 0)
        return 0;
    if (m_spRow->m_gathering.m_nReceipeId != 0)
    {
        CMasteryTable::ReceipePtr spReceipe = CMasteryTable::GetInstance()->Find(m_spRow->m_gathering.m_nReceipeId);
        if (!spReceipe)
            return 0;
        if (FUN_140e5ca20()->FUN_140b6d330(m_spRow->m_gathering.m_nReceipeId) == 0)
            return 0;
    }
    return 1;
}

// @0x141402c50
int CInteractGatheringObject::FUN_141402c50()
{
    if (m_nRespawnTick != 0)
        return m_nRespawnTick - FUN_140869420();
    return 0;
}

// @0x141402c90
int CInteractGatheringObject::FUN_141402c90()
{
    return FUN_140e5ca20()->FUN_140b6d470(m_spRow->m_gathering.m_nReceipeId) == 0;
}

// ================================================================================================================
// CInteractGuildPosterObject
// ================================================================================================================

// @0x141402cf0
CInteractGuildPosterObject::CInteractGuildPosterObject()
{
}

// @0x141402d30
CInteractGuildPosterObject::~CInteractGuildPosterObject()
{
}

// @0x141402d60
int CInteractGuildPosterObject::vfunc_1(Unk_Entity* pEntity, int nState)
{
    if (CInteractObject::vfunc_1(pEntity, nState) == 0)
        return 0;
    if (FUN_140166410()->FUN_14036d570(0x5b) == 0)
        return 0;
    FUN_141402eb0(1);
    return 1;
}

// @0x141402dd0
void CInteractGuildPosterObject::vfunc_10()
{
    if (vfunc_4() == 0)
        return;
    FUN_14052d220()->FUN_141880230(GetName(), FUN_141402e60());
}

// @0x141402e60
int CInteractGuildPosterObject::FUN_141402e60()
{
    if (m_spRow == 0)
        return 0;
    return m_spRow->m_guild.m_nHousePosterId;
}

// @0x141402eb0
void CInteractGuildPosterObject::FUN_141402eb0(unsigned char bShow)
{
    if (m_ent.FUN_1408a9090() == 0)
        return;
    int nPoster = FUN_141402e60();
    unsigned __int64 nSvc = FUN_1404ccbd0(&FUN_1403ed290()->m_svc);
    CStringW strRaw = FUN_1403ed290()->m_svc.FUN_1404d2220(nPoster);
    CStringW strFile = FUN_14016a730(FUN_1410299f0(nSvc, FUN_14016a600(strRaw, 0), nPoster, GetName(), bShow), 0);
    if (FUN_1409c1730()->FUN_140a25840(5, CStringW(strRaw)) == 1)
    {
        NiTexturePtr spTex = FUN_14052d220()->FUN_1418897a0();
        if (spTex)
            FUN_14052d220()->FUN_141888770(m_ent, spTex);
    }
    else
    {
        FUN_141403180(CStringW(strFile));
    }
}

// @0x141403180
void CInteractGuildPosterObject::FUN_141403180(CStringW strFile)
{
    if (m_ent.FUN_1408a9090() == 0)
        return;
    if (strFile.GetLength() < 1)
        return;
    NiTexturePtr spTexA(0);
    if (_waccess(strFile, 0) == 0)
    {
        NiTexturePtr spTex = FUN_14186bd30(strFile, 0x100, false);
        if (spTex == 0)
            return;
        FUN_14052d220()->FUN_141888770(m_ent, spTex);
    }
}

// ================================================================================================================
// CInteractBillBoardObject
// ================================================================================================================

// @0x1414032e0
CInteractBillBoardObject::CInteractBillBoardObject()
    : m_strText()
{
    m_nBoard = 0;
}

// @0x141403340
CInteractBillBoardObject::~CInteractBillBoardObject()
{
}

// @0x141403390
int CInteractBillBoardObject::vfunc_4()
{
    if (CInteractMeshObject::vfunc_4() == 0)
        return 0;
    Unk_IoBoardSvc* pBoard = FUN_140d271c0(0x4f4f);
    if (pBoard != 0)
    {
        __int64 nCur = FUN_140c322b0(pBoard);
        if (nCur != 0 && nCur == m_nBoard)
            return 0;
    }
    return 1;
}

// ================================================================================================================
// CInteractWatchTowerObject
// ================================================================================================================

// @0x141403400
CInteractWatchTowerObject::CInteractWatchTowerObject()
{
    m_bNear = 0;
}

// @0x141403440
CInteractWatchTowerObject::~CInteractWatchTowerObject()
{
}

// @0x141403470
int CInteractWatchTowerObject::vfunc_1(Unk_Entity* pEntity, int nState)
{
    CInteractMeshObject::vfunc_1(pEntity, nState);
    m_bNear = 0;
    FUN_1413fe9a0(0);
    return 1;
}

// @0x1414034c0
int CInteractWatchTowerObject::vfunc_7()
{
    return 0;
}

// @0x1414034d0
int CInteractWatchTowerObject::vfunc_4()
{
    return 0;
}

// @0x1414034e0
void CInteractWatchTowerObject::vfunc_3(int nState)
{
    if (m_ent.FUN_1408b70b0(0))
        return;
    if (m_spRow == 0)
        return;
    m_nState = nState;
    if (m_bNear != 0)
    {
        int bFirst = m_nState == 0;
        FUN_1413ff690(bFirst ? m_strAssetA : m_strAssetB);
        FUN_1413fda50();
    }
}

// NiPoint3 taken by value: efd::Point3 results convert through the out-of-line NiPoint3(const efd::Point3&) and are copied into the argument.
struct Unk_IoNiPoint3 : public Vector3
{
    Unk_IoNiPoint3(const Vector3& pt);                      // 0x14027dcf0
};
MS2_CHECK_SIZE(Unk_IoNiPoint3, 12);

// @0x141403f20
float FUN_141403f20(Unk_IoNiPoint3 a, Unk_IoNiPoint3 b)
{
    a.z = 0.0f;
    b.z = 0.0f;
    return a.FUN_140965c40(b).FUN_140967ac0();
}

// @0x1414035d0
void CInteractWatchTowerObject::vfunc_11()
{
    CInteractObject::vfunc_11();
    unsigned char bNear = 0;
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        float fDist = FUN_141403f20(pPlayer->GetPosition(), GetPos());
        if (fDist < 2000.0f)
            bNear = 1;
    }
    if (m_bNear == bNear)
        return;
    m_bNear = bNear;
    if (m_bNear != 0)
    {
        FUN_1413fe910();
        FUN_1413fda50();
        int bFirst = m_nState == 0;
        const CString* pAsset = bFirst != 0 ? &m_strAssetA : &m_strAssetB;
        FUN_1413ff690(*pAsset);
    }
    else
    {
        FUN_1413fe9a0(0);
        FUN_1413fdc50();
    }
}

// ================================================================================================================
// trivial virtuals
// ================================================================================================================

// @0x141403f10
int CInteractObject::vfunc_16() { return 0; }
// @0x141403f70
int CInteractGatheringObject::vfunc_15() { return m_nRespawnTick; }
// @0x141403f90
int CInteractObject::vfunc_15() { return 0; }
// @0x141403fa0
int CInteractBillBoardObject::vfunc_5() { return 8; }
// @0x141403fb0
int CInteractDisplayImage::vfunc_5() { return 5; }
// @0x141403fc0
int CInteractGatheringObject::vfunc_5() { return 6; }
// @0x141403fd0
int CInteractGuildPosterObject::vfunc_5() { return 7; }
// @0x141403fe0
int CInteractMeshObject::vfunc_5() { return 1; }
// @0x141403ff0
int CInteractObject::vfunc_5() { return 1; }
// @0x141404000
int CInteractTelescopeObject::vfunc_5() { return 2; }
// @0x141404010
int CInteractUIObject::vfunc_5() { return 3; }
// @0x141404020
int CInteractWatchTowerObject::vfunc_5() { return 9; }
// @0x141404060
void CInteractMeshObject::vfunc_2(Unk_InteractMsg*) {}
// @0x141404070
int CInteractObject::vfunc_7() { return m_nState == 1; }
// @0x1414040a0
void CInteractGatheringObject::vfunc_14(int n) { m_nRespawnTick = n; }
// @0x1414040c0
void CInteractObject::vfunc_14(int) {}

// Trailing unreferenced CRT memmove_s COMDAT 0x1414042c0.
MS2_EMIT_CRT_MEMMOVE_S();
