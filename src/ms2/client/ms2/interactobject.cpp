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
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/gfxui/uiswfentity.h"
#include "physxhelper.h"
#include <efd/AssetID.h>
#include <efd/Point3.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

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
static bool FUN_141404030(std::vector<Unk_InteractReqItem>& aItems)
{
    if (aItems.empty())
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
    virtual Unk_StreamPoint* GetPosition(Unk_StreamPoint* pOut) = 0;        // 18
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
    Unk_EntRef* FUN_141529900();
    Unk_StreamPoint* FUN_1416767d0(Unk_StreamPoint* pOut);  // position
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
    ~Unk_IoRankPtr() {}
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
    void FUN_141bd30a0(Unk_IoCutRef* pOut);
    void FUN_141bc8e00();
    void FUN_141bdb030(CString strKey, CStringW strUrl);
    void FUN_141bdb0f0(CString strKey, Unk_IoRankPtr spRank);
};
Unk_IoWorld* FUN_1403ed2d0();
struct Unk_IoFxRequest
{
    CString m_strName;
    int m_nOwnerId;
    int m_pad_0c;
    void* m_pSlot10;
    struct Unk_IoXform* m_pXform;
    char m_pad_20[0x58];
};
MS2_CHECK_SIZE(Unk_IoFxRequest, 0x78);
class Unk_IoFxMgr
{
public:
    int FUN_1411a49c0(Unk_IoFxRequest* pRequest);
    void FUN_1411a6060(int nHandle);
};
Unk_IoFxMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_IoFxRequest* p);
void FUN_1405a89e0(Unk_IoFxRequest* p);
void FUN_140a53190(Unk_IoFxRequest* p, int n);
struct Unk_IoXform
{
    Unk_EfdMatrix3 m_rotate;
    float m_afTranslate[3];
    float m_fScale;
};
MS2_CHECK_SIZE(Unk_IoXform, 0x34);
void* FUN_140a332d0(Unk_IoXform* p);
void FUN_14097faa0(float* pDst, const Unk_NiPoint3* pSrc);
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
    char FUN_14036e4c0();
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
class Unk_IoItem { public: int FUN_140526bd0(); unsigned FUN_140526c50(); };
class Unk_IoItemRef
{
public:
    Unk_IoItem* FUN_1401c0180() const;
    char FUN_140534e50() const;
    void FUN_1401bfde0();
    void* m_p[2];
};
class Unk_IoInventory { public: void FUN_140a5e5c0(Unk_IoItemRef* pOut, int nItemId, int nRarity); };
extern Unk_IoInventory DAT_143ab2a90;
int FUN_14053feb0(int nItemId);

// condition helpers
struct Unk_IoRefOwner;
int FUN_140743710(Unk_IoHomeInfo* p);

// entity and property access
int FUN_1409618c0(Unk_Entity* e, unsigned nHash, Unk_StreamPoint* pOut);
int FUN_1408a2020(Unk_Entity* e, unsigned nHash, int* pOut);
int FUN_1408a20a0(Unk_Entity* e, unsigned nHash, bool* pOut);
int FUN_140961880(Unk_Entity* e, unsigned nHash, float* pOut);   // float property
int FUN_140b27ec0(Unk_Entity* e, unsigned nHash, Unk_StreamPoint* pOut);
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
class Unk_IoSoundMgr { public: void FUN_1409a1fc0(egf::EntityID id, efd::utf8string* pName, float fVol); };
Unk_IoSoundMgr* FUN_141b6f910();

// physics prop object of a mesh interact object
class Unk_PhysPropObj;
Unk_PhysPropObj* FUN_14225f250(void* pMem, Unk_EntRef* pOwner);

// notices
class Unk_IoNotifyBind : public NotifyObject {};
Unk_IoNotifyBind* FUN_140db4a00(void* pMem, CInteractObject* pObject);
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
char* FUN_140a58500(Unk_IoPostFx* p);
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
class Unk_IoUiCreator { public: void* FUN_1422d41b0(void* pRef, const CString& strName); };
Unk_IoUiCreator* FUN_140b632f0();
void* FUN_140b634c0(void* p);
void FUN_140b62af0(void* pRef);
unsigned FUN_140869420();

