// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UINpcCreateDialog: see uinpccreatedialog.h.
// MS2-UNIT: ?\uinpccreatedialog.cpp
// MS2-RANGE: 0x141a6a470-0x141a6e060 .text$mn
// MS2-RANGE: 0x140119e20-0x140119f90 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x140119ee0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x140119f10 ; probe
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x140119f40 ; unique
// MS2-PIN: ??_GUINpcCreateDialog@@UEAAPEAXI@Z 0x141a6d600 ; unique
// MS2-PIN: ?vfunc_48@UINpcCreateDialog@@UEAAHXZ 0x141a6d640 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uinpccreatedialog.cpp"    // assumed
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"

#include "uinpccreatedialog.h"

#include <stdlib.h>
#include <string.h>
#include <vector>

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/client/ms2/npcdatacli.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/client/ms2/filepreload_1.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/commandchat.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/client/ms2/worldservice.h"

template <> MS2Ptr<ASScrollingList> UISwfEntity::GetChild<ASScrollingList>(const CString& strName);   // 0x140c02900, owned by uiinventorydialog
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

extern template class MS2Ptr<CProxyGameObject>;

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The key input state (singleton).
class Unk_14025e7c0 : public CInputKeyHandler {};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The local player: the position (slot 18) and direction (slot 20) getters.
class Unk_NcPlayer
{
public:
    virtual void Unk_Slot0();  virtual void Unk_Slot1();  virtual void Unk_Slot2();  virtual void Unk_Slot3();
    virtual void Unk_Slot4();  virtual void Unk_Slot5();  virtual void Unk_Slot6();  virtual void Unk_Slot7();
    virtual void Unk_Slot8();  virtual void Unk_Slot9();  virtual void Unk_Slot10(); virtual void Unk_Slot11();
    virtual void Unk_Slot12(); virtual void Unk_Slot13(); virtual void Unk_Slot14(); virtual void Unk_Slot15();
    virtual void Unk_Slot16(); virtual void Unk_Slot17();
    virtual Vector3 vfunc_18();
    virtual void Unk_Slot19();
    virtual Vector3 vfunc_20();
};

// The thing an entity event points at (slot 6 returns its kind object).
class Unk_NcActor { public: virtual void Unk_Slot0(); virtual void Unk_Slot1(); virtual void Unk_Slot2(); virtual void Unk_Slot3();
                            virtual void Unk_Slot4(); virtual void Unk_Slot5(); virtual const efd::ClassInfo* vfunc_6(); };

// The world: the local player, the entity of an event, the proxy of an object id, the current map.
class Unk_NcWorld : public WorldService
{
public:
    Unk_NcPlayer* FUN_141bd0cc0();
    MS2Ptr<CProxyGameObject> FUN_141bc9e70(int nId);
};

void FUN_1406c70a0(void* sp);                                // ~MS2Ptr<CProxyGameObject>

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).
void FUN_141276f80(const Unk_CommandChat&);   // FUN_141276f80 takes a pointer and returns int: kept
CString FUN_1411c0aa0(const char* szText);                   // a text without arguments

class Unk_NpcTableCli* FUN_1406d6e90();   // C3: was FUN_1406d6e90
MS2Ptr<CNpcData> FUN_1406cd330(int nNpc);   // the npc row; FUN_141a6b800 discards it

CStringW GetStringCommon(int nId);                        // string table text
void FUN_1412751f0(const CStringW& strText, int a, int b);

class Unk_UpperEvents { public: void FUN_1419308c0(UIEntityEventListener*); void FUN_141930950(UIEntityEventListener*); };
class Unk_LsEntityEvents* FUN_140c607b0();   // C3: was FUN_140c607b0

unsigned FUN_140718200(const CStringW& str);          // the npc id of an id text
CStringW FUN_1401aa6a0(int nNpc);
void FUN_140841420(CStringW& str);                      // trim
CStringTable* GetStringTable();

// xml file helpers
class CFileSystem* GetFileSystem();   // C3: was FUN_140166420
class Unk_NcNode { public: Unk_NcNode* FUN_140165cf0(const char* szTag); Unk_NcNode* FUN_140168650(const char* szTag); };
class CLogString* GetLogString();   // C3: was FUN_140166440
void Unk_AdditionalLog(class CLogString*, int, int, wchar_t const*);   // C3: was FUN_1401859c0
void FUN_140399100(CString strPattern, CString strDir, CAtlArray<CString>& output, CString strExclude, bool bLocalOnly);
CStringW FUN_1401bf530(Unk_140165cf0* pNode, const char* szAttr, CStringW strDefault);

