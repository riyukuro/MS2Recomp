// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\scenestatemove.cpp
// MS2-RANGE: 0x14174c9c0-0x14174d380 .text$mn
// MS2-RANGE: 0x140100400-0x140100540 .text$di
// MS2-PIN: ?SetupClassInfo@CSceneStateMove@@SAXPEAVClassInfo@efd@@_K@Z 0x14174d160
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestatemove.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scenestatemove.h"
#include "networkservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/Helpers.h>

CNetworkService* FUN_140714f90();
void* FUN_140aae430();
class Unk_143a09680 { public: void* m_a; void* m_b; };
class Unk_1409879 : public Unk_143a09680 { };
Unk_1409879 FUN_140987930(const void*);
extern char DAT_143a09680[];
void FUN_141489ff0(void*, Unk_143a09680);
extern CString DAT_143ab2a48;
extern unsigned short DAT_143ab2848;
void FUN_141740b00(int, int, int, const CStringW&, const unsigned short*);
CStringW FUN_14016a730(const char*, int);
CString FUN_14016a600(const wchar_t*, int);
CStringW FUN_14062b4f0(CStringW, const int&);
CStringW FUN_140298ea0(CStringW);
CStringW FUN_1408116a0(int, const int&);
void* FUN_141540270(int);
void FUN_1419e0050(void*, const CStringW&);
void FUN_141b6fcf0(const CStringW&, const CStringW&, int);
extern void (*DAT_143b03490)(short, unsigned char, const char*);
extern unsigned char DAT_1430e3b20;

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateMove);

static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");

// @0x14174c9c0
CSceneStateMove::CSceneStateMove()
{
    m_bConnecting = 0;
    m_bFailed = 0;
}

// @0x14174ca50
CSceneStateMove::~CSceneStateMove()
{
}

// @0x14174caa0
// MS2-FUNCTIONAL: the exe keeps the 24-byte FUN_140987930 result slot pointer in a stack temp before the call (same as CSceneStateLogin::OnEnter)
void CSceneStateMove::OnEnter(int nPrevState)
{
    FUN_141489ff0(FUN_140aae430(), static_cast<const Unk_143a09680&>(FUN_140987930(DAT_143a09680)));
    m_bConnecting = 0;
    m_bFailed = 0;
    CSceneStateBase::OnEnter(nPrevState);
    m_timer.FUN_1408687f0();
    m_nRetry = 0;
}

// @0x14174cb40
void CSceneStateMove::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
}

// @0x14174cb70
// MS2-FUNCTIONAL: frame size and the log block now match; the connect call's by-value CString/port argument temps (stack slots 0x78-0x88) are ordered differently
void CSceneStateMove::OnUpdate(double fTime)
{
    if (m_bConnecting == 0)
    {
        m_bConnecting = 1;
        FUN_140714f90()->FUN_1415383a0(DAT_143ab2a48, DAT_143ab2848, 1, 1, 0);
        m_timer.FUN_140868750(10000);
        CStringW addr = FUN_14016a730(DAT_143ab2a48, 0);
        FUN_141740b00(0x2dd, 1, 1, addr, &DAT_143ab2848);
    }
    if (m_nRetry < 5)
    {
        if (m_bConnecting != 0 && m_timer.FUN_140868c00() != 0)
        {
            if (FUN_140714f90()->FUN_1415384e0() == 0)
            {
                m_bConnecting = 0;
                m_nRetry = m_nRetry + 1;
                m_timer.FUN_140868750(10000);
                CStringW text = FUN_14062b4f0(CStringW(L"s_reconnect_to_server"), m_nRetry);
                void* loading = FUN_141540270(0x3ed);
                if (loading)
                    FUN_1419e0050(loading, text);
            }
        }
    }
    else if (m_nRetry == 5 && m_timer.FUN_140868c00() != 0)
    {
        if (m_bFailed == 0)
        {
            if (FUN_140714f90()->FUN_141539180())
            {
                CStringW text = FUN_140298ea0(CStringW(L"s_reconnect_to_server_fail"));
                void* loading = FUN_141540270(0x3ed);
                if (loading)
                    FUN_1419e0050(loading, text);
                m_bFailed = 1;
                m_nRetry = 0;
                m_bConnecting = 0;
                return;
            }
        }
        m_timer.FUN_1408687f0();
        m_nRetry = 6;
        if (DAT_143b03490)
        {
            const CStringW& msg0 = FUN_1408116a0(0x20f, 7);
            const CStringW& msg = msg0;
            const CString& ansi0 = FUN_14016a600(msg, 0);
            const CString& ansi = ansi0;
            const efd::LogHelper& log0 = efd::LogHelper(ansi);
            const efd::LogHelper& log = log0;
            DAT_143b03490(1, DAT_1430e3b20, log);
        }
        FUN_140d86260()->vfunc_58(0x20f, 7);
        CStringW title(L"MS2");
        FUN_141b6fcf0(FUN_1408116a0(0x20f, 7), title, 0);
        TerminateProcess(GetCurrentProcess(), 2);
    }
}

// @0x14174d0c0
void CSceneStateMove::OnPacket(CInPacket& packet)
{
    CSceneStateBase::OnPacket(packet);
}

// memmove_s 0x14174d260 closes the obj's COMDAT tail.
MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb6580-0x142cb65f0 .text$yd
