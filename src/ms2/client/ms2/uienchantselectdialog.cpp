// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIEnchantSelectDialog: choose the enchant npc (lottery / exp).
// MS2-UNIT: ?\uienchantselectdialog.cpp
// MS2-RANGE: 0x140e291e0-0x140e29f60 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uienchantselectdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uienchantselectdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/bigdatalogsystem.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/commonfiles/scriptptr.h"           // C3: Unk_ScriptPtr<CTalkScript>
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce240
class Unk_140acd6e0 : public ASButton {};   // C3: the button view of the definer's instantiation
class UICashAttendDialog { public: template <class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out); };   // C3: the child binder (0x140bc6d10, uicashattenddialog.cpp)

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> EsClickDelegate;

// The click event: the pressed button is read from +0x30.
struct Unk_EsParams { char m_pad[0x30]; void* m_pButton; };
int FUN_140bd09c0(void* pButton);                                       // which button (1 = lottery, 2 = exp mode)

// The sound event sink (TSingleton<CBigDataLogSystem>::GetInstance).
// The feature flag table (FUN_140166410).
class Unk_140166410* FUN_140166410();   // the CFeatureManager instance (0x140166410, the definer's signature)

// The npc talk machinery, as in mypc.cpp.
class CTalkScript;
Unk_ScriptPtr<CTalkScript> FUN_140856820(int nNpcId, int nKind);   // the talk script of the npc with the kind
class Unk_MyPCSurvival : public UITalkManager {};

// The world / local player (FUN_1403ed2d0 / FUN_141bd0cc0); vfunc 65 (0x208) is "talk state".
class Unk_EsWorld;
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
CStringW GetStringCommonByKey(const CStringW& str);
void FUN_1412751f0(const CStringW& str, int a, int b);

// @0x140e291e0
UIEnchantSelectDialog::UIEnchantSelectDialog()
{
    m_80 = 0;
}

// @0x140e29270
UIEnchantSelectDialog::~UIEnchantSelectDialog()
{
    m_type1Button = 0;
    m_type2Button = 0;
}

// @0x140e29310
CString UIEnchantSelectDialog::GetTypeName()
{
    return "EnchantSelectDialog";
}
MS2_REPLACE_METHOD(0x140E29310, UIEnchantSelectDialog, GetTypeName, 61, 0x9DBF64A1);

// @0x140e29360
void UIEnchantSelectDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    {
        CString strArg("enchant");
        CString strEvent("dialog_close");
        TSingleton<CBigDataLogSystem>::GetInstance()->SendLog(strEvent, strArg);
    }
    m_type1Button = 0;
    m_type2Button = 0;
}

// @0x140e29410
void UIEnchantSelectDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_close");
    FUN_1419260d0("m_webGuideButton", 0);
    ASButton* pType1 = reinterpret_cast<ASButton*>(reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<Unk_140acd6e0>("m_type1Button", reinterpret_cast<MS2Ptr<Unk_140acd6e0>&>(m_type1Button)).get());
    if (pType1 != 0)
        m_type1Button->FUN_1422ce240(EsClickDelegate(this, &UIEnchantSelectDialog::FUN_140e29860), (void*)1);
    ASButton* pType2 = reinterpret_cast<ASButton*>(reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<Unk_140acd6e0>("m_type2Button", reinterpret_cast<MS2Ptr<Unk_140acd6e0>&>(m_type2Button)).get());
    if (pType2 != 0)
        m_type2Button->FUN_1422ce240(EsClickDelegate(this, &UIEnchantSelectDialog::FUN_140e29860), (void*)2);
    if (MS2Ptr<ASMovieClip> recommend = GetChild<ASMovieClip>("m_recommendType2"))
        recommend->vfunc_4(reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xfc));
    {
        CString strArg("enchant");
        CString strEvent("dialog_open");
        TSingleton<CBigDataLogSystem>::GetInstance()->SendLog(strEvent, strArg);
    }
}

// @0x140e29860
void UIEnchantSelectDialog::FUN_140e29860(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nButton = FUN_140bd09c0(((Unk_EsParams*)&params)->m_pButton);
    CString strMode;
    unsigned int nNpcId = 0;
    if (nButton == 1)
    {
        strMode = "lottery";
        nNpcId = 0xa7dabc;
    }
    else if (nButton == 2)
    {
        strMode = "expMode";
        nNpcId = 0xa7dabe;
    }
    PCBase* pPc = ((class PCBase*)((class WorldService*)(class Unk_EsWorld*)(((class Unk_EsWorld*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPc != 0 && pPc->vfunc_65() == 1)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_error_talk_battle_state_force_talk"), 1, 1);
        return;
    }
    if (nNpcId > 0)
    {
        if (CTalkScript* pScript = FUN_140856820(nNpcId, *reinterpret_cast<Common::Constants::Value<int>*>(((char*)FUN_1401d3200()) + 0x69a0)->Get()).get())
        {
            ((class Unk_MyPCSurvival*)TSingleton<UITalkManager>::GetInstance())->FUN_141b213f0(MS2Ptr<CTalkScript>(pScript), nNpcId, 2, 0);
            ((class Unk_MyPCSurvival*)TSingleton<UITalkManager>::GetInstance())->FUN_141b1eb90(CStringA("ItemEnchantDialog"), CStringA(strMode));
        }
    }
    vfunc_67();
}
MS2_REPLACE_METHOD(0x140E29360, UIEnchantSelectDialog, vfunc_67, 160, 0x553DC0A2);
MS2_REPLACE_METHOD(0x140E29410, UIEnchantSelectDialog, OnLoadComplete, 1090, 0x1F3883A7);
MS2_REPLACE_METHOD(0x140E29860, UIEnchantSelectDialog, FUN_140e29860, 715, 0x841B273B);
