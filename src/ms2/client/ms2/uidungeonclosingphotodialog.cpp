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
#include "ms2/placeholder/asbutton.h"   // C3: ASButton ("m_addFriend")
#include "ms2/placeholder/cinpacket.h"
#include "buddymanager.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/uiservice.h"
#include <algorithm>
#include <errno.h>
#include <string.h>
#include "ms2/placeholder/ichromamanager.h"  // C3: ChromaSDK::GetChromaManager
#include "ms2/client/ms2/uirenderview.h"
#include "ms2/client/ms2/uimassiveevent.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/client/ms2/uirenderview.h"
#include "ms2/commonfiles/serverpacketdef.h"
static CString s_winSound = "BattleField_Win";

// ---- local stand-ins for classes whose units are not recovered yet ----
enum Unk_ClosingJob { Unk_ClosingJob_None };
class Unk_ClosingThing : public PCGemEquip { };
class PC { public: class Unk_MyPCEquip* GetGemEquip(); int GetSubJob(); };   // C3: unit-local view (def in pc); the gem equipment
class Unk_ModelViewCamera   // uimodelview.h's camera preset (0x30), unit-local field names
{ public:
    Unk_ModelViewCamera(); void ApplyCharCamera();
    efd::Point3 eye, target;
    float f18, f1c, f20;
    int n24, n28, n2c;
};
typedef Unk_ModelViewCamera Unk_PetBoxCameraData; MS2_CHECK_SIZE(Unk_ModelViewCamera, 0x30);
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
    virtual efd::Point3 vfunc_18();
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
    virtual void vfunc_13(const Unk_PetBoxCameraData&);
};
class UIAvatarBase
{
public:
    efd::SmartPointer<UIRenderView> GetView();
};
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
};
class UIAvatarPC : public Unk_ClosingAvatar
{
public:
    UIAvatarPC(PC*, bool);
    void FUN_1418bc790(int, int);
    class AvatarPC* FUN_1418bd1d0();
private:
    void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48; void* m_50; void* m_58;
    void* m_60; void* m_68; void* m_70; void* m_78; void* m_80; void* m_88; void* m_90; void* m_98; void* m_a0;
    void* m_a8; void* m_b0; void* m_b8; void* m_c0; void* m_c8; void* m_d0; void* m_d8; void* m_e0; void* m_e8;
};
MS2_CHECK_SIZE(UIAvatarPC, 0xf0);
class Unk_ClosingSelf : public PCBase { };
// The PC: the name getter is vtable slot 77 (+0x268).
class Unk_ClosingPlayer
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76();
    virtual CStringW vfunc_77();
};
class Unk_ClosingWorld : public WorldService
{
public:
    Unk_ClosingSelf* FUN_141bd0cc0();
};
class Unk_ClosingUIMgr { public: void FUN_141adc530(int); };
class Unk_ClosingClip : public ASUIComponent
{
public:
    // ASUIComponent slots 16-23 (not declared by the placeholder); vfunc_24 is slot 24 (+0xc0, 0x140e0e3f1)
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23();
    virtual void vfunc_24(bool);
};
class ClonePC { public: void FUN_1410885b0(bool b); };   // clonepc.h brings a PC that clashes with this unit's PC view
class Unk_BuddyInput { public: virtual unsigned vfunc_0(); };
class UIMassiveEvent* FUN_140e01890(int);   // C3: was FUN_140e01890
void SetChildText(const Scaleform::GFx::Value&, CString, CStringW);
void FUN_140cffca0(const Scaleform::GFx::Value&, CString, CString);
CStringW GetStringCommonByKey(const CStringW&);
CStringW GetStringCommon(int);
void FUN_141275260(int, int, int);
template <class T> void Unk_AkoMessage(int, int, int, const T&);   // C3: was FUN_140961010
int FUN_141276180(const CString&, const CString&);
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
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
    ClearEntries();
}

// @0x140e0e020
void UIDungeonClosingPhotoDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_1b4 = 0;
    if (reinterpret_cast<Unk_ClosingWorld*>(WorldService::GetInstance())->FUN_141bd3060() == m_1bc)
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4ef9)));
    m_1bc = 0;
}

