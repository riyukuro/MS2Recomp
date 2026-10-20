// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemGemPropertyTable and the gem rows: Table/ItemGemProperty_{tomb,swim,charEffect,effect}.xml.
// MS2-UNIT: ?\itemgempropertytable.cpp
// MS2-RANGE: 0x1405abd00-0x1405b0b70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$BY0M@D@ArgType@internal@fmt@@QEAA@AEAY0M@$$CBD@Z 0x1405ace10 ; prop
// MS2-PIN: ??$?0$$BY0N@D@ArgType@internal@fmt@@QEAA@AEAY0N@$$CBD@Z 0x1405ace40 ; prop
// MS2-PIN: ??$StringFormat@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@$$BY0M@D@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBV01@AEAY0M@$$CBD@Z 0x1405ad8a0 ; prop
// MS2-PIN: ??$StringFormat@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@$$BY0N@D@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBV01@AEAY0N@$$CBD@Z 0x1405adbb0 ; prop
// MS2-PIN: ??$make_type@$$BY0M@D@internal@fmt@@YA_KAEAY0M@$$CBD@Z 0x1405af020 ; prop
// MS2-PIN: ??$make_type@$$BY0N@D@internal@fmt@@YA_KAEAY0N@$$CBD@Z 0x1405af040 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCGemDataBase@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCGemDataBase@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1405afcd0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CItemGemPropertyTable@@6B?$TSingleton@VCItemGemPropertyTable@@@@@ 0x142d63510
// MS2-PIN: ??_7CItemGemPropertyTable@@6B?$CValidData@VCItemGemPropertyTable@@@@@ 0x142d63520
// MS2-PIN: ??$LoadGems@VCGemCharEffectData@@@CItemGemPropertyTable@@AEAAHAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x1405adec0
// MS2-PIN: ??$LoadGems@VCGemEffectData@@@CItemGemPropertyTable@@AEAAHAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x1405ae300
// MS2-PIN: ??$LoadGems@VCGemSwimData@@@CItemGemPropertyTable@@AEAAHAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x1405ae740
// MS2-PIN: ??$LoadGems@VCGemTombStoneData@@@CItemGemPropertyTable@@AEAAHAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x1405aeb80
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemgempropertytable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/citemgempropertytable.h"
#include "itemgem.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <efd/Point3.h>
#include <typeinfo>
#include "hook/ms2hook.h"

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
bool FUN_14028f710(Unk_140165cf0* pElem);                               // the element is usable
int FUN_140873ad0(Unk_140165cf0* pElem, const char* pszName, CString& strOut);
int FUN_140874670(Unk_140165cf0* pElem, const char* pszName, efd::Point3& ptOut);
unsigned char FUN_1401d1320(CCacheData* pCache);                        // the file changed since it was loaded
class Unk_1403ed280;                                                    // the effect service
Unk_1403ed280* FUN_1403ed280();
void FUN_1411a4800(const CString& strEffect, int nType);                // preloads an effect

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton and init flag (symbols-manual.tsv)
CItemGemPropertyTable* TSingleton<CItemGemPropertyTable>::s_instance;   // DAT_143aafd08
bool CItemGemPropertyTable::s_bInit;
#endif

// @0x1405abd00
CItemGemPropertyTable::CItemGemPropertyTable()
{
}

// @0x1405abdc0
CItemGemPropertyTable::~CItemGemPropertyTable()
{
}

// @0x1405abe50
// MS2-FUNCTIONAL: the exe keeps the three-string temporaries of each call alive in a different frame layout
int CItemGemPropertyTable::Load()
{
    LoadGems<CGemTombStoneData>(FUN_14071a5b0(CString("Table"), CString("ItemGemProperty_tomb.xml")), CString("tomb"));
    LoadGems<CGemSwimData>(FUN_14071a5b0(CString("Table"), CString("ItemGemProperty_swim.xml")), CString("swim"));
    LoadGems<CGemCharEffectData>(FUN_14071a5b0(CString("Table"), CString("ItemGemProperty_charEffect.xml")), CString("charEffect"));
    LoadGems<CGemEffectData>(FUN_14071a5b0(CString("Table"), CString("ItemGemProperty_effect.xml")), CString("effect"));
    SetInit(true);
    return 1;
}

// @0x1405ac160
// MS2-FUNCTIONAL: frame/temporary order differs from the exe
MS2Ptr<CGemDataBase> CItemGemPropertyTable::FUN_1405ac160(int nGemId)
{
    MS2Ptr<CGemDataBase> spData(0);
    FUN_1405a96f0()->FUN_1405ac260();
    CheckInit();
    if (m_gems.IsEmpty())
        return spData;
    Unk_LockGuard guard(m_lock);
    if (guard)
    {
    }
    else
        m_gems.Lookup(nGemId, spData);
    return spData;
}

