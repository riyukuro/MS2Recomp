// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWhisperNotifyDialog: see uiwhispernotifydialog.h.
// MS2-UNIT: ?\uiwhispernotifydialog.cpp
// MS2-RANGE: 0x141b51780-0x141b53fc0 .text$mn
// MS2-RANGE: 0x14011f4c0-0x14011f630 .text$di
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0UIWhisperNotifyDialog@@QEAA@XZ 0x141b51780 ; unique
// MS2-PIN: ??0CNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@_KI@Z 0x141b52ea0 ; unique
// MS2-PIN: ?CreateNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x141b52fd0 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141b53090 ; unique
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEBAIXZ 0x141b531d0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEBAPEAVCNode@12@_KAEAI1AEAPEAV312@@Z 0x141b531e0 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEBA_N_KAEAH@Z 0x141b53430 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x141b53490 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXI@Z 0x141b53790 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x141b539c0 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141b53ad0 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141b53bc0 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAPEAU__POSITION@@_KH@Z 0x141b53c80 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1UIWhisperNotifyDialog@@UEAA@XZ 0x141b52f30
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiwhispernotifydialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiwhispernotifydialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/formatstringid.h"   // C3: FormatStringId<...> wrappers
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/uiugceventdispatcher.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/npcdata.h"  // C3: CNpcData (FUN_1406cd330)

MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// ---- unit-local views of exe objects ----

// The SWF dialog object handed around by the UI library (the exe's dynamic_cast targets).
class ASDialog : public ASDisplayObject
{
};

// The dialog's AS object: the Invoke instantiations this unit owns.
class Unk_WhisperScript : public AScript
{
public:
    // @0x141b52b40
    Scaleform::GFx::Value FUN_141b52b40(const char* szMethod, CString a1, CString a2, CStringW a3);
    // @0x141b52c80
    Scaleform::GFx::Value FUN_141b52c80(const char* szMethod, Scaleform::GFx::Value a1, CStringW a2);
};

// A Constants::Value<int> seen through its Read (the inline COMDAT lives in another unit).
class Unk_SSGConstValue { public: int FUN_140ad5c50(); };

// The UGC info behind CItem::FUN_1405278d0 holds its look at +0x18.
struct Unk_WhisperItemUgc : public CPtred
{
    CUgcItemLook m_look;
};

// The sender record of a system whisper.
struct Unk_WhisperInfo
{
    int m_nId;                                                  // +0x00 sender
    int m_pad_04[3];
    unsigned __int64 m_nTime;                                   // +0x10 when it was sent
};

// The tail of the item data record: its stack size.
struct Unk_WhisperItemData
{
    unsigned char m_pad[0x88];
    unsigned m_nMaxCount;                                       // +0x88
};
MS2_CHECK_OFFSET(Unk_WhisperItemData, m_nMaxCount, 0x88);

MS2Ptr<CNpcData> FUN_1406cd330(int nId);                      // the sender's npc row



CString FUN_141028a90(CString strId, int bDefault);             // the local file of a downloaded image
CString FUN_1410280d0(int nKind, CString strName);
CString FUN_141028be0(__int64 nId, const CString& strName, int bNoDownload, CString strUrl);
MS2Ptr<CItemData> FUN_14053f870(int itemId);
CStringW FUN_1401aa6a0(int nId);                                // the character's name
CStringW FUN_140719a80(unsigned __int64 nUid);                  // the item guid text
CStringW FUN_1416e5900(int nItemId, bool bBold);                // the item name text
void FUN_1412751b0(const CStringW& strText, int nKind);         // shows the text as a notice
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
template <class T> CString Unk_SocketFormat(const char* szFormat, const T& n);

// The item manager: its data source (at +0x10) hands out item data records by id.
class Unk_WhisperItemSource
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual MS2Ptr<CItemData> vfunc_3(int nItemId);
};
struct Unk_WhisperItemMgr
{
    unsigned char m_pad[0x10];
    Unk_WhisperItemSource m_source;
};
void* FUN_140764020();   // C3: was FUN_140764020
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* psz);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value src);

// The exe's wrapper around CItemData lookups: "the item's data record".
// @0x141b52ac0
CString FUN_141b52ac0(unsigned __int64 nId)
{
    CString str;
    str.Format("%I64u", nId);
    return str;
}

