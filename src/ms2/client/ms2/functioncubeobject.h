// functioncubeobject.h - the housing "function cube" objects (client\ms2\functioncubeobject.cpp, header name assumed):
// CFunctionCubeObject (a placed cube that does something when used: a sit/interact state machine with cube-state
// sounds and effects) and its subclasses CHomemadeCubeObject, CBreedingCubeObject, CFarmingCubeObject and
// CNurturingCubeObject, the FunctionCubeData they hold, and the CFunctionCubeService that creates them.
// All five objects are CPtred (+0) with the text-key listener CGlobalKeyTextCallback (+0x18, secondary vftable).
#pragma once

#include <afxtempl.h>
#include <atlcoll.h>
#include <map>
#include <list>
#include <efd/ISystemService.h>
#include <efd/Category.h>

#include "ms2/ms2layout.h"
#include <egf/EntityID.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/cbasecollision.h"
#include "ms2/placeholder/cboxcollision.h"           // CBoxCollision (the interaction box)
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/client/ms2/animationcallbackmanager.h"      // CGlobalKeyTextCallback
#include "ms2/client/ms2/cubespawnobject.h"               // Unk_EntRef
#include "ms2/placeholder/cinpacket.h"

namespace efd { class IMessage; }
namespace egf { class EntityChangeMessage; }

class FunctionCubeData;
class Unk_Entity;



// 0x18-byte option block of the data row (FunctionCubeData +0xd0): int 0, short 1 at +4, int 0, float 0, int 0.
struct Unk_FcOptions
{
    Unk_FcOptions();                                              // 0x140708280
    int m_n0;                                                     // +0x00
    short m_n4;                                                   // +0x04
    int m_n8;                                                     // +0x08
    float m_fC;                                                   // +0x0c
    int m_n10;                                                    // +0x10
    int m_n14;                                                    // +0x14
};
MS2_CHECK_SIZE(Unk_FcOptions, 0x18);

// Per-state string lists: the animations (several per state) and the sound of each of the 6 cube states.
typedef ATL::CAtlArray<CString> Unk_FcStrList;
typedef ATL::CAtlArray<Unk_FcStrList> Unk_FcStrListList;

// A text pair + number (FunctionCubeData +0x118): copy ctor 0x14122da50, assign 0x14122df20.
struct Unk_FcSkillText
{
    Unk_FcSkillText();                                            // 0x140708950
    CString m_strA;                                               // +0x00
    CString m_strB;                                               // +0x08
    int m_nValue;                                                 // +0x10
};
MS2_CHECK_SIZE(Unk_FcSkillText, 0x18);

// The object's data row, copied from the cube table row when the object is created. Heap 0x138.
// vftable 0x142ec4d50 (1 slot), scalar deleting dtor 0x14122e2c0, ctor 0x14122d840, dtor 0x14122dbb0.
class FunctionCubeData : public CPtred
{
public:
    FunctionCubeData();                                           // 0x14122d840
    virtual ~FunctionCubeData();                                  // 0x14122dbb0

    int m_nCubeId;                                                // +0x18
    int m_bBuff;                                                  // +0x1c "Buy"-like flag (1 for kind 3/9 with sub 1)
    int m_bLike;                                                  // +0x20
    int m_nKind;                                                  // +0x24
    int m_nSubKind;                                               // +0x28
    int m_nSub;                                                   // +0x2c
    int m_nEffect;                                                // +0x30
    int m_n34;                                                    // +0x34
    Unk_FcStrListList m_anims;                                    // +0x38 per-state animation name lists (6 states)
    Unk_FcStrList m_sounds;                                       // +0x58 per-state sound names (6 states)
    int m_aAnim[3];                                               // +0x78
    int m_n84;                                                    // +0x84
    CString m_strModel;                                           // +0x88
    int m_n90;                                                    // +0x90
    CString m_strStr98;                                           // +0x98
    Unk_StreamPoint m_vA0;                                               // +0xa0
    Unk_StreamPoint m_vAC;                                               // +0xac
    CString m_strB8;                                              // +0xb8
    CString m_strC0;                                              // +0xc0
    CString m_strC8;                                              // +0xc8
    Unk_FcOptions m_opt;                                          // +0xd0
    int m_nE8;                                                    // +0xe8
    int m_nEC;                                                    // +0xec
    int m_nF0;                                                    // +0xf0
    int m_nF4;                                                    // +0xf4
    int m_nF8;                                                    // +0xf8
    int m_nFC;                                                    // +0xfc
    int m_n100;                                                   // +0x100
    int m_n104;                                                   // +0x104
    CString m_str108;                                             // +0x108
    int m_n110;                                                   // +0x110
    Unk_FcSkillText m_skill;                                      // +0x118
    CStringW m_strNotice;                                         // +0x130
};
MS2_CHECK_SIZE(FunctionCubeData, 0x138);

