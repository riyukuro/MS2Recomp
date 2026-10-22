// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomeOptionDialog: the home option dialog. See uihomeoptiondialog.h.
// MS2-UNIT: unit_140fa8cc0
// MS2-RANGE: 0x140fa8cc0-0x140fa9eb0 .text$mn
// MS2-RANGE: 0x1400e1a10-0x1400e1bd0 .text$di
// MS2-RANGE: 0x142caa570-0x142caa620 .text$yd
// MS2-PIN: ??__EkENTITY_INVALID@egf@@YAXXZ 0x1400e1b30 ; merge-bind
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uihomeoptiondialog.h"
#include "uimessagebox.h"
#include <atlcoll.h>
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/userugcmapinfo.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics of the unit's header (init order: sort names, skill, stun, a pointer, the condition, the key controller) ----

#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uihidesettingdialog_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
static UICommon::CMyPCKeyInputController s_keyInput;

// ---- unit-local views of exe types ----

struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;

// The home (cube map information) service: the nine permission rows of the home.
class Unk_HoService : public efd::ISystemService {
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    bool FUN_1410c3e00(int nRow);                                   // row enabled
    int FUN_1410c3e80(int nRow);                                    // row level
    char FUN_1410d5640();                                           // may change the options
};
Unk_HoService* FUN_1401cd040(Unk_EntityAppFramework* framework);

// The smart pointer to the service (8 bytes; its glue COMDATs live in the unit that first used it).
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
char FUN_140ef4cb0(Unk_HoServicePtr* pService, int n);

class Unk_HoUnused;                                                 // element of an unused local array
class Unk_HoWorld { public: MyPC* FUN_141bd0cc0(); };               // the local player
Unk_HoWorld* FUN_1403ed2d0();

void FUN_141530720(MyPC* pPC, bool bOpen, CStringW strPassword, int n);   // the player sends the open type
CStringW FUN_140298ea0(CStringW strKey);                            // string table by key
CString FUN_140223190(int nRow);                                   // the name of a permission row
int FUN_1418fd280();
void FUN_1412751f0(const CStringW& str, int a, int b);
void FUN_140710590(COutPacket& packet);
void FUN_14151f200();
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
int* FUN_1404eb7e0(int* pnA, int* pnB);                             // the larger of two ints
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);
bool FUN_140841300(const CStringW& str, const char* psz);

void FUN_1407cd930(Scaleform::GFx::Value* pObj, const char* szName, const Scaleform::GFx::Value& v);

// @0x140fa9c90
void FUN_140fa9c90(ASObj* pObj, const char* szName, unsigned char b)
{
    ASData data;
    data.FUN_1422b7f70(b);
    FUN_1407cd930(reinterpret_cast<Scaleform::GFx::Value*>(reinterpret_cast<char*>(pObj) + 0x20), szName, data.FUN_1422b9260());
}

// @0x140fa8cc0
UIHomeOptionDialog::UIHomeOptionDialog()
{
    FUN_1422dc3b0(1);
}

// @0x140fa8d20
UIHomeOptionDialog::~UIHomeOptionDialog()
{
}

// @0x140fa8d60
CString UIHomeOptionDialog::GetTypeName()
{
    return "HomeOptionDialog";
}
MS2_REPLACE_METHOD(0x140FA8D60, UIHomeOptionDialog, GetTypeName, 61, 0xC0186EEC);

// @0x140fa8db0
void UIHomeOptionDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140fa97a0();
}
MS2_REPLACE_METHOD(0x140FA8DB0, UIHomeOptionDialog, OnLoadComplete, 34, 0x713AD346);

// MS2-FUNCTIONAL: small codegen diffs (temp spills / register choice) vs exe
// @0x140fa8de0
int UIHomeOptionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    if (_stricmp("onApply", szMethod) == 0)
    {
        FUN_140d73aa0(FUN_140298ea0(CStringW(L"s_home_option_msg_confirm")), 1, static_cast<IMessageListener*>(this), CStringW(L"onApply"));
    }
    else if (_stricmp("onConfirm", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            if (data.FUN_1422b8a90() == 1)
                FUN_140d73aa0(FUN_140298ea0(CStringW(L"s_home_option_msg_confirm")), 1, static_cast<IMessageListener*>(this), CStringW(L"OnConfirm"));
            else
                vfunc_67();
        }
    }
    else if (_stricmp("apply", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            Unk_HoServicePtr spService(FUN_1401cd040(&DAT_143b059e8));
            if (FUN_140ef4cb0(&spService, 0) != 0)
                return 1;
            if (spService.FUN_1401cd1a0()->FUN_1410d5640() == 0)
            {
                FUN_140d73bc0(0x6e1, 0, 0, CStringW(L""));
                return 1;
            }
            unsigned char nOpenType = data.FUN_1422b8a10();
            CStringW strPassword = data.FUN_1422b8f40();
            strPassword.Trim();
            if (strPassword.GetLength() != 6)
            {
                FUN_140d73bc0(0xb0a, 0, 0, CStringW(L""));
                return 1;
            }
            FUN_140fa99b0(nOpenType, CStringW(strPassword));
            for (int i = 0; i < 9; ++i)
                FUN_140fa9a50(i, data.FUN_1422b8a10());
        }
    }
    else if (_stricmp("onKickUser", szMethod) == 0)
    {
        FUN_140d73aa0(FUN_140298ea0(CStringW(L"s_home_option_msg_etc_kickuser")), 1, static_cast<IMessageListener*>(this), CStringW(L"OnKickUser"));
    }
    else if (_stricmp("OnReset", szMethod) == 0)
    {
        FUN_140d73aa0(FUN_140298ea0(CStringW(L"s_home_option_init")), 1, static_cast<IMessageListener*>(this), CStringW(L"OnReset"));
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140FA8DE0, UIHomeOptionDialog, vfunc_28, 1924, 0x5CC9AD58);

