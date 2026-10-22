// cubecraft_2.h - the PC cube-craft (housing build) controller: one per local player in build mode, created by the
// PC (PCBase::+0x1020, ctor call in 0x141659250). Owning unit: client\ms2\cubecraft.cpp#2-core
// (0x1410a8550-0x1410af930). Name assumed (referenced as Unk_PCCubeCraft / Unk_CubeCraftCore by the units that call
// it); member names are invented from the code. Layout from the ctor 0x1410a8550 / dtor body 0x1410a8880
// (allocation 0x1a8). Not virtual.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <efd/SmartPointer.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/commonfiles/timer.h"

class PC;
class CubeItemInfo;
class CCubeGuideWrapper;   // cubeguide.h
class CGodModeInfo;        // 0x30-byte floating "god mode" marker (cubecraft_1.cpp)
class CItem;
class Cube;
class Unk_Service6100017;   // the cube grid service (class id 0x06100017)

// The 16-byte pointer-sized pair {vptr slot, T*} of the guide wrapper smart pointer is MS2Ptr<CCubeGuideWrapper>.
class Unk_PCCubeCraft
{
public:
    Unk_PCCubeCraft(PC* pOwner, int nMode, CubeItemInfo* pInfo);    // 0x1410a8550
    ~Unk_PCCubeCraft();                                                 // 0x1410a8880
    void SendRequestCubeMode0(int nValue);                                     // send the build-state packet (0x37, 0, nValue)
    int GetMode();                                                // the mode (0 build, 1 inventory edit, 2 move)
    int FUN_1410a8ab0();                                                // mode == 2
    void FUN_1410a8af0(bool bEnable);                                   // enter / leave the build mode
    void FUN_1410a92c0();                                               // create the placement guide (NIF)
    void FUN_1410a9630();                                               // create the owned guide (NIF / KFM / doll)
    void FUN_1410a9cc0();                                               // rebuild the guides for the current mode
    void FUN_1410a9d60();                                               // drop the effect node and the guide
    void FUN_1410a9e70();                                               // drop the second guide
    void FUN_1410a9ee0();                                               // move the guides to the cell position
    bool FUN_1410aa010();                                               // the second guide exists
    void FUN_1410aa060(unsigned char bUp);                                       // lift +- 150
    void FUN_1410aa0c0(CubeItemInfo* pInfo);                            // select an item to place
    int FUN_1410aa1f0();                                                // mode != 2
    int FUN_1410aa220();                                                // mode is 0 or 1
    int FUN_1410aa260();                                               // the six cells below are free
    void FUN_1410aa380(bool bVisible);                                  // show / hide the guide
    bool FUN_1410aa420();                                               // the guide is idle
    void FUN_1410aa4a0(bool bVisible);                                  // show / hide the second guide
    Vector3 GetPtCell();                                    // the cell position
    void FUN_1410aa550(int nMode);                                      // set the mode
    void FUN_1410aa590();                                               // arm the move timer (200 ms)
    void FUN_1410aa5c0(CubeItemInfo* pInfo);                            // set the item (or clear it)
    void FUN_1410aa6f0(Vector3 kPos, char bNoUpdate);    // place the guide at a cell
    void FUN_1410aad50();                                               // confirm: build / move / rotate
    void FUN_1410ab5a0();                                               // remove (without the notice)
    void FUN_1410ab5c0(unsigned char bNotice);                          // remove the cube at the cell
    void FUN_1410abb40();                                               // pick the cube at the cell
    void FUN_1410ac1c0();                                               // lift the character up
    void FUN_1410ac380();                                               // lift the character down
    void FUN_1410ac540();                                               // request the cube's message
    void FUN_1410ac960();                                               // second guide vfunc_1
    void FUN_1410ac9b0();                                               // per-frame update
    char GetPending();                                               // m_bPending
    int FUN_1410ad610();                                                // the item id
    __int64 FUN_1410ad640();                                            // the item instance id
    CubeItemInfo* FUN_1410ad670();                                      // the item
    int FUN_1410ad6a0(int nItemId);                                     // the fitting-doll type of an item
    void FUN_1410ad780();                                               // create the three effect items
    void FUN_1410add30();                                               // drop the three effect items
    void FUN_1410aded0();                                               // request a move / install
    void FUN_1410ae380(Vector3 kPos);                    // run the build validator
    void FUN_1410ae960(unsigned* pLeft, unsigned* pRight);              // can the character lift up / down
    void FUN_1410aeec0(const Vector3& kPos);                    // snap down to the nearest cube column
    void FUN_1410af0c0();                                               // empty
    void FUN_1410af0d0();                                               // drop the third guide
    void FUN_1410af140();                                               // orient the third guide
    void FUN_1410af1f0();                                               // find the housing quest cell

    PC* m_pOwner;                           // +0x00 the local player
    float m_fScale;                         // +0x08 (1.0)
    int m_pad_0c;
    MS2Ptr<CCubeGuideWrapper> m_spGuide;    // +0x10
    MS2Ptr<CCubeGuideWrapper> m_spGuide2;   // +0x20
    float m_fLift;                          // +0x30
    int m_pad_34;
    MS2Ptr<CubeItemInfo> m_spItem;          // +0x38
    MS2Ptr<CubeItemInfo> m_spItem2;         // +0x48
    Vector3 m_ptLast;               // +0x58
    Vector3 m_ptCell;               // +0x64
    Timer m_tPulse;                         // +0x70
    Timer m_tSlide;                         // +0xa8
    Timer m_tRotate;                        // +0xe0
    float m_fRotFrom;                       // +0x118
    float m_fRotTo;                         // +0x11c
    float m_fYaw;                           // +0x120
    int m_pad_124;
    MS2Ptr<CItem> m_spEffectA;              // +0x128
    MS2Ptr<CItem> m_spEffectB;              // +0x138
    MS2Ptr<CItem> m_spEffectC;              // +0x148
    Unk_NodePtr m_spNode;                   // +0x158
    int m_nHud;                             // +0x160 (1 shown)
    int m_nMode;                            // +0x164
    efd::SmartPointer<Unk_Service6100017> m_svc;   // +0x168
    MS2Ptr<CGodModeInfo> m_spGod;           // +0x170
    bool m_bFirstMove;                      // +0x180
    int m_nCheck;                           // +0x184 the validator result
    MS2Ptr<CCubeGuideWrapper> m_spGuide3;   // +0x188
    Vector3 m_ptOffset;             // +0x198
    bool m_bVisible;                        // +0x1a4
    bool m_bPending;                        // +0x1a5
    short m_pad_1a6;
};
MS2_CHECK_SIZE(Unk_PCCubeCraft, 0x1a8);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_spGuide, 0x10);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_spItem, 0x38);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_ptCell, 0x64);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_tPulse, 0x70);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_tRotate, 0xe0);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_spEffectA, 0x128);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_spNode, 0x158);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_nMode, 0x164);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_svc, 0x168);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_spGod, 0x170);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_spGuide3, 0x188);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_ptOffset, 0x198);
MS2_CHECK_OFFSET(Unk_PCCubeCraft, m_bVisible, 0x1a4);
