// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Tencent user report dialog and page.
// MS2-UNIT: client\ms2\uitencentuserreportdialog.cpp
// MS2-RANGE: 0x1400dcaa0-0x1400dccc0 .text$di
// MS2-RANGE: 0x140edb370-0x140edea60 .text$mn
// MS2-RANGE: 0x142ca85d0-0x142ca8690 .text$yd
// MS2-PIN: ??_GNotifyBlindTarget@@UEAAPEAXI@Z 0x140ede740
// MS2-PIN: ??_7?$Unk_ReportDelegateImpl@U?$pair@PEAVUITencentUserReportDialog@TencentUserReport@@P812@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Unk_ReportDelegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@6B@ 0x142e691b0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitencentuserreportdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uitencentuserreportdialog.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdarg.h>
#include "ms2/placeholder/asdata.h"

static CString s_marketSort[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_jobCode = "jobCode";
static CString s_sortValue = "sortValue";
static CString s_tabIndex = "tabIndex";

class Unk_ReportText : public CPtred {
public:
    void FUN_1422c4cd0(const CStringW& text);
    CStringW FUN_1422c4da0();
};
class Unk_ReportCheck : public CPtred {
public:
    void FUN_1422c1fe0(int enabled);
    void FUN_1422ce090(int checked);
    bool FUN_1422ce0e0();
    void FUN_1422cdfb0(const CStringW& text);
};
class Unk_ReportEntity : public AScript {
public:
    template<class T> Unk_ReportHandle<T> GetChild(const CString&, Unk_ReportHandle<T>&);
};
void FUN_1422bccb0(Scaleform::GFx::Value*, int);
class Unk_ReportValue { public: bool FUN_1409b4d40() const; };
template<class T> Unk_ReportHandle<T> MakeReportEntity(int, const Scaleform::GFx::Value&);
class Unk_ReportScript : public CPtred {
public:
    Scaleform::GFx::Value FUN_1422baa20(const char*);
    Scaleform::GFx::Value FUN_1422bb8f0(const char*, ASArgList&);
    template<class T> Scaleform::GFx::Value Invoke(const char* method, T value) {
        ASArgList args;
        args.FUN_1409b2800(1);
        FUN_1422bccb0(args.FUN_1409b1f70(0), value);
        return FUN_1422bb8f0(method, args);
    }
    template<class T> Unk_ReportHandle<T> GetChild(const CString& name) {
        Scaleform::GFx::Value child = FUN_1422baa20(name);
        if (reinterpret_cast<const Unk_ReportValue*>(&child)->FUN_1409b4d40())
            return MakeReportEntity<T>(m_id, child);
        return Unk_ReportHandle<T>(0);
    }
private:
    int m_id;
};
class Unk_ReportDialogAccess : public UIDialog {
public:
    template<class T> Unk_ReportHandle<T> GetChild(const CString& name) {
        if (m_30 == NULL)
            return Unk_ReportHandle<T>(0);
        return reinterpret_cast<Unk_ReportScript*>(m_30.operator->())->GetChild<T>(name);
    }
    template<class T> Unk_ReportHandle<T> GetChild(const CString& name, Unk_ReportHandle<T>& out) {
        out = GetChild<T>(name);
        return out;
    }
};
extern const int g_reportTypes[16]; // exe table; no mutable DLL-local copy
void FUN_141275260(int message, int a, int b);
CStringW GetStringCommon(int id);
class Unk_ReportLocalizer { public: CStringW FUN_1422b0570(const CString& key); };
Unk_ReportLocalizer* FUN_14025e7a0();
class Unk_ReportBlindManager {
public:
    bool FUN_140a25950(int kind, __int64 id);
    bool FUN_140a25730(int kind, CStringW name);
};
Unk_ReportBlindManager* FUN_1409c1730();
class Unk_ReportGuildManager { public: void FUN_1418885b0(int id); };
Unk_ReportGuildManager* FUN_14052d220();
class Unk_ReportUserManager { public: void FUN_1413baef0(int id, int flag); };
Unk_ReportUserManager* FUN_1403ed290();

template<class F> class Unk_ReportDelegate;
template <class R, class A1, class A2>
class Unk_ReportDelegate<R(A1, A2)>
{
public:
    class Unk_ReportDelegateImplBase
    {
    public:
        Unk_ReportDelegateImplBase();
        virtual ~Unk_ReportDelegateImplBase();                            // 0
        virtual Unk_ReportDelegateImplBase* vfunc_1() const = 0;          // 1 clone
        virtual R vfunc_2(A1 a1, A2 a2) = 0;                           // 2 Invoke
        virtual bool vfunc_3(const Unk_ReportDelegateImplBase* p) const = 0;     // 3 equals
    };

    template <class F>
    class Unk_ReportDelegateImpl : public Unk_ReportDelegateImplBase
    {
    public:
        Unk_ReportDelegateImpl(const Unk_ReportDelegateImpl& o) : m_f(o.m_f) {}
        Unk_ReportDelegateImpl(const F& f) : m_f(f) {}
        virtual Unk_ReportDelegateImplBase* vfunc_1() const { return new Unk_ReportDelegateImpl(*this); }
        virtual R vfunc_2(A1 a1, A2 a2) { return Call(m_f, a1, a2); }
        virtual bool vfunc_3(const Unk_ReportDelegateImplBase* p) const
        {
            const Unk_ReportDelegateImpl* o = dynamic_cast<const Unk_ReportDelegateImpl*>(p);
            if (!o)
                return false;
            return m_f == o->m_f;
        }

    private:
        template <class C, class M> static R Call(std::pair<C*, M>& p, A1 a1, A2 a2) { return (p.first->*p.second)(a1, a2); }

        F m_f;
    };

    Unk_ReportDelegate() : m_pImpl(0) {}
    template <class C>
    Unk_ReportDelegate(C* const& obj, R (C::*const& f)(A1, A2))     // f by const&: the caller copies the PMF before it stores `this` (uiobject.cpp agent)
        : m_pImpl(new Unk_ReportDelegateImpl<std::pair<C*, R (C::*)(A1, A2)> >(std::make_pair(obj, f)))
    {
    }
    Unk_ReportDelegate(const Unk_ReportDelegate& o);        // declared (appended by the uiobject.cpp agent): a user copy ctor makes a by-value
                                        // Unk_ReportDelegate argument go by reference to a caller temp that the callee destroys
                                        // (UIObject::OnLoadComplete 0x14131ec00); without it the ABI passes it in a register
    ~Unk_ReportDelegate();

private:
    Unk_ReportDelegateImplBase* m_pImpl;          // +0x00
};

class Unk_ReportMessageBox {
public:
    void FUN_141a024a0(int);
    void FUN_141a027c0(Unk_ReportDelegate<bool(int, const CMsgBoxData&)>);
};
MS2Ptr<Unk_ReportMessageBox> FUN_140d73e40(int, int, int, CStringW);
void FUN_140d73c60(MS2Ptr<Unk_ReportMessageBox>);

// Notification payload: the 16-byte target identifier is real data, not padding.
struct Unk_ReportTarget { __int64 low; __int64 high; };
class NotifyObject : public CPtred { public: NotifyObject(); virtual ~NotifyObject(); };
class NotifyBlindTarget : public NotifyObject {
public:
    NotifyBlindTarget(const int& kind, const Unk_ReportTarget& target) : m_kind(kind), m_target(target) {}
    virtual ~NotifyBlindTarget() = default;
private:
    int m_kind;
    Unk_ReportTarget m_target;
};
MS2_CHECK_SIZE(NotifyBlindTarget, 0x30);
class Unk_ReportNotifyManager { public: void FUN_140da4fe0(MS2Ptr<NotifyObject>); };
Unk_ReportNotifyManager* FUN_140939a10();
class Unk_ReportContact {
public:
    int FUN_1401cc5b0();
    __int64 FUN_1401cc2f0();
};
struct Unk_ReportContactRequest {
    Unk_ReportContactRequest();
    ~Unk_ReportContactRequest();
    unsigned char kind;
    __int64 id;
    CStringW name;
    CStringW reason;
};
MS2_CHECK_SIZE(Unk_ReportContactRequest, 0x20);
class Unk_ReportContactManager {
public:
    MS2Ptr<Unk_ReportContact> FUN_140ae4950(const CStringW&);
    void FUN_140ae4820(const Unk_ReportContactRequest&);
};
Unk_ReportContactManager* FUN_14097a780();

namespace TencentUserReport {

// @0x140edb370
UITencentUserReportDialog::UITencentUserReportDialog()
{
    FUN_141924170(0);
    m_page = 0;
}

// @0x140edb410
UITencentUserReportDialog::~UITencentUserReportDialog()
{
}

// @0x140edb480
void UITencentUserReportDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    if (m_30.IsNull()) {
        MS2_ASSERT_AT(26, "m_ascript" && 0);
        return;
    }
    reinterpret_cast<Unk_ReportScript*>(m_30.operator->())->Invoke("SetPage", m_data.type);
}
MS2_REPLACE_METHOD(0x140EDB480, UITencentUserReportDialog, OnLoadInit, 155, 0x7CA26282);

// @0x140edb530
void UITencentUserReportDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    CString pageName(m_data.type == 3 ? "m_ReportPageUgcItem" : "m_ReportPageCommon");
    Unk_ReportHandle<Unk_ReportEntity> pEntityPage;
    reinterpret_cast<Unk_ReportDialogAccess*>(this)->GetChild(pageName, pEntityPage);
    MS2_ASSERT_AT(40, pEntityPage);
    m_page = new UITencentUserReportPage(m_data.type, pEntityPage);
    if (m_data.type == 15)
        m_page->FUN_140edcfd0(m_data.target);
    else
        m_page->FUN_140edcfd0(m_data.name);
    if (m_data.type == 3)
        m_page->m_itemKind = m_data.itemKind;
    m_page->FUN_140edd150(m_data.itemName);
    m_page->FUN_140edd2d0(m_data.name);
    m_page->FUN_140edd450();
    m_page->FUN_140edd730();
    m_page->FUN_140edc3b0();
    m_page->FUN_140edc8c0();
}
MS2_REPLACE_METHOD(0x140EDB530, UITencentUserReportDialog, OnLoadComplete, 983, 0x1308EACA);

