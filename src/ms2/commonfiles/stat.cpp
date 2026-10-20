// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The stat table: the stat definitions (names, display
// strings, value kinds), the per-job stat values per level, the lookups on them and the merge of two stat option sets.
// MS2-UNIT: commonfiles\stat.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x1400bd140-0x1400bd1f0 .text$di
// MS2-RANGE: 0x14082e170-0x140835210 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H$0A@@?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@$$QEAH@Z 0x14082f420 ; unique
// MS2-PIN: ??$?0V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H$0A@@?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x14082f470 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@1@$$QEA_N@Z 0x14082f4c0 ; order
// MS2-PIN: ??$_Buynode@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x14082f530 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@1@QEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x1408305f0 ; unique
// MS2-PIN: ??$emplace@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x140830720 ; unique
// MS2-PIN: ??$forward@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@YA$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@0@AEAU10@@Z 0x1408307d0 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@0@AEAV10@@Z 0x1408307e0 ; order
// MS2-PIN: ??$insert@U?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@X@?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@1@@Z 0x1408307f0 ; unique
// MS2-PIN: ??$make_pair@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@YA?AU?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@0@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@$$QEAH@Z 0x140830830 ; unique
// MS2-PIN: ??1?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@XZ 0x140830f90 ; prop
// MS2-PIN: ??1?$pair@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@QEAA@XZ 0x140830fb0 ; unique
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1408313d0 ; prop
// MS2-PIN: ?GetKeyAt@?$CAtlMap@W4Unk_StatKey@@V?$Unk_StatOptPtr@VBaseOption@@@@V?$CElementTraits@W4Unk_StatKey@@@ATL@@V?$CElementTraits@V?$Unk_StatOptPtr@VBaseOption@@@@@4@@ATL@@QEBAAEBW4Unk_StatKey@@PEAU__POSITION@@@Z 0x140831c10 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@W4Unk_StatKey@@V?$Unk_StatOptPtr@VBaseOption@@@@V?$CElementTraits@W4Unk_StatKey@@@ATL@@V?$CElementTraits@V?$Unk_StatOptPtr@VBaseOption@@@@@4@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140831c80 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HUStatLevelValues@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@UStatLevelValues@@@3@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x140831cd0 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@W4Unk_StatKey@@V?$Unk_StatOptPtr@VBaseOption@@@@V?$CElementTraits@W4Unk_StatKey@@@ATL@@V?$CElementTraits@V?$Unk_StatOptPtr@VBaseOption@@@@@4@@ATL@@QEBAPEAU__POSITION@@XZ 0x140831eb0 ; unique
// MS2-PIN: ?Hash@?$CDefaultHashTraits@H@ATL@@SAKAEBH@Z 0x140831fb0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@XZ 0x140834260 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@2@XZ 0x140834270 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@2@XZ 0x140834280 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@XZ 0x1408342b0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@XZ 0x1408342c0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x1408342d0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x1408342e0 ; unique
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEBAAEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@XZ 0x1408343d0 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x140834f90 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\stat.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <vector>
#include <atlcoll.h>
#include "stat.h"
#include "itemenchantinfo.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14071ae20(const CString& strFile);                          // the string table directory
int FUN_1408731e0(Unk_140165cf0*, const char*, int&);
void FUN_1408732e0(Unk_140165cf0*, const char*, __int64&);
void FUN_1408733e0(Unk_140165cf0*, const char*, CString&);
void FUN_140873420(Unk_140165cf0*, const char*, CStringW&);
const char* FUN_14016d7d0(const void* pTypeDescriptor);                 // the decorated name of a type
CString FUN_14016a5c0(const char* pszName, int);                        // its readable form
extern const char CStat_RTTI_Type_Descriptor[];                         // 0x143a65c80
extern CStringA DAT_143aacc88;                                          // the empty name
extern CStringW DAT_143aacc90;                                          // the text shown for an unknown id

typedef ATL::CAtlMap<int, StatLevelValues, ATL::CDefaultElementTraits<int> > StatLevelMap;

