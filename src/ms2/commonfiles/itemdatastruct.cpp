// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The blocks of an item row (citemdata.h: limit, period,
// skill, property, install, effect, function, ...) and the item model block (itemdata.h: ModelPart, ModelGroup,
// ItemModelHead, ItemModelData): constructors, XML readers/writers and comparisons.
// MS2-UNIT: commonfiles\itemdatastruct.cpp
// MS2-RANGE: 0x1405434a0-0x140555a70 .text$mn
// MS2-RANGE: 0x1400b9950-0x1400b9a40 .text$di
// MS2-RANGE: 0x142c9ad60-0x142c9ae90 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$IsSameVector@_J@@YA_NAEBV?$vector@_JV?$allocator@_J@std@@@std@@0@Z 0x14054ca40 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@4@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@PEAX@1@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@1@1@Z 0x14054e630 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@4@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@1@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@PEAX@1@@Z 0x14054e990 ; unique
// MS2-PIN: ??$_Ucopy@PEAV?$MS2Ptr@VItemCustom@@@@@?$vector@V?$MS2Ptr@VItemCustom@@@@V?$allocator@V?$MS2Ptr@VItemCustom@@@@@std@@@std@@AEAAPEAV?$MS2Ptr@VItemCustom@@@@PEAV2@00@Z 0x14054f300 ; prop
// MS2-PIN: ??0?$vector@V?$MS2Ptr@VItemCustom@@@@V?$allocator@V?$MS2Ptr@VItemCustom@@@@@std@@@std@@QEAA@AEBV01@@Z 0x140551620 ; unique
// MS2-PIN: ??0ModelPart@@QEAA@AEBU0@@Z 0x140551ee0 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140552930 ; prop
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEBA_NXZ 0x140555350 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetInt@CXmlData@@QEAAHAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEBH@Z 0x14054c530
// MS2-PIN: ??0ModelPart@@QEAA@$$QEAU0@@Z 0x140551c40
// MS2-PIN: ??0ModelNamedColor@@QEAA@$$QEAU0@@Z 0x140552180
// MS2-PIN: ??0ModelNamedColor@@QEAA@AEBU0@@Z 0x140552200
// MS2-PIN: ??$?8V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@YA_NAEBV?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@0@0@Z 0x14054bf00
// MS2-PIN: ??$IsSameArray@H@@YA_NAEBV?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@0@Z 0x14054c990
// MS2-PIN: ?push_back@?$vector@_JV?$allocator@_J@std@@@std@@QEAAX$$QEA_J@Z 0x1405556e0
// MS2-PIN: ??$emplace_back@_J@?$vector@_JV?$allocator@_J@std@@@std@@QEAAX$$QEA_J@Z 0x140550620
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@_J@?$vector@_JV?$allocator@_J@std@@@std@@AEAAX$$QEA_J@Z 0x14054d4f0
// MS2-PIN: ??$_Emplace_reallocate@_J@?$vector@_JV?$allocator@_J@std@@@std@@QEAAPEA_JQEA_J$$QEA_J@Z 0x14054df10
// MS2-PIN: ??$construct@_J_J@?$_Default_allocator_traits@V?$allocator@_J@std@@@std@@SAXAEAV?$allocator@_J@1@QEA_J$$QEA_J@Z 0x1405503a0
// MS2-PIN: ?_Umove@?$vector@_JV?$allocator@_J@std@@@std@@AEAAPEA_JPEA_J00@Z 0x140554d30
// MS2-PIN: ??1DropNifData@@UEAA@XZ 0x140552480
// MS2-PIN: ??1ItemColorEx@@UEAA@XZ 0x1405524a0
// MS2-PIN: ??1ItemDropEffect@@UEAA@XZ 0x1405524c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemdatastruct.cpp"
// The _stricmp calls of this unit go through the IAT, so not ms2/placeholder/ms2stdafx.h (its plain redeclaration).
#include <afx.h>
#include <afxwin.h>
#include "itemdata.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include <algorithm>
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/dungeonmatch.h"
#include "ms2/commonfiles/pricetable.h"
#include "ms2/placeholder/cinstrumentdatatable.h"
void Unk_SplitA(CStringA&, ATL::CAtlArray<CStringA>*, const char*);   // C3: the achievedata def at 0x14015f050
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// Unrecovered helpers.
int ReadSlotAttr(Unk_140165cf0* pElem, const char* pszName, int* pnOut);    // banktable.h: slot name attribute
void FUN_1402c8940(const CString& str, std::vector<CString>& vec, const char* pszDelim);   // split into strings
int FUN_14021bdc0(CString& strName);    // slot name -> slot type
CString Name_14021c050(int nType);      // slot type -> slot name
CString FUN_14016a5c0(const char* psz, int n);
int FUN_1402227e0(int, int);  // C3: the definition's signature
class TiXmlNode   // C3: member view for the former free stand-ins
{
public:
    class TiXmlNode* InsertEndChild(class TiXmlNode const&);
};
void XmlSetAttr(class TiXmlElement*, char const*, bool);   // C3: was FUN_140873bc0
void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0
void XmlSetAttr(class TiXmlElement*, char const*, unsigned int);   // C3: was FUN_140873ce0
void XmlSetAttr(class TiXmlElement*, char const*, const CString&);   // C3: was FUN_140874050
void XmlSetAttr(class TiXmlElement*, char const*, const CStringW&);   // C3: was FUN_1408740a0
void XmlSetAttr(class TiXmlElement*, char const*, float);   // C3: was FUN_140873e30
void FUN_140874ad0(void* pElem, const char* pszName, const efd::Point3& kValue);    // SetAttribute(name, "x, y, z")
int XmlGetAttr(class TiXmlElement*, char const*, class NiPoint3&);   // C3: was FUN_1408746f0
int FUN_140874670(Unk_140165cf0* pElem, const char* pszName, efd::Point3& kOut);    // Point3 attribute (drop effect)
CString FUN_140298360(const char* psz, const CString& str);                              // ATL operator+(const char*, const CString&) (commonutil.cpp)
__int64 ParseInt64(const CString& str);                                    // 0x1402a4fe0
CString FUN_1401d4330(const wchar_t* pszWide, int nCodePage);              // wide to ansi
CString FUN_140188f50(const char* psz, int nCodePage);                     // string from an attribute value
efd::Point3 FUN_14028f060(CString str);                                    // "x, y, z" -> point (ZERO when malformed)
int XmlQuery(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408736d0
void XmlSetAttr(class TiXmlElement*, char const*, unsigned short);   // C3: was FUN_140873c60
int FUN_14053fa40(int nItemId);            // itemdata.cpp (written there as bool; the callers test eax)
int FUN_141901d20(int, __int64, __int64);  // C3: the definition's signature
int XmlGetBool(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873710

// The item price table (commonfiles\pricetable.cpp).
class CPriceTable;
// @0x140552df0
inline CPriceTable* FUN_140552df0()
{
    return TSingleton<CPriceTable>::s_instance;
}

#define MS2_ASSERT_MSG_AT(line, msg, cond) (void)((!!(cond)) || (_wassert(msg, _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))

// Container comparisons (true = same; the templates of additionalactionadditional.cpp).
template <class T> bool IsSameArray(const ATL::CAtlArray<T>& a, const ATL::CAtlArray<T>& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (unsigned i = 0; i < a.GetCount(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
template <class T> bool IsSameVector(const std::vector<T>& a, const std::vector<T>& b)
{
    if (a.size() != b.size())
        return false;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

// The __int64 lists convert their tokens with ParseInt64.
template <> void XmlSplitImpl(const CString& str, std::vector<__int64>& vec, const char* pszDelim)
{
    int nPos = 0;
    CString strToken = str.Tokenize(pszDelim, nPos);
    while (!strToken.IsEmpty())
    {
        vec.push_back(ParseInt64(strToken));
        strToken = str.Tokenize(pszDelim, nPos);
    }
}

// The game settings: feature switches by number.

// Unit-local view of the game's TiXmlElement (0x90 bytes).
// TinyXML attribute (only the sentinel of an element's attribute set is touched here).
class Unk_TiXmlAttribute
{
public:
    void* unknown00[7];                         // TiXmlBase, document, name, value, prev
    Unk_TiXmlAttribute* next;                   // +0x38
};
MS2_CHECK_SIZE(Unk_TiXmlAttribute, 0x40);

class Unk_TiXmlAttributeSet
{
public:
    // @0x140552d70
    Unk_TiXmlAttribute* First() { return (sentinel.next == &sentinel) ? 0 : sentinel.next; }
    Unk_TiXmlAttribute sentinel;
};

class TiXmlElement
{
public:
    TiXmlElement(const char* pszName);      // 0x14086f2f0
    virtual ~TiXmlElement();                // 0x14086f450
    char const* Attribute(char const*) const;
    // @0x140552e00
    bool HasAttributes() { return attributeSet.First() == 0 ? false : true; }
    // @0x140552e40
    bool HasChildren() { return firstChild == 0 ? false : true; }
    // @0x140552e70
    bool HasContent() { return HasAttributes() || HasChildren(); }
private:
    void* unknown00[4];                         // TiXmlBase, parent, type
    void* firstChild;                           // +0x28
    void* unknown30[4];                         // lastChild, value, prev, next
    Unk_TiXmlAttributeSet attributeSet;         // +0x50
};
MS2_CHECK_SIZE(TiXmlElement, 0x90);

// Drops one leading and one trailing comma of a joined list (an inline helper of the XML writers).
inline void TrimCommas(CString& str)
{
    if (str.IsEmpty())
        return;
    if (str[0] == ',')
        str = str.Mid(1);
    if (str.IsEmpty())
        return;
    if (str[str.GetLength() - 1] == ',')
        str = str.Mid(0, str.GetLength() - 1);
}

// The statics of this unit: the item list sort names and the key input controller (both header statics).
#ifndef MS2_HOOK_DLL
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;                // 0x143aaf5a0
#endif

// @0x1405434a0
DropNifData::DropNifData()
    : m_nTypeId(0), m_nUnk1c(0)
{
}

// @0x1405434f0
void DropNifData::FUN_1405434f0(Unk_140165cf0* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "typeID", reinterpret_cast<unsigned&>(m_nTypeId));
    XmlGetAttr((class TiXmlElement*)(pElem), "min", m_nUnk1c);
}

// @0x140543550
bool DropNifData::FUN_140543550(unsigned n)
{
    return m_nUnk1c <= n;
}

// @0x140543590
int DropNifData::GetTypeId()
{
    return m_nTypeId;
}

// @0x1405435b0
ItemDropEffect::ItemDropEffect()
    : typeID(0), unknown1c(50.0f), scale(1.0f), getAniSpeed(0), dropAniSpeed(0), beAniSpeed(0), shadowBias(0),
      shadowScale(0), bounceHeight(30.0f), bouncePeriod(1.0f), getAni(0, 0, 0), dropAni(0, 0, 0), beAni(0, 0, 0),
      beEffect(""), assetName(""), dropSoundID(), getSoundID()
{
}

// @0x140543730
void ItemDropEffect::Load(Unk_140165cf0* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "typeID", reinterpret_cast<unsigned&>(typeID));
    XmlGetAttr((class TiXmlElement*)(pElem), "scale", reinterpret_cast<float&>(scale));
    XmlGetAttr((class TiXmlElement*)(pElem), "bias", reinterpret_cast<float&>(unknown1c));
    XmlGetAttr((class TiXmlElement*)(pElem), "shadowscale", reinterpret_cast<float&>(shadowScale));
    XmlGetAttr((class TiXmlElement*)(pElem), "shadowbias", reinterpret_cast<float&>(shadowBias));
    FUN_140874670(pElem, "dropani", dropAni);
    XmlGetAttr((class TiXmlElement*)(pElem), "dropanispeed", reinterpret_cast<float&>(dropAniSpeed));
    FUN_140874670(pElem, "beani", beAni);
    XmlGetAttr((class TiXmlElement*)(pElem), "beanispeed", reinterpret_cast<float&>(beAniSpeed));
    FUN_140874670(pElem, "getani", getAni);
    XmlGetAttr((class TiXmlElement*)(pElem), "getanispeed", reinterpret_cast<float&>(getAniSpeed));
    XmlGetAttr((class TiXmlElement*)(pElem), "bounceheight", reinterpret_cast<float&>(bounceHeight));
    XmlGetAttr((class TiXmlElement*)(pElem), "bounceperiod", reinterpret_cast<float&>(bouncePeriod));
    XmlGetAttr((class TiXmlElement*)(pElem), "beeffect", beEffect);
    XmlGetAttr((class TiXmlElement*)(pElem), "dropSoundID", dropSoundID);
    XmlGetAttr((class TiXmlElement*)(pElem), "getSoundID", getSoundID);
    XmlGetAttr((class TiXmlElement*)(pElem), "assetName", assetName);
}

// @0x140543940
ItemColorEx::ItemColorEx(const int& nId)
    : m_nId(nId), m_nColor(-1), m_bFlag(false), m_n24(0), m_n28(0), m_n2c(0), m_n30(0), m_n34(0), m_n38(0)
{
    m_aValues[0] = 0;
    m_aValues[1] = 0;
    m_aValues[2] = 0;
}

// @0x140543a30
ModelNamedColor::ModelNamedColor()
{
    soft = 0.01f;
    posz = 0;
    zero = 0;
    negz = 0;
}

// @0x140543a90
ModelPart::ModelPart()
    : name0(""), name8(""), name10(""), isNif(0), pony(0), zalign(0), replace(0), earfold(0), ani(0), emotionhide(0),
      gender(2), capscale(1.0f), mantlescale(1.0f), ponyIndex(0), weapon(0), placeable(0), rotationMin(0, 0, 0),
      rotationMax(0, 0, 0)
{
}

// @0x140543ca0
int ModelPart::Load(Unk_140165cf0* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "name", name0);
    XmlGetAttr((class TiXmlElement*)(pElem), "selfnode", name8);
    XmlGetAttr((class TiXmlElement*)(pElem), "targetnode", name10);
    XmlGetAttr((class TiXmlElement*)(pElem), "attachnode", name18);
    name0.TrimRight();
    if (name0.Right(4) == ".nif")
    {
        isNif = 1;
    }
    else
    {
        isNif = 0;
        if (name0.Find("urn:gamebryo-animation:") == -1)
            name0 = FUN_140298360("urn:gamebryo-animation:", name0);
    }
    XmlGetAttr((class TiXmlElement*)(pElem), "pony", reinterpret_cast<int&>(pony));
    XmlGetAttr((class TiXmlElement*)(pElem), "zalign", zalign);
    XmlGetAttr((class TiXmlElement*)(pElem), "replace", reinterpret_cast<int&>(replace));
    XmlGetAttr((class TiXmlElement*)(pElem), "earfold", reinterpret_cast<int&>(earfold));
    XmlGetAttr((class TiXmlElement*)(pElem), "ani", reinterpret_cast<int&>(ani));
    XmlGetAttr((class TiXmlElement*)(pElem), "emotionhide", reinterpret_cast<int&>(emotionhide));
    XmlGetAttr((class TiXmlElement*)(pElem), "gender", gender);
    XmlGetAttr((class TiXmlElement*)(pElem), "capscale", reinterpret_cast<float&>(capscale));
    XmlGetAttr((class TiXmlElement*)(pElem), "mantlescale", reinterpret_cast<float&>(mantlescale));
    XmlGetAttr((class TiXmlElement*)(pElem), "weapon", reinterpret_cast<int&>(weapon));
    XmlGetAttr((class TiXmlElement*)(pElem), "placeable", reinterpret_cast<int&>(placeable));
    for (Unk_140165cf0* pCustom = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("custom")); pCustom != 0;
         pCustom = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pCustom))->NextSibling("custom")))
    {
        MS2Ptr<ItemCustom> spCustom(new ItemCustom);
        spCustom->FUN_140266aa0(pCustom);
        customs.push_back(spCustom);
    }
    for (Unk_140165cf0* pRotation = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("userrotation")); pRotation != 0;
         pRotation = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRotation))->NextSibling("userrotation")))
    {
        const char* pszAxis = ((class TiXmlElement*)(class Unk_140165cf0*)(pRotation))->Attribute("axis");
        if (pszAxis != 0)
        {
        if (_stricmp(pszAxis, "x") == 0)
        {
            XmlGetAttr((class TiXmlElement*)(pRotation), "min", reinterpret_cast<float&>(rotationMin.x));
            XmlGetAttr((class TiXmlElement*)(pRotation), "max", reinterpret_cast<float&>(rotationMax.x));
            ATL::CAtlArray<float> values;
            CString strDefault = Unk_ReadString((class Unk_XmlNode*)(pRotation), "default", "");
            XmlSplit(strDefault, values, ",");
            points.resize(values.GetCount());
            for (size_t i = 0; i < points.size(); i++)
                points[i].x = values[i];
        }
        else if (_stricmp(pszAxis, "y") == 0)
        {
            XmlGetAttr((class TiXmlElement*)(pRotation), "min", reinterpret_cast<float&>(rotationMin.y));
            XmlGetAttr((class TiXmlElement*)(pRotation), "max", reinterpret_cast<float&>(rotationMax.y));
            ATL::CAtlArray<float> values;
            CString strDefault = Unk_ReadString((class Unk_XmlNode*)(pRotation), "default", "");
            XmlSplit(strDefault, values, ",");
            points.resize(values.GetCount());
            for (size_t i = 0; i < points.size(); i++)
                points[i].y = values[i];
        }
        else if (_stricmp(pszAxis, "z") == 0)
        {
            XmlGetAttr((class TiXmlElement*)(pRotation), "min", reinterpret_cast<float&>(rotationMin.z));
            XmlGetAttr((class TiXmlElement*)(pRotation), "max", reinterpret_cast<float&>(rotationMax.z));
            ATL::CAtlArray<float> values;
            CString strDefault = Unk_ReadString((class Unk_XmlNode*)(pRotation), "default", "");
            XmlSplit(strDefault, values, ",");
            points.resize(values.GetCount());
            for (size_t i = 0; i < points.size(); i++)
                points[i].z = values[i];
        }
        }
    }
    int nJoint = 0;
    for (Unk_140165cf0* pJoint = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("jointangle")); pJoint != 0;
         pJoint = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pJoint))->NextSibling("jointangle")))
    {
        if (nJoint == 4)
            break;
        const char* pszName = ((class TiXmlElement*)(class Unk_140165cf0*)(pJoint))->Attribute("name");
        ModelNamedColor& color = colors[nJoint++];
        color.name = pszName;
        XmlGetAttr((class TiXmlElement*)(pJoint), "soft", reinterpret_cast<float&>(color.soft));
        XmlGetAttr((class TiXmlElement*)(pJoint), "posz", reinterpret_cast<float&>(color.posz));
        XmlGetAttr((class TiXmlElement*)(pJoint), "zero", reinterpret_cast<float&>(color.zero));
        XmlGetAttr((class TiXmlElement*)(pJoint), "negz", reinterpret_cast<float&>(color.negz));
    }
    {
        CString strCapHair = Unk_ReadString((class Unk_XmlNode*)(pElem), "capHair", "");
        ATL::CAtlArray<CString> capHairs;
        Unk_SplitA(const_cast<CStringA&>(strCapHair), (ATL::CAtlArray<CStringA>*)&(capHairs), ",");
        char chKey = 'B';
        for (unsigned i = 0; i < capHairs.GetCount(); i++)
        {
            CString strKey(chKey++, 1);
            properties.insert(std::make_pair(strKey, capHairs[i]));
        }
    }
    for (Unk_140165cf0* pDummy = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("dummy")); pDummy != 0;
         pDummy = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pDummy))->NextSibling("dummy")))
    {
        ModelNameEntry entry;
        reinterpret_cast<ItemDummyInfo*>(&entry)->Load(pDummy);
        if (entry.targetNode.IsEmpty())
            entry.targetNode = name10;
        if (entry.gender == 2)
        {
            entries[0].push_back(entry);
            entries[1].push_back(entry);
        }
        else
        {
            entries[entry.gender].push_back(entry);
        }
    }
    Unk_140165cf0* pPhysX = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("physx"));
    if (pPhysX != 0)
    {
        CString strAction = Unk_ReadString((class Unk_XmlNode*)(pPhysX), "action", "");
        FUN_1402c8940(strAction, names, ", ");
    }
    return 1;
}

