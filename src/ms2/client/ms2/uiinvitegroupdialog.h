// uiinvitegroupdialog.h - UIInviteGroupDialog (RTTI .?AVUIInviteGroupDialog@@, 0x188 bytes, UIModalDialog, UI id 0x4e90,
// swf "InviteGroupDialog"; header name assumed, defined in client\ms2\uiinventorydialog.cpp): invites people into a
// group chat. "m_userList" lists the friends, guild members and club members who are not in the chat yet,
// "m_textInput" takes a name, and "m_userCount" / "m_inviteFromComunity" show the member limit (20).
// The group chat member events (FUN_14199fd10..fe30) refresh the list while it is open.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uimodaldialog.h"

struct Unk_InvGroupEntry;

class UIInviteGroupDialog : public UIModalDialog
{
public:
    typedef ATL::CAtlList<Unk_InvGroupEntry> EntryList;

    UIInviteGroupDialog();                                      // 0x14199f740
    virtual ~UIInviteGroupDialog();                             //  0 0x14199f7e0 (??_G 0x1419a0dc0)
    virtual CString GetTypeName();                                  //  1 0x14199f820 "InviteGroupDialog"
    virtual int vfunc_13();                                     // 13 0x14199f9a0 Enter: invite the typed name
    virtual void OnLoadInit();                                  // 20 0x14199f8a0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14199fae0
    virtual int vfunc_48() { return 0x4e90; }                   // 48 0x1419a10d0
    virtual void vfunc_67();                                    // 67 0x14199f870 close: forget the chat

    // ---- non-virtual members, sorted by address ----
    void FUN_14199fcf0(unsigned nGroupId);                      // the chat to invite into
    void FUN_14199fd10(int nGroupId, const CStringW& strName, const CStringW& strText);    // a member joined
    void FUN_14199fd60(int nGroupId, const CStringW& strName, const CStringW& strOther);   // a member was invited
    void FUN_14199fdb0(int nGroupId, const CStringW& strName);  // a member left
    void FUN_14199fdf0(int nGroupId, const CStringW& strName);  // a member was kicked
    void FUN_14199fe30(int nGroupId, const CStringW& strName);  // a member went offline
    void FUN_14199fe70(unsigned nCount);                        // the selected count changed: the limit check
    void FUN_1419a0160(unsigned nCount);                        // the "m_userCount" text
    void FUN_1419a0240();                                       // rebuild the user list
    void FUN_1419a06d0(EntryList& entries);                     // add the friends
    void FUN_1419a07d0(EntryList& entries);                     // add the guild members
    void FUN_1419a08f0(EntryList& entries);                     // add the club members
    int FUN_1419a0a10(__int64 nCharacterId, EntryList& entries);   // already in the chat or listed
    int FUN_1419a0b20();                                        // the input has the focus and nothing blocks it

private:
    MS2_LAYOUT_FRIEND;
    unsigned m_180;                                             // +0x180 the group chat id
};
MS2_CHECK_SIZE(UIInviteGroupDialog, 0x188);
MS2_CHECK_OFFSET(UIInviteGroupDialog, m_180, 0x180);
