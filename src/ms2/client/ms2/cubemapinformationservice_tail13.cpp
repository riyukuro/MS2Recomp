// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService COMDAT tail slice 0x141126010-
// 0x1411263f0 (queue unit_141126010): the inline dtors of ecr::SceneGraphAddedMessage / SceneGraphMessage and of the
// SetItemEffectInfo record, then the MS2Ptr<T> copy assignments / dtors / raw-pointer assignments the service's
// containers use. Same driver family as cubemapinformationservice_tail9.cpp; the container types are shared in
// cubemapinformationservice_tail.h. Not an original file.
// MS2-UNIT: unit_141126010
// MS2-RANGE: 0x141126010-0x1411263f0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??1SetItemEffectInfo@@UEAA@XZ 0x141126060
// MS2-PIN: ??4?$MS2Ptr@VFittingDollData@@@@QEAAAEAV0@AEBV0@@Z 0x141126100 ; AddRef 0x14112fa90 / Release 0x141149320 are the FittingDollData ones; FUN_1410cb4c0 assigns MS2Ptr<FittingDollData> through it
// MS2-PIN: ??4?$MS2Ptr@VCube@@@@QEAAAEAV0@AEBV0@@Z 0x141126140 ; look-alike pairing only: 0x141126140 is the Unk_CMISHousePtr assign (AddRef 0x14112fac0), the Cube one is 0x140965020
// MS2-PIN: ??4?$Unk_PayloadPtr@VCubeOwner@@@@QEAAAEAV0@H@Z 0x141126260
// MS2-PIN: ??4?$MS2Ptr@VSetItemEffectInfo@@@@QEAAAEAV0@AEBV0@@Z 0x141126290 ; merge 63: the look-alike guess rotated 290/340 (340 went functional)
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCFunctionCubeObject@@@@QEAAAEAV1@PEAVCFunctionCubeObject@@@Z 0x1411262d0 ; look-alike pairing: the exe body calls 0x1408b6790/0x1408b6c60
// MS2-PIN: ??4?$Unk_PayloadPtr@VNoticeCubeInfo@@@@QEAAAEAV0@AEBV0@@Z 0x141126340 ; ICF target of the NoticeCubeInfo assign in cubemapinformationservice_3 (l.2257)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include <ecr/CoreRuntimeMessages.h>

class NoticeCubeInfo;
// (egfPhysX::EntityActorData member view: cubemapinformationservice_tail.h)

// (Unk_CMISPropPtr::operator= is gone: the stand-in is efd::SmartPointer<egfPhysX::EntityActorData>, whose SDK operator=
// is the exe 0x141126090)








void Unk_CMISDriveTail13()
{
    { ecr::SceneGraphAddedMessage m; }
    { SetItemEffectInfo e; }
    { MS2Ptr<FittingDollData> a, b; a = b; }
    { MS2Ptr<SalesInfo> a, b; a = b; }
    { MS2Ptr<SetItemEffectInfo> a, b; a = b; }
    { MS2Ptr<Cube> a, b; a = b; }
    { MS2Ptr<SaleStateData> a, b; a = b; }
    { MS2Ptr<UICubeUGCHead> a; a.AssignRaw(0); }
    { MS2Ptr<CFunctionCubeObject> a; a.AssignRaw(0); }
    { efd::SmartPointer<egfPhysX::EntityActorData> a, b; a = b; }
    { Unk_PayloadPtr<NoticeCubeInfo> a, b; a = b; }
    { MS2Ptr<CFunctionCubeObject> a; a = 0; }
    { Unk_PayloadPtr<CubeOwner> a; a = 0; }
    { Unk_PayloadPtr<CUGCMapData> a; a = 0; }
    { MS2Ptr<Unk_CMISUidRecord> a; a = 0; }
    { MS2Ptr<CFunctionCubeObject> a; }
    { MS2Ptr<UIHouseMarkEntity> a; }
    { MS2Ptr<AutomaticCreateCubeInfo> a; }
}
