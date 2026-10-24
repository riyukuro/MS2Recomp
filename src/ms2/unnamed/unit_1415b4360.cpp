// MS2-UNIT: unit_1415b4360
// MS2-RANGE: 0x1415b4360-0x1415b49d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern unsigned int FUN_1415f9990(void*);
extern void FUN_1415fbe70(void*, unsigned int, const char*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b4360: initializes the default invite-virtual-user event values.
// @0x1415b4360
CNMInviteVirtualUserEvent::CNMInviteVirtualUserEvent()
    : CNMEvent(0x100b, 1, 0, 0), m_28(0), m_30(0), m_34(2), m_38(0), m_3c(0), m_40(0),
      m_44(0), m_48{}, m_88{}, m_c8{}, m_1c8(0) {}

// MS2-FUNCTIONAL 0x1415b4450: initializes invite metadata and copies optional user strings.
// @0x1415b4450
CNMInviteVirtualUserEvent::CNMInviteVirtualUserEvent(long long n28, int n30, int n34, long long n38,
                                                       long long n40, const char* text48,
                                                       const char* text88)
    : CNMEvent(0x100b, 1, 0, 0), m_28(n28), m_30(n30), m_34(n34), m_38(static_cast<int>(n38)),
      m_3c(static_cast<int>(static_cast<unsigned long long>(n38) >> 32)), m_40(static_cast<int>(n40)),
      m_44(static_cast<int>(static_cast<unsigned long long>(n40) >> 32)), m_48{}, m_88{}, m_c8{}, m_1c8(0)
{
    if (text48)
        FUN_1415fbe70(m_48, sizeof(m_48), text48);
    if (text88)
        FUN_1415fbe70(m_88, sizeof(m_88), text88);
}

// MS2-FUNCTIONAL 0x1415b45a0: frames event encoding.
// @0x1415b45a0
unsigned int CNMInviteVirtualUserEvent::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    auto result = Encode(reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b4600: dispatches encoding by event format.
// @0x1415b4600
unsigned int CNMInviteVirtualUserEvent::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    return m_bFormat == 1 ? Encode(encoder, stream) : EncodeFramed(stream);
}

// MS2-FUNCTIONAL 0x1415b4660: serializes invite identifiers, flags, and user strings.
// @0x1415b4660
unsigned int CNMInviteVirtualUserEvent::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMEvent::EncodeDispatch(encoder, stream);
    FUN_14156acb0(encoder, static_cast<unsigned long long>(m_28));
    FUN_14156ac20(encoder, static_cast<unsigned int>(m_30));
    FUN_14156ac20(encoder, static_cast<unsigned int>(m_34));
    FUN_14156ac20(encoder, static_cast<unsigned int>(m_38));
    FUN_14156ac20(encoder, static_cast<unsigned int>(m_3c));
    FUN_14156ac20(encoder, static_cast<unsigned int>(m_40));
    FUN_14156ac20(encoder, static_cast<unsigned int>(m_44));
    FUN_14156ae30(encoder, m_48);
    FUN_14156ae30(encoder, m_88);
    FUN_14156ae30(encoder, m_c8);
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b4770: decodes a framed event.
// @0x1415b4770
unsigned int CNMInviteVirtualUserEvent::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b4800: dispatches decoding by event format.
// @0x1415b4800
unsigned int CNMInviteVirtualUserEvent::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    return FUN_1415fb6d0(decoder) == 2 ? DecodeFramed(stream) : Decode(decoder, stream);
}

// MS2-FUNCTIONAL 0x1415b4860: restores invite identifiers, flags, and user strings.
// @0x1415b4860
unsigned int CNMInviteVirtualUserEvent::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMEvent::DecodeDispatch(decoder, stream);
    void** vtable = *reinterpret_cast<void***>(decoder);
    using Read64 = unsigned long long(__fastcall*)(void*);
    using Read32 = unsigned int(__fastcall*)(void*);
    using ReadString = void(__fastcall*)(void*, void*, unsigned int);
    m_28 = static_cast<long long>(reinterpret_cast<Read64>(vtable[4])(decoder));
    m_30 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(decoder));
    m_34 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(decoder));
    m_38 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(decoder));
    m_3c = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(decoder));
    m_40 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(decoder));
    m_44 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(decoder));
    reinterpret_cast<ReadString>(vtable[9])(decoder, m_48, sizeof(m_48));
    reinterpret_cast<ReadString>(vtable[9])(decoder, m_88, sizeof(m_88));
    reinterpret_cast<ReadString>(vtable[9])(decoder, m_c8, 0x100);
    return FUN_1415fb750(decoder);
}

// MS2-PIN: ??0CNMInviteVirtualUserEvent@@QEAA@XZ 0x1415b4360 ; constructor body for an empty invite event
// MS2-PIN: ??0CNMInviteVirtualUserEvent@@QEAA@_JHH00PEBD1@Z 0x1415b4450 ; constructor with invite metadata
