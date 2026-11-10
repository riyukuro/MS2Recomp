// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISmartRecommendBillingDialog and UISmartRecommendNotifyDialog: see
// uismartrecommendbillingdialog.h.
// MS2-UNIT: ?\uismartrecommendbillingdialog.cpp
// MS2-RANGE: 0x14134c9d0-0x14134e450 .text$mn
// MS2-RANGE: 0x1400f0980-0x1400f0a70 .text$di
// MS2-PIN: ??1UISmartRecommendBillingDialog@@UEAA@XZ 0x14134d680
// MS2-PIN: ??_GUISmartRecommendBillingDialog@@UEAAPEAXI@Z 0x14134d720
// MS2-PIN: ??1UISmartRecommendNotifyDialog@@UEAA@XZ 0x14134e3a0
// MS2-PIN: ??_GUISmartRecommendNotifyDialog@@UEAAPEAXI@Z 0x14134e3f0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uismartrecommendbillingdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uismartrecommendbillingdialog.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/bigdatalogsystem.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include "ms2/ms2format.h"

// The header statics of the including TU: the sort type names, then the open sound name.
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strOpenSound = "system_smart_recommend_dialog_open";

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObjectContainer
{
public:
    virtual void vfunc_2(int, int, int);                                    // place the movie
    // @0x14134d4d0
    Scaleform::GFx::Value FUN_14134d4d0(const char* szMethod, int nMode, CString strBagKey, CStringW strName, CStringW strDesc, CStringW strText);
    // @0x14134e200
    Scaleform::GFx::Value FUN_14134e200(const char* szMethod, CString strBagKey, CStringW strDesc, CStringW strTitle, int nTime);
};

// The recommend table: the offer by id.
class Unk_RecommendCache
{
public:
    // @0x14134e430
    static Unk_RecommendCache* FUN_14134e430();
};
class CSmartRecommendShopTable;

class Unk_SrUIMgr
{
public:
    void FUN_141adc530(int nUiId);                              // close
};



class Unk_SrClock;

struct Unk_SrConstUInt { char m_pad_00[0x58]; };
struct Unk_SrConstTable
{
    char m_pad_00[0xce80];
    Unk_SrConstUInt m_closeDelay;                               // +0xce80
};
MS2_CHECK_OFFSET(Unk_SrConstTable, m_closeDelay, 0xce80);
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())

void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* psz);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
UIRewardNotify* FindRewardNotify(int uiType);                      // GetDialog<UIRewardNotify>
CStringW FUN_1409404f0(__int64 nMeso);                          // the meso price text
int FUN_141276180(const CString& strSound, const CString& strArg);
void CreateItemInfoSlot(const CString& strKey, MS2Ptr<CItem> spItem, int a1, int a2, int a3);   // preview the item
void DestroyItemInfoSlot(const CString& strKey);                      // drop the preview
void FUN_140710590(COutPacket& packet);                         // send the packet
void FUN_141275260(int nId, int a, int b);                      // system message
   // has this many of the item
extern Unk_Inventory g_143ab2a90;
extern __int64 DAT_143ab2898;

// @0x14134e430
Unk_RecommendCache* Unk_RecommendCache::FUN_14134e430()
{
    return reinterpret_cast<Unk_RecommendCache*>(TSingleton<CSmartRecommendShopTable>::s_instance);
}

// @0x14134c9d0
UISmartRecommendBillingDialog::UISmartRecommendBillingDialog()
{
    m_2c = 0x1a;
    m_item = 0;
}

// @0x14134ca70
CString UISmartRecommendBillingDialog::GetTypeName()
{
    return "SmartRecommendBillingDialog";
}

// @0x14134cac0
int UISmartRecommendBillingDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x14134caf0
void UISmartRecommendBillingDialog::vfunc_67()
{
    DestroyItemInfoSlot(m_strBagKey);
    UIDialog::vfunc_67();
}

// @0x14134cb30
void UISmartRecommendBillingDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_14134cfa0();
}

// @0x14134cb60
void UISmartRecommendBillingDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(0, 0, 0);
}

