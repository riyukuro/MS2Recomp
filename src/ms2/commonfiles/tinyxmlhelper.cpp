// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The game's TinyXML helpers (commonfiles\tinyxmlhelper.cpp):
// typed attribute readers/writers on a TiXmlElement, child element readers/writers, Gamebryo value types (points,
// transforms, frustums, rects, fixed strings) and the node debug string. Function names invented; the original header
// commonfiles\tinyxmlhelper.h also holds the list/enum templates that ms2/placeholder/xmlattr.h models.
// Readers return the TinyXML query codes (0 TIXML_SUCCESS, 1 TIXML_NO_ATTRIBUTE, 2 TIXML_WRONG_TYPE; 3 = empty value).
// MS2-UNIT: commonfiles\tinyxmlhelper.cpp#3
// MS2-RANGE: 0x140872ec0-0x140876dc0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <stdlib.h>
#include <atlcoll.h>
#include <atltime.h>
#include <efd/StdContainers.h>
#include <NiFixedString.h>
#include <NiPoint3.h>
#include <NiTransform.h>
#include <NiFrustum.h>
#include <NiRect.h>
#include "tinyxml.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Helpers of other units.
CStringW FUN_14016a730(const char* sz, int nCodePage);                          // multi-byte to wide
CStringA FUN_140188f50(const char* psz, int nCodePage);                         // multi-byte copy
CStringA FUN_140390ea0(const wchar_t* psz, int nCodePage);                      // wide to multi-byte
ATL::CTimeSpan FUN_140718d00(const CString& str);                               // "d,h,m,s" span
CMsTime FUN_140718950(const CString& str);                                      // date/time text
int FUN_14028c3e0(const CString& str, ATL::CAtlArray<CString>& arr, const char* pszDelim, int nCount);   // split, exact count
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);  // xmlattr.h (0x140177e40 for CAtlArray<float>)

// A 3-byte colour (r, g, b) parsed from text by FUN_1406c3910.
class Unk_Rgb3b
{
public:
    Unk_Rgb3b();
    unsigned char r, g, b;
};
Unk_Rgb3b FUN_1406c3910(const CString& str);

// The UTF-8 text of TinyXML as a wide string.
// @0x1408767c0
inline CStringW XmlWide(const char* psz)
{
    CStringW str = FUN_14016a730(psz, CP_UTF8);
    return str;
}

// Narrowing readers (the TinyXML query gives an int / a double).
// @0x140876760
template <class T> int XmlQueryInt(TiXmlElement* pElem, const char* pszName, T& out)
{
    int nValue;
    int nResult = pElem->QueryIntAttribute(pszName, &nValue);
    if (nResult == TIXML_SUCCESS)
        out = (T)nValue;
    return nResult;
}
// @0x140876710
template <class T> int XmlQueryDouble(TiXmlElement* pElem, const char* pszName, T& out)
{
    double dValue;
    int nResult = pElem->QueryDoubleAttribute(pszName, &dValue);
    if (nResult == TIXML_SUCCESS)
        out = (T)dValue;
    return nResult;
}

int XmlQuery(TiXmlElement* pElem, const char* pszName, bool& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, char& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, unsigned char& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, short& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, unsigned short& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, int& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, unsigned& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, long& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, unsigned long& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, __int64& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, unsigned __int64& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, float& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, double& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, CStringA& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, CStringW& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, efd::Point3& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, NiFixedString& out);
int XmlQuery(TiXmlElement* pElem, const char* pszName, NiPoint3& out);
int XmlQuery(TiXmlElement* pElem, NiTransform& out);
void XmlWrite(TiXmlElement* pElem, const char* pszName, const NiFixedString& value);
void XmlWrite(TiXmlElement* pElem, const char* pszName, const efd::Point3& value);
void XmlWrite(TiXmlElement* pElem, const NiTransform& value);
void XmlParsePoint(const CString& str, NiPoint3& out);

// The child element of that name; a new one is appended when there is none or bReuse is false.
// @0x140872ec0
TiXmlElement* XmlChild(TiXmlElement* pParent, const char* pszName, bool bReuse)
{
    if (pParent == NULL)
        return NULL;
    TiXmlElement* pChild = NULL;
    if (bReuse)
    {
        if (TiXmlElement* pFound = pParent->FirstChildElement(pszName))
            return pFound;
    }
    pChild = new TiXmlElement(pszName);
    pParent->LinkEndChild(pChild);
    return pChild;
}

// @0x140872f90
int XmlGetText(TiXmlElement* pElem, CStringA& out)
{
    if (pElem == NULL)
    {
        MS2_ASSERT_AT(36, FALSE);
        return 1;
    }
    out = pElem->GetText();
    return 0;
}

// @0x140873000
int XmlGetText(TiXmlElement* pElem, CStringW& out)
{
    if (pElem == NULL)
    {
        MS2_ASSERT_AT(48, FALSE);
        return 1;
    }
    out = XmlWide(pElem->GetText());
    return 0;
}

// @0x1408730a0
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, bool& out) { return XmlQuery(pElem, pszName, out); }
// @0x1408730e0
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, char& out) { return XmlQuery(pElem, pszName, out); }
// @0x140873120
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, unsigned char& out) { return XmlQuery(pElem, pszName, out); }
// @0x140873160
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, short& out) { return XmlQuery(pElem, pszName, out); }
// @0x1408731a0
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, unsigned short& out) { return XmlQuery(pElem, pszName, out); }
// @0x1408731e0
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, int& out) { return XmlQuery(pElem, pszName, out); }
// @0x140873220
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, unsigned& out) { return XmlQuery(pElem, pszName, out); }
// @0x140873260
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, long& out) { return XmlQuery(pElem, pszName, out); }
// @0x1408732a0
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, unsigned long& out) { return XmlQuery(pElem, pszName, out); }
// @0x1408732e0
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, __int64& out) { return XmlQuery(pElem, pszName, out); }
// @0x140873320
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, unsigned __int64& out) { return XmlQuery(pElem, pszName, out); }
// @0x140873360
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, float& out) { return XmlQuery(pElem, pszName, out); }
// @0x1408733a0
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, double& out) { return XmlQuery(pElem, pszName, out); }
// @0x1408733e0
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, CStringA& out) { return XmlQuery(pElem, pszName, out); }
// @0x140873420
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, CStringW& out) { return XmlQuery(pElem, pszName, out); }

