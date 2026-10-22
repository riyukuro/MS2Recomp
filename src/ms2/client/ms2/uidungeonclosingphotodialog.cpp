// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dungeon closing photo dialog.
// MS2-UNIT: client\ms2\uidungeonclosingphotodialog.cpp
// MS2-RANGE: 0x140e0de40-0x140e12730 .text$mn
// MS2-RANGE: 0x1400d72c0-0x1400d7460 .text$di
// MS2-RANGE: 0x142ca6350-0x142ca63f6 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VUIAvatarPC@@@@QEAAAEAV1@PEAVUIAvatarPC@@@Z 0x140e11b60 ; unique
// MS2-PIN: ??_GUIDungeonClosingPhotoDialog@@UEAAPEAXI@Z 0x140e11ca0 ; unique
// MS2-PIN: ??$format_arg@DW4Unk_ClosingJob@@@fmt@@YAXAEAV?$BasicFormatter@D@0@AEAPEBDAEBW4Unk_ClosingJob@@@Z 0x140e11560
// MS2-PIN: ??8?$MS2Ptr@VUIAvatarPC@@@@QEBA_NPEAVUIAvatarPC@@@Z 0x140e11bd0
// MS2-PIN: ??C?$MS2Ptr@VUIAvatarPC@@@@QEBAPEAVUIAvatarPC@@XZ 0x140e11c50
// MS2-PIN: ?push_back@?$vector@UUnk_ClosingEntry@@V?$allocator@UUnk_ClosingEntry@@@std@@@std@@QEAAXAEBUUnk_ClosingEntry@@@Z 0x140e12590
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidungeonclosingphotodialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uidungeonclosingphotodialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "buddymanager.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <errno.h>
#include <string.h>
static CString s_winSound = "BattleField_Win";

// ---- local stand-ins for classes whose units are not recovered yet ----
enum Unk_ClosingJob { Unk_ClosingJob_None };
class Unk_ClosingThing { public: void FUN_141270610(); };
struct Unk_ClosingVector
{
    Unk_ClosingVector();
    float x, y, z;
    Unk_ClosingVector& operator+=(const Unk_ClosingVector&);
};
MS2_CHECK_SIZE(Unk_ClosingVector, 12);
struct Unk_ClosingCameraData
{
    Unk_ClosingCameraData();
    void FUN_141b48530();
    Unk_ClosingVector eye, target;
    float f18, f1c, f20;
    int n24, n28, n2c;
};
MS2_CHECK_SIZE(Unk_ClosingCameraData, 0x30);
class Unk_ClosingActor
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
    virtual void vfunc_12(int);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual Unk_ClosingVector vfunc_18();
    void FUN_1410885b0(bool);
    Unk_ClosingThing* FUN_14165f460();
    Unk_ClosingJob FUN_141654730();
    void FUN_140e11d00();
    // 76 and 77 are the name setter (by value: the callee destroys it) and getter
    virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28();
    virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33();
    virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38();
    virtual void vfunc_39(); virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43();
    virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48();
    virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53();
    virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58();
    virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63();
    virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68();
    virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73();
    virtual void vfunc_74(); virtual void vfunc_75();
    virtual void vfunc_76(CStringW);
    virtual CStringW vfunc_77();
