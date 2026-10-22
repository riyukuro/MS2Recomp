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
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> EsClickDelegate;

class Unk_EsButton : public ASDisplayObject
{
public:
    void FUN_1422ce240(const EsClickDelegate& onClick, int nFlags);     // click callback
};

// The click event: the pressed button is read from +0x30.
struct Unk_EsParams { char m_pad[0x30]; void* m_pButton; };
int FUN_140bd09c0(void* pButton);                                       // which button (1 = lottery, 2 = exp mode)

// The sound event sink (FUN_140d8ee90).
class Unk_EsSound { public: void FUN_140a1f970(const CString& strEvent, const CString& strArg); };
Unk_EsSound* FUN_140d8ee90();
// The feature flag table (FUN_140166410).
class Unk_EsFeature { public: unsigned char FUN_14036d570(int id); };
Unk_EsFeature* FUN_140166410();

// The npc talk machinery, as in mypc.cpp.
class Unk_MyPCTalkScript;
struct Unk_MyPCTalkScriptPtr
{
    Unk_MyPCTalkScriptPtr(Unk_MyPCTalkScript* p);           // 0x140859c20
    Unk_MyPCTalkScriptPtr(const Unk_MyPCTalkScriptPtr& o);  // (passed by value, built in place)
    ~Unk_MyPCTalkScriptPtr();                               // 0x14078f140
    Unk_MyPCTalkScript* FUN_14078f3a0() const;              // get
    void* m_00;
    Unk_MyPCTalkScript* m_p;
};
Unk_MyPCTalkScriptPtr FUN_140856820(int nNpcId, int nKind);
class Unk_MyPCSurvival
{
public:
    int FUN_141b213f0(Unk_MyPCTalkScriptPtr spScript, int nNpcId, int nMode, int n);
    void FUN_141b1eb90(CStringA strDialog, CStringA strArg);
};
Unk_MyPCSurvival* FUN_140967100();

// The world / local player (FUN_1403ed2d0 / FUN_141bd0cc0); vfunc 65 (0x208) is "talk state".
class Unk_EsWorld;
Unk_EsWorld* FUN_1403ed2d0();
void* FUN_141bd0cc0(Unk_EsWorld* pWorld);
char* FUN_1401d3200();                                                  // the constants table
int* FUN_1402056b0(char* pEntry);
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
        FUN_140d8ee90()->FUN_140a1f970(strEvent, strArg);
    }
    m_type1Button = 0;
    m_type2Button = 0;
}

// MS2-FUNCTIONAL: OnLoadComplete: the exe keeps the MS2Ptr temps and delegate copies of each button hook (frame 0x198 vs 0x138)
// @0x140e29410
void UIEnchantSelectDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_close");
    FUN_1419260d0("m_webGuideButton", 0);
    if (FUN_140bc6d10("m_type1Button", m_type1Button).get() != 0)
        m_type1Button->FUN_1422ce240(EsClickDelegate(this, &UIEnchantSelectDialog::FUN_140e29860), 1);
    if (FUN_140bc6d10("m_type2Button", m_type2Button).get() != 0)
        m_type2Button->FUN_1422ce240(EsClickDelegate(this, &UIEnchantSelectDialog::FUN_140e29860), 2);
    MS2Ptr<ASMovieClip> recommend = FUN_140ba7930("m_recommendType2");
    if (recommend.get() != 0)
        recommend->vfunc_4(FUN_140166410()->FUN_14036d570(0xfc));
    {
        CString strArg("enchant");
        CString strEvent("dialog_open");
        FUN_140d8ee90()->FUN_140a1f970(strEvent, strArg);
    }
}

// MS2-FUNCTIONAL: FUN_140e29860: string/handle temps and the vfunc call shape differ
// @0x140e29860
void UIEnchantSelectDialog::FUN_140e29860(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nButton = FUN_140bd09c0(((Unk_EsParams*)&params)->m_pButton);
    CString strMode;
    int nNpcId = 0;
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
    void* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc != 0 && ((int (*)(void*))(*(void***)pPc)[0x208 / 8])(pPc) == 1)
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_error_talk_battle_state_force_talk"), 1, 1);
        return;
    }
    if (nNpcId != 0)
    {
        Unk_MyPCTalkScript* pScript = FUN_140856820(nNpcId, *FUN_1402056b0(FUN_1401d3200() + 0x69a0)).FUN_14078f3a0();
        if (pScript != 0)
        {
            FUN_140967100()->FUN_141b213f0(Unk_MyPCTalkScriptPtr(pScript), nNpcId, 2, 0);
            FUN_140967100()->FUN_141b1eb90(CStringA(strMode), CStringA("ItemEnchantDialog"));
        }
    }
    vfunc_67();
}
MS2_REPLACE_METHOD(0x140E29360, UIEnchantSelectDialog, vfunc_67, 160, 0x553DC0A2);
MS2_REPLACE_METHOD(0x140E29410, UIEnchantSelectDialog, OnLoadComplete, 1090, 0x1F3883A7);
MS2_REPLACE_METHOD(0x140E29860, UIEnchantSelectDialog, FUN_140e29860, 715, 0x841B273B);