// @0x140e0e090
void UIDungeonClosingPhotoDialog::vfunc_72()
{
    if (m_1b0 != 0 && m_1b0 < GetTickCountMs2()) {
        m_1b0 = 0;
        if (reinterpret_cast<Unk_ClosingWorld*>(WorldService::GetInstance())->FUN_141bd3060() == m_1bc)
            FUN_141924680();
    } else {
        if (m_1b4 == 0)
            return;
        unsigned int nNow = GetTickCountMs2();
        if (m_1b4 < nNow) {
            m_1b4 = 0;
            vfunc_67();
        }
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
        FUN_140e10010(x, y, scale, (int)(i + 1), n);
        static_cast<Unk_ClosingClip*>(e.m_clip.operator->())->SetPositionFloat((float)x, (float)y);
        static_cast<ASDisplayObject*>(static_cast<Unk_ClosingClip*>(e.m_clip.operator->()))->SetScaleInt(scale, scale);
        static_cast<Unk_ClosingClip*>(e.m_clip.operator->())->vfunc_24(1);
        FUN_140e102b0(&e);
    }
    {
        std::vector<int> pending(m_pending);
        m_pending.clear();
        for (size_t k = 0; k < pending.size(); ++k)
            LoadEntryRenderTarget(pending[k]);
    }
    FUN_140e0f790();
    int delay = 5000;
    if (n >= 5)
        delay = 8000;
    m_1b4 = GetTickCountMs2() + delay;
    m_1b8 = false;
}

// @0x140e0e510
void UIDungeonClosingPhotoDialog::vfunc_25(void* a, TPtr<Unk_UISwfEntity_25> tp, void* b, void* c)
{
    if (tp.get() == 0 || b == 0)
        return;
    int idx = FUN_140718170(*static_cast<const CString*>(c));
    if (idx < 0 || idx > (int)m_entries.size())
        return;
    if (m_entries[idx].m_avatar == 0)
        return;
    Unk_ClosingActor* actor = m_entries[idx].m_avatar->vfunc_24();
    if (!actor)
        return;
    m_entries[idx].m_avatar->vfunc_28(a, tp, b, c);
    Unk_PetBoxCameraData data;
    reinterpret_cast<Unk_ModelViewCamera*>(&data)->ApplyCharCamera();
    data.f1c = 300.0f;
    data.target += actor->vfunc_18();
    data.eye += data.target;
    reinterpret_cast<Unk_ClosingCamera*>(reinterpret_cast<UIAvatarBase*>(m_entries[idx].m_avatar.operator->())->GetView().operator->())->vfunc_13(data);
    m_entries[idx].m_avatar->FUN_1418bc790(14, 85);
}

// @0x140e0e810
void UIDungeonClosingPhotoDialog::vfunc_16()
{
    UISwfEntity::vfunc_16();
    UnloadAllRenderTargets();
}

// @0x140e0e840
bool UIDungeonClosingPhotoDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    LoadAllRenderTargets();
    return true;
}

// @0x140e0e880
void UIDungeonClosingPhotoDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (static_cast<CInPacket*>(p)->FUN_14070fe80() == 0x61) {
        unsigned pos = static_cast<Unk_BuddyInput*>(p)->vfunc_0();
        Unk_BuddyResponse r;
        reinterpret_cast<Unk_SPDB*>(&r)->FUN_1407a3cc0(*reinterpret_cast<Unk_SPDReader*>(p));
        static_cast<CInPacket*>(p)->SetOffset(pos);
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
        if (d.SetArgsIfAny(pArgs, nArgs))
            FUN_140e104d0(d.PopInt());
        return 1;
    }
    return 0;
}

