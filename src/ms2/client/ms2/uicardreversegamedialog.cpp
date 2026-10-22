// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Card reverse game page (UICardReverseGameDialog, UI id 0x4f02):
// the server (opcode 0xda) sends a deck of reward cards, the page shuffles them, the player picks cards one by one and each
// pick is answered with the opened reward. The unit ends with the CAtlArray<MS2Ptr<CardReward>> glue and the CRT memmove_s.
// MS2-UNIT: ?\uicardreversegamedialog.cpp
// MS2-RANGE: 0x1400de680-0x1400de990 .text$di
// MS2-RANGE: 0x140f26990-0x140f29a20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicardreversegamedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uicardreversegamedialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the unit's header statics (the page includes the statics header a second time) ----
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_sortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill2 = "skill";
static CString s_stun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local placeholders (unrecovered helpers) ----
typedef UICardReverseGameDialog::CardReward CardReward;

// The page's AS movie (m_30): the methods the page calls.
class Unk_CRAS : public AScript
{
public:
    Scaleform::GFx::Value FUN_140acd130(const char* szMethod, CStringW strArg);
    Scaleform::GFx::Value FUN_1409ba030(const char* szMethod, int nArg);
    Scaleform::GFx::Value FUN_1422bb330(const char* szMethod);
    Scaleform::GFx::Value FUN_1409b13b0(const char* szMethod, Scaleform::GFx::Value arg);
};
void FUN_140614800(const Scaleform::GFx::Value& v);                // destroy a result value
Scaleform::GFx::Value FUN_1406146a0(const Scaleform::GFx::Value& v);   // copy a value

// The name table (global strings).
class Unk_CRNames { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_CRNames* FUN_1401a9d70();
CStringW FUN_140811740(int nId, const int& nArg1, const int& nArg2);
CStringW FUN_140b99450(CStringW strKey, const CStringW& strA, const unsigned& nB);
CStringW FUN_1409e97f0(int nId, const unsigned& nArg);
CStringW FUN_14028de60(int nId);
void FUN_140d73aa0(CStringW strText, int nType, IMessageListener* pListener, CStringW strTag);

class Unk_CRTextFilter { public: void FUN_1416fb300(CStringW& str); };
Unk_CRTextFilter* FUN_1403b4750();

// Item slot bindings (the bound slot key -> the item).
void FUN_141415600(const CString& strKey);                         // unbind
void FUN_141415450(const CString& strKey, MS2Ptr<CItem> spItem, int a, int b, int c);   // bind
void FUN_140165270(ATL::CAtlArray<CString>& arr, const CString& str);    // CAtlArray<CString>::Add
void FUN_1402c2890(ATL::CAtlArray<CString>& arr);                        // CAtlArray<CString>::RemoveAll

char FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);             // has the AS object been released
class Unk_CRSceneMgr;
Unk_CRSceneMgr* FUN_1408e57f0();
void FUN_1422b9fd0(Unk_CRSceneMgr* pMgr, int nScene);
CUIService* FUN_1403ed2b0();
void FUN_141901470(int n, int nTypeId);
void FUN_14151f200();
void FUN_140710590(COutPacket& packet);                            // send

class Unk_CRPlayer { public: void* FUN_141bd0cc0(); };
Unk_CRPlayer* FUN_1403ed2d0();

class Unk_CRRawItem { public: char m_data[0x10]; };

MS2_EMIT_CRT_MEMMOVE_S();

// ---- the shuffle ----

// @0x140f28bd0
static Unk_CRRawItem& FUN_140f28bd0(MS2Ptr<CardReward>& sp) { return reinterpret_cast<Unk_CRRawItem&>(sp); }

// Swap two cards.
// @0x140f28be0
static void FUN_140f28be0(MS2Ptr<CardReward>& a, MS2Ptr<CardReward>& b)
{
    Unk_CRRawItem tmp = FUN_140f28bd0(a);
    FUN_140f28bd0(a) = FUN_140f28bd0(b);
    FUN_140f28bd0(b) = tmp;
}

// Fisher-Yates over the cards.
// @0x140f28b30
// MS2-FUNCTIONAL: code generation differs (branch layout / temporaries)
static void FUN_140f28b30(ATL::CAtlArray<MS2Ptr<CardReward> >& cards)
{
    int nCount = (int)cards.GetCount();
    int nLast;
    while (nLast = nCount - 1, 0 < nLast)
    {
        int nPick = rand() % nCount;
        nCount = nLast;
        if (nLast != nPick)
            FUN_140f28be0(cards[nLast], cards[nPick]);
    }
}

