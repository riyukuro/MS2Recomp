// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateSwim, the actor state of a player swimming: picks the
// swim speed (own or the ridee's), steers in the move direction, plays the swim animation and a looping effect.
// See stateswim.h.
// MS2-UNIT: ?\stateswim.cpp
// MS2-RANGE: 0x1417fa370-0x1417fb5c0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateswim.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <efd/utf8string.h>

#include "stateswim.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

void FUN_1408a8700(void* pStr);                            // 0x1408a8700 efd::utf8string()
void FUN_1408a8900(void* pStr);                            // 0x1408a8900 ~efd::utf8string
void FUN_140ae18f0(void* pStr, const char* psz);           // 0x140ae18f0 efd::utf8string::operator=(const char*)
bool FUN_14096ad40(const efd::utf8string& str);            // 0x14096ad40 the string is empty
void FUN_14165e2a0(PCBase* p, void* pStr, int nKey);       // 0x14165e2a0 the player's animation name of a key
CString FUN_14165e010(PCBase* p, int nKey);                // 0x14165e010 the player's effect name of a key
void FUN_14165f170(PCBase* p);                             // 0x14165f170
int FUN_140b7f6a0(void* pSvc, const egf::EntityID& kId);   // 0x140b7f6a0 sequence id of the model
void* FUN_141b6f910();                                     // 0x141b6f910 the animation service
void* FUN_1403ed280();                                     // effect manager
void* FUN_1403ed2d0();                                     // player manager
int FUN_141bd1a10(void* pPlayer, GameObject* pObject);
int FUN_1411a49c0(void* pEffectMgr, Unk_EffectQuery* pQuery);
void FUN_1411a6060(void* pEffectMgr, int nId);
class Unk_PCBaseBody;
void FUN_141240700(Unk_PCBaseBody* pBody, efd::Point3 kVel);               // 0x141240700
class Unk_SwimHitReport { public: void FUN_140cfaf30(); };   // the actor body's controller hit report
Unk_SwimHitReport* FUN_141240f20(Unk_PCBaseBody* pBody);

class Unk_SwimApp;
Unk_SwimApp* FUN_14086d260();                              // 0x14086d260 the application
int FUN_141473390(Unk_SwimApp* p);                         // 0x141473390 the current service tick id
bool FUN_1415337c0(int nLast, int nNow, int nMillis);      // 0x1415337c0 enough time passed since the last request
int FUN_1416764d0(MyPC* p);                                // 0x1416764d0 is riding
Ridee* FUN_141468360(PCBase* p);                           // 0x141468360 the ridee the actor sits on

// The efd::utf8string the exe builds out of line (ctor 0x1408a8700, dtor 0x1408a8900; 0x20 bytes).
struct Unk_SwimString
{
    Unk_SwimString() { FUN_1408a8700(m_buf); }
    ~Unk_SwimString() { FUN_1408a8900(m_buf); }
    Unk_SwimString& operator=(const char* psz) { FUN_140ae18f0(m_buf, psz); return *this; }
    operator const efd::utf8string&() const { return *(const efd::utf8string*)m_buf; }
    char m_buf[0x20];
};

// The config constants singleton: the swim speed at +0x56a8 is not read here; only the buff view below is.
class Unk_SwimBuff
{
public:
    efd::Point3 FUN_141683900();
    bool FUN_141683100(int nKey);
    bool FUN_141682fe0(int nKey);
};

// The item a state is told about in its slots 29/30.
class Unk_StateArg29 : public CItem { };

// @0x1417fa370
StateSwim::StateSwim(PCBase* pOwner) : State(pOwner)
{
    m_nEffect = 0;
    m_nMode = 0;
}

// @0x1417fa3d0
StateSwim::~StateSwim()
{
    FUN_1417fb400();
}

