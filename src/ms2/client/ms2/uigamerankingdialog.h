// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uigamerankingdialog.h (name assumed: the
// .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIGameRankingDialog ("GameRankingDialog", UI type 0x4f24): the ranking boards of the game (trophies, boss records,
// arcade / UGC / colosseum seasons, guild boards, ...). The categories come from Table/gameRankingCategory.xml (plus the
// chart tables the boards are built from); every board has season tabs (GameRankingTabData); the page of rows comes from
// the CGameRankingCli service (gamerankingcli.h) and is pushed to the "m_items" list of the swf.
// RTTI .?AVUIGameRankingDialog@@, 0x250 bytes, vftables UIDialog / +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset>.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/gamerankingcli.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/uidialog.h"

class ASArray;
class ASData;
class ASObj;
class CMsgBoxData;
class Unk_RankList;
class Unk_RankTab;
class Unk_RankInput;

// ---- the data of the boards ----

// A category of the left list (and its sub categories: parent id at +0x1c). Table row of gameRankingCategory.xml or
// built from a chart table (arcade modes, colosseum bosses, ...).
class GameRankingCategory : public CPtred
{
public:
    GameRankingCategory();                                  // 0x140e366f0
    virtual ~GameRankingCategory();                         //  0 0x140e36b30 (??_G 0x140e370a0)

    int m_nId;                                              // +0x18 "categoryid" (sub categories: parent * 10 + n)
    int m_nParent;                                          // +0x1c parent category id (0 = top level)
    int m_nSub;                                             // +0x20 sub id of the board (job / mode / boss id)
    int m_nType;                                            // +0x24 board type (see the switch in AddCategory)
    CStringW m_strLabel;                                    // +0x28
    CStringW m_strImage;                                    // +0x30 icon image path
    CString m_strUrl;                                       // +0x38 lower-cased url piece of the web guide
};
MS2_CHECK_SIZE(GameRankingCategory, 0x40);

// One season tab of a board.
class GameRankingTabData : public CPtred
{
public:
    GameRankingTabData();                                   // 0x140e367d0
    virtual ~GameRankingTabData();                          //  0 0x140e36b80 (??_G 0x140e370e0)

    CStringW m_strLabel;                                    // +0x18
    CStringW m_strTooltip;                                  // +0x20
    int m_nSeasonID;                                        // +0x28
};
MS2_CHECK_SIZE(GameRankingTabData, 0x30);

// ---- unit-local smart pointers (16 bytes: field 0 unused, field 1 the pointee) ----

CPtred* FUN_1401ba820(CPtred* p);                           // marks a freshly allocated object (sets the count to 1)

// Pointer to a CPtred-derived object (the CPtred is the pointee). Members are defined out of the class so that they stay
// out-of-line COMDATs like the exe's (one instance per T).
template <class T>
class Unk_RankPtr
{
public:
    Unk_RankPtr();                                          // m_p = NULL (0x140e362f0 for GameRankingCategory)
    Unk_RankPtr(Unk_RankPtr&& o);                            // move from an rvalue (0x140e36310)
    Unk_RankPtr(const Unk_RankPtr& o);                      // copy + AddRef (0x140e36340)
    Unk_RankPtr(const Unk_RankNewTag&);                     // a fresh object (0x140e36380)
    Unk_RankPtr(int);                                       // NULL (0x140e363b0)
    ~Unk_RankPtr();                                         // 0x140e369c0
    Unk_RankPtr& operator=(const Unk_RankPtr& o);           // 0x140e36bc0 (for the tab data)
    operator T*() const;                                    // raw getter for null tests (0x140e36e40)
    T* operator->() const;                                  // 0x140e36ea0
    bool operator!() const;                                 // m_p == NULL (0x140e36c40)
    bool operator==(T* p) const;                            // 0x140e36cd0

private:
    void AddRef() const;
    void AddRefImpl(void*) const;
    static void Reference(T* p);
    void Release();
    void ReleaseImpl(void*);
    void Make();
    static T* Create(void*);
    static T* Allocate(void*);
    void* m_00;
    T* m_p;
};

