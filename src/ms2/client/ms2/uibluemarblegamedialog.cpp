// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBlueMarbleGameDialog: see uibluemarblegamedialog.h.
// MS2-UNIT: ?\uibluemarblegamedialog.cpp
// MS2-RANGE: 0x140f21590-0x140f24e40 .text$mn
// MS2-RANGE: 0x1400de300-0x1400de4a0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??1UIBlueMarbleGameDialog@@UEAA@XZ 0x140f24ac0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibluemarblegamedialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uibluemarblegamedialog.h"

#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cxmldata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static UICommon::CMyPCKeyInputController s_keyInput;

// ---- unit-local placeholders (unrecovered helpers) ----

// The dice button of the movie.
class Unk_140acd6e0 : public ASDisplayObject { public: void FUN_1422c1fe0(unsigned int bEnabled); };

void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// The debug key state (singleton).
class Unk_14025e7c0 { public: bool FUN_14116d720(); };
Unk_14025e7c0* FUN_14025e7c0();

// The UI service / scene manager singletons (the scene calls of the dialog's open and close).
class Unk_BmSceneCtl;
class Unk_BmSceneMgr;
Unk_BmSceneCtl* FUN_1403ed2b0();
Unk_BmSceneMgr* FUN_1408e57f0();
void FUN_141ad9e50(Unk_BmSceneCtl* pCtl, int nScene);
void FUN_141ada610(Unk_BmSceneCtl* pCtl, int nScene);
void FUN_141ada6f0(Unk_BmSceneCtl* pCtl, int nScene);
void FUN_141adad20(Unk_BmSceneCtl* pCtl, int nScene);
void FUN_1422b9fd0(Unk_BmSceneMgr* pMgr, int nScene);
void FUN_141901470(int n, int nType);                               // UIObject::vfunc_47's helper (UI type 0x4f15)

// The chat output.
class Unk_BmChat { public: void FUN_1416fb300(const CStringW& strText); };
Unk_BmChat* FUN_1403b4750();

CGameRule* FUN_1401c0d90();                                         // TSingleton<CGameRule>::GetInstance
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringTable* GetStringTable();
extern Unk_Inventory DAT_143ab2a90;                                 // the player inventory

#include "ms2/commonfiles/commonutil.h"
CStringW FUN_14028e060(const CString& strKey, const fmt::ArgList& args);
CStringW FUN_140938ae0(CStringW strKey, const int& n);              // localized text with one number
CStringW FUN_14062b4f0(CStringW strKey, const int* pn);             // localized text with one number (pointer form)
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);    // localized text with one text
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& strArg);   // StringFormat with one text argument
CStringW FUN_140218290(int n);                                      // number text
CStringW FUN_140298ea0(CStringW strKey);                            // localized text, tooltip form
CStringW FUN_14016a730(const char* sz, int nCodePage);              // multibyte to wide
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
void FUN_141415450(const CString& strId, MS2Ptr<CItem> spItem, int a, int b, int c);   // bind an item under the id
void FUN_141415600(const CString& strId);                           // release the item bound to the id
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW text, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);

// ---- shared COMDATs first instantiated here ----

// @0x140f24320
CStringW FUN_140f24320(CString strKey, const CStringW& strName, const int& nCount)
{
    return FUN_14028e060(strKey, fmt::ArgList(fmt::internal::make_type(strName, nCount),
        fmt::internal::ArgArray<2>::Type{fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(strName),
                                         fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(nCount)}));
}

// @0x140f24650
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f24720
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2, int a3, CStringW a4, int a5)
{
    ASArgList args;
    args.FUN_1409b2800(5);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    FUN_1422bcea0(args.FUN_1409b1f70(3), a4);
    FUN_1422bccb0(args.FUN_1409b1f70(4), a5);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f24850
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, CStringW a2, int a3, int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140f21590
UIBlueMarbleGameDialog::UIBlueMarbleGameDialog()
{
    m_2c = 12;
    m_nFreeDice = 0;
    m_nPosition = 0;
    m_nConsumeItemId = 0;
    m_nConsumeItemCount = 0;
    m_bIdle = 1;
    m_58 = 0;
    FUN_141924170(1);
    FUN_141925e70(0, 1);
}

// @0x140f21680
CString UIBlueMarbleGameDialog::GetTypeName()
{
    return "BlueMarbleGameDialog";
}

// @0x140f216d0
void UIBlueMarbleGameDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
}

