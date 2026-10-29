// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMasteryObjectMark: see uimasteryobjectmark.h.
// MS2-UNIT: ?\uimasteryobjectmark.cpp
// MS2-RANGE: 0x140e59a00-0x140e5db70 .text$mn
// MS2-PIN: ??1EntityContext@UIMasteryObjectMark@@UEAA@XZ 0x140e5c4c0 ; the exe dtor has no vptr store (implicit)
// The exe's 12-byte point copies are plain rep movsb (no /Oi expansion); the pragma must precede the inline copies.
#pragma function(memcpy, memset)
#define NOMINMAX                        // NxPhysics (interactobject.h)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimasteryobjectmark.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uimasteryobjectmark.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cmasterymanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/masterytable.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/interactobject.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (names describe uses) ----
class Unk_SSGWorld
{
public:
    MS2Ptr<CInteractObject> FUN_141bc66b0(const CString& strName);   // find a field object by name
    PCBase* FUN_141bd0cc0();                                    // the local player actor
};
Unk_SSGWorld* FUN_1403ed2d0();
class Unk_MmCubeService
{
public:
    MS2Ptr<CFunctionCubeObject> FUN_141230c00(CString strName); // a cube by its id (by value: the callee destroys it)
};
Unk_MmCubeService* FUN_1409670b0();
class Unk_CameraHousing;
Unk_CameraHousing* FUN_1409670e0();
unsigned char FUN_1410c35c0(void* pHousing);                    // the camera housing mode is active
CMasteryTable* FUN_1409670c0();
__int64 FUN_141656ad0(PCBase* pActor);                          // the actor's account id
unsigned FUN_141662750(PCBase* pActor, int nType);              // the actor's mastery exp of a type
class Unk_McPc : public PCBase
{
public:
    int FUN_1416595b0();                                        // the actor is riding
};
class Unk_HmCube
{
public:
    MS2Ptr<FunctionCubeData> FUN_140ca6580();                   // the cube's table row
};
class Unk_QgCamera { public: bool FUN_140af0700(const Vector3& ptWorld, Vector3& rptScreen); };
Unk_QgCamera* FUN_1409478c0();
class Unk_QgUIScale;
Unk_QgUIScale* FUN_14025e7a0();
float FUN_1422afec0(Unk_QgUIScale* pScale, int nMovie);
int FUN_141277f40();
float FUN_1412762d0(const Vector3& pt);                 // the screen y offset of a world point
int FUN_1408a1360(Vector3 a, Vector3 b);        // the two points are on the same side
class Unk_AuCfgValue
{
public:
    const float& FUN_140298f40();
    char m_pad[0x58];
};
struct Unk_AuConfig
{
    char m_pad[0xddd0];
    Unk_AuCfgValue m_ddd0;              // +0xddd0 node mark screen offset x
    Unk_AuCfgValue m_de28;              // +0xde28 y
    Unk_AuCfgValue m_de80;              // +0xde80 cube mark screen offset x
    Unk_AuCfgValue m_ded8;              // +0xded8 y
    Unk_AuCfgValue m_df30;
    Unk_AuCfgValue m_df88;
    Unk_AuCfgValue m_dfe0;              // +0xdfe0 the distance the tooltip shows within
};
Unk_AuConfig* FUN_1401d3200();
bool FUN_1409b0390(Scaleform::GFx::Value* pValue);              // the value is undefined
CStringW GetStringCommonByKey(const CStringW& str);                    // the localized text of a string key
CStringTable* GetStringTable();                                  // the string table
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
// The local player's vtable as the slots used here (vfunc_18 returns the position as the engine point type).
class Unk_MomPlayer
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17();
    virtual Vector3 vfunc_18();                 // 0x90 position
};

using namespace ATL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// EntityContext

// @0x140e5c360
UIMasteryObjectMark::EntityContext::EntityContext()
    : m_nShown(0)
    , m_nEnabled(0)
    , m_spEntity(0)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// UIMasteryObjectMark

