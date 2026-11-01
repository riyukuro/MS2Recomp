// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The character ability table: Table\CharacterAbilityCategory.xml
// and Table\CharacterAbility.xml loaded into CCharacterAbilityCategory / CCharacterAbility rows (see characterability.h).
// MS2-UNIT: ?\characterability.cpp
// MS2-RANGE: 0x1401df430-0x1401e4000 .text$mn
// MS2-PIN: ??_7CCharacterAbilityTable@@6B?$TSingleton@VCCharacterAbilityTable@@@@@ 0x142cefe20
// MS2-PIN: ??_7CCharacterAbilityTable@@6B?$CValidData@VCCharacterAbilityTable@@@@@ 0x142cefe30
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCCacheData@@@@QEAAAEAV1@PEAVCCacheData@@@Z 0x1401e12a0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCCharacterAbilityCategory@@@@QEBAPEAVCCharacterAbilityCategory@@XZ 0x1401e13b0 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCCacheData@@@@AEBAXPEAX@Z 0x1401e3dc0 ; unique
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCCacheData@@@@AEAAXPEAX@Z 0x1401e3f10 ; unique
// MS2-PIN: ?Reference@?$MS2Ptr@VCCacheData@@@@CAXPEAVCCacheData@@@Z 0x1401e3d60 ; manual
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\characterability.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/commonfiles/characterability.h"

#include <typeinfo>
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CString FUN_14016a5c0(const char* pszName, int nFlags);                 // undecorated class name
unsigned char FUN_1401d1320(CCacheData* p);                             // file changed since load
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int FUN_140873420(Unk_140165cf0* pNode, const char* pszName, CStringW& rOut);
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
CStringW GetStringCommonByKey(const CStringW& strKey);                         // string by key

// The content switch table and the player level.
class Unk_CaSwitches : public CFeatureManager
{
public:
    unsigned short FUN_14036de00();
};
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410

// The state object that holds the ability points slot.
struct Unk_CaSlot { int m_n; };
class Unk_CaState
{
public:
    char m_pad[0x6c60];
    Unk_CaSlot m_slot;
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

// The unit's log call (an FMT_VARIADIC wrapper over CLogString::FUN_1406530d0): two arguments.
template <class A, class B> inline void FUN_1401e0850(CLogString* log, int level, int category, const wchar_t* format,
                                                      const A& a, const B& b)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b), args));
}

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CCharacterAbilityTable::s_bInit;
#endif

// @0x1401df430
CCharacterAbility::CCharacterAbility()
    : m_nId(0), m_nCategoryId(0), m_nRequireLevel(0), m_nAdditionalEffectId(0), m_nAdditionalEffectLevel(0)
{
}

// @0x1401df4d0
CCharacterAbilityCategory::CCharacterAbilityCategory()
    : m_nId(0), m_abilities(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1401df5e0
CCharacterAbilityTable::CCharacterAbilityTable()
    : m_categories(17, 0.75f, 0.25f, 2.25f, 10), m_abilities(17, 0.75f, 0.25f, 2.25f, 10)
{
    FUN_1401df7b0();
}

// @0x1401df700
CCharacterAbilityTable::~CCharacterAbilityTable()
{
}

// @0x1401df7b0
int CCharacterAbilityTable::FUN_1401df7b0()
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (LoadCharacterAbilityCategory() == 0)
            return 0;
        if (LoadCharacterAbility() == 0)
            return 0;
    }
    SetInit(true);
    return 1;
}

// @0x1401df860
int CCharacterAbilityTable::LoadCharacterAbilityCategory()
{
    m_categories.RemoveAll();
    CString strPath = FUN_14071a5b0("Table", "CharacterAbilityCategory.xml");
    m_spCategoryCache.AssignRaw(new CCacheData);
    m_spCategoryCache->FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("category")); pNode != 0; pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->NextSibling("category")))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
            continue;
        CStringW strLocale;
        XmlGetAttr((class TiXmlElement*)(pNode), "locale", strLocale);
        if (!((class Unk_CaSwitches*)FUN_140166410())->IsLocaleInList(strLocale))
            continue;
        {
            MS2Ptr<CCharacterAbilityCategory> spCategory(new CCharacterAbilityCategory);
            XmlGetAttr((class TiXmlElement*)(pNode), "id", spCategory->m_nId);
            XmlGetAttr((class TiXmlElement*)(pNode), "name", spCategory->m_strName);
            XmlGetAttr((class TiXmlElement*)(pNode), "tooltip", spCategory->m_strTooltip);
            spCategory->m_strName = GetStringCommonByKey(spCategory->m_strName);
            spCategory->m_strTooltip = GetStringCommonByKey(spCategory->m_strTooltip);
            m_categories.SetAt(spCategory->m_nId, spCategory);
        }
    }
    return 1;
}

