// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIRegionListDialog: see uiregionlistdialog.h.
// MS2-UNIT: ?\uiregionlistdialog.cpp
// MS2-RANGE: 0x140e80220-0x140e82350 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiregionlistdialog.cpp"    // assumed

#include <afx.h>
#include <winsock2.h>
#include "ms2/placeholder/ms2stdafx.h"
#include "uiregionlistdialog.h"
#include "uiscenelogin.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/commonfiles/usermail.h"  // C3: CUserMail::FUN_1408e57f0 (the scene-service global)
#include "ms2/placeholder/gfxservice.h"

#pragma comment(lib, "ws2_32.lib")

// ---- unit-local views of exe objects ----

// The region server of the login: slot 57 fills a region array.
class Unk_RlServer
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57(ATL::CAtlArray<Unk_RlPtr>* pOut);     // 57
};
class IClientPlatform* GetClientPlatform();   // C3: was void* FUN_140d86260()

// The client settings: the entry that holds the chosen region id.
// C3: FUN_140cfd260 is CGameOption's (&m_connect; the region name is its first string)
struct Unk_GsConnect;
void FUN_1412609c0(Unk_GsConnect* pEntry, const CStringW& strValue);

int FUN_1406c34c0();                                            // the Nexon platform is active
extern CString g_strServerAddr;                                 // the login ip
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
int FUN_1418fc760(char const*, void*, int, void*);   // C3: was FUN_1418fc760
CString ToCString(const char* sz, int n);
CString FUN_140188f50(const char* sz, int n);
CString FUN_140e819e0(CString strHost);

// The scene manager of the application.
class CNetworkService { public: int ConnectToConfiguredServer(); };   // C3: member view
class CNetworkService* GetNetworkService();   // C3: was GetNetworkService

void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& a);    // set a Value from an AS object
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);                // set an Int value

// AScript with the "buildRegionList" invoke shape (array, int).
class Unk_RlScript : public AScript
{
public:
    // @0x140e813f0
    Scaleform::GFx::Value FUN_140e813f0(const char* szMethod, const ASArray& arr, int n);
};

// @0x140e813f0
Scaleform::GFx::Value Unk_RlScript::FUN_140e813f0(const char* szMethod, const ASArray& arr, int n)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bce40(&args[0], arr);
    FUN_1422bccb0(&args[1], n);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- the dialog ----

// @0x140e80220
UIRegionListDialog::UIRegionListDialog()
{
    SetFlag(0, 1);
    m_80 = 0;
    m_nUnused198 = 0;
    m_nSelected = 0;
    m_strSaved = L"";
    ((class Unk_RlServer*)((void*)GetClientPlatform()))->vfunc_57(&m_regions);
}

// @0x140e80330
UIRegionListDialog::~UIRegionListDialog()
{
}

// @0x140e803a0
CString UIRegionListDialog::GetTypeName()
{
    return "RegionListDialog";
}

// @0x140e803f0
void UIRegionListDialog::OnLoadComplete()
{
    MoveSavedRegionToFront();
    BuildRegionList();
    UIDialog::OnLoadComplete();
}

// @0x140e80430
int UIRegionListDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d890(false)) {
        m_30->Invoke("onEnterKey");
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: branch layout of the stricmp chain / ASData temp
// @0x140e804b0
int UIRegionListDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)(pArgs), nArgs, (void*)(this)) != 0)
        return 1;
    if (_stricmp("onSelectRegion", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            SelectRegion(data.FUN_1422b8f40());
            OnRegionSelected();
        }
        return 1;
    } else if (_stricmp("OnEndPopdown", szMethod) == 0) {
        OnEndPopdown();
        return 1;
    }
    return 0;
}

// @0x140e80620
void UIRegionListDialog::FUN_140e80620()
{
    CStringW strRegion = TSingleton<CGameOption>::GetInstance()->FUN_140cfd260()->m_str00;
    if (!SelectRegion(strRegion)) {
        if (((GFxSceneService*)CUserMail::GetGFxSceneService())->GetSceneId() == 0x6200009) {
            UISceneLogin* pLogin = dynamic_cast<UISceneLogin*>(((GFxSceneService*)CUserMail::GetGFxSceneService())->GetScene());
            if (pLogin != 0) {
                pLogin->FUN_141acf470();
                return;
            }
        }
        FUN_141924680();
        return;
    }
    ((class CNetworkService*)GetNetworkService())->ConnectToConfiguredServer();
    vfunc_67();
}

// @0x140e80740
void UIRegionListDialog::FUN_140e80740()
{
    if (FUN_1406c34c0() == 0)
        return;
    g_strServerAddr = "";
    CStringW strEmpty(L"");
    FUN_1412609c0((Unk_GsConnect*)TSingleton<CGameOption>::GetInstance()->FUN_140cfd260(), strEmpty);
}

// @0x140e807c0
Unk_RlPtr UIRegionListDialog::GetSavedRegion()
{
    CStringW strRegion = TSingleton<CGameOption>::GetInstance()->FUN_140cfd260()->m_str00;
    if (strRegion.IsEmpty())
        return Unk_RlPtr(0);
    Unk_RlPtr region = FindRegion(strRegion);
    return region;
}

// @0x140e808b0
void UIRegionListDialog::FUN_140e808b0()
{
    if (m_30.get() != 0)
        m_30->Invoke("popdown");
}

