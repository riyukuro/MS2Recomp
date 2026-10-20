// ascript.h - PLACEHOLDER for AScript (RTTI .?AVAScript@@, 64 bytes, base CPtred, vftable 0x142db7e28) and the
// game's 16-byte smart pointer template. NOT an original header.
//
// AScript wraps an ActionScript object (Scaleform::GFx::Value at +0x20). Its Invoke helpers call an AS method by
// name and return the GFx result by value (callers destroy it at once). Only the overloads that recovered code
// calls are declared; the originals are probably variadic templates (one COMDAT per argument list), so each
// declared overload stands for one instantiation.
//
// MS2Ptr<T>: 16 bytes, the pointer at +0x08 (+0x00 unknown, probably a vftable or the owner). Its members are
// COMDAT instantiations per T (e.g. T = AScript: get 0x1409ee240, operator-> 0x1409ee290); the real template name
// is unknown. Declared without bodies: callers' bytes do not depend on them and the copies live in other units.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/gfxvalue.h"

template <class T> class MS2Ptr;
struct Unk_BmNewTag;                   // the new-object tag (0x1401b7b90; blackmarketitemoption.h)

template <class T>
class MS2Ptr
{
    template <class U> friend class MS2Ptr;
    friend struct Unk_TePtrAccess;      // taileffectobject.cpp: ResetNew on the tail info list element

public:
    MS2Ptr();
    MS2Ptr(decltype(nullptr)) { m_p = 0; } // fielddata: distinct nullptr overload
    MS2Ptr(int nNull);                  // `MS2Ptr<T> p(0)`: m_p = NULL (0x140c74e10 for T = AScript)
    // `MS2Ptr<T> p(Unk_BmNewTag(0))`: m_p = NULL, then a fresh pooled T (explicit specializations only, e.g.
    // worldmapmanager.cpp: 0x141bacbb0 for T = UIWorldMap::MapTile)
    explicit MS2Ptr(const Unk_BmNewTag& tag);
    MS2Ptr(T* p);                       // m_p = p; AddRef() (0x140f9c100 for T = UISwfEntity)
    MS2Ptr(const MS2Ptr& o);            // 0x1409b9940 for T = AScript
    // Converting copy (U derives from T): m_p = o.m_p; AddRef() (0x1405ace70 for T = CGemDataBase, U = CGemTombStoneData).
    template <class U> MS2Ptr(const MS2Ptr<U>& o) { m_p = o.m_p; AddRef(); }
    ~MS2Ptr();                          // 0x1409b9a00 for T = AScript
    // Converting assignment (U derives from T). Inline: its COMDAT is in the first unit that assigns (0x1422dca80 for
    // T = AScript, U = ASDisplayObject, in uiswfentity.cpp).
    template <class U> MS2Ptr& operator=(const MS2Ptr<U>& o)
    {
        o.AddRef();
        Release();
        m_p = o.m_p;
        return *this;
    }
    MS2Ptr& operator=(int nNull);       // `p = NULL` (int parameter: the callee homes edx as a dword)
    T* get() const;                     // tested for null: `if (p)` is written `if (p.get())` (0x1409ee240 for AScript)
    operator T*() const;                // `if (MS2Ptr<T> p = ...)`, `dynamic_cast<X*>((T*)p)` (AScript: 0x140ba7c60)
    T* operator->() const;
    MS2Ptr& operator=(const MS2Ptr& o); // 0x1409b9ad0 for AScript (mentoring reward page)
    T& operator*() const;              // 0x140c353d0 for AScript
    bool IsNull() const;                // `p.get() == 0` as a bool
    bool operator==(T* p) const;
    // `MS2Ptr tmp(p); swap(m_p, tmp.m_p);` - assignment from a raw pointer (0x140a4fd30 for T = CStateManager).
    // A named member, not operator=(T*), so that existing `p = q` / `p = 0` call sites keep their overloads.
    MS2Ptr& AssignRaw(T* p);
    // Drops the reference (`it->Reset()` on the camera effect list element; 0x140af7ba0 for
    // T = CCameraEffect, camera.cpp). Real name unknown.
    void Reset() { Release(); }

private:
    void AddRef() const;                // if (m_p) <add a reference> (0x140d03270 for T = ASDisplayObject)
    void Release();                     // if (m_p) { <drop the reference>; m_p = NULL; } (0x1409b9e00 for T = AScript)
    void ReleaseImpl(void*);            // explicit specializations only (Unk_DropEntry, uiitemdropinfodialog.cpp)
    static void Reference(T*);
public:
    bool operator!() const { return m_p == 0; }             // `m_p == 0` (w3o1: generic bodies of all members in ms2ptr_impl.h)
    MS2Ptr(MS2Ptr&& o) { m_p = o.m_p; o.m_p = 0; }   // merge3: inline (the out-of-line ms2ptr_impl.h body was unresolved in units that do not include it); a3: move at 140e08d80 / 141633bb0 transfers +8 and clears the source
#ifdef MS2_PTR_MOVE_CONVERT
    // Converting move (U derives from T): m_p = o.m_p; o.m_p = NULL (0x14100f980 for T = ASDisplayObject, U = Unk_140acd6e0;
    // opt-in per unit: the other units keep the converting copy)
    template <class U> MS2Ptr(MS2Ptr<U>&& o) { m_p = o.m_p; o.m_p = 0; }
#endif
private:
    void AddRefImpl(void*) const;       // Reference(m_p) (rdx homed as a pointer)

