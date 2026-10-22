// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TriggerCli: the cube-trigger script container (state graph
// loaded from a Trigger xml, localized action / condition texts, validation) plus its CRBMap / CAtlArray / std::set glue.
// MS2-UNIT: unit_141199270
// MS2-RANGE: 0x141199270-0x14119e920 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Buynode@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@?$_Tree_comp_alloc@V?$_Tset_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@1@$$QEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x14119b650 ; unique
// MS2-PIN: ?IsNull@?$MS2Ptr@VTriggerStateCli@@@@QEBA_NXZ 0x14119c6e0 ; unique
// MS2-PIN: ??8?$MS2Ptr@VTriggerStateCli@@@@QEBA_NPEAVTriggerStateCli@@@Z 0x14119c710 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??$construct@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAV12@@?$_Default_allocator_traits@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@SAXAEAV?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@QEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAV34@@Z 0x14119be50 ; manual
// MS2-PIN: ??$construct@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEBV12@@?$_Default_allocator_traits@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@SAXAEAV?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@QEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEBV34@@Z 0x14119be50 ; manual
// MS2-PIN: ??$construct@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@1@QEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@$$QEAV34@@Z 0x14119be50 ; manual
// MS2-PIN: ??$construct@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@?$_Default_allocator_traits@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@SAXAEAV?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@QEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@$$QEAV34@@Z 0x14119be50 ; manual
// MS2-PIN: ??1?$vector@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@V?$allocator@U?$pair@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@H@std@@@2@@std@@QEAA@XZ 0x14119c560 ; manual
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VTriggerCli@@@@AEBAXPEAX@Z 0x14119e6d0 ; manual
// MS2-PIN: ?AddRefImpl@?$Unk_PayloadPtr@VCFileBuffer@@@@AEBAXPEAX@Z 0x14119e6d0 ; manual
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\triggercli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "triggercli.h"
#include <set>
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

// tinyxml writer / reader helpers (the same ones the other trigger units use)
struct Unk_TrgXmlElement { void* m_00; void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68; void* m_70; void* m_78; void* m_80; void* m_88; };
MS2_CHECK_SIZE(Unk_TrgXmlElement, 0x90);
struct Unk_TrgXmlDecl { void* m_00; void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68; };
MS2_CHECK_SIZE(Unk_TrgXmlDecl, 0x70);
void* FUN_14086f2f0(void*, const char*);                    // TiXmlElement::TiXmlElement(const char*)
void FUN_14086f450(void*);                                  // TiXmlElement::~TiXmlElement
void* FUN_1408704d0(void*, const char*, const char*, const char*);   // TiXmlDeclaration::TiXmlDeclaration
void FUN_14081ad20(void*);                                  // TiXmlDeclaration::~TiXmlDeclaration
void* FUN_14086e000(void*, void*);                          // InsertEndChild
bool FUN_1408710c0(void*, const char*);                     // SaveFile
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);   // FirstChildElement of the document
int FUN_140873420(Unk_140165cf0* pNode, const char* pszName, CStringW& rOut);   // string attribute, 0 = found
void FUN_1401d3700(CString& s);
CStringW FUN_1401bf530(Unk_140165cf0* pNode, const char* pszName, CStringW strDefault);   // attribute or the default
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // path join

class Unk_TrgLog
{
public:
    void FUN_14015eb90(int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg);
};
Unk_TrgLog* FUN_140166440();

// String table and fmt helpers.
CStringW GetStringCommon(int nId);                            // string table entry
CStringW FUN_1408116a0(int nId, const int& nArg);           // string table entry with one integer argument
CStringW FormatStringId(int id, const fmt::ArgList& args);  // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)

// The service that resolves a cube object id (class id 0x06100017; only one lookup is used here).
struct Unk_TrgObject
{
    char m_pad00[0xb4];
    int m_nItemId;                                          // +0xb4
};
MS2_CHECK_OFFSET(Unk_TrgObject, m_nItemId, 0xb4);
class Unk_TrgService : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    Unk_TrgObject* FUN_1410b8b00(unsigned nId);
};
struct Unk_TrgFramework { efd::ServiceManagerPtr manager; };
extern Unk_TrgFramework DAT_143b059e8;
Unk_TrgService* FUN_1401cd040(Unk_TrgFramework*);
int FUN_1407071e0(int nItemId);
int FUN_140707710(int nItemId);
int FUN_140707660(int nItemId);

// @0x141199270
TriggerCli::TriggerCli()
    : m_mapText(10), m_mapTooltip(10), m_mapArgs(10), m_mapStates(10)
{
}

// @0x141199310
TriggerCli::~TriggerCli()
{
}

// @0x1411993a0
MS2Ptr<TriggerCli> TriggerCli::Create(const CString& strPath)
{
    MS2Ptr<TriggerCli> spCli(new TriggerCli);
    return spCli->LoadFile(strPath) ? spCli : MS2Ptr<TriggerCli>(0);
}

