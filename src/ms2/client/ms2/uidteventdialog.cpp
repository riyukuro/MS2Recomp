// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Timed event reward list ("DTEventDialog").
// MS2-UNIT: client\ms2\uidteventdialog.cpp
// MS2-RANGE: 0x140f359b0-0x140f3a810 .text$mn
// MS2-RANGE: 0x1400ded40-0x1400deeb0 .text$di
// MS2-RANGE: 0x142ca9380-0x142ca9410 .text$yd
// MS2-PIN: ?GetAt@?$CAtlList@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@PEAU__POSITION@@@Z 0x140f396a0
// MS2-PIN: ?AddRefObject@?$Unk_DTPtr@VRewardItem@UIDTEventDialog@@@@CAXPEAVRewardItem@UIDTEventDialog@@@Z 0x140f3a730
// MS2-PIN: ??$Unk_Fmt3@JJJ@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBJ11@Z 0x140f38940
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$MS2Ptr@VDTRewardEventContext@CommonUserEvent@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VDTRewardEventContext@CommonUserEvent@@@@@3@@ATL@@QEAAPEAVCPair@12@H@Z 0x140f39b70
// MS2-PIN: ?AddRefImpl@?$Unk_DTPtr@VRewardItem@UIDTEventDialog@@@@AEBAXPEAX@Z 0x140f3a750
// MS2-PIN: ?ReleaseImpl@?$Unk_DTPtr@VRewardItem@UIDTEventDialog@@@@AEAAXPEAX@Z 0x140f3a7c0
// MS2-PIN: ?vfunc_48@UIDTEventDialog@@UEAAHXZ 0x140f39970
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidteventdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uidteventdialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/gfxui/uialignwidget.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cusereventmanager.h"
#include "ms2/commonfiles/gameeventuservalue.h"
#include "ms2/commonfiles/usereventcontext.h"

// ---- the unit's header statics (this unit includes them in a different order than header_statics_a.h) ----
static CString s_skill("skill");
static CString s_stun("stun");
static ATL::CAtlMap<unsigned int, CString> s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----
typedef UIDTEventDialog::RewardItem Unk_DTReward;

extern GameEventUserValue DAT_143ab2fc0;
extern GameEventUserValue DAT_143ab3010;

// GameEventUserValue::GetValue<int> (0x1409617d0): its GameEventVariable::GetValue<int> has no body yet.
class Unk_AttendTable { public: int GetValue(int nKind, unsigned int nId, const int& nDefault); };

// The root AS object of the dialog movie and the clip kinds used here.
class ASDialog : public ASDisplayObject
{
};
class Unk_DTMovie : public ASMovieClip
{
};


// An AS object created on the C++ side (AScript with type 2); the unsigned setter FUN_1409c0d20 is AScript's.
typedef AScript ASObj;







class ASTooltip : public AScript
{
public:
    ASTooltip(void* pOwner, int a1, int a2);
    virtual ~ASTooltip();
    int FUN_1409e0d40(class CItem* pItem);
private:
    void* m_40; void* m_48; void* m_50; void* m_58;
};
MS2_CHECK_SIZE(ASTooltip, 0x60);

// The item class (0x1a0 bytes).
class CItem
{
public:
    CItem();
    bool FUN_140523c40(int nId, int nRarity, int nFlag);
    int FUN_14052b130(int nId, int nRarity, int nFlag);
    void SetCountClamped(int nCount);
private:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38;
    void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68; void* m_70; void* m_78;
    void* m_80; void* m_88; void* m_90; void* m_98; void* m_a0; void* m_a8; void* m_b0; void* m_b8;
    void* m_c0; void* m_c8; void* m_d0; void* m_d8; void* m_e0; void* m_e8; void* m_f0; void* m_f8;
    void* m_100; void* m_108; void* m_110; void* m_118; void* m_120; void* m_128; void* m_130; void* m_138;
    void* m_140; void* m_148; void* m_150; void* m_158; void* m_160; void* m_168; void* m_170; void* m_178;
    void* m_180; void* m_188; void* m_190; void* m_198;
};
MS2_CHECK_SIZE(CItem, 0x1a0);
void CreateItemInfoSlot(const CString& strName, MS2Ptr<CItem> pItem, int a1, int a2, int a3);