// @0x1405ac260
// MS2-FUNCTIONAL: frame/temporary order differs from the exe
bool CItemGemPropertyTable::FUN_1405ac260()
{
    bool bResult;
    bool bChanged = false;
    for (size_t i = 0; i < m_caches.GetCount(); ++i)
    {
        MS2Ptr<CCacheData> spCache = m_caches[i];
        if (spCache.get() && FUN_1401d1320(spCache.get()))
        {
            bChanged = true;
            break;
        }
    }
    if (bChanged)
    {
        Unk_LockGuard guard(m_lock);
        if (guard)
        {
        }
        else
        {
            m_caches.RemoveAll();
            m_gems.RemoveAll();
            bResult = Load() != 0;
        }
    }
    else
        bResult = true;
    return bResult;
}

// @0x1405ac3b0
// MS2-FUNCTIONAL: the exe builds the five format temporaries in a different frame layout
void CGemTombStoneData::TModelAttr::FUN_1405ac3b0(Unk_140165cf0* pElem, const CString& strPrefix)
{
    CString strFmt("{0}{1}");
    CString strKfm = StringFormat(strFmt, strPrefix, "kfm");
    CString strRegen = StringFormat(strFmt, strPrefix, "regenEffect");
    CString strIdle = StringFormat(strFmt, strPrefix, "idleEffect");
    CString strDmg = StringFormat(strFmt, strPrefix, "dmgEffect");
    CString strRevive = StringFormat(strFmt, strPrefix, "reviveEffect");
    FUN_140873ad0(pElem, strKfm, m_strKfm);
    FUN_140873ad0(pElem, strRegen, m_strRegenEffect);
    FUN_140873ad0(pElem, strIdle, m_strIdleEffect);
    FUN_140873ad0(pElem, strDmg, m_strDmgEffect);
    FUN_140873ad0(pElem, strRevive, m_strReviveEffect);
}

// @0x1405ac670
void CGemTombStoneData::TModelAttr::FUN_1405ac670()
{
    if (!m_strRegenEffect.IsEmpty())
    {
        FUN_1403ed280();
        FUN_1411a4800(m_strRegenEffect, 5);
    }
    if (!m_strIdleEffect.IsEmpty())
    {
        FUN_1403ed280();
        FUN_1411a4800(m_strIdleEffect, 5);
    }
    if (!m_strDmgEffect.IsEmpty())
    {
        FUN_1403ed280();
        FUN_1411a4800(m_strDmgEffect, 5);
    }
    if (!m_strReviveEffect.IsEmpty())
    {
        FUN_1403ed280();
        FUN_1411a4800(m_strReviveEffect, 5);
    }
}

// @0x1405ac760
// MS2-FUNCTIONAL: frame layout differs (bool return via mov al,1 vs int eax)
bool CGemTombStoneData::vfunc_1(Unk_140165cf0* pElem)
{
    CString strRotation("rotation");
    FUN_140874670(pElem, strRotation, m_ptRotation);
    m_attrA.FUN_1405ac3b0(pElem, CString(""));
    m_attrB.FUN_1405ac3b0(pElem, CString("dark_"));
    return true;
}

// @0x1405ac860
bool CGemSwimData::vfunc_1(Unk_140165cf0* pElem)
{
    FUN_140873ad0(pElem, "kf", m_strKf);
    FUN_140873ad0(pElem, "idleEffect", m_strIdleEffect);
    FUN_140873ad0(pElem, "runEffect", m_strRunEffect);
    FUN_140873ad0(pElem, "dashEffect", m_strDashEffect);
    return true;
}

// @0x1405ac8f0
CString CGemSwimData::FUN_1405ac8f0()
{
    return Unk_SocketFormat("SwimIdle_{0}", m_strKf);
}

// @0x1405ac940
CString CGemSwimData::FUN_1405ac940()
{
    return Unk_SocketFormat("SwimRun_{0}", m_strKf);
}

// @0x1405ac990
CString CGemSwimData::FUN_1405ac990()
{
    return Unk_SocketFormat("SwimDash_{0}", m_strKf);
}

// @0x1405ac9e0
void CGemSwimData::FUN_1405ac9e0()
{
    if (!m_strIdleEffect.IsEmpty())
    {
        FUN_1403ed280();
        FUN_1411a4800(m_strIdleEffect, 5);
    }
    if (!m_strRunEffect.IsEmpty())
    {
        FUN_1403ed280();
        FUN_1411a4800(m_strRunEffect, 5);
    }
    if (!m_strDashEffect.IsEmpty())
    {
        FUN_1403ed280();
        FUN_1411a4800(m_strDashEffect, 5);
    }
}

