// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). String length, coordinate and enum constraints.
// MS2-UNIT: commonfiles\constraints.cpp
// MS2-RANGE: 0x1402c3840-0x1402c4b00 .text$mn
// MS2-RANGE: 0x1400b5a20-0x1400b5ae0 .text$di
// MS2-RANGE: 0x142c9a5b0-0x142c9a5e0 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\constraints.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "constraints.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
static CString s_sortNames[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
CStringW FUN_14016a730(const char*,int);
bool FUN_140222590(int);
bool FUN_1402c4740(int);
bool FUN_1402c4770(int);
bool FUN_1402c47a0(int);
bool FUN_1402c47d0(int);
bool FUN_1402c4800(int);
bool FUN_1402c4830(int);
bool FUN_1402c4870(int);
bool FUN_1402c49b0(int);
bool FUN_1402c48a0(int);
bool FUN_1402c48f0(int);
// @0x1402c3840
bool Unk_MinUtf8::CheckA(const CString& value) {
    bool checkResult=false;
    CStringW wide=FUN_14016a730(value,0);
    checkResult=(wide.GetLength() >= length);
    MS2_ASSERT_AT(22,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C3840, Unk_MinUtf8, CheckA, 160, 0xE4FFA38B);
// @0x1402c38f0
Unk_NarrowLimit::Unk_NarrowLimit(int value) : maximum(value) {}
// @0x1402c3910
bool Unk_NarrowLimit::Check(const CString& value) const {
    bool checkResult=(value.GetLength() <= maximum);
    MS2_ASSERT_AT(35,checkResult);
    return checkResult;
}
// Check is overloaded, so MS2_REPLACE_METHOD (decltype(&Class::Method)) cannot name it: register through a this-first thunk.
MS2_REPLACE_IMPL(0x1402C3910, static_cast<bool (*)(const Unk_NarrowLimit*, const CString&)>([](const Unk_NarrowLimit* self, const CString& value) { return self->Check(value); }), "Unk_NarrowLimit::Check", 108, 0x1452C846);
// @0x1402c3990
bool Unk_NarrowLimit::Check(const CStringW& value) const {
    bool checkResult=(value.GetLength() <= maximum);
    MS2_ASSERT_AT(42,checkResult);
    return checkResult;
}
MS2_REPLACE_IMPL(0x1402C3990, static_cast<bool (*)(const Unk_NarrowLimit*, const CStringW&)>([](const Unk_NarrowLimit* self, const CStringW& value) { return self->Check(value); }), "Unk_NarrowLimit::Check", 108, 0x2CDC2D7F);
// @0x1402c3a10
Unk_RangeUtf8::Unk_RangeUtf8(int minLength,int maxLength) : minLength(minLength),maxLength(maxLength) { MS2_ASSERT_AT(50,minLength <= maxLength); }
// @0x1402c3a70
bool Unk_RangeUtf8::CheckA(const CString& value) {
    bool checkResult=false;
    CStringW wide=FUN_14016a730(value,0);
    checkResult=(wide.GetLength() >= minLength && wide.GetLength() <= maxLength);
    MS2_ASSERT_AT(60,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C3A70, Unk_RangeUtf8, CheckA, 181, 0xCD5BEDFF);
// @0x1402c3b50
bool Unk_MinWide::CheckW(const CStringW& value) {
    bool checkResult=false;
    checkResult=(value.GetLength() >= length);
    MS2_ASSERT_AT(77,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C3B50, Unk_MinWide, CheckW, 113, 0x2B2CF39D);
// @0x1402c3bd0
Unk_WideMaximum::Unk_WideMaximum(int value) : maximum(value) {}
// @0x1402c3bf0
bool Unk_WideMaximum::Check(const CStringW& value) const {
    bool checkResult=false;
    checkResult=(value.GetLength() <= maximum);
    MS2_ASSERT_AT(93,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C3BF0, Unk_WideMaximum, Check, 113, 0xE76DE6D2);
// @0x1402c3c70
Unk_WideRange::Unk_WideRange(int minimum,int maximum) : minimum(minimum),maximum(maximum) { MS2_ASSERT_AT(101,minimum <= maximum); }
// @0x1402c3cd0
bool Unk_WideRange::Check(const CStringW& value) const {
    bool checkResult=false;
    checkResult=(value.GetLength() >= minimum && value.GetLength() <= maximum);
    MS2_ASSERT_AT(109,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C3CD0, Unk_WideRange, Check, 134, 0x03C2B948);
// @0x1402c3d80
bool Unk_MinBytes::CheckA(const CString& value) {
    bool checkResult=false;
    checkResult=(value.GetLength() >= length);
    MS2_ASSERT_AT(126,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C3D80, Unk_MinBytes, CheckA, 113, 0x179C086D);
// @0x1402c3e00
Unk_NarrowMaximum::Unk_NarrowMaximum(int value) : maximum(value) {}
// @0x1402c3e20
bool Unk_NarrowMaximum::Check(const CString& value) const {
    bool checkResult=false;
    checkResult=(value.GetLength() <= maximum);
    MS2_ASSERT_AT(142,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C3E20, Unk_NarrowMaximum, Check, 113, 0xB1AE1D8D);
// @0x1402c3ea0
Unk_RangeBytes::Unk_RangeBytes(int minLength,int maxLength) : minLength(minLength),maxLength(maxLength) { MS2_ASSERT_AT(150,minLength <= maxLength); }
// @0x1402c3f00
bool Unk_RangeBytes::CheckA(const CString& value) {
    bool checkResult=false;
    checkResult=(value.GetLength() >= minLength && value.GetLength() <= maxLength);
    MS2_ASSERT_AT(158,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C3F00, Unk_RangeBytes, CheckA, 134, 0xE23B577C);
// @0x1402c3f90
Unk_PositionConstraint::Unk_PositionConstraint(float minX,float maxX,float minY,float maxY,float minZ,float maxZ,float epsilon)
    : loX(minX-epsilon),hiX(maxX+epsilon),loY(minY-epsilon),hiY(maxY+epsilon),loZ(minZ-epsilon),hiZ(maxZ+epsilon) {
    MS2_ASSERT_AT(171,minX <= maxX); MS2_ASSERT_AT(172,minY <= maxY); MS2_ASSERT_AT(173,minZ <= maxZ);
}
// @0x1402c40c0
bool Unk_PositionConstraint::Check(const Unk_ConstraintPoint& p) {
    if(loX>p.x || hiX<p.x) { MS2_ASSERT_AT(182,FALSE);return 0; }
    if(loY>p.y || hiY<p.y) { MS2_ASSERT_AT(188,FALSE);return 0; }
    if(loZ>p.z || hiZ<p.z) { MS2_ASSERT_AT(194,FALSE);return 0; }
    return 1;
}
MS2_REPLACE_METHOD(0x1402C40C0, Unk_PositionConstraint, Check, 261, 0xFE1305B4);
// @0x1402c41d0
bool Unk_1402c41d0::Check(int value) {
    bool checkResult=FUN_1402c48f0(value);
    MS2_ASSERT_AT(233,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C41D0, Unk_1402c41d0, Check, 73, 0xB3D981B2);
// @0x1402c4220
bool Unk_1402c4220::Check(int value) {
    bool checkResult=FUN_140222590(value);
    MS2_ASSERT_AT(242,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C4220, Unk_1402c4220, Check, 73, 0xD2633F72);
// @0x1402c4270
bool Unk_1402c4270::Check(int value) {
    bool checkResult=false;
    checkResult=true;
    MS2_ASSERT_AT(259,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C4270, Unk_1402c4270, Check, 70, 0x873C3B67);
// @0x1402c42c0
bool Unk_1402c42c0::Check(int value) {
    bool checkResult=false;
    checkResult=true;
    MS2_ASSERT_AT(276,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C42C0, Unk_1402c42c0, Check, 70, 0xE9605200);
// @0x1402c4310
bool Unk_1402c4310::Check(int value) {
    bool checkResult=false;
    checkResult=true;
    MS2_ASSERT_AT(293,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C4310, Unk_1402c4310, Check, 70, 0x24758E4E);
// @0x1402c4360
bool Unk_1402c4360::Check(int value) {
    if(value==0) return true;
    return Unk_1402c4310().Check(value);
}
MS2_REPLACE_METHOD(0x1402C4360, Unk_1402c4360, Check, 43, 0xAE197EB3);
// @0x1402c43a0
bool Unk_1402c43a0::Check(int value) {
    bool checkResult=false;
    checkResult=true;
    MS2_ASSERT_AT(320,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C43A0, Unk_1402c43a0, Check, 70, 0xF1262B87);
// @0x1402c43f0
bool Unk_1402c43f0::Check(unsigned char value) {
    bool checkResult=FUN_1402c49b0(value);
    MS2_ASSERT_AT(329,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C43F0, Unk_1402c43f0, Check, 76, 0x3AE8736E);
// @0x1402c4450
bool Unk_1402c4450::Check(unsigned char value) {
    bool checkResult=FUN_1402c4800(value);
    MS2_ASSERT_AT(338,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C4450, Unk_1402c4450, Check, 76, 0xF4F896D3);
// @0x1402c44b0
bool Unk_1402c44b0::Check(unsigned char value) {
    bool checkResult=FUN_1402c4830(value);
    MS2_ASSERT_AT(347,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C44B0, Unk_1402c44b0, Check, 76, 0xF95556E3);
// @0x1402c4510
bool Unk_1402c4510::Check(unsigned char value) {
    bool checkResult=FUN_1402c47a0(value);
    MS2_ASSERT_AT(356,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C4510, Unk_1402c4510, Check, 76, 0x3F0AC389);
// @0x1402c4570
bool Unk_1402c4570::Check(unsigned char value) {
    bool checkResult=FUN_1402c47d0(value);
    MS2_ASSERT_AT(365,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C4570, Unk_1402c4570, Check, 76, 0x7C73731E);
// @0x1402c45d0
bool Unk_1402c45d0::Check(unsigned char value) {
    bool checkResult=FUN_1402c48a0(value);
    MS2_ASSERT_AT(374,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C45D0, Unk_1402c45d0, Check, 76, 0xCCB32664);
// @0x1402c4630
bool Unk_1402c4630::Check(unsigned char value) {
    bool checkResult=FUN_1402c4740(value);
    MS2_ASSERT_AT(383,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C4630, Unk_1402c4630, Check, 76, 0x9C042E72);
// @0x1402c4690
bool Unk_1402c4690::Check(unsigned char value) {
    bool checkResult=FUN_1402c4770(value);
    MS2_ASSERT_AT(392,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C4690, Unk_1402c4690, Check, 76, 0x5FF4A063);
// @0x1402c46f0
bool Unk_1402c46f0::Check(int value) {
    bool checkResult=FUN_1402c4870(value);
    MS2_ASSERT_AT(401,checkResult);
    return checkResult;
}
MS2_REPLACE_METHOD(0x1402C46F0, Unk_1402c46f0, Check, 73, 0x3CA98159);
// @0x1402c4740
bool FUN_1402c4740(int value) { return value>=0 && value<6; }
MS2_REPLACE(0x1402C4740, FUN_1402c4740, 47, 0x281EAF55);
// @0x1402c4770
bool FUN_1402c4770(int value) { return value>=0 && value<3; }
MS2_REPLACE(0x1402C4770, FUN_1402c4770, 47, 0x17B6DFAC);
// @0x1402c47a0
bool FUN_1402c47a0(int value) { return value>=0 && value<3; }
MS2_REPLACE(0x1402C47A0, FUN_1402c47a0, 47, 0x17B6DFAC);
// @0x1402c47d0
bool FUN_1402c47d0(int value) { return value>=0 && value<3; }
MS2_REPLACE(0x1402C47D0, FUN_1402c47d0, 47, 0x17B6DFAC);
// @0x1402c4800
bool FUN_1402c4800(int value) { return value>=0 && value<72; }
MS2_REPLACE(0x1402C4800, FUN_1402c4800, 47, 0x58DB69BF);
// @0x1402c4830
bool FUN_1402c4830(int value) { return value>=0 && value<179; }
MS2_REPLACE(0x1402C4830, FUN_1402c4830, 50, 0xA0A87AD5);
// @0x1402c4870
bool FUN_1402c4870(int value) { return value>=0 && value<5; }
MS2_REPLACE(0x1402C4870, FUN_1402c4870, 47, 0xFFDC6976);
// @0x1402c48a0
bool FUN_1402c48a0(int value) { switch(value) { case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 201: case 202: case 209: return true; default: return false; } }
MS2_REPLACE(0x1402C48A0, FUN_1402c48a0, 67, 0xE85CE18D);
// @0x1402c48f0
bool FUN_1402c48f0(int value) { switch(value) {
case 1:
case 10:
case 20:
case 30:
case 40:
case 50:
case 60:
case 70:
case 80:
case 90:
case 100:
case 110:
return true;
default:return false;
} }
MS2_REPLACE(0x1402C48F0, FUN_1402c48f0, 71, 0x141B1D98);
// @0x1402c49b0
bool FUN_1402c49b0(int value) { return value>=0 && value<51; }
MS2_REPLACE(0x1402C49B0, FUN_1402c49b0, 47, 0x384326BC);
MS2_EMIT_CRT_MEMMOVE_S();
