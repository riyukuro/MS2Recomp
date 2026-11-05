// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uidungeoncategory.h.
// MS2-UNIT: ?\uidungeoncategory.cpp
// MS2-RANGE: 0x1400cbbb0-0x1400cbd20 .text$di
// MS2-RANGE: 0x140c08990-0x140c0ec90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: memmove_s 0x140c0ad80 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIDungeonControlCenter@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x140c0e290 ; unique
// MS2-PIN: ??C?$MS2Ptr@VDungeonRecordManagerCli@@@@QEBAPEAVDungeonRecordManagerCli@@XZ 0x140c0e5d0 ; unique
// MS2-PIN: ?vfunc_48@UIDungeonControlCenter@@UEAAHXZ 0x140c0e760 ; unique
// MS2-PIN: ?_Swap_all@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXAEAV12@@Z 0x140c0e870 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIDungeonControlCenter@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c0e990 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDungeonControlCenter@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x140c0eaa0 ; unique
// MS2-PIN: ??$Call@VUIDungeonControlCenter@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIDungeonControlCenter@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIDungeonControlCenter@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x140c0ead0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDungeonControlCenter@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c0eb10 ; unique
// MS2-PIN: ?swap@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXAEAV12@@Z 0x140c0eb70 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7UIDungeonCategoryTable@@6B?$TSingleton@VUIDungeonCategoryTable@@@@@ 0x142dfb1e0
// MS2-PIN: ??_7UIDungeonCategoryTable@@6B?$CValidData@VUIDungeonCategoryTable@@@@@ 0x142dfb1f0
// MS2-PIN: ??1?$MS2Ptr@VDungeonRecordManagerCli@@@@QEAA@XZ 0x140c0e410
// MS2-PIN: ?Release@?$MS2Ptr@VDungeonRecordManagerCli@@@@AEAAXXZ 0x140c0e7e0
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VDungeonRecordManagerCli@@@@AEAAXPEAX@Z 0x140c0e820
// MS2-PIN: ?Reference@?$MS2Ptr@VDungeonRecordManagerCli@@@@CAXPEAVDungeonRecordManagerCli@@@Z 0x140c0e7b0
// MS2-PIN: ?get@?$MS2Ptr@VDungeonUnitedWeeklyReward@@@@QEBAPEAVDungeonUnitedWeeklyReward@@XZ 0x140c0e5c0
// MS2-PIN: ?empty@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@QEBA_NXZ 0x140c0e9f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidungeoncategory.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uidungeoncategory.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uidungeonroomdialog.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include <map>
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/client/ms2/dungeonrecordcli.h"
#include "ms2/placeholder/cmycharacter.h"  // C3: CMyCharacter::GetRecord (0x140d9f2c0)
#include "ms2/commonfiles/rewardcontentstable.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/xmlattr.h"  // C3: XmlSplit was FUN_140177db0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- unit-local declarations (unrecovered callees; names describe their use) ----

// Table loading (same helpers as continentregiontable.cpp).
class Unk_DcXmlNode
{
public:
// C3 #8: dead FUN_140165cf0 / FUN_140168650 view removed (callers use Unk_XmlNode::FirstChild / NextSibling)
// C3 #8: dead FUN_140165cf0 / FUN_140168650 view removed (callers use Unk_XmlNode::FirstChild / NextSibling)
};
void FUN_1408731e0(Unk_DcXmlNode* pNode, const char* szName, int& n);
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
enum Unk_DungeonGroupType : int; template <class E> int XmlValueByName(TiXmlElement* pElem, const char* pszName, E& eOut); template <> int XmlValueByName(TiXmlElement*, const char*, Unk_DungeonGroupType&);   // 0x140179060, the enum attribute (specialization in additionalactionadditional.cpp)
bool FUN_14028f710(struct Unk_XmlElement* pNode);               // the element is enabled (feature/locale filter)
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
CString FUN_14016a5c0(const char* psz, int n);
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);

class Unk_140bccd50* FUN_140bccd50();   // the packet handler manager
COutputStream& FUN_14070f820(COutputStream& out, bool value);
COutputStream& FUN_14070f9a0(COutputStream& out, unsigned int value);

// The local player (slot 78 = level) and its manager.
class Unk_DcPlayer
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27();
    virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31();
    virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35();
    virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43();
    virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47();
    virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51();
    virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55();
    virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63();
    virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
    virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71();
    virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75();
    virtual void vfunc_76(); virtual void vfunc_77();
    virtual unsigned short vfunc_78();                          // level
};
class MyPC { public: int FUN_14152ea50(); };   // C3: unit-local view (mypc.h needs CHomePrivilege)
class Unk_DcPlayerMgr { public: Unk_DcPlayer* FUN_141bd0cc0(); };

// The party / matching state (party leader's level and job while in a party).
class Unk_DcParty : public CPartyManager
{
public:
};

