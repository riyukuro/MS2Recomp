// unit_1413a9df0.h - unit-local views of the exe objects and unrecovered callees shared by the parts of unit_1413a9df0 (the
// CGuideCondition* methods). NOT an original header.
#pragma once

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/xmlattr.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The position type vfunc_18 returns: the caller copies it into a Vector3 local (the exe slices it with rep movsb).
struct Unk_G9Pos : Vector3 {};

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
    virtual Unk_G9Pos vfunc_18();
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
void FUN_1408850f0(class Unk_G9MapInfo* pInfo);
class Unk_G9MapInfo
{
public:
    ~Unk_G9MapInfo() { FUN_1408850f0(this); }           // 0x1408850f0 (another obj)
    bool FUN_140965240(int nFlag);
    void* FUN_140885340();
    void* m_p0; void* m_p1;
};
MS2_CHECK_SIZE(Unk_G9MapInfo, 0x10);
int FUN_140375350(void* pCode);

// An object reference found in the world.
void FUN_1409649b0(class Unk_G9ObjRef* pRef);
class Unk_G9ObjRef
{
public:
    ~Unk_G9ObjRef() { FUN_1409649b0(this); }            // 0x1409649b0 (another obj)
    void* FUN_1409657e0();
    void* m_p0; void* m_p1;
};
MS2_CHECK_SIZE(Unk_G9ObjRef, 0x10);
class Unk_G9Obj { public: Vector3 FUN_1409673c0(); };
int FUN_1413b5600(Unk_G9Obj* pObj);                     // the interact state

class Unk_G9World
{
public:
    Unk_G9Player* FUN_141bd0cc0();                      // the local player
    Unk_G9MapInfo FUN_141bd30a0();
    Unk_G9ObjRef FUN_141bc6510(const Vector3& pos, int nId);
};
Unk_G9World* FUN_1403ed2d0();

// The guide manager and the guide entry reference.
class Unk_G9GuideEntry { public: void* m_p0; void* m_p1; void* m_p2; int m_n18; int m_n1c; };   // m_n1c: tested by 0x1413aa8f0
MS2_CHECK_OFFSET(Unk_G9GuideEntry, m_n1c, 0x1c);
void FUN_141397db0(class Unk_G9GuideRef* pRef);
class Unk_G9GuideRef
{
public:
    ~Unk_G9GuideRef() { FUN_141397db0(this); }          // 0x141397db0 (another obj)
    void* FUN_1413b4130() const;                        // the held entry (0x1413b4130)
    Unk_G9GuideEntry* FUN_141398900();
    void* m_p0; Unk_G9GuideEntry* m_pEntry;
};
MS2_CHECK_SIZE(Unk_G9GuideRef, 0x10);
class Unk_G9GuideMgr
{
public:
    Unk_G9GuideRef FUN_14138b990(int nGuideId);
    bool FUN_14138caa0(int nGuideId);                   // cleared
};
Unk_G9GuideMgr* FUN_1409331e0();

// The home (the player's ugc house).
class Unk_G9Home
{
public:
    void* FUN_1410b9850(int nItemId);
    int FUN_1410b9a50();
    void* FUN_1410b8ab0(const Vector3& pos);
    int FUN_1410b9950(int nIconType);
};
Unk_G9Home* FUN_1409670e0();
int FUN_1408b4f20(void* pCubeObj);
class Unk_G9ItemRec { public: void* m_p[0x38]; int m_n1c0; int m_nValue; };                          // +0x1c4
MS2_CHECK_SIZE(Unk_G9ItemRec, 0x1c8);
class Unk_G9ItemRef
{
public:
    Unk_G9ItemRec* FUN_1401b52a0();
    ~Unk_G9ItemRef() { FUN_1401b50d0(); }                // 0x1401b50d0 (another obj)
    void FUN_1401b50d0();
    void* m_p0; void* m_p1;
};
MS2_CHECK_SIZE(Unk_G9ItemRef, 0x10);
Unk_G9ItemRef FUN_14053f870(int nItemId);

