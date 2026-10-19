// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Default-constructor glue of the CubeMapInformationService
// container members and a few small types of the same slice: the 38 map families' constructor wrappers (efd::map ctor ->
// std::map ctor, or the std::map ctor itself), the std::vector / _Vector_val / iterator / allocator constructors of
// the EntityID, SmartPointer<Entity> and NiTransform vectors, tuple move constructors, pair copy constructors, and the
// record constructors (SalesInfo, SaleStateData, AutomaticCreateCubeInfo, cell/timer/notify structs).
// The family value types are the stand-ins of unit_14111eb90 (the _Tree constructors live there).
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_141121cf0
// MS2-RANGE: 0x141121cf0-0x141123340 .text$mn
// MS2-PIN: ??_7Unk_CMISNotifyBuilding@@6B@ 0x142eb3a28 ; hand: anchor vftable
// MS2-PIN: ??_7Unk_CMISAnchorMH@@6B@ 0x142eb3730 ; hand: anchor vftable
// MS2-PIN: ??_7Unk_CMISAnchorSvc@@6B@ 0x142eb3698 ; hand: anchor vftable
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@QEAA@XZ 0x141121db0 ; unique
// MS2-PIN: ??0?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@QEAA@XZ 0x141122040 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAAB@@@QEAA@XZ 0x141122050 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBN@@@QEAA@XZ 0x1411220a0 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBD@@@QEAA@XZ 0x1411220f0 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBG@@@QEAA@XZ 0x141122170 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAI@@@QEAA@XZ 0x1411221c0 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAK@@@QEAA@XZ 0x141122210 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBC@@@QEAA@XZ 0x141122260 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBH@@@QEAA@XZ 0x141122290 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAE@@@QEAA@XZ 0x1411222e0 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBB@@@QEAA@XZ 0x141122330 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAM@@@QEAA@XZ 0x141122360 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBL@@@QEAA@XZ 0x141122390 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAF@@@QEAA@XZ 0x1411223c0 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAG@@@QEAA@XZ 0x141122410 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAP@@@QEAA@XZ 0x141122460 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAJ@@@QEAA@XZ 0x1411224b0 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBA@@@QEAA@XZ 0x141122500 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBE@@@QEAA@XZ 0x141122550 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BABE@@@QEAA@XZ 0x1411225a0 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAH@@@QEAA@XZ 0x141122620 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAO@@@QEAA@XZ 0x141122670 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAB@@@QEAA@XZ 0x1411226c0 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAC@@@QEAA@XZ 0x141122710 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAD@@@QEAA@XZ 0x141122760 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBK@@@QEAA@XZ 0x1411227b0 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBJ@@@QEAA@XZ 0x141122830 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBI@@@QEAA@XZ 0x141122880 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBP@@@QEAA@XZ 0x1411228d0 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAN@@@QEAA@XZ 0x141122920 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAL@@@QEAA@XZ 0x1411229d0 ; prop
// MS2-PIN: ??0?$map@IU?$Unk_MC@$0N@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0N@@@@std@@@@@std@@QEAA@XZ 0x141122a90 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAAO@@@QEAA@XZ 0x141122af0 ; prop
// MS2-PIN: ??0?$map@IU?$Unk_MC@$0O@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0O@@@@std@@@@@std@@QEAA@XZ 0x141122b10 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BBM@@@QEAA@XZ 0x141122b40 ; prop
// MS2-PIN: ??0?$Unk_CMISTree@$0BAA@@@QEAA@XZ 0x141122b70 ; prop
// MS2-PIN: ??0?$map@IU?$Unk_MC@$0P@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0P@@@@std@@@@@std@@QEAA@XZ 0x141122b90 ; prop
// MS2-PIN: ??0?$tuple@$$QEAW4Unk_CMISKindB@@@std@@QEAA@$$QEAV01@@Z 0x141122bc0 ; prop
// MS2-PIN: ??0?$tuple@AEBVEntityID@egf@@@std@@QEAA@$$QEAV01@@Z 0x141122c00 ; prop
// MS2-PIN: ??0?$tuple@AEBW4Unk_CMISKindA@@@std@@QEAA@$$QEAV01@@Z 0x141122c40 ; prop
// MS2-PIN: ??0Unk_CMISKeySet@@QEAA@XZ 0x141122d00 ; prop
// MS2-PIN: ??0?$vector@HV?$CustomAllocator@H@efd@@@std@@QEAA@XZ 0x141122d20 ; prop
// MS2-PIN: ??0Unk_CMISAnchorStdEntVec@@QEAA@XZ 0x141122da0 ; prop
// MS2-PIN: ??0Unk_CMISXformVec@@QEAA@XZ 0x141122df0 ; prop
// MS2-PIN: ??0?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@QEAA@XZ 0x141122e40 ; prop
// MS2-PIN: ??0Category@efd@@QEAA@W4ExpectedChannelUsage@UniversalID@1@II@Z 0x141122f90 ; unique
// MS2-PIN: ??0Unk_CMISDeadString@@QEAA@XZ 0x141123030 ; unique
// MS2-PIN: ??0EntityChangeMessage@egf@@QEAA@XZ 0x141123110 ; unique
// MS2-PIN: ??0ISystemService@efd@@QEAA@XZ 0x1411231e0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <set>
#include <vector>
#include <tuple>
#include <new>
#include <efd/StdContainers.h>
#include <egf/EntityID.h>
#include <egf/Entity.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#ifndef MS2_HOOK_DLL
// ---- map families -------------------------------------------------------------------------------------------------------
// The CMIS member trees are Unk_CMISTree<N> stand-ins in cubemapinformationservice_3.h. Their constructor wrappers are
// specialised here, before that header is pulled in, over the same stand-in element types as unit_14111eb90 (the hook DLL
// keeps the exe's wrappers through the symbol rows, the local ones would allocate from the DLL heap).
template <int N> struct Unk_MC { int v[N + 1]; };
template <class T>
struct Unk_McAlloc
{
    typedef T value_type;
    template <class U> struct rebind { typedef Unk_McAlloc<U> other; };
    Unk_McAlloc() {}
    template <class U> Unk_McAlloc(const Unk_McAlloc<U>&) {}
    ~Unk_McAlloc() {}
    T* allocate(size_t n) { return (T*)::operator new(n * sizeof(T)); }
    void deallocate(T* p, size_t) { ::operator delete(p); }
};
template <int N> using Unk_McC = std::map<unsigned, Unk_MC<N>, std::less<unsigned>, Unk_McAlloc<std::pair<const unsigned, Unk_MC<N> > > >;
template <int N> using Unk_McS = std::map<unsigned, Unk_MC<N> >;

