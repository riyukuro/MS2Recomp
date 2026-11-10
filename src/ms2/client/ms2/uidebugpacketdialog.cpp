// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDebugPacketDialog (UI type 0x4ecc, 0x380 bytes) is the GM
// packet tester: the swf collects a packet id, a loop count / delay and five typed parameters (or a random mode), and the
// per-frame slot 72 sends the queued packets.
// MS2-UNIT: ?\uidebugpacketdialog.cpp
// MS2-RANGE: 0x1400ec950-0x1400eca70 .text$di
// MS2-RANGE: 0x14128f8f0-0x1412920b0 .text$mn
// MS2-RANGE: 0x142caed60-0x142caedc6 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidebugpacketdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uidebugpacketdialog.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/commandchat.h"
class COutputStream;
void FUN_1401fa700(unsigned char* payload, COutputStream& stream);   // C3: unit_1401f9eb0_packetpayloadserializers.cpp
#include "ms2/placeholder/astextinput.h"   // C3: ASTextInput::FUN_1422e0b00
#include "ms2/ms2format.h"   // C3: StringFormat<int> (was FUN_1401ceea0)
#include "ms2/placeholder/asdropdownmenu.h"
#include "ms2/placeholder/citemmergeoptionproxy.h"
#include "ms2/commonfiles/timeutil.h"

template <> MS2Ptr<ASButton> UISwfEntity::GetChild<ASButton>(const CString& strName);   // 0x140bb4b10, owned by uiinventorydialog
template <> MS2Ptr<ASTextInput> UISwfEntity::GetChild<ASTextInput>(const CString& strName);   // 0x140e35bd0, owned by uiinventorydialog

// The header statics of this unit: the label key of the combo rows, then the game header's sort names and "skill".
static CString s_strLabel = "label";
static CString s_strSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";

// ---- unit-local views of exe types ----------------------------------------------------------------------------------

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).

MS2Ptr<ASMovieClip> FUN_1409b40c0(int nMovieId, const Scaleform::GFx::Value& rValue);
int GetRandomRange(int nRange, int nBase);                       // a random number
void FUN_140710590(COutPacket& packet);                         // send
template <class T> T Unk_StrToNum(const CStringW& str);         // text to number (unit_1406c3700)
template <> unsigned char Unk_StrToNum<unsigned char>(const CStringW& str);
unsigned short FUN_140729360(const CStringW& str);
int FUN_1401d9a00(const CStringW& str);
__int64 FUN_140d2eff0(const CStringW& str);

// ---- the dialog ---------------------------------------------------------------------------------------------------------

// @0x14128f8f0
UIDebugPacketDialog::UIDebugPacketDialog()
    : m_packet(0, 0)
{
    m_40 = 1;
    SetFlag(0, 1);
    FUN_1422dc3b0(1);
    m_nId = 0;
    m_nRemain = 0;
    m_nDelay = 0;
    m_bPacketCounter = true;
    m_bCloseFromPacket = true;
}

// @0x141291cd0 ~UIDebugPacketDialog (implicit: the exe copy stores no vptr)

// @0x14128fb80
CString UIDebugPacketDialog::GetTypeName()
{
    return "DebugPacketDialog";
}

