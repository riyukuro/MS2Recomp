// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CFieldMetaTable: Table/FieldMetaData.xml (npc / pet /
// liftable / interact object -> field index, field portals, taxi stations, spawn-npc guarantees), CFieldFeatureChecker
// and CSpawnNpcGuaranteeInfo.
// MS2-UNIT: unit_1406f96f0
// MS2-RANGE: 0x1406f96f0-0x140704bd0 .text$mn
// MS2-RANGE: 0x1400bbd90-0x1400bbde0 .text$di
// MS2-RANGE: 0x142c9ba60-0x142c9ba80 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0CFieldMetaTable@@QEAA@XZ 0x1406f9890 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1406fe690 ; unique
// MS2-PIN: ??$make_pair@AEAIAEAI@std@@YA?AU?$pair@II@0@AEAI0@Z 0x1406fe730 ; unique
// MS2-PIN: ??0?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@QEAA@AEBV0@@Z 0x1406feb00 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@PEAX@std@@@std@@QEAA@XZ 0x1406fee10 ; unique
// MS2-PIN: ??4?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@QEAAAEAV0@AEBUUnk_FieldNewTag@@@Z 0x1406ffb10 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@II@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@U?$pair@II@std@@@2@XZ 0x140703f80 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@II@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@U?$pair@II@std@@@2@XZ 0x140703f90 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??$?0U?$pair@II@std@@$$V$0A@@?$tuple@$$QEAU?$pair@II@std@@@std@@QEAA@$$QEAU?$pair@II@1@@Z 0x1406fcb50 ; cf3: map<pair<uint,uint>,FieldTimeSpan> / CAtlMap<int,ListPtr> look-alike (the uint,bool / uint,ListPtr twins live elsewhere)
// MS2-PIN: ??$?0U?$pair@II@std@@@?$_Tuple_val@$$QEAU?$pair@II@std@@@std@@QEAA@$$QEAU?$pair@II@1@@Z 0x1406fcbb0 ; cf3: map<pair<uint,uint>,FieldTimeSpan> / CAtlMap<int,ListPtr> look-alike (the uint,bool / uint,ListPtr twins live elsewhere)
// MS2-PIN: ??$?0U_Exact_args_t@std@@U?$pair@II@1@$$V$0A@@?$tuple@$$QEAU?$pair@II@std@@@std@@QEAA@U_Exact_args_t@1@$$QEAU?$pair@II@1@@Z 0x1406fcbe0 ; cf3: map<pair<uint,uint>,FieldTimeSpan> / CAtlMap<int,ListPtr> look-alike (the uint,bool / uint,ListPtr twins live elsewhere)
// MS2-PIN: ??$_Try_emplace@U?$pair@II@std@@$$V@?$map@U?$pair@II@std@@UUnk_FieldTimeSpan@@U?$less@U?$pair@II@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@II@1@@Z 0x1406fe320 ; cf3: map<pair<uint,uint>,FieldTimeSpan> / CAtlMap<int,ListPtr> look-alike (the uint,bool / uint,ListPtr twins live elsewhere)
// MS2-PIN: ??$forward_as_tuple@U?$pair@II@std@@@std@@YA?AV?$tuple@$$QEAU?$pair@II@std@@@0@$$QEAU?$pair@II@0@@Z 0x1406fe6e0 ; cf3: map<pair<uint,uint>,FieldTimeSpan> / CAtlMap<int,ListPtr> look-alike (the uint,bool / uint,ListPtr twins live elsewhere)
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1407004a0 ; cf3: map<pair<uint,uint>,FieldTimeSpan> / CAtlMap<int,ListPtr> look-alike (the uint,bool / uint,ListPtr twins live elsewhere)
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBI_N@std@@@?$_Tree@V?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBI_N@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBI_N@1@@Z 0x1406fcd40
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBI_N@std@@PEAX@1@AEBI@Z 0x1406fe280
// MS2-PIN: ??$construct@PEAU?$_Tree_node@IPEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@QEAPEAU?$_Tree_node@IPEAX@1@AEAPEAU31@@Z 0x1406fe4a0
// MS2-PIN: ??$_Kfn@$$CBI_N@?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@SAAEBIAEBU?$pair@$$CBI_N@1@@Z 0x1406fe670
// MS2-PIN: ??0?$CAtlMap@IUUnk_FieldTaxi@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_FieldTaxi@@@3@@ATL@@QEAA@IMMMI@Z 0x1406fe910
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x1406fec00
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x1406fec30
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAA@XZ 0x1406fed70
// MS2-PIN: ??0?$map@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@@std@@QEAA@XZ 0x1406fee30
// MS2-PIN: ??0CNode@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAA@HI@Z 0x1406feed0
// MS2-PIN: ??0CNode@?$CAtlMap@IUUnk_FieldTaxi@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_FieldTaxi@@@3@@ATL@@QEAA@II@Z 0x1406fef10
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@IEAA@H@Z 0x1406fefa0
// MS2-PIN: ??0CPair@?$CAtlMap@IUUnk_FieldTaxi@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_FieldTaxi@@@3@@ATL@@IEAA@I@Z 0x1406fefe0
// MS2-PIN: ??8?$MS2Ptr@VUnk_NpcRecord@@@@QEBA_NPEAVUnk_NpcRecord@@@Z 0x1406ff460
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1406ff750
// MS2-PIN: ?NewNode@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@HII@Z 0x1407010d0
// MS2-PIN: ?NewNode@?$CAtlMap@IUUnk_FieldTaxi@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_FieldTaxi@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x1407012e0
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1407028d0
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IUUnk_FieldTaxi@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_FieldTaxi@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1407029c0
// MS2-PIN: ?RemoveNode@?$CAtlMap@HV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140702b00
// MS2-PIN: ?RemoveNode@?$CAtlMap@IUUnk_FieldTaxi@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_FieldTaxi@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140702bc0
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IUUnk_FieldTaxi@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_FieldTaxi@@@3@@ATL@@QEAAXMMM_N@Z 0x1407030d0
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBI_N@std@@PEAX@2@XZ 0x140703610
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x1407037f0
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBI_N@std@@PEAX@2@@Z 0x140703ef0
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBI_N@std@@@std@@@2@XZ 0x140703f50
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@XZ 0x140703fd0
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@XZ 0x140703ff0
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@U?$pair@II@std@@UUnk_FieldTimeSpan@@U?$less@U?$pair@II@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x140704a50
// MS2-PIN: ??1?$map@I_NU?$less@I@std@@V?$allocator@U?$pair@$$CBI_N@std@@@2@@std@@QEAA@XZ 0x140704a70
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@1@XZ 0x1406ff5f0
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@II@std@@UUnk_FieldTimeSpan@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1406fe6c0
// MS2-PIN: ??__Es_names@@YAXXZ 0x1400bbd90
// MS2-PIN: ?Add@?$CAtlArray@VCMsTime@@V?$CElementTraits@VCMsTime@@@ATL@@@ATL@@QEAA_KAEBVCMsTime@@@Z 0x1406ffa60
// MS2-PIN: ??_GCSpawnNpcGuaranteeInfo@@UEAAPEAXI@Z 0x1406ffa20
// MS2-PIN: ??_7CFieldFeatureChecker@@6B?$CValidData@VCFieldFeatureChecker@@@@@ 0x142d7f1d0
// MS2-PIN: ??_7CFieldMetaTable@@6B?$TSingleton@VCFieldMetaTable@@@@@ 0x142d7f210
// MS2-PIN: ??_7CFieldMetaTable@@6B?$CValidData@VCFieldMetaTable@@@@@ 0x142d7f220
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\fieldmetatable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <stdio.h>
#include <typeinfo>
#include "fieldmetatable.h"
#include "fielddata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char*);              // first child element (also takes a document)
    Unk_140165cf0* FUN_140168650(const char*);              // next sibling element
};
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14016a5c0(const char* psz, int n);
int FUN_140873220(Unk_140165cf0*, const char*, unsigned&);
int FUN_1408731e0(Unk_140165cf0*, const char*, int&);
int FUN_1408736d0(Unk_140165cf0*, const char*, bool&);
const char* FUN_14086f4b0(Unk_140165cf0*, const char*);
int FUN_1408733e0(Unk_140165cf0*, const char*, CString&);
__int64 FUN_14086b2a0(int nYear, int nMonth, int nDay, int nHour, int nMinute, int nSecond);   // server-time value
__int64 FUN_140869440();                                    // the current server time
int FUN_140408410(ATL::CAtlArray<unsigned>* pArray, const unsigned* pValue);   // index of the value, -1 when absent

