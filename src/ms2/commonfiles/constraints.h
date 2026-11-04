// Constraint type names inferred from behavior; original names were not retained.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
struct Unk_MinUtf8 { int length; bool CheckA(const CString&); };
MS2_CHECK_SIZE(Unk_MinUtf8,4);
struct Unk_NarrowLimit { int maximum; explicit Unk_NarrowLimit(int); bool Check(const CString&) const; bool Check(const CStringW&) const; };
MS2_CHECK_SIZE(Unk_NarrowLimit,4);
struct Unk_RangeUtf8 { int minLength,maxLength; Unk_RangeUtf8(int minLength,int maxLength); bool CheckA(const CString&); };
MS2_CHECK_SIZE(Unk_RangeUtf8,8);
struct Unk_MinWide { int length; bool CheckW(const CStringW&); };
MS2_CHECK_SIZE(Unk_MinWide,4);
struct Unk_WideMaximum { int maximum; explicit Unk_WideMaximum(int); bool Check(const CStringW&) const; };
MS2_CHECK_SIZE(Unk_WideMaximum,4);
struct Unk_WideRange { int minimum,maximum; Unk_WideRange(int minimum,int maximum); bool Check(const CStringW&) const; };
MS2_CHECK_SIZE(Unk_WideRange,8);
struct Unk_MinBytes { int length; bool CheckA(const CString&); };
MS2_CHECK_SIZE(Unk_MinBytes,4);
struct Unk_NarrowMaximum { int maximum; explicit Unk_NarrowMaximum(int); bool Check(const CString&) const; };
MS2_CHECK_SIZE(Unk_NarrowMaximum,4);
struct Unk_RangeBytes { int minLength,maxLength; Unk_RangeBytes(int minLength,int maxLength); bool CheckA(const CString&); };
MS2_CHECK_SIZE(Unk_RangeBytes,8);
// Coordinate record passed to 0x1402c40c0; original type name is unknown.
struct Unk_ConstraintPoint { float x,y,z; };
MS2_CHECK_SIZE(Unk_ConstraintPoint,12);
struct Unk_PositionConstraint { float loX,hiX,loY,hiY,loZ,hiZ; Unk_PositionConstraint(float,float,float,float,float,float,float); bool Check(const Unk_ConstraintPoint&); };
MS2_CHECK_SIZE(Unk_PositionConstraint,24);
struct Unk_1402c41d0 { bool Check(int); };
struct Unk_1402c4220 { bool Check(int); };
struct Unk_1402c4270 { bool Check(int); };
struct Unk_1402c42c0 { bool Check(int); };
struct Unk_1402c4310 { bool Check(int); };
struct Unk_1402c4360 { bool Check(int); };
struct Unk_1402c43a0 { bool Check(int); };
struct Unk_1402c43f0 { bool Check(unsigned char); };
struct Unk_1402c4450 { bool Check(unsigned char); };
struct Unk_1402c44b0 { bool Check(unsigned char); };
struct Unk_1402c4510 { bool Check(unsigned char); };
struct Unk_1402c4570 { bool Check(unsigned char); };
struct Unk_1402c45d0 { bool Check(unsigned char); };
struct Unk_1402c4630 { bool Check(unsigned char); };
struct Unk_1402c4690 { bool Check(unsigned char); };
struct Unk_1402c46f0 { bool Check(int); };
