// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASArray, the AS Array wrapper of the GFx UI library.
// MS2-UNIT: ?\asarray.cpp
// MS2-RANGE: 0x1422bbb50-0x1422bced0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asobj.h (Ghidra's FUN_<va> names are kept there): push / unshift for each
// value type (each returns the new length), pop / shift, length, splice and the typed element readers. The COMDAT tail
// is Value::ClearElements / RemoveElements / SetElement, the Invoke(method, Int, UInt) instance 0x1422bcb00 and the
// ASArgList element setters FUN_1422bcc70..FUN_1422bcea0 (one per argument type; the Invoke COMDATs of other units
// declare them locally).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"

#include "hook/ms2hook.h"

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);   // the movie of a movie id (ascript.cpp)

void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bcd40(Scaleform::GFx::Value* pValue, unsigned long n);
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);
void FUN_1422bcda0(Scaleform::GFx::Value* pValue, double d);
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);
void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned __int64 n);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* sz);

// @0x1422bbb50
ASArray::ASArray(int nMovieId)
    : ASObj(nMovieId)
{
    m_value.SetNull();
    if (Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId))
        pMovie->CreateArray(&m_value);
}

// @0x1422bbbe0
ASArray::ASArray(const Scaleform::GFx::Value& v, int nMovieId)
    : ASObj(v, nMovieId)
{
}

// @0x1422bbc30
ASArray::~ASArray()
{
}

// @0x1422bbc60
unsigned int ASArray::FUN_1422bbc60(int n)
{
    return FUN_1409ba030("push", n).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BBC60, ASArray, FUN_1422bbc60, 97, 0xB3F1AC1D);

// @0x1422bbcd0
unsigned int ASArray::FUN_1422bbcd0(bool b)
{
    return Invoke("push", b).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BBCD0, ASArray, FUN_1422bbcd0, 98, 0xADCFAF78);

// @0x1422bbd40
unsigned int ASArray::FUN_1422bbd40(unsigned int n)
{
    return Invoke("push", n).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BBD40, ASArray, FUN_1422bbd40, 97, 0xBC22DD0E);

// @0x1422bbdb0
unsigned int ASArray::FUN_1422bbdb0(unsigned long n)
{
    return Invoke("push", n).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BBDB0, ASArray, FUN_1422bbdb0, 97, 0x3E20F0AB);

// @0x1422bbe20
unsigned int ASArray::FUN_1422bbe20(float f)
{
    return Invoke("push", f).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BBE20, ASArray, FUN_1422bbe20, 100, 0x8AFCED16);

// @0x1422bbe90
unsigned int ASArray::FUN_1422bbe90(double d)
{
    return FUN_140e06cc0("push", d).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BBE90, ASArray, FUN_1422bbe90, 100, 0xE3E055D1);

// @0x1422bbf00
unsigned int ASArray::FUN_1422bbf00(const ASObj& obj)
{
    return Invoke("push", obj).GetUInt();
}
// (no hook: FUN_1422bbf00 is overloaded, the const AScript& form names the same exe function)

// @0x1422bbf70
unsigned int ASArray::FUN_1422bbf70(const char* sz)
{
    return FUN_140e262c0("push", sz).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BBF70, ASArray, FUN_1422bbf70, 98, 0xD9CD880C);

// @0x1422bbfe0
unsigned int ASArray::FUN_1422bbfe0(const wchar_t* sz)
{
    return FUN_140cbe3a0("push", sz).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BBFE0, ASArray, FUN_1422bbfe0, 98, 0x793E6237);

// @0x1422bc050
int ASArray::FUN_1422bc050(Scaleform::GFx::Value v)
{
    return m_value.PushBack(v);
}
MS2_REPLACE_METHOD(0x1422BC050, ASArray, FUN_1422bc050, 71, 0xE7580F3C);

// @0x1422bc0a0
unsigned int ASArray::FUN_1422bc0a0(int n)
{
    return FUN_1409ba030("unshift", n).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC0A0, ASArray, FUN_1422bc0a0, 97, 0xDCBE0863);

// @0x1422bc110
unsigned int ASArray::FUN_1422bc110(bool b)
{
    return Invoke("unshift", b).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC110, ASArray, FUN_1422bc110, 98, 0xD8A36E68);

// @0x1422bc180
unsigned int ASArray::FUN_1422bc180(unsigned int n)
{
    return Invoke("unshift", n).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC180, ASArray, FUN_1422bc180, 97, 0x9D4C2EA6);

// @0x1422bc1f0
unsigned int ASArray::FUN_1422bc1f0(unsigned long n)
{
    return Invoke("unshift", n).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC1F0, ASArray, FUN_1422bc1f0, 97, 0x834DF9FB);

