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
#include <NiColor.h>
#include <efd/Helpers.h>
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/ms2format.h"   // C3: fmt for BlockFormat<int>

void FUN_140930150(int);
class WorldService   // C3: unit-local view of the callback set
{
public:
    static WorldService* GetInstance();   // C3: was free FUN_1403ed2d0
    void FUN_141bbae40(void* p);
    void FUN_141bbae80(void* p);
};
void FUN_141bbbe40(void*, int, int, int);
void* FUN_140aae430();
void FUN_141489ff0(void*, NiColorA);                    // the app's clear colour
extern int DAT_1439f4a78;
class CLogString* GetLogString();   // C3: was FUN_140166440
template <class T> void Unk_ShopLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was FUN_140353fc0
bool FUN_141902530(int, const CMsgBoxData&);
CStringW BlockFormat(int, const fmt::ArgList&);   // C3: BlockFormat<int> (0x1408116a0)
FMT_VARIADIC_W(CStringW, BlockFormat, int)
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW, int, Delegate<bool (int, CMsgBoxData const &)>);  // C3: the definition's signature
void* FUN_140aa6d30();
class CStateService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1417e25a0(int);
};
struct Unk_1407a7d20 {
    Unk_1407a7d20(CInPacket&);
    ~Unk_1407a7d20();
    int m_0;
    CStringW m_text;
    void *m_p0, *m_p1, *m_p2, *m_p3, *m_p4;
};
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void* FUN_1409478c0();
class CameraMgr   // C3: member view for the former free stand-ins
{
public:
    int FUN_140a18070();
    bool GetSavedSetting(struct Unk_CameraSetting&);
    void FUN_140aed720(struct Unk_CameraSetting const&);
    void FUN_140aed750(int, int);
};
struct Unk_140ae7ce0 { Unk_140ae7ce0(); void *m_p0, *m_p1, *m_p2, *m_p3, *m_p4, *m_p5; };
void FUN_14174c520(CSceneStateLogin*, CInPacket&);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateLogin);

class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };   // C3: was Unk_1401cd100 (ctor 0x1401cd100)
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static Unk_BuddyHandle s_pointer(NULL);
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
void CSceneStateLogin::OnEnter(int nPrevState)
{
    CSceneStateBase::OnEnter(nPrevState);
    FUN_140930150(1);
    WorldService::GetInstance()->FUN_141bbae40((IWorldServiceCallback*)this);
    FUN_141489ff0(FUN_140aae430(), efd::ColorA::BLACK);
    DAT_1439f4a78 = -1;
    FUN_141bbbe40(WorldService::GetInstance(), 1, 1, 0);
}

// @0x14174c170
void CSceneStateLogin::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
    WorldService::GetInstance()->FUN_141bbae80((IWorldServiceCallback*)this);
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
        packet.ReadString();
        int result = packet.ReadUInt8();
        if (result > 0)
        {
            ((class CStateService*)(void*)(FUN_140aa6d30()))->FUN_1417e25a0(0x620000d);
        }
        else
        {
            Unk_ShopLog<int>(GetLogString(), 1, 0x20, L"SceneStateLogin::OnPacket {0}", result);
            FUN_140d74390(BlockFormat<int>(0x20e, 0), 0, Delegate<bool(int, const CMsgBoxData&)>(FUN_141902530));
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
    if (((class CameraMgr*)(void*)(FUN_1409478c0()))->FUN_140a18070() != 0)
    {
        Unk_140ae7ce0 tmp;
        if (((class CameraMgr*)(void*)(FUN_1409478c0()))->GetSavedSetting(*(struct Unk_CameraSetting*)(&tmp)))
        {
            ((class CameraMgr*)(void*)(FUN_1409478c0()))->FUN_140aed720(*(struct Unk_CameraSetting const*)(&tmp));
            ((class CameraMgr*)(void*)(FUN_1409478c0()))->FUN_140aed750(4, 1);
        }
    }
}

// @0x14174c520
void FUN_14174c520(CSceneStateLogin*, CInPacket& packet)
{
    int kind = packet.ReadUInt8();
    switch (kind)
    {
    case 0:
    {
        unsigned char value = packet.ReadUInt8();
        FUN_140930150(value);
        break;
    }
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb6480-0x142cb6510 .text$yd
