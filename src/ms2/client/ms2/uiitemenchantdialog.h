// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
// UIItemEnchantDialog (the item enchant window: ophelia / peachy exp mode) and its base UIItemModifyDialogBase.
// UIItemEventDispatcher is the TSingleton that fans the item events out to the registered UIItemEventListener objects.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/commonstruct_wa.h"

class ASData;
class ASObj;
class CInPacket;
class CMsgBoxData;
class NotifyObject;
class CEnchantOption;
class Unk_EnButton;
class UIItemEnchantDialog;
class Unk_EnSlot;
class Unk_EnSlotArgs;
class CIngredientContainer;

// Base of the item modify windows (enchant, ...). Size 0x190.
class UIItemModifyDialogBase : public UIDialog {
public:
    UIItemModifyDialogBase();                                   // 0x1419be860
    virtual ~UIItemModifyDialogBase();                          // 0x1412a3ed0 (unit_14129cfa0)
    virtual CString vfunc_1();                                  // 0x1419234e0 inherited UIDialog body (redeclared: the symbol table maps UIDialog::vfunc_1 to _purecall)
    virtual void vfunc_43();                                    // 0x1419be8e0 place beside the inventory (0x4e40)
    virtual void OnLoadComplete();                              // 0x1419bea10
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 0x1419bed80
    virtual void vfunc_67();                                    // 0x1419bedd0
    virtual void vfunc_84();                                    // 0x1419bee10 "initData"
    virtual void vfunc_85(int nType);                           // 0x1419bee80 packet 0x22 op 4
    virtual MS2Ptr<ASMovieClip> vfunc_86();                     // 0x1412a4070 returns a copy of m_enchantAni (unit_14129cfa0)
    int FUN_1419beef0(unsigned __int64 uid);                   // 0x1419beef0 (really a base member: UIItemRemakeOptionDialog calls it too)
    MS2Ptr<CItem> FUN_1419bef70(unsigned __int64 uid);          // 0x1419bef70
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);  // 0x140ba7930 bind a movie clip child (a UIDialog member: this+0x30)
protected:
    MS2_LAYOUT_FRIEND;
    int m_mode;                                                 // +0x178
    MS2Ptr<ASMovieClip> m_enchantAni;                           // +0x180
};
MS2_CHECK_SIZE(UIItemModifyDialogBase, 0x190);
MS2_CHECK_OFFSET(UIItemModifyDialogBase, m_mode, 0x178);
MS2_CHECK_OFFSET(UIItemModifyDialogBase, m_enchantAni, 0x180);

