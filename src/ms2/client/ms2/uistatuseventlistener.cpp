// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: ?\uistatuseventlistener.cpp (name assumed, the
// exe has no assert path for it). The status event hub (UIStatusEventDispatcher + the 8-byte UIStatusEventListener
// base) and the bank window that follows it in the file (UIStoreDialog, UI id 0x4e47).
// MS2-UNIT: ?\uistatuseventlistener.cpp
// MS2-RANGE: 0x14011dbe0-0x14011dd60 .text$di
// MS2-RANGE: 0x142cc2a90-0x142cc2b36 .text$yd
// MS2-RANGE: 0x141b0cc00-0x141b127f0 .text$mn
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uistatuseventlistener.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uistatuseventlistener.h"

#include <atlcoll.h>
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/storeslot.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the unit's static strings (.text$di) ------------------------------------------------------------------------
static CString s_strStoreDialogClose = "store_dialog_close";                // @0x14011dbe0
static CString s_strStoreDialogOpen = "store_dialog_open";                  // @0x14011dc10
static CString s_strExpandBankSlot = "system_expandbankSlot";               // @0x14011dc40
static CString s_sort7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x14011dc70
static CString s_skill = "skill";                                           // @0x14011dd30

// ---- unit-local views of exe objects (names assumed; layouts only as far as this unit reads them) ----------------------

// The local player (MyPC) and the stats the hub reads.
class Unk_StWorld { public: PCBase* FUN_141bd0cc0(); };
Unk_StWorld* FUN_1403ed2d0();
int FUN_141654730(PCBase* p);                                               // the job code
const CStringW& FUN_141656be0(PCBase* p);                                   // the player name
struct Unk_PCEquipSet;
Unk_PCEquipSet* FUN_1416561a0(PCBase* p);                                   // the equip holder
void FUN_1411e7660(Unk_PCEquipSet* p);                                      // refresh the equip set
CPartyManager* FUN_1409670d0();
class Unk_StJobTable { public: void* FUN_140353610(unsigned short nLevel); };
Unk_StJobTable* FUN_1404a1bb0();
void* FUN_140930240();
void* FUN_140930ae0();
extern __int64 DAT_143ab2898;                                               // max deposit
extern __int64 DAT_143ab28a0;
extern __int64 DAT_143ab28f8;                                               // the mesos in the bag
extern __int64 DAT_143ab2958;
CStringW FUN_140719a00(__int64 n);                                          // a number as text

// The status listeners' registry (singleton 0x140aa6d40) and the item event hub (0x140a6a840).
UIStatusEventDispatcher* FUN_140aa6d40();
class Unk_StItemHub
{
public:
    void FUN_1419cae20(UIItemEventListener* listener);                      // register (once)
    void FUN_1419caeb0(UIItemEventListener* listener);                      // unregister
};
Unk_StItemHub* FUN_140a6a840();

// The store model (global 0x143ab2d80): meso balances, slot counts, the item names.
class Unk_StItemNames;
class Unk_StModel
{
public:
    int FUN_140de27c0();                                                    // a request is pending
    int FUN_140de2860();                                                    // initialised
    void FUN_140de2b50();                                                   // request the data
    void FUN_140de2d60();                                                   // reset
    int FUN_140de1c00();                                                    // the used slots
    int FUN_140de1c30();                                                    // the slot count
    __int64 FUN_140de2a80();                                                // mesos in the store
    __int64 FUN_140de2ab0();                                                // mesos in the bag
    int FUN_140de29b0();                                                    // the next expansion step
    __int64 FUN_140de2ae0();                                                // the expansion price
    int FUN_140de2970();                                                    // the slots are at the maximum
    void FUN_140de2bd0();                                                   // sort
    void FUN_140de2c40(int bDeposit, __int64 nAmount);                      // send the deposit / withdraw
    void FUN_140de2ce0();                                                   // send the expand request
    void FUN_140de1fd0(ATL::CAtlArray<void*>* pOut);                        // the item entries
};
extern Unk_StModel DAT_143ab2d80;

// The inventory dialog (UI id 0x4e2d) the store window is placed next to.
class UIInventoryDialog : public UIDialog { };
UIInventoryDialog* FUN_1405344f0(int nUiId);
class ASDialog : public ASDisplayObject { };

// The UI message ("openWindowPos"): an ActionScript call (ASData + type, 0x50 bytes).
class Unk_OsUIMsg : public UIMsg
{
public:
    Unk_OsUIMsg();                                          // 0x1422e4490
    ~Unk_OsUIMsg();                                         // 0x140c30570
    void FUN_1422b82b0(const char* pszMethod);
    void FUN_1422b7f70(int n);
    void* m_pad[10];
};

// The bound slot bag of a bag id and the control state it keeps.
Unk_StBagBind* FUN_1422c8e90(const CString& strBagId);
StoreSlotBag* FUN_14180b940(Unk_StBagBind* pBind);
void FUN_1422cca90(StoreSlotBag* pBag);
void FUN_14180b230(CString* pBagId);                                        // drop the bag bound to the id
void FUN_14180b170(CString* pBagId, int nSlot, int nSize);                  // create the bag
class Unk_StBagCtl
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(int n);                           // 11 (+0x58)
    virtual void vfunc_12(int n);                           // 12 (+0x60)
};
Unk_StBagCtl* FUN_140c544d0(Unk_StBagBind* pBind);

