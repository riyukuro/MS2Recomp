// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The smart push classes of ?\smartpush.cpp (RTTI names):
// one class per kind of suggestion row of Table/smartPush.xml, created by name through the ClassObject factory
// ("CSmartPush" + the row's content) and polled by CSmartPushManager. Each push decides whether its HUD button is shown
// (vfunc_6), what the button says (vfunc_7..10) and what a click does (vfunc_3: usually a buy / use message box whose
// answer sends packet 0x83).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members whose job is clear but whose name is not.
// smartpushmanager.h keeps its own partial view of CSmartPush (slots 0-6, the same members); it is not merged here
// because the manager unit declares the class factory with a CSmartPush* result.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/client/ms2/smartpushtable.h"

class CMsgBoxData;
class CInteractGatheringObject;
class CHomemadeCubeObject;

// vftable 0x142e3ac50.
class CSmartPush : public ClassObject
{
public:
    CSmartPush();                                               // 0x140dcf0c0
    virtual ~CSmartPush();                                      //  0 0x140dcf140 (??_G 0x140dd7450)
    // slot 1: ClassObject::vfunc_1 (the class name)
    virtual void vfunc_2();                                     //  2 0x140dd7930 per-poll update (empty)
    virtual void vfunc_3();                                     //  3 0x140dcf1a0 button click: the buy message box
    virtual void vfunc_4(int nValue);                           //  4 0x140dcf440 server result: "s_smartpush_active" notice
    virtual void vfunc_5(bool bAccept);                         //  5 0x140dcf590 send packet 0x83 (id, package, 0, accept)
    virtual int vfunc_6();                                      //  6 0x140dcf640 display state: 0 hidden, 1 shown, 2 active
    virtual CStringW vfunc_7();                                 //  7 0x140dcf650 button text
    virtual CStringW vfunc_8();                                 //  8 0x140dcf6a0 button image (the row's imgPath)
    virtual CStringW vfunc_9();                                 //  9 0x140dcf740 message box text
    virtual CStringW vfunc_10();                                // 10 0x140dcf790 sale popup text
    virtual bool vfunc_11();                                    // 11 0x140dcf7e0
    virtual bool vfunc_12();                                    // 12 0x140dcf7f0

    bool FUN_140dcf800(int nResult, const CMsgBoxData& data);   // message box answer: 0 (yes) sends the request

    int m_nId;                                                  // +0x18 CSmartPushData::m_nId
    int m_n1c;                                                  // +0x1c chosen price package (index)
    int m_nState;                                               // +0x20 state last shown on the strip
    int m_pad_24;
    MS2SvrPtr<CSmartPushData> m_data;                           // +0x28 the table row
};
MS2_CHECK_SIZE(CSmartPush, 0x38);
MS2_CHECK_OFFSET(CSmartPush, m_nId, 0x18);
MS2_CHECK_OFFSET(CSmartPush, m_data, 0x28);

// Auto fishing time (vftable 0x142e3acc0, 0x40 bytes).
class CSmartPushAutoFishing : public CSmartPush
{
public:
    static ClassObject* CreateObject();                         // 0x140dcf840
    virtual CStringW vfunc_1();                                 // 0x140dcf8a0
    CSmartPushAutoFishing();                                    // 0x140dcf8f0
    virtual ~CSmartPushAutoFishing();                           // 0x140dcf930
    virtual void vfunc_2();                                     // 0x140dcf960 renew the auto fishing when it ran out
    virtual void vfunc_3();                                     // 0x140dcfd40
    virtual void vfunc_4(int nValue);                           // 0x140dd03e0
    virtual int vfunc_6();                                      // 0x140dd0470
    virtual CStringW vfunc_7();                                 // 0x140dd04e0
    virtual CStringW vfunc_8();                                 // 0x140dd05a0
    virtual CStringW vfunc_10();                                // 0x140dd05f0
    int FUN_140dd06b0();                                        // the package is free (2) or costs meso (0)
    bool FUN_140dd07b0();                                       // the package price can be paid
    bool FUN_140dd0a00(int nResult, const CMsgBoxData& data);   // message box answer

    int m_bActive;                                              // +0x38 the auto fishing buff was on at the last poll
};
MS2_CHECK_SIZE(CSmartPushAutoFishing, 0x40);