template <unsigned __int64 N> struct Unk_CMISTree;
template <> struct Unk_CMISTree<4097> : Unk_McC<1> { Unk_CMISTree() {} };     // unnamed family, wrapper 0x141122050 -> map ctor 0x141122070
template <> struct Unk_CMISTree<285> : Unk_McC<2> { Unk_CMISTree() {} };     // 0x1411220a0 -> map ctor 0x1411220c0
template <> struct Unk_CMISTree<275> : Unk_McC<3> { Unk_CMISTree() {} };     // 0x1411220f0 -> map ctor 0x141122110
template <> struct Unk_CMISTree<278> : Unk_McC<4> { Unk_CMISTree() {} };     // 0x141122170 -> map ctor 0x141122190
template <> struct Unk_CMISTree<264> : Unk_McC<5> { Unk_CMISTree() {} };     // 0x1411221c0 -> map ctor 0x1411221e0
template <> struct Unk_CMISTree<266> : Unk_McC<6> { Unk_CMISTree() {} };     // 0x141122210 -> map ctor 0x141122230
template <> struct Unk_CMISTree<279> : Unk_McC<7> { Unk_CMISTree() {} };     // 0x141122290 -> map ctor 0x1411222b0
template <> struct Unk_CMISTree<260> : Unk_McC<8> { Unk_CMISTree() {} };     // 0x1411222e0 -> map ctor 0x141122300
template <> struct Unk_CMISTree<261> : Unk_McC<9> { Unk_CMISTree() {} };     // 0x1411223c0 -> map ctor 0x1411223e0
template <> struct Unk_CMISTree<262> : Unk_McC<10> { Unk_CMISTree() {} };     // 0x141122410 -> map ctor 0x141122430
template <> struct Unk_CMISTree<287> : Unk_McC<11> { Unk_CMISTree() {} };     // 0x1411228d0 -> map ctor 0x1411228f0
template <> struct Unk_CMISTree<267> : Unk_McC<12> { Unk_CMISTree() {} };     // 0x1411229d0 -> map ctor 0x1411229f0
template <> struct Unk_CMISTree<4109> : Unk_McC<13> { Unk_CMISTree() {} };     // unnamed family, wrapper 0x141122a70 -> map ctor 0x141122a90
template <> struct Unk_CMISTree<4110> : Unk_McC<14> { Unk_CMISTree() {} };     // unnamed family, wrapper 0x141122af0 -> map ctor 0x141122b10
template <> struct Unk_CMISTree<256> : Unk_McC<15> { Unk_CMISTree() {} };     // 0x141122b70 -> map ctor 0x141122b90
template <> struct Unk_CMISTree<271> : Unk_McC<16> { Unk_CMISTree() {} };     // 0x141122460 -> map ctor 0x141122480
template <> struct Unk_CMISTree<265> : Unk_McC<17> { Unk_CMISTree() {} };     // 0x1411224b0 -> map ctor 0x1411224d0
template <> struct Unk_CMISTree<272> : Unk_McC<18> { Unk_CMISTree() {} };     // 0x141122500 -> map ctor 0x141122520
template <> struct Unk_CMISTree<276> : Unk_McC<19> { Unk_CMISTree() {} };     // 0x141122550 -> map ctor 0x141122570
template <> struct Unk_CMISTree<4116> : Unk_McC<20> { Unk_CMISTree() {} };     // unnamed family, wrapper 0x1411225a0 -> map ctor 0x1411225c0
template <> struct Unk_CMISTree<263> : Unk_McC<21> { Unk_CMISTree() {} };     // 0x141122620 -> map ctor 0x141122640
template <> struct Unk_CMISTree<270> : Unk_McC<22> { Unk_CMISTree() {} };     // 0x141122670 -> map ctor 0x141122690
template <> struct Unk_CMISTree<257> : Unk_McC<23> { Unk_CMISTree() {} };     // 0x1411226c0 -> map ctor 0x1411226e0
template <> struct Unk_CMISTree<258> : Unk_McC<24> { Unk_CMISTree() {} };     // 0x141122710 -> map ctor 0x141122730
template <> struct Unk_CMISTree<259> : Unk_McC<25> { Unk_CMISTree() {} };     // 0x141122760 -> map ctor 0x141122780
template <> struct Unk_CMISTree<282> : Unk_McC<26> { Unk_CMISTree() {} };     // 0x1411227b0 -> map ctor 0x1411227d0
template <> struct Unk_CMISTree<281> : Unk_McC<27> { Unk_CMISTree() {} };     // 0x141122830 -> map ctor 0x141122850
template <> struct Unk_CMISTree<280> : Unk_McC<28> { Unk_CMISTree() {} };     // 0x141122880 -> map ctor 0x1411228a0
struct Unk_CMISAnchorS29 : Unk_McS<29> { Unk_CMISAnchorS29() {} };     // std::map ctor 0x141122140
template <> struct Unk_CMISTree<274> : Unk_McS<30>::_Mybase { Unk_CMISTree() : Unk_McS<30>::_Mybase(std::less<unsigned>()) {} };     // 0x141122260
template <> struct Unk_CMISTree<273> : Unk_McS<31>::_Mybase { Unk_CMISTree() : Unk_McS<31>::_Mybase(std::less<unsigned>()) {} };     // 0x141122330
template <> struct Unk_CMISTree<268> : Unk_McS<32>::_Mybase { Unk_CMISTree() : Unk_McS<32>::_Mybase(std::less<unsigned>()) {} };     // 0x141122360
template <> struct Unk_CMISTree<283> : Unk_McS<33>::_Mybase { Unk_CMISTree() : Unk_McS<33>::_Mybase(std::less<unsigned>()) {} };     // 0x141122390
struct Unk_CMISAnchorS34 : Unk_McS<34> { Unk_CMISAnchorS34() {} };     // std::map ctor 0x1411225f0
struct Unk_CMISAnchorS35 : Unk_McS<35> { Unk_CMISAnchorS35() {} };     // std::map ctor 0x141122800
template <> struct Unk_CMISTree<269> : Unk_McS<36>::_Mybase { Unk_CMISTree() : Unk_McS<36>::_Mybase(std::less<unsigned>()) {} };     // 0x141122920
struct Unk_CMISAnchorS37 : Unk_McS<37> { Unk_CMISAnchorS37() {} };     // std::map ctor 0x141122ac0
template <> struct Unk_CMISTree<284> : Unk_McS<38>::_Mybase { Unk_CMISTree() : Unk_McS<38>::_Mybase(std::less<unsigned>()) {} };     // 0x141122b40
// BBF (277) sits on the unnamed k=1 wrapper; BPA (496) is a vector of entity ids
template <> struct Unk_CMISTree<277> : Unk_CMISTree<4097> { Unk_CMISTree() {} };
template <> struct Unk_CMISTree<496> : std::vector<egf::EntityPtr, efd::CustomAllocator<egf::EntityPtr> > { Unk_CMISTree() {} };
#endif

