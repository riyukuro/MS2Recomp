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

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types ----

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

class Unk_PrdWorld                                                  // the world service
{
public:
    MyPC* FUN_141bd0cc0();                                          // the local player
    PCBase* FUN_141bd1530(__int64 nCharId);                         // a player by character id
};
Unk_PrdWorld* FUN_1403ed2d0();

class Unk_PrdStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_PrdStrings* FUN_1401a9d70();

// The reward item: pointer 0x14053f870, get 0x140203c60, operator-> 0x1401b52a0, release 0x1401b50d0.
class Unk_PrdItemData { public: CString FUN_14053fdd0(); };        // the icon name
class Unk_PrdItemPtr
{
public:
    ~Unk_PrdItemPtr() { FUN_1401b50d0(); }
    void* FUN_140203c60() const;
    Unk_PrdItemData* FUN_1401b52a0() const;
    void FUN_1401b50d0();
private:
    void* unknown;
    void* object;
};
MS2_CHECK_SIZE(Unk_PrdItemPtr, 0x10);
Unk_PrdItemPtr FUN_14053f870(int nItemId);

// The AS root with the five-argument Invoke ("setLeftData" / "setRightData"; the strings by value: the callee destroys them).
class Unk_PrdScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_140f919d0(const char* szMethod, bool a1, bool a2, int a3, CStringW a4, CStringW a5);
};

bool FUN_140a467d0(const MS2Ptr<AScript>*);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);              // has the AS object been released
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& n);
CStringW FUN_140811740(int nId, const int& nArg1, const int& nArg2);   // formatted system text
CStringW FUN_1408116a0(int nId, const int& nArg);
CStringW FUN_14093fa20(int nStringId, const CStringW& strName, const int& nCount);   // formatted message
__int64 FUN_141656a80(PCBase* pPC);                                 // the character id
struct Unk_PrdProfile { CString FUN_1416612e0(); }; // the profile key of the player
CString FUN_141028be0(unsigned __int64 nId, CString strKey, int n, CString strExtra);   // the profile picture url
CStringW FUN_14016a730(const char* sz, int nCodePage);
void FUN_141276180(const CString& strSound, const CString& strArg); // play a UI sound
int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4);
void FUN_140710590(COutPacket& packet);

void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// @0x140f90780
UIPvPRankDuelResultDialog::UIPvPRankDuelResultDialog()
{
    m_80 = 0;
    FUN_141924170(1);
    FUN_141925e70(1, 1);
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
// MS2-FUNCTIONAL: the trailing branch shape (jne/jmp) differs
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
    if (FUN_140ba28d0(&m_30, 0) == 0)
        FUN_140f91120(&m_result);
}

// @0x140f90ec0
// MS2-FUNCTIONAL: behaviour-equivalent (call-temp layout of the by-value CStrings differs)
void UIPvPRankDuelResultDialog::FUN_140f90ec0(__int64 nCharId, bool bLeft)
{
    if (FUN_140a467d0(&m_30) || nCharId == 0)
        return;
    PCBase* pPC = FUN_1403ed2d0()->FUN_141bd1530(nCharId);
    if (pPC == 0)
        return;
    CStringW strUrl = FUN_14016a730(FUN_141028be0(FUN_141656a80(pPC), reinterpret_cast<Unk_PrdProfile*>(pPC)->FUN_1416612e0(), 1, ""), 0);
    if (bLeft)
        m_30->Invoke("setLeftCharProfile", strUrl);
    else
        m_30->Invoke("setRightProfile", strUrl);
}

// @0x140f91120
// MS2-FUNCTIONAL: behaviour-equivalent (frame / temporaries differ)
void UIPvPRankDuelResultDialog::FUN_140f91120(Unk_PrdResult* pResult)
{
    if (pResult->m_nWinnerId == 0)
        return;
    CString strUnused1;
    CString strUnused2;
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    bool bLeftWins = pResult->m_nCharIdL == pResult->m_nWinnerId;
    bool bRightWins = pResult->m_nCharIdR == pResult->m_nWinnerId;
    CStringW strTextL;
    if (pResult->m_nSecL > 0)
    {
        strTextL = FUN_140811740(0x3ff, pResult->m_nMinL, pResult->m_nSecL);
    }
    else
    {
        strTextL = FUN_1401ceea0(L"{0}", pResult->m_nMinL);
        if (pResult->m_nSecL < 0)
            strTextL += FUN_1408116a0(0x400, pResult->m_nSecL);
    }
    static_cast<Unk_PrdScript*>(m_30.operator->())->FUN_140f919d0("setLeftData", bLeftWins,
        FUN_141656a80(pMe) == pResult->m_nCharIdL, pResult->m_nScoreL, pResult->m_strNameL, strTextL);
    CStringW strTextR;
    if (pResult->m_nSecR > 0)
    {
        strTextR = FUN_140811740(0x3ff, pResult->m_nMinR, pResult->m_nSecR);
    }
    else
    {
        strTextR = FUN_1401ceea0(L"{0}", pResult->m_nMinR);
        if (pResult->m_nSecR < 0)
            strTextR += FUN_1408116a0(0x400, pResult->m_nSecR);
    }
    static_cast<Unk_PrdScript*>(m_30.operator->())->FUN_140f919d0("setRightData", bRightWins,
        FUN_141656a80(pMe) == pResult->m_nCharIdR, pResult->m_nScoreR, pResult->m_strNameR, strTextR);
    FUN_140f90ec0(pResult->m_nCharIdL, true);
    FUN_140f90ec0(pResult->m_nCharIdR, false);
    int nReward = 0;
    if (FUN_141656a80(pMe) == pResult->m_nCharIdL)
    {
        nReward = pResult->m_nRewardL;
    }
    else
    {
        if (FUN_141656a80(pMe) == pResult->m_nCharIdR)
            nReward = pResult->m_nRewardR;
    }
    CStringW strReward = FUN_14093fa20(0x401, FUN_1401a9d70()->FUN_141811980(1, 0x55d4a86), nReward);
    if (nReward == 0)
        strReward = L"";
    m_30->Invoke("setRewardText", strReward);
    Unk_PrdItemPtr spItem = FUN_14053f870(0x55d4a86);
    if (spItem.FUN_140203c60() == 0)
    {
        FUN_141276180(s_strGuildBattleReward, "");
    }
    else
    {
        m_30->Invoke("setRewardIcon", spItem.FUN_1401b52a0()->FUN_14053fdd0());
    }
}

// @0x140f919d0
Scaleform::GFx::Value Unk_PrdScript::FUN_140f919d0(const char* szMethod, bool a1, bool a2, int a3, CStringW a4, CStringW a5)
{
    ASArgList args;
    args.FUN_1409b2800(5);
    FUN_1422bcce0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    FUN_1422bcea0(args.FUN_1409b1f70(3), (const wchar_t*)a4);
    FUN_1422bcea0(args.FUN_1409b1f70(4), (const wchar_t*)a5);
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
