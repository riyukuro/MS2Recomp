// triggeractioncli.h - the client's cube-trigger script objects, recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13). The unit is `?\triggeractioncli.cpp` (.text$mn 0x140de4d10-0x140dece80, .text$di 0x1400d66e0-0x1400d67b0).
// Header name assumed; class and member names are invented from their use (RTTI gives the class names).
//
// A trigger "state" (TriggerStateCli) has onEnter / onTick / onExit action lists and a list of transitions; a transition
// (TriggerTransitionCli) holds a condition (TriggerConditionCli), the actions run when it fires and the next state's
// name. Actions and conditions are ClassObject-derived (XML attributes name, arg1..arg6). TriggerObject and its
// subclasses (Sound, Mesh, Actor, Rope, Effect, Cube, Camera) are the world objects a trigger drives, created by a
// factory from the entity's FlatModel.
#pragma once

#include <atlcoll.h>
#include <atlstr.h>
#include <vector>
#include <utility>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/cubespawnobject.h"       // Unk_EntRef

namespace egf { class Entity; }

class TriggerConditionCli;
class TriggerTransitionCli;

// Action: <action name="..." arg1="..." ... arg6="..."/>. vftable 0x142e3d1b0 (3 slots), size 0x40.
class TriggerActionCli : public ClassObject
{
public:
    TriggerActionCli();                                         // 0x140de5190
    virtual ~TriggerActionCli();                                // 0x140de5210 (slot 0: ??_G 0x140de5260)
    virtual CStringW GetTypeName();                                 // 0x140de4d10 L"TriggerActionCli"
    virtual void vfunc_2(void* pNode);                          // 0x140de5010 loads name and arg1..arg6

    static MS2Ptr<TriggerActionCli> Create(void* pNode);        // 0x140de4d60
    void SetName(CStringW strName);                             // 0x140de4e30
    void SetArgs(const ATL::CAtlArray<CStringW>& rArgs);        // 0x140de4e80
    CStringW GetName();                                         // 0x140de4eb0
    CStringW GetArg(int n);                                     // 0x140de4f00
    unsigned __int64 GetArgCount();                             // 0x140de4f60
    int GetIntArg0();                                           // 0x140de4f90 (0 unless two or more arguments)
    ATL::CAtlArray<CStringW>* GetArgs();                        // 0x140de4ff0

    ATL::CAtlArray<CStringW> m_args;                            // +0x18
    CStringW m_strName;                                         // +0x38
};
MS2_CHECK_SIZE(TriggerActionCli, 0x40);
MS2_CHECK_OFFSET(TriggerActionCli, m_args, 0x18);
MS2_CHECK_OFFSET(TriggerActionCli, m_strName, 0x38);

// Condition: <condition name="[!]Name" arg1="..." .../>. vftable 0x142e3d2f8, size 0x48.
class TriggerConditionCli : public ClassObject
{
public:
    TriggerConditionCli();                                      // 0x140de5620
    virtual ~TriggerConditionCli();                             // 0x140de5c30 (slot 0: ??_G 0x140de5c80)
    virtual CStringW GetTypeName();                                 // 0x140de55d0 L"TriggerConditionCli"
    virtual void vfunc_2(void* pNode);                          // 0x140de5aa0 loads arg1..arg6

    static MS2Ptr<TriggerConditionCli> Create(void* pNode);     // 0x140de5690
    void SetArgs(const ATL::CAtlArray<CStringW>& rArgs);        // 0x140de5880
    void SetName(CStringW strName);                             // 0x140de58b0
    void SetNot(int bNot);                                      // 0x140de5900
    CStringW GetName();                                         // 0x140de5920
    CStringW GetArg(int n) const;                               // 0x140de5970
    int GetIntArg0();                                           // 0x140de59d0
    unsigned __int64 GetArgCount();                             // 0x140de5a30
    ATL::CAtlArray<CStringW>* GetArgs();                        // 0x140de5a60
    int GetNot();                                               // 0x140de5a80

    CStringW m_strName;                                         // +0x18
    int m_bNot;                                                 // +0x20 name started with '!'
    ATL::CAtlArray<CStringW> m_args;                            // +0x28
};
MS2_CHECK_SIZE(TriggerConditionCli, 0x48);
MS2_CHECK_OFFSET(TriggerConditionCli, m_strName, 0x18);
MS2_CHECK_OFFSET(TriggerConditionCli, m_bNot, 0x20);
MS2_CHECK_OFFSET(TriggerConditionCli, m_args, 0x28);

