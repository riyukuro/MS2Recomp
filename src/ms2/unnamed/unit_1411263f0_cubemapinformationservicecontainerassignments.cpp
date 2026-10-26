// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A zone of STL COMDATs: the copy assignments of the
// CubeMapInformationService containers (`f440[key] = bucket`, `bucket[setId] = cubes`, `f498 = found`, `fc8[house] = {}`,
// `fd8[key] = {}` in cubemapinformationservice_3.cpp): five std::_Tree::operator=(const _Tree&) and their map/set
// wrappers. The efd::map<int, MS2Ptr<Cube>> / efd::set<int> values assign through two levels (the efd wrapper's implicit
// operator= -> std::map/set::operator= -> _Tree::operator=).
// MS2-UNIT: unit_1411263f0
// MS2-RANGE: 0x1411263f0-0x1411267c0 .text$mn
// MS2-PIN: ??4?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x141126470
// MS2-PIN: ??4?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$CustomAllocator@H@efd@@$0A@@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x1411264f0
// MS2-PIN: ??4?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VCFunctionCubeObject@@@@U?$less@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@V?$allocator@V?$MS2Ptr@VCFunctionCubeObject@@@@@3@$0A@@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x1411265f0
// MS2-PIN: ??4?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x1411263f0
// MS2-PIN: ??4?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@QEAAAEAV01@AEBV01@@Z 0x141126670
// MS2-PIN: ??4?$set@HU?$less@H@std@@@efd@@QEAAAEAV01@AEBV01@@Z 0x141126700
// MS2-PIN: ??4?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@@efd@@QEAAAEAV01@AEBV01@@Z 0x1411266a0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Nothing in this obj calls the assignments (cubemapinformationservice_3.cpp reaches them through opaque stand-ins), so
// they are odr-used through member-function pointer constants.
__declspec(selectany) extern Unk_CMISMapBucket& (Unk_CMISMapBucket::* const ms2_cmisBucketAssign)(const Unk_CMISMapBucket&) =
    &Unk_CMISMapBucket::operator=;
__declspec(selectany) extern Unk_CMISStdIntSet& (Unk_CMISStdIntSet::* const ms2_cmisIntSetAssign)(const Unk_CMISStdIntSet&) =
    &Unk_CMISStdIntSet::operator=;
__declspec(selectany) extern Unk_CMISFuncCubeSet& (Unk_CMISFuncCubeSet::* const ms2_cmisFuncCubeSetAssign)(
    const Unk_CMISFuncCubeSet&) = &Unk_CMISFuncCubeSet::operator=;
__declspec(selectany) extern Unk_CMISMapCube& (Unk_CMISMapCube::* const ms2_cmisCubeMapAssign)(const Unk_CMISMapCube&) =
    &Unk_CMISMapCube::operator=;
__declspec(selectany) extern Unk_CMISIntSet& (Unk_CMISIntSet::* const ms2_cmisKeySetAssign)(const Unk_CMISIntSet&) =
    &Unk_CMISIntSet::operator=;
