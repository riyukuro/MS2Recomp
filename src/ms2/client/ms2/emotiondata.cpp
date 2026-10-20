// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The character emotion library (CEmotionData,
// CEmotionGroup, CEmotionGroupImport, CEmotionTable, CEmotionManager); see emotiondata.h.
// MS2-UNIT: client\ms2\emotiondata.cpp
// MS2-RANGE: 0x1411bcb50-0x1411c5780 .text$mn
// MS2-PIN: ??_7CEmotionManager@@6B?$TSingleton@VCEmotionManager@@@@@ 0x142ebceb0
// MS2-PIN: ??_7CEmotionManager@@6B?$CValidData@VCEmotionManager@@@@@ 0x142ebcec0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\emotiondata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <shlwapi.h>
#include "emotiondata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#pragma comment(lib, "shlwapi.lib")

// Unrecovered helpers (the xml/file helpers the table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // <dir>/<file> resource path
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>& out);
void FUN_140874280(Unk_140165cf0* pElem, const char* pszNode, const char* pszAttr, CString& strOut);  // child attribute
void FUN_140399100(CString pattern, CString directory, ATL::CAtlArray<CString>& output, CString exclude, bool localOnly);
unsigned int FUN_1407181d0(const CString& s);                           // decimal string -> id
extern int DAT_1439ed00c;                                               // file caches checked (hot reload)

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CEmotionManager::s_bInit;
#endif

// The no-argument form of the game's second "{0}" formatter (inline; callers in other units bind it by name).
// @0x1411c0aa0
inline CString FUN_1411c0aa0(const char* format)
{
    return Unk_SocketFormat(format, fmt::ArgList());
}

// @0x1411bcb50
CEmotionData::CEmotionData()
    : m_bEquipHide(false), m_bTool(false)
{
}

// @0x1411bcc20
CEmotionData::~CEmotionData()
{
}

// @0x1411bccd0
bool CEmotionData::Load(Unk_140165cf0* pNode)
{
    FUN_1408733e0(pNode, "name", m_strName);
    FUN_1408733e0(pNode, "faceName", m_strFaceName);
    FUN_1408730a0(pNode, "equiphide", m_bEquipHide);
    FUN_1408730a0(pNode, "isTool", m_bTool);
    FUN_140874280(pNode, "anim", "name", m_anims[0]);
    FUN_140874280(pNode, "idleAnim", "name", m_anims[1]);
    if (m_strName.IsEmpty())
        return false;
    if (!FUN_14028f710(pNode))
        return false;
    CString strBore;
    FUN_140874280(pNode, "boreAnim", "name", strBore);
    if (!strBore.IsEmpty())
    {
        ATL::CAtlArray<CString> arr;
        FUN_14015f050(strBore, arr, ",");
        if (arr.GetCount() > 0)
            m_anims[2] = arr[0];
        if (arr.GetCount() > 1)
            m_anims[3] = arr[1];
        if (arr.GetCount() > 2)
            m_anims[4] = arr[2];
    }
    Unk_140165cf0* pTexture = pNode->FUN_140165cf0("textureani");
    if (pTexture != 0)
    {
        m_spTextureAni.AssignRaw(new CTextureAnimationData);
        if (!m_spTextureAni->FUN_141847e30(pTexture))
            m_spTextureAni = NULL;
    }
    for (Unk_140165cf0* pEffect = pNode->FUN_140165cf0("effect"); pEffect != 0; pEffect = pEffect->FUN_140168650("effect"))
    {
        m_effects.Add();
        CString& strFile = m_effects.GetAt(m_effects.GetCount() - 1);
        FUN_1408733e0(pEffect, "file", strFile);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1411BCCD0, CEmotionData, Load, 988, 0xFEB910AF);

// @0x1411bd0c0
CString CEmotionData::GetAnimation(int nIndex)
{
    if (nIndex < 0 || nIndex >= 5)
        return "";
    return m_anims[nIndex];
}
MS2_REPLACE_METHOD(0x1411BD0C0, CEmotionData, GetAnimation, 127, 0x12DE4F7C);

// @0x1411bd150
void CEmotionData::LoadTexture(CString strDir)
{
    if (m_spTextureAni)
        m_spTextureAni->FUN_141848080(strDir, 4);
}

// @0x1411bd1c0
void CEmotionData::CheckResources(CString strDir)
{
    WIN32_FIND_DATAA fd;
    for (unsigned int i = 0; i < m_effects.GetCount(); i++)
    {
        CString& strEffect = m_effects.GetAt(i);
        CString strPath = FUN_14071a5b0("Effect", strEffect);
        if (FindFirstFileA(strPath, &fd) == INVALID_HANDLE_VALUE)
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"\xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4[EmotionData - effect] [{0}]", strEffect);
    }
    if (m_spTextureAni)
    {
        for (unsigned int i = 0; i < m_spTextureAni->m_arrFrames.GetCount(); i++)
        {
            CString strTexture = m_spTextureAni->m_arrFrames.GetAt(i).FUN_141847960(strDir);
            if (!strTexture.IsEmpty())
            {
                if (FindFirstFileA(strTexture, &fd) == INVALID_HANDLE_VALUE)
                    FUN_14015eb90(FUN_140166440(), 1, 0x13, L"\xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4[EmotionData - texture] [{0}]", strTexture);
            }
            if (m_spTextureAni->m_arrFrames.GetAt(i).FUN_141847bb0())
            {
                strTexture = m_spTextureAni->m_arrFrames.GetAt(i).FUN_141847a60(strDir);
                if (FindFirstFileA(strTexture, &fd) == INVALID_HANDLE_VALUE)
                    FUN_14015eb90(FUN_140166440(), 1, 0x13, L"\xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4[EmotionData - controlTexture] [{0}]", strTexture);
            }
        }
    }
}

