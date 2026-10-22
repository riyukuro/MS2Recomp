// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Second translation unit of the client UGC code (the queue
// entry client\ms2\ugcmanager.cpp spans four TUs; see ugcmanager.h): the UGC downloads. CUgcDownloadDown queues one
// CUgcDownloadCtrl per URL; each runs URLDownloadToFileW on its own thread, and the subclass of the content kind hands
// the downloaded file to the proxies (items, cubes, banners, profile images, guild emblems, ...) that asked for it.
// MS2-UNIT: client\ms2\ugcmanager.cpp#2
// MS2-RANGE: 0x14186ef00-0x14187d7e0 .text$mn
// MS2-RANGE: 0x14010eee0-0x14010f100 .text$di
// MS2-RANGE: 0x142cbc320-0x142cbc410 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCUgcBannerPost@@@@QEAAAEAV1@PEAVCUgcBannerPost@@@Z 0x141877940 ; unique
// MS2-PIN: ??_ECUgcDownloadAdBanner@@W7EAAPEAXI@Z 0x141877e50 ; unique
// MS2-PIN: ??_ECUgcDownloadBanner@@W7EAAPEAXI@Z 0x141877e5c ; unique
// MS2-PIN: ??_ECUgcDownloadBannerAdvertise@@W7EAAPEAXI@Z 0x141877e68 ; unique
// MS2-PIN: ??_ECUgcDownloadBannerRollingImage@@W7EAAPEAXI@Z 0x141877e74 ; unique
// MS2-PIN: ??_ECUgcDownloadBlueprintIcon@@W7EAAPEAXI@Z 0x141877e80 ; unique
// MS2-PIN: ??_ECUgcDownloadBlueprintImage@@W7EAAPEAXI@Z 0x141877e8c ; unique
// MS2-PIN: ??_ECUgcDownloadCtrl@@W7EAAPEAXI@Z 0x141877e98 ; unique
// MS2-PIN: ??_ECUgcDownloadCube@@W7EAAPEAXI@Z 0x141877ea4 ; unique
// MS2-PIN: ??_ECUgcDownloadEquip@@W7EAAPEAXI@Z 0x141877ebc ; unique
// MS2-PIN: ??_ECUgcDownloadGuildMark@@W7EAAPEAXI@Z 0x141877ec8 ; unique
// MS2-PIN: ??_ECUgcDownloadGuildPoster@@W7EAAPEAXI@Z 0x141877ed4 ; unique
// MS2-PIN: ??_ECUgcDownloadItemIcon@@W7EAAPEAXI@Z 0x141877ee0 ; unique
// MS2-PIN: ??_ECUgcDownloadProfile@@W7EAAPEAXI@Z 0x141877eec ; unique
// MS2-PIN: ??_ECUgcDownloadRidee@@W7EAAPEAXI@Z 0x141877ef8 ; unique
// MS2-PIN: ??_ECUgcDownloadShopBanner@@W7EAAPEAXI@Z 0x141877f04 ; unique
// MS2-PIN: ??_ECUgcDownloadWeddingProfile@@W7EAAPEAXI@Z 0x141877f10 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CUgcDownloadDown@@6B?$TSingleton@VCUgcDownloadDown@@@@@ 0x142f8b240 ; manual: RTTI pairing misses the base name
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

// The header statics of the unit; egf::kENTITY_INVALID sits between the "stun" name and the condition object.
#define MS2_STATICS_A_BEFORE_CONDITION <egf/EntityID.h>
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";

#include <io.h>
#include <urlmon.h>
#include <wininet.h>
#pragma comment(lib, "urlmon.lib")
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>

#include "ugcmanager.h"
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include "interactobject.h"
#pragma pop_macro("max")
#pragma pop_macro("min")
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiattendgiftdialog.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cugcdownloaddown.h"
#include "ms2/placeholder/cugcdownloadload.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- callees ------------------------------------------------------------------------------------------------------

CLogString* GetLogString();                                // the log singleton
CUgcDownloadDown* FUN_1414a57f0();
CUgcDownloadLoad* FUN_1414a5800();
CUgcManager* FUN_14052d220();

// UGC file names and paths.
CString FUN_141027200(CString strName);                     // the cache key of a URL
CString FUN_1410272e0(CString strUrl);                      // the file name of a URL
CString FUN_1410280d0(int nKind, CString strName);          // the local file of a content kind
CString FUN_141028a90(CString strPath, int n);
CString FUN_14028d990(const CString& strUrl);
CStringW FUN_14016a730(const char* psz, int nCodePage);     // multi-byte to wide
void FUN_14015f050(const CString& str, CAtlArray<CString>& parts, const char* pszSep);   // split

// The game rules: content kinds a rule set disables (rule 0xb: UGC).
class Unk_UgcContentRule
{
public:
    bool FUN_1407d1210(int nType);
};
class Unk_UgcGameRules
{
public:
    Unk_UgcContentRule* FUN_14046d0d0(int nRule);
};
Unk_UgcGameRules* FUN_140302b00();

// The client options; mode 1 bypasses the URL cache.
class Unk_UgcClientOptions
{
public:
    int FUN_140478a60();
};
Unk_UgcClientOptions* FUN_1401c0d90();
unsigned int FUN_140869420();                               // the tick count (ms)

// The start handshake of CThread::vfunc_1.
class Unk_140659080
{
public:
    void FUN_1401d42d0();                                   // the thread is running
    int FUN_140659080(int nResult);                         // the thread failed to start
};

// The thread profiler scope of a worker thread (client\ms2\util.cpp).
void FUN_141b6de20();
class Unk_UtilLogScope
{
public:
    Unk_UtilLogScope(CStringA kTag);                            // 0x141b721f0
    ~Unk_UtilLogScope();                                        // 0x141b722b0
private:
    DWORD m_dwThread;
    CStringA m_kTag;
};

// Players and objects of the field.
class Unk_UgcEquipItem : public CPtred
{
public:
    void FUN_1411dc900(int bReload);                        // reload the UGC texture
};
class Unk_UgcItemIconOwner
{
public:
    void FUN_1411911f0();
};
class Unk_UgcPlayer
{
public:
    MS2Ptr<Unk_UgcEquipItem> FUN_141655c30(__int64 nItemUid);   // a worn item by uid
    Unk_UgcItemIconOwner* FUN_1417411e0();
    void FUN_1416611b0(CString strPath);                    // set the profile image
};
__int64 FUN_141656a80(Unk_UgcPlayer* pPlayer);              // the character id
int FUN_14123c580(Unk_UgcPlayer* pPlayer);                  // the object id
class Unk_UgcNameTag : public CPtred
{
public:
    char m_pad[0x50 - sizeof(CPtred)];
    CString m_strProfileImage;                              // +0x50
};
class Unk_UgcRidee
{
public:
    void FUN_1417072b0();                                   // reload the UGC texture
};
Unk_UgcRidee* FUN_1409ffd80(void* pEntity);
class Unk_UgcWorld
{
public:
    Unk_UgcPlayer* FUN_141bd0cc0();                         // the local player
    Unk_UgcPlayer* FUN_141bd1180(int nObjectId);
    Unk_UgcPlayer* FUN_141bd1290(int nObjectId);
    Unk_UgcPlayer* FUN_141bd1530(__int64 characterId);
    MS2Ptr<CInteractObject> FUN_141bc66b0(const CString& strName);
    MS2Ptr<Unk_UgcNameTag> FUN_141bc9be0(int nObjectId);
    void* FUN_141bd0fa0(egf::EntityID id);
};
Unk_UgcWorld* FUN_1403ed2d0();
void* FUN_1408e57f0();                                      // the current field
int FUN_1422b9dc0(void* pField);                            // its map id