// The option pointer as this unit instantiates it: the reference is added through an out-of-line helper (the exe calls the
// COMDAT thunk 0x1402867c0 that commonstruct.cpp also owns), unlike the inlined Unk_EnchantPtr<BaseOption>.
template<class T> class Unk_StatOptPtr {
public:
    Unk_StatOptPtr() : p(0) {}
    Unk_StatOptPtr(const Unk_StatOptPtr& o) : p(o.p) { AddRef(); }
    Unk_StatOptPtr(T* value) : p(value) { AddRef(); }
    explicit Unk_StatOptPtr(int) : p(0) {}
    ~Unk_StatOptPtr() { Release(); }
    Unk_StatOptPtr& operator=(const Unk_StatOptPtr& o) { o.AddRef(); Release(); p = o.p; return *this; }
    T* operator->() const { return p; }
    bool operator==(T* value) const { return p == value; }
    operator T*() const { return p; }
    T* get() const { return p; }
private:
    void AddRef() const { if (p) AddRefImpl(0); }
    __declspec(noinline) static void AddRefObject(T* value) { reinterpret_cast<Unk_EnchantRef*>(value)->FUN_14015b020(); }
    void AddRefImpl(void*) const { AddRefObject(p); }
    void Release() { if (p) { ReleaseImpl(0); p = 0; } }
    void ReleaseImpl(void*) {
        if (reinterpret_cast<Unk_EnchantRef*>(p)->FUN_140159bc0() == 0) {
            AddRefObject(p); reinterpret_cast<Unk_EnchantRef*>(p)->FUN_140159ba0();
        }
    }
    void* pad; T* p;
};
enum Unk_StatKey {};   // the stat id key of an option set
typedef ATL::CAtlMap<Unk_StatKey, Unk_StatOptPtr<BaseOption> > StatOptionMap;
typedef TPtredDummy<StatOptionMap> StatOptionSet;
void FUN_140267220(BaseOption* pThis, Unk_StatOptPtr<BaseOption> spOther);   // merge the other option into this one

// ---- the stat table (static initializers in .text$di, in this order) ----

static std::vector<StatDefinition> s_definitions;       // 0x143ab1b30 the 35 stats, by id
static StatLevelMap s_levels(17, 0.75f, 0.25f, 2.25f, 10);   // 0x143ab1b50 job -> values per level
static std::map<CStringA, int> s_idByName;              // 0x143ab1b98 option name -> stat id
static bool s_valid;                                    // 0x143ab1b20
void SetValid(bool bValid);

// @0x14082e170
StatDefinition::StatDefinition() : m_nId(-1), m_strName(""), m_strValueText(L""), m_strCommonText(L"")
{
}

// @0x14082e1f0
StatDefinition::StatDefinition(int nId, CStringA strName, int nValueType, CStringW strValueText, CStringW strCommonText)
    : m_nId(nId), m_strName(strName), m_nValueType(nValueType), m_strValueText(strValueText), m_strCommonText(strCommonText)
{
}

// @0x14082e2b0
// MS2-FUNCTIONAL: temp/EH layout of the option merge differs
void MergeOptions(StatOptionSet* pDest, MS2Ptr<StatOptionSet> spSource)
{
    if (!spSource)
        return;
    if (spSource->value.IsEmpty())
        return;
    for (POSITION pos = spSource->value.GetStartPosition(); pos; spSource->value.GetNext(pos))
    {
        Unk_StatKey nKey = spSource->value.GetKeyAt(pos);
        Unk_StatOptPtr<BaseOption> spOption = spSource->value.GetValueAt(pos);
        if (spOption == 0)
            continue;
        Unk_StatOptPtr<BaseOption> spExisting(0);
        if (!pDest->value.Lookup(nKey, spExisting))
            pDest->value.SetAt(nKey, spOption);
        else
            FUN_140267220(spExisting, Unk_StatOptPtr<BaseOption>(spOption));
    }
}

// @0x14082e5b0
int LoadStatNames(std::map<int, CStringW>& rNames)
{
    CString strPath = FUN_14071ae20("stringStatName.xml");
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return 0;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
        return 0;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        CStringW strName;
        CStringW strUnused;
        int nId;
        FUN_1408731e0(pNode, "id", nId);
        FUN_140873420(pNode, "name", strName);
        rNames[nId] = strName;
    }
    return 1;
}

// @0x14082e7b0
// MS2-FUNCTIONAL: local layout/EH states differ
int LoadStatDefinitions()
{
    s_definitions.clear();
    s_definitions.resize(0x23);
    std::map<int, CStringW> names;
    LoadStatNames(names);
    CString strPath = FUN_14071a5b0("Table", "statStringTable.xml");
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return 0;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
        return 0;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        CStringA strOption;
        int nId;
        int nValueType;
        int nCommonId;
        int nValueId;
        FUN_1408731e0(pNode, "id", nId);
        FUN_1408733e0(pNode, "option", strOption);
        FUN_1408731e0(pNode, "valueType", nValueType);
        FUN_1408731e0(pNode, "commonStringID", nCommonId);
        FUN_1408731e0(pNode, "valueStringID", nValueId);
        s_definitions[nId] = StatDefinition(nId, strOption, nValueType, names[nValueId], names[nCommonId]);
    }
    names.clear();
    return 1;
}

