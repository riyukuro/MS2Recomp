// uiworldshareinfoeventlistener.cpp - UIWorldShareInfoEventListener (the 8-byte interface the world-share widgets
// implement) and the UIWorldShareInfoEventDispatcher singleton that fans the events out to the registered listeners
// (CAtlArray<void*> at +8). The rest of the range is the CAtlArray<void*> block the link took from this file and the
// "you got N experience / tokens" chat-message builders (named by VA) that follow it.
// MS2-UNIT: ?\uiworldshareinfoeventlistener.cpp
// MS2-RANGE: 0x14135fc40-0x141361c50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x14135fee0 ; unique
// MS2-PIN: ??1?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x14135ff50 ; unique
// MS2-PIN: ?CallConstructors@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@CAXPEAPEAX_K@Z 0x141360120 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@CAXPEAPEAX_K@Z 0x141360190 ; unique
// MS2-PIN: ??A?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAAEAPEAX_K@Z 0x1413601d0 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@AEAA_N_K@Z 0x141360220 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@PEAX@ATL@@SAXPEAPEAX0_K@Z 0x1413603e0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAXXZ 0x141360420 ; unique
// MS2-PIN: ?RemoveAt@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAX_K0@Z 0x141360440 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA_N_KH@Z 0x141360530 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetCount@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEBA_KXZ 0x141360210
// MS2-PIN: ?Add@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA_KPEAX@Z 0x141360070
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiworldshareinfoeventlistener.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/uiworldshareinfoeventdispatcher.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/ms2recover.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types / functions ----

class PCBase;
struct Unk_WsWorld;
struct Unk_WsConstUInt;
struct Unk_WsConstants
{
    unsigned char m_unrecovered[0x5910];
    Unk_WsConstUInt* m_unused;                       // placeholder, the two fields below are at +0x5910 / +0x5968
};
class Unk_WsStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };

Unk_WsWorld* FUN_1403ed2d0();
unsigned FUN_141bd3060(Unk_WsWorld* pWorld);                                // the local player's level
PCBase* FUN_141bd0cc0(Unk_WsWorld* pWorld);                                 // the local player
unsigned char FUN_141658fa0(PCBase* pPC);
Unk_WsStrings* FUN_1401a9d70();
void* FUN_1401c0d90();
int FUN_140475e80(int nType);
unsigned int FUN_140476ad0(void* pRule);
unsigned char* FUN_1401d3200();                                             // the constants block
unsigned* FUN_1401d7c10(void* pConstant);
CStringW FUN_1409404f0(__int64 n);                                          // the number as text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_14052bd00(int nId, const CStringW& strArg);
CStringW FUN_140632a60(int nId, const CStringW& strArg1, const CStringW& strArg2);
CStringW FUN_140298ea0(CStringW strKey);
CStringW GetStringCommon(int nId);
CStringW FUN_1409eec40(int nId);
CStringW FUN_140c160b0(CStringW strKey, const __int64& n);
CStringW FUN_14086d060(int nId, const __int64& n);
void FUN_1412751b0(const CStringW& strText, int nColor);                    // add a chat message
UIRewardNotify* FUN_140938cd0(int nId);
bool FUN_1406a5720();
void* FUN_140166410();
unsigned char FUN_14036d570(void* pFeatures, int nId);

// @0x14135fc40
UIWorldShareInfoEventListener::UIWorldShareInfoEventListener()
{
}

// @0x14135fc60
UIWorldShareInfoEventListener::~UIWorldShareInfoEventListener()
{
}

// @0x14135fc80
UIWorldShareInfoEventDispatcher::UIWorldShareInfoEventDispatcher() : m_listeners()
{
}

// @0x14135fcd0
UIWorldShareInfoEventDispatcher::~UIWorldShareInfoEventDispatcher()
{
    m_listeners.RemoveAll();
}

// MS2-FUNCTIONAL: the exe's CAtlArray<void*>::Add takes the element by reference (older ATL); ours takes it by value
// @0x14135fd20
void UIWorldShareInfoEventDispatcher::FUN_14135fd20(UIWorldShareInfoEventListener* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        if (pListener == m_listeners[i])
            return;
    }
    m_listeners.Add(pListener);
}

// @0x14135fdb0
void UIWorldShareInfoEventDispatcher::FUN_14135fdb0(UIWorldShareInfoEventListener* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        if (pListener == m_listeners[i])
        {
            m_listeners.RemoveAt(i, 1);
            return;
        }
    }
}

// @0x14135fe40
void UIWorldShareInfoEventDispatcher::vfunc_1(__int64 n, int a, int b)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        UIWorldShareInfoEventListener* p = reinterpret_cast<UIWorldShareInfoEventListener*>(m_listeners[i]);
        if (p != 0)
            p->vfunc_1(n, a, b);
    }
}

// @0x1413603c0
void UIWorldShareInfoEventListener::vfunc_1(__int64, int, int)
{
}

// ---- the "you got N experience" chat messages ----