// A transition of a state. vftable 0x142e3dba0, size 0x50 (CPtred-derived).
class TriggerTransitionCli : public CPtred
{
public:
    TriggerTransitionCli(const MS2Ptr<TriggerConditionCli>& spCond, const ATL::CAtlArray<MS2Ptr<TriggerActionCli> >& rActions,
                         CStringW strTarget);                   // 0x140dec890
    virtual ~TriggerTransitionCli();                            // 0x140dec9a0 (slot 0: ??_G 0x140deca30)

    MS2Ptr<TriggerConditionCli> m_spCond;                       // +0x18
    ATL::CAtlArray<MS2Ptr<TriggerActionCli> > m_actions;        // +0x28 run when the transition fires
    CStringW m_strTarget;                                       // +0x48 name of the next state
};
MS2_CHECK_SIZE(TriggerTransitionCli, 0x50);
MS2_CHECK_OFFSET(TriggerTransitionCli, m_spCond, 0x18);
MS2_CHECK_OFFSET(TriggerTransitionCli, m_actions, 0x28);
MS2_CHECK_OFFSET(TriggerTransitionCli, m_strTarget, 0x48);

// A state of the trigger graph. vftable 0x142e3db40, size 0xb0 (CPtred-derived).
class TriggerStateCli : public CPtred
{
public:
    typedef MS2Ptr<TriggerActionCli> ActionPtr;
    typedef MS2Ptr<TriggerTransitionCli> TransitionPtr;

    explicit TriggerStateCli(void* pOwner);                     // 0x140de93d0
    virtual ~TriggerStateCli();                                 // 0x140deb6d0 (slot 0: ??_G 0x140deb930)

    void Load(void* pNode);                                     // 0x140de9490
    void Save(void* pNode);                                     // 0x140de9600
    bool Validate(int* pnReason);                               // 0x140de9d40 (limits from the config table)
    void CollectIds(std::vector<std::pair<CStringW, int> >& rOut);   // 0x140dea020 (name, id of every action / condition)
    int GetPosX();                                              // 0x140dea360
    int GetPosY();                                              // 0x140dea380
    CStringW GetName();                                         // 0x140dea3a0
    void SetPos(int nX, int nY);                                // 0x140dea3f0
    void SetName(CStringW strName);                             // 0x140dea420
    void AddOnEnter(ActionPtr spAction);                        // 0x140dea470
    void AddTransition(TransitionPtr spTrans);                  // 0x140dea4c0
    ActionPtr GetOnEnter(int n);                                // 0x140dea510
    TransitionPtr GetTransition(int n);                         // 0x140dea570
    unsigned __int64 GetOnEnterCount();                         // 0x140dea5d0
    unsigned __int64 GetTransitionCount();                      // 0x140dea600
    void AddTransition(void* pNode);                            // 0x140dea630 <condition>
    bool LoadActions(void* pNode, ATL::CAtlArray<ActionPtr>& rOut);   // 0x140dea7f0
    void SaveArgs(void* pElem, const ATL::CAtlArray<CStringW>& rArgs);   // 0x140dea8b0

    int m_nPosX;                                                // +0x18 (-1)
    int m_nPosY;                                                // +0x1c (-1)
    CStringW m_strName;                                         // +0x20
    void* m_pOwner;                                             // +0x28
    ATL::CAtlArray<TransitionPtr> m_transitions;                // +0x30
    ATL::CAtlArray<ActionPtr> m_onEnter;                        // +0x50
    ATL::CAtlArray<ActionPtr> m_onTick;                         // +0x70
    ATL::CAtlArray<ActionPtr> m_onExit;                         // +0x90
};
MS2_CHECK_SIZE(TriggerStateCli, 0xb0);
MS2_CHECK_OFFSET(TriggerStateCli, m_strName, 0x20);
MS2_CHECK_OFFSET(TriggerStateCli, m_transitions, 0x30);
MS2_CHECK_OFFSET(TriggerStateCli, m_onEnter, 0x50);
MS2_CHECK_OFFSET(TriggerStateCli, m_onTick, 0x70);
MS2_CHECK_OFFSET(TriggerStateCli, m_onExit, 0x90);

// ---- trigger world objects ----

