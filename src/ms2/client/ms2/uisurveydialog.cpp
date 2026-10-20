// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISurveyDialog: the player survey box.
// MS2-UNIT: ?\uisurveydialog.cpp
// MS2-FUNCTIONAL: OnLoadComplete, vfunc_28, the packet handlers (FUN_140eda1b0..FUN_140edad50): temp / frame layout differs; behaviour-equivalent.
// MS2-RANGE: 0x1400dc9e0-0x1400dcaa0 .text$di
// MS2-RANGE: 0x140ed9b80-0x140edb370 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uisurveydialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uisurveydialog.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdlib.h>

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics ----
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400dc9e0

// ---- unit-local views of exe functions ----
extern __int64 DAT_143ab2828;                                       // the own character id
CStringW FUN_14028de60(int nStringId);                              // string table text
CStringW FUN_140632a60(int nStringId, const CStringW& strA, const CStringW& strB);
CStringW FUN_1409eadb0(int nStringId, const CStringW& strA, const CStringW& strB, const CStringW& strC);
CStringW FUN_14093fa20(int nStringId, const CStringW& str, const unsigned& nCount);
CStringW FUN_14052bd00(int nStringId, const CStringW& arg);         // string table text with one argument
CStringW FUN_1401d0160(const wchar_t* sz, const CStringW& str);    // sz + str
CStringW FUN_14061ad70(const CStringW& str, const wchar_t* sz);     // str + sz
CStringW FUN_1401d0080(const CStringW& strA, const CStringW& strB); // strA + strB
void FUN_1412751b0(const CStringW& strText, int nColor);            // print to the chat
void FUN_140cff1b0(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
void FUN_140710590(COutPacket& packet);
void FUN_140d73bc0(int nStringId, int nType, void* pListener, CStringW strTag);    // message box

// @0x140ed9b80
UISurveyDialog::UISurveyDialog()
{
    m_7c = 1;
    m_80 = 0;
}

// @0x140ed9c10
UISurveyDialog::~UISurveyDialog()
{
}

// @0x140ed9c80
CString UISurveyDialog::vfunc_1()
{
    return "SurveyDialog";
}

// @0x140ed9cd0
void UISurveyDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925fa0("m_dragBar");
    FUN_141925ec0("m_closeButton");
    CStringW strKind = FUN_14028de60(m_188 == 0 ? 0xc8e : 0xc8d);
    FUN_140cff1b0(FUN_1422dbb40(), "m_textSurvey", FUN_1401d0080(FUN_14061ad70(FUN_1401d0160(L"[", strKind), L"] "), m_190));
    for (size_t i = 0; i < m_198.GetCount(); i++)
        m_30->Invoke("addItem", m_198[i]);
    m_30->Invoke("initDatas");
}

// @0x140ed9fe0
void UISurveyDialog::vfunc_26()
{
    UIDialog::vfunc_26();
}

// @0x140eda000
int UISurveyDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnVote", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nAnswer = atoi(data.FUN_1422b8d30());
            if (nAnswer == -1)
                return 1;
            FUN_140eda2b0(nAnswer);
        }
        return 1;
    }
    if (_stricmp("OnClose", szMethod) == 0)
        FUN_140d73bc0(0xc9b, 1, static_cast<IMessageListener*>(this), CStringW(L"Close"));
    return 0;
}

// @0x140eda1b0
void UISurveyDialog::FUN_140eda1b0(CInPacket& packet)
{
    switch (static_cast<CInputStream&>(packet).vfunc_o8_1())
    {
    case 0:
        FUN_140eda360(packet);
        break;
    case 1:
        FUN_140eda530(packet);
        break;
    case 2:
        FUN_140eda3c0(packet);
        break;
    case 3:
        FUN_140eda790(packet);
        break;
    case 4:
        FUN_140eda980(packet);
        break;
    case 5:
        FUN_140edacb0(packet);
        break;
    case 6:
        FUN_140edad50(packet);
    }
}

// @0x140eda2b0
void UISurveyDialog::FUN_140eda2b0(int nAnswer)
{
    COutPacket packet(0x90, 0);
    packet.vfunc_o10_1(5);
    packet.vfunc_o10_1(5);
    packet.vfunc_o10_4(m_178);
    packet.vfunc_o10_4(m_180);
    packet.vfunc_o10_1(nAnswer);
    FUN_140710590(packet);
    vfunc_67();
}

// @0x140eda360
void UISurveyDialog::FUN_140eda360(CInPacket& packet)
{
    FUN_1412751b0(FUN_14028de60(0xc90), 0x14);
}

