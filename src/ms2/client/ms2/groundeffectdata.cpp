// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CGroundEffectDataManager: Data/Xml/GroundEffect/<name>.xml
// footstep effects (CAtlMap<CString, MS2Ptr<..>> of ground -> action -> effect blocks plus its template glue).
// MS2-UNIT: ?\groundeffectdata.cpp
// MS2-RANGE: 0x1400f1bc0-0x1400f1f60 .text$di
// MS2-RANGE: 0x141376d00-0x14137b010 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCGroundData@@@@QEAAAEAV1@PEAVCGroundData@@@Z 0x1413785f0 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCGroundActionData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCGroundActionData@@@@@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141378e70 ; prop
// MS2-PIN: ?GetNext@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCGroundData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCGroundData@@@@@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x141378eb0 ; prop
// MS2-PIN: ?RightRotate@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCGroundActionData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCGroundActionData@@@@@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14137a5d0 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCGroundData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCGroundData@@@@@2@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x14137a6e0 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCGroundActionData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCGroundActionData@@@@@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VCGroundActionData@@@@@Z 0x14137a7f0 ; prop
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCGroundData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCGroundData@@@@@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2Ptr@VCGroundData@@@@@Z 0x14137a860 ; prop
// MS2-PIN: ?SetNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCGroundActionData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCGroundActionData@@@@@2@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x14137aa60 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCGroundData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCGroundData@@@@@2@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x14137aad0 ; unique
// MS2-PIN: ?Successor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCGroundActionData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCGroundActionData@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14137ab40 ; prop
// MS2-PIN: ?Successor@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VCGroundData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VCGroundData@@@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14137ac10 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\groundeffectdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "groundeffectdata.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <egf/EntityID.h>

// The statics of three header copies sit in this .text$di range: the first full copy comes from header_statics_a.h
// above, then a copy of only the sort type names, then a second full copy.
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_3(17, 0.75f, 0.25f, 2.25f, 10);

