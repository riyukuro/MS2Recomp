// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDarkStreamResultDialog (class name
// "DarkStreamResultDialog", UI type 0x4ee5, 0x1b8 bytes) is the result window of the DarkStream ranking dungeon. The
// result packet carries five numbers and the reward items; the dialog builds an item bag of them (ItemSlotBag, named
// m_strBagId) and sends everything to the swf as "setResult" (or remembers it until the movie has loaded). The swf
// calls back "OnOut" (close) and "OnViewRanking" (open the ranking UI or the web ranking page).
// MS2-UNIT: ?\uidarkstreamresultdialog.cpp
// MS2-RANGE: 0x140f345b0-0x140f35340 .text$mn
// MS2-PIN: ??_GUIDarkStreamResultDialog@@UEAAPEAXI@Z 0x140f352f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidarkstreamresultdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uidarkstreamresultdialog.h"

#include <atlcoll.h>

#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uiservice.h"  // C3: CUIService::OpenDialog

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

void FUN_140710590(COutPacket&);                                // send
void FUN_14141f970(const CString&);                             // drop an item bag
void FUN_14141f860(const CString&, int, void*, MS2Ptr<ItemSlotBag::CreateParam>);   // news an item bag
MS2Ptr<CItem> FUN_141420330(void*, int);                        // ItemSlotBag::CreateParam::GetItemFn: array element
int FUN_1418fc760(char const*, void*, int, void*);   // C3: was FUN_1418fc760
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CFeatureManager   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14036d570(int);
};
class UIGameRankingDialog* FUN_140b2d030(int);   // C3: was FUN_140b2d030
class UIGameRankingDialog   // C3: member view for the former free stand-ins
{
public:
    void FUN_140e2dfc0(int, int);
};
class UIWebBrowser* FUN_140c43790(int);   // C3: was FUN_140c43790
class UIWebBrowserBase { public: void FUN_14135ec00(const CString& strUrl, bool bFlag); };
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned __int64 n);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);

// @0x140f345b0
UIDarkStreamResultDialog::UIDarkStreamResultDialog()
{
    m_nValue0 = 0;
    m_nValue1 = 0;
    m_nValue2 = 0;
    m_nValue3 = 0;
    m_nValue4 = 0;
    m_bPending = false;
    m_bMode = false;
    m_strRankingUrl = "maview:/rank/darkstream";
    m_strBagId = "DarkStreamResult_Items";
}

// @0x140f346e0
UIDarkStreamResultDialog::~UIDarkStreamResultDialog()
{
}

// @0x140f34760
CString UIDarkStreamResultDialog::GetTypeName()
{
    return "DarkStreamResultDialog";
}
MS2_REPLACE_METHOD(0x140F34760, UIDarkStreamResultDialog, GetTypeName, 61, 0xDAEA3118);

// @0x140f347b0
void UIDarkStreamResultDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_bPending == true)
    {
        FUN_140f34d50();
        m_bPending = false;
    }
    FUN_140f34cb0(m_bMode);
}
MS2_REPLACE_METHOD(0x140F347B0, UIDarkStreamResultDialog, OnLoadComplete, 85, 0xFB604896);

// @0x140f34810
void UIDarkStreamResultDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(0, 0, 0);
}
MS2_REPLACE_METHOD(0x140F34810, UIDarkStreamResultDialog, vfunc_43, 161, 0x6FE03113);

// Closing tells the server (packet 0x6c) and drops the bag.
// @0x140f348c0
void UIDarkStreamResultDialog::vfunc_67()
{
    COutPacket packet(static_cast<int>(SendOp::RequestMoveField), 0);
    packet.WriteUInt8(1);
    FUN_140710590(packet);
    UIDialog::vfunc_67();
    FUN_14141f970(m_strBagId);
}
MS2_REPLACE_METHOD(0x140F348C0, UIDarkStreamResultDialog, vfunc_67, 104, 0xFA27909A);