template <class T> Unk_RankPtr<T>::Unk_RankPtr() { m_p = 0; }
template <class T> Unk_RankPtr<T>::Unk_RankPtr(Unk_RankPtr&& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> Unk_RankPtr<T>::Unk_RankPtr(const Unk_RankPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_RankPtr<T>::Unk_RankPtr(const Unk_RankNewTag&) { m_p = 0; Make(); }
template <class T> Unk_RankPtr<T>::Unk_RankPtr(int) { m_p = 0; }
template <class T> Unk_RankPtr<T>::~Unk_RankPtr() { Release(); }
template <class T> Unk_RankPtr<T>& Unk_RankPtr<T>::operator=(const Unk_RankPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> Unk_RankPtr<T>::operator T*() const { return m_p; }
template <class T> T* Unk_RankPtr<T>::operator->() const { return m_p; }
template <class T> bool Unk_RankPtr<T>::operator!() const { return m_p == 0 ? 1 : 0; }
template <class T> bool Unk_RankPtr<T>::operator==(T* p) const { return m_p == p; }
template <class T> void Unk_RankPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_RankPtr<T>::AddRefImpl(void*) const { Reference(m_p); }
template <class T> void Unk_RankPtr<T>::Reference(T* p) { CPtred::AddRefPtred(p); }
template <class T> void Unk_RankPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> void Unk_RankPtr<T>::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0) {
        Reference(m_p);
        CPtred::DeletePtred(m_p);
    }
}
template <class T> void Unk_RankPtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> T* Unk_RankPtr<T>::Create(void*) { return static_cast<T*>(FUN_1401ba820(Allocate(0))); }
template <class T> T* Unk_RankPtr<T>::Allocate(void*) { return new T; }

typedef Unk_RankPtr<GameRankingCategory> Unk_RankCatPtr;
typedef Unk_RankPtr<GameRankingTabData> Unk_RankTabPtr;
typedef ATL::CAtlArray<Unk_RankTabPtr> Unk_RankTabArray;

// Pointer to a value in a TPtredDummy box (the CPtred header sits 0x18 bytes before the pointee).
template <class T>
class Unk_RankBoxPtr
{
public:
    Unk_RankBoxPtr();                                       // 0x140e36530
    Unk_RankBoxPtr(const Unk_RankNewTag&);                  // a fresh box (0x140e364e0)
    Unk_RankBoxPtr(Unk_RankBoxPtr& o);                      // steal (0x140e364b0)
    Unk_RankBoxPtr(int);                                    // NULL (0x140e36510)
    ~Unk_RankBoxPtr();                                      // 0x140e36a20
    Unk_RankBoxPtr& operator=(const Unk_RankBoxPtr& o);     // 0x140e36c00
    T* operator->() const;                                  // 0x140e36ec0
    bool operator!() const;
    bool operator==(T* p) const;                            // 0x140e36d50

private:
    void AddRef() const;
    void AddRefImpl(void*) const;
    static void Reference(TPtredDummy<T>* p);
    void Release();
    void ReleaseImpl(void*);
    void Make();
    static TPtredDummy<T>* Allocate(void*);
    static T* Value(TPtredDummy<T>* p);
    static TPtredDummy<T>* Owner(T* p);
    static T* Create(void*);
    void* m_00;
    T* m_p;
};

template <class T> Unk_RankBoxPtr<T>::Unk_RankBoxPtr() { m_p = 0; }
template <class T> Unk_RankBoxPtr<T>::Unk_RankBoxPtr(const Unk_RankNewTag&) { m_p = 0; Make(); }
template <class T> Unk_RankBoxPtr<T>::Unk_RankBoxPtr(Unk_RankBoxPtr& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> Unk_RankBoxPtr<T>::Unk_RankBoxPtr(int) { m_p = 0; }
template <class T> Unk_RankBoxPtr<T>::~Unk_RankBoxPtr() { Release(); }
template <class T> Unk_RankBoxPtr<T>& Unk_RankBoxPtr<T>::operator=(const Unk_RankBoxPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> T* Unk_RankBoxPtr<T>::operator->() const { return m_p; }
template <class T> bool Unk_RankBoxPtr<T>::operator!() const { return m_p == 0 ? 1 : 0; }
template <class T> bool Unk_RankBoxPtr<T>::operator==(T* p) const { return m_p == p; }
template <class T> void Unk_RankBoxPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_RankBoxPtr<T>::AddRefImpl(void*) const { Reference(Owner(m_p)); }
template <class T> void Unk_RankBoxPtr<T>::Reference(TPtredDummy<T>* p) { CPtred::AddRefPtred(p); }
template <class T> void Unk_RankBoxPtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> void Unk_RankBoxPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> void Unk_RankBoxPtr<T>::ReleaseImpl(void*)
{
    TPtredDummy<T>* owner = Owner(m_p);
    if (CPtred::ReleasePtred(owner) == 0) {
        Reference(owner);
        CPtred::DeletePtred(owner);
    }
}
template <class T> TPtredDummy<T>* Unk_RankBoxPtr<T>::Allocate(void*) { return new TPtredDummy<T>(); }
template <class T> T* Unk_RankBoxPtr<T>::Value(TPtredDummy<T>* p) { return p == NULL ? NULL : &p->value; }
template <class T> TPtredDummy<T>* Unk_RankBoxPtr<T>::Owner(T* p)
{
    return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value));
}
template <class T> T* Unk_RankBoxPtr<T>::Create(void*)
{
    return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0))));
}

