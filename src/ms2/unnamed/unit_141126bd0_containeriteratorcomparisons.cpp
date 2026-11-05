// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A zone of STL/ATL COMDATs: 25 pointer-wrapper iterator
// comparison pairs, the std::string / std::wstring const_iterator comparisons, a 3-int key comparison, a CAtlArray indexer
// and a map lookup. The iterator types are the std::map/std::set const_iterators the callers compare (one stand-in left, Unk_Iter<2>).
// MS2-UNIT: unit_141126bd0
// MS2-RANGE: 0x141126bd0-0x141127a90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??8?$Unk_Int3@$0A@@@QEBA_NAEBV0@@Z 0x1411272b0 ; unique
// MS2-PIN: ??9?$Unk_Int3@$0A@@@QEBA_NAEBV0@@Z 0x1411279c0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <string>
#include <map>
#include <set>
#include <atlcoll.h>
#include <efd/StdContainers.h>
#include <efd/SmartPointer.h>
#include <egf/EntityID.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The value types behind the std::map/std::set const_iterator comparisons. The != body's operator== lookup completes each
// node pair, so the value types are complete: the cube map records as size-only views (real layouts in
// cubemapinformationservice_tail.h, which can't be included next to this unit's Unk_Int3<N> template), the pointees of the
// MS2Ptr / SmartPointer values incomplete. The == / != pair of each tree type sits 0x730 apart, the != calling its ==.
struct Unk_CMISMarkRec { char m_pad[0x50]; };       // node value of CubeMapInformationService::f288
struct Unk_CMISCell { char m_pad[0x38]; };          // node value of f2b8
struct Unk_CMISCubeTimer { char m_pad[0x48]; };     // node value of f1f8
namespace egfPhysX { class EntityActorData; }        // node value of f58: efd::SmartPointer<egfPhysX::EntityActorData>
enum Unk_CMISKindA : int;
class Cube;
class FittingDollData;
class SalesInfo;
class SetItemEffectInfo;
class UICubeUGCHead;
class SaleStateData;
class AutomaticCreateCubeInfo;
class CFunctionCubeObject;
namespace egf { class Entity; }

// Unit-local iterator stand-in for the std::map<int, Unk_Int3> const_iterator pair (0x141126c10 / 0x141127340): its value type,
// the global struct Unk_Int3, cannot be named here next to this unit's Unk_Int3<N> key template.
template <int N>
class Unk_Iter
{
public:
    bool operator==(const Unk_Iter& r) const { return (m_ptr == r.m_ptr); }
    bool operator!=(const Unk_Iter& r) const { return (!(*this == r)); }
    void* m_ptr;
};

template class Unk_Iter<2>;

// The std::_Tree_const_iterator comparisons. int vs long (0x141126c90) and unsigned vs unsigned long (0x141126f90) keys give
// byte-identical bodies; the int / unsigned copies are kept, as the != rows name them. 0x141127050 / 0x141127780 are the
// EntityID -> __int64 map (CubeMapInformationService::f48), 0x141127090 / 0x1411277c0 the EntityID -> Unk_CMISPropPtr one (f58).
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126e50
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127580
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, std::map<int, MS2Ptr<Cube> > > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, std::map<int, MS2Ptr<Cube> > > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, std::map<int, MS2Ptr<Cube> > > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, std::map<int, MS2Ptr<Cube> > > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126bd0
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127300
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISMarkRec> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISMarkRec> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISMarkRec> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISMarkRec> > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCell@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126c50
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCell@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127380
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISCell> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISCell> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISCell> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISCell> > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126c90
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1411273c0
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::SmartPointer<egf::Entity> > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::SmartPointer<egf::Entity> > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::SmartPointer<egf::Entity> > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::SmartPointer<egf::Entity> > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126cd0
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127400
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<FittingDollData> > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<FittingDollData> > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<FittingDollData> > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<FittingDollData> > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126d10
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127440
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<SalesInfo> > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<SalesInfo> > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<SalesInfo> > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<SalesInfo> > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126d50
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127480
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<SetItemEffectInfo> > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<SetItemEffectInfo> > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<SetItemEffectInfo> > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<SetItemEffectInfo> > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126d90
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1411274c0
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<Cube> > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<Cube> > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<Cube> > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<Cube> > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126dd0
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127500
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<UICubeUGCHead> > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<UICubeUGCHead> > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<UICubeUGCHead> > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, MS2Ptr<UICubeUGCHead> > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126e10
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127540
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, std::map<unsigned int, std::set<int> > > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, std::map<unsigned int, std::set<int> > > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, std::map<unsigned int, std::set<int> > > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, std::map<unsigned int, std::set<int> > > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1411270d0
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127800
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, MS2Ptr<Cube> > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, MS2Ptr<Cube> > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, MS2Ptr<Cube> > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, MS2Ptr<Cube> > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127110
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127840
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const Unk_CMISKindA, int> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const Unk_CMISKindA, int> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const Unk_CMISKindA, int> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const Unk_CMISKindA, int> > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127150
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127880
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int, int> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int, int> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int, int> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<int, int> > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127190
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1411278c0
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<MS2Ptr<AutomaticCreateCubeInfo> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<MS2Ptr<AutomaticCreateCubeInfo> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<MS2Ptr<AutomaticCreateCubeInfo> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<MS2Ptr<AutomaticCreateCubeInfo> > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1411271d0
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127900
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<MS2Ptr<CFunctionCubeObject> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<MS2Ptr<CFunctionCubeObject> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<MS2Ptr<CFunctionCubeObject> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<MS2Ptr<CFunctionCubeObject> > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126e90
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1411275c0
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::set<int> > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::set<int> > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::set<int> > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::set<int> > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126ed0
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127600
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::vector<efd::SmartPointer<egf::Entity> > > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::vector<efd::SmartPointer<egf::Entity> > > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::vector<efd::SmartPointer<egf::Entity> > > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, efd::vector<efd::SmartPointer<egf::Entity> > > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126f10
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127640
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, egf::EntityID> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, egf::EntityID> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, egf::EntityID> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, egf::EntityID> > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126f50
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127680
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISCubeTimer> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISCubeTimer> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISCubeTimer> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const int, Unk_CMISCubeTimer> > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126f90
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1411276c0
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const unsigned int, std::set<int> > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const unsigned int, std::set<int> > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const unsigned int, std::set<int> > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const unsigned int, std::set<int> > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141126fd0
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127700
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const std::pair<int, int>, MS2Ptr<SaleStateData> > > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const std::pair<int, int>, MS2Ptr<SaleStateData> > > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const std::pair<int, int>, MS2Ptr<SaleStateData> > > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const std::pair<int, int>, MS2Ptr<SaleStateData> > > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127010
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127740
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char> > >, int> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char> > >, int> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char> > >, int> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char> > >, int> > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127050
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127780
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, __int64> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, __int64> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, __int64> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, __int64> > > >&) const;
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127090
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$SmartPointer@VEntityActorData@egfPhysX@@@efd@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1411277c0
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, efd::SmartPointer<egfPhysX::EntityActorData>> > > >::operator==(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, efd::SmartPointer<egfPhysX::EntityActorData>> > > >&) const;
template bool std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, efd::SmartPointer<egfPhysX::EntityActorData>> > > >::operator!=(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const egf::EntityID, efd::SmartPointer<egfPhysX::EntityActorData>> > > >&) const;

