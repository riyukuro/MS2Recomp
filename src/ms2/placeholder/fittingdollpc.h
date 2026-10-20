#pragma once
#include "ms2/client/ms2/pcbase.h"
#include <NiFixedString.h>
#include "ms2/client/ms2/costumemanager.h"   // MS2Ptr<CostumeManager> at PC+0x1130
#include "ms2/placeholder/pcgemequip.h"     // PCGemEquip at PC+0x1078
#include <NiColor.h>
#include <set>
class CItem;
class NiAVObject;
class NiColor;
class CEquipmentSlotLayerInfo;   // MS2Ptr<T> (cequipmentslotlayerinfo.h)
class Unk_PCWaterGunInfo;   // MS2Ptr<T> (?\watergunbattleinfo.cpp)
struct Unk_StreamPoint;
struct Unk_CharEquip;   // tcreatecharinfo.h (0xc)

// Heap-only views. PC derives PCBase (ctor 14164dfd0), and FittingDollPC
// derives PC (ctor 14121b350). No constructors or vftables are emitted here.
// The additional PC virtual interface is not used by the cube guide wrappers;
// calls through these pointers use the inherited GameObject slots only.
// PC vftable 0x142f4ae28 (147 slots). Slots 124..132 are the first PC-introduced virtuals (PCBase ends at 123);
// types from the base bodies' register homing and the AvatarPC/ClonePC/MyPC overrides (sb2, work/sb2/pc_slots.txt).
// Out-of-line in the unrecovered PC unit: symbols-manual rows. Slots 133..146 appended by sb4 (work/sb4/pc_slots_133.txt:
// prologue homing + PC/ClonePC/MyPC/FittingDollPC/PortraitPC overrides). ClonePC (clonepc.h) adds 147..152.
class Unk_PCArg125;   // MS2Ptr<T> by value (MyPC override destroys it with 0x1409f74e0)
class Unk_PCActionTimer;   // CPtred-derived, defined by the user unit (avatarpc.cpp)
class Unk_PCSkillTree;   // MS2Ptr<T> at +0x1110 (copied out by FUN_1409eee00; defined by the user unit)
class CEquipItem;
class CMsTime;
class CSetItemManager;   // csetitemmanager.h
class AdditionalCli;
struct Unk_PCEquipSet
{
    Unk_PCEquipSet(PC* pOwner);                             // 0x1411dfe00
    ~Unk_PCEquipSet();                                      // 0x1411e06e0
    MS2Ptr<CEquipItem> FUN_1411e1860(int nSlot, int nKind, int n);    // a worn item of the slot (customize.cpp)
    void FUN_1411e22c0(ATL::CAtlList<MS2Ptr<CEquipItem> >& out, int nKind);   // the worn items of a kind (customize.cpp)
    void FUN_1411e5c10(); void FUN_1411e6ab0(); void FUN_1411e75f0();   // refresh the look (customize.cpp)
    MS2Ptr<CEquipItem> FUN_1411e1780(int nSlot, int nKind); MS2Ptr<CEquipItem> FUN_1411e1580(__int64 nItemUid); MS2Ptr<CEquipItem> FUN_1411e1a50(int nSlot, int nKind); void FUN_1411e4150(__int64 nItemUid, unsigned char nSlot, int nKind); void FUN_1411ea620(const CMsTime& kStart, const CMsTime& kEnd); void FUN_1411ea7c0(); void FUN_1411e7660();
    void FUN_1411e7640();                                   // the look changed (flag 50; additionalcli.cpp)
    void* FUN_1411e2440(int nKind);                         // the worn items of an equip layer, NULL when none (uiclosetdialog.cpp)
    int FUN_1411e0ba0();                                    // RefreshModel (returns 1; equipitem.cpp)
    float FUN_1411e0f90(float fDistance);                   // the knock-back distance after the equipment's resistances
    void FUN_1411e3d20(ATL::CAtlList<MS2Ptr<CEquipItem> >& aItems, int n);   // unequip a list of items (equipitem.cpp)
    void FUN_1411e46b0(MS2Ptr<CEquipItem> spItem);          // an item's models were loaded (by value; equipitem.cpp)
    void FUN_1411e4b30(MS2Ptr<CEquipItem> spItem);          // an item's models were dropped (by value; equipitem.cpp)
    void FUN_1411e7380();                                   // kind 0x12 items changed (equipitem.cpp)
    int FUN_1411e09a0();                                    // the equipment is ready (uibeautyshopdevdialog.cpp)
    void FUN_1411e89d0(int n);                              // battle stance changed (PC::vfunc_66)
    void FUN_1411e8eb0(const CString& strReason);           // hide the equip models for a reason (CEquipment)
    void FUN_1411e9020(const CString& strReason);           // show them again (CEquipment)
    void FUN_1411e38e0(MS2Ptr<CItem> spItem);               // equip (quick-equip config; PC::vfunc_127)
    void FUN_1411e3600(MS2Ptr<CItem> spItem);               // equip (PC::vfunc_127)
    void FUN_1411e3b10(MS2Ptr<CItem> spItem, int n);        // unequip (quick-equip config; PC::vfunc_128)
    void FUN_1411e3960(MS2Ptr<CItem> spItem, int n);        // unequip (PC::vfunc_128)
    void FUN_1411e37f0(MS2Ptr<CItem> spItem, __int64 n);
    void FUN_1411e3bd0(MS2Ptr<CEquipItem> spItem, int n);
    int FUN_1411e0c30(int nItemId);                         // the item id is worn (uibeautyshopdevdialog.cpp)
    void FUN_1411e7610();                                   // mark dirty (CEquipment, equipment.h)
    CString FUN_1411eabd0();                                // the set name (CEquipment)
    bool FUN_1411eac20();                                   // the set name is a named one (CEquipment)
    float FUN_1411e0f00(float f);                           // scale by special ability 3 (CEquipment)
    void FUN_1411e8b60(const CString& strA, const CString& strB, const efd::utf8string& kDefault, float fBlend);   // (CEquipment)
    float FUN_1411e1110(int nSpecial);                      // the special ability rate (CEquipment)
    int FUN_1411e1160(int nSpecial);                        // the special ability total (CEquipment)
    void FUN_1411e1ce0(ATL::CAtlList<MS2Ptr<CEquipItem> >& items, int nLayer);   // the equip items of a layer (CEquipment)
    void FUN_1411e76c0(double fTime);                       // Update (CEquipment)
    bool FUN_1411ea770();                                   // IsLayerActive (CEquipment)
    void FUN_1411e6b50();                                   // apply the skin decal colours (CEquipment)
    void FUN_1411e1b80(ATL::CAtlList<MS2Ptr<CEquipItem> >& items);   // all the equip items (CEquipment)
    float FUN_1411e1250(int nOption, unsigned nKey);        // an invoke effect option rate (CEquipment)
    float FUN_1411e13e0(int nOption, unsigned nKey);        // an invoke effect option count (CEquipment)
    void FUN_1411e7680();                                   // refresh (CEquipment)
    MS2Ptr<CEquipmentSlotLayerInfo> GetTitle();            // 0x140d29440 the codi (outfit) tab period (defined in unit_140d1ae30)
    unsigned char unknown0[0x188];
    MS2Ptr<CEquipmentSlotLayerInfo> m_spTitle;              // +0x188 (new CEquipmentSlotLayerInfo(2))
};   // FUN_1411e1780 (itemgem.cpp): the worn item of an equip slot   // the PC's equipment holder (+0xde0); methods FUN_1411e3de0/e3000/e22c0
class Unk_PCD88;      // +0xd88 target (ClonePC::vfunc_12 releases it via FUN_140a35900)

