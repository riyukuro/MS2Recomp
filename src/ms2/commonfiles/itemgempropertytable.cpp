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
// MS2-PIN: ??$LoadGems@VCGemCharEffectData@@@CItemGemPropertyTable@@AEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x1405adec0
// MS2-PIN: ??$LoadGems@VCGemEffectData@@@CItemGemPropertyTable@@AEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x1405ae300
// MS2-PIN: ??$LoadGems@VCGemSwimData@@@CItemGemPropertyTable@@AEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x1405ae740
// MS2-PIN: ??$LoadGems@VCGemTombStoneData@@@CItemGemPropertyTable@@AEAA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@0@Z 0x1405aeb80
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
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/os.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// Unrecovered helpers (the same xml loader helpers the other table units use).
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString GetXmlPath(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
int XmlQuery(class TiXmlElement*, char const*, CString&);   // C3: was FUN_140873ad0
int XmlGetAttr(class TiXmlElement*, const char*, efd::Point3&);   // C3: was FUN_140874670 (0x140874670, xmlattr's Point3 reader)
unsigned char FUN_1401d1320(CCacheData* pCache);                        // the file changed since it was loaded
class Unk_1403ed280;                                                    // the effect service
class CEffectService;
bool FUN_1411a4800(const CString& strEffect, int nType);                // preloads an effect

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
bool CItemGemPropertyTable::Load()
{
    LoadGems<CGemTombStoneData>(GetXmlPath("Table", "ItemGemProperty_tomb.xml"), "tomb");
    LoadGems<CGemSwimData>(GetXmlPath("Table", "ItemGemProperty_swim.xml"), "swim");
    LoadGems<CGemCharEffectData>(GetXmlPath("Table", "ItemGemProperty_charEffect.xml"), "charEffect");
    LoadGems<CGemEffectData>(GetXmlPath("Table", "ItemGemProperty_effect.xml"), "effect");
    SetInit(true);
    return true;
}

// @0x1405ac160
MS2Ptr<CGemDataBase> CItemGemPropertyTable::FUN_1405ac160(int nGemId)
{
    GetItemGemPropertyTable()->ReloadIfChanged();
    CheckInit();
    if (m_gems.IsEmpty())
        return MS2Ptr<CGemDataBase>(0);
    MS2Ptr<CGemDataBase> spData(0);
    {
        Unk_LockGuard guard(m_lock);
        if (guard)
        {
        }
        else
            m_gems.Lookup(nGemId, spData);
    }
    return spData;
}

// @0x1405ac260
bool CItemGemPropertyTable::ReloadIfChanged()
{
    bool bResult = false;
    bool bChanged = false;
    for (size_t i = 0; i < m_caches.GetCount(); ++i)
    {
        MS2Ptr<CCacheData> spCache = m_caches[i];
        if (spCache == 0)
            continue;
        if (FUN_1401d1320(spCache.operator->()))
        {
            bChanged = true;
            break;
        }
    }
    if (!bChanged)
        return true;
    {
        Unk_LockGuard guard(m_lock);
        if (guard)
        {
        }
        else
        {
            m_caches.RemoveAll();
            m_gems.RemoveAll();
            bResult = Load();
        }
    }
    return bResult;
}

// @0x1405ac3b0
bool CGemTombStoneData::TModelAttr::FUN_1405ac3b0(TiXmlElement* pElem, const CString& strPrefix)
{
    const CString& strFmt = "{0}{1}";
    const CString& strKfm = StringFormat(strFmt, strPrefix, "kfm");
    const CString& strRegen = StringFormat(strFmt, strPrefix, "regenEffect");
    const CString& strIdle = StringFormat(strFmt, strPrefix, "idleEffect");
    const CString& strDmg = StringFormat(strFmt, strPrefix, "dmgEffect");
    const CString& strRevive = StringFormat(strFmt, strPrefix, "reviveEffect");
    XmlQuery((class TiXmlElement*)(pElem), strKfm, m_strKfm);
    XmlQuery((class TiXmlElement*)(pElem), strRegen, m_strRegenEffect);
    XmlQuery((class TiXmlElement*)(pElem), strIdle, m_strIdleEffect);
    XmlQuery((class TiXmlElement*)(pElem), strDmg, m_strDmgEffect);
    XmlQuery((class TiXmlElement*)(pElem), strRevive, m_strReviveEffect);
    return true;
}

// @0x1405ac670
void CGemTombStoneData::TModelAttr::FUN_1405ac670()
{
    if (!m_strRegenEffect.IsEmpty())
    {
        reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance());
        FUN_1411a4800(m_strRegenEffect, 5);
    }
    if (!m_strIdleEffect.IsEmpty())
    {
        reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance());
        FUN_1411a4800(m_strIdleEffect, 5);
    }
    if (!m_strDmgEffect.IsEmpty())
    {
        reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance());
        FUN_1411a4800(m_strDmgEffect, 5);
    }
    if (!m_strReviveEffect.IsEmpty())
    {
        reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance());
        FUN_1411a4800(m_strReviveEffect, 5);
    }
}

