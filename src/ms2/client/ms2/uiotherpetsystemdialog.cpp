// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Another player's pet window ("OtherPetSystemDialog"); see
// uiotherpetsystemdialog.h. The first of the five TUs of the queue unit ?\uiotherpetsystemdialog.cpp (UIOtherPetSystemDialog,
// UIOxQuizDialog, UIPaybackDialog, UIPetExtractionScrollDialog, UIPetSystemDialog). It also emits the inline
// UIPetSystemDialog dtor and the MS2Ptr / CAtlMap COMDATs it shares with uipetsystemdialog.cpp. No .text$di.
// MS2-UNIT: ?\uiotherpetsystemdialog.cpp
// MS2-RANGE: 0x140e6d3c0-0x140e6e400 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiotherpetsystemdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uiotherpetsystemdialog.h"

#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/aslabel.h"
#include "ms2/placeholder/citem.h"
#include "ms2/gfxui/uiswfentity.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (names describe uses) ----

// The owner (a player game object); slot 77 is the character name.
class Unk_OpOwner
{
public:
#define OP_V(n) virtual void vfunc_##n();
    OP_V(0) OP_V(1) OP_V(2) OP_V(3) OP_V(4) OP_V(5) OP_V(6) OP_V(7) OP_V(8) OP_V(9)
    OP_V(10) OP_V(11) OP_V(12) OP_V(13) OP_V(14) OP_V(15) OP_V(16) OP_V(17) OP_V(18) OP_V(19)
    OP_V(20) OP_V(21) OP_V(22) OP_V(23) OP_V(24) OP_V(25) OP_V(26) OP_V(27) OP_V(28) OP_V(29)
    OP_V(30) OP_V(31) OP_V(32) OP_V(33) OP_V(34) OP_V(35) OP_V(36) OP_V(37) OP_V(38) OP_V(39)
    OP_V(40) OP_V(41) OP_V(42) OP_V(43) OP_V(44) OP_V(45) OP_V(46) OP_V(47) OP_V(48) OP_V(49)
    OP_V(50) OP_V(51) OP_V(52) OP_V(53) OP_V(54) OP_V(55) OP_V(56) OP_V(57) OP_V(58) OP_V(59)
    OP_V(60) OP_V(61) OP_V(62) OP_V(63) OP_V(64) OP_V(65) OP_V(66) OP_V(67) OP_V(68) OP_V(69)
    OP_V(70) OP_V(71) OP_V(72) OP_V(73) OP_V(74) OP_V(75) OP_V(76)
#undef OP_V
    virtual CStringW vfunc_77();                                // character name
};
class Unk_OpWorld { public: Unk_OpOwner* FUN_141bd1290(int nObjectId); };  // a player by object id
Unk_OpWorld* FUN_1403ed2d0();
class Unk_OpUIService { public: void FUN_141adc530(int nClass); };            // open a dialog
Unk_OpUIService* FUN_1403ed2b0();
UIOtherPetSystemDialog* FUN_140cbe300(int nId);                             // the dialog of a UI id
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);            // a formatted string table text

template <> inline MS2Ptr<ASLabel> UISwfEntity::GetChild<ASLabel>(const CString& strName);

// @0x140e6d3c0
UIOtherPetSystemDialog::UIOtherPetSystemDialog()
    : m_1e8(0)
{
    FUN_141924170(1);
}

// @0x140e6d450
CString UIOtherPetSystemDialog::GetTypeName()
{
    return "OtherPetSystemDialog";
}

// @0x140e6d4a0
void UIOtherPetSystemDialog::FUN_140e6d4a0(int nOwnerId, MS2Ptr<CItem> spPet)
{
    if (spPet == 0)
        return;
    if (UIOtherPetSystemDialog* pDialog = FUN_140cbe300(0x4f41))
        pDialog->FUN_140e6d5b0(nOwnerId, spPet);
}

// @0x140e6d540
void UIOtherPetSystemDialog::vfunc_67()
{
    UIPetSystemDialog::vfunc_67();
    m_1e8 = 0;
}

// @0x140e6d580
void UIOtherPetSystemDialog::OnLoadComplete()
{
    UIPetSystemDialog::OnLoadComplete();
    FUN_140e6d6b0();
}

// @0x140e6d5b0
void UIOtherPetSystemDialog::FUN_140e6d5b0(int nOwnerId, MS2Ptr<CItem> spPet)
{
    m_1e0 = nOwnerId;
    m_1e8 = spPet;
    if (vfunc_55() != 0)
        FUN_1403ed2b0()->FUN_141adc530(0x4f41);
    else
    {
        FUN_140e6d6b0();
        FUN_140e74640(0);
    }
}

// @0x140e6d650
int UIOtherPetSystemDialog::vfunc_84()
{
    return 0;
}

// @0x140e6d660
MS2Ptr<CItem> UIOtherPetSystemDialog::vfunc_85()
{
    return m_1e8;
}

// @0x140e6d6b0
// MS2-FUNCTIONAL: the GetChild / CStringW temporaries keep different stack slots than the exe
void UIOtherPetSystemDialog::FUN_140e6d6b0()
{
    if (Unk_OpOwner* pOwner = FUN_1403ed2d0()->FUN_141bd1290(m_1e0))
    {
        MS2Ptr<ASLabel> spTitle = GetChild<ASLabel>("m_title");
        if (spTitle)
            spTitle->FUN_1422e4a50(FUN_1405c2690(CStringW(L"s_pet_owner"), pOwner->vfunc_77()));
    }
}

// @0x140e6d820
template <> inline MS2Ptr<ASLabel> UISwfEntity::GetChild<ASLabel>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<ASLabel>(0);
    return m_30->FUN_140c436d0<ASLabel>(strName);
}
