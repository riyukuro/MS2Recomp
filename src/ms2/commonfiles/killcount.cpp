// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CKillCount: the kill-combo counter (UIKillCount owns one).
// The count and the tick of the last kill live in the object; the combo's grade, bonus exp rate and message text come
// from the LUA functions calcKillCount / calcKillCountGrade / calcKillCountBonusExpRate / calcKillCountMsg.
// MS2-UNIT: ?\killcount.cpp
// MS2-RANGE: 0x14064c590-0x14064ca50 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\killcount.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/ckillcount.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/luautil.h"

// ---- unit-local placeholders (unrecovered helpers; promote to src/ms2/placeholder/ when shared) ----

class Unk_LuaState : public CLua                                                      // the LUA state the kill helpers run in
{
};

unsigned int FUN_140869420();                                           // the client millisecond clock
Unk_LuaState* FUN_1401c0db0();                                          // the LUA state global (DAT_143aac4c8)
double FUN_140675920(Unk_LuaState* pLua, int nCount);                   // lua calcKillCountBonusExpRate(count)
unsigned int FUN_140675ab0(Unk_LuaState* pLua, int nCount);             // lua calcKillCountGrade(count)
unsigned int FUN_140675e00(Unk_LuaState* pLua, unsigned short a1, unsigned short a2, int nDelta, int nCount);
                                                                        // lua calcKillCount(a1, a2, nDelta, nCount)
CStringW FUN_14016a730(const char* psz, int nCodePage);                 // the CStringA -> CStringW conversion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14064c590
CKillCount::CKillCount()
{
    m_08 = 0;
    m_0c = 0;
}

// @0x14064c5d0
CKillCount::~CKillCount()
{
}

// @0x14064c5f0
int CKillCount::FUN_14064c5f0(unsigned short a1, unsigned short a2)
{
    int nShow = 0;
    int nNow = FUN_140869420();
    int nOld = m_08;
    if (m_08 == 0) {
        m_08 = m_08 + 1;
    } else {
        int nLast;
        if (m_0c == 0)
            nLast = nNow;
        else
            nLast = m_0c;
        m_0c = nLast;
        m_08 = FUN_14064c8a0(a1, a2, nNow - m_0c);
    }
    if (m_08 == 1 || m_08 != nOld) {
        nShow = 1;
        m_0c = nNow;
    }
    return nShow;
}

// @0x14064c6e0
double CKillCount::FUN_14064c6e0()
{
    return FUN_140675920(FUN_1401c0db0(), m_08);
}

// @0x14064c710
unsigned int CKillCount::FUN_14064c710()
{
    return FUN_140675ab0(FUN_1401c0db0(), m_08);
}

// @0x14064c740
CStringW CKillCount::FUN_14064c740()
{
    return FUN_14016a730(FUN_1401c0db0()->CalcKillCountMsg(m_08), 0);
}

// @0x14064c7d0
void CKillCount::FUN_14064c7d0()
{
    m_08 = 0;
    m_0c = 0;
}

// @0x14064c800
int CKillCount::FUN_14064c800()
{
    return m_08;
}

// @0x14064c820
int CKillCount::FUN_14064c820()
{
    return m_0c;
}

// @0x14064c840
int CKillCount::FUN_14064c840(int nTick)
{
    if (FUN_140675e00(FUN_1401c0db0(), 0, 0, nTick - m_0c, 1) > 1)
        return true;
    return false;
}

// @0x14064c8a0
unsigned int CKillCount::FUN_14064c8a0(unsigned short a1, unsigned short a2, int nDelta)
{
    return FUN_140675e00(FUN_1401c0db0(), a1, a2, nDelta, m_08);
}

// @0x14064c930
MS2_EMIT_CRT_MEMMOVE_S_COPY(3);