// The npc record the table checks existence of.
class Unk_NpcRecord : public CPtred {};
MS2Ptr<Unk_NpcRecord> FUN_1406cd330(int nNpcId);

// The locale / feature gate: is the feature named by the field's <feature> enabled.
class Unk_140166410 { public: bool FUN_14036d4b0(const CStringW& strFeature); };
Unk_140166410* FUN_140166410();

// field id -> <feature> name of every <fieldData> (filled once by BuildNameTable).
static ATL::CAtlMap<int, CStringW> s_names;

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CFieldFeatureChecker::s_bInit;
#endif
#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CFieldMetaTable::s_bInit;
#endif

// @0x1406f96f0
CFieldFeatureChecker::CFieldFeatureChecker()
{
}

#ifndef MS2_HOOK_DLL
// @0x1406f9750
void CFieldFeatureChecker::BuildNameTable()
{
    std::vector<MS2Ptr<CFieldData> > fields;
    CFieldData::FUN_140374090(fields);
    std::vector<MS2Ptr<CFieldData> >& range = fields;
    MS2Ptr<CFieldData>* it = range._Unchecked_begin();
    MS2Ptr<CFieldData>* itEnd = range._Unchecked_end();
    for (; it != itEnd; ++it)
    {
        MS2Ptr<CFieldData>& field = *it;
        s_names.SetAt(field->m_nFieldID, field->m_strFeature);
    }
    SetInit(true);
}
#endif