// The search input ("m_inputSearch") and the movie root helper that binds it.
class Unk_StInput : public ASDisplayObject
{
public:
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void vfunc_24(int bFocus);                                      // 24 (+0xc0) set the focus
    Scaleform::GFx::Value FUN_140bbeaa0(const char* szMethod, ASArray& a1);
    CStringW FUN_1422e0b00();                                               // the text
    void FUN_1422e0bd0(const CStringW& str);                                // set the text
    void FUN_1422e0920(const UIStoreDialog::StoreDelegate& onChange);       // text changed callback
};
int FUN_1422c76c0(Unk_StInput* p);                                          // the input has the focus
void FUN_1422c7630(ASDisplayObject* p, int bFocus);
int FUN_140bc0500(Unk_StInputRef* p);                                       // not null
Unk_StInput* FUN_140bc0550(Unk_StInputRef* p);                              // operator->
void FUN_140bbf710(Unk_StInputRef* p);                                      // default ctor
void FUN_140bbfdd0(Unk_StInputRef* p);                                      // release
void FUN_140bc0300(Unk_StInputRef* p, int n);                               // reset
int FUN_14199f2c0(Unk_StInputRef* p);                                       // composing (IME)
class Unk_StScript : public AScript
{
public:
    Unk_StInputRef FUN_140bbe940(const CString& strName, Unk_StInputRef* pBind);   // bind the input child to pBind
    Scaleform::GFx::Value FUN_140c38f00(const char* szMethod, CString a1, CStringW a2);
    Scaleform::GFx::Value FUN_140acd130(const char* szMethod, CStringW a1);
    Scaleform::GFx::Value FUN_1409ba030(const char* szMethod, int a1);
};
// the result Value of the calls above is destroyed by the caller (FUN_140614800)

// The "expand" text / effect clips.
class Unk_StExpandClip : public ASMovieClip
{
public:
#define ST_V(n) virtual void vfunc_##n();
    ST_V(16) ST_V(17) ST_V(18) ST_V(19) ST_V(20) ST_V(21) ST_V(22) ST_V(23)
#undef ST_V
    virtual void vfunc_24(int bShow);                                       // 24 (+0xc0) refresh
    void FUN_1422e4a50(const CStringW& str);                                // set the text
};

// The search platform request (see uigamedictionarydialog.cpp, the same objects).
class Unk_DictPlatform
{
public:
#define DC_V(n) virtual void vfunc_##n();
    DC_V(0) DC_V(1) DC_V(2) DC_V(3) DC_V(4) DC_V(5) DC_V(6) DC_V(7) DC_V(8) DC_V(9)
    DC_V(10) DC_V(11) DC_V(12) DC_V(13) DC_V(14) DC_V(15) DC_V(16) DC_V(17) DC_V(18) DC_V(19)
    DC_V(20) DC_V(21) DC_V(22) DC_V(23) DC_V(24) DC_V(25) DC_V(26) DC_V(27) DC_V(28) DC_V(29)
    DC_V(30) DC_V(31) DC_V(32) DC_V(33) DC_V(34) DC_V(35) DC_V(36)
    virtual int vfunc_37(void* pRequest);
#undef DC_V
};
Unk_DictPlatform* FUN_140d86260();
class Unk_DictRequest
{
public:
    Unk_DictRequest(int nId);                               // 0x1401baa00
    Unk_DictRequest(const void* pSource);                   // 0x1401baaa0
    ~Unk_DictRequest();                                     // 0x1401baaf0
    void FUN_1401bac80(const CString& strName, CStringW strValue, int n);
    int FUN_1401bab90(const CString& strName, void* pOut);
private:
    char m_pad[0x38];
};
struct Unk_DictRequestValue
{
    Unk_DictRequestValue();                                 // 0x1401ba840
    ~Unk_DictRequestValue();                                // 0x1401ba940
    char m_pad_00[8];
    CStringW m_text;                                        // +0x08
    char m_pad_10[8];
    int m_code;                                             // +0x18
    char m_pad_1c[0x1c];
};

// Input state, the movie manager, string helpers and message boxes.
class Unk_StInputState { public: char FUN_14116d9c0(int a, int b, int c); };
Unk_StInputState* FUN_14025e7c0();
char* FUN_14025e7b0();
int FUN_1402c4c90(void* p, int n);
class Unk_StUiSvc;
Unk_StUiSvc* FUN_1403ed2b0();
void FUN_141add1f0(Unk_StUiSvc* p);          // tell why the expansion is not possible
class Unk_StUiMgr { public: int FUN_1422d4e20(const CString& strKey); void FUN_1422d4dd0(const CString& strKey); };
Unk_StUiMgr* FUN_140b632f0();
class Unk_StStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_StStrings* FUN_1401a9d70();
CStringW FUN_1409eec40(int nStringId);
CStringW FUN_1413fa9b0(const CStringW& kIn);
CStringW FUN_1409404f0(__int64 n);                                          // a number with thousand separators
CStringW FUN_140763e10(int n);
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
CStringW FUN_1406e7810(const wchar_t* szFormat, const unsigned& a, const unsigned& b);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int, int, void*, CStringW);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW text, int nType, const Delegate<bool(int, const CMsgBoxData&)>& cb);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_14199e740(int nStringId, int nA, int nB, const int* pnKind, const CStringW& str);
void FUN_140961010(int nStringId, int nA, int nB, const CStringW& str);
void FUN_1409e97f0(CStringW* pOut, int nStringId, const int* pnArg);
void FUN_14151f200();
int FUN_1412772f0(__int64 n, int a);
void FUN_141276180(const CString& strKey, const CString& strValue);
int FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szDelim, int nMax);
CStringW* FUN_140159a00(ATL::CAtlArray<CStringW>* p, size_t i);
char FUN_1403b3c40(const CStringW& a, const wchar_t* b);
const __int64& FUN_1402e49a0(const __int64* a, const __int64* b);           // std::min
int FUN_141b21220(void* p);
void* FUN_140967100();
void FUN_141b1feb0(void* p);
struct Unk_PickXY { float x, y; };                                          // dialog offset
extern Unk_PickXY DAT_143b02320;                                            // zero offset
void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, Unk_PickXY offLeft, Unk_PickXY offRight);
CStringW FUN_140720ca0(void*);

