// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService COMDAT tail slice 0x141126010-
// 0x1411263f0 (queue unit_141126010): the inline dtors of ecr::SceneGraphAddedMessage / SceneGraphMessage and of the
// SetItemEffectInfo record, then the MS2Ptr<T> copy assignments / dtors / raw-pointer assignments the service's
// containers use. Same driver family as cubemapinformationservice_tail9.cpp; the container types are shared in
// cubemapinformationservice_tail.h. Not an original file.
// MS2-UNIT: unit_141126010
// MS2-RANGE: 0x141126010-0x1411263f0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??1SetItemEffectInfo@@UEAA@XZ 0x141126060
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include <ecr/CoreRuntimeMessages.h>

class NoticeCubeInfo;
namespace egfPhysX { class EntityActorData { public: void IncRefCount() const; void DecRefCount() const; }; }   // C3: member view (0x140ae1dd0, 0x140ae1b60)

Unk_CMISPropPtr& Unk_CMISPropPtr::operator=(const Unk_CMISPropPtr& o)
{
    if (m_p != o.m_p)
    {
        if (m_p != 0)
            reinterpret_cast<egfPhysX::EntityActorData*>(m_p)->DecRefCount();
        m_p = o.m_p;
        if (m_p != 0)
            reinterpret_cast<egfPhysX::EntityActorData*>(m_p)->IncRefCount();
    }
    return *this;
}

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
    { Unk_CMISPropPtr a, b; a = b; }
    { Unk_PayloadPtr<NoticeCubeInfo> a, b; a = b; }
    { MS2Ptr<CFunctionCubeObject> a; a = 0; }
    { Unk_PayloadPtr<CubeOwner> a; a = 0; }
    { Unk_PayloadPtr<CUGCMapData> a; a = 0; }
    { MS2Ptr<Unk_CMISUidRecord> a; a = 0; }
    { MS2Ptr<CFunctionCubeObject> a; }
    { MS2Ptr<UIHouseMarkEntity> a; }
    { MS2Ptr<AutomaticCreateCubeInfo> a; }
}
