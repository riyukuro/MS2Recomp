// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CDynamicActionData: Table korDynamicAction.xml (skill ids that
// run a dynamic action, with the default-on flag and the "reserved" action paths) and the lookups over the loaded rows.
// MS2-UNIT: ?\dynamicactiondata.cpp
// MS2-RANGE: 0x140346f60-0x140348ce0 .text$mn
// MS2-RANGE: 0x1400b5fa0-0x1400b6060 .text$di
// MS2-PIN: ??_7CDynamicActionData@@6B?$CValidData@VCDynamicActionData@@@@@ 0x142d290a8
// MS2-PIN: ??1?$MS2Ptr@VCDynamicActionData@@@@QEAA@XZ 0x140347dc0
// MS2-PIN: ??4?$MS2Ptr@VCDynamicActionData@@@@QEAAAEAV0@AEBV0@@Z 0x140347e80
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__E?s_lock@CDynamicActionData@@2VCLockCriticalSection@@A@@YAXXZ 0x1400b6000 ; prop
// MS2-PIN: ??0Unk_DynSetRef@@QEAA@XZ 0x140347ba0 ; prop
// MS2-PIN: ??1Unk_DynSetRef@@QEAA@XZ 0x140347d60 ; prop
// MS2-PIN: ?AddTail@?$CAtlList@V?$MS2Ptr@VCDynamicActionData@@@@V?$CElementTraits@V?$MS2Ptr@VCDynamicActionData@@@@@ATL@@@ATL@@QEAAPEAU__POSITION@@AEBV?$MS2Ptr@VCDynamicActionData@@@@@Z 0x140348130 ; unique
// MS2-PIN: ?GetAt@?$CAtlList@V?$MS2Ptr@VCDynamicActionData@@@@V?$CElementTraits@V?$MS2Ptr@VCDynamicActionData@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCDynamicActionData@@@@PEAU__POSITION@@@Z 0x140348340 ; unique
// MS2-PIN: ?GetFreeNode@?$CAtlList@V?$MS2Ptr@VCDynamicActionData@@@@V?$CElementTraits@V?$MS2Ptr@VCDynamicActionData@@@@@ATL@@@ATL@@AEAAXXZ 0x1403483b0 ; unique
// MS2-PIN: ?GetNext@?$CAtlList@V?$MS2Ptr@VCDynamicActionData@@@@V?$CElementTraits@V?$MS2Ptr@VCDynamicActionData@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCDynamicActionData@@@@AEAPEAU__POSITION@@@Z 0x1403484a0 ; unique
// MS2-PIN: ?NewNode@?$CAtlList@V?$MS2Ptr@VCDynamicActionData@@@@V?$CElementTraits@V?$MS2Ptr@VCDynamicActionData@@@@@ATL@@@ATL@@AEAAPEAVCNode@12@AEBV?$MS2Ptr@VCDynamicActionData@@@@PEAV312@1@Z 0x1403486c0 ; unique
// MS2-PIN: ?AddRef@?$TPtrValue@V?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@@AEBAXXZ 0x1403488b0 ; unique
// MS2-PIN: ?AddRefImpl@?$TPtrValue@V?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@@@AEBAXPEAX@Z 0x140348950 ; unique
// MS2-PIN: ?Release@Unk_DynSetRef@@AEAAXXZ 0x140348a10 ; unique
// MS2-PIN: ?ReleaseImpl@Unk_DynSetRef@@AEAAXPEAX@Z 0x140348ad0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dynamicactiondata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dynamicactiondata.h"
#include "logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071ae20(const CString& strFile);                               // path of a Table file
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& nOut);
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int& nOut);
CStringW FUN_1401bf530(Unk_140165cf0*, const char*, CStringW);
void FUN_14025a680(const CStringW&, ATL::CAtlArray<CStringW>&, const wchar_t*);
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& strArg);   // formats one text argument into the message
CString FUN_14016a5c0(const char* psz, int n);
void FUN_1403455f0(std::set<unsigned>* pSet, void* pResult, const unsigned* pValue);   // set<unsigned>::insert

// The statics are exe globals (symbols-manual.tsv); the hook DLL binds the exe's.
#ifndef MS2_HOOK_DLL
bool CDynamicActionData::s_bInit;
ATL::CAtlList<MS2Ptr<CDynamicActionData> > CDynamicActionData::s_rows(10);
CDynamicActionData::SkillSet CDynamicActionData::s_defaultSkills;
CLockCriticalSection CDynamicActionData::s_lock;
CDynamicActionData::SkillSet CDynamicActionData::s_allSkills;
#endif