// @0x140edb910
void UITencentUserReportDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_page = 0;
    m_data.FUN_140200f80();
}
MS2_REPLACE_METHOD(0x140EDB910, UITencentUserReportDialog, vfunc_26, 64, 0x7F2C392F);

// @0x140edb960
CString UITencentUserReportDialog::GetTypeName()
{
    return "TencentUserReportDialog";
}
MS2_REPLACE_METHOD(0x140EDB960, UITencentUserReportDialog, GetTypeName, 61, 0x7C9C1947);

// @0x140edb9b0
int UITencentUserReportDialog::vfunc_28(const char* method, const Scaleform::GFx::Value* args, unsigned int count)
{
    if (UIDialog::vfunc_28(method, args, count) == 1)
        return 1;
    if (!_stricmp("OnConfirmDialog", method)) {
        if (!m_page->FUN_140edca20())
            return 0;
        {
        MS2Ptr<Unk_ReportMessageBox> box = FUN_140d73e40(1, 0x8a7, 0, L"");
        if (box.get()) {
            box->FUN_141a024a0(0);
            box->FUN_141a027c0(Unk_ReportDelegate<bool(int, const CMsgBoxData&)>(this, &UITencentUserReportDialog::FUN_140edbc00));
            FUN_140d73c60(box);
            return 1;
        }
        }
        return 0;
    }
    if (!_stricmp("OnCancel", method)) {
        vfunc_67();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140EDB9B0, UITencentUserReportDialog, vfunc_28, 573, 0xEE622606);

// @0x140edbc00
bool UITencentUserReportDialog::FUN_140edbc00(int result, const CMsgBoxData&)
{
    if (result == 0) {
        FUN_140edbc60();
        SendRequestReport();
        vfunc_67();
        return true;
    } else if (result == 1) {
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140EDBC00, UITencentUserReportDialog, FUN_140edbc00, 86, 0x840E5AAC);

// @0x140edbc60
void UITencentUserReportDialog::FUN_140edbc60()
{
    if (m_page->FUN_140eddac0() == true) {
        switch (m_data.type) {
        case 3: FUN_140edbcf0(); break;
        case 4: FUN_140edbdd0(); break;
        case 16: FUN_140edbf80(); break;
        default: FUN_140edbe30(); break;
        }
    }
}
MS2_REPLACE_METHOD(0x140EDBC60, UITencentUserReportDialog, FUN_140edbc60, 133, 0x05E477DF);

// @0x140edbcf0
void UITencentUserReportDialog::FUN_140edbcf0()
{
    if (FUN_1409c1730()->FUN_140a25950(3, m_data.itemId) == true)
        FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyBlindTarget(3, reinterpret_cast<const Unk_ReportTarget&>(m_data.m_38))));
}
MS2_REPLACE_METHOD(0x140EDBCF0, UITencentUserReportDialog, FUN_140edbcf0, 216, 0x99A521CC);

