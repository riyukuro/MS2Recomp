// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPvpRankDuelComponent / RankDuelStatisticalData: see
// placeholder/cpvprankduelcomponent.h.
// MS2-UNIT: ?\pvprankduelcomponent.cpp
// MS2-RANGE: 0x1400d52a0-0x1400d5740 .text$di
// MS2-RANGE: 0x140dbddc0-0x140dc2ef0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__EDAT_143ac4828@@YAXXZ 0x1400d52a0 ; probe
// MS2-PIN: ??__EDAT_143ac4878@@YAXXZ 0x1400d52d0 ; probe
// MS2-PIN: ??__EDAT_143ac4880@@YAXXZ 0x1400d53c0 ; probe
// MS2-PIN: ??__EDAT_143ac4888@@YAXXZ 0x1400d53f0 ; probe
// MS2-PIN: ??__EDAT_143ac4890@@YAXXZ 0x1400d5470 ; probe
// MS2-PIN: ??__EDAT_143ac4898@@YAXXZ 0x1400d54a0 ; probe
// MS2-PIN: ??__EDAT_143ac48a0@@YAXXZ 0x1400d54d0 ; probe
// MS2-PIN: ??__EDAT_143ac48a8@@YAXXZ 0x1400d5500 ; probe
// MS2-PIN: ??__EDAT_143ac48b0@@YAXXZ 0x1400d5530 ; probe
// MS2-PIN: ??__EDAT_143ac48b8@@YAXXZ 0x1400d5560 ; probe
// MS2-PIN: ??__EDAT_143ac48c0@@YAXXZ 0x1400d5590 ; probe
// MS2-PIN: ??__EDAT_143ac48c8@@YAXXZ 0x1400d55c0 ; probe
// MS2-PIN: ??__EDAT_143ac48d0@@YAXXZ 0x1400d55f0 ; probe
// MS2-PIN: ??__EDAT_143ac48d8@@YAXXZ 0x1400d5620 ; probe
// MS2-PIN: ??__EDAT_143ac48e0@@YAXXZ 0x1400d5650 ; probe
// MS2-PIN: ??__EDAT_143ac48e8@@YAXXZ 0x1400d5680 ; probe
// MS2-PIN: ??__EDAT_143ac48f0@@YAXXZ 0x1400d56b0 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400d56e0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400d5710 ; probe
// MS2-PIN: ??$Unk_RankDialog@VUIRankPvPDialog@@@@YAPEAVUIRankPvPDialog@@H@Z 0x140dbf660 ; unique
// MS2-PINS-END tplpin
//
// File name assumed. The statics below are this unit's dynamic initializers (the sound names of the arena, the
// message box tags, and the shared-header string constants the TU saw); the rest is the std::map<int,
// MS2Ptr<RankDuelStatisticalData>> glue of the record table.
// MS2-PIN: ??__EDAT_143ac4878@@YAXXZ 0x1400d52a0
// MS2-PIN: ??__EDAT_143ac4890@@YAXXZ 0x1400d52d0
// MS2-PIN: ??__EDAT_143ac47f0@@YAXXZ 0x1400d5300
// MS2-PIN: ??__EDAT_143ac47e8@@YAXXZ 0x1400d53c0
// MS2-PIN: ??__EDAT_143ac47e0@@YAXXZ 0x1400d53f0
// MS2-PIN: ??__EDAT_143ac4830@@YAXXZ 0x1400d5420
// MS2-PIN: ??__EDAT_143ac48d8@@YAXXZ 0x1400d5470
// MS2-PIN: ??__EDAT_143ac48a8@@YAXXZ 0x1400d54a0
// MS2-PIN: ??__EDAT_143ac4898@@YAXXZ 0x1400d54d0
// MS2-PIN: ??__EDAT_143ac48e8@@YAXXZ 0x1400d5500
// MS2-PIN: ??__EDAT_143ac48e0@@YAXXZ 0x1400d5530
// MS2-PIN: ??__EDAT_143ac48b0@@YAXXZ 0x1400d5560
// MS2-PIN: ??__EDAT_143ac48a0@@YAXXZ 0x1400d5590
// MS2-PIN: ??__EDAT_143ac48f0@@YAXXZ 0x1400d55c0
// MS2-PIN: ??__EDAT_143ac48d0@@YAXXZ 0x1400d55f0
// MS2-PIN: ??__EDAT_143ac48c0@@YAXXZ 0x1400d5620
// MS2-PIN: ??__EDAT_143ac48c8@@YAXXZ 0x1400d5650
// MS2-PIN: ??__EDAT_143ac48b8@@YAXXZ 0x1400d5680
// MS2-PIN: ??__EDAT_143ac4828@@YAXXZ 0x1400d56b0
// MS2-PIN: ??__EDAT_143ac4888@@YAXXZ 0x1400d56e0
// MS2-PIN: ??__EDAT_143ac4880@@YAXXZ 0x1400d5710
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pvprankduelcomponent.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cpvprankduelcomponent.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uieventintroduce.h"
#include "ms2/client/ms2/uipvprankduelresultdialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unrecovered helpers (declarations only; the addresses are in the names) ----
// The rank-duel lobby dialog (RTTI .?AVUIRankPvPDialog@@, ui id 0x4f04).
class UIRankPvPDialog : public UIDialog
{
public:
    virtual ~UIRankPvPDialog();
    void FUN_140f94390();                                           // the match state changed
    void FUN_140f94490();                                           // the own record changed
    void FUN_140f94840();                                           // the records changed
};
class Unk_RankUIService { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); int FUN_141adc940(int nId); void FUN_141adc530(int nId); };
Unk_RankUIService* FUN_1403ed2b0();
void* FUN_1403ed2d0();
void FUN_141276180(const CString& strName, const CString& strExtra);
CStringW FUN_14028b8e0(const CStringW& str);
CStringW FUN_14028de60(int nId);
void FUN_140d73aa0(CStringW text, int nA, int nB, CStringW tag);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, IMessageListener* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_141275260(int nStringId, int nA, int nB);
class Unk_RankClientState { public: };
Unk_RankClientState* FUN_1409a8b10();
struct Unk_RankClientFlags { unsigned char m_0; unsigned char m_observer; };
Unk_RankClientFlags* FUN_140c9b8b0(Unk_RankClientState* p);
class Unk_RankLeaguePlayer { public: };
Unk_RankLeaguePlayer* FUN_1404f4540();
int FUN_140791f50(Unk_RankLeaguePlayer* p, int n);
class Unk_RankTable { public: };
struct Unk_RankEntry { char m_pad[0x28]; int m_rating; };
Unk_RankEntry* FUN_140769000(Unk_RankTable* pTable, int nRating);
bool FUN_1407105c0(COutPacket* packet, int key, int delay);
struct Unk_RankVec3 { float x, y, z; };
extern Unk_RankVec3 DAT_143b01a60;                                  // the zero position
// The local player actor (COM-style: AddRef slot 1, Release slot 2).
class Unk_RankActor
{
public:
    virtual void vfunc_0(); virtual void AddRef(); virtual void Release();
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual void SetPosition(Unk_RankVec3 pos);                     // 22
    int FUN_14166ce30();                                            // the state (1: dead)
    void FUN_14166cce0(int n);
    void FUN_14166cd70(int n);
};
Unk_RankActor* FUN_141bd0cc0(void* pWorld);

