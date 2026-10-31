// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\scenestatemulti.cpp
// MS2-RANGE: 0x14174d380-0x141750f00 .text$mn
// MS2-RANGE: 0x140100540-0x140100720 .text$di
// MS2-RANGE: 0x142cb65f0-0x142cb6695 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVCSceneStateMulti@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVCSceneStateMulti@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x141750260 ; prop
// MS2-PIN: ??$?8PEAVUIServerListDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIServerListDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x1417502d0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCSceneStateMulti@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x141750460 ; unique
// MS2-PIN: ?TypeCast@CSceneStateMulti@@UEBA_NIPEAPEAX@Z 0x141750b90 ; unique
// MS2-PIN: ?TypeCast@CSceneStateMulti@@UEBA_NIPEAPEBX@Z 0x141750be0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCSceneStateMulti@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141750c90 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIServerListDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141750cf0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIServerListDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141750d80 ; unique
// MS2-PIN: ??$Call@VUIServerListDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIServerListDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIServerListDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x141750e00 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCSceneStateMulti@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141750e40 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIServerListDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141750ea0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVCSceneStateMulti@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x141750d50
// MS2-PIN: ??$Call@VCSceneStateMulti@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVCSceneStateMulti@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVCSceneStateMulti@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x141750dc0
// MS2-PIN: ??__Es_maintenanceExit@@YAXXZ 0x140100560
// MS2-PIN: ??__Es_skill@@YAXXZ 0x140100650
// MS2-PIN: ??__Es_stun@@YAXXZ 0x140100680
// MS2-PIN: ??__Fs_maintenanceExit@@YAXXZ 0x142cb65f0
// MS2-PIN: ??__Fs_skill@@YAXXZ 0x142cb6640
// MS2-PIN: ??__Fs_stun@@YAXXZ 0x142cb6660
// MS2-PIN: ?SetupClassInfo@CSceneStateMulti@@SAXPEAVClassInfo@efd@@_K@Z 0x141750a60
// MS2-PIN: ??B?$SmartPointer@VMyPC@@@efd@@QEBAPEAVMyPC@@XZ 0x141750620
// MS2-PIN: ??B?$SmartPointer@VUnk_LobbyActor@@@efd@@QEBAPEAVUnk_LobbyActor@@XZ 0x140965780
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestatemulti.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scenestatemulti.h"
#include "networkservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <NiColor.h>
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uimessagebox.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/client/ms2/uicharacterlistdialog.h"
#include "ms2/placeholder/cserverstring.h"
#include <efd/SmartPointer.h>
#include <efd/Helpers.h>
#include <efd/MemHint.h>
#include <efd/StdContainers.h>
#include <vector>
#include <new>

// ---- externs -----------------------------------------------------------------------------------------------------
class CMsgBoxData;
class UIServerListDialog;
class Unk_1401cd100 { public: Unk_1401cd100(void*); Unk_1401cd100(const Unk_1401cd100&); private: void* m_p; };
void FUN_141489ff0(void*, NiColorA);                    // the app's clear colour
void* FUN_140aae430();
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
void FUN_141275500();
void FUN_140930fe0(CInPacket&);
void* FUN_1408e57f0();
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1422b9fd0(int);
};
CNetworkService* FUN_140714f90();

// The world manager singleton (FUN_1403ed2d0): the lobby actor registry (a red-black map at +0xb8), the callback
// list and the camera/field requests. Names inferred.
class Unk_LobbyActor;
typedef ATL::CRBMap<unsigned long long, efd::SmartPointer<Unk_LobbyActor> > Unk_LobbyActorMap;
class Unk_FieldMgr
{
public:
    void FUN_141bbae40(IWorldServiceCallback* cb);          // register callback
    void FUN_141bbae80(IWorldServiceCallback* cb);          // unregister callback
    void FUN_141bbbe40(unsigned nMapId, int a, int b);           // move to a map
    void FUN_141bbbc60(Unk_1401cd100 id, int a);              // remove an actor
    void FUN_141bdb690();
    void* FUN_141bd0cc0();                                  // the player actor
    void FUN_141bd0cf0(void* pActor);
    int FUN_141bd3060();                                    // current map id
    char m_pad[0xb8];
    Unk_LobbyActorMap m_actors;                             // +0xb8
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    static class WorldService* GetInstance();
};

// ---- lobby dialogs and managers (names inferred) ----
class UIServerListDialog : public UIDialog
{
public:
    bool FUN_141ad3260(int, const CMsgBoxData&);
    void FUN_141ad2380();
    unsigned FUN_141ad1010();
};
void* FUN_14136f520(int);   // C3: was FUN_14136f520
class Unk_CharSelectDialog : public UICharacterListDialog
{
public:
    unsigned FUN_1418f1b90();
};
Unk_CharSelectDialog* FUN_140b72de0(int nId);
extern int DAT_1439f4a78;
extern int DAT_143ab285c;
extern int DAT_143ab2860;
extern unsigned DAT_143ab2830;
extern unsigned char DAT_143ab284b;
extern CString DAT_143ab2a48;
extern unsigned short DAT_143ab2848;
extern void (*DAT_143b03490)(short, unsigned char, const char*);
extern unsigned char DAT_1430c3b20;
extern unsigned char DAT_1430e3b20;

