// Game-side TinyXML document (not efd::TiXmlDocument). Size from deleting destructor.
// Only directly called members are declared; no virtual dispatch through this placeholder.
#pragma once
#include <stdio.h>
#include "ms2/ms2layout.h"
#ifndef TIXML_ENCODING_DEFINED   // also commonfiles/tinyxml.h and the unit-local copies
#define TIXML_ENCODING_DEFINED
enum TiXmlEncoding { TIXML_ENCODING_UNKNOWN, TIXML_ENCODING_UTF8, TIXML_ENCODING_LEGACY };
#endif
class TiXmlDocument {
public:
    TiXmlDocument();
    TiXmlDocument(const TiXmlDocument& rhs);                                   // 0x140870c70
    virtual ~TiXmlDocument();
    // Virtual slots 1..16 (vftable 0x142ce6780). The To*() accessors are TiXmlNode's inline virtuals in the original;
    // they are flattened into this placeholder (achievedata.cpp emits their COMDATs with the vftable).
    virtual void Print(FILE* pFile, int nDepth) const;                          // slot 1, 0x140871470 (tinyxmlhelper.cpp)
    virtual const char* Parse(const char* p, void* pData, int nEncoding);       // slot 2, 0x140879940 (tinyxmlhelper.cpp)
    virtual const TiXmlDocument* ToDocument() const { return this; }           // slot 3
    virtual TiXmlDocument* ToDocument() { return this; }                       // slot 4
    virtual const class TiXmlElement* ToElement() const { return 0; }          // slot 5
    virtual class TiXmlElement* ToElement() { return 0; }                      // slot 6
    virtual const class TiXmlComment* ToComment() const { return 0; }          // slot 7
    virtual class TiXmlComment* ToComment() { return 0; }                      // slot 8
    virtual const class TiXmlUnknown* ToUnknown() const { return 0; }          // slot 9
    virtual class TiXmlUnknown* ToUnknown() { return 0; }                      // slot 10
    virtual const class TiXmlText* ToText() const { return 0; }                // slot 11
    virtual class TiXmlText* ToText() { return 0; }                            // slot 12
    virtual const class TiXmlDeclaration* ToDeclaration() const { return 0; }  // slot 13
    virtual class TiXmlDeclaration* ToDeclaration() { return 0; }              // slot 14
    virtual TiXmlDocument* Clone() const;                                      // slot 15, 0x140871580 (tinyxmlhelper.cpp)
    virtual bool Accept(void* pVisitor) const;                                 // slot 16, 0x1408714e0 (tinyxmlhelper.cpp)
    bool LoadFile(const char* filename, TiXmlEncoding encoding);               // 0x140870fc0
    bool SaveFile() const;                                                     // 0x140870f90
    bool SaveFile(const char* filename) const;                                 // 0x1408710c0
    TiXmlDocument& operator=(const TiXmlDocument& rhs);                        // 0x140870cf0
    bool LoadMemory(const char* buf, unsigned length, TiXmlEncoding encoding); // 0x140870d70 (tinyxml.cpp)
private:
    void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30;
    void* m_38; void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68;
};
MS2_CHECK_SIZE(TiXmlDocument,0x70);