// @0x140873460
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, ATL::CTimeSpan& out)
{
    CString str;
    int nResult = XmlQuery(pElem, pszName, str);
    if (nResult != TIXML_SUCCESS)
        return nResult;
    if (str.GetLength() < 1)
        return 3;
    out = FUN_140718d00(str);
    return nResult;
}

// @0x140873530
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, Unk_Rgb3b& out)
{
    CString str;
    int nResult = XmlQuery(pElem, pszName, str);
    if (nResult != TIXML_SUCCESS)
        return nResult;
    if (str.GetLength() < 1)
        return 3;
    out = FUN_1406c3910(str);
    return nResult;
}

// @0x140873600
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, CMsTime& out)
{
    CString str;
    int nResult = XmlQuery(pElem, pszName, str);
    if (nResult != TIXML_SUCCESS)
        return nResult;
    if (str.GetLength() < 1)
        return 3;
    out = FUN_140718950(str);
    return nResult;
}

// @0x1408736d0
int XmlQuery(TiXmlElement* pElem, const char* pszName, bool& out)
{
    return pElem->QueryBoolAttribute(pszName, &out);
}

// A BOOL attribute.
// @0x140873710
int XmlGetBool(TiXmlElement* pElem, const char* pszName, int& out)
{
    bool b = out == TRUE;
    int nResult = pElem->QueryBoolAttribute(pszName, &b);
    out = b;
    return nResult;
}

// @0x140873780
int XmlQuery(TiXmlElement* pElem, const char* pszName, char& out)
{
    short nValue;
    int nResult = XmlQueryInt(pElem, pszName, nValue);
    if (nResult == TIXML_SUCCESS)
        out = (char)nValue;
    return nResult;
}
// @0x1408737d0
int XmlQuery(TiXmlElement* pElem, const char* pszName, unsigned char& out) { return XmlQuery(pElem, pszName, (char&)out); }
// @0x140873810
int XmlQuery(TiXmlElement* pElem, const char* pszName, short& out) { return XmlQueryInt(pElem, pszName, out); }
// @0x140873850
int XmlQuery(TiXmlElement* pElem, const char* pszName, unsigned short& out) { return XmlQueryInt(pElem, pszName, (short&)out); }
// @0x140873890
int XmlQuery(TiXmlElement* pElem, const char* pszName, int& out) { return pElem->QueryIntAttribute(pszName, &out); }
// @0x1408738d0
int XmlQuery(TiXmlElement* pElem, const char* pszName, unsigned& out) { return pElem->QueryUnsignedAttribute(pszName, &out); }
// @0x140873910
int XmlQuery(TiXmlElement* pElem, const char* pszName, long& out) { return pElem->QueryIntAttribute(pszName, (int*)&out); }
// @0x140873950
int XmlQuery(TiXmlElement* pElem, const char* pszName, unsigned long& out) { return pElem->QueryUnsignedAttribute(pszName, (unsigned*)&out); }

// @0x140873990
int XmlQuery(TiXmlElement* pElem, const char* pszName, __int64& out)
{
    const char* psz = pElem->Attribute(pszName);
    if (psz == NULL)
        return TIXML_NO_ATTRIBUTE;
    out = _atoi64(psz);
    return TIXML_SUCCESS;
}

// @0x1408739f0
int XmlQuery(TiXmlElement* pElem, const char* pszName, unsigned __int64& out)
{
    const char* psz = pElem->Attribute(pszName);
    if (psz == NULL)
        return TIXML_NO_ATTRIBUTE;
    out = _strtoui64(psz, NULL, 10);
    return TIXML_SUCCESS;
}

// @0x140873a50
int XmlQuery(TiXmlElement* pElem, const char* pszName, float& out) { return XmlQueryDouble(pElem, pszName, out); }
// @0x140873a90
int XmlQuery(TiXmlElement* pElem, const char* pszName, double& out) { return pElem->QueryDoubleAttribute(pszName, &out); }

// @0x140873ad0
int XmlQuery(TiXmlElement* pElem, const char* pszName, CStringA& out)
{
    const char* psz = pElem->Attribute(pszName);
    if (psz == NULL)
        return TIXML_NO_ATTRIBUTE;
    out = psz;
    return TIXML_SUCCESS;
}

// @0x140873b30
int XmlQuery(TiXmlElement* pElem, const char* pszName, CStringW& out)
{
    const char* psz = pElem->Attribute(pszName);
    if (psz == NULL)
        return TIXML_NO_ATTRIBUTE;
    out = XmlWide(psz);
    return TIXML_SUCCESS;
}

