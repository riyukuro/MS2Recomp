// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2ActorManager: Nexon's NiActorManager subclass. Its
// own code is the two NiActorManager::Create overloads (as free functions), the exe's Clone / CloneOnlyAnimation
// (which build an MS2ActorManager), the pending-sequence flush, ctor and dtor; the rest of the unit is the Gamebryo
// header inlines (NiKFMTool ctor/dtor, NiTMapBase / NiTPointerMap / NiTStringPointerMap instances, NiTObjectArray)
// that are first instantiated here.
// MS2-UNIT: ?\ms2actormanager.cpp
// MS2-RANGE: 0x140d81400-0x140d86270 .text$mn
// MS2-RANGE: 0x1400d39e0-0x1400d3aa0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVSequence@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAA@XZ 0x140d82d50 ; unique
// MS2-PIN: ??1?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVSequenceGroup@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAA@XZ 0x140d82da0 ; unique
// MS2-PIN: ??1?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVTransition@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAA@XZ 0x140d82df0 ; unique
// MS2-PIN: ??1?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEAVNiObject@@PEAV2@V?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAA@XZ 0x140d82e40 ; prop
// MS2-PIN: ??1?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEAVNiObject@@_NV?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAA@XZ 0x140d82e90 ; prop
// MS2-PIN: ??1?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEBDPEAVNiSequenceData@@VNiStringHashFunctor@@VNiStringEqualsFunctor@@@@UEAA@XZ 0x140d82ee0 ; unique
// MS2-PIN: ??1?$NiTPointerMap@PEAVNiObject@@PEAV1@V?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAA@XZ 0x140d83030 ; prop
// MS2-PIN: ??1?$NiTPointerMap@PEAVNiObject@@_NV?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAA@XZ 0x140d83070 ; prop
// MS2-PIN: ??_G?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVSequence@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAPEAXI@Z 0x140d839c0 ; prop
// MS2-PIN: ??_G?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVSequenceGroup@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAPEAXI@Z 0x140d83a20 ; prop
// MS2-PIN: ??_G?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVTransition@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAPEAXI@Z 0x140d83a80 ; prop
// MS2-PIN: ??_G?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEAVNiObject@@PEAV2@V?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAAPEAXI@Z 0x140d83ae0 ; prop
// MS2-PIN: ??_G?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEAVNiObject@@_NV?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAAPEAXI@Z 0x140d83b40 ; prop
// MS2-PIN: ??_G?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEBDPEAVNiSequenceData@@VNiStringHashFunctor@@VNiStringEqualsFunctor@@@@UEAAPEAXI@Z 0x140d83ba0 ; prop
// MS2-PIN: ??_G?$NiTPointerMap@IPEAVSequence@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAPEAXI@Z 0x140d83c00 ; prop
// MS2-PIN: ??_G?$NiTPointerMap@IPEAVSequenceGroup@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAPEAXI@Z 0x140d83c60 ; prop
// MS2-PIN: ??_G?$NiTPointerMap@IPEAVTransition@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAPEAXI@Z 0x140d83cc0 ; prop
// MS2-PIN: ??_G?$NiTPointerMap@PEAVNiObject@@PEAV1@V?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAAPEAXI@Z 0x140d83d20 ; prop
// MS2-PIN: ??_G?$NiTPointerMap@PEAVNiObject@@_NV?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAAPEAXI@Z 0x140d83d80 ; prop
// MS2-PIN: ??_G?$NiTPointerMap@PEBDPEAVNiSequenceData@@VNiStringHashFunctor@@VNiStringEqualsFunctor@@@@UEAAPEAXI@Z 0x140d83de0 ; prop
// MS2-PIN: ?ClearValue@?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVSequence@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@MEAAXPEAV?$NiTMapItem@IPEAVSequence@NiKFMTool@@@@@Z 0x140d845c0 ; unique
// MS2-PIN: ?ClearValue@?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVSequenceGroup@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@MEAAXPEAV?$NiTMapItem@IPEAVSequenceGroup@NiKFMTool@@@@@Z 0x140d845d0 ; unique
// MS2-PIN: ?ClearValue@?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVTransition@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@MEAAXPEAV?$NiTMapItem@IPEAVTransition@NiKFMTool@@@@@Z 0x140d845e0 ; unique
// MS2-PIN: ?ClearValue@?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEAVNiObject@@_NV?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@MEAAXPEAV?$NiTMapItem@PEAVNiObject@@_N@@@Z 0x140d84600 ; unique
// MS2-PIN: ?ClearValue@?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEBDPEAVNiSequenceData@@VNiStringHashFunctor@@VNiStringEqualsFunctor@@@@MEAAXPEAV?$NiTMapItem@PEBDPEAVNiSequenceData@@@@@Z 0x140d84610 ; unique
// MS2-PIN: ?DeleteItem@?$NiTPointerMap@IPEAVSequence@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAXPEAV?$NiTMapItem@IPEAVSequence@NiKFMTool@@@@@Z 0x140d848c0 ; unique
// MS2-PIN: ?DeleteItem@?$NiTPointerMap@IPEAVSequenceGroup@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAXPEAV?$NiTMapItem@IPEAVSequenceGroup@NiKFMTool@@@@@Z 0x140d84900 ; unique
// MS2-PIN: ?DeleteItem@?$NiTPointerMap@IPEAVTransition@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAXPEAV?$NiTMapItem@IPEAVTransition@NiKFMTool@@@@@Z 0x140d84940 ; unique
// MS2-PIN: ?DeleteItem@?$NiTPointerMap@PEAVNiObject@@PEAV1@V?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAAXPEAV?$NiTMapItem@PEAVNiObject@@PEAV1@@@@Z 0x140d84980 ; unique
// MS2-PIN: ?GetStoredType@Transition@NiKFMTool@@QEBA?AW4TransitionType@2@XZ 0x140d851d0 ; unique
// MS2-PIN: ?NewItem@?$NiTPointerMap@IPEAVSequence@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAPEAV?$NiTMapItem@IPEAVSequence@NiKFMTool@@@@XZ 0x140d85300 ; unique
// MS2-PIN: ?NewItem@?$NiTPointerMap@IPEAVSequenceGroup@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAPEAV?$NiTMapItem@IPEAVSequenceGroup@NiKFMTool@@@@XZ 0x140d85320 ; unique
// MS2-PIN: ?NewItem@?$NiTPointerMap@IPEAVTransition@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@UEAAPEAV?$NiTMapItem@IPEAVTransition@NiKFMTool@@@@XZ 0x140d85340 ; unique
// MS2-PIN: ?NewItem@?$NiTPointerMap@PEAVNiObject@@PEAV1@V?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAAPEAV?$NiTMapItem@PEAVNiObject@@PEAV1@@@XZ 0x140d85360 ; unique
// MS2-PIN: ?NewItem@?$NiTPointerMap@PEAVNiObject@@_NV?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@UEAAPEAV?$NiTMapItem@PEAVNiObject@@_N@@XZ 0x140d85380 ; unique
// MS2-PIN: ?NewItem@?$NiTPointerMap@PEBDPEAVNiSequenceData@@VNiStringHashFunctor@@VNiStringEqualsFunctor@@@@UEAAPEAV?$NiTMapItem@PEBDPEAVNiSequenceData@@@@XZ 0x140d853a0 ; unique
// MS2-PIN: ?RemoveAll@?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVSequence@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@QEAAXXZ 0x140d853c0 ; unique
// MS2-PIN: ?RemoveAll@?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVSequenceGroup@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@QEAAXXZ 0x140d85480 ; unique
// MS2-PIN: ?RemoveAll@?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVTransition@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@QEAAXXZ 0x140d85540 ; unique
// MS2-PIN: ?RemoveAll@?$NiTMapBase@V?$NiTPointerAllocator@_K@@IV?$SmartPointer@VNiSequenceData@@@efd@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@QEAAXXZ 0x140d85600 ; prop
// MS2-PIN: ?RemoveAll@?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEAVNiObject@@PEAV2@V?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@QEAAXXZ 0x140d856c0 ; prop
// MS2-PIN: ?RemoveAll@?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEAVNiObject@@_NV?$NiTMapHashFunctor@PEAVNiObject@@@@V?$NiTMapEqualsFunctor@PEAVNiObject@@@@@@QEAAXXZ 0x140d85780 ; prop
// MS2-PIN: ?RemoveAll@?$NiTMapBase@V?$NiTPointerAllocator@_K@@PEBDPEAVNiSequenceData@@VNiStringHashFunctor@@VNiStringEqualsFunctor@@@@QEAAXXZ 0x140d85840 ; unique
// MS2-PIN: ?SetValue@?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVSequence@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@MEAAXPEAV?$NiTMapItem@IPEAVSequence@NiKFMTool@@@@IPEAVSequence@NiKFMTool@@@Z 0x140d85fd0 ; unique
// MS2-PIN: ?SetValue@?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVSequenceGroup@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@MEAAXPEAV?$NiTMapItem@IPEAVSequenceGroup@NiKFMTool@@@@IPEAVSequenceGroup@NiKFMTool@@@Z 0x140d86000 ; unique
// MS2-PIN: ?SetValue@?$NiTMapBase@V?$NiTPointerAllocator@_K@@IPEAVTransition@NiKFMTool@@V?$NiTMapHashFunctor@I@@V?$NiTMapEqualsFunctor@I@@@@MEAAXPEAV?$NiTMapItem@IPEAVTransition@NiKFMTool@@@@IPEAVTransition@NiKFMTool@@@Z 0x140d86030 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7MS2ActorManager@@6BActivationCallback@NiSequenceData@@@ 0x142e322b0
// MS2-PIN: ??_7MS2ActorManager@@6BTextKeyCallback@NiControllerSequence@@@ 0x142e322c8
#include <afx.h>
#include <string.h>
#pragma function(strcmp)   // the exe calls strcmp from NiStringEqualsFunctor::IsKeysEqual (no inline expansion)
#include "ms2/client/ms2/ms2actormanager.h"
#include <NiKFMTool.h>
#include <NiControllerManager.h>
#include <NiSequenceData.h>
#include <NiStream.h>
#include <NiFilename.h>
#include <NiAVObject.h>
#include <NiCloningProcess.h>
#include "hook/ms2hook.h"
#include <efd/Category.h>