// ---- UICardReverseGameDialog ----

// @0x140f26990
UICardReverseGameDialog::UICardReverseGameDialog()
    : m_1e8(0), m_1ec(0), m_1f0(-1), m_1f4(0), m_1f8(0)
{
    m_2c = 0xc;
    FUN_141925e70(0, 1);
    FUN_141924170(1);
}

// @0x140f26aa0
CString UICardReverseGameDialog::GetTypeName()
{
    return CString("CardReverseGameDialog");
}

// Refresh the "N cards left" info text.
// @0x140f26af0
// MS2-FUNCTIONAL: code generation differs (branch layout / temporaries)
void UICardReverseGameDialog::OnCardTweenComplete()
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        int nType = 3;
        CStringW strText = FUN_140811740(0xc40, m_1f4, nType);
        static_cast<Unk_CRAS*>(m_30.operator->())->FUN_140acd130("setSelectInfoText", CStringW(strText));
    }
}

// @0x140f26bd0
// MS2-FUNCTIONAL: code generation differs (branch layout / temporaries)
int UICardReverseGameDialog::vfunc_65()
{
    if (UIDialog::vfunc_65())
        return 1;
    return 0;
}

// @0x140f26c00
void UICardReverseGameDialog::vfunc_67()
{
    for (unsigned i = 0; i < m_180.GetCount(); ++i)
        FUN_141415600(m_180[i]);
    FUN_1402c2890(m_180);
    FUN_141901470(1, 0x4f02);
    UIDialog::vfunc_67();
    FUN_1403ed2b0()->FUN_141ada610(0x6200022);
    FUN_1403ed2b0()->FUN_141adad20(0x6200022);
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
}

// @0x140f26cd0
void UICardReverseGameDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_1422b9fd0(FUN_1408e57f0(), 0x6200022);
    FUN_1403ed2b0()->FUN_141ad9e50(0x6200022);
    FUN_1403ed2b0()->FUN_141ada6f0(0x6200022);
    m_1c8.RemoveAll();
    m_1a8.RemoveAll();
    m_1a0 = 0;
    m_1f8 = 0;
    m_1f4 = 0;
    m_1f0 = -1;
    FUN_141901470(0, 0x4f02);
    COutPacket packet(0x86, 0);
    packet.vfunc_o10_1(0);
    FUN_140710590(packet);
}

// @0x140f26de0
void UICardReverseGameDialog::vfunc_43()
{
    UIDialog::vfunc_43();
}

