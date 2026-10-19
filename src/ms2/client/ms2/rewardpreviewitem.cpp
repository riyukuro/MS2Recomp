// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). RewardPreviewItem / RewardPreviewInfo / CRewardPreviewTable:
// the boss and dungeon reward previews (Table/RewardPreview_boss.xml, Table/RewardPreview_dungeon.xml), see
// rewardpreviewitem.h, and the template glue of their ATL containers and std::vector.
// MS2-UNIT: ?\rewardpreviewitem.cpp
// MS2-RANGE: 0x1400d5740-0x1400d58b0 .text$di
// MS2-RANGE: 0x140dc2ef0-0x140dc9b30 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: memcpy_s 0x140dc99e0
// MS2-PIN: ??_7CRewardPreviewTable@@6B?$TSingleton@VCRewardPreviewTable@@@@@ 0x142e38708
// MS2-PIN: ??_7CRewardPreviewTable@@6B?$CValidData@VCRewardPreviewTable@@@@@ 0x142e38718
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\rewardpreviewitem.cpp"
// The exe's memcpy_s is a plain call (no /Oi expansion); the pragma must precede the inline copy.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#pragma intrinsic(memset, memcpy)   // the ATL hash table / node allocation zero-fill inline (rep stosb)
#include <errno.h>
#include <string.h>
#include "rewardpreviewitem.h"
#include "ms2/commonfiles/itemdroptable.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The statics of the common header (the sort names, "skill", "stun" and the condition map).
#include "ms2/placeholder/header_statics_a.h"

// ---- unrecovered helpers (the tinyxml wrappers and the singletons the other table units share) ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const CString& strArg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pNode);                               // the row is for this client's region
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_140c09130(Unk_140165cf0* pElem, const char* pszName, Unk_DcLevelRange& range);   // "low-high"
CString FUN_14016a5c0(const char* pszName, int nFlags);                // undecorated class name
CString FUN_14016a600(const wchar_t* psz, int nFlags);                  // wide -> multibyte
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);

// ---- .text$mn ----

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CRewardPreviewTable::s_bInit;
#endif

// @0x140dc2ef0
RewardPreviewItem::RewardPreviewItem()
    : m_itemTag(RewardPreviewItemTag_None), m_bTradable(false)
{
}

// @0x140dc2f80
void RewardPreviewItem::Load(Unk_140165cf0* pElem)
{
    m_item.vfunc_2(pElem);
    XmlEnumName<RewardPreviewItemTag, ParseRewardPreviewItemTag>(pElem, "itemTag", m_itemTag);
    XmlTokenList(pElem, "reqJobs", m_reqJobs);
    FUN_140c09130(pElem, "reqLevel", m_reqLevel);
}
MS2_REPLACE_METHOD(0x140DC2F80, RewardPreviewItem, Load, 145, 0x55730D5E);

// @0x140dc3020
void RewardPreviewItem::Set(ItemDropResult& result)
{
    m_item.m_itemId = result.m_itemId;
    m_item.FUN_14026b1c0(result.vfunc_o18_1());
    m_bTradable = result.vfunc_o18_3();
}
MS2_REPLACE_METHOD(0x140DC3020, RewardPreviewItem, Set, 91, 0x33C979F5);

// @0x140dc3090
bool RewardPreviewItem::IsValid(PC* pPC)
{
    if (!IsJobValid(pPC))
        return false;
    if (!IsLevelValid(pPC))
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140DC3090, RewardPreviewItem, IsValid, 73, 0xF2594E28);

// @0x140dc30e0
RewardPreviewItemTag RewardPreviewItem::GetItemTag()
{
    return m_itemTag;
}
MS2_REPLACE_METHOD(0x140DC30E0, RewardPreviewItem, GetItemTag, 14, 0x921EE467);

// @0x140dc3100
void RewardPreviewItem::SetItemTag(RewardPreviewItemTag eTag)
{
    m_itemTag = eTag;
}
MS2_REPLACE_METHOD(0x140DC3100, RewardPreviewItem, SetItemTag, 22, 0x6608447B);

// @0x140dc3120
bool RewardPreviewItem::GetTradable()
{
    return m_bTradable;
}
MS2_REPLACE_METHOD(0x140DC3120, RewardPreviewItem, GetTradable, 15, 0x0B226339);