// The local player: a large virtual class; slot 78 is the level.
class Unk_DTPlayer
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
    virtual void vfunc_75(); virtual void vfunc_76(); virtual void vfunc_77();
    virtual unsigned short vfunc_78();                              // level
};

// A sound / effect player (singleton 0x140e45740).
class Unk_DTSound : public UIAlignWidgetManager { };
class Unk_140e45740* FUN_140e45740();   // C3: was FUN_140e45740

class UIMinimapDialog* FUN_140c9b540(int);   // C3: was FUN_140c9b540


// ---- the "{0:02}:{1:02}:{2:02}" formatter (0x140f38940): StringFormat's 3-argument variadic body, but with its own
// MakeValue copy (the exe has MakeValue(int) 0x14086d170 here and 0x140163770 for the shared one) ----
namespace fmt { namespace internal { struct Unk_DtFormatter { typedef wchar_t Char; }; } }
#define DT_REF(n) fmt::internal::MakeValue<fmt::internal::Unk_DtFormatter>(v##n)
template <typename T0, typename T1, typename T2>
CStringW Unk_Fmt3(const wchar_t* format, const T0& v0, const T1& v1, const T2& v2)
{
    const fmt::internal::ArgArray<3>::Type array = {DT_REF(0), DT_REF(1), DT_REF(2)};
    return StringFormat(format, fmt::ArgList(fmt::internal::make_type(v0, v1, v2), array));
}

// ---- explicit specializations of the pointer members that are this unit's COMDATs ----
template <> void Unk_DTPtr<Unk_DTReward>::AddRef() const;
template <> void Unk_DTPtr<Unk_DTReward>::Release();
template <> inline Unk_DTPtr<Unk_DTReward>::Unk_DTPtr() : m_p(0) {}                                        // 0x140f38e80
template <> inline Unk_DTPtr<Unk_DTReward>::Unk_DTPtr(int) : m_p(0) {}                                     // 0x140f38e30
template <> inline Unk_DTPtr<Unk_DTReward>::Unk_DTPtr(Unk_DTReward* p) : m_p(p) { AddRef(); }              // 0x140f38e50
template <> inline Unk_DTPtr<Unk_DTReward>::Unk_DTPtr(const Unk_DTPtr& o) : m_p(o.m_p) { AddRef(); }       // 0x140f38df0
template <> inline Unk_DTPtr<Unk_DTReward>::~Unk_DTPtr() { Release(); }                                    // 0x140f39020
template <> inline Unk_DTPtr<Unk_DTReward>& Unk_DTPtr<Unk_DTReward>::operator=(const Unk_DTPtr& o)         // 0x140f39100
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <> inline bool Unk_DTPtr<Unk_DTReward>::operator==(Unk_DTReward* p) const { return m_p == p; }    // 0x140f39180
template <> inline Unk_DTPtr<Unk_DTReward>::operator Unk_DTReward*() const { return m_p; }                 // 0x140f39250
template <> inline Unk_DTReward* Unk_DTPtr<Unk_DTReward>::operator->() const { return m_p; }               // 0x140f39260
template <> inline void Unk_DTPtr<Unk_DTReward>::AddRefObject(Unk_DTReward* p)                             // 0x140f3a730
{
    CPtred::AddRefPtred(p);
}
template <> inline void Unk_DTPtr<Unk_DTReward>::AddRefImpl(void*) const { AddRefObject(m_p); }              // 0x140f3a750
template <> inline void Unk_DTPtr<Unk_DTReward>::ReleaseImpl(void*)                                          // 0x140f3a7c0
{
    if (CPtred::ReleasePtred(m_p) == 0) {
        AddRefObject(m_p);
        CPtred::DeletePtred(m_p);
    }
}
template <> inline void Unk_DTPtr<Unk_DTReward>::AddRef() const { if (m_p) AddRefImpl(0); }                // 0x140f3a700
template <> inline void Unk_DTPtr<Unk_DTReward>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }      // 0x140f3a780