// @0x141b52b40
Scaleform::GFx::Value Unk_WhisperScript::FUN_141b52b40(const char* szMethod, CString a1, CString a2, CStringW a3)
{
    ASArgList args;
    args.resize(3);
    FUN_1422bce70(&args[0], (const char*)a1);
    FUN_1422bce70(&args[1], (const char*)a2);
    FUN_1422bcea0(&args[2], (const wchar_t*)a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141b52c80
Scaleform::GFx::Value Unk_WhisperScript::FUN_141b52c80(const char* szMethod, Scaleform::GFx::Value a1, CStringW a2)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bcc70(&args[0], a1);
    FUN_1422bcea0(&args[1], (const wchar_t*)a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141b51780
UIWhisperNotifyDialog::UIWhisperNotifyDialog()
    : m_whisperTimes(17, 0.75f, 0.25f, 2.25f, 10), m_systemTimes(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_nCooldown = reinterpret_cast<Unk_SSGConstValue*>(&static_cast<Client::Constants*>(GetClientConstants())->WisperIgnoreTime)->FUN_140ad5c50();
    FUN_141925e70(0, 1);
}

// @0x141b518b0
CString UIWhisperNotifyDialog::GetTypeName()
{
    return "WhisperNotifyDialog";
}

// @0x141b51900
int UIWhisperNotifyDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    TSingleton<UIUGCEventDispatcher>::GetInstance()->FUN_141b38be0(static_cast<UIUGCEventListener*>(this));
    return 1;
}

// @0x141b51960
void UIWhisperNotifyDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_whisperTimes.RemoveAll();
    TSingleton<UIUGCEventDispatcher>::GetInstance()->FUN_141b38c70(static_cast<UIUGCEventListener*>(this));
}

// @0x141b519d0
void UIWhisperNotifyDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        int nA = static_cast<Client::Constants*>(GetClientConstants())->WisperDurationTime.Read();
        int nB = static_cast<Client::Constants*>(GetClientConstants())->WisperMaxCount.Read();
        pDialog->Invoke("init", nB, nA);
    }
}

// @0x141b51a90
void UIWhisperNotifyDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(3, 0, -60);
}

// @0x141b51b00
int UIWhisperNotifyDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    return 0;
}

// @0x141b51b30
int UIWhisperNotifyDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}

// @0x141b51b80
void UIWhisperNotifyDialog::vfunc_ugc_1(void* pId, CString strPath)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        CString strImage = FUN_141028a90(CString(strPath), 0);
        pDialog->FUN_1413127f0("updateProfileImage", FUN_141b52ac0((unsigned __int64)pId), strImage);
    }
}

// @0x141b51cd0
void UIWhisperNotifyDialog::vfunc_ugc_2(void* pId, CString strName)
{
    if (m_30 == 0)
        return;
    CString strIcon = FUN_1410280d0(0xc9, CString(strName));
    static_cast<Unk_WhisperScript*>(m_30.operator->())->FUN_1413127f0("updateItemIcon", FUN_141b52ac0((unsigned __int64)pId), strIcon);
}

// @0x141b51e30
void UIWhisperNotifyDialog::FUN_141b51e30(unsigned __int64 nId, const CStringW& strMsg, const CString& strName)
{
    if (FUN_1422dc2d0() == 0)
        return;
    if (FUN_141b529f0(nId) != 0)
        return;
    CString strId = FUN_141b52ac0(nId);
    CString strImage = FUN_141028be0(nId, strName, 1, CString(""));
    static_cast<Unk_WhisperScript*>(m_30.operator->())->FUN_141b52b40("addWhisper", strId, strImage, CStringW(strMsg));
    m_whisperTimes.SetAt(nId, GetTickCountMs2());
}