// @0x140873bc0
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, bool value)
{
    if (pElem)
        pElem->SetAttribute(pszName, value ? "true" : "false");
}
// @0x140873c20
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, short value) { if (pElem) pElem->SetAttribute(pszName, value); }
// @0x140873c60
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, unsigned short value) { if (pElem) pElem->SetAttribute(pszName, value); }
// @0x140873ca0
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, int value) { if (pElem) pElem->SetAttribute(pszName, value); }
// @0x140873ce0
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, unsigned value) 
{
    if (pElem)
    {
        CString str = StringFormat("{0}", value);
        pElem->SetAttribute(pszName, str);
    }
}
// @0x140873d50
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, long value) 
{
    if (pElem)
    {
        CString str = StringFormat("{0}", value);
        pElem->SetAttribute(pszName, str);
    }
}
// @0x140873dc0
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, unsigned long value) 
{
    if (pElem)
    {
        CString str = StringFormat("{0}", value);
        pElem->SetAttribute(pszName, str);
    }
}
// @0x140873e30
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, float value) { if (pElem) pElem->SetDoubleAttribute(pszName, value); }
// @0x140873e70
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, double value) { if (pElem) pElem->SetDoubleAttribute(pszName, value); }
// @0x140873eb0
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, const __int64& value) 
{
    if (pElem)
    {
        CString str = StringFormat("{0}", value);
        pElem->SetAttribute(pszName, str);
    }
}
// @0x140873f20
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, const unsigned __int64& value) 
{
    if (pElem)
    {
        CString str = StringFormat("{0}", value);
        pElem->SetAttribute(pszName, str);
    }
}
// @0x140873f90
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, const char* value) { if (pElem) pElem->SetAttribute(pszName, value); }
// @0x140873fd0
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, const wchar_t* value) { if (pElem) pElem->SetAttribute(pszName, FUN_140390ea0(value, 0)); }
// @0x140874050
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, const CStringA& value) { if (pElem) pElem->SetAttribute(pszName, value); }
// @0x1408740a0
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, const CStringW& value) { if (pElem) pElem->SetAttribute(pszName, FUN_140390ea0(value, 0)); }

// Attribute of the first child element of that name (1 when there is no such child).
// @0x140874130
int XmlGetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, bool& out)
{
    TiXmlElement* pChild;
    if (pElem && (pChild = pElem->FirstChildElement(pszChild)) != NULL)
        return XmlGetAttr(pChild, pszName, out);
    return TIXML_NO_ATTRIBUTE;
}
// @0x1408741a0
int XmlGetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, int& out)
{
    TiXmlElement* pChild;
    if (pElem && (pChild = pElem->FirstChildElement(pszChild)) != NULL)
        return XmlGetAttr(pChild, pszName, out);
    return TIXML_NO_ATTRIBUTE;
}
// @0x140874210
int XmlGetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, float& out)
{
    TiXmlElement* pChild;
    if (pElem && (pChild = pElem->FirstChildElement(pszChild)) != NULL)
        return XmlGetAttr(pChild, pszName, out);
    return TIXML_NO_ATTRIBUTE;
}
// @0x140874280
int XmlGetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, CStringA& out)
{
    TiXmlElement* pChild;
    if (pElem && (pChild = pElem->FirstChildElement(pszChild)) != NULL)
        return XmlGetAttr(pChild, pszName, out);
    return TIXML_NO_ATTRIBUTE;
}
// @0x1408742f0
int XmlGetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, CStringW& out)
{
    TiXmlElement* pChild;
    if (pElem && (pChild = pElem->FirstChildElement(pszChild)) != NULL)
        return XmlGetAttr(pChild, pszName, out);
    return TIXML_NO_ATTRIBUTE;
}
// @0x140874360
int XmlGetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, unsigned __int64& out)
{
    TiXmlElement* pChild;
    if (pElem && (pChild = pElem->FirstChildElement(pszChild)) != NULL)
        return XmlGetAttr(pChild, pszName, out);
    return TIXML_NO_ATTRIBUTE;
}

// Attribute of a child element (XmlChild: reused or appended).
// @0x1408743d0
void XmlSetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, bool value, bool bReuse)
{
    if (pElem)
    {
        if (TiXmlElement* pChild = XmlChild(pElem, pszChild, bReuse))
            XmlSetAttr(pChild, pszName, value);
    }
}
// @0x140874440
void XmlSetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, int value, bool bReuse)
{
    if (pElem)
    {
        if (TiXmlElement* pChild = XmlChild(pElem, pszChild, bReuse))
            XmlSetAttr(pChild, pszName, value);
    }
}
// @0x1408744b0
void XmlSetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, float value, bool bReuse)
{
    if (pElem)
    {
        if (TiXmlElement* pChild = XmlChild(pElem, pszChild, bReuse))
            XmlSetAttr(pChild, pszName, value);
    }
}
// @0x140874520
void XmlSetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, const CStringA& value, bool bReuse)
{
    if (pElem)
    {
        if (TiXmlElement* pChild = XmlChild(pElem, pszChild, bReuse))
            XmlSetAttr(pChild, pszName, value);
    }
}
// @0x140874590
void XmlSetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, const CStringW& value, bool bReuse)
{
    if (pElem)
    {
        if (TiXmlElement* pChild = XmlChild(pElem, pszChild, bReuse))
            XmlSetAttr(pChild, pszName, value);
    }
}
// @0x140874600
void XmlSetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, const unsigned __int64& value, bool bReuse)
{
    if (pElem)
    {
        if (TiXmlElement* pChild = XmlChild(pElem, pszChild, bReuse))
            XmlSetAttr(pChild, pszName, value);
    }
}

// @0x140874670
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, efd::Point3& out) { return XmlQuery(pElem, pszName, out); }
// @0x1408746b0
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, NiFixedString& out) { return XmlQuery(pElem, pszName, out); }
// @0x1408746f0
int XmlGetAttr(TiXmlElement* pElem, const char* pszName, NiPoint3& out) { return XmlQuery(pElem, pszName, out); }
// @0x140874730
int XmlGetAttr(TiXmlElement* pElem, NiTransform& out) { return XmlQuery(pElem, out); }

// "x,y,z" (2 when there are not exactly three values).
// @0x140874760
int XmlQuery(TiXmlElement* pElem, const char* pszName, efd::Point3& out)
{
    if (pElem->Attribute(pszName) == NULL)
        return TIXML_NO_ATTRIBUTE;
    ATL::CAtlArray<float> values;
    XmlSplit(CString(pElem->Attribute(pszName)), values, ",");
    if (values.GetCount() != 3)
        return TIXML_WRONG_TYPE;
    out.x = values[0];
    out.y = values[1];
    out.z = values[2];
    return TIXML_SUCCESS;
}