// Unrecovered xml loader helpers (the same ones the other table units use).
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);       // FirstChildElement
    Unk_140165cf0* FUN_140168650(const char* pszName);       // NextSiblingElement
};
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);   // string attribute
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nOut);   // integer attribute, 0 when present
class Unk_GroundFiles { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_GroundFiles* FUN_140166420();
class Unk_GroundLog { public: void FUN_14015eb90(int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg); };
Unk_GroundLog* FUN_140166440();

extern int DAT_1439ed00c;   // ground effect cache enabled

// The scene object of an owner and the unrecovered object queries used by PlayEffects.
typedef egf::EntityID Unk_ModelKey;   // model key (8 bytes)
typedef egf::EntityID Unk_ModelKeyCopy;

class Unk_GroundOwner : public GameObject
{
public:
    CString FUN_141671480();                    // the ground name under the object
    void* FUN_14123c460(Unk_ModelKey* pKeyOut);         // fills the 16-byte model key
    int FUN_14123c660();                        // non-zero when the object is hidden
};
class Unk_ObjectRef
{
public:
    Unk_ObjectRef(GameObject* pObject);         // 0x140a000f0 stores the pointer and adds a reference
    int FUN_141b71120();
private:
    GameObject* m_p;
};
int FUN_141654700(PCBase* pPc);
PCBase* FUN_140974230(GameObject* pObject);
void* FUN_1409f7c90();
int FUN_14161d0f0(void* pWindowSvc);
void* FUN_1408b6b20(Unk_ModelKeyCopy* pDst, const Unk_ModelKey* pSrc);
void* FUN_141b6ef70(void* pKey);
extern char DAT_143afa4d8;                      // shadow-node table
void* FUN_14098d8d0(void* pTable, void* pKey);  // table lookup -> node
void* FUN_1403ed2d0();                          // player manager
void* FUN_1403ed280();                          // effect manager
int FUN_141bd1a10(void* pPlayer, GameObject* pObject);
int FUN_14123c580(GameObject* pObject);
void FUN_1411a4a00(void* pEffectMgr, Unk_EffectQuery* pQuery);
unsigned char FUN_1401d1320(void*);

// @0x141376d00
CGroundEffectData::CGroundEffectData()
{
}

// @0x141376d80
CGroundEffectData::~CGroundEffectData()
{
}

// @0x141376de0
CGroundActionData::CGroundActionData()
{
}

// @0x141376e30
CGroundActionData::~CGroundActionData()
{
}

// @0x141376e70
CGroundData::CGroundData()
    : m_actions(10)
{
}

// @0x141376ec0
CGroundData::~CGroundData()
{
}

// @0x141376f00
CGroundEffectDataManager::CGroundEffectDataManager()
    : m_grounds(10)
{
}

// @0x141376f50
CGroundEffectDataManager::~CGroundEffectDataManager()
{
    POSITION posGround;
    for (posGround = m_grounds.GetHeadPosition(); posGround != 0; m_grounds.GetNext(posGround))
    {
        GroundPtr spGround = m_grounds.GetValueAt(posGround);
        if (spGround.get() != 0)
        {
            POSITION posAction;
            for (posAction = spGround->m_actions.GetHeadPosition(); posAction != 0; spGround->m_actions.GetNext(posAction))
            {
                CGroundData::ActionPtr spAction = spGround->m_actions.GetValueAt(posAction);
                if (spAction.get() != 0)
                {
                    for (size_t i = 0; i < spAction->m_effects.GetCount(); i++)
                    {
                        CGroundActionData::EffectPtr spEffect = spAction->m_effects[i];
                        if (spEffect.get() != 0)
                        {
                            spEffect->m_files.RemoveAll();
                            spEffect->m_percents.RemoveAll();
                        }
                        spEffect = 0;
                    }
                    spAction->m_effects.RemoveAll();
                }
                spAction = 0;
            }
            spGround->m_actions.RemoveAll();
            spGround = 0;
        }
    }
    m_grounds.RemoveAll();
}

// @0x141377760
CGroundEffectDataManager::GroundPtr CGroundEffectDataManager::Load(const CString& strGround)
{
    CString strPath("./Data/Xml/GroundEffect/");
    strPath += strGround;
    strPath += ".xml";
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"파일을 읽을 수 없습니다[{0}]", strPath);
        return GroundPtr(0);
    }
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return GroundPtr(0);
    }
    GroundPtr spGround(0);
    if (!m_grounds.Lookup(strGround, spGround))
    {
        spGround.AssignRaw(new CGroundData);
        m_grounds.SetAt(strGround, spGround);
    }
    for (Unk_140165cf0* pAction = pRoot->FUN_140165cf0("action"); pAction != 0; pAction = pAction->FUN_140168650("action"))
    {
        const char* pszType = FUN_14086f4b0(pAction, "type");
        if (pszType != 0)
        {
            CGroundData::ActionPtr spAction(new CGroundActionData);
            {
                CString strType(pszType);
                spGround->m_actions.SetAt(strType, spAction);
            }
            for (Unk_140165cf0* pEffects = pAction->FUN_140165cf0("effects"); pEffects != 0;
                 pEffects = pEffects->FUN_140168650("effects"))
            {
                CGroundActionData::EffectPtr spEffect(new CGroundEffectData);
                spAction->m_effects.Add(spEffect);
                for (Unk_140165cf0* pEffect = pEffects->FUN_140165cf0("effect"); pEffect != 0;
                     pEffect = pEffect->FUN_140168650("effect"))
                {
                    const char* pszFile = FUN_14086f4b0(pEffect, "filePath");
                    {
                        CString strFile(pszFile);
                        spEffect->m_files.Add(strFile);
                    }
                    int nPercent = 0;
                    if (FUN_1408731e0(pEffect, "percent", nPercent) == 0)
                        spEffect->m_percents.Add(nPercent);
                    else
                        spEffect->m_percents.Add(0);
                }
                if (spEffect->m_files.GetCount() > 0)
                {
                    if (spEffect->m_files.GetCount() == 1)
                    {
                        spEffect->m_pool.AddIndex(0, 100);
                    }
                    else
                    {
                        for (size_t i = 0; i < spEffect->m_files.GetCount(); i++)
                        {
                            int* pnPercent = &spEffect->m_percents[i];
                            spEffect->m_pool.AddIndex((int)i, *pnPercent);
                        }
                    }
                    spEffect->m_pool.Shuffle();
                }
            }
        }
    }
    return spGround;
}
#ifndef MS2_HOOK_DLL
MS2_REPLACE_METHOD(0x141377760, CGroundEffectDataManager, Load, 1680, 0x3B6C2027);
#endif

