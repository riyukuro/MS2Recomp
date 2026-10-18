// blackmarketpage.h - PLACEHOLDER for the pages of the black market window (UIBlackMarketDialog). NOT an original
// header. The pages are defined in ?\uiblackmarketpage.cpp / ?\uiblackmarketpagemeso.cpp (0x140f0bfe0-0x140f21590);
// only what UIBlackMarketDialog touches is declared. Layout proved by the base ctor 0x140f0bfe0 (size 0x60), the
// derived ctors 0x140f0c7e0 (0x100), 0x140f11850 (0xd0), 0x140f18620 (0xc8) and 0x140f1add0 (0xe0), and the operator new
// sizes in the dialog ctor. Member names are invented; none of the ctors/dtors are defined here.
//
// BlackMarketPage vftable 0x142e6fc00: 0 ~ (??_G 0x140f0c680), 1 OnInit 0x140f0c1c0 (binds "m_itemList"), 2 reset
// 0x140f0c340, 3 and 4 pure, 5 empty 0x140f0c3a0, 6 0x140f0c3b0 (returns a null market entry).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class CInPacket;
class Unk_BlackMarketEntry;
class BlackMarketPageItemSearch;
class BlackMarketPageItemRegister;
class BlackMarketPageMesoSearch;
class BlackMarketPageMesoRegister;

class BlackMarketPage : public CPtred
{
public:
    explicit BlackMarketPage(const CString& strName);               // 0x140f0bfe0
    virtual ~BlackMarketPage();                                     //  0 0x140f0c090 (??_G 0x140f0c680)
    virtual bool vfunc_1();                                         //  1 0x140f0c1c0 OnInit: bind the page root and its "m_itemList"
    virtual void vfunc_2();                                         //  2 0x140f0c340 reset
    virtual void vfunc_3() = 0;                                     //  3 the page was selected
    virtual int vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs) = 0;   //  4 AS -> C++ call
    virtual void vfunc_5();                                         //  5 0x140f0c3a0 empty (per frame)
    virtual void vfunc_6(MS2Ptr<Unk_BlackMarketEntry>* pOut, unsigned __int64 nId);   //  6 0x140f0c3b0 entry of an id

    void FUN_140f0c150(MS2Ptr<AScript> spRoot);                     // m_20 = spRoot (the callee destroys it)
    void FUN_140f0c1a0(int nMovieId);                               // m_50 = nMovieId

    MS2_LAYOUT_FRIEND;
    int m_18;                                                       // +0x18
    MS2Ptr<AScript> m_20;                                           // +0x20 the dialog's root object
    MS2Ptr<AScript> m_30;                                           // +0x30 the page's display object
    MS2Ptr<AScript> m_40;                                           // +0x40 "m_itemList"
    int m_50;                                                       // +0x50 movie id (2)
    CString m_58;                                                   // +0x58 child name
};
MS2_CHECK_SIZE(BlackMarketPage, 0x60);
MS2_CHECK_OFFSET(BlackMarketPage, m_20, 0x20);
MS2_CHECK_OFFSET(BlackMarketPage, m_50, 0x50);

// The market record of a listed item: the item itself is a MS2Ptr<CItem> at +0x38 (the size is not recovered).
class CItem;
class Unk_BlackMarketEntry : public CPtred
{
public:
    MS2_LAYOUT_FRIEND;
    void* m_pad_18;
    void* m_pad_20;
    void* m_pad_28;
    void* m_pad_30;
    MS2Ptr<CItem> m_spItem;                                         // +0x38
};
MS2_CHECK_OFFSET(Unk_BlackMarketEntry, m_spItem, 0x38);

class BlackMarketPageItemSearch : public BlackMarketPage
{
public:
    virtual ~BlackMarketPageItemSearch();
    virtual void vfunc_3();
    virtual int vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    BlackMarketPageItemSearch();                                    // 0x140f0c7e0
    void FUN_140f0d630(int nMsg, void* p2, void* p3);               // 0x140f0d630 key / mouse message
    void FUN_140f0d990(int nA, int nB, void* p);                    // 0x140f0d990 rebuild "buildItemList"
    void FUN_140f0db00(MS2Ptr<Unk_BlackMarketEntry> spEntry, int n);   // 0x140f0db00 (the callee destroys the entry)
    void FUN_140f0de60(int nA, int nB, void* p);                    // 0x140f0de60
    void FUN_140f0dfe0(int nFlag);                                  // 0x140f0dfe0
    char m_pad_60[0x100 - 0x60];
};
MS2_CHECK_SIZE(BlackMarketPageItemSearch, 0x100);

class BlackMarketPageItemRegister : public BlackMarketPage
{
public:
    virtual ~BlackMarketPageItemRegister();
    virtual void vfunc_3();
    virtual int vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    BlackMarketPageItemRegister();                                  // 0x140f11850
    void FUN_140f12d40(MS2Ptr<Unk_BlackMarketEntry> spEntry);       // 0x140f12d40 (the callee destroys the entry)
    void FUN_140f13030(MS2Ptr<Unk_BlackMarketEntry> spEntry, int n);   // 0x140f13030
    void FUN_140f132c0(void* p);                                    // 0x140f132c0 "buildOwnerItemList"
    void FUN_140f133b0(int nFlag);                                  // 0x140f133b0
    void FUN_140f13420(void* p2, void* p3);                         // 0x140f13420
    void FUN_140f137a0(int nA, int nB, void* p);                    // 0x140f137a0
    char m_pad_60[0xd0 - 0x60];
};
MS2_CHECK_SIZE(BlackMarketPageItemRegister, 0xd0);

class BlackMarketPageMesoSearch : public BlackMarketPage
{
public:
    virtual ~BlackMarketPageMesoSearch();
    virtual void vfunc_3();
    virtual int vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    explicit BlackMarketPageMesoSearch(const CString& strName);     // 0x140f18620
    char m_pad_60[0xc8 - 0x60];
};
MS2_CHECK_SIZE(BlackMarketPageMesoSearch, 0xc8);

class BlackMarketPageMesoRegister : public BlackMarketPage
{
public:
    virtual ~BlackMarketPageMesoRegister();
    virtual void vfunc_3();
    virtual int vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    BlackMarketPageMesoRegister();                                  // 0x140f1add0
    char m_pad_60[0xe0 - 0x60];
};
MS2_CHECK_SIZE(BlackMarketPageMesoRegister, 0xe0);
