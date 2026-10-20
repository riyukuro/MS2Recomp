// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The two event micro-game actor states: StateMicroGameRps
// (rock-paper-scissors against another player, state type 0x3c) and StateMicroGameCoupleDance (couple dance, 0x45), the
// helpers they share (partner lookup, default motion, the failure-message builders, dialog lookups) and the MS2Ptr
// instantiation copies of this unit. See statemicrogame.h.
// MS2-UNIT: client\ms2\statemicrogame.cpp
// MS2-RANGE: 0x140b866d0-0x140b8c180 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??8?$MS2Ptr@VRpsGameData@@@@QEBA_NPEAVRpsGameData@@@Z 0x140b8bb30 ; unique
// MS2-PIN: ??8?$MS2Ptr@VUnk_StateArg22@@@@QEBA_NPEAVUnk_StateArg22@@@Z 0x140b8bbf0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_MgDanceEvent@@@@AEAAXPEAX@Z 0x140b8c090 ; merge-bind
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??$Unk_MgGetDialog@VUIMicroGameCoupleDance@@@@YAPEAVUIMicroGameCoupleDance@@H@Z 0x140b8b5c0
// MS2-PIN: ??$Unk_MgGetDialog@VUIMicroGameCoupleDanceMessage@@@@YAPEAVUIMicroGameCoupleDanceMessage@@H@Z 0x140b8b660
// MS2-PIN: ??$Unk_MgGetDialog@VUIMicroGameRps@@@@YAPEAVUIMicroGameRps@@H@Z 0x140b8b700
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statemicrogame.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <afxbasepane.h>
#include <new>
#include <egf/Entity.h>
#include <efd/utf8string.h>

#include "statemicrogame.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/uimicrogamecoupledance.h"
#include "ms2/client/ms2/uimicrogamecoupledancemessage.h"
#include "ms2/client/ms2/uimicrogamerps.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/commandchat.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

extern Unk_StreamPoint DAT_143b01a60;                    // the zero point
extern Unk_StreamPoint DAT_143a08cf8;                    // the up axis
extern char DAT_143ab2a90;                               // the rps event's context table

// A PCBase seen through its slot 18 (the position, returned as the 12-byte point of the FUN_ operators).
class Unk_MgPos
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual Unk_StreamPoint vfunc_18();
};

// The component of an actor that shows the micro game result (PCBase slot 83).
class Unk_PCBaseComp_a88 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                              // show
    virtual void vfunc_3();                              // reset
    void FUN_14192f8b0(int nMode);                       // 0x14192f8b0
    void FUN_14192f8d0(const CString& strEffect);        // 0x14192f8d0
};

// The player manager: actors by id.
class Unk_MgWorld
{
public:
    PCBase* FUN_141bd1290(int nId);                      // 0x141bd1290
    PCBase* FUN_141bd1530(__int64 nId);                  // 0x141bd1530
};
Unk_MgWorld* FUN_1403ed2d0();

// The UI manager.
class Unk_MgUIMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_MgUIMgr* FUN_1403ed2b0();

template <class T> T* Unk_MgGetDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

CGameRule* FUN_1401c0d90();                              // 0x1401c0d90

// The animation registry: the default sequence of a model.
class Unk_MgAnimSvc { public: unsigned FUN_140b7f6a0(const egf::EntityID& kId); };
Unk_MgAnimSvc* FUN_141b6f910();

// This unit's free helpers (defined below).
bool FUN_140b883c0();
CString FUN_140b8b470(int nResult);
int FUN_140b8b540(PCBase* pActor);

// The couple dance event: stage texts and the dance names (FUN_140302b00 -> FUN_1403ed140 -> FUN_140428700).
struct Unk_MgDanceText
{
    CStringW m_strAnim;                                  // +0x00 the motion of the stage
    CStringW m_strMessage;                               // +0x08 the message
};
MS2_CHECK_SIZE(Unk_MgDanceText, 0x10);
class Unk_MgDanceEvent : public CPtred
{
public:
    Unk_MgDanceText* FUN_140402080(int nStage);          // 0x140402080
    char m_pad_18[0x30 - sizeof(CPtred)];
    int m_nMinScore;                                     // +0x30 the score needed for the good result
    int m_nStages;                                       // +0x34 the number of stages
    char m_pad_38[0x80 - 0x38];
    ATL::CAtlArray<CStringW> m_aDances;                  // +0x80
};
MS2_CHECK_OFFSET(Unk_MgDanceEvent, m_nMinScore, 0x30);
MS2_CHECK_OFFSET(Unk_MgDanceEvent, m_aDances, 0x80);
class Unk_MgEventHolder { public: MS2Ptr<Unk_MgDanceEvent> FUN_140428700(); };
class Unk_MgGameService { public: Unk_MgEventHolder* FUN_1403ed140(); };
Unk_MgGameService* FUN_140302b00();

// Actor helpers (the bodies are in the earlier objs).
class Unk_MgBuffMgr { public: Unk_StreamPoint FUN_141683290(); };
Unk_MgBuffMgr* FUN_14166d240(PCBase* p);                 // 0x14166d240
bool FUN_1416749c0(PCBase* p);                           // 0x1416749c0
Unk_StreamPoint FUN_140a0b080(const Unk_StreamPoint& kEnd, const Unk_StreamPoint& kStart, const Unk_StreamPoint& kUp);   // 0x140a0b080 look-at euler
unsigned FUN_140869420();                                // 0x140869420 the clock
bool FUN_1401647e0(const CString& strA, const CString& strB);   // 0x1401647e0 the strings are equal
CString FUN_1401d4330(const wchar_t* psz, int nCodePage);       // 0x1401d4330 wide to ansi
CString FUN_1409a2360(const char* psz, int nCodePage);          // 0x1409a2360
CStringW FUN_140298ea0(CStringW str);                    // 0x140298ea0 string-table lookup of a key
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);   // 0x14052bd00 string table text with {0}
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg); // 0x1405c2690 the same by key
void FUN_141275260(int nStringId, int nA, int nB);       // 0x141275260 notice by string id
unsigned FUN_140768010(unsigned nMax, int nMin);         // 0x140768010 random index
int FUN_140a5f180(const void* pTable, int nKey, int nDefault);   // 0x140a5f180
void FUN_141924680(void* pPane);                         // 0x141924680 close the dance pane
void* FUN_140b769d0(int nId);                            // 0x140b769d0 the dock pane of a dialog

