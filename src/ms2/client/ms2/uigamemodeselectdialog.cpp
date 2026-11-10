// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGameModeSelectDialog: see uigamemodeselectdialog.h.
// MS2-UNIT: ?\uigamemodeselectdialog.cpp
// MS2-RANGE: 0x140c19f20-0x140c1aaf0 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigamemodeselectdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uigamemodeselectdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce240

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> GmClickDelegate;

// The constants table: the two movie paths.
class Unk_GmGlobals
{
public:
    char m_pad_0000[0xe548];
    CStringW m_e548;                                                    // rpg movie path
    CStringW m_e550;                                                    // royale movie path
};
namespace Client { class Constants; } template<class T> class TSingleton; template<> class TSingleton<Client::Constants> { public: static Client::Constants* GetInstance(); }; class Unk_SingletonObj1;   // C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance); C3: the canonical return type (was Unk_GmGlobals*)

int FUN_1418fc760(const char* szMethod, void* pArgs, int nArgs, void* pDialog);
class CStateService { public: int FUN_1417e25a0(int nEvent); };
template <class T> class TSingleton;
template <> class TSingleton<CStateService> { public: static CStateService* GetInstance(); };
void FUN_1412761e0(MS2Ptr<AScript> pScript, int bShow);

// @0x140c19f20
UIGameModeSelectDialog::UIGameModeSelectDialog()
{
    m_80 = 0;
    SetFlag(0, 1);
}

// @0x140c19fb0
UIGameModeSelectDialog::~UIGameModeSelectDialog()
{
}

// @0x140c1a000
CString UIGameModeSelectDialog::GetTypeName()
{
    return "GameModeSelectDialog";
}

// @0x140c1a050
void UIGameModeSelectDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140c1a070
void UIGameModeSelectDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30 == 0)
    {
        vfunc_67();
        return;
    }
    m_178 = m_30->FUN_140acce30<ASButton>("m_start");
    if (m_178.get() != 0)
        m_178.operator->()->AddClickHandler(GmClickDelegate(this, &UIGameModeSelectDialog::OnStartClick), 0);
    ASObj obj(2);
    ((class AScript&)(obj)).SetWStringMember("rpgMoviePath", ((Unk_GmGlobals*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_e548);
    ((class AScript&)(obj)).SetWStringMember("royaleMoviePath", ((Unk_GmGlobals*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_e550);
    FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
    m_30->Invoke("initData", obj.GetValue());
}

// @0x140c1a390
int UIGameModeSelectDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    return 0;
}

// @0x140c1a3e0
int UIGameModeSelectDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    return 0;
}

// @0x140c1a410
int UIGameModeSelectDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, (void*)(pArgs), nArgs, (void*)(this)) != 0)
        return 1;
    if (_stricmp("OnEndPopdown", szMethod) == 0)
    {
        TSingleton<CStateService>::GetInstance()->FUN_1417e25a0((int)(0x6200009));
        return 1;
    }
    return 0;
}

// @0x140c1a4b0
void UIGameModeSelectDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_178 = 0;
}

// @0x140c1a4f0
void UIGameModeSelectDialog::vfunc_43()
{
    UIDialog::vfunc_43();
}

// @0x140c1a510
void UIGameModeSelectDialog::OnStartClick(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
    m_30->Invoke("popdown");
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140C1A000, UIGameModeSelectDialog, GetTypeName, 61, 0x5110BE61);
MS2_REPLACE_METHOD(0x140C1A050, UIGameModeSelectDialog, vfunc_67, 24, 0x27474BAA);
MS2_REPLACE_METHOD(0x140C1A070, UIGameModeSelectDialog, OnLoadComplete, 786, 0x43F8AF26);
MS2_REPLACE_METHOD(0x140C1A3E0, UIGameModeSelectDialog, vfunc_13, 37, 0xA76943DB);
MS2_REPLACE_METHOD(0x140C1A410, UIGameModeSelectDialog, vfunc_28, 149, 0xF73F36FA);
MS2_REPLACE_METHOD(0x140C1A4B0, UIGameModeSelectDialog, vfunc_26, 45, 0xD437AC42);
MS2_REPLACE_METHOD(0x140C1A4F0, UIGameModeSelectDialog, vfunc_43, 24, 0x1D314201);
MS2_REPLACE_METHOD(0x140C1A510, UIGameModeSelectDialog, OnStartClick, 143, 0xCEEA4664);
