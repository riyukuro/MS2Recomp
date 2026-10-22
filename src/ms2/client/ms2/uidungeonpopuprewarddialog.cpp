// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dungeon reward popup.
// MS2-UNIT: client\ms2\uidungeonpopuprewarddialog.cpp
// MS2-RANGE: 0x140c0ec90-0x140c0fdc0 .text$mn
// MS2-PIN: ?vfunc_48@UIDungeonPopupRewardDialog@@UEAAHXZ 0x140c0fb70
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidungeonpopuprewarddialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uidungeonpopuprewarddialog.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class Unk_DungeonPopupStream
{
public:
    virtual ~Unk_DungeonPopupStream();
    virtual unsigned char ReadByte();
};
// The stream sub-object is opaque (void*) so clang-cl cannot devirtualize ReadByte (no exe symbol for it).
class CInPacket { public: void* m_00; void* m_stream; };
class Unk_DungeonPopupPacketManager
{
public:
    void FUN_140da5180(int opcode, Delegate<void(CInPacket&)> handler);
    void FUN_140da51e0(int opcode, Delegate<void(CInPacket&)> handler);
};
Unk_DungeonPopupPacketManager* FUN_140bccd50();
// Reward helper is CPtred-derived (ctor starts with the 0x18-byte reference-counted base).
class UIDungeonSearchUnitedReward : public CPtred
{
public:
    UIDungeonSearchUnitedReward();
    virtual ~UIDungeonSearchUnitedReward();
    bool Init(MS2Ptr<ASMovieClip> root);
    void FUN_140e13c00();
    void FUN_14015b020();
    int FUN_140159bc0();
    void FUN_140159ba0();
private:
    void* m_18; void* m_20; void* m_28; void* m_30; void* m_38;
    void* m_40; void* m_48; void* m_50; void* m_58; void* m_60;
    void* m_68; void* m_70; void* m_78; void* m_80; void* m_88; void* m_90;
};
MS2_CHECK_SIZE(UIDungeonSearchUnitedReward, 0x98);
CStringW FUN_140298ea0(CStringW key);
void FUN_1412751b0(const CStringW& text, int flags);

// @0x140c0ec90
UIDungeonPopupRewardDialog::UIDungeonPopupRewardDialog()
{
    m_80 = 0;
    FUN_141924170(1);
}

// @0x140c0ed10
UIDungeonPopupRewardDialog::~UIDungeonPopupRewardDialog()
{
}

// @0x140c0ed60
CString UIDungeonPopupRewardDialog::GetTypeName()
{
    return "DungeonPopupRewardDialog";
}
MS2_REPLACE_METHOD(0x140C0ED60, UIDungeonPopupRewardDialog, GetTypeName, 61, 0x3A527D89);

// @0x140c0edb0
void UIDungeonPopupRewardDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140bccd50()->FUN_140da5180(0x1a, Delegate<void(CInPacket&)>(this, &UIDungeonPopupRewardDialog::FUN_140c0f210));
    FUN_141925fa0("m_dragBar");
    FUN_141925ec0("m_closeButton");
    m_reward = new UIDungeonSearchUnitedReward;
    if (!m_reward->Init(GetChild<ASMovieClip>("m_unitedReward"))) {
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                      MS2_THIS_FILE, MS2_LINE(34), __FUNCTION__));
    } else {
        m_reward->FUN_140e13c00();
    }
}
MS2_REPLACE_METHOD(0x140C0EDB0, UIDungeonPopupRewardDialog, OnLoadComplete, 873, 0x1C9B5FB0);

// @0x140c0f140
void UIDungeonPopupRewardDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_140bccd50()->FUN_140da51e0(0x1a, Delegate<void(CInPacket&)>(this, &UIDungeonPopupRewardDialog::FUN_140c0f210));
    m_reward = 0;
}
MS2_REPLACE_METHOD(0x140C0F140, UIDungeonPopupRewardDialog, vfunc_26, 189, 0xCE47389B);

// @0x140c0f210
void UIDungeonPopupRewardDialog::FUN_140c0f210(CInPacket& packet)
{
    int command = reinterpret_cast<Unk_DungeonPopupStream*>(&packet.m_stream)->ReadByte();
    switch (command) {
    case 0x17:
        m_reward->FUN_140e13c00();
        FUN_1412751b0(FUN_140298ea0(L"s_dungeonSearch_success_united_reward_reset"), 0x14);
        break;
    }
}
MS2_REPLACE_METHOD(0x140C0F210, UIDungeonPopupRewardDialog, FUN_140c0f210, 212, 0x6161BE2F);