// @0x140e59a00
UIMasteryObjectMark::UIMasteryObjectMark()
    : m_nodes(17, 0.75f, 0.25f, 2.25f, 10)
    , m_cubes(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_2c = 7;
    m_28 = FUN_141277f40();
    m_58 = 0;
}

// @0x140e59af0
UIMasteryObjectMark::~UIMasteryObjectMark()
{
}

// @0x140e59b60
CString UIMasteryObjectMark::GetTypeName()
{
    return "MasteryObjectMark";
}

// @0x140e59bb0
void UIMasteryObjectMark::FUN_140e59bb0(CInteractObject* pObject)
{
    if (m_30.get() != 0)
    {
        Vector3 pt = pObject->GetPos();
        Scaleform::GFx::Value v = m_30->FUN_140e5bfe0("create", pObject->GetName(), pt.x, pt.y);
        if (!FUN_1409b0390(&v))
        {
            ASGameEntity* pEntity = new ASGameEntity(v, m_28);
            if (pEntity)
            {
                pEntity->vfunc_3(0);
                MS2Ptr<EntityContext> spContext(new EntityContext);
                spContext->m_spEntity.AssignRaw(pEntity);
                m_nodes.SetAt(pObject->GetName(), spContext);
            }
        }
    }
    else
    {
        MS2Ptr<EntityContext> spEmpty(0);
        m_nodes.SetAt(pObject->GetName(), spEmpty);
    }
}

// @0x140e59ea0
void UIMasteryObjectMark::FUN_140e59ea0(CFunctionCubeObject* pCube)
{
    if (m_30.get() != 0)
    {
        Vector3 pt = pCube->FUN_141226d00();
        Scaleform::GFx::Value v = m_30->FUN_140e5bfe0("create", pCube->FUN_141226bd0(), pt.x, pt.y);
        if (!FUN_1409b0390(&v))
        {
            ASGameEntity* pEntity = new ASGameEntity(v, m_28);
            if (pEntity)
            {
                pEntity->vfunc_3(0);
                MS2Ptr<EntityContext> spContext(new EntityContext);
                spContext->m_spEntity.AssignRaw(pEntity);
                m_cubes.SetAt(pCube->FUN_141226bd0(), spContext);
            }
        }
    }
    else
    {
        MS2Ptr<EntityContext> spEmpty(0);
        m_cubes.SetAt(pCube->FUN_141226bd0(), spEmpty);
    }
}

// @0x140e5a190
void UIMasteryObjectMark::vfunc_2()
{
    FUN_1422dbf00(m_2c, 0, 0);
}

// @0x140e5a1c0
void UIMasteryObjectMark::vfunc_3()
{
    m_nodes.RemoveAll();
    m_cubes.RemoveAll();
    UISwfEntity::FUN_1422dc080();
}

// @0x140e5a210
void UIMasteryObjectMark::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    for (POSITION pos = m_nodes.GetStartPosition(); pos; m_nodes.GetNext(pos))
    {
        MS2Ptr<EntityContext> spContext = m_nodes.GetValueAt(pos);
        if (spContext == 0)
        {
            CInteractObject* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_nodes.GetKeyAt(pos));
            if (!pObject)
                continue;
            CInteractGatheringObject* pGather = dynamic_cast<CInteractGatheringObject*>(pObject);
            if (!pGather)
                continue;
            FUN_140e59bb0(pGather);
        }
    }
    for (POSITION pos = m_cubes.GetStartPosition(); pos; m_cubes.GetNext(pos))
    {
        MS2Ptr<EntityContext> spContext = m_cubes.GetValueAt(pos);
        if (spContext == 0)
        {
            CFunctionCubeObject* pCube = FUN_1409670b0()->FUN_141230c00(m_cubes.GetKeyAt(pos));
            if (!pCube)
                continue;
            CHomemadeCubeObject* pHome = dynamic_cast<CHomemadeCubeObject*>(pCube);
            if (!pHome)
                continue;
            FUN_140e59ea0(pHome);
        }
    }
}

