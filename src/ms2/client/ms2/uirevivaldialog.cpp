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
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/additionalclilist.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC::FUN_1416561a0
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce090
#include "ms2/commonfiles/luautil.h"  // C3: CLua::CalcRevivalMerat/CalcRevivalMeso
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Check (0x140268870)
#include "ms2/placeholder/formatstringid.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/jobsystemcli.h"
#include "ms2/placeholder/iclientplatform.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The player's equip / stat holder.
#include "ms2/client/ms2/equipment.h"   // CEquipment (was a local member view)
// The player's buff / ability list.
class Unk_PCBaseBuffs : public AdditionalCliList
{
public:
};

// The local player (slot 78 of the vftable returns the job id).
class MyPC : public PC   // C3: the real PC (fittingdollpc.h) for the job id, level and busy calls
{
public:
    int FUN_141528160();
};

// The client constants (singleton 0x1401d3200): the revival related values.
class Unk_RevUIntVal { public: };
class Unk_RevFloatVal { public: };
class Unk_RevIntVal { public: };
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

class Unk_BmPriceMgr;
class Unk_140166410;
Unk_BmPriceMgr* FUN_1401c0db0();
void* FUN_1401c0d90();
Unk_140166410* FUN_140166410();
template <typename A, typename B> CStringW FUN_14028dee0(int nId, const A& a, const B& b);

// The string table singleton: FUN_141811980(table, id).

// The platform host (singleton 0x140d86260): slots 40/41 test whether a cost can be paid, 43 raises a notice.


extern Unk_Inventory g_143ab2a90;                       // the player's inventory
extern int DAT_143ab2884;                               // the dungeon room id
extern int DAT_143ab2950;
extern __int64 DAT_143ab2898;                           // the free revival limit

// The movie root: the data calls.
class Unk_RsScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int a1, CStringW a2);
};
class UIItemPetBoxDialog : public UIDialog
{
public:
    MS2Ptr<ASCheckBox> FindCheckBox(const CString& strName);
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
};

void FUN_140710590(COutPacket& packet);                         // send the packet
void FUN_14151f200();
void FUN_14151f4e0(CStringW strTag, MS2Ptr<CMsgBoxData> spData);
CStringW GetStringCommon(int nId);
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_140cd7d20();                                       // the dungeon name
void FUN_141275260(int nId, int a, int b);                      // system message by string id
void FUN_1412751f0(const CStringW& str, int a, int b);          // system message
__int64 FUN_140632990(__int64 nValue, float fRate);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int nType);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

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
CString UIRevivalDialog::GetTypeName()
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
    GetClientPlatform()->vfunc_43(0xe, 0, 1000);
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
        int nResult = pMsg->PopInt();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (nResult == 0)
        {
            if (operator==(strTag, L"leaveInField") != 0)
                FUN_14151f200();
        }
    }
    else
    {
        if (pMsg->FUN_1422e4520() == 0x7d2)
        {
            COutPacket packet(static_cast<int>(SendOp::RequestMoveField), 0);
            packet.WriteUInt8(1);
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
        MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPc == 0)
            return false;
        if (pPc->IsDead() != 0)
        {
            COutPacket packet(static_cast<int>(SendOp::Revival), 0);
            packet.WriteUInt8(1);
            packet.WriteUInt8(nCoupon);
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
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
            FUN_141abad30(data.PopInt());
        return 1;
    }
    return 0;
}

// @0x141abace0
void UIRevivalDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_1a8.Check(1000) != 0)
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
        COutPacket packet(static_cast<int>(SendOp::Revival), 0);
        packet.WriteUInt8(0);
        FUN_140710590(packet);
        FUN_14151f200();
    }
    return true;
}