// @0x140dc3140
bool RewardPreviewItem::Compare(MS2Ptr<RewardPreviewItem> spA, MS2Ptr<RewardPreviewItem> spB)
{
    MS2Ptr<CItemData> spDataA = FUN_14053f870(spA->m_item.vfunc_o18_0());
    MS2Ptr<CItemData> spDataB = FUN_14053f870(spB->m_item.vfunc_o18_0());
    if (spDataA == 0 || spDataB == 0)
        return false;
    if (spA->GetItemTag() != spB->GetItemTag())
        return spA->GetItemTag() > spB->GetItemTag();
    int nRankA = spDataA->FUN_14053c5a0();
    int nRankB = spDataB->FUN_14053c5a0();
    if (nRankA == 0)
        nRankA = spA->m_item.vfunc_o18_1();
    if (nRankB == 0)
        nRankB = spB->m_item.vfunc_o18_1();
    if (nRankA != nRankB)
        return nRankA > nRankB;
    if (spDataA->FUN_14053c5c0() != spDataB->FUN_14053c5c0())
        return spDataA->FUN_14053c5c0() < spDataB->FUN_14053c5c0();
    if (spDataA->FUN_14053c5c0() == 1 && spDataA->FUN_14053c5e0() != spDataB->FUN_14053c5e0())
        return spDataA->FUN_14053c5e0() > spDataB->FUN_14053c5e0();
    return (unsigned)spDataA->FUN_14053c510() < (unsigned)spDataB->FUN_14053c510();
}
MS2_REPLACE(0x140DC3140, RewardPreviewItem::Compare, 1249, 0x17710CF3);

// @0x140dc3630
bool RewardPreviewItem::IsJobValid(PC* pPC)
{
    if (m_reqJobs.IsEmpty())
        return true;
    int nJob = pPC->FUN_141654700();
    if (nJob == 1)
        nJob = 10;
    for (unsigned i = 0; i < m_reqJobs.GetCount(); i++)
    {
        if (m_reqJobs[i] == nJob)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140DC3630, RewardPreviewItem, IsJobValid, 165, 0x3B254FB2);

// @0x140dc36e0
bool RewardPreviewItem::IsLevelValid(PC* pPC)
{
    if (m_reqLevel.m_nHigh == 0 && m_reqLevel.m_nLow == 0)
        return true;
    return m_reqLevel.FUN_1407790e0((unsigned short)pPC->vfunc_78()) == true;
}
MS2_REPLACE_METHOD(0x140DC36E0, RewardPreviewItem, IsLevelValid, 116, 0xA1A1320B);

// @0x140dc3760
RewardPreviewInfo::RewardPreviewInfo()
    : m_id(0)
{
}

// @0x140dc37b0
void RewardPreviewInfo::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_id);
    for (Unk_140165cf0* pNode = pElem->FUN_140165cf0("item"); pNode != 0; pNode = pNode->FUN_140168650("item"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        MS2Ptr<RewardPreviewItem> spItem(new RewardPreviewItem);
        spItem->Load(pNode);
        m_items.Add(spItem);
    }
}
MS2_REPLACE_METHOD(0x140DC37B0, RewardPreviewInfo, Load, 270, 0xC7EC1C1B);

// @0x140dc38d0
void RewardPreviewInfo::GetAll(ATL::CAtlList<ItemEntity>& items)
{
    for (unsigned i = 0; i < m_items.GetCount(); i++)
        items.AddTail(m_items[i]->m_item);
}
MS2_REPLACE_METHOD(0x140DC38D0, RewardPreviewInfo, GetAll, 119, 0xEF34B0EB);

// @0x140dc3950
void RewardPreviewInfo::GetValid(PC* pPC, ATL::CAtlList<ItemEntity>& items)
{
    for (unsigned i = 0; i < m_items.GetCount(); i++)
    {
        if (m_items[i]->IsValid(pPC))
            items.AddTail(m_items[i]->m_item);
    }
}
MS2_REPLACE_METHOD(0x140DC3950, RewardPreviewInfo, GetValid, 175, 0x81D5B08D);

// @0x140dc3a10
void RewardPreviewInfo::GetValidArray(PC* pPC, ATL::CAtlArray<MS2Ptr<RewardPreviewItem> >& items)
{
    for (unsigned i = 0; i < m_items.GetCount(); i++)
    {
        if (m_items[i]->IsValid(pPC))
            items.Add(m_items[i]);
    }
}
MS2_REPLACE_METHOD(0x140DC3A10, RewardPreviewInfo, GetValidArray, 160, 0x83FED185);

