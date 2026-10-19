// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CServerListTable: login server list (Table/serverList.xml).
// MS2-UNIT: ?\serverlisttable.cpp
// MS2-RANGE: 0x1417516d0-0x141753550 .text$mn
// MS2-PIN: ??_7CServerListTable@@6B?$TSingleton@VCServerListTable@@@@@ 0x142f61068
// MS2-PIN: ??_7CServerListTable@@6B?$CValidData@VCServerListTable@@@@@ 0x142f61078
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\serverlisttable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "serverlisttable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140168650 { public: Unk_140168650* FUN_140168650(const char*); };
CStringW FUN_1401bf530(Unk_140165cf0*, const char*, CStringW);
CString FUN_14015f710(Unk_140165cf0*, const char*, CString);
const char* FUN_14086f4b0(Unk_140165cf0*, const char*);
CString FUN_14028d1f0(const char*);
CStringW FUN_14028b8e0(const CStringW& s);
void FUN_1408731e0(void*, const char*, int&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14016a5c0(const char* psz, int n);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CServerListTable::s_bInit;
#endif

// @0x1417516d0
CServerListTable::CServerListTable() : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
    Load();
}

// @0x141751780
CServerListTable::~CServerListTable()
{
}

// @0x1417517e0
void CServerListTable::Load()
{
    TiXmlDocument doc;
    int bLoaded = FUN_140166420()->FUN_1403974b0(&doc, FUN_14071a5b0("Table", "serverList.xml"), 0, true, false);
    if (bLoaded != 0)
    {
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot != 0)
        {
            for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("server"); pNode != 0;
                 pNode = reinterpret_cast<Unk_140165cf0*>(reinterpret_cast<Unk_140168650*>(pNode)->FUN_140168650("server")))
            {
                InfoPtr info(new ServerInfo);
                if (info)
                {
                    FUN_1408731e0(pNode, "id", info->m_nId);
                    CStringW strName = FUN_1401bf530(pNode, "name", L"");
                    info->m_strName = FUN_14028b8e0(strName);
                    info->m_strIcon = FUN_14015f710(pNode, "icon", "");
                    info->m_strDisIcon = FUN_14028d1f0(FUN_14086f4b0(pNode, "dis_icon"));
                    m_map.SetAt(info->m_nId, info);
                }
            }
        }
    }
    SetInit(true);
}

// @0x141751bc0
void CServerListTable::Clear()
{
    m_map.RemoveAll();
}
MS2_REPLACE_METHOD(0x141751BC0, CServerListTable, Clear, 31, 0xFA4A8CE5);

// @0x141751bf0
CServerListTable::InfoPtr CServerListTable::GetServer(DWORD nId)
{
    CheckInit();
    if (!m_map.IsEmpty())
    {
        InfoPtr p(0);
        m_map.Lookup(nId, p);
        return p;
    }
    return InfoPtr(0);
}

// @0x141751cb0
CServerListTable::InfoPtr CServerListTable::GetFirstServer()
{
    CheckInit();
    if (!m_map.IsEmpty())
    {
        POSITION pos = m_map.GetStartPosition();
        if (pos)
        {
            InfoPtr p(const_cast<const InfoPtr&>(m_map.GetValueAt(pos)));
            return p;
        }
    }
    return InfoPtr(0);
}

// @0x141752370
void CServerListTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CServerListTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

#ifndef MS2_HOOK_DLL
// @0x141753350
void CServerListTable::SetInit(bool b)
{
    s_bInit = b;
}
#endif

// Not hooked: Load/GetServer/GetFirstServer/CheckInit/SetInit read or write s_bInit, which is a DLL-local copy here.
