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

MS2_EMIT_CRT_MEMMOVE_S();

// The statics of the common header (the sort names, "skill" and "stun").
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// ---- unit-local views of exe types ----

CUIService* FUN_1403ed2b0();
class Unk_RdStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_RdStrings* FUN_1401a9d70();
class Unk_RdScriptFilter { public: void FUN_1416fb300(CStringW& strText); };
Unk_RdScriptFilter* FUN_1403b4750();
class Unk_TextFilter { public: };
int FUN_1402252f0(Unk_TextFilter*, const CStringW& str, CStringW& strOut);
class Unk_TextFilterPtr {
public:
    ~Unk_TextFilterPtr();                                        // 0x14025c670
    Unk_TextFilter* FUN_14025cea0() const;
    void* m_00; void* m_08;
};
class Unk_TextFilterMgr { public: Unk_TextFilterPtr FUN_140229a50(); };
Unk_TextFilterMgr* FUN_14025e7d0();
class Unk_RdPC : public MyPC { public: CStringW FUN_141528330(); int FUN_141527ed0(); };
class Unk_ReWorld { public: MyPC* FUN_141bd0cc0(); };                // the local player
Unk_ReWorld* FUN_1403ed2d0();

// The user report record (ctor 0x140c74fc0, 0x118 bytes; the same view as uicommon.cpp).
class CUserReportData : public CPtred
{
public:
    CUserReportData(int nType);                                     // 0x140c74fc0
    void FUN_140ec3c70(int nKind);
    void FUN_140ec3c90(__int64 nTargetId);
    void FUN_140ec3d40(CStringW strTargetName);                     // by value: the callee destroys it
    void FUN_140ec3e00(CStringW strReporterName);
    void FUN_141904a90(int n);
    void FUN_141904af0(int n);
    void FUN_141904b10(__int64 n);
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

// The map / group record the house stands on (the info of the owned house).
class Unk_GmTarget { public: int m_pad_0[7]; int m_1c; int m_20; int m_24; void* m_28; __int64 m_30; };
class Unk_GmTargetRef
{
public:
    Unk_GmTargetRef(void* p);                                       // 0x14050dd40
    ~Unk_GmTargetRef();                                             // 0x14050de40
    Unk_GmTarget* FUN_14050dee0();
    void* FUN_140fa9d30();                                          // the record (NULL: none)
    void* m_0;
    void* m_8;
};

// The house service: the smart pointer to it (8 bytes; the glue COMDATs live in the unit that first used it).
struct Unk_EntityAppFramework;
extern Unk_EntityAppFramework DAT_143b059e8;
class Unk_HoService : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    bool FUN_1410c8470(int nGroup, int nMapId, int* pnState, __int64* pnTime);   // the state of the plot (1 sold, 4 waiting)
    int FUN_1410c3000();
    Unk_CubeOwners* FUN_1410d3360();                                // the owners of the plots
    CStringW FUN_1410d5d80(int nStringId);
};
Unk_HoService* FUN_1401cd040(Unk_EntityAppFramework* framework);
class Unk_HoServicePtr
{
public:
    Unk_HoServicePtr(Unk_HoService* p);                             // 0x1401cd0b0
    ~Unk_HoServicePtr();                                            // 0x1401cd150
    Unk_HoService* FUN_1401cd1a0() const;                           // operator->
    Unk_HoService* FUN_140885310() const;                           // get
private:
    Unk_HoService* m_p;
};

class Unk_ReTrophy { public: int FUN_1409365a0(int nId); };         // the trophy was earned
Unk_ReTrophy* FUN_1406c7600();
class Unk_ReUgcEvents { public: void FUN_141b38be0(UIUGCEventListener* p); void FUN_141b38c70(UIUGCEventListener* p); };
Unk_ReUgcEvents* FUN_140bc09f0();
class Unk_ReInv { public: int FUN_140a5f180(unsigned nItem, int n); };   // the count of an item
extern Unk_ReInv DAT_143ab2a90;
extern __int64 DAT_143ab2898;                                       // the money
extern __int64 DAT_143ab2820;                                       // my account id

