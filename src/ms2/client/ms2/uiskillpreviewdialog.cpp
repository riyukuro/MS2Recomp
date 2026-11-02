// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Skill preview avatar dialog.
// MS2-UNIT: client\ms2\uiskillpreviewdialog.cpp
// MS2-RANGE: 0x140e93690-0x140e943b0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiskillpreviewdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiskillpreviewdialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/client/ms2/uiavatarbase.h"
#include "ms2/client/ms2/uimodelview.h"
#include "ms2/client/ms2/gameobject.h"

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
    UnloadRenderTarget();
}
MS2_REPLACE_METHOD(0x140E93800, UISkillPreviewDialog, vfunc_26, 34, 0x7AF3593D);

// @0x140e93830
void UISkillPreviewDialog::vfunc_67()
{
    m_avatar = 0;
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
    GameObject* actor = m_avatar->vfunc_24();
    if (!actor) return;
    m_avatar->vfunc_28(p1, p2, p3, p4);
    FUN_140e93e70(m_skill, m_level);
    Unk_ModelViewCamera data;
    data.ApplyCharCamera();
    data.m_fMinDistance = 1000.0f;
    data.m_nStepsDone = 2;
    data.m_nSteps = 5;
    data.m_kTarget += actor->vfunc_18();
    data.m_kPosition += data.m_kTarget;
    m_avatar->GetView()->vfunc_13(data);
}
MS2_REPLACE_METHOD(0x140E939F0, UISkillPreviewDialog, vfunc_25, 721, 0x173AD909);

// @0x140e93cd0
void UISkillPreviewDialog::vfunc_16()
{
    UISwfEntity::vfunc_16();
    UnloadRenderTarget();
}
MS2_REPLACE_METHOD(0x140E93CD0, UISkillPreviewDialog, vfunc_16, 34, 0x0C98A2FC);

// @0x140e93d00
bool UISkillPreviewDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17()) return false;
    LoadRenderTarget();
    return true;
}
MS2_REPLACE_METHOD(0x140E93D00, UISkillPreviewDialog, vfunc_17, 47, 0x298FF795);

// @0x140e93d40
int UISkillPreviewDialog::vfunc_o178_1(void* avatar)
{
    if (!avatar) return 0;
    LoadRenderTarget();
    AScript data(2);
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
    if (!m_avatar->IsLoaded()) return;
    MS2Ptr<SkillData> data = reinterpret_cast<SkillDataTable*>(TSingleton<SkillDataTableCli>::GetInstance())->GetSkillData(skill);
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
    WorldService* player = WorldService::GetInstance();
    if (!player) { MS2_ASSERT_AT(188, 0); return; }
    PC* actor = reinterpret_cast<PC*>(player->FUN_141bd0cc0());
    if (!actor) { MS2_ASSERT_AT(195, 0); return; }
    m_avatar.AssignRaw(new UIAvatarPC(actor, true));
    m_avatar->vfunc_1(this);
}
MS2_REPLACE_METHOD(0x140E93FF0, UISkillPreviewDialog, FUN_140e93ff0, 342, 0x09033A99);

// @0x140e94150
void UISkillPreviewDialog::LoadRenderTarget()
{
    if (m_30.get()) m_30->Invoke("loadRenderTarget");
}
MS2_REPLACE_METHOD(0x140E94150, UISkillPreviewDialog, LoadRenderTarget, 83, 0xD1FBA7E2);

// @0x140e941b0
void UISkillPreviewDialog::UnloadRenderTarget()
{
    if (m_30.get()) m_30->Invoke("unloadRenderTarget");
}
MS2_REPLACE_METHOD(0x140E941B0, UISkillPreviewDialog, UnloadRenderTarget, 83, 0x830FFE0B);

MS2_EMIT_CRT_MEMMOVE_S();