// @0x1405ac760
bool CGemTombStoneData::vfunc_1(TiXmlElement* pElem)
{
    const CString& strRotation = "rotation";
    XmlGetAttr((class TiXmlElement*)(pElem), strRotation, reinterpret_cast<efd::Point3&>(m_ptRotation));
    m_attrA.FUN_1405ac3b0(pElem, "");
    m_attrB.FUN_1405ac3b0(pElem, "dark_");
    return true;
}

// @0x1405ac860
bool CGemSwimData::vfunc_1(TiXmlElement* pElem)
{
    XmlQuery((class TiXmlElement*)(pElem), "kf", m_strKf);
    XmlQuery((class TiXmlElement*)(pElem), "idleEffect", m_strIdleEffect);
    XmlQuery((class TiXmlElement*)(pElem), "runEffect", m_strRunEffect);
    XmlQuery((class TiXmlElement*)(pElem), "dashEffect", m_strDashEffect);
    return true;
}

// @0x1405ac8f0
CString CGemSwimData::GetIdleAnimName()
{
    return Unk_SocketFormat("SwimIdle_{0}", m_strKf);
}

// @0x1405ac940
CString CGemSwimData::GetRunAnimName()
{
    return Unk_SocketFormat("SwimRun_{0}", m_strKf);
}

// @0x1405ac990
CString CGemSwimData::GetDashAnimName()
{
    return Unk_SocketFormat("SwimDash_{0}", m_strKf);
}

// @0x1405ac9e0
void CGemSwimData::FUN_1405ac9e0()
{
    if (!m_strIdleEffect.IsEmpty())
    {
        reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance());
        FUN_1411a4800(m_strIdleEffect, 5);
    }
    if (!m_strRunEffect.IsEmpty())
    {
        reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance());
        FUN_1411a4800(m_strRunEffect, 5);
    }
    if (!m_strDashEffect.IsEmpty())
    {
        reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance());
        FUN_1411a4800(m_strDashEffect, 5);
    }
}

// @0x1405aca90
CGemCharEffectData::CGemCharEffectData()
{
}

// @0x1405acb20
bool CGemCharEffectData::vfunc_1(TiXmlElement* pElem)
{
    XmlQuery((class TiXmlElement*)(pElem), "EffectMale", m_strMale);
    XmlQuery((class TiXmlElement*)(pElem), "EffectFemale", m_strFemale);
    XmlQuery((class TiXmlElement*)(pElem), "EffectCouple_Diff", m_strCoupleDiff);
    XmlQuery((class TiXmlElement*)(pElem), "EffectCouple_Same_M", m_strCoupleSameM);
    XmlQuery((class TiXmlElement*)(pElem), "EffectCouple_Same_F", m_strCoupleSameF);
    return true;
}

// @0x1405acbd0
CString CGemCharEffectData::GetEffectByGender(int nPartnerGem)
{
    if (nPartnerGem == 0)
        return m_strMale;
    if (nPartnerGem == 1)
        return m_strFemale;
    return CString("");
}

// @0x1405acc80
CString CGemCharEffectData::GetCoupleEffect(int nOwnerGem, int nPartnerGem)
{
    if (nOwnerGem == 0 && nPartnerGem == 0)
        return m_strCoupleSameM;
    if (nOwnerGem == 1 && nPartnerGem == 1)
        return m_strCoupleSameF;
    return m_strCoupleDiff;
}

// @0x1405acd40
bool CGemEffectData::vfunc_1(TiXmlElement* pElem)
{
    XmlQuery((class TiXmlElement*)(pElem), "Effect", m_strEffect);
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

// @0x1405af570
CGemDataBase::~CGemDataBase()
{
}

// 0x1405adec0 (CGemCharEffectData), 0x1405ae300 (CGemEffectData), 0x1405ae740 (CGemSwimData), 0x1405aeb80 (CGemTombStoneData)
template <class T>
bool CItemGemPropertyTable::LoadGems(const CString& strFile, const CString& strTag)
{
    MS2Ptr<CCacheData> spCache(new CCacheData);
    if (spCache == 0)
        return false;
    spCache->SetPath(CString(strFile));
    m_caches.Add(spCache);
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFile(&doc, strFile, 0, true, false) == 0)
        return false;
    TiXmlElement* pRoot = ((class TiXmlElement*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strFile);
        return false;
    }
    const CString& strId = "id";
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild(strTag)); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling(strTag)))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
            continue;
        int nId;
        XmlGetAttr((class TiXmlElement*)(pNode), strId, reinterpret_cast<unsigned&>(nId));
        if (nId == 0)
            continue;
        MS2Ptr<T> spData(new T);
        if (spData == 0)
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
    return true;
}

MS2_EMIT_CRT_MEMMOVE_S();