#ifndef MS2_HOOK_DLL
// @0x1406f9820
int CFieldFeatureChecker::IsEnabled(int nFieldId)
{
    CheckInit();
    CStringW strFeature;
    s_names.Lookup(nFieldId, strFeature);
    return FUN_140166410()->FUN_14036d4b0(strFeature);
}
#endif

// @0x1406f9890
CFieldMetaTable::CFieldMetaTable()
    : m_npcFields(17, 0.75f, 0.25f, 2.25f, 10), m_fieldNpcs(17, 0.75f, 0.25f, 2.25f, 10),
      m_taxi(17, 0.75f, 0.25f, 2.25f, 10), m_portalTargets(17, 0.75f, 0.25f, 2.25f, 10),
      m_portalTargets2(17, 0.75f, 0.25f, 2.25f, 10), m_portalType8(17, 0.75f, 0.25f, 2.25f, 10),
      m_indoorPortals(17, 0.75f, 0.25f, 2.25f, 10), m_indoorClosure(17, 0.75f, 0.25f, 2.25f, 10),
      m_reverse(17, 0.75f, 0.25f, 2.25f, 10), m_guarantee(10), m_interact(17, 0.75f, 0.25f, 2.25f, 10),
      m_pet(17, 0.75f, 0.25f, 2.25f, 10), m_liftable(17, 0.75f, 0.25f, 2.25f, 10)
{
    CFieldFeatureChecker::BuildNameTable();
    FUN_1406f9dd0();
}

// @0x1406f9c20
CFieldMetaTable::~CFieldMetaTable()
{
    m_indoorPortals.RemoveAll();
    m_indoorClosure.RemoveAll();
    m_reverse.RemoveAll();
}

