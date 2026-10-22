// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The game ranking window ("GameRankingDialog": trophy, boss,
// arcade / UGC / colosseum boards with season tabs, the category list from Table/gameRankingCategory.xml, rows and
// the party member tooltips).
// MS2-UNIT: ?\uigamerankingdialog.cpp
// MS2-RANGE: 0x140e2cc90-0x140e39790 .text$mn
// MS2-RANGE: 0x1400d7c80-0x1400d7e20 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$forward@AEBQEAVUIGameRankingDialog@@@std@@YAAEBQEAVUIGameRankingDialog@@AEBQEAV1@@Z 0x140e35f80 ; unique
// MS2-PIN: ??0?$CAtlList@V?$Unk_RankPtr@VGameRankingCategory@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingCategory@@@@@ATL@@@ATL@@QEAA@I@Z 0x140e360a0 ; unique
// MS2-PIN: ??0?$CAtlList@V?$MS2Ptr@VUnk_RankChartRec@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_RankChartRec@@@@@ATL@@@ATL@@QEAA@I@Z 0x140e36100 ; prop
// MS2-PIN: ??0?$Unk_RankPtr@VGameRankingCategory@@@@QEAA@AEBUUnk_RankNewTag@@@Z 0x140e36380 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$Unk_RankBoxPtr@V?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@@@UUnk_RankKeyTraits@@V?$CElementTraits@V?$Unk_RankBoxPtr@V?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@@@@ATL@@@ATL@@IEAA@AEBH@Z 0x140e366b0 ; unique
// MS2-PIN: ??1?$CAtlList@V?$MS2Ptr@VUnk_RankChartRec@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_RankChartRec@@@@@ATL@@@ATL@@QEAA@XZ 0x140e36950 ; unique
// MS2-PIN: ??1?$TPtredDummy@V?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@@@UEAA@XZ 0x140e36a50 ; unique
// MS2-PIN: ??1CNode@?$CAtlList@V?$MS2Ptr@VUnk_RankChartRec@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_RankChartRec@@@@@ATL@@@ATL@@QEAA@XZ 0x140e36ad0 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIGameRankingDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140e36ee0 ; prop
// MS2-PIN: ??_G?$TPtredDummy@V?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@@@UEAAPEAXI@Z 0x140e36fa0 ; unique
// MS2-PIN: ??_GCNode@?$CAtlList@V?$MS2Ptr@VUnk_RankChartRec@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_RankChartRec@@@@@ATL@@@ATL@@QEAAPEAXI@Z 0x140e37020 ; prop
// MS2-PIN: ?CallConstructors@?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@CAXPEAV?$Unk_RankPtr@VGameRankingTabData@@@@_K@Z 0x140e37310 ; unique
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@H@ATL@@SA_NAEBH0@Z 0x140e37450 ; unique
// MS2-PIN: ?FreeNode@?$CAtlList@V?$MS2Ptr@VUnk_RankChartRec@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_RankChartRec@@@@@ATL@@@ATL@@AEAAXPEAVCNode@12@@Z 0x140e375d0 ; unique
// MS2-PIN: ??A?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAAAEAH_K@Z 0x140e37850 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Unk_RankBoxPtr@V?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@@@UUnk_RankKeyTraits@@V?$CElementTraits@V?$Unk_RankBoxPtr@V?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@@@@ATL@@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x140e37b30 ; unique
// MS2-PIN: ?vfunc_48@UIGameRankingDialog@@UEAAHXZ 0x140e37c30 ; unique
// MS2-PIN: ?Hash@?$CDefaultHashTraits@H@ATL@@SAKAEBH@Z 0x140e37de0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlList@V?$MS2Ptr@VUnk_RankChartRec@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_RankChartRec@@@@@ATL@@@ATL@@QEAAXXZ 0x140e38730 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIGameRankingDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140e39590 ; unique
// MS2-PIN: ??$Call@VUIGameRankingDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIGameRankingDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIGameRankingDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140e395d0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@@@6B@ 0x142e49a78
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400d7d40
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400d7d70
// MS2-PIN: ??0?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x140e36060
// MS2-PIN: ??1?$CAtlArray@UUnk_RankSeasonPtr@@V?$CElementTraits@UUnk_RankSeasonPtr@@@ATL@@@ATL@@QEAA@XZ 0x140e368f0
// MS2-PIN: ??0?$Unk_RankPtr@VGameRankingTabData@@@@QEAA@XZ 0x140e362f0
// MS2-PIN: ??0?$Unk_RankBoxPtr@V?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@@@QEAA@H@Z 0x140e36310
// Category null construction is pinned at the end of this unit (caller 0x140e350c0).
// MS2-PIN: ??7?$MS2Ptr@VUnk_RankChartRec@@@@QEBA_NXZ 0x140e36c70
// MS2-PIN: ??7?$MS2Ptr@VUnk_RankTab@@@@QEBA_NXZ 0x140e36ca0
// MS2-PIN: ??8?$MS2Ptr@VAScript@@@@QEBA_NPEAVAScript@@@Z 0x140e36d50
// MS2-PIN: ??8?$MS2Ptr@VUnk_RankArcade@@@@QEBA_NPEAVUnk_RankArcade@@@Z 0x140e36d90
// MS2-PIN: ??C?$MS2Ptr@VAScript@@@@QEBAPEAVAScript@@XZ 0x140e36e50
// MS2-PIN: ??C?$MS2Ptr@VUnk_RankArcade@@@@QEBAPEAVUnk_RankArcade@@XZ 0x140e36ed0
// MS2-PIN: ?GetCount@?$CAtlArray@UUnk_RankSeasonPtr@@V?$CElementTraits@UUnk_RankSeasonPtr@@@ATL@@@ATL@@QEBA_KXZ 0x140e37910
// MS2-PIN: ?GetCount@?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEBA_KXZ 0x140e37920
// MS2-PIN: ??A?$CAtlArray@UUnk_RankSeasonPtr@@V?$CElementTraits@UUnk_RankSeasonPtr@@@ATL@@@ATL@@QEAAAEAUUnk_RankSeasonPtr@@_K@Z 0x140e377d0
// MS2-PIN: ??A?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_RankPtr@VGameRankingTabData@@@@_K@Z 0x140e37810
// MS2-PIN: ?GetAt@?$CAtlList@V?$Unk_RankPtr@VGameRankingCategory@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingCategory@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_RankPtr@VGameRankingCategory@@@@PEAU__POSITION@@@Z 0x140e37890
// MS2-PIN: ?GetHeadPosition@?$CAtlList@V?$Unk_RankPtr@VGameRankingCategory@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingCategory@@@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x140e37a90
// MS2-PIN: ?GetNext@?$CAtlList@V?$Unk_RankPtr@VGameRankingCategory@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingCategory@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_RankPtr@VGameRankingCategory@@@@AEAPEAU__POSITION@@@Z 0x140e37ab0
// MS2-PIN: ?AddRef@?$Unk_RankPtr@VGameRankingCategory@@@@AEBAXXZ 0x140e39030
// MS2-PIN: ?AddRefImpl@?$Unk_RankPtr@VGameRankingCategory@@@@AEBAXPEAX@Z 0x140e39120
// MS2-PIN: ??0?$MS2Ptr@VUnk_RankInput@@@@QEAA@H@Z 0x140e363b0
// MS2-PIN: ??0?$MS2Ptr@VUnk_RankList@@@@QEAA@H@Z 0x140e36510
// MS2-PIN: ??0?$Unk_RankPtr@VGameRankingTabData@@@@QEAA@H@Z 0x140e36470
// MS2-PIN: ??0?$Unk_RankBoxPtr@V?$CAtlArray@V?$Unk_RankPtr@VGameRankingTabData@@@@V?$CElementTraits@V?$Unk_RankPtr@VGameRankingTabData@@@@@ATL@@@ATL@@@@QEAA@XZ 0x140e36490
// MS2-PIN: ??8?$Unk_RankPtr@VGameRankingTabData@@@@QEBA_NPEAVGameRankingTabData@@@Z 0x140e36d10
// MS2-PIN: ?get@?$MS2Ptr@VUnk_RankInput@@@@QEBAPEAVUnk_RankInput@@XZ 0x140e36e40
// MS2-PIN: ??0?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@QEAA@XZ 0x140e35fe0
// MS2-PIN: ??0Unk_RankDataPtr@@QEAA@XZ 0x140e36530
// MS2-PIN: ??7?$Unk_RankPtr@VGameRankingCategory@@@@QEBA_NXZ 0x140e36c40
// MS2-PIN: ??8?$Unk_RankPtr@VGameRankingCategory@@@@QEBA_NPEAVGameRankingCategory@@@Z 0x140e36cd0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIGameRankingDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e39530
// MS2-PIN: ?CallConstructors@?$CAtlArray@UUnk_RankDataPtr@@V?$CElementTraits@UUnk_RankDataPtr@@@ATL@@@ATL@@CAXPEAUUnk_RankDataPtr@@_K@Z 0x140e37290
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigamerankingdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uigamerankingdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <atltime.h>
#include <io.h>
#include <vector>
#include "hook/ms2hook.h"

