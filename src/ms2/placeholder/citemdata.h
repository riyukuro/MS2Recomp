// CItemData, RTTI and 0x390 allocation/layout from itemdata.cpp.
// Heap-only placeholder: inventory reads stack limit and function metadata.
#pragma once
#include <afx.h>
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/cobjectcount.h"
#include "ms2/ms2layout.h"
#include <efd/Point3.h>
#include <atlcoll.h>
#include <set>
#include <vector>
#include "ms2/placeholder/cxmldata.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"

class Unk_140165cf0;                // game TinyXML element (declared where the loaders are)
class ItemModelData;                // itemdata.h
class CItemExtraData;               // citemextradata.h

// The blocks of an item row. Their constructors, XML readers/writers and comparisons live in
// commonfiles\itemdatastruct.cpp; the destructors of the blocks that own heap data are in commonfiles\itemdata.cpp.
// Names of the members that are not read by recovered code are invented from the XML attribute they hold.
struct ItemSkill                    // <skill skillID skillLevel>
{
    ItemSkill();                    // 0x140546740
    int FUN_140546770(Unk_140165cf0* pElem);        // XML read (the <skill> child of pElem)
    int FUN_1405467f0(void* pParent);               // XML write (nothing)
    bool FUN_140546810(const ItemSkill* pOther);    // operator!=
    unsigned skillId;               // +0x00 "skillID"
    unsigned short skillLevel;      // +0x04 "skillLevel" (default 1)
    unsigned short unknown6;
};
MS2_CHECK_SIZE(ItemSkill, 0x8);

struct ItemMaterial                 // <material ... attack>
{
    ItemMaterial();                 // 0x140547390
    int FUN_1405473c0(Unk_140165cf0* pElem);
    int FUN_140547440(void* pParent);
    bool FUN_140547460(const ItemMaterial* pOther);
    int unknown0;
    int attack;
};
MS2_CHECK_SIZE(ItemMaterial, 0x8);

struct ItemProperty                 // <property> block: slotMax, collection, price, ...
{
    ItemProperty();                 // 0x1405474a0
    ~ItemProperty();                // 0x140540eb0
    void Load(Unk_140165cf0* pElem);       // XML read
    void FUN_1405479a0(void* pElem);                // XML write (attributes of the <property> element)
    bool FUN_140547ec0(const ItemProperty* pOther); // operator!=
    __int64 FUN_1405480f0(int nRarity);             // sell price (one value, or one per rarity 1..6)
    CString* FUN_1405481d0();                       // &slotIcon
    CString slotIcon;               // +0x00
    bool flag08;                    // +0x08
    bool flag09;                    // +0x09 (CItemData +0x79 is set from it)
    int collection;                 // +0x0c
    int doNotPreview;               // +0x10
    int applyFatiguePenalty;        // +0x14
    unsigned slotMax;               // +0x18 (default 1; clamped to 99999 on read)
    int unknown1c;
    CString movie;                  // +0x20
    CString category;               // +0x28
    CString blackMarketCategory;    // +0x30
    unsigned gearScore;             // +0x38
    bool remakeDisable;             // +0x3c
    int tradableCountDeduction;     // +0x40
    int unlimitedEnchantMaxGrade;   // +0x44
    unsigned socketDataId;          // +0x48
    int rePackingLimitCount;        // +0x4c
    int rePackingItemConsumeCount;  // +0x50
    ATL::CAtlArray<int> rePackingScrollID;  // +0x58
    bool moveDisable;               // +0x78
    std::vector<__int64> sellPrice; // +0x80 <sell price>: one value or six
};
MS2_CHECK_SIZE(ItemProperty, 0x98);
MS2_CHECK_OFFSET(ItemProperty, slotMax, 0x18);
MS2_CHECK_OFFSET(ItemProperty, rePackingScrollID, 0x58);
MS2_CHECK_OFFSET(ItemProperty, sellPrice, 0x80);

enum ItemExpirationType { ItemExpirationTypeNone = 0 };     // <life> "expirationType" (enumerators not recovered)