// ---- unit-local views of exe classes this unit calls into ----

// The nurturing pet data of a cube row (class of objectdata.cpp, unrecovered): owner name, then three hash maps.
typedef ATL::CAtlMap<unsigned short, unsigned __int64> Unk_FcMapU64;
MS2_CHECK_SIZE(Unk_FcMapU64, 0x48);
struct Unk_FcMapInt
{
    unsigned char FUN_1405b9580(unsigned short nKey, int* pnValue);       // lookup
    char m_pad[0x48];
};
struct Unk_FcObjData
{
    Unk_FcObjData();                                              // 0x140708840
    ~Unk_FcObjData();                                             // 0x140708d60
    void FUN_140704bd0(const Unk_FcObjData* pSrc);                // copy
    CStringW m_strOwner;                                          // +0x00
    char m_pad_08[0x18];
    Unk_FcMapU64 m_map;                                           // +0x20 level -> experience
    Unk_FcMapInt m_mapNpc;                                        // +0x68 level -> npc id
    char m_pad_b0[0x48];
};
MS2_CHECK_SIZE(Unk_FcObjData, 0xf8);

// The cube table row an object is built from (only the columns the objects copy).
struct Unk_FcRow
{
    int m_n0;                                                     // +0x00
    int m_nCubeId;                                                // +0x04
    int m_nSub;                                                   // +0x08
    int m_nState;                                                 // +0x0c initial state
    int m_nKind;                                                  // +0x10
    int m_nSubKind;                                               // +0x14
    int m_nEffect;                                                // +0x18
    int m_nE8;                                                    // +0x1c
    int m_nEC;                                                    // +0x20
    int m_nF0;                                                    // +0x24
    int m_nF4;                                                    // +0x28
    int m_nF8;                                                    // +0x2c
    int m_n30;                                                    // +0x30
    int m_n84;                                                    // +0x34
    char m_pad_38[8];
    Unk_FcStrList m_anims;                                        // +0x40 one animation name per state
    Unk_FcStrList m_sounds;                                       // +0x60 one sound name per state
    int m_aAnim[3];                                               // +0x80
    char m_pad_8c[0xa4 - 0x8c];
    int m_nA4;                                                    // +0xa4 animation table id (breeding)
    char m_pad_a8[0x108 - 0xa8];
    int m_n108;                                                   // +0x108
    char m_pad_10c[4];
    CString m_strModel;                                           // +0x110
    int m_n118;                                                   // +0x118
    CString m_strStr98;                                           // +0x120
    Unk_StreamPoint m_vA0;                                               // +0x128
    Unk_StreamPoint m_vAC;                                               // +0x134
    CString m_strB8;                                              // +0x140
    CString m_strC0;                                              // +0x148
    CString m_strC8;                                              // +0x150
    Unk_FcOptions m_opt;                                          // +0x158
    int m_n170;                                                   // +0x170
    char m_pad_174[4];
    CString m_str178;                                             // +0x178
    Unk_FcObjData m_objData;                                      // +0x180
    char m_pad_278[8];
    Unk_FcSkillText m_skill;                                      // +0x280
    CStringW m_strNotice;                                         // +0x298
};
MS2_CHECK_OFFSET(Unk_FcRow, m_anims, 0x40);
MS2_CHECK_OFFSET(Unk_FcRow, m_aAnim, 0x80);
MS2_CHECK_OFFSET(Unk_FcRow, m_strModel, 0x110);
MS2_CHECK_OFFSET(Unk_FcRow, m_opt, 0x158);
MS2_CHECK_OFFSET(Unk_FcRow, m_skill, 0x280);
MS2_CHECK_OFFSET(Unk_FcRow, m_strNotice, 0x298);