// @0x1406f9dd0
void CFieldMetaTable::FUN_1406f9dd0()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("FieldMetaData.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }

    // <npc id=><field id= startTime= endTime=/></npc>
    for (Unk_140165cf0* pNpc = pRoot->FUN_140165cf0("npc"); pNpc != 0; pNpc = pNpc->FUN_140168650("npc"))
    {
        unsigned nNpcId;
        FUN_140873220(pNpc, "id", nNpcId);
        if (!(FUN_1406cd330(nNpcId) == 0))
        {
            for (Unk_140165cf0* pField = pNpc->FUN_140165cf0("field"); pField != 0; pField = pField->FUN_140168650("field"))
            {
                unsigned nFieldId = 0;
                FUN_140873220(pField, "id", nFieldId);
                Unk_FieldIdListPtr pFields;
                if (!m_npcFields.Lookup(nNpcId, pFields))
                {
                    pFields = Unk_FieldNewTag(0);
                    m_npcFields.SetAt(nNpcId, pFields);
                }
                pFields.get()->AddTail(nFieldId);
                Unk_FieldIdListPtr pNpcs(0);
                if (!m_fieldNpcs.Lookup(nFieldId, pNpcs))
                {
                    pNpcs = Unk_FieldNewTag(0);
                    m_fieldNpcs.SetAt(nFieldId, pNpcs);
                }
                pNpcs.get()->AddTail(nNpcId);
                if (FUN_14086f4b0(pField, "startTime") != 0 && FUN_14086f4b0(pField, "endTime") != 0)
                {
                    CString strStart;
                    CString strEnd;
                    FUN_1408733e0(pField, "startTime", strStart);
                    FUN_1408733e0(pField, "endTime", strEnd);
                    __int64 nEnd = 0;
                    __int64 nStart = 0;
                    if (FUN_1406fc8a0(CString(strStart), &nStart))
                    {
                        if (FUN_1406fc8a0(CString(strEnd), &nEnd))
                        {
                            Unk_FieldTimeSpan span;
                            span.Set(nStart, nEnd);
                            m_activeTimes[std::make_pair(nNpcId, nFieldId)] = span;
                        }
                    }
                }
            }
        }
    }

    // <taxiStation field= IsHomePrivilege=/>
    for (Unk_140165cf0* pTaxi = pRoot->FUN_140165cf0("taxiStation"); pTaxi != 0; pTaxi = pTaxi->FUN_140168650("taxiStation"))
    {
        unsigned nField = 0;
        FUN_140873220(pTaxi, "field", nField);
        bool bHomePrivilege = false;
        FUN_1408736d0(pTaxi, "IsHomePrivilege", bHomePrivilege);
        Unk_FieldTaxi taxi;
        taxi.m_nField = nField;
        taxi.m_nHomePrivilege = bHomePrivilege;
        m_taxi.SetAt(nField, taxi);
    }

    // <fieldPortal field= indoor=><portal targetField= portalType= id= portalIndoor=/></fieldPortal>
    std::map<unsigned, bool> outdoor;
    for (Unk_140165cf0* pPortal = pRoot->FUN_140165cf0("fieldPortal"); pPortal != 0; pPortal = pPortal->FUN_140168650("fieldPortal"))
    {
        unsigned nField = 0;
        int nIndoor = 0;
        FUN_1408731e0(pPortal, "indoor", nIndoor);
        FUN_140873220(pPortal, "field", nField);
        if (FUN_1406fc870(nField) != 0)
        {
            Unk_FieldIdListPtr pTargets;
            pTargets = Unk_FieldNewTag(0);
            m_portalTargets.SetAt(nField, pTargets);
            Unk_FieldIdListPtr pTargets2;
            pTargets2 = Unk_FieldNewTag(0);
            m_portalTargets2.SetAt(nField, pTargets2);
            unsigned nTarget = 0;
            for (Unk_140165cf0* pTo = pPortal->FUN_140165cf0("portal"); pTo != 0; pTo = pTo->FUN_140168650("portal"))
            {
                FUN_140873220(pTo, "targetField", nTarget);
                if (FUN_1406fc870(nTarget) != 0)
                {
                    pTargets.get()->AddTail(nTarget);
                    int nPortalType = 0;
                    FUN_1408731e0(pTo, "portalType", nPortalType);
                    if (nPortalType == 8)
                    {
                        unsigned nPortalId;
                        FUN_140873220(pTo, "id", nPortalId);
                        Unk_FieldIdListPtr pType8(0);
                        if (!m_portalType8.Lookup(nField, pType8))
                        {
                            pType8 = Unk_FieldNewTag(0);
                            m_portalType8.SetAt(nField, pType8);
                        }
                        if (pType8.get()->Find(nPortalId, 0) == 0)
                            pType8.get()->AddTail(nPortalId);
                    }
                    else if (nPortalType == 0)
                    {
                        pTargets2.get()->AddTail(nTarget);
                    }
                }
            }
            outdoor[nField] = (nIndoor == 0);
            Unk_FieldIdListPtr pIndoor;
            pIndoor = Unk_FieldNewTag(0);
            m_indoorPortals.SetAt(nField, pIndoor);
            unsigned nIndoorTarget = 0;
            for (Unk_140165cf0* pTo = pPortal->FUN_140165cf0("portal"); pTo != 0; pTo = pTo->FUN_140168650("portal"))
            {
                int nPortalIndoor = 0;
                FUN_1408731e0(pTo, "portalIndoor", nPortalIndoor);
                FUN_140873220(pTo, "targetField", nIndoorTarget);
                if (FUN_1406fc870(nIndoorTarget) != 0 && nPortalIndoor != 0)
                {
                    if (pIndoor.get()->Find(nIndoorTarget, 0) == 0)
                        pIndoor.get()->AddTail(nIndoorTarget);
                }
            }
        }
    }

    // <interactObject id=><field id=/></interactObject>
    for (Unk_140165cf0* pObj = pRoot->FUN_140165cf0("interactObject"); pObj != 0; pObj = pObj->FUN_140168650("interactObject"))
    {
        int nObjId = 0;
        FUN_1408731e0(pObj, "id", nObjId);
        for (Unk_140165cf0* pField = pObj->FUN_140165cf0("field"); pField != 0; pField = pField->FUN_140168650("field"))
        {
            unsigned nFieldId = 0;
            FUN_140873220(pField, "id", nFieldId);
            Unk_FieldIdListPtr pFields(0);
            if (!m_interact.Lookup(nObjId, pFields))
            {
                pFields = Unk_FieldNewTag(0);
                m_interact.SetAt(nObjId, pFields);
            }
            pFields.get()->AddTail(nFieldId);
        }
    }

    // <pet id=><field id=/></pet>
    for (Unk_140165cf0* pPet = pRoot->FUN_140165cf0("pet"); pPet != 0; pPet = pPet->FUN_140168650("pet"))
    {
        unsigned nPetId = 0;
        FUN_140873220(pPet, "id", nPetId);
        for (Unk_140165cf0* pField = pPet->FUN_140165cf0("field"); pField != 0; pField = pField->FUN_140168650("field"))
        {
            unsigned nFieldId = 0;
            FUN_140873220(pField, "id", nFieldId);
            Unk_FieldIdListPtr pFields(0);
            if (!m_pet.Lookup(nPetId, pFields))
            {
                pFields = Unk_FieldNewTag(0);
                m_pet.SetAt(nPetId, pFields);
            }
            pFields.get()->AddTail(nFieldId);
        }
    }

    // <liftable id=><field id=/></liftable>
    for (Unk_140165cf0* pLift = pRoot->FUN_140165cf0("liftable"); pLift != 0; pLift = pLift->FUN_140168650("liftable"))
    {
        unsigned nLiftId = 0;
        FUN_140873220(pLift, "id", nLiftId);
        for (Unk_140165cf0* pField = pLift->FUN_140165cf0("field"); pField != 0; pField = pField->FUN_140168650("field"))
        {
            unsigned nFieldId = 0;
            FUN_140873220(pField, "id", nFieldId);
            Unk_FieldIdListPtr pFields(0);
            if (!m_liftable.Lookup(nLiftId, pFields))
            {
                pFields = Unk_FieldNewTag(0);
                m_liftable.SetAt(nLiftId, pFields);
            }
            pFields.get()->AddTail(nFieldId);
        }
    }
    SetInit(true);

    // Fold the outdoor-only indoor portals into the closure: for each such field, the fields reachable from it.
    for (POSITION posField = m_indoorPortals.GetStartPosition(); posField != 0; m_indoorPortals.GetNext(posField))
    {
        unsigned nField = m_indoorPortals.GetKeyAt(posField);
        if (outdoor[nField] != 0)
        {
            Unk_FieldIdListPtr pSeed(Unk_FieldNewTag(0));
            Unk_FieldIdListPtr pDone(Unk_FieldNewTag(0));
            pSeed.get()->AddTail(nField);
            FUN_1406fbdf0(const_cast<const Unk_FieldIdListPtr&>(pSeed), const_cast<const Unk_FieldIdListPtr&>(pDone));
            if (pDone.get()->GetCount() != 0)
            {
                m_indoorClosure.SetAt(nField, pDone);
                POSITION pos = pDone.get()->GetHeadPosition();
                while (pos != 0)
                {
                    m_reverse.SetAt(pDone.get()->GetAt(pos), nField);
                    pDone.get()->GetNext(pos);
                }
            }
        }
    }
}