struct ItemPeriod                   // <life ...>
{
    ItemPeriod();                   // 0x1405460f0
    ~ItemPeriod();                  // 0x140540db0
    int Load(Unk_140165cf0* pElem);        // XML read (the <life> child of pElem)
    int Save(void* pParent);               // XML write (nothing when all fields are empty)
    bool FUN_140546620(const ItemPeriod* pOther);   // operator!=
    int FUN_1405466d0();            // the item has a limited life
    int usePeriod;                  // +0x00 "usePeriod"
    CMsTime expiration;             // +0x08 "expirationPeriod" (y-m-d-h-m-s)
    ItemExpirationType expirationType;  // +0x18 "expirationType"
    unsigned numberOfWeeksMonths;   // +0x1c "numberOfWeeksMonths"
    CStringW termTag;               // +0x20
};
MS2_CHECK_SIZE(ItemPeriod, 0x28);

// Enum attributes of <limit> (read with the tinyxmlhelper.h enum reader; the enumerators are not recovered).
enum ItemTransferType { ItemTransferTypeNone = 0 };     // "transferType" / "globalTransferType"
enum ItemEnableBreak { ItemEnableBreakNone = 0 };       // "enableBreak"

struct ItemLimit                    // <limit ...>
{
    ItemLimit();                    // 0x140545220
    ~ItemLimit();                   // 0x140540dd0
    int Load(Unk_140165cf0* pElem);        // XML read (the <limit> child of pElem)
    int Save(void* pParent);               // XML write (nothing when equal to the default)
    bool FUN_140545a80(const ItemLimit* pOther);    // operator==
    bool FUN_140545ad0(const ItemLimit* pOther);    // operator!=
    bool FUN_140545c80(int nJob);                   // job allowed
    bool FUN_140545da0(int nJob);                   // job recommended (true when none are)
    bool FUN_140545e40();                           // the item has a job restriction
    bool FUN_140545f30();                           // transfer type 0, 3, 4 or 5
    unsigned FUN_140545f70();                       // job flags of the recommended jobs (0xfff when none)
    unsigned FUN_140546030();                       // job flags of the job limit (0xfff when it allows all)
    unsigned levelLimit;            // +0x00 "levelLimit" (default 1)
    unsigned genderLimit;           // +0x04 "genderLimit" (default 2 = both)
    ATL::CAtlArray<unsigned> jobLimit;          // +0x08
    ATL::CAtlArray<unsigned> disableJobLimit;   // +0x28
    std::set<int> recommendJobs;    // +0x48
    ItemTransferType transferType;  // +0x58
    int transferTypeVersion;        // +0x5c
    bool shopSell;                  // +0x60
    ItemEnableBreak enableBreak;    // +0x64
    bool enableRegisterMeratMarket; // +0x68
    bool exceptEnchant;             // +0x69
    bool flag6a;                    // +0x6a "vip"
    bool wedding;                   // +0x6b
    int vipLevel;                   // +0x6c
};
MS2_CHECK_SIZE(ItemLimit, 0x70);

// <install> element of an item XML (commonfiles\itemdatastruct.cpp): default ctor 0x1405481f0,
// XML read 0x140548320, XML write 0x1405485b0 (skipped when equal to a static default), operator!= 0x140548aa0
// (operator== 0x140548a50). Field names are the XML attribute names; the struct name is invented.
struct ItemInstallData {
    ItemInstallData();        // 0x1405481f0
    ~ItemInstallData();       // 0x140540d70
    CString asset;            // +0x00 "asset"
    CString preset;           // +0x08 "preset"
    int space;                // +0x10 "space": placement mask, tested as (space & CFieldData indoor mask) == mask
    int placeable;            // +0x14 "placeable"
    int stackable;            // +0x18 "stackable"
    int attachable;           // +0x1c "attachable"
    int wall;                 // +0x20 "wall"
    int cubeProp;             // +0x24 "cubeProp"
    int animatable;           // +0x28 "animatable"
    int generatePhysX;        // +0x2c "generatePhysX"
    int unchangeable;         // +0x30 "unchangeable"
    int cannotStackAttach;    // +0x34 "cannotStackAttach"
    unsigned objCode;         // +0x38 "objCode" (read as unsigned, 0x140873220)
    float staticAngle;        // +0x3c "staticAngle"
    efd::Point3 physXdimension; // +0x40 "physXdimension" "%.6f, %.6f, %.6f"
    int unknown4c;            // +0x4c alignment
    CString mapAttribute;     // +0x50 "mapAttribute"
    int propCollisionGroup;   // +0x58 "propCollisionGroup"
    bool useInstancing;       // +0x5c "useInstancing" (default true)
    int Load(Unk_140165cf0* pElem);     // XML read
    int Save(void* pParent);            // XML write
    bool FUN_140548a50(const ItemInstallData* pOther);   // operator==
    bool FUN_140548aa0(const ItemInstallData* pOther);   // operator!=
    int FUN_140548cb0();      // stackable
    bool FUN_140548cd0();     // space & 6
    bool FUN_140548d10();     // space & 1 (ugccubepalette.cpp)
    bool FUN_140548d50();     // stackable has all of bits 1, 2 and 4
};
MS2_CHECK_SIZE(ItemInstallData, 0x60);
MS2_CHECK_OFFSET(ItemInstallData, space, 0x10);
MS2_CHECK_OFFSET(ItemInstallData, cubeProp, 0x24);
MS2_CHECK_OFFSET(ItemInstallData, animatable, 0x28);
MS2_CHECK_OFFSET(ItemInstallData, objCode, 0x38);
MS2_CHECK_OFFSET(ItemInstallData, physXdimension, 0x40);
MS2_CHECK_OFFSET(ItemInstallData, mapAttribute, 0x50);
MS2_CHECK_OFFSET(ItemInstallData, useInstancing, 0x5c);

