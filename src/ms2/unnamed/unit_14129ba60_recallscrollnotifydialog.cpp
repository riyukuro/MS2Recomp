// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIRecallScrollNotifyDialog: see
// placeholder/uirecallscrollnotifydialog.h. The unit is named after its first function (the ?\uirecallscrollnotifydialog.cpp
// guess was rejected; the range holds only this class).
// MS2-UNIT: unit_14129ba60
// MS2-RANGE: 0x14129ba60-0x14129cfa0 .text$mn
// MS2-RANGE: 0x1400ecca0-0x1400ece40 .text$di
// MS2-RANGE: 0x142caee90-0x142caef40 .text$yd
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uirecallscrollnotifydialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/uirecallscrollnotifydialog.h"
#include "ms2/placeholder/uibottomcenteralignmanager.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static CStringW s_strRecallConfirm(L"recallscrollconfirm");
#include "ms2/placeholder/header_statics_a.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASDialog : public ASDisplayObject {};

// The notify clip child (RTTI unknown): a movie clip.
class Unk_RsClip : public ASMovieClip {};

// The root script object of the dialog, as the Invoke back end sees it. Only the overloads this unit calls.
class Unk_RsScript
{
public:
    Scaleform::GFx::Value FUN_1409ba030(const char* szMethod, int a1);                  // 1 int
    Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int a1, CStringW a2);     // int, string
};
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* szText);

class Unk_RsWorld { public: MS2Ptr<CFieldDataCli> FUN_141bd30a0(); };
Unk_RsWorld* FUN_1403ed2d0();
CStringTable* GetStringTable();
CStringW FUN_140632a60(int nId, const CStringW& strA, const CStringW& strB);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
CStringW FUN_14183e930(const CStringW& str, int nColor);
UIBottomCenterAlignManager* FUN_140c24ef0();
int FUN_1418dd0d0();
__int64 FUN_140869440();                                // the server time

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14129ba60
UIRecallScrollNotifyDialog::UIRecallScrollNotifyDialog()
{
    m_nOffset = 0;
    m_bActive = false;
    m_nCount = 0;
    for (int i = 0; i < 3; i++) {
        m_times[i] = 0;
        m_names[i] = L"";
        m_fields[i] = 0;
        m_clips[i] = 0;
    }
}

// @0x14129cdc0
UIRecallScrollNotifyDialog::~UIRecallScrollNotifyDialog() {}

// @0x14129cca0
// MS2-FUNCTIONAL: pointer assignment glue, emitted by the compiler's own MS2Ptr operator=
MS2Ptr<ASMovieClip>* FUN_14129cca0(MS2Ptr<ASMovieClip>* pDst, MS2Ptr<ASMovieClip>* pSrc)
{
    *pDst = *pSrc;
    return pDst;
}

// @0x14129bc10
CString UIRecallScrollNotifyDialog::GetTypeName() { return "RecallScrollNotifyDialog"; }

// @0x14129bc60
int UIRecallScrollNotifyDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x14129bc90
void UIRecallScrollNotifyDialog::vfunc_67()
{
    UIBuiltInDialog::vfunc_67();
    for (int i = 0; i < 3; i++) {
        m_times[i] = 0;
        m_names[i] = L"";
        m_fields[i] = 0;
        m_clips[i] = 0;
    }
}

// @0x14129bd50
void UIRecallScrollNotifyDialog::OnLoadInit() { UIBuiltInDialog::OnLoadInit(); }

// @0x14129bd70
void UIRecallScrollNotifyDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    for (int i = 0; i < 3; i++)
        m_clips[i] = 0;
}

// @0x14129bdd0
void UIRecallScrollNotifyDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_clips[1] = FUN_140ba4b70("m_partyNotify");
    m_clips[0] = FUN_140ba4b70("m_guildNotify");
    m_clips[2] = FUN_140ba4b70("m_weddingNotify");
    CMsTime now(FUN_140869440());
    for (int i = 0; i < 3; i++) {
        if (m_times[i] > now) {
            ATL::CTimeSpan span = m_times[i] - now;
            reinterpret_cast<Unk_RsScript*>(m_30.operator->())->FUN_14129cce0("OpenNotify", i, FUN_14129cb50(span));
        }
    }
}

// @0x14129c0b0
void UIRecallScrollNotifyDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(2, 0, FUN_1418dd0d0() * -1 + m_nOffset);
}

// @0x14129c140
int UIRecallScrollNotifyDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    return 0;
}

