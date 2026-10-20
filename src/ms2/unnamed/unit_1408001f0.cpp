// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The skill range shape (<rangeProperty> attributes: type,
// distance, height, width, endWidth, rangeAdd, rangeOffset, rangeZRotateDegree) and the target selection record built on
// it: constructors, comparisons, XML readers and writers. Layouts: commonfiles/additionalactionadditional.h.
// MS2-UNIT: unit_1408001f0
// MS2-RANGE: 0x1408001f0-0x1408011f0 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // xmlattr.h asserts (NDEBUG DLL build)
#include "ms2/commonfiles/additionalactionadditional.h"
#include "ms2/placeholder/xmlattr.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int* pnOut);
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned* pnOut);
int FUN_140873360(Unk_140165cf0* pElem, const char* pszName, float* pfOut);
int FUN_140873710(Unk_140165cf0* pElem, const char* pszName, int* pnOut);       // flag attribute
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CString& strOut);
int FUN_140874670(Unk_140165cf0* pElem, const char* pszName, efd::Point3& kOut);
void FUN_140873e30(void* pElem, const char* pszName, float fValue);
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);
void FUN_140873ce0(void* pElem, const char* pszName, unsigned nValue);
void FUN_140874050(void* pElem, const char* pszName, const CString& strValue);
void* FUN_14086e000(void* pParent, const void* pChild);                         // InsertEndChild
CString FUN_14028ef00(efd::Point3 kPoint);                                      // point -> "x, y, z"
void TrimCommas(CString& str);                                                  // 0x140552c60

// Unit-local view of the game's TiXmlElement (0x90 bytes; the writers only build it and insert it).
class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);      // 0x14086f2f0
    ~Unk_TiXmlElement();                        // 0x14086f450
private:
    void* unknown00[18];
};
MS2_CHECK_SIZE(Unk_TiXmlElement, 0x90);

// @0x1408001f0
Unk_RangeShape::Unk_RangeShape()
    : m_nType(0), m_str(), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1c(0.0f), m_pt20(0.0f, 0.0f, 0.0f), m_pt2c(0.0f, 0.0f, 0.0f), m_f38(0.0f)
{
}

// @0x1408002b0
bool Unk_RangeShape::FUN_1408002b0(const Unk_RangeShape& o)
{
    if (m_nType != o.m_nType)
        return true;
    if (m_f10 != o.m_f10)
        return true;
    if (m_f14 != o.m_f14)
        return true;
    if (m_f18 != o.m_f18)
        return true;
    if (m_f1c != o.m_f1c)
        return true;
    if (m_pt20 != o.m_pt20)
        return true;
    if (m_pt2c != o.m_pt2c)
        return true;
    if (m_f38 != o.m_f38)
        return true;
    return false;
}

// @0x1408003b0
void Unk_RangeShape::FUN_1408003b0(Unk_140165cf0* pElem)
{
    FUN_1408733e0(pElem, "rangeType", m_str);
    if (m_str == "box")
        m_nType = 1;
    else if (m_str == "cylinder")
        m_nType = 2;
    else if (m_str == "frustum")
        m_nType = 3;
    else if (m_str == "hole_cylinder")
        m_nType = 4;
    FUN_140873360(pElem, "distance", &m_f10);
    FUN_140873360(pElem, "height", &m_f14);
    FUN_140873360(pElem, "width", &m_f18);
    FUN_140873360(pElem, "endWidth", &m_f1c);
    FUN_140874670(pElem, "rangeAdd", m_pt20);
    FUN_140874670(pElem, "rangeOffset", m_pt2c);
    FUN_140873360(pElem, "rangeZRotateDegree", &m_f38);
}

// @0x140800570
void Unk_RangeShape::FUN_140800570(void* pElem)
{
    static Unk_RangeShape kDefault;
    if (m_str != kDefault.m_str)
        FUN_140874050(pElem, "rangeType", m_str);
    if (kDefault.m_f10 != m_f10)
        FUN_140873e30(pElem, "distance", m_f10);
    if (kDefault.m_f14 != m_f14)
        FUN_140873e30(pElem, "height", m_f14);
    if (kDefault.m_f18 != m_f18)
        FUN_140873e30(pElem, "width", m_f18);
    if (kDefault.m_f1c != m_f1c)
        FUN_140873e30(pElem, "endWidth", m_f1c);
    if (m_pt20 != kDefault.m_pt20)
        FUN_140874050(pElem, "rangeAdd", FUN_14028ef00(m_pt20));
    if (m_pt2c != kDefault.m_pt2c)
        FUN_140874050(pElem, "rangeOffset", FUN_14028ef00(m_pt2c));
    if (kDefault.m_f38 != m_f38)
        FUN_140873e30(pElem, "rangeZRotateDegree", m_f38);
}

// @0x140800860
Unk_RangeProperty::Unk_RangeProperty()
    : m_n40(0), m_n44(0), m_n48(0), m_n4c(0), m_n50(0), m_n54(0), m_n58(0), m_n5c(0), m_n60(0), m_n64(0), m_n68(0), m_n6c(0), m_n70(0)
{
}

