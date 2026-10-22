// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CAchieveManager: the client's achievement list (id -> CAchieve), its
// packet handler and the reward / notification texts; the achievement UI description rows (achieveDescription.xml,
// achieveSpecialRewardDescription.xml) and the achievement category tree (achieveCategory.xml) with the helpers that format
// the progress / reward strings of an achievement. The tail of the unit is ATL / MS2Ptr / fmt template glue.
// MS2-UNIT: ?\achievemanager.cpp
// MS2-RANGE: 0x1400befb0-0x1400bf220 .text$di
// MS2-RANGE: 0x140935c20-0x1409436b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?FUN_140938cd0@@YAPEAVUIRewardNotify@@H@Z 0x140938cd0 ; unique
// MS2-PIN: ??8?$MS2Ptr@VCAchieve@@@@QEBA_NPEAVCAchieve@@@Z 0x1409392f0 ; unique
// MS2-PIN: memmove_s 0x14093acb0 ; unique
// MS2-PIN: ??$FormatStringId@M@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBM@Z 0x14093f980 ; unique
// MS2-PIN: ??$FormatStringId@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBV01@AEBH@Z 0x14093fa20 ; unique
// MS2-PIN: ??$FormatStringId@_J_J@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEB_J0@Z 0x14093fd30 ; unique
// MS2-PIN: ??$FUN_14028dfa0@_WV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEB_WAEBV01@@Z 0x140940040 ; unique
// MS2-PIN: ??0?$CAtlMap@HV?$MS2Ptr@VCAchieveUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveUIData@@@@@3@@ATL@@QEAA@IMMMI@Z 0x1409405a0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@QEAA@PEAVSpecialRewardDesc@CAchieveUIData@@@Z 0x140940810 ; unique
// MS2-PIN: ??1?$CAtlMap@HV?$MS2Ptr@VCAchieveUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveUIData@@@@@3@@ATL@@QEAA@XZ 0x140940b70 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@QEBAPEAVSpecialRewardDesc@CAchieveUIData@@XZ 0x140940e60 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCAchieveUIData@@@@QEBAPEAVCAchieveUIData@@XZ 0x140940e70 ; unique
// MS2-PIN: ??C?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@QEBAPEAVSpecialRewardDesc@CAchieveUIData@@XZ 0x140940e80 ; unique
// MS2-PIN: ??_ECAchieveCategory@@WBI@EAAPEAXI@Z 0x140940eb0 ; unique
// MS2-PIN: ??_ECAchieveUIData@@WBI@EAAPEAXI@Z 0x140940ebc ; unique
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KV?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@@3@@ATL@@QEAAXXZ 0x140941460 ; prop
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@HV?$MS2Ptr@VCAchieveUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveUIData@@@@@3@@ATL@@QEAAXXZ 0x140941480 ; prop
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@HV?$MS2Ptr@VCAchieveUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveUIData@@@@@3@@ATL@@QEBAIXZ 0x1409417a0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCAchieveUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveUIData@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1409417c0 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@HV?$MS2Ptr@VCAchieveUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveUIData@@@@@3@@ATL@@QEAAXI@Z 0x1409424c0 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@_KV?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@@3@@ATL@@QEAAXI@Z 0x1409426f0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlMap@HV?$MS2Ptr@VCAchieveUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveUIData@@@@@3@@ATL@@QEAAXXZ 0x140942960 ; prop
// MS2-PIN: ?RemoveAll@?$CAtlMap@_KV?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@@3@@ATL@@QEAAXXZ 0x140942a70 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HV?$MS2Ptr@VCAchieveUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveUIData@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140942b80 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@_KV?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140942c70 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@HV?$MS2Ptr@VCAchieveUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveUIData@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140942d60 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@_KV?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140942e20 ; prop
// MS2-PIN: ?SetAt@?$CAtlMap@HV?$MS2Ptr@VCAchieveUIData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCAchieveUIData@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$MS2Ptr@VCAchieveUIData@@@@@Z 0x140942ee0 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@_KV?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@@3@@ATL@@QEAAPEAU__POSITION@@_KAEBV?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@@Z 0x140942f90 ; unique
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@_KV?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpecialRewardDesc@CAchieveUIData@@@@@3@@ATL@@QEAAXMMM_N@Z 0x1409430f0 ; prop
// MS2-PIN: ?IsNull@?$MS2Ptr@VCAchieveUIData@@@@QEBA_NXZ 0x140940df0
// MS2-PIN: ?get@?$MS2Ptr@VCAchieve@@@@QEBAPEAVCAchieve@@XZ 0x1409393b0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VNotifyObject@@@@AEAAXPEAX@Z 0x14093ac50
// MS2-PIN: ??_7NotifyObject@@6B@ 0x142dac100
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CAchieveManager@@6B@ 0x142dac0f0
// MS2-PIN: ??_7NotifyClearAchieve@@6B@ 0x142dac118
// MS2-PIN: ??_7CAchieveUIData@@6B@ 0x142dacfe8
// MS2-PIN: ??_7CAchieveUIData@@6B?$CValidData@VCAchieveUIData@@@@@ 0x142dacff8
// MS2-PIN: ??_7SpecialRewardDesc@CAchieveUIData@@6B@ 0x142dacfd8
// MS2-PIN: ??_7CAchieveCategory@@6B@ 0x142dad018
// MS2-PIN: ??_7CAchieveCategory@@6B?$CValidData@VCAchieveCategory@@@@@ 0x142dad028
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\achievemanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "achievemanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/client/ms2/uigamemenudialog.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (names are exe addresses) ----------------------------------------------------------------------------
class Unk_SingletonObj;
class Unk_AmPC;
class Unk_AmMainInfo;
class UIMyInfoDialog : public UIObject {};                      // stand-in: the class is not recovered (dialog id 0x2711)

extern "C" _ACRTIMP void __cdecl _wassert(const wchar_t* pMsg, const wchar_t* pFile, unsigned nLine);

extern Unk_SingletonObj* DAT_143ab34d0;                         // the HUD notice queue's owner
extern Unk_SingletonObj* DAT_143ab34d8;                         // the report notice manager
extern ATL::CAtlList<MS2Ptr<CAchieveData> > DAT_143aab428;      // achievedata.cpp's s_listData (load order)
extern ATL::CAtlMap<unsigned, int> DAT_143af0f30;               // achievement ids the player has seen change

// Achievement table accessors of this unit that CAchieve / the table classes do not name.
int FUN_140158350(CAchieve* pAchieve, int nId, int nGrade, int nState);     // CAchieve::Init (the header's extra parameter is unused)

// UI lookup (the same idiom as unit_1406125d0.h).
class Unk_AmUIManager
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
};
Unk_AmUIManager* FUN_1403ed2b0();

void FUN_141937ea0(UIGameMenuDialog* pDialog, CAchieve* pAchieve, int bCleared);   // the menu dialog's achievement refresh
Unk_AmMainInfo* FUN_140931900(int nUiId);
void FUN_1419f0bb0(Unk_AmMainInfo* pInfo, CAchieve* pAchieve);
void FUN_141a5a560(UIMyInfoDialog* pDialog);

// Notice plumbing.
void FUN_140d5b880(Unk_SingletonObj* pOwner, unsigned nId, int nGrade);
CStringW FUN_140d2d440(unsigned nId, int nGrade);               // the notice's title text
class Unk_AmReportMgr { public: void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify); };
class Unk_AmTrigCmdMgr { public: void FUN_14138bf00(int nCmd, int nArg1, int nArg2); };
Unk_AmTrigCmdMgr* FUN_1409331e0();
void FUN_1412751b0(const CStringW& strMsg, int nType);          // system message line
class Unk_AmEventMgr { public: bool FUN_140cead80(CStringW strEvent); };
Unk_AmEventMgr* FUN_14015a050();
int FUN_14029f2b0(int nConditionType);                          // ConditionKindOfType

// Strings.
CStringW GetStringCommon(int nStringId);                          // string table entry
CStringW GetStringCommonByKey(const CStringW& strKey);                 // string by key
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_1408116a0(int nStringId, const int& nArg);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_14062b4f0(CStringW strKey, const int* pArg);
CStringW FUN_140632a60(int nStringId, const CStringW& strA, const CStringW& strB);
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& strA, const CStringW& strB);
CStringW FUN_141b720b0(int nItemId, int nUnused);               // item name
CStringW FUN_14083bab0(const CMsTime& time, CStringW strSep);
CStringW FUN_14083cb20(const CStringW& str);
CStringW FUN_140719a00(__int64 nValue);
int FUN_1407181d0(const CStringA& str);                         // number from a string
CStringW FUN_14016a730(const char* psz, int nCodePage);
void FUN_141842290(CStringW& str);                              // text post-processing (colour tags)

