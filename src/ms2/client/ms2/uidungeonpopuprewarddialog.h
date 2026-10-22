// Recovered UIDungeonPopupRewardDialog. Header and field names are inferred.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"

class CInPacket;
class UIDungeonSearchUnitedReward;

// Unit-local intrusive pointer; the original template name is unknown.
template<class T> class DungeonRewardPtr
{
public:
    DungeonRewardPtr() : m_p(0) {}
    DungeonRewardPtr(T* p) : m_p(p) { AddRef(); }
    ~DungeonRewardPtr() { Release(); }
    DungeonRewardPtr& operator=(int) { Release(); return *this; }
    DungeonRewardPtr& operator=(T* p) {
        DungeonRewardPtr temp(p);
        T* old = m_p;
        m_p = temp.m_p;
        temp.m_p = old;
        return *this;
    }
    T* operator->() const { return m_p; }
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

class UIDungeonPopupRewardDialog : public UIDialog
{
public:
    UIDungeonPopupRewardDialog();
    virtual ~UIDungeonPopupRewardDialog();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    void FUN_140c0f210(CInPacket& packet);
    virtual int vfunc_48() { return 20357; }
private:
    MS2_LAYOUT_FRIEND;
    DungeonRewardPtr<UIDungeonSearchUnitedReward> m_reward;
};
MS2_CHECK_SIZE(UIDungeonPopupRewardDialog, 0x188);
MS2_CHECK_OFFSET(UIDungeonPopupRewardDialog, m_reward, 0x178);