// The cube placement service (efd service 0x06100017).
class Unk_UgcCube
{
};
void FUN_1408b51d0(Unk_UgcCube* pCube);                     // reload the UGC texture
class Unk_UgcCubeService : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    Unk_UgcCube* FUN_1410b8c90(egf::EntityID id);
};
struct Unk_UgcFramework
{
    efd::ServiceManagerPtr manager;
};
extern Unk_UgcFramework DAT_143b059e8;
Unk_UgcCubeService* FUN_1401cd040(Unk_UgcFramework* pFramework);

// The UGC event dispatcher (the UIUGCEventListener slots).
class Unk_UgcEventDispatcher
{
public:
    virtual ~Unk_UgcEventDispatcher();
    virtual void OnProfileImage(__int64 characterId, CString strPath);         // 1
    virtual void OnItemIcon(__int64 itemUid, CString strPath);                 // 2
    virtual void OnCallBackIcon(UgcItemIcon::CallBackData* pData, const CString& strPath);   // 3
};
Unk_UgcEventDispatcher* FUN_140bc09f0();

// The notification center.
class Unk_UgcNotifyCenter
{
public:
    void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify);
};
Unk_UgcNotifyCenter* FUN_140939a10();

// Dialogs.
class Unk_UgcUIManager
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
};
Unk_UgcUIManager* FUN_1403ed2b0();
class UIWeddingDialog : public UIDialog
{
public:
    void FUN_140fc7f30();                                   // refresh the profile images
};
class Unk_UgcCubePaletteDialog
{
public:
    void FUN_140eec480();
};
Unk_UgcCubePaletteDialog* FUN_140ef4a50(int nId);
class Unk_UgcGuildDialog : public UIDialog
{
public:
    void FUN_1419764f0(__int64 guildId, const CString& strPath);
};
Unk_UgcGuildDialog* FUN_14136f480(int nId);
class Unk_UgcGuildPvpDialog : public UIDialog
{
public:
    void FUN_14133b0f0(__int64 guildId, const CStringW& strPath);
};
Unk_UgcGuildPvpDialog* FUN_141531be0(int nId);
class Unk_UgcGuildRankDialog : public UIDialog
{
public:
    void FUN_1413415e0(__int64 guildId, const CStringW& strPath);
};
Unk_UgcGuildRankDialog* FUN_1413c87c0(int nId);
class Unk_UgcShopDialog
{
public:
    void FUN_14130bf20(CString strKey, CString strPath, bool bOk);
};
Unk_UgcShopDialog* FUN_140bfed50(int nId);
// The client platform (the scene-state game service); slot 47 shows a downloaded shop banner.
class Unk_UgcPlatform
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46();
    virtual void SetShopBanner(CString strKey, CString strPath);   // 47
};
Unk_UgcPlatform* FUN_140d86260();
class Unk_UgcGuildManager
{
public:
    void FUN_1413baef0(int nPosterId, unsigned char bShow);
};
Unk_UgcGuildManager* FUN_1403ed290();

void FUN_1401859c0(CLogString* log, int level, int category, const wchar_t* psz);   // a plain log line

// An ActionScript call.
class Unk_UgcUIMsg : public UIMsg
{
public:
    Unk_UgcUIMsg();                                         // 0x1422e4490
    ~Unk_UgcUIMsg();                                        // 0x140c30570
    void FUN_1422b82b0(const char* psz);
    void FUN_1422b7fd0(bool b);
    void* m_pad[10];
};

// The unit's log call (an FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
template <class T> inline void Unk_UgcLog(CLogString* log, int level, int category, const wchar_t* format,
                                          const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}

// A dialog by id (the template the UI units inline).
template <class T> T* Unk_UgcGetDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// A UI entity by name.
template <class T> T* Unk_UgcGetEntity(CString strName)
{
    return dynamic_cast<T*>(FUN_140b632f0()->GetUISwfEntity(strName).get());
}

// ---- CUgcDownloadParam --------------------------------------------------------------------------------------------

// @0x14186ef00
CUgcDownloadParam::CUgcDownloadParam()
{
    Clear();
}

// @0x14186ef80
CUgcDownloadParam::~CUgcDownloadParam()
{
}

// @0x14186eff0
void CUgcDownloadParam::Clear()
{
    m_nType = 0;
    m_user.Clear();
    m_upload.Clear();
    m_strUrl = "";
    m_bLocal = 0;
}
MS2_REPLACE_METHOD(0x14186eff0, CUgcDownloadParam, Clear, 136, 0xEEF9BB11);

// @0x14186f080
void CUgcDownloadParam::CopyFrom(const CUgcDownloadParam* pOther)
{
    Clear();
    if (pOther == NULL)
        return;
    m_nType = pOther->m_nType;
    m_user.CopyFrom(&pOther->m_user);
    m_upload.CopyFrom(&pOther->m_upload);
    m_strUrl = pOther->m_strUrl;
    m_bLocal = pOther->m_bLocal;
}
MS2_REPLACE_METHOD(0x14186f080, CUgcDownloadParam, CopyFrom, 198, 0x11300E38);

// ---- CUgcDownloadCtrl ---------------------------------------------------------------------------------------------

// @0x14186f150
CUgcDownloadCtrl::CUgcDownloadCtrl(CString strUrl) : m_callback(this), m_pThread(NULL)
{
    m_strUrl = strUrl;
    m_strPath = "";
    m_bComplete = 0;
    m_param.Clear();
    m_nResult = 1;
}

// @0x14186f290
CUgcDownloadCtrl::~CUgcDownloadCtrl()
{
}

// @0x14186f320
CString CUgcDownloadCtrl::GetUrl()
{
    return m_strUrl;
}
MS2_REPLACE_METHOD(0x14186f320, CUgcDownloadCtrl, GetUrl, 68, 0xF5A48732);

// @0x14186f370
CString CUgcDownloadCtrl::GetPath()
{
    return m_strPath;
}
MS2_REPLACE_METHOD(0x14186f370, CUgcDownloadCtrl, GetPath, 68, 0x887E5F1A);

// @0x14186f3c0
CString CUgcDownloadCtrl::GetFileName()
{
    if (m_strUrl.Find(".s3.", 0) != -1)
    {
        CAtlArray<CString> parts;
        FUN_14015f050(m_strUrl, parts, "/");
        int nLast = parts.GetCount() - 1;
        if (nLast < 0)
            return "";
        CString strName = parts[nLast];
        return strName;
    }
    else
    {
        return m_strUrl;
    }
}
MS2_REPLACE_METHOD(0x14186f3c0, CUgcDownloadCtrl, GetFileName, 320, 0xF1AEA004);

// @0x14186f510
int CUgcDownloadCtrl::IsComplete()
{
    return m_bComplete;
}
MS2_REPLACE_METHOD(0x14186f510, CUgcDownloadCtrl, IsComplete, 17, 0xD382A09B);

// @0x14186f530
void CUgcDownloadCtrl::SetResult(int nResult)
{
    m_nResult = nResult;
}
MS2_REPLACE_METHOD(0x14186f530, CUgcDownloadCtrl, SetResult, 25, 0xA3C4A10B);

// @0x14186f550
int CUgcDownloadCtrl::GetResult()
{
    return m_nResult;
}
MS2_REPLACE_METHOD(0x14186f550, CUgcDownloadCtrl, GetResult, 17, 0x6E1EF627);