// @0x1406fb060
void CFieldMetaTable::FUN_1406fb060(unsigned nId, ATL::CAtlArray<unsigned>& out)
{
    Unk_FieldIdListPtr pFields(0);
    if (m_pet.Lookup(nId, pFields))
    {
        for (POSITION pos = pFields.get()->GetHeadPosition(); pos != 0; pFields.get()->GetNext(pos))
        {
            out.Add(pFields.get()->GetAt(pos));
        }
    }
}

// @0x1406fb120
void CFieldMetaTable::FUN_1406fb120(unsigned nId, ATL::CAtlArray<unsigned>& out)
{
    Unk_FieldIdListPtr pFields(0);
    if (m_liftable.Lookup(nId, pFields))
    {
        for (POSITION pos = pFields.get()->GetHeadPosition(); pos != 0; pFields.get()->GetNext(pos))
        {
            out.Add(pFields.get()->GetAt(pos));
        }
    }
}

// @0x1406fb1e0
void CFieldMetaTable::FUN_1406fb1e0(int nId, ATL::CAtlArray<unsigned>& out)
{
    Unk_FieldIdListPtr pFields(0);
    if (m_interact.Lookup(nId, pFields))
    {
        for (POSITION pos = pFields.get()->GetHeadPosition(); pos != 0; pFields.get()->GetNext(pos))
        {
            out.Add(pFields.get()->GetAt(pos));
        }
    }
}