// @0x1413606c0
void FUN_1413606c0(__int64 nAmount, int nType, int nRest, bool bAdditional)
{
    int bNotify = 0;
    CStringW strB;
    CStringW strA;
    CStringW strNum = FUN_1409404f0(nAmount);
    unsigned nLevel = FUN_141bd3060(FUN_1403ed2d0());
    switch (nType)
    {
    case 0xea62:
        strA = FUN_14052bd00(0x2be, strNum);
        strB = FUN_14052bd00(0x2bf, strNum);
        break;
    case 3001:
    case 3002:
        strA = FUN_140632a60(0x2c0, FUN_1401a9d70()->FUN_141811980(3, nLevel), strNum);
        bNotify = 1;
        break;
    case 3000:
        strA = FUN_140632a60(0x2c1, FUN_1401a9d70()->FUN_141811980(3, nLevel), strNum);
        bNotify = 1;
        break;
    case 3003:
        strA = FUN_140632a60(0x2c2, FUN_1401a9d70()->FUN_141811980(3, nLevel), strNum);
        break;
    case 0x427:
        strA = FUN_1405c2690(L"s_msg_take_play_instrument_exp", strNum);
        break;
    case 0x423:
        strA = FUN_1405c2690(L"s_msg_take_fishing_exp", strNum);
        break;
    case 0x42f:
        strA = FUN_1405c2690(L"s_msg_take_arcade_exp", strNum);
        break;
    case 0x443:
        strA = FUN_1405c2690(L"s_msg_take_normal_chest_exp", strNum);
        break;
    case 0x444:
        strA = FUN_1405c2690(L"s_msg_take_normal_rare_exp", strNum);
        break;
    case 0x445:
        strA = FUN_1405c2690(L"s_msg_take_normal_rare_first_exp", strNum);
        break;
    case 3004:
    case 3007:
        strA = FUN_14052bd00(0x2bd, strNum);
        bNotify = 1;
        break;
    default:
        strA = FUN_14052bd00(0x2bd, strNum);
        break;
    }
    if (bAdditional)
        strA += FUN_140298ea0(L"s_msg_take_event_additional");
    FUN_1401c0d90();
    if (FUN_140475e80(nType) != 0)
    {
        PCBase* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pPC != 0)
        {
            if ((FUN_141658fa0(pPC) & *FUN_1401d7c10(FUN_1401d3200() + 0x5910)) != 0 && (nType == 0x15 || nType == 0xea61))
                strA += GetStringCommon(0x2c5);
        }
    }
    if (nRest != 0)
        strA += FUN_140298ea0(L"s_msg_take_rest_exp");
    UIRewardNotify* pNotify;
    if (bNotify != 0 && (pNotify = FUN_140938cd0(0x4e5d)) != 0)
        pNotify->FUN_141abf230(nAmount, 0);
    FUN_1412751b0(strA, 8);
    FUN_1412751b0(strB, 0x14);
}

// @0x1413610f0
void FUN_1413610f0(__int64 nAmount)
{
    CStringW strText = FUN_1405c2690(L"s_msg_take_adventure_level_exp", FUN_1409404f0(nAmount));
    if (FUN_140476ad0(FUN_1401c0d90()) != 0)
        strText += FUN_140298ea0(L"s_msg_take_event_additional");
    FUN_1412751b0(strText, 8);
}

// @0x141361210
void FUN_141361210(__int64 nAmount)
{
    if (nAmount == 0)
        return;
    CStringW strText = FUN_1405c2690(L"s_msg_take_survival_level_exp", FUN_1409404f0(nAmount));
    FUN_1412751b0(strText, 8);
}

// @0x1413612c0
void FUN_1413612c0(__int64 nAmount, int nType)
{
    if (nAmount == 0)
        return;
    if (nAmount > 0)
    {
        CStringW strNum = FUN_1409404f0(nAmount);
        CStringW strText = FUN_14052bd00(0x2c3, strNum);
        PCBase* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pPC != 0)
        {
            if ((FUN_141658fa0(pPC) & *FUN_1401d7c10(FUN_1401d3200() + 0x5968)) != 0 && (nType == 0x15 || nType == 0xea61))
                strText += FUN_14052bd00(0x2c5, strNum);
        }
        FUN_1412751b0(strText, 5);
    }
    else if (nAmount < 0)
    {
        CStringW strNum = FUN_1409404f0(-nAmount);
        CStringW strText = FUN_14052bd00(0x2c4, strNum);
        FUN_1412751b0(strText, 5);
    }
}

// @0x141361460
void FUN_141361460(unsigned nType, __int64 nAmount, int)
{
    if (nAmount <= 0)
        return;
    {
        CStringW strText;
        switch (nType)
        {
        case 6:
            strText = FUN_140c160b0(L"s_msg_take_habi_token", nAmount);
            break;
        case 5:
            strText = FUN_140c160b0(L"s_msg_take_lu_token", nAmount);
            break;
        case 3:
            strText = FUN_140c160b0(L"s_msg_take_honor_token", nAmount);
            break;
        case 4:
            strText = FUN_140c160b0(L"s_msg_take_karma_token", nAmount);
            break;
        case 9:
            strText = FUN_140c160b0(L"s_msg_take_reverse_coin", nAmount);
            break;
        case 10:
            strText = FUN_140c160b0(L"s_msg_take_mentor_token", nAmount);
            break;
        case 11:
            strText = FUN_140c160b0(L"s_msg_take_mentee_token", nAmount);
            break;
        case 12:
            strText = FUN_140c160b0(L"s_msg_take_star_point", nAmount);
            break;
        case 13:
            strText = FUN_14086d060(0x2ce, nAmount);
            break;
        }
        FUN_1412751b0(strText, 7);
    }
}

// MS2-FUNCTIONAL: the exe's stack-temporary layout differs (its frame is 0x20 smaller)
// @0x141361990
void FUN_141361990(__int64 nAmount)
{
    if (nAmount == 0 || !FUN_1406a5720())
        return;
    CStringW strText;
    if (nAmount > 0)
    {
        strText = FUN_14052bd00(0x2c8, FUN_1409404f0(nAmount));
    }
    else if (nAmount < 0)
    {
        strText = FUN_14052bd00(0x2da, FUN_1409404f0(-nAmount));
        if (FUN_14036d570(FUN_140166410(), 0xba) != 0)
            FUN_1412751b0(FUN_1409eec40(0x2db), 6);
    }
    FUN_1412751b0(strText, 6);
}