// @0x1422bc260
unsigned int ASArray::FUN_1422bc260(float f)
{
    return Invoke("unshift", f).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC260, ASArray, FUN_1422bc260, 100, 0xCD0930C1);

// @0x1422bc2d0
unsigned int ASArray::FUN_1422bc2d0(double d)
{
    return FUN_140e06cc0("unshift", d).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC2D0, ASArray, FUN_1422bc2d0, 100, 0x0BB5C641);

// @0x1422bc340
unsigned int ASArray::FUN_1422bc340(const ASObj& obj)
{
    return Invoke("unshift", obj).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC340, ASArray, FUN_1422bc340, 98, 0xFE3B7A96);

// @0x1422bc3b0
unsigned int ASArray::FUN_1422bc3b0(const char* sz)
{
    return FUN_140e262c0("unshift", sz).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC3B0, ASArray, FUN_1422bc3b0, 98, 0x0D07DD93);

// @0x1422bc420
unsigned int ASArray::FUN_1422bc420(const wchar_t* sz)
{
    return FUN_140cbe3a0("unshift", sz).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC420, ASArray, FUN_1422bc420, 98, 0x78729A4F);

// @0x1422bc490
unsigned int ASArray::FUN_1422bc490(Scaleform::GFx::Value v)
{
    return Invoke("unshift", v).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC490, ASArray, FUN_1422bc490, 154, 0xAF61FE63);

// @0x1422bc530
Scaleform::GFx::Value ASArray::FUN_1422bc530()
{
    return Invoke("pop");
}
MS2_REPLACE_METHOD(0x1422BC530, ASArray, FUN_1422bc530, 65, 0x1E495DD7);

// @0x1422bc580
Scaleform::GFx::Value ASArray::FUN_1422bc580()
{
    return Invoke("shift");
}
MS2_REPLACE_METHOD(0x1422BC580, ASArray, FUN_1422bc580, 65, 0x8C1288A3);

// @0x1422bc5d0
unsigned int ASArray::FUN_1422bc5d0()
{
    return FUN_1422baa20("length").GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC5D0, ASArray, FUN_1422bc5d0, 88, 0x20D7E0A1);

// @0x1422bc630
void ASArray::FUN_1422bc630()
{
    m_value.ClearElements();
}
MS2_REPLACE_METHOD(0x1422BC630, ASArray, FUN_1422bc630, 31, 0x4690E4EF);

// @0x1422bc660
void ASArray::FUN_1422bc660(unsigned nIndex, int nCount)
{
    FUN_1422bcb00("splice", nIndex, nCount);
}
MS2_REPLACE_METHOD(0x1422BC660, ASArray, FUN_1422bc660, 68, 0xCF0D00D1);

// @0x1422bc6b0
Scaleform::GFx::Value ASArray::FUN_1422bc6b0(unsigned nIndex)
{
    Scaleform::GFx::Value v;
    m_value.GetElement(nIndex, &v);
    return v;
}
MS2_REPLACE_METHOD(0x1422BC6B0, ASArray, FUN_1422bc6b0, 119, 0x03CD6D1D);

// @0x1422bc730
void ASArray::FUN_1422bc730(unsigned nIndex, const Scaleform::GFx::Value& v)
{
    if (nIndex >= FUN_1422bc5d0())
        return;
    m_value.SetElement(nIndex, v);
}
MS2_REPLACE_METHOD(0x1422BC730, ASArray, FUN_1422bc730, 67, 0x8424C835);

// @0x1422bc780
void ASArray::FUN_1422bc780(unsigned nIndex, int& nOut)
{
    nOut = FUN_1422bc6b0(nIndex).GetInt();
}
MS2_REPLACE_METHOD(0x1422BC780, ASArray, FUN_1422bc780, 97, 0x5E64C920);

// @0x1422bc7f0
void ASArray::FUN_1422bc7f0(unsigned nIndex, bool& bOut)
{
    bOut = FUN_1422bc6b0(nIndex).GetBool();
}
MS2_REPLACE_METHOD(0x1422BC7F0, ASArray, FUN_1422bc7f0, 97, 0xB88F95C2);

// @0x1422bc860
void ASArray::FUN_1422bc860(unsigned nIndex, unsigned& nOut)
{
    nOut = FUN_1422bc6b0(nIndex).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC860, ASArray, FUN_1422bc860, 97, 0xE3196770);

// @0x1422bc8d0
void ASArray::FUN_1422bc8d0(unsigned nIndex, unsigned long& nOut)
{
    nOut = FUN_1422bc6b0(nIndex).GetUInt();
}
MS2_REPLACE_METHOD(0x1422BC8D0, ASArray, FUN_1422bc8d0, 97, 0xCBA3F049);

