// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMicroGameManagerCli: the TSingleton the client keeps for
// the event micro games, and its packet handler for opcode 0x114 (the two message switches of the rock-paper-scissors
// request / answer flow and of the couple dance request / answer flow). Also holds this unit's copy of the header
// statics (the request / waiting message box tags) and the Delegate<bool(int, const CMsgBoxData&)> instantiation.
// MS2-UNIT: client\ms2\microgamemanagercli.cpp
// MS2-RANGE: 0x1400c8960-0x1400c8b90 .text$di
// MS2-RANGE: 0x140b73c50-0x140b77000 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\microgamemanagercli.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <afxbasepane.h>
#include <new>
#include <vector>

#include "ms2/placeholder/cmicrogamemanagercli.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/statebannerdata.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/statemicrogame.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/client/ms2/uicoupledanceeventdialog.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

// ---- dynamic initializers (.text$di) ----

// The tags of the four message boxes of the micro game requests.
// @0x1400c8960
static CStringW s_strCoupleDanceRequest(L"coupleDanceRequest");
// @0x1400c8990
static CStringW s_strRpsRequest(L"rpsGameRequest");
// @0x1400c89c0
static CStringW s_strCoupleDanceWaiting(L"coupleDanceWaiting");
// @0x1400c89f0
static CStringW s_strRpsWaiting(L"rpsGameWaiting");

// @0x1400c8a20 .. 0x1400c8b40
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/client/ms2/uiservice.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

// The constants table (singleton 0x1401d3200); the slot at +0x3890 holds the countdown of a request box in seconds.
class Unk_McSlot { public: int FUN_14025a620(); void* m_unknown; };
class Unk_McConsts
{
public:
    char m_pad[0x3890];
    Unk_McSlot m_boxSeconds;
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

// The couple dance event (FUN_140428700) as far as the banner handler uses it: the number of its stages.
class Unk_McEvent : public CPtred
{
public:
    char m_pad[0x34 - sizeof(CPtred)];
    int m_nStages;                                                  // +0x34
};
MS2_CHECK_OFFSET(Unk_McEvent, m_nStages, 0x34);
class Unk_McEventHolder { public: MS2Ptr<Unk_McEvent> FUN_140428700(); };
class Unk_McEventService { public: Unk_McEventHolder* FUN_1403ed140(); };

class Unk_McUIMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };

class CBuddyManager   // C3: member view for the former free stand-ins
{
public:
    unsigned int FUN_140ae51b0(__int64);
};
void* FUN_1408e57f0();
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int GetSubSceneId();
};
bool FUN_140164830(const CStringW& strA, const CStringW& strB);    // the strings differ
void FUN_14151f200();                                               // close the message box on top / show the next
MS2Ptr<CMsgBoxData> FUN_14151f820();                                // the message box on top
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                        // show the box
CStringW GetStringCommon(int nStringId);
CStringW BlockFormat(int nStringId);
CStringW FUN_140298ea0(CStringW strKey);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_1412752d0(const CStringW& strKey, int nType);
void FUN_140710590(COutPacket& packet);                             // send
CStringW FUN_140b887d0(__int64 nActorId, int nWhy);                 // statemicrogame.cpp
CStringW FUN_140b8b0b0(__int64 nActorId, int nWhy);
UIRewardNotify* FUN_140938cd0(int nUiType);

bool FUN_140bac700(int nButton, const CMsgBoxData& data);           // the rps waiting box result
bool FUN_140bacda0(int nButton, const CMsgBoxData& data);           // the couple dance waiting box result

// ---- the singleton ----

// @0x140b73c50
CMicroGameManagerCli::CMicroGameManagerCli()
{
}

// @0x140b73c90
CMicroGameManagerCli::~CMicroGameManagerCli()
{
}

// ---- the packet handler ----

bool FUN_140b73d60(void* pThis, int nType, CInPacket& packet);
bool FUN_140b751b0(void* pThis, int nType, CInPacket& packet);
static bool FUN_140b768a0(const CStringW& strTag);
UICoupleDanceEventDialog* FUN_140b769d0(int nId);
Delegate<bool(int, const CMsgBoxData&)> FUN_140b76b10(bool (*pfn)(int, const CMsgBoxData&));

