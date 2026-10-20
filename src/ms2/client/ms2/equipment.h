// equipment.h - CEquipment (no vtable, 0x198 bytes, held by value at PC+0xde0; RTTI names it through
// Delegate<void(CAtlList<TPtr<CEquipItem>>&, CEquipment&)> and DelegateImpl<pair<CEquipment*, ...>>): the slots a PC wears
// items in, the set item effects and the special ability totals of the worn items. Also CEquipmentSlot (RTTI, 0x80),
// Equipment::SetEffectInfo (RTTI, 0x40), ReplaceObject (RTTI, 0x28) and NotifyChangeActiveMyCodiTab (RTTI, 0x20).
// Owning unit ?\equipment.cpp (0x1411df590-0x1411ff4c0). Header name assumed; member names are invented (FUN_<va>
// where no evidence names them; the v2525 snapshot's names in the comments). fittingdollpc.h keeps the older view
// Unk_PCEquipSet of the same object for its users.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/intervaltimer.h"
#include "ms2/client/ms2/additionalclilist.h" // AdditionalCliList::StatMap, SAType
#include "ms2/placeholder/cpriortycutting.h"  // Unk_CuttingTarget, IEquipmentCutting
#include <efd/SmartPointer.h>

class PC;
namespace efd { class utf8string; }
class CItem;
class CEquipItem;
class CEquipmentSlotLayerInfo;
class NiNode;
class NiMesh;
class NiAVObject;
class CMsTime;
enum Unk_EquipAttrType { };   // the stat attribute key of m_attrs (35 values, 0..0x22)

// The node / mesh pair a replaced model part is swapped for.
class ReplaceObject : public CPtred
{
public:
    ReplaceObject(efd::SmartPointer<NiNode> spNode, efd::SmartPointer<NiMesh> spMesh);   // 0x1411f71d0
    virtual ~ReplaceObject();                               // 0x1411f7750 (??_G 0x1411f86e0)

    efd::SmartPointer<NiNode> m_spNode;                     // +0x18
    efd::SmartPointer<NiMesh> m_spMesh;                     // +0x20
};
MS2_CHECK_SIZE(ReplaceObject, 0x28);

// One wearing slot (20 per PC, keyed by m_nIndex): the items worn on its 6 layers, whether each layer shows, and the
// mesh parts swapped out of the body (by mesh name).
class CEquipmentSlot : public CPtred
{
public:
    CEquipmentSlot();                                       // 0x1411df590
    virtual ~CEquipmentSlot();                              // 0x1411df670 (??_G 0x1411f8560)

    int m_nIndex;                                                       // +0x18
    ATL::CRBMap<CString, MS2Ptr<ReplaceObject> > m_replaced;            // +0x20 mesh name -> swapped part (block size 10)
    std::vector<MS2Ptr<CEquipItem> > m_items;                           // +0x50 6 layers
    std::vector<int> m_bShown;                                          // +0x68 6 layers
};
MS2_CHECK_SIZE(CEquipmentSlot, 0x80);
MS2_CHECK_OFFSET(CEquipmentSlot, m_replaced, 0x20);
MS2_CHECK_OFFSET(CEquipmentSlot, m_items, 0x50);
MS2_CHECK_OFFSET(CEquipmentSlot, m_bShown, 0x68);

namespace Equipment {
// One applied set item effect (one per layer group 0..2).
class SetEffectInfo : public CPtred
{
public:
    SetEffectInfo();                                        // 0x1411dfc80 (??_G 0x1411f8720)
    bool FUN_1411dfcf0(MS2Ptr<SetEffectInfo> spOther);      // 0x1411dfcf0 IsEqual

    CString m_strName;                                      // +0x18 the effect name
    int m_nEffect;                                          // +0x20 the applied effect handle
    int m_nGroup;                                           // +0x24
    std::vector<__int64> m_uids;                            // +0x28 the uids of the set pieces
};
}
MS2_CHECK_SIZE(Equipment::SetEffectInfo, 0x40);

class CEquipment : public Unk_CuttingTarget
{
public:
    CEquipment(PC* pPC);                                    // 0x1411dfe00
    ~CEquipment();                                          // 0x1411e06e0