// Reconnect (same as CSceneStateMove::OnUpdate)
CString FUN_14016a600(const wchar_t*, int);
CStringW FUN_14062b4f0(CStringW, const int&);
CStringW FUN_1408116a0(int, const int&);
class UIObject* FUN_141540270(int);   // C3: was FUN_141540270
void FUN_141b6fcf0(const CStringW&, const CStringW&, int);

// Notify registry (as uidtattendpopup.cpp)
typedef Delegate<void(NotifyObject*)> Unk_NotifyDelegate;
class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10

// lobbyField.xml reading (as usercommandcli.cpp)
CString FUN_14071a5b0(const CString&, const CString&);
struct Unk_LobbyFiles { int FUN_1403974b0(TiXmlDocument&, const char*, int, bool, bool); };
class CFileSystem* GetFileSystem();   // C3: was FUN_140166420
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140168650 { public: Unk_140168650* FUN_140168650(const char*); };
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
int XmlQuery(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873890
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
unsigned char FUN_1401d1320(CCacheData*);

// ---- the pc preview ----
struct Unk_AllocHint
{
    Unk_AllocHint(const Unk_AllocHint&);                    // non-trivial: returned through a hidden pointer
    efd::MemHint m_hint;
};
Unk_AllocHint FUN_140876480(int nCategory);
class Unk_PCItems;
void* FUN_1401d7a50();
int FUN_140644bb0(void*, int);
class Unk_ItemSub;
class Unk_BackUpItem : public CPtred
{
public:
    MS2Ptr<Unk_ItemSub> FUN_1411dc7a0();                    // copy of the sub item at +0x20
};
class Unk_ItemSub : public CPtred
{
public:
    void FUN_140526b30(int);
};
void FUN_141653d10(MyPC*, MS2Ptr<Unk_ItemSub>);

// ---- packets / messages ----
struct Unk_1407a7d20
{
    Unk_1407a7d20(CInPacket&);
    ~Unk_1407a7d20();
    unsigned char m_kind;
    unsigned m_flags;
    CStringW m_text;
    int m_value;
    void *m_p1, *m_p2, *m_p3, *m_p4;
};
class Unk_TextFilter : public CServerStringGroup { };
class Unk_PatchTextOwner   // C3: member view for the former free stand-ins
{
public:
    class Unk_PatchTextFilter* FUN_140a87690();
};
CStringW FUN_14083d340(CStringW);
void FUN_141275400(CStringW&, int);
void FUN_1412753b0(CStringW&, int, int);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void* FUN_140aa6d30();
class CStateService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1417e25a0(int);
};
int FUN_1406516b0();
CStringW GetStringCommon(int);
CStringW FUN_1401ceea0(const wchar_t*, const int&);
UIMessageBox* FUN_14151f890();
const CStringW& FUN_141a02ce0(void*);   // CMsgBoxData::GetExtra: returns a reference in rax, no hidden slot
void FUN_141a01690(void*, const CStringW&, const CStringW&, const CStringW&);
void FUN_141a01660(void*, const CStringW&);
void FUN_141a027c0(void*, Delegate<bool(int, const CMsgBoxData&)>);
Unk_MessageBoxPtr FUN_140d73d20(int, CStringW, void*, CStringW);
void FUN_140d73c60(Unk_MessageBoxPtr);
void* FUN_140534fc0(const Unk_MessageBoxPtr&);
void* FUN_140534fe0(const Unk_MessageBoxPtr&);
bool FUN_1403b3c40(const CStringW&, const wchar_t*) throw();
bool FUN_140841300(const CStringW&, const char*);

class Unk_LobbyChar;
void FUN_1413fb630(void*, efd::vector<unsigned long long>&);
void* FUN_140a53610(void*);
#include "ms2/placeholder/notifygameeventchanged.h"
struct Unk_Settings { char m_pad[0xe258]; unsigned m_nLobbyMap; };
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
void* FUN_1401c0d90();
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/placeholder/termtagmanagercli.h"
#include "ms2/placeholder/gameeventmanagercli.h"
#include "ms2/client/ms2/equipment.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/uiloadingprogress.h"
__int64 GetServerTime();
// ---- the actor search (FUN_14174f0f0) ----
class Unk_LobbyScanner { public: void FUN_141b90e30(float* pfX, float* pfY); };   // cursor position inside the window
void* FUN_140aadf80();   // C3: was FUN_140aadf80
class Unk_QueryList { public: void* FUN_140a17e00(); unsigned FUN_140a17ea0(); void* FUN_140a17d70(unsigned); };
class Unk_QueryResult
{
public:
    ~Unk_QueryResult();                                     // 0x140a16120
    void* FUN_140a16c00();
    Unk_QueryResult* FUN_140a16c30();
    Unk_QueryList* FUN_140a17e00();
    void* m_p0;                                             // +0x00 the exe object is 8 bytes (FUN_140af0850 writes it through the sret slot)
};
struct Unk_140ae7ce0 { Unk_140ae7ce0(); float m_0, m_4, m_8, m_c, m_10, m_14, m_18, m_1c, m_20, m_24; };  // Unk_CameraSetting (cameramode.h): 0x28 bytes, 4-aligned; no array, so no /GS cookie
class Unk_QueryMgr : public CameraMgr
{
public:
    bool FUN_140aeb590(Unk_140ae7ce0*);
    void FUN_140aed720(Unk_140ae7ce0*);
    Unk_QueryResult FUN_140af0850(float fX, float fY, bool b1, bool b2, bool b3, void* p);   // pick at the cursor (cameramode.h)
};
class Unk_QueryRow { public: void* FUN_140a17cb0(); };