// Opcode 0x114: one of the two switches handles the sub type.
// MS2-FUNCTIONAL: the exe returns the callee's al without a spill.
// @0x140b73cc0
bool FUN_140b73cc0(void* pThis, CInPacket& packet)
{
    unsigned int nType = (unsigned short)packet.ReadInt16();
    bool bHandled = FUN_140b73d60(pThis, nType, packet);
    if (!bHandled)
    {
        bHandled = FUN_140b751b0(pThis, nType, packet);
        if (!bHandled)
        {
            MS2_ASSERT_AT(0x50, 0);
            bHandled = false;
        }
    }
    return bHandled;
}

// Rock-paper-scissors: banner (0), request received (1), answer: accepted (2) / declined (3), cancel (4), the request
// box is stale (5), failed (6), reward list (10), card played (0xb), request sent (0xc).
// @0x140b73d60
bool FUN_140b73d60(void* pThis, int nType, CInPacket& packet)
{
    MyPC* pMyPC = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMyPC == 0)
    {
        MS2_ASSERT_AT(0x58, 0);
        return false;
    }
    switch (nType)
    {
    case 0:
        {
            pMyPC->vfunc_59(0x3b, new StateBannerData(1), 0x97, 0);
        }
        break;
    case 1:
        {
            __int64 nTargetId = packet.ReadInt64();
            PCBase* pTarget = (PCBase*)WorldService::GetInstance()->FUN_141bd1530(nTargetId);
            if (pTarget == 0)
                break;
            if (pMyPC->FUN_14166c930() != 0x3b)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(6);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                break;
            }
            StateBanner* pBanner = (StateBanner*)pMyPC->FUN_14166ccb0();
            if (pBanner == 0)
            {
                MS2_ASSERT_AT(0x78, 0);
                break;
            }
            if (pBanner->FUN_140b7f3b0() != 1)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(6);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                break;
            }
            if (FUN_140b768a0(s_strRpsRequest) == 1)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(6);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                break;
            }
            if (((class CBuddyManager*)(void*)(((void*)TSingleton<CBuddyManager>::GetInstance())))->FUN_140ae51b0(nTargetId) != 0)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(6);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                FUN_141275260(0xd09, 1, 1);
                break;
            }
            if (((class PC*)(class PCBase*)(pMyPC))->FUN_1416595d0() == 1)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(6);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                break;
            }
            if (((class GFxSceneService*)(void*)(FUN_1408e57f0()))->GetSubSceneId() == 0x620001f)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(6);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                break;
            }
            COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
            kPacket.Encode2(0xc);
            kPacket.Encode8(nTargetId);
            FUN_140710590(kPacket);
            const CStringW& strName = pTarget->vfunc_77();
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14052bd00(0xd0e, strName), 0, s_strRpsRequest);
            if (spBox == 0)
            {
                MS2_ASSERT_AT(0xba, 0);
                break;
            }
            spBox->FUN_140b76940(CStringW(strName));
            spBox->FUN_141a01ca0(((class Unk_McConsts*)FUN_1401d3200())->m_boxSeconds.FUN_14025a620(), 1, GetStringCommon(0x2b8));
            spBox->FUN_141a02460(1);
            spBox->FUN_141a024a0(0);
            FUN_140d73c60(spBox);
        }
        break;
    case 0xc:
        {
            __int64 nTargetId = packet.ReadInt64();
            PCBase* pTarget = (PCBase*)WorldService::GetInstance()->FUN_141bd1530(nTargetId);
            if (pTarget == 0)
                break;
            pMyPC->vfunc_59(0x3c, new StateMicroGameRpsData(pTarget->FUN_14123c580()), 0x99, 0);
            CStringW strText = BlockFormat(0xd0d);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(CStringW(strText), 0);
            if (spBox == 0)
            {
                MS2_ASSERT_AT(0xd5, 0);
                break;
            }
            spBox->SetExtra(s_strRpsWaiting);
            spBox->FUN_141a01ca0(((class Unk_McConsts*)FUN_1401d3200())->m_boxSeconds.FUN_14025a620(), 1, GetStringCommon(0x2b8));
            spBox->FUN_141a027c0(FUN_140b76b10(FUN_140bac700));
            spBox->FUN_141a024a0(0);
            spBox->FUN_141a01700(0x476, 0, 0);
            FUN_140d73c60(spBox);
        }
        break;
    case 2:
        {
            __int64 nTargetId = packet.ReadInt64();
            PCBase* pTarget = (PCBase*)WorldService::GetInstance()->FUN_141bd1530(nTargetId);
            if (pTarget == 0)
                break;
            if (FUN_140b768a0(s_strRpsWaiting) == 1)
                FUN_14151f200();
            if (pMyPC->FUN_14166c930() != 0x3c)
                break;
            StateMicroGameRps* pState = (StateMicroGameRps*)pMyPC->FUN_14166ccb0();
            if (pState == 0)
            {
                MS2_ASSERT_AT(0xf3, 0);
                break;
            }
            if (pMyPC->FUN_14166cc80() != 0x99)
                break;
            if (pState->FUN_140b872c0() != pTarget->FUN_14123c580())
                break;
            FUN_141275260(0xd10, 1, 1);
        }
        break;
    case 3:
        {
            __int64 nTargetId = packet.ReadInt64();
            PCBase* pTarget = (PCBase*)WorldService::GetInstance()->FUN_141bd1530(nTargetId);
            if (pTarget == 0)
                break;
            if (FUN_140b768a0(s_strRpsWaiting) == 1)
                FUN_14151f200();
            if (pMyPC->FUN_14166c930() != 0x3c)
                break;
            StateMicroGameRps* pState = (StateMicroGameRps*)pMyPC->FUN_14166ccb0();
            if (pState == 0)
            {
                MS2_ASSERT_AT(0x111, 0);
                break;
            }
            if (pState->FUN_140b872c0() != pTarget->FUN_14123c580())
                break;
            pMyPC->vfunc_59(1, 0, 0, 0);
            CStringW strText = FUN_14052bd00(0xd0f, pTarget->vfunc_77());
            FUN_1412751f0(strText, 1, 1);
        }
        break;
    case 4:
        {
            if (pMyPC->FUN_14166c930() != 0x3c)
                break;
            StateMicroGameRps* pState = (StateMicroGameRps*)pMyPC->FUN_14166ccb0();
            if (pState == 0)
            {
                MS2_ASSERT_AT(0x128, 0);
                break;
            }
            pState->FUN_140b876a0();
        }
        break;
    case 5:
        {
            __int64 nTargetId = packet.ReadInt64();
            PCBase* pTarget = (PCBase*)WorldService::GetInstance()->FUN_141bd1530(nTargetId);
            if (pTarget == 0)
                break;
            MS2Ptr<CMsgBoxData> spBox = FUN_14151f820();
            if (spBox == 0)
                break;
            if (FUN_140164830(spBox->GetExtra(), s_strRpsRequest))
                break;
            CStringW strRequester;
            if (!spBox->FUN_140b76a70(0, strRequester))
                break;
            if (strRequester != pTarget->vfunc_77())
                break;
            FUN_14151f200();
            FUN_141275260(0xd04, 1, 1);
        }
        break;
    case 6:
        {
            __int64 nActorId = packet.ReadInt64();
            unsigned int nWhy = packet.ReadUInt8();
            CStringW strMessage = FUN_140b887d0(nActorId, nWhy);
            FUN_1412751f0(strMessage, 1, 1);
            if (FUN_140b768a0(s_strRpsWaiting) == 1)
                FUN_14151f200();
            if (FUN_140b768a0(s_strRpsRequest) == 1)
                FUN_14151f200();
            if (pMyPC->FUN_14166c930() != 0x3c)
                break;
            StateMicroGameRps* pState = (StateMicroGameRps*)pMyPC->FUN_14166ccb0();
            if (pState == 0)
                break;
            PCBase* pPartner = pState->FUN_140b879d0();
            if (pPartner == 0)
                break;
            if (pPartner->FUN_141656a80() != nActorId)
                break;
            pMyPC->vfunc_59(1, 0, 0, 0);
        }
        break;
    case 0xb:
        {
            unsigned int nMode = packet.ReadUInt8();
            unsigned int nCard = packet.ReadUInt8();
            unsigned int nPick = packet.ReadUInt8();
            if (pMyPC->FUN_14166c930() != 0x3c)
                break;
            StateMicroGameRps* pState = (StateMicroGameRps*)pMyPC->FUN_14166ccb0();
            if (pState == 0)
            {
                MS2_ASSERT_AT(0x174, 0);
                break;
            }
            pState->FUN_140b87310(nMode, nCard, nPick);
        }
        break;
    case 10:
        {
            UIRewardNotify* pNotify = FUN_140938cd0(0x4e5d);
            if (pNotify == 0)
                break;
            int nCount = packet.ReadInt32();
            for (int i = 0; i < nCount; i = i + 1)
            {
                int nItemId = packet.ReadInt32();
                unsigned int nGrade = (unsigned short)packet.ReadInt16();
                pNotify->FUN_141abf6e0(nItemId, nGrade);
            }
        }
        break;
    default:
        return false;
    }
    return true;
}

