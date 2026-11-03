// unit_1413a9df0.h - unit-local views of the exe objects and unrecovered callees shared by the parts of unit_1413a9df0 (the
// CGuideCondition* methods). NOT an original header.
#pragma once

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/xmlattr.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The local player: only the position getter and the level getter.
class Unk_G9Player
{
public:
    virtual ~Unk_G9Player();
    virtual void Unk_Slot1();
    virtual void Unk_Slot2();
    virtual void Unk_Slot3();
    virtual void Unk_Slot4();
    virtual void Unk_Slot5();
    virtual void Unk_Slot6();
    virtual void Unk_Slot7();
    virtual void Unk_Slot8();
    virtual void Unk_Slot9();
    virtual void Unk_Slot10();
    virtual void Unk_Slot11();
    virtual void Unk_Slot12();
    virtual void Unk_Slot13();
    virtual void Unk_Slot14();
    virtual void Unk_Slot15();
    virtual void Unk_Slot16();
    virtual void Unk_Slot17();
    virtual Vector3 vfunc_18();
    virtual void Unk_Slot19();
    virtual void Unk_Slot20();
    virtual void Unk_Slot21();
    virtual void Unk_Slot22();
    virtual void Unk_Slot23();
    virtual void Unk_Slot24();
    virtual void Unk_Slot25();
    virtual void Unk_Slot26();
    virtual void Unk_Slot27();
    virtual void Unk_Slot28();
    virtual void Unk_Slot29();
    virtual void Unk_Slot30();
    virtual void Unk_Slot31();
    virtual void Unk_Slot32();
    virtual void Unk_Slot33();
    virtual void Unk_Slot34();
    virtual void Unk_Slot35();
    virtual void Unk_Slot36();
    virtual void Unk_Slot37();
    virtual void Unk_Slot38();
    virtual void Unk_Slot39();
    virtual void Unk_Slot40();
    virtual void Unk_Slot41();
    virtual void Unk_Slot42();
    virtual void Unk_Slot43();
    virtual void Unk_Slot44();
    virtual void Unk_Slot45();
    virtual void Unk_Slot46();
    virtual void Unk_Slot47();
    virtual void Unk_Slot48();
    virtual void Unk_Slot49();
    virtual void Unk_Slot50();
    virtual void Unk_Slot51();
    virtual void Unk_Slot52();
    virtual void Unk_Slot53();
    virtual void Unk_Slot54();
    virtual void Unk_Slot55();
    virtual void Unk_Slot56();
    virtual void Unk_Slot57();
    virtual void Unk_Slot58();
    virtual void Unk_Slot59();
    virtual void Unk_Slot60();
    virtual void Unk_Slot61();
    virtual void Unk_Slot62();
    virtual void Unk_Slot63();
    virtual void Unk_Slot64();
    virtual int vfunc_65();
    virtual void Unk_Slot66();
    virtual void Unk_Slot67();
    virtual void Unk_Slot68();
    virtual void Unk_Slot69();
    virtual void Unk_Slot70();
    virtual void Unk_Slot71();
    virtual void Unk_Slot72();
    virtual void Unk_Slot73();
    virtual void Unk_Slot74();
    virtual void Unk_Slot75();
    virtual void Unk_Slot76();
    virtual void Unk_Slot77();
    virtual unsigned short vfunc_78();
};

// The map info of the player (continent code lookup).
template <class T> class MS2Ptr;
class CFieldDataCli;

// An object reference found in the world.
class Unk_WsB_Prop;
class CInteractObject { public: Vector3 GetPos(); int FUN_1413b5600(); };

class WorldService   // C3: member view
{
public:
    static WorldService* GetInstance();
    void* FUN_141bd0cc0();                              // the local player
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();
    MS2Ptr<Unk_WsB_Prop> FUN_141bc6510(Vector3 pos, int nId);
};

// The guide manager and the guide entry reference.
class Unk_G9GuideEntry { public: void* m_p0; void* m_p1; void* m_p2; int m_n18; int m_n1c; };   // m_n1c: tested by 0x1413aa8f0
MS2_CHECK_OFFSET(Unk_G9GuideEntry, m_n1c, 0x1c);
class Unk_Restrictions* FUN_1409331e0();

// The home (the player's ugc house).
class Unk_G9Home
{
public:
    void* FUN_1410b9850(int nItemId);
    int FUN_1410b9a50();
    int FUN_1410b9950(int nIconType);
};
class Unk_AkoHouseSvc { public: static Unk_AkoHouseSvc* GetInstance(); };
class Unk_SingletonObj* FUN_140939a00();                // the ugc market
class Unk_NametagTrophy* FUN_1406c7600();               // the trophy manager
class Unk_G9ItemRec { public: void* m_p[0x38]; int m_n1c0; int m_nValue; };                          // +0x1c4
MS2_CHECK_SIZE(Unk_G9ItemRec, 0x1c8);

class Unk_SoundSink* FUN_1409331f0();   // the key binds (C3: was void*)
void* FUN_1413b1c60(const CStringA& strName);           // the dialog of a name
void* FUN_1413b1b20(unsigned nUIId);                    // the chat emoticon dialog
void* FUN_1413b1bc0(unsigned nUIId);                    // the enchant dialog
int FUN_1413b1f30(Unk_140165cf0* pElem, const char* pszName, int& nOut);
void* FUN_14136f3e0(int nUIId);                    // the dialog of a ui id
CStringA StringFormat(const char* format);

struct Unk_PtrB;
extern ATL::CAtlArray<Unk_PtrB*> DAT_143ab3268;         // the owned titles
extern __int64 DAT_143ab2898;                           // the money

Unk_GcCondRef FUN_1413a52c0(Unk_140165cf0* pElem);      // builds the condition of a <condition> element
int FUN_1413a5570(CGuideCondition* pCond);              // runs a nested condition's test

int FUN_1413b1d00(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptInt& oOut);
int FUN_1413b1e70(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptVec3& oOut);
int FUN_1413b1ed0(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptBool& oOut);
bool FUN_140d1a9d0(const Unk_GcOptInt* pOpt);                   // Nullable<int>::HasValue (another obj)
bool Unk_GcIntIsNull(const Unk_GcOptInt* pOpt);                 // 0x1413b58a0 Nullable<int>::IsNull (#5)
int* FUN_1409393d0(Unk_GcOptInt* pOpt);                         // Nullable<int>::GetValue (achievemanager)
bool Unk_GcVec3IsNull(const Unk_GcOptVec3* pOpt);               // 0x1413b5870 Nullable<Point3>::IsNull (#5)
bool Unk_GcVec3HasValue(const Unk_GcOptVec3* pOpt);             // 0x1413b58d0 Nullable<Point3>::HasValue (#5)
bool Unk_GcBoolHasValue(const Unk_GcOptBool* pOpt);             // 0x1413b58e0 Nullable<bool>::HasValue (#5)
const int* FUN_1413989f0(const Unk_GcOptInt* pOpt);             // Nullable<int>::GetValue (guideentity#5)
CStringW FUN_14083bdc0(const CMsTime& t, bool bFlag, CStringW strDateSep, CStringW strTimeSep);
CStringW FUN_140719730(bool b);
unsigned __int64 FUN_140869440();                       // the server time
void FUN_1412751b0(const CStringW& text, int a);
