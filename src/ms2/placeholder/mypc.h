// mypc.h - PLACEHOLDER for MyPC (efd RTTI name "MyPC", derives PCBase; ctor 0x141520680, 0x1808 bytes): the local
// player's character actor. NOT an original header; only the constructor is declared (members are unrecovered).
// Owning unit: ?\mypc.cpp.
#pragma once

#include "ms2/client/ms2/pcbase.h"

class CInPacket;
class CEquipItem;
struct Unk_PCEquipSet;
struct Vector3;
class UserUGCMapInfo;
class CHomePrivilege;                             // commonfiles\homeprivilege.cpp
template <class T> class Unk_BmPtr;               // blackmarketitemoption.h

class MyPC : public PCBase
{
public:
    MyPC();                                                 // 0x141520680
    int vfunc_116() override;                               // declared only so the class is concrete
    void FUN_14152a4a0(PCBase* pTarget);                    // observe pTarget (guild battle, uipvpguildteamdialog)
    void FUN_14152a960();                                   // stop observing
    void FUN_14152a2f0(int n);                              // scenestategame packet 0x35
    class Unk_MyPCSkillSlots* FUN_141523bc0();              // the skill slot set (skillslot.cpp, 0x141765de0 etc.)
    class StatePcGuideObjectController* FUN_141523be0();    // the guide object controller (scenestategame 0x1417127b0)
    MS2Ptr<class Unk_MyPCStatPoints> FUN_140c25130();       // the stat point manager (statpointmanager.cpp)
    void FUN_141661370(int a, int b, int c);                // PC member (scenestategame packet 0x83)
    void FUN_141528c30(CInPacket& packet);                  // scenestategame packet 0x135
    void FUN_141662850(__int64 nValue);                     // PC member (scenestategame packet 0xe0)
    void FUN_141662890(__int64 nValue);                     // PC member
    Unk_PCEquipSet* FUN_1416561a0();                        // PC member: the equip holder (scenestategame 0x141712fb0)
    void FUN_141528e50(Vector3 kPos, Vector3 kRot, int nFlag);   // scenestategame 0x141721a30
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 nItemUid);     // PC member: a worn item by uid (scenestategame 0x14173b420)
    void FUN_14152f9e0();                                   // begin bulk update (scenestategame 0x14173d2e0)
    void FUN_14152f530(int nA, int nB, int bBulk);          // set entry nA = nB
    void FUN_14152fa20();                                   // end bulk update
    void FUN_14152f620(int nA);                             // remove entry nA
    int FUN_1416595d0();                                    // PC member: the cube craft mode (actionkeyobject.cpp)
    class Unk_MyPCEmotion* FUN_14165f100();                 // PC member: the playing emotion (stateemotionidle.cpp)
    class Unk_PCCubeCraft* FUN_141530290();                 // the cube craft (housing build) controller (scenestategame 0x69)
    int FUN_141659690();                                    // PC member
    class UserUGCMapInfo* FUN_141523c50();                  // the owned house (UGC map) info, MS2Ptr at +0x1618
    void FUN_141524880(Unk_BmPtr<UserUGCMapInfo> spInfo);   // set it
    int FUN_141527e00();
    void FUN_141530200();
    void FUN_141530700(int bFlag);
    void FUN_14152a2d0(int n);
    void FUN_141699a20();                                   // scenestategame OnAddUser
    void FUN_14152ed60(class Unk_UserProxy* pProxy);        // scenestategame OnAddUser
    void FUN_1416634a0(__int64 nCharId);                    // PC member (scenestategame OnAddUser)
    int FUN_141527eb0();                                    // (scenestategame storage update)
    int FUN_14152e060();                                    // 0x14152e060 the id of the actor held (state 0x20), else 0 (scenestategame 0x79)
    MS2Ptr<CHomePrivilege> FUN_140967010();                 // 0x140967010 the house privileges (+0x1628; scenestategame taxi)
private:
    char m_pad[0x1808 - 0xd40];                             // unrecovered members
};
MS2_CHECK_SIZE(MyPC, 0x1808);