// @0x141a6c140
template CStringW FUN_14028dfa0<CStringW, unsigned short, CStringW, unsigned, CStringW, CStringW>(CStringW, const CStringW&, const unsigned short&, const CStringW&, const unsigned&, const CStringW&, const CStringW&);
// @0x141a6c5a0
template CStringW FUN_14028dfa0<CStringW, unsigned short, CStringW, CStringW, CStringW>(CStringW, const CStringW&, const unsigned short&, const CStringW&, const CStringW&, const CStringW&);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141a6a470
UINpcCreateDialog::UINpcCreateDialog()
{
    m_40 = 1;
    m_bFilesRead = false;
    m_bEntriesBuilt = false;
    FUN_1422dc3b0(1);
    ((class Unk_UpperEvents*)FUN_140c607b0())->FUN_1419308c0(this);
}

// @0x141a6a590
UINpcCreateDialog::~UINpcCreateDialog()
{
    ((class Unk_UpperEvents*)FUN_140c607b0())->FUN_141930950(this);
}

// @0x141a6a680
CString UINpcCreateDialog::GetTypeName()
{
    return "NpcCreateDialog";
}

// @0x141a6a6d0
void UINpcCreateDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (!m_bFilesRead)
        ReadNpcFromFile();
    else
        FUN_141a6be40(m_strFilter);
}

// @0x141a6a730
int UINpcCreateDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (((class Unk_14025e7c0*)FUN_14025e7c0())->FUN_14116d9c0(0x1c, 0, 0)) {
        if (m_30.get())
            m_30->Invoke("onEnterKey");
        return 1;
    } else if (((class Unk_14025e7c0*)FUN_14025e7c0())->FUN_14116d9c0(0xf, 0, 0)) {
        if (m_30.get())
            m_30->Invoke("onTabKey");
        return 1;
    } else if (((class Unk_14025e7c0*)FUN_14025e7c0())->FUN_14116d840()) {
        vfunc_67();
        return 1;
    }
    return 0;
}

