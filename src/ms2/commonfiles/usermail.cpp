// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). User mail list / send-keep slots.
// MS2-UNIT: commonfiles\usermail.cpp
// MS2-RANGE: 0x1408e2ed0-0x1408e70b0 .text$mn
// MS2-RANGE: 0x1400be260-0x1400be2c0 .text$di
// MS2-RANGE: 0x142c9cad0-0x142c9cb06 .text$yd
// MS2-PIN: ??4Unk_MailAttachPtr@@QEAAAEAV0@PEAVCMailAttachItem@@@Z 0x1408e4f40
// MS2-PIN: ?get@?$Unk_MailPtr@VCMailSendKeep@@@@QEBAPEAVCMailSendKeep@@XZ 0x1408e5170
// MS2-FUNCTIONAL: 19 functions differ from the exe only in local-temporary slot order / EH state layout (behaviour-equivalent).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\usermail.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "usermail.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern __int64 DAT_143ab2828;
extern __int64 DAT_143ab25e8;

// @0x1400be260
static CString s_143ab25e0("mail_delete");
// @0x1400be290
static CString s_143ab25d8("mail_recieve");

// @0x1408e2ed0
CUserMail::CUserMail() {
    FUN_1408e3030();
    FUN_1408e3ff0(1);
    m_d0 = 0;
    m_dc = 0;
    m_d8 = 0;
    m_00 = 0;
    m_04 = 0;
}

// @0x1408e2fd0
CUserMail::~CUserMail() {
}

// @0x1408e3030
void CUserMail::FUN_1408e3030() {
    FUN_1408e49d0();
}
MS2_REPLACE_METHOD(0x1408E3030, CUserMail, FUN_1408e3030, 24, 0x68831EA6);

// @0x1408e3050
int CUserMail::FUN_1408e3050() {
    MS2_ASSERT_AT(0x1e, 0);
    return 1;
}

// @0x1408e30a0
CUserMail::MailPtr CUserMail::FUN_1408e30a0(__int64 a, CStringW b, __int64 c, CStringW d, CStringW e) {
    MailPtr mail(new CMailInfo(1));
    mail->FUN_140690330(0);
    mail->FUN_140690390(a, b);
    mail->FUN_140690460(c);
    mail->FUN_140690540(d, e);
    mail->FUN_140690d20(FUN_1408e44e0(), 0);
    for (int i = 0; i < 5; ++i) {
        KeepPtr keep = FUN_1408e43c0(i);
        if (!(keep == 0)) {
            Unk_MailAttachPtr attach(0);
            if (keep->m_kind == 0) {
                attach = keep->m_attach;
            } else {
                attach = new CMailAttachItem(i, keep->m_item);
            }
            mail->FUN_140690650(i, attach);
        }
    }
    return mail;
}

// @0x1408e3490
void CUserMail::FUN_1408e3490(unsigned v) {
    m_00 = v;
    if (v > 0) {
        if (!FUN_141bcb0a0(FUN_1403ed2d0())) {
            m_d8 = 1;
        }
    }
}
MS2_REPLACE_METHOD(0x1408E3490, CUserMail, FUN_1408e3490, 71, 0x7046536C);

// @0x1408e34e0
int CUserMail::FUN_1408e34e0() {
    return m_00;
}
MS2_REPLACE_METHOD(0x1408E34E0, CUserMail, FUN_1408e34e0, 13, 0xA5869133);

// @0x1408e3500
void CUserMail::FUN_1408e3500(int v) {
    m_04 = v;
}
MS2_REPLACE_METHOD(0x1408E3500, CUserMail, FUN_1408e3500, 22, 0x1E8921CF);

// @0x1408e3520
int CUserMail::FUN_1408e3520() {
    return m_04;
}
MS2_REPLACE_METHOD(0x1408E3520, CUserMail, FUN_1408e3520, 14, 0x7AB52803);

// @0x1408e3540
void CUserMail::FUN_1408e3540(__int64 key, __int64 value) {
    MailPtr mail = FUN_1408e3720(key);
    if (mail.get() != 0) {
        mail->FUN_1406910e0(value);
    }
}
MS2_REPLACE_METHOD(0x1408E3540, CUserMail, FUN_1408e3540, 103, 0x4560EA11);

// @0x1408e35b0
void CUserMail::FUN_1408e35b0(MailArray& out, int kind) {
    for (size_t i = 0; i < m_mails.GetCount(); ++i) {
        MailPtr mail = m_mails[i];
        if (mail->FUN_140690370() == kind) {
            out.Add(mail);
        }
    }
}

