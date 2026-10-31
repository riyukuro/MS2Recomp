// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIVIPDialog: the VIP membership window. See uivipdialog.h.
// MS2-UNIT: ?\uivipdialog.cpp
// MS2-GUESS-LOOKALIKES (the MS2Ptr / CAtlArray accessor glue is byte-identical to other instances)
// MS2-RANGE: 0x140fb7dc0-0x140fb9ac0 .text$mn
// MS2-RANGE: 0x1400e2540-0x1400e2570 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uivipdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uiservice.h"
#include "uivipdialog.h"
#include "uimessageboxdata.h"
#include "mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/vipgoods.h"
#include "ms2/commonfiles/additionalactionadditional.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"

MS2_EMIT_CRT_MEMMOVE_S();

static CString s_sndCashBuy = "cash_Buy";

// ---- unit-local views of exe objects ----

// The list control of the movie (the AS list with clear / append).
class Unk_VdList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                       // clear
    void FUN_1422dd230(const ASObj& row);                       // append a row
    void FUN_1422cf4f0(int n);
};
template <> MS2Ptr<Unk_VdList> UISwfEntity::GetChild<Unk_VdList>(const CString&);    // 0x140ba4b70

// The message box with its sound slot (the record is a CMsgBoxData).
class Unk_VdMsgBox : public CMsgBoxData { public: void FUN_141a01c30(const CString&); };


// The client event sink (FUN_140d86260); only slot 43 is used here.
class Unk_VdPlatform
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42();
    virtual void vfunc_43(int nEvent, int a2, int nDelay);
};
void* FUN_140d86260();   // C3: was FUN_140d86260

class Unk_VdUiMgr { public: void FUN_141adc750(int uiId); };
class Unk_VdGameMenu { public: void FUN_141938ae0(int nType, int n); };
class UIGameMenuDialog* FUN_140938b90(int);   // C3: was FUN_140938b90

CVIPTable* FUN_140fb9980();                                     // CVIPTable::GetInstance (defined below)
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
__int64 GetServerTime();                                        // the server time
void FUN_140710590(COutPacket& packet);                         // send the packet

CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FormatTimeSpan(ATL::CTimeSpan span, bool bA, bool bB, bool bDays, bool bHours);  // format a time span
bool FUN_140e452e0(const ATL::CTimeSpan& a, ATL::CTimeSpan b);  // a < b
bool FUN_140841300(const CStringW& str, const char* sz);        // the string equals sz
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, IMessageListener* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                  // show
void FUN_141276180(const CString& strSound, const CString& strArg);   // play a sound

MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_141275a10(CItem* pItem);                                // the item's lock kind
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);    // pRetVal = v

// @0x140fb7dc0
UIVIPDialog::UIVIPDialog()
    : m_claimedIds(10)
{
    m_nVipEnd = 0;
    m_nVip = 0;
    FUN_141924170(1);
}

// @0x140fb7e70
UIVIPDialog::~UIVIPDialog()
{
}

// @0x140fb7ee0
CString UIVIPDialog::GetTypeName()
{
    return CString("VIPDialog");
}

// @0x140fb7f30
int UIVIPDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140fb7f60
void UIVIPDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140fb7f80
void UIVIPDialog::vfunc_72()
{
    if (vfunc_55() == 1)
        return;
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    if (m_nVipEnd != ((class PC*)(class PCBase*)(pPlayer))->FUN_141662e90() || m_nVip != ((class PC*)(class PCBase*)(pPlayer))->FUN_141662de0()) {
        FUN_140fb9150();
        FUN_140fb8d10();
        m_nVipEnd = ((class PC*)(class PCBase*)(pPlayer))->FUN_141662e90();
        m_nVip = ((class PC*)(class PCBase*)(pPlayer))->FUN_141662de0();
    }
}

// @0x140fb8040
void UIVIPDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    FUN_140fb8d10();
    SendPremiumClubMode1();
    m_nVipEnd = ((class PC*)(class PCBase*)(pPlayer))->FUN_141662e90();
    m_nVip = ((class PC*)(class PCBase*)(pPlayer))->FUN_141662de0();
    ((class Unk_VdPlatform*)FUN_140d86260())->vfunc_43(0xe, 0, 1000);
}

