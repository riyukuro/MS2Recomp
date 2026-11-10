// rideonaction.h - ride-on / ride-off action records (packet payloads of the "ride" feature).
// NOT an original header: class names come from the RTTI of MapleStory2.exe (RideOnAction*, RideOffAction*); member names are
// invented from offsets. Every record is a CPtred-based object with a type id at +0x18, an Encode (vfunc_1, writes the
// record to a COutputStream) and a Decode (vfunc_2, reads the fields after the type byte from a CInputStream) override.
// Layouts proven by the constructors and the factory operator_new sizes (0x1407deb0 RideOn, 0x14077e5b0 RideOff).
#pragma once
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/commonfiles/stream.h"

class RideOnAction : public CPtred
{
public:
    RideOnAction();                                     // 0x14077dd10
    virtual ~RideOnAction();                            // 0x14077dd80
    virtual void vfunc_1(COutputStream* pStream);       // 0x14077ddb0
    virtual void vfunc_2(CInputStream* pStream);        // 0x14077de30
    int m_nType;                                        // +0x18 (0 base, 1 UseItem, 2 AdditionalEffect, 3 HideAndSeek)
    int m_n1c;
    int m_n20;
    int m_n24;
    bool m_b28;
};
MS2_CHECK_SIZE(RideOnAction, 0x30);

class RideOnActionUseItem : public RideOnAction
{
public:
    RideOnActionUseItem();                              // 0x14077e100
    ~RideOnActionUseItem() override;                    // 0x14077e190
    void vfunc_1(COutputStream* pStream) override;      // 0x14077e1d0
    void vfunc_2(CInputStream* pStream) override;       // 0x14077e240
    int m_n30;
    __int64 m_n38;
    CUgcItemLook m_look;                                // +0x40
};
MS2_CHECK_SIZE(RideOnActionUseItem, 0xa8);

class RideOnActionAdditionalEffect : public RideOnAction
{
public:
    RideOnActionAdditionalEffect();                     // 0x14077e2c0
    ~RideOnActionAdditionalEffect() override;           // 0x14077e320
    void vfunc_1(COutputStream* pStream) override;      // 0x14077e350
    void vfunc_2(CInputStream* pStream) override;       // 0x14077e3b0
    int m_n30;
    short m_s34;
};
MS2_CHECK_SIZE(RideOnActionAdditionalEffect, 0x38);

class RideOnActionHideAndSeek : public RideOnAction
{
public:
    RideOnActionHideAndSeek();                          // 0x14077e410
    ~RideOnActionHideAndSeek() override;                // 0x14077e450
};
MS2_CHECK_SIZE(RideOnActionHideAndSeek, 0x30);

class RideOffAction : public CPtred
{
public:
    RideOffAction(int nArg);                            // 0x14077e480
    virtual ~RideOffAction();                           // 0x14077e4f0
    virtual void vfunc_1(COutputStream* pStream);       // 0x14077e520
    virtual void vfunc_2(CInputStream* pStream);        // 0x14077e570
    int m_nType;                                        // +0x18 (see the derived classes)
    unsigned int m_nArg;                                // +0x1c
    int m_n20;
    int m_n24;
};
MS2_CHECK_SIZE(RideOffAction, 0x28);
class RideOffActionUseSkill : public RideOffAction
{
public:
    RideOffActionUseSkill(int nArg = 0);
    ~RideOffActionUseSkill() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    int m_n28;        // +0x28
    bool m_b2c;        // +0x2c
    int m_n30;        // +0x30
};
MS2_CHECK_SIZE(RideOffActionUseSkill, 0x38);

class RideOffActionInteract : public RideOffAction
{
public:
    RideOffActionInteract(int nArg = 0);
    ~RideOffActionInteract() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    int m_n28;        // +0x28
    CString m_s30;        // +0x30
};
MS2_CHECK_SIZE(RideOffActionInteract, 0x38);

class RideOffActionTaxi : public RideOffAction
{
public:
    RideOffActionTaxi(int nArg = 0);
    ~RideOffActionTaxi() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    int m_n28;        // +0x28
};
MS2_CHECK_SIZE(RideOffActionTaxi, 0x30);

class RideOffActionCashCall : public RideOffAction
{
public:
    RideOffActionCashCall(int nArg = 0);
    ~RideOffActionCashCall() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    int m_n28;        // +0x28
    unsigned int m_n2c;        // +0x2c
    __int64 m_n30;        // +0x30
};
MS2_CHECK_SIZE(RideOffActionCashCall, 0x38);

class RideOffActionBeautyShop : public RideOffAction
{
public:
    RideOffActionBeautyShop(int nArg = 0);
    ~RideOffActionBeautyShop() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
};
MS2_CHECK_SIZE(RideOffActionBeautyShop, 0x28);

class RideOffActionTakeLR : public RideOffAction
{
public:
    RideOffActionTakeLR(int nArg = 0);
    ~RideOffActionTakeLR() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    unsigned int m_n28;        // +0x28
    int m_n2c;        // +0x2c
};
MS2_CHECK_SIZE(RideOffActionTakeLR, 0x30);

class RideOffActionHold : public RideOffAction
{
public:
    RideOffActionHold(int nArg = 0);
    ~RideOffActionHold() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
};
MS2_CHECK_SIZE(RideOffActionHold, 0x28);

class RideOffActionRecall : public RideOffAction
{
public:
    RideOffActionRecall(int nArg = 0);
    ~RideOffActionRecall() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    __int64 m_n28;        // +0x28
};
MS2_CHECK_SIZE(RideOffActionRecall, 0x30);