// @0x140544a80
int ModelPart::FUN_140544a80(void* pParent)
{
    return 1;
}

// @0x140544aa0
int ModelPart::FUN_140544aa0(int nGender, int nWeapon) const
{
    if (gender != 2 && gender != nGender)
        return 0;
    if (weapon == 0)
        return 1;
    if (nWeapon == 0)
        return 1;
    if (weapon != nWeapon)
        return 0;
    return 1;
}

// @0x140544b10
ModelFloatList::ModelFloatList() : maxValue(1.0f), minValue(0), reverse(0)
{
}

// @0x140544b70
int ModelFloatList::Load(Unk_140165cf0* pElem)
{
    XmlTokenList(pElem, "value", values);
    XmlGetAttr((class TiXmlElement*)(pElem), "min", reinterpret_cast<float&>(minValue));
    XmlGetAttr((class TiXmlElement*)(pElem), "max", reinterpret_cast<float&>(maxValue));
    XmlGetAttr((class TiXmlElement*)(pElem), "reverse", reinterpret_cast<int&>(reverse));
    return 1;
}

// @0x140544c00
int ModelFloatList::FUN_140544c00(void* pParent)
{
    return 1;
}

// @0x140544c20
float ModelFloatList::FUN_140544c20() const
{
    if (values.empty())
        return 1.0f;
    return values[rand() % (int)values.size()];
}