// std::wstring::const_iterator comparisons (each calls its own empty _Compat). The char (std::string) pair here is a byte-identical
// look-alike of filesystem.cpp's real std::string iterator copy (0x1403a7800 / 0x1403a79a0), so it is a unit-local stand-in.
// Unk_StdCharIter<0>: 0x141127210 (==), 0x141127940 (!=); _Compat 0x141134f50.
template <int N>
class Unk_StdCharIter
{
public:
    void _Compat(const Unk_StdCharIter&) const {}
    bool operator==(const Unk_StdCharIter& r) const { _Compat(r); return (m_ptr == r.m_ptr); }
    bool operator!=(const Unk_StdCharIter& r) const { return (!(*this == r)); }
    const char* m_ptr;
};
// MS2-PIN: ??8?$_String_const_iterator@V?$_String_val@U?$_Simple_types@_W@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127260
// MS2-PIN: ??9?$_String_const_iterator@V?$_String_val@U?$_Simple_types@_W@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127980
// MS2-PIN: ??8?$Unk_StdCharIter@$0A@@@QEBA_NAEBV0@@Z 0x141127210
// MS2-PIN: ??9?$Unk_StdCharIter@$0A@@@QEBA_NAEBV0@@Z 0x141127940
template bool Unk_StdCharIter<0>::operator==(const Unk_StdCharIter<0>&) const;
template bool std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >::operator==(const std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >&) const;
template bool Unk_StdCharIter<0>::operator!=(const Unk_StdCharIter<0>&) const;
template bool std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >::operator!=(const std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >&) const;

// A 12-byte key of three ints compared member-wise.
template <int N>
class Unk_Int3
{
public:
    bool operator==(const Unk_Int3& r) const
    {
        if (r.m_a == m_a && r.m_b == m_b && r.m_c == m_c)
            return true;
        return false;
    }
    bool operator!=(const Unk_Int3& r) const
    {
        if (r.m_a != m_a || r.m_b != m_b || r.m_c != m_c)
            return true;
        return false;
    }
    int m_a;
    int m_b;
    int m_c;
};

template class Unk_Int3<0>;
MS2_CHECK_SIZE(Unk_Int3<0>, 0xc);

// A 16-byte array element (two pointers).
struct Unk_Elem16
{
    void* m_p0;
    void* m_p1;
};

// CAtlArray<Unk_Elem16>::operator[]: bounds-checked (AtlThrow(E_INVALIDARG)).
// MS2-PIN: ??A?$CAtlArray@UUnk_Elem16@@V?$CElementTraits@UUnk_Elem16@@@ATL@@@ATL@@QEAAAEAUUnk_Elem16@@_K@Z 0x141127a10
template Unk_Elem16& ATL::CAtlArray<Unk_Elem16, ATL::CElementTraits<Unk_Elem16> >::operator[](size_t) throw();

// efd::map<long,int>::operator[] (= try_emplace(key).first->second), keyed by the cube position hash (key type long: the exe has distinct operator-> copies per 32-bit key type; int/unsigned/unsigned long are taken by other units).
// MS2-PIN: ??A?$map@JHU?$less@J@std@@V?$CustomAllocator@U?$pair@$$CBJH@std@@@efd@@@std@@QEAAAEAHAEBJ@Z 0x141127a50
template int& std::map<long, int, std::less<long>, efd::CustomAllocator<std::pair<const long, int> > >::operator[](const long&);