// @0x141a6a870
int UINpcCreateDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    ASData data;
    if (_stricmp("OnNpcCreate", szMethod) == 0) {
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            Unk_NcPlayer* pPlayer = ((Unk_NcPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
            if (pPlayer == 0)
                return 1;
            int nNpc = data.PopInt();
            int nCount = data.PopInt();
            COutPacket pkt(static_cast<int>(SendOp::RequestNpcCreate), 0);
            pkt.WriteInt32(nNpc);
            pkt.WriteVector3(pPlayer->vfunc_18());
            pkt.WriteVector3(pPlayer->vfunc_20());
            pkt.WriteInt32(nCount);
            pkt.WriteBool(false);
            FUN_140710590(pkt);
            TSingleton<CFilePreload>::GetInstance()->FUN_1412104c0(nNpc);
        }
        return 1;
    } else if (_stricmp("OnSummonPet", szMethod) == 0) {
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            Unk_NcPlayer* pPlayer = ((Unk_NcPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
            if (pPlayer == 0)
                return 1;
            int nNpc = data.PopInt();
            float fValue = data.PopFloat();
            int nCount = data.PopInt();
            COutPacket pkt(static_cast<int>(SendOp::RequestNpcCreate), 0);
            pkt.WriteInt32(nNpc);
            pkt.WriteVector3(pPlayer->vfunc_18());
            pkt.WriteVector3(pPlayer->vfunc_20());
            pkt.WriteInt32(nCount);
            pkt.WriteBool(true);
            pkt.WriteFloat(fValue);
            FUN_140710590(pkt);
            TSingleton<CFilePreload>::GetInstance()->FUN_1412104c0(nNpc);
        }
        return 1;
    } else if (_stricmp("OnReleasePet", szMethod) == 0) {
        Unk_CommandChat chat;
        chat.kind = 0;
        chat.message = (const char*)FUN_1411c0aa0("/ReleasePet");
        FUN_141276f80(chat);
        return 1;
    } else if (_stricmp("OnSearchNpc", szMethod) == 0) {
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            CStringW strFilter = data.FUN_1422b8f40();
            FUN_141a6be40(strFilter);
        }
        return 1;
    } else if (_stricmp("OnMoveToNpc", szMethod) == 0) {
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nNpc = data.PopInt();
            unsigned nField;
            if (TSingleton<CFieldMetaTable>::GetInstance()->FUN_1406fb700(nNpc, &nField) != 0) {
                if (reinterpret_cast<Unk_NcWorld*>(WorldService::GetInstance())->FUN_141bd3060() == nField) {
                    MS2Ptr<CProxyGameObject> spObj = reinterpret_cast<Unk_NcWorld*>(WorldService::GetInstance())->FUN_141bc9e70(nNpc);
                    if (spObj.get() != 0) {
                        COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
                        pkt.WriteUInt8(2);
                        pkt.WriteVector3Short(spObj->FUN_1416c2270());
                        FUN_140710590(pkt);
                    }
                } else {
                    if (((Unk_NcPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()) != 0)
                        reinterpret_cast<MyPC*>(((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0())->SendFunctionCube();
                    Unk_CommandChat chat;
                    chat.kind = 0;
                    chat.message = (const char*)static_cast<const CString&>(Unk_SocketFormat("/MoveField {0}", nField));
                    FUN_141276f80(chat);
                    m_nPendingNpc = nNpc;
                }
            } else {
                FUN_1412751f0(GetStringCommon(0x578), 1, 1);
            }
        }
        return 1;
    } else if (_stricmp("onOpenFile", szMethod) == 0) {
        return 1;
    }
    return 0;
}

// @0x141a6b030
void UINpcCreateDialog::vfunc_1(void* pEvt)
{
    Unk_NcActor* pActor = reinterpret_cast<Unk_NcActor*>(WorldService::GetInstance()->FindObjectByEntityId(*(const egf::EntityID*)pEvt));
    if (pActor != 0) {
        if (efd::ClassInfo::IsKindOf(pActor != 0 ? pActor->vfunc_6() : 0, 0x6200004)) {
            if (m_nPendingNpc == 0)
                return;
            MS2Ptr<CProxyGameObject> spObj = reinterpret_cast<Unk_NcWorld*>(WorldService::GetInstance())->FUN_141bc9e70(m_nPendingNpc);
            if (spObj.get() != 0) {
                COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
                pkt.WriteUInt8(2);
                pkt.WriteVector3Short(spObj->FUN_1416c2270());
                FUN_140710590(pkt);
                m_nPendingNpc = 0;
            }
        }
    }
}

// @0x141a6b1a0
void UINpcCreateDialog::vfunc_3(MS2Ptr<CProxyGameObject> spActor)
{
    if (((MS2Ptr<CProxyGameObject>*)&static_cast<class MS2Ptr<class CProxyGameObject> const&>(spActor))->IsNull()) {
        return;
    }
    if (m_nPendingNpc == 0) {
        return;
    }
    if (spActor->FUN_1416c2090() == 0) {
        return;
    }
    if (spActor->FUN_1416c2350() != m_nPendingNpc) {
        return;
    }
    {
        COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
        pkt.WriteUInt8(2);
        pkt.WriteVector3Short(spActor->FUN_1416c2270());
        FUN_140710590(pkt);
        m_nPendingNpc = 0;
    }
}

// @0x141a6b2e0
void UINpcCreateDialog::ReadNpcFromFile()
{
    Unk_AdditionalLog((class CLogString*)(((void*)GetLogString())), 0xc, 0x13, L"ReadNpcFromFile");
    m_files.clear();
    CAtlArray<CString> files;
    FUN_140399100(CString(".xml"), CString("./Data/Xml/") + "NpcData/", files, CString(""), false);
    for (unsigned __int64 i = 0; i < files.GetCount(); i++) {
        CString strFile = files[i];
        TiXmlDocument doc;
        if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strFile, 0, true, false) == 0)
            continue;
        Unk_NcNode* pRoot = ((class Unk_NcNode*)((class Unk_XmlNode*)(((Unk_NcNode*)&doc)))->FirstChild("ms2"));
        for (Unk_NcNode* pNpc = ((class Unk_NcNode*)((class Unk_XmlNode*)(pRoot))->FirstChild("npc")); pNpc != 0; pNpc = ((class Unk_NcNode*)((class Unk_XmlNode*)(pNpc))->NextSibling("npc"))) {
            CStringW strId((const wchar_t*)0);
            strId = FUN_1401bf530((Unk_140165cf0*)pNpc, "id", CStringW(L""));
            if (strId.IsEmpty())
                continue;
            m_files.push_back(strId);
        }
    }
    m_bFilesRead = true;
    Unk_AdditionalLog((class CLogString*)(((void*)GetLogString())), 0xc, 0x13, L"End ReadNpcFromFile");
    FUN_141a6b800();
}