#include "ms2/client/ms2/cubemapinformationservice_tail.h"

#include <NiTransform.h>
#include <efd/Category.h>
#include <efd/ISystemService.h>
#include <efd/MessageHandlerBase.h>
#include <egf/EntityChangeMessage.h>
#include "ms2/placeholder/meshinstancing.h"
#include "ms2/commonfiles/timer.h"

// ---- small record types -------------------------------------------------------------------------------------------------
extern Unk_CMISEntityRef DAT_143acf820;                      // the null entity ref

// @0x141122f30
// The mark record of tail.h (Timer + id vector) as the exe builds it: the vector holds entity pointers and the ctor resets
// the timer and clears the list.
struct Unk_CMISMarkRecInit
{
    Unk_CMISMarkRecInit() { m_timer.FUN_1408687f0(); m_marks.clear(); }
    Timer m_timer;
    efd::vector<egf::EntityPtr> m_marks;
};
MS2_CHECK_SIZE(Unk_CMISMarkRecInit, 0x50);

// @0x141123160
Unk_CMISCubeTimer::Unk_CMISCubeTimer()
{
    m_timer.FUN_1408687f0();
    m_bFlagA = false;
    m_bFlagB = false;
    m_id = reinterpret_cast<const egf::EntityID&>(DAT_143acf820);
}