// The candidate set (a hash set of names, 0x30 bytes, 10 bins) and one item entry (0x10 bytes).
class Unk_StCandSet { public: char m_pad[0x30]; };
void FUN_14025b4d0(Unk_StCandSet* p, int nBins);
void* FUN_14025e750(Unk_StCandSet* p);                                      // first position
const CStringW& FUN_14025e5c0(Unk_StCandSet* p, void* pos);                 // the key at a position
void FUN_14025e840(Unk_StCandSet* p, void** pPos);                          // next
void FUN_14025c430(Unk_StCandSet* p);                                       // dtor
void* FUN_1409eea60(Unk_StCandSet* p, const CStringW& key);                 // lookup
void FUN_14025d670(Unk_StCandSet* p, const CStringW& key);                  // insert
class Unk_StItemEntry { public: char m_pad[0x10]; };
void FUN_1402034d0(Unk_StItemEntry* p, void* pSrc);
char FUN_1401c0050(Unk_StItemEntry* p, int n);
void* FUN_1401c0180(Unk_StItemEntry* p);
void FUN_140527b10(void* pItem, CStringW* pName);
void FUN_1401bfde0(Unk_StItemEntry* p);
size_t FUN_140720ca0_count(void*);
void* FUN_140c3c720(ATL::CAtlArray<void*>* p, unsigned i);

// The candidate list (setCandidates) values.
class Unk_StCandList { public: char m_pad[0x40]; };

// ---- UIStatusEventListener -------------------------------------------------------------------------------------------

// @0x141b0cc00
UIStatusEventListener::UIStatusEventListener()
{
}

// @0x141b0cc20
UIStatusEventListener::~UIStatusEventListener()
{
}

// @0x141b0cc40
int UIStatusEventListener::vfunc_oa0_1()
{
    return 1;
}

// ---- UIStatusEventDispatcher -----------------------------------------------------------------------------------------

// @0x141b0cc60
UIStatusEventDispatcher::UIStatusEventDispatcher()
{
}

// @0x141b0ccb0
UIStatusEventDispatcher::~UIStatusEventDispatcher()
{
    m_listeners.RemoveAll();
}

// @0x141b0cd00
void UIStatusEventDispatcher::FUN_141b0cd00(void* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i)
    {
        if (pListener == m_listeners.GetAt(i))
            return;
    }
    m_listeners.Add(pListener);
}

// @0x141b0cd90
void UIStatusEventDispatcher::FUN_141b0cd90(void* pListener)
{
    size_t i = 0;
    while (i < m_listeners.GetCount())
    {
        if (pListener == m_listeners.GetAt(i))
            break;
        ++i;
    }
    if (i < m_listeners.GetCount())
        m_listeners.RemoveAt(i, 1);
}

#define ST_EACH_LISTENER(i, pL) \
    for (size_t i = 0; i < m_listeners.GetCount(); ++i) \
        if (UIStatusEventListener* pL = static_cast<UIStatusEventListener*>(m_listeners.GetAt(i))) \
            if (pL->vfunc_oa0_1() != 0)

