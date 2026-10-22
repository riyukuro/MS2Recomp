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
#include "ms2/placeholder/ms2stdafx.h"

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
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/client/ms2/filepreload_1.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/commandchat.h"

extern template class MS2Ptr<CProxyGameObject>;

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The list control of the movie (the AS list with append / refresh).
class Unk_NpcList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd230(const ASObj& row);               // append a row
};

// The key input state (singleton).
class Unk_14025e7c0 { public: bool FUN_14116d9c0(int nKey, int a, int b); bool FUN_14116d840(); };
Unk_14025e7c0* FUN_14025e7c0();

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
    void FUN_1415293b0();                               // stop the auto move
};

// The thing an entity event points at (slot 6 returns its kind object).
class Unk_NcActor { public: virtual void Unk_Slot0(); virtual void Unk_Slot1(); virtual void Unk_Slot2(); virtual void Unk_Slot3();
                            virtual void Unk_Slot4(); virtual void Unk_Slot5(); virtual void* vfunc_6(); };
bool FUN_14087ddc0(void* pKind, int nMask);

class Unk_UpperEvt { public: Unk_UpperEvt(const Unk_UpperEvt&); private: void* m_0; };

// The world: the local player, the entity of an event, the proxy of an object id, the current map.
class Unk_NcWorld
{
public:
    Unk_NcPlayer* FUN_141bd0cc0();
    Unk_NcActor* FUN_141bd0fa0(Unk_UpperEvt evt);
    MS2Ptr<CProxyGameObject> FUN_141bc9e70(int nId);
    int FUN_141bd3060();
};
Unk_NcWorld* FUN_1403ed2d0();

bool FUN_140ac5aa0(const MS2Ptr<CProxyGameObject>& sp);      // the actor is gone
void FUN_1406c70a0(void* sp);                                // ~MS2Ptr<CProxyGameObject>

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).
void FUN_141276f80(const Unk_CommandChat&);
CString FUN_1411c0aa0(const char* szText);                   // a text without arguments
CString FUN_140513200(const char* szFormat, const int& n);   // narrow format of one int

// The npc id -> npc data manager: handles to the data rows.
class Unk_NcNpc
{
public:
    int FUN_1406ccfc0();                                // friendly flag
    unsigned short FUN_1406cd060();                     // level
    int FUN_140a7c970();                                // hp
    int FUN_1406cd0d0();                                // shop id
    int m_pad_00[31];
    int m_nKind;                                        // +0x7c
};
class Unk_NcHandle
{
public:
    ~Unk_NcHandle();                                    // 0x1406d5390
    bool FUN_14109a230();                               // no row
    Unk_NcNpc* FUN_140965990();
private:
    void* m_0; void* m_8;
};
MS2_CHECK_SIZE(Unk_NcHandle, 0x10);
struct Unk_NcRef { void* m_0; void* m_8; };
class Unk_NcMgr { public: Unk_NcHandle FUN_140a7cab0(unsigned nNpc); };
Unk_NcMgr* FUN_1406d6e90();
Unk_NcRef FUN_1406cd330(unsigned nNpc);
void FUN_14035e5b0(const Unk_NcRef& ref);                      // preload the npc

class Unk_NcWalk { public: int FUN_1406fb700(int nNpc, int* pField); };
Unk_NcWalk* FUN_140700390();
CStringW GetStringCommon(int nId);                        // string table text
void FUN_1412751f0(const CStringW& strText, int a, int b);

class Unk_NcEvents { public: void FUN_1419308c0(UIEntityEventListener*); void FUN_141930950(UIEntityEventListener*); };
Unk_NcEvents* FUN_140c607b0();

unsigned FUN_140718200(const CStringW& str);          // the npc id of an id text
CStringW FUN_1401aa6a0(unsigned nNpc);
void FUN_140841420(CStringW& str);                      // trim
CStringTable* GetStringTable();
CStringW FUN_140938ae0(CStringW strKey, const int& n);  // FUN_14028dfa0<int>

// xml file helpers
class Unk_NcFiles { public: int FUN_1403974b0(TiXmlDocument&, const char*, int, bool, bool); };
Unk_NcFiles* FUN_140166420();
class Unk_NcNode { public: Unk_NcNode* FUN_140165cf0(const char* szTag); Unk_NcNode* FUN_140168650(const char* szTag); };
void* FUN_140166440();
void FUN_1401859c0(void* pLog, int a, int b, const wchar_t* szText);
void FUN_140399100(CString strPattern, CString strDir, void* pOutput, CString strExclude, bool bLocalOnly);
CString FUN_14038f6d0(const CString&, const char*);
CStringW FUN_1401bf530(Unk_NcNode* pNode, const char* szAttr, CStringW strDefault);
void* FUN_140163230(void* arr);                         // CAtlArray<CString>::CAtlArray
void FUN_1401641d0(void* arr);                          // CAtlArray<CString>::~CAtlArray
unsigned __int64 FUN_1401662c0(void* arr);              // GetCount
CString* FUN_140164930(void* arr, unsigned __int64 i);  // operator[]
struct Unk_NcStrArray { void* m_0; void* m_8; void* m_10; void* m_18; };

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
    FUN_140c607b0()->FUN_1419308c0(this);
}

