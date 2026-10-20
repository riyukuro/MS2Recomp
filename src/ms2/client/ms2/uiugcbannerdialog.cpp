// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUGCBannerDialog / UIUGCCameraDialog: see uiugcbannerdialog.h.
// MS2-UNIT: ?\uiugcbannerdialog.cpp
// MS2-RANGE: 0x14011e8b0-0x14011eac0 .text$di
// MS2-RANGE: 0x141b34100-0x141b39900 .text$mn
// MS2-RANGE: 0x142cc2fd0-0x142cc3090 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetCount@?$CRBTree@H_NV?$CElementTraits@H@ATL@@V?$CElementTraits@_N@2@@ATL@@QEBA_KXZ 0x141b36f20 ; unique
// MS2-PIN: ?vfunc_48@UIUGCBannerDialog@@UEAAHXZ 0x141b36f30 ; unique
// MS2-PIN: ??_GUIUGCCameraDialog@@UEAAPEAXI@Z 0x141b38990 ; unique
// MS2-PIN: ?vfunc_48@UIUGCCameraDialog@@UEAAHXZ 0x141b389d0 ; unique
// MS2-PIN: memmove_s 0x141b389e0 ; unique
// MS2-PIN: ??0?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x141b39140 ; unique
// MS2-PIN: ??1?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x141b391b0 ; unique
// MS2-PIN: ?CallConstructors@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@CAXPEAPEAX_K@Z 0x141b39380 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@CAXPEAPEAX_K@Z 0x141b393f0 ; unique
// MS2-PIN: ??A?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAAEAPEAX_K@Z 0x141b39430 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@AEAA_N_K@Z 0x141b39480 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@PEAX@ATL@@SAXPEAPEAX0_K@Z 0x141b39620 ; unique
// MS2-PIN: ?Add@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA_KPEAX@Z 0x141b392d0
// MS2-PIN: ?RemoveAll@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAXXZ 0x141b39660 ; unique
// MS2-PIN: ?RemoveAt@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAX_K0@Z 0x141b39680 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA_N_KH@Z 0x141b39770 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it). The unit also holds the bodies of
// UIUGCEventListener and UIUGCEventDispatcher (placeholders), which the exe links in the same obj.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugcbannerdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiugcbannerdialog.h"
#include "uiugcimageuploaddialog.h"
#include "uimessagebox.h"
#include "uiservice.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cugcuploadctrl.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/uiugceventdispatcher.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ugcmanager.h"
#include "networkservice.h"
#include "ms2/unnamed/unit_1401b6d10.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <NiRect.h>

MS2_EMIT_CRT_MEMMOVE_S();

static CString s_sortA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_sortB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strProfileTakePhoto = "profile_take_photo";
static CString s_strPCTakePhoto = "PC_take_photo";

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject {};

// The status-listener registry (singleton 0x140aa6d40).
class Unk_UiStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);       // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);       // unregister
};
Unk_UiStatusMgr* FUN_140aa6d40();

// The movie root of the dialog: Invoke of a method with an int and an AS array (inline COMDAT 0x141b36aa0 / 0x141b36b60).
class Unk_UgcScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_141b36aa0(const char* szMethod, int n, ASArray& arr);
    Scaleform::GFx::Value FUN_141b36b60(const char* szMethod, int n, ASArray& arr, int nA, int nB);
};

// A row of the file list: its members as text.
class Unk_UgcImageData : public AScript
{
public:
    CStringW FUN_1422bb2b0(const char* szName);                 // a member as text
};

class Unk_UiScale { public: float FUN_141adbe70(); };            // the UI scale of the UI manager

// The title label of the dialog (a text field child of the movie).
class Unk_WcTitle : public ASDisplayObject { public: void FUN_1422e4b80(const CStringW& str); };
// MS2Ptr<Unk_WcTitle> members and the AScript child binder are COMDATs of another unit (declared only).
template <> MS2Ptr<Unk_WcTitle>::MS2Ptr();
template <> MS2Ptr<Unk_WcTitle>::~MS2Ptr();
template <> MS2Ptr<Unk_WcTitle>& MS2Ptr<Unk_WcTitle>::operator=(int);
template <> template <> MS2Ptr<Unk_WcTitle>& MS2Ptr<Unk_WcTitle>::operator=<Unk_WcTitle>(const MS2Ptr<Unk_WcTitle>&);
class Unk_WcTitleFinder { public: MS2Ptr<Unk_WcTitle> FUN_140c436d0(const CString&); };