void* FUN_1406c7600();                                  // the trophy manager
int FUN_140936740(void* pMgr, unsigned __int64 nPacked);
void* FUN_1409331f0();                                  // the key binds
int FUN_14142dc50(void* pBinds, int nSlot);
void* FUN_140939a00();                                  // the ugc market
__int64 FUN_140d56470(void* pMarket);
void* FUN_1409eed40();                                  // the manufacture book
int FUN_140d513c0(void* pBook);
void* FUN_1413b1c60(const CStringA& strName);           // the dialog of a name
// A ref-counted value handle of the dialog trees (assignment 0x1413b40b0, release 0x140d03070).
class Unk_GcNode;
class Unk_G9Inner;
class Unk_G9Val
{
public:
    Unk_G9Val(int nNull);                                   // 0x140d02f80 (another obj)
    Unk_G9Val(int nIdx, Unk_GcNode& node);                  // 0x140d01be0 (another obj)
    ~Unk_G9Val() { FUN_140d03070(); }                       // 0x140d03070 (another obj)
    void FUN_140d03070();
    Unk_G9Val& FUN_1413b40b0(const Unk_G9Val& rhs);         // operator= (#4 defines it as Unk_GcSmartRef's)
    void* FUN_140d031f0();
    Unk_G9Inner* FUN_140d03230();
    bool FUN_140d03130(int nNull);                          // IsNull
    void* m_p0; void* m_p1;
};
MS2_CHECK_SIZE(Unk_G9Val, 0x10);
// The leaf value handle of a dialog tree (release 0x140acd6e0).
class Unk_G9Leaf
{
public:
    ~Unk_G9Leaf() { FUN_140acd6e0(); }                      // 0x140acd6e0 (another obj)
    void FUN_140acd6e0();
    bool FUN_140bb6090(int nNull);                          // IsNull
    void* FUN_140acd9e0();
    void* m_p0; void* m_p1;
};
MS2_CHECK_SIZE(Unk_G9Leaf, 0x10);
// A dialog tree node: the child lookups by name.
class Unk_G9Inner
{
public:
    Unk_G9Leaf FUN_140acce30(const CStringA& strName);
    Unk_G9Val FUN_1413b19d0(const CStringA& strName);      // (#6)
    Unk_GcNode FUN_1422baa20(const char* pszName);
    char m_pad[0x18]; int m_n18;
};
class Unk_G9TreeList
{
public:
    bool FUN_140ba28d0(int nNull);                          // IsNull
    Unk_G9Inner* FUN_1409ee290();
};
// The dialog side of the tree lookups (the tree list at +0x30).
class Unk_G9TreeDlg
{
public:
    Unk_G9Val FUN_1413b1a90(const CStringA& strChild);      // (#6)
    char m_pad[0x30]; Unk_G9TreeList m_list;
};
void* FUN_1413b1b20(unsigned nUIId);                    // the chat emoticon dialog
void* FUN_1413b1bc0(unsigned nUIId);                    // the enchant dialog
int FUN_1413b1f30(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_141a75840(void* pDialog);
void* FUN_14136f3e0(unsigned nUIId);                    // the dialog of a ui id
int FUN_14195b950(void* pDialog);
CStringA FUN_141388650(const char* psz);

class Unk_G9U32Arr { public: size_t FUN_140186270(); };
extern Unk_G9U32Arr DAT_143ab3268;                      // the owned titles
extern __int64 DAT_143ab2898;                           // the money

Unk_GcCondRef FUN_1413a52c0(Unk_140165cf0* pElem);      // builds the condition of a <condition> element
int FUN_1413a5570(CGuideCondition* pCond);              // runs a nested condition's test

int FUN_1408736d0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);
int FUN_140873600(Unk_140165cf0* pElem, const char* pszName, Unk_GcTime& tOut);
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
CStringW FUN_14083bdc0(const Unk_GcTime& t, bool bFlag, CStringW strDateSep, CStringW strTimeSep);
CStringW FUN_140719730(bool b);
unsigned __int64 FUN_140869440();                       // the server time
void FUN_1412751b0(const CStringW& text, int a);
