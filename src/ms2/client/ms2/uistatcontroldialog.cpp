// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIStatControlDialog: see uistatcontroldialog.h.
// MS2-UNIT: ?\uistatcontroldialog.cpp
// MS2-RANGE: 0x14134e450-0x14134fc90 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uistatcontroldialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uistatcontroldialog.h"

#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/commandchat.h"

// ---- unit-local placeholders (unrecovered helpers) ----

// The list control of the movie (the AS list with clear / append).
class Unk_StatList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                               // clear
    void FUN_1422dd230(const ASObj& row);               // append a row
};

class ASDialog : public AScript { };

// The key input state (singleton).
class Unk_14025e7c0 { public: bool FUN_14116d840(); };
Unk_14025e7c0* FUN_14025e7c0();

// The local player: the stat values (current / max / base).
class Unk_StatActor
{
public:
    __int64 FUN_1416709d0(int nStat);                   // bonus-free value
    __int64 FUN_141670a30(int nStat);                   // max value
    __int64 FUN_141670a00(int nStat);                   // current value
};
class Unk_StatPlayers { public: Unk_StatActor* FUN_141bd0cc0(); };
Unk_StatPlayers* FUN_1403ed2d0();

// The status / item listener registries (singletons 0x140aa6d40 / 0x140a6a840).
class Unk_StatStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);   // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);   // unregister
};
Unk_StatStatusMgr* FUN_140aa6d40();
class Unk_StatItemEvents;
Unk_StatItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_StatItemEvents*, UIItemEventListener*);
void FUN_1419caeb0(Unk_StatItemEvents*, UIItemEventListener*);

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).
void FUN_141276f80(const Unk_CommandChat&);

const CString& FUN_14082efb0(int nStat);                // the xml name of a stat
CStringW FUN_14082f000(int nStat);                      // the display name of a stat
CStringW FUN_14052bd00(int nId, const CStringW& strArg);    // string table text with one argument
extern int DAT_143ab2914;                               // the character level

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14134e450
UIStatControlDialog::UIStatControlDialog()
{
    m_40 = 1;
    FUN_1422dc3b0(1);
}

// @0x14134fbe0
UIStatControlDialog::~UIStatControlDialog()
{
}

// @0x14134e510
CString UIStatControlDialog::vfunc_1()
{
    return "StatControlDialog";
}

// @0x14134e560
int UIStatControlDialog::vfunc_il1()
{
    if (vfunc_55() != 0)
        return 0;
    return 1;
}

// @0x14134e5b0
int UIStatControlDialog::vfunc_oa0_1()
{
    if (vfunc_55() != 0)
        return 0;
    return 1;
}

// @0x14134e600
void UIStatControlDialog::vfunc_67()
{
    FUN_1419caeb0(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    UIDialog::vfunc_67();
}

// @0x14134e690
void UIStatControlDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_1419cae20(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    FUN_14134f150();
}

// @0x14134e730
int UIStatControlDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (FUN_14025e7c0()->FUN_14116d840() != 0)
    {
        vfunc_67();
        return 1;
    }
    return 0;
}

// @0x14134e790
// MS2-FUNCTIONAL: same calls and branches as the exe; the frame is 0x10 bigger (named locals/temps sit at other slots)
int UIStatControlDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    if (DAT_143ab2914 < 50)
        return 0;
    ASData data;
    if (_stricmp("onSetButton", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nStat = data.FUN_1422b8b10();
            float fValue = (float)data.FUN_1422b8ca0();
            Unk_StatActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pActor != 0)
            {
                CString strCommand;
                strCommand.Format("/SetMaxStat %s %f", (const char*)FUN_14082efb0(nStat), (double)fValue);
                Unk_CommandChat chat;
                chat.kind = 0;
                chat.message = (const char*)strCommand;
                FUN_141276f80(chat);
            }
        }
        return 1;
    }
    else if (_stricmp("onSelectItem", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            Unk_StatActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pActor == 0)
                return 0;
            int nStat = data.FUN_1422b8b10();
            ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30.get());
            if (pDialog != 0)
            {
                __int64 nMax = pActor->FUN_141670a30(nStat);
                pDialog->Invoke("setValue", (float)nMax);
            }
        }
        return 1;
    }
    else if (_stricmp("onResetButton", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nStat = data.FUN_1422b8b10();
            Unk_StatActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pActor != 0)
            {
                CString strCommand;
                strCommand.Format("/ResetMaxStat %s", (const char*)FUN_14082efb0(nStat));
                Unk_CommandChat chat;
                chat.kind = 0;
                chat.message = (const char*)strCommand;
                FUN_141276f80(chat);
            }
        }
        return 1;
    }
    else if (_stricmp("onAllResetButton", szMethod) == 0)
    {
        Unk_StatActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pActor != 0)
        {
            CString strCommand;
            strCommand.Format("/ResetMaxStat all");
            Unk_CommandChat chat;
            chat.kind = 0;
            chat.message = (const char*)strCommand;
            FUN_141276f80(chat);
        }
        return 1;
    }
    return 0;
}