// @0x1406fb2a0
void CFieldMetaTable::FUN_1406fb2a0(unsigned nId, ATL::CAtlArray<unsigned>& out)
{
    CheckInit();
    Unk_FieldIdListPtr pFields;
    if (m_npcFields.Lookup(nId, pFields))
    {
        for (POSITION pos = pFields.get()->GetHeadPosition(); pos != 0; pFields.get()->GetNext(pos))
        {
            unsigned nField = pFields.get()->GetAt(pos);
            if (FUN_140408410(&out, &nField) != -1)
                continue;
            if (!FUN_1406fbb50(nId, nField))
                continue;
            out.Add(nField);
        }
    }
}

// @0x1406fb3a0
void CFieldMetaTable::FUN_1406fb3a0(unsigned nId, Unk_FieldIdList& out)
{
    CheckInit();
    Unk_FieldIdListPtr pFields;
    if (m_npcFields.Lookup(nId, pFields))
    {
        for (POSITION pos = pFields.get()->GetHeadPosition(); pos != 0; pFields.get()->GetNext(pos))
        {
            unsigned nField = pFields.get()->GetAt(pos);
            if (out.Find(nField, 0) != 0)
                continue;
            if (!FUN_1406fbb50(nId, nField))
                continue;
            MS2Ptr<CFieldData> field = CFieldData::FUN_140374140(nField);
            if (field.IsNull())
                continue;
            if (!field->m_bMapSearch)
                continue;
            out.AddTail(nField);
        }
    }
}

// @0x1406fb520
void CFieldMetaTable::FUN_1406fb520(unsigned nId, Unk_FieldIdList& out)
{
    CheckInit();
    Unk_FieldIdListPtr pFields(0);
    if (m_npcFields.Lookup(nId, pFields))
    {
        for (POSITION pos = pFields.get()->GetHeadPosition(); pos != 0; pFields.get()->GetNext(pos))
        {
            unsigned nField = pFields.get()->GetAt(pos);
            if (!FUN_1406fbb50(nId, nField))
                continue;
            out.AddTail(nField);
        }
    }
}

// @0x1406fb610
void CFieldMetaTable::FUN_1406fb610(unsigned nFieldId, Unk_FieldIdList& out)
{
    Unk_FieldIdListPtr pNpcs(0);
    if (m_fieldNpcs.Lookup(nFieldId, pNpcs))
    {
        for (POSITION pos = pNpcs.get()->GetHeadPosition(); pos != 0; pNpcs.get()->GetNext(pos))
        {
            unsigned nNpc = pNpcs.get()->GetAt(pos);
            if (!FUN_1406fbb50(nNpc, nFieldId))
                continue;
            out.AddTail(nNpc);
        }
    }
}

// @0x1406fb700
int CFieldMetaTable::FUN_1406fb700(unsigned nId, unsigned* pOut)
{
    CheckInit();
    Unk_FieldIdListPtr pFields(0);
    if (m_npcFields.Lookup(nId, pFields))
    {
        for (POSITION pos = pFields.get()->GetHeadPosition(); pos != 0; pFields.get()->GetNext(pos))
        {
            unsigned nField = pFields.get()->GetAt(pos);
            if (!FUN_1406fbb50(nId, nField))
                continue;
            *pOut = nField;
            return 1;
        }
    }
    return 0;
}

// @0x1406fb810
void CFieldMetaTable::FUN_1406fb810(unsigned nFieldId, Unk_FieldIdList& out)
{
    CheckInit();
    FUN_1406fb610(nFieldId, out);
    Unk_FieldIdListPtr pIndoor(0);
    if (m_indoorPortals.Lookup(nFieldId, pIndoor))
    {
        for (POSITION pos = pIndoor.get()->GetHeadPosition(); pos != 0; pIndoor.get()->GetNext(pos))
        {
            FUN_1406fb610(pIndoor.get()->GetAt(pos), out);
        }
    }
}

// @0x1406fb900
void CFieldMetaTable::FUN_1406fb900(unsigned nFieldId, unsigned nGroupId, Unk_FieldIdList& out)
{
    MS2Ptr<CFieldData> field = CFieldData::FUN_140374140(nFieldId);
    if (!field.IsNull())
    {
        if (!field->FUN_140375130())
        {
            Unk_FieldIdList fields(10);
            GetInstance()->FUN_1406fc2f0(nGroupId, fields);
            for (POSITION pos = fields.GetHeadPosition(); pos != 0; fields.GetNext(pos))
            {
                unsigned nId = fields.GetAt(pos);
                GetInstance()->FUN_1406fb610(nId, out);
            }
        }
        else
        {
            GetInstance()->FUN_1406fb610(nGroupId, out);
        }
    }
}