// The event handed to TriggerObject::vfunc_2: a pointer-sized field and, at +8, an argument block with virtual getters
// (slot 0 and 1 booleans, slot 3 fade in tenths of a second, slot 5 a count, slot 6 a string).
class Unk_TrigArg
{
public:
    virtual char vfunc_0() = 0;
    virtual unsigned char vfunc_1() = 0;
    virtual int vfunc_2() = 0;
    virtual int vfunc_3() = 0;
    virtual int vfunc_4() = 0;
    virtual int vfunc_5() = 0;
    virtual CStringA vfunc_6() = 0;
};
struct Unk_TriggerEvent
{
    void* m_00;
    // the argument block is the polymorphic sub-object at +8
    Unk_TrigArg* Arg() { return reinterpret_cast<Unk_TrigArg*>(reinterpret_cast<char*>(this) + 8); }
};

// A world object driven by a trigger (vftable 0x142e3d650, 5 slots, size 0x28, CPtred-derived).
class TriggerObject : public CPtred
{
public:
    TriggerObject();                                            // 0x140de5dd0
    virtual ~TriggerObject();                                   // 0x140de5e30 (slot 0: ??_G 0x140de8ee0)
    virtual void vfunc_1();                                     // 0x140de6210 (init hook: empty)
    virtual void vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx);   // 0x140de6220 (apply the event: empty)
    virtual void vfunc_3();                                     // 0x140de6240
    virtual void vfunc_4();                                     // 0x140de6250

    bool HasModel(const unsigned& rModelId);                    // 0x140de5e70
    void Init(int nId, Unk_EntRef ent);                         // 0x140de5ef0
    bool Contains(Vector3 pt);                          // 0x140de5f60 point inside the trigger box
    static MS2Ptr<TriggerObject> Create(egf::Entity* pEntity);  // 0x140de6260 (by FlatModel id)

    int m_nId;                                                  // +0x18
    Unk_EntRef m_spEntity;                                      // +0x20
};
MS2_CHECK_SIZE(TriggerObject, 0x28);

class TriggerObjectSound : public TriggerObject
{
public:
    TriggerObjectSound();                                       // 0x140de6760
    virtual ~TriggerObjectSound();                              // 0x140de67a0
    virtual void vfunc_1();                                     // 0x140de6800 kind from property 0xf83bad53
    virtual void vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx);   // 0x140de68f0

    int m_nKind;                                                // +0x28 1 BGM, 2 AMB, 3 effect
    int m_nHandle;                                              // +0x2c sound / effect handle
};
MS2_CHECK_SIZE(TriggerObjectSound, 0x30);

class TriggerObjectMesh : public TriggerObject
{
public:
    TriggerObjectMesh();                                        // 0x140de6d30
    virtual void vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx);   // 0x140de6e00
};
MS2_CHECK_SIZE(TriggerObjectMesh, 0x28);

class TriggerObjectActor : public TriggerObject
{
public:
    TriggerObjectActor();                                       // 0x140de7470
    virtual void vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx);   // 0x140de74b0
};
MS2_CHECK_SIZE(TriggerObjectActor, 0x28);

class TriggerObjectRope : public TriggerObject
{
public:
    TriggerObjectRope();                                        // 0x140de7630
    virtual void vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx);   // 0x140de7670
};
MS2_CHECK_SIZE(TriggerObjectRope, 0x28);

class TriggerObjectEffect : public TriggerObject
{
public:
    TriggerObjectEffect();                                      // 0x140de7960
    virtual ~TriggerObjectEffect();                             // 0x140de79a0
    virtual void vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx);   // 0x140de7a00

    int m_nHandle;                                              // +0x28 effect handle
};
MS2_CHECK_SIZE(TriggerObjectEffect, 0x30);

class TriggerObjectCube : public TriggerObject
{
public:
    TriggerObjectCube();                                        // 0x140de7c90
    virtual void vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx);   // 0x140de7cd0
};
MS2_CHECK_SIZE(TriggerObjectCube, 0x28);

class TriggerObjectCamera : public TriggerObject
{
public:
    TriggerObjectCamera();                                      // 0x140de7d40
    virtual void vfunc_2(Unk_TriggerEvent* pEvent, bool bSkipFx);   // 0x140de7d80
    virtual void vfunc_3();                                     // 0x140de7e00 start the camera
    virtual void vfunc_4();                                     // 0x140de86b0 end the camera
};
MS2_CHECK_SIZE(TriggerObjectCamera, 0x28);