// @0x14134ecb0
void UIStatControlDialog::vfunc_oa0_2()
{
    if (vfunc_55() != 0)
        return;
    FUN_14134f150();
}

// @0x14134ed10
void UIStatControlDialog::vfunc_oa0_3(int a1, int a2)
{
    if (vfunc_55() != 0)
        return;
    FUN_14134f150();
}

// @0x14134ed70
void UIStatControlDialog::vfunc_oa0_4(int a1, int a2)
{
    if (vfunc_55() != 0)
        return;
    FUN_14134f150();
}

// @0x14134edd0
void UIStatControlDialog::vfunc_oa0_5(int a1, int a2)
{
    if (vfunc_55() != 0)
        return;
    FUN_14134f150();
}

// @0x14134ee30
void UIStatControlDialog::vfunc_oa0_6(void* a1, void* a2)
{
    if (vfunc_55() != 0)
        return;
    FUN_14134f150();
}

// @0x14134eea0
void UIStatControlDialog::vfunc_oa0_9(unsigned short a1)
{
    if (vfunc_55() != 0)
        return;
    FUN_14134f150();
}

// @0x14134ef00
void UIStatControlDialog::vfunc_oa0_10(CStringW s)
{
    if (vfunc_55() != 0)
        return;
    FUN_14134f150();
}

// @0x14134ef80
void UIStatControlDialog::vfunc_oa0_7(int a1, CStringW s)
{
    if (vfunc_55() != 0)
        return;
    FUN_14134f150();
}

// @0x14134f000
void UIStatControlDialog::vfunc_21(void* pItem)
{
    if (vfunc_55() != 0 || pItem == 0)
        return;
    FUN_14134f150();
}

// @0x14134f070
void UIStatControlDialog::vfunc_22(void* pItem)
{
    if (vfunc_55() != 0 || pItem == 0)
        return;
    FUN_14134f150();
}

// @0x14134f0e0
void UIStatControlDialog::vfunc_il23(void* pItem)
{
    if (vfunc_55() != 0 || pItem == 0)
        return;
    FUN_14134f150();
}

// @0x14134f150
void UIStatControlDialog::FUN_14134f150()
{
    MS2Ptr<Unk_StatList> list = FUN_140c02900("m_stats");
    if (!list)
        return;
    list->FUN_1422dd1d0();
    FUN_14134f790(list, 4, 0);
    FUN_14134f790(list, 7, 0);
    FUN_14134f790(list, 10, 0);
    FUN_14134f790(list, 0, 0);
    FUN_14134f790(list, 1, 0);
    FUN_14134f790(list, 2, 0);
    FUN_14134f790(list, 3, 0);
    FUN_14134f790(list, 14, 1);
    FUN_14134f790(list, 23, 0);
    FUN_14134f790(list, 24, 0);
    FUN_14134f790(list, 15, 0);
    FUN_14134f790(list, 17, 0);
    FUN_14134f790(list, 18, 0);
    FUN_14134f790(list, 13, 1);
    FUN_14134f790(list, 20, 0);
    FUN_14134f790(list, 25, 0);
    FUN_14134f790(list, 26, 0);
    FUN_14134f790(list, 16, 0);
    FUN_14134f790(list, 19, 0);
    FUN_14134f790(list, 22, 1);
    list->vfunc_24(true);
}

// @0x14134f790
void UIStatControlDialog::FUN_14134f790(MS2Ptr<Unk_StatList> list, int nStat, int bFloat)
{
    ASObj row(2);
    Unk_StatActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pActor == 0)
        return;
    float fBase = (float)pActor->FUN_1416709d0(nStat);
    float fBonus = (float)pActor->FUN_141670a30(nStat) - fBase;
    float fValue = (float)pActor->FUN_141670a00(nStat);
    if (nStat == 4 || nStat == 10 || nStat == 7)
        fValue = (float)pActor->FUN_141670a30(nStat);
    CStringW strValue;
    if (bFloat != 0)
        strValue = FUN_14052bd00(0x98e, StringFormat(L"{0:0.1f}", fValue));
    else
        strValue = StringFormat(L"{0}", (__int64)fValue);
    CStringW strBonus;
    if (fBonus > 0.0f)
    {
        if (bFloat != 0)
            strBonus.Format(L"(%0.1f+%0.1f)", (double)fBase, (double)fBonus);
        else
            strBonus.Format(L"(%d+%d)", (__int64)fBase, (__int64)fBonus);
    }
    else if (fBonus < 0.0f)
    {
        if (bFloat != 0)
            strBonus.Format(L"(%0.1f%0.1f)", (double)fBase, (double)fBonus);
        else
            strBonus.Format(L"(%d%d)", (__int64)fBase, (__int64)fBonus);
    }
    else
    {
        strBonus.Format(L"-");
    }
    CStringW strLabel;
    strLabel.Format(L"[ %s ] [ %s ]", (const wchar_t*)FUN_14082f000(nStat), (const wchar_t*)strValue);
    row.FUN_1407cbb20("label", CStringW(strLabel));
    row.FUN_1409c0d20("statIdx", nStat);
    list->FUN_1422dd230(row);
}
