// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CCashCallManager: see ms2/placeholder/ccashcallmanager.h.
// MS2-UNIT: ?\cashcallmanager.cpp
// MS2-RANGE: 0x140b03040-0x140b04a50 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cashcallmanager.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include <new>
#include <afxdialogex.h>
#include "ms2/placeholder/ccashcallmanager.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/statecashcalldata.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/uiservice.h"

// ---- unit-local views of exe objects ----

// The world service (FUN_1403ed2d0): the local player and the current field.
class Unk_CcWorld : public WorldService
{
public:
    MyPC* FUN_141bd0cc0();                                      // the local player
};
void FUN_140d73bc0(int nId, int a, void* b, CStringW strText);  // show a notice by id

// the ids of the cash call items the player may use
extern ATL::CAtlArray<unsigned int> DAT_143ab3058;
class Unk_CcConfig { public: unsigned char FUN_14036e5b0(); };
class CFeatureManager { public: bool FUN_14036d570(int nFeature); };   // C3: unit-local view
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
CGameRule* FUN_1401c0d90();
// A 16-byte item handle.
struct Unk_CcHandle
{
    void* m_p0;
    void* m_p8;
    ~Unk_CcHandle() { FUN_1401bfde0(this); }
    static void FUN_1401bfde0(Unk_CcHandle* p);
};
class Unk_CcInventory { public: Unk_CcHandle FUN_140a5e040(int nSlot); int FUN_140a5f7b0(int nSlot, int n); };
class Unk_Inventory;
extern Unk_Inventory g_143ab2a90;   // C3: the real global (0x143ab2a90); read through Unk_CcInventory
void FUN_140692c90(Unk_CcHandle* pDst, const Unk_CcHandle& src);
__int64 FUN_14052cd70(Unk_CcHandle* p);
void* FUN_1401c0180(Unk_CcHandle* p);
class CItem   // C3: member view for the former free stand-ins
{
public:
    __int64 GetItemUid();
};
__int64 FUN_140930240();
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
__int64* FUN_1402c05b0(char* p);
unsigned char FUN_140930b10();
extern int DAT_1439f4a7c;

// @0x140b03040
CCashCallManager::CCashCallManager()
{
}

// @0x140b03080
CCashCallManager::~CCashCallManager()
{
}

// @0x140b030b0
int CCashCallManager::FUN_140b030b0(int nCallType)
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (pPC->FUN_14166ce30() != 0)
        return 0;
    if (pPC->FUN_14166c930() == 0x25 || pPC->FUN_14166c930() == 0x2a)
        return 0;
    bool bOwned = false;
    for (unsigned i = 0; i < DAT_143ab3058.GetCount(); i++)
    {
        if (nCallType == DAT_143ab3058[i])
        {
            bOwned = true;
            break;
        }
    }
    __int64 nItemUid = 0;
    int nKind = 1;
    if (((class PC*)(class MyPC*)(pPC))->FUN_141662de0() != 0 && ((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x57) != 0)
    {
        nKind = 2;
    }
    else if (bOwned)
    {
        if (FUN_1401c0d90()->IsFreeAirTaxiActive() == 0)
        {
            Unk_CcHandle hItem = reinterpret_cast<Unk_CcInventory&>(g_143ab2a90).FUN_140a5e040(10);
            if (reinterpret_cast<MS2Ptr<CItem>*>(&hItem)->operator==(0))
                FUN_140692c90(&hItem, reinterpret_cast<Unk_CcInventory&>(g_143ab2a90).FUN_140a5e040(0xb));
            if (FUN_14052cd70(&hItem) != 0)
            {
                nItemUid = ((class CItem*)(void*)(FUN_1401c0180(&hItem)))->GetItemUid();
                nKind = 2;
            }
        }
        else
        {
            nKind = 2;
        }
    }
    else
    {
        int nNeed = 3;
        if (((class Unk_CcConfig*)FUN_140166410())->FUN_14036e5b0() != 0)
            nNeed = 1;
        int nHave = reinterpret_cast<Unk_CcInventory&>(g_143ab2a90).FUN_140a5f7b0(0xb, 0);
        if (nHave >= nNeed)
        {
            Unk_CcHandle hItem = reinterpret_cast<Unk_CcInventory&>(g_143ab2a90).FUN_140a5e040(0xb);
            if (reinterpret_cast<MS2Ptr<CItem>*>(&hItem)->operator==(0))
                return 0;
            nItemUid = ((class CItem*)(void*)(FUN_1401c0180(&hItem)))->GetItemUid();
            nKind = 2;
        }
        else
        {
            if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0x83) != 0)
            {
                if (FUN_140930240() < *FUN_1402c05b0(((char*)FUN_1401d3200()) + 0x8aa8))
                    return 0;
                nKind = 3;
            }
            else
            {
                return 0;
            }
        }
    }
    if (pPC->FUN_1416764d0() != 0)
    {
        MS2Ptr<RideOffActionCashCall> spAction(new RideOffActionCashCall(0));
        spAction->m_n28 = nCallType;
        spAction->m_n2c = nKind;
        spAction->m_n30 = nItemUid;
        pPC->SendRequestRideMode1(spAction.get());
    }
    else
    {
        if (pPC->FUN_141527160(0x2a) == 0)
            return 0;
        NiPoint3 kRot = pPC->vfunc_20();
        pPC->FUN_14166d970(kRot);
        pPC->vfunc_59(0x2a, new StateCashCallData(nKind, nItemUid, nCallType), 0, 0);
    }
    return 1;
}

