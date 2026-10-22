// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uimessagebox.cpp.
//
// UIMessageBox: the HUD layer that shows the CMsgBoxData queue one box at a time (uimessageboxdata.h) and runs the
// result handlers of the tagged boxes (FUN_1419f9ba0: plain tags, FUN_1419fa910: "tag,arg" tags).
// MS2-UNIT: client\ms2\uimessagebox.cpp
// MS2-RANGE: 0x1419f71e0-0x141a00db0 .text$mn
// MS2-RANGE: 0x1401167a0-0x1401174d0 .text$di
// MS2-RANGE: 0x142cbf5d0-0x142cbfe15 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?IsNull@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEBA_NXZ 0x141a00c60 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimessagebox.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <shellapi.h>
#include <vector>
#include "uimessagebox.h"
#include "uimessageboxdata.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/networkservice.h"
#include "ms2/client/ms2/tabcontentspetevolution.h"
#include "ms2/client/ms2/uiattendgiftdialog.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/petsystemtabcontents.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/state.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di): the box tags, in the exe's initializer order ----
static CStringW s_143af3c68=L"alreadyReconnect";
static CStringW s_143af3c78=L"autoExternalBlock";
static CStringW s_143af3d78=L"changeCharName";
static CStringW s_143af3d88=L"changeGuildName";
static CStringW s_143af3d80=L"changeInvalidCharName";
static CStringW s_143af3d30=L"bannerClose";
static CStringW s_143af3cd8=L"composeBindPet";
static CStringW s_143af3ca8=L"confirmChangeCharName";
static CStringW s_143af3c38=L"confirmCommend";
static CStringW s_143af3da0=L"currency_overflow_ask";
static CStringW s_143af3c98=L"destroy_item";
static CStringW s_143af3db0=L"destroy_doll_item";
static CStringW s_143af3da8=L"destroy_store_item";
static CStringW s_143af3cc0=L"drop";
static CStringW s_143af3ce0=L"evolutionBindPet";
static CStringW s_143af3c70=L"externalBlock";
static CStringW s_143af3c20=L"forcelogin";
static CStringW s_143af3ba8=L"gameexit";
static CStringW s_143af3c00=L"groupEdit";
static CStringW s_143af3c10=L"groupExit";
static CStringW s_143af3c08=L"groupList";
static CStringW s_143af3c48=L"guildArenaJoin";
static CStringW s_143af3c40=L"guildinvite";
static CStringW s_143af3c50=L"individualArenaJoin";
static CStringW s_143af3cb8=L"itemlock_confirm";
static CStringW s_143af3ca0=L"learn_emotion";
static CStringW s_143af3c88=L"learn_skill";
static CStringW s_143af3c60=L"maintenanceExit";
static CStringW s_143af3d90=L"openMassive";
static CStringW s_143af3c28=L"partyinvite";
static CStringW s_143af3bf8=L"rankArenaJoin";
static CStringW s_143af3c30=L"recallconfirm";
static CStringW s_143af3cb0=L"recallscrollconfirm";
static CStringW s_143af3cf8=L"remakeOptionBindPet";
static CStringW s_143af3d00=L"remakeOptionScrollBindPet";
static CStringW s_143af3c58=L"requestTradeEx";
static CStringW s_143af3d40=L"coupleDanceRequest";
static CStringW s_143af3d28=L"coupleEmotion";
static CStringW s_143af3d38=L"rpsGameRequest";
static CStringW s_143af3cc8=L"sell";
static CStringW s_143af3d70=L"sellconfirm";
static CStringW s_143af3c18=L"startbypass";
static CStringW s_143af3cf0=L"studyBindPet";
static CStringW s_143af3cd0=L"summonBindPet";
static CStringW s_143af3d58=L"swapstorein-";
static CStringW s_143af3d60=L"swapstoreout-";
static CStringW s_143af3d68=L"tradein";
static CStringW s_143af3ce8=L"trainingBindPet";
static CStringW s_143af3c80=L"unlockcash";
static CStringW s_143af3c90=L"use_function_item";
static CStringW s_143af3d98=L"use_function_item_ask";
static CStringW s_143af3d48=L"usestorein";
static CStringW s_143af3d50=L"usestoreout";
static CStringW s_143af3d18=L"useBindEquipItem";
static CStringW s_143af3d10=L"useBindFuncItem";
static CStringW s_143af3d20=L"useBindGemEquipItem";
static CStringW s_143af3d08=L"useBindItemSkill";
#include "ms2/placeholder/header_statics_a.h"

static UICommon::CMyPCKeyInputController s_keys;
static CString s_close = "dialog_close";                       // the close sound event
static CString s_warning = "system_notice_error_warningBag";
#ifdef MS2_HOOK_DLL
extern Unk_MessageBoxStatic g_messageBoxState;                  // 0x143af3df8 the remembered modaless box position
#else
// @0x140117450
Unk_MessageBoxStatic g_messageBoxState;
#endif
static CString s_index = "index";
static CString s_label = "label";

// ---- callees (unit-local views) ----
class ASDialog : public ASDisplayObject {};
// The message box root clip: ASGameEntity with the movie-clip slots after ASDisplayObject's.
class Unk_MessageBoxEntity : public ASGameEntity
{
public:
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();                                    // gotoAndStop the top layer
};
// UIMsg (ASData + the message type, 0x50): ctor 0x1422e44d0, dtor 0x140c30570.
class Unk_MessageBoxMsg : public ASData
{
public:
    Unk_MessageBoxMsg(int nType);
    virtual ~Unk_MessageBoxMsg();
    int m_nType;                                                // +0x48
};
MS2_CHECK_SIZE(Unk_MessageBoxMsg, 0x50);

class Unk_MessageBoxKeys
{
public:
    bool FUN_14116d890(unsigned char bEnter);
    bool FUN_14116d840();
    bool FUN_14116d9c0(int nKey, int a, int b);
    bool FUN_14116dd30(int nPad, int a, int b);
};
Unk_MessageBoxKeys* FUN_14025e7c0();
void FUN_141901470(int bBlock, int nUiId);
void FUN_141901390(int bBlock, int nUiId);
void FUN_1419013c0(int bBlock, int nUiId);
int FUN_14151f8b0();
int FUN_14151f9c0();
void FUN_141276180(const CString& strEvent, const CString& strArg);   // play a UI sound
void FUN_1418fe1c0(const CString& strUrl);                            // open a web page

// The message box queue (uimessageboxdata.cpp's callers).
void FUN_14151f200();                                           // show the next queued box
void FUN_14151f720(MS2Ptr<CMsgBoxData> spData);
int FUN_14151f6e0();
MS2Ptr<CMsgBoxData> FUN_14151f820();
UIMessageBox* FUN_14151f890();
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spData);
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
CStringW FUN_14028de60(int nId);                                // string table text
CStringW FUN_14028b8e0(const CStringW& strKey);                 // the "s_..." key text
CStringW FUN_14052bd00(int nId, const CStringW& strArg);        // formatted string table text
void FUN_1412751f0(const CStringW& strText, int nA, int nB);     // system message
void FUN_141275260(int nId, int nA, int nB);
int FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szDelim, int nMax);
bool FUN_1407183f0(const CStringW& str);                        // "1", "o" or "t"
__time64_t FUN_140869440();

class Unk_MessageBoxSound { public: virtual void vfunc_0(); virtual void vfunc_1(int nUiId); };
Unk_MessageBoxSound* FUN_14140ea40();
UIBannerAdvertisingDialog* FUN_141876420(int nId);
MS2Ptr<ASDialog> FUN_140e43fe0(int nMovieId, const Scaleform::GFx::Value& v);

class Unk_MessageBoxPeer { public: void FUN_1410356f0(); };
Unk_MessageBoxPeer* FUN_140b04f80(int nId);
class Unk_MessageBoxPlayer { public: void FUN_1413b74f0(int bAccept); void FUN_1413bc050(); };
Unk_MessageBoxPlayer* FUN_1403ed290();
class Unk_MessageBoxSocket
{
public:
    void FUN_1415382c0();
    void FUN_1415388a0();                                       // disconnect
    void FUN_141538930(__int64 nUid, int nCount);               // drop
    void FUN_1415389b0(__int64 nUid);                           // destroy
    void FUN_141538a20(__int64 nUid);                           // destroy a storage item
    void FUN_141538a90(__int64 nSlot, __int64 nUid);            // destroy a fitting doll item
    void FUN_141538b10(int bAccept);
};
Unk_MessageBoxSocket* FUN_140714f90();
class Unk_MessageBoxTrade { public: void FUN_14185b8e0(__int64 nId, int bAccept); void FUN_14185b9d0(__int64 nUid, int nCount, int nSlot); };
Unk_MessageBoxTrade* FUN_14140ea30();
void FUN_1416a0e70();
extern int DAT_143ab2858;                                       // nonzero: the login dialog is the front end
extern bool DAT_143ab2942;

class UISceneEntity { public: virtual ~UISceneEntity(); };
class UISceneLogin : public UISceneEntity { public: void FUN_141acf470(); };
class Unk_MessageBoxScene { public: int FUN_1422b9dc0(); int FUN_1422b9e00(); UISceneEntity* FUN_1422b9e80(); };
Unk_MessageBoxScene* FUN_1408e57f0();
class Unk_MessageBoxSceneFlags { public: int FUN_1417e25a0(int nScene); };
Unk_MessageBoxSceneFlags* FUN_140aa6d30();