// @0x1411bd530
bool CEmotionData::IsTool()
{
    return m_bTool;
}
MS2_REPLACE_METHOD(0x1411BD530, CEmotionData, IsTool, 15, 0x835329ED);

// @0x1411bd550
CEmotionGroup::CEmotionGroup()
{
}

// @0x1411bd5c0
void CEmotionGroup::Load(Unk_140165cf0* pRoot)
{
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "emotion", "name", nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        MS2Ptr<CEmotionData> spData(new CEmotionData);
        if (spData->Load(nodes[i]))
            m_emotions.SetAt(spData->m_strName, spData);
    }
}
MS2_REPLACE_METHOD(0x1411BD5C0, CEmotionGroup, Load, 324, 0x77E15181);

// @0x1411bd710
void CEmotionGroup::LoadTextures(const CString& strDir)
{
    for (POSITION pos = m_emotions.GetStartPosition(); pos != 0; m_emotions.GetNext(pos))
    {
        MS2Ptr<CEmotionData> spData = m_emotions.GetValueAt(pos);
        spData->LoadTexture(strDir);
    }
}
MS2_REPLACE_METHOD(0x1411BD710, CEmotionGroup, LoadTextures, 199, 0xECE41F54);

// @0x1411bd7e0
void CEmotionGroup::CheckResources()
{
    for (POSITION pos = m_emotions.GetStartPosition(); pos != 0; m_emotions.GetNext(pos))
    {
        MS2Ptr<CEmotionData> spData = m_emotions.GetValueAt(pos);
        if (spData == NULL)
            continue;
        spData->CheckResources("");
    }
}
MS2_REPLACE_METHOD(0x1411BD7E0, CEmotionGroup, CheckResources, 231, 0xE5971B34);

// @0x1411bd8d0
CString CEmotionGroup::GetItemCode()
{
    return "";
}
MS2_REPLACE_METHOD(0x1411BD8D0, CEmotionGroup, GetItemCode, 61, 0xF218302E);

// @0x1411bd920
MS2Ptr<CEmotionData> CEmotionGroup::Find(const CString& strName)
{
    MS2Ptr<CEmotionData> spData;
    if (m_emotions.Lookup(strName, spData))
        return spData;
    return NULL;
}
MS2_REPLACE_METHOD(0x1411BD920, CEmotionGroup, Find, 173, 0x12FB877E);

// @0x1411bd9e0
void CEmotionGroup::GetNames(std::vector<CString>& names)
{
    names.clear();
    for (POSITION pos = m_emotions.GetStartPosition(); pos != 0; m_emotions.GetNext(pos))
    {
        MS2Ptr<CEmotionData> spData = m_emotions.GetValueAt(pos);
        names.push_back(m_emotions.GetKeyAt(pos));
    }
}
MS2_REPLACE_METHOD(0x1411BD9E0, CEmotionGroup, GetNames, 176, 0x5D479FE7);