// The names, services and tables the reward texts read.
class Unk_AmNames { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_AmNames* FUN_1401a9d70();
void* FUN_1403ed2d0();
Unk_AmPC* FUN_141bd0cc0(void* pWorld);
unsigned FUN_141658e60(Unk_AmPC* pPC);                          // gender: 0 male
class Unk_AmOptions { public: bool FUN_14036d570(int nFlag); };
Unk_AmOptions* FUN_140166410();

// The text filter of the exe (strips markup).
class Unk_AmTextFilter { public: void FUN_1416fb380(CStringW& str); void FUN_1416fbf20(CStringW& str); };
Unk_AmTextFilter* FUN_1403b4750();

// The coloring table: a row set of (achievement id, grade) -> colour.
struct Unk_AmColorEntry { char m_pad_00[0x24]; int m_nAchieveId; int m_nGrade; int m_nColorId; };
class Unk_AmColorElem
{
public:
    Unk_AmColorElem(Unk_AmColorEntry* pEntry);                  // 0x14056a550
    ~Unk_AmColorElem();                                         // 0x14056c2d0
    Unk_AmColorEntry* FUN_14056d570() const;                    // operator->
    void* m_pad_00;
    Unk_AmColorEntry* m_p;
};
class Unk_AmColorList { public: unsigned FUN_140570e10(); Unk_AmColorEntry* FUN_140570dd0(unsigned n); };
class Unk_AmColorSet
{
public:
    ~Unk_AmColorSet();                                          // 0x14056c240
    void* FUN_14056d460() const;
    Unk_AmColorList* FUN_14056d540() const;
    void* m_pad_00;
    void* m_p;
};
class Unk_AmIngTable { public: Unk_AmColorSet FUN_140558ad0(int nId); };
Unk_AmIngTable* FUN_140281980();

// The skill table (dynamic action rewards).
struct Unk_AmSkillRow { char m_pad_00[0x48]; CStringA m_strIcon; };
class Unk_AmSkillRef
{
public:
    ~Unk_AmSkillRef();                                          // 0x14063e5c0
    Unk_AmSkillRow* FUN_14063ed10() const;
    void* m_pad_00;
    void* m_p;
};
class Unk_AmSkillTable { public: Unk_AmSkillRef FUN_1407ee1d0(int nSkillId); };
Unk_AmSkillTable* FUN_1401958b0();

// The xml reader of the exe (see continentregiontable.cpp / learningquesttable.cpp).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140168650 { public: Unk_140168650* FUN_140168650(const char*); };
class Unk_AmFileSystem { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int nUnused, bool bA, bool bB); };
Unk_AmFileSystem* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const CStringA& strArg);
CStringA FUN_14071ae20(const CStringA& strFile);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
int FUN_140197350(Unk_140165cf0* pNode, const char* pszName, int nDefault);
unsigned FUN_140197390(Unk_140165cf0* pNode, const char* pszName, unsigned nDefault);
CStringW FUN_1401bf530(Unk_140165cf0* pNode, const char* pszName, CStringW strDefault);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nValue);
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CStringA& strValue);
int FUN_140873420(Unk_140165cf0* pNode, const char* pszName, CStringW& strValue);

class Unk_ElemArray
{
public:
    void FUN_140163e20();                                       // ctor
    void FUN_1401644e0();                                       // dtor
    unsigned __int64 FUN_14016d900();                           // size
    Unk_140165cf0*& FUN_140164a30(unsigned __int64 n);          // operator[]
    void *m_a, *m_b, *m_c;
};
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, Unk_ElemArray* pOut);

