// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NPC duel hp bar dialog. See uinpcduelhpbardialog.h.
// MS2-UNIT: client\ms2\uinpcduelhpbardialog.cpp
// MS2-RANGE: 0x140e6b7b0-0x140e6d3c0 .text$mn
// MS2-PIN: ?vfunc_48@UINpcDuelHPBarDialog@@UEAAHXZ 0x140e6d2a0
// MS2-PIN: ??$Unk_SocketFormat@W4Unk_NdJobCode@@@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBW4Unk_NdJobCode@@@Z 0x140e6cf40
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uinpcduelhpbardialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uinpcduelhpbardialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/aswindow.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/client/ms2/aseffect.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/client/ms2/npcdatacli.h"
#include "ms2/client/ms2/additionalcli.h"
#include "ms2/client/ms2/additionalclilist.h"
#include "ms2/commonfiles/additionalactionadditional.h"

// ---- unit-local declarations (names describe uses, not original class names) ----


unsigned long GetTickCountMs2();   // C3: was FUN_140869420
enum Unk_NdJobCode { Unk_NdJobCode_None = 0 };
bool FUN_140930110(int nBuffId);
CStringW FUN_1401aa6a0(int nId);
CString FUN_141028be0(__int64 nAccountId, const CString& strPath, int nSize, CString strDefault);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void FUN_140cff1b0(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int nVisible);
void FUN_140cffca0(const Scaleform::GFx::Value& root, CString strName, CString strIcon);

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);
MS2Ptr<ASEffectManager> FUN_140e6cd80(int nMovieId, CString strClass, __int64 a1, int a2);   // create the clip

// AScript calls with a fixed argument list (the 3-argument one is this unit's own COMDAT copy)
class Unk_NdScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_140e6cfe0(const char* szMethod, __int64 a1, __int64 a2, int a3);      // "setHpBarRight"
};
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// The job icon name goes through the one-argument instance of the 0x1402bf9a0 formatter (0x140e6cf40).
template CString Unk_SocketFormat<Unk_NdJobCode>(const char*, const Unk_NdJobCode&);

// ---- the dialog ----

// @0x140e6b7b0
UINpcDuelHPBarDialog::UINpcDuelHPBarDialog()
{
    FUN_141924170(1);
    FUN_141925e70(0, 1);
    m_nObjectId = 0;
    m_nBarCount = 1;
}

// @0x140e6b850
UINpcDuelHPBarDialog::~UINpcDuelHPBarDialog()
{
}

// @0x140e6b8a0
CString UINpcDuelHPBarDialog::GetTypeName()
{
    return "NpcDuelHPBarDialog";
}

// @0x140e6b8f0
void UINpcDuelHPBarDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_nObjectId = 0;
    m_nEndTick = 0;
    m_nBarCount = 1;
    m_effects = 0;
}

// @0x140e6b950
void UINpcDuelHPBarDialog::vfunc_72()
{
    if (m_30 == 0)
        return;
    UpdateRemainingTime();
    UpdatePlayerHpBar();
    FUN_140e6c9c0();
    if (m_effects.get() != 0)
        m_effects->Update();
}

// @0x140e6b9e0
void UINpcDuelHPBarDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_effects = FUN_140e6cd80(2, "flash.display.MovieClip", 0, 0);
    m_effects->SetPosA(0x2c4, 0x3c);
    m_effects->SetPosB(0x2c4, 0x69);
    m_30->Invoke("addChild", m_effects->FUN_1422bb870());
    FUN_140e6bc10();
}

// @0x140e6bb70
void UINpcDuelHPBarDialog::StartDuelBar(int nObjectId, int nDurationMs, int nBarCount)
{
    m_nObjectId = nObjectId;
    m_nEndTick = GetTickCountMs2() + nDurationMs;
    m_nBarCount = nBarCount;
    if (m_nBarCount == 0)
        m_nBarCount = 1;
    if (m_30 == 0)
        return;
    FUN_140e6bc10();
}

