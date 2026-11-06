// asobj.h - PLACEHOLDER for ASObj and ASArray. NOT an original header.
// ASObj: an AS object created on the C++ side (AScript itself with type 2; ctor 0x1422ba6e0, dtor 0x1422ba860), 0x40 bytes.
// ASArray: the AS array derived from it (ctor 0x1422bbb50, dtor 0x1422bbc30; gfxui/asarray.cpp). The Set helpers are COMDAT
// template instances (one per value type). Units must include this header instead of redefining the classes.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

// ASObj is AScript itself: the exe has no ASObj class (RTTI ASArray : AScript : CPtred), and the "ASObj" ctors/dtor
// are AScript's (0x1422ba6e0 / 0x1422ba780 / 0x1422ba860). Its setter members now live in AScript (ascript.h).
typedef AScript ASObj;
MS2_CHECK_SIZE(ASObj, 0x40);

class ASArray : public ASObj
{
public:
    ASArray(int nMovieId);                                               // 0x1422bbb50 a new empty AS array
    ASArray(const Scaleform::GFx::Value& v, int nMovieId);               // 0x1422bbbe0 (wraps an existing AS array value)
    ASArray(const ASArray& o);                                           // 0x140bbf770 (copy; passed by value to Invoke(.., int, AScript, ASArray))
    virtual ~ASArray();                                                  // 0x1422bbc30
    // push(x): the new length (gfxui/asarray.cpp)
    unsigned int PushInt(int n);                                   // push an int
    unsigned int PushBool(bool b);                                  // push a bool
    unsigned int PushUInt(unsigned int n);                          // push a UInt
    unsigned int FUN_1422bbdb0(unsigned long n);                         // push a UInt (unsigned long)
    unsigned int PushFloat(float f);                                 // push a Number
    unsigned int PushDouble(double d);                                // push a Number
    unsigned int PushObj(const ASObj& obj);                        // push an AS object
    unsigned int PushString(const char* sz);                          // push a string (uimainplayerinfo empty slot names)
    unsigned int PushWString(const wchar_t* sz);                       // push a wide string
    int PushValue(Scaleform::GFx::Value v);                          // push a value (Value::PushBack as an int; v by value)
    // unshift(x): the new length
    unsigned int UnshiftInt(int n);
    unsigned int UnshiftBool(bool b);
    unsigned int UnshiftUInt(unsigned int n);
    unsigned int UnshiftULong(unsigned long n);
    unsigned int UnshiftFloat(float f);
    unsigned int UnshiftDouble(double d);
    unsigned int UnshiftObj(const ASObj& obj);
    unsigned int UnshiftString(const char* sz);
    unsigned int UnshiftWString(const wchar_t* sz);
    unsigned int UnshiftValue(Scaleform::GFx::Value v);                 // (v by value: destroyed here)
    Scaleform::GFx::Value Pop();                               // pop()
    Scaleform::GFx::Value Shift();                               // shift()
    unsigned int GetLength();                                        // element count ("length")
    void FUN_1422bc630();                                                // remove every element (Value::ClearElements)
    void Splice(unsigned nIndex, int nCount);                    // splice(index, count) (asdropdownmenu.cpp: remove a row)
    Scaleform::GFx::Value GetElement(unsigned nIndex);                // the element at an index (merat market buy rows)
    void SetElementIfInRange(unsigned nIndex, const Scaleform::GFx::Value& v);   // set an element if the index is in range (uiclosetdialog.cpp)
    // the element at an index, converted
    void GetInt(unsigned nIndex, int& nOut);
    void GetBool(unsigned nIndex, bool& bOut);
    void GetUInt(unsigned nIndex, unsigned& nOut);                // (astilelist.cpp)
    void GetULong(unsigned nIndex, unsigned long& nOut);
    void GetFloat(unsigned nIndex, float& fOut);
    void GetDouble(unsigned nIndex, double& dOut);
    void FUN_1422bca20(unsigned nIndex, CString& strOut);
    void GetWString(unsigned nIndex, CStringW& strOut);
    // AScript::Invoke overloads called here (members of ASArray so AScript's overload set stays unchanged)
    Scaleform::GFx::Value FUN_140e06cc0(const char* szMethod, double a1);              // 0x140e06cc0 Invoke(method, Number)
    Scaleform::GFx::Value FUN_140cbe3a0(const char* szMethod, const wchar_t* a1);      // 0x140cbe3a0 Invoke(method, wide string)
    Scaleform::GFx::Value FUN_1422bcb00(const char* szMethod, int a1, unsigned int a2);   // 0x1422bcb00 Invoke(method, Int, UInt) (inline COMDAT, defined in asarray.cpp)
};

// ASDataProvider: an ASArray with its own vftable (RTTI ASDataProvider : ASArray : AScript : CPtred), same 0x40 layout.
// vftable 0x142defc98 (slot 0 = the scalar deleting dtor 0x140bc0740 -> FUN_1422df070, shared with the trivial Unk_*Array
// subclasses), ctor 0x140bbf7b0. Handed to the AS data-provider properties of list components. Wraps a CLIK
// scaleform.clik.data.DataProvider; its own code is ?\asdataprovider.cpp (0x1422deec0-0x1422df570).
class ASDataProvider : public ASArray
{
public:
    ASDataProvider(int nMovieId);                                        // 0x1422deec0 a new empty DataProvider
    ASDataProvider(MS2Ptr<ASArray> spArr, int nMovieId);                // 0x1422def60 a DataProvider over spArr (by value: destroyed here)
    ASDataProvider(Scaleform::GFx::Value& v, int nMovieId);              // 0x1422df020 wraps an existing DataProvider value
    ASDataProvider(const ASArray& arr);                                  // 0x140bbf7b0 (copies the array; invenslot slot names)
    virtual ~ASDataProvider();                                           // 0x1422df070
    void FUN_1422df0a0();                                                // cleanUp()
    void FUN_1422df0e0(unsigned int nIndex);                             // invalidate(index)
    void FUN_1422df120();                                                // remove every element: cleanUp() (asdropdownmenu.cpp)
    AScript FUN_1422df140(unsigned nIndex);                              // requestItemAt(index) as an AS object (asdropdownmenu.cpp)
    void FUN_140f1fd70(unsigned nIndex, const CString& strMember, __int64* pOut);   // 0x140f1fd70 a member of an entry (inline COMDAT, defined in uiblackmarketpagemeso.cpp)
    // The flash.events.IEventDispatcher methods (the same AS calls as ASEventDispatcher's).
    void FUN_1422df1c0(const CString& strType, const Scaleform::GFx::Value& listener, int bUseCapture, int nPriority,
                       int bUseWeakReference);                           // addEventListener
    void FUN_1422df2e0(const CString& strType, const Scaleform::GFx::Value& listener, int bUseCapture);   // removeEventListener
    int FUN_1422df3c0(const CString& strType);                           // hasEventListener
    int FUN_1422df460(const CString& strType);                           // willTrigger
    int FUN_1422df500(const class ASEvent& ev);                          // dispatchEvent
};
MS2_CHECK_SIZE(ASDataProvider, 0x40);
