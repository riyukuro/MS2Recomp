// itemdata.h - the item table row (CItemData, see ms2/placeholder/citemdata.h) and the types that share its unit:
// CItemChangeBeautyTable / CChangeBeautyData (Table/ItemChangeBeauty.xml), DropNifData, ItemDropEffect, ItemColorEx.
// Header name assumed; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <vector>
#include <efd/Point3.h>
#include <NiPoint3.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/itemcustom.h"
#include "ms2/placeholder/characterdecaldata.h"

class Unk_140165cf0;    // game TinyXML element (declared where the loaders are)
class ItemCustom;

// One <beauty> row of ItemChangeBeauty.xml (0x50 bytes; vftable has the deleting dtor only).
class CChangeBeautyData : public CPtred
{
public:
    CChangeBeautyData();                // 0x140539f90
    virtual ~CChangeBeautyData();       // 0x14053a130

    bool FUN_14053a7c0(Unk_140165cf0*); // row reader (always true; the <item> children are only validated by the loader)

    int m_nId;                          // +0x18 "id"
    int m_nUnk1c;                       // +0x1c
    std::vector<unsigned> m_lists[2];   // +0x20
};
MS2_CHECK_SIZE(CChangeBeautyData, 0x50);
MS2_CHECK_OFFSET(CChangeBeautyData, m_lists, 0x20);

// RTTI CItemChangeBeautyTable, 0xa8 bytes: TSingleton at +0, CValidData at +8.
class CItemChangeBeautyTable : public TSingleton<CItemChangeBeautyTable>, public CValidData<CItemChangeBeautyTable>
{
public:
    typedef MS2Ptr<CChangeBeautyData> DataPtr;
    typedef MS2Ptr<CCacheData> CachePtr;
    typedef ATL::CAtlMap<int, DataPtr> DataMap;

    CItemChangeBeautyTable();           // 0x140539370
    virtual ~CItemChangeBeautyTable();  // 0x140539430

    bool Load();                        // 0x1405394c0 Table/ItemChangeBeauty.xml
    DataPtr Get(int nId);               // 0x140539b70 reloads first when the file changed
    bool Reload();                      // 0x140539c70

    static void CheckInit();            // 0x14053a3f0
    static void SetInit(bool b);        // 0x14053b310

    static bool s_bInit;                // 0x143aaf3c0

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;        // +0x10
    ATL::CAtlArray<CachePtr> m_caches;  // +0x40
    DataMap m_data;                     // +0x60
};
MS2_CHECK_SIZE(CItemChangeBeautyTable, 0xa8);
MS2_CHECK_OFFSET(CItemChangeBeautyTable, m_lock, 0x10);
MS2_CHECK_OFFSET(CItemChangeBeautyTable, m_caches, 0x40);
MS2_CHECK_OFFSET(CItemChangeBeautyTable, m_data, 0x60);

// ---- The model block of an item row (RTTI ItemModelData, 0xe0 bytes; its constructor and accessors are in
// commonfiles\itemdatastruct.cpp, the destructor and the destructors of its element types here).
// Names of the element types are invented; member names are the XML attribute names their readers use
// (commonfiles\itemdatastruct.cpp).

struct ModelNameEntry               // <dummy> element of an <asset>, 0x38 bytes (ctor 0x1403142a0 and reader 0x140314350 elsewhere)
{
    ModelNameEntry();               // 0x1403142a0
    // implicit dtor (COMDAT 0x140540bc0 in itemdata.cpp) and moves: no user-declared dtor
    void FUN_140314350(Unk_140165cf0* pElem);       // XML read
    int gender;                     // +0x00 "gender": 0, 1 or 2 (both lists; the ctor's default)
    CString sequence;               // +0x08 "sequence"
    CString targetNode;             // +0x10 "targetnode" (the part's target node when empty)
    efd::Point3 rotation;           // +0x18 "rotation"
    efd::Point3 translation;        // +0x24 "translation"
    float step;                     // +0x30 "step"
    bool worldMode;                 // +0x34 "worldmode"
    bool worldLerp;                 // +0x35 "worldlerp"
};
MS2_CHECK_SIZE(ModelNameEntry, 0x38);

