// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUGCExtraCNDialog: see uiugcextracndialog.h.
// MS2-UNIT: ?\uiugcextracndialog.cpp
// MS2-RANGE: 0x140facb20-0x140fadb00 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugcextracndialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiugcextracndialog.h"
#include "uimessageboxdata.h"
#include <efd/ServiceManager.h>
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140fad9e0
MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

// The camera mode button (a button with a label and an "m_icon" movie clip).
class Unk_UgcCameraButton : public ASDisplayObject
{
public:
    void FUN_1422c1fe0(bool bEnable);                           // enable / disable
    void FUN_1422cdf50(const CString& strLabel);                // set the label
};
// The screenshot service: slot 2 says whether a screenshot can be taken, slot 54 takes it and returns 1 when it was sent.
class Unk_UgcShot
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2();
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
    virtual int vfunc_54(const struct Unk_UgcPos& pos, const struct Unk_UgcId& id, int nMode, CStringW strPath);   // MS2: slot 54 (+0x1b0)
};
Unk_UgcShot* FUN_140d86260();
struct Unk_UgcPos { void* m_0; void* m_8; void* m_10; };
struct Unk_UgcId { void* m_0; };
struct Unk_UgcMode { unsigned char m_0; unsigned char m_1; unsigned char m_2; unsigned char m_3; void* m_pad; };
class Unk_UgcPlace
{
public:
    Unk_UgcPos FUN_1410c31d0();
    Unk_UgcId FUN_1410c3260();
    Unk_UgcMode FUN_1410c34f0();
};
Unk_UgcPlace* FUN_1409670e0();
class Unk_UgcUiMgr { public: void FUN_141adc5d0(int nId); void FUN_141adc530(int nId); };
Unk_UgcUiMgr* FUN_1403ed2b0();
class Unk_UgcCam { public: void FUN_140947980(int n); };
Unk_UgcCam* FUN_1409478c0();
class Unk_UgcLook { public: void FUN_140b683f0(unsigned char n); };
Unk_UgcLook* FUN_140b6a040();
// The update list of the entity app (its count and item i; slot 1 of an item is its per-frame update).
class Unk_UgcUpdatable { public: virtual void vfunc_0(); virtual void vfunc_1(float fTime); };
class Unk_UgcUpdateList { public: unsigned FUN_140c2b8c0(); Unk_UgcUpdatable* FUN_140c2b890(unsigned n); };
efd::ServiceManager* FUN_1413f9850();                           // the game's service manager
Unk_UgcUpdateList* FUN_1413f9890();
CStringW FUN_141850100(int a, int b);                           // the screenshot path
void FUN_141275260(int nId, int a, int b);                      // show a notice by id
CStringW FUN_14028b8e0(const CStringW& strKey);                 // string table text
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
void FUN_141a024a0(CMsgBoxData* pBox, bool b);

// @0x140facb20
UIUGCExtraCNDialog::UIUGCExtraCNDialog()
{
    m_bCameraMode = false;
    FUN_141925e70(1, 1);
    m_2c = 10;
}

// @0x140facba0
UIUGCExtraCNDialog::~UIUGCExtraCNDialog()
{
}

// @0x140facbe0
void UIUGCExtraCNDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140fad4f0(false);
}

// @0x140facc10
CString UIUGCExtraCNDialog::GetTypeName()
{
    return "UGCExtraCNDialog";
}

// @0x140facc60
int UIUGCExtraCNDialog::vfunc_52()
{
    return 1;
}

// @0x140facc80
void UIUGCExtraCNDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_bCameraMode = false;
}