// @0x14128fbd0
void UIDebugPacketDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    m_movie = FUN_1409b40c0(m_28, (*m_30).FUN_1422bb890());
    m_execute = GetChild<ASButton>("m_execute");
    m_id = GetChild<ASTextInput>("m_id");
    m_loopCount = GetChild<ASTextInput>("m_loopCount");
    m_loopDelay = GetChild<ASTextInput>("m_loopDelay");
    for (int i = 0; i < 5; i++)
    {
        int nNumber = i + 1;
        CStringA strParam = StringFormat<int>("m_param{0}", nNumber);
        MS2Ptr<ASMovieClip> spParam = GetChild<ASMovieClip>(strParam);
        m_type[i] = spParam.operator->()->GetDropdownMenu("m_type");
        m_value[i] = spParam->FUN_140bbe880<ASTextInput>("m_value");
        {
            ASObj row(2);
            row.FUN_1409c0dc0((const char*)s_strLabel, "None");
            m_type[i]->AddItemRow(row);
        }
        {
            ASObj row(2);
            row.FUN_1409c0dc0((const char*)s_strLabel, "1 Byte");
            m_type[i]->AddItemRow(row);
        }
        {
            ASObj row(2);
            row.FUN_1409c0dc0((const char*)s_strLabel, "2 Byte");
            m_type[i]->AddItemRow(row);
        }
        {
            ASObj row(2);
            row.FUN_1409c0dc0((const char*)s_strLabel, "4 Byte");
            m_type[i]->AddItemRow(row);
        }
        {
            ASObj row(2);
            row.FUN_1409c0dc0((const char*)s_strLabel, "8 Byte");
            m_type[i]->AddItemRow(row);
        }
        {
            ASObj row(2);
            row.FUN_1409c0dc0((const char*)s_strLabel, "String");
            m_type[i]->AddItemRow(row);
        }
        m_type[i]->SetSelectedIndex(0);
    }
    m_executeRandom = GetChild<ASButton>("m_executeRandom");
    m_randomStart = GetChild<ASTextInput>("m_randomStart");
    m_randomEnd = GetChild<ASTextInput>("m_randomEnd");
    m_randomLoopCount = GetChild<ASTextInput>("m_randomLoopCount");
    m_randomLoopDelay = GetChild<ASTextInput>("m_randomLoopDelay");
    m_randomLoopLength = GetChild<ASTextInput>("m_randomLoopLength");
    m_randomRemain = GetChild<ASTextField>("m_randomRemain");
    m_ignoreAdminPacket = GetChild<ASCheckBox>("m_ignoreAdminPacket");
    m_usePacketCount = GetChild<ASButton>("m_usePacketCount");
    m_usePostClose = GetChild<ASButton>("m_usePostClose");
    BindDragBar("m_dragBar");
    BindCloseButton("m_close");
    m_execute->AddClickHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugPacketDialog::OnExecute), 0);
    m_executeRandom->AddClickHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugPacketDialog::OnExecuteRandom), 0);
    m_usePacketCount->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugPacketDialog::OnPacketCount), (void*)0);
    m_usePostClose->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugPacketDialog::OnCloseFromPacket), (void*)0);
    m_movie->AddEventListener("doubleClick", Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugPacketDialog::OnDoubleClick), false, 0, 0, 0);
}

// @0x141290c90
void UIDebugPacketDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    for (int i = 0; i < 5; i++)
    {
        m_type[i] = 0;
        m_value[i] = 0;
    }
    m_execute = 0;
    m_executeRandom = 0;
    m_usePacketCount = 0;
    m_usePostClose = 0;
    m_movie = 0;
}

// @0x141290d80
void UIDebugPacketDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_nRemain = 0;
    m_nDelay = 0;
    m_nNext = 0;
    m_nId = 0;
    m_nRandomRemain = 0;
    m_nRandomLength = 0;
    m_nRandomDelay = 0;
    m_nRandomNext = 0;
}

// @0x141290e20
void UIDebugPacketDialog::vfunc_72()
{
    unsigned int uNow = GetTickCountMs2();
    if (m_nRemain != 0)
    {
        while (m_nRemain > 0 && uNow > m_nNext)
        {
            COutPacket packet(m_nId, 0);
            packet.AppendPayload(m_packet, 2);
            FUN_140710590(packet);
            m_nNext += m_nDelay;
            m_nRemain--;
        }
    }
    if (m_nRandomRemain != 0)
    {
        while (m_nRandomRemain > 0 && uNow > m_nRandomNext)
        {
            int nId = reinterpret_cast<Unk_DpRange&>(m_range).GetRandomValue();
            if (((ASCheckBox*)m_ignoreAdminPacket ? true : false) && (nId == 0x50 || nId == 0x24 || nId == 0x15))
            {
                // admin packets are skipped
            }
            else
            {
                COutPacket packet(nId, 0);
                int nWritten = 0;
                while (nWritten < m_nRandomLength)
                {
                    int nKind = GetRandomRange(4, 1);
                    if (nKind == 1)
                    {
                        packet.WriteUInt8(GetRandomRange(0x100, 0));
                        nWritten += 1;
                    }
                    else if (nKind == 2)
                    {
                        packet.WriteInt16(GetRandomRange(0xffff, 0));
                        nWritten += 2;
                    }
                    else if (nKind == 3)
                    {
                        packet.WriteInt32(GetRandomRange(0x7fffffff, 0));
                        nWritten += 4;
                    }
                    else if (nKind == 4)
                    {
                        __int64 n = 0;
                        n = (unsigned)GetRandomRange(0x7fffffff, 0);
                        n >>= 32;   // the exe shifts right, so the high half is always 0
                        n += (unsigned)GetRandomRange(0x7fffffff, 0);
                        packet.WriteInt64(n);
                        nWritten += 8;
                    }
                }
                FUN_140710590(packet);
            }
            m_nRandomNext += m_nRandomDelay;
            m_nRandomRemain--;
            m_randomRemain->SetTextW(StringFormat<int>(L"{0} 개 남았습니다.", m_nRandomRemain));
        }
    }
}