struct ModelFloatList               // <scale> element, 0x28 bytes
{
    ModelFloatList();               // 0x140544b10
    // implicit dtor (COMDAT 0x140541080 in itemdata.cpp) and moves: no user-declared dtor
    int Load(Unk_140165cf0* pElem);        // XML read
    int FUN_140544c00(void* pParent);            // XML write (nothing)
    float FUN_140544c20() const;    // a random entry of values, 1.0 when empty
    float maxValue;                 // +0x00 "max" (default 1.0)
    float minValue;                 // +0x04 "min"
    int reverse;                    // +0x08 "reverse"
    std::vector<float> values;      // +0x10 "value"
};
MS2_CHECK_SIZE(ModelFloatList, 0x28);

struct ModelNamedColor              // <jointangle> element, 0x18 bytes, four of them in a ModelPart
{
    ModelNamedColor();              // 0x140543a30
    // implicit dtor (COMDAT 0x140541060 in itemdata.cpp) and moves: no user-declared dtor
    CString name;                   // +0x00 "name"
    float soft;                     // +0x08 "soft" (default 0.01)
    float posz;                     // +0x0c "posz"
    float zero;                     // +0x10 "zero"
    float negz;                     // +0x14 "negz"
};
MS2_CHECK_SIZE(ModelNamedColor, 0x18);

struct ModelPart                    // <asset> element, 0x158 bytes
{
    ModelPart();                    // 0x140543a90
    // implicit dtor (COMDAT 0x140540f60 in itemdata.cpp) and moves: no user-declared dtor
    int Load(Unk_140165cf0* pElem);        // XML read
    int FUN_140544a80(void* pParent);            // XML write (nothing)
    int FUN_140544aa0(int nGender, int nWeapon) const;   // the part is worn by the gender / weapon
    CString name0;                  // +0x00 "name"
    CString name8;                  // +0x08 "selfnode"
    CString name10;                 // +0x10 "targetnode"
    CString name18;                 // +0x18 "attachnode"
    int isNif;                      // +0x20 the name ends in ".nif" (otherwise an animation urn)
    int pony;                       // +0x24 "pony"
    unsigned zalign;                // +0x28 "zalign"
    int replace;                    // +0x2c "replace"
    int earfold;                    // +0x30 "earfold"
    int ani;                        // +0x34 "ani"
    int emotionhide;                // +0x38 "emotionhide"
    unsigned gender;                // +0x3c "gender" (default 2 = both)
    float capscale;                 // +0x40 "capscale" (default 1.0)
    float mantlescale;              // +0x44 "mantlescale" (default 1.0)
    int ponyIndex;                  // +0x48 running index of the pony parts of a group
    int weapon;                     // +0x4c "weapon"
    int placeable;                  // +0x50 "placeable"
    std::vector<MS2Ptr<ItemCustom> > customs;   // +0x58 <custom> children
    efd::Point3 rotationMin;        // +0x70 <userrotation axis> "min"
    efd::Point3 rotationMax;        // +0x7c <userrotation axis> "max"
    std::vector<efd::Point3> points;    // +0x88 <userrotation axis> "default" lists
    std::vector<CString> names;     // +0xa0 <physx action>
    ModelNamedColor colors[4];      // +0xb8 <jointangle>
    std::map<CString, CString> properties;  // +0x118 "capHair" values keyed "B", "C", ...
    std::vector<ModelNameEntry> entries[2]; // +0x128 <dummy>
};
MS2_CHECK_SIZE(ModelPart, 0x158);
MS2_CHECK_OFFSET(ModelPart, customs, 0x58);
MS2_CHECK_OFFSET(ModelPart, points, 0x88);
MS2_CHECK_OFFSET(ModelPart, colors, 0xb8);
MS2_CHECK_OFFSET(ModelPart, properties, 0x118);
MS2_CHECK_OFFSET(ModelPart, entries, 0x128);

