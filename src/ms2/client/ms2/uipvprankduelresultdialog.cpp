// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPvPRankDuelResultDialog: see uipvprankduelresultdialog.h.
// MS2-UNIT: ?\uipvprankduelresultdialog.cpp
// MS2-RANGE: 0x140f90780-0x140f91d90 .text$mn
// MS2-RANGE: 0x1400e0ee0-0x1400e10b0 .text$di
// MS2-RANGE: 0x142caa110-0x142caa1e0 .text$yd
// MS2-PIN: ?vfunc_48@UIPvPRankDuelResultDialog@@UEAAHXZ 0x140f91c60
// MS2-PIN: ??_GUIPvPRankDuelResultDialog@@UEAAPEAXI@Z 0x140f91c20
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipvprankduelresultdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

// ---- header statics (dynamic initializers 0x1400e0ee0..): the shared names / skill / stun / condition block, a key-input
// controller and the guild battle reward sound name ----
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strGuildBattleReward = "guildBattle_Reward";

#include "uipvprankduelresultdialog.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2format.h"   // C3: fmt for BlockFormat<int>
class CItemData;   // C3: MS2Ptr<CItemData>::operator->

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types ----

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

class Unk_PrdWorld                                                  // the world service
{
public:
    MyPC* GetLocalPlayer();                                          // the local player
};

// The reward item: pointer 0x14053f870, get 0x140203c60, operator-> 0x1401b52a0, release 0x1401b50d0.
class Unk_PrdItemData : public CItemData { };        // the icon name
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// The AS root with the five-argument Invoke ("setLeftData" / "setRightData"; the strings by value: the callee destroys them).
class Unk_PrdScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_140f919d0(const char* szMethod, bool a1, bool a2, int a3, CStringW a4, CStringW a5);
};

template <class A, class B> CStringW FormatStringId(int nId, const A& a, const B& b);
#include "ms2/placeholder/blockformat.h"   // C3: BlockFormat<...> over FUN_14028dee0 by its real name (was BlockFormat(int, const ArgList&))
 // the profile key of the player
CString FUN_141028be0(__int64 nId, const CString& strKey, int n, CString strExtra);   // the profile picture url
CStringW FUN_14016a730(const char* sz, int nCodePage);
int PlaySystemSound(const CString& strSound, const CString& strArg); // play a UI sound
int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4);
void FUN_140710590(COutPacket& packet);

void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void SetBoolean(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// @0x140f90780
UIPvPRankDuelResultDialog::UIPvPRankDuelResultDialog()
{
    m_80 = 0;
    SetTweenEnabled(1);
    SetFlag(1, 1);
}

// @0x140f90820
UIPvPRankDuelResultDialog::~UIPvPRankDuelResultDialog()
{
}

// @0x140f90870
CString UIPvPRankDuelResultDialog::GetTypeName()
{
    return "PvPRankDuelResultDialog";
}

// @0x140f908c0
int UIPvPRankDuelResultDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140f908f0
void UIPvPRankDuelResultDialog::vfunc_67()
{
    COutPacket packet(static_cast<int>(SendOp::Pvp), 0);
    packet.WriteUInt8(0x68);
    FUN_140710590(packet);
    UIDialog::vfunc_67();
}

// @0x140f90950
void UIPvPRankDuelResultDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_result.m_nWinnerId != 0)
        FUN_140f91120(&m_result);
}

// @0x140f909a0
void UIPvPRankDuelResultDialog::vfunc_26()
{
    UIDialog::vfunc_26();
}

// @0x140f909c0
int UIPvPRankDuelResultDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    return 0;
}

// @0x140f90a60
void UIPvPRankDuelResultDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(0, 0, 0);
}

// @0x140f90b10
void UIPvPRankDuelResultDialog::FUN_140f90b10(CInPacket* pIn)
{
    m_result.m_nWinnerId = pIn->ReadInt64();
    m_result.m_strNameL = pIn->ReadUnicodeString();
    m_result.m_nCharIdL = pIn->ReadInt64();
    m_result.m_nScoreL = pIn->ReadInt32();
    m_result.m_nMinL = pIn->ReadInt32();
    m_result.m_nSecL = pIn->ReadInt32();
    m_result.m_nRewardL = pIn->ReadInt32();
    m_result.m_strNameR = pIn->ReadUnicodeString();
    m_result.m_nCharIdR = pIn->ReadInt64();
    m_result.m_nScoreR = pIn->ReadInt32();
    m_result.m_nMinR = pIn->ReadInt32();
    m_result.m_nSecR = pIn->ReadInt32();
    m_result.m_nRewardR = pIn->ReadInt32();
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0)
        return;
    FUN_140f91120(&m_result);
}