// @0x140fb80f0
int UIVIPDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "OnClickGetItem") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nBenefitId = data.FUN_1422b8b10();
            COutPacket packet(static_cast<int>(SendOp::PremiumClub), 0);
            packet.Encode1(2);
            packet.Encode4(nBenefitId);
            FUN_140710590(packet);
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onClickBuyGoods") == 0) {
        ((class Unk_VdUiMgr*)TSingleton<CUIService>::GetInstance())->FUN_141adc750(0x4f1d);
        return 1;
    }
    return 0;
}

// @0x140fb8240
void UIVIPDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    CStringW strType = pArgs->FUN_1422b8f40();
    if (FUN_140841300(strType, "benefitItem")) {
        unsigned nBenefitId = pArgs->FUN_1422b8b10();
        CVIPBenefitItemPtr spBenefit = FUN_140fb9980()->GetBenefitItem(nBenefitId);
        if (spBenefit == 0)
            return;
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b130(spBenefit->m_nItemId, spBenefit->m_nItemRank, 0) != 0) {
            spItem->FUN_140526c70(spBenefit->m_nItemCount);
            MS2Ptr<CItem> spWorn = static_cast<MyPC*>(pPlayer)->FUN_14152e2f0(spItem);
            ASTooltip tip(((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0()), 4, 2);
            if (((class ASTooltip*)(class ASTooltip*)(&tip))->FUN_1409e13a0(spWorn.get(), spItem.get()) != 0) {
                if (spBenefit->m_nItemPeriod > 0)
                    ((class ASTooltip*)(class ASTooltip*)(&tip))->FUN_1409d6a40(((class CItem*)(class CItem*)(spItem))->FUN_1405276c0(), spBenefit->m_nItemPeriod);
                FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
            }
        }
    } else if (FUN_140841300(strType, "effectIcon")) {
        MS2Ptr<AdditionalLevelData> effect = FUN_140fb9980()->GetFirstEffect();
        if (effect == 0)
            return;
        ASTooltip tip(*pRetVal, 2);
        tip.FUN_1409e2750(effect.get(), 3, 0);
    }
}

// @0x140fb8620
void UIVIPDialog::SendPremiumClubMode1()
{
    COutPacket packet(static_cast<int>(SendOp::PremiumClub), 0);
    packet.Encode1(1);
    FUN_140710590(packet);
}

// @0x140fb8680
int UIVIPDialog::FUN_140fb8680()
{
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    if (((class PC*)(class PCBase*)(pPlayer))->FUN_141662de0() == 0)
        return 0;
    int nCount = 0;
    ATL::CAtlArray<CVIPBenefitItemPtr> items;
    FUN_140fb9980()->GetBenefitItems(items);
    for (unsigned i = 0; i < items.GetCount(); i++) {
        CVIPBenefitItemPtr spBenefit = items[i];
        if (spBenefit == 0)
            continue;
        if (FUN_140fb9720(spBenefit->m_nId) == 0)
            continue;
        nCount++;
    }
    return nCount;
}

// @0x140fb87d0
void UIVIPDialog::FUN_140fb87d0(CInPacket& packet, int nMode)
{
    if (nMode == 1) {
        m_claimedIds.RemoveAll();
        unsigned nCount = packet.ReadInt32();
        for (unsigned i = 0; i < nCount; i++)
            m_claimedIds.AddTail(packet.ReadInt32());
        FUN_140fb9150();
        Unk_VdGameMenu* pMenu = ((class Unk_VdGameMenu*)FUN_140938b90(0x4e28));
        if (pMenu != 0)
            pMenu->FUN_141938ae0(0x4f1b, 0);
    } else if (nMode == 2) {
        unsigned nBenefitId = packet.ReadInt32();
        m_claimedIds.AddTail(nBenefitId);
        FUN_140fb9150();
        CVIPBenefitItemPtr spBenefit = FUN_140fb9980()->GetBenefitItem(nBenefitId);
        if (spBenefit == 0)
            return;
        if (MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, GetStringCommonByKey(L"s_vip_dialog_get_benefit_item"), 0, L"")) {
            MS2Ptr<CItem> spItem(new CItem());
            if (!spItem->FUN_140523c40(spBenefit->m_nItemId, spBenefit->m_nItemRank, 0))
                return;
            spItem->FUN_140526c70(spBenefit->m_nItemCount);
            spBox->FUN_141a01ee0(MS2Ptr<CItem>(spItem), spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
            spBox->FUN_141a01700(0x475, 0, 0);
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
            FUN_141276180(s_sndCashBuy, "");
        }
    }
}