// @0x141a6a590
UINpcCreateDialog::~UINpcCreateDialog()
{
    FUN_140c607b0()->FUN_141930950(this);
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
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0)) {
        if (m_30.get())
            m_30->Invoke("onEnterKey");
        return 1;
    } else if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0)) {
        if (m_30.get())
            m_30->Invoke("onTabKey");
        return 1;
    } else if (FUN_14025e7c0()->FUN_14116d840()) {
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
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            Unk_NcPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPlayer == 0)
                return 1;
            int nNpc = data.FUN_1422b8a10();
            int nCount = data.FUN_1422b8a10();
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
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            Unk_NcPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPlayer == 0)
                return 1;
            int nNpc = data.FUN_1422b8a10();
            float fValue = data.FUN_1422b8c10();
            int nCount = data.FUN_1422b8a10();
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
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CStringW strFilter = data.FUN_1422b8f40();
            FUN_141a6be40(strFilter);
        }
        return 1;
    } else if (_stricmp("OnMoveToNpc", szMethod) == 0) {
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nNpc = data.FUN_1422b8a10();
            int nField;
            if (FUN_140700390()->FUN_1406fb700(nNpc, &nField) == 0) {
                FUN_1412751f0(GetStringCommon(0x578), 1, 1);
            } else if (FUN_1403ed2d0()->FUN_141bd3060() == nField) {
                MS2Ptr<CProxyGameObject> spObj = FUN_1403ed2d0()->FUN_141bc9e70(nNpc);
                if (spObj.get() != 0) {
                    COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
                    pkt.WriteUInt8(2);
                    pkt.WriteVector3Short(spObj->FUN_1416c2270());
                    FUN_140710590(pkt);
                }
            } else {
                if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0)
                    FUN_1403ed2d0()->FUN_141bd0cc0()->FUN_1415293b0();
                Unk_CommandChat chat;
                chat.kind = 0;
                CString strCmd = FUN_140513200("/MoveField {0}", nField);
                chat.message = (const char*)strCmd;
                FUN_141276f80(chat);
                m_nPendingNpc = nNpc;
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
    Unk_UpperEvt evt(*(const Unk_UpperEvt*)pEvt);
    Unk_NcActor* pActor = FUN_1403ed2d0()->FUN_141bd0fa0(evt);
    if (pActor != 0) {
        void* pKind = pActor->vfunc_6();
        if (FUN_14087ddc0(pKind, 0x6200004) && m_nPendingNpc != 0) {
            MS2Ptr<CProxyGameObject> spObj = FUN_1403ed2d0()->FUN_141bc9e70(m_nPendingNpc);
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
void UINpcCreateDialog::vfunc_3(void* pActor)
{
    const MS2Ptr<CProxyGameObject>& spActor = *(const MS2Ptr<CProxyGameObject>*)pActor;
    if (FUN_140ac5aa0(spActor)) {
        FUN_1406c70a0(pActor);
        return;
    }
    if (m_nPendingNpc == 0) {
        FUN_1406c70a0(pActor);
        return;
    }
    if (spActor->FUN_1416c2090() == 0) {
        FUN_1406c70a0(pActor);
        return;
    }
    if (spActor->FUN_1416c2350() == m_nPendingNpc) {
        COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
        pkt.WriteUInt8(2);
        pkt.WriteVector3Short(spActor->FUN_1416c2270());
        FUN_140710590(pkt);
        m_nPendingNpc = 0;
    }
    FUN_1406c70a0(pActor);
}

// @0x141a6b2e0
void UINpcCreateDialog::ReadNpcFromFile()
{
    FUN_1401859c0(FUN_140166440(), 0xc, 0x13, L"ReadNpcFromFile");
    m_files.FUN_141a6dd40();
    Unk_NcStrArray files[8];
    FUN_140163230(files);
    FUN_140399100(CString(".xml"), CString("./Data/Xml/NpcData/"), files, CString(""), false);
    for (unsigned __int64 i = 0; i < FUN_1401662c0(files); i++) {
        CString strFile = *FUN_140164930(files, i);
        TiXmlDocument doc;
        if (FUN_140166420()->FUN_1403974b0(doc, (const char*)strFile, 0, true, false) == 0)
            continue;
        Unk_NcNode* pRoot = ((Unk_NcNode*)&doc)->FUN_140165cf0("ms2");
        for (Unk_NcNode* pNpc = pRoot->FUN_140165cf0("npc"); pNpc != 0; pNpc = pNpc->FUN_140168650("npc")) {
            CStringW strId((const wchar_t*)0);
            strId = FUN_1401bf530(pNpc, "id", CStringW(L""));
            if (!strId.IsEmpty())
                m_files.FUN_14041ada0(strId);
        }
    }
    m_bFilesRead = true;
    FUN_1401859c0(FUN_140166440(), 0xc, 0x13, L"End ReadNpcFromFile");
    FUN_141a6b800();
    FUN_1401641d0(files);
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
        case 4: strKind = L"Boss"; break;
        case 5: strKind = L"Friendly"; break;
        case 6: strKind = L"Dun_Boss"; break;
        case 7: strKind = L"Dun_Elite"; break;
        }
    }
    return strKind;
}

// @0x141a6b800
void UINpcCreateDialog::FUN_141a6b800()
{
    FUN_1401859c0(FUN_140166440(), 0xc, 0x13, L"ReadNpcAll");
    for (unsigned __int64 i = 0; i < m_files.FUN_14041af10(); i++) {
        CStringW strId = m_files.FUN_1405e99b0(i);
        FUN_14035e5b0(FUN_1406cd330(FUN_140718200(strId)));
    }
    FUN_1401859c0(FUN_140166440(), 0xc, 0x13, L"End ReadNpcAll");
}

// @0x141a6b8f0
void UINpcCreateDialog::FUN_141a6b8f0()
{
    m_entries.clear();
    m_entries.resize(m_files.FUN_14041af10());
    for (unsigned __int64 i = 0; i < m_files.FUN_14041af10(); i++) {
        CStringW strId = m_files.FUN_1405e99b0(i);
        unsigned nNpc = FUN_140718200(strId);
        Unk_NcHandle row = FUN_1406d6e90()->FUN_140a7cab0(nNpc);
        if (row.FUN_14109a230())
            continue;
        int bFriendly = row.FUN_140965990()->FUN_1406ccfc0();
        CStringW strKind = FUN_141a6b6a0(row.FUN_140965990()->m_nKind, bFriendly);
        CStringW strName = GetStringTable()->FUN_141811980(10, nNpc);
        CStringW strNpc = FUN_1401aa6a0(nNpc);
        CStringW strEmpty(L"");
        unsigned nHp = row.FUN_140965990()->FUN_140a7c970();
        unsigned short nLevel = row.FUN_140965990()->FUN_1406cd060();
        CStringW strLine = FUN_14028dfa0(CStringW(L"s_npccreate_render_name_format"), strKind, nLevel, strEmpty, nHp, strName, strNpc);
        unsigned short nLevel2 = row.FUN_140965990()->FUN_1406cd060();
        CStringW strSearch = FUN_14028dfa0(CStringW(L"s_npccreate_name_format"), strKind, nLevel2, strEmpty, strName, strNpc);
        if (row.FUN_140965990()->FUN_1406cd0d0() != 0) {
            int nShop = row.FUN_140965990()->FUN_1406cd0d0();
            strLine += FUN_140938ae0(CStringW(L"s_npccreate_add_shopid"), nShop);
            int nShop2 = row.FUN_140965990()->FUN_1406cd0d0();
            strSearch += FUN_140938ae0(CStringW(L"s_npccreate_add_shopid"), nShop2);
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
void UINpcCreateDialog::FUN_141a6be40(const CStringW& strFilterIn)
{
    CStringW& strFilter = const_cast<CStringW&>(strFilterIn);
    if (!m_bEntriesBuilt)
        FUN_141a6b8f0();
    FUN_140841420(strFilter);
    strFilter.Remove(L' ');
    MS2Ptr<Unk_NpcList> list = FUN_140c02900("m_npcList");
    if (list == 0)
        return;
    bool bFilter = !strFilter.IsEmpty();
    for (std::vector<Unk_NpcEntry>::iterator it = m_entries.begin(); it != m_entries.end(); ++it) {
        if (it->m_strId.IsEmpty())
            continue;
        if (bFilter && it->m_strSearch.Find(strFilter, 0) == -1 && it->m_strId.Find(strFilter, 0) == -1)
            continue;
        ASObj row(2);
        row.FUN_1407cbb20("code", it->m_strId);
        row.FUN_1407cbb20("field", it->m_strLine);
        ((Unk_NpcList*)list)->FUN_1422dd230(row);
    }
    ((Unk_NpcList*)list)->vfunc_24(true);
    m_strFilter = strFilter;
}

// @0x141a6dd40
void Unk_NpcFileList::FUN_141a6dd40()
{
    m_v.clear();
}

// Anchor for the UCRT header-inline memmove_s the range ends with (no caller in the exe's range).
void Unk_NcAnchor(void* pDst, const void* pSrc, size_t n)
{
    memmove_s(pDst, n, pSrc, n);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc0f90-0x142cc1020 .text$yd
