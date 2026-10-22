// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See cfieldmaidmanager.h, cusermaidmanager.h.
// MS2-UNIT: ?\maidmanager.cpp
// MS2-RANGE: 0x14127e190-0x141280b40 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\maidmanager.cpp"
#define NOMINMAX
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cfieldmaidmanager.h"
#include "ms2/placeholder/cusermaidmanager.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uihudentity.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The comp pointer's members live in another unit (the pointee is only declared): bind them there.
template<> MS2Ptr<Unk_PCBaseComp_a78>::~MS2Ptr();          // 0x1405a89b0
template<> Unk_PCBaseComp_a78* MS2Ptr<Unk_PCBaseComp_a78>::get() const;     // 0x1405a8ec0
template<> Unk_PCBaseComp_a78* MS2Ptr<Unk_PCBaseComp_a78>::operator->() const;  // 0x1405a8f50
#include "ms2/placeholder/ms2ptr_impl.h"

class UIMaidDialog : public UIObject {};

// ---- out-of-unit callees ----
void* FUN_14025e7c0();                                  // the client's text-hook object
unsigned char FUN_14116d720(void* pHook);
void FUN_140710590(COutPacket& packet);                 // send
void* FUN_1403ed2b0();                                  // the UI service
int FUN_141adc890(void* pService, int nUiId);           // is the dialog open
struct Unk_MaidUIService { MS2Ptr<UIObject> FUN_141adcea0(int nUiId); };   // the dialog's UI object
void* FUN_1403ed2d0();                                  // the world of my character
PCBase* FUN_141bd1320(void* pWorld, int nActorId);
void FUN_1412d9680(UIMaidDialog* pDlg);
void FUN_1412d9b90(UIMaidDialog* pDlg);
void* FUN_140d51900(int nUiId);
void FUN_1412e34c0(void* pDlg);
void FUN_1412e3990(void* pDlg, int n);
void* FUN_140d519a0(int nUiId);
void FUN_1412dc3c0(void* pDlg);

// @0x14127e190
CFieldMaidManager::CFieldMaidManager()
    : m_mapMaid(10)
{
}

// @0x14127e1e0
CFieldMaidManager::~CFieldMaidManager()
{
}

// @0x14127e220
void CFieldMaidManager::RemoveAllMaids()
{
    m_mapMaid.RemoveAll();
}

// @0x14127e250
void CFieldMaidManager::OnPacket(CInPacket* pPacket)
{
    int cMode = pPacket->vfunc_o8_1();
    if (cMode == 0)
    {
        MS2Ptr<CMaid> spMaid(new CMaid);
        spMaid->SetMode(pPacket->vfunc_o8_1());
        spMaid->FUN_14067d730(pPacket);
        m_mapMaid.SetAt(spMaid->m_nId, spMaid);
    }
    else if (cMode == 1)
    {
        unsigned __int64 nId = pPacket->vfunc_o8_4();
        if (m_mapMaid.Lookup(nId) != 0)
            m_mapMaid.RemoveKey(nId);
    }
}

// @0x14127e400
// MS2-FUNCTIONAL: exe tests the Lookup result with jne to the copy-return branch and calls a shared MS2Ptr<CMaid> get; branch order not reproduced
MS2Ptr<CMaid> CFieldMaidManager::GetMaid(unsigned __int64 nId)
{
    MS2Ptr<CMaid> spMaid;
    if (m_mapMaid.Lookup(nId, spMaid))
        return spMaid;
    return MS2Ptr<CMaid>(0);
}

// @0x14127e4b0
CUserMaidManager::CUserMaidManager()
    : m_mapMaid(10)
{
}

// @0x14127e500
CUserMaidManager::~CUserMaidManager()
{
    m_mapMaid.RemoveAll();
}