// @0x140544ca0
ModelGroup::ModelGroup()
{
    type = 0;
}

// @0x140544cf0
void ModelGroup::FUN_140544cf0(Unk_140165cf0* pElem)
{
    ReadSlotAttr(pElem, "name", &type);
    int nPony = 0;
    for (Unk_140165cf0* pAsset = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("asset")); pAsset != 0;
         pAsset = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pAsset))->NextSibling("asset")))
    {
        parts.push_back(ModelPart());
        ModelPart* pPart = &parts[parts.size() - 1];
        pPart->Load(pAsset);
        if (pPart->pony != 0)
            pPart->ponyIndex = nPony++;
    }
    for (Unk_140165cf0* pScale = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("scale")); pScale != 0;
         pScale = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pScale))->NextSibling("scale")))
    {
        floats.push_back(ModelFloatList());
        ModelFloatList* pFloats = &floats[floats.size() - 1];
        pFloats->Load(pScale);
    }
}

// @0x140544f00
void ModelGroup::FUN_140544f00(void* pParent)
{
}

// @0x140544f20
const ModelFloatList* ModelGroup::FUN_140544f20(size_t nIndex) const
{
    static ModelFloatList s_empty;
    if (nIndex < floats.size())
        return &floats[nIndex];
    return &s_empty;
}

// @0x140544fe0
const ModelPart* ModelGroup::FUN_140544fe0(size_t nIndex) const
{
    static ModelPart s_empty;
    if (nIndex < parts.size())
        return &parts[nIndex];
    return &s_empty;
}

// @0x140545090
size_t ModelGroup::FUN_140545090() const
{
    return floats.size();
}

// @0x1405450c0
size_t ModelGroup::FUN_1405450c0() const
{
    return parts.size();
}

// @0x1405450f0
float ModelGroup::FUN_1405450f0(int nIndex) const
{
    return FUN_140544f20(nIndex)->FUN_140544c20();
}

// @0x140545130
void ModelGroup::FUN_140545130(const CString& strName)
{
    for (unsigned i = 0; i < parts.size(); i++)
        parts[i].name0 = strName;
}

// @0x1405451a0
int ModelGroup::FUN_1405451a0() const
{
    return type;
}

// @0x1405451c0
int FUN_1405451c0(CString& strName)
{
    return FUN_14021bdc0(strName);
}

// @0x1405451e0
CString FUN_1405451e0(int nType)
{
    return Name_14021c050(nType);
}

// @0x140545220
ItemLimit::ItemLimit()
    : levelLimit(1), genderLimit(2), transferType(ItemTransferTypeNone), transferTypeVersion(0), shopSell(false),
      enableBreak(ItemEnableBreakNone), enableRegisterMeratMarket(false), exceptEnchant(false), flag6a(false),
      wedding(false), vipLevel(0)
{
}

// @0x1405452f0
int ItemLimit::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pLimit = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("limit"));
    if (pLimit != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pLimit), "genderLimit", genderLimit);
        XmlGetAttr((class TiXmlElement*)(pLimit), "levelLimit", levelLimit);
        XmlValue(pLimit, "transferType", transferType);
        XmlGetAttr((class TiXmlElement*)(pLimit), "transferTypeVersion", reinterpret_cast<int&>(transferTypeVersion));
        if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x84) && ((class TiXmlElement*)(class Unk_140165cf0*)(pLimit))->Attribute("globalTransferType") != 0)
            XmlValue(pLimit, "globalTransferType", transferType);
        XmlGetAttr((class TiXmlElement*)(pLimit), "shopSell", reinterpret_cast<bool&>(shopSell));
        XmlValue(pLimit, "enableBreak", enableBreak);
        XmlGetAttr((class TiXmlElement*)(pLimit), "enableRegisterMeratMarket", reinterpret_cast<bool&>(enableRegisterMeratMarket));
        XmlGetAttr((class TiXmlElement*)(pLimit), "exceptEnchant", reinterpret_cast<bool&>(exceptEnchant));
        XmlGetAttr((class TiXmlElement*)(pLimit), "vip", reinterpret_cast<bool&>(flag6a));
        XmlGetAttr((class TiXmlElement*)(pLimit), "wedding", reinterpret_cast<bool&>(wedding));
        XmlGetAttr((class TiXmlElement*)(pLimit), "vipLevel", reinterpret_cast<int&>(vipLevel));
        XmlTokenList(pLimit, "jobLimit", jobLimit);
        XmlTokenList(pLimit, "disableJobLimit", disableJobLimit);
        XmlTokenList(pLimit, "recommendJobs", recommendJobs);
    }
    return 1;
}

// @0x140545510
int ItemLimit::Save(void* pParent)
{
    static ItemLimit s_default;
    if (FUN_140545a80(&s_default))
        return 1;
    TiXmlElement elem("limit");
    if (jobLimit.GetCount() > 0)
    {
        CString str;
        for (size_t i = 0; i < jobLimit.GetCount(); i++)
            str.AppendFormat(",%d", jobLimit[i]);
        TrimCommas(str);
        XmlSetAttr((class TiXmlElement*)(&elem), "jobLimit", str);
    }
    if (disableJobLimit.GetCount() > 0)
    {
        CString str;
        for (size_t i = 0; i < disableJobLimit.GetCount(); i++)
            str.AppendFormat(",%d", disableJobLimit[i]);
        TrimCommas(str);
        XmlSetAttr((class TiXmlElement*)(&elem), "disableJobLimit", str);
    }
    if (recommendJobs.size() > 0)
    {
        CString str;
        for (std::set<int>::iterator it = recommendJobs.begin(); it != recommendJobs.end(); ++it)
            str.AppendFormat(",%d", *it);
        TrimCommas(str);
        XmlSetAttr((class TiXmlElement*)(&elem), "recommendJobs", FUN_14016a5c0(str, 0));
    }
    if (levelLimit != 1)
        XmlSetAttr((class TiXmlElement*)(&elem), "levelLimit", levelLimit);
    if (genderLimit != 2)
        XmlSetAttr((class TiXmlElement*)(&elem), "genderLimit", genderLimit);
    if (transferType != ItemTransferTypeNone)
        XmlSetAttr((class TiXmlElement*)(&elem), "transferType", transferType);
    if (transferTypeVersion > 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "transferTypeVersion", transferTypeVersion);
    if (shopSell)
        XmlSetAttr((class TiXmlElement*)(&elem), "shopSell", shopSell);
    if (enableBreak != ItemEnableBreakNone)
        XmlSetAttr((class TiXmlElement*)(&elem), "enableBreak", enableBreak);
    if (enableRegisterMeratMarket)
        XmlSetAttr((class TiXmlElement*)(&elem), "enableRegisterMeratMarket", enableRegisterMeratMarket);
    if (exceptEnchant)
        XmlSetAttr((class TiXmlElement*)(&elem), "exceptEnchant", exceptEnchant);
    if (flag6a)
        XmlSetAttr((class TiXmlElement*)(&elem), "vip", flag6a);
    if (wedding)
        XmlSetAttr((class TiXmlElement*)(&elem), "wedding", wedding);
    if (vipLevel != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "vipLevel", vipLevel);
    ((void*)((class TiXmlNode*)(void*)(pParent))->InsertEndChild(*(class TiXmlNode const*)(&elem)));
    return 1;
}

// @0x140545a80
bool ItemLimit::FUN_140545a80(const ItemLimit* pOther)
{
    return !FUN_140545ad0(pOther);
}

// @0x140545ad0
bool ItemLimit::FUN_140545ad0(const ItemLimit* pOther)
{
    if (genderLimit != pOther->genderLimit)
        return true;
    if (levelLimit != pOther->levelLimit)
        return true;
    if (transferType != pOther->transferType)
        return true;
    if (transferTypeVersion != pOther->transferTypeVersion)
        return true;
    if (shopSell != pOther->shopSell)
        return true;
    if (enableBreak != pOther->enableBreak)
        return true;
    if (enableRegisterMeratMarket != pOther->enableRegisterMeratMarket)
        return true;
    if (exceptEnchant != pOther->exceptEnchant)
        return true;
    if (flag6a != pOther->flag6a)
        return true;
    if (wedding != pOther->wedding)
        return true;
    if (vipLevel != pOther->vipLevel)
        return true;
    if (!IsSameArray(jobLimit, pOther->jobLimit))
        return true;
    if (!IsSameArray(disableJobLimit, pOther->disableJobLimit))
        return true;
    if (recommendJobs != pOther->recommendJobs)
        return true;
    return false;
}

// @0x140545c80
bool ItemLimit::IsJobAllowed(int nJob)
{
    if (nJob == 0)
        return false;
    for (unsigned i = 0; i < disableJobLimit.GetCount(); i++)
    {
        unsigned nDisabled = disableJobLimit[i];
        if (nDisabled == nJob)
            return false;
    }
    if (nJob == 1)
        nJob = 10;
    for (unsigned i = 0; i < jobLimit.GetCount(); i++)
    {
        unsigned nLimit = jobLimit[i];
        if (nLimit == 0)
            return true;
        if (nLimit == 1)
            return true;
        if (nLimit == nJob)
            return true;
    }
    return jobLimit.IsEmpty();
}

