// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ItemGachaBoxTable: Table/gacha_info.xml (the random boxes).
// MS2-UNIT: commonfiles\itemgachaboxtable.cpp
// MS2-RANGE: 0x14059dcd0-0x1405a3940 .text$mn
// MS2-RANGE: 0x1400b9f50-0x1400ba010 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$construct@V?$MS2SvrPtr@VGachaBoxData@@@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$MS2SvrPtr@VGachaBoxData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2SvrPtr@VGachaBoxData@@@@@1@QEAV?$MS2SvrPtr@VGachaBoxData@@@@AEAV3@@Z 0x1405a1230 ; unique
// MS2-PIN: ??$construct@V?$MS2SvrPtr@VGachaBoxData@@@@V1@@?$_Default_allocator_traits@V?$allocator@V?$MS2SvrPtr@VGachaBoxData@@@@@std@@@std@@SAXAEAV?$allocator@V?$MS2SvrPtr@VGachaBoxData@@@@@1@QEAV?$MS2SvrPtr@VGachaBoxData@@@@$$QEAV3@@Z 0x1405a12d0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemgachaboxtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemgachaboxtable.h"
#include "itemdroptable.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
void FUN_140873600(Unk_140165cf0*, const char*, CMsTime&);          // date attribute
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
extern bool FUN_1403b3c40(const CStringW&, const wchar_t*);          // function name equals

extern int DAT_143ab0248;

static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x14059dcd0
GachaBoxData::GachaBoxData()
{
    m_nRandomBoxID = 0;
    m_nRandomBoxGroup = 0;
    m_bSeasonNumberOnIcon = false;
    m_saleEndDate = CMsTime(0);
    m_nUi = 0;
    m_nIndividualDropBoxID = 0;
    m_nShopID = 0;
    m_nCoinItemID = 0;
    m_nCoinItemAmount = 1;
    m_nPaymentIconTag = 0;
    for (int i = 0; i < 4; i++)
        m_nSeason[i] = 0;
}

// @0x14059ddc0
GachaBoxData::~GachaBoxData()
{
}

// @0x14059ddf0
int GachaBoxData::GetSeason() const
{
    return m_nSeason[DAT_143ab0248];
}

// @0x1405a1600
TSingleton<ItemGachaBoxTable>::TSingleton()
{
    s_instance = reinterpret_cast<ItemGachaBoxTable*>(this);
}

// @0x14059de10
ItemGachaBoxTable::ItemGachaBoxTable()
{
}

// @0x14059de60
ItemGachaBoxTable::~ItemGachaBoxTable()
{
}