// The scene-graph probes of the placement test (see statecoupleemotion.cpp: the same helper sits in that obj).
class Unk_MgPhysics
{
public:
    int FUN_14168a450(efd::Point3 ptFrom, float* pDist, float fLen);
    bool FUN_14168a770(const efd::Point3* pPoint);
    int FUN_14168a310(const efd::Point3& ptFrom, efd::Point3& ptHit, void* pInfo, float fLen, int nMask, int nA);
};
Unk_MgPhysics* FUN_1409f7ca0();
class Unk_MgEntity { public: egf::FlatModel* FUN_1408a9bd0(); void FUN_1408a2060(unsigned nProp, efd::utf8string& s); };
struct Unk_MgRayHit { char m_pad[0x30]; Unk_MgEntity* m_pObject; };
const char* FUN_1408ac310(const efd::utf8string& s);
int FUN_1408a01e0(const CStringA& s);
class Unk_MgWorldQuery { public: int FUN_141bcafa0(egf::Entity* pEntity); };

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).
void FUN_141276f80(const Unk_CommandChat& chat);         // 0x141276f80 send the chat line

// The player lookup the banner listener calls (uibannereventlistener.cpp); its callee is FUN_140b73bc0.
class Unk_141bd0cc0 : public MyPC {};
bool FUN_140b73bc0(MyPC* pPlayer);                       // 0x140b73bc0 the player can join the micro game

// ---- StateMicroGameRps ----

// @0x140b866d0
StateMicroGameRps::StateMicroGameRps(PCBase* pOwner) : State(pOwner)
{
}

// @0x140b86730
StateMicroGameRps::~StateMicroGameRps()
{
}

// @0x140b86770
void StateMicroGameRps::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spRps.AssignRaw(dynamic_cast<StateMicroGameRpsData*>(pData));
    if (m_spRps == 0)
    {
        MS2_ASSERT_AT(0x45, 0);
    }
}

// @0x140b86810
void StateMicroGameRps::vfunc_5(int n)
{
    State::vfunc_5(n);
    FUN_140b87cc0();
    m_spRps = 0;
}

// @0x140b86860
void StateMicroGameRps::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (FUN_1417b8560() != 0)
        FUN_140b88290(fTime);
    PCBase* pActor = FUN_1417b8370();
    if (pActor == 0)
        return;
    PCBase* pPartner = FUN_140b879d0();
    if (pPartner == 0)
        return;
    Unk_StreamPoint kLook = FUN_140a0b080(reinterpret_cast<Unk_MgPos*>(pPartner)->vfunc_18(),
        reinterpret_cast<Unk_MgPos*>(pActor)->vfunc_18(), DAT_143a08cf8);
    pActor->FUN_14166d8b0(kLook.z);
    Unk_StreamPoint kZero = DAT_143b01a60;
    pActor->vfunc_68(&kZero, fTime, 0, 0, 0);
}

// @0x140b869c0
int StateMicroGameRps::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0)
    {
        MS2_ASSERT_AT(0xd3, 0);
        return 0;
    }
    if (p->m_nSub == FUN_1417b7e40())
    {
        if (!FUN_140b87210(p))
            return 1;
        return 0;
    }
    return 1;
}

// @0x140b86ad0
void StateMicroGameRps::EndOfSequence(NiActorManager*, unsigned int, NiControllerSequence*, float)
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider != 0)
    {
        PCBase* pPartner = FUN_140b879d0();
        if (pPartner != 0 && !(m_spRps == 0))
        {
            if (!m_spRps->m_str.IsEmpty())
            {
                CString strKey = FUN_1401d4330(m_spRps->m_str, 0);
                CString strAnim;
                if (pRider->FUN_14166f790(&strKey, strAnim, 0))
                {
                    if (!FUN_1401647e0(pRider->FUN_14166dc50(), strAnim))
                    {
                        MS2Ptr<RpsContext> spEvent = FUN_1401c0d90()->FUN_14047d140();
                        if (spEvent == 0)
                        {
                            pRider->vfunc_59(1, 0, 0, 0);
                        }
                        else
                        {
                            int nKind = FUN_1417b7e40();
                            if (nKind == 0x9b)
                            {
                                FUN_140b87e00();
                                pRider->FUN_14166cc40(0x9c);
                            }
                            else if (nKind == 0x9c)
                            {
                                pRider->FUN_14166cc40(0x9d);
                                pRider->vfunc_59(1, 0, 0, 0);
                            }
                        }
                    }
                }
            }
        }
    }
}

// @0x140b86d80
void StateMicroGameRps::vfunc_8(double fTime)
{
    switch (FUN_1417b7e40())
    {
    case 0x9d:
        State::vfunc_8(fTime);
        if (FUN_1417b8560() == 0)
            return;
        Unk_MgBuffMgr* pBuff = FUN_14166d240(m_pOwner);
        Unk_StreamPoint kPos = pBuff->FUN_141683290();
        Unk_StreamPoint kArg = kPos;
        m_pOwner->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
        if (FUN_1416749c0(m_pOwner))
            m_pOwner->vfunc_59(2, 0, 0, 0);
        else
            FUN_1417b9460();
        break;
    }
}