// The purchase block notice (the state manager answers whether the action is blocked right now).
struct Unk_BnBlockRef;
void FUN_1401cb250(Unk_BnBlockRef*);
struct Unk_BnBlockRef
{
    void* m_00;
    void* m_08;
    ~Unk_BnBlockRef() { FUN_1401cb250(this); }
};
MS2_CHECK_SIZE(Unk_BnBlockRef, 0x10);
class Unk_BnStateMgr;
Unk_BnStateMgr* FUN_140a6a830();
void FUN_140a2f620(Unk_BnStateMgr* pMgr, Unk_BnBlockRef* pOut, int nKind);
void* FUN_1401cb3d0(Unk_BnBlockRef* pRef);
void FUN_140a2ff20(Unk_BnBlockRef* pRef, int nKind, __int64 n);

class Unk_GalleryAS;
void GallerySet(Scaleform::GFx::Value*, int);
void GallerySet(Scaleform::GFx::Value*, const Unk_GalleryAS&);

CUgcManager* FUN_14052d220();
CUIService* FUN_1403ed2b0();
template <class T> T* UgcFindDialog(eUIClassID nId);
bool FUN_140a467d0(const MS2Ptr<AScript>* pScript);             // the movie root is not loaded
bool FUN_140ba28d0(const MS2Ptr<AScript>* pScript, int n);      // the movie root is null
void FUN_14151f200();
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);     // str == sz
bool FUN_140d74e80(CStringW& tag);                              // a "terms" message box tag answered with yes
void FUN_140d74640(void* p, int nBit, int nIdA, int nIdB);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
bool FUN_140184310(const CString& str, const char* psz);        // str == psz
bool FUN_1409b0350(Scaleform::GFx::Value* pValue);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);        // set an Int value
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);   // a formatted table string
CStringW FUN_1418fec00(int nPayType, __int64 nAmount, int nFlag);   // a price as text
bool FUN_1418ff110(int nPayType, __int64 nAmount, int nFlag);    // the player can pay
void FUN_141276180(const CString& strName, const CString& strArg);
CStringW FUN_141026920(int nKind);
CStringW FUN_141028910(int nKind);
Unk_UgcFileResult SaveUgcThumbnailImage(NiRect<unsigned int> kRect, int nTarget);
__int64 FUN_140869440();                                        // the server time
int FUN_140869420();                                            // the tick count
bool FUN_1406c5200();                                           // CMsTime::IsTimeZoneSet
Unk_DateParts* FUN_14088dfa0(Unk_DateParts* pOut, __int64 nTime, int nHourOffset);
Unk_DateParts* FUN_14088dff0(Unk_DateParts* pOut, const Unk_DateParts* pIn, int nHourOffset);
void FUN_14088e0f0(Unk_DateParts* pOut, const Unk_DateParts* pIn, int nHourOffset);
void FUN_14088e140(Unk_DateParts* pDate, __int64 nTime);

// The CUgcManager takes the picked hours as CRBMap<int, int> and the day as a record of its own (ugcmanager.cpp#4).
struct Unk_BannerDay { int m_0; int m_4; int m_nDate; };

// @0x141b36aa0
inline Scaleform::GFx::Value Unk_UgcScript::FUN_141b36aa0(const char* szMethod, int n, ASArray& arr)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    GallerySet(args.FUN_1409b1f70(0), n);
    GallerySet(args.FUN_1409b1f70(1), (const Unk_GalleryAS&)arr);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141b36b60
inline Scaleform::GFx::Value Unk_UgcScript::FUN_141b36b60(const char* szMethod, int n, ASArray& arr, int nA, int nB)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    GallerySet(args.FUN_1409b1f70(0), n);
    GallerySet(args.FUN_1409b1f70(1), (const Unk_GalleryAS&)arr);
    GallerySet(args.FUN_1409b1f70(2), nA);
    GallerySet(args.FUN_1409b1f70(3), nB);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x14011e8b0 (dynamic initializer of s_sortA)