// @0x1408e3680
void CUserMail::FUN_1408e3680(MailArray& out) {
    out.RemoveAll();
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        out.Copy(m_mails);
    }
}
MS2_REPLACE_METHOD(0x1408E3680, CUserMail, FUN_1408e3680, 112, 0x4CF2FE87);

// @0x1408e3700
CUserMail::MailArray& CUserMail::FUN_1408e3700() {
    return m_mails;
}
MS2_REPLACE_METHOD(0x1408E3700, CUserMail, FUN_1408e3700, 17, 0xF6474C33);

// @0x1408e3720
CUserMail::MailPtr CUserMail::FUN_1408e3720(__int64 key) {
    MailPtr found(0);
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        m_map.Lookup(key, found);
    }
    return found;
}

// @0x1408e37e0
CUserMail::MailPtr CUserMail::FUN_1408e37e0(int index) {
    MailPtr found(0);
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        if (index < 0 || (int)m_mails.GetCount() <= index) {
            return MailPtr(0);
        }
        found = m_mails[index];
    }
    return found;
}

// @0x1408e38f0
CUserMail::MailPtr CUserMail::FUN_1408e38f0() {
    return FUN_1408e37e0(m_mails.GetCount() - 1);
}
MS2_REPLACE_METHOD(0x1408E38F0, CUserMail, FUN_1408e38f0, 83, 0xC2E6188C);

// @0x1408e3950
unsigned CUserMail::FUN_1408e3950(__int64 id) {
    unsigned result = 0xffffffff;
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        for (unsigned i = 0; i < m_mails.GetCount(); ++i) {
            if (!(m_mails[i] == 0)) {
                if (m_mails[i]->FUN_140690350() == id) {
                    result = i;
                    break;
                }
            }
        }
    }
    return result;
}

// @0x1408e3a60
void CUserMail::FUN_1408e3a60(MailPtr mail) {
    if (mail == 0)
        return;
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        if (m_map.Lookup(mail->FUN_140690350()) != 0) {
            return;
        }
        m_map.SetAt(mail->FUN_140690350(), mail);
        m_mails.Add(mail);
    }
}

// @0x1408e3b70
int CUserMail::FUN_1408e3b70(__int64 id, int force, int reason) {
    MailPtr mail(0);
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        mail = FUN_1408e3720(id);
        if (mail == 0) {
            return 0;
        }
        if (force == 0) {
            if (mail->FUN_140691220() == 1) {
                return 0;
            }
        }
        m_map.RemoveKey(id);
        for (unsigned i = 0; i < m_mails.GetCount(); ++i) {
            if (m_mails[i]->FUN_140690350() == id) {
                m_mails.RemoveAt(i, 1);
                break;
            }
        }
    }
    if (!FUN_141bcb0a0(FUN_1403ed2d0())) {
        m_dc = 1;
    }
    return 1;
}

// @0x1408e3da0
unsigned CUserMail::FUN_1408e3da0() {
    unsigned count = (unsigned)m_map.GetCount();
    return count;
}
MS2_REPLACE_METHOD(0x1408E3DA0, CUserMail, FUN_1408e3da0, 39, 0x7E9110C6);

// @0x1408e3dd0
int CUserMail::FUN_1408e3dd0(int kind) {
    MailArray list;
    FUN_1408e35b0(list, kind);
    return (int)list.GetCount();
}
MS2_REPLACE_METHOD(0x1408E3DD0, CUserMail, FUN_1408e3dd0, 86, 0x9D7B6126);

// @0x1408e3e30
int CUserMail::FUN_1408e3e30() {
    int count = 0;
    for (unsigned i = 0; i < m_mails.GetCount(); ++i) {
        MailPtr mail = m_mails[i];
        if (mail.get() != 0) {
            if (mail->FUN_140691130() == 0) {
                ++count;
            }
        }
    }
    return count;
}

// @0x1408e3f00
int CUserMail::FUN_1408e3f00(int kind) {
    int count = 0;
    for (unsigned i = 0; i < m_mails.GetCount(); ++i) {
        MailPtr mail = m_mails[i];
        if (mail->FUN_140690370() != kind)
            continue;
        if (mail->FUN_140691130())
            continue;
        ++count;
    }
    return count;
}

// @0x1408e3ff0
void CUserMail::FUN_1408e3ff0(int skipTotal) {
    m_08 = 0;
    m_keeps.SetCount(5, -1);
    for (int i = 0; i < 5; ++i) {
        m_keeps[i] = 0;
    }
    if (skipTotal == 0) {
        FUN_1408e45e0();
    } else {
        m_30 = 0;
    }
}

