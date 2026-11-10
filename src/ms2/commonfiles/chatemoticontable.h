// chatemoticontable.h - the chat emoticon tables (RTTI names ChatEmoticonData, ChatEmoticonCategoryData,
// ChatEmoticonCachedData, CChatEmoticonTable). Loaded from Table/chatEmoticonCategory.xml (<chatEmoticonCategory id
// icon_path/>), chatEmoticon.xml (<chatEmoticon id category_id group_id image_path height width vspace/>) and
// stringChatEmoticon.xml (<key id name command/>), then validated (every emoticon names a known category).
// Header name assumed (the unit is commonfiles\chatemoticontable.cpp, 0x1401e5760-0x1401f7ee0); method and member names
// are inferred from the xml attributes and the asserts. Shared by UIChatEmoticonDialog and the chat emoticon client state.
#pragma once
#include <afx.h>
#include <list>
#include <map>
#include <typeinfo>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/os.h"

// One emoticon (<chatEmoticon>). RTTI ChatEmoticonData, 0x48 bytes, base CPtred; vftable 0x142cf12e8 (1 slot: dtor).
class ChatEmoticonData : public CPtred
{
public:
    ChatEmoticonData();                     // 0x1401e57f0
    virtual ~ChatEmoticonData();            // 0x1401e58a0

    unsigned int m_nId;                     // +0x18 "id" (the id map's key; logged as unsigned)
    unsigned int m_nGroupId;                // +0x1c "group_id" (the emoticon pack, see CChatEmoticonCli)
    CStringW m_strImagePath;                // +0x20 "image_path"
    int m_nCategoryId;                      // +0x28 "category_id"
    int m_nHeight;                          // +0x2c "height"
    int m_nWidth;                           // +0x30 "width"
    int m_nVSpace;                          // +0x34 "vspace" (default -3)
    CStringW m_strName;                     // +0x38 stringChatEmoticon "name"
    CStringW m_strCommand;                  // +0x40 stringChatEmoticon "command" (rewritten to ":{0}:")
};
MS2_CHECK_SIZE(ChatEmoticonData, 0x48);
MS2_CHECK_OFFSET(ChatEmoticonData, m_strImagePath, 0x20);
MS2_CHECK_OFFSET(ChatEmoticonData, m_nVSpace, 0x34);
MS2_CHECK_OFFSET(ChatEmoticonData, m_strCommand, 0x40);

typedef MS2Ptr<ChatEmoticonData> ChatEmoticonDataPtr;

// One category tab (<chatEmoticonCategory>). RTTI ChatEmoticonCategoryData, 0x28 bytes, base CPtred.
class ChatEmoticonCategoryData : public CPtred
{
public:
    ChatEmoticonCategoryData();             // 0x1401e5760
    virtual ~ChatEmoticonCategoryData();    // 0x1401e57b0

    int m_nId;                              // +0x18 "id"
    CStringW m_strIconPath;                 // +0x20 "icon_path"
};
MS2_CHECK_SIZE(ChatEmoticonCategoryData, 0x28);
MS2_CHECK_OFFSET(ChatEmoticonCategoryData, m_strIconPath, 0x20);

typedef MS2Ptr<ChatEmoticonCategoryData> ChatEmoticonCategoryDataPtr;

// The loaded set (value-initialised by CChatEmoticonTable::Load). RTTI ChatEmoticonCachedData, 0x68 bytes, base CPtred;
// the ctor (0x1401f0420) and dtor (0x1401f0950) are implicit.
class ChatEmoticonCachedData : public CPtred
{
public:
    typedef std::list<ChatEmoticonDataPtr> EmoticonList;
    typedef std::map<unsigned int, ChatEmoticonDataPtr> EmoticonMap;
    typedef std::map<int, ChatEmoticonCategoryDataPtr> CategoryMap;