void FUN_1408a8700(void* pStr);                          // efd::utf8string()
void FUN_1408a8900(void* pStr);                          // ~efd::utf8string
struct Unk_CMISDeadString
{
    Unk_CMISDeadString() { FUN_1408a8700(m_buf); }
    ~Unk_CMISDeadString() { FUN_1408a8900(m_buf); }
    char m_buf[0x20];
};

// @0x1411230b0 (the 56-byte cell value of the cell tree, tail.h's Unk_CMISCell with the exe's member types)
struct Unk_CMISCellInit
{
    Unk_CMISCellInit() : m_scale(0.0f, 0.0f, 0.0f) {}
    Unk_CMISDeadString m_name;
    Unk_InstancingScale m_scale;
    efd::Point3 m_pos;
};
MS2_CHECK_SIZE(Unk_CMISCellInit, 0x38);

// @0x141123050
struct Unk_CMISCell56
{
    Unk_CMISCell56(const Unk_CMISCell56& o) : m_name(o.m_name), m_scale(o.m_scale), m_pos(o.m_pos) {}
    efd::utf8string m_name;
    Unk_InstancingScale m_scale;
    efd::Point3 m_pos;
};
MS2_CHECK_SIZE(Unk_CMISCell56, 0x38);

// @0x141122990 (the set element of tail11: {int; MS2Ptr} with an out-of-line copy ctor)
struct Unk_CMISIdPtr
{
    int m_id;
    MS2Ptr<Cube> m_p;
    Unk_CMISIdPtr(const Unk_CMISIdPtr& o) : m_id(o.m_id), m_p(o.m_p) {}
};