static UICommon::CMyPCKeyInputController s_keyInputController;

// ---- unit-local placeholders and externals ----

// The AS controls of the movie. Slot 24 is the one the dialog calls.
class Unk_RankCtl : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(int n);
};
// "m_items" / "m_mainCategory": the lists.
class Unk_RankList : public Unk_RankCtl
{
public:
    void FUN_1422dd1d0();                                   // clear
    void FUN_1422dcca0(int n);
    void FUN_1422e17f0(int n);
    void FUN_1422dd230(const ASObj& row);                   // append a row
};
// "m_tab": the season tab strip.
class Unk_RankTab : public Unk_RankCtl
{
public:
    void FUN_1422e31e0(int n);                              // select
    void FUN_1422e3400();                                   // clear
    void FUN_1422e2db0(const Scaleform::GFx::Value& data);  // set the data provider
    int FUN_1422e3210();                                    // the selected tab index
};
// "m_searchInput": the search text input.
class Unk_RankInput : public ASDisplayObject
{
public:
    CStringW FUN_1422e0b00();                               // the text
};
int FUN_1422c76c0(Unk_RankInput* p);                        // the input has the focus

// The AS array (ctor 0x1422deec0, dtor 0x1422df070) of the tab objects.
class Unk_RankArray : public ASArray
{
public:
    Unk_RankArray(int nType);
    virtual ~Unk_RankArray();
};

// The AS array helpers (push an int / an object).
class Unk_RankArr : public ASArray
{
public:
    void FUN_1422bbf00(const ASObj& obj);
    void FUN_1422bbc60(int n);
};
void FUN_1407cd930(Scaleform::GFx::Value* pObj, const char* szName, const Scaleform::GFx::Value& v);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);

// The root object of the movie: invoke helpers (the originals are inline COMDATs of this unit).
class Unk_RankAS : public AScript
{
public:
    Scaleform::GFx::Value FUN_140e35c60(const char* szMethod, int n);                   // @0x140e35c60
    Scaleform::GFx::Value FUN_1409ba0d0(const char* szMethod, int a1, int a2);
};
class Unk_RankMovie : public AScript
{
public:
    template <class T> MS2Ptr<T> FUN_140bbe880(const CString& strName);
};
class ASDialog : public ASDisplayObject {};

// The options / input state / flags singletons.
class Unk_RankFeature { public: bool FUN_14036d570(int); };
Unk_RankFeature* FUN_140166410();
class Unk_RankInputState { public: char FUN_14116d9c0(int a, int b, int c); };
Unk_RankInputState* FUN_14025e7c0();
class Unk_RankFlag { public: int FUN_1402c4c90(int); };
class Unk_RankFlags { public: void* p0; Unk_RankFlag flags; };
Unk_RankFlags* FUN_14025e7b0();

// The XML loader and the string table.
struct Unk_RankStrings { CStringW FUN_141811980(int, int); };
Unk_RankStrings* FUN_1401a9d70();
CString FUN_14071a5b0(const CString&, const CString&);
struct Unk_RankFiles { int FUN_1403974b0(TiXmlDocument&, const char*, int, bool, bool); };
Unk_RankFiles* FUN_140166420();
struct Unk_RankLog { void FUN_14015eb90(int, int, const wchar_t*, const CString&); };
Unk_RankLog* FUN_140166440();
void* FUN_140165cf0(void*, const char*);
void* FUN_140168650(void*, const char*);
bool FUN_14028f710(void*);
int FUN_1408731e0(void*, const char*, int&);
int FUN_1408733e0(void*, const char*, CString&);
int FUN_140873420(void*, const char*, CStringW&);
bool FUN_140184310(const CString& str, const char* psz);
void FUN_140165270(ATL::CAtlArray<CString>&, CString&);                 // Add
void FUN_1402c2890(ATL::CAtlArray<CString>&);                           // RemoveAll
size_t FUN_1401662c0(ATL::CAtlArray<CString>&);                         // GetCount
CString& FUN_140164930(ATL::CAtlArray<CString>&, size_t nIndex);        // operator[]

// Texts.
CStringW FUN_140298ea0(CStringW);                                       // localized string by key
CStringW FUN_14062b4f0(CStringW, const int*);
CStringW FUN_14062b5a0(CStringW, const int& nJob, const CStringW& strName, const int& nLevel);
CStringW FUN_1409e8970(CStringW, const int&, const int&);
CStringW FUN_140bfa7f0(CStringW, const CStringW&, const int*);
CStringW FUN_1408f71a0(CStringW, const CStringW&, const CStringW&);
CStringW FUN_140656190(const wchar_t*, const CStringW&, const CStringW&);
CStringW FUN_1401d0160(const wchar_t*, const CStringW&);
CStringW FUN_1409404f0(__int64);
CStringW FUN_1401aa6a0(int);
CString FUN_140719530(unsigned __int64);
unsigned __int64 FUN_140718350(const CString&);
CStringW FUN_14016a730(const char*, int);
CString FUN_14016a600(const wchar_t*, int);
CString FUN_141028be0(__int64 nId, const CString& strName, int nFlag, CString strExtra);
CString FUN_141029590(unsigned __int64 nId, const CString& strKey, const CString& strName, CString strExtra);
CString FUN_1410280d0(int, CString);
CStringW FUN_14083bdc0(const ATL::CTime& t, int n, CStringW strSep, CStringW strSep2);
void FUN_1406c4760(ATL::CTime* pOut, const void* pSrc);
CStringW FUN_1409eec40(int);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void FUN_141275260(int, int, int);
__int64 FUN_141a02ed0(const CMsgBoxData* pData, int a, int b);
int FUN_141a02e50(const CMsgBoxData* pData, int a, int b);
int FUN_1418fd330(__int64 nOwner);
int FUN_1418fd740(__int64 nParam, __int64 nId, int nType);
typedef Delegate<bool(int, const CMsgBoxData&)> Unk_RankMsgCallback;
void FUN_1418fde20(__int64 nId0, __int64 nId1, int nValue, const CStringW& strArg, Unk_RankMsgCallback cb);

// The chart tables and the season table behind the boards.
class Unk_RankChartRec : public CPtred
{
public:
    char m_pad_18[0x138];
    CString m_strImage;                                     // +0x150
    char m_pad_158[8];
    int m_nKind;                                            // +0x160
    int m_nId;                                              // +0x164
    int FUN_14031ddd0();
};
MS2_CHECK_OFFSET(Unk_RankChartRec, m_nKind, 0x160);
typedef MS2Ptr<Unk_RankChartRec> Unk_RankChartPtr;
typedef ATL::CAtlList<Unk_RankChartPtr> Unk_RankChartList;
class Unk_RankChartMgr { public: void FUN_140321210(Unk_RankChartList& list, int nKind); };
Unk_RankChartMgr* FUN_14031c2a0();
void FUN_140222be0(ATL::CAtlArray<int>& arr);               // the job ids
class Unk_RankArcade : public CPtred
{
public:
    int m_nId;                                              // +0x18
    char m_pad_1c[4];
    CStringW m_strImage;                                    // +0x20
    int m_nMap;                                             // +0x28
    char m_bOpen;                                           // +0x2c
};
typedef MS2Ptr<Unk_RankArcade> Unk_RankArcadePtr;
class Unk_RankArcadeTable { public: void FUN_1401a3a00(std::vector<Unk_RankArcadePtr>& out); };
extern Unk_RankArcadeTable* DAT_143ac5c38;
class Unk_RankMapInfo : public CPtred {};
class Unk_RankMapTable { public: MS2Ptr<Unk_RankMapInfo> FUN_140429930(int nId); };
void* FUN_140302b00();
Unk_RankMapTable* FUN_1403ecfe0(void*);
class Unk_RankJobTable;
int FUN_140644bb0(Unk_RankJobTable* p, int nId);
Unk_RankJobTable* FUN_1401d7a50();
void FUN_140bd0d90(ASObj* pObj, const char* szName, int n);