// @0x140edbdd0
void UITencentUserReportDialog::FUN_140edbdd0()
{
    if (FUN_1409c1730()->FUN_140a25950(2, m_data.guildId) == true)
        FUN_14052d220()->FUN_1418885b0(m_data.guildNumber);
}
MS2_REPLACE_METHOD(0x140EDBDD0, UITencentUserReportDialog, FUN_140edbdd0, 76, 0x62053618);

// @0x140edbe30
void UITencentUserReportDialog::FUN_140edbe30()
{
    MS2Ptr<Unk_ReportContact> contact = FUN_14097a780()->FUN_140ae4950(m_data.name);
    if (contact.get() && contact->FUN_1401cc5b0() == 1)
        return;
    Unk_ReportContactRequest request;
    request.kind = 5;
    request.name = m_data.name;
    request.reason = GetStringCommon(0x8af);
    request.id = contact.get() ? contact->FUN_1401cc2f0() : 0;
    FUN_14097a780()->FUN_140ae4820(request);
}
MS2_REPLACE_METHOD(0x140EDBE30, UITencentUserReportDialog, FUN_140edbe30, 329, 0xC76388B8);

// @0x140edbf80
void UITencentUserReportDialog::FUN_140edbf80()
{
    if (FUN_1409c1730()->FUN_140a25730(5, m_data.content) == true)
        FUN_1403ed290()->FUN_1413baef0(m_data.m_28, 0);
}
MS2_REPLACE_METHOD(0x140EDBF80, UITencentUserReportDialog, FUN_140edbf80, 132, 0x3A397539);