// @0x140f216f0
void UIBlueMarbleGameDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    for (size_t i = 0; i < m_boundIds.GetCount(); i++)
        FUN_141415600(m_boundIds.GetAt(i));
    m_boundIds.RemoveAll();
    FUN_141901470(1, 0x4f15);
}

// @0x140f21790
void UIBlueMarbleGameDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_141ada610(FUN_1403ed2b0(), 0x6200022);
    FUN_141adad20(FUN_1403ed2b0(), 0x6200022);
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
}

// @0x140f217f0
void UIBlueMarbleGameDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    COutPacket packet(static_cast<int>(SendOp::Mapleopoly), 0);
    packet.WriteUInt8(0);
    FUN_140710590(packet);
}

// @0x140f21850
void UIBlueMarbleGameDialog::vfunc_79(void* p)
{
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    UIDialog::vfunc_79(p);
    if (pPacket->FUN_14070fe80() == 0xe5) {
        char nKind = pPacket->ReadUInt8();
        if (nKind == 0) {
            FUN_1422b9fd0(FUN_1408e57f0(), 0x6200022);
            FUN_141ad9e50(FUN_1403ed2b0(), 0x6200022);
            FUN_141ada6f0(FUN_1403ed2b0(), 0x6200022);
            FUN_141901470(0, 0x4f15);
            m_nPosition = pPacket->ReadInt32();
            m_nFreeDice = pPacket->ReadInt32();
            m_nConsumeItemId = pPacket->ReadInt32();
            m_nConsumeItemCount = pPacket->ReadInt32();
            FUN_140cfee80((*m_30).FUN_1422bb890(), "m_warning",
                          FUN_140f24320("$s_bluemarble_warning", GetStringTable()->FUN_141811980(1, m_nConsumeItemId),
                                        m_nConsumeItemCount));
            FUN_140f227a0(*pPacket);
            FUN_140f22bb0(m_nPosition);
            FUN_140f23b90();
            FUN_140f23ca0();
            FUN_140f23940();
            m_30->Invoke("moveImmediately", m_nPosition);
            m_30->Invoke("enableDebugDice", FUN_14025e7c0()->FUN_14116d720());
            vfunc_8(1);
            m_bIdle = 1;
        } else if (nKind == 2) {
            char nAction = pPacket->ReadUInt8();
            m_nPosition = pPacket->ReadInt32();
            int nDice1 = pPacket->ReadInt32();
            int nDice2 = pPacket->ReadInt32();
            m_nFreeDice = pPacket->ReadInt32();
            FUN_140f22fe0(nDice1, nDice2, nAction);
            FUN_140f237e0(m_nPosition - (nDice1 + nDice2), m_nPosition);
            if (nAction == 2) {
                m_30->Invoke("onResetDice");
                m_bIdle = 1;
            }
            m_30->Invoke("playQueue");
            COutPacket packet(static_cast<int>(SendOp::Mapleopoly), 0);
            packet.WriteUInt8(3);
            FUN_140710590(packet);
        } else if (nKind == 4) {
            int nPrevPosition = m_nPosition;
            short nAction = pPacket->ReadInt16();
            m_nPosition = pPacket->ReadInt32();
            m_nFreeDice = pPacket->ReadInt32();
            int nArg = pPacket->ReadInt32();
            int nArg2 = pPacket->ReadInt32();
            bool bReset;
            if (nAction == 2 || nAction == 3)
                bReset = false;
            else
                bReset = true;
            FUN_140f23200(nAction, nArg, nPrevPosition);
            FUN_140f237e0(nPrevPosition, m_nPosition);
            if (nAction == 10 || nAction == 9)
                FUN_140f23590(nArg, nArg2, 0);
            if (bReset) {
                m_30->Invoke("onResetDice");
                m_bIdle = 1;
            }
            m_30->Invoke("playQueue");
            FUN_140f23940();
            if (!bReset) {
                COutPacket packet(static_cast<int>(SendOp::Mapleopoly), 0);
                packet.WriteUInt8(3);
                FUN_140710590(packet);
            }
        } else if (nKind == 6) {
            char nResult = pPacket->ReadUInt8();
            if (nResult == 1) {
                CStringW strText = FUN_140938ae0(CStringW(L"s_bluemarble_result_consume_fail"), m_nConsumeItemId);
                FUN_1403b4750()->FUN_1416fb300(strText);
                FUN_1412751f0(strText, 1, 1);
            } else if (nResult == 4) {
                FUN_1412751f0(GetStringCommonByKey(L"s_bluemarble_result_dice_complete"), 1, 1);
            } else if (nResult == 5) {
                FUN_1412751f0(GetStringCommonByKey(L"s_bluemarble_result_dice_not_complete"), 1, 1);
            }
            FUN_140f24140(1);
            m_bIdle = 1;
        }
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order/EH state layout)

// @0x140f22350
int UIBlueMarbleGameDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onDice") == 0) {
        COutPacket packet(static_cast<int>(SendOp::Mapleopoly), 0);
        packet.WriteUInt8(1);
        FUN_140710590(packet);
        FUN_140f24140(0);
        m_bIdle = 0;
    } else if (_stricmp(szMethod, "onDiceMovieComplete") == 0) {
        FUN_140f23940();
        FUN_140f23b90();
    } else if (_stricmp(szMethod, "onEndQueue") == 0) {
        FUN_140f24140(m_bIdle);
        FUN_140f23ca0();
        FUN_140f23da0();
    } else if (_stricmp(szMethod, "onClickDebugDice") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nDice1 = FUN_1407181a0(data.FUN_1422b8f40());
            int nDice2 = FUN_1407181a0(data.FUN_1422b8f40());
            if (nDice1 < 1 || 6 < nDice1)
                return 1;
            if (nDice2 < 1 || 6 < nDice2)
                return 1;
            COutPacket packet(static_cast<int>(SendOp::Mapleopoly), 0);
            packet.WriteUInt8(5);
            packet.WriteInt32(nDice1);
            packet.WriteInt32(nDice2);
            FUN_140710590(packet);
        }
        return 1;
    }
    return 0;
}