// @0x1422bc940
void ASArray::FUN_1422bc940(unsigned nIndex, float& fOut)
{
    fOut = (float)FUN_1422bc6b0(nIndex).GetNumber();
}
MS2_REPLACE_METHOD(0x1422BC940, ASArray, FUN_1422bc940, 103, 0xC6A60F3F);

// @0x1422bc9b0
void ASArray::FUN_1422bc9b0(unsigned nIndex, double& dOut)
{
    dOut = FUN_1422bc6b0(nIndex).GetNumber();
}
MS2_REPLACE_METHOD(0x1422BC9B0, ASArray, FUN_1422bc9b0, 99, 0x0C1851E6);

// @0x1422bca20
void ASArray::FUN_1422bca20(unsigned nIndex, CString& strOut)
{
    strOut = FUN_1422bc6b0(nIndex).GetString();
}
MS2_REPLACE_METHOD(0x1422BCA20, ASArray, FUN_1422bca20, 105, 0x891ED9C2);

// @0x1422bca90
void ASArray::FUN_1422bca90(unsigned nIndex, CStringW& strOut)
{
    strOut = FUN_1422bc6b0(nIndex).GetStringW();
}
MS2_REPLACE_METHOD(0x1422BCA90, ASArray, FUN_1422bca90, 105, 0xC726AEA7);

// @0x1422bcb00
inline Scaleform::GFx::Value ASArray::FUN_1422bcb00(const char* szMethod, int a1, unsigned int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1422bcc70
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v)
{
    *pValue = v;
}
MS2_REPLACE(0x1422BCC70, FUN_1422bcc70, 54, 0x0F9A74BE);

// @0x1422bccb0
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n)
{
    pValue->SetInt(n);
}
MS2_REPLACE_OVERLOAD(0x1422BCCB0, void(Scaleform::GFx::Value*, int), FUN_1422bccb0, 32, 0xAA2F14F4);

// @0x1422bcce0
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b)
{
    pValue->SetBoolean(b);
}
MS2_REPLACE_OVERLOAD(0x1422BCCE0, void(Scaleform::GFx::Value*, bool), FUN_1422bcce0, 33, 0x173D63A6);

// @0x1422bcd10
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n)
{
    pValue->SetUInt(n);
}
MS2_REPLACE_OVERLOAD(0x1422BCD10, void(Scaleform::GFx::Value*, unsigned int), FUN_1422bcd10, 32, 0xE7E7D5F2);

// @0x1422bcd40
void FUN_1422bcd40(Scaleform::GFx::Value* pValue, unsigned long n)
{
    pValue->SetUInt(n);
}
MS2_REPLACE_OVERLOAD(0x1422BCD40, void(Scaleform::GFx::Value*, unsigned long), FUN_1422bcd40, 32, 0x4C421DE2);

// @0x1422bcd70
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f)
{
    pValue->SetNumber(f);
}
MS2_REPLACE_OVERLOAD(0x1422BCD70, void(Scaleform::GFx::Value*, float), FUN_1422bcd70, 39, 0xB104BB12);

// @0x1422bcda0
void FUN_1422bcda0(Scaleform::GFx::Value* pValue, double d)
{
    pValue->SetNumber(d);
}
MS2_REPLACE_OVERLOAD(0x1422BCDA0, void(Scaleform::GFx::Value*, double), FUN_1422bcda0, 36, 0xFEDC44E0);

// @0x1422bcdd0
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n)
{
    pValue->SetNumber((double)n);
}
MS2_REPLACE_OVERLOAD(0x1422BCDD0, void(Scaleform::GFx::Value*, __int64), FUN_1422bcdd0, 39, 0x14CFC12F);

// @0x1422bce00
void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned __int64 n)
{
    pValue->SetNumber((double)n);
}
MS2_REPLACE_OVERLOAD(0x1422BCE00, void(Scaleform::GFx::Value*, unsigned __int64), FUN_1422bce00, 55, 0x314DC36E);

// @0x1422bce40
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj)
{
    *pValue = const_cast<AScript&>(obj).FUN_1422bb870();
}
MS2_REPLACE_OVERLOAD(0x1422BCE40, void(Scaleform::GFx::Value*, const AScript&), FUN_1422bce40, 42, 0xE1FF1C14);

// @0x1422bce70
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz)
{
    pValue->SetString(sz);
}
MS2_REPLACE_OVERLOAD(0x1422BCE70, void(Scaleform::GFx::Value*, const char*), FUN_1422bce70, 34, 0x22DC5B1A);

// @0x1422bcea0
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* sz)
{
    pValue->SetStringW(sz);
}
MS2_REPLACE_OVERLOAD(0x1422BCEA0, void(Scaleform::GFx::Value*, const wchar_t*), FUN_1422bcea0, 34, 0xE71BDEA3);
