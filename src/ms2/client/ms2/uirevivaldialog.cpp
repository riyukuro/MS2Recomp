// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIRevivalDialog: see uirevivaldialog.h. w290.
// MS2-UNIT: ?\uirevivaldialog.cpp
// MS2-RANGE: 0x141aba6a0-0x141abe1d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIRevivalDialog@@UEAAHXZ 0x141abdf60 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIRevivalDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141abdf70 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIRevivalDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141abe050 ; unique
// MS2-PINS-END tplpin
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uirevivaldialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uirevivaldialog.h"
#include "uimessageboxdata.h"
#include "uiservice.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The field data record (a few members read here).
struct Unk_RevFieldData
{
    char m_pad_00[0x38];
    int m_38;                                           // +0x38 the id of the field to return to
    char m_pad_3c[0x60 - 0x3c];
    int m_60;                                           // +0x60
    char m_pad_64[0x130 - 0x64];
    int m_130;                                          // +0x130 revival forbidden in this field
    char m_pad_134[0x13c - 0x134];
    int m_13c;                                          // +0x13c
    int FUN_1403754f0();
};
MS2_CHECK_OFFSET(Unk_RevFieldData, m_13c, 0x13c);

// A counted reference to a field data record (16 bytes; the reference count handle sits at +8).
class Unk_RevFieldRef
{
public:
    Unk_RevFieldRef(const Unk_RevFieldRef& o);          // 0x141abde80
    ~Unk_RevFieldRef();                                 // 0x1408850f0 release
    bool FUN_1408851f0() const;
    bool FUN_140965240(int n) const;                    // == n
    long long FUN_1409657a0() const;
    Unk_RevFieldData* FUN_140885340() const;            // operator->
    void FUN_140a57040();                               // add a reference
private:
    void* m_0;
    void* m_8;
};
MS2_CHECK_SIZE(Unk_RevFieldRef, 0x10);
Unk_RevFieldRef FUN_140a55460(int nFieldId);

// The dungeon room record (members read here).
struct Unk_RevDgData
{
    char m_pad_00[0x109];
    unsigned char m_109;                                     // +0x109
    unsigned char m_10a;                                // +0x10a
    char m_pad_10b[0x140 - 0x10b];
    int m_140;                                          // +0x140
};
MS2_CHECK_OFFSET(Unk_RevDgData, m_140, 0x140);

class Unk_RevDgRef
{
public:
    ~Unk_RevDgRef();                                    // 0x14031c0f0 release
    bool FUN_140334010(int n) const;                    // == n
    long long FUN_14031c160() const;
    Unk_RevDgData* FUN_1403347d0() const;               // operator->
private:
    void* m_0;
    void* m_8;
};
MS2_CHECK_SIZE(Unk_RevDgRef, 0x10);
class Unk_RevDgTable { public: Unk_RevDgRef FUN_1403206b0(int nId); };
Unk_RevDgTable* FUN_14031c2a0();

// The player's equip / stat holder.
class Unk_RevStats { public: float FUN_1411e1110(int nStat); };
// The player's buff / ability list.
class Unk_RevAbility
{
public:
    int FUN_140970020(unsigned nId, int nSub, int a3, int a4);
    int FUN_140970d90(unsigned nId, int nSub);
    bool FUN_140970ad0();
};
// The player's state holder.
class Unk_RevState { public: int FUN_140639340(); };

// The local player (slot 78 of the vftable returns the job id).
class Unk_RevPC
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
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
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual short vfunc_78();                           // 78: the job id
    int FUN_14166ce30();
    Unk_RevState* FUN_1416546d0();
    int FUN_141661970();
    int FUN_141658f30();                                // level
    unsigned int FUN_141528160();
    Unk_RevAbility* FUN_1416749a0();
    Unk_RevStats* FUN_1416561a0();
};

// The world (singleton 0x1403ed2d0).
class Unk_RevWorld
{
public:
    Unk_RevPC* FUN_141bd0cc0();                         // the local player
    Unk_RevFieldRef FUN_141bd30a0();                    // the current field data
    int FUN_141bd3060();                                // the current field id
    int FUN_141bdb660(int n);
};
Unk_RevWorld* FUN_1403ed2d0();

