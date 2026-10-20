// pcbase.h - PCBase (efd RTTI "PCBase", class id 0x06200013): abstract base of every animated character actor
// (PC, MyPC, ClonePC, CNpc, CPet, Ridee, CubeSpawnObject ...). Derives GameObject. Owning unit:
// client\ms2\pcbase.cpp (0x14164dfd0-0x141682f80, 1159 funcs). Header name assumed from the unit path.
//
// HOW TO USE THIS HEADER (for unit workers):
// - `class X : public PCBase { EE_DECLARE_CLASS1(X, <id>, PCBase); ... };` - do not redeclare the refcount.
// - Virtual names are vfunc_N = slot N of PCBase's primary vftable 0x142f4c6f0 (124 slots: 0-56 from GameObject,
//   57-123 new here). To override, copy the exact declaration. Slot 116 is pure (_purecall) - every concrete
//   derived class must implement vfunc_116. Unproven param types are void*; refine them here (keep slot order)
//   and tell the coordinator.
// - vfunc_114 is inline (its only COMDAT 0x140a4ffb0 lives in the cubespawnobject unit); keep it inline.
// - vfunc_80..87/103/104 return lazily-created per-actor components as MS2Ptr<T> (hidden return pointer). Their
//   T is unproven: each uses a distinct MS2Ptr instantiation (null ctor VA noted), so each gets its own Unk_ type.
// - Members: proven types where known, otherwise pointer/int-aligned stand-ins of the right size (PCBase is
//   heap-only, never a local). MS2_CHECK_OFFSETs below pin the ones derived classes touch.
#pragma once
#include <map>
#include <vector>
#include <atlcoll.h>
#include <atlcomcli.h>

#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/placeholder/timer.h"     // Timer (0x38)
#include "ms2/placeholder/pushcontrol.h"   // CPushControl (0x48)
#include "ms2/placeholder/unkvec47.h"     // Unk_Vec4 / Unk_Vec7 (+0x180..+0x1bc)
#include <efd/utf8string.h>
#include <efd/Point2.h>

// Component types behind the MS2Ptr members/getters (names unknown; MS2Ptr null-ctor VA in brackets).
class RideOnAction;        // rideonaction.h (+0xb00, slot 121)
class Unk_PCBaseActions;   // +0xd00 (?\actioncontainer.cpp; pcbase.cpp)
class CSkillRecord;        // slots 100-102 (RTTI CSkillRecord, 0x1c0; ?\skillrecord.cpp)
class Unk_PCBaseComp_a58;   // slot 80, +0xa58 [0x14108af40]
class Unk_PCBaseComp_a68;   // slot 81, +0xa68 [0x140e86b20] (null ctor COMDAT in uishieldbar)
class Unk_PCBaseComp_a78;   // slot 82, +0xa78 [0x14108af60]
class Unk_PCBaseComp_a88;   // slot 83, +0xa88 [0x14108af20]
class Unk_PCBaseComp_a98;   // slot 84, +0xa98 [0x14128f6f0]
class Unk_PCBaseComp_aa8;   // slot 85, +0xaa8 [0x140a4fc30] (CubeSpawnObject overrides slot 85)
class Unk_PCBaseComp_ab8;   // slot 86, +0xab8 [0x14108af80]
class Unk_PCBaseComp_ac8;   // slot 87, +0xac8 [0x140ba97e0]
class Unk_PCBaseComp_b18;   // slots 103/104, +0xb18 [0x141532140 / member init 0x141532470]
class CStateManager;        // +0x140 actor state machine (0x98 bytes, ctor(actor) 0x1417da7a0, AddState 0x1417daeb0)
class CEffectDummy;         // effectdummy.h: element of the npc row's part list (+0x588), applied by FUN_141674ef0
class Unk_PCBaseBuffs;      // FUN_1416749a0 (ridee.cpp)
class State;                // state.h
class StateData;            // state.h (the request record handed to CStateManager::FUN_1417dafa0)
class RideOffAction;        // commonfiles/rideonaction.h
class Ridee;                // ridee.h (the mount; +0xb10)
class PCBase;
class Unk_PCBaseEntity;      // an egf entity seen through its property getters, pcbase.cpp
class Unk_PCBaseFxSet;       // vfunc_71/73 argument (MS2Ptr by value; effect names at +0x40), pcbase.cpp
class CBoxCollision;         // functioncubeobject.h
class CDotDamageRecord;      // ?\skillrecord.cpp (view in pcbase.cpp)
class CDamageRecord;         // ?\skillrecord.cpp (view in pcbase.cpp)
class CSplashDamageRecord;   // ?\skillrecord.cpp (view in pcbase.cpp)
class Unk_PCBaseFxLib;       // vfunc_70 result: the effect-source library (FUN_1411bde10 by id), pcbase.cpp
class Unk_PCBaseFxSource;    // +0xd10, hands out Unk_PCBaseFxSet by key (slot 2), pcbase.cpp
class Unk_PCBaseEmoPlayer;   // +0x638 (FUN_141848650 stop, FUN_141848740 busy at a time), pcbase.cpp
class UISwfEntity;          // uiswfentity.h (+0xad8, unregistered by the dtor)
class Unk_PCBaseBody;       // +0x150 physics/controller body (0xf8; ctor 0x14123f2d0, dtor 0x14123f460), pcbase.cpp

// +0xc08: an 11-bit set (commonfiles\bitset.inl instance, the same as unit_140d73aa0's Unk_BitSet11): the reasons the
// actor is hidden (FUN_14166ca20 / FUN_14166ca80 / FUN_14166cb30).
// +0x648: CColorBoostManager (0x48; FUN_14109be00 adds a CColorBoostData).
class CColorBoostData;
class Unk_PCBaseColorBoostMgr
{
public:
    Unk_PCBaseColorBoostMgr();                              // 0x14109bd60
    ~Unk_PCBaseColorBoostMgr();                             // 0x14109bdc0
    void FUN_14109be00(const CColorBoostData& kData);
    void FUN_14109be30(const egf::EntityID& kId);          // per-frame update
private:
    void* m_unk[9];
};

