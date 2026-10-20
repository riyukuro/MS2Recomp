// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIChaosLightDialog (debug dialog for the chaos light
// effect) and the ChaosLightEffect runtime effect (ChaosLightEffectParam ctor/copy, node walker, effect registry walk).
// MS2-UNIT: ?\uichaoslightdialog.cpp
// MS2-RANGE: 0x141040a30-0x1410459c0 .text$mn
// MS2-RANGE: 0x1400e4b90-0x1400e4c80 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GUIChaosLightDialog@@UEAAPEAXI@Z 0x141041330 ; unique
// MS2-PIN: ?vfunc_48@UIChaosLightDialog@@UEAAHXZ 0x141041370 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$SmartPointer@VNiAVObject@@@efd@@@?$vector@V?$SmartPointer@VNiAVObject@@@efd@@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@2@@std@@AEAAXAEBV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x141042860 ; unique
// MS2-PIN: ??$_Uninitialized_copy@PEAV?$SmartPointer@VNiAVObject@@@efd@@PEAV12@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@2@@std@@YAPEAV?$SmartPointer@VNiAVObject@@@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@2@@Z 0x141042ce0 ; unique
// MS2-PIN: ??$_Uninitialized_move@PEAV?$SmartPointer@VNiAVObject@@@efd@@PEAV12@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@2@@std@@YAPEAV?$SmartPointer@VNiAVObject@@@efd@@QEAV12@0PEAV12@AEAV?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@2@@Z 0x141042e40 ; unique
// MS2-PIN: ?destroy@?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@QEAAXPEAV?$SmartPointer@VNiAVObject@@@2@@Z 0x141043110 ; unique
// MS2-PIN: ??$emplace_back@AEBV?$SmartPointer@VNiAVObject@@@efd@@@?$vector@V?$SmartPointer@VNiAVObject@@@efd@@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@2@@std@@QEAAXAEBV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x141043130 ; unique
// MS2-PIN: ??1?$vector@V?$SmartPointer@VNiAVObject@@@efd@@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@2@@std@@QEAA@XZ 0x141043980
// MS2-PIN: ?vfunc_12@ChaosLightEffect@@UEAAHXZ 0x141044440 ; unique
// MS2-PIN: ?GetRTTI@ChaosLightEffect@@UEBAPEBVNiRTTI@@XZ 0x141044490 ; unique
// MS2-PINS-END tplpin
// MS2-FUNCTIONAL 0x141042690: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (frame differs) - STL version, not a type error
// MS2-FUNCTIONAL 0x1410426c0: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (frame differs) - STL version, not a type error
// MS2-FUNCTIONAL 0x141042b60: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (callee count 7 vs exe 5) - STL version, not a type error
// MS2-FUNCTIONAL 0x141043050: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (callee count 2 vs exe 3) - STL version, not a type error
// MS2-FUNCTIONAL 0x1410430a0: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (callee count 2 vs exe 3) - STL version, not a type error
// MS2-FUNCTIONAL 0x1410430f0: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (leaf vs non-leaf)) - STL version, not a type error
// MS2-FUNCTIONAL 0x141043100: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (leaf vs non-leaf)) - STL version, not a type error
// MS2-FUNCTIONAL 0x1410432e0: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (callee count 1 vs exe 3) - STL version, not a type error
// MS2-FUNCTIONAL 0x1410438c0: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (callee count 3 vs exe 2) - STL version, not a type error
// MS2-FUNCTIONAL 0x141043950: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (frame differs) - STL version, not a type error
// MS2-FUNCTIONAL 0x141043980: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (callee count 2 vs exe 1) - STL version, not a type error
// MS2-FUNCTIONAL 0x1410451c0: efd::CustomAllocator body of the game's Gamebryo build (out-of-line MemHint ctor 0x140876480 + efd::_Malloc/_Free); the GB SDK header inlines it differently (callees differ: 0x140876480, 0x14206ac20) - SDK version, not a type error
// MS2-FUNCTIONAL 0x1410451f0: efd::CustomAllocator body of the game's Gamebryo build (out-of-line MemHint ctor 0x140876480 + efd::_Malloc/_Free); the GB SDK header inlines it differently (callees differ: 0x140876480, 0x14206ac20) - SDK version, not a type error
// MS2-FUNCTIONAL 0x141045550: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (callees differ: 0x141045580) - STL version, not a type error
// MS2-FUNCTIONAL 0x141045580: efd::CustomAllocator body of the game's Gamebryo build (out-of-line MemHint ctor 0x140876480 + efd::_Malloc/_Free); the GB SDK header inlines it differently (callees differ: 0x14206ab60) - SDK version, not a type error
// MS2-FUNCTIONAL 0x1410455b0: efd::CustomAllocator body of the game's Gamebryo build (out-of-line MemHint ctor 0x140876480 + efd::_Malloc/_Free); the GB SDK header inlines it differently (callees differ: 0x14206ab60) - SDK version, not a type error
// MS2-FUNCTIONAL 0x141045760: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (leaf vs non-leaf)) - STL version, not a type error
// MS2-FUNCTIONAL 0x1410457c0: MSVC STL internals of the exe's toolchain for list/vector over efd::CustomAllocator differ from the VS2017 headers we build with (callee count 1 vs exe 2) - STL version, not a type error
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1410426c0
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@QEAA@XZ 0x1410436b0
// MS2-PIN: ??$destroy@PEAU?$_List_node@PEAVNiAVObject@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@PEAPEAU?$_List_node@PEAVNiAVObject@@PEAX@1@@Z 0x1410430f0
// MS2-PIN: ??0?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@QEAA@XZ 0x1410436f0
// MS2-PIN: ??0?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@QEAA@XZ 0x141043700
// MS2-PIN: ??1?$_List_alloc@U?$_List_base_types@PEAVNiAVObject@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@@std@@QEAA@XZ 0x1410438c0
// MS2-PIN: ??1?$_List_buy@PEAVNiAVObject@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@QEAA@XZ 0x1410438f0
// MS2-PIN: ?allocate@?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@QEAAPEAV?$SmartPointer@VNiAVObject@@@2@_KPEBX@Z 0x1410451f0
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@PEAU?$_List_node@PEAVNiAVObject@@PEAX@2@_K@Z 0x141045550
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@QEAAXPEAU?$_List_node@PEAVNiAVObject@@PEAX@std@@_K@Z 0x141045580
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@V?$_List_val@U?$_List_simple_types@PEAVNiAVObject@@@std@@@std@@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141042690
// MS2-PIN: ??$construct@PEAU?$_List_node@PEAVNiAVObject@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@PEAPEAU?$_List_node@PEAVNiAVObject@@PEAX@1@AEAPEAU41@@Z 0x141043000
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@QEAAPEAU?$_List_node@PEAVNiAVObject@@PEAX@std@@_KPEBX@Z 0x1410451c0
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$SmartPointer@VNiAVObject@@@efd@@@?$vector@V?$SmartPointer@VNiAVObject@@@efd@@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@2@@std@@QEAAPEAV?$SmartPointer@VNiAVObject@@@efd@@QEAV23@AEBV23@@Z 0x141042920
// MS2-PIN: ??$_Freenode0@V?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@@?$_List_node@PEAVNiAVObject@@PEAX@std@@SAXAEAV?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@PEAU01@@Z 0x141042b60
// MS2-PIN: ??$construct@V?$SmartPointer@VNiAVObject@@@efd@@AEAV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@PEAV?$SmartPointer@VNiAVObject@@@3@AEAV43@@Z 0x141043050
// MS2-PIN: ??$construct@V?$SmartPointer@VNiAVObject@@@efd@@AEBV12@@?$_Normal_allocator_traits@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@@std@@SAXAEAV?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@PEAV?$SmartPointer@VNiAVObject@@@3@AEBV43@@Z 0x1410430a0
// MS2-PIN: ??$destroy@PEAVNiAVObject@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_List_node@PEAVNiAVObject@@PEAX@std@@@efd@@PEAPEAVNiAVObject@@@Z 0x141043100
// MS2-PIN: ??0?$_List_buy@PEAVNiAVObject@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@QEAA@XZ 0x1410432e0
// MS2-PIN: ??1?$list@PEAVNiAVObject@@@efd@@QEAA@XZ 0x141043950
// MS2-PIN: ?_Buynode0@?$_List_alloc@U?$_List_base_types@PEAVNiAVObject@@V?$CustomAllocator@PEAVNiAVObject@@@efd@@@std@@@std@@QEAAPEAU?$_List_node@PEAVNiAVObject@@PEAX@2@PEAU32@0@Z 0x141044810
// MS2-PIN: ?_Reallocate_exactly@?$vector@V?$SmartPointer@VNiAVObject@@@efd@@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@2@@std@@AEAAX_K@Z 0x141044f10
// MS2-PIN: ?deallocate@?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@QEAAXPEAV?$SmartPointer@VNiAVObject@@@2@_K@Z 0x1410455b0
// MS2-PIN: ?max_size@?$_Normal_allocator_traits@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@@std@@SA_KAEBV?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@efd@@@Z 0x141045760
// MS2-PIN: ?push_back@?$vector@V?$SmartPointer@VNiAVObject@@@efd@@V?$CustomAllocator@V?$SmartPointer@VNiAVObject@@@efd@@@2@@std@@QEAAXAEBV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x1410457c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uichaoslightdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uichaoslightdialog.h"