struct ItemUccMesh                  // <ucc mesh> block: the mesh name (cubecraft reads it as a CString)
{
    ItemUccMesh();                  // 0x1405495a0
    ~ItemUccMesh();                 // 0x1405410a0
    int FUN_1405495d0(Unk_140165cf0* pElem);
    int FUN_140549630(void* pParent);
    CString mesh;                   // +0x00 "mesh"
};
MS2_CHECK_SIZE(ItemUccMesh, 0x8);

struct ItemEffect                   // <effect ...>
{
    ItemEffect();                   // 0x1405496c0
    ~ItemEffect();                  // 0x140540cb0
    int Load(Unk_140165cf0* pElem);
    int Save(void* pParent);
    bool FUN_140549a40(const ItemEffect* pOther);   // operator!=
    bool FUN_140549b10();           // any field differs from the default
    int enchantShape;               // +0x00 "enchantShape" (default 1)
    CString idle;                   // +0x08 "idle"
    CString battleIdle;             // +0x10 "battleIdle"
    CString characterIdle;          // +0x18 "characterIdle"
    CString characterBattleIdle;    // +0x20 "characterBattleIdle"
    bool sameBattleIdle;            // +0x28 idle == battleIdle (no case)
    bool sameCharacterBattleIdle;   // +0x29 characterIdle == characterBattleIdle (no case)
};
MS2_CHECK_SIZE(ItemEffect, 0x30);

enum ItemHousingFilter { ItemHousingFilterDefault = 100 };          // <housing> "filter" (enumerators not recovered)
enum ItemHousingCategory { ItemHousingCategoryDefault = 10000 };    // <housing> "categoryIndex"

// The <MusicScore> block of a music score item (RTTI ItemMusicScore, 0x40 bytes, vftable 0x142d5c068). Ctor, reader,
// writer and comparison are in commonfiles\itemdatastruct.cpp.
class ItemMusicScore : public CPtred
{
public:
    ItemMusicScore();                                       // 0x14054a720
    int FUN_14054a7b0(Unk_140165cf0* pElem);                // XML read (the <MusicScore> child of pElem)
    int FUN_14054a8c0(Unk_140165cf0* pElem);                // XML read (the attributes of pElem)
    int Save(void* pParent);                       // XML write (nothing when equal to the default)
    bool FUN_14054abd0(const ItemMusicScore* pOther);       // operator!=
    bool FUN_14054aca0();                                   // isCustomNote
    int FUN_14054acc0();                                    // noteLengthMax
    int FUN_14054ace0();                                    // playTime
    int FUN_14054ad00();                                    // playCount
    CStringW FUN_14054ad20();                               // the title of the recommended music book
    int FUN_14054ade0();                                    // masteryValueMax
    int playCount;                      // +0x18 "playCount"
    int unknown1c;
    int masteryValueMax;                // +0x20 "masteryValueMax"
    bool isCustomNote;                  // +0x24 "isCustomNote"
    int recommendCategoryId;            // +0x28 "recommendCategoryId" (a music book id)
    int noteLengthMax;                  // +0x2c "noteLengthMax"
    CString fileName;                   // +0x30 "fileName"
    int playTime;                       // +0x38 "playTime"
};
MS2_CHECK_SIZE(ItemMusicScore, 0x40);
MS2_CHECK_OFFSET(ItemMusicScore, fileName, 0x30);

