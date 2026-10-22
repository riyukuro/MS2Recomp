// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uigamemenudialog.h (name assumed: the
// .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIGameMenuDialog is the always-present game menu (UI type 0x4e28, RTTI .?AVUIGameMenuDialog@@, 0x260 bytes): the
// strip of menu buttons whose entries come from the menu table (add / modify through the movie's "addMenuEntity" /
// "modifyMenuEntity"), with the red-circle / new / count badges per entry, the pet info, the quest and contract
// buttons and the entry points of the event dialogs (the free FUN_ functions of the .cpp open them).
// It is a UIBuiltInDialog (0x178) and listens to dialog, item, UGC, quest and status events: six vftables, the
// listener bases are 8-byte vptr-only sub-objects at +0x178 (UIDialogEventListener), +0x180 (UIItemEventListener),
// +0x188 (UIUGCEventListener), +0x190 (UIQuestEventListener) and +0x198 (UIStatusEventListener).
// Member names are invented where the exe has no name (vfunc_N / FUN_<va> otherwise).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/placeholder/uibuiltindialog.h"
#include "ms2/placeholder/uidialogeventlistener.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"        // UIQuestEventListener (13 slots)

class ASData;
class ASObj;
class CInPacket;
class CMsgBoxData;
class GameEventVariable;
class NotifyObject;
class Unk_GmItem;
class Unk_GmClip;
class Unk_UISwfEntity_25;

enum EMenuKey { EMenuKey_None = 0 };     // menu id key type of m_menuText (the exe has a separate CAtlMap instance for it)

class UIGameMenuDialog : public UIBuiltInDialog,
                         public UIDialogEventListener,
                         public UIItemEventListener,
                         public UIUGCEventListener,
                         public UIQuestEventListener,
                         public UIStatusEventListener
{
public:
    UIGameMenuDialog();                                                                             // 0x141935f20
    virtual ~UIGameMenuDialog();                                                                    //  0 0x141936310 (??_G 0x14193fe60)
    virtual CString GetTypeName();                                                                      //  1 0x141936630 "GameMenuDialog"
    virtual void OnLoadComplete();                                                                  // 22 0x141936a20
    virtual int vfunc_13();                                                                        // 13 0x141936e00
    virtual void vfunc_15();                                                                        // 15 0x141937980
    virtual void vfunc_16();                                                                        // 16 0x141937910
    virtual bool vfunc_17();                                                                        // 17 0x141937940
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);              // 25 0x141937290
    virtual void vfunc_26();                                                                        // 26 0x1419369e0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141936e30
    virtual void vfunc_43();                                                                        // 43 0x141936d40
    virtual int vfunc_48() { return 0x4e28; }                                                        // 48 0x1419405e0
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);                           // 49 0x141937a30 tooltips
    virtual int vfunc_65();                                                                         // 65 0x141936680
    virtual void vfunc_67();                                                                        // 67 0x1419366b0
    // UIDialogEventListener (+0x178)
    virtual void vfunc_dl_1(int n);                                                                 // o178 1 0x141937430
    virtual void vfunc_dl_2(int n);                                                                 // o178 2 0x141937470
    // UIItemEventListener (+0x180)
    virtual void vfunc_2(void*);                                                                    // o180 2 0x141937500
    virtual void vfunc_3(void*, bool);                                                              // o180 3 0x141937520
    virtual void vfunc_4(void*, int);                                                               // o180 4 0x141937560
    virtual void vfunc_5(void*, int);                                                               // o180 5 0x1419374c0
    virtual void vfunc_21(void*);                                                                   // o180 21 0x141937870
    virtual void vfunc_22(void*);                                                                   // o180 22 0x1419378a0
    virtual void vfunc_33(int n, int);                                                              // o180 33 0x1419378d0
    // UIUGCEventListener (+0x188)
    virtual void vfunc_ugc_5();                                                                     // o188 5 0x14193d640
    virtual void vfunc_ugc_6();                                                                     // o188 6 0x14193d6a0
    // UIQuestEventListener (+0x190)
    virtual void vfunc_o178_1(void* p);                                                             // o190 1 0x141937650
    virtual void vfunc_o178_2(void* p);                                                             // o190 2 0x1419376a0
    virtual void vfunc_o178_5(void*);                                                               // o190 5 0x141937740
    virtual void vfunc_o178_8(void* p);                                                             // o190 8 0x1419375a0
    virtual void vfunc_o178_10(void*);                                                              // o190 10 0x141937770
    virtual void vfunc_o178_11(void*);                                                              // o190 11 0x141937830
    // UIStatusEventListener (+0x198)
    virtual void vfunc_oa0_9(unsigned short);                                                       // o198 9 0x141937d70
    virtual void vfunc_oa0_20(int);                                                                 // o198 20 0x141937dd0
    virtual void vfunc_oa0_29();                                                                    // o198 29 0x141937ca0

    // ---- non-virtual members, sorted by address ----
    void FUN_141937e00();
    void FUN_141937e40();
    void FUN_141937e70();
    void FUN_141937ea0();
    void FUN_141937ed0();
    void FUN_141938100();
    void FUN_141938190();
    void FUN_1419381c0();
    void FUN_1419381f0(CInPacket& packet);
    void FUN_141938270(int bUp, int nA, int nB);
    void FUN_141938350(int nId, int bUp);
    void FUN_141938490(int nId, const CStringW& strText);
    void FUN_1419384d0();
    void FUN_141938700();
    void FUN_141938850();
    int FUN_141938a00(CString strName);
    void FUN_141938ae0(int nId, int nValue);
    void FUN_1419391c0();
    void FUN_141939320(bool bValue);
    void FUN_141939360(bool bValue);
    void FUN_1419394a0(bool bValue);
    void FUN_1419394e0(bool bValue);
    void FUN_141939620();
    void FUN_141939770(int nId, int nEnable);
    void FUN_1419398d0();
    void FUN_141939910();
    void FUN_141939cf0(int nId);
    void FUN_141939ec0();
    void FUN_14193a020(NotifyObject* pNotify);
    void FUN_14193a0f0(NotifyObject*);
    void FUN_14193a120();
    void FUN_14193a140();
    int FUN_14193a7b0(int nId, ASObj* pObj);
    void FUN_14193ab80();
    void FUN_14193abe0();
    void FUN_14193ac40(int nEnable, int nId);
    CString FUN_14193ae90(int nId);
    CString FUN_14193afc0(int nId);
    MS2Ptr<Unk_GmItem> FUN_14193b0f0(int nId, void*);
    MS2Ptr<Unk_GmItem> FUN_14193b180(const CString& strName);
    // game menu button handlers bound by CGameMenuTable::RegisterDefs (0x140cf1110)
    void FUN_14193b5b0();
    void FUN_14193b630();
    void FUN_14193b670();
    void FUN_14193bda0();
    void FUN_14193bdf0();
    void FUN_14193c3c0();
    void FUN_14193c550();
    void FUN_14193c630();
    void FUN_14193c660();
    void FUN_14193c730();
    void FUN_14193c780();
    void FUN_14193c800();
    void FUN_14193c930();
    void FUN_14193cea0();
    void FUN_14193cf60();
    void FUN_14193d250();
    void FUN_14193d320();
    void FUN_14193d3d0();
    void FUN_14193d400();
    void FUN_14193d520();
    void FUN_14193d560();
    void FUN_14193d590();
    void FUN_14193d5c0();
    void FUN_14193d5e0();
    void FUN_14193d700();
    void FUN_14193b2f0(CInPacket&);
    void FUN_14193b320(GameEventVariable*);
    void FUN_14193b360();
    void FUN_14193b4a0(void* pQuest);
    int FUN_14193b530(int nId);
    int FUN_14193b570(int nId);
    void FUN_14193b750();
    void FUN_14193bbe0();
    void FUN_14193bf70();
    void FUN_14193bfa0();
    void FUN_14193bfd0();
    void FUN_14193c000();
    void FUN_14193d030();
    bool FUN_14193d8a0(int nResult, const CMsgBoxData& box);
    bool SendBeauty(int nResult, const CMsgBoxData& box);
    bool FUN_14193d9e0(int nResult, const CMsgBoxData&);
    bool SendQuest(int nResult, const CMsgBoxData&);
    bool FUN_14193dab0(int nResult, const CMsgBoxData&);
    void FUN_14193daf0(bool bEvent);
    void FUN_14193dd50();
    void FUN_14193dd70();
    void FUN_14193dd90(Scaleform::GFx::Value* pOut, int nId, const CStringW& strFmt, int nTipId);
    void FUN_14193df10(Scaleform::GFx::Value* pOut);
    void FUN_14193e0e0(Scaleform::GFx::Value* pOut);
    void FUN_14193e2e0(int nMapType);
    void OnPetAttack();
    int FUN_14193e940(int nField);

    // The menu strip is a movie clip child ("m_menus"); 0x140ba7930 binds it by name.
    MS2Ptr<Unk_GmClip> FUN_140ba7930(const CString& strName);

