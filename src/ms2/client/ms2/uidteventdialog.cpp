// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Timed event reward list ("DTEventDialog").
// MS2-UNIT: client\ms2\uidteventdialog.cpp
// MS2-RANGE: 0x140f359b0-0x140f3a810 .text$mn
// MS2-RANGE: 0x1400ded40-0x1400deeb0 .text$di
// MS2-RANGE: 0x142ca9380-0x142ca9410 .text$yd
// MS2-PIN: ?GetAt@Unk_DTBindList@@QEAAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAU__POSITION@@@Z 0x140f396a0
// MS2-PIN: ?AddRefObject@?$Unk_DTPtr@VRewardItem@UIDTEventDialog@@@@CAXPEAVRewardItem@UIDTEventDialog@@@Z 0x140f3a730
// MS2-PIN: ??$Unk_Fmt3@JJJ@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBJ11@Z 0x140f38940
// MS2-PIN: ?Lookup@Unk_DTCtxMap@@QEAAPEAXI@Z 0x140f39b70
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

// ---- the unit's header statics (this unit includes them in a different order than header_statics_a.h) ----
class Unk_1402a9d70
{
public:
    Unk_1402a9d70(int, float, float, float, int);
    ~Unk_1402a9d70();

private:
    void* m_00; void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48;
};
MS2_CHECK_SIZE(Unk_1402a9d70, 0x50);
static CString s_skill("skill");
static CString s_stun("stun");
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----
typedef UIDTEventDialog::RewardItem Unk_DTReward;

// Reference counting of the intrusive pointers' targets (CPtred-derived objects): add 0x14015b020, release 0x140159bc0.
class Unk_DTRefCount
{
public:
    void FUN_14015b020();
    int FUN_140159bc0();
    void FUN_140159ba0();
};

// One reward step of an event: the seconds it lasts and the item given.
class Unk_DTStep : public CPtred
{
public:
    unsigned int m_18;
    unsigned int m_1c;      // +0x1c seconds the step lasts
    unsigned int m_20;
    int m_24;               // +0x24 item id
    int m_28;               // +0x28 item count
    int m_2c;               // +0x2c item rarity
};

// An event context (data of the server's event): id, minimum level, kind flag and the steps.
class Unk_DTCtx : public CPtred
{
public:
    unsigned int m_18;      // +0x18 event id
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned short m_30;    // +0x30 minimum level
    char m_32;
    unsigned char m_33;     // +0x33 selects the data table
    int m_34;
    ATL::CAtlArray<Unk_DTPtr<Unk_DTStep> > m_38;                    // +0x38 the steps
};
MS2_CHECK_SIZE(Unk_DTCtx, 0x58);

// The data tables (two instances of one class; 0x143ab2fc0 and 0x143ab3010): lookup by (kind, id) with a default.
class Unk_DTTable
{
public:
    unsigned int FUN_1409617d0(int nKind, unsigned int nId, const int& nDefault);          // as an int
    __int64 FUN_140be8f80(int nKind, unsigned int nId, const __int64& nDefault);           // as a 64-bit value
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
    void* m_pad_38; void* m_pad_40; void* m_pad_48;
};
MS2_CHECK_SIZE(Unk_DTTable, 0x50);
extern Unk_DTTable g_unkTableA;     // 0x143ab2fc0
extern Unk_DTTable g_unkTableB;     // 0x143ab3010

// The root AS object of the dialog movie and the clip kinds used here.
class ASDialog : public ASDisplayObject
{
public:
    int FUN_1422c1500();
    int FUN_1422c1530();
    float FUN_1422c10a0();
    float FUN_1422c1110();
    void FUN_1422bffe0(int x, int y);
};
class Unk_DTMovie : public ASMovieClip
{
public:
    int FUN_1422c2510(double* pValue, double* pExtra);
};

class ASData : public CPtred
{
public:
    int FUN_1422b8b10();
private:
    void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30; void* m_pad_38; void* m_pad_40;
};
MS2_CHECK_SIZE(ASData, 0x48);