// The UI manager.
class Unk_DcUIMgr
{
public:
    void FUN_141adc530(int nUiId);
};
template <class T> T* Unk_GetUI(int nUiId);
class UIDungeonSearchSettingDialog : public UIDialog
{
public:
    void SetSelected(const std::set<unsigned int>& ids);
};

// The dungeon rooms (rows of the dungeon room table) and the weekly reward steps.
class Unk_DcRoom : public CPtred
{
public:
    int m_nId;                                                  // +0x18
private:
    unsigned char m_pad_1c[0xe8];
public:
    unsigned short m_nMinLevel;                                 // +0x104
private:
    unsigned char m_pad_106[0x42];
public:
    CString m_strBanner;                                        // +0x148
private:
    unsigned char m_pad_150[0x61];
public:
    bool m_bHidden;                                             // +0x1b1
private:
    unsigned char m_pad_1b2[0x3a];
public:
    DWORD m_nGroupId;                                           // +0x1ec
};
MS2_CHECK_OFFSET(Unk_DcRoom, m_nMinLevel, 0x104);
MS2_CHECK_OFFSET(Unk_DcRoom, m_strBanner, 0x148);
MS2_CHECK_OFFSET(Unk_DcRoom, m_bHidden, 0x1b1);
MS2_CHECK_OFFSET(Unk_DcRoom, m_nGroupId, 0x1ec);

class CMyCharacter* FUN_140931510();
__int64 GetServerTime();
class Unk_140166410* FUN_140166410();
class CFeatureManager { public: bool FUN_14036d570(int nFeature); };   // C3: unit-local view

void* FUN_140764030();

// The find component's party search button.
#include "ms2/placeholder/asbutton.h"   // C3: the button view is ASButton (was the stand-in Unk_140acd6e0)

// Strings.
CStringW TranslateEnumDungeonGroup(unsigned int nGroupType);      // group type name
bool FUN_140e14520(int nGroupType);                             // the group type is listed
bool FUN_140e146a0();                                           // matching is available
template <class T> CString Unk_SocketFormat(const char* szFormat, const T& n);
void XmlSetAttr(class TiXmlElement*, const char*, const CString&);   // C3: was FUN_140874050
class TiXmlElement;
template <class C> int XmlTokenList(TiXmlElement* pElem, const char* pszName, C& out);   // C3: was FUN_140178770 (std::vector<unsigned>)
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_1409404f0(__int64 n);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
extern int DAT_143ab2878;                                       // service type (2: party search disabled)

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols-manual.tsv)
bool UIDungeonCategoryTable::s_bInit;
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140c08990
UIDungeonCategory::UIDungeonCategory()
{
}

// @0x140c089f0
UIDungeonCategory::~UIDungeonCategory()
{
}

// @0x140c08a30
UIDungeonCategoryTable::UIDungeonCategoryTable()
{
    Load();
}

// @0x140c08ad0
UIDungeonCategoryTable::~UIDungeonCategoryTable()
{
}

// @0x140c09130
int FUN_140c09130(Unk_DcXmlNode* pNode, const char* szName, Unk_DcLevelRange& range)
{
    CString str;
    int nResult = XmlGetAttr((class TiXmlElement*)(pNode), szName, str);
    if (nResult == 0) {
        ATL::CAtlArray<unsigned short> values;
        XmlSplit(str, values, "-");
        if (values.GetCount() != 2)
            return 2;
        range.FUN_14075bc80(values[0], values[1]);
    }
    return nResult;
}

