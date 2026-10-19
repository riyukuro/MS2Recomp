// tixmlprinter.h - PLACEHOLDER for the game's TinyXML TiXmlString / TiXmlVisitor / TiXmlPrinter (global namespace,
// not efd::). Shapes follow TinyXML 2.5 (tinystr.h / tinyxml.h, no TIXML_USE_STL); only what the users touch.
// The inline COMDATs were placed by ?\meratmarketbasketinfo.cpp (0x1406a8540...). The TiXmlPrinter visits are
// outside it (0x140871b80-0x140872050).
#pragma once
#include <string.h>
#include "ms2/ms2layout.h"

class TiXmlDocument;
class TiXmlElement;
class TiXmlAttribute;
class TiXmlDeclaration;
class TiXmlText;
class TiXmlComment;
class TiXmlUnknown;

class TiXmlString
{
public:
    typedef size_t size_type;

    // @0x1406a8660
    TiXmlString() : rep_(&nullrep_) {}
    // @0x1406a85d0
    explicit TiXmlString(const char* copy) : rep_(0)
    {
        init(static_cast<size_type>(strlen(copy)));
        memcpy(start(), copy, length());
    }
    // @0x1401646b0
    ~TiXmlString() { quit(); }

    // @0x14018efa0
    const char* c_str() const { return rep_->str; }
    // @0x1406aeab0
    size_type length() const { return rep_->size; }
    TiXmlString& operator=(const char* copy);              // 0x1408725b0 (inline in TinyXML; the COMDAT is outside the users' ranges)

private:
    // @0x1406aea80
    void init(size_type sz) { init(sz, sz); }
    // @0x1406aead0
    char* start() const { return rep_->str; }

    struct Rep
    {
        size_type size, capacity;
        char str[1];
    };

    void init(size_type sz, size_type cap)
    {
        if (cap)
        {
            const size_type bytesNeeded = sizeof(Rep) + cap;
            const size_type intsNeeded = (bytesNeeded + sizeof(int) - 1) / sizeof(int);
            rep_ = reinterpret_cast<Rep*>(new int[intsNeeded]);

            rep_->str[rep_->size = sz] = '\0';
            rep_->capacity = cap;
        }
        else
        {
            rep_ = &nullrep_;
        }
    }

    // @0x14016d840
    void quit()
    {
        if (rep_ != &nullrep_)
        {
            delete[] (reinterpret_cast<int*>(rep_));
        }
    }

    Rep* rep_;
    static Rep nullrep_;                                    // 0x143ab1fb0
};
MS2_CHECK_SIZE(TiXmlString, 0x8);

// vftable 0x142d78158. MSVC groups the same-named overloads (reversed), so the slots run VisitEnter(element),
// VisitEnter(doc), VisitExit(element), VisitExit(doc), Visit(unknown), Visit(comment), Visit(text), Visit(declaration).
class TiXmlVisitor
{
public:
    // @0x1406a8ba0
    virtual ~TiXmlVisitor() {}

    // @0x1406ae1d0
    virtual bool VisitEnter(const TiXmlDocument& /*doc*/) { return true; }
    // @0x1406ae200
    virtual bool VisitExit(const TiXmlDocument& /*doc*/) { return true; }

    // @0x1406ae1e0
    virtual bool VisitEnter(const TiXmlElement& /*element*/, const TiXmlAttribute* /*firstAttribute*/) { return true; }
    // @0x1406ae210
    virtual bool VisitExit(const TiXmlElement& /*element*/) { return true; }

    // @0x1406ae1a0
    virtual bool Visit(const TiXmlDeclaration& /*declaration*/) { return true; }
    // @0x1406ae1b0
    virtual bool Visit(const TiXmlText& /*text*/) { return true; }
    // @0x1406ae190
    virtual bool Visit(const TiXmlComment& /*comment*/) { return true; }
    // @0x1406ae1c0
    virtual bool Visit(const TiXmlUnknown& /*unknown*/) { return true; }
};

// Prints a node tree into a string (vftable 0x142d781a8).
class TiXmlPrinter : public TiXmlVisitor
{
public:
    // @0x1406a8540
    TiXmlPrinter() : depth(0), simpleTextPrint(false), buffer(), indent("\t"), lineBreak("\n") {}

    virtual bool VisitEnter(const TiXmlDocument& doc);      // 0x140871b80
    virtual bool VisitExit(const TiXmlDocument& doc);       // 0x140871ba0

    virtual bool VisitEnter(const TiXmlElement& element, const TiXmlAttribute* firstAttribute);  // 0x140871bc0
    virtual bool VisitExit(const TiXmlElement& element);    // 0x140871d60

    virtual bool Visit(const TiXmlDeclaration& declaration);    // 0x140871e20
    virtual bool Visit(const TiXmlText& text);              // 0x140871e80
    virtual bool Visit(const TiXmlComment& comment);        // 0x140871fd0
    virtual bool Visit(const TiXmlUnknown& unknown);        // 0x140872050

    // @0x1406a9770
    const char* CStr() { return buffer.c_str(); }
    // 0x141b324c0 (uitriggereditordialog.cpp): no indentation, no line breaks
    void SetStreamPrinting() { indent = ""; lineBreak = ""; }

private:
    int depth;                                              // +0x08
    bool simpleTextPrint;                                   // +0x0c
    TiXmlString buffer;                                     // +0x10
    TiXmlString indent;                                     // +0x18
    TiXmlString lineBreak;                                  // +0x20
};
MS2_CHECK_SIZE(TiXmlPrinter, 0x28);
