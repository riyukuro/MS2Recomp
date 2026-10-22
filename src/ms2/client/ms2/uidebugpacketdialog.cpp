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

// The header statics of this unit: the label key of the combo rows, then the game header's sort names and "skill".
static CString s_strLabel = "label";
static CString s_strSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";

// ---- unit-local views of exe types ----------------------------------------------------------------------------------

class Unk_DpControl : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
};
class Unk_DpButton : public Unk_DpControl
{
public:
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& callback, int nFlags);   // click
    void FUN_1422c2a70(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& callback, int nFlags);   // toggle
};
class Unk_DpInput : public Unk_DpControl { public: CStringW FUN_1422e0b00(); };         // the text
class Unk_DpCheck : public Unk_DpControl { };
class Unk_DpCombo : public Unk_DpControl
{
public:
    void FUN_1422dfc70(ASObj& item);                            // add a row
    void FUN_1422df690(int nRow);                               // select a row
    int FUN_1422df6c0();                                        // selected row
};
// The "m_param<n>" movie clip: the child lookups by name.
class Unk_DpParam
{
public:
    MS2Ptr<Unk_DpCombo> FUN_140bbe700(const CString& strName);
    MS2Ptr<Unk_DpInput> FUN_140bbe880(const CString& strName);
};
class Unk_DpMovie { public: void FUN_1422c3600(const CString& strEvent, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& callback,
                                               int a3, int a4, int a5, void* a6); };
// Unk_CommandChat: placeholder/commandchat.h (the chat command record).

MS2Ptr<ASMovieClip> FUN_1409b40c0(int nMovieId, const Scaleform::GFx::Value& rValue);
CStringA FUN_1402bb1c0(const char* pszFormat, const int& n);
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& n);
unsigned FUN_140869420();                                       // the server time
int FUN_140768010(int nRange, int nBase);                       // a random number
void FUN_140710590(COutPacket& packet);                         // send
unsigned char FUN_1406c3b20(const CStringW& str);               // text to number
short FUN_140729360(const CStringW& str);
int FUN_1401d9a00(const CStringW& str);
__int64 FUN_140d2eff0(const CStringW& str);

// ---- the dialog ---------------------------------------------------------------------------------------------------------

// @0x14128f8f0
UIDebugPacketDialog::UIDebugPacketDialog()
    : m_packet(0, 0)
{
    m_40 = 1;
    FUN_141925e70(0, 1);
    FUN_1422dc3b0(1);
    m_nId = 0;
    m_nRemain = 0;
    m_nDelay = 0;
    m_bPacketCounter = true;
    m_bCloseFromPacket = true;
}

// @0x141291cd0
UIDebugPacketDialog::~UIDebugPacketDialog()
{
}

// @0x14128fb80
CString UIDebugPacketDialog::GetTypeName()
{
    return "DebugPacketDialog";
}