// @0x140b03590
int CCashCallManager::FUN_140b03590(__int64 nItemUid)
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (pPC->FUN_14166ce30() != 0)
    {
        FUN_140d73bc0(0x95, 0, 0, CStringW(L""));
        return 0;
    }
    if (pPC->FUN_14166c930() == 0x25 || pPC->FUN_14166c930() == 0x2a)
    {
        FUN_140d73bc0(0x95, 0, 0, CStringW(L""));
        return 0;
    }
    if (((class PC*)(class MyPC*)(pPC))->FUN_141661aa0() <= 0)
    {
        FUN_140d73bc0(0x96, 0, 0, CStringW(L""));
        return 0;
    }
    if (((class Unk_CcWorld*)WorldService::GetInstance())->FUN_141bd30a0()->FUN_140375410() == 0)
    {
        FUN_140d73bc0(0x94, 0, 0, CStringW(L""));
        return 0;
    }
    int nKind = 5;
    if (pPC->FUN_1416764d0() != 0)
    {
        MS2Ptr<RideOffActionCashCall> spAction(new RideOffActionCashCall(0));
        spAction->m_n2c = nKind;
        spAction->m_n30 = nItemUid;
        pPC->SendRequestRideMode1(spAction.get());
    }
    else
    {
        if (pPC->FUN_141527160(0x2a) == 0)
        {
            FUN_140d73bc0(0x97, 0, 0, CStringW(L""));
            return 0;
        }
        NiPoint3 kRot = pPC->vfunc_20();
        pPC->FUN_14166d970(kRot);
        pPC->vfunc_59(0x2a, new StateCashCallData(nKind, nItemUid, 0), 0, 0);
    }
    return 1;
}

// @0x140b03980
int CCashCallManager::FUN_140b03980(__int64 nItemUid)
{
    if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4e97))) != 0)
    {
        FUN_140d73bc0(0x9c, 0, 0, CStringW(L""));
        return 0;
    }
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (pPC->FUN_14166ce30() != 0)
    {
        FUN_140d73bc0(0x9a, 0, 0, CStringW(L""));
        return 0;
    }
    if (pPC->FUN_14166c930() == 0x25 || pPC->FUN_14166c930() == 0x2a)
    {
        FUN_140d73bc0(0x9a, 0, 0, CStringW(L""));
        return 0;
    }
    if (((class Unk_CcWorld*)WorldService::GetInstance())->FUN_141bd30a0()->FUN_140375450() == 0)
    {
        FUN_140d73bc0(0x99, 0, 0, CStringW(L""));
        return 0;
    }
    int nKind = 4;
    if (pPC->FUN_1416764d0() != 0)
    {
        MS2Ptr<RideOffActionCashCall> spAction(new RideOffActionCashCall(0));
        spAction->m_n2c = nKind;
        spAction->m_n30 = nItemUid;
        pPC->SendRequestRideMode1(spAction.get());
    }
    else
    {
        if (pPC->FUN_141527160(0x2a) == 0)
        {
            FUN_140d73bc0(0x9b, 0, 0, CStringW(L""));
            return 0;
        }
        NiPoint3 kRot = pPC->vfunc_20();
        pPC->FUN_14166d970(kRot);
        pPC->vfunc_59(0x2a, new StateCashCallData(nKind, nItemUid, 0), 0, 0);
    }
    return 1;
}