NiImplementRTTI(MS2ActorManager, NiActorManager);   // .text$di 0x1400d39e0

// File-scope statics of the unit (dynamic initialisers 0x1400d3a10 / 0x1400d3a40 / 0x1400d3a70; no reader is known).
CStringW g_143ac2fe0(L"");
CStringW g_143ac2fe8(L"");
void* DAT_143ac2fd8;    // singleton read by FUN_140d86260

// Public view of the protected NiActorManager state the (free-function) Create / flush code touches.
struct Unk_ActorAccess : public MS2ActorManager
{
    using NiActorManager::m_spManager;
    using NiActorManager::m_kSeqDataMap;
    using NiActorManager::m_kMS2PendingSeqDataMap;
    using NiActorManager::Initialize;
};

NiActorManager* FUN_140d815d0(NiKFMTool* pkKFMTool, const char* pcKFMFilePath, bool bCumulativeAnimations,
                              bool bLoadFilesFromDisk, NiStream* pkStream, NiPoseBinding* pkPoseBinding);

// @0x140d85cf0 m_spManager = pkManager
void FUN_140d85cf0(Unk_ActorAccess* pkActorManager, NiControllerManager* pkManager)
{
    pkActorManager->m_spManager = pkManager;
}

// @0x140d86260 singleton accessor (callers type the result differently; see the symbols-manual row)
void* FUN_140d86260()
{
    return DAT_143ac2fd8;
}