// @0x140545da0
bool ItemLimit::IsJobRecommended(int nJob)
{
    if (recommendJobs.empty())
        return true;
    if (nJob == 1)
        nJob = 10;
    if (recommendJobs.find(nJob) != recommendJobs.end())
        return true;
    return false;
}

// @0x140545e40
bool ItemLimit::FUN_140545e40()
{
    if (disableJobLimit.IsEmpty() && jobLimit.IsEmpty())
        return false;
    if (!disableJobLimit.IsEmpty())
        return true;
    if (!jobLimit.IsEmpty())
    {
        for (unsigned i = 0; i < jobLimit.GetCount(); i++)
        {
            unsigned nLimit = jobLimit[i];
            if (nLimit == 0)
                return false;
            if (nLimit == 1)
                return false;
        }
        return true;
    }
    return false;
}

// @0x140545f30
bool ItemLimit::FUN_140545f30()
{
    switch (transferType)
    {
    case 0:
    case 3:
    case 4:
    case 5:
        return true;
    }
    return false;
}

// @0x140545f70
unsigned ItemLimit::GetRecommendJobMask()
{
    if (recommendJobs.empty())
        return 0xfff;
    unsigned nFlags = 0;
    for (int nJob : recommendJobs)
        nFlags |= FUN_1402227e0(nJob, 0);
    return nFlags;
}

// @0x140546030
unsigned ItemLimit::FUN_140546030()
{
    if (jobLimit.IsEmpty())
        return 0;
    unsigned nFlags = 0;
    size_t nCount = jobLimit.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        unsigned nJob = jobLimit[i];
        if (nJob == 0)
            return 0xfff;
        nFlags |= FUN_1402227e0(nJob, 0);
    }
    return nFlags;
}

// @0x1405460f0
ItemPeriod::ItemPeriod() : usePeriod(0), expirationType(ItemExpirationTypeNone), numberOfWeeksMonths(0)
{
}

// @0x140546150
int ItemPeriod::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pLife = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("life"));
    if (pLife != 0)
    {
        ATL::CAtlArray<int> values;
        CString strExpiration;
        XmlGetAttr((class TiXmlElement*)(pLife), "usePeriod", reinterpret_cast<int&>(usePeriod));
        XmlGetAttr((class TiXmlElement*)(pLife), "expirationPeriod", strExpiration);
        XmlSplit(strExpiration, values, "-");
        if (values.GetCount() == 6)
            expiration = CMsTime(values[0], values[1], values[2], values[3], values[4], values[5]);
        XmlValue(pLife, "expirationType", expirationType);
        XmlGetAttr((class TiXmlElement*)(pLife), "numberOfWeeksMonths", numberOfWeeksMonths);
        XmlGetAttr((class TiXmlElement*)(pLife), "termTag", termTag);
    }
    return 1;
}

// @0x140546370
int ItemPeriod::Save(void* pParent)
{
    if (usePeriod == 0 && expiration.Get() == 0 && expirationType == ItemExpirationTypeNone && numberOfWeeksMonths == 0 &&
        termTag.IsEmpty())
        return 1;
    TiXmlElement elem("life");
    if (usePeriod > 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "usePeriod", usePeriod);
    CString strExpiration("");
    if (expiration.Get() > 0)
    {
        strExpiration.Format("%04d-%02d-%02d-%02d-%02d-%02d", expiration.GetYear(), expiration.GetMonth(),
                             expiration.GetDay(), expiration.GetHour(), expiration.GetMinute(), expiration.GetSecond());
    }
    if (!strExpiration.IsEmpty())
        XmlSetAttr((class TiXmlElement*)(&elem), "expirationPeriod", strExpiration);
    if (expirationType != ItemExpirationTypeNone)
        XmlSetAttr((class TiXmlElement*)(&elem), "expirationType", expirationType);
    if (numberOfWeeksMonths != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "numberOfWeeksMonths", numberOfWeeksMonths);
    if (!termTag.IsEmpty())
        XmlSetAttr((class TiXmlElement*)(&elem), "termTag", termTag);
    ((void*)((class TiXmlNode*)(void*)(pParent))->InsertEndChild(*(class TiXmlNode const*)(&elem)));
    return 1;
}

// @0x140546620
bool ItemPeriod::FUN_140546620(const ItemPeriod* pOther)
{
    if (usePeriod != pOther->usePeriod)
        return true;
    if (expiration != pOther->expiration)
        return true;
    if (expirationType != pOther->expirationType)
        return true;
    if (numberOfWeeksMonths != pOther->numberOfWeeksMonths)
        return true;
    if (termTag != pOther->termTag)
        return true;
    return false;
}

// @0x1405466d0
int ItemPeriod::FUN_1405466d0()
{
    return usePeriod > 0 || expiration.Get() > 0 || expirationType != ItemExpirationTypeNone || !termTag.IsEmpty();
}

// @0x140546740
ItemSkill::ItemSkill() : skillId(0), skillLevel(1)
{
}

// @0x140546770
int ItemSkill::LoadXml(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pSkill = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("skill"));
    if (pSkill != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pSkill), "skillID", skillId);
        XmlGetAttr((class TiXmlElement*)(pSkill), "skillLevel", reinterpret_cast<unsigned short&>(skillLevel));
    }
    return 1;
}

// @0x1405467f0
int ItemSkill::FUN_1405467f0(void* pParent)
{
    return 1;
}

// @0x140546810
bool ItemSkill::FUN_140546810(const ItemSkill* pOther)
{
    if (skillId != pOther->skillId)
        return true;
    if (skillLevel != pOther->skillLevel)
        return true;
    return false;
}

// @0x140546860
MsTransform::MsTransform()
{
    scale = 1.0f;
}

// @0x1405468d0
void MsTransform::LoadXml(Unk_140165cf0* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "position", *(class NiPoint3*)&static_cast<class efd::Point3&>(position));
    XmlGetAttr((class TiXmlElement*)(pElem), "rotation", *(class NiPoint3*)&static_cast<class efd::Point3&>(rotation));
    XmlGetAttr((class TiXmlElement*)(pElem), "scale", reinterpret_cast<float&>(scale));
}

// @0x140546940
void MsTransform::SaveXml(void* pElem)
{
    if (position != efd::Point3::ZERO)
        FUN_140874ad0(pElem, "position", position);
    if (rotation != efd::Point3::ZERO)
        FUN_140874ad0(pElem, "rotation", rotation);
    if (scale != 1.0f)
        XmlSetAttr((class TiXmlElement*)(pElem), "scale", scale);
}

// @0x140546a00
ItemModelHead::ItemModelHead() : flag10(false), flag11(false), unknown14(0), scale(false), rotation(false),
    translation(false), capAttach(false)
{
}

// @0x140546a90
int ItemModelHead::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pCustomize = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("customize"));
    if (pCustomize == 0)
        return 1;
    XmlGetAttr((class TiXmlElement*)(pCustomize), "color", reinterpret_cast<bool&>(flag10));
    XmlGetAttr((class TiXmlElement*)(pCustomize), "colorPalette", unknown14);
    CString strIds = Unk_ReadString((class Unk_XmlNode*)(pCustomize), "defaultColorIndex", "-1");
    XmlSplit(strIds, ids, ",");
    CString strDelays = Unk_ReadString((class Unk_XmlNode*)(pCustomize), "colorDelay", "");
    XmlSplit(strDelays, unknown30, ",");
    XmlGetAttr((class TiXmlElement*)(pCustomize), "scale", reinterpret_cast<bool&>(scale));
    XmlGetAttr((class TiXmlElement*)(pCustomize), "rotation", reinterpret_cast<bool&>(rotation));
    XmlGetAttr((class TiXmlElement*)(pCustomize), "translation", reinterpret_cast<bool&>(translation));
    XmlGetAttr((class TiXmlElement*)(pCustomize), "capAttach", reinterpret_cast<bool&>(capAttach));
    flag11 = ids.size() > 1;
    if (unknown14 == 0)
        flag10 = false;
    Unk_140165cf0* pCapTransform = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pCustomize))->FirstChild("capTransform"));
    if (pCapTransform != 0)
    {
        handle.AssignRaw(new MsTransform);
        handle->LoadXml(pCapTransform);
    }
    return 1;
}

// The joined id/delay lists are built and trimmed but never written (as in the original).
// @0x140546d70
int ItemModelHead::Save(void* pParent)
{
    TiXmlElement elem("customize");
    if (flag10)
        XmlSetAttr((class TiXmlElement*)(&elem), "color", flag10 ? 1 : 0);
    if (unknown14 != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "colorPalette", unknown14);
    if (ids.size() > 0 && ids[0] != -1)
    {
        CString str;
        for (int nId : ids)
            str.AppendFormat(",%s", nId);
        TrimCommas(str);
    }
    if (unknown30.size() > 0 && unknown30[0] != 0)
    {
        CString str;
        for (int nDelay : unknown30)
            str.AppendFormat(",%s", nDelay);
        TrimCommas(str);
    }
    if (scale)
        XmlSetAttr((class TiXmlElement*)(&elem), "scale", 1);
    if (rotation)
        XmlSetAttr((class TiXmlElement*)(&elem), "rotation", 1);
    if (translation)
        XmlSetAttr((class TiXmlElement*)(&elem), "translation", 1);
    if (capAttach)
        XmlSetAttr((class TiXmlElement*)(&elem), "capAttach", 1);
    if (handle.get() != 0)
    {
        TiXmlElement transform("transform");
        handle->SaveXml(&transform);
        if (transform.HasContent())
            ((void*)((class TiXmlNode*)(void*)(&elem))->InsertEndChild(*(class TiXmlNode const*)(&transform)));
    }
    if (elem.HasContent())
        ((void*)((class TiXmlNode*)(void*)(pParent))->InsertEndChild(*(class TiXmlNode const*)(&elem)));
    return 1;
}

// @0x140547130
bool ItemModelHead::FUN_140547130()
{
    return scale;
}

// @0x140547150
bool ItemModelHead::FUN_140547150()
{
    return rotation;
}

// @0x140547170
bool ItemModelHead::FUN_140547170()
{
    return translation;
}

// @0x140547190
bool ItemModelHead::FUN_140547190()
{
    return flag10;
}

// @0x1405471b0
bool ItemModelHead::FUN_1405471b0()
{
    return capAttach;
}

// @0x1405471d0
bool ItemModelHead::FUN_1405471d0()
{
    return FUN_140547150() || FUN_140547170() || FUN_140547130();
}

