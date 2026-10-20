// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Hidden string literals: a string class whose constructor
// takes a character count and the characters as varargs (keeps the literal out of the exe's string pool) and interns
// the text in a function-local static unordered_map; char and wchar_t twins. No string, assert or RTTI names this TU:
// every class/function name is invented (after the v2525 snapshot, work/ext/v2525 src/ms2/tu/140841580.cpp).
// The TU is [0x140841580, 0x14084cb30): its own code 0x140841580-0x140841c70 is followed by the STL COMDAT tail
// (unordered_map<string, vector<char>> / <wstring, vector<wchar_t>> internals) that unit_140841c70 covers.
// 0x140841780-0x140841c70 was queue unit unit_140841780; it is the same TU, so its range is merged here (w523).
// The two ctors 0x140841580/0x140841860 sit in no queue row.
// No hooks: nothing in the exe calls these functions, and Get/Table read the unit's mutable function-local statics.
// MS2-UNIT: unit_140841c70
// MS2-RANGE: 0x140841580-0x14084cb30 .text$mn
// MS2-RANGE: 0x142c9c450-0x142c9c490 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <cstdarg>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include "ms2/ms2recover.h"

typedef std::unordered_map<std::string, std::vector<char>> HiddenStringTableA;
typedef std::unordered_map<std::wstring, std::vector<wchar_t>> HiddenStringTableW;

class CHiddenStringA {
public:
    CHiddenStringA(size_t count, ...);
    const char* Get() const;
    HiddenStringTableA& Table() const;
    std::string m_text;
};

class CHiddenStringW {
public:
    CHiddenStringW(size_t count, ...);
    const wchar_t* Get() const;
    HiddenStringTableW& Table() const;
    std::wstring m_text;
};

// @0x140841580
CHiddenStringA::CHiddenStringA(size_t count, ...) {
    va_list args;
    va_start(args, count);
    std::vector<char> chars;
    for (size_t i = 0; i < count - 1; ++i)
        chars.push_back(va_arg(args, char));
    chars.push_back('\0');
    m_text = &chars[0];
    HiddenStringTableA& table = Table();
    HiddenStringTableA::const_iterator it = table.find(m_text);
    if (it == table.end())
        table.insert(std::make_pair(m_text, chars));
    va_end(args);
}

// @0x140841780
const char* CHiddenStringA::Get() const {
    return &Table()[m_text][0];
}

// @0x1408417d0
HiddenStringTableA& CHiddenStringA::Table() const {
    static HiddenStringTableA table;
    return table;
}

// @0x140841860
CHiddenStringW::CHiddenStringW(size_t count, ...) {
    va_list args;
    va_start(args, count);
    std::vector<wchar_t> chars;
    for (size_t i = 0; i < count - 1; ++i)
        chars.push_back(va_arg(args, wchar_t));
    chars.push_back(L'\0');
    m_text = &chars[0];
    HiddenStringTableW& table = Table();
    HiddenStringTableW::const_iterator it = table.find(m_text);
    if (it == table.end())
        table.insert(std::make_pair(m_text, chars));
    va_end(args);
}

// @0x140841a70
const wchar_t* CHiddenStringW::Get() const {
    return &Table()[m_text][0];
}

// @0x140841ac0
HiddenStringTableW& CHiddenStringW::Table() const {
    static HiddenStringTableW table;
    return table;
}

// @0x140841b50
bool operator==(const CStringW& text, const CHiddenStringW& hidden) {
    return text == CStringW(hidden.Get());
}

// @0x140841bb0
bool operator==(const CStringA& text, const CHiddenStringA& hidden) {
    return text == CStringA(hidden.Get());
}