// @0x140eda3c0
void UISurveyDialog::FUN_140eda3c0(CInPacket& packet)
{
    CInputStream& in = packet;
    CStringW strName = in.vfunc_o8_8();
    CStringW strKind = FUN_14028de60(in.vfunc_o8_1() == 1 ? 0xc8d : 0xc8e);
    FUN_1412751b0(FUN_140632a60(0xc93, strKind, strName), 0x14);
    FUN_1412751b0(FUN_14028de60(0xc92), 0x14);
}

// @0x140eda530
void UISurveyDialog::FUN_140eda530(CInPacket& packet)
{
    CInputStream& in = packet;
    CStringW strName = in.vfunc_o8_8();
    CStringW strKind = FUN_14028de60(in.vfunc_o8_1() == 1 ? 0xc8d : 0xc8e);
    FUN_1412751b0(FUN_140632a60(0xc91, strKind, strName), 0x14);
    unsigned char nCount = in.vfunc_o8_1();
    for (int i = 0; i < (int)nCount; i++)
    {
        CStringW strAnswer = in.vfunc_o8_8();
        FUN_1412751b0(FUN_1401d0160(L"- ", strAnswer), 0x14);
    }
    FUN_1412751b0(FUN_14028de60(0xc92), 0x14);
}

// @0x140eda790
void UISurveyDialog::FUN_140eda790(CInPacket& packet)
{
    CInputStream& in = packet;
    CStringW strA = in.vfunc_o8_8();
    char cKindA = in.vfunc_o8_1();
    CStringW strB = in.vfunc_o8_8();
    char cKindB = in.vfunc_o8_1();
    CStringW strKind = FUN_14028de60(cKindA == 1 ? 0xc8d : 0xc8e);
    FUN_1412751b0(FUN_1409eadb0(cKindB == 1 ? 0xc95 : 0xc96, strKind, strA, strB), 0x14);
}

// @0x140eda980
void UISurveyDialog::FUN_140eda980(CInPacket& packet)
{
    CInputStream& in = packet;
    m_178 = in.vfunc_o8_4();
    m_180 = in.vfunc_o8_4();
    m_188 = in.vfunc_o8_1() == 1;
    m_190 = in.vfunc_o8_8();
    m_198.RemoveAll();
    unsigned char nCount = in.vfunc_o8_1();
    for (int i = 0; i < (int)nCount; i++)
        m_198.Add(in.vfunc_o8_8());
    if (FUN_141924740() != 0)
        vfunc_67();
    FUN_141924680();
    if (m_178 == DAT_143ab2828)
    {
        CStringW strKind = FUN_14028de60(m_188 == 0 ? 0xc8e : 0xc8d);
        FUN_1412751b0(FUN_140632a60(0xc97, strKind, m_190), 0x14);
    }
}

// @0x140edacb0
void UISurveyDialog::FUN_140edacb0(CInPacket& packet)
{
    CStringW strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    FUN_1412751b0(FUN_14052bd00(0xc98, strName), 0x14);
}

// @0x140edad50
void UISurveyDialog::FUN_140edad50(CInPacket& packet)
{
    CInputStream& in = packet;
    __int64 nId = in.vfunc_o8_4();
    bool bKind = in.vfunc_o8_1() == 1;
    CStringW strName = in.vfunc_o8_8();
    CStringW strKind = FUN_14028de60(bKind ? 0xc8d : 0xc8e);
    FUN_1412751b0(FUN_140632a60(0xc99, strKind, strName), 0x14);
    unsigned nCount = in.vfunc_o8_1();
    for (int i = 0; i <= (int)nCount; i++)
    {
        CStringW strAnswer = FUN_14028de60(0xc8f);
        if ((unsigned)i != nCount)
            strAnswer = in.vfunc_o8_8();
        unsigned nVotes = in.vfunc_o8_1();
        if ((unsigned)i == nCount && nVotes == 0)
            continue;
        CStringW strLine = FUN_14093fa20(0xc9a, strAnswer, nVotes);
        if (bKind)
        {
            for (int j = 0; j < (int)nVotes; j++)
                strLine += FUN_1401d0160(L" ", in.vfunc_o8_8());
        }
        FUN_1412751b0(strLine, 0x14);
    }
    if (FUN_141924740() != 0 && m_180 == nId)
        vfunc_67();
}

// @0x140edb160
int UISurveyDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    int nResult = pMsg->FUN_1422b8a10();
    CStringW strTag = pMsg->FUN_1422b8f40();
    if (strTag.CompareNoCase(L"Close") == 0 && nResult == 0)
        vfunc_67();
    return 0;
}
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142ca85a0-0x142ca85d0 .text$yd