// @0x1412911e0
void UIDebugPacketDialog::OnExecute(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    FUN_141291470();
}

// @0x141291210
void UIDebugPacketDialog::OnExecuteRandom(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    FUN_141291850();
}

// @0x141291240
void UIDebugPacketDialog::OnPacketCount(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    COutPacket packet(static_cast<int>(SendOp::UserChat), 0);
    Unk_CommandChat chat;
    chat.kind = 0;
    chat.message = L"/PacketCounter 0";
    if (m_bPacketCounter)
        chat.message = L"/PacketCounter 1";
    chat.target = L"";
    FUN_1401fa700(reinterpret_cast<unsigned char*>(&chat), reinterpret_cast<COutputStream&>(packet));
    FUN_140710590(packet);
    if (m_bPacketCounter)
        m_bPacketCounter = false;
    else
        m_bPacketCounter = true;
}

// @0x141291340
void UIDebugPacketDialog::OnCloseFromPacket(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    COutPacket packet(static_cast<int>(SendOp::UserChat), 0);
    Unk_CommandChat chat;
    chat.kind = 0;
    chat.message = L"/CloseFromPacket 0";
    if (m_bCloseFromPacket)
        chat.message = L"/CloseFromPacket 1";
    chat.target = L"";
    FUN_1401fa700(reinterpret_cast<unsigned char*>(&chat), reinterpret_cast<COutputStream&>(packet));
    FUN_140710590(packet);
    if (m_bCloseFromPacket)
        m_bCloseFromPacket = false;
    else
        m_bCloseFromPacket = true;
}

// @0x141291440
void UIDebugPacketDialog::OnDoubleClick(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    FUN_141291470();
}

// @0x141291470
bool UIDebugPacketDialog::FUN_141291470()
{
    m_nId = FUN_1401d9a00(m_id->GetText());
    if (m_nId == 0)
        return false;
    m_nRemain = FUN_1401d9a00(m_loopCount->GetText());
    m_nDelay = FUN_1401d9a00(m_loopDelay->GetText());
    if (m_nRemain < 1)
        m_nRemain = 1;
    m_nNext = GetTickCountMs2() + m_nDelay;
    m_packet.FUN_140710740(m_nId, 0, 1);
    for (int i = 0; i < 5; i++)
    {
        int nType = m_type[i]->GetSelectedIndex();
        CStringW strValue = m_value[i]->GetText();
        if (strValue.GetLength() < 1 && nType != 5)
            break;
        if (nType == 0)
            break;
        else if (nType == 1)
            m_packet.WriteUInt8(Unk_StrToNum<unsigned char>(strValue));
        else if (nType == 2)
            m_packet.WriteInt16(FUN_140729360(strValue));
        else if (nType == 3)
            m_packet.WriteInt32(FUN_1401d9a00(strValue));
        else if (nType == 4)
            m_packet.WriteInt64(FUN_140d2eff0(strValue));
        else if (nType == 5)
            m_packet.WriteUnicodeString(strValue);
    }
    return true;
}

// @0x141291850
bool UIDebugPacketDialog::FUN_141291850()
{
    int nStart = FUN_1401d9a00(m_randomStart->GetText());
    int nEnd = FUN_1401d9a00(m_randomEnd->GetText());
    m_range.Set(nStart, nEnd);
    m_nRandomRemain = FUN_1401d9a00(m_randomLoopCount->GetText());
    m_nRandomDelay = FUN_1401d9a00(m_randomLoopDelay->GetText());
    m_nRandomLength = FUN_1401d9a00(m_randomLoopLength->GetText());
    m_nRandomNext = GetTickCountMs2() + m_nRandomDelay;
    return true;
}

// @0x141291f20
int Unk_DpRange::GetRandomValue()
{
    if (m_nMax > m_nMin)
        return rand() % (m_nMax - m_nMin + 1) + m_nMin;
    return m_nMin;
}