// The pointer to the actor: AddRef on copy, Release on destruction (the destructor is not declared throw()).
template <class T> class Unk_RankComPtr
{
public:
    Unk_RankComPtr(T* lp) { p = lp; if (p != 0) p->AddRef(); }
    ~Unk_RankComPtr() { if (p != 0) p->Release(); }
    bool operator==(T* other) const { return p == other; }
    T* operator->() const { return p; }
    T* p;
};

template <class T> T* Unk_RankDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

#define RANK_SFX(name) { CString strExtra(""); FUN_141276180(name, strExtra); }

// ---- exe globals 0x143ac47e0-0x143ac48f8 (symbols-manual.tsv; the hook DLL binds the exe's) ----
extern CString DAT_143ac47f0[7];
extern CString DAT_143ac47e8;
extern CString DAT_143ac47e0;
extern Unk_1402a9d70 DAT_143ac4830;
extern CStringW DAT_143ac4878;
extern CStringW DAT_143ac4890;
extern CString DAT_143ac48d8;
extern CString DAT_143ac48a8;
extern CString DAT_143ac4898;
extern CString DAT_143ac48e8;
extern CString DAT_143ac48e0;
extern CString DAT_143ac48b0;
extern CString DAT_143ac48a0;
extern CString DAT_143ac48f0;
extern CString DAT_143ac48d0;
extern CString DAT_143ac48c0;
extern CString DAT_143ac48c8;
extern CString DAT_143ac48b8;
extern CString DAT_143ac4828;
extern CString DAT_143ac4888;
extern CString DAT_143ac4880;

