// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomePasswordDialog: see uihomepassworddialog.h.
// MS2-UNIT: ?\uihomepassworddialog.cpp
// MS2-RANGE: 0x1400ed9c0-0x1400edb60 .text$di
// MS2-RANGE: 0x1412c8bd0-0x1412c9860 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uihomepassworddialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static UICommon::CMyPCKeyInputController s_keyInputController;

// ---- unit-local views of exe types (unrecovered helpers) ----

class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };
class Unk_HpWorld;
class Unk_HpActor;                                              // the local player
struct Unk_HpActorData { char m_pad_00[0x38]; __int64 m_38; };  // +0x38 the expire time of the home password
class Unk_HpActorPtr
{
public:
    Unk_HpActorPtr(Unk_HpActor* pActor);                        // 0x14050dd40
    ~Unk_HpActorPtr();                                          // 0x14050de40
    void* FUN_140fa9d30() const;
    Unk_HpActorData* FUN_14050dee0() const;                     // operator->
private:
    void* m_0;
    void* m_8;
};
MS2_CHECK_SIZE(Unk_HpActorPtr, 0x10);
class Unk_HpMovie { public: Scaleform::GFx::Value FUN_140e0a8c0(const char* szMethod, CStringW strText, int nState); };

Unk_HpWorld* FUN_1403ed2d0();
Unk_HpActor* FUN_141bd0cc0(Unk_HpWorld* pWorld);
Unk_HpActor* FUN_141523c50(Unk_HpActor* pActor);
__int64 FUN_140869440();                                        // server time
CStringW GetStringCommon(int nStringId);
CStringW FUN_1409e90c0(int nStringId, const int& nYear, const int& nMonth, const int& nDay, const int& nHour,
                       const int& nMinute);
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, void* pScene);
void FUN_140710590(COutPacket& packet);
void FUN_140d73bc0(int nStringId, int a2, int a3, CStringW strText);
void FUN_140d73aa0(CStringW strText, int a2, IMessageListener* pListener, CStringW strTag);
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);    // case-insensitive equal
void FUN_14151f200();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1412c8bd0
UIHomePasswordDialog::UIHomePasswordDialog()
{
    FUN_141924170(1);
}

// @0x1412c8c50
UIHomePasswordDialog::~UIHomePasswordDialog()
{
}

// @0x1412c8cb0
CString UIHomePasswordDialog::GetTypeName()
{
    return "HomePasswordDialog";
}

// @0x1412c8d00
int UIHomePasswordDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    return 1;
}

// @0x1412c8d30
void UIHomePasswordDialog::vfunc_67()
{
    COutPacket packet(static_cast<int>(SendOp::FunctionCube), 0);
    packet.WriteUInt8(7);
    packet.WriteUnicodeStringA(m_178);
    FUN_140710590(packet);
    UIDialog::vfunc_67();
}

// @0x1412c8db0
void UIHomePasswordDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.IsNull() != 0)
        return;
    Unk_HpActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor != 0)
    {
        Unk_HpActorPtr ref(FUN_141523c50(pActor));
        if (ref.FUN_140fa9d30() != 0)
        {
            __int64 nExpire = ref.FUN_14050dee0()->m_38;
            unsigned nState = FUN_140869440() < nExpire;
            CMsTime time(nExpire);
            if (nState != 0)
            {
                reinterpret_cast<Unk_HpMovie*>(m_30.operator->())->FUN_140e0a8c0("setState", FUN_1409e90c0(0xb08, time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute()), nState);
            }
            else
            {
                reinterpret_cast<Unk_HpMovie*>(m_30.operator->())->FUN_140e0a8c0("setState", GetStringCommon(0xb09), nState);
            }
        }
    }
}

// @0x1412c9030
// MS2-FUNCTIONAL: the exe's vfunc_79 returns the IsNull result (base slot is declared void)
void UIHomePasswordDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    if (vfunc_55() == 0)
        m_30.IsNull();
}

// @0x1412c9090
int UIHomePasswordDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0))
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    else if (_stricmp("OnConfirm", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strPassword = data.FUN_1422b8f40();
            unsigned nFlag = data.FUN_1422b8a90();
            strPassword.Trim();
            if (strPassword.GetLength() != 6)
                FUN_140d73bc0(0xb0a, 0, 0, L"");
            else
                SendRequestCube(1, strPassword, nFlag);
        }
        return 1;
    }
    else if (_stricmp("OnStop", szMethod) == 0)
    {
        Unk_HpActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pActor != 0)
        {
            Unk_HpActorPtr ref(FUN_141523c50(pActor));
            if (ref.FUN_140fa9d30() != 0)
            {
                __int64 nExpire = ref.FUN_14050dee0()->m_38;
                unsigned nState = FUN_140869440() < nExpire;
                CMsTime time(nExpire);
                if (nState != 0)
                    FUN_140d73aa0(FUN_1409e90c0(0xb06, time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute()), 1, this, L"onStop");
            }
        }
        return 1;
    }
    return 0;
}

// @0x1412c94d0
void UIHomePasswordDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(0, 0, 0);
}

// @0x1412c9580
int UIHomePasswordDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (nResult == 0)
        {
            if (FUN_1403b3c40(strTag, L"onStop"))
                FUN_1412c97c0();
            return 1;
        }
    }
    return 0;
}

// @0x1412c9680
void UIHomePasswordDialog::FUN_1412c9680(CString strPassword)
{
    m_178 = strPassword;
}

// @0x1412c96d0
void UIHomePasswordDialog::SendRequestCube(int nMode, CStringW strPassword, int nUnused)
{
    Unk_HpActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor != 0)
    {
        Unk_HpActorPtr ref(FUN_141523c50(pActor));
        if (ref.FUN_140fa9d30() != 0)
        {
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.WriteUInt8(0x18);
            packet.WriteUInt8(nMode);
            packet.WriteUnicodeString(strPassword);
            FUN_140710590(packet);
        }
    }
}

// @0x1412c97c0
void UIHomePasswordDialog::FUN_1412c97c0()
{
    SendRequestCube(0, L"", 0);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caf410-0x142caf4c0 .text$yd