struct ModelGroup                   // 0x38 bytes (also the unit's third static, 0x143aaf568)
{
    ModelGroup();                   // 0x140544ca0
    // implicit dtor (COMDAT 0x140540f30 in itemdata.cpp) and moves: no user-declared dtor
    void FUN_140544cf0(Unk_140165cf0* pElem);       // XML read
    void FUN_140544f00(void* pParent);           // XML write (nothing)
    const ModelFloatList* FUN_140544f20(size_t nIndex) const;   // the nIndex-th scale list (a static default when out of range)
    const ModelPart* FUN_140544fe0(size_t nIndex) const;  // the nIndex-th part (a static default when out of range)
    size_t FUN_140545090() const;       // number of scale lists
    size_t FUN_1405450c0() const;       // number of parts
    float FUN_1405450f0(int nIndex) const;              // a random value of the nIndex-th scale list
    void FUN_140545130(const CString& strName);     // renames every part
    int FUN_1405451a0() const;     // type
    std::vector<ModelPart> parts;   // +0x00
    std::vector<ModelFloatList> floats; // +0x18
    int type;                       // +0x30 "name"
};
MS2_CHECK_SIZE(ModelGroup, 0x38);

// RTTI MsTransform (0x38): the <capTransform> of an item's <customize> block (ctor and readers in
// commonfiles\itemdatastruct.cpp; the implicit dtor 0x140552590 and ??_G 0x140552c20 are COMDATs there).
class MsTransform : public CPtred
{
public:
    MsTransform();                  // 0x140546860
    void FUN_1405468d0(Unk_140165cf0* pElem);       // XML read
    void FUN_140546940(void* pElem);                // XML write
    NiPoint3 position;              // +0x18 (NiPoint3() COMDAT 0x1405522f0)
    NiPoint3 rotation;              // +0x24
    float scale;                    // +0x30 (default 1.0)
};
MS2_CHECK_SIZE(MsTransform, 0x38);

struct ItemModelHead                // <customize> block, 0x50 bytes at ItemModelData +0x48
{
    ItemModelHead();                // 0x140546a00
    ~ItemModelHead();               // 0x140540c70
    int Load(Unk_140165cf0* pElem);        // XML read
    int Save(void* pParent);               // XML write
    bool FUN_140547130();           // scale
    bool FUN_140547150();           // rotation
    bool FUN_140547170();           // translation
    bool FUN_140547190();           // flag at +0x10
    bool FUN_1405471b0();           // capAttach
    bool FUN_1405471d0();           // any of three flags
    bool FUN_140547230();           // more than one default colour
    int FUN_140547250();            // +0x14
    int FUN_140547270(int nIndex) const;    // the nIndex-th entry of the id list, -1 when out of range
    int FUN_1405472d0(int nIndex) const;    // the nIndex-th colour delay, 0 when out of range
    size_t FUN_140547330();         // size of the id list
    MsTransform* FUN_140547360();   // the cap transform (may be null)
    MS2Ptr<MsTransform> handle;     // +0x00 <capTransform>
    bool flag10;                    // +0x10 "color"
    bool flag11;                    // +0x11 more than one default colour index
    unsigned unknown14;             // +0x14 "colorPalette"
    std::vector<int> ids;           // +0x18 "defaultColorIndex"
    std::vector<int> unknown30;     // +0x30 "colorDelay"
    bool scale;                     // +0x48 "scale"
    bool rotation;                  // +0x49 "rotation"
    bool translation;               // +0x4a "translation"
    bool capAttach;                 // +0x4b "capAttach"
    int unknown4c;
};
MS2_CHECK_SIZE(ItemModelHead, 0x50);