// ---- the game-option block (OnEnter) ----
struct Unk_C9B8B0 { void* m_0; void* m_8; };
struct Unk_AE6540 { bool m_0, m_1, m_2; };
class Unk_GameOptionA : public CGameOption { public: Unk_C9B8B0* FUN_140c9b8b0(); Unk_AE6540* FUN_140ae6540(); };

class Unk_1402a9d70
{
public:
    Unk_1402a9d70(int, float, float, float, int);               // 0x1402a9d70
    ~Unk_1402a9d70();                                           // 0x1402aa1d0
private:
    char m_pad[0x50];
};
MS2_CHECK_SIZE(Unk_1402a9d70, 0x50);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateMulti);

static CStringW s_maintenanceExit(L"maintenanceExit");
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static Unk_1401cd100 s_pointer(NULL);
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);

// @0x14174d380
// MS2-NOTE: job-code maps are keyed DWORD (hash 0x14015a330 family), not int
LobbyFieldTable::LobbyFieldTable()
    : m_selectMap(17, 0.75f, 0.25f, 2.25f, 10), m_createMap(17, 0.75f, 0.25f, 2.25f, 10), m_bLoaded(false)
{
}

// @0x14174d450
LobbyFieldTable::~LobbyFieldTable()
{
    Clear();
}

// @0x14174d4d0
int LobbyFieldTable::Load()
{
    if (FUN_1401d1320(this))
        Clear();
    if (m_bLoaded)
        return 1;
    m_bLoaded = true;
    CString strPath = FUN_14071a5b0("Table", "lobbyField.xml");
    CCacheData::FUN_1401d1160(strPath);
    TiXmlDocument doc;
    if (((struct Unk_LobbyFiles*)GetFileSystem())->FUN_1403974b0(doc, strPath, 0, true, false) != 0)
    {
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
            return 0;
        CString strKey("key");
        CString strJobCode("jobCode");
        CString strSelectMap("selectMap");
        CString strCreateMap("createMap");
        for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0(strKey); pNode != 0;
             pNode = reinterpret_cast<Unk_140165cf0*>(reinterpret_cast<Unk_140168650*>(pNode)->FUN_140168650(strKey)))
        {
            if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
                continue;
            int nJobCode = 0;
            XmlQuery((class TiXmlElement*)(pNode), strJobCode, nJobCode);
            if (nJobCode == 0)
                continue;
            int nSelectMap = 0;
            XmlGetAttr((class TiXmlElement*)(pNode), strSelectMap, *(unsigned int*)&static_cast<int&>(nSelectMap));
            int nCreateMap = 0;
            XmlGetAttr((class TiXmlElement*)(pNode), strCreateMap, *(unsigned int*)&static_cast<int&>(nCreateMap));
            m_selectMap.SetAt(nJobCode, nSelectMap);
            m_createMap.SetAt(nJobCode, nCreateMap);
            if (nCreateMap == 0)
                m_selectMaps.Add(nSelectMap);
        }
    }
    return 1;
}

// @0x14174d860
unsigned int LobbyFieldTable::GetSelectMap(int nJobCode)
{
    if (nJobCode == 0)
        nJobCode = 1;
    int nMap = 0;
    if (!m_selectMap.Lookup(nJobCode, nMap))
        m_selectMap.Lookup(1, nMap);
    return nMap;
}

// @0x14174d8d0
unsigned int LobbyFieldTable::GetCreateMap(int nJobCode)
{
    int nMap = 0;
    if (m_createMap.IsEmpty() || !m_createMap.Lookup(nJobCode, nMap))
        return GetRandomSelectMap();
    return nMap;
}

// @0x14174d940
void LobbyFieldTable::Clear()
{
    m_selectMap.RemoveAll();
    m_selectMaps.RemoveAll();
    m_createMap.RemoveAll();
    m_bLoaded = false;
}