// @0x140547230
bool ItemModelHead::FUN_140547230()
{
    return flag11;
}

// @0x140547250
int ItemModelHead::FUN_140547250()
{
    return unknown14;
}

// @0x140547270
int ItemModelHead::FUN_140547270(int nIndex) const
{
    int nCount = (int)ids.size();
    if (nCount == 0 || nCount <= nIndex)
        return -1;
    return ids[nIndex];
}

// @0x1405472d0
int ItemModelHead::FUN_1405472d0(int nIndex) const
{
    int nCount = (int)unknown30.size();
    if (nCount == 0 || nCount <= nIndex)
        return 0;
    return unknown30[nIndex];
}

// @0x140547330
size_t ItemModelHead::FUN_140547330()
{
    return ids.size();
}

// @0x140547360
MsTransform* ItemModelHead::FUN_140547360()
{
    return handle.get();
}

// @0x140547390
ItemMaterial::ItemMaterial()
{
    unknown0 = 0;
    attack = 0;
}

// @0x1405473c0
int ItemMaterial::FUN_1405473c0(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pMaterial = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("material"));
    if (pMaterial != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pMaterial), "ui", reinterpret_cast<int&>(unknown0));
        XmlGetAttr((class TiXmlElement*)(pMaterial), "attack", reinterpret_cast<int&>(attack));
    }
    return 1;
}

// @0x140547440
int ItemMaterial::FUN_140547440(void* pParent)
{
    return 1;
}

// @0x140547460
bool ItemMaterial::FUN_140547460(const ItemMaterial* pOther)
{
    if (unknown0 != pOther->unknown0)
        return true;
    if (attack != pOther->attack)
        return true;
    return false;
}

// @0x1405474a0
ItemProperty::ItemProperty()
    : flag08(false), flag09(false), collection(0), doNotPreview(0), applyFatiguePenalty(0), slotMax(1), gearScore(0),
      remakeDisable(false), tradableCountDeduction(0), unlimitedEnchantMaxGrade(0), socketDataId(0),
      rePackingLimitCount(0), rePackingItemConsumeCount(0), moveDisable(false)
{
}

// @0x1405475c0
void ItemProperty::Load(Unk_140165cf0* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "slotMax", slotMax);
    slotMax = (std::min<unsigned>)(slotMax, 99999);
    XmlGetAttr((class TiXmlElement*)(pElem), "collection", reinterpret_cast<int&>(collection));
    XmlGetAttr((class TiXmlElement*)(pElem), "doNotPreview", reinterpret_cast<int&>(doNotPreview));
    XmlGetAttr((class TiXmlElement*)(pElem), "applyFatiguePenalty", reinterpret_cast<int&>(applyFatiguePenalty));
    XmlGetAttr((class TiXmlElement*)(pElem), "category", category);
    XmlGetAttr((class TiXmlElement*)(pElem), "blackMarketCategory", blackMarketCategory);
    XmlGetAttr((class TiXmlElement*)(pElem), "slotIcon", slotIcon);
    XmlGetAttr((class TiXmlElement*)(pElem), "movie", movie);
    XmlGetAttr((class TiXmlElement*)(pElem), "remakeDisable", reinterpret_cast<bool&>(remakeDisable));
    Unk_140165cf0* pSell = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("sell"));
    if (pSell != 0)
        XmlTokenList(pSell, "price", sellPrice);
    XmlGetAttr((class TiXmlElement*)(pElem), "gearScore", gearScore);
    XmlGetAttr((class TiXmlElement*)(pElem), "tradableCountDeduction", reinterpret_cast<int&>(tradableCountDeduction));
    XmlGetAttr((class TiXmlElement*)(pElem), "unlimitedEnchantMaxGrade", reinterpret_cast<int&>(unlimitedEnchantMaxGrade));
    XmlGetAttr((class TiXmlElement*)(pElem), "rePackingLimitCount", reinterpret_cast<int&>(rePackingLimitCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "rePackingItemConsumeCount", reinterpret_cast<int&>(rePackingItemConsumeCount));
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x84) && ((class TiXmlElement*)(class Unk_140165cf0*)(pElem))->Attribute("globalRePackingLimitCount") != 0)
        XmlGetAttr((class TiXmlElement*)(pElem), "globalRePackingLimitCount", reinterpret_cast<int&>(rePackingLimitCount));
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x84) && ((class TiXmlElement*)(class Unk_140165cf0*)(pElem))->Attribute("globalRePackingItemConsumeCount") != 0)
        XmlGetAttr((class TiXmlElement*)(pElem), "globalRePackingItemConsumeCount", reinterpret_cast<int&>(rePackingItemConsumeCount));
    CString strScrollIds;
    XmlGetAttr((class TiXmlElement*)(pElem), "rePackingScrollID", strScrollIds);
    if (!strScrollIds.IsEmpty())
        XmlSplit(strScrollIds, rePackingScrollID, ",");
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x84) && ((class TiXmlElement*)(class Unk_140165cf0*)(pElem))->Attribute("globalRePackingScrollID") != 0)
    {
        CString strGlobalScrollIds;
        XmlGetAttr((class TiXmlElement*)(pElem), "globalRePackingScrollID", strGlobalScrollIds);
        if (!strGlobalScrollIds.IsEmpty())
            XmlSplit(strGlobalScrollIds, rePackingScrollID, ",");
    }
    XmlGetAttr((class TiXmlElement*)(pElem), "socketDataId", socketDataId);
    XmlGetAttr((class TiXmlElement*)(pElem), "moveDisable", reinterpret_cast<bool&>(moveDisable));
}

// @0x1405479a0
void ItemProperty::FUN_1405479a0(void* pElem)
{
    if (slotMax != 1)
        XmlSetAttr((class TiXmlElement*)(pElem), "slotMax", slotMax);
    if (!slotIcon.IsEmpty())
        XmlSetAttr((class TiXmlElement*)(pElem), "slotIcon", slotIcon);
    if (!category.IsEmpty())
        XmlSetAttr((class TiXmlElement*)(pElem), "category", category);
    if (!blackMarketCategory.IsEmpty())
        XmlSetAttr((class TiXmlElement*)(pElem), "blackMarketCategory", blackMarketCategory);
    if (remakeDisable)
        XmlSetAttr((class TiXmlElement*)(pElem), "remakeDisable", remakeDisable);
    if (!movie.IsEmpty())
        XmlSetAttr((class TiXmlElement*)(pElem), "movie", movie);
    if (gearScore != 0)
        XmlSetAttr((class TiXmlElement*)(pElem), "gearScore", gearScore);
    if (unlimitedEnchantMaxGrade > 0)
        XmlSetAttr((class TiXmlElement*)(pElem), "unlimitedEnchantMaxGrade", unlimitedEnchantMaxGrade);
    if (tradableCountDeduction > 0)
        XmlSetAttr((class TiXmlElement*)(pElem), "tradableCountDeduction", tradableCountDeduction);
    if (rePackingLimitCount != 0)
        XmlSetAttr((class TiXmlElement*)(pElem), "rePackingLimitCount", rePackingLimitCount);
    if (rePackingItemConsumeCount != 0)
        XmlSetAttr((class TiXmlElement*)(pElem), "rePackingItemConsumeCount", rePackingItemConsumeCount);
    if (!rePackingScrollID.IsEmpty())
    {
        CString str;
        for (unsigned i = 0; i < rePackingScrollID.GetCount(); i++)
            str.AppendFormat(",%d", rePackingScrollID[i]);
        TrimCommas(str);
        XmlSetAttr((class TiXmlElement*)(pElem), "rePackingScrollID", str);
    }
    if (moveDisable)
        XmlSetAttr((class TiXmlElement*)(pElem), "moveDisable", moveDisable);
    if (collection != 0)
        XmlSetAttr((class TiXmlElement*)(pElem), "collection", collection);
    if (doNotPreview != 0)
        XmlSetAttr((class TiXmlElement*)(pElem), "doNotPreview", doNotPreview);
    if (socketDataId != 0)
        XmlSetAttr((class TiXmlElement*)(pElem), "socketDataId", socketDataId);
    if (applyFatiguePenalty != 0)
        XmlSetAttr((class TiXmlElement*)(pElem), "applyFatiguePenalty", applyFatiguePenalty);
    if (sellPrice.size() > 0)
    {
        CString str;
        for (size_t i = 0; i < sellPrice.size(); i++)
            str.AppendFormat(",%I64d", sellPrice[i]);
        TrimCommas(str);
        if (!str.IsEmpty())
        {
            TiXmlElement sell("sell");
            if (!str.IsEmpty())
                XmlSetAttr((class TiXmlElement*)(&sell), "price", str);
            ((void*)((class TiXmlNode*)(void*)(pElem))->InsertEndChild(*(class TiXmlNode const*)(&sell)));
        }
    }
}

// @0x140547ec0
bool ItemProperty::FUN_140547ec0(const ItemProperty* pOther)
{
    if (slotMax != pOther->slotMax)
        return true;
    if (collection != pOther->collection)
        return true;
    if (doNotPreview != pOther->doNotPreview)
        return true;
    if (applyFatiguePenalty != pOther->applyFatiguePenalty)
        return true;
    if (category != pOther->category)
        return true;
    if (blackMarketCategory != pOther->blackMarketCategory)
        return true;
    if (slotIcon != pOther->slotIcon)
        return true;
    if (movie != pOther->movie)
        return true;
    if (remakeDisable != pOther->remakeDisable)
        return true;
    if (!IsSameVector(sellPrice, pOther->sellPrice))
        return true;
    if (gearScore != pOther->gearScore)
        return true;
    if (tradableCountDeduction != pOther->tradableCountDeduction)
        return true;
    if (unlimitedEnchantMaxGrade != pOther->unlimitedEnchantMaxGrade)
        return true;
    if (rePackingLimitCount != pOther->rePackingLimitCount)
        return true;
    if (rePackingItemConsumeCount != pOther->rePackingItemConsumeCount)
        return true;
    if (!IsSameArray(rePackingScrollID, pOther->rePackingScrollID))
        return true;
    if (socketDataId != pOther->socketDataId)
        return true;
    if (moveDisable != pOther->moveDisable)
        return true;
    return false;
}

// @0x1405480f0
__int64 ItemProperty::FUN_1405480f0(int nRarity)
{
    if (sellPrice.empty())
        return 0;
    if (sellPrice.size() == 1)
        return sellPrice[0];
    MS2_ASSERT_MSG_AT(0x623, L"m_sellPrice.size() == 6", sellPrice.size() == 6);
    if (sellPrice.size() != 6)
        return 0;
    return sellPrice[nRarity - 1];
}

