// MS2-UNIT: client\ms2\cubemapinformationservice.cpp#3
// MS2-RANGE: 0x1410b68a0-0x1410d5bc0 .text$mn
// MS2-RANGE: 0x1400e6230-0x1400e6420 .text$di
// MS2-PIN: ??0Unk_CMISFlags3@@QEAA@XZ 0x140b68e60
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCube@@@@QEAAAEAV1@PEAVCube@@@Z 0x140965090 ; unique
// MS2-PIN: ??0Unk_CMISIntList@@QEAA@XZ 0x1411229d0
// MS2-PIN: ??1Unk_CMISIntList@@QEAA@XZ 0x141125b70
// MS2-PIN: ??0Unk_CMISPt3@@QEAA@AEBUUnk_StreamPoint@@@Z 0x14027dcf0
// MS2-PIN: ??_7CubeMapInformationService@@6BISystemService@efd@@@ 0x142eb3960
// MS2-PIN: ??_7CubeMapInformationService@@6B?$TSingleton@VCubeMapInformationService@@@@@ 0x142eb39e8
// MS2-PIN: ??_7?$TSingleton@VCubeMapInformationService@@@@6B@ 0x142eb3950
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wregister"
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "cubemapinformationservice_3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citemdata.h"
#include <efd/MessageService.h>
#include <efd/ISystemService.h>
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/hardwareinstancingservice.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uihomeinfodialog.h"
#include <float.h>
#include "ms2/client/ms2/uihousemark.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#define MS2_STATICS_A_BEFORE_CONDITION "cubemapinformationservice_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
static UICommon::CMyPCKeyInputController s_keyInput;                // @0x1400e63f0

class CCubeMotionManager;
void FUN_14112ded0();                                                // CCubeMotionManager::DestroyInstance
CCubeMotionManager* FUN_14112dd30();                                 // CCubeMotionManager::CreateInstance
efd::MessageService* FUN_1413f9830();
void FUN_1410db490(efd::IDependencyRegistrar*, unsigned);
void FUN_1410db4c0(efd::IDependencyRegistrar*, unsigned);
void FUN_1410db460(efd::IDependencyRegistrar*, unsigned);
unsigned char* FUN_1411282d0(Unk_CMISTree<280>*, const int*);
int* FUN_141128250(Unk_CMISTree<281>*, const int*);
void FUN_14115ab30(Unk_CMISTree<260>*);
void FUN_1409fabe0(void*);
unsigned char* FUN_141128310(Unk_CMISTree<280>*, const int*);
int* FUN_141128290(Unk_CMISTree<281>*, const int*);
int* FUN_1411280d0(Unk_CMISTree<270>*, const CString*);
void FUN_14114fae0(Unk_CMISTree<282>*);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CubeMapInformationService);
CubeMapInformationService* TSingleton<CubeMapInformationService>::s_instance = 0;
inline TSingleton<CubeMapInformationService>::TSingleton() { s_instance = static_cast<CubeMapInformationService*>(this); }

// Unk_CMISTree<N>'s ctor/dtor stay declared only: symbols.tsv binds each family to the exe's wrapper pair
// (0x141122xxx / 0x141125xxx), which allocates/frees the tree's head node. A local definition would win over that
// binding in the hook DLL and leave head null (the hooked MS2::RegisterServices then AVs in the first f368 lookup).
// Exceptions: 287's dtor (FUN_1410b7fe0's static, atexit thunk 0x142cac250) has no symbol row, and the 294/295 locals
// of FUN_1410d3450 are constructed/destroyed by explicit wrapper calls, so their implicit ctor/dtor do nothing.
void FUN_1411258b0(Unk_CMISTree<287>*);
template <> Unk_CMISTree<287>::~Unk_CMISTree() { FUN_1411258b0(this); }
template <> Unk_CMISTree<294>::Unk_CMISTree() {}
template <> Unk_CMISTree<294>::~Unk_CMISTree() {}
template <> Unk_CMISTree<295>::Unk_CMISTree() {}
template <> Unk_CMISTree<295>::~Unk_CMISTree() {}
Unk_CMISFlags3::Unk_CMISFlags3() : a(false), b(false), c(false) {}

// @0x1410b68a0
FittingDollData::FittingDollData() {
    kind=0;instanceId=0;field28=0;
    position=efd::Point3::ZERO;
    rotation=efd::Point3::ZERO;
    field44=0;field48=0;items.RemoveAll();
}
// @0x1410b6990
FittingDollData::~FittingDollData() { items.RemoveAll(); }

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1410b69e0
CubeMapInformationService::CubeMapInformationService() : f158(0), s1c8(L""), s1d0(L""), f2d8(reinterpret_cast<const Unk_CMISEntityRef&>(s_cubeMapNone))
{
    FUN_14112dd30();
    for (int i = 0; i < 3; i++)
        f318[i] = 0;
    static_cast<Unk_Int3&>(p300) = Unk_Int3(0, 0, 0);
    static_cast<Unk_Int3&>(p30c) = Unk_Int3(0, 0, 0);
    for (int i = 0; i < 9; i++) {
        int k = i;
        *FUN_1411282d0(&f368, &k) = 0;
    }
    for (int j = 0; j < 9; j++) {
        int k = j;
        *FUN_141128250(&f378, &k) = 0;
    }
    a388.RemoveAll();
    a3a8.RemoveAll();
    FUN_14114fae0(&f3c8);
    t3e0.FUN_1408687f0();
}
#endif
// @0x1410b7240
CubeMapInformationService::~CubeMapInformationService()
{
    FUN_14112ded0();
}
// @0x1410b7680
const char* CubeMapInformationService::GetDisplayName() const { return "CubeMapInformationService"; }


// ---- callees outside the unit ----
struct Unk_CMISPartyPtr { void* m_p; };                                                     // MS2Ptr<party info>
struct Unk_CMISParty { char m_pad[0x20]; int m_map; int m_key; };
class Unk_CMISRoster { public: int FUN_141527920(__int64 nId); int FUN_141527e00(); void* FUN_141523c50(); void* FUN_141530290(); };
class Unk_CMISWorld
{
public:
    Unk_CMISRoster* FUN_141bd0cc0();                            // the party/roster manager
    int FUN_141bd3060();                                        // the current map id
    int FUN_141bcfd10();                                        // the world state (4 = in field, 6 = loading)
    void* FUN_141bd0fa0(Unk_CMISEntityRef ref);                 // the magic-cube object of an entity
    int FUN_141bcfbd0();                                        // in a field with a home (state 4 and a map)
    Unk_PayloadPtr<Unk_CMISObj208> FUN_141bd30a0();             // the current field data
    void FUN_141bc58d0(struct Unk_CMISNpcList* pOut);           // fills the list of npcs
    void FUN_141bc5a20(struct Unk_CMISNpcRef* pOut, CString strKey);   // looks an npc up by its "<kind>_<cell>" key
    int FUN_141bd98d0();                                        // the current character id
    void FUN_141bdb690();                                       // flushes the cube change batch
};
Unk_CMISWorld* FUN_1403ed2d0();
class Unk_CMISActor
{
public:
    Unk_StreamPoint FUN_141676880();                            // PCBase member: the facing point
    Unk_StreamPoint FUN_1416767d0();                            // PCBase member: the position
};
void FUN_140a01250(Unk_StreamPoint ptDir, Unk_StreamPoint* pForward, Unk_StreamPoint* pRight);
Unk_Int3 FUN_1408a1430(Unk_StreamPoint pt);                     // the cube cell of a world point
int FUN_1408a13d0(Unk_StreamPoint pt);                          // the cell key of a world point
int FUN_1408a0370(int x, int y, int z);                         // the cell key of a cube point
template <unsigned __int64 N> struct Unk_CMISIter { void* node; };
Unk_CMISIter<281>* FUN_141152210(Unk_CMISTree<281>*, Unk_CMISIter<281>*);
Unk_CMISIter<281>* FUN_141158460(Unk_CMISTree<281>*, Unk_CMISIter<281>*, const int*);
bool FUN_1408b7170(Unk_CMISIter<281>*, Unk_CMISIter<281>*);
Unk_CMISIter<270>* FUN_141151fd0(Unk_CMISTree<270>*, Unk_CMISIter<270>*);
Unk_CMISIter<270>* FUN_141158000(Unk_CMISTree<270>*, Unk_CMISIter<270>*, const CString*);
bool FUN_141127740(Unk_CMISIter<270>*, Unk_CMISIter<270>*);
Unk_CMISIter<260>* FUN_141151af0(Unk_CMISTree<260>*, Unk_CMISIter<260>*);
Unk_CMISIter<260>* FUN_141157580(Unk_CMISTree<260>*, Unk_CMISIter<260>*, const int*);
bool FUN_141126d90(Unk_CMISIter<260>*, Unk_CMISIter<260>*);
Unk_CMISIter<272>* FUN_141151d90(Unk_CMISTree<272>*, Unk_CMISIter<272>*);
Unk_CMISIter<272>* FUN_141157ba0(Unk_CMISTree<272>*, Unk_CMISIter<272>*, const int*);
bool FUN_141127680(Unk_CMISIter<272>*, Unk_CMISIter<272>*);
Unk_CMISIter<265>* FUN_141151d30(Unk_CMISTree<265>*, Unk_CMISIter<265>*);
Unk_CMISIter<265>* FUN_141157ac0(Unk_CMISTree<265>*, Unk_CMISIter<265>*, const int*);
bool FUN_141127640(Unk_CMISIter<265>*, Unk_CMISIter<265>*);
__int64 FUN_14115ad10(Unk_CMISTree<259>*);                      // the element count
Unk_CMISIter<261>* FUN_141151c10(Unk_CMISTree<261>*, Unk_CMISIter<261>*);
Unk_CMISIter<261>* FUN_141157820(Unk_CMISTree<261>*, Unk_CMISIter<261>*, const int*);
bool FUN_141126e50(Unk_CMISIter<261>*, Unk_CMISIter<261>*);
Unk_CMISTree<287>* FUN_141127d90(Unk_CMISTree<261>*, const int*);        // operator[]: the column of cubes
Unk_CMISTree<287>* FUN_141127dd0(Unk_CMISTree<261>*, const int*);        // operator[] (const flavour, pair.second)
__int64 FUN_14115adb0(Unk_CMISTree<287>*);                      // the element count
Unk_CMISIter<287>* FUN_140885c40(Unk_CMISTree<287>*, Unk_CMISIter<287>*);
Unk_CMISIter<287>* FUN_140885ca0(Unk_CMISTree<287>*, Unk_CMISIter<287>*, const int*);
bool FUN_140885290(Unk_CMISIter<287>*, Unk_CMISIter<287>*);
MS2Ptr<Cube>* FUN_141128350(Unk_CMISTree<287>*, const int*);
int FUN_1408a03c0(Unk_Int3 pt);                                 // the cell key of a cube point
Unk_Int3 FUN_1408a0400(int nKey);                               // the cube point of a cell key
Unk_CMISIter<278>* FUN_14114db40(Unk_CMISTree<278>*, Unk_CMISIter<278>*);   // begin
Unk_CMISIter<278>* FUN_141151910(Unk_CMISTree<278>*, Unk_CMISIter<278>*);   // end
unsigned char FUN_141127380(Unk_CMISIter<278>*, Unk_CMISIter<278>*);                 // operator!=
int* FUN_141128540(Unk_CMISIter<278>*);                                     // operator*
void FUN_141129a60(Unk_CMISIter<278>*);                                     // operator++
Unk_CMISIter<269>* FUN_14096ad60(Unk_CMISTree<269>*, Unk_CMISIter<269>*);                           // end
Unk_CMISIter<269>* FUN_14096ae20(Unk_CMISTree<269>*, Unk_CMISIter<269>*, const __int64*);            // find
bool FUN_140965380(Unk_CMISIter<269>*, Unk_CMISIter<269>*);
bool FUN_1409654d0(Unk_CMISIter<269>*, Unk_CMISIter<269>*);
Unk_CubeOwnerPtr* FUN_1409656d0(Unk_CMISTree<269>*, const __int64*);                                 // operator[]
void FUN_141156310(Unk_CMISTree<269>*, const __int64*);                                              // erase
void FUN_1411552b0(Unk_CMISTree<270>*, const CString*);                                   // erase
void FUN_14114f0e0(Unk_CMISTree<260>*);
void FUN_14114fa40(Unk_CMISTree<259>*);
void FUN_1410b2760(Unk_CMISTree<277>*);
void FUN_14114f360(Unk_CMISTree<262>*);
void FUN_14114f2c0(Unk_CMISTree<261>*);
void FUN_1402237c0(ATL::CAtlArray<Unk_CMISElem458*>*);
struct Unk_CMISPt2 { float x, y; };
Unk_CubeOwnerPtr FUN_1408a0fa0(Unk_CubeOwners& owners, int nGroup, int nBlock);
struct Unk_CMISRes16 { Unk_CMISRes16(const Unk_CMISRes16&); __int64 m_a, m_b; };
Unk_CMISRes16 FUN_1408a15b0(Unk_StreamPoint, Unk_StreamPoint);
Unk_CMISIter<257>* FUN_141152030(Unk_CMISTree<257>*, Unk_CMISIter<257>*);
Unk_CMISIter<257>* FUN_1411580e0(Unk_CMISTree<257>*, Unk_CMISIter<257>*, const Unk_CMISEntityRef*);
bool FUN_141127050(Unk_CMISIter<257>*, Unk_CMISIter<257>*);
void** FUN_141128110(Unk_CMISTree<257>*, const Unk_CMISEntityRef*);
bool FUN_140965240(Unk_PayloadPtr<Unk_CMISObj208>*, void*);
Unk_CMISIter<265>* FUN_14114e010(Unk_CMISTree<265>*, Unk_CMISIter<265>*);       // begin
struct Unk_CMISRefElem { int m_key, m_pad; Unk_CMISEntityRef m_ref; };
Unk_CMISRefElem* FUN_1411286a0(Unk_CMISIter<265>*);                           // operator*
void FUN_141129bd0(Unk_CMISIter<265>*);                                       // operator++
unsigned FUN_140869420();
void FUN_1408a06a0(int, int);
struct Unk_CMISIntPair { int m_key, m_val; };
struct Unk_CMISInsRes { void* m_it; bool m_ok; };
Unk_CMISIter<286>* FUN_140340ff0(Unk_CMISTree<286>*, Unk_CMISIter<286>*);                    // begin
Unk_CMISIter<286>* FUN_140341f40(Unk_CMISTree<286>*, Unk_CMISIter<286>*);                    // end
Unk_CMISIter<286>* FUN_1404c0270(Unk_CMISTree<286>*, Unk_CMISIter<286>*, const unsigned __int64*);   // find
unsigned char FUN_1403344a0(Unk_CMISIter<286>*, Unk_CMISIter<286>*);
unsigned char FUN_140334210(Unk_CMISIter<286>*, Unk_CMISIter<286>*);
Unk_CMISInsRes* FUN_1404422b0(Unk_CMISTree<286>*, Unk_CMISInsRes*, const unsigned __int64*);   // insert
void FUN_1404bfb40(Unk_CMISTree<286>*, const unsigned __int64*);                               // erase
unsigned __int64* FUN_1408f2950(Unk_CMISIter<286>*);                                           // operator*
void FUN_140334ef0(Unk_CMISIter<286>*);                                                        // operator++
Unk_CMISIter<282>* FUN_1411582a0(Unk_CMISTree<282>*, Unk_CMISIter<282>*, const int*);
Unk_CMISIter<282>* FUN_141152150(Unk_CMISTree<282>*, Unk_CMISIter<282>*);
bool FUN_141127110(Unk_CMISIter<282>*, Unk_CMISIter<282>*);
Unk_CMISIntPair* FUN_1411284e0(Unk_CMISIter<282>*);
bool FUN_141151720(Unk_CMISTree<260>*);
CFieldData* FUN_140885340(Unk_PayloadPtr<Unk_CMISObj208>*);
bool FUN_140374410(int);
unsigned FUN_141bd3060(Unk_CMISWorld*);
Unk_CMISIter<278>* FUN_141157040(Unk_CMISTree<278>*, Unk_CMISIter<278>*, const int*);
const Unk_CMISEntityRef* FUN_1408b76f0(egf::Entity*);                   // &entity id
egf::Entity* FUN_1408a9280(const void* pSp);
void FUN_1409618c0(egf::Entity*, unsigned, Unk_StreamPoint*);   // GetProperty(Point3)
struct Unk_CMISPt3 { float x, y, z; Unk_CMISPt3(const Unk_StreamPoint&); };   // efd::Point3 copy (0x14027dcf0)
struct Unk_CMISRayHit { __int64 m_q0, m_q1, m_q2, m_q3, m_q4, m_q5; egf::Entity* m_pEntity; __int64 m_q7, m_q8, m_q9, m_q10, m_q11, m_q12; };
void FUN_140ad4440(Unk_CMISRayHit*);
class CPhysXHelper;
CPhysXHelper* FUN_1409f7ca0();
int FUN_14168a310(CPhysXHelper*, Unk_CMISPt3*, Unk_StreamPoint*, Unk_CMISRayHit*, float, __int64, int);
class Unk_CMISPhysScene
{
public:
    virtual void vf0() = 0; virtual void vf1() = 0; virtual void vf2() = 0; virtual void vf3() = 0;
    virtual void vf4() = 0; virtual void vf5() = 0; virtual void vf6() = 0; virtual void vf7() = 0;
    virtual void RemoveActor(void* pActor) = 0;             // +0x40
};
Unk_CMISPhysScene* FUN_14168a1c0(CPhysXHelper*);
void FUN_14168a540(CPhysXHelper*, int);
void FUN_14168a570(CPhysXHelper*);
void FUN_141bc8e00(Unk_CMISWorld*);
void FUN_1411554c0(Unk_CMISTree<257>*, const Unk_CMISEntityRef*);
void FUN_1411556d0(Unk_CMISTree<258>*, const Unk_CMISEntityRef*);
Unk_CMISEntityRef* FUN_141127ed0(Unk_CMISTree<265>*, const int*);
void FUN_1411547a0(Unk_CMISTree<265>*, const int*);
bool FUN_14028d470(float, float);
extern Unk_StreamPoint DAT_143a08cf8;                                       // up vector
extern Unk_StreamPoint DAT_143b01a60;                                       // zero / fall-through direction
struct Unk_CMISCubeByKey { int first; MS2Ptr<Cube> second; };                // the node value of the cubes by key
void FUN_14114dd70(Unk_CMISTree<260>*, Unk_CMISIter<260>*);                 // begin
bool FUN_1411274c0(Unk_CMISIter<260>*, Unk_CMISIter<260>*);                 // operator!=
Unk_CMISCubeByKey* FUN_1411285e0(Unk_CMISIter<260>*);                       // operator*
void FUN_141129b50(Unk_CMISIter<260>*);                                     // operator++
Unk_CMISIter<260>* FUN_141129b00(Unk_CMISIter<260>*, Unk_CMISIter<260>*, int);        // operator++(int)
int FUN_1408b4f20(Cube*);                                                   // the item id of a cube
__int64 FUN_1408b4f50(Cube*);
int FUN_14053fc10(int);                                                     // the item category
struct Unk_CMISCubeOwner { char m_pad[0x18]; __int64 m_nId; };
Unk_CMISCubeOwner* FUN_1408b4f80(Cube*);                                    // the owner record of a cube
struct Unk_CMISIntList { Unk_CMISIntList(); ~Unk_CMISIntList(); void* m_pFirst; void* m_pLast; void* m_pEnd; };   // 0x18 bytes: the cube keys of a column
Unk_CMISIter<262>* FUN_141151c70(Unk_CMISTree<262>*, Unk_CMISIter<262>*);   // end
Unk_CMISIter<262>* FUN_141157900(Unk_CMISTree<262>*, Unk_CMISIter<262>*, const int*);   // find
bool FUN_1411275c0(Unk_CMISIter<262>*, Unk_CMISIter<262>*);                 // operator!=
// By-value spellings of the same map<int,...> members: a non-POD iterator comes back through a hidden pointer, so its
// temporaries sit after the named locals as in the exe's `fd8.find(k) != fd8.end()`.
template <unsigned __int64 N> struct Unk_CMISItV {
    void* node;
    Unk_CMISItV() {}
    bool FUN_1411275c0(const Unk_CMISItV&) const;   // <262> operator!=
    bool FUN_141126e90(const Unk_CMISItV&) const;   // <262> operator==
    bool FUN_140d7b400(const Unk_CMISItV&) const;   // <276> operator==
};
template <unsigned __int64 N> struct Unk_CMISTreeV {
    Unk_CMISItV<N> FUN_141151c70();                 // <262> end
    Unk_CMISItV<N> FUN_141157900(const int&);       // <262> find
    Unk_CMISItV<N> FUN_141151df0();                 // <276> end
    Unk_CMISItV<N> FUN_141157c80(const int&);       // <276> find
};
bool FUN_141126e90(Unk_CMISIter<262>*, Unk_CMISIter<262>*);                 // operator==
Unk_CMISIntList* FUN_141127e10(Unk_CMISTree<262>*, const int*);             // operator[]
void FUN_141126700(Unk_CMISIntList*, Unk_CMISIntList*);                     // operator=
struct Unk_CMISListIter { void* m_p; };
Unk_CMISListIter* FUN_14114e630(Unk_CMISIntList*, Unk_CMISListIter*);                    // begin
struct Unk_CMISListEnd { void* m_p; void* m_a; };
Unk_CMISListEnd* FUN_1411522d0(Unk_CMISIntList*, Unk_CMISListEnd*);         // end
bool FUN_14035ea60(Unk_CMISListIter*, Unk_CMISListEnd*);                   // operator!=
int* FUN_1403e8d70(Unk_CMISListIter*);                                      // operator*
void FUN_14035ebf0(Unk_CMISListIter*);                                      // operator++
struct Unk_CMISHouseInfo : public CPtred                                    // a house marker record (0x38)
{
    int m_nGroup;                                                           // +0x18
    Unk_StreamPoint m_pt;                                                   // +0x1c
    CStringW m_strOwner;                                                    // +0x28
    bool m_bNoSalable;                                                      // +0x30
    int m_nValue;                                                           // +0x34
};
struct Unk_CMISHousePtr { void* m_0; void* m_p; }; MS2_CHECK_SIZE(Unk_CMISHousePtr, 0x10); // object at +8 (ctor 0x14111e6e0, -> 0x141128470); 8 bytes overflowed FUN_1410bbf20's local
struct Unk_CMISHouseNode { int first; Unk_CMISHousePtr second; };
class Unk_CMISHouseMark { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); void FUN_14198cb00(const Unk_CMISHouseInfo& info); void FUN_14198cf50(); };
Unk_CMISHouseMark* FUN_1410dc020();
bool FUN_1411516e0(Unk_CMISTree<274>*);                                     // empty
void FUN_14114dc90(Unk_CMISTree<274>*, Unk_CMISIter<274>*);                 // begin
Unk_CMISIter<274>* FUN_141151a30(Unk_CMISTree<274>*, Unk_CMISIter<274>*);   // end
bool FUN_141127440(Unk_CMISIter<274>*, Unk_CMISIter<274>*);                 // operator!=
Unk_CMISHouseNode* FUN_1411285a0(Unk_CMISIter<274>*);                       // operator*
void FUN_141129ac0(Unk_CMISIter<274>*);                                     // operator++
Unk_CMISIter<274>* FUN_1411573c0(Unk_CMISTree<274>*, Unk_CMISIter<274>*, const int*);   // find
Unk_CMISHousePtr* FUN_141127c50(Unk_CMISTree<274>*, const int*);             // operator[]
Unk_CMISHouseInfo* FUN_141128470(Unk_CMISHousePtr*);                         // operator->
int FUN_1408b5620(int);
bool FUN_141151760(Unk_CMISTree<259>*);
bool FUN_141126b10(Unk_CMISHousePtr*, int);                                 // operator==(0)
Unk_CMISHouseInfo* FUN_141128800(Unk_CMISHousePtr*);                        // operator*
class Unk_CMISPolyObj { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); };
struct Unk_CMISPolyNode { int first; Unk_CMISHousePtr second; };
void FUN_14114dde0(Unk_CMISTree<273>*, Unk_CMISIter<273>*);                 // begin
Unk_CMISIter<273>* FUN_141151b50(Unk_CMISTree<273>*, Unk_CMISIter<273>*);   // end
bool FUN_141127500(Unk_CMISIter<273>*, Unk_CMISIter<273>*);                 // operator!=
Unk_CMISPolyNode* FUN_141128600(Unk_CMISIter<273>*);                        // operator*
void FUN_141129b70(Unk_CMISIter<273>*);                                     // operator++
Unk_CMISPolyObj* FUN_1411284c0(Unk_CMISHousePtr*);                          // operator->
struct Unk_CMISPair { int m_a, m_b; };
extern Unk_CMISPair DAT_143b02320;                                          // initial cursor pair
float FUN_14029d220(float f);                                               // fabsf
Unk_Int3* FUN_14112ca20(Unk_Int3* pA, Unk_Int3* pOut, Unk_Int3* pB);   // point add
struct Unk_DkPoint : public Unk_Int3 { Unk_Int3 operator+(const Unk_DkPoint& o) const; };   // 0x14112ca20 (unit_14112ab60)
const int* FUN_1402fbd20(const int*, const int*);               // std::min
const int* FUN_1404eb7e0(const int*, const int*);               // std::max
MS2Ptr<Cube>* FUN_141127cd0(Unk_CMISTree<260>*, const int*);             // operator[]: the cube of a key
struct Unk_CMISCubeById { Unk_CMISEntityRef key; MS2Ptr<Cube> second; };  // the node value of the cubes by entity
Unk_CMISIter<259>* FUN_1411581c0(Unk_CMISTree<259>*, Unk_CMISIter<259>*, const Unk_CMISEntityRef*);   // find
Unk_CMISIter<259>* FUN_1411520f0(Unk_CMISTree<259>*, Unk_CMISIter<259>*);                             // end
bool FUN_141127800(Unk_CMISIter<259>*, Unk_CMISIter<259>*);                                          // operator!=
Unk_CMISCubeById* FUN_141128780(Unk_CMISIter<259>*);                                                 // operator*
bool FUN_1408a07b0(int nMapId, int a, __int64 b);
extern int DAT_1439f4a7c;
extern __int64 DAT_143ab2820;

// @0x1410b76a0
int CubeMapInformationService::FUN_1410b76a0()
{
    FUN_1410c68e0();
    FUN_1410d0310();
    return 1;
}
// @0x1410b76d0
void CubeMapInformationService::FUN_1410b76d0()
{
    f158 = 0;
    f160 = false;
    t168.FUN_140868750(1000);
    t250.FUN_140868750(200);
    f208 = FUN_1403ed2d0()->FUN_141bd30a0();
    f218 = FUN_1408ad3f0(FUN_1403ed2d0()->FUN_141bd3060());
}
// @0x1410b7a20
Unk_StreamPoint CubeMapInformationService::FUN_1410b7a20(Unk_StreamPoint pt, Unk_StreamPoint* pOut)
{
    Unk_Int3 cell = FUN_1408a1430(pt);
    pOut->x = (float)cell.x * 150.0f;
    pOut->y = (float)cell.y * 150.0f;
    pOut->z = (float)cell.z * 150.0f;
    return *pOut;
}
// @0x1410b7ad0
Unk_StreamPoint CubeMapInformationService::FUN_1410b7ad0(PCBase* pActor, float fDist, Unk_StreamPoint* pOut, int bSnap)
{
    return FUN_1410b7ba0(reinterpret_cast<Unk_CMISActor*>(pActor)->FUN_1416767d0(), reinterpret_cast<Unk_CMISActor*>(pActor)->FUN_141676880(), fDist, pOut, bSnap);
}
// @0x1410b7ba0
Unk_StreamPoint CubeMapInformationService::FUN_1410b7ba0(Unk_StreamPoint ptFrom, Unk_StreamPoint ptTo, float fDist, Unk_StreamPoint* pOut, int bSnap)
{
    Unk_StreamPoint kForward, kRight;
    FUN_140a01250(ptTo, &kForward, &kRight);
    *pOut = ptFrom.FUN_14097fd50(kForward.FUN_14097fc90((float)bSnap).FUN_14097fc90(150.0f));
    pOut->x = pOut->x + 75.0f;
    pOut->y = pOut->y + 75.0f;
    pOut->z = pOut->z + fDist;
    if (pOut->x < 0.0f)
        pOut->x = pOut->x - 150.0f;
    if (pOut->y < 0.0f)
        pOut->y = pOut->y - 150.0f;
    return *pOut;
}
// @0x1410b7d50
bool CubeMapInformationService::FUN_1410b7d50()
{
    return FUN_14115ad10(&f78) == 0;
}
// @0x1410b7da0
bool CubeMapInformationService::FUN_1410b7da0(Unk_StreamPoint pt)
{
    if (!FUN_1410b7e80(pt))
        return false;
    int nKey = FUN_1408a13d0(pt);
    Unk_CMISIter<265> itEnd, itFind;
    if (FUN_141127640(FUN_141157ac0(&f2e0, &itFind, &nKey), FUN_141151d30(&f2e0, &itEnd)))
        return true;
    return false;
}
// @0x1410b7e80
bool CubeMapInformationService::FUN_1410b7e80(Unk_StreamPoint pt)
{
    return FUN_1410b7ed0(FUN_1408a13d0(pt));
}
// @0x1410b7ed0
bool CubeMapInformationService::FUN_1410b7ed0(int nKey)
{
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_141126d90(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)))
        return false;
    Unk_CMISIter<272> itEnd2, itFind2;
    if (FUN_141127680(FUN_141157ba0(&f1f8, &itFind2, &nKey), FUN_141151d90(&f1f8, &itEnd2)))
        return false;
    return true;
}
// @0x1410b7f90
bool CubeMapInformationService::FUN_1410b7f90(Unk_Int3 cell)
{
    return FUN_1410b7ed0(FUN_1408a0370(cell.x, cell.y, cell.z));
}

// @0x1410b7fe0
Unk_CMISTree<287>* CubeMapInformationService::FUN_1410b7fe0(int nKey)
{
    static Unk_CMISTree<287> s_empty;
    Unk_CMISIter<261> itEnd, itFind;
    if (FUN_141126e50(FUN_141157820(&fc8, &itFind, &nKey), FUN_141151c10(&fc8, &itEnd)))
        return &s_empty;
    return FUN_141127dd0(&fc8, &nKey);
}
// @0x1410b80d0
Cube* CubeMapInformationService::FUN_1410b80d0(MS2Ptr<Cube> spCube, int nZ)
{
    int nKey = FUN_1408a03c0(spCube->position);
    Unk_CMISIter<261> itEnd, itFind;
    if (FUN_141126e50(FUN_141157820(&fc8, &itFind, &nKey), FUN_141151c10(&fc8, &itEnd)))
        return 0;
    int nColumn = FUN_1408a03c0(spCube->position);
    Unk_CMISTree<287>* pColumn = FUN_141127d90(&fc8, &nColumn);
    if (FUN_14115adb0(pColumn) == 0)
        return 0;
    Unk_CMISIter<287> itColEnd, itColFind;
    if (FUN_140885290(FUN_140885ca0(pColumn, &itColFind, &nZ), FUN_140885c40(pColumn, &itColEnd)))
        return 0;
    return FUN_141128350(pColumn, &nZ)->get();
}
// @0x1410b82c0
bool CubeMapInformationService::FUN_1410b82c0(MS2Ptr<Cube> spCube)
{
    int nKey = FUN_1408a03c0(spCube->position);
    Unk_CMISIter<261> itEnd, itFind;
    if (FUN_141126e50(FUN_141157820(&fc8, &itFind, &nKey), FUN_141151c10(&fc8, &itEnd)))
        return false;
    int nColumn = FUN_1408a03c0(spCube->position);
    Unk_CMISTree<287>* pColumn = FUN_141127d90(&fc8, &nColumn);
    if (FUN_14115adb0(pColumn) == 0)
        return false;
    return true;
}
// @0x1410b8420
bool CubeMapInformationService::FUN_1410b8420(MS2Ptr<Cube> spCube, int nZ)
{
    int nKey = FUN_1408a03c0(spCube->position);
    Unk_CMISIter<261> itEnd, itFind;
    if (FUN_141126e50(FUN_141157820(&fc8, &itFind, &nKey), FUN_141151c10(&fc8, &itEnd)))
        return false;
    int nColumn = FUN_1408a03c0(spCube->position);
    Unk_CMISTree<287>* pColumn = FUN_141127d90(&fc8, &nColumn);
    if (FUN_14115adb0(pColumn) == 0)
        return false;
    Unk_CMISIter<287> itColEnd, itColFind;
    if (FUN_140885290(FUN_140885ca0(pColumn, &itColFind, &nZ), FUN_140885c40(pColumn, &itColEnd)))
        return false;
    return true;
}
// @0x1410b85f0
void CubeMapInformationService::FUN_1410b85f0(Unk_Int3* pMin, Unk_Int3* pMax)
{
    pMin->x = 0x7fffffff;
    pMin->y = 0x7fffffff;
    pMin->z = 0x7fffffff;
    pMax->x = 0x80000000;
    pMax->y = 0x80000000;
    pMax->z = 0x80000000;
    Unk_CMISIter<278> it, itEnd;
    for (FUN_14114db40(&f2b8, &it); FUN_141127380(&it, FUN_141151910(&f2b8, &itEnd)); FUN_141129a60(&it)) {
        int nKey = *FUN_141128540(&it);
        Unk_Int3 cell = FUN_1408a0400(nKey);
        pMin->x = *FUN_1402fbd20(&pMin->x, &cell.x);
        pMin->y = *FUN_1402fbd20(&pMin->y, &cell.y);
        pMin->z = *FUN_1402fbd20(&pMin->z, &cell.z);
        pMax->x = *FUN_1404eb7e0(&pMax->x, &cell.x);
        pMax->y = *FUN_1404eb7e0(&pMax->y, &cell.y);
        pMax->z = *FUN_1404eb7e0(&pMax->z, &cell.z);
    }
}

// @0x1410b8790
Cube* CubeMapInformationService::FUN_1410b8790(Unk_Int3 pt)
{
    int nMaxDrop = 0;
    if (FUN_1410c3180() != 0)
        nMaxDrop = f2fc;
    else
        nMaxDrop = 20;
    Unk_Int3 ptHit = pt;
    int nDrop = 0;
    while (nDrop++ <= nMaxDrop) {
        int nKey = FUN_1408a03c0(pt);
        if (FUN_1410d2f40(nKey) != 0) {
            MS2Ptr<Cube> spCube(FUN_1410b8b00(nKey));
            if (spCube.get() != 0) {
                if (FUN_1408a07b0(FUN_1403ed2d0()->FUN_141bd3060(), DAT_1439f4a7c, DAT_143ab2820)) {
                    ptHit = pt;
                    break;
                } else if (spCube->field50 != 0) {
                    ptHit = pt;
                    break;
                }
            }
        }
        pt.z = pt.z - 1;
    }
    return FUN_1410b8a60(ptHit);
}
// @0x1410b8980
Cube* CubeMapInformationService::FUN_1410b8980(Unk_Int3 pt)
{
    Cube* pBase = FUN_1410b8a60(pt);
    if (pBase != 0 && pBase->field44 == 0)
        return 0;
    while (pBase != 0) {
        pt.z = pt.z - 1;
        Cube* pNext = FUN_1410b8a60(pt);
        if (pNext == 0 || pNext->field50 != pBase->field50 || pNext->field44 == 0)
            return pBase;
        pBase = pNext;
    }
    return pBase;
}
// @0x1410b8a60
Cube* CubeMapInformationService::FUN_1410b8a60(Unk_Int3 pt)
{
    return FUN_1410b8b00(FUN_1408a0370(pt.x, pt.y, pt.z));
}
// @0x1410b8ab0
Cube* CubeMapInformationService::FUN_1410b8ab0(Unk_StreamPoint pt)
{
    return FUN_1410b8b00(FUN_1408a13d0(pt));
}
// @0x1410b8b00
Cube* CubeMapInformationService::FUN_1410b8b00(int nKey)
{
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_141126d90(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)))
        return 0;
    Unk_CMISIter<272> itEnd2, itFind2;
    if (FUN_141127680(FUN_141157ba0(&f1f8, &itFind2, &nKey), FUN_141151d90(&f1f8, &itEnd2)))
        return 0;
    return FUN_141127cd0(&f98, &nKey)->get();
}
// @0x1410b8be0
Cube* CubeMapInformationService::FUN_1410b8be0(const Unk_CMISEntityRef& ref)
{
    Unk_1401cd100 none(0);
    if (ref.FUN_140965410(none))
        return 0;
    Unk_CMISIter<259> itFind, itEnd;
    FUN_1411581c0(&fa8, &itFind, &ref);
    if (FUN_141127800(&itFind, FUN_1411520f0(&fa8, &itEnd)))
        return FUN_141128780(&itFind)->second.get();
    return 0;
}

// @0x1410b8c90
Cube* CubeMapInformationService::FUN_1410b8c90(const Unk_CMISEntityRef& ref)
{
    Unk_1401cd100 none(0);
    if (ref.FUN_140965410(none))
        return 0;
    Unk_CMISIter<259> itFind, itEnd;
    FUN_1411581c0(&fa8, &itFind, &ref);
    if (FUN_141127800(&itFind, FUN_1411520f0(&fa8, &itEnd))) {
        MS2Ptr<Cube> spCube(FUN_141128780(&itFind)->second);
        if (spCube->field48 == 0)
            return 0;
        return spCube.get();
    }
    return 0;
}
// @0x1410b8d90
Cube* CubeMapInformationService::FUN_1410b8d90(Cube* pBase, int nOffset, int nField44)
{
    Cube* pCube = 0;
    if (pBase != 0 && nOffset != 0) {
        Unk_Int3 off = FUN_1408a0400(nOffset);
        Unk_Int3 tmp;
        pCube = FUN_1410b8a60(*FUN_14112ca20(&off, &tmp, &pBase->position));
        if (pCube != 0 && pCube->field44 == nField44)
            return pCube;
        else
            return 0;
    }
    return pCube;
}
// @0x1410b9080
Cube* CubeMapInformationService::FUN_1410b9080(Cube* pBase, int nOffset)
{
    Cube* pCube = 0;
    if (pBase != 0 && nOffset != 0) {
        Unk_Int3 off = FUN_1408a0400(nOffset);
        Unk_Int3 tmp;
        pCube = FUN_1410b8a60(*FUN_14112ca20(&off, &tmp, &pBase->position));
        if (pCube != 0 && pCube->field70 != 0)
            return pCube;
        else
            return 0;
    }
    return pCube;
}

// @0x1410b8e60
Cube* CubeMapInformationService::FUN_1410b8e60(egf::Entity* pEntity)
{
    if (pEntity != 0) {
        Unk_StreamPoint pt;
        FUN_1409618c0(pEntity, 0xfd95ca52, &pt);
        Cube* pCube = FUN_1410b8ab0(pt);
        if (pCube != 0 && pCube->field70 != 0) {
            if (FUN_1408b76f0(FUN_1408a9280(&pCube->entity))->FUN_140965410(*reinterpret_cast<const Unk_1401cd100*>(FUN_1408b76f0(pEntity))))
                return pCube;
        }
    }
    return 0;
}

// @0x1410b8f30
Cube* CubeMapInformationService::FUN_1410b8f30(Unk_StreamPoint ptFrom, Unk_StreamPoint* pHit, float fRange)
{
    static Unk_StreamPoint s_kDown = DAT_143a08cf8.FUN_14097fc90(20.0f);
    Unk_CMISPt3 ptStart(ptFrom.FUN_14097fd50(s_kDown));
    if (FUN_14028d470(fRange, 0.0f))
        fRange = 150.0f;
    Unk_CMISRayHit hit;
    FUN_140ad4440(&hit);
    if (FUN_14168a310(FUN_1409f7ca0(), &ptStart, pHit, &hit, fRange, 0, 0) != 0)
        return FUN_1410b8e60(hit.m_pEntity);
    return 0;
}

// @0x1410b9150
Unk_StreamPoint CubeMapInformationService::FUN_1410b9150(Unk_StreamPoint ptIn)
{
    static Unk_StreamPoint s_kDown = DAT_143a08cf8.FUN_14097fc90(20.0f);
    Unk_CMISPt3 ptStart(ptIn.FUN_14097fd50(s_kDown));
    Unk_StreamPoint ptDir = DAT_143b01a60;
    Unk_CMISRayHit hit;
    FUN_140ad4440(&hit);
    Cube* pCube;
    if (FUN_14168a310(FUN_1409f7ca0(), &ptStart, &ptDir, &hit, 750.0f, 0, 0) != 0 && (pCube = FUN_1410b8e60(hit.m_pEntity)) != 0 && pCube->field70 != 0) {
        Unk_StreamPoint ptRes;
        FUN_1409618c0(FUN_1408a9280(&pCube->entity), 0xfd95ca52, &ptRes);
        ptRes.z = ptIn.z;
        return ptRes;
    }
    return ptIn;
}

// @0x1410b9330
// MS2-FUNCTIONAL: frame 0x10 larger than the exe (the operator+ temp is allocated before the by-value copies); same calls and control flow
bool CubeMapInformationService::FUN_1410b9330(void* pArg, Unk_StreamPoint pt, float fStep, Unk_StreamPoint* pOutPos, Unk_StreamPoint* pOutRot, int* pnResult, void** ppHit)
{
    float fLimit = 75.0f;
    void* pFound = 0;
    float fRadius = fStep;
    Unk_StreamPoint ptCur;
    Unk_StreamPoint ptOffset = DAT_143b01a60;
    Unk_CMISPair kCursor = DAT_143b02320;
    *pnResult = FUN_1410d1320(pArg, pt, fStep, &ptCur);
    if (*pnResult == 9)
        return false;
    float fDx = pt.x - ptCur.x;
    float fDy = pt.y - ptCur.y;
    *pOutRot = DAT_143b01a60;
    if (FUN_14029d220(fDx) > fLimit - fRadius)
        fDx = (fDx / FUN_14029d220(fDx)) * (fLimit - fRadius);
    if (FUN_14029d220(fDy) > fLimit - fRadius)
        fDy = (fDy / FUN_14029d220(fDy)) * (fLimit - fRadius);
    *pnResult = FUN_1410d1820(pArg, *pnResult, pt, ptCur, &pFound);
    if (pFound == 0 || FUN_1410d2130(pFound, *pnResult, fRadius, pOutPos, pOutRot) == 0) {
        int nDir = *pnResult;
        switch (nDir) {
        case 0:
            return false;
        case 1:
            pOutRot->z = 225.0f;
            ptOffset.x = -fRadius;
            ptOffset.y = fRadius;
            break;
        case 2:
            pOutRot->z = 180.0f;
            ptOffset.x = fDx;
            ptOffset.y = fRadius;
            break;
        case 3:
            pOutRot->z = 135.0f;
            ptOffset.x = fRadius;
            ptOffset.y = fRadius;
            break;
        case 4:
            pOutRot->z = 90.0f;
            ptOffset.x = fRadius;
            ptOffset.y = fDy;
            break;
        case 5:
            pOutRot->z = 45.0f;
            ptOffset.x = fRadius;
            ptOffset.y = -fRadius;
            break;
        case 6:
            pOutRot->z = 0.0f;
            ptOffset.x = fDx;
            ptOffset.y = -fRadius;
            break;
        case 7:
            pOutRot->z = 315.0f;
            ptOffset.x = -fRadius;
            ptOffset.y = -fRadius;
            break;
        case 8:
            pOutRot->z = 270.0f;
            ptOffset.x = -fRadius;
            ptOffset.y = fDy;
            break;
        }
        ptCur.z = pt.z;
        *pOutPos = ptCur.FUN_14097fd50(ptOffset);
        return true;
    }
    pOutPos->z = pt.z;
    if (ppHit != 0)
        *ppHit = pFound;
    return true;
}

// @0x1410b9850
Cube* CubeMapInformationService::FUN_1410b9850(int nItemId)
{
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        {
            if (FUN_1408b4f20(spCube.operator->()) == nItemId)
                return spCube.get();
        }
    }
    return 0;
}
// @0x1410b9950
int CubeMapInformationService::FUN_1410b9950(int nCategory)
{
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        if (FUN_14053fc10(FUN_1408b4f20(spCube.operator->())) == nCategory)
            return 1;
    }
    return 0;
}
// @0x1410b9a50
int CubeMapInformationService::FUN_1410b9a50()
{
    int nCount = 0;
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        nCount++;
    }
    return nCount;
}
// @0x1410b9b20
int CubeMapInformationService::FUN_1410b9b20(int nItemId)
{
    int nCount = 0;
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        if (FUN_1408b4f20(spCube.operator->()) != nItemId)
            continue;
        nCount++;
    }
    return nCount;
}
// @0x1410b9d80
int CubeMapInformationService::FUN_1410b9d80(__int64 nId)
{
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        if (FUN_1408b4f50(spCube.operator->()) == nId)
            return 1;
    }
    return 0;
}
// @0x1410b9e70
Unk_CMISTree<277>* CubeMapInformationService::FUN_1410b9e70()
{
    return &f2a8;
}

// @0x1410b9c20
int CubeMapInformationService::FUN_1410b9c20(int nItemId, __int64 nOwnerId)
{
    int nCount = 0;
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        if (FUN_1408b4f20(spCube.operator->()) != nItemId)
            continue;
        __int64 nOwner = 0;
        Unk_CMISCubeOwner* pOwner = FUN_1408b4f80(spCube.operator->());
        if (pOwner != 0)
            nOwner = pOwner->m_nId;
        if (nOwner != nOwnerId)
            continue;
        nCount++;
    }
    return nCount;
}
// @0x1410ba440
float CubeMapInformationService::FUN_1410ba440(int nDir)
{
    switch (nDir) {
    case 1:
        return 270.0f;
    case 2:
        return 180.0f;
    case 3:
        return 90.0f;
    case 4:
        return 0.0f;
    default:
        return 0.0f;
    }
}
// @0x1410ba4a0
int CubeMapInformationService::FUN_1410ba4a0(Unk_StreamPoint ptDir)
{
    Unk_StreamPoint kWest(-1.0f, 0.0f, 0.0f);
    Unk_StreamPoint kNorth(0.0f, 1.0f, 0.0f);
    Unk_StreamPoint kEast(1.0f, 0.0f, 0.0f);
    Unk_StreamPoint kSouth(0.0f, -1.0f, 0.0f);
    Unk_StreamPoint kForward, kRight;
    FUN_140a01250(ptDir, &kForward, &kRight);
    if (kWest.FUN_140a00f20(kForward) == 1.0f)
        return 1;
    else if (kNorth.FUN_140a00f20(kForward) == 1.0f)
        return 2;
    else if (kEast.FUN_140a00f20(kForward) == 1.0f)
        return 3;
    else if (kSouth.FUN_140a00f20(kForward) == 1.0f)
        return 4;
    return 0;
}
// @0x1410bab50
Unk_Int3 CubeMapInformationService::FUN_1410bab50(Unk_Int3 pt, int nDir)
{
    switch (nDir) {
    case 1:
        pt.x = pt.x - 1;
        break;
    case 2:
        pt.y = pt.y + 1;
        break;
    case 3:
        pt.x = pt.x + 1;
        break;
    case 4:
        pt.y = pt.y - 1;
        break;
    }
    return pt;
}
// @0x1410bac00
Unk_Int3 CubeMapInformationService::FUN_1410bac00(Unk_StreamPoint ptDir)
{
    Unk_StreamPoint kWest(-1.0f, 0.0f, 0.0f);
    Unk_StreamPoint kNorth(0.0f, 1.0f, 0.0f);
    Unk_StreamPoint kEast(1.0f, 0.0f, 0.0f);
    Unk_StreamPoint kSouth(0.0f, -1.0f, 0.0f);
    Unk_StreamPoint kForward, kRight;
    FUN_140a01250(ptDir, &kForward, &kRight);
    if (kWest.FUN_140a00f20(kForward) == 1.0f)
        return Unk_Int3(-1, 0, 0);
    else if (kNorth.FUN_140a00f20(kForward) == 1.0f)
        return Unk_Int3(0, 1, 0);
    else if (kEast.FUN_140a00f20(kForward) == 1.0f)
        return Unk_Int3(1, 0, 0);
    else if (kSouth.FUN_140a00f20(kForward) == 1.0f)
        return Unk_Int3(0, -1, 0);
    return Unk_Int3(0, 0, 0);
}

// @0x1410bb950
int CubeMapInformationService::FUN_1410bb950(Unk_Int3 pt)
{
    MS2Ptr<Cube> spCube(FUN_1410b8a60(pt));
    while (spCube.get() != 0) {
        if (spCube->field50 != 0)
            return spCube->field50;
        pt.z = pt.z - 1;
        spCube.AssignRaw(FUN_1410b8a60(pt));
    }
    return 0;
}
// @0x1410bba60
void CubeMapInformationService::FUN_1410bba60(int nKey)
{
    Unk_Int3 pt = FUN_1408a0400(nKey);
    FUN_1410bb950(pt);
}

// @0x1410bbab0
int CubeMapInformationService::FUN_1410bbab0(int nKey)
{
    if (reinterpret_cast<Unk_CMISTreeV<262>*>(&fd8)->FUN_141157900(nKey).FUN_1411275c0(reinterpret_cast<Unk_CMISTreeV<262>*>(&fd8)->FUN_141151c70())) {
        Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nKey);
        Unk_CMISListIter it;
        Unk_CMISListEnd itListEnd;
        for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
            int nCell = *FUN_1403e8d70(&it);
            Unk_Int3 pt = FUN_1408a0400(nCell);
            pt.z = pt.z + 1;
            if (FUN_1410b7f90(pt))
                return 1;
        }
    }
    return 0;
}
// @0x1410bbc00
// MS2-FUNCTIONAL: identical code and slot layout, but the frame is 0x10 larger than the exe (unreferenced temporary)
void CubeMapInformationService::FUN_1410bbc00(int nKey, int nUnused)
{
    if (reinterpret_cast<Unk_CMISTreeV<262>*>(&fd8)->FUN_141157900(nKey).FUN_141126e90(reinterpret_cast<Unk_CMISTreeV<262>*>(&fd8)->FUN_141151c70())) {
        Unk_CMISIntList kEmpty;
        FUN_141126700(FUN_141127e10(&fd8, &nKey), &kEmpty);
    }
    FUN_1410bbcd0(nKey, 0);
}

// @0x1410bc1c0
void CubeMapInformationService::FUN_1410bc1c0()
{
    if (!FUN_1411516e0(&f238)) {
        Unk_CMISHouseMark* pHouse = FUN_1410dc020();
        if (pHouse != 0) {
            Unk_CMISIter<274> it, itEnd;
            for (FUN_14114dc90(&f238, &it); FUN_141127440(&it, FUN_141151a30(&f238, &itEnd)); FUN_141129ac0(&it)) {
                if (FUN_141126b10(&FUN_1411285a0(&it)->second, 0))
                    continue;
                pHouse->FUN_14198cb00(*FUN_141128800(&FUN_1411285a0(&it)->second));
            }
        }
    }
    Unk_CMISIter<273> itMark, itMarkEnd;
    for (FUN_14114dde0(&f228, &itMark); FUN_141127500(&itMark, FUN_141151b50(&f228, &itMarkEnd)); FUN_141129b70(&itMark)) {
        Unk_CMISPolyObj* pObj = FUN_1411284c0(&FUN_141128600(&itMark)->second);
        pObj->vfunc_2();
    }
}
// @0x1410bc320
void CubeMapInformationService::FUN_1410bc320()
{
    Unk_CMISHouseMark* pHouse = FUN_1410dc020();
    if (pHouse != 0)
        pHouse->FUN_14198cf50();
    Unk_CMISIter<273> itMark, itMarkEnd;
    for (FUN_14114dde0(&f228, &itMark); FUN_141127500(&itMark, FUN_141151b50(&f228, &itMarkEnd)); FUN_141129b70(&itMark)) {
        Unk_CMISPolyObj* pObj = FUN_1411284c0(&FUN_141128600(&itMark)->second);
        pObj->vfunc_3();
    }
}

// @0x1410bf250
// MS2-FUNCTIONAL: exe local slot/branch layout differs by 2 bytes
void CubeMapInformationService::FUN_1410bf250(const CString* pKey)
{
    int n;
    Unk_CMISIter<270> itEnd, itFind;
    if (FUN_141127740(FUN_141158000(&f358, &itFind, pKey), FUN_141151fd0(&f358, &itEnd))) {
        n = *FUN_1411280d0(&f358, pKey);
        *FUN_1411280d0(&f358, pKey) = n + 1;
    } else {
        *FUN_1411280d0(&f358, pKey) = 1;
    }
}
// @0x1410bf320
void CubeMapInformationService::FUN_1410bf320(const CString* pKey)
{
    Unk_CMISIter<270> itEnd, itFind;
    if (FUN_141127740(FUN_141158000(&f358, &itFind, pKey), FUN_141151fd0(&f358, &itEnd))) {
        int n = *FUN_1411280d0(&f358, pKey);
        if (0 < n)
            n = n - 1;
        *FUN_1411280d0(&f358, pKey) = n;
    }
}
// @0x1410bf3e0
int CubeMapInformationService::FUN_1410bf3e0(const CString* pKey)
{
    Unk_CMISIter<270> itEnd, itFind;
    if (FUN_141127740(FUN_141158000(&f358, &itFind, pKey), FUN_141151fd0(&f358, &itEnd))) {
        int nVal = *FUN_1411280d0(&f358, pKey);
        return nVal;
    }
    return 0;
}
// @0x1410c3e00
unsigned char CubeMapInformationService::FUN_1410c3e00(int nKey) { return *FUN_141128310(&f368, &nKey); }
// @0x1410c3e40
void CubeMapInformationService::FUN_1410c3e40(int nKey, unsigned char v) { *FUN_141128310(&f368, &nKey) = v; }
// @0x1410c3e80
int CubeMapInformationService::FUN_1410c3e80(int nKey)
{
    Unk_CMISIter<281> itEnd, itFind;
    if (FUN_1408b7170(FUN_141158460(&f378, &itFind, &nKey), FUN_141152210(&f378, &itEnd)))
        return 0;
    return *FUN_141128290(&f378, &nKey);
}
// @0x1410c3f10
void CubeMapInformationService::FUN_1410c3f10(int nKey, int v) { *FUN_141128290(&f378, &nKey) = v; }
// @0x1410c3f50
void CubeMapInformationService::FUN_1410c3f50(int n)
{
    if (f1dc == n)
        return;
    f1dc = n;
    GenerateFloorPhysX();
}
// @0x1410c3fa0
int CubeMapInformationService::FUN_1410c3fa0() { return f1dc; }
// @0x1410c2fe0
void CubeMapInformationService::FUN_1410c2fe0(void*) {}
// @0x1410cb900
bool CubeMapInformationService::FUN_1410cb900() { return f248; }
// @0x1410ce7e0
Unk_CMISTree<260>* CubeMapInformationService::FUN_1410ce7e0() { return &f98; }
// @0x1410cef40
efd::AsyncResult CubeMapInformationService::OnShutdown()
{
    FUN_1410d0310();
    return efd::AsyncResult_Complete;
}
// @0x1410cf130
void CubeMapInformationService::FUN_1410cf130(void*, void* p) { FUN_1409fabe0(p); }
// @0x1410d3360
Unk_CMISTree<268>* CubeMapInformationService::FUN_1410d3360() { return &f138; }
// @0x1410d3380
Unk_CMISTree<269>* CubeMapInformationService::FUN_1410d3380() { return &f148; }
// @0x1410d4660
ATL::CAtlArray<Unk_CMISElem388*>* CubeMapInformationService::FUN_1410d4660() { return &a388; }
// @0x1410d4920
ATL::CAtlArray<Unk_CMISElem3a8*>* CubeMapInformationService::FUN_1410d4920() { return &a3a8; }
// @0x1410d5530
bool CubeMapInformationService::FUN_1410d5530() { return f3dc; }
// @0x1410d5700
void CubeMapInformationService::FUN_1410d5700(unsigned __int64 v) { f420 = v; }
// @0x1410d5730
unsigned __int64 CubeMapInformationService::FUN_1410d5730() { return f420; }
// @0x1410d5750
void CubeMapInformationService::FUN_1410d5750(unsigned __int64 v) { f428 = v; }
// @0x1410d5780
unsigned __int64 CubeMapInformationService::FUN_1410d5780() { return f428; }
// @0x1410d5ab0
void CubeMapInformationService::FUN_1410d5ab0() { FUN_14115ab30(&f98); }
// @0x1410d5ae0
void CubeMapInformationService::FUN_1410d5ae0(int v) { f450 = v; }
// @0x1410d5b00
int CubeMapInformationService::FUN_1410d5b00() { return f450; }
// @0x1410cb8b0
void CubeMapInformationService::FUN_1410cb8b0(bool b)
{
    f248 = b;
    if (f248)
        f24c = FUN_140869420();
}
// @0x1410cb920
bool CubeMapInformationService::FUN_1410cb920(int n)
{
    if (!f248)
        return false;
    return FUN_140869420() > (unsigned)(f24c + n);
}
// @0x1410d2ee0
int CubeMapInformationService::FUN_1410d2ee0() { return FUN_141151720(&fb8); }
// @0x1410d2f10
int CubeMapInformationService::FUN_1410d2f10() { return FUN_140374410(FUN_141bd3060(FUN_1403ed2d0())); }
// @0x1410d2f40
int CubeMapInformationService::FUN_1410d2f40(int nKey)
{
    Unk_CMISIter<278> itEnd, itFind;
    if (FUN_141127380(FUN_141157040(&f2b8, &itFind, &nKey), FUN_141151910(&f2b8, &itEnd)))
        return 1;
    return 0;
}
// @0x1410d54f0
void CubeMapInformationService::FUN_1410d54f0(bool b)
{
    if (DAT_143ab2820 != FUN_1410c3180())
        return;
    f3dc = b;
}
// @0x1410d5550
int CubeMapInformationService::FUN_1410d5550(int nKey)
{
    Unk_CMISIter<282> itTmp, itEnd;
    Unk_CMISIter<282> it = *FUN_1411582a0(&f3c8, &itTmp, &nKey);
    if (FUN_141127110(&it, FUN_141152150(&f3c8, &itEnd)))
        return 0;
    return FUN_1411284e0(&it)->m_val;
}
// @0x1410d55d0
void CubeMapInformationService::FUN_1410d55d0(int a, int b)
{
    if (FUN_140885340(&f208)->FUN_140375130()) {
        FUN_1408a06a0(f1b8, f1b4);
        return;
    } else {
        FUN_1408a06a0(a, b);
    }
}
// @0x1410d5640
bool CubeMapInformationService::FUN_1410d5640()
{
    if (FUN_1410d2f10() == 0)
        return false;
    if (FUN_1410c35c0())
        return false;
    if (FUN_1410c3180() != DAT_143ab2820)
        return false;
    return true;
}
// @0x1410d56a0
bool CubeMapInformationService::FUN_1410d56a0()
{
    if (FUN_1410d2f10() == 0)
        return false;
    if (!FUN_1410c35c0())
        return false;
    if (FUN_1410c3180() != DAT_143ab2820)
        return false;
    return true;
}
// @0x1410d57a0
void CubeMapInformationService::FUN_1410d57a0(unsigned __int64 key)
{
    Unk_CMISIter<286> itEnd, itFind;
    Unk_CMISInsRes res;
    if (FUN_1403344a0(FUN_1404c0270(&f430, &itFind, &key), FUN_140341f40(&f430, &itEnd)))
        return;
    FUN_1404422b0(&f430, &res, &key);
}
// @0x1410d5830
void CubeMapInformationService::FUN_1410d5830(unsigned __int64 key)
{
    Unk_CMISIter<286> itEnd, itFind;
    if (FUN_140334210(FUN_1404c0270(&f430, &itFind, &key), FUN_140341f40(&f430, &itEnd)))
        return;
    FUN_1404bfb40(&f430, &key);
}
// @0x1410d58c0
bool CubeMapInformationService::FUN_1410d58c0(unsigned __int64 key)
{
    Unk_CMISIter<286> itEnd, itFind;
    if (FUN_1403344a0(FUN_1404c0270(&f430, &itFind, &key), FUN_140341f40(&f430, &itEnd)))
        return true;
    return false;
}
// @0x1410d5930
void CubeMapInformationService::FUN_1410d5930(Unk_CMISTree<286>* pOut)
{
    Unk_CMISIter<286> it, itEnd;
    Unk_CMISInsRes res;
    for (FUN_140340ff0(&f430, &it); FUN_1403344a0(&it, FUN_140341f40(&f430, &itEnd)); FUN_140334ef0(&it))
        FUN_1404422b0(pOut, &res, FUN_1408f2950(&it));
}
// @0x1410c5420
void* CubeMapInformationService::FUN_1410c5420(Unk_CMISEntityRef key)
{
    Unk_CMISIter<257> itEnd, itFind;
    if (FUN_141127050(FUN_1411580e0(&f48, &itFind, &key), FUN_141152030(&f48, &itEnd)))
        return 0;
    return *FUN_141128110(&f48, &key);
}
// @0x1410cb420
int CubeMapInformationService::FUN_1410cb420(const Unk_CMISEntityRef* pRef)
{
    Unk_CMISIter<265> it, itEnd;
    for (FUN_14114e010(&f108, &it); FUN_141127640(&it, FUN_141151d30(&f108, &itEnd)); FUN_141129bd0(&it)) {
        if (pRef->FUN_140965410(reinterpret_cast<const Unk_1401cd100&>(FUN_1411286a0(&it)->m_ref)))
            return 1;
    }
    return 0;
}
// @0x1410d2730
int CubeMapInformationService::FUN_1410d2730(const Unk_Int3* pPt)
{
    if (FUN_1410c3180() != 0) {
        if (pPt->x < p300.x || pPt->y < p300.y)
            return 0;
        if (pPt->x > p30c.x || pPt->y > p30c.y)
            return 0;
    }
    return 1;
}
// @0x1410d4340
int CubeMapInformationService::FUN_1410d4340(Unk_CubePoint* pOut)
{
    if (FUN_140965240(&f208, 0))
        return 0;
    if (FUN_140885340(&f208)->FUN_140375130() == 0)
        return 0;
    memcpy(pOut, &p300, 12);
    return 1;
}
// @0x1410c4d80
void CubeMapInformationService::FUN_1410c4d80(const Unk_StreamPoint& pt, float fDist)
{
    FUN_1408a15b0(pt, DAT_143b01a60);
    FUN_1410c2840(pt, fDist);
}
// @0x1410c68e0
bool CubeMapInformationService::FUN_1410c68e0()
{
    FUN_14114f0e0(&f98);
    FUN_14114fa40(&fa8);
    FUN_14114f0e0(&fb8);
    FUN_1410b2760(&f2a8);
    FUN_14114f360(&fd8);
    FUN_14114f2c0(&fc8);
    FUN_1402237c0(&a458);
    return true;
}
// @0x1410d2340
// MS2-FUNCTIONAL: the exe materialises both compare results in int temps (locals layout differs)
bool CubeMapInformationService::FUN_1410d2340(const Unk_CMISPt2* a, const Unk_CMISPt2* b, float fLimX, float fLimY)
{
    return FUN_14029d220(a->x - b->x) <= fLimX && FUN_14029d220(a->y - b->y) <= fLimY;
}
// @0x1410caa60
void CubeMapInformationService::FUN_1410caa60(const CString* pKey, int v)
{
    Unk_CMISIter<270> itEnd, itFind;
    if (FUN_141127740(FUN_141158000(&f1a0, &itFind, pKey), FUN_141151fd0(&f1a0, &itEnd)))
        FUN_1411552b0(&f1a0, pKey);
    *FUN_1411280d0(&f1a0, pKey) = v;
}
// @0x1410c51d0
void CubeMapInformationService::FUN_1410c51d0(int nA, int nB, CStringW strName)
{
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB);
    if (spOwner == 0)
        return;
    spOwner->ownerName = strName;
}
// @0x1410c8030
__int64 CubeMapInformationService::FUN_1410c8030(int nA, int nB)
{
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB);
    if (spOwner == 0)
        return 0;
    return spOwner->ownerID;
}
// @0x1410cba80
int CubeMapInformationService::FUN_1410cba80(int nDir, int nField50, Unk_Int3* pCell, Unk_CMISPt3* pPos)
{
    Cube* pCube = FUN_1410b8a60(*pCell);
    if (pCube == 0 || pCube->field50 != nField50 || pCube->field44 == 0) {
        if (nDir != 1) {
            pPos->z -= 150.0f;
            pCell->z -= 1;
        }
        return 1;
    }
    return 0;
}
// @0x1410ce3f0
void CubeMapInformationService::FUN_1410ce3f0(Unk_CubeOwnerPtr spOwner)
{
    Unk_CMISIter<269> itEnd, itFind;
    if (FUN_140965380(FUN_14096ae20(&f148, &itFind, &spOwner->ownerID), FUN_14096ad60(&f148, &itEnd)))
        *FUN_1409656d0(&f148, &spOwner->ownerID) = spOwner;
}
// @0x1410ce4b0
void CubeMapInformationService::FUN_1410ce4b0(Unk_CubeOwnerPtr spOwner)
{
    Unk_CMISIter<269> itEnd, itFind;
    if (FUN_1409654d0(FUN_14096ae20(&f148, &itFind, &spOwner->ownerID), FUN_14096ad60(&f148, &itEnd)))
        FUN_141156310(&f148, &spOwner->ownerID);
}
// @0x1410c5280
void CubeMapInformationService::FUN_1410c5280(int nKey)
{
    Unk_CMISIter<265> itEnd, itFind;
    if (FUN_141127640(FUN_141157ac0(&f2c8, &itFind, &nKey), FUN_141151d30(&f2c8, &itEnd))) {
        FUN_1410c5340(*FUN_141127ed0(&f2c8, &nKey));
        FUN_1411547a0(&f2c8, &nKey);
    }
}
// @0x1410c5340
void CubeMapInformationService::FUN_1410c5340(Unk_CMISEntityRef ref)
{
    void* pObj = FUN_1410c5420(ref);
    if (pObj != 0) {
        Unk_CMISPhysScene* pScene = FUN_14168a1c0(FUN_1409f7ca0());
        if (pScene != 0) {
            FUN_14168a540(FUN_1409f7ca0(), 0);
            pScene->RemoveActor(pObj);
            FUN_141bc8e00(FUN_1403ed2d0());
            FUN_14168a570(FUN_1409f7ca0());
            FUN_1411554c0(&f48, &ref);
            FUN_1411556d0(&f58, &ref);
        }
    }
}
// @0x1410c6070
void CubeMapInformationService::FUN_1410c6070()
{
    if (f40 != 0) {
        Unk_CMISPhysScene* pScene = FUN_14168a1c0(FUN_1409f7ca0());
        if (pScene != 0) {
            FUN_14168a540(FUN_1409f7ca0(), 0);
            pScene->RemoveActor(f40);
            FUN_141bc8e00(FUN_1403ed2d0());
            FUN_14168a570(FUN_1409f7ca0());
        }
        f40 = 0;
    }
}
// @0x1410c6820
void CubeMapInformationService::FUN_1410c6820(int nIdx)
{
    if (f318[nIdx] != 0) {
        Unk_CMISPhysScene* pScene = FUN_14168a1c0(FUN_1409f7ca0());
        if (pScene != 0) {
            FUN_14168a540(FUN_1409f7ca0(), 0);
            pScene->RemoveActor(f318[nIdx]);
            FUN_141bc8e00(FUN_1403ed2d0());
            FUN_14168a570(FUN_1409f7ca0());
        }
        f318[nIdx] = 0;
    }
}
// @0x1410c3020
void CubeMapInformationService::FUN_1410c3020(int nField)
{
    f1b0 = nField;
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&f98, &it); FUN_1411274c0(&it, FUN_141151af0(&f98, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 != 0)
            continue;
        spCube->field54 = nField;
    }
}
// @0x1410c54a0
Unk_StreamPoint CubeMapInformationService::FUN_1410c54a0(Unk_EntRef spEnt)
{
    Unk_StreamPoint ptRes(150.0f, 150.0f, 150.0f);
    Unk_StreamPoint ptProp;
    FUN_1409618c0(FUN_1408a9280(&spEnt), 0xcb086a2d, &ptProp);
    if (ptProp.FUN_140552700(DAT_143b01a60))
        ptRes = ptProp;
    return ptRes;
}
// @0x1410ce560
void CubeMapInformationService::FUN_1410ce560()
{
    Unk_CMISIter<260> it, itEnd, itOld;
    for (FUN_14114dd70(&f98, &it); FUN_1411274c0(&it, FUN_141151af0(&f98, &itEnd)); FUN_141129b00(&it, &itOld, 0))
        FUN_1410c1910(FUN_1408a0400(FUN_1411285e0(&it)->first), 1);
}
// @0x1410ce310
int CubeMapInformationService::FUN_1410ce310()
{
    int nCount = 0;
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube.get() != 0) {
            if (FUN_1408b5620(FUN_1408b4f20(spCube.operator->())) != 0)
                nCount = nCount + 1;
        }
    }
    return nCount;
}
// @0x1410d33a0
int CubeMapInformationService::FUN_1410d33a0(int nKey, Unk_StreamPoint* pOut)
{
    Unk_CMISIter<274> itEnd, itFind;
    if (FUN_141127440(FUN_1411573c0(&f238, &itFind, &nKey), FUN_141151a30(&f238, &itEnd))) {
        *pOut = FUN_141128470(FUN_141127c50(&f238, &nKey))->m_pt;
        return 1;
    }
    return 0;
}
// @0x1410c7f60
CStringW CubeMapInformationService::FUN_1410c7f60(int nA, int nB)
{
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB);
    if (spOwner == 0)
        return CStringW(L"");
    return CStringW(spOwner->ownerName);
}
// @0x1410d5b20
void CubeMapInformationService::FUN_1410d5b20(__int64 nId)
{
    if (FUN_141151760(&f78)) {
        COutPacket packet(0x37, 0);
        packet.vfunc_o10_1(0x44);
        packet.vfunc_o10_4(nId);
        FUN_140710590(packet);
        f478 = 0;
    } else {
        f478 = nId;
    }
}
// @0x1410ce800
efd::SyncResult CubeMapInformationService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    FUN_1410db490(pRegistrar, 1);
    FUN_1410db4c0(pRegistrar, 1);
    FUN_1410db460(pRegistrar, 1);
    return efd::SyncResult_Success;
}
// @0x1410ce850
efd::AsyncResult CubeMapInformationService::OnInit()
{
    FUN_1413f9830()->Subscribe(this, s_cubeMapCategory, 0, false);
    return efd::AsyncResult_Complete;
}

// @0x1410c3000
int CubeMapInformationService::FUN_1410c3000() { return f1b0; }
// @0x1410c3100
int CubeMapInformationService::FUN_1410c3100() { return f1b4; }
// @0x1410c3120
void CubeMapInformationService::FUN_1410c3120(int v) { f1b4 = v; }
// @0x1410c3140
int CubeMapInformationService::FUN_1410c3140() { return f1b8; }
// @0x1410c3160
void CubeMapInformationService::FUN_1410c3160(int v) { f1b8 = v; }
// @0x1410c3180
__int64 CubeMapInformationService::FUN_1410c3180() { return f1c0; }
// @0x1410c31a0
void CubeMapInformationService::FUN_1410c31a0(__int64 v) { f1c0 = v; }
// @0x1410c31d0
CStringW CubeMapInformationService::FUN_1410c31d0() { return s1c8; }
// @0x1410c3220
void CubeMapInformationService::FUN_1410c3220(const CStringW& s) { s1c8 = s; }
// @0x1410c3260
CStringW CubeMapInformationService::FUN_1410c3260() { return s1d0; }
// @0x1410c32b0
void CubeMapInformationService::FUN_1410c32b0(const CStringW& s) { s1d0 = s; }
// @0x1410c32f0
int CubeMapInformationService::FUN_1410c32f0() { return f1d8; }
// @0x1410c3310
void CubeMapInformationService::FUN_1410c3310(int v) { f1d8 = v; }
// @0x1410c33f0
int CubeMapInformationService::FUN_1410c33f0() { return f2f0; }
// @0x1410c3410
void CubeMapInformationService::FUN_1410c3410(int v) { f2f0 = v; }
// @0x1410c3430
int CubeMapInformationService::FUN_1410c3430() { return f2f4; }
// @0x1410c3450
void CubeMapInformationService::FUN_1410c3450(int v) { f2f4 = v; }
// @0x1410c3470
int CubeMapInformationService::FUN_1410c3470() { return f2f8; }
// @0x1410c3490
void CubeMapInformationService::FUN_1410c3490(int v) { f2f8 = v; }
// @0x1410c34b0
int CubeMapInformationService::FUN_1410c34b0() { return f2fc; }
// @0x1410c34d0
void CubeMapInformationService::FUN_1410c34d0(int v) { f2fc = v; }
// @0x1410c34f0
Unk_CMISFlags3 CubeMapInformationService::FUN_1410c34f0() { return f418; }
// @0x1410c3530
void CubeMapInformationService::FUN_1410c3530(Unk_CMISFlags3 v) { f418 = v; }
// @0x1410c3560
void CubeMapInformationService::FUN_1410c3560(bool v) { f418.a = v; }
// @0x1410c3580
void CubeMapInformationService::FUN_1410c3580(bool v) { f418.b = v; }
// @0x1410c35a0
void CubeMapInformationService::FUN_1410c35a0(bool v) { f418.c = v; }
// @0x1410c35c0
bool CubeMapInformationService::FUN_1410c35c0() { return f330 == 1; }
// @0x1410c3600
bool CubeMapInformationService::FUN_1410c3600(int v)
{
    if (f330 == v)
        return true;
    return false;
}
// @0x1410c3630
void CubeMapInformationService::FUN_1410c3630(int v) { f330 = v; }
// @0x1410c3650
int CubeMapInformationService::FUN_1410c3650() { return f330; }

// ---- w138 callees (unit-local, names invented) ----
class Unk_CMISLog { public: unsigned __int64 FUN_140353fc0(int nLevel, int nCategory, const wchar_t* pFormat, const int* pA); unsigned __int64 FUN_1403d7960(int nLevel, int nCategory, const wchar_t* pFormat, const int* pA, const int* pB); unsigned __int64 FUN_1410db4f0(int nLevel, int nCategory, const wchar_t* pFormat, const int& a, const int& b, const int& c); unsigned __int64 FUN_1401859c0(int nLevel, int nCategory, const wchar_t* pMsg); };
Unk_CMISLog* FUN_140166440();
struct Unk_CMISEntId { Unk_CMISEntId(const Unk_CMISEntId&); __int64 m_id; };
void FUN_14115b260(CCubeMotionManager* pMgr, const Unk_CMISEntityRef* pId, float fFrom, float fTo, unsigned nMs);   // AddRotate
CCubeMotionManager* FUN_1410af790();
struct Unk_CMISSlot;
class Unk_CMISMagicCube { public: void FUN_141230df0(CString strKey); void FUN_141232330(int nKey, float fRot); Unk_CMISSlot FUN_141230f60(Unk_StreamPoint ptPos, float fRange, int nPc); };
Unk_CMISMagicCube* FUN_1409670b0();
bool FUN_14034eee0(const CStringW& s, const wchar_t* pSz);                 // operator==
CStringW* FUN_141bd3080(Unk_CMISWorld*);                                   // the current map name
CStringW* FUN_140efe330(CStringW* pOut, const wchar_t* pSz, int n);
struct Unk_CMISPairRes { Unk_CMISPairRes(const Unk_CMISPairRes&); int m_a, m_b; };
Unk_CMISPairRes FUN_14111d460(const int& a, const int& b);                                          // make_pair
Unk_CMISIter<263>* FUN_141151f70(Unk_CMISTree<263>*, Unk_CMISIter<263>*);                            // end
Unk_CMISIter<263>* FUN_141157f20(Unk_CMISTree<263>*, Unk_CMISIter<263>*, const Unk_CMISPairRes&);    // find
bool FUN_141126fd0(Unk_CMISIter<263>*, Unk_CMISIter<263>*);                                          // operator==
void FUN_1411550a0(Unk_CMISTree<263>*, const Unk_CMISPairRes&);                                      // erase
void** FUN_141128090(Unk_CMISTree<263>*, const Unk_CMISPairRes&);                                    // operator[]
void* FUN_141128410(void** pSecond);                                                                 // the raw pointer of the value
Unk_CMISIter<276>* FUN_141151df0(Unk_CMISTree<276>*, Unk_CMISIter<276>*);                            // end
Unk_CMISIter<276>* FUN_141157c80(Unk_CMISTree<276>*, Unk_CMISIter<276>*, const int*);                // find
unsigned char FUN_140d7b400(Unk_CMISIter<276>*, Unk_CMISIter<276>*);                                          // operator!=
struct Unk_CMISObj498;
template <> struct Unk_CMISIter<284> { void* node; };
void FUN_141120750(Unk_CMISIter<284>*);                                                              // default ctor
Unk_CMISIter<284>* FUN_14114e7f0(Unk_CMISTree<284>*, Unk_CMISIter<284>*);                            // begin
Unk_CMISIter<284>* FUN_141152450(Unk_CMISTree<284>*, Unk_CMISIter<284>*);                            // end
bool FUN_141127900(Unk_CMISIter<284>*, Unk_CMISIter<284>*);                                          // operator!=
void* FUN_141128b30(Unk_CMISIter<284>*);                                                             // operator*
Unk_CMISObj498* FUN_1409658e0(void* pSlot);                                                          // the object of a slot
int FUN_14112e110(Unk_CMISObj498*);                                                                  // the object id
void FUN_141227780(Unk_CMISObj498*);                                                                 // release the object's link
Unk_CMISIter<284>* FUN_141129990(Unk_CMISIter<284>*, Unk_CMISIter<284>*, int);                       // operator++(int)
void FUN_141156b50(Unk_CMISTree<284>*, Unk_CMISIter<284>*, Unk_CMISIter<284>);                       // erase
Unk_CMISEntityRef* FUN_141127e90(Unk_CMISTree<265>*, const int*);                                    // operator[]
void FUN_140899bd0(Unk_CMISEntityRef* pDst, const Unk_CMISEntityRef& src);                           // operator=
struct Unk_CMISHandle388 { void* m_a; void* m_p; void* m_c; };
struct Unk_CMISHandle3a8 { void* m_a; void* m_p; void* m_c; };
unsigned __int64 FUN_140fac790(ATL::CAtlArray<Unk_CMISHandle3a8>*);                                  // GetCount
Unk_CMISHandle3a8* FUN_14112dfe0(ATL::CAtlArray<Unk_CMISHandle3a8>*, unsigned __int64);              // operator[]
void FUN_140fac570(Unk_CMISHandle3a8* pDst, const Unk_CMISHandle3a8* pSrc);                          // copy ctor
void FUN_14112d9b0(ATL::CAtlArray<Unk_CMISElem3a8*>*, const Unk_CMISHandle3a8*);                    // Add
void FUN_140fac610(Unk_CMISHandle3a8* p);                                                            // dtor
unsigned __int64 FUN_140fac7a0(ATL::CAtlArray<Unk_CMISHandle388>*);                                  // GetCount
Unk_CMISHandle388* FUN_14112e020(ATL::CAtlArray<Unk_CMISHandle388>*, unsigned __int64);              // operator[]
void FUN_140fac5b0(Unk_CMISHandle388* pDst, const Unk_CMISHandle388* pSrc);                          // copy ctor
void FUN_14112da60(ATL::CAtlArray<Unk_CMISElem388*>*, const Unk_CMISHandle388*);                    // Add
void FUN_140fac640(Unk_CMISHandle388* p);                                                            // dtor
unsigned __int64 FUN_140186260(ATL::CAtlArray<Unk_CMISElem458*>*);                                   // GetCount
int* FUN_1401844d0(ATL::CAtlArray<Unk_CMISElem458*>*, unsigned __int64);                             // operator[]
void FUN_14112d900(ATL::CAtlArray<MS2Ptr<Cube>>*, const MS2Ptr<Cube>*);                              // Add

// @0x1410c2840
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
bool CubeMapInformationService::FUN_1410c2840(Unk_StreamPoint pt, float fDist)
{
    Unk_Int3 cell;
    memcpy(&cell, &pt, sizeof(cell));
    int nKey = FUN_1408a03c0(cell);
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_141126d90(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)) == 0) {
        MS2Ptr<Cube> spCube(*FUN_141127cd0(&f98, &nKey));
        Unk_StreamPoint kRot;
        FUN_1409618c0(FUN_1408a9280(&spCube->entity), 0x68c7c29d, &kRot);
        spCube->fieldD4 = (int)fDist;
        Unk_CMISEntityRef kId(*FUN_1408b76f0(FUN_1408a9280(&spCube->entity)));
        FUN_14115b260((CCubeMotionManager*)FUN_1410af790(), &kId, kRot.z, fDist, 200);
        FUN_1409670b0()->FUN_141232330(nKey, fDist);
        return true;
    }
    FUN_140166440()->FUN_1410db4f0(1, 0x13, L"[ERROR] No cube on that position = {0}, {1}, {2}", cell.x, cell.y, cell.z);
    return false;
}
// @0x1410c3330
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410c3330(CStringW* pOut)
{
    CStringW s = FUN_1410c31d0();
    if (!FUN_14034eee0(s, L"")) {
        CStringW sMap;
        *pOut = *FUN_140efe330(&sMap, (const wchar_t*)*FUN_141bd3080(FUN_1403ed2d0()), 0);
    } else {
        *pOut = s;
    }
}
// @0x1410c79a0
void CubeMapInformationService::FUN_1410c79a0(int nA, int nB)
{
    Unk_CMISIter<263> itEnd, itFind;
    if (FUN_141126fd0(FUN_141157f20(&fe8, &itFind, FUN_14111d460(nA, nB)), FUN_141151f70(&fe8, &itEnd)) != 0)
        return;
    FUN_1411550a0(&fe8, FUN_14111d460(nA, nB));
}
// @0x1410c7c20
void* CubeMapInformationService::FUN_1410c7c20(int nA, int nB)
{
    Unk_CMISIter<263> itEnd, itFind;
    if (FUN_141126fd0(FUN_141157f20(&fe8, &itFind, FUN_14111d460(nA, nB)), FUN_141151f70(&fe8, &itEnd)) != 0)
        return 0;
    return FUN_141128410(FUN_141128090(&fe8, FUN_14111d460(nA, nB)));
}
// @0x1410cdf60
int CubeMapInformationService::FUN_1410cdf60(Unk_Int3* pA, Unk_Int3* pB)
{
    int nKey = FUN_1408a03c0(static_cast<const Unk_DkPoint&>(*pA) + static_cast<const Unk_DkPoint&>(*pB));
    if (reinterpret_cast<Unk_CMISTreeV<276>*>(&f298)->FUN_141157c80(nKey).FUN_140d7b400(reinterpret_cast<Unk_CMISTreeV<276>*>(&f298)->FUN_141151df0()))
        return 1;
    return 0;
}
// @0x1410c92e0
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410c92e0(int nId)
{
    Unk_CMISIter<284> it, itTmp, itOut, itEnd;
    FUN_141120750(&it);
    it = *FUN_14114e7f0(&f498, &itTmp);
    while (FUN_141127900(&it, FUN_141152450(&f498, &itEnd))) {
        if (FUN_14112e110(FUN_1409658e0(FUN_141128b30(&it))) == nId) {
            FUN_141227780(FUN_1409658e0(FUN_141128b30(&it)));
            FUN_141156b50(&f498, &itOut, it);
            return;
        }
        FUN_141129990(&it, &itTmp, 0);
    }
}
// @0x1410cb380
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410cb380(Unk_Int3 pt, const Unk_CMISEntityRef& ref)
{
    Unk_CMISEntityRef kRef(ref);
    if (FUN_1410cb420(&kRef) == 0) {
        int nKey = FUN_1408a13d0(*reinterpret_cast<Unk_StreamPoint*>(&pt));
        FUN_140899bd0(FUN_141127e90(&f108, &nKey), ref);
    }
}
// @0x1410d4680
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410d4680(ATL::CAtlArray<Unk_CMISHandle3a8>* pSrc)
{
    for (unsigned __int64 i = 0; i < FUN_140fac790(pSrc); i++) {
        Unk_CMISHandle3a8 h;
        FUN_140fac570(&h, FUN_14112dfe0(pSrc, i));
        FUN_14112d9b0(&a3a8, &h);
        FUN_140fac610(&h);
    }
}
// @0x1410d43c0
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410d43c0(ATL::CAtlArray<Unk_CMISHandle388>* pSrc)
{
    for (unsigned __int64 i = 0; i < FUN_140fac7a0(pSrc); i++) {
        Unk_CMISHandle388 h;
        FUN_140fac5b0(&h, FUN_14112e020(pSrc, i));
        FUN_14112da60(&a388, &h);
        FUN_140fac640(&h);
    }
}
// @0x1410d59c0
void CubeMapInformationService::FUN_1410d59c0(ATL::CAtlArray<MS2Ptr<Cube>>* pOut)
{
    for (unsigned __int64 i = 0; i < FUN_140186260(&a458); i++) {
        int nKey = *FUN_1401844d0(&a458, i);
        Unk_CMISIter<260> itEnd, itFind;
        if (FUN_1411274c0(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)))
            FUN_14112d900(pOut, FUN_141127cd0(&f98, &nKey));
    }
}

// ---- w138 batch 2 ----
struct Unk_CMISStr { __int64 m_a, m_b, m_c, m_d; };                                          // efd::utf8string (0x20)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_1407071e0(unsigned nObjCode);                                                        // the object code has a scenegraph
int FUN_140707260(unsigned nObjCode);                                                        // the object code has an animation
Unk_CMISStr* FUN_140ae18f0(Unk_CMISStr* pStr, const char* pSz);                              // operator=
Unk_CMISStr* FUN_14112cdc0(Unk_CMISStr* pStr, const char* pSz);                              // operator+=
Unk_CMISStr* FUN_14112cd90(Unk_CMISStr* pStr, Unk_CMISStr* pAdd);                            // operator+=
Unk_CMISStr* FUN_1409989e0(Unk_CMISStr* pStr, const char* pSz);                              // ctor
unsigned __int64 FUN_141158af0(Unk_CMISStr* pStr, const char* pFind, unsigned __int64 nPos); // rfind
Unk_CMISStr* FUN_14115afa0(Unk_CMISStr* pStr, Unk_CMISStr* pOut, unsigned __int64 nPos, unsigned __int64 nLen);   // substr
unsigned __int64 FUN_14208c9b0(Unk_CMISStr* pStr);                                           // length
void FUN_1408a8900(Unk_CMISStr* pStr);                                                       // dtor
void FUN_1408a20a0(egf::Entity* pEntity, unsigned nId, bool* pOut);                          // GetProperty(bool)

// @0x1410b77e0
// MS2-FUNCTIONAL: branch layout of the nested if/else and the MS2Ptr temporaries differ from the exe; same calls
int CubeMapInformationService::FUN_1410b77e0(int nItemId, Unk_CMISStr* pOut)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return 0;
    if (FUN_1407071e0(spItem->install.objCode) == 0) {
        FUN_140ae18f0(pOut, "urn:gamebryo-scenegraph:");
    } else {
        if (FUN_140707260(spItem->install.objCode) == 0)
            FUN_140ae18f0(pOut, "urn:gamebryo-scenegraph:");
        else
            FUN_140ae18f0(pOut, "urn:gamebryo-animation:");
    }
    if (FUN_1410cb980(nItemId) == 0) {
        if (spItem.get() != 0) {
            Unk_CMISStr sPath, sName;
            FUN_1409989e0(&sPath, (const char*)spItem->install.asset);
            __int64 nSlash = FUN_141158af0(&sPath, "/", (unsigned __int64)-1);
            __int64 nDot = FUN_141158af0(&sPath, ".", (unsigned __int64)-1);
            FUN_14115afa0(&sPath, &sName, nSlash + 1, (nDot - nSlash) - 1);
            if (FUN_14208c9b0(&sName) == 0)
                FUN_14112cdc0(pOut, "Empty");
            else
                FUN_14112cd90(pOut, &sName);
            FUN_1408a8900(&sName);
            FUN_1408a8900(&sPath);
        }
    } else {
        FUN_14112cdc0(pOut, "Empty");
    }
    return 1;
}
// @0x1410c5570
void CubeMapInformationService::FUN_1410c5570(Unk_EntRef spEnt)
{
    bool bFlag = false;
    FUN_1408a20a0((egf::Entity*)spEnt.FUN_1408a9280(), 0x38141815, &bFlag);
    if (bFlag == false)
        return;
    Unk_StreamPoint pt = FUN_1410c54a0(spEnt);
    GeneratePhysX(spEnt, pt);
}
// ---- w138 batch 3 ----
struct Unk_CMISCell56;
void FUN_1411230b0(Unk_CMISCell56* p);                                                      // default ctor
struct Unk_CMISCell56                                                                       // the 56-byte value of the cell tree (copy 0x141123050, dtor 0x141125ec0)
{
    Unk_CMISCell56() { FUN_1411230b0(this); }
    Unk_CMISCell56(const Unk_CMISCell56&);
    ~Unk_CMISCell56();
    void* m_pName; void* m_pB; void* m_pC; void* m_pD;                                      // +0 (32 bytes of tree/string state)
    Unk_StreamPoint m_pos;                                                                  // +0x20
    Unk_StreamPoint m_rot;                                                                  // +0x2c
};
MS2_CHECK_SIZE(Unk_CMISCell56, 56);
Unk_CMISCell56* FUN_141127b10(Unk_CMISTree<278>*, const int*);                              // operator[]
// @0x1410c2610
// MS2-FUNCTIONAL: exe keeps a constructed-flag around the 56-byte value copy (extra state)
bool CubeMapInformationService::FUN_1410c2610(Unk_Int3 pt)
{
    Unk_CMISIter<278> itEnd, itFind;
    int nKey = FUN_1408a03c0(pt);
    if (FUN_141127380(FUN_141157040(&f2b8, &itFind, &nKey), FUN_141151910(&f2b8, &itEnd)) != 0) {
        int nGroup = 0, nFloor = 0;
        Cube* pCube = FUN_1410b8a60(pt);
        if (pCube != 0) {
            nGroup = pCube->field50;
            nFloor = pCube->field54;
        }
        FUN_1410c1910(pt, 1);
        int nKey2 = FUN_1408a03c0(pt);
        Unk_CMISCell56 val(*FUN_141127b10(&f2b8, &nKey2));
        FUN_1410be0c0(pt, nGroup, nFloor, &val);
        return true;
    }
    FUN_1410c1910(pt, 0);
    return false;
}
struct Unk_CMISKeySet { Unk_CMISKeySet(); ~Unk_CMISKeySet(); void* m_a; void* m_b; void* m_c; };   // 0x18 bytes: set<int> (ctor 0x141122d00, dtor 0x141125cb0)
struct Unk_CMISSetIter { void* m_p; };
Unk_CMISIter<264>* FUN_141151970(Unk_CMISTree<264>*, Unk_CMISIter<264>*);                   // end
Unk_CMISIter<264>* FUN_141157200(Unk_CMISTree<264>*, Unk_CMISIter<264>*, const int*);       // find
bool FUN_141126c90(Unk_CMISIter<264>*, Unk_CMISIter<264>*);                                 // operator!=
void FUN_14115a8a0(Unk_CMISKeySet*, Unk_CMISCubeByKey*);                                    // insert
Unk_CMISSetIter* FUN_141152510(Unk_CMISKeySet*, Unk_CMISSetIter*);                          // end
Unk_CMISSetIter* FUN_14114e8d0(Unk_CMISKeySet*, Unk_CMISSetIter*);                          // begin
bool FUN_14076cf90(Unk_CMISSetIter*, Unk_CMISSetIter*);                                     // operator!=
int* FUN_14076d030(Unk_CMISSetIter*);                                                       // operator*
void FUN_14076d080(Unk_CMISSetIter*);                                                       // operator++
// @0x1410c2a90
// MS2-FUNCTIONAL: frame layout / EH state count differ in the cube loop
void CubeMapInformationService::FUN_1410c2a90(int nGroup)
{
    Unk_CMISIter<264> itEnd, itFind;
    if (FUN_141126c90(FUN_141157200(&ff8, &itFind, &nGroup), FUN_141151970(&ff8, &itEnd)) == 0) {
        Unk_CMISKeySet set;
        Unk_CMISIter<260> it, itEnd2;
        for (FUN_14114dd70(&f98, &it); FUN_1411274c0(&it, FUN_141151af0(&f98, &itEnd2)); FUN_141129b50(&it)) {
            MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
            if (spCube->field48 != 0) {
                if (spCube->field50 == nGroup)
                    FUN_14115a8a0(&set, FUN_1411285e0(&it));
            }
        }
        Unk_CMISKeySet* pSet = &set;
        Unk_CMISSetIter itSetEnd = *FUN_141152510(pSet, &itSetEnd);
        Unk_CMISSetIter itSet = *FUN_14114e8d0(pSet, &itSet);
        for (; FUN_14076cf90(&itSet, &itSetEnd); FUN_14076d080(&itSet))
            FUN_1410c2610(FUN_1408a0400(*FUN_14076d030(&itSet)));
    } else {
        FUN_140166440()->FUN_1401859c0(1, 0x13, L"[ERROR] SalePost entity doesn't exist");
    }
}
struct Unk_CMISEntSet { __int64 m_a, m_b, m_c, m_d, m_e; };                                                 // set<entity id> (ctor 0x141122da0, dtor 0x141125d50)
void* FUN_1409657a0(Unk_PayloadPtr<Unk_CMISObj208>*);                                        // operator bool
void FUN_141122da0(Unk_CMISEntSet*);
void FUN_141125d50(Unk_CMISEntSet*);
void FUN_141126870(Unk_CMISEntSet*, Unk_CMISEntSet*);                                       // assign
void FUN_14115a990(Unk_CMISEntSet*, const Unk_CMISEntityRef*);                              // insert
Unk_CMISIter<271>* FUN_141151cd0(Unk_CMISTree<271>*, Unk_CMISIter<271>*);                   // end
Unk_CMISIter<271>* FUN_1411579e0(Unk_CMISTree<271>*, Unk_CMISIter<271>*, const int*);       // find
unsigned char FUN_141126ed0(Unk_CMISIter<271>*, Unk_CMISIter<271>*);                        // operator!=
Unk_CMISEntSet* FUN_141127e50(Unk_CMISTree<271>*, const int*);                              // operator[]
void FUN_14098c6e0(egf::Entity*, unsigned, bool*);                                          // SetProperty(bool)
// @0x1410c2ce0
// MS2-FUNCTIONAL: std::map floors + EH state of the entity set differ from the exe's inlined tree helpers
void CubeMapInformationService::FUN_1410c2ce0(egf::Entity* pEntity)
{
    if (f218 != 0 && FUN_1409657a0(&f208) != 0) {
        if (FUN_140885340(&f208)->FUN_140375100() != 0)
            return;
        Unk_StreamPoint pt = DAT_143b01a60;
        FUN_1409618c0(pEntity, 0xfd95ca52, &pt);
        int nFound = 0;
        for (unsigned __int64 nFloor = 1; nFloor <= f218->floors.size(); ++nFloor) {
            int nKey = (int)nFloor;
            std::map<int, Unk_UGCFloor>::iterator itEnd = f218->floors.end();
            if (f218->floors.find(nKey) != itEnd) {
                if (f218->floors[nKey].startHeight <= pt.z)
                    nFound = (int)nFloor;
            }
        }
        if (nFound != 0) {
            Unk_CMISIter<271> itTmp, itTmp2;
            Unk_CMISIter<271>* pEnd = FUN_141151cd0(&f1e8, &itTmp);
            if (FUN_141126ed0(FUN_1411579e0(&f1e8, &itTmp2, &nFound), pEnd) != 0) {
                Unk_CMISEntSet setNew;
                FUN_141122da0(&setNew);
                FUN_141126870(FUN_141127e50(&f1e8, &nFound), &setNew);
                FUN_141125d50(&setNew);
            }
            Unk_CMISEntSet* pSet = FUN_141127e50(&f1e8, &nFound);
            FUN_14115a990(pSet, FUN_1408b76f0(pEntity));
            if (f1e0 != nFound) {
                bool bFlag = false;
                FUN_14098c6e0(pEntity, 0xa0b6b179, &bFlag);
            }
        }
    }
}
Unk_CMISIter<280>* FUN_141152270(Unk_CMISTree<280>*, Unk_CMISIter<280>*);                   // end
Unk_CMISIter<280>* FUN_141158540(Unk_CMISTree<280>*, Unk_CMISIter<280>*, const int*);       // find
unsigned char FUN_1408b71b0(Unk_CMISIter<280>*, Unk_CMISIter<280>*);                        // operator!=
// @0x1410c3cd0
bool CubeMapInformationService::FUN_1410c3cd0(int nKey)
{
    Unk_CMISIter<280> itEnd, itFind;
    if (FUN_1408b71b0(FUN_141158540(&f368, &itFind, &nKey), FUN_141152270(&f368, &itEnd)) != 0)
        return false;
    if (*FUN_141128310(&f368, &nKey) == 0)
        return false;
    int nState = FUN_1410c3e80(nKey);
    if (nState != 0) {
        if (FUN_1410c3180() == DAT_143ab2820 && nState == 1)
            return false;
        if (nState == 2) {
            if (FUN_1410c3180() == DAT_143ab2820)
                return false;
            Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pRoster == 0)
                return true;
            if (pRoster->FUN_141527920(FUN_1410c3180()) != 0)
                return false;
        }
    }
    return true;
}
struct Unk_CMISHouseRec { __int64 m_q0, m_q1, m_q2; int m_state, m_pad; __int64 m_value; };   // the house record (state at 0x18, value at 0x20)
int FUN_1408a0890(int, int, int*);
struct Unk_CMISHouseRef                                                                     // MS2Ptr<house record>
{
    Unk_CMISHouseRef(void* p);                                                              // 0x14111ea00
    Unk_CMISHouseRef(void** pSlot);                                                         // 0x14111e9c0 (copy of a map slot)
    ~Unk_CMISHouseRef();                                                                    // 0x141123820
    void* m_p;
    void* FUN_141128410();                                                                  // operator bool
    Unk_CMISHouseRec* FUN_1411284b0();                                                      // operator->
};
// @0x1410c8470
// MS2-FUNCTIONAL: unwind-state locals of the exe's result temporaries differ
bool CubeMapInformationService::FUN_1410c8470(int nA, int nB, int* pState, __int64* pValue)
{
    int nFlag = 0;
    FUN_1408a0890(nB, nA, &nFlag);
    int nIsOne = 0;
    if (nFlag == 1)
        nIsOne = 1;
    Unk_CMISHouseRef spHouse(FUN_1410c7c20(nA, nIsOne));
    if (spHouse.FUN_141128410() == 0 || (spHouse.FUN_1411284b0()->m_state != 4 && spHouse.FUN_1411284b0()->m_state != 1))
        return false;
    *pState = spHouse.FUN_1411284b0()->m_state;
    *pValue = spHouse.FUN_1411284b0()->m_value;
    return true;
}
struct Unk_CMISPartyRef                                                                     // MS2Ptr<party info>
{
    Unk_CMISPartyRef(void* p);                                                              // 0x14050dd40
    ~Unk_CMISPartyRef();                                                                    // 0x14050de40
    void* m_p;
    void* FUN_140fa9d30();                                                                  // operator bool
    Unk_CMISParty* FUN_14050dee0();                                                         // operator->
};
struct Unk_CMISSalable { Unk_CMISSalable(); ~Unk_CMISSalable(); void* m_pad0[4]; int m_nField20; int m_pad24; void* m_pad28[15]; void* m_pField0xa0; void* m_pad1[3]; };   // 0xc0 like Unk_UGCGroup; ctor 0x1408ad110, dtor 0x14050de70
int FUN_1408a0d30(int, Unk_CMISSalable*, int);
// @0x1410c80d0
bool CubeMapInformationService::FUN_1410c80d0(int nGroup)
{
    int nMap = FUN_1403ed2d0()->FUN_141bd3060();
    Unk_CMISSalable salable;
    if (FUN_1408a0d30(nGroup, &salable, nMap) == 0)
        return false;
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, 0);
    if (spOwner == static_cast<CubeOwner*>(0))
        return true;
    return false;
}
// @0x1410c8580
// MS2-FUNCTIONAL: unwind-state locals of the exe's result temporaries differ
int CubeMapInformationService::FUN_1410c8580(int nGroup)
{
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pRoster->FUN_141527e00() == 0) {
        Unk_CMISPartyRef spParty(pRoster->FUN_141523c50());
        if (spParty.FUN_140fa9d30() != 0) {
            if (spParty.FUN_14050dee0()->m_map == FUN_1403ed2d0()->FUN_141bd3060() && spParty.FUN_14050dee0()->m_key == nGroup)
                return 0x31;
        }
    }
    if (FUN_1410c80d0(nGroup) == 0)
        return 0x2f;
    return 0;
}
// @0x1410c78b0
Unk_CubeOwnerMap* CubeMapInformationService::FUN_1410c78b0(int nGroup)
{
    static Unk_CubeOwnerMap s_empty;
    if (reinterpret_cast<Unk_CubeOwners&>(f138).find(nGroup) == reinterpret_cast<Unk_CubeOwners&>(f138).end())
        return &s_empty;
    return &reinterpret_cast<Unk_CubeOwners&>(f138)[nGroup];
}
int FUN_1407072e0(int);
// @0x1410cb980
int CubeMapInformationService::FUN_1410cb980(int nItemId)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem.IsNull())
        return 0;
    if (spItem->install.asset.IsEmpty() && spItem->install.preset.IsEmpty())
        return 1;
    if (FUN_1407072e0(spItem->install.objCode) != 0)
        return 1;
    return 0;
}
// ---- w138 batch 4 ----
struct Unk_CMISInvEntry { __int64 m_q0, m_q1, m_q2; unsigned m_count; unsigned m_need; };    // inventory slot (count at 0x18, need at 0x1c)
struct Unk_CMISInvKey { int m_item; unsigned m_need; };
struct Unk_CMISInvPtr                                                                       // MS2Ptr<inventory slot>
{
    Unk_CMISInvPtr(int);                                                                    // 0x1408882c0
    Unk_CMISInvPtr(void* pNode);                                                            // 0x140eba830
    ~Unk_CMISInvPtr();                                                                      // 0x140888a90
    void* m_a; Unk_CMISInvEntry* m_p;
    bool FUN_141126ad0(int);                                                                // operator==
    Unk_CMISInvEntry* FUN_140889010();                                                      // operator->
};
class Unk_CMISInv
{
public:
    __int64 FUN_140ebb080();                                                                // first position
    void* FUN_140ebb100(__int64 pos);                                                       // the node at a position
    void FUN_140ebb030(__int64* pPos);                                                      // next position
    bool FUN_14088acd0(Unk_CMISInvKey* pKey, Unk_CMISInvPtr* pOut);                         // find by item and need
};
class Unk_CMISInvMgr;
Unk_CMISInvMgr* FUN_1409eed80();
Unk_CMISInv* FUN_140886640(Unk_CMISInvMgr*);
Unk_CMISIter<282>* FUN_14114e470(Unk_CMISTree<282>*, Unk_CMISIter<282>*);                   // begin
Unk_CMISIntPair* FUN_1411287a0(Unk_CMISIter<282>*);                                         // operator*
void FUN_141129cd0(Unk_CMISIter<282>*);                                                     // operator++
// @0x1410d50c0
unsigned __int64 CubeMapInformationService::FUN_1410d50c0()
{
    unsigned __int64 nTotal = 0;
    Unk_CMISInv* pInv = FUN_140886640(FUN_1409eed80());
    for (__int64 pos = pInv->FUN_140ebb080(); pos != 0; pInv->FUN_140ebb030(&pos)) {
        Unk_CMISInvPtr spSlot(pInv->FUN_140ebb100(pos));
        if (spSlot.FUN_141126ad0(0) != 0)
            continue;
        nTotal += spSlot.FUN_140889010()->m_count;
    }
    return nTotal;
}
// @0x1410d4fa0
// MS2-FUNCTIONAL: iterator/key stack slots swapped vs the exe (same calls and order)
unsigned __int64 CubeMapInformationService::FUN_1410d4fa0()
{
    unsigned __int64 nTotal = 0;
    Unk_CMISInv* pInv = FUN_140886640(FUN_1409eed80());
    Unk_CMISIter<282> it, itEnd;
    Unk_CMISInvKey key;
    for (FUN_14114e470(&f3c8, &it); FUN_141127110(&it, FUN_141152150(&f3c8, &itEnd)); FUN_141129cd0(&it)) {
        key.m_item = FUN_1411287a0(&it)->m_key;
        key.m_need = FUN_1411287a0(&it)->m_val;
        Unk_CMISInvPtr spSlot(0);
        if (pInv->FUN_14088acd0(&key, &spSlot) != 0) {
            if (key.m_need >= spSlot.FUN_140889010()->m_need)
                nTotal += spSlot.FUN_140889010()->m_count;
        }
    }
    return nTotal;
}
// @0x1410d5190
// MS2-FUNCTIONAL: iterator/key stack slots swapped vs the exe (same calls and order)
void CubeMapInformationService::FUN_1410d5190(unsigned __int64* pCubes, unsigned __int64* pOthers)
{
    Unk_CMISInv* pInv = FUN_140886640(FUN_1409eed80());
    Unk_CMISIter<282> it, itEnd;
    Unk_CMISInvKey key;
    for (FUN_14114e470(&f3c8, &it); FUN_141127110(&it, FUN_141152150(&f3c8, &itEnd)); FUN_141129cd0(&it)) {
        key.m_item = FUN_1411287a0(&it)->m_key;
        key.m_need = FUN_1411287a0(&it)->m_val;
        Unk_CMISInvPtr spSlot(0);
        if (pInv->FUN_14088acd0(&key, &spSlot) != 0) {
            if (key.m_need >= spSlot.FUN_140889010()->m_need)
                *pCubes += spSlot.FUN_140889010()->m_count;
        }
    }
    for (__int64 pos = pInv->FUN_140ebb080(); pos != 0; pInv->FUN_140ebb030(&pos)) {
        Unk_CMISInvPtr spSlot(pInv->FUN_140ebb100(pos));
        if (spSlot.FUN_141126ad0(0) != 0)
            continue;
        *pOthers += spSlot.FUN_140889010()->m_count;
    }
}
// @0x1410d5350
void CubeMapInformationService::FUN_1410d5350()
{
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube.get() != 0) {
            Unk_Int3 pos = spCube->position;
            if (pos.x < p300.x || pos.x > p30c.x || pos.y < p300.y || pos.y > p30c.y || pos.z < p300.z || pos.z > f2fc) {
                COutPacket packet(0x37, 0);
                packet.vfunc_o10_1(0x1f);
                FUN_140710590(packet);
                return;
            }
        }
    }
}
// ---- w138 batch 5 ----
struct Unk_CMISDesignInfo { __int64 m_q0, m_q1, m_q2; int m_id; int m_pad; CStringA m_name; __int64 m_value; };   // UGCMapDesignInfo (0x30)
struct Unk_CMISDesignPtr                                                                     // MS2Ptr<UGCMapDesignInfo>
{
    Unk_CMISDesignPtr(const Unk_CMISHandle388& src);                                     // 140fac5b0
    Unk_CMISDesignPtr(Unk_CMISDesignInfo* p);                                               // 14111eaa0
    ~Unk_CMISDesignPtr();                                                                   // 140fac640
    void* m_a; Unk_CMISDesignInfo* m_p;
    void* FUN_141128430();                                                                  // operator bool
    Unk_CMISDesignInfo* FUN_140fac700();                                                   // operator->
};
Unk_CMISDesignInfo* FUN_140898780(void* pMem);                                              // UGCMapDesignInfo::UGCMapDesignInfo
void FUN_14112da60(ATL::CAtlArray<Unk_CMISElem388*>*, const Unk_CMISDesignPtr*);          // Add
// @0x1410d4450
// MS2-FUNCTIONAL: exe keeps one more EH state around the new-expression result; same calls
void CubeMapInformationService::FUN_1410d4450(__int64 nId, int nIdx, CStringA strName, __int64 nValue)
{
    if (FUN_1410c3180() != nId)
        return;
    for (unsigned __int64 i = 0; i < FUN_140fac7a0(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle388>*>(&a388)); i++) {
        Unk_CMISDesignPtr spInfo(*FUN_14112e020(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle388>*>(&a388), i));
        if (spInfo.FUN_141128430() != 0 && spInfo.FUN_140fac700()->m_id == nIdx) {
            spInfo.FUN_140fac700()->m_name = strName;
            spInfo.FUN_140fac700()->m_value = nValue;
            return;
        }
    }
    void* pMem = ::operator new(0x30);
    Unk_CMISDesignInfo* pNew = 0;
    if (pMem != 0)
        pNew = FUN_140898780(pMem);
    Unk_CMISDesignPtr spNew(pNew);
    spNew.FUN_140fac700()->m_id = nIdx;
    spNew.FUN_140fac700()->m_name = strName;
    spNew.FUN_140fac700()->m_value = nValue;
    FUN_14112da60(&a388, &spNew);
}
struct Unk_CMISBlueprintInfo { __int64 m_q0, m_q1, m_q2; int m_id; int m_pad; CStringA m_name; __int64 m_value; };   // UGCMapBlueprintInfo (0x30)
struct Unk_CMISBlueprintPtr                                                                     // MS2Ptr<UGCMapBlueprintInfo>
{
    Unk_CMISBlueprintPtr(const Unk_CMISHandle3a8& src);                                     // 140fac570
    Unk_CMISBlueprintPtr(Unk_CMISBlueprintInfo* p);                                               // 14111ea50
    ~Unk_CMISBlueprintPtr();                                                                   // 140fac610
    void* m_a; Unk_CMISBlueprintInfo* m_p;
    void* FUN_141128420();                                                                  // operator bool
    Unk_CMISBlueprintInfo* FUN_140fac6f0();                                                   // operator->
};
Unk_CMISBlueprintInfo* FUN_1408987f0(void* pMem);                                              // UGCMapBlueprintInfo::UGCMapBlueprintInfo
void FUN_14112d9b0(ATL::CAtlArray<Unk_CMISElem3a8*>*, const Unk_CMISBlueprintPtr*);          // Add
// @0x1410d4710
// MS2-FUNCTIONAL: exe keeps one more EH state around the new-expression result; same calls
void CubeMapInformationService::FUN_1410d4710(__int64 nId, int nIdx, CStringA strName, __int64 nValue)
{
    if (FUN_1410c3180() != nId)
        return;
    for (unsigned __int64 i = 0; i < FUN_140fac790(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle3a8>*>(&a3a8)); i++) {
        Unk_CMISBlueprintPtr spInfo(*FUN_14112dfe0(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle3a8>*>(&a3a8), i));
        if (spInfo.FUN_141128420() != 0 && spInfo.FUN_140fac6f0()->m_id == nIdx) {
            spInfo.FUN_140fac6f0()->m_name = strName;
            spInfo.FUN_140fac6f0()->m_value = nValue;
            return;
        }
    }
    void* pMem = ::operator new(0x30);
    Unk_CMISBlueprintInfo* pNew = 0;
    if (pMem != 0)
        pNew = FUN_1408987f0(pMem);
    Unk_CMISBlueprintPtr spNew(pNew);
    spNew.FUN_140fac6f0()->m_id = nIdx;
    spNew.FUN_140fac6f0()->m_name = strName;
    spNew.FUN_140fac6f0()->m_value = nValue;
    FUN_14112d9b0(&a3a8, &spNew);
}
// ---- w138 batch 6 ----
bool FUN_1411272b0(const Unk_Int3*, const Unk_Int3*);
Unk_CMISRes16 FUN_1408a15b0(Unk_Int3, const Unk_StreamPoint&);
Unk_Int3 FUN_1408a15b0(Unk_Int3, Unk_StreamPoint&);   // same function; 12-byte result temp (0x1410cb1b0)                              // the world point of a cell (writes the xy centre)                                        // operator==
// @0x1410d2da0
int CubeMapInformationService::FUN_1410d2da0(int nKey, Unk_Int3 pt)
{
    if (reinterpret_cast<Unk_CMISTreeV<262>*>(&fd8)->FUN_141157900(nKey).FUN_141126e90(reinterpret_cast<Unk_CMISTreeV<262>*>(&fd8)->FUN_141151c70()))
        return 0;
    int nResult = 0;
    Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nKey);
    Unk_CMISListIter it;
    Unk_CMISListEnd itListEnd;
    for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
        int nCell = *FUN_1403e8d70(&it);
        Unk_Int3 cell = FUN_1408a0400(nCell);
        cell.z = cell.z + 1;
        if (FUN_1411272b0(&cell, &pt)) {
            nResult = 1;
            break;
        }
    }
    return nResult;
}
// @0x1410d23f0
// MS2-FUNCTIONAL: branch/return layout of the result differs from the exe; same calls and compares
int CubeMapInformationService::FUN_1410d23f0(int nGroup, int nBlock)
{
    int nHeight = 0;
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
    bool bNoOwner = spOwner == 0;
    spOwner = 0;
    if (!bNoOwner) {
        if (FUN_140885340(&f208)->FUN_140375130() == 0) {
            if (f218 != 0) {
                std::map<int, Unk_UGCGroup>::iterator itEnd = f218->groups.end();
                if (f218->groups.find(nGroup) != itEnd)
                    nHeight = f218->groups[nGroup].heightLimit;
            }
        } else {
            nHeight = f2fc;
        }
    }
    return nHeight;
}
// @0x1410d2130
// MS2-FUNCTIONAL: branch/return layout of the result differs from the exe; same calls and compares
bool CubeMapInformationService::FUN_1410d2130(Cube* pCube, int nDir, float fSize, float* pOutXY, Unk_StreamPoint* pOutPt)
{
    Unk_StreamPoint ptCenter;
    FUN_1408a15b0(pCube->position, ptCenter);
    float fHalf = 75.0f + fSize * 0.5f;
    *pOutPt = DAT_143b01a60;
    if (nDir == 1) {
        pOutPt->z = 225.0f;
        pOutXY[0] = ptCenter.x - fHalf;
        pOutXY[1] = ptCenter.y + fHalf;
        return true;
    } else if (nDir == 3) {
        pOutPt->z = 135.0f;
        pOutXY[0] = ptCenter.x + fHalf;
        pOutXY[1] = ptCenter.y + fHalf;
        return true;
    } else if (nDir == 5) {
        pOutPt->z = 45.0f;
        pOutXY[0] = ptCenter.x + fHalf;
        pOutXY[1] = ptCenter.y - fHalf;
        return true;
    } else if (nDir == 7) {
        pOutPt->z = 315.0f;
        pOutXY[0] = ptCenter.x - fHalf;
        pOutXY[1] = ptCenter.y - fHalf;
        return true;
    }
    return false;
}
int FUN_1410a8a90(void*);
// @0x1410d2590
int CubeMapInformationService::FUN_1410d2590(Unk_Int3 pt, int nGroup, int nBlock)
{
    Unk_Int3 cell = pt;
    cell.z = cell.z - 1;
    int nHeight = FUN_1410d23f0(nGroup, nBlock);
    if (nHeight == 0)
        return 1;
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pRoster == 0)
        return 0;
    if (pRoster->FUN_141530290() == 0)
        return 0;
    Cube* pCube = 0;
    if (FUN_1410a8a90(pRoster->FUN_141530290()) != 2)
        pCube = FUN_1410b8790(cell);
    else
        pCube = FUN_1410b8980(cell);
    if (pCube == 0)
        return 0;
    cell = pCube->position;
    if (pCube->field44 != 1)
        cell.z = cell.z - 1;
    if (cell.z > pt.z)
        return 0;
    if (cell.z + nHeight < pt.z)
        return 0;
    return 1;
}
// @0x1410c3fc0
// MS2-FUNCTIONAL: std::map floors vs the exe's inlined tree helpers; stack frame differs
void CubeMapInformationService::FUN_1410c3fc0(PCBase* pActor, float* pOutLo, float* pOutHi)
{
    if (f218 == 0) {
        *pOutLo = 0.0f;
        *pOutHi = 0.0f;
        return;
    }
    Unk_StreamPoint ptFront;
    FUN_1410b7ad0(pActor, 0, &ptFront, 0);
    Unk_StreamPoint ptCell;
    FUN_1410b7a20(ptFront, &ptCell);
    int nFound = 0;
    for (unsigned __int64 nFloor = 1; nFloor <= (unsigned __int64)(__int64)f1dc; ++nFloor) {
        int nKey = (int)nFloor;
        std::map<int, Unk_UGCFloor>::iterator itEnd = f218->floors.end();
        if (f218->floors.find(nKey) != itEnd) {
            if (f218->floors[nKey].startHeight <= ptCell.z)
                nFound = (int)nFloor;
        }
    }
    if (nFound != 0) {
        Unk_UGCFloor& floor = f218->floors[nFound];
        *pOutLo = floor.startHeight;
        *pOutHi = floor.startHeight + (float)floor.field4 * 150.0f;
    }
}
// ---- w138 batch 4 ----
struct Unk_CMISItemData { char pad[0x1c4]; int field1c4; };
class Unk_CMISItemRef                                                                       // item ptr passed by value (the callee destroys it)
{
public:
    ~Unk_CMISItemRef();                                                                     // 0x1401b50d0
    Unk_CMISItemData* FUN_1401b52a0();
    void* FUN_140203c60();
    bool IsSet() { return FUN_140203c60() ? true : false; }
    void* m_unknown;
    void* m_pObject;
};
bool FUN_140930c90(__int64 nOwner);
bool FUN_140930d20(__int64 nOwner);
extern int DAT_143ae0fb4;
// @0x1410c6980
// MS2-FUNCTIONAL: item-ptr bool test is an inlined operator bool with a byte temporary in the exe; frame 0x4 larger
int CubeMapInformationService::FUN_1410c6980(Cube* pCube, int nKind, Unk_CMISItemRef rItem, __int64 nOwner, int nMode)
{
    if (DAT_143ae0fb4 != 0)
        return 1;
    if (FUN_1408a07b0(FUN_1403ed2d0()->FUN_141bd3060(), DAT_1439f4a7c, DAT_143ab2820))
        return 1;
    switch (nMode) {
    case 3: {
        if (rItem.IsSet() && rItem.FUN_1401b52a0()->field1c4 != 0)
            return 0;
        __int64 nCur = FUN_1410c8030(pCube->field50, pCube->field54);
        if (nCur != nOwner && !FUN_140930c90(nCur) && !FUN_140930d20(nCur))
            return 0;
        break;
    }
    case 4: {
        __int64 nCur = FUN_1410c8030(pCube->field50, pCube->field54);
        if (nCur != nOwner && !FUN_140930c90(nCur) && !FUN_140930d20(nCur))
            return 0;
        break;
    }
    }
    return 1;
}
struct Unk_CMISSaleState { Unk_CMISSaleState(); char m_pad[0x28]; };                        // ctor 0x141123290
void FUN_141126340(void** pSlot, Unk_CMISHouseRef& rRef);                                   // assign into a map slot
// @0x1410c7a50
// MS2-FUNCTIONAL: exe keeps the iterators and make_pair results in unwind-state temporaries
void CubeMapInformationService::FUN_1410c7a50(int nA, int nB, int nState, __int64 nValue)
{
    Unk_CMISIter<263> itEnd;
    Unk_CMISIter<263> itFind;
    if (FUN_141126fd0(FUN_141157f20(&fe8, &itFind, FUN_14111d460(nA, nB)), FUN_141151f70(&fe8, &itEnd)) != 0) {
        Unk_CMISHouseRef spNew(new Unk_CMISSaleState());
        FUN_141126340(FUN_141128090(&fe8, FUN_14111d460(nA, nB)), spNew);
    }
    Unk_CMISHouseRef spHouse(FUN_141128090(&fe8, FUN_14111d460(nA, nB)));
    spHouse.FUN_1411284b0()->m_state = nState;
    spHouse.FUN_1411284b0()->m_value = nValue;
    FUN_1410bbcd0(nA, nB);
}
// @0x1410c81c0
// MS2-FUNCTIONAL: exe spills the iterator and list temporaries; frame is larger
int CubeMapInformationService::FUN_1410c81c0(int nGroup, int* pnWidth, int* pnHeight, int* pnDepth)
{
    *pnWidth = 0;
    *pnHeight = 0;
    *pnDepth = 0;
    if (FUN_140965240(&f208, 0))
        return 0;
    if (FUN_140885340(&f208)->FUN_140375130())
        nGroup = 1;
    Unk_CMISIter<262> itEnd, itFind;
    if (FUN_141126e90(FUN_141157900(&fd8, &itFind, &nGroup), FUN_141151c70(&fd8, &itEnd)))
        return 0;
    int nMinX = 0x7fffffff, nMaxX = -0x7fffffff - 1;
    int nMinY = 0x7fffffff, nMaxY = -0x7fffffff - 1;
    Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
    Unk_CMISListIter it;
    Unk_CMISListEnd itListEnd;
    for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
        Unk_Int3 pt = FUN_1408a0400(*FUN_1403e8d70(&it));
        if (FUN_1410b8980(pt) != 0) {
            if (pt.x < nMinX)
                nMinX = pt.x;
            if (nMaxX < pt.x)
                nMaxX = pt.x;
            if (pt.y < nMinY)
                nMinY = pt.y;
            if (nMaxY < pt.y)
                nMaxY = pt.y;
        }
    }
    *pnWidth = nMaxX - nMinX + 1;
    *pnHeight = f218->groups[nGroup].heightLimit + 1;
    *pnDepth = nMaxY - nMinY + 1;
    return 1;
}
// @0x1410c88b0
// MS2-FUNCTIONAL: std::map floors vs the exe's inlined tree helpers; stack frame differs
int CubeMapInformationService::FUN_1410c88b0(PCBase* pActor)
{
    int nFound = 0;
    if (f218 == 0)
        return 0;
    Unk_StreamPoint ptFront;
    FUN_1410b7ad0(pActor, 0, &ptFront, 0);
    Unk_StreamPoint ptCell;
    FUN_1410b7a20(ptFront, &ptCell);
    for (unsigned __int64 nFloor = 1; nFloor <= (unsigned __int64)(__int64)f1dc; ++nFloor) {
        int nKey = (int)nFloor;
        std::map<int, Unk_UGCFloor>::iterator itEnd = f218->floors.end();
        if (f218->floors.find(nKey) == itEnd)
            continue;
        if (f218->floors[nKey].startHeight <= ptCell.z)
            nFound = (int)nFloor;
    }
    return nFound;
}
__int64 FUN_141656ad0(Unk_CMISRoster*);
// @0x1410ca900
int CubeMapInformationService::FUN_1410ca900(int nGroup)
{
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pRoster != 0) {
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (!(spOwner == 0)) {
            if (spOwner->ownerID == FUN_141656ad0(pRoster)) {
                Unk_CMISListIter it;
                Unk_CMISListEnd itListEnd;
                Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
                if (FUN_14035ea60(FUN_14114e630(pList, &it), FUN_1411522d0(pList, &itListEnd)))
                    return 1;
            }
        }
    }
    return 0;
}
// @0x1410cdd80
int CubeMapInformationService::FUN_1410cdd80(Unk_StreamPoint* pFrom, Unk_StreamPoint* pTo, float fDist, Unk_Int3* pOffset)
{
    if (DAT_143ae0fb4 != 0)
        return 1;
    if (FUN_1408a07b0(FUN_1403ed2d0()->FUN_141bd3060(), DAT_1439f4a7c, DAT_143ab2820))
        return 1;
    Unk_StreamPoint ptHit;
    FUN_1410b7ba0(*pFrom, *pTo, -fDist, &ptHit, 0);
    Unk_Int3 kCell = FUN_1408a1430(ptHit);
    kCell = static_cast<const Unk_DkPoint&>(kCell) + static_cast<const Unk_DkPoint&>(*pOffset);
    int nKey = FUN_1408a03c0(kCell);
    Unk_CMISIter<276> itEnd, itFind;
    if (FUN_140d7b400(FUN_141157c80(&f298, &itFind, &nKey), FUN_141151df0(&f298, &itEnd)))
        return 1;
    return 0;
}
struct Unk_EntityAppFramework;
extern Unk_EntityAppFramework DAT_143b059e8;
HardwareInstancingService* FUN_14098c5b0(Unk_EntityAppFramework*);
int FUN_1413d6890(HardwareInstancingService*, egf::Entity*);
egf::Entity* FUN_14112e0d0(const egf::EntityChangeMessage*);
void FUN_1408b4fd0(Cube* pCube, egf::Entity* pEntity);                                      // Cube::SetEntity
class Unk_CMISSvcPtr                                                                        // smart pointer to a framework service
{
public:
    Unk_CMISSvcPtr(HardwareInstancingService* p);                                           // 0x14098c7d0
    ~Unk_CMISSvcPtr();                                                                      // 0x14098cc60
    HardwareInstancingService* FUN_14098d0e0() const;                                       // operator->
    void* FUN_14098d090() const;                                                            // operator bool (returns the pointer)
private:
    void* m_p;
};
// @0x1410cef70
// MS2-FUNCTIONAL: the exe's service-pointer truth test is an inlined bool conversion with a byte temporary; frame differs
void CubeMapInformationService::FUN_1410cef70(const egf::EntityChangeMessage* pMsg, efd::Category)
{
    if (FUN_1403ed2d0()->FUN_141bcfd10() == 6)
        return;
    egf::Entity* pEntity = FUN_14112e0d0(pMsg);
    Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
    if (spInst.FUN_14098d090() != 0 && FUN_1413d6890(spInst.FUN_14098d0e0(), pEntity) != 0)
        return;
    if (FUN_1403ed2d0()->FUN_141bcfd10() == 4)
        FUN_1410cf5c0(pEntity);
    else
        FUN_1410cf160(pEntity);
    Unk_StreamPoint pt = DAT_143b01a60;
    FUN_1409618c0(pEntity, 0xfd95ca52, &pt);
    int nKey = FUN_1408a13d0(pt);
    Cube* pCube = FUN_1410b8b00(nKey);
    if (pCube != 0)
        FUN_1408b4fd0(pCube, pEntity);
    FUN_1410c5280(nKey);
}
class UIMainPlayerInfo;
__int64 FUN_140931900(int nUiId);
UIHomeInfoDialog* FUN_140bbea00(int nId);
class Unk_CMISNotifyMgr { public: void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify); };
Unk_CMISNotifyMgr* FUN_140939a10();
class Unk_CMISNotifyBuilding : public NotifyObject                                          // NotifyChangeUIBuildingCount (0x20 bytes, ctor 0x141123250)
{
public:
    Unk_CMISNotifyBuilding(const int* pCount);
    int m_nCount;
};
// @0x1410ce1e0
void CubeMapInformationService::FUN_1410ce1e0(int nNotify, const int* pCount)
{
    __int64 nInfo = FUN_140931900(0x4e5f);
    if (nInfo == 0)
        return;
    if (nNotify != 0) {
        Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pRoster == 0)
            return;
        UIHomeInfoDialog* pDlg = FUN_140bbea00(0x4ed8);
        if (pDlg != 0 && pDlg->vfunc_9() != 0)
            pDlg->FUN_1412c5690();
        FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new Unk_CMISNotifyBuilding(pCount)));
    }
}
int FUN_1408b56c0(MS2Ptr<CItemData> spItem);
int FUN_1408b58c0(MS2Ptr<CItemData> spItem);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_1408b4f20(Cube* pCube);
// @0x1410ce020
// MS2-FUNCTIONAL: the exe's by-value item-ptr copies carry fewer unwind states (10 vs 13); symbol pairing of the MS2Ptr helpers differs
void CubeMapInformationService::FUN_1410ce020(MS2Ptr<Cube> spCube)
{
    if (spCube.IsNull())
        return;
    int nItemId = FUN_1408b4f20(spCube.operator->());
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return;
    if (!spItem->FUN_14053d940()) {
        if (FUN_1408b56c0(spItem) == 0 && FUN_1408b58c0(spItem) == 0)
            return;
    }
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pRoster != 0) {
        __int64 nMe = FUN_141656ad0(pRoster);
        Cube* pCube = spCube.operator->();
        __int64 nOwner = FUN_1410c8030(spCube->field50, pCube->field54);
        if (nMe == nOwner)
            FUN_1410ce1e0(1, &nItemId);
    }
}
CStringW FUN_14028de60(int nStringId);
// @0x1410c7ce0
// MS2-FUNCTIONAL: exe spills the owner-temporary pointer through two extra locals; frame 0x10 larger
CStringW CubeMapInformationService::FUN_1410c7ce0(int nA, int nB)
{
    CStringW strText;
    bool bHasOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB) != 0;
    if (bHasOwner)
        return strText;
    strText = FUN_14028de60(0x7e7);
    int nState = 2;
    Unk_CMISHouseRef spHouse(FUN_1410c7c20(nA, nB));
    if (spHouse.FUN_141128410() != 0)
        nState = spHouse.FUN_1411284b0()->m_state;
    if (nState == 4)
        strText = FUN_14028de60(0x7e8);
    if (FUN_1410c80d0(nB) == 0)
        strText = FUN_14028de60(0x7e9);
    return strText;
}
class Unk_CMISOwnerSvc { public: int FUN_140ae52d0(int nMapId, int nGroup); };
Unk_CMISOwnerSvc* FUN_14097a780();
// @0x1410c8670
// MS2-FUNCTIONAL: exe's unwind-state / temporaries layout differs (frame 0x10 larger)
int CubeMapInformationService::FUN_1410c8670(int nGroup, int* pnFlag)
{
    int nResult = 0;
    Unk_CMISRoster* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0) {
        nResult = 0;
    } else {
        int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
        *pnFlag = 0;
        FUN_1408a0890(nMapId, nGroup, pnFlag);
        int nFlag = *pnFlag;
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nFlag == 1);
        if (spOwner.get() == 0) {
            if (pPC->FUN_141527e00() == 0) {
                Unk_CMISPartyRef spParty(pPC->FUN_141523c50());
                if (spParty.FUN_14050dee0()->m_key == nGroup) {
                    if (spParty.FUN_14050dee0()->m_map == FUN_1403ed2d0()->FUN_141bd3060())
                        nResult = 2;
                }
            }
            int nState = 2;
            Unk_CMISHouseRef spHouse(FUN_1410c7c20(nGroup, nFlag == 1));
            if (spHouse.FUN_141128410() != 0)
                nState = spHouse.FUN_1411284b0()->m_state;
            if (nState == 4)
                nResult = 1;
        } else {
            if (spOwner->ownerID == FUN_141656ad0(pPC)) {
                nResult = 2;
            } else {
                if (FUN_14097a780()->FUN_140ae52d0(nMapId, nGroup) == 0)
                    nResult = 3;
                else
                    nResult = 3;
            }
        }
    }
    return nResult;
}
// ---- sale-post effect request (shared by c4240 / c44b0) ----
void FUN_1408a10e0(Unk_CubeOwners& owners, int nGroup, int nBlock, const CStringW& strName, __int64 nOwnerId);
void FUN_1408a0eb0(Unk_CubeOwners& owners, int nGroup, int nBlock);
struct Unk_CMISEffReq                                                                       // an effect play request (0x78 bytes; ctor 0x140a52ef0, dtor 0x1405a89e0)
{
    CString m_strName;                                                                      // +0
    int m_nOwnerId;                                                                         // +8
    int m_pad_0c;
    void* m_pSlot10;                                                                        // +0x10 (the attach node)
    char m_pad_18[0x1a];
    bool m_bFlag32;                                                                         // +0x32
    char m_pad_33[0x45];
};
MS2_CHECK_SIZE(Unk_CMISEffReq, 0x78);
void FUN_140a52ef0(Unk_CMISEffReq* p);
void FUN_1405a89e0(Unk_CMISEffReq* p);
struct Unk_CMISConsts { char m_pad_00[0x128]; CString m_strCubeFlash[5]; char m_pad_150[0x2a0 - 0x150]; CString m_strRemoveEffect; CString m_strHouseEffect; char m_pad_2b0[0x300 - 0x2b0]; CString m_strSaleEffect; CString m_strCubeEffect; };   // game-wide constants (the sale-post effect name at +0x300)
Unk_CMISConsts* FUN_1401d31f0();
class Unk_CMISEffMgr { public: void FUN_1411a4a00(Unk_CMISEffReq* pRequest); int FUN_1411a49c0(Unk_CMISEffReq* pRequest); void FUN_1411a6060(int nEffect); };
Unk_CMISEffMgr* FUN_1403ed280();
bool FUN_1411273c0(Unk_CMISIter<264>*, Unk_CMISIter<264>*);                                 // operator!=
Unk_CMISEntityRef* FUN_141127b90(Unk_CMISTree<264>*, const int*);                           // operator[]
egf::Entity* FUN_1408a9090(Unk_CMISEntityRef*);                                             // the entity of a ref
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                                            // the scene root of an entity
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);                            // NiNode-checked dynamic cast
extern NiRTTI DAT_143afa4d8;
void FUN_1409fabf0(void** pSlot, NiObject* pNode);                                          // assign the attach node
// @0x1410c4240
// MS2-FUNCTIONAL: owner-ptr / iterator temporaries and the effect-request unwind states are laid out differently from the exe
void CubeMapInformationService::FUN_1410c4240(int nGroup, int nBlock, const CStringW& strName, __int64 nUnused, __int64 nOwnerId)
{
    bool bHasOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock).get() != 0;
    if (!bHasOwner) {
        FUN_1408a10e0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock, strName, nOwnerId);
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
        if (spOwner.get() != 0)
            FUN_1410ce3f0(spOwner);
        Unk_CMISIter<264> itEnd, itFind;
        if (FUN_1411273c0(FUN_141157200(&ff8, &itFind, &nGroup), FUN_141151970(&ff8, &itEnd))) {
            Unk_CMISEffReq request;
            FUN_140a52ef0(&request);
            request.m_strName = FUN_1401d31f0()->m_strSaleEffect;
            request.m_nOwnerId = 7;
            FUN_1409fabf0(&request.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(FUN_1408a9090(FUN_141127b90(&ff8, &nGroup)))));
            FUN_1403ed280()->FUN_1411a4a00(&request);
            FUN_1405a89e0(&request);
        }
    }
}
// @0x1410c44b0
// MS2-FUNCTIONAL: owner-ptr / iterator temporaries and the effect-request unwind states are laid out differently from the exe
void CubeMapInformationService::FUN_1410c44b0(int nGroup, int nBlock, int bFlag)
{
    Unk_CMISIter<262> itEnd262, itFind262;
    if (FUN_141126e90(FUN_141157900(&fd8, &itFind262, &nGroup), FUN_141151c70(&fd8, &itEnd262)) == 0) {
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
        if (spOwner == 0) {
            FUN_140166440()->FUN_1401859c0(1, 0x13, L"[ERROR] Can't find salable group to sell");
        } else {
            Unk_CMISIter<264> itEnd, itFind;
            if (FUN_141126c90(FUN_141157200(&ff8, &itFind, &nGroup), FUN_141151970(&ff8, &itEnd)) == 0) {
                if (bFlag != 0)
                    FUN_1410c2a90(nGroup);
                Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pRoster != 0) {
                    __int64 nMe = FUN_141656ad0(pRoster);
                    if (nMe == spOwner->ownerID)
                        FUN_1410ccc00(nGroup, 0, 0);
                }
                FUN_1408a0eb0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
                FUN_1410ce4b0(spOwner);
                FUN_1410cd440();
                Unk_CMISIter<264> itEnd2, itFind2;
                if (FUN_1411273c0(FUN_141157200(&ff8, &itFind2, &nGroup), FUN_141151970(&ff8, &itEnd2))) {
                    Unk_CMISEffReq request;
                    FUN_140a52ef0(&request);
                    request.m_strName = FUN_1401d31f0()->m_strSaleEffect;
                    request.m_nOwnerId = 7;
                    FUN_1409fabf0(&request.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(FUN_1408a9090(FUN_141127b90(&ff8, &nGroup)))));
                    FUN_1403ed280()->FUN_1411a4a00(&request);
                    FUN_1405a89e0(&request);
                }
            } else {
                FUN_140166440()->FUN_1401859c0(1, 0x13, L"[ERROR] Can't find salable group to sell");
            }
        }
    } else {
        FUN_140166440()->FUN_1401859c0(1, 0x13, L"[ERROR] Cant' find salable group to sell");
    }
}
// ---- w138 batch 5 ----
struct Unk_CMISBlock { Unk_CMISBlock(const Unk_CMISBlock&); ~Unk_CMISBlock(); void* m_a; void* m_b; };   // copy 14111e680, dtor 141123760
struct Unk_CMISObjHandle { void* m_a; void* m_b; };
struct Unk_CMISObjRec { char pad[0x40]; int nKind; };
class Unk_CMISWorldMgr { public: egf::Entity* FUN_1411cf440(const egf::EntityID&); void FUN_1411cf570(egf::Entity*); egf::EntityPtr FUN_1411ce7c0(efd::utf8string, efd::utf8string, NiPoint3, NiPoint3, float, int, int); };
void* FUN_1409670f0();
int FUN_140707660(int);
Unk_CMISIter<266>* FUN_1411519d0(Unk_CMISTree<266>*, Unk_CMISIter<266>*);
Unk_CMISIter<266>* FUN_1411572e0(Unk_CMISTree<266>*, Unk_CMISIter<266>*, const int*);
bool FUN_141127400(Unk_CMISIter<266>*, Unk_CMISIter<266>*);                // operator!=
Unk_CMISBlock* FUN_141127bd0(Unk_CMISTree<266>*, const int*);                // operator[]
void FUN_141153740(Unk_CMISTree<266>*, const int*);                          // erase
void FUN_14111d290(Unk_CMISTree<267>*, Unk_CMISIter<267>*, const int*);      // insert
MS2Ptr<Cube>* FUN_141128190(Unk_CMISTree<259>*, const Unk_CMISEntityRef*);
void FUN_1412304e0(Unk_CMISMagicCube*, int, int, int);
void FUN_140704ec0(Unk_CMISObjHandle*, unsigned);
void* FUN_140708ea0(Unk_CMISObjHandle*);
Unk_CMISObjRec* FUN_140708eb0(Unk_CMISObjHandle*);
void FUN_140708b20(Unk_CMISObjHandle*);
int FUN_14053c5e0(CItemData*);
int FUN_1408a0190(int);
void FUN_1408a0480(Cube*);
// @0x1410bd080
// MS2-FUNCTIONAL: transliteration with typed temporaries; the exe copies the cell points through stack blocks
bool CubeMapInformationService::FUN_1410bd080(__int64 nOwner, Unk_Int3 pt, float fRot, CubeItemInfo* pInfo, const efd::utf8string& strName,
    int nField50, int nField54, unsigned char bField4c, __int64 nUnused, int nFieldD8, Unk_PayloadPtr<NoticeCubeInfo> spNotice)
{
    if (pInfo == 0)
        return false;
    int nItemId = pInfo->itemId;
    int nCell = FUN_1408a03c0(pt);
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_1411274c0(FUN_141157580(&f98, &itFind, &nCell), FUN_141151af0(&f98, &itEnd)))
        return false;
    Unk_StreamPoint ptCell = DAT_143b01a60;
    FUN_1408a15b0(pt, ptCell);
    Unk_StreamPoint ptRot = DAT_143b01a60;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    CItemData* pItem = spItem.get();
    if (pItem == 0)
        return false;
    int nObjCode = FUN_1408a0190(FUN_14053c5e0(pItem));
    int nObjProp = pItem->install.animatable;
    Unk_CMISWorldMgr* pWorld = static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0());
    egf::EntityPtr spEnt;
    if (FUN_1407071e0(pItem->install.objCode) == 0) {
        if (pItem->install.preset.GetLength() == 0) {
            spEnt = pWorld->FUN_1411ce7c0(efd::utf8string("MS2CubeProp"), strName,
                NiPoint3(ptCell.x, ptCell.y, ptCell.z), NiPoint3(ptRot.x, ptRot.y, ptRot.z), 1.0f, nObjProp, 0);
            if (nObjProp != 0 && spEnt.data() != 0) {
                bool bFlag = false;
                if (FUN_1408a20a0(spEnt.data(), 0x23f9860e, &bFlag), bFlag == 0) {
                    if (pItem->install.useInstancing == 0) {
                        bool bOff = false;
                        FUN_14098c6e0(spEnt.data(), 0x23f9860e, &bOff);
                        bool bOff2 = false;
                        FUN_14098c6e0(spEnt.data(), 0xd9f313f2, &bOff2);
                    }
                } else {
                    bool bOn = true;
                    FUN_14098c6e0(spEnt.data(), 0xd9f313f2, &bOn);
                }
            }
        } else {
            spEnt = pWorld->FUN_1411ce7c0(efd::utf8string((const char*)pItem->install.preset), efd::utf8string(""),
                NiPoint3(ptCell.x, ptCell.y, ptCell.z), NiPoint3(ptRot.x, ptRot.y, ptRot.z), 1.0f, nObjProp, 0);
        }
    } else {
        int nTreeKey = FUN_1407072e0(pItem->install.objCode);
        int nAnim = FUN_140707660(pItem->install.objCode);
        Unk_CMISIter<266> itEnd2, itFind2;
        bool bInTree = nTreeKey != 0 && FUN_141127400(FUN_1411572e0(&f118, &itFind2, &nCell), FUN_1411519d0(&f118, &itEnd2));
        if (bInTree) {
            int nKey2 = FUN_1408a03c0(pt);
            Unk_CMISBlock rec(*FUN_141127bd0(&f118, &nKey2));
            spEnt = FUN_1410bc3d0(Unk_CMISBlock(rec));
            int nKey3 = FUN_1408a03c0(pt);
            FUN_141153740(&f118, &nKey3);
        } else if (FUN_1410c35c0() == 0 || nTreeKey == 0) {
            efd::utf8string strModel(FUN_140707260(pItem->install.objCode) == 0 ? "MS2FunctionCubeNIF" : "MS2FunctionCubeKFM");
            if (pItem->install.preset.GetLength() == 0)
                spEnt = pWorld->FUN_1411ce7c0(strModel, strName,
                    NiPoint3(ptCell.x, ptCell.y, ptCell.z), NiPoint3(ptRot.x, ptRot.y, ptRot.z), 1.0f, nObjProp, 0);
            else
                spEnt = pWorld->FUN_1411ce7c0(efd::utf8string((const char*)pItem->install.preset), efd::utf8string(""),
                    NiPoint3(ptCell.x, ptCell.y, ptCell.z), NiPoint3(ptRot.x, ptRot.y, ptRot.z), 1.0f, nObjProp, 0);
            if (nTreeKey != 0) {
                Unk_CMISIter<267> itIns;
                FUN_14111d290(&f128, &itIns, &nCell);
            }
        } else {
            unsigned nIdx = f3d8;
            f3d8 = f3d8 + 1;
            if (nIdx > 0x3f9)
                nIdx = 0x3fa;
            spEnt = FUN_1410bc7f0(ptCell, ptRot, nIdx, pInfo->itemId);
        }
        Unk_CMISObjHandle hObj;
        FUN_140704ec0(&hObj, pItem->install.objCode);
        if (FUN_140708ea0(&hObj) != 0) {
            bool bPlay = true;
            if (FUN_1410c35c0() != 0 && (nTreeKey != 0 || nAnim != 0))
                bPlay = false;
            if (bPlay)
                FUN_1412304e0(FUN_1409670b0(), nCell, nObjCode, FUN_140708eb0(&hObj)->nKind);
            if (spEnt.data() != 0 && FUN_140708eb0(&hObj)->nKind == 0xb) {
                bool bOff = false;
                FUN_14098c6e0(spEnt.data(), 0xa0b6b179, &bOff);
            }
        }
        FUN_140708b20(&hObj);
    }
    if (spEnt.data() == 0)
        return false;
    MS2Ptr<Cube> spCube(new Cube);
    spCube->field18 = nOwner;
    spCube->position = pt;
    spCube->item->FUN_1408b3700(pInfo);
    spCube->entity = spEnt;
    spCube->field44 = nObjCode;
    spCube->field50 = nField50;
    spCube->field54 = nField54;
    spCube->field48 = 1;
    spCube->field4c = bField4c;
    spCube->field70 = pItem->install.cubeProp;
    spCube->fieldD8 = nFieldD8;
    memcpy(&spCube->fieldD4, &fRot, sizeof(float));
    spCube->notice = spNotice;
    FUN_1408a0480(spCube.get());
    *FUN_141128190(&f78, FUN_1408b76f0(spCube->entity.data())) = spCube;
    if (FUN_1407071e0(spCube->fieldB4) != 0)
        *FUN_141127cd0(&f88, &nCell) = spCube;
    return true;
}
// ---- w138 batch 6 ----
// @0x1410c4850
// MS2-FUNCTIONAL: Unk_Int3 temporaries and by-value notice copies differ from the exe
void CubeMapInformationService::FUN_1410c4850(__int64 nOwner, Unk_Int3 pt, CubeItemInfo* pInfo, float fRot, int nField50, int nField54,
    unsigned char bField4c, int nUnused, int nFieldD8, Unk_PayloadPtr<NoticeCubeInfo> spNotice)
{
    if (pInfo == 0)
        return;
    efd::utf8string strName;
    int nCell = FUN_1408a03c0(pt);
    Unk_CMISIter<265> itEnd, itFind;
    if (FUN_141127640(FUN_141157ac0(&f2e0, &itFind, &nCell), FUN_141151d30(&f2e0, &itEnd)) == 0) {
        if (FUN_1410b77e0(pInfo->itemId, reinterpret_cast<Unk_CMISStr*>(&strName)) != 0) {
            FUN_1410bd080(nOwner, pt, fRot, pInfo, strName, nField50, nField54, bField4c, nUnused,
                nFieldD8, Unk_PayloadPtr<NoticeCubeInfo>(spNotice));
            FUN_1410d4cb0(pInfo->itemId, true);
            if (FUN_1410cb900()) {
                if (FUN_1410c3600(1) != 0 || FUN_1410c3600(3) != 0)
                    FUN_1410d54f0(true);
            }
        }
    } else {
        FUN_1410bca70(nOwner, pt, fRot, nField50, nField54, nUnused, nFieldD8);
    }
}
// @0x1410c4b50
void CubeMapInformationService::FUN_1410c4b50(Unk_Int3 pt, bool bKeep)
{
    Unk_StreamPoint ptCell = DAT_143b01a60;
    FUN_1408a15b0(pt, ptCell);
    int nCell = FUN_1408a03c0(pt);
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_1411274c0(FUN_141157580(&fb8, &itFind, &nCell), FUN_141151af0(&fb8, &itEnd))) {
        MS2Ptr<Cube> spCube = *FUN_141127cd0(&fb8, &nCell);
        if (spCube.get() != 0) {
            FUN_1410bec60(MS2Ptr<Cube>(spCube));
            FUN_1410d4cb0(FUN_1408b4f20(spCube.operator->()), false);
            if (FUN_1410c35c0() != 0) {
                if (FUN_1410cb900())
                    FUN_1410d54f0(true);
            }
        }
    }
    if (bKeep == 0)
        FUN_1410c2610(pt);
    else
        FUN_1410c1910(pt, 0);
}
// @0x1410c4e20
// MS2-FUNCTIONAL: MS2Ptr<Cube> temporaries and Unk_Int3 copies differ from the exe
void CubeMapInformationService::FUN_1410c4e20(__int64 nOwner, Unk_Int3 pt, CubeItemInfo* pInfo, float fRot, unsigned char bField4c, int nUnused, int nFieldD8)
{
    if (pInfo == 0)
        return;
    Unk_StreamPoint ptCell = DAT_143b01a60;
    FUN_1408a15b0(pt, ptCell);
    MS2Ptr<Cube> spCube(FUN_1410b8ab0(ptCell));
    if (spCube.get() == 0) {
        FUN_140166440()->FUN_1401859c0(0xc, 0x13, L"Not Exist ReplaceCube");
        return;
    }
    if (spCube->field48 != 0) {
        FUN_1410bec60(MS2Ptr<Cube>(spCube));
        FUN_1410d4cb0(FUN_1408b4f20(spCube.operator->()), false);
        if (FUN_1410c35c0() != 0 && FUN_1410cb900())
            FUN_1410d54f0(true);
    }
    FUN_1410c1910(FUN_1408a1430(ptCell), 1);
    efd::utf8string strName;
    if (FUN_1410b77e0(pInfo->itemId, reinterpret_cast<Unk_CMISStr*>(&strName)) != 0) {
        Unk_PayloadPtr<NoticeCubeInfo> spNone(0);
        FUN_1410bd080(nOwner, pt, fRot, pInfo, strName, spCube->field50, spCube->field54, bField4c, nUnused, nFieldD8, spNone);
        FUN_1410d4cb0(pInfo->itemId, true);
        if (FUN_1410c35c0() != 0 && FUN_1410cb900())
            FUN_1410d54f0(true);
    }
}
// ---- w138 batch 7 ----
struct Unk_CMISRec { char pad[0x3c]; Unk_CMISInvKey key; char pad2[0x50 - 0x3c - sizeof(Unk_CMISInvKey)]; int nSetId; };                                  // an item-table row (key at 0x3c)
struct Unk_CMISRecRef { void* m_a; void* m_b; };                                            // handle of an item-table row
class Unk_CMISItemTable;
Unk_CMISItemTable* FUN_140281980();
Unk_CMISRecRef* FUN_1405566e0(Unk_CMISItemTable*, Unk_CMISRecRef* pOut, int nItemId);
__int64 FUN_140df5b00(Unk_CMISRecRef*);                                                     // the handle is set
Unk_CMISRec* FUN_14056d580(Unk_CMISRecRef*);                                                // operator->
void FUN_14056c300(Unk_CMISRecRef*);                                                        // dtor
int* FUN_1411281d0(Unk_CMISTree<282>*, const int*);                                         // operator[]
bool FUN_141127840(Unk_CMISIter<282>*, Unk_CMISIter<282>*);                                 // operator!=
// @0x1410d4cb0
// MS2-FUNCTIONAL: iterator/key stack slots swapped vs the exe (same calls and order)
void CubeMapInformationService::FUN_1410d4cb0(int nItemId, bool bAdd)
{
    Unk_CMISInv* pInv = FUN_140886640(FUN_1409eed80());
    Unk_CMISRecRef rec;
    FUN_1405566e0(FUN_140281980(), &rec, nItemId);
    if (FUN_140df5b00(&rec) != 0) {
        Unk_CMISInvPtr spSlot(0);
        if (pInv->FUN_14088acd0(&FUN_14056d580(&rec)->key, &spSlot) != 0) {
            Unk_CMISIter<282> itEnd, itFind;
            if (FUN_141127110(FUN_1411582a0(&f3c8, &itFind, &FUN_14056d580(&rec)->key.m_item), FUN_141152150(&f3c8, &itEnd)) == 0) {
                int* pnCount = FUN_1411281d0(&f3c8, &FUN_14056d580(&rec)->key.m_item);
                int nNew;
                if (bAdd == 0) {
                    nNew = *pnCount - 1;
                    if (nNew < 0)
                        nNew = 0;
                } else {
                    nNew = *pnCount + 1;
                }
                *FUN_1411281d0(&f3c8, &FUN_14056d580(&rec)->key.m_item) = nNew;
            } else if (bAdd != 0) {
                *FUN_1411281d0(&f3c8, &FUN_14056d580(&rec)->key.m_item) = 1;
            }
        }
    }
    Unk_CMISIter<282> it, itEnd2;
    for (FUN_14114e470(&f3c8, &it); FUN_141127840(&it, FUN_141152150(&f3c8, &itEnd2)); FUN_141129cd0(&it)) {
        Unk_CMISInvKey key;
        key.m_item = FUN_1411287a0(&it)->m_key;
        key.m_need = FUN_1411287a0(&it)->m_val;
        Unk_CMISInvPtr spSlot2(0);
        if (pInv->FUN_14088acd0(&key, &spSlot2) != 0 && spSlot2.FUN_140889010()->m_need <= key.m_need)
            spSlot2.FUN_140889010();
    }
    t3e0.FUN_140868750(100);
    FUN_14056c300(&rec);
}
// ---- w138 batch 8: set-item effects ----
struct Unk_CMISPieceInfo { char pad[0x18]; unsigned nMax; CString strModelEffect; CString strFullEffect; CString strSetName; CString strAttachNode; };
struct Unk_CMISPieceRef { void* m_a; void* m_b; };                                          // MS2Ptr<piece info>
struct Unk_CMISPieceMap { void* m_head; unsigned __int64 m_count; };
struct Unk_CMISPieceIter { void* m_p; };
struct Unk_CMISPiecePair { int m_key; int m_pad; Unk_CMISPieceRef m_value; };
struct Unk_CMISSetInfo { char pad[0x20]; Unk_CMISPieceMap m_pieces; unsigned m_nNeed; };
struct Unk_CMISSetRef                                                                       // MS2Ptr<set info> passed by value (the callee destroys it)
{
    Unk_CMISSetRef() {}
    Unk_CMISSetRef(const Unk_CMISSetRef&);                                                  // 0x140ba0950
    ~Unk_CMISSetRef();                                                                      // 0x1409ed950
    Unk_CMISSetInfo* FUN_1409ee2d0();                                                       // operator->
    bool FUN_1409ede50(int);                                                                // operator==
    void* m_a; void* m_b;
};
struct Unk_CMISCubeList { void* m_a; void* m_b; void* m_c; };
struct Unk_CMISCountMap { void* m_head; unsigned __int64 m_count; };
struct Unk_CMISCountIter { void* m_p; };
class Unk_CMISSetEffect : public CPtred                                                      // SetItemEffectInfo (0x28; ctor 0x1411233c0)
{
public:
    Unk_CMISSetEffect();
    int m_nEffect;
    CString m_strName;
};
class Unk_CMISFlatModel { public: bool FUN_14211e240(unsigned nModel); };                   // egf::FlatModel::ContainsModel
class Unk_CMISEffSvc;
Unk_CMISListIter* FUN_140367e30(Unk_CMISCubeList*, Unk_CMISListIter*);                      // begin
Unk_CMISListEnd* FUN_140368110(Unk_CMISCubeList*, Unk_CMISListEnd*);                        // end
Unk_CMISPieceIter* FUN_1409efa80(Unk_CMISPieceMap*, Unk_CMISPieceIter*);                    // begin
Unk_CMISPieceIter* FUN_1409efe40(Unk_CMISPieceMap*, Unk_CMISPieceIter*);                    // end
Unk_CMISPieceIter* FUN_140ba1ff0(Unk_CMISPieceMap*, Unk_CMISPieceIter*, const int*);        // find
bool FUN_1409ee120(Unk_CMISPieceIter*, Unk_CMISPieceIter*);                                 // operator!=
bool FUN_1409edfd0(Unk_CMISPieceIter*, Unk_CMISPieceIter*);                                 // operator==
Unk_CMISPiecePair* FUN_1409ee2e0(Unk_CMISPieceIter*);                                       // operator*
void FUN_1409ee490(Unk_CMISPieceIter*);                                                     // operator++
Unk_CMISPieceRef* FUN_140ba0d00(Unk_CMISPieceMap*, const int*);                             // operator[] (const)
Unk_CMISPieceRef* FUN_141128010(Unk_CMISPieceMap*, const int*);                             // operator[]
void FUN_14111e900(Unk_CMISPieceRef* pDst, const Unk_CMISPieceRef* pSrc);                   // copy ctor
__int64 FUN_141128400(Unk_CMISPieceRef*);                                                   // is set
Unk_CMISPieceInfo* FUN_140ba0d40(Unk_CMISPieceRef*);                                        // operator->
void FUN_140b9cda0(Unk_CMISPieceRef*);                                                      // dtor
bool FUN_141126b50(Unk_CMISPieceRef*, int);                                                 // operator==
void FUN_14025bf00(Unk_CMISCountMap*);                                                      // ctor
void FUN_14025c810(Unk_CMISCountMap*);                                                      // dtor
Unk_CMISCountIter* FUN_140265b50(Unk_CMISCountMap*, Unk_CMISCountIter*);                    // begin
Unk_CMISCountIter* FUN_140265e30(Unk_CMISCountMap*, Unk_CMISCountIter*);                    // end
Unk_CMISCountIter* FUN_140266230(Unk_CMISCountMap*, Unk_CMISCountIter*, const int*);        // find
bool FUN_14025cdb0(Unk_CMISCountIter*, Unk_CMISCountIter*);                                 // operator!=
Unk_CMISIntPair* FUN_14025cf40(Unk_CMISCountIter*);                                         // operator*
void FUN_1403e8fb0(Unk_CMISCountIter*);                                                     // operator++
int* FUN_141127f90(Unk_CMISCountMap*, const int*);                                          // operator[]
Unk_CMISFlatModel* FUN_1408a9bd0(egf::Entity*);
egf::Entity* FUN_1408a9090(const efd::SmartPointer<egf::Entity>*);
Unk_CMISEffSvc* FUN_141b6f910();
void FUN_1409a1fc0(Unk_CMISEffSvc*, const Unk_CMISEntityRef*, const efd::utf8string*, float fScale, int nFlag);
struct Unk_CMISLimits { char pad[8]; };
struct Unk_CMISLimitF { float m_f; };
struct Unk_CMISRules { char pad[0xf80]; Unk_CMISLimitF m_fAtF80; char padF84[0xfd8 - 0xf84]; Unk_CMISLimitF m_fNear; char pad2[0x1138 - 0xfdc]; Unk_CMISLimits m_limits1138; char pad2b[0x1190 - 0x1138 - sizeof(Unk_CMISLimits)]; Unk_CMISLimits m_limits1190; char pad2c[0x1348 - 0x1190 - sizeof(Unk_CMISLimits)]; Unk_CMISLimits m_limits1348; char pad3[0x5078 - 0x1348 - sizeof(Unk_CMISLimits)]; Unk_CMISLimits m_limits5078; char pad4[0xa288 - 0x5078 - sizeof(Unk_CMISLimits)]; Unk_CMISLimits m_limits; };   // game-wide rules (limit tables at 0x1348/0x5078/0xa288)
Unk_CMISRules* FUN_1401d3200();
int* FUN_1402056b0(Unk_CMISLimits* pTable);
Unk_CMISIter<279>* FUN_141151a90(Unk_CMISTree<279>*, Unk_CMISIter<279>*);
Unk_CMISIter<279>* FUN_1411574a0(Unk_CMISTree<279>*, Unk_CMISIter<279>*, const int*);
bool FUN_141127480(Unk_CMISIter<279>*, Unk_CMISIter<279>*);                                 // operator!=
MS2Ptr<Unk_CMISSetEffect>* FUN_141127c90(Unk_CMISTree<279>*, const int*);                   // operator[]
void FUN_141153af0(Unk_CMISTree<279>*, const int*);                                         // erase
// @0x1410bf610
// MS2-FUNCTIONAL: transliteration with typed stand-ins; iterator/ref temporaries are laid out differently from the exe
void CubeMapInformationService::FUN_1410bf610(Unk_CMISCubeList* pPlaced, Unk_CMISSetRef rSet, Unk_CMISCubeList* pOthers)
{
    bool bAnyLimited = false;
    Unk_CMISPieceIter itPiece, itPieceEnd;
    FUN_1409efa80(&rSet.FUN_1409ee2d0()->m_pieces, &itPiece);
    while (FUN_1409ee120(&itPiece, FUN_1409efe40(&rSet.FUN_1409ee2d0()->m_pieces, &itPieceEnd))) {
        Unk_CMISPieceRef rPiece;
        FUN_14111e900(&rPiece, &FUN_1409ee2e0(&itPiece)->m_value);
        if (FUN_141128400(&rPiece) != 0 && FUN_140ba0d40(&rPiece)->nMax != 0) {
            bAnyLimited = true;
            FUN_140b9cda0(&rPiece);
            break;
        }
        FUN_140b9cda0(&rPiece);
        FUN_1409ee490(&itPiece);
    }
    unsigned nPlaced = 0;
    Unk_CMISCountMap mapCount;
    FUN_14025bf00(&mapCount);
    Unk_CMISListIter itCube;
    Unk_CMISListEnd itCubeEnd;
    for (FUN_140367e30(pPlaced, &itCube); FUN_14035ea60(&itCube, FUN_140368110(pPlaced, &itCubeEnd)); FUN_14035ebf0(&itCube)) {
        int nKey = *FUN_1403e8d70(&itCube);
        MS2Ptr<Cube> spCube(FUN_1410b8b00(nKey));
        if (spCube.get() != 0) {
            int nCount = 0;
            int nItem = FUN_1408b4f20(spCube.operator->());
            Unk_CMISCountIter itFind, itEnd;
            if (FUN_14025cdb0(FUN_140266230(&mapCount, &itFind, &nItem), FUN_140265e30(&mapCount, &itEnd))) {
                int nItem2 = FUN_1408b4f20(spCube.operator->());
                nCount = *FUN_141127f90(&mapCount, &nItem2);
            }
            nCount = nCount + 1;
            int nItem3 = FUN_1408b4f20(spCube.operator->());
            *FUN_141127f90(&mapCount, &nItem3) = nCount;
            nPlaced = nPlaced + 1;
        }
    }
    unsigned nLimited = 0;
    if (bAnyLimited) {
        Unk_CMISCountIter itCnt, itCntEnd;
        FUN_140265b50(&mapCount, &itCnt);
        while (FUN_14025cdb0(&itCnt, FUN_140265e30(&mapCount, &itCntEnd))) {
            int nItem = FUN_14025cf40(&itCnt)->m_key;
            unsigned nHave = FUN_14025cf40(&itCnt)->m_val;
            Unk_CMISPieceIter itFind, itEnd;
            if (FUN_1409edfd0(FUN_140ba1ff0(&rSet.FUN_1409ee2d0()->m_pieces, &itFind, &nItem), FUN_1409efe40(&rSet.FUN_1409ee2d0()->m_pieces, &itEnd)) == 0) {
                Unk_CMISPieceRef rPiece;
                FUN_14111e900(&rPiece, FUN_140ba0d00(&rSet.FUN_1409ee2d0()->m_pieces, &nItem));
                if (FUN_141126b50(&rPiece, 0) == 0) {
                    if (nHave < FUN_140ba0d40(&rPiece)->nMax)
                        nLimited = nLimited + nHave;
                    else
                        nLimited = nLimited + FUN_140ba0d40(&rPiece)->nMax;
                }
                FUN_140b9cda0(&rPiece);
            }
            FUN_1403e8fb0(&itCnt);
        }
    }
    bool bComplete = false;
    if (bAnyLimited == 0) {
        if (rSet.FUN_1409ee2d0()->m_nNeed <= nPlaced)
            bComplete = true;
    } else {
        if (rSet.FUN_1409ee2d0()->m_nNeed <= nLimited)
            bComplete = true;
    }
    Unk_CMISListIter itSel;
    Unk_CMISListEnd itSelEnd;
    for (FUN_140367e30(pPlaced, &itSel); FUN_14035ea60(&itSel, FUN_140368110(pPlaced, &itSelEnd)); FUN_14035ebf0(&itSel)) {
        int nKey = *FUN_1403e8d70(&itSel);
        MS2Ptr<Cube> spCube(FUN_1410b8b00(nKey));
        if (spCube.get() == 0)
            continue;
        int nItem = FUN_1408b4f20(spCube.operator->());
        Unk_CMISPieceIter itFind, itEnd;
        if (FUN_1409edfd0(FUN_140ba1ff0(&rSet.FUN_1409ee2d0()->m_pieces, &itFind, &nItem), FUN_1409efe40(&rSet.FUN_1409ee2d0()->m_pieces, &itEnd)) != 0)
            continue;
        int nItem2 = FUN_1408b4f20(spCube.operator->());
        Unk_CMISPieceRef rPiece;
        FUN_14111e900(&rPiece, FUN_141128010(&rSet.FUN_1409ee2d0()->m_pieces, &nItem2));
        if (spCube.get() != 0) {
            if (FUN_1408a9bd0(FUN_1408a9280(&spCube->entity))->FUN_14211e240(0x48ccc02d)) {
                const char* pszEffect = bComplete == 0 ? (const char*)FUN_140ba0d40(&rPiece)->strModelEffect : (const char*)FUN_140ba0d40(&rPiece)->strFullEffect;
                efd::utf8string strEffect(pszEffect);
                FUN_1409a1fc0(FUN_141b6f910(), FUN_1408b76f0(FUN_1408a9280(&spCube->entity)), &strEffect, 1.0f, 1);
            }
            if (!FUN_140ba0d40(&rPiece)->strSetName.IsEmpty()) {
                if (bComplete == 0) {
                    Unk_CMISIter<279> itE, itF;
                    if (FUN_141127480(FUN_1411574a0(&f348, &itF, &nKey), FUN_141151a90(&f348, &itE))) {
                        MS2Ptr<Unk_CMISSetEffect> spEff = *FUN_141127c90(&f348, &nKey);
                        FUN_1403ed280()->FUN_1411a6060(spEff->m_nEffect);
                        FUN_141153af0(&f348, &nKey);
                        FUN_1410bf320(&spEff->m_strName);
                    }
                } else {
                    int nUse = FUN_1410bf3e0(&FUN_140ba0d40(&rPiece)->strSetName);
                    if (nUse >= *FUN_1402056b0(&FUN_1401d3200()->m_limits)) {
                        FUN_140b9cda0(&rPiece);
                        continue;
                    }
                    Unk_CMISEffReq request;
                    FUN_140a52ef0(&request);
                    request.m_strName = FUN_140ba0d40(&rPiece)->strSetName;
                    if (FUN_140ba0d40(&rPiece)->strAttachNode.IsEmpty()) {
                        FUN_1409fabf0(&request.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(FUN_1408a9090(&spCube->entity))));
                    } else {
                        bool bAttached = false;
                        NiAVObject* pRoot = FUN_141b6efc0(FUN_1408a9090(&spCube->entity));
                        if (pRoot != 0) {
                            NiObject* pNode = FUN_14098d8d0(&DAT_143afa4d8, pRoot->GetObjectByName(NiFixedString((const char*)FUN_140ba0d40(&rPiece)->strAttachNode)));
                            if (pNode != 0) {
                                FUN_1409fabf0(&request.m_pSlot10, pNode);
                                bAttached = true;
                            }
                        }
                        if (bAttached == 0)
                            FUN_1409fabf0(&request.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(FUN_1408a9090(&spCube->entity))));
                    }
                    bool bOff = false;
                    FUN_14098c6e0(FUN_1408a9280(&spCube->entity), 0x2a7fd9f4, &bOff);
                    int nEffect = FUN_1403ed280()->FUN_1411a49c0(&request);
                    if (nEffect != 0) {
                        Unk_CMISIter<279> itE, itF;
                        if (FUN_141127480(FUN_1411574a0(&f348, &itF, &nKey), FUN_141151a90(&f348, &itE))) {
                            MS2Ptr<Unk_CMISSetEffect> spOld = *FUN_141127c90(&f348, &nKey);
                            FUN_1403ed280()->FUN_1411a6060(spOld->m_nEffect);
                            FUN_1410bf320(&spOld->m_strName);
                        }
                        MS2Ptr<Unk_CMISSetEffect> spNew(new Unk_CMISSetEffect);
                        spNew->m_nEffect = nEffect;
                        spNew->m_strName = FUN_140ba0d40(&rPiece)->strSetName;
                        *FUN_141127c90(&f348, &nKey) = spNew;
                        FUN_1410bf250(&spNew->m_strName);
                    }
                    FUN_1405a89e0(&request);
                }
            }
            FUN_140b9cda0(&rPiece);
        } else {
            FUN_140b9cda0(&rPiece);
        }
    }
    Unk_CMISListIter itOther;
    Unk_CMISListEnd itOtherEnd;
    for (FUN_140367e30(pOthers, &itOther); FUN_14035ea60(&itOther, FUN_140368110(pOthers, &itOtherEnd)); FUN_14035ebf0(&itOther)) {
        int nKey = *FUN_1403e8d70(&itOther);
        MS2Ptr<Cube> spCube(FUN_1410b8b00(nKey));
        if (spCube.get() == 0)
            continue;
        int nItem = FUN_1408b4f20(spCube.operator->());
        Unk_CMISPieceIter itFind, itEnd;
        if (FUN_1409edfd0(FUN_140ba1ff0(&rSet.FUN_1409ee2d0()->m_pieces, &itFind, &nItem), FUN_1409efe40(&rSet.FUN_1409ee2d0()->m_pieces, &itEnd)) != 0)
            continue;
        int nItem2 = FUN_1408b4f20(spCube.operator->());
        Unk_CMISPieceRef rPiece;
        FUN_14111e900(&rPiece, FUN_141128010(&rSet.FUN_1409ee2d0()->m_pieces, &nItem2));
        if (spCube.get() != 0) {
            if (!FUN_140ba0d40(&rPiece)->strSetName.IsEmpty()) {
                Unk_CMISIter<279> itE, itF;
                if (FUN_141127480(FUN_1411574a0(&f348, &itF, &nKey), FUN_141151a90(&f348, &itE))) {
                    MS2Ptr<Unk_CMISSetEffect> spEff = *FUN_141127c90(&f348, &nKey);
                    FUN_1403ed280()->FUN_1411a6060(spEff->m_nEffect);
                    FUN_141153af0(&f348, &nKey);
                    FUN_1410bf320(&spEff->m_strName);
                }
            }
        }
        FUN_140b9cda0(&rPiece);
    }
    FUN_14025c810(&mapCount);
}
// ---- w138 batch 9 ----
Unk_CMISIter<283>* FUN_141157740(Unk_CMISTree<283>*, Unk_CMISIter<283>*, const int*);       // find
Unk_CMISIter<283>* FUN_141151bb0(Unk_CMISTree<283>*, Unk_CMISIter<283>*);                   // end
bool FUN_141126e10(Unk_CMISIter<283>*, Unk_CMISIter<283>*);                                 // operator==
struct Unk_CMISBucket { void* m_head; unsigned __int64 m_count; };                          // set id -> placed cube keys
struct Unk_CMISBucketIter { void* m_p; };
Unk_CMISBucket* FUN_141127d50(Unk_CMISTree<283>*, const int*);                              // operator[]
Unk_CMISBucketIter* FUN_141151f10(Unk_CMISBucket*, Unk_CMISBucketIter*);                    // end
Unk_CMISBucketIter* FUN_141157e40(Unk_CMISBucket*, Unk_CMISBucketIter*, const int*);        // find
bool FUN_141126f90(Unk_CMISBucketIter*, Unk_CMISBucketIter*);                               // operator==
Unk_CMISCubeList* FUN_141128050(Unk_CMISBucket*, const int*);                               // operator[]
Unk_CMISListIter* FUN_140368510(Unk_CMISCubeList*, Unk_CMISListIter*, const int*);          // find
bool FUN_14035e9e0(Unk_CMISListIter*, Unk_CMISListEnd*);                                    // operator==
void FUN_140e47160(Unk_CMISCubeList*, const int*);                                          // insert
void FUN_14035dea0(Unk_CMISCubeList*);                                                      // ctor
void FUN_14035e6c0(Unk_CMISCubeList*);                                                      // dtor
void FUN_14035d1e0(Unk_CMISCubeList*, Unk_CMISListIter*, const int*);                       // insert
class Unk_CMISSetMgr;
Unk_CMISSetMgr* FUN_1409eed50();
Unk_CMISSetRef* FUN_140b9df60(Unk_CMISSetMgr*, Unk_CMISSetRef* pOut, int nSetId);
bool FUN_1401b5240(MS2Ptr<CItemData>*, int);                                                // operator==
bool FUN_140885250(Unk_CMISRecRef*, int);                                                   // operator==
// @0x1410bec60
// MS2-FUNCTIONAL: MS2Ptr/iterator temporaries and the repeated unwind blocks are laid out differently from the exe
void CubeMapInformationService::FUN_1410bec60(MS2Ptr<Cube> spCube)
{
    if (FUN_1408b4f20(spCube.operator->()) == 0)
        return;
    MS2Ptr<CItemData> spItem = FUN_14053f870(FUN_1408b4f20(spCube.operator->()));
    if (spItem.get() == 0)
        return;
    Unk_CMISRecRef rec;
    FUN_1405566e0(FUN_140281980(), &rec, FUN_1408b4f20(spCube.operator->()));
    if (FUN_140885250(&rec, 0) != 0) {
        FUN_14056c300(&rec);
        return;
    }
    if (FUN_14056d580(&rec)->nSetId == 0) {
        FUN_14056c300(&rec);
        return;
    }
    Unk_CMISSetRef rSet;
    FUN_140b9df60(FUN_1409eed50(), &rSet, FUN_14056d580(&rec)->nSetId);
    if (rSet.FUN_1409ede50(0) != 0) {
        FUN_14056c300(&rec);
        return;
    }
    int nItem = FUN_1408b4f20(spCube.operator->());
    Unk_CMISPieceIter itEnd, itFind;
    if (FUN_1409ee120(FUN_140ba1ff0(&rSet.FUN_1409ee2d0()->m_pieces, &itFind, &nItem), FUN_1409efe40(&rSet.FUN_1409ee2d0()->m_pieces, &itEnd)) == 0) {
        int nItemLog = FUN_1408b4f20(spCube.operator->());
        FUN_140166440()->FUN_1403d7960(1, 0x13, L"세트아이템으로 지정된 아이템({0})이지만 SetItemTable({1})에는 등록되지 않았습니다", &nItemLog, &FUN_14056d580(&rec)->nSetId);
        FUN_14056c300(&rec);
        return;
    }
    Unk_CMISIter<283> itBucketEnd, itBucket;
    if (FUN_141126e10(FUN_141157740(&f440, &itBucket, &spCube->field50), FUN_141151bb0(&f440, &itBucketEnd))) {
        FUN_14056c300(&rec);
        return;
    }
    Unk_CMISBucket* pBucket = FUN_141127d50(&f440, &spCube->field50);
    Unk_CMISBucketIter itInnerEnd, itInner;
    FUN_141151f10(pBucket, &itInnerEnd);
    if (FUN_141126f90(FUN_141157e40(pBucket, &itInner, &FUN_14056d580(&rec)->nSetId), &itInnerEnd)) {
        FUN_14056c300(&rec);
        return;
    }
    int nCell = FUN_1408a03c0(spCube->position);
    Unk_CMISCubeList* pCells = FUN_141128050(pBucket, &FUN_14056d580(&rec)->nSetId);
    Unk_CMISListEnd itCellEnd;
    Unk_CMISListIter itCell;
    if (FUN_14035e9e0(FUN_140368510(pCells, &itCell, &nCell), FUN_140368110(pCells, &itCellEnd)) == 0) {
        FUN_140e47160(pCells, &nCell);
        Unk_CMISCubeList lstNew;
        FUN_14035dea0(&lstNew);
        Unk_CMISListIter itIns;
        FUN_14035d1e0(&lstNew, &itIns, &nCell);
        FUN_1410bf610(pCells, Unk_CMISSetRef(rSet), &lstNew);
        FUN_14035e6c0(&lstNew);
    }
    FUN_14056c300(&rec);
}
// ---- w138 batch 10 ----
struct Unk_CMISOuterPair { int m_key; int m_pad; Unk_CMISBucket m_value; };
struct Unk_CMISBucketPair { int m_key; int m_pad; Unk_CMISCubeList m_value; };
Unk_CMISIter<283>* FUN_14114de50(Unk_CMISTree<283>*, Unk_CMISIter<283>*);                   // begin
bool FUN_141127540(Unk_CMISIter<283>*, Unk_CMISIter<283>*);                                 // operator!=
Unk_CMISOuterPair* FUN_141128620(Unk_CMISIter<283>*);                                       // operator*
void FUN_141129b90(Unk_CMISIter<283>*);                                                     // operator++
Unk_CMISBucketIter* FUN_14114e1d0(Unk_CMISBucket*, Unk_CMISBucketIter*);                    // begin
bool FUN_1411276c0(Unk_CMISBucketIter*, Unk_CMISBucketIter*);                               // operator!=
Unk_CMISBucketPair* FUN_1411286e0(Unk_CMISBucketIter*);                                     // operator*
void FUN_141129c10(Unk_CMISBucketIter*);                                                    // operator++
// @0x1410bf470
// MS2-FUNCTIONAL: iterator temporaries are laid out differently from the exe
void CubeMapInformationService::FUN_1410bf470()
{
    Unk_CMISIter<283> itOuter, itOuterEnd;
    for (FUN_14114de50(&f440, &itOuter); FUN_141127540(&itOuter, FUN_141151bb0(&f440, &itOuterEnd)); FUN_141129b90(&itOuter)) {
        Unk_CMISBucket* pBucket = &FUN_141128620(&itOuter)->m_value;
        Unk_CMISBucketIter itInner, itInnerEnd;
        for (FUN_14114e1d0(pBucket, &itInner); FUN_1411276c0(&itInner, FUN_141151f10(pBucket, &itInnerEnd)); FUN_141129c10(&itInner)) {
            int nSetId = FUN_1411286e0(&itInner)->m_key;
            Unk_CMISCubeList* pCells = &FUN_1411286e0(&itInner)->m_value;
            Unk_CMISSetRef rSet;
            FUN_140b9df60(FUN_1409eed50(), &rSet, nSetId);
            if (rSet.FUN_1409ede50(0) == 0) {
                Unk_CMISCubeList lstEmpty;
                FUN_14035dea0(&lstEmpty);
                FUN_1410bf610(pCells, Unk_CMISSetRef(rSet), &lstEmpty);
                FUN_14035e6c0(&lstEmpty);
            }
        }
    }
}
// @0x1410ce600
// MS2-FUNCTIONAL: CubeItemInfo/Unk_Int3 temporaries are laid out differently from the exe
void CubeMapInformationService::FUN_1410ce600(int nItemId, Unk_Int3 pt, int nZ)
{
    int nCell = FUN_1408a03c0(pt);
    CubeItemInfo info;
    info.instanceId = nCell;
    info.count = 0;
    info.itemId = nItemId;
    info.look = 0;
    efd::utf8string strName;
    FUN_1410bd080(nCell, pt, nZ, &info, strName, 0, 0, 0, 0, 0, Unk_PayloadPtr<NoticeCubeInfo>(0));
}
class Unk_CMISPawn                                                                          // the local player (slot 18 gives the position)
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual Unk_StreamPoint vfunc_18();
    virtual Unk_StreamPoint vfunc_19();
    virtual Unk_StreamPoint vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24();
    int FUN_141656ad0();
    Unk_StreamPoint FUN_1416767d0();
};
float* FUN_140298f40(Unk_CMISLimitF* pLimit);
// @0x1410cb1b0
Unk_CMISEntityRef CubeMapInformationService::FUN_1410cb1b0()
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    float fBest = FLT_MAX;
    Unk_1401cd100 best(0);
    if (pPawn != 0) {
        Unk_CMISIter<265> it, itEnd;
        for (FUN_14114e010(&f108, &it); FUN_141127640(&it, FUN_141151d30(&f108, &itEnd)); FUN_141129bd0(&it)) {
            int nKey = FUN_1411286a0(&it)->m_key;
            Unk_CMISEntityRef ref(FUN_1411286a0(&it)->m_ref);
            Unk_StreamPoint ptCell;
            FUN_1408a15b0(FUN_1408a0400(nKey), static_cast<Unk_StreamPoint&>(ptCell));
            float fDist = pPawn->vfunc_18().FUN_140965c40(ptCell).FUN_140967ac0();
            if (fDist > *FUN_140298f40(&FUN_1401d3200()->m_fNear))
                continue;
            if (fDist > fBest)
                continue;
            fBest = fDist;
            FUN_140899bd0(reinterpret_cast<Unk_CMISEntityRef*>(&best), ref);
        }
    }
    return Unk_CMISEntityRef(reinterpret_cast<const Unk_CMISEntityRef&>(best));
}
// ---- w138 batch 11 ----
struct Unk_CMISCubeTimer { Timer m_timer; bool m_bFlagA; bool m_bFlagB; };                 // f1f8 value: the placement timer (flags at 0x38/0x39)
class Unk_CMISClock;
Unk_CMISClock* FUN_14086d260();
int FUN_141473390(Unk_CMISClock*);                                                          // the current time
Unk_CMISCubeTimer* FUN_141127f10(Unk_CMISTree<272>*, const int*);                           // operator[]
bool FUN_1413d6e60(HardwareInstancingService*, egf::Entity*, int);
void FUN_141689ec0(CPhysXHelper*, egf::Entity*, int nAnim, int nA, int nB);
// @0x1410caf20
// MS2-FUNCTIONAL: service-pointer truth test is an inlined bool conversion in the exe; frame differs
void CubeMapInformationService::FUN_1410caf20(Cube* pCube, int nTime)
{
    int nCell = FUN_1408a03c0(pCube->position);
    Unk_CMISIter<272> itEnd, itFind;
    if (FUN_141127680(FUN_141157ba0(&f1f8, &itFind, &nCell), FUN_141151d90(&f1f8, &itEnd)) == 0) {
        bool bInstanced = false;
        FUN_1408a20a0(FUN_1408a9280(&pCube->entity), 0x23f9860e, &bInstanced);
        if (bInstanced) {
            Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
            if (spInst.FUN_14098d090() != 0)
                FUN_1413d6e60(spInst.FUN_14098d0e0(), FUN_1408a9090(&pCube->entity), 0);
        }
        bool bOff = false;
        FUN_14098c6e0(FUN_1408a9280(&pCube->entity), 0xa0b6b179, &bOff);
        Unk_CMISCubeTimer* pTimer = FUN_141127f10(&f1f8, &nCell);
        pTimer->m_timer.FUN_140868750(nTime - FUN_141473390(FUN_14086d260()));
        FUN_1408a20a0(FUN_1408a9280(&pCube->entity), 0x2a7fd9f4, &pTimer->m_bFlagA);
        FUN_1408a20a0(FUN_1408a9280(&pCube->entity), 0x9004569a, &pTimer->m_bFlagB);
        if (pCube->field44 != 1)
            FUN_141689ec0(FUN_1409f7ca0(), FUN_1408a9090(&pCube->entity), 5, 0, 1);
    }
}
egf::EntityPtr FUN_1408a7ed0(const Unk_CMISEntityRef* pRef);
void FUN_140998250(egf::Entity*, unsigned, efd::AssetID*);
void FUN_140de8bd0(egf::Entity*, unsigned, efd::AssetID*);
// @0x1410bbcd0
// MS2-FUNCTIONAL: entity-ptr and AssetID temporaries / unwind states are laid out differently from the exe
void CubeMapInformationService::FUN_1410bbcd0(int nGroup, int nIsOne)
{
    int nFlag = 0;
    FUN_1408a0890(FUN_1403ed2d0()->FUN_141bd3060(), nGroup, &nFlag);
    Unk_CMISIter<264> itEnd, itFind;
    if (FUN_141126c90(FUN_141157200(&ff8, &itFind, &nGroup), FUN_141151970(&ff8, &itEnd)) == 0) {
        egf::EntityPtr spEnt = FUN_1408a7ed0(FUN_141127b90(&ff8, &nGroup));
        if (FUN_1408a9090(&spEnt) != 0) {
            int nState = 2;
            Unk_CMISHouseRef spHouse(FUN_1410c7c20(nGroup, nIsOne));
            if (spHouse.FUN_141128410() != 0)
                nState = spHouse.FUN_1411284b0()->m_state;
            efd::AssetID asset;
            if (nState == 2)
                FUN_140998250(FUN_1408a9280(&spEnt), 0x2472f50d, &asset);
            else if (nState == 1)
                FUN_140998250(FUN_1408a9280(&spEnt), 0x811e9044, &asset);
            else if (nState == 4)
                FUN_140998250(FUN_1408a9280(&spEnt), 0x46fed193, &asset);
            FUN_140de8bd0(FUN_1408a9280(&spEnt), 0x770e5fc6, &asset);
        }
    } else {
        FUN_140166440()->FUN_140353fc0(0xc, 0x13, L"Not exist salable group : {0}", &nGroup);
    }
}
void FUN_140964eb0(Unk_CMISEntityRef* pDst, egf::EntityPtr* pSrc);
CStringW FUN_140979570(int nMap);
void FUN_14111e6e0(Unk_CMISHousePtr*);                                                      // ctor: allocates a fresh record
void FUN_141126140(Unk_CMISHousePtr* pDst, Unk_CMISHousePtr* pSrc);                         // assign
void FUN_141123790(Unk_CMISHousePtr*);                                                      // dtor
// @0x1410bbf20
// MS2-FUNCTIONAL: entity-ptr and CString temporaries / unwind states are laid out differently from the exe
void CubeMapInformationService::FUN_1410bbf20(int nGroup, const egf::EntityID& id)
{
    egf::EntityPtr spEnt(static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411cf440(id));
    FUN_140964eb0(FUN_141127b90(&ff8, &nGroup), &spEnt);
    Unk_StreamPoint pt = DAT_143b01a60;
    FUN_1409618c0(FUN_1408a9280(&spEnt), 0xfd95ca52, &pt);
    CStringW strKey;
    strKey.Format(L"%d", nGroup);
    int nMap = FUN_1403ed2d0()->FUN_141bd3060();
    CStringW strOwner;
    Unk_CMISSalable salable;
    if (FUN_1408a0d30(nGroup, &salable, nMap) != 0)
        strOwner = FUN_140979570(nMap);
    Unk_CMISHousePtr spInfo;
    FUN_14111e6e0(&spInfo);
    FUN_141128470(&spInfo)->m_nGroup = nGroup;
    FUN_141128470(&spInfo)->m_pt = pt;
    FUN_141128470(&spInfo)->m_strOwner = strOwner;
    FUN_141128470(&spInfo)->m_bNoSalable = salable.m_pField0xa0 == 0;
    FUN_141128470(&spInfo)->m_nValue = salable.m_nField20;
    FUN_141126140(FUN_141127c50(&f238, &nGroup), &spInfo);
    Unk_CMISHouseMark* pMark = FUN_1410dc020();
    if (pMark != 0)
        pMark->FUN_14198cb00(*FUN_141128800(&spInfo));
    FUN_141123790(&spInfo);
}

// ---- w138 batch 12 ----
struct Unk_CMISDollRec { char m_pad0[0x18]; int m_nId; int m_pad1c; __int64 m_nChar; int m_nSlot; Unk_StreamPoint m_ptPos; Unk_StreamPoint m_ptRot; int m_bItems; int m_pad48[2]; char m_items[1]; };
class Unk_CMISDoll
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
    virtual void vfunc_19(Unk_StreamPoint ptPos);
    virtual void vfunc_20();
    virtual void vfunc_21(Unk_StreamPoint ptRot);
    void FUN_141656a50(__int64 nCharId);
    void FUN_14121c6e0(__int64 nCharId);
    void FUN_14123c5a0(int nId);
    int FUN_14121bab0(int nSlot);
    egf::EntityID FUN_14123c460();
    egf::Entity* FUN_14123c410();
    void FUN_141653d10(void* pItem);
};
struct Unk_CMISWorldBind { int FUN_141bbb1e0(Unk_CMISDoll* pObj, int bFullInit, unsigned nCamera); };
void* FUN_14121b350(void* pMem);                                // FittingDollPC::FittingDollPC
void* FUN_140876480(void* out, int cat);   void* FUN_14208a860(unsigned __int64 size, unsigned cat);
struct Unk_CMISItemElem { char m_pad[0x18]; };
unsigned FUN_140720ca0(void* pArr);
void* FUN_140a69ee0(void* pArr, unsigned nIdx);
Unk_CMISItemElem* FUN_1402034d0(Unk_CMISItemElem* pOut, void* pSrc);
void FUN_1401bfde0(Unk_CMISItemElem* p);

static Unk_CMISDoll* NewCMISDoll()
{
    int tmp;
    int* cat = (int*)FUN_140876480(&tmp, 0);
    void* mem = FUN_14208a860(0x1300, *cat);
    return mem == 0 ? 0 : (Unk_CMISDoll*)FUN_14121b350(mem);
}

// @0x1410bc7f0
// MS2-FUNCTIONAL: the exe's CComPtr temp and EH frame are not reproduced
egf::EntityPtr CubeMapInformationService::FUN_1410bc7f0(Unk_StreamPoint ptPos, Unk_StreamPoint ptRot, unsigned nIdx, int nItemId)
{
    Unk_CMISDoll* pc = NewCMISDoll();
    pc->FUN_141656a50(0);
    pc->FUN_14121c6e0(0);
    pc->FUN_14123c5a0(nItemId);
    pc->vfunc_19(ptPos);
    pc->vfunc_21(ptRot);
    if (pc->FUN_14121bab0(nIdx) == 0)
        return egf::EntityPtr(0);
    ((Unk_CMISWorldBind*)FUN_1403ed2d0())->FUN_141bbb1e0(pc, 0, 1);
    egf::EntityID id = pc->FUN_14123c460();
    FUN_1410cb380(*(Unk_Int3*)&ptPos, reinterpret_cast<const Unk_CMISEntityRef&>(id));
    return egf::EntityPtr(pc->FUN_14123c410());
}

// @0x1410bc3d0
// MS2-FUNCTIONAL: the exe's CComPtr temp and EH frame are not reproduced
egf::EntityPtr CubeMapInformationService::FUN_1410bc3d0(Unk_CMISBlock rec)
{
    Unk_CMISDollRec* r = (Unk_CMISDollRec*)&rec;
    Unk_CMISDoll* pc = NewCMISDoll();
    pc->FUN_141656a50(r->m_nChar);
    pc->FUN_14121c6e0(r->m_nChar);
    pc->FUN_14123c5a0(r->m_nId);
    pc->vfunc_19(r->m_ptPos);
    pc->vfunc_21(r->m_ptRot);
    if (pc->FUN_14121bab0(r->m_nSlot) == 0)
        return egf::EntityPtr(0);
    if (r->m_bItems != 0) {
        for (unsigned i = 0; i < FUN_140720ca0(r->m_items); i++) {
            Unk_CMISItemElem e;
            FUN_1402034d0(&e, FUN_140a69ee0(r->m_items, i));
            pc->FUN_141653d10(&e);
            FUN_1401bfde0(&e);
        }
    }
    ((Unk_CMISWorldBind*)FUN_1403ed2d0())->FUN_141bbb1e0(pc, 0, 1);
    egf::EntityID id = pc->FUN_14123c460();
    FUN_1410cb380(*(Unk_Int3*)&r->m_ptPos, reinterpret_cast<const Unk_CMISEntityRef&>(id));
    return egf::EntityPtr(pc->FUN_14123c410());
}

// ---- w138 batch 13 ----
struct Unk_CMISRefList;                                                                     // list of entities found near a point
extern Unk_StreamPoint DAT_143b01a60;                                                       // the zero point
void FUN_14114dbb0(Unk_CMISTree<264>*, Unk_CMISIter<264>*);                                 // begin
bool FUN_1411516a0(Unk_CMISTree<264>*);                                                     // empty
Unk_CMISRefElem* FUN_141128560(Unk_CMISIter<264>*);                                         // operator*
void FUN_141129a80(Unk_CMISIter<264>*);                                                     // operator++
bool FUN_1408b70b0(egf::EntityPtr*, int);                                                   // operator==
void* FUN_140965820(Unk_CubeOwnerPtr*);                                                     // get
void FUN_1408a8790(Unk_CubeOwnerPtr*);                                                      // dtor
void FUN_1408a8720(egf::EntityPtr*);                                                        // dtor
float FUN_140966f00(Unk_StreamPoint ptA, Unk_StreamPoint ptB);                              // distance
void FUN_14115a960(Unk_CMISRefList*, egf::EntityPtr*);                                      // push_back
void** FUN_141123230(void* pOut, Unk_CMISPawn*);
void** FUN_1411525d0(Unk_CMISRefList*, void** pOut);                                        // end
void** FUN_14114e990(Unk_CMISRefList*, void** pOut);                                        // begin
void FUN_14111d5b0(void* pFirst, void* pLast, void* pKey);

// @0x1410bb610
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410bb610(unsigned nMask, Unk_CMISPawn* pPawn, float fDist, Unk_CMISRefList* pOut)
{
    if (pPawn != 0 && !FUN_1411516a0(&ff8)) {
        Unk_CMISIter<264> it, itEnd;
        FUN_14114dbb0(&ff8, &it);
        while (FUN_1411273c0(&it, FUN_141151970(&ff8, &itEnd))) {
            int nGroup = FUN_141128560(&it)->m_key;
          { egf::EntityPtr spEnt = FUN_1408a7ed0(&FUN_141128560(&it)->m_ref);   // dtor 0x1408a8720 once, at the block end
            if (!FUN_1408b70b0(&spEnt, 0)) {
                Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
                void* pOwner = FUN_140965820(&spOwner);
                FUN_1408a8790(&spOwner);
                for (unsigned nBit = 1; (int)nBit < 5; nBit <<= 1) {
                    if ((nMask & nBit) == nBit && (pOwner == 0 || nBit == 1) && (pOwner != 0 || nBit != 1)) {
                        Unk_StreamPoint ptPawn = pPawn->vfunc_18();
                        Unk_StreamPoint ptEnt = DAT_143b01a60;
                        FUN_1409618c0(FUN_1408a9280(&spEnt), 0xfd95ca52, &ptEnt);
                        float fD = FUN_140966f00(ptPawn, ptEnt);
                        if (fD < fDist)
                            FUN_14115a960(pOut, &spEnt);
                    }
                }
            }
          }
            FUN_141129a80(&it);
        }
        void* aCopy[1]; void* pEnd[1]; void* pBegin[1];
        FUN_14111d5b0(*FUN_14114e990(pOut, pBegin), *FUN_1411525d0(pOut, pEnd), *FUN_141123230(aCopy, pPawn));
    }
}

// ---- w138 batch 14 ----
struct Unk_CMISSlot { Unk_CMISSlot(void* pId); Unk_CMISSlot(const Unk_CMISSlot&); ~Unk_CMISSlot(); void* m_p; };   // ctor 14111e890, copy 14111e850, dtor 1409648f0
struct Unk_CMISObjRec30 { char m_pad[0x30]; int m_n30; char m_pad34[0xc]; void* m_pKind; };
struct Unk_CMISInfoRef { ~Unk_CMISInfoRef(); void* m_p; };                                   // dtor 140ca62a0
class Unk_CMISObj498 { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual int vfunc_2(void* pCtx, void* pRec, int nCell, __int64 nOwner, void* pItem); Unk_CMISInfoRef FUN_140ca6580(); void FUN_141227310(); void FUN_141227360(); Unk_CMISEntityRef FUN_141226eb0(); };
int FUN_141126a70(Unk_CMISObjHandle*);                                                                // IsNull
void* FUN_141225470(int nKind);
void* FUN_1408b7270(Unk_PayloadPtr<CubeItemInfo>*);
void FUN_141226b80(Unk_CMISObj498*, CString strName);
void FUN_141230c90(Unk_CMISMagicCube*, Unk_CMISSlot slot);

// @0x1410d0000
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410d0000(void* pCtx, MS2Ptr<Cube> spCube)
{
    Unk_CMISObjHandle hObj;
    FUN_140704ec0(&hObj, spCube->fieldB4);
    if (FUN_141126a70(&hObj) == 0) {
        Unk_CMISObjRec30* pRec = (Unk_CMISObjRec30*)FUN_140708eb0(&hObj);
        if (pRec->m_n30 != 0) {
            Unk_CMISSlot slot(FUN_141225470(FUN_140708eb0(&hObj)->nKind));
            Unk_StreamPoint ptCube = *(Unk_StreamPoint*)&spCube->position;
            Unk_CMISObj498* pObj = FUN_1409658e0(&slot);
            void* pItem = FUN_1408b7270(&spCube->item);
            __int64 nOwner = FUN_1410c8030(spCube->field50, spCube->field54);
            int nCell = FUN_1408a03c0(*(Unk_Int3*)&ptCube);
            if (pObj->vfunc_2(pCtx, &((Unk_CMISObjRec30*)FUN_140708eb0(&hObj))->m_n30, nCell, nOwner, pItem) != 0) {
                CString strKey;
                strKey.Format("%d_%d", spCube->field44, FUN_1408a03c0(*(Unk_Int3*)&spCube->position));
                FUN_141226b80(FUN_1409658e0(&slot), strKey);
                FUN_141230c90(FUN_1409670b0(), Unk_CMISSlot(slot));
            }
        }
    }
}

// ---- w138 batch 15 ----
struct Unk_CMISRefList { Unk_CMISRefList(); ~Unk_CMISRefList(); char m_buf[0x20]; };        // ctor 1408a84d0, dtor 1408a88a0
bool FUN_1411517a0(Unk_CMISRefList*);                                                       // empty
Unk_CMISEntityRef* FUN_1408a9050(Unk_CMISRefList*, int nIdx);
void FUN_1408a2020(egf::Entity*, unsigned, int*);                                           // SetProperty(int)
float FUN_140966ea0(Unk_StreamPoint ptA, Unk_StreamPoint ptB);                              // distance

// @0x1410c93c0
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410c93c0()
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    UIHouseMark* pMark;
    if (pPawn != 0 && (pMark = reinterpret_cast<UIHouseMark*>(FUN_1410dc020())) != 0) {
        if (!f158.FUN_1408b70b0(0)) {
            if (f158.FUN_1408a9090() != 0) {
                Unk_StreamPoint ptEnt = DAT_143b01a60;
                FUN_1409618c0(reinterpret_cast<egf::Entity*>(f158.FUN_1408a9280()), 0xfd95ca52, &ptEnt);
                Unk_StreamPoint ptPawn = pPawn->vfunc_18();
                float fDist = FUN_140966ea0(ptEnt, ptPawn);
                if ((float)*FUN_1402056b0(&FUN_1401d3200()->m_limits1348) <= fDist) {
                    int nVal = 0;
                    FUN_1408a2020(reinterpret_cast<egf::Entity*>(f158.FUN_1408a9280()), 0x85ef19e7, &nVal);
                    MS2Ptr<UIHouseMarkEntity> spMark = pMark->FUN_14198ce50(nVal);
                    if (spMark.get() != 0)
                        spMark->FUN_14198b320();
                    f158.FUN_1408b6ec0(0);
                    f160 = false;
                }
            }
        } else {
            Unk_CMISRefList list;
            FUN_1410bb610(5, pPawn, (float)*FUN_1402056b0(&FUN_1401d3200()->m_limits1348), &list);
            if (!FUN_1411517a0(&list)) {
                egf::EntityPtr spEnt = FUN_1408a7ed0(FUN_1408a9050(&list, 0));
                int nVal = 0;
                FUN_1408a2020(FUN_1408a9280(&spEnt), 0x85ef19e7, &nVal);
                MS2Ptr<UIHouseMarkEntity> spMark = pMark->FUN_14198ce50(nVal);
                if (spMark.get() != 0)
                    spMark->FUN_14198b2f0();
                f160 = true;
                FUN_140964eb0(reinterpret_cast<Unk_CMISEntityRef*>(&f158), &spEnt);
            }
        }
    }
}

// ---- w138 batch 16 ----
struct Unk_CMISNpcElem;
struct Unk_CMISNpcList { Unk_CMISNpcList(); ~Unk_CMISNpcList(); void* m_buf[4]; };           // ctor 140964560, dtor 140964ca0
struct Unk_CMISNpcIter { void* m_p; };
struct Unk_CMISNpcRef { Unk_CMISNpcRef(Unk_CMISNpcElem* p); ~Unk_CMISNpcRef(); void* m_p; };  // ctor 140963ff0, dtor 1409649e0
class Unk_CMISNpc { public: void FUN_141447410(egf::Entity* pEntity); int FUN_141447340(); Unk_StreamPoint FUN_141447c80(); CString FUN_1414472a0(); };
void* FUN_14096b140(Unk_CMISNpcList*);
Unk_CMISNpcIter* FUN_14096adc0(Unk_CMISNpcList*, Unk_CMISNpcIter*);                            // end
Unk_CMISNpcIter* FUN_14096aab0(Unk_CMISNpcList*, Unk_CMISNpcIter*);                            // begin
bool FUN_140965510(Unk_CMISNpcIter*, Unk_CMISNpcIter*);                                        // operator!=
Unk_CMISNpcElem* FUN_140965a50(Unk_CMISNpcIter*);                                              // operator*
void FUN_140965b10(Unk_CMISNpcIter*);                                                          // operator++
Unk_CMISNpc* FUN_140965930(Unk_CMISNpcRef*);                                                   // operator->
bool FUN_1402a5b40(CString* pStr, const char* psz);
float FUN_140a17940(float fVal, float fMin, float fMax);                                       // clamp

// @0x1410c7110
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
int CubeMapInformationService::FUN_1410c7110(int* pCell)
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPawn == 0)
        return 0;
    Unk_StreamPoint kForward, kRight;
    FUN_140a01250(pPawn->vfunc_20(), &kForward, &kRight);
    Unk_StreamPoint ptHit;
    FUN_1410b7ad0(reinterpret_cast<PCBase*>(pPawn), 0.0f, &ptHit, 1);
    Unk_Int3 cell = FUN_1408a1430(ptHit);
    if (!FUN_1410b7f90(cell))
        return 0;
    MS2Ptr<Cube> spCube(FUN_1410b8a60(cell));
    if (FUN_1408b4f20(spCube.operator->()) == 0 || FUN_1408b4f20(spCube.operator->()) == 8)
        return 0;
    if (spCube->field44 != 2)
        return 0;
    if (spCube->field58 == 1)
        return 0;
    egf::EntityPtr spEnt(reinterpret_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411cf440(*reinterpret_cast<const egf::EntityID*>(FUN_1408b76f0(FUN_1408a9280(&spCube->entity)))));
    if (FUN_1408b70b0(&spEnt, 0))
        return 0;
    Unk_StreamPoint ptDir;
    FUN_1409618c0(FUN_1408a9280(&spEnt), 0x68c7c29d, &ptDir);
    Unk_StreamPoint kForward2, kRight2;
    FUN_140a01250(ptDir, &kForward2, &kRight2);
    float fDot = FUN_140a17940(kForward.FUN_140a00f20(kForward2), -1.0f, 1.0f);
    if (fDot <= 0.7f)
        return 0;
    *pCell = FUN_1408a03c0(*(Unk_Int3*)&spCube->position);
    return 1;
}

// @0x1410c7500
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
bool CubeMapInformationService::FUN_1410c7500(CString* pOut)
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPawn != 0) {
        Unk_CMISNpcList list;
        FUN_1403ed2d0()->FUN_141bc58d0(&list);
        if (FUN_14096b140(&list) == 0)
            return false;
        Unk_StreamPoint kForward, kRight;
        FUN_140a01250(pPawn->vfunc_20(), &kForward, &kRight);
        Unk_StreamPoint ptHit;
        FUN_1410b7ad0(reinterpret_cast<PCBase*>(pPawn), 0.0f, &ptHit, 1);
        Unk_Int3 cellHit = FUN_1408a1430(ptHit);
        Unk_CMISNpcIter itEnd, itCur, itTmp;
        itEnd = *FUN_14096adc0(&list, &itTmp);
        itCur = *FUN_14096aab0(&list, &itTmp);
        while (FUN_140965510(&itCur, &itEnd)) {
            Unk_CMISNpcRef spNpc(FUN_140965a50(&itCur));
            if (FUN_140965930(&spNpc)->FUN_141447340() != 0) {
                Unk_StreamPoint ptNpc = FUN_140965930(&spNpc)->FUN_141447c80();
                Unk_Int3 cellNpc = FUN_1408a1430(ptNpc);
                Unk_StreamPoint ptDelta = ptNpc.FUN_140965c40(pPawn->vfunc_18());
                float fLen = ptDelta.FUN_140968990();
                if (fLen <= 150.0f) {
                    float fDot = FUN_140a17940(ptDelta.FUN_140a00f20(kForward), -1.0f, 1.0f);
                    if (0.5f < fDot && -0x7fffffff - 1 < cellNpc.z)
                        *pOut = FUN_140965930(&spNpc)->FUN_1414472a0();
                }
            }
            FUN_140965b10(&itCur);
        }
    }
    return FUN_1402a5b40(pOut, "");
}

// ---- w138 batch 17 ----
struct Unk_CMISObjInfo { char m_pad[0xe4]; int m_nShown; };
struct Unk_CMISStockItem;
struct Unk_CMISStockRef { Unk_CMISStockRef(void* p); ~Unk_CMISStockRef(); bool FUN_140df59d0(int); Unk_CMISStockItem* FUN_140df5b10(); void* m_p; };   // ctor 140df5140, dtor 140df5710
struct Unk_CMISStockMgr { void FUN_140dfc750(ATL::CAtlArray<void*>* pOut); };
extern Unk_CMISStockMgr DAT_143ab2e50;
void* FUN_1409657b0(void* pSlot);                                                           // the slot is set
float FUN_1402bac70(Unk_CMISLimitF*);                                                       // the value
Unk_CMISObjInfo* FUN_1409658d0(Unk_CMISInfoRef*);
void FUN_140dd7170(void* pDst, Unk_CMISSlot* pSrc);                                         // assign
int FUN_140dfc370(Unk_CMISStockItem*);                                                      // the item id
Unk_CMISIter<282>* FUN_14114e4e0(Unk_CMISTree<282>*, Unk_CMISIter<282>*);                   // begin
Unk_CMISIter<282>* FUN_1411521b0(Unk_CMISTree<282>*, Unk_CMISIter<282>*);                   // end
Unk_CMISIter<282>* FUN_141158380(Unk_CMISTree<282>*, Unk_CMISIter<282>*, const int*);       // find
int* FUN_141128210(Unk_CMISTree<282>*, const int*);                                         // operator[]
void FUN_14114df30(Unk_CMISTree<262>*, Unk_CMISIter<262>*);                                 // begin
int* FUN_141128660(Unk_CMISIter<262>*);                                                     // operator*
void FUN_141129bb0(Unk_CMISIter<262>*);                                                     // operator++

// @0x1410c8a90
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410c8a90()
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPawn == 0)
        return;
    int nPc = pPawn->FUN_141656ad0();
    float fRange = FUN_1402bac70(&FUN_1401d3200()->m_fAtF80);
    Unk_StreamPoint ptPawn = pPawn->FUN_1416767d0();
    Unk_CMISSlot slot = FUN_1409670b0()->FUN_141230f60(ptPawn, fRange, nPc);
    bool bShown = false;
    if (FUN_1409657b0(&slot) != 0) {
        Unk_CMISInfoRef info = FUN_1409658e0(&slot)->FUN_140ca6580();
        bShown = FUN_1409658d0(&info)->m_nShown != 0;
    }
    if (bShown) {
        if (FUN_1409657b0(&f480) != 0) {
            Unk_CMISEntityRef idOld = FUN_1409658e0(&f480)->FUN_141226eb0();
            Unk_CMISEntityRef idNew = FUN_1409658e0(&slot)->FUN_141226eb0();
            if (idNew.FUN_140965410(reinterpret_cast<const Unk_1401cd100&>(idOld))) {
                if (f490 == 0) {
                    FUN_1409658e0(&f480)->FUN_141227310();
                    f494 = FUN_140869420();
                    f490 = 1;
                } else {
                    if ((unsigned)(f494 + *FUN_1402056b0(&FUN_1401d3200()->m_limits5078)) < FUN_140869420())
                        FUN_1409658e0(&f480)->FUN_141227360();
                }
                return;
            }
        }
        if (FUN_1409657b0(&f480) != 0)
            FUN_1409658e0(&f480)->FUN_141227360();
        FUN_140dd7170(&f480, &slot);
        FUN_1409658e0(&f480)->FUN_141227310();
        f494 = FUN_140869420();
        f490 = 1;
    } else {
        if (FUN_1409657b0(&f480) != 0)
            FUN_1409658e0(&f480)->FUN_141227360();
        f490 = 0;
    }
}

// @0x1410d2fb0
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
bool CubeMapInformationService::FUN_1410d2fb0(__int64 nOwnerId, int nCategory, int* pnCount)
{
    *pnCount = 0;
    if (f218 == 0)
        return false;
    Unk_CMISIter<262> it, itEnd;
    for (FUN_14114df30(&fd8, &it); FUN_1411275c0(&it, FUN_141151c70(&fd8, &itEnd)); FUN_141129bb0(&it)) {
        int nGroup = *FUN_141128660(&it);
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (spOwner == 0)
            continue;
        if (spOwner->ownerID != nOwnerId)
            continue;
        std::map<int, Unk_UGCGroup>::iterator itGroupEnd = f218->groups.end();
        if (f218->groups.find(nGroup) == itGroupEnd)
            continue;
        int nHeight = 0;
        if (FUN_140885340(&f208)->FUN_140375130() == 0)
            nHeight = f218->groups[nGroup].heightLimit;
        else
            nHeight = f2fc;
        Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
        Unk_CMISListIter itList;
        Unk_CMISListEnd itListEnd;
        for (FUN_14114e630(pList, &itList); FUN_14035ea60(&itList, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&itList)) {
            int nKey = *FUN_1403e8d70(&itList);
            for (int nH = 1; nH <= nHeight; nH++) {
                Unk_Int3 pt = FUN_1408a0400(nKey);
                pt.z += nH;
                Cube* pCube = FUN_1410b8a60(pt);
                if (pCube != 0 && FUN_14053fc10(FUN_1408b4f20(pCube)) == nCategory)
                    *pnCount = *pnCount + 1;
            }
        }
        break;
    }
    return *pnCount > 0;
}

// @0x1410d4940
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
unsigned __int64 CubeMapInformationService::FUN_1410d4940()
{
    Unk_CMISInv* pInv = FUN_140886640(FUN_1409eed80());
    Unk_CMISTree<282> counts;
    ATL::CAtlArray<void*> stock;
    DAT_143ab2e50.FUN_140dfc750(&stock);
    for (unsigned __int64 i = 0; i < stock.GetCount(); i++) {
        Unk_CMISStockRef ref(stock.GetAt(i));
        if (ref.FUN_140df59d0(0))
            continue;
        int nItem = FUN_140dfc370(ref.FUN_140df5b10());
        Unk_CMISRecRef rec;
        FUN_1405566e0(FUN_140281980(), &rec, nItem);
        if (FUN_140885250(&rec, 0) == 0) {
            Unk_CMISInvPtr spSlot(0);
            if (pInv->FUN_14088acd0(&FUN_14056d580(&rec)->key, &spSlot) != 0) {
                Unk_CMISIter<282> itEnd, itFind;
                if (FUN_141127110(FUN_141158380(&counts, &itFind, &FUN_14056d580(&rec)->key.m_item), FUN_1411521b0(&counts, &itEnd)) == 0)
                    *FUN_141128210(&counts, &FUN_14056d580(&rec)->key.m_item) = *FUN_141128210(&counts, &FUN_14056d580(&rec)->key.m_item) + 1;
                else
                    *FUN_141128210(&counts, &FUN_14056d580(&rec)->key.m_item) = 1;
            }
        }
        FUN_14056c300(&rec);
    }
    unsigned __int64 nTotal = 0;
    Unk_CMISIter<282> it, itEnd2;
    for (FUN_14114e4e0(&counts, &it); FUN_141127840(&it, FUN_1411521b0(&counts, &itEnd2)); FUN_141129cd0(&it)) {
        Unk_CMISInvKey key;
        key.m_item = FUN_1411287a0(&it)->m_key;
        key.m_need = FUN_1411287a0(&it)->m_val;
        Unk_CMISInvPtr spSlot(0);
        if (pInv->FUN_14088acd0(&key, &spSlot) != 0) {
            if (spSlot.FUN_140889010()->m_need <= key.m_need)
                nTotal += spSlot.FUN_140889010()->m_count;
        }
    }
    return nTotal;
}

// ---- w138 batch 18 ----
Unk_CMISListIter* FUN_141158620(Unk_CMISTree<267>*, Unk_CMISListIter*, const int*);         // find
void FUN_141156520(Unk_CMISTree<267>*, const int*);                                         // erase
bool FUN_141126cd0(Unk_CMISIter<266>*, Unk_CMISIter<266>*);                                 // operator==
void FUN_141126100(Unk_CMISBlock* pDst, const Unk_CMISBlock* pSrc);                         // operator=
Unk_CMISBlock* FUN_141127c10(Unk_CMISTree<266>*, const int*);                               // operator[]
void FUN_14111c730(Unk_CMISTree<259>*, Unk_CMISIter<259>*, Unk_CMISIter<259>);              // erase
void FUN_140965020(MS2Ptr<Cube>* pDst, MS2Ptr<Cube>* pSrc);                                 // operator=

// @0x1410cb4c0
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410cb4c0(Unk_CMISBlock rec)
{
    int nKey = FUN_1408a13d0(((Unk_CMISDollRec*)&rec)->m_ptPos);
    Unk_CMISListIter itFindSet;
    Unk_CMISListEnd itEndSet;
    if (FUN_14035ea60(FUN_141158620(&f128, &itFindSet, &nKey), FUN_1411522d0(reinterpret_cast<Unk_CMISIntList*>(&f128), &itEndSet)) == 0) {
        Unk_CMISIter<266> itEnd, itFind;
        if (FUN_141126cd0(FUN_1411572e0(&f118, &itFind, &nKey), FUN_1411519d0(&f118, &itEnd)))
            FUN_141126100(FUN_141127c10(&f118, &nKey), &rec);
    } else {
        Unk_CMISIter<260> itEnd, itFind;
        if (FUN_1411274c0(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)) == 0) {
            FUN_141126100(FUN_141127c10(&f118, &nKey), &rec);
        } else {
            MS2Ptr<Cube> spCube(*FUN_141127cd0(&f98, &nKey));
            const Unk_CMISEntityRef* pId;
            if (FUN_1408a9090(&spCube->entity) == 0)
                pId = reinterpret_cast<const Unk_CMISEntityRef*>(&s_cubeMapNone);
            else
                pId = FUN_1408b76f0(FUN_1408a9280(&spCube->entity));
            Unk_CMISEntityRef idOld(*pId);
            egf::EntityPtr spNew = FUN_1410bc3d0(Unk_CMISBlock(rec));
            FUN_140964eb0(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity), &spNew);
            Unk_CMISIter<259> itFindE, itEndE;
            FUN_1411581c0(&fa8, &itFindE, &idOld);
            if (FUN_141127800(&itFindE, FUN_1411520f0(&fa8, &itEndE)))
                FUN_14111c730(&fa8, &itEndE, itFindE);
            if (FUN_1408a9090(&spCube->entity) != 0)
                FUN_140965020(FUN_141128190(&fa8, FUN_1408b76f0(FUN_1408a9280(&spCube->entity))), &spCube);
            FUN_141156520(&f128, &nKey);
        }
    }
}

// ---- w138 batch 19 ----
struct Unk_CMISCubeNode { int m_key; int m_pad; Unk_CMISCubeTimer m_val; };
void FUN_14114e080(Unk_CMISTree<272>*, Unk_CMISIter<272>*);                                 // begin
Unk_CMISCubeNode* FUN_1411286c0(Unk_CMISIter<272>*);                                        // operator*
void FUN_141129bf0(Unk_CMISIter<272>*);                                                     // operator++
void FUN_1411549b0(Unk_CMISTree<272>*, const int*);                                         // erase
void FUN_140ae1160(egf::Entity*, unsigned, int*);                                           // SetProperty(int)

// @0x1410c9db0
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410c9db0()
{
    Unk_CMISIntList setDone;
    Unk_CMISIter<272> it, itEnd;
    for (FUN_14114e080(&f1f8, &it); FUN_141127680(&it, FUN_141151d90(&f1f8, &itEnd)); FUN_141129bf0(&it)) {
        int nKey = FUN_1411286c0(&it)->m_key;
        Unk_CMISCubeTimer* pTimer = &FUN_1411286c0(&it)->m_val;
        if (pTimer->m_timer.FUN_140868c00() != 0) {
            Unk_CMISIter<267> itIns;
            FUN_14111d290(reinterpret_cast<Unk_CMISTree<267>*>(&setDone), &itIns, &nKey);
            Cube* pCube = FUN_141127cd0(&f98, &nKey)->get();
            FUN_14098c6e0(FUN_1408a9280(&pCube->entity), 0x9004569a, &pTimer->m_bFlagB);
            FUN_14098c6e0(FUN_1408a9280(&pCube->entity), 0x2a7fd9f4, &pTimer->m_bFlagA);
            bool bFlag = false;
            FUN_1408a20a0(FUN_1408a9280(&pCube->entity), 0x23f9860e, &bFlag);
            if (pCube->field44 == 1) {
                Unk_CMISEffReq request;
                FUN_140a52ef0(&request);
                request.m_strName = FUN_1401d31f0()->m_strCubeEffect;
                request.m_nOwnerId = 7;
                FUN_1409fabf0(&request.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(FUN_1408a9090(&pCube->entity))));
                FUN_1403ed280()->FUN_1411a4a00(&request);
                FUN_1405a89e0(&request);
            }
            if (bFlag) {
                Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
                if (spInst.FUN_14098d090() != 0)
                    FUN_1413d6e60(spInst.FUN_14098d0e0(), FUN_1408a9090(&pCube->entity), 1);
            }
            bool bOn = true;
            FUN_14098c6e0(FUN_1408a9280(&pCube->entity), 0xa0b6b179, &bOn);
            if (pCube->field44 != 1) {
                int nEffect = 9;
                FUN_140ae1160(FUN_1408a9280(&pCube->entity), 0xada5c5d2, &nEffect);
                FUN_141689ec0(FUN_1409f7ca0(), FUN_1408a9090(&pCube->entity), nEffect, 0, 1);
            }
        }
    }
    Unk_CMISListIter itList;
    Unk_CMISListEnd itListEnd;
    for (FUN_14114e630(&setDone, &itList); FUN_14035ea60(&itList, FUN_1411522d0(&setDone, &itListEnd)); FUN_14035ebf0(&itList))
        FUN_1411549b0(&f1f8, FUN_1403e8d70(&itList));
}

// ---- w138 batch 20 ----
extern Unk_Int3 DAT_143ab2388;                                                              // the none cell
bool FUN_1411279c0(Unk_Int3* pA, const Unk_Int3* pB);                                       // operator!=

// @0x1410badf0
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
Cube* CubeMapInformationService::FUN_1410badf0(int nGroup, Unk_CMISPawn* pPawn)
{
    Unk_CMISIter<262> itEnd, itFind;
    if (FUN_141126e90(FUN_141157900(&fd8, &itFind, &nGroup), FUN_141151c70(&fd8, &itEnd)))
        return 0;
    Unk_Int3 cellBest = DAT_143ab2388;
    Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
    Unk_CMISListIter it;
    Unk_CMISListEnd itListEnd;
    for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
        int nKey = *FUN_1403e8d70(&it);
        Cube* pCube = FUN_1410b8a60(FUN_1408a0400(nKey));
        if (pCube != 0 && pCube->field50 == nGroup) {
            if (!FUN_1411279c0(&cellBest, &DAT_143ab2388)) {
                cellBest = *(Unk_Int3*)&pCube->position;
            } else {
                Unk_StreamPoint ptBest;
                FUN_1408a15b0(*(Unk_StreamPoint*)&cellBest, ptBest);
                Unk_StreamPoint ptCube;
                FUN_1408a15b0(*(Unk_StreamPoint*)&pCube->position, ptCube);
                float fCube = FUN_140966f00(pPawn->vfunc_18(), ptCube);
                float fBest = FUN_140966f00(pPawn->vfunc_18(), ptBest);
                if (fCube < fBest)
                    cellBest = *(Unk_Int3*)&pCube->position;
            }
        }
    }
    if (!FUN_1411279c0(&cellBest, &DAT_143ab2388))
        return 0;
    return FUN_1410b8a60(cellBest);
}

// ---- w138 batch 21 ----
void FUN_141689ec0(CPhysXHelper*, egf::Entity*, int, int);
bool FUN_141689a10(CPhysXHelper*, egf::Entity*);
void FUN_1410dc360(egf::Entity*, unsigned, int*);                                           // SetProperty(int)
void FUN_140ae1240(egf::Entity*, unsigned, Unk_CMISStr*);                                   // SetProperty(string)

// @0x1410d0e30
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410d0e30(egf::Entity* pEntity, MS2Ptr<Cube> spCube)
{
    if (pEntity == 0 || spCube.IsNull()) {
        _wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp", 0x166a);
        return;
    }
    if (spCube->field6c != 0) {
        bool bOn = true;
        FUN_14098c6e0(pEntity, 0x38141815, &bOn);
        if (!(*(Unk_StreamPoint*)&spCube->offset).FUN_140552700(DAT_143b01a60))
            FUN_1410c5570(Unk_EntRef((Unk_Entity*)pEntity));
        else
            GeneratePhysX(Unk_EntRef((Unk_Entity*)pEntity), *(Unk_StreamPoint*)&spCube->offset);
    }
    if ((const char*)spCube->textA0 == 0) {
        Unk_CMISStr strName;
        FUN_1409989e0(&strName, (const char*)spCube->textA0);
        FUN_140ae1240(pEntity, 0xde5dd580, &strName);
        FUN_1408a8900(&strName);
    }
    if (spCube->fieldA8 == 8 || spCube->fieldA8 == 9) {
        if (FUN_141689a10(FUN_1409f7ca0(), pEntity)) {
            FUN_1410dc360(pEntity, 0xada5c5d2, &spCube->fieldA8);
            FUN_141689ec0(FUN_1409f7ca0(), pEntity, (short)spCube->fieldA8, 0);
        }
    }
    int nKey = FUN_1408a03c0(spCube->position);
    Unk_CMISIter<278> itEnd, itFind;
    if (FUN_141127380(FUN_141157040(&f2b8, &itFind, &nKey), FUN_141151910(&f2b8, &itEnd))) {
        Unk_CMISIter<260> itEnd2, itFind2;
        if (FUN_141126d90(FUN_141157580(&fb8, &itFind2, &nKey), FUN_141151af0(&fb8, &itEnd2))) {
            if (FUN_1410d2730(&spCube->position) == 0) {
                bool bFlag = false;
                FUN_1408a20a0(FUN_1408a9280(&spCube->entity), 0x23f9860e, &bFlag);
                if (bFlag) {
                    Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
                    if (spInst.FUN_14098d090() != 0)
                        FUN_1413d6e60(spInst.FUN_14098d0e0(), FUN_1408a9090(&spCube->entity), 0);
                }
                bool bOff = false;
                FUN_14098c6e0(FUN_1408a9280(&spCube->entity), 0xa0b6b179, &bOff);
            }
        }
    }
}

// ---- w138 batch 22 ----
void FUN_1412314e0(Unk_CMISMagicCube*, Unk_StreamPoint ptPos, ATL::CAtlArray<void*>* pOut);   // the objects around a point
int FUN_14112e290(Unk_CMISObj498*);                                                         // the object kind (1 = cube)
bool FUN_141126b90(Unk_PayloadPtr<NoticeCubeInfo>*, int);                                   // operator==
void* FUN_1411284a0(Unk_PayloadPtr<NoticeCubeInfo>*);                                       // operator->
int FUN_1408b49e0(void* pNotice);                                                           // the notice size
void FUN_141122b40(Unk_CMISTree<284>*);                                                     // ctor
void FUN_141125c50(Unk_CMISTree<284>*);                                                     // dtor
void FUN_14111d3b0(Unk_CMISTree<284>*, Unk_CMISIter<284>*, Unk_CMISSlot*);                  // insert
Unk_CMISIter<284>* FUN_1411588c0(Unk_CMISTree<284>*, Unk_CMISIter<284>*, void* pKey);       // find
bool FUN_1411271d0(Unk_CMISIter<284>*, Unk_CMISIter<284>*);                                 // operator==
__int64 FUN_14115adf0(Unk_CMISTree<284>*);                                                  // the element count
void FUN_141126790(Unk_CMISTree<284>*, Unk_CMISTree<284>*);                                 // operator=
void FUN_1412273b0(Unk_CMISObj498*);                                                        // link the object

// @0x1410c8e40
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410c8e40()
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPawn == 0)
        return;
    Unk_StreamPoint ptPawn = pPawn->FUN_1416767d0();
    ATL::CAtlArray<void*> aNear;
    FUN_1412314e0(FUN_1409670b0(), ptPawn, &aNear);
    Unk_CMISTree<284> found;
    for (unsigned __int64 i = 0; i < aNear.GetCount(); i++) {
        Unk_CMISSlot slot(*reinterpret_cast<Unk_CMISSlot*>(&aNear.GetAt(i)));
        if (FUN_14112e290(FUN_1409658e0(&slot)) == 1) {
            MS2Ptr<Cube> spCube(FUN_1410b8b00(FUN_14112e110(FUN_1409658e0(&slot))));
            if (!spCube.IsNull()) {
                if (FUN_141126b90(&spCube->notice, 0) == 0) {
                    float fLen = ptPawn.FUN_140965c40(spCube->FUN_1408b5370()).FUN_140967ac0();
                    float fRad = ((float)FUN_1408b49e0(FUN_1411284a0(&spCube->notice)) - 0.5f) * 150.0f;
                    if (fLen <= fRad) {
                        Unk_CMISIter<284> itIns;
                        FUN_14111d3b0(&found, &itIns, &slot);
                    }
                }
            }
        }
    }
    Unk_CMISIter<284> itCur, itTmp, itTmp2, itEnd, itFind, itOld;
    FUN_141120750(&itCur);
    itCur = *FUN_14114e7f0(&f498, &itTmp);
    while (FUN_141127900(&itCur, FUN_141152450(&f498, &itTmp2))) {
        itEnd = *FUN_141152450(&found, &itTmp);
        if (FUN_1411271d0(FUN_1411588c0(&found, &itFind, FUN_141128b30(&itCur)), &itEnd))
            FUN_141227780(FUN_1409658e0(FUN_141128b30(&itCur)));
        FUN_141129990(&itCur, &itOld, 0);
    }
    if (FUN_14115adf0(&found) != 0) {
        itCur = *FUN_14114e7f0(&found, &itTmp);
        while (FUN_141127900(&itCur, FUN_141152450(&found, &itTmp2))) {
            itEnd = *FUN_141152450(&f498, &itTmp);
            if (FUN_1411271d0(FUN_1411588c0(&f498, &itFind, FUN_141128b30(&itCur)), &itEnd))
                FUN_1412273b0(FUN_1409658e0(FUN_141128b30(&itCur)));
            FUN_141129990(&itCur, &itOld, 0);
        }
    }
    FUN_141126790(&f498, &found);
}

// ---- w138 batch 23 ----
struct Unk_CMISNearMap;                                                                     // map: group -> nearest cell of the group
struct Unk_CMISNearIter { void* m_p; };
Unk_CMISNearIter* FUN_1411518b0(Unk_CMISNearMap*, Unk_CMISNearIter*);                       // end
Unk_CMISNearIter* FUN_141156f60(Unk_CMISNearMap*, Unk_CMISNearIter*, const int*);           // find
bool FUN_141127340(Unk_CMISNearIter*, Unk_CMISNearIter*);                                   // operator!=
Unk_Int3* FUN_141127ad0(Unk_CMISNearMap*, const int*);                                      // operator[]

// @0x1410bb170
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410bb170(Unk_CMISPawn* pPawn, int nDx, int nDy, int nDz, Unk_CMISNearMap* pMap)
{
    Unk_StreamPoint ptA;
    FUN_1410b7ad0(reinterpret_cast<PCBase*>(pPawn), -150.0f, &ptA, 0);
    Unk_StreamPoint ptB;
    FUN_1410b7a20(ptA, &ptB);
    Cube* pBase = FUN_1410b8ab0(ptB);
    if (pBase == 0) {
        ptB.z = ptB.z + 150.0f;
        pBase = FUN_1410b8ab0(ptB);
        if (pBase == 0)
            return;
    }
    for (int x = pBase->position.x - nDx; x <= pBase->position.x + nDx; x++) {
        for (int y = pBase->position.y - nDy; y <= pBase->position.y + nDy; y++) {
            for (int z = pBase->position.z - nDz; z <= pBase->position.z + nDz; z++) {
                Cube* pCube = FUN_1410b8a60(Unk_Int3(x, y, z));
                if (pCube != 0 && pCube->field50 != 0) {
                    Unk_CMISNearIter itEnd, itFind;
                    if (FUN_141127340(FUN_141156f60(pMap, &itFind, &pCube->field50), FUN_1411518b0(pMap, &itEnd)) == 0) {
                        *FUN_141127ad0(pMap, &pCube->field50) = pCube->position;
                    } else {
                        Unk_StreamPoint ptNear;
                        FUN_1408a15b0(*(Unk_StreamPoint*)FUN_141127ad0(pMap, &pCube->field50), ptNear);
                        Unk_StreamPoint ptThis;
                        FUN_1408a15b0(*(Unk_StreamPoint*)&pCube->position, ptThis);
                        float fThis = FUN_140966f00(pPawn->vfunc_18(), ptThis);
                        float fNear = FUN_140966f00(pPawn->vfunc_18(), ptNear);
                        if (fThis < fNear)
                            *FUN_141127ad0(pMap, &pCube->field50) = pCube->position;
                    }
                }
            }
        }
    }
}

// ---- w138 batch 24 ----
Unk_CMISIter<265>* FUN_141151d30(Unk_CMISTree<265>*, Unk_CMISIter<265>*);                   // end
Unk_CMISIter<265>* FUN_141157ac0(Unk_CMISTree<265>*, Unk_CMISIter<265>*, const int*);       // find
bool FUN_141126f10(Unk_CMISIter<265>*, Unk_CMISIter<265>*);                                 // operator==
void FUN_1408a2060(egf::Entity*, unsigned, Unk_CMISStr*);                                   // GetProperty(string)
const char* FUN_1408ac310(Unk_CMISStr*);
int FUN_1408a01e0(CString strType);                                                         // the cube kind of a name

// @0x1410bca70
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
bool CubeMapInformationService::FUN_1410bca70(__int64 nOwner, Unk_Int3 pt, float fRot, int nField50, int nField54, __int64 nUnused, int nFieldD8)
{
    int nCell = FUN_1408a03c0(pt);
    Unk_CMISIter<265> itEnd, itFind;
    if (FUN_141126f10(FUN_141157ac0(&f2e0, &itFind, &nCell), FUN_141151d30(&f2e0, &itEnd)))
        return false;
    Unk_CMISEntityRef idOld(*FUN_141127ed0(&f2e0, &nCell));
    egf::EntityPtr spOld(static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411cf440(*reinterpret_cast<const egf::EntityID*>(&idOld)));
    if (FUN_1408b70b0(&spOld, 0))
        return false;
    Unk_StreamPoint ptCell = DAT_143b01a60;
    FUN_1408a15b0(*(Unk_StreamPoint*)&pt, ptCell);
    Unk_StreamPoint ptRot = DAT_143b01a60;
    ptRot.z = fRot;
    Unk_CMISStr strKind;
    FUN_1409989e0(&strKind, "None");
    FUN_1408a2060(FUN_1408a9280(&spOld), 0x15014205, &strKind);
    int nKind = FUN_1408a01e0(CString(FUN_1408ac310(&strKind)));
    egf::EntityPtr spNew = static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411ce7c0(efd::utf8string("MS2CubeProp"),
        efd::utf8string("urn:gamebryo-scenegraph:Empty"), NiPoint3(ptCell.x, ptCell.y, ptCell.z), NiPoint3(ptRot.x, ptRot.y, ptRot.z), 1.0f, 0, 0);
    bool bResult = false;
    if (!FUN_1408b70b0(&spNew, 0)) {
        int nFlag = 0;
        if (((Unk_CMISFlatModel*)FUN_1408a9bd0(FUN_1408a9280(&spOld)))->FUN_14211e240(0xd8dea70d))
            nFlag = 1;
        CubeItemInfo info;
        MS2Ptr<Cube> spCube(new Cube);
        spCube->field18 = nOwner;
        spCube->position = pt;
        spCube->item->FUN_1408b3700(&info);
        spCube->entity = spNew;
        spCube->field44 = nKind;
        spCube->field50 = nField50;
        spCube->field54 = nField54;
        spCube->field48 = 1;
        spCube->field4c = 0;
        spCube->field70 = nFlag;
        spCube->fieldD8 = nFieldD8;
        memcpy(&spCube->fieldD4, &fRot, sizeof(float));
        FUN_140965020(FUN_141128190(&f78, FUN_1408b76f0(FUN_1408a9280(&spNew))), &spCube);
        bResult = true;
    }
    FUN_1408a8900(&strKind);
    return bResult;
}

// ---- w142 batch 1 ----
#include <NiTexturingProperty.h>
#include <NiMesh.h>
struct Unk_CMISTexPtr;
void FUN_14097f4a0(Unk_CMISTexPtr* p);                                                      // release
struct Unk_CMISTexPtr { ~Unk_CMISTexPtr() { FUN_14097f4a0(this); } void* m_p; };           // texture handle (8 bytes)
void* FUN_14097fbf0(Unk_CMISTexPtr* p);                                                     // handle -> texture
class Unk_CMISResMgr { public: Unk_CMISTexPtr FUN_141552f90(CString strPath, int nFlags); };    // texture load by path
Unk_CMISResMgr* FUN_140a0afd0();
struct Unk_CMISSceneIter                                                                    // scene walker (0x30 bytes; ctor 0x14098cb80, dtor 0x14098cf00)
{
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5;
};
MS2_CHECK_SIZE(Unk_CMISSceneIter, 0x30);
void FUN_14098cb80(Unk_CMISSceneIter* pIter, NiAVObject* pRoot);
NiAVObject* FUN_14098e0d0(Unk_CMISSceneIter* pIter, int bDescend);
void FUN_14098cf00(Unk_CMISSceneIter* pIter);
int FUN_1413d6f40(HardwareInstancingService* pSvc, egf::Entity* pEntity);
NiTexturingProperty::Map* FUN_14109a6b0(NiTexturingProperty* pProp);                        // GetBaseMap
unsigned FUN_140d89850(NiTexturingProperty::Map* pMap);                                     // GetClampMode
void FUN_140980e20(NiTexturingProperty::Map* pMap, unsigned nClamp);                        // SetClampMode
void FUN_140981040(NiTexturingProperty::Map* pMap, void* pTexture);                         // SetTexture

// @0x1410cab10
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410cab10(Cube* pCube)
{
    bool bFlag = false;
    FUN_1408a20a0(FUN_1408a9280(&pCube->entity), 0x23f9860e, &bFlag);
    if (bFlag) {
        Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
        if (spInst.FUN_14098d090() != 0) {
            if (FUN_1413d6f40(spInst.FUN_14098d0e0(), FUN_1408a9090(&pCube->entity)) != 0) {
                bool bOn = true;
                FUN_14098c6e0(FUN_1408a9280(&pCube->entity), 0xa0b6b179, &bOn);
            }
        }
    }
    int nPick = rand() % 4;
    CString strTex = FUN_1401d31f0()->m_strCubeFlash[0];
    if (nPick == 0)
        strTex += FUN_1401d31f0()->m_strCubeFlash[1];
    else if (nPick == 1)
        strTex += FUN_1401d31f0()->m_strCubeFlash[2];
    else if (nPick == 2)
        strTex += FUN_1401d31f0()->m_strCubeFlash[3];
    else if (nPick == 3)
        strTex += FUN_1401d31f0()->m_strCubeFlash[4];
    Unk_CMISTexPtr spTexture = FUN_140a0afd0()->FUN_141552f90(strTex, 1);
    Unk_CMISSvcPtr spInst2(FUN_14098c5b0(&DAT_143b059e8));
    NiAVObject* pRoot = FUN_141b6efc0(FUN_1408a9090(&pCube->entity));
    if (pRoot != 0) {
        Unk_CMISSceneIter iter;
        FUN_14098cb80(&iter, pRoot);
        for (;;) {
            NiAVObject* pObj = FUN_14098e0d0(&iter, 1);
            if (pObj == 0)
                break;
            NiMesh* pMesh = NiDynamicCast(NiMesh, pObj);
            if (pMesh == 0)
                continue;
            NiTexturingProperty* pTex = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(8));
            if (FUN_14109a6b0(pTex) == 0)
                continue;
            NiTexturingProperty::Map* pMap = NiNew NiTexturingProperty::Map;
            FUN_140980e20(pMap, FUN_140d89850(FUN_14109a6b0(pTex)));
            FUN_140981040(pMap, FUN_14097fbf0(&spTexture));
            pTex->SetDecalMap(0, pMap);
            pMesh->UpdateProperties();
            break;
        }
        pRoot->UpdateProperties();
        pRoot->UpdateEffects();
        pRoot->Update(0.0f, true);
        FUN_14098cf00(&iter);
    }
}

// ---- w142 batch 2: cf160 / c1330 ----
class ObjectWeaponInfo { public: void* m_unk[11]; };                                        // 0x58 bytes, ctor 0x1408b45b0
MS2_CHECK_SIZE(ObjectWeaponInfo, 0x58);
ObjectWeaponInfo* FUN_1408b45b0(ObjectWeaponInfo* pMem);
void FUN_1408a1640(Cube* pCube);
void FUN_1410b2510(Unk_CMISTree<277>* pTree, int x, int y, int z);                          // insert a cell
void FUN_1401854f0(ATL::CAtlArray<Unk_CMISElem458*>* pArr, int nKey);                       // append
void FUN_141126970(Unk_CMISCell56* pDst, Unk_CMISCell56* pSrc);                             // operator=
Unk_CMISCell56* FUN_141127b50(Unk_CMISTree<278>*, const int*);                              // operator[]
void* FUN_14112e120(egf::Entity* pEntity);
void FUN_1409a10d0(Unk_CMISCell56* pCell, void* pName);
Unk_StreamPoint FUN_1413fa320(egf::Entity* pEntity);                                        // the position of an entity
void FUN_1402bd040(Unk_StreamPoint* p);
int FUN_140ae11a0(egf::Entity*, unsigned, int*);                                            // GetProperty(int), 0 = found

// @0x1410c1330
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
MS2Ptr<Cube> CubeMapInformationService::FUN_1410c1330(Unk_StreamPoint ptWorld, float fUnused, CubeItemInfo* pInfo, int nKind,
    egf::EntityPtr spEnt, bool bUnused, int nField50)
{
    Unk_Int3 cell = FUN_1408a1430(ptWorld);
    int nKey = FUN_1408a03c0(cell);
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_1411274c0(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)) != 0)
        return MS2Ptr<Cube>((Cube*)0);
    MS2Ptr<Cube> spCube(new Cube);
    spCube->position = cell;
    spCube->item->FUN_1408b3700(pInfo);
    spCube->entity = spEnt;
    spCube->field44 = nKind;
    spCube->field50 = nField50;
    FUN_1408a1640(spCube.get());
    bool bFlag = false;
    if (FUN_1408a9090(&spEnt) != 0) {
        FUN_1408a20a0(FUN_1408a9280(&spEnt), 0x9ea356ad, &bFlag);
        if (bFlag) {
            ObjectWeaponInfo* pWeapon = FUN_1408b45b0((ObjectWeaponInfo*)::operator new(0x58));
            spCube->weapon = pWeapon;
            FUN_1401854f0(&a458, nKey);
        }
    }
    *FUN_141127cd0(&f98, &nKey) = spCube;
    *FUN_141128190(&fa8, FUN_1408b76f0(FUN_1408a9280(&spCube->entity))) = spCube;
    if (spCube->field48 != 0)
        *FUN_141127cd0(&fb8, &nKey) = spCube;
    if (spCube->field70 != 0 && spCube->field6c != 0)
        FUN_1410b2510(&f2a8, cell.x, cell.y, cell.z);
    Unk_CMISIter<262> itEnd2, itFind2;
    if (FUN_141126e90(FUN_141157900(&fd8, &itFind2, &spCube->field50), FUN_141151c70(&fd8, &itEnd2)) != 0) {
        Unk_CMISIntList empty;
        FUN_141126700(FUN_141127e10(&fd8, &spCube->field50), &empty);
    }
    Unk_CMISIter<267> itIns;
    FUN_14111d290(reinterpret_cast<Unk_CMISTree<267>*>(FUN_141127e10(&fd8, &spCube->field50)), &itIns, &nKey);
    Unk_CMISCell56 val;
    FUN_1409a10d0(&val, FUN_14112e120(FUN_1408a9280(&spEnt)));
    val.m_pos = FUN_1413fa320(FUN_1408a9090(&spEnt));
    FUN_1409618c0(FUN_1408a9280(&spEnt), 0x68c7c29d, &val.m_rot);
    FUN_141126970(FUN_141127b50(&f2b8, &nKey), &val);
    return spCube;
}

// @0x1410cf160
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410cf160(egf::Entity* pEntity)
{
    if (FUN_1408a9bd0(pEntity)->FUN_14211e240(0xf01a7608)) {
        int nGroup = 0;
        FUN_1408a2020(pEntity, 0x85ef19e7, &nGroup);
        Unk_CMISEntityRef idCopy(*FUN_1408b76f0(pEntity));
        FUN_1410bbf20(nGroup, reinterpret_cast<const egf::EntityID&>(idCopy));
    } else if (FUN_1408a9bd0(pEntity)->FUN_14211e240(0xd8dea70d)) {
        Unk_StreamPoint pt;
        FUN_1402bd040(&pt);
        FUN_1409618c0(pEntity, 0xfd95ca52, &pt);
        int nField50 = 0;
        FUN_1408a2020(pEntity, 0x85ef19e7, &nField50);
        Unk_CMISStr strKind;
        FUN_1409989e0(&strKind, "None");
        FUN_1408a2060(pEntity, 0x15014205, &strKind);
        int nKind = FUN_1408a01e0(CString(FUN_1408ac310(&strKind)));
        bool bAnimatable = false;
        FUN_1408a20a0(pEntity, 0x38141815, &bAnimatable);
        if (bAnimatable)
            FUN_1410c5570(Unk_EntRef((Unk_Entity*)pEntity));
        MS2Ptr<Cube> spCube = FUN_1410c1330(pt, 0.0f, 0, nKind, egf::EntityPtr(pEntity), false, nField50);
        if (spCube.get() != 0)
            spCube->field70 = 1;
        FUN_1408a8900(&strKind);
    } else if (FUN_1408a9bd0(pEntity)->FUN_14211e240(0xc9cd2193)) {
        bool bAnimatable = false;
        FUN_1408a20a0(pEntity, 0x38141815, &bAnimatable);
        if (bAnimatable)
            FUN_1410c5570(Unk_EntRef((Unk_Entity*)pEntity));
    }
    if (FUN_1408a9bd0(pEntity)->FUN_14211e240(0xe34a6afd)) {
        int nValue = 0;
        if (FUN_140ae11a0(pEntity, 0x1a1899fc, &nValue) == 0 && nValue != 0) {
            Unk_StreamPoint pt;
            FUN_1402bd040(&pt);
            FUN_1409618c0(pEntity, 0xfd95ca52, &pt);
            int nKey = FUN_1408a13d0(pt);
            FUN_140899bd0(FUN_141127ed0(&f2e0, &nKey), *FUN_1408b76f0(pEntity));
        }
    }
}

// ---- w142 batch 3: ba5f0, be0c0, be6e0, b9e90 ----
struct Unk_CMISIntVec;
void FUN_141122e40(Unk_CMISIntVec* p);                                                      // ctor
void FUN_141125df0(Unk_CMISIntVec* p);                                                      // dtor
struct Unk_CMISIntVec                                                                       // std::vector<int> (0x18 bytes)
{
    Unk_CMISIntVec() { FUN_141122e40(this); }
    ~Unk_CMISIntVec() { FUN_141125df0(this); }
    void* m_pFirst; void* m_pLast; void* m_pEnd;
};
void FUN_14115a9f0(Unk_CMISIntVec* pVec, const int* pValue);                                // push_back
unsigned __int64 FUN_14115af60(Unk_CMISIntVec* pVec);                                       // size
int* FUN_1411283c0(Unk_CMISIntVec* pVec, unsigned __int64 nIdx);                            // operator[]

// @0x1410ba5f0
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
int CubeMapInformationService::FUN_1410ba5f0(Unk_Int3 pt, Unk_StreamPoint ptRef)
{
    Cube* pCube = FUN_1410b8a60(pt);
    if (pCube == 0 || pCube->field60 == 0) {
        if (0.0f <= ptRef.z)
            ptRef.z = (float)(int)((ptRef.z + 89.0f) / 90.0f) * 90.0f;
        else
            ptRef.z = (float)(int)((ptRef.z - 89.0f) / 90.0f) * 90.0f;
        int nStart = FUN_1410ba4a0(ptRef);
        Unk_CMISIntVec vecDir;
        int nDir;
        nDir = 0; FUN_14115a9f0(&vecDir, &nDir);
        nDir = 1; FUN_14115a9f0(&vecDir, &nDir);
        nDir = 2; FUN_14115a9f0(&vecDir, &nDir);
        nDir = 3; FUN_14115a9f0(&vecDir, &nDir);
        nDir = 4; FUN_14115a9f0(&vecDir, &nDir);
        nDir = 2; FUN_14115a9f0(&vecDir, &nDir);
        nDir = 3; FUN_14115a9f0(&vecDir, &nDir);
        nDir = 4; FUN_14115a9f0(&vecDir, &nDir);
        int nTry = 0;
        unsigned __int64 nIdx = nStart;
        while (nTry < 4 && nIdx < FUN_14115af60(&vecDir)) {
            nTry++;
            Unk_Int3 cell = pt;
            int nDirNow = *FUN_1411283c0(&vecDir, nIdx);
            if (nDirNow == 1) {
                cell.x = cell.x - 1;
                Cube* pNear = FUN_1410b8a60(cell);
                if (pNear != 0 && pNear->field68 != 0)
                    return 1;
            } else if (nDirNow == 2) {
                cell.y = cell.y + 1;
                Cube* pNear = FUN_1410b8a60(cell);
                if (pNear != 0 && pNear->field68 != 0)
                    return 2;
            } else if (nDirNow == 3) {
                cell.x = cell.x + 1;
                Cube* pNear = FUN_1410b8a60(cell);
                if (pNear != 0 && pNear->field68 != 0)
                    return 3;
            } else if (nDirNow == 4) {
                cell.y = cell.y - 1;
                Cube* pNear = FUN_1410b8a60(cell);
                if (pNear != 0 && pNear->field68 != 0)
                    return 4;
            }
            nIdx = nIdx + 1;
        }
        return 0;
    }
    Unk_StreamPoint ptDir = DAT_143b01a60;
    *(int*)&ptDir.z = pCube->fieldD4;
    return FUN_1410ba4a0(ptDir);
}

void FUN_140b27f00(egf::Entity* pEntity, unsigned nId, const Unk_StreamPoint* pValue);      // SetProperty(Point3)
void FUN_140a38a50(egf::Entity* pEntity, unsigned nId, const Unk_StreamPoint* pValue);      // SetProperty(Point3)
void FUN_141568a90(egf::Entity* pEntity);
void FUN_1408b3810(CubeItemInfo* pInfo);
unsigned __int64 FUN_1410db860(Unk_CMISLog* pLog, int nLevel, int nCategory, const wchar_t* pFormat, const int* pA, const int* pB,
    const int* pC, const char* const* pD);

// @0x1410be0c0
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
bool CubeMapInformationService::FUN_1410be0c0(Unk_Int3 pt, int nGroup, int nFloor, Unk_CMISCell56* pCell)
{
    int nKey = FUN_1408a03c0(pt);
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_1411274c0(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)) != 0)
        return false;
    Unk_StreamPoint ptCell = DAT_143b01a60;
    FUN_1408a15b0(pt, ptCell);
    Unk_StreamPoint ptRot = DAT_143b01a60;
    egf::EntityPtr spEnt = static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411ce7c0(
        efd::utf8string(reinterpret_cast<const efd::utf8string&>(pCell->m_pName)), efd::utf8string(""),
        NiPoint3(ptCell.x, ptCell.y, ptCell.z), NiPoint3(ptRot.x, ptRot.y, ptRot.z), 1.0f, 0, 0);
    if (FUN_1408a9090(&spEnt) == 0) {
        const char* pszModel = FUN_1408ac310(reinterpret_cast<Unk_CMISStr*>(pCell));
        FUN_1410db860(FUN_140166440(), 1, 0x13, L"[ERROR] Create Default Cube Error = {0}, {1}, {2}, Model = {3}", &pt.x, &pt.y, &pt.z, &pszModel);
        return false;
    }
    Unk_CMISStr strKind;
    FUN_1409989e0(&strKind, "None");
    FUN_1408a2060(FUN_1408a9280(&spEnt), 0x15014205, &strKind);
    int nKind = FUN_1408a01e0(CString(FUN_1408ac310(&strKind)));
    FUN_140b27f00(FUN_1408a9280(&spEnt), 0x213f5f94, &pCell->m_pos);
    FUN_141568a90(FUN_1408a9090(&spEnt));
    FUN_140a38a50(FUN_1408a9280(&spEnt), 0x68c7c29d, &pCell->m_rot);
    MS2Ptr<Cube> spCube(new Cube);
    spCube->position = pt;
    FUN_1408b3810(spCube->item.get());
    spCube->entity = spEnt;
    spCube->field44 = nKind;
    spCube->field50 = nGroup;
    spCube->field54 = nFloor;
    spCube->field48 = 0;
    spCube->field70 = 1;
    spCube->field6c = 1;
    spCube->offset = NiPoint3(150.0f, 150.0f, 150.0f);
    FUN_1408a1640(spCube.get());
    *FUN_141128190(&f78, FUN_1408b76f0(FUN_1408a9280(&spEnt))) = spCube;
    FUN_1408a8900(&strKind);
    return true;
}

void FUN_1411225f0(Unk_CMISBucket* p);                                                      // ctor
void FUN_141125670(Unk_CMISBucket* p);                                                      // dtor
void FUN_141126670(Unk_CMISBucket* pDst, Unk_CMISBucket* pSrc);                             // operator=
void FUN_141126760(Unk_CMISCubeList* pDst, Unk_CMISCubeList* pSrc);                         // operator=

// @0x1410be6e0
// MS2-FUNCTIONAL: MS2Ptr/iterator temporaries and the repeated unwind blocks are laid out differently from the exe
void CubeMapInformationService::FUN_1410be6e0(MS2Ptr<Cube> spCube)
{
    if (FUN_1408b4f20(spCube.operator->()) == 0)
        return;
    MS2Ptr<CItemData> spItem = FUN_14053f870(FUN_1408b4f20(spCube.operator->()));
    if (spItem.get() == 0)
        return;
    Unk_CMISRecRef rec;
    FUN_1405566e0(FUN_140281980(), &rec, FUN_1408b4f20(spCube.operator->()));
    if (FUN_140885250(&rec, 0) != 0) {
        FUN_14056c300(&rec);
        return;
    }
    if (FUN_14056d580(&rec)->nSetId == 0) {
        FUN_14056c300(&rec);
        return;
    }
    Unk_CMISSetRef rSet;
    FUN_140b9df60(FUN_1409eed50(), &rSet, FUN_14056d580(&rec)->nSetId);
    if (rSet.FUN_1409ede50(0) != 0) {
        FUN_14056c300(&rec);
        return;
    }
    int nItem = FUN_1408b4f20(spCube.operator->());
    Unk_CMISPieceIter itEnd, itFind;
    if (FUN_1409ee120(FUN_140ba1ff0(&rSet.FUN_1409ee2d0()->m_pieces, &itFind, &nItem), FUN_1409efe40(&rSet.FUN_1409ee2d0()->m_pieces, &itEnd)) == 0) {
        int nItemLog = FUN_1408b4f20(spCube.operator->());
        FUN_140166440()->FUN_1403d7960(1, 0x13, L"세트아이템으로 지정된 아이템({0})이지만 SetItemTable({1})에는 등록되지 않았습니다", &nItemLog, &FUN_14056d580(&rec)->nSetId);
        FUN_14056c300(&rec);
        return;
    }
    Unk_CMISIter<283> itBucketEnd, itBucket;
    if (FUN_141126e10(FUN_141157740(&f440, &itBucket, &spCube->field50), FUN_141151bb0(&f440, &itBucketEnd))) {
        Unk_CMISBucket bucketNew;
        FUN_1411225f0(&bucketNew);
        FUN_141126670(FUN_141127d50(&f440, &spCube->field50), &bucketNew);
        FUN_141125670(&bucketNew);
    }
    Unk_CMISBucket* pBucket = FUN_141127d50(&f440, &spCube->field50);
    Unk_CMISBucketIter itInnerEnd, itInner;
    FUN_141151f10(pBucket, &itInnerEnd);
    if (FUN_141126f90(FUN_141157e40(pBucket, &itInner, &FUN_14056d580(&rec)->nSetId), &itInnerEnd)) {
        Unk_CMISCubeList lstNew;
        FUN_14035dea0(&lstNew);
        FUN_141126760(FUN_141128050(pBucket, &FUN_14056d580(&rec)->nSetId), &lstNew);
        FUN_14035e6c0(&lstNew);
    }
    int nCell = FUN_1408a03c0(spCube->position);
    Unk_CMISCubeList* pCells = FUN_141128050(pBucket, &FUN_14056d580(&rec)->nSetId);
    Unk_CMISListEnd itCellEnd;
    Unk_CMISListIter itCell;
    if (FUN_14035e9e0(FUN_140368510(pCells, &itCell, &nCell), FUN_140368110(pCells, &itCellEnd)) != 0) {
        Unk_CMISListIter itIns;
        FUN_14035d1e0(pCells, &itIns, &nCell);
    }
    FUN_14056c300(&rec);
}

struct Unk_CMISCubePtrSet { void* m_a; void* m_b; void* m_c; };                             // set of cube pointers
void FUN_14115a900(Unk_CMISCubePtrSet* pSet, Cube** ppCube);                                // insert
void FUN_14115a8d0(Unk_CMISCubePtrSet* pSet, Cube** ppCube);                                // insert
bool FUN_1408a8dd0(Unk_CubeOwnerPtr* pPtr, int);                                            // operator==
bool FUN_140375130(CFieldData* pData);
int* FUN_141128660(Unk_CMISIter<262>*);                                                     // operator*
void FUN_141129bb0(Unk_CMISIter<262>*);                                                     // operator++
Unk_CMISListIter* FUN_141158620(Unk_CMISIntList*, Unk_CMISListIter*, const int*);           // find
int FUN_140707710(int);

// @0x1410b9e90
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
int CubeMapInformationService::FUN_1410b9e90(__int64 nOwnerId, Unk_CMISCubePtrSet* pOut)
{
    if (DAT_143ae0fb4 == 0) {
        Unk_CMISIter<262> itGroup, itGroupEnd;
        for (FUN_14114df30(&fd8, &itGroup); FUN_1411275c0(&itGroup, FUN_141151c70(&fd8, &itGroupEnd)); FUN_141129bb0(&itGroup)) {
            int nGroup = *FUN_141128660(&itGroup);
            Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
            if (!FUN_1408a8dd0(&spOwner, 0)) {
                if (spOwner->ownerID == nOwnerId) {
                    std::map<int, Unk_UGCGroup>::iterator itFound = f218->groups.find(nGroup);
                    if (itFound != f218->groups.end()) {
                        int nDepth = 0;
                        if (!FUN_140375130(FUN_140885340(&f208)))
                            nDepth = itFound->second.heightLimit;
                        else
                            nDepth = f2fc;
                        Unk_CMISIntList setSeen;
                        Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
                        Unk_CMISListIter it;
                        Unk_CMISListEnd itListEnd;
                        for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
                            int nKey = *FUN_1403e8d70(&it);
                            for (int z = 0; z <= nDepth; z++) {
                                Unk_Int3 cell = FUN_1408a0400(nKey);
                                cell.z = cell.z + z;
                                int nCellKey = FUN_1408a03c0(cell);
                                Unk_CMISListIter itFind;
                                Unk_CMISListEnd itSeenEnd;
                                if (!FUN_14035ea60(FUN_141158620(&setSeen, &itFind, &nCellKey), FUN_1411522d0(&setSeen, &itSeenEnd))) {
                                    Unk_CMISIter<267> itIns;
                                    FUN_14111d290(reinterpret_cast<Unk_CMISTree<267>*>(&setSeen), &itIns, &nCellKey);
                                    Cube* pCube = FUN_1410b8a60(cell);
                                    if (pCube != 0 && FUN_1407071e0(pCube->fieldB4) != 0 && FUN_140707710(pCube->fieldB4) != 0
                                        && FUN_140707660(pCube->fieldB4) == 0)
                                        FUN_14115a900(pOut, &pCube);
                                }
                            }
                        }
                        return 1;
                    }
                }
            }
        }
    } else {
        Unk_CMISIter<260> itCube, itCubeEnd;
        for (FUN_14114dd70(&f98, &itCube); FUN_1411274c0(&itCube, FUN_141151af0(&f98, &itCubeEnd)); FUN_141129b50(&itCube)) {
            MS2Ptr<Cube> spCube(FUN_1411285e0(&itCube)->second);
            if (spCube->field48 != 0) {
                if (!FUN_1408b70b0(&spCube->entity, 0)) {
                    Cube* pCube = spCube.get();
                    FUN_14115a8d0(pOut, &pCube);
                }
            }
        }
    }
    return 1;
}

// ---- w142 batch 4 ----
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxPhysics.h>
#pragma pop_macro("min")
#pragma pop_macro("max")
struct Unk_CMISPropPtr { void* m_p; };                                  // smart pointer to the prop object (8 bytes)
void FUN_140ae1340(Unk_CMISPropPtr* p, void* pObj);                     // ctor
void FUN_140ae16b0(Unk_CMISPropPtr* p);                                 // dtor
Unk_CMISPropPtr* FUN_141128150(Unk_CMISTree<258>*, const Unk_CMISEntityRef*);       // operator[]
void FUN_141126090(Unk_CMISPropPtr* pDst, Unk_CMISPropPtr* pSrc);       // assign
void* FUN_14225f250(void* pMem, Unk_EntRef spOwner);                    // prop object ctor
bool FUN_141127780(Unk_CMISIter<257>*, Unk_CMISIter<257>*);
extern Unk_StreamPoint DAT_143b01a60;

// A static box actor at pos (cm, centre of the bottom face) with the given size (cm) turned around z by fAngle degrees.
static NxActor* CMISCreateBoxActor(NxScene* pScene, const Unk_StreamPoint& pos, float sx, float sy, float sz, float fAngle, const char* pszName, int nGroup)
{
    NxBoxShapeDesc box;
    box.dimensions.set(sx, sy, sz);
    box.dimensions *= 0.01f;
    box.dimensions *= 0.5f;
    box.groupsMask.bits0 = 0xffffffff;
    box.shapeFlags &= 0xffedffff;
    NxActorDesc actorDesc;
    actorDesc.shapes.pushBack(&box);
    NxVec3 vPose(pos.x * 0.01f, pos.y * 0.01f, pos.z * 0.01f);
    vPose.z += box.dimensions.z;
    actorDesc.globalPose.t = vPose;
    actorDesc.globalPose.M.rotZ((fAngle * 3.1415927f) / 180.0f);
    FUN_14168a540(FUN_1409f7ca0(), 0);
    NxActor* pActor = pScene->createActor(actorDesc);
    if (pActor != 0) {
        pActor->setName(pszName);
        NxU32 nShapes = pActor->getNbShapes();
        NxShape* const* ppShapes = pActor->getShapes();
        for (NxU32 i = 0; i < nShapes; ++i)
            ppShapes[i]->setGroup(nGroup);
    }
    return pActor;
}

// @0x1410c5680
// MS2-FUNCTIONAL: PhysX descriptor setup written with the SDK's own members; the shape group is a guess (the exe passes none)
void CubeMapInformationService::GeneratePhysX(Unk_EntRef spEnt, Unk_StreamPoint pt)
{
    Unk_CMISIter<257> itEnd, itFind;
    if (FUN_141127780(FUN_1411580e0(&f48, &itFind, FUN_1408b76f0(FUN_1408a9280(&spEnt))), FUN_141152030(&f48, &itEnd)) != 0)
        return;
    NxScene* pScene = reinterpret_cast<NxScene*>(FUN_14168a1c0(FUN_1409f7ca0()));
    if (pScene == 0)
        return;
    Unk_StreamPoint ptPos, ptRot;
    FUN_1409618c0(FUN_1408a9280(&spEnt), 0xfd95ca52, &ptPos);
    FUN_1409618c0(FUN_1408a9280(&spEnt), 0x68c7c29d, &ptRot);
    NxActor* pActor = CMISCreateBoxActor(pScene, ptPos, pt.x, pt.y, pt.z, ptRot.z, "CubeMapInformationService::GeneratePhysX", 0);
    if (pActor != 0) {
        int tmp;
        int* cat = (int*)FUN_140876480(&tmp, 0);
        void* mem = FUN_14208a860(0x98, *cat);
        void* pProp = mem == 0 ? 0 : FUN_14225f250(mem, spEnt);
        Unk_CMISPropPtr sp;
        FUN_140ae1340(&sp, pProp);
        pActor->userData = sp.m_p;
        *FUN_141128110(&f48, FUN_1408b76f0(FUN_1408a9280(&spEnt))) = pActor;
        FUN_141126090(FUN_141128150(&f58, FUN_1408b76f0(FUN_1408a9280(&spEnt))), &sp);
        FUN_140ae16b0(&sp);
    }
    FUN_14168a570(FUN_1409f7ca0());
}

// @0x1410c5ba0
// MS2-FUNCTIONAL: PhysX descriptor setup written with the SDK's own members
void CubeMapInformationService::GenerateFloorPhysX()
{
    FUN_1410c6070();
    NxScene* pScene = reinterpret_cast<NxScene*>(FUN_14168a1c0(FUN_1409f7ca0()));
    if (pScene == 0 || f218 == 0)
        return;
    if (f218->floors.find(f1dc) == f218->floors.end())
        return;
    if ((int)f218->floors.size() == f1dc)
        return;
    const Unk_UGCFloor& floor = f218->floors[f1dc];
    Unk_StreamPoint pos = DAT_143b01a60;
    pos.z = floor.startHeight + (float)floor.field4 * 150.0f;
    NxActor* pActor = CMISCreateBoxActor(pScene, pos, 1500.0f, 1500.0f, 150.0f, 0.0f, "CubeMapInformationService::GenerateFloorPhysX", 9);
    f40 = pActor;
    if (pActor != 0)
        pActor->userData = 0;
    FUN_14168a570(FUN_1409f7ca0());
}

// @0x1410c6100
// MS2-FUNCTIONAL: PhysX descriptor setup written with the SDK's own members
void CubeMapInformationService::GenerateAreaPhysX(int n)
{
    FUN_1410c6820(n);
    NxScene* pScene = reinterpret_cast<NxScene*>(FUN_14168a1c0(FUN_1409f7ca0()));
    if (pScene == 0)
        return;
    Unk_StreamPoint ptLo = DAT_143b01a60, ptHi = DAT_143b01a60;
    FUN_1408a15b0(p300, ptLo);
    FUN_1408a15b0(p30c, ptHi);
    Unk_StreamPoint size = DAT_143b01a60, pos = ptLo;
    if (n == 0) {
        size.x = 150.0f;
        size.y = (ptHi.y - ptLo.y) + 300.0f;
        size.z = (float)(f2fc + 3) * 150.0f;
        pos.x = pos.x - 150.0f;
        pos.y = (pos.y + size.y * 0.5f) - 225.0f;
        pos.z = pos.z + 150.0f;
    } else if (n == 1) {
        size.x = (ptHi.x - ptLo.x) + 150.0f;
        size.y = 150.0f;
        size.z = (float)(f2fc + 3) * 150.0f;
        pos.x = (pos.x + size.x * 0.5f) - 75.0f;
        pos.y = pos.y - 150.0f;
        pos.z = pos.z + 150.0f;
    } else if (n == 2) {
        size.x = (ptHi.x - ptLo.x) + 150.0f;
        size.y = (ptHi.y - ptLo.y) + 150.0f;
        size.z = 300.0f;
        pos.x = (pos.x + size.x * 0.5f) - 75.0f;
        pos.y = (pos.y + size.y * 0.5f) - 75.0f;
        pos.z = pos.z + (float)(f2fc + 1) * 150.0f + 150.0f;
    }
    NxActor* pActor = CMISCreateBoxActor(pScene, pos, size.x, size.y, size.z, 0.0f, "CubeMapInformationService::GenerateAreaPhysX", 7);
    f318[n] = pActor;
    if (pActor != 0)
        pActor->userData = 0;
    FUN_14168a570(FUN_1409f7ca0());
}

// @0x1410c6b90
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
int CubeMapInformationService::FUN_1410c6b90(unsigned nMask, int* pOutGroup, int nMode, Unk_CMISEntityRef* pOutEnt)
{
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pRoster == 0)
        return 0;
    Unk_StreamPoint ptA = DAT_143b01a60, ptB = DAT_143b01a60;
    FUN_1410b7ad0(reinterpret_cast<PCBase*>(pRoster), 0.0f, &ptA, 1);
    FUN_1410b7ad0(reinterpret_cast<PCBase*>(pRoster), 0.0f, &ptB, 0);
    Unk_Int3 cellA = FUN_1408a1430(ptA);
    Unk_Int3 cellB = FUN_1408a1430(ptB);
    Unk_CMISIter<264> it, itEnd;
    FUN_14114dbb0(&ff8, &it);
    while (FUN_1411273c0(&it, FUN_141151970(&ff8, &itEnd))) {
        int nGroup = FUN_141128560(&it)->m_key;
        egf::EntityPtr spEnt = FUN_1408a7ed0(&FUN_141128560(&it)->m_ref);
        if (!FUN_1408b70b0(&spEnt, 0)) {
            FUN_140899bd0(pOutEnt, *FUN_1408b76f0(FUN_1408a9280(&spEnt)));
            Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
            bool bOwned = FUN_140965820(&spOwner) != 0;
            bool bSkip = (nMode == 1 || nMode == 2) && !bOwned;
            if (!bSkip && nMode == 1 && spOwner->ownerID != FUN_141656ad0(pRoster))
                bSkip = true;
            if (!bSkip && nMode == 2 && spOwner->ownerID == FUN_141656ad0(pRoster))
                bSkip = true;
            if (!bSkip) {
                Unk_CMISHouseRef spHouse(FUN_1410c7c20(nGroup, f1b0));
                if (spHouse.FUN_141128410() != 0 && (nMask & (unsigned)spHouse.FUN_1411284b0()->m_state) == 0)
                    bSkip = true;
                else if ((nMask & 2) && bOwned)
                    bSkip = true;
                else if ((nMask & 1) && !bOwned)
                    bSkip = true;
                else if ((nMask & 4) && bOwned)
                    bSkip = true;
                else {
                    Unk_StreamPoint ptEnt = DAT_143b01a60;
                    FUN_1409618c0(FUN_1408a9280(&spEnt), 0xfd95ca52, &ptEnt);
                    Unk_Int3 cell = FUN_1408a1430(ptEnt);
                    if (FUN_1411272b0(&cell, &cellA) || FUN_1411272b0(&cell, &cellB)) {
                        *pOutGroup = nGroup;
                        return 1;
                    }
                }
            }
        }
        FUN_141129a80(&it);
    }
    return 0;
}

// @0x1410d1320
// MS2-FUNCTIONAL: the eight neighbour probes are a loop over a table instead of the exe's nested ifs
int CubeMapInformationService::FUN_1410d1320(void* pArg, Unk_StreamPoint pt, float fStep, Unk_StreamPoint* pOut)
{
    Cube* pCube = static_cast<Cube*>(pArg);
    Unk_StreamPoint ptCenter = DAT_143b01a60;
    Unk_StreamPoint ptProbe = DAT_143b01a60;
    float fHalf = fStep * 0.5f;
    FUN_1408a15b0(pCube->position, ptCenter);
    float fLimit = 75.0f;
    if (FUN_1410d2340(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptCenter), fLimit - fStep, fLimit - fStep)) {
        if (pOut != 0)
            *pOut = ptCenter;
        return 0;
    }
    float fOff = fLimit - fHalf;
    float fFar = fLimit - fStep;
    // MS2: clockwise from the upper left; the sides use the far limit on their long axis
    static const int s_dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    static const int s_dy[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
    ptProbe.z = ptCenter.z;
    for (int i = 0; i < 8; ++i) {
        ptProbe.x = ptCenter.x + (float)s_dx[i] * fOff;
        ptProbe.y = ptCenter.y + (float)s_dy[i] * fOff;
        float fLimX = s_dx[i] == 0 ? fFar : fHalf;
        float fLimY = s_dy[i] == 0 ? fFar : fHalf;
        if (FUN_1410d2340(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptProbe), fLimX, fLimY)) {
            if (pOut != 0)
                *pOut = ptProbe;
            return i + 1;
        }
    }
    return 9;
}

int FUN_14053f9c0(int nItemId);
int FUN_1408b5820(int nItemId);
int FUN_1408b5f70(int nItemId);
// @0x1410d27c0
// MS2-FUNCTIONAL: the visited-column set is a std::set<pair>, not the exe's tree helpers
bool CubeMapInformationService::FUN_1410d27c0(__int64 nOwner, int nMode, int* pCount, int* pLimit)
{
    *pLimit = 0;
    *pCount = 0;
    if (f218 == 0)
        return false;
    if (DAT_143ae0fb4 != 0)
        return true;
    Unk_CMISIter<262> it, itEnd;
    for (FUN_14114df30(&fd8, &it); FUN_1411275c0(&it, FUN_141151c70(&fd8, &itEnd)); FUN_141129bb0(&it)) {
        int nGroup = *FUN_141128660(&it);
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (spOwner == 0 || spOwner->ownerID != nOwner)
            continue;
        std::map<int, Unk_UGCGroup>::iterator itGroup = f218->groups.find(nGroup);
        if (itGroup == f218->groups.end())
            continue;
        const Unk_UGCGroup& group = itGroup->second;
        int nHeight = FUN_140885340(&f208)->FUN_140375130() != 0 ? f2fc : group.heightLimit;
        if (nMode == 0)
            *pLimit = group.buildingCount;
        else if (nMode == 1)
            *pLimit = group.maidCount;
        else if (nMode == 2)
            *pLimit = group.triggerCount;
        else if (nMode == 4)
            *pLimit = group.installNpcCount;
        std::set<std::pair<int, int> > seen;
        Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
        Unk_CMISListIter itCell;
        Unk_CMISListEnd itCellEnd;
        for (FUN_14114e630(pList, &itCell); FUN_14035ea60(&itCell, FUN_1411522d0(pList, &itCellEnd)); FUN_14035ebf0(&itCell)) {
            int nKey = *FUN_1403e8d70(&itCell);
            Unk_Int3 cell = FUN_1408a0400(nKey);
            if (!seen.insert(std::make_pair(cell.x, cell.y)).second)
                continue;
            for (int h = 1; h <= nHeight; ++h) {
                Unk_Int3 up = FUN_1408a0400(nKey);
                up.z = up.z + h;
                Cube* pCube = FUN_1410b8a60(up);
                if (pCube == 0)
                    continue;
                int nItem = FUN_1408b4f20(pCube);
                bool bCount = false;
                if (nMode == 0)
                    bCount = FUN_14053f9c0(nItem) != 0;
                else if (nMode == 1)
                    bCount = FUN_1408b5620(nItem) != 0;
                else if (nMode == 2)
                    bCount = FUN_1408b5820(nItem) != 0;
                else if (nMode == 4)
                    bCount = FUN_1408b5f70(nItem) != 0;
                if (bCount)
                    *pCount = *pCount + 1;
            }
        }
        break;
    }
    return *pLimit > 0 && *pCount < *pLimit;
}

// ---- w142 batch 5 ----
struct Unk_CMISXformVec;                                                    // vector<NiTransform>
void FUN_14115a9c0(Unk_CMISXformVec* pVec, const NiTransform* pXform);     // push_back
struct Unk_CMISMarkRec { char m_b[0x50]; };                                 // Timer (0x38) + list of the mark entities (0x18); node value of f288
void FUN_141122f30(Unk_CMISMarkRec*);                                       // ctor
void FUN_141125e70(Unk_CMISMarkRec*);                                       // dtor
void FUN_141126920(Unk_CMISMarkRec* pDst, Unk_CMISMarkRec* pSrc);           // assign
void FUN_14115a930(void* pList, egf::EntityPtr* pEnt);                      // push_back
Unk_CMISIter<275>* FUN_141151850(Unk_CMISTree<275>*, Unk_CMISIter<275>*);                           // end
Unk_CMISIter<275>* FUN_141156e80(Unk_CMISTree<275>*, Unk_CMISIter<275>*, const int*);               // find
bool FUN_141126bd0(Unk_CMISIter<275>*, Unk_CMISIter<275>*);                                         // operator==
Unk_CMISMarkRec* FUN_141127a90(Unk_CMISTree<275>*, const int*);                                     // operator[]
// @0x1410cbb40
// MS2-FUNCTIONAL: the exe's NiTransform temporary / security cookie frame is not reproduced
void CubeMapInformationService::FUN_1410cbb40(Unk_CMISXformVec* pOut, int nMode, int nGroup, Unk_StreamPoint ptPlayer, Unk_Int3 cell, bool bRot, int nMs)
{
    Unk_StreamPoint ptCell = DAT_143b01a60;
    FUN_1408a15b0(cell, ptCell);
    Unk_StreamPoint ptDir = ptPlayer.FUN_140965c40(ptCell);
    ptDir.FUN_140968990();
    ptCell = ptCell.FUN_14097fd50(ptDir.FUN_14097fc90(75.0f));
    ptCell.z = ptCell.z + 150.0f;
    Unk_StreamPoint ptRot = DAT_143b01a60;
    if (bRot)
        ptRot = Unk_StreamPoint(0.0f, 0.0f, 90.0f);
    if (nMode == 0) {
        int nHeight = 0;
        if (FUN_140885340(&f208)->FUN_140375130() == 0) {
            if (f218 != 0) {
                std::map<int, Unk_UGCGroup>::iterator itGroup = f218->groups.find(nGroup);
                if (itGroup != f218->groups.end())
                    nHeight = itGroup->second.heightLimit;
            }
        } else {
            nHeight = f2fc;
        }
        for (int i = 0; i < nHeight; ++i) {
            NiTransform xform;
            xform.MakeIdentity();
            xform.m_Translate = NiPoint3(ptCell.x, ptCell.y, ptCell.z + (float)i * 150.0f + 75.0f);
            xform.m_Rotate.FromEulerAnglesXYZ((-ptRot.x * 3.1415927f) / 180.0f, (-ptRot.y * 3.1415927f) / 180.0f, (-ptRot.z * 3.1415927f) / 180.0f);
            FUN_14115a9c0(pOut, &xform);
        }
    } else if (nMode == 1) {
        egf::EntityPtr spMark = static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411ce7c0(efd::utf8string("MS2PhysXProp"),
            efd::utf8string("urn:gamebryo-scenegraph:Eff_Own_Ground_Mark_01"), NiPoint3(ptCell.x, ptCell.y, ptCell.z), NiPoint3(ptRot.x, ptRot.y, ptRot.z), 1.0f, 1, 0);
        Unk_CMISIter<275> itEnd, itFind;
        if (FUN_141126bd0(FUN_141156e80(&f288, &itFind, &nGroup), FUN_141151850(&f288, &itEnd))) {
            Unk_CMISMarkRec rec;
            FUN_141122f30(&rec);
            FUN_141126920(FUN_141127a90(&f288, &nGroup), &rec);
            FUN_141125e70(&rec);
        }
        Unk_CMISMarkRec* pRec = FUN_141127a90(&f288, &nGroup);
        FUN_14115a930(pRec->m_b + 0x38, &spMark);
        Timer* pTimer = reinterpret_cast<Timer*>(pRec);
        if (nMs == 0)
            pTimer->FUN_1408687c0();
        else
            pTimer->FUN_140868750(nMs);
    }
}

int FUN_1416595d0(Unk_CMISRoster*);
// @0x1410c3670
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410c3670()
{
    Unk_Int3 cellMin, cellMax;
    cellMin.x = cellMin.y = cellMin.z = 0;
    cellMax = cellMin;
    FUN_1410b85f0(&cellMin, &cellMax);
    p300 = reinterpret_cast<const Unk_CubePoint&>(cellMin);
    p30c = reinterpret_cast<const Unk_CubePoint&>(cellMax);
    p300.x = (p30c.x - f2f8) + 1;
    p300.y = (p30c.y - f2f8) + 1;
    Unk_CMISIter<278> it, itEnd;
    for (FUN_14114db40(&f2b8, &it); FUN_141127380(&it, FUN_141151910(&f2b8, &itEnd)); FUN_141129a60(&it)) {
        int nKey = *FUN_141128540(&it);
        Unk_Int3 cell = FUN_1408a0400(nKey);
        MS2Ptr<Cube> spCube(FUN_1410b8b00(FUN_1408a03c0(cell)));
        if (spCube.get() == 0)
            continue;
        bool bInstanced = false;
        FUN_1408a20a0(FUN_1408a9280(&spCube->entity), 0x23f9860e, &bInstanced);
        if (cell.x < p300.x || p30c.x < cell.x || cell.y < p300.y || p30c.y < cell.y) {
            if (bInstanced) {
                Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
                if (spInst.FUN_14098d090() != 0)
                    FUN_1413d6e60(spInst.FUN_14098d0e0(), FUN_1408a9090(&spCube->entity), 0);
            }
            bool bDone = false;
            FUN_1408a20a0(FUN_1408a9280(&spCube->entity), 0x7e5f4195, &bDone);
            if (!bDone) {
                FUN_141689ec0(FUN_1409f7ca0(), FUN_1408a9090(&spCube->entity), 5, 0, 0);
                bool bSet = true;
                FUN_14098c6e0(FUN_1408a9280(&spCube->entity), 0x7e5f4195, &bSet);
            }
            bool bOff = false;
            FUN_14098c6e0(FUN_1408a9280(&spCube->entity), 0xa0b6b179, &bOff);
        } else {
            if (bInstanced) {
                Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
                if (spInst.FUN_14098d090() != 0)
                    FUN_1413d6e60(spInst.FUN_14098d0e0(), FUN_1408a9090(&spCube->entity), 1);
            }
            bool bDone = false;
            FUN_1408a20a0(FUN_1408a9280(&spCube->entity), 0x7e5f4195, &bDone);
            if (bDone) {
                int nEffect = 9;
                FUN_140ae1160(FUN_1408a9280(&spCube->entity), 0xada5c5d2, &nEffect);
                FUN_141689ec0(FUN_1409f7ca0(), FUN_1408a9090(&spCube->entity), nEffect, 0, 0);
                bool bClear = false;
                FUN_14098c6e0(FUN_1408a9280(&spCube->entity), 0x7e5f4195, &bClear);
            }
            bool bOn = true;
            FUN_14098c6e0(FUN_1408a9280(&spCube->entity), 0xa0b6b179, &bOn);
        }
    }
    GenerateAreaPhysX(1);
    GenerateAreaPhysX(0);
    GenerateAreaPhysX(2);
    if (FUN_1410c3180() == DAT_143ab2820 || FUN_140930c90(FUN_1410c3180()) || FUN_140930d20(FUN_1410c3180())) {
        Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pRoster != 0 && FUN_1416595d0(pRoster) != 0 && FUN_1410a8a90(pRoster->FUN_141530290()) != 2) {
            FUN_1410cd440();
            FUN_1410cc160(0);
            FUN_1410cc160(1);
        }
    }
    FUN_141bc8e00(FUN_1403ed2d0());
}

// ---- w142 batch 6: OnTick ----
class Unk_CMISPcObj                                                         // the actor behind a world object (PCBase)
{
public:
    virtual void vf0() = 0; virtual void vf1() = 0; virtual void vf2() = 0; virtual void vf3() = 0;
    virtual void vf4() = 0; virtual void vf5() = 0; virtual void vf6() = 0; virtual void vf7() = 0;
    virtual void vf8() = 0; virtual void vf9() = 0; virtual void vf10() = 0; virtual void vf11() = 0;
    virtual void vf12() = 0; virtual void vf13() = 0; virtual void vf14() = 0; virtual void vf15() = 0;
    virtual void vf16() = 0; virtual void vf17() = 0; virtual void vf18() = 0; virtual void vf19() = 0;
    virtual void vf20() = 0; virtual void vf21() = 0; virtual void vf22() = 0;
    virtual void SetState(int n) = 0;                                       // MS2: slot 23 (PCBase::vfunc_23)
    int FUN_14166ce30();                                                    // dead (1)
};
class Unk_CMISSystem                                                        // game-system singleton behind DAT_143ab7908
{
public:
    virtual void vf0() = 0; virtual void vf1() = 0; virtual void vf2() = 0; virtual void vf3() = 0;
    virtual void vf4() = 0; virtual void vf5() = 0; virtual void vf6() = 0; virtual void vf7() = 0;
    virtual void vf8() = 0; virtual void vf9() = 0; virtual void vf10() = 0; virtual void vf11() = 0;
    virtual void vf12() = 0; virtual void vf13() = 0; virtual void vf14() = 0; virtual void vf15() = 0;
    virtual void vf16() = 0; virtual void vf17() = 0; virtual void vf18() = 0; virtual void vf19() = 0;
    virtual void vf20() = 0; virtual void vf21() = 0; virtual void vf22() = 0; virtual void vf23() = 0;
    virtual void vf24() = 0; virtual void vf25() = 0; virtual void vf26() = 0; virtual void vf27() = 0;
    virtual void vf28() = 0; virtual void vf29() = 0; virtual void vf30() = 0; virtual void vf31() = 0;
    virtual void vf32() = 0;
    virtual void Flush() = 0;                                               // MS2: slot 33
};
Unk_CMISSystem* FUN_140a6a840();
struct Unk_CMISObjRef;                                                      // map value: intrusive pointer to a world object
class Unk_CMISObjMap;
Unk_CMISObjMap* FUN_141bd36b0(Unk_CMISWorld*);                              // the world objects (member in the exe)
void* FUN_140c20a10(Unk_CMISObjMap*);                                       // GetHeadPosition
Unk_CMISObjRef* FUN_14112e2b0(Unk_CMISObjMap*, void* pos);                  // GetValueAt
void FUN_14112e170(Unk_CMISObjMap*, void** pPos);                           // GetNext
Unk_CMISPcObj* FUN_140aac420(Unk_CMISObjRef*);
void FUN_14115b540(CCubeMotionManager*);
Unk_CMISIter<256>* FUN_14114e860(Unk_CMISTree<256>*, Unk_CMISIter<256>*);   // begin
Unk_CMISIter<256>* FUN_1411524b0(Unk_CMISTree<256>*, Unk_CMISIter<256>*);   // end
bool FUN_140a16b10(Unk_CMISIter<256>*, Unk_CMISIter<256>*);                 // operator!=
Unk_CMISEntityRef* FUN_140a16d80(Unk_CMISIter<256>*);                       // operator*
void FUN_140a17010(Unk_CMISIter<256>*);                                     // operator++
void FUN_1411501c0(Unk_CMISTree<256>*);                                     // clear
void FUN_1411cf540(void* pWorld, Unk_CMISEntityRef id);                     // destroy the entity of an id
Unk_CMISIter<273>* FUN_141157660(Unk_CMISTree<273>*, Unk_CMISIter<273>*, const int*);   // find
Unk_CMISHousePtr* FUN_141127d10(Unk_CMISTree<273>*, const int*);            // operator[]
void FUN_141153f10(Unk_CMISTree<273>*, const int*);                         // erase
void FUN_141906680(Unk_CMISPolyObj*);                                       // destroy the head ui
void FUN_141906610(Unk_CMISPolyObj*, int nKey);                             // bind the cell key
void* FUN_141906490(void* pMem, Unk_Int3 cell, CStringW strName, int nValue);   // UICubeUGCHead::UICubeUGCHead
void* FUN_141126380(Unk_CMISHousePtr* pSlot, void* pObj);                   // assign
class Unk_CMISMsgStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_CMISMsgStrings* FUN_1401a9d70();
Unk_CMISIter<260>* FUN_14111c6f0(Unk_CMISTree<260>*, Unk_CMISIter<260>* pOut, Unk_CMISIter<260> it);   // erase

// @0x1410ce8a0
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
efd::AsyncResult CubeMapInformationService::OnTick()
{
    FUN_1410c8a90();
    FUN_1410c8e40();
    FUN_1410c93c0();
    FUN_1410c9710();
    if (t250.FUN_140868c00() != 0) {
        FUN_1410ca170();
        t250.FUN_140868750(200);
    }
    FUN_14115b540(FUN_1410af790());
    FUN_1410c9db0();
    Unk_CMISIter<256> itEnt, itEntEnd;
    for (FUN_14114e860(&f30, &itEnt); FUN_140a16b10(&itEnt, FUN_1411524b0(&f30, &itEntEnd)); FUN_140a17010(&itEnt))
        FUN_1411cf540(FUN_1409670f0(), *FUN_140a16d80(&itEnt));
    FUN_1411501c0(&f30);
    if (FUN_1409657a0(&f208) != 0) {
        if (FUN_140885340(&f208)->FUN_140375100() == 0 && f218 != 0 && !f218->floors.empty() && t168.FUN_140868c00() != 0) {
            Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pRoster != 0) {
                int nMyFloor = FUN_1410c88b0(reinterpret_cast<PCBase*>(pRoster));
                Unk_CMISObjMap* pObjects = FUN_141bd36b0(FUN_1403ed2d0());
                for (void* pos = FUN_140c20a10(pObjects); pos != 0; FUN_14112e170(pObjects, &pos)) {
                    Unk_CMISPcObj* pPc = FUN_140aac420(FUN_14112e2b0(pObjects, pos));
                    if (pPc != 0 && pPc->FUN_14166ce30() == 0) {
                        int nFloor = FUN_1410c88b0(reinterpret_cast<PCBase*>(pPc));
                        pPc->SetState(nMyFloor < nFloor ? 0 : 1);
                    }
                }
            }
            t168.FUN_140868750(1000);
        }
    }
    if (t3e0.FUN_140868c00() != 0) {
        FUN_140a6a840()->Flush();
        t3e0.FUN_1408687f0();
    }
    if (FUN_1410b7d50() && f88.count != 0) {
        Unk_CMISIter<260> itCube, itCubeEnd;
        FUN_14114dd70(&f88, &itCube);
        if (FUN_1411274c0(&itCube, FUN_141151af0(&f88, &itCubeEnd))) {
            int nKey = FUN_1411285e0(&itCube)->first;
            Unk_CMISIter<273> itHead, itHeadEnd;
            if (FUN_141127500(FUN_141157660(&f228, &itHead, &nKey), FUN_141151b50(&f228, &itHeadEnd))) {
                FUN_141906680(FUN_1411284c0(FUN_141127d10(&f228, &nKey)));
                FUN_141153f10(&f228, &nKey);
            }
            MS2Ptr<Cube> spCube(FUN_1411285e0(&itCube)->second);
            void* pMem = ::operator new(0x90);
            void* pHead = 0;
            if (pMem != 0)
                pHead = FUN_141906490(pMem, FUN_1408a0400(nKey), FUN_1401a9d70()->FUN_141811980(1, FUN_1408b4f20(spCube.operator->())), spCube->fieldB4);
            FUN_141126380(FUN_141127d10(&f228, &nKey), pHead);
            FUN_141906610(FUN_1411284c0(FUN_141127d10(&f228, &nKey)), nKey);
            Unk_CMISIter<260> itNext;
            FUN_14111c6f0(&f88, &itNext, itCube);
        }
    }
    return efd::AsyncResult_Pending;
}

// ---- w142 batch 7 ----
struct Unk_CMISEntSetIter { void* m_p; };
Unk_CMISEntSetIter* FUN_14114e9f0(Unk_CMISEntSet*, Unk_CMISEntSetIter*);    // begin
Unk_CMISEntSetIter* FUN_141152630(Unk_CMISEntSet*, Unk_CMISEntSetIter*);    // end
bool FUN_141127980(Unk_CMISEntSetIter*, Unk_CMISEntSetIter*);               // operator!=
const Unk_CMISEntityRef* FUN_141128e60(Unk_CMISEntSetIter*);                // operator*
void FUN_14112ab40(Unk_CMISEntSetIter*);                                    // operator++
bool FUN_140de8e30(const Unk_CMISStr& str, const char* psz);            // == psz
float* FUN_1408b0470(void* pFloors, const int* pKey);                       // the start height of a floor (operator[])
void FUN_14115b430(CCubeMotionManager* pMgr, const Unk_CMISEntityRef* pId);                                 // stop the motions of an entity
void FUN_14115b370(CCubeMotionManager* pMgr, const Unk_CMISEntityRef* pId, float fFrom, float fTo, unsigned nMs, bool bFlag);   // fade
// @0x1410c9710
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410c9710()
{
    if (FUN_1403ed2d0()->FUN_141bcfbd0() == 0 || FUN_141151760(&f78) == false || f218 == 0 || FUN_1409657a0(&f208) == 0)
        return;
    if (FUN_140885340(&f208)->FUN_140375100() != 0)
        return;
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pRoster == 0)
        return;
    int nFloor = FUN_1410c88b0(reinterpret_cast<PCBase*>(pRoster));
    if (nFloor == 0 || f1e0 == nFloor)
        return;
    if (f1e0 != 0 && nFloor < f1e0) {
        Unk_CMISEntSet* pSet = FUN_141127e50(&f1e8, &f1e0);
        Unk_CMISEntSetIter it, itEnd;
        for (FUN_14114e9f0(pSet, &it), FUN_141152630(pSet, &itEnd); FUN_141127980(&it, &itEnd); FUN_14112ab40(&it)) {
            Unk_CMISEntityRef id(*FUN_141128e60(&it));
            egf::Entity* pEnt = static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411cf440(reinterpret_cast<const egf::EntityID&>(id));
            if (pEnt == 0)
                continue;
            Unk_CMISStr strKind;
            FUN_1409989e0(&strKind, "None");
            FUN_1408a2060(pEnt, 0x15014205, &strKind);
            Unk_StreamPoint ptEnt = DAT_143b01a60;
            FUN_1409618c0(pEnt, 0xfd95ca52, &ptEnt);
            float fStart = *FUN_1408b0470(&f218->floors, &f1e0);
            if (!FUN_140de8e30(strKind, "Stair") || ptEnt.z != fStart) {
                FUN_14115b430(FUN_1410af790(), FUN_1408b76f0(pEnt));
                FUN_14115b370(FUN_1410af790(), FUN_1408b76f0(pEnt), 1.0f, 0.0f, 200, false);
            } else {
                bool bOff = false;
                FUN_14098c6e0(pEnt, 0xa0b6b179, &bOff);
            }
            FUN_1408a8900(&strKind);
        }
    }
    if (f1e0 < nFloor) {
        Unk_CMISEntSet* pSet = FUN_141127e50(&f1e8, &nFloor);
        Unk_CMISEntSetIter it, itEnd;
        for (FUN_14114e9f0(pSet, &it), FUN_141152630(pSet, &itEnd); FUN_141127980(&it, &itEnd); FUN_14112ab40(&it)) {
            Unk_CMISEntityRef id(*FUN_141128e60(&it));
            egf::Entity* pEnt = static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411cf440(reinterpret_cast<const egf::EntityID&>(id));
            if (pEnt == 0)
                continue;
            Unk_CMISStr strKind;
            FUN_1409989e0(&strKind, "None");
            FUN_1408a2060(pEnt, 0x15014205, &strKind);
            Unk_StreamPoint ptEnt = DAT_143b01a60;
            FUN_1409618c0(pEnt, 0xfd95ca52, &ptEnt);
            float fStart = *FUN_1408b0470(&f218->floors, &nFloor);
            if (!FUN_140de8e30(strKind, "Stair") || ptEnt.z != fStart) {
                bool bOn = true;
                FUN_14098c6e0(pEnt, 0xa0b6b179, &bOn);
                FUN_14115b430(FUN_1410af790(), FUN_1408b76f0(pEnt));
                FUN_14115b370(FUN_1410af790(), FUN_1408b76f0(pEnt), 0.0f, 1.0f, 200, true);
            } else {
                bool bOn = true;
                FUN_14098c6e0(pEnt, 0xa0b6b179, &bOn);
            }
            FUN_1408a8900(&strKind);
        }
    }
    f1e0 = nFloor;
}

// ---- w142 batch 8 ----
struct Unk_CMISNearMap { void* m_head; size_t m_nCount; };
struct Unk_CMISDemolishUI;                                                                  // UIHouseDemolishDialog
struct Unk_CMISMarkEntry { int m_key; int m_pad; Unk_CMISMarkRec m_rec; };                  // node value of f288
Unk_CMISNearMap* FUN_141122140(Unk_CMISNearMap*);                                           // ctor
void FUN_1411252d0(Unk_CMISNearMap*);                                                       // dtor
Unk_CMISNearIter* FUN_14114dad0(Unk_CMISNearMap*, Unk_CMISNearIter*);                       // begin
int* FUN_141128520(Unk_CMISNearIter*);                                                      // operator* (the key)
void FUN_141129a40(Unk_CMISNearIter*);                                                      // operator++
void FUN_1411531f0(Unk_CMISNearMap*, const int*);                                           // erase
int FUN_141659610(Unk_CMISPawn*);                                                           // the pawn is a ghost (state 1)
void FUN_14152a2b0(Unk_CMISPawn*, int);                                                     // set the pawn's mark flag
Unk_CMISDemolishUI* FUN_1410dbf80(unsigned nId);                                            // find the demolish dialog
void FUN_1413503b0(Unk_CMISDemolishUI*);                                                    // show
void FUN_141350440(Unk_CMISDemolishUI*);                                                    // hide
Unk_CMISIter<275>* FUN_14114da60(Unk_CMISTree<275>*, Unk_CMISIter<275>*);                   // begin
bool FUN_141127300(Unk_CMISIter<275>*, Unk_CMISIter<275>*);                                 // operator!=
Unk_CMISMarkEntry* FUN_141128500(Unk_CMISIter<275>*);                                       // operator*
void FUN_141129a20(Unk_CMISIter<275>*);                                                     // operator++
// @0x1410ca170
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410ca170()
{
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(pRoster);
    if (pRoster == 0 || FUN_141659610(pPawn) != 0)
        return;
    FUN_14152a2b0(pPawn, 0);
    Unk_CMISNearMap mapOuter;
    FUN_141122140(&mapOuter);
    int nOuter = *FUN_1402056b0(&FUN_1401d3200()->m_limits1190);
    FUN_1410bb170(pPawn, nOuter, nOuter, 2, &mapOuter);
    Unk_CMISNearMap mapInner;
    FUN_141122140(&mapInner);
    int nInner = *FUN_1402056b0(&FUN_1401d3200()->m_limits1138);
    FUN_1410bb170(pPawn, nInner, nInner, 2, &mapInner);
    bool bAny = false;
    Unk_CMISNearIter it, itEnd, itFind;
    for (FUN_14114dad0(&mapInner, &it); FUN_141127340(&it, FUN_1411518b0(&mapInner, &itEnd)); FUN_141129a40(&it)) {
        int nGroup = *FUN_141128520(&it);
        if (FUN_141127340(FUN_141156f60(&mapOuter, &itFind, &nGroup), FUN_1411518b0(&mapOuter, &itEnd)))
            FUN_1411531f0(&mapOuter, &nGroup);
        if (FUN_1410ca900(nGroup) != 0) {
            bAny = true;
            FUN_14152a2b0(pPawn, 1);
        }
    }
    if (Unk_CMISDemolishUI* pUI = FUN_1410dbf80(0x4ea1)) {
        if (FUN_1410c3180() == 0 && bAny)
            FUN_1413503b0(pUI);
        else
            FUN_141350440(pUI);
    }
    for (FUN_14114dad0(&mapOuter, &it); FUN_141127340(&it, FUN_1411518b0(&mapOuter, &itEnd)); FUN_141129a40(&it)) {
        int nGroup = *FUN_141128520(&it);
        Unk_CMISIter<275> itMark, itMarkEnd;
        if (FUN_141127300(FUN_141156e80(&f288, &itMark, &nGroup), FUN_141151850(&f288, &itMarkEnd)) == 0) {
            Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
            if (!FUN_1408a8dd0(&spOwner, 0)) {
                if (spOwner->ownerID == FUN_141656ad0(pRoster))
                    FUN_1410ccc00(nGroup, 1, 0);
            }
            FUN_1408a8790(&spOwner);
        }
    }
    Unk_CMISIter<275> itMark, itMarkEnd;
    for (FUN_14114da60(&f288, &itMark); FUN_141127300(&itMark, FUN_141151850(&f288, &itMarkEnd)); FUN_141129a20(&itMark)) {
        int nGroup = FUN_141128500(&itMark)->m_key;
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (FUN_1408a8dd0(&spOwner, 0)) {
            FUN_1408a8790(&spOwner);
            continue;
        }
        if (spOwner->ownerID == FUN_141656ad0(pRoster)) {
            if (FUN_141127340(FUN_141156f60(&mapInner, &itFind, &nGroup), FUN_1411518b0(&mapInner, &itEnd))) {
                FUN_1410ccc00(nGroup, 0, 0);
            } else {
                Cube* pNear = FUN_1410badf0(nGroup, pPawn);
                if (pNear != 0) {
                    Unk_StreamPoint ptA;
                    FUN_1402bd040(&ptA);
                    FUN_1410b7ad0(reinterpret_cast<PCBase*>(pPawn), -150.0f, &ptA, 0);
                    Unk_StreamPoint ptB;
                    FUN_1402bd040(&ptB);
                    FUN_1410b7a20(ptA, &ptB);
                    Unk_Int3 cell = FUN_1408a1430(ptB);
                    float fDx = fabsf((float)(pNear->position.x - cell.x));
                    float fDy = fabsf((float)(pNear->position.y - cell.y));
                    int nLimit = *FUN_1402056b0(&FUN_1401d3200()->m_limits1190);
                    if (!(fDx <= (float)nLimit && fDy <= (float)nLimit)) {
                        FUN_1410ccc00(nGroup, 0, 0);
                        FUN_1408a8790(&spOwner);
                        break;
                    }
                }
            }
        } else if (reinterpret_cast<Timer*>(&FUN_141128500(&itMark)->m_rec)->FUN_140868c00() != 0) {
            FUN_1410ccc00(nGroup, 0, 0);
        }
        FUN_1408a8790(&spOwner);
    }
    FUN_1411252d0(&mapInner);
    FUN_1411252d0(&mapOuter);
}

// ---- w142 batch 9 ----
#include "ms2/placeholder/meshinstancing.h"
#include "ms2/client/ms2/entityinstancing.h"
Unk_CMISIter<260>* FUN_141151af0(Unk_CMISTree<260>*, Unk_CMISIter<260>*);                   // end
Unk_CMISIter<260>* FUN_141157580(Unk_CMISTree<260>*, Unk_CMISIter<260>*, const int*);       // find
bool FUN_1411274c0(Unk_CMISIter<260>*, Unk_CMISIter<260>*);                                 // operator!=
Unk_CMISIter<261>* FUN_141151c10(Unk_CMISTree<261>*, Unk_CMISIter<261>*);                   // end
Unk_CMISIter<261>* FUN_141157820(Unk_CMISTree<261>*, Unk_CMISIter<261>*, const int*);       // find
bool FUN_141126e50(Unk_CMISIter<261>*, Unk_CMISIter<261>*);                                 // operator==
Unk_CMISTree<287>* FUN_1411228d0(Unk_CMISTree<287>*);                                       // ctor
void FUN_1411258b0(Unk_CMISTree<287>*);                                                     // dtor
void FUN_1411266a0(Unk_CMISTree<287>* pDst, Unk_CMISTree<287>* pSrc);                       // assign
Unk_CMISIter<285>* FUN_1411517f0(Unk_CMISTree<285>*, Unk_CMISIter<285>*);                   // end
Unk_CMISIter<285>* FUN_141156da0(Unk_CMISTree<285>*, Unk_CMISIter<285>*, const int*);       // find
bool FUN_14063ec30(Unk_CMISIter<285>*, Unk_CMISIter<285>*);                                 // operator!=
int* FUN_141127a50(Unk_CMISTree<285>*, const int*);                                         // operator[]: the effect of a cube
int FUN_14112f0b0();                                                                        // the client is in a map that needs no instancing refresh
CubeItemInfo* FUN_1408b7290(Unk_PayloadPtr<CubeItemInfo>*);                                 // operator->
int FUN_1408b3860(CubeItemInfo*);                                                           // the item has a model
MeshInstancing* FUN_1413d6770(HardwareInstancingService*, const Unk_MeshInstancingConfig*); // find the instancing of a config
MeshInstancing* FUN_1413d4b40(HardwareInstancingService*, egf::Entity*, int nCellZ, unsigned nCapacity);   // create an EntityInstancing
int FUN_1413d4fe0(HardwareInstancingService*, EntityInstancing*, egf::Entity*);             // add an entity to an instancing
// @0x1410c06b0
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
bool CubeMapInformationService::FUN_1410c06b0(MS2Ptr<Cube> spCube)
{
    Unk_Int3 cell = spCube->position;
    int nKey = FUN_1408a03c0(cell);
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_1411274c0(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)))
        return false;
    FUN_140965020(FUN_141127cd0(&f98, &nKey), &spCube);
    FUN_140965020(FUN_141128190(&fa8, FUN_1408b76f0(FUN_1408a9280(&spCube->entity))), &spCube);
    if (spCube->field48 != 0)
        FUN_140965020(FUN_141127cd0(&fb8, &nKey), &spCube);
    if (spCube->field70 != 0 && spCube->field6c != 0)
        FUN_1410b2510(&f2a8, spCube->position.x, spCube->position.y, spCube->position.z);
    if (spCube->fieldD8 != 0) {
        int nHouse = spCube->fieldD8;
        Unk_StreamPoint ptDir;
        FUN_1402bd040(&ptDir);
        FUN_1409618c0(FUN_1408a9280(&spCube->entity), 0x68c7c29d, &ptDir);
        int nDir = FUN_1410ba4a0(ptDir);
        Unk_CMISIter<261> itHouseEnd, itHouse;
        if (FUN_141126e50(FUN_141157820(&fc8, &itHouse, &nHouse), FUN_141151c10(&fc8, &itHouseEnd))) {
            Unk_CMISTree<287> empty;
            FUN_1411228d0(&empty);
            FUN_1411266a0(FUN_141127dd0(&fc8, &nHouse), &empty);
            FUN_1411258b0(&empty);
        }
        Unk_CMISTree<287>* pCubes = FUN_141127dd0(&fc8, &nHouse);
        Unk_CMISIter<287> itCubesEnd, itCube;
        if (FUN_140885290(FUN_140885ca0(pCubes, &itCube, &nDir), FUN_140885c40(pCubes, &itCubesEnd)))
            FUN_140965020(FUN_141128350(pCubes, &nDir), &spCube);
    }
    if (f218 != 0) {
        if (spCube->field48 != 0 && FUN_1408b4f20(spCube.get()) != 0 && spCube->fieldB4 != 0) {
            bool bMine = false;
            if (FUN_140885340(&f208)->FUN_140375130() == 0) {
                Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), spCube->field50, spCube->field54);
                if (spOwner.get() != 0 && spOwner->ownerID == DAT_143ab2820)
                    bMine = true;
                FUN_1408a8790(&spOwner);
            } else if (FUN_1410c3180() == DAT_143ab2820) {
                bMine = true;
            }
            if (bMine && FUN_14053fc10(FUN_1408b4f20(spCube.get())) == 0xd) {
                Unk_CMISEffReq request;
                FUN_140a52ef0(&request);
                request.m_strName = FUN_1401d31f0()->m_strHouseEffect;
                request.m_nOwnerId = 0;
                FUN_1409fabf0(&request.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(FUN_1408a9090(&spCube->entity))));
                request.m_bFlag32 = true;
                bool bDrawn = false;
                FUN_14098c6e0(FUN_1408a9280(&spCube->entity), 0x2a7fd9f4, &bDrawn);
                int nEffect = FUN_1403ed280()->FUN_1411a49c0(&request);
                if (nEffect != 0) {
                    Unk_CMISIter<285> itEffEnd, itEff;
                    if (FUN_14063ec30(FUN_141156da0(&f338, &itEff, &nKey), FUN_1411517f0(&f338, &itEffEnd)))
                        FUN_1403ed280()->FUN_1411a6060(*FUN_141127a50(&f338, &nKey));
                    *FUN_141127a50(&f338, &nKey) = nEffect;
                }
                FUN_1405a89e0(&request);
            }
        }
        if (FUN_14112f0b0() == 0) {
            if (spCube->field48 != 0 && spCube->fieldA8 == 8) {
                Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
                if (spInst.FUN_14098d090() != 0) {
                    egf::Entity* pEnt = FUN_1408a9090(&spCube->entity);
                    if (FUN_1413d6890(spInst.FUN_14098d0e0(), pEnt) == 0) {
                        Unk_MeshInstancingConfig kConfig(FUN_1408a9090(&spCube->entity), 0, 0);
                        kConfig.unknown48.z = -spCube->field50;
                        EntityInstancing* pInst = dynamic_cast<EntityInstancing*>(FUN_1413d6770(spInst.FUN_14098d0e0(), &kConfig));
                        if (pInst == 0) {
                            int nW, nH, nD;
                            if (FUN_1410c81c0(spCube->field50, &nW, &nH, &nD) != 0)
                                pInst = static_cast<EntityInstancing*>(FUN_1413d4b40(spInst.FUN_14098d0e0(), FUN_1408a9090(&spCube->entity), -spCube->field50, nW * nH * nD));
                        }
                        if (pInst != 0)
                            FUN_1413d4fe0(spInst.FUN_14098d0e0(), pInst, FUN_1408a9090(&spCube->entity));
                    }
                }
            }
        } else if (spCube->field48 != 0 && FUN_140374410(FUN_141bd3060(FUN_1403ed2d0()))) {
            int nHasModel = 0;
            if (FUN_1408b7270(&spCube->item) != 0)
                nHasModel = FUN_1408b3860(FUN_1408b7290(&spCube->item));
            if (nHasModel == 0 && spCube->fieldB4 == 0) {
                Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
                if (spInst.FUN_14098d090() != 0) {
                    if (FUN_1413d6890(spInst.FUN_14098d0e0(), FUN_1408a9090(&spCube->entity)) == 0) {
                        Unk_MeshInstancingConfig kConfig(FUN_1408a9090(&spCube->entity), 0, 0);
                        kConfig.unknown48.z = -spCube->field50;
                        EntityInstancing* pInst = dynamic_cast<EntityInstancing*>(FUN_1413d6770(spInst.FUN_14098d0e0(), &kConfig));
                        if (pInst == 0)
                            pInst = static_cast<EntityInstancing*>(FUN_1413d4b40(spInst.FUN_14098d0e0(), FUN_1408a9090(&spCube->entity), -spCube->field50, 10));
                        if (pInst != 0)
                            FUN_1413d4fe0(spInst.FUN_14098d0e0(), pInst, FUN_1408a9090(&spCube->entity));
                    }
                }
            }
        }
    }
    return true;
}

// ---- w142 batch 10 ----
void FUN_141153d00(Unk_CMISTree<260>*, const int*);                                         // erase
void FUN_141152dd0(Unk_CMISTree<285>*, const int*);                                         // erase
Unk_CMISIter<259>* FUN_14114e400(Unk_CMISTree<259>*, Unk_CMISIter<259>*);                   // begin
void FUN_141129cb0(Unk_CMISIter<259>*);                                                     // operator++
Unk_CMISIter<256>* FUN_14111d3f0(Unk_CMISTree<256>*, Unk_CMISIter<256>*, const Unk_CMISEntityRef*);   // insert
bool FUN_141127580(Unk_CMISIter<261>*, Unk_CMISIter<261>*);                                 // operator!=
struct Unk_CMISColEntry { int m_key; int m_pad; MS2Ptr<Cube> m_value; };                    // node value of a house's cubes
Unk_CMISIter<287>* FUN_140885bd0(Unk_CMISTree<287>*, Unk_CMISIter<287>*);                   // begin
bool FUN_1408852d0(Unk_CMISIter<287>*, Unk_CMISIter<287>*);                                 // operator!=
Unk_CMISColEntry* FUN_140885360(Unk_CMISIter<287>*);                                        // operator*
void FUN_1408853e0(Unk_CMISIter<287>*);                                                     // operator++
void FUN_141156100(Unk_CMISTree<287>*, const int*);                                         // erase
void FUN_141bbb7f0(Unk_CMISWorld*, void* pObj, int nFlag);                                  // remove an object from the world
void FUN_1410b25a0(Unk_CMISTree<277>* pTree, int x, int y, int z);                          // remove a cell
// @0x1410c1910
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently; the magic-cube object is held raw
bool CubeMapInformationService::FUN_1410c1910(const Unk_Int3& pt, int bDefer)
{
    int nKey = FUN_1408a03c0(pt);
    Unk_CMISIter<273> itHeadEnd, itHead;
    if (FUN_141127500(FUN_141157660(&f228, &itHead, &nKey), FUN_141151b50(&f228, &itHeadEnd))) {
        FUN_141906680(FUN_1411284c0(FUN_141127d10(&f228, &nKey)));
        FUN_141153f10(&f228, &nKey);
    }
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_1411274c0(FUN_141157580(&f88, &itFind, &nKey), FUN_141151af0(&f88, &itEnd)))
        FUN_141153d00(&f88, &nKey);
    if (FUN_141126d90(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd))) {
        Unk_CMISIter<259> it, itAllEnd;
        for (FUN_14114e400(&f78, &it); ; FUN_141129cb0(&it)) {
            if (!FUN_141127800(&it, FUN_1411520f0(&f78, &itAllEnd))) {
                FUN_140166440()->FUN_1410db4f0(1, 0x13, L"[ERROR] No cube on that position = {0}, {1}, {2}", pt.x, pt.y, pt.z);
                return false;
            }
            MS2Ptr<Cube> spIter(FUN_141128780(&it)->second);
            if (FUN_1408a03c0(spIter->position) == nKey) {
                Unk_CMISIter<256> itIns;
                FUN_14111d3f0(&f68, &itIns, &FUN_141128780(&it)->key);
                return false;
            }
        }
    }
    MS2Ptr<Cube> spCube(*FUN_141127cd0(&f98, &nKey));
    if (spCube->fieldD8 != 0) {
        Unk_CMISIter<261> itHouseEnd, itHouse;
        if (FUN_141127580(FUN_141157820(&fc8, &itHouse, &spCube->fieldD8), FUN_141151c10(&fc8, &itHouseEnd))) {
            Unk_CMISTree<287>* pCubes = FUN_141127dd0(&fc8, &spCube->fieldD8);
            Unk_CMISIter<287> itCube, itCubesEnd;
            for (FUN_140885bd0(pCubes, &itCube); FUN_1408852d0(&itCube, FUN_140885c40(pCubes, &itCubesEnd)); FUN_1408853e0(&itCube)) {
                Unk_CMISColEntry* pEntry = FUN_140885360(&itCube);
                if (pEntry->m_value.get() == spCube.get())
                    FUN_141156100(pCubes, &pEntry->m_key);
            }
        }
    }
    Unk_CMISIter<285> itEffEnd, itEff;
    if (FUN_14063ec30(FUN_141156da0(&f338, &itEff, &nKey), FUN_1411517f0(&f338, &itEffEnd))) {
        FUN_1403ed280()->FUN_1411a6060(*FUN_141127a50(&f338, &nKey));
        FUN_141152dd0(&f338, &nKey);
    }
    Unk_CMISEffReq request;
    FUN_140a52ef0(&request);
    request.m_strName = FUN_1401d31f0()->m_strRemoveEffect;
    request.m_nOwnerId = 7;
    FUN_1409fabf0(&request.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(FUN_1408a9090(&spCube->entity))));
    FUN_1403ed280()->FUN_1411a4a00(&request);
    FUN_141153d00(&f98, &nKey);
    FUN_141153d00(&fb8, &nKey);
    Unk_CMISIter<259> itById, itByIdEnd;
    FUN_1411581c0(&fa8, &itById, FUN_1408b76f0(FUN_1408a9280(&spCube->entity)));
    if (FUN_141127800(&itById, FUN_1411520f0(&fa8, &itByIdEnd))) {
        Unk_CMISIter<259> itErased;
        FUN_14111c730(&fa8, &itErased, itById);
    }
    if (FUN_1407071e0(spCube->fieldB4) != 0) {
        CString strKey;
        strKey.Format("%d_%d", spCube->field44, FUN_1408a03c0(spCube->position));
        FUN_1409670b0()->FUN_141230df0(strKey);
        if (FUN_1407072e0(spCube->fieldB4) != 0) {
            Unk_CMISIter<265> itMagicEnd, itMagic;
            if (FUN_141127640(FUN_141157ac0(&f108, &itMagic, &nKey), FUN_141151d30(&f108, &itMagicEnd))) {
                void* pMagic = FUN_1403ed2d0()->FUN_141bd0fa0(Unk_CMISEntityRef(*FUN_141127ed0(&f108, &nKey)));
                if (pMagic != 0)
                    FUN_141bbb7f0(FUN_1403ed2d0(), pMagic, 0);
                FUN_1411547a0(&f108, &nKey);
            }
        }
    }
    Unk_CMISIter<265> itDeferEnd, itDefer;
    if (bDefer != 0 && FUN_141126f10(FUN_141157ac0(&f2c8, &itDefer, &nKey), FUN_141151d30(&f2c8, &itDeferEnd)))
        FUN_140899bd0(FUN_141127ed0(&f2c8, &nKey), *FUN_1408b76f0(FUN_1408a9280(&spCube->entity)));
    else
        FUN_1410c5340(Unk_CMISEntityRef(*FUN_1408b76f0(FUN_1408a9280(&spCube->entity))));
    static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411cf570(FUN_1408a9090(&spCube->entity));
    FUN_1410b25a0(&f2a8, pt.x, pt.y, pt.z);
    FUN_1410ce020(spCube);
    if (FUN_14112f0b0() == 0) {
        if (spCube->field48 != 0 || spCube->fieldA8 == 8) {
            Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
            if (spInst.FUN_14098d090() != 0 && FUN_1413d6890(spInst.FUN_14098d0e0(), FUN_1408a9090(&spCube->entity)) == 0)
                FUN_1413d6f40(spInst.FUN_14098d0e0(), FUN_1408a9090(&spCube->entity));
        }
    } else if (spCube->field48 != 0) {
        Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
        if (spInst.FUN_14098d090() != 0 && FUN_1413d6890(spInst.FUN_14098d0e0(), FUN_1408a9090(&spCube->entity)) == 0)
            FUN_1413d6f40(spInst.FUN_14098d0e0(), FUN_1408a9090(&spCube->entity));
    }
    FUN_1405a89e0(&request);
    return true;
}

// ---- w142 batch 11 ----
#include "ms2/placeholder/tixmldocument.h"
struct Unk_CMISXmlNode { char m_raw[0x90]; };                                               // TiXmlElement / TiXmlComment / TiXmlDeclaration storage
void FUN_14086f2f0(Unk_CMISXmlNode* pElem, const char* pszName);                            // TiXmlElement ctor
void FUN_14086f450(Unk_CMISXmlNode* pElem);                                                 // TiXmlElement dtor
void FUN_1408704d0(Unk_CMISXmlNode* pDecl, const char* pszVersion, const char* pszEncoding, const char* pszStandalone);   // TiXmlDeclaration ctor
void FUN_1408700b0(Unk_CMISXmlNode* pComment, const char* pszText);                         // TiXmlComment ctor
void FUN_1408724d0(Unk_CMISXmlNode* pComment);                                              // TiXmlComment dtor
void FUN_14086e000(void* pParent, const void* pChild);                                      // InsertEndChild
void FUN_14086f8d0(void* pElem, const char* pszName, const char* pszValue);                 // SetAttribute(string)
void FUN_140873ce0(void* pElem, const char* pszName, unsigned int nValue);
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);
void FUN_140873e30(void* pElem, const char* pszName, float fValue);
void FUN_140874050(void* pElem, const char* pszName, const CString& strValue);
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* pszPath);                               // SaveFile
CString FUN_1409a2360(const char* psz, int n);                                              // text conversion
CString FUN_14016a5c0(const char* psz, int n);                                              // text conversion
struct Unk_CMISAutoCube                                                                     // AutomaticCreateCubeInfo (0x50, ctor 0x141122e70): a cube that is created by the game, not stored in the map
{
    char m_hdr[0x18];                                                                       // CPtred header
    int m_nItemId;                                                                          // +0x18
    Unk_Int3 m_offset;                                                                      // +0x1c
    float m_fRotation;                                                                      // +0x28
    int m_nWallDir;                                                                         // +0x2c
    char m_pad30[0x20];
};
MS2_CHECK_SIZE(Unk_CMISAutoCube, 0x50);
void FUN_141122e70(void* pMem);                                                             // AutomaticCreateCubeInfo::AutomaticCreateCubeInfo
typedef MS2Ptr<CPtred> Unk_CMISAutoPtr;                                                     // MS2Ptr<AutomaticCreateCubeInfo>
static Unk_CMISAutoCube* Unk_CMISAuto(const Unk_CMISAutoPtr& sp) { return reinterpret_cast<Unk_CMISAutoCube*>(sp.get()); }
typedef Unk_CMISTree<294> Unk_CMISColumnSet;                                                // set of the (x, y) columns already exported
typedef Unk_CMISTree<295> Unk_CMISAutoList;                                                 // the automatic cubes in the order of discovery
Unk_CMISColumnSet* FUN_141122a70(Unk_CMISColumnSet*);                                       // ctor
void FUN_141125bb0(Unk_CMISColumnSet*);                                                     // dtor
Unk_CMISIter<294>* FUN_141152330(Unk_CMISColumnSet*, Unk_CMISIter<294>*);                   // end
Unk_CMISIter<294>* FUN_141158700(Unk_CMISColumnSet*, Unk_CMISIter<294>*, const Unk_CMISPairRes&);   // find
bool FUN_141127880(Unk_CMISIter<294>*, Unk_CMISIter<294>*);                                 // operator!=
Unk_CMISIter<294>* FUN_14111d2d0(Unk_CMISColumnSet*, Unk_CMISIter<294>*, const Unk_CMISPairRes&);   // insert
Unk_CMISAutoList* FUN_141122af0(Unk_CMISAutoList*);                                         // ctor
void FUN_141125c10(Unk_CMISAutoList*);                                                      // dtor
Unk_CMISIter<295>* FUN_14111d370(Unk_CMISAutoList*, Unk_CMISIter<295>*, const Unk_CMISAutoPtr*);   // insert
Unk_CMISIter<295>* FUN_14114e780(Unk_CMISAutoList*, Unk_CMISIter<295>*);                    // begin
Unk_CMISIter<295>* FUN_1411523f0(Unk_CMISAutoList*, Unk_CMISIter<295>*);                    // end
bool FUN_1411278c0(Unk_CMISIter<295>*, Unk_CMISIter<295>*);                                 // operator!=
Unk_CMISAutoPtr* FUN_141128b10(Unk_CMISIter<295>*);                                // operator*
void FUN_141129970(Unk_CMISIter<295>*);                                                     // operator++
int* FUN_141128660(Unk_CMISIter<262>*);                                                     // operator* (the group)
void FUN_141129bb0(Unk_CMISIter<262>*);                                                     // operator++
static CString Unk_CMISFormatPoint(const Unk_Int3& pt)                                      // "x,y,z" (0x141b6eee0)
{
    CString str;
    str.Format("%d,%d,%d", (unsigned)pt.x, (unsigned)pt.y, (unsigned)pt.z);
    return str;
}
// @0x1410d3450
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently; the document is a stack object and the declaration node is not destroyed
int CubeMapInformationService::FUN_1410d3450(CString strName)
{
    if (!FUN_140374410(FUN_1403ed2d0()->FUN_141bd3060()))
        return 0;
    Unk_CubePoint base;
    if (FUN_1410d4340(&base) == 0)
        return 0;
    if (f218 == 0)
        return 0;
    if (f218->groups.find(1) == f218->groups.end())
        return 0;
    TiXmlDocument doc;
    Unk_CMISXmlNode decl;
    FUN_1408704d0(&decl, "1.0", "utf-8", "");
    FUN_14086e000(&doc, &decl);
    {
        Unk_CMISXmlNode comment;
        CString strComment = FUN_1409a2360(" \xc6\xc4\xbd\xcc\xc7\xd8\xbc\xad \xbb\xe7\xbf\xeb\xc7\xcf\xb4\xc2 \xb5\xa5\xc0\xcc\xc5\xcd\xc0\xcc\xb4\xcf \xc1\xf7\xc1\xa2 \xbc\xf6\xc1\xa4\xc7\xcf\xc1\xf6 \xb8\xb6\xbc\xbc\xbf\xe4 ", 0);
        FUN_1408700b0(&comment, strComment);
        FUN_14086e000(&doc, &comment);
        FUN_1408724d0(&comment);
    }
    Unk_CMISXmlNode elemMap;
    FUN_14086f2f0(&elemMap, "ugcmap");
    FUN_14086f8d0(&elemMap, "baseCubePoint3", Unk_CMISFormatPoint(base));
    CString strSize;
    strSize.Format("%dx%dx%d", FUN_1410c3470(), FUN_1410c3470(), FUN_1410c34b0());
    FUN_14086f8d0(&elemMap, "indoorSizeType", strSize);
    Unk_CMISAutoList listAuto;
    FUN_141122af0(&listAuto);
    Unk_CMISColumnSet setDone;
    FUN_141122a70(&setDone);
    Unk_CMISIter<262> itGroup, itGroupEnd;
    for (FUN_14114df30(&fd8, &itGroup); FUN_1411275c0(&itGroup, FUN_141151c70(&fd8, &itGroupEnd)); FUN_141129bb0(&itGroup)) {
        int nGroup = *FUN_141128660(&itGroup);
        if (nGroup == 0)
            continue;
        Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
        Unk_CMISListIter it;
        Unk_CMISListEnd itListEnd;
        for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
            Unk_Int3 cell = FUN_1408a0400(*FUN_1403e8d70(&it));
            Unk_CMISIter<294> itDone, itDoneEnd;
            if (FUN_141127880(FUN_141158700(&setDone, &itDone, FUN_14111d460(cell.x, cell.y)), FUN_141152330(&setDone, &itDoneEnd)))
                continue;
            FUN_14111d2d0(&setDone, &itDone, FUN_14111d460(cell.x, cell.y));
            if (FUN_1410b8980(cell) == 0)
                continue;
            int nHeight = 0;
            if (FUN_140885340(&f208)->FUN_140375130() == 0) {
                if (f218 != 0) {
                    std::map<int, Unk_UGCGroup>::iterator itFound = f218->groups.find(nGroup);
                    if (itFound != f218->groups.end())
                        nHeight = f218->groups[nGroup].heightLimit;
                }
            } else {
                nHeight = f2fc;
            }
            for (int k = 0; k <= nHeight; k++) {
                Unk_Int3 col(cell.x, cell.y, cell.z + k);
                int nColKey = FUN_1408a03c0(col);
                Unk_CMISIter<260> itCubeEnd, itCube;
                if (FUN_141126d90(FUN_141157580(&fb8, &itCube, &nColKey), FUN_141151af0(&fb8, &itCubeEnd)))
                    continue;
                MS2Ptr<Cube> spCube(*FUN_141127cd0(&fb8, &nColKey));
                if (spCube.get() == 0)
                    continue;
                MS2Ptr<CItemData> spItem = FUN_14053f870(FUN_1408b4f20(spCube.get()));
                if (spItem == 0)
                    continue;
                Unk_Int3 rel(col.x - base.x, col.y - base.y, col.z - base.z);
                float fRot;
                memcpy(&fRot, &spCube->fieldD4, sizeof(fRot));
                if (spItem->install.attachable == 0) {
                    Unk_CMISXmlNode elemCube;
                    FUN_14086f2f0(&elemCube, "cube");
                    FUN_140873ce0(&elemCube, "itemID", FUN_1408b4f20(spCube.get()));
                    FUN_140874050(&elemCube, "offsetCubePoint3", Unk_CMISFormatPoint(rel));
                    FUN_140873e30(&elemCube, "rotation", fRot);
                    FUN_140873ca0(&elemCube, "wallDir", 0);
                    FUN_14086e000(&elemMap, &elemCube);
                    FUN_14086f450(&elemCube);
                } else {
                    Unk_StreamPoint ptRef;
                    FUN_1402bd040(&ptRef);
                    memcpy(&ptRef.z, &spCube->fieldD4, sizeof(float));
                    int nWallDir = FUN_1410ba5f0(cell, ptRef);
                    void* pMem = ::operator new(sizeof(Unk_CMISAutoCube));
                    FUN_141122e70(pMem);
                    Unk_CMISAutoPtr spInfo(static_cast<CPtred*>(pMem));
                    Unk_CMISAutoCube* pInfo = Unk_CMISAuto(spInfo);
                    pInfo->m_nItemId = FUN_1408b4f20(spCube.get());
                    pInfo->m_offset = rel;
                    pInfo->m_fRotation = fRot;
                    pInfo->m_nWallDir = nWallDir;
                    Unk_CMISIter<295> itIns;
                    FUN_14111d370(&listAuto, &itIns, &spInfo);
                }
            }
        }
    }
    Unk_CMISIter<295> itAuto, itAutoEnd;
    for (FUN_14114e780(&listAuto, &itAuto); FUN_1411278c0(&itAuto, FUN_1411523f0(&listAuto, &itAutoEnd)); FUN_141129970(&itAuto)) {
        Unk_CMISAutoPtr spInfo(*FUN_141128b10(&itAuto));
        if (spInfo.get() == 0)
            continue;
        Unk_CMISXmlNode elemCube;
        FUN_14086f2f0(&elemCube, "cube");
        FUN_140873ce0(&elemCube, "itemID", Unk_CMISAuto(spInfo)->m_nItemId);
        FUN_140874050(&elemCube, "offsetCubePoint3", Unk_CMISFormatPoint(Unk_CMISAuto(spInfo)->m_offset));
        FUN_140873e30(&elemCube, "rotation", Unk_CMISAuto(spInfo)->m_fRotation);
        FUN_140873ca0(&elemCube, "wallDir", (int)(unsigned char)Unk_CMISAuto(spInfo)->m_nWallDir);
        FUN_14086e000(&elemMap, &elemCube);
        FUN_14086f450(&elemCube);
    }
    FUN_14086e000(&doc, &elemMap);
    CString strPath;
    strPath.Format("./Data/Xml/ExportedUGCMap/%s.xml", (const char*)strName);
    FUN_1408710c0(&doc, FUN_14016a5c0(strPath, 0));
    FUN_141125bb0(&setDone);
    FUN_141125c10(&listAuto);
    FUN_14086f450(&elemMap);
    return 1;
}

// ---- w142 batch 12 ----
extern Unk_CMISEntityRef DAT_143acf820;                                                     // the null entity ref
struct Unk_CMISMarkList { char m_b[0x18]; };                                                // list of the mark entities of a mark record (at +0x38 of the record)
Unk_CMISEntSetIter* FUN_14114e930(Unk_CMISMarkList*, Unk_CMISEntSetIter*);                  // begin
Unk_CMISEntSetIter* FUN_141152570(Unk_CMISMarkList*, Unk_CMISEntSetIter*);                  // end
const Unk_CMISEntityRef* FUN_141128e50(Unk_CMISEntSetIter*);                                // operator*
void FUN_14112ab20(Unk_CMISEntSetIter*);                                                    // operator++
void FUN_14114ec80(Unk_CMISTree<275>*);                                                     // clear
void FUN_14114f4a0(Unk_CMISTree<265>*);                                                     // clear
void FUN_14114f540(Unk_CMISTree<272>*);                                                     // clear
void FUN_14114f860(Unk_CMISTree<270>*);                                                     // clear
void FUN_14114f400(Unk_CMISTree<271>*);                                                     // clear
void FUN_14114f5e0(Unk_CMISTree<276>*);                                                     // clear
void FUN_14114edc0(Unk_CMISTree<278>*);                                                     // clear
void FUN_14114f7c0(Unk_CMISTree<263>*);                                                     // clear
void FUN_14114f900(Unk_CMISTree<257>*);                                                     // clear
void FUN_14114f9a0(Unk_CMISTree<258>*);                                                     // clear
void FUN_14114ee60(Unk_CMISTree<264>*);                                                     // clear
void FUN_14114fe00(Unk_CMISTree<269>*);                                                     // clear
void FUN_14114ef00(Unk_CMISTree<266>*);                                                     // clear
void FUN_14114fea0(Unk_CMISTree<267>*);                                                     // clear
void FUN_14114ebe0(Unk_CMISTree<285>*);                                                     // clear
void FUN_14114f040(Unk_CMISTree<279>*);                                                     // clear
void FUN_14114f180(Unk_CMISTree<273>*);                                                     // clear
void FUN_14114efa0(Unk_CMISTree<274>*);                                                     // clear
void FUN_141150120(Unk_CMISTree<284>*);                                                     // clear
void FUN_1403416e0(Unk_CMISTree<286>*);                                                     // clear
void FUN_14114f220(Unk_CMISTree<283>*);                                                     // clear
void FUN_1408ac410(Unk_CubeOwners*);                                                        // clear
void FUN_140b68e90(Unk_CMISFlags3*);                                                        // reset
void FUN_14112f280(ATL::CAtlArray<Unk_CMISElem388*>*);                                      // RemoveAll
void FUN_14112f260(ATL::CAtlArray<Unk_CMISElem3a8*>*);                                      // RemoveAll
struct Unk_CMISActorEntry { Unk_CMISEntityRef m_key; void* m_pActor; };                     // node value of f48
Unk_CMISIter<257>* FUN_14114e320(Unk_CMISTree<257>*, Unk_CMISIter<257>*);                   // begin
Unk_CMISActorEntry* FUN_141128740(Unk_CMISIter<257>*);                                      // operator*
void FUN_141129c70(Unk_CMISIter<257>*);                                                     // operator++
struct Unk_CMISEffEntry { int m_key; int m_nEffect; };                                      // node value of f338
Unk_CMISIter<285>* FUN_14114d9f0(Unk_CMISTree<285>*, Unk_CMISIter<285>*);                   // begin
Unk_CMISEffEntry* FUN_14063ed80(Unk_CMISIter<285>*);                                        // operator*
void FUN_141129a00(Unk_CMISIter<285>*);                                                     // operator++
struct Unk_CMISSetEffNode { int m_key; int m_pad; MS2Ptr<Unk_CMISSetEffect> m_second; };    // node value of f348
Unk_CMISIter<279>* FUN_14114dd00(Unk_CMISTree<279>*, Unk_CMISIter<279>*);                   // begin
Unk_CMISSetEffNode* FUN_1411285c0(Unk_CMISIter<279>*);                                      // operator*
void FUN_141129ae0(Unk_CMISIter<279>*);                                                     // operator++
// @0x1410d0310
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410d0310()
{
    Unk_CMISIter<265> itDefer;
    for (FUN_14114e010(&f2c8, &itDefer); ; FUN_141129bd0(&itDefer)) {
        Unk_CMISIter<265> itDeferEnd;
        if (!FUN_141127640(&itDefer, FUN_141151d30(&f2c8, &itDeferEnd)))
            break;
        FUN_1410c5340(Unk_CMISEntityRef(FUN_1411286a0(&itDefer)->m_ref));
    }
    FUN_14114f4a0(&f2c8);
    Unk_CMISIter<275> itMark;
    for (FUN_14114da60(&f288, &itMark); ; FUN_141129a20(&itMark)) {
        Unk_CMISIter<275> itMarkEnd;
        if (!FUN_141127300(&itMark, FUN_141151850(&f288, &itMarkEnd)))
            break;
        Unk_CMISMarkList* pMarks = reinterpret_cast<Unk_CMISMarkList*>(FUN_141128500(&itMark)->m_rec.m_b + 0x38);
        Unk_CMISEntSetIter itTmp, itEnt, itEntEnd;
        itEntEnd = *FUN_141152570(pMarks, &itTmp);
        itEnt = *FUN_14114e930(pMarks, &itTmp);
        while (FUN_141127980(&itEnt, &itEntEnd)) {
            {   egf::EntityPtr spEnt = FUN_1408a7ed0(FUN_141128e50(&itEnt));   // dtor 0x1408a8720 once, at the block end
                static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411cf570(FUN_1408a9090(&spEnt));
            }
            FUN_14112ab20(&itEnt);
        }
    }
    FUN_14114ec80(&f288);
    FUN_140899bd0(&f2d8, DAT_143acf820);
    FUN_14114f540(&f1f8);
    FUN_14114f860(&f1a0);
    f1e0 = 1;
    f1b0 = 0;
    f1b4 = 0;
    f1b8 = 0;
    f1c0 = 0;
    s1c8 = L"";
    s1d0 = L"";
    f1d8 = 0;
    f1dc = 0;
    f208 = Unk_PayloadPtr<Unk_CMISObj208>(0);
    f218 = Unk_UGCMapPtr(0);
    f2f0 = 0;
    f2f4 = 0;
    f478 = 0;
    f2f8 = 0;
    f2fc = 0;
    p300 = Unk_CubePoint();
    p30c = Unk_CubePoint();
    FUN_140b68e90(&f418);
    f330 = 0;
    f3d8 = 0x12;
    f3dc = false;
    t3e0.FUN_1408687f0();
    for (int i = 0; i < 9; i++)
        *FUN_1411282d0(&f368, &i) = 0;
    for (int i = 0; i < 9; i++)
        *FUN_141128250(&f378, &i) = 0;
    FUN_14112f280(&a388);
    FUN_14112f260(&a3a8);
    FUN_14114fae0(&f3c8);
    FUN_14114f400(&f1e8);
    FUN_14114f5e0(&f298);
    FUN_14114edc0(&f2b8);
    FUN_14114f7c0(&fe8);
    FUN_1410c6070();
    for (int i = 0; i < 3; i++)
        FUN_1410c6820(i);
    Unk_CMISIter<257> itActor;
    for (FUN_14114e320(&f48, &itActor); ; FUN_141129c70(&itActor)) {
        Unk_CMISIter<257> itActorEnd;
        if (!FUN_141127780(&itActor, FUN_141152030(&f48, &itActorEnd)))
            break;
        void* pActor = FUN_141128740(&itActor)->m_pActor;
        if (pActor != 0) {
            Unk_CMISPhysScene* pScene = FUN_14168a1c0(FUN_1409f7ca0());
            if (pScene != 0) {
                FUN_14168a540(FUN_1409f7ca0(), 0);
                pScene->RemoveActor(pActor);
                FUN_141bc8e00(FUN_1403ed2d0());
                FUN_14168a570(FUN_1409f7ca0());
            }
        }
    }
    FUN_14114f900(&f48);
    FUN_14114f9a0(&f58);
    FUN_14112ded0();
    FUN_14112dd30();
    FUN_14114fa40(&f78);
    FUN_14114f0e0(&f88);
    FUN_14114f0e0(&f98);
    FUN_14114fa40(&fa8);
    FUN_14114f0e0(&fb8);
    FUN_1410b2760(&f2a8);
    FUN_1402237c0(&a458);
    FUN_14114f360(&fd8);
    FUN_14114f2c0(&fc8);
    FUN_14114ee60(&ff8);
    FUN_1408ac410(reinterpret_cast<Unk_CubeOwners*>(&f138));
    FUN_14114fe00(&f148);
    FUN_14114f4a0(&f108);
    FUN_14114ef00(&f118);
    FUN_14114fea0(&f128);
    FUN_14114f4a0(&f2e0);
    Unk_CMISIter<285> itEff;
    for (FUN_14114d9f0(&f338, &itEff); ; FUN_141129a00(&itEff)) {
        Unk_CMISIter<285> itEffEnd;
        if (!FUN_14063ec30(&itEff, FUN_1411517f0(&f338, &itEffEnd)))
            break;
        int nEffect = FUN_14063ed80(&itEff)->m_nEffect;
        if (nEffect != 0)
            FUN_1403ed280()->FUN_1411a6060(nEffect);
    }
    FUN_14114ebe0(&f338);
    Unk_CMISIter<279> itSet;
    for (FUN_14114dd00(&f348, &itSet); ; FUN_141129ae0(&itSet)) {
        Unk_CMISIter<279> itSetEnd;
        if (!FUN_141127480(&itSet, FUN_141151a90(&f348, &itSetEnd)))
            break;
        MS2Ptr<Unk_CMISSetEffect> spEff(FUN_1411285c0(&itSet)->m_second);
        if (spEff->m_nEffect != 0)
            FUN_1403ed280()->FUN_1411a6060(spEff->m_nEffect);
    }
    FUN_14114f040(&f348);
    FUN_14114f860(&f358);
    Unk_CMISIter<273> itHead;
    for (FUN_14114dde0(&f228, &itHead); ; FUN_141129b70(&itHead)) {
        Unk_CMISIter<273> itHeadEnd;
        if (!FUN_141127500(&itHead, FUN_141151b50(&f228, &itHeadEnd)))
            break;
        FUN_141906680(FUN_1411284c0(&FUN_141128600(&itHead)->second));
    }
    FUN_14114f180(&f228);
    if (Unk_CMISHouseMark* pHouse = FUN_1410dc020())
        pHouse->vfunc_3();    // MS2: slot 3
    FUN_14114efa0(&f238);
    f480 = Unk_PayloadPtr<Unk_CMISObj480>(0);
    FUN_141150120(&f498);
    f420 = 0;
    f428 = 0;
    FUN_1403416e0(&f430);
    FUN_14114f220(&f440);
}

// ---- w142 batch 13 ----
struct Unk_CMISXformVec                                                                     // vector<NiTransform> (0x18 bytes)
{
    Unk_CMISXformVec();                                                                     // 0x141122df0
    ~Unk_CMISXformVec();                                                                    // 0x141125da0
    unsigned __int64 FUN_14115af10();                                                       // size
    NiTransform* FUN_141128390(unsigned __int64 nIndex);                                    // operator[]
    void* m_a; void* m_b; void* m_c;
};
bool FUN_140965550(const Unk_CMISEntityRef*, const Unk_CMISEntityRef*);                     // operator!=
void FUN_1413d5220(HardwareInstancingService*, Unk_CMISEntityRef);                          // drop the effect entity
Unk_CMISEntityRef* FUN_1413d49f0(HardwareInstancingService*, Unk_CMISEntityRef* pOut, Unk_CMISStr* pName, efd::AssetID* pAsset,
    bool bInstanced, NiTransform* pXforms, int nCount, int nCapacity);                      // create an instanced effect entity
void FUN_140de0cb0(efd::AssetID* pAsset, Unk_CMISStr* pUrn);                                // set the urn
void FUN_14111d240(Unk_CMISIntList*, Unk_CMISInsRes*, const int*);                          // insert
unsigned* FUN_14038e780(void* pTmp);                                                        // the default alloc alignment
void* FUN_14206ac20(unsigned __int64 nSize, unsigned nAlign);                               // aligned alloc
// @0x1410cc160
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410cc160(int nKind)
{
    if (nKind == 0) {
        if (FUN_140965550(&f2d8, &DAT_143acf820)) {
            Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
            FUN_1413d5220(spInst.FUN_14098d0e0(), Unk_CMISEntityRef(f2d8));
            FUN_140899bd0(&f2d8, DAT_143acf820);
        }
        return;
    }
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    Unk_CMISXformVec vecXform;
    Unk_CMISIter<262> itGroup, itGroupEnd;
    for (FUN_14114df30(&fd8, &itGroup); FUN_1411275c0(&itGroup, FUN_141151c70(&fd8, &itGroupEnd)); FUN_141129bb0(&itGroup)) {
        int nGroup = *FUN_141128660(&itGroup);
        if (nGroup == 0)
            continue;
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (FUN_1408a8dd0(&spOwner, 0))
            continue;
        int nFlag = 0;
        if (FUN_1408a0890(FUN_1403ed2d0()->FUN_141bd3060(), nGroup, &nFlag) == 0)
            continue;
        if (nFlag != 0)
            continue;
        if (spOwner->ownerID != FUN_141656ad0(pRoster) && !FUN_140930c90(spOwner->ownerID) && !FUN_140930d20(spOwner->ownerID))
            continue;
        FUN_1410ccc00(nGroup, 0, 0);
        Unk_CMISIntList setSeen;
        Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
        Unk_CMISListIter it;
        Unk_CMISListEnd itListEnd;
        for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
            Unk_Int3 cell = FUN_1408a0400(*FUN_1403e8d70(&it));
            Cube* pCube = FUN_1410b8980(cell);
            if (pCube == 0)
                continue;
            if (FUN_140375130(FUN_140885340(&f208)) && !(p300.x <= cell.x && p300.y <= cell.y && p300.z <= cell.z))
                continue;
            int nCellKey = FUN_1408a03c0(pCube->position);
            Unk_CMISListIter itFind;
            Unk_CMISListEnd itSeenEnd;
            if (FUN_14035ea60(FUN_141158620(&setSeen, &itFind, &nCellKey), FUN_1411522d0(&setSeen, &itSeenEnd)))
                continue;
            int nCellKey2 = FUN_1408a03c0(pCube->position);
            Unk_CMISInsRes resIns;
            FUN_14111d240(&setSeen, &resIns, &nCellKey2);
            Unk_StreamPoint ptGuide;
            FUN_1402bd040(&ptGuide);
            FUN_1408a15b0(pCube->position, ptGuide);
            Unk_CMISPt3 ptWalk(ptGuide);
            Unk_Int3 cellX = pCube->position;
            cellX.x = cellX.x + 1;
            if (FUN_1410cba80(pCube->field44, nGroup, &cellX, &ptWalk) != 0)
                FUN_1410cbb40(&vecXform, 0, nGroup, Unk_StreamPoint(ptWalk.x, ptWalk.y, ptWalk.z), cellX, true, 0);
            ptWalk = Unk_CMISPt3(ptGuide);
            Unk_Int3 cellY = pCube->position;
            cellY.y = cellY.y + 1;
            if (FUN_1410cba80(pCube->field44, nGroup, &cellY, &ptWalk) != 0)
                FUN_1410cbb40(&vecXform, 0, nGroup, Unk_StreamPoint(ptWalk.x, ptWalk.y, ptWalk.z), cellY, false, 0);
            Unk_StreamPoint ptRot(90.0f, 0.0f, 0.0f);
            if (pCube->field44 != 2)
                ptGuide.z = ptGuide.z + 150.0f;
            NiTransform xform;
            xform.MakeIdentity();
            xform.m_Translate = NiPoint3(ptGuide.x, ptGuide.y, ptGuide.z);
            xform.m_Rotate.FromEulerAnglesXYZ((-ptRot.x * 3.1415927f) / 180.0f, (-ptRot.y * 3.1415927f) / 180.0f, (-ptRot.z * 3.1415927f) / 180.0f);
            FUN_14115a9c0(&vecXform, &xform);
        }
    }
    efd::AssetID asset;
    Unk_CMISStr strUrn;
    FUN_1409989e0(&strUrn, "urn:gamebryo-scenegraph:Eff_Build_GuideLine_01");
    FUN_140de0cb0(&asset, &strUrn);
    FUN_1408a8900(&strUrn);
    char tmpAlign[8];
    unsigned nAlign = *FUN_14038e780(tmpAlign);
    NiTransform* pXforms = static_cast<NiTransform*>(FUN_14206ac20(vecXform.FUN_14115af10() * sizeof(NiTransform), nAlign));
    for (unsigned __int64 i = 0; i < vecXform.FUN_14115af10(); i++)
        new (pXforms + i) NiTransform(*vecXform.FUN_141128390(i));
    Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
    Unk_CMISStr strProp;
    FUN_1409989e0(&strProp, "MS2PhysXProp");
    Unk_CMISEntityRef idNew(DAT_143acf820);
    FUN_1413d49f0(spInst.FUN_14098d0e0(), &idNew, &strProp, &asset, false, pXforms, (int)vecXform.FUN_14115af10(), (int)vecXform.FUN_14115af10());
    FUN_140899bd0(&f2d8, idNew);
    FUN_1408a8900(&strProp);
}

// ---- w142 batch 14 ----
bool FUN_1411270d0(Unk_CMISIter<259>*, Unk_CMISIter<259>*);                                 // operator==
Unk_CMISIter<256>* FUN_1411589a0(Unk_CMISTree<256>*, Unk_CMISIter<256>*, const Unk_CMISEntityRef*);   // find
void FUN_141156cf0(Unk_CMISTree<256>*, Unk_CMISIter<256>*, Unk_CMISIter<256>);              // erase
__int64 FUN_1409657f0(Unk_CMISNpcRef*);                                                     // operator bool
void FUN_141852050(NiAVObject*, int);
// @0x1410cf5c0
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410cf5c0(egf::Entity* pEntity)
{
    Unk_CMISIter<259> itFind, itEnd;
    FUN_1411581c0(&f78, &itFind, FUN_1408b76f0(pEntity));
    if (!FUN_1411270d0(&itFind, FUN_1411520f0(&f78, &itEnd))) {
        MS2Ptr<Cube> spCube(FUN_141128780(&itFind)->second);
        Unk_CMISIter<259> itErased;
        FUN_14111c730(&f78, &itErased, itFind);
        Unk_CMISIter<256> itPending, itPendingEnd;
        FUN_1411589a0(&f68, &itPending, FUN_1408b76f0(pEntity));
        if (!FUN_140a16b10(&itPending, FUN_1411524b0(&f68, &itPendingEnd))) {
            int nKey = FUN_1408a03c0(spCube->position);
            Unk_CMISIter<265> itMagic, itMagicEnd;
            if (FUN_141127640(FUN_141157ac0(&f2e0, &itMagic, &nKey), FUN_141151d30(&f2e0, &itMagicEnd))) {
                egf::EntityPtr spCur(reinterpret_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411cf440(*reinterpret_cast<const egf::EntityID*>(FUN_141127ed0(&f2e0, &nKey))));
                if (FUN_1408a9280(&spCur) != 0) {
                    Unk_CMISIter<256> itIns;
                    FUN_14111d3f0(&f30, &itIns, FUN_1408b76f0(pEntity));
                    FUN_140964eb0(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity), &spCur);
                }
            }
            Unk_CMISListIter itFindSet;
            Unk_CMISListEnd itEndSet;
            if (FUN_14035ea60(FUN_141158620(&f128, &itFindSet, &nKey), FUN_1411522d0(reinterpret_cast<Unk_CMISIntList*>(&f128), &itEndSet))) {
                Unk_CMISIter<266> itBlock, itBlockEnd;
                if (FUN_141127400(FUN_1411572e0(&f118, &itBlock, &nKey), FUN_1411519d0(&f118, &itBlockEnd))) {
                    Unk_CMISBlock rec(*FUN_141127c10(&f118, &nKey));
                    egf::EntityPtr spNew = FUN_1410bc3d0(Unk_CMISBlock(rec));
                    egf::EntityPtr spOld = FUN_1408a7ed0(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity));
                    FUN_140964eb0(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity), &spNew);
                    Unk_CMISIter<256> itIns;
                    FUN_14111d3f0(&f30, &itIns, FUN_1408b76f0(FUN_1408a9280(&spOld)));
                    FUN_141156520(&f128, &nKey);
                    FUN_141153740(&f118, &nKey);
                }
            }
            FUN_1410d0e30(FUN_1408a9090(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)), spCube);
            FUN_1410c06b0(spCube);
            FUN_1410c2ce0(FUN_1408a9090(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)));
            if (spCube->fieldB0 != 0) {
                if (FUN_1408a9bd0(FUN_1408a9280(&spCube->entity))->FUN_14211e240(0x48ccc02d)) {
                    efd::utf8string strOn("On");
                    FUN_1409a1fc0(FUN_141b6f910(), FUN_1408b76f0(FUN_1408a9280(&spCube->entity)), &strOn, 1.0f, 0);
                } else {
                    NiAVObject* pRoot = FUN_141b6efc0(FUN_1408a9090(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)));
                    if (pRoot != 0)
                        FUN_141852050(pRoot, 0);
                }
            }
            if (spCube->field4c == 0) {
                if (spCube->fieldB4 != 0)
                    FUN_1410d0000(FUN_1408a9090(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)), spCube);
            } else {
                CString strKey;
                strKey.Format("%d_%d", spCube->field44, FUN_1408a03c0(spCube->position));
                Unk_CMISNpcRef spNpc(static_cast<Unk_CMISNpcElem*>(0));
                FUN_1403ed2d0()->FUN_141bc5a20(&spNpc, strKey);
                if (FUN_1409657f0(&spNpc) != 0)
                    FUN_140965930(&spNpc)->FUN_141447410(FUN_1408a9090(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)));
            }
            FUN_1410be6e0(spCube);
            if (!FUN_1410cb900() && FUN_14115ad10(&f78) == 0) {
                FUN_1410cb8b0(true);
                COutPacket packet(0x10, 0);
                packet.vfunc_o10_3(FUN_1403ed2d0()->FUN_141bd98d0());
                FUN_140710590(packet);
                FUN_1403ed2d0()->FUN_141bdb690();
            }
            if (FUN_1410cb900())
                FUN_1410bf470();
            FUN_1410ce020(spCube);
        } else {
            Unk_CMISIter<256> itIns;
            FUN_14111d3f0(&f30, &itIns, FUN_1408b76f0(pEntity));
            Unk_CMISIter<256> itErasedPending;
            FUN_141156cf0(&f68, &itErasedPending, itPending);
        }
        if (f478 != 0 && FUN_141151760(&f78)) {
            COutPacket packet(0x37, 0);
            packet.vfunc_o10_1(0x44);
            packet.vfunc_o10_4(f478);
            FUN_140710590(packet);
            f478 = 0;
        }
    }
}

// ---- w142 batch 15 ----
bool* FUN_141127f50(Unk_CMISTree<276>*, const int*);                                        // operator[]
// @0x1410cd440
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410cd440()
{
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    FUN_14114f5e0(&f298);
    Unk_CMISIter<262> itGroup, itGroupEnd;
    for (FUN_14114df30(&fd8, &itGroup); FUN_1411275c0(&itGroup, FUN_141151c70(&fd8, &itGroupEnd)); FUN_141129bb0(&itGroup)) {
        int nGroup = *FUN_141128660(&itGroup);
        if (nGroup == 0)
            continue;
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (FUN_1408a8dd0(&spOwner, 0))
            continue;
        int nFlag = 0;
        if (FUN_1408a0890(FUN_1403ed2d0()->FUN_141bd3060(), nGroup, &nFlag) == 0)
            continue;
        if (nFlag != 0)
            continue;
        if (spOwner->ownerID != FUN_141656ad0(pRoster) && !FUN_140930c90(spOwner->ownerID) && !FUN_140930d20(spOwner->ownerID))
            continue;
        Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
        Unk_CMISListIter it;
        Unk_CMISListEnd itListEnd;
        for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
            Unk_Int3 cell = FUN_1408a0400(*FUN_1403e8d70(&it));
            Cube* pCube = FUN_1410b8980(cell);
            if (pCube == 0)
                continue;
            if (FUN_140375130(FUN_140885340(&f208)) && !(p300.x <= cell.x && p300.y <= cell.y && p300.z <= cell.z))
                continue;
            Unk_Int3 base = pCube->position;
            if (pCube->field44 != 1)
                base.z = base.z - 1;
            int nHeight = 0;
            if (!FUN_140375130(FUN_140885340(&f208))) {
                if (f218 != 0) {
                    std::map<int, Unk_UGCGroup>::iterator itFound = f218->groups.find(nGroup);
                    if (itFound != f218->groups.end())
                        nHeight = itFound->second.heightLimit;
                }
            } else {
                nHeight = f2fc;
            }
            static const int s_aOffsets[9][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1} };
            for (int dz = -1; dz < nHeight + 2; dz++) {
                for (int i = 0; i < 9; i++) {
                    Unk_Int3 pt = base;
                    pt.z = pt.z + dz;
                    pt.x = pt.x + s_aOffsets[i][0];
                    pt.y = pt.y + s_aOffsets[i][1];
                    int nKey = FUN_1408a03c0(pt);
                    *FUN_141127f50(&f298, &nKey) = true;
                }
            }
        }
    }
}

// ---- w142 batch 16 ----
struct Unk_CMISCorner { int m_nDiag, m_nSideB, m_nSideC, m_nRetB, m_nRetC, m_nDirB, m_nDirC; };    // neighbours of a diagonal walk direction
// @0x1410d1820
// MS2-FUNCTIONAL: exe's switch is compiled to a jump table with per-case temporaries
int CubeMapInformationService::FUN_1410d1820(void* pArg, int nDir, Unk_StreamPoint pt, Unk_StreamPoint ptCur, void** ppFound)
{
    Cube* pBase = static_cast<Cube*>(pArg);
    static const Unk_CMISCorner s_aCorners[4] = {
        { 0x1ff, 0xff, 0x100, 3, 7, 8, 2 },
        { 0x101, 1, 0x100, 1, 5, 4, 2 },
        { 0xff01, 1, 0xff00, 7, 3, 4, 6 },
        { 0xffff, 0xff, 0xff00, 5, 1, 8, 6 },
    };
    *ppFound = 0;
    float fDx = FUN_14029d220(pt.x - ptCur.x);
    float fDy = FUN_14029d220(pt.y - ptCur.y);
    switch (nDir) {
    case 2:
        if (FUN_1410b9080(pBase, 0x100) != 0)
            nDir = 0;
        break;
    case 4:
        if (FUN_1410b9080(pBase, 1) != 0)
            nDir = 0;
        break;
    case 6:
        if (FUN_1410b9080(pBase, 0xff00) != 0)
            nDir = 0;
        break;
    case 8:
        if (FUN_1410b9080(pBase, 0xff) != 0)
            nDir = 0;
        break;
    case 1:
    case 3:
    case 5:
    case 7: {
        const Unk_CMISCorner& c = s_aCorners[nDir / 2];
        Cube* pDiag = FUN_1410b9080(pBase, c.m_nDiag);
        Cube* pSideB = FUN_1410b9080(pBase, c.m_nSideB);
        bool bNoB = pSideB == 0;
        Cube* pSideC = FUN_1410b9080(pBase, c.m_nSideC);
        bool bNoC = pSideC == 0;
        int nMissing = (pDiag == 0) + bNoB + bNoC;
        if (nMissing == 0) {
            nDir = 0;
            break;
        }
        if (nMissing == 1) {
            if (pDiag != 0) {
                if (!bNoB) {
                    *ppFound = pSideB;
                    return c.m_nRetB;
                }
                if (!bNoC) {
                    *ppFound = pSideC;
                    return c.m_nRetC;
                }
            }
        } else if (nMissing != 2) {
            return nDir;
        }
        if (fDx <= fDy) {
            if (bNoC)
                nDir = c.m_nDirC;
            else if (bNoB)
                nDir = c.m_nDirB;
        } else if (bNoB) {
            nDir = c.m_nDirB;
        } else if (bNoC) {
            nDir = c.m_nDirC;
        }
        break;
    }
    }
    return nDir;
}

// ---- w142 batch 17 ----
void FUN_141150260(Unk_CMISMarkList*);                                                      // clear
void FUN_141152fe0(Unk_CMISTree<275>*, const int*);                                         // erase
// @0x1410ccc00
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently
void CubeMapInformationService::FUN_1410ccc00(int nGroup, int nA, int nB)
{
    Unk_CMISIter<275> itMark, itMarkEnd;
    if (nA == 0) {
        if (!FUN_141126bd0(FUN_141156e80(&f288, &itMark, &nGroup), FUN_141151850(&f288, &itMarkEnd))) {
            Unk_CMISMarkRec* pRec = FUN_141127a90(&f288, &nGroup);
            Unk_CMISMarkList* pMarks = reinterpret_cast<Unk_CMISMarkList*>(pRec->m_b + 0x38);
            Unk_CMISEntSetIter itTmp, itEnt, itEntEnd;
            itEntEnd = *FUN_141152570(pMarks, &itTmp);
            itEnt = *FUN_14114e930(pMarks, &itTmp);
            while (FUN_141127980(&itEnt, &itEntEnd)) {
                {   egf::EntityPtr spEnt = FUN_1408a7ed0(FUN_141128e50(&itEnt));   // dtor 0x1408a8720 once, at the block end
                    static_cast<Unk_CMISWorldMgr*>(FUN_1409670f0())->FUN_1411cf570(FUN_1408a9090(&spEnt));
                }
                FUN_14112ab20(&itEnt);
            }
            FUN_141150260(pMarks);
            FUN_141152fe0(&f288, &nGroup);
        }
        return;
    }
    if (FUN_141127300(FUN_141156e80(&f288, &itMark, &nGroup), FUN_141151850(&f288, &itMarkEnd)) != 0)
        return;
    Unk_CMISXformVec vecXform;
    Unk_CMISIntList setSeen;
    Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
    Unk_CMISListIter it;
    Unk_CMISListEnd itListEnd;
    for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
        Unk_Int3 cell = FUN_1408a0400(*FUN_1403e8d70(&it));
        Cube* pCube = FUN_1410b8980(cell);
        if (pCube == 0)
            continue;
        int nCellKey = FUN_1408a03c0(pCube->position);
        Unk_CMISListIter itFind;
        Unk_CMISListEnd itSeenEnd;
        if (FUN_14035ea60(FUN_141158620(&setSeen, &itFind, &nCellKey), FUN_1411522d0(&setSeen, &itSeenEnd)))
            continue;
        int nCellKey2 = FUN_1408a03c0(pCube->position);
        Unk_CMISInsRes resIns;
        FUN_14111d240(&setSeen, &resIns, &nCellKey2);
        Unk_StreamPoint ptGuide;
        FUN_1402bd040(&ptGuide);
        FUN_1408a15b0(pCube->position, ptGuide);
        static const int s_aSides[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (int i = 0; i < 4; i++) {
            Unk_CMISPt3 ptWalk(ptGuide);
            Unk_Int3 cellSide = pCube->position;
            cellSide.x = cellSide.x + s_aSides[i][0];
            cellSide.y = cellSide.y + s_aSides[i][1];
            if (FUN_1410cba80(pCube->field44, nGroup, &cellSide, &ptWalk) != 0)
                FUN_1410cbb40(&vecXform, 1, nGroup, Unk_StreamPoint(ptWalk.x, ptWalk.y, ptWalk.z), cellSide, i < 2, nB);
        }
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cac180-0x142cac290 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x1410b7680, CubeMapInformationService, GetDisplayName, 13, 0x2FB6DCC0);
MS2_REPLACE_METHOD(0x1410b76a0, CubeMapInformationService, FUN_1410b76a0, 39, 0x648AA90F);
MS2_REPLACE_METHOD(0x1410b76d0, CubeMapInformationService, FUN_1410b76d0, 265, 0xF4081F84);
MS2_REPLACE_METHOD(0x1410b7d50, CubeMapInformationService, FUN_1410b7d50, 59, 0x07985FD2);
MS2_REPLACE_METHOD(0x1410b7ed0, CubeMapInformationService, FUN_1410b7ed0, 186, 0xAC1530CD);
MS2_REPLACE_METHOD(0x1410b85f0, CubeMapInformationService, FUN_1410b85f0, 395, 0xB3929125);
MS2_REPLACE_METHOD(0x1410b8b00, CubeMapInformationService, FUN_1410b8b00, 216, 0xCBC48B0D);
MS2_REPLACE_METHOD(0x1410b8be0, CubeMapInformationService, FUN_1410b8be0, 156, 0xB429EB82);
MS2_REPLACE_METHOD(0x1410b8c90, CubeMapInformationService, FUN_1410b8c90, 246, 0x10AD86AF);
MS2_REPLACE_METHOD(0x1410b8d90, CubeMapInformationService, FUN_1410b8d90, 196, 0x55FF5994);
MS2_REPLACE_METHOD(0x1410b9080, CubeMapInformationService, FUN_1410b9080, 185, 0x677D3CED);
MS2_REPLACE_METHOD(0x1410b8e60, CubeMapInformationService, FUN_1410b8e60, 196, 0x3F8F57AF);
MS2_REPLACE_METHOD(0x1410b9850, CubeMapInformationService, FUN_1410b9850, 236, 0xADA8963A);
MS2_REPLACE_METHOD(0x1410b9950, CubeMapInformationService, FUN_1410b9950, 235, 0xC5339393);
MS2_REPLACE_METHOD(0x1410b9a50, CubeMapInformationService, FUN_1410b9a50, 196, 0x95408E66);
MS2_REPLACE_METHOD(0x1410b9b20, CubeMapInformationService, FUN_1410b9b20, 239, 0x9BF4E278);
MS2_REPLACE_METHOD(0x1410b9d80, CubeMapInformationService, FUN_1410b9d80, 230, 0x9186AEEE);
MS2_REPLACE_METHOD(0x1410b9e70, CubeMapInformationService, FUN_1410b9e70, 17, 0xF99D8EA5);
MS2_REPLACE_METHOD(0x1410b9c20, CubeMapInformationService, FUN_1410b9c20, 332, 0x3020E9D3);
MS2_REPLACE_METHOD(0x1410ba440, CubeMapInformationService, FUN_1410ba440, 89, 0x086CED8D);
MS2_REPLACE_METHOD(0x1410bba60, CubeMapInformationService, FUN_1410bba60, 74, 0xA664D743);
MS2_REPLACE_METHOD(0x1410bbab0, CubeMapInformationService, FUN_1410bbab0, 319, 0x2A5ADFAB);
MS2_REPLACE_METHOD(0x1410bbc00, CubeMapInformationService, FUN_1410bbc00, 187, 0x2F873811);
MS2_REPLACE_METHOD(0x1410bc1c0, CubeMapInformationService, FUN_1410bc1c0, 341, 0xA1F224F9);
MS2_REPLACE_METHOD(0x1410bc320, CubeMapInformationService, FUN_1410bc320, 167, 0x50877F16);
MS2_REPLACE_METHOD(0x1410bf250, CubeMapInformationService, FUN_1410bf250, 200, 0x61F0F4F0);
MS2_REPLACE_METHOD(0x1410bf320, CubeMapInformationService, FUN_1410bf320, 175, 0xD2D50267);
MS2_REPLACE_METHOD(0x1410bf3e0, CubeMapInformationService, FUN_1410bf3e0, 136, 0x318E7974);
MS2_REPLACE_METHOD(0x1410c3e00, CubeMapInformationService, FUN_1410c3e00, 45, 0x58BA7039);
MS2_REPLACE_METHOD(0x1410c3e40, CubeMapInformationService, FUN_1410c3e40, 54, 0x7EC14B0A);
MS2_REPLACE_METHOD(0x1410c3e80, CubeMapInformationService, FUN_1410c3e80, 127, 0x18215EAB);
MS2_REPLACE_METHOD(0x1410c3f10, CubeMapInformationService, FUN_1410c3f10, 53, 0x2A46211D);
MS2_REPLACE_METHOD(0x1410c3f50, CubeMapInformationService, FUN_1410c3f50, 62, 0xA11B4F73);
MS2_REPLACE_METHOD(0x1410c3fa0, CubeMapInformationService, FUN_1410c3fa0, 17, 0x404A6EDE);
MS2_REPLACE_METHOD(0x1410c2fe0, CubeMapInformationService, FUN_1410c2fe0, 11, 0x02239C70);
MS2_REPLACE_METHOD(0x1410cb900, CubeMapInformationService, FUN_1410cb900, 18, 0xA0847883);
MS2_REPLACE_METHOD(0x1410ce7e0, CubeMapInformationService, FUN_1410ce7e0, 17, 0x8068262B);
MS2_REPLACE_METHOD(0x1410cef40, CubeMapInformationService, OnShutdown, 29, 0xE1D7D38E);
MS2_REPLACE_METHOD(0x1410cf130, CubeMapInformationService, FUN_1410cf130, 34, 0xC49A39F0);
MS2_REPLACE_METHOD(0x1410d3360, CubeMapInformationService, FUN_1410d3360, 17, 0x5150E482);
MS2_REPLACE_METHOD(0x1410d3380, CubeMapInformationService, FUN_1410d3380, 17, 0x3A7EB6D2);
MS2_REPLACE_METHOD(0x1410d4660, CubeMapInformationService, FUN_1410d4660, 17, 0x18B129A4);
MS2_REPLACE_METHOD(0x1410d4920, CubeMapInformationService, FUN_1410d4920, 17, 0xC3C8FAC4);
MS2_REPLACE_METHOD(0x1410d5530, CubeMapInformationService, FUN_1410d5530, 18, 0xC14493FE);
MS2_REPLACE_METHOD(0x1410d5700, CubeMapInformationService, FUN_1410d5700, 28, 0x356A1923);
MS2_REPLACE_METHOD(0x1410d5730, CubeMapInformationService, FUN_1410d5730, 18, 0xC60F1F35);
MS2_REPLACE_METHOD(0x1410d5750, CubeMapInformationService, FUN_1410d5750, 28, 0x6AA5EA3B);
MS2_REPLACE_METHOD(0x1410d5780, CubeMapInformationService, FUN_1410d5780, 18, 0x90D6741D);
MS2_REPLACE_METHOD(0x1410d5ab0, CubeMapInformationService, FUN_1410d5ab0, 33, 0xA21D86D2);
MS2_REPLACE_METHOD(0x1410d5ae0, CubeMapInformationService, FUN_1410d5ae0, 25, 0x763309C3);
MS2_REPLACE_METHOD(0x1410d5b00, CubeMapInformationService, FUN_1410d5b00, 17, 0x3138EB3F);
MS2_REPLACE_METHOD(0x1410cb8b0, CubeMapInformationService, FUN_1410cb8b0, 66, 0xE066738E);
MS2_REPLACE_METHOD(0x1410cb920, CubeMapInformationService, FUN_1410cb920, 85, 0x297258A7);
MS2_REPLACE_METHOD(0x1410d2ee0, CubeMapInformationService, FUN_1410d2ee0, 36, 0x5AC7A644);
MS2_REPLACE_METHOD(0x1410d2f10, CubeMapInformationService, FUN_1410d2f10, 37, 0xE46D8CAC);
MS2_REPLACE_METHOD(0x1410d2f40, CubeMapInformationService, FUN_1410d2f40, 106, 0x5364A2D9);
MS2_REPLACE_METHOD(0x1410d54f0, CubeMapInformationService, FUN_1410d54f0, 55, 0x13AFFF7A);
MS2_REPLACE_METHOD(0x1410d5550, CubeMapInformationService, FUN_1410d5550, 116, 0x1BB93540);
MS2_REPLACE_METHOD(0x1410d55d0, CubeMapInformationService, FUN_1410d55d0, 99, 0x4DF08151);
MS2_REPLACE_METHOD(0x1410d5640, CubeMapInformationService, FUN_1410d5640, 78, 0x35A2C1CC);
MS2_REPLACE_METHOD(0x1410d56a0, CubeMapInformationService, FUN_1410d56a0, 78, 0x9102DA93);
MS2_REPLACE_METHOD(0x1410d57a0, CubeMapInformationService, FUN_1410d57a0, 129, 0x2C79A85D);
MS2_REPLACE_METHOD(0x1410d5830, CubeMapInformationService, FUN_1410d5830, 124, 0x2A5CBAD1);
MS2_REPLACE_METHOD(0x1410d58c0, CubeMapInformationService, FUN_1410d58c0, 104, 0x60D380B4);
MS2_REPLACE_METHOD(0x1410d5930, CubeMapInformationService, FUN_1410d5930, 129, 0x378D7D4C);
MS2_REPLACE_METHOD(0x1410cb420, CubeMapInformationService, FUN_1410cb420, 144, 0x21D42334);
MS2_REPLACE_METHOD(0x1410d2730, CubeMapInformationService, FUN_1410d2730, 129, 0xC7765144);
MS2_REPLACE_METHOD(0x1410d4340, CubeMapInformationService, FUN_1410d4340, 122, 0x714CCD58);
MS2_REPLACE_METHOD(0x1410c4d80, CubeMapInformationService, FUN_1410c4d80, 147, 0xB8AE8FB4);
MS2_REPLACE_METHOD(0x1410c68e0, CubeMapInformationService, FUN_1410c68e0, 149, 0xB6BF2B95);
MS2_REPLACE_METHOD(0x1410d2340, CubeMapInformationService, FUN_1410d2340, 156, 0xEEE5AF23);
MS2_REPLACE_METHOD(0x1410caa60, CubeMapInformationService, FUN_1410caa60, 157, 0xD35299AC);
MS2_REPLACE_METHOD(0x1410c8030, CubeMapInformationService, FUN_1410c8030, 146, 0xB5FEEB28);
MS2_REPLACE_METHOD(0x1410cba80, CubeMapInformationService, FUN_1410cba80, 173, 0x93E405C5);
MS2_REPLACE_METHOD(0x1410c5280, CubeMapInformationService, FUN_1410c5280, 181, 0x3432B4D0);
MS2_REPLACE_METHOD(0x1410c6070, CubeMapInformationService, FUN_1410c6070, 131, 0xB538D479);
MS2_REPLACE_METHOD(0x1410c6820, CubeMapInformationService, FUN_1410c6820, 176, 0x44A9A5A7);
MS2_REPLACE_METHOD(0x1410c3020, CubeMapInformationService, FUN_1410c3020, 210, 0x33E82D80);
MS2_REPLACE_METHOD(0x1410ce560, CubeMapInformationService, FUN_1410ce560, 145, 0xA6305FF4);
MS2_REPLACE_METHOD(0x1410ce310, CubeMapInformationService, FUN_1410ce310, 212, 0xE2043451);
MS2_REPLACE_METHOD(0x1410d33a0, CubeMapInformationService, FUN_1410d33a0, 160, 0x039024A4);
MS2_REPLACE_METHOD(0x1410d5b20, CubeMapInformationService, FUN_1410d5b20, 153, 0xAA015FE8);
MS2_REPLACE_METHOD(0x1410ce800, CubeMapInformationService, OnPreInit, 69, 0xF3875923);
MS2_REPLACE_METHOD(0x1410ce850, CubeMapInformationService, OnInit, 68, 0xC478B401);
MS2_REPLACE_METHOD(0x1410c3000, CubeMapInformationService, FUN_1410c3000, 17, 0xF1B8F21A);
MS2_REPLACE_METHOD(0x1410c3100, CubeMapInformationService, FUN_1410c3100, 17, 0x0C547E26);
MS2_REPLACE_METHOD(0x1410c3120, CubeMapInformationService, FUN_1410c3120, 25, 0x6BCE764A);
MS2_REPLACE_METHOD(0x1410c3140, CubeMapInformationService, FUN_1410c3140, 17, 0xA6F3F9B2);
MS2_REPLACE_METHOD(0x1410c3160, CubeMapInformationService, FUN_1410c3160, 25, 0x3BA376EE);
MS2_REPLACE_METHOD(0x1410c3180, CubeMapInformationService, FUN_1410c3180, 18, 0x7817FBF0);
MS2_REPLACE_METHOD(0x1410c31a0, CubeMapInformationService, FUN_1410c31a0, 28, 0x9BD0B3F6);
MS2_REPLACE_METHOD(0x1410c3220, CubeMapInformationService, FUN_1410c3220, 44, 0x94C6B9D1);
MS2_REPLACE_METHOD(0x1410c32b0, CubeMapInformationService, FUN_1410c32b0, 44, 0xCDE1E189);
MS2_REPLACE_METHOD(0x1410c32f0, CubeMapInformationService, FUN_1410c32f0, 17, 0xA5AE1952);
MS2_REPLACE_METHOD(0x1410c3310, CubeMapInformationService, FUN_1410c3310, 25, 0x108C6F4E);
MS2_REPLACE_METHOD(0x1410c33f0, CubeMapInformationService, FUN_1410c33f0, 17, 0xAD0495CD);
MS2_REPLACE_METHOD(0x1410c3410, CubeMapInformationService, FUN_1410c3410, 25, 0x41B73909);
MS2_REPLACE_METHOD(0x1410c3430, CubeMapInformationService, FUN_1410c3430, 17, 0x47A41159);
MS2_REPLACE_METHOD(0x1410c3450, CubeMapInformationService, FUN_1410c3450, 25, 0xA71AE37D);
MS2_REPLACE_METHOD(0x1410c3470, CubeMapInformationService, FUN_1410c3470, 17, 0xE24066E5);
MS2_REPLACE_METHOD(0x1410c3490, CubeMapInformationService, FUN_1410c3490, 25, 0x76F30A21);
MS2_REPLACE_METHOD(0x1410c34b0, CubeMapInformationService, FUN_1410c34b0, 17, 0x7CDCBC71);
MS2_REPLACE_METHOD(0x1410c34d0, CubeMapInformationService, FUN_1410c34d0, 25, 0xDC538E95);
MS2_REPLACE_METHOD(0x1410c3560, CubeMapInformationService, FUN_1410c3560, 26, 0xF15554F9);
MS2_REPLACE_METHOD(0x1410c3580, CubeMapInformationService, FUN_1410c3580, 26, 0x35FC9996);
MS2_REPLACE_METHOD(0x1410c35a0, CubeMapInformationService, FUN_1410c35a0, 26, 0x7C050D3B);
MS2_REPLACE_METHOD(0x1410c35c0, CubeMapInformationService, FUN_1410c35c0, 48, 0xD6F4770B);
MS2_REPLACE_METHOD(0x1410c3600, CubeMapInformationService, FUN_1410c3600, 33, 0x9CFBA143);
MS2_REPLACE_METHOD(0x1410c3630, CubeMapInformationService, FUN_1410c3630, 25, 0x8E6F2F68);
MS2_REPLACE_METHOD(0x1410c3650, CubeMapInformationService, FUN_1410c3650, 17, 0xA1044F2C);
MS2_REPLACE_METHOD(0x1410c3330, CubeMapInformationService, FUN_1410c3330, 179, 0x36C5FE72);
MS2_REPLACE_METHOD(0x1410c79a0, CubeMapInformationService, FUN_1410c79a0, 162, 0xA36F599E);
MS2_REPLACE_METHOD(0x1410c7c20, CubeMapInformationService, FUN_1410c7c20, 172, 0x9458C2DA);
MS2_REPLACE_METHOD(0x1410cdf60, CubeMapInformationService, FUN_1410cdf60, 180, 0xE021D634);
MS2_REPLACE_METHOD(0x1410c92e0, CubeMapInformationService, FUN_1410c92e0, 218, 0x1A9BF0C4);
MS2_REPLACE_METHOD(0x1410d4680, CubeMapInformationService, FUN_1410d4680, 135, 0x19987D09);
MS2_REPLACE_METHOD(0x1410d43c0, CubeMapInformationService, FUN_1410d43c0, 135, 0x1EFD68B9);
MS2_REPLACE_METHOD(0x1410d59c0, CubeMapInformationService, FUN_1410d59c0, 224, 0x7EFB2116);
MS2_REPLACE_METHOD(0x1410b77e0, CubeMapInformationService, FUN_1410b77e0, 563, 0xFFCFF167);
MS2_REPLACE_METHOD(0x1410c2a90, CubeMapInformationService, FUN_1410c2a90, 583, 0x84A15AF6);
MS2_REPLACE_METHOD(0x1410c2ce0, CubeMapInformationService, FUN_1410c2ce0, 748, 0xFE7012D8);
MS2_REPLACE_METHOD(0x1410c3cd0, CubeMapInformationService, FUN_1410c3cd0, 290, 0x1F1F3F30);
MS2_REPLACE_METHOD(0x1410c8470, CubeMapInformationService, FUN_1410c8470, 257, 0xF30205C2);
MS2_REPLACE_METHOD(0x1410c80d0, CubeMapInformationService, FUN_1410c80d0, 231, 0xABEACB41);
MS2_REPLACE_METHOD(0x1410c8580, CubeMapInformationService, FUN_1410c8580, 223, 0x9BA56468);
MS2_REPLACE_METHOD(0x1410cb980, CubeMapInformationService, FUN_1410cb980, 245, 0x73C4ED69);
MS2_REPLACE_METHOD(0x1410d50c0, CubeMapInformationService, FUN_1410d50c0, 196, 0x522E19D8);
MS2_REPLACE_METHOD(0x1410d4fa0, CubeMapInformationService, FUN_1410d4fa0, 275, 0xAD5CD043);
MS2_REPLACE_METHOD(0x1410d5190, CubeMapInformationService, FUN_1410d5190, 433, 0xE5884B7A);
MS2_REPLACE_METHOD(0x1410d5350, CubeMapInformationService, FUN_1410d5350, 399, 0xC29D2273);
MS2_REPLACE_METHOD(0x1410d23f0, CubeMapInformationService, FUN_1410d23f0, 398, 0x7EA54F09);
MS2_REPLACE_METHOD(0x1410c3fc0, CubeMapInformationService, FUN_1410c3fc0, 622, 0xED5B5BB5);
MS2_REPLACE_METHOD(0x1410c81c0, CubeMapInformationService, FUN_1410c81c0, 679, 0x79FEA130);
MS2_REPLACE_METHOD(0x1410c88b0, CubeMapInformationService, FUN_1410c88b0, 468, 0x031EFECB);
MS2_REPLACE_METHOD(0x1410ca900, CubeMapInformationService, FUN_1410ca900, 338, 0xDCF131AE);
MS2_REPLACE_METHOD(0x1410cdd80, CubeMapInformationService, FUN_1410cdd80, 473, 0xE8A2EA39);
MS2_REPLACE_METHOD(0x1410c8670, CubeMapInformationService, FUN_1410c8670, 564, 0x851CB294);
MS2_REPLACE_METHOD(0x1410c4240, CubeMapInformationService, FUN_1410c4240, 612, 0x636D9607);
MS2_REPLACE_METHOD(0x1410c44b0, CubeMapInformationService, FUN_1410c44b0, 911, 0x74EE43B5);
MS2_REPLACE_METHOD(0x1410d4cb0, CubeMapInformationService, FUN_1410d4cb0, 737, 0x0AD0CDA1);
MS2_REPLACE_METHOD(0x1410bf470, CubeMapInformationService, FUN_1410bf470, 407, 0x4A53EA23);
MS2_REPLACE_METHOD(0x1410caf20, CubeMapInformationService, FUN_1410caf20, 649, 0x82022BDF);
MS2_REPLACE_METHOD(0x1410bbcd0, CubeMapInformationService, FUN_1410bbcd0, 575, 0xA310E8A1);
MS2_REPLACE_METHOD(0x1410bbf20, CubeMapInformationService, FUN_1410bbf20, 654, 0x0B26EEC4);
MS2_REPLACE_METHOD(0x1410bb610, CubeMapInformationService, FUN_1410bb610, 814, 0x8E4E010D);
MS2_REPLACE_METHOD(0x1410c93c0, CubeMapInformationService, FUN_1410c93c0, 827, 0xF91FF719);
MS2_REPLACE_METHOD(0x1410c7110, CubeMapInformationService, FUN_1410c7110, 992, 0xDA3A0DB0);
MS2_REPLACE_METHOD(0x1410c7500, CubeMapInformationService, FUN_1410c7500, 930, 0xAB12E4E9);
MS2_REPLACE_METHOD(0x1410c8a90, CubeMapInformationService, FUN_1410c8a90, 937, 0x33BAEC7A);
MS2_REPLACE_METHOD(0x1410d2fb0, CubeMapInformationService, FUN_1410d2fb0, 915, 0xFC10B7BD);
MS2_REPLACE_METHOD(0x1410d4940, CubeMapInformationService, FUN_1410d4940, 871, 0xEED28F52);
MS2_REPLACE_METHOD(0x1410c9db0, CubeMapInformationService, FUN_1410c9db0, 953, 0x23E747DF);
MS2_REPLACE_METHOD(0x1410badf0, CubeMapInformationService, FUN_1410badf0, 882, 0x6A5735E8);
MS2_REPLACE_METHOD(0x1410c8e40, CubeMapInformationService, FUN_1410c8e40, 1173, 0x6F333CC5);
MS2_REPLACE_METHOD(0x1410bb170, CubeMapInformationService, FUN_1410bb170, 1174, 0xF89B4DA8);
MS2_REPLACE_METHOD(0x1410cf160, CubeMapInformationService, FUN_1410cf160, 1112, 0x5523D56E);
MS2_REPLACE_METHOD(0x1410b9e90, CubeMapInformationService, FUN_1410b9e90, 1417, 0xA437BC17);
MS2_REPLACE_METHOD(0x1410c5ba0, CubeMapInformationService, GenerateFloorPhysX, 1220, 0xE7AB0ADE);
MS2_REPLACE_METHOD(0x1410c6100, CubeMapInformationService, GenerateAreaPhysX, 1803, 0x057F76EE);
MS2_REPLACE_METHOD(0x1410c6b90, CubeMapInformationService, FUN_1410c6b90, 1400, 0x9319C1FA);
MS2_REPLACE_METHOD(0x1410d27c0, CubeMapInformationService, FUN_1410d27c0, 1473, 0x02ED2F24);
MS2_REPLACE_METHOD(0x1410c3670, CubeMapInformationService, FUN_1410c3670, 1616, 0x10D8D61D);
MS2_REPLACE_METHOD(0x1410c9710, CubeMapInformationService, FUN_1410c9710, 1689, 0xF4C22809);
MS2_REPLACE_METHOD(0x1410ca170, CubeMapInformationService, FUN_1410ca170, 1926, 0x80AEF6DD);
MS2_REPLACE_METHOD(0x1410c1910, CubeMapInformationService, FUN_1410c1910, 3321, 0x80DCC52D);
MS2_REPLACE_METHOD(0x1410d0310, CubeMapInformationService, FUN_1410d0310, 2841, 0x47EBE7B4);
MS2_REPLACE_METHOD(0x1410cf5c0, CubeMapInformationService, FUN_1410cf5c0, 2611, 0x3A7711E8);

