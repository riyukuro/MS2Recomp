// notifychangebuff.h - the NotifyObject subclasses of the client's notify header (dispatched by name through the
// NotifySystem; vfunc_1 returns the notice name). Recovered with ?\notifychangebuff.cpp (unit_140db46d0: the second
// half of the notify classes, 0x140db46d0-0x140db5c50; the first half is in unit_140da50e0.cpp). Header name assumed from
// the unit name; member names are inferred from use. Classes without a constructor here are built in their callers
// (their vftables are emitted there); only the 12 classes with a constructor in this range own a vftable here.
#pragma once
#include <afx.h>
#include <efd/SmartPointer.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifykeytable.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/notifychangeactivemycoditab.h"

class PCBase;
// A buff record (?\additionalcli.cpp, new(0x78)); only its size and the shared MS2Ptr instances are needed here.
class AdditionalCli : public CPtred
{
public:
    AdditionalCli();                                        // 0x14096bae0
    int m_nCasterId;                                        // +0x18
    int m_pad_1c, m_pad_20, m_pad_24, m_pad_28, m_pad_2c, m_pad_30, m_pad_34, m_pad_38, m_pad_3c;
    void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58; void* m_pad_60; void* m_pad_68; void* m_pad_70;
};
MS2_CHECK_SIZE(AdditionalCli, 0x78);
class Unk_MDamage;
class Unk_SSGNpc;
// The npc class is a large PCBase-derived type recovered with scenestategame.cpp; here only the exe's shared copy / release
// instances (0x140a7b390 / 0x140a7b530) are used.
template <> efd::SmartPointer<Unk_SSGNpc>::SmartPointer(const efd::SmartPointer<Unk_SSGNpc>& spOther);
template <> efd::SmartPointer<Unk_SSGNpc>::~SmartPointer();

class NotifyChangeBuff : public NotifyObject
{
public:
    NotifyChangeBuff(unsigned nId, unsigned short nSubId);   // 0x140db4720
    virtual CStringW vfunc_1();                     // 0x140db46d0
    static ClassObject* CreateObject();             // 0x140db46c0 (returns NULL: no factory)
    unsigned m_nId;                                 // +0x18
    unsigned short m_nSubId;                        // +0x1c
    int m_bAdded;                                   // +0x20
    MS2Ptr<AdditionalCli> m_spCli;                  // +0x28 the buff record
};
MS2_CHECK_SIZE(NotifyChangeBuff, 0x38);

class NotifyFadeInComplete : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db47b0 / 0x140db47a0

class NotifyAddNpc : public NotifyObject
{
public:
    NotifyAddNpc(efd::SmartPointer<Unk_SSGNpc> spNpc);   // 0x140db4860
    virtual CStringW vfunc_1();                     // 0x140db4810
    static ClassObject* CreateObject();             // 0x140db4800 (returns NULL: no factory)
    efd::SmartPointer<Unk_SSGNpc> m_spNpc;          // +0x18
};
MS2_CHECK_SIZE(NotifyAddNpc, 0x20);

class NotifyRemoveNpc : public NotifyObject
{
public:
    NotifyRemoveNpc(efd::SmartPointer<Unk_SSGNpc> spNpc);   // 0x140db4930
    virtual CStringW vfunc_1();                     // 0x140db48e0
    static ClassObject* CreateObject();             // 0x140db48d0 (returns NULL: no factory)
    efd::SmartPointer<Unk_SSGNpc> m_spNpc;          // +0x18
};
MS2_CHECK_SIZE(NotifyRemoveNpc, 0x20);

class NotifyAddInteract : public NotifyObject
{
public:
    NotifyAddInteract(void* pObj);   // 0x140db4a00
    virtual CStringW vfunc_1();                     // 0x140db49b0
    static ClassObject* CreateObject();             // 0x140db49a0 (returns NULL: no factory)
    void* m_pObj;                                   // +0x18 the field object
};
MS2_CHECK_SIZE(NotifyAddInteract, 0x20);

class NotifyAddLiftable : public NotifyObject
{
public:
    NotifyAddLiftable(void* pObj);   // 0x140db4ab0
    virtual CStringW vfunc_1();                     // 0x140db4a60
    static ClassObject* CreateObject();             // 0x140db4a50 (returns NULL: no factory)
    void* m_pObj;                                   // +0x18 the field object
};
MS2_CHECK_SIZE(NotifyAddLiftable, 0x20);

class NotifyAddPortal : public NotifyObject
{
public:
    NotifyAddPortal(void* pObj);   // 0x140db4b60
    virtual CStringW vfunc_1();                     // 0x140db4b10
    static ClassObject* CreateObject();             // 0x140db4b00 (returns NULL: no factory)
    void* m_pObj;                                   // +0x18 the field object
};
MS2_CHECK_SIZE(NotifyAddPortal, 0x20);