// Popups the objects own (classes of other units; only the constructors and the setters used here).
class UIBootyPopup : public CPtred
{
public:
    UIBootyPopup();                                               // 0x141031430
    char m_pad_18[0x90 - 0x18];
};
MS2_CHECK_SIZE(UIBootyPopup, 0x90);
class UIUGCCubeNoticePopup : public CPtred
{
public:
    UIUGCCubeNoticePopup();                                       // 0x140fb49b0
    char m_pad_18[0x98 - 0x18];
};
MS2_CHECK_SIZE(UIUGCCubeNoticePopup, 0x98);

// The message a function cube is created from: an embedded sub object at +8 whose slot 3 yields the state.
class Unk_FcStateSrc
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual unsigned short vfunc_2();
    virtual int vfunc_3();                                        // current state
    virtual __int64 vfunc_4();
};
struct Unk_FcMsg
{
    void* m_unk0;                                                 // +0x00
    Unk_FcStateSrc m_src;                                         // +0x08
};

// The state message vfunc_14 reads (FUN_14112e290 = its state field at +0x38).
class Unk_FcStateMsg : public CPtred
{
public:
    int FUN_14112e290();                                          // state
    char m_pad_18[0x20];
    int m_nState;                                                 // +0x38
};

// 0x18-byte sound/effect request (CeRequest-like, 0x78): name, type, then a 0x68 block. See FUN_1411a49c0.
struct Unk_FcSoundReq
{
    CString m_strName;                                            // +0x00
    int m_nType;                                                  // +0x08
    int m_nPad0c;                                                 // +0x0c
    char m_unk[0x68];                                             // +0x10 (constructed by FUN_1409fabf0)
};

// ---- the base class ----
// 0xb0 bytes. vftable 0x142ec4d60 (16 slots), listener vftable 0x142ec4de8 (EndOfSequence overridden).
class CFunctionCubeObject : public CPtred, public CGlobalKeyTextCallback
{
public:
    CFunctionCubeObject();                                        // 0x141225080
    virtual ~CFunctionCubeObject();                               // 0x141225270
    virtual void vfunc_1(Unk_FcMsg* pMsg);                        // 1  0x1412255c0
    virtual int vfunc_2(Unk_Entity* pEntity, const Unk_FcRow* pRow, int nCubeId, __int64 nArg,
        CubeItemInfo* pItem);                                     // 2  0x141225610 set up from a table row
    virtual void vfunc_3();                                       // 3  0x141226300
    virtual void vfunc_4();                                       // 4  0x141226310
    virtual void vfunc_5(float);                                  // 5  0x141226320
    virtual CStringW vfunc_6();                                   // 6  0x141226340 hover text
    virtual CStringW vfunc_7();                                   // 7  0x141226580 "key"
    virtual void vfunc_8(CString str);                            // 8  0x1412265d0 send the use packet
    virtual bool vfunc_9(CString str);                            // 9  0x1412266c0 is this the object with that id
    virtual void vfunc_10(int nState, bool bFlag);                // 10 0x141226730 play a random sound of the state
    virtual void vfunc_11(int nState);                            // 11 0x141226950
    virtual void vfunc_12(int nState, bool bFlag);                // 12 0x141226a90 set the state
    virtual void vfunc_13();                                      // 13 0x14122e7a0
    virtual void vfunc_14(MS2Ptr<Unk_FcStateMsg> sp);       // 14 0x141226b20
    virtual int vfunc_15();                                       // 15 0x141226f30