// The client constants (singleton 0x1401d3200): the revival related values.
class Unk_RevUIntVal { public: unsigned* FUN_1401d7c10(); };
class Unk_RevFloatVal { public: float* FUN_140298f40(); };
class Unk_RevIntVal { public: int* FUN_1402056b0(); };
struct Unk_RevConsts
{
    char m_pad_0[0x51d8];
    Unk_RevUIntVal m_51d8;
    char m_pad_51d9[0x8cc0 - 0x51d9];
    Unk_RevFloatVal m_8cc0;
    char m_pad_8cc1[0x90f8 - 0x8cc1];
    float m_90f8;                                       // +0x90f8
    char m_pad_90fc[0xa278 - 0x90fc];
    unsigned char m_a278;                                     // +0xa278
    char m_pad_a279[0xcfe0 - 0xa279];
    Unk_RevIntVal m_cfe0;                               // +0xcfe0 the auto-decline countdown
};
MS2_CHECK_OFFSET(Unk_RevConsts, m_cfe0, 0xcfe0);
Unk_RevConsts* FUN_1401d3200();
unsigned* FUN_1401d7c10(Unk_RevUIntVal* p);
float* FUN_140298f40(Unk_RevFloatVal* p);
int* FUN_1402056b0(Unk_RevIntVal* p);

class Unk_RevJob
{
public:
    int FUN_140676830(short nJob, int nFlag);
    int FUN_1406771e0(short nJob, int nA, int nB);
};
Unk_RevJob* FUN_1401c0db0();
class Unk_RevRule { public: int FUN_140477d10(int nLevel); };
Unk_RevRule* FUN_1401c0d90();
class Unk_RevFeatures
{
public:
    bool FUN_14036d570(int nFeature);
    bool FUN_14036d6d0();
};
Unk_RevFeatures* FUN_140166410();

// The string table singleton: FUN_141811980(table, id).
class Unk_RevStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_RevStrings* FUN_1401a9d70();

// The platform host (singleton 0x140d86260): slots 40/41 test whether a cost can be paid, 43 raises a notice.
class Unk_RevNet
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
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
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual bool vfunc_40(__int64 nCost);
    virtual bool vfunc_41(__int64 nCost);
    virtual void vfunc_42();
    virtual void vfunc_43(int nA, int nB, int nC);
};
Unk_RevNet* FUN_140d86260();

// The player's inventory (global 0x143ab2a90) and a counted item handle.
class Unk_RevItemHandle
{
public:
    ~Unk_RevItemHandle();                               // 0x1401bfde0 release
    void* FUN_14052cd70() const;                        // the item
private:
    void* m_0;
    void* m_8;
};
MS2_CHECK_SIZE(Unk_RevItemHandle, 0x10);
class Unk_RevInventory { public: Unk_RevItemHandle FUN_140a5e040(int nTab); };
extern Unk_RevInventory g_revInventory;                 // 0x143ab2a90

extern int DAT_143ab2884;                               // the dungeon room id
extern int DAT_143ab2950;
extern __int64 DAT_143ab2898;                           // the free revival limit

// The check box child (the coupon).
class Unk_RevCheck : public ASDisplayObject
{
public:
    int FUN_1422c2030();
    bool FUN_1422ce0e0();
    void FUN_1422ce090(int n);
    void FUN_1422c1fe0(int n);
};

// The movie root: the data calls.
class Unk_RevMovie : public AScript
{
public:
    Scaleform::GFx::Value FUN_140e0a8c0(const char* szMethod, CStringW strText, int nKind);
    Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int nButton, CStringW strLabel);
};
// The game entity clip (slot 13 = goto label, slot 25 = resize).
class Unk_RevEntity : public ASGameEntity
{
public:
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(const CString& strLabel);
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
    virtual void vfunc_25();
    Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int nButton, CStringW strLabel);
};

bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released
void FUN_140710590(COutPacket& packet);                         // send the packet
void FUN_14151f200();
void FUN_14151f4e0(CStringW strTag, MS2Ptr<CMsgBoxData> spData);
CStringW FUN_14028de60(int nId);
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_14052bd00(int nId, const CStringW& strArg);
CStringW FUN_14086d060(int nId, const __int64& n);
CStringW FUN_140c160b0(CStringW strFmt, const __int64& n);
CStringW FUN_1405c2690(CStringW strFmt, const CStringW& strArg);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_1412e7c20(int nStrId, const CStringW& a0, const int& a1);
CStringW FUN_140938ae0(CStringW strKey, const int& a1);
CStringW FUN_140cd7d20();                                       // the dungeon name
CStringW FUN_1401d0160(const wchar_t* psz, const CStringW& str);   // ATL::operator+(const wchar_t*, const CStringW&)
void FUN_141275260(int nId, int a, int b);                      // system message by string id
void FUN_1412751f0(const CStringW& str, int a, int b);          // system message
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);    // case-insensitive equal
bool FUN_140374410(int nFieldId);
__int64 FUN_140632990(__int64 nValue, float fRate);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int nType);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, IMessageListener* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
CUIService* FUN_1403ed2b0();

typedef Delegate<bool(int, const CMsgBoxData&)> RevAnswerDelegate;

// ---- UIRevivalDialog ------------------------------------------------------------------------------------------------

// @0x141aba6a0
UIRevivalDialog::UIRevivalDialog() : m_180(0)
{
    m_1b4 = 0;
    m_7c = 1;
    m_2c = 0x1d;
    m_e0 = 3;
    m_190 = -1;
    m_198 = 0;
    m_1a0 = 0;
    m_1a4 = 0;
    m_1b0 = 0;
    FUN_141925e70(0, 1);
}

// @0x141aba7b0
UIRevivalDialog::~UIRevivalDialog()
{
}

// @0x141aba800
CString UIRevivalDialog::vfunc_1()
{
    return "RevivalDialog";
}

// @0x141aba850
void UIRevivalDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_178 = -1;
    FUN_141abb420();
    FUN_141abae20();
    FUN_140d86260()->vfunc_43(0xe, 0, 1000);
}

// @0x141aba8c0
void UIRevivalDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_180 = 0;
    m_190 = -1;
    m_198 = 0;
}

// @0x141aba920
int UIRevivalDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (nResult == 0)
        {
            if (FUN_1403b3c40(strTag, L"leaveInField") != 0)
                FUN_14151f200();
        }
    }
    else
    {
        if (pMsg->FUN_1422e4520() == 0x7d2)
        {
            COutPacket packet(0x6c, 0);
            packet.vfunc_o10_1(1);
            FUN_140710590(packet);
        }
    }
    return 0;
}

// @0x141abaa30
bool UIRevivalDialog::SendRevivalMode1(int nResult, const CMsgBoxData& box)
{
    int nCoupon = FUN_141abc9d0();
    if (nResult == 0)
    {
        Unk_RevPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc == 0)
            return false;
        if (pPc->FUN_14166ce30() != 0)
        {
            COutPacket packet(0x1f, 0);
            packet.vfunc_o10_1(1);
            packet.vfunc_o10_1(nCoupon);
            FUN_140710590(packet);
        }
        else
        {
            FUN_141275260(0x284, 1, 1);
        }
    }
    m_180 = 0;
    m_190 = -1;
    return true;
}

// @0x141abab30
void UIRevivalDialog::vfunc_43()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        static_cast<Unk_RevEntity*>(spEntity.operator->())->vfunc_25();
}

// @0x141ababd0
int UIRevivalDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    return 0;
}

// @0x141abac00
int UIRevivalDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onRevival", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141abad30(data.FUN_1422b8a10());
        return 1;
    }
    return 0;
}

// @0x141abace0
void UIRevivalDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_1a8.FUN_140268870(1000) != 0)
        FUN_141abcc50();
}