#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/worldservice.h"
#include <efd/MemoryDefines.h>
#include <list>
#include <map>
#include <NiNode.h>
#include <NiMesh.h>
#include <NiTexturingProperty.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
class Unk_GameClock { public: double FUN_141473280(); };
Unk_GameClock* FUN_14086d260();
WorldService* FUN_1403ed2d0();

void* FUN_14098d8d0(const void* pRtti, void* pObject);                 // dynamic cast through an NiRTTI (NULL-safe)
extern char DAT_143ad1588;                                              // RTTI of the effect node (Unk_EffectNode)
extern char DAT_143af8a10;                                              // RTTI of the texture map controller
struct Unk_MaterialTable;
struct Unk_MaterialEntry;
extern Unk_MaterialTable DAT_143d69198;
const NiMaterial* FUN_140a17cd0(NiMesh* pMesh);                         // the mesh's active material
Unk_MaterialEntry* FUN_140a17af0(Unk_MaterialTable* pTable, const NiMaterial* pMaterial);   // table lookup, NULL-safe
int FUN_140ef4dd0(Unk_MaterialEntry* pEntry);                           // the entry's material kind (1..3: chaos kinds)

// A controller that animates one map of a texturing property (the map pointer sits at +0x58).
struct Unk_MapController
{
    char m_pad_00[0x58];
    NiTexturingProperty::Map* m_pMap;
    // @0x141044480
    NiTexturingProperty::Map* FUN_141044480() { return m_pMap; }
};

