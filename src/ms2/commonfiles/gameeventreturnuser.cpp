// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameEventReturnUser and the ctor / dtor of its
// MentoringContext (the registration of the factory is in gameeventlobbymap.cpp).
// MS2-UNIT: ?\gameeventreturnuser.cpp
// MS2-RANGE: 0x14041cb50-0x14041d470 .text$mn
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_RuAux@@@@CAXPEAVUnk_RuAux@@@Z 0x14041d1b0 ; merge-bind
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventreturnuser.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gameeventreturnuser.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#define MS2_GE_OUT(out) (*reinterpret_cast<COutputStream*>(out))

// An unrecovered refcounted type (the +0xd0 member).
class Unk_RuAux : public CPtred { };

// Out-of-unit helpers.
// The mentoring slot of the event manager (+0x448; the accessor FUN_14041d160 is in this unit).
class Unk_RuMentoring
{
public:
    void FUN_140424da0(MS2Ptr<MentoringContext> spContext);     // start
    void FUN_140424ea0();                                       // end
};
class Unk_RuManager
{
public:
    // @0x14041d160
    Unk_RuMentoring* GetMentoring() { return &m_448; }
private:
    char m_pad[0x448];
    Unk_RuMentoring m_448;
};
Unk_RuManager* FUN_140302b00();

// @0x14041cb50
GameEvent* FUN_14041cb50() { return new GameEventReturnUser; }

// @0x14041cbb0
CStringW GameEventReturnUser::vfunc_1() { return CStringW(L"GameEventReturnUser"); }

// @0x14041cc00
GameEventReturnUser::GameEventReturnUser()
{
    FUN_1402e3480(2);
    FUN_1402e3480(1);
    FUN_1402e3480(3);
    m_e0.AssignRaw(new MentoringContext);
}

// @0x14041ccf0
void GameEventReturnUser::vfunc_2() {}

// @0x14041cd00
void GameEventReturnUser::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    m_e0->Write(MS2_GE_OUT(out));
}

// @0x14041cd50
void GameEventReturnUser::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_e0->Read(*reinterpret_cast<CInPacket*>(in));
}

// @0x14041cda0
void GameEventReturnUser::OnStart()
{
    if (0 < m_e0->m_18)
        FUN_140302b00()->GetMentoring()->FUN_140424da0(m_e0);
}

// @0x14041ce30
void GameEventReturnUser::vfunc_6()
{
    if (0 < m_e0->m_18)
        FUN_140302b00()->GetMentoring()->FUN_140424ea0();
}

// @0x14041cf20
MentoringContext::MentoringContext() : m_18(0), m_20(0), m_28(0)
{
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE_METHOD(0x14041CBB0, GameEventReturnUser, vfunc_1, 61, 0xE36CC2D1);
MS2_REPLACE_METHOD(0x14041CD00, GameEventReturnUser, vfunc_3, 66, 0x10EC5821);
MS2_REPLACE_METHOD(0x14041CD50, GameEventReturnUser, vfunc_4, 66, 0xBAB6C5C6);
MS2_REPLACE_METHOD(0x14041CDA0, GameEventReturnUser, OnStart, 124, 0x2CA4961C);
MS2_REPLACE_METHOD(0x14041CE30, GameEventReturnUser, vfunc_6, 60, 0xC3839913);