#ifndef MS2_HOOK_DLL
CStringW DAT_143ac4878(L"rankArenaJoin");
CStringW DAT_143ac4890(L"rankArenaObserve");
CString DAT_143ac47f0[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };   // shared UGC header constants
CString DAT_143ac47e8("skill");
CString DAT_143ac47e0("stun");
Unk_1402a9d70 DAT_143ac4830(0x11, 0.75f, 0.25f, 2.25f, 10);
CString DAT_143ac48d8("System_Draw_01");
CString DAT_143ac48a8("System_Fight_01");
CString DAT_143ac4898("System_GetReady_01");
CString DAT_143ac48e8("System_Pefect_01");
CString DAT_143ac48e0("Voice_Draw_01");
CString DAT_143ac48b0("Voice_Fight_01");
CString DAT_143ac48a0("Voice_GetReady_01");
CString DAT_143ac48f0("Voice_Pefect_01");
CString DAT_143ac48d0("Voice_YouLose_01");
CString DAT_143ac48c0("Voice_YouWin_01");
CString DAT_143ac48c8("System_YouLose_01");
CString DAT_143ac48b8("System_YouWin_01");
CString DAT_143ac4828("guildBattle_Apply");
CString DAT_143ac4888("guildBattle_MatchingFail");
CString DAT_143ac4880("guildBattle_MatchingSuccess");
#endif

// The rank table (global 0x143ab0e50).
class Unk_RankTable;
Unk_RankTable* FUN_140dc19b0();
extern Unk_RankTable* DAT_143ab0e50;

// @0x140dc1390; the destructor 0x140dc1500 only runs ~CPtred
RankDuelStatisticalData::RankDuelStatisticalData() : m_key(0), m_value1c(0), m_value20(0), m_flag24(false) {}

// @0x140dc1500
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
RankDuelStatisticalData::~RankDuelStatisticalData() {}

// @0x140dbddc0
CPvpRankDuelComponent::CPvpRankDuelComponent()
{
    Reset();
}

// @0x140dbde10
CPvpRankDuelComponent::~CPvpRankDuelComponent() {}

// @0x140dbde50
void CPvpRankDuelComponent::SetState(int nState)
{
    m_state = nState;
}

