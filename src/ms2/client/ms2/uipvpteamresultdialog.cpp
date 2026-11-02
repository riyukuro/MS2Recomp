// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPvPTeamResultDialog: see uipvpteamresultdialog.h.
// MS2-UNIT: ?\uipvpteamresultdialog.cpp
// MS2-RANGE: 0x1413450d0-0x1413466b0 .text$mn
// MS2-RANGE: 0x1400f0390-0x1400f0590 .text$di
// MS2-PIN: ?vfunc_48@UIPvPTeamResultDialog@@UEAAHXZ 0x141346640
// MS2-PIN: ??_GUIPvPTeamResultDialog@@UEAAPEAXI@Z 0x141346590
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipvpteamresultdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

// ---- header statics (dynamic initializers 0x1400f0390..): two sound names, a key-input controller, then the shared
// names / skill / stun / condition block ----
static CString s_strMassiveFail = "massive_fail";
static CString s_strBattleFieldWin = "BattleField_Win";
#include "ms2/placeholder/cmypckeyinputcontroller.h"
static UICommon::CMyPCKeyInputController s_keyInput;
#include "ms2/placeholder/header_statics_a.h"

#include "uipvpteamresultdialog.h"

#include "ms2/commonfiles/packet.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/pvpmanager.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
#include "ms2/placeholder/ichromamanager.h"  // C3: ChromaSDK::GetChromaManager
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/commonfiles/pvpinfo.h"

// ---- unit-local views of exe types ----

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

// One member of a team (the PvP service's team lists): the character id, name and the score columns.
class Unk_PtMember
{
public:
    __int64 m_0;                                                // character id
    CStringW m_8;                                               // name
    int m_10;                                                   // steal
    int m_14;                                                   // kill
    int m_18;                                                   // death
    int m_1c;                                                   // job
    bool m_20;                                                  // offline
};

class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    static class WorldService* GetInstance();
};

// The PvP service: the team lists (+0x68).
typedef std::vector<Unk_PvpEntryItem*> Unk_PtVec;
class Unk_PtMgr
{
public:
    Unk_PtVec* FUN_1413465d0(int nTeam);                        // the member list of a team
    void FUN_141346600(int* pScoreA, int* pScoreB);             // the team scores
private:
    char m_pad_00[0x68];
    Unk_PvpEntryBlock m_68;
};

// The AS root with the PvP-result Invoke helpers (the strings by value: the callee destroys them).
class Unk_PtScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_140c4bd20(const char* szMethod, bool a1, Scaleform::GFx::Value a2);
    Scaleform::GFx::Value FUN_141346320(const char* szMethod, bool a1, const char* a2, const char* a3, const char* a4, int a5);
    Scaleform::GFx::Value FUN_141346430(const char* szMethod, bool a1, CStringW a2, const wchar_t* a3, CStringW a4, int a5);
};

class Unk_PtConst { public: unsigned int m_n; };
class Unk_PtConfig
{
public:
    char m_pad_0[0x4f70];
    Unk_PtConst m_rewardItem;                                   // +0x4f70
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200


CStringW FUN_14016a730(const char* sz, int nCodePage);
int FUN_141276180(const CString& strSound, const CString& strArg);               // play a UI sound
void FUN_141415450(const CString& strName, MS2Ptr<CItem> pItem, int a1, int a2, int a3);
void FUN_141415600(const CString& strBindID);                   // release the item bound to the name
bool FUN_140a467d0(const MS2Ptr<AScript>*);
int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4);
void FUN_140710590(COutPacket& packet);
void FUN_141346650();
Unk_PtMember** FUN_141346670(Unk_PtVec* pVec, size_t nIndex);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);

// @0x1413450d0
UIPvPTeamResultDialog::UIPvPTeamResultDialog()
{
    m_80 = 0;
    m_nCount = -1;
    FUN_141924170(1);
}

// @0x141345160
UIPvPTeamResultDialog::~UIPvPTeamResultDialog()
{
}

// @0x1413451b0
CString UIPvPTeamResultDialog::GetTypeName()
{
    return "PvPTeamResultDialog";
}

// @0x141345200
void UIPvPTeamResultDialog::vfunc_67()
{
    if (m_nCount >= 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Pvp), 0);
        packet.WriteUInt8(0x6e);
        FUN_140710590(packet);
        m_nCount = -1;
    }
    FUN_141346140();
    UIDialog::vfunc_67();
}

