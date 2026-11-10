// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIRealEstateDialog: the house info dialog. See uirealestatedialog.h.
// MS2-UNIT: ?\uirealestatedialog.cpp
// MS2-RANGE: 0x14011b620-0x14011b740 .text$di
// MS2-RANGE: 0x141ab20e0-0x141ab5d50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uirealestatedialog.h"
#include "uimessagebox.h"
#include "uiservice.h"
#include "uimessageboxdata.h"
#include "uiugcmodelhousedialog.h"
#include "networkservice.h"
#include <atlcoll.h>
#include <atltime.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/userugcmapinfo.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/commonfiles/ugcmapdata.h"
#include "ms2/commonfiles/achievedata.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/uiugceventdispatcher.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include <efd/SmartPointer.h>   // C3: efd::SmartPointer<CubeMapInformationService> (the house service pointer)
#include "ms2/commonfiles/commonstringtable.h"   // C3: CommonString::GetChecker, CBanTextChecker::CheckHomeName
#include "ms2/client/ms2/achievemanager.h"       // C3: CAchieveManager::IsCompleted
#include "ms2/client/ms2/inventory.h"            // C3: Unk_Inventory::FUN_140a5f180
#include "ms2/client/ms2/addresstable.h"         // C3: CAddressTable::GetText
#include "ms2/placeholder/formatstringid.h"      // C3: FormatStringId<...>

MS2_EMIT_CRT_MEMMOVE_S();

// The statics of the common header (the sort names, "skill" and "stun").
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// ---- unit-local views of exe types ----

class Unk_ReWorld { public: MyPC* GetLocalPlayer(); };                // the local player

// The user report record (ctor 0x140c74fc0, 0x118 bytes; the same view as uicommon.cpp).
class CUserReportData : public CPtred
{
public:
    CUserReportData(int nType);                                     // 0x140c74fc0
    void SetField28(int nKind);
    void SetFielda0(__int64 nTargetId);
    void SetFieldb8(CStringW strTargetName);                     // by value: the callee destroys it
    void SetTitle(CStringW strReporterName);
    void SetField70(int n);
    void SetField74(int n);
    void SetField68(__int64 n);
    MS2_LAYOUT_FRIEND;
private:
    void* m_pad_18; void* m_pad_20; void* m_pad_28;
    void* m_pad_30; void* m_pad_38; void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58;
    void* m_pad_60;
    __int64 m_68;
    int m_70;
    int m_74;
    void* m_pad_78; void* m_pad_80; void* m_pad_88; void* m_pad_90; void* m_pad_98; void* m_pad_a0;
    void* m_pad_a8; void* m_pad_b0; void* m_pad_b8; void* m_pad_c0; void* m_pad_c8; void* m_pad_d0;
    void* m_pad_d8; void* m_pad_e0; void* m_pad_e8; void* m_pad_f0; void* m_pad_f8; void* m_pad_100;
    void* m_pad_108; void* m_pad_110;
};
MS2_CHECK_SIZE(CUserReportData, 0x118);

// The house service: the smart pointer to it (8 bytes; the glue COMDATs live in the unit that first used it).
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
// C3: Unk_Service6100017 (the house service, CLASS_ID 0x06100017) was CubeMapInformationService (cubemapinformationservice_3.h)
//
//
//
//
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 egf::g_bapiContext
// C3: Unk_HoService (FUN_1410d3360, the owners of the plots) was CubeMapInformationService
//
//
//
//
//
//
template <> efd::SmartPointer<CubeMapInformationService>::SmartPointer(CubeMapInformationService* pObject);   // 0x1401cd0b0
template <> efd::SmartPointer<CubeMapInformationService>::~SmartPointer();                             // 0x1401cd150