// @0x140dbde70
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
void CPvpRankDuelComponent::OnMessage(int nMessage, CInPacket& packet)
{
    if (nMessage == 0xe)
    {
        m_state = 1;
        UIRankPvPDialog* pDialog = Unk_RankDialog<UIRankPvPDialog>(0x4f04);
        if (pDialog)
            pDialog->FUN_140f94390();
        RANK_SFX(DAT_143ac4828);
    }
    else if (nMessage == 0xf)
    {
        m_state = 0;
        UIRankPvPDialog* pDialog = Unk_RankDialog<UIRankPvPDialog>(0x4f04);
        if (pDialog)
            pDialog->FUN_140f94390();
    }
    else if (nMessage == 0x10)
    {
        bool bMatched = packet.vfunc_o8_0();
        if (bMatched)
        {
            m_state = 2;
            UIRankPvPDialog* pDialog = Unk_RankDialog<UIRankPvPDialog>(0x4f04);
            if (pDialog)
            {
                pDialog->FUN_140f94390();
                CStringW strText(FUN_14028b8e0(CStringW(L"s_rank_duel_matching_complete")));
                MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0, strText, pDialog, DAT_143ac4878);
                if (box.get())
                {
                    box->FUN_141a01ca0(0xf, 1, FUN_14028de60(0x2b8));
                    box->FUN_141a02460(1);
                    box->FUN_141a02480(1);
                    box->FUN_141a024a0(0);
                    box->FUN_141a024c0();
                    box->FUN_141a01690(FUN_14028b8e0(CStringW(L"s_rank_duel_immediately_join")), CStringW(L""), CStringW(L""));
                    FUN_140d73c60(box);
                }
            }
            RANK_SFX(DAT_143ac4880);
        }
        else
        {
            m_state = 0;
            UIRankPvPDialog* pDialog = Unk_RankDialog<UIRankPvPDialog>(0x4f04);
            if (pDialog)
                pDialog->FUN_140f94390();
            FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_rank_duel_matching_fail")), 0, 0, CStringW(L""));
            RANK_SFX(DAT_143ac4888);
        }
    }
    else if (nMessage == 0x16)
    {
        m_league = packet.vfunc_o8_3();
        m_value20 = packet.vfunc_o8_3();
        m_value24 = packet.vfunc_o8_3();
        m_value28 = packet.vfunc_o8_3();
        UIRankPvPDialog* pDialog = Unk_RankDialog<UIRankPvPDialog>(0x4f04);
        if (pDialog)
            pDialog->FUN_140f94490();
    }
    else if (nMessage == 0x17)
    {
        m_records.clear();
        int nCount = packet.vfunc_o8_3();
        m_total2c = 0;
        m_total30 = 0;
        for (int i = 0; i < nCount; i++)
        {
            MS2Ptr<RankDuelStatisticalData> spRecord(new RankDuelStatisticalData);
            spRecord->FUN_14026b250(packet);
            m_records[spRecord->m_key] = spRecord;
            m_total2c += spRecord->m_value1c;
            m_total30 += spRecord->m_value20;
        }
        UIRankPvPDialog* pDialog = Unk_RankDialog<UIRankPvPDialog>(0x4f04);
        if (pDialog)
        {
            pDialog->FUN_140f94490();
            pDialog->FUN_140f94840();
        }
    }
    else if (nMessage == 0x19)
    {
        if (m_state != 0)
            return;
        if (FUN_140c9b8b0(FUN_1409a8b10())->m_observer)
        {
            CStringW strText(FUN_14028b8e0(CStringW(L"s_rank_duel_matching_complete_to_observe")));
            UIRankPvPDialog* pDialog = Unk_RankDialog<UIRankPvPDialog>(0x4f04);
            if (pDialog == 0)
                return;
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, strText, pDialog, DAT_143ac4890);
            if (box.get())
            {
                box->FUN_141a01ca0(0xf, 1, FUN_14028de60(0x2b8));
                box->FUN_141a02460(1);
                box->FUN_141a02480(1);
                box->FUN_141a024a0(0);
                FUN_140d73c60(box);
            }
        }
    }
    else if (nMessage == 0x12)
    {
        if (FUN_1403ed2b0()->FUN_141adc940(0x4f05))
            FUN_1403ed2b0()->FUN_141adc530(0x4f05);
        UIPvPRankDuelResultDialog* pDialog = Unk_RankDialog<UIPvPRankDuelResultDialog>(0x4f05);
        if (pDialog)
            pDialog->FUN_140f90b10(&packet);
    }
    else if (nMessage == 0x13)
    {
        bool bFlag = packet.vfunc_o8_0();
        Unk_RankActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pActor == 0)
            return;
        if (bFlag)
        {
            pActor->FUN_14166cd70(1);
        }
        else
        {
            pActor->SetPosition(DAT_143b01a60);
            pActor->FUN_14166cce0(1);
        }
    }
    else if (nMessage == 0x1b)
    {
        int nRound = packet.vfunc_o8_3();
        int nTotal = packet.vfunc_o8_3();
        UIEventIntroduce* pIntro = Unk_RankDialog<UIEventIntroduce>(0x4f06);
        if (pIntro == 0)
            return;
        pIntro->FUN_140f41190(nTotal, nRound);
        RANK_SFX(DAT_143ac4898);
        RANK_SFX(DAT_143ac48a0);
    }
    else if (nMessage == 0x1a)
    {
        int nValue = packet.vfunc_o8_3();
        UIEventIntroduce* pIntro = Unk_RankDialog<UIEventIntroduce>(0x4f06);
        if (pIntro == 0)
            return;
        pIntro->FUN_140f410b0(nValue);
        RANK_SFX(DAT_143ac48a8);
        RANK_SFX(DAT_143ac48b0);
    }
    else if (nMessage == 0x1c)
    {
        int nValue = packet.vfunc_o8_3();
        UIEventIntroduce* pIntro = Unk_RankDialog<UIEventIntroduce>(0x4f06);
        if (pIntro == 0)
            return;
        pIntro->FUN_140f40ef0(nValue);
        RANK_SFX(DAT_143ac48b8);
        RANK_SFX(DAT_143ac48c0);
    }
    else if (nMessage == 0x1d)
    {
        int nValue = packet.vfunc_o8_3();
        UIEventIntroduce* pIntro = Unk_RankDialog<UIEventIntroduce>(0x4f06);
        if (pIntro == 0)
            return;
        pIntro->FUN_140f40f60(nValue);
        RANK_SFX(DAT_143ac48c8);
        RANK_SFX(DAT_143ac48d0);
    }
    else if (nMessage == 0x1e)
    {
        int nValue = packet.vfunc_o8_3();
        UIEventIntroduce* pIntro = Unk_RankDialog<UIEventIntroduce>(0x4f06);
        if (pIntro == 0)
            return;
        pIntro->FUN_140f40fd0(nValue);
        RANK_SFX(DAT_143ac48d8);
        RANK_SFX(DAT_143ac48e0);
    }
    else if (nMessage == 0x1f)
    {
        int nValue = packet.vfunc_o8_3();
        UIEventIntroduce* pIntro = Unk_RankDialog<UIEventIntroduce>(0x4f06);
        if (pIntro == 0)
            return;
        pIntro->FUN_140f41040(nValue);
        RANK_SFX(DAT_143ac48e8);
        RANK_SFX(DAT_143ac48f0);
    }
}