// @0x14011e970 (dynamic initializer of s_keyInput)
// @0x14011e9a0 (dynamic initializer of s_sortB)
// @0x14011ea60 (dynamic initializer of s_strProfileTakePhoto)
// @0x14011ea90 (dynamic initializer of s_strPCTakePhoto)

// @0x141b34100
UIUGCBannerDialog::UIUGCBannerDialog()
    : m_188(0)
    , m_1f0((FUN_14088dfa0(&m_190, 0, 0), FUN_14088dfa0(&m_1c0, 0, 0), -1))
    , m_1f4(0)
    , m_228(0)
    , m_22c(0)
{
    FUN_141924170(1);
    m_230 = FUN_1401d3200()->UgcBannerCheckTime.Read();
}

// @0x141b34270
UIUGCBannerDialog::~UIUGCBannerDialog()
{
}

// @0x141b34320
CString UIUGCBannerDialog::vfunc_1()
{
    return CString("UGCBannerDialog");
}

// @0x141b34370
int UIUGCBannerDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    UIUGCEventDispatcher::GetInstance()->FUN_141b38be0(static_cast<UIUGCEventListener*>(this));
    return 1;
}

// @0x141b34410
void UIUGCBannerDialog::vfunc_67()
{
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    UIUGCEventDispatcher::GetInstance()->FUN_141b38c70(static_cast<UIUGCEventListener*>(this));
    UIDialog::vfunc_67();
    FUN_14052d220()->FUN_141880ec0(vfunc_48());
    m_188 = 0;
    m_1f8.RemoveAll();
    m_228 = 0;
    m_1f0 = -1;
    m_22c = 0;
}

// @0x141b34520
void UIUGCBannerDialog::vfunc_72()
{
    bool bChanged;
    int nTick = FUN_140869420();
    if (m_228 == 0)
        m_228 = nTick;
    if ((unsigned int)(nTick - m_228) >= 500 && FUN_1406c5200())
    {
        Unk_DateParts now;
        FUN_14088dfa0(&now, FUN_140869440(), 0);
        if (now.m_hour != m_1f0)
        {
            m_1f0 = now.m_hour;
            Unk_DateParts shifted;
            FUN_14088dff0(&shifted, &m_190, m_230);
            bChanged = false;
            if (shifted.m_date == m_1c0.m_date)
                bChanged = true;
            if (FUN_14052d220() != 0)
            {
                if (FUN_14052d220()->FUN_141888dc0())
                {
                    bChanged = true;
                    FUN_14052d220()->FUN_141888da0(false);
                }
            }
            if (bChanged == true)
                FUN_141b359b0();
        }
    }
    if (m_22c != 0)
    {
        FUN_141b363b0();
        m_22c = 0;
    }
}

// @0x141b346a0
void UIUGCBannerDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    MS2Ptr<CUgcUploadCtrl> spUpload = FUN_14052d220()->FUN_141882610();
    if (spUpload == 0)
    {
        vfunc_67();
        return;
    }
    if (spUpload->FUN_1418a3ad0() == vfunc_48())
    {
        if (spUpload->m_nKind == 3)
        {
            if (FUN_141b357e0() == 0)
                vfunc_67();
            else
            {
                FUN_14088e140(&m_190, FUN_140869440());
                FUN_14088e140(&m_1c0, FUN_140869440());
                if (m_230 < 0x18)
                    m_1f4 = 0;
                else
                    m_1f4 = 1;
            }
        }
        else
            vfunc_67();
    }
    else
        vfunc_67();
}

// @0x141b34850
void UIUGCBannerDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141b358d0();
    FUN_141b359b0();
    FUN_141b365e0();
    FUN_141b35b80();
    FUN_141b36750(0);
    FUN_140d86260()->vfunc_43(0xe, 0, 1000);
}

// @0x141b348d0
void UIUGCBannerDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_238 = 0;
}