class UIItemEnchantDialog : public UIItemModifyDialogBase, public UIStatusEventListener, public UIItemEventListener {
public:
    UIItemEnchantDialog();                                      // 0x1419befc0
    virtual ~UIItemEnchantDialog();                             // 0x1419bf160
    virtual CString vfunc_1();                                  // 0x1419bf2c0 "ItemEnchantDialog"
    virtual void OnLoadInit();                                  // 0x1419bf310
    virtual void OnLoadComplete();                              // 0x1419bf410
    virtual int vfunc_13();                                     // 0x1419bfc40
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 0x1419bf910
    virtual void vfunc_43();                                    // 0x1419bfc20
    virtual int vfunc_48();                                     // 0x1419ca850
    virtual void vfunc_67();                                    // 0x1419bf590
    virtual void vfunc_85(int nType);                           // 0x1419bfca0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // 0x1419bfc50
    void FUN_1419bfd70();                                 // 0x1419bfd70
    void FUN_1419bff60();                                 // 0x1419bff60
    void FUN_1419c02e0(CString name);                                 // 0x1419c02e0
    void SendRequestItemEnchantMode15(ASData*);                                 // 0x1419c0360
    void SendRequestItemEnchantMode19(ASData*);                                 // 0x1419c03d0
    void FUN_1419c0440(ASData* pData);                                 // 0x1419c0440
    void SendRequestItemEnchantMode6(unsigned __int64 uid);                                 // 0x1419c0c70
    void FUN_1419c0d40(ASData* pData);                                 // 0x1419c0d40
    void OnComplete();                                 // 0x1419c10e0
    void OnRetry();                                 // 0x1419c11e0
    void FUN_1419c1220(ASData* pData);                                 // 0x1419c1220
    void OnClickFailStackUp();                                 // 0x1419c15c0
    void OnClickFailStackDown();                                 // 0x1419c1630
    unsigned __int64 GetSelectedUid();                                 // 0x1419c16a0
    void FUN_1419c16c0(unsigned __int64 uid, int flag);                                 // 0x1419c16c0
    void FUN_1419c19d0();                                 // 0x1419c19d0
    void FUN_1419c1a40(ATL::CAtlArray<unsigned __int64>& out);                                 // 0x1419c1a40
    int FUN_1419c1d60();                                 // 0x1419c1d60
    unsigned FUN_1419c1e00();                                 // 0x1419c1e00
    CString FUN_1419c1e40(CItem* item);                               // 0x1419c1e40
    void FUN_1419c1f20(CInPacket& pkt);                                 // 0x1419c1f20
    void FUN_1419c2e30(CItem* item, int prevLevel, CInPacket& pkt);                                 // 0x1419c2e30
    void FUN_1419c3390(CItem* item, CEnchantOption* stat, int prevLevel);                                 // 0x1419c3390
    void FUN_1419c37f0(unsigned __int64 uid, Unk_EnSlotArgs* slot);                                 // 0x1419c37f0
    void FUN_1419c3950(CInPacket& pkt);                                 // 0x1419c3950
    void FUN_1419c3b90(CInPacket& pkt);                                 // 0x1419c3b90
    void FUN_1419c3e70(CInPacket& pkt);                                 // 0x1419c3e70
    void SendRequestItemEnchantMode1(void*, void*, void*);                                 // 0x1419c3fd0
    void FUN_1419c4050();                                 // 0x1419c4050
    void FUN_1419c41b0();                                 // 0x1419c41b0
    void FUN_1419c4360(unsigned __int64 uid);                                 // 0x1419c4360
    bool FUN_1419c4a50(int result, const CMsgBoxData& box);                                 // 0x1419c4a50
    bool FUN_1419c4e00(int result, const CMsgBoxData& box);                                 // 0x1419c4e00
    bool FUN_1419c5890(int result, const CMsgBoxData& box);                                 // 0x1419c5890
    bool FUN_1419c5d20(int result, const CMsgBoxData& box);                                 // 0x1419c5d20
    bool FUN_1419c5d90(int result, const CMsgBoxData& box);                                 // 0x1419c5d90
    bool SendRequestItemEnchantMode2(int result, const CMsgBoxData& box);                                 // 0x1419c5de0
    bool FUN_1419c5e90(int result, const CMsgBoxData& box);                                 // 0x1419c5e90
    bool FUN_1419c5f00(int result, const CMsgBoxData& box);                                 // 0x1419c5f00
    void SendRequestItemEnchantMode17(const Scaleform::GFx::FunctionHandler::Params&);                                 // 0x1419c5f60
    void SendRequestItemEnchantMode18(const Scaleform::GFx::FunctionHandler::Params&);                                 // 0x1419c6060
    void FUN_1419c6160(const Scaleform::GFx::FunctionHandler::Params&);                                 // 0x1419c6160
    void FUN_1419c6270(const Scaleform::GFx::FunctionHandler::Params&);                                 // 0x1419c6270
    void FUN_1419c6380(NotifyObject* pNotify);                                 // 0x1419c6380
    void FUN_1419c6420();                                 // 0x1419c6420
    CStringW FUN_1419c65b0(MS2Ptr<CItem> item, CEnchantOption* pOption);                                 // 0x1419c65b0
    void FUN_1419c6840(MS2Ptr<CItem> item, CEnchantOption* pOption, ASObj& dest);                                 // 0x1419c6840
    void FUN_1419c6bb0(ASObj& dest, CItem* item);                                 // 0x1419c6bb0
    void FUN_1419c6cd0(ASObj& dest, CIngredientContainer* container);                                 // 0x1419c6cd0
    void FUN_1419c7140(ASObj& dest);                                 // 0x1419c7140
    void FUN_1419c74e0(ASObj& dest, CItem* item);                                 // 0x1419c74e0
    void FUN_1419c7610(ASObj& dest);                                 // 0x1419c7610
    void FUN_1419c77a0();                                 // 0x1419c77a0
    CString FUN_1419c78a0(CItem* item, CString key, ATL::CAtlArray<CString>& names);                                 // 0x1419c78a0
    CStringW FUN_1419c7970(float rate);                                 // 0x1419c7970
    void FUN_1419c7a30(unsigned __int64 uid, int mode);                                 // 0x1419c7a30
    void SendRequestItemEnchantMode4(unsigned __int64 uid, int mode);                                 // 0x1419c7ce0
    CStringW FUN_1419c7e20(CItem* item);                                 // 0x1419c7e20
    CStringW FUN_1419c7ec0(int level, int rank);                                 // 0x1419c7ec0
    CStringW FUN_1419c7f50(CItem* item, int count);                                 // 0x1419c7f50
    CStringW FUN_1419c8020();                                 // 0x1419c8020
    void FUN_1419c8070(CItem* item);                                 // 0x1419c8070
    Unk_EnSlot* FUN_1419c8160(const CString& name);                                 // 0x1419c8160
    void FUN_1419c81a0();                                 // 0x1419c81a0
    int FUN_1419c86b0(int itemId);                                 // 0x1419c86b0
    int FUN_1419c8830(int itemId);                                 // 0x1419c8830
    int FUN_1419c89b0(unsigned __int64 uid);                                 // 0x1419c89b0
    int FUN_1419c8b80(unsigned __int64 uid);                                 // 0x1419c8b80
    CStringW FUN_1419c8ce0(CItem* item);                                 // 0x1419c8ce0
    void FUN_1419c90b0(unsigned int itemId, int count, __int64 arg);                                 // 0x1419c90b0
    int FUN_1419c9260(CItem* base, CItem* other);                                 // 0x1419c9260
    int FUN_1419c93a0(CItem* base, CItem* other);                                 // 0x1419c93a0
    bool FUN_1419c9490(CItem* base, CItem* other);                                 // 0x1419c9490
    int FUN_1419c9530(CItem* base);                                 // 0x1419c9530
    int FUN_1419c9630(CItem* base, CItem* other);                                 // 0x1419c9630
private:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_selectedUid;                             // +0x1a0
    int m_expMode;                                              // +0x1a8 1 = ophelia, 2 = peachy
    ATL::CAtlArray<CString> m_bag0;                    // +0x1b0
    ATL::CAtlArray<CString> m_bag1;                    // +0x1d0
    int m_state;                                                // +0x1f0
    MS2Ptr<CItem> m_item;                                       // +0x1f8
    int m_208;                                                  // +0x208
    unsigned __int64 m_210;                                     // +0x210
    int m_218;                                                  // +0x218
    unsigned __int64 m_220;                                     // +0x220
    float m_228, m_22c, m_230, m_234, m_238, m_23c;             // +0x228
    CIngredientContainer m_ingredients;                         // +0x240
    MS2Ptr<Unk_EnButton> m_debugBtnFillIngredientUnit;          // +0x270
    MS2Ptr<Unk_EnButton> m_debugBtnFillIngredient;              // +0x280
    MS2Ptr<Unk_EnButton> m_debugBtnFillFailStack;               // +0x290
    MS2Ptr<Unk_EnButton> m_debugBtnUseAllFailStack;             // +0x2a0
    unsigned m_2b0;                                             // +0x2b0
    float m_2b4;                                                // +0x2b4
    unsigned m_2b8;                                             // +0x2b8
    int m_2bc;                                                  // +0x2bc
    int m_failStack;                                            // +0x2c0
    ATL::CAtlArray<unsigned __int64> m_failStackUids;           // +0x2c8
    ItemEntity m_result;                                        // +0x2e8
    MS2Ptr<CEnchantOption> m_option;                            // +0x318
};
MS2_CHECK_SIZE(UIItemEnchantDialog, 0x328);
MS2_CHECK_OFFSET(UIItemEnchantDialog, m_selectedUid, 0x1a0);
MS2_CHECK_OFFSET(UIItemEnchantDialog, m_bag0, 0x1b0);
MS2_CHECK_OFFSET(UIItemEnchantDialog, m_item, 0x1f8);
MS2_CHECK_OFFSET(UIItemEnchantDialog, m_228, 0x228);
MS2_CHECK_OFFSET(UIItemEnchantDialog, m_ingredients, 0x240);
MS2_CHECK_OFFSET(UIItemEnchantDialog, m_debugBtnFillIngredientUnit, 0x270);
MS2_CHECK_OFFSET(UIItemEnchantDialog, m_failStack, 0x2c0);
MS2_CHECK_OFFSET(UIItemEnchantDialog, m_failStackUids, 0x2c8);
MS2_CHECK_OFFSET(UIItemEnchantDialog, m_result, 0x2e8);
MS2_CHECK_OFFSET(UIItemEnchantDialog, m_option, 0x318);