// @0x140b86ea0
// MS2-FUNCTIONAL: the animation-name temporaries differ from the exe
void StateMicroGameRps::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    int nKind = FUN_1417b7e40();
    if (nKind < 0x99 || nKind > 0x9a)
    {
        if (m_spRps == 0)
            return;
        if (!m_spRps->m_str.IsEmpty())
        {
            CString strKey = FUN_1401d4330(m_spRps->m_str, 0);
            CString strAnim;
            if (m_pOwner->FUN_14166f790(&strKey, strAnim, 0))
            {
                efd::utf8string kAnim((const char*)strAnim);
                m_pOwner->FUN_14166dd20(kAnim, 1.0f, false, false);
            }
        }
    }
    else
    {
        egf::EntityID kId;
        FUN_140b87a40(FUN_141b6f910()->FUN_140b7f6a0(m_pOwner->FUN_14123c460(kId)));
    }
}

// @0x140b870a0
void StateMicroGameRps::vfunc_6()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
        return;
    pRider->vfunc_59(1, 0, 0, 0);
}

// @0x140b87100
bool StateMicroGameRps::vfunc_28(MS2Ptr<Unk_StateArg22> p)
{
    int nKind = FUN_1417b7e40();
    if (nKind == p->m_nSub)
    {
        if (!FUN_140b87210(p))
            return true;
        return false;
    }
    return true;
}

// @0x140b871c0
int StateMicroGameRps::FUN_140b871c0()
{
    if (m_spRps.get() != 0)
        return m_spRps->m_n1c;
    return -1;
}

// @0x140b87210
bool StateMicroGameRps::FUN_140b87210(MS2Ptr<Unk_StateArg22> p)
{
    if (m_spRps.get() != 0)
        return m_spRps->FUN_1417c16b0(p);
    return false;
}

// @0x140b872c0
int StateMicroGameRps::FUN_140b872c0()
{
    if (m_spRps.get() != 0)
        return m_spRps->m_n18;
    return 0;
}

// @0x140b87310
void StateMicroGameRps::FUN_140b87310(int nMode, int nCard, int nPick)
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
    {
        MS2_ASSERT_AT(0x92, 0);
        return;
    }
    if (FUN_1417b7e40() != 0x9a)
    {
        MS2_ASSERT_AT(0x98, 0);
        return;
    }
    if ((nMode >= 0 && nMode <= 3) == false)
    {
        MS2_ASSERT_AT(0x9e, 0);
        return;
    }
    if ((nCard >= 0 && nCard <= 2) == false)
    {
        MS2_ASSERT_AT(0xa4, 0);
        return;
    }
    if ((nPick >= 0 && nPick <= 2) == false)
    {
        MS2_ASSERT_AT(0xaa, 0);
        return;
    }
    UIMicroGameRps* pUI = Unk_MgGetDialog<UIMicroGameRps>(0x4f60);
    if (pUI == 0)
    {
        MS2_ASSERT_AT(0xb1, 0);
        return;
    }
    pUI->FUN_140e663b0();
    MS2Ptr<RpsContext> spEvent = FUN_1401c0d90()->FUN_14047d140();
    if (spEvent == 0)
    {
        MS2_ASSERT_AT(0xba, 0);
        return;
    }
    MS2Ptr<RpsGameData> spGame = spEvent->m_spGameData;
    if (spGame == 0)
    {
        MS2_ASSERT_AT(0xc1, 0);
        return;
    }
    if (m_spRps == 0)
        return;
    m_spRps->m_n1c = nCard;
    m_spRps->m_n20 = nMode;
    CStringW& rName = spGame->m_actionNames[nCard];
    m_spRps->m_str = rName;
    pRider->FUN_14166cc40(0x9b);
}

// @0x140b876a0
bool StateMicroGameRps::FUN_140b876a0()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
    {
        MS2_ASSERT_AT(0x77, 0);
        return false;
    }
    bool bNull = (m_spRps == 0);
    if (!bNull)
    {
        UIMicroGameRps* pUI = Unk_MgGetDialog<UIMicroGameRps>(0x4f60);
        if (pUI == 0)
        {
            MS2_ASSERT_AT(0x81, 0);
            return false;
        }
        pUI->FUN_140e66330();
        m_spRps->m_n1c = -1;
        m_spRps->m_n20 = -1;
        m_spRps->m_str.Empty();
        pRider->FUN_14166cc40(0x9a);
    }
    return bNull;
}

// @0x140b877c0
void StateMicroGameRps::FUN_140b877c0()
{
    if (FUN_1417b8560() != 0)
    {
        MS2Ptr<RpsContext> spEvent = FUN_1401c0d90()->FUN_14047d140();
        if (!(spEvent == 0))
        {
            MS2Ptr<RpsGameData> spGame = spEvent->m_spGameData;
            if (!(spGame == 0))
            {
                if (!spGame->m_messages.IsEmpty())
                {
                    int nIndex = FUN_140768010(spGame->m_messages.GetCount(), 0);
                    CStringW strText = spGame->m_messages.GetAt(nIndex);
                    Unk_CommandChat chat;
                    chat.kind = 0x17;
                    chat.message = FUN_140298ea0(strText);
                    FUN_141276f80(chat);
                }
            }
        }
    }
}

// @0x140b879d0
PCBase* StateMicroGameRps::FUN_140b879d0()
{
    Unk_MgWorld* pWorld = FUN_1403ed2d0();
    if (pWorld == 0)
        return 0;
    if (m_spRps.get() != 0)
        return pWorld->FUN_141bd1290(m_spRps->m_n18);
    return 0;
}

// @0x140b87a40
void StateMicroGameRps::FUN_140b87a40(unsigned int nSeq)
{
    int n = 0;
    if (m_pOwner->vfunc_65() != 0)
        n = 1;
    if (!m_pOwner->FUN_14166de90(n, nSeq))
    {
        m_pOwner->FUN_14166dda0(n);
        m_pOwner->FUN_14166f8f0(0, 1);
    }
}