private:
    void* m_pad_08[606];
    int m_12f8;
    int m_12fc;
};
class Unk_ClosingCamera
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
    virtual void vfunc_12(int);
    virtual void vfunc_13(const Unk_ClosingCameraData&);
};
class Unk_ClosingCameraPtr
{
public:
    ~Unk_ClosingCameraPtr();
    Unk_ClosingCamera* operator->() const;
private:
    Unk_ClosingCamera* m_p;
};
MS2_CHECK_SIZE(Unk_ClosingCameraPtr, 8);
class Unk_ClosingAvatar : public CPtred
{
public:
    virtual void vfunc_1(IUIAvatarEventListener*);
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
    virtual void vfunc_12(int);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual Unk_ClosingActor* vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual int vfunc_27(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual void vfunc_28(void*, TPtr<Unk_UISwfEntity_25>, void*, void*);
    void FUN_1418bc790(int, int);
    Unk_ClosingActor* FUN_1418bd1d0();
    Unk_ClosingCameraPtr FUN_1418b9bc0();
};
class UIAvatarPC : public Unk_ClosingAvatar
{
public:
    UIAvatarPC(void*, bool);
private:
    void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48; void* m_50; void* m_58;
    void* m_60; void* m_68; void* m_70; void* m_78; void* m_80; void* m_88; void* m_90; void* m_98; void* m_a0;
    void* m_a8; void* m_b0; void* m_b8; void* m_c0; void* m_c8; void* m_d0; void* m_d8; void* m_e0; void* m_e8;
};
MS2_CHECK_SIZE(UIAvatarPC, 0xf0);
class Unk_ClosingSelf { public: __int64 FUN_141656a80(); };
// The PC: the name getter is vtable slot 77 (+0x268).
class Unk_ClosingPlayer
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76();
    virtual CStringW vfunc_77();
};
class Unk_ClosingWorld
{
public:
    Unk_ClosingPlayer* FUN_141bd1530(__int64);
    Unk_ClosingSelf* FUN_141bd0cc0();
    int FUN_141bd3060();
};
Unk_ClosingWorld* FUN_1403ed2d0();
class Unk_ClosingUIMgr { public: void FUN_141adc530(int); };
Unk_ClosingUIMgr* FUN_1403ed2b0();
class Unk_ClosingButton : public ASDisplayObject { public: void FUN_1422c1fe0(unsigned); };
class Unk_ClosingClip : public ASUIComponent
{
public:
    // ASUIComponent slots 16-23 (not declared by the placeholder); vfunc_24 is slot 24 (+0xc0, 0x140e0e3f1)
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23();
    virtual void vfunc_24(bool);
    void FUN_1422c00f0(float, float);
    void FUN_1422c0180(unsigned, unsigned);
};
class Unk_BuddyInput { public: virtual unsigned vfunc_0(); int FUN_14070fe80(); void FUN_140715280(unsigned); };
class Unk_RewardOtherDialog : public UIDialog { public: void FUN_1419f6a70(int, CStringW, int); };
Unk_RewardOtherDialog* FUN_140e01890(int);
class Unk_140a94350
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int n);
};
Unk_140a94350* FUN_140a94350();
CBuddyManager* FUN_14097a780();
void FUN_140cfee80(const Scaleform::GFx::Value&, CString, CStringW);
void FUN_140cffca0(const Scaleform::GFx::Value&, CString, CString);
CStringW GetStringCommonByKey(const CStringW&);
CStringW GetStringCommon(int);
CString FUN_14031c9d0(unsigned);
CStringW FUN_14062b4f0(CStringW, const int*);
void FUN_141275260(int, int, int);
void FUN_140961010(int, int, int, const CStringW&);
void FUN_141276180(const CString&, const CString&);
unsigned FUN_140869420();
int FUN_140718170(const CString&);

// @0x140e0de40
UIDungeonClosingPhotoDialog::UIDungeonClosingPhotoDialog() : m_1b0(0), m_1b4(0), m_1bc(0)
{
    FUN_141925e70(3, 1);
}

// @0x140e0df20
UIDungeonClosingPhotoDialog::~UIDungeonClosingPhotoDialog() {}

// @0x140e0dfa0
CString UIDungeonClosingPhotoDialog::GetTypeName() { return "DungeonClosingPhotoDialog"; }

// @0x140e0dff0
void UIDungeonClosingPhotoDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_140e0f6b0();
}

// @0x140e0e020
void UIDungeonClosingPhotoDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_1b4 = 0;
    if (FUN_1403ed2d0()->FUN_141bd3060() == m_1bc)
        FUN_1403ed2b0()->FUN_141adc530(0x4ef9);
    m_1bc = 0;
}

