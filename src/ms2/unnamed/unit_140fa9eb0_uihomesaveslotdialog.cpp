// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomeSaveSlotDialog: the save/load slots of the home designer
// (and of the blueprint designer, which uses the second slot list of the cube service). See unit_140fa9eb0.h.
// MS2-UNIT: unit_140fa9eb0
// MS2-RANGE: 0x140fa9eb0-0x140facb20 .text$mn
// MS2-RANGE: 0x1400e1bd0-0x1400e1d60 .text$di
// MS2-RANGE: 0x142caa620-0x142caa6a6 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$forward@AEBQEAVUIHomeSaveSlotDialog@@@std@@YAAEBQEAVUIHomeSaveSlotDialog@@AEBQEAV1@@Z 0x140fac470 ; unique
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIHomeSaveSlotDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x140fac5f0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIHomeSaveSlotDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140fac710 ; unique
// MS2-PIN: ??_GUIHomeSaveSlotDialog@@UEAAPEAXI@Z 0x140fac750 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIHomeSaveSlotDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140faca40 ; unique
// MS2-PIN: ??$Call@VUIHomeSaveSlotDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIHomeSaveSlotDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIHomeSaveSlotDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140faca80 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIHomeSaveSlotDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140fac9e0
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VUGCMapBlueprintInfo@@@@V?$CElementTraits@V?$MS2Ptr@VUGCMapBlueprintInfo@@@@@ATL@@@ATL@@QEBA_KXZ 0x140fac790
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VUGCMapDesignInfo@@@@V?$CElementTraits@V?$MS2Ptr@VUGCMapDesignInfo@@@@@ATL@@@ATL@@QEBA_KXZ 0x140fac7a0
// MS2-PIN: ?Release@?$MS2Ptr@VUGCMapBlueprintInfo@@@@AEAAXXZ 0x140fac8c0
// MS2-PIN: ?Release@?$MS2Ptr@VUGCMapDesignInfo@@@@AEAAXXZ 0x140fac900
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUGCMapBlueprintInfo@@@@AEAAXPEAX@Z 0x140fac940
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUGCMapDesignInfo@@@@AEAAXPEAX@Z 0x140fac990
// MS2-PIN: ?Reference@?$MS2Ptr@VUGCMapBlueprintInfo@@@@CAXPEAVUGCMapBlueprintInfo@@@Z 0x140fac820
// MS2-PIN: ?Reference@?$MS2Ptr@VUGCMapDesignInfo@@@@CAXPEAVUGCMapDesignInfo@@@Z 0x140fac840
// MS2-PIN: ?AddRef@?$MS2Ptr@VUGCMapBlueprintInfo@@@@AEBAXXZ 0x140fac7c0
// MS2-PIN: ?AddRef@?$MS2Ptr@VUGCMapDesignInfo@@@@AEBAXXZ 0x140fac7f0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUGCMapBlueprintInfo@@@@AEBAXPEAX@Z 0x140fac860
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUGCMapDesignInfo@@@@AEBAXPEAX@Z 0x140fac890
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_140fa9eb0.h"
#include <atlcoll.h>
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/ms2format.h"

// ---- statics of the unit's header (init order: sort names, a pointer, the key controller, skill, stun, a pointer) ----

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static egf::EntityID s_pointer1(0);   // @0x1400e1c90
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static egf::EntityID s_pointer2(0);   // @0x1400e1d40

// ---- unit-local views of exe types ----

// The cube map information service (class id 0x06100017), which also keeps the home / blueprint save slots.
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 egf::g_bapiContext
extern int DAT_143ab2914;

// One saved slot: id, name and the time it was saved (0 = empty). The ugcdef.h class, declared here as
// scenestategame.cpp does (the header's includes would add header statics to this unit).
class UGCMapDesignInfo : public CPtred
{
public:
    UGCMapDesignInfo();
    int m_nId;                                              // +0x18
    CString m_strName;                                      // +0x20
    __int64 m_nTime;                                        // +0x28
};
MS2_CHECK_SIZE(UGCMapDesignInfo, 0x30);