// @0x140346f60
// MS2-FUNCTIONAL: member init order/temp layout differs from the exe
CDynamicActionData::CDynamicActionData()
    : m_nDefault(0), m_nSkillId(0)
{
}

// @0x140346ff0
CDynamicActionData::~CDynamicActionData()
{
}

// @0x140347050
// MS2-FUNCTIONAL: MS2Ptr temp/frame layout differs from the exe
MS2Ptr<CDynamicActionData> CDynamicActionData::Find(int nSkillId)
{
    CheckInit();
    MS2Ptr<CDynamicActionData> spRow(0);
    if (Unk_LockGuard guard = s_lock) {}
    else
    {
        POSITION pos = s_rows.GetHeadPosition();
        while (pos)
        {
            spRow = s_rows.GetAt(pos);
            if (spRow->m_nSkillId == nSkillId)
                return spRow;
            s_rows.GetNext(pos);
        }
    }
    return MS2Ptr<CDynamicActionData>(0);
}

// @0x1403477b0
// MS2-FUNCTIONAL: MS2Ptr temp/frame layout differs from the exe
void CDynamicActionData::GetDefaults(ATL::CAtlArray<MS2Ptr<CDynamicActionData> >& rOut)
{
    CheckInit();
    if (Unk_LockGuard guard = s_lock) {}
    else
    {
        POSITION pos = s_rows.GetHeadPosition();
        while (pos)
        {
            MS2Ptr<CDynamicActionData> spRow = s_rows.GetAt(pos);
            if (spRow->m_nDefault != 0)
                rOut.Add(spRow);
            s_rows.GetNext(pos);
        }
    }
}

// @0x140347890
// MS2-FUNCTIONAL: iterator temp layout differs from the exe
bool CDynamicActionData::IsDefault(unsigned nSkillId)
{
    CheckInit();
    SkillSet spSet = s_defaultSkills;
    if (!spSet)
        return false;
    return spSet->find(nSkillId) != spSet->end();
}

// @0x140347960
// MS2-FUNCTIONAL: iterator temp layout differs from the exe
bool CDynamicActionData::IsListed(unsigned nSkillId)
{
    CheckInit();
    SkillSet spSet = s_allSkills;
    if (!spSet)
        return false;
    return spSet->find(nSkillId) != spSet->end();
}

// @0x140347180
// MS2-FUNCTIONAL: EH-state/temp layout of the XML loader differs from the exe (precedent vipgoods.cpp)
void CDynamicActionData::Load()
{
    TiXmlDocument doc;
    CString strPath = FUN_14071ae20(CString("korDynamicAction.xml"));
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    TPtrValue<std::set<unsigned> > spDefaults;
    spDefaults = Unk_GrNewTag(0);
    TPtrValue<std::set<unsigned> > spAll;
    spAll = Unk_GrNewTag(0);
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "key", "skillID", &nodes);
    for (std::vector<Unk_140165cf0*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        Unk_140165cf0* pNode = *it;
        MS2Ptr<CDynamicActionData> spRow(new CDynamicActionData);
        spRow->FUN_1401d1160(CString(strPath));
        FUN_140873220(pNode, "skillID", spRow->m_nSkillId);
        FUN_1408731e0(pNode, "default", spRow->m_nDefault);
        CStringW strReserved = FUN_1401bf530(pNode, "reserved", CStringW(L""));
        ATL::CAtlArray<CStringW> parts;
        FUN_14025a680(strReserved, parts, L"|");
        for (size_t i = 0; i < parts.GetCount(); i++)
            spRow->m_reserved.Add(FUN_1401e8510(L"/{0}", parts[i]));
        if (Unk_LockGuard guard = s_lock) {}
        else
            s_rows.AddTail(spRow);
        char result[16];
        if (spRow->m_nDefault != 0)
            FUN_1403455f0(spDefaults.get(), result, &spRow->m_nSkillId);
        FUN_1403455f0(spAll.get(), result, &spRow->m_nSkillId);
    }
    s_defaultSkills = SkillSet(spDefaults);
    s_allSkills = SkillSet(spAll);
    SetInit(true);
}

// @0x1403481e0
void CDynamicActionData::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CDynamicActionData).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1403488a0
void CDynamicActionData::SetInit(bool b)
{
    s_bInit = b;
}

// Explicit instantiations: the exe keeps the out-of-line pointer members in this TU.
template class MS2Ptr<CDynamicActionData>;
template class TPtrValue<std::set<unsigned> >;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9a650-0x142c9a6d0 .text$yd