// @0x141b34910
int UIUGCBannerDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (nResult == 0)
        {
            if (FUN_140d74e80(strTag) == 0)
            {
                if (FUN_1403b3c40(strTag, L"noexist"))
                {
                    FUN_141b358d0();
                    FUN_141b364a0(-1);
                    MS2Ptr<CUgcUploadCtrl> spUpload = FUN_14052d220()->FUN_141882610();
                    if (spUpload.get() != 0)
                    {
                        if (spUpload->m_spViewer.get() != 0)
                            spUpload->m_spViewer->vfunc_4();
                    }
                }
            }
            else
                FUN_14052d220()->FUN_141883400(reinterpret_cast<ATL::CRBMap<int, int>&>(m_1f8),
                                               reinterpret_cast<const Unk_BannerDay&>(m_1c0));
            FUN_14151f200();
            return 1;
        }
        FUN_14151f200();
    }
    return 0;
}

// @0x141b34b60
int UIUGCBannerDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnOpenFolder", szMethod) == 0)
    {
        FUN_141b35cd0();
        return 1;
    }
    if (_stricmp("OnPreview", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141b35d00(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnUpload", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141b35e10(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnNewDraw", szMethod) == 0)
    {
        FUN_141b36080();
        return 1;
    }
    if (_stricmp("OnAddImage", szMethod) == 0)
    {
        FUN_141b360c0();
        return 1;
    }
    if (_stricmp("onScrollPosition", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nIndex = data.FUN_1422b8a10();
            if (nIndex > -1)
                FUN_141b36140(nIndex);
        }
        return 1;
    }
    if (_stricmp("onScrollPositionReserve", szMethod) == 0)
    {
        FUN_141b359b0();
        return 1;
    }
    if (_stricmp("OnTimeReserve", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nHour = data.FUN_1422b8a10();
            if (nHour > -1)
                FUN_141b36230(nHour, data.FUN_1422b8a90() != 0);
        }
        return 1;
    }
    if (_stricmp("OnDateOffset", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141b362b0(data.FUN_1422b8a10());
        return 1;
    }
    if (_stricmp("OnItemDoubleClick", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nIndex = data.FUN_1422b8a10();
            if (nIndex == -1)
            {
                FUN_140d73bc0(0x2e0, 0, 0, CStringW(L""));
                return 1;
            }
            FUN_14052d220()->FUN_141882a70(nIndex, 1);
        }
        return 1;
    }
    return 0;
}

// @0x141b35070
void UIUGCBannerDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    CString strType = pArgs->FUN_1422b8d30();
    if (!FUN_140184310(strType, "image"))
    {
        if (strType.Find("m_timeSlot", 0) != -1)
        {
            int nHour = atoi(strType.Mid(10));
            Unk_BannerPtr banner = CFieldBannerData::GetBanner(m_188);
            if (banner == 0)
                return;
            if (nHour < 0 || nHour > 0x17)
                return;
            __int64 nPrice = banner->GetHourly(nHour);
            CStringW strPrice = FUN_1418fec00(FUN_141b36a60(), nPrice, 0);
            CStringW strText = FUN_14052bd00(0x9b6, strPrice);
            ASTooltip tip(1, 2);
            if (tip.FUN_1409e26b0(strText) != 0)
                *pRetVal = tip.FUN_1422bb870();
        }
    }
    else
    {
        Scaleform::GFx::Value arg = pArgs->FUN_1422b9260();
        AScript root((const Scaleform::GFx::Value&)arg, 2);
        if (root.FUN_1422ba9a0() == 0)
        {
            AScript data(root.FUN_1422baa20("data"), 2);
            if (data.FUN_1422ba9a0() == 0)
            {
                ASTooltip tip(1, 2);
                CStringW strText = ((Unk_UgcImageData*)&data)->FUN_1422bb2b0("tooltip");
                if (tip.FUN_1409e26b0(strText) != 0)
                {
                    tip.FUN_1409c6dc0(2);
                    tip.FUN_1409c6e60(-4);
                    tip.FUN_1409c6e90(1);
                    *pRetVal = tip.FUN_1422bb870();
                }
            }
        }
    }
}

// @0x141b35420
void UIUGCBannerDialog::vfunc_ugc_4(int nDialog)
{
    if (vfunc_48() != nDialog)
        return;
    m_22c = 1;
}