// @0x140f22640
int UIBlueMarbleGameDialog::vfunc_71()
{
    if (m_bIdle == 0) {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d74390(GetStringCommonByKey(L"s_bluemarble_close"), 1,
            Delegate<bool(int, const CMsgBoxData&)>(this, &UIBlueMarbleGameDialog::FUN_140f22760));
        return 1;
    }
    return 0;
}   // MS2-FUNCTIONAL: not byte-matched (call order/EH state layout)

// @0x140f22760
bool UIBlueMarbleGameDialog::FUN_140f22760(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
        vfunc_67();
    return true;
}

// @0x140f227a0
void UIBlueMarbleGameDialog::FUN_140f227a0(CInPacket& packet)
{
    unsigned int nCells = packet.ReadInt32();
    for (unsigned int i = 0; i < nCells; i++) {
        short nKind = packet.ReadInt16();
        int nArg = packet.ReadInt32();
        int nCount = packet.ReadInt32();
        ASObj row(2);
        row.FUN_1409c0d20("idx", i);
        if (nKind == 10) {
            MS2Ptr<CItemData> spData = FUN_14053f870(nArg);
            if (spData.get()) {
                row.FUN_1407cba60("binding", FUN_140f23f10(spData->FUN_14053c510(), spData->FUN_14053c5a0(), nCount));
            }
        } else if (nKind != 0) {
            CStringW strKind = FUN_140218290(nKind);
            CStringW strAction = FUN_14062b4f0(FUN_1401e8510(L"s_bluemarble_action_{0}", strKind), &nArg);
            CStringW strTooltip = FUN_140298ea0(FUN_1401e8510(L"s_bluemarble_action_tooltip_{0}", strKind));
            row.FUN_1407cbb20("action", strKind);
            row.FUN_1407cbb20("actionStr", strAction);
            row.FUN_1407cbb20("tooltipStr", strTooltip);
        }
        if (m_30.get())
            m_30->Invoke("setBoard", row);
    }
}   // MS2-FUNCTIONAL: not byte-matched (call order/EH state layout)

