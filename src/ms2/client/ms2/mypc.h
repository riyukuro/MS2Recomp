// mypc.h - MyPC (efd RTTI "MyPC", class id 0x06200004): the local player's character actor. Derives PC and
// IMessageListener (+0x12e0, the message box answers). Owning unit: ?\mypc.cpp (0x141520680-0x141538060).
// Header name assumed from the unit path.
//
// Size 0x1808 (??_G 0x141533430). vftables: primary 0x142f29f88 (147 slots, PC's), CallbackObject 0x142f2a428
// (dtor thunk 0x1415333dc), IMessageListener 0x142f2a460 (OnMessage 0x141520cc0).
// Members: proven types where known, otherwise unit-local views named after their ctor VA. Heap-only.
#pragma once
#include <set>
#include <list>
#include <atlcoll.h>
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/client/ms2/cubecraft_1.h"     // StateLocalController
#include "ms2/client/ms2/clonepc.h"         // Unk_CloneTimer

class CInPacket;
class CEquipItem;
class CItem;
class CGetExp;              // RTTI CGetExp (0x50): the exp gain popup (?\getexp.cpp)
class CHomePrivilege;       // commonfiles\homeprivilege.cpp (0x20, CPtred)
class Unk_MyPCSkillSlots;   // = CSkillSystem (scenestategame.cpp / placeholder mypc.h view)
class Unk_MyPCStatPoints;
class Unk_MyPCComp1618;     // MS2Ptr at +0x1618 (null ctor 0x1415324e0, dtor 0x14050de40)

// The member at +0x12e8: a StateLocalController whose records live on the base (state.cpp declares them on the
// PcGuide subclass). Ctor 0x1417b73c0, implicit dtor 0x1410a6dc0 (COMDAT in cubecraft_1).
class Unk_StateArg22;
class Unk_MyPCStateCtl : public StateLocalController
{
public:
    Unk_MyPCStateCtl();                                     // 0x1417b73c0
    ~Unk_MyPCStateCtl();                                    // 0x1410a6dc0
    void FUN_1417b7430(PCBase* pOwner);                     // init with the owner
    void FUN_1417b7450();                                   // drop the current and queued records
    void FUN_1417b76b0(float fTime);                        // advance with the game time
    int FUN_1417b7490();                                    // a record is due
    MS2Ptr<Unk_StateArg22> FUN_1417b7620();                 // copy of the current record
    void FUN_1417b7670(Unk_StateArg22* pRec);               // set the current record
    unsigned char m_body[0x48];                             // +0x08 records list, current record, owner
};

// The member at +0x1338: the action key table (ctor 0x140951c70 in ?\actionkeyobject.cpp, dtor 0x140952e70).
class Unk_MyPCActionKeys
{
public:
    Unk_MyPCActionKeys();                                   // 0x140951c70
    ~Unk_MyPCActionKeys();                                  // 0x140952e70
    void FUN_140952ef0();
    unsigned char m_body[0xa0];                             // three CAtlMaps of actions by key
};

