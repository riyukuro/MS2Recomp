// CMouseController (RTTI name): the singleton that turns mouse input in the 3D world into "click to move / click an NPC,
// portal or object" behaviour. It keeps a list of CMouseInteract strategies (talk cancel, taxi, UGC banner, weapon object,
// portal, object, NPC), asks each one in turn what is under the cursor, remembers the winner and drives the local player
// towards the clicked ground point. Member names are invented from their use.
// Owning unit: unit_140ad1860 (0x140ad1860-0x140ad5280). The CMouseInteract* ctors / dtors / vfunc_6 live there too.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/mctimer.h"
#include "ms2/client/ms2/mouseinteract.h"
#include <egf/EntityID.h>

namespace egf { class Entity; }


class Unk_McPc;
class Unk_McAttach;
class Unk_McApp;

class CMouseController : public TSingleton<CMouseController>
{
public:
    CMouseController();                                     // 0x140ad1860
    virtual ~CMouseController();                            // 0x140ad1d20 (scalar deleting 0x140ad4810)

    void FUN_140ad1da0(int nMsg, int nX, int nY);           // mouse message dispatcher (0x200 move, 0x201 down, 0x202 up, 0x2a3 leave)
    void FUN_140ad1ef0();                                   // per-frame update
    void FUN_140ad1f30(int nOldAction, int nNewAction);     // the player's action changed
    void FUN_140ad2070();                                   // forget the click vectors
    int FUN_140ad20f0(int bEnable);                         // switch the controller on / off (false when the option is missing)
    int HasMode();                                   // is the controller on
    int FUN_140ad21f0();                                    // does the move vector differ from zero
    int FUN_140ad2220();                                   // move vector y > 0
    int FUN_140ad2260();                                   // move vector y < 0
    Unk_StreamPoint GetMove();                        // the move vector
    void FUN_140ad22d0();                                   // reset and go idle
    void FUN_140ad2300(Unk_StreamPoint pt);                 // spawn the click effect at pt
    void FUN_140ad23f0(int nX, int nY);                     // button released
    void FUN_140ad2660(int nX, int nY);                                // button pressed
    void FUN_140ad26d0(int nX, int nY);                     // mouse moved while the button is held
    void FUN_140ad2830();                                   // interact ray from the player
    int FUN_140ad2ac0(int nX, int nY, CStringW* pStrHint);  // cursor kind under the mouse (and its hint string)
    void FUN_140ad2d80();                                   // hover update
    void FUN_140ad3040();                                   // movement progress check
    Unk_StreamPoint FUN_140ad3260(Unk_StreamPoint pt);      // direction towards pt in the map's plane
    Unk_StreamPoint FUN_140ad3400(Unk_StreamPoint pt);      // direction towards pt for side-view maps
    int FUN_140ad3550(int nX, int nY, Unk_StreamPoint* pOut);   // pick an interact strategy
    Unk_StreamPoint FUN_140ad3740(int nX, int nY);          // pick a point with the scene pick
    Unk_StreamPoint FUN_140ad3a60(int nX, int nY);          // intersect the cursor ray with the player's plane
    Unk_StreamPoint FUN_140ad3c70();                        // position of the player (or what it rides)
    int FUN_140ad3d60();                                    // any of the three slots occupied
    int FUN_140ad3dd0(int nX, int nY);                      // cursor inside the window
    bool FUN_140ad3e80(egf::Entity* pEntity);       // entity may be clicked
    bool FUN_140ad3fb0(const egf::EntityID& id);   // same, by entity id
    void FUN_140ad4000(const Unk_StreamPoint* pPoint);      // remember the clicked point
    void FUN_140ad40b0();                                   // drop the selected strategy
    int FUN_140ad4140(int nMapId);                          // map allows a special pick

    int m_nMode;                                            // +0x08 0 off, 1 idle, 2 moving, 3 button held
    Unk_StreamPoint m_vMove;                                // +0x0c
    Unk_StreamPoint m_vDown;                                // +0x18 clicked point
    Unk_StreamPoint m_vDir;                                 // +0x24
    float m_fLastDist;                                      // +0x30
    float m_fAccumDist;                                     // +0x34
    Unk_McTimer m_tmMove;                                   // +0x38
    Unk_McTimer m_tmHold;                                   // +0x40
    Unk_McTimer m_tmPick;                                   // +0x48
    MS2Ptr<CMouseInteract> m_spCurrent;                     // +0x50
    ATL::CAtlArray<MS2Ptr<CMouseInteract> > m_arrInteract;  // +0x60
    int m_nIgnoreRelease;                                   // +0x80
};
MS2_CHECK_OFFSET(CMouseController, m_nMode, 0x08);
MS2_CHECK_OFFSET(CMouseController, m_vMove, 0x0c);
MS2_CHECK_OFFSET(CMouseController, m_vDown, 0x18);
MS2_CHECK_OFFSET(CMouseController, m_vDir, 0x24);
MS2_CHECK_OFFSET(CMouseController, m_fLastDist, 0x30);
MS2_CHECK_OFFSET(CMouseController, m_tmMove, 0x38);
MS2_CHECK_OFFSET(CMouseController, m_tmPick, 0x48);
MS2_CHECK_OFFSET(CMouseController, m_spCurrent, 0x50);
MS2_CHECK_OFFSET(CMouseController, m_arrInteract, 0x60);
MS2_CHECK_OFFSET(CMouseController, m_nIgnoreRelease, 0x80);