// @0x141abad30
void UIRevivalDialog::FUN_141abad30(int nButton)
{
    if (m_178 > 0)
        return;
    switch (nButton)
    {
    case 1:
        FUN_141abb600();
        break;
    case 2:
        if (m_1b4 == 2)
            FUN_141abc080();
        else if (m_1b4 == 1)
            FUN_141abbb20();
        break;
    }
}

// @0x141abadb0
bool UIRevivalDialog::SendRevivalMode0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        COutPacket packet(0x1f, 0);
        packet.vfunc_o10_1(0);
        FUN_140710590(packet);
        FUN_14151f200();
    }
    return true;
}

// @0x141abae20
// MS2-FUNCTIONAL: frame 0x60 larger (extra call-result temporaries); the || bool temp and the string assigns differ
void UIRevivalDialog::FUN_141abae20()
{
    Unk_RevPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    {
        CStringW strMsg;
        Unk_RevFieldRef spField = FUN_1403ed2d0()->FUN_141bd30a0();
        if (pPc->FUN_1416546d0()->FUN_140639340() == 1 || (spField.FUN_1409657a0() != 0 && spField.FUN_140885340()->m_60 == 0))
        {
            strMsg = FUN_14028de60(0x27c);
        }
        else
        {
            if (pPc->FUN_141661970() == 0)
            {
                if (m_1b4 == 2)
                    strMsg = FUN_14028b8e0(L"s_msg_die_meso");
                else if (m_1b4 == 1)
                    strMsg = FUN_14028b8e0(L"s_msg_die_merat");
                else
                    strMsg = FUN_14028b8e0(L"s_msg_die_none");
            }
            else if (m_1b4 == 2)
            {
                strMsg = FUN_14028b8e0(L"s_msg_die_repeat_meso");
            }
            else if (m_1b4 == 1)
            {
                strMsg = FUN_14028b8e0(L"s_msg_die_repeat_merat");
            }
            else
            {
                strMsg = FUN_14028b8e0(L"s_msg_die_repeat_none");
            }
        }
        if (spField.FUN_1409657a0() != 0)
        {
            Unk_RevFieldData* pData = spField.FUN_140885340();
            if (pData->m_38 != FUN_1403ed2d0()->FUN_141bd3060())
            {
                Unk_RevFieldData* pTo = spField.FUN_140885340();
                strMsg += FUN_1401d0160(L"\n", FUN_14052bd00(0x27d, FUN_1401a9d70()->FUN_141811980(3, pTo->m_38)));
            }
        }
        if (m_30.get() != 0)
        {
            int nRepeat = pPc->FUN_141661970();
            static_cast<Unk_RevMovie*>(m_30.operator->())->FUN_140e0a8c0("setData", strMsg, nRepeat);
        }
    }
}

// @0x141abb420
void UIRevivalDialog::FUN_141abb420()
{
    Unk_RevPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity == 0)
        return;
    static_cast<Unk_RevEntity*>(spEntity.operator->())->FUN_14129cce0("setButtonLabel", 1, FUN_141abd790());
    FUN_141abcb90();
    if (m_1b4 == 0)
        static_cast<Unk_RevEntity*>(spEntity.operator->())->vfunc_13("btn1");
    else
        static_cast<Unk_RevEntity*>(spEntity.operator->())->vfunc_13("btn2");
    FUN_141abcc50();
}

