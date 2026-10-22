// Recovered bingo event dialog (5x5 board: the player picks a free or cash magic pencil, the daily numbers are crossed
// off, completed lines and the 12 line bingo play effects and unlock the reward buttons). Unk_ names are local
// reconstruction names.
#pragma once
#include <queue>
#include <atlcoll.h>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/tptreddummy.h"
class ASMovieClip;
class ASTextField;
class ASItemSlot;
class CMsgBoxData;
class Unk_140acd6e0;
class Unk_BingoClip;
class Unk_BingoScript;

void FUN_14015b020(CPtred*);
int FUN_140159bc0(CPtred*);
void FUN_140159ba0(CPtred*);
CPtred* FUN_1401ba820(CPtred*);

// Smart pointer to the value of a TPtredDummy<CAtlArray<MS2Ptr<ASItemSlot>>> (same shape as Unk_PktPtr of
// commonfiles\clientreconnectionstructs.h): the item slots shown in one reward list.
struct Unk_BingoNewTag { explicit Unk_BingoNewTag(int); };
class Unk_BingoSlots
{
public:
    typedef ATL::CAtlArray<MS2Ptr<ASItemSlot> > Array;
    Unk_BingoSlots() : m_p(0) {}
    Unk_BingoSlots(const Unk_BingoNewTag&) : m_p(0) { Make(); }
    Unk_BingoSlots(const Unk_BingoSlots& o) : m_p(o.m_p) { AddRef(); }
    ~Unk_BingoSlots() { Release(); }
    Unk_BingoSlots& operator=(const Unk_BingoSlots& o)
    {
        o.AddRef();
        Release();
        m_p = o.m_p;
        return *this;
    }
    Array* get() const { return m_p; }
    Array* operator->() const { return m_p; }

private:
    void AddRef() const { if (m_p) AddRefImpl(0); }
    void Make() { Release(); m_p = Create(0); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    static TPtredDummy<Array>* Allocate(void*) { return new TPtredDummy<Array>(); }
    static Array* Value(TPtredDummy<Array>* p) { return p == NULL ? NULL : &p->value; }
    static TPtredDummy<Array>* Owner(Array* p) { return p == NULL ? NULL : reinterpret_cast<TPtredDummy<Array>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<Array>, value)); }
    static void Ref(CPtred* p) { FUN_14015b020(p); }
    static Array* Create(void*) { return Value(static_cast<TPtredDummy<Array>*>(FUN_1401ba820(Allocate(0)))); }
    void AddRefImpl(void*) const { Ref(Owner(m_p)); }
    void ReleaseImpl(void*)
    {
        CPtred* owner = Owner(m_p);
        if (FUN_140159bc0(owner) == 0) { Ref(owner); FUN_140159ba0(owner); }
    }
    void* m_00;
    Array* m_p;                                 // +0x08
};
MS2_CHECK_SIZE(Unk_BingoSlots, 0x10);

// The icon, item slot, text and buttons of the free / cash magic pencil panel.
struct Unk_BingoPanel
{
    MS2Ptr<ASMovieClip> m_icon;                 // +0x00
    MS2Ptr<ASItemSlot> m_slot;                  // +0x10
    MS2Ptr<ASTextField> m_text;                 // +0x20
    MS2Ptr<Unk_140acd6e0> m_use;              // +0x30
    MS2Ptr<Unk_140acd6e0> m_cancel;           // +0x40
    MS2Ptr<ASMovieClip> m_effect;               // +0x50
    void FUN_140bb69a0();                       // clears every member
    void FUN_140bb7fd0();                       // idle look
    void FUN_140bb8100();                       // selected look
};
MS2_CHECK_SIZE(Unk_BingoPanel, 0x60);

// One queued cell animation of the pencil (kind 0 = appear and draw, 1 = appear, 2 = flip).
struct Unk_BingoStep
{
    // @0x140bb5930
    Unk_BingoStep(int nKind, MS2Ptr<ASMovieClip> clip, int nIndex, bool bFlag) { m_kind = nKind; m_clip = clip; m_index = nIndex; m_flag = bFlag; }
    // @0x140bb59b0
    Unk_BingoStep(int nKind, MS2Ptr<ASMovieClip> clip, bool bFlag) { m_kind = nKind; m_clip = clip; m_index = -1; m_flag = bFlag; }
    int m_kind;                                 // +0x00
    MS2Ptr<ASMovieClip> m_clip;                 // +0x08
    int m_index;                                // +0x18 board cell (-1 none)
    bool m_flag;                                // +0x1c plus pencil
};
MS2_CHECK_SIZE(Unk_BingoStep, 0x20);