// @0x14134cbd0
void UISmartRecommendBillingDialog::vfunc_79(void* p)
{
#define SRB_PKT static_cast<CInPacket*>(p)
    UIDialog::vfunc_79(p);
    if (SRB_PKT->FUN_14070fe80() == 0xa0)
    {
        unsigned nAccepted = SRB_PKT->ReadUInt8();
        if (nAccepted == 1)
        {
            UIRewardNotify* pNotify = FindRewardNotify(0x4e5d);
            if (pNotify != 0)
                pNotify->FUN_141abf6e0(m_item->m_nItemId, m_item->m_nItemRank);
            if (TSingleton<CUIService>::GetInstance()->FUN_141adc940((eUIClassID)0x4e9e) == 0)
                TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e9e);
            UIDialog::vfunc_67();
        }
    }
#undef SRB_PKT
}

// @0x14134ccd0
int UISmartRecommendBillingDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    return 0;
}

// @0x14134cd00
int UISmartRecommendBillingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "OnConfirm") == 0)
    {
        if (!m_item)
            return 0;
        if (m_item->m_nRequireMoney != 0)
        {
            if (DAT_143ab2898 < m_item->m_nRequireMoney)
            {
                FUN_141275260(0x34, 1, 1);
                return 0;
            }
        }
        else
        {
            if (m_item->m_nRequireItemCount != 0)
            {
                if (g_143ab2a90.FUN_140a5ed40(m_item->m_nRequireItemId, m_item->m_nRequireItemRank, m_item->m_nRequireItemCount) == 0)
                {
                    FUN_141275260(0x4b, 1, 1);
                    return 0;
                }
            }
        }
        COutPacket packet(static_cast<int>(SendOp::SmartRecommendBilling), 0);
        packet.WriteUInt8(0);
        packet.WriteInt32(m_item->m_nCode);
        FUN_140710590(packet);
        return 1;
    }
    else if (_stricmp(szMethod, "OnCancel") == 0)
    {
        UIDialog::vfunc_67();
        return 1;
    }
    return 0;
}

// @0x14134cf50
void UISmartRecommendBillingDialog::SetItem(MS2Ptr<CRecommendItem> item)
{
    m_item = item;
}

// @0x14134cfa0
void UISmartRecommendBillingDialog::FUN_14134cfa0()
{
    if (!m_item)
        return;
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
        {
            MS2Ptr<CItem> spItem(new CItem);
            if (spItem->FUN_140523c40(m_item->m_nItemId, m_item->m_nItemRank, 0))
            {
                spItem->SetCountClamped(m_item->m_nItemCount);
                m_strBagKey = GetTypeName();
                CreateItemInfoSlot(m_strBagKey, spItem, 0, 0x415, 0);
                int nMode = m_item->m_nRequireMoney != 0 ? 1 : 2;
                CStringW strText;
                if (nMode == 1)
                {
                    strText = FUN_1409404f0(m_item->m_nRequireMoney);
                }
                else if (nMode == 2)
                {
                    strText.Format(L"%s x%d", (const wchar_t*)TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, m_item->m_nRequireItemId), m_item->m_nRequireItemCount);
                }
                pDialog->FUN_14134d4d0("Open", nMode, m_strBagKey, spItem->FUN_140527b10(), m_item->m_strStoreDescription, strText);
            }
        }
    }
}

// @0x14134d4d0
Scaleform::GFx::Value ASDialog::FUN_14134d4d0(const char* szMethod, int nMode, CString strBagKey, CStringW strName, CStringW strDesc, CStringW strText)
{
    ASArgList args;
    args.resize(5);
    FUN_1422bcd10(&args[0], nMode);
    FUN_1422bce70(&args[1], (const char*)strBagKey);
    FUN_1422bcea0(&args[2], (const wchar_t*)strName);
    FUN_1422bcea0(&args[3], (const wchar_t*)strDesc);
    FUN_1422bcea0(&args[4], (const wchar_t*)strText);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x14134d770
UISmartRecommendNotifyDialog::UISmartRecommendNotifyDialog()
{
    m_2c = 0x19;
    m_item = 0;
    m_nCloseTick = 0;
    FUN_141925e70(0, 1);
}

// @0x14134d830
CString UISmartRecommendNotifyDialog::GetTypeName()
{
    return "SmartRecommendNotifyDialog";
}

// @0x14134d880
int UISmartRecommendNotifyDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x14134d8b0
void UISmartRecommendNotifyDialog::vfunc_67()
{
    DestroyItemInfoSlot(m_strBagKey);
    m_nCloseTick = 0;
    UIDialog::vfunc_67();
}

// @0x14134d8f0
void UISmartRecommendNotifyDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_14134dcc0();
}