// @0x140dc3ac0
void RewardPreviewInfo::GetValidVector(PC* pPC, std::vector<MS2Ptr<RewardPreviewItem> >& items)
{
    for (unsigned i = 0; i < m_items.GetCount(); i++)
    {
        if (m_items[i]->IsValid(pPC))
            items.push_back(m_items[i]);
    }
}
MS2_REPLACE_METHOD(0x140DC3AC0, RewardPreviewInfo, GetValidVector, 160, 0x00487691);

// @0x140dc3b70
CRewardPreviewTable::CRewardPreviewTable()
{
}

// @0x140dc3c20
bool CRewardPreviewTable::Load()
{
    if (!LoadBoss())
        return false;
    if (!LoadDungeon())
        return false;
    SetInit(true);
    return true;
}
MS2_REPLACE_METHOD(0x140DC3C20, CRewardPreviewTable, Load, 65, 0x0E5636E2);

// @0x140dc3c70
MS2Ptr<RewardPreviewInfo> CRewardPreviewTable::GetBoss(unsigned nNpcId)
{
    CheckInit();
    MS2Ptr<RewardPreviewInfo> spInfo;
    if (m_boss.Lookup(nNpcId, spInfo))
        return spInfo;
    return MS2Ptr<RewardPreviewInfo>(0);
}
MS2_REPLACE_METHOD(0x140DC3C70, CRewardPreviewTable, GetBoss, 171, 0x908C51AF);

// @0x140dc3d30
MS2Ptr<RewardPreviewInfo> CRewardPreviewTable::GetDungeon(unsigned nDungeonRoomId)
{
    CheckInit();
    MS2Ptr<RewardPreviewInfo> spInfo;
    if (m_dungeon.Lookup(nDungeonRoomId, spInfo))
        return spInfo;
    return MS2Ptr<RewardPreviewInfo>(0);
}
MS2_REPLACE_METHOD(0x140DC3D30, CRewardPreviewTable, GetDungeon, 171, 0x0A65C89B);

// @0x140dc3df0
bool CRewardPreviewTable::ValidateBoss()
{
    CheckInit();
    ATL::CAtlMap<unsigned, CString> errors;
    for (POSITION pos = m_boss.GetStartPosition(); pos != 0; m_boss.GetNext(pos))
    {
        MS2Ptr<CNpcData> spNpc = FUN_1406cd330(m_boss.GetKeyAt(pos));
        if (spNpc == 0)
            continue;
        MS2Ptr<RewardPreviewInfo> spInfo = m_boss.GetValueAt(pos);
        if (spInfo == 0)
            continue;
        ATL::CAtlList<ItemEntity> items;
        spInfo->GetAll(items);
        for (POSITION posItem = items.GetHeadPosition(); posItem != 0; items.GetNext(posItem))
        {
            ItemEntity& item = items.GetAt(posItem);
            bool bFound = false;
            std::vector<unsigned>& boxes = spNpc->m_drop.m_aIndividualDropBoxId;
            for (size_t i = 0; i < boxes.size(); i++)
            {
                if (ItemDropTable::GetInstance()->HasItem(boxes[i], item.m_itemId, item.vfunc_o18_1()))
                    bFound = true;
            }
            if (!bFound)
            {
                CString str;
                if (boxes.empty())
                {
                    str.Format("Run Boss ItemID[%d] ItemName[%s ...] DropBoxIds Empty", item.m_itemId,
                               (const char*)FUN_14016a600(CStringTable::GetInstance()->FUN_141811980(1, item.m_itemId), 0));
                }
                else
                {
                    CString strBoxes;
                    for (size_t j = 0; j < boxes.size(); j++)
                    {
                        CString strBox;
                        strBox.Format("%d,", boxes[j]);
                        strBoxes += strBox;
                    }
                    str.Format("Run Boss ItemID[%d] ItemName[%s ...] DropBoxIds[%s]", item.m_itemId,
                               (const char*)FUN_14016a600(CStringTable::GetInstance()->FUN_141811980(1, item.m_itemId), 0),
                               (const char*)strBoxes);
                }
                errors.SetAt(item.m_itemId, str);
            }
        }
    }
    for (POSITION pos = errors.GetStartPosition(); pos != 0; errors.GetNext(pos))
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"{0}", errors.GetValueAt(pos));
    return true;
}
MS2_REPLACE_METHOD(0x140DC3DF0, CRewardPreviewTable, ValidateBoss, 1508, 0xA129A80A);

