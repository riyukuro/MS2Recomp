// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item edit page (UIItemEditDialog, UI id 0x4e24): edits the worn
// costume through the item customize controller (Customize) and saves / resets it ("m_save" / "m_reset"). Sibling of
// UIBeautyShopDialog (same bases, same customize listener); the unit's range ends with the Delegate glue of its two
// callbacks and the CRT memmove_s copy.
// MS2-UNIT: ?\uiitemeditdialog.cpp
// MS2-RANGE: 0x1419bc730-0x1419be700 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVUIItemEditDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemEditDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x1419bdf20 ; prop
// MS2-PIN: ??$?8PEAVUIItemEditDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemEditDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x1419bdf90 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIItemEditDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x1419be0d0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemEditDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419be370 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemEditDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419be3d0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIItemEditDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x1419be430 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIItemEditDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x1419be460 ; unique
// MS2-PIN: ??$Call@VUIItemEditDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemEditDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIItemEditDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x1419be4a0 ; unique
// MS2-PIN: ??$Call@VUIItemEditDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemEditDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIItemEditDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x1419be4e0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemEditDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1419be520 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemEditDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1419be580 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemeditdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uiitemeditdialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- local stand-ins for classes whose units are not recovered yet ----

// The "my codi" tab notification (also declared in uibeautyshopdialog.cpp).
class NotifyChangeActiveMyCodiTab : public NotifyObject
{
public:
    NotifyChangeActiveMyCodiTab();
    virtual ~NotifyChangeActiveMyCodiTab();
    bool m_bActive;                             // +0x18 the "my codi" tab is still valid
};
MS2_CHECK_OFFSET(NotifyChangeActiveMyCodiTab, m_bActive, 0x18);

// The parent scene movie; only its RTTI is used.
class UISceneGameBeautyShop : public UISwfEntity
{
public:
    virtual ~UISceneGameBeautyShop();
};

// A button child of the page.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    int FUN_1422c2030();                                        // is enabled
    void FUN_1422c1fe0(unsigned int bEnabled);                  // enable
};

// The hair apply effect request.
struct Unk_IEEffectRequest
{
    CString m_strName;                          // +0x00 effect xml
    int m_n08;                                  // +0x08
    char m_pad_0c[0x78 - 0x0c];
};
MS2_CHECK_SIZE(Unk_IEEffectRequest, 0x78);
class Unk_IEEffectMgr { public: void FUN_1411a4a00(Unk_IEEffectRequest* pRequest); };
Unk_IEEffectMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_IEEffectRequest* p);         // construct
void FUN_140a53190(Unk_IEEffectRequest* p, int nObjectId);
void FUN_1405a89e0(Unk_IEEffectRequest* p);         // destroy
struct Unk_IEEffectPaths { char m_pad_0[0x2e0]; CString m_hairApply; };   // +0x2e0
Unk_IEEffectPaths* FUN_1401d31f0();

// A client constant holding a string (0x58 bytes each).
class Unk_IEConstStr
{
public:
    CString FUN_1409f6f30();                    // copy of the string
    char m_data[0x58];
};
struct Unk_IEConstants
{
    char m_pad_0[0xcc50];
    Unk_IEConstStr m_cc50;                      // +0xcc50 the item edit guide
};
MS2_CHECK_OFFSET(Unk_IEConstants, m_cc50, 0xcc50);
Unk_IEConstants* FUN_1401d3200();

// The player and its equipment.
class Unk_IEEquip : public CPtred
{
public:
    CItemData* FUN_1411dc7f0();                 // the worn item data
};
typedef MS2Ptr<Unk_IEEquip> Unk_IEEquipPtr;
class Unk_IEPlayer
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49();
    virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58();
    virtual void vfunc_59(int nState, int a2, int a3, int a4);      // 59 (0x1d8) switch the player state
    int FUN_14166c930();                        // the player state
    void FUN_14166cc40(int n);
    Unk_IEEquipPtr FUN_141655e10(int nSlot);    // the handle of the worn item of a slot
};
int FUN_14123c580(Unk_IEPlayer* pPc);           // object id