struct Unk_CMISPawn;
// @0x141123230
struct Unk_CMISByDistance
{
    Unk_CMISByDistance(Unk_CMISPawn* pPawn) { m_pPawn = pPawn; }
    Unk_CMISPawn* m_pPawn;
};

class NotifyObject
{
public:
    NotifyObject();                                          // 0x140939070
    virtual ~NotifyObject();
    char m_pad[0x10];
};
// @0x141123250
class Unk_CMISNotifyBuilding : public NotifyObject
{
public:
    Unk_CMISNotifyBuilding(const int* pnBuilding) : m_nBuilding(*pnBuilding) {}
    virtual ~Unk_CMISNotifyBuilding();
    int m_nBuilding;                                         // +0x18
};

// @0x141122e70
AutomaticCreateCubeInfo::AutomaticCreateCubeInfo()
    : m_nId(0), m_cell(0, 0, 0), m_fAngle(0.0f), m_nFlag(0)
{
    m_arr.FUN_1401c0580();
}

// @0x141123290
SaleStateData::SaleStateData() : m_nState(0), m_p(0) {}

// @0x1411232e0
SalesInfo::SalesInfo() {}

#ifndef MS2_HOOK_DLL
// ---- vectors named by their constructor wrappers ----------------------------------------------------------------------------
struct Unk_CMISKeySet : std::vector<int, efd::CustomAllocator<int> > { Unk_CMISKeySet() {} };                        // 0x141122d00
struct Unk_CMISXformVec : std::vector<NiTransform, efd::CustomAllocator<NiTransform> > { Unk_CMISXformVec() {} };    // 0x141122df0
struct Unk_CMISAnchorStdEntVec : std::vector<egf::EntityID, efd::CustomAllocator<egf::EntityID> > { Unk_CMISAnchorStdEntVec() {} };                       // 0x141122e40