// @0x14134d920
void UISmartRecommendNotifyDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(8, 0x28, -70);
}

// @0x14134d9a0
int UISmartRecommendNotifyDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    return 0;
}

// The billing dialog by id.
// @0x14134e160
static UISmartRecommendBillingDialog* FUN_14134e160(int nUiId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (ref.get() != 0)
            return dynamic_cast<UISmartRecommendBillingDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// @0x14134d9d0
int UISmartRecommendNotifyDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "OnBuy") == 0)
    {
        UISmartRecommendBillingDialog* pBilling = FUN_14134e160(0x4e9f);
        if (pBilling != 0)
            pBilling->SetItem(m_item);
        if (TSingleton<CUIService>::GetInstance()->FUN_141adc940((eUIClassID)0x4e9f) == 0)
            TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e9f);
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4e9f)));
        if (m_item.get() != 0)
        {
            CString strValue = Unk_SocketFormat<unsigned int>("{0}", m_item->m_nCode);
            TSingleton<CBigDataLogSystem>::GetInstance()->SendLog("smart_recommend_try", strValue);
        }
        return 1;
    }
    else if (_stricmp(szMethod, "OnCloseComplete") == 0)
    {
        vfunc_67();
        return 1;
    }
    return 0;
}

// @0x14134db90
void UISmartRecommendNotifyDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_nCloseTick != 0)
    {
        if (((class CMainSystem*)(class Unk_SrClock*)(reinterpret_cast<Unk_SrClock*>(TSingleton<CMainSystem>::GetInstance())))->GetServerTick() > m_nCloseTick)
        {
            ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDialog != 0)
                pDialog->Invoke("Close");
            m_nCloseTick = 0;
        }
    }
}

// @0x14134dc50
void UISmartRecommendNotifyDialog::FUN_14134dc50(int nRecommendId)
{
    m_item = reinterpret_cast<CSmartRecommendShopTable*>(Unk_RecommendCache::FUN_14134e430())->FUN_140815890(nRecommendId);
}

// @0x14134dcc0
void UISmartRecommendNotifyDialog::FUN_14134dcc0()
{
    if (!m_item)
        return;
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
        {
            MS2Ptr<CItem> spItem(new CItem);
            if (spItem->FUN_140523c40(m_item->m_nItemId, m_item->m_nItemRank, 0))
            {
                spItem->SetCountClamped(m_item->m_nItemCount);
                m_strBagKey = GetTypeName();
                CreateItemInfoSlot(m_strBagKey, spItem, 0, 0x415, 0);
                pDialog->FUN_14134e200("Open", m_strBagKey, m_item->m_strItemDescription, m_item->m_strBuyButtonText, m_item->m_nNpcImageType);
                FUN_141276180(s_strOpenSound, "");
                m_nCloseTick = ((class CMainSystem*)(class Unk_SrClock*)(reinterpret_cast<Unk_SrClock*>(TSingleton<CMainSystem>::GetInstance())))->GetServerTick() + *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((struct Unk_SrConstTable*)GetClientConstants())->m_closeDelay)->Get();
                if (m_item.get() != 0)
                {
                    CString strValue = Unk_SocketFormat<unsigned int>("{0}", m_item->m_nCode);
                    TSingleton<CBigDataLogSystem>::GetInstance()->SendLog("smart_recommend_open", strValue);
                }
            }
        }
    }
}

// @0x14134e200
Scaleform::GFx::Value ASDialog::FUN_14134e200(const char* szMethod, CString strBagKey, CStringW strDesc, CStringW strTitle, int nTime)
{
    ASArgList args;
    args.resize(4);
    FUN_1422bce70(&args[0], (const char*)strBagKey);
    FUN_1422bcea0(&args[1], (const wchar_t*)strDesc);
    FUN_1422bcea0(&args[2], (const wchar_t*)strTitle);
    FUN_1422bccb0(&args[3], nTime);
    return FUN_1422bb8f0(szMethod, args);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb07f0-0x142cb0840 .text$yd