class Unk_MessageBoxUI
{
public:
    void FUN_141adc5d0(int nId);                                // close
    void FUN_141adc750(int nId);                                // open
    int FUN_141adc940(int nId);
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
};
Unk_MessageBoxUI* FUN_1403ed2b0();
template <class T> inline T* Unk_MessageBoxDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>(p.operator->());
    }
    return 0;
}
class UILoginDialog : public UIDialog { public: void FUN_1419e2310(int n); };
class UIItemRemakeScrollDialog : public UIDialog { public: void FUN_140f59ad0(__int64 nUid, int n); };
class Unk_MessageBoxGuideDialog : public UIDialog { public: void FUN_1418dfb30(int nId, int nType, int nLayer); int FUN_1418dfc40(); };
Unk_MessageBoxGuideDialog* FUN_140ff7030(int nId);
class Unk_MessageBoxWeb { public: void FUN_141b794e0(CString& strOut, const char* szPage); };
Unk_MessageBoxWeb* FUN_140cc18a0();
class Unk_MessageBoxWindow { public: HWND FUN_14209c720(); };
Unk_MessageBoxWindow* FUN_140aadf80();
class Unk_MessageBoxParty { public: void FUN_14162b950(int nResult); };
Unk_MessageBoxParty* FUN_1409670d0();
class Unk_MessageBoxArena { public: void FUN_141280d40(); };
Unk_MessageBoxArena* FUN_140f97ef0();
class Unk_MessageBoxItemLock { public: void FUN_140612e10(); };
extern Unk_MessageBoxItemLock* DAT_143aaf308;
inline Unk_MessageBoxItemLock* FUN_140535310() { return DAT_143aaf308; }
class Unk_MessageBoxFeature { public: bool FUN_14036d570(int nId); };
Unk_MessageBoxFeature* FUN_140166410();
class Unk_MessageBoxShutdown { public: int FUN_1402c4c90(int nId); };
class Unk_MessageBoxContents { public: void* m_0; Unk_MessageBoxShutdown m_shutdown; };
Unk_MessageBoxContents* FUN_14025e7b0();
class Unk_MessageBoxFilter : public CPtred { public: bool FUN_140225720(const CStringW& str, CStringW& strOut); };
class Unk_MessageBoxFilters { public: MS2Ptr<Unk_MessageBoxFilter> FUN_140229a50(); };
Unk_MessageBoxFilters* FUN_14025e7d0();
class Unk_MessageBoxNameDialog : public UIDialog { public: void FUN_1418f2030(__int64 nUid, const CStringW& strName); void FUN_1418f20d0(); };
Unk_MessageBoxNameDialog* FUN_140b72de0(int nId);
class Unk_MessageBoxTradeDialog : public UIDialog { public: int FUN_141b283f0(int* pSlot); };
Unk_MessageBoxTradeDialog* FUN_14140e820(int nId);
void FUN_141404930(__int64 nUid);
void FUN_141425fc0(__int64 nUid, unsigned int nCount, CItem* pItem);  // sell
void FUN_1409e4950(MS2Ptr<CItem> spItem, CStringW& strOut, bool& bOut);
void FUN_140961010(int nId, int nA, int nB, CStringW strArg);
class Unk_MessageBoxSlots { public: CStringW FUN_141813300(int nSlot); };
Unk_MessageBoxSlots* FUN_1401a9d70();
int FUN_141276a30(const CStringW& strName, CStringW& strError);  // validate a character name
void FUN_140b845a0(__int64 nId, unsigned int nEmotion);
int FUN_1416764d0(PC* pPlayer);                                 // riding
int FUN_14166c930(PC* pPlayer);
int FUN_14123c580(void* pActor);                                // the object id
int FUN_14053dc20(Unk_ItemEquipData* pData);
unsigned short FUN_14053dc40(Unk_ItemEquipData* pData);
void FUN_140d1bd60(MS2Ptr<CItem> spItem, int n);
void FUN_141271960(MS2Ptr<CItem> spItem, int nSlot, int n);
bool FUN_140930b10();
void* FUN_140966da0(ATL::CAtlArray<void*>& arr);

class Unk_MessageBoxGameOption { public: char m_pad_00[0x10]; __time64_t m_nFuncItemAsk; __time64_t m_nCurrencyAsk; };
class Unk_MessageBoxGameOptions { public: void FUN_141243540(); Unk_MessageBoxGameOption* FUN_140c9b8b0(); };
Unk_MessageBoxGameOptions* FUN_1409a8b10();

// Game constants table slots (0x58 bytes each, FUN_1401d7c10 / FUN_1402056b0 / FUN_140298f80 read the value).
struct Unk_MessageBoxConstSlot { char m_pad_00[0x58]; };
struct Unk_MessageBoxConsts
{
    char m_pad_00[0xc130];
    Unk_MessageBoxConstSlot m_sellConfirmPrice;                 // +0xc130
    char m_pad_c188[0xd2f8 - 0xc188];
    Unk_MessageBoxConstSlot m_guideUrl;                         // +0xd2f8
    char m_pad_d350[0x8];
    Unk_MessageBoxConstSlot m_guideId;                          // +0xd358
};
MS2_CHECK_OFFSET(Unk_MessageBoxConsts, m_guideId, 0xd358);
Unk_MessageBoxConsts* FUN_1401d3200();
const unsigned int* FUN_1401d7c10(const Unk_MessageBoxConstSlot* pSlot);
const int* FUN_1402056b0(const Unk_MessageBoxConstSlot* pSlot);
const CString* FUN_140298f80(const Unk_MessageBoxConstSlot* pSlot);

// Item sound transform (NiTransform: rotate, translate, scale).
struct Unk_MessageBoxPt3 { float x, y, z; };
struct Unk_MessageBoxRot { float m[3][3]; };
struct Unk_MessageBoxXform
{
    Unk_MessageBoxRot m_rotate;                                 // +0x00
    Unk_MessageBoxPt3 m_translate;                              // +0x24
    float m_fScale;                                             // +0x30
};
MS2_CHECK_SIZE(Unk_MessageBoxXform, 0x34);

void FUN_140a332d0(Unk_MessageBoxXform* p);                     // NiTransform default ctor
void FUN_14027dcf0(Unk_MessageBoxPt3* pDst, const NiPoint3& src);   // NiPoint3 from efd::Point3
void FUN_14097faa0(Unk_MessageBoxPt3* pDst, const Unk_MessageBoxPt3* pSrc);   // NiPoint3::operator=
void FUN_140a33240(Unk_MessageBoxRot* pDst, const Unk_EfdMatrix3* pSrc);   // NiMatrix3 from efd::Matrix3
extern Unk_EfdMatrix3 DAT_143a09600;                  // identity rotation
class Unk_MessageBoxItemSound { public: CString FUN_140559750(); };
Unk_MessageBoxItemSound* FUN_140281980();
class Unk_MessageBoxEffects
{
public:
    void FUN_1411a5110(CString strPath, CString strName, CString strBone, int a, Unk_MessageBoxXform* pXform, float fScale, int b);
};
Unk_MessageBoxEffects* FUN_1403ed280();

// The skill a bound item casts (avatarpc.cpp / inventory.cpp layout).
struct Unk_InventorySkillRequest {
    Unk_InventorySkillRequest(int, unsigned short);
    int skill;
    unsigned short level;
    unsigned __int64 tick;
    unsigned serial, unknown14;
    float origin[3], direction[3];
    unsigned unknown30, unknown34;
    bool remap, suppressDispatch, itemUse;
    __int64 item;
};
MS2_CHECK_SIZE(Unk_InventorySkillRequest, 0x48);
class Unk_InventorySkillLevel : public CPtred {};
class Unk_MessageBoxSkillTable { public: MS2Ptr<Unk_InventorySkillLevel> FUN_1407ee2f0(int nSkill, unsigned short nLevel); };
Unk_MessageBoxSkillTable* FUN_1401958b0();
bool FUN_140804450(Unk_InventorySkillLevel* p);
class CSkillRecord : public CPtred
{
public:
    char m_pad_18[0x94];
    bool m_bItemSkill;                                          // +0xac
    char m_pad_ad[0x113];
};
MS2_CHECK_OFFSET(CSkillRecord, m_bItemSkill, 0xac);
MS2_CHECK_SIZE(CSkillRecord, 0x1c0);
class Unk_MessageBoxSkills { public: MS2Ptr<CSkillRecord> FUN_141765570(Unk_InventorySkillRequest& req); };
class StateMicroGameRpsData : public StateData
{
public:
    StateMicroGameRpsData(int nTarget);                         // 0x1417c1520
    char m_pad_18[0x18];
};
MS2_CHECK_SIZE(StateMicroGameRpsData, 0x30);
class StateMicroGameCoupleDanceData : public StateData
{
public:
    StateMicroGameCoupleDanceData(int nTarget);                 // 0x1417c1830
    char m_pad_18[0x10];
};
MS2_CHECK_SIZE(StateMicroGameCoupleDanceData, 0x28);
class Unk_MessageBoxActor { public: __int64 FUN_141656a80(); };   // the character id
class Unk_MessageBoxPC : public PC
{
public:
    Unk_MessageBoxSkills* FUN_141523bc0();
    void FUN_14152aa90(MS2Ptr<CItem> spItem, int n);            // summon a pet
    void FUN_14152c280(RideOffAction* pAction);
    CItem* FUN_14152efa0(__int64 nUid, __int64* pSlot);         // a fitting doll item
    class Unk_MessageBoxSkillBook* FUN_1416546d0();
};
class Unk_MessageBoxSkillBook { public: void FUN_140a6e140(__int64 nUid, int nItemId, unsigned short nSkill); };
class Unk_MessageBoxPortal : public CPtred
{
public:
    char m_pad_18[0x160];
    CStringW m_strName;                                         // +0x178
};
MS2_CHECK_OFFSET(Unk_MessageBoxPortal, m_strName, 0x178);
class Unk_MessageBoxWorld
{
public:
    MS2Ptr<Unk_MessageBoxPortal> FUN_141bc2800(int nId);
    void FUN_141bc2980(std::vector<int>& ids);
    void FUN_141bc2c90(const NiPoint3& pos, ATL::CAtlArray<void*>& out);
    Unk_MessageBoxPC* FUN_141bd0cc0();                          // the local player
    Unk_MessageBoxActor* FUN_141bd1420(CStringW strName);
    Unk_MessageBoxActor* FUN_141bd1530(__int64 nId);
};
Unk_MessageBoxWorld* FUN_1403ed2d0();
extern Unk_Inventory DAT_143ab2a90;
class Unk_MessageBoxStore
{
public:
    MS2Ptr<CItem> FUN_140de1490(__int64 nUid);
    void FUN_140de2dc0(__int64 nUid, int nSlot, int nCount, MS2Ptr<CItemData> spData);   // put in
    void FUN_140de31f0(__int64 nUid, int nSlot, int nCount, MS2Ptr<CItemData> spData);   // take out
};
extern Unk_MessageBoxStore DAT_143ab2d80;
class TabContentsPetCompose : public PetSystemTabContents { public: void FUN_140cb48a0(int bUsePoint); };
class TabContentsPetRemakeOption : public PetSystemTabContents { public: void FUN_140b95280(int bUsePoint); };
class Unk_MessageBoxPetDialog : public UIDialog { public: MS2Ptr<PetSystemTabContents> FUN_140e746c0(); };
Unk_MessageBoxPetDialog* FUN_140b99ba0(int nId);
class Unk_MessageBoxTrainingDialog : public UIDialog { public: void FUN_140e57d60(); };
Unk_MessageBoxTrainingDialog* FUN_140d276c0(int nId);