struct Unk_CMISAnchorMH : efd::BaseMessageHandler
{
    Unk_CMISAnchorMH() {}
    virtual void HandleMessage(efd::IBase*, const efd::IMessage*, efd::Category) {}
    virtual void RegisterMessageFactory(efd::MessageFactory*) {}
};                                                                                                                   // 0x141122f10
class Unk_CMISAnchorSvc : public efd::ISystemService
{
    EE_DECLARE_CLASS1(Unk_CMISAnchorSvc, 0x06100fff, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    Unk_CMISAnchorSvc() {}
    virtual const char* GetDisplayName() const { return ""; }
};                                                                                                                   // 0x1411231e0

typedef std::pair<const unsigned, std::set<int> > Unk_CMISBucketPair;

void Unk_CMISTreeAnchor(void* p)
{
    new (p) Unk_CMISTree<4097>;
    new (p) Unk_CMISTree<285>;
    new (p) Unk_CMISTree<275>;
    new (p) Unk_CMISTree<278>;
    new (p) Unk_CMISTree<264>;
    new (p) Unk_CMISTree<266>;
    new (p) Unk_CMISTree<279>;
    new (p) Unk_CMISTree<260>;
    new (p) Unk_CMISTree<261>;
    new (p) Unk_CMISTree<262>;
    new (p) Unk_CMISTree<287>;
    new (p) Unk_CMISTree<267>;
    new (p) Unk_CMISTree<4109>;
    new (p) Unk_CMISTree<4110>;
    new (p) Unk_CMISTree<256>;
    new (p) Unk_CMISTree<271>;
    new (p) Unk_CMISTree<265>;
    new (p) Unk_CMISTree<272>;
    new (p) Unk_CMISTree<276>;
    new (p) Unk_CMISTree<4116>;
    new (p) Unk_CMISTree<263>;
    new (p) Unk_CMISTree<270>;
    new (p) Unk_CMISTree<257>;
    new (p) Unk_CMISTree<258>;
    new (p) Unk_CMISTree<259>;
    new (p) Unk_CMISTree<282>;
    new (p) Unk_CMISTree<281>;
    new (p) Unk_CMISTree<280>;
    new (p) Unk_CMISAnchorS29;
    new (p) Unk_CMISTree<274>;
    new (p) Unk_CMISTree<273>;
    new (p) Unk_CMISTree<268>;
    new (p) Unk_CMISTree<283>;
    new (p) Unk_CMISAnchorS34;
    new (p) Unk_CMISAnchorS35;
    new (p) Unk_CMISTree<269>;
    new (p) Unk_CMISAnchorS37;
    new (p) Unk_CMISTree<284>;
    new (p) Unk_CMISKeySet;
    new (p) Unk_CMISXformVec;
    new (p) Unk_CMISAnchorStdEntVec;
    new (p) std::vector<egf::EntityPtr>;
    new (p) Unk_CMISAnchorMH;
    new (p) Unk_CMISAnchorSvc;
    new (p) Unk_CMISMarkRecInit;
    new (p) Unk_CMISCellInit;
    new (p) Unk_CMISCell56(*(const Unk_CMISCell56*)p);
    new (p) Unk_CMISIdPtr(*(const Unk_CMISIdPtr*)p);
    new (p) Unk_CMISByDistance(0);
    new (p) Unk_CMISNotifyBuilding((const int*)p);
    new (p) egf::EntityChangeMessage;
    new (p) efd::Category(efd::UniversalID::ECU_Any, 1, 2);
    new (p) Unk_CMISBucketPair(*(const Unk_CMISBucketPair*)p);
    new (p) std::tuple<Unk_CMISKindB&&>(std::move(*(std::tuple<Unk_CMISKindB&&>*)p));
    new (p) std::tuple<const egf::EntityID&>(std::move(*(std::tuple<const egf::EntityID&>*)p));
    new (p) std::tuple<const Unk_CMISKindA&>(std::move(*(std::tuple<const Unk_CMISKindA&>*)p));
    new (p) std::tuple<const int&>(std::move(*(std::tuple<const int&>*)p));
    new (p) std::tuple<const __int64&>(std::move(*(std::tuple<const __int64&>*)p));
    new (p) std::_Vector_iterator<std::_Vector_val<std::_Simple_types<egf::EntityID> > >((egf::EntityID*)0, (const std::_Container_base0*)0);
    new (p) std::_Vector_iterator<std::_Vector_val<std::_Simple_types<egf::EntityPtr> > >((egf::EntityPtr*)0, (const std::_Container_base0*)0);
    new (p) std::_Vector_val<std::_Simple_types<egf::EntityID> >;
    new (p) std::_Vector_val<std::_Simple_types<NiTransform> >;
    new (p) std::_Vector_val<std::_Simple_types<egf::EntityPtr> >;
}
#endif