// @0x140e6bc10
void UINpcDuelHPBarDialog::FUN_140e6bc10()
{
    if (m_nObjectId == 0)
        return;
    PC* pPc = reinterpret_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPc != 0) {
        FUN_140cfee80(FUN_1422dbc00(), "m_leftName", pPc->vfunc_77());
        Unk_NdJobCode nJob = (Unk_NdJobCode)pPc->FUN_141654730();
        CString strJobIcon = Unk_SocketFormat("_{0}", nJob);
        FUN_140cffca0(FUN_1422dbc00(), "m_leftJobIcon", strJobIcon);
        CString strProfile = FUN_141028be0(pPc->FUN_141656a80(), pPc->FUN_1416612e0(), 1, "");
        ((Unk_NdScript*)m_30.operator->())->Invoke("setLeftProfile", strProfile);
        UpdatePlayerHpBar();
    }
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nObjectId));
    if (pNpc != 0) {
        CStringW strName = FUN_14028dfa0<CStringW, CStringW>(L"s_npc_duelhpbar_dialog_right_name", FUN_1401aa6a0(pNpc->FUN_141092fa0()),
            TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x11, pNpc->GetNpcData()->GetRace()));
        FUN_140cff1b0(FUN_1422dbc00(), "m_rightName", strName);
        FUN_140cfee80(FUN_1422dbc00(), "m_rightLevel", StringFormat(L"{0}", pNpc->vfunc_78()));
        CString strProfile(pNpc->GetNpcData()->m_strPortrait);
        m_30->Invoke("setRightProfile", strProfile);
        FUN_140e6c9c0();
        m_effects->Clear();
        ATL::CAtlList<MS2Ptr<AdditionalCli> > list(10);
        reinterpret_cast<AdditionalCliList*>(pNpc->FUN_1416749a0())->FUN_1409725f0(list);
        for (POSITION pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos)) {
            MS2Ptr<AdditionalCli> buff = list.GetAt(pos);
            if (buff == 0)
                continue;
            bool bFlag = FUN_140930110(buff->m_nCasterId);
            if (!buff->FUN_14096d810()->m_ui.FUN_1401927c0(bFlag))
                continue;
            FUN_140e6c440(buff);
        }
    }
}

// @0x140e6c440
void UINpcDuelHPBarDialog::FUN_140e6c440(MS2Ptr<AdditionalCli> buff)
{
    if (m_30 == 0)
        return;
    if (m_effects == 0)
        return;
    if (buff->GetOwner()->FUN_14123c580() != m_nObjectId)
        return;
    m_effects->AddEffect(buff);
}

// @0x140e6c540
void UINpcDuelHPBarDialog::FUN_140e6c540(MS2Ptr<AdditionalCli> buff)
{
    if (m_30 == 0)
        return;
    if (m_effects == 0)
        return;
    if (buff->GetOwner()->FUN_14123c580() != m_nObjectId)
        return;
    m_effects->UpdateEffect(buff);
}

// @0x140e6c640
void UINpcDuelHPBarDialog::RemoveBuffEffect(int nBuffId)
{
    if (m_30 == 0)
        return;
    if (m_effects == 0)
        return;
    m_effects->RemoveEffect(nBuffId);
}

// @0x140e6c6c0
void UINpcDuelHPBarDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get() != 0) {
        pEntity->vfunc_2(1, 0, 0x32);
        pEntity->vfunc_3(1);
    }
}

// @0x140e6c7a0
void UINpcDuelHPBarDialog::UpdateRemainingTime()
{
    unsigned int nMinutes = 0;
    unsigned int nSeconds = 0;
    unsigned int nNow = GetTickCountMs2();
    if (nNow < m_nEndTick) {
        unsigned int nLeft = m_nEndTick - nNow;
        nLeft /= 1000;
        nMinutes = nLeft / 60;
        nSeconds = nLeft % 60;
    }
    ASDialog* pRoot = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pRoot != 0) {
        CString strTime;
        strTime.Format("%02d%02d", nMinutes, nSeconds);
        pRoot->Invoke("setTime", strTime);
    }
}

// @0x140e6c900
void UINpcDuelHPBarDialog::UpdatePlayerHpBar()
{
    if (m_30 == 0)
        return;
    PC* pPc = reinterpret_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    __int64 nHp = pPc->FUN_141670a00(4);
    __int64 nMaxHp = pPc->FUN_141670a30(4);
    ((Unk_NdScript*)m_30.operator->())->Invoke("setHpBarLeft", nHp, nMaxHp);
}

