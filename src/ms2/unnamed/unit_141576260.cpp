// Nexon Messenger session member list encoding methods.
// MS2-UNIT: unit_141576260
// MS2-RANGE: 0x141576260-0x141576ae0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);

// MS2-FUNCTIONAL 0x141576780: uses opaque stack storage for the temporary encoder; list encoding behavior is preserved.
// @0x141576780
unsigned int CNMSessionMemberList::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMSessionMemberList*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x1415767e0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415767e0
unsigned int CNMSessionMemberList::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMSessionMemberList*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMSessionMemberList*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x141576840: serializes the count and each member in order; the range loop differs from the original iterator helper calls.
// @0x141576840
unsigned int CNMSessionMemberList::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10.size()));
    for (CNMSessionMemberInfo& member : m_10)
        member.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}
