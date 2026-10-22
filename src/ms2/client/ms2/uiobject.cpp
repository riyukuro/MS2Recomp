// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIObject, the base of every game UI object.
// MS2-UNIT: ?\uiobject.cpp
// MS2-RANGE: 0x14131e150-0x14131f690 .text$mn
// MS2-RANGE: 0x1400ef1c0-0x1400ef351 .text$di
// MS2-RANGE: 0x142cafdc0-0x142cafe65 .text$yd
//
// The unit has no __FILE__ string (no asserts); its directory (client\ms2) is assumed from its neighbours. Names are
// Ghidra's (vfunc_<slot> / FUN_<va>) unless the exe has one (RTTI: UIGameDictionaryDialog, UIQuestDialog,
// ASUIComponent, ASTooltip); GetDialog is invented. The COMDAT tail is the Delegate<void(const Params&)> binding of
// UIObject::vfunc_51 (delegate.h), GetDialog<T> and the CRT memmove_s copy.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiobject.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uiobject.h"

#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/uidialog.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astooltip.h"

static UICommon::CMyPCKeyInputController s_keyInputController;     // header static (origin unknown), 0x143ad7930

// ---- unit-local placeholders (unrecovered singletons / helpers; promote to src/ms2/placeholder/ when shared) ----


class ASUIComponent : public AScript    // RTTI .?AVASUIComponent@@
{
public:
    void FUN_1422c7a90(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> callback, int n);
};
void FUN_1422c6380(Scaleform::GFx::Value& value, int nGroup);
void FUN_1422c63f0(Scaleform::GFx::Value& value, int nGroup);


extern int g_nDebugUI;                  // 0x143ae0fc0 (name invented): debug UI information on

void FUN_141901420(int n, int nUIType);
CStringW FUN_140718650(const CString& str);                 // CString -> CStringW
void FUN_1412751b0(const CStringW& strText, int nType);     // system message
void FUN_1412751f0(const CStringW& strText, int a1, int a2);
CStringW GetStringCommonByKey(const CStringW& strKey);             // localised string
CStringW FUN_1402a5170(const wchar_t* szFormat, const CString& a1);    // "{0}" formatter
void FUN_141276180(const CString& strSound, const CString& strArg);    // play a system sound
int FUN_1407181d0(const CString& str);
int FUN_140718170(const CString& str);
void FUN_1418fe1c0(const CString& strUrl);

class Unk_140c43790 { public: void FUN_14135ec00(const CString& strUrl, bool b); };
Unk_140c43790* FUN_140c43790(int nUIType);
class Unk_140961730 : public UIDialog { public: void FUN_141b5bc70(int nMapId); };
Unk_140961730* FUN_140961730(int nUIType);
class Unk_140b99ba0 { public: void FUN_140e74550(int nId); };
Unk_140b99ba0* FUN_140b99ba0(int nUIType);
class Unk_140961550 : public UIDialog { public: int FUN_141924630(); void FUN_1412b8ff0(int nDungeonId); };
Unk_140961550* FUN_140961550(int nUIType);

class Unk_1401aa6a0                     // 8-byte dictionary key (ctor 0x1401aa6a0)
{
public:
    Unk_1401aa6a0(int nId);
    Unk_1401aa6a0(const Unk_1401aa6a0& o);  // user copy ctor + dtor: by-value args go through a caller temp
    ~Unk_1401aa6a0();

private:
    int m_00;
    int m_04;
};
class Unk_1401a9d70 { public: Unk_1401aa6a0 FUN_141811980(int a1, int nId); };
Unk_1401a9d70* FUN_1401a9d70();

class UIGameDictionaryDialog : public UIDialog
{
public:
    void FUN_140f46ea0(int nTab, Unk_1401aa6a0 key, int n);
};
class UIQuestDialog : public UIDialog
{
public:
    int FUN_141a9c290(int nQuestId);
    void FUN_141a9bff0(int nQuestId);
};

class Unk_1406cd330 { public: int FUN_1406ccfc0(); };       // NPC data
MS2Ptr<Unk_1406cd330> FUN_1406cd330(int nNpcId);

class Unk_1403ed2b0 { public: MS2Ptr<UIObject> FUN_141adcea0(int nUIType); };
Unk_1403ed2b0* FUN_1403ed2b0();