// @0x1401dfd40
int CCharacterAbilityTable::LoadCharacterAbility()
{
    m_abilities.RemoveAll();
    for (POSITION pos = m_categories.GetStartPosition(); pos != NULL; m_categories.GetNext(pos))
    {
        MS2Ptr<CCharacterAbilityCategory> spCategory = m_categories.GetValueAt(pos);
        spCategory->m_abilities.RemoveAll();
    }
    CString strPath = FUN_14071a5b0("Table", "CharacterAbility.xml");
    m_spAbilityCache.AssignRaw(new CCacheData);
    m_spAbilityCache->FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("ability")); pNode != 0; pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->NextSibling("ability")))
    {
        if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
            continue;
        CStringW strLocale;
        XmlGetAttr((class TiXmlElement*)(pNode), "locale", strLocale);
        if (!((class Unk_CaSwitches*)FUN_140166410())->IsLocaleInList(strLocale))
            continue;
        {
            MS2Ptr<CCharacterAbility> spAbility(new CCharacterAbility);
            XmlGetAttr((class TiXmlElement*)(pNode), "id", spAbility->m_nId);
            XmlGetAttr((class TiXmlElement*)(pNode), "categoryID", spAbility->m_nCategoryId);
            XmlGetAttr((class TiXmlElement*)(pNode), "requireLevel", spAbility->m_nRequireLevel);
            XmlGetAttr((class TiXmlElement*)(pNode), "additionalEffectID", spAbility->m_nAdditionalEffectId);
            XmlGetAttr((class TiXmlElement*)(pNode), "additionalEffectLevel", spAbility->m_nAdditionalEffectLevel);
            MS2Ptr<CCharacterAbilityCategory> spCategory(0);
            if (!m_categories.Lookup(spAbility->m_nCategoryId, spCategory))
            {
                FUN_1401e0850(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}] Not Found CategoryID {1}", strPath, spAbility->m_nCategoryId);
                return 0;
            }
            spCategory->m_abilities.SetAt(spAbility->m_nId, spAbility);
            m_abilities.SetAt(spAbility->m_nId, spAbility);
        }
    }
    return 1;
}

// @0x1401e0350
void CCharacterAbilityTable::FUN_1401e0350(ATL::CAtlList<MS2Ptr<CCharacterAbilityCategory> >* pOut)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (FUN_1401d1320(m_spCategoryCache.operator->()) != 0 || FUN_1401d1320(m_spAbilityCache.operator->()) != 0)
            FUN_1401df7b0();
        for (POSITION pos = m_categories.GetStartPosition(); pos != NULL; m_categories.GetNext(pos))
            pOut->AddTail(m_categories.GetValueAt(pos));
    }
}

// @0x1401e0450
void CCharacterAbilityTable::FUN_1401e0450(ATL::CAtlList<MS2Ptr<CCharacterAbility> >* pOut)
{
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (FUN_1401d1320(m_spCategoryCache.operator->()) != 0 || FUN_1401d1320(m_spAbilityCache.operator->()) != 0)
            FUN_1401df7b0();
        for (POSITION pos = m_abilities.GetStartPosition(); pos != NULL; m_abilities.GetNext(pos))
            pOut->AddTail(m_abilities.GetValueAt(pos));
    }
}

// @0x1401e0560
MS2Ptr<CCharacterAbilityCategory> CCharacterAbilityTable::FUN_1401e0560(int nId)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (FUN_1401d1320(m_spCategoryCache.operator->()) != 0 || FUN_1401d1320(m_spAbilityCache.operator->()) != 0)
            FUN_1401df7b0();
        MS2Ptr<CCharacterAbilityCategory> spCategory(0);
        m_categories.Lookup(nId, spCategory);
        return spCategory;
    }
}

// @0x1401e0670
MS2Ptr<CCharacterAbility> CCharacterAbilityTable::FUN_1401e0670(int nId)
{
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
        __assume(0);
    }
    else
    {
        if (FUN_1401d1320(m_spCategoryCache.operator->()) != 0 || FUN_1401d1320(m_spAbilityCache.operator->()) != 0)
            FUN_1401df7b0();
        MS2Ptr<CCharacterAbility> spAbility(0);
        m_abilities.Lookup(nId, spAbility);
        return spAbility;
    }
}

// @0x1401e0790
int FUN_1401e0790(unsigned short nLevel, int nPoints)
{
    unsigned short nPlayerLevel = ((class Unk_CaSwitches*)FUN_140166410())->FUN_14036de00();
    int nTotal = nLevel - nPlayerLevel;
    nTotal += *reinterpret_cast<int*>(reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_CaState*)FUN_1401d3200())->m_slot)->Get());
    nTotal += nPoints;
    return nTotal;
}

// @0x1401e0800
int FUN_1401e0800(unsigned short nLevel)
{
    if (!((class Unk_CaSwitches*)FUN_140166410())->FUN_14036d570(0x2d))
        return 0;
    if (((class Unk_CaSwitches*)FUN_140166410())->FUN_14036de00() > nLevel)
        return 0;
    return 1;
}

// @0x1401e1690
void CCharacterAbilityTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CCharacterAbilityTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1401e3b00
void CCharacterAbilityTable::SetInit(bool b)
{
    s_bInit = b;
}
