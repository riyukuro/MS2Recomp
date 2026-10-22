// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPvPGuildTeamResultDialog: see uipvpguildteamresultdialog.h.
// MS2-UNIT: ?\uipvpguildteamresultdialog.cpp
// MS2-RANGE: 0x1413405b0-0x141342570 .text$mn
// MS2-RANGE: 0x1400efc20-0x1400efce0 .text$di
// MS2-RANGE: 0x142cb0210-0x142cb0290 .text$yd
// MS2-PIN: ?vfunc_48@UIPvPGuildTeamResultDialog@@UEAAHXZ 0x141342560
// MS2-PIN: ??_GUIPvPGuildTeamResultDialog@@UEAAPEAXI@Z 0x141342520
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipvpguildteamresultdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uipvpguildteamresultdialog.h"

#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

// ---- header statics (dynamic initializers 0x1400efc20..) ----
static CString s_strMassiveFail = "massive_fail";
static CString s_strMassiveSuccess = "massive_success";
static CString s_strBattleFieldWin = "BattleField_Win";
static CString s_strGuildBattleReward = "guildBattle_Reward";

// ---- unit-local views of exe types ----

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

class Unk_PgtrGuildSvc                                              // the guild service: the own guild at +8
{
public:
    void* m_pad_00;
    CGuildInfo m_info;
};
Unk_PgtrGuildSvc* FUN_1403ed290();

struct Unk_PgtrConfig
{
    char m_pad_00[0xa0];
    CString m_strMarkServer;                                        // +0xa0 passed to the guild mark URL builder
};
Unk_PgtrConfig* FUN_1401d31f0();

class Unk_PgtrStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_PgtrStrings* FUN_1401a9d70();

class Unk_PgtrSound                                                 // the sound / cursor service
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int n);
};
Unk_PgtrSound* FUN_140a94350();

// The reward item: pointer 0x14053f870, get 0x140203c60, operator-> 0x1401b52a0, release 0x1401b50d0.
class Unk_PgtrItemData { public: CString FUN_14053fdd0(); };       // the icon name
class Unk_PgtrItemPtr
{
public:
    ~Unk_PgtrItemPtr() { FUN_1401b50d0(); }
    void* FUN_140203c60() const;
    Unk_PgtrItemData* FUN_1401b52a0() const;
    void FUN_1401b50d0();
private:
    void* unknown;
    void* object;
};
MS2_CHECK_SIZE(Unk_PgtrItemPtr, 0x10);
Unk_PgtrItemPtr FUN_14053f870(int nItemId);

CStringW FUN_140298ea0(CStringW strKey);                            // the string table text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);        // case-insensitive equal
CStringW FUN_140811740(int nId, const int& nArg1, const int& nArg2);   // formatted system text
CStringW FUN_1408116a0(int nId, const int& nArg);
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& n);
CStringW FUN_14093fa20(int nStringId, const CStringW& strName, const int& nCount);   // formatted message
CString FUN_14016a600(const wchar_t* sz, int nCodePage);
CStringW FUN_14016a730(const char* sz, int nCodePage);
CString FUN_141029590(unsigned __int64 nId, const CString& strKey, const CString& strName, CString strExtra);
void FUN_141276180(const CString& strSound, const CString& strArg); // play a UI sound
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
bool FUN_140a467d0(const MS2Ptr<AScript>*);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);              // has the AS object been released
int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4);
void FUN_140710590(COutPacket& packet);

void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);

// @0x1413405b0
Unk_PgtrGuild::Unk_PgtrGuild()
    : m_nGuildId(0), m_nScore(0), m_nMin(0), m_nSec(0)
{
}

// @0x141340650
void Unk_PgtrGuild::FUN_141340650(CInPacket* pIn)
{
    m_strName = pIn->ReadUnicodeString();
    m_nGuildId = pIn->ReadInt64();
    m_nScore = pIn->ReadInt32();
    m_nMin = pIn->ReadInt32();
    m_nSec = pIn->ReadInt32();
    m_strMark = pIn->ReadUnicodeString();
}

// @0x141340810
void Unk_PgtrGuild::FUN_141340810(CInPacket* pIn)
{
    m_nGuildId = pIn->ReadInt64();
    m_strName = pIn->ReadUnicodeString();
    m_strMark = pIn->ReadUnicodeString();
    m_nScore = pIn->ReadInt32();
    m_nMin = 0;
    m_nSec = 0;
    m_strTime.Empty();
}