class Unk_NametagTrophy* GetAchieveManager();   // C3: was GetAchieveManager
class Unk_Inventory;
extern Unk_Inventory g_143ab2a90;   // C3: the real global (0x143ab2a90); read through Unk_ReInv
extern __int64 DAT_143ab2898;                                       // the money
extern __int64 DAT_143ab2820;                                       // my account id

// The root script object, as the Invoke back end sees it.
class Unk_ReScript
{
public:
    Scaleform::GFx::Value InvokeInt(const char* szMethod, int a1);
};
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
namespace Scaleform { namespace GFx { class Movie; } }
Scaleform::GFx::Movie* GetMovie(int nMovieId);                                // the movie of a UI layer
class Unk_ReObj : public ASObj { public: void FUN_141ab5b30(const char* szName, int n); };

bool FUN_14053f8c0(unsigned nItemId);                               // the item is meso
bool FUN_14053f940(unsigned nItemId);                               // the item is merat
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_1408a0d30(int nGroup, Unk_UGCGroup& rResult, int nMapId);
int FUN_1408a09d0(unsigned* pnItem, __int64* pnPrice, int nMapId, int nGroup);
int FUN_1408a0b80(unsigned* pnItem, __int64* pnPrice, int nMapId, int nGroup);
int FUN_1408a0890(int nMapId, int nGroup, int* pnKind);
Unk_CubeOwnerPtr FindCubeOwner(Unk_CubeOwners& owners, int nMapId, int nBlockId);
__int64 GetServerTime();                                            // the server time
int GetLanguage();                                                // client language
CStringW FUN_14083bab0(const CMsTime& time, CStringW strSep);
CStringW FUN_1409404f0(__int64 n);                                  // a number with thousand separators
CStringW FUN_140719a00(long long n);                                // integer text
CStringW GetStringCommon(int nStringId);
CStringW FUN_14016a730(const char* psz, int nCodePage);
CStringW FUN_14093bad0(int nId, int nGrade, CStringW strFormat);    // the trophy requirement text
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
#include "ms2/placeholder/blockformat.h"   // C3: BlockFormat<...> over FUN_14028dee0 by its real name (was BlockFormat(int, const ArgList&))
int FUN_1418fc760(char const*, void*, int, void*);   // C3: was FUN_1418fc760
void ShowMessageBox(CStringW text, int nType, void* p, CStringW tag);
void FUN_140d74640(void* p, int nBit, int nIdA, int nIdB);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int, int, void*, CStringW);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_14151f200();
UIMessageBox* GetMessageBoxLayer();
int FUN_140d74e80(CStringW& str);
int FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szDelim, int nMax);
void FUN_140710590(COutPacket& packet);
UIUGCModelHouseDialog* FindUGCModelHouseDialog(int nClass);

// @0x14011b620
// (the dynamic initializers of the three statics above are emitted from the statics' declarations)

// @0x141ab20e0
UIRealEstateDialog::UIRealEstateDialog()
    : m_nGroup(0), m_nMapId(0)
{
    SetTweenEnabled(1);
}

// @0x141ab21a0
UIRealEstateDialog::~UIRealEstateDialog()
{
}

// @0x141ab2220
CString UIRealEstateDialog::GetTypeName()
{
    return "RealEstateDialog";
}

// @0x141ab2270
int UIRealEstateDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x141ab22a0
void UIRealEstateDialog::vfunc_67()
{
    vfunc_47(1);
    UIDialog::vfunc_67();
    TSingleton<UIUGCEventDispatcher>::GetInstance()->RemoveListener(static_cast<UIUGCEventListener*>(this));
}

// @0x141ab2310
void UIRealEstateDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141ab42a0();
    TSingleton<UIUGCEventDispatcher>::GetInstance()->AddListener(static_cast<UIUGCEventListener*>(this));
}

// @0x141ab2370
void UIRealEstateDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (vfunc_55() == 0)
    {
        if (m_30.IsNull())
            return;
    }
}

// @0x141ab23d0
void UIRealEstateDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    vfunc_47(0);
}