class Unk_140166410 { public: bool FUN_14036d750(const CStringW& strLocale); };
Unk_140166410* FUN_140166410();
int FUN_140651920(CString str);
int FUN_1406516a0();

// The UI object of type nUIType, if it is a T (COMDAT template; name invented).
template <class T>
T* GetDialog(int nUIType)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nUIType);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14131e150
UIObject::UIObject()
{
}

// @0x14131e1a0
UIObject::~UIObject()
{
}

// @0x14131e1e0
CString UIObject::GetTypeName()
{
    return "Object";
}
MS2_REPLACE_METHOD(0x14131E1E0, UIObject, GetTypeName, 61, 0x1D384CF7);

// @0x14131e230
void UIObject::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (strMethod == "getTooltip")
        vfunc_49(pRetVal, pArgs);
    else if (strMethod == "playSystemSound")
        vfunc_50(pRetVal, pArgs);

    if (strMethod == "webPage") {
        CString strUrl = pArgs->FUN_1422b8d30();
        Unk_140c43790* p = FUN_140c43790(0x4e6a);
        if (p == NULL)
            return;
        p->FUN_14135ec00(strUrl, true);
    } else if (strMethod == "externalWeb") {
        CString strUrl = pArgs->FUN_1422b8d30();
        FUN_1418fe1c0(strUrl);
    } else if (strMethod == "worldmap") {
        int nMapId = FUN_1407181d0(pArgs->FUN_1422b8d30());
        Unk_140961730* p = FUN_140961730(0x4e42);
        if (p == NULL)
            return;
        p->FUN_141b5bc70(nMapId);
        p->FUN_141924680();
    } else if (strMethod == "quest") {
        int nQuestId = FUN_1407181d0(pArgs->FUN_1422b8d30());
        UIQuestDialog* p = GetDialog<UIQuestDialog>(0x4e3e);
        if (p == NULL)
            return;
        if (p->FUN_141a9c290(nQuestId) == 0) {
            FUN_1412751f0(GetStringCommonByKey(L"s_quest_dialog_unknown_quest"), 1, 1);
            return;
        }
        p->FUN_141a9bff0(nQuestId);
        p->FUN_141924680();
    } else if (strMethod == "itemdictionary") {
        int nItemId = FUN_1407181d0(pArgs->FUN_1422b8d30());
        UIGameDictionaryDialog* p = GetDialog<UIGameDictionaryDialog>(0x4f0b);
        if (p == NULL)
            return;
        p->FUN_140f46ea0(3, FUN_1401a9d70()->FUN_141811980(1, nItemId), 1);
        p->FUN_141924680();
    } else if (strMethod == "npcdictionary") {
        int nNpcId = FUN_1407181d0(pArgs->FUN_1422b8d30());
        UIGameDictionaryDialog* p = GetDialog<UIGameDictionaryDialog>(0x4f0b);
        if (p == NULL)
            return;
        MS2Ptr<Unk_1406cd330> pNpc = FUN_1406cd330(nNpcId);
        if (pNpc == NULL)
            return;
        if (pNpc->FUN_1406ccfc0() > 0)
            p->FUN_140f46ea0(1, Unk_1401aa6a0(nNpcId), 1);
        else
            p->FUN_140f46ea0(2, Unk_1401aa6a0(nNpcId), 1);
        p->FUN_141924680();
    } else if (strMethod == "petCollectGroup") {
        int nGroupId = FUN_140718170(pArgs->FUN_1422b8d30());
        Unk_140b99ba0* p = FUN_140b99ba0(0x4f38);
        if (p == NULL)
            return;
        p->FUN_140e74550(nGroupId);
    } else if (strMethod == "dungeon") {
        int nDungeonId = FUN_1407181d0(pArgs->FUN_1422b8d30());
        Unk_140961550* p = FUN_140961550(0x4ebd);
        if (p == NULL)
            return;
        if (p->FUN_141924630())
            p->vfunc_68();
        p->FUN_1412b8ff0(nDungeonId);
        p->FUN_141924680();
    } else if (strMethod == "isEnableLocale") {
        CStringW strLocale = pArgs->FUN_1422b8f40();
        bool bEnable = FUN_140166410()->FUN_14036d750(strLocale);
        Scaleform::GFx::Value value(bEnable);
        *pRetVal = value;
    } else if (strMethod == "isEnableLanguage") {
        CString strLanguage = pArgs->FUN_1422b8d30();
        bool bEnable = FUN_140651920(strLanguage) == FUN_1406516a0();
        Scaleform::GFx::Value value(bEnable);
        *pRetVal = value;
    }
}
MS2_REPLACE_METHOD(0x14131E230, UIObject, vfunc_45, 2216, 0x306BF590);