// @0x140dc43e0
bool CRewardPreviewTable::ValidateDungeon()
{
    CheckInit();
    ATL::CAtlMap<unsigned, CString> errors;
    for (POSITION pos = m_dungeon.GetHeadPosition(); pos != 0; m_dungeon.GetNext(pos))
    {
        unsigned nRoomId = m_dungeon.GetKeyAt(pos);
        DungeonRoomPtr spRoom = DungeonRoomTable::GetInstance()->GetRoom(nRoomId);
        if (spRoom == 0)
            continue;
        MS2Ptr<RewardPreviewInfo> spInfo = m_dungeon.GetValueAt(pos);
        if (spInfo == 0)
            continue;
        ATL::CAtlList<ItemEntity> items;
        spInfo->GetAll(items);
        for (POSITION posItem = items.GetHeadPosition(); posItem != 0; items.GetNext(posItem))
        {
            ItemEntity& item = items.GetAt(posItem);
            bool bFound = false;
            std::vector<unsigned>& boxes = spRoom->m_rewardDropBoxIds;
            for (size_t i = 0; i < boxes.size(); i++)
            {
                if (ItemDropTable::GetInstance()->HasItem(boxes[i], item.m_itemId, item.vfunc_o18_1()))
                    bFound = true;
            }
            if (!bFound)
            {
                CString str;
                if (boxes.empty())
                {
                    str.Format("Run Dungeon ItemID[%d] ItemName[%s ...] DropBoxIds Empty", item.m_itemId,
                               (const char*)FUN_14016a600(CStringTable::GetInstance()->FUN_141811980(1, item.m_itemId), 0));
                }
                else
                {
                    CString strBoxes;
                    for (size_t j = 0; j < boxes.size(); j++)
                    {
                        CString strBox;
                        strBox.Format("%d,", boxes[j]);
                        strBoxes += strBox;
                    }
                    str.Format("Run Dungeon ItemID[%d] ItemName[%s ...] DropBoxIds[%s]", item.m_itemId,
                               (const char*)FUN_14016a600(CStringTable::GetInstance()->FUN_141811980(1, item.m_itemId), 0),
                               (const char*)strBoxes);
                }
                errors.SetAt(item.m_itemId, str);
            }
        }
    }
    for (POSITION pos = errors.GetStartPosition(); pos != 0; errors.GetNext(pos))
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"{0}", errors.GetValueAt(pos));
    return true;
}
MS2_REPLACE_METHOD(0x140DC43E0, CRewardPreviewTable, ValidateDungeon, 1528, 0x41EE26E0);

// @0x140dc49e0
bool CRewardPreviewTable::LoadBoss()
{
    CString strPath = FUN_14071a5b0("Table", "RewardPreview_boss.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("preview"); pNode != 0; pNode = pNode->FUN_140168650("preview"))
    {
        unsigned nId = 0;
        if (FUN_140873220(pNode, "id", nId) != 0)
            continue;
        MS2Ptr<RewardPreviewInfo> spInfo(new RewardPreviewInfo);
        spInfo->Load(pNode);
        m_boss.SetAt(nId, spInfo);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140DC49E0, CRewardPreviewTable, LoadBoss, 628, 0x37464587);

// @0x140dc4c60
bool CRewardPreviewTable::LoadDungeon()
{
    CString strPath = FUN_14071a5b0("Table", "RewardPreview_dungeon.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("preview"); pNode != 0; pNode = pNode->FUN_140168650("preview"))
    {
        int nId;
        FUN_140873220(pNode, "id", nId);
        if (nId == 0)
            continue;
        MS2Ptr<RewardPreviewInfo> spInfo(new RewardPreviewInfo);
        spInfo->Load(pNode);
        m_dungeon.SetAt(nId, spInfo);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140DC4C60, CRewardPreviewTable, LoadDungeon, 623, 0xF0074044);

// @0x140dc4ee0
RewardPreviewItemTag ParseRewardPreviewItemTag(const CString& str)
{
    if (str.IsEmpty())
        return RewardPreviewItemTag_None;
    if (str.CompareNoCase("new") == 0)
        return RewardPreviewItemTag_New;
    else if (str.CompareNoCase("event") == 0)
        return RewardPreviewItemTag_Event;
    return RewardPreviewItemTag_None;
}
MS2_REPLACE(0x140DC4EE0, ParseRewardPreviewItemTag, 96, 0x4240600D);

// @0x140dc6780
void CRewardPreviewTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CRewardPreviewTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140dc8f90
void CRewardPreviewTable::SetInit(bool b)
{
    s_bInit = b;
}

// The UCRT's `static __inline memcpy_s` of this TU (kept alive by the pointer below).
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
