// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MailText / MailTextParagraph / MailTextValue: see mailtextutil.h.
// MS2-UNIT: commonfiles\mailtextutil.cpp
// MS2-RANGE: 0x14065b160-0x140661c00 .text$mn
// MS2-GUESS-LOOKALIKES
//
// Ported from the v2525 snapshot's recovery of the same functions (names / shapes), re-judged against this exe.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\mailtextutil.cpp"

#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "mailtextutil.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (names describe uses) ----
int FUN_140873420(void* pElement, const char* szName, CStringW& strOut);        // xml attribute -> wide string
CStringW FUN_14083cb20(const CStringW& strNumber);                              // digits grouped with commas
bool FUN_14025cd60(const CStringW& a, const CStringW& b);                       // string equals
CStringW FUN_1407196b0(int nItem);                                              // an item id as text
CStringW FUN_140719a00(__int64 nMoney);                                         // a money amount as text
int FUN_140718200(const CStringW& strNumber);                                   // text -> int
void* FUN_140165cf0(void* pNode, const char* szName);                           // first child element
void* FUN_140168650(void* pNode, const char* szName);                           // next sibling element
bool FUN_14083d7e0(const CStringW& strText, const CStringW& strPrefix);         // starts with
CFileSystem* GetFileSystem();                                                   // the file system singleton
class Unk_MtItemTexts { public: CStringW FUN_141811980(int n, int nId); };      // text by kind and id (1 = item name)
Unk_MtItemTexts* FUN_1401a9d70();

// @0x14065ee80 / @0x14065eeb0: the arrays' Copy
template <class T> void MailCopyArray(ATL::CAtlArray<T>& destination, const ATL::CAtlArray<T>& source)
{
    destination.Copy(source);
}

// @0x14065b160
MailTextValue::MailTextValue() : m_kind(0), m_value(L""), m_auxiliary(L"") {}
// @0x14065b1d0
MailTextValue::MailTextValue(int kind, const CStringW& value, const CStringW& auxiliary)
    : m_kind(kind), m_value(value), m_auxiliary(auxiliary) {}