// @0x140e80910
void UIRegionListDialog::FUN_140e80910()
{
    if (vfunc_55() != 0) {
        FUN_141924680();
    } else if (m_30.get() != 0) {
        m_30->Invoke("popup");
    } else {
        vfunc_68();
        FUN_141924680();
    }
}

// @0x140e809b0
Unk_RlPtr UIRegionListDialog::GetFirstRegion(int nUnused)
{
    if (m_regions.IsEmpty())
        return Unk_RlPtr(0);
    return static_cast<const Unk_RlPtr&>(m_regions.GetAt(0));
}

// @0x140e80a40
void UIRegionListDialog::MoveSavedRegionToFront()
{
    m_strSaved = TSingleton<CGameOption>::GetInstance()->FUN_140cfd260()->m_str00;
    if (m_strSaved.IsEmpty())
        return;
    ATL::CAtlArray<Unk_RlPtr> arrNew;
    Unk_RlPtr saved = FindRegion(m_strSaved);
    if (saved.get() != 0)
        arrNew.InsertAt(0, saved, 1);
    for (int i = 0; i < (int)m_regions.GetCount(); i++) {
        if (m_regions[i]->m_id == m_strSaved)
            continue;
        arrNew.Add(m_regions[i]);
    }
    m_regions.RemoveAll();
    m_regions.Copy(arrNew);
}

// @0x140e80c30
void UIRegionListDialog::BuildRegionList()
{
    if (m_30 == 0)
        return;
    ASArray arr(2);
    for (int i = 0; i < (int)m_regions.GetCount(); i++) {
        ASObj obj(2);
        CString strPath("./Data/Resource/Image/Emblem/Server/");
        obj.SetWStringMember("id", m_regions[i]->m_id);
        obj.SetWStringMember("label", m_regions[i]->m_label);
#if defined(__clang__)
        // clang-cl inlines the dllimport Concatenate and needs CSimpleStringT::CopyChars, which no mfc140 import provides.
        CString strIcon = strPath;
        strIcon += m_regions[i]->m_image;
        obj.SetStringMember("icon", strIcon);
#else
        obj.SetStringMember("icon", strPath + m_regions[i]->m_image);
#endif
        obj.SetIntMember("status", m_regions[i]->m_status);
        arr.PushValue(Scaleform::GFx::Value(obj.GetValue()));
    }
    static_cast<Unk_RlScript*>(m_30.operator->())->FUN_140e813f0("buildRegionList", arr, m_nSelected);
}

// MS2-FUNCTIONAL: stack slot order of the CStringW copy for FindRegion
// @0x140e80f10
bool UIRegionListDialog::SelectRegion(CStringW strRegion)
{
    Unk_RlPtr region = FindRegion(strRegion);
    if (region.get() != 0) {
        if (FUN_1406c34c0() == 1)
            g_strServerAddr = FUN_140e819e0(region->m_host);
        FUN_1412609c0((Unk_GsConnect*)TSingleton<CGameOption>::GetInstance()->FUN_140cfd260(), region->m_id);
        return true;
    } else {
        {
            CStringW strEmpty(L"");
            FUN_1412609c0((Unk_GsConnect*)TSingleton<CGameOption>::GetInstance()->FUN_140cfd260(), strEmpty);
        }
        return false;
    }
}

// @0x140e810d0
Unk_RlPtr UIRegionListDialog::FindRegion(CStringW strRegion)
{
    for (int i = 0; i < (int)m_regions.GetCount(); i++) {
        if (m_regions[i]->m_id == strRegion)
            return static_cast<const Unk_RlPtr&>(m_regions[i]);
    }
    return Unk_RlPtr(0);
}

// @0x140e811d0
void UIRegionListDialog::OnRegionSelected()
{
    if (((GFxSceneService*)CUserMail::GetGFxSceneService())->GetSceneId() == 0x6200009) {
        UISceneLogin* pLogin = dynamic_cast<UISceneLogin*>(((GFxSceneService*)CUserMail::GetGFxSceneService())->GetScene());
        if (pLogin != 0) {
            int nUiId = vfunc_48();
            pLogin->FUN_141acfad0((__int64)&nUiId);
        }
    } else {
        FUN_140e808b0();
    }
}

// @0x140e81270
void UIRegionListDialog::OnEndPopdown()
{
    if (FUN_1406c34c0() == 0) {
        CStringW strRegion = TSingleton<CGameOption>::GetInstance()->FUN_140cfd260()->m_str00;
        FUN_140e812e0(strRegion);
    }
    FUN_140e80620();
}

// @0x140e812e0
void UIRegionListDialog::FUN_140e812e0(const CStringW& strRegion)
{
    Unk_RlPtr region = FindRegion(strRegion);
    if (region == 0)
        region = GetFirstRegion(0);
    if (region == 0)
        return;
    if (FUN_1406c34c0() == 0)
        FUN_1412609c0((Unk_GsConnect*)TSingleton<CGameOption>::GetInstance()->FUN_140cfd260(), region->m_id);
}

// The region host's first address as dotted text.
// @0x140e819e0
CString FUN_140e819e0(CString strHost)
{
    WSADATA wsaData;
    WSAStartup(0x202, &wsaData);
    hostent* pHost = gethostbyname(ToCString(strHost, 0));
    if (pHost == 0)
        return "";
    return FUN_140188f50(inet_ntoa(*(in_addr*)pHost->h_addr_list[0]), 0);
}

MS2_EMIT_CRT_MEMMOVE_S();
