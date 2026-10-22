// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TermTagContext: see ms2/placeholder/termtagcontext.h.
// MS2-UNIT: ?\termtagcontext.cpp
// MS2-RANGE: 0x1408665e0-0x140866b00 .text$mn
// MS2-PIN: ??1TermTagContext@@UEAA@XZ 0x140866a90
// MS2-PIN: ??_GTermTagContext@@UEAAPEAXI@Z 0x140866ac0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\termtagcontext.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/termtagcontext.h"
#include "gamerule.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1408665e0
TermTagContext::TermTagContext() : m_18(0), m_48(false)
{
}

// @0x140866670
int TermTagContext::FUN_140866670()
{
    return m_18;
}

// @0x140866690
CStringW TermTagContext::FUN_140866690()
{
    return m_20;
}

// @0x1408666e0
CMsTime TermTagContext::FUN_1408666e0()
{
    return m_28;
}

// @0x140866720
CMsTime TermTagContext::FUN_140866720()
{
    return m_38;
}

// @0x140866760
bool TermTagContext::FUN_140866760()
{
    return m_48;
}

// @0x140866780
void TermTagContext::FUN_140866780()
{
    CGameRule::GetInstance()->FUN_140479280(MS2Ptr<TermTagContext>(this));
}

// @0x1408667e0
void TermTagContext::FUN_1408667e0()
{
    CGameRule::GetInstance()->FUN_140479330(m_20);
}

// @0x140866820
// MS2-FUNCTIONAL: three bytes shorter in the exe (return form of the && chain not found)
int TermTagContext::FUN_140866820(const CMsTime& kTime)
{
    if (m_28 <= kTime)
    {
        if (kTime < m_38)
            return 1;
    }
    return 0;
}

// @0x140866880
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
int TermTagContext::FUN_140866880(const __time64_t* pTime)
{
    if (m_28 <= CMsTime(*pTime) && m_38 > CMsTime(*pTime))
        return 1;
    return 0;
}

// @0x140866900
void TermTagContext::FUN_140866900(CInPacket& packet)
{
    m_18 = packet.ReadInt32();
    m_20 = packet.ReadUnicodeString();
    m_28 = packet.ReadInt64();
    m_38 = packet.ReadInt64();
    m_48 = packet.ReadBool();
}