// @0x140f22bb0
void UIBlueMarbleGameDialog::FUN_140f22bb0(int nPosition)
{
    ASArray rewards(2);
    MS2Ptr<BlueMarbleEventContext> spContext = FUN_1401c0d90()->FUN_14047b940();
    if (spContext.get()) {
        POSITION pos = spContext->m_rewards.GetHeadPosition();
        while (pos) {
            MS2Ptr<ItemEntity> spReward = spContext->m_rewards.GetValueAt(pos);
            int nRound = spContext->m_rewards.GetKeyAt(pos);
            MS2Ptr<CItemData> spData = FUN_14053f870(spReward->m_itemId);
            if (spData == 0) {
            } else {
                ASObj row(2);
                row.FUN_1407cba60("binding", FUN_140f23f10(spData->FUN_14053c510(), spData->FUN_14053c5a0(), spReward->m_count));
                bool bReceive;
                if (nPosition < nRound * 0x1c || nRound == 0)
                    bReceive = false;
                else
                    bReceive = true;
                row.FUN_1407cbbe0("receive", bReceive);
                CStringW strRound;
                if (nRound == 0)
                    strRound = GetStringCommonByKey(L"s_bluemarble_reward_default");
                else
                    strRound = FUN_14062b4f0(CStringW(L"s_bluemarble_reward_repeat"), &nRound);
                row.FUN_1407cbb20("round", strRound);
                rewards.FUN_1422bbf00(row);
            }
            spContext->m_rewards.GetNext(pos);
        }
    }
    if (m_30.get())
        m_30->FUN_140bd2cb0("onReward", rewards);
}   // MS2-FUNCTIONAL: not byte-matched (call order/EH state layout)

// @0x140f22fe0
void UIBlueMarbleGameDialog::FUN_140f22fe0(int nDice1, int nDice2, int nKind)
{
    CStringW strMessage;
    if (nKind == 2)
        strMessage = GetStringCommonByKey(L"s_bluemarble_result_trap_escape_fail");
    else if (nKind == 3)
        strMessage = GetStringCommonByKey(L"s_bluemarble_result_trap_escape_success");
    unsigned int nContinue = (unsigned int)(nKind != 2);
    int nRemain = m_nPosition - (nDice1 + nDice2);
    m_30->Invoke("onDice", nRemain, nDice1, nDice2, CStringW(strMessage), nContinue);
}

// @0x140f23200
void UIBlueMarbleGameDialog::FUN_140f23200(int nAction, int nArg, int nPrevPosition)
{
    CStringW strMessage;
    switch (nAction) {
    case 1:
        m_30->Invoke("onActionNotifyFail");
        break;
    case 7:
        m_30->Invoke("onActionNotifyTrap", nArg);
        break;
    case 8:
        m_30->Invoke("onActionNotifyTour", nArg);
        break;
    case 9:
        m_30->Invoke("onActionNotifyParadise", nArg);
        break;
    default:
        strMessage = FUN_14062b4f0(FUN_1401e8510(L"s_bluemarble_action_{0}", FUN_140218290(nAction)), &nArg);
        if (strMessage.GetLength() > 0)
            m_30->Invoke("onActionNotify", CStringW(strMessage));
        break;
    }
    switch (nAction) {
    case 2:
    case 3:
        m_30->Invoke("onActionWalk", m_nPosition, nPrevPosition, 1);
        break;
    case 4:
    case 8:
        m_30->FUN_1409ba0d0("onActionFly", m_nPosition, 0);
        break;
    }
}

