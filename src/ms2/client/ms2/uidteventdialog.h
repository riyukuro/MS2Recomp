// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uidteventdialog.h (name assumed: the
// .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIDTEventDialog ("DTEventDialog", UI type 0x4f01) is the list of timed event rewards: each entry (a RewardItem,
// bound to an event context) counts its elapsed seconds, shows a gauge and a "hh:mm:ss" countdown and is added to,
// updated in and removed from the AS list ("addItem" / "updateItem" / "removeItem"). RTTI .?AVUIDTEventDialog@@,
// 0x288 bytes, vftables 0x142e76e68 (89 slots) and 0x142e76e58 for RewardItem.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset>.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/intervaltimer.h"
#include "ms2/commonfiles/dtrewardeventcontext.h"
#include "ms2/commonfiles/timeutil.h"

// The intrusive smart pointer of the event data (16 bytes, the pointer at +8; same shape as MS2Ptr). Its members
// are COMDATs per T; the ones instantiated for the first time in this unit are defined in the .cpp (explicit
// specializations), the others live in earlier units.
template <class T>
class Unk_DTPtr
{
public:
    Unk_DTPtr();
    Unk_DTPtr(int nNull);
    Unk_DTPtr(T* p);
    Unk_DTPtr(const Unk_DTPtr& o);
    ~Unk_DTPtr();
    Unk_DTPtr& operator=(const Unk_DTPtr& o);
    operator T*() const;
    T* operator->() const;
    bool operator==(T* p) const;

private:
    static void AddRefObject(T* p);
    void AddRefImpl(void* n) const;
    void ReleaseImpl(void* n);
    void AddRef() const;
    void Release();

    void* m_unk_00;
    T* m_p;
};

void FUN_141415600(const CString& strBindID);                       // release the item bound to the name

class UIDTEventDialog : public UIDialog
{
public:
    // One entry of the list: the event context, its start time and the elapsed seconds.
    class RewardItem : public CPtred
    {
    public:
        // Both inline (COMDATs of this unit): ctor 0x140f38f20, dtor 0x140f39090 (??_G 0x140f392f0).
        RewardItem() : m_start(GetServerTime()), m_elapsed(0), m_step(0) {}
        virtual ~RewardItem() { FUN_141415600(m_bindID); }

        MS2Ptr<CommonUserEvent::DTRewardEventContext> m_ctx;                                        // +0x18
        __time64_t m_start;                                                                         // +0x28
        unsigned int m_elapsed;                                                                     // +0x30 seconds
        unsigned int m_step;                                                                        // +0x34 index of the step
        CString m_bindID;                                                                           // +0x38
    };

    UIDTEventDialog();                                                                              // 0x140f359b0
    virtual ~UIDTEventDialog();                                                                     //  0 0x140f35b20 (??_G 0x140f39330)
    virtual CString GetTypeName();                                                                      //  1 0x140f35bb0
    virtual void OnLoadComplete();                                                                  // 22 0x140f35cc0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x140f35de0
    virtual void vfunc_43();                                                                        // 43 0x140f35e30
    virtual int vfunc_48() { return 0x4f01; }                                                       // 48 (COMDAT 0x140f39970)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);                           // 49 0x140f38160 tooltip
    virtual int vfunc_65();                                                                         // 65 0x140f35c90
    virtual void vfunc_67();                                                                        // 67 0x140f35c00
    virtual void vfunc_72();                                                                        // 72 0x140f36110
    virtual int vfunc_84(Unk_DTPtr<RewardItem> pReward);                                            // 84 0x140f36620 add
    virtual int vfunc_85(Unk_DTPtr<RewardItem> pReward);                                            // 85 0x140f36fb0 update
    virtual int vfunc_86(Unk_DTPtr<RewardItem> pReward);                                            // 86 0x140f37700 remove
    virtual int vfunc_87(Unk_DTPtr<RewardItem> pReward, unsigned int nStep);                        // 87 0x140f37870 change step

    void FUN_140f38430(MS2Ptr<CommonUserEvent::DTRewardEventContext> pCtx);                         // create the RewardItem of a context
    void FUN_140f38630(unsigned int nID);                                                           // remove everything of an event
    void FUN_140f38750();                                                                           // activate the waiting contexts
    CStringW FUN_140f388c0(CTimeSpan* pSpan);                                                       // "hh:mm:ss"

private:
    MS2_LAYOUT_FRIEND;
    Unk_IntervalTimer m_timer;                                                                      // +0x178
    ATL::CAtlMap<unsigned int, Unk_DTPtr<RewardItem> > m_active;                                    // +0x180
    ATL::CAtlMap<unsigned int, Unk_DTPtr<RewardItem> > m_pending;                                   // +0x1c8
    ATL::CAtlMap<int, MS2Ptr<CommonUserEvent::DTRewardEventContext> > m_ctx;                        // +0x210
    ATL::CAtlList<CString> m_binds;                                                                 // +0x258
};
MS2_CHECK_SIZE(UIDTEventDialog, 0x288);
MS2_CHECK_OFFSET(UIDTEventDialog, m_timer, 0x178);
MS2_CHECK_OFFSET(UIDTEventDialog, m_active, 0x180);
MS2_CHECK_OFFSET(UIDTEventDialog, m_pending, 0x1c8);
MS2_CHECK_OFFSET(UIDTEventDialog, m_ctx, 0x210);
MS2_CHECK_OFFSET(UIDTEventDialog, m_binds, 0x258);