// @0x14129c170
int UIRecallScrollNotifyDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField == 0) return 0;
    if (!_stricmp(szMethod, "OnNotify")) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            int nSlot = data.FUN_1422b8a10();
            if (nSlot < 0 || nSlot >= 3)
                return 1;
            MS2Ptr<CFieldDataCli> spSender = CFieldDataCli::Find(m_fields[nSlot]);
            if (spSender == 0) return 0;
            CStringW strMsg = FUN_140632a60(0xb62, m_names[nSlot], GetStringTable()->FUN_141811980(3, m_fields[nSlot]));
            {
                MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, CStringW(strMsg), 0, CStringW(s_strRecallConfirm));
                if (box.get() != 0) {
                    box->FUN_140533ff0(nSlot);
                    box->FUN_140b76940(CStringW(m_names[nSlot]));
                    box->FUN_140534050(m_fields[nSlot]);
                    box->FUN_141a02460(1);
                    box->FUN_141a02480(1);
                    box->FUN_141a024a0(0);
                    box->FUN_141a01700(0x477, 0x478, 0);
                    FUN_140d73c60(MS2Ptr<CMsgBoxData>(box));
                }
            }
            return 1;
        }
    }
    return 0;
}

// @0x14129c610
void UIRecallScrollNotifyDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (FUN_1422dc2d0() == 0)
        return;
    if (m_tick.FUN_140268870(1000) != 0) {
        CMsTime now(FUN_140869440());
        int nActive = 0;
        for (int i = 0; i < 3; i++) {
            CMsTime zero(0);
            if (m_times[i] == zero)
                continue;
            if (m_clips[i].get() != 0 ? true : false) {
                if (m_clips[i]->FUN_1422bfca0()) {
                    nActive = nActive + 1;
                    if (now > m_times[i]) {
                        reinterpret_cast<Unk_RsScript*>(m_30.operator->())->FUN_1409ba030("CloseNotify", i);
                    } else {
                        ATL::CTimeSpan span = m_times[i] - now;
                        reinterpret_cast<Unk_RsScript*>(m_30.operator->())->FUN_14129cce0("UpdateNotify", i, FUN_14129cb50(span));
                    }
                }
            }
        }
        if (m_nCount != nActive) {
            m_nCount = nActive;
            FUN_14129cc60(m_nCount != 0);
        }
    }
}

// @0x14129c8e0
void UIRecallScrollNotifyDialog::SetOffset(int nOffset) { m_nOffset = nOffset; }

// @0x14129c900
bool UIRecallScrollNotifyDialog::IsActive() { return m_bActive; }

// @0x14129c920
void UIRecallScrollNotifyDialog::FUN_14129c920(int nSlot, __time64_t nTime, const CStringW& strName, int nField)
{
    m_times[nSlot] = nTime;
    m_names[nSlot] = strName;
    m_fields[nSlot] = nField;
    if (FUN_1422dc2d0() == 0)
        return;
    CMsTime now(FUN_140869440());
    ATL::CTimeSpan span = m_times[nSlot] - now;
    reinterpret_cast<Unk_RsScript*>(m_30.operator->())->FUN_14129cce0("OpenNotify", nSlot, FUN_14129cb50(span));
    FUN_14129cc60(true);
}

// @0x14129caa0
void UIRecallScrollNotifyDialog::FUN_14129caa0(int nSlot)
{
    m_times[nSlot] = 0;
    if (FUN_1422dc2d0() == 0)
        return;
    reinterpret_cast<Unk_RsScript*>(m_30.operator->())->FUN_1409ba030("CloseNotify", nSlot);
}

// @0x14129cb20
void UIRecallScrollNotifyDialog::FUN_14129cb20() { memset(m_times, 0, sizeof(m_times)); }

// @0x14129cb50
CStringW UIRecallScrollNotifyDialog::FUN_14129cb50(ATL::CTimeSpan span)
{
    CStringW str;
    str.Format(L"%02d:%02d", span.GetMinutes(), span.GetSeconds());
    int nColor = 0xffffff;
    if (span.GetTotalSeconds() <= 10)
        nColor = 0xff0000;
    str = FUN_14183e930(str, nColor);
    return str;
}

// @0x14129cc60
void UIRecallScrollNotifyDialog::FUN_14129cc60(bool bActive)
{
    m_bActive = bActive;
    if (FUN_140c24ef0() != 0)
        FUN_140c24ef0()->FUN_140bc1730();
}

// @0x14129cce0
Scaleform::GFx::Value Unk_RsScript::FUN_14129cce0(const char* szMethod, int a1, CStringW a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), (const wchar_t*)a2);
    return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