// @0x14174d9a0
unsigned int LobbyFieldTable::GetRandomSelectMap()
{
    if (m_selectMaps.IsEmpty())
        return 0;
    size_t nCount = m_selectMaps.GetCount();
    size_t nIndex = (size_t)rand() % nCount;
    return m_selectMaps.GetAt(nIndex);
}

// @0x14174da20
CSceneStateMulti::CSceneStateMulti()
    : m_hPreviewPC(0), m_nMode(-1), m_nCreateMap(2), m_nJobCode(0), m_bReconnecting(0), m_nRetry(0)
{
}

// @0x14174db30
CSceneStateMulti::~CSceneStateMulti()
{
}

// @0x14174dbc0
CSceneStateMulti::BackUpCharacterInfo::BackUpCharacterInfo(MyPC* pPC)
    : m_items(10)
{
    if (pPC != 0)
    {
        m_nGender = ((class PC*)(class MyPC*)(pPC))->FUN_141658e60();
        for (int i = 0; i < 2; i++)
            m_equip[i] = *((struct Unk_CharEquip const*)&((class PC*)(class MyPC*)(pPC))->FUN_141659220(i));
        m_nJobCode = reinterpret_cast<PC*>(pPC)->FUN_141654700();
        m_n68 = reinterpret_cast<PC*>(pPC)->FUN_141654730();
        ATL::CAtlArray<MS2Ptr<Unk_BackUpItem> > tmp;
        reinterpret_cast<CEquipment*>(((class Unk_PCItems*)((class PC*)(class MyPC*)(pPC))->FUN_1416561a0()))->FUN_1411e1b80(*reinterpret_cast<ATL::CAtlList<MS2Ptr<CEquipItem>, ATL::CElementTraits<MS2Ptr<CEquipItem>>>*>(static_cast<ATL::CAtlList<MS2Ptr<Unk_BackUpItem>, ATL::CElementTraits<MS2Ptr<Unk_BackUpItem>>>*>(&m_items)));
    }
}

// @0x14174dd40
CSceneStateMulti::BackUpCharacterInfo::~BackUpCharacterInfo()
{
    m_items.RemoveAll();
}

// @0x14174dd90
void CSceneStateMulti::OnEnter(int nPrevState)
{
    CSceneStateBase::OnEnter(nPrevState);
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(CStringW(L"NotifyGameEventChanged"),
        Unk_NotifyDelegate(this, &CSceneStateMulti::FUN_14174ffb0));
    m_lobbyField.Load();
    FUN_141275500();
    ((class Unk_FieldMgr*)WorldService::GetInstance())->FUN_141bbae40(this);
    FUN_141489ff0(FUN_140aae430(), efd::ColorA::BLACK);
    if (nPrevState == 0x6200009)
        FUN_14174f4a0();
    m_timer.FUN_1408687f0();
    m_bReconnecting = 0;
    m_nRetry = 0;
    m_reconnectTimer.FUN_1408687f0();
    if (reinterpret_cast<CFeatureManager*>(((void*)FUN_140166410()))->FUN_14036e560())
    {
        reinterpret_cast<Unk_GameOptionA*>(TSingleton<CGameOption>::GetInstance())->FUN_140c9b8b0()->m_8 = 0;
        reinterpret_cast<Unk_GameOptionA*>(TSingleton<CGameOption>::GetInstance())->FUN_140ae6540()->m_0 = true;
        reinterpret_cast<Unk_GameOptionA*>(TSingleton<CGameOption>::GetInstance())->FUN_140ae6540()->m_1 = true;
        reinterpret_cast<Unk_GameOptionA*>(TSingleton<CGameOption>::GetInstance())->FUN_140ae6540()->m_2 = true;
        reinterpret_cast<Unk_GameOptionA*>(TSingleton<CGameOption>::GetInstance())->FUN_141243540();
    }
}

// @0x14174dff0
void CSceneStateMulti::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
    m_nMode = -1;
    reinterpret_cast<GameEventManagerCli*>(((void*)TSingleton<GameEventManagerCli>::GetInstance()))->Clear();
    reinterpret_cast<TermTagManagerCli*>(((void*)TSingleton<TermTagManagerCli>::GetInstance()))->Clear();
    FUN_14174fd00();
    ((class Unk_FieldMgr*)WorldService::GetInstance())->FUN_141bbae80(this);
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(CStringW(L"NotifyGameEventChanged"),
        Unk_NotifyDelegate(this, &CSceneStateMulti::FUN_14174ffb0));
}

