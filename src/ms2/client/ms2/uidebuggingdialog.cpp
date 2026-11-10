// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDebuggingDialog: see uidebuggingdialog.h.
// MS2-UNIT: ?\uidebuggingdialog.cpp
// MS2-RANGE: 0x141284e00-0x141286410 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidebuggingdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include "uidebuggingdialog.h"
#include "pcbase.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/nipoint3.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>
#include <efd/Point2.h>
#include <egf/Entity.h>
#include <ecr/SceneGraphService.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/windowservice.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/client/ms2/npcdatacli.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include <NiRenderObject.h>
#include <Ni3DRenderView.h>
#include <efd/ServiceManager.h>
#include <ecr/PickService.h>

// ---- unit-local views of exe objects ----

// The mesh UV picker (meshuvpicker.h is not included: only the pick is called here).
class CMeshUVPicker : public efd::MemObject
{
public:
    CMeshUVPicker();                                                    // 0x14147e6e0
    bool PickUVAndPosition(NiRenderObject* pMesh, NiCamera* pCamera, float fX, float fY, struct Unk_FcPoint3* pPos0, struct Unk_FcPoint3* pPos1,
                       class NiPoint2* pUV, float* pIndex, CAtlArray<NiRenderObject*>* pExtras);   // 0x14147ea50 (meshuvpicker.h)
    char m_pad[0x98];
};
MS2_CHECK_SIZE(CMeshUVPicker, 0x98);

class Unk_DbgNpc : public CNpc { };
// The marker effect request: a NoticeMessage (placeholder/effectquery.h), 0x70 bytes. The ctor 0x140a52ef0 fills all of
// it and SetActor 0x140a53190 writes +0x54 (a 16-byte stand-in was overrun, rt1 stackovf.py); only the name and the type
// are used here.
struct Unk_DbgMarker
{
    Unk_DbgMarker();                                                    // 0x140a52ef0
    ~Unk_DbgMarker();                                                   // 0x1405a89e0
    void* m_pName;                                                      // +0x00 CString
    int m_nType;                                                        // +0x08
    int m_nPad;
    void* m_pad10[(0x70 - 0x10) / 8];
};
class Unk_DbgEffectMgr
{
public:
};
class NoticeMessage   // C3: member view for the former free stand-ins
{
public:
    NoticeMessage();
    ~NoticeMessage();
    void SetActor(int);
    void* m_storage[14];
};
struct Unk_DbgConfig { char m_pad[0x2e8]; CString m_strMarkerEffect; };   // the client config
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0
struct Unk_DbgApp : public CWindowService { };         // cursor position
void* FUN_140aadf80();   // C3: was FUN_140aadf80
class Ni3DRenderView* FUN_1413f9a70();   // C3: was FUN_1413f9a70
class Unk_ServiceManager* FUN_1413f9850();   // C3: was FUN_1413f9850
ecr::SceneGraphService* FUN_1413f98b0();                                // the scene graph service
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
// Depth-first walker over a scene graph (0x38 bytes; unrecovered class, symbols-manual rows shared with util.cpp).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);              // 0x14098cb80
    ~Unk_NodeQueue();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
typedef Unk_NodeQueue Unk_SceneWalker;   // C3: was a local stand-in for Unk_NodeQueue
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);
void* FUN_140876480(void* pOut, int nCat);
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCat);
CStringW FUN_14016a730(const char* sz, int n);                          // narrow text -> CStringW
// The animation service view that returns the npc model name.
struct Unk_EmModelLoader { efd::utf8string GetCurrentSequenceName(const egf::EntityID& kId); };   // C3: as equipmodel.cpp defines it
namespace egmAnimation { class AnimationService; }
egmAnimation::AnimationService* FUN_141b6f910();
float FUN_14028d3a0(float fValue);                                       // table value of a speed
bool FUN_14028d470(float fValue, float fZero);                           // fValue == nZero
// The npc record handle accessors.
struct Unk_DbgSpeedRec;

// ---- the UV picker pointer (the five inline members were first emitted by this unit) ----

// @0x141286170
Unk_UVPickerPtr::Unk_UVPickerPtr(CMeshUVPicker* p)
{
    m_p = p;
    if (m_p != 0)
        ((class NiRefObject*)(void*)(m_p))->IncRefCount();
}

// @0x1412861b0
Unk_UVPickerPtr::~Unk_UVPickerPtr()
{
    if (m_p != 0)
        ((class NiRefObject*)(void*)(m_p))->DecRefCount();
}

// @0x1412861e0
Unk_UVPickerPtr& Unk_UVPickerPtr::FUN_1412861e0(CMeshUVPicker* p)
{
    if (m_p != p)
    {
        if (m_p != 0)
            ((class NiRefObject*)(void*)(m_p))->DecRefCount();
        m_p = p;
        if (m_p != 0)
            ((class NiRefObject*)(void*)(m_p))->IncRefCount();
    }
    return *this;
}

// @0x141286250
bool Unk_UVPickerPtr::FUN_141286250(CMeshUVPicker* p) const
{
    return m_p == p;
}