// @0x1411bdaa0
CEmotionGroupImport::CEmotionGroupImport(MS2Ptr<CEmotionGroup> spGroup, CString strItemCode)
    : m_spGroup(spGroup), m_strItemCode(strItemCode)
{
}

// @0x1411bdb30
CString CEmotionGroupImport::GetItemCode()
{
    return m_strItemCode;
}
MS2_REPLACE_METHOD(0x1411BDB30, CEmotionGroupImport, GetItemCode, 66, 0xFA83FBC3);

// @0x1411bdb80
MS2Ptr<CEmotionData> CEmotionGroupImport::Find(const CString& strName)
{
    return m_spGroup->Find(strName);
}
MS2_REPLACE_METHOD(0x1411BDB80, CEmotionGroupImport, Find, 96, 0xE432788D);

// @0x1411bdbf0
void CEmotionGroupImport::GetNames(std::vector<CString>& names)
{
    m_spGroup->GetNames(names);
}
MS2_REPLACE_METHOD(0x1411BDBF0, CEmotionGroupImport, GetNames, 62, 0x070CF902);

// @0x1411bdc40
CEmotionTable::CEmotionTable(const CString& strType)
    : m_strType(strType)
{
}

// @0x1411bdd90
CEmotionTable::~CEmotionTable()
{
}

// @0x1411bde10
MS2Ptr<CEmotionGroup> CEmotionTable::GetGroup(unsigned int nId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (DAT_1439ed00c == 0 || IsIdCacheChanged(nId) == true)
        ReadEmotionGroup(nId);
    MS2Ptr<CEmotionGroup> spGroup;
    if (!m_groups.Lookup(nId, spGroup))
    {
        spGroup = ReadEmotionGroup(nId);
        m_groups.SetAt(nId, spGroup);
    }
    return spGroup;
}
MS2_REPLACE_METHOD(0x1411BDE10, CEmotionTable, GetGroup, 359, 0xD70AD528);

// @0x1411bdf80
void CEmotionTable::LoadCommon()
{
    ATL::CAtlArray<CString> files;
    CString strDir = FUN_1411c0aa0("./Data/xml/Emotion/Common");
    FUN_140399100(".xml", strDir, files, "", false);
    for (unsigned int i = 0; i < files.GetCount(); i++)
    {
        TiXmlDocument doc;
        if (FUN_140166420()->FUN_1403974b0(&doc, files[i], 0, true, false) == 0)
            return;
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", files[i]);
            return;
        }
        CString strName = PathFindFileNameA(files[i]);
        strName.Replace(".xml", "");
        AddNameCache(strName, files[i]);
        MS2Ptr<CEmotionGroup> spGroup(new CEmotionGroup);
        spGroup->Load(pRoot);
        m_commonGroups.SetAt(strName, spGroup);
    }
}
MS2_REPLACE_METHOD(0x1411BDF80, CEmotionTable, LoadCommon, 927, 0x0001D8EA);

// @0x1411be330
void CEmotionTable::LoadAll()
{
    ATL::CAtlArray<CString> files;
    CString strDir = Unk_SocketFormat("./Data/xml/Emotion/{0}", m_strType);
    FUN_140399100(".xml", strDir, files, "", false);
    for (size_t i = 0; i < files.GetCount(); i++)
    {
        CString strName = PathFindFileNameA(files[i]);
        strName.Replace(".xml", "");
        unsigned int nId = FUN_1407181d0(strName);
        ReadEmotionGroup(nId);
    }
}
MS2_REPLACE_METHOD(0x1411BE330, CEmotionTable, LoadAll, 471, 0x21C1CF46);

// @0x1411be510
void CEmotionTable::LoadTextures(unsigned int nId, CString strDir)
{
    MS2Ptr<CEmotionGroup> spGroup = GetGroup(nId);
    if (spGroup)
        spGroup->LoadTextures(strDir);
}

// @0x1411be590
void CEmotionTable::CheckResources(unsigned int nId)
{
    MS2Ptr<CEmotionGroup> spGroup = GetGroup(nId);
    if (spGroup == NULL)
        return;
    spGroup->CheckResources();
}
MS2_REPLACE_METHOD(0x1411BE590, CEmotionTable, CheckResources, 108, 0x8BE12349);

