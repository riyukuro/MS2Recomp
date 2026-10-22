// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Ride-on / ride-off action records: construction, packet encode/decode
// and the two factories that pick the record class from the leading type byte.
// File and function names are invented (class names come from RTTI).
// MS2-UNIT: ?\rideonaction.cpp
// MS2-RANGE: 0x14077dd10-0x140781d80 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\rideonaction.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

void FUN_140892c70(CUgcItemLook* p);
void FUN_140893070(CUgcItemLook* p, COutputStream* pStream);
void FUN_140893250(CUgcItemLook* p, CInputStream* pStream);

// ---- RideOnAction ----------------------------------------------------------------------------------------------------------
// @0x14077dd10
RideOnAction::RideOnAction()
{
    m_nType = 0;
    m_n1c = 0;
    m_n20 = 0;
    m_n24 = 0;
    m_b28 = false;
}
// @0x14077dd80
RideOnAction::~RideOnAction()
{
}
// @0x14077ddb0
void RideOnAction::vfunc_1(COutputStream* pStream)
{
    pStream->WriteUInt8(m_nType);
    pStream->WriteInt32(m_n1c);
    pStream->WriteInt32(m_n20);
    pStream->WriteUInt8(m_b28);
}
MS2_REPLACE_METHOD(0x14077DDB0, RideOnAction, vfunc_1, 117, 0xC83D806E);
// @0x14077de30
// MS2-FUNCTIONAL: the exe tests the slot-1 result with `test al,al` (no movzx/movsx) before the byte-bool ternary; no stream return type reproduces it
void RideOnAction::vfunc_2(CInputStream* pStream)
{
    m_n1c = pStream->ReadInt32();
    m_n20 = pStream->ReadInt32();
    m_b28 = pStream->ReadUInt8() ? true : false;
}
MS2_REPLACE_METHOD(0x14077DE30, RideOnAction, vfunc_2, 112, 0xBBE81F7C);
// @0x14077deb0
MS2Ptr<RideOnAction> FUN_14077deb0(CInputStream* pStream)
{
    unsigned int nType = pStream->ReadUInt8();
    MS2Ptr<RideOnAction> pAction(0);
    switch (nType) {
    case 0:
        pAction.AssignRaw(new RideOnAction());
        break;
    case 1:
        pAction.AssignRaw(new RideOnActionUseItem());
        break;
    case 2:
        pAction.AssignRaw(new RideOnActionAdditionalEffect());
        break;
    case 3:
        pAction.AssignRaw(new RideOnActionHideAndSeek());
        break;
    }
    if (pAction.get())
        pAction->vfunc_2(pStream);
    return pAction;
}
MS2_REPLACE(0x14077DEB0, FUN_14077deb0, 578, 0xB0AA39DE);
// @0x14077e100
RideOnActionUseItem::RideOnActionUseItem()
    : m_n30(0), m_n38(0)
{
    m_nType = 1;
    FUN_140892c70(&m_look);
}
// @0x14077e190
RideOnActionUseItem::~RideOnActionUseItem()
{
}
// @0x14077e1d0
void RideOnActionUseItem::vfunc_1(COutputStream* pStream)
{
    RideOnAction::vfunc_1(pStream);
    pStream->WriteInt32(m_n30);
    pStream->WriteInt64(m_n38);
    FUN_140893070(&m_look, pStream);
}
MS2_REPLACE_METHOD(0x14077E1D0, RideOnActionUseItem, vfunc_1, 105, 0xA6540C5B);
// @0x14077e240
void RideOnActionUseItem::vfunc_2(CInputStream* pStream)
{
    RideOnAction::vfunc_2(pStream);
    m_n30 = pStream->ReadInt32();
    m_n38 = pStream->ReadInt64();
    FUN_140892c70(&m_look);
    FUN_140893250(&m_look, pStream);
}
MS2_REPLACE_METHOD(0x14077E240, RideOnActionUseItem, vfunc_2, 122, 0x9916437F);
// @0x14077e2c0
RideOnActionAdditionalEffect::RideOnActionAdditionalEffect()
    : m_n30(0), m_s34(1)
{
    m_nType = 2;
}
// @0x14077e320
RideOnActionAdditionalEffect::~RideOnActionAdditionalEffect()
{
}
// @0x14077e350
void RideOnActionAdditionalEffect::vfunc_1(COutputStream* pStream)
{
    RideOnAction::vfunc_1(pStream);
    pStream->WriteInt32(m_n30);
    pStream->WriteInt16(m_s34);
}
MS2_REPLACE_METHOD(0x14077E350, RideOnActionAdditionalEffect, vfunc_1, 83, 0x5FF3AEC8);
// @0x14077e3b0
void RideOnActionAdditionalEffect::vfunc_2(CInputStream* pStream)
{
    RideOnAction::vfunc_2(pStream);
    m_n30 = pStream->ReadInt32();
    m_s34 = pStream->ReadInt16();
}
MS2_REPLACE_METHOD(0x14077E3B0, RideOnActionAdditionalEffect, vfunc_2, 83, 0xE204C5CF);
// @0x14077e410
RideOnActionHideAndSeek::RideOnActionHideAndSeek()
{
    m_nType = 3;
}
// @0x14077e450
RideOnActionHideAndSeek::~RideOnActionHideAndSeek()
{
}