// @0x140e0ea40
bool UIDungeonClosingPhotoDialog::FUN_140e0ea40()
{
    if (m_1b0 != 0)
        return true;
    if (FUN_141924630() != 0)
        return true;
    return false;
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
        LoadEntryRenderTarget(found);
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
            case 0: text = FUN_14028dfa0(CStringW(L"s_dungeon_record_accum_damage"), value); break;
            case 1: text = FUN_14028dfa0(CStringW(L"s_dungeon_record_accum_heal"), value); break;
            case 2: text = FUN_14028dfa0(CStringW(L"s_dungeon_record_accum_hit_count"), value); break;
            case 3: text = FUN_14028dfa0(CStringW(L"s_dungeon_record_boss_last_hit"), value); break;
            case 4: text = FUN_14028dfa0(CStringW(L"s_dungeon_record_accum_move_distance"), value); break;
            case 5: text = FUN_14028dfa0(CStringW(L"s_dungeon_record_accum_critical_damage"), value); break;
            case 6: text = FUN_14028dfa0(CStringW(L"s_dungeon_record_max_critial_damage"), value); break;
            case 7: text = FUN_14028dfa0(CStringW(L"s_dungeon_record_accum_monster_kill"), value); break;
            case 8: text = FUN_14028dfa0(CStringW(L"s_dungeon_record_accum_be_hit_count"), value); break;
            case 9: text = FUN_14028dfa0(CStringW(L"s_dungeon_record_accum_default_skill_damage"), value); break;
            }
        }
        if (m_entries.size() < 10) {
            Unk_ClosingPlayer* player = reinterpret_cast<Unk_ClosingPlayer*>(WorldService::GetInstance()->FUN_141bd1530(uid));
            if (player == 0)
                continue;
            UIAvatarPC* av = new UIAvatarPC(reinterpret_cast<PC*>(player), false);
            reinterpret_cast<Unk_ClosingActor*>(av->FUN_1418bd1d0())->vfunc_76(player->vfunc_77());
            reinterpret_cast<Unk_ClosingActor*>(av->FUN_1418bd1d0())->FUN_140e11d00();
            reinterpret_cast<ClonePC*>(av->FUN_1418bd1d0())->FUN_1410885b0(true);
            reinterpret_cast<Unk_ClosingThing*>(reinterpret_cast<PC*>(av->FUN_1418bd1d0())->GetGemEquip())->FUN_141270610();
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
    m_1bc = reinterpret_cast<Unk_ClosingWorld*>(WorldService::GetInstance())->FUN_141bd3060();
    unsigned flag = 0;
    switch (res) {
    case 1: {
        UIMassiveEvent* dlg = FUN_140e01890(0x4e4c);
        if (dlg) {
            flag = 2000;
            ChromaSDK::GetChromaManager()->SetState(9);
            dlg->FUN_1419f6a70(5, GetStringCommonByKey(L"s_room_dungeon_clear"), 2000);
            FUN_141276180(s_winSound, "");
        }
        break;
    }
    case 2: {
        UIMassiveEvent* dlg = FUN_140e01890(0x4e4c);
        if (dlg) {
            flag = 2000;
            dlg->FUN_1419f6a70(7, GetStringCommonByKey(L"s_room_dungeon_fail"), 2000);
        }
        break;
    }
    }
    if (flag > 0)
        FUN_140e0fcf0(2000);
    else
        FUN_141924680();
}

// @0x140e0f6b0
void UIDungeonClosingPhotoDialog::ClearEntries()
{
    UnloadAllRenderTargets();
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
        if (m_entries[i].m_clip == 0)
            continue;
        UIAvatarPC* av = m_entries[i].m_avatar;
        if (!av)
            continue;
        Unk_ClosingActor* actor = reinterpret_cast<Unk_ClosingActor*>(av->FUN_1418bd1d0());
        if (!actor)
            continue;
        MS2Ptr<ASMovieClip> info = m_entries[i].m_clip->FUN_1409b4560("m_characterInfo");
        if (info == 0)
            return;
        MS2Ptr<ASMovieClip> charInfo = info->FUN_1409b4560("m_charInfo");
        if (charInfo.get()) {
            SetChildText((*charInfo).FUN_1422bb890(), "m_charName", actor->vfunc_77());
            Unk_ClosingJob job = (Unk_ClosingJob)reinterpret_cast<PC*>(actor)->GetSubJob();
            CString jobStr = StringFormat("_{0}", job);
            FUN_140cffca0((*charInfo).FUN_1422bb890(), "m_jobMovie", jobStr);
        }
        MS2Ptr<ASMovieClip> rank = info->FUN_1409b4560("m_rank");
        if (rank.get()) {
            if (m_entries[i].m_rank >= 0) {
                CString rankStr = GetRankName(m_entries[i].m_rank);
                rank->vfunc_4(true);
                rank->vfunc_15(rankStr);
            } else {
                rank->vfunc_4(false);
            }
        }
        SetChildText((*info).FUN_1422bb890(), "m_etcInfo", m_entries[i].m_text);
    }
}