// @0x141a00840
template <> inline bool Delegate<bool(int, const CMsgBoxData&)>::operator==(const Delegate& o) const
{
    if (m_pImpl == 0 && o.m_pImpl == 0)
        return true;
    if (m_pImpl == 0 || o.m_pImpl == 0)
        return false;
    return m_pImpl->vfunc_3(o.m_pImpl);
}

// @0x1419f71e0
UIMessageBox::UIMessageBox() : m_count(0), m_layer(4), m_closing(0), m_data(0)
{
    m_58 = 0;
    m_2c = 25;
    m_layer = 0;
    FUN_1422dc3b0(1);
}

// @0x1419f72a0
UIMessageBox::~UIMessageBox()
{
    m_data = 0;
}

// @0x1419f7320
void UIMessageBox::vfunc_2()
{
    UIHeadUpDisplay::vfunc_2();
}
MS2_REPLACE_METHOD(0x1419F7320, UIMessageBox, vfunc_2, 24, 0xB4310325);

// @0x1419f7340
void UIMessageBox::vfunc_3()
{
    m_count = 0;
    m_data = 0;
    UIHeadUpDisplay::vfunc_3();
}
MS2_REPLACE_METHOD(0x1419F7340, UIMessageBox, vfunc_3, 57, 0x7379E71C);

// @0x1419f7380
CString UIMessageBox::vfunc_1()
{
    return "MessageBox";
}
MS2_REPLACE_METHOD(0x1419F7380, UIMessageBox, vfunc_1, 61, 0xEE6CD44A);

// @0x1419f73d0
void UIMessageBox::vfunc_8(int bVisible)
{
    vfunc_47(bVisible == 0);
    MS2Ptr<ASDisplayObject> root(dynamic_cast<ASDisplayObject*>(static_cast<AScript*>(m_30)));
    if (root.get())
        root->vfunc_3(bVisible);
}
MS2_REPLACE_METHOD(0x1419F73D0, UIMessageBox, vfunc_8, 199, 0xAD059E8F);

// @0x1419f74a0
void UIMessageBox::vfunc_43()
{
    MS2Ptr<ASGameEntity> root(dynamic_cast<ASGameEntity*>(static_cast<AScript*>(m_30)));
    if (root.get())
        static_cast<Unk_MessageBoxEntity*>(root.operator->())->vfunc_25();
}
MS2_REPLACE_METHOD(0x1419F74A0, UIMessageBox, vfunc_43, 146, 0xAE8947D0);

// @0x1419f7540
void UIMessageBox::OnLoadComplete()
{
    UIObject::OnLoadComplete();
}
MS2_REPLACE_METHOD(0x1419F7540, UIMessageBox, OnLoadComplete, 24, 0x9B1A4878);

// @0x1419f7560
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
int UIMessageBox::vfunc_13()
{
    if (FUN_1419f8270())
        return 0;
    if (m_data.IsNull() || m_30.IsNull())
        FUN_1419f8170(0);
    CString method = "";
    bool enter = m_data->FUN_141a030b0();
    if (FUN_14025e7c0()->FUN_14116d890(static_cast<unsigned char>(enter)))
    {
        if (!m_data->FUN_141a03090())
            return 1;
        method = "onEnterKey";
    }
    else if (FUN_14025e7c0()->FUN_14116d840())
    {
        if (!m_data->FUN_141a03100())
            return 1;
        method = "onEscapeKey";
    }
    else if (FUN_14025e7c0()->FUN_14116d9c0(0x79, 0, 0))
        method = "onUpKey";
    else if (FUN_14025e7c0()->FUN_14116dd30(0x30d41, 0, 0))
        method = "onUpKey";
    else if (FUN_14025e7c0()->FUN_14116d9c0(0x7b, 0, 0))
        method = "onLeftKey";
    else if (FUN_14025e7c0()->FUN_14116dd30(0x30d43, 0, 0))
        method = "onLeftKey";
    else if (FUN_14025e7c0()->FUN_14116d9c0(0x7e, 0, 0))
        method = "onDownKey";
    else if (FUN_14025e7c0()->FUN_14116dd30(0x30d42, 0, 0))
        method = "onDownKey";
    else if (FUN_14025e7c0()->FUN_14116d9c0(0x7c, 0, 0))
        method = "onRightKey";
    else if (FUN_14025e7c0()->FUN_14116dd30(0x30d44, 0, 0))
        method = "onRightKey";
    else if (FUN_14025e7c0()->FUN_14116d9c0(15, 0, 0))
        method = "onTabKey";
    if (!method.IsEmpty())
    {
        m_30->Invoke("onProcessKey", method);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419F7560, UIMessageBox, vfunc_13, 1043, 0xA6912204);

// @0x1419f7980
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
int UIMessageBox::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    CString name = szMethod;
    if (!_stricmp("OnClick", name))
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nButton = data.FUN_1422b8a10();
            int nBoxId = data.FUN_1422b8b10();
            CStringW strTag = data.FUN_1422b8f40();
            Scaleform::GFx::Value extra = data.FUN_1422b9260();
            if (m_data.get())
                m_data->FUN_141a02810(strTag);
            FUN_1419f9410(nButton, nBoxId, strTag, extra);
        }
        return 1;
    }
    else if (!_stricmp("OnChangeTime", name))
    {
        if (m_data.get())
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs))
            {
                int nSec = data.FUN_1422b8a10();
                m_data->FUN_141a03130(this, nSec);
            }
        }
        return 1;
    }
    else if (!_stricmp("OnTopMostLayer", name))
    {
        FUN_1419f8de0();
        return 1;
    }
    else if (!_stricmp("OnPopupTimerComplete", name))
    {
        if (m_data == 0)
            return 0;
        m_data->FUN_141a03390(this);
        IMessageListener* pListener = m_data->FUN_141a02cc0();
        if (pListener)
        {
            Unk_MessageBoxMsg msg(2002);
            msg.FUN_1422b8310(m_data->GetExtra());
            pListener->OnMessage(this, reinterpret_cast<UIMsg*>(&msg));
            return 1;
        }
        pListener = 0;
    }
    else if (!_stricmp("onHyperLinkClick", name))
    {
        if (m_data == 0)
            return 0;
        CString strLink = m_data->GetLinkUrl();
        if (!strLink.IsEmpty())
            FUN_1418fe1c0(strLink);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419F7980, UIMessageBox, vfunc_28, 1382, 0x80B4CD48);

// @0x1419f7f00
void UIMessageBox::vfunc_47(int bBlock)
{
    if (m_data.get())
    {
        if (!FUN_14151f8b0() || !m_data->FUN_141a03050())
            FUN_141901390(bBlock, vfunc_48());
        if (!FUN_14151f9c0() || !m_data->IsModaless())
            FUN_1419013c0(bBlock, vfunc_48());
    }
    else
        FUN_141901470(bBlock, vfunc_48());
}
MS2_REPLACE_METHOD(0x1419F7F00, UIMessageBox, vfunc_47, 224, 0x0A28E066);

// @0x1419f7ff0
int UIMessageBox::FUN_1419f7ff0(MS2Ptr<CMsgBoxData> spData)
{
    if (m_30.IsNull())
        return 0;
    if (FUN_1419f84c0(spData))
        return 0;
    m_closing = 0;
    if (!FUN_1419f8270())
        FUN_1419f9250(false);
    FUN_1419f8ec0(spData);
    return 1;
}
MS2_REPLACE_METHOD(0x1419F7FF0, UIMessageBox, FUN_1419f7ff0, 296, 0x5EB61E8B);

// @0x1419f8120
void UIMessageBox::FUN_1419f8120()
{
    int bClose = 0;
    if (m_closing)
        bClose = 1;
    FUN_1419f9250(bClose);
    FUN_1419f8270();
}
MS2_REPLACE_METHOD(0x1419F8120, UIMessageBox, FUN_1419f8120, 65, 0x31213ACE);

// @0x1419f8170
void UIMessageBox::FUN_1419f8170(int nResult)
{
    if (m_30.get())
    {
        m_closing = 1;
        m_30->Invoke("closeAll", nResult);
    }
    FUN_1419f88e0(1);
}
MS2_REPLACE_METHOD(0x1419F8170, UIMessageBox, FUN_1419f8170, 119, 0x4834C06E);

// @0x1419f81f0
void UIMessageBox::FUN_1419f81f0(MS2Ptr<CMsgBoxData> spData)
{
    if (FUN_1419f8270())
        return;
    FUN_1419f9250(false);
    FUN_1419f8ec0(spData);
}
MS2_REPLACE_METHOD(0x1419F81F0, UIMessageBox, FUN_1419f81f0, 122, 0x4CDA3CBB);

// @0x1419f8270
int UIMessageBox::FUN_1419f8270()
{
    return m_count == 0;
}
MS2_REPLACE_METHOD(0x1419F8270, UIMessageBox, FUN_1419f8270, 44, 0x346395F5);

// @0x1419f82b0
void UIMessageBox::FUN_1419f82b0(const CStringW& strText)
{
    if (m_30.get())
        m_30->Invoke("onProcessFunction", "updateErrorMsg", strText);
}
MS2_REPLACE_METHOD(0x1419F82B0, UIMessageBox, FUN_1419f82b0, 171, 0x7D43612C);

// @0x1419f8370
void UIMessageBox::FUN_1419f8370(const CStringW& strText)
{
    if (m_30.get())
    {
        if (m_data.get())
            m_data->SetMsg(strText);
        m_30->Invoke("onProcessFunction", "updateMsg", strText);
    }
}
MS2_REPLACE_METHOD(0x1419F8370, UIMessageBox, FUN_1419f8370, 240, 0x1109672B);

// @0x1419f8470
MS2Ptr<CMsgBoxData> UIMessageBox::FUN_1419f8470()
{
    return m_data;
}
MS2_REPLACE_METHOD(0x1419F8470, UIMessageBox, FUN_1419f8470, 67, 0xE0100933);