// The localized-string formatters: FormatStringId (0x14028dee0) and the key based back end FUN_14028dfa0 with this unit's
// own fmt::internal::MakeValue instances (the Unk_WcFormatter of partyvotecli.cpp).
CStringW FormatStringId(int nId, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FormatStringId, int)
CStringW FUN_14028dfa0(const CStringW&, const fmt::ArgList&);
namespace fmt { namespace internal {
struct Unk_WcFormatter { typedef wchar_t Char; };
template <typename T> inline ULongLong wc_make_type(const T& arg) { return MakeValue<Unk_WcFormatter>::type(arg); }
struct Unk_WcArgType {
    ULongLong type;
    Unk_WcArgType() : type(0) {}
    template <typename T> Unk_WcArgType(const T& arg) : type(wc_make_type(arg)) {}
};
inline ULongLong wc_make_type(Unk_WcArgType t0 = Unk_WcArgType(), Unk_WcArgType t1 = Unk_WcArgType(), Unk_WcArgType t2 = Unk_WcArgType(),
                              Unk_WcArgType t3 = Unk_WcArgType(), Unk_WcArgType t4 = Unk_WcArgType(), Unk_WcArgType t5 = Unk_WcArgType(),
                              Unk_WcArgType t6 = Unk_WcArgType(), Unk_WcArgType t7 = Unk_WcArgType(), Unk_WcArgType t8 = Unk_WcArgType(),
                              Unk_WcArgType t9 = Unk_WcArgType(), Unk_WcArgType t10 = Unk_WcArgType(), Unk_WcArgType t11 = Unk_WcArgType(),
                              Unk_WcArgType t12 = Unk_WcArgType(), Unk_WcArgType t13 = Unk_WcArgType(), Unk_WcArgType t14 = Unk_WcArgType()) {
    return t0.type | (t1.type << 4) | (t2.type << 8) | (t3.type << 12) | (t4.type << 16) | (t5.type << 20) |
           (t6.type << 24) | (t7.type << 28) | (t8.type << 32) | (t9.type << 36) | (t10.type << 40) |
           (t11.type << 44) | (t12.type << 48) | (t13.type << 52) | (t14.type << 56);
}
} }
#define WC_REF(n) fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(v##n)
#define WC_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline CStringW FUN_14028dfa0(CStringW arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, WC_REF)}; \
        return FUN_14028dfa0(arg1, fmt::ArgList(fmt::internal::wc_make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
WC_WRAP(1)
WC_WRAP(2)


// This unit's own text helpers (defined below).
CStringW FUN_14093ce70(int nId, int nGrade);
int FUN_14093dc90(int nId, int nGrade, CStringW& strIcon, CStringW& strMsg);
CStringW FUN_14093c8d0(int nId, int nGrade, int bRaw);
CStringW FUN_14093bad0(int nId, int nGrade, CStringW strFormat);
CStringW FUN_14093dd50(int nId, __int64 nA, __int64 nB);
CStringW FUN_14093dee0(int nId, CStringW strA, CStringW strB);
CStringW FUN_14093e000(int nId, __int64 nA, __int64 nB);
CStringW FUN_14093e190(int nId, CStringW strA, CStringW strB);
int FUN_14093e2b0(int nCondType);
CStringW FUN_14093f4d0(int nSeconds);
CStringW FUN_14093f670(int nValue);
CStringW FUN_14093f800(__int64 nTime);
CStringW FUN_1409404f0(__int64 nValue);
int FUN_140940370(Unk_140165cf0* pNode, const char* pszName, int* pOut);
int FUN_140940430(Unk_140165cf0* pNode, const char* pszName, int* pOut);
CAchieveManager* FUN_1406c7600();                               // CAchieveManager::GetInstance
CMsTime FUN_1406c47a0(__int64 nTime);
CString FUN_14016a5c0(const char* psz, int n);

// ---- unit statics (.text$di) -----------------------------------------------------------------------------------------------------
static ATL::CAtlMap<int, MS2Ptr<CAchieveUIData> > s_mapUIData;                      // 0x143ab35c0 (achieveDescription.xml rows)
static CAchieveCategory::List s_aCategory;                                          // 0x143ab3658 (the top-level category nodes)
static CLockCriticalSection s_lockTables;                                           // 0x143ab3588
static ATL::CAtlMap<ULONGLONG, MS2Ptr<CAchieveUIData::SpecialRewardDesc> > s_mapSpecial;   // 0x143ab3610 (id << 32 | grade)
static CStringA s_aszCondition[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };   // 0x143ab3500
static CStringA s_strSkill("skill");                                                // 0x143ab34f8
static CStringA s_strStun("stun");                                                  // 0x143ab34f0
static ATL::CAtlMap<unsigned, CStringA> s_mapName;                                  // 0x143ab3540

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe flags (class static comments in the header)
bool CAchieveCategory::s_bInit;                                                     // 0x143ab3678
bool CAchieveUIData::s_bInit;                                                       // 0x143ab34e0
#endif

// ---- inline helpers (COMDATs of this obj) ----------------------------------------------------------------------------------------

// @0x140939920
inline ATL::CAtlList<MS2Ptr<CAchieveData> >* FUN_140939920() { return &DAT_143aab428; }

// @0x140939a00
inline Unk_SingletonObj* FUN_140939a00() { return DAT_143ab34d0; }

// @0x140939a10
inline Unk_SingletonObj* FUN_140939a10() { return DAT_143ab34d8; }

// @0x14093aca0
inline unsigned char Unk_NullableInt::HasValue()
{
    return m_bSet;
}

// @0x1409393d0
inline int* Unk_NullableInt::GetValue()
{
    (void)((!!(m_bSet != 0)) || (_wassert(L"m_isValueSet", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\nullable.h", 0x5c), 0));
    return &m_nValue;
}

// @0x1409398d0
inline MS2Ptr<CAchieveData> CAchieve::GetDataRef()
{
    return m_pData;
}

// @0x1409399f0
inline unsigned CAchieve::GetId()
{
    return m_nId;
}

// @0x140939ae0
inline int CAchieve::GetStartGrade()
{
    return m_nStartGrade;
}

// @0x140941760
inline int CAchieve::GetCondType()
{
    return m_cond.m_pData->m_nType;
}

// @0x140941790
inline __int64 CAchieve::GetProgress()
{
    return m_cond.m_nCount;
}

// ---- CAchieveManager -----------------------------------------------------------------------------------------------------------

// @0x140935c20
CAchieveManager::CAchieveManager() : m_map(10)
{
    m_tally.FUN_140267ba0();
}

// @0x140935c90
CAchieveManager::~CAchieveManager()
{
}

// @0x140935cd0
void CAchieveManager::Reload()
{
    m_map.RemoveAll();
    m_tally.FUN_140267bd0();
    ATL::CAtlArray<MS2Ptr<CAchieveData> > aData;
    CAchieveData::GetAll(aData);
    for (size_t i = 0; i < aData.GetCount(); i++)
    {
        MS2Ptr<CAchieveData> pData = aData[i];
        MS2Ptr<CAchieve> pAchieve(new CAchieve);
        if (FUN_140158350(pAchieve.operator->(), pData->m_nId, pData->m_nFirstGrade, 2) != 0)
            m_map.SetAt(pData->m_nId, pAchieve);
    }
}
MS2_REPLACE_METHOD(0x140935CD0, CAchieveManager, Reload, 389, 0x922413B4);

// @0x140935e60
MS2Ptr<CAchieve> CAchieveManager::Find(unsigned nId)
{
    MS2Ptr<CAchieve> pAchieve(0);
    m_map.Lookup(nId, pAchieve);
    return pAchieve;
}
MS2_REPLACE_METHOD(0x140935E60, CAchieveManager, Find, 121, 0x58144287);

// @0x140935ee0
void CAchieveManager::GetFirstList(CAchieveList& rOut)
{
    GetList(rOut, 2, 0, 0, 0);
}
MS2_REPLACE_METHOD(0x140935EE0, CAchieveManager, GetFirstList, 59, 0x88B9005C);

// @0x140935f30
void CAchieveManager::GetFirstListByCategory(CAchieveList& rOut, unsigned char nCategory)
{
    GetList(rOut, 2, nCategory, 0, 0);
}
MS2_REPLACE_METHOD(0x140935F30, CAchieveManager, GetFirstListByCategory, 67, 0x6C17E14E);

// @0x140935f80
void CAchieveManager::GetList(CAchieveList& rOut, int nType, unsigned char nCategory, int bStarted, int bGradeReached)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<CAchieve> pAchieve = m_map.GetValueAt(pos);
        if (nType != 0 && pAchieve->GetDataRef()->m_nType != nType)
            continue;
        if (nCategory != 0 && pAchieve->GetDataRef()->m_nCategory != (unsigned)nCategory)
            continue;
        if (bStarted != 0 && pAchieve->IsStarted() == 0)
            continue;
        if (bGradeReached != 0 && pAchieve->IsGradeReached() == 0)
            continue;
        rOut.Add(pAchieve);
    }
}
MS2_REPLACE_METHOD(0x140935F80, CAchieveManager, GetList, 608, 0xB6DD836C);

// @0x1409361f0
void CAchieveManager::GetListFromTable(CAchieveList& rOut, int nType, unsigned char nCategory, int bStarted, int bGradeReached)
{
    ATL::CAtlList<MS2Ptr<CAchieveData> >* pList = FUN_140939920();
    for (POSITION pos = pList->GetHeadPosition(); pos != 0; pList->GetNext(pos))
    {
        MS2Ptr<CAchieveData> pData = pList->GetAt(pos);
        MS2Ptr<CAchieve> pAchieve = Find(pData->m_nId);
        if (pAchieve.IsNull())
            continue;
        if (nType != 0 && pAchieve->GetDataRef()->m_nType != nType)
            continue;
        if (nCategory != 0 && pAchieve->GetDataRef()->m_nCategory != (unsigned)nCategory)
            continue;
        if (bStarted != 0 && pAchieve->IsStarted() == 0)
            continue;
        if (bGradeReached != 0 && pAchieve->IsGradeReached() == 0)
            continue;
        rOut.Add(pAchieve);
    }
}
MS2_REPLACE_METHOD(0x1409361F0, CAchieveManager, GetListFromTable, 728, 0x1F314E65);

// @0x1409364d0
int CAchieveManager::GetRewardTotal(int nType)
{
    CAchieveList aList;
    GetList(aList, nType, 0, 0, 1);
    int nTotal = 0;
    for (size_t i = 0; i < aList.GetCount(); i++)
        nTotal += aList[i]->GetRewardCount();
    return nTotal;
}
MS2_REPLACE_METHOD(0x1409364D0, CAchieveManager, GetRewardTotal, 199, 0x78B15772);

// @0x1409365a0
int CAchieveManager::IsCompleted(unsigned nId)
{
    MS2Ptr<CAchieve> pAchieve = Find(nId);
    if (pAchieve.IsNull())
        return false;
    return pAchieve->GetState() == 3;
}
MS2_REPLACE_METHOD(0x1409365A0, CAchieveManager, IsCompleted, 152, 0x6CC133B6);

// @0x140936640
bool CAchieveManager::IsGradeCleared(unsigned nId, int nGrade)
{
    MS2Ptr<CAchieve> pAchieve = Find(nId);
    if (pAchieve.IsNull())
        return false;
    if (pAchieve->GetState() == 3)
        return nGrade <= pAchieve->GetCurGrade();
    return nGrade < pAchieve->GetCurGrade();
}
MS2_REPLACE_METHOD(0x140936640, CAchieveManager, IsGradeCleared, 250, 0x426BE738);

// @0x140936740
bool CAchieveManager::HasCompletedOfType(Unk_NullableInt nType)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<CAchieve> pAchieve = m_map.GetValueAt(pos);
        if (pAchieve->GetData30() == 0)
        {
            if (nType.HasValue() && pAchieve->GetDataRef()->m_nType != *nType.GetValue())
                continue;
            if (pAchieve->IsCompleted() != 0)
                return true;
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x140936740, CAchieveManager, HasCompletedOfType, 428, 0x7D5EC3BD);

// @0x140936900
int CAchieveManager::IsBeforeStartGrade(unsigned nId, int nGrade)
{
    MS2Ptr<CAchieve> pAchieve = Find(nId);
    if (pAchieve.IsNull())
        return false;
    return pAchieve->GetStartGrade() > nGrade;
}
MS2_REPLACE_METHOD(0x140936900, CAchieveManager, IsBeforeStartGrade, 158, 0x1A2A0203);

// @0x1409369b0
int CAchieveManager::IsBeforeStartGradeOf(MS2Ptr<CAchieve> pAchieve, int nGrade)
{
    if (pAchieve == 0)
        return false;
    return pAchieve->GetStartGrade() > nGrade;
}

// The three dialog lookups (UI ids 0x4e28 / 0x2711 / 0x4e5d).
static UIGameMenuDialog* FUN_140938b90(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> pUi = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (pUi.get())
            return dynamic_cast<UIGameMenuDialog*>((UIObject*)pUi);
    }
    return 0;
}

static UIMyInfoDialog* FUN_140938c30(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> pUi = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (pUi.get())
            return dynamic_cast<UIMyInfoDialog*>((UIObject*)pUi);
    }
    return 0;
}

static UIRewardNotify* FUN_140938cd0(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> pUi = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (pUi.get())
            return dynamic_cast<UIRewardNotify*>((UIObject*)pUi);
    }
    return 0;
}