// @0x14174e150
void CSceneStateMulti::OnUpdate(double fTime)
{
    CSceneStateBase::OnUpdate(fTime);
    if (m_bReconnecting)
    {
        if (m_nRetry < 5)
        {
            if (m_reconnectTimer.FUN_140868c00() != 0)
            {
                if (FUN_140714f90()->FUN_1415384e0() == 0)
                {
                    FUN_140714f90()->FUN_1415383a0(DAT_143ab2a48, DAT_143ab2848, 1, 1, 0);
                    m_nRetry = m_nRetry + 1;
                    CStringW text = FUN_14062b4f0(CStringW(L"s_reconnect_to_server"), m_nRetry);
                    void* loading = ((void*)FUN_141540270(0x3ed));
                    if (loading)
                        reinterpret_cast<UILoadingProgress*>(loading)->FUN_1419e0050(text);
                }
                m_reconnectTimer.FUN_140868750(10000);
            }
        }
        else if (m_nRetry == 5 && m_reconnectTimer.FUN_140868c00() != 0)
        {
            m_reconnectTimer.FUN_1408687f0();
            m_nRetry = 6;
            if (DAT_143b03490)
                DAT_143b03490(1, DAT_1430c3b20, efd::LogHelper(FUN_14016a600(FUN_1408116a0(0x20f, 7), 0)));
            FUN_140d86260()->vfunc_58(0x20f, 7);
            FUN_140d86260()->vfunc_63(false, m_nRetry, 7);
            {
                CStringW title(L"MS2");
                FUN_141b6fcf0(FUN_1408116a0(0x20f, 7), title, 0);
            }
            TerminateProcess(GetCurrentProcess(), 2);
        }
    }
    else
    {
        if (DAT_143ab285c != 0 && m_timer.FUN_140868c00() != 0)
        {
            m_timer.FUN_1408687f0();
            if (m_nMode == 0)
            {
                UIServerListDialog* pList = ((class UIServerListDialog*)FUN_14136f520(0x4ef0));
                if (pList != 0 && pList->FUN_1422dc2d0() != 0)
                    pList->FUN_141ad2380();
            }
            else if (m_nMode == 1 && DAT_143ab2860 == 3)
            {
                Unk_CharSelectDialog* pSelect = FUN_140b72de0(0x4ef1);
                if (pSelect != 0 && pSelect->FUN_1422dc2d0() != 0)
                    pSelect->FUN_1418f13f0();
            }
            FUN_140d86260()->vfunc_63(true, m_nRetry, 0);
        }
    }
}

// @0x14174e6b0
void CSceneStateMulti::OnPacket(CInPacket& packet)
{
    CSceneStateBase::OnPacket(packet);
    switch (packet.FUN_14070fe80())
    {
    case static_cast<int>(RecvOp::Notice):
        FUN_14174f4c0(packet);
        break;
    case static_cast<int>(RecvOp::WaitingTicketUpdate):
        OnWaitingTicketUpdate(packet);
        break;
    case static_cast<int>(RecvOp::GameEvent):
        reinterpret_cast<GameEventManagerCli*>(((void*)TSingleton<GameEventManagerCli>::GetInstance()))->Dispatch(packet);
        break;
    case static_cast<int>(RecvOp::TermTag):
        reinterpret_cast<TermTagManagerCli*>(((void*)TSingleton<TermTagManagerCli>::GetInstance()))->OnPacket(packet);
        break;
    case static_cast<int>(RecvOp::GameEventUserValue):
        FUN_140930fe0(packet);
        break;
    case static_cast<int>(RecvOp::SyncWorld):
        FUN_14174fcc0(packet);
        break;
    case static_cast<int>(RecvOp::EventReward):
        OnEventReward(packet);
    }
}

// @0x14174e880
void CSceneStateMulti::vfunc_1(int)
{
    ((class Unk_FieldMgr*)WorldService::GetInstance())->FUN_141bdb690();
    if (m_nMode == 2)
    {
        FUN_14174ec40(rand() % 2, true);
    }
    else if (m_nMode == 1)
    {
        Unk_CharSelectDialog* pSelect = FUN_140b72de0(0x4ef1);
        if (pSelect)
            pSelect->FUN_1418f1cb0();
        if (DAT_143ab285c != 0 && DAT_143ab2860 != 3)
        {
            DAT_143ab285c = 0;
            DAT_143ab284b = 0;
        }
    }
    if (reinterpret_cast<Unk_QueryMgr*>(TSingleton<CameraMgr>::GetInstance())->FUN_140a18070() != 0)
    {
        Unk_140ae7ce0 tmp;
        if (reinterpret_cast<Unk_QueryMgr*>(TSingleton<CameraMgr>::GetInstance())->FUN_140aeb590(&tmp))
        {
            reinterpret_cast<Unk_QueryMgr*>(TSingleton<CameraMgr>::GetInstance())->FUN_140aed720(&tmp);
            reinterpret_cast<Unk_QueryMgr*>(TSingleton<CameraMgr>::GetInstance())->FUN_140aed750(4, 1);
        }
    }
}

// @0x14174e980
void CSceneStateMulti::vfunc_4(int)
{
    if (DAT_1439f4a78 == 2)
    {
        m_bReconnecting = 1;
        m_nRetry = 0;
        m_reconnectTimer.FUN_140868750(10000);
        FUN_140714f90()->FUN_1415383a0(DAT_143ab2a48, DAT_143ab2848, 1, 1, 0);
    }
}