// MS2-FUNCTIONAL: call-result temporaries / frame slots differ from the exe
// @0x140faccb0
int UIUGCExtraCNDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onCameraMode", szMethod) == 0)
    {
        FUN_140fad4f0(m_bCameraMode == 0);
    }
    else if (_stricmp("onScreenShot", szMethod) == 0)
    {
        Unk_UgcShot* pShot = FUN_140d86260();
        if (pShot->vfunc_2() == 1)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14028b8e0(CStringW(L"s_msg_ugc_home_upload_screenshot")), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                FUN_141a024a0(spBox.get(), false);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIUGCExtraCNDialog::FUN_140fad0a0));
                FUN_140d73c60(spBox);
            }
        }
        else
        {
            FUN_141850100(0, 1);
        }
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: exe keeps extra call-result temporaries
// @0x140facfa0
void UIUGCExtraCNDialog::FUN_140facfa0(bool bCameraMode)
{
    if (bCameraMode)
        FUN_140fad4f0(false);
    MS2Ptr<Unk_UgcCameraButton> spButton = FUN_140bb4b10(CString("m_cameraMode"));
    if (spButton.get() != 0)
        spButton.operator->()->FUN_1422c1fe0(bCameraMode == 0);
}

// @0x140fad070
void UIUGCExtraCNDialog::FUN_140fad070(bool bCameraMode)
{
    FUN_140facfa0(bCameraMode);
}

// MS2-FUNCTIONAL: exe keeps extra call-result temporaries (frame 0x18 larger)
// @0x140fad0a0
bool UIUGCExtraCNDialog::FUN_140fad0a0(int nResult, const CMsgBoxData& box)
{
    efd::ServiceManager* pManager = FUN_1413f9850();
    if (pManager == 0)
        return false;
    Unk_UgcUpdateList* pList = FUN_1413f9890();
    if (pList == 0)
        return false;
    double dTime = pManager->GetTime(0xe001001b);
    for (unsigned i = 0; i < pList->FUN_140c2b8c0(); i++)
    {
        Unk_UgcUpdatable* pItem = pList->FUN_140c2b890(i);
        if (pItem != 0)
            pItem->vfunc_1((float)dTime);
    }
    CStringW strPath = FUN_141850100(0, 1);
    if (nResult == 0 && !strPath.IsEmpty())
    {
        Unk_UgcShot* pShot = FUN_140d86260();
        if (pShot->vfunc_54(FUN_1409670e0()->FUN_1410c31d0(), FUN_1409670e0()->FUN_1410c3260(), 0xd0, CStringW(strPath)) == 1)
            FUN_141275260(0x466, 1, 1);
    }
    return true;
}

// MS2-FUNCTIONAL: exe keeps extra call-result temporaries (CString/handle slots)
// @0x140fad2b0
void UIUGCExtraCNDialog::FUN_140fad2b0()
{
    MS2Ptr<Unk_UgcCameraButton> spButton = FUN_140bb4b10(CString("m_cameraMode"));
    if (spButton.get() != 0)
    {
        if (m_bCameraMode == 0)
            spButton.operator->()->FUN_1422cdf50("$s_camera_free");
        else
            spButton.operator->()->FUN_1422cdf50("$s_camera_default");
        MS2Ptr<ASMovieClip> spIcon = spButton.operator->()->FUN_1409b4560("m_icon");
        if (spIcon.get() != 0)
        {
            if (m_bCameraMode == 0)
                spIcon.operator->()->vfunc_15("free");
            else
                spIcon.operator->()->vfunc_15("default");
        }
    }
}

// MS2-FUNCTIONAL: exe keeps extra call-result temporaries
// @0x140fad4f0
void UIUGCExtraCNDialog::FUN_140fad4f0(bool bCameraMode)
{
    m_bCameraMode = bCameraMode;
    if (m_bCameraMode == 0)
    {
        Unk_UgcMode mode = FUN_1409670e0()->FUN_1410c34f0();
        FUN_140b6a040()->FUN_140b683f0(mode.m_2);
        FUN_1403ed2b0()->FUN_141adc5d0(0x4f3e);
    }
    else
    {
        FUN_1409478c0()->FUN_140947980(6);
        FUN_1403ed2b0()->FUN_141adc530(0x4f3e);
    }
    FUN_140fad2b0();
}