    void FUN_1411e0810();                                   // ClearAll
    int FUN_1411e09a0();                                    // IsAllLoaded
    int FUN_1411e0b30();                                    // RefreshModelIfLoaded
    int FUN_1411e0ba0();                                    // RefreshModel
    int FUN_1411e0c00();                                    // 0
    void FUN_1411e0c10();                                   // RefreshModelIfLoaded
    int FUN_1411e0c30(int nItemId);                         // HasItem
    int FUN_1411e0d40(int nItemId);                         // HasItem (valid items only)
    PC* FUN_1411e0ee0();                                    // the owner
    float FUN_1411e0f00(float f);                           // scale by special ability 3
    float FUN_1411e0f50(float f);                           // add special ability 4
    float FUN_1411e0f90(float f);                           // reduce by special ability 0x27
    unsigned FUN_1411e1080(unsigned n);                     // reduce by special ability 0x22
    float FUN_1411e1110(SAType eType);                      // the special ability rate (/ 1000)
    int FUN_1411e1160(SAType eType);                        // the special ability total
    float FUN_1411e1250(int nOption, unsigned nKey);        // an invoke effect option rate
    float FUN_1411e13e0(int nOption, unsigned nKey);        // an invoke effect option count
    MS2Ptr<CEquipItem> FUN_1411e1580(__int64 nUid);         // FindByUid
    MS2Ptr<CEquipItem> FUN_1411e1780(int nSlot, int nLayer);    // FindItem
    MS2Ptr<CEquipItem> FUN_1411e1860(int nSlot, int nSkip, int bCheck);  // FindUsableItem
    MS2Ptr<CEquipItem> FUN_1411e1a50(int nSlot, int bCheck);    // FindEquippableItem
    void FUN_1411e1b80(ATL::CAtlList<MS2Ptr<CEquipItem> >& items) const;          // CollectItems
    void FUN_1411e1ce0(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nLayer);    // CollectItemsAt
    void FUN_1411e1e30(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nSkip);     // CollectItemsExcept
    void FUN_1411e1fc0(std::vector<MS2Ptr<CEquipItem> >& items, int nSkip);       // CollectItemsExcept
    void FUN_1411e2150(std::vector<MS2Ptr<CEquipItem> >& items, int nLayer);      // CollectItemsAt
    void FUN_1411e22c0(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nLayer);    // CollectItemsUpTo
    int FUN_1411e2440(int nLayer);                          // CountItemsAt
    MS2Ptr<CEquipItem> FUN_1411e2610(NiAVObject* pObj, bool bActive, int nLayer, bool bDeep);   // the worn item owning a node
    efd::SmartPointer<NiAVObject> FUN_1411e2a60(__int64 nUid, const CString& strName, bool bDeep);   // an item's node by name
    void FUN_1411e2e40(ATL::CAtlList<MS2Ptr<CEquipItem> >& items);                // CollectFirstActive
    void FUN_1411e3000(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nMaxLayer, int bCheck, bool bForce);   // the shown items
    void FUN_1411e3600(MS2Ptr<CItem> spItem);               // Equip
    void FUN_1411e36e0(MS2Ptr<CEquipItem> spItem);          // Equip
    void FUN_1411e37f0(MS2Ptr<CItem> spItem, __int64 nValue);   // Equip
    void FUN_1411e38e0(MS2Ptr<CItem> spItem);               // RequestLoad
    void FUN_1411e3960(MS2Ptr<CItem> spItem, int nFlag);    // Unequip
    void FUN_1411e3b10(MS2Ptr<CItem> spItem, int nFlag);    // RequestLoad
    void FUN_1411e3bd0(MS2Ptr<CEquipItem> spItem, int nFlag);   // Unequip
    void FUN_1411e3c70(MS2Ptr<CEquipItem> spItem, int nFlag);   // RequestLoad
    void FUN_1411e3d20(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nFlag);     // Unequip
    void FUN_1411e3de0(int bKeepLoaded);                    // UnequipAll
    void FUN_1411e3f80(const ATL::CRBMap<int, int>& keep, int bKeepLoaded);       // UnequipExcept
    void FUN_1411e4150(__int64 nItemUid, int nSlot, int nLayer);   // move an item to another slot
    void FUN_1411e46b0(MS2Ptr<CEquipItem> spItem);          // an item's models were loaded
    void FUN_1411e4b30(MS2Ptr<CEquipItem> spItem);          // an item's models were dropped
    void FUN_1411e5100(MS2Ptr<CEquipItem> spItem);          // the layer expired tag
    int FUN_1411e5280(int nLayer);                          // no shown upper / lower item above the layer
    void FUN_1411e5450(MS2Ptr<CEquipItem> spItem);          // SetExpired
    void FUN_1411e5500(MS2Ptr<CEquipItem> spItem);          // SetInvalid
    void FUN_1411e55b0(MS2Ptr<CEquipItem> spItem);          // SetPCBang
    void FUN_1411e5660(MS2Ptr<CEquipItem> spItem);          // ClearPCBang
    void FUN_1411e56e0(MS2Ptr<CEquipItem> spItem);          // SetVIP
    void FUN_1411e5790(MS2Ptr<CEquipItem> spItem);          // ClearVIP
    void FUN_1411e5810(MS2Ptr<CEquipItem> spItem, const CString& strTag);    // AddTag
    void FUN_1411e58c0(MS2Ptr<CEquipItem> spItem, const CString& strTag);    // RemoveTag
    void FUN_1411e5940(MS2Ptr<CEquipItem> spItem);          // OnTagChanged
    void FUN_1411e5c10();
    void FUN_1411e6ab0();
    void FUN_1411e6b50();                                   // apply the skin decal colours
    void FUN_1411e6e70();                                   // re-tag the shown items and refresh the cutting
    void FUN_1411e7320();                                   // ApplyEquipMaps
    void FUN_1411e7380();
    void FUN_1411e75f0();                                   // m_48 = 1
    void FUN_1411e7610();                                   // m_4c = 1
    void FUN_1411e7640();                                   // m_50 = 1
    void FUN_1411e7660();                                   // m_54 = 1
    void FUN_1411e7680();
    void FUN_1411e76a0();                                   // m_5f = true
    void FUN_1411e76c0();
    void FUN_1411e89d0(int n);                              // slot 32 of the shown items' models
    void FUN_1411e8b60(const CString& strA, const CString& strB, const efd::utf8string& kDefault, float fBlend);
    void FUN_1411e8eb0(const CString& strTag);              // tag the shown items
    void FUN_1411e9020(const CString& strTag);              // untag them
    void FUN_1411e9190(int bShow);                          // show / hide the swapped parts (customize)
    void FUN_1411e8d20(const CString& strName);             // hide the model part (CPriortyCutting)
    int FUN_1411e9530(int nSlot, const CString& strName);    // re-attach the slot's swapped meshes
    int FUN_1411e9760(int nSlot, const CString& strName);    // detach them
    void FUN_1411ea2e0(bool bEnable);                       // SetOptimize
    void FUN_1411ea430(MS2Ptr<CEquipItem> spItem);          // ModelReady
    void FUN_1411ea500(MS2Ptr<CEquipItem> spItem);          // ModelChanged
    void FUN_1411ea320();                                   // drop effect slot 2 of every item
    CString FUN_1411ea5d0(const CString& str);
    void FUN_1411ea620(const CMsTime& kStart, const CMsTime& kEnd);   // set the codi tab period
    bool FUN_1411ea770();                                   // IsLayerActive
    void FUN_1411ea7c0();
    void FUN_1411ea8c0();
    void FUN_1411eaa00(MS2Ptr<Equipment::SetEffectInfo> spInfo);    // ApplySetEffect
    int FUN_1411eacf0();
    int FUN_1411eb3c0();
    int FUN_1411eb550();
    CString FUN_1411eabd0();                                // the set name
    bool FUN_1411eac20();                                   // HasSetName
    void FUN_1411eac40(bool b);
    void FUN_1411ebde0();                                   // Update (500 ms)
    void FUN_1411ebec0(MS2Ptr<CEquipItem> spItem, int nFlag);   // RemoveEquipItem
    void FUN_1411ec190(MS2Ptr<CEquipItem> spItem, int nFlag);   // ApplyEquipItem
    void FUN_1411ec480(bool bForce);                        // RefreshSetEffect
    void FUN_1411ed270();
    void FUN_1411edbb0();
    void FUN_1411ee930();                                   // OnSetItemChanged
    void FUN_1411eeda0();                                   // ResetMeshOptimizer
    void FUN_1411ef740();                                   // Reset
    int FUN_1411ef780(MS2Ptr<CEquipItem> spItem, int nLayer);      // CanEquip
    int FUN_1411ef870(MS2Ptr<CEquipmentSlot> spSlot, int nLayer);  // IsSlotActive
    void FUN_1411ef970();                                   // ClearSetEffects
    void FUN_1411efa00(int nIndex);                         // RemoveSetEffect
    MS2Ptr<Equipment::SetEffectInfo> FUN_1411efaf0(const CString& strName, const std::vector<MS2Ptr<Equipment::SetEffectInfo> >& effects);
    int FUN_1411efb90(const CString& strName, const std::vector<MS2Ptr<Equipment::SetEffectInfo> >& effects);
    void FUN_1411efcb0(unsigned nId, CString strName, bool bInserted);   // the set effect callback

public:
    MS2_LAYOUT_FRIEND;
    int m_00;                                                           // +0x00
    int m_04;                                                           // +0x04
    PC* m_pPC;                                                          // +0x08
    ATL::CRBMap<int, MS2Ptr<CEquipmentSlot> > m_slots;                  // +0x10 20 slots keyed by index
    efd::SmartPointer<IEquipmentCutting> m_spCutting;                   // +0x40 a CPriortyCutting
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    bool m_5c;
    bool m_bOptimize;                                                   // +0x5d
    bool m_5e;
    bool m_5f;
    bool m_bSetDirty;                                                   // +0x60 (no ctor store)
    int m_64;
    ATL::CAtlArray<efd::SmartPointer<NiMesh> > m_meshes68;              // +0x68
    ATL::CAtlArray<efd::SmartPointer<NiMesh> > m_meshes88;              // +0x88
    AdditionalCliList::StatMap m_skillStats;                            // +0xa8 (17, .75, .25, 2.25, 10)
    AdditionalCliList::StatMap m_effectStats;                           // +0xf0
    std::vector<MS2Ptr<Equipment::SetEffectInfo> > m_setEffects;        // +0x138 3 groups
    bool m_bHasSetName;                                                 // +0x150
    CString m_strSetName;                                               // +0x158
    Unk_IntervalTimer m_updateTimer;                                    // +0x160
    std::map<Unk_EquipAttrType, int> m_attrs;                           // +0x168
    std::map<SAType, int> m_abilities;                                  // +0x178
    MS2Ptr<CEquipmentSlotLayerInfo> m_spLayerInfo;                      // +0x188 new CEquipmentSlotLayerInfo(2)
};
MS2_CHECK_SIZE(CEquipment, 0x198);
MS2_CHECK_OFFSET(CEquipment, m_slots, 0x10);
MS2_CHECK_OFFSET(CEquipment, m_spCutting, 0x40);
MS2_CHECK_OFFSET(CEquipment, m_5c, 0x5c);
MS2_CHECK_OFFSET(CEquipment, m_64, 0x64);
MS2_CHECK_OFFSET(CEquipment, m_meshes68, 0x68);
MS2_CHECK_OFFSET(CEquipment, m_skillStats, 0xa8);
MS2_CHECK_OFFSET(CEquipment, m_effectStats, 0xf0);
MS2_CHECK_OFFSET(CEquipment, m_setEffects, 0x138);
MS2_CHECK_OFFSET(CEquipment, m_strSetName, 0x158);
MS2_CHECK_OFFSET(CEquipment, m_attrs, 0x168);
MS2_CHECK_OFFSET(CEquipment, m_spLayerInfo, 0x188);