// @0x14131eae0
void UIObject::OnLoadInit()
{
    UISwfEntity::OnLoadInit();
    if (g_nDebugUI) {
        CString strName = m_20.Mid(0, m_20.ReverseFind('_'));
        strName = strName.Mid(0, strName.ReverseFind('_'));
        strName.Format("Swf Name : %s", (const char*)strName);
        FUN_1412751b0(FUN_140718650(strName), 0x14);
    }
}
MS2_REPLACE_METHOD(0x14131EAE0, UIObject, OnLoadInit, 272, 0x5906B2D0);

// @0x14131ec00
// Not in the hook DLL: DLL callers (subclass OnLoadComplete overrides call UIObject::OnLoadComplete by name) bind the
// exe's copy (symbols.tsv); the DLL body would hand the exe a DelegateImpl with the DLL's vftable/RTTI (hooked
// UILoadingProgress::OnLoadComplete -> the title never loaded, fx6).
#ifndef MS2_HOOK_DLL
void UIObject::OnLoadComplete()
{
    UISwfEntity::OnLoadComplete();
    int nGroup = FUN_1422db730();
    if (nGroup == 2) {
        ASUIComponent* p = dynamic_cast<ASUIComponent*>((AScript*)m_30);
        if (p) {
            p->FUN_1422c7a90(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIObject::vfunc_51), 0);
            FUN_1422c6380(p->FUN_1422bb870(), nGroup);
        }
    }
}
#endif
// Not hooked: builds a DelegateImpl with the DLL's vftable/RTTI and hands it to the exe (see section 9).

// @0x14131ed10
void UIObject::vfunc_26()
{
    UISwfEntity::vfunc_26();
    int nGroup = FUN_1422db730();
    if (nGroup == 2) {
        ASUIComponent* p = dynamic_cast<ASUIComponent*>((AScript*)m_30);
        if (p)
            FUN_1422c63f0(p->FUN_1422bb870(), FUN_1422db730());
    }
}
MS2_REPLACE_METHOD(0x14131ED10, UIObject, vfunc_26, 145, 0xF503749B);

// @0x14131edb0
void UIObject::vfunc_47(int n)
{
    FUN_141901420(n, vfunc_48());
}
MS2_REPLACE_METHOD(0x14131EDB0, UIObject, vfunc_47, 48, 0xD5BC974C);

// @0x14131edf0
void UIObject::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
}
MS2_REPLACE_METHOD(0x14131EDF0, UIObject, vfunc_49, 16, 0xB7F2802D);

// @0x14131ee10
void UIObject::vfunc_50(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    FUN_141276180(pArgs->FUN_1422b8d30(), "");
}
MS2_REPLACE_METHOD(0x14131EE10, UIObject, vfunc_50, 121, 0x7B802993);

// @0x14131ee90
void UIObject::vfunc_42(GfxException* pException)
{
    if (pException)
        MessageBoxA(NULL, pException->what(), "Exception", 0);
    FUN_1422dc0b0();
}
MS2_REPLACE_METHOD(0x14131EE90, UIObject, vfunc_42, 74, 0x59E38CB2);

// @0x14131eee0
void UIObject::vfunc_51(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == NULL)
        return;
    if (g_nDebugUI) {
        CStringW strText = FUN_1402a5170(L"[Debug SWF Name]\nUI{0}.swf", vfunc_7());
        ASTooltip tooltip(1, 2);
        tooltip.FUN_1409c6dc0(5);
        tooltip.FUN_1409c6e90(0x14);
        if (tooltip.FUN_1409e26b0(strText))
            *params.pRetVal = tooltip.FUN_1422bb870();
    }
}
MS2_REPLACE_METHOD(0x14131EEE0, UIObject, vfunc_51, 280, 0x46F4F902);

MS2_EMIT_CRT_MEMMOVE_S();  // memmove_s 0x14131f570