// @0x141199520
MS2Ptr<TriggerCli> TriggerCli::Create(CFileSystem::BufferPtr spBuffer)
{
    MS2Ptr<TriggerCli> spCli(new TriggerCli);
    return spCli->LoadBuffer(spBuffer) ? spCli : MS2Ptr<TriggerCli>(0);
}

// @0x1411996f0
// MS2-FUNCTIONAL: source shape differs (set/trim control flow)
int TriggerCli::Validate(int* pnError)
{
    if (m_states.GetCount() == 0)
    {
        *pnError = 10;
        return 0;
    }
    std::set<CStringW> names;
    for (UINT i = 0; i < m_states.GetCount(); ++i)
    {
        if (m_states[i] == 0)
        {
            *pnError = 6;
            return 0;
        }
        CStringW strName = m_states[i]->GetName();
        if (names.find(strName) != names.end())
        {
            *pnError = 0xb;
            return 0;
        }
        if (strName.Trim() != m_states[i]->GetName())
        {
            *pnError = 0xc;
            return 0;
        }
        if (m_states[i]->Validate(pnError) == 0)
            return 0;
        names.insert(m_states[i]->GetName());
    }
    return 1;
}

// @0x141199a30
void TriggerCli::CollectIds(std::vector<std::pair<CStringW, int> >& rOut)
{
    for (UINT i = 0; i < m_states.GetCount(); ++i)
        m_states[i]->CollectIds(rOut);
}

// @0x141199ab0
int TriggerCli::LoadFile(const CString& strPath)
{
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return 0;
    CString strNorm(strPath);
    FUN_1401d3700(strNorm);
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pState = pRoot->FUN_140165cf0("state"); pState != 0; pState = pState->FUN_140168650("state"))
        LoadState(pState);
    return 1;
}

// @0x141199c40
int TriggerCli::LoadBuffer(CFileSystem::BufferPtr spBuffer)
{
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403979e0(&doc, spBuffer) == 0)
        return 0;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
        return 0;
    for (Unk_140165cf0* pState = pRoot->FUN_140165cf0("state"); pState != 0; pState = pState->FUN_140168650("state"))
        LoadState(pState);
    return 1;
}