// Auto instrument play time (vftable 0x142e3ad30, 0x40 bytes).
class CSmartPushAutoPlayInstrument : public CSmartPush
{
public:
    static ClassObject* CreateObject();                         // 0x140dd0c30
    virtual CStringW vfunc_1();                                 // 0x140dd0c90
    CSmartPushAutoPlayInstrument();                             // 0x140dd0ce0
    virtual ~CSmartPushAutoPlayInstrument();                    // 0x140dd0d20
    virtual void vfunc_2();                                     // 0x140dd0d50
    virtual void vfunc_3();                                     // 0x140dd1100
    virtual void vfunc_4(int nValue);                           // 0x140dd1800
    virtual int vfunc_6();                                      // 0x140dd1830
    virtual CStringW vfunc_7();                                 // 0x140dd18d0
    virtual CStringW vfunc_8();                                 // 0x140dd1990
    virtual CStringW vfunc_10();                                // 0x140dd19e0
    int FUN_140dd1aa0();
    bool FUN_140dd1ba0();
    bool FUN_140dd1df0(int nResult, const CMsgBoxData& data);

    int m_bPlaying;                                             // +0x38 the auto play was on at the last poll
};
MS2_CHECK_SIZE(CSmartPushAutoPlayInstrument, 0x40);

// Safe riding (vftable 0x142e3ada0).
class CSmartPushSafeRiding : public CSmartPush
{
public:
    static ClassObject* CreateObject();                         // 0x140dd2020
    virtual CStringW vfunc_1();                                 // 0x140dd2080
    CSmartPushSafeRiding();                                     // 0x140dd20d0
    virtual ~CSmartPushSafeRiding();                            // 0x140dd2110
    virtual int vfunc_6();                                      // 0x140dd2140
    virtual CStringW vfunc_7();                                 // 0x140dd22a0
    virtual CStringW vfunc_9();                                 // 0x140dd2360
    virtual bool vfunc_12();                                    // 0x140dd2470
};
MS2_CHECK_SIZE(CSmartPushSafeRiding, 0x38);

// Safe riding on water (vftable 0x142e3ae10).
class CSmartPushSafeWaterRiding : public CSmartPush
{
public:
    static ClassObject* CreateObject();                         // 0x140dd24e0
    virtual CStringW vfunc_1();                                 // 0x140dd2540
    CSmartPushSafeWaterRiding();                                // 0x140dd2590
    virtual ~CSmartPushSafeWaterRiding();                       // 0x140dd25d0
    virtual int vfunc_6();                                      // 0x140dd2600
    virtual CStringW vfunc_7();                                 // 0x140dd2790
    virtual CStringW vfunc_9();                                 // 0x140dd2850
};
MS2_CHECK_SIZE(CSmartPushSafeWaterRiding, 0x38);

// Safe riding on water, the toggle form (vftable 0x142e3ae80: one more slot).
class CSmartPushSafeWaterRidingToggle : public CSmartPush
{
public:
    static ClassObject* CreateObject();                         // 0x140dd2960
    virtual CStringW vfunc_1();                                 // 0x140dd29c0
    CSmartPushSafeWaterRidingToggle();                          // 0x140dd2a10
    virtual ~CSmartPushSafeWaterRidingToggle();                 // 0x140dd2a50
    virtual void vfunc_3();                                     // 0x140dd2a80 send packet 0x83 directly
    virtual void vfunc_13();                                    // 13 0x140dd2b20 (empty)
    virtual int vfunc_6();                                      // 0x140dd2b30
    virtual CStringW vfunc_7();                                 // 0x140dd2cc0
    virtual bool vfunc_11();                                    // 0x140dd2d80 true
    virtual void vfunc_4(int nValue);                           // 0x140dd2d90 (empty)
};
MS2_CHECK_SIZE(CSmartPushSafeWaterRidingToggle, 0x38);

// Auto mastery interaction (vftable 0x142e3aef8): the row's content names the mastery ("Gathering", ...).
class CSmartPushAutoInteraction : public CSmartPush
{
public:
    virtual void vfunc_4(int nValue);                           // 0x140dd2da0 "s_mastery_autointeraction_result"
    virtual CStringW vfunc_7();                                 // 0x140dd2f10
    virtual void vfunc_3();                                     // 0x140dd2fc0
    virtual int vfunc_13() = 0;                                 // 13 start the auto interaction
    virtual int vfunc_14() = 0;                                 // 14 the mastery recipe id of the nearby object
    bool FUN_140dd3a70(int nResult, const CMsgBoxData& data);   // message box answer: start the auto interaction
};
MS2_CHECK_SIZE(CSmartPushAutoInteraction, 0x38);

// Gathering / mining on interact objects (vftable 0x142e3af78).
class CSmartPushAutoInteractObject : public CSmartPushAutoInteraction
{
public:
    virtual int vfunc_6();                                      // 0x140dd3cb0
    virtual int vfunc_13();                                     // 0x140dd3d10
    virtual int vfunc_14();                                     // 0x140dd3d50
    CInteractGatheringObject* FUN_140dd3dd0();                  // the nearest gathering object of the row's mastery
};
MS2_CHECK_SIZE(CSmartPushAutoInteractObject, 0x38);