// @0x140c08b50
void UIDungeonCategoryTable::Load()
{
    TiXmlDocument doc;
    CString strPath = FUN_14071a5b0("Table", "dungeonCategory.xml");
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return;
    Unk_DcXmlNode* pRoot = ((class Unk_DcXmlNode*)((class Unk_XmlNode*)(reinterpret_cast<Unk_DcXmlNode*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0) {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_DcXmlNode* pTab = ((class Unk_DcXmlNode*)((class Unk_XmlNode*)(pRoot))->FirstChild("dungeonMainTab")); pTab != 0;
         pTab = ((class Unk_DcXmlNode*)((class Unk_XmlNode*)(pTab))->NextSibling("dungeonMainTab"))) {
        int nIndex = 0;
        XmlGetAttr((class TiXmlElement*)(pTab), "index", reinterpret_cast<int&>(nIndex));
        if (nIndex < 0 || nIndex >= 2)
            continue;
        for (Unk_DcXmlNode* pSub = ((class Unk_DcXmlNode*)((class Unk_XmlNode*)(pTab))->FirstChild("dungeonSubTab")); pSub != 0;
             pSub = ((class Unk_DcXmlNode*)((class Unk_XmlNode*)(pSub))->NextSibling("dungeonSubTab"))) {
            if (!FUN_14028f710((struct Unk_XmlElement*)(pSub)))
                continue;
            MS2Ptr<UIDungeonCategory> pCategory(new UIDungeonCategory);
            FUN_140c09130(pSub, "level", pCategory->m_range);
            for (Unk_DcXmlNode* pNode = ((class Unk_DcXmlNode*)((class Unk_XmlNode*)(pSub))->FirstChild("dungeonCategory")); pNode != 0;
                 pNode = ((class Unk_DcXmlNode*)((class Unk_XmlNode*)(pNode))->NextSibling("dungeonCategory"))) {
                Unk_DcGroupType nGroupType;
                XmlValueByName(reinterpret_cast<TiXmlElement*>(pNode), "groupType", reinterpret_cast<Unk_DungeonGroupType&>(nGroupType));
                pCategory->m_groupTypes.Add(nGroupType);
            }
            m_maps[nIndex].SetAt(pCategory->m_range.m_nLow, pCategory);
        }
    }
    SetInit(true);
}

// @0x140c08ec0
void UIDungeonCategoryTable::FUN_140c08ec0(int nTab, ATL::CAtlArray<MS2Ptr<UIDungeonCategory> >& out)
{
    CheckInit();
    if (nTab < 0 || nTab >= 2)
        return;
    Map& map = m_maps[nTab];
    for (POSITION pos = map.GetHeadPosition(); pos != 0; map.GetNext(pos))
        out.Add(map.GetValueAt(pos));
}
MS2_REPLACE_METHOD(0x140C08EC0, UIDungeonCategoryTable, FUN_140c08ec0, 138, 0xCD3F2EA2);

// @0x140c08f50
unsigned short UIDungeonCategoryTable::FUN_140c08f50(int nTab)
{
    CheckInit();
    if (nTab < 0 || nTab >= 2)
        return 0;
    Map& map = m_maps[nTab];
    unsigned short nMax = 0;
    for (POSITION pos = map.GetHeadPosition(); pos != 0; map.GetNext(pos)) {
        MS2Ptr<UIDungeonCategory> pCategory = map.GetValueAt(pos);
        if (pCategory->m_range.m_nLow >= nMax)
            nMax = pCategory->m_range.m_nLow;
    }
    return nMax;
}
MS2_REPLACE_METHOD(0x140C08F50, UIDungeonCategoryTable, FUN_140c08f50, 212, 0xFFEA75BF);

// @0x140c09030
int UIDungeonCategoryTable::FUN_140c09030(int nTab, unsigned short nLevel)
{
    CheckInit();
    if (nTab < 0 || nTab >= 2)
        return 0;
    Map& map = m_maps[nTab];
    int nIndex = 0;
    for (POSITION pos = map.GetHeadPosition(); pos != 0; map.GetNext(pos)) {
        MS2Ptr<UIDungeonCategory> pCategory = map.GetValueAt(pos);
        if (pCategory->m_range.FUN_1407790e0(nLevel))
            return nIndex;
        nIndex++;
    }
    return map.GetCount() - 1;
}
MS2_REPLACE_METHOD(0x140C09030, UIDungeonCategoryTable, FUN_140c09030, 256, 0x3506C89E);

// @0x140c09910
void UIDungeonCategoryTable::CheckInit()
{
    if (!s_bInit) {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(UIDungeonCategoryTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140c0ab90
void UIDungeonCategoryTable::SetInit(bool b)
{
    s_bInit = b;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140c0aea0
UIDungeonControlCenter::UIDungeonControlCenter() : m_binder("DungeonControlCenter"), m_nSubTab(0)
{
    m_58 = 1;
}

// @0x140c0af60
UIDungeonControlCenter::~UIDungeonControlCenter()
{
}

// @0x140c0afd0
CString UIDungeonControlCenter::GetTypeName()
{
    return "DungeonControlCenter";
}
MS2_REPLACE_METHOD(0x140C0AFD0, UIDungeonControlCenter, GetTypeName, 61, 0x134E9AB7);

// @0x140c0b020
void UIDungeonControlCenter::vfunc_67()
{
    UIDialog::vfunc_67();
    reinterpret_cast<PacketHandlerManager*>(FUN_140bccd50())->UnregisterHandler(0x53, Delegate<void(CInPacket&)>(this, &UIDungeonControlCenter::FUN_140c0cea0));
    reinterpret_cast<PacketHandlerManager*>(FUN_140bccd50())->UnregisterHandler(0x1a, Delegate<void(CInPacket&)>(this, &UIDungeonControlCenter::FUN_140c0cf20));
    m_binder.FUN_140d43990();
}

// @0x140c0b180
void UIDungeonControlCenter::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    reinterpret_cast<PacketHandlerManager*>(FUN_140bccd50())->RegisterHandler(0x53, Delegate<void(CInPacket&)>(this, &UIDungeonControlCenter::FUN_140c0cea0));
    reinterpret_cast<PacketHandlerManager*>(FUN_140bccd50())->RegisterHandler(0x1a, Delegate<void(CInPacket&)>(this, &UIDungeonControlCenter::FUN_140c0cf20));
    FUN_1419260d0("m_webGuideButton", 0);
    Unk_DcPlayer* pPlayer = ((Unk_DcPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer != 0)
        m_nSubTab = UIDungeonCategoryTable::GetInstance()->FUN_140c09030(0, pPlayer->vfunc_78());
    FUN_140c0bab0();
    FUN_140c0c430();
    FUN_140c0c600(0);
}

// @0x140c0b390
int UIDungeonControlCenter::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    ASData data;
    if (_stricmp("onTabChange", szMethod) == 0) {
        ASData args;
        if (args.SetArgsIfAny(pArgs, nArgs)) {
            int nTab = args.PopInt();
            FUN_140c0c600(nTab);
        }
        return 1;
    } else if (_stricmp("onSubTabChange", szMethod) == 0) {
        ASData args;
        if (args.SetArgsIfAny(pArgs, nArgs)) {
            m_nSubTab = args.PopInt();
            FUN_140c0c660(1);
        }
        return 1;
    } else if (_stricmp("onPartySearch", szMethod) == 0) {
        OnPartySearch();
        return 1;
    } else if (_stricmp("onPartyMatch", szMethod) == 0) {
        SendPartyMode32();
        return 1;
    } else if (_stricmp("onPartyMatchCancel", szMethod) == 0) {
        SendPartyMode34();
        return 1;
    } else if (_stricmp("onSetting", szMethod) == 0) {
        OnSetting();
        return 1;
    } else if (_stricmp("onPopupDetail", szMethod) == 0) {
        OnPopupDetail();    // no return: falls through to 0
    } else if (_stricmp("onBookmark", szMethod) == 0) {
        OnBookmark();
        return 1;
    } else if (_stricmp("onEnterLobby", szMethod) == 0) {
        ASData args;
        if (args.SetArgsIfAny(pArgs, nArgs))
            SendRoomDungeon(args.PopUInt());
        return 1;
    } else if (_stricmp("onClickTile", szMethod) == 0) {
        ASData args;
        if (args.SetArgsIfAny(pArgs, nArgs))
            FUN_140c0cdb0(args.PopUInt());
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140C0B390, UIDungeonControlCenter, vfunc_28, 1077, 0x601E5140);

// @0x140c0b800
int UIDungeonControlCenter::vfunc_53(void* pCfg)
{
    UIDialog::vfunc_53(pCfg);
    CString str;
    std::set<unsigned int>& ids = m_bookmarks;
    std::set<unsigned int>::iterator itEnd = ids.end();
    for (std::set<unsigned int>::iterator it = ids.begin(); it != itEnd; ++it) {
        unsigned int nId = *it;
        str += Unk_SocketFormat<unsigned int>("{0},", nId);
    }
    XmlSetAttr((class TiXmlElement*)(pCfg), "dungeon", str);
    return 1;
}
MS2_REPLACE_METHOD(0x140C0B800, UIDungeonControlCenter, vfunc_53, 275, 0x59C2B689);

// @0x140c0b920
int UIDungeonControlCenter::vfunc_54(void* pCfg)
{
    UIDialog::vfunc_54(pCfg);
    m_bookmarks.clear();
    std::vector<unsigned int> ids;
    XmlTokenList(static_cast<TiXmlElement*>(pCfg), "dungeon", ids);
    for (size_t i = 0; i < ids.size(); i++) {
        if (TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(ids[i]).get())
            m_bookmarks.insert(ids[i]);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140C0B920, UIDungeonControlCenter, vfunc_54, 325, 0xE146A10B);

// @0x140c0ba70
void UIDungeonControlCenter::FUN_140c0ba70(std::set<unsigned int>& ids)
{
    m_bookmarks.swap(ids);
}
MS2_REPLACE_METHOD(0x140C0BA70, UIDungeonControlCenter, FUN_140c0ba70, 43, 0x24B189AA);

// @0x140c0bab0
void UIDungeonControlCenter::FUN_140c0bab0()
{
    Unk_DcPlayer* pPlayer = ((Unk_DcPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    ASObj obj(2);
    int nWeekly = 0;
    int nWeeklyMax = 0;
    if (DungeonRecordCliPtr pMission = FUN_140931510()->GetRecord().operator->()->GetRecord(0x3ee)) {
        nWeekly = pMission->GetBonusRewardCountNow();
        nWeeklyMax = pMission->GetMaxCount();
        obj.FUN_1407cbb20("weekly", FUN_14028dfa0(L"s_dungeon_control_center_reward_weekly", reinterpret_cast<const unsigned&>(nWeekly), reinterpret_cast<const unsigned&>(nWeeklyMax)));
        int nDaily = pMission->GetClearCount(GetServerTime());
        int nDailyMax = pMission->GetSubRewardCount();
        obj.FUN_1407cbb20("daily", FUN_14028dfa0(L"s_dungeon_control_center_reward_daily", reinterpret_cast<const unsigned&>(nDaily), reinterpret_cast<const unsigned&>(nDailyMax)));
    }
    int nNext = 0;
    size_t nCount = TSingleton<DungeonRoomTable>::GetInstance()->GetUnitedWeeklyRewardCount();
    for (size_t i = 0; i < nCount; i++) {
        MS2Ptr<DungeonUnitedWeeklyReward> pStep = TSingleton<DungeonRoomTable>::GetInstance()->GetUnitedWeeklyReward(i);
        if (pStep == 0)
            continue;
        bool bReached = (unsigned int)nWeekly >= pStep->m_rewardCount;
        if (!bReached) {
            nNext = pStep->m_rewardCount;
            break;
        }
    }
    if (nNext == 0) {
        nNext = nWeeklyMax;
        obj.FUN_1407cb9c0("complete", 1);
        obj.FUN_1407cbb20("count", GetStringCommonByKey(L"s_dungeon_control_center_require_reward_complete"));
    } else {
        int nRemain = nNext - nWeekly;
        obj.FUN_1407cb9c0("complete", 0);
        obj.FUN_1407cbb20("count", FUN_14028dfa0(L"s_dungeon_control_center_require_reward_count", reinterpret_cast<const unsigned&>(nRemain)));
    }
    MS2Ptr<DungeonUnitedWeeklyReward> pStep = TSingleton<DungeonRoomTable>::GetInstance()->FindUnitedWeeklyReward(nNext);
    if (pStep.get()) {
        RewardContentsTable::Result rewards;
        static_cast<RewardContentsTable*>(FUN_140764030())->GetReward(pStep->m_rewardID, pPlayer->vfunc_78(), rewards);
        if (!rewards.m_items.empty())
            obj.FUN_1407cba60("binding", m_binder.FUN_140d43510(static_cast<ItemAble*>(&rewards.m_items[0])));
        __int64 nMeso = rewards.m_nMeso;
        __int64 nExp = rewards.m_nExp;
        if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xb9)) {
            if (FUN_140931510()->GetRecord().operator->()->IsBoostActive()) {
                nMeso *= FUN_140931510()->GetRecord().operator->()->GetRateB();
                nExp *= FUN_140931510()->GetRecord().operator->()->GetRateA();
            }
        }
        obj.FUN_1407cbb20("meso", FUN_1409404f0(nMeso));
        obj.FUN_1407cbb20("exp", FUN_14028dfa0<CStringW>(L"s_number_string_exp", FUN_1409404f0(nExp)));
    }
    if (MS2Ptr<ASUIComponent> pComponent = GetChild<ASUIComponent>("m_dungeonRewardComponent"))
        pComponent->Invoke("setData", obj);
}
MS2_REPLACE_METHOD(0x140C0BAB0, UIDungeonControlCenter, FUN_140c0bab0, 2415, 0xF7AC412D);

// @0x140c0c430
void UIDungeonControlCenter::FUN_140c0c430()
{
    int nMatch = reinterpret_cast<Unk_DcParty*>(TSingleton<CPartyManager>::GetInstance())->IsMatchSearching(1);
    int bEnabled = FUN_140e146a0();
    if (MS2Ptr<ASUIComponent> pComponent = GetChild<ASUIComponent>("m_dungeonFindComponent")) {
        pComponent->Invoke("setMatch", nMatch);
        pComponent->Invoke("setEnabled", bEnabled);
        if (MS2Ptr<ASButton> pButton = pComponent->FUN_140acce30<ASButton>("m_partySearch"))
            pButton->FUN_1422c1fe0(DAT_143ab2878 != 2);
    }
}
MS2_REPLACE_METHOD(0x140C0C430, UIDungeonControlCenter, FUN_140c0c430, 443, 0xF0A3FAEA);

// @0x140c0c600
void UIDungeonControlCenter::FUN_140c0c600(int nTab)
{
    if (nTab < 0 || nTab >= 2)
        return;
    int nType = nTab;
    switch (nType) {
    case 0:
        FUN_140c0c660(0);
        break;
    case 1:
        FUN_140c0c8e0();
        break;
    }
}
MS2_REPLACE_METHOD(0x140C0C600, UIDungeonControlCenter, FUN_140c0c600, 90, 0xE6959727);

// @0x140c0c660
void UIDungeonControlCenter::FUN_140c0c660(int bUpdate)
{
    ATL::CAtlArray<MS2Ptr<UIDungeonCategory> > categories;
    UIDungeonCategoryTable::GetInstance()->FUN_140c08ec0(0, categories);
    if (m_nSubTab >= (int)categories.GetCount())
        return;
    ASObj obj(2);
    ASArray list(2);
    FUN_140c0d260(list);
    FUN_140c0d620(categories[m_nSubTab], list);
    obj.FUN_1409eb1d0("dungeon", list);
    if (bUpdate != 0) {
        m_30->FUN_140acd1f0("updateTab", AScript(obj));
    } else {
        obj.FUN_1409c48f0("dungeonLv", UIDungeonCategoryTable::GetInstance()->FUN_140c08f50(0));
        obj.FUN_1407cb9c0("idx", m_nSubTab);
        m_30->Invoke("buildTab", 0, AScript(obj));
    }
}
MS2_REPLACE_METHOD(0x140C0C660, UIDungeonControlCenter, FUN_140c0c660, 632, 0xB1B65975);

// @0x140c0c8e0
void UIDungeonControlCenter::FUN_140c0c8e0()
{
    ATL::CAtlArray<MS2Ptr<UIDungeonCategory> > categories;
    UIDungeonCategoryTable::GetInstance()->FUN_140c08ec0(1, categories);
    ASObj obj(2);
    if (categories.GetCount() == 0)
        return;
    ASArray list(2);
    FUN_140c0d620(categories[0], list);
    obj.FUN_1409eb1d0("dungeon", list);
    m_30->Invoke("buildTab", 1, AScript(obj));
}
MS2_REPLACE_METHOD(0x140C0C8E0, UIDungeonControlCenter, FUN_140c0c8e0, 400, 0xBA9C9A96);

// @0x140c0dea0
UIDungeonSearchSettingDialog* FUN_140c0dea0(int nUiId)
{
    if (reinterpret_cast<Unk_DcUIMgr*>(TSingleton<CUIService>::GetInstance()) != 0) {
        MS2Ptr<UIObject> spUI = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIDungeonSearchSettingDialog*>((UIObject*)spUI);
    }
    return 0;
}

// @0x140c0ca80
void UIDungeonControlCenter::OnSetting()
{
    if (m_bookmarks.empty()) {
        RoomVec rooms;
        FUN_140c0dab0(rooms);
        std::set<unsigned int> unused;
        MS2_FOR_EACH(MS2Ptr<Unk_DcRoom> pRoom, rooms)
            m_bookmarks.insert(reinterpret_cast<DungeonRoom*>(pRoom.operator->())->GetDungeonRoomID());
    }
    UIDungeonSearchSettingDialog* pDialog = FUN_140c0dea0(0x4f86);
    if (pDialog != 0) {
        pDialog->SetSelected(m_bookmarks);
        pDialog->FUN_141924680();
    }
}

// @0x140c0cc00
void UIDungeonControlCenter::OnPartySearch()
{
    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4eda)));
}
MS2_REPLACE_METHOD(0x140C0CC00, UIDungeonControlCenter, OnPartySearch, 32, 0x23FD8E49);

// @0x140c0dd90
COutputStream& FUN_140c0dd90(COutputStream& out, const std::set<unsigned int>& ids)
{
    out.WriteInt32(ids.size());
    for (std::set<unsigned int>::const_iterator it = ids.begin(); it != ids.end(); it++)
        FUN_14070f9a0(out, *it);
    return out;
}

// @0x140c0cc30
void UIDungeonControlCenter::SendPartyMode32()
{
    COutPacket packet(static_cast<int>(SendOp::Party), 0);
    packet.Encode1(0x20);
    packet.Encode1(1);
    FUN_140c0dd90(packet, m_bookmarks);
    FUN_14070f820(packet, false);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140C0CC30, UIDungeonControlCenter, SendPartyMode32, 123, 0x8CB1324B);

// @0x140c0ccc0
void UIDungeonControlCenter::SendPartyMode34()
{
    COutPacket packet(static_cast<int>(SendOp::Party), 0);
    packet.Encode1(0x22);
    packet.Encode1(1);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140C0CCC0, UIDungeonControlCenter, SendPartyMode34, 87, 0xD11E8DC1);

// @0x140c0cd20
void UIDungeonControlCenter::OnBookmark()
{
    UIDungeonRoomDialog* pDialog = Unk_GetUI<UIDungeonRoomDialog>(0x4ebd);
    if (pDialog != 0) {
        TSingleton<CUIService>::GetInstance()->FUN_141adc690((eUIClassID)0x4ebd);
        pDialog->FUN_1412b9110();
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4ebd)));
    }
}
MS2_REPLACE_METHOD(0x140C0CD20, UIDungeonControlCenter, OnBookmark, 83, 0xF817E2BE);

// @0x140c0cd80
void UIDungeonControlCenter::OnPopupDetail()
{
    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4f85)));
}
MS2_REPLACE_METHOD(0x140C0CD80, UIDungeonControlCenter, OnPopupDetail, 32, 0xE11816BE);