// @0x1406fba40
int CFieldMetaTable::FUN_1406fba40(unsigned nId, int nField)
{
    CheckInit();
    Unk_FieldIdListPtr pFields;
    if (m_npcFields.Lookup(nId, pFields))
    {
        for (POSITION pos = pFields.get()->GetHeadPosition(); pos != 0; pFields.get()->GetNext(pos))
        {
            int nCandidate = pFields.get()->GetAt(pos);
            if (!FUN_1406fbb50(nId, nCandidate))
                continue;
            if (nField == nCandidate)
                return 1;
        }
    }
    return 0;
}

// @0x1406fbb50
bool CFieldMetaTable::FUN_1406fbb50(unsigned nNpc, unsigned nField)
{
    std::map<NpcFieldKey, Unk_FieldTimeSpan>::iterator it = m_activeTimes.find(std::make_pair(nNpc, nField));
    if (it == m_activeTimes.end())
        return true;
    if (it->second.Contains(FUN_140869440()))
        return true;
    return false;
}

// @0x1406fbc10
int CFieldMetaTable::FUN_1406fbc10(unsigned nField)
{
    Unk_FieldTaxi taxi;
    return m_taxi.Lookup(nField, taxi);
}

// @0x1406fbc50
unsigned CFieldMetaTable::FUN_1406fbc50(unsigned nField)
{
    Unk_FieldTaxi taxi;
    if (m_taxi.Lookup(nField, taxi))
        return taxi.m_nHomePrivilege;
    return 0;
}

// @0x1406fbca0
Unk_FieldIdListPtr CFieldMetaTable::FUN_1406fbca0(unsigned nField)
{
    Unk_FieldIdListPtr pTargets(0);
    bool bFound = m_portalTargets.Lookup(nField, pTargets);
    return bFound ? Unk_FieldIdListPtr(pTargets) : Unk_FieldIdListPtr(0);
}

// @0x1406fbdf0
void CFieldMetaTable::FUN_1406fbdf0(Unk_FieldIdListPtr pFrom, Unk_FieldIdListPtr pTo)
{
    CheckInit();
    if (pFrom == 0 || pTo == 0)
        return;
    Unk_FieldIdListPtr pMerged(Unk_FieldNewTag(0));
    for (POSITION posFrom = pFrom.get()->GetHeadPosition(); posFrom != 0; pFrom.get()->GetNext(posFrom))
    {
        unsigned nFrom = pFrom.get()->GetAt(posFrom);
        Unk_FieldIdListPtr pIndoor;
        if (m_indoorPortals.Lookup(nFrom, pIndoor))
        {
            if (!(pIndoor == 0))
            {
                POSITION posIndoor = pIndoor.get()->GetHeadPosition();
                while (posIndoor != 0)
                {
                    int nIndoor = pIndoor.get()->GetAt(posIndoor);
                    bool bFound = false;
                    POSITION posTo = pTo.get()->GetHeadPosition();
                    while (posTo != 0)
                    {
                        if (pTo.get()->GetAt(posTo) == nIndoor)
                        {
                            bFound = true;
                            break;
                        }
                        pTo.get()->GetNext(posTo);
                    }
                    if (!bFound)
                    {
                        pMerged.get()->AddTail(nIndoor);
                        pTo.get()->AddTail(nIndoor);
                    }
                    pIndoor.get()->GetNext(posIndoor);
                }
            }
        }
    }
    if (pMerged.get()->GetCount() != 0)
    {
        FUN_1406fbdf0(const_cast<const Unk_FieldIdListPtr&>(pMerged), const_cast<const Unk_FieldIdListPtr&>(pTo));
    }
}

// @0x1406fc110
int CFieldMetaTable::FUN_1406fc110(unsigned nKey, unsigned* pValue)
{
    CheckInit();
    if (m_reverse.Lookup(nKey, *pValue))
        return 1;
    return 0;
}

// @0x1406fc160
int CFieldMetaTable::FUN_1406fc160(unsigned nKey, Unk_FieldIdListPtr& pList)
{
    CheckInit();
    if (m_indoorPortals.Lookup(nKey, pList))
        return 1;
    return 0;
}

// @0x1406fc1b0
void CFieldMetaTable::FUN_1406fc1b0(std::set<unsigned>& seen, unsigned nField)
{
    Unk_FieldIdListPtr pList;
    if (FUN_1406fc160(nField, pList))
    {
        for (POSITION pos = pList.get()->GetHeadPosition(); pos != 0; pList.get()->GetNext(pos))
        {
            unsigned nNext = pList.get()->GetAt(pos);
            if (seen.find(nNext) == seen.end())
            {
                seen.insert(nNext);
                FUN_1406fc1b0(seen, nNext);
            }
        }
    }
}