// @0x1419f84c0
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
int UIMessageBox::FUN_1419f84c0(MS2Ptr<CMsgBoxData> spData)
{
    if (!spData.IsNull() && !m_data.IsNull())
    {
        CStringW strCur = m_data.get() ? m_data->GetExtra() : CStringW(L"");
        CStringW strNew = spData.get() ? spData->GetExtra() : CStringW(L"");
        if (!strNew.IsEmpty() && !strCur.IsEmpty() && strCur.Compare(strNew) == 0)
            return 1;
        if (!spData->FUN_141a02da0().IsNull() && !m_data->FUN_141a02da0().IsNull() &&
            spData->FUN_141a02da0() == m_data->FUN_141a02da0())
            return 1;
        return 0;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419F84C0, UIMessageBox, FUN_1419f84c0, 1043, 0x42470F2E);

// @0x1419f88e0
void UIMessageBox::FUN_1419f88e0(int bBlock)
{
    FUN_141901470(bBlock, vfunc_48());
}
MS2_REPLACE_METHOD(0x1419F88E0, UIMessageBox, FUN_1419f88e0, 48, 0x9F3089AC);

// Sell an item: asks first when the item is rare or the price is over the confirm limit.
// @0x1419f8920
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
static void FUN_1419f8920(MS2Ptr<CItem> spItem, unsigned int nCount)
{
    if (!spItem)
        return;
    int bAsk = 0;
    if (spItem.get())
    {
        if (spItem->FUN_140526bd0() < 4)
        {
            if (spItem->FUN_1405258b0() != 0 ||
                spItem->FUN_140527670() * (int)nCount >= *FUN_1401d7c10(&FUN_1401d3200()->m_sellConfirmPrice))
                bAsk = 1;
        }
        else
            bAsk = 1;
    }
    if (bAsk == 0)
    {
        FUN_141425fc0(spItem->FUN_140526a50(), nCount, spItem.get());
    }
    else
    {
        CStringW strTag;
        strTag.Format(L"%s,%d", (const wchar_t*)s_143af3d70, nCount);
        CStringW strAsk = FUN_14028de60(0x28c);
        CStringW strMsg;
        CStringW strExtra;
        bool bExtra = false;
        FUN_1409e4950(spItem, strExtra, bExtra);
        if (bExtra == true && strExtra.GetLength() > 0)
        {
            strMsg += strExtra;
            strMsg += L"\n";
        }
        strMsg += strAsk;
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, strMsg, 0, strTag);
        if (spBox.get())
        {
            MS2Ptr<CItem> spCopy = spItem->FUN_140524250();
            spCopy->FUN_140526c70(nCount);
            spBox->FUN_141a01600(spItem->FUN_140526a50());
            spBox->FUN_141a01ee0(spCopy, spCopy->FUN_140527b10(), 1, 0, -1, -1, 1);
            spBox->FUN_141a01700(0x47e, 0x476, 0);
            FUN_140d73c60(spBox);
        }
    }
}

// @0x1419f8de0
void UIMessageBox::FUN_1419f8de0()
{
    FUN_140b632f0()->FUN_1422d48f0(this, m_layer);
}
MS2_REPLACE_METHOD(0x1419F8DE0, UIMessageBox, FUN_1419f8de0, 41, 0x2CD98C0B);

// @0x1419f8e10
void UIMessageBox::FUN_1419f8e10(MS2Ptr<CMsgBoxData> spData)
{
    if (spData.get())
    {
        CString strSound = spData->GetSound();
        if (!strSound.IsEmpty())
            FUN_141276180(strSound, "");
    }
}
MS2_REPLACE_METHOD(0x1419F8E10, UIMessageBox, FUN_1419f8e10, 163, 0xBFB98928);

// @0x1419f8ec0
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
void UIMessageBox::FUN_1419f8ec0(MS2Ptr<CMsgBoxData> spData)
{
    m_count = 1;
    FUN_140b632f0()->FUN_1422d4780(this, m_layer);
    FUN_140b632f0()->FUN_1422d48f0(this, m_layer);
    FUN_14140ea40()->vfunc_1(0x4e48);
    m_data = spData;
    FUN_1419f8e10(spData);
    if (m_data.get())
    {
        if (m_data->GetExtra() == s_143af3ba8)
        {
            UIBannerAdvertisingDialog* pBanner = FUN_141876420(0x4eca);
            if (pBanner)
                pBanner->FUN_141031260();
        }
    }
    if (m_data.get())
    {
        ASObj obj(FUN_1422db730());
        m_data->FUN_141a034d0(obj);
        m_30->Invoke("open", obj);
        vfunc_8(1);
    }
}
MS2_REPLACE_METHOD(0x1419F8EC0, UIMessageBox, FUN_1419f8ec0, 571, 0xFAAAA2EC);

// @0x1419f9110
void UIMessageBox::FUN_1419f9110()
{
    if (!FUN_1419f8270())
    {
        vfunc_8(0);
        FUN_140b632f0()->FUN_1422d4840(this, 4);
        FUN_141276180(s_close, "");
    }
    if (m_data.get() ? true : false)
    {
        if (m_data->GetExtra() == s_143af3ba8)
        {
            UIBannerAdvertisingDialog* pBanner = FUN_141876420(0x4eca);
            if (pBanner)
                pBanner->FUN_1410312d0();
        }
    }
    m_data = 0;
    m_count = 0;
    m_closing = 0;
}
MS2_REPLACE_METHOD(0x1419F9110, UIMessageBox, FUN_1419f9110, 299, 0x70757C1F);

// @0x1419f9250
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
void UIMessageBox::FUN_1419f9250(int nResult)
{
    if (m_30.get() && m_data.get())
    {
        m_data->FUN_141a03470();
        Scaleform::GFx::Value ret = m_30->Invoke("closeCurrent", (long)m_data->FUN_141a02ca0(), nResult);
        if (m_data->IsModaless())
        {
            MS2Ptr<ASDialog> spBox = FUN_140e43fe0(m_28, ret);
            if (spBox.get())
                m_data->FUN_141a04f80(spBox);
        }
    }
    FUN_1419f9110();
}
MS2_REPLACE_METHOD(0x1419F9250, UIMessageBox, FUN_1419f9250, 434, 0xCED33908);

// OnClick: the callback boxes call their delegate, the others go to the listener and the tag handlers.
// @0x1419f9410
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
void UIMessageBox::FUN_1419f9410(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra)
{
    if (m_data == 0 || m_data->FUN_141a02ca0() != nBoxId)
    {
        FUN_14151f200();
        return;
    }
    bool bClose = m_closing == 1;
    MS2Ptr<CMsgBoxData> spData = m_data;
    if (spData->FUN_141a01480())
    {
        if (spData->FUN_141a014d0(nButton, &extra))
        {
            if (!(spData == m_data.get()))
                FUN_14151f720(spData);
            else
                FUN_14151f200();
        }
    }
    else
    {
        int bHandled = 1;
        IMessageListener* pListener = m_data->FUN_141a02cc0();
        if (pListener)
        {
            Unk_MessageBoxMsg msg(0);
            msg.FUN_1422b7f70(nButton);
            msg.FUN_1422b8310(strTag);
            bHandled = pListener->OnMessage(this, reinterpret_cast<UIMsg*>(&msg));
        }
        int bConsumed = FUN_1419f97a0(nButton, nBoxId, strTag, extra);
        if (strTag == s_143af3bf8 && bHandled == 0 && m_closing == 0)
            return;
        if (bConsumed || !bHandled)
            bClose = true;
    }
    if (bClose && FUN_14151f6e0() == 0)
    {
        MS2Ptr<CMsgBoxData> spNext = FUN_14151f820();
        if (spNext.get())
        {
            if (spNext->FUN_141a02ca0() == nBoxId)
                FUN_14151f200();
            else
                FUN_14151f720(spData);
        }
    }
}
MS2_REPLACE_METHOD(0x1419F9410, UIMessageBox, FUN_1419f9410, 903, 0x9CF56E02);

// @0x1419f97a0
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
int UIMessageBox::FUN_1419f97a0(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra)
{
    if (m_data == 0)
        return 1;
    if (strTag.IsEmpty())
    {
        if (!FUN_1419f8270())
            return 1;
        return 0;
    }
    MS2Ptr<CMsgBoxData> spData = m_data;
    if (FUN_1419f9ba0(nButton, nBoxId, strTag, extra))
        return 1;
    if (FUN_1419fa910(nButton, nBoxId, strTag, extra))
        return 1;
    IMessageListener* pListener = spData->FUN_141a02cc0();
    if (pListener)
    {
        ATL::CAtlList<CStringW> groups(10);
        groups.AddTail(s_143af3c00);
        groups.AddTail(s_143af3c08);
        groups.AddTail(s_143af3c10);
        POSITION pos = groups.GetHeadPosition();
        while (pos)
        {
            CStringW strGroup = groups.GetAt(pos);
            if (strTag.Find(strGroup) != -1)
            {
                Unk_MessageBoxMsg msg(0x7d1);
                msg.FUN_1422b8310(strGroup);
                msg.FUN_1422b7f70(nButton);
                msg.FUN_1422b83f0(extra);
                pListener->OnMessage(this, reinterpret_cast<UIMsg*>(&msg));
            }
            groups.GetNext(pos);
        }
    }
    if (spData->GetType())
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1419F97A0, UIMessageBox, FUN_1419f97a0, 1009, 0x3894B590);