// @0x1405481d0
CString* ItemProperty::FUN_1405481d0()
{
    return &slotIcon;
}

// @0x1405481f0
ItemInstallData::ItemInstallData()
    : asset(""), preset(""), space(0), placeable(0), stackable(0), attachable(0), wall(0), cubeProp(0), animatable(0),
      generatePhysX(0), unchangeable(0), cannotStackAttach(0), objCode(0), staticAngle(0), physXdimension(0, 0, 0),
      propCollisionGroup(0), useInstancing(true)
{
}

// @0x140548320
int ItemInstallData::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pInstall = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("install"));
    if (pInstall != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pInstall), "placeable", reinterpret_cast<int&>(placeable));
        XmlGetAttr((class TiXmlElement*)(pInstall), "unchangeable", reinterpret_cast<int&>(unchangeable));
        XmlGetAttr((class TiXmlElement*)(pInstall), "cannotStackAttach", reinterpret_cast<int&>(cannotStackAttach));
        XmlGetAttr((class TiXmlElement*)(pInstall), "stackable", reinterpret_cast<int&>(stackable));
        XmlGetAttr((class TiXmlElement*)(pInstall), "attachable", reinterpret_cast<int&>(attachable));
        XmlGetAttr((class TiXmlElement*)(pInstall), "wall", reinterpret_cast<int&>(wall));
        XmlGetAttr((class TiXmlElement*)(pInstall), "generatePhysX", reinterpret_cast<int&>(generatePhysX));
        XmlGetAttr((class TiXmlElement*)(pInstall), "cubeProp", reinterpret_cast<int&>(cubeProp));
        XmlGetAttr((class TiXmlElement*)(pInstall), "space", reinterpret_cast<int&>(space));
        XmlGetAttr((class TiXmlElement*)(pInstall), "animatable", reinterpret_cast<int&>(animatable));
        XmlGetAttr((class TiXmlElement*)(pInstall), "objCode", objCode);
        XmlGetAttr((class TiXmlElement*)(pInstall), "staticAngle", reinterpret_cast<float&>(staticAngle));
        XmlGetAttr((class TiXmlElement*)(pInstall), "asset", asset);
        XmlGetAttr((class TiXmlElement*)(pInstall), "preset", preset);
        XmlGetAttr((class TiXmlElement*)(pInstall), "mapAttribute", mapAttribute);
        XmlGetAttr((class TiXmlElement*)(pInstall), "propCollisionGroup", reinterpret_cast<int&>(propCollisionGroup));
        XmlGetAttr((class TiXmlElement*)(pInstall), "useInstancing", reinterpret_cast<bool&>(useInstancing));
        const char* pszDimension = ((class TiXmlElement*)(class Unk_140165cf0*)(pInstall))->Attribute("physXdimension");
        if (pszDimension != 0)
            physXdimension = FUN_14028f060(FUN_140188f50(pszDimension, 0));
    }
    return 1;
}

// @0x1405485b0
int ItemInstallData::Save(void* pParent)
{
    static ItemInstallData s_default;
    if (FUN_140548a50(&s_default))
        return 1;
    TiXmlElement elem("install");
    if (placeable != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "placeable", placeable);
    if (unchangeable != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "unchangeable", unchangeable);
    if (cannotStackAttach != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "cannotStackAttach", cannotStackAttach);
    if (stackable != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "stackable", stackable);
    if (attachable != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "attachable", attachable);
    if (wall != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "wall", wall);
    if (generatePhysX != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "generatePhysX", generatePhysX);
    if (cubeProp != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "cubeProp", cubeProp);
    if (space != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "space", space);
    if (animatable != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "animatable", animatable);
    if (objCode != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "objCode", objCode);
    if (staticAngle != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "staticAngle", staticAngle);
    if (!asset.IsEmpty())
        XmlSetAttr((class TiXmlElement*)(&elem), "asset", asset);
    if (!preset.IsEmpty())
        XmlSetAttr((class TiXmlElement*)(&elem), "preset", preset);
    if (!useInstancing)
        XmlSetAttr((class TiXmlElement*)(&elem), "useInstancing", useInstancing);
    if (physXdimension != efd::Point3::ZERO)
    {
        CString str;
        str.Format("%.6f, %.6f, %.6f", physXdimension.x, physXdimension.y, physXdimension.z);
        XmlSetAttr((class TiXmlElement*)(&elem), "physXdimension", str);
    }
    if (!mapAttribute.IsEmpty())
        XmlSetAttr((class TiXmlElement*)(&elem), "mapAttribute", mapAttribute);
    if (propCollisionGroup != 0)
        XmlSetAttr((class TiXmlElement*)(&elem), "propCollisionGroup", propCollisionGroup);
    ((void*)((class TiXmlNode*)(void*)(pParent))->InsertEndChild(*(class TiXmlNode const*)(&elem)));
    return 1;
}

// @0x140548a50
bool ItemInstallData::FUN_140548a50(const ItemInstallData* pOther)
{
    return !FUN_140548aa0(pOther);
}

// @0x140548aa0
bool ItemInstallData::FUN_140548aa0(const ItemInstallData* pOther)
{
    if (placeable != pOther->placeable)
        return true;
    if (unchangeable != pOther->unchangeable)
        return true;
    if (cannotStackAttach != pOther->cannotStackAttach)
        return true;
    if (stackable != pOther->stackable)
        return true;
    if (attachable != pOther->attachable)
        return true;
    if (wall != pOther->wall)
        return true;
    if (generatePhysX != pOther->generatePhysX)
        return true;
    if (cubeProp != pOther->cubeProp)
        return true;
    if (space != pOther->space)
        return true;
    if (animatable != pOther->animatable)
        return true;
    if (objCode != pOther->objCode)
        return true;
    if (staticAngle != pOther->staticAngle)
        return true;
    if (asset != pOther->asset)
        return true;
    if (preset != pOther->preset)
        return true;
    if (mapAttribute != pOther->mapAttribute)
        return true;
    if (propCollisionGroup != pOther->propCollisionGroup)
        return true;
    if (useInstancing != pOther->useInstancing)
        return true;
    if (physXdimension != pOther->physXdimension)
        return true;
    return false;
}

// @0x140548cb0
int ItemInstallData::FUN_140548cb0()
{
    return stackable;
}

// @0x140548cd0
bool ItemInstallData::FUN_140548cd0()
{
    const int nMask = 6;
    return (space & nMask) > 0;
}

// @0x140548d10
bool ItemInstallData::FUN_140548d10()
{
    const int nMask = 1;
    return (space & nMask) > 0;
}

// @0x140548d50
bool ItemInstallData::FUN_140548d50()
{
    if ((stackable & 1) != 0 && (stackable & 2) != 0 && (stackable & 4) != 0)
        return true;
    return false;
}

// @0x140548d90
ItemHousing::ItemHousing()
    : price(0), filter(ItemHousingFilterDefault), categoryIndex(ItemHousingCategoryDefault), priceCount(1),
      trophyID(0), trophyLevel(1), interiorLevel(1), hasPrice(false), setItemID(0), doNotInstallBlueprint(false)
{
}

// @0x140548e50
int ItemHousing::LoadXml(Unk_140165cf0* pElem, int nItemId)
{
    Unk_140165cf0* pHousing = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("housing"));
    if (pHousing != 0)
    {
        XmlValue(pHousing, "filter", filter);
        XmlValue(pHousing, "categoryIndex", categoryIndex);
        XmlTokenList(pHousing, "categoryTag", categoryTag);
        XmlGetAttr((class TiXmlElement*)(pHousing), "trophyID", trophyID);
        XmlGetAttr((class TiXmlElement*)(pHousing), "trophyLevel", trophyLevel);
        XmlGetAttr((class TiXmlElement*)(pHousing), "interiorLevel", reinterpret_cast<unsigned short&>(interiorLevel));
        FUN_140552df0()->GetHousing(nItemId, &hasPrice, &price, &priceCount);
        XmlGetAttr((class TiXmlElement*)(pHousing), "setItemID", setItemID);
        XmlQuery((class TiXmlElement*)(pHousing), "doNotInstallBlueprint", doNotInstallBlueprint);
    }
    return 1;
}

// @0x140548fe0
void ItemHousing::LoadElement(Unk_140165cf0* pElem, int nItemId)
{
    itemId = nItemId;
    XmlValue(pElem, "filter", filter);
    XmlValue(pElem, "categoryIndex", categoryIndex);
    XmlTokenList(pElem, "categoryTag", categoryTag);
    XmlGetAttr((class TiXmlElement*)(pElem), "trophyID", trophyID);
    XmlGetAttr((class TiXmlElement*)(pElem), "trophyLevel", trophyLevel);
    XmlGetAttr((class TiXmlElement*)(pElem), "interiorLevel", reinterpret_cast<unsigned short&>(interiorLevel));
    if (FUN_140552df0() != 0)
        FUN_140552df0()->GetHousing(nItemId, &hasPrice, &price, &priceCount);
    XmlGetAttr((class TiXmlElement*)(pElem), "setItemID", setItemID);
    XmlQuery((class TiXmlElement*)(pElem), "doNotInstallBlueprint", doNotInstallBlueprint);
}

// @0x140549160
int ItemHousing::Save(void* pParent)
{
    static ItemHousing s_default;
    if (FUN_140549380(&s_default))
    {
        TiXmlElement elem("housing");
        if (filter != ItemHousingFilterDefault)
            XmlSetAttr((class TiXmlElement*)(&elem), "filter", filter);
        if (categoryIndex != ItemHousingCategoryDefault)
            XmlSetAttr((class TiXmlElement*)(&elem), "categoryIndex", categoryIndex);
        if (trophyID != 0)
            XmlSetAttr((class TiXmlElement*)(&elem), "trophyID", trophyID);
        if (trophyLevel != 1)
            XmlSetAttr((class TiXmlElement*)(&elem), "trophyLevel", trophyLevel);
        if (interiorLevel != 1)
            XmlSetAttr((class TiXmlElement*)(&elem), "interiorLevel", interiorLevel);
        if (setItemID != 0)
            XmlSetAttr((class TiXmlElement*)(&elem), "setItemID", setItemID);
        if (doNotInstallBlueprint)
            XmlSetAttr((class TiXmlElement*)(&elem), "doNotInstallBlueprint", doNotInstallBlueprint);
        ((void*)((class TiXmlNode*)(void*)(pParent))->InsertEndChild(*(class TiXmlNode const*)(&elem)));
    }
    return 1;
}