// @0x140e0e090
void UIDungeonClosingPhotoDialog::vfunc_72()
{
    if (m_1b0 == 0 || FUN_140869420() <= m_1b0) {
        if (m_1b4 != 0 && m_1b4 < FUN_140869420()) {
            m_1b4 = 0;
            vfunc_67();
        }
    } else {
        m_1b0 = 0;
        if (FUN_1403ed2d0()->FUN_141bd3060() == m_1bc)
            FUN_141924680();
    }
}

// @0x140e0e150
void UIDungeonClosingPhotoDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    int n = (int)m_entries.size();
    int cap = 10;
    n = (std::min)(n, cap);
    for (size_t i = 0; i < m_entries.size(); ++i) {
        Unk_ClosingEntry& e = m_entries[i];
        e.m_avatar->vfunc_1(this);
        CString name = StringFormat("m_char{0}", i + 1);
        e.m_clip = GetChild<ASUIComponent>(name);
        e.m_clip->vfunc_3(1);
        int x = 0, y = 0;
        unsigned scale = 100;
        FUN_140e10010(x, y, scale, (int)i + 1, n);
        Unk_ClosingClip* clip = static_cast<Unk_ClosingClip*>(e.m_clip.operator->());
        clip->FUN_1422c00f0((float)x, (float)y);
        clip->FUN_1422c0180(scale, scale);
        clip->vfunc_24(1);
        FUN_140e102b0(&e);
    }
    std::vector<int> pending(m_pending);
    m_pending.clear();
    for (size_t k = 0; k < pending.size(); ++k)
        FUN_140e0fd20(pending[k]);
    FUN_140e0f790();
    int delay = 5000;
    if (4 < n)
        delay = 8000;
    m_1b4 = FUN_140869420() + delay;
    m_1b8 = false;
}

// @0x140e0e510
void UIDungeonClosingPhotoDialog::vfunc_25(void* a, TPtr<Unk_UISwfEntity_25> tp, void* b, void* c)
{
    if (tp.get() == 0 || b == 0)
        return;
    int idx = FUN_140718170(*static_cast<const CString*>(c));
    if (idx >= 0 && idx <= (int)m_entries.size()) {
        if (m_entries[idx].m_avatar == 0)
            return;
        Unk_ClosingActor* actor = m_entries[idx].m_avatar->vfunc_24();
        if (!actor)
            return;
        m_entries[idx].m_avatar->vfunc_28(a, tp, b, c);
        Unk_ClosingCameraData data;
        data.FUN_141b48530();
        data.f1c = 300.0f;
        data.target += actor->vfunc_18();
        data.eye += data.target;
        m_entries[idx].m_avatar->FUN_1418b9bc0()->vfunc_13(data);
        m_entries[idx].m_avatar->FUN_1418bc790(14, 85);
    }
}

// @0x140e0e810
void UIDungeonClosingPhotoDialog::vfunc_16()
{
    UISwfEntity::vfunc_16();
    FUN_140e0ff50();
}

// @0x140e0e840
bool UIDungeonClosingPhotoDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    FUN_140e0fe40();
    return true;
}

// @0x140e0e880
void UIDungeonClosingPhotoDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    Unk_BuddyInput* in = static_cast<Unk_BuddyInput*>(p);
    if (in->FUN_14070fe80() == 0x61) {
        unsigned pos = in->vfunc_0();
        Unk_BuddyResponse r;
        r.FUN_1407a3cc0(*in);
        in->FUN_140715280(pos);
        FUN_140e10800(r.result, r.name);
    }
}

// @0x140e0e960
int UIDungeonClosingPhotoDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onAddFriend", szMethod) == 0) {
        ASData d;
        if (d.FUN_1422b9620(pArgs, nArgs))
            FUN_140e104d0(d.FUN_1422b8a10());
        return 1;
    }
    return 0;
}