// @0x1419f9ba0
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
int UIMessageBox::FUN_1419f9ba0(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra)
{
    if (strTag == s_143af3ba8 && FUN_1419fb480(nButton))
        return 1;
    else if (strTag == s_143af3c18)
    {
        if (FUN_1419fb500(nButton))
            return 1;
    }
    else if (strTag == s_143af3c20)
    {
        if (FUN_1419fb3c0())
            return 1;
    }
    else if (strTag.Find(s_143af3c28) == 0)
    {
        if (FUN_1419fb930(nButton))
            return 1;
    }
    else if (strTag == s_143af3c30)
    {
        if (FUN_1419fc640(nButton))
            return 1;
    }
    else if (strTag == s_143af3c38)
    {
        if (SendRequestCube(nButton))
            return 1;
    }
    else if (strTag == s_143af3c40)
    {
        if (FUN_1419fba00(nButton))
            return 1;
    }
    else if (strTag == s_143af3c48)
    {
        if (FUN_1419fc710(nButton))
            return 1;
    }
    else if (strTag == s_143af3c50)
    {
        if (FUN_1419fcde0(nButton))
            return 1;
    }
    else if (strTag == s_143af3c58)
    {
        if (FUN_1419fc750(nButton))
            return 1;
    }
    else if (strTag == s_143af3c60)
    {
        if (FUN_1419fc7d0(nButton))
            return 1;
    }
    else if (strTag == s_143af3c68)
    {
        if (FUN_1419fcc70(nButton))
            return 1;
    }
    else if (strTag == s_143af3c70 || strTag == s_143af3c78)
    {
        if (FUN_1419fccb0(nButton))
            return 1;
    }
    else if (strTag == s_143af3c80)
    {
        if (FUN_1419fb8e0(nButton))
            return 1;
    }
    else if (strTag == s_143af3c88)
    {
        if (FUN_1419fb7b0(nButton))
            return 1;
    }
    else if (strTag == s_143af3c90)
    {
        if (FUN_1419fc810(nButton))
            return 1;
    }
    else if (strTag == s_143af3c98)
    {
        if (FUN_1419fba50(nButton))
            return 1;
    }
    else if (strTag == s_143af3ca0)
    {
        if (FUN_1419fc550(nButton))
            return 1;
    }
    else if (strTag == s_143af3ca8)
    {
        if (FUN_1419fce20(nButton))
            return 1;
    }
    else if (strTag == s_143af3cb0)
    {
        if (FUN_1419fcf60(nButton))
            return 1;
    }
    else if (strTag == s_143af3cb8)
    {
        if (FUN_1419fd0d0(nButton))
            return 1;
    }
    else if (strTag == s_143af3cc0)
    {
        if (FUN_1419fe790(nButton, 1))
            return 1;
    }
    else if (strTag == s_143af3cc8)
    {
        if (FUN_1419fe830(nButton, 1))
            return 1;
    }
    else if (strTag == s_143af3cd0)
    {
        if (FUN_1419fd130(nButton))
            return 1;
    }
    else if (strTag == s_143af3cd8)
    {
        if (FUN_1419fd260(nButton))
            return 1;
    }
    else if (strTag == s_143af3ce0)
    {
        if (FUN_1419fd4a0(nButton))
            return 1;
    }
    else if (strTag == s_143af3ce8)
    {
        if (FUN_1419fd6e0(nButton))
            return 1;
    }
    else if (strTag == s_143af3cf0 || strTag == s_143af3cf8)
    {
        if (FUN_1419fd830(nButton))
            return 1;
    }
    else if (strTag == s_143af3d00)
    {
        if (FUN_1419fda70(nButton))
            return 1;
    }
    else if (strTag == s_143af3d08)
    {
        if (FUN_1419fdbe0(nButton))
            return 1;
    }
    else if (strTag == s_143af3d10)
    {
        if (FUN_1419fde80(nButton))
            return 1;
    }
    else if (strTag == s_143af3d18)
    {
        if (FUN_1419fdf80(nButton))
            return 1;
    }
    else if (strTag == s_143af3d20)
    {
        if (FUN_1419fe110(nButton))
            return 1;
    }
    else if (strTag == s_143af3d28)
    {
        if (FUN_1419ff870(nButton))
            return 1;
    }
    else if (strTag == s_143af3d30)
    {
        if (FUN_1419ff7d0(nButton))
            return 1;
    }
    else if (strTag == s_143af3d38)
    {
        if (FUN_1419ffb20(nButton))
            return 1;
    }
    else if (strTag == s_143af3d40)
    {
        if (FUN_1419fff10(nButton))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419F9BA0, UIMessageBox, FUN_1419f9ba0, 3430, 0x6E7FC896);

// @0x1419fa910
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419fa910(int nButton, int nBoxId, CStringW strTag, Scaleform::GFx::Value& extra)
{
    ATL::CAtlArray<CStringW> tokens;
    if (!FUN_14028cb70(strTag, tokens, L",", 2))
        return 0;
    if (tokens[0] == s_143af3d48)
    {
        if (FUN_1419fe240(nButton, _wtoi(tokens[1])))
            return 1;
    }
    else if (tokens[0] == s_143af3d50)
    {
        if (FUN_1419fe310(nButton, _wtoi(tokens[1])))
            return 1;
    }
    else if (tokens[0] == s_143af3d58)
    {
        if (FUN_1419fe590(nButton, _wtoi(tokens[1])))
            return 1;
    }
    else if (tokens[0] == s_143af3d60)
    {
        if (FUN_1419fe690(nButton, _wtoi(tokens[1])))
            return 1;
    }
    else if (tokens[0] == s_143af3cc0)
    {
        if (FUN_1419fe790(nButton, _wtoi(tokens[1])))
            return 1;
    }
    else if (tokens[0] == s_143af3cc8)
    {
        if (FUN_1419fe830(nButton, _wtoi(tokens[1])))
            return 1;
    }
    else if (tokens[0] == s_143af3d68)
    {
        if (FUN_1419fe900(nButton, _wtoi(tokens[1])))
            return 1;
    }
    else if (tokens[0] == s_143af3d70)
    {
        if (FUN_1419fea00(nButton, _wtoi(tokens[1])))
            return 1;
    }
    else if (tokens[0] == s_143af3d78)
    {
        if (FUN_1419feae0(nButton, tokens[1]))
            return 1;
    }
    else if (tokens[0] == s_143af3d80)
    {
        if (FUN_1419fecc0(nButton, tokens[1]))
            return 1;
    }
    else if (tokens[0] == s_143af3d88)
    {
        if (FUN_1419feeb0(nButton, tokens[1]))
            return 1;
    }
    else if (tokens[0] == s_143af3d90)
    {
        if (FUN_1419ff130(nButton, tokens[1]))
            return 1;
    }
    else if (tokens[0] == s_143af3d98)
    {
        bool bDontAsk = FUN_1407183f0(tokens[1]);
        if (bDontAsk == true && nButton == 0)
        {
            __time64_t tNow = FUN_140869440();
            FUN_1409a8b10()->FUN_140c9b8b0()->m_nFuncItemAsk = tNow;
            FUN_1409a8b10()->FUN_141243540();
        }
        if (FUN_1419fc810(nButton))
            return 1;
    }
    else if (tokens[0] == s_143af3da0)
    {
        bool bDontAsk = FUN_1407183f0(tokens[1]);
        if (bDontAsk == true && nButton == 0)
        {
            __time64_t tNow = FUN_140869440();
            FUN_1409a8b10()->FUN_140c9b8b0()->m_nCurrencyAsk = tNow;
            FUN_1409a8b10()->FUN_141243540();
        }
        if (FUN_1419ffe20(nButton))
            return 1;
    }
    else if (tokens[0] == s_143af3da8)
    {
        if (FUN_1419fbd40(nButton, strTag))
            return 1;
    }
    else if (tokens[0] == s_143af3db0)
    {
        if (!FUN_140166410()->FUN_14036d570(0xd4))
            return 0;
        if (FUN_1419fc140(nButton, strTag))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419FA910, UIMessageBox, FUN_1419fa910, 2716, 0x7FE1CD7E);

// @0x1419fb3c0
int UIMessageBox::FUN_1419fb3c0()
{
    if (FUN_1408e57f0()->FUN_1422b9dc0() == 0x620000d)
    {
        FUN_140714f90()->FUN_1415388a0();
        FUN_1416a0e70();
        PostQuitMessage(0);
        return 0;
    }
    if (FUN_140aa6d30()->FUN_1417e25a0(0x6200009) == 0 && FUN_1408e57f0()->FUN_1422b9dc0() == 0x6200009)
    {
        UISceneLogin* pLogin = dynamic_cast<UISceneLogin*>(FUN_1408e57f0()->FUN_1422b9e80());
        if (pLogin)
            pLogin->FUN_141acf470();
    }
    return 1;
}

// @0x1419fb480
int UIMessageBox::FUN_1419fb480(int nButton)
{
    if (nButton == 0)
    {
        if (DAT_143ab2942 == false)
            FUN_140d86260()->vfunc_22(0x3f2, "GameEnd");
        FUN_140714f90()->FUN_1415388a0();
        FUN_1416a0e70();
        PostQuitMessage(0);
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FB480, UIMessageBox, FUN_1419fb480, 112, 0x6AFEFB11);

// @0x1419fb500
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419fb500(int nButton)
{
    if (nButton == 0)
    {
        if (FUN_1408e57f0()->FUN_1422b9dc0() == 0x6200009)
        {
            if (DAT_143ab2858 == 0)
            {
                FUN_140d73aa0(FUN_14052bd00(0x20f, FUN_14028de60(0xd28)), 0, 0, L"");
            }
            else
            {
                UILoginDialog* pDialog = Unk_MessageBoxDialog<UILoginDialog>(0x4e22);
                if (pDialog)
                    pDialog->FUN_1419e2310(0);
            }
            return 0;
        }
    }
    return 1;
}

// @0x1419fb630
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
int UIMessageBox::FUN_1419fb630(int nButton)
{
    if (nButton == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4e69);
    }
    else
    {
        if (nButton == 2)
        {
            Unk_MessageBoxGuideDialog* pDialog = FUN_140ff7030(0x4e87);
            if (pDialog)
                pDialog->FUN_1418dfb30(*FUN_1402056b0(&FUN_1401d3200()->m_guideId), 0x22, m_layer);
            return 0;
        }
        if (nButton == 3)
        {
            CString strUrl;
            const char* szPage = *FUN_140298f80(&FUN_1401d3200()->m_guideUrl);
            FUN_140cc18a0()->FUN_141b794e0(strUrl, szPage);
            FUN_1418fe1c0(strUrl);
            return 0;
        }
    }
    Unk_MessageBoxGuideDialog* pDialog = FUN_140ff7030(0x4e87);
    if (pDialog && !pDialog->vfunc_55() && pDialog->FUN_1418dfc40() == *FUN_1402056b0(&FUN_1401d3200()->m_guideId))
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e87);
    return 1;
}
MS2_REPLACE_METHOD(0x1419FB630, UIMessageBox, FUN_1419fb630, 363, 0x8A536F36);

// @0x1419fb7b0
int UIMessageBox::FUN_1419fb7b0(int nButton)
{
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPlayer)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem.get())
            pPlayer->FUN_1416546d0()->FUN_140a6e140(nUid, FUN_14053dc20(spItem->FUN_140527840()), FUN_14053dc40(spItem->FUN_140527840()));
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FB7B0, UIMessageBox, FUN_1419fb7b0, 298, 0xB81A151D);