// <housing> block (RTTI .?AVItemHousing@@, vftable 0x142d5c058 holds only the destructor). Its constructor, XML
// reader/writer and comparison are in commonfiles\itemdatastruct.cpp; the price fields come from the price table
// (commonfiles\pricetable.cpp) for the item id.
class ItemHousing : public CPtred
{
public:
    ItemHousing();                                          // 0x140548d90
    int FUN_140548e50(Unk_140165cf0* pElem, int nItemId);   // XML read (the <housing> child of pElem)
    void FUN_140548fe0(Unk_140165cf0* pElem, int nItemId);  // XML read (the attributes of pElem)
    int Save(void* pParent);                       // XML write (nothing when equal to the default)
    bool FUN_140549380(const ItemHousing* pOther);          // operator!=
    int FUN_140549470(int nItemId, __int64 nUid, __int64 nUgc);     // the item can be placed
    int FUN_1405494e0();                                    // item id
    __int64 price;                      // +0x18 price table
    std::vector<unsigned> categoryTag;  // +0x20 "categoryTag"
    ItemHousingFilter filter;           // +0x38 "filter" (default 100)
    ItemHousingCategory categoryIndex;  // +0x3c "categoryIndex" (default 10000)
    int priceCount;                     // +0x40 price table (default 1)
    unsigned trophyID;                  // +0x44 "trophyID"
    unsigned trophyLevel;               // +0x48 "trophyLevel" (default 1)
    unsigned short interiorLevel;       // +0x4c "interiorLevel" (default 1)
    bool hasPrice;                      // +0x4e the price table has the item
    unsigned setItemID;                 // +0x50 "setItemID"
    bool doNotInstallBlueprint;         // +0x54 "doNotInstallBlueprint"
    int itemId;                         // +0x58
};
MS2_CHECK_SIZE(ItemHousing, 0x60);
MS2_CHECK_OFFSET(ItemHousing, categoryTag, 0x20);
MS2_CHECK_OFFSET(ItemHousing, interiorLevel, 0x4c);
MS2_CHECK_OFFSET(ItemHousing, itemId, 0x58);

struct ItemFusion                   // <fusion fusionable>
{
    ItemFusion();                   // 0x140549500
    int FUN_140549520(Unk_140165cf0* pElem);
    int FUN_140549580(void* pParent);
    int fusionable;
    int unknown4;
};
MS2_CHECK_SIZE(ItemFusion, 0x8);

struct ItemAdditionalEffect         // <AdditionalEffect ...>
{
    ItemAdditionalEffect();         // 0x140549bb0
    ~ItemAdditionalEffect();        // 0x140540c40
    int FUN_140549c00(Unk_140165cf0* pElem);
    int FUN_140549d40(void* pParent);
    bool FUN_140549d60(const ItemAdditionalEffect* pOther);     // operator!=
    unsigned FUN_140549de0();       // the first id (0 when none)
    unsigned short FUN_140549e20(); // the first level (0 when none)
    ATL::CAtlArray<unsigned> ids;           // +0x00 "id"
    ATL::CAtlArray<unsigned short> levels;  // +0x20 "level"
    int dropEffect;                 // +0x40 "dropEffect"
    int unknown44;
};
MS2_CHECK_SIZE(ItemAdditionalEffect, 0x48);

struct ItemFunctionArgs             // the <function> parameter string split into arguments, 0x70 bytes
{
    ItemFunctionArgs();             // 0x1408d1bd0
    ~ItemFunctionArgs();            // 0x140540c00
    void FUN_1408d1e00(CStringW strText, CStringW strSeparators);   // split strText into args
    unsigned FUN_1408d2380();       // the argument count
    unsigned FUN_1408d1f60(int nIndex, int nDefault);
    CStringW FUN_1408d21c0(int nIndex, CStringW strDefault);   // the nIndex-th argument as a string (unit_140d1ae30: OpenWebPage)
    int FUN_1408d1fd0(int nIndex, int nDefault);   // the nIndex-th argument as a number (usercommandcli.h: Unk_CommandArgs)
    CStringW text;                  // +0x00
    ATL::CAtlArray<CStringW> args;  // +0x08
    ATL::CAtlMap<int, int> values;  // +0x28
};
MS2_CHECK_SIZE(ItemFunctionArgs, 0x70);

