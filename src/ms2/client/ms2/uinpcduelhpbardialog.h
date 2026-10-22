// uinpcduelhpbardialog.h - UINpcDuelHPBarDialog (RTTI .?AVUINpcDuelHPBarDialog@@, 0x198 bytes, UI id 0x4f62, swf
// "NpcDuelHPBarDialog"): the NPC duel bar. Left side = the local player (name, job icon, profile, hp), right side =
// the duel NPC (name, level, profile, multi-bar hp), a countdown "setTime" and the NPC's buff icons. Owning unit:
// client\ms2\uinpcduelhpbardialog.cpp (0x140e6b7b0-0x140e6d3c0). Header name assumed from the unit path (w13).
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASEffectManager;
class Unk_NdBuff;

class UINpcDuelHPBarDialog : public UIDialog
{
public:
    UINpcDuelHPBarDialog();                             // 0x140e6b7b0
    virtual ~UINpcDuelHPBarDialog();                    //  0 0x140e6b850 (??_G 0x140e6d260)
    virtual CString GetTypeName();                          //  1 0x140e6b8a0 "NpcDuelHPBarDialog"
    virtual void vfunc_43();                            // 43 0x140e6c6c0 entity bar placement (1, 0, 50) + visible
    virtual void vfunc_67();                            // 67 0x140e6b8f0 close: reset the duel
    virtual void vfunc_72();                            // 72 0x140e6b950 per-tick refresh
    virtual void OnLoadComplete();                      // 22 0x140e6b9e0 create the effect manager clip
    virtual int vfunc_48() { return 0x4f62; }           // 48 0x140e6d2a0

    void FUN_140e6bb70(int nObjectId, int nDurationMs, int nBarCount);   // start a duel (npc id, time, bars)
    void FUN_140e6bc10();                               // refresh both profiles, hp bars and the npc buffs
    void FUN_140e6c440(MS2Ptr<Unk_NdBuff> buff);        // add a buff icon (when it belongs to the npc)
    void FUN_140e6c540(MS2Ptr<Unk_NdBuff> buff);        // remove a buff icon
    void FUN_140e6c640(int nBuffId);                    // update a buff icon
    void FUN_140e6c7a0();                               // "setTime" mmss
    void FUN_140e6c900();                               // "setHpBarLeft" (local player hp, max hp)
    void FUN_140e6c9c0();                               // "setHpBarRight" (npc hp split into bars)

private:
    MS2_LAYOUT_FRIEND;
    int m_nObjectId;                                    // +0x178 object id of the duel npc
    unsigned int m_nEndTick;                            // +0x17c tick at which the duel ends
    int m_nBarCount;                                    // +0x180 hp bars of the npc (1 = single)
    MS2Ptr<ASEffectManager> m_effects;                  // +0x188 buff icon container
};
MS2_CHECK_SIZE(UINpcDuelHPBarDialog, 0x198);
MS2_CHECK_OFFSET(UINpcDuelHPBarDialog, m_nObjectId, 0x178);
MS2_CHECK_OFFSET(UINpcDuelHPBarDialog, m_nBarCount, 0x180);
MS2_CHECK_OFFSET(UINpcDuelHPBarDialog, m_effects, 0x188);