typedef Unk_RankBoxPtr<Unk_RankTabArray> Unk_RankTabsPtr;
// the exe's map passes the int key by const reference
struct Unk_RankKeyTraits : ATL::CElementTraits<int> { typedef const int& INARGTYPE; };

// A season record of the season table (CSeasonData-like; only the fields the dialog reads).
struct Unk_RankSeason
{
    char m_pad_00[0x1c];
    int m_nSeason;                                          // +0x1c season number (yyyyss / 100 = ...)
    char m_pad_20[0x10];
    void* m_start;                                          // +0x30 start time
    char m_pad_38[8];
    void* m_end;                                            // +0x40 end time
};

// 16-byte smart pointer of a season record (copy 0x140795e50, dtor 0x1404eec20).
struct Unk_RankSeasonPtr
{
    Unk_RankSeasonPtr() : m_00(0), m_p(0) {}                // 0x140e362f0 (folded with the other m_p = 0 ctors)
    Unk_RankSeasonPtr(const Unk_RankSeasonPtr& o);          // 0x140795e50
    ~Unk_RankSeasonPtr();                                   // 0x1404eec20
    Unk_RankSeason* FUN_1404f0bf0() const;                  // the record
    bool FUN_1404f01a0(int) const;                          // == NULL
    void* m_00;
    Unk_RankSeason* m_p;
};

// ---- the dialog ----

class UIGameRankingDialog : public UIDialog
{
public:
    UIGameRankingDialog();                                                                          // 0x140e2cc90
    virtual ~UIGameRankingDialog();                                                                 //  0 0x140e2cdc0 (??_G 0x140e37120)
    virtual CString vfunc_1();                                                                      //  1 0x140e2cec0
    virtual int vfunc_13();                                                                         // 13 0x140e2da50 search input shortcut
    virtual void OnLoadComplete();                                                                  // 22 0x140e2cfa0
    virtual void vfunc_26();                                                                        // 26 0x140e2cf60
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x140e2d0d0
    virtual int vfunc_48() { return 0x4f24; }                                                       // 48 (0x140e37c30, COMDAT)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);                           // 49 0x140e2dc70 party member tooltip
    virtual int vfunc_65();                                                                         // 65 0x140e2cf10
    virtual void vfunc_67();                                                                        // 67 0x140e2cf40
    virtual void vfunc_72();                                                                        // 72 0x140e2dd60 marks downloaded: refresh
    virtual int vfunc_73();                                                                         // 73 0x140e2dd00

