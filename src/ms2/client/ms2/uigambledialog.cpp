// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGambleDialog: the gamble / loot box result dialog.
// MS2-UNIT: ?\uigambledialog.cpp
// MS2-RANGE: 0x141935200-0x141935f20 .text$mn
// MS2-PIN: ??1UIGambleDialog@@UEAA@XZ 0x141935d40
// MS2-PIN: ??_GUIGambleDialog@@UEAAPEAXI@Z 0x141935db0
#define MS2_UISWFENTITY_VF15_RET
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigambledialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uigambledialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uitalkcinematic.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uitalkmanager.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types ----

// The root AS object of the gamble movie.
class ASDialog : public ASDisplayObject
{
public:
    Scaleform::GFx::Value FUN_141935bc0(const char* szMethod, CString strBind, unsigned int nSlot, CStringW strName, CString strIcon, int nFlag);   // "bind"
};

// C3: the Unk_GbTalk / Unk_GbReward / Unk_GbItems views were UITalkManager and its CTalkRewardData (m_items +0x18, the
// result item array); FUN_141082d60 is UITalkManager's inline accessor.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

UITalkCinematic* FindTalkCinematic(int nId);

void DestroyItemInfoSlot(const CString& strBindID);                    // release the item bound to the name
void CreateItemInfoSlot(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, int nIconType, int nFlags);
#include "ms2/ms2format.h"
CStringW FUN_1418fec00(int, __int64, bool);          // money text by pay type
int FUN_1403bafd0(int id);
void SetString(Scaleform::GFx::Value* pValue, const char* sz);
void SetUInt(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// @0x141935200
UIGambleDialog::UIGambleDialog()
{
    m_2c = 0xc;
    m_1d8 = 0;
}

// @0x1419352b0
CString UIGambleDialog::GetTypeName()
{
    return CString("GambleDialog");
}

// @0x141935300
int UIGambleDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x141935330
void UIGambleDialog::vfunc_67()
{
    for (size_t i = 0; i < m_binds.GetCount(); i++)
        DestroyItemInfoSlot(m_binds[i]);
    m_binds.RemoveAll();
    UIDialog::vfunc_67();
}

// @0x1419353c0
void UIGambleDialog::vfunc_43()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        UITalkCinematic* pUI = FindTalkCinematic(0x4e40);
        if (pUI != 0)
        {
            int n = pUI->GetLowerCutGlobalY();
            if (n != -1)
            {
                pDlg->vfunc_2(1, 0, n - pDlg->GetHeightCeil());
                return;
            }
        }
    }
    ASDialog* pDlg2 = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg2 != 0)
        pDlg2->vfunc_2(1, 0, 0);
}

// @0x1419354d0
UISwfEntity* UIGambleDialog::vfunc_15() { return this; }

// @0x1419354f0
void UIGambleDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    int cResult;
    if (((CInPacket*)pPacket)->GetOpcode() == 0x9c && (cResult = ((CInPacket*)pPacket)->ReadUInt8()) == 1) {
        for (size_t i = 0; i < m_binds.GetCount(); i++)
            DestroyItemInfoSlot(m_binds[i]);
        m_binds.RemoveAll();
        if (SetResultItems() == 0)
            return;
        ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDlg != 0)
            pDlg->Invoke("OpenBox");
    }
}

// @0x141935660
int UIGambleDialog::vfunc_13() { return 0; }

// @0x141935670
int UIGambleDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "OnResult") == 0) {
        TSingleton<UITalkManager>::GetInstance()->SendNpcTalkMode2(0);
        return 1;
    }
    else if (_stricmp(szMethod, "OnHideComplete") == 0) {
        UIDialog::vfunc_67();
        return 1;
    }
    return 0;
}

// @0x141935710
int UIGambleDialog::SetResultItems()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0) {
        UITalkManager::CTalkRewardData* pReward = TSingleton<UITalkManager>::GetInstance()->FUN_141082d60();
        if (reinterpret_cast<ATL::CAtlArray<MS2Ptr<CItem> >*>(&pReward->m_items)->GetCount() <= 0)
            return 0;
        reinterpret_cast<AScript*>(pDlg)->SetIntMember("m_resultItemCount", reinterpret_cast<ATL::CAtlArray<MS2Ptr<CItem> >*>(&pReward->m_items)->GetCount());
        for (unsigned i = 0; i < reinterpret_cast<ATL::CAtlArray<MS2Ptr<CItem> >*>(&pReward->m_items)->GetCount(); i++) {
            MS2Ptr<CItem> spItem = reinterpret_cast<ATL::CAtlArray<MS2Ptr<CItem> >&>(pReward->m_items)[i];
            if (spItem.IsNull())
                continue;
            CString strBind;
            strBind.Format("%s_%d", (const char*)GetTypeName(), i + 1);
            unsigned nCount = spItem->GetCount();
            CStringW strName = StringFormat<CStringW, unsigned int>(L"{0} X {1}", spItem->FUN_140527b10(), nCount);
            CreateItemInfoSlot(strBind, spItem, i, 0x415, 0);
            int nFlag = 1;
            int nPayType = FUN_1403bafd0(spItem->GetItemId());
            if (nPayType != 0x11) {
                strName = FUN_1418fec00(nPayType, (unsigned)spItem->GetCount(), (bool)0);
                if (!strName.IsEmpty())
                    nFlag = 0;
            }
            pDlg->FUN_141935bc0("bind", strBind, i + 1, strName, spItem->GetIconPath(), nFlag);
            m_binds.Add(strBind);
        }
        reinterpret_cast<UITalkManager::CTalkRewardData*>(pReward)->FUN_141b1dbd0();
        return 1;
    }
    return 0;
}

// @0x141935bc0
inline Scaleform::GFx::Value ASDialog::FUN_141935bc0(const char* szMethod, CString strBind, unsigned int nSlot, CStringW strName, CString strIcon, int nFlag)
{
    ASArgList args;
    args.resize(5);
    SetString(&args[0], strBind);
    SetUInt(&args[1], nSlot);
    FUN_1422bcea0(&args[2], strName);
    SetString(&args[3], strIcon);
    FUN_1422bccb0(&args[4], nFlag);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141935d40 ~UIGambleDialog (implicit: the exe copy stores no vptr)

// @0x141935df0
int UIGambleDialog::vfunc_48()
{
    return 0x4e98;
}
