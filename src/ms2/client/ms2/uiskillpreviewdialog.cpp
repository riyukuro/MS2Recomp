// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Skill preview avatar dialog.
// MS2-UNIT: client\ms2\uiskillpreviewdialog.cpp
// MS2-RANGE: 0x140e93690-0x140e943b0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiskillpreviewdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiskillpreviewdialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unit-local declarations for unrecovered avatar, camera and skill-data helpers.
struct Unk_SkillPreviewVector
{
    Unk_SkillPreviewVector();
    float x, y, z;
    Unk_SkillPreviewVector& operator+=(const Unk_SkillPreviewVector&);
};
MS2_CHECK_SIZE(Unk_SkillPreviewVector, 12);
struct Unk_SkillPreviewCameraData
{
    Unk_SkillPreviewCameraData();
    void FUN_141b48530();
    Unk_SkillPreviewVector eye, target;
    float f18, f1c, f20;
    int n24, n28, n2c;
};
MS2_CHECK_SIZE(Unk_SkillPreviewCameraData, 0x30);
class Unk_SkillPreviewActor
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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual Unk_SkillPreviewVector vfunc_18();
};
class Unk_SkillPreviewCamera
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
    virtual void vfunc_12();
    virtual void vfunc_13(const Unk_SkillPreviewCameraData&);
};
class Unk_SkillPreviewCameraPtr
{
public:
    ~Unk_SkillPreviewCameraPtr();
    Unk_SkillPreviewCamera* operator->() const;
private:
    Unk_SkillPreviewCamera* m_p;
};
MS2_CHECK_SIZE(Unk_SkillPreviewCameraPtr, 8);
class Unk_SkillPreviewAvatar
{
public:
    virtual void vfunc_0();
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
    virtual void vfunc_12();
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
    virtual Unk_SkillPreviewActor* vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual int vfunc_27(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual void vfunc_28(void*, TPtr<Unk_UISwfEntity_25>, void*, void*);
    void FUN_1418ba340(int);
    int FUN_1418b9b80();
    void FUN_1418bce80(int);
    void FUN_1418bcf60(int, unsigned short);
    Unk_SkillPreviewCameraPtr FUN_1418b9bc0();
};
class UIAvatarPC : public Unk_SkillPreviewAvatar
{
public:
    UIAvatarPC(void*, bool);
private:
    void* m_8;
    void* m_10;
    void* m_18;
    void* m_20;
    void* m_28;
    void* m_30;
    void* m_38;
    void* m_40;
    void* m_48;
    void* m_50;
    void* m_58;
    void* m_60;
    void* m_68;
    void* m_70;
    void* m_78;
    void* m_80;
    void* m_88;
    void* m_90;
    void* m_98;
    void* m_a0;
    void* m_a8;
    void* m_b0;
    void* m_b8;
    void* m_c0;
    void* m_c8;
    void* m_d0;
    void* m_d8;
    void* m_e0;
    void* m_e8;
};
MS2_CHECK_SIZE(UIAvatarPC, 0xf0);
class Unk_SkillPreviewAScript
{
public:
    Unk_SkillPreviewAScript(int);
    ~Unk_SkillPreviewAScript();
    Scaleform::GFx::Value& FUN_1422bb870();
private:
    void* m_0; void* m_8; void* m_10; void* m_18;
    void* m_20; void* m_28; void* m_30; void* m_38;
};
MS2_CHECK_SIZE(Unk_SkillPreviewAScript, 0x40);
class Unk_SkillPreviewSkill
{
public:
    bool FUN_1407e9d30();
};
class Unk_SkillPreviewSkillPtr
{
public:
    ~Unk_SkillPreviewSkillPtr();
    bool IsNull() const;
    Unk_SkillPreviewSkill* operator->() const;
private:
    void* m_0;
    Unk_SkillPreviewSkill* m_p;
};
MS2_CHECK_SIZE(Unk_SkillPreviewSkillPtr, 0x10);
class Unk_SkillPreviewSkillManager
{
public:
    Unk_SkillPreviewSkillPtr FUN_1407ee1d0(int);
};
Unk_SkillPreviewSkillManager* FUN_1401958b0();
class Unk_SkillPreviewPlayer
{
public:
    void* FUN_141bd0cc0();
};
Unk_SkillPreviewPlayer* FUN_1403ed2d0();

// @0x140e93690
UISkillPreviewDialog::UISkillPreviewDialog() : m_skill(0), m_level(0) {}

// @0x140e93740
UISkillPreviewDialog::~UISkillPreviewDialog() {}

// @0x140e937b0
CString UISkillPreviewDialog::GetTypeName() { return "SkillPreviewDialog"; }
MS2_REPLACE_METHOD(0x140E937B0, UISkillPreviewDialog, GetTypeName, 61, 0xFF814432);

// @0x140e93800
void UISkillPreviewDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_140e941b0();
}
MS2_REPLACE_METHOD(0x140E93800, UISkillPreviewDialog, vfunc_26, 34, 0x7AF3593D);

// @0x140e93830
void UISkillPreviewDialog::vfunc_67()
{
    m_avatar.Reset(0);
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140E93830, UISkillPreviewDialog, vfunc_67, 45, 0x89DA258E);

// @0x140e93870
int UISkillPreviewDialog::vfunc_65()
{
    if (!vfunc_55()) FUN_1419235d0();
    m_skill = 0;
    m_level = 0;
    FUN_140e93ff0();
    return UIDialog::vfunc_65();
}
MS2_REPLACE_METHOD(0x140E93870, UISkillPreviewDialog, vfunc_65, 96, 0xDE108BC1);