// @0x14174ea50
int CSceneStateMulti::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (!pMsg->FUN_1422e4520())
    {
        if (dynamic_cast<UIMessageBox*>(pSender))
        {
            int nResult = pMsg->FUN_1422b8a10();
            CStringW strTag = pMsg->FUN_1422b8f40();
            if (FUN_1403b3c40(strTag, L"waitingticketdialog")) {}  // empty body: the exe tests the result and does nothing
        }
    }
    return 0;
}

// @0x14174eaf0
int CSceneStateMulti::FUN_14174eaf0()
{
    return ((class Unk_FieldMgr*)WorldService::GetInstance())->FUN_141bd0cc0() != 0;
}

// @0x14174eb30
void CSceneStateMulti::FUN_14174eb30()
{
    FUN_14174fe40();
    reinterpret_cast<GameEventManagerCli*>(((void*)TSingleton<GameEventManagerCli>::GetInstance()))->Clear();
    reinterpret_cast<TermTagManagerCli*>(((void*)TSingleton<TermTagManagerCli>::GetInstance()))->Clear();
    ((class GFxSceneService*)(void*)(FUN_1408e57f0()))->FUN_1422b9fd0(0x620001a);
}

// @0x14174eb80
void CSceneStateMulti::FUN_14174eb80(int nJobCode)
{
    m_nJobCode = nJobCode;
    FUN_14174ff00();
    ((class GFxSceneService*)(void*)(FUN_1408e57f0()))->FUN_1422b9fd0(0x620001c);
}

// @0x14174ebc0
void CSceneStateMulti::FUN_14174ebc0()
{
    if (m_nMode == 0)
    {
        UIServerListDialog* pList = ((class UIServerListDialog*)FUN_14136f520(0x4ef0));
        if (pList)
            DAT_143ab2830 = pList->FUN_141ad1010();
    }
    else if (m_nMode == 1)
    {
        FUN_14174fea0();
    }
    m_nMode = 1;
    ((class GFxSceneService*)(void*)(FUN_1408e57f0()))->FUN_1422b9fd0(0x620001b);
}

// @0x14174ec40
void CSceneStateMulti::FUN_14174ec40(int nGender, bool bFlag)
{
    if (m_nMode != 2)
        return;
    FUN_14174fd00();
    efd::SmartPointer<MyPC> spPC(new (FUN_140876480(0).m_hint) MyPC());
    if (spPC.data())
    {
        reinterpret_cast<PC*>(spPC.operator->())->FUN_1416566d0(1);
        TCreateCharInfo info;
        info.FUN_14107ae00();
        info.m_nType = 3;
        info.m_nGender = nGender;
        info.m_nJobCode = m_nJobCode;
        info.m_n30 = FUN_140644bb0(FUN_1401d7a50(), m_nJobCode);
        info.m_b58 = bFlag;
        if (info.FUN_14107c3a0(reinterpret_cast<PC*>(spPC.operator MyPC*())))
            m_hPreviewPC = reinterpret_cast<GameObject*>(spPC.operator->())->FUN_14123c500();
    }
}

// @0x14174ee00
void CSceneStateMulti::FUN_14174ee00(BackUpCharacterInfo* pInfo)
{
    if (m_nMode != 2)
        return;
    FUN_14174fd00();
    efd::SmartPointer<MyPC> spPC(new (FUN_140876480(0).m_hint) MyPC());
    if (spPC.data())
    {
        reinterpret_cast<PC*>(spPC.operator->())->FUN_1416566d0(1);
        TCreateCharInfo info(3, pInfo->m_nGender);
        info.m_nJobCode = pInfo->m_nJobCode;
        info.m_n30 = pInfo->m_n68;
        for (int i = 0; i < 2; i++)
            info.m_equip[i] = pInfo->m_equip[i];
        if (info.FUN_14107b440(reinterpret_cast<PC*>(spPC.operator MyPC*())))
        {
            m_hPreviewPC = reinterpret_cast<GameObject*>(spPC.operator->())->FUN_14123c500();
            ATL::CAtlList<MS2Ptr<Unk_BackUpItem> >& items = pInfo->m_items;
            for (POSITION pos = items.GetHeadPosition(); pos != 0; items.GetNext(pos))
            {
                MS2Ptr<Unk_ItemSub> sub = items.GetAt(pos)->FUN_1411dc7a0();
                if (sub.get() != 0)
                {
                    sub->FUN_140526b30(reinterpret_cast<GameObject*>(spPC.operator->())->FUN_14123c580());
                    FUN_141653d10(spPC.operator->(), sub);
                }
            }
        }
    }
}