template <> inline bool MS2Ptr<EventStruct::DTReward>::operator==(EventStruct::DTReward* p) const { return m_p == p; }    // 0x140f39140
template <> inline MS2Ptr<CommonUserEvent::DTRewardEventContext>::operator CommonUserEvent::DTRewardEventContext*() const { return m_p; }    // 0x140f39240

// @0x1400ded40
// @0x1400ded70
// @0x1400deda0
// @0x1400dedf0
// (the four initializers above are the statics at the top)

// @0x140f359b0
UIDTEventDialog::UIDTEventDialog()
    : m_active(17, 0.75f, 0.25f, 2.25f, 10), m_pending(17, 0.75f, 0.25f, 2.25f, 10), m_ctx(17, 0.75f, 0.25f, 2.25f, 10),
      m_binds(10)
{
    m_2c = 0x19;
    FUN_141925e70(0, 1);
    m_timer.Init();
}

// @0x140f35b20
UIDTEventDialog::~UIDTEventDialog()
{
}

// @0x140f35bb0
CString UIDTEventDialog::GetTypeName()
{
    return "DTEventDialog";
}
MS2_REPLACE_METHOD(0x140F35BB0, UIDTEventDialog, GetTypeName, 61, 0x85A1FB0B);

// @0x140f35c00
void UIDTEventDialog::vfunc_67()
{
    for (POSITION pos = m_binds.GetHeadPosition(); pos != NULL; m_binds.GetNext(pos))
        DestroyItemInfoSlot(m_binds.GetAt(pos));
    m_binds.RemoveAll();
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140F35C00, UIDTEventDialog, vfunc_67, 135, 0x69B9630D);

// @0x140f35c90
int UIDTEventDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140F35C90, UIDTEventDialog, vfunc_65, 37, 0x6A349588);

// @0x140f35cc0
void UIDTEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_timer.Init();
    m_active.RemoveAll();
    m_pending.RemoveAll();
    m_ctx.RemoveAll();
    ATL::CAtlArray<MS2Ptr<CommonUserEvent::DTRewardEventContext> > ctxs;
    TSingleton<CUserEventManager>::GetInstance()->GetAllDTReward(ctxs);
    for (unsigned int i = 0; i < ctxs.GetCount(); i++)
        FUN_140f38430(ctxs[i]);
}
MS2_REPLACE_METHOD(0x140F35CC0, UIDTEventDialog, OnLoadComplete, 282, 0xFD2CF139);

// @0x140f35de0
int UIDTEventDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140F35DE0, UIDTEventDialog, vfunc_28, 67, 0x9725EABA);