// @0x140e0ea40
bool UIDungeonClosingPhotoDialog::FUN_140e0ea40()
{
    return m_1b0 != 0 || FUN_141924630() != 0;
}

// @0x140e0ea80
int UIDungeonClosingPhotoDialog::vfunc_o178_1(void* av)
{
    if (!av)
        return 0;
    int found = 0;
    for (size_t i = 0; i < m_entries.size(); ++i) {
        if (m_entries[i].m_avatar.get() == av) {
            found = (int)i;
            break;
        }
    }
    if (found >= 0)
        FUN_140e0fd20(found);
    return 1;
}

// @0x140e0eb40
void UIDungeonClosingPhotoDialog::FUN_140e0eb40(CInPacket& pkt)
{
    m_entries.clear();
    m_pending.clear();
    unsigned res = pkt.ReadUInt8();
    int count = pkt.ReadInt32();
    for (int i = 0; i < count; ++i) {
        __int64 uid = pkt.ReadInt64();
        int rank = pkt.ReadInt32();
        int type = pkt.ReadInt32();
        int value = pkt.ReadInt32();
        CStringW text;
        if (value > 0) {
            switch (type) {
            case 0: text = FUN_14062b4f0(CStringW(L"s_dungeon_record_accum_damage"), &value); break;
            case 1: text = FUN_14062b4f0(CStringW(L"s_dungeon_record_accum_heal"), &value); break;
            case 2: text = FUN_14062b4f0(CStringW(L"s_dungeon_record_accum_hit_count"), &value); break;
            case 3: text = FUN_14062b4f0(CStringW(L"s_dungeon_record_boss_last_hit"), &value); break;
            case 4: text = FUN_14062b4f0(CStringW(L"s_dungeon_record_accum_move_distance"), &value); break;
            case 5: text = FUN_14062b4f0(CStringW(L"s_dungeon_record_accum_critical_damage"), &value); break;
            case 6: text = FUN_14062b4f0(CStringW(L"s_dungeon_record_max_critial_damage"), &value); break;
            case 7: text = FUN_14062b4f0(CStringW(L"s_dungeon_record_accum_monster_kill"), &value); break;
            case 8: text = FUN_14062b4f0(CStringW(L"s_dungeon_record_accum_be_hit_count"), &value); break;
            case 9: text = FUN_14062b4f0(CStringW(L"s_dungeon_record_accum_default_skill_damage"), &value); break;
            }
        }
        if (m_entries.size() < 10) {
            Unk_ClosingPlayer* player = FUN_1403ed2d0()->FUN_141bd1530(uid);
            if (player == 0)
                continue;
            UIAvatarPC* av = new UIAvatarPC(player, false);
            Unk_ClosingActor* actor = av->FUN_1418bd1d0();
            actor->vfunc_76(player->vfunc_77());
            av->FUN_1418bd1d0()->FUN_140e11d00();
            av->FUN_1418bd1d0()->FUN_1410885b0(true);
            av->FUN_1418bd1d0()->FUN_14165f460()->FUN_141270610();
            av->vfunc_1(this);
            Unk_ClosingEntry entry;
            entry.m_uid = uid;
            entry.m_avatar.AssignRaw(av);
            entry.m_clip = 0;
            entry.m_text = text;
            entry.m_rank = rank;
            m_entries.push_back(entry);
        }
    }
    m_1bc = FUN_1403ed2d0()->FUN_141bd3060();
    unsigned flag = 0;
    if (res == 1) {
        Unk_RewardOtherDialog* dlg = FUN_140e01890(0x4e4c);
        if (dlg) {
            flag = 2000;
            FUN_140a94350()->vfunc_10(9);
            dlg->FUN_1419f6a70(5, GetStringCommonByKey(CStringW(L"s_room_dungeon_clear")), 2000);
            FUN_141276180(s_winSound, "");
        }
    } else if (res == 2) {
        Unk_RewardOtherDialog* dlg = FUN_140e01890(0x4e4c);
        if (dlg) {
            flag = 2000;
            dlg->FUN_1419f6a70(7, GetStringCommonByKey(CStringW(L"s_room_dungeon_fail")), 2000);
        }
    }
    if (flag > 0)
        FUN_140e0fcf0(2000);
    else
        FUN_141924680();
}

