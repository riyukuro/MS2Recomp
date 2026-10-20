// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed from the unit path
// (client\ms2\emotiondata.cpp, 0x1411bcb50-0x1411c5780).
//
// The character emotion library (Data/xml/Emotion/<Item|Npc>/<id>.xml and the shared groups in
// Data/xml/Emotion/Common/<name>.xml):
//   CEmotionData        one <emotion> (animations, face, texture animation, effect files);
//   CEmotionGroup       the emotions of one model, by name;
//   CEmotionGroupImport a model file that <import>s a common group and only adds an item code;
//   CEmotionTable       one library (Item or Npc): the groups by model id and the common groups by name, with the
//                       file caches used for hot reload (the class name is from the log text
//                       "NotFound CEmotionTable::ReadEmotionGroup Import");
//   CEmotionManager     the singleton holding the Item and Npc libraries (created by CMainSystem).
// RTTI names: CEmotionData, CEmotionGroup, CEmotionGroupImport, CEmotionManager. Member and method names are
// invented from the xml attributes, the log texts and the call sites (VAs in the comments).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>
#include <typeinfo>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"                     // TSingleton
#include "ms2/placeholder/ascript.h"                // MS2Ptr
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/client/ms2/textureanimationdata.h"

class Unk_140165cf0;     // game TinyXML element

// One <emotion name faceName equiphide isTool> element. RTTI CEmotionData, 0x90 bytes (operator new 0x1411bd5c0),
// vftable 0x142ebce30 (one slot: the dtor).
class CEmotionData : public CPtred
{
public:
    CEmotionData();                                         // 0x1411bcb50
    virtual ~CEmotionData();                                // 0x1411bcc20 (??_G 0x1411c02d0)
    bool Load(Unk_140165cf0* pNode);                        // 0x1411bccd0 false: no name or not enabled
    CString GetAnimation(int nIndex);                       // 0x1411bd0c0 "" outside 0..4
    void LoadTexture(CString strDir);                       // 0x1411bd150 load the texture animation frames
    void CheckResources(CString strDir);                    // 0x1411bd1c0 log missing effect / texture files
    bool IsTool();                                          // 0x1411bd530

    CString m_strFaceName;                                  // +0x18 "faceName"
    CString m_strName;                                      // +0x20 "name" (the key in the group)
    bool m_bEquipHide;                                      // +0x28 "equiphide"
    MS2Ptr<CTextureAnimationData> m_spTextureAni;           // +0x30 <textureani>
    ATL::CAtlArray<CString> m_effects;                      // +0x40 <effect file>
    bool m_bTool;                                           // +0x60 "isTool"
    CString m_anims[5];                                     // +0x68 <anim name>, <idleAnim name>, <boreAnim name> (up to 3, ',')
};
MS2_CHECK_SIZE(CEmotionData, 0x90);
MS2_CHECK_OFFSET(CEmotionData, m_spTextureAni, 0x30);
MS2_CHECK_OFFSET(CEmotionData, m_effects, 0x40);
MS2_CHECK_OFFSET(CEmotionData, m_bTool, 0x60);
MS2_CHECK_OFFSET(CEmotionData, m_anims, 0x68);

typedef ATL::CAtlMap<CString, MS2Ptr<CEmotionData>, ATL::CStringElementTraitsI<CString> > CEmotionDataMap;

// The emotions of one model. RTTI CEmotionGroup, 0x60 bytes, vftable 0x142ebce40 (4 slots). The dtor is implicit
// (0x1411bfd80, no vptr store).
class CEmotionGroup : public CPtred
{
public:
    CEmotionGroup();                                        // 0x1411bd550
    void Load(Unk_140165cf0* pRoot);                        // 0x1411bd5c0 the <emotion> list of <ms2>
    void LoadTextures(const CString& strDir);               // 0x1411bd710
    void CheckResources();                                  // 0x1411bd7e0
    virtual CString GetItemCode();                          //  1 0x1411bd8d0 "" (the import's item code)
    virtual MS2Ptr<CEmotionData> Find(const CString& strName);  //  2 0x1411bd920 null when missing
    virtual void GetNames(std::vector<CString>& names);     //  3 0x1411bd9e0

    CEmotionDataMap m_emotions;                             // +0x18 name -> emotion
};
MS2_CHECK_SIZE(CEmotionGroup, 0x60);
MS2_CHECK_OFFSET(CEmotionGroup, m_emotions, 0x18);

// <import name itemCode>: the group of a common file plus an item code. RTTI CEmotionGroupImport, 0x78 bytes,
// vftable 0x142ebce68. Implicit dtor (0x1411bfdb0).
class CEmotionGroupImport : public CEmotionGroup
{
public:
    CEmotionGroupImport(MS2Ptr<CEmotionGroup> spGroup, CString strItemCode);   // 0x1411bdaa0
    virtual CString GetItemCode();                          //  1 0x1411bdb30
    virtual MS2Ptr<CEmotionData> Find(const CString& strName);  //  2 0x1411bdb80
    virtual void GetNames(std::vector<CString>& names);     //  3 0x1411bdbf0