// @0x14127e550
void CUserMaidManager::OnPacket(CInPacket* pPacket)
{
    int cMode = pPacket->vfunc_o8_1();
    if (cMode == 0)
    {
        m_mapMaid.RemoveAll();
        unsigned int nCount = pPacket->vfunc_o8_3();
        for (unsigned int i = 0; i < nCount; i++)
        {
            MS2Ptr<CMaid> spMaid(new CMaid);
            spMaid->SetMode(pPacket->vfunc_o8_1());
            spMaid->FUN_14067d730(pPacket);
            m_mapMaid.SetAt(spMaid->m_nId, spMaid);
        }
    }
    else if (cMode == 1)
    {
        MS2Ptr<CMaid> spMaid(new CMaid);
        spMaid->SetMode(pPacket->vfunc_o8_1());
        spMaid->FUN_14067d730(pPacket);
        m_mapMaid.SetAt(spMaid->m_nId, spMaid);
    }
    else if (cMode == 3)
    {
        MS2Ptr<CMaid> spMaid(new CMaid);
        spMaid->SetMode(pPacket->vfunc_o8_1());
        spMaid->FUN_14067d730(pPacket);
        int bNewer = 0;
        {
            MS2Ptr<CMaid> spOld = GetMaid(spMaid->m_nId);
            if (spOld.get() != 0)
            {
                if (spOld->m_nOrder < spMaid->m_nOrder)
                    bNewer = 1;
            }
        }
        m_mapMaid.SetAt(spMaid->m_nId, spMaid);
        if (FUN_141adc890(FUN_1403ed2b0(), 0x4e9d) != 0)
        {
            UIMaidDialog* pDlg = GetMaidDialog(0x4e9d);
            if (pDlg != 0)
                FUN_1412d9680(pDlg);
        }
        if (FUN_141adc890(FUN_1403ed2b0(), 0x4ec0) != 0)
        {
            void* pDlg = FUN_140d51900(0x4ec0);
            if (pDlg != 0)
            {
                FUN_1412e34c0(pDlg);
                if (bNewer)
                    FUN_1412e3990(pDlg, 0);
            }
        }
    }
    else if (cMode == 2)
    {
        unsigned __int64 nId = pPacket->vfunc_o8_4();
        if (m_mapMaid.Lookup(nId) != 0)
            m_mapMaid.RemoveKey(nId);
    }
    else if (cMode == 4)
    {
        int nActorId = pPacket->vfunc_o8_3();
        if (FUN_141adc890(FUN_1403ed2b0(), 0x4e9d) != 0)
        {
            UIMaidDialog* pDlg = GetMaidDialog(0x4e9d);
            if (pDlg != 0)
                FUN_1412d9b90(pDlg);
        }
        PCBase* pPC = FUN_141bd1320(FUN_1403ed2d0(), nActorId);
        if (pPC != 0)
        {
            MS2Ptr<Unk_PCBaseComp_a78> spComp = pPC->vfunc_82();
            if (spComp.get() != 0)
                ((UIHudEntity::Entity*)(void*)spComp.operator->())->FUN_140f48d80();
        }
    }
    if (cMode == 1 || cMode == 2 || cMode == 3)
    {
        if (FUN_141adc890(FUN_1403ed2b0(), 0x4ec9) != 0)
        {
            void* pDlg = FUN_140d519a0(0x4ec9);
            if (pDlg != 0)
                FUN_1412dc3c0(pDlg);
        }
    }
}

// @0x14127ec10
// MS2-FUNCTIONAL: exe tests the Lookup result with jne to the copy-return branch and calls a shared MS2Ptr<CMaid> get; branch order not reproduced
MS2Ptr<CMaid> CUserMaidManager::GetMaid(unsigned __int64 nId)
{
    MS2Ptr<CMaid> spMaid;
    if (m_mapMaid.Lookup(nId, spMaid))
        return spMaid;
    return MS2Ptr<CMaid>(0);
}

// @0x14127ecc0
void CUserMaidManager::SendRequest5(unsigned __int64 nId)
{
    if (FUN_14116d720(FUN_14025e7c0()) == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Maid), 0);
    packet.vfunc_o10_1(5);
    packet.vfunc_o10_4(nId);
    FUN_140710590(packet);
}

// @0x14127ed40
void CUserMaidManager::SendRequest6(unsigned __int64 nId)
{
    if (FUN_14116d720(FUN_14025e7c0()) == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Maid), 0);
    packet.vfunc_o10_1(6);
    packet.vfunc_o10_4(nId);
    FUN_140710590(packet);
}

// @0x14127edc0
void CUserMaidManager::SendRequest7(unsigned __int64 nId)
{
    if (FUN_14116d720(FUN_14025e7c0()) == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Maid), 0);
    packet.vfunc_o10_1(7);
    packet.vfunc_o10_4(nId);
    FUN_140710590(packet);
}

// @0x14127ee40
void CUserMaidManager::SendRequest8(unsigned __int64 nId)
{
    if (FUN_14116d720(FUN_14025e7c0()) == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Maid), 0);
    packet.vfunc_o10_1(8);
    packet.vfunc_o10_4(nId);
    FUN_140710590(packet);
}

// @0x14127eec0
void CUserMaidManager::SendRequest9(unsigned __int64 nId)
{
    if (FUN_14116d720(FUN_14025e7c0()) == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Maid), 0);
    packet.vfunc_o10_1(9);
    packet.vfunc_o10_4(nId);
    FUN_140710590(packet);
}

// @0x14127ef40
void CUserMaidManager::SendRequest10(unsigned __int64 nId, unsigned __int64 nValue, int cFlag)
{
    if (FUN_14116d720(FUN_14025e7c0()) == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::Maid), 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_4(nId);
    packet.vfunc_o10_1(cFlag);
    packet.vfunc_o10_4(nValue);
    FUN_140710590(packet);
}

// @0x14127eff0
CUserMaidManager::MaidMap* CUserMaidManager::GetMaidMap()
{
    return &m_mapMaid;
}

// @0x14127f000
UIMaidDialog* CUserMaidManager::GetMaidDialog(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spUI = ((Unk_MaidUIService*)FUN_1403ed2b0())->FUN_141adcea0(nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIMaidDialog*>((UIObject*)spUI);
    }
    return 0;
}

// @0x141280a20
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