class ItemModelData : public CCacheData
{
public:
    ItemModelData();                // 0x14054ae00
    virtual ~ItemModelData();       // 0x140540e20
    static unsigned FUN_14054aec0(unsigned nId);    // nId / 100000
    void FUN_14054aee0(int n);      // m_nUnk28 = n
    void FUN_14054af00(Unk_140165cf0* pElem);       // XML read
    void FUN_14054b230(void* pParent);           // XML write (nothing)
    void FUN_14054b250(const CString& strName);     // renames every part of every group
    std::vector<CString>* FUN_14054b2c0(int nGender);   // the <cutting> names of a gender
    const ModelGroup* FUN_14054b2f0(size_t nIndex) const;       // the nIndex-th group (a static empty one when out of range)
    int FUN_14054b3b0();            // m_nUnk28
    size_t FUN_14054b3d0();         // number of groups
    int FUN_14054b400() const;      // type of the first group, 0 when none
    bool FUN_14054b450(int nType) const;    // a group has the type (type 19 stands for 4 and 5)
    bool FUN_14054b520();
    bool FUN_14054b550();
    int FUN_14054b580();
    int FUN_14054b5b0(int nIndex);
    int FUN_14054b5e0(int nIndex);
    size_t FUN_14054b610();
    bool FUN_14054b640();
    ItemModelHead* FUN_14054b670(); // &head
    ItemModelHead* FUN_14054b690(); // &head
    CharacterDecalData* FUN_14054b6b0();            // the decal block (may be null)
    CStringW FUN_14054b6e0();       // name
    int m_nUnk28;                   // +0x28
    std::vector<ModelGroup> groups; // +0x30
    ItemModelHead head;             // +0x48
    std::vector<CString> names98;   // +0x98
    std::vector<CString> namesB0;   // +0xb0
    MS2Ptr<CharacterDecalData> resource;     // +0xc8
    CStringW name;                  // +0xd8
};
MS2_CHECK_SIZE(ItemModelData, 0xe0);
MS2_CHECK_OFFSET(ItemModelData, groups, 0x30);
MS2_CHECK_OFFSET(ItemModelData, head, 0x48);
MS2_CHECK_OFFSET(ItemModelData, resource, 0xc8);

// <drop> rows of the item drop table: three small CPtred-derived records (destructors in itemdatastruct.cpp).
class DropNifData : public CPtred   // 0x20 bytes
{
public:
    DropNifData();                  // 0x1405434a0
    virtual ~DropNifData() = default;   // COMDAT 0x140552480 (no vptr store)
    void FUN_1405434f0(Unk_140165cf0* pElem);   // XML read
    bool FUN_140543550(unsigned n); // m_nUnk1c <= n
    int FUN_140543590();            // type id
    int m_nTypeId;                  // +0x18 "typeID"
    unsigned m_nUnk1c;              // +0x1c
};
MS2_CHECK_SIZE(DropNifData, 0x20);

class ItemDropEffect : public CPtred    // 0x88 bytes
{
public:
    ItemDropEffect();               // 0x1405435b0
    virtual ~ItemDropEffect() = default;    // COMDAT 0x1405524c0 (no vptr store)
    void Load(Unk_140165cf0* pElem);   // XML read
    int typeID;                     // +0x18
    float unknown1c;                // +0x1c (default 50.0)
    float scale;                    // +0x20
    float getAniSpeed;              // +0x24
    float dropAniSpeed;             // +0x28
    float beAniSpeed;               // +0x2c
    float shadowBias;               // +0x30
    float shadowScale;              // +0x34
    float bounceHeight;             // +0x38 (default 30.0)
    float bouncePeriod;             // +0x3c
    efd::Point3 getAni;             // +0x40
    efd::Point3 dropAni;            // +0x4c
    efd::Point3 beAni;              // +0x58
    int unknown64;
    CString beEffect;               // +0x68
    CString assetName;              // +0x70
    CString dropSoundID;            // +0x78
    CString getSoundID;             // +0x80
};
MS2_CHECK_SIZE(ItemDropEffect, 0x88);

class ItemColorEx : public CPtred   // 0x48 bytes
{
public:
    ItemColorEx(const int& nId);    // 0x140543940
    virtual ~ItemColorEx() = default;   // COMDAT 0x1405524a0 (no vptr store)
    int m_nId;                      // +0x18
    int m_nColor;                   // +0x1c (default -1)
    bool m_bFlag;                   // +0x20
    int m_n24, m_n28, m_n2c, m_n30, m_n34, m_n38;
    int m_aValues[3];               // +0x3c
};
MS2_CHECK_SIZE(ItemColorEx, 0x48);