// The slot of the blueprint list: the ugcdef.h UGCMapBlueprintInfo (the same fields, a separate MS2Ptr chain in the exe).
class UGCMapBlueprintInfo : public CPtred {
public:
    int m_nId;                                                      // +0x18
    CString m_strName;                                              // +0x20
    __int64 m_nTime;                                                // +0x28
};
MS2_CHECK_OFFSET(UGCMapBlueprintInfo, m_nId, 0x18);
MS2_CHECK_OFFSET(UGCMapBlueprintInfo, m_strName, 0x20);
MS2_CHECK_OFFSET(UGCMapBlueprintInfo, m_nTime, 0x28);

// C3: Unk_Service6100017 was CubeMapInformationService (class id 0x06100017, the view below)
//
//
//
// The cube map service members reached through the same service pointer.
class CubeMapInformationService : public efd::ISystemService {
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    bool FUN_1410c3600(int nRule);
    int FUN_1410d2f10();
    int FUN_1410c3100();
    int FUN_1410c3140();
    ATL::CAtlArray<MS2Ptr<UGCMapDesignInfo> >* FUN_1410d4660();         // the home slots (+0x388)
    ATL::CAtlArray<MS2Ptr<UGCMapBlueprintInfo> >* FUN_1410d4920();    // the blueprint slots (+0x3a8)
};

MS2Ptr<CMsgBoxData> CreateMessageBox(int nType, CStringW strText, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
#include "ms2/commonfiles/commonutil.h"
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
CStringW FUN_14016a730(const char* sz, int nCodePage);
CStringW FUN_14083bab0(const CMsTime& time, CStringW strSep);
int FUN_1418fc760(const char* szEvent, void* a2, int a3, void* a4);
bool FUN_1408a06a0(int nMapId, int nGroup);
void SendRequestCubeMode35(int nSlot);

void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

// @0x140fac0a0
CStringW FUN_140fac0a0(__int64 nTime)
{
    if (nTime == 0)
        return CStringW(L"");
    CMsTime time(nTime);
    CStringW strText;
    CStringW strDate = FUN_14083bab0(time, CStringW(L"/"));
    strText.Format(L"%s %02d:%02d:%02d", strDate.GetString(), time.GetHour(), time.GetMinute(), time.GetSecond());
    return strText;
}

// @0x140fac340
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, CStringW a2, CStringW a3)
{
    ASArgList args;
    args.resize(3);
    FUN_1422bccb0(&args[0], a1);
    FUN_1422bcea0(&args[1], a2);
    FUN_1422bcea0(&args[2], a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140fa9eb0
UIHomeSaveSlotDialog::UIHomeSaveSlotDialog()
{
    SetTweenEnabled(1);
    m_saveMode = 1;
}

// @0x140fa9f20
UIHomeSaveSlotDialog::~UIHomeSaveSlotDialog()
{
}

// @0x140fa9f60
CString UIHomeSaveSlotDialog::GetTypeName()
{
    return CString("HomeSaveSlotDialog");
}
MS2_REPLACE_METHOD(0x140FA9F60, UIHomeSaveSlotDialog, GetTypeName, 61, 0xE5D59A4F);

// @0x140fa9fb0
void UIHomeSaveSlotDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    static_cast<ASObj*>(m_30.operator->())->SetIntMember("saveMode", m_saveMode);
    UpdateSlots();
}
MS2_REPLACE_METHOD(0x140FA9FB0, UIHomeSaveSlotDialog, OnLoadComplete, 78, 0xADF43989);

// @0x140faa010
void UIHomeSaveSlotDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (vfunc_55() == 0 && !m_30)
    {
    }
}