// @0x140c0cdb0
void UIDungeonControlCenter::FUN_140c0cdb0(int nId)
{
    UIDungeonRoomDialog* pDialog = Unk_GetUI<UIDungeonRoomDialog>(0x4ebd);
    if (pDialog != 0) {
        TSingleton<CUIService>::GetInstance()->FUN_141adc690((eUIClassID)0x4ebd);
        pDialog->FUN_1412b8ff0(nId);
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4ebd)));
    }
}
MS2_REPLACE_METHOD(0x140C0CDB0, UIDungeonControlCenter, FUN_140c0cdb0, 91, 0xA9F2625E);

// @0x140c0ce20
void UIDungeonControlCenter::SendRoomDungeon(int nGroupType)
{
    int nLobby = FUN_140c0dc60(nGroupType);
    if (nLobby != -1) {
        COutPacket packet(static_cast<int>(SendOp::RoomDungeon), 0);
        packet.Encode1((unsigned char)nLobby);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x140C0CE20, UIDungeonControlCenter, SendRoomDungeon, 113, 0xCAA06AAE);

// @0x140c0cea0
void UIDungeonControlCenter::FUN_140c0cea0(CInPacket& packet)
{
    int nCommand = packet.ReadUInt8();
    switch (nCommand) {
    case 2:
    case 3:
    case 7:
    case 8:
    case 9:
    case 0x1e:
        FUN_140c0c430();
        break;
    }
}
MS2_REPLACE_METHOD(0x140C0CEA0, UIDungeonControlCenter, FUN_140c0cea0, 115, 0x2E3439AD);

// @0x140c0cf20
void UIDungeonControlCenter::FUN_140c0cf20(CInPacket& packet)
{
    int nCommand = packet.ReadUInt8();
    switch (nCommand) {
    case 0x17:
        FUN_140c0bab0();
        break;
    }
}
MS2_REPLACE_METHOD(0x140C0CF20, UIDungeonControlCenter, FUN_140c0cf20, 87, 0xD16A6CCA);

// @0x140c0cf80
int UIDungeonControlCenter::FUN_140c0cf80(int nGroupType, const Unk_DcLevelRange& range, ASArray& out)
{
    RoomVec rooms;
    TSingleton<DungeonRoomTable>::GetInstance()->GetGroupRooms((DungeonGroupType)nGroupType, reinterpret_cast<std::vector<DungeonRoomPtr>&>(rooms));
    for (size_t i = 0; i < rooms.size(); i++) {
        MS2Ptr<Unk_DcRoom> pRoom = rooms[i];
        if (range.IsValid() && !range.FUN_1407790e0(pRoom->m_nMinLevel))
            continue;
        ASObj obj(2);
        obj.FUN_1409c0d20("id", pRoom->m_nId);
        obj.FUN_1407cba60("banner", pRoom->m_strBanner);
        obj.FUN_1407cbb20("title", FUN_14028dfa0<unsigned short, CStringW>(L"s_dungeon_control_center_dungeon_title", pRoom->m_nMinLevel,
                                                 TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x14, pRoom->m_nId)));
        out.PushObj(obj);
    }
    return out.GetLength() != 0;
}
MS2_REPLACE_METHOD(0x140C0CF80, UIDungeonControlCenter, FUN_140c0cf80, 720, 0x945A24C6);