// @0x141abae20
void UIRevivalDialog::FUN_141abae20()
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    {
        CStringW strMsg;
        MS2Ptr<CFieldDataCli> spField = WorldService::GetInstance()->FUN_141bd30a0();
        if (pPc->FUN_1416546d0()->GetJobGroupID() == 1 || ((reinterpret_cast<long long>(spField.get()) ? true : false) && spField->m_nDeathPenalty == 0))
        {
            strMsg = GetStringCommon(0x27c);
        }
        else
        {
            if (pPc->IsRevivalBlocked() != 0)
            {
                if (m_1b4 == 2)
                    strMsg = GetStringCommonByKey(L"s_msg_die_repeat_meso");
                else if (m_1b4 == 1)
                    strMsg = GetStringCommonByKey(L"s_msg_die_repeat_merat");
                else
                    strMsg = GetStringCommonByKey(L"s_msg_die_repeat_none");
            }
            else if (m_1b4 == 2)
            {
                strMsg = GetStringCommonByKey(L"s_msg_die_meso");
            }
            else if (m_1b4 == 1)
            {
                strMsg = GetStringCommonByKey(L"s_msg_die_merat");
            }
            else
            {
                strMsg = GetStringCommonByKey(L"s_msg_die_none");
            }
        }
        if (reinterpret_cast<long long>(spField.get()) ? true : false)
        {
            CFieldDataCli* pData = spField.operator->();
            if (pData->m_nRevivalReturnId != WorldService::GetInstance()->FUN_141bd3060())
            {
                CFieldDataCli* pTo = spField.operator->();
                CStringW strTo = FormatStringId<CStringW>(0x27d, TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, pTo->m_nRevivalReturnId));
                strMsg += L"\n" + strTo;
            }
        }
        if (m_30.get() != 0)
        {
            static_cast<AScript*>(m_30.operator->())->Invoke("setData", strMsg, pPc->IsRevivalBlocked());
        }
    }
}

// @0x141abb420
void UIRevivalDialog::FUN_141abb420()
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity == 0)
        return;
    reinterpret_cast<Unk_RsScript*>(spEntity.operator->())->FUN_14129cce0("setButtonLabel", 1, FUN_141abd790());
    FUN_141abcb90();
    if (m_1b4 == 0)
        static_cast<Unk_RevEntity*>(spEntity.operator->())->vfunc_13("btn1");
    else
        static_cast<Unk_RevEntity*>(spEntity.operator->())->vfunc_13("btn2");
    FUN_141abcc50();
}

// @0x141abb600
void UIRevivalDialog::FUN_141abb600()
{
    if (m_1b0 != 0)
    {
        MS2Ptr<CFieldDataCli> spField = WorldService::GetInstance()->FUN_141bd30a0();
        if (spField == 0)
            return;
        CStringW strMsg = FUN_14028dfa0<CStringW>(CStringW(L"s_room_exit_msg_default_revival_limit_dungeon"), FUN_140cd7d20());
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0, strMsg, static_cast<IMessageListener*>(this), CStringW(L"leaveInField"));
        if (spBox.get() != 0)
        {
            spBox->SetButtonLabelIds(0x476, 0, 0);
            spBox->SetTimer(*reinterpret_cast<Common::Constants::Value<int>*>(&reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_cfe0)->Get(), 1, GetStringCommon(0x2b8));
            FUN_140d73c60(spBox);
        }
    }
    else
    {
        int nFieldId = WorldService::GetInstance()->FUN_141bd3060();
        MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(nFieldId);
        if (spField.IsNull() != 0)
            return;
        int nTo = spField->m_nRevivalReturnId != 0 ? spField->m_nRevivalReturnId : nFieldId;
        if (nFieldId != nTo)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(FormatStringId<CStringW>(0x287, TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, nTo)), 1);
            spBox->SetCallback(RevAnswerDelegate(this, &UIRevivalDialog::SendRevivalMode0));
            spBox->FUN_141a01800(2);
            FUN_140d73c60(spBox);
        }
        else
        {
            COutPacket packet(static_cast<int>(SendOp::Revival), 0);
            packet.WriteUInt8(0);
            FUN_140710590(packet);
        }
    }
}

