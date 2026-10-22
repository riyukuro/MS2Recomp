// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CQuestTable: Table/questToFieldTable.xml (quest id -> the field
// ids the quest takes place in).
// MS2-UNIT: ?\questtable.cpp
// MS2-RANGE: 0x1416e3800-0x1416e4010 .text$mn
// MS2-PIN: ??_7CQuestTable@@6B?$TSingleton@VCQuestTable@@@@@ 0x142f57968
// MS2-PIN: ??_7CQuestTable@@6B?$CValidData@VCQuestTable@@@@@ 0x142f57978
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\questtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cquesttable.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CString FUN_14016a5c0(const char* psz, int n);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CQuestTable::s_bInit;
#endif

// @0x1416e3800
CQuestTable::CQuestTable() : m_mapFields(17, 0.75f, 0.25f, 2.25f, 10)
{
    LoadQuestToField();
}

// @0x1416e38b0
CQuestTable::~CQuestTable()
{
}

// @0x1416e3910
// MS2-FUNCTIONAL: frame is 0x20 larger; the path/document temporaries and the loop locals are placed differently
void CQuestTable::LoadQuestToField()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("questToFieldTable.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) != 0)
    {
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        }
        else
        {
            for (Unk_140165cf0* pQuest = pRoot->FUN_140165cf0("quest"); pQuest != 0; pQuest = pQuest->FUN_140168650("quest"))
            {
                unsigned int nId;
                FUN_140873220(pQuest, "id", nId);
                CString strFields = FUN_14015f710(pQuest, "fields", CString(""));
                ATL::CAtlArray<unsigned int> arrFields;
                XmlSplit(strFields, arrFields, ",");
                FieldListPtr fields((Unk_CubeNewTag(0)));
                for (size_t i = 0; i < arrFields.GetCount(); i++)
                    fields->AddTail(arrFields[i]);
                m_mapFields.SetAt(nId, fields);
            }
            SetInit(true);
        }
    }
}

// @0x1416e3c10
void CQuestTable::GetFields(DWORD nQuestId, ATL::CAtlList<unsigned int>* pOut)
{
    CheckInit();
    FieldListPtr fields(0);
    if (m_mapFields.Lookup(nQuestId, fields))
    {
        for (POSITION pos = fields->GetHeadPosition(); pos != 0; fields->GetNext(pos))
            pOut->AddTail(fields->GetAt(pos));
    }
}

// @0x1416e3e30
void CQuestTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CQuestTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1416e3ee0
void CQuestTable::SetInit(bool b)
{
    s_bInit = b;
}

MS2_EMIT_CRT_MEMMOVE_S();