// @0x140faa070
int UIHomeSaveSlotDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (FUN_1418fc760(szMethod, (void*)pArgs, nArgs, 0))
        return 1;
    if (_stricmp(szMethod, "OnSaveSlot") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            efd::SmartPointer<CubeMapInformationService> spService(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
            if (spService)
            {
                int nSlot = data.PopInt();
                if (reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410c3600(3))
                    FUN_140fabae0(nSlot);
                else
                    FUN_140fab520(nSlot);
            }
        }
    }
    else if (_stricmp(szMethod, "OnLoadSlot") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            efd::SmartPointer<CubeMapInformationService> spService(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
            if (spService)
            {
                int nSlot = data.PopInt();
                if (reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410c3600(3))
                    FUN_140fabe80(nSlot);
                else
                    FUN_140fab8c0(nSlot);
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140FAA070, UIHomeSaveSlotDialog, vfunc_28, 592, 0x024C5C3B);

// @0x140faa2d0
void UIHomeSaveSlotDialog::UpdateSlots()
{
    if (!m_30)
        return;
    efd::SmartPointer<CubeMapInformationService> spService(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
    if (reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410c3600(3))
    {
        ATL::CAtlArray<MS2Ptr<UGCMapBlueprintInfo> >* pSlots = reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410d4920();
        for (size_t i = 0; i < 5; ++i)
        {
            CString strName;
            __int64 nTime = 0;
            if (i < pSlots->GetCount())
            {
                strName = (*pSlots)[i]->m_strName;
                nTime = (*pSlots)[i]->m_nTime;
                m_30->Invoke("setSlot", (*pSlots)[i]->m_nId, FUN_14016a730((LPCSTR)strName, 0), FUN_140fac0a0(nTime));
            }
        }
    }
    else
    {
        ATL::CAtlArray<MS2Ptr<UGCMapDesignInfo> >* pSlots = reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410d4660();
        for (size_t i = 0; i < 5; ++i)
        {
            CString strName;
            __int64 nTime = 0;
            if (i < pSlots->GetCount())
            {
                strName = (*pSlots)[i]->m_strName;
                nTime = (*pSlots)[i]->m_nTime;
                m_30->Invoke("setSlot", (*pSlots)[i]->m_nId, FUN_14016a730((LPCSTR)strName, 0), FUN_140fac0a0(nTime));
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140FAA2D0, UIHomeSaveSlotDialog, UpdateSlots, 1017, 0xA6F64619);

// @0x140faa6d0
void UIHomeSaveSlotDialog::SetSaveMode()
{
    m_saveMode = 1;
    if (FUN_141924630())
    {
        if ((AScript*)m_30 != 0)
            static_cast<ASObj*>(m_30.operator->())->SetIntMember("saveMode", m_saveMode);
    }
    else
        FUN_141924680();
}
MS2_REPLACE_METHOD(0x140FAA6D0, UIHomeSaveSlotDialog, SetSaveMode, 121, 0x4C398FF8);

// @0x140faa750
void UIHomeSaveSlotDialog::SetLoadMode()
{
    m_saveMode = 0;
    if (FUN_141924630())
    {
        if ((AScript*)m_30 != 0)
            static_cast<ASObj*>(m_30.operator->())->SetIntMember("saveMode", m_saveMode);
    }
    else
        FUN_141924680();
}
MS2_REPLACE_METHOD(0x140FAA750, UIHomeSaveSlotDialog, SetLoadMode, 121, 0xDD1169D2);

// @0x140faa7d0
bool UIHomeSaveSlotDialog::OnSaveNameEntered(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    efd::SmartPointer<CubeMapInformationService> spService(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
    if (spService == 0)
        return true;
    int nSlot = data.FUN_141a02e50(0, 0);
    CStringW strName = data.FUN_141a02d50();
    strName.Trim(L",");
    ATL::CAtlArray<MS2Ptr<UGCMapDesignInfo> >* pSlots = reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410d4660();
    for (size_t i = 0; i < pSlots->GetCount(); ++i)
    {
        MS2Ptr<UGCMapDesignInfo> spSlot = (*pSlots)[i];
        if (spSlot->m_nId == nSlot && spSlot->m_nTime != 0)
        {
            if (MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, GetStringCommonByKey(L"s_home_save_btn_overwrite"), 0, CStringW(L"")))
            {
                spBox->Append<int>(nSlot);
                spBox->AddStringArg(CStringW(strName));
                spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeSaveSlotDialog::SendRequestCubeMode46));
                FUN_140d73c60(spBox);
                return true;
            }
        }
    }
    COutPacket pkt(static_cast<int>(SendOp::RequestCube), 0);
    pkt.WriteUInt8(0x2e);
    pkt.WriteInt32(nSlot);
    pkt.WriteUnicodeString(strName);
    FUN_140710590(pkt);
    return true;
}

// @0x140faac30
bool UIHomeSaveSlotDialog::OnLoadConfirmed(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    efd::SmartPointer<CubeMapInformationService> spService(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
    if (spService == 0)
        return true;
    int nSlot = data.FUN_141a02e50(0, 0);
    bool bBlocked = reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410c3600(1);
    if (!bBlocked && DAT_143ab2914 >= 50)
    {
        if (reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410d2f10() != 0)
        {
            bBlocked = FUN_1408a06a0(reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410c3140(), reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410c3100());
        }
    }
    if (bBlocked)
    {
        COutPacket pkt(static_cast<int>(SendOp::RequestCube), 0);
        pkt.WriteUInt8(0x2f);
        pkt.WriteInt32(nSlot);
        FUN_140710590(pkt);
    }
    else
    {
        SendRequestCubeMode35(nSlot);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140FAAC30, UIHomeSaveSlotDialog, OnLoadConfirmed, 377, 0x4F722325);

// @0x140faadb0
bool UIHomeSaveSlotDialog::SendRequestCubeMode46(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    int nSlot = data.FUN_141a02e50(0, 0);
    CStringW strName = data.FUN_141a02fd0(1, CStringW());
    COutPacket pkt(static_cast<int>(SendOp::RequestCube), 0);
    pkt.WriteUInt8(0x2e);
    pkt.WriteInt32(nSlot);
    pkt.WriteUnicodeString(strName);
    FUN_140710590(pkt);
    return true;
}
MS2_REPLACE_METHOD(0x140FAADB0, UIHomeSaveSlotDialog, SendRequestCubeMode46, 235, 0x407FDCD3);

// @0x140faaeb0
bool UIHomeSaveSlotDialog::OnBlueprintSaveNameEntered(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    efd::SmartPointer<CubeMapInformationService> spService(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
    if (spService == 0)
        return true;
    int nSlot = data.FUN_141a02e50(0, 0);
    CStringW strName = data.FUN_141a02d50();
    strName.Trim(L",");
    ATL::CAtlArray<MS2Ptr<UGCMapBlueprintInfo> >* pSlots = reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410d4920();
    for (size_t i = 0; i < pSlots->GetCount(); ++i)
    {
        MS2Ptr<UGCMapBlueprintInfo> spSlot = (*pSlots)[i];
        if (spSlot->m_nId == nSlot && spSlot->m_nTime != 0)
        {
            if (MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, GetStringCommonByKey(L"s_home_save_btn_overwrite"), 0, CStringW(L"")))
            {
                spBox->Append<int>(nSlot);
                spBox->AddStringArg(CStringW(strName));
                spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeSaveSlotDialog::SendRequestCubeMode64));
                FUN_140d73c60(spBox);
                return true;
            }
        }
    }
    COutPacket pkt(static_cast<int>(SendOp::RequestCube), 0);
    pkt.WriteUInt8(0x40);
    pkt.WriteInt32(nSlot);
    pkt.WriteUnicodeString(strName);
    FUN_140710590(pkt);
    return true;
}

// @0x140fab310
bool UIHomeSaveSlotDialog::SendRequestCubeMode65(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    efd::SmartPointer<CubeMapInformationService> spService(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
    if (spService == 0)
        return true;
    int nSlot = data.FUN_141a02e50(0, 0);
    if (reinterpret_cast<CubeMapInformationService*>(spService.operator->())->FUN_1410c3600(3))
    {
        COutPacket pkt(static_cast<int>(SendOp::RequestCube), 0);
        pkt.WriteUInt8(0x41);
        pkt.WriteInt32(nSlot);
        FUN_140710590(pkt);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140FAB310, UIHomeSaveSlotDialog, SendRequestCubeMode65, 263, 0xB9710357);

// @0x140fab420
bool UIHomeSaveSlotDialog::SendRequestCubeMode64(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    int nSlot = data.FUN_141a02e50(0, 0);
    CStringW strName = data.FUN_141a02fd0(1, CStringW());
    COutPacket pkt(static_cast<int>(SendOp::RequestCube), 0);
    pkt.WriteUInt8(0x40);
    pkt.WriteInt32(nSlot);
    pkt.WriteUnicodeString(strName);
    FUN_140710590(pkt);
    return true;
}
MS2_REPLACE_METHOD(0x140FAB420, UIHomeSaveSlotDialog, SendRequestCubeMode64, 235, 0x70C5E0AF);

// @0x140fab520
void UIHomeSaveSlotDialog::FUN_140fab520(int nSlot)
{
    if (nSlot < 0 || nSlot > 5)
        return;
    CStringW strMsg = FUN_14028dfa0(CStringW(L"s_home_save_messagebox"), nSlot);
    CStringW strTitle = GetStringCommonByKey(L"s_home_save_title_empty");
    MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(5, CStringW(strMsg), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->Append<int>(nSlot);
        spBox->SetButtonLabels(GetStringCommonByKey(L"s_home_save_btn_text"), GetStringCommonByKey(L"s_word_cancel"), L"");
        spBox->SetInput(0, strTitle, 0x14, 1, 1);
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeSaveSlotDialog::OnSaveNameEntered));
        FUN_140d73c60(spBox);
    }
}

// @0x140fab8c0
void UIHomeSaveSlotDialog::FUN_140fab8c0(int nSlot)
{
    if (nSlot < 0 || nSlot > 5)
        return;
    CStringW strMsg = FUN_14028dfa0(CStringW(L"s_home_load_messagebox"), nSlot);
    MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, CStringW(strMsg), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->Append<int>(nSlot);
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeSaveSlotDialog::OnLoadConfirmed));
        FUN_140d73c60(spBox);
    }
}

// @0x140fabae0
void UIHomeSaveSlotDialog::FUN_140fabae0(int nSlot)
{
    if (nSlot < 0 || nSlot > 5)
        return;
    CStringW strMsg = FUN_14028dfa0(CStringW(L"s_home_save_messagebox"), nSlot);
    CStringW strTitle = GetStringCommonByKey(L"s_home_save_title_empty");
    MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(5, CStringW(strMsg), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->Append<int>(nSlot);
        spBox->SetButtonLabels(GetStringCommonByKey(L"s_home_save_btn_text"), GetStringCommonByKey(L"s_word_cancel"), L"");
        spBox->SetInput(0, strTitle, 0x14, 1, 1);
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeSaveSlotDialog::OnBlueprintSaveNameEntered));
        FUN_140d73c60(spBox);
    }
}

// @0x140fabe80
void UIHomeSaveSlotDialog::FUN_140fabe80(int nSlot)
{
    if (nSlot < 0 || nSlot > 5)
        return;
    CStringW strMsg = FUN_14028dfa0(CStringW(L"s_home_blueprint_load_messagebox"), nSlot);
    MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, CStringW(strMsg), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->Append<int>(nSlot);
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeSaveSlotDialog::SendRequestCubeMode65));
        FUN_140d73c60(spBox);
    }
}

// @0x140fac7b0
int UIHomeSaveSlotDialog::vfunc_48()
{
    return 0x4f27;
}
MS2_REPLACE_METHOD(0x140FAC7B0, UIHomeSaveSlotDialog, vfunc_48, 11, 0x70AFA5E9);