// @0x14082e4b0
int LoadStats()
{
    if (!LoadStatDefinitions())
        return 0;
    for (StatDefinition definition : s_definitions)
    {
        s_idByName.insert(std::make_pair(definition.GetName(), definition.GetId()));
    }
    SetValid(true);
    return 1;
}

// @0x14082eb80
// MS2-FUNCTIONAL: stack layout of the 56000-byte local differs
int LoadUserStats(unsigned nJob)
{
    CStringA strFile;
    strFile.Format("userStat%d.xml", nJob);
    CString strPath = FUN_14071a5b0("Table/Server", strFile);
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return 0;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
        return 0;
    StatLevelValues values;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("stat"); pNode != 0; pNode = pNode->FUN_140168650("stat"))
    {
        int nLevel = 1;
        if (FUN_1408731e0(pNode, "lev", nLevel) != 1)
        {
            for (int i = 0; i < 0x23; ++i)
            {
                StatDefinition& definition = s_definitions[i];
                int nId = definition.GetId();
                CStringA strName = definition.GetName();
                FUN_1408732e0(pNode, strName, values.m_values[nLevel - 1][nId]);
            }
        }
    }
    s_levels.SetAt(nJob, values);
    return 1;
}

// @0x14082ee80
int FindStatByName(const CStringA& strName)
{
    for (int i = 0; i < 0x23; ++i)
    {
        if (s_definitions[i].GetName().CompareNoCase(strName) == 0)
            return s_definitions[i].GetId();
    }
    return -1;
}

// @0x14082ef20
int GetStatIdByName(const CStringA& strName)
{
    std::map<CStringA, int>::iterator it = s_idByName.find(strName);
    if (it != s_idByName.end())
        return it->second;
    MS2_ASSERT_AT(511, 0);
    return -1;
}

// @0x14082efb0
const CStringA& GetStatName(unsigned nId)
{
    unsigned nIndex = nId;
    if (nIndex >= 0x23)
        return DAT_143aacc88;
    return s_definitions[nIndex].GetName();
}

// @0x14082f000
CStringW GetStatCommonText(unsigned nId)
{
    unsigned nIndex = nId;
    if (nIndex >= 0x23)
        return DAT_143aacc90;
    return s_definitions[nIndex].GetCommonText();
}

// @0x14082f090
CStringW GetStatValueText(unsigned nId)
{
    unsigned nIndex = nId;
    if (nIndex >= 0x23)
        return DAT_143aacc90;
    return s_definitions[nIndex].GetValueText();
}

void CheckValid();

// @0x14082f120
__int64 GetStatValue(int nJob, unsigned short nLevel, int nStat)
{
    CheckValid();
    StatLevelMap::CPair* pPair = s_levels.Lookup(nJob);
    if (pPair)
    {
        StatLevelValues* pValues = &pPair->m_value;
        if (nLevel < 200)
            return pValues->m_values[nLevel][nStat];
    }
    return 0;
}

// @0x14082f1a0
int IsPercentStat(int nStat)
{
    switch (nStat)
    {
    case 4:
        return true;
    default:
        return false;
    }
}

// @0x14082f1d0
bool IsStatKindOne(int nStat)
{
    (void)((s_definitions[nStat].m_nValueType != 0) || (_wassert(L"m_statTo[stat].m_valueType != eOptionValue::kNone", _CRT_WIDE(MS2_THIS_FILE), 573), 0));
    return s_definitions[nStat].m_nValueType == 1;
}

// @0x14082f250
bool IsStatKindTwo(int nStat)
{
    (void)((s_definitions[nStat].m_nValueType != 0) || (_wassert(L"m_statTo[stat].m_valueType != eOptionValue::kNone", _CRT_WIDE(MS2_THIS_FILE), 579), 0));
    return s_definitions[nStat].m_nValueType == 2;
}

// @0x14082f2d0
int GetStatValueType(int nStat)
{
    return s_definitions[nStat].m_nValueType;
}

// @0x14082f300
void CheckStatName(const CStringA& strName)
{
    GetStatIdByName(strName);
}

// @0x1408315b0
void CheckValid()
{
    if (!s_valid)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(FUN_14016d7d0(CStat_RTTI_Type_Descriptor), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140833470
void SetValid(bool bValid)
{
    s_valid = bValid;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c3b0-0x142c9c410 .text$yd
