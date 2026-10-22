// Recovered Tencent user report classes; field names and supporting wrapper names are inferred.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include <utility>
class CMsgBoxData;
class COutPacket;
class Unk_ReportEntity;
class Unk_ReportText;
class Unk_ReportCheck;

// AS wrapper pointers; only this unit's inline copies/comparisons are defined.
template<class T> class Unk_ReportHandle {
public:
    Unk_ReportHandle();
    Unk_ReportHandle(int nullValue);
    Unk_ReportHandle(const Unk_ReportHandle& o) : m_p(o.m_p) { AddRef(); }
    ~Unk_ReportHandle();
    Unk_ReportHandle& operator=(int);
    Unk_ReportHandle& operator=(const Unk_ReportHandle& o) {
        o.AddRef(); Release(); m_p = o.m_p; return *this;
    }
    T* get() const;
    operator T*() const;
    T* operator->() const;
    bool IsNull() const { return m_p == 0; }
    bool operator!() const { return m_p == 0; }
    bool operator==(T*) const;
private:
    void AddRef() const;
    void Release();
    void* m_00;
    T* m_p;
};
template<class T> class Unk_ReportOwner
{
public:
    Unk_ReportOwner() : m_p(0) {}
    Unk_ReportOwner(T* p) : m_p(p) { AddRef(); }
    ~Unk_ReportOwner() { Release(); }
    Unk_ReportOwner& operator=(int) { Release(); return *this; }
    Unk_ReportOwner& operator=(T* p) {
        Unk_ReportOwner temp(p);
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

namespace TencentUserReport {
class UITencentUserReportPage;
struct Unk_ReportData {
    Unk_ReportData();
    ~Unk_ReportData();
    void FUN_140200f80();
    void FUN_140201180(COutPacket&);
    int type; int reason;
    CStringW name; CStringW target; CStringW itemName;
    __int64 m_20; int m_28; int m_2c; CStringW content;
    __int64 m_38; __int64 m_40;
    __int64 itemId; __int64 guildId;
    int guildNumber; int m_5c; CString m_60;
    CStringW comment; CStringW title; CString path;
    int itemKind; int m_84; __int64 m_88; __int64 m_90;
    CStringW m_98; CStringW reportTitle; __int64 reportId;
    CString reportPath; CStringW reportComment;
    __int64 m_c0; __int64 m_c8; CString m_d0;
    int m_d8; int m_dc; __int64 m_e0;
};
MS2_CHECK_SIZE(Unk_ReportData, 0xe8);
class UITencentUserReportDialog : public UIDialog {
public:
    UITencentUserReportDialog();
    virtual ~UITencentUserReportDialog();
    virtual void OnLoadInit();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual CString vfunc_1();
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    bool FUN_140edbc00(int result, const CMsgBoxData& data);
    void FUN_140edbc60();
    void FUN_140edbcf0();
    void FUN_140edbdd0();
    void FUN_140edbe30();
    void FUN_140edbf80();
    void SendRequestReport();
    // @0x140ede800
    virtual int vfunc_48() { return 20274; }
private:
    MS2_LAYOUT_FRIEND;
    Unk_ReportOwner<UITencentUserReportPage> m_page;
    Unk_ReportData m_data;
};
MS2_CHECK_SIZE(UITencentUserReportDialog, 0x270);
class UITencentUserReportPage : public CPtred {
public:
    UITencentUserReportPage(int type, Unk_ReportHandle<Unk_ReportEntity> entity);
    virtual ~UITencentUserReportPage();
    void FUN_140edc3b0();
    void FUN_140edc590(int enabled);
    void FUN_140edc650(int enabled, int count, ...);
    void FUN_140edc7d0(int type);
    void FUN_140edc8c0();
    bool FUN_140edca20();
    void FUN_140edcfd0(CStringW name);
    void FUN_140edd150(CStringW name);
    void FUN_140edd2d0(CStringW name);
    void FUN_140edd450();
    void FUN_140edd730();
    bool FUN_140eddac0();
    int FUN_140eddc40(int type);
    int FUN_140eddc90();
    int FUN_140eddd60(int index);
    CStringW FUN_140edddd0();
    void FUN_14015b020();
    int FUN_140159bc0();
    void FUN_140159ba0();
    int m_itemKind;
private:
    MS2_LAYOUT_FRIEND;
    Unk_ReportHandle<Unk_ReportEntity> m_entity;
    Unk_ReportHandle<Unk_ReportText> m_text;
    Unk_ReportHandle<Unk_ReportCheck> m_checks[16]; // real indexed checkbox array, not padding
    int m_type;
};
MS2_CHECK_SIZE(UITencentUserReportPage, 0x148);
}
MS2_CHECK_OFFSET(TencentUserReport::Unk_ReportData, comment, 0x68);
MS2_CHECK_OFFSET(TencentUserReport::Unk_ReportData, itemKind, 0x80);
MS2_CHECK_OFFSET(TencentUserReport::Unk_ReportData, reportComment, 0xb8);
MS2_CHECK_OFFSET(TencentUserReport::UITencentUserReportDialog, m_page, 0x178);
MS2_CHECK_OFFSET(TencentUserReport::UITencentUserReportDialog, m_data, 0x188);
MS2_CHECK_OFFSET(TencentUserReport::UITencentUserReportPage, m_itemKind, 0x18);
MS2_CHECK_OFFSET(TencentUserReport::UITencentUserReportPage, m_entity, 0x20);
MS2_CHECK_OFFSET(TencentUserReport::UITencentUserReportPage, m_checks, 0x40);
MS2_CHECK_OFFSET(TencentUserReport::UITencentUserReportPage, m_type, 0x140);