    MS2Ptr<CEmotionGroup> m_spGroup;                        // +0x60 the imported common group
    CString m_strItemCode;                                  // +0x70 "itemCode"
};
MS2_CHECK_SIZE(CEmotionGroupImport, 0x78);
MS2_CHECK_OFFSET(CEmotionGroupImport, m_spGroup, 0x60);

typedef ATL::CAtlMap<CString, MS2Ptr<CEmotionGroup>, ATL::CStringElementTraitsI<CString> > CEmotionGroupNameMap;
typedef ATL::CAtlMap<unsigned int, MS2Ptr<CEmotionGroup> > CEmotionGroupIdMap;
typedef ATL::CAtlMap<unsigned int, MS2Ptr<CCacheData> > CEmotionIdCacheMap;
typedef ATL::CAtlMap<CString, MS2Ptr<CCacheData>, ATL::CStringElementTraitsI<CString> > CEmotionNameCacheMap;

// One emotion library (no vftable, 0x158 bytes; CEmotionManager +0x10 "Item", +0x168 "Npc").
class CEmotionTable
{
public:
    CEmotionTable(const CString& strType);                  // 0x1411bdc40
    ~CEmotionTable();                                       // 0x1411bdd90
    MS2Ptr<CEmotionGroup> GetGroup(unsigned int nId);       // 0x1411bde10 (re)reads <type>/<id>.xml when needed
    void LoadCommon();                                      // 0x1411bdf80 Data/xml/Emotion/Common/*.xml
    void LoadAll();                                         // 0x1411be330 Data/xml/Emotion/<type>/*.xml
    void LoadTextures(unsigned int nId, CString strDir);    // 0x1411be510
    void CheckResources(unsigned int nId);                  // 0x1411be590
    MS2Ptr<CEmotionGroup> ReadEmotionGroup(unsigned int nId);   // 0x1411be610
    MS2Ptr<CEmotionGroup> GetCommonGroup(const CString& strName);   // 0x1411beb50
    bool IsIdCacheChanged(unsigned int nId);                // 0x1411bec20 no cache or file changed
    bool IsNameCacheChanged(const CString& strName);        // 0x1411bece0
    void AddIdCache(unsigned int nId, const CString& strPath);      // 0x1411beda0
    void AddNameCache(const CString& strName, const CString& strPath);  // 0x1411beed0

    CEmotionGroupNameMap m_commonGroups;                    // +0x00 common file name -> group
    CLockCriticalSection m_lock;                            // +0x48
    CEmotionGroupIdMap m_groups;                            // +0x78 model id -> group
    CString m_strType;                                      // +0xc0 "Item" / "Npc"
    CEmotionIdCacheMap m_idCache;                           // +0xc8
    CEmotionNameCacheMap m_nameCache;                       // +0x110
};
MS2_CHECK_SIZE(CEmotionTable, 0x158);
MS2_CHECK_OFFSET(CEmotionTable, m_lock, 0x48);
MS2_CHECK_OFFSET(CEmotionTable, m_groups, 0x78);
MS2_CHECK_OFFSET(CEmotionTable, m_strType, 0xc0);
MS2_CHECK_OFFSET(CEmotionTable, m_idCache, 0xc8);
MS2_CHECK_OFFSET(CEmotionTable, m_nameCache, 0x110);

CString FUN_14016a5c0(const char* psz, int nCodePage);     // narrows a string (the RTTI name in CheckInit)

// RTTI CEmotionManager, 0x2c0 bytes. Bases: TSingleton<CEmotionManager> at +0x0 (s_instance DAT_143ab6dc8, vftable
// 0x142ebceb0), CValidData<CEmotionManager> at +0x8 (vftable 0x142ebcec0).
class CEmotionManager : public TSingleton<CEmotionManager>, public CValidData<CEmotionManager>
{
public:
    CEmotionManager();                                      // 0x1411bf010
    virtual ~CEmotionManager();                             // 0x1411bf100 (??_G 0x1411c0390)
    void Init();                                            // 0x1411bf180
    CEmotionTable* GetItemTable();                          // 0x1411bf1b0
    CEmotionTable* GetNpcTable();                           // 0x1411bf1e0
    // @0x1411c0570
    static void CheckInit()
    {
        if (!s_bInit)
        {
            CStringA msg;
            msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CEmotionManager).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    // @0x1411c4fe0
    static void SetInit(bool bInit) { s_bInit = bInit; }
    static bool s_bInit;                                    // DAT_143ad1ae9

    CEmotionTable m_itemTable;                              // +0x10 "Item"
    CEmotionTable m_npcTable;                               // +0x168 "Npc"
};
MS2_CHECK_SIZE(CEmotionManager, 0x2c0);
MS2_CHECK_OFFSET(CEmotionManager, m_itemTable, 0x10);
MS2_CHECK_OFFSET(CEmotionManager, m_npcTable, 0x168);
