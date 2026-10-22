// cstringtable.h - CStringTable (RTTI .?AVCStringTable@@, 0x2a0 bytes): the string.xml tables and the item / skill
// description tables every UI reads. NOT an original header (the member names are invented); recovered in
// client\ms2\stringtable.cpp, which defines everything declared here.
// Bases: TSingleton<CStringTable> at +0x0, CValidData<CStringTable> at +0x8.
//
// string.xml ("Table\string.xml") lists the tables: <key id=".." name="<file>" parser=".." parserValue="..">. A table
// is a CStringCache: its <name>.xml files are read lazily (on the first lookup, or when the file changed) into
// id -> text. The description tables (korItemDescription.xml, stringSkillDescription.xml, SetItemName.xml,
// UGCMapSetItemName.xml, stringAdditionalDescription.xml) hold per id a CDesc (name/mainDescription/... -> text).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

class Unk_140165cf0;
class CStringTable : public TSingleton<CStringTable>, public CValidData<CStringTable>
{
public:
    // One string table: ids -> text, loaded from the files in m_files.
    class CStringCache : public CPtred
    {
    public:
        CString m_strParser;                                // +0x18 "parser" ("raceName", "customValue", ...)
        CString m_strParserValue;                           // +0x20 "parserValue"
        ATL::CRBMap<DWORD, CStringW> m_strings;             // +0x28
        CLockCriticalSection m_lock;                        // +0x58
        ATL::CAtlList<MS2Ptr<CCacheData> > m_files;         // +0x88 the xml files and their load stamps

        void FUN_1418176e0(CString strFile);                // adds an xml file (a Table path) to m_files
        int FUN_141819280();                                // a file changed on disk since it was loaded
    };

    // The texts of one description row, by tag name ("name", "mainDescription", ...).
    class CDesc : public CPtred
    {
    public:
        class DescValue : public CPtred
        {
        public:
            DescValue();                                    // 0x141816a60
            int m_bPending;                                 // +0x18 the text still has to be checked for "$"
            CStringW m_strText;                             // +0x20
        };
        typedef MS2Ptr<DescValue> ValuePtr;
        typedef ATL::CRBMap<CString, ValuePtr> ValueMap;

        CStringW FUN_141813a30(const CString& strTag);             // the text of a tag (checks the "$" marker once)
        void FUN_141813b80(const CString& strTag, const CStringW& strText);    // adds a tag

        ValueMap m_values;                                  // +0x18
    };

    // The rows of one id by level: level -> CDesc, a lookup uses the highest level not above the wanted one.
    class CLevelDesc : public CPtred
    {
    public:
        typedef MS2Ptr<CDesc> DescPtr;
        typedef ATL::CRBMap<unsigned short, DescPtr> LevelMap;
        LevelMap m_levels;                                  // +0x18
    };

    typedef MS2Ptr<CStringCache> CachePtr;
    typedef MS2Ptr<CDesc> DescPtr;
    typedef MS2Ptr<CLevelDesc> LevelDescPtr;
    typedef ATL::CAtlMap<int, CachePtr> CacheMap;
    typedef ATL::CAtlMap<int, DescPtr> DescMap;
    typedef ATL::CAtlMap<int, LevelDescPtr> LevelDescMap;

    CStringTable();                                         // 0x141810bf0
    virtual ~CStringTable();

    bool Load();                                   // reads string.xml and the description files
    bool FUN_141811960();                                   // reload
    CStringW FUN_141811980(int nTable, int nId);            // the string of a table row
    CStringW GetItemDescription(int nItemId, CString strTag);    // an item description
    CStringW GetSkillDescription(int nSkillId, unsigned short nLevel, CString strTag);    // a skill description
    CStringW FUN_141812290(int nBuffId, unsigned short nLevel, CString strTag);     // a leveled description
    CStringW FUN_1418125b0(int nId);                        // a name (npc / pet / map etc. by id range)
    CStringW GetSetItemName(int nSetId, CString strTag);     // a set item name
    CStringW GetUGCMapSetItemName(int nSetId, CString strTag);     // an UGC map set item name
    int FUN_141812c40(int nTable, const CStringW& strName); // the id whose text is strName (-1: none)
    CStringW FUN_141812ec0(int n);
    CStringW FUN_141812f60(int nItemId);                    // the name of an item's string id
    CStringW FUN_141813060(int nRank, int nItemId);
    CStringW FUN_141813150(int nRank);                      // "s_word_rank_%02d"
    CStringW FUN_141813200(__int64 nItemUid);
    CStringW FUN_141813300(int nTab);                       // an inventory tab name
    CStringW FUN_141813610(int a, int b, int c);
    CStringW FUN_141813790(CStringW strFormat, CStringW strArgs);   // formats the text with ','-separated arguments
    void FUN_141813970(Unk_140165cf0* pRoot);               // item descriptions
    void FUN_1418139b0(Unk_140165cf0* pRoot);               // level descriptions
    void FUN_1418139f0(Unk_140165cf0* pRoot);               // skill descriptions
    int FUN_141813c80(CachePtr spCache, CString strParser, CString strParserValue);   // loads a table's files
    int FUN_141813e70(CachePtr spCache);                    // ... with the "name" attribute
    int FUN_141813f10(CachePtr spCache);                    // ... "raceName"
    int FUN_141814310(CachePtr spCache, CString strAttr);   // ... any attribute
    int FUN_141814750(CString strFile, DescMap& rMap, CCacheData& rCache);
    int FUN_141814a20(CString strFile, DescMap& rMap, CCacheData& rCache, ATL::CAtlArray<CString>& rTags);
    int FUN_141814cf0(LevelDescMap& rMap, CachePtr spCache);
    CStringW FUN_141815160(LevelDescMap& rMap, int* pnId, unsigned short* pnLevel, const CString& strTag);
    CStringW FUN_141815330(LevelDescPtr& spLevels, unsigned short* pnLevel, const CString& strTag);
    DescPtr FUN_1418154e0(Unk_140165cf0* pNode);            // a description row of the item tags
    DescPtr FUN_141815650(Unk_140165cf0* pNode, ATL::CAtlArray<CString>& rTags);
    DescPtr FUN_1418158b0(Unk_140165cf0* pNode);            // a description row of the skill tags
    void FUN_141815a20(DescMap& rMap, Unk_140165cf0* pRoot);
    void FUN_141815b30(LevelDescMap& rMap, Unk_140165cf0* pRoot);

    static void CheckInit();                                // 0x1418178d0 message box when the tables are not loaded
    static void SetInit(bool b);                            // 0x14181c6c0
    static bool s_bInit;                                    // 0x143aef008

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x10
    CacheMap m_caches;                                      // +0x40 table id -> table
    DescMap m_itemDescs;                                    // +0x88 korItemDescription.xml
    DescMap m_skillDescs;                                   // +0xd0 stringSkillDescription.xml
    LevelDescMap m_levelDescs;                              // +0x118 stringAdditionalDescription.xml
    DescMap m_setItemNames;                                 // +0x160 SetItemName.xml
    CCacheData m_itemDescStamp;                             // +0x1a8
    CCacheData m_skillDescStamp;                            // +0x1d0
    CachePtr m_spAdditional;                                // +0x1f8 the stringAdditionalDescription.xml table
    CCacheData m_setItemNameStamp;                          // +0x208
    DescMap m_ugcSetItemNames;                              // +0x230 UGCMapSetItemName.xml
    CCacheData m_ugcSetItemNameStamp;                       // +0x278
};
MS2_CHECK_SIZE(CStringTable, 0x2a0);