// @0x14065b240
bool MailTextValue::Load(void* element) {
    CStringW value;
    if (FUN_140873420(element, "str", value) != 1) {
        m_kind = 0;
        bool numeric = value.SpanIncluding(L"0123456789,.") == value;
        if (numeric && value.Replace(L",", L"") > 0)
            value = FUN_14083cb20(value);
        m_value = value;
        return true;
    }
    else if (FUN_140873420(element, "key", value) != 1) { m_kind = 1; m_value = value; return true; }
    else if (FUN_140873420(element, "item", value) != 1) { m_kind = 2; m_value = value; return true; }
    else if (FUN_140873420(element, "money", value) != 1) {
        m_kind = 3;
        bool numeric = value.SpanIncluding(L"0123456789") == value;
        if (numeric) value = FUN_14083cb20(value);
        m_value = value;
        return true;
    }
    MS2_ASSERT_AT(0x46, FALSE);
    return false;
}
// @0x14065b560
CStringW MailTextValue::Write(const CStringW& tag) {
    if (m_kind == 0) return StringFormat(L"<{0} str=\"{1}\" />", tag, m_value);
    else if (m_kind == 1) return StringFormat(L"<{0} key=\"{1}\" />", tag, m_value);
    else if (m_kind == 2) return StringFormat(L"<{0} item=\"{1}\" />", tag, m_value);
    else if (m_kind == 3) return StringFormat(L"<{0} money=\"{1}\" />", tag, m_value);
    MS2_ASSERT_AT(0x5d, FALSE); return CStringW(L"");
}
// @0x14065b6e0
CStringW MailTextValue::WriteChildren(const CStringW& tag, const CStringW& childTag, const ATL::CAtlArray<MailTextValue>& children) {
    CStringW result(L"");
    if (m_kind == 0) result += StringFormat(L"<{0} str=\"{1}\" >", tag, m_value);
    else if (m_kind == 1) result += StringFormat(L"<{0} key=\"{1}\" >", tag, m_value);
    else if (m_kind == 2) result += StringFormat(L"<{0} item=\"{1}\" >", tag, m_value);
    else if (m_kind == 3) result += StringFormat(L"<{0} money=\"{1}\" >", tag, m_value);
    else { MS2_ASSERT_AT(0x77, FALSE); return CStringW(L""); }
    for (unsigned i = 0; i < children.GetCount(); ++i) result += const_cast<MailTextValue&>(children[i]).Write(childTag);
    result += StringFormat(L"</{0}>", tag);
    return result;
}
// @0x14065ba60
CStringW MailTextValue::Resolve() {
    CStringW result(L"");
    if (m_kind == 0) result = m_value;
    else if (m_kind == 1) result = CommonString::GetInstance()->GetWideByKey(m_value);
    else if (m_kind == 2) { int item = FUN_140718200(m_value); result = FUN_1401a9d70()->FUN_141811980(1, item); }
    else if (m_kind == 3) result = m_value;
    else MS2_ASSERT_AT(0xa0, FALSE);
    return result;
}
// @0x14065bc20
int MailTextValue::GetKind() { return m_kind; }
// @0x14065bc40
CStringW MailTextValue::GetValue() { return m_value; }
// @0x14065bc90
MailTextValue MailTextValue::Text(const CStringW& text) { MailTextValue result = MailTextValue(0, text, L""); return result; }
// @0x14065bd20
MailTextValue MailTextValue::Key(int key) { CStringW value = CommonString::GetInstance()->GetWideRaw(key); MailTextValue result = MailTextValue(1, value, L""); return result; }
// @0x14065bdd0
MailTextValue MailTextValue::Item(int item, const CStringW& auxiliary) { MailTextValue result = MailTextValue(2, FUN_1407196b0(item), auxiliary); return result; }
// @0x14065be70
MailTextValue MailTextValue::Money(__int64 money) { MailTextValue result = MailTextValue(3, FUN_140719a00(money), L""); return result; }
// @0x14065bf30
MailTextParagraph::MailTextParagraph() {}
// @0x14065bf70
MailTextParagraph::MailTextParagraph(const MailTextParagraph& value) : m_value(value.m_value) { MailCopyArray(m_children, value.m_children); }
// @0x14065bfe0
MailTextParagraph::MailTextParagraph(const MailTextValue& value) : m_value(value) {}
// @0x14065c030
MailTextParagraph::MailTextParagraph(const MailTextValue& value, const MailTextValue& a) : m_value(value) { m_children.Add(a); }
// @0x14065c0a0
MailTextParagraph::MailTextParagraph(const MailTextValue& value, const MailTextValue& a, const MailTextValue& b) : m_value(value) { m_children.Add(a); m_children.Add(b); }
// @0x14065c130
MailTextParagraph::MailTextParagraph(const MailTextValue& value, const MailTextValue& a, const MailTextValue& b, const MailTextValue& c) : m_value(value) { m_children.Add(a); m_children.Add(b); m_children.Add(c); }
// @0x14065c1d0
MailTextParagraph::MailTextParagraph(const MailTextValue& value, const MailTextValue& a, const MailTextValue& b, const MailTextValue& c, const MailTextValue& d) : m_value(value) { m_children.Add(a); m_children.Add(b); m_children.Add(c); m_children.Add(d); }
// @0x14065c280
MailTextParagraph& MailTextParagraph::operator=(const MailTextParagraph& value) { m_value = value.m_value; MailCopyArray(m_children, value.m_children); return *this; }
// @0x14065c2d0
void MailTextParagraph::AddText(const CStringW& text) { m_children.Add(MailTextValue::Text(text)); }
// @0x14065c340
void MailTextParagraph::AddKey(int key) { m_children.Add(MailTextValue::Key(key)); }
// @0x14065c3a0
void MailTextParagraph::AddItem(int item, const CStringW& auxiliary) { m_children.Add(MailTextValue::Item(item, auxiliary)); }
// @0x14065c410
bool MailTextParagraph::Load(void* root) {
    bool loaded = m_value.Load(root);
    if (!loaded) return false;
    for (void* child = FUN_140165cf0(root, "p"); child; child = FUN_140168650(child, "p")) {
        MailTextValue value; value.Load(child); m_children.Add(value);
    }
    return true;
}
// @0x14065c4d0
CStringW MailTextParagraph::Write(const CStringW& tag) { return m_value.WriteChildren(tag, L"p", m_children); }
// @0x14065c560
CStringW MailTextParagraph::Resolve() {
    CStringW result = m_value.Resolve();
    switch (m_children.GetCount()) {
    case 0: return result;
    case 1: return StringFormat(result, ResolveChild(0));
    case 2: return StringFormat(result, ResolveChild(0), ResolveChild(1));
    case 3: return StringFormat(result, ResolveChild(0), ResolveChild(1), ResolveChild(2));
    case 4: return StringFormat(result, ResolveChild(0), ResolveChild(1), ResolveChild(2), ResolveChild(3));
    case 5: return StringFormat(result, ResolveChild(0), ResolveChild(1), ResolveChild(2), ResolveChild(3), ResolveChild(4));
    }
    MS2_ASSERT_AT(0x13c, FALSE);
    return result;
}
// @0x14065cc10
bool MailTextParagraph::IsPlain() { return m_value.GetKind() == 0 && m_children.IsEmpty() ? 1 : 0; }
// @0x14065cc70
CStringW MailTextParagraph::ResolveChild(int index) {
    if ((int)m_children.GetCount() <= index) return CStringW(L"");
    return m_children[index].Resolve();
}
// @0x14065cd10
MailTextParagraph MailTextParagraph::Text(const CStringW& text) { MailTextParagraph result = MailTextParagraph(MailTextValue::Text(text)); return result; }
// @0x14065cdb0
MailTextParagraph MailTextParagraph::Key(int key) { MailTextParagraph result = MailTextParagraph(MailTextValue::Key(key)); return result; }
// @0x14065ce50
MailTextParagraph MailTextParagraph::Item(int item, const CStringW& auxiliary) { MailTextParagraph result = MailTextParagraph(MailTextValue::Item(item, auxiliary)); return result; }
// @0x14065cf00
MailTextParagraph MailTextParagraph::Money(__int64 money) { MailTextParagraph result = MailTextParagraph(MailTextValue::Money(money)); return result; }
// @0x14065cfa0
MailText::MailText(int code) : m_code(code), m_number(0) {}
// @0x14065d000
MailText::MailText(int code, const MailText& value) : m_code(code), m_number(0) { m_title = value.m_title; MailCopyArray(m_paragraphs, value.m_paragraphs); }
// @0x14065d0a0
MailText::MailText(int code, unsigned int key) : m_code(code), m_number(0) { SetTitleKey(key); }
// @0x14065d120
MailText::MailText(int code, int number) : m_code(code), m_number(0) { SetNumber(number); }
// @0x14065d1a0
MailText::MailText(int code, const CStringW& text) : m_code(code), m_number(0) { SetTitleText(text); }
// @0x14065d220
MailText::MailText(int code, __int64 money) : m_code(code), m_number(0) { SetTitleMoney(money); }
// @0x14065d2a0
void MailText::SetTitleKey(int key) { m_number = 0; m_title = MailTextValue::Key(key); }
// @0x14065d310
void MailText::SetNumber(int number) { m_number = number; }
// @0x14065d330
void MailText::SetTitleText(const CStringW& text) { m_number = 0; m_title = MailTextValue::Text(text); }
// @0x14065d3a0
void MailText::SetTitleMoney(__int64 money) { m_number = 0; m_title = MailTextValue::Money(money); }
// @0x14065d410
void MailText::AddText(const CStringW& text) { m_paragraphs.Add(MailTextParagraph::Text(text)); }
// @0x14065d480
void MailText::AddKey(int key) { m_paragraphs.Add(MailTextParagraph::Key(key)); }
// @0x14065d4f0
void MailText::Add(const MailTextParagraph& paragraph) { m_paragraphs.Add(paragraph); }
// @0x14065d520
void MailText::AddMoney(__int64 money) { m_paragraphs.Add(MailTextParagraph::Money(money)); }
// @0x14065d590
bool MailText::Load(const CStringW& title, const CStringW& body) {
    bool loaded = false;
    loaded = LoadTitle(title);
    if (!loaded) return false;
    loaded = LoadBody(body);
    if (!loaded) return false;
    return loaded;
}
// @0x14065d600
bool MailText::LoadTitle(const CStringW& text) {
    SetTitleText(text);
    if (!FUN_14083d7e0(text, L"<ms2>")) return true;
    TiXmlDocument document;
    if (!GetFileSystem()->FUN_140397ab0(&document, text)) return false;
    void* root = FUN_140165cf0(&document, "ms2"); if (!root) return false;
    void* title = FUN_140165cf0(root, "title"); if (!title) return false;
    bool loaded = m_title.Load(title);
    if (!loaded) MS2_ASSERT_AT(0x1e6, FALSE);
    return true;
}
// @0x14065d7b0
bool MailText::LoadBody(const CStringW& text) {
    m_paragraphs.RemoveAll();
    if (!FUN_14083d7e0(text, L"<ms2>")) return true;
    TiXmlDocument document;
    if (!GetFileSystem()->FUN_140397ab0(&document, text)) return false;
    void* root = FUN_140165cf0(&document, "ms2"); if (!root) return false;
    void* firstChild = FUN_140165cf0(root, "body");
    if (!firstChild) return false;
    for (void* child = firstChild; child; child = FUN_140168650(child, "body")) {
        MailTextParagraph paragraph;
        bool loaded = paragraph.Load(child);
        m_paragraphs.Add(paragraph);
        if (!loaded) MS2_ASSERT_AT(0x209, FALSE);
    }
    return true;
}
// @0x14065d9d0
CStringW MailText::ResolveTitle() {
    CStringW result = m_title.Resolve();
    switch (m_paragraphs.GetCount()) {
    case 0: return result;
    case 1: return StringFormat(result, ResolveParagraph(0));
    case 2: return StringFormat(result, ResolveParagraph(0), ResolveParagraph(1));
    case 3: return StringFormat(result, ResolveParagraph(0), ResolveParagraph(1), ResolveParagraph(2));
    case 4: return StringFormat(result, ResolveParagraph(0), ResolveParagraph(1), ResolveParagraph(2), ResolveParagraph(3));
    case 5: return StringFormat(result, ResolveParagraph(0), ResolveParagraph(1), ResolveParagraph(2), ResolveParagraph(3), ResolveParagraph(4));
    case 6: return StringFormat(result, ResolveParagraph(0), ResolveParagraph(1), ResolveParagraph(2), ResolveParagraph(3), ResolveParagraph(4), ResolveParagraph(5));
    case 7: return StringFormat(result, ResolveParagraph(0), ResolveParagraph(1), ResolveParagraph(2), ResolveParagraph(3), ResolveParagraph(4), ResolveParagraph(5), ResolveParagraph(6));
    case 8: return StringFormat(result, ResolveParagraph(0), ResolveParagraph(1), ResolveParagraph(2), ResolveParagraph(3), ResolveParagraph(4), ResolveParagraph(5), ResolveParagraph(6), ResolveParagraph(7));
    case 9: return StringFormat(result, ResolveParagraph(0), ResolveParagraph(1), ResolveParagraph(2), ResolveParagraph(3), ResolveParagraph(4), ResolveParagraph(5), ResolveParagraph(6), ResolveParagraph(7), ResolveParagraph(8));
    case 10: return StringFormat(result, ResolveParagraph(0), ResolveParagraph(1), ResolveParagraph(2), ResolveParagraph(3), ResolveParagraph(4), ResolveParagraph(5), ResolveParagraph(6), ResolveParagraph(7), ResolveParagraph(8), ResolveParagraph(9));
    }
    MS2_ASSERT_AT(0x263, FALSE);
    return result;
}

// @0x14065edf0
CStringW MailText::ResolveParagraph(int index) {
    if ((int)m_paragraphs.GetCount() <= index) return CStringW(L"");
    return m_paragraphs[index].Resolve();
}
