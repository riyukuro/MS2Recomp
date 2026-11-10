// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIPvPResultDialog: the result table of the FFA / one-punch PvP match.
// MS2-UNIT: ?\uipvpresultdialog.cpp
// MS2-RANGE: 0x1413439a0-0x141344ab0 .text$mn
// MS2-PIN: ?vfunc_48@UIPvPResultDialog@@UEAAHXZ 0x141344aa0
// MS2-PIN: ??_GUIPvPResultDialog@@UEAAPEAXI@Z 0x141344a40
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipvpresultdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uipvpresultdialog.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/commonfiles/pvpinfo.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/fittingdollpc.h"   // C3: PC::FUN_140967420
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/pvpmanager.h"
#include "ms2/ms2format.h"   // C3: StringFormat<int> (was FUN_1401ceea0)
class CItemData;   // C3: MS2Ptr<CItemData>::operator->

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types ----

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

class Unk_PrWorld                                                   // the world service
{
public:
    MyPC* GetLocalPlayer();                                          // the local player
};

// One row of the result (the ranking's row, see uipvprankingdialog.cpp).
class Unk_PvPRankEntry
{
public:
    bool HasRank();                                           // the player has a rank

    __int64 m_nCharId;                  // +0x00
    CStringW m_strName;                 // +0x08
    int m_nScore;                       // +0x10
    int m_nKill;                        // +0x14
    int m_nDeath;                       // +0x18
    int m_pad_1c;
    __int64 m_nDamage;                  // +0x20
    bool m_bOnline;                     // +0x28
};

class Unk_PvPRankTable { };                                         // the rank list (Unk_PvpTimer)
class Unk_PvPRankService                                            // the game-mode service
{
public:
    Unk_PvPRankEntry* GetRankEntry(int nRank);                     // the row of a rank
    int GetRankCount() { return reinterpret_cast<Unk_PvpTimer*>(&m_table)->GetRowCount(); }         // 0x141344a80 the row count
private:
    void* m_pad_00;
    Unk_PvPRankTable m_table;
};

// The player's PvP info (PC::FUN_140967420's MS2Ptr<CPvPInfo>, fittingdollpc.h).

// The reward item: pointer 0x14053f870, get 0x140203c60, operator-> 0x1401b52a0, release 0x1401b50d0.
class Unk_PrItemData : public CItemData { };         // the icon name
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// The AS root with the two-argument Invoke ("showLastResult").
class Unk_PrScript : public AScript { };
class Unk_RsScript { public: Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int a1, CStringW a2); };   // C3: unit-local view (def in unit_14129ba60); Invoke(int, string)

template <class A, class B> CStringW FormatStringId(int nId, const A& a, const B& b);
int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4);
void FUN_140710590(COutPacket& packet);

// @0x1413439a0
UIPvPResultDialog::UIPvPResultDialog()
{
    m_178 = 2;
    m_17c = 0x55d4a86;
    m_180 = -1;
    SetTweenEnabled(1);
}

// @0x141343a30
UIPvPResultDialog::~UIPvPResultDialog()
{
}

// @0x141343a70
CString UIPvPResultDialog::GetTypeName()
{
    return "PvPResultDialog";
}

// @0x141343ac0
int UIPvPResultDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x141343af0
void UIPvPResultDialog::vfunc_67()
{
    if (m_180 >= 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Pvp), 0);
        packet.WriteUInt8(0x68);
        FUN_140710590(packet);
    }
    m_180 = -1;
    UIDialog::vfunc_67();
}

// @0x141343b70
void UIPvPResultDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141344780(m_180);
}

// @0x141343bb0
void UIPvPResultDialog::vfunc_79(void* pData)
{
    UIDialog::vfunc_79(pData);
    vfunc_55() || ((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull();
}

// @0x141343c10
void UIPvPResultDialog::FUN_141343c10(int nFrom, int nTo)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    int nFirst = (std::min)(nFrom, nTo);
    int nLast = (std::max)(nFrom, nTo);
    for (int nRank = nFirst; nRank <= nLast; nRank++)
    {
        Unk_PvPRankEntry* pEntry = (Unk_PvPRankEntry*)reinterpret_cast<Unk_PvPRankService*>(TSingleton<CPVPManager>::GetInstance())->GetRankEntry(nRank);
        if (pEntry == 0)
            continue;
        ASObj obj(2);
        if (!FUN_141344210(&obj, nRank, pEntry))
            continue;
        m_30->Invoke("AddOrUpdateMember", obj.GetValue());
    }
}

// @0x141343da0
void UIPvPResultDialog::SetLastResult(int nRank)
{
    m_180 = nRank;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    CStringW strText(L"");
    if (0 < m_180)
    {
        strText = FormatStringId<CStringW, int>(0x401, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, m_17c), m_180);
        m_30->Invoke("setRewardText", strText);
        MS2Ptr<CItemData> spItem = FUN_14053f870(m_17c);
        if ((CItemData*)spItem != 0)
            m_30->Invoke("setRewardIcon", reinterpret_cast<Unk_PrItemData*>(spItem.operator->())->GetIconPath());
    }
    reinterpret_cast<Unk_RsScript*>(m_30.operator->())->FUN_14129cce0("showLastResult", m_180, strText);
}