// @0x140549380
bool ItemHousing::FUN_140549380(const ItemHousing* pOther)
{
    if (filter != pOther->filter)
        return true;
    if (categoryIndex != pOther->categoryIndex)
        return true;
    if (categoryTag != pOther->categoryTag)
        return true;
    if (trophyID != pOther->trophyID)
        return true;
    if (trophyLevel != pOther->trophyLevel)
        return true;
    if (interiorLevel != pOther->interiorLevel)
        return true;
    if (setItemID != pOther->setItemID)
        return true;
    if (doNotInstallBlueprint != pOther->doNotInstallBlueprint)
        return true;
    return false;
}

// @0x140549470
int ItemHousing::FUN_140549470(int nItemId, __int64 nUid, __int64 nUgc)
{
    if (!hasPrice)
        return 0;
    if (FUN_14053fa40(nItemId))
    {
        unsigned nCount = FUN_141901d20(nItemId, nUid, nUgc);
        if (nCount > 0)
            return 0;
    }
    return 1;
}

// @0x1405494e0
int ItemHousing::FUN_1405494e0()
{
    return itemId;
}

// @0x140549500
ItemFusion::ItemFusion()
{
    fusionable = 0;
}

// @0x140549520
int ItemFusion::LoadXml(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pFusion = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("fusion"));
    if (pFusion != 0)
        XmlGetAttr((class TiXmlElement*)(pFusion), "fusionable", reinterpret_cast<int&>(fusionable));
    return 1;
}

// @0x140549580
int ItemFusion::FUN_140549580(void* pParent)
{
    return 1;
}

// @0x1405495a0
ItemUccMesh::ItemUccMesh()
{
}

// @0x1405495d0
int ItemUccMesh::LoadXml(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pUcc = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("ucc"));
    if (pUcc != 0)
        XmlGetAttr((class TiXmlElement*)(pUcc), "mesh", mesh);
    return 1;
}

// @0x140549630
int ItemUccMesh::SaveXml(void* pParent)
{
    if (!mesh.IsEmpty())
    {
        TiXmlElement elem("ucc");
        XmlSetAttr((class TiXmlElement*)(&elem), "mesh", mesh);
        ((void*)((class TiXmlNode*)(void*)(pParent))->InsertEndChild(*(class TiXmlNode const*)(&elem)));
    }
    return 1;
}

// @0x1405496c0
ItemEffect::ItemEffect() : enchantShape(1), sameBattleIdle(false), sameCharacterBattleIdle(false)
{
}

// @0x140549740
int ItemEffect::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pEffect = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("effect"));
    if (pEffect != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pEffect), "enchantShape", reinterpret_cast<int&>(enchantShape));
        XmlGetAttr((class TiXmlElement*)(pEffect), "idle", idle);
        XmlGetAttr((class TiXmlElement*)(pEffect), "battleIdle", battleIdle);
        XmlGetAttr((class TiXmlElement*)(pEffect), "characterIdle", characterIdle);
        XmlGetAttr((class TiXmlElement*)(pEffect), "characterBattleIdle", characterBattleIdle);
        if (!idle.IsEmpty() && idle.CompareNoCase(battleIdle) == 0)
            sameBattleIdle = true;
        if (!characterIdle.IsEmpty() && characterIdle.CompareNoCase(characterBattleIdle) == 0)
            sameCharacterBattleIdle = true;
    }
    return 1;
}

// @0x1405498b0
int ItemEffect::Save(void* pParent)
{
    if (FUN_140549b10())
    {
        TiXmlElement elem("effect");
        if (enchantShape != 1)
            XmlSetAttr((class TiXmlElement*)(&elem), "enchantShape", enchantShape);
        if (!idle.IsEmpty())
            XmlSetAttr((class TiXmlElement*)(&elem), "idle", idle);
        if (!battleIdle.IsEmpty())
            XmlSetAttr((class TiXmlElement*)(&elem), "battleIdle", battleIdle);
        if (!characterIdle.IsEmpty())
            XmlSetAttr((class TiXmlElement*)(&elem), "characterIdle", characterIdle);
        if (!characterBattleIdle.IsEmpty())
            XmlSetAttr((class TiXmlElement*)(&elem), "characterBattleIdle", characterBattleIdle);
        ((void*)((class TiXmlNode*)(void*)(pParent))->InsertEndChild(*(class TiXmlNode const*)(&elem)));
    }
    return 1;
}

// @0x140549a40
bool ItemEffect::FUN_140549a40(const ItemEffect* pOther)
{
    if (enchantShape != pOther->enchantShape)
        return true;
    if (idle != pOther->idle)
        return true;
    if (battleIdle != pOther->battleIdle)
        return true;
    if (characterIdle != pOther->characterIdle)
        return true;
    if (characterBattleIdle != pOther->characterBattleIdle)
        return true;
    return false;
}

// @0x140549b10
bool ItemEffect::FUN_140549b10()
{
    if (enchantShape != 1)
        return true;
    if (!idle.IsEmpty())
        return true;
    if (!battleIdle.IsEmpty())
        return true;
    if (!characterIdle.IsEmpty())
        return true;
    if (!characterBattleIdle.IsEmpty())
        return true;
    return false;
}

// @0x140549bb0
ItemAdditionalEffect::ItemAdditionalEffect()
{
    dropEffect = 0;
}

// @0x140549c00
int ItemAdditionalEffect::FUN_140549c00(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pEffect = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("AdditionalEffect"));
    if (pEffect != 0)
    {
        CString strIds = Unk_ReadString((class Unk_XmlNode*)(pEffect), "id", "");
        XmlSplit(strIds, ids, ",");
        CString strLevels = Unk_ReadString((class Unk_XmlNode*)(pEffect), "level", "");
        XmlSplit(strLevels, levels, ",");
        XmlGetBool((class TiXmlElement*)(pEffect), "dropEffect", *(int*)(&dropEffect));
    }
    return 1;
}

// @0x140549d40
int ItemAdditionalEffect::FUN_140549d40(void* pParent)
{
    return 1;
}

// @0x140549d60
bool ItemAdditionalEffect::FUN_140549d60(const ItemAdditionalEffect* pOther)
{
    if (!IsSameArray(ids, pOther->ids))
        return true;
    if (!IsSameArray(levels, pOther->levels))
        return true;
    if (dropEffect != pOther->dropEffect)
        return true;
    return false;
}

// @0x140549de0
unsigned ItemAdditionalEffect::FUN_140549de0()
{
    if (ids.IsEmpty())
        return 0;
    return ids.GetAt(0);
}

// @0x140549e20
unsigned short ItemAdditionalEffect::FUN_140549e20()
{
    if (levels.IsEmpty())
        return 0;
    return levels.GetAt(0);
}

// ---- ItemFunction -------------------------------------------------------------------------------------------------------
// The unit's two-argument log call (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
template <class T, class U>
inline void Unk_ItemDataLog(CLogString* log, int level, int category, const wchar_t* format, const T& first,
                            const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// @0x140549e70
ItemFunction::ItemFunction()
    : arg0(0), arg1(0), arg2(0)
{
}

// @0x140549f00
int ItemFunction::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* p = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("function"));
    if (p != 0)
    {
        XmlGetAttr((class TiXmlElement*)(p), "name", name);
        XmlGetAttr((class TiXmlElement*)(p), "parameter", name2);
        XmlGetAttr((class TiXmlElement*)(p), "param1", reinterpret_cast<int&>(arg0));
        XmlGetAttr((class TiXmlElement*)(p), "param2", reinterpret_cast<int&>(arg1));
        XmlGetAttr((class TiXmlElement*)(p), "param3", reinterpret_cast<int&>(arg2));
        // "<key=value,...>" is parsed as xml values, anything else as a comma separated argument list
        bool bXml = name2.GetLength() > 1 && name2.Left(1) == L"<" && name2.Right(1) == L">";
        if (bXml)
            xml.FUN_14092c400(name2);
        else
            parameter.FUN_1408d1e00(name2, L",");
        if (FUN_14054a350() == 0)
            Unk_ItemDataLog(CLogString::GetInstance(), 1, 0x13, L"xml 형식이 잘못 되었습니다ItemFunction!! [{0}] [{1}]",
                            FUN_1401d4330(name, 0), FUN_1401d4330(name2, 0));
    }
    return 1;
}

// @0x14054a2b0
bool ItemFunction::FUN_14054a2b0(const ItemFunction* pOther)
{
    if (name != pOther->name)
        return true;
    if (name2 != pOther->name2)
        return true;
    if (arg0 != pOther->arg0)
        return true;
    if (arg1 != pOther->arg1)
        return true;
    if (arg2 != pOther->arg2)
        return true;
    return false;
}

// @0x14054a350
int ItemFunction::FUN_14054a350()
{
    if (name == L"ExpandInven")
    {
        if (parameter.FUN_1408d2380() < 1)
            return 0;
        unsigned nSlots = parameter.FUN_1408d1fd0(0, 0);
        if (nSlots % 6 != 0)
            return 0;
    }
    return 1;
}

// @0x14054a3d0
bool ItemFunction::FUN_14054a3d0()
{
    return name.GetLength() > 0;
}

// @0x14054a410
bool ItemFunction::FUN_14054a410()
{
    return !xml.FUN_14092c5c0();
}

// @0x14054a460
int ItemFunction::FUN_14054a460()
{
    if (name == L"OpenItemBox")
    {
        return arg0;
    }
    else if (name == L"OpenItemBoxWithKey")
    {
        if (arg0 != 0)
            return arg0;
        else
            return parameter.FUN_1408d1fd0(5, 0);
    }
    else if ((name == L"OpenItemBoxLullu" || name == L"OpenItemBoxLulluSimple") && !xml.FUN_14092c5c0())
    {
        return xml.GetInt(L"commonBoxId", 0);
    }
    else if (name == L"SelectItemBox")
    {
        if (FUN_14054a410())
            return xml.GetInt(L"individualDropBoxId", 0);
        else
            return parameter.FUN_1408d1fd0(1, 0);
    }
    else if (name == L"OpenGachaBox")
    {
        int nBoxId = parameter.FUN_1408d1fd0(0, 0);
        GachaBoxDataPtr spBox = ItemGachaBoxTable::GetInstance()->GetBox(nBoxId);
        if (spBox == 0)
            return 0;
        return spBox->m_nIndividualDropBoxID;
    }
    return 0;
}