// @0x141b52030
void UIWhisperNotifyDialog::FUN_141b52030(int nItemId, int nGrade, int nCount, const CStringW& strMsg)
{
    if (FUN_1422dc2d0() == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    ASSlot slot(2);
    slot.SetIconPathString(spData->GetIconPath());
    slot.SetItemGrade(nGrade);
    if (1 < reinterpret_cast<Unk_WhisperItemData*>(spData.get())->m_nMaxCount)
        slot.SetItemCountValue(nCount);
    static_cast<Unk_WhisperScript*>(m_30.operator->())->FUN_141b52c80("addGiftItem", slot.FUN_1422bb870(), CStringW(strMsg));
}

// @0x141b52210
void UIWhisperNotifyDialog::FUN_141b52210(MS2Ptr<CItem> spItem, const CStringW& strMsg, const CString& strUgcPath)
{
    if (FUN_1422dc2d0() == 0)
        return;
    if (spItem == 0)
        return;
    ASSlot slot(2);
    {
        CString strName = spItem->FUN_140528590();
        if (!strUgcPath.IsEmpty())
            strName = strUgcPath;
        if (spItem->FUN_140525f60() != 0)
        {
            if (spItem->GetUgcInfo() != 0)
            {
                if (TSingleton<CUgcManager>::GetInstance()->FUN_1418841f0(&reinterpret_cast<Unk_WhisperItemUgc*>(spItem->GetUgcInfo())->m_look, MS2Ptr<CItem>(0), 0) != 0)
                    strName = "";
            }
        }
        slot.SetItemGUID(FUN_140719a80(spItem->GetItemUid()));
        slot.SetIconPathString(strName);
        slot.SetItemGrade(spItem->GetRarity());
        if (1 < spItem->GetSlotMax())
            slot.SetItemCountValue(spItem->GetCount());
        slot.SetUgcTag(spItem->GetUgcTag());
    }
    static_cast<Unk_WhisperScript*>(m_30.operator->())->FUN_141b52c80("addGiftItem", slot.FUN_1422bb870(), CStringW(strMsg));
}

// @0x141b52570
void UIWhisperNotifyDialog::FUN_141b52570(const Unk_WhisperInfo* pInfo, int nMode, int nItemId)
{
    if (FUN_1422dc2d0() == 0)
        return;
    if (pInfo == 0)
        return;
    if (FUN_141b52a60(pInfo->m_nId) != 0)
        return;
    CStringW strText = FormatStringId<CStringW>(0x5eb, FUN_1401aa6a0(pInfo->m_nId));
    TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strText);
    MS2Ptr<CNpcData> sender = FUN_1406cd330(pInfo->m_nId);
    if (!sender)
        return;
    CStringW strExtra(L"");
    if (nMode == 1 && nItemId != 0)
    {
        MS2Ptr<CItemData> spData = (&((struct Unk_WhisperItemMgr*)FUN_140764020())->m_source)->vfunc_3(nItemId);
        if (spData.get() != 0)
        {
            CStringW strName = FUN_1416e5900(nItemId, true);
            strExtra += FormatStringId<CStringW>(0x5ed, strName);
        }
    }
    if (nMode == 1)
        strText += strExtra;
    static_cast<Unk_WhisperScript*>(m_30.operator->())->FUN_141b52b40("addSystemWhisper", Unk_SocketFormat<unsigned int>("{0}", reinterpret_cast<const unsigned int&>(pInfo->m_nId)),
                                                                      sender->m_strPortrait, CStringW(strText));
    m_systemTimes.SetAt(pInfo->m_nId, GetTickCountMs2());
    // CMsTime, not CTime: the exe formats the hour/minute in the server time zone (ctor 0x1406c47a0,
    // GetMinute 0x1406c4f80, GetHour 0x1406c4f10).
    CMsTime time((__time64_t)pInfo->m_nTime);
    int nMinute = time.GetMinute();
    int nHour = time.GetHour();
    CStringW strLog = FormatStringId<int, int, CStringW>(0x5ec, nHour, nMinute, FUN_1401aa6a0(pInfo->m_nId));
    if (nMode == 1)
        strLog += strExtra;
    TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strLog);
    FUN_1412751b0(strLog, 0x14);
}

// @0x141b529f0
int UIWhisperNotifyDialog::FUN_141b529f0(unsigned __int64 nId)
{
    int nTime = 0;
    if (!m_whisperTimes.Lookup(nId, nTime))
        return 0;
    if ((unsigned)(GetTickCountMs2() - nTime) > m_nCooldown)
        return 0;
    return 1;
}

// @0x141b52a60
int UIWhisperNotifyDialog::FUN_141b52a60(int nId)
{
    int nTime = 0;
    if (!m_systemTimes.Lookup(nId, nTime))
        return 0;
    if ((unsigned)(GetTickCountMs2() - nTime) > 60000)
        return 0;
    return 1;
}


// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc34a0-0x142cc3530 .text$yd
