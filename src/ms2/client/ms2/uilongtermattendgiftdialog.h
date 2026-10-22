// Recovered UILongTermAttendGiftDialog (long-term attendance gift event dialog, UI type 0x4f98, RTTI
// .?AVUILongTermAttendGiftDialog@@, 0x188 bytes); names of fields and local helpers are inferred. Original header name
// assumed: the .cpp's __FILE__ string is in the exe, the header's is not.
// The dialog shows the attendance frame (title, dates, attendance points, "attend" button) and one reward row per
// attendance day; the event record (MS2Ptr at +0x178) comes from the game event manager.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ascript.h"

class CInPacket;
class CMsgBoxData;
class NotifyObject;
class Unk_LtaEvent;
class Unk_LtaList;

class UILongTermAttendGiftDialog : public UIDialog
{
public:
    UILongTermAttendGiftDialog();                                          // 0x140c6b300
    virtual ~UILongTermAttendGiftDialog();                                 //  0 0x140c6b450
    virtual CString GetTypeName();                                             //  1 0x140c6b4a0
    virtual int vfunc_13();                                                // 13 0x140c6b5b0
    virtual void OnLoadComplete();                                         // 22 0x140c6b560
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c6b8b0
    virtual void vfunc_45(Scaleform::GFx::Value* pResult, const CString& strMethod, ASData* pArgs);       // 45 0x140c6b5d0
    virtual int vfunc_48() { return 0x4f98; }                              // 48 (COMDAT 0x140c6e000)
    virtual int vfunc_65();                                                // 65 0x140c6b4f0
    virtual void vfunc_67();                                               // 67 0x140c6b520

    void FUN_140c6b9d0();                                                  // refresh the reward list when the dialog is loaded
    void SendEventRewardMode27(NotifyObject*);                                     // "NotifyGameStart": asks the server for the event data
    void FUN_140c6bac0(int nType, CInPacket& packet);                      // server answer of packet 0x97
    bool SendEventRewardMode26(int nResult, const CMsgBoxData& data);             // "use merat to attend" confirm result
    bool FUN_140c6bd40(int nResult, const CMsgBoxData& data);             // "lack of merat" box result
    void FUN_140c6bdb0();                                                  // "setData" of the swf (header)
    void FUN_140c6c250();                                                  // "setAttendance" of the swf (day frames)
    void FUN_140c6c4a0();                                                  // fill the reward list
    void FUN_140c6c8e0();                                                  // refresh everything
    void FUN_140c6c920();                                                  // "updateAttendance" of the swf
    bool FUN_140c6cbf0();                                                  // fetch the event record; true when there is one
    void SendEventRewardMode25(int nDay);                                          // claim the reward of a day
    void FUN_140c6cd00();                                                  // press the attend button
    int FUN_140c6d040(unsigned int nDay);                                  // 0 not yet, 1 claimable, 2 claimed
    int FUN_140c6d130();                                                   // days that can still be caught up
    CString FUN_140c6d200(unsigned int nDay, unsigned int nCur, int nCatchUp);   // state frame name of a day
    CString FUN_140c6d390(int nItemId);                                    // icon path of an item
    CString FUN_140c6d470();                                               // frame name of the event
    int FUN_140c6d520();                                                   // table int 0xa8d (this event)
    int FUN_140c6d570();                                                   // table int 0xa8e (this event)
    CStringW FUN_140c6d5c0();                                              // table string 0xa8c (claimed days)

    MS2Ptr<Unk_LtaList> FUN_140c02900(const CString& strName);              // bind a list child

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_LtaEvent> m_178;                                            // +0x178 the event record
};
MS2_CHECK_SIZE(UILongTermAttendGiftDialog, 0x188);
MS2_CHECK_OFFSET(UILongTermAttendGiftDialog, m_178, 0x178);
