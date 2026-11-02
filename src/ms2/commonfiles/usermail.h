// Recovered user mail manager (name inferred from the unit; no RTTI). Unk_* names are inferred from behaviour.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cmailtypes.h"

int FUN_140159bc0(CPtred*);
void FUN_140159ba0(CPtred*);

// Intrusive pointer to a CPtred-derived mail object (16 bytes, pointer at +8); one instance per T.
template<class T> class Unk_MailPtr {
public:
    Unk_MailPtr() : p(0) {}
    Unk_MailPtr(int) : p(0) {}
    Unk_MailPtr(T* value) : p(value) { AddRef(); }
    Unk_MailPtr(const Unk_MailPtr& o) : p(o.p) { AddRef(); }
    Unk_MailPtr(Unk_MailPtr&& o) : p(o.p) { o.p = 0; }
    ~Unk_MailPtr() { Release(); }
    Unk_MailPtr& operator=(const Unk_MailPtr& o) { o.AddRef(); Release(); p = o.p; return *this; }
    Unk_MailPtr& operator=(int) { Release(); return *this; }
    // Assignment from a raw pointer (`Unk_MailPtr tmp(value); swap`), named so that `p = q` / `p = 0` keep their overloads
    // (the exe operator= COMDAT 0x1419ede60 is in uimaillistdialog.cpp).
    // @0x1419ede60
    Unk_MailPtr& AssignRaw(T* value) { Unk_MailPtr temp(value); T* old = p; p = temp.p; temp.p = old; return *this; }
    bool operator==(T* value) const { return p == value; }
    T* get() const { return p; }
    // @0x1419ea470 (CMailInfo)
    bool IsNull() const { return p == 0; }
    T* operator->() const { return p; }
private:
    void AddRef() const { if (p) AddRefImpl(0); }
    static void Reference(T* value) { CPtred::AddRefPtred(value); }
    void AddRefImpl(void*) const { Reference(p); }
    void Release() { if (p) { ReleaseImpl(0); p = 0; } }
    void ReleaseImpl(void*) { if (CPtred::ReleasePtred(p) == 0) { Reference(p); CPtred::DeletePtred(p); } }
    void* pad_00; T* p;
};

class Unk_MailSession;
Unk_MailSession* FUN_1403ed2d0();
int FUN_141bcfbd0(Unk_MailSession*);
class Unk_MailService;
Unk_MailService* FUN_1401c0db0();
int FUN_1422b9ea0(__int64);
void FUN_141276180(const CString&, const CString&);

class CUserMail {
public:
    typedef Unk_MailPtr<CMailInfo> MailPtr;
    typedef Unk_MailPtr<CMailSendKeep> KeepPtr;
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
    MailArray& FUN_1408e3700();
    MailPtr FindMailById(__int64 key);
    MailPtr GetMailAt(int index);
    MailPtr GetLastMail();
    unsigned FindMailIndexById(__int64 id);
    void AddMailIfNew(MailPtr mail);
    int FUN_1408e3b70(__int64 id, int force, int reason);   // reason (0, 0x41) is not read
    unsigned FUN_1408e3da0();
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
    void FUN_1408e45e0();
    __int64 FUN_1408e4810();
    __int64 CalcSendFee(__int64 amount);
    void FUN_1408e4890();
    int FUN_1408e48b0();
    void FUN_1408e48f0();
    void FUN_1408e49d0();
    static __int64 FUN_1408e57f0();
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
