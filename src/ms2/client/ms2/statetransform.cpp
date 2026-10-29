// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateTransform / StateTransformDoll, the actor states of a
// player being fitted: both start the "Eff_FittingDoll" effect and play the mantle change animation. See statetransform.h.
// MS2-UNIT: ?\statetransform.cpp
// MS2-RANGE: 0x1417fe410-0x1417fea70 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statetransform.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <efd/utf8string.h>

#include "statetransform.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

void FUN_1409989e0(void* pOut, const char* psz);           // 0x1409989e0 efd::utf8string(const char*)
void FUN_1408a8900(void* pStr);                            // 0x1408a8900 ~efd::utf8string
void* FUN_1403ed280();                                     // effect manager
void* FUN_1403ed2d0();                                     // player manager
int FUN_141bd1a10(void* pPlayer, GameObject* pObject);
int FUN_1411a49c0(void* pEffectMgr, Unk_EffectQuery* pQuery);
void FUN_1411a6060(void* pEffectMgr, int nId);
unsigned FUN_140869420();                                  // millisecond clock
int FUN_14028d260(float fSeconds);                         // seconds -> milliseconds

// The efd::utf8string the exe builds out of line (ctor 0x1409989e0, dtor 0x1408a8900; 0x20 bytes).
struct Unk_TfString
{
    Unk_TfString(const char* psz) { FUN_1409989e0(m_buf, psz); }
    ~Unk_TfString() { FUN_1408a8900(m_buf); }
    operator const efd::utf8string&() const { return *(const efd::utf8string*)m_buf; }
    char m_buf[0x20];
};

// ---- StateTransform ----

// @0x1417fe410
StateTransform::StateTransform(PCBase* pOwner) : State(pOwner)
{
    m_nEffect = 0;
}

// @0x1417fe460
StateTransform::~StateTransform()
{
    if (m_nEffect != 0)
    {
        FUN_1411a6060(FUN_1403ed280(), m_nEffect);
        m_nEffect = 0;
    }
}

// @0x1417fe4d0
void StateTransform::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    const char* pszEffect = "CH/Common/Eff_FittingDoll.xml";
    Unk_EffectQuery query;
    query.m_strName = pszEffect;
    query.m_nObject = FUN_141bd1a10(FUN_1403ed2d0(), m_pOwner);
    query.SetActor(m_pOwner->FUN_14123c580());
    m_nEffect = FUN_1411a49c0(FUN_1403ed280(), &query);
    m_pOwner->FUN_14166dd20("Equip_Change_Mantle_A", 1.0f, false, false);
}

// @0x1417fe610
void StateTransform::vfunc_5(int n)
{
    State::vfunc_5(n);
}

// @0x1417fe640
void StateTransform::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
}

// @0x1417fe670
void StateTransform::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    State::EndOfSequence(pkManager, eSequenceID, pkSeq, fEventTime);
    FUN_1411a6060(FUN_1403ed280(), m_nEffect);
    m_nEffect = 0;
    m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417fea50
int StateTransform::vfunc_1()
{
    return 0x22;
}

// ---- StateTransformDoll ----

// @0x1417fe710
StateTransformDoll::StateTransformDoll(PCBase* pOwner) : State(pOwner)
{
    m_nEffect = 0;
    m_nEndTime = 0;
}

// @0x1417fe770
StateTransformDoll::~StateTransformDoll()
{
    if (m_nEffect != 0)
    {
        FUN_1411a6060(FUN_1403ed280(), m_nEffect);
        m_nEffect = 0;
    }
}

// @0x1417fe7e0
void StateTransformDoll::vfunc_4(StateData* pData)
{
    const char* pszEffect = "CH/Common/Eff_FittingDoll.xml";
    int nNow = FUN_140869420();
    m_nEndTime = nNow + FUN_14028d260(1.0f);
    Unk_EffectQuery query;
    query.m_strName = pszEffect;
    query.m_nObject = FUN_141bd1a10(FUN_1403ed2d0(), m_pOwner);
    query.SetActor(m_pOwner->FUN_14123c580());
    m_nEffect = FUN_1411a49c0(FUN_1403ed280(), &query);
    m_pOwner->FUN_14166dd20("Equip_Change_Mantle_A", 1.0f, false, false);
}

// @0x1417fe930
void StateTransformDoll::vfunc_5(int n)
{
    FUN_1411a6060(FUN_1403ed280(), m_nEffect);
    m_nEffect = 0;
}

// @0x1417fe970
void StateTransformDoll::vfunc_3(double fTime)
{
    if (FUN_140869420() >= m_nEndTime)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417fea60
int StateTransformDoll::vfunc_1()
{
    return 0x22;
}