    // non-virtual members (this = UIGameRankingDialog*)
    void FUN_140e2dec0(int nMsg);                                                                   // refresh result visibility after a message
    void FUN_140e2dfc0(int nType, int nSub);                                                        // select the board of (type, sub)
    void FUN_140e2e030(CString strUrl);                                                             // select the board of a web guide url
    void LoadGameRankingCategory();                                                                           // load gameRankingCategory.xml
    void FUN_140e2e540();                                                                           // select the first category
    void FUN_140e2e620();                                                                           // build the season tabs of every board type
    Unk_RankTabPtr FUN_140e304c0(CStringW strLabel, CStringW strTooltip, int nSeason);             // new tab data
    void FUN_140e305a0(Unk_RankCatPtr spCategory);                                                  // add a category (+ its sub categories)
    void FUN_140e31140();                                                                           // push the category list to the swf
    void FUN_140e31510(Unk_RankCatPtr spCategory);                                                  // push the tabs of a category
    void FUN_140e31910(int nFlag);                                                                  // push the rank info (description, my rank)
    void FUN_140e31b00();                                                                           // push the rows of the page
    void FUN_140e32a00(Unk_RankCatPtr spCategory, ASArray& arr);                                    // append the sub categories
    int FUN_140e32c30(int nCategoryId);                                                             // has sub categories
    void FUN_140e32d30(ATL::CAtlList<Unk_RankCatPtr>& list);                                        // collect the top level categories
    void FUN_140e32df0(ATL::CAtlList<Unk_RankCatPtr>& list);                                        // collect the sub categories
    void FUN_140e32eb0();                                                                           // drop the rows, clear the swf list
    void FUN_140e32f30(int nPush, int nForce, CStringW strSearch);                                  // request the page
    Unk_RankTabsPtr FUN_140e33240(Unk_RankCatPtr spCategory);                                       // build the tabs of a category
    Unk_RankTabPtr FUN_140e339e0(int nType, int nIndex);                                            // the tab of (type, index)
    CStringW FUN_140e33ae0(Unk_RankCatPtr spCategory, Unk_RankSeasonPtr spSeason);                  // season label
    void FUN_140e33e20();                                                                           // select the category in the swf list
    void FUN_140e33fb0(ASObj& obj, Unk_RankCatPtr spCategory, int nFlag);                           // my rank text and recommender
    void FUN_140e34830(ASObj& obj, Unk_RankCatPtr spCategory);                                      // description text
    void FUN_140e34bb0(ASObj& obj, Unk_RankCatPtr spCategory);                                      // job image / icon
    void FUN_140e34ce0(int nPage, int nPages);                                                      // "setButtonPage"
    void FUN_140e34d50(CStringW strSearch);                                                         // search
    void FUN_140e34eb0(Unk_RankPageReq spReply);                                                    // a page arrived
    Unk_RankCatPtr FUN_140e350c0(int nCategoryId);                                                  // find a category
    void FUN_140e351d0(int nCategoryId, Unk_RankKey* pKey);                                         // key of a board
    void FUN_140e35350(int nCategoryId, Unk_RankKey* pKey);                                         // key of a board (second variant)
    int FUN_140e354d0(int nType, int nSub);                                                         // category id of (type, sub)
    void FUN_140e355d0(Scaleform::GFx::Value* pRet, int nRow, int nType);                           // party member tooltip
    bool FUN_140e359e0(int nBtn, const CMsgBoxData& data);                                         // move-home confirm result

    MS2Ptr<Unk_RankList> FUN_140c02900(const CString& strName);                                     // bind a list child
    MS2Ptr<Unk_RankTab> FUN_140c02870(const CString& strName);                                      // bind a tab child
    MS2Ptr<Unk_RankInput> FUN_140e35bd0(const CString& strName);                                  // find the search input

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<Unk_RankCatPtr> m_categories;             // +0x178 (block size 10)
    ATL::CAtlMap<int, Unk_RankTabsPtr, Unk_RankKeyTraits> m_tabs;              // +0x1a8 board type -> tabs (17 bins, 0.75, 0.25, 2.25, block 10)
    ATL::CAtlArray<Unk_RankDataPtr> m_rows;                 // +0x1f0 the rows of the page
    ATL::CAtlArray<CString> m_missingMarks;                 // +0x210 mark files still downloading
    MS2Ptr<Unk_RankList> m_items;                           // +0x230 the "m_items" list
    int m_nCategory;                                        // +0x240
    int m_nPage;                                            // +0x244
    int m_nTab;                                             // +0x248
};
MS2_CHECK_SIZE(UIGameRankingDialog, 0x250);
MS2_CHECK_OFFSET(UIGameRankingDialog, m_categories, 0x178);
MS2_CHECK_OFFSET(UIGameRankingDialog, m_tabs, 0x1a8);
MS2_CHECK_OFFSET(UIGameRankingDialog, m_rows, 0x1f0);
MS2_CHECK_OFFSET(UIGameRankingDialog, m_missingMarks, 0x210);
MS2_CHECK_OFFSET(UIGameRankingDialog, m_items, 0x230);
MS2_CHECK_OFFSET(UIGameRankingDialog, m_nTab, 0x248);