class Unk_RankSeasonTable
{
public:
    void FUN_1407920d0(int nKind, ATL::CAtlArray<Unk_RankSeasonPtr>& out);
    void FUN_140792250(int nKind, ATL::CAtlArray<Unk_RankSeasonPtr>& out);
    CStringW FUN_1407925e0(Unk_RankSeasonPtr sp, int nIndex);
};
Unk_RankSeasonTable* FUN_1404f4540();
int FUN_140b3f460(int nType);

// The recommender record (the mentor of the local player).
class Unk_RankRecInfo : public CPtred
{
public:
    char m_pad_18[8];
    unsigned __int64 m_nAccount;                            // +0x20
    CStringW m_strName;                                     // +0x28
};
class Unk_RankEventMgr { public: MS2Ptr<Unk_RankRecInfo> FUN_1404786b0(int n); };
Unk_RankEventMgr* FUN_1401c0d90();
class PC;
class PCBase;
CStringW* FUN_141656be0(PCBase* pPc);                       // guild name
class Unk_RankPlayerMgr { public: PCBase* FUN_141bd0cc0(); };
Unk_RankPlayerMgr* FUN_1403ed2d0();
class Unk_RankUiMgr { public: int FUN_1422d4e20(const CString& strKey); };
Unk_RankUiMgr* FUN_140b632f0();

// Popup menu parameters (uipartysearchdialog.cpp).
class Unk_RankMenuInfo
{
public:
    void FUN_140c302f0(float x, float y, int nKind, int nMenuId, int a5, CString strKey, void* p);
    void FUN_140c304c0();
    unsigned char m_pad[0x88];
};
MS2_CHECK_SIZE(Unk_RankMenuInfo, 0x88);
class Unk_RankMenu
{
public:
    void FUN_141a7f090(Unk_RankMenuInfo& info, const CStringW& strName, __int64 nChar, unsigned __int64 nAccount, int nType, int a);
};
Unk_RankMenu* FUN_140c30140(int nUiId);

Unk_RankArcadeTable* FUN_140e37aa0();

// ---- the dialog ----

// @0x140e2cc90
UIGameRankingDialog::UIGameRankingDialog()
    : m_categories(10)
    , m_items(0)
{
    m_nCategory = 0;
    m_nPage = 0;
    m_nTab = 0;
    FUN_1422dc3b0(1);
    LoadGameRankingCategory();
}

// @0x140e2cdc0
UIGameRankingDialog::~UIGameRankingDialog()
{
    m_categories.RemoveAll();
    m_tabs.RemoveAll();
    m_rows.RemoveAll();
    m_missingMarks.RemoveAll();
}

// @0x140e2cec0
CString UIGameRankingDialog::vfunc_1()
{
    return CString("GameRankingDialog");
}

// @0x140e2cf10
int UIGameRankingDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140e2cf40
void UIGameRankingDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140e2cf60
void UIGameRankingDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_items = 0;
}

// @0x140e2cfa0
void UIGameRankingDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (!FUN_140166410()->FUN_14036d570(0x3f))
        return;
    LoadGameRankingCategory();
    FUN_140e2e540();
    FUN_140e2e620();
    FUN_1419260d0(CString("m_webGuideButton"), 0);
    m_items = FUN_140c02900(CString("m_items"));
    FUN_140e31140();
    FUN_140e33e20();
}

// @0x140e2d0d0
int UIGameRankingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    if (_stricmp("onSelectMainCategory", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_nCategory = data.FUN_1422b8a10();
            Unk_RankCatPtr spCategory = FUN_140e350c0(m_nCategory);
            if (spCategory)
            {
                if (FUN_140e32c30(spCategory->m_nId) != 0)
                {
                    if (m_30.get())
                        reinterpret_cast<Unk_RankAS*>(m_30.operator->())->FUN_140e35c60("showSearchResult", 2);
                    return 1;
                }
                FUN_140e31510(spCategory);
            }
        }
    }
    else if (_stricmp("onChangeTab", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_nTab = data.FUN_1422b8a10();
            FUN_140e31910(1);
            Unk_RankKey key;
            FUN_140e351d0(m_nCategory, &key);
            Unk_RankPageReq req = CGameRankingCli::FUN_140b2e980()->FUN_140b2add0(key, 1, 1);
            if (req.FUN_140b2e190() != 0)
                FUN_140e34ce0(1, req.FUN_140b2e220()->FUN_140b2e9c0());
            m_nPage = 1;
            FUN_140e32f30(1, 1, CStringW(L""));
        }
    }
    else if (_stricmp("OnChangePageRequest", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_nPage = data.FUN_1422b8a10();
            FUN_140e32f30(1, 0, CStringW(L""));
        }
    }
    else if (_stricmp("onSearch", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_140e34d50(CStringW(data.FUN_1422b8f40()));
    }
    else if (_stricmp("onMoveHome", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            unsigned __int64 nId0 = FUN_140718350(data.FUN_1422b8d30());
            unsigned __int64 nId1 = FUN_140718350(data.FUN_1422b8d30());
            CStringW strName = data.FUN_1422b8f40();
            if (FUN_1418fd330(nId1) != 0)
            {
                FUN_1418fde20(nId0, nId1, 0x11, strName, Unk_RankMsgCallback(this, &UIGameRankingDialog::FUN_140e359e0));
                return 1;
            }
        }
    }
    else if (_stricmp("onRankingMemberPopupMenu", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            float x = data.FUN_1422b8c10();
            float y = data.FUN_1422b8c10();
            unsigned __int64 nAccount = FUN_140718350(data.FUN_1422b8d30());
            unsigned __int64 nChar = FUN_140718350(data.FUN_1422b8d30());
            CStringW strName = data.FUN_1422b8f40();
            Unk_RankMenu* pMenu = FUN_140c30140(0x4e39);
            if (pMenu != 0)
            {
                Unk_RankMenuInfo info;
                info.FUN_140c302f0(x, y, 3, 2, 0, CString(""), 0);
                pMenu->FUN_141a7f090(info, strName, nChar, nAccount, 0x11, 0);
                info.FUN_140c304c0();
            }
        }
    }
    return 1;
}

// @0x140e2da50
int UIGameRankingDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() == 0)
    {
        if (vfunc_55() == 0 && !m_30.IsNull())
        {
            ASDialog* pDlg = dynamic_cast<ASDialog*>(static_cast<AScript*>(m_30));
            if (pDlg != 0)
            {
                if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
                {
                    if (FUN_140b632f0() != 0)
                    {
                        CString strKey(m_20);
                        if (FUN_140b632f0()->FUN_1422d4e20(strKey) == 0)
                            return 0;
                    }
                }
                MS2Ptr<Unk_RankInput> spInput = FUN_140e35bd0(CString("m_searchInput"));
                if (spInput.get() != 0)
                {
                    if (FUN_1422c76c0(spInput.operator->()) != 0)
                        FUN_140e34d50(spInput->FUN_1422e0b00());
                }
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

// @0x140e2dc70
void UIGameRankingDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    CString strName = pArgs->FUN_1422b8d30();
    int nRow = pArgs->FUN_1422b8a10();
    int nType = pArgs->FUN_1422b8a10();
    if (FUN_140184310(strName, "m_pbname"))
        FUN_140e355d0(pRetVal, nRow, nType);
}

// @0x140e2dd00
int UIGameRankingDialog::vfunc_73()
{
    if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x32) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    return UIDialog::vfunc_73();
}

// @0x140e2dd60
void UIGameRankingDialog::vfunc_72()
{
    if (m_missingMarks.GetCount() > 0)
    {
        int bAll = 1;
        for (size_t i = 0; i < m_missingMarks.GetCount(); i++)
        {
            if (_waccess(CStringW(FUN_14016a730(m_missingMarks[i], 0)), 4) != 0)
                bAll = 0;
        }
        if (bAll)
        {
            m_missingMarks.RemoveAll();
            FUN_140e32f30(1, 1, CStringW(L""));
        }
    }
}

// @0x140e2dec0
void UIGameRankingDialog::FUN_140e2dec0(int nMsg)
{
    switch (nMsg)
    {
    case 0x3ee:
        if (m_30.get())
            reinterpret_cast<Unk_RankAS*>(m_30.operator->())->FUN_140e35c60("showSearchResult", 0);
        break;
    case 0x457:
        FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, CStringW(L""));
        break;
    }
}