struct ItemFunction                 // <function name parameter ...>
{
    ItemFunction();                 // 0x140549e70
    ~ItemFunction();                // 0x140540d10
    int Load(Unk_140165cf0* pElem);
    bool FUN_14054a2b0(const ItemFunction* pOther);    // operator!=
    int FUN_14054a350();            // 0 when the parameter is malformed
    bool FUN_14054a3d0();           // has a name
    bool FUN_14054a410();           // has xml values
    int FUN_14054a460();            // the box (drop group) id an OpenItemBox* / SelectItemBox / OpenGachaBox opens
    CStringW name;                  // +0x00 (functionName)
    CStringW name2;                 // +0x08
    int arg0, arg1, arg2;           // +0x10
    int unknown1c;
    ItemFunctionArgs parameter;     // +0x20
    CXmlData xml;                   // +0x90
};
MS2_CHECK_SIZE(ItemFunction, 0xf0);
MS2_CHECK_OFFSET(ItemFunction, parameter, 0x20);
MS2_CHECK_OFFSET(ItemFunction, xml, 0x90);

class CItemData : public CPtred, public CValidData<CItemData>, public CObjectCount<CItemData> {
public:
    CItemData();             // 0x14053b510
    virtual ~CItemData();    // 0x14053b730
    bool Load(Unk_140165cf0* pElem);    // 0x14053b830 XML read
    bool Save(void* pParent);    // 0x14053be30 XML write
    bool FUN_14053c170(const CItemData* pOther);    // 0x14053c170 operator!=
    int FUN_14053c560();     // 0x14053c560 (uiitemenchantdialog.cpp)
    bool FUN_14053d510();    // 0x14053d510
    int FUN_14053c6f0();     // 0x14053c6f0
    int FUN_14053c510();     // 0x14053c510 return the item id (+0x20; sb4, clonecube)
    int FUN_14053fdb0();     // 0x14053fdb0 (ugccubepalette.cpp) required level, 0 when none
    bool FUN_14053cde0();    // 0x14053cde0 unique (non-stacking) item
    int FUN_14053dd30();     // 0x14053dd30 the id of the npc the item summons
    bool FUN_14053d6f0();    // 0x14053d6f0 UGC item
    bool FUN_14053cb80();    // 0x14053cb80
    CString FUN_14053fdd0(); // 0x14053fdd0 the item's display name
    // @ITEMDATA-MEMBERS-BEGIN (added by itemdata.cpp)
    void FUN_14053c4f0(int nId);    // 0x14053c4f0
    void FUN_14053c530();    // 0x14053c530
    int FUN_14053c5a0();    // 0x14053c5a0
    int FUN_14053c5c0();    // 0x14053c5c0
    int FUN_14053c5e0();    // 0x14053c5e0
    int FUN_14053c600();    // 0x14053c600
    int FUN_14053c620();    // 0x14053c620
    int FUN_14053c650();    // 0x14053c650
    int FUN_14053c670();    // 0x14053c670
    bool FUN_14053c6b0(int nStringTag);    // 0x14053c6b0
    bool FUN_14053c710();    // 0x14053c710
    bool FUN_14053c7c0();    // 0x14053c7c0
    bool FUN_14053c810();    // 0x14053c810
    bool FUN_14053c870();    // 0x14053c870
    bool FUN_14053c8b0();    // 0x14053c8b0
    int FUN_14053c8e0(int nJob);    // 0x14053c8e0
    int FUN_14053c940(int nGender);     // 0x14053c940 wearable by the gender
    int FUN_14053c9a0(unsigned short nLevel);    // 0x14053c9a0
    int FUN_14053c9e0(int nGender, int nB);    // 0x14053c9e0
    int FUN_14053cae0(int nGender, int nCategory);    // 0x14053cae0
    bool FUN_14053cb40();    // 0x14053cb40
    bool FUN_14053cbc0();    // 0x14053cbc0
    bool FUN_14053cc00();    // 0x14053cc00
    bool FUN_14053cc40();    // 0x14053cc40
    bool FUN_14053cc80();    // 0x14053cc80
    bool FUN_14053ccc0();    // 0x14053ccc0
    bool FUN_14053cd10();    // 0x14053cd10
    bool FUN_14053cd50();    // 0x14053cd50
    bool FUN_14053cd90();    // 0x14053cd90
    bool FUN_14053ce20();    // 0x14053ce20
    bool FUN_14053ce40();    // 0x14053ce40
    bool FUN_14053ce80();    // 0x14053ce80
    bool FUN_14053cf00();    // 0x14053cf00
    bool FUN_14053cf40();    // 0x14053cf40
    bool FUN_14053cf90();    // 0x14053cf90
    bool FUN_14053cfd0();    // 0x14053cfd0
    bool FUN_14053d020();    // 0x14053d020
    bool FUN_14053d070();    // 0x14053d070
    bool FUN_14053d0c0();    // 0x14053d0c0
    int FUN_14053d110();    // 0x14053d110
    bool FUN_14053d150();    // 0x14053d150
    bool FUN_14053d1f0();    // 0x14053d1f0
    bool FUN_14053d210();    // 0x14053d210
    bool FUN_14053d230();    // 0x14053d230
    bool FUN_14053d270();    // 0x14053d270
    bool FUN_14053d2b0();    // 0x14053d2b0
    bool FUN_14053d2f0();    // 0x14053d2f0
    bool FUN_14053d340();    // 0x14053d340
    bool FUN_14053d460();    // 0x14053d460
    bool FUN_14053d550();    // 0x14053d550
    bool FUN_14053d5c0();    // 0x14053d5c0
    bool FUN_14053d600();    // 0x14053d600
    int FUN_14053d640();    // 0x14053d640
    bool FUN_14053d660();    // 0x14053d660
    bool FUN_14053d740();    // 0x14053d740
    bool FUN_14053d760();    // 0x14053d760
    bool FUN_14053d7c0();    // 0x14053d7c0
    bool FUN_14053d800();    // 0x14053d800
    bool FUN_14053d840();    // 0x14053d840
    bool FUN_14053d880();    // 0x14053d880
    bool FUN_14053d8c0();    // 0x14053d8c0
    bool FUN_14053d900();    // 0x14053d900
    bool FUN_14053d940();    // 0x14053d940
    bool FUN_14053d990();    // 0x14053d990
    int FUN_14053d9d0();    // 0x14053d9d0
    bool FUN_14053da20();    // 0x14053da20
    bool FUN_14053dad0();    // 0x14053dad0
    int FUN_14053db80();    // 0x14053db80
    int FUN_14053dc20();    // 0x14053dc20
    unsigned short FUN_14053dc40();    // 0x14053dc40
    int FUN_14053dc60();    // 0x14053dc60
    int FUN_14053dc90();    // 0x14053dc90
    int FUN_14053dce0();    // 0x14053dce0
    int FUN_14053dd80();    // 0x14053dd80
    int FUN_14053ddb0();    // 0x14053ddb0
    int FUN_14053dde0();    // 0x14053dde0
    int FUN_14053de10();    // 0x14053de10
    int FUN_14053de40();    // 0x14053de40
    int FUN_14053de60();    // 0x14053de60
    int FUN_14053de80();    // 0x14053de80
    int FUN_14053dec0();    // 0x14053dec0
    int FUN_14053df20();    // 0x14053df20
    int FUN_14053df80();    // 0x14053df80
    bool FUN_14053dfd0(const CStringW& strName);    // 0x14053dfd0
    bool FUN_14053e010();    // 0x14053e010
    bool FUN_14053e070();    // 0x14053e070
    bool FUN_14053e0d0();    // 0x14053e0d0
    bool FUN_14053e130();    // 0x14053e130
    bool FUN_14053e170();    // 0x14053e170
    int FUN_14053e210();    // 0x14053e210
    int FUN_14053e260();    // 0x14053e260
    int FUN_14053e2b0(int nIndex);    // 0x14053e2b0
    int FUN_14053e310(int nIndex);    // 0x14053e310
    int FUN_14053e370();    // 0x14053e370
    int FUN_14053e3c0();    // 0x14053e3c0
    int FUN_14053e410();    // 0x14053e410
    bool FUN_14053e460();    // 0x14053e460
    int FUN_14053e530();    // 0x14053e530
    bool FUN_14053e670();    // 0x14053e670
    Unk_PayloadPtr<CItemExtraData> FUN_14053e6c0();    // 0x14053e6c0
    bool FUN_14053e8e0();    // 0x14053e8e0
    int FUN_14053e900();    // 0x14053e900
    bool FUN_14053e940();    // 0x14053e940
    int FUN_14053e9e0();    // 0x14053e9e0
    unsigned long long FUN_14053ea00(int nRank);    // 0x14053ea00
    void FUN_14053eb20();    // 0x14053eb20
    ItemModelData* FUN_14053eba0();    // 0x14053eba0
    int FUN_14053ec50();    // 0x14053ec50
    void FUN_14053ec70();    // 0x14053ec70
    CString FUN_14053eca0();    // 0x14053eca0
    bool FUN_14053ecf0();    // 0x14053ecf0 always true
    void FUN_14053ed00();    // 0x14053ed00
    int FUN_14053ef40();    // 0x14053ef40
    int FUN_14053ef80();    // 0x14053ef80
    int FUN_14053efd0();    // 0x14053efd0
    int FUN_14053eff0(int nType);    // 0x14053eff0
    int FUN_14053f080();    // 0x14053f080
    int FUN_14053f0a0();    // 0x14053f0a0
    int FUN_14053f0d0(int nRank);    // 0x14053f0d0
    int FUN_14053f390(int nBase, int nIdx);    // 0x14053f390
    double FUN_14053f430(int nSub);    // 0x14053f430
    double FUN_14053f4f0(int nIdx);    // 0x14053f4f0
    double FUN_14053f620(int nIdx);    // 0x14053f620
    bool FUN_14053f750(long long nParam);    // 0x14053f750
    int FUN_14053f7c0();    // 0x14053f7c0
    void FUN_14053fd90();    // 0x14053fd90
    // @ITEMDATA-MEMBERS-END