// The root script object, as the Invoke back end sees it.
class Unk_ReScript
{
public:
    Scaleform::GFx::Value FUN_141ab5a90(const char* szMethod, int a1);
};
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);
void* FUN_1422bb8b0(int nMovieId);                                  // the movie of a UI layer
class Unk_ReObj : public ASObj { public: void FUN_141ab5b30(const char* szName, int n); };

bool FUN_14053f8c0(unsigned nItemId);                               // the item is meso
unsigned char FUN_14053f940(unsigned nItemId);                      // the item is merat
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);
int FUN_1408a0d30(int nGroup, Unk_UGCGroup& rResult, int nMapId);
int FUN_1408a09d0(unsigned* pnItem, __int64* pnPrice, int nMapId, int nGroup);
int FUN_1408a0b80(unsigned* pnItem, __int64* pnPrice, int nMapId, int nGroup);
int FUN_1408a0890(int nMapId, int nGroup, int* pnKind);
Unk_CubeOwnerPtr FUN_1408a0fa0(Unk_CubeOwners& owners, int nMapId, int nBlockId);
bool FUN_140a467d0(const MS2Ptr<AScript>*);
__int64 FUN_140869440();                                            // the server time
int FUN_1406516a0();                                                // client language
CStringW FUN_14083bab0(const CMsTime& time, CStringW strSep);
CStringW FUN_140979570(int nMapId);                                 // the address of a map
CStringW FUN_1409404f0(__int64 n);                                  // a number with thousand separators
CStringW FUN_140719a00(long long n);                                // integer text
CStringW FUN_14052bd00(int nId, const CStringW& arg);
CStringW GetStringCommon(int nStringId);
CStringW FUN_14016a730(const char* psz, int nCodePage);
CStringW FUN_14093bad0(int nId, int nGrade, CStringW strFormat);    // the trophy requirement text
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
CStringW FUN_1409e90c0(int nId, const int& nYear, const int& nMonth, const int& nDay, const int& nHour, const int& nMinute);
CStringW FUN_1412e7520(int nId, const int& nYear, const int& nMonth, const int& nDay);
CStringW FUN_140811740(int nId, const int& nA, const int& nB);
CStringW FUN_1408116a0(int nId, const int& nA);
CStringW FUN_140a228f0(int nId, const int& nA, const CStringW& strB);
CStringW FUN_1412e7c20(int nId, const CStringW& strA, const int& nB);
int FUN_1418fc760(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, void* a4);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_140d74640(void* p, int nBit, int nIdA, int nIdB);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int, int, void*, CStringW);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_14151f200();
UIMessageBox* FUN_14151f890();
void FUN_1419f82b0(UIMessageBox* pBox, const CStringW& strText);
int FUN_140d74e80(const CStringW& str);
bool FUN_140841300(const CStringW& str, const char* psz);
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);
int FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szDelim, int nMax);
void FUN_140710590(COutPacket& packet);
UIUGCModelHouseDialog* FUN_141ab59f0(int nClass);

// @0x14011b620
// (the dynamic initializers of the three statics above are emitted from the statics' declarations)

// @0x141ab20e0
UIRealEstateDialog::UIRealEstateDialog()
    : m_nGroup(0), m_nMapId(0)
{
    FUN_141924170(1);
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
    return UIDialog::vfunc_65() != 0;
}

// @0x141ab22a0
void UIRealEstateDialog::vfunc_67()
{
    vfunc_47(1);
    UIDialog::vfunc_67();
    FUN_140bc09f0()->FUN_141b38c70(static_cast<UIUGCEventListener*>(this));
}

// @0x141ab2310
void UIRealEstateDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141ab42a0();
    FUN_140bc09f0()->FUN_141b38be0(static_cast<UIUGCEventListener*>(this));
}

// MS2-FUNCTIONAL: the exe returns the IsNull result (base slot is void); extra movzx only
// @0x141ab2370
void UIRealEstateDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (vfunc_55() == 0)
        m_30.IsNull();
}