// @0x140f23590
void UIBlueMarbleGameDialog::FUN_140f23590(int nItemId, int nRarity, int nCount)
{
    if (m_30.IsNull())
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData.get()) {
        CStringW strMessage = FUN_1405c2690(CStringW(L"s_bluemarble_get_item"),
                                            GetStringTable()->FUN_141811980(1, nItemId));
        m_30->Invoke("onRewardNotify", CStringW(strMessage),
                     FUN_14016a730(spData->FUN_14053fdd0(), 0), spData->FUN_14053c5a0(), nCount);
    }
}

// @0x140f237e0
void UIBlueMarbleGameDialog::FUN_140f237e0(int nPrevPosition, int nPosition)
{
    int nPrevLap = nPrevPosition / 0x1c;
    int nLap = nPosition / 0x1c;
    if (nPrevLap == nLap)
        return;
    MS2Ptr<BlueMarbleEventContext> spContext = FUN_1401c0d90()->FUN_14047b940();
    if (spContext.get()) {
        MS2Ptr<ItemEntity> spReward(0);
        if (spContext->m_rewards.Lookup(0, spReward))
            FUN_140f23590(spReward->m_itemId, spReward->m_count, 1);
        if (spContext->m_rewards.Lookup(nLap, spReward))
            FUN_140f23590(spReward->m_itemId, spReward->m_count, 1);
    }
}

// @0x140f23940
void UIBlueMarbleGameDialog::FUN_140f23940()
{
    CStringW strText = m_nFreeDice > 0 ? FUN_14062b4f0(CStringW(L"s_bluemarble_free_dice"), &m_nFreeDice)
                                       : GetStringCommonByKey(L"s_bluemarble_dice");
    if (m_30.get())
        m_30->Invoke("updateDiceButton", CStringW(strText), m_nFreeDice);
}

// @0x140f23b90
void UIBlueMarbleGameDialog::FUN_140f23b90()
{
    if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_coinCount")) {
        int nCoins = DAT_143ab2a90.FUN_140a5f180(m_nConsumeItemId, 0);
        CStringW strText = FUN_14062b4f0(CStringW(L"s_bluemarble_coin_count"), &nCoins);
        spText->FUN_1422c4cd0(strText);
    }
}

// @0x140f23ca0
void UIBlueMarbleGameDialog::FUN_140f23ca0()
{
    if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_finishCount")) {
        int nFinish = m_nPosition / 0x1c;
        CStringW strText = FUN_14062b4f0(CStringW(L"s_bluemarble_finish_count"), &nFinish);
        spText->FUN_1422c4cd0(strText);
    }
}

// @0x140f23da0
void UIBlueMarbleGameDialog::FUN_140f23da0()
{
    ASArray flags(2);
    if (MS2Ptr<BlueMarbleEventContext> spContext = FUN_1401c0d90()->FUN_14047b940()) {
        for (POSITION pos = spContext->m_rewards.GetHeadPosition(); pos != 0; spContext->m_rewards.GetNext(pos)) {
            int nRound = spContext->m_rewards.GetKeyAt(pos);
            bool bReceive = m_nPosition >= nRound * 0x1c && nRound != 0;
            flags.FUN_1422bbcd0(bReceive);
        }
    }
    if (m_30.get())
        m_30->FUN_140bd2cb0("updateReward", flags);
}

// @0x140f23f10
CString UIBlueMarbleGameDialog::FUN_140f23f10(int nItemId, int nRarity, int nCount)
{
    size_t nIndex = m_boundIds.GetCount();
    CString strId = Unk_SocketFormat("{0}_{1}", GetTypeName(), nIndex);
    MS2Ptr<CItem> spItem(new CItem);
    if (!spItem->FUN_140523c40(nItemId, nRarity, 0))
        return "";
    spItem->FUN_140526c70(nCount);
    FUN_141415450(strId, spItem, 0, 0, 0);
    m_boundIds.Add(strId);
    return strId;
}

// @0x140f24140
void UIBlueMarbleGameDialog::FUN_140f24140(int bEnabled)
{
    if (MS2Ptr<Unk_140acd6e0> spButton = FUN_140bb4b10("m_dice"))
        spButton->FUN_1422c1fe0(bEnabled);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca8f70-0x142ca9020 .text$yd