// Breeding / farming on function cubes (vftable 0x142e3aff8).
class CSmartPushAutoFunctionCubeObject : public CSmartPushAutoInteraction
{
public:
    virtual int vfunc_6();                                      // 0x140dd40a0
    virtual int vfunc_13();                                     // 0x140dd4130
    virtual int vfunc_14();                                     // 0x140dd41b0
    CHomemadeCubeObject* FUN_140dd4230();                       // the nearest homemade cube of the row's mastery
};
MS2_CHECK_SIZE(CSmartPushAutoFunctionCubeObject, 0x38);

class CSmartPushAutoGathering : public CSmartPushAutoInteractObject
{
public:
    static ClassObject* CreateObject();                         // 0x140dd44c0
    virtual CStringW vfunc_1();                                 // 0x140dd4520
};
class CSmartPushAutoMining : public CSmartPushAutoInteractObject
{
public:
    static ClassObject* CreateObject();                         // 0x140dd4570
    virtual CStringW vfunc_1();                                 // 0x140dd45d0
};
class CSmartPushAutoBreeding : public CSmartPushAutoFunctionCubeObject
{
public:
    static ClassObject* CreateObject();                         // 0x140dd4620
    virtual CStringW vfunc_1();                                 // 0x140dd4680
};
class CSmartPushAutoFarming : public CSmartPushAutoFunctionCubeObject
{
public:
    static ClassObject* CreateObject();                         // 0x140dd46d0
    virtual CStringW vfunc_1();                                 // 0x140dd4730
};

// The "use a buff item" forms (vftables 0x142e3b278 / 0x142e3b2f8, 0x40 bytes): the button uses the best buff item of
// the bag that carries the special ability m_nAbility.
class CSmartPushAutoInteractObjectBuffItem : public CSmartPushAutoInteractObject
{
public:
    virtual void vfunc_3();                                     // 0x140dd4780
    virtual int vfunc_14();                                     // 0x140dd4b40 the buff item id
    bool FUN_140dd4b70(int nResult, const CMsgBoxData& data);   // message box answer: use the item

    int m_nAbility;                                             // +0x38 set by the derived ctor
};
MS2_CHECK_SIZE(CSmartPushAutoInteractObjectBuffItem, 0x40);

class CSmartPushAutoFunctionCubeObjectBuffItem : public CSmartPushAutoFunctionCubeObject
{
public:
    virtual void vfunc_3();                                     // 0x140dd4c00
    virtual int vfunc_14();                                     // 0x140dd4fc0
    bool FUN_140dd4ff0(int nResult, const CMsgBoxData& data);

    int m_nAbility;                                             // +0x38
};
MS2_CHECK_SIZE(CSmartPushAutoFunctionCubeObjectBuffItem, 0x40);

class CSmartPushAutoGatheringBuff : public CSmartPushAutoInteractObjectBuffItem
{
public:
    CSmartPushAutoGatheringBuff() { m_nAbility = 0x47; }        // 0x140dd6cd0
    static ClassObject* CreateObject();                         // 0x140dd5080
    virtual CStringW vfunc_1();                                 // 0x140dd50e0
};
class CSmartPushAutoMiningBuff : public CSmartPushAutoInteractObjectBuffItem
{
public:
    CSmartPushAutoMiningBuff() { m_nAbility = 0x43; }           // 0x140dd6dd0
    static ClassObject* CreateObject();                         // 0x140dd5130
    virtual CStringW vfunc_1();                                 // 0x140dd5190
};
class CSmartPushAutoBreedingBuff : public CSmartPushAutoFunctionCubeObjectBuffItem
{
public:
    CSmartPushAutoBreedingBuff() { m_nAbility = 0x44; }         // 0x140dd6b90
    static ClassObject* CreateObject();                         // 0x140dd51e0
    virtual CStringW vfunc_1();                                 // 0x140dd5240
};
class CSmartPushAutoFarmingBuff : public CSmartPushAutoFunctionCubeObjectBuffItem
{
public:
    CSmartPushAutoFarmingBuff() { m_nAbility = 0x48; }          // 0x140dd6c00
    static ClassObject* CreateObject();                         // 0x140dd5290
    virtual CStringW vfunc_1();                                 // 0x140dd52f0
};

// The id of the best (highest special ability value) buff item of the bag with special ability nAbility (0: none).
int FUN_140dd5340(int nAbility);