// @0x140800920
bool Unk_RangeProperty::FUN_140800920(const Unk_RangeProperty& o)
{
    if (Unk_RangeShape(*this).FUN_1408002b0(Unk_RangeShape(o)))
        return true;
    if (m_n40 != o.m_n40)
        return true;
    if (m_n44 != o.m_n44)
        return true;
    if (m_n48 != o.m_n48)
        return true;
    if (m_n4c != o.m_n4c)
        return true;
    if (m_n50 != o.m_n50)
        return true;
    if (m_n54 != o.m_n54)
        return true;
    if (m_n58 != o.m_n58)
        return true;
    if (m_n5c != o.m_n5c)
        return true;
    if (m_n60 != o.m_n60)
        return true;
    if (m_n64 != o.m_n64)
        return true;
    if (m_n68 != o.m_n68)
        return true;
    if (m_n6c != o.m_n6c)
        return true;
    if (m_n70 != o.m_n70)
        return true;
    return false;
}

// @0x140800b50
// MS2-FUNCTIONAL: the exe's reader is void with an early `return;` that destroys strName on its own path; the shared header
// declares int, so the early exit here falls through the single cleanup (no value is returned, as in the exe).
#pragma warning(disable : 4716)
int Unk_RangeProperty::FUN_140800b50(Unk_140165cf0* pElem, CString strName)
{
    Unk_140165cf0* pRange = pElem->FUN_140165cf0(strName);
    if (pRange != 0)
    {
        FUN_1408003b0(pRange);
        FUN_1408731e0(pRange, "includeCaster", &m_n40);
        FUN_1408731e0(pRange, "applyTarget", &m_n44);
        FUN_1408731e0(pRange, "castTarget", &m_n48);
        FUN_140873220(pRange, "targetSelectType", (unsigned*)&m_n5c);
        if (m_n5c != 0)
        {
            FUN_140873220(pRange, "targetHasBuffID", (unsigned*)&m_n4c);
            FUN_140873220(pRange, "targetHasBuffOverlapCount", (unsigned*)&m_n50);
            FUN_140873220(pRange, "targetHasNotBuffID", (unsigned*)&m_n54);
            FUN_1408731e0(pRange, "targetHasBuffOwner", &m_n58);
            FUN_140873710(pRange, "targetSelectParty", &m_n60);
            FUN_140873710(pRange, "targetSelectGuild", &m_n64);
        }
        FUN_1408731e0(pRange, "targetStatCompare", &m_n68);
        FUN_1408731e0(pRange, "targetStatCompareFunction", &m_n6c);
        ATL::CAtlArray<unsigned> arrRank;
        XmlTokenList(pRange, "applyTargetIgnoreNpcRanks", arrRank);
        for (unsigned __int64 i = 0; i < arrRank.GetCount(); i++)
            m_n70 |= 1 << (arrRank[i] & 0x1f);
    }
}

// @0x140800de0
void Unk_RangeProperty::FUN_140800de0(void* pParent, CString strName)
{
    static Unk_RangeProperty kDefault;
    if (FUN_140800920(kDefault))
    {
        Unk_TiXmlElement elem(strName);
        FUN_140800570(&elem);
        if (m_n40 != kDefault.m_n40)
            FUN_140873ca0(&elem, "includeCaster", m_n40);
        if (m_n44 != kDefault.m_n44)
            FUN_140873ca0(&elem, "applyTarget", m_n44);
        if (m_n48 != kDefault.m_n48)
            FUN_140873ca0(&elem, "castTarget", m_n48);
        if (m_n5c != 0)
        {
            FUN_140873ce0(&elem, "targetSelectType", m_n5c);
            if (m_n4c != kDefault.m_n4c)
                FUN_140873ce0(&elem, "targetHasBuffID", m_n4c);
            if (m_n50 != kDefault.m_n50)
                FUN_140873ce0(&elem, "targetHasBuffOverlapCount", m_n50);
            if (m_n54 != kDefault.m_n54)
                FUN_140873ce0(&elem, "targetHasNotBuffID", m_n54);
            if (m_n58 != kDefault.m_n58)
                FUN_140873ca0(&elem, "targetHasBuffOwner", m_n58);
            if (m_n60 != kDefault.m_n60)
                FUN_140873ca0(&elem, "targetSelectParty", m_n60);
            if (m_n64 != kDefault.m_n64)
                FUN_140873ca0(&elem, "targetSelectGuild", m_n64);
        }
        if (m_n6c != kDefault.m_n6c)
        {
            if (m_n68 != kDefault.m_n68)
                FUN_140873ca0(&elem, "targetStatCompare", m_n68);
            FUN_140873ca0(&elem, "targetStatCompareFunction", m_n6c);
        }
        if (m_n70 != kDefault.m_n70)
        {
            CString strRanks;
            for (unsigned i = 1; i < 8; i++)
            {
                if ((m_n70 & (1 << i)) != 0)
                    strRanks.AppendFormat(",%d", i);
            }
            TrimCommas(strRanks);
            if (!strRanks.IsEmpty())
                FUN_140874050(&elem, "applyTargetIgnoreNpcRanks", strRanks);
        }
        FUN_14086e000(pParent, &elem);
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c0d0-0x142c9c110 .text$yd
