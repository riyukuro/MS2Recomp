// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNifAnimationService: runs the time controllers of cached NIF models.
// MS2-UNIT: ?\nifanimationservice.cpp
// MS2-PIN: ??_7CNifAnimationService@@6BISystemService@efd@@@ 0x142f2c258
// MS2-PIN: ??_7CNifAnimationService@@6B?$TSingleton@VCNifAnimationService@@@@@ 0x142f2c2e0
// MS2-RANGE: 0x1400fa2d0-0x1400fa2f0 .text$di
// MS2-RANGE: 0x141545470-0x141548790 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetBeginKeyTime@NiTimeController@@QEBAMXZ 0x1415467d0 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@_KPEAVNifAnimationInfo@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@PEAVNifAnimationInfo@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x1415467f0 ; unique
// MS2-PIN: ?TypeCast@CNifAnimationService@@UEBA_NIPEAPEAX@Z 0x141548480 ; unique
// MS2-PIN: ?TypeCast@CNifAnimationService@@UEBA_NIPEAPEBX@Z 0x1415484d0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?RemoveHead@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiAVObject@@@efd@@@@QEAA?AV?$SmartPointer@VNiAVObject@@@efd@@XZ 0x141547bd0
// MS2-PIN: ?RemoveTail@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiAVObject@@@efd@@@@QEAA?AV?$SmartPointer@VNiAVObject@@@efd@@XZ 0x141547ef0
// MS2-PIN: ?RemovePos@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiAVObject@@@efd@@@@QEAA?AV?$SmartPointer@VNiAVObject@@@efd@@AEAPEAX@Z 0x141547cb0
// MS2-PIN: ?FindPos@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiAVObject@@@efd@@@@QEBAPEAXAEBV?$SmartPointer@VNiAVObject@@@efd@@PEAX@Z 0x1415466c0
// MS2-PIN: ??4?$SmartPointer@VNi3DRenderView@@@efd@@QEAAAEAV01@PEAVNi3DRenderView@@@Z 0x141546340
// MS2-PIN: ?GetClassDesc@CNifAnimationService@@UEBAPEBVClassInfo@efd@@XZ 0x1415467e0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\nifanimationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "nifanimationservice.h"
#include <NiCloningProcess.h>
#include <NiDefaultClickRenderStep.h>
#include <NiViewRenderClick.h>
#include <ecr/RenderService.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Depth-first walker over a NIF scene graph (0x30 bytes: the base ctor 0x14098c730 fills up to +0x2c; unrecovered class). Next(bDescend) yields the next NiAVObject.
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x30);

// Registers the service's dependency (a template inline of efd::IDependencyRegistrar, instantiated in another unit).
void FUN_1411ab770(efd::IDependencyRegistrar* pRegistrar, int nFlags);
// efd::ServiceManager::GetSystemServiceAs<ecr::RenderService>() (0x1411d15b0, shared COMDAT of another unit).
ecr::RenderService* FUN_1411d15b0(efd::ServiceManager* pManager);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CNifAnimationService);
CNifAnimationService* TSingleton<CNifAnimationService>::s_instance = 0;
inline TSingleton<CNifAnimationService>::TSingleton() { s_instance = static_cast<CNifAnimationService*>(this); }

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x141545470
CNifAnimationService::CNifAnimationService() : m_spView(0), m_mapInfo(10)
{
}
#endif
// @0x141545510
CNifAnimationService::~CNifAnimationService()
{
}
// @0x141545580
const char* CNifAnimationService::GetDisplayName() const { return "NifAnimationService"; }

