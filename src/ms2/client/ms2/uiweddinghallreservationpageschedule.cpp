// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingHallReservationPageSchedule: the date/time page of the
// wedding hall reservation dialog (see uiweddinghallreservationpage.h).
// MS2-UNIT: ?\uiweddinghallreservationpageschedule.cpp
// MS2-RANGE: 0x140fe33a0-0x140fe4650 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddinghallreservationpageschedule.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiweddinghallreservationpage.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// ---- exe callees ----
void* FUN_1409eed90();                                                      // the singleton of the own character
__int64 FUN_140869440();                                                    // the current time source
void FUN_140fdc030(UIDialog* pDialog);
void FUN_140fdbf70(UIDialog* pDialog);
void FUN_140fdc130(UIDialog* pDialog, __int64 nTime);                       // tells the dialog the chosen time
void FUN_140fdc160(UIDialog* pDialog, bool bPrivate);                       // tells the dialog the public/private choice
void* FUN_140fdca40(UIDialog* pDialog);                                     // the reservation target
int FUN_140fdca20(UIDialog* pDialog);
void FUN_1412751f0(const CStringW& strText, int a, int b);                  // notice
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
CStringW FUN_140b8e910(const CMsTime& time);                                // date text
bool FUN_14086ab70(CMsTime tmOld, CMsTime tmNew, int nBaseHour);
void TruncateToDay(CMsTime& time);                                          // 0x14086a6c0 (commonfiles/timeutil.cpp)
void AddDays(CMsTime& time, long days);                                     // 0x14086a7e0
void AddHours(CMsTime& time, int hours);                                    // 0x14086a830
extern unsigned DAT_143ab2830;                                              // the own character's type

// The own wedding record: +0x20 is the reservation kind (1 = own wedding, 2 = guest), +0x28 the wedding time.
struct Unk_SchedTarget
{
    char m_pad_00[0x20];
    int m_nKind;                                                            // +0x20
    int m_pad_24;
    __int64 m_nTime;                                                        // +0x28
};
Unk_SchedTarget* FUN_140d295d0(void* pCharacter);

// The hall table: is the hour taken?
class Unk_SchedHallTable { public: bool FUN_140909870(unsigned nType, const CMsTime& time); };
Unk_SchedHallTable* FUN_1409023c0();

// The public/private radio group and the prev/next buttons (AS wrappers of the page movie).
class Unk_SchedGroup : public ASDisplayObject { public: void FUN_1422e8ce0(int nValue, int nFlag); };
Unk_SchedGroup* FUN_1422e8920(void* pMem, const Scaleform::GFx::Value& v, int nMovieId);   // ctor
class Unk_SchedButton : public ASDisplayObject { public: void FUN_1422c1fe0(bool bEnable); };

void FUN_14015b020(CPtred*);
int FUN_140159bc0(CPtred*);
void FUN_140159ba0(CPtred*);
// The smart pointer of the group wrapper (16 bytes, the pointer at +8).
template <class T> class Unk_WedPtr
{
public:
    Unk_WedPtr() : p(0) {}
    Unk_WedPtr(int) : p(0) {}
    Unk_WedPtr(T* q) : p(q) { AddRef(); }
    Unk_WedPtr(Unk_WedPtr&& q) : p(q.p) { q.p = 0; }
    ~Unk_WedPtr() { Release(); }
    T* get() const { return p; }
    operator T*() const { return p; }
private:
    void AddRef() const { if (p) ReferenceImpl((void*)0); }
    static void Reference(T* q) { FUN_14015b020(q); }
    void ReferenceImpl(void*) const { Reference(p); }
    void Release() { if (p) { ReleaseImpl((void*)0); p = 0; } }
    void ReleaseImpl(void*) { if (FUN_140159bc0(p) == 0) { Reference(p); FUN_140159ba0(p); } }
    void* m_0;
    T* p;
};

template <class T> Unk_WedPtr<T> FUN_140fe42c0(int nMovieId, const Scaleform::GFx::Value& v);

// The AScript with this unit's child getter (one COMDAT per wrapper class).
class Unk_SchedScript : public AScript
{
public:
    template <class T> Unk_WedPtr<T> FUN_140fe4370(const CString& strName);
};

class UIWeddingHallReservationPageSchedule : public UIWeddingHallReservationPage
{
public:
    UIWeddingHallReservationPageSchedule(UIDialog* pDialog);        // 0x140fe33a0
    virtual ~UIWeddingHallReservationPageSchedule();                // 0x140fe3410 (deleting dtor 0x140fe4500)