// @0x140f90ec0
void UIPvPRankDuelResultDialog::SetPlayerProfile(__int64 nCharId, bool bLeft)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    if (nCharId == 0)
        return;
    PCBase* pPC = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(nCharId));
    if (pPC == 0)
        return;
    CStringW strUrl = FUN_14016a730(FUN_141028be0(((class PCBase*)(class PCBase*)(pPC))->FUN_141656a80(), reinterpret_cast<PC*>(pPC)->FUN_1416612e0(), 1, ""), 0);
    if (bLeft)
        m_30->Invoke("setLeftCharProfile", strUrl);
    else
        m_30->Invoke("setRightProfile", strUrl);
}

// @0x140f91120
void UIPvPRankDuelResultDialog::FUN_140f91120(Unk_PrdResult* pResult)
{
    if (pResult->m_nWinnerId == 0)
        return;
    CString strUnused1;
    CString strUnused2;
    MyPC* pMe = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pMe == 0)
        return;
    bool bLeftWins = pResult->m_nCharIdL == pResult->m_nWinnerId;
    bool bRightWins = pResult->m_nCharIdR == pResult->m_nWinnerId;
    {
        CStringW strTextL;
        if (pResult->m_nSecL > 0)
        {
            strTextL = FormatStringId<int, int>(0x3ff, pResult->m_nMinL, pResult->m_nSecL);
        }
        else
        {
            strTextL = StringFormat<int>(L"{0}", reinterpret_cast<const int&>(pResult->m_nMinL));
            if (pResult->m_nSecL < 0)
                strTextL += BlockFormat<int>(0x400, pResult->m_nSecL);
        }
        static_cast<Unk_PrdScript*>(m_30.operator->())->FUN_140f919d0("setLeftData", bLeftWins,
            ((class PCBase*)(class PCBase*)(pMe))->FUN_141656a80() == pResult->m_nCharIdL, pResult->m_nScoreL, pResult->m_strNameL, strTextL);
    }
    {
        CStringW strTextR;
        if (pResult->m_nSecR > 0)
        {
            strTextR = FormatStringId<int, int>(0x3ff, pResult->m_nMinR, pResult->m_nSecR);
        }
        else
        {
            strTextR = StringFormat<int>(L"{0}", reinterpret_cast<const int&>(pResult->m_nMinR));
            if (pResult->m_nSecR < 0)
                strTextR += BlockFormat<int>(0x400, pResult->m_nSecR);
        }
        static_cast<Unk_PrdScript*>(m_30.operator->())->FUN_140f919d0("setRightData", bRightWins,
            ((class PCBase*)(class PCBase*)(pMe))->FUN_141656a80() == pResult->m_nCharIdR, pResult->m_nScoreR, pResult->m_strNameR, strTextR);
    }
    SetPlayerProfile(pResult->m_nCharIdL, true);
    SetPlayerProfile(pResult->m_nCharIdR, false);
    int nReward = 0;
    if (((class PCBase*)(class PCBase*)(pMe))->FUN_141656a80() == pResult->m_nCharIdL)
    {
        nReward = pResult->m_nRewardL;
    }
    else
    {
        if (((class PCBase*)(class PCBase*)(pMe))->FUN_141656a80() == pResult->m_nCharIdR)
            nReward = pResult->m_nRewardR;
    }
    CStringW strReward = FormatStringId<CStringW, int>(0x401, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, 0x55d4a86), nReward);
    if (nReward == 0)
        strReward = L"";
    m_30->Invoke("setRewardText", strReward);
    MS2Ptr<CItemData> spItem = FUN_14053f870(0x55d4a86);
    if (spItem.get() != 0)
    {
        m_30->Invoke("setRewardIcon", reinterpret_cast<Unk_PrdItemData*>(spItem.operator->())->GetIconPath());
        return;
    }
    PlaySystemSound(s_strGuildBattleReward, "");
}

// @0x140f919d0
Scaleform::GFx::Value Unk_PrdScript::FUN_140f919d0(const char* szMethod, bool a1, bool a2, int a3, CStringW a4, CStringW a5)
{
    ASArgList args;
    args.resize(5);
    SetBoolean(&args[0], a1);
    SetBoolean(&args[1], a2);
    FUN_1422bccb0(&args[2], a3);
    FUN_1422bcea0(&args[3], (const wchar_t*)a4);
    FUN_1422bcea0(&args[4], (const wchar_t*)a5);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f91b30
Unk_PrdResult::Unk_PrdResult()
    : m_nScoreL(0), m_nScoreR(0), m_nMinL(0), m_nMinR(0), m_nSecL(0), m_nSecR(0),
      m_nCharIdL(0), m_nCharIdR(0), m_nWinnerId(0), m_nRewardL(0), m_nRewardR(0)
{
}

// @0x140f91bf0
Unk_PrdResult::~Unk_PrdResult()
{
}