// @0x140fb8d10
void UIVIPDialog::FUN_140fb8d10()
{
    if (!m_30)
        return;
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    MS2Ptr<ASTextField> spTime = FUN_140bb4cf0("m_remainTime");
    if (spTime == 0)
        return;
    if (((class PC*)(class PCBase*)(pPlayer))->FUN_141662de0() == 0) {
        spTime->FUN_1422c4cd0(GetStringCommonByKey(L"s_vip_dialog_end_time"));
    } else {
        ATL::CTimeSpan span = CMsTime(((class PC*)(class PCBase*)(pPlayer))->FUN_141662e90()) - CMsTime(GetServerTime());
        if (FUN_140e452e0(span, 0))
            return;
        CStringW strRemain = FormatTimeSpan(span, true, true, false, false);
        if (strRemain.IsEmpty())
            strRemain = GetStringCommonByKey(L"s_vip_dialog_remain_time_hour");
        else
            strRemain = FUN_1405c2690(L"s_vip_dialog_remain_time", strRemain);
        spTime->FUN_1422c4f00(strRemain);
    }
    unsigned nTextWidth = spTime->FUN_1422c5970();
    float fX, fY;
    spTime->FUN_1422c0f60(&fX, &fY);
    fX = fX + (float)((spTime->FUN_1422c1340() - nTextWidth) - 0x1e);
    if (MS2Ptr<ASMovieClip> spIcon = FUN_140ba7930("m_timerIcon"))
        spIcon->FUN_1422c00f0(fX, fY);
}

// @0x140fb9150
void UIVIPDialog::FUN_140fb9150()
{
    if (!m_30)
        return;
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    MS2Ptr<Unk_VdList> spList = GetChild<Unk_VdList>("m_benefitItemList");
    if (spList == 0)
        return;
    spList->Invoke("resetRenderer");
    spList->FUN_1422dd1d0();
    spList->FUN_1422cf4f0(0);
    ATL::CAtlArray<CVIPBenefitItemPtr> items;
    FUN_140fb9980()->GetBenefitItems(items);
    for (unsigned i = 0; i < items.GetCount(); i++) {
        CVIPBenefitItemPtr spBenefit = items[i];
        if (spBenefit == 0)
            continue;
        MS2Ptr<CItemData> spData = FUN_14053f870(spBenefit->m_nItemId);
        if (!spData)
            continue;
        MS2Ptr<CItem> spItem(new CItem());
        if (!spItem->FUN_140523c40(spBenefit->m_nItemId, spBenefit->m_nItemRank, 0))
            continue;
        ASObj row(2);
        row.FUN_1409c0d20("id", spBenefit->m_nId);
        row.FUN_1407cbb20("label", ((class CStringTable*)TSingleton<CStringTable>::GetInstance())->FUN_141811980(1, spBenefit->m_nItemId));
        row.FUN_1409adc90("itemGrade", spBenefit->m_nItemRank);
        row.FUN_1409c0d20("itemCount", spBenefit->m_nItemCount);
        row.FUN_1407cba60("iconPath", spData->FUN_14053fdd0());
        row.FUN_1407cb9c0("itemPcBang", spItem->FUN_140525ca0());
        row.FUN_1407cb9c0("itemVIP", spItem->FUN_140525db0());
        int nLock = FUN_141275a10(spItem.get());
        if (nLock == 2)
            row.FUN_1407cb9c0("disable", 1);
        else if (nLock == 1)
            row.FUN_1407cb9c0("itemLock", 1);
        else if (nLock == 3)
            row.FUN_1407cb9c0("itemConditionLock", 1);
        int bDisable = FUN_140fb9720(spBenefit->m_nId) == 0;
        row.FUN_1407cb9c0("disableButton", bDisable);
        spList->FUN_1422dd230(row);
    }
    spList->vfunc_24(true);
}

// @0x140fb9720
int UIVIPDialog::FUN_140fb9720(unsigned nBenefitId)
{
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    if (((class PC*)(class PCBase*)(pPlayer))->FUN_141662de0() == 0)
        return 0;
    if (m_claimedIds.Find(nBenefitId) != 0)
        return 0;
    return 1;
}

// @0x140fb9980
CVIPTable* FUN_140fb9980()
{
    return TSingleton<CVIPTable>::s_instance;
}

// @0x140fb9990
int UIVIPDialog::vfunc_48()
{
    return 0x4f1b;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caa9e0-0x142caaa00 .text$yd