// An AS object created on the C++ side (AScript with type 2) with the typed setters (COMDATs, one per value type).
class ASObj : public AScript
{
public:
    ASObj(int nType);
    virtual ~ASObj();
    void FUN_1409c0d20(const char* szName, unsigned int n);
    void FUN_1407cb9c0(const char* szName, int n);
    void FUN_1407cba60(const char* szName, CString str);
    void FUN_1407cbb20(const char* szName, CStringW str);
};
MS2_CHECK_SIZE(ASObj, 0x40);

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
    void FUN_140526c70(int nCount);
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
void FUN_141415450(const CString& strName, MS2Ptr<CItem> pItem, int a1, int a2, int a3);

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
class Unk_1403ed2d0 { public: Unk_DTPlayer* FUN_141bd0cc0(); };
Unk_1403ed2d0* FUN_1403ed2d0();

// The event data manager (singleton 0x14041beb0): fills an array with all event contexts.
class Unk_DTCtxMgr { public: void FUN_1408d7db0(ATL::CAtlArray<Unk_DTPtr<Unk_DTCtx> >& ctxs); };
Unk_DTCtxMgr* FUN_14041beb0();

// A sound / effect player (singleton 0x140e45740).
class Unk_DTSound { public: void FUN_1422e6d00(int n); };
Unk_DTSound* FUN_140e45740();

UISwfEntity* FUN_140c9b540(int nUIType);                        // a UI object by type id

// CAtlArray<unsigned int> (32 bytes) with all members in earlier units.
class Unk_DTUIntArray
{
public:
    Unk_DTUIntArray();                                          // 0x140183460
    ~Unk_DTUIntArray();                                         // 0x140181d30
    void FUN_1401855a0(unsigned int n);                         // Add
    size_t FUN_140186270();                                     // GetCount
    unsigned int* FUN_1401c0c80(size_t i);                      // operator[]
    void FUN_1402c2830();                                       // RemoveAll
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18;
};
MS2_CHECK_SIZE(Unk_DTUIntArray, 0x20);

// Time-of-day helpers (commonfiles\timeutil.cpp): a 16-byte time value.
class Unk_Time
{
public:
    Unk_Time(__int64 n);                                        // 0x1406c47a0
    Unk_Time(const Unk_Time& o);                                // declared: forces by-pointer passing
private:
    __int64 m_0; __int64 m_8;
};
bool FUN_14086ab70(Unk_Time a, Unk_Time b, int nBaseHour);

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
    reinterpret_cast<Unk_DTRefCount*>(p)->FUN_14015b020();
}
template <> inline void Unk_DTPtr<Unk_DTReward>::AddRefImpl(void*) const { AddRefObject(m_p); }              // 0x140f3a750
template <> inline void Unk_DTPtr<Unk_DTReward>::ReleaseImpl(void*)                                          // 0x140f3a7c0
{
    if (reinterpret_cast<Unk_DTRefCount*>(m_p)->FUN_140159bc0() == 0) {
        AddRefObject(m_p);
        reinterpret_cast<Unk_DTRefCount*>(m_p)->FUN_140159ba0();
    }
}
template <> inline void Unk_DTPtr<Unk_DTReward>::AddRef() const { if (m_p) AddRefImpl(0); }                // 0x140f3a700
template <> inline void Unk_DTPtr<Unk_DTReward>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }      // 0x140f3a780

template <> inline bool Unk_DTPtr<Unk_DTStep>::operator==(Unk_DTStep* p) const { return m_p == p; }        // 0x140f39140
template <> inline Unk_DTPtr<Unk_DTCtx>::operator Unk_DTCtx*() const { return m_p; }                       // 0x140f39240