class NotifyDamagedMyPC : public NotifyObject
{
public:
    NotifyDamagedMyPC(Unk_MDamage* pDamage);   // 0x140db4c10
    virtual CStringW vfunc_1();                     // 0x140db4bc0
    static ClassObject* CreateObject();             // 0x140db4bb0 (returns NULL: no factory)
    Unk_MDamage* m_pDamage;                         // +0x18
};
MS2_CHECK_SIZE(NotifyDamagedMyPC, 0x20);

class NotifyDebugMode : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db4c70 / 0x140db4c60

class NotifyActiveMyCodiTab : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db4cd0 / 0x140db4cc0


class NotifyDebugState : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db4d90 / 0x140db4d80

class NotifyChangeJob : public NotifyObject
{
public:
    NotifyChangeJob(PCBase* pPc);   // 0x140db4e40
    virtual CStringW vfunc_1();                     // 0x140db4df0
    static ClassObject* CreateObject();             // 0x140db4de0 (returns NULL: no factory)
    PCBase* m_pc;                                   // +0x18 the player the change applies to
};
MS2_CHECK_SIZE(NotifyChangeJob, 0x20);

class NotifyChangeEquipment : public NotifyObject
{
public:
    NotifyChangeEquipment(PCBase* pPc);   // 0x140db4ef0
    virtual CStringW vfunc_1();                     // 0x140db4ea0
    static ClassObject* CreateObject();             // 0x140db4e90 (returns NULL: no factory)
    PCBase* m_pc;                                   // +0x18 the player the change applies to
};
MS2_CHECK_SIZE(NotifyChangeEquipment, 0x20);

class NotifyChangeLevel : public NotifyObject
{
public:
    NotifyChangeLevel(PCBase* pPc);   // 0x140db4fa0
    virtual CStringW vfunc_1();                     // 0x140db4f50
    static ClassObject* CreateObject();             // 0x140db4f40 (returns NULL: no factory)
    PCBase* m_pc;                                   // +0x18 the player the change applies to
};
MS2_CHECK_SIZE(NotifyChangeLevel, 0x20);

class NotifyChangeTitle : public NotifyObject
{
public:
    NotifyChangeTitle(PCBase* pPc);   // 0x140db5050
    virtual CStringW vfunc_1();                     // 0x140db5000
    static ClassObject* CreateObject();             // 0x140db4ff0 (returns NULL: no factory)
    PCBase* m_pc;                                   // +0x18 the player the change applies to
};
MS2_CHECK_SIZE(NotifyChangeTitle, 0x20);

class NotifyClearAchieve : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db50b0 / 0x140db50a0

class NotifyChangePcRidee : public NotifyObject
{
public:
    NotifyChangePcRidee(PCBase* pPc);   // 0x140db5160
    virtual CStringW vfunc_1();                     // 0x140db5110
    static ClassObject* CreateObject();             // 0x140db5100 (returns NULL: no factory)
    PCBase* m_pc;                                   // +0x18 the player the change applies to
};
MS2_CHECK_SIZE(NotifyChangePcRidee, 0x20);

class NotifyOpenDialogByScene : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db51c0 / 0x140db51b0

class NotifyKillPlayer : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db5220 / 0x140db5210

class NotifySurvivalState : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db5280 / 0x140db5270

class NotifySurvivalGameStart : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db52e0 / 0x140db52d0

class NotifySurvivalGameFinish : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db5340 / 0x140db5330

class NotifyDungeonEnterState : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db53a0 / 0x140db5390

// NotifySkillSetMode (0x140db5400 / 0x140db53f0), NotifyShortkeyPage (0x140db5460 / 0x140db5450): placeholder/notifykeytable.h.

class NotifyBlindTarget : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db54c0 / 0x140db54b0

class NotifyChatEmoticonSelected : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db5520 / 0x140db5510

// The ctor (0x141253de0) is inline: ?\gameoptioninputdefault.cpp builds it (and so emits its vftable 0x142ec88f0).
class NotifyChangeGameOptionInput : public NotifyObject
{
public:
    NotifyChangeGameOptionInput(int nOption) : m_nOption(nOption) {}
    virtual CStringW vfunc_1();                                     // 0x140db5580
    static ClassObject* CreateObject();                             // 0x140db5570
    int m_nOption;                                                  // +0x18 the option tab id (9..13)
};

class NotifyChangeUIBuildingCount : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db55e0 / 0x140db55d0

class NotifyChangeEnableFeature : public NotifyObject { public: virtual CStringW vfunc_1(); static ClassObject* CreateObject(); };   // 0x140db5640 / 0x140db5630
