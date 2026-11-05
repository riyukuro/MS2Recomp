// itemdatatable.h - CItemDataTable (RTTI .?AVCItemDataTable@@, 0x4f0 bytes): the client item table singleton. It reads
// Table/ItemData.xml (drop styles and nifs, grade nifs/effects, text colours, weapon speeds, enchant nifs, item tags),
// the per-file item rows of Table/itemData/<nnn>.xml and the item models on demand, plus the colour palettes, ui
// material sounds, music scores and housing rows. Header name assumed from the unit; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <set>
#include <typeinfo>
#include <unordered_map>
#include <utility>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/blackmarketitemoption.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/placeholder/citemdata.h"

class TiXmlElement;    // game TinyXML element
CString FUN_14016a5c0(const char* psz, int n);     // the class name of a type_info name

// The key of the grade nif / grade effect / text colour maps (its own hash and compare COMDATs: an enum).
enum ItemGradeKey {};
// The key of the item tag map (a second enum: distinct hash and compare COMDATs).
enum ItemTagKey {};

// A colour palette (Table/colorPalette.xml <colorPalette>): its colours in file order and by colour SN.
class CColorPaletteInfo : public CPtred
{
public:
    typedef ATL::CAtlArray<MS2Ptr<ItemColorEx> > ColorArray;
    typedef ATL::CAtlMap<int, MS2Ptr<ItemColorEx> > ColorMap;

    CColorPaletteInfo();                                    // 0x140555a70
    virtual ~CColorPaletteInfo() = default;

    void Init();                                            // 0x140555ae0 fresh array and map
    void Clear();                                           // 0x140555b80
    bool AddColor(MS2Ptr<ItemColorEx> spColor);             // 0x140555c00

    Unk_BmBoxPtr<ColorArray> GetColors() const { return m_spColors; }
    Unk_BmBoxPtr<ColorMap> GetColorMap() const { return m_spColorMap; }

private:
    MS2_LAYOUT_FRIEND;
    Unk_BmBoxPtr<ColorArray> m_spColors;                    // +0x18
    Unk_BmBoxPtr<ColorMap> m_spColorMap;                    // +0x28 by ItemColorEx::m_nColor
};
MS2_CHECK_SIZE(CColorPaletteInfo, 0x38);

struct Unk_TrophyKey   // (trophyID, trophyLevel) of a housing row: the key of CItemDataTable::m_setTrophy (and DAT_143ab32d8)
{
    Unk_TrophyKey();                                                                 // 0x1409ed810 (inline in astooltip_local.h)
    Unk_TrophyKey(unsigned nId, unsigned nLevel) : m_nId(nId), m_nLevel(nLevel) {}  // 0x14056beb0
    bool operator<(const Unk_TrophyKey& o) const                                     // 0x14056e500
    {
        if (m_nId != o.m_nId)
            return m_nId < o.m_nId;
        else
            return m_nLevel < o.m_nLevel;
    }
    unsigned m_nId;     // +0x00
    unsigned m_nLevel;  // +0x04
};
MS2_CHECK_SIZE(Unk_TrophyKey, 0x8);