// @0x1408748b0
int XmlQuery(TiXmlElement* pElem, const char* pszName, NiFixedString& out)
{
    if (pElem == NULL)
        return TIXML_NO_ATTRIBUTE;
    CString str;
    int nResult = XmlQuery(pElem, pszName, str);
    if (nResult == TIXML_SUCCESS)
        out = (const char*)str;
    return nResult;
}

// @0x140874940
int XmlQuery(TiXmlElement* pElem, const char* pszName, NiPoint3& out)
{
    if (pElem == NULL)
        return TIXML_NO_ATTRIBUTE;
    const char* psz = pElem->Attribute(pszName);
    if (psz == NULL)
        return TIXML_NO_ATTRIBUTE;
    CString str = FUN_140188f50(psz, 0);
    XmlParsePoint(str, out);
    return TIXML_SUCCESS;
}

// position / rotation (Euler XYZ) / scale attributes.
// @0x1408749e0
int XmlQuery(TiXmlElement* pElem, NiTransform& out)
{
    if (pElem == NULL)
        return 1;
    NiPoint3 kRotate;
    XmlGetAttr(pElem, "position", out.m_Translate);
    XmlGetAttr(pElem, "rotation", kRotate);
    XmlGetAttr(pElem, "scale", out.m_fScale);
    out.m_Rotate.FromEulerAnglesXYZ(kRotate.x, kRotate.y, kRotate.z);
    return 0;
}

// @0x140874a90
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, const NiFixedString& value) { XmlWrite(pElem, pszName, value); }
// @0x140874ad0
void XmlSetAttr(TiXmlElement* pElem, const char* pszName, const efd::Point3& value) { XmlWrite(pElem, pszName, value); }
// @0x140874b10
void XmlSetAttr(TiXmlElement* pElem, const NiTransform& value) { XmlWrite(pElem, value); }

// @0x140874b40
void XmlWrite(TiXmlElement* pElem, const char* pszName, const NiFixedString& value)
{
    efd::string str((const char*)value);
    CString strValue(str.c_str());
    XmlSetAttr(pElem, pszName, strValue);
}

// MS2-FUNCTIONAL: the exe loads &value.x straight into r8 after the y/z argument stores (one register move differs).
// @0x140874bf0
void XmlWrite(TiXmlElement* pElem, const char* pszName, const efd::Point3& value)
{
    CString str = StringFormat("{0},{1},{2}", value.x, value.y, value.z);
    XmlSetAttr(pElem, pszName, str);
}

// @0x140874c70
void XmlWrite(TiXmlElement* pElem, const NiTransform& value)
{
    if (pElem)
    {
        NiPoint3 kRotate;
        value.m_Rotate.ToEulerAnglesXYZ(kRotate.x, kRotate.y, kRotate.z);
        XmlSetAttr(pElem, "position", value.m_Translate);
        XmlSetAttr(pElem, "rotation", kRotate);
        XmlSetAttr(pElem, "scale", value.m_fScale);
    }
}

// @0x140874d20
int XmlGetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, NiFixedString& out)
{
    TiXmlElement* pChild;
    if (pElem && (pChild = pElem->FirstChildElement(pszChild)) != NULL)
        return XmlGetAttr(pChild, pszName, out);
    return TIXML_NO_ATTRIBUTE;
}
// @0x140874d90
int XmlGetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, NiPoint3& out)
{
    TiXmlElement* pChild;
    if (pElem && (pChild = pElem->FirstChildElement(pszChild)) != NULL)
        return XmlGetAttr(pChild, pszName, out);
    return TIXML_NO_ATTRIBUTE;
}

// @0x140874e00
int XmlGetChild(TiXmlElement* pElem, const char* pszChild, NiFrustum& out)
{
    if (pElem == NULL)
        return 1;
    XmlGetChildAttr(pElem, pszChild, "left", out.m_fLeft);
    XmlGetChildAttr(pElem, pszChild, "right", out.m_fRight);
    XmlGetChildAttr(pElem, pszChild, "top", out.m_fTop);
    XmlGetChildAttr(pElem, pszChild, "bottom", out.m_fBottom);
    XmlGetChildAttr(pElem, pszChild, "near", out.m_fNear);
    XmlGetChildAttr(pElem, pszChild, "far", out.m_fFar);
    XmlGetChildAttr(pElem, pszChild, "ortho", out.m_bOrtho);
    return 0;
}

// @0x140874f20
int XmlGetChild(TiXmlElement* pElem, const char* pszChild, NiRect<float>& out)
{
    if (pElem == NULL)
        return 1;
    XmlGetChildAttr(pElem, pszChild, "left", out.m_left);
    XmlGetChildAttr(pElem, pszChild, "right", out.m_right);
    XmlGetChildAttr(pElem, pszChild, "top", out.m_top);
    XmlGetChildAttr(pElem, pszChild, "bottom", out.m_bottom);
    return 0;
}

// @0x140874fe0
int XmlGetChild(TiXmlElement* pElem, const char* pszChild, NiTransform& out)
{
    if (pElem == NULL)
        return 1;
    NiPoint3 kRotate;
    XmlGetChildAttr(pElem, pszChild, "position", out.m_Translate);
    XmlGetChildAttr(pElem, pszChild, "rotation", kRotate);
    XmlGetChildAttr(pElem, pszChild, "scale", out.m_fScale);
    out.m_Rotate.FromEulerAnglesXYZ(kRotate.x, kRotate.y, kRotate.z);
    return 0;
}

// @0x1408750a0
void XmlSetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, const NiFixedString& value, bool bReuse)
{
    if (pElem)
    {
        if (TiXmlElement* pChild = XmlChild(pElem, pszChild, bReuse))
            XmlSetAttr(pChild, pszName, value);
    }
}
// @0x140875110
void XmlSetChildAttr(TiXmlElement* pElem, const char* pszChild, const char* pszName, const efd::Point3& value, bool bReuse)
{
    if (pElem)
    {
        if (TiXmlElement* pChild = XmlChild(pElem, pszChild, bReuse))
            XmlSetAttr(pChild, pszName, value);
    }
}