// @0x140b87ad0
void StateMicroGameRps::FUN_140b87ad0()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider != 0)
    {
        PCBase* pPartner = FUN_140b879d0();
        if (pPartner != 0)
        {
            int nResult = FUN_140b8b540(pRider);
            int nPartnerResult = FUN_140b8b540(pPartner);
            CString strEffect = FUN_140b8b470(nResult);
            CString strPartnerEffect = FUN_140b8b470(nPartnerResult);
            MS2Ptr<Unk_PCBaseComp_a88> spShow = pRider->vfunc_83();
            MS2Ptr<Unk_PCBaseComp_a88> spPartnerShow = pPartner->vfunc_83();
            if (spShow == 0 || spPartnerShow == 0)
                return;
            spShow->FUN_14192f8b0(3);
            spShow->FUN_14192f8d0(strEffect);
            spShow->vfunc_2();
            spPartnerShow->FUN_14192f8b0(3);
            spPartnerShow->FUN_14192f8d0(strPartnerEffect);
            spPartnerShow->vfunc_2();
        }
    }
}

// @0x140b87cc0
void StateMicroGameRps::FUN_140b87cc0()
{
    MyPC* pRider = FUN_1417b84b0();
    PCBase* pPartner = FUN_140b879d0();
    if (pRider != 0 && pPartner != 0)
    {
        MS2Ptr<Unk_PCBaseComp_a88> spShow = pRider->vfunc_83();
        MS2Ptr<Unk_PCBaseComp_a88> spPartnerShow = pPartner->vfunc_83();
        if (spShow == 0 || spPartnerShow == 0)
        {
            MS2_ASSERT_AT(0x19c, 0);
        }
        else
        {
            spShow->vfunc_3();
            spPartnerShow->vfunc_3();
        }
    }
}

// @0x140b87e00
// MS2-FUNCTIONAL: the string temporaries of the notice chain differ from the exe
bool StateMicroGameRps::FUN_140b87e00()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
    {
        MS2_ASSERT_AT(0x1a9, 0);
        return false;
    }
    MS2Ptr<RpsContext> spEvent = FUN_1401c0d90()->FUN_14047d140();
    if (spEvent == 0)
        return false;
    if (m_spRps == 0)
        return false;
    MS2Ptr<RpsGameData> spGame = spEvent->m_spGameData;
    if (spGame == 0)
    {
        MS2_ASSERT_AT(0x1b7, 0);
        return false;
    }
    if (m_spRps->m_n20 < 0 || m_spRps->m_n20 > 3)
    {
        MS2_ASSERT_AT(0x1bd, 0);
        return false;
    }
    RpsGameData::Result* pResult = &spGame->m_results[m_spRps->m_n20];
    if (pResult->m_actions.IsEmpty())
        return false;
    int nAction = FUN_140768010(pResult->m_actions.GetCount(), 0);
    m_spRps->m_str = pResult->m_actions.GetAt(nAction);
    FUN_140b87ad0();
    if (pResult->m_messages.IsEmpty())
        return false;
    int nMessage = FUN_140768010(pResult->m_actions.GetCount(), 0);
    CStringW strText = pResult->m_messages.GetAt(nMessage);
    Unk_CommandChat chat;
    chat.kind = 0x17;
    chat.message = FUN_140298ea0(strText);
    FUN_141276f80(chat);
    switch (m_spRps->m_n20)
    {
    case 0:
        FUN_141275260(0xd14, 1, 1);
        break;
    case 1:
        FUN_141275260(0xd12, 1, 1);
        break;
    case 2:
        FUN_141275260(0xd13, 1, 1);
        break;
    }
    return true;
}

// @0x140b88290
// MS2-FUNCTIONAL: branch layout of the null guards differs from the exe
void StateMicroGameRps::FUN_140b88290(double)
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider)
    {
        PCBase* pPartner = FUN_140b879d0();
        if (pPartner == 0)
        {
            pRider->vfunc_59(1, 0, 0, 0);
        }
        else if (pPartner->FUN_14166c930() != 0x3c && pPartner->FUN_14166c930() != 0x3b)
        {
            if (FUN_1417b7e40() == 0x9a)
                FUN_141275260(0xd05, 1, 1);
            pRider->vfunc_59(1, 0, 0, 0);
        }
        else
        {
            if (FUN_1417b7e40() == 0x9a && FUN_140b883c0() == false)
                pRider->vfunc_59(1, 0, 0, 0);
        }
    }
}

// The rps window of the event is open.
// @0x140b883c0
bool FUN_140b883c0()
{
    MS2Ptr<RpsContext> spEvent = FUN_1401c0d90()->FUN_14047d140();
    if (spEvent == 0)
        return false;
    int nCount = FUN_140a5f180(&DAT_143ab2a90, spEvent->m_20, 0);
    if (nCount <= 0)
        return false;
    return true;
}

// Both players are within the micro game's reach.
// @0x140b88470
bool FUN_140b88470(const Unk_StreamPoint& kA, const Unk_StreamPoint& kB)
{
    float fMax = (float)*static_cast<Client::Constants*>(FUN_1401d3200())->MicroGameMaxDistance.Get();
    float fDist = kA.FUN_140965c40(kB).FUN_140967ac0();
    if (fDist > fMax)
        return false;
    return true;
}