// @0x140e5a560
void UIMasteryObjectMark::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_30.IsNull())
        return;
    FUN_140e5a600();
    FUN_140e5ac30();
}

// @0x140e5a5b0
int UIMasteryObjectMark::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    return 0;
}

// @0x140e5a600
void UIMasteryObjectMark::FUN_140e5a600()
{
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPC)
        return;
    POSITION pos = m_nodes.GetStartPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_nodes.GetNext(pos);
        CStringA strKey = m_nodes.GetKeyAt(posCur);
        MS2Ptr<EntityContext> spContext = m_nodes.GetValueAt(posCur);
        if (spContext == 0)
            continue;
        MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc66b0(strKey);
        if (spObject.IsNull())
        {
            FUN_140e5b450(strKey);
            continue;
        }
        if (CInteractGatheringObject* pGather = dynamic_cast<CInteractGatheringObject*>(spObject.operator->()))
        {
            Vector3 ptScreen;
            Vector3 ptWorld = pGather->GetPos().FUN_14097fd50(Vector3(0.0f, 0.0f, 200.0f));
            float fDist = reinterpret_cast<Unk_MomPlayer*>(pPC)->vfunc_18().FUN_140965c40(pGather->GetPos()).FUN_140967ac0();
            if (!FUN_1409478c0()->FUN_140af0700(ptWorld, ptScreen) || 1000.0f < fDist)
            {
                spContext->m_spEntity->vfunc_3(0);
            }
            else
            {
                ptScreen.FUN_140ad0c10(FUN_1422afec0(FUN_14025e7a0(), m_28));
                ptScreen.y += FUN_1412762d0(pGather->GetPos());
                ptScreen.x += FUN_1401d3200()->m_ddd0.FUN_140298f40();
                ptScreen.y += FUN_1401d3200()->m_de28.FUN_140298f40();
                spContext->m_spEntity->FUN_140e5bf20("setPosition", ptScreen.x, ptScreen.y);
                int nShow = (fDist < FUN_1401d3200()->m_dfe0.FUN_140298f40() && pGather->FUN_141402b40() != 0) ? 1 : 0;
                if (FUN_1408a1360(reinterpret_cast<Unk_MomPlayer*>(pPC)->vfunc_18(), pGather->GetPos()) == 0)
                    nShow = 0;
                if (spContext->m_nShown != nShow)
                {
                    spContext->m_spEntity->Invoke("showTooltip", nShow);
                    spContext->m_nShown = nShow;
                }
                if (FUN_140e5b520(pGather, spContext.get()) != 0)
                    FUN_140e5bd80(spContext.get());
                bool bVisible = nShow != 0 ? true : spContext->m_nEnabled != 0;
                if (spContext->m_spEntity->FUN_1422bfca0() != bVisible)
                    spContext->m_spEntity->vfunc_4(bVisible);
            }
        }
        else
        {
            FUN_140e5b450(strKey);
        }
    }
}