// @0x141ab23d0
void UIRealEstateDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    vfunc_47(0);
}

// MS2-FUNCTIONAL: large body, temp spills / argument evaluation order differ vs exe
// @0x141ab2410
int UIRealEstateDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 1;
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    if (_stricmp("OnContract", szMethod) != 0)
    {
        if (_stricmp("OnReport", szMethod) == 0)
        {
            MS2Ptr<CUserReportData> spReport(new CUserReportData(4));
            spReport->FUN_140ec3c70(1);
            spReport->FUN_141904b10(m_nOwnerId);
            spReport->FUN_140ec3e00(m_strOwnerName);
            spReport->FUN_141904a90(m_nMapId);
            spReport->FUN_141904af0(m_nGroup);
            spReport->FUN_140ec3c90(m_nOwnerId);
            spReport->FUN_140ec3d40(m_strOwnerName);
            FUN_140d86260()->vfunc_48(spReport);
            return 1;
        }
        if (_stricmp("OnChangeHomeName", szMethod) == 0)
        {
            MS2Ptr<CMsgBoxData> box = FUN_140d73e40(10, 0x23, static_cast<IMessageListener*>(this), CStringW(L"changeHomeName"));
            if (box.get() != 0)
            {
                box->FUN_141a01d30(3, CStringW(L""), 0x10, 0, 0);
                FUN_140d73c60(box);
            }
            return 1;
        }
        if (_stricmp("onChangeAuth", szMethod) != 0)
        {
            if (_stricmp("onRenew", szMethod) == 0)
            {
                __int64 nNotice = *FUN_1401d3200()->UgcHomeExtensionNoticeDate.Get() * 0x15180;
                Unk_GmTargetRef target(pPC->FUN_141523c50());
                if (target.FUN_140fa9d30() != 0)
                {
                    if (nNotice < target.FUN_14050dee0()->m_30 - FUN_140869440())
                    {
                        __int64 nExpire = target.FUN_14050dee0()->m_30 - nNotice;
                        CStringW strExpire = FUN_141ab5520(nExpire);
                        FUN_140d73aa0(FUN_140a228f0(1999, *FUN_1401d3200()->UgcHomeExtensionNoticeDate.Get(), strExpire), 0, 0, CStringW(L""));
                        return 0;
                    }
                }
                Unk_UGCGroup group;
                if (FUN_1408a0d30(m_nGroup, group, m_nMapId) != 0)
                {
                    unsigned nItem = 0;
                    __int64 nPrice = 0;
                    FUN_1408a0b80(&nItem, &nPrice, m_nMapId, m_nGroup);
                    int nDays = group.extensionDate;
                    if (FUN_14053f8c0(nItem))
                        FUN_140d73aa0(FUN_140a228f0(0x7d1, nDays, FUN_1409404f0(nPrice)), 1, static_cast<IMessageListener*>(this), CStringW(L"onExtension"));
                    else if (FUN_14053f940(nItem))
                        FUN_140d73aa0(FUN_140a228f0(2000, nDays, FUN_1409404f0(nPrice)), 1, static_cast<IMessageListener*>(this), CStringW(L"onExtension"));
                    else
                        FUN_140d73aa0(FUN_14028dee0(0x7d2, nDays, FUN_1401a9d70()->FUN_141811980(1, nItem), nPrice), 1, static_cast<IMessageListener*>(this), CStringW(L"onExtension"));
                    return 1;
                }
                return 0;
            }
            if (_stricmp("onSell", szMethod) == 0)
                FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4e82);
        }
        return 0;
    }
    Unk_UGCGroup group;
    if (FUN_1408a0d30(m_nGroup, group, m_nMapId) == 0)
        return 1;
    if (pPC->FUN_141527e00() == 0 && static_cast<Unk_RdPC*>(pPC)->FUN_141527ed0() != 0)
    {
        FUN_140d73aa0(GetStringCommon(0x7f5), 0, 0, CStringW(L""));
    }
    else
    {
        if (group.trophyID != 0)
        {
            if (FUN_1406c7600()->FUN_1409365a0(group.trophyID) == 0)
            {
                MS2Ptr<CAchieveData> spTrophy = GetAchieveData(group.trophyID);
                if (spTrophy.get() != 0)
                {
                    CStringW strTrophy = FUN_14093bad0(group.trophyID, spTrophy->m_nMaxGrade, CStringW(L""));
                    FUN_140d73aa0(FUN_14052bd00(0x7f6, strTrophy), 0, 0, CStringW(L""));
                }
                return 1;
            }
        }
        FUN_140d74640(static_cast<IMessageListener*>(this), 8, 0x7fb, 0x7fc);
    }
    return 1;
}