// @0x141b0ce20
// MS2-FUNCTIONAL: frame layout of the per-case temporaries differs
void UIStatusEventDispatcher::FUN_141b0ce20(int nEvent, int nValue)
{
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (nEvent == 0)
    {
        ST_EACH_LISTENER(i0, pL)
            pL->vfunc_oa0_3((int)pPlayer->FUN_141670a00(4), (int)pPlayer->FUN_141670a30(4));
        FUN_1409670d0()->FUN_14162a910(TPtr<PCBase>(pPlayer));
    }
    else if (nEvent == 1)
    {
        ST_EACH_LISTENER(i1, pL)
            pL->vfunc_oa0_4((int)pPlayer->FUN_141670a00(7), (int)pPlayer->FUN_141670a30(7));
    }
    else if (nEvent == 2)
    {
        ST_EACH_LISTENER(i2, pL)
            pL->vfunc_oa0_5((int)pPlayer->FUN_141670a00(10), (int)pPlayer->FUN_141670a30(10));
    }
    else if (nEvent == 3)
    {
        ST_EACH_LISTENER(i3, pL)
            pL->vfunc_oa0_6((void*)DAT_143ab28a0, FUN_1404a1bb0()->FUN_140353610((unsigned short)pPlayer->vfunc_78()));
    }
    else if (nEvent == 4)
    {
        ST_EACH_LISTENER(i4, pL)
            pL->vfunc_oa0_7(FUN_141654730(pPlayer), CStringW(FUN_1401a9d70()->FUN_141811980(6, FUN_141654730(pPlayer))));
        FUN_1409670d0()->FUN_14162a840(TPtr<PCBase>(pPlayer));
    }
    else if (nEvent == 5)
    {
        ST_EACH_LISTENER(i5, pL)
            pL->vfunc_oa0_8(CStringW(pPlayer->vfunc_77()));
    }
    else if (nEvent == 6)
    {
        FUN_1411e7660(FUN_1416561a0(pPlayer));
        ST_EACH_LISTENER(i6, pL)
            pL->vfunc_oa0_9((unsigned short)pPlayer->vfunc_78());
        FUN_1409670d0()->FUN_14162aa10(TPtr<PCBase>(pPlayer));
    }
    else if (nEvent == 7)
    {
        ST_EACH_LISTENER(i7, pL)
            pL->vfunc_oa0_10(CStringW(FUN_141656be0(pPlayer)));
    }
    else if (nEvent == 8)
    {
        ST_EACH_LISTENER(i8, pL)
            pL->vfunc_oa0_11((void*)DAT_143ab2898);
    }
    else if (nEvent == 10)
    {
        ST_EACH_LISTENER(i10, pL)
            pL->vfunc_oa0_13((void*)DAT_143ab28f8);
    }
    else if (nEvent == 9)
    {
        ST_EACH_LISTENER(i9, pL)
            pL->vfunc_oa0_12(pPlayer->FUN_14166c930());
    }
    else if (nEvent == 0xb)
    {
        ST_EACH_LISTENER(i11, pL)
            pL->vfunc_oa0_14(FUN_140930240(), nValue);
    }
    else if (nEvent == 0xc)
    {
        ST_EACH_LISTENER(i12, pL)
            pL->vfunc_oa0_20(nValue);
    }
    else if (nEvent == 0xd)
    {
        ST_EACH_LISTENER(i13, pL)
            pL->vfunc_oa0_15(FUN_140930ae0(), nValue);
    }
    else if (nEvent == 0xe)
    {
        ST_EACH_LISTENER(i14, pL)
            pL->vfunc_oa0_21();
    }
    else if (nEvent == 0xf)
    {
        ST_EACH_LISTENER(i15, pL)
            pL->vfunc_oa0_28();
    }
    else if (nEvent == 0x10)
    {
        ST_EACH_LISTENER(i16, pL)
            pL->vfunc_oa0_29();
    }
    else if (nEvent == 0x11)
    {
        ST_EACH_LISTENER(i17, pL)
            pL->vfunc_oa0_30(((int (*)(PCBase*))(*(void***)pPlayer)[0x468 / 8])(pPlayer));
    }
    else if (nEvent == 0x12)
    {
        ST_EACH_LISTENER(i18, pL)
            pL->vfunc_oa0_31((void*)DAT_143ab2958);
    }
}

// @0x141b0e000
void UIStatusEventDispatcher::FUN_141b0e000()
{
    for (size_t i = 0; i < 0x13; ++i)
        FUN_141b0ce20((int)i, 0);
}

// @0x141b0e050
void UIStatusEventDispatcher::FUN_141b0e050()
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i)
    {
        UIStatusEventListener* pL = static_cast<UIStatusEventListener*>(m_listeners.GetAt(i));
        if (pL != 0)
            pL->vfunc_oa0_2();
    }
}

// @0x141b0e0d0
void UIStatusEventDispatcher::FUN_141b0e0d0()
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i)
    {
        UIStatusEventListener* pL = static_cast<UIStatusEventListener*>(m_listeners.GetAt(i));
        if (pL != 0)
            pL->vfunc_oa0_22();
    }
}

// @0x141b0e150
void UIStatusEventDispatcher::FUN_141b0e150()
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i)
    {
        UIStatusEventListener* pL = static_cast<UIStatusEventListener*>(m_listeners.GetAt(i));
        if (pL != 0)
            pL->vfunc_oa0_23();
    }
}

// @0x141b0e1d0
void UIStatusEventDispatcher::FUN_141b0e1d0(int a1)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i)
    {
        UIStatusEventListener* pL = static_cast<UIStatusEventListener*>(m_listeners.GetAt(i));
        if (pL != 0)
            pL->vfunc_oa0_24(a1);
    }
}

// @0x141b0e260
void UIStatusEventDispatcher::FUN_141b0e260(void* a1)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i)
    {
        UIStatusEventListener* pL = static_cast<UIStatusEventListener*>(m_listeners.GetAt(i));
        if (pL != 0)
            pL->vfunc_oa0_25(a1);
    }
}

// @0x141b0e2f0
void UIStatusEventDispatcher::FUN_141b0e2f0(void* a1)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i)
    {
        UIStatusEventListener* pL = static_cast<UIStatusEventListener*>(m_listeners.GetAt(i));
        if (pL != 0)
            pL->vfunc_oa0_26(a1);
    }
}

// @0x141b0e380
void UIStatusEventDispatcher::FUN_141b0e380(int a1, int a2)
{
    for (size_t i = 0; i < m_listeners.GetCount(); ++i)
    {
        UIStatusEventListener* pL = static_cast<UIStatusEventListener*>(m_listeners.GetAt(i));
        if (pL != 0)
            pL->vfunc_oa0_27(a1, a2);
    }
}

// ---- UIStoreDialog ---------------------------------------------------------------------------------------------------

