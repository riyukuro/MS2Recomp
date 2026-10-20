// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A 3-byte RGB colour (the field light colours of fieldproperty.cpp):
// constructors, conversion to/from a 0..1 float colour, stream read/write, and parsing "r,g,b" from a CStringA / CStringW through a
// tokenizer into a std::vector<unsigned char>. Follows ms2filestring.cpp in the exe; file, class and helper names are invented.
// MS2-UNIT: unit_1406c3700
// MS2-RANGE: 0x1406c3700-0x1406c4730 .text$mn   (0x1406c4730/0x1406c4760 are CMsTime ctors: commonfiles/mstime.cpp)
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <stdlib.h>
#include <vector>
#include "hook/ms2hook.h"

class CInputStream;
class COutputStream;
CInputStream& FUN_14070f340(CInputStream& in, unsigned char& value);       // operator>>(unsigned char&)
COutputStream& FUN_14070f860(COutputStream& out, unsigned char value);      // operator<<(unsigned char)

// The 0..1 float colour (unit-local; fieldproperty.h and lighteffectparam.cpp overlay the same type).
struct Unk_Vec3f
{
    Unk_Vec3f(float x, float y, float z);
    float x, y, z;
};

class Unk_Rgb3b
{
public:
    Unk_Rgb3b();
    Unk_Rgb3b(unsigned char r, unsigned char g, unsigned char b);
    Unk_Vec3f ToColor() const;
    void SetColor(const Unk_Vec3f& kColor);

    unsigned char m_r;
    unsigned char m_g;
    unsigned char m_b;
};

// @0x1406c3700
Unk_Rgb3b::Unk_Rgb3b()
{
    m_r = 0;
    m_g = 0;
    m_b = 0;
}

// @0x1406c3730
Unk_Rgb3b::Unk_Rgb3b(unsigned char r, unsigned char g, unsigned char b)
{
    m_r = r;
    m_g = g;
    m_b = b;
}

// @0x1406c3780
Unk_Vec3f Unk_Rgb3b::ToColor() const
{
    return Unk_Vec3f(m_r / 255.0f, m_g / 255.0f, m_b / 255.0f);
}
MS2_REPLACE_METHOD(0x1406C3780, Unk_Rgb3b, ToColor, 117, 0xF778C2AC);

// @0x1406c3800
void Unk_Rgb3b::SetColor(const Unk_Vec3f& kColor)
{
    m_r = (unsigned char)(int)kColor.x;
    m_g = (unsigned char)(int)kColor.y;
    m_b = (unsigned char)(int)kColor.z;
}
MS2_REPLACE_METHOD(0x1406C3800, Unk_Rgb3b, SetColor, 63, 0x018959BA);

// @0x1406c3850
CInputStream& operator>>(CInputStream& in, Unk_Rgb3b& kColor)
{
    FUN_14070f340(in, kColor.m_r);
    FUN_14070f340(in, kColor.m_g);
    FUN_14070f340(in, kColor.m_b);
    return in;
}

// @0x1406c38b0
COutputStream& operator<<(COutputStream& out, const Unk_Rgb3b& kColor)
{
    FUN_14070f860(out, kColor.m_r);
    FUN_14070f860(out, kColor.m_g);
    FUN_14070f860(out, kColor.m_b);
    return out;
}

// ---- string parsing --------------------------------------------------------------------------------------------------------

template <class T> T Unk_StrToNum(const CStringA& str);
template <class T> T Unk_StrToNum(const CStringW& str);
template <> unsigned char Unk_StrToNum<unsigned char>(const CStringA& str) { return (unsigned char)atoi(str); }
template <> unsigned char Unk_StrToNum<unsigned char>(const CStringW& str) { return (unsigned char)_wtoi(str); }

// Splits str at any of szTokens and appends every piece converted to T.
template <class T, class S>
void Unk_Tokenize(const S& str, std::vector<T>& out, const typename S::XCHAR* szTokens)
{
    int nPos = 0;
    S strToken = str.Tokenize(szTokens, nPos);
    while (!strToken.IsEmpty())
    {
        out.push_back(Unk_StrToNum<T>(strToken));
        strToken = str.Tokenize(szTokens, nPos);
    }
}

// "r,g,b" -> colour (black unless exactly three numbers).
// @0x1406c3910
Unk_Rgb3b FUN_1406c3910(const CStringA& str)
{
    std::vector<unsigned char> v;
    Unk_Tokenize(str, v, ",");
    if (v.size() != 3)
        return Unk_Rgb3b();
    return Unk_Rgb3b(v[0], v[1], v[2]);
}
MS2_REPLACE(0x1406C3910, FUN_1406c3910, 204, 0xA467262C);

// @0x1406c39f0
Unk_Rgb3b FUN_1406c39f0(const CStringW& str)
{
    std::vector<unsigned char> v;
    Unk_Tokenize(str, v, L",");
    if (v.size() != 3)
        return Unk_Rgb3b();
    return Unk_Rgb3b(v[0], v[1], v[2]);
}
MS2_REPLACE(0x1406C39F0, FUN_1406c39f0, 204, 0x939BB305);

// @0x1406c4340
Unk_Vec3f::Unk_Vec3f(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