    // CGlobalKeyTextCallback override (secondary vftable slot 5)
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);           // 0x141226d70

    void FUN_141226b80(CString str);                              // 0x141226b80 set the id
    CString FUN_141226bd0();                                      // 0x141226bd0 the id
    void FUN_141226c20(bool bFlag);                               // 0x141226c20
    int FUN_141226cd0();                                          // 0x141226cd0 item id
    Unk_StreamPoint FUN_141226d00();                                     // 0x141226d00 position property
    // @0x140967140 (inline; COMDAT in actionkeyobject.cpp's range)
    unsigned char FUN_140967140() { return m_bAlt; }
    Unk_EntRef FUN_141226e60();                                   // 0x141226e60 copy of the entity handle
    egf::EntityID FUN_141226eb0();                               // 0x141226eb0 the entity id (or 0)
    MS2Ptr<CBoxCollision> FUN_141226f90();                        // 0x141226f90 refresh the box pose, return it
    void FUN_141227100(int nSound);                               // 0x141227100
    void FUN_1412271c0(int nState);                               // 0x1412271c0
    int FUN_1412271f0();                                          // 0x1412271f0
    int FUN_141227270();                                                   // 0x141227270
    Unk_FcSkillText FUN_1412272b0();                              // 0x1412272b0
    void FUN_141227310();                                         // 0x141227310
    void FUN_141227360();                                         // 0x141227360
    void FUN_1412273b0();                                         // 0x1412273b0
    void FUN_141227780();                                         // 0x141227780
    void FUN_1412277d0(unsigned char bOn);                                 // 0x1412277d0
    void FUN_1412278b0();                                         // 0x1412278b0
    void FUN_141227950();                                         // 0x141227950
    void FUN_141227cd0();                                         // 0x141227cd0
    void FUN_141227dd0(int nSkip);                                // 0x141227dd0
    void FUN_141228060();                                         // 0x141228060
    void FUN_141228100();                                         // 0x141228100
    void FUN_141228200();                                         // 0x141228200
    void FUN_1412282d0();                                         // 0x1412282d0
    void FUN_141228340();                                         // 0x141228340

    // exe members defined elsewhere
    int FUN_140966fc0();                                          // cube kind of the data row
    int FUN_1409674f0();                                          // exe member of another unit
    int FUN_140e5cc00();                                          // exe member of another unit
    __int64 FUN_140e5cbf0();                                      // exe member of another unit
    int FUN_14112e110();                                          // item id
    int FUN_14122e6d0();                                          // 0x14122e6d0
    int FUN_14122e710();                                          // 0x14122e710
    int FUN_141236a60();                                          // 0x141236a60 m_bLike
    unsigned char FUN_141236b10();                                // 0x141236b10 m_b21

public:
    MS2_LAYOUT_FRIEND;
    char m_bAlt;                                                  // +0x20
    char m_b21;                                                   // +0x21
    CString m_strId;                                              // +0x28
    Unk_EntRef m_ent;                                             // +0x30 the cube entity
    int m_nState;                                                 // +0x38
    int m_n3c;                                                    // +0x3c (not initialised by the ctor)
    int m_nArg;                                                   // +0x40
    __int64 m_nArg2;                                              // +0x48
    MS2Ptr<CBoxCollision> m_spBox;                                // +0x50 the interaction box
    int m_n60;                                                    // +0x60
    MS2Ptr<CubeItemInfo> m_spItem;                                // +0x68
    MS2Ptr<FunctionCubeData> m_spData;                            // +0x78
    int m_nSoundHandle;                                           // +0x88
    unsigned char m_bFxOn;                                                 // +0x8c
    MS2Ptr<UIBootyPopup> m_spBooty;                               // +0x90
    MS2Ptr<UIUGCCubeNoticePopup> m_spNotice;                      // +0xa0
};
MS2_CHECK_SIZE(CFunctionCubeObject, 0xb0);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_ent, 0x30);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_spBox, 0x50);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_spItem, 0x68);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_spData, 0x78);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_spBooty, 0x90);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_spNotice, 0xa0);