// @0x140e0fcf0
void UIDungeonClosingPhotoDialog::FUN_140e0fcf0(int n)
{
    m_1b0 = GetTickCountMs2() + n;
}

// @0x140e0fd20
void UIDungeonClosingPhotoDialog::LoadEntryRenderTarget(int idx)
{
    if (idx > (int)m_entries.size())
        return;
    if (m_entries[idx].m_clip)
        m_entries[idx].m_clip->Invoke("loadRenderTarget", StringFormat(L"{0}", idx));
    else
        m_pending.push_back(idx);
}

// @0x140e0fe40
void UIDungeonClosingPhotoDialog::LoadAllRenderTargets()
{
    for (size_t i = 0; i < m_entries.size(); ++i) {
        if (m_entries[i].m_clip.get())
            m_entries[i].m_clip->Invoke("loadRenderTarget", StringFormat(L"{0}", i));
    }
}

// @0x140e0ff50
void UIDungeonClosingPhotoDialog::UnloadAllRenderTargets()
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
    int nWidth = 0x1ac;
    int nHeight = 0x26a;
    int nGap = 10;
    int nRowGap = 0x32;
    if (total > 4) {
        nWidth = 0x156;
        nHeight = 0x1ee;
        scale = 0x50;
    } else {
        scale = 100;
    }
    if (total <= 4) {
        int nSpan = total * nWidth + (total - 1) * nGap;
        int nLeft = -(nSpan / 2);
        x = nLeft + (slot - 1) * (nWidth + nGap);
        y = -(nHeight / 2);
    } else {
        int nCol = slot;
        int nHalf = total / 2;
        int nRest = total - nHalf;
        int nCount = nHalf;
        if (slot > nHalf) {
            nCount = nRest;
            nCol = nCol - nHalf;
            y = nRowGap / 2;
        } else {
            nCount = nHalf;
            y = -(nHeight + nRowGap / 2);
        }
        int nSpan = nCount * nWidth + (nCount - 1) * nGap;
        int nLeft = -(nSpan / 2);
        x = nLeft + (nCol - 1) * (nWidth + nGap);
    }
    MS2Ptr<ASMovieClip> bg = GetChild<ASMovieClip>("m_bg");
    if (bg.get()) {
        x += bg->FUN_1422c1340() / 2;
        y += bg->GetHeightCeil() / 2;
    }
}