// The effect node (EffectNode, 400 bytes): the walker skips the subtrees of the ones with mode 1.
struct Unk_EffectNodeView
{
    char m_pad_00[0x17c];
    int m_nMode;
    // @0x1410444a0
    int FUN_1410444a0() { return m_nMode; }
};

// CEffect's run-time type test (the effects are NiRefObject-based; the helpers are inline COMDATs of this obj).
struct Unk_EffectCast
{
    // @0x141044660
    static bool FUN_141044660(CEffect* pEffect, const NiRTTI* pRTTI)
    {
        const NiRTTI* pCur = pEffect->GetRTTI();
        while (pCur)
        {
            if (pCur == pRTTI)
                return true;
            pCur = pCur->GetBaseRTTI();
        }
        return false;
    }
    // @0x141044370
    static CEffect* FUN_141044370(CEffect* pEffect, const NiRTTI* pRTTI)
    {
        return FUN_141044660(pEffect, pRTTI) ? pEffect : 0;
    }
    // @0x1410443c0
    static CEffect* FUN_1410443c0(const NiRTTI* pRTTI, CEffect* pEffect)
    {
        if (pEffect == 0)
            return 0;
        return FUN_141044370(pEffect, pRTTI);
    }
};

// The effect manager singleton (0x1403ed280): +0x48 holds the live effects, grouped by owner.
struct Unk_EffectGroup;
typedef std::list<NiPointer<CEffect> > Unk_EffectList;
struct Unk_EffectGroup
{
    void* m_unk_00;
    Unk_EffectList m_listEffects;                                       // +0x08
    // @0x141044280
    Unk_EffectList::iterator FUN_141044280() { return m_listEffects.begin(); }
    // @0x1410443f0
    Unk_EffectList::iterator FUN_1410443f0() { return m_listEffects.end(); }
};
typedef std::map<unsigned int, Unk_EffectGroup*> Unk_EffectGroupMap;
class Unk_EffectMgr
{
public:
    // @0x141044430
    Unk_EffectGroupMap* FUN_141044430() { return &m_mapGroups; }
    char m_pad_00[0x48];
    Unk_EffectGroupMap m_mapGroups;                                     // +0x48
};
Unk_EffectMgr* FUN_1403ed280();