// @0x14186f570
void CUgcDownloadCtrl::Start()
{
    MakePath();
    m_pThread = AfxBeginThread(Downloading, this, 0, 0, 0, NULL);
}
MS2_REPLACE_METHOD(0x14186f570, CUgcDownloadCtrl, Start, 82, 0x3932A5E7);

// @0x14186f5d0
void CUgcDownloadCtrl::OnSuccess()
{
    if (OnDownloaded() == 1)
    {
        if (FUN_1414a57f0())
            FUN_1414a57f0()->Finish(GetUrl(), 0);
    }
}
MS2_REPLACE_METHOD(0x14186f5d0, CUgcDownloadCtrl, OnSuccess, 116, 0xD303C032);

// @0x14186f650
void CUgcDownloadCtrl::OnFailure(HRESULT hr)
{
    if (hr == E_ABORT)
    {
        if (_access(GetPath(), 4) == 0)
        {
            OnSuccess();
            return;
        }
    }
    if (FUN_1414a57f0())
        FUN_1414a57f0()->Finish(GetUrl(), 0x1f);
}
MS2_REPLACE_METHOD(0x14186f650, CUgcDownloadCtrl, OnFailure, 220, 0xEFDFEA66);

// @0x14186f740
HRESULT CUgcDownloadCtrl::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
{
    if (ulProgress == ulProgressMax && ulStatusCode == BINDSTATUS_ENDDOWNLOADDATA)
        m_bComplete = 1;
    return S_OK;
}
MS2_REPLACE_METHOD(0x14186f740, CUgcDownloadCtrl, OnProgress, 54, 0x4E22E45E);

// @0x14186f780
UINT CUgcDownloadCtrl::Downloading(LPVOID pParam)
{
    FUN_141b6de20();
    Unk_UtilLogScope scope(CString("CUgcDownloadCtrl::Downloading"));
    CUgcDownloadCtrl* pCtrl = static_cast<CUgcDownloadCtrl*>(pParam);
    CStringW strUrl = FUN_14016a730(pCtrl->GetUrl(), 0);
    CStringW strPath = FUN_14016a730(pCtrl->GetPath(), 0);
    Unk_UgcClientOptions* pOptions = FUN_1401c0d90();
    if (pOptions && pOptions->FUN_140478a60() == 1)
        DeleteUrlCacheEntryW(strUrl);
    HRESULT hr = URLDownloadToFileW(NULL, strUrl, strPath, 0, &pCtrl->m_callback);
    if (pCtrl->IsComplete())
        pCtrl->OnSuccess();
    else
        pCtrl->OnFailure(hr);
    return 0;
}
MS2_REPLACE(0x14186f780, CUgcDownloadCtrl::Downloading, 493, 0x5816E807);

// ---- the subclasses -----------------------------------------------------------------------------------------------

// @0x14186f980
CUgcDownloadEquip::CUgcDownloadEquip(CString strUrl) : CUgcDownloadCtrl(strUrl), m_list(10)
{
}

// @0x14186fa20
CUgcDownloadEquip::~CUgcDownloadEquip()
{
    m_list.RemoveAll();
}

// @0x14186fa90
// MS2-FUNCTIONAL: the exe moves pProxy through an extra pointer temp before the downcast (two-level proxy
// classes); no cast form tried reproduces it
void CUgcDownloadEquip::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcItemPC* pSrc = static_cast<CUgcItemPC*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcItemPC> sp(new CUgcItemPC);
    sp->CopyFrom(pSrc);
    m_list.AddTail(sp);
}
MS2_REPLACE_METHOD(0x14186fa90, CUgcDownloadEquip, AddProxy, 229, 0x4873A353);

// @0x14186fb80
void CUgcDownloadEquip::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(1, strName);
}
MS2_REPLACE_METHOD(0x14186fb80, CUgcDownloadEquip, MakePath, 238, 0x49EC9BEB);

// @0x14186fc80
void CUgcDownloadEquip::ProcessResult()
{
    if (m_nResult == 0)
    {
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcItemPC> sp = m_list.GetAt(pos);
            if (sp == 0)
                continue;
            Unk_UgcPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(sp->m_nObjectId);
            if (pPlayer == NULL)
                continue;
            MS2Ptr<Unk_UgcEquipItem> spEquip = pPlayer->FUN_141655c30(sp->m_itemUid);
            if (spEquip == 0)
                continue;
            spEquip->FUN_1411dc900(1);
        }
    }
    Unk_UgcLog(GetLogString(), 0xc, 0x13, L"[CUgcDownloadEquip::ProcessResult] proxy count = {0}", m_list.GetCount());
}
MS2_REPLACE_METHOD(0x14186fc80, CUgcDownloadEquip, ProcessResult, 447, 0xE108C4AE);

// @0x14186fe50
int CUgcDownloadEquip::OnDownloaded()
{
    FUN_1414a5800()->Push(m_strUrl, m_strPath, m_param.m_nType, m_param.m_upload.m_uid);
    return 0;
}
MS2_REPLACE_METHOD(0x14186fe50, CUgcDownloadEquip, OnDownloaded, 193, 0xA6BFCA79);

// @0x14186ff20
CUgcDownloadCube::CUgcDownloadCube(CString strUrl) : CUgcDownloadCtrl(strUrl), m_list(10)
{
}

// @0x14186ffc0
CUgcDownloadCube::~CUgcDownloadCube()
{
    m_list.RemoveAll();
}

// @0x141870030
// MS2-FUNCTIONAL: the exe moves pProxy through an extra pointer temp before the downcast (two-level proxy
// classes); no cast form tried reproduces it
void CUgcDownloadCube::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcItemCube* pSrc = static_cast<CUgcItemCube*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcItemCube> sp(new CUgcItemCube);
    sp->CopyFrom(pSrc);
    m_list.AddTail(sp);
}
MS2_REPLACE_METHOD(0x141870030, CUgcDownloadCube, AddProxy, 229, 0x60FAB4CD);

// @0x141870120
void CUgcDownloadCube::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(2, strName);
}
MS2_REPLACE_METHOD(0x141870120, CUgcDownloadCube, MakePath, 238, 0x60D545CC);

// @0x141870220
void CUgcDownloadCube::ProcessResult()
{
    if (m_nResult == 0)
    {
        efd::SmartPointer<Unk_UgcCubeService> spService(FUN_1401cd040(&DAT_143b059e8));
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcItemCube> sp = m_list.GetAt(pos);
            if (sp == 0)
                continue;
            Unk_UgcCube* pCube = spService->FUN_1410b8c90(sp->m_entityId);
            if (pCube)
                FUN_1408b51d0(pCube);
            else
                FUN_14052d220()->FUN_141886cc0(sp.get(), m_strPath, m_param.m_upload.m_uid);
        }
        Unk_UgcCubePaletteDialog* pDialog = FUN_140ef4a50(0x4f16);
        if (pDialog)
            pDialog->FUN_140eec480();
    }
    Unk_UgcLog(GetLogString(), 0xc, 0x13, L"[CUgcDownloadCube::ProcessResult] proxy count = {0}", m_list.GetCount());
}
MS2_REPLACE_METHOD(0x141870220, CUgcDownloadCube, ProcessResult, 574, 0x6AF398CE);