// @0x141abbb20
void UIRevivalDialog::FUN_141abbb20()
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    MS2Ptr<CFieldDataCli> spField = WorldService::GetInstance()->FUN_141bd30a0();
    if (spField == 0)
        return;
    if (FUN_141abdab0(spField) == 0)
        return;
    FUN_141abccb0();
    int bHasCoupon = 0;
    int nCanPay = FUN_141abcb10(m_190);
    int nCoupon = FUN_141abc9d0();
    if (nCoupon != 0)
    {
        MS2Ptr<CItem> hItem = g_143ab2a90.FUN_140a5e040(4);
        if (hItem.get() != 0)
            bHasCoupon = 1;
    }
    if (bHasCoupon == 0 && nCanPay == 0)
    {
        TSingleton<CUIService>::GetInstance()->FUN_141add1f0();
        return;
    }
    if (spField->m_nInfinityMeratRevival == 0)
    {
        if (pPc->FUN_1416749a0()->FUN_140970020(*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_51d8)->Get(), 0, 0, 1) != 0)
        {
            FUN_141275260(0x281, 1, 1);
            return;
        }
    }
    if (nCoupon != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Revival), 0);
        packet.WriteUInt8(1);
        packet.WriteUInt8(nCoupon);
        FUN_140710590(packet);
    }
    else
    {
        CStringW strMsg;
        if (FUN_141abc740() != 0)
            strMsg = FUN_14028dfa0<__int64>(L"s_msg_revival_merat_msg_box_cn", m_190);
        else
            strMsg = FormatStringId<__int64>(0x283, m_190);
        m_180 = FUN_140d73f20(strMsg, 1);
        m_180->FUN_141a01540(L"revival_merat");
        m_180->SetCallback(RevAnswerDelegate(this, &UIRevivalDialog::SendRevivalMode1));
        FUN_140d73c60(m_180);
    }
}

// @0x141abc080
void UIRevivalDialog::FUN_141abc080()
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    MS2Ptr<CFieldDataCli> spField = WorldService::GetInstance()->FUN_141bd30a0();
    if (spField == 0)
        return;
    if (FUN_141abdab0(spField) == 0)
        return;
    FUN_141abd290();
    int bHasCoupon = 0;
    int nCoupon = FUN_141abc9d0();
    if (nCoupon != 0)
    {
        MS2Ptr<CItem> hItem = g_143ab2a90.FUN_140a5e040(4);
        if (hItem.get() != 0)
            bHasCoupon = 1;
    }
    if (bHasCoupon == 0 && FUN_141abcad0(m_198) == 0)
    {
        __int64 nCost = ((CLua*)FUN_1401c0db0())->CalcRevivalMerat(pPc->vfunc_78(), 0);
        float fRate = *reinterpret_cast<Common::Constants::Value<float>*>(&reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_8cc0)->Get() < reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x42)
            ? *reinterpret_cast<Common::Constants::Value<float>*>(&reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_8cc0)->Get() : reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x42);
        nCost = FUN_140632990(nCost, 1.0f - fRate);
        nCost = nCost < 0 ? 0 : nCost;
        if (FUN_141abc930() == 0 || FUN_141abcb10(nCost) == 0)
        {
            FUN_141275260(0x34, 1, 1);
            return;
        }
        CStringW strMsg;
        if (FUN_141abc740() != 0)
            strMsg = FUN_14028dfa0<__int64>(L"s_msg_revival_meso_cannot_merat_msg_box_cn", nCost);
        else
            strMsg = FUN_14028dfa0<__int64>(L"s_msg_revival_meso_cannot_merat_msg_box", nCost);
        m_180 = FUN_140d73f20(strMsg, 1);
        m_180->FUN_141a01540(L"revival_merat");
        m_180->SetCallback(RevAnswerDelegate(this, &UIRevivalDialog::SendRevivalMode1));
        FUN_140d73c60(m_180);
        return;
    }
    if (spField->m_nInfinityMeratRevival == 0)
    {
        if (pPc->FUN_1416749a0()->FUN_140970020(*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_51d8)->Get(), 0, 0, 1) != 0)
        {
            FUN_141275260(0x281, 1, 1);
            return;
        }
    }
    COutPacket packet(static_cast<int>(SendOp::Revival), 0);
    packet.WriteUInt8(2);
    packet.WriteUInt8(nCoupon);
    FUN_140710590(packet);
}