// @0x14174f0f0
Unk_LobbyChar* CSceneStateMulti::FUN_14174f0f0()
{
    float fMapX, fMapY;
    ((class Unk_LobbyScanner*)FUN_140aadf80())->FUN_141b90e30(&fMapX, &fMapY);
    if (reinterpret_cast<Unk_QueryMgr*>(TSingleton<CameraMgr>::GetInstance())->FUN_140a18070() == 0)
        return 0;
    Unk_QueryResult result = reinterpret_cast<Unk_QueryMgr*>(TSingleton<CameraMgr>::GetInstance())->FUN_140af0850(fMapX, fMapY, true, true, false, 0);
    if (result.FUN_140a16c00() == 0)
        return 0;
    Unk_FieldMgr* pMgr = ((class Unk_FieldMgr*)WorldService::GetInstance());
    for (unsigned iRow = 0; iRow < result.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17ea0(); iRow++)
    {
        Unk_QueryRow* pRow = static_cast<Unk_QueryRow*>(result.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17d70(iRow));
        for (POSITION pos = pMgr->m_actors.GetHeadPosition(); pos != 0; pMgr->m_actors.GetNext(pos))
        {
            Unk_LobbyActor* pActor = pMgr->m_actors.GetValueAt(pos);
            Unk_LobbyChar* pChar = static_cast<Unk_LobbyChar*>(FUN_140a53610(pActor));
            if (pChar == 0)
                continue;
            efd::vector<unsigned long long> ids;
            FUN_1413fb630(((void*)(reinterpret_cast<GameObject*>(pActor)->FUN_14123c410())), ids);
            for (unsigned iId = 0; iId < ids.size(); iId++)
            {
                if ((long long)pRow->FUN_140a17cb0() == (long long)ids.at(iId))
                    return pChar;
            }
        }
    }
    return 0;
}

// @0x14174f390
void CSceneStateMulti::FUN_14174f390(void* pActor, int)
{
    ((class Unk_FieldMgr*)WorldService::GetInstance())->FUN_141bd0cf0(pActor);
}

// @0x14174f3c0
int CSceneStateMulti::vfunc_15()
{
    return 1;
}

// @0x14174f3e0
unsigned int CSceneStateMulti::FUN_14174f3e0()
{
    int nJobCode = 0;
    Unk_CharSelectDialog* pSelect = FUN_140b72de0(0x4ef1);
    if (pSelect)
        nJobCode = pSelect->FUN_1418f1b90();
    return m_lobbyField.GetSelectMap(nJobCode);
}

// @0x14174f440
unsigned int CSceneStateMulti::FUN_14174f440()
{
    return m_lobbyField.GetCreateMap(m_nJobCode);
}

// @0x14174f470
void CSceneStateMulti::FUN_14174f470()
{
    m_timer.FUN_140868750(1000);
}

// @0x14174f4a0
void CSceneStateMulti::FUN_14174f4a0()
{
    FUN_14174fe40();
}

// @0x14174f4c0
void CSceneStateMulti::FUN_14174f4c0(CInPacket& packet)
{
    Unk_1407a7d20 info(packet);
    int nKind = info.m_kind;
    if (nKind == 4)
    {
        unsigned nFlags = info.m_flags;
        CStringW text(info.m_text);
        text = ((class Unk_TextFilter*)((class Unk_PatchTextOwner*)(class Unk_TextFilter*)(reinterpret_cast<Unk_TextFilter*>(TSingleton<CServerString>::GetInstance())))->FUN_140a87690())->GetString(text);
        int nValue = info.m_value;
        text = FUN_14083d340(CStringW(text));
        if ((nFlags & 4) != 0 || (nFlags & 0x40) != 0)
        {
            FUN_140d73aa0(CStringW(text), 0, 0, CStringW(L""));
        }
        else if ((nFlags & 0x80) != 0)
        {
            FUN_140d73aa0(CStringW(text), 0, 0, CStringW(s_maintenanceExit));
            FUN_140d86260()->vfunc_58(0x289, 0);
        }
        else if ((nFlags & 0x10) != 0)
        {
            FUN_1412753b0(text, 9, nValue);
        }
        else if ((nFlags & 0x200) != 0)
        {
            int nRead = packet.ReadInt32();
            FUN_141275400(text, nRead);
        }
    }
    else if (nKind == 5)
    {
        unsigned nFlags = info.m_flags;
        CStringW text(info.m_text);
        if ((nFlags & 4) != 0 || (nFlags & 0x40) != 0)
        {
            FUN_140714f90()->FUN_1415388a0();
            ((class CStateService*)(void*)(FUN_140aa6d30()))->FUN_1417e25a0(0x6200009);
            FUN_140d73aa0(CStringW(text), 0, 0, CStringW(L""));
        }
    }
}