// @0x140edc010
void UITencentUserReportDialog::SendRequestReport()
{
    m_data.reason = m_page->FUN_140eddc90();
    m_data.comment = m_page->FUN_140edddd0();
    m_data.reportComment = m_page->FUN_140edddd0();
    switch (m_data.reason) {
    case 22:
    case 36:
        m_data.reportTitle = m_data.title;
        m_data.reportPath = m_data.path;
        m_data.reportId = 0;
        break;
    }
    COutPacket packet(0x52, 0);
    m_data.FUN_140201180(packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140EDC010, UITencentUserReportDialog, SendRequestReport, 449, 0x6FD06EBB);

// @0x140edc1e0
UITencentUserReportPage::UITencentUserReportPage(int type, Unk_ReportHandle<Unk_ReportEntity> entity)
{
    m_type = type;
    m_entity = entity;
    m_itemKind = 0;
    FUN_140edc3b0();
}

// @0x140edc2c0
UITencentUserReportPage::~UITencentUserReportPage()
{
    for (int i = 0; i < 16; ++i)
        m_checks[i] = 0;
    m_text = 0;
    m_entity = 0;
}

// @0x140edc3b0
void UITencentUserReportPage::FUN_140edc3b0()
{
    for (int nIndex = 0; nIndex < 16; ++nIndex) {
        m_checks[nIndex] = 0;
        CString name;
        name.Format("m_checkBoxReportType%d", g_reportTypes[nIndex]);
        if (!((m_entity.get() ? true : false) && m_entity->GetChild(name, m_checks[nIndex]))) {
            MS2_ASSERT_AT(269, "m_pEntity && m_pEntity->GetChild(sCheckBoxName, m_aCheckBoxReportType[nIndex])" && 0);
            continue;
        }
    }
}
MS2_REPLACE_METHOD(0x140EDC3B0, UITencentUserReportPage, FUN_140edc3b0, 462, 0xE7EEF04F);

// @0x140edc590
void UITencentUserReportPage::FUN_140edc590(int enabled)
{
    for (int i = 0; i < 16; ++i) {
        if (m_checks[i].IsNull()) {
            MS2_ASSERT_AT(277, "m_aCheckBoxReportType[nIndex]" && 0);
            continue;
        }
        m_checks[i]->FUN_1422c1fe0(enabled);
    }
}
MS2_REPLACE_METHOD(0x140EDC590, UITencentUserReportPage, FUN_140edc590, 171, 0x54D4D610);

// Variadic entry: the hook thunk cannot forward an untyped argument list.
// @0x140edc650
void UITencentUserReportPage::FUN_140edc650(int enabled, int count, ...)
{
    FUN_140edc590(0);
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int index = FUN_140eddc40(va_arg(args, int));
        if (index < 0 || index > 15) {
            MS2_ASSERT_AT(295, "CHECK_RANGE(nReportTypeIndex, 0, REPORT_TYPE_COUNT - 1)" && 0);
            continue;
        }
        if (m_checks[index].IsNull()) {
            MS2_ASSERT_AT(296, "m_aCheckBoxReportType[nReportTypeIndex]" && 0);
            continue;
        }
        m_checks[index]->FUN_1422c1fe0(enabled);
    }
    va_end(args);
}