// @0x141abb600
// MS2-FUNCTIONAL: the exe keeps the dungeon-name temporary unchained (temp/slot order differs); source form unknown
void UIRevivalDialog::FUN_141abb600()
{
    if (m_1b0 != 0)
    {
        Unk_RevFieldRef spField = FUN_1403ed2d0()->FUN_141bd30a0();
        if (spField.FUN_140965240(0) != 0)
            return;
        CStringW strMsg = FUN_1405c2690(CStringW(L"s_room_exit_msg_default_revival_limit_dungeon"), FUN_140cd7d20());
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0, strMsg, static_cast<IMessageListener*>(this), CStringW(L"leaveInField"));
        if (spBox.get() != 0)
        {
            spBox->FUN_141a01700(0x476, 0, 0);
            spBox->FUN_141a01ca0(*FUN_1402056b0(&FUN_1401d3200()->m_cfe0), 1, FUN_14028de60(0x2b8));
            FUN_140d73c60(spBox);
        }
    }
    else
    {
        int nFieldId = FUN_1403ed2d0()->FUN_141bd3060();
        Unk_RevFieldRef spField = FUN_140a55460(nFieldId);
        if (spField.FUN_1408851f0() != 0)
            return;
        int nTo = nFieldId;
        if (spField.FUN_140885340()->m_38 != 0)
            nTo = spField.FUN_140885340()->m_38;
        if (nFieldId == nTo)
        {
            COutPacket packet(0x1f, 0);
            packet.vfunc_o10_1(0);
            FUN_140710590(packet);
        }
        else
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(FUN_14052bd00(0x287, FUN_1401a9d70()->FUN_141811980(3, nTo)), 1);
            spBox->FUN_141a027c0(RevAnswerDelegate(this, &UIRevivalDialog::SendRevivalMode0));
            spBox->FUN_141a01800(2);
            FUN_140d73c60(spBox);
        }
    }
}

// @0x141abbb20
// MS2-FUNCTIONAL: frame 0x10 larger (call-result temporaries); source form unknown
void UIRevivalDialog::FUN_141abbb20()
{
    Unk_RevPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    Unk_RevFieldRef spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField.FUN_140965240(0) != 0)
        return;
    if (FUN_141abdab0(spField) == 0)
        return;
    FUN_141abccb0();
    int bHasCoupon = 0;
    unsigned nCanPay = FUN_141abcb10(m_190);
    int nCoupon = FUN_141abc9d0();
    if (nCoupon != 0)
    {
        Unk_RevItemHandle hItem = g_revInventory.FUN_140a5e040(4);
        bHasCoupon = hItem.FUN_14052cd70() != 0;
    }
    if (bHasCoupon || nCanPay != 0)
    {
        if (spField.FUN_140885340()->m_13c == 0)
        {
            if (pPc->FUN_1416749a0()->FUN_140970020(*FUN_1401d7c10(&FUN_1401d3200()->m_51d8), 0, 0, 1) != 0)
            {
                FUN_141275260(0x281, 1, 1);
                return;
            }
        }
        if (nCoupon == 0)
        {
            CStringW strMsg;
            if (FUN_141abc740() == 0)
                strMsg = FUN_14086d060(0x283, m_190);
            else
                strMsg = FUN_140c160b0(CStringW(L"s_msg_revival_merat_msg_box_cn"), m_190);
            m_180 = FUN_140d73f20(strMsg, 1);
            m_180->FUN_141a01540(L"revival_merat");
            m_180->FUN_141a027c0(RevAnswerDelegate(this, &UIRevivalDialog::SendRevivalMode1));
            FUN_140d73c60(m_180);
        }
        else
        {
            COutPacket packet(0x1f, 0);
            packet.vfunc_o10_1(1);
            packet.vfunc_o10_1(nCoupon);
            FUN_140710590(packet);
        }
    }
    else
    {
        FUN_1403ed2b0()->FUN_141add1f0();
    }
}