// @0x1405aca90
CGemCharEffectData::CGemCharEffectData()
{
}

// @0x1405acb20
bool CGemCharEffectData::vfunc_1(Unk_140165cf0* pElem)
{
    FUN_140873ad0(pElem, "EffectMale", m_strMale);
    FUN_140873ad0(pElem, "EffectFemale", m_strFemale);
    FUN_140873ad0(pElem, "EffectCouple_Diff", m_strCoupleDiff);
    FUN_140873ad0(pElem, "EffectCouple_Same_M", m_strCoupleSameM);
    FUN_140873ad0(pElem, "EffectCouple_Same_F", m_strCoupleSameF);
    return true;
}

// @0x1405acbd0
CString CGemCharEffectData::FUN_1405acbd0(int nPartnerGem)
{
    if (nPartnerGem == 0)
        return m_strMale;
    if (nPartnerGem == 1)
        return m_strFemale;
    return CString("");
}

// @0x1405acc80
CString CGemCharEffectData::FUN_1405acc80(int nOwnerGem, int nPartnerGem)
{
    if (nOwnerGem == 0 && nPartnerGem == 0)
        return m_strCoupleSameM;
    if (nOwnerGem == 1 && nPartnerGem == 1)
        return m_strCoupleSameF;
    return m_strCoupleDiff;
}

// @0x1405acd40
bool CGemEffectData::vfunc_1(Unk_140165cf0* pElem)
{
    FUN_140873ad0(pElem, "Effect", m_strEffect);
    return true;
}

// @0x1405af210
CGemDataBase::CGemDataBase()
{
}

// @0x1405af240
CGemEffectData::CGemEffectData()
{
}

// @0x1405af280
CGemSwimData::CGemSwimData()
{
}

// @0x1405af300
CGemTombStoneData::CGemTombStoneData()
{
}

// @0x1405af3f0
CGemTombStoneData::TModelAttr::TModelAttr()
{
}

// @0x1405af4f0
// MS2-FUNCTIONAL: the exe dtor does not store the class vptr before destroying the members (no source form found)
CGemCharEffectData::~CGemCharEffectData()
{
}

// @0x1405af570
CGemDataBase::~CGemDataBase()
{
}

// @0x1405af5a0
// MS2-FUNCTIONAL: the exe dtor does not store the class vptr before destroying the members (no source form found)
CGemEffectData::~CGemEffectData()
{
}

// @0x1405af5d0
// MS2-FUNCTIONAL: the exe dtor does not store the class vptr before destroying the members (no source form found)
CGemSwimData::~CGemSwimData()
{
}

// @0x1405af630
// MS2-FUNCTIONAL: the exe dtor does not store the class vptr before destroying the members (no source form found)
CGemTombStoneData::~CGemTombStoneData()
{
}

// @0x1405af6b0
// MS2-FUNCTIONAL: the exe dtor does not store the class vptr before destroying the members (no source form found)
CGemTombStoneData::TModelAttr::~TModelAttr()
{
}

// 0x1405adec0 (CGemCharEffectData), 0x1405ae300 (CGemEffectData), 0x1405ae740 (CGemSwimData), 0x1405aeb80 (CGemTombStoneData)
// MS2-FUNCTIONAL: frame layout of the temporaries differs from the exe (1081 vs 1075 bytes)
template <class T>
int CItemGemPropertyTable::LoadGems(const CString& strFile, const CString& strTag)
{
    MS2Ptr<CCacheData> spCache(new CCacheData);
    if (spCache.IsNull())
        return 0;
    spCache->FUN_1401d1160(CString(strFile));
    m_caches.Add(spCache);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strFile, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strFile);
        return 0;
    }
    CString strId("id");
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0(strTag); pNode != 0; pNode = pNode->FUN_140168650(strTag))
    {
        if (!FUN_14028f710(pNode))
            continue;
        int nId;
        FUN_140873220(pNode, strId, reinterpret_cast<unsigned&>(nId));
        if (nId == 0)
            continue;
        MS2Ptr<T> spData(new T);
        if (spData.IsNull())
            continue;
        spData->m_nGemId = nId;
        spData->vfunc_1(pNode);
        MS2Ptr<CGemDataBase> spBase(spData);
        Unk_LockGuard guard(m_lock);
        if (guard)
        {
        }
        else
            m_gems.SetAt(nId, spBase);
    }
    return 1;
}

MS2_EMIT_CRT_MEMMOVE_S();