// @0x141ab2410
int UIRealEstateDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC == 0)
        return 1;
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)(pArgs), nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    else if (_stricmp("OnContract", szMethod) == 0)
    {
        Unk_UGCGroup group;
        if (FUN_1408a0d30(m_nGroup, group, m_nMapId) == 0)
            return 1;
        unsigned int nTrophy = group.trophyID;
        if (pPC->HasNoHome() == 0 && pPC->FUN_141527ed0() != 0)
        {
            ShowMessageBox(GetStringCommon(0x7f5), 0, 0, CStringW(L""));
        }
        else if (nTrophy > 0 && reinterpret_cast<CAchieveManager*>(GetAchieveManager())->IsCompleted(nTrophy) == 0)
        {
            MS2Ptr<CAchieveData> spTrophy = GetAchieveData(nTrophy);
            if (spTrophy.get() != 0)
                ShowMessageBox(FormatStringId(0x7f6, FUN_14093bad0(nTrophy, spTrophy->m_nMaxGrade, CStringW(L""))), 0, 0, CStringW(L""));
        }
        else
            FUN_140d74640(static_cast<IMessageListener*>(this), 8, 0x7fb, 0x7fc);
        return 1;
    }
    else if (_stricmp("OnReport", szMethod) == 0)
    {
        MS2Ptr<CUserReportData> spReport(new CUserReportData(4));
        spReport->SetField28(1);
        spReport->SetField68(m_nOwnerId);
        spReport->SetTitle(m_strOwnerName);
        spReport->SetField70(m_nMapId);
        spReport->SetField74(m_nGroup);
        spReport->SetFielda0(m_nOwnerId);
        spReport->SetFieldb8(m_strOwnerName);
        FUN_140d86260()->vfunc_48(spReport);
        return 1;
    }
    else if (_stricmp("OnChangeHomeName", szMethod) == 0)
    {
        {
            MS2Ptr<CMsgBoxData> box = FUN_140d73e40(10, 0x23, static_cast<IMessageListener*>(this), CStringW(L"changeHomeName"));
            if (box.get() != 0)
            {
                CStringW strEmpty(L"");
                box->SetInput(3, strEmpty, 0x10, 0, 0);
                FUN_140d73c60(box);
            }
        }
        return 1;
    }
    else if (_stricmp("onChangeAuth", szMethod) == 0)
    {
    }
    else if (_stricmp("onRenew", szMethod) == 0)
    {
        __int64 nNotice = *GetClientConstants()->UgcHomeExtensionNoticeDate.Get() * 60 * 60 * 24;
        Unk_BmPtr<UserUGCMapInfo> target(pPC->GetUGCMapInfo());
        if ((target.get() ? true : false) && target->m_n30 - GetServerTime() > nNotice)
        {
            __int64 nExpire = target->m_n30 - nNotice;
            CStringW strExpire = FormatDateTime(nExpire);
            ShowMessageBox(FUN_14028dee0(1999, *GetClientConstants()->UgcHomeExtensionNoticeDate.Get(), strExpire), 0, 0, CStringW(L""));
        }
        else
        {
            Unk_UGCGroup group;
            if (FUN_1408a0d30(m_nGroup, group, m_nMapId) == 0)
                return 0;
            unsigned nItem = 0;
            __int64 nPrice = 0;
            FUN_1408a0b80(&nItem, &nPrice, m_nMapId, m_nGroup);
            int nDays = group.extensionDate;
            if (FUN_14053f8c0(nItem))
                ShowMessageBox(FUN_14028dee0(0x7d1, nDays, FUN_1409404f0(nPrice)), 1, static_cast<IMessageListener*>(this), CStringW(L"onExtension"));
            else if (FUN_14053f940(nItem))
                ShowMessageBox(FUN_14028dee0(2000, nDays, FUN_1409404f0(nPrice)), 1, static_cast<IMessageListener*>(this), CStringW(L"onExtension"));
            else
                ShowMessageBox(FUN_14028dee0(0x7d2, nDays, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItem), nPrice), 1, static_cast<IMessageListener*>(this), CStringW(L"onExtension"));
            return 1;
        }
    }
    else if (_stricmp("onSell", szMethod) == 0)
        TSingleton<CUIService>::GetInstance()->ToggleDialog((eUIClassID)0x4e82);
    return 0;
}

