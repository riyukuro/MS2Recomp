// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGemSettingDialog: choose the slots the transparency gem hides.
// MS2-UNIT: ?\uigemsettingdialog.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x140113990-0x140113b00 .text$di
// MS2-RANGE: 0x141946030-0x141946c10 .text$mn
// MS2-RANGE: 0x142cbe1f0-0x142cbe280 .text$yd
// MS2-PIN: ??0Unk_GsSetting@@QEAA@XZ 0x141946b90
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigemsettingdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uigemsettingdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/pcgemequip.h"

// ---- unit-local views of exe types ----

// The check box child (value at FUN_1422ce0e0, set at FUN_1422ce090), returned in an MS2Ptr<ASCheckBox>.
class Unk_GsCheck : public ASButton { };
class ASCheckBox;
class UIItemPetBoxDialog : public UIDialog { public: MS2Ptr<ASCheckBox> FindCheckBox(const CString& strName); };   // C3: FUN_140e52670, the check box child

// The worn equipment: the gem in a slot.
class Unk_GsEquip : public PCGemEquip { };

// The setting the server gets: the gem type and one hidden flag per equip slot.
struct Unk_GsSetting
{
    Unk_GsSetting();                                            // 0x141946b90
    unsigned char m_nType;
    int m_aHidden[10];
};
MS2_CHECK_SIZE(Unk_GsSetting, 0x2c);

// ---- out-of-unit callees ----
extern int DAT_1439f9284;                                       // the slot of the gem being set (-1 = none)
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
class PC   // C3: member view for the former free stand-ins
{
public:
    class Unk_MyPCEquip* GetGemEquip();
};
void FUN_1405a8650(MS2Ptr<CGemBase>& sp);                       // MS2Ptr release
void FUN_1401fd2e0(unsigned char* payload, COutputStream& stream);   // write the setting (unit_1401f9eb0.h)
void FUN_140710590(COutPacket& packet);                         // send

Unk_GsSetting::Unk_GsSetting()
    : m_nType(0), m_aHidden()
{
}

// @0x141946030
UIGemSettingDialog::UIGemSettingDialog()
{
    FUN_141924170(0);
}

// @0x141946090
UIGemSettingDialog::~UIGemSettingDialog()
{
}

// @0x1419460d0
CString UIGemSettingDialog::GetTypeName()
{
    return CString("GemSettingDialog");
}

// @0x141946120
void UIGemSettingDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
}

// @0x1419469b0
CGemTransparency* UIGemSettingDialog::FUN_1419469b0()
{
    if (DAT_1439f9284 == -1)
        return 0;
    void* pActor = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pActor == 0)
        return 0;
#ifdef __clang__
    MS2Ptr<CGemBase> spGem = ((class Unk_GsEquip*)((class PC*)(void*)(pActor))->GetGemEquip())->FUN_141270740(1);   // clang-cl won't bind the temporary to MS2Ptr&
    return dynamic_cast<CGemTransparency*>(spGem.operator->());
#else
    return dynamic_cast<CGemTransparency*>(((class Unk_GsEquip*)((class PC*)(void*)(pActor))->GetGemEquip())->FUN_141270740(1).operator->());
#endif
}

// @0x141946140
void UIGemSettingDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    CGemTransparency* pGem = FUN_1419469b0();
    if (pGem == 0)
    {
        vfunc_67();
        return;
    }
    FUN_141946b10("m_cp", pGem->IsSlotHidden(0));
    FUN_141946b10("m_ey", pGem->IsSlotHidden(1));
    FUN_141946b10("m_cl", pGem->IsSlotHidden(2));
    FUN_141946b10("m_pa", pGem->IsSlotHidden(3));
    FUN_141946b10("m_mt", pGem->IsSlotHidden(4));
    FUN_141946b10("m_ea", pGem->IsSlotHidden(5));
    FUN_141946b10("m_fh", pGem->IsSlotHidden(6));
    FUN_141946b10("m_gl", pGem->IsSlotHidden(7));
    FUN_141946b10("m_ri", pGem->IsSlotHidden(8));
    FUN_141946b10("m_sh", pGem->IsSlotHidden(9));
}

// @0x141946510
int UIGemSettingDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    return 0;
}

// @0x141946560
int UIGemSettingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnOk", szMethod) == 0)
    {
        if (DAT_1439f9284 == -1)
            return 1;
        if (FUN_1419469b0() == 0)
            return 1;
        Unk_GsSetting setting;
        setting.m_nType = (unsigned char)DAT_1439f9284;
        setting.m_aHidden[0] = FUN_141946a70("m_cp");
        setting.m_aHidden[1] = FUN_141946a70("m_ey");
        setting.m_aHidden[2] = FUN_141946a70("m_cl");
        setting.m_aHidden[3] = FUN_141946a70("m_pa");
        setting.m_aHidden[4] = FUN_141946a70("m_mt");
        setting.m_aHidden[5] = FUN_141946a70("m_ea");
        setting.m_aHidden[6] = FUN_141946a70("m_fh");
        setting.m_aHidden[7] = FUN_141946a70("m_gl");
        setting.m_aHidden[8] = FUN_141946a70("m_ri");
        setting.m_aHidden[9] = FUN_141946a70("m_sh");
        COutPacket packet(static_cast<int>(SendOp::BadgeEquip), 0);
        packet.WriteUInt8(3);
        FUN_1401fd2e0((unsigned char*)&setting, packet);
        FUN_140710590(packet);
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: op-identical; the frame is 16 bytes larger than the exe (the 24-byte handle FUN_141946b10 needs leaves a dead slot here)
// @0x141946a70
int UIGemSettingDialog::FUN_141946a70(CString strName)
{
    {
        MS2Ptr<ASCheckBox> hCheck = GetChild<ASCheckBox>(strName);
        if ((ASCheckBox*)hCheck != 0)
            return reinterpret_cast<Unk_GsCheck*>(hCheck.operator->())->FUN_1422ce0e0();
    }
    return 0;
}

// @0x141946b10
void UIGemSettingDialog::FUN_141946b10(CString strName, int nValue)
{
    MS2Ptr<ASCheckBox> hCheck = GetChild<ASCheckBox>(strName);
    if ((ASCheckBox*)hCheck != 0)
        reinterpret_cast<Unk_GsCheck*>(hCheck.operator->())->FUN_1422ce090(nValue);
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x1419460D0, UIGemSettingDialog, GetTypeName, 61, 0xB036F7FD);