// @0x140e2dfc0
void UIGameRankingDialog::FUN_140e2dfc0(int nType, int nSub)
{
    int nId = FUN_140e354d0(nType, nSub);
    if (nId == 0)
        return;
    if (FUN_140e32c30(nId) != 0)
        nId += 10;
    m_nCategory = nId;
}

// @0x140e2e030
void UIGameRankingDialog::FUN_140e2e030(CString strUrl)
{
    strUrl.MakeLower();
    if (strUrl.Find("/rank/", 0) == -1)
        return;
    POSITION pos = m_categories.GetHeadPosition();
    while (pos != 0)
    {
        Unk_RankCatPtr spCategory(m_categories.GetAt(pos));
        if (spCategory)
        {
            if (!spCategory->m_strUrl.IsEmpty())
            {
                if (strUrl.Find(spCategory->m_strUrl, 0) != -1)
                {
                    if (FUN_140e32c30(spCategory->m_nId) == 0)
                        m_nCategory = spCategory->m_nId;
                    else
                        m_nCategory = spCategory->m_nId + 10;
                    return;
                }
            }
        }
        m_categories.GetNext(pos);
    }
}

// @0x140e2e1d0
void UIGameRankingDialog::LoadGameRankingCategory()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("gameRankingCategory.xml"));
    m_categories.RemoveAll();
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(doc, strPath, 0, true, false) == 0)
        return;
    void* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (void* pNode = FUN_140165cf0(pRoot, "gameRankingCategory"); pNode != 0; pNode = FUN_140168650(pNode, "gameRankingCategory"))
    {
        CStringW strFeature;
        FUN_140873420(pNode, "feature", strFeature);
        if (!FUN_14028f710(pNode))
            continue;
        Unk_RankCatPtr spCategory((Unk_RankNewTag(0)));
        FUN_1408731e0(pNode, "categoryid", spCategory->m_nId);
        FUN_1408731e0(pNode, "type", spCategory->m_nType);
        FUN_1408733e0(pNode, "url", spCategory->m_strUrl);
        spCategory->m_strUrl.MakeLower();
        spCategory->m_strLabel = FUN_1401a9d70()->FUN_141811980(0x34, spCategory->m_nType);
        FUN_140e305a0(spCategory);
    }
}

// @0x140e2e540
void UIGameRankingDialog::FUN_140e2e540()
{
    if (m_categories.IsEmpty())
        return;
    Unk_RankCatPtr spCategory(m_categories.GetHead());
    if (spCategory)
    {
        if (m_nCategory == 0)
        {
            if (FUN_140e32c30(spCategory->m_nId) != 0)
                m_nCategory = spCategory->m_nId + 10;
            else
                m_nCategory = spCategory->m_nId;
        }
    }
}

#define RANK_ADD_TAB(box, key) \
    (box)->Add(FUN_140e304c0(FUN_140298ea0(CStringW(key)), CStringW(L""), 0))

#define RANK_BOSS_TABS(box) \
    RANK_ADD_TAB(box, L"s_gameranking_tab_boss_maximum_join"); \
    RANK_ADD_TAB(box, L"s_gameranking_tab_boss_hall_of_fame"); \
    RANK_ADD_TAB(box, L"s_gameranking_tab_boss_shortest_time")

// @0x140e2e620
void UIGameRankingDialog::FUN_140e2e620()
{
    Unk_RankTabsPtr sp3((Unk_RankNewTag(0)));
    m_tabs.SetAt(3, sp3);

    Unk_RankTabsPtr sp7((Unk_RankNewTag(0)));
    RANK_BOSS_TABS(sp7);
    m_tabs.SetAt(7, sp7);

    Unk_RankTabsPtr sp8((Unk_RankNewTag(0)));
    RANK_BOSS_TABS(sp8);
    m_tabs.SetAt(8, sp8);

    Unk_RankTabsPtr sp9((Unk_RankNewTag(0)));
    RANK_BOSS_TABS(sp9);
    m_tabs.SetAt(9, sp9);

    Unk_RankTabsPtr spF((Unk_RankNewTag(0)));
    RANK_BOSS_TABS(spF);
    m_tabs.SetAt(0xf, spF);

    Unk_RankTabsPtr sp11((Unk_RankNewTag(0)));
    RANK_BOSS_TABS(sp11);
    m_tabs.SetAt(0x11, sp11);

    Unk_RankTabsPtr spB((Unk_RankNewTag(0)));
    RANK_ADD_TAB(spB, L"s_gameranking_tab_worldboss_maximum_join");
    RANK_ADD_TAB(spB, L"s_gameranking_tab_worldboss_hall_of_fame");
    RANK_ADD_TAB(spB, L"s_gameranking_tab_worldboss_damage");
    m_tabs.SetAt(0xb, spB);

    Unk_RankTabsPtr spC((Unk_RankNewTag(0)));
    RANK_ADD_TAB(spC, L"s_gameranking_tab_famechallenge_maximum_join");
    RANK_ADD_TAB(spC, L"s_gameranking_tab_famechallenge_hall_of_fame");
    RANK_ADD_TAB(spC, L"s_gameranking_tab_famechallenge_shortest_time");
    m_tabs.SetAt(0xc, spC);

    Unk_RankTabsPtr sp10((Unk_RankNewTag(0)));
    m_tabs.SetAt(10, sp10);
    Unk_RankTabsPtr sp4((Unk_RankNewTag(0)));
    m_tabs.SetAt(4, sp4);
    Unk_RankTabsPtr sp5((Unk_RankNewTag(0)));
    m_tabs.SetAt(5, sp5);
    Unk_RankTabsPtr sp6((Unk_RankNewTag(0)));
    m_tabs.SetAt(6, sp6);

    Unk_RankTabsPtr sp1((Unk_RankNewTag(0)));
    RANK_ADD_TAB(sp1, L"s_gameranking_tab_guild_trophy");
    m_tabs.SetAt(1, sp1);

    Unk_RankTabsPtr sp2((Unk_RankNewTag(0)));
    RANK_ADD_TAB(sp2, L"s_gameranking_tab_individual_trophy");
    m_tabs.SetAt(2, sp2);

    Unk_RankTabsPtr spE((Unk_RankNewTag(0)));
    m_tabs.SetAt(0xe, spE);
    Unk_RankTabsPtr sp16((Unk_RankNewTag(0)));
    m_tabs.SetAt(0x10, sp16);
}

// @0x140e304c0
Unk_RankTabPtr UIGameRankingDialog::FUN_140e304c0(CStringW strLabel, CStringW strTooltip, int nSeason)
{
    Unk_RankTabPtr spTab((Unk_RankNewTag(0)));
    spTab->m_strLabel = strLabel;
    spTab->m_strTooltip = strTooltip;
    spTab->m_nSeasonID = nSeason;
    return spTab;
}