// @0x141ab31f0
void UIRealEstateDialog::vfunc_ugc_5()
{
    if (vfunc_55() != 0)
        return;
    SetContractEffect();
}

// @0x141ab3250
int UIRealEstateDialog::FUN_141ab3250(const CStringW& strName)
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC == 0)
        return 1;
    if (CBanTextChecker* pFilter = ((class CommonString*)TSingleton<CommonString>::GetInstance())->GetChecker())
    {
        CStringW strError;
        if (pFilter->CheckHomeName(strName, strError) == 0)
        {
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.WriteUInt8(0x15);
            packet.WriteUnicodeString(strName);
            FUN_140710590(packet);
        }
        else
        {
            if (pPC->HasNoHome() == 0)
                SetHomeName(pPC->GetHomeName());
            UIMessageBox* pBox = GetMessageBoxLayer();
            if (pBox != 0)
                ((class UIMessageBox*)(class UIMessageBox*)(pBox))->UpdateErrorMessage(strError);
            return 0;
        }
    }
    return 1;
}

// @0x141ab3400
void UIRealEstateDialog::vfunc_ugc_7(int bRefresh)
{
    if (vfunc_55() != 0)
        return;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC != 0 && pPC->HasNoHome() == 0)
    {
        SetHomeName(pPC->GetHomeName());
        if (bRefresh != 0 && pPC->GetUGCMapInfo() != 0)
        {
            if (pPC->FUN_141527ed0() != 0)
            {
                SetExpireDate(&pPC->GetUGCMapInfo()->m_n30);
                m_30->Invoke("setContractEffect", bRefresh);
            }
            else
            {
                __int64 nTime = 0;
                int nState = 0;
                efd::SmartPointer<CubeMapInformationService> spSvc(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
                if ((CubeMapInformationService*)spSvc ? true : false)
                {
                    if (reinterpret_cast<CubeMapInformationService*>(spSvc.operator->())->FUN_1410c8470(m_nGroup, m_nMapId, &nState, &nTime) != 0)
                    {
                        CMsTime tWait(nTime + *GetClientConstants()->UgcHomeSaleWaitingTime.Get());
                        m_30->Invoke("setWaitingDate", BlockFormat(0x7dd, tWait.GetYear(), tWait.GetMonth(), tWait.GetDay(), tWait.GetHour(), tWait.GetMinute()));
                    }
                }
            }
        }
    }
}

// @0x141ab3760
void UIRealEstateDialog::SetHomeName(CStringW strName)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    m_30->Invoke("setHomeName", CStringW(strName));
}

// @0x141ab3820
void UIRealEstateDialog::SetContractEffect()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC != 0 && pPC->HasNoHome() == 0)
        SetExpireDate(&pPC->GetUGCMapInfo()->m_n30);
    if (m_30.get() != 0)
        m_30->Invoke("setContractEffect", 1);
}

// @0x141ab38e0
void UIRealEstateDialog::SendRequestCubeMode2()
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC == 0)
        return;
    if (pPC->HasNoHome() != 0)
    {
        UIUGCModelHouseDialog* pDlg = FindUGCModelHouseDialog(0x4f3f);
        if (pDlg != 0)
            SetPlot(pDlg, m_nGroup);
        if (TSingleton<CUIService>::GetInstance()->IsDialogClosed((eUIClassID)0x4f3f) != 0)
            TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)0x4f3f);
    }
    else
    {
        int nIndex = 0;
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.WriteUInt8(2);
        packet.WriteInt32(m_nGroup);
        packet.WriteInt32(nIndex);
        FUN_140710590(packet);
    }
}