// The current field.
class Unk_IEField
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49();
    virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69();
    virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76(); virtual void vfunc_77(); virtual void vfunc_78(); virtual void vfunc_79();
    virtual void vfunc_80(); virtual void vfunc_81(); virtual void vfunc_82(); virtual void vfunc_83(); virtual void vfunc_84(); virtual void vfunc_85(); virtual void vfunc_86(); virtual void vfunc_87(); virtual void vfunc_88(); virtual void vfunc_89();
    virtual void vfunc_90(); virtual void vfunc_91(); virtual void vfunc_92(); virtual void vfunc_93(); virtual void vfunc_94(); virtual void vfunc_95(); virtual void vfunc_96(); virtual void vfunc_97(); virtual void vfunc_98(); virtual void vfunc_99();
    virtual void vfunc_100(); virtual void vfunc_101(); virtual void vfunc_102(); virtual void vfunc_103(); virtual void vfunc_104(); virtual void vfunc_105(); virtual void vfunc_106(); virtual void vfunc_107(); virtual void vfunc_108(); virtual void vfunc_109();
    virtual void vfunc_110(); virtual void vfunc_111(); virtual void vfunc_112(); virtual void vfunc_113(); virtual void vfunc_114(); virtual void vfunc_115(); virtual void vfunc_116(); virtual void vfunc_117(); virtual void vfunc_118(); virtual void vfunc_119();
    virtual void vfunc_120(); virtual void vfunc_121(); virtual void vfunc_122(); virtual void vfunc_123(); virtual void vfunc_124(); virtual void vfunc_125(); virtual void vfunc_126(); virtual void vfunc_127(); virtual void vfunc_128(); virtual void vfunc_129();
    virtual void vfunc_130(); virtual void vfunc_131(); virtual void vfunc_132(); virtual void vfunc_133(); virtual void vfunc_134(); virtual void vfunc_135(); virtual void vfunc_136(); virtual void vfunc_137(); virtual void vfunc_138(); virtual void vfunc_139();
    virtual void vfunc_140(); virtual void vfunc_141(); virtual void vfunc_142(); virtual void vfunc_143(); virtual void vfunc_144(); virtual void vfunc_145(); virtual void vfunc_146(); virtual void vfunc_147(); virtual void vfunc_148();
    virtual void vfunc_149();                   // 149 restore the field camera
};
class Unk_IEWorld
{
public:
    Unk_IEPlayer* FUN_141bd0cc0();              // the player (NULL outside the game)
    Unk_IEField* FUN_141bd3620();
};
Unk_IEWorld* FUN_1403ed2d0();

// Misc singletons.
class Unk_IECutScene { public: bool FUN_14116d840(); };
Unk_IECutScene* FUN_14025e7c0();
class Unk_IEItemEvents
{
public:
    void FUN_1419cae20(UIItemEventListener* pListener);
    void FUN_1419caeb0(UIItemEventListener* pListener);
};
Unk_IEItemEvents* FUN_140a6a840();
class Unk_IENotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb);
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> cb);
};
Unk_IENotices* FUN_140939a10();
class Unk_IEMgr { public: int FUN_141b21220(); void FUN_141b1feb0(); };
Unk_IEMgr* FUN_140967100();
Unk_BSCamera* FUN_140cd47b0(int nId);
class Unk_IESound;
Unk_IESound* FUN_1408e57f0();
void FUN_1422b9fd0(Unk_IESound* p, int nEvent);
void FUN_14151f200();                           // no arguments
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);
void* FUN_1405a8e70(void* pHandle);
void FUN_1405a85f0(void* pHandle);
int FUN_14053e210(CItemData* pData);
int FUN_1414124a0(void* pPart);                 // the item id of a part
void FUN_140d73aa0(CStringW strText, int nType, IMessageListener* pListener, CStringW strTag);
CStringW FUN_140f09f90(int nId, const int& nArg);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
CStringW FUN_14028de60(int nId);
CStringW FUN_14028b8e0(const CStringW& strKey);

MS2_EMIT_CRT_MEMMOVE_S();

// ---- UIItemEditDialog ----

// @0x1419bc730
UIItemEditDialog::UIItemEditDialog()
    : m_1a8(0), m_1b0(0)
{
    m_2c = 0xc;
    m_80 = 0;
    m_7c = 1;
    m_88 = 1;
    m_58 = 1;
    FUN_141925e70(0, 1);
}

// @0x1419bc850
CString UIItemEditDialog::vfunc_1()
{
    return "ItemEditDialog";
}

// @0x1419bc8a0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIItemEditDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIItemEditDialog::FUN_1419bd530));
    if (FUN_140967100()->FUN_141b21220() != 0)
        FUN_140967100()->FUN_141b1feb0();
    m_198 = 0;
    m_1a8 = 0;
    m_1b0 = 0;
}

