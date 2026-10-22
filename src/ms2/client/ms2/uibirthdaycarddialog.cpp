// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBirthdayCardDialog: see uibirthdaycarddialog.h.
// MS2-UNIT: ?\uibirthdaycarddialog.cpp
// MS2-RANGE: 0x140bb9770-0x140bb9cf0 .text$mn
// MS2-RANGE: 0x1400ca1c0-0x1400ca1f0 .text$di
// MS2-PIN: ??_GUIBirthdayCardDialog@@UEAAPEAXI@Z 0x140bb9b60
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibirthdaycarddialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uibirthdaycarddialog.h"

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The local player's actor: only the birthday test and the birthday time (member +0x11e8) are used here.
class Unk_BirthdayActor
{
public:
    unsigned int FUN_141660030();                               // has a birthday
    __int64 m_pad_00[0x23d];
    __int64 m_nBirthday;                                        // +0x11e8
};
__int64 FUN_140bb9ba0(Unk_BirthdayActor* pActor);

// The sound manager (scenestategame.cpp's Unk_SSGEffectMgr).
class Unk_BirthdaySound
{
public:
    void FUN_1411a5110(CString strPath, CString strName, CString strBone, int a, void* pXform, float fScale, int b);   // play a sound
};

void* FUN_1403ed2d0();                                          // the world session (local player owner)
Unk_BirthdayActor* FUN_141bd0cc0(void* pSession);               // the local player's actor
Unk_BirthdaySound* FUN_1403ed280();
CString FUN_1402bad60(const char* szFormat, const int* pn);     // format one int
void* FUN_140967100();
void FUN_141b1feb0(void* pTalk);
void FUN_140710590(COutPacket& packet);                         // 0x140710590 send the packet

// 0x143abd4f8: the greeting sound's name.
CString DAT_143abd4f8("02100303");

// @0x140bb9770
UIBirthdayCardDialog::UIBirthdayCardDialog()
{
    FUN_141924170(1);
}

// @0x140bb97d0
UIBirthdayCardDialog::~UIBirthdayCardDialog()
{
}

// @0x140bb9810
CString UIBirthdayCardDialog::GetTypeName()
{
    return "BirthdayCardDialog";
}
MS2_REPLACE_METHOD(0x140BB9810, UIBirthdayCardDialog, GetTypeName, 61, 0x1B4B8DDF);

// @0x140bb9860
int UIBirthdayCardDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140BB9860, UIBirthdayCardDialog, vfunc_65, 37, 0x1083A844);

// @0x140bb9890
void UIBirthdayCardDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_141b1feb0(FUN_140967100());
}
MS2_REPLACE_METHOD(0x140BB9890, UIBirthdayCardDialog, vfunc_67, 37, 0xAB07D7CD);

// @0x140bb98c0
void UIBirthdayCardDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    SendBirthdayCard();
    FUN_140bb9960();
}
MS2_REPLACE_METHOD(0x140BB98C0, UIBirthdayCardDialog, OnLoadComplete, 44, 0xD6EBC18F);

// @0x140bb9900
void UIBirthdayCardDialog::SendBirthdayCard()
{
    COutPacket packet(static_cast<int>(SendOp::BirthdayCard), 0);
    packet.WriteUInt8(0);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140bb9900, UIBirthdayCardDialog, SendBirthdayCard, 75, 0xB451B3E8);

// @0x140bb9960
void UIBirthdayCardDialog::FUN_140bb9960()
{
    if (m_30.get() != 0)
    {
        Unk_BirthdayActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pActor != 0)
        {
            if (pActor->FUN_141660030() != 0)
            {
                CMsTime time(FUN_140bb9ba0(pActor));
                int nMonth;
                m_30->Invoke("setBirthDay", FUN_1402bad60("{0:02d}", &(nMonth = time.GetMonth())));
                FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/system"), CString(DAT_143abd4f8), CString(""), 1, 0, 1.0f, 0);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140bb9960, UIBirthdayCardDialog, FUN_140bb9960, 506, 0x608DD92A);

// @0x140bb9ba0
__int64 FUN_140bb9ba0(Unk_BirthdayActor* pActor)
{
    return pActor->m_nBirthday;
}

// @0x140bb9bc0
int UIBirthdayCardDialog::vfunc_48()
{
    return 0x4f55;
}

// @0x140bb9bd0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca1870-0x142ca1890 .text$yd