// @0x140c0d260
void UIDungeonControlCenter::FUN_140c0d260(ASArray& out)
{
    ASObj obj(2);
    obj.FUN_1407cb9c0("isRecommend", 1);
    obj.FUN_1407cbb20("category", GetStringCommonByKey(L"s_dungeon_control_center_recommend_category"));
    ASArray list(2);
    RoomVec rooms;
    FUN_140c0d800(rooms);
    for (unsigned int i = 0; i < rooms.size(); i++) {
        if (!reinterpret_cast<Unk_DcParty*>(TSingleton<CPartyManager>::GetInstance())->CanEnterDungeonRoom(reinterpret_cast<DungeonRoom*>(rooms[i].operator->())->GetDungeonRoomID()))
            continue;
        if (rooms[i]->m_bHidden)
            continue;
        MS2Ptr<Unk_DcRoom> pRoom = rooms[i];
        ASObj item(2);
        item.FUN_1409c0d20("id", pRoom->m_nId);
        item.FUN_1407cba60("banner", pRoom->m_strBanner);
        item.FUN_1407cbb20("title", FUN_14028dfa0<unsigned short, CStringW>(L"s_dungeon_control_center_dungeon_title", pRoom->m_nMinLevel,
                                                  TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x14, pRoom->m_nId)));
        list.PushObj(item);
    }
    obj.FUN_1409eb1d0("list", list);
    out.PushObj(obj);
}
MS2_REPLACE_METHOD(0x140C0D260, UIDungeonControlCenter, FUN_140c0d260, 944, 0xD7B5DA54);