// @0x140e6c9c0
void UINpcDuelHPBarDialog::FUN_140e6c9c0()
{
    if (m_30 == 0)
        return;
    if (m_nBarCount == 0)
        return;
    CNpc* pNpc = reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(m_nObjectId));
    if (pNpc == 0)
        return;
    const __int64& nHp = pNpc->FUN_141670a00(4);
    const __int64& nMaxHp = pNpc->FUN_141670a30(4);
    if (nMaxHp == 0)
        return;
    __int64 nPerBar = nMaxHp / m_nBarCount;
    if (nPerBar == 0)
        nPerBar = 1;
    int nBar = (int)(nHp / nPerBar + 1);
    if (nBar < 1)
        nBar = 1;
    if (nBar > m_nBarCount)
        nBar = m_nBarCount;
    int nShown;
    __int64 nRest = nHp - (nBar - 1) * nPerBar;
    if (nRest < 0)
        nRest = 0;
    if (nRest > nPerBar)
        nRest = nPerBar;
    ((Unk_NdScript*)m_30.operator->())->FUN_140e6cfe0("setHpBarRight", nRest, nPerBar, nBar);
    nShown = nBar;
    if (nShown <= 1) {
        FUN_140cff840(FUN_1422dbc00(), "m_rightBarCount", 0);
    } else {
        CStringW strCount = FUN_14028dfa0(L"s_npc_duelhpbar_dialog_barCount", nShown);
        FUN_140cff840(FUN_1422dbc00(), "m_rightBarCount", 1);
        FUN_140cfee80(FUN_1422dbc00(), "m_rightBarCount", strCount);
    }
}

// @0x140e6cd80
MS2Ptr<ASEffectManager> FUN_140e6cd80(int nMovieId, CString strClass, __int64 a1, int a2)
{
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(nMovieId);
    if (pMovie == 0)
        return MS2Ptr<ASEffectManager>(0);
    Scaleform::GFx::Value obj;
    pMovie->CreateObject(&obj, strClass, reinterpret_cast<const Scaleform::GFx::Value*>(a1), a2);
    if (((Scaleform::GFx::Value*)(void*)(&obj))->IsUndefined() != 0)
        return MS2Ptr<ASEffectManager>(0);
    MS2Ptr<ASEffectManager> pEffects(new ASEffectManager(obj, nMovieId));
    return pEffects;
}

// @0x140e6cfe0 (the "setHpBarRight" argument list)
Scaleform::GFx::Value Unk_NdScript::FUN_140e6cfe0(const char* szMethod, __int64 a1, __int64 a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_REPLACE_METHOD(0x140E6B8A0, UINpcDuelHPBarDialog, GetTypeName, 61, 0x01524E8D);
MS2_REPLACE_METHOD(0x140E6B8F0, UINpcDuelHPBarDialog, vfunc_67, 90, 0x54B3777A);
MS2_REPLACE_METHOD(0x140E6B950, UINpcDuelHPBarDialog, vfunc_72, 123, 0x2C3B24B1);
MS2_REPLACE_METHOD(0x140E6B9E0, UINpcDuelHPBarDialog, OnLoadComplete, 387, 0x3FEED2D8);
MS2_REPLACE_METHOD(0x140E6BB70, UINpcDuelHPBarDialog, StartDuelBar, 145, 0x9B9A0FFE);
MS2_REPLACE_METHOD(0x140E6C440, UINpcDuelHPBarDialog, FUN_140e6c440, 247, 0xDB003D3C);
MS2_REPLACE_METHOD(0x140E6C540, UINpcDuelHPBarDialog, FUN_140e6c540, 247, 0x169BBFC0);
MS2_REPLACE_METHOD(0x140E6C640, UINpcDuelHPBarDialog, RemoveBuffEffect, 107, 0x38164386);
MS2_REPLACE_METHOD(0x140E6C6C0, UINpcDuelHPBarDialog, vfunc_43, 203, 0x0737E564);
MS2_REPLACE_METHOD(0x140E6C900, UINpcDuelHPBarDialog, UpdatePlayerHpBar, 181, 0x15054B8C);
MS2_REPLACE_METHOD(0x140E6C9C0, UINpcDuelHPBarDialog, FUN_140e6c9c0, 951, 0xE11ED690);
MS2_REPLACE(0x140E6CD80, FUN_140e6cd80, 436, 0x15B246EF);
