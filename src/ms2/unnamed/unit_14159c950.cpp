// Recovered from the Nexon Messenger client library: chat-room callback registration request.
// MS2-UNIT: unit_14159c950
// MS2-RANGE: 0x14159c950-0x14159ccd0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmchatroomfunc.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: callback fields and default values match; base constructor argument register width differs.
// @0x14159c950
CNMCRRegisterCallbackFunc::CNMCRRegisterCallbackFunc()
    : CNMFunc(0xb001, 1, 0, 0), m_hWnd(nullptr), m_uMsg(0), m_3c(0)
{
}

// @0x14159c9b0
CNMCRRegisterCallbackFunc::CNMCRRegisterCallbackFunc(unsigned uSerialKey, HWND hWnd, unsigned uMsg)
    : CNMFunc(0xb001, 1, static_cast<int>(uSerialKey), 0), m_hWnd(hWnd), m_uMsg(uMsg), m_3c(0)
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x14159ca20
unsigned int CNMCRRegisterCallbackFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159ca80
unsigned int CNMCRRegisterCallbackFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: callback handle and message payload order recovered; direct dispatch replaces virtual calls.
// @0x14159cae0
unsigned int CNMCRRegisterCallbackFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(reinterpret_cast<std::uintptr_t>(m_hWnd)));
        FUN_14156ac20(pEncoder, m_uMsg);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159cb60
unsigned int CNMCRRegisterCallbackFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159cbf0
unsigned int CNMCRRegisterCallbackFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: both request fields and final validity check recovered; direct dispatch replaces virtual calls.
// @0x14159cc50
unsigned int CNMCRRegisterCallbackFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        using ReadU32 = unsigned int(__fastcall*)(void*);
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        m_hWnd = reinterpret_cast<HWND>(static_cast<std::uintptr_t>(ReadU32(vftable[3])(pDecoder)));
        m_uMsg = ReadU32(vftable[3])(pDecoder);
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRRegisterCallbackFunc@@QEAA@XZ 0x14159c950