    int id;                  // +0x20
    int type;                // +0x24 <property type>
    int subtype;             // +0x28
    int iconCode;            // +0x2c
    int itemGroup;           // +0x30
    int skinType;            // +0x34
    int rank;                // +0x38
    int itemPreset;          // +0x3c <tool itemPreset>
    int originID;            // +0x40 <basic originID>
    int stringTag;           // +0x44 <basic stringTag> (looked up in the string tag table)
    int param1;              // +0x48
    int param2;              // +0x4c
    ItemSkill skill;         // +0x50 <skill skillID skillLevel>
    bool bPCBang;            // +0x58 <PCBang>
    int constantID;          // +0x5c <option constantID>
    int randomID;            // +0x60
    int optionLevel;         // +0x64 (default 1)
    int optionLevelFactor;   // +0x68
    ItemProperty property;   // +0x70 <property> block
    ItemMaterial material;   // +0x108 <material>
    ItemPeriod period;       // +0x110 <usePeriod ...>
    ItemLimit limit;         // +0x138 <limit ...>
    ItemInstallData install;  // +0x1a8 <install> (CItemData operator!= 0x14053c170 compares it with 0x140548aa0)
    ItemUccMesh cubeTextureName; // +0x208 <ucc mesh>, read by CNifCubeGuide::FUN_1410b0680
    ItemEffect effect;       // +0x210 <effect ...>
    ItemFusion fusion;       // +0x240 <fusion>
    ItemAdditionalEffect additionalEffect;  // +0x248 <AdditionalEffect>
    ItemFunction function;   // +0x290 <function ...>
    MS2Ptr<ItemModelData> model;     // +0x380
};
MS2_CHECK_SIZE(CItemData, 0x390);
MS2_CHECK_OFFSET(CItemData, property, 0x70);
MS2_CHECK_OFFSET(CItemData, install, 0x1a8);
MS2_CHECK_OFFSET(CItemData, cubeTextureName, 0x208);
MS2_CHECK_OFFSET(CItemData, function, 0x290);
MS2_CHECK_OFFSET(CItemData, model, 0x380);