// @0x14059dea0
// MS2-FUNCTIONAL: EH-state/temp-CString layout of the XML loader differs from the exe (precedent banktable.cpp)
void ItemGachaBoxTable::Load()
{
    m_map.clear();
    CString strDir;
    strDir.Format("%s", "Table");
    CString strPath = FUN_14071a5b0(strDir, CString("gacha_info.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "randomBox", "randomBoxID", &nodes);
    for (unsigned __int64 i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        GachaBoxDataPtr spBox(MS2SvrNewTag(0));
        FUN_140873220(pNode, "randomBoxID", reinterpret_cast<unsigned&>(spBox->m_nRandomBoxID));
        FUN_140873220(pNode, "randomBoxGroup", reinterpret_cast<unsigned&>(spBox->m_nRandomBoxGroup));
        FUN_140873220(pNode, "randomBoxSeasonKR", reinterpret_cast<unsigned&>(spBox->m_nSeason[0]));
        FUN_140873220(pNode, "randomBoxSeasonJP", reinterpret_cast<unsigned&>(spBox->m_nSeason[1]));
        FUN_140873220(pNode, "randomBoxSeasonNA", reinterpret_cast<unsigned&>(spBox->m_nSeason[2]));
        FUN_140873220(pNode, "randomBoxSeasonCN", reinterpret_cast<unsigned&>(spBox->m_nSeason[3]));
        FUN_140873600(pNode, "saleEndDate", spBox->m_saleEndDate);
        FUN_140873220(pNode, "ui", reinterpret_cast<unsigned&>(spBox->m_nUi));
        FUN_140873220(pNode, "individualDropBoxID", reinterpret_cast<unsigned&>(spBox->m_nIndividualDropBoxID));
        FUN_140873220(pNode, "shopID", reinterpret_cast<unsigned&>(spBox->m_nShopID));
        FUN_140873220(pNode, "coinItemID", reinterpret_cast<unsigned&>(spBox->m_nCoinItemID));
        FUN_140873220(pNode, "coinItemAmount", reinterpret_cast<unsigned&>(spBox->m_nCoinItemAmount));
        FUN_1408730a0(pNode, "seasonNumberOnIcon", spBox->m_bSeasonNumberOnIcon);
        FUN_140873220(pNode, "paymentIconTag", reinterpret_cast<unsigned&>(spBox->m_nPaymentIconTag));
        int nKey = spBox->m_nRandomBoxID;
        m_map[nKey] = spBox;
    }
}

// @0x14059e340
GachaBoxDataPtr ItemGachaBoxTable::FUN_14059e340(int nRandomBoxID)
{
    std::map<int, GachaBoxDataPtr>::iterator it = m_map.find(nRandomBoxID);
    if (it == m_map.end())
        return GachaBoxDataPtr(0);
    return it->second;
}

// @0x14059e400
int ItemGachaBoxTable::GetIndividualDropBoxID(int nRandomBoxID)
{
    std::map<int, GachaBoxDataPtr>::iterator it = m_map.find(nRandomBoxID);
    if (it == m_map.end())
        return 0;
    return it->second->m_nIndividualDropBoxID;
}

// @0x14059e490
int ItemGachaBoxTable::FUN_14059e490(int nShopID)
{
    for (std::map<int, GachaBoxDataPtr>::iterator it = m_map.begin(); it != m_map.end(); ++it)
    {
        GachaBoxDataPtr& sp = it->second;
        if (sp.get() != 0 && sp->m_nShopID == nShopID)
            return sp->m_nUi;
    }
    return 0;
}

// @0x14059e550
int ItemGachaBoxTable::FUN_14059e550(int nShopID)
{
    for (std::map<int, GachaBoxDataPtr>::iterator it = m_map.begin(); it != m_map.end(); ++it)
    {
        GachaBoxDataPtr& sp = it->second;
        if (sp.get() != 0 && sp->m_nShopID == nShopID)
            return sp->m_nCoinItemID;
    }
    return 0;
}

// @0x14059e610
int ItemGachaBoxTable::GetCoinItemID(int nRandomBoxID)
{
    std::map<int, GachaBoxDataPtr>::iterator it = m_map.find(nRandomBoxID);
    if (it == m_map.end())
        return 0;
    return it->second->m_nCoinItemID;
}

// @0x14059e6a0
int ItemGachaBoxTable::FUN_14059e6a0(int nItemID)
{
    if (nItemID == 0)
        return 0;
    MS2Ptr<CItemData> item = FUN_14053f870(nItemID);
    if (item == 0)
        return 0;
    int nBoxId = item->FUN_14053dec0();
    if (nBoxId != 0)
        return GetCoinItemID(nBoxId);
    std::vector<ItemDropResult> drops;
    ItemDropContext ctx;
    if (FUN_1403b3c40(item->function.name, L"OpenItemBox"))
    {
        TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(item->function.arg0, ctx, drops, true);
    }
    else if (FUN_1403b3c40(item->function.name, L"OpenItemBoxWithKey"))
    {
        int nId = item->function.parameter.FUN_1408d1fd0(5, 0);
        TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(nId, ctx, drops, true);
    }
    else
    {
        int nDefault0 = 0;
        int nCommon = item->function.xml.GetInt(L"commonBoxId", nDefault0);
        int nDefault1 = 0;
        int nUnCommon = item->function.xml.GetInt(L"unCommonBoxId", nDefault1);
        int nDefault2 = 0;
        int nIndividual = item->function.xml.GetInt(L"individualDropBoxId", nDefault2);
        if (nCommon != 0)
            TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(nCommon, ctx, drops, true);
        if (nUnCommon != 0)
            TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(nUnCommon, ctx, drops, true);
        if (nIndividual != 0)
            TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(nIndividual, ctx, drops, true);
    }
    for (ItemDropResult r : drops)
    {
        item = FUN_14053f870(r.vfunc_o18_0());
        if (item == 0)
            return 0;
        int nId = item->FUN_14053dec0();
        if (nId != 0)
            return GetCoinItemID(nId);
    }
    return 0;
}

// @0x14059ebb0
int ItemGachaBoxTable::FUN_14059ebb0(int nCoinItemID)
{
    for (std::map<int, GachaBoxDataPtr>::iterator it = m_map.begin(); it != m_map.end(); ++it)
    {
        GachaBoxDataPtr& sp = it->second;
        if (sp.get() != 0 && sp->m_nCoinItemID == nCoinItemID)
            return sp->m_nRandomBoxID;
    }
    return 0;
}

// @0x14059ec70
void ItemGachaBoxTable::FUN_14059ec70(std::vector<GachaBoxDataPtr>& out)
{
    for (std::map<int, GachaBoxDataPtr>::iterator it = m_map.begin(); it != m_map.end(); ++it)
        out.push_back(it->second);
}

// @0x14059ed00
int ItemGachaBoxTable::FUN_14059ed00(int nId)
{
    for (std::map<int, GachaBoxDataPtr>::iterator it = m_map.begin(); it != m_map.end(); ++it)
    {
        GachaBoxDataPtr& sp = it->second;
        if (sp.get() != 0)
        {
            int nCoin = sp->m_nCoinItemID;
            if (sp->m_nRandomBoxID == nId || nCoin == nId)
                return sp->GetSeason();
        }
    }
    return 0;
}

// @0x14059ee00
int ItemGachaBoxTable::FUN_14059ee00(int nShopID)
{
    for (std::map<int, GachaBoxDataPtr>::iterator it = m_map.begin(); it != m_map.end(); ++it)
    {
        GachaBoxDataPtr& sp = it->second;
        if (sp.get() != 0 && sp->m_nShopID == nShopID)
            return sp->m_nPaymentIconTag;
    }
    return 0;
}

// @0x14059eec0
bool ItemGachaBoxTable::FUN_14059eec0(int nCoinItemID)
{
    for (std::map<int, GachaBoxDataPtr>::iterator it = m_map.begin(); it != m_map.end(); ++it)
    {
        GachaBoxDataPtr& sp = it->second;
        if (sp.get() != 0 && sp->m_nCoinItemID == nCoinItemID)
            return true;
    }
    return false;
}

// @0x14059ef70
bool ItemGachaBoxTable::FUN_14059ef70(int nRandomBoxID)
{
    std::map<int, GachaBoxDataPtr>::iterator it = m_map.find(nRandomBoxID);
    if (it == m_map.end())
        return false;
    return it->second->m_bSeasonNumberOnIcon;
}