// @0x140936a50
void CAchieveManager::OnPacket(CByteBuffer& rBuf)
{
    unsigned char nMode = rBuf.vfunc_o8_1();
    if (nMode == 0)
        Reload();
    if (nMode == 1)
    {
        unsigned nCount = rBuf.vfunc_o8_3();
        for (size_t i = 0; i < nCount; i++)
        {
            int nId = rBuf.vfunc_o8_3();
            int nGrade = rBuf.vfunc_o8_3();
            MS2Ptr<CAchieve> pAchieve(new CAchieve);
            if (FUN_140158350(pAchieve.operator->(), nId, nGrade, 0) == 0)
            {
                pAchieve->Decode(rBuf);
            }
            else
            {
                pAchieve->Decode(rBuf);
                m_map.SetAt(nId, pAchieve);
                Tally(pAchieve.get());
            }
        }
        return;
    }
    if (nMode != 2)
        return;
    unsigned nId = rBuf.vfunc_o8_3();
    MS2Ptr<CAchieve> pAchieve = Find(nId);
    if (pAchieve.get() != 0)
    {
        int nOldStart = pAchieve->GetStartGrade();
        int nOldGrade = pAchieve->GetCurGrade();
        int nOldState = pAchieve->GetState();
        pAchieve->Decode(rBuf);
        int bNotified = 0;
        if (nOldGrade != pAchieve->GetCurGrade() || (nOldState != 3 && pAchieve->GetState() == 3))
        {
            NotifyClear(pAchieve.get());
            RebuildTally();
            bNotified = 1;
        }
        if (pAchieve->GetType() != 8)
        {
            if (nOldStart != pAchieve->GetStartGrade())
                NotifyReward(nId, nOldStart);
            UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28);
            if (pMenu != 0)
                FUN_141937ea0(pMenu, pAchieve.get(), bNotified);
            Unk_AmMainInfo* pInfo = FUN_140931900(0x4e5f);
            if (pInfo != 0)
                FUN_1419f0bb0(pInfo, pAchieve.get());
            UIMyInfoDialog* pMyInfo = FUN_140938c30(0x2711);
            if (pMyInfo != 0)
                FUN_141a5a560(pMyInfo);
        }
    }
    DAT_143af0f30.SetAt(nId, 1);
}

// @0x140936ec0
void CAchieveManager::NotifyClear(CAchieve* pAchieve)
{
    if (pAchieve != 0)
    {
        int nState = pAchieve->GetState();
        int nGrade = ((nState == 3 ? pAchieve->GetCurGrade() : pAchieve->GetCurGrade() - 1) < 1)
            ? 1 : (nState == 3 ? pAchieve->GetCurGrade() : pAchieve->GetCurGrade() - 1);
        FUN_140d5b880(FUN_140939a00(), pAchieve->GetId(), nGrade);
        if (pAchieve->GetType() != 8)
        {
            UIRewardNotify* pNotify = FUN_140938cd0(0x4e5d);
            if (pNotify != 0)
                pNotify->FUN_141abfdc0((Unk_RNAchieve*)pAchieve);
            MS2Ptr<CAchieveData> pData = pAchieve->GetDataRef();
            if (pData)
            {
                int nRewardType = pData->GetGrade(nGrade)->m_reward.m_nType;
                if (0 < nRewardType)
                    FUN_1409331e0()->FUN_14138bf00(0x17, 0, 0);
            }
            CStringW strTitle = FUN_140d2d440(pAchieve->GetId(), nGrade);
            if (nState == 3)
                FUN_1412751b0(StringFormat(GetStringCommon(0x77d), strTitle), 0x14);
            else
                FUN_1412751b0(StringFormat(GetStringCommon(0x77c), strTitle), 0x14);
            ((Unk_AmReportMgr*)FUN_140939a10())->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyClearAchieve(pAchieve->GetId())));
        }
    }
}

// Shows the "you unlocked <...>" toast and the system line for the beauty (hair / makeup) reward of the current player.
// @0x1409372b0
// MS2-FUNCTIONAL: the 9 near-identical reward text blocks; the temporaries of the inlined string formatting are not byte-matched
void CAchieveManager::NotifyReward(int nId, int nGrade)
{
    MS2Ptr<CAchieveData> pData = GetAchieveData(nId);
    if (pData.IsNull())
        return;
    MS2Ptr<CAchieveGradeData> pGrade = pData->GetGrade(nGrade);
    if (pGrade.IsNull())
        return;
    UIRewardNotify* pNotify = FUN_140938cd0(0x4e5d);
    if (pNotify == 0)
        return;
    CStringW strIcon;
    CStringW strMsg;
    if (FUN_14093dc90(nId, nGrade, strIcon, strMsg) == 0)
    {
        switch (pGrade->m_reward.m_nType)
        {
        case 1:
            pNotify->FUN_141abf6e0(pGrade->m_reward.m_nCode, pGrade->m_reward.m_nRank);
            break;
        case 3:
            pNotify->FUN_141ac1b50(pGrade->m_reward.m_nValue);
            FUN_1412751b0(FUN_14028dfa0(CStringW(L"s_reward_notify_stat_point"), pGrade->m_reward.m_nValue), 0x14);
            break;
        case 4:
        {
            pNotify->FUN_141ac1950(pGrade->m_reward.m_nValue, pGrade->m_reward.m_nSubJob);
            CStringW strKey(L"s_reward_notify_skill_point");
            if (pGrade->m_reward.m_nSubJob == 2)
                strKey = L"s_reward_notify_skill_point_sub_1";
            FUN_1412751b0(FUN_14028dfa0(CStringW(strKey), pGrade->m_reward.m_nValue), 0x14);
            break;
        }
        case 5:
            pNotify->FUN_141ac1580(CStringW(L"./Data/Resource/Image/ETC/weaponshop_unlock.png"),
                                   FUN_1405c2690(CStringW(L"s_system_achieve_reward_shop_unlock"), FUN_1401a9d70()->FUN_141811980(1, pGrade->m_reward.m_nCode)), 0);
            FUN_1412751b0(FUN_1405c2690(CStringW(L"s_system_achieve_reward_shop_auth_notify"), FUN_1401a9d70()->FUN_141811980(1, pGrade->m_reward.m_nCode)), 0x1c);
            break;
        case 6:
            pNotify->FUN_141ac1580(CStringW(L"./Data/Resource/Image/ETC/buildshop_unlock.png"),
                                   FUN_1405c2690(CStringW(L"s_system_achieve_reward_shop_unlock"), FUN_1401a9d70()->FUN_141811980(1, pGrade->m_reward.m_nCode)), 0);
            FUN_1412751b0(FUN_1405c2690(CStringW(L"s_system_achieve_reward_shop_auth_notify"), FUN_1401a9d70()->FUN_141811980(1, pGrade->m_reward.m_nCode)), 0x1c);
            break;
        case 7:
            pNotify->FUN_141ac1580(CStringW(L"./Data/Resource/Image/ETC/rideshop_unlock.png"),
                                   FUN_1405c2690(CStringW(L"s_system_achieve_reward_shop_unlock"), FUN_1401a9d70()->FUN_141811980(1, pGrade->m_reward.m_nCode)), 0);
            FUN_1412751b0(FUN_1405c2690(CStringW(L"s_system_achieve_reward_shop_auth_notify"), FUN_1401a9d70()->FUN_141811980(1, pGrade->m_reward.m_nCode)), 0x1c);
        }
        if (FUN_140166410()->FUN_14036d570(0xbb))
        {
            int nType = pGrade->m_reward.m_nType;
            if (nType == 8)
            {
                Unk_AmColorSet set = FUN_140281980()->FUN_140558ad0(pGrade->m_reward.m_nCode);
                if (set.FUN_14056d460() != 0)
                {
                    for (unsigned i = 0; i < set.FUN_14056d540()->FUN_140570e10(); i++)
                    {
                        Unk_AmColorElem elem(set.FUN_14056d540()->FUN_140570dd0(i));
                        if (elem.FUN_14056d570()->m_nAchieveId == nId)
                        {
                            if (elem.FUN_14056d570()->m_nGrade == nGrade)
                            {
                                pNotify->FUN_141ac1580(CStringW(L"./Data/Resource/Image/ETC/colorpalette_unlock.png"),
                                                       FUN_1405c2690(CStringW(L"s_system_achieve_reward_coloring"), FUN_1401a9d70()->FUN_141811980(0x48, elem.FUN_14056d570()->m_nColorId)), 0);
                                FUN_1412751b0(FUN_1405c2690(CStringW(L"s_system_achieve_reward_coloring_auth_notify"), FUN_1401a9d70()->FUN_141811980(0x48, elem.FUN_14056d570()->m_nColorId)), 0x1c);
                            }
                        }
                    }
                }
            }
            else if (9 < nType)
            {
                if (nType < 12)
                {
                    Unk_AmPC* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
                    if (pPC != 0)
                    {
                        CStringA strGender(FUN_141658e60(pPC) == 0 ? "male" : "female");
                        CStringA strValue;
                        if (pGrade->m_reward.m_mapExtra.Lookup(strGender, strValue))
                        {
                            pNotify->FUN_141ac1580(CStringW(L"./Data/Resource/Image/ETC/customizeshop_unlock.png"),
                                                   FUN_1405c2690(CStringW(L"s_system_achieve_reward_beauty"), FUN_1401a9d70()->FUN_141811980(1, FUN_1407181d0(strValue))), 0);
                            FUN_1412751b0(FUN_1405c2690(CStringW(L"s_system_achieve_reward_beauty_auth_notify"), FUN_1401a9d70()->FUN_141811980(1, FUN_1407181d0(strValue))), 0x1c);
                        }
                    }
                }
                else if (nType == 12)
                {
                    Unk_AmSkillRow* pRow = FUN_1401958b0()->FUN_1407ee1d0(pGrade->m_reward.m_nCode).FUN_14063ed10();
                    if (pRow != 0)
                    {
                        pNotify->FUN_141ac1580(FUN_14016a730(pRow->m_strIcon, 0),
                                               FUN_1405c2690(CStringW(L"s_system_achieve_reward_dynamicaction"), FUN_1401a9d70()->FUN_141811980(4, pGrade->m_reward.m_nCode)), 0);
                        FUN_1412751b0(FUN_1405c2690(CStringW(L"s_system_achieve_reward_dynamicaction_auth_notify"), FUN_1401a9d70()->FUN_141811980(4, pGrade->m_reward.m_nCode)), 0x1c);
                    }
                }
            }
        }
        if (FUN_140166410()->FUN_14036d570(0xbc) && pGrade->m_reward.m_nType == 9)
        {
            Unk_AmPC* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
            if (pPC == 0)
                return;
            CStringA strGender(FUN_141658e60(pPC) == 0 ? "male" : "female");
            CStringA strValue;
            if (pGrade->m_reward.m_mapExtra.Lookup(strGender, strValue))
            {
                pNotify->FUN_141ac1580(CStringW(L"./Data/Resource/Image/ETC/customizeshop_unlock.png"),
                                       FUN_1405c2690(CStringW(L"s_system_achieve_reward_beauty"), FUN_1401a9d70()->FUN_141811980(1, FUN_1407181d0(strValue))), 0);
                FUN_1412751b0(FUN_1405c2690(CStringW(L"s_system_achieve_reward_beauty_auth_notify"), FUN_1401a9d70()->FUN_141811980(1, FUN_1407181d0(strValue))), 0x1c);
            }
        }
    }
    else
    {
        pNotify->FUN_141ac1580(strIcon, strMsg, 0);
        FUN_1412751b0(FUN_1405c2690(CStringW(L"s_system_achieve_reward_auth_notify_manual"), FUN_14093ce70(nId, nGrade)), 0x1c);
    }
    FUN_1409331e0()->FUN_14138bf00(3, pGrade->m_reward.m_nType, 0);
}