// @0x141abc080
// MS2-FUNCTIONAL: frame/temp order differs (call-result temporaries); source form unknown
void UIRevivalDialog::FUN_141abc080()
{
    Unk_RevPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    Unk_RevFieldRef spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField.FUN_140965240(0) != 0)
        return;
    if (FUN_141abdab0(spField) == 0)
        return;
    FUN_141abd290();
    int bHasCoupon = 0;
    int nCoupon = FUN_141abc9d0();
    if (nCoupon != 0)
    {
        Unk_RevItemHandle hItem = g_revInventory.FUN_140a5e040(4);
        if (hItem.FUN_14052cd70() != 0)
            bHasCoupon = 1;
    }
    if (bHasCoupon == 0 && FUN_141abcad0(m_198) == 0)
    {
        short nJob = pPc->vfunc_78();
        __int64 nCost = FUN_1401c0db0()->FUN_140676830(nJob, 0);
        float fStat = pPc->FUN_1416561a0()->FUN_1411e1110(0x42);
        float fRate = fStat <= *FUN_140298f40(&FUN_1401d3200()->m_8cc0) ? pPc->FUN_1416561a0()->FUN_1411e1110(0x42) : *FUN_140298f40(&FUN_1401d3200()->m_8cc0);
        nCost = FUN_140632990(nCost, 1.0f - fRate);
        if (nCost < 0)
            nCost = 0;
        if (FUN_141abc930() == 0 || FUN_141abcb10(nCost) == 0)
        {
            FUN_141275260(0x34, 1, 1);
        }
        else
        {
            CStringW strMsg;
            if (FUN_141abc740() == 0)
                strMsg = FUN_140c160b0(CStringW(L"s_msg_revival_meso_cannot_merat_msg_box"), nCost);
            else
                strMsg = FUN_140c160b0(CStringW(L"s_msg_revival_meso_cannot_merat_msg_box_cn"), nCost);
            m_180 = FUN_140d73f20(strMsg, 1);
            m_180->FUN_141a01540(L"revival_merat");
            m_180->FUN_141a027c0(RevAnswerDelegate(this, &UIRevivalDialog::SendRevivalMode1));
            FUN_140d73c60(m_180);
        }
    }
    else
    {
        if (spField.FUN_140885340()->m_13c == 0)
        {
            if (pPc->FUN_1416749a0()->FUN_140970020(*FUN_1401d7c10(&FUN_1401d3200()->m_51d8), 0, 0, 1) != 0)
            {
                FUN_141275260(0x281, 1, 1);
                return;
            }
        }
        COutPacket packet(0x1f, 0);
        packet.vfunc_o10_1(2);
        packet.vfunc_o10_1(nCoupon);
        FUN_140710590(packet);
    }
}

// @0x141abc740
bool UIRevivalDialog::FUN_141abc740()
{
    return FUN_140166410()->FUN_14036d6d0();
}

// @0x141abc770
int UIRevivalDialog::FUN_141abc770()
{
    Unk_RevFieldRef spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField.FUN_1408851f0() != 0)
        return 0;
    return spField.FUN_140885340()->FUN_1403754f0();
}

// @0x141abc7f0
// MS2-FUNCTIONAL: the level argument is copied through ecx into edx and the frame is 0x10 larger; source form unknown
int UIRevivalDialog::FUN_141abc7f0()
{
    Unk_RevPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    int nResult = 0;
    int nLevel = pPc->FUN_141658f30();
    if (FUN_1401c0d90()->FUN_140477d10(nLevel) == 1)
    {
        nResult = 1;
    }
    else
    {
        if (pPc->FUN_141528160() > 0)
            nResult = 1;
    }
    if (nResult == 0)
        return nResult;
    if (FUN_140166410()->FUN_14036d570(0x5d) == 0)
        return nResult;
    int nRoom = DAT_143ab2884;
    if (nRoom == 0)
        return nResult;
    Unk_RevDgRef spRoom = FUN_14031c2a0()->FUN_1403206b0(nRoom);
    if (spRoom.FUN_140334010(0) != 0)
        return nResult;
    if (spRoom.FUN_1403347d0()->m_109 != 0)
        nResult = 0;
    return nResult;
}

// @0x141abc930
bool UIRevivalDialog::FUN_141abc930()
{
    if (FUN_1401d3200()->m_a278 != 0)
        return false;
    if (DAT_143ab2884 != 0)
    {
        Unk_RevDgRef spRoom = FUN_14031c2a0()->FUN_1403206b0(DAT_143ab2884);
        if (spRoom.FUN_14031c160() != 0 && spRoom.FUN_1403347d0()->m_10a != 0)
            return false;
    }
    return true;
}

