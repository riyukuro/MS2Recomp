// tixmlelement.h - PLACEHOLDER (not an original header): a reduced view of commonfiles/tinyxml.h's TiXmlNode /
// TiXmlElement for the units that don't include the real header (via xmlattr.h, or directly).
// - Real signatures and the real layout (vptr 0, firstChild +0x28, value +0x38, attributeSet +0x50, 0x90 in all).
// - The ctor and the virtual dtors / Parse are declared only: no ctor or dtor body is compiled through this view, so
//   no vftable or RTTI is emitted from it, and every reference resolves to tinyxml.obj's definitions.
// - The inline bodies are byte-identical to the real ones (or to the exe's inline COMDATs at the tagged VAs).
// - A unit that also needs the real tinyxml.h must include tinyxml.h first; this view then steps aside.
// - No DynamicCast / RTTI through this view.
#pragma once

// TinyXML's own TiXmlString (reference to a rep {size, capacity, str[]}); the exe's c_str is this 18-byte accessor, not
// std::string::c_str (0x1401d4890).
struct Unk_TiXmlString
{
    struct Rep { size_t size; size_t capacity; char str[1]; };
    Rep* m_rep;
    const char* c_str() const { return m_rep->str; }
};

#ifndef TINYXML_INCLUDED
#define MS2_TIXML_REDUCED_VIEW

#ifndef TIXML_ENCODING_DEFINED   // also tixmldocument.h and tinyxml.h
#define TIXML_ENCODING_DEFINED
enum TiXmlEncoding { TIXML_ENCODING_UNKNOWN, TIXML_ENCODING_UTF8, TIXML_ENCODING_LEGACY };
#endif

class TiXmlElement;
class TiXmlParsingData;

// TinyXML attribute (only the sentinel of an element's attribute set is touched here).
class Unk_TiXmlAttribute
{
public:
    void* unknown00[7];                         // TiXmlBase, document, name, value, prev
    Unk_TiXmlAttribute* next;                   // +0x38
};

class Unk_TiXmlAttributeSet
{
public:
    // @0x140552d70
    Unk_TiXmlAttribute* First() { return (sentinel.next == &sentinel) ? 0 : sentinel.next; }
    Unk_TiXmlAttribute sentinel;
};

class TiXmlNode
{
public:
    virtual ~TiXmlNode();
    // @0x140189180
    const char* Value() const { return value.c_str(); }
    void Clear();
    TiXmlNode* FirstChild();
    TiXmlNode* LinkEndChild(TiXmlNode* addThis);
    TiXmlNode* InsertEndChild(const TiXmlNode& addThis);
    bool RemoveChild(TiXmlNode* removeThis);
    const TiXmlElement* FirstChildElement() const;
    const TiXmlElement* FirstChildElement(const char* value) const;
    TiXmlElement* FirstChildElement(const char* value);                 // 0x140165cf0
    const TiXmlElement* NextSiblingElement() const;                     // 0x14086e770
    // @0x1403f0510 (TinyXML's non-const wrapper)
    TiXmlElement* NextSiblingElement() { return const_cast<TiXmlElement*>((const_cast<const TiXmlNode*>(this))->NextSiblingElement()); }
    const TiXmlElement* NextSiblingElement(const char* value) const;
    TiXmlElement* NextSiblingElement(const char* value);                // 0x140168650
protected:
    void* unknown08[4];                         // TiXmlBase location / userData, parent, type
    TiXmlNode* firstChild;                      // +0x28
    TiXmlNode* lastChild;                       // +0x30
    Unk_TiXmlString value;                      // +0x38
    TiXmlNode* prev;                            // +0x40
    TiXmlNode* next;                            // +0x48
};

class TiXmlElement : public TiXmlNode
{
public:
    TiXmlElement(const char* pszName);                                  // 0x14086f2f0
    virtual ~TiXmlElement();                                            // 0x14086f450
    virtual const char* Parse(const char* p, TiXmlParsingData* data, TiXmlEncoding encoding);   // 0x1408782b0
    const char* Attribute(const char* name) const;                      // 0x14086f4b0
    const char* Attribute(const char* name, int* i) const;              // 0x14086f500
    const char* Attribute(const char* name, double* d) const;
    int QueryIntAttribute(const char* name, int* ival) const;           // 0x14086f600
    void SetAttribute(const char* name, const char* value);
    void SetAttribute(const char* name, int value);
    void SetDoubleAttribute(const char* name, double value);
    void RemoveAttribute(const char* name);
    // @0x140552e00
    bool HasAttributes() { return attributeSet.First() == 0 ? false : true; }
    // @0x140552e40
    bool HasChildren() { return firstChild == 0 ? false : true; }
    // @0x140552e70
    bool HasContent() { return HasAttributes() || HasChildren(); }
private:
    Unk_TiXmlAttributeSet attributeSet;         // +0x50
};

#endif // TINYXML_INCLUDED