// @0x140e102b0
void UIDungeonClosingPhotoDialog::FUN_140e102b0(Unk_ClosingEntry* e)
{
    if (MS2Ptr<ASMovieClip> info = e->m_clip->FUN_1409b4560("m_characterInfo")) {
        if (MS2Ptr<ASButton> btn = info->FUN_140acce30<ASButton>("m_addFriend")) {
            Unk_ClosingSelf* self = ((Unk_ClosingSelf*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
            bool isSelf = self ? self->FUN_141656a80() == e->m_uid : false;
            bool buddy = TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4d70(e->m_uid);
            bool show = !isSelf && !buddy;
            btn->vfunc_4(show);
            btn->FUN_1422c1fe0(show);
        }
    }
}

// @0x140e104d0
void UIDungeonClosingPhotoDialog::FUN_140e104d0(int slot)
{
    int idx = slot - 1;
    int valid;
    if (idx >= 0 && idx <= (int)m_entries.size() - 1)
        valid = 1;
    else
        valid = 0;
    if (!valid)
        return;
    Unk_ClosingEntry* e = &m_entries[idx];
    if (((Unk_ClosingSelf*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0())->FUN_141656a80() == e->m_uid)
        return;
    if (TSingleton<CBuddyManager>::GetInstance()->FUN_140ae4d70(e->m_uid) == 1)
        return;
    {
        UIAvatarPC* av = e->m_avatar.get();
        if (!av)
            return;
        Unk_ClosingActor* actor = reinterpret_cast<Unk_ClosingActor*>(av->FUN_1418bd1d0());
        if (!actor)
            return;
        if (e->m_clip == 0)
            return;
        if (MS2Ptr<ASMovieClip> info = e->m_clip->FUN_1409b4560("m_characterInfo")) {
            if (MS2Ptr<ASButton> btn = info->FUN_140acce30<ASButton>("m_addFriend"))
                btn->FUN_1422c1fe0(0);
        }
        Unk_BuddyRequest req;
        req.protocol = 2;
        req.name = actor->vfunc_77();
        req.memo = GetStringCommon(0x60a);
        TSingleton<CBuddyManager>::GetInstance()->SendBuddyRequest(req);
    }
}

// @0x140e10800
void UIDungeonClosingPhotoDialog::FUN_140e10800(int result, CStringW name)
{
    if (result == 0)
        return;
    CBuddyManager::Ptr buddy = TSingleton<CBuddyManager>::GetInstance()->FindByName(name);
    if (buddy.get()) {
        if (buddy->FUN_1401cc5d0() == 1) {
            Unk_AkoMessage<CStringW>(0x61a, 1, 1, name);
            return;
        } else if (buddy->FUN_1401cc5b0() == 1) {
            Unk_AkoMessage<CStringW>(0x619, 1, 1, name);
            return;
        }
    } else {
        switch (result) {
        case 1: FUN_141275260(0x614, 1, 1); break;
        case 2: Unk_AkoMessage<CStringW>(0x622, 1, 1, name); break;
        case 3: Unk_AkoMessage<CStringW>(0x621, 1, 1, name); break;
        case 4: Unk_AkoMessage<CStringW>(0x617, 1, 1, name); break;
        case 5: Unk_AkoMessage<CStringW>(0x61c, 1, 1, name); break;
        case 6: Unk_AkoMessage<CStringW>(0x61b, 1, 1, name); break;
        case 7: Unk_AkoMessage<CStringW>(0x61d, 1, 1, name); break;
        case 8: Unk_AkoMessage<CStringW>(0x61e, 1, 1, name); break;
        case 9: Unk_AkoMessage<CStringW>(0x602, 1, 1, name); break;
        default: FUN_141275260(0x613, 1, 1); break;
        }
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
MS2_REPLACE_METHOD(0x140E0F6B0, UIDungeonClosingPhotoDialog, ClearEntries, 217, 0x26A6CA20);
MS2_REPLACE_METHOD(0x140E0F790, UIDungeonClosingPhotoDialog, FUN_140e0f790, 1360, 0x142313B4);
MS2_REPLACE_METHOD(0x140E0FCF0, UIDungeonClosingPhotoDialog, FUN_140e0fcf0, 38, 0xB5134428);
MS2_REPLACE_METHOD(0x140E0FE40, UIDungeonClosingPhotoDialog, LoadAllRenderTargets, 251, 0x36262D83);
MS2_REPLACE_METHOD(0x140E0FF50, UIDungeonClosingPhotoDialog, UnloadAllRenderTargets, 176, 0x39D83762);
MS2_REPLACE_METHOD(0x140E10010, UIDungeonClosingPhotoDialog, FUN_140e10010, 666, 0xEE731CE4);
MS2_REPLACE_METHOD(0x140E102B0, UIDungeonClosingPhotoDialog, FUN_140e102b0, 533, 0x47263C5C);
MS2_REPLACE_METHOD(0x140E104D0, UIDungeonClosingPhotoDialog, FUN_140e104d0, 804, 0xD8A04FFD);
MS2_REPLACE_METHOD(0x140E10800, UIDungeonClosingPhotoDialog, FUN_140e10800, 616, 0x3ACFF152);
MS2_REPLACE_METHOD_VIA(0x140E0EA80, UIDungeonClosingPhotoDialog, IUIAvatarEventListener, vfunc_o178_1, 178, 0x0D4CB44B);
MS2_REPLACE_METHOD(0x140E11D00, Unk_ClosingActor, FUN_140e11d00, 21, 0x1856F557);