// @0x140875180
void XmlSetChild(TiXmlElement* pElem, const char* pszChild, const NiFrustum& value, bool bReuse)
{
    XmlSetChildAttr(pElem, pszChild, "left", value.m_fLeft, bReuse);
    XmlSetChildAttr(pElem, pszChild, "right", value.m_fRight, bReuse);
    XmlSetChildAttr(pElem, pszChild, "top", value.m_fTop, bReuse);
    XmlSetChildAttr(pElem, pszChild, "bottom", value.m_fBottom, bReuse);
    XmlSetChildAttr(pElem, pszChild, "near", value.m_fNear, bReuse);
    XmlSetChildAttr(pElem, pszChild, "far", value.m_fFar, bReuse);
    XmlSetChildAttr(pElem, pszChild, "ortho", value.m_bOrtho, bReuse);
}

// @0x1408752d0
void XmlSetChild(TiXmlElement* pElem, const char* pszChild, const NiRect<float>& value, bool bReuse)
{
    XmlSetChildAttr(pElem, pszChild, "left", value.m_left, bReuse);
    XmlSetChildAttr(pElem, pszChild, "right", value.m_right, bReuse);
    XmlSetChildAttr(pElem, pszChild, "top", value.m_top, bReuse);
    XmlSetChildAttr(pElem, pszChild, "bottom", value.m_bottom, bReuse);
}

// Only the position is written (the rotation is computed and dropped; both branches are the same in the exe).
// @0x1408753a0
void XmlSetChild(TiXmlElement* pElem, const char* pszChild, const NiTransform& value, bool bReuse)
{
    if (pElem)
    {
        NiPoint3 kRotate;
        value.m_Rotate.ToEulerAnglesXYZ(kRotate.x, kRotate.y, kRotate.z);
        if (bReuse)
            XmlSetChildAttr(pElem, pszChild, "position", value.m_Translate, bReuse);
        else
            XmlSetChildAttr(pElem, pszChild, "position", value.m_Translate, bReuse);
    }
}

// "File:<document>(<row>) // NodeInfo:<name> a="v" ..." for error messages.
// @0x140875470
CStringW XmlNodeInfo(TiXmlElement* pElem)
{
    if (pElem == NULL)
        return L"";
    CString strFile;
    TiXmlNode* pRoot = pElem->Parent();
    if (pRoot)
    {
        while (pRoot->Parent() && pRoot->Parent() != pRoot)
            pRoot = pRoot->Parent();
        strFile = XmlWide(pRoot->Value());
    }
    CStringW str = StringFormat(L"File:{0}({1}) // NodeInfo:{2}", strFile, pElem->Row(), XmlWide(pElem->Value()));
    TiXmlAttribute* pAttr = pElem->FirstAttribute();
    while (pAttr)
    {
        str = StringFormat(L"{0} {1}=\"{2}\"", str, XmlWide(pAttr->Name()), XmlWide(pAttr->Value()));
        if (pAttr == pAttr->Next())
            break;
        pAttr = pAttr->Next();
    }
    return str;
}

// @0x140875760
void XmlParsePoint(const CString& str, NiPoint3& out)
{
    ATL::CAtlArray<CString> values;
    if (!FUN_14028c3e0(str, values, ",", 3))
        return;
    out.x = (float)atof(values[0]);
    out.y = (float)atof(values[1]);
    out.z = (float)atof(values[2]);
}

// The exe's efd::AtomicDecrement(UInt64&) (0x1408765e0) calls winnt.h's InterlockedDecrement64 out of line (this
// copy); the SDK header here uses the intrinsic, so the compiled AtomicDecrement does the lock xadd itself.
// @0x1408769b0
LONG64 Unk_InterlockedDecrement64(LONG64 volatile* pAddend)
{
    return _InterlockedDecrement64(pAddend);
}