// @0x141870470
int CUgcDownloadCube::OnDownloaded()
{
    FUN_1414a5800()->Push(m_strUrl, m_strPath, m_param.m_nType, m_param.m_upload.m_uid);
    return 0;
}
MS2_REPLACE_METHOD(0x141870470, CUgcDownloadCube, OnDownloaded, 193, 0xFD8002C8);

// @0x141870540
CUgcDownloadItemIcon::CUgcDownloadItemIcon(CString strUrl) : CUgcDownloadCtrl(strUrl), m_list(10)
{
}

// @0x1418705e0
CUgcDownloadItemIcon::~CUgcDownloadItemIcon()
{
    m_list.RemoveAll();
}

// @0x141870650
// MS2-FUNCTIONAL: the exe moves pProxy through an extra pointer temp before the downcast (two-level proxy
// classes); no cast form tried reproduces it
void CUgcDownloadItemIcon::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcItemIconPC* pSrc = static_cast<CUgcItemIconPC*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcItemIconPC> sp(new CUgcItemIconPC);
    sp->CopyFrom(pSrc);
    m_list.AddTail(sp);
}
MS2_REPLACE_METHOD(0x141870650, CUgcDownloadItemIcon, AddProxy, 229, 0xBF306250);

// @0x141870740
void CUgcDownloadItemIcon::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(0xc9, strName);
}
MS2_REPLACE_METHOD(0x141870740, CUgcDownloadItemIcon, MakePath, 238, 0x01691EE1);

// @0x141870840
void CUgcDownloadItemIcon::ProcessResult()
{
    if (m_nResult == 0)
    {
        Unk_UgcPlayer* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC == NULL)
            return;
        CString strUrl = FUN_1410272e0(m_strUrl);
        MS2Ptr<CItem> spItem(0);
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcItemIconPC> sp = m_list.GetAt(pos);
            if (sp == 0)
                continue;
            if (sp->m_nKind == 1)
            {
                Unk_UgcPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1180(sp->m_nObjectId);
                Unk_UgcItemIconOwner* pOwner;
                if (pPlayer && (pOwner = pPlayer->FUN_1417411e0()) != NULL)
                    pOwner->FUN_1411911f0();
            }
            else if (sp->m_nKind == 2)
            {
                FUN_140bc09f0()->OnItemIcon(sp->m_itemUid, strUrl);
            }
            else if (sp->m_nKind == 3)
            {
                FUN_140bc09f0()->OnCallBackIcon(&sp->m_callBack, m_strPath);
            }
        }
    }
    Unk_UgcLog(GetLogString(), 0xc, 0x13, L"[CUgcDownloadItemIcon::ProcessResult] proxy count = {0}",
               m_list.GetCount());
}
MS2_REPLACE_METHOD(0x141870840, CUgcDownloadItemIcon, ProcessResult, 782, 0xBF3BA1EC);

// @0x141870b60
CUgcDownloadBanner::CUgcDownloadBanner(CString strUrl) : CUgcDownloadCtrl(strUrl)
{
    m_spPost = 0;
}

// @0x141870c10
CUgcDownloadBanner::~CUgcDownloadBanner()
{
    m_spPost = 0;
}

// @0x141870c90
// MS2-FUNCTIONAL: the exe moves pProxy through an extra pointer temp before the downcast (two-level proxy
// classes); no cast form tried reproduces it
void CUgcDownloadBanner::AddProxy(IUgcProxy* pProxy)
{
    if (m_spPost.get() == 0 && pProxy)
    {
        CUgcBannerPost* pSrc = static_cast<CUgcBannerPost*>(pProxy);
        if (pSrc)
        {
            m_spPost.AssignRaw(new CUgcBannerPost);
            m_spPost->CopyFrom(pSrc);
        }
    }
}
MS2_REPLACE_METHOD(0x141870c90, CUgcDownloadBanner, AddProxy, 231, 0x285DCB5C);

// @0x141870d80
void CUgcDownloadBanner::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(3, strName);
}
MS2_REPLACE_METHOD(0x141870d80, CUgcDownloadBanner, MakePath, 238, 0x3AF60BD9);

// @0x141870e80
void CUgcDownloadBanner::ProcessResult()
{
    if (m_nResult == 0)
    {
        int nBannerId = m_spPost->m_nBannerId;
        CString strUrl = FUN_1410272e0(m_strUrl);
        MS2Ptr<CUgcRegistBanner> sp(new CUgcRegistBanner);
        sp->m_nType = m_param.m_nType;
        sp->m_strUrl = strUrl;
        sp->m_user.CopyFrom(&m_param.m_user);
        sp->m_upload.CopyFrom(&m_param.m_upload);
        sp->m_post.CopyFrom(m_spPost.get());
        FUN_14052d220()->FUN_141887dc0(nBannerId, sp);
    }
}
MS2_REPLACE_METHOD(0x141870e80, CUgcDownloadBanner, ProcessResult, 592, 0xBAA0BF86);

// @0x1418710e0
int CUgcDownloadBanner::OnDownloaded()
{
    FUN_1414a5800()->Push(m_strUrl, m_strPath, m_param.m_nType, m_param.m_upload.m_uid);
    return 0;
}
MS2_REPLACE_METHOD(0x1418710e0, CUgcDownloadBanner, OnDownloaded, 193, 0x6428784E);

// @0x1418711b0
CUgcDownloadProfile::CUgcDownloadProfile(CString strUrl) : CUgcDownloadCtrl(strUrl), m_list(10)
{
}

// @0x141871250
CUgcDownloadProfile::~CUgcDownloadProfile()
{
    m_list.RemoveAll();
}

// @0x1418712c0
void CUgcDownloadProfile::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcUserProxy* pSrc = static_cast<CUgcUserProxy*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcUserProxy> sp(new CUgcUserProxy);
    sp->CopyFrom(pSrc);
    m_list.AddTail(sp);
}
MS2_REPLACE_METHOD(0x1418712c0, CUgcDownloadProfile, AddProxy, 210, 0xD22A85D3);

// @0x1418713a0
void CUgcDownloadProfile::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(5, strName);
}
MS2_REPLACE_METHOD(0x1418713a0, CUgcDownloadProfile, MakePath, 238, 0xAC0BE74E);

// @0x1418714a0
void CUgcDownloadProfile::ProcessResult()
{
    if (m_nResult == 0)
    {
        CString strUrl = FUN_1410272e0(m_strUrl);
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcUserProxy> sp = m_list.GetAt(pos);
            if (sp == 0)
                continue;
            if (sp->m_strObjectName.GetLength() > 0)
            {
                CInteractObject* pObject = FUN_1403ed2d0()->FUN_141bc66b0(sp->m_strObjectName).get();
                CInteractDisplayImage* pImage = dynamic_cast<CInteractDisplayImage*>(pObject);
                if (pImage)
                {
                    CString strImage = FUN_141028a90(strUrl, 0);
                    pImage->FUN_1414017b0(strImage);
                }
            }
            else
            {
                Unk_UgcPlayer* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (FUN_1422b9dc0(FUN_1408e57f0()) != 0x620000d)
                {
                    if (pMyPC == NULL)
                        return;
                    unsigned int nObjectId = 0;
                    if (FUN_141656a80(pMyPC) == sp->m_characterId)
                    {
                        pMyPC->FUN_1416611b0(strUrl);
                        nObjectId = FUN_14123c580(pMyPC);
                    }
                    else
                    {
                        Unk_UgcPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1530(sp->m_characterId);
                        if (pPlayer)
                        {
                            pPlayer->FUN_1416611b0(strUrl);
                            nObjectId = FUN_14123c580(pPlayer);
                        }
                    }
                    if (nObjectId > 0)
                    {
                        MS2Ptr<Unk_UgcNameTag> spTag = FUN_1403ed2d0()->FUN_141bc9be0(nObjectId);
                        if (spTag.get())
                            spTag->m_strProfileImage = strUrl;
                    }
                }
                FUN_140bc09f0()->OnProfileImage(sp->m_characterId, strUrl);
            }
        }
    }
    Unk_UgcLog(GetLogString(), 0xc, 0x13, L"[CUgcDownloadProfile::ProcessResult] proxy count = {0}", m_list.GetCount());
}
MS2_REPLACE_METHOD(0x1418714a0, CUgcDownloadProfile, ProcessResult, 1217, 0xBCA7EE22);