// The skill system at +0x13d8 (RTTI CSkillSystem, ?\skillslot.cpp; ctor 0x1417646d0, dtor 0x141764900).
class CSkillSystem
{
public:
    CSkillSystem();                                         // 0x1417646d0
    ~CSkillSystem();                                        // 0x141764900
    void FUN_141764a80(class MyPC* pOwner);                 // init with the owner
    void FUN_141766af0(float fDelta);                       // per-frame update
    MS2Ptr<class CSkillRecord> FUN_141765570(struct Unk_InventorySkillRequest& kReq);   // build the record of a request
    void FUN_141767f80(int nSkillId);                       // add a temporary skill
    void FUN_1417683d0();                                   // refresh the skill slots
    MS2Ptr<class Unk_MyPCSkillSet> FUN_141768380();         // the temporary (ridee) skill set, if any
    void FUN_141768100(int nSkillId);                       // remove a temporary skill
    MS2Ptr<class CSkillRecord> FUN_141764e30(struct Unk_InventorySkillRequest& kReq);   // cast a request
    MS2Ptr<class Unk_PCBaseComp_b18> FUN_141764e30(struct Unk_InventorySkillRequest* pReq);   // the same, the record as the casting skill (vfunc_104)
    int FUN_1417674a0(int n);                               // the pending skill id
    float FUN_141765fe0(int nSkillId, int n);              // the cooldown left of nSkillId
    int FUN_141768bd0(MS2Ptr<class CSkillRecord> spRecord); // the record may be cast during its cooldown
    void FUN_141766cc0(MS2Ptr<class CSkillRecord> spRecord);
    void FUN_141767990(int nSkillId, unsigned short nLevel); // start the cooldown
    int FUN_141768fb0(unsigned int nSkillId, unsigned short nLevel);   // uses left
    void FUN_1417664e0(int nSkillId, int nCoolSkillId, float fCool, float fCombo, int bCombo);   // start a cooldown
    void FUN_141768900(MS2Ptr<class CSkillRecord> spRecord);
    void* m_vfptr_unused_;                                  // +0x00 (vftable; slots unrecovered)
    unsigned char m_body[0x1e8];
};

// The pending portal move at +0x17a0 (0x20; ctor 0x1415328a0).
struct Unk_MyPCPortalMove
{
    // @0x1415328a0
    Unk_MyPCPortalMove() : m_nPortalId(0), m_nA(0), m_nB(0), m_nC(0), m_nD(0), m_bWithPwd(0) {}
    // @0x1415335d0
    void Reset()
    {
        m_nPortalId = 0;
        m_nA = 0;
        m_nB = 0;
        m_nC = 0;
        m_nD = 0;
        m_bWithPwd = 0;
    }
    int m_nPortalId;                                        // +0x00
    int m_nA;                                               // +0x04
    int m_nB;                                               // +0x08
    __int64 m_nC;                                           // +0x10
    int m_nD;                                               // +0x18
    int m_bWithPwd;                                         // +0x1c
};

// The notify sent once the local character is ready (0x18).
class NotifyCompleteMyPC : public NotifyObject
{
public:
    // @0x141532780
    NotifyCompleteMyPC() {}
    // implicit virtual dtor 0x141532ce0 (no vptr store; pinned)
    virtual CStringW vfunc_1();                             // 0x140db4550 (notify name, other unit)
};

// The notify of a used skill (0x20).
class NotifyUseSKill : public NotifyObject
{
public:
    // @0x1415327b0
    NotifyUseSKill(int nSkillId, short nLevel) : m_nSkillId(nSkillId), m_nLevel(nLevel) {}
    // implicit virtual dtor 0x141532d00 (pinned)
    virtual CStringW vfunc_1();                             // 0x140db4670 (notify name, other unit)
    int m_nSkillId;                                         // +0x18
    short m_nLevel;                                         // +0x1c
};

// The key of the lapenshard slot maps at +0x16b0 / +0x17c0 (an enum: CAtlMap passes it by reference).
enum Unk_MyPCLapenSlot { MYPC_LAPEN_SLOT_NONE = 0 };

// The house setting sent by FUN_141530720 (compared as a byte: a scoped enum over unsigned char).
enum class Unk_MyPCHouseSetting : unsigned char { Kind0 = 0, Kind1 = 1, Kind2 = 2 };

class MyPC : public PC, public IMessageListener
{
    EE_DECLARE_CLASS1(MyPC, 0x06200004, PC);   // ClassInfo 0x143ae10b0 (setup 0x141536810)

public:
    MyPC();                                                 // 0x141520680
    virtual ~MyPC();                                        // 0x141520ab0

    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0x141520cc0

