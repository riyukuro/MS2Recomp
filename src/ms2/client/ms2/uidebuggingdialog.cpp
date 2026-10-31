// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDebuggingDialog: see uidebuggingdialog.h.
// MS2-UNIT: ?\uidebuggingdialog.cpp
// MS2-RANGE: 0x141284e00-0x141286410 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidebuggingdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
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
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"

// ---- unit-local views of exe objects ----

// The mesh UV picker (meshuvpicker.h is not included: only the pick is called here).
class CMeshUVPicker : public efd::MemObject
{
public:
    CMeshUVPicker();                                                    // 0x14147e6e0
    bool FUN_14147ea50(void* pMesh, void* pCam, float fX, float fY, Vector3* pHit, Vector3* pNormal,
                       efd::Point2* pUV, unsigned* pTri, void* pSkins);   // pick
    char m_pad[0x98];
};
MS2_CHECK_SIZE(CMeshUVPicker, 0x98);

// The record of an npc row (CNpcData); only the speed fields are read here.
struct Unk_DbgNpcRec : public CPtred
{
    char m_pad_18[0x5c - 0x18];
    float m_fAniSpeed;                                                  // +0x5c
    char m_pad_60[0xd0 - 0x60];
    float m_fWalkSpeed;                                                 // +0xd0
    float m_fRunSpeed;                                                  // +0xd4
};
// The npc's data handle as FUN_141093270 returns it (16 bytes).
class Unk_DbgNpcDataPtr
{
public:
    ~Unk_DbgNpcDataPtr();                                               // 0x1406d5390 release
    Unk_DbgNpcRec* operator->() const;                                  // 0x140965990
    void* m_pad_00;
    void* m_p;
};
// The record handle converted from it (16 bytes).
class Unk_DbgRecPtr
{
public:
    Unk_DbgRecPtr(const Unk_DbgNpcDataPtr& src);                        // 0x1406cf850
    ~Unk_DbgRecPtr();                                                   // 0x14035e5b0 release
    bool operator!() const;                                             // 0x14035e9b0
    Unk_DbgNpcRec* get() const;                                         // 0x140729ad0
    Unk_DbgNpcRec* operator->() const;                                  // 0x14035eb90
    void* m_pad_00;
    void* m_p;
};
class Unk_DbgNpc : public CNpc
{
public:
    Unk_DbgNpcDataPtr FUN_141093270();                                  // the npc's data record handle
};
class Unk_DbgWorld
{
public:
    Unk_DbgNpc* FUN_141bd1320(int nId);                                 // npc by object id
    void* FUN_141bd36d0();                                              // npc tree
};
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
    int FUN_1411a49c0(Unk_DbgMarker* pRequest);                         // start the effect, returns its id
    void FUN_1411a6060(int nId);                                        // stop an effect
};
void FUN_140a53190(Unk_DbgMarker* p, int nTarget);
struct Unk_DbgConfig { char m_pad[0x2e8]; CString m_strMarkerEffect; };   // the client config
Unk_DbgConfig* FUN_1401d31f0();
class Unk_DbgCameraMgr : public CameraMgr
{
public:
    bool FUN_140af0520(const efd::Point2& kScreen, Unk_NiPoint3* pOrigin, Unk_NiPoint3* pDir);   // screen point to ray
};
struct Unk_DbgApp : public CWindowService { };         // cursor position
Unk_DbgApp* FUN_140aadf80();
struct Unk_DbgView { void* FUN_1409a8a60(); };                          // the view's camera
Unk_DbgView* FUN_1413f9a70();
void* FUN_1413f9850();                                                  // the service manager
void* FUN_140af2a30(void* pManager);
ecr::SceneGraphService* FUN_1413f98b0();                                // the scene graph service
efd::Point2 FUN_140a0a600(float fX, float fY);
extern Vector3 DAT_143b01a60;                                   // the zero point
void* FUN_140a7b840(void* pMap);                                        // npc tree iterator
void* FUN_140a7b8e0(void* pMap, void* pos);
PCBase* FUN_140a7b650(void* pEntry);
void FUN_140a7b860(void* pMap, void** pPos);
// Depth-first walker over a scene graph (0x38 bytes; unrecovered class, symbols-manual rows shared with util.cpp).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);
void* FUN_14098d8d0(const void* pRtti, void* pObject);                  // dynamic cast through an NiRTTI
extern char DAT_143afa7d0;                                              // NiRTTI of the mesh class
void* FUN_140876480(void* pOut, int nCat);
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCat);
void FUN_140980460(void* p);                                            // NiRefObject::IncRefCount
void FUN_1405a93d0(void* p);                                            // NiRefObject::DecRefCount
CStringW FUN_14016a730(const char* sz, int n);                          // narrow text -> CStringW
// The model table entry the npc's data record names (state names and the like).
struct Unk_DbgModelSet
{
    ~Unk_DbgModelSet();                                                 // 0x1408a8900
    char m_p[0x20];
};
class Unk_DbgModelTable
{
public:
    Unk_DbgModelSet FUN_141206030(const egf::EntityID& kKey);           // the npc's model set
};
Unk_DbgModelTable* FUN_141b6f910();
const char* FUN_1408ac310(Unk_DbgModelSet* p);                          // animation name
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
        FUN_140980460(m_p);
}

// @0x1412861b0
Unk_UVPickerPtr::~Unk_UVPickerPtr()
{
    if (m_p != 0)
        FUN_1405a93d0(m_p);
}