// The server data of the game (opcode 0xda): 0 the deck, 1 shuffle, 2 a card was picked, 3 the result.
// @0x140f26e00
// MS2-FUNCTIONAL: code generation differs (temporaries / frame layout)
void UICardReverseGameDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    if (pPacket->FUN_14070fe80() == 0xda)
    {
        char cMode = pPacket->vfunc_o8_1();
        if (cMode == 0)
        {
            m_1c8.RemoveAll();  // (the exe clears the pick list through the shared helper)
            for (unsigned i = 0; i < m_180.GetCount(); ++i)
                FUN_141415600(m_180[i]);
            FUN_1402c2890(m_180);
            m_1e8 = pPacket->vfunc_o8_3();
            m_1ec = pPacket->vfunc_o8_3();
            unsigned nCards = pPacket->vfunc_o8_3();
            for (unsigned nCard = 0; nCard < nCards; ++nCard)
            {
                MS2Ptr<CardReward> spCard(new CardReward);
                spCard->m_nIndex = nCard;
                spCard->m_nItemId = pPacket->vfunc_o8_3();
                spCard->m_nRank = pPacket->vfunc_o8_1();
                spCard->m_nCount = pPacket->vfunc_o8_3();
                if (m_30.get() != 0)
                {
                    ASObj obj(2);
                    CString strBind;
                    MS2Ptr<CItem> spItem(new CItem);
                    if (spItem->FUN_140523c40(spCard->m_nItemId, spCard->m_nRank, 0))
                    {
                        spItem->FUN_140526c70(spCard->m_nCount);
                        int nSeq = m_1a0++;
                        strBind.Format("%s_%d", (const char*)GetTypeName(), nSeq);
                        FUN_141415450(strBind, MS2Ptr<CItem>(spItem), 0, 0x415, 0);
                        FUN_140165270(m_180, strBind);
                    }
                    spCard->m_strBindId = strBind;
                    obj.FUN_1409c0d20("index", nCard);
                    obj.FUN_1407cba60("bindID", CString(strBind));
                    obj.FUN_1409c0d20("itemID", spCard->m_nItemId);
                    obj.FUN_1409c0d20("itemRank", spCard->m_nRank);
                    obj.FUN_1407cb9c0("itemCount", spCard->m_nCount);
                    obj.FUN_1407cbb20("itemName", spItem->FUN_140527b10());
                    static_cast<Unk_CRAS*>(m_30.operator->())->FUN_1409b13b0("updateItem", FUN_1406146a0(obj.FUN_1422bb870()));
                    m_1a8.Add(spCard);
                }
            }
            CStringW strItem = FUN_1401a9d70()->FUN_141811980(1, m_1e8);
            CStringW strNotice = FUN_140b99450(CStringW(L"s_card_reverse_game_dialog_play_notice"), strItem, m_1ec);
            static_cast<Unk_CRAS*>(m_30.operator->())->FUN_140acd130("setPlayInfoText", CStringW(strNotice));
        }
        else if (cMode == 1)
        {
            m_1f4 = 3;
            FUN_140614800(static_cast<Unk_CRAS*>(m_30.operator->())->FUN_1422bb330("onShuffle"));
            m_1c8.Copy(m_1a8);
            for (unsigned i = 0; i < m_180.GetCount(); ++i)
                FUN_141415600(m_180[i]);
            FUN_1402c2890(m_180);
            FUN_140f28b30(m_1c8);
        }
        else if (cMode == 2)
        {
            if (!m_1a8.IsEmpty())
            {
                int nPick = pPacket->vfunc_o8_3();
                m_1f8 = m_1a8[nPick];
                --m_1f4;
                for (unsigned i = 0; i < m_1c8.GetCount(); ++i)
                {
                    MS2Ptr<CardReward> spCard(m_1c8[i]);
                    if (spCard->m_nIndex == m_1a8[nPick]->m_nIndex)
                    {
                        m_1c8.RemoveAt(i, 1);
                        break;
                    }
                }
                static_cast<Unk_CRAS*>(m_30.operator->())->FUN_1409ba030("openCard", m_1f0);
            }
        }
        else if (cMode == 3)
        {
            unsigned nResult = pPacket->vfunc_o8_1();
            if (nResult == 0)
            {
                CStringW strMsg = FUN_1409e97f0(0xc3f, (const unsigned&)m_1e8);
                FUN_1403b4750()->FUN_1416fb300(strMsg);
                FUN_140d73aa0(CStringW(strMsg), 0, 0, CStringW(L""));
                static_cast<Unk_CRAS*>(m_30.operator->())->FUN_1409ba030("setShuffleButton", 1);
            }
        }
    }
}

// @0x140f27b40
int UICardReverseGameDialog::vfunc_13()
{
    return 0;
}