// @0x1409388a0
void CAchieveManager::Tally(CAchieve* pAchieve)
{
    if (pAchieve != 0)
    {
        MS2Ptr<CAchieveData> pData = pAchieve->GetDataRef();
        if (!pData.IsNull())
        {
            if (pData->m_nType == 2)
            {
                for (int nGrade = pData->m_nFirstGrade; nGrade <= pAchieve->GetCurGrade(); nGrade++)
                {
                    if (pAchieve->GetValue(nGrade) != 0)
                    {
                        int nCategory = pData->m_nCategory;
                        if (nCategory == 1)
                            m_tally.FUN_140267c70(0, 1);
                        else if (nCategory == 2)
                            m_tally.FUN_140267c70(1, 1);
                        else if (nCategory == 3)
                            m_tally.FUN_140267c70(2, 1);
                    }
                }
            }
        }
    }
}

// @0x1409389f0
void CAchieveManager::RebuildTally()
{
    m_tally.FUN_140267bd0();
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<CAchieve> pAchieve = m_map.GetValueAt(pos);
        if (pAchieve->IsStarted() == 0)
            continue;
        Tally(pAchieve.get());
    }
}

// @0x140938ad0
Unk_AchieveTab* CAchieveManager::GetTally()
{
    return &m_tally;
}

// ---- NotifyClearAchieve --------------------------------------------------------------------------------------------------------

// @0x140939070
NotifyObject::NotifyObject()
{
}

// @0x140939260
NotifyObject::~NotifyObject()
{
}

// @0x140939030
NotifyClearAchieve::NotifyClearAchieve(int nId)
{
    m_nId = nId;
}

// @0x140939240
NotifyClearAchieve::~NotifyClearAchieve()
{
}

// ---- CAchieveUIData ------------------------------------------------------------------------------------------------------------

// @0x14093add0
CAchieveUIData::CAchieveUIData()
{
    m_nId = 0;
}

// @0x14093ae90
CAchieveUIData::~CAchieveUIData()
{
}

// @0x14093af30
void CAchieveUIData::LoadAll()
{
    LoadDesc();
    LoadSpecialReward();
    SetInit(true);
}

#ifndef MS2_HOOK_DLL
// @0x14093af50
// MS2-FUNCTIONAL: the exe builds the file name / path CStringA temps with early destruction; no source form found
void CAchieveUIData::LoadDesc()
{
    TiXmlDocument doc;
    CStringA strPath = FUN_14071ae20(CStringA("achieveDescription.xml"));
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) != 0)
    {
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        }
        else
        {
            Unk_ElemArray aElem;
            aElem.FUN_140163e20();
            FUN_14028faa0(pRoot, "achieve", "id", &aElem);
            for (unsigned __int64 i = 0; i < aElem.FUN_14016d900(); i++)
            {
                Unk_140165cf0* pElem = aElem.FUN_140164a30(i);
                MS2Ptr<CAchieveUIData> pUI(new CAchieveUIData);
                int nId = FUN_140197350(pElem, "id", 0);
                pUI->m_nId = nId;
                CStringW strDesc = FUN_1401bf530(pElem, "desc", CStringW(L""));
                CStringW strComplete = FUN_1401bf530(pElem, "complete", CStringW(L""));
                CStringW strManualDesc = FUN_1401bf530(pElem, "manualDesc", CStringW(L""));
                CStringW strManualComplete = FUN_1401bf530(pElem, "manualComplete", CStringW(L""));
                FUN_1403b4750()->FUN_1416fb380(strComplete);
                FUN_1403b4750()->FUN_1416fb380(strManualComplete);
                FUN_1403b4750()->FUN_1416fbf20(strDesc);
                FUN_1403b4750()->FUN_1416fbf20(strManualDesc);
                pUI->m_strDesc = strDesc;
                pUI->m_strComplete = strComplete;
                pUI->m_strManualDesc = strManualDesc;
                pUI->m_strManualComplete = strManualComplete;
                if (Unk_LockGuard guard = s_lockTables) {} else
                {
                    s_mapUIData.SetAt(pUI->m_nId, pUI);
                }
            }
            aElem.FUN_1401644e0();
        }
    }
}
#endif

#ifndef MS2_HOOK_DLL
// @0x14093b440
// MS2-FUNCTIONAL: the exe builds the file name / path CStringA temps with early destruction; no source form found
void CAchieveUIData::LoadSpecialReward()
{
    TiXmlDocument doc;
    CStringA strPath = FUN_14071ae20(CStringA("achieveSpecialRewardDescription.xml"));
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) != 0)
    {
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        }
        else
        {
            for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("achieve"); pElem != 0; pElem = reinterpret_cast<Unk_140165cf0*>(reinterpret_cast<Unk_140168650*>(pElem)->FUN_140168650("achieve")))
            {
                MS2Ptr<SpecialRewardDesc> pDesc(new SpecialRewardDesc);
                unsigned nId = FUN_140197390(pElem, "id", 0);
                int nGrade = FUN_140197350(pElem, "grade", 0);
                pDesc->m_strSpecialDesc = FUN_1401bf530(pElem, "specialDesc", CStringW(L""));
                pDesc->m_strNotifyIcon = FUN_1401bf530(pElem, "specialNotifyIcon", CStringW(L""));
                pDesc->m_strNotifyString = FUN_1401bf530(pElem, "specialNotifyString", CStringW(L""));
                FUN_1403b4750()->FUN_1416fb380(pDesc->m_strSpecialDesc);
                FUN_1403b4750()->FUN_1416fb380(pDesc->m_strNotifyString);
                if (Unk_LockGuard guard = s_lockTables) {} else
                {
                    s_mapSpecial.SetAt((ULONGLONG)nId << 32 | (__int64)nGrade, pDesc);
                }
            }
        }
    }
}
#endif

#ifndef MS2_HOOK_DLL
// @0x14093b8c0
MS2Ptr<CAchieveUIData> CAchieveUIData::Find(int nId)
{
    CheckInit();
    MS2Ptr<CAchieveUIData> pUI(0);
    if (Unk_LockGuard guard = s_lockTables) {} else
    {
        s_mapUIData.Lookup(nId, pUI);
    }
    return pUI;
}
#endif

// ---- achievement texts ----------------------------------------------------------------------------------------------------------