// @0x141b0ebd0
UIStoreDialog::UIStoreDialog()
    : m_188(""), m_190(0), m_194(0), m_198(0), m_1a0(L"")
{
    FUN_140bbf710(&m_1a8);
    FUN_141924170(1);
    m_164 = 1;
    m_5c = 1;
    m_c8 = s_strStoreDialogOpen;
    m_d0 = s_strStoreDialogClose;
}

// @0x141b0ed50
UIStoreDialog::~UIStoreDialog()
{
    FUN_140bbfdd0(&m_1a8);
}

// @0x141b0ee20
CString UIStoreDialog::vfunc_1()
{
    return "StoreDialog";
}

// @0x141b0ee70
int UIStoreDialog::vfunc_oa0_1()
{
    return vfunc_55() == 0;
}

// @0x141b0eec0
int UIStoreDialog::vfunc_65()
{
    int nOpened = UIDialog::vfunc_65();
    if (nOpened != 0)
        m_188 = vfunc_1();
    return nOpened != 0;
}

// @0x141b0ef40
void UIStoreDialog::vfunc_66()
{
    UIDialog::vfunc_66();
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0)
    {
        m_194 = pInv->vfunc_55() == 0 ? 1 : 0;
        if (m_194 == 0)
        {
            ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDlg != 0)
            {
                Unk_OsUIMsg msg;
                msg.FUN_1422b82b0("openWindowPos");
                msg.FUN_1422b7f70(vfunc_48());
                pInv->OnMessage(this, &msg);
            }
        }
        else
        {
            FUN_141275c30(this, pInv, DAT_143b02320, DAT_143b02320);
        }
    }
}

// @0x141b0f0c0
void UIStoreDialog::vfunc_67()
{
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_14180b230(&m_188);
    FUN_141b1feb0(FUN_140967100());
    DAT_143ab2d80.FUN_140de2d60();
    UIDialog::vfunc_67();
    m_80 = 1;
    m_198 = 0;
    m_1a0 = L"";
    m_190 = 0;
    vfunc_47(1);
}

// @0x141b0f1e0
int UIStoreDialog::vfunc_54(void* pCfg)
{
    return UIDialog::vfunc_54(pCfg);
}

// @0x141b0f210
int UIStoreDialog::vfunc_73()
{
    if (FUN_1402c4c90(FUN_14025e7b0() + 8, 0xc) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    if (FUN_141b10af0() == 0)
        return UIDialog::vfunc_73();
    FUN_140d73bc0(0x9e, 0, 0, CStringW(L""));
    return 0;
}

// @0x141b0f2b0
int UIStoreDialog::vfunc_71()
{
    if (FUN_141b10af0() == 0)
        return 0;
    if (m_190 == 0)
        FUN_140d73aa0(FUN_1409eec40(0x2ad), 1, static_cast<IMessageListener*>(this), CStringW(L"askClose"));
    else
        FUN_140d73aa0(FUN_1409eec40(0x2ae), 1, static_cast<IMessageListener*>(this), CStringW(L"askClose"));
    return 1;
}

// @0x141b0f430
void UIStoreDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    vfunc_47(0);
    if (DAT_143ab2d80.FUN_140de2860() == 0)
        DAT_143ab2d80.FUN_140de2b50();
}

// @0x141b0f4f0
void UIStoreDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_198 = 6;
    if (m_30.get() != 0)
    {
        Unk_StScript* pScript = static_cast<Unk_StScript*>(m_30.operator->());
        bool bBound;
        {
            CString strName("m_inputSearch");
            Unk_StInputRef spBound = pScript->FUN_140bbe940(strName, &m_1a8);
            bBound = FUN_140bc0500(&spBound) != 0;
            FUN_140bbfdd0(&spBound);
        }
        if (bBound)
        {
            FUN_140bc0550(&m_1a8)->FUN_1422e0920(StoreDelegate(this, &UIStoreDialog::FUN_141b10bc0));
        }
        CStringW strMoney = FUN_140719a00(DAT_143ab28f8);
        pScript->FUN_140c38f00("initData", m_188, CStringW(strMoney));
    }
}

// @0x141b0f780
void UIStoreDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_140bc0300(&m_1a8, 0);
}

// @0x141b0f7c0
int UIStoreDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() != 0 || dynamic_cast<UIMessageBox*>(pSender) == 0)
        return 0;
    int nAnswer = pMsg->FUN_1422b8a10();
    CStringW strTag = pMsg->FUN_1422b8f40();
    int nResult = 1;
    if (nAnswer == 0)
    {
        if (FUN_1403b3c40(strTag, L"askClose") == 0)
        {
            ATL::CAtlArray<CStringW> aParts;
            if (FUN_14028cb70(strTag, aParts, L",", 2) != 0)
            {
                CStringW strCmd(aParts.GetAt(0));
                CStringW strAmount(aParts.GetAt(1));
                if (!strAmount.IsEmpty())
                {
                    __int64 nAmount = _wtoi64(strAmount);
                    if (FUN_1403b3c40(strCmd, L"deposit") == 0)
                    {
                        if (FUN_1403b3c40(strCmd, L"withdraw") != 0)
                            nResult = FUN_141b11350(nAmount);
                    }
                    else
                    {
                        nResult = FUN_141b11190(nAmount);
                    }
                }
            }
        }
        else
        {
            nResult = 0;
            FUN_14151f200();
            vfunc_67();
        }
    }
    if (nResult != 0)
        FUN_14151f200();
    return 1;
}