// @0x141ab31f0
void UIRealEstateDialog::vfunc_ugc_5()
{
    if (vfunc_55() == 0)
        FUN_141ab3820();
}

// MS2-FUNCTIONAL: temp spills / CStringW copy placement differ vs exe
// @0x141ab3250
int UIRealEstateDialog::FUN_141ab3250(const CStringW& strName)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
    {
        Unk_TextFilterPtr filter = FUN_14025e7d0()->FUN_140229a50();
        Unk_TextFilter* pFilter = filter.FUN_14025cea0();
        if (pFilter != 0)
        {
            CStringW strError;
            if (FUN_1402252f0(pFilter, strName, strError) != 0)
            {
                if (pPC->FUN_141527e00() == 0)
                    FUN_141ab3760(static_cast<Unk_RdPC*>(pPC)->FUN_141528330());
                UIMessageBox* pBox = FUN_14151f890();
                if (pBox != 0)
                    FUN_1419f82b0(pBox, strError);
                return 0;
            }
            COutPacket packet(0x37, 0);
            packet.vfunc_o10_1(0x15);
            packet.vfunc_o10_8(strName);
            FUN_140710590(packet);
        }
    }
    return 1;
}

// MS2-FUNCTIONAL: temp spills / date composition differ vs exe
// @0x141ab3400
void UIRealEstateDialog::vfunc_ugc_7(int bRefresh)
{
    if (vfunc_55() != 0 || FUN_140a467d0(&m_30))
        return;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0 || pPC->FUN_141527e00() != 0)
        return;
    FUN_141ab3760(static_cast<Unk_RdPC*>(pPC)->FUN_141528330());
    if (bRefresh == 0 || pPC->FUN_141523c50() == 0)
        return;
    if (static_cast<Unk_RdPC*>(pPC)->FUN_141527ed0() == 0)
    {
        __int64 nTime = 0;
        int nState = 0;
        Unk_HoServicePtr spSvc(FUN_1401cd040(&DAT_143b059e8));
        if (spSvc.FUN_140885310() != 0)
        {
            if (spSvc.FUN_1401cd1a0()->FUN_1410c8470(m_nGroup, m_nMapId, &nState, &nTime) != 0)
            {
                CMsTime tWait(nTime + *FUN_1401d3200()->UgcHomeSaleWaitingTime.Get());
                int nMinute = tWait.GetMinute();
                int nHour = tWait.GetHour();
                int nDay = tWait.GetDay();
                int nMonth = tWait.GetMonth();
                int nYear = tWait.GetYear();
                m_30->Invoke("setWaitingDate", FUN_1409e90c0(0x7dd, nYear, nMonth, nDay, nHour, nMinute));
            }
        }
    }
    else
    {
        FUN_141ab4040(&pPC->FUN_141523c50()->m_n30);
        m_30->Invoke("setContractEffect", bRefresh);
    }
}

// @0x141ab3760
void UIRealEstateDialog::FUN_141ab3760(CStringW strName)
{
    if (FUN_140a467d0(&m_30) == 0)
        m_30->Invoke("setHomeName", CStringW(strName));
}