    int Load();                                                 // 0x1401e5910 (0 = loaded and valid)
    int LoadEmoticons();                                        // 0x1401e5980 chatEmoticon.xml
    int LoadStrings();                                          // 0x1401e5f70 stringChatEmoticon.xml
    int LoadCategories();                                       // 0x1401e6570 chatEmoticonCategory.xml
    int Validate();                                             // 0x1401e6a40
    int ValidateEmoticon(ChatEmoticonDataPtr spEmoticon);       // 0x1401e6d70 its category exists
    int ValidateCategory(ChatEmoticonCategoryDataPtr spCategory);   // 0x1401e6ee0

    std::list<MS2Ptr<CCacheData> > m_caches;                    // +0x18 one per loaded xml (path, write time)
    EmoticonMap m_emoticons;                                    // +0x28 id -> emoticon
    CategoryMap m_categories;                                   // +0x38 id -> category
    std::map<int, EmoticonList> m_byGroup;                      // +0x48 group id -> its emoticons
    std::map<CStringW, EmoticonList> m_byCommand;               // +0x58 ":{0}:" command -> emoticons
};
MS2_CHECK_SIZE(ChatEmoticonCachedData, 0x68);
MS2_CHECK_OFFSET(ChatEmoticonCachedData, m_emoticons, 0x28);
MS2_CHECK_OFFSET(ChatEmoticonCachedData, m_byCommand, 0x58);

typedef MS2Ptr<ChatEmoticonCachedData> ChatEmoticonCachedDataPtr;

class CChatEmoticonTable;
CString ToCString(const char* psz, int nCodePage);         // narrows a string (the RTTI name in CheckInit)

// This instantiation stores the complete object pointer; DAT_143aac658 (getter FUN_1409eecd0).
template <> class TSingleton<CChatEmoticonTable>
{
public:
    TSingleton();                           // 0x1401ef7d0
    virtual ~TSingleton() { s_instance = 0; }   // 0x1401f0560
    static CChatEmoticonTable* s_instance;
    static CChatEmoticonTable* GetInstance();           // 0x1409eecd0
};

// The table. RTTI CChatEmoticonTable, 0x20 bytes: TSingleton +0 (vftable 0x142cf1328), CValidData +8 (0x142cf1338),
// the loaded data +0x10.
class CChatEmoticonTable : public TSingleton<CChatEmoticonTable>, public CValidData<CChatEmoticonTable>
{
public:
    CChatEmoticonTable();                   // 0x1401e6f70
    virtual ~CChatEmoticonTable();          // 0x1401e6fe0

    int Load();                                                     // 0x1401e7040 builds and swaps in a new cached set
    ChatEmoticonDataPtr GetEmoticon(unsigned int nEmoticonId);    // emoticon by id (null when missing)
    ChatEmoticonCategoryDataPtr GetCategory(int nCategoryId);     // category by id (null when missing)
    void GetEmoticonsByGroup(unsigned int nGroupId, std::list<ChatEmoticonDataPtr>* pOut);   // copy of the emoticons of a group
    void GetEmoticonsByCommand(const CStringW& strCommand, std::list<ChatEmoticonDataPtr>* pOut);   // emoticons of a ":cmd:"
    int FUN_1401e75b0(unsigned int nGroupId);                       // the group has emoticons
    ChatEmoticonCachedDataPtr GetCachedData();                      // the current cached set (reloaded when a file changed)

    // @0x1401f1ef0
    static void CheckInit()
    {
        if (!s_bInit)
        {
            CStringA msg;
            msg.Format("%s is not initialized", (const char*)ToCString(typeid(CChatEmoticonTable).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    // @0x1401f1fa0
    static void SetInit(bool bInit) { s_bInit = bInit; }

    static bool s_bInit;                    // DAT_143aac660

    ChatEmoticonCachedDataPtr m_spData;     // +0x10
};
MS2_CHECK_SIZE(CChatEmoticonTable, 0x20);
MS2_CHECK_OFFSET(CChatEmoticonTable, m_spData, 0x10);