// ---- Homemade / Breeding / Farming (gathering cubes) ----
// Homemade: vftable 0x142ec4e20 (18 slots: 16 + vfunc_16 / vfunc_17), listener vftable 0x142ec4eb8.
class CHomemadeCubeObject : public CFunctionCubeObject
{
public:
    CHomemadeCubeObject();                                        // 0x1412283b0
    virtual ~CHomemadeCubeObject();                               // 0x141228430
    virtual void vfunc_3();                                       // 3  0x1412284c0
    virtual void vfunc_4();                                       // 4  0x1412284d0
    virtual void vfunc_5(float);                                  // 5  0x141228620
    virtual CStringW vfunc_6();                                   // 6  0x1412286d0
    virtual CStringW vfunc_7();                                   // 7  0x141228720
    virtual void vfunc_8(CString str);                            // 8  0x141228810 start the gathering
    virtual void vfunc_11(int nState);                            // 11 0x141228e40
    virtual void vfunc_13();                                      // 13 0x141228640
    virtual int vfunc_15();                                       // 15 0x141228680
    virtual int vfunc_16();                                       // 16 0x141228fa0 mastery kind
    virtual int vfunc_17();                                       // 17 0x1412291e0 mastery is enough

    void FUN_141228fb0(__int64 n);                                // 0x141228fb0
    __int64 FUN_141228fe0();                                      // 0x141228fe0
    int FUN_141229000(bool bWatch);                               // 0x141229000
    int FUN_141229080();                                          // 0x141229080
    int FUN_141229120();                                          // 0x141229120
    int FUN_140e5cc00();                                          // exe member of another unit
    __int64 FUN_140e5cbf0();                                      // exe member of another unit

public:
    MS2_LAYOUT_FRIEND;
    __int64 m_nB0;                                                // +0xb0
    __int64 m_nB8;                                                // +0xb8
    int m_nSoundHandle2;                                          // +0xc0
    char m_pad_c4[4];
};
MS2_CHECK_SIZE(CHomemadeCubeObject, 0xc8);

// Breeding: vftable 0x142ec4ef0.
class CBreedingCubeObject : public CHomemadeCubeObject
{
public:
    CBreedingCubeObject();                                        // 0x1412291f0
    virtual ~CBreedingCubeObject();                               // 0x141229270
    virtual int vfunc_2(Unk_Entity* pEntity, const Unk_FcRow* pRow, int nCubeId, __int64 nArg,
        CubeItemInfo* pItem);                                     // 2  0x141229360
    virtual void vfunc_3();                                       // 3  0x1412299f0
    virtual void vfunc_5(float fArg);                             // 5  0x141229b70
    virtual CStringW vfunc_6();                                   // 6  0x141229c10
    virtual void vfunc_10(int nState, bool bFlag);                // 10 0x14122a370
    virtual int vfunc_16();                                       // 16 0x14122a350 (5)
    virtual int vfunc_17();                                       // 17 0x14122a670

public:
    MS2_LAYOUT_FRIEND;
    CString m_strAnim;                                            // +0xc8
    Unk_EntRef m_entPet;                                          // +0xd0 the pet entity
};
MS2_CHECK_SIZE(CBreedingCubeObject, 0xd8);

// Farming: vftable 0x142ec4fc0.
class CFarmingCubeObject : public CHomemadeCubeObject
{
public:
    CFarmingCubeObject();                                         // 0x14122a6e0
    virtual ~CFarmingCubeObject();                                // 0x14122a730
    virtual int vfunc_2(Unk_Entity* pEntity, const Unk_FcRow* pRow, int nCubeId, __int64 nArg,
        CubeItemInfo* pItem);                                     // 2  0x14122a770
    virtual CStringW vfunc_6();                                   // 6  0x14122a900
    virtual int vfunc_16();                                       // 16 0x14122b040 (6)
    virtual int vfunc_17();                                       // 17 0x14122b060
};
MS2_CHECK_SIZE(CFarmingCubeObject, 0xc8);