// @0x141871970
CUgcDownloadWeddingProfile::CUgcDownloadWeddingProfile(CString strUrl) : CUgcDownloadCtrl(strUrl), m_list(10)
{
}

// @0x141871a10
CUgcDownloadWeddingProfile::~CUgcDownloadWeddingProfile()
{
    m_list.RemoveAll();
}

// @0x141871a80
void CUgcDownloadWeddingProfile::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcUserProxy* pSrc = static_cast<CUgcUserProxy*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcUserProxy> sp(new CUgcUserProxy);
    sp->CopyFrom(pSrc);
    m_list.AddTail(sp);
}
MS2_REPLACE_METHOD(0x141871a80, CUgcDownloadWeddingProfile, AddProxy, 210, 0xE80D2F31);

// @0x141871b60
void CUgcDownloadWeddingProfile::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(10, strName);
}
MS2_REPLACE_METHOD(0x141871b60, CUgcDownloadWeddingProfile, MakePath, 238, 0x4F45D9FE);

// @0x141871c60
void CUgcDownloadWeddingProfile::ProcessResult()
{
    if (m_nResult == 0)
    {
        CString strUrl = FUN_1410272e0(m_strUrl);
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcUserProxy> sp = m_list.GetAt(pos);
            if (sp == 0)
                continue;
            UIWeddingDialog* pDialog = Unk_UgcGetDialog<UIWeddingDialog>(0x4f8c);
            if (pDialog)
                pDialog->FUN_140fc7f30();
        }
    }
    Unk_UgcLog(GetLogString(), 0xc, 0x13, L"[CUgcDownloadWeddingProfile::ProcessResult] proxy count = {0}",
               m_list.GetCount());
}
MS2_REPLACE_METHOD(0x141871c60, CUgcDownloadWeddingProfile, ProcessResult, 373, 0x1CCCDB4A);

// @0x141871de0
CUgcDownloadGuildMark::CUgcDownloadGuildMark(CString strUrl) : CUgcDownloadCtrl(strUrl), m_list(10)
{
    m_130 = 0;
}

// @0x141871e90
CUgcDownloadGuildMark::~CUgcDownloadGuildMark()
{
}

// @0x141871ee0
void CUgcDownloadGuildMark::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcGuildMarkProxy* pSrc = static_cast<CUgcGuildMarkProxy*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcGuildMarkProxy> sp(new CUgcGuildMarkProxy);
    sp->CopyFrom(pSrc);
    m_list.AddTail(sp);
}
MS2_REPLACE_METHOD(0x141871ee0, CUgcDownloadGuildMark, AddProxy, 210, 0x5B1E9C51);

// @0x141871fc0
void CUgcDownloadGuildMark::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(6, strName);
}
MS2_REPLACE_METHOD(0x141871fc0, CUgcDownloadGuildMark, MakePath, 238, 0x178A6965);

// @0x1418720c0
void CUgcDownloadGuildMark::ProcessResult()
{
    if (m_nResult == 0)
    {
        CString strUrl = FUN_1410272e0(m_strUrl);
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcGuildMarkProxy> sp = m_list.GetAt(pos);
            if (sp == 0)
                continue;
            Unk_UgcGuildDialog* pGuild = FUN_14136f480(0x4e4f);
            if (pGuild && pGuild->vfunc_55() == 0)
                pGuild->FUN_1419764f0(sp->m_nGuildId, strUrl);
            Unk_UgcGuildPvpDialog* pPvp = FUN_141531be0(0x4ec4);
            if (pPvp && pPvp->vfunc_55() == 0)
                pPvp->FUN_14133b0f0(sp->m_nGuildId, FUN_14016a730(strUrl, 0));
            Unk_UgcGuildRankDialog* pRank = FUN_1413c87c0(0x4ec7);
            if (pRank && pRank->vfunc_55() == 0)
                pRank->FUN_1413415e0(sp->m_nGuildId, FUN_14016a730(strUrl, 0));
            CInteractObject* pObject = FUN_1403ed2d0()->FUN_141bc66b0(sp->m_strName).get();
            CInteractDisplayImage* pImage = dynamic_cast<CInteractDisplayImage*>(pObject);
            if (pImage)
                pImage->FUN_1414017b0(m_strPath);
        }
    }
    Unk_UgcLog(GetLogString(), 0xc, 0x13, L"[CUgcDownloadGuildMark::ProcessResult] proxy count = {0}",
               m_list.GetCount());
}
MS2_REPLACE_METHOD(0x1418720c0, CUgcDownloadGuildMark, ProcessResult, 914, 0xC202CF80);

// @0x141872460
CUgcDownloadGuildPoster::CUgcDownloadGuildPoster(CString strUrl) : CUgcDownloadCtrl(strUrl)
{
}

// @0x141872500
CUgcDownloadGuildPoster::~CUgcDownloadGuildPoster()
{
}

// @0x141872550
void CUgcDownloadGuildPoster::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcGuildPosterProxy* pSrc = static_cast<CUgcGuildPosterProxy*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcGuildPosterProxy> sp(new CUgcGuildPosterProxy);
    sp->CopyFrom(pSrc);
    m_spPoster.AssignRaw(pSrc);                             // the caller's proxy, not the copy
}
MS2_REPLACE_METHOD(0x141872550, CUgcDownloadGuildPoster, AddProxy, 210, 0x0D6D43FB);

// @0x141872630
void CUgcDownloadGuildPoster::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(8, strName);
}
MS2_REPLACE_METHOD(0x141872630, CUgcDownloadGuildPoster, MakePath, 238, 0x4D0A1E3F);

// @0x141872730
void CUgcDownloadGuildPoster::ProcessResult()
{
    if (m_nResult == 0 && m_spPoster.get())
        FUN_1403ed290()->FUN_1413baef0(m_spPoster->m_nIndex, 0);
    FUN_1401859c0(GetLogString(), 0xc, 0x13, L"[CUgcDownloadGuildPoster::ProcessResult]");
}
MS2_REPLACE_METHOD(0x141872730, CUgcDownloadGuildPoster, ProcessResult, 131, 0xC7FB1C84);

// @0x1418727c0
CUgcDownloadRidee::CUgcDownloadRidee(CString strUrl) : CUgcDownloadCtrl(strUrl), m_list(10)
{
}

// @0x141872860
CUgcDownloadRidee::~CUgcDownloadRidee()
{
    m_list.RemoveAll();
}

// @0x1418728d0
// MS2-FUNCTIONAL: the exe moves pProxy through an extra pointer temp before the downcast (two-level proxy
// classes); no cast form tried reproduces it
void CUgcDownloadRidee::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcItemRidee* pSrc = static_cast<CUgcItemRidee*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcItemRidee> sp(new CUgcItemRidee);
    sp->CopyFrom(pSrc);
    m_list.AddTail(sp);
}
MS2_REPLACE_METHOD(0x1418728d0, CUgcDownloadRidee, AddProxy, 229, 0x8D15B524);