// @0x1419fb8e0
int UIMessageBox::FUN_1419fb8e0(int nButton)
{
    if (nButton == 0)
    {
        Unk_MessageBoxPeer* pPeer = FUN_140b04f80(20156);
        if (pPeer)
            pPeer->FUN_1410356f0();
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FB8E0, UIMessageBox, FUN_1419fb8e0, 63, 0x97A78D53);

// @0x1419fb930
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419fb930(int nButton)
{
    int nResult = nButton == 0 ? 1 : 9;
    if (nResult == 9)
    {
        if (m_closing == 0)
        {
            if (m_data.get() && m_data->GetTimer().m_nButton != 0)
                nResult = 12;
        }
        else
            nResult = 21;
    }
    FUN_1409670d0()->FUN_14162b950(nResult);
    return 1;
}
MS2_REPLACE_METHOD(0x1419FB930, UIMessageBox, FUN_1419fb930, 187, 0xF39E0C2D);

// @0x1419fba00
int UIMessageBox::FUN_1419fba00(int nButton)
{
    int bAccept = nButton == 0 ? 1 : 0;
    FUN_1403ed290()->FUN_1413b74f0(bAccept);
    return 1;
}
MS2_REPLACE_METHOD(0x1419FBA00, UIMessageBox, FUN_1419fba00, 73, 0xDD738340);


// @0x1419fba50
// MS2-FUNCTIONAL: NiTransform stand-ins (the exe builds the transform inline)
int UIMessageBox::FUN_1419fba50(int nButton)
{
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer && nButton == 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_data->FUN_141a02c00());
        if (spItem.get())
        {
            __int64 nUid = spItem->FUN_140526a50();
            FUN_140714f90()->FUN_1415389b0(nUid);
            Unk_MessageBoxXform xf;
            FUN_140a332d0(&xf);
            xf.m_fScale = 1.0f;
            Unk_MessageBoxPt3 pos;
            FUN_14027dcf0(&pos, pPlayer->vfunc_18());
            FUN_14097faa0(&xf.m_translate, &pos);
            Unk_MessageBoxRot rot;
            FUN_140a33240(&rot, &DAT_143a09600);
            xf.m_rotate = rot;
            CString strSound = FUN_140281980()->FUN_140559750();
            if (!strSound.IsEmpty())
                FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"), CString(strSound), CString(""), 1, &xf, 1.0f, 0);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FBA50, UIMessageBox, FUN_1419fba50, 735, 0x7B0CE74D);

// @0x1419fbd40
// MS2-FUNCTIONAL: NiTransform stand-ins (the exe builds the transform inline)
int UIMessageBox::FUN_1419fbd40(int nButton, CStringW strTag)
{
    ATL::CAtlArray<CStringW> tokens;
    if (!FUN_14028cb70(strTag, tokens, L",", 2))
        return 0;
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 1;
    bool bOk = FUN_1407183f0(tokens[1]);
    if (bOk == true && nButton == 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2d80.FUN_140de1490(m_data->FUN_141a02c00());
        if (spItem.get())
        {
            FUN_140714f90()->FUN_141538a20(spItem->FUN_140526a50());
            Unk_MessageBoxXform xf;
            FUN_140a332d0(&xf);
            xf.m_fScale = 1.0f;
            Unk_MessageBoxPt3 pos;
            FUN_14027dcf0(&pos, pPlayer->vfunc_18());
            FUN_14097faa0(&xf.m_translate, &pos);
            Unk_MessageBoxRot rot;
            FUN_140a33240(&rot, &DAT_143a09600);
            xf.m_rotate = rot;
            CString strSound = FUN_140281980()->FUN_140559750();
            if (!strSound.IsEmpty())
                FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"), CString(strSound), CString(""), 1, &xf, 1.0f, 0);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FBD40, UIMessageBox, FUN_1419fbd40, 1004, 0x279431D3);

// @0x1419fc140
// MS2-FUNCTIONAL: NiTransform stand-ins (the exe builds the transform inline)
int UIMessageBox::FUN_1419fc140(int nButton, CStringW strTag)
{
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 1;
    ATL::CAtlArray<CStringW> tokens;
    if (!FUN_14028cb70(strTag, tokens, L",", 2))
        return 0;
    if (m_data == 0)
        return 1;
    bool bOk = FUN_1407183f0(tokens[1]);
    if (bOk == true && nButton == 0)
    {
        __int64 nSlot = 0;
        MS2Ptr<CItem> spItem(pPlayer->FUN_14152efa0(m_data->FUN_141a02c00(), &nSlot));
        if (spItem.get())
        {
            FUN_140714f90()->FUN_141538a90(nSlot, spItem->FUN_140526a50());
            Unk_MessageBoxXform xf;
            FUN_140a332d0(&xf);
            xf.m_fScale = 1.0f;
            Unk_MessageBoxPt3 pos;
            FUN_14027dcf0(&pos, pPlayer->vfunc_18());
            FUN_14097faa0(&xf.m_translate, &pos);
            Unk_MessageBoxRot rot;
            FUN_140a33240(&rot, &DAT_143a09600);
            xf.m_rotate = rot;
            CString strSound = FUN_140281980()->FUN_140559750();
            if (!strSound.IsEmpty())
                FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"), CString(strSound), CString(""), 1, &xf, 1.0f, 0);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FC140, UIMessageBox, FUN_1419fc140, 1021, 0xB1DBE34C);

// @0x1419fc550
int UIMessageBox::FUN_1419fc550(int nButton)
{
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPlayer)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        FUN_14151f200();
        if (MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid))
            DAT_143ab2a90.SendEmotion(spItem.get());
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FC550, UIMessageBox, FUN_1419fc550, 221, 0xF5CE1574);

// @0x1419fc640
int UIMessageBox::FUN_1419fc640(int nButton)
{
    int bAccept = nButton == 0 ? 1 : 0;
    FUN_140714f90()->FUN_141538b10(bAccept);
    return 1;
}
MS2_REPLACE_METHOD(0x1419FC640, UIMessageBox, FUN_1419fc640, 73, 0x0185AFFF);

// @0x1419fc690
int UIMessageBox::SendRequestCube(int nButton)
{
    FUN_14151f200();
    if (nButton == 0)
    {
        COutPacket packet(0x37, 0);
        packet.Encode1(0x19);
        FUN_140710590(packet);
        return 1;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FC690, UIMessageBox, SendRequestCube, 112, 0x3F0B35F5);

// @0x1419fc710
int UIMessageBox::FUN_1419fc710(int nButton)
{
    if (nButton == 0)
        FUN_1403ed290()->FUN_1413bc050();
    return 1;
}
MS2_REPLACE_METHOD(0x1419FC710, UIMessageBox, FUN_1419fc710, 43, 0x27E625D8);

// @0x1419fc750
int UIMessageBox::FUN_1419fc750(int nButton)
{
    __int64 nId = m_data->FUN_141a02f10(0, 0);
    int bAccept = nButton == 0 ? 1 : 0;
    FUN_14140ea30()->FUN_14185b8e0(nId, bAccept);
    return 1;
}
MS2_REPLACE_METHOD(0x1419FC750, UIMessageBox, FUN_1419fc750, 116, 0x9F204CD0);

// @0x1419fc7d0
int UIMessageBox::FUN_1419fc7d0(int nButton)
{
    if (nButton == 0)
    {
        FUN_140714f90()->FUN_1415388a0();
        FUN_1416a0e70();
        PostQuitMessage(0);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FC7D0, UIMessageBox, FUN_1419fc7d0, 56, 0xA10A6BE4);

// @0x1419fc810
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419fc810(int nButton)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        int bAsk = 0;
        m_data->FUN_140be25f0(0, bAsk);
        if (bAsk == 0)
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
            if (spItem.get())
                DAT_143ab2a90.FUN_140a63880(spItem.get(), CStringW(L""));
        }
        else
        {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
            if (spItem.get())
            {
                CStringW strName;
                __int64 nAmount = 0;
                m_data->FUN_140b76a70(1, strName);
                m_data->FUN_140e01c50(2, nAmount);
                CStringW strMsg = FUN_14052bd00(0x2a7, strName);
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x1a, strMsg, 0, s_143af3da0);
                if (spBox.get())
                {
                    spBox->FUN_141a01600(spItem->FUN_140526a50());
                    spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
                    spBox->FUN_141a01800(2);
                    spBox->FUN_141a024e0(FUN_14028de60(0x29e), 0);
                    FUN_140d73c60(spBox);
                }
            }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FC810, UIMessageBox, FUN_1419fc810, 1112, 0xC18E5FC1);

// @0x1419fcc70
int UIMessageBox::FUN_1419fcc70(int nButton)
{
    if (nButton == 0)
        FUN_140714f90()->FUN_1415382c0();
    return 1;
}
MS2_REPLACE_METHOD(0x1419FCC70, UIMessageBox, FUN_1419fcc70, 43, 0x23E8BDFB);

// @0x1419fccb0
int UIMessageBox::FUN_1419fccb0(int nButton)
{
    if (nButton != 0)
        return 1;
    int nType = -1;
    m_data->FUN_141a00450(0, nType);
    SHELLEXECUTEINFOA info = {};
    info.cbSize = sizeof(info);
    info.fMask = 0;
    info.hwnd = FUN_140aadf80()->FUN_14209c720();
    info.lpVerb = "Open";
    info.lpFile = "IEXPLORE.EXE";
    info.lpDirectory = 0;
    info.nShow = SW_SHOWNORMAL;
    info.hInstApp = 0;
    switch (nType)
    {
    case 0:
        info.lpParameters = "http://maplestory2.nexon.com/Auth/Certify";
        ShellExecuteExA(&info);
        FUN_140714f90()->FUN_1415388a0();
        FUN_1416a0e70();
        PostQuitMessage(0);
        break;
    case 1:
        info.lpParameters = "http://maplestory2.nexon.com/auth/identification";
        ShellExecuteExA(&info);
        break;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FCCB0, UIMessageBox, FUN_1419fccb0, 295, 0x4EBD3D32);

// @0x1419fcde0
int UIMessageBox::FUN_1419fcde0(int nButton)
{
    if (nButton == 0)
        FUN_140f97ef0()->FUN_141280d40();
    return 1;
}
MS2_REPLACE_METHOD(0x1419FCDE0, UIMessageBox, FUN_1419fcde0, 43, 0x51639961);

// @0x1419fce20
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419fce20(int nButton)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02f10(0, 0);
        CStringW strName = m_data->FUN_141a02fd0(1, CStringW());
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem.get())
            DAT_143ab2a90.FUN_140a63880(spItem.get(), strName);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FCE20, UIMessageBox, FUN_1419fce20, 312, 0xCA9D1AA7);

// @0x1419fcf60
int UIMessageBox::FUN_1419fcf60(int nButton)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        COutPacket packet(0x6f, 0);
        packet.Encode1(m_data->FUN_141a02e50(0, 0));
        packet.COutPacket::vfunc_o10_8(m_data->FUN_141a02fd0(1, CStringW()));
        packet.Encode4(m_data->FUN_141a02e90(2, 0));
        FUN_140710590(packet);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FCF60, UIMessageBox, FUN_1419fcf60, 356, 0x82A9A7B6);

// @0x1419fd0d0
int UIMessageBox::FUN_1419fd0d0(int nButton)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
        FUN_140535310()->FUN_140612e10();
    return 1;
}
MS2_REPLACE_METHOD(0x1419FD0D0, UIMessageBox, FUN_1419fd0d0, 78, 0x7F02717F);

// @0x1419fd130
int UIMessageBox::FUN_1419fd130(int nButton)
{
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem == 0)
            return 0;
        pPlayer->FUN_14152aa90(spItem, 1);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FD130, UIMessageBox, FUN_1419fd130, 283, 0x693778D4);

// @0x1419fd260
int UIMessageBox::FUN_1419fd260(int nButton)
{
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem == 0)
            return 0;
        Unk_MessageBoxPetDialog* pDialog = FUN_140b99ba0(0x4f38);
        if (pDialog)
        {
            if (pDialog->vfunc_55())
                return 0;
            MS2Ptr<PetSystemTabContents> spTab = pDialog->FUN_140e746c0();
            if (spTab == 0)
                return 0;
            MS2Ptr<TabContentsPetCompose> spCompose(dynamic_cast<TabContentsPetCompose*>((PetSystemTabContents*)spTab));
            if (spCompose == 0)
                return 0;
            spCompose->FUN_140cb48a0(1);
        }
    }
    return 1;
}