// @0x140e305a0
void UIGameRankingDialog::FUN_140e305a0(Unk_RankCatPtr spCategory)
{
    if (spCategory != 0)
    {
        int nSubIdx = 1;
        int nType = spCategory->m_nType;
        int nId = spCategory->m_nId;
        if (nType == 3 || nType == 0xe || nType == 0x10)
        {
            ATL::CAtlArray<int> aJobs;
            FUN_140222be0(aJobs);
            if (aJobs.GetCount() == 0)
                return;
            if (nType == 0x10)
            {
                Unk_RankChartList list(10);
                FUN_14031c2a0()->FUN_140321210(list, 0xd);
                if (list.GetCount() == 0)
                    return;
            }
            m_categories.AddTail(spCategory);
            for (size_t i = 0; i < aJobs.GetCount(); i++)
            {
                int nJob = aJobs[i];
                if (nJob != 0 && nJob != 1)
                {
                    int nOffset = nSubIdx * 10;
                    nSubIdx++;
                    Unk_RankCatPtr spSub((Unk_RankNewTag(0)));
                    spSub->m_nId = nId + nOffset;
                    spSub->m_nSub = nJob;
                    spSub->m_strLabel = FUN_1401a9d70()->FUN_141811980(0x4d, spSub->m_nSub);
                    spSub->m_strImage = L"";
                    spSub->m_nParent = nId;
                    spSub->m_nType = nType;
                    m_categories.AddTail(spSub);
                }
            }
        }
        else if (nType == 7 || nType == 8 || nType == 9 || nType == 0xb || nType == 0xc || nType == 0xf || nType == 0x11)
        {
            int nKind = 2;
            switch (nType)
            {
            case 7: nKind = 2; break;
            case 8: nKind = 3; break;
            case 9: nKind = 4; break;
            case 0xb: nKind = 8; break;
            case 0xc: nKind = 0xc; break;
            case 0xf: nKind = 5; break;
            case 0x11: nKind = 0xe;
            }
            Unk_RankChartList list(10);
            FUN_14031c2a0()->FUN_140321210(list, nKind);
            if (list.GetCount() == 0)
                return;
            m_categories.AddTail(spCategory);
            POSITION pos = list.GetHeadPosition();
            while (pos != 0)
            {
                Unk_RankChartPtr spRec(list.GetAt(pos));
                if (!spRec)
                    return;
                int nOffset = nSubIdx * 10;
                nSubIdx++;
                CStringW strLabel;
                if ((nType == 0xf && spRec->m_nKind == 4) || (nType == 0x11 && spRec->m_nKind == 4))
                    strLabel = FUN_1401a9d70()->FUN_141811980(0x14, spRec->FUN_14031ddd0());
                else
                    strLabel = FUN_1401aa6a0(spRec->m_nId);
                Unk_RankCatPtr spSub((Unk_RankNewTag(0)));
                spSub->m_nId = nId + nOffset;
                spSub->m_nSub = spRec->m_nId;
                spSub->m_strLabel = strLabel;
                spSub->m_strImage = (const char*)spRec->m_strImage;
                spSub->m_nParent = nId;
                spSub->m_nType = nType;
                m_categories.AddTail(spSub);
                list.GetNext(pos);
            }
        }
        else if (nType == 10)
        {
            std::vector<Unk_RankArcadePtr> aArcade;
            FUN_140e37aa0()->FUN_1401a3a00(aArcade);
            if (aArcade.size() == 0)
                return;
            m_categories.AddTail(spCategory);
            for (size_t i = 0; i < aArcade.size(); i++)
            {
                Unk_RankArcadePtr spRec(aArcade[i]);
                if (spRec == 0)
                    continue;
                if (spRec->m_nMap == 0)
                    continue;
                if (spRec->m_bOpen == 1)
                {
                    if (FUN_1403ecfe0(FUN_140302b00())->FUN_140429930(spRec->m_nId) == 0)
                        continue;
                }
                int nOffset = nSubIdx * 10;
                nSubIdx++;
                Unk_RankCatPtr spSub((Unk_RankNewTag(0)));
                spSub->m_nId = nId + nOffset;
                spSub->m_nSub = spRec->m_nId;
                spSub->m_strLabel = FUN_1401a9d70()->FUN_141811980(0x20, spSub->m_nSub);
                spSub->m_strImage = FUN_1401d0160(L"./Data/Resource/Image/Map/Arcade/", spRec->m_strImage);
                spSub->m_nParent = nId;
                spSub->m_nType = 10;
                m_categories.AddTail(spSub);
            }
        }
        else
        {
            m_categories.AddTail(spCategory);
        }
    }
}

// @0x140e31140
void UIGameRankingDialog::FUN_140e31140()
{
    MS2Ptr<Unk_RankList> spList = FUN_140c02900(CString("m_mainCategory"));
    if (!(spList.get()))
        return;
    spList->FUN_1422dd1d0();
    ASObj root(2);
    ASArray nodes(2);
    ATL::CAtlList<Unk_RankCatPtr> top(10);
    FUN_140e32d30(top);
    POSITION pos = top.GetHeadPosition();
    while (pos != 0)
    {
        Unk_RankCatPtr spCat(top.GetAt(pos));
        if (spCat)
        {
            ASObj node(2);
            ASArray sub(2);
            node.FUN_1407cbb20("label", CStringW(spCat->m_strLabel));
            node.FUN_140e35da0("rankType", spCat->m_nType);
            if (FUN_140e32c30(spCat->m_nId) == 0)
            {
                node.FUN_140e35d00("type", 0);
            }
            else
            {
                FUN_140e32a00(Unk_RankCatPtr(spCat), sub);
                node.FUN_140e35d00("type", 1);
                node.FUN_1409eb1d0("nodes", sub);
            }
            node.FUN_1407cb9c0("id", spCat->m_nId);
            node.FUN_1409c0dc0("rendererClassName", "export_renderer_category");
            static_cast<Unk_RankArr&>(nodes).FUN_1422bbf00(node);
        }
        top.GetNext(pos);
    }
    root.FUN_140e35d00("type", 1);
    root.FUN_1409eb1d0("nodes", nodes);
    if (m_30.get())
        reinterpret_cast<Unk_RankAS*>(m_30.operator->())->Invoke("setList", root);
}

// @0x140e31510
void UIGameRankingDialog::FUN_140e31510(Unk_RankCatPtr spCategory)
{
    Unk_RankArray aTabs(2);
    MS2Ptr<Unk_RankTab> spTab = FUN_140c02870(CString("m_tab"));
    if (!spTab)
        return;
    spTab->FUN_1422e31e0(-1);
    spTab->FUN_1422e3400();
    spTab->vfunc_24(1);
    int nType = spCategory->m_nType;
    Unk_RankTabsPtr spTabs = FUN_140e33240(Unk_RankCatPtr(spCategory));
    for (size_t i = 0; i < spTabs->GetCount(); i++)
    {
        Unk_RankTabPtr spData = FUN_140e339e0(nType, (int)i);
        if (spData)
        {
            ASObj item(2);
            item.FUN_1407cbb20("label", CStringW(spData->m_strLabel));
            item.FUN_1407cb9c0("seasonID", spData->m_nSeasonID);
            ASObj tip(2);
            tip.FUN_1409c0dc0("className", "export_common_tooltip_tooltipText");
            tip.FUN_1407cbb20("id", CStringW(spData->m_strTooltip));
            tip.FUN_1409c0dc0("align", "topLeft");
            item.FUN_1409eb270("tooltipData", tip);
            aTabs.FUN_1422bc050(Scaleform::GFx::Value(item.FUN_1422bb870()));
        }
    }
    spTab->FUN_1422e2db0(aTabs.FUN_1422bb870());
    spTab->FUN_1422e31e0(0);
    m_nTab = spTab->FUN_1422e3210();
}

// @0x140e31910
void UIGameRankingDialog::FUN_140e31910(int nFlag)
{
    ASObj info(2);
    Unk_RankCatPtr spCat = FUN_140e350c0(m_nCategory);
    if (spCat)
    {
        info.FUN_140e35da0("type", spCat->m_nType);
        FUN_140e33fb0(info, Unk_RankCatPtr(spCat), nFlag);
        FUN_140e34830(info, Unk_RankCatPtr(spCat));
        FUN_140e34bb0(info, Unk_RankCatPtr(spCat));
        if (m_30.get())
            reinterpret_cast<Unk_RankAS*>(m_30.operator->())->Invoke("setRankInfo", Scaleform::GFx::Value(info.FUN_1422bb870()));
    }
}

#define RANK_ROW (m_rows[i].FUN_140b2e1e0())