// @0x1413409a0
UIPvPGuildTeamResultDialog::UIPvPGuildTeamResultDialog()
    : m_bOwnA(false), m_bSound(false), m_bSwap(false)
{
    m_80 = 0;
    FUN_141924170(1);
    FUN_141925e70(1, 1);
}

// @0x141340aa0
UIPvPGuildTeamResultDialog::~UIPvPGuildTeamResultDialog()
{
}

// @0x141340b30
CString UIPvPGuildTeamResultDialog::GetTypeName()
{
    return "PvPGuildTeamResultDialog";
}

// @0x141340b80
void UIPvPGuildTeamResultDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1413418a0();
}

// @0x141340bb0
void UIPvPGuildTeamResultDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    if (m_nMode == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Pvp), 0);
        packet.WriteUInt8(0x68);
        FUN_140710590(packet);
    }
}

// @0x141340c20
int UIPvPGuildTeamResultDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
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

// @0x141340cc0
void UIPvPGuildTeamResultDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(0, 0, -30);
}

// @0x141340d70
void UIPvPGuildTeamResultDialog::FUN_141340d70(CInPacket* pIn)
{
    m_guildA.FUN_141340650(pIn);
    m_guildB.FUN_141340650(pIn);
    int nCount = pIn->ReadInt32();
    m_nMode = 0;
    m_strTitle = FUN_140298ea0(L"s_PvpGuildResult_title_pvp");
    __int64 nOwnGuild = FUN_1403ed290()->m_info.FUN_1404ccbd0();
    m_guildA.m_strResult = L"win";
    m_guildB.m_strResult = L"lose";
    m_bOwnA = m_guildA.m_nGuildId == nOwnGuild;
    m_bSound = true;
    m_bSwap = m_bOwnA;
    m_guildA.m_strTime = FUN_140811740(0x3ff, m_guildA.m_nMin, m_guildA.m_nSec);
    m_guildB.m_strTime = FUN_1401ceea0(L"{0}", m_guildB.m_nMin);
    if (m_guildB.m_nSec > 0)
    {
        m_guildB.m_strTime = FUN_140811740(0x3ff, m_guildB.m_nMin, m_guildB.m_nSec);
    }
    else
    {
        if (m_guildB.m_nSec < 0)
            m_guildB.m_strTime += FUN_1408116a0(0x400, m_guildB.m_nSec);
    }
    m_strReward.Empty();
    if (nCount != 0)
        m_strReward = FUN_14093fa20(0x401, FUN_1401a9d70()->FUN_141811980(1, 0x55d4a86), nCount);
    m_nRewardItem = 0x55d4a86;
    if (FUN_141924630())
        FUN_1413418a0();
    else
        FUN_141924680();
}

// @0x141341220
void UIPvPGuildTeamResultDialog::FUN_141341220(CInPacket* pIn)
{
    m_guildA.FUN_141340810(pIn);
    m_guildB.FUN_141340810(pIn);
    m_nMode = 1;
    m_strTitle = FUN_140298ea0(L"s_PvpGuildResult_title_vsGame");
    m_bSwap = true;
    m_nRewardItem = 0;
    m_bSound = false;
    FUN_141342190();
    __int64 nOwnGuild = FUN_1403ed290()->m_info.FUN_1404ccbd0();
    Unk_PgtrGuild* pOwn = FUN_1413420e0(nOwnGuild, true);
    if (FUN_1403b3c40(pOwn->m_strResult, L"win"))
        m_strReward = FUN_1405c2690(L"s_PvpGuildResult_vsGame_result_lose", pOwn->m_strName);
    if (FUN_1403b3c40(pOwn->m_strResult, L"lose"))
        m_strReward = FUN_1405c2690(L"s_PvpGuildResult_vsGame_result_win", pOwn->m_strName);
    if (FUN_1403b3c40(pOwn->m_strResult, L"draw"))
        m_strReward = FUN_1405c2690(L"s_PvpGuildResult_vsGame_result_draw", pOwn->m_strName);
    if (FUN_141924630())
        FUN_1413418a0();
    else
        FUN_141924680();
}

// @0x1413415e0
void UIPvPGuildTeamResultDialog::FUN_1413415e0(__int64 nGuildId, const CStringW& strMark)
{
    if (FUN_140a467d0(&m_30))
        return;
    if (nGuildId == 0)
        return;
    if (m_guildA.m_nGuildId != nGuildId && m_guildB.m_nGuildId != nGuildId)
        return;
    CStringW strUrl = FUN_14016a730(FUN_141029590(nGuildId, FUN_14016a600(strMark, 0), "", FUN_1401d31f0()->m_strMarkServer), 0);
    Unk_PgtrGuild* pLeft = FUN_141342040(true);
    if (pLeft->m_nGuildId == nGuildId)
        m_30->Invoke("setLeftGuildMark", strUrl);
    else
        m_30->Invoke("setRightGuildMark", strUrl);
}