// @0x140d81400
MS2ActorManager::~MS2ActorManager()
{
}

// @0x140d81450 NiActorManager::Create(const char* pcKFMFilename, ...)
NiActorManager* FUN_140d81450(const char* pcKFMFilename, bool bCumulativeAnimations, bool bLoadFilesFromDisk,
                              NiStream* pkStream, NiPoseBinding* pkPoseBinding)
{
    NiKFMTool::KFM_RC eRC, eSuccess = NiKFMTool::KFM_SUCCESS;

    NiKFMToolPtr spKFMTool = EE_NEW NiKFMTool;
    eRC = spKFMTool->LoadFile(pcKFMFilename);
    if (eRC != eSuccess)
    {
        return NULL;
    }

    return FUN_140d815d0(spKFMTool, pcKFMFilename, bCumulativeAnimations, bLoadFilesFromDisk, pkStream,
                         pkPoseBinding);
}

// NiActorManager::Create(NiKFMTool*, ...) building an MS2ActorManager
// @0x140d815d0
// MS2-FUNCTIONAL: the exe's NiStream is 0x5d0 bytes (engine header sizeof 0x4c8): allocate the exe size and placement-new
// it (a header-sized block was overrun by the exe ctor / Load: heap corruption on every KFM actor load)
NiActorManager* FUN_140d815d0(NiKFMTool* pkKFMTool, const char* pcKFMFilePath, bool bCumulativeAnimations,
                              bool bLoadFilesFromDisk, NiStream* pkStream, NiPoseBinding* pkPoseBinding)
{
    NiFilename kFilename(pcKFMFilePath);
    char acKFMPath[NI_MAX_PATH];
    NiSprintf(acKFMPath, NI_MAX_PATH, "%s%s", kFilename.GetDrive(), kFilename.GetDir());
    pkKFMTool->SetBaseKFMPath(acKFMPath);

    Unk_ActorAccess* pkActorManager = (Unk_ActorAccess*)EE_NEW MS2ActorManager(pkKFMTool, bCumulativeAnimations);

    if (bLoadFilesFromDisk)
    {
        bool bDeleteStream = false;
        if (!pkStream)
        {
            pkStream = ::new (efd::MemObject::operator new(0x5d0, EE_MEMHINT_NONE)) NiStream;
            bDeleteStream = true;
        }

        if (!pkActorManager->Initialize(*pkStream, pkPoseBinding))
        {
            EE_DELETE pkActorManager;
            return NULL;
        }

        if (bDeleteStream)
        {
            EE_DELETE pkStream;
        }
    }
    else
    {
        FUN_140d85cf0(pkActorManager, EE_NEW NiControllerManager(NULL));
    }

    return pkActorManager;
}