// @0x1418729c0
void CUgcDownloadRidee::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(7, strName);
}
MS2_REPLACE_METHOD(0x1418729c0, CUgcDownloadRidee, MakePath, 238, 0xA8BF23C6);

// @0x141872ac0
void CUgcDownloadRidee::ProcessResult()
{
    if (m_nResult == 0)
    {
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcItemRidee> sp = m_list.GetAt(pos);
            if (sp == 0)
                continue;
            Unk_UgcRidee* pRidee = FUN_1409ffd80(FUN_1403ed2d0()->FUN_141bd0fa0(sp->m_entityId));
            if (pRidee)
                pRidee->FUN_1417072b0();
            else
                FUN_14052d220()->FUN_141887040(sp.get(), m_strPath, m_param.m_upload.m_uid);
        }
    }
    Unk_UgcLog(GetLogString(), 0xc, 0x13, L"[CUgcDownloadRidee::ProcessResult] proxy count = {0}", m_list.GetCount());
}
MS2_REPLACE_METHOD(0x141872ac0, CUgcDownloadRidee, ProcessResult, 495, 0x511D51FA);

// @0x141872cc0
int CUgcDownloadRidee::OnDownloaded()
{
    FUN_1414a5800()->Push(m_strUrl, m_strPath, m_param.m_nType, m_param.m_upload.m_uid);
    return 0;
}
MS2_REPLACE_METHOD(0x141872cc0, CUgcDownloadRidee, OnDownloaded, 193, 0x7824E7C8);

// @0x141872d90
CUgcDownloadBannerAdvertise::CUgcDownloadBannerAdvertise(CString strUrl) : CUgcDownloadCtrl(strUrl)
{
}

// @0x141872e10
CUgcDownloadBannerAdvertise::~CUgcDownloadBannerAdvertise()
{
}

// @0x141872e50
void CUgcDownloadBannerAdvertise::AddProxy(IUgcProxy* pProxy)
{
}
MS2_REPLACE_METHOD(0x141872e50, CUgcDownloadBannerAdvertise, AddProxy, 11, 0x02239C70);

// @0x141872e70
void CUgcDownloadBannerAdvertise::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_14028d990(m_strUrl);
    m_strPath = FUN_1410280d0(m_param.m_nType, strName);
}
MS2_REPLACE_METHOD(0x141872e70, CUgcDownloadBannerAdvertise, MakePath, 195, 0x221FA327);

// @0x141872f40
void CUgcDownloadBannerAdvertise::ProcessResult()
{
    if (m_nResult == 0)
    {
        UIBannerAdvertisingDialog* pDialog = Unk_UgcGetDialog<UIBannerAdvertisingDialog>(0x4eca);
        if (pDialog)
            pDialog->SetImage(m_strPath);
    }
}
MS2_REPLACE_METHOD(0x141872f40, CUgcDownloadBannerAdvertise, ProcessResult, 106, 0xBAA211FA);

// @0x141872fb0
CUgcDownloadShopBanner::CUgcDownloadShopBanner(CString strUrl) : CUgcDownloadCtrl(strUrl), m_list(10)
{
}

// @0x141873050
CUgcDownloadShopBanner::~CUgcDownloadShopBanner()
{
    m_list.RemoveAll();
}

// @0x1418730c0
void CUgcDownloadShopBanner::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcShopBannerProxy* pSrc = static_cast<CUgcShopBannerProxy*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcShopBannerProxy> sp(new CUgcShopBannerProxy);
    sp->CopyFrom(pSrc);
    m_list.AddTail(sp);
}
MS2_REPLACE_METHOD(0x1418730c0, CUgcDownloadShopBanner, AddProxy, 210, 0x318431FC);

// @0x1418731a0
void CUgcDownloadShopBanner::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_14028d990(m_strUrl);
    m_strPath = FUN_1410280d0(m_param.m_nType, strName);
}
MS2_REPLACE_METHOD(0x1418731a0, CUgcDownloadShopBanner, MakePath, 195, 0xD18445C4);

// @0x141873270
void CUgcDownloadShopBanner::ProcessResult()
{
    if (m_nResult == 0 && m_param.m_nType == 0xcb)
    {
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcShopBannerProxy> sp = m_list.GetAt(pos);
            FUN_140d86260()->SetShopBanner(sp->m_strKey, m_strPath);
        }
    }
    if (m_param.m_nType == 0xcc || m_param.m_nType == 0xcf || m_param.m_nType == 0xd2)
    {
        Unk_UgcShopDialog* pDialog = FUN_140bfed50(0x4ec1);
        bool bOk = m_nResult == 0 ? TRUE : FALSE;
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcShopBannerProxy> sp = m_list.GetAt(pos);
            if (!sp->m_strEntity.IsEmpty())
            {
                UIObject* pEntity = Unk_UgcGetEntity<UIObject>(sp->m_strEntity);
                if (pEntity)
                {
                    Unk_UgcUIMsg msg;
                    msg.FUN_1422b82b0("setImgPath");
                    msg.FUN_1422b82b0(sp->m_strKey);
                    msg.FUN_1422b82b0(m_strPath);
                    msg.FUN_1422b7fd0(bOk);
                    pEntity->OnMessage(0, &msg);
                }
            }
            else
            {
                pDialog->FUN_14130bf20(sp->m_strKey, m_strPath, bOk);
            }
        }
        Unk_UgcLog(GetLogString(), 0xc, 0x13, L"[CUgcDownloadShopBanner::ProcessResult] proxy count = {0}",
                   m_list.GetCount());
    }
}
MS2_REPLACE_METHOD(0x141873270, CUgcDownloadShopBanner, ProcessResult, 1155, 0x595F080F);

// @0x141873700
CUgcDownloadAdBanner::CUgcDownloadAdBanner(CString strUrl) : CUgcDownloadCtrl(strUrl)
{
}

// @0x141873780
CUgcDownloadAdBanner::~CUgcDownloadAdBanner()
{
}

// @0x1418737c0
void CUgcDownloadAdBanner::AddProxy(IUgcProxy* pProxy)
{
}
MS2_REPLACE_METHOD(0x1418737c0, CUgcDownloadAdBanner, AddProxy, 11, 0x02239C70);

// @0x1418737e0
void CUgcDownloadAdBanner::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_14028d990(m_strUrl);
    m_strPath = FUN_1410280d0(m_param.m_nType, strName);
}
MS2_REPLACE_METHOD(0x1418737e0, CUgcDownloadAdBanner, MakePath, 195, 0x1DDC5225);

// @0x1418738b0
void CUgcDownloadAdBanner::ProcessResult()
{
    if (m_nResult == 0)
        FUN_140939a10()->FUN_140da4fe0(
            MS2Ptr<NotifyObject>(new NotifyUgcDownloadComplete(m_param.m_nType, m_strUrl, m_strPath)));
}
MS2_REPLACE_METHOD(0x1418738b0, CUgcDownloadAdBanner, ProcessResult, 298, 0xBD917E27);

// @0x1418739e0
CUgcDownloadBannerRollingImage::CUgcDownloadBannerRollingImage(CString strUrl) : CUgcDownloadCtrl(strUrl)
{
    m_spProxy = 0;
}

// @0x141873a90
CUgcDownloadBannerRollingImage::~CUgcDownloadBannerRollingImage()
{
    m_spProxy = 0;
}