// @0x141286290
CMeshUVPicker* Unk_UVPickerPtr::FUN_141286290() const
{
    return m_p;
}

// ---- UIDebuggingDialog ----

// @0x141284e00
UIDebuggingDialog::UIDebuggingDialog()
    : m_bPicking(0), m_spPicker(0)
{
    m_40 = 1;
    m_bClear = 1;
}

// @0x141284ea0
UIDebuggingDialog::~UIDebuggingDialog()
{
    m_spPicker.FUN_1412861e0(0);
    FUN_1412860c0();
}

// @0x141284f30
CString UIDebuggingDialog::GetTypeName()
{
    return CString("DebuggingDialog");
}

// @0x141284f80
void UIDebuggingDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_nTargetId = 0;
    m_nMarkerId = 0;
    if (m_spPicker.FUN_141286250(0))
    {
        m_spPicker.FUN_1412861e0(new (efd::MemHint(efd::MemHint::NONE)) CMeshUVPicker);
    }
    m_timer.FUN_1408687f0();
    m_bClear = 1;
    m_30->Invoke("initData");
}

// @0x1412850c0
int UIDebuggingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onClickChooseNPC", szMethod) == 0)
    {
        OnClickChooseNPC();
        return 1;
    }
    return 0;
}

// @0x141285130
void UIDebuggingDialog::vfunc_33(void* p, float fX, float fY)
{
    UISwfEntity::vfunc_33(p, fX, fY);
    if (vfunc_55() != 0)
        return;
    if (m_bPicking != 0 && m_timer.FUN_140868c00() != 0 && TSingleton<CameraMgr>::GetInstance()->FUN_140a18070() != 0)
    {
        void* pScene = ((void*)FUN_1413f9850());
        if (pScene == 0)
            return;
        efd::Point2 kScreen(fX, fY);
        Unk_NiPoint3 kOrigin(DAT_143b01a60);
        Unk_NiPoint3 kDir(DAT_143b01a60);
        if (TSingleton<CameraMgr>::GetInstance()->ScreenToRay(reinterpret_cast<const NiPoint2&>(kScreen), reinterpret_cast<NiPoint3&>(kOrigin), reinterpret_cast<NiPoint3&>(kDir)))
        {
            if (void* pSceneData = reinterpret_cast<efd::ServiceManager*>(FUN_1413f9850())->GetSystemServiceAs<ecr::PickService>())
            {
                void* pMap = WorldService::GetInstance()->FUN_141bd36d0();
                bool bFound = false;
                for (void* pos = ((void*)((ATL::CRBTree<unsigned int, efd::SmartPointer<CNpc>, ATL::CElementTraits<unsigned int>, ATL::CElementTraits<efd::SmartPointer<CNpc>>>*)(void*)(pMap))->GetHeadPosition()); pos != 0; ((ATL::CRBTree<unsigned int, efd::SmartPointer<CNpc>, ATL::CElementTraits<unsigned int>, ATL::CElementTraits<efd::SmartPointer<CNpc>>>*)(void*)(pMap))->GetNext(reinterpret_cast<POSITION&>(pos)))
                {
                    if (bFound)
                        break;
                    Unk_DbgNpc* pNpc = static_cast<Unk_DbgNpc*>((CNpc*)((ATL::CRBTree<unsigned int, efd::SmartPointer<CNpc>, ATL::CElementTraits<unsigned int>, ATL::CElementTraits<efd::SmartPointer<CNpc>>>*)(void*)(pMap))->GetValueAt((struct __POSITION*)(pos)));
                    if (pNpc == 0)
                        continue;
                    MS2Ptr<CNpcData> spData = pNpc->GetNpcData();
                    if (!spData)
                        continue;
                    ecr::SceneGraphService* pSceneSvc = FUN_1413f98b0();
                    NiAVObject* pRoot = pSceneSvc->GetSceneGraphFromEntity(pNpc->GetEntity());
                    Unk_SceneWalker walker((NiAVObject*)(pRoot));
                    while (void* pNode = walker.Next(true))
                    {
                        if (void* pMesh = ((void*)NiObject::DynamicCast(&NiRenderObject::ms_RTTI, (class NiObject const*)(pNode))))
                        {
                            Ni3DRenderView* pView = FUN_1413f9a70();
                            Vector3 kHit;
                            Vector3 kNormal;
                            efd::Point2 kUV;
                            efd::Point2 kCursor;
                            if (((struct Unk_DbgApp*)FUN_140aadf80())->GetCursorClientPos(&kCursor.x, &kCursor.x + 1) == 0)
                                return;
                            unsigned nTri;
                            if (m_spPicker.FUN_141286290()->PickUVAndPosition((NiRenderObject*)pMesh, pView->GetCamera(), kCursor.x, kCursor.y, (struct Unk_FcPoint3*)&kHit,
                                                                              (struct Unk_FcPoint3*)&kNormal, (class NiPoint2*)&kUV, (float*)&nTri, 0))
                            {
                                m_bPicking = 0;
                                if (m_nTargetId != 0 || m_nMarkerId != 0)
                                    FUN_1412860c0();
                                m_nTargetId = pNpc->GetObjectId();
                                NoticeMessage kMarker;   // C3: was Unk_DbgMarker
                                reinterpret_cast<CString&>(((Unk_DbgMarker&)(kMarker)).m_pName) = ((struct Unk_DbgConfig*)FUN_1401d31f0())->m_strMarkerEffect;
                                ((Unk_DbgMarker&)(kMarker)).m_nType = pNpc->FUN_141092ff0() != 0 ? 6 : 5;
                                ((class NoticeMessage*)(struct Unk_DbgMarker*)(&((Unk_DbgMarker&)(kMarker))))->SetActor(pNpc->GetObjectId());
                                m_nMarkerId = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&((Unk_DbgMarker&)(kMarker))));
                                bFound = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

// @0x141285690
void UIDebuggingDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_spPicker.FUN_1412861e0(0);
    FUN_1412860c0();
}

// @0x1412856d0
void UIDebuggingDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (vfunc_55() != 0)
        return;
    int bClear = 1;
    if (m_nTargetId != 0)
    {
        Unk_DbgNpc* pNpc = reinterpret_cast<Unk_DbgNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nTargetId));
        if (pNpc != 0)
        {
            efd::utf8string kModel = reinterpret_cast<Unk_EmModelLoader*>(FUN_141b6f910())->GetCurrentSequenceName(pNpc->GetEntityID());
            CStringW strNpcName = pNpc->vfunc_77().GetLength() == 0 ? L"Noname" : (LPCWSTR)pNpc->vfunc_77();
            FUN_141286050("m_npcName", strNpcName);
            FUN_141286050("m_aniName", FUN_14016a730(kModel.c_str(), 0));
            CStringW strState;
            strState.Format(L"%d", pNpc->GetCurStateId());
            FUN_141286050("m_state", strState);
            CStringW strSubState;
            strSubState.Format(L"%d", pNpc->FUN_14166cc80());
            FUN_141286050("m_subState", strSubState);
            FUN_141286050("m_aniSpeedCondition", FUN_14016a730(pNpc->FUN_1416713e0(), 0));
            FUN_141286050("m_aniSpeedExpression", FUN_14016a730(pNpc->FUN_141671430(), 0));
            CStringW strMoveSpeed;
            strMoveSpeed.Format(L"%.1f/%.1f", (double)pNpc->vfunc_95(), (double)FUN_14028d3a0(pNpc->GetNpcData()->m_fRunSpeed));
            FUN_141286050("m_moveSpeedS", strMoveSpeed);
            MS2Ptr<CNpcData> spData = pNpc->GetNpcData();
            if (spData.get() != 0)
            {
                float fBase = spData->m_fRunSpeed;
                if (FUN_14028d470(fBase, 0))
                {
                    fBase = spData->m_fWalkSpeed;
                    if (FUN_14028d470(fBase, 0))
                    {
                        fBase = pNpc->vfunc_95();
                        if (FUN_14028d470(fBase, 0))
                            fBase = 1.1754944e-38f;
                    }
                }
                CStringW strPercent;
                strPercent.Format(L"%.1f%%", (double)(pNpc->vfunc_95() / fBase));
                FUN_141286050("m_moveSpeedPercent", strPercent);
                strPercent.Format(L"%.1f%%", (double)(pNpc->FUN_1416713c0() * 100.0f));
                FUN_141286050("m_aniSpeedPercent", strPercent);
                strPercent.Format(L"%.1f", (double)spData->m_model.m_fAniSpeed);
                FUN_141286050("m_aniSpeed", strPercent);
                FUN_141286050("m_aniSpeedFix", L"false");
            }
            bClear = 0;
            m_bClear = 0;
        }
    }
    if (bClear != 0)
    {
        FUN_1412860c0();
        if (m_bClear == 0)
            m_30->Invoke("clearAll");
        m_bClear = 1;
    }
}

// @0x141286050
void UIDebuggingDialog::FUN_141286050(const CString& strName, const CStringW& strText)
{
    MS2Ptr<ASTextField> spText = GetChild<ASTextField>(strName);
    if (spText.get() != 0)
        spText->SetTextW(strText);
}

// @0x1412860c0
void UIDebuggingDialog::FUN_1412860c0()
{
    if (m_nMarkerId != 0)
    {
        if (reinterpret_cast<Unk_DbgEffectMgr*>(TSingleton<CEffectService>::GetInstance()) != 0)
            TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nMarkerId);
    }
    m_nMarkerId = 0;
    m_nTargetId = 0;
}

// @0x141286130
void UIDebuggingDialog::OnClickChooseNPC()
{
    m_bPicking = 1;
    m_timer.FUN_140868750(500);
}

// @0x1412862e0 is the inline vfunc_48 of the header.

// @0x1412862f0
MS2_EMIT_CRT_MEMMOVE_S();