// @0x141abc740
bool UIRevivalDialog::FUN_141abc740()
{
    return reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d6d0();
}

// @0x141abc770
int UIRevivalDialog::FUN_141abc770()
{
    MS2Ptr<CFieldDataCli> spField = WorldService::GetInstance()->FUN_141bd30a0();
    if (spField.IsNull() != 0)
        return 0;
    return spField->FUN_1403754f0();
}

// @0x141abc7f0
int UIRevivalDialog::FUN_141abc7f0()
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return 0;
    int nResult = 0;
    if (((CGameRule*)FUN_1401c0d90())->FUN_140477d10(pPc->FUN_141658f30()) == 1)
        nResult = 1;
    else if ((unsigned int)pPc->FUN_141528160() > 0)
        nResult = 1;
    if (nResult != 0)
    {
        do
        {
            if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x5d) == 0)
                break;
            int nRoom = DAT_143ab2884;
            if (nRoom == 0)
                break;
            DungeonRoomPtr spRoom = TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(nRoom);
            if (spRoom == 0)
                break;
            if (spRoom->m_limitMesoRevival == 0)
                break;
            nResult = 0;
        } while (0);
    }
    return nResult;
}

// @0x141abc930
bool UIRevivalDialog::FUN_141abc930()
{
    if (reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_a278 != 0)
        return false;
    if (DAT_143ab2884 != 0)
    {
        DungeonRoomPtr spRoom = TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(DAT_143ab2884);
        if (spRoom.get() != 0 && spRoom->m_limitMeratRevival != 0)
            return false;
    }
    return true;
}

// @0x141abc9d0
int UIRevivalDialog::FUN_141abc9d0()
{
    if (m_30 == 0)
        return 0;
    MS2Ptr<ASCheckBox> spCoupon = reinterpret_cast<UIItemPetBoxDialog*>(this)->FindCheckBox("m_coupon");
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
        if (GetClientPlatform()->vfunc_41(nCost) != 0)
            return true;
    }
    return GetClientPlatform()->vfunc_40(nCost);
}

// @0x141abcb90
void UIRevivalDialog::FUN_141abcb90()
{
    if (WorldService::GetInstance()->FUN_141bdb660(8) != 0)
    {
        m_1b4 = 0;
    }
    else
    {
        if (CFieldData::FUN_140374410(WorldService::GetInstance()->FUN_141bd3060()) != 0)
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
void UIRevivalDialog::FUN_141abccb0()
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    __int64 nCost = ((CLua*)FUN_1401c0db0())->CalcRevivalMerat(pPc->vfunc_78(),
        pPc->FUN_1416749a0()->GetOverlapCount(*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_51d8)->Get(), 0));
    float fRate = *reinterpret_cast<Common::Constants::Value<float>*>(&reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_8cc0)->Get() < reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x42)
        ? *reinterpret_cast<Common::Constants::Value<float>*>(&reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_8cc0)->Get() : reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0x42);
    nCost = FUN_140632990(nCost, 1.0f - fRate);
    nCost = nCost < 0 ? 0 : nCost;
    if (m_190 != nCost)
    {
        FUN_141abae20();
        CStringW strLabel;
        if (FUN_141abc740() != 0)
            strLabel = FUN_14028dfa0<CStringW>(L"s_msg_revival_merat_btn_cn", FUN_1409404f0(nCost));
        else
            strLabel = FormatStringId<CStringW>(0x280, FUN_1409404f0(nCost));
        static_cast<Unk_RsScript*>(m_30.operator->())->FUN_14129cce0("setButtonLabel", 2, strLabel);
        m_190 = nCost;
        if (m_180.get() != 0)
        {
            CStringW strMsg;
            if (FUN_141abc740() != 0)
                strMsg = FUN_14028dfa0<__int64>(L"s_msg_revival_merat_msg_box_cn", m_190);
            else
                strMsg = FormatStringId<__int64>(0x283, m_190);
            m_180->SetMsg(strMsg);
            FUN_14151f4e0(m_180->FUN_141a02b90(), m_180);
        }
    }
}