class Unk_HsInfo;     // MS2Ptr<T> by value (defined by uihideandseekresultdialog.cpp)
// PC member types (w539). Complete types only in pc.cpp; the MS2Ptr members need only declarations.
class CEquipModel;     // equipmodel.h (the attach-effect models of the worn weapons)
class CWeaponAction;   // +0xd70 the action prefix row of the worn weapon pair (weaponactiontable.h)
class Unk_PCLinkFD8;  // +0xfd8 (create 0x141993100, release 0x141993180)
class CGuideObject;   // +0x1228 [3] the cube guide objects (cubecraft_1.h; FUN_1416623d0 sets them)
class JobSystemCli;
class CubeItemInfo;
class CSkillTierOptionManager;
class CStatPointManager;
class CoupleEffectSystem;
class WaterGunBattleInfo;
class CTailEffectObject;
class CTailEffectObjectFromAdditional;
class CRandomTargetEffect;
namespace HideAndSeek { class Info; }
// PC +0xf78: four item handles (ctor 0x140c86000 = vector ctor + FUN_140c86060; implicit dtor 0x141666a60).
// The cooldown methods are Unk_PCItemCooldowns' (scenestategame.cpp); FUN_1416561c0 hands this object out as one.
struct Unk_PCItemSlots4
{
    Unk_PCItemSlots4();                                     // 0x140c86000
    void FUN_140c86060();
    MS2Ptr<CItem> m_aItems[4];
};
MS2_CHECK_SIZE(Unk_PCItemSlots4, 0x40);
MS2_CHECK_SIZE(Unk_PCEquipSet, 0x198);   // ctor 0x1411dfe00, dtor 0x1411e06e0 (PC +0xde0..+0xf78)
// The player's interact mode (PC +0x1240): while active it picks the kind of object to interact with (actionkeyobject.cpp).
// Defined here because PC::FUN_140967420 copies the MS2Ptr inline.
class Unk_PCInteractMode : public CPtred
{
public:
    bool FUN_140743550();                                   // active
    void FUN_140743a10(CInPacket& packet);                  // decode (scenestategame OnAddUser)
    int FUN_140743710();                                    // the target kind
    bool FUN_140743590();                                   // CPvPInfo: mode 1
    bool FUN_140743690();                                   // CPvPInfo: mode 10
};
class PC : public PCBase {
    EE_DECLARE_CLASS1(PC, 0x06200003, PCBase);   // ClassInfo 0x143ae2e20 (setup COMDAT 0x1409f8020 in avatarpc; sb4)
public:
    PC();                                                   // 0x14164dfd0 (called by ClonePC::ClonePC)
    virtual ~PC();
    virtual void vfunc_9(void* p);                          // 9 0x141651300 (PCBase 0x14166b470)
    virtual void vfunc_12();                                // 12 0x1416515a0 (PCBase 0x14166b810)
    virtual void vfunc_14();                                // 14 0x141651bb0 (PCBase 0x14166b880)
    virtual int vfunc_10();                                 // 10 0x141651370 (PCBase 0x14166b550)
    virtual void vfunc_53(float f);                         // 53 0x141660240
    virtual void vfunc_59(int nState, StateData* pData, int nSub, int bForce);   // 59 0x1416537d0
    virtual int vfunc_116();                                // 116 0x14165ebe0 (PCBase's is pure)
    // slots AvatarPC inherits from here (declared so the vftable resolves to the exe slots)
    virtual void vfunc_107(MS2Ptr<CDamageRecord> spRecord, float fScale); // 107 0x14165f720
    virtual void vfunc_113(void* p);                        // 113 0x14165fec0
    virtual void vfunc_114(void*);                          // 114 0x14165c4e0
    virtual float vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut);// 115 0x14165e500
    virtual int vfunc_118(const NiPoint3& kPos, float* pDist, CString* pName);   // 118 0x141655a30 (PCBase signature)
    virtual void vfunc_120(MS2Ptr<RideOnAction> spAction);  // 120 0x1416561e0 (by value)
    virtual void vfunc_121(MS2Ptr<RideOffAction> spAction);   // 121 0x1416562d0
    virtual int vfunc_122(void* p);                         // 122 0x14165f5d0
    virtual void vfunc_15();                                // 15 0x141651d00
    virtual void vfunc_16();                                // 16 0x141651d40
    virtual void vfunc_23(int n);                           // 23 0x14165c320
    virtual void vfunc_24(int nFlags);                      // 24 0x141662160 the visibility flags
    virtual void vfunc_31(bool b);                          // 31 0x141652030
    virtual void vfunc_33(void* a, void* b);                // 33 0x141652080
    virtual void vfunc_34(void* p);                         // 34 0x1416529f0
    virtual void vfunc_35(void* p);                         // 35 0x141652e20
    virtual void vfunc_40(float a, float b, float c, float d);   // 40 0x14165d8d0
    virtual void vfunc_42(float f, bool b);                 // 42 0x14165dad0
    virtual void vfunc_44(void* p);                         // 44 0x14165dd80
    virtual void vfunc_52(double fTime);                    // 52 0x141651d80
    virtual int vfunc_57();                                 // 57 0x141653ce0
    virtual CString vfunc_60();                             // 60 0x141658a30
    virtual int vfunc_61();                                 // 61 0x141658b80
    virtual bool vfunc_62();                                // 62 0x141658c40
    virtual void vfunc_66(int n);                           // 66 0x1416544f0
    virtual int vfunc_69();                                 // 69 0x14165f480
    virtual void vfunc_71(MS2Ptr<Unk_PCBaseFxSet> spSet);   // 71 0x14165ff00
    virtual void vfunc_72();                                // 72 0x14165ff80
    virtual void vfunc_74(__int64 nCur, __int64 nMax);      // 74 0x141656af0
    virtual CStringW vfunc_77();                            // 77 0x141656c70
    virtual int vfunc_78();                                 // 78 0x1416578f0
    virtual MS2Ptr<Unk_PCBaseComp_a58> vfunc_80();          // 80 0x141656db0
    virtual MS2Ptr<Unk_PCBaseComp_a68> vfunc_81();          // 81 0x141656f80
    virtual MS2Ptr<Unk_PCBaseComp_a98> vfunc_84();          // 84 0x1416572b0
    virtual MS2Ptr<Unk_PCBaseComp_a88> vfunc_83();          // 83 0x141657670
    virtual MS2Ptr<Unk_PCBaseComp_ab8> vfunc_86();          // 86 0x141657470
    virtual void vfunc_49();                                // 49 0x141660e00
    virtual int vfunc_64();                                 // 64 0x141654840 (mypc vftable, w97)
    virtual MS2Ptr<Unk_PCBaseComp_a78> vfunc_82();          // 82 0x141657100
    virtual MS2Ptr<Unk_PCBaseComp_aa8> vfunc_85();          // 85 0x1416573b0
    virtual MS2Ptr<Unk_PCBaseComp_ac8> vfunc_87();          // 87 0x1416575b0
    virtual void vfunc_90(void* p);                         // 90 0x141657910 the stats packet
    virtual void vfunc_91(void* p);                         // 91 0x141657c40 = vfunc_90
    virtual float vfunc_95();                               // 95 0x14165e4a0 (PCBase 0x141671620)
    virtual int vfunc_99(int n);                            // 99 0x141654850
    virtual int vfunc_124(int a, int b);                    // 124 0x141653840 (1/0; homes edx and r8d)
    virtual void vfunc_125(MS2Ptr<Unk_PCArg125> p);         // 125 0x141654900 (MyPC 0x141522d40)
    virtual void vfunc_126(MS2Ptr<Unk_PCArg125> p, int n);  // 126 0x141655230 (n == 0: p.get() + 0x430)
    virtual void vfunc_127(CItem* pItem, int n);            // 127 0x1416563c0 (MS2Ptr<CItem>(pItem) into +0xde0)
    virtual void vfunc_128(CItem* pItem, int n);            // 128 0x1416564a0
    virtual void vfunc_129(const CStringW& str);            // 129 0x141656ba0: +0xdc8 = str
    virtual void vfunc_130(CStringA str);                   // 130 0x141656c00: +0xdd0 = str (by value)
    virtual void vfunc_131(short n);                        // 131 0x141657820: word +0xddc = n
    virtual int vfunc_132(CItem* pItem, int n, bool b);     // 132 0x141657e20
    virtual int vfunc_133(CItem* pItem, bool b);            // 133 0x141657dc0: vfunc_132(pItem, pItem->FUN_140527a20(), b)
    virtual CStringW vfunc_134();                           // 134 0x141658cd0 (hidden return; PC: L"")
    virtual void vfunc_135(int a, int b, void* p);          // 135 0x141659450
    virtual void vfunc_136(const CString& strModel, const efd::utf8string& kAnim, float fBlend);   // 136 0x14165c240 play an animation on the equipment
    virtual int vfunc_137();                                // 137 0x14165d6d0
    virtual void vfunc_138(NiAVObject* pRoot, int n, const Unk_CharEquip* pEquip);  // 138 0x14165f050
    virtual void vfunc_139();                               // 139 0x14165efa0
    virtual void vfunc_140(int n);                          // 140 0x1416600c0
    virtual int vfunc_141();                                // 141 0x141660100
    virtual void vfunc_142();                               // 142 0x141660740 (AvatarPC 0x1409f52e0)
    virtual void vfunc_143();                               // 143 0x141660920 (ClonePC/PortraitPC override)
    virtual void vfunc_144();                               // 144 0x141660f80
    virtual int vfunc_145();                                // 145 0x141661be0: return 1 (ClonePC: 0)
    virtual bool vfunc_146();                               // 146 0x141662e50
    // PC TU members (w539)
    void FUN_141653740(int nTargetId, int nCasterId, int nKind, int nFlag);   // an effect event of a target
    JobSystemCli* FUN_1416546d0();                          // the job system
    int FUN_141654730();
    int FUN_141654760();
    void FUN_141654790();                                   // the job changed (reload, notify)
    MS2Ptr<CEquipItem> FUN_141655c90(int nSlot);            // the worn item of a slot, kind 0
    MS2Ptr<CEquipItem> FUN_141655cf0(int nSlot);            // kind 1
    MS2Ptr<CEquipItem> FUN_141655d50(int nSlot);            // kind 5
    MS2Ptr<CEquipItem> FUN_141655db0(int nSlot);            // kind 4
    void FUN_141656580(MS2Ptr<CItem> spItem, __int64 n);
    void FUN_1416565f0(MS2Ptr<CItem> spItem, int n);
    void FUN_141656660(MS2Ptr<CEquipItem> spItem, int n);
    void FUN_1416566d0(int n);                              // +0xd68
    int FUN_1416566f0();                                    // +0xd68
    void FUN_141656710();                                   // refresh the stance and the buffs after an equip change
    int FUN_141656750();                                    // the equipment is ready
    int FUN_1416538d0(CDamageRecord* pRecord);              // the hit grabs this onto the attacker (state 0x2b; no hit reaction)
    int FUN_141653f00();                                    // rebuild the weapon stance from the worn weapons (changed: 1)
    MS2Ptr<CEquipItem> FUN_141655ee0(int nSlot, bool bKind0Only);   // the worn weapon (slot 4/5): kind 0, or the first of kinds 0..2 holding one
    int FUN_14165c570();                                    // the normal attack skill of the weapon stance
    void FUN_14165c720(unsigned int nSkillId, short nLevel);         // preload a skill and its combo chain
    int FUN_14165c090(efd::Point3 kPos);                    // there is ground ahead of kPos and room to stand there (by value)
    void FUN_14165cac0();                                   // create the tomb stone entity (+0xfc8)
    int FUN_14165a540();                                    // step onto the cube under / next to the actor
    int FUN_14165b500(int nKind);                           // climb: 1 onto a wall ahead, 2 down the side of the cube below
    MS2Ptr<class CGemPetSkin> FUN_14165df00();              // the worn pet skin gem (feature 0x6c)
    MS2Ptr<class CGemSwim> FUN_14165e1b0();                 // the worn swim gem (feature 0x68)
    void FUN_141660ee0();                                   // the equipment finished loading (once: +0xd40)
    void FUN_1416599b0();                                   // drop the followed entity (+0xdb0) beyond 70 units
    egf::Entity* FUN_141659af0(int nKind);                  // the ladder / rope entity at hand (models 0xbadf0a13, 0xc13e30c8)
    egf::Entity* FUN_141659b80(int nKind, unsigned int nModel, float fHeight);   // the nearest entity of a model in reach
    egf::Entity* FUN_141659f80();                           // snap onto the nearest 0xd116ab46 entity (within 500)
    void FUN_141660c20(const CAtlArray<MS2Ptr<CItem> >& aItems, bool bQuick);   // equip the items (bQuick: FUN_1411e38e0)
    void FUN_1416611b0(CString strKey);                     // take the profile image key if it names this character
    CString FUN_14165e010(int nAction);                     // the swim effect of an action (0x30 idle, 0x32 dash, else run)
    bool FUN_14165e2a0(efd::utf8string& kOut, int nAction); // the swim gem's animation of an action (false: none)
    void FUN_141659250(int nValue, CubeItemInfo* pInfo);   // recreate the cube craft controller for the mode
    __int64 FUN_141656ad0();                                // +0xdc0
    int FUN_14165ef30();                                    // this is the local player
    MS2Ptr<Unk_PCLinkFD8> FUN_141657730();                  // the +0xfd8 record, created on demand (none while busy)
    int FUN_141661970();                                    // busy
    BOOL FUN_141661e40(int* pnEnchant, int* pnGrade);       // the best enchant level / grade of the worn items (name tag)
    void FUN_141657c80(bool bEnable);                       // apply the attach effects of the equipment
    bool FUN_141658150(ATL::CAtlArray<CEquipModel*>& kEffects, ATL::CAtlArray<CString>& kNodes, int bPrimary);   // collect the weapons' attach effects and their nodes
    CStringW& FUN_141656be0();                              // +0xdc8
    CStringA& FUN_141656c50();                              // +0xdd0
    CStringW& FUN_141656d90();                              // +0x1030 the displayed name
    // non-virtual members called by scenestategame.cpp (w86)
    MS2Ptr<CItem> FUN_141655b80(__int64 nItemUid);          // 0x141655b80 an owned item by uid
    MS2Ptr<CEquipItem> FUN_141655e10(int nSlot);            // 0x141655e10 the worn item of a slot (customize.cpp)
    int FUN_1416569b0(CItem* pItem);                        // 0x1416569b0 the equip slot of an item (customize.cpp)
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 nItemUid);     // 0x141655c30 a worn item by uid
    MS2Ptr<CEquipItem> FUN_141655e80(int nSlot, int nKind); // 0x141655e80 the worn item of a slot (scenestategame 0x7b)
    void FUN_1416642c0(bool b);                             // 0x1416642c0 +0x1224 (scenestategame 0x79 mode 6)
    void FUN_141661c70(int n);                              // 0x141661c70 +0x10f4, refreshes the name tag (scenestategame 0xa8 mode 1)
    Unk_PCEquipSet* FUN_1416561a0();                        // 0x1416561a0 &m_kEquipDE0
    int FUN_141654700();                                    // 0x141654700 the job
    int FUN_141658f30();                                    // 0x141658f30 PC bang premium (item use check, unit_140d1ae30)
    unsigned FUN_141662de0();                               // 0x141662de0 the VIP grade (item use check, unit_140d1ae30)
    int FUN_141658e60();                                    // 0x141658e60 the gender (uiitemcreatedialog.cpp)
    int FUN_1416639e0();                                    // 0x1416639e0 the selected super world chat item id (uisidepopuptalk_2.cpp)
    int FUN_141662eb0(class CItem* pItem);                  // 0x141662eb0 the item may be used (mypc)
    class Unk_PCItemCooldowns* FUN_1416561c0();             // 0x1416561c0
    int FUN_1416595d0();                                    // the cube craft mode (scenestategame 0x1417235a0)
    class Unk_PCCubeCraft* FUN_141659700();                 // the cube craft controller
    void FUN_14165f1f0(int nA, int nB);                     // scenestategame 0x69 (cube weapon held / dropped)
    class Unk_MyPCEmotion* FUN_14165f100();                 // the playing emotion (actionkeyobject.cpp)
    // @0x140967420
    MS2Ptr<Unk_PCInteractMode> FUN_140967420() { return m_spInteractMode; }   // COMDAT in actionkeyobject.cpp's range
    Unk_StreamPoint FUN_1416767d0();                        // PCBase member: the position (the ride's when riding; actionkeyobject.cpp)
    void FUN_141660000(__int64 nValue);
    void FUN_141661ba0(int n);                              // scenestategame packet (state reset flag)
    void FUN_141661dc0(unsigned short nA, int nB);          // scenestategame packet 0xb1
    void FUN_141658ed0(unsigned char n);                    // scenestategame packet 0xb2
    void FUN_141662d60(__int64 nValue);                     // scenestategame packet 0xe6
    int FUN_141661aa0();                                    // scenestategame packet 0x33 (pvp flag)
    void FUN_141661a60(int n);                              // scenestategame packet 0x33
    void FUN_1416619d0(unsigned int nEnd);                  // scenestategame packet 0x33 (+0x10e8; the main player info timer)
    void FUN_141661370(int a, int b, int c);                // scenestategame packet 0x34 (also on MyPC)
    void FUN_1416591e0(int nSlot, const NiColor& kColor);   // +0xd98 + nSlot*0xc = kColor (scenestategame 0x30)
    const NiColor& FUN_141659220(int nSlot);                // the colour at +0xd98 + nSlot*0xc
    void FUN_141656780();                                   // re-apply the appearance (scenestategame 0x30)
    void FUN_141659000(int n);                              // 0x141659000 (an enchant-effect item was equipped; equipitem.cpp)
    float FUN_14165eb80();                                  // 0x14165eb80 the animation blend of state 0x2f (equipitem.cpp)
    CString FUN_141658d20();                                // 0x141658d20 the animation name prefix (equipitem.cpp)
    __int64 FUN_141658eb0();                                // +0xfe8
    unsigned char FUN_141658f10();                          // the PC bang grade
    unsigned char FUN_141658fa0();                          // the PC bang bonus flags
    void FUN_141658fc0(const egf::EntityID& kId);           // +0xdb0
    int FUN_1416595b0();                                    // the cube craft mode
    int FUN_141659610();                                    // cube craft mode 1
    int FUN_141659650();                                    // cube craft mode 2
    int FUN_141659690();                                    // the cube craft controller moves a cube
    int FUN_1416596d0();                                    // cube craft mode 1
    void FUN_141659720();                                   // tick the cube craft controller's second guide
    void FUN_141659770(bool b, const CString& strKind);     // (empty in the client; vfunc_71 / vfunc_72 pass "Emotion")
    void FUN_14165ebb0(float f);                            // +0x1180 the animation speed scale
    int FUN_14165ffe0();                                    // +0x11cc
    int FUN_141660030();                                    // +0x11e8 is a time of the current month
    void FUN_14165f0b0(MS2Ptr<CItem> spItem);               // +0x1040 the held item
    void FUN_14165f130(int n);                              // +0x1050
    int FUN_14165f150();                                    // +0x1050 an item is held
    void FUN_14165f170();                                   // put the held item away (packet 0x37/0x12)
    void FUN_141661820(int nSkillId, short nLevel, std::set<unsigned int>& kVisited, std::set<unsigned int>& kFound);   // (empty in the client)
    void FUN_141661840(int nSkillId, short nLevel);         // (empty in the client)
    int FUN_141661860();                                    // +0x1000
    unsigned int FUN_141661a80();                           // +0x10e8 the end tick
    void FUN_141661ac0();                                   // reset +0x10ec / +0x10e8 once the end tick passed
    int FUN_141661bc0();                                    // +0xff0 the party id
    int FUN_141661c50();                                    // +0x10f4 the title
    void FUN_1416623d0(efd::SmartPointer<CGuideObject> spGuide, int nIndex);   // +0x1228[nIndex] (0..2)
    CGuideObject* FUN_141662440(int nIndex);                // +0x1228[nIndex] (0..2)
    int FUN_141662490(int nIndex);                          // a guide is set
    class CConstructionGuideObject* FUN_1416625b0();        // guide 0
    class CFishingGuideObject* FUN_1416625e0();             // guide 1
    class CSkillMagicControlGuide* FUN_141662610();         // guide 2
    __int64 FUN_141662670();                                // +0x1140
    int FUN_1416626b0();                                    // +0x1148, reset on a new day of +0x1140
    int FUN_141662730();                                    // +0x114c
    int FUN_141662830();                                    // +0x1184 the last bank call time
    int FUN_141662870();                                    // +0x1188
    float FUN_1416628b0(int nOption, unsigned nKey);        // an invoke effect option rate of the equipment
    float FUN_1416628f0(int nOption, unsigned nKey);        // an invoke effect option count of the equipment
    float FUN_141662930(int nSpecial);                      // a special ability rate of the equipment
    int FUN_141662980(int nSpecial);                        // a special ability total of the equipment
    void FUN_141662da0(int n);                              // +0x1198 (refreshes the equipment)
    __int64 FUN_141662e90();                                // +0x1190 the VIP end time
    int FUN_141663040();                                    // +0xd80
    int FUN_141663080();                                    // +0x119c
    int FUN_1416630c0();                                    // +0x11a0
    void FUN_1416630e0(unsigned int nId);                   // attach a ClonePC id (+0x11a8)
    void FUN_141663120(unsigned int nId);                   // detach a ClonePC id
    void FUN_141663400(MS2Ptr<CItem> spItem);               // +0x11b8
    MS2Ptr<CItem> FUN_141663450();                          // +0x11b8
    void FUN_141663500(int nObjectId);                      // the couple effect: an object
    void FUN_141663620();                                   // start the couple effect (or remember it)
    void FUN_1416636e0(MS2Ptr<CItem> spItem, int nGemId);   // create the couple effect of a couple item (itemgem.cpp)
    void FUN_141663680();                                   // stop the couple effect
    void FUN_141663870();                                   // drop the couple effect
    CStringW FUN_1416638b0();                               // the couple effect name
    int FUN_141663940();                                    // the couple type (0: none)
    __int64 FUN_141663990();                                // the couple partner id (0: none)
    int FUN_141663a20();                                    // +0x11f4, reset when +0x11f8 expired
    int FUN_141663ac0();                                    // +0x11f8 is unset or expired
    short FUN_141663b50();                                  // +0x120c
    void FUN_141663b70(unsigned int nId);                   // add an effect id (+0x1210)
    void FUN_141663bb0(unsigned int nId);                   // remove an effect id
    void FUN_141663be0(const NiFixedString& kSequence, float fSpeed, const NiFixedString& kTextKey);   // play a sequence on the effects
    void FUN_141663d00(efd::Point3 kDir);                   // turn the effects
    void FUN_141663e20(int nCount, int nTailId);            // the tail effect length / row
    void FUN_141663ea0();                                   // stop the tail effect
    bool FUN_1416642a0();                                   // +0x1224
    void FUN_141659790(const CString& strAnim);             // play an animation on the weapons' attach models
    int FUN_14165c1b0(int* pnId, CString* pstrName, float fRange);   // the nearest holdable target (0: FindHoldTargetRange)
    MS2Ptr<Unk_PCD88> FUN_14165c2d0();                      // +0xd88
    MS2Ptr<CWeaponAction> FUN_14165c520();                  // +0xd70
    Unk_PCActionTimer* FUN_14165ca20();                     // +0xfc8
    Unk_PCActionTimer* FUN_14165ca50();                     // +0xfc8 while active
    void FUN_141660d50();                                   // the default collision box
    void FUN_141660df0();                                   // (empty)
    void FUN_1416615f0(float fDelta);                       // the +0x1054 timer tick
    void FUN_1416616a0(unsigned int nDelay);                // blink the model alpha (faster nDelay ms after +0x1064)
    void FUN_141661880(int bEnable, int nValue, const CubeItemInfo* pInfo);   // enter / leave the cube mode (+0x1000 / +0x1008)
    void FUN_14165d300(int nA, int nB, int nC);             // PCBase member (pcbase.cpp; scenestategame 0x5d)
    void FUN_14165d550(int bHide);                          // the tomb stone breaks (bHide: hide its entity)
    void FUN_1416629d0(Unk_StreamPoint kPos, Unk_StreamPoint kRot);   // scenestategame 0x141721a30
    MS2Ptr<Unk_PCWaterGunInfo> FUN_141664250();             // the water gun battle info (+0x1260)
    void FUN_141662640(__int64 nValue);                      // scenestategame 0x1417340f0
    void FUN_141662690(int nValue);
    void FUN_141662710(int nValue);
    void FUN_141661330(const CStringW& strName);             // set the displayed name (scenestategame)
    class Unk_MyPCEquip* FUN_14165f460();                   // the equipment (mypc.cpp, w97)
    MS2Ptr<CSetItemManager> FUN_1411f9310();                // 0x1411f9310 m_spSetItems (a pc.h inline first emitted by equipment.cpp)
    void FUN_141670540(int nIndex, int nType, __int64 nValue);   // PCBase: set a stat value (mypc.cpp, w97)
    // scenestategame OnAddUser (0x14170fda0); argument kinds from the callee prologues
    void FUN_141656aa0(__int64 nAccountId);
    void FUN_141656a50(__int64 nCharId);
    void FUN_141658e40(int nGender);
    void FUN_141658e80(__int64 nValue);
    void FUN_14174a340(int n) { m_n11c8 = n; }              // @0x14174a340
    void FUN_14165ffc0(int n);
    void FUN_141663a00(int n);
    void FUN_141663a70(int n);
    void FUN_141663a90(__int64 n);
    void FUN_141663b10(short n);
    void FUN_141663060(int n);
    void FUN_1416630a0(int n);
    void FUN_141662790(int nIndex, int nValue);
    unsigned int FUN_141662750(int nIndex);                 // 0x141662750 mastery exp (+0x1150[nIndex], 0..11)
    int FUN_1416627d0(int nIndex);                          // 0x1416627d0 mastery grade of the exp
    void FUN_141660fc0(CString str);
    void FUN_14165f090(int n);
    void FUN_141653d10(MS2Ptr<CItem> spItem);
    void FUN_141661b20(CInPacket& packet);
    void FUN_141661c00(CInPacket& packet);
    void FUN_141661d40(CInPacket& packet);
    void FUN_141663150(CInPacket& packet);
    void FUN_141662e30(int n);
    void FUN_1416634a0(__int64 nCharId);
    void FUN_141663550();
    void FUN_14165c970(void* p);                            // notify the action timer (+0xfc8)
    void FUN_1416624e0(int nIndex);                         // remove the cube guide nIndex
    void FUN_141662850(__int64 nValue);
    void FUN_141662890(__int64 nValue);
    MS2Ptr<Unk_HsInfo> FUN_141664200();                     // the hide and seek record (scenestategame 0x12b)
    MS2Ptr<Unk_PCSkillTree> FUN_1409eee00();                // copy of the skill tree at +0x1110 (scenestategame 0x49)
    CString FUN_1416612e0();                                // the profile image key (wedding partner icons, unit_140fdab30)
    // additionalcli.cpp (the buff list)
    void FUN_141663ef0(AdditionalCli* pCli);                // a tail effect record was added
    void FUN_1416640d0(AdditionalCli* pCli);                // a tail effect record was modified
    void FUN_141664160(AdditionalCli* pCli);                // a tail effect record was removed
    bool FUN_141660120();                                   // the stun state is blocked
    void FUN_141658f70(unsigned char nFlags);               // add PC bang bonus flags (+0xff9)
    // @0x140978540
    void FUN_140978540() { m_nFF9 = 0; }                    // clear the PC bang bonus flags
    // @0x140976c10
    int FUN_140976c10() { return m_n1058 != 0; }
    // @0x1409763e0
    MS2Ptr<CostumeManager> FUN_1409763e0() { return m_spCostume; }
    // @0x141c04f70
    unsigned char FUN_141c04f70() { return m_b1204; }       // faded out (?\worldservice.cpp#6)
    // @0x141bfaec0
    void FUN_141bfaec0(bool bFaded) { m_b1204 = bFaded; }    // (COMDAT in worldservice.cpp)
    // @0x141bfed80
    int FUN_141bfed80() { return m_n1200; }                 // fade delay in ms (COMDAT in worldservice.cpp)
    // 0xd40..0x12e0, from the ctor 0x14164dfd0 / dtor 0x141650b10 member sequences (w539; v2525 PC.h agrees). The MS2Ptr
    // handle types are the exe's per-type instantiations (their COMDATs live in the PC unit's tail).
    bool m_bD40;                                            // +0xd40 (ctor: true)
    ATL::CAtlArray<MS2Ptr<CItem> > m_kListD48;              // +0xd48 owned items (FUN_141653d10 adds; MyPC/PortraitPC read)
    int m_nD68;                                             // +0xd68 (FUN_1416566f0 / FUN_1416566d0)
    MS2Ptr<CWeaponAction> m_spWeaponActionD70;              // +0xd70 the worn weapon pair's action row (FUN_141653f00 rebuilds it)
    int m_nD80;                                             // +0xd80 (FUN_141663040)
    MS2Ptr<Unk_PCD88> m_spD88;                              // +0xd88
    NiColor m_colorD98[2];                                  // +0xd98 (FUN_141659220 / FUN_1416591e0)
    egf::EntityID m_entityDB0;                              // +0xdb0 (FUN_141658fc0)
    __int64 m_nCharIdDB8;                                   // +0xdb8 (FUN_141656a50 / FUN_141656a80)
    __int64 m_nAccountIdDC0;                                // +0xdc0 (FUN_141656aa0 / FUN_141656ad0)
    CStringW m_strNameDC8;                                  // +0xdc8 (vfunc_129)
    CStringA m_strDD0;                                      // +0xdd0 (vfunc_130)
    int m_nGenderDD8;                                       // +0xdd8 (FUN_141658e40 / FUN_141658e60)
    unsigned short m_nLevelDDC;                             // +0xddc the level (vfunc_131 / vfunc_78; ctor: 1)
    Unk_PCEquipSet m_kEquipDE0;                             // +0xde0 equip holder (FUN_1411e3de0)
    Unk_PCItemSlots4 m_kItemsF78;                           // +0xf78 (FUN_1416561c0)
    MS2Ptr<JobSystemCli> m_spJobFB8;                        // +0xfb8 (FUN_1416546d0)
    MS2Ptr<Unk_PCActionTimer> m_spFC8;                      // +0xfc8
    MS2Ptr<Unk_PCLinkFD8> m_spFD8;                          // +0xfd8 (FUN_141657730)
    __int64 m_nFE8;                                         // +0xfe8 (FUN_141658e80 / FUN_141658eb0)
    int m_nFF0;                                             // +0xff0
    int m_nFF4;                                             // +0xff4
    unsigned char m_nFF8;                                   // +0xff8 PC bang grade (FUN_141658ed0 / FUN_141658f10)
    unsigned char m_nFF9;                                   // +0xff9 PC bang bonus flags (FUN_141658f70)
    int m_nCubeModeFFC;                                     // +0xffc the cube craft mode (FUN_1416595b0 / FUN_1416595d0)
    int m_n1000;                                            // +0x1000
    MS2Ptr<CubeItemInfo> m_spCube1008;                      // +0x1008
    int m_n1018;                                            // +0x1018
    class Unk_PCCubeCraft* m_pCubeCraft;                    // +0x1020 (FUN_141659700; cube craft mode only)
    CStringA m_str1028;                                     // +0x1028 the profile image key (FUN_1416612e0)
    CStringW m_strName1030;                                 // +0x1030 the displayed name (FUN_141661330)
    int m_n1038;                                            // +0x1038 (FUN_14165f090)
    MS2Ptr<CItem> m_spItem1040;                             // +0x1040 (FUN_14165f0b0 / FUN_14165f100)
    int m_n1050;                                            // +0x1050 (FUN_14165f130 / FUN_14165f150; not set by the ctor)
    int m_n1054;                                            // +0x1054
    int m_n1058;                                            // +0x1058 (non-zero: buffs never resist knock-back)
    int m_n105c;                                            // +0x105c
    int m_n1060;                                            // +0x1060 an effect id (the dtor removes it)
    int m_n1064;                                            // +0x1064
    unsigned int m_n1068;                                   // +0x1068 the blink phase (FUN_1416616a0, 0..1000)
    unsigned int m_n106c;                                   // +0x106c the last blink tick
    bool m_b1070;                                           // +0x1070 the blink state (not set by the ctor)
    char m_pad_1071[7];
    PCGemEquip m_kGemEquip1078;                             // +0x1078 (FUN_14165f460)
    unsigned int m_n10e8;                                   // +0x10e8
    int m_n10ec;                                            // +0x10ec
    int m_n10f0;                                            // +0x10f0
    int m_n10f4;                                            // +0x10f4 the title (FUN_141661c70)
    short m_n10f8;                                          // +0x10f8
    int m_n10fc;                                            // +0x10fc
    MS2Ptr<CSetItemManager> m_spSetItems;                   // +0x1100 the set item bonuses (FUN_1411f9310)
    MS2Ptr<CSkillTierOptionManager> m_spSkillTier1110;      // +0x1110 (FUN_1409eee00)
    MS2Ptr<CStatPointManager> m_spStatPoint1120;            // +0x1120
    MS2Ptr<CostumeManager> m_spCostume;                     // +0x1130 the costume sets (additionalcli.cpp)
    __int64 m_n1140;                                        // +0x1140
    int m_n1148;                                            // +0x1148
    int m_n114c;                                            // +0x114c
    unsigned int m_aMastery1150[12];                        // +0x1150 mastery exp (FUN_141662750)
    float m_f1180;                                          // +0x1180 (ctor: 1.0)
    int m_n1184;                                            // +0x1184
    int m_n1188;                                            // +0x1188
    __int64 m_n1190;                                        // +0x1190
    int m_n1198;                                            // +0x1198
    int m_n119c;                                            // +0x119c
    int m_n11a0;                                            // +0x11a0
    std::set<unsigned int> m_set11a8;                       // +0x11a8 ClonePC ids (the dtor detaches them)
    MS2Ptr<CItem> m_spItem11b8;                             // +0x11b8
    int m_n11c8;                                            // +0x11c8 (FUN_14174a340)
    int m_n11cc;                                            // +0x11cc
    int m_n11d0;                                            // +0x11d0
    MS2Ptr<CoupleEffectSystem> m_spCouple11d8;              // +0x11d8
    __int64 m_n11e8;                                        // +0x11e8
    int m_n11f0;                                            // +0x11f0
    int m_n11f4;                                            // +0x11f4
    __int64 m_n11f8;                                        // +0x11f8
    int m_n1200;                                            // +0x1200 fade delay in ms (WorldService 0x141bd7390)
    unsigned char m_b1204;                                  // +0x1204 faded out (WorldService 0x141bd7390, set by 0x141bfaec0)
    int m_n1208;                                            // +0x1208
    short m_n120c;                                          // +0x120c
    std::set<unsigned int> m_set1210;                       // +0x1210
    int m_n1220;                                            // +0x1220
    bool m_b1224;                                           // +0x1224 (FUN_1416642c0)
    efd::SmartPointer<CGuideObject> m_spGuide1228[3];       // +0x1228 the cube guides (FUN_1416623d0)
    MS2Ptr<Unk_PCInteractMode> m_spInteractMode;            // +0x1240 (a CPvPInfo; actionkeyobject.cpp)
    MS2Ptr<HideAndSeek::Info> m_spHideAndSeek1250;          // +0x1250
    MS2Ptr<WaterGunBattleInfo> m_spWaterGun1260;            // +0x1260
    MS2Ptr<CTailEffectObject> m_spTailEffect1270;           // +0x1270
    ATL::CAtlMap<int, MS2Ptr<CTailEffectObjectFromAdditional> > m_mapTail1280;   // +0x1280 additional-effect tails (a separate MS2Ptr instantiation from +0x1270's)
    MS2Ptr<CRandomTargetEffect> m_spRandomTarget12c8;       // +0x12c8
    efd::SmartPointer<NiAVObject> m_sp12d8;                 // +0x12d8 (init 0x14097eba0(p,0), as PCBase +0xbe8)
};
MS2_CHECK_OFFSET(PC, m_kListD48, 0xd48);
MS2_CHECK_OFFSET(PC, m_spWeaponActionD70, 0xd70);
MS2_CHECK_OFFSET(PC, m_colorD98, 0xd98);
MS2_CHECK_OFFSET(PC, m_strNameDC8, 0xdc8);
MS2_CHECK_OFFSET(PC, m_kItemsF78, 0xf78);
MS2_CHECK_OFFSET(PC, m_spJobFB8, 0xfb8);
MS2_CHECK_OFFSET(PC, m_nFE8, 0xfe8);
MS2_CHECK_OFFSET(PC, m_spCube1008, 0x1008);
MS2_CHECK_OFFSET(PC, m_str1028, 0x1028);
MS2_CHECK_OFFSET(PC, m_spItem1040, 0x1040);
MS2_CHECK_OFFSET(PC, m_kGemEquip1078, 0x1078);
MS2_CHECK_OFFSET(PC, m_n10e8, 0x10e8);
MS2_CHECK_OFFSET(PC, m_n10fc, 0x10fc);
MS2_CHECK_OFFSET(PC, m_aMastery1150, 0x1150);
MS2_CHECK_OFFSET(PC, m_f1180, 0x1180);
MS2_CHECK_OFFSET(PC, m_set11a8, 0x11a8);
MS2_CHECK_OFFSET(PC, m_spCouple11d8, 0x11d8);
MS2_CHECK_OFFSET(PC, m_set1210, 0x1210);
MS2_CHECK_OFFSET(PC, m_spGuide1228, 0x1228);
MS2_CHECK_OFFSET(PC, m_mapTail1280, 0x1280);
MS2_CHECK_OFFSET(PC, m_spRandomTarget12c8, 0x12c8);
MS2_CHECK_OFFSET(PC, m_sp12d8, 0x12d8);
MS2_CHECK_OFFSET(PC, m_spD88, 0xd88);
MS2_CHECK_OFFSET(PC, m_kEquipDE0, 0xde0);
MS2_CHECK_OFFSET(PC, m_spFC8, 0xfc8);
MS2_CHECK_OFFSET(PC, m_pCubeCraft, 0x1020);
MS2_CHECK_OFFSET(PC, m_nFF9, 0xff9);
MS2_CHECK_OFFSET(PC, m_n1058, 0x1058);
MS2_CHECK_OFFSET(PC, m_b1070, 0x1070);
MS2_CHECK_OFFSET(PC, m_n1200, 0x1200);
MS2_CHECK_OFFSET(PC, m_b1204, 0x1204);
MS2_CHECK_OFFSET(PC, m_spSetItems, 0x1100);
MS2_CHECK_OFFSET(PC, m_spCostume, 0x1130);
MS2_CHECK_OFFSET(PC, m_spInteractMode, 0x1240);
MS2_CHECK_SIZE(PC, 0x12e0); // deleting dtor 1416678b0

