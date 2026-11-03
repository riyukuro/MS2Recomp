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
#include "ms2/client/ms2/hardwareinstancingservice.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uihomeinfodialog.h"
#include <float.h>
#include "ms2/client/ms2/uihousemark.h"
#include "ms2/client/ms2/uicubeugchead.h"
#include "ms2/client/ms2/ugcmapitem.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#define MS2_STATICS_A_BEFORE_CONDITION "cubemapinformationservice_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/commonfiles/objectdata.h"
#include "ms2/commonfiles/ugcmapsetiteminfo.h"
#include "ms2/commonfiles/ugccubecategorytable.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/client/ms2/fielddatacli.h"    // C3: MS2Ptr<CFieldDataCli>::operator->
#include "ms2/client/ms2/liftableobject.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
#include <efd/EEMath.h>   // C3: efd::Clamp was FUN_140a17940
#include <efd/StdContainers.h>
#include <efd/utf8string.h>
// cubemapinformationservice_tail.h's value types (same names and layout)
class SalesInfo;
class SaleStateData;
class SetItemEffectInfo;
enum Unk_CMISKindA { Unk_CMISKindA_None };             // key of the 0x14112cb40 comparator family
enum Unk_CMISKindB { Unk_CMISKindB_None };             // key of the 0x14112cb80 comparator family
// per-cell record with a UTF-8 name (node value of f2b8)
struct Unk_CMISCell
{
    efd::utf8string m_name;
    int m_a, m_b, m_c, m_d, m_e, m_f;
};
// the real containers behind the tree stand-ins (the alias targets of their FUN_ wrappers)
class AutomaticCreateCubeInfo : public CPtred                                                // ctor 0x141122e70 (0x50); cubemapinformationservice_tail.h layout
{
public:
    AutomaticCreateCubeInfo();
    int m_nId;
    Unk_Int3 m_cell;
    float m_fAngle;
    int m_nFlag;
    char m_arr[0x20];                                                                       // Unk_GuildArray
};
struct Unk_CMISCubeTimer { Timer m_timer; bool m_bFlagA; bool m_bFlagB; egf::EntityID m_id; };   // f1f8 value: the placement timer (flags at 0x38/0x39); cubemapinformationservice_tail.h layout
MS2_CHECK_SIZE(Unk_CMISCubeTimer, 0x48);   // the exe frees f1f8 nodes as 0x70 bytes (deallocate 0x141150840)
struct Unk_CMISMarkRec;
namespace egfPhysX { class EntityActorData; }
struct Unk_Int3;
typedef std::map<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, int, std::less<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>, efd::CustomAllocator<std::pair<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>> const, int>> > CMISEMap_CString_int;
typedef std::map<egf::EntityID, MS2Ptr<Cube>, std::less<egf::EntityID>, efd::CustomAllocator<std::pair<const egf::EntityID, MS2Ptr<Cube>>> > CMISEMap_EntityID_MS2Ptr_Cube;
typedef std::map<egf::EntityID, efd::SmartPointer<egfPhysX::EntityActorData>, std::less<egf::EntityID>, efd::CustomAllocator<std::pair<const egf::EntityID, efd::SmartPointer<egfPhysX::EntityActorData>>> > CMISEMap_EntityID_PropPtr;
typedef std::map<egf::EntityID, __int64, std::less<egf::EntityID>, efd::CustomAllocator<std::pair<const egf::EntityID, __int64>> > CMISEMap_EntityID_int64;
typedef std::map<Unk_CMISKindA, int, std::less<Unk_CMISKindA>, efd::CustomAllocator<std::pair<const Unk_CMISKindA, int>> > CMISEMap_KindA_int;
typedef std::map<Unk_CMISKindB, int, std::less<Unk_CMISKindB>, efd::CustomAllocator<std::pair<const Unk_CMISKindB, int>> > CMISEMap_KindB_int;
typedef std::map<Unk_CMISKindB, unsigned char, std::less<Unk_CMISKindB>, efd::CustomAllocator<std::pair<const Unk_CMISKindB, unsigned char>> > CMISEMap_KindB_u_char;
typedef std::map<int, Unk_CMISCell, std::less<int>, efd::CustomAllocator<std::pair<const int, Unk_CMISCell>> > CMISEMap_int_Cell;
typedef std::map<int, Unk_CMISCubeTimer, std::less<int>, efd::CustomAllocator<std::pair<const int, Unk_CMISCubeTimer>> > CMISEMap_int_CubeTimer;
typedef std::map<int, egf::EntityID, std::less<int>, efd::CustomAllocator<std::pair<const int, egf::EntityID>> > CMISEMap_int_EntityID;
typedef std::map<int, Unk_CMISKindA, std::less<int>, efd::CustomAllocator<std::pair<const int, Unk_CMISKindA>> > CMISEMap_int_KindA;
typedef std::map<int, MS2Ptr<Cube>, std::less<int>, efd::CustomAllocator<std::pair<const int, MS2Ptr<Cube>>> > CMISEMap_int_MS2Ptr_Cube;
typedef std::map<int, MS2Ptr<FittingDollData>, std::less<int>, efd::CustomAllocator<std::pair<const int, MS2Ptr<FittingDollData>>> > CMISEMap_int_MS2Ptr_FittingDollData;
typedef std::map<int, MS2Ptr<SetItemEffectInfo>, std::less<int>, efd::CustomAllocator<std::pair<const int, MS2Ptr<SetItemEffectInfo>>> > CMISEMap_int_MS2Ptr_SetItemEffectInfo;
typedef std::map<int, std::map<int, MS2Ptr<Cube>, std::less<int>, std::allocator<std::pair<const int, MS2Ptr<Cube>>>>, std::less<int>, efd::CustomAllocator<std::pair<const int, std::map<int, MS2Ptr<Cube>, std::less<int>, std::allocator<std::pair<const int, MS2Ptr<Cube>>>>>> > CMISEMap_int_Map_int_MS2Ptr_Cube;
typedef std::map<int, Unk_CMISMarkRec, std::less<int>, efd::CustomAllocator<std::pair<const int, Unk_CMISMarkRec>> > CMISEMap_int_MarkRec;
typedef std::map<int, efd::SmartPointer<egf::Entity>, std::less<int>, efd::CustomAllocator<std::pair<const int, efd::SmartPointer<egf::Entity>>> > CMISEMap_int_SmartPointer_Entity;
typedef std::map<int, efd::vector<efd::SmartPointer<egf::Entity>>, std::less<int>, efd::CustomAllocator<std::pair<const int, efd::vector<efd::SmartPointer<egf::Entity>>>> > CMISEMap_int_vector_Entity;
typedef std::map<int, efd::set<int, std::less<int>>, std::less<int>, efd::CustomAllocator<std::pair<const int, efd::set<int, std::less<int>>>> > CMISEMap_int_set_int;
typedef std::map<int, unsigned int, std::less<int>, efd::CustomAllocator<std::pair<const int, unsigned int>> > CMISEMap_int_u_int;
typedef std::map<long, MS2Ptr<Cube>, std::less<long>, efd::CustomAllocator<std::pair<const long, MS2Ptr<Cube>>> > CMISEMap_long_MS2Ptr_Cube;
typedef std::map<std::pair<int, int>, MS2Ptr<SaleStateData>, std::less<std::pair<int, int>>, efd::CustomAllocator<std::pair<const std::pair<int, int>, MS2Ptr<SaleStateData>>> > CMISEMap_std_pair_int_int_MS2Ptr_SaleStateData;
typedef std::set<egf::EntityID, std::less<egf::EntityID>, efd::CustomAllocator<egf::EntityID> > CMISESet_EntityID;
typedef std::set<MS2Ptr<AutomaticCreateCubeInfo>, std::less<MS2Ptr<AutomaticCreateCubeInfo>>, efd::CustomAllocator<MS2Ptr<AutomaticCreateCubeInfo>> > CMISESet_MS2Ptr_AutomaticCreateCubeInfo;
typedef std::set<int, std::less<int>, efd::CustomAllocator<int> > CMISESet_int;
typedef std::set<std::pair<int, int>, std::less<std::pair<int, int>>, efd::CustomAllocator<std::pair<int, int>> > CMISESet_std_pair_int_int;
typedef std::map<Unk_CMISKindA, int, std::less<Unk_CMISKindA>, std::allocator<std::pair<const Unk_CMISKindA, int>> > CMISMap_KindA_int;
typedef std::map<int, MS2Ptr<Cube>, std::less<int>, std::allocator<std::pair<const int, MS2Ptr<Cube>>> > CMISMap_int_MS2Ptr_Cube;
typedef std::map<int, MS2Ptr<SalesInfo>, std::less<int>, std::allocator<std::pair<const int, MS2Ptr<SalesInfo>>> > CMISMap_int_MS2Ptr_SalesInfo;
typedef std::map<int, MS2Ptr<UICubeUGCHead>, std::less<int>, std::allocator<std::pair<const int, MS2Ptr<UICubeUGCHead>>> > CMISMap_int_MS2Ptr_UICubeUGCHead;
typedef std::map<int, std::map<unsigned int, std::set<int, std::less<int>, std::allocator<int>>, std::less<unsigned int>, std::allocator<std::pair<unsigned const int, std::set<int, std::less<int>, std::allocator<int>>>>>, std::less<int>, std::allocator<std::pair<const int, std::map<unsigned int, std::set<int, std::less<int>, std::allocator<int>>, std::less<unsigned int>, std::allocator<std::pair<unsigned const int, std::set<int, std::less<int>, std::allocator<int>>>>>>> > CMISMap_int_Map_unsigned_int_Set_int;
typedef std::map<int, Unk_Int3, std::less<int>, std::allocator<std::pair<const int, Unk_Int3>> > CMISMap_int_Unk_Int3;
typedef std::map<unsigned int, MS2SvrPtr<CUGCMapSetItemInfo>, std::less<unsigned int>, std::allocator<std::pair<unsigned const int, MS2SvrPtr<CUGCMapSetItemInfo>>> > CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo;
typedef std::map<unsigned int, std::set<int, std::less<int>, std::allocator<int>>, std::less<unsigned int>, std::allocator<std::pair<unsigned const int, std::set<int, std::less<int>, std::allocator<int>>>> > CMISMap_u_int_Set_int;
typedef std::map<unsigned int, int, std::less<unsigned int>, std::allocator<std::pair<unsigned const int, int>> > CMISMap_u_int_int;
typedef std::set<int, std::less<int>, std::allocator<int> > CMISSet_int;
typedef std::set<MS2Ptr<CFunctionCubeObject>, std::less<MS2Ptr<CFunctionCubeObject>>, std::allocator<MS2Ptr<CFunctionCubeObject>> > CMISSet_MS2Ptr_CFunctionCubeObject;
typedef std::set<unsigned __int64, std::less<unsigned __int64>, std::allocator<unsigned __int64> > CMISSet_u_int64;
class CItemData;   // C3: MS2Ptr<CItemData>::operator->
#undef MS2_STATICS_A_BEFORE_CONDITION
static UICommon::CMyPCKeyInputController s_keyInput;                // @0x1400e63f0

namespace egf { class EntityID; }
class CCubeMotionManager   // C3: member view for the former free stand-ins
{
public:
    void Update();
    void AddRotate(egf::EntityID id, float fFrom, float fTo, unsigned nMs);
    void AddFade(egf::EntityID id, float fFrom, float fTo, unsigned nMs, bool bHide);
    void RemoveFade(egf::EntityID id);
};
void FUN_14112ded0();                                                // CCubeMotionManager::DestroyInstance
CCubeMotionManager* FUN_14112dd30();                                 // CCubeMotionManager::CreateInstance
efd::MessageService* FUN_1413f9830();
void Unk_CMISNotifyA(struct Unk_CMISSink*, int);   // C3: was FUN_1410db460
char* FUN_1411282d0(void*, struct Unk_Key*);   // C3: was FUN_1411282d0
char* FUN_141128250(void*, struct Unk_Key*);   // C3: was FUN_141128250
void FUN_1409fabe0(void*);
char* FUN_141128310(void*, void*);   // C3: was FUN_141128310
char* FUN_141128290(void*, void*);   // C3: was FUN_141128290
char* FUN_1411280d0(void*, void*);   // C3: was FUN_1411280d0

// ms_ClassInfo and its initializer belong to unit_1400e5dd0 (.text$di 0x1400e5dd0-, outside the hook DLL); the
// hook DLL defines it here.
#ifdef MS2_HOOK_DLL
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CubeMapInformationService);
#endif
CubeMapInformationService* TSingleton<CubeMapInformationService>::s_instance = 0;
inline TSingleton<CubeMapInformationService>::TSingleton() { s_instance = static_cast<CubeMapInformationService*>(this); }

// Unk_CMISTree<N>'s ctor/dtor stay declared only: symbols.tsv binds each family to the exe's wrapper pair
// (0x141122xxx / 0x141125xxx), which allocates/frees the tree's head node. A local definition would win over that
// binding in the hook DLL and leave head null (the hooked MS2::RegisterServices then AVs in the first f368 lookup).
// Exceptions: 287's dtor (FUN_1410b7fe0's static, atexit thunk 0x142cac250) has no symbol row, and the 294/295 locals
// of ExportUGCMap are constructed/destroyed by explicit wrapper calls, so their implicit ctor/dtor do nothing.
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
CubeMapInformationService::CubeMapInformationService() : f158(0), s1c8(L""), s1d0(L""), f2d8(reinterpret_cast<const Unk_CMISEntityRef&>(g_cubeMapNone))
{
    FUN_14112dd30();
    for (int i = 0; i < 3; i++)
        f318[i] = 0;
    static_cast<Unk_Int3&>(p300) = Unk_Int3(0, 0, 0);
    static_cast<Unk_Int3&>(p30c) = Unk_Int3(0, 0, 0);
    for (int i = 0; i < 9; i++) {
        int k = i;
        *((unsigned char*)FUN_1411282d0((void*)(&f368), (struct Unk_Key*)(&k))) = 0;
    }
    for (int j = 0; j < 9; j++) {
        int k = j;
        *((int*)FUN_141128250((void*)(&f378), (struct Unk_Key*)(&k))) = 0;
    }
    a388.RemoveAll();
    a3a8.RemoveAll();
    reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->clear();
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
class MyPC   // C3: member view (real class not in this TU)
{
public:
    int HasNoHome();
    class Unk_MyPCComp1618* FUN_141523c50();                    // the party info
    int FUN_141527920(void* p);
    void FUN_14152a2b0(int n);                                  // set the mark flag
    class Unk_PCCubeCraft* GetActiveCubeCraft();
};
class PC { public: int IsInCubeMode(); int IsCubeMode1(); __int64 FUN_141656ad0(); void FUN_141656a50(__int64 nCharId); void FUN_141653d10(MS2Ptr<CItem> spItem); };   // C3: unit-local view
class FittingDollPC : public efd::MemObject { public: FittingDollPC(); char m_pad[0x1300]; int FUN_14121bab0(int nItemId); void FUN_14121c6e0(void* p); };   // C3: unit-local view
class Unk_CMISRoster { };
class Unk_CMISWorld : public WorldService
{
public:
    Unk_CMISRoster* FUN_141bd0cc0();                            // the party/roster manager
    void* FUN_141bd0fa0(Unk_CMISEntityRef ref);                 // the magic-cube object of an entity
    Unk_PayloadPtr<Unk_CMISObj208> FUN_141bd30a0();             // the current field data
};
class Unk_CMISActor
{
public:
    Vector3 FUN_141676880();                            // PCBase member: the facing point
    Vector3 FUN_1416767d0();                            // PCBase member: the position
};
void FUN_140a01250(Vector3 ptDir, Vector3* pForward, Vector3* pRight);
Unk_Int3 FUN_1408a1430(Vector3 pt);                     // the cube cell of a world point
int FUN_1408a13d0(Vector3 pt);                          // the cell key of a world point
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
int* FUN_141128540(Unk_CMISIter<278>*);                                     // operator*
void* FUN_141129a60(struct Unk_TreeIter*);   // C3: was FUN_141129a60
class Unk_CMISUidRecord : public CPtred                                                              // cubemapinformationservice_tail.h layout
{
public:
    virtual ~Unk_CMISUidRecord();
};
typedef std::map<unsigned __int64, Unk_CubeOwnerPtr> CMISMap_u64_CubeOwnerPtr;                      // f148 (the exe's folded rows name this instantiation for find/end/==/!=/[])
typedef std::map<unsigned __int64, MS2Ptr<Unk_CMISUidRecord>, std::less<unsigned __int64>, efd::CustomAllocator<std::pair<const unsigned __int64, MS2Ptr<Unk_CMISUidRecord>>> > CMISEMap_u64_MS2Ptr_UidRecord;   // f148 (and this one for erase/clear)
void FUN_1411552b0(Unk_CMISTree<270>*, const CString*);                                   // erase
class Unk_CubeHeightIndex   // C3: member view for the former free stand-ins
{
public:
    void Clear();
    void FUN_1410b2510(int, int, int);
    void FUN_1410b25a0(int, int, int);
};
void FUN_1402237c0(struct Unk_LevelArray*);   // C3: was FUN_1402237c0
struct Unk_CMISPt2 { float x, y; };
Unk_CubeOwnerPtr FUN_1408a0fa0(Unk_CubeOwners& owners, int nGroup, int nBlock);
efd::Point3 FUN_1408a15b0(Vector3, Vector3);
Unk_CMISIter<257>* FUN_141152030(Unk_CMISTree<257>*, Unk_CMISIter<257>*);
char* FUN_141128110(void*, void*);   // the f48 value of a key (unit_141127a90)
class CFieldDataCli;   // C3: forward decl for a rewritten call
Unk_CMISIter<265>* FUN_14114e010(Unk_CMISTree<265>*, Unk_CMISIter<265>*);       // begin
struct Unk_CMISRefElem { int m_key, m_pad; Unk_CMISEntityRef m_ref; };
Unk_CMISRefElem* FUN_1411286a0(Unk_CMISIter<265>*);                           // operator*
void FUN_141129bd0(Unk_CMISIter<265>*);                                       // operator++
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
bool FUN_1408a06a0(int, int);   // C3: was FUN_1408a06a0
struct Unk_CMISIntPair { int m_key, m_val; };
struct Unk_CMISInsRes { void* m_it; bool m_ok; };
Unk_CMISIter<286>* FUN_140340ff0(Unk_CMISTree<286>*, Unk_CMISIter<286>*);                    // begin
Unk_CMISIter<286>* FUN_140341f40(Unk_CMISTree<286>*, Unk_CMISIter<286>*);                    // end
Unk_CMISIter<286>* FUN_1404c0270(Unk_CMISTree<286>*, Unk_CMISIter<286>*, const unsigned __int64*);   // find
unsigned char FUN_1403344a0(Unk_CMISIter<286>*, Unk_CMISIter<286>*);
unsigned char FUN_140334210(Unk_CMISIter<286>*, Unk_CMISIter<286>*);
Unk_CMISInsRes* FUN_1404422b0(Unk_CMISTree<286>*, Unk_CMISInsRes*, const unsigned __int64*);   // insert
unsigned __int64* FUN_1408f2950(Unk_CMISIter<286>*);                                           // operator*
void FUN_140334ef0(Unk_CMISIter<286>*);                                                        // operator++
Unk_CMISIter<282>* FUN_1411582a0(Unk_CMISTree<282>*, Unk_CMISIter<282>*, const int*);
Unk_CMISIter<282>* FUN_141152150(Unk_CMISTree<282>*, Unk_CMISIter<282>*);
bool FUN_141127110(Unk_CMISIter<282>*, Unk_CMISIter<282>*);
bool FUN_141127840(Unk_CMISIter<282>*, Unk_CMISIter<282>*);                                 // operator!=
Unk_CMISIntPair* FUN_1411284e0(Unk_CMISIter<282>*);
bool FUN_141151720(Unk_CMISTree<260>*);
Unk_CMISIter<278>* FUN_141157040(Unk_CMISTree<278>*, Unk_CMISIter<278>*, const int*);
struct Unk_CMISPt3 { float x, y, z; Unk_CMISPt3(const Vector3&); };   // efd::Point3 copy (0x14027dcf0)
struct Unk_CMISRayHit { __int64 m_q0, m_q1, m_q2, m_q3, m_q4, m_q5; egf::Entity* m_pEntity; __int64 m_q7, m_q8, m_q9, m_q10, m_q11, m_q12; };
void FUN_140ad4440(Unk_CMISRayHit*);
class CPhysXHelper;
class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: was FUN_1409f7ca0
int FUN_14168a310(CPhysXHelper*, Unk_CMISPt3*, Vector3*, Unk_CMISRayHit*, float, __int64, int);
class Unk_CMISPhysScene
{
public:
    virtual void vf0() = 0; virtual void vf1() = 0; virtual void vf2() = 0; virtual void vf3() = 0;
    virtual void vf4() = 0; virtual void vf5() = 0; virtual void vf6() = 0; virtual void vf7() = 0;
    virtual void RemoveActor(void* pActor) = 0;             // +0x40
};
class CPhysXHelper   // C3: member view for the former free stand-ins
{
public:
    class NxScene* FUN_14168a1c0();
public:
    void FUN_14168a540(int);   // C3: was free FUN_14168a540
public:
    void FUN_14168a570();   // C3: was free FUN_14168a570
    bool FUN_141689a10(egf::Entity* pEntity);
    void FUN_141689ec0(egf::Entity* pEntity, unsigned short nGroup, const class NxGroupsMask* pMask, int bRefresh);
};
void FUN_1411554c0(Unk_CMISTree<257>*, const Unk_CMISEntityRef*);
void FUN_1411556d0(Unk_CMISTree<258>*, const Unk_CMISEntityRef*);
char* FUN_141127ed0(void*, void*);   // C3: was FUN_141127ed0
bool FUN_14028d470(float, float);
extern Vector3 DAT_143a08cf8;                                       // up vector
extern Vector3 DAT_143b01a60;                                       // zero / fall-through direction
struct Unk_CMISCubeByKey { int first; MS2Ptr<Cube> second; };                // the node value of the cubes by key
void FUN_14114dd70(Unk_CMISTree<260>*, Unk_CMISIter<260>*);                 // begin
bool FUN_1411274c0(Unk_CMISIter<260>*, Unk_CMISIter<260>*);                 // operator!=
Unk_CMISCubeByKey* FUN_1411285e0(Unk_CMISIter<260>*);                       // operator*
void* FUN_141129b50(struct Unk_TreeIter*);   // C3: was FUN_141129b50
Unk_CMISIter<260>* FUN_141129b00(Unk_CMISIter<260>*, Unk_CMISIter<260>*, int);        // operator++(int)
int FUN_14053fc10(int);                                                     // the item category
struct Unk_CMISCubeOwner { char m_pad[0x18]; __int64 m_nId; };
struct Unk_CMISIntList { Unk_CMISIntList(); ~Unk_CMISIntList(); void* m_pHead; unsigned __int64 m_nSize; };   // 0x10 bytes (list<int>): the cube keys of a column
Unk_CMISIter<262>* FUN_141151c70(Unk_CMISTree<262>*, Unk_CMISIter<262>*);   // end
Unk_CMISIter<262>* FUN_141157900(Unk_CMISTree<262>*, Unk_CMISIter<262>*, const int*);   // find
bool FUN_1411275c0(Unk_CMISIter<262>*, Unk_CMISIter<262>*);                 // operator!=
bool FUN_141126e90(Unk_CMISIter<262>*, Unk_CMISIter<262>*);                 // operator==
char* FUN_141127e10(void*, void*);   // C3: was FUN_141127e10
void FUN_141126700(Unk_CMISIntList*, Unk_CMISIntList*);                     // operator=
struct Unk_CMISListIter { void* m_p; };
Unk_CMISListIter* FUN_14114e630(Unk_CMISIntList*, Unk_CMISListIter*);                    // begin
struct Unk_CMISListEnd { void* m_p; };
Unk_CMISListEnd* FUN_1411522d0(Unk_CMISIntList*, Unk_CMISListEnd*);         // end
bool FUN_14035ea60(Unk_CMISListIter*, Unk_CMISListEnd*);                   // operator!=
int* FUN_1403e8d70(Unk_CMISListIter*);                                      // operator*
void FUN_14035ebf0(Unk_CMISListIter*);                                      // operator++
struct Unk_CMISHouseInfo : public CPtred                                    // a house marker record (0x38)
{
    int m_nGroup;                                                           // +0x18
    Vector3 m_pt;                                                   // +0x1c
    CStringW m_strOwner;                                                    // +0x28
    bool m_bNoSalable;                                                      // +0x30
    int m_nValue;                                                           // +0x34
};
struct Unk_CMISHousePtr { void* m_0; void* m_p; }; MS2_CHECK_SIZE(Unk_CMISHousePtr, 0x10); // object at +8 (ctor 0x14111e6e0, -> 0x141128470); 8 bytes overflowed FUN_1410bbf20's local
struct Unk_CMISHouseNode { int first; Unk_CMISHousePtr second; };
class Unk_CMISHouseMark { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();   };
Unk_CMISHouseMark* FUN_1410dc020();
void FUN_14114dc90(Unk_CMISTree<274>*, Unk_CMISIter<274>*);                 // begin
Unk_CMISIter<274>* FUN_141151a30(Unk_CMISTree<274>*, Unk_CMISIter<274>*);   // end
bool FUN_141127440(Unk_CMISIter<274>*, Unk_CMISIter<274>*);                 // operator!=
Unk_CMISHouseNode* FUN_1411285a0(Unk_CMISIter<274>*);                       // operator*
void* FUN_141129ac0(struct Unk_TreeIter*);   // C3: was FUN_141129ac0
Unk_CMISIter<274>* FUN_1411573c0(Unk_CMISTree<274>*, Unk_CMISIter<274>*, const int*);   // find
char* FUN_141127c50(void*, void*);   // C3: was FUN_141127c50
Unk_CMISHouseInfo* FUN_141128470(Unk_CMISHousePtr*);                         // operator->
int FUN_1408b5620(int);
bool FUN_141126b10(Unk_CMISHousePtr*, int);                                 // operator==(0)
Unk_CMISHouseInfo* FUN_141128800(Unk_CMISHousePtr*);                        // operator*
class Unk_CMISPolyObj { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); };
struct Unk_CMISPolyNode { int first; Unk_CMISHousePtr second; };
Unk_CMISPolyNode* FUN_141128600(Unk_CMISIter<273>*);                        // operator*
void FUN_141129b70(Unk_CMISIter<273>*);                                     // operator++
Unk_CMISPolyObj* FUN_1411284c0(Unk_CMISHousePtr*);                          // operator->
struct Unk_CMISPair { int m_a, m_b; };
extern Unk_CMISPair DAT_143b02320;                                          // initial cursor pair
float FUN_14029d220(float f);                                               // fabsf
Unk_Int3* FUN_14112ca20(Unk_Int3* pA, Unk_Int3* pOut, Unk_Int3* pB);   // point add
struct Unk_DkPoint : public Unk_Int3 { Unk_Int3 operator+(const Unk_DkPoint& o) const; };   // 0x14112ca20 (unit_14112ab60)
MS2Ptr<Cube>* FUN_141127cd0(Unk_CMISTree<260>*, const int*);             // operator[]: the cube of a key
struct Unk_CMISCubeById { Unk_CMISEntityRef key; MS2Ptr<Cube> second; };  // the node value of the cubes by entity
bool FUN_141127800(Unk_CMISIter<259>*, Unk_CMISIter<259>*);                                          // operator!=
Unk_CMISCubeById* FUN_141128780(Unk_CMISIter<259>*);                                                 // operator*
bool FUN_1408a07b0(int nMapId, int a, __int64 b);
extern int DAT_1439f4a7c;
extern __int64 DAT_143ab2820;

// @0x1410b76a0
int CubeMapInformationService::FUN_1410b76a0()
{
    ClearCubes();
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
    f208 = reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())->FUN_141bd30a0();
    f218 = FUN_1408ad3f0(WorldService::GetInstance()->FUN_141bd3060());
}
// @0x1410b7a20
Vector3 CubeMapInformationService::GetCellPosition(Vector3 pt, Vector3* pOut)
{
    Unk_Int3 cell = FUN_1408a1430(pt);
    pOut->x = (float)cell.x * 150.0f;
    pOut->y = (float)cell.y * 150.0f;
    pOut->z = (float)cell.z * 150.0f;
    return *pOut;
}
// @0x1410b7ad0
Vector3 CubeMapInformationService::GetCellInFrontOfActor(PCBase* pActor, float fDist, Vector3* pOut, int bSnap)
{
    return FUN_1410b7ba0(reinterpret_cast<Unk_CMISActor*>(pActor)->FUN_1416767d0(), reinterpret_cast<Unk_CMISActor*>(pActor)->FUN_141676880(), fDist, pOut, bSnap);
}
// @0x1410b7ba0
Vector3 CubeMapInformationService::FUN_1410b7ba0(Vector3 ptFrom, Vector3 ptTo, float fDist, Vector3* pOut, int bSnap)
{
    Vector3 kForward, kRight;
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
    return reinterpret_cast<const CMISESet_EntityID*>(&f78)->size() == 0;
}
// @0x1410b7da0
bool CubeMapInformationService::FUN_1410b7da0(Vector3 pt)
{
    if (!HasCubeAtPoint(pt))
        return false;
    int nKey = FUN_1408a13d0(pt);
    if ((reinterpret_cast<CMISEMap_int_EntityID*>(&f2e0)->find(nKey) != reinterpret_cast<CMISEMap_int_EntityID*>(&f2e0)->end()))
        return true;
    return false;
}
// @0x1410b7e80
bool CubeMapInformationService::HasCubeAtPoint(Vector3 pt)
{
    return HasCubeAtKey(FUN_1408a13d0(pt));
}
// @0x1410b7ed0
bool CubeMapInformationService::HasCubeAtKey(int nKey)
{
    if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->find(nKey) == reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()))
        return false;
    if ((reinterpret_cast<CMISEMap_int_CubeTimer*>(&f1f8)->find(nKey) != reinterpret_cast<CMISEMap_int_CubeTimer*>(&f1f8)->end()))
        return false;
    return true;
}
// @0x1410b7f90
bool CubeMapInformationService::HasCubeAtCell(Unk_Int3 cell)
{
    return HasCubeAtKey(FUN_1408a0370(cell.x, cell.y, cell.z));
}

// @0x1410b7fe0
Unk_CMISTree<287>* CubeMapInformationService::FUN_1410b7fe0(int nKey)
{
    static Unk_CMISTree<287> s_empty;
    if ((reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->find(nKey) == reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->end()))
        return &s_empty;
    return FUN_141127dd0(&fc8, &nKey);
}
// @0x1410b80d0
Cube* CubeMapInformationService::FUN_1410b80d0(MS2Ptr<Cube> spCube, int nZ)
{
    int nKey = FUN_1408a03c0(spCube->position);
    if ((reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->find(nKey) == reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->end()))
        return 0;
    int nColumn = FUN_1408a03c0(spCube->position);
    Unk_CMISTree<287>* pColumn = FUN_141127d90(&fc8, &nColumn);
    if (reinterpret_cast<const CMISEMap_long_MS2Ptr_Cube*>(pColumn)->size() == 0)
        return 0;
    if ((reinterpret_cast<CMISMap_int_MS2Ptr_Cube*>(pColumn)->find(nZ) == reinterpret_cast<CMISMap_int_MS2Ptr_Cube*>(pColumn)->end()))
        return 0;
    return FUN_141128350(pColumn, &nZ)->get();
}
// @0x1410b82c0
bool CubeMapInformationService::FUN_1410b82c0(MS2Ptr<Cube> spCube)
{
    int nKey = FUN_1408a03c0(spCube->position);
    if ((reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->find(nKey) == reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->end()))
        return false;
    int nColumn = FUN_1408a03c0(spCube->position);
    Unk_CMISTree<287>* pColumn = FUN_141127d90(&fc8, &nColumn);
    if (reinterpret_cast<const CMISEMap_long_MS2Ptr_Cube*>(pColumn)->size() == 0)
        return false;
    return true;
}
// @0x1410b8420
bool CubeMapInformationService::FUN_1410b8420(MS2Ptr<Cube> spCube, int nZ)
{
    int nKey = FUN_1408a03c0(spCube->position);
    if ((reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->find(nKey) == reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->end()))
        return false;
    int nColumn = FUN_1408a03c0(spCube->position);
    Unk_CMISTree<287>* pColumn = FUN_141127d90(&fc8, &nColumn);
    if (reinterpret_cast<const CMISEMap_long_MS2Ptr_Cube*>(pColumn)->size() == 0)
        return false;
    if ((reinterpret_cast<CMISMap_int_MS2Ptr_Cube*>(pColumn)->find(nZ) == reinterpret_cast<CMISMap_int_MS2Ptr_Cube*>(pColumn)->end()))
        return false;
    return true;
}
// @0x1410b85f0
void CubeMapInformationService::ComputeCellBounds(Unk_Int3* pMin, Unk_Int3* pMax)
{
    pMin->x = 0x7fffffff;
    pMin->y = 0x7fffffff;
    pMin->z = 0x7fffffff;
    pMax->x = 0x80000000;
    pMax->y = 0x80000000;
    pMax->z = 0x80000000;
    for (CMISEMap_int_Cell::iterator it = reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->begin(); (it != reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->end()); FUN_141129a60((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<278>*>(&it)))) {
        int nKey = *FUN_141128540(reinterpret_cast<Unk_CMISIter<278>*>(&it));
        Unk_Int3 cell = FUN_1408a0400(nKey);
        pMin->x = std::min<int>(pMin->x, cell.x);
        pMin->y = std::min<int>(pMin->y, cell.y);
        pMin->z = std::min<int>(pMin->z, cell.z);
        pMax->x = std::max<int>(pMax->x, cell.x);
        pMax->y = std::max<int>(pMax->y, cell.y);
        pMax->z = std::max<int>(pMax->z, cell.z);
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
            MS2Ptr<Cube> spCube(GetCubeByKey(nKey));
            if (spCube.get() != 0) {
                if (FUN_1408a07b0(WorldService::GetInstance()->FUN_141bd3060(), DAT_1439f4a7c, DAT_143ab2820)) {
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
    return GetCubeAtCell(ptHit);
}
// @0x1410b8980
Cube* CubeMapInformationService::FUN_1410b8980(Unk_Int3 pt)
{
    Cube* pBase = GetCubeAtCell(pt);
    if (pBase != 0 && pBase->field44 == 0)
        return 0;
    while (pBase != 0) {
        pt.z = pt.z - 1;
        Cube* pNext = GetCubeAtCell(pt);
        if (pNext == 0 || pNext->field50 != pBase->field50 || pNext->field44 == 0)
            return pBase;
        pBase = pNext;
    }
    return pBase;
}
// @0x1410b8a60
Cube* CubeMapInformationService::GetCubeAtCell(Unk_Int3 pt)
{
    return GetCubeByKey(FUN_1408a0370(pt.x, pt.y, pt.z));
}
// @0x1410b8ab0
Cube* CubeMapInformationService::GetCubeAtPoint(Vector3 pt)
{
    return GetCubeByKey(FUN_1408a13d0(pt));
}
// @0x1410b8b00
Cube* CubeMapInformationService::GetCubeByKey(int nKey)
{
    if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->find(nKey) == reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()))
        return 0;
    if ((reinterpret_cast<CMISEMap_int_CubeTimer*>(&f1f8)->find(nKey) != reinterpret_cast<CMISEMap_int_CubeTimer*>(&f1f8)->end()))
        return 0;
    return FUN_141127cd0(&f98, &nKey)->get();
}
// @0x1410b8be0
Cube* CubeMapInformationService::FindCubeByEntityRef(const Unk_CMISEntityRef& ref)
{
    Unk_1401cd100 none(0);
    if (reinterpret_cast<const egf::EntityID&>(ref).operator==(reinterpret_cast<const egf::EntityID&>(none)))
        return 0;
    CMISEMap_EntityID_MS2Ptr_Cube::iterator itFind = reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&fa8)->find(*reinterpret_cast<const egf::EntityID*>(&ref));
    if ((itFind != reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&fa8)->end()))
        return FUN_141128780(reinterpret_cast<Unk_CMISIter<259>*>(&itFind))->second.get();
    return 0;
}

// @0x1410b8c90
Cube* CubeMapInformationService::FUN_1410b8c90(const Unk_CMISEntityRef& ref)
{
    Unk_1401cd100 none(0);
    if (reinterpret_cast<const egf::EntityID&>(ref).operator==(reinterpret_cast<const egf::EntityID&>(none)))
        return 0;
    CMISEMap_EntityID_MS2Ptr_Cube::iterator itFind = reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&fa8)->find(*reinterpret_cast<const egf::EntityID*>(&ref));
    if ((itFind != reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&fa8)->end())) {
        MS2Ptr<Cube> spCube(FUN_141128780(reinterpret_cast<Unk_CMISIter<259>*>(&itFind))->second);
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
        pCube = GetCubeAtCell(*FUN_14112ca20(&off, &tmp, &pBase->position));
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
        pCube = GetCubeAtCell(*FUN_14112ca20(&off, &tmp, &pBase->position));
        if (pCube != 0 && pCube->field70 != 0)
            return pCube;
        else
            return 0;
    }
    return pCube;
}

// @0x1410b8e60
Cube* CubeMapInformationService::GetCubeByEntity(egf::Entity* pEntity)
{
    if (pEntity != 0) {
        Vector3 pt;
        reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(pt));
        Cube* pCube = GetCubeAtPoint(pt);
        if (pCube != 0 && pCube->field70 != 0) {
            if (reinterpret_cast<const egf::EntityID&>((*((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&pCube->entity))->operator->()))->GetEntityID()))).operator==(reinterpret_cast<const egf::EntityID&>(*reinterpret_cast<const Unk_1401cd100*>(((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(pEntity))->GetEntityID())))))
                return pCube;
        }
    }
    return 0;
}

// @0x1410b8f30
Cube* CubeMapInformationService::GetCubeByRaycast(Vector3 ptFrom, Vector3* pHit, float fRange)
{
    static Vector3 s_kDown = DAT_143a08cf8.FUN_14097fc90(20.0f);
    Unk_CMISPt3 ptStart(ptFrom.FUN_14097fd50(s_kDown));
    if (FUN_14028d470(fRange, 0.0f))
        fRange = 150.0f;
    Unk_CMISRayHit hit;
    FUN_140ad4440(&hit);
    if (FUN_14168a310(((class CPhysXHelper*)FUN_1409f7ca0()), &ptStart, pHit, &hit, fRange, 0, 0) != 0)
        return GetCubeByEntity(hit.m_pEntity);
    return 0;
}

// @0x1410b9150
Vector3 CubeMapInformationService::FUN_1410b9150(Vector3 ptIn)
{
    static Vector3 s_kDown = DAT_143a08cf8.FUN_14097fc90(20.0f);
    Unk_CMISPt3 ptStart(ptIn.FUN_14097fd50(s_kDown));
    Vector3 ptDir = DAT_143b01a60;
    Unk_CMISRayHit hit;
    FUN_140ad4440(&hit);
    Cube* pCube;
    if (FUN_14168a310(((class CPhysXHelper*)FUN_1409f7ca0()), &ptStart, &ptDir, &hit, 750.0f, 0, 0) != 0 && (pCube = GetCubeByEntity(hit.m_pEntity)) != 0 && pCube->field70 != 0) {
        Vector3 ptRes;
        reinterpret_cast<egf::Entity*>(((const egf::EntityPtr*)(&pCube->entity))->operator->())->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(ptRes));
        ptRes.z = ptIn.z;
        return ptRes;
    }
    return ptIn;
}

// @0x1410b9330
int CubeMapInformationService::FUN_1410b9330(void* pArg, Vector3 pt, float fStep, Vector3* pOutPos, Vector3* pOutRot, int* pnResult, void** ppHit)
{
    float fLimit = 75.0f;
    void* pFound = 0;
    float fRadius = fStep;
    Vector3 ptCur;
    Vector3 ptOffset = DAT_143b01a60;
    Unk_CMISPair kCursor = DAT_143b02320;
    *pnResult = FUN_1410d1320(pArg, pt, fStep, &ptCur);
    if (*pnResult == 9)
        return 0;
    float fDx = pt.x - ptCur.x;
    float fDy = pt.y - ptCur.y;
    *pOutRot = DAT_143b01a60;
    if (FUN_14029d220(fDx) > fLimit - fRadius)
        fDx = (fDx / FUN_14029d220(fDx)) * (fLimit - fRadius);
    if (FUN_14029d220(fDy) > fLimit - fRadius)
        fDy = (fDy / FUN_14029d220(fDy)) * (fLimit - fRadius);
    *pnResult = FUN_1410d1820(pArg, *pnResult, pt, ptCur, &pFound);
    if (pFound != 0 && FUN_1410d2130(static_cast<Cube*>(pFound), *pnResult, fRadius, reinterpret_cast<float*>(pOutPos), pOutRot) != 0) {
        pOutPos->z = pt.z;
        if (ppHit != 0)
            *ppHit = pFound;
        return 1;
    }
    {
        switch (*pnResult) {
        case 0:
            return 0;
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
        return 1;
    }
}

// @0x1410b9850
Cube* CubeMapInformationService::FindCubeByItemId(int nItemId)
{
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&it)))) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->second);
        if (spCube->field48 == 0)
            continue;
        {
            if (((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20() == nItemId)
                return spCube.get();
        }
    }
    return 0;
}
// @0x1410b9950
int CubeMapInformationService::HasCubeWithIconCode(int nCategory)
{
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&it)))) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->second);
        if (spCube->field48 == 0)
            continue;
        if (FUN_14053fc10(((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20()) == nCategory)
            return 1;
    }
    return 0;
}
// @0x1410b9a50
int CubeMapInformationService::CountCubes()
{
    int nCount = 0;
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&it)))) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->second);
        if (spCube->field48 == 0)
            continue;
        nCount++;
    }
    return nCount;
}
// @0x1410b9b20
int CubeMapInformationService::CountCubesByItemId(int nItemId)
{
    int nCount = 0;
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&it)))) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->second);
        if (spCube->field48 == 0)
            continue;
        if (((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20() != nItemId)
            continue;
        nCount++;
    }
    return nCount;
}
// @0x1410b9d80
int CubeMapInformationService::FUN_1410b9d80(__int64 nId)
{
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&it)))) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->second);
        if (spCube->field48 == 0)
            continue;
        if (((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f50() == nId)
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
int CubeMapInformationService::CountCubesByItemIdAndOwner(int nItemId, __int64 nOwnerId)
{
    int nCount = 0;
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&it)))) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->second);
        if (spCube->field48 == 0)
            continue;
        if (((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20() != nItemId)
            continue;
        __int64 nOwner = 0;
        Unk_CMISCubeOwner* pOwner = ((struct Unk_CMISCubeOwner*)((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f80());
        if (pOwner != 0)
            nOwner = pOwner->m_nId;
        if (nOwner != nOwnerId)
            continue;
        nCount++;
    }
    return nCount;
}
// @0x1410ba440
float CubeMapInformationService::DirectionToAngle(int nDir)
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
int CubeMapInformationService::VectorToDirection(Vector3 ptDir)
{
    Vector3 kWest(-1.0f, 0.0f, 0.0f);
    Vector3 kNorth(0.0f, 1.0f, 0.0f);
    Vector3 kEast(1.0f, 0.0f, 0.0f);
    Vector3 kSouth(0.0f, -1.0f, 0.0f);
    Vector3 kForward, kRight;
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
Unk_Int3 CubeMapInformationService::StepCellInDirection(Unk_Int3 pt, int nDir)
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
Unk_Int3 CubeMapInformationService::FUN_1410bac00(Vector3 ptDir)
{
    Vector3 kWest(-1.0f, 0.0f, 0.0f);
    Vector3 kNorth(0.0f, 1.0f, 0.0f);
    Vector3 kEast(1.0f, 0.0f, 0.0f);
    Vector3 kSouth(0.0f, -1.0f, 0.0f);
    Vector3 kForward, kRight;
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
    MS2Ptr<Cube> spCube(GetCubeAtCell(pt));
    while (spCube.get() != 0) {
        if (spCube->field50 != 0)
            return spCube->field50;
        pt.z = pt.z - 1;
        spCube.AssignRaw(GetCubeAtCell(pt));
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
    if ((reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->find(nKey) != reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end())) {
        Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nKey)));
        for (CMISESet_int::iterator it = reinterpret_cast<CMISESet_int*>(pList)->begin(); (it != reinterpret_cast<CMISESet_int*>(pList)->end()); ++it) {
            int nCell = *((int*)(&*it));
            Unk_Int3 pt = FUN_1408a0400(nCell);
            pt.z = pt.z + 1;
            if (HasCubeAtCell(pt))
                return 1;
        }
    }
    return 0;
}
// @0x1410bbc00
void CubeMapInformationService::FUN_1410bbc00(int nKey, int nUnused)
{
    if ((reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->find(nKey) == reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end())) {
        Unk_CMISIntList kEmpty;
        FUN_141126700(((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nKey))), &kEmpty);
    }
    FUN_1410bbcd0(nKey, 0);
}

// @0x1410bc1c0
void CubeMapInformationService::FUN_1410bc1c0()
{
    if (!((std::_Tree<std::_Tmap_traits<int, MS2Ptr<FittingDollData>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<FittingDollData>>>, 0>>*)(void*)(&f238))->empty()) {
        Unk_CMISHouseMark* pHouse = FUN_1410dc020();
        if (pHouse != 0) {
            for (CMISMap_int_MS2Ptr_SalesInfo::iterator it = reinterpret_cast<CMISMap_int_MS2Ptr_SalesInfo*>(&f238)->begin(); (it != reinterpret_cast<CMISMap_int_MS2Ptr_SalesInfo*>(&f238)->end()); FUN_141129ac0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<274>*>(&it)))) {
                if (FUN_141126b10(&FUN_1411285a0(reinterpret_cast<Unk_CMISIter<274>*>(&it))->second, 0))
                    continue;
                ((UIHouseMark*)(Unk_CMISHouseMark*)(pHouse))->FUN_14198cb00(*(Unk_HouseMarkInfo const*)(Unk_CMISHouseInfo const*)&(*FUN_141128800(&FUN_1411285a0(reinterpret_cast<Unk_CMISIter<274>*>(&it))->second)));
            }
        }
    }
    for (CMISMap_int_MS2Ptr_UICubeUGCHead::iterator itMark = reinterpret_cast<CMISMap_int_MS2Ptr_UICubeUGCHead*>(&f228)->begin(); (itMark != reinterpret_cast<CMISMap_int_MS2Ptr_UICubeUGCHead*>(&f228)->end()); ++itMark) {
        Unk_CMISPolyObj* pObj = FUN_1411284c0(&FUN_141128600(reinterpret_cast<Unk_CMISIter<273>*>(&itMark))->second);
        pObj->vfunc_2();
    }
}
// @0x1410bc320
void CubeMapInformationService::FUN_1410bc320()
{
    Unk_CMISHouseMark* pHouse = FUN_1410dc020();
    if (pHouse != 0)
        ((UIHouseMark*)(Unk_CMISHouseMark*)(pHouse))->FUN_14198cf50();
    for (CMISMap_int_MS2Ptr_UICubeUGCHead::iterator itMark = reinterpret_cast<CMISMap_int_MS2Ptr_UICubeUGCHead*>(&f228)->begin(); (itMark != reinterpret_cast<CMISMap_int_MS2Ptr_UICubeUGCHead*>(&f228)->end()); ++itMark) {
        Unk_CMISPolyObj* pObj = FUN_1411284c0(&FUN_141128600(reinterpret_cast<Unk_CMISIter<273>*>(&itMark))->second);
        pObj->vfunc_3();
    }
}

// @0x1410bf250
void CubeMapInformationService::IncrementKeyCount(const CString* pKey)
{
    if ((reinterpret_cast<CMISEMap_CString_int*>(&f358)->find(*pKey) != reinterpret_cast<CMISEMap_CString_int*>(&f358)->end())) {
        int n = *((int*)FUN_1411280d0((void*)(&f358), (void*)(pKey)));
        n++;
        *((int*)FUN_1411280d0((void*)(&f358), (void*)(pKey))) = n;
    } else {
        *((int*)FUN_1411280d0((void*)(&f358), (void*)(pKey))) = 1;
    }
}
// @0x1410bf320
void CubeMapInformationService::DecrementKeyCount(const CString* pKey)
{
    if ((reinterpret_cast<CMISEMap_CString_int*>(&f358)->find(*pKey) != reinterpret_cast<CMISEMap_CString_int*>(&f358)->end())) {
        int n = *((int*)FUN_1411280d0((void*)(&f358), (void*)(pKey)));
        if (0 < n)
            n = n - 1;
        *((int*)FUN_1411280d0((void*)(&f358), (void*)(pKey))) = n;
    }
}
// @0x1410bf3e0
int CubeMapInformationService::GetKeyCount(const CString* pKey)
{
    if ((reinterpret_cast<CMISEMap_CString_int*>(&f358)->find(*pKey) != reinterpret_cast<CMISEMap_CString_int*>(&f358)->end())) {
        int nVal = *((int*)FUN_1411280d0((void*)(&f358), (void*)(pKey)));
        return nVal;
    }
    return 0;
}
// @0x1410c3e00
unsigned char CubeMapInformationService::FUN_1410c3e00(int nKey) { return *((unsigned char*)FUN_141128310((void*)(&f368), (void*)(&nKey))); }
// @0x1410c3e40
void CubeMapInformationService::FUN_1410c3e40(int nKey, unsigned char v) { *((unsigned char*)FUN_141128310((void*)(&f368), (void*)(&nKey))) = v; }
// @0x1410c3e80
int CubeMapInformationService::FUN_1410c3e80(int nKey)
{
    if ((reinterpret_cast<CMISEMap_KindB_int*>(&f378)->find(*reinterpret_cast<const Unk_CMISKindB*>(&nKey)) == reinterpret_cast<CMISEMap_KindB_int*>(&f378)->end()))
        return 0;
    return *((int*)FUN_141128290((void*)(&f378), (void*)(&nKey)));
}
// @0x1410c3f10
void CubeMapInformationService::FUN_1410c3f10(int nKey, int v) { *((int*)FUN_141128290((void*)(&f378), (void*)(&nKey))) = v; }
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
void CubeMapInformationService::FUN_1410d5ab0() { ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<Cube>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<Cube>>>, 0>>*)(void*)(&f98))->size(); }
// @0x1410d5ae0
void CubeMapInformationService::FUN_1410d5ae0(int v) { f450 = v; }
// @0x1410d5b00
int CubeMapInformationService::FUN_1410d5b00() { return f450; }
// @0x1410cb8b0
void CubeMapInformationService::SetTimerEnabled(bool b)
{
    f248 = b;
    if (f248)
        f24c = GetTickCountMs2();
}
// @0x1410cb920
bool CubeMapInformationService::HasTimerExpired(int n)
{
    if (!f248)
        return false;
    return GetTickCountMs2() > (unsigned)(f24c + n);
}
// @0x1410d2ee0
int CubeMapInformationService::FUN_1410d2ee0() { return reinterpret_cast<const CMISEMap_int_Cell*>(&fb8)->empty(); }
// @0x1410d2f10
int CubeMapInformationService::FUN_1410d2f10() { return CFieldData::FUN_140374410(WorldService::GetInstance()->FUN_141bd3060()); }
// @0x1410d2f40
int CubeMapInformationService::FUN_1410d2f40(int nKey)
{
    if ((reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->find(nKey) != reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->end()))
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
    CMISEMap_KindA_int::const_iterator it = reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->find(*reinterpret_cast<const Unk_CMISKindA*>(&nKey));
    if ((it == reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->end()))
        return 0;
    return FUN_1411284e0(reinterpret_cast<Unk_CMISIter<282>*>(&it))->m_val;
}
// @0x1410d55d0
void CubeMapInformationService::FUN_1410d55d0(int a, int b)
{
    if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130()) {
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
    Unk_CMISInsRes res;
    if ((reinterpret_cast<CMISSet_u_int64*>(&f430)->find(key) != reinterpret_cast<CMISSet_u_int64*>(&f430)->end()))
        return;
    FUN_1404422b0(&f430, &res, &key);
}
// @0x1410d5830
void CubeMapInformationService::FUN_1410d5830(unsigned __int64 key)
{
    if ((reinterpret_cast<CMISSet_u_int64*>(&f430)->find(key) == reinterpret_cast<CMISSet_u_int64*>(&f430)->end()))
        return;
    ((std::_Tree<std::_Tset_traits<unsigned __int64, std::less<unsigned __int64>, std::allocator<unsigned __int64>, 0>>*)(void*)(&f430))->erase(*(unsigned __int64 const*)(&key));
}
// @0x1410d58c0
bool CubeMapInformationService::FUN_1410d58c0(unsigned __int64 key)
{
    if ((reinterpret_cast<CMISSet_u_int64*>(&f430)->find(key) != reinterpret_cast<CMISSet_u_int64*>(&f430)->end()))
        return true;
    return false;
}
// @0x1410d5930
void CubeMapInformationService::FUN_1410d5930(Unk_CMISTree<286>* pOut)
{
    Unk_CMISInsRes res;
    for (CMISSet_u_int64::iterator it = reinterpret_cast<CMISSet_u_int64*>(&f430)->begin(); (it != reinterpret_cast<CMISSet_u_int64*>(&f430)->end()); ++it)
        FUN_1404422b0(pOut, &res, ((unsigned __int64*)(&*it)));
}
// @0x1410c5420
void* CubeMapInformationService::FindPhysXActor(Unk_CMISEntityRef key)
{
    if (reinterpret_cast<CMISEMap_EntityID_int64*>(&f48)->find(*reinterpret_cast<const egf::EntityID*>(&key)) == reinterpret_cast<CMISEMap_EntityID_int64*>(&f48)->end())
        return 0;
    return *reinterpret_cast<void**>(FUN_141128110(&f48, &key));
}
// @0x1410cb420
int CubeMapInformationService::ContainsEntityRef(Unk_CMISEntityRef ref)
{
    for (CMISEMap_int_EntityID::iterator it = reinterpret_cast<CMISEMap_int_EntityID*>(&f108)->begin(); (it != reinterpret_cast<CMISEMap_int_EntityID*>(&f108)->end()); ++it) {
        if (reinterpret_cast<const egf::EntityID&>(ref).operator==(reinterpret_cast<const egf::EntityID&>(reinterpret_cast<const Unk_1401cd100&>(FUN_1411286a0(reinterpret_cast<Unk_CMISIter<265>*>(&it))->m_ref))))
            return 1;
    }
    return 0;
}
// @0x1410d2730
int CubeMapInformationService::IsCellInBounds(Unk_Int3 pt)
{
    if (FUN_1410c3180() != 0) {
        if (pt.x < p300.x || pt.y < p300.y)
            return 0;
        if (pt.x > p30c.x || pt.y > p30c.y)
            return 0;
    }
    return 1;
}
// @0x1410d4340
int CubeMapInformationService::FUN_1410d4340(Unk_CubePoint* pOut)
{
    if (((MS2Ptr<CFieldDataCli>*)(void*)(&f208))->operator==(0))
        return 0;
    if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130() == 0)
        return 0;
    memcpy(pOut, &p300, 12);
    return 1;
}
// @0x1410c4d80
void CubeMapInformationService::FUN_1410c4d80(const Vector3& pt, float fDist)
{
    FUN_1408a15b0(pt, DAT_143b01a60);
    FUN_1410c2840(pt, fDist);
}
// @0x1410c68e0
bool CubeMapInformationService::ClearCubes()
{
    ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<Cube>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<Cube>>>, 0>>*)(void*)(&f98))->clear();
    ((std::_Tree<std::_Tmap_traits<egf::EntityID, MS2Ptr<Cube>, std::less<egf::EntityID>, efd::CustomAllocator<std::pair<egf::EntityID const, MS2Ptr<Cube>>>, 0>>*)(void*)(&fa8))->clear();
    ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<Cube>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<Cube>>>, 0>>*)(void*)(&fb8))->clear();
    ((class Unk_CubeHeightIndex*)(void*)(&f2a8))->Clear();
    ((std::_Tree<std::_Tmap_traits<int, efd::set<int, std::less<int>>, std::less<int>, efd::CustomAllocator<std::pair<int const, efd::set<int, std::less<int>>>>, 0>>*)(void*)(&fd8))->clear();
    ((std::_Tree<std::_Tmap_traits<int, std::map<int, MS2Ptr<Cube>, std::less<int>, std::allocator<std::pair<int const, MS2Ptr<Cube>>>>, std::less<int>, efd::CustomAllocator<std::pair<int const, std::map<int, MS2Ptr<Cube>, std::less<int>, std::allocator<std::pair<int const, MS2Ptr<Cube>>>>>>, 0>>*)(void*)(&fc8))->clear();
    FUN_1402237c0((struct Unk_LevelArray*)(&a458));
    return true;
}
// @0x1410d2340
int CubeMapInformationService::ArePointsWithinRange2D(const Unk_CMISPt2* a, const Unk_CMISPt2* b, float fLimX, float fLimY)
{
    int bX = FUN_14029d220(a->x - b->x) <= fLimX;
    int bY = FUN_14029d220(a->y - b->y) <= fLimY;
    return bX & bY;
}
// @0x1410caa60
void CubeMapInformationService::FUN_1410caa60(const CString* pKey, int v)
{
    if ((reinterpret_cast<CMISEMap_CString_int*>(&f1a0)->find(*pKey) != reinterpret_cast<CMISEMap_CString_int*>(&f1a0)->end()))
        reinterpret_cast<CMISEMap_CString_int*>(&f1a0)->erase(*pKey);
    *((int*)FUN_1411280d0((void*)(&f1a0), (void*)(pKey))) = v;
}
// @0x1410c51d0
void CubeMapInformationService::SetOwnerName(int nA, int nB, CStringW strName)
{
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB);
    if (spOwner == 0)
        return;
    spOwner->ownerName = strName;
}
// @0x1410c8030
__int64 CubeMapInformationService::GetOwnerId(int nA, int nB)
{
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB);
    if (spOwner == 0)
        return 0;
    return spOwner->ownerID;
}
// @0x1410cba80
int CubeMapInformationService::FUN_1410cba80(int nDir, int nField50, Unk_Int3* pCell, Unk_CMISPt3* pPos)
{
    Cube* pCube = GetCubeAtCell(*pCell);
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
void CubeMapInformationService::AddOwner(Unk_CubeOwnerPtr spOwner)
{
    if (reinterpret_cast<CMISMap_u64_CubeOwnerPtr*>(&f148)->find(*reinterpret_cast<const unsigned __int64*>(&spOwner->ownerID)) == reinterpret_cast<CMISMap_u64_CubeOwnerPtr*>(&f148)->end())
        (*reinterpret_cast<CMISMap_u64_CubeOwnerPtr*>(&f148))[*reinterpret_cast<const unsigned __int64*>(&spOwner->ownerID)] = spOwner;
}
// @0x1410ce4b0
void CubeMapInformationService::RemoveOwner(Unk_CubeOwnerPtr spOwner)
{
    if (reinterpret_cast<CMISMap_u64_CubeOwnerPtr*>(&f148)->find(*reinterpret_cast<const unsigned __int64*>(&spOwner->ownerID)) != reinterpret_cast<CMISMap_u64_CubeOwnerPtr*>(&f148)->end())
        reinterpret_cast<CMISEMap_u64_MS2Ptr_UidRecord*>(&f148)->erase(*reinterpret_cast<const unsigned __int64*>(&spOwner->ownerID));
}
// @0x1410c5280
void CubeMapInformationService::FUN_1410c5280(int nKey)
{
    if ((reinterpret_cast<CMISEMap_int_EntityID*>(&f2c8)->find(nKey) != reinterpret_cast<CMISEMap_int_EntityID*>(&f2c8)->end())) {
        RemovePhysXActor(*((struct Unk_CMISEntityRef*)FUN_141127ed0((void*)(&f2c8), (void*)(&nKey))));
        ((std::_Tree<std::_Tmap_traits<int, egf::EntityID, std::less<int>, efd::CustomAllocator<std::pair<int const, egf::EntityID>>, 0>>*)(void*)(&f2c8))->erase(*(int const*)(&nKey));
    }
}
// @0x1410c5340
void CubeMapInformationService::RemovePhysXActor(Unk_CMISEntityRef ref)
{
    void* pObj = FindPhysXActor(ref);
    if (pObj != 0) {
        Unk_CMISPhysScene* pScene = ((class Unk_CMISPhysScene*)((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a1c0());
        if (pScene != 0) {
            ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a540(0);
            pScene->RemoveActor(pObj);
            ((class WorldService*)(class Unk_CMISWorld*)(reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())))->FUN_141bc8e00();
            ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a570();
            reinterpret_cast<CMISEMap_EntityID_int64*>(&f48)->erase(*reinterpret_cast<const egf::EntityID*>(&ref));
            reinterpret_cast<CMISEMap_EntityID_PropPtr*>(&f58)->erase(*reinterpret_cast<const egf::EntityID*>(&ref));
        }
    }
}
// @0x1410c6070
void CubeMapInformationService::DestroyFloorPhysX()
{
    if (f40 != 0) {
        Unk_CMISPhysScene* pScene = ((class Unk_CMISPhysScene*)((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a1c0());
        if (pScene != 0) {
            ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a540(0);
            pScene->RemoveActor(f40);
            ((class WorldService*)(class Unk_CMISWorld*)(reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())))->FUN_141bc8e00();
            ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a570();
        }
        f40 = 0;
    }
}
// @0x1410c6820
void CubeMapInformationService::RemovePhysActor(int nIdx)
{
    if (f318[nIdx] != 0) {
        Unk_CMISPhysScene* pScene = ((class Unk_CMISPhysScene*)((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a1c0());
        if (pScene != 0) {
            ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a540(0);
            pScene->RemoveActor(f318[nIdx]);
            ((class WorldService*)(class Unk_CMISWorld*)(reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())))->FUN_141bc8e00();
            ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a570();
        }
        f318[nIdx] = 0;
    }
}
// @0x1410c3020
void CubeMapInformationService::FUN_1410c3020(int nField)
{
    f1b0 = nField;
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&it)))) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->second);
        if (spCube->field48 != 0)
            continue;
        spCube->field54 = nField;
    }
}
// @0x1410c54a0
Vector3 CubeMapInformationService::FUN_1410c54a0(Unk_EntRef spEnt)
{
    Vector3 ptRes(150.0f, 150.0f, 150.0f);
    Vector3 ptProp;
    reinterpret_cast<egf::Entity*>(((const egf::EntityPtr*)(&spEnt))->operator->())->GetPropertyValue<efd::Point3>(0xcb086a2d, (efd::Point3&)(ptProp));
    if (ptProp.FUN_140552700(DAT_143b01a60))
        ptRes = ptProp;
    return ptRes;
}
// @0x1410ce560
void CubeMapInformationService::FUN_1410ce560()
{
    Unk_CMISIter<260> itOld;
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()); FUN_141129b00(reinterpret_cast<Unk_CMISIter<260>*>(&it), &itOld, 0))
        FUN_1410c1910(FUN_1408a0400(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->first), 1);
}
// @0x1410ce310
int CubeMapInformationService::FUN_1410ce310()
{
    int nCount = 0;
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&it)))) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->second);
        if (spCube.get() != 0) {
            if (FUN_1408b5620(((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20()) != 0)
                nCount = nCount + 1;
        }
    }
    return nCount;
}
// @0x1410d33a0
int CubeMapInformationService::TryGetHouseMarkPosition(int nKey, Vector3* pOut)
{
    if ((reinterpret_cast<CMISMap_int_MS2Ptr_SalesInfo*>(&f238)->find(nKey) != reinterpret_cast<CMISMap_int_MS2Ptr_SalesInfo*>(&f238)->end())) {
        *pOut = FUN_141128470(((struct Unk_CMISHousePtr*)FUN_141127c50((void*)(&f238), (void*)(&nKey))))->m_pt;
        return 1;
    }
    return 0;
}
// @0x1410c7f60
CStringW CubeMapInformationService::GetOwnerName(int nA, int nB)
{
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB);
    if (spOwner == 0)
        return CStringW(L"");
    return CStringW(spOwner->ownerName);
}
// @0x1410d5b20
void CubeMapInformationService::SendRequestCubeMode68(__int64 nId)
{
    if (((std::_Tree<std::_Tset_traits<egf::EntityID, std::less<egf::EntityID>, efd::CustomAllocator<egf::EntityID>, 0>>*)(void*)(&f78))->empty()) {
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.WriteUInt8(0x44);
        packet.WriteInt64(nId);
        FUN_140710590(packet);
        f478 = 0;
    } else {
        f478 = nId;
    }
}
// @0x1410ce800
efd::SyncResult CubeMapInformationService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    (pRegistrar)->AddDependency<egf::FlatModelManager>(1);
    (pRegistrar)->AddDependency<efd::MessageService>(1);
    Unk_CMISNotifyA((struct Unk_CMISSink*)(pRegistrar), 1);
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
class Unk_CMISLog { public: unsigned __int64 FUN_140353fc0(int nLevel, int nCategory, const wchar_t* pFormat, const int* pA); unsigned __int64 FUN_1403d7960(int nLevel, int nCategory, const wchar_t* pFormat, const int* pA, const int* pB); unsigned __int64 FUN_1410db4f0(int nLevel, int nCategory, const wchar_t* pFormat, const int& a, const int& b, const int& c); };
class CLogString* GetLogString();   // C3: was FUN_140166440
void Unk_AdditionalLog(class CLogString*, int, int, const wchar_t*);
struct Unk_CMISEntId { Unk_CMISEntId(const Unk_CMISEntId&); __int64 m_id; };
CCubeMotionManager* GetCubeMotionManager();
struct Unk_CMISSlot;
class Unk_CMISMagicCube : public CFunctionCubeService { public: Unk_CMISSlot FUN_141230f60(Vector3 ptPos, float fRange, __int64 nPc); };
class CFunctionCubeService* FUN_1409670b0();   // C3: was FUN_1409670b0
CStringW Unk_ArcWide(const wchar_t* pSz, int n);
struct Unk_CMISPairRes { Unk_CMISPairRes(const Unk_CMISPairRes&); int m_a, m_b; };
Unk_CMISPairRes FUN_14111d460(const int& a, const int& b);                                          // make_pair
void** FUN_141128090(Unk_CMISTree<263>*, const Unk_CMISPairRes&);                                    // operator[]
void* FUN_141128410(void** pSecond);                                                                 // the raw pointer of the value
Unk_CMISIter<276>* FUN_141151df0(Unk_CMISTree<276>*, Unk_CMISIter<276>*);                            // end
Unk_CMISIter<276>* FUN_141157c80(Unk_CMISTree<276>*, Unk_CMISIter<276>*, const int*);                // find
unsigned char FUN_140d7b400(Unk_CMISIter<276>*, Unk_CMISIter<276>*);                                          // operator!=
struct Unk_CMISObj498;
template <> struct Unk_CMISIter<284> { void* node; };
void* FUN_141128b30(Unk_CMISIter<284>*);                                                             // operator*
int FUN_14112e110(Unk_CMISObj498*);                                                                  // the object id
char* FUN_141127e90(void*, struct Unk_Key*);   // C3: was FUN_141127e90
struct Unk_CMISHandle388 { void* m_a; void* m_p; void* m_c; };
struct Unk_CMISHandle3a8 { void* m_a; void* m_p; void* m_c; };
class Unk_HomeSlot;   // C3: forward decl for a rewritten call
struct Unk_CMISHandle16* FUN_14112dfe0(struct Unk_CMISArr16*, unsigned __int64);   // C3: was FUN_14112dfe0
void FUN_14112d9b0(ATL::CAtlArray<Unk_CMISElem3a8*>*, const Unk_CMISHandle3a8*);                    // Add
class Unk_BlueprintSlot;   // C3: forward decl for a rewritten call
struct Unk_CMISHandle16* FUN_14112e020(struct Unk_CMISArr16*, unsigned __int64);   // C3: was FUN_14112e020
void FUN_14112da60(ATL::CAtlArray<Unk_CMISElem388*>*, const Unk_CMISHandle388*);                    // Add
unsigned __int64 FUN_14112d900(struct Unk_CMISArr16*, void const*);   // C3: was FUN_14112d900

// @0x1410c2840
bool CubeMapInformationService::FUN_1410c2840(Vector3 pt, float fDist)
{
    int nKey = FUN_1408a03c0(*reinterpret_cast<Unk_Int3*>(&pt));
    if (reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->find(nKey) == reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()) {
        ((class Unk_CMISLog*)GetLogString())->FUN_1410db4f0(1, 0x13, L"[ERROR] No cube on that position = {0}, {1}, {2}", reinterpret_cast<const int&>(pt.x), reinterpret_cast<const int&>(pt.y), reinterpret_cast<const int&>(pt.z));
        return false;
    }
    MS2Ptr<Cube> spCube(*FUN_141127cd0(&f98, &nKey));
    Vector3 kRot;
    reinterpret_cast<egf::Entity*>(((const egf::EntityPtr*)(&spCube->entity))->operator->())->GetPropertyValue<efd::Point3>(0x68c7c29d, (efd::Point3&)(kRot));
    reinterpret_cast<float&>(spCube->fieldD4) = fDist;
    ((CCubeMotionManager*)GetCubeMotionManager())->AddRotate(((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID(), kRot.z, fDist, 200);
    ((class Unk_CMISMagicCube*)FUN_1409670b0())->FUN_141232330(nKey, fDist);
    return true;
}
// @0x1410c3330
void CubeMapInformationService::FUN_1410c3330(CStringW* pOut)
{
    CStringW s = FUN_1410c31d0();
    if ((s != L""))
        *pOut = s;
    else
        *pOut = Unk_ArcWide(*((class WorldService*)(class Unk_CMISWorld*)(reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())))->FUN_141bd3080(), 0);
}
// @0x1410c79a0
void CubeMapInformationService::FUN_1410c79a0(int nA, int nB)
{
    if ((reinterpret_cast<CMISEMap_std_pair_int_int_MS2Ptr_SaleStateData*>(&fe8)->find(std::make_pair(nA, nB)) == reinterpret_cast<CMISEMap_std_pair_int_int_MS2Ptr_SaleStateData*>(&fe8)->end()) != 0)
        return;
    reinterpret_cast<CMISEMap_std_pair_int_int_MS2Ptr_SaleStateData*>(&fe8)->erase(std::make_pair(nA, nB));
}
// @0x1410c7c20
void* CubeMapInformationService::FUN_1410c7c20(int nA, int nB)
{
    if ((reinterpret_cast<CMISEMap_std_pair_int_int_MS2Ptr_SaleStateData*>(&fe8)->find(std::make_pair(nA, nB)) == reinterpret_cast<CMISEMap_std_pair_int_int_MS2Ptr_SaleStateData*>(&fe8)->end()) != 0)
        return 0;
    return FUN_141128410(FUN_141128090(&fe8, FUN_14111d460(nA, nB)));
}
// @0x1410cdf60
int CubeMapInformationService::FUN_1410cdf60(Unk_Int3* pA, Unk_Int3* pB)
{
    int nKey = FUN_1408a03c0(static_cast<const Unk_DkPoint&>(*pA) + static_cast<const Unk_DkPoint&>(*pB));
    if ((reinterpret_cast<CMISEMap_int_KindA*>(&f298)->find(nKey) != reinterpret_cast<CMISEMap_int_KindA*>(&f298)->end()))
        return 1;
    return 0;
}
// @0x1410c92e0
void CubeMapInformationService::RemoveFunctionCubeObject(int nId)
{
    CMISSet_MS2Ptr_CFunctionCubeObject::iterator it;
    for (it = reinterpret_cast<CMISSet_MS2Ptr_CFunctionCubeObject*>(&f498)->begin(); it != reinterpret_cast<CMISSet_MS2Ptr_CFunctionCubeObject*>(&f498)->end(); it++) {
        if (FUN_14112e110(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(FUN_141128b30(reinterpret_cast<Unk_CMISIter<284>*>(&it))))->operator->())) == nId) {
            ((class CFunctionCubeObject*)(struct Unk_CMISObj498*)(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(FUN_141128b30(reinterpret_cast<Unk_CMISIter<284>*>(&it))))->operator->())))->HideNotice();
            reinterpret_cast<CMISSet_MS2Ptr_CFunctionCubeObject*>(&f498)->erase(it);
            break;
        }
    }
}
// @0x1410cb380
void CubeMapInformationService::AddEntityRef(Unk_Int3 pt, const Unk_CMISEntityRef& ref)
{
    if (ContainsEntityRef(ref) != 0)
        return;
    int nKey = FUN_1408a13d0(*reinterpret_cast<Vector3*>(&pt));
    *(egf::EntityID*)(((struct Unk_CMISEntityRef*)FUN_141127e90((void*)(&f108), (struct Unk_Key*)(&nKey)))) = *(const egf::EntityID*)&(ref);
}
// @0x1410d59c0
void CubeMapInformationService::FUN_1410d59c0(ATL::CAtlArray<MS2Ptr<Cube>>* pOut)
{
    for (unsigned __int64 i = 0; i < ((ATL::CAtlArray<int, ATL::CElementTraits<int>>*)(void*)(&a458))->GetCount(); i++) {
        int nKey = (*(ATL::CAtlArray<int>*)(&a458))[i];
        if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->find(nKey) != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()))
            FUN_14112d900((struct Unk_CMISArr16*)(pOut), (void const*)(FUN_141127cd0(&f98, &nKey)));
    }
}

// ---- w138 batch 2 ----
struct Unk_CMISStr { __int64 m_a, m_b, m_c, m_d; };                                          // efd::utf8string (0x20)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_1407071e0(int);   // C3: was FUN_1407071e0
int FUN_140707260(int);   // C3: was FUN_140707260
Unk_CMISStr* FUN_14112cdc0(Unk_CMISStr* pStr, const char* pSz);                              // operator+=
Unk_CMISStr* FUN_14112cd90(Unk_CMISStr* pStr, Unk_CMISStr* pAdd);                            // operator+=
Unk_CMISStr* FUN_1409989e0(Unk_CMISStr* pStr, const char* pSz);                              // ctor
Unk_CMISStr* FUN_14115afa0(Unk_CMISStr* pStr, Unk_CMISStr* pOut, unsigned __int64 nPos, unsigned __int64 nLen);   // substr
void FUN_1408a8900(Unk_CMISStr* pStr);                                                       // dtor

// @0x1410b77e0
int CubeMapInformationService::FUN_1410b77e0(int nItemId, Unk_CMISStr* pOut)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return 0;
    if (FUN_1407071e0(spItem->install.objCode) != 0) {
        if (FUN_140707260(spItem->install.objCode) != 0)
            *reinterpret_cast<efd::utf8string*>(pOut) = "urn:gamebryo-animation:";
        else
            *reinterpret_cast<efd::utf8string*>(pOut) = "urn:gamebryo-scenegraph:";
    } else {
        *reinterpret_cast<efd::utf8string*>(pOut) = "urn:gamebryo-scenegraph:";
    }
    if (FUN_1410cb980(nItemId) != 0) {
        FUN_14112cdc0(pOut, "Empty");
    } else if (spItem.get() != 0) {
        efd::utf8string sPath((const char*)spItem->install.asset);
        __int64 nSlash = sPath.find_last_of("/", (unsigned __int64)-1);
        __int64 nDot = sPath.find_last_of(".", (unsigned __int64)-1);
        efd::utf8string sName = sPath.substr(nSlash + 1, (nDot - nSlash) - 1);
        if (sName.length() != 0)
            FUN_14112cd90(pOut, (Unk_CMISStr*)&sName);
        else
            FUN_14112cdc0(pOut, "Empty");
    }
    return 1;
}
// @0x1410c5570
void CubeMapInformationService::FUN_1410c5570(Unk_EntRef spEnt)
{
    bool bFlag = false;
    ((egf::Entity*)reinterpret_cast<egf::EntityPtr&>(spEnt).operator->())->GetPropertyValue(0x38141815, bFlag);
    if (bFlag == false)
        return;
    Vector3 pt = FUN_1410c54a0(spEnt);
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
    char m_aName[32];                                                                       // +0 efd::utf8string (copied by 0x1409a0f10)
    Vector3 m_pos;                                                                  // +0x20
    Vector3 m_rot;                                                                  // +0x2c
};
MS2_CHECK_SIZE(Unk_CMISCell56, 56);
char* FUN_141127b10(void*, struct Unk_Key*);   // C3: was FUN_141127b10
// @0x1410c2610
bool CubeMapInformationService::FUN_1410c2610(Unk_Int3 pt)
{
    int nKey = FUN_1408a03c0(pt);
    if ((reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->find(nKey) != reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->end()) != 0) {
        int nGroup = 0, nFloor = 0;
        Cube* pCube = GetCubeAtCell(pt);
        if (pCube != 0) {
            nGroup = pCube->field50;
            nFloor = pCube->field54;
        }
        FUN_1410c1910(pt, 1);
        if (bool bOk = true) {
            int nKey2 = FUN_1408a03c0(pt);
            Unk_CMISCell56 val(*((struct Unk_CMISCell56*)FUN_141127b10((void*)(&f2b8), (struct Unk_Key*)(&nKey2))));
            FUN_1410be0c0(pt, nGroup, nFloor, &val);
        }
    }
    else {
        FUN_1410c1910(pt, 0);
        return false;
    }
    return true;
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
void CubeMapInformationService::FUN_1410c2a90(int nGroup)
{
    if ((reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->find(nGroup) == reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->end()) != 0) {
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[ERROR] SalePost entity doesn't exist");
        return;
    }
    Unk_CMISKeySet set;
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&it)))) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->second);
        if (spCube->field48 == 0)
            continue;
        if (spCube->field50 != nGroup)
            continue;
        FUN_14115a8a0(&set, FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it)));
    }
    Unk_CMISKeySet* pSet = &set;
    Unk_CMISSetIter tEnd, tBegin;
    Unk_CMISSetIter itSetEnd = *FUN_141152510(pSet, &tEnd);
    Unk_CMISSetIter itSet = *FUN_14114e8d0(pSet, &tBegin);
    for (; FUN_14076cf90(&itSet, &itSetEnd); FUN_14076d080(&itSet)) {
        int nCell = *FUN_14076d030(&itSet);
        FUN_1410c2610(FUN_1408a0400(nCell));
    }
}
struct Unk_CMISEntSet { __int64 m_a, m_b, m_c, m_d, m_e; };                                                 // set<entity id> (ctor 0x141122da0, dtor 0x141125d50)
void FUN_141122da0(Unk_CMISEntSet*);
void FUN_141125d50(Unk_CMISEntSet*);
void FUN_141126870(Unk_CMISEntSet*, Unk_CMISEntSet*);                                       // assign
void FUN_14115a990(Unk_CMISEntSet*, const Unk_CMISEntityRef*);                              // insert
Unk_CMISIter<271>* FUN_141151cd0(Unk_CMISTree<271>*, Unk_CMISIter<271>*);                   // end
Unk_CMISIter<271>* FUN_1411579e0(Unk_CMISTree<271>*, Unk_CMISIter<271>*, const int*);       // find
unsigned char FUN_141126ed0(Unk_CMISIter<271>*, Unk_CMISIter<271>*);                        // operator!=
char* FUN_141127e50(void*, void*);   // C3: was FUN_141127e50
void FUN_14098c6e0(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0
// @0x1410c2ce0
void CubeMapInformationService::FUN_1410c2ce0(egf::Entity* pEntity)
{
    if (f218 != 0 && ((void*)((MS2Ptr<CFieldDataCli>*)(void*)(&f208))->get()) != 0) {
        if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375100() == 0) {
        Vector3 pt = DAT_143b01a60;
        reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(pt));
        int nFound = 0;
        for (unsigned __int64 nFloor = 1; nFloor <= f218->floors.size(); ++nFloor) {
            int nKey = (int)nFloor;
            if (f218->floors.find(nKey) == f218->floors.end())
                continue;
            int nKey2 = (int)nFloor;
            Unk_UGCFloor& floor = f218->floors[nKey2];
            if (floor.startHeight <= pt.z)
                nFound = (int)nFloor;
        }
        if (nFound != 0) {
            if ((reinterpret_cast<CMISEMap_int_vector_Entity*>(&f1e8)->find(nFound) == reinterpret_cast<CMISEMap_int_vector_Entity*>(&f1e8)->end()) != 0) {
                std::vector<egf::EntityID, efd::CustomAllocator<egf::EntityID>> setNew;
                FUN_141126870(((struct Unk_CMISEntSet*)FUN_141127e50((void*)(&f1e8), (void*)(&nFound))), reinterpret_cast<Unk_CMISEntSet*>(&setNew));
            }
            Unk_CMISEntSet* pSet = ((struct Unk_CMISEntSet*)FUN_141127e50((void*)(&f1e8), (void*)(&nFound)));
            FUN_14115a990(pSet, ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(pEntity))->GetEntityID()));
            if (f1e0 != nFound) {
                bool bFlag = false;
                FUN_14098c6e0((class Unk_CachedEntity*)(pEntity), 0xa0b6b179, *(bool const*)(&bFlag));
            }
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
    if ((reinterpret_cast<CMISEMap_KindB_u_char*>(&f368)->find(*reinterpret_cast<const Unk_CMISKindB*>(&nKey)) == reinterpret_cast<CMISEMap_KindB_u_char*>(&f368)->end()) != 0)
        return false;
    if (*((unsigned char*)FUN_141128310((void*)(&f368), (void*)(&nKey))) == 0)
        return false;
    int nState = FUN_1410c3e80(nKey);
    if (nState != 0) {
        if (FUN_1410c3180() == DAT_143ab2820 && nState == 1)
            return false;
        if (nState == 2) {
            if (FUN_1410c3180() == DAT_143ab2820)
                return false;
            Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
            if (pRoster == 0)
                return true;
            if (((MyPC*)pRoster)->FUN_141527920((void*)FUN_1410c3180()) != 0)
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
    void* m_0;
    void* m_p;                                                                              // object at +8 (ctor 0x14111ea00)
    void* FUN_141128410();                                                                  // operator bool
    Unk_CMISHouseRec* FUN_1411284b0();                                                      // operator->
};
MS2_CHECK_SIZE(Unk_CMISHouseRef, 0x10);   // 8 bytes overflowed the locals the exe's ctors fill at +8
// @0x1410c8470
int CubeMapInformationService::FUN_1410c8470(int nA, int nB, int* pState, __int64* pValue)
{
    int nFlag = 0;
    FUN_1408a0890(nB, nA, &nFlag);
    int nIsOne = 0;
    if (nFlag == 1)
        nIsOne = 1;
    Unk_CMISHouseRef spHouse(FUN_1410c7c20(nA, nIsOne));
    if (spHouse.FUN_141128410() != 0 && (spHouse.FUN_1411284b0()->m_state == 4 || spHouse.FUN_1411284b0()->m_state == 1)) {
        *pState = spHouse.FUN_1411284b0()->m_state;
        *pValue = spHouse.FUN_1411284b0()->m_value;
        return 1;
    }
    return 0;
}
struct Unk_CMISPartyRef                                                                     // MS2Ptr<party info>
{
    Unk_CMISPartyRef(void* p);                                                              // 0x14050dd40
    ~Unk_CMISPartyRef();                                                                    // 0x14050de40
    void* m_vtbl;                                                                           // MS2Ptr: vtable, then the pointee at +8
    void* m_p;
    void* FUN_140fa9d30();                                                                  // operator bool
    Unk_CMISParty* FUN_14050dee0();                                                         // operator->
};
MS2_CHECK_SIZE(Unk_CMISPartyRef, 0x10);
struct Unk_CMISSalable { Unk_CMISSalable(); ~Unk_CMISSalable(); void* m_pad0[4]; int m_nField20; int m_pad24; void* m_pad28[15]; int m_nHideEmoticon; unsigned m_nTrophyId; void* m_pad1[3]; };   // 0xc0 like Unk_UGCGroup; ctor 0x1408ad110, dtor 0x14050de70
int FUN_1408a0d30(int, struct Unk_UGCGroup&, int);   // C3: was FUN_1408a0d30
// @0x1410c80d0
bool CubeMapInformationService::IsGroupSalableAndUnowned(int nGroup)
{
    int nMap = WorldService::GetInstance()->FUN_141bd3060();
    Unk_CMISSalable salable;
    if (FUN_1408a0d30(nGroup, *(struct Unk_UGCGroup*)(&salable), nMap) == 0)
        return false;
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, 0);
    if (spOwner == static_cast<CubeOwner*>(0))
        return true;
    return false;
}
// @0x1410c8580
int CubeMapInformationService::FUN_1410c8580(int nGroup)
{
    Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (((MyPC*)(Unk_CMISRoster*)(pRoster))->HasNoHome() == 0) {
        Unk_CMISPartyRef spParty(((MyPC*)pRoster)->FUN_141523c50());
        if (spParty.FUN_140fa9d30() != 0) {
            if (spParty.FUN_14050dee0()->m_map == WorldService::GetInstance()->FUN_141bd3060() && spParty.FUN_14050dee0()->m_key == nGroup)
                return 0x31;
        }
    }
    if (IsGroupSalableAndUnowned(nGroup) == 0)
        return 0x2f;
    return 0;
}
// @0x1410c78b0
Unk_CubeOwnerMap* CubeMapInformationService::GetGroupOwners(int nGroup)
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
};
class Unk_CMISInvMgr;
Unk_CMISIter<282>* FUN_14114e470(Unk_CMISTree<282>*, Unk_CMISIter<282>*);                   // begin
Unk_CMISIntPair* FUN_1411287a0(Unk_CMISIter<282>*);                                         // operator*
void* FUN_141129cd0(struct Unk_TreeIter*);   // C3: was FUN_141129cd0
// @0x1410d50c0
unsigned __int64 CubeMapInformationService::FUN_1410d50c0()
{
    unsigned __int64 nTotal = 0;
    Unk_CMISInv* pInv = ((class Unk_CMISInv*)&((class UGCCubeCategoryTable*)(class Unk_CMISInvMgr*)(reinterpret_cast<Unk_CMISInvMgr*>(TSingleton<UGCCubeCategoryTable>::GetInstance())))->GetBonusInteriors());
    for (__int64 pos = pInv->FUN_140ebb080(); pos != 0; pInv->FUN_140ebb030(&pos)) {
        Unk_CMISInvPtr spSlot(pInv->FUN_140ebb100(pos));
        if (spSlot.FUN_141126ad0(0) != 0)
            continue;
        nTotal += spSlot.FUN_140889010()->m_count;
    }
    return nTotal;
}
// @0x1410d4fa0
unsigned __int64 CubeMapInformationService::FUN_1410d4fa0()
{
    unsigned __int64 nTotal = 0;
    Unk_CMISInv* pInv = ((class Unk_CMISInv*)&((class UGCCubeCategoryTable*)(class Unk_CMISInvMgr*)(reinterpret_cast<Unk_CMISInvMgr*>(TSingleton<UGCCubeCategoryTable>::GetInstance())))->GetBonusInteriors());
    for (CMISEMap_KindA_int::iterator it = reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->begin(); (it != reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->end()); FUN_141129cd0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<282>*>(&it)))) {
        int nItem = FUN_1411287a0(reinterpret_cast<Unk_CMISIter<282>*>(&it))->m_key;
        unsigned nNeed = FUN_1411287a0(reinterpret_cast<Unk_CMISIter<282>*>(&it))->m_val;
        Unk_CMISInvPtr spSlot(0);
        if (((ATL::CAtlMap<ECubeCategory, Unk_CubePtr<UGCCubeCategoryTable::Interior>, ATL::CElementTraits<ECubeCategory>, ATL::CElementTraits<Unk_CubePtr<UGCCubeCategoryTable::Interior>>>*)(Unk_CMISInv*)(pInv))->Lookup(*(ECubeCategory const*)(&nItem), *(Unk_CubePtr<UGCCubeCategoryTable::Interior>*)(Unk_CMISInvPtr*)(&spSlot)) != 0) {
            if (nNeed >= spSlot.FUN_140889010()->m_need)
                nTotal += spSlot.FUN_140889010()->m_count;
        }
    }
    return nTotal;
}
// @0x1410d5190
void CubeMapInformationService::FUN_1410d5190(unsigned __int64* pCubes, unsigned __int64* pOthers)
{
    Unk_CMISInv* pInv = ((class Unk_CMISInv*)&((class UGCCubeCategoryTable*)(class Unk_CMISInvMgr*)(reinterpret_cast<Unk_CMISInvMgr*>(TSingleton<UGCCubeCategoryTable>::GetInstance())))->GetBonusInteriors());
    for (CMISEMap_KindA_int::iterator it = reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->begin(); (it != reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->end()); FUN_141129cd0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<282>*>(&it)))) {
        int nItem = FUN_1411287a0(reinterpret_cast<Unk_CMISIter<282>*>(&it))->m_key;
        unsigned nNeed = FUN_1411287a0(reinterpret_cast<Unk_CMISIter<282>*>(&it))->m_val;
        Unk_CMISInvPtr spSlot(0);
        if (((ATL::CAtlMap<ECubeCategory, Unk_CubePtr<UGCCubeCategoryTable::Interior>, ATL::CElementTraits<ECubeCategory>, ATL::CElementTraits<Unk_CubePtr<UGCCubeCategoryTable::Interior>>>*)(Unk_CMISInv*)(pInv))->Lookup(*(ECubeCategory const*)(&nItem), *(Unk_CubePtr<UGCCubeCategoryTable::Interior>*)(Unk_CMISInvPtr*)(&spSlot)) != 0) {
            if (nNeed >= spSlot.FUN_140889010()->m_need)
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
void CubeMapInformationService::SendRequestCubeMode31()
{
    for (CMISEMap_int_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->begin(); (it != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&it)))) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&it))->second);
        if (spCube.get() != 0) {
            Unk_Int3 pos = spCube->position;
            if (pos.x < p300.x || pos.x > p30c.x || pos.y < p300.y || pos.y > p30c.y || pos.z < p300.z || pos.z > f2fc) {
                COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
                packet.WriteUInt8(0x1f);
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
void FUN_14112da60(ATL::CAtlArray<Unk_CMISElem388*>*, const Unk_CMISDesignPtr*);          // Add
// @0x1410d4450
void CubeMapInformationService::FUN_1410d4450(__int64 nId, int nIdx, CStringA strName, __int64 nValue)
{
    if (FUN_1410c3180() != nId)
        return;
    for (unsigned __int64 i = 0; i < ((ATL::CAtlArray<MS2Ptr<Unk_BlueprintSlot>, ATL::CElementTraits<MS2Ptr<Unk_BlueprintSlot>>>*)(void*)(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle388>*>(&a388)))->GetCount(); i++) {
        Unk_CMISDesignPtr spInfo(*((struct Unk_CMISHandle388*)FUN_14112e020((struct Unk_CMISArr16*)(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle388>*>(&a388)), i)));
        if (spInfo.FUN_141128430() != 0 && spInfo.FUN_140fac700()->m_id == nIdx) {
            spInfo.FUN_140fac700()->m_name = strName;
            spInfo.FUN_140fac700()->m_value = nValue;
            return;
        }
    }
    Unk_CMISDesignPtr spNew(reinterpret_cast<Unk_CMISDesignInfo*>(new UGCMapDesignInfo));
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
void FUN_14112d9b0(ATL::CAtlArray<Unk_CMISElem3a8*>*, const Unk_CMISBlueprintPtr*);          // Add
// @0x1410d4710
void CubeMapInformationService::FUN_1410d4710(__int64 nId, int nIdx, CStringA strName, __int64 nValue)
{
    if (FUN_1410c3180() != nId)
        return;
    for (unsigned __int64 i = 0; i < ((ATL::CAtlArray<MS2Ptr<Unk_HomeSlot>, ATL::CElementTraits<MS2Ptr<Unk_HomeSlot>>>*)(void*)(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle3a8>*>(&a3a8)))->GetCount(); i++) {
        Unk_CMISBlueprintPtr spInfo(*((struct Unk_CMISHandle3a8*)FUN_14112dfe0((struct Unk_CMISArr16*)(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle3a8>*>(&a3a8)), i)));
        if (spInfo.FUN_141128420() != 0 && spInfo.FUN_140fac6f0()->m_id == nIdx) {
            spInfo.FUN_140fac6f0()->m_name = strName;
            spInfo.FUN_140fac6f0()->m_value = nValue;
            return;
        }
    }
    Unk_CMISBlueprintPtr spNew(reinterpret_cast<Unk_CMISBlueprintInfo*>(new UGCMapBlueprintInfo));
    spNew.FUN_140fac6f0()->m_id = nIdx;
    spNew.FUN_140fac6f0()->m_name = strName;
    spNew.FUN_140fac6f0()->m_value = nValue;
    FUN_14112d9b0(&a3a8, &spNew);
}
// @0x1410d4680
void CubeMapInformationService::FUN_1410d4680(ATL::CAtlArray<Unk_CMISHandle3a8>* pSrc)
{
    for (unsigned __int64 i = 0; i < ((ATL::CAtlArray<MS2Ptr<Unk_HomeSlot>, ATL::CElementTraits<MS2Ptr<Unk_HomeSlot>>>*)(void*)(pSrc))->GetCount(); i++) {
        Unk_CMISBlueprintPtr h(*((struct Unk_CMISHandle3a8*)FUN_14112dfe0((struct Unk_CMISArr16*)(pSrc), i)));
        FUN_14112d9b0(&a3a8, &h);
    }
}
// @0x1410d43c0
void CubeMapInformationService::FUN_1410d43c0(ATL::CAtlArray<Unk_CMISHandle388>* pSrc)
{
    for (unsigned __int64 i = 0; i < ((ATL::CAtlArray<MS2Ptr<Unk_BlueprintSlot>, ATL::CElementTraits<MS2Ptr<Unk_BlueprintSlot>>>*)(void*)(pSrc))->GetCount(); i++) {
        Unk_CMISDesignPtr h(*((struct Unk_CMISHandle388*)FUN_14112e020((struct Unk_CMISArr16*)(pSrc), i)));
        FUN_14112da60(&a388, &h);
    }
}
// ---- w138 batch 6 ----
bool FUN_1411272b0(const Unk_Int3*, const Unk_Int3*);
efd::Point3 FUN_1408a15b0(Unk_Int3, const Vector3&);
Unk_Int3 FUN_1408a15b0(Unk_Int3, Vector3&);   // same function; 12-byte result temp (0x1410cb1b0)                              // the world point of a cell (writes the xy centre)                                        // operator==
// @0x1410d2da0
int CubeMapInformationService::FUN_1410d2da0(int nKey, Unk_Int3 pt)
{
    if ((reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->find(nKey) == reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()))
        return 0;
    int nResult = 0;
    Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nKey)));
    for (CMISESet_int::iterator it = reinterpret_cast<CMISESet_int*>(pList)->begin(); (it != reinterpret_cast<CMISESet_int*>(pList)->end()); ++it) {
        int nCell = *((int*)(&*it));
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
int CubeMapInformationService::FUN_1410d23f0(int nGroup, int nBlock)
{
    int nHeight = 0;
    bool bNoOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock) == 0;
    if (bNoOwner)
        return nHeight;
    if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130() != 0) {
        nHeight = f2fc;
    } else if (f218 != 0) {
        if (f218->groups.find(nGroup) != f218->groups.end())
            nHeight = f218->groups[nGroup].heightLimit;
    }
    return nHeight;
}
// @0x1410d2130
int CubeMapInformationService::FUN_1410d2130(Cube* pCube, int nDir, float fSize, float* pOutXY, Vector3* pOutPt)
{
    Vector3 ptCenter;
    FUN_1408a15b0(pCube->position, ptCenter);
    float fHalfSize = fSize * 0.5f;
    float fHalf = 75.0f + fHalfSize;
    *pOutPt = DAT_143b01a60;
    switch (nDir) {
    case 1:
        pOutPt->z = 225.0f;
        reinterpret_cast<Unk_CMISPt2*>(pOutXY)->x = ptCenter.x - fHalf;
        reinterpret_cast<Unk_CMISPt2*>(pOutXY)->y = ptCenter.y + fHalf;
        return 1;
    case 3:
        pOutPt->z = 135.0f;
        reinterpret_cast<Unk_CMISPt2*>(pOutXY)->x = ptCenter.x + fHalf;
        reinterpret_cast<Unk_CMISPt2*>(pOutXY)->y = ptCenter.y + fHalf;
        return 1;
    case 5:
        pOutPt->z = 45.0f;
        reinterpret_cast<Unk_CMISPt2*>(pOutXY)->x = ptCenter.x + fHalf;
        reinterpret_cast<Unk_CMISPt2*>(pOutXY)->y = ptCenter.y - fHalf;
        return 1;
    case 7:
        pOutPt->z = 315.0f;
        reinterpret_cast<Unk_CMISPt2*>(pOutXY)->x = ptCenter.x - fHalf;
        reinterpret_cast<Unk_CMISPt2*>(pOutXY)->y = ptCenter.y - fHalf;
        return 1;
    }
    return 0;
}
class Unk_PCCubeCraft   // C3: member view for the former free stand-ins
{
public:
    int GetMode();
};
// @0x1410d2590
int CubeMapInformationService::FUN_1410d2590(Unk_Int3 pt, int nGroup, int nBlock)
{
    Unk_Int3 cell = pt;
    cell.z = cell.z - 1;
    int nHeight = FUN_1410d23f0(nGroup, nBlock);
    if (nHeight == 0)
        return 1;
    Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pRoster == 0)
        return 0;
    if (((MyPC*)pRoster)->GetActiveCubeCraft() == 0)
        return 0;
    Cube* pCube = 0;
    if (((class Unk_PCCubeCraft*)(void*)(((MyPC*)pRoster)->GetActiveCubeCraft()))->GetMode() != 2)
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
void CubeMapInformationService::FUN_1410c3fc0(PCBase* pActor, float* pOutLo, float* pOutHi)
{
    if (f218 == 0) {
        *pOutLo = 0.0f;
        *pOutHi = 0.0f;
        return;
    }
    Vector3 ptFront;
    GetCellInFrontOfActor(pActor, 0, &ptFront, 0);
    Vector3 ptCell;
    GetCellPosition(ptFront, &ptCell);
    int nFound = 0;
    for (unsigned __int64 nFloor = 1; nFloor <= (unsigned __int64)(__int64)f1dc; ++nFloor) {
        int nKey = (int)nFloor;
        if (f218->floors.find(nKey) == f218->floors.end())
            continue;
        int nKey2 = (int)nFloor;
        Unk_UGCFloor& floor = f218->floors[nKey2];
        if (floor.startHeight <= ptCell.z)
            nFound = (int)nFloor;
    }
    if (nFound == 0)
        return;
    Unk_UGCFloor& floor = f218->floors[nFound];
    *pOutLo = floor.startHeight;
    *pOutHi = floor.startHeight + (float)floor.field4 * 150.0f;
}
// ---- w138 batch 4 ----
struct Unk_CMISItemData { char pad[0x1c4]; int field1c4; };
class Unk_CMISItemRef                                                                       // item ptr passed by value (the callee destroys it)
{
public:
    ~Unk_CMISItemRef();                                                                     // 0x1401b50d0
    void* FUN_140203c60();
    void* m_unknown;
    void* m_pObject;
};
unsigned char FUN_140930c90(__int64 nOwner);
unsigned char FUN_140930d20(__int64 nOwner);
extern int DAT_143ae0fb4;
// @0x1410c6980
int CubeMapInformationService::FUN_1410c6980(Cube* pCube, int nKind, Unk_CMISItemRef rItem, __int64 nOwner, int nMode)
{
    if (DAT_143ae0fb4 != 0)
        return 1;
    if (FUN_1408a07b0(WorldService::GetInstance()->FUN_141bd3060(), DAT_1439f4a7c, DAT_143ab2820))
        return 1;
    switch (nMode) {
    case 3: {
        if ((((void*)reinterpret_cast<MS2Ptr<CItemData>&>(rItem).operator CItemData*()) ? true : false) && reinterpret_cast<Unk_CMISItemData*>(reinterpret_cast<const MS2Ptr<CItemData>&>(rItem).operator->())->field1c4 != 0)
            return 0;
        __int64 nCur = GetOwnerId(pCube->field50, pCube->field54);
        if (nCur != nOwner && !FUN_140930c90(nCur) && !FUN_140930d20(nCur))
            return 0;
        break;
    }
    case 4: {
        __int64 nCur = GetOwnerId(pCube->field50, pCube->field54);
        if (nCur != nOwner && !FUN_140930c90(nCur) && !FUN_140930d20(nCur))
            return 0;
        break;
    }
    }
    return 1;
}
struct Unk_CMISSaleState { Unk_CMISSaleState(); char m_pad[0x28]; };                        // ctor 0x141123290
// @0x1410c7a50
void CubeMapInformationService::FUN_1410c7a50(int nA, int nB, int nState, __int64 nValue)
{
    if ((reinterpret_cast<CMISEMap_std_pair_int_int_MS2Ptr_SaleStateData*>(&fe8)->find(std::make_pair(nA, nB)) == reinterpret_cast<CMISEMap_std_pair_int_int_MS2Ptr_SaleStateData*>(&fe8)->end()) != 0) {
        Unk_CMISHouseRef spNew(new Unk_CMISSaleState());
        *reinterpret_cast<Unk_PayloadPtr<NoticeCubeInfo>*>(FUN_141128090(&fe8, FUN_14111d460(nA, nB))) =
            reinterpret_cast<const Unk_PayloadPtr<NoticeCubeInfo>&>(spNew);      // 0x141126340 (ICF)
    }
    Unk_CMISHouseRef spHouse(FUN_141128090(&fe8, FUN_14111d460(nA, nB)));
    spHouse.FUN_1411284b0()->m_state = nState;
    spHouse.FUN_1411284b0()->m_value = nValue;
    FUN_1410bbcd0(nA, nB);
}
// @0x1410c81c0
int CubeMapInformationService::FUN_1410c81c0(int nGroup, int* pnWidth, int* pnHeight, int* pnDepth)
{
    *pnWidth = 0;
    *pnHeight = 0;
    *pnDepth = 0;
    if (((MS2Ptr<CFieldDataCli>*)(void*)(&f208))->operator==(0))
        return 0;
    if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130())
        nGroup = 1;
    if ((reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->find(nGroup) == reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()))
        return 0;
    int nMinX = 0x7fffffff, nMaxX = -0x7fffffff - 1;
    int nMinY = 0x7fffffff, nMaxY = -0x7fffffff - 1;
    Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nGroup)));
    for (CMISESet_int::iterator it = reinterpret_cast<CMISESet_int*>(pList)->begin(); (it != reinterpret_cast<CMISESet_int*>(pList)->end()); ++it) {
        int nCell = *((int*)(&*it));
        Unk_Int3 pt = FUN_1408a0400(nCell);
        Cube* pCube = FUN_1410b8980(pt);
        if (pCube == 0)
            continue;
        if (pt.x < nMinX)
            nMinX = pt.x;
        if (pt.x > nMaxX)
            nMaxX = pt.x;
        if (pt.y < nMinY)
            nMinY = pt.y;
        if (pt.y > nMaxY)
            nMaxY = pt.y;
    }
    *pnWidth = nMaxX - nMinX + 1;
    *pnHeight = f218->groups[nGroup].heightLimit + 1;
    *pnDepth = nMaxY - nMinY + 1;
    return 1;
}
// @0x1410c88b0
int CubeMapInformationService::FUN_1410c88b0(PCBase* pActor)
{
    if (f218 == 0)
        return 0;
    Vector3 ptFront;
    GetCellInFrontOfActor(pActor, 0, &ptFront, 0);
    Vector3 ptCell;
    GetCellPosition(ptFront, &ptCell);
    int nFound = 0;
    for (unsigned __int64 nFloor = 1; nFloor <= (unsigned __int64)(__int64)f1dc; ++nFloor) {
        int nKey = (int)nFloor;
        if (f218->floors.find(nKey) == f218->floors.end())
            continue;
        int nKey2 = (int)nFloor;
        Unk_UGCFloor& floor = f218->floors[nKey2];
        if (floor.startHeight <= ptCell.z)
            nFound = (int)nFloor;
    }
    return nFound;
}
// @0x1410ca900
int CubeMapInformationService::FUN_1410ca900(int nGroup)
{
    Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pRoster == 0)
        return 0;
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
    if (spOwner == 0)
        return 0;
    if (spOwner->ownerID == ((PC*)pRoster)->FUN_141656ad0()) {
        Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nGroup)));
        if ((reinterpret_cast<CMISESet_int*>(pList)->begin() != reinterpret_cast<CMISESet_int*>(pList)->end()))
            return 1;
    }
    return 0;
}
// @0x1410cdd80
int CubeMapInformationService::FUN_1410cdd80(Vector3* pFrom, Vector3* pTo, float fDist, Unk_Int3* pOffset)
{
    if (DAT_143ae0fb4 != 0)
        return 1;
    if (FUN_1408a07b0(WorldService::GetInstance()->FUN_141bd3060(), DAT_1439f4a7c, DAT_143ab2820))
        return 1;
    Vector3 ptHit;
    FUN_1410b7ba0(*pFrom, *pTo, -fDist, &ptHit, 0);
    Unk_Int3 kCell = FUN_1408a1430(ptHit);
    kCell = static_cast<const Unk_DkPoint&>(kCell) + static_cast<const Unk_DkPoint&>(*pOffset);
    int nKey = FUN_1408a03c0(kCell);
    if ((reinterpret_cast<CMISEMap_int_KindA*>(&f298)->find(nKey) != reinterpret_cast<CMISEMap_int_KindA*>(&f298)->end()))
        return 1;
    return 0;
}
struct Unk_EntityAppFramework;
extern Unk_EntityAppFramework DAT_143b059e8;
class Unk_HwService* FUN_14098c5b0(struct Unk_EntityAppFramework*);   // C3: was FUN_14098c5b0
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
void CubeMapInformationService::FUN_1410cef70(const egf::EntityChangeMessage* pMsg, efd::Category)
{
    if (reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())->GetState() == 6)
        return;
    egf::Entity* pEntity = ((egf::EntityChangeMessage*)(void*)(pMsg))->GetEntity();
    Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
    if ((spInst.FUN_14098d090() ? true : false) && spInst.FUN_14098d0e0()->FUN_1413d6890(pEntity) != 0)
        return;
    if (reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())->GetState() != 4)
        FUN_1410cf160(pEntity);
    else
        FUN_1410cf5c0(pEntity);
    Vector3 pt = DAT_143b01a60;
    reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(pt));
    int nKey = FUN_1408a13d0(pt);
    Cube* pCube = GetCubeByKey(nKey);
    if (pCube != 0)
        ((class Cube*)(class Cube*)(pCube))->FUN_1408b4fd0(pEntity);
    FUN_1410c5280(nKey);
}
class UIMainPlayerInfo;
UIMainPlayerInfo* FUN_140931900(int nUiId);
UIHomeInfoDialog* FUN_140bbea00(int nId);
class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10
class NotifyChangeUIBuildingCount : public NotifyObject                                     // 0x20 bytes, ctor 0x141123250
{
public:
    NotifyChangeUIBuildingCount(const int* pCount);
    virtual CStringW GetTypeName();                                                         // 0x140db55e0
    int m_nCount;
};
// @0x1410ce1e0
void CubeMapInformationService::FUN_1410ce1e0(int nNotify, const int* pCount)
{
    UIMainPlayerInfo* nInfo = FUN_140931900(0x4e5f);
    if (nInfo == 0)
        return;
    if (nNotify != 0) {
        Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pRoster == 0)
            return;
        UIHomeInfoDialog* pDlg = FUN_140bbea00(0x4ed8);
        if (pDlg != 0 && pDlg->vfunc_9() != 0)
            pDlg->FUN_1412c5690();
        ((class NotifySystem*)FUN_140939a10())->Post(MS2Ptr<NotifyObject>(new NotifyChangeUIBuildingCount(pCount)));
    }
}
int FUN_1408b56c0(MS2Ptr<CItemData> spItem);
int FUN_1408b58c0(MS2Ptr<CItemData> spItem);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
// @0x1410ce020
void CubeMapInformationService::FUN_1410ce020(MS2Ptr<Cube> spCube)
{
    if (spCube == 0)
        return;
    int nItemId = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return;
    if (spItem->FUN_14053d940() || FUN_1408b56c0(spItem) != 0 || FUN_1408b58c0(spItem) != 0) {
        Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pRoster != 0) {
            if (((PC*)pRoster)->FUN_141656ad0() == GetOwnerId(spCube->field50, spCube->field54))
                FUN_1410ce1e0(1, &nItemId);
        }
    }
}
CStringW GetStringCommon(int nStringId);
// @0x1410c7ce0
CStringW CubeMapInformationService::FUN_1410c7ce0(int nA, int nB)
{
    CStringW strText;
    bool bHasOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB) != 0;
    if (bHasOwner)
        return strText;
    strText = GetStringCommon(0x7e7);
    int nState = 2;
    Unk_CMISHouseRef spHouse(FUN_1410c7c20(nA, nB));
    if (spHouse.FUN_141128410() != 0)
        nState = spHouse.FUN_1411284b0()->m_state;
    if (nState == 4)
        strText = GetStringCommon(0x7e8);
    if (IsGroupSalableAndUnowned(nA) == 0)
        strText = GetStringCommon(0x7e9);
    return strText;
}
// @0x1410c8670
int CubeMapInformationService::FUN_1410c8670(int nGroup, int* pnFlag)
{
    int nResult = 0;
    Unk_CMISRoster* pPC = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC == 0)
        return nResult;
    int nMapId = WorldService::GetInstance()->FUN_141bd3060();
    *pnFlag = 0;
    FUN_1408a0890(nMapId, nGroup, pnFlag);
    int bOne = 0;
    if (*pnFlag == 1)
        bOne = 1;
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, bOne);
    if (spOwner.get() != 0) {
        if (spOwner->ownerID == ((PC*)pPC)->FUN_141656ad0()) {
            nResult = 2;
        } else {
            if (TSingleton<CBuddyManager>::GetInstance()->FUN_140ae52d0(nMapId, nGroup) != 0)
                nResult = 3;
            else
                nResult = 3;
        }
    } else {
        if (((MyPC*)(Unk_CMISRoster*)(pPC))->HasNoHome() == 0) {
            Unk_CMISPartyRef spParty(((MyPC*)pPC)->FUN_141523c50());
            if (spParty.FUN_14050dee0()->m_key == nGroup) {
                if (spParty.FUN_14050dee0()->m_map == WorldService::GetInstance()->FUN_141bd3060())
                    nResult = 2;
            }
        }
        int nState = 2;
        Unk_CMISHouseRef spHouse(FUN_1410c7c20(nGroup, bOne));
        if (spHouse.FUN_141128410() != 0)
            nState = spHouse.FUN_1411284b0()->m_state;
        if (nState == 4)
            nResult = 1;
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
struct Unk_CMISConsts { char m_pad_00[0x128]; CString m_strCubeFlash0; CString m_strCubeFlash1; CString m_strCubeFlash2; CString m_strCubeFlash3; CString m_strCubeFlash4; char m_pad_150[0x2a0 - 0x150]; CString m_strRemoveEffect; CString m_strHouseEffect; char m_pad_2b0[0x300 - 0x2b0]; CString m_strSaleEffect; CString m_strCubeEffect; };   // game-wide constants (the sale-post effect name at +0x300)
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0
bool FUN_1411273c0(Unk_CMISIter<264>*, Unk_CMISIter<264>*);                                 // operator!=
char* FUN_141127b90(void*, void*);   // C3: was FUN_141127b90
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                                            // the scene root of an entity
extern NiRTTI DAT_143afa4d8;
// @0x1410c4240
void CubeMapInformationService::FUN_1410c4240(int nGroup, int nBlock, const CStringW& strName, __int64 nUnused, __int64 nOwnerId)
{
    bool bHasOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock).get() != 0;
    if (bHasOwner)
        return;
    FUN_1408a10e0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock, strName, nOwnerId);
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
    if (spOwner.get() != 0)
        AddOwner(spOwner);
    if ((reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->find(nGroup) != reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->end())) {
        Unk_EffectTarget request;
        request.m_strName = ((struct Unk_CMISConsts*)FUN_1401d31f0())->m_strSaleEffect;
        request.m_nKind = 7;
        *reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&reinterpret_cast<Unk_CMISEffReq&>(request).m_pSlot10) = (NiAVObject*)(NiObject::DynamicCast(&DAT_143afa4d8, (class NiObject const*)(FUN_141b6efc0(((const egf::EntityPtr*)(((struct Unk_CMISEntityRef*)FUN_141127b90((void*)(&ff8), (void*)(&nGroup)))))->operator egf::Entity*()))));
        TSingleton<CEffectService>::GetInstance()->FUN_1411a4a00(request);
    }
}
// @0x1410c44b0
void CubeMapInformationService::FUN_1410c44b0(int nGroup, int nBlock, int bFlag)
{
    if ((reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->find(nGroup) == reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()) != 0) {
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[ERROR] Cant' find salable group to sell");
        return;
    }
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
    if (spOwner == 0) {
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[ERROR] Can't find salable group to sell");
        return;
    }
    if ((reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->find(nGroup) == reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->end()) != 0) {
        Unk_AdditionalLog(GetLogString(), 1, 0x13, L"[ERROR] Can't find salable group to sell");
        return;
    }
    if (bFlag != 0)
        FUN_1410c2a90(nGroup);
    Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pRoster != 0) {
        if (((PC*)pRoster)->FUN_141656ad0() == spOwner->ownerID)
            FUN_1410ccc00(nGroup, 0, 0);
    }
    FUN_1408a0eb0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
    RemoveOwner(spOwner);
    FUN_1410cd440();
    if ((reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->find(nGroup) != reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->end())) {
        Unk_EffectTarget request;
        request.m_strName = ((struct Unk_CMISConsts*)FUN_1401d31f0())->m_strSaleEffect;
        request.m_nKind = 7;
        *reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&reinterpret_cast<Unk_CMISEffReq&>(request).m_pSlot10) = (NiAVObject*)(NiObject::DynamicCast(&DAT_143afa4d8, (class NiObject const*)(FUN_141b6efc0(((const egf::EntityPtr*)(((struct Unk_CMISEntityRef*)FUN_141127b90((void*)(&ff8), (void*)(&nGroup)))))->operator egf::Entity*()))));
        TSingleton<CEffectService>::GetInstance()->FUN_1411a4a00(request);
    }
}
// ---- w138 batch 5 ----
struct Unk_CMISBlock { Unk_CMISBlock(const Unk_CMISBlock&); ~Unk_CMISBlock(); void* m_a; void* m_b; };   // copy 14111e680, dtor 141123760
struct Unk_CMISObjHandle { void* m_a; void* m_b; };
struct Unk_CMISObjRec { char pad[0x40]; int nKind; };
class Unk_CMISWorldMgr : public EntityWorldManager { public: egf::EntityPtr FUN_1411ce7c0(efd::utf8string, efd::utf8string, NiPoint3, NiPoint3, float, int, int); };
int FUN_140707660(int);
Unk_CMISIter<266>* FUN_1411519d0(Unk_CMISTree<266>*, Unk_CMISIter<266>*);
Unk_CMISIter<266>* FUN_1411572e0(Unk_CMISTree<266>*, Unk_CMISIter<266>*, const int*);
bool FUN_141127400(Unk_CMISIter<266>*, Unk_CMISIter<266>*);                // operator!=
char* FUN_141127bd0(void*, struct Unk_Key*);   // C3: was FUN_141127bd0
void FUN_14111d290(Unk_CMISTree<267>*, Unk_CMISInsRes*, const int*);      // insert
MS2Ptr<Cube>* FUN_141128190(Unk_CMISTree<259>*, const Unk_CMISEntityRef*);
unsigned int FUN_1408a0190(int);   // C3: was FUN_1408a0190
void FUN_1408a0480(Cube*);
// @0x1410bd080
bool CubeMapInformationService::FUN_1410bd080(__int64 nOwner, Unk_Int3 pt, float fRot, CubeItemInfo* pInfo, const efd::utf8string& strName,
    int nField50, int nField54, unsigned char bField4c, int nUnused, int nFieldD8, Unk_PayloadPtr<NoticeCubeInfo> spNotice)
{
    if (pInfo == 0)
        return false;
    int nItemId = pInfo->itemId;
    int nCell = FUN_1408a03c0(pt);
    if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->find(nCell) != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()))
        return false;
    NiPoint3 ptCell = reinterpret_cast<const NiPoint3&>(DAT_143b01a60);
    FUN_1408a15b0(pt, reinterpret_cast<Vector3&>(ptCell));
    NiPoint3 ptRot = reinterpret_cast<const NiPoint3&>(DAT_143b01a60);
    ptRot.z = fRot;
    int nObjProp = 0;
    int nObjCode = 0;
    CItemData* pItem = FUN_14053f870(nItemId);
    if (pItem == 0)
        return false;
    nObjCode = FUN_1408a0190(((class CItemData*)(class CItemData*)(pItem))->GetSubtype());
    nObjProp = pItem->install.animatable;
    egf::EntityPtr spEnt(0);
    if (FUN_1407071e0(pItem->install.objCode) != 0) {
        int nTreeKey = FUN_1407072e0(pItem->install.objCode);
        int nAnim = FUN_140707660(pItem->install.objCode);
        if (nTreeKey != 0 && (reinterpret_cast<CMISEMap_int_MS2Ptr_FittingDollData*>(&f118)->find(nCell) != reinterpret_cast<CMISEMap_int_MS2Ptr_FittingDollData*>(&f118)->end())) {
            int nKey2 = FUN_1408a03c0(pt);
            Unk_CMISBlock rec(*((struct Unk_CMISBlock*)FUN_141127bd0((void*)(&f118), (struct Unk_Key*)(&nKey2))));
            spEnt = FUN_1410bc3d0(Unk_CMISBlock(rec));
            int nKey3 = FUN_1408a03c0(pt);
            ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<FittingDollData>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<FittingDollData>>>, 0>>*)(void*)(&f118))->erase(*(int const*)(&nKey3));
        } else if (FUN_1410c35c0() != 0 && nTreeKey != 0) {
            unsigned nIdx = f3d8;
            f3d8 = f3d8 + 1;
            if (nIdx >= 0x3fa)
                nIdx = 0x3fa;
            spEnt = FUN_1410bc7f0(reinterpret_cast<Vector3&>(ptCell), reinterpret_cast<Vector3&>(ptRot), nIdx, pInfo->itemId);
        } else {
            efd::utf8string strModel(FUN_140707260(pItem->install.objCode) != 0 ? "MS2FunctionCubeKFM" : "MS2FunctionCubeNIF");
            if (pItem->install.preset.GetLength() != 0)
                spEnt = static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411ce7c0(efd::utf8string((const char*)pItem->install.preset), efd::utf8string(""),
                    ptCell, ptRot, 1.0f, nObjProp, 0);
            else
                spEnt = static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411ce7c0(strModel, strName,
                    ptCell, ptRot, 1.0f, nObjProp, 0);
            if (nTreeKey != 0) {
                Unk_CMISInsRes itIns;
                FUN_14111d290(&f128, &itIns, &nCell);
            }
        }
        CObjectDataPtr spData = FUN_140704ec0(pItem->install.objCode);
        if (spData) {
            bool bPlay = true;
            if (FUN_1410c35c0() != 0 && (nTreeKey != 0 || nAnim != 0))
                bPlay = false;
            if (bPlay)
                ((class CFunctionCubeService*)(class Unk_CMISMagicCube*)(((class Unk_CMISMagicCube*)FUN_1409670b0())))->AddPendingCube(nCell, nObjCode, ((Unk_CMISObjRec*)spData.operator->())->nKind);
            if (spEnt != 0 && ((Unk_CMISObjRec*)spData.operator->())->nKind == 0xb) {
                bool bOff = false;
                FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&spEnt))->operator->()), 0xa0b6b179, *(bool const*)(&bOff));
            }
        }
    } else {
        if (pItem->install.preset.GetLength() != 0) {
            spEnt = static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411ce7c0(efd::utf8string((const char*)pItem->install.preset), efd::utf8string(""),
                ptCell, ptRot, 1.0f, nObjProp, 0);
        } else {
            spEnt = static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411ce7c0(efd::utf8string("MS2CubeProp"), strName,
                ptCell, ptRot, 1.0f, nObjProp, 0);
            if (nObjProp != 0 && spEnt != 0) {
                bool bFlag = false;
                if (spEnt.data()->GetPropertyValue(0x23f9860e, bFlag) == 0) {
                    if (pItem->install.useInstancing == 0) {
                        bool bOff = false;
                        FUN_14098c6e0((class Unk_CachedEntity*)(spEnt.data()), 0x23f9860e, *(bool const*)(&bOff));
                        bool bOff2 = false;
                        FUN_14098c6e0((class Unk_CachedEntity*)(spEnt.data()), 0xd9f313f2, *(bool const*)(&bOff2));
                    } else if (bFlag) {
                        bool bOn = true;
                        FUN_14098c6e0((class Unk_CachedEntity*)(spEnt.data()), 0xd9f313f2, *(bool const*)(&bOn));
                    }
                }
            }
        }
    }
    if (spEnt == 0)
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
    reinterpret_cast<float&>(spCube->fieldD4) = fRot;
    spCube->notice = spNotice;
    FUN_1408a0480(spCube.get());
    *FUN_141128190(&f78, ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spEnt))->operator->()))->GetEntityID())) = spCube;
    if (FUN_1407071e0(spCube->fieldB4) != 0)
        *FUN_141127cd0(&f88, &nCell) = spCube;
    return true;
}
// ---- w138 batch 6 ----
// @0x1410c4850
void CubeMapInformationService::FUN_1410c4850(__int64 nOwner, Unk_Int3 pt, CubeItemInfo* pInfo, float fRot, int nField50, int nField54,
    unsigned char bField4c, int nUnused, int nFieldD8, Unk_PayloadPtr<NoticeCubeInfo> spNotice)
{
    if (pInfo == 0)
        return;
    efd::utf8string strName;
    int nCell = FUN_1408a03c0(pt);
    if (reinterpret_cast<CMISEMap_int_EntityID*>(&f2e0)->find(nCell) != reinterpret_cast<CMISEMap_int_EntityID*>(&f2e0)->end()) {
        FUN_1410bca70(nOwner, pt, fRot, nField50, nField54, nUnused, nFieldD8);
    } else {
        if (FUN_1410b77e0(pInfo->itemId, reinterpret_cast<Unk_CMISStr*>(&strName)) != 0) {
            FUN_1410bd080(nOwner, pt, fRot, pInfo, strName, nField50, nField54, bField4c, nUnused,
                nFieldD8, Unk_PayloadPtr<NoticeCubeInfo>(spNotice));
            FUN_1410d4cb0(pInfo->itemId, true);
            if (FUN_1410cb900()) {
                if (FUN_1410c3600(1) != 0 || FUN_1410c3600(3) != 0)
                    FUN_1410d54f0(true);
            }
        }
    }
}
// @0x1410c4b50
void CubeMapInformationService::FUN_1410c4b50(Unk_Int3 pt, bool bKeep)
{
    Vector3 ptCell = DAT_143b01a60;
    FUN_1408a15b0(pt, ptCell);
    int nCell = FUN_1408a03c0(pt);
    if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->find(nCell) != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end())) {
        MS2Ptr<Cube> spCube = *FUN_141127cd0(&fb8, &nCell);
        if (spCube.get() != 0) {
            FUN_1410bec60(MS2Ptr<Cube>(spCube));
            FUN_1410d4cb0(((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20(), false);
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
void CubeMapInformationService::FUN_1410c4e20(__int64 nOwner, Unk_Int3 pt, CubeItemInfo* pInfo, float fRot, unsigned char bField4c, int nUnused, int nFieldD8)
{
    if (pInfo == 0)
        return;
    Vector3 ptCell = DAT_143b01a60;
    FUN_1408a15b0(pt, ptCell);
    MS2Ptr<Cube> spCube(GetCubeAtPoint(ptCell));
    if (spCube.get() != 0) {
        if (spCube->field48 != 0) {
            FUN_1410bec60(MS2Ptr<Cube>(spCube));
            FUN_1410d4cb0(((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20(), false);
            if (FUN_1410c35c0() != 0 && FUN_1410cb900())
                FUN_1410d54f0(true);
        }
        FUN_1410c1910(FUN_1408a1430(ptCell), 1);
        efd::utf8string strName;
        if (FUN_1410b77e0(pInfo->itemId, reinterpret_cast<Unk_CMISStr*>(&strName)) != 0) {
            FUN_1410bd080(nOwner, pt, fRot, pInfo, strName, spCube->field50, spCube->field54, bField4c, nUnused, nFieldD8, Unk_PayloadPtr<NoticeCubeInfo>(0));
            FUN_1410d4cb0(pInfo->itemId, true);
            if (FUN_1410c35c0() != 0 && FUN_1410cb900())
                FUN_1410d54f0(true);
        }
    } else {
        Unk_AdditionalLog(GetLogString(), 0xc, 0x13, L"Not Exist ReplaceCube");
    }
}
// ---- w138 batch 7 ----
struct Unk_CMISRec { char pad[0x3c]; Unk_CMISInvKey key; char pad2[0x50 - 0x3c - sizeof(Unk_CMISInvKey)]; int nSetId; };                                  // an item-table row (key at 0x3c)
struct Unk_CMISRecRef { void* m_a; void* m_b; };                                            // handle of an item-table row
class Unk_CMISItemTable;
Unk_CMISRecRef* FUN_1405566e0(Unk_CMISItemTable*, Unk_CMISRecRef* pOut, int nItemId);
__int64 FUN_140df5b00(Unk_CMISRecRef*);                                                     // the handle is set
Unk_CMISRec* FUN_14056d580(Unk_CMISRecRef*);                                                // operator->
void FUN_14056c300(Unk_CMISRecRef*);                                                        // dtor
char* FUN_1411281d0(void*, void*);   // C3: was FUN_1411281d0
// @0x1410d4cb0
void CubeMapInformationService::FUN_1410d4cb0(int nItemId, bool bAdd)
{
    Unk_CMISInv* pInv = ((class Unk_CMISInv*)&((class UGCCubeCategoryTable*)(class Unk_CMISInvMgr*)(reinterpret_cast<Unk_CMISInvMgr*>(TSingleton<UGCCubeCategoryTable>::GetInstance())))->GetBonusInteriors());
    MS2Ptr<ItemHousing> spHousing = TSingleton<CItemDataTable>::GetInstance()->GetHousing(nItemId);
    if (spHousing != 0) {
        Unk_CMISInvPtr spSlot(0);
        if (((ATL::CAtlMap<ECubeCategory, Unk_CubePtr<UGCCubeCategoryTable::Interior>, ATL::CElementTraits<ECubeCategory>, ATL::CElementTraits<Unk_CubePtr<UGCCubeCategoryTable::Interior>>>*)(Unk_CMISInv*)(pInv))->Lookup(*(ECubeCategory const*)(&spHousing->categoryIndex), *(Unk_CubePtr<UGCCubeCategoryTable::Interior>*)(Unk_CMISInvPtr*)(&spSlot)) != 0) {
            if (reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->find(*reinterpret_cast<const Unk_CMISKindA*>(&spHousing->categoryIndex)) == reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->end()) {
                if (bAdd)
                    *((int*)FUN_1411281d0((void*)(&f3c8), (void*)(&spHousing->categoryIndex))) = 1;
            } else {
                int nCount = *((int*)FUN_1411281d0((void*)(&f3c8), (void*)(&spHousing->categoryIndex)));
                if (bAdd) {
                    nCount++;
                } else {
                    nCount--;
                    if (nCount < 0)
                        nCount = 0;
                }
                *((int*)FUN_1411281d0((void*)(&f3c8), (void*)(&spHousing->categoryIndex))) = nCount;
            }
        }
    }
    int nTotal = 0;
    for (CMISEMap_KindA_int::iterator it = reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->begin(); (it != reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->end()); FUN_141129cd0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<282>*>(&it)))) {
        Unk_CMISInvKey key;
        key.m_item = FUN_1411287a0(reinterpret_cast<Unk_CMISIter<282>*>(&it))->m_key;
        key.m_need = FUN_1411287a0(reinterpret_cast<Unk_CMISIter<282>*>(&it))->m_val;
        Unk_CMISInvPtr spSlot2(0);
        if (((ATL::CAtlMap<ECubeCategory, Unk_CubePtr<UGCCubeCategoryTable::Interior>, ATL::CElementTraits<ECubeCategory>, ATL::CElementTraits<Unk_CubePtr<UGCCubeCategoryTable::Interior>>>*)(Unk_CMISInv*)(pInv))->Lookup(*(ECubeCategory const*)(Unk_CMISInvKey*)(&key), *(Unk_CubePtr<UGCCubeCategoryTable::Interior>*)(Unk_CMISInvPtr*)(&spSlot2)) != 0) {
            if (key.m_need >= spSlot2.FUN_140889010()->m_need)
                nTotal += spSlot2.FUN_140889010()->m_count;
        }
    }
    t3e0.FUN_140868750(100);
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
struct Unk_CMISCubeList { void* m_a; void* m_b; };
struct Unk_CMISCountMap { void* m_head; unsigned __int64 m_count; };
struct Unk_CMISCountIter { void* m_p; };
class SetItemEffectInfo : public CPtred                                                      // 0x28, ctor 0x1411233c0; cubemapinformationservice_tail.h layout
{
public:
    SetItemEffectInfo();
    int m_nEffect;
    CString m_strName;
};
class SalesInfo : public CPtred                                                              // 0x38, ctor 0x1411232e0; cubemapinformationservice_tail.h layout
{
public:
    SalesInfo();
    int m_nA;
    efd::Point3 m_pos;
    CStringW m_str;
    void* m_pTail;
};
class SaleStateData : public CPtred                                                          // 0x28, ctor 0x141123290; cubemapinformationservice_tail.h layout
{
public:
    SaleStateData();
    int m_nState;
    void* m_p;
};
class Unk_CMISFlatModel { public:  };                   // egf::FlatModel::ContainsModel
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
char* FUN_141128010(void*, struct Unk_Key*);   // C3: was FUN_141128010
void* FUN_14111e900(void*, void*);   // C3: was FUN_14111e900
__int64 FUN_141128400(Unk_CMISPieceRef*);                                                   // is set
bool FUN_141126b50(Unk_CMISPieceRef*, int);                                                 // operator==
Unk_CMISCountIter* FUN_140265b50(Unk_CMISCountMap*, Unk_CMISCountIter*);                    // begin
Unk_CMISCountIter* FUN_140265e30(Unk_CMISCountMap*, Unk_CMISCountIter*);                    // end
Unk_CMISCountIter* FUN_140266230(Unk_CMISCountMap*, Unk_CMISCountIter*, const int*);        // find
bool FUN_14025cdb0(Unk_CMISCountIter*, Unk_CMISCountIter*);                                 // operator!=
Unk_CMISIntPair* FUN_14025cf40(Unk_CMISCountIter*);                                         // operator*
void FUN_1403e8fb0(Unk_CMISCountIter*);                                                     // operator++
char* FUN_141127f90(void*, struct Unk_Key*);   // C3: was FUN_141127f90
Unk_CMISEffSvc* FUN_141b6f910();
void FUN_1409a1fc0(Unk_CMISEffSvc*, const Unk_CMISEntityRef*, const efd::utf8string*, float fScale, bool bFlag);
struct Unk_CMISLimits { char pad[8]; };
struct Unk_CMISLimitF { float m_f; };
struct Unk_CMISRules { char pad[0xf80]; Unk_CMISLimitF m_fAtF80; char padF84[0xfd8 - 0xf84]; Unk_CMISLimitF m_fNear; char pad2[0x1138 - 0xfdc]; Unk_CMISLimits m_limits1138; char pad2b[0x1190 - 0x1138 - sizeof(Unk_CMISLimits)]; Unk_CMISLimits m_limits1190; char pad2c[0x1348 - 0x1190 - sizeof(Unk_CMISLimits)]; Unk_CMISLimits m_limits1348; char pad3[0x5078 - 0x1348 - sizeof(Unk_CMISLimits)]; Unk_CMISLimits m_limits5078; char pad4[0xa288 - 0x5078 - sizeof(Unk_CMISLimits)]; Unk_CMISLimits m_limits; };   // game-wide rules (limit tables at 0x1348/0x5078/0xa288)
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
Unk_CMISIter<279>* FUN_1411574a0(Unk_CMISTree<279>*, Unk_CMISIter<279>*, const int*);
void FUN_141153af0(Unk_CMISTree<279>*, const int*);                                         // erase
// @0x1410bf610
// MS2-FUNCTIONAL: transliteration with typed stand-ins; iterator/ref temporaries are laid out differently from the exe
void CubeMapInformationService::FUN_1410bf610(Unk_CMISCubeList* pPlaced, Unk_CMISSetRef rSet, Unk_CMISCubeList* pOthers)
{
    bool bAnyLimited = false;
    CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo::iterator itPiece = reinterpret_cast<CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo*>(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces)->begin();
    while ((itPiece != reinterpret_cast<CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo*>(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces)->end())) {
        Unk_CMISPieceRef rPiece;
        FUN_14111e900((void*)(&rPiece), (void*)(&((Unk_CMISPiecePair*)(itPiece.operator->()))->m_value));
        if (FUN_141128400(&rPiece) != 0 && ((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->nMax != 0) {
            bAnyLimited = true;
            ((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->~MS2SvrPtr();
            break;
        }
        ((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->~MS2SvrPtr();
        ++itPiece;
    }
    unsigned nPlaced = 0;
    CMISMap_u_int_int mapCount;
    for (CMISSet_int::iterator itCube = reinterpret_cast<CMISSet_int*>(pPlaced)->begin(); (itCube != reinterpret_cast<CMISSet_int*>(pPlaced)->end()); ++itCube) {
        int nKey = *((int*)(&*itCube));
        MS2Ptr<Cube> spCube(GetCubeByKey(nKey));
        if (spCube.get() != 0) {
            int nCount = 0;
            int nItem = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
            if ((mapCount.find(nItem) != mapCount.end())) {
                int nItem2 = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
                nCount = *((int*)FUN_141127f90((void*)(&mapCount), (struct Unk_Key*)(&nItem2)));
            }
            nCount = nCount + 1;
            int nItem3 = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
            *((int*)FUN_141127f90((void*)(&mapCount), (struct Unk_Key*)(&nItem3))) = nCount;
            nPlaced = nPlaced + 1;
        }
    }
    unsigned nLimited = 0;
    if (bAnyLimited) {
        CMISMap_u_int_int::iterator itCnt = mapCount.begin();
        while ((itCnt != mapCount.end())) {
            int nItem = ((Unk_CMISIntPair*)(itCnt.operator->()))->m_key;
            unsigned nHave = ((Unk_CMISIntPair*)(itCnt.operator->()))->m_val;
            if ((reinterpret_cast<CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo*>(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces)->find(nItem) == reinterpret_cast<CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo*>(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces)->end()) == 0) {
                Unk_CMISPieceRef rPiece;
                FUN_14111e900((void*)(&rPiece), (void*)(((Unk_CMISPieceRef*)&(*(CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo*)(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces))[*(const unsigned int*)(&nItem)])));
                if (FUN_141126b50(&rPiece, 0) == 0) {
                    if (nHave < ((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->nMax)
                        nLimited = nLimited + nHave;
                    else
                        nLimited = nLimited + ((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->nMax;
                }
                ((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->~MS2SvrPtr();
            }
            ++itCnt;
        }
    }
    bool bComplete = false;
    if (bAnyLimited == 0) {
        if (((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_nNeed <= nPlaced)
            bComplete = true;
    } else {
        if (((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_nNeed <= nLimited)
            bComplete = true;
    }
    for (CMISSet_int::iterator itSel = reinterpret_cast<CMISSet_int*>(pPlaced)->begin(); (itSel != reinterpret_cast<CMISSet_int*>(pPlaced)->end()); ++itSel) {
        int nKey = *((int*)(&*itSel));
        MS2Ptr<Cube> spCube(GetCubeByKey(nKey));
        if (spCube.get() == 0)
            continue;
        int nItem = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
        if ((reinterpret_cast<CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo*>(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces)->find(nItem) == reinterpret_cast<CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo*>(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces)->end()) != 0)
            continue;
        int nItem2 = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
        Unk_CMISPieceRef rPiece;
        FUN_14111e900((void*)(&rPiece), (void*)(((struct Unk_CMISPieceRef*)FUN_141128010((void*)(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces), (struct Unk_Key*)(&nItem2)))));
        if (spCube.get() != 0) {
            if (((egf::FlatModel*)(Unk_CMISFlatModel*)(((class Unk_CMISFlatModel*)((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetModel())))->ContainsModel(0x48ccc02d)) {
                const char* pszEffect = bComplete == 0 ? (const char*)((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->strModelEffect : (const char*)((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->strFullEffect;
                efd::utf8string strEffect(pszEffect);
                FUN_1409a1fc0(FUN_141b6f910(), ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID()), &strEffect, 1.0f, true);
            }
            if (!((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->strSetName.IsEmpty()) {
                if (bComplete == 0) {
                    if ((reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->find(nKey) != reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->end())) {
                        MS2Ptr<SetItemEffectInfo> spEff = (*reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348))[nKey];
                        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(spEff->m_nEffect);
                        reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->erase(nKey);
                        DecrementKeyCount(&spEff->m_strName);
                    }
                } else {
                    int nUse = GetKeyCount(&((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->strSetName);
                    if (nUse >= *reinterpret_cast<Common::Constants::Value<int>*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_limits)->Get()) {
                        ((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->~MS2SvrPtr();
                        continue;
                    }
                    Unk_EffectTarget request;
                    request.m_strName = ((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->strSetName;
                    if (((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->strAttachNode.IsEmpty()) {
                        *reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&reinterpret_cast<Unk_CMISEffReq&>(request).m_pSlot10) = (NiAVObject*)(NiObject::DynamicCast(&DAT_143afa4d8, (class NiObject const*)(FUN_141b6efc0(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*()))));
                    } else {
                        bool bAttached = false;
                        NiAVObject* pRoot = FUN_141b6efc0(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*());
                        if (pRoot != 0) {
                            NiObject* pNode = NiObject::DynamicCast(&DAT_143afa4d8, (class NiObject const*)(pRoot->GetObjectByName(NiFixedString((const char*)((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->strAttachNode))));
                            if (pNode != 0) {
                                *reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&reinterpret_cast<Unk_CMISEffReq&>(request).m_pSlot10) = (NiAVObject*)(pNode);
                                bAttached = true;
                            }
                        }
                        if (bAttached == 0)
                            *reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&reinterpret_cast<Unk_CMISEffReq&>(request).m_pSlot10) = (NiAVObject*)(NiObject::DynamicCast(&DAT_143afa4d8, (class NiObject const*)(FUN_141b6efc0(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*()))));
                    }
                    bool bOff = false;
                    FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()), 0x2a7fd9f4, *(bool const*)(&bOff));
                    int nEffect = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(reinterpret_cast<Unk_EffectTarget&>(request));
                    if (nEffect != 0) {
                        if ((reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->find(nKey) != reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->end())) {
                            MS2Ptr<SetItemEffectInfo> spOld = (*reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348))[nKey];
                            TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(spOld->m_nEffect);
                            DecrementKeyCount(&spOld->m_strName);
                        }
                        MS2Ptr<SetItemEffectInfo> spNew(new SetItemEffectInfo);
                        spNew->m_nEffect = nEffect;
                        spNew->m_strName = ((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->strSetName;
                        (*reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348))[nKey] = spNew;
                        IncrementKeyCount(&spNew->m_strName);
                    }
                }
            }
            ((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->~MS2SvrPtr();
        } else {
            ((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->~MS2SvrPtr();
        }
    }
    for (CMISSet_int::iterator itOther = reinterpret_cast<CMISSet_int*>(pOthers)->begin(); (itOther != reinterpret_cast<CMISSet_int*>(pOthers)->end()); ++itOther) {
        int nKey = *((int*)(&*itOther));
        MS2Ptr<Cube> spCube(GetCubeByKey(nKey));
        if (spCube.get() == 0)
            continue;
        int nItem = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
        if ((reinterpret_cast<CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo*>(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces)->find(nItem) == reinterpret_cast<CMISMap_u_int_MS2SvrPtr_CUGCMapSetItemInfo*>(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces)->end()) != 0)
            continue;
        int nItem2 = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
        Unk_CMISPieceRef rPiece;
        FUN_14111e900((void*)(&rPiece), (void*)(((struct Unk_CMISPieceRef*)FUN_141128010((void*)(&((Unk_CMISSetInfo*)(void*)reinterpret_cast<MS2SvrPtr<CUGCMapSetItemData>&>(rSet).operator->())->m_pieces), (struct Unk_Key*)(&nItem2)))));
        if (spCube.get() != 0) {
            if (!((Unk_CMISPieceInfo*)(void*)((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->operator->())->strSetName.IsEmpty()) {
                if ((reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->find(nKey) != reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->end())) {
                    MS2Ptr<SetItemEffectInfo> spEff = (*reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348))[nKey];
                    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(spEff->m_nEffect);
                    reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->erase(nKey);
                    DecrementKeyCount(&spEff->m_strName);
                }
            }
        }
        ((MS2SvrPtr<CUGCMapSetItemInfo>*)(void*)(&rPiece))->~MS2SvrPtr();
    }
}
// ---- w138 batch 9 ----
Unk_CMISIter<283>* FUN_141157740(Unk_CMISTree<283>*, Unk_CMISIter<283>*, const int*);       // find
Unk_CMISIter<283>* FUN_141151bb0(Unk_CMISTree<283>*, Unk_CMISIter<283>*);                   // end
bool FUN_141126e10(Unk_CMISIter<283>*, Unk_CMISIter<283>*);                                 // operator==
struct Unk_CMISBucket { void* m_head; unsigned __int64 m_count; };                          // set id -> placed cube keys
struct Unk_CMISBucketIter { void* m_p; };
char* FUN_141127d50(void*, void*);   // C3: was FUN_141127d50
Unk_CMISBucketIter* FUN_141151f10(Unk_CMISBucket*, Unk_CMISBucketIter*);                    // end
Unk_CMISBucketIter* FUN_141157e40(Unk_CMISBucket*, Unk_CMISBucketIter*, const int*);        // find
bool FUN_141126f90(Unk_CMISBucketIter*, Unk_CMISBucketIter*);                               // operator==
char* FUN_141128050(void*, void*);   // C3: was FUN_141128050
Unk_CMISListIter* FUN_140368510(Unk_CMISCubeList*, Unk_CMISListIter*, const int*);          // find
bool FUN_14035e9e0(Unk_CMISListIter*, Unk_CMISListEnd*);                                    // operator==
void FUN_14035dea0(Unk_CMISCubeList*);                                                      // ctor
void FUN_14035e6c0(Unk_CMISCubeList*);                                                      // dtor
void FUN_14035d1e0(Unk_CMISCubeList*, Unk_CMISInsRes*, const int*);                         // insert (writes the pair)
class Unk_CMISSetMgr;
Unk_CMISSetRef* FUN_140b9df60(Unk_CMISSetMgr*, Unk_CMISSetRef* pOut, int nSetId);
bool FUN_1401b5240(MS2Ptr<CItemData>*, int);                                                // operator==
bool FUN_140885250(Unk_CMISRecRef*, int);                                                   // operator==
// @0x1410bec60
void CubeMapInformationService::FUN_1410bec60(MS2Ptr<Cube> spCube)
{
    if (((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20() == 0)
        return;
    MS2Ptr<CItemData> spItem = FUN_14053f870(((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20());
    if (spItem == 0)
        return;
    MS2Ptr<ItemHousing> spHousing = TSingleton<CItemDataTable>::GetInstance()->GetHousing(((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20());
    if (spHousing == 0)
        return;
    if (spHousing->setItemID == 0)
        return;
    UGCMapSetItemDataPtr spSet = TSingleton<CUGCMapSetItemTable>::GetInstance()->FUN_140b9df60(spHousing->setItemID);
    if (spSet == 0)
        return;
    bool bFound = false;
    unsigned nItem = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
    if (spSet->m_items.find(nItem) != spSet->m_items.end())
        bFound = true;
    if (!bFound) {
        int nItemLog = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
        ((class Unk_CMISLog*)GetLogString())->FUN_1403d7960(1, 0x13, L"세트아이템으로 지정된 아이템({0})이지만 SetItemTable({1})에는 등록되지 않았습니다", &nItemLog, (const int*)&spHousing->setItemID);
        return;
    }
    CMISMap_int_Map_unsigned_int_Set_int::iterator itOuter = reinterpret_cast<CMISMap_int_Map_unsigned_int_Set_int*>(&f440)->find(spCube->field50);
    if (itOuter == reinterpret_cast<CMISMap_int_Map_unsigned_int_Set_int*>(&f440)->end()) {
        return;
    }
    Unk_CMISBucket* pBucket = ((struct Unk_CMISBucket*)FUN_141127d50((void*)(&f440), (void*)(&spCube->field50)));
    if (reinterpret_cast<CMISMap_u_int_Set_int*>(pBucket)->find(spHousing->setItemID) == reinterpret_cast<CMISMap_u_int_Set_int*>(pBucket)->end()) {
        return;
    }
    int nCell = FUN_1408a03c0(spCube->position);
    Unk_CMISCubeList* pCells = ((struct Unk_CMISCubeList*)FUN_141128050((void*)(pBucket), (void*)((const int*)&spHousing->setItemID)));
    if (reinterpret_cast<CMISSet_int*>(pCells)->find(nCell) == reinterpret_cast<CMISSet_int*>(pCells)->end())
        return;
    reinterpret_cast<CMISSet_int*>(pCells)->erase(nCell);
    CMISSet_int setNew;
    setNew.insert(nCell);
    FUN_1410bf610(pCells, Unk_CMISSetRef(*reinterpret_cast<Unk_CMISSetRef*>(&spSet)), reinterpret_cast<Unk_CMISCubeList*>(&setNew));
}
// ---- w138 batch 10 ----
struct Unk_CMISOuterPair { int m_key; int m_pad; Unk_CMISBucket m_value; };
struct Unk_CMISBucketPair { int m_key; int m_pad; Unk_CMISCubeList m_value; };
Unk_CMISIter<283>* FUN_14114de50(Unk_CMISTree<283>*, Unk_CMISIter<283>*);                   // begin
bool FUN_141127540(Unk_CMISIter<283>*, Unk_CMISIter<283>*);                                 // operator!=
Unk_CMISOuterPair* FUN_141128620(Unk_CMISIter<283>*);                                       // operator*
void* FUN_141129b90(struct Unk_TreeIter*);   // C3: was FUN_141129b90
Unk_CMISBucketIter* FUN_14114e1d0(Unk_CMISBucket*, Unk_CMISBucketIter*);                    // begin
bool FUN_1411276c0(Unk_CMISBucketIter*, Unk_CMISBucketIter*);                               // operator!=
Unk_CMISBucketPair* FUN_1411286e0(Unk_CMISBucketIter*);                                     // operator*
void* FUN_141129c10(struct Unk_TreeIter*);   // C3: was FUN_141129c10
// @0x1410bf470
void CubeMapInformationService::FUN_1410bf470()
{
    for (CMISMap_int_Map_unsigned_int_Set_int::iterator itOuter = reinterpret_cast<CMISMap_int_Map_unsigned_int_Set_int*>(&f440)->begin(); (itOuter != reinterpret_cast<CMISMap_int_Map_unsigned_int_Set_int*>(&f440)->end()); FUN_141129b90((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<283>*>(&itOuter)))) {
        Unk_CMISBucket* pBucket = &FUN_141128620(reinterpret_cast<Unk_CMISIter<283>*>(&itOuter))->m_value;
        for (CMISMap_u_int_Set_int::iterator itInner = reinterpret_cast<CMISMap_u_int_Set_int*>(pBucket)->begin(); (itInner != reinterpret_cast<CMISMap_u_int_Set_int*>(pBucket)->end()); FUN_141129c10((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISBucketIter*>(&itInner)))) {
            int nSetId = FUN_1411286e0(reinterpret_cast<Unk_CMISBucketIter*>(&itInner))->m_key;
            Unk_CMISCubeList* pCells = &FUN_1411286e0(reinterpret_cast<Unk_CMISBucketIter*>(&itInner))->m_value;
            UGCMapSetItemDataPtr spSet = CUGCMapSetItemTable::GetInstance()->FUN_140b9df60(nSetId);
            if (spSet == 0)
                continue;
            std::set<int> setEmpty;
            FUN_1410bf610(pCells, Unk_CMISSetRef(*reinterpret_cast<Unk_CMISSetRef*>(&spSet)), reinterpret_cast<Unk_CMISCubeList*>(&setEmpty));
        }
    }
}
// @0x1410ce600
void CubeMapInformationService::FUN_1410ce600(int nItemId, Unk_Int3 pt, int nZ)
{
    int nCell = FUN_1408a03c0(pt);
    CubeItemInfo info;
    info.itemId = nItemId;
    info.instanceId = nCell;
    info.count = 0;
    info.look = 0;
    efd::utf8string strName;
    FUN_1410bd080(FUN_1408a03c0(pt), pt, nZ, &info, strName, 0, 0, 0, 0, 0, Unk_PayloadPtr<NoticeCubeInfo>(0));
}
class Unk_CMISPawn                                                                          // the local player (slot 18 gives the position)
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual Vector3 vfunc_18();
    virtual Vector3 vfunc_19();
    virtual Vector3 vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24();
    Vector3 FUN_1416767d0();
};
class Unk_IntOptionEntry   // C3: member view for the former free stand-ins
{
public:
    int& FUN_140298f40();
};
// @0x1410cb1b0
Unk_CMISEntityRef CubeMapInformationService::FUN_1410cb1b0()
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()));
    float fBest = FLT_MAX;
    Unk_1401cd100 best(0);
    if (pPawn != 0) {
        for (CMISEMap_int_EntityID::iterator it = reinterpret_cast<CMISEMap_int_EntityID*>(&f108)->begin(); (it != reinterpret_cast<CMISEMap_int_EntityID*>(&f108)->end()); ++it) {
            int nKey = FUN_1411286a0(reinterpret_cast<Unk_CMISIter<265>*>(&it))->m_key;
            Unk_CMISEntityRef ref(FUN_1411286a0(reinterpret_cast<Unk_CMISIter<265>*>(&it))->m_ref);
            Vector3 ptCell;
            FUN_1408a15b0(FUN_1408a0400(nKey), static_cast<Vector3&>(ptCell));
            float fDist = pPawn->vfunc_18().FUN_140965c40(ptCell).FUN_140967ac0();
            if (fDist > *((float*)&((class Unk_IntOptionEntry*)(struct Unk_CMISLimitF*)(&((struct Unk_CMISRules*)FUN_1401d3200())->m_fNear))->FUN_140298f40()))
                continue;
            if (fDist > fBest)
                continue;
            fBest = fDist;
            *(egf::EntityID*)(reinterpret_cast<Unk_CMISEntityRef*>(&best)) = *(const egf::EntityID*)&(ref);
        }
    }
    return Unk_CMISEntityRef(reinterpret_cast<const Unk_CMISEntityRef&>(best));
}
// ---- w138 batch 11 ----
class Unk_CMISClock;
char* FUN_141127f10(void*, void*);   // C3: was FUN_141127f10
// @0x1410caf20
void CubeMapInformationService::FUN_1410caf20(Cube* pCube, int nTime)
{
    int nCell = FUN_1408a03c0(pCube->position);
    if (reinterpret_cast<CMISEMap_int_CubeTimer*>(&f1f8)->find(nCell) != reinterpret_cast<CMISEMap_int_CubeTimer*>(&f1f8)->end())
        return;
        bool bInstanced = false;
        ((const egf::EntityPtr*)(&pCube->entity))->operator->()->GetPropertyValue(0x23f9860e, bInstanced);
        if (bInstanced) {
            Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
            if (spInst.FUN_14098d090() != 0)
                spInst.FUN_14098d0e0()->FUN_1413d6e60(((const egf::EntityPtr*)(&pCube->entity))->operator egf::Entity*(), false);
        }
        bool bOff = false;
        FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&pCube->entity))->operator->()), 0xa0b6b179, *(bool const*)(&bOff));
        Unk_CMISCubeTimer* pTimer = ((struct Unk_CMISCubeTimer*)FUN_141127f10((void*)(&f1f8), (void*)(&nCell)));
        pTimer->m_timer.FUN_140868750(nTime - ((class CMainSystem*)(class Unk_CMISClock*)(reinterpret_cast<Unk_CMISClock*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473390());
        ((const egf::EntityPtr*)(&pCube->entity))->operator->()->GetPropertyValue(0x2a7fd9f4, pTimer->m_bFlagA);
        ((const egf::EntityPtr*)(&pCube->entity))->operator->()->GetPropertyValue(0x9004569a, pTimer->m_bFlagB);
        if (pCube->field44 != 1) {
            unsigned short nShape = 5;
            ((class CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(((const egf::EntityPtr*)(&pCube->entity))->operator egf::Entity*(), nShape, 0, 1);
        }
}
void FUN_140de8bd0(egf::Entity*, unsigned, efd::AssetID*);
// @0x1410bbcd0
void CubeMapInformationService::FUN_1410bbcd0(int nGroup, int nIsOne)
{
    int nFlag = 0;
    FUN_1408a0890(WorldService::GetInstance()->FUN_141bd3060(), nGroup, &nFlag);
    if ((reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->find(nGroup) == reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->end()) != 0) {
        ((class Unk_CMISLog*)GetLogString())->FUN_140353fc0(0xc, 0x13, L"Not exist salable group : {0}", &nGroup);
        return;
    }
    egf::EntityPtr spEnt = *(const egf::EntityPtr*)(((struct Unk_CMISEntityRef*)FUN_141127b90((void*)(&ff8), (void*)(&nGroup))));
    if (((const egf::EntityPtr*)(&spEnt))->operator egf::Entity*() != 0) {
        int nState = 2;
        Unk_CMISHouseRef spHouse(FUN_1410c7c20(nGroup, nIsOne));
        if (spHouse.FUN_141128410() != 0)
            nState = spHouse.FUN_1411284b0()->m_state;
        efd::AssetID asset;
        if (nState == 2)
            (((const egf::EntityPtr*)(&spEnt))->operator->())->GetPropertyValue<efd::AssetID>(0x2472f50d, asset);
        else if (nState == 1)
            (((const egf::EntityPtr*)(&spEnt))->operator->())->GetPropertyValue<efd::AssetID>(0x811e9044, asset);
        else if (nState == 4)
            (((const egf::EntityPtr*)(&spEnt))->operator->())->GetPropertyValue<efd::AssetID>(0x46fed193, asset);
        FUN_140de8bd0(((const egf::EntityPtr*)(&spEnt))->operator->(), 0x770e5fc6, &asset);
    }
}
void FUN_14111e6e0(Unk_CMISHousePtr*);                                                      // ctor: allocates a fresh record
void FUN_141126140(Unk_CMISHousePtr* pDst, Unk_CMISHousePtr* pSrc);                         // assign
void FUN_141123790(Unk_CMISHousePtr*);                                                      // dtor
class CAddressTable { public: static CStringW GetText(int nId); };   // C3: the map name text (0x140979570)
// @0x1410bbf20
void CubeMapInformationService::FUN_1410bbf20(int nGroup, egf::EntityID id)
{
    egf::EntityPtr spEnt(static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411cf440(id));
    *(egf::EntityPtr*)(((struct Unk_CMISEntityRef*)FUN_141127b90((void*)(&ff8), (void*)(&nGroup)))) = spEnt;
    Vector3 pt = DAT_143b01a60;
    reinterpret_cast<egf::Entity*>(((const egf::EntityPtr*)(&spEnt))->operator->())->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(pt));
    CStringW strKey;
    strKey.Format(L"%d", nGroup);
    int nMap = WorldService::GetInstance()->FUN_141bd3060();
    CStringW strOwner;
    Unk_CMISSalable salable;
    if (FUN_1408a0d30(nGroup, *(struct Unk_UGCGroup*)(&salable), nMap) != 0)
        strOwner = CAddressTable::GetText(nMap);
    MS2SvrPtr<SalesInfo> spInfo(MS2SvrNewTag(0));
    reinterpret_cast<Unk_CMISHouseInfo*>(spInfo.operator->())->m_nGroup = nGroup;
    reinterpret_cast<Unk_CMISHouseInfo*>(spInfo.operator->())->m_pt = pt;
    reinterpret_cast<Unk_CMISHouseInfo*>(spInfo.operator->())->m_strOwner = strOwner;
    reinterpret_cast<Unk_CMISHouseInfo*>(spInfo.operator->())->m_bNoSalable = salable.m_nHideEmoticon == 0;
    reinterpret_cast<Unk_CMISHouseInfo*>(spInfo.operator->())->m_nValue = salable.m_nField20;
    FUN_141126140(((struct Unk_CMISHousePtr*)FUN_141127c50((void*)(&f238), (void*)(&nGroup))), (Unk_CMISHousePtr*)&spInfo);
    Unk_CMISHouseMark* pMark = FUN_1410dc020();
    if (pMark != 0)
        ((UIHouseMark*)(Unk_CMISHouseMark*)(pMark))->FUN_14198cb00(*(Unk_HouseMarkInfo const*)(SalesInfo const*)&(*spInfo));
}

// ---- w138 batch 12 ----
class Unk_CMISDoll
{
public:
    virtual void vfunc_0(); virtual void IncRefCount() const; virtual void DecRefCount() const;   // efd::IBase (GameObject 0x1409f2fe0 / 0x1409f2ec0)
    virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
    virtual void vfunc_19(Vector3 ptPos);
    virtual void vfunc_20();
    virtual void vfunc_21(Vector3 ptRot);
};
struct Unk_CMISWorldBind {  };
// @0x1410bc7f0
egf::EntityPtr CubeMapInformationService::FUN_1410bc7f0(Vector3 ptPos, Vector3 ptRot, unsigned nIdx, int nItemId)
{
    efd::SmartPointer<Unk_CMISDoll> pc = (Unk_CMISDoll*)EE_NEW FittingDollPC;      // held to the end: the exe releases it on both exits
    ((PC*)(pc).operator->())->FUN_141656a50(0);
    ((FittingDollPC*)(pc).operator->())->FUN_14121c6e0(0);
    ((GameObject*)(pc).operator->())->FUN_14123c5a0(nIdx);
    pc->vfunc_19(ptPos);
    pc->vfunc_21(ptRot);
    if (((FittingDollPC*)(pc).operator->())->FUN_14121bab0(nItemId) == 0)
        return egf::EntityPtr(0);
    ((WorldService*)(Unk_CMISWorldBind*)(((Unk_CMISWorldBind*)reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance()))))->FUN_141bbb1e0((GameObject*)(Unk_CMISDoll*)(pc), 0, 1);
    unsigned __int64 kId;                                   // the id slot (no ctor in the exe)
    egf::EntityID& rId = reinterpret_cast<egf::EntityID&>(kId);
    AddEntityRef(*(Unk_Int3*)&ptPos, reinterpret_cast<const Unk_CMISEntityRef&>(((GameObject*)(pc).operator->())->FUN_14123c460(rId)));
    return egf::EntityPtr(((GameObject*)(pc).operator->())->FUN_14123c410());
}

// @0x1410bc3d0
egf::EntityPtr CubeMapInformationService::FUN_1410bc3d0(Unk_CMISBlock rec)
{
#define CMIS_DOLL(rec) (reinterpret_cast<const MS2Ptr<FittingDollData>&>(rec))     // rec is the MS2Ptr<FittingDollData>
    efd::SmartPointer<Unk_CMISDoll> pc = (Unk_CMISDoll*)EE_NEW FittingDollPC;      // held to the end: the exe releases it on both exits
    ((PC*)(pc).operator->())->FUN_141656a50(CMIS_DOLL(rec)->instanceId);
    ((FittingDollPC*)(pc).operator->())->FUN_14121c6e0((void*)CMIS_DOLL(rec)->instanceId);
    ((GameObject*)(pc).operator->())->FUN_14123c5a0(CMIS_DOLL(rec)->kind);
    pc->vfunc_19(reinterpret_cast<const Vector3&>(CMIS_DOLL(rec)->position));
    pc->vfunc_21(reinterpret_cast<const Vector3&>(CMIS_DOLL(rec)->rotation));
    if (((FittingDollPC*)(pc).operator->())->FUN_14121bab0(CMIS_DOLL(rec)->field28) == 0)
        return egf::EntityPtr(0);
    if (CMIS_DOLL(rec)->field44 != 0) {
        for (size_t i = 0; i < CMIS_DOLL(rec)->items.GetCount(); i++) {
            MS2Ptr<CItem> e = CMIS_DOLL(rec)->items[i];
            ((PC*)(pc).operator->())->FUN_141653d10(e);
        }
    }
    ((WorldService*)(Unk_CMISWorldBind*)(((Unk_CMISWorldBind*)reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance()))))->FUN_141bbb1e0((GameObject*)(Unk_CMISDoll*)(pc), 0, 1);
    unsigned __int64 kId;                                   // the id slot (no ctor in the exe)
    egf::EntityID& rId = reinterpret_cast<egf::EntityID&>(kId);
    AddEntityRef(*(Unk_Int3*)&CMIS_DOLL(rec)->position, reinterpret_cast<const Unk_CMISEntityRef&>(((GameObject*)(pc).operator->())->FUN_14123c460(rId)));
    return egf::EntityPtr(((GameObject*)(pc).operator->())->FUN_14123c410());
}

// ---- w138 batch 13 ----
struct Unk_CMISRefList;                                                                     // list of entities found near a point
extern Vector3 DAT_143b01a60;                                                       // the zero point
void FUN_14114dbb0(Unk_CMISTree<264>*, Unk_CMISIter<264>*);                                 // begin
Unk_CMISRefElem* FUN_141128560(Unk_CMISIter<264>*);                                         // operator*
void* FUN_141129a80(struct Unk_TreeIter*);   // C3: was FUN_141129a80
void* FUN_140965820(Unk_CubeOwnerPtr*);                                                     // get
void FUN_1408a8790(Unk_CubeOwnerPtr*);                                                      // dtor
void FUN_1408a8720(egf::EntityPtr*);                                                        // dtor
float FUN_140966f00(Vector3 ptA, Vector3 ptB);                              // distance
void FUN_14115a960(void*, void*);   // C3: was FUN_14115a960
void** FUN_141123230(void* pOut, Unk_CMISPawn*);
void** FUN_1411525d0(Unk_CMISRefList*, void** pOut);                                        // end
void** FUN_14114e990(Unk_CMISRefList*, void** pOut);                                        // begin
void FUN_14111d5b0(void* pFirst, void* pLast, void* pKey);

// @0x1410bb610
void CubeMapInformationService::FUN_1410bb610(unsigned nMask, Unk_CMISPawn* pPawn, float fDist, Unk_CMISRefList* pOut)
{
    if (pPawn == 0)
        return;
    if (((std::_Tree<std::_Tmap_traits<int, unsigned int, std::less<int>, efd::CustomAllocator<std::pair<int const, unsigned int>>, 0>>*)(void*)(&ff8))->empty())
        return;
    for (CMISEMap_int_SmartPointer_Entity::iterator it = reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->begin(); (it != reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->end()); FUN_141129a80((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<264>*>(&it)))) {
        int nGroup = FUN_141128560(reinterpret_cast<Unk_CMISIter<264>*>(&it))->m_key;
        egf::EntityPtr spEnt = *(const egf::EntityPtr*)(&FUN_141128560(reinterpret_cast<Unk_CMISIter<264>*>(&it))->m_ref);
        if ((&spEnt)->operator==((egf::Entity*)(0)))
            continue;
        bool bOwned = false;
        unsigned char bHasOwner = FUN_140965820(const_cast<Unk_CubeOwnerPtr*>(&static_cast<const Unk_CubeOwnerPtr&>(FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0)))) != 0 ? 1 : 0;
        if (bHasOwner)
            bOwned = true;
        for (int nBit = 1; nBit < 5; nBit <<= 1) {
            if ((nMask & nBit) != nBit)
                continue;
            if (bOwned && nBit != 1)
                continue;
            if (!bOwned && nBit == 1)
                continue;
            Vector3 ptPawn = pPawn->vfunc_18();
            Vector3 ptEnt = DAT_143b01a60;
            reinterpret_cast<egf::Entity*>(((const egf::EntityPtr*)(&spEnt))->operator->())->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(ptEnt));
            float fD = FUN_140966f00(ptPawn, ptEnt);
            if (fD < fDist)
                FUN_14115a960((void*)(pOut), (void*)(&spEnt));
        }
    }
    void* aCopy[1]; void* pEnd[1]; void* pBegin[1];
    FUN_14111d5b0(*FUN_14114e990(pOut, pBegin), *FUN_1411525d0(pOut, pEnd), *FUN_141123230(aCopy, pPawn));
}

// ---- w138 batch 14 ----
struct Unk_CMISSlot { Unk_CMISSlot(void* pId); Unk_CMISSlot(const Unk_CMISSlot&); ~Unk_CMISSlot(); void* m_vtbl; void* m_p; };   // ctor 14111e890, copy 14111e850, dtor 1409648f0
MS2_CHECK_SIZE(Unk_CMISSlot, 0x10);
struct Unk_CMISObjRec30 { char m_pad[0x30]; int m_n30; char m_pad34[0xc]; void* m_pKind; };
struct Unk_CMISInfoRef { ~Unk_CMISInfoRef(); void* m_vtbl; void* m_p; };                                   // dtor 140ca62a0
MS2_CHECK_SIZE(Unk_CMISInfoRef, 0x10);
class Unk_CMISObj498 { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual int vfunc_2(void* pCtx, void* pRec, int nCell, __int64 nOwner, void* pItem); Unk_CMISInfoRef FUN_140ca6580();   Unk_CMISEntityRef FUN_141226eb0(); };
int FUN_141126a70(Unk_CMISObjHandle*);                                                                // IsNull
class CFunctionCubeObject* FUN_141225470(int);   // C3: was FUN_141225470
void FUN_141230c90(Unk_CMISMagicCube*, Unk_CMISSlot slot);

// @0x1410d0000
void CubeMapInformationService::FUN_1410d0000(void* pCtx, MS2Ptr<Cube> spCube)
{
    CObjectDataPtr spData = FUN_140704ec0(spCube->fieldB4);
    if (!spData)
        return;
    {
        if (((Unk_CMISObjRec30*)spData.operator->())->m_n30 != 0) {
            Unk_CMISSlot slot(((void*)FUN_141225470(((Unk_CMISObjRec*)spData.operator->())->nKind)));
            Vector3 ptCube = *(Vector3*)&spCube->position;
            Unk_CMISObj498* pObj = ((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&slot))->operator->());
            void* pItem = ((void*)((MS2Ptr<CubeItemInfo>*)(void*)(&spCube->item))->get());
            int FUN_1408a03c0(const Unk_Int3& pt);
            __int64 nOwner = GetOwnerId(spCube->field50, spCube->field54);
            if (pObj->vfunc_2(pCtx, &((Unk_CMISObjRec30*)spData.operator->())->m_n30, FUN_1408a03c0(*(Unk_Int3*)&ptCube), nOwner, pItem) != 0) {
                CString strKey;
                strKey.Format("%d_%d", spCube->field44, FUN_1408a03c0(Unk_Int3(*(Unk_Int3*)&spCube->position)));
                ((class CFunctionCubeObject*)(class Unk_CMISObj498*)(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&slot))->operator->())))->SetId(strKey);
                FUN_141230c90(((class Unk_CMISMagicCube*)FUN_1409670b0()), Unk_CMISSlot(slot));
                int nKind = ((Unk_CMISObjRec*)spData.operator->())->nKind;
            }
        }
    }
}

// ---- w138 batch 15 ----
struct Unk_CMISRefList { Unk_CMISRefList(); ~Unk_CMISRefList(); void* m_buf[3]; };        // ctor 1408a84d0, dtor 1408a88a0
class AdditionalLevelData;   // C3: forward decl for a rewritten call
float FUN_140966ea0(Vector3 ptA, Vector3 ptB);                              // distance

// @0x1410c93c0
void CubeMapInformationService::FUN_1410c93c0()
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()));
    if (pPawn == 0)
        return;
    UIHouseMark* pMark = reinterpret_cast<UIHouseMark*>(FUN_1410dc020());
    if (pMark == 0)
        return;
    if (reinterpret_cast<egf::EntityPtr&>(f158).operator==((egf::Entity*)(0))) {
        Unk_CMISRefList list;
        FUN_1410bb610(5, pPawn, (float)*reinterpret_cast<Common::Constants::Value<int>*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_limits1348)->Get(), &list);
        if (((std::vector<MS2Ptr<AdditionalLevelData>, std::allocator<MS2Ptr<AdditionalLevelData>>>*)(struct Unk_CMISRefList*)(&list))->empty())
            return;
        egf::EntityPtr spEnt = *(const egf::EntityPtr*)(&(*(std::vector<egf::EntityPtr>*)(&list))[0]);
        int nVal = 0;
        ((const egf::EntityPtr*)(&spEnt))->operator->()->GetPropertyValue<int>(0x85ef19e7, nVal);
        MS2Ptr<UIHouseMarkEntity> spMark = pMark->FUN_14198ce50(nVal);
        if (spMark.get() != 0)
            spMark->FUN_14198b2f0();
        f160 = true;
        *(egf::EntityPtr*)(reinterpret_cast<Unk_CMISEntityRef*>(&f158)) = spEnt;
    } else {
        if (reinterpret_cast<egf::EntityPtr&>(f158).operator egf::Entity*() != 0) {
            Vector3 ptEnt = DAT_143b01a60;
            reinterpret_cast<egf::Entity*>(reinterpret_cast<egf::Entity*>(reinterpret_cast<egf::EntityPtr&>(f158).operator->()))->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(ptEnt));
            float fDist = FUN_140966ea0(ptEnt, pPawn->vfunc_18());
            if (fDist >= (float)*reinterpret_cast<Common::Constants::Value<int>*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_limits1348)->Get()) {
                int nVal = 0;
                reinterpret_cast<egf::Entity*>(reinterpret_cast<egf::EntityPtr&>(f158).operator->())->GetPropertyValue<int>(0x85ef19e7, nVal);
                MS2Ptr<UIHouseMarkEntity> spMark = pMark->FUN_14198ce50(nVal);
                if (spMark.get() != 0)
                    spMark->FUN_14198b320();
                reinterpret_cast<egf::EntityPtr&>(f158).operator=((egf::Entity*)(0));
                f160 = false;
            }
        }
    }
}

// ---- w138 batch 16 ----
// MS2Ptr<CLiftableObject>: the pointer is at +8. ctor 140963ff0 is the copy ctor (the element is an MS2Ptr), dtor 1409649e0

// @0x1410c7110
int CubeMapInformationService::FUN_1410c7110(int* pCell)
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()));
    if (pPawn != 0) {
    Vector3 kForward, kRight;
    FUN_140a01250(pPawn->vfunc_20(), &kForward, &kRight);
    Vector3 ptHit;
    GetCellInFrontOfActor(reinterpret_cast<PCBase*>(pPawn), 0.0f, &ptHit, 1);
    Unk_Int3 cell = FUN_1408a1430(ptHit);
    if (HasCubeAtCell(cell)) {
    MS2Ptr<Cube> spCube(GetCubeAtCell(cell));
    if (((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20() == 0 || ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20() == 8)
        return 0;
    if (spCube->field44 != 2)
        return 0;
    if (spCube->field58 == 1)
        return 0;
    egf::EntityPtr spEnt(reinterpret_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411cf440(*reinterpret_cast<const egf::EntityID*>(((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID()))));
    if ((&spEnt)->operator==((egf::Entity*)(0)))
        return 0;
    Vector3 ptDir;
    reinterpret_cast<egf::Entity*>(((const egf::EntityPtr*)(&spEnt))->operator->())->GetPropertyValue<efd::Point3>(0x68c7c29d, (efd::Point3&)(ptDir));
    Vector3 kForward2, kRight2;
    FUN_140a01250(ptDir, &kForward2, &kRight2);
    float fDot = efd::Clamp(kForward.FUN_140a00f20(kForward2), -1.0f, 1.0f);
    if (fDot > 0.7f) {
        *pCell = FUN_1408a03c0(*(Unk_Int3*)&spCube->position);
        return 1;
    }
    }
    }
    return 0;
}

class Unk_WsB_Lift : public CPtred {};                                                      // the lift object behind MS2Ptr<Unk_WsB_Lift> (CLiftableObject)
// @0x1410c7500
int CubeMapInformationService::FUN_1410c7500(CString* pOut)
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()));
    if (pPawn != 0) {
        std::vector<MS2Ptr<Unk_WsB_Lift> > list;
        WorldService::GetInstance()->FUN_141bc58d0(&list);
        if (list.size() <= 0)
            return false;
        efd::Point3 kForward, kRight;
        FUN_140a01250(pPawn->vfunc_20(), (Vector3*)&kForward, (Vector3*)&kRight);
        efd::Point3 ptHit;
        GetCellInFrontOfActor(reinterpret_cast<PCBase*>(pPawn), 0.0f, (Vector3*)&ptHit, 1);
        Unk_Int3 cellHit = FUN_1408a1430(reinterpret_cast<const Vector3&>(ptHit));
        int nMinZ = 0x80000000;
        std::vector<MS2Ptr<Unk_WsB_Lift> >& range = list;       // the range-for over the list
        std::vector<MS2Ptr<Unk_WsB_Lift> >::const_iterator itEnd = range.end();
        for (std::vector<MS2Ptr<Unk_WsB_Lift> >::const_iterator itCur = range.begin(); itCur != itEnd; ++itCur) {
            MS2Ptr<Unk_WsB_Lift> spNpc(*itCur);
            if (reinterpret_cast<CLiftableObject*>(spNpc.operator->())->CanLift() == 0)
                continue;
            Vector3 ptNpc = reinterpret_cast<CLiftableObject*>(spNpc.operator->())->FUN_141447c80();
            Unk_Int3 cellNpc = FUN_1408a1430(ptNpc);
            Vector3 ptDelta = ptNpc.FUN_140965c40(pPawn->vfunc_18());
            ptDelta.z = 0.0f;
            float fLen = ptDelta.FUN_140968990();
            if (fLen > 150.0f)
                continue;
            float fDot = efd::Clamp(ptDelta.FUN_140a00f20(reinterpret_cast<const Vector3&>(kForward)), -1.0f, 1.0f);
            if (fDot > 0.5f && cellNpc.z > nMinZ)
                *pOut = static_cast<const CString&>(reinterpret_cast<CLiftableObject*>(spNpc.operator->())->GetName());
        }
    }
    return (*(pOut) != "");
}

// ---- w138 batch 17 ----
struct Unk_CMISObjInfo { char m_pad[0xe4]; int m_nShown; };
Unk_CMISIter<282>* FUN_14114e4e0(Unk_CMISTree<282>*, Unk_CMISIter<282>*);                   // begin
Unk_CMISIter<282>* FUN_1411521b0(Unk_CMISTree<282>*, Unk_CMISIter<282>*);                   // end
Unk_CMISIter<282>* FUN_141158380(Unk_CMISTree<282>*, Unk_CMISIter<282>*, const int*);       // find
char* FUN_141128210(void*, void*);   // C3: was FUN_141128210
void FUN_14114df30(Unk_CMISTree<262>*, Unk_CMISIter<262>*);                                 // begin
int* FUN_141128660(Unk_CMISIter<262>*);                                                     // operator*
void* FUN_141129bb0(struct Unk_TreeIter*);   // C3: was FUN_141129bb0

// @0x1410c8a90
void CubeMapInformationService::FUN_1410c8a90()
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()));
    if (pPawn == 0)
        return;
    Unk_CMISSlot slot = ((class Unk_CMISMagicCube*)FUN_1409670b0())->FUN_141230f60(pPawn->FUN_1416767d0(), reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_fAtF80)->Read(), ((PC*)pPawn)->FUN_141656ad0());
    bool bShown = (((MS2Ptr<CFunctionCubeObject>*)(void*)(&slot))->get() ? true : false) && ((Unk_CMISObjInfo*)(void*)((MS2Ptr<FunctionCubeData>*)(void*)(const_cast<Unk_CMISInfoRef*>(&static_cast<const Unk_CMISInfoRef&>(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&slot))->operator->())->FUN_140ca6580()))))->operator->())->m_nShown != 0;
    if (bShown) {
        if ((((MS2Ptr<CFunctionCubeObject>*)(void*)(&f480))->get() ? true : false) && reinterpret_cast<const egf::EntityID&>(static_cast<const Unk_CMISEntityRef&>(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&slot))->operator->())->FUN_141226eb0())).operator==(reinterpret_cast<const egf::EntityID&>(reinterpret_cast<const Unk_1401cd100&>(static_cast<const Unk_CMISEntityRef&>(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&f480))->operator->())->FUN_141226eb0()))))) {
            if (f490 != 0) {
                if ((unsigned)(f494 + *reinterpret_cast<Common::Constants::Value<int>*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_limits5078)->Get()) < GetTickCountMs2())
                    ((CFunctionCubeObject*)(Unk_CMISObj498*)(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&f480))->operator->())))->FUN_141227360();
            } else {
                ((CFunctionCubeObject*)(Unk_CMISObj498*)(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&f480))->operator->())))->FUN_141227310();
                f494 = GetTickCountMs2();
                f490 = 1;
            }
        } else {
            if (((void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&f480))->get()) != 0)
                ((CFunctionCubeObject*)(Unk_CMISObj498*)(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&f480))->operator->())))->FUN_141227360();
            *(MS2Ptr<CFunctionCubeObject>*)(void*)(&f480) = *(MS2Ptr<CFunctionCubeObject>*)(void*)(&slot);
            ((CFunctionCubeObject*)(Unk_CMISObj498*)(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&f480))->operator->())))->FUN_141227310();
            f494 = GetTickCountMs2();
            f490 = 1;
        }
    } else {
        if (((void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&f480))->get()) != 0)
            ((CFunctionCubeObject*)(Unk_CMISObj498*)(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&f480))->operator->())))->FUN_141227360();
        f490 = 0;
    }
}

template <int N> class Unk_Wrap { public: bool IsNull() const; };    // 0x141126aa0 for N == 2
// @0x1410d2fb0
int CubeMapInformationService::FUN_1410d2fb0(__int64 nOwnerId, int nCategory, int* pnCount)
{
    *pnCount = 0;
    if (reinterpret_cast<Unk_Wrap<2>*>(&f218)->IsNull())
        return 0;
    for (CMISEMap_int_set_int::iterator it = reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->begin(); (it != reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()); FUN_141129bb0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<262>*>(&it)))) {
        int nGroup = *FUN_141128660(reinterpret_cast<Unk_CMISIter<262>*>(&it));
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (spOwner == 0)
            continue;
        if (spOwner->ownerID != nOwnerId)
            continue;
        if (f218->groups.find(nGroup) == f218->groups.end())
            continue;
        Unk_UGCGroup& rGroup = f218->groups[nGroup];
        int nHeight = 0;
        if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130())
            nHeight = f2fc;
        else
            nHeight = rGroup.heightLimit;
        Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nGroup)));
        for (CMISESet_int::iterator itList = reinterpret_cast<CMISESet_int*>(pList)->begin(); (itList != reinterpret_cast<CMISESet_int*>(pList)->end()); ++itList) {
            int nKey = *((int*)(&*itList));
            for (int nH = 1; nH <= nHeight; nH++) {
                Unk_Int3 pt = FUN_1408a0400(nKey);
                pt.z += nH;
                Cube* pCube = GetCubeAtCell(pt);
                if (pCube != 0 && FUN_14053fc10(((class Cube*)(class Cube*)(pCube))->FUN_1408b4f20()) == nCategory)
                    *pnCount = *pnCount + 1;
            }
        }
        break;
    }
    if (*pnCount > 0)
        return 1;
    return 0;
}

// @0x1410d4940
unsigned __int64 CubeMapInformationService::FUN_1410d4940()
{
    Unk_CMISInv* pInv = ((class Unk_CMISInv*)&((class UGCCubeCategoryTable*)(class Unk_CMISInvMgr*)(reinterpret_cast<Unk_CMISInvMgr*>(TSingleton<UGCCubeCategoryTable>::GetInstance())))->GetBonusInteriors());
    CMISMap_KindA_int counts;
    ATL::CAtlArray<MS2Ptr<CUGCMapItem> > stock;
    DAT_143ab2e50.FUN_140dfc750(stock);
    for (unsigned __int64 i = 0; i < stock.GetCount(); i++) {
        MS2Ptr<CUGCMapItem> spItem(stock.GetAt(i));
        if (spItem == 0)
            continue;
        int nItem = spItem->GetItemId();
        MS2Ptr<ItemHousing> spHousing = TSingleton<CItemDataTable>::GetInstance()->GetHousing(nItem);
        if (spHousing == 0)
            continue;
        Unk_CMISInvPtr spSlot(0);
        if (((ATL::CAtlMap<ECubeCategory, Unk_CubePtr<UGCCubeCategoryTable::Interior>, ATL::CElementTraits<ECubeCategory>, ATL::CElementTraits<Unk_CubePtr<UGCCubeCategoryTable::Interior>>>*)(Unk_CMISInv*)(pInv))->Lookup(*(ECubeCategory const*)(&spHousing->categoryIndex), *(Unk_CubePtr<UGCCubeCategoryTable::Interior>*)(Unk_CMISInvPtr*)(&spSlot)) != 0) {
            if (reinterpret_cast<CMISMap_KindA_int*>(&counts)->find(*reinterpret_cast<const Unk_CMISKindA*>(&spHousing->categoryIndex)) == reinterpret_cast<CMISMap_KindA_int*>(&counts)->end()) {
                *((int*)FUN_141128210((void*)(&counts), (void*)(&spHousing->categoryIndex))) = 1;
            } else {
                int nCount = *((int*)FUN_141128210((void*)(&counts), (void*)(&spHousing->categoryIndex)));
                nCount++;
                *((int*)FUN_141128210((void*)(&counts), (void*)(&spHousing->categoryIndex))) = nCount;
            }
        }
    }
    unsigned __int64 nTotal = 0;
    for (CMISMap_KindA_int::iterator it = reinterpret_cast<CMISMap_KindA_int*>(&counts)->begin(); (it != reinterpret_cast<CMISMap_KindA_int*>(&counts)->end()); FUN_141129cd0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<282>*>(&it)))) {
        int nItem = FUN_1411287a0(reinterpret_cast<Unk_CMISIter<282>*>(&it))->m_key;
        unsigned nNeed = FUN_1411287a0(reinterpret_cast<Unk_CMISIter<282>*>(&it))->m_val;
        Unk_CMISInvPtr spSlot(0);
        if (((ATL::CAtlMap<ECubeCategory, Unk_CubePtr<UGCCubeCategoryTable::Interior>, ATL::CElementTraits<ECubeCategory>, ATL::CElementTraits<Unk_CubePtr<UGCCubeCategoryTable::Interior>>>*)(Unk_CMISInv*)(pInv))->Lookup(*(ECubeCategory const*)(&nItem), *(Unk_CubePtr<UGCCubeCategoryTable::Interior>*)(Unk_CMISInvPtr*)(&spSlot)) != 0) {
            if (nNeed >= spSlot.FUN_140889010()->m_need)
                nTotal += spSlot.FUN_140889010()->m_count;
        }
    }
    return nTotal;
}

// ---- w138 batch 18 ----
Unk_CMISListIter* FUN_141158620(Unk_CMISTree<267>*, Unk_CMISListIter*, const int*);         // find
bool FUN_141126cd0(Unk_CMISIter<266>*, Unk_CMISIter<266>*);                                 // operator==
void FUN_141126100(Unk_CMISBlock* pDst, const Unk_CMISBlock* pSrc);                         // operator=
char* FUN_141127c10(void*, void*);   // C3: was FUN_141127c10

// @0x1410cb4c0
void CubeMapInformationService::FUN_1410cb4c0(Unk_CMISBlock rec)
{
    int nKey = FUN_1408a13d0(reinterpret_cast<const Vector3&>(CMIS_DOLL(rec)->position));
    if (reinterpret_cast<CMISESet_int*>(&f128)->find(nKey) != reinterpret_cast<CMISESet_int*>(&f128)->end()) {
        if (reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->find(nKey) != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()) {
            MS2Ptr<Cube> spCube(*FUN_141127cd0(&f98, &nKey));
            egf::EntityID idOld(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*() != 0 ? ((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID() : *reinterpret_cast<const egf::EntityID*>(&g_cubeMapNone));
            *(egf::EntityPtr*)(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)) = *(const_cast<egf::EntityPtr*>(&static_cast<const egf::EntityPtr&>(FUN_1410bc3d0(Unk_CMISBlock(rec)))));
            CMISEMap_EntityID_MS2Ptr_Cube::iterator itFindE = reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&fa8)->find(idOld);
            if (itFindE != reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&fa8)->end())
                reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&fa8)->erase(itFindE);
            if (((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*() != 0)
                *(MS2Ptr<Cube>*)(FUN_141128190(&fa8, ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID()))) = spCube;
            ((std::_Tree<std::_Tset_traits<int, std::less<int>, efd::CustomAllocator<int>, 0>>*)(void*)(&f128))->erase(*(int const*)(&nKey));
        } else {
            FUN_141126100(((struct Unk_CMISBlock*)FUN_141127c10((void*)(&f118), (void*)(&nKey))), &rec);
        }
    } else {
        if (reinterpret_cast<CMISEMap_int_MS2Ptr_FittingDollData*>(&f118)->find(nKey) == reinterpret_cast<CMISEMap_int_MS2Ptr_FittingDollData*>(&f118)->end())
            FUN_141126100(((struct Unk_CMISBlock*)FUN_141127c10((void*)(&f118), (void*)(&nKey))), &rec);
    }
}

// ---- w138 batch 19 ----
struct Unk_CMISCubeNode { int m_key; int m_pad; Unk_CMISCubeTimer m_val; };
void FUN_14114e080(Unk_CMISTree<272>*, Unk_CMISIter<272>*);                                 // begin
Unk_CMISCubeNode* FUN_1411286c0(Unk_CMISIter<272>*);                                        // operator*
void FUN_141129bf0(Unk_CMISIter<272>*);                                                     // operator++

// @0x1410c9db0
void CubeMapInformationService::FUN_1410c9db0()
{
    Unk_CMISIntList setDone;
    for (CMISEMap_int_CubeTimer::iterator it = reinterpret_cast<CMISEMap_int_CubeTimer*>(&f1f8)->begin(); (it != reinterpret_cast<CMISEMap_int_CubeTimer*>(&f1f8)->end()); ++it) {
        int nKey = FUN_1411286c0(reinterpret_cast<Unk_CMISIter<272>*>(&it))->m_key;
        Unk_CMISCubeTimer* pTimer = &FUN_1411286c0(reinterpret_cast<Unk_CMISIter<272>*>(&it))->m_val;
        if (pTimer->m_timer.FUN_140868c00() != 0) {
            Unk_CMISInsRes itIns;
            FUN_14111d290(reinterpret_cast<Unk_CMISTree<267>*>(&setDone), &itIns, &nKey);
            Cube* pCube = FUN_141127cd0(&f98, &nKey)->get();
            FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&pCube->entity))->operator->()), 0x9004569a, *(bool const*)(&pTimer->m_bFlagB));
            FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&pCube->entity))->operator->()), 0x2a7fd9f4, *(bool const*)(&pTimer->m_bFlagA));
            bool bFlag = false;
            ((const egf::EntityPtr*)(&pCube->entity))->operator->()->GetPropertyValue(0x23f9860e, bFlag);
            if (pCube->field44 == 1) {
                Unk_EffectTarget request;
                request.m_strName = ((struct Unk_CMISConsts*)FUN_1401d31f0())->m_strCubeEffect;
                request.m_nKind = 7;
                *reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&reinterpret_cast<Unk_CMISEffReq&>(request).m_pSlot10) = (NiAVObject*)(NiObject::DynamicCast(&DAT_143afa4d8, (class NiObject const*)(FUN_141b6efc0(((const egf::EntityPtr*)(&pCube->entity))->operator egf::Entity*()))));
                TSingleton<CEffectService>::GetInstance()->FUN_1411a4a00(request);
            }
            if (bFlag) {
                Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
                if (spInst.FUN_14098d090() != 0)
                    spInst.FUN_14098d0e0()->FUN_1413d6e60(((const egf::EntityPtr*)(&pCube->entity))->operator egf::Entity*(), true);
            }
            bool bOn = true;
            FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&pCube->entity))->operator->()), 0xa0b6b179, *(bool const*)(&bOn));
            if (pCube->field44 != 1) {
                unsigned short nEffect = 9;
                ((const egf::EntityPtr*)(&pCube->entity))->operator->()->GetPropertyValue<unsigned short>(0xada5c5d2, nEffect);
                ((class CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(((const egf::EntityPtr*)(&pCube->entity))->operator egf::Entity*(), nEffect, 0, 1);
            }
        }
    }
    for (CMISESet_int::iterator itList = reinterpret_cast<CMISESet_int*>(&setDone)->begin(); (itList != reinterpret_cast<CMISESet_int*>(&setDone)->end()); ++itList)
        ((std::_Tree<std::_Tmap_traits<int, Unk_CMISCubeTimer, std::less<int>, efd::CustomAllocator<std::pair<int const, Unk_CMISCubeTimer>>, 0>>*)(void*)(&f1f8))->erase(*(int const*)(((int*)(&*itList))));
}

// ---- w138 batch 20 ----
extern Unk_Int3 DAT_143ab2388;                                                              // the none cell
bool FUN_1411279c0(Unk_Int3* pA, const Unk_Int3* pB);                                       // operator!=

// @0x1410badf0
Cube* CubeMapInformationService::FUN_1410badf0(int nGroup, Unk_CMISPawn* pPawn)
{
    if ((reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->find(nGroup) == reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()))
        return 0;
    Unk_Int3 cellBest = DAT_143ab2388;
    Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nGroup)));
    for (CMISESet_int::iterator it = reinterpret_cast<CMISESet_int*>(pList)->begin(); (it != reinterpret_cast<CMISESet_int*>(pList)->end()); ++it) {
        int nKey = *((int*)(&*it));
        Unk_Int3 cell = FUN_1408a0400(nKey);
        Cube* pCube = GetCubeAtCell(cell);
        if (pCube == 0)
            continue;
        if (pCube->field50 != nGroup)
            continue;
        if (FUN_1411279c0(&cellBest, &DAT_143ab2388)) {
            Vector3 ptBest;
            FUN_1408a15b0(cellBest, ptBest);
            Vector3 ptCube;
            FUN_1408a15b0(*(Unk_Int3*)&pCube->position, ptCube);
            if (FUN_140966f00(pPawn->vfunc_18(), ptCube) < FUN_140966f00(pPawn->vfunc_18(), ptBest))
                cellBest = *(Unk_Int3*)&pCube->position;
        } else {
            cellBest = *(Unk_Int3*)&pCube->position;
        }
    }
    if (FUN_1411279c0(&cellBest, &DAT_143ab2388))
        return GetCubeAtCell(cellBest);
    return 0;
}

// ---- w138 batch 21 ----

// @0x1410d0e30
void CubeMapInformationService::FUN_1410d0e30(egf::Entity* pEntity, MS2Ptr<Cube> spCube)
{
    if (pEntity == 0 || spCube.IsNull()) {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp", 0x166a), 0));
        return;
    }
    if (spCube->field6c != 0) {
        bool bOn = true;
        FUN_14098c6e0((class Unk_CachedEntity*)(pEntity), 0x38141815, *(bool const*)(&bOn));
        if ((*(Vector3*)&spCube->offset).FUN_140552700(DAT_143b01a60))
            GeneratePhysX(Unk_EntRef((Unk_Entity*)pEntity), *(Vector3*)&spCube->offset);
        else
            FUN_1410c5570(Unk_EntRef((Unk_Entity*)pEntity));
    }
    if ((const char*)spCube->textA0 == 0) {
        efd::utf8string strName((const char*)spCube->textA0);
        pEntity->SetPropertyValue<efd::utf8string>(0xde5dd580, strName);
    }
    if (spCube->fieldA8 == 8 || spCube->fieldA8 == 9) {
        if (((class CPhysXHelper*)FUN_1409f7ca0())->FUN_141689a10(pEntity)) {
            (pEntity)->SetPropertyValue<int>(0xada5c5d2, spCube->fieldA8);
            ((class CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(pEntity, (short)spCube->fieldA8, 0, 0);
        }
    }
    int nKey = FUN_1408a03c0(spCube->position);
    if ((reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->find(nKey) != reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->end())) {
        if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->find(nKey) == reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end())) {
            if (IsCellInBounds(spCube->position) == 0) {
                bool bFlag = false;
                ((const egf::EntityPtr*)(&spCube->entity))->operator->()->GetPropertyValue(0x23f9860e, bFlag);
                if (bFlag) {
                    Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
                    if (spInst.FUN_14098d090() != 0)
                        spInst.FUN_14098d0e0()->FUN_1413d6e60(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*(), false);
                }
                bool bOff = false;
                FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()), 0xa0b6b179, *(bool const*)(&bOff));
            }
        }
    }
}

// ---- w138 batch 22 ----
void FUN_1412314e0(Unk_CMISMagicCube*, Vector3 ptPos, ATL::CAtlArray<Unk_CMISSlot>* pOut);   // the objects around a point (MS2Ptr<CFunctionCubeObject>)
int FUN_14112e290(Unk_CMISObj498*);                                                         // the object kind (1 = cube)
bool FUN_141126b90(Unk_PayloadPtr<NoticeCubeInfo>*, int);                                   // operator==
void* FUN_1411284a0(Unk_PayloadPtr<NoticeCubeInfo>*);                                       // operator->
class NoticeCubeInfo   // C3: member view for the former free stand-ins
{
public:
    int GetN20() const;
};

// @0x1410c8e40
void CubeMapInformationService::FUN_1410c8e40()
{
    Unk_CMISPawn* pPawn = reinterpret_cast<Unk_CMISPawn*>(((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0()));
    if (pPawn == 0)
        return;
    Vector3 ptPawn = pPawn->FUN_1416767d0();
    // The near objects are 16-byte MS2Ptr<CFunctionCubeObject> handles: GetAt steps by 16 (0x141127a10) and the
    // array dtor (0x141123410) releases each one.
    ATL::CAtlArray<Unk_CMISSlot> aNear;
    FUN_1412314e0(((class Unk_CMISMagicCube*)FUN_1409670b0()), ptPawn, &aNear);
    CMISSet_MS2Ptr_CFunctionCubeObject found;
    for (unsigned __int64 i = 0; i < aNear.GetCount(); i++) {
        Unk_CMISSlot slot(aNear.GetAt(i));
        if (FUN_14112e290(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&slot))->operator->())) != 1)
            continue;
        MS2Ptr<Cube> spCube(GetCubeByKey(FUN_14112e110(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(&slot))->operator->()))));
        if (spCube == 0)
            continue;
        if (FUN_141126b90(&spCube->notice, 0))
            continue;
        float fLen = ptPawn.FUN_140965c40(spCube->FUN_1408b5370()).FUN_140967ac0();
        float fRad = 150.0f * ((float)((class NoticeCubeInfo*)(void*)(FUN_1411284a0(&spCube->notice)))->GetN20() - 0.5f);
        if (fLen > fRad)
            continue;
        found.insert(*reinterpret_cast<MS2Ptr<CFunctionCubeObject>*>(&slot));
    }
    CMISSet_MS2Ptr_CFunctionCubeObject::iterator itCur;
    for (itCur = reinterpret_cast<CMISSet_MS2Ptr_CFunctionCubeObject*>(&f498)->begin(); itCur != reinterpret_cast<CMISSet_MS2Ptr_CFunctionCubeObject*>(&f498)->end(); itCur++) {
        if (found.find(*itCur) == found.end())
            ((class CFunctionCubeObject*)(struct Unk_CMISObj498*)(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(FUN_141128b30(reinterpret_cast<Unk_CMISIter<284>*>(&itCur))))->operator->())))->HideNotice();
    }
    if (found.size() > 0) {
        for (itCur = found.begin(); itCur != found.end(); itCur++) {
            if (reinterpret_cast<CMISSet_MS2Ptr_CFunctionCubeObject*>(&f498)->find(*itCur) == reinterpret_cast<CMISSet_MS2Ptr_CFunctionCubeObject*>(&f498)->end())
                ((class CFunctionCubeObject*)(class Unk_CMISObj498*)(((Unk_CMISObj498*)(void*)((MS2Ptr<CFunctionCubeObject>*)(void*)(FUN_141128b30(reinterpret_cast<Unk_CMISIter<284>*>(&itCur))))->operator->())))->FUN_1412273b0();
        }
    }
    *reinterpret_cast<CMISSet_MS2Ptr_CFunctionCubeObject*>(&f498) = found;
}

// ---- w138 batch 23 ----
struct Unk_CMISNearMap;                                                                     // map: group -> nearest cell of the group
struct Unk_CMISNearIter { void* m_p; };
Unk_CMISNearIter* FUN_1411518b0(Unk_CMISNearMap*, Unk_CMISNearIter*);                       // end
Unk_CMISNearIter* FUN_141156f60(Unk_CMISNearMap*, Unk_CMISNearIter*, const int*);           // find
bool FUN_141127340(Unk_CMISNearIter*, Unk_CMISNearIter*);                                   // operator!=
char* FUN_141127ad0(void*, void*);   // C3: was FUN_141127ad0

// @0x1410bb170
void CubeMapInformationService::FUN_1410bb170(Unk_CMISPawn* pPawn, int nDx, int nDy, int nDz, Unk_CMISNearMap* pMap)
{
    Vector3 ptA;
    GetCellInFrontOfActor(reinterpret_cast<PCBase*>(pPawn), -150.0f, &ptA, 0);
    Vector3 ptB;
    GetCellPosition(ptA, &ptB);
    Cube* pBase = GetCubeAtPoint(ptB);
    if (pBase == 0) {
        ptB.z = ptB.z + 150.0f;
        pBase = GetCubeAtPoint(ptB);
        if (pBase == 0)
            return;
    }
    for (int x = pBase->position.x - nDx; x <= pBase->position.x + nDx; x++) {
        for (int y = pBase->position.y - nDy; y <= pBase->position.y + nDy; y++) {
            for (int z = pBase->position.z - nDz; z <= pBase->position.z + nDz; z++) {
                Unk_Int3 cell(x, y, z);
                Cube* pCube = GetCubeAtCell(cell);
                if (pCube == 0)
                    continue;
                if (pCube->field50 == 0)
                    continue;
                if ((reinterpret_cast<CMISMap_int_Unk_Int3*>(pMap)->find(pCube->field50) != reinterpret_cast<CMISMap_int_Unk_Int3*>(pMap)->end())) {
                    Vector3 ptNear;
                    FUN_1408a15b0(*((struct Unk_Int3*)FUN_141127ad0((void*)(pMap), (void*)(&pCube->field50))), ptNear);
                    Vector3 ptThis;
                    FUN_1408a15b0(*(Unk_Int3*)&pCube->position, ptThis);
                    if (FUN_140966f00(pPawn->vfunc_18(), ptThis) < FUN_140966f00(pPawn->vfunc_18(), ptNear))
                        *((struct Unk_Int3*)FUN_141127ad0((void*)(pMap), (void*)(&pCube->field50))) = pCube->position;
                } else {
                    *((struct Unk_Int3*)FUN_141127ad0((void*)(pMap), (void*)(&pCube->field50))) = pCube->position;
                }
            }
        }
    }
}

// ---- w138 batch 24 ----
Unk_CMISIter<265>* FUN_141151d30(Unk_CMISTree<265>*, Unk_CMISIter<265>*);                   // end
Unk_CMISIter<265>* FUN_141157ac0(Unk_CMISTree<265>*, Unk_CMISIter<265>*, const int*);       // find
bool FUN_141126f10(Unk_CMISIter<265>*, Unk_CMISIter<265>*);                                 // operator==
int FUN_1408a01e0(CString strType);                                                         // the cube kind of a name

// @0x1410bca70
bool CubeMapInformationService::FUN_1410bca70(__int64 nOwner, Unk_Int3 pt, float fRot, int nField50, int nField54, int nUnused, int nFieldD8)
{
    int nCell = FUN_1408a03c0(pt);
    if ((reinterpret_cast<CMISEMap_int_EntityID*>(&f2e0)->find(nCell) == reinterpret_cast<CMISEMap_int_EntityID*>(&f2e0)->end()))
        return false;
    Unk_CMISEntityRef idOld(*((struct Unk_CMISEntityRef*)FUN_141127ed0((void*)(&f2e0), (void*)(&nCell))));
    egf::EntityPtr spOld(static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411cf440(*reinterpret_cast<const egf::EntityID*>(&idOld)));
    if ((&spOld)->operator==((egf::Entity*)(0)))
        return false;
    NiPoint3 ptCell = reinterpret_cast<const NiPoint3&>(DAT_143b01a60);
    FUN_1408a15b0(pt, reinterpret_cast<Vector3&>(ptCell));
    NiPoint3 ptRot = reinterpret_cast<const NiPoint3&>(DAT_143b01a60);
    ptRot.z = fRot;
    int nKind = 0;
    efd::utf8string strKind("None");
    ((const egf::EntityPtr*)(&spOld))->operator->()->GetPropertyValue<efd::utf8string>(0x15014205, strKind);
    nKind = FUN_1408a01e0(CString(strKind.c_str()));
    egf::EntityPtr spNew = static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411ce7c0(efd::utf8string("MS2CubeProp"),
        efd::utf8string("urn:gamebryo-scenegraph:Empty"), ptCell, ptRot, 1.0f, 0, 0);
    if ((&spNew)->operator==((egf::Entity*)(0)))
        return false;
    int nFlag = 0;
    if (((egf::FlatModel*)(Unk_CMISFlatModel*)(((Unk_CMISFlatModel*)((class Unk_CMISFlatModel*)((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spOld))->operator->()))->GetModel()))))->ContainsModel(0xd8dea70d))
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
    reinterpret_cast<float&>(spCube->fieldD4) = fRot;
    *(MS2Ptr<Cube>*)(FUN_141128190(&f78, ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spNew))->operator->()))->GetEntityID()))) = spCube;
    return true;
}

// ---- w142 batch 1 ----
#include <NiTexturingProperty.h>
#include <NiMesh.h>
#include "ms2/client/ms2/nifeffectparam.h"   // C3: CNifLoadingService::GetTexture
class Unk_ResourceMgr* FUN_140a0afd0();   // C3: was FUN_140a0afd0
class Unk_NodeQueue                                                                         // scene walker (0x30 bytes; ctor 0x14098cb80, dtor 0x14098cf00)
{
public:
    Unk_NodeQueue(NiAVObject* pRoot);
    ~Unk_NodeQueue();
    NiAVObject* Next(bool bDescend);
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5;
};   // C3: unit-local view
MS2_CHECK_SIZE(Unk_NodeQueue, 0x30);

// @0x1410cab10
void CubeMapInformationService::FUN_1410cab10(Cube* pCube)
{
    bool bFlag = false;
    ((const egf::EntityPtr*)(&pCube->entity))->operator->()->GetPropertyValue(0x23f9860e, bFlag);
    if (bFlag) {
        Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
        if (spInst.FUN_14098d090() != 0) {
            if (spInst.FUN_14098d0e0()->FUN_1413d6f40(((const egf::EntityPtr*)(&pCube->entity))->operator egf::Entity*()) != 0) {
                bool bOn = true;
                FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&pCube->entity))->operator->()), 0xa0b6b179, *(bool const*)(&bOn));
            }
        }
    }
    int nPick = rand() % 4;
    CString strTex = ((struct Unk_CMISConsts*)FUN_1401d31f0())->m_strCubeFlash0;
    switch (nPick) {
    case 0:
        strTex += ((struct Unk_CMISConsts*)FUN_1401d31f0())->m_strCubeFlash1;
        break;
    case 1:
        strTex += ((struct Unk_CMISConsts*)FUN_1401d31f0())->m_strCubeFlash2;
        break;
    case 2:
        strTex += ((struct Unk_CMISConsts*)FUN_1401d31f0())->m_strCubeFlash3;
        break;
    case 3:
        strTex += ((struct Unk_CMISConsts*)FUN_1401d31f0())->m_strCubeFlash4;
        break;
    }
    efd::SmartPointer<NiTexture> spTexture = ((class CNifLoadingService*)FUN_140a0afd0())->GetTexture(strTex, 1);
    Unk_CMISSvcPtr spInst2(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
    NiAVObject* pRoot = FUN_141b6efc0(((const egf::EntityPtr*)(&pCube->entity))->operator egf::Entity*());
    if (pRoot != 0) {
        Unk_NodeQueue iter(pRoot);
        while (NiAVObject* pObj = iter.Next(true)) {
            NiMesh* pMesh = NiDynamicCast(NiMesh, pObj);
            if (pMesh != 0) {
                NiTexturingProperty* pTex = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(8));
                if (((class NiTexturingProperty*)(class NiTexturingProperty*)(pTex))->GetBaseMap() == 0)
                    continue;
                NiTexturingProperty::Map* pMap = NiNew NiTexturingProperty::Map;
                pMap->SetFilterMode(((class NiTexturingProperty*)(class NiTexturingProperty*)(pTex))->GetBaseMap()->GetFilterMode());
                ((NiTexturingProperty::Map*)(void*)(pMap))->SetTexture((class NiTexture*)(spTexture));
                pTex->SetDecalMap(0, pMap);
                pMesh->UpdateProperties();
                break;
            }
        }
        pRoot->UpdateProperties();
        pRoot->UpdateEffects();
        pRoot->Update(0.0f, true);
    }
}

// ---- w142 batch 2: cf160 / c1330 ----
class ObjectWeaponInfo { public: ObjectWeaponInfo(); void* m_unk[11]; };                    // 0x58 bytes, ctor 0x1408b45b0
MS2_CHECK_SIZE(ObjectWeaponInfo, 0x58);
void FUN_1408a1640(Cube* pCube);
void FUN_141126970(Unk_CMISCell56* pDst, Unk_CMISCell56* pSrc);                             // operator=
char* FUN_141127b50(void*, void*);   // C3: was FUN_141127b50
const efd::utf8string& FUN_14112e120(egf::Entity* pEntity);                                // the entity's model name
efd::Color FUN_1413fa320(egf::Entity* pEntity);                                             // the entity's colour (meshinstancing.cpp)
void FUN_1402bd040(Vector3* p);

// @0x1410c1330
MS2Ptr<Cube> CubeMapInformationService::FUN_1410c1330(Vector3 ptWorld, float fUnused, CubeItemInfo* pInfo, int nKind,
    egf::EntityPtr spEnt, bool bUnused, int nField50)
{
    Unk_Int3 cell = FUN_1408a1430(ptWorld);
    int nKey = FUN_1408a03c0(cell);
    if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->find(nKey) != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()) != 0)
        return MS2Ptr<Cube>(0);
    MS2Ptr<Cube> spCube(new Cube);
    spCube->position = cell;
    spCube->item->FUN_1408b3700(pInfo);
    spCube->entity = spEnt;
    spCube->field44 = nKind;
    spCube->field50 = nField50;
    FUN_1408a1640(spCube.get());
    bool bFlag = false;
    if (((const egf::EntityPtr*)(&spEnt))->operator egf::Entity*() != 0) {
        ((const egf::EntityPtr*)(&spEnt))->operator->()->GetPropertyValue(0x9ea356ad, bFlag);
        if (bFlag) {
            spCube->weapon = new ObjectWeaponInfo;
            ((ATL::CAtlArray<int, ATL::CElementTraits<int>>*)(void*)(&a458))->Add(nKey);
        }
    }
    *FUN_141127cd0(&f98, &nKey) = spCube;
    *FUN_141128190(&fa8, ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID())) = spCube;
    if (spCube->field48 != 0)
        *FUN_141127cd0(&fb8, &nKey) = spCube;
    if (spCube->field70 != 0 && spCube->field6c != 0)
        ((class Unk_CubeHeightIndex*)(void*)(&f2a8))->FUN_1410b2510(cell.x, cell.y, cell.z);
    if ((reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->find(spCube->field50) == reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()) != 0) {
        Unk_CMISIntList empty;
        FUN_141126700(((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&spCube->field50))), &empty);
    }
    efd::set<int, std::less<int>>& cubeKeys = *reinterpret_cast<efd::set<int, std::less<int>>*>(FUN_141127e10((void*)(&fd8), (void*)(&spCube->field50)));
    cubeKeys.insert(nKey);
    Unk_CMISCell val;
    val.m_name = FUN_14112e120(((const egf::EntityPtr*)(&spEnt))->operator->());
    reinterpret_cast<efd::Color&>(val.m_a) = FUN_1413fa320(((const egf::EntityPtr*)(&spEnt))->operator egf::Entity*());
    ((const egf::EntityPtr*)(&spEnt))->operator->()->GetPropertyValue<efd::Point3>(0x68c7c29d, reinterpret_cast<efd::Point3&>(val.m_d));
    FUN_141126970(((struct Unk_CMISCell56*)FUN_141127b50((void*)(&f2b8), (void*)(&nKey))), reinterpret_cast<Unk_CMISCell56*>(&val));
    return spCube;
}

// @0x1410cf160
void CubeMapInformationService::FUN_1410cf160(egf::Entity* pEntity)
{
    if (((egf::FlatModel*)(Unk_CMISFlatModel*)(((class Unk_CMISFlatModel*)((egf::Entity*)(void*)(pEntity))->GetModel())))->ContainsModel(0xf01a7608)) {
        int nGroup = 0;
        pEntity->GetPropertyValue<int>(0x85ef19e7, nGroup);
        FUN_1410bbf20(nGroup, pEntity->GetEntityID());
    } else if (((egf::FlatModel*)(Unk_CMISFlatModel*)(((class Unk_CMISFlatModel*)((egf::Entity*)(void*)(pEntity))->GetModel())))->ContainsModel(0xd8dea70d)) {
        efd::Point3 pt;
        pEntity->GetPropertyValue<efd::Point3>(0xfd95ca52, pt);
        int nField50 = 0;
        pEntity->GetPropertyValue<int>(0x85ef19e7, nField50);
        efd::utf8string strKind("None");
        pEntity->GetPropertyValue<efd::utf8string>(0x15014205, strKind);
        int nKind = FUN_1408a01e0(CString(strKind.c_str()));
        bool bAnimatable = false;
        pEntity->GetPropertyValue(0x38141815, bAnimatable);
        if (bAnimatable)
            FUN_1410c5570(Unk_EntRef((Unk_Entity*)pEntity));
        MS2Ptr<Cube> spCube = FUN_1410c1330(*reinterpret_cast<Vector3*>(&pt), 0.0f, 0, nKind, egf::EntityPtr(pEntity), false, nField50);
        if (spCube.get() != 0)
            spCube->field70 = 1;
    } else if (((egf::FlatModel*)(Unk_CMISFlatModel*)(((class Unk_CMISFlatModel*)((egf::Entity*)(void*)(pEntity))->GetModel())))->ContainsModel(0xc9cd2193)) {
        bool bAnimatable = false;
        pEntity->GetPropertyValue(0x38141815, bAnimatable);
        if (bAnimatable)
            FUN_1410c5570(Unk_EntRef((Unk_Entity*)pEntity));
    }
    if (((egf::FlatModel*)(Unk_CMISFlatModel*)(((class Unk_CMISFlatModel*)((egf::Entity*)(void*)(pEntity))->GetModel())))->ContainsModel(0xe34a6afd)) {
        int nValue = 0;
        if ((pEntity)->GetPropertyValue<unsigned int>(0x1a1899fc, *(unsigned int*)(&nValue)) == 0 && nValue != 0) {
            efd::Point3 pt;
            pEntity->GetPropertyValue<efd::Point3>(0xfd95ca52, pt);
            int nKey = FUN_1408a13d0(*reinterpret_cast<Vector3*>(&pt));
            *(egf::EntityID*)(((struct Unk_CMISEntityRef*)FUN_141127ed0((void*)(&f2e0), (void*)(&nKey)))) = *(const egf::EntityID*)&(*((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(pEntity))->GetEntityID()));
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
int* FUN_1411283c0(class Unk_ArrayInt*, unsigned __int64);   // C3: was FUN_1411283c0

// @0x1410ba5f0
int CubeMapInformationService::FUN_1410ba5f0(Unk_Int3 pt, Vector3 ptRef)
{
    Cube* pCube = GetCubeAtCell(pt);
    if (pCube != 0 && pCube->field60 != 0) {
        Vector3 ptDir = DAT_143b01a60;
        ptDir.z = *(float*)&pCube->fieldD4;
        return VectorToDirection(ptDir);
    }
    if (ptRef.z < 0.0)
        ptRef.z = (float)(int)((ptRef.z - 89.0f) / 90.0f) * 90.0f;
    else
        ptRef.z = (float)(int)((ptRef.z + 89.0f) / 90.0f) * 90.0f;
    int nStart = VectorToDirection(ptRef);
    Unk_CMISIntVec vecDir;
    int nDir0 = 0; FUN_14115a9f0(&vecDir, &nDir0);
    int nDir1 = 1; FUN_14115a9f0(&vecDir, &nDir1);
    int nDir2 = 2; FUN_14115a9f0(&vecDir, &nDir2);
    int nDir3 = 3; FUN_14115a9f0(&vecDir, &nDir3);
    int nDir4 = 4; FUN_14115a9f0(&vecDir, &nDir4);
    int nDir5 = 2; FUN_14115a9f0(&vecDir, &nDir5);
    int nDir6 = 3; FUN_14115a9f0(&vecDir, &nDir6);
    int nDir7 = 4; FUN_14115a9f0(&vecDir, &nDir7);
    int nTry = 0;
    __int64 nFirst = nStart;
    for (unsigned __int64 nIdx = nFirst; nTry < 4 && nIdx < FUN_14115af60(&vecDir); nIdx++) {
        nTry++;
        Unk_Int3 cell = pt;
        int nDirNow = *FUN_1411283c0((class Unk_ArrayInt*)(&vecDir), nIdx);
        switch (nDirNow) {
        case 1: {
            cell.x--;
            Cube* pNear = GetCubeAtCell(cell);
            if (pNear != 0 && pNear->field68 != 0)
                return 1;
            break;
        }
        case 2: {
            cell.y++;
            Cube* pNear = GetCubeAtCell(cell);
            if (pNear != 0 && pNear->field68 != 0)
                return 2;
            break;
        }
        case 3: {
            cell.x++;
            Cube* pNear = GetCubeAtCell(cell);
            if (pNear != 0 && pNear->field68 != 0)
                return 3;
            break;
        }
        case 4: {
            cell.y--;
            Cube* pNear = GetCubeAtCell(cell);
            if (pNear != 0 && pNear->field68 != 0)
                return 4;
            break;
        }
        }
    }
    return 0;
}

void FUN_140b27f00(void*, unsigned int, void*);   // C3: was FUN_140b27f00
void FUN_141568a90(egf::Entity* pEntity);
unsigned __int64 FUN_1410db860(Unk_CMISLog* pLog, int nLevel, int nCategory, const wchar_t* pFormat, const int* pA, const int* pB,
    const int* pC, const char* const* pD);

// @0x1410be0c0
bool CubeMapInformationService::FUN_1410be0c0(Unk_Int3 pt, int nGroup, int nFloor, Unk_CMISCell56* pCell)
{
    int nKey = FUN_1408a03c0(pt);
    if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->find(nKey) != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()) != 0)
        return false;
    Vector3 ptCell = DAT_143b01a60;
    FUN_1408a15b0(pt, ptCell);
    Vector3 ptRot = DAT_143b01a60;
    egf::EntityPtr spEnt = static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411ce7c0(
        efd::utf8string(reinterpret_cast<const efd::utf8string&>(pCell->m_aName)), efd::utf8string(""),
        *(NiPoint3*)&ptCell, *(NiPoint3*)&ptRot, 1.0f, 0, 0);
    if (((const egf::EntityPtr*)(&spEnt))->operator egf::Entity*() == 0) {
        const char* pszModel = reinterpret_cast<efd::utf8string*>(&pCell->m_aName)->c_str();
        FUN_1410db860(((class Unk_CMISLog*)GetLogString()), 1, 0x13, L"[ERROR] Create Default Cube Error = {0}, {1}, {2}, Model = {3}", &pt.x, &pt.y, &pt.z, &pszModel);
        return false;
    }
    efd::utf8string strKind("None");
    ((const egf::EntityPtr*)(&spEnt))->operator->()->GetPropertyValue<efd::utf8string>(0x15014205, strKind);
    int nKind = FUN_1408a01e0(CString(strKind.c_str()));
    FUN_140b27f00((void*)(((const egf::EntityPtr*)(&spEnt))->operator->()), 0x213f5f94, (void*)(&pCell->m_pos));
    FUN_141568a90(((const egf::EntityPtr*)(&spEnt))->operator egf::Entity*());
    (((const egf::EntityPtr*)(&spEnt))->operator->())->SetPropertyValue<efd::Point3>(0x68c7c29d, *(const efd::Point3*)(&pCell->m_rot));
    MS2Ptr<Cube> spCube(new Cube);
    spCube->position = pt;
    ((class CubeItemInfo*)(class CubeItemInfo*)(spCube->item.get()))->FUN_1408b3810();
    spCube->entity = spEnt;
    spCube->field44 = nKind;
    spCube->field50 = nGroup;
    spCube->field54 = nFloor;
    spCube->field48 = 0;
    spCube->field70 = 1;
    spCube->field6c = 1;
    *(Vector3*)&spCube->offset = Vector3(150.0f, 150.0f, 150.0f);
    FUN_1408a1640(spCube.get());
    *FUN_141128190(&f78, ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spEnt))->operator->()))->GetEntityID())) = spCube;
    return true;
}

void FUN_1411225f0(Unk_CMISBucket* p);                                                      // ctor
void FUN_141125670(Unk_CMISBucket* p);                                                      // dtor
void FUN_141126670(Unk_CMISBucket* pDst, Unk_CMISBucket* pSrc);                             // operator=
void FUN_141126760(Unk_CMISCubeList* pDst, Unk_CMISCubeList* pSrc);                         // operator=

// @0x1410be6e0
void CubeMapInformationService::FUN_1410be6e0(MS2Ptr<Cube> spCube)
{
    if (((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20() == 0)
        return;
    MS2Ptr<CItemData> spItem = FUN_14053f870(((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20());
    if (spItem == 0)
        return;
    MS2Ptr<ItemHousing> rec = TSingleton<CItemDataTable>::GetInstance()->GetHousing(((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20());
    if (rec == 0)
        return;
    if (rec->setItemID == 0)
        return;
    UGCMapSetItemDataPtr spSet = TSingleton<CUGCMapSetItemTable>::GetInstance()->FUN_140b9df60(rec->setItemID);
    if (spSet == 0)
        return;
    bool bFound = false;
    unsigned nItem = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
    if (spSet->m_items.find(nItem) != spSet->m_items.end())
        bFound = true;
    if (!bFound) {
        int nItemLog = ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20();
        ((class Unk_CMISLog*)GetLogString())->FUN_1403d7960(1, 0x13, L"세트아이템으로 지정된 아이템({0})이지만 SetItemTable({1})에는 등록되지 않았습니다", &nItemLog, (const int*)&rec->setItemID);
        return;
    }
    CMISMap_int_Map_unsigned_int_Set_int::iterator itOuter = reinterpret_cast<CMISMap_int_Map_unsigned_int_Set_int*>(&f440)->find(spCube->field50);
    if (itOuter == reinterpret_cast<CMISMap_int_Map_unsigned_int_Set_int*>(&f440)->end()) {
        CMISMap_u_int_Set_int bucketNew;
        *reinterpret_cast<CMISMap_u_int_Set_int*>(FUN_141127d50((void*)(&f440), (void*)(&spCube->field50))) = bucketNew;
    }
    Unk_CMISBucket* pBucket = ((struct Unk_CMISBucket*)FUN_141127d50((void*)(&f440), (void*)(&spCube->field50)));
    if (reinterpret_cast<CMISMap_u_int_Set_int*>(pBucket)->find(rec->setItemID) == reinterpret_cast<CMISMap_u_int_Set_int*>(pBucket)->end()) {
        CMISSet_int lstNew;
        *reinterpret_cast<CMISSet_int*>(FUN_141128050((void*)(pBucket), (void*)(&rec->setItemID))) = lstNew;
    }
    int nCell = FUN_1408a03c0(spCube->position);
    Unk_CMISCubeList* pCells = ((struct Unk_CMISCubeList*)FUN_141128050((void*)(pBucket), (void*)(&rec->setItemID)));
    if ((reinterpret_cast<CMISSet_int*>(pCells)->find(nCell) == reinterpret_cast<CMISSet_int*>(pCells)->end()) != 0) {
        Unk_CMISInsRes itIns;
        FUN_14035d1e0(pCells, &itIns, &nCell);
    }
}

struct Unk_CMISCubePtrSet { void* m_a; void* m_b; void* m_c; };                             // set of cube pointers
void FUN_14115a900(Unk_CMISCubePtrSet* pSet, Cube** ppCube);                                // insert
void FUN_14115a8d0(Unk_CMISCubePtrSet* pSet, Cube** ppCube);                                // insert
bool FUN_1408a8dd0(Unk_CubeOwnerPtr* pPtr, int);                                            // operator==
int* FUN_141128660(Unk_CMISIter<262>*);                                                     // operator*
Unk_CMISListIter* FUN_141158620(Unk_CMISIntList*, Unk_CMISListIter*, const int*);           // find
int FUN_140707710(int);

// @0x1410b9e90
int CubeMapInformationService::FUN_1410b9e90(__int64 nOwnerId, Unk_CMISCubePtrSet* pOut)
{
    if (DAT_143ae0fb4 != 0) {
        for (CMISEMap_int_MS2Ptr_Cube::iterator itCube = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->begin(); (itCube != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()); FUN_141129b50((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<260>*>(&itCube)))) {
            MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&itCube))->second);
            if (spCube->field48 == 0)
                continue;
            if ((&spCube->entity)->operator==((egf::Entity*)(0)))
                continue;
            Cube* pCube = spCube.get();
            FUN_14115a8d0(pOut, &pCube);
        }
        return 1;
    }
    for (CMISEMap_int_set_int::iterator itGroup = reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->begin(); (itGroup != reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()); FUN_141129bb0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<262>*>(&itGroup)))) {
        int nGroup = *FUN_141128660(reinterpret_cast<Unk_CMISIter<262>*>(&itGroup));
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (FUN_1408a8dd0(&spOwner, 0))
            continue;
        if (spOwner->ownerID != nOwnerId)
            continue;
        if (f218->groups.find(nGroup) == f218->groups.end())
            continue;
        Unk_UGCGroup& group = f218->groups[nGroup];
        int nDepth = 0;
        if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130())
            nDepth = f2fc;
        else
            nDepth = group.heightLimit;
        Unk_CMISIntList setSeen;
        Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nGroup)));
        for (CMISESet_int::iterator it = reinterpret_cast<CMISESet_int*>(pList)->begin(); (it != reinterpret_cast<CMISESet_int*>(pList)->end()); ++it) {
            int nKey = *((int*)(&*it));
            for (int z = 0; z <= nDepth; z++) {
                Unk_Int3 cell = FUN_1408a0400(nKey);
                cell.z = cell.z + z;
                int nCellKey = FUN_1408a03c0(cell);
                if (reinterpret_cast<CMISESet_int*>(&setSeen)->find(nCellKey) != reinterpret_cast<CMISESet_int*>(&setSeen)->end())
                    continue;
                int nNewKey = FUN_1408a03c0(cell);
                Unk_CMISInsRes itIns;
                FUN_14111d290(reinterpret_cast<Unk_CMISTree<267>*>(&setSeen), &itIns, &nNewKey);
                Cube* pCube = GetCubeAtCell(cell);
                if (pCube != 0 && FUN_1407071e0(pCube->fieldB4) != 0 && FUN_140707710(pCube->fieldB4) != 0
                    && FUN_140707660(pCube->fieldB4) == 0)
                    FUN_14115a900(pOut, &pCube);
            }
        }
        break;
    }
    return 1;
}

// ---- w142 batch 4 ----
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxPhysics.h>
#include <efdPhysX/PhysXTypes.h>
#include <egfPhysX/EntityActorData.h>
#pragma pop_macro("min")
#pragma pop_macro("max")
char* FUN_141128150(void*, void*);   // C3: was FUN_141128150
bool FUN_141127780(Unk_CMISIter<257>*, Unk_CMISIter<257>*);
extern Vector3 DAT_143b01a60;

// @0x1410c5680
void CubeMapInformationService::GeneratePhysX(Unk_EntRef spEnt, Vector3 pt)
{
    if ((reinterpret_cast<CMISEMap_EntityID_int64*>(&f48)->find(*reinterpret_cast<const egf::EntityID*>(((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spEnt))->operator->()))->GetEntityID()))) != reinterpret_cast<CMISEMap_EntityID_int64*>(&f48)->end()) != 0)
        return;
    NxActor* pActor = 0;
    NxScene* pScene = reinterpret_cast<NxScene*>(((class Unk_CMISPhysScene*)((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a1c0()));
    if (pScene == 0)
        return;
    efd::Point3 ptPos;
    reinterpret_cast<egf::Entity*>(((const egf::EntityPtr*)(&spEnt))->operator->())->GetPropertyValue<efd::Point3>(0xfd95ca52, ptPos);
    efd::Point3 ptRot;
    reinterpret_cast<egf::Entity*>(((const egf::EntityPtr*)(&spEnt))->operator->())->GetPropertyValue<efd::Point3>(0x68c7c29d, ptRot);
    NxVec3 kPos;
    efdPhysX::PhysXTypes::Point3ToNxVec3(ptPos, kPos);
    Vector3 size = pt;
    NxBoxShapeDesc box;
    box.dimensions.set(size.x, size.y, size.z);
    box.dimensions = box.dimensions * 0.01f * 0.5f;
    box.groupsMask.bits0 = 0xffffffff;
    box.shapeFlags &= 0xffedffff;
    NxActorDesc actorDesc;
    actorDesc.body = 0;
    actorDesc.shapes.pushBack(&box);
    efd::Point3 ptPose = ptPos;
    actorDesc.globalPose.t = NxVec3(ptPose.x, ptPose.y, ptPose.z);
    actorDesc.globalPose.t = actorDesc.globalPose.t * 0.01f;
    actorDesc.globalPose.t.z += box.dimensions.z;
    actorDesc.globalPose.M.rotZ((ptRot.z * 3.1415927f) / 180.0f);
    ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a540(0);
    pActor = pScene->createActor(actorDesc);
    if (pActor != 0) {
        pActor->setName("CubeMapInformationService::GeneratePhysX");
        NxU32 nShapes = pActor->getNbShapes();
        NxShape* const* ppShapes = pActor->getShapes();
        for (NxU32 i = 0; i < nShapes; ++i) {
            NxShape* pShape = ppShapes[i];
            pShape->setGroup(9);
        }
        efd::SmartPointer<egfPhysX::EntityActorData> sp(new (efd::MemHint(efd::MemHint::NONE)) egfPhysX::EntityActorData(reinterpret_cast<const egf::EntityPtr&>(spEnt)));
        pActor->userData = sp.operator egfPhysX::EntityActorData*();
        *reinterpret_cast<void**>(FUN_141128110(&f48, (void*)((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spEnt))->operator->()))->GetEntityID()))) = pActor;
        *((efd::SmartPointer<egfPhysX::EntityActorData>*)FUN_141128150((void*)(&f58), (void*)(((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spEnt))->operator->()))->GetEntityID())))) = sp;
    }
    ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a570();
}

// @0x1410c5ba0
void CubeMapInformationService::GenerateFloorPhysX()
{
    DestroyFloorPhysX();
    NxScene* pScene = reinterpret_cast<NxScene*>(((class Unk_CMISPhysScene*)((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a1c0()));
    if (pScene == 0)
        return;
    if (f218 == 0)
        return;
    if (f218->floors.find(f1dc) == f218->floors.end())
        return;
    if (f218->floors.size() == f1dc)
        return;
    const Unk_UGCFloor& floor = f218->floors[f1dc];
    float fZ = floor.startHeight + (float)floor.field4 * 150.0f;
    Vector3 pos = DAT_143b01a60;
    pos.z = fZ;
    Vector3 rot = DAT_143b01a60;
    NxVec3 kPos;
    efdPhysX::PhysXTypes::Point3ToNxVec3(reinterpret_cast<const efd::Point3&>(pos), kPos);
    NxBoxShapeDesc box;
    box.dimensions.set(1500.0f, 1500.0f, 150.0f);
    box.dimensions = box.dimensions * 0.01f * 0.5f;
    box.groupsMask.bits0 = 0xffffffff;
    box.shapeFlags &= 0xffedffff;
    NxActorDesc actorDesc;
    actorDesc.body = 0;
    actorDesc.shapes.pushBack(&box);
    Vector3 pt = pos;
    actorDesc.globalPose.t = NxVec3(pt.x, pt.y, pt.z);
    actorDesc.globalPose.t = actorDesc.globalPose.t * 0.01f;
    actorDesc.globalPose.t.z += box.dimensions.z;
    actorDesc.globalPose.M.rotZ((rot.z * 3.1415927f) / 180.0f);
    ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a540(0);
    f40 = pScene->createActor(actorDesc);
    if (f40 != 0) {
        ((NxActor*)f40)->setName("CubeMapInformationService::GenerateFloorPhysX");
        NxU32 nShapes = ((NxActor*)f40)->getNbShapes();
        NxShape* const* ppShapes = ((NxActor*)f40)->getShapes();
        for (NxU32 i = 0; i < nShapes; ++i) {
            NxShape* pShape = ppShapes[i];
            pShape->setGroup(9);
        }
        ((NxActor*)f40)->userData = 0;
    }
    ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a570();
}

// @0x1410c6100
efd::Point3 FUN_1408a15b0(Unk_CubePoint, efd::Point3&);   // same function; Point3 result assigned through efd::Point3::operator=

void CubeMapInformationService::GenerateAreaPhysX(int n)
{
    RemovePhysActor(n);
    NxScene* pScene = reinterpret_cast<NxScene*>(((class Unk_CMISPhysScene*)((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a1c0()));
    if (pScene == 0)
        return;
    efd::Point3 ptLo = reinterpret_cast<const efd::Point3&>(DAT_143b01a60), ptHi = reinterpret_cast<const efd::Point3&>(DAT_143b01a60);
    ptLo = FUN_1408a15b0(p300, ptLo);
    ptHi = FUN_1408a15b0(p30c, ptHi);
    Vector3 size = DAT_143b01a60;
    efd::Point3 pos = ptLo;
    switch (n) {
    case 0:
        size.x = 150.0f;
        size.y = (ptHi.y - ptLo.y) + 300.0f;
        size.z = 150.0f * (float)(f2fc + 3);
        pos.x = pos.x - 150.0f;
        pos.y = (pos.y + size.y * 0.5f) - 225.0f;
        pos.z = pos.z + 150.0f;
        break;
    case 1:
        size.x = (ptHi.x - ptLo.x) + 150.0f;
        size.y = 150.0f;
        size.z = 150.0f * (float)(f2fc + 3);
        pos.x = (pos.x + size.x * 0.5f) - 75.0f;
        pos.y = pos.y - 150.0f;
        pos.z = pos.z + 150.0f;
        break;
    case 2:
        size.x = (ptHi.x - ptLo.x) + 150.0f;
        size.y = (ptHi.y - ptLo.y) + 150.0f;
        size.z = 300.0f;
        pos.x = (pos.x + size.x * 0.5f) - 75.0f;
        pos.y = (pos.y + size.y * 0.5f) - 75.0f;
        pos.z = pos.z + (150.0f + 150.0f * (float)(f2fc + 1));
        break;
    }
    Vector3 rot = DAT_143b01a60;
    NxVec3 kPos;
    efdPhysX::PhysXTypes::Point3ToNxVec3(pos, kPos);
    NxBoxShapeDesc box;
    box.dimensions.set(size.x, size.y, size.z);
    box.dimensions = box.dimensions * 0.01f * 0.5f;
    box.groupsMask.bits0 = 0xffffffff;
    box.shapeFlags &= 0xffedffff;
    NxActorDesc actorDesc;
    actorDesc.body = 0;
    actorDesc.shapes.pushBack(&box);
    efd::Point3 pt = pos;
    actorDesc.globalPose.t = NxVec3(pt.x, pt.y, pt.z);
    actorDesc.globalPose.t = actorDesc.globalPose.t * 0.01f;
    actorDesc.globalPose.t.z += box.dimensions.z;
    actorDesc.globalPose.M.rotZ((rot.z * 3.1415927f) / 180.0f);
    ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a540(0);
    f318[n] = pScene->createActor(actorDesc);
    if (f318[n] != 0) {
        ((NxActor*)f318[n])->setName("CubeMapInformationService::GenerateAreaPhysX");
        NxU32 nShapes = ((NxActor*)f318[n])->getNbShapes();
        NxShape* const* ppShapes = ((NxActor*)f318[n])->getShapes();
        for (NxU32 i = 0; i < nShapes; ++i) {
            NxShape* pShape = ppShapes[i];
            pShape->setGroup(7);
        }
        ((NxActor*)f318[n])->userData = 0;
    }
    ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a570();
}

// @0x1410c6b90
int CubeMapInformationService::FUN_1410c6b90(unsigned nMask, int* pOutGroup, int nMode, Unk_CMISEntityRef* pOutEnt)
{
    Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pRoster != 0) {
        efd::Point3 ptA;
        GetCellInFrontOfActor(reinterpret_cast<PCBase*>(pRoster), 0.0f, (Vector3*)&ptA, 1);
        efd::Point3 ptB;
        GetCellInFrontOfActor(reinterpret_cast<PCBase*>(pRoster), 0.0f, (Vector3*)&ptB, 0);
        Unk_Int3 cellA = FUN_1408a1430(reinterpret_cast<const Vector3&>(ptA));
        Unk_Int3 cellB = FUN_1408a1430(reinterpret_cast<const Vector3&>(ptB));
        for (CMISEMap_int_SmartPointer_Entity::iterator it = reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->begin(); (it != reinterpret_cast<CMISEMap_int_SmartPointer_Entity*>(&ff8)->end()); FUN_141129a80((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<264>*>(&it)))) {
            int nGroup = FUN_141128560(reinterpret_cast<Unk_CMISIter<264>*>(&it))->m_key;
            egf::EntityPtr spEnt = *(const egf::EntityPtr*)(&FUN_141128560(reinterpret_cast<Unk_CMISIter<264>*>(&it))->m_ref);
            if ((&spEnt)->operator==((egf::Entity*)(0)))
                continue;
            *(egf::EntityID*)(pOutEnt) = *(const egf::EntityID*)&(*((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spEnt))->operator->()))->GetEntityID()));
            bool bOwned = false;
            Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
            if (FUN_140965820(&spOwner) != 0)
                bOwned = true;
            if (nMode == 1 && !bOwned)
                continue;
            if (nMode == 2 && !bOwned)
                continue;
            if (nMode == 1 && spOwner->ownerID != ((PC*)pRoster)->FUN_141656ad0())
                continue;
            if (nMode == 2 && spOwner->ownerID == ((PC*)pRoster)->FUN_141656ad0())
                continue;
            Unk_CMISHouseRef spHouse(FUN_1410c7c20(nGroup, f1b0));
            if (spHouse.FUN_141128410() != 0 && (nMask & (unsigned)spHouse.FUN_1411284b0()->m_state) == 0)
                continue;
            if ((nMask & 2) && bOwned)
                continue;
            if ((nMask & 1) && !bOwned)
                continue;
            if ((nMask & 4) && bOwned)
                continue;
            Vector3 ptEnt = DAT_143b01a60;
            reinterpret_cast<egf::Entity*>(((const egf::EntityPtr*)(&spEnt))->operator->())->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(ptEnt));
            Unk_Int3 cell = FUN_1408a1430(ptEnt);
            if (FUN_1411272b0(&cell, &cellA) || FUN_1411272b0(&cell, &cellB)) {
                *pOutGroup = nGroup;
                return 1;
            }
        }
    }
    return 0;
}

// @0x1410d1320
int CubeMapInformationService::FUN_1410d1320(void* pArg, Vector3 pt, float fStep, Vector3* pOut)
{
    efd::Point3 ptProbe;
    efd::Point3 ptCenter;
    float fHalf = fStep * 0.5f;
    FUN_1408a15b0(static_cast<Cube*>(pArg)->position, reinterpret_cast<Vector3&>(ptCenter));
    float fLimit = 75.0f;
    float fOff = fLimit - fStep;
    if (ArePointsWithinRange2D(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptCenter), fOff, fOff)) {
        if (pOut != 0)
            *reinterpret_cast<efd::Point3*>(pOut) = ptCenter;
        return 0;
    }
    // MS2: clockwise from the upper left; the sides use the far limit on their long axis
    fOff = fLimit - fHalf;
    float fSize = fHalf;
    float fFar = fLimit - fStep;
    ptProbe.z = ptCenter.z;
    ptProbe.x = ptCenter.x - fOff;
    ptProbe.y = ptCenter.y + fOff;
    if (ArePointsWithinRange2D(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptProbe), fSize, fSize)) {
        if (pOut != 0)
            *reinterpret_cast<efd::Point3*>(pOut) = ptProbe;
        return 1;
    }
    ptProbe.x = ptCenter.x;
    ptProbe.y = ptCenter.y + fOff;
    if (ArePointsWithinRange2D(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptProbe), fFar, fSize)) {
        if (pOut != 0)
            *reinterpret_cast<efd::Point3*>(pOut) = ptProbe;
        return 2;
    }
    ptProbe.x = ptCenter.x + fOff;
    ptProbe.y = ptCenter.y + fOff;
    if (ArePointsWithinRange2D(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptProbe), fSize, fSize)) {
        if (pOut != 0)
            *reinterpret_cast<efd::Point3*>(pOut) = ptProbe;
        return 3;
    }
    ptProbe.x = ptCenter.x + fOff;
    ptProbe.y = ptCenter.y;
    if (ArePointsWithinRange2D(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptProbe), fSize, fFar)) {
        if (pOut != 0)
            *reinterpret_cast<efd::Point3*>(pOut) = ptProbe;
        return 4;
    }
    ptProbe.x = ptCenter.x + fOff;
    ptProbe.y = ptCenter.y - fOff;
    if (ArePointsWithinRange2D(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptProbe), fSize, fSize)) {
        if (pOut != 0)
            *reinterpret_cast<efd::Point3*>(pOut) = ptProbe;
        return 5;
    }
    ptProbe.x = ptCenter.x;
    ptProbe.y = ptCenter.y - fOff;
    if (ArePointsWithinRange2D(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptProbe), fFar, fSize)) {
        if (pOut != 0)
            *reinterpret_cast<efd::Point3*>(pOut) = ptProbe;
        return 6;
    }
    ptProbe.x = ptCenter.x - fOff;
    ptProbe.y = ptCenter.y - fOff;
    if (ArePointsWithinRange2D(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptProbe), fSize, fSize)) {
        if (pOut != 0)
            *reinterpret_cast<efd::Point3*>(pOut) = ptProbe;
        return 7;
    }
    ptProbe.x = ptCenter.x - fOff;
    ptProbe.y = ptCenter.y;
    if (ArePointsWithinRange2D(reinterpret_cast<const Unk_CMISPt2*>(&pt), reinterpret_cast<const Unk_CMISPt2*>(&ptProbe), fSize, fFar)) {
        if (pOut != 0)
            *reinterpret_cast<efd::Point3*>(pOut) = ptProbe;
        return 8;
    }
    return 9;
}

int FUN_14053f9c0(int nItemId);
int FUN_1408b5820(int nItemId);
int FUN_1408b5f70(int nItemId);
// @0x1410d27c0
int CubeMapInformationService::FUN_1410d27c0(__int64 nOwner, int nMode, int* pCount, int* pLimit)
{
    *pLimit = 0;
    *pCount = 0;
    if (reinterpret_cast<Unk_Wrap<2>*>(&f218)->IsNull())
        return 0;
    if (DAT_143ae0fb4 != 0)
        return 1;
    for (CMISEMap_int_set_int::iterator it = reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->begin(); (it != reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()); FUN_141129bb0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<262>*>(&it)))) {
        int nGroup = *FUN_141128660(reinterpret_cast<Unk_CMISIter<262>*>(&it));
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (spOwner == 0)
            continue;
        if (spOwner->ownerID != nOwner)
            continue;
        if (f218->groups.find(nGroup) == f218->groups.end())
            continue;
        const Unk_UGCGroup& group = f218->groups[nGroup];
        int nHeight = 0;
        if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130() != 0)
            nHeight = f2fc;
        else
            nHeight = group.heightLimit;
        if (nMode == 0)
            *pLimit = group.buildingCount;
        else if (nMode == 1)
            *pLimit = group.maidCount;
        else if (nMode == 2)
            *pLimit = group.triggerCount;
        else if (nMode == 4)
            *pLimit = group.installNpcCount;
        std::set<std::pair<int, int> > seen;
        Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nGroup)));
        for (CMISESet_int::iterator itCell = reinterpret_cast<CMISESet_int*>(pList)->begin(); (itCell != reinterpret_cast<CMISESet_int*>(pList)->end()); ++itCell) {
            int nKey = *((int*)(&*itCell));
            Unk_Int3 cell = FUN_1408a0400(nKey);
            if (seen.find(std::make_pair(cell.x, cell.y)) != seen.end())
                continue;
            seen.insert(std::make_pair(cell.x, cell.y));
            for (int h = 1; h <= nHeight; ++h) {
                Unk_Int3 up = FUN_1408a0400(nKey);
                up.z = up.z + h;
                Cube* pCube = GetCubeAtCell(up);
                if (pCube != 0) {
                    if (nMode == 0) {
                        if (FUN_14053f9c0(pCube->FUN_1408b4f20()) != 0)
                            ++*pCount;
                    } else if (nMode == 1) {
                        if (FUN_1408b5620(pCube->FUN_1408b4f20()) != 0)
                            ++*pCount;
                    } else if (nMode == 2) {
                        if (FUN_1408b5820(pCube->FUN_1408b4f20()) != 0)
                            ++*pCount;
                    } else if (nMode == 4) {
                        if (FUN_1408b5f70(pCube->FUN_1408b4f20()) != 0)
                            ++*pCount;
                    }
                }
            }
        }
        break;
    }
    if (*pLimit > 0 && *pLimit > *pCount)
        return 1;
    return 0;
}

// ---- w142 batch 5 ----
struct Unk_CMISXformVec;                                                    // vector<NiTransform>
void FUN_14115a9c0(Unk_CMISXformVec* pVec, const NiTransform* pXform);     // push_back
struct Unk_CMISMarkRec                                                      // Timer (0x38) + list of the mark entities (0x18); node value of f288
{
    Unk_CMISMarkRec();      // 0x141122f30
    ~Unk_CMISMarkRec();     // 0x141125e70: not trivial, so erase/clear of f288 destroy the node value (??_G pair 0x14112d0a0)
    union { char m_b[0x50]; __int64 m_q[10]; };   // m_q: 8-aligned like the Timer/vector it stands in for (pair value at +8, sizeof(pair) 0x58) and not a /GS char buffer
};
void FUN_141126920(Unk_CMISMarkRec* pDst, Unk_CMISMarkRec* pSrc);           // assign
void FUN_14115a930(void* pList, egf::EntityPtr* pEnt);                      // push_back
Unk_CMISIter<275>* FUN_141151850(Unk_CMISTree<275>*, Unk_CMISIter<275>*);                           // end
Unk_CMISIter<275>* FUN_141156e80(Unk_CMISTree<275>*, Unk_CMISIter<275>*, const int*);               // find
bool FUN_141126bd0(Unk_CMISIter<275>*, Unk_CMISIter<275>*);                                         // operator==
char* FUN_141127a90(void*, void*);   // C3: was FUN_141127a90
// @0x1410cbb40
void CubeMapInformationService::FUN_1410cbb40(Unk_CMISXformVec* pOut, int nMode, int nGroup, Vector3 ptPlayer, Unk_Int3 cell, bool bRot, int nMs)
{
    Vector3 ptCell;
    FUN_1408a15b0(cell, ptCell);
    Vector3 ptDir = ptPlayer.FUN_140965c40(ptCell);
    ptDir.FUN_140968990();
    ptCell = ptCell.FUN_14097fd50(ptDir.FUN_14097fc90(75.0f));
    ptCell.z = ptCell.z + 150.0f;
    Vector3 ptRot = DAT_143b01a60;
    if (bRot)
        ptRot = Vector3(0.0f, 0.0f, 90.0f);
    if (nMode == 0) {
        int nHeight = 0;
        if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130()) {
            nHeight = f2fc;
        } else if (f218 != 0) {
            if (f218->groups.find(nGroup) != f218->groups.end())
                nHeight = f218->groups[nGroup].heightLimit;
        }
        for (int i = 0; i < nHeight; ++i) {
            Vector3 ptLevel = ptCell;
            ptLevel.z = ptCell.z + (float)i * 150.0f;
            ptLevel.z = ptLevel.z + 75.0f;
            NiTransform xform;
            xform.MakeIdentity();
            Vector3 ptT(reinterpret_cast<const efd::Point3&>(ptLevel));
            xform.m_Translate = reinterpret_cast<const NiPoint3&>(ptT);
            xform.m_Rotate.FromEulerAnglesXYZ((-ptRot.x * 3.1415927f) / 180.0f, (-ptRot.y * 3.1415927f) / 180.0f, (-ptRot.z * 3.1415927f) / 180.0f);
            FUN_14115a9c0(pOut, &xform);
        }
    } else if (nMode == 1) {
        egf::EntityPtr spMark = static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411ce7c0(efd::utf8string("MS2PhysXProp"),
            efd::utf8string("urn:gamebryo-scenegraph:Eff_Own_Ground_Mark_01"), reinterpret_cast<const NiPoint3&>(ptCell), reinterpret_cast<const NiPoint3&>(ptRot), 1.0f, 1, 0);
        if ((reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->find(nGroup) == reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->end())) {
            Unk_CMISMarkRec rec;
            FUN_141126920(((struct Unk_CMISMarkRec*)FUN_141127a90((void*)(&f288), (void*)(&nGroup))), &rec);
        }
        Unk_CMISMarkRec* pRec = ((struct Unk_CMISMarkRec*)FUN_141127a90((void*)(&f288), (void*)(&nGroup)));
        FUN_14115a930(pRec->m_b + 0x38, &spMark);
        if (nMs == 0)
            reinterpret_cast<Timer*>(pRec->m_b)->FUN_1408687c0();
        else
            reinterpret_cast<Timer*>(pRec->m_b)->FUN_140868750(nMs);
    }
}

// @0x1410c3670
void CubeMapInformationService::FUN_1410c3670()
{
    Unk_CubePoint cellMin;
    Unk_CubePoint cellMax;
    ComputeCellBounds(&cellMin, &cellMax);
    p300 = cellMin;
    p30c = cellMax;
    p300.x = (p30c.x - f2f8) + 1;
    p300.y = (p30c.y - f2f8) + 1;
    for (CMISEMap_int_Cell::iterator it = reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->begin(); (it != reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->end()); FUN_141129a60((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<278>*>(&it)))) {
        int nKey = *FUN_141128540(reinterpret_cast<Unk_CMISIter<278>*>(&it));
        Unk_Int3 cell = FUN_1408a0400(nKey);
        MS2Ptr<Cube> spCube(GetCubeByKey(FUN_1408a03c0(cell)));
        if (spCube == 0)
            continue;
        bool bInstanced = false;
        ((const egf::EntityPtr*)(&spCube->entity))->operator->()->GetPropertyValue(0x23f9860e, bInstanced);
        if (cell.x >= p300.x && cell.x <= p30c.x && cell.y >= p300.y && cell.y <= p30c.y) {
            if (bInstanced) {
                Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
                if (spInst.FUN_14098d090() != 0)
                    spInst.FUN_14098d0e0()->FUN_1413d6e60(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*(), true);
            }
            bool bDone = false;
            ((const egf::EntityPtr*)(&spCube->entity))->operator->()->GetPropertyValue(0x7e5f4195, bDone);
            if (bDone) {
                unsigned short nEffect = 9;
                ((const egf::EntityPtr*)(&spCube->entity))->operator->()->GetPropertyValue<unsigned short>(0xada5c5d2, nEffect);
                ((class CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*(), nEffect, 0, 0);
                bool bClear = false;
                FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()), 0x7e5f4195, *(bool const*)(&bClear));
            }
            bool bOn = true;
            FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()), 0xa0b6b179, *(bool const*)(&bOn));
        } else {
            if (bInstanced) {
                Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
                if (spInst.FUN_14098d090() != 0)
                    spInst.FUN_14098d0e0()->FUN_1413d6e60(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*(), false);
            }
            bool bDone = false;
            ((const egf::EntityPtr*)(&spCube->entity))->operator->()->GetPropertyValue(0x7e5f4195, bDone);
            if (!bDone) {
                ((class CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*(), 5, 0, 0);
                bool bSet = true;
                FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()), 0x7e5f4195, *(bool const*)(&bSet));
            }
            bool bOff = false;
            FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()), 0xa0b6b179, *(bool const*)(&bOff));
        }
    }
    GenerateAreaPhysX(1);
    GenerateAreaPhysX(0);
    GenerateAreaPhysX(2);
    if (FUN_1410c3180() == DAT_143ab2820 || FUN_140930c90(FUN_1410c3180()) || FUN_140930d20(FUN_1410c3180())) {
        Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pRoster != 0 && ((PC*)pRoster)->IsInCubeMode() != 0 && ((class Unk_PCCubeCraft*)(void*)(((MyPC*)pRoster)->GetActiveCubeCraft()))->GetMode() != 2) {
            FUN_1410cd440();
            FUN_1410cc160(0);
            FUN_1410cc160(1);
        }
    }
    ((class WorldService*)(class Unk_CMISWorld*)(reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())))->FUN_141bc8e00();
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
class Unk_InventoryListener* FUN_140a6a840();   // C3: was FUN_140a6a840
struct Unk_CMISObjRef;                                                      // map value: intrusive pointer to a world object
class Unk_CMISObjMap;
char* FUN_14112e2b0(void*, char*);   // C3: was FUN_14112e2b0
unsigned __int64 FUN_14112e170(void*, unsigned __int64*);   // C3: was FUN_14112e170
Unk_CMISPcObj* FUN_140aac420(Unk_CMISObjRef*);
Unk_CMISIter<256>* FUN_14114e860(Unk_CMISTree<256>*, Unk_CMISIter<256>*);   // begin
Unk_CMISIter<256>* FUN_1411524b0(Unk_CMISTree<256>*, Unk_CMISIter<256>*);   // end
bool FUN_140a16b10(Unk_CMISIter<256>*, Unk_CMISIter<256>*);                 // operator!=
Unk_CMISEntityRef* FUN_140a16d80(Unk_CMISIter<256>*);                       // operator*
void FUN_140a17010(Unk_CMISIter<256>*);                                     // operator++
Unk_CMISIter<273>* FUN_141157660(Unk_CMISTree<273>*, Unk_CMISIter<273>*, const int*);   // find
char* FUN_141127d10(void*, void*);   // C3: was FUN_141127d10
void* FUN_141906490(void* pMem, Unk_Int3 cell, CStringW strName, int nValue);   // UICubeUGCHead::UICubeUGCHead
Unk_CMISIter<260>* FUN_14111c6f0(Unk_CMISTree<260>*, Unk_CMISIter<260>* pOut, Unk_CMISIter<260> it);   // erase

// @0x1410ce8a0
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
    ((class CCubeMotionManager*)(class CCubeMotionManager*)(GetCubeMotionManager()))->Update();
    FUN_1410c9db0();
    for (CMISESet_EntityID::iterator itEnt = reinterpret_cast<CMISESet_EntityID*>(&f30)->begin(); (itEnt != reinterpret_cast<CMISESet_EntityID*>(&f30)->end()); ++itEnt) {
        Unk_CMISEntityRef id = *FUN_140a16d80(reinterpret_cast<Unk_CMISIter<256>*>(&itEnt));
        TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf540(*reinterpret_cast<egf::EntityID*>(&id));
    }
    ((std::_Tree<std::_Tset_traits<egf::EntityID, std::less<egf::EntityID>, efd::CustomAllocator<egf::EntityID>, 0>>*)(void*)(&f30))->clear();
    if (((void*)((MS2Ptr<CFieldDataCli>*)(void*)(&f208))->get()) != 0) {
        if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375100() == 0 && (f218 != 0 ? true : false) && f218->floors.size() > 0 && t168.FUN_140868c00() != 0) {
            Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
            if (pRoster != 0) {
                int nMyFloor = FUN_1410c88b0(reinterpret_cast<PCBase*>(pRoster));
                Unk_CMISObjMap* pObjects = ((class Unk_CMISObjMap*)((class WorldService*)(class Unk_CMISWorld*)(reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())))->FUN_141bd36b0());
                for (void* pos = ((void*)((ATL::CRBTree<unsigned int, Unk_WsV118, ATL::CElementTraits<unsigned int>, ATL::CElementTraits<Unk_WsV118>>*)(class Unk_CMISObjMap*)(pObjects))->GetHeadPosition()); pos != 0; FUN_14112e170((void*)(pObjects), (unsigned __int64*)(&pos))) {
                    Unk_CMISPcObj* pPc = FUN_140aac420(((struct Unk_CMISObjRef*)FUN_14112e2b0((void*)(pObjects), (char*)(pos))));
                    if (pPc != 0 && ((PCBase*)pPc)->IsDead() == 0) {
                        int nFloor = FUN_1410c88b0(reinterpret_cast<PCBase*>(pPc));
                        if (nFloor > nMyFloor)
                            pPc->SetState(0);
                        else
                            pPc->SetState(1);
                    }
                }
            }
            t168.FUN_140868750(1000);
        }
    }
    if (t3e0.FUN_140868c00() != 0) {
        ((class Unk_CMISSystem*)FUN_140a6a840())->Flush();
        t3e0.FUN_1408687f0();
    }
    if (FUN_1410b7d50() && reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f88)->size() > 0) {
        CMISEMap_int_MS2Ptr_Cube::iterator itCube = reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f88)->begin();
        if ((itCube != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f88)->end())) {
            int nKey = FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&itCube))->first;
            if ((reinterpret_cast<CMISMap_int_MS2Ptr_UICubeUGCHead*>(&f228)->find(nKey) != reinterpret_cast<CMISMap_int_MS2Ptr_UICubeUGCHead*>(&f228)->end())) {
                ((class UICubeUGCHead*)(class Unk_CMISPolyObj*)(FUN_1411284c0(((struct Unk_CMISHousePtr*)FUN_141127d10((void*)(&f228), (void*)(&nKey))))))->FUN_141906680();
                ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<UICubeUGCHead>, std::less<int>, std::allocator<std::pair<int const, MS2Ptr<UICubeUGCHead>>>, 0>>*)(void*)(&f228))->erase(*(int const*)(&nKey));
            }
            MS2Ptr<Cube> spCube(FUN_1411285e0(reinterpret_cast<Unk_CMISIter<260>*>(&itCube))->second);
            ((void*)&((MS2Ptr<UICubeUGCHead>*)(struct Unk_CMISHousePtr*)(((struct Unk_CMISHousePtr*)FUN_141127d10((void*)(&f228), (void*)(&nKey)))))->AssignRaw(new UICubeUGCHead(*(const Unk_UgcCell*)&static_cast<const Unk_Int3&>(FUN_1408a0400(nKey)), TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, ((class Cube*)(class Cube*)(spCube.operator->()))->FUN_1408b4f20()), spCube->fieldB4)));
            ((class UICubeUGCHead*)(class Unk_CMISPolyObj*)(FUN_1411284c0(((struct Unk_CMISHousePtr*)FUN_141127d10((void*)(&f228), (void*)(&nKey))))))->FUN_141906610(nKey);
            reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f88)->erase(itCube);
        }
    }
    return efd::AsyncResult_Pending;
}

// ---- w142 batch 7 ----
struct Unk_CMISEntSetIter { void* m_p; };
typedef std::vector<egf::EntityID, efd::CustomAllocator<egf::EntityID>> CMISVec_EntityID;
typedef std::vector<efd::SmartPointer<egf::Entity>, efd::CustomAllocator<efd::SmartPointer<egf::Entity>>> CMISVec_EntityPtr;
struct Unk_ListNode;
bool FUN_141127980(Unk_CMISEntSetIter*, Unk_CMISEntSetIter*);               // operator!=
const Unk_CMISEntityRef* FUN_141128e60(Unk_CMISEntSetIter*);                // operator*
void* FUN_14112ab40(Unk_ListNode**);                                        // operator++
bool FUN_140de8e30(const Unk_CMISStr& str, const char* psz);            // == psz
float* FUN_1408b0470(void* pFloors, const int* pKey);                       // the start height of a floor (operator[])
// @0x1410c9710
void CubeMapInformationService::FUN_1410c9710()
{
    if (reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())->FUN_141bcfbd0() == 0)
        return;
    if (reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&f78)->size() > 0)
        return;
    if ((CUGCMapData*)f218 != 0 && (CFieldDataCli*)*((MS2Ptr<CFieldDataCli>*)(void*)(&f208)) != 0 && (*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375100() == 0) {
    if (Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0())) {
    int nFloor = FUN_1410c88b0(reinterpret_cast<PCBase*>(pRoster));
    if (nFloor == 0)
        return;
    if (f1e0 != nFloor) {
    if (f1e0 != 0 && f1e0 > nFloor) {
        CMISVec_EntityID* pV = reinterpret_cast<CMISVec_EntityID*>(FUN_141127e50((void*)(&f1e8), (void*)(&f1e0)));
        CMISVec_EntityID& rV = *pV;
        CMISVec_EntityID::const_iterator itEnd = rV.end();
        for (CMISVec_EntityID::const_iterator it = rV.begin(); it != itEnd; ++it) {
            egf::EntityID id = *it;
            egf::Entity* pEnt = static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411cf440(id);
            if (pEnt != 0) {
            efd::utf8string strKind("None");
            pEnt->GetPropertyValue<efd::utf8string>(0x15014205, strKind);
            Vector3 ptEnt = DAT_143b01a60;
            pEnt->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(ptEnt));
            float* pfStart = FUN_1408b0470(&f218->floors, &f1e0);
            if (strKind == "Stair" && ptEnt.z == *pfStart) {
                pEnt->SetPropertyValue<bool>(0xa0b6b179, false);
            } else {
                GetCubeMotionManager()->RemoveFade(pEnt->GetEntityID());
                GetCubeMotionManager()->AddFade(pEnt->GetEntityID(), 1.0f, 0.0f, 200, false);
            }
            }
        }
    }
    if (nFloor > f1e0) {
        CMISVec_EntityID* pV = reinterpret_cast<CMISVec_EntityID*>(FUN_141127e50((void*)(&f1e8), (void*)(&nFloor)));
        CMISVec_EntityID& rV = *pV;
        CMISVec_EntityID::const_iterator itEnd = rV.end();
        for (CMISVec_EntityID::const_iterator it = rV.begin(); it != itEnd; ++it) {
            egf::EntityID id = *it;
            egf::Entity* pEnt = static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411cf440(id);
            if (pEnt != 0) {
            efd::utf8string strKind("None");
            pEnt->GetPropertyValue<efd::utf8string>(0x15014205, strKind);
            Vector3 ptEnt = DAT_143b01a60;
            pEnt->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(ptEnt));
            float* pfStart = FUN_1408b0470(&f218->floors, &nFloor);
            if (strKind == "Stair" && ptEnt.z == *pfStart) {
                pEnt->SetPropertyValue<bool>(0xa0b6b179, true);
            } else {
                pEnt->SetPropertyValue<bool>(0xa0b6b179, true);
                GetCubeMotionManager()->RemoveFade(pEnt->GetEntityID());
                GetCubeMotionManager()->AddFade(pEnt->GetEntityID(), 0.0f, 1.0f, 200, true);
            }
            }
        }
    }
    f1e0 = nFloor;
    }
    }
    }
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
Unk_CMISDemolishUI* FUN_1410dbf80(unsigned nId);                                            // find the demolish dialog
class UIHouseDemolishDialog   // C3: member view for the former free stand-ins
{
public:
    void Hide();
    void Show();
};
Unk_CMISIter<275>* FUN_14114da60(Unk_CMISTree<275>*, Unk_CMISIter<275>*);                   // begin
bool FUN_141127300(Unk_CMISIter<275>*, Unk_CMISIter<275>*);                                 // operator!=
Unk_CMISMarkEntry* FUN_141128500(Unk_CMISIter<275>*);                                       // operator*
void FUN_141129a20(Unk_CMISIter<275>*);                                                     // operator++
int FUN_14025a620(class Unk_ConstVal*);                                                   // Constants::Value<int> read
float FUN_140a38cd0(float f);                                                             // fabs
// @0x1410ca170
void CubeMapInformationService::FUN_1410ca170()
{
    Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pRoster == 0)
        return;
    if (((PC*)pRoster)->IsCubeMode1() != 0)
        return;
    ((MyPC*)pRoster)->FUN_14152a2b0(0);
    CMISMap_int_Unk_Int3 mapOuter;
    FUN_1410bb170(reinterpret_cast<Unk_CMISPawn*>(pRoster), FUN_14025a620(reinterpret_cast<Unk_ConstVal*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_limits1190)), FUN_14025a620(reinterpret_cast<Unk_ConstVal*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_limits1190)), 2, reinterpret_cast<Unk_CMISNearMap*>(&mapOuter));
    CMISMap_int_Unk_Int3 mapInner;
    FUN_1410bb170(reinterpret_cast<Unk_CMISPawn*>(pRoster), FUN_14025a620(reinterpret_cast<Unk_ConstVal*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_limits1138)), FUN_14025a620(reinterpret_cast<Unk_ConstVal*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_limits1138)), 2, reinterpret_cast<Unk_CMISNearMap*>(&mapInner));
    int bAny = 0;
    for (CMISMap_int_Unk_Int3::iterator it = mapInner.begin(); it != mapInner.end(); ++it) {
        int nGroup = *FUN_141128520(reinterpret_cast<Unk_CMISNearIter*>(&it));
        if (mapOuter.find(nGroup) != mapOuter.end())
            mapOuter.erase(*(int const*)(&nGroup));
        if (FUN_1410ca900(nGroup) != 0) {
            bAny = 1;
            ((MyPC*)reinterpret_cast<Unk_CMISPawn*>(pRoster))->FUN_14152a2b0(1);
        }
    }
    if (Unk_CMISDemolishUI* pUI = FUN_1410dbf80(0x4ea1)) {
        if (FUN_1410c3180() == 0 && bAny)
            ((class UIHouseDemolishDialog*)(struct Unk_CMISDemolishUI*)(pUI))->Show();
        else
            ((class UIHouseDemolishDialog*)(struct Unk_CMISDemolishUI*)(pUI))->Hide();
    }
    for (CMISMap_int_Unk_Int3::iterator it = mapOuter.begin(); it != mapOuter.end(); ++it) {
        int nGroup = *FUN_141128520(reinterpret_cast<Unk_CMISNearIter*>(&it));
        if (reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->find(nGroup) != reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->end())
            continue;
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (spOwner == 0)
            continue;
        if (spOwner->ownerID == ((PC*)pRoster)->FUN_141656ad0())
            FUN_1410ccc00(nGroup, 1, 0);
    }
    for (CMISEMap_int_MarkRec::iterator itMark = reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->begin(); itMark != reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->end(); ++itMark) {
        int nGroup = FUN_141128500(reinterpret_cast<Unk_CMISIter<275>*>(&itMark))->m_key;
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (spOwner == 0)
            continue;
        if (spOwner->ownerID != ((PC*)pRoster)->FUN_141656ad0()) {
            Unk_CMISMarkRec* pRec = &FUN_141128500(reinterpret_cast<Unk_CMISIter<275>*>(&itMark))->m_rec;
            if (reinterpret_cast<Timer*>(pRec->m_b)->FUN_140868c00() != 0)
                FUN_1410ccc00(nGroup, 0, 0);
            continue;
        }
        if (mapInner.find(nGroup) != mapInner.end()) {
            FUN_1410ccc00(nGroup, 0, 0);
            continue;
        }
        Cube* pNear = FUN_1410badf0(nGroup, reinterpret_cast<Unk_CMISPawn*>(pRoster));
        if (pNear == 0)
            continue;
        Vector3 ptA;
        GetCellInFrontOfActor(reinterpret_cast<PCBase*>(reinterpret_cast<Unk_CMISPawn*>(pRoster)), -150.0f, &ptA, 0);
        Vector3 ptB;
        GetCellPosition(ptA, &ptB);
        Unk_Int3 cell = FUN_1408a1430(ptB);
        if (FUN_140a38cd0((float)(pNear->position.x - cell.x)) > (float)*reinterpret_cast<Common::Constants::Value<int>*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_limits1190)->Get()
            || FUN_140a38cd0((float)(pNear->position.y - cell.y)) > (float)*reinterpret_cast<Common::Constants::Value<int>*>(&((struct Unk_CMISRules*)FUN_1401d3200())->m_limits1190)->Get()) {
            FUN_1410ccc00(nGroup, 0, 0);
            break;
        }
    }
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
Unk_CMISIter<285>* FUN_141156da0(Unk_CMISTree<285>*, Unk_CMISIter<285>*, const int*);       // find
int* FUN_141127a50(Unk_CMISTree<285>*, const int*);                                         // operator[]: the effect of a cube
class Unk_AvModeSvc* FUN_1409f7c90();
struct Unk_CMISGlue { int Global(); };                                                      // 0x14112f0b0: the client is in a map that needs no instancing refresh
// @0x1410c06b0
bool CubeMapInformationService::FUN_1410c06b0(MS2Ptr<Cube> spCube)
{
    const Unk_Int3& rPos = spCube->position;
    Unk_Int3 cell = rPos;
    int FUN_1408a03c0(const Unk_Int3& pt);
    int nKey = FUN_1408a03c0(cell);
    if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->find(nKey) != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end()))
        return false;
    *(MS2Ptr<Cube>*)(FUN_141127cd0(&f98, &nKey)) = spCube;
    *(MS2Ptr<Cube>*)(FUN_141128190(&fa8, ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID()))) = spCube;
    if (spCube->field48 != 0)
        *(MS2Ptr<Cube>*)(FUN_141127cd0(&fb8, &nKey)) = spCube;
    if (spCube->field70 != 0 && spCube->field6c != 0)
        ((class Unk_CubeHeightIndex*)(void*)(&f2a8))->FUN_1410b2510(rPos.x, rPos.y, rPos.z);
    if (spCube->fieldD8 != 0) {
        int nHouse = spCube->fieldD8;
        efd::Point3 ptDir;
        reinterpret_cast<egf::Entity*>(((const egf::EntityPtr*)(&spCube->entity))->operator->())->GetPropertyValue<efd::Point3>(0x68c7c29d, ptDir);
        int nDir = VectorToDirection(*(Vector3*)&ptDir);
        if ((reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->find(nHouse) == reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->end())) {
            Unk_CMISTree<287> empty;
            FUN_1411266a0(FUN_141127dd0(&fc8, &nHouse), &empty);
        }
        Unk_CMISTree<287>* pCubes = FUN_141127dd0(&fc8, &nHouse);
        if ((reinterpret_cast<CMISMap_int_MS2Ptr_Cube*>(pCubes)->find(nDir) == reinterpret_cast<CMISMap_int_MS2Ptr_Cube*>(pCubes)->end()))
            *(MS2Ptr<Cube>*)(FUN_141128350(pCubes, &nDir)) = spCube;
    }
    if (f218 != 0) {
        if (spCube->field48 != 0 && ((class Cube*)(class Cube*)(spCube.get()))->FUN_1408b4f20() != 0 && spCube->fieldB4 != 0) {
            int bMine = 0;
            if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130()) {
                if (DAT_143ab2820 == FUN_1410c3180())
                    bMine = 1;
            } else {
                Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), spCube->field50, spCube->field54);
                if ((spOwner != 0 ? true : false) && spOwner->ownerID == DAT_143ab2820)
                    bMine = 1;
            }
            if (bMine != 0 && FUN_14053fc10(((class Cube*)(class Cube*)(spCube.get()))->FUN_1408b4f20()) == 0xd) {
                Unk_EffectTarget request;
                request.m_strName = ((struct Unk_CMISConsts*)FUN_1401d31f0())->m_strHouseEffect;
                request.m_nKind = 0;
                *reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&reinterpret_cast<Unk_CMISEffReq&>(request).m_pSlot10) = (NiAVObject*)(NiObject::DynamicCast(&DAT_143afa4d8, (class NiObject const*)(FUN_141b6efc0(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*()))));
                request.m_b32 = true;
                bool bDrawn = false;
                FUN_14098c6e0((class Unk_CachedEntity*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()), 0x2a7fd9f4, *(bool const*)(&bDrawn));
                int nEffect = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(reinterpret_cast<Unk_EffectTarget&>(request));
                if (nEffect != 0) {
                    if ((reinterpret_cast<CMISEMap_int_u_int*>(&f338)->find(nKey) != reinterpret_cast<CMISEMap_int_u_int*>(&f338)->end()))
                    {
                        unsigned nOldEffect = *FUN_141127a50(&f338, &nKey);
                        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(nOldEffect);
                    }
                    *FUN_141127a50(&f338, &nKey) = nEffect;
                }
            }
        }
        if (((Unk_CMISGlue*)FUN_1409f7c90())->Global() != 0) {
            if (spCube->field48 != 0 && CFieldData::FUN_140374410(WorldService::GetInstance()->FUN_141bd3060())) {
                int nHasModel = 0;
                if (((void*)((MS2Ptr<CubeItemInfo>*)(void*)(&spCube->item))->get()) != 0)
                    nHasModel = ((class CubeItemInfo*)(class CubeItemInfo*)((*(MS2Ptr<CubeItemInfo>*)(void*)(&spCube->item)).operator->()))->FUN_1408b3860();
                if (nHasModel == 0 && spCube->fieldB4 == 0) {
                    Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
                    if ((spInst.FUN_14098d090() != 0 ? true : false)) {
                        if (spInst.FUN_14098d0e0()->FUN_1413d6890(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*()) == 0) {
                            Unk_MeshInstancingConfig kConfig(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*(), 0, 0);
                            kConfig.unknown48.z = -spCube->field50;
                            MeshInstancing* pFound = spInst.FUN_14098d0e0()->FindInstancingByConfig(kConfig);
                            EntityInstancing* pInst = dynamic_cast<EntityInstancing*>(pFound);
                            if (pInst == 0)
                                pInst = static_cast<EntityInstancing*>(spInst.FUN_14098d0e0()->FUN_1413d4b40(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*(), -spCube->field50, 10));
                            if (pInst != 0)
                                spInst.FUN_14098d0e0()->FUN_1413d4fe0(pInst, ((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*());
                        }
                    }
                }
            }
        } else if (spCube->field48 != 0 && spCube->fieldA8 == 8) {
            Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
            if ((spInst.FUN_14098d090() != 0 ? true : false)) {
                if (spInst.FUN_14098d0e0()->FUN_1413d6890(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*()) == 0) {
                    Unk_MeshInstancingConfig kConfig(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*(), 0, 0);
                    kConfig.unknown48.z = -spCube->field50;
                    MeshInstancing* pFound = spInst.FUN_14098d0e0()->FindInstancingByConfig(kConfig);
                    EntityInstancing* pInst = dynamic_cast<EntityInstancing*>(pFound);
                    if (pInst == 0) {
                        int nW, nH, nD;
                        if (FUN_1410c81c0(spCube->field50, &nW, &nH, &nD) != 0)
                            pInst = static_cast<EntityInstancing*>(spInst.FUN_14098d0e0()->FUN_1413d4b40(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*(), -spCube->field50, nW * nH * nD));
                    }
                    if (pInst != 0)
                        spInst.FUN_14098d0e0()->FUN_1413d4fe0(pInst, ((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*());
                }
            }
        }
    }
    return true;
}

// ---- w142 batch 10 ----
void* FUN_141129cb0(struct Unk_TreeIter*);   // C3: was FUN_141129cb0
Unk_CMISInsRes* FUN_14111d3f0(Unk_CMISTree<256>*, Unk_CMISInsRes*, const Unk_CMISEntityRef*);   // insert
bool FUN_141127580(Unk_CMISIter<261>*, Unk_CMISIter<261>*);                                 // operator!=
struct Unk_CMISColEntry { int m_key; int m_pad; MS2Ptr<Cube> m_value; };                    // node value of a house's cubes
Unk_CMISIter<287>* FUN_140885bd0(Unk_CMISTree<287>*, Unk_CMISIter<287>*);                   // begin
bool FUN_1408852d0(Unk_CMISIter<287>*, Unk_CMISIter<287>*);                                 // operator!=
Unk_CMISColEntry* FUN_140885360(Unk_CMISIter<287>*);                                        // operator*
void FUN_1408853e0(Unk_CMISIter<287>*);                                                     // operator++
class Unk_CMISGameObj { public: virtual void vfunc_0(); virtual void IncRefCount() const; virtual void DecRefCount() const; };   // GameObject's efd::IBase slots
// @0x1410c1910
bool CubeMapInformationService::FUN_1410c1910(const Unk_Int3& pt, int bDefer)
{
    int nKey = FUN_1408a03c0(pt);
    if ((reinterpret_cast<CMISMap_int_MS2Ptr_UICubeUGCHead*>(&f228)->find(nKey) != reinterpret_cast<CMISMap_int_MS2Ptr_UICubeUGCHead*>(&f228)->end())) {
        ((class UICubeUGCHead*)(class Unk_CMISPolyObj*)(FUN_1411284c0(((struct Unk_CMISHousePtr*)FUN_141127d10((void*)(&f228), (void*)(&nKey))))))->FUN_141906680();
        ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<UICubeUGCHead>, std::less<int>, std::allocator<std::pair<int const, MS2Ptr<UICubeUGCHead>>>, 0>>*)(void*)(&f228))->erase(*(int const*)(&nKey));
    }
    if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f88)->find(nKey) != reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f88)->end()))
        ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<Cube>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<Cube>>>, 0>>*)(void*)(&f88))->erase(*(int const*)(&nKey));
    if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->find(nKey) == reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&f98)->end())) {
        for (CMISEMap_EntityID_MS2Ptr_Cube::iterator it = reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&f78)->begin(); (it != reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&f78)->end()); FUN_141129cb0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<259>*>(&it)))) {
            MS2Ptr<Cube> spIter(FUN_141128780(reinterpret_cast<Unk_CMISIter<259>*>(&it))->second);
            int nIterKey = FUN_1408a03c0(spIter->position);
            if (nIterKey == nKey) {
                Unk_CMISInsRes itIns;
                FUN_14111d3f0(&f68, &itIns, &FUN_141128780(reinterpret_cast<Unk_CMISIter<259>*>(&it))->key);
                return false;
            }
        }
        ((class Unk_CMISLog*)GetLogString())->FUN_1410db4f0(1, 0x13, L"[ERROR] No cube on that position = {0}, {1}, {2}", pt.x, pt.y, pt.z);
        return false;
    }
    MS2Ptr<Cube> spCube(*FUN_141127cd0(&f98, &nKey));
    if (spCube->fieldD8 != 0) {
        if ((reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->find(spCube->fieldD8) != reinterpret_cast<CMISEMap_int_Map_int_MS2Ptr_Cube*>(&fc8)->end())) {
            Unk_CMISTree<287>* pCubes = FUN_141127dd0(&fc8, &spCube->fieldD8);
            for (CMISMap_int_MS2Ptr_Cube::iterator itCube = reinterpret_cast<CMISMap_int_MS2Ptr_Cube*>(pCubes)->begin(); (reinterpret_cast<std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<long const, MS2Ptr<Cube>>>>>&>(itCube) != reinterpret_cast<const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<long const, MS2Ptr<Cube>>>>>&>(static_cast<const CMISMap_int_MS2Ptr_Cube::iterator&>(reinterpret_cast<CMISMap_int_MS2Ptr_Cube*>(pCubes)->end()))); ++itCube) {
                if (FUN_140885360(reinterpret_cast<Unk_CMISIter<287>*>(&itCube))->m_value == (Cube*)spCube)
                    ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<Cube>, std::less<int>, std::allocator<std::pair<int const, MS2Ptr<Cube>>>, 0>>*)(void*)(pCubes))->erase(*(int const*)(&FUN_140885360(reinterpret_cast<Unk_CMISIter<287>*>(&itCube))->m_key));
            }
        }
    }
    if ((reinterpret_cast<CMISEMap_int_u_int*>(&f338)->find(nKey) != reinterpret_cast<CMISEMap_int_u_int*>(&f338)->end())) {
        unsigned nEffectId = *FUN_141127a50(&f338, &nKey);
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(nEffectId);
        ((std::_Tree<std::_Tmap_traits<int, unsigned int, std::less<int>, efd::CustomAllocator<std::pair<int const, unsigned int>>, 0>>*)(void*)(&f338))->erase(*(int const*)(&nKey));
    }
    Unk_EffectTarget request;
    request.m_strName = ((struct Unk_CMISConsts*)FUN_1401d31f0())->m_strRemoveEffect;
    request.m_nKind = 7;
    *reinterpret_cast<efd::SmartPointer<NiAVObject>*>(&reinterpret_cast<Unk_CMISEffReq&>(request).m_pSlot10) = (NiAVObject*)(NiObject::DynamicCast(&DAT_143afa4d8, (class NiObject const*)(FUN_141b6efc0(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*()))));
    TSingleton<CEffectService>::GetInstance()->FUN_1411a4a00(request);
    ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<Cube>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<Cube>>>, 0>>*)(void*)(&f98))->erase(*(int const*)(&nKey));
    ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<Cube>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<Cube>>>, 0>>*)(void*)(&fb8))->erase(*(int const*)(&nKey));
    CMISEMap_EntityID_MS2Ptr_Cube::iterator itById = reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&fa8)->find(*reinterpret_cast<const egf::EntityID*>(((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID())));
    if ((itById != reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&fa8)->end())) {
        reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&fa8)->erase(itById);
    }
    if (FUN_1407071e0(spCube->fieldB4) != 0) {
        CString strKey;
        strKey.Format("%d_%d", spCube->field44, FUN_1408a03c0(spCube->position));
        ((class Unk_CMISMagicCube*)FUN_1409670b0())->RemoveCube(strKey);
        if (FUN_1407072e0(spCube->fieldB4) != 0) {
            if ((reinterpret_cast<CMISEMap_int_EntityID*>(&f108)->find(nKey) != reinterpret_cast<CMISEMap_int_EntityID*>(&f108)->end())) {
                // held across the remove and the erase, as the exe's SmartPointer<GameObject> (0x140a000f0 / 0x140964870)
                efd::SmartPointer<Unk_CMISGameObj> spMagic = (Unk_CMISGameObj*)reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())->FUN_141bd0fa0(Unk_CMISEntityRef(*((struct Unk_CMISEntityRef*)FUN_141127ed0((void*)(&f108), (void*)(&nKey)))));
                if (spMagic)
                    WorldService::GetInstance()->FUN_141bbb7f0(reinterpret_cast<GameObject*>(static_cast<Unk_CMISGameObj*>(spMagic)), 0);
                ((std::_Tree<std::_Tmap_traits<int, egf::EntityID, std::less<int>, efd::CustomAllocator<std::pair<int const, egf::EntityID>>, 0>>*)(void*)(&f108))->erase(*(int const*)(&nKey));
            }
        }
    }
    if (bDefer != 0 && (reinterpret_cast<CMISEMap_int_EntityID*>(&f2c8)->find(nKey) == reinterpret_cast<CMISEMap_int_EntityID*>(&f2c8)->end()))
        *(egf::EntityID*)(((struct Unk_CMISEntityRef*)FUN_141127ed0((void*)(&f2c8), (void*)(&nKey)))) = *(const egf::EntityID*)&(*((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID()));
    else
        RemovePhysXActor(Unk_CMISEntityRef(*((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID())));
    static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411cf570(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*());
    ((class Unk_CubeHeightIndex*)(void*)(&f2a8))->FUN_1410b25a0(pt.x, pt.y, pt.z);
    FUN_1410ce020(spCube);
    if (((Unk_CMISGlue*)FUN_1409f7c90())->Global() != 0) {
        if (spCube->field48 != 0) {
            Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
            if ((spInst.FUN_14098d090() != 0 ? true : false) && spInst.FUN_14098d0e0()->FUN_1413d6890(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*()) == 0)
                spInst.FUN_14098d0e0()->FUN_1413d6f40(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*());
        }
    } else if (spCube->field48 != 0 || spCube->fieldA8 == 8) {
        Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
        if ((spInst.FUN_14098d090() != 0 ? true : false) && spInst.FUN_14098d0e0()->FUN_1413d6890(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*()) == 0)
            spInst.FUN_14098d0e0()->FUN_1413d6f40(((const egf::EntityPtr*)(&spCube->entity))->operator egf::Entity*());
    }
    return true;
}

// ---- w142 batch 11 ----
#include "ms2/placeholder/tixmldocument.h"
#include <egf/Entity.h>  // C3: egf::Entity::GetPropertyValue<bool>
struct Unk_CMISXmlNode { char m_raw[0x90]; };                                               // TiXmlElement / TiXmlComment / TiXmlDeclaration storage
void FUN_14086f2f0(Unk_CMISXmlNode* pElem, const char* pszName);                            // TiXmlElement ctor
void FUN_1408704d0(Unk_CMISXmlNode* pDecl, const char* pszVersion, const char* pszEncoding, const char* pszStandalone);   // TiXmlDeclaration ctor
void FUN_1408700b0(Unk_CMISXmlNode* pComment, const char* pszText);                         // TiXmlComment ctor
class TiXmlNode   // C3: member view for the former free stand-ins
{
public:
    class TiXmlNode* InsertEndChild(class TiXmlNode const&);
};
class TiXmlElement { public: virtual ~TiXmlElement(); void SetAttribute(const char* pszName, const char* pszValue); };   // C3: unit-local view
class TiXmlComment { public: virtual ~TiXmlComment(); };   // C3: unit-local view
void XmlSetAttr(class TiXmlElement*, char const*, unsigned int);   // C3: was FUN_140873ce0
void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0
void XmlSetAttr(class TiXmlElement*, char const*, float);   // C3: was FUN_140873e30
void XmlSetAttr(class TiXmlElement*, char const*, const CString&);
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
Unk_CMISInsRes* FUN_14111d2d0(Unk_CMISColumnSet*, Unk_CMISInsRes*, const Unk_CMISPairRes&);   // insert
Unk_CMISAutoList* FUN_141122af0(Unk_CMISAutoList*);                                         // ctor
void FUN_141125c10(Unk_CMISAutoList*);                                                      // dtor
Unk_CMISInsRes* FUN_14111d370(Unk_CMISAutoList*, Unk_CMISInsRes*, const Unk_CMISAutoPtr*);   // insert
Unk_CMISIter<295>* FUN_14114e780(Unk_CMISAutoList*, Unk_CMISIter<295>*);                    // begin
Unk_CMISIter<295>* FUN_1411523f0(Unk_CMISAutoList*, Unk_CMISIter<295>*);                    // end
bool FUN_1411278c0(Unk_CMISIter<295>*, Unk_CMISIter<295>*);                                 // operator!=
Unk_CMISAutoPtr* FUN_141128b10(Unk_CMISIter<295>*);                                // operator*
void FUN_141129970(Unk_CMISIter<295>*);                                                     // operator++
int* FUN_141128660(Unk_CMISIter<262>*);                                                     // operator* (the group)
static CString Unk_CMISFormatPoint(const Unk_Int3& pt)                                      // "x,y,z" (0x141b6eee0)
{
    CString str;
    str.Format("%d,%d,%d", (unsigned)pt.x, (unsigned)pt.y, (unsigned)pt.z);
    return str;
}
// @0x1410d3450
// MS2-FUNCTIONAL: exe's temporaries and unwind states are laid out differently; the document is a stack object and the declaration node is not destroyed
int CubeMapInformationService::ExportUGCMap(CString strName)
{
    if (!CFieldData::FUN_140374410(WorldService::GetInstance()->FUN_141bd3060()))
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
    ((class TiXmlNode*)(void*)(&doc))->InsertEndChild(*(class TiXmlNode const*)(&decl));
    {
        Unk_CMISXmlNode comment;
        CString strComment = FUN_1409a2360(" \xc6\xc4\xbd\xcc\xc7\xd8\xbc\xad \xbb\xe7\xbf\xeb\xc7\xcf\xb4\xc2 \xb5\xa5\xc0\xcc\xc5\xcd\xc0\xcc\xb4\xcf \xc1\xf7\xc1\xa2 \xbc\xf6\xc1\xa4\xc7\xcf\xc1\xf6 \xb8\xb6\xbc\xbc\xbf\xe4 ", 0);
        FUN_1408700b0(&comment, strComment);
        ((class TiXmlNode*)(void*)(&doc))->InsertEndChild(*(class TiXmlNode const*)(&comment));
        ((TiXmlComment*)(void*)(&comment))->TiXmlComment::~TiXmlComment();
    }
    Unk_CMISXmlNode elemMap;
    FUN_14086f2f0(&elemMap, "ugcmap");
    ((TiXmlElement*)(void*)(&elemMap))->SetAttribute("baseCubePoint3", Unk_CMISFormatPoint(base));
    CString strSize;
    strSize.Format("%dx%dx%d", FUN_1410c3470(), FUN_1410c3470(), FUN_1410c34b0());
    ((TiXmlElement*)(void*)(&elemMap))->SetAttribute("indoorSizeType", strSize);
    efd::set<MS2Ptr<AutomaticCreateCubeInfo> > listAuto;
    efd::set<std::pair<int, int> > setDone;
    for (CMISEMap_int_set_int::iterator itGroup = reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->begin(); (itGroup != reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()); FUN_141129bb0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<262>*>(&itGroup)))) {
        int nGroup = *FUN_141128660(reinterpret_cast<Unk_CMISIter<262>*>(&itGroup));
        if (nGroup == 0)
            continue;
        Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nGroup)));
        for (CMISESet_int::iterator it = reinterpret_cast<CMISESet_int*>(pList)->begin(); (it != reinterpret_cast<CMISESet_int*>(pList)->end()); ++it) {
            Unk_Int3 cell = FUN_1408a0400(*((int*)(&*it)));
            if ((setDone.find(std::make_pair(cell.x, cell.y)) != setDone.end()))
                continue;
            Unk_CMISInsRes resDone;
            FUN_14111d2d0(reinterpret_cast<Unk_CMISColumnSet*>(&setDone), &resDone, FUN_14111d460(cell.x, cell.y));
            if (FUN_1410b8980(cell) == 0)
                continue;
            int nHeight = 0;
            if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130() == 0) {
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
                if ((reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->find(nColKey) == reinterpret_cast<CMISEMap_int_MS2Ptr_Cube*>(&fb8)->end()))
                    continue;
                MS2Ptr<Cube> spCube(*FUN_141127cd0(&fb8, &nColKey));
                if (spCube.get() == 0)
                    continue;
                MS2Ptr<CItemData> spItem = FUN_14053f870(((class Cube*)(class Cube*)(spCube.get()))->FUN_1408b4f20());
                if (spItem == 0)
                    continue;
                Unk_Int3 rel(col.x - base.x, col.y - base.y, col.z - base.z);
                float fRot;
                memcpy(&fRot, &spCube->fieldD4, sizeof(fRot));
                if (spItem->install.attachable == 0) {
                    Unk_CMISXmlNode elemCube;
                    FUN_14086f2f0(&elemCube, "cube");
                    XmlSetAttr((class TiXmlElement*)(&elemCube), "itemID", ((class Cube*)(class Cube*)(spCube.get()))->FUN_1408b4f20());
                    XmlSetAttr((class TiXmlElement*)(&elemCube), "offsetCubePoint3", Unk_CMISFormatPoint(rel));
                    XmlSetAttr((class TiXmlElement*)(&elemCube), "rotation", fRot);
                    XmlSetAttr((class TiXmlElement*)(&elemCube), "wallDir", 0);
                    ((class TiXmlNode*)(void*)(&elemMap))->InsertEndChild(*(class TiXmlNode const*)(&elemCube));
                    ((TiXmlElement*)(void*)(&elemCube))->TiXmlElement::~TiXmlElement();
                } else {
                    Vector3 ptRef;
                    FUN_1402bd040(&ptRef);
                    memcpy(&ptRef.z, &spCube->fieldD4, sizeof(float));
                    int nWallDir = FUN_1410ba5f0(cell, ptRef);
                    void* pMem = ::operator new(sizeof(Unk_CMISAutoCube));
                    FUN_141122e70(pMem);
                    Unk_CMISAutoPtr spInfo(static_cast<CPtred*>(pMem));
                    Unk_CMISAutoCube* pInfo = Unk_CMISAuto(spInfo);
                    pInfo->m_nItemId = ((class Cube*)(class Cube*)(spCube.get()))->FUN_1408b4f20();
                    pInfo->m_offset = rel;
                    pInfo->m_fRotation = fRot;
                    pInfo->m_nWallDir = nWallDir;
                    Unk_CMISInsRes itIns;
                    FUN_14111d370(reinterpret_cast<Unk_CMISAutoList*>(&listAuto), &itIns, &spInfo);
                }
            }
        }
    }
    for (CMISESet_MS2Ptr_AutomaticCreateCubeInfo::iterator itAuto = listAuto.begin(); (itAuto != listAuto.end()); ++itAuto) {
        Unk_CMISAutoPtr spInfo(*FUN_141128b10(reinterpret_cast<Unk_CMISIter<295>*>(&itAuto)));
        if (spInfo.get() == 0)
            continue;
        Unk_CMISXmlNode elemCube;
        FUN_14086f2f0(&elemCube, "cube");
        XmlSetAttr((class TiXmlElement*)(&elemCube), "itemID", Unk_CMISAuto(spInfo)->m_nItemId);
        XmlSetAttr((class TiXmlElement*)(&elemCube), "offsetCubePoint3", Unk_CMISFormatPoint(Unk_CMISAuto(spInfo)->m_offset));
        XmlSetAttr((class TiXmlElement*)(&elemCube), "rotation", Unk_CMISAuto(spInfo)->m_fRotation);
        XmlSetAttr((class TiXmlElement*)(&elemCube), "wallDir", (int)(unsigned char)Unk_CMISAuto(spInfo)->m_nWallDir);
        ((class TiXmlNode*)(void*)(&elemMap))->InsertEndChild(*(class TiXmlNode const*)(&elemCube));
        ((TiXmlElement*)(void*)(&elemCube))->TiXmlElement::~TiXmlElement();
    }
    ((class TiXmlNode*)(void*)(&doc))->InsertEndChild(*(class TiXmlNode const*)(&elemMap));
    CString strPath;
    strPath.Format("./Data/Xml/ExportedUGCMap/%s.xml", (const char*)strName);
    doc.SaveFile(FUN_14016a5c0(strPath, 0));
    ((TiXmlElement*)(void*)(&elemMap))->TiXmlElement::~TiXmlElement();
    return 1;
}

// ---- w142 batch 12 ----
extern Unk_CMISEntityRef DAT_143acf820;                                                     // the null entity ref (g_cubeMapNone of the statics header)
struct Unk_CMISMarkList { char m_b[0x18]; };                                                // list of the mark entities of a mark record (at +0x38 of the record)
const Unk_CMISEntityRef* FUN_141128e50(Unk_CMISEntSetIter*);                                // operator*
void* FUN_14112ab20(Unk_ListNode**);                                                        // operator++
class Unk_UhSetting   // C3: member view for the former free stand-ins
{
public:
    void Reset();
};
// The two arrays hold 16-byte payload handles: the exe RemoveAll runs each element's dtor (0x14112dc70 / 0x14112dcd0).
// Declared on tail14's Unk_CMISArr16 so the fullexe links its definitions; a CAtlArray<T*> declaration aliased to the
// pointer-array RemoveAll, which freed the buffer without releasing the designs and blueprints.
struct Unk_CMISArr16;
void FUN_14112f280(Unk_CMISArr16*);                                                         // RemoveAll
void FUN_14112f260(Unk_CMISArr16*);                                                         // RemoveAll
struct Unk_CMISActorEntry { Unk_CMISEntityRef m_key; void* m_pActor; };                     // node value of f48
Unk_CMISIter<257>* FUN_14114e320(Unk_CMISTree<257>*, Unk_CMISIter<257>*);                   // begin
Unk_CMISActorEntry* FUN_141128740(Unk_CMISIter<257>*);                                      // operator*
void FUN_141129c70(Unk_CMISIter<257>*);                                                     // operator++
struct Unk_CMISEffEntry { int m_key; int m_nEffect; };                                      // node value of f338
Unk_CMISEffEntry* FUN_14063ed80(Unk_CMISIter<285>*);                                        // operator*
void* FUN_141129a00(struct Unk_TreeIter*);   // C3: was FUN_141129a00
struct Unk_CMISSetEffNode { int m_key; int m_pad; MS2Ptr<SetItemEffectInfo> m_second; };    // node value of f348
Unk_CMISSetEffNode* FUN_1411285c0(Unk_CMISIter<279>*);                                      // operator*
void FUN_141129ae0(Unk_CMISIter<279>*);                                                     // operator++
// @0x1410d0310
void CubeMapInformationService::FUN_1410d0310()
{
    for (CMISEMap_int_EntityID::iterator itDefer = reinterpret_cast<CMISEMap_int_EntityID*>(&f2c8)->begin(); itDefer != reinterpret_cast<CMISEMap_int_EntityID*>(&f2c8)->end(); ++itDefer)
        RemovePhysXActor(Unk_CMISEntityRef(FUN_1411286a0(reinterpret_cast<Unk_CMISIter<265>*>(&itDefer))->m_ref));
    ((std::_Tree<std::_Tmap_traits<int, egf::EntityID, std::less<int>, efd::CustomAllocator<std::pair<int const, egf::EntityID>>, 0>>*)(void*)(&f2c8))->clear();
    for (CMISEMap_int_MarkRec::iterator itMark = reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->begin(); itMark != reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->end(); ++itMark) {
        Unk_CMISMarkRec& rec = FUN_141128500(reinterpret_cast<Unk_CMISIter<275>*>(&itMark))->m_rec;
        CMISVec_EntityPtr& rMarks = *reinterpret_cast<CMISVec_EntityPtr*>(rec.m_b + 0x38);
        CMISVec_EntityPtr::const_iterator itEntEnd = rMarks.end();
        for (CMISVec_EntityPtr::const_iterator itEnt = rMarks.begin(); FUN_141127980(reinterpret_cast<Unk_CMISEntSetIter*>(&itEnt), reinterpret_cast<Unk_CMISEntSetIter*>(&itEntEnd)); FUN_14112ab20(reinterpret_cast<Unk_ListNode**>(&itEnt))) {
            egf::EntityPtr spEnt = *(const egf::EntityPtr*)(FUN_141128e50(reinterpret_cast<Unk_CMISEntSetIter*>(&itEnt)));
            static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411cf570(((const egf::EntityPtr*)(&spEnt))->operator egf::Entity*());
        }
    }
    ((std::_Tree<std::_Tmap_traits<int, Unk_CMISMarkRec, std::less<int>, efd::CustomAllocator<std::pair<int const, Unk_CMISMarkRec>>, 0>>*)(void*)(&f288))->clear();
    *(egf::EntityID*)(&f2d8) = *(const egf::EntityID*)&(DAT_143acf820);
    ((std::_Tree<std::_Tmap_traits<int, Unk_CMISCubeTimer, std::less<int>, efd::CustomAllocator<std::pair<int const, Unk_CMISCubeTimer>>, 0>>*)(void*)(&f1f8))->clear();
    ((std::_Tree<std::_Tmap_traits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, int, std::less<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>, efd::CustomAllocator<std::pair<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>> const, int>>, 0>>*)(void*)(&f1a0))->clear();
    f1e0 = 1;
    f1b0 = 0;
    f1b4 = 0;
    f1b8 = 0;
    f1c0 = 0;
    s1c8 = L"";
    s1d0 = L"";
    f1d8 = 0;
    f1dc = 0;
    f208 = 0;
    f218 = 0;
    f2f0 = 0;
    f2f4 = 0;
    f478 = 0;
    f2f8 = 0;
    f2fc = 0;
    static_cast<Unk_Int3&>(p300) = Unk_Int3(0, 0, 0);
    static_cast<Unk_Int3&>(p30c) = Unk_Int3(0, 0, 0);
    ((class Unk_UhSetting*)(struct Unk_CMISFlags3*)(&f418))->Reset();
    f330 = 0;
    f3d8 = 0x12;
    f3dc = false;
    t3e0.FUN_1408687f0();
    for (int i = 0; i < 9; i++) {
        int k = i;
        *((unsigned char*)FUN_1411282d0((void*)(&f368), (struct Unk_Key*)(&k))) = 0;
    }
    for (int j = 0; j < 9; j++) {
        int k = j;
        *((int*)FUN_141128250((void*)(&f378), (struct Unk_Key*)(&k))) = 0;
    }
    FUN_14112f280(reinterpret_cast<Unk_CMISArr16*>(&a388));
    FUN_14112f260(reinterpret_cast<Unk_CMISArr16*>(&a3a8));
    reinterpret_cast<CMISEMap_KindA_int*>(&f3c8)->clear();
    ((std::_Tree<std::_Tmap_traits<int, efd::vector<efd::SmartPointer<egf::Entity>>, std::less<int>, efd::CustomAllocator<std::pair<int const, efd::vector<efd::SmartPointer<egf::Entity>>>>, 0>>*)(void*)(&f1e8))->clear();
    reinterpret_cast<CMISEMap_int_KindA*>(&f298)->clear();
    reinterpret_cast<CMISEMap_int_Cell*>(&f2b8)->clear();
    reinterpret_cast<CMISEMap_std_pair_int_int_MS2Ptr_SaleStateData*>(&fe8)->clear();
    DestroyFloorPhysX();
    for (int i = 0; i < 3; i++)
        RemovePhysActor(i);
    for (CMISEMap_EntityID_int64::iterator itActor = reinterpret_cast<CMISEMap_EntityID_int64*>(&f48)->begin(); itActor != reinterpret_cast<CMISEMap_EntityID_int64*>(&f48)->end(); ++itActor) {
        void* pActor = FUN_141128740(reinterpret_cast<Unk_CMISIter<257>*>(&itActor))->m_pActor;
        if (pActor != 0) {
            Unk_CMISPhysScene* pScene = ((class Unk_CMISPhysScene*)((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a1c0());
            if (pScene != 0) {
                ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a540(0);
                pScene->RemoveActor(pActor);
                ((class WorldService*)(class Unk_CMISWorld*)(reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())))->FUN_141bc8e00();
                ((class CPhysXHelper*)(class CPhysXHelper*)(((class CPhysXHelper*)FUN_1409f7ca0())))->FUN_14168a570();
            }
        }
    }
    ((std::_Tree<std::_Tmap_traits<egf::EntityID, __int64, std::less<egf::EntityID>, efd::CustomAllocator<std::pair<egf::EntityID const, __int64>>, 0>>*)(void*)(&f48))->clear();
    ((std::_Tree<std::_Tmap_traits<egf::EntityID, efd::SmartPointer<egfPhysX::EntityActorData>, std::less<egf::EntityID>, efd::CustomAllocator<std::pair<egf::EntityID const, efd::SmartPointer<egfPhysX::EntityActorData>>>, 0>>*)(void*)(&f58))->clear();
    FUN_14112ded0();
    FUN_14112dd30();
    ((std::_Tree<std::_Tmap_traits<egf::EntityID, MS2Ptr<Cube>, std::less<egf::EntityID>, efd::CustomAllocator<std::pair<egf::EntityID const, MS2Ptr<Cube>>>, 0>>*)(void*)(&f78))->clear();
    ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<Cube>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<Cube>>>, 0>>*)(void*)(&f88))->clear();
    ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<Cube>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<Cube>>>, 0>>*)(void*)(&f98))->clear();
    ((std::_Tree<std::_Tmap_traits<egf::EntityID, MS2Ptr<Cube>, std::less<egf::EntityID>, efd::CustomAllocator<std::pair<egf::EntityID const, MS2Ptr<Cube>>>, 0>>*)(void*)(&fa8))->clear();
    ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<Cube>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<Cube>>>, 0>>*)(void*)(&fb8))->clear();
    ((class Unk_CubeHeightIndex*)(void*)(&f2a8))->Clear();
    FUN_1402237c0((struct Unk_LevelArray*)(&a458));
    ((std::_Tree<std::_Tmap_traits<int, efd::set<int, std::less<int>>, std::less<int>, efd::CustomAllocator<std::pair<int const, efd::set<int, std::less<int>>>>, 0>>*)(void*)(&fd8))->clear();
    ((std::_Tree<std::_Tmap_traits<int, std::map<int, MS2Ptr<Cube>, std::less<int>, std::allocator<std::pair<int const, MS2Ptr<Cube>>>>, std::less<int>, efd::CustomAllocator<std::pair<int const, std::map<int, MS2Ptr<Cube>, std::less<int>, std::allocator<std::pair<int const, MS2Ptr<Cube>>>>>>, 0>>*)(void*)(&fc8))->clear();
    ((std::_Tree<std::_Tmap_traits<int, efd::SmartPointer<egf::Entity>, std::less<int>, efd::CustomAllocator<std::pair<int const, efd::SmartPointer<egf::Entity>>>, 0>>*)(void*)(&ff8))->clear();
    ((std::_Tree<std::_Tmap_traits<int, std::map<int, Unk_PayloadPtr<CubeOwner>, std::less<int>, std::allocator<std::pair<int const, Unk_PayloadPtr<CubeOwner>>>>, std::less<int>, std::allocator<std::pair<int const, std::map<int, Unk_PayloadPtr<CubeOwner>, std::less<int>, std::allocator<std::pair<int const, Unk_PayloadPtr<CubeOwner>>>>>>, 0>>*)(void*)(reinterpret_cast<Unk_CubeOwners*>(&f138)))->clear();
    reinterpret_cast<CMISEMap_u64_MS2Ptr_UidRecord*>(&f148)->clear();
    ((std::_Tree<std::_Tmap_traits<int, egf::EntityID, std::less<int>, efd::CustomAllocator<std::pair<int const, egf::EntityID>>, 0>>*)(void*)(&f108))->clear();
    ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<FittingDollData>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<FittingDollData>>>, 0>>*)(void*)(&f118))->clear();
    ((std::_Tree<std::_Tset_traits<int, std::less<int>, efd::CustomAllocator<int>, 0>>*)(void*)(&f128))->clear();
    ((std::_Tree<std::_Tmap_traits<int, egf::EntityID, std::less<int>, efd::CustomAllocator<std::pair<int const, egf::EntityID>>, 0>>*)(void*)(&f2e0))->clear();
    for (CMISEMap_int_u_int::iterator itEff = reinterpret_cast<CMISEMap_int_u_int*>(&f338)->begin(); itEff != reinterpret_cast<CMISEMap_int_u_int*>(&f338)->end(); FUN_141129a00((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<285>*>(&itEff)))) {
        int nEffect = FUN_14063ed80(reinterpret_cast<Unk_CMISIter<285>*>(&itEff))->m_nEffect;
        if (nEffect != 0)
            TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(nEffect);
    }
    ((std::_Tree<std::_Tmap_traits<int, unsigned int, std::less<int>, efd::CustomAllocator<std::pair<int const, unsigned int>>, 0>>*)(void*)(&f338))->clear();
    for (CMISEMap_int_MS2Ptr_SetItemEffectInfo::iterator itSet = reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->begin(); itSet != reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->end(); FUN_141129ae0(reinterpret_cast<Unk_CMISIter<279>*>(&itSet))) {
        MS2Ptr<SetItemEffectInfo> spEff(FUN_1411285c0(reinterpret_cast<Unk_CMISIter<279>*>(&itSet))->m_second);
        if (spEff->m_nEffect != 0)
            TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(spEff->m_nEffect);
    }
    reinterpret_cast<CMISEMap_int_MS2Ptr_SetItemEffectInfo*>(&f348)->clear();
    ((std::_Tree<std::_Tmap_traits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, int, std::less<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>, efd::CustomAllocator<std::pair<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>> const, int>>, 0>>*)(void*)(&f358))->clear();
    for (CMISMap_int_MS2Ptr_UICubeUGCHead::iterator itHead = reinterpret_cast<CMISMap_int_MS2Ptr_UICubeUGCHead*>(&f228)->begin(); itHead != reinterpret_cast<CMISMap_int_MS2Ptr_UICubeUGCHead*>(&f228)->end(); FUN_141129b70(reinterpret_cast<Unk_CMISIter<273>*>(&itHead))) {
        ((class UICubeUGCHead*)(class Unk_CMISPolyObj*)(FUN_1411284c0(&FUN_141128600(reinterpret_cast<Unk_CMISIter<273>*>(&itHead))->second)))->FUN_141906680();
    }
    ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<UICubeUGCHead>, std::less<int>, std::allocator<std::pair<int const, MS2Ptr<UICubeUGCHead>>>, 0>>*)(void*)(&f228))->clear();
    if (Unk_CMISHouseMark* pHouse = FUN_1410dc020())
        pHouse->vfunc_3();    // MS2: slot 3
    reinterpret_cast<CMISMap_int_MS2Ptr_SalesInfo*>(&f238)->clear();
    f480 = 0;
    ((std::_Tree<std::_Tset_traits<MS2Ptr<CFunctionCubeObject>, std::less<MS2Ptr<CFunctionCubeObject>>, std::allocator<MS2Ptr<CFunctionCubeObject>>, 0>>*)(void*)(&f498))->clear();
    f420 = 0;
    f428 = 0;
    ((std::_Tree<std::_Tset_traits<unsigned __int64, std::less<unsigned __int64>, std::allocator<unsigned __int64>, 0>>*)(void*)(&f430))->clear();
    ((std::_Tree<std::_Tmap_traits<int, std::map<unsigned int, std::set<int, std::less<int>, std::allocator<int>>, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, std::set<int, std::less<int>, std::allocator<int>>>>>, std::less<int>, std::allocator<std::pair<int const, std::map<unsigned int, std::set<int, std::less<int>, std::allocator<int>>, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, std::set<int, std::less<int>, std::allocator<int>>>>>>>, 0>>*)(void*)(&f440))->clear();
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
void FUN_140de0cb0(efd::AssetID* pAsset, const efd::utf8string& strUrn);                                // set the urn
void FUN_14111d240(Unk_CMISIntList*, Unk_CMISInsRes*, const int*);                          // insert
// @0x1410cc160
void CubeMapInformationService::FUN_1410cc160(int nKind)
{
    if (nKind != 0) {
        Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        Unk_CMISXformVec vecXform;
        for (CMISEMap_int_set_int::iterator itGroup = reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->begin(); (itGroup != reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()); FUN_141129bb0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<262>*>(&itGroup)))) {
            int nGroup = *FUN_141128660(reinterpret_cast<Unk_CMISIter<262>*>(&itGroup));
            if (nGroup == 0)
                continue;
            Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
            if (FUN_1408a8dd0(&spOwner, 0))
                continue;
            int nFlag = 0;
            if (FUN_1408a0890(WorldService::GetInstance()->FUN_141bd3060(), nGroup, &nFlag) == 0)
                continue;
            if (nFlag != 0)
                continue;
            if (spOwner->ownerID != ((PC*)pRoster)->FUN_141656ad0() && !FUN_140930c90(spOwner->ownerID) && !FUN_140930d20(spOwner->ownerID))
                continue;
            FUN_1410ccc00(nGroup, 0, 0);
            Unk_CMISIntList setSeen;
            Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nGroup)));
            for (CMISESet_int::iterator it = reinterpret_cast<CMISESet_int*>(pList)->begin(); (it != reinterpret_cast<CMISESet_int*>(pList)->end()); ++it) {
                int nCell = *((int*)(&*it));
                Unk_Int3 cell = FUN_1408a0400(nCell);
                Cube* pCube = FUN_1410b8980(cell);
                if (pCube == 0)
                    continue;
                if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130() && !(cell.x >= p300.x && cell.y >= p300.y && cell.z >= p300.z))
                    continue;
                int nCellKey = FUN_1408a03c0(pCube->position);
                if ((reinterpret_cast<CMISESet_int*>(&setSeen)->find(nCellKey) != reinterpret_cast<CMISESet_int*>(&setSeen)->end()))
                    continue;
                int nCellKey2 = FUN_1408a03c0(pCube->position);
                Unk_CMISInsRes resIns;
                FUN_14111d240(&setSeen, &resIns, &nCellKey2);
                cell = pCube->position;
                efd::Point3 ptGuide;
                FUN_1408a15b0(cell, reinterpret_cast<Vector3&>(ptGuide));
                Unk_Int3 cellN = cell;
                efd::Point3 ptWalk = ptGuide;
                cellN = cell;
                cellN.x++;
                if (FUN_1410cba80(pCube->field44, nGroup, &cellN, reinterpret_cast<Unk_CMISPt3*>(&ptWalk)) != 0)
                    FUN_1410cbb40(&vecXform, 0, nGroup, reinterpret_cast<Vector3&>(ptWalk), cellN, true, 0);
                ptWalk = ptGuide;
                cellN = cell;
                cellN.y++;
                if (FUN_1410cba80(pCube->field44, nGroup, &cellN, reinterpret_cast<Unk_CMISPt3*>(&ptWalk)) != 0)
                    FUN_1410cbb40(&vecXform, 0, nGroup, reinterpret_cast<Vector3&>(ptWalk), cellN, false, 0);
                efd::Point3 ptRot(90.0f, 0.0f, 0.0f);
                if (pCube->field44 != 2)
                    ptGuide.z = ptGuide.z + 150.0f;
                NiTransform xform;
                xform.MakeIdentity();
                xform.m_Translate = ptGuide;
                xform.m_Rotate.FromEulerAnglesXYZ((-ptRot.x * 3.1415927f) / 180.0f, (-ptRot.y * 3.1415927f) / 180.0f, (-ptRot.z * 3.1415927f) / 180.0f);
                FUN_14115a9c0(&vecXform, &xform);
            }
        }
        efd::AssetID asset;
        {
            efd::utf8string strUrn("urn:gamebryo-scenegraph:Eff_Build_GuideLine_01");
            FUN_140de0cb0(&asset, strUrn);
        }
        NiTransform* pXforms = static_cast<NiTransform*>(efd::_Malloc(vecXform.FUN_14115af10() * sizeof(NiTransform), efd::MemHint()));
        for (unsigned __int64 i = 0; i < vecXform.FUN_14115af10(); i++)
            pXforms[i] = *vecXform.FUN_141128390(i);
        Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
        efd::utf8string strProp("MS2PhysXProp");
        *(egf::EntityID*)(&f2d8) = *(const egf::EntityID*)&(reinterpret_cast<const Unk_CMISEntityRef&>(static_cast<const egf::EntityID&>(spInst.FUN_14098d0e0()->FUN_1413d49f0(strProp, asset, false, pXforms, (int)vecXform.FUN_14115af10(), (int)vecXform.FUN_14115af10()))));
    } else {
        if ((*(const egf::EntityID*)(&f2d8) != *(const egf::EntityID*)(&DAT_143acf820))) {
            Unk_CMISSvcPtr spInst(((class HardwareInstancingService*)FUN_14098c5b0(&DAT_143b059e8)));
            spInst.FUN_14098d0e0()->FUN_1413d5220(reinterpret_cast<const egf::EntityID&>(f2d8));
            *(egf::EntityID*)(&f2d8) = *(const egf::EntityID*)&(DAT_143acf820);
        }
    }
}

// ---- w142 batch 14 ----
bool FUN_1411270d0(Unk_CMISIter<259>*, Unk_CMISIter<259>*);                                 // operator==
Unk_CMISIter<256>* FUN_1411589a0(Unk_CMISTree<256>*, Unk_CMISIter<256>*, const Unk_CMISEntityRef*);   // find
void FUN_141156cf0(Unk_CMISTree<256>*, Unk_CMISIter<256>*, Unk_CMISIter<256>);              // erase
void FUN_141852050(void*, unsigned int);   // C3: was FUN_141852050
// @0x1410cf5c0
void CubeMapInformationService::FUN_1410cf5c0(egf::Entity* pEntity)
{
    CMISEMap_EntityID_MS2Ptr_Cube::iterator itFind = reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&f78)->find(*reinterpret_cast<const egf::EntityID*>(((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(pEntity))->GetEntityID())));
    if (itFind == reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&f78)->end())
        return;
    MS2Ptr<Cube> spCube(FUN_141128780(reinterpret_cast<Unk_CMISIter<259>*>(&itFind))->second);
    reinterpret_cast<CMISEMap_EntityID_MS2Ptr_Cube*>(&f78)->erase(itFind);
    CMISESet_EntityID::iterator itPending = reinterpret_cast<CMISESet_EntityID*>(&f68)->find(*reinterpret_cast<const egf::EntityID*>(((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(pEntity))->GetEntityID())));
    if (itPending != reinterpret_cast<CMISESet_EntityID*>(&f68)->end()) {
        Unk_CMISInsRes itIns;
        FUN_14111d3f0(&f30, &itIns, ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(pEntity))->GetEntityID()));
        reinterpret_cast<CMISESet_EntityID*>(&f68)->erase(itPending);
    } else {
        int nKey = FUN_1408a03c0(spCube->position);
        if (reinterpret_cast<CMISEMap_int_EntityID*>(&f2e0)->find(nKey) != reinterpret_cast<CMISEMap_int_EntityID*>(&f2e0)->end()) {
            egf::EntityID idCur = *reinterpret_cast<const egf::EntityID*>(((struct Unk_CMISEntityRef*)FUN_141127ed0((void*)(&f2e0), (void*)(&nKey))));
            egf::EntityPtr spCur(reinterpret_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411cf440(idCur));
            if (((const egf::EntityPtr*)(&spCur))->operator egf::Entity*() != 0) {
                Unk_CMISInsRes itIns;
                FUN_14111d3f0(&f30, &itIns, ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(pEntity))->GetEntityID()));
                *(egf::EntityPtr*)(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)) = spCur;
            }
        }
        if (reinterpret_cast<CMISESet_int*>(&f128)->find(nKey) != reinterpret_cast<CMISESet_int*>(&f128)->end()) {
            if (reinterpret_cast<CMISEMap_int_MS2Ptr_FittingDollData*>(&f118)->find(nKey) != reinterpret_cast<CMISEMap_int_MS2Ptr_FittingDollData*>(&f118)->end()) {
                Unk_CMISBlock rec(*((struct Unk_CMISBlock*)FUN_141127c10((void*)(&f118), (void*)(&nKey))));
                egf::EntityPtr spNew = FUN_1410bc3d0(Unk_CMISBlock(rec));
                egf::EntityPtr spOld = *(const egf::EntityPtr*)(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity));
                *(egf::EntityPtr*)(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)) = spNew;
                Unk_CMISInsRes itIns;
                FUN_14111d3f0(&f30, &itIns, ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spOld))->operator->()))->GetEntityID()));
                ((std::_Tree<std::_Tset_traits<int, std::less<int>, efd::CustomAllocator<int>, 0>>*)(void*)(&f128))->erase(*(int const*)(&nKey));
                ((std::_Tree<std::_Tmap_traits<int, MS2Ptr<FittingDollData>, std::less<int>, efd::CustomAllocator<std::pair<int const, MS2Ptr<FittingDollData>>>, 0>>*)(void*)(&f118))->erase(*(int const*)(&nKey));
            }
        }
        FUN_1410d0e30(((const egf::EntityPtr*)(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)))->operator egf::Entity*(), spCube);
        FUN_1410c06b0(spCube);
        FUN_1410c2ce0(((const egf::EntityPtr*)(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)))->operator egf::Entity*());
        if (spCube->fieldB0 != 0) {
            if (((egf::FlatModel*)(Unk_CMISFlatModel*)(((class Unk_CMISFlatModel*)((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetModel())))->ContainsModel(0x48ccc02d)) {
                efd::utf8string strOn("On");
                FUN_1409a1fc0(FUN_141b6f910(), ((struct Unk_CMISEntityRef const*)&((egf::Entity*)(void*)(((const egf::EntityPtr*)(&spCube->entity))->operator->()))->GetEntityID()), &strOn, 1.0f, false);
            } else {
                NiAVObject* pRoot = FUN_141b6efc0(((const egf::EntityPtr*)(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)))->operator egf::Entity*());
                if (pRoot != 0)
                    FUN_141852050((void*)(pRoot), 0);
            }
        }
        if (spCube->field4c != 0) {
            CString strKey;
            strKey.Format("%d_%d", spCube->field44, FUN_1408a03c0(spCube->position));
            MS2Ptr<Unk_WsB_Lift> spNpc = WorldService::GetInstance()->FindLiftByName(strKey); // returned in place, as in the exe (no ctor)
            if ((__int64)spNpc.get() != 0)
                reinterpret_cast<CLiftableObject*>(spNpc.operator->())->BindEntity(reinterpret_cast<Unk_Entity*>(((const egf::EntityPtr*)(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)))->operator egf::Entity*()));
        } else {
            if (spCube->fieldB4 != 0)
                FUN_1410d0000(((const egf::EntityPtr*)(reinterpret_cast<Unk_CMISEntityRef*>(&spCube->entity)))->operator egf::Entity*(), spCube);
        }
        FUN_1410be6e0(spCube);
        if (!FUN_1410cb900() && reinterpret_cast<const CMISESet_EntityID*>(&f78)->size() == 0) {
            SetTimerEnabled(true);
            COutPacket packet(static_cast<int>(SendOp::ResponseFieldEnter), 0);
            packet.WriteInt32(reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())->FUN_141bd98d0());
            FUN_140710590(packet);
            reinterpret_cast<Unk_CMISWorld*>(WorldService::GetInstance())->FUN_141bdb690();
        }
        if (FUN_1410cb900())
            FUN_1410bf470();
        FUN_1410ce020(spCube);
    }
    if (f478 != 0 && ((std::_Tree<std::_Tset_traits<egf::EntityID, std::less<egf::EntityID>, efd::CustomAllocator<egf::EntityID>, 0>>*)(void*)(&f78))->empty()) {
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.WriteUInt8(0x44);
        packet.WriteInt64(f478);
        FUN_140710590(packet);
        f478 = 0;
    }
}

// ---- w142 batch 15 ----
char* FUN_141127f50(void*, struct Unk_Key*);   // C3: was FUN_141127f50
// @0x1410cd440
void CubeMapInformationService::FUN_1410cd440()
{
    efd::Point3 FUN_1408a15b0(Vector3, const Vector3&);
    Unk_CMISRoster* pRoster = ((Unk_CMISRoster*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    reinterpret_cast<CMISEMap_int_KindA*>(&f298)->clear();
    for (CMISEMap_int_set_int::iterator itGroup = reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->begin(); (itGroup != reinterpret_cast<CMISEMap_int_set_int*>(&fd8)->end()); FUN_141129bb0((struct Unk_TreeIter*)(reinterpret_cast<Unk_CMISIter<262>*>(&itGroup)))) {
        int nGroup = *FUN_141128660(reinterpret_cast<Unk_CMISIter<262>*>(&itGroup));
        if (nGroup == 0)
            continue;
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (FUN_1408a8dd0(&spOwner, 0))
            continue;
        int nFlag = 0;
        if (FUN_1408a0890(WorldService::GetInstance()->FUN_141bd3060(), nGroup, &nFlag) == 0)
            continue;
        if (nFlag != 0)
            continue;
        if (spOwner->ownerID != ((PC*)pRoster)->FUN_141656ad0() && !FUN_140930c90(spOwner->ownerID) && !FUN_140930d20(spOwner->ownerID))
            continue;
        Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nGroup)));
        for (CMISESet_int::iterator it = reinterpret_cast<CMISESet_int*>(pList)->begin(); (it != reinterpret_cast<CMISESet_int*>(pList)->end()); ++it) {
            int nCellKey = *it;
            Unk_Int3 cell = FUN_1408a0400(nCellKey);
            Cube* pCube = FUN_1410b8980(cell);
            if (pCube == 0)
                continue;
            if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130() && !(cell.x >= p300.x && cell.y >= p300.y && cell.z >= p300.z))
                continue;
            cell = pCube->position;
            if (pCube->field44 != 1)
                cell.z--;
            Vector3 ptZero;
            FUN_1408a15b0(*(Vector3*)&cell, ptZero);
            Unk_Int3 base = cell;
            int nHeight = 0;
            if ((*(MS2Ptr<CFieldDataCli>*)(void*)(&f208))->FUN_140375130())
                nHeight = f2fc;
            else if (f218 != 0 && f218->groups.find(nGroup) != f218->groups.end())
                nHeight = f218->groups[nGroup].heightLimit;
            int nTop = nHeight + 2;
            for (int dz = -1; dz < nTop; dz++) {
                Unk_Int3 pt = cell;
                pt.z += dz;
                int nKey0 = FUN_1408a03c0(pt);
                *((bool*)FUN_141127f50((void*)(&f298), (struct Unk_Key*)(&nKey0))) = true;
                Unk_CubePoint q;
                (Unk_Int3&)q = pt;
                q.x--;
                int nKey1 = FUN_1408a03c0((Unk_Int3&)q);
                *((bool*)FUN_141127f50((void*)(&f298), (struct Unk_Key*)(&nKey1))) = true;
                (Unk_Int3&)q = pt;
                q.x++;
                int nKey2 = FUN_1408a03c0((Unk_Int3&)q);
                *((bool*)FUN_141127f50((void*)(&f298), (struct Unk_Key*)(&nKey2))) = true;
                (Unk_Int3&)q = pt;
                q.y--;
                int nKey3 = FUN_1408a03c0((Unk_Int3&)q);
                *((bool*)FUN_141127f50((void*)(&f298), (struct Unk_Key*)(&nKey3))) = true;
                (Unk_Int3&)q = pt;
                q.y++;
                int nKey4 = FUN_1408a03c0((Unk_Int3&)q);
                *((bool*)FUN_141127f50((void*)(&f298), (struct Unk_Key*)(&nKey4))) = true;
                (Unk_Int3&)q = pt;
                q.x++;
                q.y++;
                int nKey5 = FUN_1408a03c0((Unk_Int3&)q);
                *((bool*)FUN_141127f50((void*)(&f298), (struct Unk_Key*)(&nKey5))) = true;
                (Unk_Int3&)q = pt;
                q.x--;
                q.y++;
                int nKey6 = FUN_1408a03c0((Unk_Int3&)q);
                *((bool*)FUN_141127f50((void*)(&f298), (struct Unk_Key*)(&nKey6))) = true;
                (Unk_Int3&)q = pt;
                q.x++;
                q.y--;
                int nKey7 = FUN_1408a03c0((Unk_Int3&)q);
                *((bool*)FUN_141127f50((void*)(&f298), (struct Unk_Key*)(&nKey7))) = true;
                (Unk_Int3&)q = pt;
                q.x--;
                q.y--;
                int nKey8 = FUN_1408a03c0((Unk_Int3&)q);
                *((bool*)FUN_141127f50((void*)(&f298), (struct Unk_Key*)(&nKey8))) = true;
            }
        }
    }
}

// ---- w142 batch 16 ----
// @0x1410d1820
int CubeMapInformationService::FUN_1410d1820(void* pArg, int nDir, Vector3 pt, Vector3 ptCur, void** ppFound)
{
    int bNoC;
    int bNoB;
    int bNoDiag;
    int nMissing = 0;
    *ppFound = 0;
    float fDx = FUN_14029d220(pt.x - ptCur.x);
    float fDy = FUN_14029d220(pt.y - ptCur.y);
    switch (nDir) {
    case 1:
        bNoDiag = FUN_1410b9080(static_cast<Cube*>(pArg), 0x1ff) == 0;
        bNoB = FUN_1410b9080(static_cast<Cube*>(pArg), 0xff) == 0;
        bNoC = FUN_1410b9080(static_cast<Cube*>(pArg), 0x100) == 0;
        nMissing = bNoDiag + bNoB + bNoC;
        switch (nMissing) {
        case 0:
            return 0;
        case 1:
            if (bNoDiag == 0) {
                if (bNoB == 0) {
                    *ppFound = FUN_1410b9080(static_cast<Cube*>(pArg), 0xff);
                    return 3;
                } else if (bNoC == 0) {
                    *ppFound = FUN_1410b9080(static_cast<Cube*>(pArg), 0x100);
                    return 7;
                }
            }
        case 2:
            if (fDx > fDy) {
                if (bNoB != 0)
                    nDir = 8;
                else if (bNoC != 0)
                    nDir = 2;
            } else {
                if (bNoC != 0)
                    nDir = 2;
                else if (bNoB != 0)
                    nDir = 8;
            }
            return nDir;
        default:
            return nDir;
        }
    case 2:
        if (FUN_1410b9080(static_cast<Cube*>(pArg), 0x100) != 0)
            nDir = 0;
        break;
    case 3:
        bNoDiag = FUN_1410b9080(static_cast<Cube*>(pArg), 0x101) == 0;
        bNoB = FUN_1410b9080(static_cast<Cube*>(pArg), 1) == 0;
        bNoC = FUN_1410b9080(static_cast<Cube*>(pArg), 0x100) == 0;
        nMissing = bNoDiag + bNoB + bNoC;
        switch (nMissing) {
        case 0:
            return 0;
        case 1:
            if (bNoDiag == 0) {
                if (bNoB == 0) {
                    *ppFound = FUN_1410b9080(static_cast<Cube*>(pArg), 1);
                    return 1;
                } else if (bNoC == 0) {
                    *ppFound = FUN_1410b9080(static_cast<Cube*>(pArg), 0x100);
                    return 5;
                }
            }
        case 2:
            if (fDx > fDy) {
                if (bNoB != 0)
                    nDir = 4;
                else if (bNoC != 0)
                    nDir = 2;
            } else {
                if (bNoC != 0)
                    nDir = 2;
                else if (bNoB != 0)
                    nDir = 4;
            }
            return nDir;
        default:
            return nDir;
        }
    case 4:
        if (FUN_1410b9080(static_cast<Cube*>(pArg), 1) != 0)
            nDir = 0;
        break;
    case 5:
        bNoDiag = FUN_1410b9080(static_cast<Cube*>(pArg), 0xff01) == 0;
        bNoB = FUN_1410b9080(static_cast<Cube*>(pArg), 1) == 0;
        bNoC = FUN_1410b9080(static_cast<Cube*>(pArg), 0xff00) == 0;
        nMissing = bNoDiag + bNoB + bNoC;
        switch (nMissing) {
        case 0:
            return 0;
        case 1:
            if (bNoDiag == 0) {
                if (bNoB == 0) {
                    *ppFound = FUN_1410b9080(static_cast<Cube*>(pArg), 1);
                    return 7;
                } else if (bNoC == 0) {
                    *ppFound = FUN_1410b9080(static_cast<Cube*>(pArg), 0xff00);
                    return 3;
                }
            }
        case 2:
            if (fDx > fDy) {
                if (bNoB != 0)
                    nDir = 4;
                else if (bNoC != 0)
                    nDir = 6;
            } else {
                if (bNoC != 0)
                    nDir = 6;
                else if (bNoB != 0)
                    nDir = 4;
            }
            return nDir;
        default:
            return nDir;
        }
    case 6:
        if (FUN_1410b9080(static_cast<Cube*>(pArg), 0xff00) != 0)
            nDir = 0;
        break;
    case 7:
        bNoDiag = FUN_1410b9080(static_cast<Cube*>(pArg), 0xffff) == 0;
        bNoB = FUN_1410b9080(static_cast<Cube*>(pArg), 0xff) == 0;
        bNoC = FUN_1410b9080(static_cast<Cube*>(pArg), 0xff00) == 0;
        nMissing = bNoDiag + bNoB + bNoC;
        switch (nMissing) {
        case 0:
            return 0;
        case 1:
            if (bNoDiag == 0) {
                if (bNoB == 0) {
                    *ppFound = FUN_1410b9080(static_cast<Cube*>(pArg), 0xff);
                    return 5;
                } else if (bNoC == 0) {
                    *ppFound = FUN_1410b9080(static_cast<Cube*>(pArg), 0xff00);
                    return 1;
                }
            }
        case 2:
            if (fDx > fDy) {
                if (bNoB != 0)
                    nDir = 8;
                else if (bNoC != 0)
                    nDir = 6;
            } else {
                if (bNoC != 0)
                    nDir = 6;
                else if (bNoB != 0)
                    nDir = 8;
            }
            return nDir;
        default:
            return nDir;
        }
    case 8:
        if (FUN_1410b9080(static_cast<Cube*>(pArg), 0xff) != 0)
            nDir = 0;
    }
    return nDir;
}

// ---- w142 batch 17 ----
// @0x1410ccc00
void CubeMapInformationService::FUN_1410ccc00(int nGroup, int nA, int nB)
{
    efd::Point3 FUN_1408a15b0(Vector3, const Vector3&);
    if (nA != 0) {
        if (reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->find(nGroup) != reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->end())
            return;
        Unk_CMISXformVec vecXform;
        Unk_CMISIntList setSeen;
        Unk_CMISIntList* pList = ((struct Unk_CMISIntList*)FUN_141127e10((void*)(&fd8), (void*)(&nGroup)));
        for (CMISESet_int::iterator it = reinterpret_cast<CMISESet_int*>(pList)->begin(); (it != reinterpret_cast<CMISESet_int*>(pList)->end()); ++it) {
            int nKey = *it;
            Unk_Int3 cell = FUN_1408a0400(nKey);
            Cube* pCube = FUN_1410b8980(cell);
            if (pCube == 0)
                continue;
            int nCellKey = FUN_1408a03c0(pCube->position);
            if (reinterpret_cast<CMISESet_int*>(&setSeen)->find(nCellKey) != reinterpret_cast<CMISESet_int*>(&setSeen)->end())
                continue;
            reinterpret_cast<CMISESet_int*>(&setSeen)->insert(FUN_1408a03c0(pCube->position));
            cell = pCube->position;
            Vector3 ptGuide;
            FUN_1408a15b0(*(Vector3*)&cell, ptGuide);
            Unk_Int3 cellSide = cell;
            Vector3 ptWalk = ptGuide;
            cellSide.x--;
            if (FUN_1410cba80(pCube->field44, nGroup, &cellSide, reinterpret_cast<Unk_CMISPt3*>(&ptWalk)) != 0)
                FUN_1410cbb40(&vecXform, 1, nGroup, ptWalk, cellSide, true, nB);
            ptWalk = ptGuide;
            cellSide = cell;
            cellSide.x++;
            if (FUN_1410cba80(pCube->field44, nGroup, &cellSide, reinterpret_cast<Unk_CMISPt3*>(&ptWalk)) != 0)
                FUN_1410cbb40(&vecXform, 1, nGroup, ptWalk, cellSide, true, nB);
            ptWalk = ptGuide;
            cellSide = cell;
            cellSide.y--;
            if (FUN_1410cba80(pCube->field44, nGroup, &cellSide, reinterpret_cast<Unk_CMISPt3*>(&ptWalk)) != 0)
                FUN_1410cbb40(&vecXform, 1, nGroup, ptWalk, cellSide, false, nB);
            ptWalk = ptGuide;
            cellSide = cell;
            cellSide.y++;
            if (FUN_1410cba80(pCube->field44, nGroup, &cellSide, reinterpret_cast<Unk_CMISPt3*>(&ptWalk)) != 0)
                FUN_1410cbb40(&vecXform, 1, nGroup, ptWalk, cellSide, false, nB);
        }
    } else {
        if (reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->find(nGroup) == reinterpret_cast<CMISEMap_int_MarkRec*>(&f288)->end())
            return;
        {
            Unk_CMISMarkRec* pRec = ((struct Unk_CMISMarkRec*)FUN_141127a90((void*)(&f288), (void*)(&nGroup)));
            CMISVec_EntityPtr& rMarks = *reinterpret_cast<CMISVec_EntityPtr*>(pRec->m_b + 0x38);
            CMISVec_EntityPtr::const_iterator itEntEnd = rMarks.end();
            for (CMISVec_EntityPtr::const_iterator itEnt = rMarks.begin(); FUN_141127980(reinterpret_cast<Unk_CMISEntSetIter*>(&itEnt), reinterpret_cast<Unk_CMISEntSetIter*>(&itEntEnd)); FUN_14112ab20(reinterpret_cast<Unk_ListNode**>(&itEnt))) {
                egf::EntityPtr spEnt = *(const egf::EntityPtr*)(FUN_141128e50(reinterpret_cast<Unk_CMISEntSetIter*>(&itEnt)));
                static_cast<Unk_CMISWorldMgr*>(TSingleton<EntityWorldManager>::GetInstance())->FUN_1411cf570(((const egf::EntityPtr*)(&spEnt))->operator egf::Entity*());
            }
            ((std::vector<efd::SmartPointer<egf::Entity>, efd::CustomAllocator<efd::SmartPointer<egf::Entity>>>*)(pRec->m_b + 0x38))->clear();
            ((std::_Tree<std::_Tmap_traits<int, Unk_CMISMarkRec, std::less<int>, efd::CustomAllocator<std::pair<int const, Unk_CMISMarkRec>>, 0>>*)(void*)(&f288))->erase(*(int const*)(&nGroup));
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
MS2_REPLACE_METHOD(0x1410b7ed0, CubeMapInformationService, HasCubeAtKey, 186, 0xAC1530CD);
MS2_REPLACE_METHOD(0x1410b85f0, CubeMapInformationService, ComputeCellBounds, 395, 0xB3929125);
MS2_REPLACE_METHOD(0x1410b8b00, CubeMapInformationService, GetCubeByKey, 216, 0xCBC48B0D);
MS2_REPLACE_METHOD(0x1410b8be0, CubeMapInformationService, FindCubeByEntityRef, 156, 0xB429EB82);
MS2_REPLACE_METHOD(0x1410b8c90, CubeMapInformationService, FUN_1410b8c90, 246, 0x10AD86AF);
MS2_REPLACE_METHOD(0x1410b8d90, CubeMapInformationService, FUN_1410b8d90, 196, 0x55FF5994);
MS2_REPLACE_METHOD(0x1410b9080, CubeMapInformationService, FUN_1410b9080, 185, 0x677D3CED);
MS2_REPLACE_METHOD(0x1410b8e60, CubeMapInformationService, GetCubeByEntity, 196, 0x3F8F57AF);
MS2_REPLACE_METHOD(0x1410b9850, CubeMapInformationService, FindCubeByItemId, 236, 0xADA8963A);
MS2_REPLACE_METHOD(0x1410b9950, CubeMapInformationService, HasCubeWithIconCode, 235, 0xC5339393);
MS2_REPLACE_METHOD(0x1410b9a50, CubeMapInformationService, CountCubes, 196, 0x95408E66);
MS2_REPLACE_METHOD(0x1410b9b20, CubeMapInformationService, CountCubesByItemId, 239, 0x9BF4E278);
MS2_REPLACE_METHOD(0x1410b9d80, CubeMapInformationService, FUN_1410b9d80, 230, 0x9186AEEE);
MS2_REPLACE_METHOD(0x1410b9e70, CubeMapInformationService, FUN_1410b9e70, 17, 0xF99D8EA5);
MS2_REPLACE_METHOD(0x1410b9c20, CubeMapInformationService, CountCubesByItemIdAndOwner, 332, 0x3020E9D3);
MS2_REPLACE_METHOD(0x1410ba440, CubeMapInformationService, DirectionToAngle, 89, 0x086CED8D);
MS2_REPLACE_METHOD(0x1410bba60, CubeMapInformationService, FUN_1410bba60, 74, 0xA664D743);
MS2_REPLACE_METHOD(0x1410bbab0, CubeMapInformationService, FUN_1410bbab0, 319, 0x2A5ADFAB);
MS2_REPLACE_METHOD(0x1410bbc00, CubeMapInformationService, FUN_1410bbc00, 187, 0x2F873811);
MS2_REPLACE_METHOD(0x1410bc1c0, CubeMapInformationService, FUN_1410bc1c0, 341, 0xA1F224F9);
MS2_REPLACE_METHOD(0x1410bc320, CubeMapInformationService, FUN_1410bc320, 167, 0x50877F16);
MS2_REPLACE_METHOD(0x1410bf250, CubeMapInformationService, IncrementKeyCount, 200, 0x61F0F4F0);
MS2_REPLACE_METHOD(0x1410bf320, CubeMapInformationService, DecrementKeyCount, 175, 0xD2D50267);
MS2_REPLACE_METHOD(0x1410bf3e0, CubeMapInformationService, GetKeyCount, 136, 0x318E7974);
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
MS2_REPLACE_METHOD(0x1410cb8b0, CubeMapInformationService, SetTimerEnabled, 66, 0xE066738E);
MS2_REPLACE_METHOD(0x1410cb920, CubeMapInformationService, HasTimerExpired, 85, 0x297258A7);
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
MS2_REPLACE_METHOD(0x1410cb420, CubeMapInformationService, ContainsEntityRef, 144, 0x21D42334);
MS2_REPLACE_METHOD(0x1410d2730, CubeMapInformationService, IsCellInBounds, 129, 0xC7765144);
MS2_REPLACE_METHOD(0x1410d4340, CubeMapInformationService, FUN_1410d4340, 122, 0x714CCD58);
MS2_REPLACE_METHOD(0x1410c4d80, CubeMapInformationService, FUN_1410c4d80, 147, 0xB8AE8FB4);
MS2_REPLACE_METHOD(0x1410c68e0, CubeMapInformationService, ClearCubes, 149, 0xB6BF2B95);
MS2_REPLACE_METHOD(0x1410d2340, CubeMapInformationService, ArePointsWithinRange2D, 156, 0xEEE5AF23);
MS2_REPLACE_METHOD(0x1410caa60, CubeMapInformationService, FUN_1410caa60, 157, 0xD35299AC);
MS2_REPLACE_METHOD(0x1410c8030, CubeMapInformationService, GetOwnerId, 146, 0xB5FEEB28);
MS2_REPLACE_METHOD(0x1410cba80, CubeMapInformationService, FUN_1410cba80, 173, 0x93E405C5);
MS2_REPLACE_METHOD(0x1410c5280, CubeMapInformationService, FUN_1410c5280, 181, 0x3432B4D0);
MS2_REPLACE_METHOD(0x1410c6070, CubeMapInformationService, DestroyFloorPhysX, 131, 0xB538D479);
MS2_REPLACE_METHOD(0x1410c6820, CubeMapInformationService, RemovePhysActor, 176, 0x44A9A5A7);
MS2_REPLACE_METHOD(0x1410c3020, CubeMapInformationService, FUN_1410c3020, 210, 0x33E82D80);
MS2_REPLACE_METHOD(0x1410ce560, CubeMapInformationService, FUN_1410ce560, 145, 0xA6305FF4);
MS2_REPLACE_METHOD(0x1410ce310, CubeMapInformationService, FUN_1410ce310, 212, 0xE2043451);
MS2_REPLACE_METHOD(0x1410d33a0, CubeMapInformationService, TryGetHouseMarkPosition, 160, 0x039024A4);
MS2_REPLACE_METHOD(0x1410d5b20, CubeMapInformationService, SendRequestCubeMode68, 153, 0xAA015FE8);
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
MS2_REPLACE_METHOD(0x1410c92e0, CubeMapInformationService, RemoveFunctionCubeObject, 218, 0x1A9BF0C4);
MS2_REPLACE_METHOD(0x1410d4680, CubeMapInformationService, FUN_1410d4680, 135, 0x19987D09);
MS2_REPLACE_METHOD(0x1410d43c0, CubeMapInformationService, FUN_1410d43c0, 135, 0x1EFD68B9);
MS2_REPLACE_METHOD(0x1410d59c0, CubeMapInformationService, FUN_1410d59c0, 224, 0x7EFB2116);
MS2_REPLACE_METHOD(0x1410b77e0, CubeMapInformationService, FUN_1410b77e0, 563, 0xFFCFF167);
MS2_REPLACE_METHOD(0x1410c2a90, CubeMapInformationService, FUN_1410c2a90, 583, 0x84A15AF6);
MS2_REPLACE_METHOD(0x1410c2ce0, CubeMapInformationService, FUN_1410c2ce0, 748, 0xFE7012D8);
MS2_REPLACE_METHOD(0x1410c3cd0, CubeMapInformationService, FUN_1410c3cd0, 290, 0x1F1F3F30);
MS2_REPLACE_METHOD(0x1410c8470, CubeMapInformationService, FUN_1410c8470, 257, 0xF30205C2);
MS2_REPLACE_METHOD(0x1410c80d0, CubeMapInformationService, IsGroupSalableAndUnowned, 231, 0xABEACB41);
MS2_REPLACE_METHOD(0x1410c8580, CubeMapInformationService, FUN_1410c8580, 223, 0x9BA56468);
MS2_REPLACE_METHOD(0x1410cb980, CubeMapInformationService, FUN_1410cb980, 245, 0x73C4ED69);
MS2_REPLACE_METHOD(0x1410d50c0, CubeMapInformationService, FUN_1410d50c0, 196, 0x522E19D8);
MS2_REPLACE_METHOD(0x1410d4fa0, CubeMapInformationService, FUN_1410d4fa0, 275, 0xAD5CD043);
MS2_REPLACE_METHOD(0x1410d5190, CubeMapInformationService, FUN_1410d5190, 433, 0xE5884B7A);
MS2_REPLACE_METHOD(0x1410d5350, CubeMapInformationService, SendRequestCubeMode31, 399, 0xC29D2273);
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