// @0x141abd290
void UIRevivalDialog::FUN_141abd290()
{
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    int nA = pPc->FUN_141528160();
    int nB = ((CGameRule*)FUN_1401c0d90())->FUN_140477d10(pPc->FUN_141658f30());
    __int64 nCost = ((CLua*)FUN_1401c0db0())->CalcRevivalMeso(pPc->vfunc_78(), nA, nB);
    float fRate = reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_90f8 < reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0xa4)
        ? reinterpret_cast<Unk_RevConsts*>(FUN_1401d3200())->m_90f8 : reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->GetAbilityRate((SAType)0xa4);
    nCost = FUN_140632990(nCost, 1.0f - fRate);
    nCost = nCost < 0 ? 0 : nCost;
    if (CFieldData::FUN_140374410(WorldService::GetInstance()->FUN_141bd3060()) != 0)
        nCost = 0;
    FUN_141abae20();
    CStringW strLabel;
    if (nB != 0)
    {
        strLabel = FormatStringId<CStringW>(0x286, FUN_1409404f0(nCost));
    }
    else
    {
        unsigned int nKind = pPc->FUN_141528160();
        strLabel = FUN_14028dee0<CStringW, unsigned int>(0x285, FUN_1409404f0(nCost), nKind);
    }
    static_cast<Unk_RsScript*>(m_30.operator->())->FUN_14129cce0("setButtonLabel", 2, strLabel);
    m_198 = nCost;
    m_1a0 = nA;
    m_1a4 = nB;
}

// @0x141abd640
void UIRevivalDialog::FUN_141abd640()
{
    if (m_30 == 0)
        return;
    MS2Ptr<ASCheckBox> spCoupon = reinterpret_cast<UIItemPetBoxDialog*>(this)->FindCheckBox("m_coupon");
    if (spCoupon == 0)
        return;
    MS2Ptr<CItem> hItem = g_143ab2a90.FUN_140a5e040(4);
    if (m_1b4 != 0 && hItem.get() != 0)
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
CStringW UIRevivalDialog::FUN_141abd790()
{
    m_1b0 = 0;
    CStringW strLabel = GetStringCommon(0x27e);
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return strLabel;
    int nRoom = DAT_143ab2884;
    if (nRoom == 0)
        return strLabel;
    DungeonRoomPtr spRoom = TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(nRoom);
    if (spRoom == 0)
        return strLabel;
    unsigned int nExit = spRoom->m_defaultRevivalLimitCount;
    if (nExit == 0)
        return strLabel;
    unsigned int nLeft = nExit - DAT_143ab2950 < 0 ? 0 : nExit - DAT_143ab2950;
    if (nLeft == 0)
    {
        strLabel = GetStringCommonByKey(L"s_room_exit_dungeon");
        m_1b0 = 1;
    }
    else
    {
        strLabel = FUN_14028dfa0<unsigned int>(CStringW(L"s_msg_revival_count_btn"), nLeft);
    }
    return strLabel;
}

// @0x141abdab0
int UIRevivalDialog::FUN_141abdab0(MS2Ptr<CFieldDataCli> spField)
{
    if (spField == 0)
        return 0;
    if (spField->m_nDoNotRevivalHere != 0)
    {
        FUN_141275260(0x282, 1, 1);
        return 0;
    }
    MyPC* pPc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPc == 0)
        return 0;
    if (pPc->FUN_1416749a0()->IsDisableRevivalHere() != 0)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_msg_revival_merat_cannot_here_debuff"), 1, 1);
        return 0;
    }
    return 1;
}


// @0x141abe0b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
// MS2-PIN: ??0?$MS2Ptr@VCFieldDataCli@@@@QEAA@AEBV0@@Z 0x141abde80