// @0x1408e4090
void CUserMail::FUN_1408e4090(int index) {
    if (-1 < index && index < 5) {
        Unk_LockGuard guard(m_lock);
        if (guard != 0) {} else {
            m_keeps[index] = 0;
        }
        FUN_1408e45e0();
    }
}

// @0x1408e4120
void CUserMail::FUN_1408e4120(int index, Unk_MailAttachPtr attach) {
    if (index < 0 || 4 < index) {
        return;
    }
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        KeepPtr keep(new CMailSendKeep(attach));
        m_keeps[index] = keep;
    }
    FUN_1408e45e0();
}

// @0x1408e4270
void CUserMail::FUN_1408e4270(int index, MS2Ptr<CItem> item) {
    if (index < 0 || 4 < index) {
        return;
    }
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        KeepPtr keep(new CMailSendKeep(item));
        m_keeps[index] = keep;
    }
    FUN_1408e45e0();
}

// @0x1408e43c0
CUserMail::KeepPtr CUserMail::FUN_1408e43c0(int index) {
    if (index < 0 || 4 < index) {
        return KeepPtr(0);
    }
    KeepPtr keep = m_keeps[index];
    return keep;
}

// @0x1408e4470
void CUserMail::FUN_1408e4470(__int64 value) {
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        m_08 = value;
    }
    FUN_1408e45e0();
}

// @0x1408e44e0
__int64 CUserMail::FUN_1408e44e0() {
    return m_08;
}
MS2_REPLACE_METHOD(0x1408E44E0, CUserMail, FUN_1408e44e0, 15, 0x5B8A7339);

// @0x1408e4500
int CUserMail::FUN_1408e4500() {
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        for (int i = 0; i < 5; ++i) {
            KeepPtr keep = m_keeps[i];
            if (keep == 0) {
                return i;
            }
        }
    }
    return -1;
}

// @0x1408e45e0
void CUserMail::FUN_1408e45e0() {
    __int64 sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;
    for (int i = 0; i < 5; ++i) {
        KeepPtr keep = m_keeps[i];
        if (keep.get() != 0) {
            sum1 += keep->FUN_14068fe20(1);
            sum2 += keep->FUN_14068fe20(2);
            sum3 += keep->FUN_14068fe20(3);
            sum4 += keep->FUN_14068fe20(4);
            sum5 += keep->FUN_14068fe20(5);
            sum6 += keep->FUN_14068fe20(6);
        }
    }
    m_30 = FUN_1401c0db0()->FUN_140676020(m_08, sum1, sum2, sum3, sum4, sum5, sum6);
}

// @0x1408e4810
__int64 CUserMail::FUN_1408e4810() {
    return m_30;
}
MS2_REPLACE_METHOD(0x1408E4810, CUserMail, FUN_1408e4810, 15, 0xAC153A31);

// @0x1408e4830
__int64 CUserMail::FUN_1408e4830(__int64 amount) {
    __int64 fee = 0;
    if (amount == 0) {
        fee = 0;
    } else if (amount <= 100000) {
        fee = 5000;
    } else {
        fee = (amount * 5) / 100;
    }
    return fee;
}
MS2_REPLACE_METHOD(0x1408E4830, CUserMail, FUN_1408e4830, 90, 0xBA2C3F2C);

// @0x1408e4890
void CUserMail::FUN_1408e4890() {
    m_d0 = DAT_143ab2828;
}

// @0x1408e48b0
int CUserMail::FUN_1408e48b0() {
    return m_d0 == DAT_143ab2828;
}

// @0x1408e48f0
void CUserMail::FUN_1408e48f0() {
    if (m_d8 != 0) {
        if (FUN_141bcfbd0(FUN_1403ed2d0()) == 0) {
            return;
        }
        m_d8 = 0;
        if (FUN_1422b9ea0(FUN_1408e57f0()) == 0) {
            FUN_141276180(s_143ab25d8, CString(""));
        }
    }
    if (m_dc != 0) {
        m_dc = 0;
        FUN_141276180(s_143ab25e0, CString(""));
    }
}

// @0x1408e49d0
void CUserMail::FUN_1408e49d0() {
    Unk_LockGuard guard(m_lock);
    if (guard != 0) {} else {
        m_map.RemoveAll();
        m_mails.RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x1408E49D0, CUserMail, FUN_1408e49d0, 109, 0xBE44D731);

// @0x1408e57f0
__int64 CUserMail::FUN_1408e57f0() {
    return DAT_143ab25e8;
}