// The AS callbacks: shuffle button, card click, card open, tween complete, close.
// @0x140f27b50
// MS2-FUNCTIONAL: code generation differs (temporaries / frame layout)
int UICardReverseGameDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp(szMethod, "onShuffleButton") == 0)
    {
        COutPacket packet(0x86, 0);
        packet.vfunc_o10_1(1);
        FUN_140710590(packet);
        return 1;
    }
    if (_stricmp(szMethod, "onCardClick") == 0)
    {
        if (m_1f8 == 0 && 0 < m_1f4 && m_30.get() != 0 && m_1f0 == -1)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                COutPacket packet(0x86, 0);
                packet.vfunc_o10_1(2);
                FUN_140710590(packet);
                m_1f0 = data.FUN_1422b8b10();
            }
        }
        return 1;
    }
    if (_stricmp(szMethod, "onCardOpen") == 0)
    {
        if (m_30.get() != 0)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                int nIndex = data.FUN_1422b8b10();
                bool bOpened = data.FUN_1422b8a90();
                ASObj obj(2);
                if (!bOpened || m_1f8.get() == 0)
                {
                    if (!m_1c8.IsEmpty())
                    {
                        obj.FUN_1409c0d20("index", nIndex);
                        MS2Ptr<CardReward> spCard(m_1c8[m_1c8.GetCount() - 1]);
                        m_1c8.RemoveAt(m_1c8.GetCount() - 1, 1);
                        CString strBind;
                        MS2Ptr<CItem> spItem(new CItem);
                        if (spItem->FUN_140523c40(spCard->m_nItemId, spCard->m_nRank, 0))
                        {
                            spItem->FUN_140526c70(spCard->m_nCount);
                            int nSeq = m_1a0++;
                            strBind.Format("%s_%d", (const char*)GetTypeName(), nSeq);
                            FUN_141415450(strBind, MS2Ptr<CItem>(spItem), 0, 0x415, 0);
                            FUN_140165270(m_180, strBind);
                            spCard->m_strBindId = strBind;
                        }
                        obj.FUN_1407cba60("bindID", CString(spCard->m_strBindId));
                        obj.FUN_1409c0d20("itemID", spCard->m_nItemId);
                        obj.FUN_1409adc90("itemRank", spCard->m_nRank);
                        obj.FUN_1407cb9c0("itemCount", spCard->m_nCount);
                        obj.FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, spCard->m_nItemId));
                        static_cast<Unk_CRAS*>(m_30.operator->())->FUN_1409b13b0("updateItem", FUN_1406146a0(obj.FUN_1422bb870()));
                    }
                }
                else
                {
                    obj.FUN_1409c0d20("index", nIndex);
                    CString strBind;
                    MS2Ptr<CItem> spItem(new CItem);
                    if (spItem->FUN_140523c40(m_1f8->m_nItemId, m_1f8->m_nRank, 0))
                    {
                        spItem->FUN_140526c70(m_1f8->m_nCount);
                        int nSeq = m_1a0++;
                        strBind.Format("%s_%d", (const char*)GetTypeName(), nSeq);
                        FUN_141415450(strBind, MS2Ptr<CItem>(spItem), 0, 0x415, 0);
                        FUN_140165270(m_180, strBind);
                        m_1f8->m_strBindId = strBind;
                    }
                    obj.FUN_1407cba60("bindID", CString(m_1f8->m_strBindId));
                    obj.FUN_1409c0d20("itemID", m_1f8->m_nItemId);
                    obj.FUN_1409c0d20("itemRank", m_1f8->m_nRank);
                    obj.FUN_1407cb9c0("itemCount", m_1f8->m_nCount);
                    obj.FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, m_1f8->m_nItemId));
                    static_cast<Unk_CRAS*>(m_30.operator->())->FUN_1409b13b0("updateItem", FUN_1406146a0(obj.FUN_1422bb870()));
                    OnCardTweenComplete();
                    m_1f0 = -1;
                    m_1f8 = 0;
                }
            }
        }
        return 1;
    }
    if (_stricmp(szMethod, "onCardTweenComplete") == 0)
    {
        OnCardTweenComplete();
        return 1;
    }
    if (_stricmp(szMethod, "OnCloseDialog") == 0)
    {
        if (m_1f4 < 1)
            vfunc_67();
        else
            FUN_140d73aa0(FUN_14028de60(0xc41), 1, static_cast<IMessageListener*>(this), CStringW(L""));
        return 1;
    }
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}

// The card tooltip.
// @0x140f288c0
// MS2-FUNCTIONAL: code generation differs (temporaries / frame layout)
void UICardReverseGameDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        int nItemId = pArgs->FUN_1422b8b10();
        int nRank = pArgs->FUN_1422b8b10();
        int nCount = pArgs->FUN_1422b8b10();
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_14052b130(nItemId, nRank, 0) != 0)
        {
            spItem->FUN_140526c70(nCount);
            ASTooltip tip(pPlayer, 0x20, 2);
            if (tip.FUN_1409e0d40(spItem.get()) != 0)
            {
                *pRetVal = tip.FUN_1422bb870();
                return;
            }
        }
    }
}

// The message box answer (IMessageListener at +0x18): the leave box closes the page on "yes".
// @0x140f28a70
int UICardReverseGameDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && pSender == dynamic_cast<UIMessageBox*>(pSender))
    {
        int nResult = pMsg->FUN_1422b8a10();
        FUN_14151f200();
        if (nResult == 0)
            vfunc_67();
    }
    return 1;
}

// @0x140f28d70
UICardReverseGameDialog::CardReward::CardReward()
    : m_nIndex(0), m_nItemId(0), m_nRank(1), m_nCount(0)
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca90d0-0x142ca9210 .text$yd
