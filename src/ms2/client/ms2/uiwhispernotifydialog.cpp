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
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// ---- unit-local views of exe objects ----

// The SWF dialog object handed around by the UI library (the exe's dynamic_cast targets).
class ASDialog : public ASDisplayObject
{
public:
    Scaleform::GFx::Value FUN_1413127f0(const char* szMethod, CString a1, CString a2);
};

// The dialog's AS object: the Invoke instantiations this unit owns.
class Unk_WhisperScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_1413127f0(const char* szMethod, CString a1, CString a2);
    // @0x141b52b40
    Scaleform::GFx::Value FUN_141b52b40(const char* szMethod, CString a1, CString a2, CStringW a3);
    // @0x141b52c80
    Scaleform::GFx::Value FUN_141b52c80(const char* szMethod, Scaleform::GFx::Value a1, CStringW a2);
};

// A Constants::Value<int> seen through its Read (the inline COMDAT lives in another unit).
class Unk_WhisperConstValue { public: int FUN_140536a30(); int FUN_140ad5c50(); };

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

// The sender of a system whisper (the friend / party record).
class Unk_WhisperSender : public CPtred
{
public:
    unsigned char m_pad_18[0x78];
    CString m_strImage;                                         // +0x90 the sender's profile image
};
MS2_CHECK_OFFSET(Unk_WhisperSender, m_strImage, 0x90);
class Unk_WhisperSenderPtr
{
public:
    Unk_WhisperSenderPtr();                                     // user-provided: hidden return pointer ABI
    bool FUN_14035e9b0();                                       // is empty
    Unk_WhisperSender* FUN_14035eb90();                         // operator->
    void FUN_14035e5b0();                                       // release
    void* m_unk_00;
    Unk_WhisperSender* m_p;                                     // +0x08
};
Unk_WhisperSenderPtr FUN_1406cd330(int nId);

class Unk_WhisperTextFilter
{
public:
    void FUN_1416fb340(CStringW& str);                          // 0x1416fb340 system text
};
Unk_WhisperTextFilter* FUN_1403b4750();

class Unk_UgcEvents { public: void FUN_141b38be0(UIUGCEventListener* p); void FUN_141b38c70(UIUGCEventListener* p); };
Unk_UgcEvents* FUN_140bc09f0();

CString FUN_141028a90(CString strId, int bDefault);             // the local file of a downloaded image
CString FUN_1410280d0(int nKind, CString strName);
CString FUN_141028be0(__int64 nId, const CString& strName, int bNoDownload, CString strUrl);
CUgcManager* FUN_14052d220();
MS2Ptr<CItemData> FUN_14053f870(int itemId);
CStringW FUN_1401aa6a0(int nId);                                // the character's name
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);  // string table text with one argument
CStringW FUN_140292b10(int nStringId, const int& nHour, const int& nMinute, const CStringW& strName);   // string table text with three arguments
CStringW FUN_140719a80(unsigned __int64 nUid);                  // the item guid text
CStringW FUN_1416e5900(int nItemId, int nBold);                 // the item name text
void FUN_1412751b0(const CStringW& strText, int nKind);         // shows the text as a notice
int FUN_140869420();                                            // the server time in seconds
CString FUN_140513200(const char* szFormat, const int& nArg);

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
Unk_WhisperItemMgr* FUN_140764020();
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
    args.FUN_1409b2800(3);
    FUN_1422bce70(args.FUN_1409b1f70(0), (const char*)a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), (const char*)a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), (const wchar_t*)a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141b52c80
Scaleform::GFx::Value Unk_WhisperScript::FUN_141b52c80(const char* szMethod, Scaleform::GFx::Value a1, CStringW a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), (const wchar_t*)a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141b51780
UIWhisperNotifyDialog::UIWhisperNotifyDialog()
    : m_whisperTimes(17, 0.75f, 0.25f, 2.25f, 10), m_systemTimes(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_nCooldown = reinterpret_cast<Unk_WhisperConstValue*>(&static_cast<Client::Constants*>(FUN_1401d3200())->WisperIgnoreTime)->FUN_140ad5c50();
    FUN_141925e70(0, 1);
}

// @0x141b518b0
CString UIWhisperNotifyDialog::vfunc_1()
{
    return "WhisperNotifyDialog";
}

// @0x141b51900
int UIWhisperNotifyDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    FUN_140bc09f0()->FUN_141b38be0(static_cast<UIUGCEventListener*>(this));
    return 1;
}

// @0x141b51960
void UIWhisperNotifyDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_whisperTimes.RemoveAll();
    FUN_140bc09f0()->FUN_141b38c70(static_cast<UIUGCEventListener*>(this));
}