// @0x140e5ac30
void UIMasteryObjectMark::FUN_140e5ac30()
{
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPC)
        return;
    if (FUN_1410c35c0(FUN_1409670e0()) != 0)
        return;
    POSITION pos = m_cubes.GetStartPosition();
    while (pos)
    {
        POSITION posCur = pos;
        m_cubes.GetNext(pos);
        CStringA strKey = m_cubes.GetKeyAt(posCur);
        MS2Ptr<EntityContext> spContext = m_cubes.GetValueAt(posCur);
        if (spContext == 0)
            continue;
        MS2Ptr<CFunctionCubeObject> spCube = FUN_1409670b0()->FUN_141230c00(strKey);
        if (spCube.IsNull())
        {
            FUN_140e5b450(strKey);
            continue;
        }
        int nOwnerOk = 1;
        if (static_cast<CHomemadeCubeObject*>(spCube.operator->())->FUN_140e5cc00() == 1)
        {
            if (static_cast<CHomemadeCubeObject*>(spCube.operator->())->FUN_140e5cbf0() != FUN_141656ad0(pPC))
                nOwnerOk = 0;
        }
        MS2Ptr<CHomemadeCubeObject> spHome(dynamic_cast<CHomemadeCubeObject*>(spCube.get()));
        if ((spHome.get() ? true : false) && nOwnerOk != 0)
        {
            Vector3 ptScreen;
            Vector3 ptWorld = spHome->FUN_141226d00().FUN_14097fd50(Vector3(0.0f, 0.0f, 200.0f));
            float fDist = reinterpret_cast<Unk_MomPlayer*>(pPC)->vfunc_18().FUN_140965c40(spHome->FUN_141226d00()).FUN_140967ac0();
            int nRiding = static_cast<Unk_McPc*>(pPC)->FUN_1416595b0() != 0;
            if (!FUN_1409478c0()->FUN_140af0700(ptWorld, ptScreen) || 1000.0f < fDist || nRiding != 0)
            {
                spContext->m_spEntity->vfunc_3(0);
                if (spContext->m_nShown != 0)
                {
                    spContext->m_spEntity->Invoke("showTooltip", 0);
                    spContext->m_nShown = 0;
                }
            }
            else
            {
                ptScreen.FUN_140ad0c10(FUN_1422afec0(FUN_14025e7a0(), m_28));
                ptScreen.y += FUN_1412762d0(spHome->FUN_141226d00());
                ptScreen.x += FUN_1401d3200()->m_de80.FUN_140298f40();
                ptScreen.y += FUN_1401d3200()->m_ded8.FUN_140298f40();
                spContext->m_spEntity->FUN_140e5bf20("setPosition", ptScreen.x, ptScreen.y);
                int nShow = (fDist < FUN_1401d3200()->m_dfe0.FUN_140298f40() && spHome->FUN_141229080() != 0) ? 1 : 0;
                if (FUN_1408a1360(reinterpret_cast<Unk_MomPlayer*>(pPC)->vfunc_18(), spHome->FUN_141226d00()) == 0)
                    nShow = 0;
                if (spContext->m_nShown != nShow)
                {
                    spContext->m_spEntity->Invoke("showTooltip", nShow);
                    spContext->m_nShown = nShow;
                }
                if (FUN_140e5b620(spHome.get(), spContext.get()) != 0)
                    FUN_140e5bd80(spContext.get());
                bool bVisible = nShow != 0 ? 1 : spContext->m_nEnabled != 0;
                if (spContext->m_spEntity->FUN_1422bfca0() != bVisible)
                    spContext->m_spEntity->vfunc_4(bVisible);
            }
        }
        else
        {
            FUN_140e5b450(strKey);
        }
    }
}

// @0x140e5b450
void UIMasteryObjectMark::FUN_140e5b450(const CStringA& strKey)
{
    if (m_30.get() != 0)
    {
        m_30->Invoke("remove", CString(strKey));
        m_nodes.RemoveKey(strKey);
    }
}

// @0x140e5b520
int UIMasteryObjectMark::FUN_140e5b520(CInteractObject* pObject, EntityContext* pContext)
{
    int nChanged = FUN_140e5b720(pObject->GetRow()->m_gathering.m_nReceipeId, pContext);
    CStringW strName = GetStringTable()->FUN_141811980(0xb, pObject->GetRowId());
    if (pContext->m_strObjName != strName)
    {
        pContext->m_strObjName = strName;
        nChanged = 1;
    }
    return nChanged;
}

// @0x140e5b620
int UIMasteryObjectMark::FUN_140e5b620(CFunctionCubeObject* pCube, EntityContext* pContext)
{
    int nChanged = FUN_140e5b720(reinterpret_cast<Unk_HmCube*>(pCube)->FUN_140ca6580()->m_n100, pContext);
    CStringW strName = GetStringTable()->FUN_141811980(1, pCube->FUN_141226cd0());
    if (pContext->m_strObjName != strName)
    {
        pContext->m_strObjName = strName;
        nChanged = 1;
    }
    return nChanged;
}

