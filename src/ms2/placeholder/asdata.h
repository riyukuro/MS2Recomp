// asdata.h - PLACEHOLDER for ASData and ASArgList, the ActionScript call argument containers. NOT an original header.
//
// ASData: RTTI .?AVASData@@, vftable 0x143109b30, base CPtred, ctor 0x1422b7f20, dtor 0x1406147b0. 0x48 bytes: an
// array of GFx values at +0x18 (ctor 0x1422b96a0: 5 pointers + an int, padded to 0x30). UIMsg (0x50) derives and adds an
// int at +0x48. The size is load-bearing: /Od orders the frame slots by size and use count, so a 0x50 ASData swaps the
// slots of the by-value MS2Ptr copies in the dialogs' vfunc_28 (RECOVERY.md section 8, "Frame slots in the wrong order").
//
// ASArgList: the argument list of AScript::Invoke (a std::vector-like first/last/end triple of GFx values, 0x18 bytes; ctor 0x1409b1e80, dtor 0x1409b1f20).
//
// Declared: the union of the FUN_ methods the units use. Units must include this header instead of redefining the classes.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/gfxvalue.h"

class AScript;

class ASData : public CPtred
{
public:
    ASData();
    virtual ~ASData();
    int FUN_1422b9620(const Scaleform::GFx::Value* pArgs, unsigned int nArgs);    // copy the arguments in
    int FUN_1422b8b10();                                                            // first argument as int
    int FUN_1422b8a10();                                                            // result code (first argument as int)
    CString FUN_1422b8d30();                                                        // first argument as a string
    CStringW FUN_1422b8f40();                                                       // first argument as a wide string
    void FUN_1422b8310(const wchar_t* sz);
    void FUN_1422b8370(size_t n);
    Scaleform::GFx::Value FUN_1422b9260();
    float FUN_1422b8c10();                                                          // next argument as float (UIRimLightDialog)
    void FUN_1422b7f70(int n);                                                      // append an int argument
    void FUN_1422b7fd0(bool b);                                                     // append a bool argument (shopcategorytable.cpp)
    void FUN_1422b8270(const AScript& obj);                                         // append an AS object argument (astooltip.cpp)
    void FUN_1422b83f0(const Scaleform::GFx::Value& v);                             // append a value argument (uimessagebox.cpp)
    bool FUN_1422b8a90();                                                           // next argument as bool (UIChaosLightDialog)
    void FUN_1422b8030(unsigned int n);                                             // append an unsigned argument (asitemslot.cpp)
    void FUN_1422b8090(unsigned long n);                                            // append an unsigned long argument (asitemslot.cpp)
    void FUN_1422b80f0(float f);                                                    // append a float argument (asitemslot.cpp)
    void FUN_1422b8160(double d);                                                   // append a number argument (notifyswfentity.cpp)
    void FUN_1422b81c0(__int64 n);                                                  // append a 64-bit argument (asitemslot.cpp)
    void FUN_1422b82b0(const char* sz);                                             // append a string argument (asitemslot.cpp)
    double FUN_1422b8ca0();                                                         // next argument as double (UIStatControlDialog)
    int FUN_1422b9360();                                                            // argument count (uiitemcreatedialog.cpp)

private:
    void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30; void* m_pad_38; void* m_pad_40;
};
MS2_CHECK_SIZE(ASData, 0x48);

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