// Is the point a legal spot to stand: ground below, not blocked, and no solid / forbidden object on it?
// @0x140b884e0
// MS2-FUNCTIONAL: written from the call sequence.
bool FUN_140b884e0(Unk_StreamPoint& kPoint)
{
    kPoint.z += 5.0f;
    float fDist = 0.0f;
    if (FUN_1409f7ca0()->FUN_14168a450(efd::Point3(kPoint.x, kPoint.y, kPoint.z), &fDist, 10.0f) == 0)
        return false;
    if (FUN_1409f7ca0()->FUN_14168a770((const efd::Point3*)&kPoint))
        return false;
    Unk_StreamPoint kDown = DAT_143b01a60;
    Unk_MgRayHit kHit;
    if (FUN_1409f7ca0()->FUN_14168a310(efd::Point3(kPoint.x, kPoint.y, kPoint.z), (efd::Point3&)kDown, &kHit, 0.0f, 0, 0) == 0)
        return false;
    if (kHit.m_pObject == 0)
        return false;
    efd::utf8string strTag("None");
    kHit.m_pObject->FUN_1408a2060(0x15014205, strTag);
    CStringA strValue((const char*)FUN_1408ac310(strTag));
    if (FUN_1408a01e0(strValue) == 0x40)
        return false;
    if (kHit.m_pObject->FUN_1408a9bd0()->ContainsModel(0xd3b04f05))
        return false;
    if (kHit.m_pObject->FUN_1408a9bd0()->ContainsModel(0x032767dd))
        return false;
    if (kHit.m_pObject->FUN_1408a9bd0()->ContainsModel(0x72f49865))
        return false;
    return reinterpret_cast<Unk_MgWorldQuery*>(FUN_1403ed2d0())->FUN_141bcafa0((egf::Entity*)kHit.m_pObject) == 0;
}

// The player can take part in the micro game (the check of the banner listener).
// @0x140b887b0
bool FUN_140b887b0(Unk_141bd0cc0* pPlayer)
{
    return FUN_140b73bc0(pPlayer);
}

// The notice text of a failed rps request.
// @0x140b887d0
CStringW FUN_140b887d0(__int64 nActorId, int nWhy)
{
    CStringW strPartner(L"");
    PCBase* pPartner = FUN_1403ed2d0()->FUN_141bd1530(nActorId);
    if (pPartner != 0)
        strPartner = pPartner->vfunc_77();
    CStringW strMessage(L"");
    if (nWhy == 0)
        strMessage = FUN_14052bd00(0xd0a, strPartner);
    else if (nWhy == 1)
        strMessage = FUN_14052bd00(0xd07, strPartner);
    else if (nWhy == 2)
        strMessage = FUN_14052bd00(0xd0b, strPartner);
    else if (nWhy == 3)
        strMessage = FUN_14052bd00(0xd06, strPartner);
    else
        strMessage = FUN_14052bd00(0xd11, strPartner);
    return strMessage;
}

// ---- StateMicroGameCoupleDance ----

// @0x140b88aa0
StateMicroGameCoupleDance::StateMicroGameCoupleDance(PCBase* pOwner) : State(pOwner), m_nStage(0), m_nDeadline(0), m_nScore(0)
{
}

// @0x140b88b40
StateMicroGameCoupleDance::~StateMicroGameCoupleDance()
{
}

// @0x140b88bb0
void StateMicroGameCoupleDance::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spDance.AssignRaw(dynamic_cast<StateMicroGameCoupleDanceData*>(pData));
    if (m_spDance == 0)
    {
        MS2_ASSERT_AT(0x2b0, 0);
    }
}

// @0x140b88c50
void StateMicroGameCoupleDance::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_spDance = 0;
}

// @0x140b88c90
void StateMicroGameCoupleDance::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (FUN_1417b8560() != 0)
        FUN_140b89ed0(fTime);
    PCBase* pActor = FUN_1417b8370();
    if (pActor == 0)
        return;
    PCBase* pPartner = FUN_140b89dd0();
    if (pPartner == 0)
        return;
    Unk_StreamPoint kLook = FUN_140a0b080(reinterpret_cast<Unk_MgPos*>(pPartner)->vfunc_18(),
        reinterpret_cast<Unk_MgPos*>(pActor)->vfunc_18(), DAT_143a08cf8);
    pActor->FUN_14166d8b0(kLook.z);
    Unk_StreamPoint kZero = DAT_143b01a60;
    pActor->vfunc_68(&kZero, fTime, 0, 0, 0);
    if (m_nDeadline != 0 && FUN_140869420() >= (unsigned)m_nDeadline)
        FUN_140b8a060();
}

// @0x140b88e20
int StateMicroGameCoupleDance::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0)
    {
        MS2_ASSERT_AT(0x2fc, 0);
        return 0;
    }
    if (p->m_nSub == FUN_1417b7e40())
    {
        if (!FUN_140b89410(p))
            return 1;
        return 0;
    }
    return 1;
}

// @0x140b88f30
void StateMicroGameCoupleDance::EndOfSequence(NiActorManager*, unsigned int, NiControllerSequence*, float)
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider != 0 && !(m_spDance == 0))
    {
        if (!m_spDance->m_str.IsEmpty())
        {
            if (!FUN_1401647e0(pRider->FUN_14166dc50(), m_spDance->m_str) && FUN_1417b7e40() != 0xad)
                m_spDance->m_str.Empty();
        }
    }
}

// @0x140b89040
void StateMicroGameCoupleDance::vfunc_8(double fTime)
{
    switch (FUN_1417b7e40())
    {
    case 0xb1:
        State::vfunc_8(fTime);
        if (FUN_1417b8560() == 0)
            return;
        Unk_MgBuffMgr* pBuff = FUN_14166d240(m_pOwner);
        Unk_StreamPoint kPos = pBuff->FUN_141683290();
        Unk_StreamPoint kArg = kPos;
        m_pOwner->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
        if (FUN_1416749c0(m_pOwner))
            m_pOwner->vfunc_59(2, 0, 0, 0);
        else
            FUN_1417b9460();
        break;
    }
}

// @0x140b89160
// MS2-FUNCTIONAL: the animation-name temporaries differ from the exe
void StateMicroGameCoupleDance::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    if (!(m_spDance == 0))
    {
        if (!m_spDance->m_str.IsEmpty())
        {
            efd::utf8string kAnim((const char*)FUN_1409a2360(m_spDance->m_str, 0));
            m_pOwner->FUN_14166dd20(kAnim, 1.0f, false, false);
            return;
        }
    }
    egf::EntityID kId;
    FUN_140b89e40(FUN_141b6f910()->FUN_140b7f6a0(m_pOwner->FUN_14123c460(kId)));
}