// Nurturing: vftable 0x142ec5090 (derives the base directly), listener vftable 0x142ec5118.
class CNurturingCubeObject : public CFunctionCubeObject
{
public:
    CNurturingCubeObject();                                       // 0x14122b0d0
    virtual ~CNurturingCubeObject();                              // 0x14122b1f0
    virtual void vfunc_1(Unk_FcMsg* pMsg);                        // 1  0x14122b2e0
    virtual int vfunc_2(Unk_Entity* pEntity, const Unk_FcRow* pRow, int nCubeId, __int64 nArg,
        CubeItemInfo* pItem);                                     // 2  0x14122b6e0
    virtual void vfunc_3();                                       // 3  0x14122b870
    virtual void vfunc_5(float fZ);                               // 5  0x14122b9f0
    virtual CStringW vfunc_6();                                   // 6  0x14122bab0
    virtual CStringW vfunc_7();                                   // 7  0x14122bbe0
    virtual void vfunc_8(CString str);                            // 8  0x14122bc30
    virtual void vfunc_14(MS2Ptr<Unk_FcStateMsg> sp);       // 14 0x14122b530

    int FUN_14122bda0();                                          // 0x14122bda0 may the player use it
    int FUN_14122c340();                                          // 0x14122c340 is it the player's own
    int FUN_14122c410();                                          // 0x14122c410 npc id of the level
    void FUN_14122c460(int nMode);                                // 0x14122c460 success notice
    void FUN_14122c7b0(int nError);                               // 0x14122c7b0 error notice
    efd::SmartPointer<CubeSpawnObject> GetValue();                           // 0x14122cab0 (copy of the pet pointer)
    __int64 FUN_14122cb00();                                      // 0x14122cb00
    unsigned short FUN_14122cb20();                               // 0x14122cb20
    unsigned short FUN_14122cb40();                               // 0x14122cb40
    unsigned FUN_14122cb60();                                     // 0x14122cb60
    __int64 FUN_14122cb80();                                      // 0x14122cb80
    __int64 FUN_14122cba0();                                      // 0x14122cba0
    void FUN_14122cbc0(unsigned short nLevel, Unk_EntRef ent);    // 0x14122cbc0 spawn the pet
    void FUN_14122ce80(unsigned short nLevel);                    // 0x14122ce80 respawn on a level change
    int FUN_14122d190();                                          // 0x14122d190 is the timer over
    int FUN_14122d200();                                          // 0x14122d200 action id
    void FUN_14122d2a0(const CStringW& str);                      // 0x14122d2a0 notice once

public:
    MS2_LAYOUT_FRIEND;
    int m_bNear;                                                  // +0xb0
    int m_bNotice;                                                // +0xb4 a notice may be shown
    __int64 m_nTime;                                              // +0xb8 timestamp of the last feeding
    __int64 m_nC0;                                                // +0xc0
    char m_pad_c8[8];
    Unk_EntRef m_entPet;                                          // +0xd0
    efd::SmartPointer<CubeSpawnObject> m_spPet;                   // +0xd8
    __int64 m_nE0;                                                // +0xe0
    __int64 m_nE8;                                                // +0xe8
    unsigned short m_nLevel;                                      // +0xf0
    unsigned short m_nMaxLevel;                                   // +0xf2
    unsigned m_nF4;                                               // +0xf4
    Unk_FcObjData m_obj;                                          // +0xf8
};
MS2_CHECK_SIZE(CNurturingCubeObject, 0x1f0);
MS2_CHECK_OFFSET(CNurturingCubeObject, m_entPet, 0xd0);
MS2_CHECK_OFFSET(CNurturingCubeObject, m_spPet, 0xd8);
MS2_CHECK_OFFSET(CNurturingCubeObject, m_obj, 0xf8);

// ---- the service ----
// Smart-pointer targets seen through the cube service: a magic effect tag (its id at +0x2c) and a collision area.
class Unk_FcTag : public CPtred
{
public:
    char m_pad_18[0x14];
    int m_nOwner;                                                 // +0x2c
};
class Unk_FcArea : public CPtred
{
public:
    int m_n18;                                                    // +0x18 (read by the tick check)
    char m_pad_1c[0x24];
};

class CFunctionCubeService;
template <class T> class TSingleton;
template <> class TSingleton<CFunctionCubeService>
{
public:
    TSingleton();                                   // 0x141234920 (inline, in the cpp)
    virtual ~TSingleton() { s_instance = 0; }       // 0x141234ea0
    static CFunctionCubeService* s_instance;        // 0x143ab3918
};

