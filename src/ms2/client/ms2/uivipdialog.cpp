// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIVIPDialog: the VIP membership window. See uivipdialog.h.
// MS2-UNIT: ?\uivipdialog.cpp
// MS2-GUESS-LOOKALIKES (the MS2Ptr / CAtlArray accessor glue is byte-identical to other instances)
// MS2-RANGE: 0x140fb7dc0-0x140fb9ac0 .text$mn
// MS2-RANGE: 0x1400e2540-0x1400e2570 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uivipdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uivipdialog.h"
#include "uimessageboxdata.h"
#include "mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/vipgoods.h"
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

// The VIP effect of the first benefit: a 16-byte skill reference released by 0x1401836a0.
void FUN_1401836a0(Unk_VipEffectRef*);
struct Unk_VdEffectHold
{
    Unk_VipEffectRef m_ref;
    Unk_VdEffectHold(const Unk_VipEffectRef& r) : m_ref(r) {}
    ~Unk_VdEffectHold() { FUN_1401836a0(&m_ref); }
    bool IsNull() const { return m_ref.m_p == 0; }
    void* get() const { return m_ref.m_p; }
};

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
Unk_VdPlatform* FUN_140d86260();

class Unk_VdUiMgr { public: void FUN_141adc750(int uiId); };
Unk_VdUiMgr* FUN_1403ed2b0();
class Unk_VdGameMenu { public: void FUN_141938ae0(int nType, int n); };
Unk_VdGameMenu* FUN_140938b90(int uiId);

CVIPTable* FUN_140fb9980();                                     // CVIPTable::GetInstance (defined below)
void* FUN_1403ed2d0();                                          // the world
PCBase* FUN_141bd0cc0(void* pWorld);                            // the local player
int FUN_141662de0(PCBase* pPC);                                 // the player has VIP
__int64 FUN_141662e90(PCBase* pPC);                             // the VIP end time
__int64 FUN_140869440();                                        // the server time
void FUN_140710590(COutPacket& packet);                         // send the packet

class Unk_VdStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_VdStrings* FUN_1401a9d70();
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_14086aec0(ATL::CTimeSpan span, int nA, int nB, bool bDays, bool bHours);   // format a time span
bool FUN_140e452e0(const ATL::CTimeSpan& a, ATL::CTimeSpan b);  // a < b
bool FUN_140841300(const CStringW& str, const char* sz);        // the string equals sz
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, IMessageListener* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                  // show
void FUN_141276180(const CString& strSound, const CString& strArg);   // play a sound

MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_141275a10(CItem* pItem);                                // the item's lock kind
int FUN_1405276c0(CItem* pItem);                                // the item id
int FUN_1409e13a0(ASTooltip* pTip, CItem* pCompare, CItem* pItem);   // item tooltip (the member in astooltip.h is declared void)
void FUN_1409d6a40(ASTooltip* pTip, int nItemId, __int64 nPeriod);    // the period line of the tooltip
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
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    if (m_nVipEnd != FUN_141662e90(pPlayer) || m_nVip != FUN_141662de0(pPlayer)) {
        FUN_140fb9150();
        FUN_140fb8d10();
        m_nVipEnd = FUN_141662e90(pPlayer);
        m_nVip = FUN_141662de0(pPlayer);
    }
}

// @0x140fb8040
// MS2-FUNCTIONAL: behaviour-equivalent; temp slots / MS2Ptr glue pairing and EH unwind map differ from the exe
void UIVIPDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0) {
        FUN_140fb8d10();
        SendPremiumClubMode1();
        m_nVipEnd = FUN_141662e90(pPlayer);
        m_nVip = FUN_141662de0(pPlayer);
        FUN_140d86260()->vfunc_43(0xe, 0, 1000);
    }
}

// @0x140fb80f0
// MS2-FUNCTIONAL: behaviour-equivalent; temp slots / MS2Ptr glue pairing and EH unwind map differ from the exe
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
    if (_stricmp(szMethod, "onClickBuyGoods") == 0) {
        FUN_1403ed2b0()->FUN_141adc750(0x4f1d);
        return 1;
    }
    return 0;
}

// @0x140fb8240
// MS2-FUNCTIONAL: behaviour-equivalent; temp slots / MS2Ptr glue pairing and EH unwind map differ from the exe
void UIVIPDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    CStringW strType = pArgs->FUN_1422b8f40();
    if (!FUN_140841300(strType, "benefitItem")) {
        if (FUN_140841300(strType, "effectIcon")) {
            Unk_VdEffectHold effect(FUN_140fb9980()->GetFirstEffect());
            if (effect.IsNull())
                return;
            ASTooltip tip(*pRetVal, 2);
            tip.FUN_1409e2750(effect.get(), 3, 0);
        }
    } else {
        unsigned nBenefitId = pArgs->FUN_1422b8b10();
        CVIPBenefitItemPtr spBenefit = FUN_140fb9980()->GetBenefitItem(nBenefitId);
        if (spBenefit == 0)
            return;
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b130(spBenefit->m_nItemId, spBenefit->m_nItemRank, 0) != 0) {
            spItem->FUN_140526c70(spBenefit->m_nItemCount);
            MS2Ptr<CItem> spWorn = static_cast<MyPC*>(pPlayer)->FUN_14152e2f0(spItem);
            ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 4, 2);
            if (FUN_1409e13a0(&tip, spWorn.get(), spItem.get()) != 0) {
                if (spBenefit->m_nItemPeriod > 0)
                    FUN_1409d6a40(&tip, FUN_1405276c0(spItem.get()), spBenefit->m_nItemPeriod);
                FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
            }
        }
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
// MS2-FUNCTIONAL: behaviour-equivalent; temp slots / MS2Ptr glue pairing and EH unwind map differ from the exe
int UIVIPDialog::FUN_140fb8680()
{
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    if (FUN_141662de0(pPlayer) == 0)
        return 0;
    int nCount = 0;
    ATL::CAtlArray<CVIPBenefitItemPtr> items;
    FUN_140fb9980()->GetBenefitItems(items);
    for (unsigned i = 0; i < items.GetCount(); i++) {
        CVIPBenefitItemPtr spBenefit = items[i];
        if (spBenefit == 0)
            continue;
        if (FUN_140fb9720(spBenefit->m_nId) != 0)
            nCount++;
    }
    return nCount;
}