// ---- inline COMDATs of the unit's own helper classes ----
inline CString& Unk_DTBindList::GetAt(POSITION pos)                                                        // 0x140f396a0
{
    ATLENSURE(pos != NULL);
    char* pNode = reinterpret_cast<char*>(pos);
    return *reinterpret_cast<CString*>(pNode + 0x10);
}
inline size_t Unk_DTBindList::GetCount() const { return m_nElements; }                                    // 0x140f39730
inline void* Unk_DTCtxMap::Lookup(unsigned int nKey)                                                       // 0x140f39b70
{
    unsigned int iBin;
    unsigned int nHash;
    void* pPrev;
    void* pNode = GetNode(nKey, iBin, nHash, pPrev);
    return pNode;
}

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
    m_timer.FUN_140268840();
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
        FUN_141415600(m_binds.GetAt(pos));
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
    m_timer.FUN_140268840();
    m_active.RemoveAll();
    m_pending.RemoveAll();
    m_ctx.RemoveAll();
    ATL::CAtlArray<Unk_DTPtr<Unk_DTCtx> > ctxs;
    FUN_14041beb0()->FUN_1408d7db0(ctxs);
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
        if (bMove && (pOwner = FUN_140c9b540(0x4e29)) != NULL) {
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
                dialog->FUN_1422bffe0(nRemain > 0 ? nRemain : 0, 0x1c);
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
    if (!m_timer.FUN_140268870(1000)) return;
    {
        FUN_140f38750();
        Unk_DTUIntArray ids;
        for (POSITION pos = m_pending.GetStartPosition(); pos != NULL; m_pending.GetNext(pos)) {
            Unk_DTPtr<Unk_DTReward> pReward(m_pending.GetValueAt(pos));
            MS2_ASSERT_AT(186, pReward != NULL);
            if (FUN_14086ab70(Unk_Time(pReward->m_start), Unk_Time(FUN_140869440()), 0)) {
                if (vfunc_84(pReward) == 1) {
                    ids.FUN_1401855a0(m_pending.GetKeyAt(pos));
                    m_active.SetAt(pReward->m_ctx->m_18, pReward);
                }
            }
        }
        for (unsigned int i = 0; i < ids.FUN_140186270(); i++) {
            unsigned int nKey = *ids.FUN_1401c0c80(i);
            if (m_pending.Lookup(nKey) != NULL)
                m_pending.RemoveKey(nKey);
        }
        ids.FUN_1402c2830();
        for (POSITION pos = m_active.GetStartPosition(); pos != NULL; m_active.GetNext(pos)) {
            Unk_DTPtr<Unk_DTReward> pReward(m_active.GetValueAt(pos));
            MS2_ASSERT_AT(211, pReward != NULL);
            if (vfunc_85(pReward) == 0)
                ids.FUN_1401855a0(m_active.GetKeyAt(pos));
        }
        for (unsigned int i = 0; i < ids.FUN_140186270(); i++) {
            unsigned int nKey = *ids.FUN_1401c0c80(i);
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
    Unk_DTTable& rTable = pReward->m_ctx->m_33 ? g_unkTableB : g_unkTableA;
    int nDefault = 0;
    pReward->m_step = rTable.FUN_1409617d0(0x2be, pReward->m_ctx->m_18, nDefault);
    if (pReward->m_ctx->m_38.GetCount() <= pReward->m_step)
        return 0;
    Unk_DTPtr<Unk_DTStep> pStep(pReward->m_ctx->m_38[(int)pReward->m_step]);
    if (pStep == NULL)
        return 0;
    __int64 nDefault64 = 0;
    pReward->m_start = rTable.FUN_140be8f80(700, pReward->m_ctx->m_18, nDefault64);
    int nDefault2 = 0;
    pReward->m_elapsed = rTable.FUN_1409617d0(0x2bd, pReward->m_ctx->m_18, nDefault2);
    __int64 now = FUN_140869440();
    if (pReward->m_start == 0)
        pReward->m_start = now;
    CTimeSpan elapsed(now - pReward->m_start);
    pReward->m_elapsed += elapsed.GetTotalSeconds();
    if (pReward->m_elapsed > pStep->m_1c)
        pReward->m_elapsed = pStep->m_1c;
    CTimeSpan remain(0);
    if (pStep->m_1c > pReward->m_elapsed)
        remain = pStep->m_1c - pReward->m_elapsed;
    float fElapsed = (float)pReward->m_elapsed;
    int nGauge = (int)(fElapsed * (100.0f / (float)pStep->m_1c));
    CStringW strRemain = FUN_140f388c0(&remain);
    int bVibrate = 0;
    if (remain.GetTotalSeconds() <= 10)
        bVibrate = 1;
    ASObj obj(2);
    CString strBindID;
    MS2Ptr<CItem> item(new CItem);
    if (item->FUN_140523c40(pStep->m_24, pStep->m_2c, 0)) {
        item->FUN_140526c70(pStep->m_28);
        strBindID.Format("%s_%d", (LPCSTR)GetTypeName(), m_binds.GetCount() + 1);
        FUN_141415450(strBindID, item, 0, 0x415, 0);
        m_binds.AddTail(strBindID);
    }
    obj.FUN_1409c0d20("eventID", pReward->m_ctx->m_18);
    obj.FUN_1407cba60("bindID", strBindID);
    obj.FUN_1409c0d20("itemCount", pStep->m_28);
    obj.FUN_1407cbb20("remainTime", strRemain);
    obj.FUN_1407cb9c0("gaugeRate", nGauge);
    obj.FUN_1407cb9c0("vibrate", bVibrate);
    m_30->Invoke("addItem", obj.FUN_1422bb870());
    FUN_140e45740()->FUN_1422e6d00(0);
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
    Unk_DTTable& rTable = pReward->m_ctx->m_33 ? g_unkTableB : g_unkTableA;
    int nDefault = 0;
    unsigned int nStep = rTable.FUN_1409617d0(0x2be, pReward->m_ctx->m_18, nDefault);
    if (pReward->m_ctx->m_38.GetCount() <= nStep) {
        vfunc_86(pReward);
        return 0;
    }
    if (pReward->m_step != nStep)
        return vfunc_87(pReward, nStep);
    pReward->m_step = nStep;
    Unk_DTPtr<Unk_DTStep> pStep(pReward->m_ctx->m_38[(int)pReward->m_step]);
    if (pStep == NULL)
        return 0;
    __int64 nDefault64 = 0;
    pReward->m_start = rTable.FUN_140be8f80(700, pReward->m_ctx->m_18, nDefault64);
    int nDefault2 = 0;
    pReward->m_elapsed = rTable.FUN_1409617d0(0x2bd, pReward->m_ctx->m_18, nDefault2);
    __int64 now = FUN_140869440();
    if (pReward->m_start == 0)
        pReward->m_start = now;
    CTimeSpan elapsed(now - pReward->m_start);
    pReward->m_elapsed += elapsed.GetTotalSeconds();
    if (pReward->m_elapsed > pStep->m_1c)
        pReward->m_elapsed = pStep->m_1c;
    CTimeSpan remain(0);
    if (pStep->m_1c > pReward->m_elapsed)
        remain = pStep->m_1c - pReward->m_elapsed;
    int bVibrate = 0;
    if (remain.GetTotalSeconds() <= 1)
        bVibrate = 1;
    float fElapsed = (float)pReward->m_elapsed;
    int nGauge = (int)(fElapsed * (100.0f / (float)pStep->m_1c));
    CStringW strRemain = FUN_140f388c0(&remain);
    ASObj obj(2);
    obj.FUN_1409c0d20("eventID", pReward->m_ctx->m_18);
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
    obj.FUN_1409c0d20("eventID", pReward->m_ctx->m_18);
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
    Unk_DTPtr<Unk_DTStep> pStep(pReward->m_ctx->m_38[(int)pReward->m_step]);
    if (pStep == NULL)
        return 0;
    Unk_DTTable& rTable = pReward->m_ctx->m_33 ? g_unkTableB : g_unkTableA;
    __int64 nDefault64 = 0;
    pReward->m_start = rTable.FUN_140be8f80(700, pReward->m_ctx->m_18, nDefault64);
    int nDefault2 = 0;
    pReward->m_elapsed = rTable.FUN_1409617d0(0x2bd, pReward->m_ctx->m_18, nDefault2);
    __int64 now = FUN_140869440();
    if (pReward->m_start == 0)
        pReward->m_start = now;
    CTimeSpan elapsed(now - pReward->m_start);
    pReward->m_elapsed += elapsed.GetTotalSeconds();
    if (pReward->m_elapsed > pStep->m_1c)
        pReward->m_elapsed = pStep->m_1c;
    CTimeSpan remain(0);
    if (pStep->m_1c > pReward->m_elapsed)
        remain = pStep->m_1c - pReward->m_elapsed;
    float fElapsed = (float)pReward->m_elapsed;
    int nGauge = (int)(fElapsed * (100.0f / (float)pStep->m_1c));
    CStringW strRemain = FUN_140f388c0(&remain);
    int bVibrate = 0;
    if (remain.GetTotalSeconds() <= 1)
        bVibrate = 1;
    ASObj obj(2);
    CString strBindID;
    MS2Ptr<CItem> item(new CItem);
    if (item->FUN_140523c40(pStep->m_24, pStep->m_2c, 0)) {
        item->FUN_140526c70(pStep->m_28);
        strBindID.Format("%s_%d", (LPCSTR)GetTypeName(), m_binds.GetCount() + 1);
        FUN_141415450(strBindID, item, 0, 0x415, 0);
        m_binds.AddTail(strBindID);
    }
    obj.FUN_1407cb9c0("change", 1);
    obj.FUN_1409c0d20("eventID", pReward->m_ctx->m_18);
    obj.FUN_1407cba60("bindID", strBindID);
    obj.FUN_1409c0d20("itemCount", pStep->m_28);
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
    Unk_DTPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == NULL)
        return;
    unsigned int nID = pArgs->FUN_1422b8b10();
    Unk_DTPtr<Unk_DTReward> pReward(0);
    if (!m_active.Lookup(nID, pReward))
        return;
    Unk_DTPtr<Unk_DTStep> pStep(pReward->m_ctx->m_38[(int)pReward->m_step]);
    if (pStep == NULL)
        return;
    MS2Ptr<CItem> item(new CItem);
    if (item->FUN_14052b130(pStep->m_24, pStep->m_2c, 0)) {
        item->FUN_140526c70(pStep->m_28);
        ASTooltip tooltip(pPlayer, 0x20, 2);
        if (tooltip.FUN_1409e0d40(item.get())) {
            *pRetVal = tooltip.FUN_1422bb870();
            return;
        }
    }
}
MS2_REPLACE_METHOD(0x140F38160, UIDTEventDialog, vfunc_49, 700, 0x9E104B3A);

// @0x140f38430
void UIDTEventDialog::FUN_140f38430(Unk_DTPtr<Unk_DTCtx> pCtx)
{
    Unk_DTPtr<Unk_DTReward> pReward(new RewardItem);
    if (pReward == NULL)
        return;
    Unk_DTPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == NULL)
        return;
    if (pPlayer->vfunc_78() < pCtx->m_30) {
        m_ctx.SetAt(pCtx->m_18, pCtx);
        return;
    }
    pReward->m_ctx = pCtx;
    vfunc_84(pReward);
    m_active.SetAt(pCtx->m_18, pReward);
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
    Unk_DTPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == NULL)
        return;
    POSITION pos = m_ctx.GetStartPosition();
    while (pos != NULL) {
        Unk_DTPtr<Unk_DTCtx> pCtx(m_ctx.GetValueAt(pos));
        MS2_ASSERT_AT(146, pCtx != NULL);
        m_ctx.GetNext(pos);
        if (pPlayer->vfunc_78() >= pCtx->m_30) {
            m_ctx.RemoveKey(pCtx->m_18);
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