// ---- RideOffAction ---------------------------------------------------------------------------------------------------------
// @0x14077e480
RideOffAction::RideOffAction(int nArg)
    : m_nType(0), m_nArg(nArg), m_n20(0), m_n24(0)
{
}
// @0x14077e4f0
RideOffAction::~RideOffAction()
{
}
// @0x14077e520
void RideOffAction::vfunc_1(COutputStream* pStream)
{
    pStream->WriteUInt8(m_nType);
    pStream->WriteUInt8(m_nArg);
}
MS2_REPLACE_METHOD(0x14077E520, RideOffAction, vfunc_1, 69, 0x4AA66412);
// @0x14077e570
void RideOffAction::vfunc_2(CInputStream* pStream)
{
    m_nArg = pStream->ReadUInt8();
}
MS2_REPLACE_METHOD(0x14077E570, RideOffAction, vfunc_2, 46, 0x84681AAE);
// @0x14077e5b0
MS2Ptr<RideOffAction> FUN_14077e5b0(CInputStream* pStream)
{
    int nType = pStream->ReadUInt8();
    MS2Ptr<RideOffAction> pAction(0);
    switch (nType) {
    case 0:
        pAction.AssignRaw(new RideOffAction(0));
        break;
    case 1:
        pAction.AssignRaw(new RideOffActionUseSkill(0));
        break;
    case 25:
        pAction.AssignRaw(new RideOffActionUseGlideItem(0));
        break;
    case 2:
        pAction.AssignRaw(new RideOffActionInteract(0));
        break;
    case 3:
        pAction.AssignRaw(new RideOffActionTaxi(0));
        break;
    case 4:
        pAction.AssignRaw(new RideOffActionCashCall(0));
        break;
    case 5:
        pAction.AssignRaw(new RideOffActionBeautyShop(0));
        break;
    case 6:
        pAction.AssignRaw(new RideOffActionTakeLR(0));
        break;
    case 7:
        pAction.AssignRaw(new RideOffActionHold(0));
        break;
    case 8:
        pAction.AssignRaw(new RideOffActionRecall(0));
        break;
    case 9:
        pAction.AssignRaw(new RideOffActionSummonPetOn(0));
        break;
    case 10:
        pAction.AssignRaw(new RideOffActionSummonPetTransfer(0));
        break;
    case 11:
        pAction.AssignRaw(new RideOffActionHomeConvenient(0));
        break;
    case 12:
        pAction.AssignRaw(new RideOffActionDisableField(0));
        break;
    case 13:
        pAction.AssignRaw(new RideOffActionDead(0));
        break;
    case 14:
        pAction.AssignRaw(new RideOffActionAdditionalEffect(0));
        break;
    case 15:
        pAction.AssignRaw(new RideOffActionRidingUI(0));
        break;
    case 16:
        pAction.AssignRaw(new RideOffActionHomemade(0));
        break;
    case 22:
        pAction.AssignRaw(new RideOffActionNurturing(0));
        break;
    case 17:
        pAction.AssignRaw(new RideOffActionAutoInteraction(0));
        break;
    case 18:
        pAction.AssignRaw(new RideOffActionAutoClimb(0));
        break;
    case 19:
        pAction.AssignRaw(new RideOffActionCoupleEmotion(0));
        break;
    case 21:
        pAction.AssignRaw(new RideOffActionUseFunctionItem(0));
        break;
    case 23:
        pAction.AssignRaw(new RideOffActionGroggy(0));
        break;
    case 24:
        pAction.AssignRaw(new RideOffActionUnRideSkill(0));
        break;
    case 26:
        pAction.AssignRaw(new RideOffActionHideAndSeek(0));
        break;
    }
    if (pAction.get())
        pAction->vfunc_2(pStream);
    return pAction;
}
MS2_REPLACE(0x14077E5B0, FUN_14077e5b0, 2890, 0x80429F64);
// @0x14077f170
RideOffActionBeautyShop::RideOffActionBeautyShop(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 5;
}
// @0x14077f1c0
RideOffActionBeautyShop::~RideOffActionBeautyShop()
{
}
// @0x14077f1f0
void RideOffActionBeautyShop::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
}
MS2_REPLACE_METHOD(0x14077F1F0, RideOffActionBeautyShop, vfunc_1, 34, 0x73071EB2);
// @0x14077f220
void RideOffActionBeautyShop::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
}
MS2_REPLACE_METHOD(0x14077F220, RideOffActionBeautyShop, vfunc_2, 34, 0x45B2D9D2);
// @0x14077f250
RideOffActionUseSkill::RideOffActionUseSkill(int nArg)
    : RideOffAction(nArg),
      m_n28(0),
      m_b2c(0),
      m_n30(0)
{
    m_nType = 1;
}
// @0x14077f2c0
RideOffActionUseSkill::~RideOffActionUseSkill()
{
}
// @0x14077f2f0
void RideOffActionUseSkill::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt32(m_n28);
    pStream->WriteBool(m_b2c);
    pStream->WriteInt32(m_n30);
}
MS2_REPLACE_METHOD(0x14077F2F0, RideOffActionUseSkill, vfunc_1, 106, 0xC372793A);
// @0x14077f360
void RideOffActionUseSkill::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt32();
    m_b2c = pStream->ReadBool();
    m_n30 = pStream->ReadInt32();
}
MS2_REPLACE_METHOD(0x14077F360, RideOffActionUseSkill, vfunc_2, 105, 0x8410A7B4);
// @0x14077f3d0
RideOffActionUseGlideItem::RideOffActionUseGlideItem(int nArg)
    : RideOffAction(nArg),
      m_n28(0),
      m_b30(0),
      m_n34(0)
{
    m_nType = 25;
}
// @0x14077f440
RideOffActionUseGlideItem::~RideOffActionUseGlideItem()
{
}
// @0x14077f470
void RideOffActionUseGlideItem::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt64(m_n28);
    pStream->WriteBool(m_b30);
    pStream->WriteInt32(m_n34);
}
MS2_REPLACE_METHOD(0x14077F470, RideOffActionUseGlideItem, vfunc_1, 107, 0xAAEF86D8);
// @0x14077f4f0
void RideOffActionUseGlideItem::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt64();
    m_b30 = pStream->ReadBool();
    m_n34 = pStream->ReadInt32();
}
MS2_REPLACE_METHOD(0x14077F4F0, RideOffActionUseGlideItem, vfunc_2, 106, 0x536E8B2B);
// @0x14077f560
RideOffActionInteract::RideOffActionInteract(int nArg)
    : RideOffAction(nArg),
      m_n28(0),
      m_s30("")
{
    m_nType = 2;
}
// @0x14077f5e0
RideOffActionInteract::~RideOffActionInteract()
{
}
// @0x14077f620
void RideOffActionInteract::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt32(m_n28);
    pStream->WriteUnicodeStringA(m_s30);
}
MS2_REPLACE_METHOD(0x14077F620, RideOffActionInteract, vfunc_1, 96, 0xE3BC6C08);
// @0x14077f690
void RideOffActionInteract::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt32();
    m_s30 = pStream->ReadUnicodeStringA();
}
MS2_REPLACE_METHOD(0x14077F690, RideOffActionInteract, vfunc_2, 138, 0x3B776968);
// @0x14077f720
RideOffActionTaxi::RideOffActionTaxi(int nArg)
    : RideOffAction(nArg),
      m_n28(0)
{
    m_nType = 3;
}
// @0x14077f780
RideOffActionTaxi::~RideOffActionTaxi()
{
}
// @0x14077f7b0
void RideOffActionTaxi::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt32(m_n28);
}
MS2_REPLACE_METHOD(0x14077F7B0, RideOffActionTaxi, vfunc_1, 58, 0xF7462841);
// @0x14077f7f0
void RideOffActionTaxi::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt32();
}
MS2_REPLACE_METHOD(0x14077F7F0, RideOffActionTaxi, vfunc_2, 58, 0x266FF3FB);
// @0x14077f830
RideOffActionCashCall::RideOffActionCashCall(int nArg)
    : RideOffAction(nArg),
      m_n28(0),
      m_n2c(0),
      m_n30(0)
{
    m_nType = 4;
}
// @0x14077f8a0
RideOffActionCashCall::~RideOffActionCashCall()
{
}
// @0x14077f8d0
void RideOffActionCashCall::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt32(m_n28);
    pStream->WriteUInt8(m_n2c);
    pStream->WriteInt64(m_n30);
}
MS2_REPLACE_METHOD(0x14077F8D0, RideOffActionCashCall, vfunc_1, 108, 0x7E215306);
// @0x14077f950
void RideOffActionCashCall::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt32();
    m_n2c = pStream->ReadUInt8();
    m_n30 = pStream->ReadInt64();
}
MS2_REPLACE_METHOD(0x14077F950, RideOffActionCashCall, vfunc_2, 110, 0x020A9C99);
// @0x14077f9d0
RideOffActionTakeLR::RideOffActionTakeLR(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 6;
    m_n28 = 1;
    m_n2c = 0;
}
// @0x14077fa30
RideOffActionTakeLR::~RideOffActionTakeLR()
{
}
// @0x14077fa60
void RideOffActionTakeLR::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteUInt8(m_n28);
    pStream->WriteInt32(m_n2c);
}
MS2_REPLACE_METHOD(0x14077FA60, RideOffActionTakeLR, vfunc_1, 83, 0xF0072FE3);
// @0x14077fac0
void RideOffActionTakeLR::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadUInt8();
    m_n2c = pStream->ReadInt32();
}
MS2_REPLACE_METHOD(0x14077FAC0, RideOffActionTakeLR, vfunc_2, 85, 0x20995F5C);
// @0x14077fb20
RideOffActionHold::RideOffActionHold(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 7;
}
// @0x14077fb70
RideOffActionHold::~RideOffActionHold()
{
}
// @0x14077fba0
void RideOffActionHold::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
}
MS2_REPLACE_METHOD(0x14077FBA0, RideOffActionHold, vfunc_1, 34, 0xE3573D20);
// @0x14077fbd0
void RideOffActionHold::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
}
MS2_REPLACE_METHOD(0x14077FBD0, RideOffActionHold, vfunc_2, 34, 0x15727DC0);
// @0x14077fc00
RideOffActionAutoClimb::RideOffActionAutoClimb(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 18;
}
// @0x14077fc50
RideOffActionAutoClimb::~RideOffActionAutoClimb()
{
}
// @0x14077fc80
void RideOffActionAutoClimb::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
}
MS2_REPLACE_METHOD(0x14077FC80, RideOffActionAutoClimb, vfunc_1, 34, 0xC0C35011);
// @0x14077fcb0
void RideOffActionAutoClimb::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
}
MS2_REPLACE_METHOD(0x14077FCB0, RideOffActionAutoClimb, vfunc_2, 34, 0x2084B831);
// @0x14077fce0
RideOffActionRecall::RideOffActionRecall(int nArg)
    : RideOffAction(nArg),
      m_n28(0)
{
    m_nType = 8;
}
// @0x14077fd40
RideOffActionRecall::~RideOffActionRecall()
{
}
// @0x14077fd70
void RideOffActionRecall::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt64(m_n28);
}
MS2_REPLACE_METHOD(0x14077FD70, RideOffActionRecall, vfunc_1, 59, 0x758A93B9);
// @0x14077fdc0
void RideOffActionRecall::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt64();
}
MS2_REPLACE_METHOD(0x14077FDC0, RideOffActionRecall, vfunc_2, 59, 0xC526C6DB);
// @0x14077fe10
RideOffActionSummonPetOn::RideOffActionSummonPetOn(int nArg)
    : RideOffAction(nArg),
      m_n28(0),
      m_n30(0)
{
    m_nType = 9;
}
// @0x14077fe70
RideOffActionSummonPetOn::~RideOffActionSummonPetOn()
{
}
// @0x14077fea0
void RideOffActionSummonPetOn::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt64(m_n28);
    pStream->WriteUInt8(m_n30);
}
MS2_REPLACE_METHOD(0x14077FEA0, RideOffActionSummonPetOn, vfunc_1, 84, 0x3E30D275);
// @0x14077ff00
void RideOffActionSummonPetOn::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt64();
    m_n30 = pStream->ReadUInt8();
}
MS2_REPLACE_METHOD(0x14077FF00, RideOffActionSummonPetOn, vfunc_2, 86, 0x1C6D9CCE);
// @0x14077ff60
RideOffActionSummonPetTransfer::RideOffActionSummonPetTransfer(int nArg)
    : RideOffAction(nArg),
      m_n28(0)
{
    m_nType = 10;
}
// @0x14077ffc0
RideOffActionSummonPetTransfer::~RideOffActionSummonPetTransfer()
{
}
// @0x14077fff0
void RideOffActionSummonPetTransfer::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt64(m_n28);
}
MS2_REPLACE_METHOD(0x14077FFF0, RideOffActionSummonPetTransfer, vfunc_1, 59, 0x658F1DBB);
// @0x140780040
void RideOffActionSummonPetTransfer::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt64();
}
MS2_REPLACE_METHOD(0x140780040, RideOffActionSummonPetTransfer, vfunc_2, 59, 0x492B9219);
// @0x140780090
RideOffActionHomeConvenient::RideOffActionHomeConvenient(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 11;
}
// @0x1407800e0
RideOffActionHomeConvenient::~RideOffActionHomeConvenient()
{
}
// @0x140780110
void RideOffActionHomeConvenient::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteUInt8(m_n28);
}
MS2_REPLACE_METHOD(0x140780110, RideOffActionHomeConvenient, vfunc_1, 59, 0x1BFD31B9);
// @0x140780160
void RideOffActionHomeConvenient::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadUInt8();
}
MS2_REPLACE_METHOD(0x140780160, RideOffActionHomeConvenient, vfunc_2, 61, 0xB26EA954);
// @0x1407801b0
RideOffActionDisableField::RideOffActionDisableField(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 12;
    m_n20 = 1;
    m_n24 = 1;
}
// @0x140780210
RideOffActionDisableField::~RideOffActionDisableField()
{
}
// @0x140780240
RideOffActionDead::RideOffActionDead(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 13;
    m_n20 = 1;
    m_n24 = 1;
}
// @0x1407802a0
RideOffActionDead::~RideOffActionDead()
{
}
// @0x1407802d0
RideOffActionAdditionalEffect::RideOffActionAdditionalEffect(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 14;
    m_n20 = 1;
    m_n24 = 1;
}
// @0x140780330
RideOffActionAdditionalEffect::~RideOffActionAdditionalEffect()
{
}
// @0x140780360
RideOffActionRidingUI::RideOffActionRidingUI(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 15;
    m_n20 = 1;
}
// @0x1407803c0
RideOffActionRidingUI::~RideOffActionRidingUI()
{
}
// @0x1407803f0
RideOffActionHomemade::RideOffActionHomemade(int nArg)
    : RideOffAction(nArg),
      m_s28(""),
      m_n30(0),
      m_n34(0),
      m_n38(0)
{
    m_nType = 16;
}
// @0x140780480
RideOffActionHomemade::~RideOffActionHomemade()
{
}
// @0x1407804c0
void RideOffActionHomemade::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteUnicodeStringA(m_s28);
    pStream->WriteInt32(m_n30);
    pStream->WriteInt16(m_n34);
    pStream->WriteInt32(m_n38);
}
MS2_REPLACE_METHOD(0x1407804C0, RideOffActionHomemade, vfunc_1, 145, 0x4A49CEC5);
// @0x140780560
void RideOffActionHomemade::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_s28 = pStream->ReadUnicodeStringA();
    m_n30 = pStream->ReadInt32();
    m_n34 = (unsigned short)pStream->ReadInt16();
    m_n38 = pStream->ReadInt32();
}
MS2_REPLACE_METHOD(0x140780560, RideOffActionHomemade, vfunc_2, 189, 0xE99A5349);
// @0x140780630
RideOffActionNurturing::RideOffActionNurturing(int nArg)
    : RideOffAction(nArg),
      m_s28(""),
      m_n30(0)
{
    m_nType = 22;
}
// @0x1407806b0
RideOffActionNurturing::~RideOffActionNurturing()
{
}
// @0x1407806f0
void RideOffActionNurturing::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteUnicodeStringA(m_s28);
    pStream->WriteInt32(m_n30);
}
MS2_REPLACE_METHOD(0x1407806F0, RideOffActionNurturing, vfunc_1, 96, 0xB2D03658);
// @0x140780760
void RideOffActionNurturing::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_s28 = pStream->ReadUnicodeStringA();
    m_n30 = pStream->ReadInt32();
}
MS2_REPLACE_METHOD(0x140780760, RideOffActionNurturing, vfunc_2, 138, 0x1F1D9B6B);
// @0x1407807f0
RideOffActionAutoInteraction::RideOffActionAutoInteraction(int nArg)
    : RideOffAction(nArg),
      m_n28(0),
      m_n2c(0),
      m_n30(0)
{
    m_nType = 17;
}
// @0x140780860
RideOffActionAutoInteraction::~RideOffActionAutoInteraction()
{
}
// @0x140780890
void RideOffActionAutoInteraction::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt32(m_n28);
    pStream->WriteInt16(m_n2c);
    pStream->WriteInt32(m_n30);
}
MS2_REPLACE_METHOD(0x140780890, RideOffActionAutoInteraction, vfunc_1, 107, 0x65FBFA3F);
// @0x140780910
void RideOffActionAutoInteraction::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt32();
    m_n2c = (unsigned short)pStream->ReadInt16();
    m_n30 = pStream->ReadInt32();
}
MS2_REPLACE_METHOD(0x140780910, RideOffActionAutoInteraction, vfunc_2, 109, 0x27020240);
// @0x140780990
RideOffActionCoupleEmotion::RideOffActionCoupleEmotion(int nArg)
    : RideOffAction(nArg),
      m_n28(0),
      m_n30(0)
{
    m_nType = 19;
}
// @0x1407809f0
RideOffActionCoupleEmotion::~RideOffActionCoupleEmotion()
{
}
// @0x140780a20
void RideOffActionCoupleEmotion::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt32(m_n28);
    pStream->WriteInt64(m_n30);
}
MS2_REPLACE_METHOD(0x140780A20, RideOffActionCoupleEmotion, vfunc_1, 83, 0x6F3451CD);
// @0x140780a80
void RideOffActionCoupleEmotion::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt32();
    m_n30 = pStream->ReadInt64();
}
MS2_REPLACE_METHOD(0x140780A80, RideOffActionCoupleEmotion, vfunc_2, 83, 0xF1B8C75D);
// @0x140780ae0
RideOffActionReact::RideOffActionReact(int nArg)
    : RideOffAction(nArg),
      m_n28(0),
      m_s30("")
{
    m_nType = 20;
}
// @0x140780b60
RideOffActionReact::~RideOffActionReact()
{
}
// @0x140780ba0
void RideOffActionReact::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt32(m_n28);
    pStream->WriteUnicodeStringA(m_s30);
}
MS2_REPLACE_METHOD(0x140780BA0, RideOffActionReact, vfunc_1, 96, 0x2862008F);
// @0x140780c10
void RideOffActionReact::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt32();
    m_s30 = pStream->ReadUnicodeStringA();
}
MS2_REPLACE_METHOD(0x140780C10, RideOffActionReact, vfunc_2, 138, 0xF063DE0D);
// @0x140780ca0
RideOffActionUseFunctionItem::RideOffActionUseFunctionItem(int nArg)
    : RideOffAction(nArg),
      m_n28(0)
{
    m_nType = 21;
}
// @0x140780d10
RideOffActionUseFunctionItem::~RideOffActionUseFunctionItem()
{
}
// @0x140780d50
void RideOffActionUseFunctionItem::vfunc_1(COutputStream* pStream)
{
    RideOffAction::vfunc_1(pStream);
    pStream->WriteInt64(m_n28);
    pStream->WriteUnicodeString(m_s30);
}
MS2_REPLACE_METHOD(0x140780D50, RideOffActionUseFunctionItem, vfunc_1, 97, 0x5ED0FB5B);
// @0x140780dc0
void RideOffActionUseFunctionItem::vfunc_2(CInputStream* pStream)
{
    RideOffAction::vfunc_2(pStream);
    m_n28 = pStream->ReadInt64();
    m_s30 = pStream->ReadUnicodeString();
}
MS2_REPLACE_METHOD(0x140780DC0, RideOffActionUseFunctionItem, vfunc_2, 139, 0x36C8EB23);
// @0x140780e60
RideOffActionGroggy::RideOffActionGroggy(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 23;
    m_n20 = 1;
    m_n24 = 1;
}
// @0x140780ec0
RideOffActionGroggy::~RideOffActionGroggy()
{
}
// @0x140780ef0
RideOffActionUnRideSkill::RideOffActionUnRideSkill(int nArg)
    : RideOffAction(nArg)
{
    m_nType = 24;
    m_n20 = 0;
    m_n24 = 1;
}
// @0x140780f50
RideOffActionUnRideSkill::~RideOffActionUnRideSkill()
{
}
// @0x140780f80
RideOffActionHideAndSeek::RideOffActionHideAndSeek(int nArg)
    : RideOffAction(0)
{
    m_nType = 26;
    m_n20 = 1;
}
// @0x140780fd0
RideOffActionHideAndSeek::~RideOffActionHideAndSeek()
{
}

// Trailing unreferenced CRT memmove_s COMDAT 0x140781c60.
MS2_EMIT_CRT_MEMMOVE_S();