    virtual bool vfunc_1();                                         // 0x140fe3440
    virtual void vfunc_2();                                         // 0x140fe3670
    virtual bool vfunc_4(__int64 a1, __int64 a2, int a3);           // 0x140fe3690
    virtual void vfunc_5();                                         // 0x140fe3950
    virtual void vfunc_6();                                         // 0x140fe3980
    virtual void vfunc_7();                                         // 0x140fe3a20
    virtual CString vfunc_8();                                      // 0x140fe3a90
    virtual CStringW vfunc_9();                                     // 0x140fe3ae0
    virtual CStringW vfunc_10(bool bStart);                         // 0x140fe3b50
    virtual bool vfunc_12();                                        // 0x140fe3c10

    CMsTime m_date;                                                 // +0x30 the shown day
    bool m_bPrivate;                                                // +0x40
    __int64 m_nTime;                                                // +0x48 the chosen time (0: none)
};
MS2_CHECK_SIZE(UIWeddingHallReservationPageSchedule, 0x50);

void FUN_140fe3c40(UIWeddingHallReservationPageSchedule* pPage);

// @0x140fe33a0
UIWeddingHallReservationPageSchedule::UIWeddingHallReservationPageSchedule(UIDialog* pDialog) : UIWeddingHallReservationPage(pDialog)
{
    m_bPrivate = false;
    m_nTime = 0;
}

// @0x140fe3410
UIWeddingHallReservationPageSchedule::~UIWeddingHallReservationPageSchedule()
{
}

// MS2-FUNCTIONAL: frame 0x30 larger: temp slots of the two child handles/CMsTime differ
// @0x140fe3440
bool UIWeddingHallReservationPageSchedule::vfunc_1()
{
    if (!UIWeddingHallReservationPage::vfunc_1())
        return false;
    if (m_nTime != 0)
    {
        m_date = CMsTime(m_nTime);
        TruncateToDay(m_date);
    }
    FUN_140fe3c40(this);
    {
        Unk_WedPtr<Unk_SchedGroup> spPublic = static_cast<Unk_SchedScript*>(m_pScript.operator->())->FUN_140fe4370<Unk_SchedGroup>("m_publicGroup");
        if (spPublic)
            spPublic.get()->FUN_1422e8ce0(m_bPrivate == 0, 1);
    }
    if (m_nTime != 0)
    {
        Unk_WedPtr<Unk_SchedGroup> spTime = static_cast<Unk_SchedScript*>(m_pScript.operator->())->FUN_140fe4370<Unk_SchedGroup>("m_timeGroup");
        if (spTime)
        {
            CMsTime tTime(m_nTime);
            int nHour = tTime.GetHour();
            spTime.get()->FUN_1422e8ce0(nHour, 1);
        }
    }
    return true;
}

// @0x140fe3670
void UIWeddingHallReservationPageSchedule::vfunc_2()
{
    UIWeddingHallReservationPage::vfunc_2();
}

// MS2-FUNCTIONAL: else-chain / ASData slot layout differs
// @0x140fe3690
bool UIWeddingHallReservationPageSchedule::vfunc_4(__int64 a1, __int64 a2, int a3)
{
    if (UIWeddingHallReservationPage::vfunc_4(a1, a2, a3) == 1)
        return true;
    if (_stricmp((const char*)a1, "onPrevDay") == 0)
    {
        AddDays(m_date, -1);
        FUN_140fe3c40(this);
        return true;
    }
    if (_stricmp((const char*)a1, "onNextDay") == 0)
    {
        AddDays(m_date, 1);
        FUN_140fe3c40(this);
        return true;
    }
    if (_stricmp((const char*)a1, "onSelectTime") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620((const Scaleform::GFx::Value*)a2, a3))
        {
            int nHour = data.FUN_1422b8a10();
            if (nHour == -1)
            {
                m_nTime = 0;
                FUN_140fdc130(m_pDialog, m_nTime);
                return true;
            }
            CMsTime tTime(m_date);
            AddHours(tTime, nHour);
            m_nTime = tTime.Get();
            FUN_140fdc130(m_pDialog, m_nTime);
        }
        return true;
    }
    if (_stricmp((const char*)a1, "onSelectPublic") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620((const Scaleform::GFx::Value*)a2, a3))
        {
            int nValue = data.FUN_1422b8a10();
            m_bPrivate = nValue == 0;
            FUN_140fdc160(m_pDialog, m_bPrivate);
        }
    }
    return false;
}

// @0x140fe3950
void UIWeddingHallReservationPageSchedule::vfunc_5()
{
    FUN_140fdbf70(m_pDialog);
}

// @0x140fe3980
void UIWeddingHallReservationPageSchedule::vfunc_6()
{
    if (FUN_140fdca40(m_pDialog) == 0)
    {
        CStringW strKey(L"s_wedding_hall_reservation_select_time");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
    }
    else
    {
        FUN_140fdc030(m_pDialog);
    }
}