// @0x141b35480
void UIUGCBannerDialog::FUN_141b35480(int nResult)
{
    if (nResult == 0)
        FUN_140d73bc0(0x468, 0, 0, CStringW(L""));
    else
    {
        CStringW strText = FUN_14052d220()->FUN_14187f210(nResult);
        if (!strText.IsEmpty())
            FUN_1412751f0(strText, 1, 1);
    }
    vfunc_67();
}

// @0x141b35540
int UIUGCBannerDialog::FUN_141b35540(MS2Ptr<CUgcPreReserve> spReserve)
{
    if (spReserve->m_nCount != m_188)
        return 0x2a;
    if (spReserve->m_reserves.GetCount() != m_1f8.GetCount())
        return 0x2b;
    MS2Ptr<CUgcUploadCtrl> spUpload = FUN_14052d220()->FUN_141882610();
    if (spUpload == 0)
        return 0xd;
    if (spUpload->m_nKind != 3)
        return 0x5b;
    IUgcViewer* pViewer = spUpload->m_spViewer.get();
    if (pViewer == 0)
        return 0x11;
    for (POSITION pos = spReserve->m_reserves.GetHeadPosition(); pos != 0; spReserve->m_reserves.GetNext(pos))
    {
        MS2Ptr<CUgcBannerReserve> spBanner = spReserve->m_reserves.GetValueAt(pos);
        if (spBanner.get() != 0)
            reinterpret_cast<CUgcBannerPost*>(reinterpret_cast<char*>(pViewer) + 0x18)->m_reserves.SetAt(spBanner->GetKey(), spBanner);
    }
    m_1f8.RemoveAll();
    FUN_14052d220()->FUN_141882020();
    return 0;
}

// @0x141b357e0
int UIUGCBannerDialog::FUN_141b357e0()
{
    MS2Ptr<CUgcUploadCtrl> spUpload = FUN_14052d220()->FUN_141882610();
    if (spUpload == 0)
        return 0;
    if (spUpload->m_nKind != 3)
        return 0;
    IUgcViewer* pViewer = spUpload->m_spViewer.get();
    if (pViewer == 0)
        return 0;
    m_188 = static_cast<CUgcViewerBanner*>(pViewer)->m_post.m_nBannerId;
    return 1;
}

// @0x141b358d0
void UIUGCBannerDialog::FUN_141b358d0()
{
    if (FUN_140a467d0(&m_30) == 0)
    {
        FUN_14052d220()->FUN_141889ce0(3);
        ASArray arr(2);
        FUN_14052d220()->FUN_141889e20(0x10, 0, &arr);
        int nCount = FUN_14052d220()->FUN_14188a480();
        ((Unk_UgcScript*)m_30.operator->())->FUN_141b36aa0("buildUGCFiles", nCount, arr);
    }
}

// @0x141b359b0
void UIUGCBannerDialog::FUN_141b359b0()
{
    if (FUN_140a467d0(&m_30) == 0)
    {
        FUN_14088e0f0(&m_1c0, &m_190, m_1f4 * 0x18 + m_230);
        ASArray arr(2);
        FUN_14052d220()->FUN_141888de0(m_188, reinterpret_cast<const Unk_BannerDay&>(m_1c0),
                                       reinterpret_cast<ATL::CRBMap<int, int>&>(m_1f8), &arr);
        int nBit = m_230 < 0x18 ? 2 : 3;
        ((Unk_UgcScript*)m_30.operator->())->FUN_141b36b60("buildTimeReserve", m_1f4, arr, m_230 > 0x17, nBit);
    }
}

// @0x141b35b80
void UIUGCBannerDialog::FUN_141b35b80()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        CStringW strDir = FUN_141026920(3);
        wchar_t szFull[260] = {0};
        _wfullpath(szFull, strDir, 260);
        CStringW strFull(szFull);
        pDialog->Invoke("setFolder", strFull);
    }
}

// @0x141b35cd0
void UIUGCBannerDialog::FUN_141b35cd0()
{
    FUN_14052d220()->FUN_1418829b0(3);
}