class CItemDataTable : public CCacheData,
                       public TSingleton<CItemDataTable>,
                       public CValidData<CItemDataTable>
{
public:
    // An item tag (ItemData.xml <tag>, names registered by InitItemTags).
    class ItemTagParam : public CPtred
    {
    public:
        virtual ~ItemTagParam() = default;
        CString m_strName;                                  // +0x18
        int m_nItemId;                                      // +0x20
        ItemTagKey m_eTag;                                  // +0x24
    };

    typedef MS2Ptr<CItemData> ItemDataPtr;
    typedef MS2Ptr<ItemModelData> ModelPtr;
    typedef Delegate<bool(const ItemColorEx&, MS2Ptr<CItemData>)> ColorFilter;

    CItemDataTable();                                       // 0x140555ce0
    virtual ~CItemDataTable();                              // 0x140556140

    MS2Ptr<ItemDropEffect> GetDropEffect(int nType);                        // 0x140556380
    MS2Ptr<ItemDropEffect> GetItemDropEffect(unsigned nItemId, unsigned nValue); // 0x140556440
    MS2Ptr<ItemMusicScore> GetMusicScore(unsigned nId);                       // 0x1405565f0
    MS2Ptr<ItemHousing> GetHousing(unsigned nId);                             // 0x1405566e0
    CString GetGradeNif(ItemGradeKey eGrade);                               // 0x1405567e0
    CString GetGradePetNif(ItemGradeKey eGrade);                            // 0x1405568a0
    CString GetGradeEffect(ItemGradeKey eGrade);                            // 0x140556930
    unsigned GetTextColor(ItemGradeKey eGrade);                             // 0x1405569f0
    CStringW GetTextColorString(ItemGradeKey eGrade);                       // 0x140556a40
    int GetWeaponSpeed(int nWeapon);                                        // 0x140556aa0
    float GetRevisionRatio(int nWeapon, int nIndex);                        // 0x140556af0
    void Load();                                                            // 0x140556b70
    void Reload();                                                          // 0x140556ea0
    void LoadAllItemData();                                                 // 0x140556f50
    void LoadBlackMarketSearchable();                                       // 0x140557050
    std::set<Unk_TrophyKey>* GetTrophySet();                         // 0x140557250
    CString GetEnchantNif(int nWeapon, int nEnchant, int nUnlimited, unsigned nType);   // 0x140557270
    int GetTagItemId(ItemTagKey eTag);                                      // 0x1405575b0
    ItemTagKey GetTagByName(const CString& strName);                        // 0x140557640
    CString GetTagName(ItemTagKey eTag);                                    // 0x140557730
    ModelPtr GetModel(unsigned nPreset);                                    // 0x1405577f0
    void FUN_140557910(int);                                                // 0x140557910 (empty)
    void GetHousingByCategory(int nCategory, ATL::CAtlArray<MS2Ptr<ItemHousing> >& out);  // 0x140557920
    bool FindItems(unsigned short nLevel, int nGender, int nJob, int nType, ATL::CAtlArray<ItemDataPtr>& out);    // 0x140557a30
    ItemDataPtr GetItemData(int nItemId);                                   // 0x140557f70
    void LoadItemFile(const CString& strPath, std::vector<ItemDataPtr>& out);   // 0x140558060
    void LoadItemDataFile(unsigned nFile);                                  // 0x140558260
    CString GetUiMaterialSound(unsigned nMaterial);                         // 0x140558690
    MS2Ptr<ItemColorEx> GetPaletteColor(int nPalette, unsigned nIndex);    // 0x1405587f0
    MS2Ptr<ItemColorEx> GetPaletteColorBySN(int nPalette, int nColorSN);   // 0x140558960
    Unk_BmBoxPtr<CColorPaletteInfo::ColorArray> GetPaletteColors(int nPalette);     // 0x140558ad0
    MS2Ptr<ItemColorEx> GetPaletteColorOrRandom(int nPalette, int nIndex); // 0x140558b90
    MS2Ptr<ItemColorEx> FindPaletteColor(int nPalette, const int& nCh0);   // 0x140558cc0
    MS2Ptr<ItemColorEx> FindPaletteColor(int nPalette, ItemDataPtr spItem, ColorFilter fnFilter);  // 0x140558e80
    MS2Ptr<ItemColorEx> FindPaletteColor(int nPalette, const int& nCh0, const int& nCh1);  // 0x1405590e0
    ATL::CRBMap<CStringW, int, ATL::CStringElementTraitsI<CStringW> >* GetBlackMarketSearchable();  // 0x1405592c0
    void GetAllItemData(std::vector<ItemDataPtr>& out);                     // 0x1405592e0
    void GetAllModels(std::vector<ModelPtr>& out);                          // 0x1405593d0
    void LoadItemNameIds(std::vector<unsigned>& out);                       // 0x1405594b0
    void ResetAllItemData();                                                // 0x140559690
    CString GetDefaultUiMaterialSound();                                    // 0x140559750

    static void CheckInit()
    {
        if (!s_bInit)
        {
            CString msg;
            msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemDataTable).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    static void SetInit(bool b) { s_bInit = b; }
    static bool s_bInit;                                                    // 0x143aaf964

private:
    void LoadDropStyle(TiXmlElement* pRoot);                               // 0x1405597a0
    void LoadDropItemAsset(TiXmlElement* pRoot);                           // 0x1405598c0
    void LoadGradeNif(TiXmlElement* pRoot);                                // 0x140559a50
    void LoadGradePetNif(TiXmlElement* pRoot);                             // 0x140559b40
    void LoadGradeEffect(TiXmlElement* pRoot);                             // 0x140559c30
    void LoadTextColor(TiXmlElement* pRoot);                               // 0x140559d20
    void LoadWeaponSpeed(TiXmlElement* pRoot);                             // 0x140559e60
    void LoadRevisionRatio(TiXmlElement* pRoot);                           // 0x140559f00
    void LoadEnchant(TiXmlElement* pRoot);                                 // 0x140559fa0
    void LoadUnlimitedEnchant(TiXmlElement* pRoot);                        // 0x14055a120
    void LoadUiMaterialSound();                                             // 0x14055a230
    void LoadColorPalette(const CString& strPath);                          // 0x14055a4a0
    void LoadMusicScore();                                                  // 0x14055ad50
    void LoadHousing();                                                     // 0x14055b030
    void InitItemTags();                                                    // 0x14055b3f0
    void AddItemTag(ItemTagKey eTag, CString strName);                      // 0x14055f090
    void LoadTagItemIds(TiXmlElement* pRoot);                              // 0x14055f190
    void OnItemLoaded(ItemDataPtr spItem);                                  // 0x14055f2c0
    ItemDataPtr FindItemData(int nItemId);                                  // 0x14055f300
    MS2Ptr<ItemTagParam> FindTag(ItemTagKey eTag);                          // 0x14055f440
    ModelPtr FindModel(unsigned nPreset);                                   // 0x14055f4d0
    bool LoadModel(unsigned nPreset);                                       // 0x14055f640
    bool LoadModelFile(unsigned nFile);                                     // 0x14055f970
    int GetEnchantKey(int nWeapon, int nLevel);                             // 0x14055fce0

    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_csModel;                                         // +0x38
    std::map<unsigned, ModelPtr> m_mapModel;                                // +0x68
    std::map<unsigned, MS2Ptr<ItemMusicScore> > m_mapMusicScore;               // +0x78
    std::map<unsigned, MS2Ptr<ItemHousing> > m_mapHousing;                     // +0x88
    std::set<Unk_TrophyKey> m_setTrophy;                                    // +0x98 (trophyID, trophyLevel) of housing rows
    std::set<unsigned> m_setModelFile;                                      // +0xa8 loaded model files
    CLockCriticalSection m_cs;                                              // +0xb8
    std::unordered_map<int, ItemDataPtr> m_mapItem;                         // +0xe8
    std::set<unsigned> m_setItemFile;                                       // +0x128 loaded itemData files
    ATL::CAtlMap<ItemGradeKey, CString> m_mapGradeNif;                      // +0x138
    ATL::CAtlMap<ItemGradeKey, CString> m_mapGradePetNif;                   // +0x180
    ATL::CAtlMap<ItemGradeKey, CString> m_mapGradeEffect;                   // +0x1c8
    ATL::CAtlMap<ItemGradeKey, unsigned> m_mapTextColor;                    // +0x210
    ATL::CAtlMap<int, MS2Ptr<ItemDropEffect> > m_mapDropEffect;             // +0x258
    ATL::CAtlMap<int, CString> m_mapEnchant;                                // +0x2a0 by GetEnchantKey
    ATL::CAtlMap<int, CString> m_mapUnlimitedEnchant;                       // +0x2e8 by weapon
    std::map<unsigned, std::vector<MS2Ptr<DropNifData> > > m_mapDropNif;       // +0x330
    ATL::CAtlMap<ItemTagKey, MS2Ptr<ItemTagParam> > m_mapTag;               // +0x340
    ATL::CAtlMap<unsigned, CString> m_mapUiMaterialSound;                   // +0x388
    ATL::CAtlMap<int, Unk_BmPtr<CColorPaletteInfo> > m_mapPalette;             // +0x3d0
    ATL::CRBMap<CStringW, int, ATL::CStringElementTraitsI<CStringW> > m_mapBlackMarketSearchable;  // +0x418
    std::vector<unsigned> m_vec448;                                         // +0x448
    ATL::CAtlMap<int, int> m_mapWeaponSpeed;                                // +0x460
    ATL::CAtlMap<int, float> m_mapRevisionRatio;                            // +0x4a8
};
MS2_CHECK_SIZE(CItemDataTable, 0x4f0);