// @0x1417fa420
// MS2-FUNCTIONAL: the exe holds the ridee in a CComPtr (temp + EH frame); a raw pointer is used here
void StateSwim::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_nMode = FUN_141473390(FUN_14086d260());
    FUN_1417fb440();
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
        FUN_14165f170(pPC);
    if (m_pOwner->GetClassID() == 0x6200045)
        PCBase::FUN_141677f40(m_pOwner);
    float* pSpeed = m_pOwner->FUN_141671920();
    if (FUN_1417fb370() == 0)
    {
        m_n10 = 0x84;
        m_pOwner->FUN_141671960(pSpeed[3]);
    }
    else if (m_pOwner->FUN_141676b70() == 0)
    {
        m_n10 = 0x84;
        m_pOwner->FUN_141671960(pSpeed[2]);
    }
    else
    {
        m_n10 = 0x85;
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            Ridee* pRidee = FUN_141468360(m_pOwner);
            if (pRidee == 0)
                m_pOwner->FUN_141671960(pSpeed[3]);
            else
                m_pOwner->FUN_141671960(pRidee->FUN_1417070a0());
        }
        else
        {
            m_pOwner->FUN_141671960(pSpeed[3]);
        }
    }
}

// @0x1417fa600
// MS2-FUNCTIONAL: inlined array temporaries differ from the exe
void StateSwim::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_pOwner->FUN_141671960(m_pOwner->FUN_141671920()[2]);
    FUN_1417fb400();
}

// @0x1417fa660
// MS2-FUNCTIONAL: the exe holds the ridee in a CComPtr and lays out the point temporaries differently
void StateSwim::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->vfunc_63() == 0)
        return;
    float* pSpeed = m_pOwner->FUN_141671920();
    if (m_n10 == 0x84)
    {
        if (FUN_1417fb370() == 0)
            m_pOwner->FUN_141671960(pSpeed[3]);
        else
            m_pOwner->FUN_141671960(pSpeed[2]);
    }
    else if (m_n10 == 0x85)
    {
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            Ridee* pRidee = FUN_141468360(m_pOwner);
            if (pRidee == 0)
                m_pOwner->FUN_141671960(pSpeed[3]);
            else
                m_pOwner->FUN_141671960(pRidee->FUN_1417070a0());
        }
        else
        {
            m_pOwner->FUN_141671960(pSpeed[3]);
        }
    }
    efd::Point3 kDir = m_pOwner->FUN_141674b60(m_pOwner->FUN_14123c360());
    efd::Point3 kVel = kDir * m_pOwner->vfunc_95();
    efd::Point3 kMove = kVel * (float)fTime;
    FUN_141240700(m_pOwner->FUN_14166d220(), kVel);
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1417fa950
// MS2-FUNCTIONAL: call-site temporaries and branch layout differ from the exe
void StateSwim::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0 || m_pOwner->vfunc_63() == 0)
        return;
    if (m_pOwner->FUN_141675ed0() == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    if (FUN_1417b9460())
        return;
    if (m_pOwner->vfunc_99(0) != 0)
    {
        FUN_141240f20(m_pOwner->FUN_14166d220())->FUN_140cfaf30();
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    Unk_SwimBuff* pBuff = (Unk_SwimBuff*)m_pOwner->FUN_14166d240();
    efd::Point3 kDir = pBuff->FUN_141683900();
    m_pOwner->vfunc_22(kDir);
    if (m_pOwner->FUN_141676b70() == 0 || FUN_1417fb370() == 0)
        m_n10 = 0x84;
    else
        m_n10 = 0x85;
    if (pBuff->FUN_141683100(0x30d41))
    {
        pPC->FUN_1415248d0(1, 0);
    }
    else if (pBuff->FUN_141683100(0x30d42))
    {
        pPC->FUN_1415248d0(2, 0);
    }
    else if (m_pOwner->FUN_141671a30() == 0 || (!pBuff->FUN_141682fe0(0x493e1) && m_n28 == 0))
    {
        if (!m_pOwner->FUN_1416749c0())
            m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        m_n28 = 0;
        m_pOwner->vfunc_59(6, 0, 0x25, 0);
    }
}

// @0x1417fac90
// MS2-FUNCTIONAL: string wrapper and EH frame differ from the exe
void StateSwim::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    egf::EntityID kId;
    int nSeq = FUN_140b7f6a0(FUN_141b6f910(), m_pOwner->FUN_14123c460(kId));
    if (FUN_1417fb370() == 0)
    {
        Unk_SwimString strAnim;
        PCBase* pPC = FUN_1417b8370();
        if (pPC != 0)
            FUN_14165e2a0(pPC, &strAnim, 0x31);
        if (FUN_14096ad40(strAnim))
        {
            if (!m_pOwner->FUN_14166de90(0x31, nSeq))
                strAnim = m_pOwner->vfunc_123(0x31);
        }
        bool bPlayed = false;
        if (!FUN_14096ad40(strAnim))
        {
            float* pSpeed = m_pOwner->FUN_141671920();
            vfunc_10(m_pOwner->vfunc_95(), pSpeed[3], pSpeed[1], 1.0f, 0);
            bPlayed = m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), false, false);
        }
        if (bPlayed)
            FUN_1417fb440();
    }
    else
    {
        int nKey = 0x1c;
        if (m_n10 == 0x85)
            nKey = 0x1f;
        if (!m_pOwner->FUN_14166de90(nKey, nSeq))
        {
            float* pSpeed = m_pOwner->FUN_141671920();
            vfunc_10(m_pOwner->vfunc_95(), pSpeed[2], pSpeed[1], 1.0f, 0);
            m_pOwner->FUN_14166dda0(nKey);
        }
    }
}