// @0x140dbf090
void CPvpRankDuelComponent::Reset()
{
    m_state = 0;
    m_value24 = 1000;
    m_league = 0;
    m_value20 = 1000;
    m_value28 = 0;
    m_total2c = 0;
    m_total30 = 0;
    m_records.clear();
}

// @0x140dbf110
void CPvpRankDuelComponent::RefreshLeague()
{
    int nLeague = FUN_140791f50(FUN_1404f4540(), 1);
    if (m_league != nLeague)
    {
        m_league = nLeague;
        m_value20 = 1000;
    }
}

// @0x140dbf160
bool CPvpRankDuelComponent::RequestCancelMatch()
{
    Unk_RankComPtr<Unk_RankActor> spActor(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (spActor == 0)
        return false;
    if (spActor->FUN_14166ce30() == 1)
    {
        FUN_141275260(0x279, 1, 1);
        return false;
    }
    COutPacket packet(0x61, 0);
    packet.vfunc_o10_1(0x10);
    FUN_1407105c0(&packet, 0x10, 1000);
    return true;
}

// @0x140dc19b0
Unk_RankTable* FUN_140dc19b0()
{
    return DAT_143ab0e50;
}

// @0x140dbf260
// MS2-FUNCTIONAL: not byte-exact yet (register allocation / block order differ)
int CPvpRankDuelComponent::CurrentRating()
{
    return FUN_140769000(FUN_140dc19b0(), m_value20)->m_rating;
}

// @0x140dbf2a0
MS2Ptr<RankDuelStatisticalData> CPvpRankDuelComponent::FindRecord(int nKey)
{
    if (m_records.find(nKey) == m_records.end())
        return MS2Ptr<RankDuelStatisticalData>(0);
    return m_records[nKey];
}
