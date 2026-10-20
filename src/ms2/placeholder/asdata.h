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

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/gfxvalue.h"

class AScript;
class ASData;

// Value conversions of the ASData readers (free functions, asdata.cpp).
int FUN_1422b9390(const Scaleform::GFx::Value& v);
unsigned int FUN_1422b93b0(const Scaleform::GFx::Value& v);
bool FUN_1422b93d0(const Scaleform::GFx::Value& v);
float FUN_1422b93f0(const Scaleform::GFx::Value& v);
double FUN_1422b9420(const Scaleform::GFx::Value& v);
CString FUN_1422b9440(const Scaleform::GFx::Value& v);
CStringW FUN_1422b9490(const Scaleform::GFx::Value& v);
__int64 FUN_1422b9550(const Scaleform::GFx::Value& v);

class ASData : public CPtred
{
public:
    ASData();
    // ~ASData is implicit (0x1406147b0, emitted with unit_1406125d0): the exe dtor stores no vftable pointer, which
    // cl only omits in a compiler-generated destructor.
    void FUN_1422b7f70(int n);                                                      // append an int argument
    void FUN_1422b7fd0(bool b);                                                     // append a bool argument
    void FUN_1422b8030(unsigned int n);                                             // append an unsigned argument
    void FUN_1422b8090(unsigned long n);                                            // append an unsigned long argument
    void FUN_1422b80f0(float f);                                                    // append a float argument
    void FUN_1422b8160(double d);                                                   // append a number argument
    void FUN_1422b81c0(__int64 n);                                                  // append a 64-bit argument
    void FUN_1422b8230(ASData* pOther);                                             // append all arguments of another ASData
    void FUN_1422b8270(const AScript& obj);                                         // append an AS object argument
    void FUN_1422b82b0(const char* sz);                                             // append a string argument
    void FUN_1422b8310(const wchar_t* sz);                                          // append a wide string argument
    void FUN_1422b8370(size_t n);                                                   // append a size argument
    void FUN_1422b83f0(const Scaleform::GFx::Value& v);                             // append a value argument
    void FUN_1422b8420(int* pOut);                                                  // next argument as int
    void FUN_1422b84a0(bool* pOut);                                                 // next argument as bool
    void FUN_1422b8520(unsigned int* pOut);                                         // next argument as unsigned
    void FUN_1422b85a0(unsigned long* pOut);                                        // next argument as unsigned long
    void FUN_1422b8620(float* pOut);                                                // next argument as float
    void FUN_1422b86a0(double* pOut);                                               // next argument as double
    void FUN_1422b8720(__int64* pOut);                                              // next argument as __int64
    void FUN_1422b87a0(CString& strOut);                                            // next argument as a string
    void FUN_1422b8860(CStringW& strOut);                                           // next argument as a wide string
    void FUN_1422b88e0(unsigned __int64* pOut);                                     // next argument as unsigned __int64
    void FUN_1422b8990(Scaleform::GFx::Value& vOut);                                // next argument
    int FUN_1422b8a10();                                                            // next argument as int (result code)
    bool FUN_1422b8a90();                                                           // next argument as bool
    int FUN_1422b8b10();                                                            // next argument as unsigned (callers use int)
    unsigned long FUN_1422b8b90();                                                  // next argument as unsigned long
    float FUN_1422b8c10();                                                          // next argument as float
    double FUN_1422b8ca0();                                                         // next argument as double
    CString FUN_1422b8d30();                                                        // next argument as a string ("" if not a string)
    CStringW FUN_1422b8f40();                                                       // next argument as a wide string
    __int64 FUN_1422b9110();                                                        // next argument as __int64
    unsigned __int64 FUN_1422b91a0();                                               // next argument as unsigned __int64
    Scaleform::GFx::Value FUN_1422b9260();                                          // next argument
    bool FUN_1422b9330();                                                           // no arguments left
    int FUN_1422b9360();                                                            // argument count
    int FUN_1422b9580(ATL::CAtlList<Scaleform::GFx::Value>& dst);                  // append all arguments to a list (TRUE if any)
    int FUN_1422b9620(const Scaleform::GFx::Value* pArgs, unsigned int nArgs);    // replace the arguments

    ATL::CAtlList<Scaleform::GFx::Value> m_args;    // +0x18
};
MS2_CHECK_SIZE(ASData, 0x48);
MS2_CHECK_OFFSET(ASData, m_args, 0x18);

class ASArgList
{
public:
    ASArgList();
    ~ASArgList();
    void FUN_1409b2800(int nCount);                                      // resize
    Scaleform::GFx::Value* FUN_1409b1f70(int nIndex);                    // operator[]
    unsigned __int64 FUN_1409b2840();                                    // size (asevent.cpp)

private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
};
MS2_CHECK_SIZE(ASArgList, 0x18);