// gathering and tables
void FUN_140e59bb0(void* p, CInteractObject* pObject);
void* FUN_14122d430(int nId);
class Unk_IoGatherRow { public: int m_pad_00[7]; unsigned m_nLevel; int m_pad_20; unsigned m_nMinLevel; };
class Unk_IoGatherIt { public: void FUN_14066d5b0(); char FUN_14066d900(); Unk_IoGatherRow* FUN_14066d9a0(); char m_buf[16]; };
class Unk_IoGatherMgr { public: void FUN_14066aa00(Unk_IoGatherIt* pOut, int nId); int FUN_14066bc40(int nId); };
Unk_IoGatherMgr* FUN_1409670c0();
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
    virtual void vf0() = 0; virtual void vf1() = 0;
    virtual short ReadShort() = 0;      // 2
    virtual int ReadInt() = 0;          // 3
};
struct Unk_InteractMsg
{
    void* m_pad_00;
    void* m_pStreamVptr;
    Unk_IoStream* Stream() { return reinterpret_cast<Unk_IoStream*>(&m_pStreamVptr); }
};

// state interact data sent to the world
class Unk_IoStateData : public CPtred
{
public:
    int m_nId;                      // +0x18
    int m_pad_1c;
    CString m_strName;              // +0x20
    char m_pad_28[8];
    int m_nFlag;                    // +0x30
    int m_pad_34;
};
MS2_CHECK_SIZE(Unk_IoStateData, 0x38);
Unk_IoStateData* FUN_1417d0be0(void* pMem);                 // StateInteractData ctor
struct Unk_IoStateSp { void* m_pad; Unk_IoStateData* m_p; };
void FUN_140964220(Unk_IoStateSp* p, Unk_IoStateData* pData);
Unk_IoStateData* FUN_1409659d0(Unk_IoStateSp* p);
void* FUN_140965870(Unk_IoStateSp* p);
void FUN_140964bc0(Unk_IoStateSp* p);

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
    void* pMem = operator new(0x20);
    Unk_IoNotifyBind* pNotify = pMem ? FUN_140db4a00(pMem, this) : 0;
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(pNotify));
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
        Unk_IoXform xf;
        FUN_140a332d0(&xf);
        Unk_StreamPoint ptUp(0.0f, 0.0f, 1.0f);
        Unk_StreamPoint ptPos = m_vPos.FUN_14097fd50(ptUp);
        Unk_NiPoint3 niPos(ptPos);
        FUN_14097faa0(xf.m_afTranslate, &niPos);
        xf.m_rotate.FUN_142083d40((m_vRot.x * 3.1415927f) / 180.0f, (m_vRot.y * 3.1415927f) / 180.0f,
                                  (m_vRot.z * 3.1415927f) / 180.0f);
        xf.m_fScale = 1.0f;
        Unk_IoFxRequest request;
        FUN_140a52ef0(&request);
        request.m_strName = strAsset;
        request.m_nOwnerId = 0;
        request.m_pXform = &xf;
        m_nEffect = FUN_1403ed280()->FUN_1411a49c0(&request);
        m_nShownState = m_nState;
        FUN_1405a89e0(&request);
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