// @0x140e31b00
void UIGameRankingDialog::FUN_140e31b00()
{
    Unk_RankCatPtr spCat = FUN_140e350c0(m_nCategory);
    if (!spCat)
        return;
    FUN_1402c2890(m_missingMarks);
    for (size_t i = 0; i < m_rows.GetCount(); i++)
    {
        ASObj row(2);
        if (RANK_ROW->m_nRankType != 0)
            row.FUN_1407cb9c0("ranktype", RANK_ROW->m_nRankType);
        if (RANK_ROW->m_nRank != 0)
            row.FUN_1407cb9c0("rank", RANK_ROW->m_nRank);
        if (RANK_ROW->m_nPoint != 0)
            row.FUN_1407cbb20("point", FUN_1409404f0(RANK_ROW->m_nPoint));
        if (RANK_ROW->m_nPvpGrade != 0)
            row.FUN_1407cb9c0("pvpGrade", RANK_ROW->m_nPvpGrade);
        if (!RANK_ROW->m_cname.IsEmpty())
            row.FUN_1407cbb20("cname", CStringW(RANK_ROW->m_cname));
        if (!RANK_ROW->m_pbname.IsEmpty())
            row.FUN_1407cbb20("pbname", CStringW(RANK_ROW->m_pbname));
        if (!RANK_ROW->m_gname.IsEmpty())
            row.FUN_1407cbb20("gname", CStringW(RANK_ROW->m_gname));
        if (!RANK_ROW->m_gbname.IsEmpty())
            row.FUN_1407cbb20("gbname", CStringW(RANK_ROW->m_gbname));
        if (!RANK_ROW->m_registerationDate.IsEmpty())
            row.FUN_1407cbb20("registerationDate", CStringW(RANK_ROW->m_registerationDate));
        if (!RANK_ROW->m_attackTime.IsEmpty())
            row.FUN_1407cbb20("attackTime", CStringW(RANK_ROW->m_attackTime));
        if (!RANK_ROW->m_pvpGradeName.IsEmpty())
            row.FUN_1407cbb20("pvpGradeName", CStringW(RANK_ROW->m_pvpGradeName));
        if (!RANK_ROW->m_markFile.IsEmpty())
        {
            CString strUrl;
            CString strSub;
            if (RANK_ROW->m_nMarkId == 0)
            {
                strUrl = FUN_141028be0(RANK_ROW->m_nCharSN, FUN_14016a600(RANK_ROW->m_markFile, 0), 1, CString(""));
                strSub = FUN_1410280d0(5, FUN_14016a600(RANK_ROW->m_markFile, 0));
            }
            else
            {
                strUrl = FUN_141029590(RANK_ROW->m_nMarkId, FUN_14016a600(RANK_ROW->m_markFile, 0), CString(""), CString(""));
                strSub = FUN_1410280d0(6, FUN_14016a600(RANK_ROW->m_markFile, 0));
            }
            if (_waccess(FUN_14016a730(strSub, 0), 4) != 0)
                FUN_140165270(m_missingMarks, strSub);
            row.FUN_1407cba60("markURL", CString(strUrl));
        }
        if (!RANK_ROW->m_homename.IsEmpty())
            row.FUN_1407cbb20("homename", CStringW(RANK_ROW->m_homename));
        if (RANK_ROW->m_nAccountSN != 0)
            row.FUN_1407cba60("accountSN", FUN_140719530(RANK_ROW->m_nAccountSN));
        if (RANK_ROW->m_nCharSN != 0)
            row.FUN_1407cba60("charSN", FUN_140719530(RANK_ROW->m_nCharSN));
        if (RANK_ROW->m_nRankPoint != 0)
            row.FUN_1407cba60("rankPoint", FUN_140719530((__int64)RANK_ROW->m_nRankPoint));
        m_items->FUN_1422dd230(row);
    }
    m_items->vfunc_24(1);
}

// @0x140e32a00
void UIGameRankingDialog::FUN_140e32a00(Unk_RankCatPtr spCategory, ASArray& arr)
{
    ATL::CAtlList<Unk_RankCatPtr> list(10);
    FUN_140e32df0(list);
    POSITION pos = list.GetHeadPosition();
    while (pos != 0)
    {
        Unk_RankCatPtr spSub(list.GetAt(pos));
        if (spSub)
        {
            if (spSub->m_nParent == spCategory->m_nId)
            {
                ASObj node(2);
                node.FUN_1407cb9c0("id", spSub->m_nId);
                node.FUN_1407cbb20("label", CStringW(spSub->m_strLabel));
                node.FUN_140e35da0("rankType", spSub->m_nType);
                node.FUN_140e35d00("type", 0);
                node.FUN_1409c0dc0("rendererClassName", "export_renderer_category_low");
                static_cast<Unk_RankArr&>(arr).FUN_1422bbf00(node);
            }
        }
        list.GetNext(pos);
    }
}

// @0x140e32c30
int UIGameRankingDialog::FUN_140e32c30(int nCategoryId)
{
    ATL::CAtlList<Unk_RankCatPtr> list(10);
    FUN_140e32df0(list);
    for (POSITION pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos))
    {
        Unk_RankCatPtr spSub(list.GetAt(pos));
        if (spSub)
        {
            if (spSub->m_nParent == nCategoryId)
                return 1;
        }
    }
    return 0;
}

// @0x140e32d30
void UIGameRankingDialog::FUN_140e32d30(ATL::CAtlList<Unk_RankCatPtr>& list)
{
    for (POSITION pos = m_categories.GetHeadPosition(); pos != 0; m_categories.GetNext(pos))
    {
        Unk_RankCatPtr spCat(static_cast<const Unk_RankCatPtr&>(m_categories.GetAt(pos)));
        if (spCat != 0 && spCat->m_nParent == 0)
            list.AddTail(spCat);
    }
}

// @0x140e32df0
void UIGameRankingDialog::FUN_140e32df0(ATL::CAtlList<Unk_RankCatPtr>& list)
{
    for (POSITION pos = m_categories.GetHeadPosition(); pos != 0; m_categories.GetNext(pos))
    {
        Unk_RankCatPtr spCat(static_cast<const Unk_RankCatPtr&>(m_categories.GetAt(pos)));
        if (spCat != 0 && spCat->m_nParent != 0)
            list.AddTail(spCat);
    }
}

// @0x140e32eb0
void UIGameRankingDialog::FUN_140e32eb0()
{
    m_rows.RemoveAll();
    if (m_items == 0)
        return;
    m_items->FUN_1422dd1d0();
    m_items->FUN_1422dcca0(-1);
}

// @0x140e32f30
void UIGameRankingDialog::FUN_140e32f30(int nPush, int nForce, CStringW strSearch)
{
    FUN_140e32eb0();
    Unk_RankKey key;
    FUN_140e351d0(m_nCategory, &key);
    if (m_30.get())
        reinterpret_cast<Unk_RankAS*>(m_30.operator->())->FUN_140e35c60("showSearchResult", 1);
    if (CGameRankingCli::FUN_140b2e980()->FUN_140b2b440(key, m_nPage, m_rows, CStringW(strSearch), nForce) == 1)
    {
        if (nPush == 1)
            FUN_140e31b00();
    }
    else if (nForce == 1 && strSearch.GetLength() == 0)
    {
        CGameRankingParam param;
        param.m_key.FUN_140b35820(key);
        param.m_search = strSearch;
        CGameRankingCli::FUN_140b2e980()->FUN_140b2bf30(&param);
    }
    if (strSearch.GetLength() == 0)
    {
        Unk_RankKey key2;
        FUN_140e35350(m_nCategory, &key2);
        Unk_RankInfoPtr info = CGameRankingCli::FUN_140b2e980()->FUN_140b2ac30(key2, nForce);
        if (info.FUN_140b2e080(0))
        {
            void* pCached = CGameRankingCli::FUN_140b2e980()->FUN_140b2c6f0(key2.FUN_140b357e0());
            if (pCached != 0)
            {
                CGameRankingParam param2;
                param2.m_key.FUN_140b35820(key2);
                param2.m_38 = pCached;
                CGameRankingCli::FUN_140b2e980()->FUN_140b2bf30(&param2);
            }
        }
    }
}

// @0x140e33240
Unk_RankTabsPtr UIGameRankingDialog::FUN_140e33240(Unk_RankCatPtr spCategory)
{
    if (spCategory != 0)
    {
        int nType = spCategory->m_nType;
        int nKind = FUN_140b3f460(nType);
        ATL::CAtlArray<Unk_RankSeasonPtr> aSeasons;
        FUN_1404f4540()->FUN_1407920d0(nKind, aSeasons);
        Unk_RankTabsPtr spTabs((Unk_RankNewTag(0)));
        m_tabs.Lookup(nType, spTabs);
        if (nKind == -1)
            return spTabs;
        spTabs->RemoveAll();
        if (nType == 0xe)
        {
            if (aSeasons.GetCount() == 0)
            {
                FUN_1404f4540()->FUN_140792250(nKind, aSeasons);
                spTabs->Add(FUN_140e304c0(FUN_140298ea0(CStringW(L"s_gameranking_tab_off_season")), CStringW(L""), 0));
            }
        }
        for (size_t i = 0; i < aSeasons.GetCount(); i++)
        {
            Unk_RankSeasonPtr spSeason(aSeasons[i]);
            CStringW strLabel = FUN_140e33ae0(Unk_RankCatPtr(spCategory), Unk_RankSeasonPtr(spSeason));
            ATL::CTime tStart;
            ATL::CTime tEnd;
            FUN_1406c4760(&tStart, &spSeason.FUN_1404f0bf0()->m_start);
            FUN_1406c4760(&tEnd, &spSeason.FUN_1404f0bf0()->m_end);
            tEnd -= ATL::CTimeSpan(1);
            CStringW strStart = FUN_14083bdc0(tStart, 1, CStringW(L"/"), CStringW(L":"));
            CStringW strEnd = FUN_14083bdc0(tEnd, 1, CStringW(L"/"), CStringW(L":"));
            strStart = strStart.Left(strStart.GetLength() - 3);
            strEnd = strEnd.Left(strEnd.GetLength() - 3);
            CStringW strRange = FUN_140656190(L"{0} ~ {1}", strStart, strEnd);
            spTabs->Add(FUN_140e304c0(CStringW(strLabel), CStringW(strRange), spSeason.FUN_1404f0bf0()->m_nSeason));
        }
        return spTabs;
    }
    return Unk_RankTabsPtr(0);
}

