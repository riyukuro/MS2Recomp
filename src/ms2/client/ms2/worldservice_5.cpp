// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService COMDAT tail, sub-unit #5 (owner ws3, w530).
// MS2-UNIT: ?\worldservice.cpp#5
// The rest of the old #5 range (0x141bf79d0-0x141bfe180) is covered by unit_141bf79d0 .. unit_141bf98d0 (done) and
// unit_141bf99b8 (0x141bf99b8-0x141c00000), so #5 keeps only the head of the sorted tail: ??4 / ??7 / ??8 / ??9 / ??A.
// MS2-RANGE: 0x141bf7060-0x141bf79d0 .text$mn
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_WsV9a0@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141bf7640 ; cf3: calls the empty _Compat 0x141c215b0 (vector iterator, not a tree iterator)
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_WsV9a0@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141bf7950 ; cf3: calls ??8 0x141bf7640
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\worldservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "gameobject.h"
#include <egf/EntityID.h>

// ---- 0x141bf7060-0x141bf7380: the ??4 / ??7 / ??8 COMDATs at the head of the CU's sorted COMDAT tail
// m_1e8's value is a std::set<egf::EntityID> (its _Tree::clear is 0x140a1da60, the m_838 set ctor 0x140a15e30):
// FUN_141bc7aa0 copies it with set::operator= (0x141bf70e0 -> _Tree::operator= 0x141bf7060).
// The m_1d8 value as the exe copies it (0x141bf7110: qword, dword, EntityID::operator=, dword).
struct Unk_Ws5TrackedNode
{
    void* m_sceneNode;
    int m_state;
    egf::EntityID m_entityId;
    int m_group;
};
// The m_1a8 value as the CRBMap SetAt helper 0x141c1b490 assigns it (0x141bf7180).
struct Unk_Ws5ObjectEntry
{
    efd::SmartPointer<GameObject> m_obj;
    egf::EntityID m_id;
};
class Unk_WsB_Vibrator;
class FieldProperty;
class Unk_Ws5UnitTag : public CPtred {};             // the MS2Ptr a unit's vfunc_82 returns (FUN_141bcabf0)
class Unk_Ws5TipObj : public CPtred {};              // the m_ad0 tooltip holder (FUN_141bdb6a0)
class Unk_Ws5RefA : public NiRefObject {};           // SmartPointer == targets (FUN_141bbd640, FUN_141bc0ff0)
class Unk_Ws5RefB : public NiRefObject {};
class Unk_Ws5RefC : public NiRefObject {};           // m_930 value pointer tested with != (FUN_141bd49d0)
class Unk_Ws5Obj;                                    // the CAtlArray element of FUN_141bd28d0
// Pointer operands are taken by reference so the TU emits only the compared operators (no smart-pointer ctor/dtor).
void Unk_Ws5Head(std::set<egf::EntityID>& a, const std::set<egf::EntityID>& b, Unk_Ws5TrackedNode& n,
    const Unk_Ws5TrackedNode& n2, Unk_Ws5ObjectEntry& e, const Unk_Ws5ObjectEntry& e2, const MS2Ptr<Unk_WsPtredaa0>& aa0,
    const efd::SmartPointer<Unk_Ws5RefA>& ra, const efd::SmartPointer<Unk_Ws5RefB>& rb,
    const efd::SmartPointer<Unk_Ws5RefC>& rc, const MS2Ptr<Unk_WsB_Vibrator>& p0, const MS2Ptr<Unk_WsPtreda80>& p1,
    const MS2Ptr<Unk_Ws5UnitTag>& p2, const MS2Ptr<FieldProperty>& p3, const MS2Ptr<Unk_Ws5TipObj>& p4,
    ATL::CAtlArray<Unk_Ws5Obj*>& arr)
{
    a = b;
    n = n2;
    e = e2;
    if (!aa0)
        ;
    if (ra == 0 || rb == 0 || rc != 0)
        ;
    if (p0 == 0 || p1 == 0 || p2 == 0 || p3 == 0 || p4 == 0)
        ;
    if (arr[0] == 0)
        ;
}

template <class M> void Unk_WsTouchTree(M& m, typename M::key_type k)
{
    typename M::iterator it = m.find(k);
    if (it != m.end())
        m.erase(it);
    for (typename M::iterator i = m.begin(); i != m.end(); ++i)
        ;
    for (typename M::iterator i = m.begin(); i != m.end(); i++)
        ;
    for (typename M::iterator i = m.end(); i != m.begin(); --i)
        ;
    for (typename M::const_iterator i = m.begin(); i != m.end(); ++i)
        ;
}
struct Unk_WsT0 { unsigned char raw[16]; };
struct Unk_WsT2 { void* raw; };
struct Unk_WsT3 { void* raw; };
struct Unk_WsT4 { void* raw; };
struct Unk_WsT5 { void* raw; };
struct Unk_WsT6 { unsigned char raw[32]; };
struct Unk_WsT7 { void* raw; };
void Unk_WsAnchor()
{
    std::map<int, Unk_WsT0> m0; Unk_WsTouchTree(m0, 0);
    std::map<int, std::set<unsigned __int64> > m1; Unk_WsTouchTree(m1, 0);
    std::map<unsigned, Unk_WsT2> m2; Unk_WsTouchTree(m2, 0);
    std::map<unsigned __int64, Unk_WsT3> m3; Unk_WsTouchTree(m3, 0);
    std::map<unsigned __int64, Unk_WsT4> m4; Unk_WsTouchTree(m4, 0);
    std::map<unsigned __int64, Unk_WsT5> m5; Unk_WsTouchTree(m5, 0);
    std::map<unsigned __int64, Unk_WsT6> m6; Unk_WsTouchTree(m6, 0);
    std::map<unsigned __int64, Unk_WsT7> m7; Unk_WsTouchTree(m7, 0);
    std::map<unsigned __int64, MS2Ptr<Unk_WsPtred> > m8; Unk_WsTouchTree(m8, 0);
    std::set<void*> m9; Unk_WsTouchTree(m9, 0);
    // m_9a0's const_iterator ==/!= (0x141bf7640 / 0x141bf7950; == calls the empty _Compat 0x141c215b0). Without these
    // the set<unsigned __int64> tree-iterator ??9 above paired with 0x141bf7950 by masked bytes (cf3, 2026-10-17).
    std::vector<Unk_WsV9a0> v9a0;
    std::vector<Unk_WsV9a0>::const_iterator a = v9a0.begin(), b = v9a0.end();
    if (a == b || a != b)
        ;
}