// @0x1419fd4a0
int UIMessageBox::FUN_1419fd4a0(int nButton)
{
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem == 0)
            return 0;
        Unk_MessageBoxPetDialog* pDialog = FUN_140b99ba0(0x4f38);
        if (pDialog)
        {
            if (pDialog->vfunc_55())
                return 0;
            MS2Ptr<PetSystemTabContents> spTab = pDialog->FUN_140e746c0();
            if (spTab == 0)
                return 0;
            MS2Ptr<TabContentsPetEvolution> spEvolution(dynamic_cast<TabContentsPetEvolution*>((PetSystemTabContents*)spTab));
            if (spEvolution == 0)
                return 0;
            spEvolution->OnPetEnchant(1);
        }
    }
    return 1;
}

// @0x1419fd6e0
int UIMessageBox::FUN_1419fd6e0(int nButton)
{
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem == 0)
            return 0;
        Unk_MessageBoxTrainingDialog* pDialog = FUN_140d276c0(0x4f12);
        if (pDialog)
        {
            if (pDialog->vfunc_55())
                return 0;
            pDialog->FUN_140e57d60();
            return 1;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FD6E0, UIMessageBox, FUN_1419fd6e0, 326, 0xEB79FDCB);

// @0x1419fd830
int UIMessageBox::FUN_1419fd830(int nButton)
{
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem == 0)
            return 0;
        Unk_MessageBoxPetDialog* pDialog = FUN_140b99ba0(0x4f38);
        if (pDialog)
        {
            if (pDialog->vfunc_55())
                return 0;
            MS2Ptr<PetSystemTabContents> spTab = pDialog->FUN_140e746c0();
            if (spTab == 0)
                return 0;
            MS2Ptr<TabContentsPetRemakeOption> spRemake(dynamic_cast<TabContentsPetRemakeOption*>((PetSystemTabContents*)spTab));
            if (spRemake == 0)
                return 0;
            spRemake->FUN_140b95280(1);
        }
    }
    return 1;
}

// @0x1419fda70
int UIMessageBox::FUN_1419fda70(int nButton)
{
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem == 0)
            return 0;
        UIItemRemakeScrollDialog* pDialog = Unk_MessageBoxDialog<UIItemRemakeScrollDialog>(0x4f09);
        if (pDialog)
        {
            if (pDialog->vfunc_55())
                return 0;
            __int64 nScroll = 0;
            m_data->FUN_140b19130(0, nScroll);
            pDialog->FUN_140f59ad0(nScroll, 1);
        }
    }
    return 1;
}

// @0x1419fdbe0
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419fdbe0(int nButton)
{
    if (m_data == 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (nButton != 0)
        return 1;
    __int64 nUid = m_data->FUN_141a02c00();
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
    if (!(spItem == 0))
    {
        int nSkill = 0;
        m_data->FUN_140961900(0, nSkill);
        MS2Ptr<Unk_InventorySkillLevel> spLevel = FUN_1401958b0()->FUN_1407ee2f0(nSkill, 1);
        if (!(spLevel == 0))
        {
            Unk_InventorySkillRequest request(nSkill, 1);
            request.remap = FUN_140804450(spLevel.operator->());
            request.item = spItem->FUN_140526a50();
            MS2Ptr<CSkillRecord> spRecord = pPlayer->FUN_141523bc0()->FUN_141765570(request);
            if (!(spRecord == 0))
            {
                spRecord->m_bItemSkill = true;
                return pPlayer->vfunc_102(spRecord);
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419FDBE0, UIMessageBox, FUN_1419fdbe0, 662, 0x412AD453);

// @0x1419fde80
int UIMessageBox::FUN_1419fde80(int nButton)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem == 0)
            return 0;
        FUN_140d1bd60(spItem, 1);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FDE80, UIMessageBox, FUN_1419fde80, 244, 0x4AC492C7);

// @0x1419fdf80
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
int UIMessageBox::FUN_1419fdf80(int nButton)
{
    if (m_data == 0)
        return 1;
    __int64 nUid = m_data->FUN_141a02c00();
    int nResult = 0;
    if (nButton == 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem == 0)
            return 0;
        nResult = DAT_143ab2a90.FUN_140a62270(spItem.get(), m_data->FUN_141a02e90(0, 0), m_data->FUN_141a02e90(1, 0), 1);
    }
    if (FUN_140166410()->FUN_14036d570(0xe8) && nResult == 0 && DAT_143ab2a90.FUN_140a66f20() == nUid)
        DAT_143ab2a90.FUN_140a66f40(0);
    return 1;
}
MS2_REPLACE_METHOD(0x1419FDF80, UIMessageBox, FUN_1419fdf80, 387, 0x7E745354);

// @0x1419fe110
int UIMessageBox::FUN_1419fe110(int nButton)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem == 0)
            return 0;
        int nCount = m_data->FUN_141a02e50(0, 0);
        FUN_141271960(spItem, nCount, 1);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FE110, UIMessageBox, FUN_1419fe110, 288, 0xC7608C36);

static int FUN_141a00250(__int64 nUid, int nCount);
static int FUN_141a002b0(__int64 nUid, int nCount);

// @0x1419fe240
int UIMessageBox::FUN_1419fe240(int nButton, int nCount)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        if (!FUN_141a002b0(nUid, nCount))
            return 1;
        DAT_143ab2d80.FUN_140de2dc0(nUid, 0, nCount, MS2Ptr<CItemData>(0));
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FE240, UIMessageBox, FUN_1419fe240, 198, 0x8FFC0149);

// @0x1419fe310
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419fe310(int nButton, int nCount)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        if (FUN_141a00250(nUid, nCount))
        {
            MS2Ptr<CItem> spItem = DAT_143ab2d80.FUN_140de1490(nUid);
            if (!!spItem == false)
            {
                int nSlot = DAT_143ab2a90.FUN_140a617f0(spItem);
                int nResult = DAT_143ab2a90.FUN_140a612b0(nSlot, spItem, nCount);
                if (nResult == -1)
                {
                    FUN_140961010(0x44, 1, 1, FUN_1401a9d70()->FUN_141813300(nSlot));
                    FUN_141276180(s_warning, CString(""));
                }
                else
                    DAT_143ab2d80.FUN_140de31f0(nUid, nResult, nCount, MS2Ptr<CItemData>(0));
            }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FE310, UIMessageBox, FUN_1419fe310, 624, 0x8F2EFD69);

// @0x1419fe590
int UIMessageBox::FUN_1419fe590(int nButton, int nCount)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        int nSlot = m_data->FUN_141a02c60();
        __int64 nUid = m_data->FUN_141a02c00();
        if (!FUN_141a002b0(nUid, nCount))
            return 1;
        DAT_143ab2d80.FUN_140de2dc0(nUid, nSlot, nCount, MS2Ptr<CItemData>(0));
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FE590, UIMessageBox, FUN_1419fe590, 235, 0x3212ADF6);

// @0x1419fe690
int UIMessageBox::FUN_1419fe690(int nButton, int nCount)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        int nSlot = m_data->FUN_141a02c60();
        __int64 nUid = m_data->FUN_141a02c00();
        if (!FUN_141a00250(nUid, nCount))
            return 1;
        DAT_143ab2d80.FUN_140de31f0(nUid, nSlot, nCount, MS2Ptr<CItemData>(0));
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FE690, UIMessageBox, FUN_1419fe690, 235, 0xA5B54A09);

// @0x1419fe790
int UIMessageBox::FUN_1419fe790(int nButton, int nCount)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        if (!FUN_141a002b0(nUid, nCount))
            return 1;
        FUN_140714f90()->FUN_141538930(nUid, nCount);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FE790, UIMessageBox, FUN_1419fe790, 150, 0x0DABE3E9);

// @0x1419fe830
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
int UIMessageBox::FUN_1419fe830(int nButton, int nCount)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        if (FUN_141a002b0(nUid, nCount))
        {
            FUN_14151f200();
            FUN_1419f8920(DAT_143ab2a90.FUN_140a5d680(nUid), nCount);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FE830, UIMessageBox, FUN_1419fe830, 193, 0xB5EC7C67);

// @0x1419fe900
int UIMessageBox::FUN_1419fe900(int nButton, int nCount)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        if (!FUN_141a002b0(nUid, nCount))
            return 1;
        if (FUN_1403ed2b0()->FUN_141adc940(0x4e83) == 0)
        {
            Unk_MessageBoxTradeDialog* pDialog = FUN_14140e820(0x4e83);
            if (pDialog)
            {
                int nSlot = 0;
                if (pDialog->FUN_141b283f0(&nSlot))
                {
                    FUN_14140ea30()->FUN_14185b9d0(nUid, nCount, nSlot);
                    FUN_141404930(nUid);
                }
            }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FE900, UIMessageBox, FUN_1419fe900, 244, 0xEB4B35A3);

// @0x1419fea00
int UIMessageBox::FUN_1419fea00(int nButton, int nCount)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        __int64 nUid = m_data->FUN_141a02c00();
        if (!FUN_141a002b0(nUid, nCount))
            return 1;
        FUN_141425fc0(nUid, nCount, DAT_143ab2a90.FUN_140a5d680(nUid).get());
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FEA00, UIMessageBox, FUN_1419fea00, 218, 0x20D8B1E2);

// @0x1419feae0
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419feae0(int nButton, const CStringW& strName)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        MS2Ptr<CMsgBoxData> spData = m_data;
        if (strName.IsEmpty())
        {
            UIMessageBox* pBox = FUN_14151f890();
            if (pBox)
                pBox->FUN_1419f82b0(FUN_14028de60(0xd));
            return 0;
        }
        CStringW strError;
        if (FUN_141276a30(strName, strError) == 0)
        {
            UIMessageBox* pBox = FUN_14151f890();
            if (pBox)
                pBox->FUN_1419f82b0(strError);
            return 0;
        }
        COutPacket packet(0x7d, 0);
        packet.COutPacket::vfunc_o10_8(strName);
        packet.Encode8(spData->FUN_141a02c00());
        FUN_140710590(packet);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FEAE0, UIMessageBox, FUN_1419feae0, 471, 0x6BA83DA0);

