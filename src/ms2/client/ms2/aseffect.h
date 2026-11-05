// aseffect.h - ASEffect / ASEffectManager: the C++ side of the buff / debuff icon strip (Scaleform clips
// "export_additional_effect" and a flash.display.MovieClip container pair). Owning unit: ?\aseffect.cpp
// (0x1409b2d70-0x1409b8e30, .text$mn; the .text$di statics at 0x1400c03c0). Header name assumed from the unit path;
// both class names are real (RTTI, vftables 0x142db6f30 / 0x142db7470).
//
// ASEffect (0xf0) : ASMovieClip shows one buff (its icon, a cooldown sweep clip, a border colour, a remaining-time
// text and a stack-count text). ASEffectManager (0x120) : ASMovieClip owns the effects of the local player, keyed by
// the buff id, and lays them out in two rows (own buffs / debuffs) under two container clips.
// The buff object itself is AdditionalCli (additionalcli.h).
#pragma once

#include "ms2/placeholder/intervaltimer.h"

#include <afx.h>
#include <atlcoll.h>
#include <list>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ascript.h"

// The buff record: AdditionalCli (additionalcli.h).
class AdditionalCli;

// 8-byte millisecond poll timer (ctor 0x140517b00, "interval elapsed" test 0x140268870 re-arms).
typedef Unk_IntervalTimer Unk_AsTimer;

class ASEffect : public ASMovieClip
{
public:
    explicit ASEffect(MS2Ptr<AdditionalCli> spBuff);                   // 0x1409b2d70 (the argument is destroyed by the callee)
    virtual ~ASEffect();                                            // 0x1409b2ec0

    void BindChildren();                                            // 0x1409b2fb0 create the AS object, bind its children
    bool IsLoaded();                                                // 0x1409b3300 the AS object exists
    void Update();                                                  // 0x1409b3330 per-frame cooldown sweep / remaining time
    void UpdateIcon();                                              // 0x1409b3a20 border colour, stack count, icon
    CStringW FormatRemain(float fSeconds);                          // 0x1409b3d50 "{0}{1}" count + unit
    void SetE0(int n);                                              // 0x1409b3700
    void SetE4(int n);                                              // 0x1409b3720
    void SetBuff(MS2Ptr<AdditionalCli> spBuff);                        // 0x1409b3740 (by value: callee destroys)
    void SetStartTime(int nTime);                                   // 0x1409b37c0
    bool IsBuffType();                                              // 0x1409b37e0
    bool IsTimed();                                                 // 0x1409b3820
    bool IsOwnerAlive();                                            // 0x1409b3840
    void FUN_1409b3900();                                           // 0x1409b3900 buff id
    int GetE4();                                                    // 0x1409b3930
    void GetTooltip(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x1409b3950 "GetTooltipCallback"

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<AdditionalCli> m_buff;                                      // +0x80
    int m_90;                                                       // +0x90 start time (ms clock)
    Unk_AsTimer m_94;                                               // +0x94 text refresh timer
    MS2Ptr<ASMovieClip> m_a0;                                       // +0xa0 m_cooldown
    MS2Ptr<ASMovieClip> m_b0;                                       // +0xb0 m_buffBorder
    MS2Ptr<ASTextField> m_c0;                                       // +0xc0 m_textField (remaining time)
    MS2Ptr<ASTextField> m_d0;                                       // +0xd0 m_textCountField (stacks)
    int m_e0;                                                       // +0xe0 owner level for the tooltip
    int m_e4;                                                       // +0xe4 list sort key
    bool m_e8;                                                      // +0xe8 timed (sweep running)
    bool m_e9;                                                      // +0xe9 icon needs refresh
};
MS2_CHECK_SIZE(ASEffect, 0xf0);
MS2_CHECK_OFFSET(ASEffect, m_buff, 0x80);
MS2_CHECK_OFFSET(ASEffect, m_94, 0x94);
MS2_CHECK_OFFSET(ASEffect, m_a0, 0xa0);
MS2_CHECK_OFFSET(ASEffect, m_d0, 0xd0);
MS2_CHECK_OFFSET(ASEffect, m_e8, 0xe8);

class ASEffectManager : public ASMovieClip
{
public:
    ASEffectManager(const Scaleform::GFx::Value& v, int nMovieId);  // 0x1409b5200
    virtual ~ASEffectManager();                                     // 0x1409b5580

    void Update();                                                  // 0x1409b5610
    void SetPosA(int x, int y);                                     // 0x1409b57b0 move the own-buff container
    void SetPosB(int x, int y);                                     // 0x1409b5810 move the debuff container
    void SetE0(int n);                                              // 0x1409b5870
    void SetMax(int n);                                             // 0x1409b5890
    void SetColumns(int n);                                         // 0x1409b58b0
    void SetUp(bool b);                                             // 0x1409b58d0
    void SetFilter(bool b);                                         // 0x1409b58f0
    void AddEffect(MS2Ptr<AdditionalCli> spBuff);                      // 0x1409b5940 (by value: callee destroys)
    void UpdateEffect(MS2Ptr<AdditionalCli> spBuff);                   // 0x1409b5aa0
    void RemoveEffect(int nBuffId);                                 // 0x1409b5b60
    void Clear();                                                   // 0x1409b5c20

private:
    MS2_LAYOUT_FRIEND;
    void Attach(MS2Ptr<ASEffect> spEffect);                         // 0x1409b6170
    void Detach(MS2Ptr<ASEffect> spEffect);                         // 0x1409b6370
    void InsertSorted(std::list<MS2Ptr<ASEffect> >& list, MS2Ptr<ASEffect> spEffect);   // 0x1409b5d10
    void Remove(std::list<MS2Ptr<ASEffect> >& list, MS2Ptr<ASEffect> spEffect);        // 0x1409b5e30
    void Layout(std::list<MS2Ptr<ASEffect> >& list, bool bFilter);                    // 0x1409b5f10

    MS2Ptr<ASMovieClip> m_80;                                       // +0x80 container of the own buffs
    MS2Ptr<ASMovieClip> m_90;                                       // +0x90 container of the debuffs
    int m_a0;                                                       // +0xa0
    int m_a4;                                                       // +0xa4 most icons per row set
    bool m_a8;                                                      // +0xa8 layout dirty
    int m_ac;                                                       // +0xac icons per row
    bool m_b0;                                                      // +0xb0 rows grow upwards
    bool m_b1;                                                      // +0xb1 filter by owner
    ATL::CAtlMap<int, MS2Ptr<ASEffect> > m_b8;                      // +0xb8 buff id -> effect
    std::list<MS2Ptr<ASEffect> > m_100;                             // +0x100
    std::list<MS2Ptr<ASEffect> > m_110;                             // +0x110
};
MS2_CHECK_SIZE(ASEffectManager, 0x120);
MS2_CHECK_OFFSET(ASEffectManager, m_90, 0x90);
MS2_CHECK_OFFSET(ASEffectManager, m_b8, 0xb8);
MS2_CHECK_OFFSET(ASEffectManager, m_100, 0x100);
MS2_CHECK_OFFSET(ASEffectManager, m_110, 0x110);
