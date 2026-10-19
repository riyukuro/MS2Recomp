// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Mentoring: the mentee register page. Field/helper names are inferred.
// MS2-UNIT: client\ms2\uimentoringmenteeregisterpage.cpp
// MS2-RANGE: 0x140c70480-0x140c71310 .text$mn
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIMentoringMenteeRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x140c71140 ; merge-bind
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIMentoringMenteeRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140c71160 ; merge-bind
// MS2-PIN: ??_GUIMentoringMenteeRegisterPage@@UEAAPEAXI@Z 0x140c711a0 ; merge-bind
// MS2-PIN: ??$FUN_14028dfa0@HHHHHHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBH11111AEBV01@@Z 0x140c70b70
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimentoringmenteeregisterpage.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uimentoringrewardpage.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
// The player actor (RTTI unknown): slot 77 returns the character name.
class Unk_MentorActorV
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24();
    virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34();
    virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44();
    virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49();
    virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54();
    virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64();
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69();
    virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74();
    virtual void vfunc_75(); virtual void vfunc_76();
    virtual CStringW GetName();     // 77 (+0x268)
};
class Unk_MentorWorldV { public: Unk_MentorActorV* FUN_141bd0cc0(); };
Unk_MentorWorldV* FUN_1403ed2d0();
// The event schedule (singleton chain 0x140302b00 -> 0x14041d160): start/end of the registration period.
class Unk_MentorIdArray;
class Unk_MentorSchedule { public: __int64 FUN_140424e60(); __int64 FUN_140424e20(); void FUN_140424ed0(Unk_MentorIdArray& ids); };
class Unk_MentorScheduleHolder { public: Unk_MentorSchedule* FUN_14041d160(); };
Unk_MentorScheduleHolder* FUN_140302b00();