// The name of an achievement from the names table (table 0x18).
// @0x14093b970
CStringW FUN_14093b970(int nId)
{
    return FUN_1401a9d70()->FUN_141811980(0x18, nId);
}

// "[Ⅲ] title": the grade as a roman numeral (0..10) in front of the achievement name.
// @0x14093b9c0
CStringW FUN_14093b9c0(int nId, int nGrade)
{
    static const wchar_t s_aRoman[] = { L'0', L'Ⅰ', L'Ⅱ', L'Ⅲ', L'Ⅳ', L'Ⅴ', L'Ⅵ', L'Ⅶ', L'Ⅷ', L'Ⅸ', L'Ⅹ' };
    if (nGrade < 0 || nGrade >= _countof(s_aRoman))
        return CStringW(L"");
    return FUN_14028dfa0(CStringW(L"s_achieve_title"), s_aRoman[nGrade], FUN_14093b970(nId));
}

// @0x14093bad0
// MS2-FUNCTIONAL: the temporaries of the string table lookups are not byte-matched
CStringW FUN_14093bad0(int nId, int nGrade, CStringW strFormat)
{
    MS2Ptr<CAchieveData> pData = GetAchieveData(nId);
    if (pData.IsNull())
        return CStringW(L"");
    if (strFormat.GetLength() == 0)
        strFormat = L"[{0}]{1}";
    CStringW strTag;
    int nCategory = pData->m_nCategory;
    if (nCategory == 1)
        strTag = GetStringCommon(0x76e);
    else if (nCategory == 2)
        strTag = GetStringCommon(0x76d);
    else if (nCategory == 3)
        strTag = GetStringCommon(0x76f);
    return StringFormat((LPCWSTR)strFormat, strTag, FUN_14093b9c0(nId, nGrade));
}

// @0x14093bd40
// MS2-FUNCTIONAL: the temporaries of the string table lookups are not byte-matched
CStringW FUN_14093bd40(int nId, int nGrade, CStringW strFormat)
{
    CStringW strTitle = FUN_14093bad0(nId, nGrade, CStringW(L""));
    if (strTitle.IsEmpty())
        return CStringW(L"");
    CStringW strCond = FUN_14093c8d0(nId, nGrade, 0);
    if (strFormat.IsEmpty())
        strFormat = GetStringCommonByKey(CStringW(L"s_skill_require_achieve"));
    return StringFormat((LPCWSTR)strFormat, strTitle, strCond);
}

// @0x14093bf10
// MS2-FUNCTIONAL: the progress text of one condition kind; the four fmt shapes share the temporaries of the strings
CStringW FUN_14093bf10(CAchieve* pAchieve, int nGrade)
{
    if (pAchieve == 0)
        return CStringW(L"");
    __int64 nProgress = pAchieve->GetProgress();
    __int64 nValue = pAchieve->GetGradeGoal(nGrade);
    if (nValue < nProgress)
        nProgress = nValue;
    CStringW strText;
    int nKind = FUN_14093e2b0(pAchieve->GetCondType());
    if (nKind == 0)
        strText = FUN_140632a60(0x800, FUN_14093f4d0((int)(nProgress / 60)), FUN_14093f4d0((int)(nValue / 60)));
    else if (nKind == 1)
        strText = FUN_140632a60(0x800, FUN_14093f4d0((int)nProgress), FUN_14093f4d0((int)nValue));
    else if (nKind == 2)
        strText = FUN_1408f71a0(CStringW(L"s_achieve_renderer_count_distance"), FUN_14093f670((int)nProgress), FUN_14093f670((int)nValue));
    else
        strText = FormatStringId(0x7ff, nProgress, nValue);
    return strText;
}

// The progress text of the current grade of an achievement ("3/10").
// @0x14093c320
// MS2-FUNCTIONAL: the temporaries of the nested string builders are not byte-matched
CStringW FUN_14093c320(CAchieve* pAchieve)
{
    if (pAchieve == 0)
        return CStringW(L"");
    MS2Ptr<CAchieveData> pData = GetAchieveData(pAchieve->GetId());
    if (pData.IsNull())
        return CStringW(L"");
    MS2Ptr<CAchieveGradeData> pGrade = pData->GetGrade(pAchieve->GetCurGrade());
    if (pGrade.IsNull())
        return CStringW(L"");
    __int64 nProgress = pAchieve->GetProgress();
    unsigned __int64 nTarget = pGrade->m_pCondition->m_target.GetFirstValue();
    CStringW strText;
    int nKind = FUN_14093e2b0(pAchieve->GetCondType());
    if (nKind == 0)
        strText = FUN_14093e190(pAchieve->GetId(), FUN_14093f4d0((int)(nProgress / 60)), FUN_14093f4d0((int)(nTarget / 60)));
    else if (nKind == 1)
        strText = FUN_14093e190(pAchieve->GetId(), FUN_14093f4d0((int)nProgress), FUN_14093f4d0((int)nTarget));
    else if (nKind == 2)
        strText = FUN_14093e190(pAchieve->GetId(), FUN_14093f670((int)nProgress), FUN_14093f670((int)nTarget));
    else if (nKind == 3)
    {
        if (nTarget != 0)
            nProgress = nProgress - (nTarget - 1);
        strText = FUN_14093e000(pAchieve->GetId(), nProgress, nTarget);
    }
    else if (nKind == 4)
        strText = FUN_14093e000(pAchieve->GetId(), nProgress, nTarget);
    return strText;
}

// The requirement text of one grade ("collect 10"); bRaw keeps the colour tags.
// @0x14093c8d0
// MS2-FUNCTIONAL: the temporaries of the nested string builders are not byte-matched
CStringW FUN_14093c8d0(int nId, int nGrade, int bRaw)
{
    MS2Ptr<CAchieveData> pData = GetAchieveData(nId);
    if (pData.IsNull())
        return CStringW(L"");
    MS2Ptr<CAchieveGradeData> pGrade = pData->GetGrade(nGrade);
    if (pGrade.IsNull())
        return CStringW(L"");
    unsigned __int64 nGoal = pGrade->m_pCondition->m_nGoal;
    unsigned __int64 nTarget = pGrade->m_pCondition->m_target.GetFirstValue();
    CStringW strText;
    int nKind = FUN_14093e2b0(pGrade->m_pCondition->m_nType);
    if (nKind == 0)
        strText = FUN_14093dee0(nId, FUN_14093f4d0((int)(nGoal / 60)), FUN_14093f4d0((int)(nTarget / 60)));
    else if (nKind == 1)
        strText = FUN_14093dee0(nId, FUN_14093f4d0((int)nGoal), FUN_14093f4d0((int)nTarget));
    else if (nKind == 2)
        strText = FUN_14093dee0(nId, FUN_14093f670((int)nGoal), FUN_14093f670((int)nTarget));
    else
        strText = FUN_14093dd50(nId, nGoal, nTarget);
    if (bRaw == 0)
        FUN_141842290(strText);
    return strText;
}

// The reward text of the first grade of the player's achievement nId.
// @0x14093cdb0
CStringW FUN_14093cdb0(int nId)
{
    MS2Ptr<CAchieve> pAchieve = FUN_1406c7600()->Find(nId);
    if (pAchieve.IsNull())
        return CStringW(L"");
    return FUN_14093ce70(nId, pAchieve->GetStartGrade());
}