    virtual void vfunc_22(const efd::Point3& kPos);         // 22 0x1415213b0
    virtual int vfunc_10();                                 // 10 0x141521430
    virtual void vfunc_12();                                // 12 0x141521560
    virtual void vfunc_14();                                // 14 0x141521630
    virtual int vfunc_108();                                // 108 0x141521650
    virtual int vfunc_63();                                 // 63 0x141521670
    virtual void vfunc_110();                               // 110 0x1415216a0
    virtual void vfunc_66(int n);                           // 66 0x1415216c0
    virtual void vfunc_90(void* p);                         // 90 0x141521760
    virtual void vfunc_91(void* p);                         // 91 0x1415219a0
    virtual MS2Ptr<Unk_PCBaseComp_b18> vfunc_104(bool a, bool b, bool c);  // 104 0x1415219d0
    virtual bool vfunc_102(MS2Ptr<CSkillRecord> skill);     // 102 0x141521fc0
    virtual void vfunc_59(int nState, StateData* pData, int nSub, int bForce);   // 59 0x141522c60
    virtual int vfunc_58();                                 // 58 0x141522cc0
    virtual void vfunc_67(efd::Point3* pDir, efd::Point3* pSide);// 67 0x141522ce0
    virtual void vfunc_125(MS2Ptr<Unk_PCArg125> p);         // 125 0x141522d40
    virtual void vfunc_127(CItem* pItem, int n);            // 127 0x141522eb0
    virtual void vfunc_128(CItem* pItem, int n);            // 128 0x141522f60
    virtual void vfunc_94(int n);                           // 94 0x141523010
    virtual void vfunc_112(void* p, int n);                 // 112 0x1415231f0
    virtual void vfunc_113(void* p);                        // 113 0x1415232d0
    virtual MS2Ptr<Unk_PCBaseComp_a58> vfunc_80();          // 80 0x141523390
    virtual MS2Ptr<Unk_PCBaseComp_a68> vfunc_81();          // 81 0x141523480
    virtual MS2Ptr<Unk_PCBaseComp_a88> vfunc_83();          // 83 0x141523570
    virtual MS2Ptr<Unk_PCBaseComp_ab8> vfunc_86();          // 86 0x141523630
    virtual UISwfEntity* vfunc_88();                        // 88 0x141523670
    virtual int vfunc_137();                                // 137 0x141523720
    virtual void vfunc_135(int a, int b, void* p);          // 135 0x1415238d0
    virtual CStringW vfunc_134();                           // 134 0x141523ae0
    virtual bool vfunc_146();                               // 146 0x141523b70
    virtual void vfunc_120(MS2Ptr<RideOnAction> spAction);  // 120 0x14152c460 (by value)
    virtual void vfunc_121(MS2Ptr<RideOffAction> spAction);   // 121 0x14152c670
    virtual void vfunc_53(float f);                         // 53 0x141530950
    virtual void vfunc_49();                                // 49 0x141531310
    virtual void vfunc_144();                               // 144 0x1415313f0
    virtual void vfunc_47(bool b);                          // 47 0x141531410
    virtual bool vfunc_56(float f);                         // 56 0x141531430
    virtual bool vfunc_55(float a, float b);                // 55 0x141531450
    // @0x141536690
    virtual void vfunc_24(int) { m_unk_40 = 0; }            // 24 (inline)