// @0x1413440a0
void UIPvPResultDialog::FUN_1413440a0()
{
    PC* pPC = reinterpret_cast<PC*>((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    bool bInPvP = pPC && ((CPvPInfo*)pPC->GetPvPInfo() ? true : false);
    if (bInPvP)
    {
        m_178 = reinterpret_cast<CPvPInfo*>(pPC->GetPvPInfo().operator->())->m_nMode;
        m_17c = reinterpret_cast<CPvPInfo*>(pPC->GetPvPInfo().operator->())->GetRewardItemId();
    }
}

// @0x141344210
bool UIPvPResultDialog::FUN_141344210(ASObj* pObj, int nRank, Unk_PvPRankEntry* pEntry)
{
    if (pEntry == 0)
        return false;
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC == 0)
        return false;
    PCBase* pOther = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(pEntry->m_nCharId));
    CString strIcon("");
    MS2Ptr<CItemData> spItem = FUN_14053f870(m_17c);
    if ((CItemData*)spItem != 0)
        strIcon = reinterpret_cast<Unk_PrItemData*>(spItem.operator->())->GetIconPath();
    pObj->SetIntMember("rank", nRank);
    {
        CStringW strRank(L"-");
        if (pEntry->HasRank() && pEntry->m_bOnline)
            strRank = StringFormat<int>(L"{0}", nRank);
        pObj->SetWStringMember("charName", pEntry->m_strName);
        pObj->SetWStringMember("rankText", strRank);
        pObj->SetIntMember("score", pEntry->m_nScore);
        pObj->SetIntMember("kill", pEntry->m_nKill);
        pObj->SetIntMember("death", pEntry->m_nDeath);
        pObj->FUN_1409c1180("damage", pEntry->m_nDamage);
        pObj->SetBoolMember("isOffline", pEntry->m_bOnline == 0);
        pObj->SetBoolMember("isMe", ((class PCBase*)(class PCBase*)(pPC))->FUN_141656a80() == pEntry->m_nCharId);
        if (pOther)
            pObj->FUN_140bd0d90("job", reinterpret_cast<PC*>(pOther)->GetSubJob());
        else
            pObj->SetIntMember("job", 0);
        int nCount = 0;
        if (pEntry->m_bOnline == 0)
        {
            nCount = 0;
        }
        else if (pEntry->HasRank())
        {
            if (0 < nRank && nRank < 11)
            {
                if (m_178 == 2)
                {
                    nCount = *Client::Constants::GetInstance()->PvpFFARewardCount[nRank - 1].Get();
                    nCount = nCount + *Client::Constants::GetInstance()->PvpFFAAdditionRewardRate.Get() * pEntry->m_nKill;
                }
                else if (m_178 == 5)
                {
                    nCount = *Client::Constants::GetInstance()->PvpOnePunchRewardCount[nRank - 1].Get();
                }
            }
        }
        else
        {
            if (m_178 == 2)
                nCount = *Client::Constants::GetInstance()->PvpFFARewardCount[9].Get();
            else if (m_178 == 5)
                nCount = *Client::Constants::GetInstance()->PvpOnePunchRewardCount[9].Get();
        }
        pObj->SetStringMember("rewardIcon", strIcon);
        pObj->SetIntMember("rewardCount", nCount);
    }
    return true;
}

// @0x141344780
void UIPvPResultDialog::FUN_141344780(int nRank)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    int nCount = reinterpret_cast<Unk_PvPRankService*>(TSingleton<CPVPManager>::GetInstance())->GetRankCount();
    for (int n = 1; n <= nCount; n++)
    {
        Unk_PvPRankEntry* pEntry = (Unk_PvPRankEntry*)reinterpret_cast<Unk_PvPRankService*>(TSingleton<CPVPManager>::GetInstance())->GetRankEntry(n);
        if (pEntry == 0)
            continue;
        ASObj obj(2);
        if (!FUN_141344210(&obj, n, pEntry))
            continue;
        m_30->Invoke("AddOrUpdateMember", obj.GetValue());
    }
    SetLastResult(nRank);
}

// @0x1413448f0
int UIPvPResultDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
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

// @0x141344990
void UIPvPResultDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(1, 0, 150);
}