// @0x140e0f6b0
void UIDungeonClosingPhotoDialog::FUN_140e0f6b0()
{
    FUN_140e0ff50();
    for (size_t i = 0; i < m_entries.size(); ++i) {
        if (m_entries[i].m_clip.get())
            m_entries[i].m_clip->vfunc_3(0);
    }
    m_entries.clear();
    m_pending.clear();
}

// @0x140e0f790
void UIDungeonClosingPhotoDialog::FUN_140e0f790()
{
    for (size_t i = 0; i < m_entries.size(); ++i) {
        Unk_ClosingEntry& e = m_entries[i];
        if (e.m_clip == 0)
            continue;
        UIAvatarPC* av = e.m_avatar;
        Unk_ClosingActor* actor = av ? av->FUN_1418bd1d0() : 0;
        if (!actor)
            continue;
        MS2Ptr<ASMovieClip> info = e.m_clip->FUN_1409b4560("m_characterInfo");
        if (info.get() == 0)
            return;
        MS2Ptr<ASMovieClip> charInfo = info->FUN_1409b4560("m_charInfo");
        if (charInfo.get()) {
            FUN_140cfee80(charInfo->FUN_1422bb890(), "m_charName", actor->vfunc_77());
            Unk_ClosingJob job = actor->FUN_141654730();
            CString jobStr = StringFormat("_{0}", job);
            FUN_140cffca0(charInfo->FUN_1422bb890(), "m_jobMovie", jobStr);
        }
        MS2Ptr<ASMovieClip> rank = info->FUN_1409b4560("m_rank");
        if (rank.get()) {
            if (e.m_rank < 0) {
                rank->vfunc_4(false);
            } else {
                CString rankStr = FUN_14031c9d0((unsigned)e.m_rank);
                rank->vfunc_4(true);
                rank->vfunc_15(rankStr);
            }
        }
        FUN_140cfee80(info->FUN_1422bb890(), "m_etcInfo", e.m_text);
    }
}

// @0x140e0fcf0
void UIDungeonClosingPhotoDialog::FUN_140e0fcf0(int n)
{
    m_1b0 = FUN_140869420() + n;
}

// @0x140e0fd20
void UIDungeonClosingPhotoDialog::FUN_140e0fd20(int idx)
{
    if (idx <= (int)m_entries.size()) {
        if (m_entries[idx].m_clip.get() == 0)
            m_pending.push_back(idx);
        else
            m_entries[idx].m_clip->Invoke("loadRenderTarget", StringFormat(L"{0}", idx));
    }
}

// @0x140e0fe40
void UIDungeonClosingPhotoDialog::FUN_140e0fe40()
{
    for (size_t i = 0; i < m_entries.size(); ++i) {
        if (m_entries[i].m_clip.get())
            m_entries[i].m_clip->Invoke("loadRenderTarget", StringFormat(L"{0}", i));
    }
}

// @0x140e0ff50
void UIDungeonClosingPhotoDialog::FUN_140e0ff50()
{
    for (size_t i = 0; i < m_entries.size(); ++i) {
        if (m_entries[i].m_clip.get())
            m_entries[i].m_clip->Invoke("unloadRenderTarget");
    }
}