// +0x6d8: the buff tracker of the next unit (0x70; ctor 0x141682e90, dtor 0x141682f30; FUN_141682f60(p, owner) binds
// it, FUN_141682fe0(p, id) tests a buff, FUN_141683a90(p) flushes it).
class Unk_PCBaseBuffTracker
{
public:
    Unk_PCBaseBuffTracker();                                // 0x141682e90
    ~Unk_PCBaseBuffTracker();                               // 0x141682f30
private:
    void* m_p00;                                            // = 0
    Timer m_timer08;
    efd::Point3 m_pos40;                                    // = ZERO
    int m_n4c;
    int m_n50;                                              // = 0
    efd::Point3 m_pos54;
    efd::Point3 m_pos60;
};
MS2_CHECK_SIZE(Unk_PCBaseBuffTracker, 0x70);

// +0x748: the actor's buffs (0x1a0; ctor 0x14096ef20(p, owner); unit 0x14096ef20..). FUN_1416749a0 returns it as the
// Unk_PCBaseBuffs view that ridee.cpp / pcbase.cpp declare. The recovered class is AdditionalCliList
// (additionalclilist.h, ?\additionalcli.cpp#2); this opaque view keeps pcbase.h free of the table headers.
class Unk_PCBaseBuffList
{
public:
    Unk_PCBaseBuffList(PCBase* pOwner);                     // 0x14096ef20
    ~Unk_PCBaseBuffList();
    void FUN_140970490();                                   // clear
    void FUN_140971150();                                   // refresh after an equip change (pc.cpp)
    bool FUN_140970ad0();                                   // a buff keeps the actor busy (pc.cpp)
    void FUN_140970420(double dTime);                       // per-frame update
    float FUN_1409705d0();                                  // scale
    int FUN_1409701d0(int nKind);
    int FUN_140970eb0(float& fOut);                         // a buff fixes the height
private:
    char m_pad[0x1a0];
};

class Unk_PCBaseFlags
{
public:
    Unk_PCBaseFlags();                                      // 0x140d75040
    Unk_PCBaseFlags& FUN_140d75120(unsigned nPos, bool bValue);   // set / clear one bit
    bool FUN_140d75240(unsigned nPos) const;                // test one bit
    void Reset(unsigned nPos) { FUN_140d75120(nPos, false); }     // COMDAT 0x141682e20
    bool Any() const                                        // COMDAT 0x141682520
    {
        for (int i = 1; i >= 0; i--) {
            if (m_bits[i] != 0)
                return true;
        }
        return false;
    }
    int Count() const                                       // COMDAT 0x141682780
    {
        int n = 0;
        for (int i = 1; i >= 0; i--) {
            for (unsigned char b = m_bits[i]; b != 0; b >>= 4)
                n += "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4"[b & 0xf];
        }
        return n;
    }
    unsigned char m_bits[2];
};

// 0xd40 bytes. vftable 0x142f4c6f0 (124 slots); CallbackObject vftable @+8 0x142f4cad8 (dtor thunk 0x14167f518,
// overrides AnimActivated 0x14166bec0, TextKeyEvent 0x14166bf40, EndOfSequence 0x14166c550).
// efd: TypeCast 0x141680770/0x141680720, GetClassDesc 0x14167f940, ??_G 0x14167f670, ClassInfo 0x143ae32d0.
class PCBase : public GameObject
{
    EE_DECLARE_CLASS1(PCBase, 0x06200013, GameObject);

public:
    PCBase();                                               // 0x14166a650
    virtual ~PCBase();                                      // 0x14166af20

    // NiActorManager::CallbackObject overrides
    virtual void AnimActivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x14166bec0
    virtual void TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x14166bf40
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x14166c550

    // GameObject overrides (slots 9..56)
    virtual void vfunc_9(void* p);                          // 9 0x14166b470
    virtual int vfunc_10();                                 // 10 0x14166b550
    virtual void vfunc_12();                                // 12 0x14166b810
    virtual void vfunc_14();                                // 14 0x14166b880
    virtual void vfunc_15();                                // 15 0x14166b990
    virtual void vfunc_16();                                // 16 0x14166b9e0
    virtual NiPoint3 vfunc_18();                            // 18 0x14166bbe0
    virtual void vfunc_19(efd::Point3 kPos);                // 19 0x14166bb10 (by value)
    virtual NiPoint3 vfunc_20();                            // 20 0x14166bc50
    virtual void vfunc_21(efd::Point3 kDir);                // 21 0x14166bb60 (by value)
    virtual void vfunc_23(int n);                           // 23 0x14166c5b0
    virtual Unk_GoAttachment* vfunc_26();                   // 26 0x14166bd70
    virtual void vfunc_32(bool b);                          // 32 0x14166bdd0
    virtual NiPoint3 vfunc_37();                            // 37 0x14166bcc0
    virtual void vfunc_52(double fTime);                    // 52 0x14166c640 (update)
    virtual void vfunc_53(float f);                         // 53 0x141679450

