// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUGCModelHouseDialog: see uiugcmodelhousedialog.h.
// MS2-UNIT: ?\uiugcmodelhousedialog.cpp
// MS2-RANGE: 0x140faf390-0x140faf840 .text$mn
// MS2-PIN: ??1UIUGCModelHouseDialog@@UEAA@XZ 0x140faf410
// MS2-PIN: ??_GUIUGCModelHouseDialog@@UEAAPEAXI@Z 0x140faf6d0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugcmodelhousedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiugcmodelhousedialog.h"

#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_UmPlayer;
void* FUN_1403ed2d0();                                          // the game context
Unk_UmPlayer* FUN_141bd0cc0(void* pContext);                    // the local player
void FUN_14152a240(Unk_UmPlayer* pPlayer, int nConcept);        // apply the home concept
void FUN_140710590(COutPacket& packet);                         // 0x140710590 send the packet

// @0x140faf390
UIUGCModelHouseDialog::UIUGCModelHouseDialog()
{
    m_nPlot = 0;
    m_88 = 1;
    FUN_141924170(1);
}

// @0x140faf450
CString UIUGCModelHouseDialog::GetTypeName()
{
    return "UGCModelHouseDialog";
}
MS2_REPLACE_METHOD(0x140FAF450, UIUGCModelHouseDialog, GetTypeName, 61, 0xBC81B70C);

// @0x140faf4a0
void UIUGCModelHouseDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140faf6b0(this, 0);
}
MS2_REPLACE_METHOD(0x140FAF4A0, UIUGCModelHouseDialog, vfunc_67, 36, 0xC7FB607C);

// @0x140faf4d0
void UIUGCModelHouseDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
}

// @0x140faf4f0
int UIUGCModelHouseDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("OnHomeConcept", szMethod) == 0 && data.FUN_1422b9620(pArgs, nArgs) != 0) {
        Unk_UmPlayer* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pPlayer == 0)
            return 0;
        int nConcept = data.FUN_1422b8a10();
        if (m_nPlot == 0) {
            FUN_14152a240(pPlayer, nConcept);
        } else {
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.WriteUInt8(2);
            packet.WriteInt32(m_nPlot);
            packet.WriteInt32(nConcept);
            FUN_140710590(packet);
        }
        CUIService::GetInstance()->FUN_141adc5d0((eUIClassID)0x4f3f);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140FAF4F0, UIUGCModelHouseDialog, vfunc_28, 440, 0x778F4B82);

// @0x140faf6b0
void FUN_140faf6b0(UIUGCModelHouseDialog* pDialog, int nPlot)
{
    pDialog->m_nPlot = nPlot;
}

// @0x140faf710
int UIUGCModelHouseDialog::vfunc_48()
{
    return 0x4f3f;
}

MS2_EMIT_CRT_MEMMOVE_S();