// @0x140e5b720
unsigned UIMasteryObjectMark::FUN_140e5b720(int nReceipeId, EntityContext* pContext)
{
    MS2Ptr<CMasteryReceipe> spReceipe = FUN_1409670c0()->Find(nReceipeId);
    if (spReceipe.IsNull())
        return 0;
    CStringW strType;
    CStringW strProp;
    CStringW strStatus;
    int nEnabled = 1;
    if (CMasteryManager::GetInstance()->FUN_140b6d470(nReceipeId) == 0)
    {
        int nLimit = FUN_1409670c0()->LimitState(nReceipeId);
        switch (nLimit)
        {
        case 0:
            strProp = GetStringCommonByKey(L"s_mastery_mark_success_prop_high");
            break;
        case 1:
            strProp = GetStringCommonByKey(L"s_mastery_mark_success_prop_normal");
            break;
        case 3:
            strProp = GetStringCommonByKey(L"s_mastery_mark_success_prop_zero");
            break;
        case 2:
            strProp = GetStringCommonByKey(L"s_mastery_mark_success_prop_low");
            break;
        }
        switch (spReceipe->m_nType)
        {
        case 4:
            strType = L"gathering";
            break;
        case 3:
            strType = L"mining";
            break;
        case 5:
            strType = L"breeding";
            break;
        case 6:
            strType = L"farming";
            break;
        }
        PCBase* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC)
        {
            int nLevel = FUN_141662750(pPC, spReceipe->m_nType);
            int nFactor = FUN_1409670c0()->Factor(nReceipeId, nLevel);
            strStatus = FUN_1409670c0()->DifferentialName(nReceipeId, FUN_141662750(pPC, spReceipe->m_nType));
            if (nFactor == 0)
                strStatus = "disable";
            nEnabled = (nFactor != 0 && nLimit != 3) ? 1 : 0;
        }
    }
    else
    {
        strProp = GetStringCommonByKey(L"s_mastery_mark_success_prop_lack_mastery");
        strStatus = L"impossible";
        strType = L"lock";
        nEnabled = 0;
    }
    unsigned nChanged = 0;
    if (pContext->m_strType != strType)
    {
        pContext->m_strType = strType;
        nChanged = 1;
    }
    if (pContext->m_strProp != strProp)
    {
        pContext->m_strProp = strProp;
        nChanged = 1;
    }
    if (pContext->m_strStatus != strStatus)
    {
        pContext->m_strStatus = strStatus;
        nChanged = 1;
    }
    if (pContext->m_nEnabled != nEnabled)
    {
        pContext->m_nEnabled = nEnabled;
        nChanged = 1;
    }
    return nChanged;
}

// @0x140e5bd80
void UIMasteryObjectMark::FUN_140e5bd80(EntityContext* pContext)
{
    ASObj obj(m_28);
    obj.FUN_1407cbb20("objName", pContext->m_strObjName);
    obj.FUN_1407cbb20("prop", pContext->m_strProp);
    obj.FUN_1407cbb20("status", pContext->m_strStatus);
    obj.FUN_1407cbb20("type", pContext->m_strType);
    pContext->m_spEntity->Invoke("setData", obj);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COMDAT glue

// @0x140e5bf20
inline Scaleform::GFx::Value AScript::FUN_140e5bf20(const char* szMethod, float a1, float a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcd70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140e5bfe0
inline Scaleform::GFx::Value AScript::FUN_140e5bfe0(const char* szMethod, CString a1, float a2, float a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce70(args.FUN_1409b1f70(0), (const char*)a1);
    FUN_1422bcd70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcd70(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140e5cbf0
__int64 CHomemadeCubeObject::FUN_140e5cbf0()
{
    return m_nArg2;
}

// @0x140e5cc00
int CHomemadeCubeObject::FUN_140e5cc00()
{
    return m_spData->m_n84;
}

// @0x140e5da50
MS2_EMIT_CRT_MEMMOVE_S_COPY(16);
