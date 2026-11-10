// asdata.h - PLACEHOLDER for ASData and ASArgList, the ActionScript call argument containers. NOT an original header.
//
// ASData: RTTI .?AVASData@@, vftable 0x143109b30, base CPtred, ctor 0x1422b7f20, dtor 0x1406147b0. 0x48 bytes: a FIFO
// of GFx values at +0x18, an ATL::CAtlList<Value> built with block size 10 (ctor 0x1422b96a0, AddTail 0x1422b9770, RemoveHead
// 0x1422b9b30; src/ms2/gfxui/asdata.cpp). Appenders AddTail one value, readers RemoveHead the next one. UIMsg (0x50) derives and adds an
// int at +0x48. The size is load-bearing: /Od orders the frame slots by size and use count, so a 0x50 ASData swaps the
// slots of the by-value MS2Ptr copies in the dialogs' vfunc_28 (RECOVERY.md section 8, "Frame slots in the wrong order").
//
// ASArgList: the argument list of AScript::Invoke (a std::vector-like first/last/end triple of GFx values, 0x18 bytes; ctor 0x1409b1e80, dtor 0x1409b1f20).
//
// Declared: the union of the FUN_ methods the units use. Units must include this header instead of redefining the classes.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/gfxvalue.h"

class AScript;
class ASData;

// Value conversions of the ASData readers (free functions, asdata.cpp).
int ValueToInt(const Scaleform::GFx::Value& v);
unsigned int ValueToUInt(const Scaleform::GFx::Value& v);
bool ValueToBool(const Scaleform::GFx::Value& v);
float ValueToFloat(const Scaleform::GFx::Value& v);
double ValueToDouble(const Scaleform::GFx::Value& v);
CString ValueToString(const Scaleform::GFx::Value& v);
CStringW ValueToStringW(const Scaleform::GFx::Value& v);
__int64 ValueToInt64(const Scaleform::GFx::Value& v);

class ASData : public CPtred
{
public:
    ASData();
    // ~ASData is implicit (0x1406147b0, emitted with unit_1406125d0): the exe dtor stores no vftable pointer, which
    // cl only omits in a compiler-generated destructor.
    void AddInt(int n);                                                      // append an int argument
    void AddBool(bool b);                                                     // append a bool argument
    void AddUInt(unsigned int n);                                             // append an unsigned argument
    void AddULong(unsigned long n);                                            // append an unsigned long argument
    void AddFloat(float f);                                                    // append a float argument
    void AddDouble(double d);                                                   // append a number argument
    void AddInt64(__int64 n);                                                  // append a 64-bit argument
    void AddArgsFrom(ASData* pOther);                                             // append all arguments of another ASData
    void AddObj(const AScript& obj);                                         // append an AS object argument
    void AddString(const char* sz);                                             // append a string argument
    void AddWString(const wchar_t* sz);                                          // append a wide string argument
    void AddSize(size_t n);                                                   // append a size argument
    void AddValue(const Scaleform::GFx::Value& v);                             // append a value argument
    void ReadInt(int* pOut);                                                  // next argument as int
    void ReadBool(bool* pOut);                                                 // next argument as bool
    void ReadUInt(unsigned int* pOut);                                         // next argument as unsigned
    void ReadULong(unsigned long* pOut);                                        // next argument as unsigned long
    void ReadFloat(float* pOut);                                                // next argument as float
    void ReadDouble(double* pOut);                                               // next argument as double
    void ReadInt64(__int64* pOut);                                              // next argument as __int64
    void PopString(CString& strOut);                                            // next argument as a string
    void PopStringW(CStringW& strOut);                                           // next argument as a wide string
    void ReadUInt64(unsigned __int64* pOut);                                     // next argument as unsigned __int64
    void ReadValue(Scaleform::GFx::Value& vOut);                                // next argument
    int PopInt();                                                            // next argument as int (result code)
    bool PopBool();                                                           // next argument as bool
    int PopUInt();                                                            // next argument as unsigned (callers use int)
    unsigned long PopULong();                                                  // next argument as unsigned long
    float PopFloat();                                                          // next argument as float
    double PopDouble();                                                         // next argument as double
    CString FUN_1422b8d30();                                                        // next argument as a string ("" if not a string)
    CStringW FUN_1422b8f40();                                                       // next argument as a wide string
    __int64 PopInt64();                                                        // next argument as __int64
    unsigned __int64 PopUInt64();                                               // next argument as unsigned __int64
    Scaleform::GFx::Value PopValue();                                          // next argument
    bool IsEmpty();                                                           // no arguments left
    int GetArgCount();                                                            // argument count
    int AppendArgsTo(ATL::CAtlList<Scaleform::GFx::Value>& dst);                  // append all arguments to a list (TRUE if any)
    int SetArgsIfAny(const Scaleform::GFx::Value* pArgs, unsigned int nArgs);    // replace the arguments

    ATL::CAtlList<Scaleform::GFx::Value> m_args;    // +0x18
};
MS2_CHECK_SIZE(ASData, 0x48);
MS2_CHECK_OFFSET(ASData, m_args, 0x18);

// ASArgList is the exe's std::vector<GFx::Value> itself: vector() 0x1409b1e80, ~vector() 0x1409b1f20,
// resize 0x1409b2800, operator[] 0x1409b1f70.
typedef std::vector<Scaleform::GFx::Value> ASArgList;
MS2_CHECK_SIZE(ASArgList, 0x18);