// @0x141ab39f0
int UIRealEstateDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nAnswer = pMsg->PopInt();
        CStringW strTag = pMsg->FUN_1422b8f40();
        ATL::CAtlArray<CStringW> aParts;
        if (nAnswer == 0)
        {
            if (FUN_140d74e80(strTag) != 0)
            {
                SendRequestCubeMode2();
            }
            else
            {
                if (strTag == "onExtension")
                {
                    FUN_14151f200();
                    Unk_UGCGroup group;
                    if (FUN_1408a0d30(m_nGroup, group, m_nMapId) == 0)
                        return 0;
                    unsigned nItem = 0;
                    __int64 nPrice = 0;
                    FUN_1408a0b80(&nItem, &nPrice, m_nMapId, m_nGroup);
                    if (FUN_14053f8c0(nItem))
                    {
                        if (DAT_143ab2898 < nPrice)
                        {
                            efd::SmartPointer<CubeMapInformationService> spSvc(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
                            ShowMessageBox(spSvc->GetMessageText(0x43), 0, 0, CStringW(L""));
                            return 1;
                        }
                    }
                    else if (FUN_14053f940(nItem))
                    {
                        if (!FUN_140d86260()->vfunc_40(nPrice))
                        {
                            TSingleton<CUIService>::GetInstance()->FUN_141add1f0();
                            return 1;
                        }
                    }
                    else if (g_143ab2a90.FUN_140a5f180(nItem, 0) < nPrice)
                    {
                        efd::SmartPointer<CubeMapInformationService> spSvc(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
                        ShowMessageBox(spSvc->GetMessageText(0x43), 0, 0, CStringW(L""));
                        return 1;
                    }
                    COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
                    packet.WriteUInt8(9);
                    FUN_140710590(packet);
                }
                else
                {
                    FUN_14028cb70(strTag, aParts, L",", 2);
                    if (aParts[0] == L"changeHomeName")
                    {
                        CStringW strName(aParts[1]);
                        if (aParts.GetCount() > 2)
                        {
                            strName = strTag;
                            strName.Replace(L"changeHomeName,", L"");
                        }
                        if (FUN_141ab3250(strName) != 0)
                            FUN_14151f200();
                        return 1;
                    }
                }
            }
        }
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x141ab4000
void UIRealEstateDialog::SetGroupAndMapId(int nGroup, int nMapId)
{
    m_nGroup = nGroup;
    m_nMapId = nMapId;
}

// @0x141ab4040
void UIRealEstateDialog::SetExpireDate(const __int64* pnTime)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    if (*pnTime != 0)
    {
        int nLang = GetLanguage();
        CMsTime tTime(*pnTime);
        int nDay = tTime.GetDay();
        int nMonth = tTime.GetMonth();
        int nYear = tTime.GetYear();
        CStringW strDate = FUN_14028dee0(0x7d9, nYear, nMonth, nDay);
        if (nLang != 0)
            strDate = FUN_14083bab0(tTime, CStringW(L"/"));
        int nMinute = tTime.GetMinute();
        int nHour = tTime.GetHour();
        CStringW strTime = FormatStringId(0x7da, nHour, nMinute);
        m_30->Invoke("setExpireDate", CStringW(strDate), CStringW(strTime));
    }
}

// @0x141ab42a0
void UIRealEstateDialog::FUN_141ab42a0()
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC == 0)
        return;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull() != 0)
        return;
    void* pMovie = GetMovie(m_28);
    if (pMovie == 0)
        return;
    ASObj obj(2);
    efd::SmartPointer<CubeMapInformationService> spSvc(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
    CStringW strMapName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, m_nMapId);
    Unk_UGCGroup group;
    if (FUN_1408a0d30(m_nGroup, group, m_nMapId) == 0)
        return;
    int bOwn = 0;
    int bBlocked = 0;
    int bContractable = 0;
    int nState;
    __int64 nTime;
    if (pPC->HasNoHome() == 0)
    {
        Unk_BmPtr<UserUGCMapInfo> target(pPC->GetUGCMapInfo());
        if (m_nMapId == target->m_n20 && m_nGroup == target->m_n24)
            bOwn = 1;
    }
    m_strOwnerName = "";
    m_nOwnerId = 0;
    if (bOwn != 0)
    {
        reinterpret_cast<Unk_ReScript*>(m_30.operator->())->InvokeInt("initMyHouse", 0);
        SetExpireDate(&pPC->GetUGCMapInfo()->m_n30);
        m_30->Invoke("setContractEffect", 0);
        SetHomeName(pPC->GetHomeName());
    }
    else
    {
        if (reinterpret_cast<CubeMapInformationService*>(spSvc.operator->())->FUN_1410c8470(m_nGroup, m_nMapId, &nState, &nTime) != 0)
        {
            reinterpret_cast<Unk_ReScript*>(m_30.operator->())->InvokeInt("initMyHouse", nState == 4 ? 2 : 1);
            if (nState == 4)
            {
                CMsTime tWait(nTime + *GetClientConstants()->UgcHomeSaleWaitingTime.Get());
                m_30->Invoke("setWaitingDate", BlockFormat(0x7dd, tWait.GetYear(), tWait.GetMonth(), tWait.GetDay(), tWait.GetHour(), tWait.GetMinute()));
            }
            else if (nState == 1)
            {
                CStringW strOwner;
                int nBlock = 0;
                int nKind = 0;
                FUN_1408a0890(m_nMapId, m_nGroup, &nKind);
                if (nKind == 0)
                    nBlock = 0;
                else if (nKind == 1)
                    nBlock = 1;
                else
                    nBlock = reinterpret_cast<CubeMapInformationService*>(spSvc.operator->())->FUN_1410c3000();
                {
                    Unk_CubeOwners& rOwners = *reinterpret_cast<CubeMapInformationService*>(spSvc.operator->())->FUN_1410d3360();
                    Unk_CubeOwnerPtr spOwner = FindCubeOwner(rOwners, m_nGroup, nBlock);
                    if (spOwner.get() != 0)
                    {
                        strOwner = spOwner->ownerName;
                        m_strOwnerName = strOwner;
                        m_nOwnerId = spOwner->ownerID;
                    }
                }
                SetHomeName(CStringW(strOwner));
                SetExpireDate(&nTime);
                m_30->Invoke("setContractEffect", 0);
            }
        }
        else
        {
            bContractable = 1;
            reinterpret_cast<Unk_ReScript*>(m_30.operator->())->InvokeInt("initMyHouse", 2);
        }
    }
    strMapName = CAddressTable::GetText(m_nMapId);
    obj.SetWStringMember("buildingName", CStringW(strMapName));
    CStringW strContract;
    strContract = BlockFormat<int>(0x7ce, group.contractDate);
    obj.SetWStringMember("contractDate", CStringW(strContract));
    unsigned nItem = 0;
    __int64 nPrice = 0;
    FUN_1408a09d0(&nItem, &nPrice, m_nMapId, m_nGroup);
    unsigned nExtItem = 0;
    __int64 nExtPrice = 0;
    FUN_1408a0b80(&nExtItem, &nExtPrice, m_nMapId, m_nGroup);
    __int64 nShown = nPrice;
    if (group.FUN_1408ad2c0() != 0)
        obj.SetIntMember("priceType", 0);
    else if (group.FUN_1408ad2f0() != 0)
        obj.SetIntMember("priceType", 1);
    else
    {
        obj.SetIntMember("priceType", 2);
        obj.SetMemberUInt("item", nItem);
        MS2Ptr<CItemData> spData = FUN_14053f870(nItem);
        if (spData.get() != 0)
        {
            obj.SetStringMember("icon", spData->GetIconPath());
            obj.SetWStringMember("itemName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItem));
        }
    }
    obj.SetWStringMember("price", FUN_140719a00(nShown));
    obj.SetWStringMember("contractPrice", FUN_140719a00(nPrice));
    obj.SetWStringMember("extensionPrice", FUN_140719a00(nExtPrice));
    CStringW strDesc(L"");
    if (FUN_14053f8c0(nExtItem) || FUN_14053f940(nExtItem))
        strDesc = FUN_14028dee0(0x7df, FUN_1409404f0(nExtPrice), nExtItem);
    else
        strDesc = FUN_14028dee0(0x7e0, FUN_1409404f0(nExtPrice), nExtItem);
    TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectAndValueWords(strDesc);
    obj.SetWStringMember("description", FUN_14028dee0(0x7e1, group.contractDate, strDesc));
    static_cast<Unk_ReObj&>(obj).FUN_141ab5b30("buildingIcon", group.buildingType);
    obj.SetWStringMember("buildingType", GetStringCommon(group.buildingType + 0x7d3));
    CStringW strArea;
    strArea = FormatStringId(0x7d7, group.field30, group.heightLimit);
    obj.SetWStringMember("areaSize", CStringW(strArea));
    obj.SetBoolMember("land", 0 < group.buildingCount);
    obj.SetWStringMember("buildingCount", BlockFormat<int>(0x7d8, group.buildingCount));
    obj.SetWStringMember("preview", FUN_14016a730(group.previewIcon, 0));
    CStringW strTrophy(L"");
    unsigned int nTrophy = group.trophyID;
    if (nTrophy > 0)
    {
        MS2Ptr<CAchieveData> spTrophy = GetAchieveData(nTrophy);
        if (spTrophy.get() != 0)
            strTrophy = FormatStringId(0x7f6, FUN_14093bad0(nTrophy, spTrophy->m_nMaxGrade, CStringW(L"")));
    }
    obj.SetWStringMember("trophy", CStringW(strTrophy));
    if (bBlocked != 0)
    {
        obj.SetIntMember("contractable", 0);
        obj.SetWStringMember("contractableText", GetStringCommon(0x7f8));
        obj.SetWStringMember("trophy", GetStringCommon(0x7f9));
    }
    else
    {
        obj.SetIntMember("contractable", bContractable);
        obj.SetWStringMember("contractableText", GetStringCommon(0x7fa));
    }
    m_30->Invoke("initData", obj);
}

// @0x141ab5520
CStringW UIRealEstateDialog::FormatDateTime(const __int64& nTime)
{
    CStringW strText;
    if (nTime != 0)
    {
        CMsTime tTime(nTime);
        int nMinute = tTime.GetMinute();
        int nHour = tTime.GetHour();
        int nDay = tTime.GetDay();
        int nMonth = tTime.GetMonth();
        int nYear = tTime.GetYear();
        strText = BlockFormat(0x7de, nYear, nMonth, nDay, nHour, nMinute);
    }
    return strText;
}

// @0x141ab59f0
UIUGCModelHouseDialog* FindUGCModelHouseDialog(int nClass)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> spObject = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nClass);
        if (spObject.get() != 0)
            return dynamic_cast<UIUGCModelHouseDialog*>(spObject.operator->());
    }
    return 0;
}

// @0x141ab5a90
Scaleform::GFx::Value Unk_ReScript::InvokeInt(const char* szMethod, int a1)
{
    ASArgList args;
    args.resize(1);
    FUN_1422bccb0(&args[0], a1);
    return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(szMethod, args);
}

// @0x141ab5b30
void Unk_ReObj::FUN_141ab5b30(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc1af0-0x142cc1b60 .text$yd