// @0x1419bca20
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIItemEditDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    FUN_1419bdb50(0);
    Unk_IEPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
    {
        m_198.AssignRaw(new Customize(FUN_14123c580(pPc), static_cast<IItemCustomizeEventListener*>(this), 0));
        m_198->FUN_140cd25c0(6);
    }
    m_1a8 = FUN_140cd47b0(0x4ef2);
    if (m_30.get())
    {
        CString strGuide = FUN_1401d3200()->m_cc50.FUN_1409f6f30();
        m_30->Invoke("initData", CString(strGuide));
    }
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIItemEditDialog::FUN_1419bd530));
}

// @0x1419bcd40
int UIItemEditDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() == 0)
    {
        if (FUN_14025e7c0()->FUN_14116d840() == false)
            return 0;
        FUN_1419bd9f0();
        return 1;
    }
    return 1;
}

// @0x1419bcd90
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIItemEditDialog::vfunc_15()
{
    if (vfunc_55() == 0)
    {
        if (m_198.get())
            m_198->FUN_140cd1bf0();
        if (m_1a8)
            m_1a8->FUN_1418dda30(m_198->FUN_140cd27f0() == 0);
    }
}

// The answers of the scene (OnExit) and of the message box (errorEdit).
// @0x1419bce50
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIItemEditDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    UIDialog::OnMessage(pSender, pMsg);
    if (pMsg->FUN_1422e4520() == 0)
    {
        if (dynamic_cast<UISceneGameBeautyShop*>(pSender))
        {
            CString strMethod = pMsg->FUN_1422b8d30();
            if (_stricmp("OnExit", strMethod) == 0)
                FUN_1419bd9f0();
            return 1;
        }
        if (dynamic_cast<UIMessageBox*>(pSender))
        {
            int nResult = pMsg->FUN_1422b8a10();
            CStringW strTag = pMsg->FUN_1422b8f40();
            FUN_14151f200();
            if (nResult == 0 && FUN_1403b3c40(strTag, L"errorEdit"))
                FUN_1419bd860();
            return 1;
        }
    }
    return 0;
}

// The server result of the save (opcode 0x31).
// @0x1419bcfd0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIItemEditDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    if (pPacket->FUN_14070fe80() == 0x31)
    {
        m_1b0 = 0;
        unsigned nMode = pPacket->vfunc_o8_1();
        if (nMode == 8)
        {
            int nResult = pPacket->vfunc_o8_3();
            if (nResult != 0)
            {
                FUN_140d73aa0(FUN_140f09f90(0x272, nResult), 0, static_cast<IMessageListener*>(this),
                              CStringW(L"errorEdit"));
                OnReset();
            }
        }
    }
}

// @0x1419bd150
int UIItemEditDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) == 0)
    {
        if (_stricmp("OnSave", szMethod) == 0)
        {
            OnSave();
            return 1;
        }
        if (_stricmp("OnReset", szMethod) == 0)
        {
            OnReset();
            return 1;
        }
        if (_stricmp("OnClickClose", szMethod) == 0)
        {
            FUN_1419bd9f0();
            return 1;
        }
        return 0;
    }
    return 1;
}

// A worn item changed: play the apply effect and reset the page.
// @0x1419bd210
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIItemEditDialog::vfunc_24(void* p)
{
    if (p)
    {
        Unk_IEPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc)
        {
            if (pPc->FUN_14166c930() != 0xe)
                pPc->vfunc_59(0xe, 0, 0, 0);
            pPc->FUN_14166cc40(0x4c);
            Unk_IEEffectRequest effect;
            FUN_140a52ef0(&effect);
            effect.m_strName = FUN_1401d31f0()->m_hairApply;
            effect.m_n08 = 1;
            FUN_140a53190(&effect, FUN_14123c580(pPc));
            FUN_1403ed280()->FUN_1411a4a00(&effect);
            FUN_1419bdb50(0);
            m_1b0 = 0;
            FUN_1405a89e0(&effect);
        }
    }
}

// IItemCustomizeEventListener: a part changed; enable the buttons when it is the edited one.
// @0x1419bd330
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIItemEditDialog::vfunc_1(void* p)
{
    if (p == 0)
        return 0;
    if (m_198 == 0)
        return 0;
    if (m_198->FUN_140cd17e0() == FUN_1414124a0(p))
        FUN_1419bdb50(1);
    return 1;
}

// @0x1419bd3c0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIItemEditDialog::vfunc_3(void* p, float)
{
    if (p == 0)
        return 0;
    if (m_198 == 0)
        return 0;
    if (m_198->FUN_140cd17e0() == FUN_1414124a0(p))
        FUN_1419bdb50(1);
    return 1;
}