// The reward text of one grade (special text of the table, or built from the reward type).
// @0x14093ce70
// MS2-FUNCTIONAL: the reward type switch builds its strings through many inlined temporaries
CStringW FUN_14093ce70(int nId, int nGrade)
{
    MS2Ptr<CAchieveData> pData = GetAchieveData(nId);
    if (pData.IsNull())
        return CStringW(L"");
    MS2Ptr<CAchieveGradeData> pGrade = pData->GetGrade(nGrade);
    if (pGrade.IsNull())
        return CStringW(L"");
    MS2Ptr<CAchieveUIData> pUI = CAchieveUIData::Find(nId);
    if (pUI.IsNull())
        return CStringW(L"");
    MS2Ptr<CAchieveUIData::SpecialRewardDesc> pSpecial = CAchieveUIData::FindSpecialReward(nId, nGrade);
    if (pSpecial.get() != 0)
        return CStringW(pSpecial->m_strSpecialDesc);
    int nValue = pGrade->m_reward.m_nValue;
    unsigned nCode = pGrade->m_reward.m_nCode;
    switch (pGrade->m_reward.m_nType - 1)
    {
    case 0:
        return FormatStringId(0x770, FUN_1401a9d70()->FUN_141811980(1, nCode), nValue);
    case 1:
        return FUN_14052bd00(0x774, FUN_141b720b0(nCode, 0));
    case 2:
        return FUN_14062b4f0(CStringW(L"s_achieve_reward_stat_point"), &nValue);
    case 3:
    {
        CStringW strKey(L"s_achieve_reward_skill_point");
        if (pGrade->m_reward.m_nSubJob == 2)
            strKey = L"s_achieve_reward_skill_point_sub_1";
        return FUN_14062b4f0(CStringW(strKey), &nValue);
    }
    case 4:
    case 5:
    case 6:
        return FUN_1405c2690(CStringW(L"s_achieve_reward_item_buy_auth"), FUN_1401a9d70()->FUN_141811980(1, nCode));
    default:
        if (FUN_140166410()->FUN_14036d570(0xbb))
        {
            int nType = pGrade->m_reward.m_nType;
            if (nType == 8)
            {
                CStringW strAll;
                Unk_AmColorSet set = FUN_140281980()->FUN_140558ad0(nCode);
                if (set.FUN_14056d460() != 0)
                {
                    for (unsigned i = 0; i < set.FUN_14056d540()->FUN_140570e10(); i++)
                    {
                        Unk_AmColorElem elem(set.FUN_14056d540()->FUN_140570dd0(i));
                        if (elem.FUN_14056d570()->m_nAchieveId == nId)
                        {
                            if (elem.FUN_14056d570()->m_nGrade == nGrade)
                            {
                                if (strAll.GetLength() != 0)
                                    strAll += "\n";
                                strAll += FUN_1405c2690(CStringW(L"s_achieve_reward_coloring"), FUN_1401a9d70()->FUN_141811980(0x48, elem.FUN_14056d570()->m_nColorId));
                            }
                        }
                    }
                }
                return strAll;
            }
            if (9 < nType)
            {
                if (nType < 12)
                {
                    Unk_AmPC* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
                    if (pPC != 0)
                    {
                        CStringA strGender(FUN_141658e60(pPC) == 0 ? "male" : "female");
                        CStringA strValue;
                        pGrade->m_reward.m_mapExtra.Lookup(strGender, strValue);
                        return FUN_1405c2690(CStringW(L"s_achieve_reward_beauty"), FUN_1401a9d70()->FUN_141811980(1, FUN_1407181d0(strValue)));
                    }
                }
                else if (nType == 12)
                {
                    return FUN_1405c2690(CStringW(L"s_achieve_reward_dynamicaction"), FUN_1401a9d70()->FUN_141811980(4, nCode));
                }
            }
        }
        if (!FUN_140166410()->FUN_14036d570(0xbc) || pGrade->m_reward.m_nType != 9)
            return CStringW(L"");
        Unk_AmPC* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pPC == 0)
            return CStringW(L"");
        CStringA strGender(FUN_141658e60(pPC) == 0 ? "male" : "female");
        CStringA strValue;
        pGrade->m_reward.m_mapExtra.Lookup(strGender, strValue);
        return FUN_1405c2690(CStringW(L"s_achieve_reward_beauty"), FUN_1401a9d70()->FUN_141811980(1, FUN_1407181d0(strValue)));
    }
}

// The special notify icon / text of a grade, when the special reward table has them.
// @0x14093dc90
int FUN_14093dc90(int nId, int nGrade, CStringW& strIcon, CStringW& strMsg)
{
    MS2Ptr<CAchieveUIData::SpecialRewardDesc> pSpecial = CAchieveUIData::FindSpecialReward(nId, nGrade);
    if (pSpecial.get() != 0)
    {
        strIcon = pSpecial->m_strNotifyIcon;
        strMsg = pSpecial->m_strNotifyString;
        return 1;
    }
    return 0;
}

// @0x14093dd50
CStringW FUN_14093dd50(int nId, __int64 nA, __int64 nB)
{
    MS2Ptr<CAchieveUIData> pUI = CAchieveUIData::Find(nId);
    if (pUI.get() == 0)
        return CStringW(L"");
    if (pUI->m_strManualDesc.GetLength() == 0)
        return StringFormat((LPCWSTR)pUI->m_strDesc, FUN_1409404f0(nA), FUN_1409404f0(nB));
    return CStringW(pUI->m_strManualDesc);
}

// @0x14093dee0
CStringW FUN_14093dee0(int nId, CStringW strA, CStringW strB)
{
    MS2Ptr<CAchieveUIData> pUI = CAchieveUIData::Find(nId);
    if (pUI.get() == 0)
        return CStringW(L"");
    if (pUI->m_strManualDesc.GetLength() == 0)
        return StringFormat((LPCWSTR)pUI->m_strDesc, strA, strB);
    return CStringW(pUI->m_strManualDesc);
}

// @0x14093e000
CStringW FUN_14093e000(int nId, __int64 nA, __int64 nB)
{
    MS2Ptr<CAchieveUIData> pUI = CAchieveUIData::Find(nId);
    if (pUI.get() == 0)
        return CStringW(L"");
    if (pUI->m_strManualComplete.GetLength() == 0)
        return StringFormat((LPCWSTR)pUI->m_strComplete, FUN_1409404f0(nA), FUN_1409404f0(nB));
    return CStringW(pUI->m_strManualComplete);
}

// @0x14093e190
CStringW FUN_14093e190(int nId, CStringW strA, CStringW strB)
{
    MS2Ptr<CAchieveUIData> pUI = CAchieveUIData::Find(nId);
    if (pUI.get() == 0)
        return CStringW(L"");
    if (pUI->m_strManualComplete.GetLength() == 0)
        return StringFormat((LPCWSTR)pUI->m_strComplete, strA, strB);
    return CStringW(pUI->m_strManualComplete);
}

// How the progress of a condition type is shown: 0 minutes, 1 seconds, 2 distance, 3 stack, 4 plain count.
// @0x14093e2b0
int FUN_14093e2b0(int nCondType)
{
    if (FUN_14029f2b0(nCondType) == 0x11)
    {
        if (nCondType == 0x44)
            return 0;
        if (nCondType == 0x45)
            return 0;
        return 1;
    }
    else if (FUN_14029f2b0(nCondType) == 0xf)
    {
        return 2;
    }
    else if (FUN_14029f2b0(nCondType) == 0xe)
    {
        return 0;
    }
    else if (nCondType == 0x7b)
    {
        return 3;
    }
    return 4;
}

// The time (as a date string) an achievement entry was recorded, or "" when it was never.
// @0x14093e330
CStringW FUN_14093e330(CAchieve* pAchieve, int nKey)
{
    if (pAchieve == 0)
        return CStringW(L"");
    __int64 nTime = pAchieve->GetValue(nKey);
    if (nTime == 0)
        return CStringW(L"");
    return FUN_14093f800(nTime);
}

#ifndef MS2_HOOK_DLL
// @0x14093e3e0
MS2Ptr<CAchieveUIData::SpecialRewardDesc> CAchieveUIData::FindSpecialReward(int nId, int nGrade)
{
    MS2Ptr<SpecialRewardDesc> pDesc(0);
    if (Unk_LockGuard guard = s_lockTables) {} else
    {
        s_mapSpecial.Lookup((ULONGLONG)(unsigned)nId << 32 | (__int64)nGrade, pDesc);
    }
    return pDesc;
}
#endif

// ---- CAchieveCategory ---------------------------------------------------------------------------------------------------------

// @0x14093e4a0
CAchieveCategory::CAchieveCategory()
    : m_nId(0), m_nTab(0), m_nTree(0)
{
}

// @0x14093e570
CAchieveCategory::~CAchieveCategory()
{
}

#ifndef MS2_HOOK_DLL
// @0x14093e610
// MS2-FUNCTIONAL: the exe builds the file / directory CStringA temps with early destruction; no source form found
bool CAchieveCategory::Load()
{
    TiXmlDocument doc;
    CStringA strPath = FUN_14071a5b0(CStringA("Table"), CStringA("achieveCategory.xml"));
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    Unk_ElemArray aElem;
    aElem.FUN_140163e20();
    FUN_14028faa0(pRoot, "category", "id", &aElem);
    for (unsigned __int64 i = 0; i < aElem.FUN_14016d900(); i++)
    {
        Unk_140165cf0* pElem = aElem.FUN_140164a30(i);
        MS2Ptr<CAchieveCategory> pCat(new CAchieveCategory);
        FUN_1408731e0(pElem, "id", pCat->m_nId);
        FUN_140940370(pElem, "tab", &pCat->m_nTab);
        FUN_140940430(pElem, "tree", &pCat->m_nTree);
        FUN_1408733e0(pElem, "categoryTag", pCat->m_strCategoryTag);
        FUN_1408733e0(pElem, "contentsTag", pCat->m_strContentsTag);
        FUN_140873420(pElem, "eventFilter", pCat->m_strEventFilter);
        for (Unk_140165cf0* pChildElem = pElem->FUN_140165cf0("child"); pChildElem != 0; pChildElem = reinterpret_cast<Unk_140165cf0*>(reinterpret_cast<Unk_140168650*>(pChildElem)->FUN_140168650("child")))
        {
            MS2Ptr<CAchieveCategory> pChild(new CAchieveCategory);
            FUN_1408731e0(pChildElem, "id", pChild->m_nId);
            FUN_140940370(pElem, "tab", &pChild->m_nTab);
            FUN_1408733e0(pChildElem, "categoryTag", pChild->m_strCategoryTag);
            FUN_1408733e0(pChildElem, "contentsTag", pChild->m_strContentsTag);
            pCat->m_aChildren.Add(pChild);
        }
        s_aCategory.Add(pCat);
    }
    SetInit(true);
    aElem.FUN_1401644e0();
    return true;
}
#endif