    void* m_unk_00;
    T* m_p;                             // +0x08
};

class ASMovieClip;
class ASTextField;
class ASArray;
class ASArgList;                        // the argument list of the Invoke back end (defined by the units using it)

enum Unk_UgcOpenType : int;             // the upload kind of the UGC image upload dialog (uiugcimageuploaddialog.h)

class AScript : public CPtred
{
public:
    AScript(const Scaleform::GFx::Value& v, int nMovieId);                                   // 0x1422ba780 (ASCommonDepth)
    AScript(int nMovieId);                                                                   // 0x1422ba6e0 creates a fresh AS object (asequipicon.cpp)
    AScript(Scaleform::GFx::Value& v, int nMovieId);                                         // 0x1422ba7f0 same body as the const& form (asequipicon.cpp)
    Scaleform::GFx::Value FUN_1422baa20(const char* szMember);                               // child member by name
    void FUN_1422baad0(const char* szMember, CStringW& strOut);                             // read a string member (merat market products)
    bool FUN_1422ba9a0();                                                                    // value is undefined
    Scaleform::GFx::Value& FUN_1422bb870();                                                  // m_value
    Scaleform::GFx::Value Invoke(const char* szMethod);                                     // 0x1422bb330
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2);                      // 0x140acd070
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, int a3, CStringW a4, int a5);   // 0x140f24720 (inline COMDAT, defined in uibluemarblegamedialog.cpp; a4 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CStringW a2, int a3, int a4);      // 0x140f24850 (inline COMDAT, defined in uibluemarblegamedialog.cpp; a1/a2 by value)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, float a2, CStringW a3);            // 0x14100fe60 (inline COMDAT, defined in uiplayinstrumentdialog.cpp; a1/a3 by value)
    template <class T> MS2Ptr<T> FUN_140be2480(const CString&, MS2Ptr<T>&);                            // bind tab bar (UIPlayInstrumentDialog)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, int a3);              // 0x140f24650 (not in the unit that owns it yet; added by uihsldialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, bool a1, int a2);                     // 0x14184af30 (inline COMDAT, defined in textureanimationdata.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, CString a1);                          // 0x1409b46e0
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CStringW a2);            // 0x140e78470
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CString a2);             // 0x1412cc450 (inline COMDAT, defined in uiindividualpvpdialog.cpp; both by value)
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1);            // 0x1409b13b0 (a1 by value: callee destroys)
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1, int a2);   // 0x1409b1490 (ascommondepth.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, CString a1, bool a2, Scaleform::GFx::Value a3, Scaleform::GFx::Value a4);   // 0x14131cc10 (inline COMDAT, defined in uimeratmarketregisterdialog.cpp; all by value)
    void FUN_1422bac00(const char* szMember, CString& strOut);                               // read a narrow string member (uimeratmarketregisterdialog.cpp)
    Scaleform::GFx::Value FUN_140e5bf20(const char* szMethod, float a1, float a2);          // 0x140e5bf20 (inline COMDAT, defined in uimasteryobjectmark.cpp)
    Scaleform::GFx::Value FUN_140e5bfe0(const char* szMethod, CString a1, float a2, float a3);   // 0x140e5bfe0 (inline COMDAT, defined in uimasteryobjectmark.cpp; a1 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, CString a1, const AScript& a2);      // 0x140e7bcb0 (inline COMDAT, defined in uiquestnavigation.cpp; a1 by value)
    Scaleform::GFx::Value Invoke(const char* szMethod, const AScript& obj);                  // 0x140ba4cc0 (passes obj's value)
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned int a1, float a2);          // 0x140ba4c00 (inline COMDAT, defined in uiadventureleveldialog.cpp)
    template <class T> MS2Ptr<T> FUN_140accef0(const CString& strName);                      // child control by name (the adventure level lists)
    template <class T> MS2Ptr<T> FUN_140acce30(const CString& strName);                      // same, one COMDAT per wrapper class (w47: pet evolution)
    template <class T> MS2Ptr<T> FUN_140accfb0(const CString& strName);
    template <class T> MS2Ptr<T> FUN_140bbe880(const CString& strName);    // bind a typed child (uiguilddialog "m_gradeName" as ASTextInput)
    template <class T> MS2Ptr<T> FUN_140c26ea0(const CString& strName);                      // child control by name (guild mail "m_content"; uiguilddialog.cpp)
    template <class T> MS2Ptr<T> FUN_140c11f50(const CString& strName);                      // child control by name (check box; uirankpvpdialog.cpp)
    template <class T> MS2Ptr<T> FUN_140bfa6a0(const CString& strName);                      // child control by name (alliance quest list)
    template <class T> MS2Ptr<T> FUN_140be23c0(const CString& strName);                      // child control by name (tab bar; uidailymissiondialog.cpp)
    template <class T> MS2Ptr<T> FUN_140bc7280(const CString& strName);                      // child control by name (list; uidailymissiondialog.cpp)
    template <class T> MS2Ptr<T> FUN_140fe4370(const CString& strName);                      // child control by name (tab button group; uimeratmarketdialog.cpp)
    AScript(const AScript& o);                                                               // 0x1409bb7b0 (inline COMDAT)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1);                         // 0x140acd130 (inline COMDAT, tabcontentspetevolution.cpp)
    // 0x141917bf0 (inline COMDAT, defined in uidamagetext.cpp; all by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, CString a1, CString a2, CString a3, CString a4);
    Scaleform::GFx::Value FUN_140acd1f0(const char* szMethod, AScript a1);                   // 0x140acd1f0 (Invoke with the AS object by value: the callee destroys it)
    Scaleform::GFx::Value FUN_1422bb8f0(const char* szMethod, ASArgList& args);              // the Invoke back end
    Scaleform::GFx::Value Invoke(const char* szMethod, __int64 a1, CStringW a2, int a3, CStringW a4);   // 0x141b4da00 (inline COMDAT, defined in uiupperhpbar.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, bool a1);                             // 0x140bfe360 (inline COMDAT, defined in uicoupledanceeventdialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, MS2Ptr<AScript> a1);                 // 0x141ac34b0 (inline COMDAT, defined in uirewardnotify.cpp; a1 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, CStringW a2, CStringW a3);   // 0x140fac340 (inline COMDAT, defined in unit_140fa9eb0.cpp; a2/a3 by value: the callee destroys them)
    Scaleform::GFx::Value FUN_1412e80d0(const char* szMethod, CStringW a1, CStringW a2, CStringW a3);   // 0x1412e80d0 (Invoke with three strings; the args are destroyed by the callee)
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned int a1, unsigned int a2, CStringW a3);   // 0x140bfedf0 (inline COMDAT, defined in uirandomcoupon.cpp; a3 by value: the callee destroys)
    Scaleform::GFx::Value Invoke(const char* szMethod, CString a1, int a2, int a3);          // 0x141944620 (inline COMDAT, defined in uigameoptiondialog.cpp; a1 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, bool a2, bool a3);            // 0x141944710 (inline COMDAT, defined in uigameoptiondialog.cpp)

    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, int a2, int a3, CStringW a4);   // 0x140fb1a80 (inline COMDAT, defined in uiugcportaldialog.cpp; a1/a4 by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, AScript a2, ASArray a3);   // 0x140c1f740 (inline COMDAT, defined in uihideandseekresultdialog.cpp; a2/a3 by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, CStringW a2, CStringW a3, CStringW a4, int a5, bool a6);   // 0x1412e7f30 (inline COMDAT, defined in uimanufacturedialog.cpp; a2..a4 by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned __int64 a1, CString a2, CStringW a3);   // 0x1412e8210 (inline COMDAT, defined in uimanufacturedialog.cpp; a2/a3 by value)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CStringW a2, CStringW a3, int a4);   // 0x1418ce200 (inline COMDAT, defined in uibeautyshopdialog.cpp; a1..a3 by value)
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1, int a2, CString a3);   // 0x1418ce360 (inline COMDAT, defined in uibeautyshopdialog.cpp; a1/a3 by value)
    Scaleform::GFx::Value Invoke(const char* szMethod, float a1, int a2);                    // 0x1418cc380 (inline COMDAT, defined in uibeautyshopdialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1); // 0x1409ba030 (couple dance HUD)
    Scaleform::GFx::Value Invoke(const char* szMethod, Unk_UgcOpenType a1);          // 0x141b3b610 (inline COMDAT, defined in uiugcimageuploaddialog.cpp; an Int value of the open type)
    Scaleform::GFx::Value Invoke(const char* szMethod, const char* a1, bool a2);             // 0x141aa2d90 (inline COMDAT, defined in uiquestdialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, class ASFunction a1);                 // 0x1409bb370 (inline COMDAT, defined in asitemslot.cpp; a1 by value: the callee destroys it)
    Scaleform::GFx::Value FUN_141b06d40(const char* szMethod, class ASDataProvider* a1, bool a2);       // 0x141b06d40 (inline COMDAT, defined in uishopdialog.cpp: Invoke with a list and a flag)
    Scaleform::GFx::Value FUN_141b06e00(const char* szMethod, unsigned __int64 a1, unsigned int a2);        // 0x141b06e00 (inline COMDAT, defined in uishopdialog.cpp: Invoke with a UInt64 and a UInt)
    Scaleform::GFx::Value Invoke(const char* szMethod, class ASSlot a1);                     // 0x1409bb460 (inline COMDAT, defined in asitemslot.cpp; a1 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, long a1, int a2);                     // 0x141a004c0 (inline COMDAT, defined in uimessagebox.cpp; Int/Int values, (int, int) is taken by 0x140acd070)
    Scaleform::GFx::Value Invoke(const char* szMethod, const char* a1, CStringW a2);  // 0x141a00580 (inline COMDAT, defined in uimessagebox.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, __int64 a1, __int64 a2, int a3); // 0x140e98700 (UITamingBar, w4s10)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, int a3, int a4); // 0x140e64f60 (couple dance HUD COMDAT)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, int a3, int a4, int a5, CString a6, size_t a7);   // 0x140f35180 (inline COMDAT, defined in uidarkstreamresultdialog.cpp; a6 by value: the callee destroys it)
    Scaleform::GFx::Value FUN_140f5ff80(const char* szMethod, CStringW a1, bool a2);        // 0x140f5ff80 (inline COMDAT; a1 by value: the callee destroys it)

    Scaleform::GFx::Value Invoke(const char* szMethod, __int64 a1);                         // 0x140c60480 (inline COMDAT, defined in unit_140c5d230.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, int a3, int a4, int a5);   // 0x140c60370 (inline COMDAT, defined in unit_140c5d230.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, __int64 a1, __int64 a2, CStringW a3);   // 0x140c60520 (inline COMDAT, defined in unit_140c5d230.cpp; a3 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, __int64 a1, __int64 a2, CStringW a3, CString a4);   // 0x140c60620 (inline COMDAT, defined in unit_140c5d230.cpp; a3/a4 by value)

    // Binds the AS child `strName` to `out` and returns a copy of it (0x140bbe640 for T = Unk_ASExitButton).
    template <class T> MS2Ptr<T> FUN_140bbe640(const CString& strName, MS2Ptr<T>& out);

    template<class T> MS2Ptr<T> FUN_140beaf20(const CString&, MS2Ptr<T>&); // bind text (mentoring reward)
    template<class T> MS2Ptr<T> FUN_140bc71c0(const CString&, MS2Ptr<T>&); // bind display object
    template<class T> MS2Ptr<T> FUN_141009c70(const CString&, MS2Ptr<T>&); // bind child component (inline COMDAT, defined in uinoticedialog.cpp)
    template<class T> MS2Ptr<T> FUN_140c57d70(const CString&, MS2Ptr<T>&); // bind child control (inline COMDAT, defined in uiitemtreasuremapdialog.cpp)
    template<class T> MS2Ptr<T> FUN_140bbe7c0(const CString&, MS2Ptr<T>&); // bind combo box (party search register)
    template<class T> MS2Ptr<T> FUN_140bbe940(const CString&, MS2Ptr<T>&); // bind input box (party search register)
    template<class T> MS2Ptr<T> FUN_140bc7340(const CString&, MS2Ptr<T>&); // bind list (debug guide)
    template<class T> MS2Ptr<T> FUN_140c12010(const CString&, MS2Ptr<T>&); // bind check box (party search register)
    template<class T> MS2Ptr<T> FUN_140bc7100(const CString&, MS2Ptr<T>&); // bind icon (DT attendance)
    template<class T> MS2Ptr<T> FUN_140bc6e60(const CString&, MS2Ptr<T>&); // bind gauge (uidungeonroomdialog "m_summaryGauge")
    template<class T> MS2Ptr<T> FUN_140e159f0(const CString&);               // child control by name, one COMDAT per wrapper class (dungeon helper)
    template<class F> void FUN_1422c2a70(const F&, int); // click callback (DT attendance)
    Scaleform::GFx::Value& FUN_1422bb890(); // root value forwarding accessor
    Scaleform::GFx::Value FUN_140e813f0(const char* szMethod, const ASArray& arr, int n);    // Invoke(method, array, int) (unit_141347b10: "buildCategoryList")
    MS2Ptr<ASMovieClip> FUN_1409b4560(const CString& strName); // bind a movie clip child (w4s10; units may hide it)
    MS2Ptr<ASTextField> FUN_1409b4620(const CString& strName); // bind a text field child (aseffect.cpp)
    Scaleform::GFx::Value Invoke(const char*, CString, int); // setTabCount, 0x140a46640
    Scaleform::GFx::Value FUN_140ee5060(const char* szMethod, CString a1, bool a2);          // 0x140ee5060 (game menu red circle)
    Scaleform::GFx::Value FUN_140c38f00(const char* szMethod, CString a1, CStringW a2);     // 0x140c38f00 (game menu event popup)
    Scaleform::GFx::Value FUN_14184af30(const char* szMethod, bool a1, int a2);             // 0x14184af30 (game menu quest)
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned int a1);                    // 0x140ba26d0 (UIStanceBar; Value = UInt)
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned long a1);                   // 0x140ba2770
    Scaleform::GFx::Value Invoke(const char* szMethod, long a1);                            // 0x1418e0670 (inline COMDAT, defined in uicameraeditdialog.cpp; an Int value like the int form 0x1409ba030)
    Scaleform::GFx::Value Invoke(const char* szMethod, float a1, float a2, CStringW a3, int a4, bool a5, CStringW a6, CStringW a7, int a8);   // 0x1418e1d20 (inline COMDAT, defined in uicameraeditdialog.cpp; a3/a6/a7 by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned long a1, unsigned long a2); // 0x140ba2810
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CStringW a2, int a3, Scaleform::GFx::Value a4);   // 0x140c6db60 (inline COMDAT, defined in uilongtermattendgiftdialog.cpp; a1/a2/a4 by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned int a1, Scaleform::GFx::Value a2);   // 0x140e2b2d0 (inline COMDAT, defined in uiequipiconcontainer.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1, CString a2, Scaleform::GFx::Value a3);   // 0x140e2b3d0 (inline COMDAT, defined in uiequipiconcontainer.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1, int a2, bool a3);   // 0x140f8f850 (inline COMDAT, defined in uipartysearchdialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, CStringW a2, CStringW a3, CStringW a4, CStringW a5, CStringW a6, CStringW a7);   // 0x14198d3c0 (inline COMDAT, defined in uihousemark.cpp; the strings by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, CString a1, CStringW a2, CStringW a3, CStringW a4, int a5, int a6);   // 0x141a730c0 (uiobjectstoredialog.cpp initData; the strings by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, unsigned int a2, CStringW a3, CStringW a4);   // 0x1413515e0 (uitextpreviewdialog.cpp descriptionCheck; a3/a4 by value: the callee destroys them)
    int FUN_14198f250() { return m_nMovieId; }                                              // 0x14198f250 (inline COMDAT, first emitted in uihousemark.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, AScript a2);                  // 0x140c0df40 (inline COMDAT, defined in uidungeoncategory.cpp; a2 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, __int64 a1, __int64 a2);              // 0x140cb6990 (UIPvPGuildTeamDialog setHpBar)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CStringW a2, __int64 a3, __int64 a4);   // 0x14133c8c0 (inline COMDAT, defined in uipvpguildteamdialog.cpp; a1/a2 by value: the callee destroys them)
    bool FUN_1422ba9f0(const char* szMember);                                               // the AS object has the member (uipvpguildteamdialog)
    Scaleform::GFx::Value FUN_14190b490(const char* szMethod, unsigned int a1, unsigned int a2, float a3);   // 0x14190b490 (Invoke; inline COMDAT, defined in uicutscenecinematic.cpp: setStageSize)
    Scaleform::GFx::Value FUN_14190b570(const char* szMethod, bool a1, CStringW a2, CStringW a3);   // 0x14190b570 (Invoke; inline COMDAT, defined in uicutscenecinematic.cpp; a2/a3 by value: the callee destroys them)
    Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int a1, CStringW a2);         // 0x14129cce0 (Invoke(int, string), defined in unit_14129ba60.cpp; a2 by value)
    Scaleform::GFx::Value FUN_1409ba0d0(const char* szMethod, int a1, int a2);               // 0x1409ba0d0 (UIQuestGuideDialog setMaxEntity)
    Scaleform::GFx::Value FUN_140bd2cb0(const char* szMethod, const ASArray& a1);           // 0x140bd2cb0 (UIQuestGuideDialog buildAll)
    Scaleform::GFx::Value FUN_140ed11b0(const char* szMethod, unsigned int a1);               // 0x140ed11b0 (inline COMDAT, defined in uiskillbookautodistributedialog.cpp; Value = UInt)
    Scaleform::GFx::Value FUN_140ed0fd0(const char* szMethod, int a1, bool a2);             // 0x140ed0fd0 (UIQuestGuideDialog setTracingEntity)
    Scaleform::GFx::Value FUN_1422bb3c0();                                                   // 0x1422bb3c0 call the AS function this object wraps
    Scaleform::GFx::Value Invoke(const char* szMethod, const AScript& a1, const char* a2);  // 0x141aafc10 (inline COMDAT, defined in uiquesteventlistener.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, float a1);                           // 0x14127bfb0 (inline COMDAT, defined in gfxmoviebackground.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, float a1, float a2, float a3);       // 0x14127c050 (inline COMDAT, defined in gfxmoviebackground.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, Scaleform::GFx::Value a3);   // 0x140f0a3f0 (inline COMDAT, defined in uibeautyshopstyledialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, Scaleform::GFx::Value a2);   // 0x140f0a510 (inline COMDAT, defined in uibeautyshopstyledialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, const wchar_t* a1, bool a2, bool a3);   // 0x140f0a610 (inline COMDAT, defined in uibeautyshopstyledialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, CString a1, Scaleform::GFx::Value a2);    // 0x140f0c520 (inline COMDAT, defined in uiblackmarketpage.cpp; both by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, const ASArray& a1, int a2, int a3);       // 0x140f17080 (inline COMDAT, defined in uiblackmarketpage.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1, Scaleform::GFx::Value a2);   // 0x140f17150 (inline COMDAT, defined in uiblackmarketpage.cpp; both by value)
    Scaleform::GFx::Value Invoke(const char* szMethod, const class ASDataProvider& a1);          // 0x140bbeaa0 (inline COMDAT; the provider's value)
    Scaleform::GFx::Value Invoke(const char* szMethod, const ASArray& a1, int a2);               // 0x140e813f0 (inline COMDAT)
    CStringW FUN_1422bb2b0(const char* szName);                                                 // a member as text (uiblackmarketpage.cpp; ASObj declares the same)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CStringW a2, bool a3, bool a4);   // 0x140f0a6f0 (inline COMDAT, defined in uibeautyshopstyledialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1, long a2);   // 0x140f0a830 (inline COMDAT, defined in uibeautyshopstyledialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, bool a2, bool a3, Scaleform::GFx::Value a4);   // 0x1419b2be0 (inline COMDAT, defined in uiitemcoloringdialog.cpp; all by value)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, bool a2);                    // 0x140f356e0 (inline COMDAT, defined in uidarkstreamscoredialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, bool a3);            // 0x140f9d9e0 (inline COMDAT, defined in uishadowexpeditionbossbar.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, bool a1, bool a2);                   // 0x140fc1a70 (inline COMDAT, defined in uiwatchagamedialog.cpp)
    Scaleform::GFx::Value FUN_14197a3e0(const char* szMethod, bool a1, bool a2, bool a3);   // 0x14197a3e0 (inline COMDAT, defined in uiguilddialog.cpp: Invoke with three Booleans)
    Scaleform::GFx::Value FUN_14197a240(const char* szMethod, int a1, bool a2, float a3);   // 0x14197a240 (inline COMDAT, defined in uiguilddialog.cpp: Invoke with an Int, a Boolean and a Number)
    Scaleform::GFx::Value FUN_141979e60(const char* szMethod, int a1, int a2, const class ASArray& a3);   // 0x141979e60 (inline COMDAT, defined in uiguilddialog.cpp: Invoke with two Ints and an array)
    Scaleform::GFx::Value FUN_14197a030(const char* szMethod, int a1, int a2, bool a3, const class ASArray& a4);   // 0x14197a030 (inline COMDAT, defined in uiguilddialog.cpp)
    Scaleform::GFx::Value FUN_14197a320(const char* szMethod, bool a1, const class ASArray& a2);   // 0x14197a320 (inline COMDAT, defined in uiguilddialog.cpp)
    Scaleform::GFx::Value FUN_14197a120(const char* szMethod, int a1, float a2, int a3, CStringW a4);   // 0x14197a120 (inline COMDAT, defined in uiguilddialog.cpp; a4 by value: the callee destroys it)
    Scaleform::GFx::Value FUN_141979f30(const char* szMethod, int a1, int a2, CStringW a3);   // 0x141979f30 (inline COMDAT, defined in uiguilddialog.cpp; a3 by value: the callee destroys it)
    template <class T> MS2Ptr<T> FUN_140c436d0(const CString& strName);   // child control by name (guild championship "m_participate" as ASLabel; uiguilddialog.cpp)
    Scaleform::GFx::Value FUN_140e6b140(const char* szMethod, int a1, CString a2);          // 0x140e6b140 (a2 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, int a2);                // 0x140e0a8c0 (inline COMDAT, defined in uichapterbook.cpp; a1 by value: the callee destroys it)
    Scaleform::GFx::Value FUN_141b62c20(const char* szMethod, int a1, const AScript& a2);    // 0x141b62c20 (inline COMDAT, defined in uiworldmapdialog.cpp: Invoke with an Int and an object)
    Scaleform::GFx::Value FUN_141b62ce0(const char* szMethod, unsigned __int64 a1, unsigned int a2);   // 0x141b62ce0 (inline COMDAT, defined in uiworldmapdialog.cpp: Invoke with a UInt64 and a UInt)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, CStringW a2, int a3);        // 0x140e65dd0 (inline COMDAT, defined in uimicrogamecoupledancemessage.cpp; a2 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, int a2, CStringW a3, CStringW a4);   // 0x141342280 (inline COMDAT, defined in uipvpguildteamresultdialog.cpp; the strings by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, const char* a2);        // 0x1413423e0 (inline COMDAT, defined in uipvpguildteamresultdialog.cpp; a1 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, CString a1, unsigned __int64 a2, CString a3);   // 0x1412db770 (inline COMDAT, defined in uimaidrecipelistdialog.cpp; the strings by value: the callee destroys them)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, CStringW a3);        // 0x140ed0ed0 (UIManufactureStatus updateProgress; a3 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned __int64 a1, CStringW a2);   // 0x140ed1250 (inline COMDAT, defined in uiskillbookautodistributedialog.cpp; a2 by value: the callee destroys it)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CStringW a2, int a3);   // 0x140ed1090 (inline COMDAT, defined in uiskillbookautodistributedialog.cpp; the strings by value)
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1, Scaleform::GFx::Value a2, int a3);   // 0x1412e13f0 (inline COMDAT, defined in uimaidrecipelistdialog.cpp; the values by value)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, const char* a3, int a4);   // 0x1412d4770 (inline COMDAT, defined in uiitemoptioncreatedialog.cpp)
    // Invoke(method, size_t) / Invoke(method, size_t, bool) under their addresses: an Invoke overload taking a single
    // unsigned __int64 would make the existing Invoke(method, <int-like>) calls ambiguous.
    Scaleform::GFx::Value FUN_140c1c8c0(const char* szMethod, unsigned __int64 a1);         // 0x140c1c8c0 (UInt value; "setupTabSize")
    Scaleform::GFx::Value FUN_140fdd6b0(const char* szMethod, unsigned __int64 a1, bool a2);   // 0x140fdd6b0 (inline COMDAT, defined in uiweddinghallreservationdialog.cpp; "setTabEnable")
    Scaleform::GFx::Value FUN_1413127f0(const char* szMethod, CString a1, CString a2);         // 0x1413127f0 (Invoke(string, string); both by value: the callee destroys them; uiguilddialog "setGuildMark")
    Scaleform::GFx::Value FUN_141312a70(const char* szMethod, CString a1, Scaleform::GFx::Value a2, int a3, int a4, CStringW a5);   // 0x141312a70 (inline COMDAT, defined in uimeratmarketdialog.cpp: "buildSellerItemList"; a1/a2/a5 by value)
    Scaleform::GFx::Value FUN_1413128f0(const char* szMethod, CString a1, Scaleform::GFx::Value a2, int a3, int a4, const wchar_t* a5);   // 0x1413128f0 (same, a5 a literal)
    Scaleform::GFx::Value FUN_1413130e0(const char* szMethod, Scaleform::GFx::Value a1, CStringW a2, int a3);   // 0x1413130e0 (inline COMDAT of uimeratmarketdialog.cpp: "changeState"; a1/a2 by value)
    MS2Ptr<class ASDropdownMenu> FUN_140bbe700(const CString& strName);                       // 0x140bbe700 bind a dropdown child (uiguilddialog "m_sortDropdown")

    Scaleform::GFx::Value FUN_1413125d0(const char* szMethod, const ASArray& a1, int a2, bool a3, Scaleform::GFx::Value a4);   // 0x1413125d0 (inline COMDAT, defined in uimeratmarketdialog.cpp: "buildItemList"; a4 by value)

    Scaleform::GFx::Value FUN_1413124f0(const char* szMethod, const ASArray& a1, int a2, bool a3);   // 0x1413124f0 (inline COMDAT, uimeratmarketdialog.cpp: "buildItemList" without the info object)

    Scaleform::GFx::Value FUN_141312710(const char* szMethod, CStringA a1, int a2);   // 0x141312710 (inline COMDAT, uimeratmarketdialog.cpp: "removeItemComplete"; a1 by value)

    Scaleform::GFx::Value FUN_141312c10(const char* szMethod, CStringW a1, int a2);   // 0x141312c10 (inline COMDAT, uimeratmarketdialog.cpp: "removeBasket"; a1 by value)

    Scaleform::GFx::Value FUN_141313220(const char* szMethod, Scaleform::GFx::Value a1, int a2);   // 0x141313220 (inline COMDAT, defined in uimeratmarketdialog.cpp: "appendLimitedTab"; a1 by value)
    Scaleform::GFx::Value FUN_141312cf0(const char* szMethod, ASArray a1, int a2, bool a3);   // 0x141312cf0 (inline COMDAT, defined in uimeratmarketdialog.cpp; a1 by value)
    Scaleform::GFx::Value FUN_141312e20(const char* szMethod, Scaleform::GFx::Value a1, const ASArray& a2, int a3, int a4);   // 0x141312e20 (inline COMDAT, uimeratmarketdialog.cpp: "addSellerComplete"; a1 by value)
    Scaleform::GFx::Value FUN_141312f60(const char* szMethod, Scaleform::GFx::Value a1, Scaleform::GFx::Value a2, CString a3);   // 0x141312f60 (inline COMDAT, uimeratmarketdialog.cpp; all by value)

    Scaleform::GFx::Value FUN_1409ba030(const char* szMethod, int a1);   // 0x1409ba030 Invoke(method, int) (uimeratmarketdialog.cpp "changeTab")

    Scaleform::GFx::Value FUN_140f0a830(const char* szMethod, Scaleform::GFx::Value a1, long a2);   // 0x140f0a830 Invoke(method, value, long) (uimeratmarketdialog.cpp "updateBg"; a1 by value)

    Scaleform::GFx::Value Invoke(const char* szMethod, float a1, float a2, CStringW a3, CStringW a4, CStringW a5, CStringW a6);   // 0x140e6e910 (inline COMDAT, defined in uioxquizdialog.cpp: "setQuizPromoteCooltime"; the strings by value)

protected:   // cr4: was private; derived AS helpers (ASCommonDepth) read the movie id and the value
    union {
        void* m_pad_18;                 // not char[8]: an array member makes every local AS object a /GS buffer
        int m_nMovieId;                 // +0x18 movie id given to the ctor (ASCommonDepth reads it)
    };
    Scaleform::GFx::Value m_value;      // +0x20
};
MS2_CHECK_SIZE(AScript, 0x40);