// @0x1411be610
MS2Ptr<CEmotionGroup> CEmotionTable::ReadEmotionGroup(unsigned int nId)
{
    CString strPath;
    strPath.Format("%s/%08u.xml", (const char*)m_strType, nId);
    strPath = FUN_14071a5b0("Emotion", strPath);
    AddIdCache(nId, strPath);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, false, false) == 0)
        return NULL;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return NULL;
    }
    MS2Ptr<CEmotionGroup> spGroup;
    Unk_140165cf0* pImport = pRoot->FUN_140165cf0("import");
    if (pImport != 0)
    {
        CString strName;
        CString strItemCode;
        FUN_1408733e0(pImport, "name", strName);
        FUN_1408733e0(pImport, "itemCode", strItemCode);
        MS2Ptr<CEmotionGroup> spCommon = GetCommonGroup(strName);
        if (spCommon == NULL)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"NotFound CEmotionTable::ReadEmotionGroup Import: {0}", strName);
            return NULL;
        }
        spGroup.AssignRaw(new CEmotionGroupImport(spCommon, strItemCode));
    }
    else
    {
        spGroup.AssignRaw(new CEmotionGroup);
        spGroup->Load(pRoot);
    }
    m_groups.SetAt(nId, spGroup);
    return spGroup;
}
MS2_REPLACE_METHOD(0x1411BE610, CEmotionTable, ReadEmotionGroup, 1334, 0x68FB7E71);

// @0x1411beb50
MS2Ptr<CEmotionGroup> CEmotionTable::GetCommonGroup(const CString& strName)
{
    if (DAT_1439ed00c == 0 || IsNameCacheChanged(strName) == true)
    {
        LoadCommon();
        m_groups.RemoveAll();
        m_idCache.RemoveAll();
    }
    MS2Ptr<CEmotionGroup> spGroup;
    m_commonGroups.Lookup(strName, spGroup);
    return spGroup;
}
MS2_REPLACE_METHOD(0x1411BEB50, CEmotionTable, GetCommonGroup, 200, 0xC7FF51F6);

// @0x1411bec20
bool CEmotionTable::IsIdCacheChanged(unsigned int nId)
{
    MS2Ptr<CCacheData> spCache;
    m_idCache.Lookup(nId, spCache);
    if (spCache == NULL)
        return true;
    if (FUN_1401d1320(spCache.get()) == true)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1411BEC20, CEmotionTable, IsIdCacheChanged, 175, 0x928CAD3D);

// @0x1411bece0
bool CEmotionTable::IsNameCacheChanged(const CString& strName)
{
    MS2Ptr<CCacheData> spCache;
    m_nameCache.Lookup(strName, spCache);
    if (spCache == NULL)
        return true;
    if (FUN_1401d1320(spCache.get()) == true)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1411BECE0, CEmotionTable, IsNameCacheChanged, 184, 0x414BE9E0);

// @0x1411beda0
void CEmotionTable::AddIdCache(unsigned int nId, const CString& strPath)
{
    MS2Ptr<CCacheData> spCache(new CCacheData);
    if (!spCache)
    {
        MS2_ASSERT_AT(0x19f, "cache" && 0);
        return;
    }
    spCache->FUN_1401d1160(strPath);
    m_idCache.SetAt(nId, spCache);
}

// @0x1411beed0
void CEmotionTable::AddNameCache(const CString& strName, const CString& strPath)
{
    MS2Ptr<CCacheData> spCache(new CCacheData);
    if (!spCache)
    {
        MS2_ASSERT_AT(0x1aa, "cache" && 0);
        return;
    }
    spCache->FUN_1401d1160(strPath);
    m_nameCache.SetAt(strName, spCache);
}

// @0x1411bf010
CEmotionManager::CEmotionManager()
    : m_itemTable("Item"), m_npcTable("Npc")
{
    m_itemTable.LoadCommon();
    Init();
}

// @0x1411bf100
CEmotionManager::~CEmotionManager()
{
}

// @0x1411bf180
void CEmotionManager::Init()
{
    m_itemTable.LoadAll();
    SetInit(true);
}

// @0x1411bf1b0
CEmotionTable* CEmotionManager::GetItemTable()
{
    CheckInit();
    return &m_itemTable;
}
MS2_REPLACE_METHOD(0x1411BF1B0, CEmotionManager, GetItemTable, 28, 0xB9B85446);

// @0x1411bf1e0
CEmotionTable* CEmotionManager::GetNpcTable()
{
    CheckInit();
    return &m_npcTable;
}
MS2_REPLACE_METHOD(0x1411BF1E0, CEmotionManager, GetNpcTable, 30, 0xB10D5435);