// ---- ItemMusicScore -----------------------------------------------------------------------------------------------------
// The music book table (item.cpp; the title of a book lives at +0x28).
class Unk_MusicBookInfo : public CPtred { public: char m_pad18[0x10]; CString m_str28; CStringW FUN_14072c480(); };
class Unk_MusicBookTable { public: MS2Ptr<Unk_MusicBookInfo> FUN_14072cc10(unsigned); };
Unk_MusicBookTable* FUN_14052d1d0();

// @0x14054a720
ItemMusicScore::ItemMusicScore()
    : playCount(0), masteryValueMax(0), isCustomNote(false), recommendCategoryId(0), noteLengthMax(0), playTime(0)
{
}

// @0x14054a7b0
int ItemMusicScore::LoadXml(Unk_140165cf0* pElem)
{
    Unk_140165cf0* p = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("MusicScore"));
    if (p != 0)
    {
        XmlGetAttr((class TiXmlElement*)(p), "playCount", reinterpret_cast<int&>(playCount));
        XmlGetAttr((class TiXmlElement*)(p), "masteryValueMax", reinterpret_cast<int&>(masteryValueMax));
        XmlGetAttr((class TiXmlElement*)(p), "isCustomNote", reinterpret_cast<bool&>(isCustomNote));
        XmlGetAttr((class TiXmlElement*)(p), "noteLengthMax", reinterpret_cast<int&>(noteLengthMax));
        XmlGetAttr((class TiXmlElement*)(p), "fileName", fileName);
        XmlGetAttr((class TiXmlElement*)(p), "playTime", reinterpret_cast<int&>(playTime));
        XmlGetAttr((class TiXmlElement*)(p), "recommendCategoryId", reinterpret_cast<int&>(recommendCategoryId));
    }
    return 1;
}

// @0x14054a8c0
int ItemMusicScore::LoadElement(Unk_140165cf0* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "playCount", reinterpret_cast<int&>(playCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "masteryValueMax", reinterpret_cast<int&>(masteryValueMax));
    XmlGetAttr((class TiXmlElement*)(pElem), "isCustomNote", reinterpret_cast<bool&>(isCustomNote));
    XmlGetAttr((class TiXmlElement*)(pElem), "noteLengthMax", reinterpret_cast<int&>(noteLengthMax));
    XmlGetAttr((class TiXmlElement*)(pElem), "fileName", fileName);
    XmlGetAttr((class TiXmlElement*)(pElem), "playTime", reinterpret_cast<int&>(playTime));
    XmlGetAttr((class TiXmlElement*)(pElem), "recommendCategoryId", reinterpret_cast<int&>(recommendCategoryId));
    return 1;
}

// @0x14054a9b0
int ItemMusicScore::Save(void* pParent)
{
    static ItemMusicScore s_default;
    if (FUN_14054abd0(&s_default))
    {
        TiXmlElement elem("MusicScore");
        if (playCount != 0)
            XmlSetAttr((class TiXmlElement*)(&elem), "playCount", playCount);
        if (masteryValueMax != 0)
            XmlSetAttr((class TiXmlElement*)(&elem), "masteryValueMax", masteryValueMax);
        if (isCustomNote)
            XmlSetAttr((class TiXmlElement*)(&elem), "isCustomNote", isCustomNote);
        if (noteLengthMax != 0)
            XmlSetAttr((class TiXmlElement*)(&elem), "noteLengthMax", noteLengthMax);
        if (!fileName.IsEmpty())
            XmlSetAttr((class TiXmlElement*)(&elem), "fileName", fileName);
        if (playTime != 0)
            XmlSetAttr((class TiXmlElement*)(&elem), "playTime", playTime);
        if (recommendCategoryId != 0)
            XmlSetAttr((class TiXmlElement*)(&elem), "recommendCategoryId", recommendCategoryId);
        ((void*)((class TiXmlNode*)(void*)(pParent))->InsertEndChild(*(class TiXmlNode const*)(&elem)));
    }
    return 1;
}

// @0x14054abd0
bool ItemMusicScore::FUN_14054abd0(const ItemMusicScore* pOther)
{
    if (playCount != pOther->playCount)
        return true;
    if (masteryValueMax != pOther->masteryValueMax)
        return true;
    if (isCustomNote != pOther->isCustomNote)
        return true;
    if (noteLengthMax != pOther->noteLengthMax)
        return true;
    if (fileName != pOther->fileName)
        return true;
    if (playTime != pOther->playTime)
        return true;
    if (recommendCategoryId != pOther->recommendCategoryId)
        return true;
    return false;
}

// @0x14054aca0
bool ItemMusicScore::FUN_14054aca0()
{
    return isCustomNote;
}

// @0x14054acc0
int ItemMusicScore::FUN_14054acc0()
{
    return noteLengthMax;
}

// @0x14054ace0
int ItemMusicScore::FUN_14054ace0()
{
    return playTime;
}

// @0x14054ad00
int ItemMusicScore::FUN_14054ad00()
{
    return playCount;
}

// @0x14054ad20
CStringW ItemMusicScore::FUN_14054ad20()
{
    MS2Ptr<Unk_MusicBookInfo> spInfo = FUN_14052d1d0()->FUN_14072cc10(recommendCategoryId);
    if (spInfo == 0)
        return L"";
    return reinterpret_cast<MS2Ptr<CInstrumentCategoryData>&>(spInfo)->GetName();
}

// @0x14054ade0
int ItemMusicScore::FUN_14054ade0()
{
    return masteryValueMax;
}

// ---- ItemModelData ------------------------------------------------------------------------------------------------------
// @0x14054ae00
ItemModelData::ItemModelData()
    : m_nUnk28(0)
{
}

// @0x14054aec0
unsigned ItemModelData::FUN_14054aec0(unsigned nId)
{
    return nId / 100000;
}

// @0x14054aee0
void ItemModelData::FUN_14054aee0(int n)
{
    m_nUnk28 = n;
}

// @0x14054af00
void ItemModelData::FUN_14054af00(Unk_140165cf0* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "desc", name);
    Unk_140165cf0* pSlots = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("slots"));
    if (pSlots != 0)
    {
        for (Unk_140165cf0* pSlot = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pSlots))->FirstChild("slot")); pSlot != 0; pSlot = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pSlot))->NextSibling("slot")))
        {
            groups.push_back(ModelGroup());
            ModelGroup& group = groups[groups.size() - 1];
            group.FUN_140544cf0(pSlot);
            if (group.FUN_1405451a0() == 3)
            {
                resource.AssignRaw(new CharacterDecalData);
                resource->FUN_1401e4090(pSlot);
            }
        }
    }
    head.Load(pElem);
    Unk_140165cf0* pCutting = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("cutting"));
    if (pCutting != 0)
    {
        for (Unk_140165cf0* pMesh = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pCutting))->FirstChild("mesh")); pMesh != 0; pMesh = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pMesh))->NextSibling("mesh")))
        {
            CString strName = Unk_ReadString((class Unk_XmlNode*)(pMesh), "name", "");
            if (strName.IsEmpty())
                continue;
            int nGender = 2;
            XmlGetAttr((class TiXmlElement*)(pMesh), "gender", reinterpret_cast<int&>(nGender));
            if (nGender == 0 || nGender == 2)
                names98.push_back(strName);
            if (nGender == 1 || nGender == 2)
                namesB0.push_back(strName);
        }
    }
}

// @0x14054b230
void ItemModelData::FUN_14054b230(void* pParent)
{
}

// @0x14054b250
void ItemModelData::FUN_14054b250(const CString& strName)
{
    for (size_t i = 0; i < groups.size(); ++i)
        groups[i].FUN_140545130(strName);
}

// @0x14054b2c0
std::vector<CString>* ItemModelData::FUN_14054b2c0(int nGender)
{
    if (nGender == 0)
        return &names98;
    return &namesB0;
}

// @0x14054b2f0
const ModelGroup* ItemModelData::GetGroup(size_t nIndex) const
{
    static ModelGroup s_empty;
    if (nIndex < groups.size())
        return &groups[nIndex];
    return &s_empty;
}

// @0x14054b3b0
int ItemModelData::FUN_14054b3b0()
{
    return m_nUnk28;
}

// @0x14054b3d0
size_t ItemModelData::FUN_14054b3d0()
{
    return groups.size();
}

// @0x14054b400
int ItemModelData::FUN_14054b400() const
{
    if (groups.empty())
        return 0;
    return groups[0].FUN_1405451a0();
}

// @0x14054b450
bool ItemModelData::FUN_14054b450(int nType) const
{
    for (size_t i = 0; i < groups.size(); ++i)
    {
        if (groups[i].FUN_1405451a0() == 19)
            return nType == 5 || nType == 4;
        else if (groups[i].FUN_1405451a0() == nType)
            return true;
    }
    return false;
}

// @0x14054b520
bool ItemModelData::FUN_14054b520()
{
    return head.FUN_140547190();
}

// @0x14054b550
bool ItemModelData::FUN_14054b550()
{
    return head.FUN_1405471d0();
}

// @0x14054b580
int ItemModelData::FUN_14054b580()
{
    return head.FUN_140547250();
}

// @0x14054b5b0
int ItemModelData::FUN_14054b5b0(int nIndex)
{
    return head.FUN_140547270(nIndex);
}

// @0x14054b5e0
int ItemModelData::FUN_14054b5e0(int nIndex)
{
    return head.FUN_1405472d0(nIndex);
}

// @0x14054b610
size_t ItemModelData::FUN_14054b610()
{
    return head.FUN_140547330();
}

// @0x14054b640
bool ItemModelData::FUN_14054b640()
{
    return head.FUN_140547230();
}

// @0x14054b670
ItemModelHead* ItemModelData::FUN_14054b670()
{
    return &head;
}

// @0x14054b690
ItemModelHead* ItemModelData::FUN_14054b690()
{
    return &head;
}

// @0x14054b6b0
CharacterDecalData* ItemModelData::FUN_14054b6b0()
{
    return resource.get();
}

// @0x14054b6e0
CStringW ItemModelData::GetName()
{
    return name;
}
