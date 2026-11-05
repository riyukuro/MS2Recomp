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
template <class T> class MS2Ptr;

// The key of the lapenshard slot maps (as in ms2/client/ms2/mypc.h; no unit includes both headers)
enum Unk_MyPCLapenSlot { MYPC_LAPEN_SLOT_NONE = 0 };
// The house setting kind (as in ms2/client/ms2/mypc.h)
enum class Unk_MyPCHouseSetting : unsigned char { Kind0 = 0, Kind1 = 1, Kind2 = 2 };

class MyPC : public PCBase
{
public:
    // The real class id (client mypc.h EE_DECLARE_CLASS1): without it efd::DynamicCast<MyPC> tests PCBase's 0x06200013
    // and its COMDAT, when the linker keeps this view's copy, accepts every PC as the local player.
    static const efd::ClassID CLASS_ID = 0x06200004;
    MyPC();                                                 // 0x141520680
    int vfunc_116() override;                               // declared only so the class is concrete
    void StartObserving(PCBase* pTarget);                    // observe pTarget (guild battle, uipvpguildteamdialog)
    void StopObserving();                                   // stop observing
    void FUN_14152a2f0(int n);                              // scenestategame packet 0x35
    void FUN_141524a80(bool bForce);                        // stop moving for a cast (scenestategame)
    int FUN_141525480(int nSkillId, bool bRemap);           // the skill (switched by buffs) may be cast (as ms2/client/ms2/mypc.h)
    void FUN_141530720(Unk_MyPCHouseSetting nKind, CStringW strValue, unsigned char bFlag);   // house setting (packet 0x37 0x18)
    class CSkillSystem* FUN_141523bc0();                    // the skill slot set (skillslot.cpp, 0x141765de0 etc.)
    class StatePcGuideObjectController* FUN_141523be0();    // the guide object controller (scenestategame 0x1417127b0)
    MS2Ptr<class CStatPointManager> FUN_140c25130();        // the stat point manager (statpointmanager.cpp)
    void FUN_141661370(int a, int b, int c);                // PC member (scenestategame packet 0x83)
    void FUN_141528c30(CInPacket& packet);                  // scenestategame packet 0x135
    void FUN_141662850(__int64 nValue);                     // PC member (scenestategame packet 0xe0)
    void FUN_141662890(__int64 nValue);                     // PC member
    Unk_PCEquipSet* FUN_1416561a0();                        // PC member: the equip holder (scenestategame 0x141712fb0)
    void FUN_141528e50(efd::Point3 kPos, efd::Point3 kRot, int bFlyCamera);   // warp (mypc.cpp); scenestategame 0x141721a30
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 nItemUid);     // PC member: a worn item by uid (scenestategame 0x14173b420)
    void ClearLapenshards();                                   // begin bulk update (scenestategame 0x14173d2e0)
    void EquipLapenshard(Unk_MyPCLapenSlot nSlot, unsigned nItemId, int bBulk);   // equip nItemId in nSlot
    void FUN_14152fa20();                                   // end bulk update
    void UnequipLapenshard(Unk_MyPCLapenSlot nSlot);        // unequip nSlot
    int FUN_1416595d0();                                    // PC member: the cube craft mode (actionkeyobject.cpp)
    class Unk_MyPCEmotion* FUN_14165f100();                 // PC member: the playing emotion (stateemotionidle.cpp)
    class Unk_PCCubeCraft* GetActiveCubeCraft();                 // the cube craft (housing build) controller (scenestategame 0x69)
    bool FUN_1415302e0(int nItemId);                        // the cube item is locked (housing level, achievement)
    int FUN_141659690();                                    // PC member
    class UserUGCMapInfo* FUN_141523c50();                  // the owned house (UGC map) info, MS2Ptr at +0x1618
    void FUN_141524880(MS2Ptr<UserUGCMapInfo> spInfo);   // set it (mypc.cpp)
    int HasNoHome();
    int FUN_141527ed0();                                    // 0x141527ed0 (uirealestatedialog.cpp)
    CStringW GetHomeName();                                 // 0x141528330 the house name
    int FUN_141527160(int nNext);                           // 0x141527160
    int FUN_14152e950();                                    // 0x14152e950
    void SendRequestMoveFieldMode2(int nPortalId, int nA, int nB, __int64 nC, CStringW strPwd);   // 0x141529c80 password portal move
    void SendCraftModeOff();
    void FUN_141530700(int bFlag);
    void FUN_14152a2d0(int n);
    void FUN_141699a20();                                   // scenestategame OnAddUser
    void FUN_14152ed60(class Unk_UserProxy* pProxy);        // scenestategame OnAddUser
    void FUN_1416634a0(__int64 nCharId);                    // PC member (scenestategame OnAddUser)
    int FUN_141527eb0();                                    // (scenestategame storage update)
    int FUN_141529620();
    int FUN_14152e060();                                    // 0x14152e060 the id of the actor held (state 0x20), else 0 (scenestategame 0x79)
    MS2Ptr<CHomePrivilege> FUN_140967010();                 // 0x140967010 the house privileges (+0x1628; scenestategame taxi)
private:
    char m_pad[0x1808 - 0xd40];                             // unrecovered members
};
MS2_CHECK_SIZE(MyPC, 0x1808);