// @0x140d81930 (slot 3)
NiActorManager* MS2ActorManager::Clone(NiCloningProcess* pkCloningProcess)
{
    bool bDeleteCloningProcess = false;
    if (!pkCloningProcess)
    {
        pkCloningProcess = EE_NEW NiCloningProcess();
        bDeleteCloningProcess = true;
    }
    pkCloningProcess->m_eCopyType = NiObjectNET::COPY_EXACT;
    NiAVObject* pkNIFRoot = (NiAVObject*)m_spNIFRoot->Clone(*pkCloningProcess);
    if (bDeleteCloningProcess)
    {
        EE_DELETE pkCloningProcess;
    }

    NiControllerManager* pkManager = NiControllerManager::FindControllerManager(pkNIFRoot);

    MS2ActorManager* pkActorManager = EE_NEW MS2ActorManager(m_spKFMTool, m_bCumulativeAnimationsRequested);
    pkActorManager->m_spNIFRoot = pkNIFRoot;
    pkActorManager->m_spManager = pkManager;

    pkActorManager->m_pkCallbackObject = m_pkCallbackObject;
    NiTMapIterator kIter = m_kSeqDataMap.GetFirstPos();
    while (kIter)
    {
        SequenceID eSequenceID;
        NiSequenceDataPtr spOrigSeqData;
        m_kSeqDataMap.GetNext(kIter, eSequenceID, spOrigSeqData);

        NiSequenceData* pkNewSeqData = pkActorManager->m_spManager->GetSequenceDataByName(spOrigSeqData->GetName());
        pkActorManager->m_kSeqDataMap.SetAt(eSequenceID, pkNewSeqData);
    }
    for (unsigned int ui = 0; ui < m_kCallbacks.GetSize(); ui++)
    {
        CallbackData* pkData = m_kCallbacks.GetAt(ui);
        if (pkData)
        {
            pkActorManager->m_kCallbacks.AddFirstEmpty(pkData);
        }
    }

    return pkActorManager;
}