// MS2-FUNCTIONAL: the cost item is a raw Unk_IoItemRef released by hand (FUN_1401bfde0 before each return); the exe holds a real MS2Ptr<CItem> local (EH frame, the returns run its dtor), 38 bytes longer
// @0x1413fde40
int CInteractObject::FUN_1413fde40()
{
    if (m_spRow == 0)
        return 0;
    if (m_spRow->m_item.m_nCode != 0)
    {
        int nRarity = m_spRow->m_item.m_nRank;
        if (nRarity == 0)
            nRarity = FUN_14053feb0(m_spRow->m_item.m_nCode);
        Unk_IoItemRef item;
        DAT_143ab2a90.FUN_140a5e5c0(&item, m_spRow->m_item.m_nCode, nRarity);
        if (item.FUN_140534e50() != 0)
        {
            item.FUN_1401bfde0();
            return 0;
        }
        unsigned nLevel = item.FUN_1401c0180()->FUN_140526c50();
        if (nLevel < m_spRow->m_item.m_nConsume)
        {
            item.FUN_1401bfde0();
            return 0;
        }
        if (item.FUN_1401c0180()->FUN_140526bd0() != nRarity)
        {
            item.FUN_1401bfde0();
            return 0;
        }
        item.FUN_1401bfde0();
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
    if (!FUN_141404030(m_spRow->m_aReqItem.m_aItem))
        return 1;
    std::vector<Unk_InteractReqItem>& aReq = m_spRow->m_aReqItem.m_aItem;
    std::vector<Unk_InteractReqItem>::const_iterator itEnd = aReq.end();
    for (std::vector<Unk_InteractReqItem>::const_iterator it = aReq.begin(); it != itEnd; ++it)
    {
        Unk_InteractReqItem req = *it;
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
        packet.vfunc_o10_1(0xb);
        packet.vfunc_o10_3(1);
        packet.vfunc_o10_7(GetName());
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
        packet.vfunc_o10_1(0xc);
        packet.vfunc_o10_3(1);
        packet.vfunc_o10_7(GetName());
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

// MS2-FUNCTIONAL: the effect transform is built through named Unk_StreamPoint / Unk_NiPoint3 locals and an explicit transform init (3 calls more than the exe, which passes the summed point temp straight to the translate setter)
// @0x1413fe5d0
void CInteractObject::vfunc_12()
{
    if (m_spRow->m_effect.m_strSuccess.GetLength() != 0)
    {
        Unk_IoXform xf;
        FUN_140a332d0(&xf);
        Unk_StreamPoint ptUp(0.0f, 0.0f, 1.0f);
        Unk_StreamPoint ptPos = m_vPos.FUN_14097fd50(ptUp);
        Unk_NiPoint3 niPos(ptPos);
        FUN_14097faa0(xf.m_afTranslate, &niPos);
        xf.m_rotate.FUN_142083d40((m_vRot.x * 3.1415927f) / 180.0f, (m_vRot.y * 3.1415927f) / 180.0f,
                                  (m_vRot.z * 3.1415927f) / 180.0f);
        xf.m_fScale = 1.0f;
        Unk_IoFxRequest request;
        FUN_140a52ef0(&request);
        request.m_strName = m_spRow->m_effect.m_strSuccess;
        request.m_nOwnerId = 1;
        request.m_pXform = &xf;
        Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
            FUN_140a53190(&request, pPlayer->FUN_14123c580());
        m_nParticle = FUN_1403ed280()->FUN_1411a49c0(&request);
        FUN_1405a89e0(&request);
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
    Unk_EntRef owner(0);
    owner.FUN_1408b6ec0(pEntity);
    void* pMem = operator new(0x98);
    Unk_PhysPropObj* pProp = pMem ? FUN_14225f250(pMem, &owner) : 0;
    m_spProp.FUN_140ae17e0(pProp);
    efd::utf8string strMesh;
    FUN_1409989e0(&strMesh, "MS2InteractMesh");
    bool bMesh = FUN_1408a9bd0(pEntity)->ContainsModel(strMesh);
    FUN_1408a8900(&strMesh);
    if (!bMesh)
    {
        efd::utf8string strActor;
        FUN_1409989e0(&strActor, "MS2InteractActor");
        bool bActor = FUN_1408a9bd0(pEntity)->ContainsModel(strActor);
        FUN_1408a8900(&strActor);
        if (!bActor)
            return 0;
        efd::utf8string strA;
        efd::utf8string strB;
        FUN_1408a2060(pEntity, 0x3ff293c8, &strA);
        FUN_1408a2060(pEntity, 0x63c7b14a, &strB);
        m_strAssetA = FUN_1408ac310(&strA);
        m_strAssetB = FUN_1408ac310(&strB);
        m_nAssetType = 2;
    }
    else
    {
        efd::AssetID idA;
        efd::AssetID idB;
        FUN_140998250(pEntity, 0x770e5fc6, &idA);
        FUN_140998250(pEntity, 0xae1cf70e, &idB);
        m_strAssetA = FUN_14099ad40(&idA);
        m_strAssetB = FUN_14099ad40(&idB);
        m_nAssetType = 1;
    }
    return CInteractObject::vfunc_1(pEntity, nState);
}

// @0x1413fef20
void CInteractMeshObject::vfunc_3(int nState)
{
    CInteractObject::vfunc_3(nState);
    if (!(m_spRow == 0) && !m_ent.FUN_1408b70b0(0))
    {
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
        }
        else
        {
            unsigned char bFlag = 1;
            FUN_14098c6e0(m_ent.FUN_1408a9280(), 0xa0b6b179, &bFlag);
            unsigned bFirst = m_nState == 0;
            CString* pAsset = bFirst == 0 ? &m_strAssetB : &m_strAssetA;
            FUN_1413ff690(*pAsset);
            int nCollision;
            if (bFirst == 0)
                nCollision = m_spRow->m_mesh.m_nReactableCollision;
            else
                nCollision = m_spRow->m_mesh.m_nNormalCollision;
            FUN_1413ff800(nCollision);
        }
    }
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

// @0x1413ff170
// MS2-FUNCTIONAL: PhysX descriptor setup written with the SDK's own members
void CInteractMeshObject::MakeNxBoxController()
{
    if (m_pActor != 0)
        return;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    if (pScene == 0)
        return;
    Unk_StreamPoint ptPos;
    ptPos = m_vPos;
    NxBoxShapeDesc box;
    box.dimensions.set(m_spRow->m_mesh.m_shapeDimension.x, m_spRow->m_mesh.m_shapeDimension.y, m_spRow->m_mesh.m_shapeDimension.z);
    box.dimensions *= 0.01f;
    box.dimensions *= 0.5f;
    box.groupsMask.bits0 = 0xffffffff;
    box.shapeFlags &= 0xffedffff;
    NxActorDesc actorDesc;
    actorDesc.shapes.pushBack(&box);
    NxVec3 vPose(ptPos.x * 0.01f, ptPos.y * 0.01f, ptPos.z * 0.01f);
    vPose.z += box.dimensions.z;
    actorDesc.globalPose.t = vPose;
    actorDesc.globalPose.M.rotZ((m_vRot.z * 3.1415927f) / 180.0f);
    NxVec3 vSet(m_vPos.x * 0.01f, m_vPos.y * 0.01f, m_vPos.z * 0.01f);
    vSet.z += m_spRow->m_mesh.m_shapeDimension.z * 0.01f * 0.5f;
    FUN_1409f7ca0()->FUN_14168a540(0);
    m_pActor = pScene->createActor(actorDesc);
    if (m_pActor != 0)
    {
        m_pActor->setName("CInteractMeshObject::MakeNxBoxController");
        NxU32 nShapes = m_pActor->getNbShapes();
        NxShape* const* ppShapes = m_pActor->getShapes();
        for (NxU32 i = 0; i < nShapes; ++i)
            ppShapes[i]->setFlag(NX_SF_VISUALIZATION, false);
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
        efd::utf8string str;
        FUN_1409989e0(&str, strAsset);
        FUN_140de0cb0(&id, &str);
        FUN_1408a8900(&str);
        FUN_140de8bd0(m_ent.FUN_1408a9280(), 0x770e5fc6, &id);
    }
    else if (m_nAssetType == 2)
    {
        efd::utf8string str;
        FUN_1409989e0(&str, strAsset);
        egf::EntityID idEnt = *FUN_1408b76f0(m_ent.FUN_1408a9280());
        FUN_141b6f910()->FUN_1409a1fc0(idEnt, &str, 1.0f);
        FUN_1408a8900(&str);
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
    m_ent.FUN_1408b6ec0(pPlayer->FUN_141529900()->FUN_1408a9090());
    if (m_ent.FUN_1408a9090() == 0)
        return;
    m_bActive = 1;
    FUN_141276180(s_strUseTelescope, CString(""));
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
    Unk_StreamPoint colA;
    Unk_StreamPoint colB;
    FUN_1406c4340(&colA.x, 0.0f, 0.0f, 0.0f);
    FUN_1406c4340(&colB.x, 0.0f, 0.0f, 0.0f);
    bool bFilter = false;
    bool bColor = false;
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

// @0x1413fff60
void CInteractTelescopeObject::OnCutSceneSkip(NotifyObject*)
{
    FUN_140ad4b90()->FUN_141863460(0.0f);
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
    Unk_IoCutRef ref;
    FUN_1403ed2d0()->FUN_141bd30a0(&ref);
    if (ref.FUN_1409657a0() != 0)
    {
        Unk_IoCutData* pData = ref.FUN_140885340();
        FUN_1409a8b00()->FUN_1409a4450(pData->m_b1fd, pData->m_n204, pData->m_n208, pData->m_n200);
        FUN_1409a8b00()->FUN_1409a46a0(pData->m_b20c, &pData->m_n210, pData->m_n214, pData->m_n218, pData->m_n21c);
    }
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyCutSceneCinematicSkip"),
                                   Delegate<void(NotifyObject*)>(this, &CInteractTelescopeObject::OnCutSceneSkip));
    m_bActive = 0;
    ref.FUN_1408850f0();
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
    char ref[16];
    UISwfEntity* pEntity = reinterpret_cast<UISwfEntity*>(
        FUN_140b634c0(FUN_140b632f0()->FUN_1422d41b0(ref, m_spRow->m_ui.m_strSwf)));
    UIDialog* pDialog = dynamic_cast<UIDialog*>(pEntity);
    FUN_140b62af0(ref);
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
    if (FUN_1403ed2b0()->FUN_141adc940(m_nDialogId) == 0)
    {
        Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
        {
            FUN_1403ed2b0()->FUN_141adc5d0(m_nDialogId);
        }
        else
        {
            float fRange = GetRow()->m_validate.m_fInteractionDistance;
            Unk_StreamPoint ptSelf = GetPos();
            Unk_StreamPoint ptPlayer;
            pPlayer->FUN_1416767d0(&ptPlayer);
            float fDist = ptPlayer.FUN_140965c40(ptSelf).FUN_140967ac0();
            if (fRange < fDist)
                FUN_1403ed2b0()->FUN_141adc5d0(m_nDialogId);
        }
    }
    else
    {
        m_nDialogId = 0;
    }
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
    if (FUN_14025e7b0()->m_cfg.FUN_1402c4c90(0x32) == 0)
    {
        if (FUN_140166410()->FUN_14036d570(0x3f) == 1)
        {
            m_pThread = AfxBeginThread(GetURLFromGameRanking, this, 0, 0, 0, 0);
            return 1;
        }
    }
    if (FUN_140166410()->FUN_14036e4c0() != 0)
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
struct Unk_IoUrl { char m_buf[0x80]; };
void FUN_1409208e0(Unk_IoUrl* p, std::wstring strUrl);
int FUN_140920cf0(Unk_IoUrl* p, std::wstring strVerb, int n);
int FUN_140922f20(Unk_IoUrl* p);
void FUN_140922860(Unk_IoUrl* p, std::string* pBody);
void FUN_140920b30(Unk_IoUrl* p);
const char* FUN_14018ef70(std::string* p);
CStringW FUN_140efe330(const char* psz, unsigned n);

// ---- ranking / xml / image stand-ins used by the display image ----
struct Unk_IoXmlElem { char m_buf[0x90]; };
Unk_IoXmlElem* FUN_14086f2f0(Unk_IoXmlElem* p, const char* pszName);       // TiXmlElement(const char*)
void FUN_14086f450(Unk_IoXmlElem* p);                                       // ~TiXmlElement
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
class Unk_IoPosterSvc { public: void FUN_1404d2220(CStringW* pOut, int nId); };
unsigned __int64 FUN_1404ccbd0(Unk_IoPosterSvc* p);
struct Unk_IoPosterHolder { char m_pad_00[8]; Unk_IoPosterSvc m_svc; };
Unk_IoPosterHolder* FUN_1403ed290();

struct Unk_IoTexPtr { void* m_p; };
void FUN_14097ed60(Unk_IoTexPtr* p, void* pRaw);            // ctor from a raw pointer (AddRef when set)
void FUN_14097f4a0(Unk_IoTexPtr* p);
void* FUN_14097fbf0(Unk_IoTexPtr* p);
void FUN_14186bd30(Unk_IoTexPtr* pOut, const CStringW& strPath, int nFlag, int nZero);
unsigned char FUN_1410b21a0(Unk_IoTexPtr* p, int nZero);
class Unk_IoTexMgr
{
public:
    void FUN_141888770(Unk_EntRef ent, void* pTex);
    void FUN_1418897a0(Unk_IoTexPtr* pOut);
    void FUN_141880230(CString strName, int nPosterId);
};
Unk_IoTexMgr* FUN_14052d220();
class Unk_IoPosterChk { public: char FUN_140a25840(int n, CStringW str); };
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
        Unk_IoXmlElem elem;
        FUN_14086f2f0(&elem, "guild");
        if (FUN_1408782b0(&elem, strKey, 0, 1) == 0)
        {
            FUN_14086f450(&elem);
            return;
        }
        CString strMark = FUN_14015f710(&elem, "mark", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strGuildName = FUN_1401bf530(&elem, "name", CStringW(L""));
        m_nGuildRank = FUN_140197350(&elem, "rank", 0);
        m_nGuildTrophy = FUN_140197350(&elem, "trophy", 0);
        m_nGuildScore = FUN_140197350(&elem, "score", 0);
        if (strMark.GetLength() < 1 || nSn == 0)
        {
            FUN_14086f450(&elem);
            return;
        }
        CString strPath = FUN_141029590(nSn, strMark, GetName(), CString(""));
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
        FUN_14086f450(&elem);
    }
    else if (spRow->m_displayUrl.m_nType == 2)
    {
        Unk_IoXmlElem elem;
        FUN_14086f2f0(&elem, "character");
        if (FUN_1408782b0(&elem, strKey, 0, 1) == 0)
        {
            FUN_14086f450(&elem);
            return;
        }
        CString strPortrait = FUN_14015f710(&elem, "portrait", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strCharName = FUN_1401bf530(&elem, "name", CStringW(L""));
        m_nCharTrophy = FUN_140197350(&elem, "trophy", 0);
        m_nCharRank = FUN_140197350(&elem, "rank", 0);
        CString strPath = FUN_141028be0(nSn, strPortrait, 1, GetName());
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
        FUN_14086f450(&elem);
    }
    else if (spRow->m_displayUrl.m_nType == 4)
    {
        Unk_IoXmlElem elem;
        FUN_14086f2f0(&elem, "character");
        if (FUN_1408782b0(&elem, strKey, 0, 1) == 0)
        {
            FUN_14086f450(&elem);
            return;
        }
        CString strPortrait = FUN_14015f710(&elem, "portrait", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strCharName = FUN_1401bf530(&elem, "name", CStringW(L""));
        m_nCharBuildPoint = FUN_140197350(&elem, "build_point", 0);
        m_nCharRank = FUN_140197350(&elem, "rank", 0);
        CString strPath = FUN_141028be0(nSn, strPortrait, 1, GetName());
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
        FUN_14086f450(&elem);
    }
    else if (spRow->m_displayUrl.m_nType == 5)
    {
        Unk_IoXmlElem elem;
        FUN_14086f2f0(&elem, "character");
        if (FUN_1408782b0(&elem, strKey, 0, 1) == 0)
        {
            FUN_14086f450(&elem);
            return;
        }
        CString strPortrait = FUN_14015f710(&elem, "portrait", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strCharName = FUN_1401bf530(&elem, "name", CStringW(L""));
        m_nCharScore = FUN_140197350(&elem, "score", 0);
        m_nCharRank = FUN_140197350(&elem, "rank", 0);
        CString strPath = FUN_141028be0(nSn, strPortrait, 1, GetName());
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
        FUN_14086f450(&elem);
    }
}

// @0x141401380
void CInteractDisplayImage::FUN_141401380(Unk_IoRankPtr spRank)
{
    MS2Ptr<CInteractObjectData> spRow = GetRow();
    if (spRow == 0)
    {
        spRank.FUN_140b2da40();
        return;
    }
    if (spRank == 0)
    {
        spRank.FUN_140b2da40();
        return;
    }
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
    int nType = m_spRow->m_displayUrl.m_nType;
    if (nType == 1 || nType == 3)
    {
        strPath = FUN_141029590(nGuildSn, strKey, GetName(), CString(""));
    }
    else if (nType == 2 || (nType >= 4 && nType <= 5))
    {
        strPath = FUN_141028be0(nCharSn, strKey, 1, GetName());
    }
    if (strPath.GetLength() > 0)
        FUN_1414017b0(strPath);
    spRank.FUN_140b2da40();
}

// @0x1414017b0
void CInteractDisplayImage::FUN_1414017b0(const CString& strFile)
{
    CStringW strPath = FUN_14016a730(strFile, 0);
    if (m_ent.FUN_1408a9090() == 0)
        return;
    Unk_IoTexPtr texA;
    FUN_14097ed60(&texA, 0);
    if (_waccess(strPath, 0) == 0)
    {
        Unk_IoTexPtr texB;
        FUN_14186bd30(&texB, strPath, 0x100, 0);
        if (FUN_1410b21a0(&texB, 0) != 0)
        {
            FUN_14097f4a0(&texB);
            FUN_14097f4a0(&texA);
            return;
        }
        FUN_14052d220()->FUN_141888770(m_ent, FUN_14097fbf0(&texB));
        FUN_14097f4a0(&texB);
    }
    FUN_14097f4a0(&texA);
}

// @0x141401920
UINT CInteractDisplayImage::GetURLFromIndirectURL(LPVOID pParam)
{
    CInteractDisplayImage* pThis = static_cast<CInteractDisplayImage*>(pParam);
    FUN_141b6de20();
    Unk_IoThreadScope scope;
    FUN_141b721f0(&scope, CString("CInteractDisplayImage::GetURLFromIndirectURL"));
    UINT nRet = 0;
    if (pThis != 0)
    {
        CString strName = pThis->GetName();
        std::wstring strUrl(CStringW(FUN_14016a730(pThis->m_strUrl, 0)));
        Unk_IoUrl url;
        FUN_1409208e0(&url, strUrl);
        if (FUN_140920cf0(&url, std::wstring(L"GET"), 0) != 0)
        {
            if (FUN_140922f20(&url) != 0)
            {
                nRet = 0;
                FUN_140920b30(&url);
                FUN_141b722b0(&scope);
                return nRet;
            }
            std::string strBody;
            FUN_140922860(&url, &strBody);
            CStringW strResult = FUN_140efe330(FUN_14018ef70(&strBody), 0);
            if (FUN_1403ed2d0() != 0)
                FUN_1403ed2d0()->FUN_141bdb030(CString(strName), CStringW(strResult));
        }
        FUN_140920b30(&url);
    }
    FUN_141b722b0(&scope);
    return nRet;
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
            spTemp.FUN_140b2da40();
            ++nTry;
        } while (spRank.FUN_140efcde0() == 0);
        FUN_140b436f0(&param);
    }
    if (spRank.FUN_140efcde0() != 0 && FUN_1403ed2d0() != 0)
    {
        Unk_IoRankPtr spCopy(spRank);
        FUN_1403ed2d0()->FUN_141bdb0f0(CString(strName), spCopy);
    }
    spRank.FUN_140b2da40();
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
    short sType = pMsg->Stream()->ReadShort();
    int nCount = pMsg->Stream()->ReadInt();
    vfunc_3(0);
    int nNow = FUN_140869420();
    m_nRespawnTick = nNow + m_spRow->m_nResetTime;
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        void* pMem = operator new(0x38);
        Unk_IoStateData* pData = 0;
        if (pMem != 0)
            pData = FUN_1417d0be0(pMem);
        Unk_IoStateSp spData;
        FUN_140964220(&spData, pData);
        FUN_1409659d0(&spData)->m_nId = GetRowId();
        FUN_1409659d0(&spData)->m_strName = GetName();
        FUN_1409659d0(&spData)->m_nFlag = 1;
        int nMsg = 0x8c;
        if (sType == 0)
            nMsg = 0x8b;
        pPlayer->SendState(0x19, FUN_140965870(&spData), nMsg, 0);
        FUN_140964bc0(&spData);
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
    pOut->m_strHint = GetStringCommonByKey(CStringW(L"s_action_gathering"));
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
    int nGatherId = m_spRow->m_gathering.m_nReceipeId;
    if (nGatherId != 0)
    {
        Unk_IoGatherIt it;
        FUN_1409670c0()->FUN_14066aa00(&it, m_spRow->m_gathering.m_nReceipeId);
        if (it.FUN_14066d900() != 0)
        {
            it.FUN_14066d5b0();
            return 0;
        }
        unsigned nLevel = pPlayer->FUN_141662750(it.FUN_14066d9a0()->m_nLevel);
        if (nLevel < it.FUN_14066d9a0()->m_nMinLevel)
        {
            it.FUN_14066d5b0();
            return 0;
        }
        if (FUN_140e5ca20()->FUN_140b6d330(m_spRow->m_gathering.m_nReceipeId) == 0)
        {
            it.FUN_14066d5b0();
            return 0;
        }
        it.FUN_14066d5b0();
    }
    return 1;
}

// @0x141402ad0
int CInteractGatheringObject::vfunc_16()
{
    if (FUN_141402c90() == 0)
        return 0;
    if (FUN_1409670c0()->FUN_14066bc40(m_spRow->m_gathering.m_nReceipeId) == 3)
        return 0;
    return 1;
}

// MS2-FUNCTIONAL: the gathering iterator Unk_IoGatherIt is a buffer placeholder released by hand (GS cookie frame); the exe has a real iterator object with a dtor (EH frame) and returns through a stored result
// @0x141402b40
int CInteractGatheringObject::FUN_141402b40()
{
    if (vfunc_15() != 0)
        return 0;
    if (m_spRow->m_gathering.m_nReceipeId != 0)
    {
        Unk_IoGatherIt it;
        FUN_1409670c0()->FUN_14066aa00(&it, m_spRow->m_gathering.m_nReceipeId);
        if (it.FUN_14066d900() != 0)
        {
            it.FUN_14066d5b0();
            return 0;
        }
        if (FUN_140e5ca20()->FUN_140b6d330(m_spRow->m_gathering.m_nReceipeId) == 0)
        {
            it.FUN_14066d5b0();
            return 0;
        }
        it.FUN_14066d5b0();
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

// MS2-FUNCTIONAL: string temporaries differ: the exe builds the CStringW copy for FUN_140a25840 after the URL and keeps the texture handle as a by-value object (one CStringA dtor fewer, EH states shifted); the raw texture handle here is released by hand
// @0x141402eb0
void CInteractGuildPosterObject::FUN_141402eb0(unsigned char bShow)
{
    if (m_ent.FUN_1408a9090() == 0)
        return;
    int nPoster = FUN_141402e60();
    unsigned __int64 nSvc = FUN_1404ccbd0(&FUN_1403ed290()->m_svc);
    CStringW strRaw;
    FUN_1403ed290()->m_svc.FUN_1404d2220(&strRaw, nPoster);
    CString strUrl = FUN_1410299f0(nSvc, FUN_14016a600(strRaw, 0), nPoster, GetName(), bShow);
    CStringW strFile = FUN_14016a730(strUrl, 0);
    if (FUN_1409c1730()->FUN_140a25840(5, CStringW(strRaw)) == 1)
    {
        Unk_IoTexPtr tex;
        FUN_14052d220()->FUN_1418897a0(&tex);
        if (FUN_14097fbf0(&tex) != 0)
            FUN_14052d220()->FUN_141888770(m_ent, FUN_14097fbf0(&tex));
        FUN_14097f4a0(&tex);
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
    Unk_IoTexPtr texA;
    FUN_14097ed60(&texA, 0);
    if (_waccess(strFile, 0) == 0)
    {
        Unk_IoTexPtr texB;
        FUN_14186bd30(&texB, strFile, 0x100, 0);
        if (FUN_1410b21a0(&texB, 0) != 0)
        {
            FUN_14097f4a0(&texB);
            FUN_14097f4a0(&texA);
            return;
        }
        FUN_14052d220()->FUN_141888770(m_ent, FUN_14097fbf0(&texB));
        FUN_14097f4a0(&texB);
    }
    FUN_14097f4a0(&texA);
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

// @0x141403f20
static float FUN_141403f20(Unk_StreamPoint* pA, Unk_StreamPoint* pB)
{
    pA->z = 0.0f;
    pB->z = 0.0f;
    return pA->FUN_140965c40(*pB).FUN_140967ac0();
}

// @0x1414035d0
void CInteractWatchTowerObject::vfunc_11()
{
    CInteractObject::vfunc_11();
    unsigned char bNear = 0;
    Unk_IoPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        Unk_StreamPoint ptSelf = GetPos();
        Unk_StreamPoint ptPlayer;
        pPlayer->GetPosition(&ptPlayer);
        float fDist = FUN_141403f20(&ptPlayer, &ptSelf);
        if (fDist < 2000.0f)
            bNear = 1;
    }
    if (m_bNear != bNear)
    {
        m_bNear = bNear;
        if (m_bNear == 0)
        {
            FUN_1413fe9a0(0);
            FUN_1413fdc50();
        }
        else
        {
            FUN_1413fe910();
            FUN_1413fda50();
            const CString* pAsset;
            if (m_nState == 0)
                pAsset = &m_strAssetA;
            else
                pAsset = &m_strAssetB;
            FUN_1413ff690(*pAsset);
        }
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