    // new virtuals, slots 57..123
    virtual int vfunc_57();                                 // 57  0x14166c7d0
    virtual int vfunc_58();                                 // 58  0x14166c7e0
    virtual void vfunc_59(int nState, StateData* pData, int nSub, int bForce);   // 59  0x14166c800
    virtual CString vfunc_60();                             // 60  0x14166c9b0 (returns a literal; PC overrides)
    virtual int vfunc_61();                                 // 61  0x14166ca00
    virtual bool vfunc_62();                                // 62  0x14166ca10
    virtual int vfunc_63();                                 // 63  0x14166ce00
    virtual int vfunc_64();                                 // 64  0x14166cec0
    virtual int vfunc_65();                                 // 65  0x14166ced0
    virtual void vfunc_66(int n);                           // 66  0x14166cef0
    virtual void vfunc_67(efd::Point3* pDir, efd::Point3* pSide);   // 67  0x14166cf40 facing and side vectors
    virtual bool vfunc_68(void* a, double t, int b, unsigned c, int d);  // 68 0x14166e100
    virtual int vfunc_69();                                 // 69  0x14166f9f0
    virtual Unk_PCBaseFxLib* vfunc_70();                    // 70  0x14166fa00
    virtual void vfunc_71(MS2Ptr<Unk_PCBaseFxSet> spSet);   // 71  0x14166fa30
    virtual void vfunc_72();                                // 72  0x14166fa60
    virtual void vfunc_73(MS2Ptr<Unk_PCBaseFxSet> spSet, int bFx); // 73  0x14166fa70
    virtual void vfunc_74(__int64 nCur, __int64 nMax);      // 74  0x14166fbf0 (scenestategame 0x2e: hp current/max)
    virtual void vfunc_75(__int64 nCur, __int64 nMax);      // 75 (shield bar current/max)  0x14166fc70
    virtual void vfunc_76(CStringW str);                    // 76  0x14166fcf0 (by value: the callee destroys it)
    virtual CStringW vfunc_77();                            // 77  0x14166fd50
    virtual int vfunc_78();                                 // 78  0x14166fda0
    virtual void vfunc_79();                                // 79  0x14166fdb0
    virtual MS2Ptr<Unk_PCBaseComp_a58> vfunc_80();          // 80  0x14166fde0 (base: null; Ridee/PC override)
    virtual MS2Ptr<Unk_PCBaseComp_a68> vfunc_81();          // 81  0x14166fe20
    virtual MS2Ptr<Unk_PCBaseComp_a78> vfunc_82();          // 82  0x14166fe60
    virtual MS2Ptr<Unk_PCBaseComp_a88> vfunc_83();          // 83  0x14166fea0
    virtual MS2Ptr<Unk_PCBaseComp_a98> vfunc_84();          // 84  0x14166fee0
    virtual MS2Ptr<Unk_PCBaseComp_aa8> vfunc_85();          // 85  0x14166ff20
    virtual MS2Ptr<Unk_PCBaseComp_ab8> vfunc_86();          // 86  0x14166ff60
    virtual MS2Ptr<Unk_PCBaseComp_ac8> vfunc_87();          // 87  0x14166ffa0
    virtual UISwfEntity* vfunc_88();                        // 88  0x14166ffe0 (base: null; MyPC: its EP progress UI, m_unk_ad8)
    virtual float vfunc_89();                               // 89  0x141670450
    virtual void vfunc_90(void* p);                         // 90  0x141670a90
    virtual void vfunc_91(void* p);                         // 91  0x141670cd0
    virtual void vfunc_92(void* p);                         // 92  0x141670d10
    virtual void vfunc_93(bool b);                          // 93  0x141671130
    virtual void vfunc_94(int n);                           // 94  0x141671380
    virtual float vfunc_95();                               // 95  0x141671620
    virtual float vfunc_96();                               // 96  0x141671680 move speed
    virtual float vfunc_97();                               // 97  0x141671720
    virtual float vfunc_98(float f);                        // 98  0x1416718d0
    virtual int vfunc_99(int n);                            // 99  0x141671b70
    // 100-102 take the skill record smart pointer BY VALUE (the callee destroys it: MS2Ptr<CSkillRecord> dtor
    // 0x140975740 on the homed rdx in 0x141672910 / 0x141672de0 / 0x141673890; callers copy it with 0x1409f71b0 first,
    // e.g. inventory 0x140a62d30 -> slot 102, skillslot 0x141765570 -> slot 100). CSkillRecord: RTTI, new(0x1c0).
    virtual void vfunc_100(MS2Ptr<CSkillRecord> skill, int n);           // 100 0x141672910
    virtual void vfunc_101(MS2Ptr<CSkillRecord> skill, int n, void* q);  // 101 0x141672de0
    virtual bool vfunc_102(MS2Ptr<CSkillRecord> skill);                  // 102 0x141673890 (base: return true)
    virtual MS2Ptr<Unk_PCBaseComp_b18> vfunc_103();         // 103 0x1416738c0 (checks +0x8e8 list)
    virtual MS2Ptr<Unk_PCBaseComp_b18> vfunc_104(bool a, bool b, bool c);  // 104 0x1416739c0 (base: null; 3 bools per Ridee)
    virtual void vfunc_105(efd::Point3 kPos, void* b, void* c, int d);   // 105 0x141673a10 (kPos by value per Ridee)
    virtual void vfunc_106(const efd::Point3& kMove, double dTime, int nFlags);   // 106 0x141674750 move by a delta
    virtual void vfunc_107(MS2Ptr<CDamageRecord> spRecord, float fScale); // 107 0x141674020 knock-back from a hit
    virtual int vfunc_108();                                // 108 0x141674bf0
    virtual void vfunc_109(int n);                          // 109 0x141674c00
    virtual void vfunc_110();                               // 110 0x141674c50
    virtual void vfunc_111(void* p, int a, int b, void* q); // 111 0x141674c60 (CNpc/CPet override)
    virtual void vfunc_112(void* p, int n);                 // 112 0x141674d80 (CNpc/CPet override)
    virtual void vfunc_113(void* p);                        // 113 0x141674ec0
    virtual void vfunc_114(void*) {}                        // 114 0x140a4ffb0 (inline; Ridee overrides)
    // 115: three register floats + stack float, int, int* (CGuideObject 0x1410a1240 / Ridee 0x141706490 forward all
    // six; CNpc/CPet 0x141090850 stores 0 to *pOut, tests nFlag == 0 and multiplies the result by d; PC 0x14165e500
    // stores 1/0 to *pOut). Base 0x141675270: return 0.0f.
    virtual float vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut);  // 115 0x141675270
    virtual int vfunc_116() = 0;                            // 116 _purecall (CubeSpawnObject 0x140a4efd0: return 1)
    virtual int vfunc_117();                                // 117 0x1416752a0
    virtual int vfunc_118(const NiPoint3& kPos, float* pDist, CString* pName);   // 118 0x1416752f0 nearest node in +0xb88
    virtual void vfunc_119();                               // 119 0x141675450
    virtual void vfunc_120(MS2Ptr<RideOnAction> spAction);  // 120 0x141676b90 (by value)
    virtual void vfunc_121(MS2Ptr<RideOffAction> spAction);   // 121 0x1416773f0 (by value)
    virtual int vfunc_122(void* p);                         // 122 0x1416781c0
    virtual const char* vfunc_123(int n);                   // 123 0x1416790b0 (looks up in +0xd00; a string per Ridee)

    // non-virtual helpers called by derived units
    bool FUN_14166dd20(const efd::utf8string& strAnim, float fSpeed, bool bA, bool bB);   // 0x14166dd20 play animation
    void FUN_14166fff0(CStringW str);                       // 0x14166fff0 chat balloon text (by value)
    bool FUN_141674ef0(const CEffectDummy& kDummy);         // 0x141674ef0 attach an effect node per the dummy
    MS2Ptr<CStateManager> FUN_141678750();                  // 0x141678750 copy of m_spStateMgr (w17)
    void FUN_141676310(int n);                              // 0x141676310 empty
    bool FUN_141679220(const char* szName);                 // 0x141679220 FUN_141679270 found a sequence
    int FUN_1416765b0();                                    // 0x1416765b0 the ridee has a free seat
    void FUN_141676060(NiPoint3 kPos);                      // 0x141676060 set +0xc10 (forwarded to the ridee)
    void FUN_14166ebf0(PCBase* pOther);                     // 0x14166ebf0 copy pOther's +0xae0 entity position
    int FUN_141675ed0();                                    // 0x141675ed0 standing on a kind-8 (water) entity
    void FUN_141676140();                                   // 0x141676140 send the fall damage since +0xc10
    void FUN_141678ad0(CString strName, bool bOutline, float fScale, float fAngle);   // 0x141678ad0 attach a model under "Eff_UI" (+0xc40)
    void FUN_141678f50();
    GameObject* FUN_141679800(CAtlArray<efd::SmartPointer<GameObject> >& arrTargets, float fAngle, efd::Point3 kDir, int nMode);   // 0x141679800 best target in a cone by angle (alive first)
    GameObject* FUN_141679ad0(CAtlArray<efd::SmartPointer<GameObject> >& arrTargets, float fAngle, efd::Point3 kDir, int nMode);   // 0x141679ad0 best target in a cone by distance (alive first)                                   // 0x141678f50 detach +0xc40 from "Eff_UI"
    // clonepc.cpp (w69)
    bool FUN_14166ed10();                                   // 0x14166ed10 the value ClonePC copies into m_b9d0
    void FUN_14166ed70(int n);                              // 0x14166ed70
    void FUN_14166ef10(const CString& str, int nA, int nB, bool bC);   // 0x14166ef10 play an emotion
    int FUN_14166f6d0();
    bool FUN_14166f790(void* pKey, CString& strOut, int n);   // 0x14166f790 effect name of a key
    void FUN_14166f940();                                   // 0x14166f940 emotion timer expired: back to default                                    // 0x14166f6d0
    CString FUN_14166f740();                                // 0x14166f740 (returns a string)
    void FUN_141671c20(MS2Ptr<CDamageRecord> spRecord);     // 0x141671c20 show a hit (damage numbers or the miss effect)
    void FUN_141672020(MS2Ptr<CDotDamageRecord> spRecord);
    void FUN_1416721d0(MS2Ptr<CSplashDamageRecord> spRecord);   // 0x1416721d0 show a splash hit   // 0x141672020 show a DoT tick
    int FUN_1416725c0(NiPoint3& kDir, float fDist, float fHeight, float fUp);   // 0x1416725c0 can step fDist along kDir (motioncontroller)
    static int FUN_141677f40(PCBase* pActor);                // 0x141677f40 local rider: request getting off (states)
    void FUN_1416788d0();                                   // 0x1416788d0 cast skill 20000011 (or the "not now" notice)
    void FUN_14166f380();                                   // 0x14166f380 reload the effect source (vfunc_70 library, vfunc_69 id)
    // uipvpguildteamdialog.cpp (w71)
    __int64 FUN_141670a00(int nStat);                       // 0x141670a00 current value of a stat (4 = hp)
    __int64 FUN_141670a30(int nStat);                       // 0x141670a30 max value of a stat
    // ridee.cpp (w67)
    ATL::CRBMap<CString, efd::SmartPointer<NiAVObject> >& FUN_141708b10() { return m_unk_b88; }   // COMDAT 0x141708b10
    int FUN_14166c930();                                    // 0x14166c930 current state id (0: none)
    int FUN_14166cc80();                                    // 0x14166cc80 current sub state
    State* FUN_14166ccb0();                                 // 0x14166ccb0 current state
    void FUN_141670700(int nType, __int64 nValue);           // 0x141670700 (scenestategame packet 0x64: 10, skill id)
    __int64 FUN_141656a80();                                // 0x141656a80 (scenestategame packet 0x39 battle record key)
    void FUN_14166ce50(int n);                              // 0x14166ce50 (scenestategame packet 0x34: 0)
    int FUN_14166ce30();                                    // 0x14166ce30 dead (1)
    // @0x140976780
    int FUN_140976780() { return m_unk_118; }               // sound pitch (additionalcli.cpp)
    // @0x1409788b0
    void FUN_1409788b0(int n) { m_unk_118 = n; }
    float FUN_14166da40();                                  // 0x14166da40
    void FUN_14166d820();                                   // 0x14166d820
    void FUN_14166e0a0();                                   // 0x14166e0a0
    void FUN_141670d50(efd::Point2 kSize);                  // 0x141670d50 (25, 105 for a Ridee)
    void FUN_141670fd0(efd::Point3 kSize, efd::Point3 kOffset);   // 0x141670fd0 collision box
    void FUN_141671960(float fSpeed);                       // 0x141671960
    Unk_PCBaseBuffs* FUN_1416749a0();                       // 0x1416749a0
    bool FUN_1416749c0();                                   // 0x1416749c0
    int FUN_141676410();                                    // 0x141676410 riding id
    MS2Ptr<Unk_PCBaseComp_b18> FUN_141676930();             // 0x141676930 ugc ridee item
    void FUN_141676b50(int bRun);                           // 0x141676b50
    int FUN_141676b70();                                    // 0x141676b70
    void FUN_141678240(egf::EntityID& kId, NiPoint3& kPos);   // 0x141678240 out: +0xae0 / +0xae8
    void FUN_141678290(egf::EntityID kId, NiPoint3 kPos);   // 0x141678290
    void FUN_141678360();                                   // 0x141678360
    class Ridee* FUN_1416764a0();                           // 0x1416764a0 the ridee this actor rides (scenestategame, w86)
    void FUN_14166ce70(int nEmotion);                       // 0x14166ce70 (scenestategame packet 0x3f, w86)
    __int64 FUN_141670990(int nKind, int nStat);            // 0x141670990 stat value (kind 0..2, stat 0..0x22; scenestategame w109)
    // pcbase.cpp (w112)
    void FUN_141670ed0(Unk_PCBaseEntity* pEntity);          // 0x141670ed0 ground material of the entity under the actor
    CString FUN_141671480();                                // 0x141671480 footstep material
    BOOL FUN_1416719c0();                                   // 0x1416719c0 model is a "Dash" model
    int FUN_141671a30();                                    // 0x141671a30 standing on ground
    void FUN_1416700b0(int nType);                          // 0x1416700b0 banner
    void FUN_141670180(bool bShow);                         // 0x141670180 refresh the hp bar
    void FUN_141670260(int nShield, bool bShow);            // 0x141670260 refresh the shield bar
    float FUN_141670390();                                  // 0x141670390 height (+ mount)
    void FUN_141670540(int nKind, int nStat, __int64 nValue);   // 0x141670540 set a stat value
    void FUN_1416705c0(int nStat, __int64 nValue);          // 0x1416705c0
    void FUN_1416708a0(int nStat, __int64 nValue);          // 0x1416708a0
    void FUN_141670920(int nStat, __int64 nValue);          // 0x141670920
    int FUN_1416787a0();                                    // 0x1416787a0 field +0x4c of the local player record
    efd::utf8string& FUN_14166e0d0();                       // 0x14166e0d0 current animation name
    void FUN_14166ed30(bool b);
    void FUN_14166ed50(bool b);
    void FUN_14166f8f0(int nA, int nB);
    void FUN_141670330(float f);
    void FUN_141670360(float f);
    float FUN_141670430();
    float FUN_141670500();
    float FUN_141670520();
    __int64 FUN_1416709d0(int nStat);
    __int64 FUN_141670a60(int nStat);
    void FUN_141670d80(float fSpeed);
    void FUN_141670db0(CString str);
    void FUN_141670e00(CString str);
    void FUN_141670e50(CString str);
    void FUN_141670ea0();
    efd::Point2 FUN_141671390();
    CString FUN_1416713e0();
    CString FUN_141671430();
    CString FUN_1416715b0();
    float FUN_141671600();
    float* FUN_141671920();
    float FUN_141671940();
    void FUN_141671990(float fScale);
    BOOL FUN_141671b20();
    efd::Point3 FUN_141676020();
    void FUN_141676980(int n);
    void FUN_1416769a0(__int64 nUid);
    int FUN_1416769d0();
    __int64 FUN_1416769f0();
    void FUN_1416781a0(int n);
    int FUN_1416782e0();
    void FUN_141678300(int n);
    int FUN_141678320();
    void FUN_141678340(int n);
    efd::Point3 FUN_141678710();
    int FUN_141679070();
    void FUN_141679090(int n);
    int FUN_14166c960();                                    // 0x14166c960 queued state (m_unk_c48)
    int FUN_14166c980();                                    // 0x14166c980 previous state id
    void FUN_14166ca20(unsigned int nReason);               // 0x14166ca20 hide for a reason
    void FUN_14166ca80(unsigned int nReason);               // 0x14166ca80 clear a hide reason
    bool FUN_14166cad0();                                   // 0x14166cad0 hidden for any reason
    bool FUN_14166cb00(unsigned int nReason);               // 0x14166cb00
    void FUN_14166cb30();                                   // 0x14166cb30 apply the hide reasons
    void FUN_14166cc40(int nValue);                         // 0x14166cc40
    void FUN_14166cce0(unsigned int nFlags);                // 0x14166cce0 m_unk_158 |= (rider and mount)
    void FUN_14166cd70(unsigned int nFlags);                // 0x14166cd70 m_unk_158 &= ~
    Unk_PCBaseBody* FUN_14166d220();                        // 0x14166d220 the physics body
    void* FUN_14166d240();                                  // 0x14166d240 &m_unk_6d8
    void FUN_14166d260();                                   // 0x14166d260 move the body to the actor
    void FUN_14166d2d0(const efd::Point3& kTarget, int bTurn);   // 0x14166d2d0 face a point
    void FUN_14166d430(efd::Point3 kDir, int bTurn, int bResetTilt);   // 0x14166d430 face a direction
    void FUN_14166d630(float fTime);                        // 0x14166d630 turn toward m_f934
    void FUN_14166d8b0(float fAngle);                       // 0x14166d8b0 target yaw
    void FUN_14166d8e0(efd::Point3 kTilt);                  // 0x14166d8e0
    void FUN_14166d970(efd::Point3 kRot);                   // 0x14166d970
    void FUN_14166d9d0(const NiPoint3& kPos);               // 0x14166d9d0
    void FUN_14166da10(float fSpeed);                       // 0x14166da10 turn speed
    float FUN_14166da60();                                  // 0x14166da60
    float FUN_14166dab0();                                  // 0x14166dab0 turn speed
    float FUN_14166dad0(const efd::Point3& kLook, const efd::Point3& kDir);   // 0x14166dad0 yaw (degrees)
    efd::Point3 FUN_141674a10(efd::Point3 kDir, float* pYaw);   // 0x141674a10 local dir -> world dir (+ its yaw)
    int FUN_141673b40(MS2Ptr<Unk_PCBaseComp_b18> spItem);   // 0x141673b40 (by value)
    MS2Ptr<Unk_PCBaseComp_b18> FUN_141673bf0(__int64 nTagId, int nKind);   // 0x141673bf0 find in +0x8e8
    MS2Ptr<Unk_PCBaseComp_b18> FUN_141673ce0(MS2Ptr<Unk_PCBaseComp_b18> spItem);   // 0x141673ce0 replace +0x8e8 with it
    MS2Ptr<Unk_PCBaseComp_b18> FUN_141673e10(__int64 nTagId);   // 0x141673e10 find in +0x8e8
    int FUN_141673ef0();                                     // 0x141673ef0 skill id of the running skill state (avatarpc.cpp)
    void FUN_141673f70(float a, float b, float c);           // 0x141673f70 color boost (also the ridee)
    efd::Point3 FUN_141674b60(efd::Point3 kDir);             // 0x141674b60 local dir -> world dir
    int FUN_141674bc0();                                     // 0x141674bc0 (buffs)
    NiAVObject* FUN_141675150(const CString& strNode);       // 0x141675150 the named node (the ridee's when riding)
    unsigned int FUN_141675240();                            // 0x141675240 movement flags of the buffs
    efd::SmartPointer<NiAVObject> FUN_1416757c0(CString strName);   // 0x1416757c0 node of +0xb88
    efd::SmartPointer<NiAVObject> FUN_1416758a0(CString strName);   // 0x1416758a0 node of +0xbb8
    efd::SmartPointer<NiAVObject> FUN_141675930();          // 0x141675930 copy of +0xbe8
    int FUN_141675cd0(const NiPoint3& kPos, CString strUnused, CString* pName, float* pDist);   // 0x141675cd0 nearest node in +0xbb8
    int FUN_141675e60();                                     // 0x141675e60 +0xbb8 not empty
    void* FUN_141675eb0();                                   // 0x141675eb0 &m_pushControl (statemanager.cpp)
    void FUN_141676320(MS2Ptr<RideOnAction> spAction);       // 0x141676320 (by value)
    MS2Ptr<RideOnAction> FUN_141676370();                    // 0x141676370 copy of +0xb00
    int FUN_1416763c0();                                     // 0x1416763c0 the ridee's object id
    int FUN_141676500();                                     // 0x141676500 the ridee's type is 1
    void FUN_141676670(unsigned int nKey, int nValue);       // 0x141676670 +0xb28
    void FUN_1416766b0(MS2Ptr<Unk_PCBaseComp_b18> spItem);   // 0x1416766b0 (by value)
    void FUN_141676700();                                    // 0x141676700 +0xb28 RemoveAll
    void FUN_141676730(unsigned int nKey);                   // 0x141676730 +0xb28 RemoveKey
    int FUN_141676760();                                     // 0x141676760 +0xb28 count
    int FUN_141676790(unsigned int nKey);                    // 0x141676790 +0xb28 lookup (0 if missing)
    NiPoint3 FUN_1416767d0();                                // 0x1416767d0 vfunc_18 of the ridee when riding
    NiPoint3 FUN_141676880();                                // 0x141676880 vfunc_20 of the ridee when riding
    void* FUN_141676a10();                                   // 0x141676a10 (the world object of +0xb70)
    void FUN_141676a50(__int64 nUid, int n);                 // 0x141676a50 +0xca8 SetAt
    void FUN_141676ab0(__int64 nUid);                        // 0x141676ab0 +0xca8 RemoveKey
    int FUN_141676b00(__int64 nUid);                         // 0x141676b00 +0xca8 has it
    void FUN_141678160(const NiPoint3& kPos);                // 0x141678160 m_posBF4 = kPos
    unsigned int FUN_141678680();                            // 0x141678680 skill-use disable mask (buffs | field)
    int FUN_141678820();                                     // 0x141678820 +0xc68 when the field checks climbing
    void FUN_141679120(int n);                               // 0x141679120 (+0xd00 slot 4)
    efd::utf8string FUN_141679170(int a, int b);             // 0x141679170 (+0xd00 slot 6)
    NiPoint3 FUN_14166dbb0();                               // 0x14166dbb0
    CString FUN_14166dc50();                                // 0x14166dc50 model name
    bool FUN_14166dda0(int nId);                            // 0x14166dda0 play the animation of slot 123
    void FUN_14166de50(float fOffset);                      // 0x14166de50 offset of the current sequence
    CString FUN_14166dbf0(const efd::utf8string& kName);    // 0x14166dbf0 model-specific animation name
    float FUN_1416713c0();                                  // 0x1416713c0 animation speed
    void FUN_141675980();                                   // 0x141675980
    void FUN_141679e90();                                   // 0x141679e90 stop the sequence effects
    bool FUN_14166de90(int nKey, unsigned int nSeq);            // 0x14166de90 nAnimId is one of +0xd00's names for nKey
    unsigned int FUN_141679270(const char* szName);                   // 0x141679270 animation id of vfunc_60() + szName (-2: none)
    void FUN_1416795e0();                                    // 0x1416795e0 replay the queued state request (+0xc48)
    void FUN_141679760();                                    // 0x141679760 reload +0xd00 for vfunc_57()
    void FUN_141679e00();                                    // 0x141679e00 stop the +0xa30 effects
    void FUN_141679f30();                                    // 0x141679f30
    void FUN_141679fa0();                                    // 0x141679fa0
    // mypc.cpp (w99)
    unsigned short FUN_141661e00();                         // 0x141661e00 the channel the actor is on
    int FUN_141661e20();                                    // 0x141661e20
    int FUN_1416764d0();                                    // 0x1416764d0 riding

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CStateManager> m_spStateMgr; // +0x140 (init 0x14167dfe0; CubeSpawnObject assigns via AssignRaw)
    Unk_PCBaseBody* m_unk_150;          // +0x150 = 0; created by vfunc_10
    int m_unk_158;                      // +0x158
    int m_unk_15c;                      // +0x15c
    int m_unk_160;                      // +0x160
    float m_f164;                       // +0x164 (not initialised by PCBase; derived ctors load config floats)
    float m_f168;                       // +0x168
    float m_f16c;                       // +0x16c
    float m_f170;                       // +0x170
    float m_f174;                       // +0x174
    float m_f178;                       // +0x178
    float m_f17c;                       // +0x17c
    Unk_Vec4 m_unk_180;                 // +0x180 (ctor 0x140266620; m_x = 1800.0, m_z move speed: vfunc_10 -> FUN_141671960)
    Unk_Vec4 m_unk_190;                 // +0x190 (ctor 0x140266620; m_x = turn speed in degrees per second, 1800.0)
    Unk_Vec7 m_unk_1a0;                 // +0x1a0 (ctor 0x1402666f0; m_a = 50.0)
    int m_unk_1bc;                      // +0x1bc
    __int64 m_unk_1c0[3][0x23];         // +0x1c0 stat values (kind 0..2, stat 0..0x22; FUN_141670990)
    __int64 m_unk_508[0x23];            // +0x508 zero-filled record
    efd::Point2 m_unk_620;              // +0x620 (init 0x140a0a600(p, 25.0, 105.0)) model size
    MS2Ptr<CBoxCollision> m_sp628;      // +0x628 collision box (FUN_141670fd0)
    MS2Ptr<Unk_PCBaseEmoPlayer> m_sp638; // +0x638 (init 0x14167e030)
    Unk_PCBaseColorBoostMgr m_colorBoost;   // +0x648 CColorBoostManager (0x48)
    CPushControl m_pushControl;         // +0x690 (0x48)
    Unk_PCBaseBuffTracker m_unk_6d8;    // +0x6d8
    Unk_PCBaseBuffList m_unk_748;       // +0x748 buffs
    CAtlList<MS2Ptr<Unk_PCBaseComp_b18> > m_unk_8e8;   // +0x8e8 (init 0x14167de50(p,10)); head probed by vfunc_103
    CStringW m_strW918;                 // +0x918
    NiPoint3 m_pos920;                  // +0x920 = ZERO
    float m_f92c;                       // +0x92c = 1.0
    float m_f930;                       // +0x930 = 1.0
    float m_f934;                       // +0x934 = 0
    float m_f938;                       // +0x938 = 1.0
    CString m_str940;                   // +0x940 = ""
    CString m_str948;                   // +0x948 = ""
    CString m_str950;                   // +0x950
    CString m_str958;                   // +0x958 = ""
    CString m_str960;                   // +0x960 = ""
    int m_unk_968;                      // +0x968
    Timer m_timer970;                   // +0x970
    int m_unk_9a8;                      // +0x9a8
    efd::Point3 m_pos9ac;               // +0x9ac = ZERO (shadow ground point)
    NiPoint3 m_pos9b8;                  // +0x9b8 (init 0x1402bd040)
    unsigned short m_unk_9c4;           // +0x9c4 ground material kind
    float m_f9c8;                       // +0x9c8 (FLT_MAX / 0; shadow argument)
    float m_f9cc;                       // +0x9cc = 0
    bool m_b9d0;                        // +0x9d0 = 1
    bool m_b9d1;                        // +0x9d1 = 1
    CString m_str9d8;                   // +0x9d8 = "default"
    CString m_str9e0;                   // +0x9e0
    Timer m_timer9e8;                   // +0x9e8
    float m_afA20[4];                   // +0xa20 "FA_Skin" floats extra data (FUN_141679fa0; not initialised by the ctor)
    CAtlArray<unsigned int> m_arrA30;   // +0xa30 effect handles (vfunc_73)
    int m_unk_a50;                      // +0xa50 = 1
    MS2Ptr<Unk_PCBaseComp_a58> m_spA58; // +0xa58
    MS2Ptr<Unk_PCBaseComp_a68> m_spA68; // +0xa68 (init 0x14167e0b0)
    MS2Ptr<Unk_PCBaseComp_a78> m_spA78; // +0xa78
    MS2Ptr<Unk_PCBaseComp_a88> m_spA88; // +0xa88
    MS2Ptr<Unk_PCBaseComp_a98> m_spA98; // +0xa98
    MS2Ptr<Unk_PCBaseComp_aa8> m_spAA8; // +0xaa8
    MS2Ptr<Unk_PCBaseComp_ab8> m_spAB8; // +0xab8
    MS2Ptr<Unk_PCBaseComp_ac8> m_spAC8; // +0xac8 (init 0x14167e090)
    UISwfEntity* m_unk_ad8;             // +0xad8 = 0 (the dtor unregisters it from the UISwfEntityManager)
    egf::EntityID m_unk_ae0;            // +0xae0 (init 0x1408995b0, then 0x140899bd0(p, 0x143ae3278)); EntityID per Ridee
    NiPoint3 m_posAE8;                  // +0xae8 (= ZERO)
    int m_unk_af4;                      // +0xaf4 = 0x7fffffff
    int m_unk_af8;                      // +0xaf8
    MS2Ptr<RideOnAction> m_spB00;       // +0xb00 (init 0x1407810b0(p,0)) the pending ride-on action
    efd::SmartPointer<Ridee> m_spB10;   // +0xb10 the mount (ctor 0x140963df0(p,0), dtor 0x1409648b0)
    MS2Ptr<Unk_PCBaseComp_b18> m_spB18; // +0xb18
    CAtlMap<unsigned int, int> m_mapB28;   // +0xb28 (17 bins, .75/.25/2.25, block 10; init 0x140163400)
    int m_unk_b70;                      // +0xb70
    __int64 m_nUidB78;                  // +0xb78 (FUN_141676a50: the +0xca8 key)
    int m_unk_b80;                      // +0xb80
    ATL::CRBMap<CString, efd::SmartPointer<NiAVObject> > m_unk_b88;   // +0xb88 (init 0x14167deb0(p,10)); node map per Ridee
    ATL::CRBMap<CString, efd::SmartPointer<NiAVObject> > m_unk_bb8;   // +0xbb8 (init 0x14167deb0(p,10)); second node map
    efd::SmartPointer<NiAVObject> m_spBE8;   // +0xbe8 (init 0x14097eba0(p,0))
    float m_fBF0;                       // +0xbf0 (FUN_1410a7600 / FUN_1410a77e0)
    NiPoint3 m_posBF4;                  // +0xbf4 = ZERO
    int m_unk_c00;                      // +0xc00
    int m_unk_c04;                      // +0xc04 = 1
    Unk_PCBaseFlags m_unk_c08;          // +0xc08 hide reasons
    int m_unk_c0c;                      // +0xc0c
    efd::Point3 m_posC10;               // +0xc10 = ZERO (fall start height)
    efd::Point3 m_posC1C;               // +0xc1c the move requested this frame (vfunc_68)
    efd::Point3 m_posC28;               // +0xc28 the body position before this frame's move
    efd::SmartPointer<NiAVObject> m_spC38;  // +0xc38 (init 0x14097eba0(p,0))
    efd::SmartPointer<NiAVObject> m_spC40;  // +0xc40 (init 0x14097eba0(p,0)) attached under "Eff_UI"
    int m_unk_c48;                      // +0xc48 = 5
    MS2Ptr<StateData> m_unk_c50;        // +0xc50 state request queued before the model loads (init 0x14167e100(p,0))
    int m_unk_c60;                      // +0xc60
    int m_unk_c64;                      // +0xc64
    int m_unk_c68;                      // +0xc68
    Timer m_timerC70;                   // +0xc70 (armed 1000 ms)
    CAtlMap<__int64, int> m_mapCA8;     // +0xca8 item uid -> n (init 0x140c69c80)
    std::map<int, std::map<CString, std::vector<unsigned int> > > m_mapCF0;   // +0xcf0 (init 0x14167e4b0) key -> prefixed sequence name -> animation ids
    MS2Ptr<Unk_PCBaseActions> m_spD00;  // +0xd00 (init 0x14094d440 = MS2Ptr()); vfunc_123 looks up here (0x14094e040 = ->)
    MS2Ptr<Unk_PCBaseFxSource> m_spD10; // +0xd10 (init 0x1411bf870)
    int m_unk_d20;                      // +0xd20
    std::vector<unsigned> m_vecD28;     // +0xd28 (init 0x140182ed0)
};
MS2_CHECK_SIZE(PCBase, 0xd40);
MS2_CHECK_OFFSET(PCBase, m_spStateMgr, 0x140);
MS2_CHECK_OFFSET(PCBase, m_f164, 0x164);
MS2_CHECK_OFFSET(PCBase, m_f178, 0x178);
MS2_CHECK_OFFSET(PCBase, m_unk_1c0, 0x1c0);
MS2_CHECK_OFFSET(PCBase, m_unk_620, 0x620);
MS2_CHECK_OFFSET(PCBase, m_unk_ae0, 0xae0);
MS2_CHECK_OFFSET(PCBase, m_unk_508, 0x508);
MS2_CHECK_OFFSET(PCBase, m_spB10, 0xb10);
MS2_CHECK_OFFSET(PCBase, m_unk_c08, 0xc08);
MS2_CHECK_OFFSET(PCBase, m_unk_c0c, 0xc0c);
MS2_CHECK_OFFSET(PCBase, m_unk_c50, 0xc50);
MS2_CHECK_OFFSET(PCBase, m_unk_b88, 0xb88);
MS2_CHECK_OFFSET(PCBase, m_colorBoost, 0x648);
MS2_CHECK_OFFSET(PCBase, m_pushControl, 0x690);
MS2_CHECK_OFFSET(PCBase, m_unk_748, 0x748);
MS2_CHECK_OFFSET(PCBase, m_unk_8e8, 0x8e8);
MS2_CHECK_OFFSET(PCBase, m_strW918, 0x918);
MS2_CHECK_OFFSET(PCBase, m_str940, 0x940);
MS2_CHECK_OFFSET(PCBase, m_timer970, 0x970);
MS2_CHECK_OFFSET(PCBase, m_str9d8, 0x9d8);
MS2_CHECK_OFFSET(PCBase, m_timer9e8, 0x9e8);
MS2_CHECK_OFFSET(PCBase, m_arrA30, 0xa30);
MS2_CHECK_OFFSET(PCBase, m_spA58, 0xa58);
MS2_CHECK_OFFSET(PCBase, m_spAA8, 0xaa8);
MS2_CHECK_OFFSET(PCBase, m_spB18, 0xb18);
MS2_CHECK_OFFSET(PCBase, m_mapB28, 0xb28);
MS2_CHECK_OFFSET(PCBase, m_spBE8, 0xbe8);
MS2_CHECK_OFFSET(PCBase, m_posC28, 0xc28);
MS2_CHECK_OFFSET(PCBase, m_timerC70, 0xc70);
MS2_CHECK_OFFSET(PCBase, m_mapCA8, 0xca8);
MS2_CHECK_OFFSET(PCBase, m_spD00, 0xd00);
MS2_CHECK_OFFSET(PCBase, m_vecD28, 0xd28);