// @0x1419fecc0
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419fecc0(int nButton, const CStringW& strName)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        MS2Ptr<CMsgBoxData> spData = m_data;
        if (strName.IsEmpty())
        {
            UIMessageBox* pBox = FUN_14151f890();
            if (pBox)
                pBox->FUN_1419f82b0(FUN_14028de60(0xd));
            return 0;
        }
        CStringW strError;
        if (FUN_141276a30(strName, strError) == 0)
        {
            UIMessageBox* pBox = FUN_14151f890();
            if (pBox)
                pBox->FUN_1419f82b0(strError);
            return 0;
        }
        Unk_MessageBoxNameDialog* pDialog = FUN_140b72de0(0x4ef1);
        if (pDialog)
            pDialog->FUN_1418f2030(spData->FUN_141a02ed0(0, 0), strName);
    }
    else
    {
        Unk_MessageBoxNameDialog* pDialog = FUN_140b72de0(0x4ef1);
        if (pDialog)
            pDialog->FUN_1418f20d0();
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FECC0, UIMessageBox, FUN_1419fecc0, 490, 0x65602E3E);

// @0x1419feeb0
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419feeb0(int nButton, const CStringW& strName)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        MS2Ptr<CMsgBoxData> spData = m_data;
        if (strName.IsEmpty())
        {
            UIMessageBox* pBox = FUN_14151f890();
            if (pBox)
                pBox->FUN_1419f82b0(FUN_14028de60(0xd));
            return 0;
        }
        Unk_MessageBoxFilter* pFilter = FUN_14025e7d0()->FUN_140229a50().get();
        if (pFilter)
        {
            CStringW strMsg;
            if (pFilter->FUN_140225720(strName, strMsg))
            {
                FUN_1412751f0(strMsg, 1, 1);
                return 0;
            }
        }
        CItem* pItem = DAT_143ab2a90.FUN_140a5d680(spData->FUN_141a02c00()).get();
        if (!pItem)
            return 0;
        DAT_143ab2a90.FUN_140a63880(pItem, strName);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FEEB0, UIMessageBox, FUN_1419feeb0, 630, 0x2C053356);

// @0x1419ff130
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419ff130(int nButton, const CStringW& strName)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        if (FUN_14025e7b0()->m_shutdown.FUN_1402c4c90(0x3b))
        {
            FUN_141275260(0x2f7, 1, 1);
            return 0;
        }
        MS2Ptr<CMsgBoxData> spData = m_data;
        CItem* pItem = DAT_143ab2a90.FUN_140a5d680(spData->FUN_141a02c00()).get();
        if (!pItem)
            return 0;
        Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (!pPlayer)
            return 0;
        ATL::CAtlArray<void*> portals;
        NiPoint3 pos = pPlayer->vfunc_18();
        FUN_1403ed2d0()->FUN_141bc2c90(pos, portals);
        if (FUN_140966da0(portals))
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_msg_item_open_massive_error_another_portal")), 1, 1);
            return 0;
        }
        if (FUN_140930b10())
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_msg_item_open_massive_cant_open")), 1, 1);
            return 0;
        }
        if (FUN_14166c930(pPlayer) != 1)
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_msg_item_open_massive_invalid_state")), 1, 1);
            return 0;
        }
        if (FUN_1408e57f0()->FUN_1422b9e00() != 0x620001d)
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_msg_item_open_massive_invalid_state")), 1, 1);
            return 0;
        }
        int nOpen = 0;
        std::vector<int> ids;
        FUN_1403ed2d0()->FUN_141bc2980(ids);
        for (size_t i = 0; i < ids.size(); i++)
        {
            MS2Ptr<Unk_MessageBoxPortal> spPortal = FUN_1403ed2d0()->FUN_141bc2800(ids[i]);
            if (!(spPortal == 0))
            {
                if (spPortal->m_strName.GetLength() > 0)
                    nOpen++;
            }
        }
        if (nOpen > 9)
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_msg_item_open_massive_error_too_many_portal")), 1, 1);
            return 0;
        }
        DAT_143ab2a90.FUN_140a63880(pItem, strName);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FF130, UIMessageBox, FUN_1419ff130, 1684, 0x88C3FDCA);

// @0x1419ff7d0
int UIMessageBox::FUN_1419ff7d0(int nButton)
{
    if (nButton != 0)
        return 1;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPlayer)
    {
        (void)((!!(0)) || (_wassert(L"0", _CRT_WIDE(MS2_THIS_FILE), 0x8a9), 0));
        return 1;
    }
    pPlayer->vfunc_59(1, 0, 0, 0);
    return 1;
}
MS2_REPLACE_METHOD(0x1419FF7D0, UIMessageBox, FUN_1419ff7d0, 142, 0xBBEC0EC1);

// @0x1419ff870
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419ff870(int nButton)
{
    if (m_data == 0)
        return 1;
    unsigned int nEmotion = m_data->FUN_141a02e90(0, 0);
    __int64 nId = m_data->FUN_141a02f10(1, 0);
    CStringW strName = m_data->FUN_141a02fd0(2, CStringW());
    if (nButton == 0)
    {
        Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (FUN_1416764d0(pPlayer) == 0)
            FUN_140b845a0(nId, nEmotion);
        else
        {
            MS2Ptr<RideOffActionCoupleEmotion> spAction(new RideOffActionCoupleEmotion(0));
            spAction->m_n28 = nEmotion;
            spAction->m_n30 = nId;
            pPlayer->FUN_14152c280(spAction.get());
        }
    }
    else
    {
        COutPacket packet(0xa3, 0);
        packet.Encode1(4);
        packet.Encode4(nEmotion);
        packet.Encode8(nId);
        FUN_140710590(packet);
    }
    return 1;
}

// @0x1419ffb20
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
int UIMessageBox::FUN_1419ffb20(int nButton)
{
    if (m_data == 0)
        return 1;
    CStringW strName = m_data->FUN_141a02fd0(0, CStringW());
    int bAccept = nButton == 0;
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    Unk_MessageBoxActor* pTarget = FUN_1403ed2d0()->FUN_141bd1420(strName);
    if (!pPlayer || !pTarget)
    {
        (void)((!!(0)) || (_wassert(L"0", _CRT_WIDE(MS2_THIS_FILE), 0x8be), 0));
        return 1;
    }
    if (bAccept == 0)
    {
        COutPacket packet(0xa8, 0);
        packet.Encode2(3);
        packet.Encode8(pTarget->FUN_141656a80());
        FUN_140710590(packet);
        return 1;
    }
    else
    {
        COutPacket packet(0xa8, 0);
        packet.Encode2(2);
        packet.Encode8(pTarget->FUN_141656a80());
        FUN_140710590(packet);
        pPlayer->vfunc_59(0x3c, new StateMicroGameRpsData(FUN_14123c580(pTarget)), 0x99, 0);
        return 1;
    }
}

// @0x1419ffe20
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419ffe20(int nButton)
{
    if (m_data == 0)
        return 1;
    if (nButton == 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_data->FUN_141a02c00());
        if (spItem.get())
            DAT_143ab2a90.FUN_140a63880(spItem.get(), CStringW(L""));
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419FFE20, UIMessageBox, FUN_1419ffe20, 223, 0x879EDE35);

// @0x1419fff10
// MS2-FUNCTIONAL: stack frame / temporary slot layout differs from the exe
int UIMessageBox::FUN_1419fff10(int nButton)
{
    if (m_data == 0)
        return 1;
    unsigned int nRound = m_data->FUN_141a02e90(0, 0);
    __int64 nId = 0;
    m_data->FUN_140b19130(1, nId);
    Unk_MessageBoxPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    Unk_MessageBoxActor* pTarget = FUN_1403ed2d0()->FUN_141bd1530(nId);
    if (!pPlayer || !pTarget)
    {
        (void)((!!(0)) || (_wassert(L"0", _CRT_WIDE(MS2_THIS_FILE), 0x8e2), 0));
        return 1;
    }
    if (nButton == 0)
    {
        COutPacket packet(0xa8, 0);
        packet.Encode2(0xf);
        packet.Encode4(nRound);
        packet.Encode8(pTarget->FUN_141656a80());
        FUN_140710590(packet);
        pPlayer->vfunc_59(0x45, new StateMicroGameCoupleDanceData(FUN_14123c580(pTarget)), 0xa9, 0);
    }
    else
    {
        COutPacket packet(0xa8, 0);
        packet.Encode2(0x11);
        packet.Encode4(nRound);
        packet.Encode8(pTarget->FUN_141656a80());
        FUN_140710590(packet);
    }
    return 1;
}

// ---- template / helper zone ----

// The count check of the store / inventory "tag,count" boxes.
template <class A, class B> inline void Unk_MessageBoxCountMessage(int nId, int nA, int nB, const A& a, const B& b);

// @0x141a00180
static int FUN_141a00180(MS2Ptr<CItem> spItem, int nCount)
{
    if (!spItem)
        return 1;
    int nHave = spItem->FUN_140526c50();
    if (nCount <= 0 || nCount > nHave)
    {
        int nOne = 1;
        Unk_MessageBoxCountMessage(0xee, 1, 1, nOne, nHave);
        return 0;
    }
    return 1;
}

// @0x141a00250
static int FUN_141a00250(__int64 nUid, int nCount)
{
    if (nUid == 0)
        return 1;
    return FUN_141a00180(DAT_143ab2d80.FUN_140de1490(nUid), nCount);
}

// @0x141a002b0
static int FUN_141a002b0(__int64 nUid, int nCount)
{
    if (nUid == 0)
        return 1;
    return FUN_141a00180(DAT_143ab2a90.FUN_140a5d680(nUid), nCount);
}

// @0x141a00450
// MS2-FUNCTIONAL: branch/early-return layout differs from the exe
inline bool CMsgBoxData::FUN_141a00450(unsigned int nIndex, int& nOut) const
{
    if (nIndex >= m_args.GetCount())
        return false;
    nOut = _wtoi(m_args.GetAt(nIndex));
    return true;
}

void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* psz);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// @0x141a004c0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, long a1, int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141a00580
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, const char* a1, CStringW a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), (const wchar_t*)a2);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();  // memmove_s 0x141a00c90