// @0x141873b10
void CUgcDownloadBannerRollingImage::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcBannerRollingImageProxy* pSrc = static_cast<CUgcBannerRollingImageProxy*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcBannerRollingImageProxy> sp(new CUgcBannerRollingImageProxy);
    sp->CopyFrom(pSrc);
    m_spProxy = sp;
}
MS2_REPLACE_METHOD(0x141873b10, CUgcDownloadBannerRollingImage, AddProxy, 210, 0xD19E87E3);

// @0x141873bf0
void CUgcDownloadBannerRollingImage::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(0xce, strName);
}
MS2_REPLACE_METHOD(0x141873bf0, CUgcDownloadBannerRollingImage, MakePath, 238, 0x0419C4B2);

// @0x141873cf0
void CUgcDownloadBannerRollingImage::ProcessResult()
{
    if (m_nResult == 0)
    {
        int nCount = (int)m_spProxy->m_images.size();
        for (int i = 0; i < nCount; i++)
        {
            int nBannerId = m_spProxy->m_images[i];
            FUN_14052d220()->FUN_141888420(nBannerId, m_strPath);
        }
    }
}
MS2_REPLACE_METHOD(0x141873cf0, CUgcDownloadBannerRollingImage, ProcessResult, 241, 0x4059AD94);

// @0x141873df0
CUgcDownloadBlueprintImage::CUgcDownloadBlueprintImage(CString strUrl) : CUgcDownloadCtrl(strUrl), m_list(10)
{
}

// @0x141873e90
CUgcDownloadBlueprintImage::~CUgcDownloadBlueprintImage()
{
    m_list.RemoveAll();
}

// @0x141873f00
// MS2-FUNCTIONAL: the exe moves pProxy through an extra pointer temp before the downcast (two-level proxy
// classes); no cast form tried reproduces it
void CUgcDownloadBlueprintImage::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcBlueprintImageProxy* pSrc = static_cast<CUgcBlueprintImageProxy*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcBlueprintImageProxy> sp(new CUgcBlueprintImageProxy);
    sp->CopyFrom(pSrc);
    m_list.AddTail(sp);
}
MS2_REPLACE_METHOD(0x141873f00, CUgcDownloadBlueprintImage, AddProxy, 229, 0x310B017A);

// @0x141873ff0
void CUgcDownloadBlueprintImage::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(9, strName);
}
MS2_REPLACE_METHOD(0x141873ff0, CUgcDownloadBlueprintImage, MakePath, 238, 0x29CDD6AB);

// @0x1418740f0
void CUgcDownloadBlueprintImage::ProcessResult()
{
    if (m_nResult == 0)
    {
        CString strUrl = FUN_1410272e0(m_strUrl);
        MS2Ptr<CItem> spItem(0);
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcBlueprintImageProxy> sp = m_list.GetAt(pos);
            if (sp == 0)
                continue;
            NotifyUgcDownloadComplete* pNotify = new NotifyUgcDownloadComplete(9, m_strUrl, m_strPath);
            if (pNotify)
                pNotify->m_uid = sp->m_n18;
            FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(pNotify));
        }
    }
    Unk_UgcLog(GetLogString(), 0xc, 0x13, L"[CUgcDownloadBlueprintImage::ProcessResult] proxy count = {0}",
               m_list.GetCount());
}
MS2_REPLACE_METHOD(0x1418740f0, CUgcDownloadBlueprintImage, ProcessResult, 717, 0x83300BF5);

// @0x1418743d0
int CUgcDownloadBlueprintImage::OnDownloaded()
{
    FUN_1414a5800()->Push(m_strUrl, m_strPath, m_param.m_nType, m_param.m_upload.m_uid);
    return 1;
}
MS2_REPLACE_METHOD(0x1418743d0, CUgcDownloadBlueprintImage, OnDownloaded, 196, 0x874239FC);

// @0x1418744a0
CUgcDownloadBlueprintIcon::CUgcDownloadBlueprintIcon(CString strUrl) : CUgcDownloadCtrl(strUrl), m_list(10)
{
}

// @0x141874540
CUgcDownloadBlueprintIcon::~CUgcDownloadBlueprintIcon()
{
    m_list.RemoveAll();
}

// @0x1418745b0
// MS2-FUNCTIONAL: the exe moves pProxy through an extra pointer temp before the downcast (two-level proxy
// classes); no cast form tried reproduces it
void CUgcDownloadBlueprintIcon::AddProxy(IUgcProxy* pProxy)
{
    if (pProxy == NULL)
        return;
    CUgcItemIconPC* pSrc = static_cast<CUgcItemIconPC*>(pProxy);
    if (pSrc == NULL)
        return;
    MS2Ptr<CUgcItemIconPC> sp(new CUgcItemIconPC);
    sp->CopyFrom(pSrc);
    m_list.AddTail(sp);
}
MS2_REPLACE_METHOD(0x1418745b0, CUgcDownloadBlueprintIcon, AddProxy, 229, 0x3AA0C9F0);

// @0x1418746a0
void CUgcDownloadBlueprintIcon::MakePath()
{
    if (m_strUrl.GetLength() == 0)
        return;
    CString strName = FUN_1410272e0(m_strUrl);
    m_strPath = FUN_1410280d0(0xd1, strName);
}
MS2_REPLACE_METHOD(0x1418746a0, CUgcDownloadBlueprintIcon, MakePath, 238, 0x6D161295);

// @0x1418747a0
void CUgcDownloadBlueprintIcon::ProcessResult()
{
    if (m_nResult == 0)
    {
        Unk_UgcPlayer* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC == NULL)
            return;
        CString strUrl = FUN_1410272e0(m_strUrl);
        MS2Ptr<CItem> spItem(0);
        for (POSITION pos = m_list.GetHeadPosition(); pos; m_list.GetNext(pos))
        {
            MS2Ptr<CUgcItemIconPC> sp = m_list.GetAt(pos);
            if (sp == 0)
                continue;
            if (sp->m_nKind == 2)
                FUN_140bc09f0()->OnItemIcon(sp->m_itemUid, strUrl);
            else if (sp->m_nKind == 3)
                FUN_140bc09f0()->OnCallBackIcon(&sp->m_callBack, m_strPath);
        }
    }
    Unk_UgcLog(GetLogString(), 0xc, 0x13, L"[CUgcDownloadBlueprintIcon::ProcessResult] proxy count = {0}",
               m_list.GetCount());
}
MS2_REPLACE_METHOD(0x1418747a0, CUgcDownloadBlueprintIcon, ProcessResult, 661, 0x772FA1E7);

// ---- CUgcDownloadDown ---------------------------------------------------------------------------------------------

// @0x141874a40
CUgcDownloadDown::CUgcDownloadDown() : m_mapWait(10), m_mapActive(10), m_mapAll(10), m_hEvent(NULL), m_bStop(0)
{
    m_hSemaphore = CreateSemaphoreA(NULL, 0, 0x7fffffff, NULL);
}

// @0x141874b40
CUgcDownloadDown::~CUgcDownloadDown()
{
    if (m_hSemaphore)
        CloseHandle(m_hSemaphore);
    if (m_hEvent)
        CloseHandle(m_hEvent);
}

