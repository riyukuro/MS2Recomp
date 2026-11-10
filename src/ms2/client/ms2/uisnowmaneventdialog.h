// Recovered UISnowmanEventDialog; names of fields and local helpers are inferred.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/intervaltimer.h"
class GameEventVariable;
class SnowmanContext;
class CInPacket;
namespace UICommon { class CAlignmentInfo; }
template<class T> class SnowmanPtr
{
public:
    SnowmanPtr() : m_p(0) {}
    SnowmanPtr(T* p) : m_p(p) { AddRef(); }
    ~SnowmanPtr() { Release(); }
    SnowmanPtr& operator=(int) { Release(); return *this; }
    SnowmanPtr& operator=(T* p) {
        SnowmanPtr temp(p);
        T* old = m_p;
        m_p = temp.m_p;
        temp.m_p = old;
        return *this;
    }
    bool IsNull() const { return m_p == 0; }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
    bool operator==(T* p) const { return m_p == p; }   // 0x141a48b60 for CAlignmentInfo (uiminimapentity.cpp)
private:
    void AddRef() const { if (m_p) AddRefImpl(0); }
    static void Reference(T* p) { CPtred::AddRefPtred(p); }
    void AddRefImpl(void*) const { Reference(m_p); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    void ReleaseImpl(void*) {
        if (CPtred::ReleasePtred(m_p) == 0) {
            Reference(m_p);
            CPtred::DeletePtred(m_p);
        }
    }
    void* m_unused;
    T* m_p;
};

class UISnowmanEventDialog : public UIDialog
{
public:
    UISnowmanEventDialog();
    virtual ~UISnowmanEventDialog();
    virtual CString GetTypeName();
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void OnLoadComplete();
    virtual void vfunc_45(Scaleform::GFx::Value*, const CString&, ASData*);
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual void vfunc_72();
    virtual void vfunc_43();
    virtual void vfunc_44(int, int, int, int*, int*);
    virtual int vfunc_53(void*);
    virtual int vfunc_54(void*);
    virtual void vfunc_19();
    void FUN_140e954b0(MS2Ptr<SnowmanContext> context);
    void SendEventRewardMode12(int index);
    void SendEventRewardMode13(int index);
    int GetCurSnowflakeCount(int index);
    int GetCurDailyCompleteCount(int index);
    int GetCurAccumCompleteCount(int index);
    bool IsAccumRewardReceived(int index);
    CString GetItemIconPath(int itemId);
    void UpdateInfo();
    void FUN_140e96a90(const CStringW& path);
    int FUN_140e96c50(int type, CInPacket& packet);
    void GetDialogSize(int* width, int* height);
    void ApplyAlign();
    void OnSnowflakeCountChanged(GameEventVariable*);
    void OnDailyCompleteCountChanged(GameEventVariable*);
    void OnAccumCompleteCountChanged(GameEventVariable*);
    void FUN_140e96f60(GameEventVariable*);
    virtual int vfunc_48();
private:
    MS2_LAYOUT_FRIEND;
    Unk_IntervalTimer m_timer;
    __int64 m_lastUpdate;
    int m_offsetX;
    int m_offsetY;
    int m_alignment;
    SnowmanPtr<UICommon::CAlignmentInfo> m_alignInfo;
};
MS2_CHECK_SIZE(UISnowmanEventDialog, 0x1a8);
MS2_CHECK_OFFSET(UISnowmanEventDialog, m_timer, 0x178);
MS2_CHECK_OFFSET(UISnowmanEventDialog, m_lastUpdate, 0x180);
MS2_CHECK_OFFSET(UISnowmanEventDialog, m_offsetX, 0x188);
MS2_CHECK_OFFSET(UISnowmanEventDialog, m_offsetY, 0x18c);
MS2_CHECK_OFFSET(UISnowmanEventDialog, m_alignment, 0x190);
MS2_CHECK_OFFSET(UISnowmanEventDialog, m_alignInfo, 0x198);