// @0x141ab3820
void UIRealEstateDialog::FUN_141ab3820()
{
    if (FUN_140a467d0(&m_30) == 0)
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0 && pPC->FUN_141527e00() == 0)
            FUN_141ab4040(&pPC->FUN_141523c50()->m_n30);
        if (m_30.get() != 0)
            m_30->Invoke("setContractEffect", 1);
    }
}

// @0x141ab38e0
void UIRealEstateDialog::SendRequestCubeMode2()
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (pPC->FUN_141527e00() == 0)
    {
        COutPacket packet(0x37, 0);
        packet.vfunc_o10_1(2);
        packet.vfunc_o10_3(m_nGroup);
        packet.vfunc_o10_3(0);
        FUN_140710590(packet);
    }
    else
    {
        UIUGCModelHouseDialog* pDlg = FUN_141ab59f0(0x4f3f);
        if (pDlg != 0)
            FUN_140faf6b0(pDlg, m_nGroup);
        if (FUN_1403ed2b0()->FUN_141adc940((eUIClassID)0x4f3f) != 0)
            FUN_1403ed2b0()->OpenDialog((eUIClassID)0x4f3f);
    }
}

// MS2-FUNCTIONAL: large body, temp spills / argument evaluation order differ vs exe
// @0x141ab39f0
int UIRealEstateDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() != 0 || dynamic_cast<UIMessageBox*>(pSender) == 0)
        return 0;
    int nAnswer = pMsg->FUN_1422b8a10();
    CStringW strTag = pMsg->FUN_1422b8f40();
    ATL::CAtlArray<CStringW> aParts;
    if (nAnswer == 0)
    {
        if (FUN_140d74e80(strTag) == 0)
        {
            if (FUN_140841300(strTag, "onExtension") == 0)
            {
                FUN_14028cb70(strTag, aParts, L",", 2);
                if (FUN_1403b3c40(aParts[0], L"changeHomeName"))
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
            else
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
                        Unk_HoServicePtr spSvc(FUN_1401cd040(&DAT_143b059e8));
                        FUN_140d73aa0(spSvc.FUN_1401cd1a0()->FUN_1410d5d80(0x43), 0, 0, CStringW(L""));
                        return 1;
                    }
                }
                else if (FUN_14053f940(nItem))
                {
                    if (!FUN_140d86260()->vfunc_40(nPrice))
                    {
                        FUN_1403ed2b0()->FUN_141add1f0();
                        return 1;
                    }
                }
                else if (DAT_143ab2a90.FUN_140a5f180(nItem, 0) < nPrice)
                {
                    Unk_HoServicePtr spSvc(FUN_1401cd040(&DAT_143b059e8));
                    FUN_140d73aa0(spSvc.FUN_1401cd1a0()->FUN_1410d5d80(0x43), 0, 0, CStringW(L""));
                    return 1;
                }
                COutPacket packet(0x37, 0);
                packet.vfunc_o10_1(9);
                FUN_140710590(packet);
            }
        }
        else
        {
            SendRequestCubeMode2();
        }
    }
    FUN_14151f200();
    return 1;
}

// @0x141ab4000
void UIRealEstateDialog::FUN_141ab4000(int nGroup, int nMapId)
{
    m_nGroup = nGroup;
    m_nMapId = nMapId;
}

// MS2-FUNCTIONAL: temp spills / CStringW copy placement differ vs exe
// @0x141ab4040
void UIRealEstateDialog::FUN_141ab4040(const __int64* pnTime)
{
    if (FUN_140a467d0(&m_30) == 0 && *pnTime != 0)
    {
        int nLang = FUN_1406516a0();
        CMsTime tTime(*pnTime);
        int nDay = tTime.GetDay();
        int nMonth = tTime.GetMonth();
        int nYear = tTime.GetYear();
        CStringW strDate = FUN_1412e7520(0x7d9, nYear, nMonth, nDay);
        if (nLang != 0)
            strDate = FUN_14083bab0(tTime, CStringW(L"/"));
        int nMinute = tTime.GetMinute();
        int nHour = tTime.GetHour();
        CStringW strTime = FUN_140811740(0x7da, nHour, nMinute);
        m_30->Invoke("setExpireDate", CStringW(strDate), CStringW(strTime));
    }
}

