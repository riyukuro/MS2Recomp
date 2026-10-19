// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameEventDTReward (daily attendance reward event) and the
// DTRewardEventContext it fills, plus the smart-pointer / CAtlArray glue over the reward rows.
// MS2-UNIT: ?\gameeventdtreward.cpp
// MS2-RANGE: 0x14041b140-0x14041c1a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventdtreward.cpp"

#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameeventdtreward.h"
#include "ms2/commonfiles/usereventcontext.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cusereventmanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

using namespace CommonUserEvent;

#ifdef __clang__
#define MS2_GE_R(in) (reinterpret_cast<Unk_GEReader*>(reinterpret_cast<char*>(in) + 8))
#else
#define MS2_GE_R(in) (&(in)->reader)
#endif

// Out-of-unit helpers.
void FUN_14025a680(const CStringW& text, ATL::CAtlArray<CStringW>& tokens, const wchar_t* pszDelims);   // split
void FUN_140274fc0(const CStringW& text, ATL::CAtlArray<unsigned int>* pOut, const wchar_t* pszSep);    // split ids
bool FUN_1407183f0(const CStringW& value);
unsigned short FUN_1407181a0(const CStringW& value);
// The DTReward rows hang off the context through Unk_EventRewardList (usereventcontext.cpp).
void FUN_1408d5c30(DTRewardEventContext* pContext, const ATL::CAtlArray<unsigned int>& fields);
// CUserEventManager::AddDTReward: the context handle is passed as the exe's own handle type.
void FUN_1408d7cd0(CUserEventManager* pManager, Unk_DTCtxArg<DTRewardEventContext> spContext);

// ---- GameEventDTReward -----------------------------------------------------------------------------------------------

// @0x14041b140
GameEvent* FUN_14041b140() { return new GameEventDTReward; }

// @0x14041b1a0
CStringW GameEventDTReward::vfunc_1() { return CStringW(L"GameEventDTReward"); }
MS2_REPLACE_METHOD(0x14041B1A0, GameEventDTReward, vfunc_1, 61, 0xD464C57C);

// @0x14041b1f0
GameEventDTReward::GameEventDTReward() : m_bShown(false)
{
    FUN_1402e3480(1);
}

// @0x14041b280
void GameEventDTReward::vfunc_2()
{
    m_spContext = 0;
    FUN_14041b6e0(m_68, m_70, m_78, m_80);
}

// @0x14041b300
void GameEventDTReward::vfunc_5()
{
    if (m_spContext.get() != 0)
        FUN_1408d7cd0(TSingleton<CUserEventManager>::GetInstance(), m_spContext);
}

// @0x14041b380
void GameEventDTReward::vfunc_6()
{
    TSingleton<CUserEventManager>::GetInstance()->RemoveDTReward(FUN_1402e1d00());
}

// @0x14041b3c0
void GameEventDTReward::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_68);
    out->WriteStringW(m_70);
    out->WriteStringW(m_78);
    out->WriteStringW(m_80);
}
MS2_REPLACE_METHOD(0x14041B3C0, GameEventDTReward, vfunc_3, 188, 0x572EB6DF);

// @0x14041b490
void GameEventDTReward::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_68 = MS2_GE_R(in)->ReadStringW();
    m_70 = MS2_GE_R(in)->ReadStringW();
    m_78 = MS2_GE_R(in)->ReadStringW();
    m_80 = MS2_GE_R(in)->ReadStringW();
    FUN_14041b6e0(m_68, m_70, m_78, m_80);
}

// @0x14041b6e0
void GameEventDTReward::FUN_14041b6e0(const CStringW& rewards, const CStringW& levels, const CStringW& flags, const CStringW& last)
{
    ATL::CAtlArray<CStringW> rows;
    FUN_14025a680(rewards, rows, L";");
    if (rows.IsEmpty())
        return;
    m_spContext.AssignRaw(new DTRewardEventContext(FUN_1402e1d00(), FUN_1402e2730()));
    for (unsigned i = 0; i < rows.GetCount(); i++) {
        ATL::CAtlArray<unsigned int> fields;
        FUN_140274fc0(rows[i], &fields, L",");
        if (fields.IsEmpty() || fields.GetCount() != 9)
            continue;
        FUN_1408d5c30(m_spContext.operator->(), fields);
    }
    ATL::CAtlArray<CStringW> parts;
    FUN_14025a680(levels, parts, L",");
    if (parts.GetCount() >= 1)
        m_bShown = FUN_1407183f0(parts[0]);
    if (parts.GetCount() >= 2) {
        unsigned short level = FUN_1407181a0(parts[1]);
        m_spContext->m_level = level;
    }
    parts.RemoveAll();
    FUN_14025a680(flags, parts, L",");
    if (parts.GetCount() >= 1)
        m_spContext->m_b32 = FUN_1407183f0(parts[0]);
    m_spContext->m_b33 = FUN_1407183f0(last);
    if (!m_bShown)
        FUN_1402e3480(3);
}

// ---- DTRewardEventContext --------------------------------------------------------------------------------------------

// @0x14041bb00
CommonUserEvent::DTRewardEventContext::DTRewardEventContext(int id, const CMsTime& time)
    : m_id(id), m_time(time), m_level(0), m_b32(0), m_b33(0)
{
}
