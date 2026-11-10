// Recovered user mail manager (name inferred from the unit; no RTTI). Unk_* names are inferred from behaviour.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cmailtypes.h"

// The mail pointers are MS2Ptr<T> (ascript.h), the game's 16-byte intrusive pointer to a CPtred-derived object.
// The former MS2Ptr<T> view had the same layout and the same member bodies (ms2ptr_impl.h). Exe COMDATs:
// AssignRaw 0x1419ede60 (uimaillistdialog.cpp), IsNull<CMailInfo> 0x1419ea470, get<CMailSendKeep> 0x1408e5170.
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

class Unk_MailSession;
Unk_MailSession* FUN_1403ed2d0();
int FUN_141bcfbd0(Unk_MailSession*);
class Unk_BmPriceMgr* FUN_1401c0db0();
int FUN_1422b9ea0(__int64);
int FUN_141276180(const CString&, const CString&);

class CUserMail {
public:
    typedef MS2Ptr<CMailInfo> MailPtr;
    typedef MS2Ptr<CMailSendKeep> KeepPtr;
    typedef ATL::CAtlArray<MailPtr> MailArray;
    CUserMail();
    ~CUserMail();
    void FUN_1408e3030();
    int FUN_1408e3050();
    MailPtr FUN_1408e30a0(__int64 a, CStringW b, __int64 c, CStringW d, CStringW e);
    void SetUnreadCount(unsigned v);
    int FUN_1408e34e0();
    void FUN_1408e3500(int v);
    int FUN_1408e3520();
    void FUN_1408e3540(__int64 key, __int64 value);
    void GetMailsByKind(MailArray& out, int kind);
    void GetAllMails(MailArray& out);
    MailArray& GetMails();
    MailPtr FindMailById(__int64 key);
    MailPtr GetMailAt(int index);
    MailPtr GetLastMail();
    unsigned FindMailIndexById(__int64 id);
    void AddMailIfNew(MailPtr mail);
    int RemoveMail(__int64 id, int force, int reason);   // reason (0, 0x41) is not read
    unsigned GetMailCount();
    int GetMailCountByKind(int kind);
    int CountUnreadMails();
    int CountUnreadMailsByKind(int kind);
    void ResetSendDraft(int skipTotal);
    void ClearSendKeep(int index);
    void SetSendKeepAttachment(int index, Unk_MailAttachPtr attach);
    void SetSendKeepItem(int index, MS2Ptr<CItem> item);
    KeepPtr GetSendKeep(int index);
    void SetSendMoney(__int64 value);
    __int64 FUN_1408e44e0();
    int FindFreeSendSlot();
    void UpdateSendFee();
    __int64 GetSendFee();
    __int64 CalcSendFee(__int64 amount);
    void FUN_1408e4890();
    int FUN_1408e48b0();
    void FUN_1408e48f0();
    void ClearMails();
    static __int64 GetGFxSceneService();
private:
    MS2_LAYOUT_FRIEND;
    int m_00; int m_04;
    __int64 m_08;
    ATL::CAtlArray<KeepPtr> m_keeps;                 // +0x10, 5 slots
    __int64 m_30;
    CLockCriticalSection m_lock;                     // +0x38
    ATL::CAtlMap<__int64, MailPtr> m_map;            // +0x68
    MailArray m_mails;                               // +0xb0
    __int64 m_d0; int m_d8; int m_dc;
};
MS2_CHECK_SIZE(CUserMail, 0xe0);
MS2_CHECK_OFFSET(CUserMail, m_keeps, 0x10);
MS2_CHECK_OFFSET(CUserMail, m_lock, 0x38);
MS2_CHECK_OFFSET(CUserMail, m_map, 0x68);
MS2_CHECK_OFFSET(CUserMail, m_mails, 0xb0);
MS2_CHECK_OFFSET(CUserMail, m_d0, 0xd0);
