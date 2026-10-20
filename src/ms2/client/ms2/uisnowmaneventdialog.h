// Recovered UISnowmanEventDialog; names of fields and local helpers are inferred.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
class GameEventVariable;
class Unk_SnowmanContext;
class CInPacket;
namespace UICommon { class CAlignmentInfo; }
class Unk_SnowmanTimer {
public:
    Unk_SnowmanTimer();
    void FUN_140268840();
    int FUN_140268870(int interval);
private:
    int m_tick; int m_last;
};
MS2_CHECK_SIZE(Unk_SnowmanTimer, 8);
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
    static void Reference(T* p) { p->FUN_14015b020(); }
    void AddRefImpl(void*) const { Reference(m_p); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    void ReleaseImpl(void*) {
        if (m_p->FUN_140159bc0() == 0) {
            Reference(m_p);
            m_p->FUN_140159ba0();
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
    virtual CString vfunc_1();
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
    void FUN_140e954b0(MS2Ptr<Unk_SnowmanContext> context);
    void FUN_140e95be0(int index);
    void FUN_140e95d90(int index);
    int FUN_140e95f40(int index);
    int FUN_140e960d0(int index);
    int FUN_140e96260(int index);
    bool FUN_140e963f0(int index);
    CString FUN_140e96500(int itemId);
    void FUN_140e965e0();
    void FUN_140e96a90(const CStringW& path);
    int FUN_140e96c50(int type, CInPacket& packet);
    void FUN_140e96900(int* width, int* height);
    void FUN_140e969a0();
    void FUN_140e96ed0(GameEventVariable*);
    void FUN_140e96f00(GameEventVariable*);
    void FUN_140e96f30(GameEventVariable*);
    void FUN_140e96f60(GameEventVariable*);
    virtual int vfunc_48();
private:
    MS2_LAYOUT_FRIEND;
    Unk_SnowmanTimer m_timer;
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
