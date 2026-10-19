// asobj.h - PLACEHOLDER for ASObj and ASArray. NOT an original header.
// ASObj: an AS object created on the C++ side (AScript itself with type 2; ctor 0x1422ba6e0, dtor 0x1422ba860), 0x40 bytes.
// ASArray: the AS array derived from it (ctor 0x1422bbb50, dtor 0x1422bbc30). The Set helpers are COMDAT template
// instances (one per value type). Units must include this header instead of redefining the classes.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class ASObj : public AScript
{
public:
    ASObj(int nType);
    ASObj(const Scaleform::GFx::Value& v, int nMovieId);                 // 0x1422ba780 (ASTooltip(Value))
    ASObj(Scaleform::GFx::Value& v, int nMovieId);                       // 0x1422ba7f0 (same body; the merat market products)
    virtual ~ASObj();
    void FUN_1407cbbe0(const char* szName, bool b);                      // set a bool member
    void FUN_1407cba60(const char* szName, CString str);                 // set a string member
    void FUN_1407cbb20(const char* szName, CStringW str);                // set a wide string member
    void FUN_1407cb9c0(const char* szName, int n);                       // set an int member
    void FUN_1409c0d20(const char* szName, unsigned int n);              // set an unsigned member
    void FUN_1409c0dc0(const char* szName, const char* szValue);         // set a string member from a char*
    void FUN_1409c0e60(const char* szName, const wchar_t* szValue);      // set a string member from a wchar_t*
    void FUN_1409c1180(const char* szName, __int64 n);                   // set a 64-bit member
    void FUN_1409c48f0(const char* szName, short n);                     // set a short member
    void FUN_1409adbe0(const char* szName, Scaleform::GFx::Value v);     // set a member to a value
    void FUN_140ef0000(const char* szName, int n);                       // same (uiugccubepalettedialog.cpp copy)
    void FUN_140ef00a0(const char* szName, int n);                       // same (second copy)
    void FUN_140f8f970(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, uipartysearchdialog.cpp)
    void FUN_140f8fa10(const char* szName, unsigned int n);              // same, unsigned
    void FUN_1409c4a30(const char* szName, float f);                     // set a float member (UIRimLightDialog)
    void FUN_140e06d60(const char* szName, double d);                    // set a double member (UIRimLightDialog)
    void FUN_1409adc90(const char* szName, int n);                       // set an int member (item rank; UISnowmanEventDialog)
    void FUN_140f43b40(const char* szName, int n);                       // set an int member (fishing medal; UIRewardNotify)
    void FUN_1409eb310(const char* szName, int n);                       // set an int member via ASData (astooltip.cpp)
    void FUN_1409eb3b0(const char* szName, long n);                      // set a long member via ASData (astooltip.cpp)
    void FUN_1409eb270(const char* szName, const ASObj& obj);            // set a member to another AS object
    void FUN_1409eb1d0(const char* szName, const class ASArray& arr);    // set a member to an AS array (UITalkCinematic components)
    void FUN_140c16160(const char* szName, ASArray arr);                 // set a member to an AS array (arr by value: the callee destroys it; uiitemextractionscrolldialog)
    void FUN_140e846b0(const char* szName, size_t n);                    // set a size_t member (a Set<unsigned __int64> COMDAT, in uirpseventdialog's range)
    void FUN_140e35d00(const char* szName, int n);                       // set an int member (inline COMDAT, uigamerankingdialog.cpp)
    void FUN_140e35da0(const char* szName, int n);                       // same body, a second instance (uigamerankingdialog.cpp)
    void FUN_140c1f8b0(const char* szName, int n);                       // set an int member (hide and seek result rows)
    void FUN_140bd0d90(const char* szName, int n);                       // set an int member (job code, uimainplayerinfo)
    void FUN_140c0e050(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, uidungeoncategory.cpp)
    void FUN_140c43830(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, uiitemgachaboxdialog.cpp)
    void FUN_141aafcd0(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, uiquesteventlistener.cpp)
    void FUN_1409c4990(const char* szName, unsigned long n);             // set a colour member (uiavatarbase.cpp)
    void FUN_140cfd0d0(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, gameoptionlanguage.cpp)
    void FUN_140cfd170(const char* szName, int n);                       // same body, a second instance
    void FUN_140f3f020(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, uienchantscrolldialog.cpp)
    void FUN_140fbd930(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, uivipgoodsshopdialog.cpp)
    void FUN_141a65c70(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, uinpccontroldialog.cpp)
    void FUN_140fe95a0(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, uiweddingpage.cpp)
    void FUN_1412d4860(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, uiitemoptioncreatedialog.cpp)
    void FUN_1412d4900(const char* szName, int n);                       // same, a second instance
    void FUN_1412d49a0(const char* szName, int n);                       // same, a third instance
    void FUN_140ec3230(const char* szName, int n);                       // set an int member via ASData (inline COMDAT, uimeratmarketcommon.cpp)
};
MS2_CHECK_SIZE(ASObj, 0x40);

class ASArray : public ASObj
{
public:
    ASArray(int nType);
    ASArray(const Scaleform::GFx::Value& v, int nMovieId);               // 0x1422bbbe0 (wraps an existing AS array value)
    ASArray(const ASArray& o);                                           // 0x140bbf770 (copy; passed by value to Invoke(.., int, AScript, ASArray))
    virtual ~ASArray();
    bool FUN_1422bc050(Scaleform::GFx::Value v);                         // push
    void FUN_1422bbf70(const char* sz);                                  // push a string (uimainplayerinfo empty slot names)
    void FUN_1422bbfe0(const wchar_t* sz);                               // push a wide string
    void FUN_1422bbf00(const ASObj& obj);                                // push an AS object
    void FUN_1422bbcd0(bool b);                                          // push a bool
    void FUN_1422bbc60(int n);                                           // push an int
    unsigned int FUN_1422bc5d0();                                        // element count
};

// ASDataProvider: an ASArray with its own vftable (RTTI ASDataProvider : ASArray : AScript : CPtred), same 0x40 layout.
// vftable 0x142defc98 (slot 0 = the scalar deleting dtor 0x140bc0740 -> FUN_1422df070, shared with the trivial Unk_*Array
// subclasses), ctor 0x140bbf7b0. Handed to the AS data-provider properties of list components.
class ASDataProvider : public ASArray
{
public:
    ASDataProvider(int nType);
    virtual ~ASDataProvider();
};
MS2_CHECK_SIZE(ASDataProvider, 0x40);