// @0x140c0d620
void UIDungeonControlCenter::FUN_140c0d620(MS2Ptr<UIDungeonCategory> pCategory, ASArray& out)
{
    for (size_t i = 0; i < pCategory->m_groupTypes.GetCount(); i++) {
        int nGroupType = pCategory->m_groupTypes[i];
        if (!FUN_140e14520(nGroupType))
            continue;
        ASObj obj(2);
        obj.FUN_1407cb9c0("isRecommend", 0);
        obj.FUN_1407cbb20("category", TranslateEnumDungeonGroup(nGroupType));
        obj.FUN_140c0e050("groupType", nGroupType);
        obj.FUN_1407cbbe0("hasLobby", FUN_140c0dc60(nGroupType) != -1);
        ASArray list(2);
        if (FUN_140c0cf80(nGroupType, pCategory->m_range, list)) {
            obj.FUN_1409eb1d0("list", list);
            out.PushObj(obj);
        }
    }
}
MS2_REPLACE_METHOD(0x140C0D620, UIDungeonControlCenter, FUN_140c0d620, 473, 0x77BD59BC);

// @0x140c0d800
void UIDungeonControlCenter::FUN_140c0d800(RoomVec& out)
{
    out.clear();
    Unk_DcPlayer* pPlayer = ((Unk_DcPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    unsigned short nLevel = 0;
    int nJob = 0;
    if (reinterpret_cast<Unk_DcParty*>(TSingleton<CPartyManager>::GetInstance())->IsInParty()) {
        nLevel = reinterpret_cast<Unk_DcParty*>(TSingleton<CPartyManager>::GetInstance())->GetMinMemberLevel();
        nJob = reinterpret_cast<Unk_DcParty*>(TSingleton<CPartyManager>::GetInstance())->FUN_14162c1e0();
    } else {
        nLevel = pPlayer->vfunc_78();
        nJob = reinterpret_cast<MyPC*>(pPlayer)->FUN_14152ea50();
    }
    RoomVec rooms;
    TSingleton<DungeonRoomTable>::GetInstance()->GetRoomsForLevel(nLevel, nJob, reinterpret_cast<std::vector<DungeonRoomPtr>&>(rooms));
    std::map<DWORD, bool> groups;
    unsigned int nAdded = 0;
    for (unsigned int i = 0; i < rooms.size(); i++) {
        MS2Ptr<Unk_DcRoom> pRoom = rooms[i];
        if (nLevel < pRoom->m_nMinLevel)
            continue;
        if (!reinterpret_cast<Unk_DcParty*>(TSingleton<CPartyManager>::GetInstance())->CanEnterDungeonRoom(reinterpret_cast<DungeonRoom*>(pRoom.operator->())->GetDungeonRoomID()))
            continue;
        if (pRoom->m_bHidden)
            continue;
        if (pRoom->m_nGroupId != 0 && groups[pRoom->m_nGroupId] == true)
            continue;
        groups[pRoom->m_nGroupId] = true;
        out.push_back(rooms[i]);
        nAdded++;
        if (nAdded >= 4)
            break;
    }
}
MS2_REPLACE_METHOD(0x140C0D800, UIDungeonControlCenter, FUN_140c0d800, 677, 0xFD9591E3);

// @0x140c0dab0
void UIDungeonControlCenter::FUN_140c0dab0(RoomVec& out)
{
    out.clear();
    Unk_DcPlayer* pPlayer = ((Unk_DcPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    unsigned short nLevel = 0;
    int nJob = 0;
    if (reinterpret_cast<Unk_DcParty*>(TSingleton<CPartyManager>::GetInstance())->IsInParty()) {
        nLevel = reinterpret_cast<Unk_DcParty*>(TSingleton<CPartyManager>::GetInstance())->GetMinMemberLevel();
        nJob = reinterpret_cast<Unk_DcParty*>(TSingleton<CPartyManager>::GetInstance())->FUN_14162c1e0();
    } else {
        nLevel = pPlayer->vfunc_78();
        nJob = reinterpret_cast<MyPC*>(pPlayer)->FUN_14152ea50();
    }
    RoomVec rooms;
    TSingleton<DungeonRoomTable>::GetInstance()->GetMatchRooms(nLevel, nJob, reinterpret_cast<std::vector<DungeonRoomPtr>&>(rooms));
    for (unsigned int i = 0; i < rooms.size(); i++) {
        if (!reinterpret_cast<Unk_DcParty*>(TSingleton<CPartyManager>::GetInstance())->CanEnterDungeonRoom(reinterpret_cast<DungeonRoom*>(rooms[i].operator->())->GetDungeonRoomID()))
            continue;
        if (rooms[i]->m_bHidden)
            continue;
        out.push_back(rooms[i]);
    }
}
MS2_REPLACE_METHOD(0x140C0DAB0, UIDungeonControlCenter, FUN_140c0dab0, 425, 0xC1691F3F);

// @0x140c0dc60
int UIDungeonControlCenter::FUN_140c0dc60(int nGroupType)
{
    switch (nGroupType) {
    case 3:
        return 4;
    case 4:
        return 0xc;
    case 0xd:
        return 0xd;
    case 5:
        return 0xe;
    }
    return -1;
}
MS2_REPLACE_METHOD(0x140C0DC60, UIDungeonControlCenter, FUN_140c0dc60, 84, 0xF6BD78CB);

// @0x140c0df40 Invoke(name, int, AS object): the by-value object is destroyed by the callee
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, AScript a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), Scaleform::GFx::Value(a2.FUN_1422bb890()));
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140c0e050
void ASObj::FUN_140c0e050(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    m_value.SetMember(szName, data.PopValue());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca2310-0x142ca23a0 .text$yd