// @0x14093eae0
void CAchieveCategory::GetTabs(List& rOut)
{
    CheckInit();
    for (size_t i = 0; i < s_aCategory.GetCount(); i++)
    {
        MS2Ptr<CAchieveCategory> pTab = s_aCategory[i];
        if (!pTab->IsOpen())
            continue;
        rOut.Add(pTab);
    }
}

// @0x14093eb90
void CAchieveCategory::GetRows(List& rOut)
{
    CheckInit();
    for (size_t i = 0; i < s_aCategory.GetCount(); i++)
    {
        MS2Ptr<CAchieveCategory> pTab = s_aCategory[i];
        if (!pTab->IsOpen())
            continue;
        rOut.Add(pTab);
        for (size_t j = 0; j < pTab->m_aChildren.GetCount(); j++)
        {
            MS2Ptr<CAchieveCategory> pChild = pTab->m_aChildren[j];
            if (!pChild->IsOpen())
                continue;
            rOut.Add(pChild);
        }
    }
}

// The nIndex-th open row (tabs and their open children counted in display order).
#ifndef MS2_HOOK_DLL
// @0x14093ece0
MS2Ptr<CAchieveCategory> CAchieveCategory::GetRow(int nIndex)
{
    CheckInit();
    int nCount = 0;
    for (size_t i = 0; i < s_aCategory.GetCount(); i++)
    {
        MS2Ptr<CAchieveCategory> pTab = s_aCategory[i];
        if (!pTab->IsOpen())
            continue;
        if (nCount++ == nIndex)
            return pTab;
        for (size_t j = 0; j < pTab->m_aChildren.GetCount(); j++)
        {
            MS2Ptr<CAchieveCategory> pChild = pTab->m_aChildren[j];
            if (!pChild->IsOpen())
                continue;
            if (nCount++ == nIndex)
                return pChild;
        }
    }
    return MS2Ptr<CAchieveCategory>(0);
}
#endif

#ifndef MS2_HOOK_DLL
// @0x14093ef10
MS2Ptr<CAchieveCategory> CAchieveCategory::FindById(int nId)
{
    CheckInit();
    for (size_t i = 0; i < s_aCategory.GetCount(); i++)
    {
        MS2Ptr<CAchieveCategory> pTab = s_aCategory[i];
        if (pTab->m_nId == nId)
            return s_aCategory[i];
        for (size_t j = 0; j < pTab->m_aChildren.GetCount(); j++)
        {
            MS2Ptr<CAchieveCategory> pChild = pTab->m_aChildren[j];
            if (pChild->m_nId == nId)
                return pChild;
        }
    }
    return MS2Ptr<CAchieveCategory>(0);
}
#endif

#ifndef MS2_HOOK_DLL
// @0x14093f0d0
int CAchieveCategory::FindIdByTab(int nTab)
{
    CheckInit();
    for (size_t i = 0; i < s_aCategory.GetCount(); i++)
    {
        MS2Ptr<CAchieveCategory> pTab = s_aCategory[i];
        if (pTab->m_nTab == nTab)
            return pTab->m_nId;
        for (size_t j = 0; j < pTab->m_aChildren.GetCount(); j++)
        {
            MS2Ptr<CAchieveCategory> pChild = pTab->m_aChildren[j];
            if (pChild->m_nTab == nTab)
                return pChild->m_nId;
        }
    }
    return 0;
}
#endif

// @0x14093f240
int CAchieveCategory::IsOpen()
{
    if (m_strEventFilter.GetLength() != 0)
    {
        if (FUN_14015a050()->FUN_140cead80(m_strEventFilter))
            return 1;
        return 0;
    }
    return 1;
}

// @0x14093f2d0
int CAchieveCategory::Matches(unsigned nAchieveId)
{
    MS2Ptr<CAchieveData> pData = GetAchieveData(nAchieveId);
    if (pData.IsNull())
        return 0;
    if (m_nTab == 0)
    {
        if (pData->m_nType == 9)
            return 0;
    }
    else
    {
        if (m_nTab == 1)
            return 0;
        if (m_nTab == 2 && pData->m_nType != 9)
            return 0;
    }
    if (m_strCategoryTag.GetLength() != 0)
    {
        if (pData->m_strCategoryTag.Find((const char*)m_strCategoryTag, 0) == -1)
            return 0;
    }
    if (m_strContentsTag.GetLength() != 0)
    {
        if (pData->m_strContentsTag.Find((const char*)m_strContentsTag, 0) == -1)
            return 0;
    }
    return 1;
}

// "minutes seconds" text of a duration given in seconds.
// @0x14093f4d0
CStringW FUN_14093f4d0(int nSeconds)
{
    CStringW strText;
    int nMinutes = nSeconds / 60;
    int nRest = nSeconds % 60;
    if (nMinutes != 0)
        strText += FUN_1408116a0(0x801, nMinutes);
    if (nRest != 0)
    {
        if (strText.GetLength() != 0)
            strText += " ";
        strText += FUN_1408116a0(0x802, nRest);
    }
    if (strText.GetLength() == 0)
    {
        int nZero = 0;
        strText = FUN_1408116a0(0x802, nZero);
    }
    return strText;
}

// A distance in millimetres as metres / kilometres text.
// @0x14093f670
CStringW FUN_14093f670(int nValue)
{
    CStringW strText;
    if (nValue < 1000)
    {
        strText = FUN_1408116a0(0x778, nValue);
    }
    else if (nValue % 1000 == 0)
    {
        int nKilo = nValue / 1000;
        strText = FUN_1408116a0(0x779, nKilo);
    }
    else
    {
        float fKilo = (float)nValue / 1000.0f;
        strText = FormatStringId(0x77a, fKilo);
    }
    return strText;
}

// @0x14093f800
CStringW FUN_14093f800(__int64 nTime)
{
    CMsTime time = FUN_1406c47a0(nTime);
    CStringW str = FUN_14083bab0(time, CStringW(L"/"));
    return str;
}

// @0x14093f8a0
int CAchieveCategory::ParseTab(CStringA& strTab)
{
    if (strTab.CompareNoCase("summary") == 0)
        return 1;
    else if (strTab.CompareNoCase("emblem") == 0)
        return 2;
    else if (strTab.CompareNoCase("trophy") == 0)
        return 0;
    return 0;
}

// @0x14093f910
int CAchieveCategory::ParseTree(CStringA& strTree)
{
    if (strTree.CompareNoCase("expand") == 0)
        return 0;
    else if (strTree.CompareNoCase("collapse") == 0)
        return 1;
    else if (strTree.CompareNoCase("fixed") == 0)
        return 2;
    return 0;
}

// @0x140940370
int FUN_140940370(Unk_140165cf0* pNode, const char* pszName, int* pOut)
{
    CStringA str;
    int nRet = FUN_1408733e0(pNode, pszName, str);
    if (nRet == 0)
        *pOut = CAchieveCategory::ParseTab(str);
    return nRet;
}

// @0x140940430
int FUN_140940430(Unk_140165cf0* pNode, const char* pszName, int* pOut)
{
    CStringA str;
    int nRet = FUN_1408733e0(pNode, pszName, str);
    if (nRet == 0)
        *pOut = CAchieveCategory::ParseTree(str);
    return nRet;
}

// @0x1409404f0
CStringW FUN_1409404f0(__int64 nValue)
{
    return FUN_14083cb20(FUN_140719a00(nValue));
}

// ---- SpecialRewardDesc / init flags ---------------------------------------------------------------------------------------------------

// @0x140940ac0
CAchieveUIData::SpecialRewardDesc::SpecialRewardDesc()
{
}

// @0x140940d20
CAchieveUIData::SpecialRewardDesc::~SpecialRewardDesc()
{
}

// @0x1409411e0
void CAchieveCategory::CheckInit()
{
    if (!s_bInit)
    {
        CStringA msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CAchieveCategory).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140941290
void CAchieveUIData::CheckInit()
{
    if (!s_bInit)
    {
        CStringA msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CAchieveUIData).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1409431a0
void CAchieveCategory::SetInit(bool bInit)
{
    s_bInit = bInit;
}

// @0x1409431b0
void CAchieveUIData::SetInit(bool bInit)
{
    s_bInit = bInit;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9d1c0-0x142c9d2d0 .text$yd