// @0x141a6b6a0
CStringW UINpcCreateDialog::FUN_141a6b6a0(int nType, int bFriendly)
{
    CStringW strKind;
    if (bFriendly != 0) {
        strKind = L"Friendly";
    } else {
        switch (nType) {
        case 1: strKind = L"Mob"; break;
        case 3: strKind = L"Elite"; break;
        case 7: strKind = L"Dun_Elite"; break;
        case 4: strKind = L"Boss"; break;
        case 6: strKind = L"Dun_Boss"; break;
        case 5: strKind = L"Friendly"; break;
        }
    }
    return strKind;
}

// @0x141a6b800
void UINpcCreateDialog::FUN_141a6b800()
{
    Unk_AdditionalLog((class CLogString*)(((void*)GetLogString())), 0xc, 0x13, L"ReadNpcAll");
    for (unsigned __int64 i = 0; i < m_files.size(); i++) {
        CStringW strId = m_files[i];
        unsigned nNpc = FUN_140718200(strId);
        FUN_1406cd330(nNpc);
    }
    Unk_AdditionalLog((class CLogString*)(((void*)GetLogString())), 0xc, 0x13, L"End ReadNpcAll");
}

// @0x141a6b8f0
void UINpcCreateDialog::FUN_141a6b8f0()
{
    m_entries.clear();
    m_entries.resize(m_files.size());
    for (unsigned __int64 i = 0; i < m_files.size(); i++) {
        CStringW strId = m_files[i];
        unsigned nNpc = FUN_140718200(strId);
        MS2Ptr<NpcDataCli> row = reinterpret_cast<NpcDataTableCli*>(FUN_1406d6e90())->Find(nNpc);
        if (row.IsNull())
            continue;
        CStringW strKind = FUN_141a6b6a0(row->m_nClass, row->GetFriendly());
        CStringW strName = GetStringTable()->FUN_141811980(10, nNpc);
        CStringW strNpc = FUN_1401aa6a0(nNpc);
        CStringW strEmpty(L"");
        CStringW strLine = FUN_14028dfa0(CStringW(L"s_npccreate_render_name_format"), strKind, row->GetLevel(), strEmpty, row->GetClassConstant(), strName, strNpc);
        CStringW strSearch = FUN_14028dfa0(CStringW(L"s_npccreate_name_format"), strKind, row->GetLevel(), strEmpty, strName, strNpc);
        if (row->GetShopId() > 0) {
            strLine += FUN_14028dfa0(CStringW(L"s_npccreate_add_shopid"), row->GetShopId());
            strSearch += FUN_14028dfa0(CStringW(L"s_npccreate_add_shopid"), row->GetShopId());
        }
        FUN_140841420(strSearch);
        strSearch.Remove(L' ');
        m_entries[i].m_strId = strId;
        m_entries[i].m_strSearch = strSearch;
        m_entries[i].m_strLine = strLine;
    }
    m_bEntriesBuilt = true;
}

// @0x141a6be40
void UINpcCreateDialog::FUN_141a6be40(CStringW& strFilter)
{
    if (!m_bEntriesBuilt)
        FUN_141a6b8f0();
    FUN_140841420(strFilter);
    strFilter.Remove(L' ');
    MS2Ptr<ASScrollingList> list = GetChild<ASScrollingList>("m_npcList");
    if (list == 0)
        return;
    bool bEmpty = strFilter.IsEmpty();
    std::vector<Unk_NpcEntry>& rEntries = m_entries;
    std::vector<Unk_NpcEntry>::const_iterator itEnd = rEntries.end();
    for (std::vector<Unk_NpcEntry>::const_iterator it = rEntries.begin(); it != itEnd; ++it) {
        const Unk_NpcEntry& e = *it;
        if (e.m_strId.IsEmpty())
            continue;
        if (!bEmpty && e.m_strSearch.Find(strFilter, 0) == -1 && e.m_strId.Find(strFilter, 0) == -1)
            continue;
        ASObj row(2);
        row.FUN_1407cbb20("code", e.m_strId);
        row.FUN_1407cbb20("field", e.m_strLine);
        ((ASScrollingList*)list)->AddItem(row);
    }
    ((ASScrollingList*)list)->vfunc_24(true);
    m_strFilter = strFilter;
}


// Anchor for the UCRT header-inline memmove_s the range ends with (no caller in the exe's range).
void Unk_NcAnchor(void* pDst, const void* pSrc, size_t n)
{
    memmove_s(pDst, n, pSrc, n);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc0f90-0x142cc1020 .text$yd
