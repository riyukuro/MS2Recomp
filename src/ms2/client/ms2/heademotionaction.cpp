// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CHeadEmotionAction: a head action that stores three ints,
// looks a PC up by object id, and releases the PC's +0xd88 intrusive pointer. Also holds the unit's unreferenced CRT
// memcpy_s/memmove_s copies.
// MS2-UNIT: ?\heademotionaction.cpp
// MS2-RANGE: 0x1413f9290-0x1413f9810 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\heademotionaction.cpp"
// The exe's memcpy_s/memset calls are plain calls (no /Oi expansion); the pragma must precede the inline definition.
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/heademotionaction.h"
#include <errno.h>
#include <string.h>
#include "ms2/ms2recover.h"
#include "ms2/placeholder/fittingdollpc.h"

// The +0xd88 target of a PC (CPtred-derived; see clonepc.cpp).
class Unk_PCD88 : public CPtred {};

// The PC methods used here (their units define the real classes).

// The entity manager (singleton FUN_1403ed2d0): finds a PC by object id.
class Unk_EntityMgr
{
public:
    PC* FUN_141bd1290(int nId);                 // 0x141bd1290
};
Unk_EntityMgr* FUN_1403ed2d0();                 // 0x1403ed2d0
void FUN_140a34f00(Unk_PCD88* pPCD88);          // 0x140a34f00

#include "ms2/placeholder/ms2ptr_impl.h"

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
#pragma function(memcpy, memset)
// @0x1413f95a0
static __inline errno_t ms2_head_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnHeadMemcpyS)(void*, size_t, const void*, size_t) = &ms2_head_memcpy_s;
#pragma intrinsic(memcpy, memset)

// @0x1413f96f0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);

// @0x1413f9290
CHeadEmotionAction::CHeadEmotionAction(MS2Ptr<Unk_PCD88> spD88) : m_spD88(spD88)
{
}

// @0x1413f9300
CHeadEmotionAction::~CHeadEmotionAction()
{
}

// @0x1413f9340
bool CHeadEmotionAction::vfunc_1(int nA, int nB, int nC)
{
    m_n18 = nA;
    m_n1c = nB;
    m_n20 = nC;
    if (vfunc_4())
        return false;
    return true;
}

// @0x1413f93b0
void CHeadEmotionAction::vfunc_2()
{
}

// @0x1413f93c0
bool CHeadEmotionAction::vfunc_3()
{
    return false;
}

// @0x1413f93d0
bool CHeadEmotionAction::vfunc_4()
{
    return false;
}

// @0x1413f93e0
bool CHeadEmotionAction::vfunc_5()
{
    return false;
}

// @0x1413f93f0
void CHeadEmotionAction::vfunc_6(double f)
{
    if (vfunc_4())
    {
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(m_n18);
        if (pPC != 0)
            FUN_140a34f00(pPC->FUN_14165c2d0().operator->());
    }
}