// @0x141b0fa40
// MS2-FUNCTIONAL: frame layout of the message box temporaries differs
int UIStoreDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onClickDeposit", szMethod) == 0)
    {
        if (FUN_141b11490() == 0)
        {
            FUN_141275260(0x42, 1, 1);
        }
        else
        {
            MS2Ptr<CMsgBoxData> box = FUN_140d73e40(7, 0x2a9, static_cast<IMessageListener*>(this), CStringW(L"deposit"));
            if (box.get() != 0)
            {
                int nMax = FUN_1412772f0(DAT_143ab2d80.FUN_140de2a80(), 1);
                box->FUN_141a01d30(1, CStringW(L""), nMax, 0, 0);
                FUN_140d73c60(box);
            }
        }
        return 1;
    }
    if (_stricmp("onClickWithDraw", szMethod) == 0)
    {
        if (FUN_141b11490() == 0)
        {
            FUN_141275260(0x42, 1, 1);
        }
        else
        {
            MS2Ptr<CMsgBoxData> box = FUN_140d73e40(7, 0x2aa, static_cast<IMessageListener*>(this), CStringW(L"withdraw"));
            if (box.get() != 0)
            {
                int nMax = FUN_1412772f0(DAT_143ab2d80.FUN_140de2ab0(), 1);
                box->FUN_141a01d30(1, CStringW(L""), nMax, 0, 0);
                FUN_140d73c60(box);
            }
        }
        return 1;
    }
    if (_stricmp("onClickExpandSlot", szMethod) == 0)
    {
        if (FUN_141b114f0() == 0)
        {
            int nStep = DAT_143ab2d80.FUN_140de29b0();
            CStringW strMsg;
            FUN_1409e97f0(&strMsg, 0x2b0, &nStep);
            FUN_140d73aa0(CStringW(L""), 0, 0, strMsg);
        }
        else
        {
            CStringW strQuestion = FUN_14028dee0(0x2a8, (__int64)DAT_143ab2d80.FUN_140de2ae0(), 6);
            Delegate<bool(int, const CMsgBoxData&)> onResult(this, &UIStoreDialog::FUN_141b11c90);
            MS2Ptr<CMsgBoxData> box = FUN_140d74390(CStringW(strQuestion), 1, onResult);
        }
        return 1;
    }
    if (_stricmp("onClickSort", szMethod) == 0)
    {
        DAT_143ab2d80.FUN_140de2bd0();
        return 1;
    }
    if (_stricmp("OnItemSearch", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141b10ed0(data.FUN_1422b8f40());
        return 1;
    }
    if (_stricmp("OnSelected", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141b116d0(CStringW(FUN_1413fa9b0(data.FUN_1422b8f40())));
        return 1;
    }
    return 0;
}

// @0x141b10210
void UIStoreDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (vfunc_55() == 0 && 0 < m_198)
    {
        if ((m_198 & 4) != 0)
            FUN_141b110e0();
        if ((m_198 & 2) != 0)
            FUN_141b11590();
    }
}

// @0x141b10290
int UIStoreDialog::vfunc_13()
{
    if (vfunc_55() != 0)
        return 0;
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0) == 0)
        return 0;
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg == 0)
        return 0;
    if (FUN_140b632f0() != 0)
    {
        CString strKey(m_20);
        if (FUN_140b632f0()->FUN_1422d4e20(strKey) == 0)
            return 0;
    }
    if (FUN_140bc0500(&m_1a8) != 0)
    {
        if (FUN_1422c76c0(FUN_140bc0550(&m_1a8)) == 0)
        {
            FUN_1422c7630(pDlg, 0);
        }
        else
        {
            FUN_141b10ed0(FUN_140bc0550(&m_1a8)->FUN_1422e0b00());
            FUN_1422c7630(pDlg, 1);
            FUN_1422c7630(FUN_140bc0550(&m_1a8), 0);
        }
    }
    return 1;
}

// @0x141b10480
// MS2-FUNCTIONAL: frame layout of the request temporaries differs
void UIStoreDialog::vfunc_80(void* pRequest)
{
    if (FUN_140bc0500(&m_1a8) == 0)
        return;
    Unk_DictRequest request(pRequest);
    Unk_DictRequestValue value;
    if (request.FUN_1401bab90("m_inputSearch", &value) == 1)
    {
        if (value.m_code == 0)
        {
            FUN_141b116d0(CStringW(FUN_1413fa9b0(FUN_140bc0550(&m_1a8)->FUN_1422e0b00())));
        }
        else
        {
            FUN_140bc0550(&m_1a8)->FUN_1422e0bd0(CStringW(L""));
            FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, CStringW(L""));
        }
    }
}

// @0x141b106b0
void UIStoreDialog::vfunc_oa0_13(void* a1)
{
    if (m_30.get() != 0)
    {
        static_cast<Unk_StScript*>(m_30.operator->())->FUN_140acd130("changeMoney", CStringW(FUN_140719a00((__int64)a1)));
    }
}

// @0x141b10780
void UIStoreDialog::vfunc_oa0_9(unsigned short a1)
{
    if (FUN_1422dc390() != 0)
    {
        StoreSlotBag* pBag = FUN_14180b940(FUN_1422c8e90(m_188));
        if (pBag != 0)
            FUN_1422cca90(pBag);
    }
}

// @0x141b107e0
void UIStoreDialog::vfunc_oa0_7(int a1, CStringW s)
{
    if (FUN_1422dc390() != 0)
    {
        StoreSlotBag* pBag = FUN_14180b940(FUN_1422c8e90(m_188));
        if (pBag != 0)
            FUN_1422cca90(pBag);
    }
}