// Client side of the housing function cubes (service id 0x06100019): it keeps every placed cube object by its id
// string, forwards the cube packets to them and ticks them. Pointer-to-member names are invented from their use.
class CFunctionCubeService : public efd::ISystemService, public TSingleton<CFunctionCubeService>
{
    EE_DECLARE_CLASS1(CFunctionCubeService, 0x06100019, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    typedef ATL::CRBMap<CString, MS2Ptr<CFunctionCubeObject> > CubeMap;
    typedef ATL::CRBMap<MS2Ptr<Unk_FcTag>, MS2Ptr<Unk_FcArea> > TagMap;

    CFunctionCubeService();                         // 0x14122ef20
    virtual ~CFunctionCubeService();                // 0x14122f000
    virtual const char* GetDisplayName() const;     // 0x14122f0f0
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x141230670
    virtual efd::AsyncResult OnInit();              // 0x1412306b0
    virtual efd::AsyncResult OnTick();              // 0x141230950
    virtual efd::AsyncResult OnShutdown();          // 0x1412309e0

    void FUN_14122f110(const egf::EntityChangeMessage* pMsg, efd::Category cat);    // entity removed (8254)
    void FUN_14122f240(const efd::IMessage* pMsg, efd::Category cat);
    void FUN_14122f270(CInPacket* pPacket);         // the cube packet dispatcher
    void FUN_141230310(CInPacket* pPacket);
    void FUN_1412304e0(unsigned nA, unsigned nB, int nKind);
    void FUN_141230580(CString strId, MS2Ptr<CFunctionCubeObject> spObject);
    MS2Ptr<CFunctionCubeObject> FUN_141230c00(CString strId);
    void FUN_141230c90(MS2Ptr<CFunctionCubeObject> spObject);
    void FUN_141230df0(CString strId);
    MS2Ptr<CFunctionCubeObject> FUN_141230f60(Unk_StreamPoint pt, float fRange, __int64 nOwner);
    MS2Ptr<CFunctionCubeObject> FUN_141231200(Unk_StreamPoint pt, float fRange, __int64 nOwner, int nKind);
    void FUN_1412314e0(Unk_StreamPoint pt, ATL::CAtlArray<MS2Ptr<CFunctionCubeObject> >& aOut);
    void FUN_1412316a0(MS2Ptr<Unk_FcArea> spArea, MS2Ptr<Unk_FcTag> spTag);
    void FUN_141231730();
    void FUN_141231be0();
    void FUN_141231ce0(int nKey, CString str, int bAppend);
    int FUN_141231eb0(int nKey, int* pnItem);
    void FUN_141232260();
    void FUN_141232330(int nItem, float fValue);
    int FUN_141232430(int nItem, __int64 nOwner);
    void FUN_141232660(ATL::CAtlArray<MS2Ptr<CHomemadeCubeObject> >& aOut, __int64 nOwner);
    void FUN_141232810(ATL::CAtlArray<MS2Ptr<CNurturingCubeObject> >& aOut);

    efd::Category m_catGlobal;                                    // +0x28 the message service's unique category
    CubeMap m_mapCubes;                                           // +0x30 cube id -> object
    CubeMap m_mapPending;                                         // +0x60 "<a>_<b>" -> object created from the table
    TagMap m_mapTags;                                             // +0x90
    std::map<int, std::list<CString> > m_mapStrings;              // +0xc0 cube item id -> object ids
};
MS2_CHECK_SIZE(CFunctionCubeService, 0xd0);
MS2_CHECK_OFFSET(CFunctionCubeService, m_catGlobal, 0x28);
MS2_CHECK_OFFSET(CFunctionCubeService, m_mapCubes, 0x30);
MS2_CHECK_OFFSET(CFunctionCubeService, m_mapPending, 0x60);
MS2_CHECK_OFFSET(CFunctionCubeService, m_mapTags, 0x90);
MS2_CHECK_OFFSET(CFunctionCubeService, m_mapStrings, 0xc0);