// @0x141b519d0
void UIWhisperNotifyDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        int nA = reinterpret_cast<Unk_WhisperConstValue*>(&static_cast<Client::Constants*>(FUN_1401d3200())->WisperDurationTime)->FUN_140536a30();
        int nB = reinterpret_cast<Unk_WhisperConstValue*>(&static_cast<Client::Constants*>(FUN_1401d3200())->WisperMaxCount)->FUN_140536a30();
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
    m_whisperTimes.SetAt(nId, FUN_140869420());
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
    slot.FUN_1409c2750(spData->FUN_14053fdd0());
    slot.FUN_1409c23e0(nGrade);
    if (1 < reinterpret_cast<Unk_WhisperItemData*>(spData.get())->m_nMaxCount)
        slot.FUN_1409c2190(nCount);
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
            if (spItem->FUN_1405278d0() != 0)
            {
                if (FUN_14052d220()->FUN_1418841f0(&reinterpret_cast<Unk_WhisperItemUgc*>(spItem->FUN_1405278d0())->m_look, MS2Ptr<CItem>(0), 0) != 0)
                    strName = "";
            }
        }
        slot.FUN_1409c28f0(FUN_140719a80(spItem->FUN_140526a50()));
        slot.FUN_1409c2750(strName);
        slot.FUN_1409c23e0(spItem->FUN_140526bd0());
        if (1 < spItem->FUN_1405281e0())
            slot.FUN_1409c2190(spItem->FUN_140526c50());
        slot.FUN_1409c2950(spItem->FUN_140528840());
    }
    static_cast<Unk_WhisperScript*>(m_30.operator->())->FUN_141b52c80("addGiftItem", slot.FUN_1422bb870(), CStringW(strMsg));
}

// @0x141b52570
// MS2-FUNCTIONAL: frame 0x10 smaller in the exe (one more EH state, 24 ip2state entries); temporaries not matched
void UIWhisperNotifyDialog::FUN_141b52570(const Unk_WhisperInfo* pInfo, int nMode, int nItemId)
{
    if (FUN_1422dc2d0() == 0)
        return;
    if (pInfo == 0)
        return;
    if (FUN_141b52a60(pInfo->m_nId) != 0)
        return;
    CStringW strText = FUN_14052bd00(0x5eb, FUN_1401aa6a0(pInfo->m_nId));
    FUN_1403b4750()->FUN_1416fb340(strText);
    Unk_WhisperSenderPtr sender = FUN_1406cd330(pInfo->m_nId);
    if (sender.FUN_14035e9b0())
        return;
    CStringW strExtra(L"");
    if (nMode == 1 && nItemId != 0)
    {
        MS2Ptr<CItemData> spData = (&FUN_140764020()->m_source)->vfunc_3(nItemId);
        if (spData.get() != 0)
            strExtra += FUN_14052bd00(0x5ed, FUN_1416e5900(nItemId, 1));
    }
    if (nMode == 1)
        strText += strExtra;
    static_cast<Unk_WhisperScript*>(m_30.operator->())->FUN_141b52b40("addSystemWhisper", FUN_140513200("{0}", pInfo->m_nId),
                                                                      sender.FUN_14035eb90()->m_strImage, CStringW(strText));
    m_systemTimes.SetAt(pInfo->m_nId, FUN_140869420());
    CTime time((__time64_t)pInfo->m_nTime);
    int nMinute = time.GetMinute();
    int nHour = time.GetHour();
    CStringW strLog = FUN_140292b10(0x5ec, nHour, nMinute, FUN_1401aa6a0(pInfo->m_nId));
    if (nMode == 1)
        strLog += strExtra;
    FUN_1403b4750()->FUN_1416fb340(strLog);
    FUN_1412751b0(strLog, 0x14);
    sender.FUN_14035e5b0();
}

// @0x141b529f0
int UIWhisperNotifyDialog::FUN_141b529f0(unsigned __int64 nId)
{
    int nTime = 0;
    if (!m_whisperTimes.Lookup(nId, nTime))
        return 0;
    if ((unsigned)(FUN_140869420() - nTime) > m_nCooldown)
        return 0;
    return 1;
}

// @0x141b52a60
int UIWhisperNotifyDialog::FUN_141b52a60(int nId)
{
    int nTime = 0;
    if (!m_systemTimes.Lookup(nId, nTime))
        return 0;
    if ((unsigned)(FUN_140869420() - nTime) > 60000)
        return 0;
    return 1;
}


// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc34a0-0x142cc3530 .text$yd