// @0x141b10860
void UIStoreDialog::vfunc_oa0_25(void* a1)
{
    Unk_StBagCtl* pCtl = FUN_140c544d0(FUN_1422c8e90(m_188));
    if (pCtl != 0)
        pCtl->vfunc_11((int)(__int64)a1);
}

// @0x141b108c0
void UIStoreDialog::vfunc_oa0_26(void* a1)
{
    Unk_StBagCtl* pCtl = FUN_140c544d0(FUN_1422c8e90(m_188));
    if (pCtl != 0)
        pCtl->vfunc_12((int)(__int64)a1);
}

// @0x141b10920
void UIStoreDialog::vfunc_9(void* p)
{
    m_198 |= 2;
}

// @0x141b10950
void UIStoreDialog::vfunc_10(void* p)
{
    m_198 |= 2;
}

// @0x141b10980
void UIStoreDialog::vfunc_il13()
{
    m_198 = 6;
}

// @0x141b109a0
void UIStoreDialog::FUN_141b109a0()
{
    if (vfunc_55() == 0 && FUN_1422dc390() != 0)
    {
        m_198 = 6;
        MS2Ptr<ASMovieClip> spEff = FUN_140ba7930("m_expandEff");
        if (spEff.get() != 0)
        {
            spEff->vfunc_3(1);
            spEff->vfunc_12(1);
        }
        FUN_141276180(s_strExpandBankSlot, CString(""));
    }
}

// @0x141b10af0
int UIStoreDialog::FUN_141b10af0()
{
    if (FUN_141b21220(FUN_140967100()) == 0 && vfunc_55() == 0)
        return 1;
    return 0;
}

// @0x141b10b50
CStringW UIStoreDialog::FUN_141b10b50()
{
    return m_1a0;
}

// @0x141b10ba0
void UIStoreDialog::FUN_141b10ba0(int n)
{
    m_190 = n;
}

// @0x141b10bc0
// MS2-FUNCTIONAL: frame layout of the candidate temporaries differs
void UIStoreDialog::FUN_141b10bc0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (FUN_14199f2c0(&m_1a8) != 0)
        return;
    if (FUN_1422c76c0(FUN_140bc0550(&m_1a8)) == 0)
        return;
    CStringW strText = FUN_140bc0550(&m_1a8)->FUN_1422e0b00();
    if (strText.IsEmpty())
        return;
    strText.TrimRight();
    CStringW strSearch = FUN_1413fa9b0(strText);
    ASArray aCandidates(2);                                                 // the exe builds an ASDataProvider-like list (0x1422deec0)
    if (strSearch.GetLength() > 0)
    {
        Unk_StCandSet set;
        FUN_14025b4d0(&set, 10);
        FUN_141b11a10(CStringW(strSearch), &set);
        for (void* pos = FUN_14025e750(&set); pos != 0; FUN_14025e840(&set, &pos))
        {
            CStringW strName = FUN_1413fa9b0(FUN_14025e5c0(&set, pos));
            ASObj row(2);
            row.FUN_1407cbb20("label", FUN_14025e5c0(&set, pos));
            aCandidates.FUN_1422bbf00(row);
        }
        FUN_14025c430(&set);
    }
    unsigned int nRows = aCandidates.FUN_1422bc5d0();
    int nShown = nRows < 6 ? (int)aCandidates.FUN_1422bc5d0() : 5;
    static_cast<ASObj*>(static_cast<AScript*>(FUN_140bc0550(&m_1a8)))->FUN_1407cb9c0("m_rowCount", nShown);
    FUN_140bc0550(&m_1a8)->FUN_140bbeaa0("setCandidates", aCandidates);
}

// @0x141b10eb0
void UIStoreDialog::FUN_141b10eb0()
{
    m_198 = 4;
}

// @0x141b10ed0
void UIStoreDialog::FUN_141b10ed0(CStringW strText)
{
    if (strText.IsEmpty())
    {
        FUN_141b116d0(CStringW(L""));
        return;
    }
    Unk_DictRequest request(0x4e47);
    request.FUN_1401bac80("m_inputSearch", CStringW(strText), 0);
    int nResult = FUN_140d86260()->vfunc_37(&request);
    if (nResult == 1)
    {
        FUN_141b116d0(CStringW(FUN_1413fa9b0(strText)));
    }
    else if (nResult == 2)
    {
        return;
    }
}

// @0x141b110e0
void UIStoreDialog::FUN_141b110e0()
{
    FUN_14180b230(&m_188);
    FUN_14180b170(&m_188, 0, DAT_143ab2d80.FUN_140de1c30());
    if (m_30.get() != 0)
        m_30->Invoke("updateBag");
    m_198 &= ~4;
}

// @0x141b11190
int UIStoreDialog::FUN_141b11190(const __int64& nAmount)
{
    if (DAT_143ab2898 < nAmount)
    {
        FUN_141275260(0x2b6, 1, 1);
        return 0;
    }
    __int64 nStore = DAT_143ab2d80.FUN_140de2a80();
    if (nAmount < 1 || nStore < nAmount)
    {
        __int64 nMax = FUN_1402e49a0(&nStore, &DAT_143ab2898);
        if (nAmount == 0)
        {
            FUN_141275260(0x2b2, 1, 1);
        }
        else
        {
            int nKind = 1;
            FUN_14199e740(0xee, 1, 1, &nKind, FUN_1409404f0(nMax));
        }
        return 0;
    }
    __int64 nTotal = DAT_143ab28f8 + nAmount;
    if (nTotal < 2000000001)
    {
        DAT_143ab2d80.FUN_140de2c40(1, nAmount);
        return 1;
    }
    FUN_140961010(0x2b3, 1, 1, FUN_140763e10(2000000000));
    return 0;
}