// @0x140e10010
void UIDungeonClosingPhotoDialog::FUN_140e10010(int& x, int& y, unsigned& scale, int slot, int total)
{
    if (slot > total)
        return;
    if (total < 5) {
        scale = 100;
        x = (slot - 1) * 0x1b6 - (total * 0x1b6 - 10) / 2;
        y = -0x135;
    } else {
        scale = 0x50;
        int half = total / 2;
        int s;
        if (half < slot) {
            s = slot - half;
            y = 0x19;
            half = total - half;
        } else {
            s = slot;
            y = -0x207;
        }
        x = (s - 1) * 0x160 - (half * 0x160 - 10) / 2;
    }
    MS2Ptr<ASMovieClip> bg = GetChild<ASMovieClip>("m_bg");
    if (bg.get()) {
        x += bg->FUN_1422c1340() / 2;
        y += bg->FUN_1422c13b0() / 2;
    }
}

// @0x140e102b0
void UIDungeonClosingPhotoDialog::FUN_140e102b0(Unk_ClosingEntry* e)
{
    MS2Ptr<ASMovieClip> info = e->m_clip->FUN_1409b4560("m_characterInfo");
    if (info.get()) {
        MS2Ptr<Unk_ClosingButton> btn = info->FUN_140acce30<Unk_ClosingButton>("m_addFriend");
        if (btn.get()) {
            Unk_ClosingSelf* self = FUN_1403ed2d0()->FUN_141bd0cc0();
            bool isSelf = self && self->FUN_141656a80() == e->m_uid;
            bool buddy = FUN_14097a780()->FUN_140ae4d70(e->m_uid);
            int show = (isSelf || buddy) ? 0 : 1;
            btn->vfunc_4(show != 0);
            btn->FUN_1422c1fe0(show);
        }
    }
}

// @0x140e104d0
void UIDungeonClosingPhotoDialog::FUN_140e104d0(int slot)
{
    slot -= 1;
    bool valid;
    if (slot < 0 || (int)m_entries.size() - 1 < slot)
        valid = false;
    else
        valid = true;
    if (!valid)
        return;
    Unk_ClosingEntry* e = &m_entries[slot];
    __int64 selfId = FUN_1403ed2d0()->FUN_141bd0cc0()->FUN_141656a80();
    if (selfId != e->m_uid && !(FUN_14097a780()->FUN_140ae4d70(e->m_uid) == 1)) {
        UIAvatarPC* av = e->m_avatar;
        Unk_ClosingActor* actor = av ? av->FUN_1418bd1d0() : 0;
        if (!actor || e->m_clip == 0)
            return;
        MS2Ptr<ASMovieClip> info = e->m_clip->FUN_1409b4560("m_characterInfo");
        if (info.get()) {
            MS2Ptr<Unk_ClosingButton> btn = info->FUN_140acce30<Unk_ClosingButton>("m_addFriend");
            if (btn.get())
                btn->FUN_1422c1fe0(0);
        }
        Unk_BuddyRequest req;
        req.protocol = 2;
        req.name = actor->vfunc_77();
        req.memo = GetStringCommon(0x60a);
        FUN_14097a780()->FUN_140ae4820(req);
    }
}

// @0x140e10800
void UIDungeonClosingPhotoDialog::FUN_140e10800(int result, CStringW name)
{
    if (result == 0)
        return;
    CBuddyManager::Ptr buddy = FUN_14097a780()->FUN_140ae4950(name);
    if (buddy.get() == 0) {
        result -= 1;
        switch (result) {
        case 0: FUN_141275260(0x614, 1, 1); break;
        case 1: FUN_140961010(0x622, 1, 1, name); break;
        case 2: FUN_140961010(0x621, 1, 1, name); break;
        case 3: FUN_140961010(0x617, 1, 1, name); break;
        case 4: FUN_140961010(0x61c, 1, 1, name); break;
        case 5: FUN_140961010(0x61b, 1, 1, name); break;
        case 6: FUN_140961010(0x61d, 1, 1, name); break;
        case 7: FUN_140961010(0x61e, 1, 1, name); break;
        case 8: FUN_140961010(0x602, 1, 1, name); break;
        default: FUN_141275260(0x613, 1, 1); break;
        }
    } else {
        if (buddy->FUN_1401cc5d0() == 1)
            FUN_140961010(0x61a, 1, 1, name);
        else if (buddy->FUN_1401cc5b0() == 1)
            FUN_140961010(0x619, 1, 1, name);
    }
}