// @0x1413771f0
void CGroundEffectDataManager::GetEffectFiles(CString strGround, CString strAction, ATL::CAtlArray<CString>* pFiles)
{
    GroundPtr spGround(0);
    if (DAT_1439ed00c == 0 || !m_grounds.Lookup(strGround, spGround))
        spGround = Load(strGround);
    if (spGround == 0)
        return;
    CGroundData::ActionPtr spAction(0);
    if (spGround->m_actions.Lookup(strAction, spAction))
    {
        for (size_t i = 0; i < spAction->m_effects.GetCount(); i++)
        {
            CGroundActionData::EffectPtr spEffect = spAction->m_effects[i];
            if (spEffect.get() != 0)
            {
                __int64 nIndex = spEffect->m_pool.Pick();
                pFiles->Add(spEffect->m_files[(size_t)nIndex]);
            }
        }
    }
}
#ifndef MS2_HOOK_DLL
MS2_REPLACE_METHOD(0x1413771F0, CGroundEffectDataManager, GetEffectFiles, 548, 0x659CCAC5);
#endif

// @0x141377420
// MS2-FUNCTIONAL: frame has 0x70 bytes of unreferenced locals the source cannot reproduce; calls and control flow match
void CGroundEffectDataManager::PlayEffects(GameObject* pObject, CString strAction)
{
    PCBase* pPc;
    if ((pPc = FUN_140974230(pObject)) != 0 && FUN_141654700(pPc) == 0x6e && pPc->vfunc_65() != 0
        && strAction.Find("run", 0) == 0)
        return;
    CString strGround = static_cast<Unk_GroundOwner*>(pObject)->FUN_141671480();
    if (strGround.IsEmpty())
        return;
    Unk_ModelKey kModel;
    static_cast<Unk_GroundOwner*>(pObject)->FUN_14123c460(&kModel);
    if (static_cast<Unk_GroundOwner*>(pObject)->FUN_14123c660() != 0)
        return;
    if (FUN_14161d0f0(FUN_1409f7c90()) == 0)
    {
        if (Unk_ObjectRef(pObject).FUN_141b71120() == 0)
            return;
    }
    ATL::CAtlArray<CString> files;
    GetEffectFiles(CString(strGround), CString(strAction), &files);
    Unk_ModelKeyCopy kCopy;
    void* pNode = FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6ef70(FUN_1408b6b20(&kCopy, &kModel)));
    if (pNode != 0)
    {
        Unk_EffectQuery query;
        query.m_nObject = FUN_141bd1a10(FUN_1403ed2d0(), pObject);
        query.SetActor(FUN_14123c580(pObject));
        for (unsigned int i = 0; i < files.GetCount(); i++)
        {
            query.m_strName = files[i];
            FUN_1411a4a00(FUN_1403ed280(), &query);
        }
    }
}
#ifndef MS2_HOOK_DLL
MS2_REPLACE_METHOD(0x141377420, CGroundEffectDataManager, PlayEffects, 826, 0x9C1CAC10);
#endif

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb0ef0-0x142cb1040 .text$yd
