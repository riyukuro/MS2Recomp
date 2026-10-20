// worldservice_real.h - the REAL container types of WorldService's template members, for the COMDAT-tail parts of
// worldservice.cpp (?\worldservice.cpp#5..#9). NOT an original header.
//
// worldservice.h declares the members with size-equal stand-ins (Unk_WsV<off>, u64 keys) that worldservice_1.cpp is written
// against. The exe's tail COMDATs, however, are instantiated over the real key/value types, and their bytes depend on them
// (std::less<egf::EntityID> calls EntityID::operator<, signed vs unsigned key compares, value dtors), and so does their
// order (the tail is sorted by mangled name). The tail parts therefore instantiate these types. Proofs (w529, 2026-10-20):
//   - node sizes of the tail's allocator<_Tree_node<..>>::deallocate group 0x141c2bba0..0x141c2bd80, in name order:
//     list<Entity*> 0x18, set<ptr> 0x28, int-keyed {MS2Ptr 0x38, set 0x38, SmartPointer 0x30}, EntityID-keyed
//     {SmartPointer x3 0x30, record 0x48, __int64 0x30}, __int64-keyed {MS2Ptr 0x38}: matches v2525 WorldService.h
//     (m_048..m_ad0) member for member, including the signed int key of m_ac0 (worldservice.h: unsigned);
//   - vector element sizes (0x10/0x10/0x18/0x10) from the vector deallocates 0x141c2bfc0..0x141c2c050.
// Use: `WsReal::Map1d8` etc. A member type proven here may replace the stand-in in worldservice.h once worldservice_1.cpp is
// ported to it (same size, so the layout does not change).
#pragma once

#include <list>
#include <map>
#include <set>
#include <vector>
#include <efd/SmartPointer.h>
#include <egf/EntityID.h>

#include "worldservice.h"
#include "alphaanimation.h"                            // CEntityShower / CEntityHider (NiRefObject)
#include "ms2actorupdater.h"
#include "ms2/placeholder/iworldservicecallback.h"

namespace egf { class Entity; }

namespace WsReal
{
// m_1d8 value: one tracked visible scene object (0x20 bytes; set construction 0x141beda30 allocates 0x20).
class VisibleObjectRecord
{
public:
    NiAVObject* object;                                 // +0x00
    int value8;                                         // +0x08
    egf::EntityID entityId;                             // +0x10
    int value18;                                        // +0x18
    bool operator<(const VisibleObjectRecord& o) const { return entityId < o.entityId; }   // 0x141bf98d0 (unit_141bf98d0)
};
MS2_CHECK_SIZE(VisibleObjectRecord, 0x20);

class Rec1f8 : public CPtred {};                        // m_1f8 values (held through MS2Ptr)
class Recad0 : public CPtred {};                        // m_ad0 values (held through MS2Ptr)
// The tail holds 7 MS2Ptr<T>::Release/ReleaseImpl pairs (0x141c28c80..0x141c28e00 / 0x141c28ee0..0x141c290c0, called by the
// ~MS2Ptr COMDATs 0x141bf5570..0x141bf5690) whose Reference<T> COMDATs are 0x141c1f620..0x141c1f6c0, except FieldProperty's
// (0x140b28640). In that order T = MS2ActorUpdater, Rec1f8, Recad0 (= m_aa0's pointee too: ~MS2Ptr 0x141bf55d0), m_a80's,
// FieldProperty, and two not yet identified (stand-ins below; 0x141bf5660 is used by the m_208 list holder, 0x141bf5690 by
// the m_708 values in FUN_141bd0220).
class RecPtrA : public CPtred {};
class RecPtrB : public CPtred {};

typedef std::set<IWorldServiceCallback*> Set048;                                         // +0x048
typedef std::list<egf::Entity*> List088;                                                 // +0x088, +0x098
typedef std::map<egf::EntityID, VisibleObjectRecord> Map1d8;                             // +0x1d8
typedef std::set<egf::EntityID> EntitySet;
typedef std::map<int, EntitySet> Map1e8;                                                 // +0x1e8
typedef std::map<int, MS2Ptr<Rec1f8> > Map1f8;                                           // +0x1f8
typedef std::map<egf::EntityID, efd::SmartPointer<egf::Entity> > Map2e8;                 // +0x2e8
typedef std::map<egf::EntityID, int> Map900;                                             // +0x900 (ctor 0x1413e86d0, other CU; empty() 0x141c2c0c0 here)
typedef std::map<egf::EntityID, efd::SmartPointer<CEntityShower> > Map980;               // +0x980
typedef std::map<egf::EntityID, efd::SmartPointer<CEntityHider> > Map990;                // +0x990
typedef std::vector<MS2Ptr<MS2ActorUpdater> > Vec9a0;                                    // +0x9a0
typedef std::vector<std::pair<CStringA, CStringW> > Veca00;                              // +0xa00
typedef std::vector<std::pair<CStringA, MS2Ptr<Unk_WsK_Rank> > > Veca18;                 // +0xa18
typedef std::vector<std::pair<CStringA, CStringA> > VecTextPair;                         // local of FUN_141bdb1b0 (ctor 0x141bf3300, dtor 0x141bf5ef0)
typedef std::map<egf::EntityID, __int64> Mapab0;                                         // +0xab0 (server-time deadline)
typedef std::map<int, efd::SmartPointer<egf::Entity> > Mapac0;                           // +0xac0
typedef std::map<__int64, MS2Ptr<Recad0> > Mapad0;                                       // +0xad0

MS2_CHECK_SIZE(Map1d8, 0x10);
MS2_CHECK_SIZE(Vec9a0, 0x18);
}