// @0x1415455a0
int CNifAnimationService::FUN_1415455a0(unsigned __int64 nKey, NiNode* pkNif, int nMode)
{
    if (nMode == 1)
    {
        Unk_SceneWalker walker(pkNif);
        NiAVObject* pkObject;
        while ((pkObject = walker.Next(true)) != 0)
        {
            NiTimeController* pkCtrl = pkObject->GetControllers();
            while (pkCtrl != 0)
            {
                pkCtrl->Stop();
                pkCtrl->Start(0.0f);
                pkCtrl = pkCtrl->GetNext();
            }
        }
    }
    else
    {
        if (m_spView == (Ni3DRenderView*)0)
            return 0;

        NifAnimationInfo* pInfo = 0;
        if (m_mapInfo.Lookup(nKey, pInfo))
            return 0;

        pInfo = EE_NEW NifAnimationInfo;
        pInfo->CollectKeyTimes(pkNif);

        NiCloningProcess kCloning(0x25);
        kCloning.m_eCopyType = NiObjectNET::COPY_EXACT;
        pInfo->m_spClone = NiDynamicCast(NiNode, pkNif->Clone(kCloning));
        pInfo->m_spOriginal = pkNif;
        for (size_t i = 0; i < pkNif->GetChildCount(); i++)
        {
            NiAVObject* pkChild = pkNif->GetAt((unsigned int)i);
            if (pkChild)
            {
                pInfo->m_aChildren.Add(pkChild);
                pkNif->DetachChild(pkChild);
            }
        }
        if (pInfo->m_fEndTime <= 0.0f)
            pInfo->m_fEndTime = 0.1f;
        pInfo->m_timer.FUN_140868750((int)(pInfo->m_fEndTime * 1000.0f));
        m_mapInfo.SetAt(nKey, pInfo);
        m_spView->AppendScene(pInfo->m_spClone);
    }
    return 1;
}
// @0x141545920
// MS2-FUNCTIONAL: engine-typed rewrite; codegen differs from exe (inlined engine templates / frame layout)
efd::SyncResult CNifAnimationService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    FUN_1411ab770(pRegistrar, 1);
    return efd::SyncResult_Success;
}
// @0x141545950
efd::AsyncResult CNifAnimationService::OnInit()
{
    m_mapInfo.RemoveAll();
    ecr::RenderService* pkRender = FUN_1411d15b0(m_pServiceManager);
    NiDefaultClickRenderStep* pkClickStep = NiDynamicCast(NiDefaultClickRenderStep, pkRender->GetActiveRenderSurface()->GetRenderStep());
    NiViewRenderClick* pkClick = 0;
    NiTPointerList<NiRenderClickPtr>& kClicks = pkClickStep->GetRenderClickList();

    m_spView = EE_NEW Ni3DRenderView(0, 0, true);
    {
        NiFixedString kName("NifAnimationInfo");
        m_spView->SetName(kName);
    }

    NiTListIterator kPos = kClicks.GetHeadPos();
    while (kPos != 0)
    {
        pkClick = NiDynamicCast(NiViewRenderClick, kClicks.GetNext(kPos));
        if (pkClick != 0 && pkClick->GetName() == "SceneGraphClick")
        {
            pkClick->PrependRenderView(m_spView);   // the exe puts the view first (0x14127cce0, AddHead)
            break;
        }
    }
    return efd::AsyncResult_Complete;
}
// @0x141545b30
efd::AsyncResult CNifAnimationService::OnTick()
{
    for (POSITION pos = m_mapInfo.GetHeadPosition(); pos != 0; m_mapInfo.GetNext(pos))
    {
        NifAnimationInfo* pInfo = m_mapInfo.GetValueAt(pos);
        if (pInfo != 0)
        {
            if (pInfo->m_timer.FUN_140868c00() != 0)
            {
                m_spView->RemoveScene(pInfo->m_spClone);
                delete pInfo;
                m_mapInfo.RemoveAt(pos);
                continue;
            }
            float fTime = (float)pInfo->m_timer.FUN_140868a70() / 1000.0f;
            pInfo->m_spClone->Update(fTime, true);
        }
    }
    return efd::AsyncResult_Pending;
}
// @0x141545ca0
efd::AsyncResult CNifAnimationService::OnShutdown()
{
    if (m_spView)
    {
        for (POSITION pos = m_mapInfo.GetHeadPosition(); pos != 0; m_mapInfo.GetNext(pos))
        {
            NifAnimationInfo* pInfo = m_mapInfo.GetValueAt(pos);
            if (pInfo != 0)
            {
                m_spView->RemoveScene(pInfo->m_spClone);
                delete pInfo;
            }
        }
        m_mapInfo.RemoveAll();

        ecr::RenderService* pkRender = FUN_1411d15b0(m_pServiceManager);
        if (pkRender != 0 && pkRender->GetActiveRenderSurface() != 0)
        {
            NiDefaultClickRenderStep* pkClickStep = NiDynamicCast(NiDefaultClickRenderStep, pkRender->GetActiveRenderSurface()->GetRenderStep());
            NiViewRenderClick* pkClick = 0;
            NiTPointerList<NiRenderClickPtr>& kClicks = pkClickStep->GetRenderClickList();
            NiTListIterator kPos = kClicks.GetHeadPos();
            while (kPos != 0)
            {
                pkClick = NiDynamicCast(NiViewRenderClick, kClicks.GetNext(kPos));
                if (pkClick != 0 && pkClick->GetName() == "SceneGraphClick")
                {
                    pkClick->RemoveRenderView(m_spView);
                    break;
                }
            }
        }
        m_spView = 0;
    }
    return efd::AsyncResult_Complete;
}
// @0x141548520 (UCRT header-inline memcpy_s from corecrt_memcpy_s.h, one internal-linkage copy per TU)
#pragma function(memset, memcpy)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
static __inline errno_t ms2_memcpy_s(void* const dst, size_t const dstSize, void const* const src, size_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    if (src == NULL || dstSize < srcSize) {
        memset(dst, 0, dstSize);
        MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
        MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
        return EINVAL;
    }
    memcpy(dst, src, srcSize);
    return 0;
}
#pragma intrinsic(memset, memcpy)
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &ms2_memcpy_s;
MS2_EMIT_CRT_MEMMOVE_S();
// MS2-PIN: ?IsEmpty@?$NiTListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiProperty@@@efd@@@@QEBA_NXZ 0x141546cb0 ; property-list IsEmpty (twin of the effect-list copy 0x141546c80)