// @0x140e339e0
Unk_RankTabPtr UIGameRankingDialog::FUN_140e339e0(int nType, int nIndex)
{
    Unk_RankTabsPtr spTabs;
    Unk_RankTabPtr spTab(0);
    m_tabs.Lookup(nType, spTabs);
    if (spTabs->GetCount() > (size_t)nIndex)
        spTab = (*spTabs.operator->())[nIndex];
    return spTab;
}

// @0x140e33ae0
CStringW UIGameRankingDialog::FUN_140e33ae0(Unk_RankCatPtr spCategory, Unk_RankSeasonPtr spSeason)
{
    if (!spSeason.FUN_1404f01a0(0) && !(spCategory == 0))
    {
        int nType = spCategory->m_nType;
        CStringW strLabel(L"");
        if (nType == 6)
        {
            int nYear = spSeason.FUN_1404f0bf0()->m_nSeason / 100;
            int nSeason = spSeason.FUN_1404f0bf0()->m_nSeason % 100;
            strLabel = FUN_1409e8970(CStringW(L"s_gameranking_tab_ugc_season"), nYear, nSeason);
        }
        else if (nType == 0x10)
        {
            int nSeason = spSeason.FUN_1404f0bf0()->m_nSeason % 100;
            strLabel = FUN_14062b4f0(CStringW(L"s_gameranking_tab_bosscolosseum_season"), &nSeason);
        }
        else
        {
            strLabel = FUN_1404f4540()->FUN_1407925e0(Unk_RankSeasonPtr(spSeason), spCategory->m_nSub);
        }
        return strLabel;
    }
    return CStringW(L"");
}

// @0x140e33e20
void UIGameRankingDialog::FUN_140e33e20()
{
    MS2Ptr<Unk_RankList> spList = FUN_140c02900(CString("m_mainCategory"));
    if (spList.get())
    {
        int nIndex = 0;
        POSITION pos = m_categories.GetHeadPosition();
        while (pos != 0)
        {
            Unk_RankCatPtr spCat(static_cast<const Unk_RankCatPtr&>(m_categories.GetAt(pos)));
            if (spCat && spCat->m_nId == m_nCategory)
            {
                spList->FUN_1422dcca0(nIndex);
                spList->FUN_1422e17f0(nIndex);
                return;
            }
            m_categories.GetNext(pos);
            nIndex++;
        }
    }
}

// @0x140e33fb0
void UIGameRankingDialog::FUN_140e33fb0(ASObj& obj, Unk_RankCatPtr spCategory, int nFlag)
{
    Unk_RankKey key;
    FUN_140e35350(spCategory->m_nId, &key);
    Unk_RankInfoPtr info = CGameRankingCli::FUN_140b2e980()->FUN_140b2ac30(key, nFlag);
    int nRank;
    if (info.FUN_140b2e180() == 0)
        nRank = 0;
    else
        nRank = info.FUN_140b2e210()->vfunc_3();
    int nKeyType = key.FUN_140b357e0();
    MS2Ptr<Unk_RankRecInfo> spRec = FUN_1401c0d90()->FUN_1404786b0(1);
    if (spRec.get() == 0 || nKeyType != 6)
    {
        obj.FUN_1407cbbe0("recommender", false);
    }
    else
    {
        obj.FUN_1407cbbe0("recommender", true);
        obj.FUN_1407cbb20("recommenderName", CStringW(spRec->m_strName));
        obj.FUN_1407cba60("recommenderAccountSN", FUN_140719530(spRec->m_nAccount));
    }
    switch (nKeyType - 1)
    {
    case 0:
    case 4:
        if (nRank == 0)
        {
            obj.FUN_1407cbb20("rankText", FUN_140298ea0(CStringW(L"s_gameranking_tab_no_rank")));
        }
        else
        {
            PCBase* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPc != 0)
            {
                CStringW strGuild(*FUN_141656be0(pPc));
                if (strGuild.IsEmpty())
                    obj.FUN_1407cbb20("rankText", FUN_140298ea0(CStringW(L"s_gameranking_tab_no_rank")));
                else
                    obj.FUN_1407cbb20("rankText", FUN_140bfa7f0(CStringW(L"s_gameranking_tab_guild_rank"), strGuild, &nRank));
            }
        }
        break;
    case 1:
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xe:
    case 0xf:
    case 0x10:
        if (nRank == 0)
            obj.FUN_1407cbb20("rankText", FUN_140298ea0(CStringW(L"s_gameranking_tab_no_rank")));
        else
            obj.FUN_1407cbb20("rankText", FUN_14062b4f0(CStringW(L"s_gameranking_tab_my_rank"), &nRank));
        break;
    case 0xd:
        if (info.FUN_140b2e180() != 0)
        {
            if (info.FUN_140b2e210()->vfunc_2() != 0)
            {
                if (nRank < 0)
                {
                    int nPercent = -nRank;
                    obj.FUN_1407cbb20("rankText", FUN_14062b4f0(CStringW(L"s_gameranking_tab_my_rank_percent_down"), &nPercent));
                }
                else
                {
                    obj.FUN_1407cbb20("rankText", FUN_140298ea0(CStringW(L"s_gameranking_tab_my_rank_percent_up")));
                }
                break;
            }
        }
        if (nRank == 0)
            obj.FUN_1407cbb20("rankText", FUN_140298ea0(CStringW(L"s_gameranking_tab_no_rank")));
        else
            obj.FUN_1407cbb20("rankText", FUN_14062b4f0(CStringW(L"s_gameranking_tab_my_rank"), &nRank));
    }
}

// @0x140e34830
void UIGameRankingDialog::FUN_140e34830(ASObj& obj, Unk_RankCatPtr spCategory)
{
    bool bTop = spCategory->m_nParent == 0;
    CStringW strCategory(bTop ? CStringW(spCategory->m_strLabel) : FUN_1401a9d70()->FUN_141811980(0x34, spCategory->m_nType));
    CStringW strSub(spCategory->m_strLabel);
    Unk_RankTabPtr spTab;
    spTab = FUN_140e339e0(spCategory->m_nType, m_nTab);
    if (spTab)
    {
        switch (spCategory->m_nType)
        {
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 0xb:
        case 0xc:
        case 0xf:
        case 0x11:
            strSub = spTab->m_strLabel;
        }
    }
    Unk_RankKey key;
    FUN_140e351d0(spCategory->m_nId, &key);
    CStringW strDesc = FUN_1408f71a0(CStringW(L"s_gameranking_tab_description"), strCategory, strSub);
    obj.FUN_1407cbb20("desc", CStringW(strDesc));
}

// @0x140e34bb0
void UIGameRankingDialog::FUN_140e34bb0(ASObj& obj, Unk_RankCatPtr spCategory)
{
    switch (spCategory->m_nType)
    {
    case 3:
    case 0xe:
    case 0x10:
        FUN_140bd0d90(&obj, "jobImage", FUN_140644bb0(FUN_1401d7a50(), spCategory->m_nSub));
        break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xf:
    case 0x11:
        obj.FUN_1407cbb20("iconPath", CStringW(spCategory->m_strImage));
    }
}

// @0x140e34ce0
void UIGameRankingDialog::FUN_140e34ce0(int nPage, int nPages)
{
    if (m_30.get())
        reinterpret_cast<Unk_RankAS*>(m_30.operator->())->FUN_1409ba0d0("setButtonPage", nPage, nPages);
}

