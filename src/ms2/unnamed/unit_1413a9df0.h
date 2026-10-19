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
    virtual void Unk_Slot0();
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
    virtual Unk_StreamPoint vfunc_18();
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
class Unk_G9MapInfo
{
public:
    bool FUN_140965240(int nFlag);
    void* FUN_140885340();
    void* m_p0; void* m_p1; void* m_p2; void* m_p3;
};
MS2_CHECK_SIZE(Unk_G9MapInfo, 0x20);
void FUN_1408850f0(Unk_G9MapInfo* pInfo);
int FUN_140375350(void* pCode);

// An object reference found in the world.
class Unk_G9ObjRef
{
public:
    void* FUN_1409657e0();
    void* m_p0; void* m_p1;
};
MS2_CHECK_SIZE(Unk_G9ObjRef, 0x10);
void FUN_1409649b0(Unk_G9ObjRef* pRef);
class Unk_G9Obj { public: Unk_StreamPoint FUN_1409673c0(); };
int FUN_1413b5600(Unk_G9Obj* pObj);                     // the interact state

class Unk_G9World
{
public:
    Unk_G9Player* FUN_141bd0cc0();                      // the local player
    Unk_G9MapInfo FUN_141bd30a0();
    Unk_G9ObjRef FUN_141bc6510(const Unk_StreamPoint& pos, int nId);
};
Unk_G9World* FUN_1403ed2d0();

// The guide manager and the guide entry reference.
class Unk_G9GuideEntry { public: void* m_p0; void* m_p1; void* m_p2; int m_n18; int m_n1c; };   // m_n1c: tested by 0x1413aa8f0
MS2_CHECK_OFFSET(Unk_G9GuideEntry, m_n1c, 0x1c);
class Unk_G9GuideRef
{
public:
    Unk_G9GuideEntry* FUN_141398900();
    void* m_p0; Unk_G9GuideEntry* m_pEntry; void* m_p2; void* m_p3;
};
MS2_CHECK_SIZE(Unk_G9GuideRef, 0x20);
void FUN_141397db0(Unk_G9GuideRef* pRef);
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
    void* FUN_1410b8ab0(const Unk_StreamPoint& pos);
    int FUN_1410b9950(int nIconType);
};
Unk_G9Home* FUN_1409670e0();
unsigned __int64 FUN_1408b4f20(void* pCubeObj);
class Unk_G9ItemRec { public: void* m_p[0x38]; int m_n1c0; int m_nValue; };                          // +0x1c4
MS2_CHECK_SIZE(Unk_G9ItemRec, 0x1c8);
class Unk_G9ItemRef
{
public:
    Unk_G9ItemRec* FUN_1401b52a0();
    void FUN_1401b50d0();
    void* m_p0; void* m_p1;
};
MS2_CHECK_SIZE(Unk_G9ItemRef, 0x10);
Unk_G9ItemRef FUN_14053f870(unsigned __int64 nId);

void* FUN_1406c7600();                                  // the trophy manager
int FUN_140936740(void* pMgr, unsigned __int64 nPacked);
void* FUN_1409331f0();                                  // the key binds
int FUN_14142dc50(void* pBinds, int nSlot);
void* FUN_140939a00();                                  // the ugc market
__int64 FUN_140d56470(void* pMarket);
void* FUN_1409eed40();                                  // the manufacture book
int FUN_140d513c0(void* pBook);
void* FUN_1413b1c60(const CStringA& strName);           // the dialog of a name
struct Unk_G9Val { void* m_p0; void* m_p1; };           // a ref-counted value handle of the dialog trees
Unk_G9Val* FUN_1413b19d0(void* pInner, Unk_G9Val* pOut, const CString* pName);
void FUN_1413b1a90(void* pDialog, Unk_G9Val* pOut, const CString* pChild);
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
CStringW FUN_14083bdc0(const Unk_GcTime& t, int nFlag, const CStringW& strDateSep, const CStringW& strTimeSep);
CStringW FUN_140719730(bool b);
unsigned __int64 FUN_140869440();                       // the server time
void FUN_1412751b0(const CStringW& text, int a);