// @0x141abc9d0
int UIRevivalDialog::FUN_141abc9d0()
{
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return 0;
    MS2Ptr<Unk_RevCheck> spCoupon = FUN_140e52670("m_coupon");
    if (spCoupon == 0)
        return 0;
    if (spCoupon->FUN_1422c2030() == 0)
        return 0;
    return spCoupon->FUN_1422ce0e0();
}

// @0x141abcad0
bool UIRevivalDialog::FUN_141abcad0(__int64 nCost)
{
    return DAT_143ab2898 >= nCost;
}

// @0x141abcb10
bool UIRevivalDialog::FUN_141abcb10(__int64 nCost)
{
    if (FUN_141abc740() != 0)
    {
        if (FUN_140d86260()->vfunc_41(nCost) != 0)
            return true;
    }
    return FUN_140d86260()->vfunc_40(nCost);
}

// @0x141abcb90
void UIRevivalDialog::FUN_141abcb90()
{
    if (FUN_1403ed2d0()->FUN_141bdb660(8) != 0)
    {
        m_1b4 = 0;
    }
    else
    {
        if (FUN_140374410(FUN_1403ed2d0()->FUN_141bd3060()) != 0)
        {
            m_1b4 = 2;
        }
        else
        {
            if (FUN_141abc7f0() != 0)
            {
                m_1b4 = 2;
            }
            else
            {
                if (FUN_141abc930() != 0)
                    m_1b4 = 1;
                else
                    m_1b4 = 0;
            }
        }
    }
}

// @0x141abcc50
void UIRevivalDialog::FUN_141abcc50()
{
    switch (m_1b4)
    {
    case 1:
        FUN_141abccb0();
        break;
    case 2:
        FUN_141abd290();
        break;
    }
    FUN_141abd640();
}

// @0x141abccb0
// MS2-FUNCTIONAL: the exe spills the vftable pointer of the player before the slot 78 call; source form unknown
void UIRevivalDialog::FUN_141abccb0()
{
    Unk_RevPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    int nFlag = pPc->FUN_1416749a0()->FUN_140970d90(*FUN_1401d7c10(&FUN_1401d3200()->m_51d8), 0);
    __int64 nBase = FUN_1401c0db0()->FUN_140676830(pPc->vfunc_78(), nFlag);
    float fStat = pPc->FUN_1416561a0()->FUN_1411e1110(0x42);
    float fRate = fStat <= *FUN_140298f40(&FUN_1401d3200()->m_8cc0) ? pPc->FUN_1416561a0()->FUN_1411e1110(0x42) : *FUN_140298f40(&FUN_1401d3200()->m_8cc0);
    __int64 nCost = FUN_140632990(nBase, 1.0f - fRate);
    if (nCost < 0)
        nCost = 0;
    if (m_190 == nCost)
        return;
    FUN_141abae20();
    CStringW strLabel;
    if (FUN_141abc740() == 0)
        strLabel = FUN_14052bd00(0x280, FUN_1409404f0(nCost));
    else
        strLabel = FUN_1405c2690(CStringW(L"s_msg_revival_merat_btn_cn"), FUN_1409404f0(nCost));
    static_cast<Unk_RevMovie*>(m_30.operator->())->FUN_14129cce0("setButtonLabel", 2, strLabel);
    m_190 = nCost;
    if (m_180.get() != 0)
    {
        CStringW strMsg;
        if (FUN_141abc740() == 0)
            strMsg = FUN_14086d060(0x283, m_190);
        else
            strMsg = FUN_140c160b0(CStringW(L"s_msg_revival_merat_msg_box_cn"), m_190);
        m_180->SetMsg(strMsg);
        FUN_14151f4e0(m_180->FUN_141a02b90(), m_180);
    }
}