// The fitting doll: a PC-derived actor the cube fitting-doll UI dresses up (?\fittingdollslot.cpp, 0x14121b350-0x14121ced0).
// Size 0x1300 (??_G 0x14121cca0). vftable 0x142ec2b60 (147 slots), CallbackObject vftable 0x142ec3000 (dtor thunk 0x14121cc8c).
// efd: GetClassDesc 0x14121cd80, TypeCast 0x14121cf50 / 0x14121cfa0, ms_ClassInfo 0x143ad3290, SetupClassInfo 0x14121cef0.
class FittingDollPC : public PC {
    EE_DECLARE_CLASS1(FittingDollPC, 0x06200046, PC);
public:
    FittingDollPC();                                        // 0x14121b350
    virtual ~FittingDollPC();                               // 0x14121b540
    virtual void vfunc_9(void* p);                          // 9   0x14121c140
    virtual int vfunc_10();                                 // 10  0x14121bec0
    virtual void vfunc_12();                                // 12  0x14121bf10
    virtual void vfunc_19(efd::Point3 kPos);                // 19  0x14121c1c0
    virtual void vfunc_24(int) { m_unk_40 = 0; }            // 24  0x14121ced0
    virtual void vfunc_53(float f);                         // 53  0x14121bf80
    virtual bool vfunc_68(void* a, double t, int b, unsigned c, int d);   // 68 0x14121bf60
    virtual MS2Ptr<Unk_PCBaseComp_a58> vfunc_80();          // 80  0x14121ce10
    virtual MS2Ptr<Unk_PCBaseComp_a78> vfunc_82();          // 82  0x14121ce50
    virtual MS2Ptr<Unk_PCBaseComp_a88> vfunc_83();          // 83  0x14121cd90
    virtual MS2Ptr<Unk_PCBaseComp_aa8> vfunc_85();          // 85  0x14121cd40
    virtual MS2Ptr<Unk_PCBaseComp_ab8> vfunc_86();          // 86  0x14121ce90
    virtual MS2Ptr<Unk_PCBaseComp_ac8> vfunc_87();          // 87  0x14121cd00
    virtual UISwfEntity* vfunc_88();                        // 88  0x14121cdd0
    virtual void vfunc_138(NiAVObject* pRoot, int n, const Unk_CharEquip* pEquip);  // 138 0x14121c230
    virtual int vfunc_145();                                // 145 0x14121ca50

    void FUN_14121c170(NiFixedString parentName);
    int FUN_14121c710();                                    // 0x14121c710 (scenestategame 0x7b mode 7: 1 selects the equip set)
    int FUN_14121bab0(int nItemId);                         // 0x14121bab0 set up the doll from an item (false when the item has no doll)
    void* FUN_14121c6c0();                                  // 0x14121c6c0 return unknown12f0
    void FUN_14121c6e0(void* p);                            // 0x14121c6e0 unknown12f0 = p
    bool FUN_14121c830();                                   // 0x14121c830 FUN_14121c710() == 0
    int FUN_14121c870(CItem* pItem);                        // 0x14121c870 the result of putting the item on the doll (0 = ok)
    int FUN_14121c910(CItem* pItem);                        // 0x14121c910
    int FUN_14121c9d0(CItem* pItem);                        // 0x14121c9d0
    int type, index, unknown12e8;
    void* unknown12f0;
    NiFixedString parentName;
};
MS2_CHECK_SIZE(FittingDollPC, 0x1300); // deleting dtor 14121cca0
MS2_CHECK_OFFSET(FittingDollPC, parentName, 0x12f8);