// Couple dance: banner (0xd), request received (0xe), accepted (0xf), request sent (0x10), declined (0x11), start
// (0x12), request cancelled (0x13), failed (0x14), answer (0x16).
// @0x140b751b0
bool FUN_140b751b0(void* pThis, int nType, CInPacket& packet)
{
    MyPC* pMyPC = static_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pMyPC == 0)
    {
        MS2_ASSERT_AT(0x197, 0);
        return false;
    }
    int nValue = packet.ReadInt32();
    switch (nType)
    {
    case 0xd:
        pMyPC->vfunc_59(0x3b, new StateBannerData(2), 0x97, 0);
        break;
    case 0xe:
        {
            __int64 nTargetId = packet.ReadInt64();
            PCBase* pTarget = (PCBase*)WorldService::GetInstance()->FUN_141bd1530(nTargetId);
            if (pTarget == 0)
                break;
            if (pMyPC->FUN_14166c930() != 0x3b)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(0x14);
                kPacket.Encode4(nValue);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                break;
            }
            StateBanner* pBanner = dynamic_cast<StateBanner*>(pMyPC->FUN_14166ccb0());
            if (pBanner == 0)
            {
                MS2_ASSERT_AT(0x1ba, 0);
                break;
            }
            if (pBanner->FUN_140b7f3b0() != 2)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(0x14);
                kPacket.Encode4(nValue);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                break;
            }
            if (FUN_140b768a0(s_strCoupleDanceRequest) == 1)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(0x14);
                kPacket.Encode4(nValue);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                break;
            }
            if (((class CBuddyManager*)(void*)(((void*)TSingleton<CBuddyManager>::GetInstance())))->FUN_140ae51b0(nTargetId) != 0)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(0x14);
                kPacket.Encode4(nValue);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                FUN_1412752d0(L"s_microgame_couple_dance_response_failed_blocked_user", 1);
                break;
            }
            if (((class PC*)(class PCBase*)(pMyPC))->FUN_1416595d0() == 1)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(0x14);
                kPacket.Encode4(nValue);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                break;
            }
            if (((class GFxSceneService*)(void*)(FUN_1408e57f0()))->GetSubSceneId() == 0x620001f)
            {
                COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
                kPacket.Encode2(0x14);
                kPacket.Encode4(nValue);
                kPacket.Encode8(nTargetId);
                kPacket.Encode1(0);
                FUN_140710590(kPacket);
                break;
            }
            COutPacket kPacket(static_cast<int>(SendOp::Microgame), 0);
            kPacket.Encode2(0x10);
            kPacket.Encode4(nValue);
            kPacket.Encode8(nTargetId);
            FUN_140710590(kPacket);
            const CStringW& strName = pTarget->vfunc_77();
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_1405c2690(L"s_microgame_couple_dance_request_recv", strName), 0, s_strCoupleDanceRequest);
            if (spBox == 0)
            {
                MS2_ASSERT_AT(0x202, 0);
                break;
            }
            spBox->FUN_140534050(nValue);
            spBox->FUN_1405340b0(nTargetId);
            spBox->FUN_141a01ca0(((class Unk_McConsts*)FUN_1401d3200())->m_boxSeconds.FUN_14025a620(), 1, GetStringCommon(0x2b8));
            spBox->FUN_141a02460(1);
            spBox->FUN_141a024a0(0);
            FUN_140d73c60(spBox);
        }
        break;
    case 0x10:
        {
            __int64 nTargetId = packet.ReadInt64();
            PCBase* pTarget = (PCBase*)WorldService::GetInstance()->FUN_141bd1530(nTargetId);
            if (pTarget == 0)
                break;
            pMyPC->vfunc_59(0x45, new StateMicroGameCoupleDanceData(pTarget->FUN_14123c580()), 0xa9, 0);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(FUN_140298ea0(L"s_microgame_couple_dance_waiting"), 0);
            if (spBox == 0)
            {
                MS2_ASSERT_AT(0x21c, 0);
                break;
            }
            spBox->SetExtra(s_strCoupleDanceWaiting);
            spBox->FUN_141a01ca0(((class Unk_McConsts*)FUN_1401d3200())->m_boxSeconds.FUN_14025a620(), 1, GetStringCommon(0x2b8));
            spBox->FUN_141a027c0(FUN_140b76b10(FUN_140bacda0));
            spBox->FUN_141a024a0(0);
            spBox->FUN_141a01700(0x476, 0, 0);
            FUN_140d73c60(spBox);
        }
        break;
    case 0xf:
        {
            __int64 nTargetId = packet.ReadInt64();
            if (FUN_140b768a0(s_strRpsWaiting) == 1)
                FUN_14151f200();
            PCBase* pTarget = (PCBase*)WorldService::GetInstance()->FUN_141bd1530(nTargetId);
            if (pTarget == 0)
                break;
            if (pMyPC->FUN_14166c930() != 0x45)
                break;
            StateMicroGameCoupleDance* pState = dynamic_cast<StateMicroGameCoupleDance*>(pMyPC->FUN_14166ccb0());
            if (pState == 0)
            {
                MS2_ASSERT_AT(0x23a, 0);
                break;
            }
            if (pMyPC->FUN_14166cc80() != 0xa9)
                break;
            if (pState->FUN_140b894c0() != pTarget->FUN_14123c580())
                break;
            FUN_1412752d0(L"s_microgame_couple_dance_response_accept", 1);
        }
        break;
    case 0x11:
        {
            __int64 nTargetId = packet.ReadInt64();
            PCBase* pTarget = (PCBase*)WorldService::GetInstance()->FUN_141bd1530(nTargetId);
            if (pTarget == 0)
                break;
            if (FUN_140b768a0(s_strCoupleDanceWaiting) == 1)
                FUN_14151f200();
            if (pMyPC->FUN_14166c930() != 0x45)
                break;
            StateMicroGameCoupleDance* pState = dynamic_cast<StateMicroGameCoupleDance*>(pMyPC->FUN_14166ccb0());
            if (pState == 0)
            {
                MS2_ASSERT_AT(600, 0);
                break;
            }
            if (pState->FUN_140b894c0() != pTarget->FUN_14123c580())
                break;
            pMyPC->vfunc_59(1, 0, 0, 0);
            FUN_1412751f0(FUN_1405c2690(L"s_microgame_couple_dance_response_decline", pTarget->vfunc_77()), 1, 1);
        }
        break;
    case 0x13:
        {
            __int64 nTargetId = packet.ReadInt64();
            MS2Ptr<CMsgBoxData> spBox = FUN_14151f820();
            if (spBox == 0)
                break;
            if (FUN_140164830(spBox->GetExtra(), s_strCoupleDanceRequest))
                break;
            int nFirst = 0;
            if (!spBox->FUN_140961900(0, nFirst))
                break;
            if (nValue != nFirst)
                break;
            __int64 nRequester;
            if (!spBox->FUN_140b19130(1, nRequester))
                break;
            if (nRequester != nTargetId)
                break;
            FUN_14151f200();
            FUN_1412752d0(L"s_microgame_couple_dance_request_cancel", 1);
        }
        break;
    case 0x12:
        {
            if (pMyPC->FUN_14166c930() != 0x45)
                break;
            UICoupleDanceEventDialog* pPane = (UICoupleDanceEventDialog*)FUN_140b769d0(0x4f71);
            if (pPane != 0 && pPane->FUN_141924630() != 0)
                pPane->vfunc_67();
            StateMicroGameCoupleDance* pState = dynamic_cast<StateMicroGameCoupleDance*>(pMyPC->FUN_14166ccb0());
            if (pState == 0)
            {
                MS2_ASSERT_AT(0x29c, 0);
                break;
            }
            MS2Ptr<Unk_McEvent> spEvent = reinterpret_cast<Unk_McEventService*>(TSingleton<CGameEventValueManager>::GetInstance())->FUN_1403ed140()->FUN_140428700();
            if (spEvent == 0)
            {
                MS2_ASSERT_AT(0x2a2, 0);
                break;
            }
            if (FUN_140b768a0(s_strCoupleDanceWaiting) == 1)
                FUN_14151f200();
            std::vector<int> aStages;
            for (int i = 0; i < spEvent->m_nStages; i = i + 1)
            {
                int nStage = (unsigned short)packet.ReadInt16();
                aStages.push_back(nStage);
            }
            pState->FUN_140b89510(aStages);
        }
        break;
    case 0x16:
        {
            unsigned int nTime = packet.ReadUInt8();
            bool bFlag = packet.ReadUInt8() != 0;
            unsigned int nA = (unsigned short)packet.ReadInt16();
            unsigned int nB = (unsigned short)packet.ReadInt16();
            if (pMyPC->FUN_14166c930() != 0x45)
                break;
            StateMicroGameCoupleDance* pState = dynamic_cast<StateMicroGameCoupleDance*>(pMyPC->FUN_14166ccb0());
            if (pState == 0)
            {
                MS2_ASSERT_AT(0x2c0, 0);
                break;
            }
            pState->FUN_140b89880(nTime, bFlag, nA, nB);
        }
        break;
    case 0x14:
        {
            __int64 nActorId = packet.ReadInt64();
            unsigned int nWhy = packet.ReadUInt8();
            CStringW strMessage = FUN_140b8b0b0(nActorId, nWhy);
            FUN_1412751f0(strMessage, 1, 1);
            if (FUN_140b768a0(s_strCoupleDanceWaiting) == 1)
                FUN_14151f200();
            if (FUN_140b768a0(s_strCoupleDanceRequest) == 1)
                FUN_14151f200();
            if (pMyPC->FUN_14166c930() != 0x45)
                break;
            StateMicroGameCoupleDance* pState = dynamic_cast<StateMicroGameCoupleDance*>(pMyPC->FUN_14166ccb0());
            if (pState == 0)
                break;
            PCBase* pPartner = pState->FUN_140b89dd0();
            if (pPartner == 0)
                break;
            if (pPartner->FUN_141656a80() != nActorId)
                break;
            pMyPC->vfunc_59(1, 0, 0, 0);
        }
        break;
    default:
        return false;
    }
    return true;
}

