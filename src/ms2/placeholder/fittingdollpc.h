#pragma once
#include "ms2/client/ms2/pcbase.h"
#include <NiFixedString.h>
#include "ms2/client/ms2/costumemanager.h"   // MS2Ptr<CostumeManager> at PC+0x1130
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
class AdditionalCli;
struct Unk_PCEquipSet
{
    MS2Ptr<CEquipItem> FUN_1411e1860(int nSlot, int nKind, int n);    // a worn item of the slot (customize.cpp)
    void FUN_1411e22c0(ATL::CAtlList<MS2Ptr<CEquipItem> >& out, int nKind);   // the worn items of a kind (customize.cpp)
    void FUN_1411e5c10(); void FUN_1411e6ab0(); void FUN_1411e75f0();   // refresh the look (customize.cpp)
    MS2Ptr<CEquipItem> FUN_1411e1780(int nSlot, int nKind); MS2Ptr<CEquipItem> FUN_1411e1580(__int64 nItemUid); void FUN_1411e4150(__int64 nItemUid, unsigned char nSlot, int nKind); void FUN_1411ea620(const CMsTime& kStart, const CMsTime& kEnd); void FUN_1411ea7c0(); void FUN_1411e7660();
    void FUN_1411e7640();                                   // the look changed (flag 50; additionalcli.cpp)
    void* FUN_1411e2440(int nKind);                         // the worn items of an equip layer, NULL when none (uiclosetdialog.cpp)
    MS2Ptr<CEquipmentSlotLayerInfo> GetTitle();            // 0x140d29440 the codi (outfit) tab period (defined in unit_140d1ae30)
    unsigned char unknown0[0x188];
    MS2Ptr<CEquipmentSlotLayerInfo> m_spTitle;              // +0x188 (new CEquipmentSlotLayerInfo(2))
    unsigned char unknown198[0x50];
};   // FUN_1411e1780 (itemgem.cpp): the worn item of an equip slot   // the PC's equipment holder (+0xde0); methods FUN_1411e3de0/e3000/e22c0
class Unk_PCD88;      // +0xd88 target (ClonePC::vfunc_12 releases it via FUN_140a35900)
class Unk_PCArg126;   // MS2Ptr<T> by value (get 0x1409f7930, ICF generic dtor 0x1401bfde0)
class Unk_HsInfo;     // MS2Ptr<T> by value (defined by uihideandseekresultdialog.cpp)
// The player's interact mode (PC +0x1240): while active it picks the kind of object to interact with (actionkeyobject.cpp).
// Defined here because PC::FUN_140967420 copies the MS2Ptr inline.
class Unk_PCInteractMode : public CPtred
{
public:
    bool FUN_140743550();                                   // active
    void FUN_140743a10(CInPacket& packet);                  // decode (scenestategame OnAddUser)
    int FUN_140743710();                                    // the target kind
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
    virtual MS2Ptr<Unk_PCBaseComp_a68> vfunc_81();          // 81 0x141656f80
    virtual MS2Ptr<Unk_PCBaseComp_a98> vfunc_84();          // 84 0x1416572b0
    virtual void vfunc_49();                                // 49 0x141660e00
    virtual int vfunc_64();                                 // 64 0x141654840 (mypc vftable, w97)
    virtual MS2Ptr<Unk_PCBaseComp_a78> vfunc_82();          // 82 0x141657100
    virtual MS2Ptr<Unk_PCBaseComp_aa8> vfunc_85();          // 85 0x1416573b0
    virtual MS2Ptr<Unk_PCBaseComp_ac8> vfunc_87();          // 87 0x1416575b0
    virtual void vfunc_90(void* p);                         // 90 0x141657910
    virtual float vfunc_95();                               // 95 0x14165e4a0 (PCBase 0x141671620)
    virtual int vfunc_99(int n);                            // 99 0x141654850
    virtual int vfunc_124(int a, int b);                    // 124 0x141653840 (1/0; homes edx and r8d)
    virtual void vfunc_125(MS2Ptr<Unk_PCArg125> p);         // 125 0x141654900 (MyPC 0x141522d40)
    virtual void vfunc_126(MS2Ptr<Unk_PCArg126> p, int n);  // 126 0x141655230 (n == 0: p.get() + 0x430)
    virtual void vfunc_127(CItem* pItem, int n);            // 127 0x1416563c0 (MS2Ptr<CItem>(pItem) into +0xde0)
    virtual void vfunc_128(CItem* pItem, int n);            // 128 0x1416564a0
    virtual void vfunc_129(const CStringW& str);            // 129 0x141656ba0: +0xdc8 = str
    virtual void vfunc_130(CStringA str);                   // 130 0x141656c00: +0xdd0 = str (by value)
    virtual void vfunc_131(short n);                        // 131 0x141657820: word +0xddc = n
    virtual int vfunc_132(CItem* pItem, int n, bool b);     // 132 0x141657e20
    virtual int vfunc_133(CItem* pItem, bool b);            // 133 0x141657dc0: vfunc_132(pItem, pItem->FUN_140527a20(), b)
    virtual CStringW vfunc_134();                           // 134 0x141658cd0 (hidden return; PC: L"")
    virtual void vfunc_135(int a, int b, void* p);          // 135 0x141659450
    virtual void vfunc_136(void* a, void* b, float f);      // 136 0x14165c240 (xmm3)
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
    void FUN_1416619d0(int n);                              // scenestategame packet 0x33
    void FUN_141661370(int a, int b, int c);                // scenestategame packet 0x34 (also on MyPC)
    void FUN_1416591e0(int nSlot, const NiColor& kColor);   // +0xd98 + nSlot*0xc = kColor (scenestategame 0x30)
    const NiColor& FUN_141659220(int nSlot);                // the colour at +0xd98 + nSlot*0xc
    void FUN_141656780();                                   // re-apply the appearance (scenestategame 0x30)
    void FUN_14165d300(int nA, int nB, int nC);             // PCBase member (pcbase.cpp; scenestategame 0x5d)
    void FUN_1416629d0(Unk_StreamPoint kPos, Unk_StreamPoint kRot);   // scenestategame 0x141721a30
    MS2Ptr<Unk_PCWaterGunInfo> FUN_141664250();             // the water gun battle info (+0x1260)
    void FUN_141662640(__int64 nValue);                      // scenestategame 0x1417340f0
    void FUN_141662690(int nValue);
    void FUN_141662710(int nValue);
    void FUN_141661330(const CStringW& strName);             // set the displayed name (scenestategame)
    class Unk_MyPCEquip* FUN_14165f460();                   // the equipment (mypc.cpp, w97)
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
    // 0xd40..0x12e0. The MS2Ptr at +0xfc8 (an action timer; AvatarPC::vfunc_142 pokes it) is exposed, the rest is opaque.
    // ClonePC (clonepc.cpp) uses the list at +0xd48, the MS2Ptr at +0xd88 and the equip holder at +0xde0.
    unsigned char unknownD40[8];
    unsigned char m_kListD48[0x40];                         // +0xd48 (reset by FUN_1408f3a80)
    MS2Ptr<Unk_PCD88> m_spD88;                              // +0xd88
    unsigned char unknownD98[0x48];
    Unk_PCEquipSet m_kEquipDE0;                             // +0xde0 equip holder (FUN_1411e3de0)
    MS2Ptr<Unk_PCActionTimer> m_spFC8;                      // +0xfc8
    unsigned char unknownFD8[0x21];
    unsigned char m_nFF9;                                   // +0xff9 PC bang bonus flags (FUN_141658f70)
    unsigned char unknownFFA[0x26];
    class Unk_PCCubeCraft* m_pCubeCraft;                    // +0x1020 (FUN_141659700; cube craft mode only)
    unsigned char unknown1028[0x30];
    int m_n1058;                                            // +0x1058 (non-zero: buffs never resist knock-back)
    unsigned char unknown105c[0xd4];
    MS2Ptr<CostumeManager> m_spCostume;                     // +0x1130 the costume sets (additionalcli.cpp)
    unsigned char unknown1140[0x88];
    int m_n11c8;                                            // +0x11c8 (FUN_14174a340)
    unsigned char unknown11cc[0x74];
    MS2Ptr<Unk_PCInteractMode> m_spInteractMode;      // +0x1240 (actionkeyobject.cpp)
    unsigned char unknown1250[0x90];
};
MS2_CHECK_OFFSET(PC, m_kListD48, 0xd48);
MS2_CHECK_OFFSET(PC, m_spD88, 0xd88);
MS2_CHECK_OFFSET(PC, m_kEquipDE0, 0xde0);
MS2_CHECK_OFFSET(PC, m_spFC8, 0xfc8);
MS2_CHECK_OFFSET(PC, m_pCubeCraft, 0x1020);
MS2_CHECK_OFFSET(PC, m_nFF9, 0xff9);
MS2_CHECK_OFFSET(PC, m_n1058, 0x1058);
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
