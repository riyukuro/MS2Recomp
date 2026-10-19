// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameDictionaryManager: the game dictionary's web-finder
// tables (npc / monster / item id -> GameDictionaryData), loaded once by the ctor and read by UIGameDictionaryDialog.
// Method names are invented (see ms2/placeholder/gamedictionarymanager.h); the tail is the CRBMap / std::list /
// TPtrValue glue over the entry pointer.
// MS2-UNIT: ?\gamedictionarymanager.cpp
// MS2-RANGE: 0x1403b72d0-0x1403ba180 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gamedictionarymanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <list>
#include "ms2/placeholder/gamedictionarymanager.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

void* FUN_140166440();                                                      // the log singleton
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);       // log "{0}" with a path
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);       // Table/<file>

// @0x1403b72d0
GameDictionaryManager::GameDictionaryManager()
{
    LoadAll();
}

// @0x1403b7360
GameDictionaryManager::~GameDictionaryManager()
{
}

// @0x1403b73c0
void GameDictionaryManager::LoadAll()
{
    LoadNpc();
    LoadMob();
    LoadItem();
}
MS2_REPLACE_METHOD(0x1403b73c0, GameDictionaryManager, LoadAll, 44, 0x35EA1878);

// @0x1403b7400
void GameDictionaryManager::LoadNpc()
{
    m_npcs.RemoveAll();
    CString strDir;
    strDir.Format("%s", "Table");
    CString strPath = FUN_14071a5b0(strDir, "monsterWebfinder_Npc.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
        LoadEntry(m_npcs, pNode);
}
MS2_REPLACE_METHOD(0x1403b7400, GameDictionaryManager, LoadNpc, 477, 0x9A42D2EA);

// @0x1403b75f0
void GameDictionaryManager::LoadMob()
{
    m_mobs.RemoveAll();
    CString strDir;
    strDir.Format("%s", "Table");
    CString strPath = FUN_14071a5b0(strDir, "monsterWebfinder_Mob.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
        LoadEntry(m_mobs, pNode);
}
MS2_REPLACE_METHOD(0x1403b75f0, GameDictionaryManager, LoadMob, 477, 0x7E8CA427);

// @0x1403b77e0
void GameDictionaryManager::LoadItem()
{
    m_items.RemoveAll();
    CString strDir;
    strDir.Format("%s", "Table");
    CString strPath = FUN_14071a5b0(strDir, "itemWebfinder.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
        LoadEntry(m_items, pNode);
}
MS2_REPLACE_METHOD(0x1403b77e0, GameDictionaryManager, LoadItem, 477, 0xA92DA7FB);

// @0x1403b79d0
void GameDictionaryManager::LoadEntry(DataMap& map, Unk_140165cf0* pElem)
{
    int nValue = 0;
    FUN_1408731e0(pElem, "value", nValue);
    if (nValue == 0)
        return;
    DataPtr spData = Unk_GrNewTag(0);
    FUN_140873220(pElem, "id", spData->m_id);
    FUN_1408731e0(pElem, "grade", spData->m_grade);
    FUN_1408731e0(pElem, "invisibleLevel", spData->m_invisibleLevel);
    FUN_140873220(pElem, "FieldID", spData->m_fieldId);
    map.SetAt(spData->m_id, spData);
}
MS2_REPLACE_METHOD(0x1403b79d0, GameDictionaryManager, LoadEntry, 271, 0x0CECFEDE);

// @0x1403b7af0
std::list<GameDictionaryManager::DataPtr> GameDictionaryManager::GetAll(int nType)
{
    DataMap* pMap = 0;
    if (nType == kNpc)
        pMap = &m_npcs;
    else if (nType == kMob)
        pMap = &m_mobs;
    else if (nType == kItem)
        pMap = &m_items;
    std::list<DataPtr> result;
    if (pMap == 0)
        return result;
    for (POSITION pos = pMap->GetHeadPosition(); pos != 0; pMap->GetNext(pos))
    {
        DataPtr& spData = pMap->GetValueAt(pos);
        if (spData == 0)
            continue;
        result.push_back(spData);
    }
    return result;
}
MS2_REPLACE_METHOD(0x1403b7af0, GameDictionaryManager, GetAll, 330, 0x93064A0D);

// @0x1403b7c40
GameDictionaryManager::DataPtr GameDictionaryManager::Get(int nType, int nId)
{
    DataMap* pMap = 0;
    if (nType == kNpc)
        pMap = &m_npcs;
    else if (nType == kMob)
        pMap = &m_mobs;
    else if (nType == kItem)
        pMap = &m_items;
    if (pMap == 0)
        return DataPtr(0);
    DataPtr spData;
    pMap->Lookup(nId, spData);
    return spData;
}
MS2_REPLACE_METHOD(0x1403b7c40, GameDictionaryManager, Get, 231, 0x097EEEDD);

// @0x1403b7d30
void GameDictionaryManager::SetMobLevel(int nId, int nLevel)
{
    DataPtr spData(0);
    if (m_mobs.Lookup(nId, spData) == true)
        spData->m_level = nLevel;
}
MS2_REPLACE_METHOD(0x1403b7d30, GameDictionaryManager, SetMobLevel, 106, 0xEA90F0A5);