// @0x141b35d00
int UIUGCBannerDialog::FUN_141b35d00(int nIndex)
{
    if (nIndex == -1)
    {
        FUN_140d73bc0(0x2e0, 0, 0, CStringW(L""));
        return 0;
    }
    if (FUN_14052d220()->FUN_141881a40(nIndex) == 0)
    {
        FUN_140d73bc0(0x2e2, 0, static_cast<IMessageListener*>(this), CStringW(L"noexist"));
        return 0;
    }
    if (FUN_14052d220()->FUN_141881800(3, nIndex) == 0)
    {
        FUN_141275260(0x2e1, 1, 1);
        return 0;
    }
    return 1;
}

// @0x141b35e10
int UIUGCBannerDialog::FUN_141b35e10(int nIndex)
{
    Unk_BnBlockRef block;
    FUN_140a2f620(FUN_140a6a830(), &block, 5);
    if (FUN_1401cb3d0(&block) != 0)
    {
        FUN_140a2ff20(&block, 5, (__int64)static_cast<IMessageListener*>(this));
        return 0;
    }
    if (nIndex == -1)
    {
        FUN_140d73bc0(0x2e0, 0, 0, CStringW(L""));
        return 0;
    }
    if (m_1f8.GetCount() == 0)
    {
        FUN_140d73bc0(0x2e4, 0, 0, CStringW(L""));
        return 0;
    }
    if (!FUN_1418ff110(FUN_141b36a60(), FUN_141b368b0(), 1))
        return 0;
    if (FUN_14052d220()->FUN_141881890(nIndex) == 0)
    {
        FUN_140d73bc0(0x2e2, 0, static_cast<IMessageListener*>(this), CStringW(L"noexist"));
        return 0;
    }
    FUN_140d74640(static_cast<IMessageListener*>(this), 1, 0x9d4, 0x9cf);
    return 1;
}

// @0x141b36080
int UIUGCBannerDialog::FUN_141b36080()
{
    if (FUN_14052d220()->FUN_141880fc0() == 0)
        return 0;
    FUN_141b358d0();
    return 1;
}

// @0x141b360c0
int UIUGCBannerDialog::FUN_141b360c0()
{
    CStringW strDir(L"./");
    int nResult = FUN_14052d220()->FUN_1418810c0(strDir, L"Image Files (*.dds, *.png, *.jpg)");
    if (nResult == 0)
        return 0;
    FUN_141b358d0();
    FUN_141b364a0(0);
    return 1;
}

// @0x141b36140
int UIUGCBannerDialog::FUN_141b36140(int nIndex)
{
    if (nIndex == -1)
        return 0;
    if (FUN_140a467d0(&m_30) != 0)
        return 0;
    int nPos = nIndex << 2;
    ASArray arr(2);
    FUN_14052d220()->FUN_141889e20(0x10, nPos, &arr);
    ((Unk_UgcScript*)m_30.operator->())->FUN_141b36aa0("buildScrollPosition", nPos, arr);
    return 1;
}

// @0x141b36230
int UIUGCBannerDialog::FUN_141b36230(int nHour, bool bPicked)
{
    if (!bPicked)
        m_1f8.RemoveKey(nHour);
    else
        m_1f8.SetAt(nHour, bPicked);
    FUN_141b366b0();
    FUN_141b369d0();
    return 1;
}

// @0x141b362b0
int UIUGCBannerDialog::FUN_141b362b0(int nOffset)
{
    int nDay = m_1f4 + nOffset;
    int nLow = m_230 >= 0x18;
    int nHigh = m_230 < 0x18 ? 2 : 3;
    if (nDay <= nLow)
        nDay = nLow;
    if (nDay >= nHigh)
        nDay = nHigh;
    if (nDay == m_1f4)
        return 1;
    m_1f4 = nDay;
    m_1f8.RemoveAll();
    FUN_141b359b0();
    FUN_141b365e0();
    FUN_141b366b0();
    return 1;
}