// The statics the "apply" checkbox drives (0x143acd310 flag, 0x143acd330 the edited param).
static ChaosLightEffectParam s_defaultParam;                            // @0x1400e4b90
static CString s_strSkill1("skill");                                    // @0x1400e4bc0
static CString s_strStun1("stun");                                      // @0x1400e4bf0
static CString s_strSkill2("skill");                                    // @0x1400e4c20
static CString s_strStun2("stun");                                      // @0x1400e4c50
static bool s_bApply;

// @0x141040a30
UIChaosLightDialog::UIChaosLightDialog()
{
    m_40 = 1;
    m_spParam.AssignRaw(new ChaosLightEffectParam);
}

// @0x141040af0
UIChaosLightDialog::~UIChaosLightDialog()
{
}

// @0x141040b40
CString UIChaosLightDialog::vfunc_1()
{
    return "ChaosLightDialog";
}

// @0x141040b90
void UIChaosLightDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASObj obj(2);
    const ChaosLightEffectParam* pParam = FUN_141041e90();
    obj.FUN_1409c4a30("boost", pParam->m_fFresnelBoost);
    obj.FUN_1409c4a30("exponent", pParam->m_fFresnelExponent);
    obj.FUN_1409c4a30("dimmer", pParam->m_fDimmer);
    obj.FUN_1409c4a30("r", pParam->m_fRed);
    obj.FUN_1409c4a30("g", pParam->m_fGreen);
    obj.FUN_1409c4a30("b", pParam->m_fBlue);
    obj.FUN_1407cbbe0("apply", FUN_1410420c0());
    m_30->Invoke("initData", obj.FUN_1422bb870());
}

