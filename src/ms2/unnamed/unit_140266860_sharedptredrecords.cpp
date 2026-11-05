// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The small CPtred data classes in front of the common structs:
// QuestMask (a flag plus its 16-byte quest ranges), ItemCustom's ctor and XML read / write, BaseOption (one int value
// with its stream IO) and InvokeEffectOption, plus a (key, pointer, ref) record. File name invented (no __FILE__ string).
// MS2-UNIT: unit_140266860
// MS2-RANGE: 0x140266860-0x140267090 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_140266860.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <efd/Point3.h>
#include <NiPoint3.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/questmasktable.h"
#include "ms2/placeholder/itemcustom.h"
#include "ms2/commonfiles/stream.h"

// ---- unit-local views of classes whose shared placeholders carry no vftable (layouts identical, same sizes) ----

// The stream views BaseOption / InvokeEffectOption use (virtual slots 0..4; the same shapes as itemenchantinfo.h).
class Unk_EnchantWrite {
public:
    virtual void vfunc_0(bool);
    virtual void vfunc_1(unsigned char);
    virtual void vfunc_2();
    virtual void vfunc_3(int);
    virtual void vfunc_4(__int64);
    virtual void vfunc_5(float);
};
class Unk_EnchantRead {
public:
    virtual bool vfunc_0();
    virtual unsigned char vfunc_1();
    virtual void vfunc_2();
    virtual int vfunc_3();
    virtual __int64 vfunc_4();
    virtual float vfunc_5();
};

// RTTI BaseOption, 0x20 bytes: one value (an int; the float view is value / 1000).
class BaseOption : public CPtred
{
public:
    BaseOption();                                       // 0x140266c70
    void FUN_140266cc0();                               // clear
    bool HasValue() const;
    void FUN_140266d20(Unk_EnchantWrite& rOut) const;
    void FUN_140266d60(Unk_EnchantRead& rIn);
    void FUN_140266da0(const BaseOption* pSource);      // copy
    void FUN_140266dd0(const BaseOption* pSource);      // add
    float FUN_140266e10() const;
    int GetValue() const;
    void FUN_140266e50(float fValue);
    void SetValue(int nValue);
    bool FUN_140266ee0(const BaseOption* pOther) const;

    int m_nValue;                                       // +0x18
    int m_nIndex;                                       // +0x1c
};
MS2_CHECK_SIZE(BaseOption, 0x20);

// RTTI InvokeEffectOption, 0x28 bytes.
class InvokeEffectOption : public CPtred
{
public:
    InvokeEffectOption();                               // 0x140266f10
    void FUN_140266f70();                               // clear
    void FUN_140266fb0(Unk_EnchantWrite& rOut) const;
    void FUN_140267020(Unk_EnchantRead& rIn);

    int m_nA;                                           // +0x18
    int m_nB;                                           // +0x1c
    float m_fC;                                         // +0x20
    int m_pad_24;
};
MS2_CHECK_SIZE(InvokeEffectOption, 0x28);

// A (key, pointer, ref) record.
struct Unk_Ref16 { void* m_unknown; void* m_p; };
class CUgcItemLook;   // C3: the ref is MS2Ptr<CUgcItemLook> (was the FUN_14027cb90 / FUN_14027cbb0 Unk_Ref16 views)
//
struct Unk_KeyedRef
{
    Unk_KeyedRef();                                     // 0x140266bc0
    Unk_KeyedRef(int nKey, void* pData, void* pRef);    // 0x140266c10

    int m_nKey;                                         // +0x00
    int m_pad_04;
    void* m_pData;                                      // +0x08
    Unk_Ref16 m_ref;                                    // +0x10
};
MS2_CHECK_SIZE(Unk_KeyedRef, 0x20);

// Out-of-line vector helpers and the XML attribute accessors of the game's TinyXML wrapper.
class TiXmlElement;
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, const char*, efd::Point3&);   // C3: was FUN_140874670 (0x140874670, xmlattr's Point3 reader)
void XmlSetAttr(class TiXmlElement*, char const*, const CStringA&);   // C3: was FUN_140874050
// The exe passes a NiPoint3 built implicitly from the efd::Point3 member (0x14027dcf0): XmlSetAttr's NiPoint3 view.
void FUN_140874ad0(class TiXmlElement* pElem, const char* pszName, const NiPoint3& pt);   // XmlSetAttr, NiPoint3 view
float FUN_14028aed0(float f);                           // round

// @0x140266860
QuestMask::QuestMask()
    : m_nEnable(1)
{
}

// @0x1402668b0
// MS2-FUNCTIONAL: CAtlArray<Unk_Z16i>::Copy is the exe free function FUN_140280a70 owned by commonstruct_2; the callee symbol cannot pair
QuestMask::QuestMask(const QuestMask& rOther)
    : m_nEnable(1)
{
    m_aRanges.Copy(rOther.m_aRanges);
}