// The item event hub: a TSingleton (global via FUN_140a6a840) with the registered listeners at +0x8. Each slot walks the
// listeners and forwards to the same-named slot (+1) of every live UIItemEventListener.
class UIItemEventDispatcher : public TSingleton<UIItemEventDispatcher> {
public:
    UIItemEventDispatcher();                                    // 0x1419cad80
    virtual ~UIItemEventDispatcher();                           // 0x1419cadd0
    virtual void vfunc_1(void*);                         // 0x1419caf40
    virtual void vfunc_2(void*, bool);                   // 0x1419cafe0
    virtual void vfunc_3(void*, int);                    // 0x1419cb090
    virtual void vfunc_4(void*, int);                    // 0x1419cb140
    virtual void vfunc_5(void*);                         // 0x1419cb1f0
    virtual void vfunc_6(void*);                         // 0x1419cb290
    virtual void vfunc_7(void*);                         // 0x1419cb330
    virtual void vfunc_8(void*);                         // 0x1419cb3d0
    virtual void vfunc_9(void*);                         // 0x1419cb470
    virtual void vfunc_10(void*);                         // 0x1419cb510
    virtual void vfunc_11();                              // 0x1419cb5b0
    virtual void vfunc_12();                              // 0x1419cb640
    virtual void vfunc_13(void*);                         // 0x1419cb6d0
    virtual void vfunc_14(void*);                         // 0x1419cb770
    virtual void vfunc_15(void*);                         // 0x1419cb810
    virtual void vfunc_16(void*, int);                    // 0x1419cb8b0
    virtual void vfunc_17(void*);                         // 0x1419cb960
    virtual void vfunc_18(void*);                         // 0x1419cba00
    virtual void vfunc_19(void*);                         // 0x1419cbaa0
    virtual void vfunc_20(void*);                         // 0x1419cbb40
    virtual void vfunc_21(void*);                         // 0x1419cbbe0
    virtual void vfunc_22(void*);                         // 0x1419cbc80
    virtual void vfunc_23(void*);                         // 0x1419cbd20
    virtual void vfunc_24(void*);                         // 0x1419cbdc0
    virtual void vfunc_25(int);                           // 0x1419cbe60
    virtual void vfunc_26(int);                           // 0x1419cbf00
    virtual void vfunc_27(void*);                         // 0x1419cbfa0
    virtual void vfunc_28(void*);                         // 0x1419cc040
    virtual void vfunc_29(void*);                         // 0x1419cc0e0
    virtual void vfunc_30(void*);                         // 0x1419cc180
    virtual void vfunc_31(void*, int, int);               // 0x1419cc220
    virtual void vfunc_32(int, int);                      // 0x1419cc2e0
    virtual void vfunc_33();                              // 0x1419cc390
private:
    ATL::CAtlArray<UIItemEventListener*> m_listeners;           // +0x08
};