    // non-virtual members used by other units (placeholder mypc.h)
    void FUN_14152a4a0(PCBase* pTarget);                    // observe pTarget
    void FUN_14152a960();                                   // stop observing
    void FUN_14152a360(PCBase* pTarget);                     // point the construction guide camera at pTarget
    void FUN_14152a700(PCBase* pTarget);                     // fly the camera to the construction guide pTarget
    void FUN_14152a640(int nTeam);                          // observe a guild team
    void FUN_14152a2f0(int n);
    CSkillSystem* FUN_141523bc0();                          // the skill system
    void FUN_141523ba0();
    Unk_MyPCStateCtl* FUN_141523be0();                      // the state controller
    MS2Ptr<Unk_PCBaseComp_b18> FUN_141523c00();
    Unk_MyPCComp1618* FUN_141523c50();
    void FUN_141523c80();                                   // pick the housing cube under the player
    int FUN_141527120();
    int FUN_141527160(int nNext);
    bool FUN_141527280();
    int FUN_141527650(int nKind);                           // the skill condition nKind holds (else a notice)
    int FUN_1415278d0(void* p);
    int FUN_141527920(void* p);
    int FUN_141527960();
    int FUN_141527c50(int nItemId);                         // the item is worn or in the item list
    int FUN_141527e00();                                    // no house
    int FUN_141527e60();
    int FUN_141527eb0();
    int FUN_141527ed0();
    int FUN_141527f60();
    int FUN_141527f80(int* pMapId);
    int FUN_141528020(efd::Point3& kPos);
    int FUN_141528140();
    int FUN_141528160();
    CStringW FUN_1415281c0();
    CStringW FUN_141528330();
    int FUN_141528970();                                    // open the item remake option talk
    int FUN_1415283c0(int nKind);                           // enter the home convenience state
    int FUN_1415286a0();                                    // enter the home convenience state 3
    int FUN_141525480(int nSkillId, bool bRemap);           // the skill (switched by buffs) may be cast
    void FUN_141526c80(int& nSkillId, unsigned short& nLevel);   // switch the skill by the casting skill / buffs
    int FUN_141529620();
    int FUN_141529ae0(int nMapId, int nA, int nB, __int64 nC);   // check the portal lock, then stop
    void FUN_14152a040();
    void FUN_14152a240(int nId);
    void FUN_14152a2b0(int n);
    void FUN_14152a2d0(int n);
    void FUN_14152a310(MS2Ptr<Unk_PCBaseComp_b18> sp);
    int FUN_14152e060();
    void FUN_14152e240(unsigned n);
    int FUN_14152e280(unsigned n);
    int FUN_14152e950();
    bool FUN_1415275b0(short nKind);                         // the burning event is active for nKind
    int FUN_1415279d0(PCBase* pOther);                       // can ride along with pOther (buddy, party or guild)
    egf::Entity* FUN_141529750();                            // the telescope in reach (with a view list)
    egf::Entity* FUN_141529900();                            // the telescope in reach, its views opened
    void FUN_14152b800(__int64 nItemUid);                    // request 0x78/1 for an inventory item
    void FUN_14152b8d0(__int64 nItemUid);                    // summon with an inventory item
    void FUN_14152aa90(MS2Ptr<CItem> spItem, int bConfirmed); // summon the pet of an item
    void FUN_14152ba80(MS2Ptr<CItem> spItem);               // use a mount item
    bool FUN_141526730(int bAuto, unsigned* pSlot);         // pick the quick slot to cast
    int FUN_141527b50(PCBase* pOther);                       // nothing blocks the flat line to pOther
    unsigned short FUN_141528b80(int nSkillId);             // the learned level of nSkillId (1 when not learned)
    int FUN_14152e970(int nId);                             // the free skill points of nId
    bool FUN_14152e7f0();                                   // a worn item still counts (not expired)
    size_t FUN_14152eb20();
    size_t FUN_14152eb50();
    void FUN_14152eb80();
    int FUN_14152ebd0();
    void FUN_14152ec40(__int64 n);
    void FUN_14152ec80(__int64 n);
    void FUN_14152ed60(const struct Unk_MyPCGameBegin* pData);   // the mark lists from the field entry data
    void FUN_14152ee60(CInPacket& packet);                  // the mark lists from a packet
    class CItem* FUN_14152efa0(__int64 nItemUid, __int64* pOwner);   // an item of the house owner on this account's plot
    void FUN_14152f140(__int64 nOwnerId);                   // return the locked items of a plot PC
    void FUN_14152f3c0();                                   // the same for every plot PC
    int FUN_14152feb0(int nMode, bool bPalette);            // request the cube build mode (packet 0x36)
    int FUN_14152c280(class RideOffAction* pAction);        // get off the ride
    void FUN_141530200();                                   // leave the cube build mode
    class Unk_PCCubeCraft* FUN_141530290();                 // the cube craft controller in the cube craft mode
    int FUN_141529a50(int nNpcId);                          // talk to the npc (0: the nearest talkable one)
    PCBase* FUN_141529640();
    void FUN_1415293b0();
    void FUN_14152dbc0();
    void FUN_14152e0c0();
    void FUN_14152e170(int nMode, int nArg);
    int FUN_14152ea50();
    void FUN_1415294f0(int nObjectId, __int64 nExp);                                // the nearest talkable npc
    void FUN_141529d90();                                   // request the house design mode (packet 0x6c 4)
    void FUN_141529e90();                                   // request the blueprint mode (packet 0x6c 5)
    bool FUN_141525580(MS2Ptr<class CSkillRecord> spRecord);   // the record may be cast now
    void FUN_141525ff0(MS2Ptr<class CSkillRecord> spRecord, float fElapsed);   // send the cast
    void FUN_141524a80(bool bForce);                        // stop moving for a cast
    void FUN_14152b2d0(__int64 nItemUid);                   // summon the pet of an inventory item
    MS2Ptr<CItem> FUN_14152e2f0(MS2Ptr<CItem> spItem);       // the worn item spItem would replace
    bool FUN_1415302e0(int nItemId);                         // the cube item is locked (housing level, achievement)
    void FUN_141523e60(CItem* pItem, int* pStatDiff, int* pSpecialDiff, int* pScoreDiff);   // the stat change of equipping pItem
    static void FUN_141531470(ATL::CAtlArray<MS2Ptr<CItem> >& aItems, int* pStats, int* pSpecials, int* pScore);   // sum the items' stats
    void FUN_14152dee0(int nId);                            // packet 0x40 3
    void FUN_14152df80();                                   // packet 0x40 4 (camera reset first)
    void FUN_14152dff0(unsigned char n);                    // packet 0x40 6
    // @0x140967010
    MS2Ptr<CHomePrivilege> FUN_140967010() { return m_spHomePrivilege; }   // COMDAT in actionkeyobject.cpp's range
    static void FUN_1415308d0();                            // reset the debug switches
    static void FUN_141530910(int n);
    static PCBase* FUN_141530930();                         // the local player
    void FUN_141530d70(double dTime);
    void FUN_141530db0();
    bool FUN_1415272b0();                                   // the worn weapon fits the job
    void FUN_1415310e0(std::list<class Unk_MyPCDropItem*>& lstDrops);   // pick up the drop items (packet 0x1d)
    int FUN_14152ecc0(__int64 n);
    int FUN_14152ed10(__int64 n);
    void FUN_141528c30(CInPacket& packet);
    void FUN_141528c90(efd::Point3 kPos, efd::Point3 kDir); // warp the ridee (ground snapped)
    void FUN_141528e50(efd::Point3 kPos, efd::Point3 kRot, int bFlyCamera);   // warp (and the ridee)
    int FUN_14152f860(unsigned int nKey);
    void FUN_141530700(int n);
    void FUN_141530720(Unk_MyPCHouseSetting nKind, CStringW strValue, unsigned char bFlag);   // house setting (packet 0x37 0x18)
    void FUN_14152f9e0();                                   // begin bulk update
    void FUN_14152f530(Unk_MyPCLapenSlot nSlot, unsigned nItemId, int bBulk);   // equip nItemId in nSlot
    void FUN_14152f620(Unk_MyPCLapenSlot nSlot);            // unequip nSlot
    unsigned FUN_14152f770(Unk_MyPCLapenSlot nSlot);        // the item in nSlot
    Unk_MyPCLapenSlot FUN_14152f7c0(unsigned nItemId);      // the slot of nItemId
    int FUN_14152f8b0(unsigned nItemId);                    // an item of the same group is equipped
    void FUN_14152f960(ATL::CAtlArray<unsigned int>& aOut); // the equipped item ids
    void FUN_14152fa20();                                   // end bulk update
    void FUN_14152fc20();                                   // poll the channel once a second
    unsigned short FUN_14152fce0(unsigned nGroup);          // the highest grade equipped in nGroup
    Unk_MyPCLapenSlot FUN_14152fd50(unsigned nItemId);      // the slot to equip nItemId into
    void FUN_141529c80(int nPortalId, int nA, int nB, __int64 nC, CStringW strPwd);   // password portal move
    void FUN_14152a0c0(int nPortalId, int nD, int nA, int nB, CStringW strA, CStringW strPwd);   // portal move
    int FUN_1415271e0(PCBase* pActor, struct Unk_MyPCSkillUse* pSkill);   // can the skill be used on pActor
    void FUN_141529fb0();                                   // request the field leave (packet 0x6c 6)
    void FUN_141524880(MS2Ptr<Unk_MyPCComp1618> sp);        // set m_sp1618
    int FUN_1415248d0(int nSide, int nType);                // sit (0xbadf0a13) or lie (0xc13e30c8) on a nearby object