// @0x140f34930
int UIDarkStreamResultDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)(pArgs), nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnOut", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    else if (_stricmp("OnViewRanking", szMethod) == 0)
    {
        if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x3f) == true)
        {
            void* pRanking = ((void*)FUN_140b2d030(0x4f24));
            if (pRanking != 0)
            {
                ((class UIGameRankingDialog*)(void*)(pRanking))->FUN_140e2dfc0(3, 0);
                (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4f24)));
            }
        }
        else if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x3b) == true)
        {
            void* pPage = ((void*)FUN_140c43790(0x4e6a));
            if (pPage == 0)
                return 1;
            ((class UIWebBrowserBase*)pPage)->FUN_14135ec00(m_strRankingUrl, true);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140F34930, UIDarkStreamResultDialog, vfunc_28, 359, 0xB0C8208F);

// The result packet: five numbers and a byte-counted list of reward items.
// @0x140f34ab0
void UIDarkStreamResultDialog::FUN_140f34ab0(CInPacket& packet)
{
    m_items.clear();
    m_nValue0 = packet.ReadInt32();
    m_nValue1 = packet.ReadInt32();
    m_nValue2 = packet.ReadInt32();
    m_nValue3 = packet.ReadInt32();
    m_nValue4 = packet.ReadInt32();
    int nCount = packet.ReadUInt8();
    for (int i = 0; i < nCount; ++i)
    {
        ItemEntity item;
        item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_items.push_back(item);
    }
    FUN_140f34d50();
}
MS2_REPLACE_METHOD(0x140F34AB0, UIDarkStreamResultDialog, FUN_140f34ab0, 492, 0xA07CE4EF);

// @0x140f34cb0
void UIDarkStreamResultDialog::FUN_140f34cb0(bool bMode)
{
    m_bMode = bMode;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    int nMode = 0;
    if (m_bMode != false)
        nMode = 1;
    m_30.operator->()->Invoke("setMode", nMode);
}
MS2_REPLACE_METHOD(0x140F34CB0, UIDarkStreamResultDialog, FUN_140f34cb0, 144, 0xACAE770B);

// Make a CItem of every reward (the ones the item table accepts), hand them to an item bag and send the whole result
// to the swf; before the movie has loaded just remember that it is pending.
// @0x140f34d50
void UIDarkStreamResultDialog::FUN_140f34d50()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
    {
        m_bPending = true;
        return;
    }
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    for (size_t i = 0; i < m_items.size(); ++i)
    {
        ItemEntity& entity = m_items[i];
        MS2Ptr<CItem> item(new CItem);
        if (item->FUN_14052b130(entity.vfunc_o18_0(), entity.vfunc_o18_1(), 0) != 0)
        {
            item->FUN_14052b340(entity.vfunc_o18_2());
            items.Add(item);
        }
    }
    FUN_14141f970(m_strBagId);
    MS2Ptr<ItemSlotBag::CreateParam> param(new ItemSlotBag::CreateParam);
    param->m_pfnGetItem = FUN_141420330;
    param->m_nIconType = 0xc15;
    param->m_nFlags = 0x800;
    FUN_14141f860(m_strBagId, (int)items.GetCount(), &items, param);
    m_30.operator->()->Invoke("setResult", m_nValue0, m_nValue1, m_nValue2, m_nValue3, m_nValue4, m_strBagId, items.GetCount());
}
MS2_REPLACE_METHOD(0x140F34D50, UIDarkStreamResultDialog, FUN_140f34d50, 1061, 0x2F873CAB);

// @0x140f35180 Invoke(name, 5 ints, string, count): the string is passed by value and destroyed by the callee
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2, int a3, int a4, int a5, CString a6, size_t a7)
{
    ASArgList args;
    args.resize(7);
    FUN_1422bccb0(&args[0], a1);
    FUN_1422bccb0(&args[1], a2);
    FUN_1422bccb0(&args[2], a3);
    FUN_1422bccb0(&args[3], a4);
    FUN_1422bccb0(&args[4], a5);
    FUN_1422bce70(&args[5], (const char*)a6);
    FUN_1422bce00(&args[6], a7);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f35330
int UIDarkStreamResultDialog::vfunc_48()
{
    return 0x4ee5;
}