// @0x141abd290
// MS2-FUNCTIONAL: the exe spills the vftable pointer of the player before the slot 78 call; source form unknown
void UIRevivalDialog::FUN_141abd290()
{
    Unk_RevPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    int nA = pPc->FUN_141528160();
    int nB = FUN_1401c0d90()->FUN_140477d10(pPc->FUN_141658f30());
    __int64 nBase = FUN_1401c0db0()->FUN_1406771e0(pPc->vfunc_78(), nA, nB);
    float fStat = pPc->FUN_1416561a0()->FUN_1411e1110(0xa4);
    float fRate = fStat <= FUN_1401d3200()->m_90f8 ? pPc->FUN_1416561a0()->FUN_1411e1110(0xa4) : FUN_1401d3200()->m_90f8;
    __int64 nCost = FUN_140632990(nBase, 1.0f - fRate);
    if (nCost < 0)
        nCost = 0;
    if (FUN_140374410(FUN_1403ed2d0()->FUN_141bd3060()) != 0)
        nCost = 0;
    FUN_141abae20();
    CStringW strLabel;
    if (nB == 0)
    {
        int nKind = pPc->FUN_141528160();
        strLabel = FUN_1412e7c20(0x285, FUN_1409404f0(nCost), nKind);
    }
    else
    {
        strLabel = FUN_14052bd00(0x286, FUN_1409404f0(nCost));
    }
    static_cast<Unk_RevMovie*>(m_30.operator->())->FUN_14129cce0("setButtonLabel", 2, strLabel);
    m_198 = nCost;
    m_1a0 = nA;
    m_1a4 = nB;
}

// @0x141abd640
void UIRevivalDialog::FUN_141abd640()
{
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    MS2Ptr<Unk_RevCheck> spCoupon = FUN_140e52670("m_coupon");
    if (spCoupon == 0)
        return;
    Unk_RevItemHandle hItem = g_revInventory.FUN_140a5e040(4);
    if (m_1b4 != 0 && hItem.FUN_14052cd70() != 0)
    {
        if (spCoupon->FUN_1422c2030() == 0)
        {
            spCoupon->FUN_1422ce090(1);
            spCoupon->FUN_1422c1fe0(1);
        }
    }
    else
    {
        spCoupon->FUN_1422ce090(0);
        spCoupon->FUN_1422c1fe0(0);
    }
}

// @0x141abd790
// MS2-FUNCTIONAL: extra named local and a different return-copy shape (frame/EH states differ); source form unknown
CStringW UIRevivalDialog::FUN_141abd790()
{
    m_1b0 = 0;
    CStringW strLabel = FUN_14028de60(0x27e);
    Unk_RevPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return strLabel;
    int nRoom = DAT_143ab2884;
    if (nRoom == 0)
        return strLabel;
    Unk_RevDgRef spRoom = FUN_14031c2a0()->FUN_1403206b0(nRoom);
    if (spRoom.FUN_140334010(0) == 0)
    {
        int nExit = spRoom.FUN_1403347d0()->m_140;
        if (nExit == 0)
            return strLabel;
        int nLeft = nExit - DAT_143ab2950;
        if (nLeft == 0)
        {
            strLabel = FUN_14028b8e0(L"s_room_exit_dungeon");
            m_1b0 = 1;
        }
        else
        {
            strLabel = FUN_140938ae0(CStringW(L"s_msg_revival_count_btn"), nLeft);
        }
        return strLabel;
    }
    return strLabel;
}

// @0x141abdab0
int UIRevivalDialog::FUN_141abdab0(Unk_RevFieldRef spField)
{
    if (spField.FUN_140965240(0) != 0)
        return 0;
    if (spField.FUN_140885340()->m_130 != 0)
    {
        FUN_141275260(0x282, 1, 1);
        return 0;
    }
    Unk_RevPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    if (pPc->FUN_1416749a0()->FUN_140970ad0() != 0)
    {
        FUN_1412751f0(FUN_14028b8e0(L"s_msg_revival_merat_cannot_here_debuff"), 1, 1);
        return 0;
    }
    return 1;
}

// @0x141abde80
Unk_RevFieldRef::Unk_RevFieldRef(const Unk_RevFieldRef& o)
{
    m_8 = o.m_8;
    FUN_140a57040();
}

// @0x141abe0b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