// @0x140edc7d0
void UITencentUserReportPage::FUN_140edc7d0(int type)
{
    for (int i = 0; i < 16; ++i) {
        if (m_checks[i].IsNull()) {
            MS2_ASSERT_AT(308, "m_aCheckBoxReportType[nIndex]" && 0);
            continue;
        }
        if (g_reportTypes[i] == type)
            m_checks[i]->FUN_1422ce090(1);
        m_checks[i]->FUN_1422c1fe0(0);
    }
}
MS2_REPLACE_METHOD(0x140EDC7D0, UITencentUserReportPage, FUN_140edc7d0, 234, 0xC26ED4A7);

// @0x140edc8c0
void UITencentUserReportPage::FUN_140edc8c0()
{
    if (m_type == 1 || m_type == 2)
        FUN_140edc650(1, 2, 25, 32);
    else if (m_type == 3) {
        if (m_itemKind == 1)
            FUN_140edc650(1, 2, 33, 41);
        else
            FUN_140edc650(1, 3, 23, 33, 25);
    } else if (m_type == 6 || m_type == 9)
        FUN_140edc7d0(13);
    else if (m_type == 4)
        FUN_140edc7d0(24);
    else if (m_type == 15)
        FUN_140edc7d0(34);
    else if (m_type == 16)
        FUN_140edc7d0(24);
    else
        FUN_140edc590(1);
}
MS2_REPLACE_METHOD(0x140EDC8C0, UITencentUserReportPage, FUN_140edc8c0, 345, 0x3377C28C);