private:
    MS2_LAYOUT_FRIEND;

    int m_nDirty;                                       // +0x1a0 a menu table change is pending (rebuilt by the next refresh)
    bool m_bPetUpdate;                                  // +0x1a4
    ATL::CAtlMap<EMenuKey, CStringW> m_menuText;             // +0x1a8 menu id -> event popup text
    ATL::CAtlArray<int> m_order;                        // +0x1f0 the menu ids of the last build (the "new" badge)
    ATL::CAtlMap<EMenuKey, int> m_enabled;              // +0x210 menu id -> enabled (key by reference: SetAt 0x140c1e090)
    bool m_bFlag258;                                    // +0x258 UGC terms accepted
    bool m_bFlag259;                                    // +0x259 red circle of the UGC entry (id 0x16)
    bool m_bFlag25a;                                    // +0x25a red circle of the entry with id 7
};
MS2_CHECK_SIZE(UIGameMenuDialog, 0x260);
MS2_CHECK_OFFSET(UIGameMenuDialog, m_nDirty, 0x1a0);
MS2_CHECK_OFFSET(UIGameMenuDialog, m_bPetUpdate, 0x1a4);
MS2_CHECK_OFFSET(UIGameMenuDialog, m_menuText, 0x1a8);
MS2_CHECK_OFFSET(UIGameMenuDialog, m_order, 0x1f0);
MS2_CHECK_OFFSET(UIGameMenuDialog, m_enabled, 0x210);
MS2_CHECK_OFFSET(UIGameMenuDialog, m_bFlag258, 0x258);