// @0x140fb87d0
// MS2-FUNCTIONAL: behaviour-equivalent; temp slots / MS2Ptr glue pairing and EH unwind map differ from the exe
void UIVIPDialog::FUN_140fb87d0(CInPacket& packet, int nMode)
{
    if (nMode == 1) {
        m_claimedIds.RemoveAll();
        unsigned nCount = packet.vfunc_o8_3();
        for (unsigned i = 0; i < nCount; i++)
            m_claimedIds.AddTail(packet.vfunc_o8_3());
        FUN_140fb9150();
        Unk_VdGameMenu* pMenu = FUN_140938b90(0x4e28);
        if (pMenu != 0)
            pMenu->FUN_141938ae0(0x4f1b, 0);
    } else if (nMode == 2) {
        unsigned nBenefitId = packet.vfunc_o8_3();
        m_claimedIds.AddTail(nBenefitId);
        FUN_140fb9150();
        CVIPBenefitItemPtr spBenefit = FUN_140fb9980()->GetBenefitItem(nBenefitId);
        if (spBenefit == 0)
            return;
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x11, GetStringCommonByKey(CStringW(L"s_vip_dialog_get_benefit_item")), 0, CStringW(L""));
        if (spBox.get() == 0)
            return;
        MS2Ptr<CItem> spItem(new CItem());
        if (!spItem->FUN_140523c40(spBenefit->m_nItemId, spBenefit->m_nItemRank, 0))
            return;
        spItem->FUN_140526c70(spBenefit->m_nItemCount);
        spBox->FUN_141a01ee0(MS2Ptr<CItem>(spItem), spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
        spBox->FUN_141a01700(0x475, 0, 0);
        FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
        FUN_141276180(s_sndCashBuy, CString(""));
    }
}

// @0x140fb8d10
// MS2-FUNCTIONAL: behaviour-equivalent; temp slots / MS2Ptr glue pairing and EH unwind map differ from the exe
void UIVIPDialog::FUN_140fb8d10()
{
    if (!m_30)
        return;
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    MS2Ptr<ASTextField> spTime = FUN_140bb4cf0(CString("m_remainTime"));
    if (spTime == 0)
        return;
    if (FUN_141662de0(pPlayer) == 0) {
        spTime->FUN_1422c4cd0(GetStringCommonByKey(CStringW(L"s_vip_dialog_end_time")));
    } else {
        CMsTime now(FUN_140869440());
        CMsTime end(FUN_141662e90(pPlayer));
        ATL::CTimeSpan span = end - now;
        if (FUN_140e452e0(span, ATL::CTimeSpan(0)))
            return;
        CStringW strRemain = FUN_14086aec0(span, 1, 1, 0, 0);
        if (strRemain.IsEmpty())
            strRemain = GetStringCommonByKey(CStringW(L"s_vip_dialog_remain_time_hour"));
        else
            strRemain = FUN_1405c2690(CStringW(L"s_vip_dialog_remain_time"), strRemain);
        spTime->FUN_1422c4f00(strRemain);
    }
    int nTextWidth = (int)(__int64)spTime->FUN_1422c5970();
    float fX, fY;
    spTime->FUN_1422c0f60(&fX, &fY);
    fX = fX + (float)((spTime->FUN_1422c1340() - nTextWidth) - 0x1e);
    MS2Ptr<ASMovieClip> spIcon = FUN_140ba7930(CString("m_timerIcon"));
    if (spIcon != 0)
        spIcon->FUN_1422c00f0(fX, fY);
}

// @0x140fb9150
// MS2-FUNCTIONAL: behaviour-equivalent; temp slots / MS2Ptr glue pairing and EH unwind map differ from the exe
void UIVIPDialog::FUN_140fb9150()
{
    if (!m_30)
        return;
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    MS2Ptr<Unk_VdList> spList = GetChild<Unk_VdList>(CString("m_benefitItemList"));
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
        if (spData.get() == 0)
            continue;
        MS2Ptr<CItem> spItem(new CItem());
        if (!spItem->FUN_140523c40(spBenefit->m_nItemId, spBenefit->m_nItemRank, 0))
            continue;
        ASObj row(2);
        row.FUN_1409c0d20("id", spBenefit->m_nId);
        row.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141811980(1, spBenefit->m_nItemId));
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
        row.FUN_1407cb9c0("disableButton", FUN_140fb9720(spBenefit->m_nId) == 0);
        spList->FUN_1422dd230(row);
    }
    spList->vfunc_24(true);
}

// @0x140fb9720
// MS2-FUNCTIONAL: behaviour-equivalent; temp slots / MS2Ptr glue pairing and EH unwind map differ from the exe
int UIVIPDialog::FUN_140fb9720(unsigned nBenefitId)
{
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    if (FUN_141662de0(pPlayer) == 0)
        return 0;
    return m_claimedIds.Find(nBenefitId) == 0;
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