// @0x140f35e30
void UIDTEventDialog::vfunc_43()
{
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog != NULL) {
        bool bMove = false;
        int bIdle = m_60 == 0 && m_78 != 0 && vfunc_52() != 0;
        if (bIdle) {
            if (!((float)dialog->FUN_1422c1500() >= dialog->FUN_1422c10a0() &&
                  (float)dialog->FUN_1422c1530() >= dialog->FUN_1422c1110() &&
                  dialog->FUN_1422c10a0() >= 0.0f && dialog->FUN_1422c1110() >= 0.0f))
                bMove = true;
        } else
            bMove = true;
        UISwfEntity* pOwner;
        if (bMove && (pOwner = ((class UISwfEntity*)FUN_140c9b540(0x4e29))) != NULL) {
            if (pOwner->FUN_1422dc430() == 0)
                m_60 = 1;
            else {
                int nRemain = 0;
                if (MS2Ptr<ASMovieClip> movie = dynamic_cast<ASMovieClip*>((AScript*)pOwner->FUN_1422dba00())) {
                    double fValue = 0.0;
                    double fExtra = 0.0;
                    if (reinterpret_cast<Unk_DTMovie*>(movie.operator->())->FUN_1422c2510(&fValue, &fExtra))
                        nRemain = (int)(fValue - (double)dialog->FUN_1422c1340());
                }
                dialog->SetPositionInt(nRemain > 0 ? nRemain : 0, 0x1c);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140F35E30, UIDTEventDialog, vfunc_43, 718, 0x455C8C11);

// @0x140f36110
void UIDTEventDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (!FUN_1422dc2d0()) return;
    if (m_30 == NULL) return;
    if (!m_timer.Check(1000)) return;
    {
        FUN_140f38750();
        ATL::CAtlArray<unsigned int> ids;
        for (POSITION pos = m_pending.GetStartPosition(); pos != NULL; m_pending.GetNext(pos)) {
            Unk_DTPtr<Unk_DTReward> pReward(m_pending.GetValueAt(pos));
            MS2_ASSERT_AT(186, pReward != NULL);
            if (IsEarlierDay(CMsTime(pReward->m_start), CMsTime(GetServerTime()), 0)) {
                if (vfunc_84(pReward) == 1) {
                    ids.Add(m_pending.GetKeyAt(pos));
                    m_active.SetAt(pReward->m_ctx->m_id, pReward);
                }
            }
        }
        for (unsigned int i = 0; i < ids.GetCount(); i++) {
            unsigned int nKey = ids[i];
            if (m_pending.Lookup(nKey) != NULL)
                m_pending.RemoveKey(nKey);
        }
        ids.RemoveAll();
        for (POSITION pos = m_active.GetStartPosition(); pos != NULL; m_active.GetNext(pos)) {
            Unk_DTPtr<Unk_DTReward> pReward(m_active.GetValueAt(pos));
            MS2_ASSERT_AT(211, pReward != NULL);
            if (vfunc_85(pReward) == 0)
                ids.Add(m_active.GetKeyAt(pos));
        }
        for (unsigned int i = 0; i < ids.GetCount(); i++) {
            unsigned int nKey = ids[i];
            Unk_DTPtr<Unk_DTReward> pMoved(0);
            if (m_active.Lookup(nKey, pMoved)) {
                m_active.RemoveKey(nKey);
                m_pending.SetAt(nKey, pMoved);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140F36110, UIDTEventDialog, vfunc_72, 1278, 0x5CC99485);

// @0x140f36620
int UIDTEventDialog::vfunc_84(Unk_DTPtr<RewardItem> pReward)
{
    if (FUN_1422dc2d0() == 0)
        return 0;
    if (m_30 == NULL)
        return 0;
    if (pReward == NULL)
        return 0;
    GameEventUserValue& rTable = pReward->m_ctx->m_b33 ? DAT_143ab3010 : DAT_143ab2fc0;
    int nDefault = 0;
    pReward->m_step = reinterpret_cast<Unk_AttendTable&>(rTable).GetValue(0x2be, pReward->m_ctx->m_id, nDefault);
    if (pReward->m_ctx->m_rewards.GetCount() <= pReward->m_step)
        return 0;
    MS2Ptr<EventStruct::DTReward> pStep(pReward->m_ctx->m_rewards[(int)pReward->m_step]);
    if (pStep == NULL)
        return 0;
    __int64 nDefault64 = 0;
    pReward->m_start = rTable.GetValue<__int64>(700, pReward->m_ctx->m_id, nDefault64);
    int nDefault2 = 0;
    pReward->m_elapsed = reinterpret_cast<Unk_AttendTable&>(rTable).GetValue(0x2bd, pReward->m_ctx->m_id, nDefault2);
    __int64 now = GetServerTime();
    if (pReward->m_start == 0)
        pReward->m_start = now;
    CTimeSpan elapsed(now - pReward->m_start);
    pReward->m_elapsed += elapsed.GetTotalSeconds();
    if (pReward->m_elapsed > (unsigned int)pStep->b)
        pReward->m_elapsed = (unsigned int)pStep->b;
    CTimeSpan remain(0);
    if ((unsigned int)pStep->b > pReward->m_elapsed)
        remain = (unsigned int)pStep->b - pReward->m_elapsed;
    float fElapsed = (float)pReward->m_elapsed;
    int nGauge = (int)(fElapsed * (100.0f / (float)(unsigned int)pStep->b));
    CStringW strRemain = FUN_140f388c0(&remain);
    int bVibrate = 0;
    if (remain.GetTotalSeconds() <= 10)
        bVibrate = 1;
    ASObj obj(2);
    CString strBindID;
    MS2Ptr<CItem> item(new CItem);
    if (item->FUN_140523c40(pStep->d, pStep->f, 0)) {
        item->SetCountClamped(pStep->e);
        strBindID.Format("%s_%d", (LPCSTR)GetTypeName(), m_binds.GetCount() + 1);
        CreateItemInfoSlot(strBindID, item, 0, 0x415, 0);
        m_binds.AddTail(strBindID);
    }
    obj.SetMemberUInt("eventID", pReward->m_ctx->m_id);
    obj.FUN_1407cba60("bindID", strBindID);
    obj.SetMemberUInt("itemCount", pStep->e);
    obj.FUN_1407cbb20("remainTime", strRemain);
    obj.FUN_1407cb9c0("gaugeRate", nGauge);
    obj.FUN_1407cb9c0("vibrate", bVibrate);
    m_30->Invoke("addItem", obj.FUN_1422bb870());
    ((class Unk_DTSound*)FUN_140e45740())->FUN_1422e6d00(0);
    return 1;
}
MS2_REPLACE_METHOD(0x140F36620, UIDTEventDialog, vfunc_84, 2429, 0x4EA48E5D);

// @0x140f36fb0
int UIDTEventDialog::vfunc_85(Unk_DTPtr<RewardItem> pReward)
{
    if (m_30 == NULL)
        return 0;
    if (pReward == NULL)
        return 0;
    GameEventUserValue& rTable = pReward->m_ctx->m_b33 ? DAT_143ab3010 : DAT_143ab2fc0;
    int nDefault = 0;
    unsigned int nStep = reinterpret_cast<Unk_AttendTable&>(rTable).GetValue(0x2be, pReward->m_ctx->m_id, nDefault);
    if (pReward->m_ctx->m_rewards.GetCount() <= nStep) {
        vfunc_86(pReward);
        return 0;
    }
    if (pReward->m_step != nStep)
        return vfunc_87(pReward, nStep);
    pReward->m_step = nStep;
    MS2Ptr<EventStruct::DTReward> pStep(pReward->m_ctx->m_rewards[(int)pReward->m_step]);
    if (pStep == NULL)
        return 0;
    __int64 nDefault64 = 0;
    pReward->m_start = rTable.GetValue<__int64>(700, pReward->m_ctx->m_id, nDefault64);
    int nDefault2 = 0;
    pReward->m_elapsed = reinterpret_cast<Unk_AttendTable&>(rTable).GetValue(0x2bd, pReward->m_ctx->m_id, nDefault2);
    __int64 now = GetServerTime();
    if (pReward->m_start == 0)
        pReward->m_start = now;
    CTimeSpan elapsed(now - pReward->m_start);
    pReward->m_elapsed += elapsed.GetTotalSeconds();
    if (pReward->m_elapsed > (unsigned int)pStep->b)
        pReward->m_elapsed = (unsigned int)pStep->b;
    CTimeSpan remain(0);
    if ((unsigned int)pStep->b > pReward->m_elapsed)
        remain = (unsigned int)pStep->b - pReward->m_elapsed;
    int bVibrate = 0;
    if (remain.GetTotalSeconds() <= 1)
        bVibrate = 1;
    float fElapsed = (float)pReward->m_elapsed;
    int nGauge = (int)(fElapsed * (100.0f / (float)(unsigned int)pStep->b));
    CStringW strRemain = FUN_140f388c0(&remain);
    ASObj obj(2);
    obj.SetMemberUInt("eventID", pReward->m_ctx->m_id);
    obj.FUN_1407cbb20("remainTime", strRemain);
    obj.FUN_1407cb9c0("gaugeRate", nGauge);
    obj.FUN_1407cb9c0("vibrate", bVibrate);
    m_30->Invoke("updateItem", obj.FUN_1422bb870());
    return 1;
}
MS2_REPLACE_METHOD(0x140F36FB0, UIDTEventDialog, vfunc_85, 1854, 0x3AA4CF0B);

// @0x140f37700
int UIDTEventDialog::vfunc_86(Unk_DTPtr<RewardItem> pReward)
{
    if (m_30 == NULL)
        return 0;
    if (pReward == NULL)
        return 0;
    ASObj obj(2);
    obj.SetMemberUInt("eventID", pReward->m_ctx->m_id);
    m_30->Invoke("removeItem", obj.FUN_1422bb870());
    return 1;
}
MS2_REPLACE_METHOD(0x140F37700, UIDTEventDialog, vfunc_86, 350, 0xAE829E19);

// @0x140f37870
int UIDTEventDialog::vfunc_87(Unk_DTPtr<RewardItem> pReward, unsigned int nStep)
{
    if (FUN_1422dc2d0() == 0)
        return 0;
    if (m_30 == NULL)
        return 0;
    if (pReward == NULL)
        return 0;
    pReward->m_step = nStep;
    MS2Ptr<EventStruct::DTReward> pStep(pReward->m_ctx->m_rewards[(int)pReward->m_step]);
    if (pStep == NULL)
        return 0;
    GameEventUserValue& rTable = pReward->m_ctx->m_b33 ? DAT_143ab3010 : DAT_143ab2fc0;
    __int64 nDefault64 = 0;
    pReward->m_start = rTable.GetValue<__int64>(700, pReward->m_ctx->m_id, nDefault64);
    int nDefault2 = 0;
    pReward->m_elapsed = reinterpret_cast<Unk_AttendTable&>(rTable).GetValue(0x2bd, pReward->m_ctx->m_id, nDefault2);
    __int64 now = GetServerTime();
    if (pReward->m_start == 0)
        pReward->m_start = now;
    CTimeSpan elapsed(now - pReward->m_start);
    pReward->m_elapsed += elapsed.GetTotalSeconds();
    if (pReward->m_elapsed > (unsigned int)pStep->b)
        pReward->m_elapsed = (unsigned int)pStep->b;
    CTimeSpan remain(0);
    if ((unsigned int)pStep->b > pReward->m_elapsed)
        remain = (unsigned int)pStep->b - pReward->m_elapsed;
    float fElapsed = (float)pReward->m_elapsed;
    int nGauge = (int)(fElapsed * (100.0f / (float)(unsigned int)pStep->b));
    CStringW strRemain = FUN_140f388c0(&remain);
    int bVibrate = 0;
    if (remain.GetTotalSeconds() <= 1)
        bVibrate = 1;
    ASObj obj(2);
    CString strBindID;
    MS2Ptr<CItem> item(new CItem);
    if (item->FUN_140523c40(pStep->d, pStep->f, 0)) {
        item->SetCountClamped(pStep->e);
        strBindID.Format("%s_%d", (LPCSTR)GetTypeName(), m_binds.GetCount() + 1);
        CreateItemInfoSlot(strBindID, item, 0, 0x415, 0);
        m_binds.AddTail(strBindID);
    }
    obj.FUN_1407cb9c0("change", 1);
    obj.SetMemberUInt("eventID", pReward->m_ctx->m_id);
    obj.FUN_1407cba60("bindID", strBindID);
    obj.SetMemberUInt("itemCount", pStep->e);
    obj.FUN_1407cbb20("remainTime", strRemain);
    obj.FUN_1407cb9c0("gaugeRate", nGauge);
    obj.FUN_1407cb9c0("vibrate", bVibrate);
    m_30->Invoke("updateItem", obj.FUN_1422bb870());
    return 1;
}
MS2_REPLACE_METHOD(0x140F37870, UIDTEventDialog, vfunc_87, 2268, 0x641A42AF);

// @0x140f38160
void UIDTEventDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    Unk_DTPlayer* pPlayer = reinterpret_cast<Unk_DTPlayer*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return;
    unsigned int nID = pArgs->PopUInt();
    Unk_DTPtr<Unk_DTReward> pReward(0);
    if (!m_active.Lookup(nID, pReward))
        return;
    MS2Ptr<EventStruct::DTReward> pStep(pReward->m_ctx->m_rewards[(int)pReward->m_step]);
    if (pStep == NULL)
        return;
    MS2Ptr<CItem> item(new CItem);
    if (item->FUN_14052b130(pStep->d, pStep->f, 0)) {
        item->SetCountClamped(pStep->e);
        ASTooltip tooltip(pPlayer, 0x20, 2);
        if (tooltip.FUN_1409e0d40(item.get())) {
            *pRetVal = tooltip.FUN_1422bb870();
            return;
        }
    }
}
MS2_REPLACE_METHOD(0x140F38160, UIDTEventDialog, vfunc_49, 700, 0x9E104B3A);

// @0x140f38430
void UIDTEventDialog::FUN_140f38430(MS2Ptr<CommonUserEvent::DTRewardEventContext> pCtx)
{
    Unk_DTPtr<Unk_DTReward> pReward(new RewardItem);
    if (pReward == NULL)
        return;
    Unk_DTPlayer* pPlayer = reinterpret_cast<Unk_DTPlayer*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return;
    if (pPlayer->vfunc_78() < pCtx->m_level) {
        m_ctx.SetAt(pCtx->m_id, pCtx);
        return;
    }
    pReward->m_ctx = pCtx;
    vfunc_84(pReward);
    m_active.SetAt(pCtx->m_id, pReward);
}
MS2_REPLACE_METHOD(0x140F38430, UIDTEventDialog, FUN_140f38430, 493, 0xAD898361);

// @0x140f38630
void UIDTEventDialog::FUN_140f38630(unsigned int nID)
{
    Unk_DTPtr<Unk_DTReward> pReward(0);
    if (m_active.Lookup(nID, pReward)) {
        vfunc_86(pReward);
        m_active.RemoveKey(nID);
    }
    if (m_pending.Lookup(nID, pReward))
        m_pending.RemoveKey(nID);
    if (m_ctx.Lookup(nID) == NULL)
        m_ctx.RemoveKey(nID);
}
MS2_REPLACE_METHOD(0x140F38630, UIDTEventDialog, FUN_140f38630, 272, 0x3FB9C696);

// @0x140f38750
void UIDTEventDialog::FUN_140f38750()
{
    Unk_DTPlayer* pPlayer = reinterpret_cast<Unk_DTPlayer*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return;
    POSITION pos = m_ctx.GetStartPosition();
    while (pos != NULL) {
        MS2Ptr<CommonUserEvent::DTRewardEventContext> pCtx(m_ctx.GetValueAt(pos));
        MS2_ASSERT_AT(146, pCtx != NULL);
        m_ctx.GetNext(pos);
        if (pPlayer->vfunc_78() >= pCtx->m_level) {
            m_ctx.RemoveKey(pCtx->m_id);
            FUN_140f38430(pCtx);
        }
    }
}
MS2_REPLACE_METHOD(0x140F38750, UIDTEventDialog, FUN_140f38750, 349, 0x8BF9775A);

// @0x140f388c0
CStringW UIDTEventDialog::FUN_140f388c0(CTimeSpan* pSpan)
{
    long nHours = pSpan->GetHours();
    long nMinutes = pSpan->GetMinutes();
    long nSeconds = pSpan->GetSeconds();
#ifdef __clang__
        return Unk_Fmt3(L"{0:02}:{1:02}:{2:02}", (int)nHours, (int)nMinutes, (int)nSeconds);  // clang-cl: long is ambiguous in MakeValue
#else
        return Unk_Fmt3(L"{0:02}:{1:02}:{2:02}", nHours, nMinutes, nSeconds);
#endif
}
MS2_REPLACE_METHOD(0x140F388C0, UIDTEventDialog, FUN_140f388c0, 127, 0xA29015DF);

MS2_EMIT_CRT_MEMMOVE_S();