// @0x141345290
void UIPvPTeamResultDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141345de0();
}

// @0x1413452c0
void UIPvPTeamResultDialog::FUN_1413452c0()
{
    m_nCount = -1;
    m_nUnk17c = -1;
    m_nWinTeam = 0;
    m_nMyTeam = 0;
}

// @0x141345310
void UIPvPTeamResultDialog::FUN_141345310()
{
    PC* pPlayer = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    bool bNoTeam = pPlayer->FUN_140967420() == NULL;
    if (bNoTeam)
        return;
    int nMyTeam = 0;
    if (reinterpret_cast<CPvPInfo*>(pPlayer->FUN_140967420().operator->())->GetPoint() == 0xc9)
        nMyTeam = 1;
    else if (reinterpret_cast<CPvPInfo*>(pPlayer->FUN_140967420().operator->())->GetPoint() == 0xca)
        nMyTeam = 2;
    m_nMyTeam = nMyTeam;
    FUN_141345e40();
}

// @0x1413454b0
void UIPvPTeamResultDialog::FUN_1413454b0()
{
    if (m_30.IsNull())
        return;
    int teams[2] = {0xc9, 0xca};
    for (int i = 0; i < 2; i++)
    {
        Unk_PtVec* pList = reinterpret_cast<Unk_PtMgr*>(TSingleton<CPVPManager>::GetInstance())->FUN_1413465d0(teams[i]);
        if (pList != 0)
        {
            for (size_t j = 0; j < pList->size(); j++)
            {
                Unk_PtMember* pMember = *FUN_141346670(pList, j);
                if (pMember == 0)
                    continue;
                ASObj obj(2);
                if (!FUN_141345c60(obj, (int)j, pMember))
                    continue;
                static_cast<Unk_PtScript*>(m_30.operator->())->FUN_140c4bd20("AddOrUpdateTeamMember", teams[i] == 0xc9, obj.FUN_1422bb870());
            }
        }
    }
}

// @0x1413456a0
void UIPvPTeamResultDialog::FUN_1413456a0()
{
    if (m_30.IsNull())
        return;
    int nScoreA = 0;
    int nScoreB = 0;
    reinterpret_cast<Unk_PtMgr*>(TSingleton<CPVPManager>::GetInstance())->FUN_141346600(&nScoreA, &nScoreB);
    static_cast<Unk_PtScript*>(m_30.operator->())->FUN_1409ba0d0("UpdateScore", nScoreA, nScoreB);
}

// @0x141345740
void UIPvPTeamResultDialog::FUN_141345740(int nTeam, int nCount)
{
    m_nCount = nCount;
    m_nUnk17c = 0;
    if (nTeam == 0xc9)
        m_nWinTeam = 1;
    else if (nTeam == 0xca)
        m_nWinTeam = 2;
    else
        m_nWinTeam = 0;
    if (m_30.IsNull())
        return;
    FUN_1413457f0();
}

#ifndef MS2_HOOK_DLL
// @0x1413457f0
void UIPvPTeamResultDialog::FUN_1413457f0()
{
    if (m_nCount < 0)
    {
        static_cast<Unk_PtScript*>(m_30.operator->())->FUN_141346320("showLastResult", false, "", "", "", 0);
    }
    else if (m_nCount >= 0)
    {
        unsigned int nItemId = *reinterpret_cast<unsigned int*>(reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_PtConfig*)FUN_1401d3200())->m_rewardItem)->Get());
        CString strBind = FUN_141345eb0(nItemId, m_nCount);
        CStringW strIcon = FUN_14016a730(strBind, 0);
        CStringW strReward(L"");
        CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId);
        if (m_nCount == 0)
            strIcon = L"";
        if (m_nMyTeam == m_nWinTeam)
        {
            FUN_141276180(s_strBattleFieldWin, "");
            ChromaSDK::GetChromaManager()->SetState(9);
            strReward = FUN_14028dfa0<CStringW, int>(L"s_team_pvp_winner_reward_one_type", strName, m_nCount);
        }
        else
        {
            FUN_141276180(s_strMassiveFail, "");
            strReward = FUN_14028dfa0<CStringW, int>(L"s_team_pvp_loser_reward_one_type", strName, m_nCount);
        }
        static_cast<Unk_PtScript*>(m_30.operator->())->FUN_141346430("showLastResult", true, strIcon, L"", strReward, m_nWinTeam);
    }
}
#endif