// @0x1419bd460
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIItemEditDialog::vfunc_2(void* p, float, int)
{
    if (p == 0)
        return 0;
    if (m_198 == 0)
        return 0;
    if (m_198->FUN_140cd17e0() == FUN_1414124a0(p))
        FUN_1419bdb50(1);
    return 1;
}

// The leave box answered: leave on OK.
// @0x1419bd500
bool UIItemEditDialog::FUN_1419bd500(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
        FUN_1419bd860();
    return true;
}

// The active my-codi tab changed.
// @0x1419bd530
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIItemEditDialog::FUN_1419bd530(NotifyObject* pNotify)
{
    if (!(m_30 == 0) && !(m_198 == 0))
    {
        NotifyChangeActiveMyCodiTab* pTab = dynamic_cast<NotifyChangeActiveMyCodiTab*>(pNotify);
        if (pTab == 0 || pTab->m_bActive)
            FUN_1419bd860();
        else
            FUN_140d74390(FUN_14028b8e0(CStringW(L"s_beauty_msg_exit_by_expired_codi")), 0,
                          Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEditDialog::FUN_1419bd500));
    }
}

// @0x1419bd6d0
bool UIItemEditDialog::FUN_1419bd6d0(int nResult, const CMsgBoxData&)
{
    if (nResult == 0)
        return FUN_1419bd710();
    return true;
}

// @0x1419bd710
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIItemEditDialog::FUN_1419bd710()
{
    if (!(m_30 == 0) && !(m_198 == 0))
    {
        if (FUN_1419bd7a0() == false)
            FUN_1419bd860();
        else
            m_198->FUN_140cd25c0(6);
    }
    return true;
}

// The worn costume can be edited.
// @0x1419bd7a0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIItemEditDialog::FUN_1419bd7a0()
{
    Unk_IEPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    Unk_IEEquipPtr spEquip = pPc->FUN_141655e10(6);
    if (spEquip.get() != 0)
    {
        CItemData* pData = spEquip->FUN_1411dc7f0();
        if (pData != 0 && FUN_14053e210(pData) != 0)
            return true;
    }
    return false;
}

// Leave the page: restore the worn item.
// @0x1419bd860
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
bool UIItemEditDialog::FUN_1419bd860()
{
    if (!(m_198 == 0))
    {
        if (m_198->FUN_140cd2a00() != 0)
            m_198->FUN_140cd22f0(6);
        Unk_IEField* pField = FUN_1403ed2d0()->FUN_141bd3620();
        if (pField)
            pField->vfunc_149();
        FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
        return true;
    }
    return false;
}

// @0x1419bd920
void UIItemEditDialog::OnSave()
{
    if (m_198.get())
        m_198->FUN_140cd2280(6);
    FUN_1419bdb50(0);
    m_1b0 = 1;
}

// @0x1419bd990
void UIItemEditDialog::OnReset()
{
    if (m_198.get())
        m_198->FUN_140cd22f0(6);
    FUN_1419bdb50(0);
}

// Close: ask first when something was changed.
// @0x1419bd9f0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIItemEditDialog::FUN_1419bd9f0()
{
    if (FUN_1419bdb90() == 0)
    {
        FUN_1419bd860();
    }
    else
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(FUN_14028de60(0x271), 1);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEditDialog::FUN_1419bd500));
        spBox->FUN_141a01800(2);
        FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
    }
}

// @0x1419bdb50
void UIItemEditDialog::FUN_1419bdb50(int bEnable)
{
    FUN_1419bdc40(bEnable);
    FUN_1419bdce0(bEnable);
}

// @0x1419bdb90
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UIItemEditDialog::FUN_1419bdb90()
{
    MS2Ptr<Unk_140acd6e0> spSave = FUN_140bb4b10(CString("m_save"));
    if (spSave.get() == 0)
        return 0;
    return spSave->FUN_1422c2030();
}

// @0x1419bdc40
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIItemEditDialog::FUN_1419bdc40(int bEnable)
{
    MS2Ptr<Unk_140acd6e0> spSave = FUN_140bb4b10(CString("m_save"));
    if (spSave.get())
        spSave->FUN_1422c1fe0(bEnable);
}

// @0x1419bdce0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UIItemEditDialog::FUN_1419bdce0(int bEnable)
{
    MS2Ptr<Unk_140acd6e0> spReset = FUN_140bb4b10(CString("m_reset"));
    if (spReset.get())
        spReset->FUN_1422c1fe0(bEnable);
}
