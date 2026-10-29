// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CContinentRegionTable: Table/MapContinentTable.xml.
// MS2-UNIT: ?\continentregiontable.cpp
// MS2-RANGE: 0x1402c5180-0x1402c6c20 .text$mn
// MS2-PIN: ??_7CContinentRegionTable@@6B?$TSingleton@VCContinentRegionTable@@@@@ 0x142d203c8
// MS2-PIN: ??_7CContinentRegionTable@@6B?$CValidData@VCContinentRegionTable@@@@@ 0x142d203d8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\continentregiontable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "continentregiontable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (same ones serverlisttable.cpp uses).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140168650 { public: Unk_140168650* FUN_140168650(const char*); };
void FUN_1408731e0(void*, const char*, int&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14016a5c0(const char* psz, int n);
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CContinentRegionTable::s_bInit;
#endif

// @0x1402c5180
CContinentRegionTable::CContinentRegionTable() : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
    Load();
}

// @0x1402c5230
CContinentRegionTable::~CContinentRegionTable()
{
    m_map.RemoveAll();
}

// @0x1402c52b0
void CContinentRegionTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "MapContinentTable.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("continent"); pNode != 0;
         pNode = reinterpret_cast<Unk_140165cf0*>(reinterpret_cast<Unk_140168650*>(pNode)->FUN_140168650("continent")))
    {
        InfoPtr info(new ContinentInfo);
        FUN_1408731e0(pNode, "id", info->m_nId);
        FUN_1408731e0(pNode, "hideOtherWorldQuest", info->m_nHideOtherWorldQuest);
        FUN_1408731e0(pNode, "shadowContinent", info->m_nShadowContinent);
        FUN_1408731e0(pNode, "representWorldmapContinent", info->m_nRepresentWorldmapContinent);
        m_map.SetAt(info->m_nId, info);
    }
    SetInit(true);
}

// @0x1402c5570
CContinentRegionTable::InfoPtr CContinentRegionTable::GetContinent(DWORD nId)
{
    CheckInit();
    InfoPtr p(0);
    m_map.Lookup(nId, p);
    return p;
}

// @0x1402c5850
ContinentInfo::ContinentInfo()
{
    m_nId = 0;
    m_nHideOtherWorldQuest = 0;
    m_nShadowContinent = 0;
    m_nRepresentWorldmapContinent = 0;
}

// @0x1402c5b50
void CContinentRegionTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CContinentRegionTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1402c6a20
void CContinentRegionTable::SetInit(bool b)
{
    s_bInit = b;
}