// MS2-FUNCTIONAL: large body, temp spills / argument evaluation order differ vs exe
// @0x141ab42a0
void UIRealEstateDialog::FUN_141ab42a0()
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0 || FUN_140a467d0(&m_30) != 0 || FUN_1422bb8b0(m_28) == 0)
        return;
    ASObj obj(2);
    Unk_HoServicePtr spSvc(FUN_1401cd040(&DAT_143b059e8));
    CStringW strMapName = FUN_1401a9d70()->FUN_141811980(3, m_nMapId);
    Unk_UGCGroup group;
    if (FUN_1408a0d30(m_nGroup, group, m_nMapId) == 0)
        return;
    int bOwn = 0;
    int bBlocked = 0;
    int bContractable = 0;
    int nState = 0;
    __int64 nTime = 0;
    if (pPC->FUN_141527e00() == 0)
    {
        Unk_GmTargetRef target(pPC->FUN_141523c50());
        if (m_nMapId == target.FUN_14050dee0()->m_20 && m_nGroup == target.FUN_14050dee0()->m_24)
            bOwn = 1;
    }
    m_strOwnerName = "";
    m_nOwnerId = 0;
    if (bOwn == 0)
    {
        if (spSvc.FUN_1401cd1a0()->FUN_1410c8470(m_nGroup, m_nMapId, &nState, &nTime) == 0)
        {
            bContractable = 1;
            reinterpret_cast<Unk_ReScript*>(m_30.operator->())->FUN_141ab5a90("initMyHouse", 2);
        }
        else
        {
            int nMode = nState == 4 ? 2 : 1;
            reinterpret_cast<Unk_ReScript*>(m_30.operator->())->FUN_141ab5a90("initMyHouse", nMode);
            if (nState == 4)
            {
                CMsTime tWait(nTime + *FUN_1401d3200()->UgcHomeSaleWaitingTime.Get());
                int nMinute = tWait.GetMinute();
                int nHour = tWait.GetHour();
                int nDay = tWait.GetDay();
                int nMonth = tWait.GetMonth();
                int nYear = tWait.GetYear();
                m_30->Invoke("setWaitingDate", FUN_1409e90c0(0x7dd, nYear, nMonth, nDay, nHour, nMinute));
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
                    nBlock = spSvc.FUN_1401cd1a0()->FUN_1410c3000();
                Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(*spSvc.FUN_1401cd1a0()->FUN_1410d3360(), m_nGroup, nBlock);
                if (spOwner.get() != 0)
                {
                    strOwner = spOwner->ownerName;
                    m_strOwnerName = strOwner;
                    m_nOwnerId = spOwner->ownerID;
                }
                FUN_141ab3760(CStringW(strOwner));
                FUN_141ab4040(&nTime);
                m_30->Invoke("setContractEffect", 0);
            }
        }
    }
    else
    {
        reinterpret_cast<Unk_ReScript*>(m_30.operator->())->FUN_141ab5a90("initMyHouse", 0);
        FUN_141ab4040(&pPC->FUN_141523c50()->m_n30);
        m_30->Invoke("setContractEffect", 0);
        FUN_141ab3760(static_cast<Unk_RdPC*>(pPC)->FUN_141528330());
    }
    strMapName = FUN_140979570(m_nMapId);
    obj.FUN_1407cbb20("buildingName", CStringW(strMapName));
    CStringW strContract;
    strContract = FUN_1408116a0(0x7ce, group.contractDate);
    obj.FUN_1407cbb20("contractDate", CStringW(strContract));
    unsigned nItem = 0;
    __int64 nPrice = 0;
    FUN_1408a09d0(&nItem, &nPrice, m_nMapId, m_nGroup);
    unsigned nExtItem = 0;
    __int64 nExtPrice = 0;
    FUN_1408a0b80(&nExtItem, &nExtPrice, m_nMapId, m_nGroup);
    __int64 nShown = nPrice;
    if (group.FUN_1408ad2c0() == 0)
    {
        if (group.FUN_1408ad2f0() == 0)
        {
            obj.FUN_1407cb9c0("priceType", 2);
            obj.FUN_1409c0d20("item", nItem);
            MS2Ptr<CItemData> spData = FUN_14053f870(nItem);
            if (spData.get() != 0)
            {
                obj.FUN_1407cba60("icon", spData->FUN_14053fdd0());
                obj.FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, nItem));
            }
        }
        else
            obj.FUN_1407cb9c0("priceType", 1);
    }
    else
        obj.FUN_1407cb9c0("priceType", 0);
    obj.FUN_1407cbb20("price", FUN_140719a00(nShown));
    obj.FUN_1407cbb20("contractPrice", FUN_140719a00(nPrice));
    obj.FUN_1407cbb20("extensionPrice", FUN_140719a00(nExtPrice));
    CStringW strDesc;
    if (FUN_14053f8c0(nExtItem) == 0 && FUN_14053f940(nExtItem) == 0)
        strDesc = FUN_1412e7c20(0x7e0, FUN_1409404f0(nExtPrice), nExtItem);
    else
        strDesc = FUN_1412e7c20(0x7df, FUN_1409404f0(nExtPrice), nExtItem);
    FUN_1403b4750()->FUN_1416fb300(strDesc);
    obj.FUN_1407cbb20("description", FUN_140a228f0(0x7e1, group.contractDate, strDesc));
    static_cast<Unk_ReObj&>(obj).FUN_141ab5b30("buildingIcon", group.buildingType);
    obj.FUN_1407cbb20("buildingType", GetStringCommon(group.buildingType + 0x7d3));
    CStringW strArea;
    strArea = FUN_140811740(0x7d7, group.field30, group.heightLimit);
    obj.FUN_1407cbb20("areaSize", CStringW(strArea));
    obj.FUN_1407cbbe0("land", 0 < group.buildingCount);
    obj.FUN_1407cbb20("buildingCount", FUN_1408116a0(0x7d8, group.buildingCount));
    obj.FUN_1407cbb20("preview", FUN_14016a730(group.previewIcon, 0));
    CStringW strTrophy;
    int nTrophy = group.trophyID;
    if (nTrophy != 0)
    {
        MS2Ptr<CAchieveData> spTrophy = GetAchieveData(nTrophy);
        if (spTrophy.get() != 0)
            strTrophy = FUN_14052bd00(0x7f6, FUN_14093bad0(nTrophy, spTrophy->m_nMaxGrade, CStringW(L"")));
    }
    obj.FUN_1407cbb20("trophy", CStringW(strTrophy));
    if (bBlocked == 0)
    {
        obj.FUN_1407cb9c0("contractable", bContractable);
        obj.FUN_1407cbb20("contractableText", GetStringCommon(0x7fa));
    }
    else
    {
        obj.FUN_1407cb9c0("contractable", 0);
        obj.FUN_1407cbb20("contractableText", GetStringCommon(0x7f8));
        obj.FUN_1407cbb20("trophy", GetStringCommon(0x7f9));
    }
    m_30->Invoke("initData", obj);
}

// @0x141ab5520
CStringW UIRealEstateDialog::FUN_141ab5520(const __int64& nTime)
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
        strText = FUN_1409e90c0(0x7de, nYear, nMonth, nDay, nHour, nMinute);
    }
    return strText;
}

// @0x141ab59f0
UIUGCModelHouseDialog* FUN_141ab59f0(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObject = FUN_1403ed2b0()->FUN_141adcea0((eUIClassID)nClass);
        if (spObject.get() != 0)
            return dynamic_cast<UIUGCModelHouseDialog*>(spObject.operator->());
    }
    return 0;
}

// @0x141ab5a90
Scaleform::GFx::Value Unk_ReScript::FUN_141ab5a90(const char* szMethod, int a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(szMethod, args);
}

// @0x141ab5b30
void Unk_ReObj::FUN_141ab5b30(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc1af0-0x142cc1b60 .text$yd