// @0x140edca20
bool UITencentUserReportPage::FUN_140edca20()
{
    if (m_entity == NULL) {
        FUN_141275260(0x8ac, 1, 1);
        return false;
    }
    Unk_ReportHandle<Unk_ReportText> target;
    if ((m_entity.get() ? true : false) && m_entity->GetChild("m_textFieldTargetItemName", target)) {
        CStringW name = target->FUN_1422c4da0();
        if (name.GetLength() > 24) {
            FUN_141275260(0x8ac, 1, 1);
            return false;
        }
        if (name.IsEmpty() == true) {
            FUN_141275260(0x8ac, 1, 1);
            return false;
        }
    }
    Unk_ReportHandle<Unk_ReportText> comment;
    if (m_entity->GetChild("m_textAreaComment", comment) == NULL) {
        FUN_141275260(0x8ac, 1, 1);
        return false;
    }
    {
        CStringW text = comment->FUN_1422c4da0();
        if (text.GetLength() > 4000) {
            FUN_141275260(0x8ac, 1, 1);
            return false;
        }
        if (text.IsEmpty() == true) {
            FUN_141275260(0x8a4, 1, 1);
            return false;
        }
    }
    int checked = 0;
    for (int i = 0; i < 16; ++i) {
        if (m_checks[i].IsNull()) {
            MS2_ASSERT_AT(430, "m_aCheckBoxReportType[nIndex]" && 0);
            continue;
        }
        if (m_checks[i] == NULL) {
            FUN_141275260(0x8ac, 1, 1);
            return false;
        }
        if (m_checks[i]->FUN_1422ce0e0() == true)
            ++checked;
    }
    if (checked > 1) {
        FUN_141275260(0x8ac, 1, 1);
        return false;
    }
    if (checked == 0) {
        FUN_141275260(0x8a5, 1, 1);
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140EDCA20, UITencentUserReportPage, FUN_140edca20, 1445, 0xBBA73BF9);

// @0x140edcfd0
void UITencentUserReportPage::FUN_140edcfd0(CStringW name)
{
    Unk_ReportHandle<Unk_ReportText> text;
    if ((m_entity.get() ? true : false) && m_entity->GetChild("m_textFieldTargetName", text))
        text->FUN_1422c4cd0(name);
}
MS2_REPLACE_METHOD(0x140EDCFD0, UITencentUserReportPage, FUN_140edcfd0, 374, 0xFE5824BF);

// @0x140edd150
void UITencentUserReportPage::FUN_140edd150(CStringW name)
{
    Unk_ReportHandle<Unk_ReportText> text;
    if ((m_entity.get() ? true : false) && m_entity->GetChild("m_textFieldTargetItemName", text))
        text->FUN_1422c4cd0(name);
}
MS2_REPLACE_METHOD(0x140EDD150, UITencentUserReportPage, FUN_140edd150, 374, 0x721E8FEF);

// @0x140edd2d0
void UITencentUserReportPage::FUN_140edd2d0(CStringW name)
{
    Unk_ReportHandle<Unk_ReportText> text;
    if ((m_entity.get() ? true : false) && m_entity->GetChild("m_textFieldTargetItemSellerName", text))
        text->FUN_1422c4cd0(name);
}
MS2_REPLACE_METHOD(0x140EDD2D0, UITencentUserReportPage, FUN_140edd2d0, 374, 0x8887ABE7);

// @0x140edd450
void UITencentUserReportPage::FUN_140edd450()
{
    Unk_ReportHandle<Unk_ReportText> text;
    if ((m_entity.get() ? true : false) && m_entity->GetChild("m_textFieldWarnig", text)) {
        switch (m_type) {
        case 3: text->FUN_1422c4cd0(GetStringCommon(0x8b2)); break;
        case 4: text->FUN_1422c4cd0(GetStringCommon(0x8b1)); break;
        case 16: text->FUN_1422c4cd0(GetStringCommon(0x8b1)); break;
        default: text->FUN_1422c4cd0(GetStringCommon(0x8b0)); break;
        }
    }
}
MS2_REPLACE_METHOD(0x140EDD450, UITencentUserReportPage, FUN_140edd450, 715, 0x095FCB16);

// @0x140edd730
void UITencentUserReportPage::FUN_140edd730()
{
    Unk_ReportHandle<Unk_ReportCheck> check;
    if ((m_entity.get() ? true : false) && m_entity->GetChild("m_checkBoxBlock", check)) {
        switch (m_type) {
        case 3: check->FUN_1422cdfb0(FUN_14025e7a0()->FUN_1422b0570("$s_report_blind_contents_check")); break;
        case 4: check->FUN_1422cdfb0(FUN_14025e7a0()->FUN_1422b0570("$s_report_blind_contents_check")); break;
        case 16: check->FUN_1422cdfb0(FUN_14025e7a0()->FUN_1422b0570("$s_report_blind_contents_check")); break;
        default: check->FUN_1422cdfb0(FUN_14025e7a0()->FUN_1422b0570("$s_report_ban_character_check")); break;
        }
    }
}
MS2_REPLACE_METHOD(0x140EDD730, UITencentUserReportPage, FUN_140edd730, 899, 0x8E1EA5C2);

// @0x140eddac0
bool UITencentUserReportPage::FUN_140eddac0()
{
    Unk_ReportHandle<Unk_ReportCheck> check;
    if ((m_entity.get() ? true : false) && m_entity->GetChild("m_checkBoxBlock", check))
        return check->FUN_1422ce0e0();
    return false;
}
MS2_REPLACE_METHOD(0x140EDDAC0, UITencentUserReportPage, FUN_140eddac0, 376, 0xB7891EA5);

// @0x140eddc40
int UITencentUserReportPage::FUN_140eddc40(int type)
{
    for (int i = 0; i < 16; ++i)
        if (g_reportTypes[i] == type)
            return i;
    return -1;
}
MS2_REPLACE_METHOD(0x140EDDC40, UITencentUserReportPage, FUN_140eddc40, 73, 0x3D1259CD);

// @0x140eddc90
int UITencentUserReportPage::FUN_140eddc90()
{
    for (int i = 0; i < 16; ++i) {
        if (m_checks[i].IsNull()) {
            MS2_ASSERT_AT(570, "m_aCheckBoxReportType[nIndex]" && 0);
            continue;
        }
        if (m_checks[i]->FUN_1422ce0e0() == true)
            return FUN_140eddd60(i);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140EDDC90, UITencentUserReportPage, FUN_140eddc90, 193, 0x221A3BAB);

// @0x140eddd60
int UITencentUserReportPage::FUN_140eddd60(int index)
{
    if (index < 0 || index > 15) {
        MS2_ASSERT_AT(583, "CHECK_RANGE(nIndex, 0, REPORT_TYPE_COUNT - 1)" && 0);
        return 0;
    }
    return g_reportTypes[index];
}
MS2_REPLACE_METHOD(0x140EDDD60, UITencentUserReportPage, FUN_140eddd60, 97, 0x5A548407);

// @0x140edddd0
CStringW UITencentUserReportPage::FUN_140edddd0()
{
    Unk_ReportHandle<Unk_ReportText> comment;
    if ((m_entity.get() ? true : false) && m_entity->GetChild("m_textAreaComment", comment))
        return comment->FUN_1422c4da0();
    return L"";
}
MS2_REPLACE_METHOD(0x140EDDDD0, UITencentUserReportPage, FUN_140edddd0, 429, 0x45919D1D);

} // namespace TencentUserReport