// @0x140fa9570
int UIHomeOptionDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender))
    {
        int nAnswer = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        ATL::CAtlArray<Unk_HoUnused*> aUnused;
        FUN_14151f200();
        if (nAnswer == 0)
        {
            if (FUN_1403b3c40(strTag, L"OnReset"))
                m_30->Invoke("reset");
            else if (FUN_140841300(strTag, "OnKickUser"))
                SendRequestCubeMode49();
            else if (FUN_140841300(strTag, "onApply"))
                m_30->Invoke("requestData", false);
            else if (FUN_140841300(strTag, "OnConfirm"))
                m_30->Invoke("requestData", true);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140FA9570, UIHomeOptionDialog, OnMessage, 549, 0xC6230034);

// MS2-FUNCTIONAL: small codegen diffs (temp spills / register choice) vs exe
// @0x140fa97a0
void UIHomeOptionDialog::FUN_140fa97a0()
{
    ASObj obj(2);
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
    {
        Unk_BmPtr<UserUGCMapInfo> spHouse(pPC->FUN_141523c50());
        if (spHouse.get() != 0)
            FUN_140fa9c90(&obj, "opentype", spHouse->m_n40);
    }
    Unk_HoServicePtr spService(FUN_1401cd040(&DAT_143b059e8));
    if (spService.FUN_140885310() == 0)
        return;
    for (int i = 0; i < 9; ++i)
    {
        int nRow = i;
        bool bOn = spService.FUN_1401cd1a0()->FUN_1410c3e00(nRow);
        int nLevel = spService.FUN_1401cd1a0()->FUN_1410c3e80(nRow);
        int nValue;
        if (!bOn)
            nValue = 0;
        else
            nValue = nLevel + 1;
        obj.FUN_1407cb9c0(FUN_140223190(nRow), nValue);
    }
    m_30->Invoke("setData", obj);
}
MS2_REPLACE_METHOD(0x140FA97A0, UIHomeOptionDialog, FUN_140fa97a0, 515, 0xB6C067B7);

// MS2-FUNCTIONAL: FUN_140fa99b0: the exe compares the open type byte in memory (cmp byte, 1) and passes a bool; cl widens it
// @0x140fa99b0
void UIHomeOptionDialog::FUN_140fa99b0(bool bOpen, CStringW strPassword)
{
    if (bOpen != true)
        strPassword = L"";
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
        FUN_141530720(pPC, bOpen, CStringW(strPassword), 1);
}
MS2_REPLACE_METHOD(0x140FA99B0, UIHomeOptionDialog, FUN_140fa99b0, 149, 0x7577FED5);

// @0x140fa9a50
void UIHomeOptionDialog::FUN_140fa9a50(int nRow, int nValue)
{
    SendRequestCubeMode42(nRow, 0 < nValue);
    int nLevel = nValue - 1;
    int nZero = 0;
    SendRequestCubeMode43(nRow, *FUN_1404eb7e0(&nZero, &nLevel));
}
MS2_REPLACE_METHOD(0x140FA9A50, UIHomeOptionDialog, FUN_140fa9a50, 112, 0x83221714);

// @0x140fa9ad0
void UIHomeOptionDialog::SendRequestCubeMode42(int nRow, bool bOn)
{
    COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
    packet.vfunc_o10_1(0x2a);
    packet.vfunc_o10_1(nRow);
    packet.vfunc_o10_0(bOn);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140FA9AD0, UIHomeOptionDialog, SendRequestCubeMode42, 117, 0x51D3FED8);

// @0x140fa9b50
void UIHomeOptionDialog::SendRequestCubeMode43(int nRow, int nLevel)
{
    COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
    packet.vfunc_o10_1(0x2b);
    packet.vfunc_o10_1(nRow);
    packet.vfunc_o10_1(nLevel);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140FA9B50, UIHomeOptionDialog, SendRequestCubeMode43, 117, 0xE2DAB25B);

// @0x140fa9bd0
void UIHomeOptionDialog::SendRequestCubeMode49()
{
    COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
    packet.vfunc_o10_1(0x31);
    FUN_140710590(packet);
    if (FUN_1418fd280() == 1)
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_home_option_msg_kick_user")), 1, 1);
}
MS2_REPLACE_METHOD(0x140FA9BD0, UIHomeOptionDialog, SendRequestCubeMode49, 187, 0x29C0712D);

MS2_EMIT_CRT_MEMMOVE_S();