class UIBingoEventDialog : public UIDialog
{
public:
    UIBingoEventDialog();
    virtual ~UIBingoEventDialog();
    virtual CString GetTypeName();
    virtual int vfunc_65();
    virtual void vfunc_26();
    virtual void vfunc_43();
    virtual void vfunc_72();
    virtual void OnLoadComplete();
    virtual void vfunc_79(void*);
    virtual int OnMessage(UISwfEntity*, UIMsg*);
    // @0x140bb6c60
    virtual int vfunc_48() { return 20355; }
    void FUN_140bb06e0(const Scaleform::GFx::FunctionHandler::Params&);
    void SendEventRewardMode23(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140bb0ea0(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140bb13e0(const Scaleform::GFx::FunctionHandler::Params&);
    bool FUN_140bb1460(int, const CMsgBoxData&);
    bool FUN_140bb14a0(int, const CMsgBoxData&);
    void FUN_140bb14d0();
    void FUN_140bb1580();
    void FUN_140bb1d60();
    void FUN_140bb2310();
    void FUN_140bb2720();
    void FUN_140bb2c40();
    void FUN_140bb3050(int);
    void FUN_140bb3bd0();
    unsigned FUN_140bb3f80();
    void FUN_140bb4040();
    void FUN_140bb4150(unsigned);
    void FUN_140bb43a0(ATL::CAtlArray<bool>&, ATL::CAtlArray<int>&);
    void FUN_140bb46e0();
private:
    MS2_LAYOUT_FRIEND;
    int m_state;                                // +0x178 0 none, 1 free pencil, 2 cash pencil
    unsigned m_stage;                           // +0x17c
    ATL::CAtlArray<int> m_checked;              // +0x180 crossed numbers
    ATL::CAtlArray<int> m_board;                // +0x1a0 the 25 board numbers
    ATL::CAtlArray<int> m_received;             // +0x1c0 received reward indices
    ATL::CAtlArray<int> m_called;               // +0x1e0 daily numbers
    CMsTime m_time;                             // +0x200 last server time
    bool m_msgOpen;                             // +0x210 a message box is open
    ATL::CAtlArray<MS2Ptr<ASMovieClip> > m_cells;   // +0x218
    ATL::CAtlArray<MS2Ptr<ASMovieClip> > m_lines;   // +0x238
    MS2Ptr<ASMovieClip> m_board5;               // +0x258
    MS2Ptr<ASMovieClip> m_firework;             // +0x268
    ATL::CAtlArray<MS2Ptr<ASMovieClip> > m_rewardLists;   // +0x278
    ATL::CAtlArray<MS2Ptr<Unk_140acd6e0> > m_receive;   // +0x298
    ATL::CAtlArray<Unk_BingoSlots> m_rewardSlots;   // +0x2b8
    Unk_BingoPanel m_free;                      // +0x2d8
    Unk_BingoPanel m_cash;                      // +0x338
    unsigned m_tick;                            // +0x398
    ATL::CAtlArray<bool> m_lineDone;            // +0x3a0
    ATL::CAtlArray<bool> m_lineShown;           // +0x3c0
    ATL::CAtlArray<int> m_checkedCopy;          // +0x3e0
    std::queue<Unk_BingoStep> m_steps;          // +0x400
};
MS2_CHECK_SIZE(UIBingoEventDialog, 0x428);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_state, 0x178);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_checked, 0x180);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_time, 0x200);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_msgOpen, 0x210);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_cells, 0x218);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_board5, 0x258);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_rewardLists, 0x278);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_rewardSlots, 0x2b8);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_free, 0x2d8);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_cash, 0x338);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_tick, 0x398);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_lineDone, 0x3a0);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_checkedCopy, 0x3e0);
MS2_CHECK_OFFSET(UIBingoEventDialog, m_steps, 0x400);