// @0x141040d20
int UIChaosLightDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onCheckApply", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            bool bApply = data.FUN_1422b8a90();
            FUN_1410411e0(bApply);
        }
        return 1;
    }
    else if (_stricmp("onChangeSliderBoost", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_spParam->m_fFresnelBoost = data.FUN_1422b8c10();
        return 1;
    }
    else if (_stricmp("onChangeSliderExponent", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_spParam->m_fFresnelExponent = data.FUN_1422b8c10();
        return 1;
    }
    else if (_stricmp("onChangeSliderDimmer", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_spParam->m_fDimmer = data.FUN_1422b8c10();
        return 1;
    }
    else if (_stricmp("onChangeSliderRed", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_spParam->m_fRed = data.FUN_1422b8c10();
        return 1;
    }
    else if (_stricmp("onChangeSliderGreen", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_spParam->m_fGreen = data.FUN_1422b8c10();
        return 1;
    }
    else if (_stricmp("onChangeSliderBlue", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_spParam->m_fBlue = data.FUN_1422b8c10();
        return 1;
    }
    return 0;
}

// @0x1410411e0
void UIChaosLightDialog::FUN_1410411e0(bool bApply)
{
    FUN_1410420a0(bApply);
    if (bApply)
        FUN_141041ea0(m_spParam.get());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1410415b0
ChaosLightEffectParam::ChaosLightEffectParam()
    : TransitionEffectParam(0xe)
    , m_nLayer(0)
{
    m_fFresnelBoost = 26.09f;
    m_fFresnelExponent = 5.36f;
    m_fDimmer = 0.0f;
    m_fRed = 0.95f;
    m_fGreen = 0.57f;
    m_fBlue = 0.22f;
    m_bBlink = false;
    m_nBlinkBoostStart = 0;
}

// @0x141043a30
ChaosLightEffectParam& ChaosLightEffectParam::FUN_141043a30(const ChaosLightEffectParam& rSrc)
{
    TransitionEffectParam::operator=(rSrc);
    m_fFresnelBoost = rSrc.m_fFresnelBoost;
    m_fFresnelExponent = rSrc.m_fFresnelExponent;
    m_fDimmer = rSrc.m_fDimmer;
    m_fRed = rSrc.m_fRed;
    m_fGreen = rSrc.m_fGreen;
    m_fBlue = rSrc.m_fBlue;
    m_nLayer = rSrc.m_nLayer;
    m_bBlink = rSrc.m_bBlink;
    m_nBlinkBoostStart = rSrc.m_nBlinkBoostStart;
    m_strNode = rSrc.m_strNode;
    return *this;
}

// @0x141043760
Unk_NodeWalker::Unk_NodeWalker(NiAVObject* pRoot)
    : m_list(10)
{
    FUN_1410447b0(pRoot);
}

// @0x1410439e0
Unk_NodeWalker::~Unk_NodeWalker()
{
}

// @0x141044210
void Unk_NodeWalker::FUN_141044210(NiNode* pNode)
{
    int nCount = pNode->GetArrayCount();
    for (int i = 0; i < nCount; i++)
    {
        NiAVObject* pChild = pNode->GetAt(i);
        if (pChild)
            m_list.AddTail(pChild);
    }
}

// @0x1410446c0
NiAVObject* Unk_NodeWalker::FUN_1410446c0(bool bChildren)
{
    if (m_list.IsEmpty())
        return NULL;
    NiAVObject* pObject = m_list.RemoveHead();
    if (FUN_14098d8d0(&DAT_143ad1588, pObject) && ((Unk_EffectNodeView*)pObject)->FUN_1410444a0() == 1)
        return FUN_1410446c0(bChildren);
    if (bChildren)
    {
        NiNode* pNode = (NiNode*)FUN_14098d8d0(&NiNode::ms_RTTI, pObject);
        if (pNode)
            FUN_141044210(pNode);
    }
    return pObject;
}

// @0x1410447b0
void Unk_NodeWalker::FUN_1410447b0(NiAVObject* pRoot)
{
    m_list.RemoveAll();
    m_list.AddTail(pRoot);
}

// @0x1410416a0
ChaosLightEffect::ChaosLightEffect()
{
    m_dStartTime2 = 0;
    m_dLastTick = 0;
    m_dPhase = 0;
    m_bBlinkOn = false;
}

// @0x141041750
ChaosLightEffect::~ChaosLightEffect()
{
}

// @0x1410417c0
bool ChaosLightEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!TransitionEffect::vfunc_3(pParam, pTarget))
        return false;
    const ChaosLightEffectParam* pUse = static_cast<const ChaosLightEffectParam*>(pParam);
    GameObject* pObject = pTarget->FUN_140a533b0();
    if (!pObject)
        return false;
    efd::list<NiAVObject*> listNodes;
    pObject->vfunc_44(&listNodes);
    m_vecObjects.clear();
    m_vecObjects.reserve(listNodes.size());
    for (efd::list<NiAVObject*>::iterator it = listNodes.begin(); it != listNodes.end(); ++it)
    {
        if (*it)
        {
            NiAVObjectPtr spNode(*it);
            m_vecObjects.push_back(spNode);
        }
    }
    if (s_bApply)
        pUse = &s_defaultParam;
    m_dStartTime = FUN_14086d260()->FUN_141473280() + pUse->m_fStartDelay;
    m_fDuration = pUse->m_fDuration;
    m_b2c = pUse->m_b30;
    m_param.FUN_141043a30(*pUse);
    if (pUse->m_fStartDelay == 0.0f)
        vfunc_4();
    return true;
}

// @0x1410419e0
void ChaosLightEffect::vfunc_4()
{
    m_b2e = true;
    MS2_FOR_EACH(NiAVObjectPtr spNode, m_vecObjects)
        FUN_1410423d0(spNode);
    m_dStartTime2 = FUN_14086d260()->FUN_141473280();
}

// @0x141041ae0
void ChaosLightEffect::vfunc_7()
{
    m_b2e = false;
    for (unsigned int i = 0; i < m_arrLayers.GetCount(); i++)
    {
        ChaosLightEffectLayer* pLayer = m_arrLayers[i];
        FUN_1403ed2d0()->FUN_141bd3680()->RemoveLayer(pLayer);
    }
    MS2_FOR_EACH(NiAVObjectPtr spNode, m_vecObjects)
        spNode->UpdateProperties();
}

// @0x141041c20
void ChaosLightEffect::vfunc_13(TransitionData* pFrom, TransitionData* pTo, float fT)
{
    ChaosLightTransitionData* pA = static_cast<ChaosLightTransitionData*>(pFrom);
    ChaosLightTransitionData* pB = static_cast<ChaosLightTransitionData*>(pTo);
    m_param.m_fFresnelBoost = pA->m_fFresnelBoost + fT * (pB->m_fFresnelBoost - pA->m_fFresnelBoost);
    m_param.m_fFresnelExponent = pA->m_fFresnelExponent + fT * (pB->m_fFresnelExponent - pA->m_fFresnelExponent);
    m_param.m_fDimmer = pA->m_fDimmer + fT * (pB->m_fDimmer - pA->m_fDimmer);
    m_param.m_fRed = pA->m_fRed + fT * (pB->m_fRed - pA->m_fRed);
    m_param.m_fGreen = pA->m_fGreen + fT * (pB->m_fGreen - pA->m_fGreen);
    m_param.m_fBlue = pA->m_fBlue + fT * (pB->m_fBlue - pA->m_fBlue);
    for (unsigned int i = 0; i < m_arrLayers.GetCount(); i++) {
        ChaosLightEffectLayer* pLayer = m_arrLayers[i];
        pLayer->FUN_141046410(m_param);
    }
}

// @0x141041e50
bool ChaosLightEffect::vfunc_9()
{
    if (m_param.m_bBlink)
        FUN_1410420d0();
    return TransitionEffect::vfunc_9();
}

// @0x141041e90
const ChaosLightEffectParam* FUN_141041e90()
{
    return &s_defaultParam;
}

#ifndef MS2_HOOK_DLL
// @0x141041ea0
// Store the edited param as the override and push it to every live chaos light effect.
void FUN_141041ea0(const ChaosLightEffectParam* pParam)
{
    s_defaultParam.FUN_141043a30(*pParam);
    if (!s_bApply)
        return;
    Unk_EffectGroupMap* pMap = FUN_1403ed280()->FUN_141044430();
    for (Unk_EffectGroupMap::iterator itGroup = pMap->begin(); itGroup != pMap->end(); ++itGroup)
    {
        Unk_EffectGroup* pGroup = itGroup->second;
        for (Unk_EffectList::iterator itEffect = pGroup->FUN_141044280(); itEffect != pGroup->FUN_1410443f0(); ++itEffect)
        {
            NiPointer<ChaosLightEffect> spEffect(static_cast<ChaosLightEffect*>(Unk_EffectCast::FUN_1410443c0(&ChaosLightEffect::ms_RTTI, *itEffect)));
            NiPointer<ChaosLightEffect>& rEffect = spEffect;
            if (!rEffect)
                continue;
            for (unsigned int i = 0; i < rEffect->m_arrLayers.GetCount(); i++)
            {
                ChaosLightEffectLayer* pLayer = rEffect->m_arrLayers[i];
                pLayer->FUN_141046410(*pParam);
                FUN_1403ed2d0()->FUN_141bd3680()->Refresh(pLayer);
            }
        }
    }
}
#endif

#ifndef MS2_HOOK_DLL
// @0x1410420a0
void FUN_1410420a0(bool bApply)
{
    s_bApply = bApply;
}
#endif

#ifndef MS2_HOOK_DLL
// @0x1410420c0
bool FUN_1410420c0()
{
    return s_bApply;
}
#endif

// @0x1410420d0
// Blink: the colour toggles between black and the current colour, the phase speeds up after blinkBoostStart seconds.
void ChaosLightEffect::FUN_1410420d0()
{
    ChaosLightEffectParam kParam;
    kParam.FUN_141043a30(m_param);
    double dNow = FUN_14086d260()->FUN_141473280();
    float fDelta = (float)(dNow - m_dLastTick);
    m_dLastTick = dNow;
    if (m_param.m_nBlinkBoostStart > 0 && (double)m_param.m_nBlinkBoostStart < dNow - m_dStartTime2)
    {
        float fBoost = (float)((dNow - m_dStartTime2) - (float)m_param.m_nBlinkBoostStart) + 3.0f;
        m_dPhase += (double)(fDelta * fBoost);
    }
    else
        m_dPhase += (double)(fDelta * 3.0f);
    if (1.0 < m_dPhase)
    {
        m_bBlinkOn = !m_bBlinkOn;
        m_dPhase = 0;
    }
    if (m_bBlinkOn)
    {
        kParam.m_fRed = m_param.m_fRed;
        kParam.m_fGreen = m_param.m_fGreen;
        kParam.m_fBlue = m_param.m_fBlue;
    }
    else
        kParam.m_fRed = kParam.m_fGreen = kParam.m_fBlue = 0;
    for (unsigned int i = 0; i < m_arrLayers.GetCount(); i++) {
        ChaosLightEffectLayer* pLayer = m_arrLayers[i];
        pLayer->FUN_141046410(kParam);
    }
}

// @0x1410423d0
// Put a chaos light layer on every mesh below spObject that has a chaos material and whose glow map no controller drives.
void ChaosLightEffect::FUN_1410423d0(NiAVObjectPtr spObject)
{
    if (spObject == NULL)
        return;
    Unk_NodeWalker kWalker(spObject);
    NiAVObject* pObject;
    while ((pObject = kWalker.FUN_1410446c0(true)) != NULL)
    {
        NiMesh* pMesh = (NiMesh*)FUN_14098d8d0(&NiMesh::ms_RTTI, pObject);
        if (pMesh)
        {
        Unk_MaterialEntry* pEntry = FUN_140a17af0(&DAT_143d69198, FUN_140a17cd0(pMesh));
        if (!pEntry || FUN_140ef4dd0(pEntry) == 0)
            continue;
        NiProperty* pTexturing = pMesh->GetProperty(NiProperty::TEXTURING);
        if (pTexturing)
        {
            NiTexturingProperty::Map* pGlowMap = static_cast<NiTexturingProperty*>(pTexturing)->GetGlowMap();
            if (pGlowMap)
            {
                bool bDriven = false;
                NiTimeController* pCtrl = pTexturing->GetControllers();
                while (pCtrl)
                {
                    Unk_MapController* pMapCtrl = (Unk_MapController*)FUN_14098d8d0(&DAT_143af8a10, pCtrl);
                    pCtrl = pCtrl->GetNext();
                    if (pMapCtrl && pGlowMap == pMapCtrl->FUN_141044480())
                    {
                        bDriven = true;
                        break;
                    }
                }
                if (bDriven)
                    continue;
            }
        }
        ChaosLightEffectLayerManager* pManager = FUN_1403ed2d0()->FUN_141bd3680();
        ChaosLightEffectLayer* pLayer = new (efd::MemHint(efd::MemHint::NONE))
            ChaosLightEffectLayer(pMesh, pManager->FUN_1410469c0(), &m_param);
        pManager->AddLayer(pLayer);
        NiPointer<ChaosLightEffectLayer> spLayer(pLayer);
        m_arrLayers.Add(spLayer);
        }
    }
    spObject->UpdateProperties();
}

// @0x141041490
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

MS2_REPLACE_METHOD(0x141040B40, UIChaosLightDialog, vfunc_1, 61, 0x55C7BAFE);
MS2_REPLACE_METHOD(0x141040B90, UIChaosLightDialog, OnLoadComplete, 389, 0xC4F956FC);
MS2_REPLACE_METHOD(0x141040D20, UIChaosLightDialog, vfunc_28, 1166, 0xB0797E63);
MS2_REPLACE_METHOD(0x1410411E0, UIChaosLightDialog, FUN_1410411e0, 64, 0x8A3224F6);
MS2_REPLACE_METHOD(0x141043A30, ChaosLightEffectParam, FUN_141043a30, 270, 0xE2E1D133);
MS2_REPLACE_METHOD(0x141044210, Unk_NodeWalker, FUN_141044210, 110, 0x1E0CF115);
MS2_REPLACE_METHOD(0x1410446C0, Unk_NodeWalker, FUN_1410446c0, 176, 0x1AA4469C);
MS2_REPLACE_METHOD(0x1410447B0, Unk_NodeWalker, FUN_1410447b0, 50, 0x33965F07);
MS2_REPLACE_METHOD(0x1410419E0, ChaosLightEffect, vfunc_4, 246, 0x59ADE1A6);
MS2_REPLACE_METHOD(0x141041AE0, ChaosLightEffect, vfunc_7, 307, 0x9E354AEA);
MS2_REPLACE_METHOD(0x141041C20, ChaosLightEffect, vfunc_13, 540, 0x2DCE3D62);
MS2_REPLACE_METHOD(0x141041E50, ChaosLightEffect, vfunc_9, 50, 0x6D5BDC9F);
MS2_REPLACE_METHOD(0x1410420D0, ChaosLightEffect, FUN_1410420d0, 747, 0x30F00AC9);