// @0x14128fbd0
// MS2-FUNCTIONAL: control flow follows the exe; the string temporaries and the combo row objects are named differently.
void UIDebugPacketDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    m_movie = FUN_1409b40c0(m_28, (*m_30).FUN_1422bb890());
    m_execute = FUN_140bb4b10("m_execute");
    m_id = FUN_140e35bd0("m_id");
    m_loopCount = FUN_140e35bd0("m_loopCount");
    m_loopDelay = FUN_140e35bd0("m_loopDelay");
    for (int i = 0; i < 5; i++)
    {
        int nNumber = i + 1;
        MS2Ptr<ASMovieClip> spParam = FUN_140ba7930(FUN_1402bb1c0("m_param{0}", nNumber));
        Unk_DpParam* pParam = reinterpret_cast<Unk_DpParam*>(spParam.operator->());
        m_type[i] = pParam->FUN_140bbe700("m_type");
        m_value[i] = pParam->FUN_140bbe880("m_value");
        static const char* const aszTypes[] = {"None", "1 Byte", "2 Byte", "4 Byte", "8 Byte", "String"};
        for (int j = 0; j < 6; j++)
        {
            ASObj row(2);
            row.FUN_1409c0dc0((const char*)s_strLabel, aszTypes[j]);
            m_type[i]->FUN_1422dfc70(row);
        }
        m_type[i]->FUN_1422df690(0);
    }
    m_executeRandom = FUN_140bb4b10("m_executeRandom");
    m_randomStart = FUN_140e35bd0("m_randomStart");
    m_randomEnd = FUN_140e35bd0("m_randomEnd");
    m_randomLoopCount = FUN_140e35bd0("m_randomLoopCount");
    m_randomLoopDelay = FUN_140e35bd0("m_randomLoopDelay");
    m_randomLoopLength = FUN_140e35bd0("m_randomLoopLength");
    m_randomRemain = FUN_140bb4cf0("m_randomRemain");
    m_ignoreAdminPacket = FUN_140e52670("m_ignoreAdminPacket");
    m_usePacketCount = FUN_140bb4b10("m_usePacketCount");
    m_usePostClose = FUN_140bb4b10("m_usePostClose");
    FUN_141925fa0("m_dragBar");
    FUN_141925ec0("m_close");
    m_execute->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugPacketDialog::OnExecute), 0);
    m_executeRandom->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugPacketDialog::OnExecuteRandom), 0);
    m_usePacketCount->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugPacketDialog::OnPacketCount), 0);
    m_usePostClose->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugPacketDialog::OnCloseFromPacket), 0);
    reinterpret_cast<Unk_DpMovie*>(m_movie.operator->())->FUN_1422c3600("doubleClick", Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDebugPacketDialog::OnDoubleClick), 0, 0, 0, 0);
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
// MS2-FUNCTIONAL: control flow follows the exe; the loop locals sit in different stack slots.
void UIDebugPacketDialog::vfunc_72()
{
    unsigned int uNow = FUN_140869420();
    if (m_nRemain != 0)
    {
        while (m_nRemain > 0 && m_nNext < uNow)
        {
            COutPacket packet(m_nId, 0);
            packet.FUN_14020aa30(m_packet, 2);
            FUN_140710590(packet);
            m_nNext += m_nDelay;
            m_nRemain--;
        }
    }
    if (m_nRandomRemain != 0)
    {
        while (m_nRandomRemain > 0 && m_nRandomNext < uNow)
        {
            int nId = m_range.FUN_141291f20();
            if ((Unk_DpCheck*)m_ignoreAdminPacket == 0 || (nId != 0x50 && nId != 0x24 && nId != 0x15))
            {
                COutPacket packet(nId, 0);
                int nWritten = 0;
                while (nWritten < m_nRandomLength)
                {
                    int nKind = FUN_140768010(4, 1);
                    if (nKind == 1)
                    {
                        unsigned char n = FUN_140768010(0x100, 0);
                        packet.WriteUInt8(n);
                        nWritten += 1;
                    }
                    else if (nKind == 2)
                    {
                        short n = FUN_140768010(0xffff, 0);
                        packet.WriteInt16(n);
                        nWritten += 2;
                    }
                    else if (nKind == 3)
                    {
                        int n = FUN_140768010(0x7fffffff, 0);
                        packet.WriteInt32(n);
                        nWritten += 4;
                    }
                    else if (nKind == 4)
                    {
                        FUN_140768010(0x7fffffff, 0);
                        int n = FUN_140768010(0x7fffffff, 0);
                        packet.WriteInt64(n);
                        nWritten += 8;
                    }
                }
                FUN_140710590(packet);
            }
            m_nRandomNext += m_nRandomDelay;
            m_nRandomRemain--;
            m_randomRemain->FUN_1422c4cd0(FUN_1401ceea0(L"{0} 개 남았습니다.", m_nRandomRemain));
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
    chat.FUN_1401fa700(packet);
    FUN_140710590(packet);
    if (!m_bPacketCounter)
        m_bPacketCounter = true;
    else
        m_bPacketCounter = false;
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
    chat.FUN_1401fa700(packet);
    FUN_140710590(packet);
    if (!m_bCloseFromPacket)
        m_bCloseFromPacket = true;
    else
        m_bCloseFromPacket = false;
}

// @0x141291440
void UIDebugPacketDialog::OnDoubleClick(const Scaleform::GFx::FunctionHandler::Params& rParams)
{
    FUN_141291470();
}

// @0x141291470
// MS2-FUNCTIONAL: control flow follows the exe; the parsed values pass through extra locals.
int UIDebugPacketDialog::FUN_141291470()
{
    m_nId = FUN_1401d9a00(m_id->FUN_1422e0b00());
    if (m_nId == 0)
        return 0;
    m_nRemain = FUN_1401d9a00(m_loopCount->FUN_1422e0b00());
    m_nDelay = FUN_1401d9a00(m_loopDelay->FUN_1422e0b00());
    if (m_nRemain < 1)
        m_nRemain = 1;
    m_nNext = FUN_140869420() + m_nDelay;
    m_packet.FUN_140710740(m_nId, 0, 1);
    for (int i = 0; i < 5; i++)
    {
        int nType = m_type[i]->FUN_1422df6c0();
        CStringW strValue = m_value[i]->FUN_1422e0b00();
        if (strValue.GetLength() < 1 && nType != 5)
            break;
        if (nType == 0)
            break;
        if (nType == 1)
            m_packet.WriteUInt8(FUN_1406c3b20(strValue));
        else if (nType == 2)
            m_packet.WriteInt16(FUN_140729360(strValue));
        else if (nType == 3)
            m_packet.WriteInt32(FUN_1401d9a00(strValue));
        else if (nType == 4)
            m_packet.WriteInt64(FUN_140d2eff0(strValue));
        else if (nType == 5)
            m_packet.WriteUnicodeString(strValue);
    }
    return 1;
}

// @0x141291850
bool UIDebugPacketDialog::FUN_141291850()
{
    int nStart = FUN_1401d9a00(m_randomStart->FUN_1422e0b00());
    int nEnd = FUN_1401d9a00(m_randomEnd->FUN_1422e0b00());
    m_range.FUN_1405c6380(nStart, nEnd);
    m_nRandomRemain = FUN_1401d9a00(m_randomLoopCount->FUN_1422e0b00());
    m_nRandomDelay = FUN_1401d9a00(m_randomLoopDelay->FUN_1422e0b00());
    m_nRandomLength = FUN_1401d9a00(m_randomLoopLength->FUN_1422e0b00());
    m_nRandomNext = FUN_140869420() + m_nRandomDelay;
    return true;
}

// @0x141291f20
int Unk_DpRange::FUN_141291f20()
{
    if (m_nMin < m_nMax)
        return rand() % (m_nMax - m_nMin + 1) + m_nMin;
    return m_nMin;
}