// @0x140e938e0
void UISkillPreviewDialog::OnLoadComplete() { UIDialog::OnLoadComplete(); }
MS2_REPLACE_METHOD(0x140E938E0, UISkillPreviewDialog, OnLoadComplete, 24, 0xAF35FBEC);

// @0x140e93900
void UISkillPreviewDialog::vfunc_15() { vfunc_55(); }
MS2_REPLACE_METHOD(0x140E93900, UISkillPreviewDialog, vfunc_15, 33, 0x18A5D356);

// @0x140e93930
int UISkillPreviewDialog::vfunc_28(const char* method, const Scaleform::GFx::Value* args, unsigned int count)
{
    if (UIDialog::vfunc_28(method, args, count)) return 1;
    if (m_avatar.get() ? true : false) {
        if (m_avatar->vfunc_27(method, args, count)) return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E93930, UISkillPreviewDialog, vfunc_28, 181, 0x729656BC);

// @0x140e939f0
void UISkillPreviewDialog::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (vfunc_55() || m_30 == 0) return;
    if (m_avatar == 0) return;
    if (!p2.get() || !p3) return;
    m_avatar->FUN_1418ba340(1);
    Unk_SkillPreviewActor* actor = m_avatar->vfunc_24();
    if (!actor) return;
    m_avatar->vfunc_28(p1, p2, p3, p4);
    FUN_140e93e70(m_skill, m_level);
    Unk_SkillPreviewCameraData data;
    data.FUN_141b48530();
    data.f1c = 1000.0f;
    data.n2c = 2;
    data.n28 = 5;
    data.target += actor->vfunc_18();
    data.eye += data.target;
    m_avatar->FUN_1418b9bc0()->vfunc_13(data);
}
MS2_REPLACE_METHOD(0x140E939F0, UISkillPreviewDialog, vfunc_25, 721, 0x173AD909);

// @0x140e93cd0
void UISkillPreviewDialog::vfunc_16()
{
    UISwfEntity::vfunc_16();
    FUN_140e941b0();
}
MS2_REPLACE_METHOD(0x140E93CD0, UISkillPreviewDialog, vfunc_16, 34, 0x0C98A2FC);

// @0x140e93d00
bool UISkillPreviewDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17()) return false;
    FUN_140e94150();
    return true;
}
MS2_REPLACE_METHOD(0x140E93D00, UISkillPreviewDialog, vfunc_17, 47, 0x298FF795);

// @0x140e93d40
int UISkillPreviewDialog::vfunc_o178_1(void* avatar)
{
    if (!avatar) return 0;
    FUN_140e94150();
    Unk_SkillPreviewAScript data(2);
    m_30->Invoke("initData", data.FUN_1422bb870());
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x140E93D40, UISkillPreviewDialog, IUIAvatarEventListener, vfunc_o178_1, 221, 0x2DA9586A);

// @0x140e93e30
int UISkillPreviewDialog::vfunc_o178_0(void*) { return 1; }
MS2_REPLACE_METHOD_VIA(0x140E93E30, UISkillPreviewDialog, IUIAvatarEventListener, vfunc_o178_0, 16, 0x32804D89);

// @0x140e93e50
int UISkillPreviewDialog::vfunc_o178_2(void*) { return 1; }
MS2_REPLACE_METHOD_VIA(0x140E93E50, UISkillPreviewDialog, IUIAvatarEventListener, vfunc_o178_2, 16, 0x32804D89);

// @0x140e93e70
void UISkillPreviewDialog::FUN_140e93e70(int skill, unsigned short level)
{
    if (!skill) return;
    if (!m_avatar) return;
    m_skill = skill;
    m_level = level;
    if (!m_avatar->FUN_1418b9b80()) return;
    Unk_SkillPreviewSkillPtr data = FUN_1401958b0()->FUN_1407ee1d0(skill);
    if (data.IsNull()) { MS2_ASSERT_AT(162, 0); return; }
    if (data->FUN_1407e9d30()) m_avatar->FUN_1418bce80(skill);
    else m_avatar->FUN_1418bcf60(skill, level);
    m_skill = 0;
    m_level = 0;
}
MS2_REPLACE_METHOD(0x140E93E70, UISkillPreviewDialog, FUN_140e93e70, 368, 0xA3D6BD91);

// @0x140e93ff0
void UISkillPreviewDialog::FUN_140e93ff0()
{
    if (m_avatar.get()) return;
    Unk_SkillPreviewPlayer* player = FUN_1403ed2d0();
    if (!player) { MS2_ASSERT_AT(188, 0); return; }
    void* actor = player->FUN_141bd0cc0();
    if (!actor) { MS2_ASSERT_AT(195, 0); return; }
    m_avatar = new UIAvatarPC(actor, true);
    m_avatar->vfunc_1(this);
}
MS2_REPLACE_METHOD(0x140E93FF0, UISkillPreviewDialog, FUN_140e93ff0, 342, 0x09033A99);

// @0x140e94150
void UISkillPreviewDialog::FUN_140e94150()
{
    if (m_30.get()) m_30->Invoke("loadRenderTarget");
}
MS2_REPLACE_METHOD(0x140E94150, UISkillPreviewDialog, FUN_140e94150, 83, 0xD1FBA7E2);

// @0x140e941b0
void UISkillPreviewDialog::FUN_140e941b0()
{
    if (m_30.get()) m_30->Invoke("unloadRenderTarget");
}
MS2_REPLACE_METHOD(0x140E941B0, UISkillPreviewDialog, FUN_140e941b0, 83, 0x830FFE0B);

MS2_EMIT_CRT_MEMMOVE_S();