// @0x140b892f0
void StateMicroGameCoupleDance::vfunc_6()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
        return;
    pRider->vfunc_59(1, 0, 0, 0);
}

// @0x140b89350
bool StateMicroGameCoupleDance::vfunc_28(MS2Ptr<Unk_StateArg22> p)
{
    int nKind = FUN_1417b7e40();
    if (nKind == p->m_nSub)
    {
        if (!FUN_140b89410(p))
            return true;
        return false;
    }
    return true;
}

// @0x140b89410
bool StateMicroGameCoupleDance::FUN_140b89410(MS2Ptr<Unk_StateArg22> p)
{
    if (m_spDance.get() != 0)
        return m_spDance->FUN_1417c1990(p);
    return false;
}

// @0x140b894c0
int StateMicroGameCoupleDance::FUN_140b894c0()
{
    if (m_spDance.get() != 0)
        return m_spDance->m_n18;
    return 0;
}

// @0x140b89510
// MS2-FUNCTIONAL: the string temporaries of the message chain differ from the exe
bool StateMicroGameCoupleDance::FUN_140b89510(const std::vector<int>& aStages)
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
    {
        MS2_ASSERT_AT(0x3af, 0);
        return false;
    }
    FUN_140b8b020(aStages);
    MS2Ptr<Unk_MgDanceEvent> spEvent = FUN_140302b00()->FUN_1403ed140()->FUN_140428700();
    if (spEvent == 0)
    {
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    if (spEvent->m_nStages == 0)
    {
        MS2_ASSERT_AT(0x3bd, 0);
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    if (!(m_spDance == 0))
    {
        m_spDance->m_b1c = false;
        pRider->FUN_14166cc40(0xaa);
        Unk_MgDanceText* pText = spEvent->FUN_140402080(0);
        UIMicroGameCoupleDanceMessage* pMessage = Unk_MgGetDialog<UIMicroGameCoupleDanceMessage>(0x4f72);
        if (pMessage != 0)
            pMessage->FUN_140e65c00(FUN_140298ea0(CStringW(pText->m_strMessage)), 3000);
        m_spDance->m_str = (const wchar_t*)pText->m_strAnim;
        efd::utf8string kAnim((const char*)FUN_1409a2360(m_spDance->m_str, 0));
        m_pOwner->FUN_14166dd20(kAnim, 1.0f, false, false);
        m_nDeadline = FUN_140869420() + 3000;
    }
    return true;
}

// @0x140b89880
// MS2-FUNCTIONAL: the string temporaries of the message chain differ from the exe
bool StateMicroGameCoupleDance::FUN_140b89880(int nStage, bool bGood, int nDance, int nPartnerDance)
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
    {
        MS2_ASSERT_AT(0x42e, 0);
        return false;
    }
    if (FUN_1417b7e40() != 0xac)
    {
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    MS2Ptr<Unk_MgDanceEvent> spEvent = FUN_140302b00()->FUN_1403ed140()->FUN_140428700();
    if (spEvent == 0)
    {
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    if (m_spDance == 0)
    {
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    UIMicroGameCoupleDance* pUI = Unk_MgGetDialog<UIMicroGameCoupleDance>(0x4f70);
    if (pUI == 0)
    {
        MS2_ASSERT_AT(0x448, 0);
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    pUI->FUN_140e646e0();
    m_nStage = nStage;
    if (nDance >= 0 && nDance < (int)spEvent->m_aDances.GetCount())
    {
        if (nPartnerDance >= 0 && nPartnerDance < (int)spEvent->m_aDances.GetCount())
        {
            m_spDance->m_b1c = bGood;
            if (bGood)
                m_nScore = m_nScore + 1;
            Unk_MgDanceText* pText = spEvent->FUN_140402080(3);
            UIMicroGameCoupleDanceMessage* pMessage = Unk_MgGetDialog<UIMicroGameCoupleDanceMessage>(0x4f72);
            if (pMessage != 0)
                pMessage->FUN_140e65c00(FUN_140298ea0(CStringW(pText->m_strMessage)), 3000);
            m_spDance->m_str = (const wchar_t*)spEvent->m_aDances.GetAt(nDance);
            efd::utf8string kAnim((const char*)FUN_1409a2360(m_spDance->m_str, 0));
            m_pOwner->FUN_14166dd20(kAnim, 1.0f, false, false);
            m_nDeadline = FUN_140869420() + 3000;
            pRider->FUN_14166cc40(0xad);
            return true;
        }
        MS2_ASSERT_AT(0x458, 0);
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    MS2_ASSERT_AT(0x451, 0);
    pRider->vfunc_59(1, 0, 0, 0);
    return false;
}

// @0x140b89dd0
PCBase* StateMicroGameCoupleDance::FUN_140b89dd0()
{
    Unk_MgWorld* pWorld = FUN_1403ed2d0();
    if (pWorld == 0)
        return 0;
    if (m_spDance.get() != 0)
        return pWorld->FUN_141bd1290(m_spDance->m_n18);
    return 0;
}

// @0x140b89e40
void StateMicroGameCoupleDance::FUN_140b89e40(unsigned int nSeq)
{
    int n = 0;
    if (m_pOwner->vfunc_65() != 0)
        n = 1;
    if (!m_pOwner->FUN_14166de90(n, nSeq))
    {
        m_pOwner->FUN_14166dda0(n);
        m_pOwner->FUN_14166f8f0(0, 1);
    }
}

// @0x140b89ed0
// MS2-FUNCTIONAL: branch layout of the null guards differs from the exe
void StateMicroGameCoupleDance::FUN_140b89ed0(double)
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider)
    {
        PCBase* pPartner = FUN_140b89dd0();
        if (pPartner == 0)
        {
            pRider->vfunc_59(1, 0, 0, 0);
        }
        else if (pPartner->FUN_14166c930() != 0x45 && pPartner->FUN_14166c930() != 0x3b)
        {
            pRider->vfunc_59(1, 0, 0, 0);
        }
    }
}

// @0x140b89f90
bool StateMicroGameCoupleDance::FUN_140b89f90()
{
    MS2Ptr<Unk_MgDanceEvent> spEvent = FUN_140302b00()->FUN_1403ed140()->FUN_140428700();
    if (spEvent == 0)
    {
        MS2_ASSERT_AT(0x2f1, 0);
        return false;
    }
    return m_nStage >= spEvent->m_nStages - 1;
}

// @0x140b8a060
void StateMicroGameCoupleDance::FUN_140b8a060()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider != 0)
    {
        MS2Ptr<Unk_MgDanceEvent> spEvent = FUN_140302b00()->FUN_1403ed140()->FUN_140428700();
        if (spEvent == 0)
        {
            pRider->vfunc_59(1, 0, 0, 0);
        }
        else
        {
            switch (FUN_1417b7e40())
            {
            case 0xaa:
                FUN_140b8a290();
                pRider->FUN_14166cc40(0xab);
                break;
            case 0xab:
                FUN_140b8a5f0();
                pRider->FUN_14166cc40(0xac);
                break;
            case 0xad:
                pRider->FUN_14166cc40(0xae);
                break;
            case 0xae:
                FUN_140b8a910();
                pRider->FUN_14166cc40(0xaf);
                break;
            case 0xaf:
                if (FUN_140b89f90() == false)
                {
                    m_nStage = m_nStage + 1;
                    FUN_140b8a290();
                    pRider->FUN_14166cc40(0xab);
                }
                else
                {
                    FUN_140b8acc0();
                    pRider->FUN_14166cc40(0xb0);
                }
                break;
            case 0xb0:
                {
                    CBasePane* pPane = (CBasePane*)FUN_140b769d0(0x4f71);
                    if (pPane != 0 && pPane->IsFloating() == 0)
                        FUN_141924680(pPane);
                    pRider->FUN_14166cc40(0xb1);
                    pRider->vfunc_59(1, 0, 0, 0);
                }
            }
        }
    }
}

// @0x140b8a290
// MS2-FUNCTIONAL: the string temporaries of the message chain differ from the exe
bool StateMicroGameCoupleDance::FUN_140b8a290()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
    {
        MS2_ASSERT_AT(0x3db, 0);
        return false;
    }
    if (FUN_1417b7e40() != 0xaa && FUN_1417b7e40() != 0xaf)
    {
        MS2_ASSERT_AT(0x3e1, 0);
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    MS2Ptr<Unk_MgDanceEvent> spEvent = FUN_140302b00()->FUN_1403ed140()->FUN_140428700();
    if (spEvent == 0)
    {
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    if (!(m_spDance == 0))
    {
        m_spDance->m_b1c = false;
        Unk_MgDanceText* pText = spEvent->FUN_140402080(1);
        UIMicroGameCoupleDanceMessage* pMessage = Unk_MgGetDialog<UIMicroGameCoupleDanceMessage>(0x4f72);
        if (pMessage != 0)
            pMessage->FUN_140e65ce0(m_nStage + 1, FUN_140298ea0(CStringW(pText->m_strMessage)), 3000);
        m_spDance->m_str = (const wchar_t*)pText->m_strAnim;
        efd::utf8string kAnim((const char*)FUN_1409a2360(m_spDance->m_str, 0));
        m_pOwner->FUN_14166dd20(kAnim, 1.0f, false, false);
        m_nDeadline = FUN_140869420() + 3000;
    }
    return true;
}

// @0x140b8a5f0
// MS2-FUNCTIONAL: the string temporaries of the animation call differ from the exe
bool StateMicroGameCoupleDance::FUN_140b8a5f0()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
    {
        MS2_ASSERT_AT(0x403, 0);
        return false;
    }
    if (FUN_1417b7e40() != 0xab)
    {
        MS2_ASSERT_AT(0x409, 0);
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    MS2Ptr<Unk_MgDanceEvent> spEvent = FUN_140302b00()->FUN_1403ed140()->FUN_140428700();
    if (spEvent == 0)
    {
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    if (!(m_spDance == 0))
    {
        Unk_MgDanceText* pText = spEvent->FUN_140402080(2);
        m_spDance->m_str = (const wchar_t*)pText->m_strAnim;
        efd::utf8string kAnim((const char*)FUN_1409a2360(m_spDance->m_str, 0));
        m_pOwner->FUN_14166dd20(kAnim, 1.0f, false, false);
        UIMicroGameCoupleDance* pUI = Unk_MgGetDialog<UIMicroGameCoupleDance>(0x4f70);
        if (pUI == 0)
        {
            MS2_ASSERT_AT(0x420, 0);
            pRider->vfunc_59(1, 0, 0, 0);
            return false;
        }
        pUI->FUN_140b8be30(m_aStages[m_nStage]);
        pUI->FUN_140e641d0(0, 0);
    }
    return true;
}

// @0x140b8a910
// MS2-FUNCTIONAL: the string temporaries of the message chain differ from the exe
bool StateMicroGameCoupleDance::FUN_140b8a910()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
    {
        MS2_ASSERT_AT(0x478, 0);
        return false;
    }
    if (FUN_1417b7e40() != 0xae)
    {
        MS2_ASSERT_AT(0x47e, 0);
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    MS2Ptr<Unk_MgDanceEvent> spEvent = FUN_140302b00()->FUN_1403ed140()->FUN_140428700();
    if (spEvent == 0)
    {
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    if (m_spDance == 0)
    {
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    Unk_MgDanceText* pText;
    if (m_spDance->m_b1c == 0)
        pText = spEvent->FUN_140402080(5);
    else
        pText = spEvent->FUN_140402080(4);
    UIMicroGameCoupleDanceMessage* pMessage = Unk_MgGetDialog<UIMicroGameCoupleDanceMessage>(0x4f72);
    if (pMessage != 0)
        pMessage->FUN_140e65c00(FUN_140298ea0(CStringW(pText->m_strMessage)), 3000);
    m_spDance->m_str = (const wchar_t*)pText->m_strAnim;
    efd::utf8string kAnim((const char*)FUN_1409a2360(m_spDance->m_str, 0));
    m_pOwner->FUN_14166dd20(kAnim, 1.0f, false, false);
    m_nDeadline = FUN_140869420() + 3000;
    return true;
}

// @0x140b8acc0
// MS2-FUNCTIONAL: the string temporaries of the message chain differ from the exe
bool StateMicroGameCoupleDance::FUN_140b8acc0()
{
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
    {
        MS2_ASSERT_AT(0x4a1, 0);
        return false;
    }
    if (FUN_1417b7e40() != 0xaf)
    {
        MS2_ASSERT_AT(0x4a7, 0);
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    MS2Ptr<Unk_MgDanceEvent> spEvent = FUN_140302b00()->FUN_1403ed140()->FUN_140428700();
    if (spEvent == 0)
    {
        pRider->vfunc_59(1, 0, 0, 0);
        return false;
    }
    Unk_MgDanceText* pText;
    if (m_nScore < spEvent->m_nMinScore)
        pText = spEvent->FUN_140402080(6);
    else
        pText = spEvent->FUN_140402080(7);
    UIMicroGameCoupleDanceMessage* pMessage = Unk_MgGetDialog<UIMicroGameCoupleDanceMessage>(0x4f72);
    if (pMessage != 0)
        pMessage->FUN_140e65c00(FUN_140298ea0(CStringW(pText->m_strMessage)), 3000);
    m_spDance->m_str = (const wchar_t*)pText->m_strAnim;
    efd::utf8string kAnim((const char*)FUN_1409a2360(m_spDance->m_str, 0));
    m_pOwner->FUN_14166dd20(kAnim, 1.0f, false, false);
    m_nDeadline = FUN_140869420() + 3000;
    return true;
}

// @0x140b8b020
void StateMicroGameCoupleDance::FUN_140b8b020(const std::vector<int>& aStages)
{
    m_aStages.clear();
    m_aStages.assign(aStages.begin(), aStages.end());
    m_nStage = 0;
    m_nDeadline = 0;
    m_nScore = 0;
}

// The notice text of a failed couple dance request.
// @0x140b8b0b0
CStringW FUN_140b8b0b0(__int64 nActorId, int nWhy)
{
    CStringW strPartner(L"");
    PCBase* pPartner = FUN_1403ed2d0()->FUN_141bd1530(nActorId);
    if (pPartner != 0)
        strPartner = pPartner->vfunc_77();
    CStringW strMessage(L"");
    if (nWhy == 0)
        strMessage = FUN_1405c2690(CStringW(L"s_microgame_couple_dance_request_failed_peer_wrong_state"), strPartner);
    else if (nWhy == 1)
        strMessage = FUN_1405c2690(CStringW(L"s_microgame_couple_dance_request_failed_blocked_in_this_field"), strPartner);
    else if (nWhy == 2)
        strMessage = FUN_1405c2690(CStringW(L"s_microgame_couple_dance_accept_failed_peer_wrong_state"), strPartner);
    else if (nWhy == 3)
        strMessage = FUN_1405c2690(CStringW(L"s_microgame_couple_dance_banner_failed_blocked_in_this_field"), strPartner);
    else
        strMessage = FUN_1405c2690(CStringW(L"s_microgame_couple_dance_failed"), strPartner);
    return strMessage;
}

// ---- helpers shared by the Rps state ----

// The effect movie of a rps result.
// @0x140b8b470
CString FUN_140b8b470(int nResult)
{
    if (nResult == 0)
        return CString("Emo_rpsgame_rock.swf");
    else if (nResult == 1)
        return CString("Emo_rpsgame_paper.swf");
    else if (nResult == 2)
        return CString("Emo_rpsgame_scissors.swf");
    else
        return CString("");
}

// The card an actor played (-1: none / not in the rps state).
// @0x140b8b540
// MS2-FUNCTIONAL: branch layout of the null guards differs from the exe
int FUN_140b8b540(PCBase* pActor)
{
    if (pActor == 0)
        return -1;
    if (pActor->FUN_14166c930() == 0x3c)
    {
        StateMicroGameRps* pState = static_cast<StateMicroGameRps*>(pActor->FUN_14166ccb0());
        if (pState == 0)
        {
            MS2_ASSERT_AT(0x2c, 0);
            return -1;
        }
        return pState->FUN_140b871c0();
    }
    return -1;
}

// @0x140b8be10
int StateMicroGameCoupleDance::vfunc_1()
{
    return 0x45;
}

// @0x140b8be20
int StateMicroGameRps::vfunc_1()
{
    return 0x3c;
}

// @0x140b8bd10
MS2Ptr<StateData> StateMicroGameCoupleDance::vfunc_27()
{
    return MS2Ptr<StateData>(new StateMicroGameCoupleDanceData(0));
}

// @0x140b8bd90
MS2Ptr<StateData> StateMicroGameRps::vfunc_27()
{
    return MS2Ptr<StateData>(new StateMicroGameRpsData(0));
}

// Shared header statics: this TU's .text$di initializers and their atexit thunks (gap2 orphan di sweep).
// MS2-RANGE: 0x1400c9240-0x1400c93b0 .text$di
// MS2-RANGE: 0x142ca1210-0x142ca12a0 .text$yd
#include "ms2/placeholder/header_statics_a.h"