// @0x1417fafb0
// MS2-FUNCTIONAL: frame/local layout differs from the exe
void StateSwim::vfunc_10(float a, float b, float c, float d, int e)
{
    int nOut = 0;
    float fSpeed = m_pOwner->vfunc_115(a, b, c, d, e, &nOut);
    m_pOwner->FUN_141670d80(fSpeed);
}

// @0x1417fb040
int StateSwim::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0)
        return 0;
    MyPC* pPC = FUN_1417b84b0();
    int nNow = FUN_141473390(FUN_14086d260());
    if (pPC != 0 && FUN_1416764d0(pPC) != 0 && FUN_1415337c0(m_nMode, nNow, 1000))
    {
        m_nMode = nNow;
        return 1;
    }
    if (m_n10 == p->m_nSub)
        return 0;
    m_nMode = nNow;
    return 1;
}

// @0x1417fb160
// MS2-FUNCTIONAL: the exe's smart-pointer temporaries and EH frame are not reproduced
void StateSwim::vfunc_29(MS2Ptr<Unk_StateArg29> p)
{
    State::vfunc_29(p);
    CItemGem* pGem = p->FUN_140527900();
    if (pGem != 0 && pGem->GetGem().get() != 0)
    {
        MS2Ptr<CGemSwim> spSwim(dynamic_cast<CGemSwim*>(pGem->GetGem().get()));
        if (spSwim.get() != 0)
            FUN_1417fb440();
    }
}

// @0x1417fb370
// MS2-FUNCTIONAL: the exe holds the ridee in a CComPtr (temp + EH frame); a raw pointer is used here
int StateSwim::FUN_1417fb370()
{
    Ridee* pRidee = FUN_141468360(m_pOwner);
    if (pRidee == 0)
        return 0;
    return pRidee->FUN_1417075e0();
}

// @0x1417fb400
void StateSwim::FUN_1417fb400()
{
    if (m_nEffect != 0)
    {
        FUN_1411a6060(FUN_1403ed280(), m_nEffect);
        m_nEffect = 0;
    }
}

// @0x1417fb440
// MS2-FUNCTIONAL: CString temporaries differ from the exe
void StateSwim::FUN_1417fb440()
{
    FUN_1417fb400();
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        Unk_EffectQuery query;
        query.m_strName = FUN_14165e010(pPC, 0x31);
        query.m_nObject = FUN_141bd1a10(FUN_1403ed2d0(), m_pOwner);
        query.SetActor(pPC->FUN_14123c580());
        m_nEffect = FUN_1411a49c0(FUN_1403ed280(), &query);
    }
}

// @0x1417fb570
int StateSwim::vfunc_14()
{
    return 0;
}

// @0x1417fb580
int StateSwim::vfunc_1()
{
    return 0x1b;
}

// @0x1417fb590
int StateSwim::vfunc_19()
{
    return 0;
}

// @0x1417fb5a0
void StateSwim::vfunc_34()
{
    m_n28 = 1;
}