    Unk_MyPCStateCtl m_kStateCtl;                           // +0x12e8
    Unk_MyPCActionKeys m_kActionKeys;                       // +0x1338
    CSkillSystem m_kSkillSystem;                            // +0x13d8
    CGetExp* m_pGetExp;                                     // +0x15c8 (created on the first exp gain)
    int m_n15d0;                                            // +0x15d0 = 0x7fffffff
    bool m_b15d4;                                           // +0x15d4
    bool m_b15d5;                                           // +0x15d5 (set by vfunc_110)
    bool m_b15d6;                                           // +0x15d6
    int m_n15d8;                                            // +0x15d8 (vfunc_22: not at the origin)
    int m_n15dc;
    int m_n15e0;                                            // +0x15e0
    int m_n15e4;                                            // +0x15e4
    int m_bMapDirty;                                        // +0x15e8 (set when a counted entry changes)
    int m_n15ec;                                            // +0x15ec
    int m_n15f0;                                            // +0x15f0
    std::set<unsigned> m_set15f8;                                // +0x15f8
    MS2Ptr<Unk_PCBaseComp_b18> m_sp1608;                    // +0x1608
    MS2Ptr<Unk_MyPCComp1618> m_sp1618;                      // +0x1618
    MS2Ptr<CHomePrivilege> m_spHomePrivilege;               // +0x1628
    PCBase* m_pObserved;                                    // +0x1638 the observed actor
    int m_n1640;                                            // +0x1640
    int m_n1644;                                            // +0x1644
    __int64 m_n1648;                                        // +0x1648
    ATL::CAtlList<__int64> m_list1650;                      // +0x1650
    ATL::CAtlList<__int64> m_list1680;                      // +0x1680
    ATL::CAtlMap<Unk_MyPCLapenSlot, unsigned int> m_map16b0;   // +0x16b0 slot -> item id
    ATL::CAtlMap<unsigned int, unsigned int> m_map16f8;     // +0x16f8 item id -> equipped count
    ATL::CAtlMap<unsigned int, unsigned short> m_map1740;   // +0x1740 item group -> highest grade
    Unk_CloneTimer m_timer1788;                             // +0x1788
    Unk_StreamPoint m_pos1790;                              // +0x1790
    int m_n179c;                                            // +0x179c
    Unk_MyPCPortalMove m_kPortalMove;                       // +0x17a0
    ATL::CAtlMap<Unk_MyPCLapenSlot, DWORD> m_map17c0;      // +0x17c0 slot -> tick of the last change
};
MS2_CHECK_OFFSET(MyPC, m_kStateCtl, 0x12e8);
MS2_CHECK_OFFSET(MyPC, m_kActionKeys, 0x1338);
MS2_CHECK_OFFSET(MyPC, m_kSkillSystem, 0x13d8);
MS2_CHECK_OFFSET(MyPC, m_pGetExp, 0x15c8);
MS2_CHECK_OFFSET(MyPC, m_set15f8, 0x15f8);
MS2_CHECK_OFFSET(MyPC, m_pObserved, 0x1638);
MS2_CHECK_OFFSET(MyPC, m_list1650, 0x1650);
MS2_CHECK_OFFSET(MyPC, m_map16b0, 0x16b0);
MS2_CHECK_OFFSET(MyPC, m_timer1788, 0x1788);
MS2_CHECK_OFFSET(MyPC, m_kPortalMove, 0x17a0);
MS2_CHECK_OFFSET(MyPC, m_map17c0, 0x17c0);
MS2_CHECK_SIZE(MyPC, 0x1808);