// @0x140fe3a20
void UIWeddingHallReservationPageSchedule::vfunc_7()
{
    m_bPrivate = false;
    m_nTime = 0;
    m_date = FUN_140869440();
    AddHours(m_date, 4);
    TruncateToDay(m_date);
}

// @0x140fe3a90
CString UIWeddingHallReservationPageSchedule::vfunc_8()
{
    return CString("PageSchedule");
}

// @0x140fe3ae0
CStringW UIWeddingHallReservationPageSchedule::vfunc_9()
{
    CStringW strKey(L"s_wedding_reservation_schedule_page");
    return GetStringCommonByKey(strKey);
}

// MS2-FUNCTIONAL: one byte of the branch layout differs
// @0x140fe3b50
CStringW UIWeddingHallReservationPageSchedule::vfunc_10(bool bStart)
{
    if (bStart == 0)
    {
        CStringW strNext(L"s_wedding_reservation_next");
        return GetStringCommonByKey(strNext);
    }
    CStringW strPrev(L"s_wedding_reservation_prev");
    return GetStringCommonByKey(strPrev);
}

// MS2-FUNCTIONAL: branch layout of the bool result differs
// @0x140fe3c10
bool UIWeddingHallReservationPageSchedule::vfunc_12()
{
    if (FUN_140fdca20(m_pDialog) != 0)
        return true;
    return false;
}

// MS2-FUNCTIONAL: CMsTime temp slots differ (frame 0x40 larger in the exe)
// @0x140fe3c40 (refreshes the selectable hours, the day arrows and the date text)
void FUN_140fe3c40(UIWeddingHallReservationPageSchedule* pPage)
{
    Unk_SchedTarget* pTarget = FUN_140d295d0(FUN_1409eed90());
    int nFrom = 0;
    int nTo = 0x18;
    if (pTarget->m_nKind == 1)
    {
        CMsTime tStart(FUN_140869440());
        CMsTime tEnd(FUN_140d295d0(FUN_1409eed90())->m_nTime);
        AddHours(tStart, 4);
        AddDays(tEnd, 7);
        if (!FUN_14086ab70(CMsTime(tStart), CMsTime(pPage->m_date), 0))
            nFrom = tStart.GetHour();
        if (!FUN_14086ab70(CMsTime(pPage->m_date), CMsTime(tEnd), 0))
            nTo = tEnd.GetHour();
    }
    else if (pTarget->m_nKind == 2)
    {
        CMsTime tStart(FUN_140869440());
        CMsTime tEnd(FUN_140869440());
        AddHours(tStart, 4);
        AddDays(tEnd, 7);
        if (!FUN_14086ab70(CMsTime(tStart), CMsTime(pPage->m_date), 0))
            nFrom = tStart.GetHour();
        if (!FUN_14086ab70(CMsTime(pPage->m_date), CMsTime(tEnd), 0))
            nTo = tEnd.GetHour();
    }
    pPage->m_pScript->FUN_1409ba0d0("setEnableTime", nFrom, nTo);
    for (int i = 0; i < 0x18; i++)
    {
        CMsTime tHour(pPage->m_date);
        AddHours(tHour, i);
        if (FUN_1409023c0()->FUN_140909870(DAT_143ab2830, tHour) == 1)
            pPage->m_pScript->Invoke("setDisabledTime", i);
    }
    {
        MS2Ptr<Unk_SchedButton> spPrev = pPage->m_pScript->FUN_140acce30<Unk_SchedButton>("m_prev");
        if (spPrev.get())
            spPrev->FUN_1422c1fe0(nFrom == 0);
    }
    {
        MS2Ptr<Unk_SchedButton> spNext = pPage->m_pScript->FUN_140acce30<Unk_SchedButton>("m_next");
        if (spNext.get())
            spNext->FUN_1422c1fe0(nTo == 0x18);
    }
    MS2Ptr<ASTextField> spDate = pPage->m_pScript->FUN_1409b4620("m_date");
    if (spDate.get())
        spDate->FUN_1422c4cd0(FUN_140b8e910(pPage->m_date));
}

// MS2-FUNCTIONAL: temp slot layout of the allocation differs
// @0x140fe42c0
template <class T> Unk_WedPtr<T> FUN_140fe42c0(int nMovieId, const Scaleform::GFx::Value& v)
{
    void* pMem = operator new(0x80);
    T* pNew = pMem ? FUN_1422e8920(pMem, v, nMovieId) : 0;
    Unk_WedPtr<T> sp(pNew);
    return sp;
}

// MS2-FUNCTIONAL: temp slot layout differs
// @0x140fe4370
template <class T> Unk_WedPtr<T> Unk_SchedScript::FUN_140fe4370(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return FUN_140fe42c0<T>(m_nMovieId, v);
    return Unk_WedPtr<T>(0);
}