// The box on top has this tag.
// @0x140b768a0
static bool FUN_140b768a0(const CStringW& strTag)
{
    MS2Ptr<CMsgBoxData> spBox = FUN_14151f820();
    if (spBox == 0)
        return false;
    if (FUN_140164830(spBox->GetExtra(), strTag))
        return false;
    return true;
}

// Appends a string argument.
CStringW FUN_140719900(CStringW str);          // string-argument filter (by value)
CStringW FUN_140718600(const CStringW& str);   // its inverse on read
// @0x140b76940
void CMsgBoxData::FUN_140b76940(CStringW str)
{
    m_args.Add(FUN_140719900(str));
}

// The couple dance event dialog (UI type 0x4f71) if it is open.
// @0x140b769d0
UICoupleDanceEventDialog* FUN_140b769d0(int nId)
{
    if (reinterpret_cast<Unk_McUIMgr*>(TSingleton<CUIService>::GetInstance()))
    {
        MS2Ptr<UIObject> p = reinterpret_cast<Unk_McUIMgr*>(TSingleton<CUIService>::GetInstance())->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UICoupleDanceEventDialog*>((UIObject*)p);
    }
    return 0;
}

// The nIndex-th string argument.
// @0x140b76a70
bool CMsgBoxData::FUN_140b76a70(unsigned int nIndex, CStringW& strOut) const
{
    if (nIndex >= m_args.GetCount())
        return false;
    strOut = FUN_140718600(m_args[nIndex]);
    return true;
}

// ---- Delegate<bool(int, const CMsgBoxData&)> over a free function ----

// MS2-FUNCTIONAL: 0x140b76b10 is the Delegate<bool(int,const CMsgBoxData&)>(pfn) ctor itself (our ctor COMDAT matches it
//   byte-exact); this free-function name (imported by 5 units, same rcx=ret/rdx=pfn ABI) only forwards to that ctor
// @0x140b76b10
Delegate<bool(int, const CMsgBoxData&)> FUN_140b76b10(bool (*pfn)(int, const CMsgBoxData&))
{
    return Delegate<bool(int, const CMsgBoxData&)>(pfn);
}

// @0x140b76ee0
MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca0ea0-0x142ca0fb0 .text$yd