// @0x141b363b0
void UIUGCBannerDialog::FUN_141b363b0()
{
    MS2Ptr<CUgcUploadCtrl> spUpload = FUN_14052d220()->FUN_141882610();
    if (spUpload == 0)
        return;
    if (spUpload->m_spFile == 0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("updateThumbnailImage");
}

// @0x141b364a0
void UIUGCBannerDialog::FUN_141b364a0(int nIndex)
{
    if (nIndex == -1)
    {
        if (m_30.get() != 0)
            m_30->Invoke("selectThumbnail", -1);
    }
    else
    {
        MS2Ptr<CUploadFile> spFile = FUN_14052d220()->FUN_14188a4b0(nIndex);
        if (spFile == 0)
            return;
        if (m_30.get() != 0)
            m_30->Invoke("selectThumbnail", nIndex);
        FUN_141b35d00(nIndex);
    }
}

// @0x141b365e0
void UIUGCBannerDialog::FUN_141b365e0()
{
    CStringW strDate = m_1c0.FUN_14088e040();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("setDate", strDate);
}

// @0x141b366b0
void UIUGCBannerDialog::FUN_141b366b0()
{
    if (vfunc_55() == 0)
    {
        Unk_BannerPtr banner = CFieldBannerData::GetBanner(m_188);
        if (banner == 0)
            return;
        FUN_141b36750(FUN_141b368b0());
    }
}

// @0x141b36750
void UIUGCBannerDialog::FUN_141b36750(__int64 nPrice)
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        if (m_238 == 0)
            m_238 = reinterpret_cast<Unk_WcTitleFinder*>(m_30.operator->())->FUN_140c436d0("m_labelMeso");
        if (m_238.get() != 0)
            m_238->FUN_1422e4b80(FUN_1418fec00(FUN_141b36a60(), nPrice, 0));
    }
}

// @0x141b368b0
__int64 UIUGCBannerDialog::FUN_141b368b0()
{
    Unk_BannerPtr banner = CFieldBannerData::GetBanner(m_188);
    if (banner == 0)
        return 0;
    __int64 nTotal = 0;
    POSITION pos = m_1f8.GetHeadPosition();
    while (pos != 0)
    {
        int nHour = m_1f8.GetKeyAt(pos);
        nTotal += banner->GetHourly(nHour);
        m_1f8.GetNext(pos);
    }
    return nTotal;
}

// @0x141b369d0
void UIUGCBannerDialog::FUN_141b369d0()
{
    if (vfunc_55() == 0)
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
            pDialog->Invoke("dirtyReserveList");
    }
}

// @0x141b36a60
int UIUGCBannerDialog::FUN_141b36a60()
{
    if (CFeatureManager::GetInstance()->FUN_14036d710(99))
        return 10;
    return 3;
}

// ---- UIUGCCameraDialog ----

// @0x141b37fb0
UIUGCCameraDialog::UIUGCCameraDialog()
{
    m_80 = 1;
    m_178 = L"";
    m_180 = L"";
    m_188 = 0;
    m_18c = 0;
    m_190 = 0;
    m_194 = 0;
    m_198 = 0;
}

// @0x141b380c0
UIUGCCameraDialog::~UIUGCCameraDialog()
{
}

// @0x141b38130
CString UIUGCCameraDialog::vfunc_1()
{
    return CString("UGCCameraDialog");
}

// @0x141b38180
int UIUGCCameraDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x141b381b0
void UIUGCCameraDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x141b381d0
void UIUGCCameraDialog::vfunc_72()
{
    if (vfunc_55() != 1 && m_188 > 0)
    {
        if (m_188 == 1)
            m_188 = 2;
        else if (m_188 == 2)
        {
            m_188 = 0;
            FUN_141276180(s_strProfileTakePhoto, CString(""));
            FUN_141276180(s_strPCTakePhoto, CString(""));
            FUN_141b386b0(m_18c, m_190, m_194, m_198);
            UIUGCImageUploadDialog* pDialog = UgcFindDialog<UIUGCImageUploadDialog>(eUI_4e56);
            if (pDialog != 0)
                pDialog->FUN_141b3a600();
        }
    }
}

// @0x141b38320
void UIUGCCameraDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        pDialog->Invoke("open",
                        FUN_1401d3200()->UGCCameraDefaultSize.Read(),
                        FUN_1401d3200()->UGCCameraMinSize.Read(),
                        FUN_1401d3200()->UGCCameraMaxSize.Read(),
                        FUN_1401d3200()->UGCCameraSnapshotPreviewTime.Read());
    }
}

// @0x141b38430
void UIUGCCameraDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
}

