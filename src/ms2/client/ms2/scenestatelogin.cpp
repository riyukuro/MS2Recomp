// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\scenestatelogin.cpp
// MS2-RANGE: 0x14174c000-0x14174c710 .text$mn
// MS2-RANGE: 0x140100130-0x1401002c0 .text$di
// MS2-PIN: ?SetupClassInfo@CSceneStateLogin@@SAXPEAVClassInfo@efd@@_K@Z 0x14174c610
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestatelogin.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scenestatelogin.h"
#include "networkservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ascript.h"

void FUN_140930150(int);
void* FUN_1403ed2d0();
void FUN_141bbae40(void*, IWorldServiceCallback*);
void FUN_141bbae80(void*, IWorldServiceCallback*);
void FUN_141bbbe40(void*, int, int, int);
void* FUN_140aae430();
class Unk_143a09680 { public: void* m_a; void* m_b; };
class Unk_1409879 : public Unk_143a09680 { };
Unk_1409879 FUN_140987930(const void*);
extern char DAT_143a09680[];
void FUN_141489ff0(void*, Unk_143a09680);
extern int DAT_1439f4a78;
void* FUN_140166440();
void FUN_140353fc0(void*, int, int, const wchar_t*, const int&);
Delegate<bool(int, const CMsgBoxData&)> FUN_140b76b10(bool (*)(int, const CMsgBoxData&));
bool FUN_141902530(int, const CMsgBoxData&);
CStringW FUN_1408116a0(int, const int&);
class Unk_MsgBoxData {};
MS2Ptr<Unk_MsgBoxData> FUN_140d74390(CStringW, int, Delegate<bool(int, const CMsgBoxData&)>);
void* FUN_140aa6d30();
void FUN_1417e25a0(void*, int);
struct Unk_1407a7d20 {
    Unk_1407a7d20(CInPacket&);
    ~Unk_1407a7d20();
    int m_0;
    CStringW m_text;
    void *m_p0, *m_p1, *m_p2, *m_p3, *m_p4;
};
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void* FUN_1409478c0();
int FUN_140a18070(void*);
struct Unk_140ae7ce0 { Unk_140ae7ce0(); void *m_p0, *m_p1, *m_p2, *m_p3, *m_p4, *m_p5; };
bool FUN_140aeb590(void*, Unk_140ae7ce0*);
void FUN_140aed720(void*, Unk_140ae7ce0*);
void FUN_140aed750(void*, int, int);
void FUN_14174c520(CSceneStateLogin*, CInPacket&);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateLogin);

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static Unk_1401cd100 s_pointer(NULL);
static UICommon::CMyPCKeyInputController s_keyInput;

// @0x14174c000
CSceneStateLogin::CSceneStateLogin()
{
}

// @0x14174c060
CSceneStateLogin::~CSceneStateLogin()
{
}

// @0x14174c0a0
// MS2-FUNCTIONAL: the exe keeps the 24-byte FUN_140987930 result slot pointer in a stack temp before the call (10 bytes) - not reproduced
void CSceneStateLogin::OnEnter(int nPrevState)
{
    CSceneStateBase::OnEnter(nPrevState);
    FUN_140930150(1);
    FUN_141bbae40(FUN_1403ed2d0(), this);
    FUN_141489ff0(FUN_140aae430(), static_cast<const Unk_143a09680&>(FUN_140987930(DAT_143a09680)));
    DAT_1439f4a78 = -1;
    FUN_141bbbe40(FUN_1403ed2d0(), 1, 1, 0);
}

// @0x14174c170
void CSceneStateLogin::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
    FUN_141bbae80(FUN_1403ed2d0(), this);
}

// @0x14174c1d0
void CSceneStateLogin::OnUpdate(double fTime)
{
    CSceneStateBase::OnUpdate(fTime);
}

// @0x14174c200
void CSceneStateLogin::OnPacket(CInPacket& packet)
{
    CSceneStateBase::OnPacket(packet);
    switch (packet.FUN_14070fe80())
    {
    case static_cast<int>(RecvOp::Admin):
        FUN_14174c520(this, packet);
        break;
    case static_cast<int>(RecvOp::ServerList):
    {
        packet.vfunc_o8_7();
        int result = packet.vfunc_o8_1();
        if (result > 0)
        {
            FUN_1417e25a0(FUN_140aa6d30(), 0x620000d);
        }
        else
        {
            FUN_140353fc0(FUN_140166440(), 1, 0x20, L"SceneStateLogin::OnPacket {0}", result);
            FUN_140d74390(FUN_1408116a0(0x20e, 0), 0, FUN_140b76b10(FUN_141902530));
            FUN_140d86260()->vfunc_58(0x20e, 0);
        }
        break;
    }
    case static_cast<int>(RecvOp::Notice):
    {
        Unk_1407a7d20 info(packet);
        FUN_140d73aa0(CStringW(info.m_text), 0, 0, CStringW(L""));
    }
    }
}

// @0x14174c4a0
void CSceneStateLogin::vfunc_1(int)
{
    if (FUN_140a18070(FUN_1409478c0()) != 0)
    {
        Unk_140ae7ce0 tmp;
        if (FUN_140aeb590(FUN_1409478c0(), &tmp))
        {
            FUN_140aed720(FUN_1409478c0(), &tmp);
            FUN_140aed750(FUN_1409478c0(), 4, 1);
        }
    }
}

// @0x14174c520
void FUN_14174c520(CSceneStateLogin*, CInPacket& packet)
{
    int kind = packet.vfunc_o8_1();
    switch (kind)
    {
    case 0:
    {
        unsigned char value = packet.vfunc_o8_1();
        FUN_140930150(value);
        break;
    }
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb6480-0x142cb6510 .text$yd
