// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService COMDAT tail slice 0x141123340-
// 0x1411234d0 (queue unit_141123340): the inline ctors of ecr::SceneGraphAddedMessage / SceneGraphMessage and of the
// SetItemEffectInfo record, and the CAtlArray<void*> dtors of the service's three element-pointer arrays. Same driver
// family as cubemapinformationservice_tail9.cpp; the container types are shared in cubemapinformationservice_tail.h.
// Not an original file.
// MS2-UNIT: unit_141123340
// MS2-RANGE: 0x141123340-0x1411234d0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??0SetItemEffectInfo@@QEAA@XZ 0x1411233c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include <ecr/CoreRuntimeMessages.h>

inline SetItemEffectInfo::SetItemEffectInfo() : m_nEffect(0)
{
}

void Unk_CMISDriveTail12()
{
    { ecr::SceneGraphAddedMessage m; }
    { SetItemEffectInfo e; }
    { ATL::CAtlArray<Unk_CMISElem388*> a; ATL::CAtlArray<Unk_CMISElem3a8*> b; ATL::CAtlArray<Unk_CMISElem458*> c; }
    { ATL::CAtlArray<MS2Ptr<CFunctionCubeObject> > d; }
}
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@VCFunctionCubeObject@@@@V?$CElementTraits@V?$MS2Ptr@VCFunctionCubeObject@@@@@ATL@@@ATL@@QEAA@XZ 0x141123410 ; gp1: FUN_1410c8e40's aNear dtor
