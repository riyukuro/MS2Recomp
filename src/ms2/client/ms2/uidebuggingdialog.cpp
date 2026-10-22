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

// ---- unit-local views of exe objects ----

// The mesh UV picker (meshuvpicker.h is not included: only the pick is called here).
class CMeshUVPicker : public efd::MemObject
{
public:
    CMeshUVPicker();                                                    // 0x14147e6e0
    bool FUN_14147ea50(void* pMesh, void* pCam, float fX, float fY, Unk_StreamPoint* pHit, Unk_StreamPoint* pNormal,
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
class Unk_DbgNpc : public PCBase
{
public:
    MS2Ptr<Unk_DbgNpcRec> FUN_141093270();                              // the npc's data record handle
    int FUN_141092ff0();                                                // nonzero: the npc carries a custom model block
    CString FUN_1416713e0();                                            // animation speed condition (PCBase view)
};
class Unk_DbgWorld
{
public:
    Unk_DbgNpc* FUN_141bd1320(int nId);                                 // npc by object id
    void* FUN_141bd36d0();                                              // npc tree
};
Unk_DbgWorld* FUN_1403ed2d0();
// The marker effect request (0x78 bytes in the exe; only the name and the type are used here).
struct Unk_DbgMarker
{
    void* m_pName;                                                      // +0x00 CString
    int m_nType;                                                        // +0x08
    int m_nPad;
};
class Unk_DbgEffectMgr
{
public:
    int FUN_1411a49c0(Unk_DbgMarker* pRequest);                         // start the effect, returns its id
    void FUN_1411a6060(int nId);                                        // stop an effect
};
Unk_DbgEffectMgr* FUN_1403ed280();
void* FUN_140a52ef0(Unk_DbgMarker* p);
void FUN_140a53190(Unk_DbgMarker* p, int nTarget);
void FUN_1405a89e0(Unk_DbgMarker* p);
struct Unk_DbgConfig { char m_pad[0x2e8]; CString m_strMarkerEffect; };   // the client config
Unk_DbgConfig* FUN_1401d31f0();
class Unk_DbgCameraMgr
{
public:
    int FUN_140a18070();
    bool FUN_140af0520(const efd::Point2& kScreen, Unk_NiPoint3* pOrigin, Unk_NiPoint3* pDir);   // screen point to ray
};
Unk_DbgCameraMgr* FUN_1409478c0();
struct Unk_DbgApp { int FUN_141b90e30(float* pX, float* pY); };         // cursor position
Unk_DbgApp* FUN_140aadf80();
struct Unk_DbgView { void* FUN_1409a8a60(); };                          // the view's camera
Unk_DbgView* FUN_1413f9a70();
void* FUN_1413f9850();                                                  // the service manager
void* FUN_140af2a30(void* pManager);
ecr::SceneGraphService* FUN_1413f98b0();                                // the scene graph service
efd::Point2* FUN_140a0a600(efd::Point2* pOut, float fX, float fY);
extern Unk_StreamPoint DAT_143b01a60;                                   // the zero point
void* FUN_140a7b840(void* pMap);                                        // npc tree iterator
void* FUN_140a7b8e0(void* pMap, void* pos);
PCBase* FUN_140a7b650(void* pEntry);
void FUN_140a7b860(void* pMap, void** pPos);
void FUN_14098cb80(void* pWalker, NiAVObject* pRoot);                   // scene node walker (56 bytes)
void* FUN_14098e0d0(void* pWalker, int nSkip);
void FUN_14098cf00(void* pWalker);
void* FUN_14098d8d0(const void* pRtti, void* pObject);                  // dynamic cast through an NiRTTI
extern char DAT_143afa7d0;                                              // NiRTTI of the mesh class
void* FUN_140876480(void* pOut, int nCat);
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCat);
void FUN_140980460(void* p);                                            // NiRefObject::IncRefCount
void FUN_1405a93d0(void* p);                                            // NiRefObject::DecRefCount
CStringW FUN_14016a730(const char* sz, int n);                          // narrow text -> CStringW
// The model table entry the npc's data record names (state names and the like).
struct Unk_DbgModelSet { void* m_a; void* m_b; void* m_c; void* m_d; };
void* FUN_141b6f910();
void FUN_141206030(void* pTable, Unk_DbgModelSet* pOut, const egf::EntityID& kKey);
const char* FUN_1408ac310(Unk_DbgModelSet* p);                          // animation name
void FUN_1408a8900(Unk_DbgModelSet* p);
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

// MS2-FUNCTIONAL: the exe expands efd::MemObject::operator new inline (no MemHint temp call)
// @0x141284f80
void UIDebuggingDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_nTargetId = 0;
    m_nMarkerId = 0;
    if (m_spPicker.FUN_141286250(0))
    {
        CMeshUVPicker* pPicker = new (efd::MemHint(efd::MemHint::NONE)) CMeshUVPicker;
        m_spPicker.FUN_1412861e0(pPicker);
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

// MS2-FUNCTIONAL: call-result temporaries and the walker/iterator locals differ from the exe
// @0x141285130
void UIDebuggingDialog::vfunc_33(void* p, float fX, float fY)
{
    UISwfEntity::vfunc_33(p, fX, fY);
    if (vfunc_55() != 0 || m_bPicking == 0 || m_timer.FUN_140868c00() == 0)
        return;
    Unk_DbgCameraMgr* pCamMgr = FUN_1409478c0();
    if (pCamMgr->FUN_140a18070() == 0 || FUN_1413f9850() == 0)
        return;
    efd::Point2 kScreen;
    FUN_140a0a600(&kScreen, fX, fY);
    Unk_NiPoint3 kOrigin(DAT_143b01a60);
    Unk_NiPoint3 kDir(DAT_143b01a60);
    if (!pCamMgr->FUN_140af0520(kScreen, &kOrigin, &kDir))
        return;
    if (FUN_140af2a30(FUN_1413f9850()) == 0)
        return;
    void* pMap = FUN_1403ed2d0()->FUN_141bd36d0();
    bool bFound = false;
    for (void* pos = FUN_140a7b840(pMap); pos != 0 && !bFound; FUN_140a7b860(pMap, &pos))
    {
        Unk_DbgNpc* pNpc = static_cast<Unk_DbgNpc*>(FUN_140a7b650(FUN_140a7b8e0(pMap, pos)));
        if (pNpc == 0)
            continue;
        MS2Ptr<Unk_DbgNpcRec> spData = pNpc->FUN_141093270();
        if (spData.get() == 0)
            continue;
        NiAVObject* pRoot = FUN_1413f98b0()->GetSceneGraphFromEntity(pNpc->FUN_14123c410());
        char walker[56];
        FUN_14098cb80(walker, pRoot);
        for (;;)
        {
            void* pNode = FUN_14098e0d0(walker, 1);
            if (pNode == 0)
                break;
            void* pMesh = FUN_14098d8d0(&DAT_143afa7d0, pNode);
            if (pMesh == 0)
                continue;
            void* pView = FUN_1413f9a70();
            Unk_StreamPoint kHit;
            Unk_StreamPoint kNormal;
            efd::Point2 kUV;
            efd::Point2 kCursor;
            if (FUN_140aadf80()->FUN_141b90e30(&kCursor.x, &kCursor.y) == 0)
            {
                FUN_14098cf00(walker);
                return;
            }
            unsigned nTri;
            if (!m_spPicker.FUN_141286290()->FUN_14147ea50(pMesh, static_cast<Unk_DbgView*>(pView)->FUN_1409a8a60(), kCursor.x,
                                                           kCursor.y, &kHit, &kNormal, &kUV, &nTri, 0))
                continue;
            m_bPicking = 0;
            if (m_nTargetId != 0 || m_nMarkerId != 0)
                FUN_1412860c0();
            m_nTargetId = pNpc->FUN_14123c580();
            Unk_DbgMarker kMarker;
            FUN_140a52ef0(&kMarker);
            reinterpret_cast<CString&>(kMarker.m_pName) = FUN_1401d31f0()->m_strMarkerEffect;
            kMarker.m_nType = pNpc->FUN_141092ff0() == 0 ? 5 : 6;
            FUN_140a53190(&kMarker, pNpc->FUN_14123c580());
            m_nMarkerId = FUN_1403ed280()->FUN_1411a49c0(&kMarker);
            bFound = true;
            FUN_1405a89e0(&kMarker);
            break;
        }
        FUN_14098cf00(walker);
    }
}

// @0x141285690
void UIDebuggingDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_spPicker.FUN_1412861e0(0);
    FUN_1412860c0();
}

// MS2-FUNCTIONAL: the exe keeps every call-result CString in its own frame slot
// @0x1412856d0
void UIDebuggingDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (vfunc_55() != 0)
        return;
    int bClear = 1;
    if (m_nTargetId != 0)
    {
        Unk_DbgNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nTargetId);
        if (pNpc != 0)
        {
            Unk_DbgModelSet kModel;
            FUN_141206030(FUN_141b6f910(), &kModel, pNpc->FUN_14123c460());
            CStringW strNpcName = pNpc->vfunc_77().GetLength() == 0 ? CStringW(L"Noname") : pNpc->vfunc_77();
            FUN_141286050("m_npcName", strNpcName);
            FUN_141286050("m_aniName", FUN_14016a730(FUN_1408ac310(&kModel), 0));
            CStringW strState;
            strState.Format(L"%d", (unsigned __int64)pNpc->FUN_14166c930());
            FUN_141286050("m_state", strState);
            CStringW strSubState;
            strSubState.Format(L"%d", (unsigned __int64)pNpc->FUN_14166cc80());
            FUN_141286050("m_subState", strSubState);
            FUN_141286050("m_aniSpeedCondition", FUN_14016a730(pNpc->FUN_1416713e0(), 0));
            FUN_141286050("m_aniSpeedExpression", FUN_14016a730(pNpc->FUN_141671430(), 0));
            CStringW strMoveSpeed;
            MS2Ptr<Unk_DbgNpcRec> spRec = pNpc->FUN_141093270();
            float fMax = FUN_14028d3a0(spRec->m_fRunSpeed);
            strMoveSpeed.Format(L"%.1f/%.1f", (double)pNpc->vfunc_95(), (double)fMax);
            FUN_141286050("m_moveSpeedS", strMoveSpeed);
            MS2Ptr<Unk_DbgNpcRec> spData = pNpc->FUN_141093270();
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
                strPercent.Format(L"%.1f%%", (double)(pNpc->FUN_1416713c0() * 100.0));
                FUN_141286050("m_aniSpeedPercent", strPercent);
                strPercent.Format(L"%.1f", (double)spData->m_fAniSpeed);
                FUN_141286050("m_aniSpeed", strPercent);
                FUN_141286050("m_aniSpeedFix", CStringW(L"false"));
            }
            bClear = 0;
            m_bClear = 0;
            FUN_1408a8900(&kModel);
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
        if (FUN_1403ed280() != 0)
            FUN_1403ed280()->FUN_1411a6060(m_nMarkerId);
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