MS2_REPLACE_METHOD(0x140D81930, MS2ActorManager, Clone, 959, 0x0E2754B0);

// @0x140d81d00 (slot 5) MS2: the cloned sequence data is parked in the pending map instead of being added to the
// new controller manager.
NiActorManager* MS2ActorManager::CloneOnlyAnimation(NiAVObject* pkAVObject, bool bCumulativeAnimation)
{
    const char* pcModelRoot = m_spKFMTool->GetModelRoot();
    if (!pcModelRoot)
    {
        return NULL;
    }

    NiAVObject* pkActorRoot = pkAVObject ? pkAVObject->GetObjectByName(pcModelRoot) : NULL;

    NiControllerManager* pkManager = EE_NEW NiControllerManager(pkActorRoot, bCumulativeAnimation, NULL, true);

    MS2ActorManager* pkActorManager = EE_NEW MS2ActorManager(m_spKFMTool, bCumulativeAnimation);

    pkActorManager->m_pkCallbackObject = m_pkCallbackObject;
    NiTStringPointerMap<NiSequenceData*> kByName(37, true);
    unsigned int uiCount = m_spManager->GetSequenceDataCount();
    for (unsigned int ui = 0; ui < uiCount; ui++)
    {
        NiSequenceData* pkSeqData = m_spManager->GetSequenceDataAt(ui);
        if (!pkSeqData || pkSeqData->GetTempPose())
            continue;

        kByName.SetAt(pkSeqData->GetName(), pkSeqData);
    }

    NiTMapIterator kIter = m_kSeqDataMap.GetFirstPos();
    while (kIter)
    {
        SequenceID eSequenceID;
        NiSequenceDataPtr spOrigSeqData;
        m_kSeqDataMap.GetNext(kIter, eSequenceID, spOrigSeqData);

        NiSequenceData* pkNewSeqData = NULL;
        if (kByName.GetAt(spOrigSeqData->GetName(), pkNewSeqData))
        {
            pkActorManager->m_kMS2PendingSeqDataMap.SetAt(eSequenceID, pkNewSeqData);
        }
    }

    for (unsigned int ui = 0; ui < m_kCallbacks.GetSize(); ui++)
    {
        CallbackData* pkData = m_kCallbacks.GetAt(ui);
        if (pkData)
        {
            pkActorManager->m_kCallbacks.AddFirstEmpty(pkData);
        }
    }

    pkActorManager->m_spNIFRoot = pkAVObject;
    pkActorManager->m_spManager = pkManager;

    return pkActorManager;
}

// @0x140d821f0 moves the pending sequence data into the controller manager; returns 0 while there is none.
// (kfmmodel.cpp declares it `void* FUN_140d821f0(void*)`; the exe returns a bool in al)
#define MS2_AM ((Unk_ActorAccess*)pActorManager)
bool FUN_140d821f0(void* pActorManager)
{
    if (MS2_AM->m_spManager)
    {
        NiTMapIterator kIter = MS2_AM->m_kMS2PendingSeqDataMap.GetFirstPos();
        while (kIter)
        {
            NiActorManager::SequenceID eSequenceID;
            NiSequenceDataPtr spSeqData;
            MS2_AM->m_kMS2PendingSeqDataMap.GetNext(kIter, eSequenceID, spSeqData);

            MS2_AM->m_spManager->AddSequenceData(spSeqData);
            MS2_AM->m_kSeqDataMap.SetAt(eSequenceID, spSeqData);
        }
        MS2_AM->m_kMS2PendingSeqDataMap.RemoveAll();
        return true;
    }
    return false;
}
#undef MS2_AM

// @0x140d82310
MS2ActorManager::MS2ActorManager(NiKFMTool* pkKFMTool, bool bCumulativeAnimations)
    : NiActorManager(pkKFMTool, bCumulativeAnimations)
{
}