// @0x141199da0
int TriggerCli::LoadEditorTable()
{
    int nEnabled = 0;
    if (nEnabled == 0)
        return 0;
    CString strPath = FUN_14071a5b0("Table/Server", "triggerEditor.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
    {
        CStringW strCond = FUN_1401bf530(pKey, "cond", CStringW(L""));
        CStringW strAct = FUN_1401bf530(pKey, "act", CStringW(L""));
        CStringW strText = FUN_1401bf530(pKey, "text", CStringW(L""));
        CStringW strTooltip = FUN_1401bf530(pKey, "tooltip", CStringW(L""));
        if (!strCond.IsEmpty())
        {
            m_mapText.SetAt(strCond, strText);
            m_mapTooltip.SetAt(strCond, strTooltip);
            Unk_TrgPtr<ArgArray> spArgs(Unk_TrgNewTag(0));
            for (UINT i = 0; i < 6; ++i)
            {
                CString strAttr;
                strAttr.Format("arg%d", i + 1);
                CStringW strValue;
                if (FUN_140873420(pKey, (const char*)strAttr, strValue) == 0)
                    spArgs->SetAtGrow(i, strValue);
            }
            m_mapArgs.SetAt(strCond, spArgs);
        }
        if (!strAct.IsEmpty())
        {
            m_mapText.SetAt(strAct, strText);
            m_mapTooltip.SetAt(strAct, strTooltip);
            Unk_TrgPtr<ArgArray> spArgs(Unk_TrgNewTag(0));
            for (UINT i = 0; i < 6; ++i)
            {
                CString strAttr;
                strAttr.Format("arg%d", i + 1);
                CStringW strValue;
                if (FUN_140873420(pKey, (const char*)strAttr, strValue) == 0)
                    spArgs->SetAtGrow(i, strValue);
            }
            m_mapArgs.SetAt(strAct, spArgs);
        }
    }
    return 1;
}

// @0x14119a3f0
CStringW TriggerCli::FormatText(CStringW strKey, const ATL::CAtlArray<CStringW>& rArgs)
{
    CStringW strText;
    if (!m_mapText.Lookup(strKey, strText))
        return strKey;
    for (size_t i = 0; i < rArgs.GetCount(); ++i)
    {
        CStringW strToken;
        strToken.Format(L"#%d#", i + 1);
        CStringW strArg(rArgs[i]);
        if (strArg.GetLength() > 0x14)
        {
            strArg.Truncate(0x14);
            strArg.Format(L"%s...", (const wchar_t*)strArg);
        }
        strText.Replace((const wchar_t*)strToken, (const wchar_t*)strArg);
    }
    return strText;
}

// @0x14119a5e0
CStringW TriggerCli::GetTooltip(CStringW strKey)
{
    CStringW strText;
    if (m_mapTooltip.Lookup(strKey, strText))
        return strText;
    return strKey;
}

// @0x14119a6b0
CStringW TriggerCli::GetArgTemplate(CStringW strKey)
{
    CStringW strText;
    if (!m_mapText.Lookup(strKey, strText))
        return strKey;
    for (size_t i = 0; i < 6; ++i)
    {
        CStringW strToken;
        strToken.Format(L"#%d#", i + 1);
        CStringW strTag;
        strTag.Format(L"[Arg%d]", i + 1);
        strText.Replace((const wchar_t*)strToken, (const wchar_t*)strTag);
    }
    return strText;
}

// @0x14119a850
void TriggerCli::SaveFile(const CString& strPath)
{
    TiXmlDocument doc;
    SaveDocument(&doc);
    FUN_1408710c0(&doc, (const char*)strPath);
}

// @0x14119a8c0
// MS2-FUNCTIONAL: game TiXml objects modelled as POD (no EH unwind state)
void TriggerCli::SaveDocument(TiXmlDocument* pDoc)
{
    Unk_TrgXmlElement elRoot;
    Unk_TrgXmlElement elState;
    Unk_TrgXmlDecl decl;
    FUN_1408704d0(&decl, "1.0", "utf-8", "");
    FUN_14086e000(pDoc, &decl);
    FUN_14086f2f0(&elRoot, "ms2");
    for (size_t i = 0; i < m_states.GetCount(); ++i)
    {
        FUN_14086f2f0(&elState, "state");
        m_states[i]->Save(&elState);
        FUN_14086e000(&elRoot, &elState);
        FUN_14086f450(&elState);
    }
    FUN_14086e000(pDoc, &elRoot);
    FUN_14086f450(&elRoot);
    FUN_14081ad20(&decl);
}

// @0x14119aa10
// MS2-FUNCTIONAL: frame/temp layout differs
bool TriggerCli::GetFirstError(CStringW& rText)
{
    if (m_states.GetCount() == 0)
    {
        StatePtr spState = GetState(CStringW(L"newState1"));
        if (spState.IsNull())
        {
            rText = GetErrorText(7);
            return false;
        }
    }
    int nError;
    int nOk = Validate(&nError);
    if (nOk == 0)
        rText = GetErrorText(nError);
    return nOk != 0;
}

// @0x14119ab70
// MS2-FUNCTIONAL: loop exit jumps differ
int TriggerCli::CheckObjects(std::vector<CStringW>& rErrors)
{
    efd::SmartPointer<Unk_TrgService> spService(FUN_1401cd040(&DAT_143b059e8));
    std::vector<std::pair<CStringW, int> > ids;
    CollectIds(ids);
    CStringW strMsg;
    for (size_t i = 0; i < ids.size(); ++i)
    {
        std::pair<CStringW, int>& rId = ids[i];
        Unk_TrgObject* pObject = spService->FUN_1410b8b00(rId.second);
        if (pObject == 0)
        {
            strMsg = FormatStringId(0xafb, rId.first, GetErrorText(0xd), rId.second);
            rErrors.push_back(strMsg);
        }
        else if (FUN_1407071e0(pObject->m_nItemId) == 0 || FUN_140707710(pObject->m_nItemId) == 0 ||
                 FUN_140707660(pObject->m_nItemId) != 0)
        {
            strMsg = FormatStringId(0xafb, rId.first, GetErrorText(0xd), rId.second);
            rErrors.push_back(strMsg);
        }
    }
    return rErrors.size() == 0;
}

// @0x14119ae90
// MS2-FUNCTIONAL: switch lowering differs
CStringW TriggerCli::GetErrorText(int nError)
{
    CStringW strText(L"");
    if (nError >= 0)
    {
        if (nError < 0xd)
            strText = FUN_1408116a0(0xafc, nError);
        else if (nError == 0xd)
            strText = GetStringCommon(0xafd);
    }
    return strText;
}

// @0x14119afc0
TriggerCli::StatePtr TriggerCli::GetState(const CStringW& strName)
{
    StatePtr spState(0);
    if (!m_mapStates.Lookup(strName, spState))
    {
        spState.AssignRaw(new TriggerStateCli(this));
        spState->SetName(strName);
        m_mapStates.SetAt(strName, spState);
        m_states.Add(spState);
    }
    return spState;
}

// @0x14119b140
// MS2-FUNCTIONAL: EH/branch shape differs
void TriggerCli::LoadState(Unk_140165cf0* pNode)
{
    CStringW strName;
    FUN_140873420(pNode, "name", strName);
    StatePtr spState;
    if (!m_mapStates.Lookup(strName, spState))
    {
        spState.AssignRaw(new TriggerStateCli(this));
        spState->Load(pNode);
        m_mapStates.SetAt(strName, spState);
        m_states.Add(spState);
    }
}