// @0x141b11350
int UIStoreDialog::FUN_141b11350(const __int64& nAmount)
{
    if (DAT_143ab28f8 < nAmount)
    {
        FUN_141275260(0x2b5, 1, 1);
        return 0;
    }
    __int64 nStore = DAT_143ab2d80.FUN_140de2ab0();
    if (nAmount < 1 || nStore < nAmount)
    {
        __int64 nMax = FUN_1402e49a0(&nStore, &DAT_143ab28f8);
        if (nAmount == 0)
        {
            FUN_141275260(0x2b4, 1, 1);
        }
        else
        {
            int nKind = 1;
            FUN_14199e740(0xee, 1, 1, &nKind, FUN_1409404f0(nMax));
        }
        return 0;
    }
    DAT_143ab2d80.FUN_140de2c40(0, nAmount);
    return 1;
}

// @0x141b11490
int UIStoreDialog::FUN_141b11490()
{
    if (DAT_143ab2d80.FUN_140de27c0() == 0)
    {
        PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0 && pPlayer->FUN_14166ce30() == 0)
            return 1;
    }
    return 0;
}

// @0x141b114f0
bool UIStoreDialog::FUN_141b114f0()
{
    return DAT_143ab2d80.FUN_140de2970() == 0;
}

// @0x141b11520
void UIStoreDialog::FUN_141b11520()
{
    Unk_DictPlatform* pPlatform = FUN_140d86260();
    if (((char (*)(Unk_DictPlatform*, __int64))(*(void***)pPlatform)[0x140 / 8])(pPlatform, DAT_143ab2d80.FUN_140de2ae0()) == 1)
        DAT_143ab2d80.FUN_140de2ce0();
    else
        FUN_141add1f0(FUN_1403ed2b0());
}

// @0x141b11590
void UIStoreDialog::FUN_141b11590()
{
    unsigned nSlots = DAT_143ab2d80.FUN_140de1c00();
    unsigned nUsed = DAT_143ab2d80.FUN_140de1c30();
    MS2Ptr<Unk_StExpandClip> spText = FUN_140e6d820("m_expand");
    if (spText.get() != 0)
    {
        spText->FUN_1422e4a50(FUN_1406e7810(L"{0}/{1}", nSlots, nUsed));
        spText->vfunc_24(1);
    }
    m_198 &= ~2;
}

// @0x141b116d0
// MS2-FUNCTIONAL: frame layout of the message box temporaries differs
void UIStoreDialog::FUN_141b116d0(CStringW strText)
{
    m_1a0 = strText;
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        StoreSlotBag* pBag = FUN_14180b940(FUN_1422c8e90(m_188));
        if (pBag != 0)
        {
            int nIndex = pBag->FUN_14180b3e0(CStringW(strText));
            if (nIndex > -1)
                reinterpret_cast<Unk_StScript*>(pDlg)->FUN_1409ba030("moveScroll", nIndex);
            if (nIndex == -1)
            {
                if (FUN_140bc0500(&m_1a8) != 0)
                {
                    FUN_1422c7630(FUN_140bc0550(&m_1a8), 0);
                    FUN_140bc0550(&m_1a8)->FUN_1422e0bd0(CStringW(L""));
                    FUN_140bc0550(&m_1a8)->vfunc_24(1);
                }
                MS2Ptr<CMsgBoxData> box = FUN_140d73e40(0, 0x937, 0, CStringW(L""));
                if (box.get() != 0)
                {
                    box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIStoreDialog::FUN_141b11ba0));
                    FUN_140d73c60(box);
                }
            }
        }
    }
}

// @0x141b11a10
void UIStoreDialog::FUN_141b11a10(CStringW strText, Unk_StCandSet* pOut)
{
    ATL::CAtlArray<void*> aEntries;
    DAT_143ab2d80.FUN_140de1fd0(&aEntries);
    for (unsigned i = 0; i < FUN_140720ca0_count(&aEntries); ++i)
    {
        Unk_StItemEntry entry;
        FUN_1402034d0(&entry, FUN_140c3c720(&aEntries, i));
        if (FUN_1401c0050(&entry, 0) == 0)
        {
            CStringW strItem;
            FUN_140527b10(FUN_1401c0180(&entry), &strItem);
            CStringW strNorm = FUN_1413fa9b0(strItem);
            strText.MakeLower();
            strNorm.MakeLower();
            if (strNorm.Find(strText, 0) != -1)
            {
                if (FUN_1409eea60(pOut, strItem) == 0)
                    FUN_14025d670(pOut, strItem);
            }
        }
        FUN_1401bfde0(&entry);
    }
}

// @0x141b11ba0
bool UIStoreDialog::FUN_141b11ba0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDlg != 0 && FUN_140bc0500(&m_1a8) != 0)
        {
            FUN_140b632f0()->FUN_1422d4dd0(CString(m_20));
            FUN_1422c7630(FUN_140bc0550(&m_1a8), 1);
        }
    }
    return true;
}

// @0x141b11c90
bool UIStoreDialog::FUN_141b11c90(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        FUN_141b11520();
    return true;
}