// @0x140266930
// MS2-FUNCTIONAL: CAtlArray<Unk_Z16i>::Copy is the exe free function FUN_140280a70 owned by commonstruct_2; the callee symbol cannot pair
QuestMask& QuestMask::operator=(const QuestMask& rOther)
{
    m_aRanges.Copy(rOther.m_aRanges);
    return *this;
}

// @0x140266970
// MS2-FUNCTIONAL: CAtlArray<Unk_Z16i> operator[] / GetCount are the exe free functions FUN_14027f040 / FUN_1402815b0 owned by commonstruct_2
int QuestMask::FUN_140266970() const
{
    for (size_t i = 0; i < m_aRanges.GetCount(); i++)
    {
        if (m_aRanges[i].a == 0)
            return 0;
    }
    return m_aRanges.GetCount() > 0;
}

// @0x140266a10
ItemCustom::ItemCustom() : unknown18(0.0f, 0.0f, 0.0f), unknown24(0.0f, 0.0f, 0.0f)
{
}

// @0x140266aa0
void ItemCustom::FUN_140266aa0(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "icon", name);
    XmlGetAttr((class TiXmlElement*)(pElem), "position", reinterpret_cast<efd::Point3&>(unknown18));
    XmlGetAttr((class TiXmlElement*)(pElem), "rotation", reinterpret_cast<efd::Point3&>(unknown24));
}

// @0x140266b10
void ItemCustom::FUN_140266b10(void* pElem) const
{
    if (name.GetLength() > 0)
        XmlSetAttr((class TiXmlElement*)(pElem), "icon", name);
    FUN_140874ad0((class TiXmlElement*)(pElem), "position", unknown18);
    FUN_140874ad0((class TiXmlElement*)(pElem), "rotation", unknown24);
}

// @0x140266bc0
Unk_KeyedRef::Unk_KeyedRef()
{
    m_nKey = 0;
    m_pData = 0;
    reinterpret_cast<MS2Ptr<CUgcItemLook>*>(&m_ref)->MS2Ptr<CUgcItemLook>::MS2Ptr(0);
}

// @0x140266c10
Unk_KeyedRef::Unk_KeyedRef(int nKey, void* pData, void* pRef)
{
    m_nKey = nKey;
    m_pData = pData;
    reinterpret_cast<MS2Ptr<CUgcItemLook>*>(&m_ref)->MS2Ptr<CUgcItemLook>::MS2Ptr((CUgcItemLook*)pRef);
}

// @0x140266c70
BaseOption::BaseOption()
{
    m_nValue = 0;
    m_nIndex = 0;
}

// @0x140266cc0
void BaseOption::FUN_140266cc0()
{
    m_nValue = 0;
}

// @0x140266ce0
bool BaseOption::HasValue() const
{
    return m_nValue != 0;
}

// @0x140266d20
void BaseOption::FUN_140266d20(Unk_EnchantWrite& rOut) const
{
    rOut.vfunc_3(m_nValue);
}

// @0x140266d60
void BaseOption::FUN_140266d60(Unk_EnchantRead& rIn)
{
    m_nValue = rIn.vfunc_3();
}

// @0x140266da0
void BaseOption::FUN_140266da0(const BaseOption* pSource)
{
    if (pSource == 0)
        return;
    m_nValue = pSource->m_nValue;
}

// @0x140266dd0
void BaseOption::FUN_140266dd0(const BaseOption* pSource)
{
    if (pSource == 0)
        return;
    m_nValue = m_nValue + pSource->m_nValue;
}

// @0x140266e10
float BaseOption::FUN_140266e10() const
{
    return (float)m_nValue / 1000.0f;
}

// @0x140266e30
int BaseOption::GetValue() const
{
    return m_nValue;
}

// @0x140266e50
void BaseOption::FUN_140266e50(float fValue)
{
    m_nValue = (int)FUN_14028aed0(fValue * 1000.0f);
}

// @0x140266e90
void BaseOption::SetValue(int nValue)
{
    m_nValue = nValue;
}

// @0x140266ee0
bool BaseOption::FUN_140266ee0(const BaseOption* pOther) const
{
    if (m_nValue != pOther->m_nValue)
        return false;
    return true;
}

// @0x140266f10
InvokeEffectOption::InvokeEffectOption()
{
    m_nA = 0;
    m_nB = 0;
    m_fC = 0;
}

// @0x140266f70
void InvokeEffectOption::FUN_140266f70()
{
    m_fC = 0;
    m_nB = 0;
    m_nA = 0;
}

// @0x140266fb0
void InvokeEffectOption::FUN_140266fb0(Unk_EnchantWrite& rOut) const
{
    rOut.vfunc_3(m_nB);
    rOut.vfunc_5(m_fC);
    rOut.vfunc_3(m_nA);
}

// @0x140267020
void InvokeEffectOption::FUN_140267020(Unk_EnchantRead& rIn)
{
    m_nB = rIn.vfunc_3();
    m_fC = rIn.vfunc_5();
    m_nA = rIn.vfunc_3();
}
