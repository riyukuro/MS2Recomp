// additionalcli.h - AdditionalCli (RTTI .?AVAdditionalCli@@, 0x78 bytes, vftable 0x142db12c8): the client record of one
// additional effect (buff / debuff) on an actor - the table row (AdditionalLevelData), its owner, caster, overlap count,
// timing, shield value and the keep effect it plays - and AdditionalCustomCli (RTTI, 0x78, vftable 0x142db12d8), a
// locally started record. Recovered with ?\additionalcli.cpp#1 (0x14096bae0-0x14096ee00). Header name assumed; member
// and method names are invented from use (the exe has the log text "CAdditionalEffect::DecodeModifyPacket").
// The packet records (Unk_AdditionalOwner / Unk_AdditionalState / Unk_AdditionalValue) are in
// commonfiles/additionalactionadditional.h.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/additionalactionadditional.h"

class PCBase;
class CInPacket;

class AdditionalCli : public CPtred
{
public:
    AdditionalCli();                                        // 0x14096bae0
    virtual ~AdditionalCli();                               // 0x14096bbe0 (??_G 0x14096e8e0)

    bool FUN_14096bc20(int nOwner, MS2Ptr<AdditionalCli> spSrc);    // copy spSrc onto this actor (clone)
    void FUN_14096bd30(PCBase* pOwner, int nId, unsigned short nLevel, int n44);   // start a local record
    void FUN_14096be10(PCBase* pOwner, const Unk_AdditionalOwner& owner, CInPacket& packet);   // full decode
    void FUN_14096bf40(PCBase* pOwner, unsigned nFlags, const Unk_AdditionalOwner& owner, CInPacket& packet);   // DecodeModifyPacket
    void FUN_14096c2a0(const Unk_AdditionalOwner& owner);  // key and caster
    void FUN_14096c2e0(const Unk_AdditionalState& state);   // times, id, level, count, enabled
    void FUN_14096c360(const Unk_AdditionalValue& value);   // shield value
    void FUN_14096c390(const Unk_AdditionalValue& value);   // shield max
    void FUN_14096c3c0(CStringW str, int n);                // empty
    void FUN_14096c3f0();                                   // start the stance bar
    void FUN_14096c4c0();                                   // play the start effect unless active
    void FUN_14096c520();                                   // per-frame update
    void FUN_14096c650(int nCaster);                        // removed: stop effects, play the stop effect
    int FUN_14096c6f0();                                    // has an owner and a row
    void FUN_14096c740();                                   // (re)play the keep effect
    void FUN_14096c7a0();                                   // play the keep effect
    void FUN_14096c8e0();                                   // overlap start effect of the current count
    void FUN_14096ca50();                                   // overlap effects
    void FUN_14096ca80();                                   // overlap keep effect of the current count
    void FUN_14096ccc0(int nCount);                         // overlap end effect
    void FUN_14096ce50();                                   // stop the keep effect
    void FUN_14096cec0();                                   // play the invoke effect
    int FUN_14096d050();                                    // shown (enabled or time left)
    void FUN_14096d0c0();                                   // stance bar time
    void FUN_14096d130();                                   // stance bar step
    int FUN_14096d260();                                    // key
    PCBase* FUN_14096d280();                                // owner
    unsigned FUN_14096d2a0();                               // effect id
    unsigned short FUN_14096d2c0();                         // level
    unsigned FUN_14096d2e0();                               // remaining ms (0 when unlimited or over)
    unsigned FUN_14096d330();                               // total ms
    int FUN_14096d350();                                    // sort key of the buff strip
    void FUN_14096d430();                                   // tell the buff UIs
    void FUN_14096d5c0();                                   // shield bar value
    bool FUN_14096d6b0();                                   // has a cooldown-less keep effect of the own caster
    bool FUN_14096d7a0();                                   // shows a timer sweep
    AdditionalLevelData* FUN_14096d810();                   // the row
    void FUN_14096d840();                                   // play the start effect
    void FUN_14096d9d0(int nCaster);                        // play the stop effect
    int FUN_14096db00();                                    // the owner is a portrait (no effects)
    void FUN_14096db40();                                   // drop when the required skill is not running

    int m_nCasterId;                                        // +0x18 caster object id
    unsigned m_nStartTick;                                  // +0x1c
    unsigned m_nEndTick;                                    // +0x20 (0: unlimited)
    unsigned m_nOverlapCount;                               // +0x24 (1)
    int m_bEnabled;                                         // +0x28 (1)
    int m_bSuspended;                                       // +0x2c
    __int64 m_nShieldValue;                                 // +0x30
    __int64 m_nShieldMax;                                   // +0x38 (not set by the ctor)
    int m_b40;                                              // +0x40 from the field enter list
    int m_b44;                                              // +0x44
    int m_nKey;                                             // +0x48
    PCBase* m_pOwner;                                       // +0x50
    unsigned m_nId;                                         // +0x58
    unsigned short m_nLevel;                                // +0x5c
    unsigned m_nKeepEffect;                                 // +0x60 CEffectService id of the keep effect
    MS2Ptr<AdditionalLevelData> m_spLevel;                  // +0x68
};
MS2_CHECK_SIZE(AdditionalCli, 0x78);
MS2_CHECK_OFFSET(AdditionalCli, m_nShieldValue, 0x30);
MS2_CHECK_OFFSET(AdditionalCli, m_pOwner, 0x50);
MS2_CHECK_OFFSET(AdditionalCli, m_spLevel, 0x68);

class AdditionalCustomCli : public AdditionalCli
{
public:
    AdditionalCustomCli(PCBase* pOwner, int nKey, int nId, unsigned nEndTick, unsigned nCount);   // 0x14096dcb0
    // MS2-FUNCTIONAL: the exe dtor skips the vftable store (no source form found in 2 tries)
    virtual ~AdditionalCustomCli() {}                       // 0x14096e600 (??_G 0x14096e920)
};
MS2_CHECK_SIZE(AdditionalCustomCli, 0x78);