// @0x1406fc2f0
void CFieldMetaTable::FUN_1406fc2f0(unsigned nField, Unk_FieldIdList& out)
{
    std::set<unsigned> seen;
    seen.insert(nField);
    FUN_1406fc1b0(seen, nField);
    std::set<unsigned>::iterator it = seen.begin();
    while (it != seen.end())
    {
        out.AddTail(*it);
        it++;
    }
}

// @0x1406fc3c0
Unk_FieldIdListPtr CFieldMetaTable::FUN_1406fc3c0(unsigned nField)
{
    CheckInit();
    Unk_FieldIdListPtr pTargets(0);
    m_portalType8.Lookup(nField, pTargets);
    return pTargets;
}

// @0x1406fc450
Unk_FieldIdListMap& CFieldMetaTable::FUN_1406fc450()
{
    CheckInit();
    return m_portalType8;
}

// @0x1406fc480
void CFieldMetaTable::FUN_1406fc480(int nFieldId, int nNpcId, const CMsTime& t)
{
    MS2Ptr<CSpawnNpcGuaranteeInfo> info;
    if (!m_guarantee.Lookup(nFieldId, info))
    {
        info.AssignRaw(new CSpawnNpcGuaranteeInfo);
        info->m_nFieldId = nFieldId;
        info->m_nNpcId = nNpcId;
        m_guarantee.SetAt(nFieldId, info);
    }
    info->m_time = t;
}

// @0x1406fc590
void CFieldMetaTable::FUN_1406fc590(int nFieldId)
{
    MS2Ptr<CSpawnNpcGuaranteeInfo> info;
    if (!m_guarantee.Lookup(nFieldId, info))
        return;
    m_guarantee.RemoveKey(info->m_nFieldId);
}

// @0x1406fc620
int CFieldMetaTable::FUN_1406fc620(int nNpcId, CMsTime& out)
{
    ATL::CAtlArray<CMsTime> times;
    if (FUN_1406fc6d0(nNpcId, times) && !times.IsEmpty())
    {
        out = times[0];
        return 1;
    }
    else
    {
        return 0;
    }
}

// @0x1406fc6d0
int CFieldMetaTable::FUN_1406fc6d0(int nNpcId, ATL::CAtlArray<CMsTime>& out)
{
    for (POSITION pos = m_guarantee.GetHeadPosition(); pos != 0; m_guarantee.GetNext(pos))
    {
        MS2Ptr<CSpawnNpcGuaranteeInfo> info(m_guarantee.GetValueAt(pos));
        if (info->m_nNpcId == nNpcId)
            out.Add(info->m_time);
    }
    if (out.IsEmpty())
        return 0;
    else
        return 1;
}

// @0x1406fc7b0
bool CFieldMetaTable::FUN_1406fc7b0(unsigned nField, unsigned nId)
{
    Unk_FieldIdListPtr pTargets(0);
    if (!m_portalTargets2.Lookup(nField, pTargets))
        return false;
    return pTargets.get()->Find(nId, 0) != 0;
}

// @0x1406fc870
int CFieldMetaTable::FUN_1406fc870(unsigned nFieldId)
{
    return CFieldFeatureChecker::IsEnabled(nFieldId);
}

// @0x1406fc8a0
// Parses "yyyy-mm-dd-hh-mm-ss"; false when any part is out of range.
bool CFieldMetaTable::FUN_1406fc8a0(CString str, __int64* pTime)
{
    int nYear = 0;
    int nMonth = 0;
    int nDay = 0;
    int nHour = 0;
    int nMinute = 0;
    int nSecond = 0;
    sscanf(str, "%d-%d-%d-%d-%d-%d", &nYear, &nMonth, &nDay, &nHour, &nMinute, &nSecond);
    if (nYear < 1900 || nMonth < 1 || nMonth > 12 || nDay < 1 || nDay > 31 || nHour < 0 || nHour > 23 ||
        nMinute < 0 || nMinute > 59 || nSecond < 0 || nSecond > 59)
        return false;
    *pTime = FUN_14086b2a0(nYear, nMonth, nDay, nHour, nMinute, nSecond);
    return true;
}

// @0x1406ff040
CSpawnNpcGuaranteeInfo::CSpawnNpcGuaranteeInfo() : m_nFieldId(0), m_nNpcId(0)
{
}

// @0x1406ffb80
void CFieldFeatureChecker::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CFieldFeatureChecker).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1406ffc30
void CFieldMetaTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CFieldMetaTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140703180
void CFieldFeatureChecker::SetInit(bool b)
{
    s_bInit = b;
}

// @0x140703190
void CFieldMetaTable::SetInit(bool b)
{
    s_bInit = b;
}