CStringW FUN_14028dfa0(CStringW strKey, const fmt::ArgList& args);   // string table text, formatted
// The wide argument-type chain of this unit's FUN_14028dfa0<int x6, CStringW> instance (as in item.cpp's own two-argument one).
namespace fmt { namespace internal {
struct Unk_WcFormatter { typedef wchar_t Char; };
template <typename T> inline ULongLong wc_make_type(const T& arg) { return MakeValue<Unk_WcFormatter>::type(arg); }
struct Unk_WcArgType {
    ULongLong type;
    Unk_WcArgType() : type(0) {}
    template <typename T> Unk_WcArgType(const T& arg) : type(wc_make_type(arg)) {}
};
inline ULongLong wc_make_type(Unk_WcArgType t0 = Unk_WcArgType(), Unk_WcArgType t1 = Unk_WcArgType(), Unk_WcArgType t2 = Unk_WcArgType(),
                              Unk_WcArgType t3 = Unk_WcArgType(), Unk_WcArgType t4 = Unk_WcArgType(), Unk_WcArgType t5 = Unk_WcArgType(),
                              Unk_WcArgType t6 = Unk_WcArgType(), Unk_WcArgType t7 = Unk_WcArgType(), Unk_WcArgType t8 = Unk_WcArgType(),
                              Unk_WcArgType t9 = Unk_WcArgType(), Unk_WcArgType t10 = Unk_WcArgType(), Unk_WcArgType t11 = Unk_WcArgType(),
                              Unk_WcArgType t12 = Unk_WcArgType(), Unk_WcArgType t13 = Unk_WcArgType(), Unk_WcArgType t14 = Unk_WcArgType()) {
    return t0.type | (t1.type << 4) | (t2.type << 8) | (t3.type << 12) | (t4.type << 16) | (t5.type << 20) |
           (t6.type << 24) | (t7.type << 28) | (t8.type << 32) | (t9.type << 36) | (t10.type << 40) |
           (t11.type << 44) | (t12.type << 48) | (t13.type << 52) | (t14.type << 56);
}
} }
#define WC_REF(n) fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(v##n)
#define WC_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline CStringW FUN_14028dfa0(CStringW arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, WC_REF)}; \
        return FUN_14028dfa0(arg1, fmt::ArgList(fmt::internal::wc_make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
// @0x140c70b70
// MS2-FUNCTIONAL: fmt argument temporaries (2 extra frame slots, ArgType chain order) differ from the exe
WC_WRAP(7)
template CStringW FUN_14028dfa0<int, int, int, int, int, int, CStringW>(CStringW, const int&, const int&, const int&, const int&, const int&, const int&, const CStringW&);
CStringW FUN_14028b8e0(const CStringW& strKey);                     // string table text
class Unk_MentorChat { public: void FUN_1416fb340(CStringW& strText); };
Unk_MentorChat* FUN_1403b4750();
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
void FUN_140710590(COutPacket& pkt);
void FUN_141a024a0(CMsgBoxData* pBox, bool b);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
void FUN_140710590(COutPacket& pkt);
void FUN_141a024a0(CMsgBoxData* pBox, bool b);
// The register role byte (ctor 0x140c71120 always stores 4).
class Unk_MenteeRole
{
public:
    Unk_MenteeRole() { m_nRole = 4; }       // @0x140c71120
    void FUN_14069a480(COutPacket& pkt);
private:
    char m_nRole;
};

// @0x140c70480
UIMentoringMenteeRegisterPage::UIMentoringMenteeRegisterPage(UIMentoringDialog* p) : UIMentoringPage(p) {}
// @0x140c704c0
UIMentoringMenteeRegisterPage::~UIMentoringMenteeRegisterPage() {}

// @0x140c704f0
int UIMentoringMenteeRegisterPage::vfunc_1()
{
    if (UIMentoringPage::vfunc_1() == 0) return 0;
    return 1;
}

// @0x140c70520
void UIMentoringMenteeRegisterPage::vfunc_2()
{
    UIMentoringPage::vfunc_2();
}

// @0x140c70540
int UIMentoringMenteeRegisterPage::vfunc_5(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (UIMentoringPage::vfunc_5(szMethod, pArgs, nArgs)) return 1;
    if (_stricmp(szMethod, "onRegister") == 0)
    {
        Unk_MentorActorV* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pActor == 0) return 1;
        CMsTime tStart(FUN_140302b00()->FUN_14041d160()->FUN_140424e60());
        CMsTime tEnd(FUN_140302b00()->FUN_14041d160()->FUN_140424e20());
        int nStartYear, nStartMonth, nStartDay, nEndYear, nEndMonth, nEndDay;
        nEndDay = tEnd.GetDay();
        nEndMonth = tEnd.GetMonth();
        nEndYear = tEnd.GetYear();
        nStartDay = tStart.GetDay();
        nStartMonth = tStart.GetMonth();
        nStartYear = tStart.GetYear();
        CStringW strMsg = FUN_14028dfa0(CStringW(L"s_mentoring_mentee_register_warn"), nStartYear, nStartMonth, nStartDay, nEndYear, nEndMonth, nEndDay, pActor->GetName());
        FUN_1403b4750()->FUN_1416fb340(strMsg);
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, CStringW(strMsg), 0, CStringW(L""));
            if (spBox)
            {
                FUN_141a024a0(spBox.get(), false);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMentoringMenteeRegisterPage::FUN_140c709d0));
                FUN_140d73c60(spBox);
            }
        }
        return 1;
    }
    return 0;
}

// @0x140c70910
CString UIMentoringMenteeRegisterPage::vfunc_6() { return "MenteeRegisterPage"; }

// @0x140c70960
CStringW UIMentoringMenteeRegisterPage::vfunc_7() { return FUN_14028b8e0(L"s_mentoring_tab_register_mentee"); }

// @0x140c709d0
bool UIMentoringMenteeRegisterPage::FUN_140c709d0(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0) return true;
    COutPacket pkt(0xa1, 0);
    Unk_MenteeRole role;
    role.FUN_14069a480(pkt);
    FUN_140710590(pkt);
    return true;
}