// @0x141b38460
int UIUGCCameraDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    return 0;
}

// @0x141b384b0
int UIUGCCameraDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnSnapShot", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDialog != 0)
            {
                float fScale = ((Unk_UiScale*)FUN_1403ed2b0())->FUN_141adbe70();
                m_18c = (int)(data.FUN_1422b8ca0() / fScale);
                m_190 = (int)(data.FUN_1422b8ca0() / fScale);
                m_194 = (int)(data.FUN_1422b8ca0() / fScale);
                m_198 = (int)(data.FUN_1422b8ca0() / fScale);
                m_188 = 1;
            }
        }
        return 1;
    }
    if (_stricmp("onProfile", szMethod) == 0)
        FUN_14052d220()->FUN_14187fb30();
    return 0;
}

// @0x141b386b0
void UIUGCCameraDialog::FUN_141b386b0(int nX, int nY, int nWidth, int nHeight)
{
    NiRect<unsigned int> rect(0, 0, 0, 0);
    rect.m_left = nX;
    rect.m_right = nX + nWidth;
    rect.m_top = nY;
    rect.m_bottom = nY + nHeight;
    Unk_UgcFileResult result = SaveUgcThumbnailImage(rect, 0);
    if (result.m_nResult == 0)
    {
        m_178.Format(L"%s/%s", (const wchar_t*)FUN_141028910(5), (const wchar_t*)result.m_strName);
        m_180.Format(L"%s\\%s", (const wchar_t*)FUN_141026920(5), (const wchar_t*)result.m_strName);
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
            pDialog->Invoke("savedSnapShot", m_178);
    }
    else
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
            pDialog->Invoke("failedSnapShop");
    }
}

// ---- UIUGCEventListener / UIUGCEventDispatcher (placeholders; bodies of this obj) ----

// @0x141b38b00
UIUGCEventListener::UIUGCEventListener()
{
}

// @0x141b38b20
UIUGCEventListener::~UIUGCEventListener()
{
}

// @0x141b38b40
UIUGCEventDispatcher::UIUGCEventDispatcher()
{
}

// @0x141b38b90
UIUGCEventDispatcher::~UIUGCEventDispatcher()
{
    m_8.RemoveAll();
}

// MS2-FUNCTIONAL: the exe's CAtlArray<void*>::Add takes the element by reference (older ATL); ours takes it by value
// @0x141b38be0
void UIUGCEventDispatcher::FUN_141b38be0(UIUGCEventListener* pListener)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        if (pListener == m_8[i])
            return;
    }
    m_8.Add(pListener);
}

// @0x141b38c70
void UIUGCEventDispatcher::FUN_141b38c70(UIUGCEventListener* pListener)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        if (pListener == m_8[i])
        {
            m_8.RemoveAt(i, 1);
            return;
        }
    }
}

// @0x141b38d00
void UIUGCEventDispatcher::vfunc_1(void* p, CString str)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIUGCEventListener* pListener = static_cast<UIUGCEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_ugc_1(p, str);
    }
}

// @0x141b38dd0
void UIUGCEventDispatcher::vfunc_2(void* p, CString str)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIUGCEventListener* pListener = static_cast<UIUGCEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_ugc_2(p, str);
    }
}

// @0x141b38ea0
void UIUGCEventDispatcher::vfunc_3(void* p, void* q)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIUGCEventListener* pListener = static_cast<UIUGCEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_ugc_3(p, q);
    }
}

// @0x141b38f30
void UIUGCEventDispatcher::vfunc_4(int n)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIUGCEventListener* pListener = static_cast<UIUGCEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_ugc_4(n);
    }
}

// @0x141b38fc0
void UIUGCEventDispatcher::vfunc_5()
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIUGCEventListener* pListener = static_cast<UIUGCEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_ugc_5();
    }
}

// @0x141b39040
void UIUGCEventDispatcher::vfunc_6()
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIUGCEventListener* pListener = static_cast<UIUGCEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_ugc_6();
    }
}

// @0x141b390c0
void UIUGCEventDispatcher::vfunc_7(int n)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIUGCEventListener* pListener = static_cast<UIUGCEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_ugc_7(n);
    }
}