// @0x14174f8d0
void CSceneStateMulti::OnWaitingTicketUpdate(CInPacket& packet)
{
    if (FUN_1406516b0() == 3)
    {
        UIServerListDialog* pList = ((class UIServerListDialog*)FUN_14136f520(0x4ef0));
        if (pList != 0)
            pList->vfunc_8(1);
    }
    int nWaiting = packet.ReadInt32();
    CStringW text = FUN_1401ceea0(GetStringCommon(0xac0), nWaiting);
    UIMessageBox* pBox = FUN_14151f890();
    if (pBox != 0)
    {
        Unk_MessageBoxPtr current = pBox->FUN_1419f8470();
        if (FUN_140534fc0(current) != 0)
        {
            if (FUN_1403b3c40(FUN_141a02ce0(FUN_140534fe0(current)), L"waitingticketdialog"))
            {
                pBox->FUN_1419f8370(text);
                return;
            }
        }
    }
    Unk_MessageBoxPtr box = FUN_140d73d20(0, CStringW(text), 0, CStringW(L""));
    FUN_141a01690(FUN_140534fe0(box), GetStringCommon(0xac1), L"", L"");
    FUN_141a01660(FUN_140534fe0(box), L"waitingticketdialog");
    UIServerListDialog* pList = ((class UIServerListDialog*)FUN_14136f520(0x4ef0));
    if (pList != 0)
        FUN_141a027c0(FUN_140534fe0(box), Delegate<bool(int, const CMsgBoxData&)>(pList, &UIServerListDialog::FUN_141ad3260));
    FUN_140d73c60(Unk_MessageBoxPtr(box));
}

// @0x14174fcc0
void CSceneStateMulti::FUN_14174fcc0(CInPacket& packet)
{
    ((class Unk_OSInput*)&static_cast<class CInputStream&>(packet))->Read8(*(unsigned __int64*)(&m_nServerTime));
}

// @0x14174fd00
void CSceneStateMulti::FUN_14174fd00()
{
    if (m_hPreviewPC != 0)
        ((class Unk_FieldMgr*)WorldService::GetInstance())->FUN_141bbbc60(Unk_1401cd100(reinterpret_cast<void*>(m_hPreviewPC)), 0);
    m_hPreviewPC = 0;
}

// @0x14174fd70
int CSceneStateMulti::FUN_14174fd70()
{
    return ((class Unk_FieldMgr*)WorldService::GetInstance())->FUN_141bd3060() == 1;
}

// @0x14174fdb0
bool CSceneStateMulti::FUN_14174fdb0()
{
    if (m_nServerTime == 0)
        return false;
    CMsTime serverTime(m_nServerTime);
    CMsTime now(GetServerTime());
    return serverTime.GetMonth() == now.GetMonth();
}

// @0x14174fe40
void CSceneStateMulti::FUN_14174fe40()
{
    if (m_nMode != 0)
    {
        if (!FUN_14174fd70())
            ((class Unk_FieldMgr*)WorldService::GetInstance())->FUN_141bbbe40(1, 1, 0);
    }
    m_nMode = 0;
}

// @0x14174fea0
void CSceneStateMulti::FUN_14174fea0()
{
    unsigned nMap = FUN_14174ff70();
    if (nMap == 0)
        nMap = FUN_14174f3e0();
    ((class Unk_FieldMgr*)WorldService::GetInstance())->FUN_141bbbe40(nMap, 1, 0);
    m_nMode = 1;
}

// @0x14174ff00
void CSceneStateMulti::FUN_14174ff00()
{
    unsigned nMap = FUN_14174ff70();
    if (nMap == 0)
        nMap = FUN_14174f440();
    m_nCreateMap = nMap;
    ((class Unk_FieldMgr*)WorldService::GetInstance())->FUN_141bbbe40(nMap, 1, 0);
    m_nMode = 2;
}

// @0x14174ff70
unsigned int CSceneStateMulti::FUN_14174ff70()
{
    if (FUN_14174fdb0())
        return ((struct Unk_Settings*)FUN_1401d3200())->m_nLobbyMap;
    return reinterpret_cast<CGameRule*>(FUN_1401c0d90())->FUN_14047b9b0();
}

// @0x14174ffb0
void CSceneStateMulti::FUN_14174ffb0(NotifyObject* pNotify)
{
    if (m_nMode == 0)
        return;
    NotifyGameEventChanged* pEvent = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (pEvent != 0 && FUN_140841300(pEvent->m_eventName, "LobbyMap"))
    {
        if (m_nMode == 1)
            FUN_14174fea0();
        else if (m_nMode == 2)
            FUN_14174ff00();
    }
}

// @0x141750050
void CSceneStateMulti::OnEventReward(CInPacket& packet)
{
    unsigned char cKind = packet.ReadUInt8();
    if (cKind == 0x10)
    {
        Unk_CharSelectDialog* pSelect = FUN_140b72de0(0x4ef1);
        if (pSelect != 0)
            pSelect->FUN_1418ed6b0(packet);
    }
}

// Look-alike pairs (fx24): s_pointer's initializer vs the egf header's kENTITY_INVALID one; vector<unsigned __int64>::_Xrange
// (byte-identical to every _Xrange; this TU's copy is in range).
// MS2-PIN: ??__Es_pointer@@YAXXZ 0x1401006b0
// MS2-PIN: ?_Xrange@?$vector@_KV?$allocator@_K@std@@@std@@CAXXZ 0x141750c30
