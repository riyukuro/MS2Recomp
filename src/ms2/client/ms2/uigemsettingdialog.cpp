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

// ---- unit-local views of exe types ----

// The check box child (value at FUN_1422ce0e0, set at FUN_1422ce090) and the handle it is returned in (24 bytes).
class Unk_GsCheck { public: bool FUN_1422ce0e0(); void FUN_1422ce090(int checked); };
class Unk_GsHandle
{
public:
    Unk_GsHandle() {}
    int FUN_140a58460();
    Unk_GsCheck* FUN_140a58490();
    void FUN_140a583d0();
private:
    char m_pad[0x18];
};
class Unk_GsEntity : public UIDialog { public: Unk_GsHandle FUN_140e52670(const CString& strName); };

// The worn equipment: the gem in a slot.
class Unk_GsEquip { public: MS2Ptr<CGemBase> FUN_141270740(int nSlot); };

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
void* FUN_1403ed2d0();                                          // the local player
void* FUN_141bd0cc0(void* pPlayer);                             // its actor
Unk_GsEquip* FUN_14165f460(void* pActor);                       // the equipment
CGemBase* FUN_140ddcc50(MS2Ptr<CGemBase>& sp);                  // MS2Ptr::operator->
void FUN_1405a8650(MS2Ptr<CGemBase>& sp);                       // MS2Ptr release
void FUN_1401fd2e0(Unk_GsSetting& setting, COutPacket& packet); // write the setting
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

// MS2-FUNCTIONAL: frame 16 bytes smaller than the exe (temp handle layout / EH states)
// @0x1419469b0
CGemTransparency* UIGemSettingDialog::FUN_1419469b0()
{
    if (DAT_1439f9284 == -1)
        return 0;
    void* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return 0;
    MS2Ptr<CGemBase> spGem = FUN_14165f460(pActor)->FUN_141270740(1);
    CGemTransparency* pGem = dynamic_cast<CGemTransparency*>(FUN_140ddcc50(spGem));
    FUN_1405a8650(spGem);
    return pGem;
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
    FUN_141946b10("m_cp", pGem->FUN_1405a4140(0));
    FUN_141946b10("m_ey", pGem->FUN_1405a4140(1));
    FUN_141946b10("m_cl", pGem->FUN_1405a4140(2));
    FUN_141946b10("m_pa", pGem->FUN_1405a4140(3));
    FUN_141946b10("m_mt", pGem->FUN_1405a4140(4));
    FUN_141946b10("m_ea", pGem->FUN_1405a4140(5));
    FUN_141946b10("m_fh", pGem->FUN_1405a4140(6));
    FUN_141946b10("m_gl", pGem->FUN_1405a4140(7));
    FUN_141946b10("m_ri", pGem->FUN_1405a4140(8));
    FUN_141946b10("m_sh", pGem->FUN_1405a4140(9));
}

// @0x141946510
int UIGemSettingDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) == 0)
        return 0;
    return 1;
}

// MS2-FUNCTIONAL: the 10 name temps / hidden-slot stores are scheduled differently from the exe
// @0x141946560
int UIGemSettingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnOk", szMethod) != 0)
        return 0;
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
    FUN_1401fd2e0(setting, packet);
    FUN_140710590(packet);
    return 1;
}

// MS2-FUNCTIONAL: the handle temp has different EH states (exe copies the by-value name twice)
// @0x141946a70
bool UIGemSettingDialog::FUN_141946a70(CString strName)
{
    Unk_GsHandle hCheck = ((Unk_GsEntity*)this)->FUN_140e52670(strName);
    bool bValue = false;
    if (hCheck.FUN_140a58460() != 0)
        bValue = hCheck.FUN_140a58490()->FUN_1422ce0e0();
    hCheck.FUN_140a583d0();
    return bValue;
}

// MS2-FUNCTIONAL: same handle temp difference as FUN_141946a70
// @0x141946b10
void UIGemSettingDialog::FUN_141946b10(CString strName, int nValue)
{
    Unk_GsHandle hCheck = ((Unk_GsEntity*)this)->FUN_140e52670(strName);
    if (hCheck.FUN_140a58460() != 0)
        hCheck.FUN_140a58490()->FUN_1422ce090(nValue);
    hCheck.FUN_140a583d0();
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x1419460D0, UIGemSettingDialog, GetTypeName, 61, 0xB036F7FD);