// @0x1413418a0
void UIPvPGuildTeamResultDialog::FUN_1413418a0()
{
    if (FUN_140ba28d0(&m_30, 0))
        return;
    FUN_140cfee80(FUN_1422dbb40(), "m_msg", m_strTitle);
    Unk_PgtrGuild* pLeft;
    {
        Unk_PgtrGuild* p = m_bSwap ? &m_guildA : &m_guildB;
        pLeft = p;
    }
    Unk_PgtrGuild* pRight;
    {
        Unk_PgtrGuild* p = m_bSwap ? &m_guildB : &m_guildA;
        pRight = p;
    }
    m_30->Invoke("setLeftData", pLeft->m_strResult, pLeft->m_nScore, pLeft->m_strName, pLeft->m_strTime);
    m_30->Invoke("setRightData", pRight->m_strResult, pRight->m_nScore, pRight->m_strName, pRight->m_strTime);
    const char* szType;
    if (m_nRewardItem)
        szType = "item";
    else
        szType = "text";
    m_30->Invoke("setRewardText", m_strReward, szType);
    FUN_1413415e0(pLeft->m_nGuildId, pLeft->m_strMark);
    FUN_1413415e0(pRight->m_nGuildId, pRight->m_strMark);
    if (m_nRewardItem != 0)
    {
        Unk_PgtrItemPtr spItem = FUN_14053f870(m_nRewardItem);
        if (spItem.FUN_140203c60() != 0)
            m_30->Invoke("setRewardIcon", spItem.FUN_1401b52a0()->FUN_14053fdd0());
    }
    FUN_141341e70();
}

#ifndef MS2_HOOK_DLL
// @0x141341e70
void UIPvPGuildTeamResultDialog::FUN_141341e70()
{
    if (!m_bSound)
        return;
    if (m_bOwnA)
    {
        FUN_141276180(s_strMassiveSuccess, "");
        FUN_141276180(s_strBattleFieldWin, "");
        FUN_140a94350()->vfunc_10(9);
        FUN_141276180("system_notice_GuildBattleGuide06", "");
    }
    else
    {
        FUN_141276180(s_strMassiveFail, "");
        FUN_141276180("system_notice_GuildBattleGuide07", "");
    }
    FUN_141276180(s_strGuildBattleReward, "");
}
#endif

// @0x141342040
Unk_PgtrGuild* UIPvPGuildTeamResultDialog::FUN_141342040(bool bLeft)
{
    if (m_bSwap)
    {
        Unk_PgtrGuild* pGuild = bLeft ? &m_guildA : &m_guildB;
        return pGuild;
    }
    {
        Unk_PgtrGuild* pGuild = bLeft ? &m_guildB : &m_guildA;
        return pGuild;
    }
}

// @0x1413420e0
Unk_PgtrGuild* UIPvPGuildTeamResultDialog::FUN_1413420e0(__int64 nGuildId, bool bOther)
{
    if (m_guildA.m_nGuildId == nGuildId)
    {
        Unk_PgtrGuild* pGuild = bOther ? &m_guildB : &m_guildA;
        return pGuild;
    }
    else
    {
        Unk_PgtrGuild* pGuild = bOther ? &m_guildA : &m_guildB;
        return pGuild;
    }
}

// @0x141342190
void UIPvPGuildTeamResultDialog::FUN_141342190()
{
    if (m_guildA.m_nScore > m_guildB.m_nScore)
    {
        m_guildA.m_strResult = L"win";
        m_guildB.m_strResult = L"lose";
    }
    else if (m_guildA.m_nScore < m_guildB.m_nScore)
    {
        m_guildA.m_strResult = L"lose";
        m_guildB.m_strResult = L"win";
    }
    else
    {
        m_guildA.m_strResult = L"draw";
        m_guildB.m_strResult = L"draw";
    }
}

// @0x141342280
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, int a2, CStringW a3, CStringW a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcea0(args.FUN_1409b1f70(0), (const wchar_t*)a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), (const wchar_t*)a3);
    FUN_1422bcea0(args.FUN_1409b1f70(3), (const wchar_t*)a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1413423e0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, const char* a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcea0(args.FUN_1409b1f70(0), (const wchar_t*)a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}
