// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiwhispernotifydialog.h (name assumed: the
// exe has no __FILE__ string for this unit).
//
// UIWhisperNotifyDialog ("WhisperNotifyDialog", UI type 0x4e5e, RTTI .?AVUIWhisperNotifyDialog@@, 0x218 bytes = UIDialog +
// UIUGCEventListener at +0x178): the corner popup that lists incoming whispers, system whispers (friend / party notices) and
// received gift items. The UGC listener refreshes the sender's profile image / the gift's icon when a download finishes.
// m_whisperTimes / m_systemTimes remember when a sender last whispered so the popup repeats at most once per cool-down.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members, member names invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiugceventlistener.h"

class CItem;
struct Unk_WhisperInfo;

class UIWhisperNotifyDialog : public UIDialog, public UIUGCEventListener
{
public:
    UIWhisperNotifyDialog();                                                // 0x141b51780 (open tween 0)
    virtual ~UIWhisperNotifyDialog() = default;                                   //  0 0x141b52f30 (??_G 0x141b52f90)
    virtual CString GetTypeName();                                              //  1 0x141b518b0 "WhisperNotifyDialog"
    virtual void OnLoadInit();                                              // 20 0x141b519d0 sets the popup's slide ("init")
    virtual int vfunc_13();                                                 // 13 0x141b51b00
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x141b51b30
    virtual void vfunc_43();                                                // 43 0x141b51a90
    virtual int vfunc_48() { return 0x4e5e; }                               // 48 0x141b532d0 UI type id
    virtual int vfunc_65();                                                 // 65 0x141b51900 Open: listen for UGC events
    virtual void vfunc_67();                                                // 67 0x141b51960 Close: forget the times
    // UIUGCEventListener (+0x178)
    virtual void vfunc_ugc_1(void* pId, CString strPath);                   // 1 0x141b51b80 the sender's profile image arrived
    virtual void vfunc_ugc_2(void* pId, CString strName);                   // 2 0x141b51cd0 the gift's item icon arrived

    void FUN_141b51e30(unsigned __int64 nId, const CStringW& strMsg, const CString& strName);   // add a whisper
    void FUN_141b52030(int nItemId, int nGrade, int nCount, const CStringW& strMsg);            // add a gift item by id
    void FUN_141b52210(MS2Ptr<CItem> spItem, const CStringW& strMsg, const CString& strUgcPath);   // add a gift item
    void FUN_141b52570(const Unk_WhisperInfo* pInfo, int nMode, int nItemId);                   // add a system whisper
    int FUN_141b529f0(unsigned __int64 nId);                                // the sender whispered within the cool-down
    int FUN_141b52a60(int nId);                                             // the system sender notified within a minute

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<unsigned __int64, int> m_whisperTimes;                     // +0x180 sender id -> time
    ATL::CAtlMap<int, int> m_systemTimes;                                   // +0x1c8 system sender id -> time
    unsigned m_nCooldown;                                                   // +0x210 (client constant)
};
MS2_CHECK_SIZE(UIWhisperNotifyDialog, 0x218);