// @0x140e34d50
void UIGameRankingDialog::FUN_140e34d50(CStringW strSearch)
{
    if (strSearch.IsEmpty())
        return;
    Unk_RankKey key;
    FUN_140e351d0(m_nCategory, &key);
    Unk_RankPageReq req = CGameRankingCli::FUN_140b2e980()->FUN_140b2af90(key, CStringW(strSearch), 1);
    if (req.FUN_140b2e0c0(0))
    {
        CGameRankingParam param;
        param.m_key.FUN_140b35820(key);
        param.m_search = strSearch;
        CGameRankingCli::FUN_140b2e980()->FUN_140b2bf30(&param);
    }
}

// @0x140e34eb0
void UIGameRankingDialog::FUN_140e34eb0(Unk_RankPageReq spReply)
{
    if (!spReply.FUN_140b2e0c0(0))
    {
        FUN_140e32eb0();
        Unk_RankListHandle list = spReply.FUN_140b2e220()->FUN_140b3dcc0();
        if (list.FUN_140b2e170() != 0)
        {
            Unk_RankDataPtr spData((Unk_RankNewTag(0)));
            spData.FUN_140b2e1e0()->FUN_140b287b0(spReply.FUN_140b2e220()->FUN_140e37c20(), Unk_RankJson(list));
            if (spData.FUN_140b2e1e0()->m_nRank == 0)
            {
                if (m_30.get())
                    reinterpret_cast<Unk_RankAS*>(m_30.operator->())->FUN_140e35c60("showSearchResult", 0);
            }
            else
            {
                m_rows.Add(spData);
                if (m_30.get())
                    reinterpret_cast<Unk_RankAS*>(m_30.operator->())->FUN_140e35c60("showSearchResult", 1);
                FUN_140e31b00();
            }
        }
    }
}

// @0x140e350c0
Unk_RankCatPtr UIGameRankingDialog::FUN_140e350c0(int nCategoryId)
{
    for (POSITION pos = m_categories.GetHeadPosition(); pos != 0; m_categories.GetNext(pos))
    {
        Unk_RankCatPtr spCat(static_cast<const Unk_RankCatPtr&>(m_categories.GetAt(pos)));
        if (spCat)
        {
            if (spCat->m_nId == nCategoryId)
                return spCat;
        }
    }
    return Unk_RankCatPtr(0);
}

// @0x140e351d0
void UIGameRankingDialog::FUN_140e351d0(int nCategoryId, Unk_RankKey* pKey)
{
    Unk_RankCatPtr spCat = FUN_140e350c0(nCategoryId);
    if (spCat)
    {
        Unk_RankTabPtr spTab;
        spTab = FUN_140e339e0(spCat->m_nType, m_nTab);
        if (spTab == 0)
            return;
        CGameRankingCli::FUN_140b2e980()->FUN_140b2b870(pKey, spCat->m_nType, spCat->m_nSub, m_nTab, spTab->m_nSeasonID);
    }
}

// @0x140e35350
void UIGameRankingDialog::FUN_140e35350(int nCategoryId, Unk_RankKey* pKey)
{
    Unk_RankCatPtr spCat = FUN_140e350c0(nCategoryId);
    if (spCat)
    {
        Unk_RankTabPtr spTab;
        spTab = FUN_140e339e0(spCat->m_nType, m_nTab);
        if (spTab == 0)
            return;
        CGameRankingCli::FUN_140b2e980()->FUN_140b2bbf0(pKey, spCat->m_nType, spCat->m_nSub, m_nTab, spTab->m_nSeasonID);
    }
}

// @0x140e354d0
int UIGameRankingDialog::FUN_140e354d0(int nType, int nSub)
{
    for (POSITION pos = m_categories.GetHeadPosition(); pos != 0; m_categories.GetNext(pos))
    {
        Unk_RankCatPtr spCat(static_cast<const Unk_RankCatPtr&>(m_categories.GetAt(pos)));
        if (spCat != 0 && spCat->m_nType == nType && spCat->m_nSub == nSub)
            return spCat->m_nId;
    }
    return 0;
}

// @0x140e355d0
void UIGameRankingDialog::FUN_140e355d0(Scaleform::GFx::Value* pRet, int nRow, int nType)
{
    if ((size_t)nRow < m_rows.GetCount())
    {
        ASTooltip tooltip(1, 2);
        tooltip.FUN_1409c6d70(CString("export_common_tooltip_tooltipText"));
        tooltip.FUN_1409c6e00(0);
        tooltip.FUN_1409c6dc0(3);
        tooltip.FUN_1409c6e60(5);
        CStringW strText;
        if (nType == 0xc)
            strText = FUN_140298ea0(CStringW(L"s_gameranking_characterinfo"));
        else
            strText = FUN_140298ea0(CStringW(L"s_gameranking_party_member"));
        for (int i = 0; i < 10; i++)
        {
            if (!m_rows[nRow].FUN_140b2e1e0()->m_party[i].m_name.IsEmpty())
            {
                strText += FUN_14062b5a0(CStringW(L"s_gameranking_party_member_job"),
                                         m_rows[nRow].FUN_140b2e1e0()->m_party[i].m_nJob,
                                         m_rows[nRow].FUN_140b2e1e0()->m_party[i].m_name,
                                         m_rows[nRow].FUN_140b2e1e0()->m_party[i].m_nLevel);
            }
        }
        tooltip.FUN_1409c6cb0(strText);
        FUN_1409b4bc0(pRet, tooltip.FUN_1422bb870());
    }
}

// @0x140e359e0
bool UIGameRankingDialog::FUN_140e359e0(int nBtn, const CMsgBoxData& data)
{
    if (nBtn == 0)
    {
        __int64 nA = FUN_141a02ed0(&data, 0, 0);
        __int64 nB = FUN_141a02ed0(&data, 1, 0);
        int nC = FUN_141a02e50(&data, 2, 0);
        FUN_1418fd740(nA, nB, nC);
    }
    return true;
}

// ---- the inline helpers of the unit ----

// @0x140e35bd0
MS2Ptr<Unk_RankInput> UIGameRankingDialog::FUN_140e35bd0(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<Unk_RankInput>(0);
    return static_cast<Unk_RankMovie*>(m_30.operator->())->FUN_140bbe880<Unk_RankInput>(strName);
}

// @0x140e35c60
Scaleform::GFx::Value Unk_RankAS::FUN_140e35c60(const char* szMethod, int n)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bccb0(args.FUN_1409b1f70(0), n);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140e35d00
void ASObj::FUN_140e35d00(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140e35da0
void ASObj::FUN_140e35da0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140e37aa0
Unk_RankArcadeTable* FUN_140e37aa0()
{
    return DAT_143ac5c38;
}

// @0x140e37c20
int Unk_RankReply::FUN_140e37c20()
{
    return m_nRankType;
}

// ---- the data records ----

// @0x140e366f0
GameRankingCategory::GameRankingCategory()
{
    m_nType = 0;
    m_nSub = 0;
    m_nParent = 0;
    m_nId = 0;
    m_strLabel = L"";
    m_strImage = L"";
}

// @0x140e367d0
GameRankingTabData::GameRankingTabData()
{
    m_strLabel = (m_strTooltip = L"");
    m_nSeasonID = 0;
}

// @0x140e36b30
GameRankingCategory::~GameRankingCategory()
{
}

// @0x140e36b80
GameRankingTabData::~GameRankingTabData()
{
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140E2CEC0, UIGameRankingDialog, vfunc_1, 61, 0x4BBB450D);
MS2_REPLACE_METHOD(0x140E2CF40, UIGameRankingDialog, vfunc_67, 24, 0xAEA4F70C);
MS2_REPLACE_METHOD(0x140E2CF60, UIGameRankingDialog, vfunc_26, 45, 0xB6337DE6);
MS2_REPLACE_METHOD(0x140E2DC70, UIGameRankingDialog, vfunc_49, 138, 0xB87A410B);
MS2_REPLACE_METHOD(0x140E359E0, UIGameRankingDialog, FUN_140e359e0, 117, 0xF0541677);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca6720-0x142ca67d0 .text$yd

// MS2-PIN: ??0?$Unk_RankPtr@VGameRankingCategory@@@@QEAA@H@Z 0x140e363b0
// MS2-PIN: ??0?$Unk_RankPtr@VGameRankingCategory@@@@QEAA@$$QEAV0@@Z 0x140e36310
// MS2-PIN: ??0?$Unk_RankPtr@VGameRankingCategory@@@@QEAA@AEBV0@@Z 0x140e36340