// @0x1412861e0
Unk_UVPickerPtr& Unk_UVPickerPtr::FUN_1412861e0(CMeshUVPicker* p)
{
    if (m_p != p)
    {
        if (m_p != 0)
            FUN_1405a93d0(m_p);
        m_p = p;
        if (m_p != 0)
            FUN_140980460(m_p);
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
    if (m_bPicking != 0 && m_timer.FUN_140868c00() != 0 && reinterpret_cast<Unk_DbgCameraMgr*>(TSingleton<CameraMgr>::GetInstance())->FUN_140a18070() != 0)
    {
        void* pScene = FUN_1413f9850();
        if (pScene == 0)
            return;
        efd::Point2 kScreen = FUN_140a0a600(fX, fY);
        Unk_NiPoint3 kOrigin(DAT_143b01a60);
        Unk_NiPoint3 kDir(DAT_143b01a60);
        if (reinterpret_cast<Unk_DbgCameraMgr*>(TSingleton<CameraMgr>::GetInstance())->FUN_140af0520(kScreen, &kOrigin, &kDir))
        {
            if (void* pSceneData = FUN_140af2a30(FUN_1413f9850()))
            {
                void* pMap = reinterpret_cast<Unk_DbgWorld*>(WorldService::GetInstance())->FUN_141bd36d0();
                bool bFound = false;
                for (void* pos = FUN_140a7b840(pMap); pos != 0; FUN_140a7b860(pMap, &pos))
                {
                    if (bFound)
                        break;
                    Unk_DbgNpc* pNpc = static_cast<Unk_DbgNpc*>(FUN_140a7b650(FUN_140a7b8e0(pMap, pos)));
                    if (pNpc == 0)
                        continue;
                    Unk_DbgRecPtr spData = pNpc->FUN_141093270();
                    if (!spData)
                        continue;
                    ecr::SceneGraphService* pSceneSvc = FUN_1413f98b0();
                    NiAVObject* pRoot = pSceneSvc->GetSceneGraphFromEntity(pNpc->FUN_14123c410());
                    Unk_SceneWalker walker(pRoot);
                    while (void* pNode = walker.Next(true))
                    {
                        if (void* pMesh = FUN_14098d8d0(&DAT_143afa7d0, pNode))
                        {
                            void* pView = FUN_1413f9a70();
                            Vector3 kHit;
                            Vector3 kNormal;
                            efd::Point2 kUV;
                            efd::Point2 kCursor;
                            if (FUN_140aadf80()->GetCursorClientPos(&kCursor.x, &kCursor.x + 1) == 0)
                                return;
                            unsigned nTri;
                            if (m_spPicker.FUN_141286290()->FUN_14147ea50(pMesh, static_cast<Unk_DbgView*>(pView)->FUN_1409a8a60(),
                                                                          kCursor.x, kCursor.y, &kHit, &kNormal, &kUV, &nTri, 0))
                            {
                                m_bPicking = 0;
                                if (m_nTargetId != 0 || m_nMarkerId != 0)
                                    FUN_1412860c0();
                                m_nTargetId = pNpc->FUN_14123c580();
                                Unk_DbgMarker kMarker;
                                reinterpret_cast<CString&>(kMarker.m_pName) = FUN_1401d31f0()->m_strMarkerEffect;
                                kMarker.m_nType = pNpc->FUN_141092ff0() != 0 ? 6 : 5;
                                FUN_140a53190(&kMarker, pNpc->FUN_14123c580());
                                m_nMarkerId = reinterpret_cast<Unk_DbgEffectMgr*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a49c0(&kMarker);
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
        Unk_DbgNpc* pNpc = reinterpret_cast<Unk_DbgWorld*>(WorldService::GetInstance())->FUN_141bd1320(m_nTargetId);
        if (pNpc != 0)
        {
            Unk_DbgModelSet kModel = FUN_141b6f910()->FUN_141206030(pNpc->FUN_14123c460());
            CStringW strNpcName = pNpc->vfunc_77().GetLength() == 0 ? L"Noname" : (LPCWSTR)pNpc->vfunc_77();
            FUN_141286050("m_npcName", strNpcName);
            FUN_141286050("m_aniName", FUN_14016a730(FUN_1408ac310(&kModel), 0));
            CStringW strState;
            strState.Format(L"%d", pNpc->FUN_14166c930());
            FUN_141286050("m_state", strState);
            CStringW strSubState;
            strSubState.Format(L"%d", pNpc->FUN_14166cc80());
            FUN_141286050("m_subState", strSubState);
            FUN_141286050("m_aniSpeedCondition", FUN_14016a730(pNpc->FUN_1416713e0(), 0));
            FUN_141286050("m_aniSpeedExpression", FUN_14016a730(pNpc->FUN_141671430(), 0));
            CStringW strMoveSpeed;
            strMoveSpeed.Format(L"%.1f/%.1f", (double)pNpc->vfunc_95(), (double)FUN_14028d3a0(pNpc->FUN_141093270()->m_fRunSpeed));
            FUN_141286050("m_moveSpeedS", strMoveSpeed);
            Unk_DbgRecPtr spData = pNpc->FUN_141093270();
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
                strPercent.Format(L"%.1f", (double)spData->m_fAniSpeed);
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
    MS2Ptr<ASTextField> spText = FUN_140bb4cf0(strName);
    if (spText.get() != 0)
        spText->FUN_1422c4cd0(strText);
}

// @0x1412860c0
void UIDebuggingDialog::FUN_1412860c0()
{
    if (m_nMarkerId != 0)
    {
        if (reinterpret_cast<Unk_DbgEffectMgr*>(TSingleton<CEffectService>::GetInstance()) != 0)
            reinterpret_cast<Unk_DbgEffectMgr*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a6060(m_nMarkerId);
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