class RideOffActionSummonPetOn : public RideOffAction
{
public:
    RideOffActionSummonPetOn(int nArg = 0);
    ~RideOffActionSummonPetOn() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    __int64 m_n28;        // +0x28
    unsigned int m_n30;        // +0x30
};
MS2_CHECK_SIZE(RideOffActionSummonPetOn, 0x38);

class RideOffActionSummonPetTransfer : public RideOffAction
{
public:
    RideOffActionSummonPetTransfer(int nArg = 0);
    ~RideOffActionSummonPetTransfer() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    __int64 m_n28;        // +0x28
};
MS2_CHECK_SIZE(RideOffActionSummonPetTransfer, 0x30);

class RideOffActionHomeConvenient : public RideOffAction
{
public:
    RideOffActionHomeConvenient(int nArg = 0);
    ~RideOffActionHomeConvenient() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    unsigned int m_n28;        // +0x28
};
MS2_CHECK_SIZE(RideOffActionHomeConvenient, 0x30);

class RideOffActionDisableField : public RideOffAction
{
public:
    RideOffActionDisableField(int nArg = 0);
    ~RideOffActionDisableField() override;
};
MS2_CHECK_SIZE(RideOffActionDisableField, 0x28);

class RideOffActionDead : public RideOffAction
{
public:
    RideOffActionDead(int nArg = 0);
    ~RideOffActionDead() override;
};
MS2_CHECK_SIZE(RideOffActionDead, 0x28);

class RideOffActionAdditionalEffect : public RideOffAction
{
public:
    RideOffActionAdditionalEffect(int nArg = 0);
    ~RideOffActionAdditionalEffect() override;
};
MS2_CHECK_SIZE(RideOffActionAdditionalEffect, 0x28);

class RideOffActionRidingUI : public RideOffAction
{
public:
    RideOffActionRidingUI(int nArg = 0);
    ~RideOffActionRidingUI() override;
};
MS2_CHECK_SIZE(RideOffActionRidingUI, 0x28);

class RideOffActionHomemade : public RideOffAction
{
public:
    RideOffActionHomemade(int nArg = 0);
    ~RideOffActionHomemade() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    CString m_s28;        // +0x28
    int m_n30;        // +0x30
    unsigned int m_n34;        // +0x34
    int m_n38;        // +0x38
};
MS2_CHECK_SIZE(RideOffActionHomemade, 0x40);

class RideOffActionAutoInteraction : public RideOffAction
{
public:
    RideOffActionAutoInteraction(int nArg = 0);
    ~RideOffActionAutoInteraction() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    int m_n28;        // +0x28
    unsigned int m_n2c;        // +0x2c
    int m_n30;        // +0x30
};
MS2_CHECK_SIZE(RideOffActionAutoInteraction, 0x38);

class RideOffActionAutoClimb : public RideOffAction
{
public:
    RideOffActionAutoClimb(int nArg = 0);
    ~RideOffActionAutoClimb() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
};
MS2_CHECK_SIZE(RideOffActionAutoClimb, 0x28);

class RideOffActionCoupleEmotion : public RideOffAction
{
public:
    RideOffActionCoupleEmotion(int nArg = 0);
    ~RideOffActionCoupleEmotion() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    int m_n28;        // +0x28
    __int64 m_n30;        // +0x30
};
MS2_CHECK_SIZE(RideOffActionCoupleEmotion, 0x38);

class RideOffActionReact : public RideOffAction
{
public:
    RideOffActionReact(int nArg = 0);
    ~RideOffActionReact() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    int m_n28;        // +0x28
    CString m_s30;        // +0x30
};
MS2_CHECK_SIZE(RideOffActionReact, 0x38);

class RideOffActionUseFunctionItem : public RideOffAction
{
public:
    RideOffActionUseFunctionItem(int nArg = 0);
    ~RideOffActionUseFunctionItem() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    __int64 m_n28;        // +0x28
    CStringW m_s30;        // +0x30
};
MS2_CHECK_SIZE(RideOffActionUseFunctionItem, 0x38);

class RideOffActionNurturing : public RideOffAction
{
public:
    RideOffActionNurturing(int nArg = 0);
    ~RideOffActionNurturing() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    CString m_s28;        // +0x28
    int m_n30;        // +0x30
};
MS2_CHECK_SIZE(RideOffActionNurturing, 0x38);

class RideOffActionGroggy : public RideOffAction
{
public:
    RideOffActionGroggy(int nArg = 0);
    ~RideOffActionGroggy() override;
};
MS2_CHECK_SIZE(RideOffActionGroggy, 0x28);

class RideOffActionUnRideSkill : public RideOffAction
{
public:
    RideOffActionUnRideSkill(int nArg = 0);
    ~RideOffActionUnRideSkill() override;
};
MS2_CHECK_SIZE(RideOffActionUnRideSkill, 0x28);

class RideOffActionUseGlideItem : public RideOffAction
{
public:
    RideOffActionUseGlideItem(int nArg = 0);
    ~RideOffActionUseGlideItem() override;
    void vfunc_1(COutputStream* pStream) override;
    void vfunc_2(CInputStream* pStream) override;
    __int64 m_n28;        // +0x28
    bool m_b30;        // +0x30
    int m_n34;        // +0x34
};
MS2_CHECK_SIZE(RideOffActionUseGlideItem, 0x38);

class RideOffActionHideAndSeek : public RideOffAction
{
public:
    RideOffActionHideAndSeek(int nArg = 0);
    ~RideOffActionHideAndSeek() override;
};
MS2_CHECK_SIZE(RideOffActionHideAndSeek, 0x28);

// Factories: read the type byte, build the record, then decode its fields.
MS2Ptr<RideOnAction> ReadRideOnAction(CInputStream* pStream);      // 0x14077deb0
MS2Ptr<RideOffAction> ReadRideOffAction(CInputStream* pStream);     // 0x14077e5b0