// @0x141345c60
bool UIPvPTeamResultDialog::FUN_141345c60(ASObj& obj, int nIndex, Unk_PtMember* pMember)
{
    if (pMember == 0)
        return false;
    PC* pPlayer = ((PC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return false;
    obj.FUN_1407cb9c0("index", nIndex);
    obj.FUN_1407cbb20("charName", pMember->m_8);
    obj.FUN_1407cb9c0("kill", pMember->m_14);
    obj.FUN_1407cb9c0("death", pMember->m_18);
    obj.FUN_1407cb9c0("steal", pMember->m_10);
    obj.FUN_1407cbbe0("isOffline", pMember->m_20 == 0);
    obj.FUN_1407cbbe0("isMe", pPlayer->FUN_141656a80() == pMember->m_0);
    obj.FUN_1407cb9c0("job", pMember->m_1c);
    return true;
}

// @0x141345de0
void UIPvPTeamResultDialog::FUN_141345de0()
{
    if (m_30.IsNull())
        return;
    FUN_141345e40();
    FUN_1413454b0();
    FUN_1413456a0();
    FUN_1413457f0();
}

// @0x141345e40
void UIPvPTeamResultDialog::FUN_141345e40()
{
    if (m_30.IsNull())
        return;
    m_30->Invoke("SetMyTeam", m_nMyTeam);
}

// @0x141345eb0
CString UIPvPTeamResultDialog::FUN_141345eb0(unsigned int nItemId, int nAmount)
{
    CString strBind;
    strBind.Format("%s_%d", (LPCSTR)GetTypeName(), nItemId);
    if (m_slots.find(strBind) == m_slots.end())
    {
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nItemId, 1, 0))
            return "";
        spItem->SetCountClamped(nAmount);
        FUN_141415450(strBind, spItem, 0, 0x411, 0);
        m_slots.insert(strBind);
    }
    return strBind;
}

// @0x141346140
void UIPvPTeamResultDialog::FUN_141346140()
{
    for (std::set<CString>::iterator it = m_slots.begin(), itEnd = m_slots.end(); it != itEnd; ++it)
        FUN_141415600(*it);
    m_slots.clear();
}

// @0x1413461d0
int UIPvPTeamResultDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
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

// @0x141346270
void UIPvPTeamResultDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(1, 0, 150);
}

// @0x141346320
Scaleform::GFx::Value Unk_PtScript::FUN_141346320(const char* szMethod, bool a1, const char* a2, const char* a3, const char* a4, int a5)
{
    ASArgList args;
    args.FUN_1409b2800(5);
    FUN_1422bcce0(args.FUN_1409b1f70(0), a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    FUN_1422bce70(args.FUN_1409b1f70(2), a3);
    FUN_1422bce70(args.FUN_1409b1f70(3), a4);
    FUN_1422bccb0(args.FUN_1409b1f70(4), a5);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141346430
Scaleform::GFx::Value Unk_PtScript::FUN_141346430(const char* szMethod, bool a1, CStringW a2, const wchar_t* a3, CStringW a4, int a5)
{
    ASArgList args;
    args.FUN_1409b2800(5);
    FUN_1422bcce0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), (const wchar_t*)a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    FUN_1422bcea0(args.FUN_1409b1f70(3), (const wchar_t*)a4);
    FUN_1422bccb0(args.FUN_1409b1f70(4), a5);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1413465d0
Unk_PtVec* Unk_PtMgr::FUN_1413465d0(int nTeam)
{
    return m_68.FUN_14101c160(nTeam);
}

// @0x141346600
void Unk_PtMgr::FUN_141346600(int* pScoreA, int* pScoreB)
{
    m_68.FUN_14101c1a0(pScoreA, pScoreB);
}

// @0x141346650
void FUN_141346650()
{
    std::_Xout_of_range("invalid vector<T> subscript");
}

// @0x141346670
Unk_PtMember** FUN_141346670(Unk_PtVec* pVec, size_t nIndex)
{
    if (pVec->size() <= nIndex)
        FUN_141346650();
    return (Unk_PtMember**)(static_cast<const Unk_PtVec*>(pVec)->_Myfirst() + nIndex);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb0570-0x142cb0660 .text$yd