// @0x140b03d70
int CCashCallManager::FUN_140b03d70(__int64 nItemUid)
{
    if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4e47))) != 0)
    {
        FUN_140d73bc0(0x9e, 0, 0, CStringW(L""));
        return 0;
    }
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (pPC->FUN_14166ce30() != 0)
    {
        FUN_140d73bc0(0x9d, 0, 0, CStringW(L""));
        return 0;
    }
    if (pPC->FUN_14166c930() == 0x25 || pPC->FUN_14166c930() == 0x2a)
    {
        FUN_140d73bc0(0x9d, 0, 0, CStringW(L""));
        return 0;
    }
    int nKind = 6;
    if (pPC->FUN_1416764d0() != 0)
    {
        MS2Ptr<RideOffActionCashCall> spAction(new RideOffActionCashCall(0));
        spAction->m_n2c = nKind;
        spAction->m_n30 = nItemUid;
        pPC->SendRequestRideMode1(spAction.get());
    }
    else
    {
        if (pPC->FUN_141527160(0x2a) == 0)
        {
            FUN_140d73bc0(0x9f, 0, 0, CStringW(L""));
            return 0;
        }
        NiPoint3 kRot = pPC->vfunc_20();
        pPC->FUN_14166d970(kRot);
        pPC->vfunc_59(0x2a, new StateCashCallData(nKind, nItemUid, 0), 0, 0);
    }
    return 1;
}

// MS2-FUNCTIONAL: the limit sum adds nA into nCount (add ecx,edx) in the exe; every spelling tried adds nCount into nA
// @0x140b040a0
int CCashCallManager::FUN_140b040a0(int nCount)
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (pPC->FUN_14166ce30() != 0)
    {
        FUN_140d73bc0(0xb57, 0, 0, CStringW(L""));
        return 0;
    }
    if (pPC->FUN_14166c930() == 0x2c)
    {
        FUN_140d73bc0(0xb57, 0, 0, CStringW(L""));
        return 0;
    }
    if (pPC->FUN_14166c930() != 1 || pPC->FUN_141675ed0() != 0)
    {
        FUN_140d73bc0(0xb59, 0, 0, CStringW(L""));
        return 0;
    }
    if (DAT_1439f4a7c == 0)
    {
        FUN_140d73bc0(0xb58, 0, 0, CStringW(L""));
        return 0;
    }
    if (FUN_140930b10() != 0)
    {
        FUN_140d73bc0(0xb58, 0, 0, CStringW(L""));
        return 0;
    }
    if (((class Unk_CcWorld*)WorldService::GetInstance())->FUN_141bd30a0()->FUN_140375490() == 0)
    {
        FUN_140d73bc0(0xb58, 0, 0, CStringW(L""));
        return 0;
    }
    int nLimit = ((class Unk_CcWorld*)WorldService::GetInstance())->FUN_141bd30a0()->vfunc_2();
    if (nLimit > 0)
    {
        int nA = ((class Unk_CcWorld*)WorldService::GetInstance())->FUN_141bc2bc0();
        if (((class Unk_CcWorld*)WorldService::GetInstance())->FUN_141bc2b30() + (nA + nCount) > nLimit)
        {
            FUN_140d73bc0(0xb5f, 0, 0, CStringW(L""));
            return 0;
        }
    }
    return 1;
}

// @0x140b04430
int CCashCallManager::FUN_140b04430(__int64 nTarget, int nCount)
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    if (FUN_140b040a0(nCount) == 0)
        return 0;
    if (pPC->FUN_1416764d0() != 0)
    {
        MS2Ptr<RideOffActionRecall> spAction(new RideOffActionRecall(0));
        spAction->m_n28 = nTarget;
        pPC->SendRequestRideMode1(spAction.get());
    }
    else
    {
        if (pPC->FUN_141527160(0x2c) == 0)
        {
            FUN_140d73bc0(0xb59, 0, 0, CStringW(L""));
            return 0;
        }
        NiPoint3 kRot = pPC->vfunc_20();
        pPC->FUN_14166d970(kRot);
        pPC->vfunc_59(0x2c, new StateRecallData(reinterpret_cast<void*>(nTarget)), 0, 0);
    }
    return 1;
}

// @0x140b04a20
CRuntimeClass* FUN_140b04a20()
{
    return CDialogEx::GetThisClass();
}

MS2_EMIT_CRT_MEMMOVE_S();