// @0x141874c20
unsigned int CUgcDownloadDown::vfunc_1(void* pParam, Unk_140659080& start)
{
    m_hEvent = CreateEventA(NULL, FALSE, FALSE, NULL);
    if (m_hEvent == NULL)
    {
        start.FUN_140659080(E_FAIL);
        return -1;
    }
    start.FUN_1401d42d0();
    while (FALSE != TRUE)
    {
        WaitForSingleObject(m_hSemaphore, INFINITE);
        if (m_bStop)
            break;
        CAtlList<MS2Ptr<CUgcDownloadCtrl> > batch(10);
        if (Unk_LockGuard guard = m_lock)
        {
        }
        else
        {
            if (m_mapWait.GetCount() == 0)
                continue;
            if (m_mapActive.GetCount() >= 10)
                continue;
            int nActive = 0;
            POSITION pos = m_mapWait.GetHeadPosition();
            while (pos)
            {
                POSITION posCur = pos;
                m_mapWait.GetNext(pos);
                MS2Ptr<CUgcDownloadCtrl> sp = m_mapWait.GetValueAt(posCur);
                if (sp.get())
                {
                    m_mapActive.SetAt(sp->GetUrl(), sp);
                    batch.AddTail(sp);
                }
                m_mapWait.RemoveAt(posCur);
                nActive = m_mapActive.GetCount();
                if (nActive >= 10)
                    break;
            }
        }
        if (batch.GetCount() > 0)
        {
            for (POSITION pos = batch.GetHeadPosition(); pos; batch.GetNext(pos))
            {
                MS2Ptr<CUgcDownloadCtrl> sp = batch.GetAt(pos);
                if (sp == 0)
                    continue;
                if (sp->m_param.m_bLocal == 0)
                {
                    sp->Start();
                }
                else
                {
                    if (FUN_140302b00() && FUN_140302b00()->FUN_14046d0d0(0xb)->FUN_1407d1210(sp->m_param.m_nType))
                        continue;
                    sp->MakePath();
                    FUN_1414a5800()->Push(sp->m_param.m_strUrl, sp->GetPath(), sp->m_param.m_nType,
                                          sp->m_param.m_upload.m_uid);
                }
            }
            batch.RemoveAll();
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141874c20, CUgcDownloadDown, vfunc_1, 1302, 0x49904C9A);

// @0x141875140
void CUgcDownloadDown::Stop()
{
    if (m_hEvent)
        SetEvent(m_hEvent);
    if (m_hSemaphore)
    {
        m_bStop = 1;
        ReleaseSemaphore(m_hSemaphore, 1, NULL);
        FUN_1401d3510(INFINITE);
    }
    unsigned int nStart = FUN_140869420();
    while (FALSE != TRUE)
    {
        unsigned int nElapsed = FUN_140869420() - nStart;
        if (nElapsed > 10000)
            break;
        if (IsIdle() == 1)
            break;
        Sleep(1000);
    }
}
MS2_REPLACE_METHOD(0x141875140, CUgcDownloadDown, Stop, 189, 0x1FF1276A);

// @0x141875210
int CUgcDownloadDown::Push(CUgcDownloadParam* pParam, IUgcProxy* pProxy)
{
    if (pParam == NULL)
        return 0;
    if (pProxy == NULL)
        return 0;
    CString strUrl = pParam->m_strUrl;
    int nType = pParam->m_nType;
    MS2Ptr<CUgcDownloadCtrl> sp(0);
    int bNew = 0;
    if (strUrl.GetLength() == 0)
        return 0;
    if (FUN_140302b00() && FUN_140302b00()->FUN_14046d0d0(0xb)->FUN_1407d1210(nType))
        return 0;
    if (nType == 1 || nType == 2 || nType == 0xc9 || nType == 3 || nType == 5 || nType == 6 || nType == 8 ||
        nType == 7 || nType == 0xce || nType == 9 || nType == 0xd1 || nType == 10)
        strUrl = FUN_141027200(strUrl);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_mapAll.Lookup(strUrl, sp);
        if (sp == 0)
        {
            switch (nType)
            {
            case 1:
                sp.AssignRaw(new CUgcDownloadEquip(strUrl));
                break;
            case 2:
                sp.AssignRaw(new CUgcDownloadCube(strUrl));
                break;
            case 0xc9:
                sp.AssignRaw(new CUgcDownloadItemIcon(strUrl));
                break;
            case 3:
                sp.AssignRaw(new CUgcDownloadBanner(strUrl));
                break;
            case 5:
                sp.AssignRaw(new CUgcDownloadProfile(strUrl));
                break;
            case 10:
                sp.AssignRaw(new CUgcDownloadWeddingProfile(strUrl));
                break;
            case 6:
                sp.AssignRaw(new CUgcDownloadGuildMark(strUrl));
                break;
            case 8:
                sp.AssignRaw(new CUgcDownloadGuildPoster(strUrl));
                break;
            case 7:
                sp.AssignRaw(new CUgcDownloadRidee(strUrl));
                break;
            case 0xca:
                sp.AssignRaw(new CUgcDownloadBannerAdvertise(strUrl));
                break;
            case 0xcb:
                sp.AssignRaw(new CUgcDownloadShopBanner(strUrl));
                break;
            case 0xcc:
            case 0xcf:
            case 0xd2:
                sp.AssignRaw(new CUgcDownloadShopBanner(strUrl));
                break;
            case 0xcd:
                sp.AssignRaw(new CUgcDownloadAdBanner(strUrl));
                break;
            case 0xce:
                sp.AssignRaw(new CUgcDownloadBannerRollingImage(strUrl));
                break;
            case 9:
                sp.AssignRaw(new CUgcDownloadBlueprintImage(strUrl));
                break;
            case 0xd1:
                sp.AssignRaw(new CUgcDownloadBlueprintIcon(strUrl));
                break;
            }
            if (sp == 0)
                return 0;
            sp->m_param.CopyFrom(pParam);
            m_mapAll.SetAt(strUrl, sp);
            bNew = 1;
        }
        sp->AddProxy(pProxy);
        if (sp.get() && bNew == 1)
            m_mapWait.SetAt(strUrl, sp);
    }
    if (sp.get() && bNew == 1)
        ReleaseSemaphore(m_hSemaphore, 1, NULL);
    return 1;
}
MS2_REPLACE_METHOD(0x141875210, CUgcDownloadDown, Push, 3440, 0x95FC903A);

// @0x1418760a0
void CUgcDownloadDown::Finish(CString strName, int nResult)
{
    MS2Ptr<CUgcDownloadCtrl> sp(0);
    BOOL bSignal = FALSE;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_mapActive.Lookup(strName, sp);
        if (sp.get())
        {
            m_mapActive.RemoveKey(strName);
            m_mapAll.RemoveKey(strName);
        }
        if (m_mapWait.GetCount() > 0 && m_mapActive.GetCount() < 10)
            bSignal = TRUE;
    }
    if (bSignal)
        ReleaseSemaphore(m_hSemaphore, 1, NULL);
    FUN_14052d220()->FUN_141886190(strName, sp, nResult);
}
MS2_REPLACE_METHOD(0x1418760a0, CUgcDownloadDown, Finish, 488, 0x13F3FE12);

// @0x141876290
int CUgcDownloadDown::IsIdle()
{
    int bIdle = 1;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        for (POSITION pos = m_mapAll.GetHeadPosition(); pos; m_mapAll.GetNext(pos))
        {
            MS2Ptr<CUgcDownloadCtrl> sp = m_mapAll.GetValueAt(pos);
            if (sp.get() && sp->m_pThread)
            {
                bIdle = 0;
                break;
            }
        }
    }
    return bIdle;
}
MS2_REPLACE_METHOD(0x141876290, CUgcDownloadDown, IsIdle, 253, 0xBA4B1D23);