// @0x140e11d00
void Unk_ClosingActor::FUN_140e11d00() { m_12fc = 2; }

// @0x140e12610 (the UCRT header-inline memmove_s from corecrt_memcpy_s.h, emitted here as an ordinary function)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
errno_t FUN_140e12610(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140E0DFA0, UIDungeonClosingPhotoDialog, GetTypeName, 61, 0xCD36F508);
MS2_REPLACE_METHOD(0x140E0DFF0, UIDungeonClosingPhotoDialog, vfunc_26, 34, 0xA4E5FC6E);
MS2_REPLACE_METHOD(0x140E0E020, UIDungeonClosingPhotoDialog, vfunc_67, 98, 0xC53D4AD8);
MS2_REPLACE_METHOD(0x140E0E090, UIDungeonClosingPhotoDialog, vfunc_72, 175, 0xF7816ACA);
MS2_REPLACE_METHOD(0x140E0E150, UIDungeonClosingPhotoDialog, OnLoadComplete, 944, 0xE31868BF);
MS2_REPLACE_METHOD(0x140E0E510, UIDungeonClosingPhotoDialog, vfunc_25, 758, 0xD4C53FDF);
MS2_REPLACE_METHOD(0x140E0E810, UIDungeonClosingPhotoDialog, vfunc_16, 34, 0x491297CE);
MS2_REPLACE_METHOD(0x140E0E840, UIDungeonClosingPhotoDialog, vfunc_17, 47, 0x1B6E7A51);
MS2_REPLACE_METHOD(0x140E0E880, UIDungeonClosingPhotoDialog, vfunc_79, 212, 0x370462AD);
MS2_REPLACE_METHOD(0x140E0E960, UIDungeonClosingPhotoDialog, vfunc_28, 208, 0xB4AD78BB);
MS2_REPLACE_METHOD(0x140E0EA40, UIDungeonClosingPhotoDialog, FUN_140e0ea40, 52, 0xE31499F5);
MS2_REPLACE_METHOD(0x140E0F6B0, UIDungeonClosingPhotoDialog, FUN_140e0f6b0, 217, 0x26A6CA20);
MS2_REPLACE_METHOD(0x140E0F790, UIDungeonClosingPhotoDialog, FUN_140e0f790, 1360, 0x142313B4);
MS2_REPLACE_METHOD(0x140E0FCF0, UIDungeonClosingPhotoDialog, FUN_140e0fcf0, 38, 0xB5134428);
MS2_REPLACE_METHOD(0x140E0FE40, UIDungeonClosingPhotoDialog, FUN_140e0fe40, 251, 0x36262D83);
MS2_REPLACE_METHOD(0x140E0FF50, UIDungeonClosingPhotoDialog, FUN_140e0ff50, 176, 0x39D83762);
MS2_REPLACE_METHOD(0x140E10010, UIDungeonClosingPhotoDialog, FUN_140e10010, 666, 0xEE731CE4);
MS2_REPLACE_METHOD(0x140E102B0, UIDungeonClosingPhotoDialog, FUN_140e102b0, 533, 0x47263C5C);
MS2_REPLACE_METHOD(0x140E104D0, UIDungeonClosingPhotoDialog, FUN_140e104d0, 804, 0xD8A04FFD);
MS2_REPLACE_METHOD(0x140E10800, UIDungeonClosingPhotoDialog, FUN_140e10800, 616, 0x3ACFF152);
MS2_REPLACE_METHOD_VIA(0x140E0EA80, UIDungeonClosingPhotoDialog, IUIAvatarEventListener, vfunc_o178_1, 178, 0x0D4CB44B);
MS2_REPLACE_METHOD(0x140E11D00, Unk_ClosingActor, FUN_140e11d00, 21, 0x1856F557);