MS2_REPLACE_OVERLOAD(0x140872ec0, TiXmlElement*(TiXmlElement*, const char*, bool), XmlChild, 195, 0x0FBD7DEA);
MS2_REPLACE_OVERLOAD(0x140872f90, int(TiXmlElement*, CStringA&), XmlGetText, 94, 0x29FB1159);
MS2_REPLACE_OVERLOAD(0x140873000, int(TiXmlElement*, CStringW&), XmlGetText, 145, 0x2AD98460);
MS2_REPLACE_OVERLOAD(0x1408730a0, int(TiXmlElement*, const char*, bool&), XmlGetAttr, 44, 0x7B53D319);
MS2_REPLACE_OVERLOAD(0x1408730e0, int(TiXmlElement*, const char*, char&), XmlGetAttr, 44, 0x840E9249);
MS2_REPLACE_OVERLOAD(0x140873120, int(TiXmlElement*, const char*, unsigned char&), XmlGetAttr, 44, 0xE9E74899);
MS2_REPLACE_OVERLOAD(0x140873160, int(TiXmlElement*, const char*, short&), XmlGetAttr, 44, 0xE9E74899);
MS2_REPLACE_OVERLOAD(0x1408731a0, int(TiXmlElement*, const char*, unsigned short&), XmlGetAttr, 44, 0xE9E74899);
MS2_REPLACE_OVERLOAD(0x1408731e0, int(TiXmlElement*, const char*, int&), XmlGetAttr, 44, 0xE9E74899);
MS2_REPLACE_OVERLOAD(0x140873220, int(TiXmlElement*, const char*, unsigned&), XmlGetAttr, 44, 0xE9E74899);
MS2_REPLACE_OVERLOAD(0x140873260, int(TiXmlElement*, const char*, long&), XmlGetAttr, 44, 0xE9E74899);
MS2_REPLACE_OVERLOAD(0x1408732a0, int(TiXmlElement*, const char*, unsigned long&), XmlGetAttr, 44, 0xE9E74899);
MS2_REPLACE_OVERLOAD(0x1408732e0, int(TiXmlElement*, const char*, __int64&), XmlGetAttr, 44, 0xE9E74899);
MS2_REPLACE_OVERLOAD(0x140873320, int(TiXmlElement*, const char*, unsigned __int64&), XmlGetAttr, 44, 0x662028B9);
MS2_REPLACE_OVERLOAD(0x140873360, int(TiXmlElement*, const char*, float&), XmlGetAttr, 44, 0xF8021159);
MS2_REPLACE_OVERLOAD(0x1408733a0, int(TiXmlElement*, const char*, double&), XmlGetAttr, 44, 0xF8021159);
MS2_REPLACE_OVERLOAD(0x1408733e0, int(TiXmlElement*, const char*, CStringA&), XmlGetAttr, 44, 0xF8021159);
MS2_REPLACE_OVERLOAD(0x140873420, int(TiXmlElement*, const char*, CStringW&), XmlGetAttr, 44, 0x743AF179);
MS2_REPLACE_OVERLOAD(0x140873460, int(TiXmlElement*, const char*, ATL::CTimeSpan&), XmlGetAttr, 191, 0xDB473B07);
MS2_REPLACE_OVERLOAD(0x140873530, int(TiXmlElement*, const char*, Unk_Rgb3b&), XmlGetAttr, 202, 0x76F5A8CF);
MS2_REPLACE_OVERLOAD(0x140873600, int(TiXmlElement*, const char*, CMsTime&), XmlGetAttr, 193, 0x64F546C3);
MS2_REPLACE_OVERLOAD(0x1408736d0, int(TiXmlElement*, const char*, bool&), XmlQuery, 44, 0x4C56C77A);
MS2_REPLACE_OVERLOAD(0x140873710, int(TiXmlElement*, const char*, int&), XmlGetBool, 101, 0x08E34FF8);
MS2_REPLACE_OVERLOAD(0x140873780, int(TiXmlElement*, const char*, char&), XmlQuery, 71, 0x959E2118);
MS2_REPLACE_OVERLOAD(0x1408737d0, int(TiXmlElement*, const char*, unsigned char&), XmlQuery, 44, 0x7A277E1A);
MS2_REPLACE_OVERLOAD(0x140873810, int(TiXmlElement*, const char*, short&), XmlQuery, 44, 0x2F0F9BA0);
MS2_REPLACE_OVERLOAD(0x140873850, int(TiXmlElement*, const char*, unsigned short&), XmlQuery, 44, 0x9F081031);
MS2_REPLACE_OVERLOAD(0x140873890, int(TiXmlElement*, const char*, int&), XmlQuery, 44, 0x95A01610);
MS2_REPLACE_OVERLOAD(0x1408738d0, int(TiXmlElement*, const char*, unsigned&), XmlQuery, 44, 0xB62DCCF0);
MS2_REPLACE_OVERLOAD(0x140873910, int(TiXmlElement*, const char*, long&), XmlQuery, 44, 0x0CC87061);
MS2_REPLACE_OVERLOAD(0x140873950, int(TiXmlElement*, const char*, unsigned long&), XmlQuery, 44, 0x636FA1C1);
MS2_REPLACE_OVERLOAD(0x140873990, int(TiXmlElement*, const char*, __int64&), XmlQuery, 80, 0xADC64993);
MS2_REPLACE_OVERLOAD(0x1408739f0, int(TiXmlElement*, const char*, unsigned __int64&), XmlQuery, 88, 0x9D6C0299);
MS2_REPLACE_OVERLOAD(0x140873a50, int(TiXmlElement*, const char*, float&), XmlQuery, 44, 0xDC9CA38F);
MS2_REPLACE_OVERLOAD(0x140873a90, int(TiXmlElement*, const char*, double&), XmlQuery, 44, 0x432B3A20);
MS2_REPLACE_OVERLOAD(0x140873ad0, int(TiXmlElement*, const char*, CStringA&), XmlQuery, 77, 0xCB7DA5AC);
MS2_REPLACE_OVERLOAD(0x140873b30, int(TiXmlElement*, const char*, CStringW&), XmlQuery, 128, 0xED8A3441);
MS2_REPLACE_OVERLOAD(0x140873bc0, void(TiXmlElement*, const char*, bool), XmlSetAttr, 87, 0xAD7320CC);
MS2_REPLACE_OVERLOAD(0x140873c20, void(TiXmlElement*, const char*, short), XmlSetAttr, 56, 0x6685BC5D);
MS2_REPLACE_OVERLOAD(0x140873c60, void(TiXmlElement*, const char*, unsigned short), XmlSetAttr, 56, 0x8BEA47E5);
MS2_REPLACE_OVERLOAD(0x140873ca0, void(TiXmlElement*, const char*, int), XmlSetAttr, 52, 0x2A88FE26);
MS2_REPLACE_OVERLOAD(0x140873ce0, void(TiXmlElement*, const char*, unsigned), XmlSetAttr, 105, 0xD064F787);
MS2_REPLACE_OVERLOAD(0x140873d50, void(TiXmlElement*, const char*, long), XmlSetAttr, 105, 0xF8FEECEF);
MS2_REPLACE_OVERLOAD(0x140873dc0, void(TiXmlElement*, const char*, unsigned long), XmlSetAttr, 105, 0xDCB24609);
MS2_REPLACE_OVERLOAD(0x140873e30, void(TiXmlElement*, const char*, float), XmlSetAttr, 57, 0x4DB5256C);
MS2_REPLACE_OVERLOAD(0x140873e70, void(TiXmlElement*, const char*, double), XmlSetAttr, 54, 0xCEEDBED4);
MS2_REPLACE_OVERLOAD(0x140873eb0, void(TiXmlElement*, const char*, const __int64&), XmlSetAttr, 105, 0xB9C4D53D);
MS2_REPLACE_OVERLOAD(0x140873f20, void(TiXmlElement*, const char*, const unsigned __int64&), XmlSetAttr, 105, 0xB421D468);
MS2_REPLACE_OVERLOAD(0x140873f90, void(TiXmlElement*, const char*, const char*), XmlSetAttr, 52, 0xAE0DEFD3);
MS2_REPLACE_OVERLOAD(0x140873fd0, void(TiXmlElement*, const char*, const wchar_t*), XmlSetAttr, 115, 0x62CF9920);
MS2_REPLACE_OVERLOAD(0x140874050, void(TiXmlElement*, const char*, const CStringA&), XmlSetAttr, 61, 0x117740CB);
MS2_REPLACE_OVERLOAD(0x1408740a0, void(TiXmlElement*, const char*, const CStringW&), XmlSetAttr, 124, 0x0A83BAAE);
MS2_REPLACE_OVERLOAD(0x140874130, int(TiXmlElement*, const char*, const char*, bool&), XmlGetChildAttr, 92, 0x21369994);
MS2_REPLACE_OVERLOAD(0x1408741a0, int(TiXmlElement*, const char*, const char*, int&), XmlGetChildAttr, 92, 0x0E22E194);
MS2_REPLACE_OVERLOAD(0x140874210, int(TiXmlElement*, const char*, const char*, float&), XmlGetChildAttr, 92, 0xF96A3BDB);
MS2_REPLACE_OVERLOAD(0x140874280, int(TiXmlElement*, const char*, const char*, CStringA&), XmlGetChildAttr, 92, 0x3D37447B);
MS2_REPLACE_OVERLOAD(0x1408742f0, int(TiXmlElement*, const char*, const char*, CStringW&), XmlGetChildAttr, 92, 0x633C87E7);
MS2_REPLACE_OVERLOAD(0x140874360, int(TiXmlElement*, const char*, const char*, unsigned __int64&), XmlGetChildAttr, 92, 0xCC8B1FD2);
MS2_REPLACE_OVERLOAD(0x1408743d0, void(TiXmlElement*, const char*, const char*, bool, bool), XmlSetChildAttr, 92, 0xB7777EC1);
MS2_REPLACE_OVERLOAD(0x140874440, void(TiXmlElement*, const char*, const char*, int, bool), XmlSetChildAttr, 91, 0xDF22DF9E);
MS2_REPLACE_OVERLOAD(0x1408744b0, void(TiXmlElement*, const char*, const char*, float, bool), XmlSetChildAttr, 93, 0xEBF35C76);
MS2_REPLACE_OVERLOAD(0x140874520, void(TiXmlElement*, const char*, const char*, const CStringA&, bool), XmlSetChildAttr, 91, 0x6E3BC7A9);
MS2_REPLACE_OVERLOAD(0x140874590, void(TiXmlElement*, const char*, const char*, const CStringW&, bool), XmlSetChildAttr, 91, 0xF8F296EA);
MS2_REPLACE_OVERLOAD(0x140874600, void(TiXmlElement*, const char*, const char*, const unsigned __int64&, bool), XmlSetChildAttr, 91, 0x4A9FAE20);
MS2_REPLACE_OVERLOAD(0x140874670, int(TiXmlElement*, const char*, efd::Point3&), XmlGetAttr, 44, 0x9D93591B);
MS2_REPLACE_OVERLOAD(0x1408746b0, int(TiXmlElement*, const char*, NiFixedString&), XmlGetAttr, 44, 0x3A89CC7A);
MS2_REPLACE_OVERLOAD(0x1408746f0, int(TiXmlElement*, const char*, NiPoint3&), XmlGetAttr, 44, 0x3AEE47DD);
MS2_REPLACE_OVERLOAD(0x140874730, int(TiXmlElement*, NiTransform&), XmlGetAttr, 34, 0xFE5129E9);
MS2_REPLACE_OVERLOAD(0x140874760, int(TiXmlElement*, const char*, efd::Point3&), XmlQuery, 318, 0x8BD94A83);
MS2_REPLACE_OVERLOAD(0x1408748b0, int(TiXmlElement*, const char*, NiFixedString&), XmlQuery, 138, 0x36F1653F);
MS2_REPLACE_OVERLOAD(0x140874940, int(TiXmlElement*, const char*, NiPoint3&), XmlQuery, 140, 0x1C10C098);
MS2_REPLACE_OVERLOAD(0x1408749e0, int(TiXmlElement*, NiTransform&), XmlQuery, 157, 0x17191F5C);
MS2_REPLACE_OVERLOAD(0x140874a90, void(TiXmlElement*, const char*, const NiFixedString&), XmlSetAttr, 44, 0x0A81425B);
MS2_REPLACE_OVERLOAD(0x140874ad0, void(TiXmlElement*, const char*, const efd::Point3&), XmlSetAttr, 44, 0x6C93A24B);
MS2_REPLACE_OVERLOAD(0x140874b10, void(TiXmlElement*, const NiTransform&), XmlSetAttr, 34, 0xAD468C46);
MS2_REPLACE_OVERLOAD(0x140874b40, void(TiXmlElement*, const char*, const NiFixedString&), XmlWrite, 156, 0xF1CC31A6);
MS2_REPLACE_OVERLOAD(0x140874bf0, void(TiXmlElement*, const char*, const efd::Point3&), XmlWrite, 114, 0x0A27D908);
MS2_REPLACE_OVERLOAD(0x140874c70, void(TiXmlElement*, const NiTransform&), XmlWrite, 163, 0x531BE788);
MS2_REPLACE_OVERLOAD(0x140874d20, int(TiXmlElement*, const char*, const char*, NiFixedString&), XmlGetChildAttr, 92, 0x0AE819EE);
MS2_REPLACE_OVERLOAD(0x140874d90, int(TiXmlElement*, const char*, const char*, NiPoint3&), XmlGetChildAttr, 92, 0x15F326AE);
MS2_REPLACE_OVERLOAD(0x140874e00, int(TiXmlElement*, const char*, NiFrustum&), XmlGetChild, 278, 0x4E79E057);
MS2_REPLACE_OVERLOAD(0x140874f20, int(TiXmlElement*, const char*, NiRect<float>&), XmlGetChild, 176, 0xFEE7D9E1);
MS2_REPLACE_OVERLOAD(0x140874fe0, int(TiXmlElement*, const char*, NiTransform&), XmlGetChild, 180, 0x5BD36A99);
MS2_REPLACE_OVERLOAD(0x1408750a0, void(TiXmlElement*, const char*, const char*, const NiFixedString&, bool), XmlSetChildAttr, 91, 0xCAB927BE);
MS2_REPLACE_OVERLOAD(0x140875110, void(TiXmlElement*, const char*, const char*, const efd::Point3&, bool), XmlSetChildAttr, 91, 0x20D1B89E);
MS2_REPLACE_OVERLOAD(0x140875180, void(TiXmlElement*, const char*, const NiFrustum&, bool), XmlSetChild, 315, 0xAB6F6650);
MS2_REPLACE_OVERLOAD(0x1408752d0, void(TiXmlElement*, const char*, const NiRect<float>&, bool), XmlSetChild, 192, 0x9EE5F1E9);
MS2_REPLACE_OVERLOAD(0x1408753a0, void(TiXmlElement*, const char*, const NiTransform&, bool), XmlSetChild, 192, 0xE82BD901);
MS2_REPLACE_OVERLOAD(0x140875470, CStringW(TiXmlElement*), XmlNodeInfo, 746, 0xD9EC8598);
MS2_REPLACE_OVERLOAD(0x140875760, void(const CString&, NiPoint3&), XmlParsePoint, 233, 0x7AC729D4);

// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Construct1@PEADAEBQEAD@?$_Normal_allocator_traits@V?$CustomAllocator@D@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@D@efd@@PEAPEADAEBQEAD@Z 0x140876170 ; unique
// MS2-PIN: ??$_Destroy1@PEAD@?$_Normal_allocator_traits@V?$CustomAllocator@D@efd@@@std@@SAXAEAV?$CustomAllocator@D@efd@@PEAPEADU?$integral_constant@_N$00@1@@Z 0x1408761c0 ; unique
// MS2-PIN: ??$construct@PEADAEBQEAD@?$_Normal_allocator_traits@V?$CustomAllocator@D@efd@@@std@@SAXAEAV?$CustomAllocator@D@efd@@PEAPEADAEBQEAD@Z 0x140876300 ; unique
// MS2-PIN: ??$destroy@PEAD@?$_Normal_allocator_traits@V?$CustomAllocator@D@efd@@@std@@SAXAEAV?$CustomAllocator@D@efd@@PEAPEAD@Z 0x140876340 ; unique
// MS2-PIN: ?_Get_data@?$_String_alloc@U?$_String_base_types@DV?$CustomAllocator@D@efd@@@std@@@std@@QEAAAEAV?$_String_val@U?$_Simple_types@D@std@@@2@XZ 0x1408768f0 ; unique
// MS2-PIN: ?_Get_data@?$_String_alloc@U?$_String_base_types@DV?$CustomAllocator@D@efd@@@std@@@std@@QEBAAEBV?$_String_val@U?$_Simple_types@D@std@@@2@XZ 0x140876910 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@D@efd@@V?$_String_val@U?$_Simple_types@D@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@D@efd@@XZ 0x140876930 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@D@efd@@V?$_String_val@U?$_Simple_types@D@std@@@std@@$00@std@@QEAAAEAV?$_String_val@U?$_Simple_types@D@std@@@2@XZ 0x140876950 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@D@efd@@V?$_String_val@U?$_Simple_types@D@std@@@std@@$00@std@@QEBAAEBV?$_String_val@U?$_Simple_types@D@std@@@2@XZ 0x140876960 ; prop
// MS2-PIN: ?_Getal@?$_String_alloc@U?$_String_base_types@DV?$CustomAllocator@D@efd@@@std@@@std@@QEAAAEAV?$CustomAllocator@D@efd@@XZ 0x140876970 ; unique
// MS2-PIN: ?_Max_size1@?$_Normal_allocator_traits@V?$CustomAllocator@D@efd@@@std@@SA_KAEBV?$CustomAllocator@D@efd@@U?$integral_constant@_N$00@2@@Z 0x1408769d0 ; unique
// MS2-PIN: ?_Tidy_deallocate@?$basic_string@DU?$char_traits@D@std@@V?$CustomAllocator@D@efd@@@std@@QEAAXXZ 0x140876a10 ; unique
// MS2-PIN: ?max_size@?$CustomAllocator@D@efd@@QEBA_KXZ 0x140876d20 ; unique
// MS2-PIN: ?max_size@?$_Normal_allocator_traits@V?$CustomAllocator@D@efd@@@std@@SA_KAEBV?$CustomAllocator@D@efd@@@Z 0x140876d30 ; unique
// MS2-PIN: ?max_size@?$basic_string@DU?$char_traits@D@std@@V?$CustomAllocator@D@efd@@@std@@QEBA_KXZ 0x140876d50 ; unique
// MS2-PINS-END tplpin
// MS2-FUNCTIONAL ?AtomicDecrement@efd@@YA_KAEA_K@Z: the exe calls InterlockedDecrement64 out of line (Unk_InterlockedDecrement64), the efd header inlines the intrinsic
// MS2-PIN: ?AtomicDecrement@efd@@YA_KAEA_K@Z 0x1408765e0 ; efd::GlobalStringTable::DecRefCount calls it
// MS2-PIN: ?Unk_InterlockedDecrement64@@YA_JPEC_J@Z 0x1408769b0 ; called by AtomicDecrement 0x1408765e0
