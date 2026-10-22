// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomeInsideOptionDialog: see uihomeinsideoptiondialog.h.
// MS2-UNIT: ?\uihomeinsideoptiondialog.cpp
// MS2-RANGE: 0x140c27340-0x140c29160 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??8?$MS2Ptr@VUgcHomeBgData@@@@QEBA_NPEAVUgcHomeBgData@@@Z 0x140c28720 ; order
// MS2-PIN: ??8?$MS2Ptr@VUgcHomeCameraData@@@@QEBA_NPEAVUgcHomeCameraData@@@Z 0x140c28760 ; order
// MS2-PIN: ??8?$MS2Ptr@VUgcHomeLightData@@@@QEBA_NPEAVUgcHomeLightData@@@Z 0x140c287a0 ; order
// MS2-PIN: ?GetValueAt@?$CRBTree@IV?$MS2Ptr@VUgcHomeBgData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUgcHomeBgData@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VUgcHomeBgData@@@@PEAU__POSITION@@@Z 0x140c28990 ; order
// MS2-PIN: ?GetValueAt@?$CRBTree@IV?$MS2Ptr@VUgcHomeCameraData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUgcHomeCameraData@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VUgcHomeCameraData@@@@PEAU__POSITION@@@Z 0x140c289f0 ; order
// MS2-PIN: ?GetValueAt@?$CRBTree@IV?$MS2Ptr@VUgcHomeLightData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUgcHomeLightData@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VUgcHomeLightData@@@@PEAU__POSITION@@@Z 0x140c28a50 ; order
// MS2-PIN: ?IsEmpty@?$CRBTree@IV?$MS2Ptr@VUgcHomeBgData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUgcHomeBgData@@@@@3@@ATL@@QEBA_NXZ 0x140c28ab0 ; unique
// MS2-PIN: ?IsEmpty@?$CRBTree@IV?$MS2Ptr@VUgcHomeCameraData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUgcHomeCameraData@@@@@3@@ATL@@QEBA_NXZ 0x140c28ae0 ; order
// MS2-PIN: ?IsEmpty@?$CRBTree@IV?$MS2Ptr@VUgcHomeLightData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUgcHomeLightData@@@@@3@@ATL@@QEBA_NXZ 0x140c28b10 ; order
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihomeinsideoptiondialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uihomeinsideoptiondialog.h"
#include "ugchomebgdata.h"
#include "uimessageboxdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

// The combo box (its slot 24 is the "enable" setter; slots 6..23 are declared so the slot number is right).
class Unk_HioCombo : public ASDisplayObject
{
public:
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
    virtual void vfunc_24(int nEnable);                         // 24
    void FUN_1422dfc10();                                       // clear the items
    void FUN_1422dfc70(const ASObj& item);                    // add an item
    void FUN_1422df690(unsigned int nSelected);                 // select
    unsigned char FUN_1422df6c0();                              // the selection
};
class Unk_HioButton : public ASDisplayObject
{
public:
    int FUN_1422c2030();                                        // is enabled
    void FUN_1422c1fe0(unsigned int bEnabled);                  // set enabled
};
class Unk_HioScript : public AScript
{
public:
    template <class T> MS2Ptr<T> FUN_140bbe700(const CString& strName);   // bind a child of the movie
};

// The selected row of each table (3 bytes), as the exe copies it out of the home setting.
struct Unk_HioSetting
{
    unsigned char m_nBg;
    unsigned char m_nLight;
    unsigned char m_nCamera;
};
class Unk_HioSettingSrc { public: void FUN_1410c34f0(Unk_HioSetting* pOut); };
Unk_HioSettingSrc* FUN_1409670e0();

typedef Delegate<bool(int, const CMsgBoxData&)> HioAnswerDelegate;
CStringW FUN_140298ea0(CStringW strKey);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released
void FUN_140710590(COutPacket& packet);                         // send the packet

// @0x140c27340
UIHomeInsideOptionDialog::UIHomeInsideOptionDialog()
{
    m_80 = 0;
    FUN_141924170(1);
}

// @0x140c273b0
UIHomeInsideOptionDialog::~UIHomeInsideOptionDialog()
{
}

// @0x140c273f0
CString UIHomeInsideOptionDialog::GetTypeName()
{
    return "HomeInsideOptionDialog";
}

// @0x140c27440
// MS2-FUNCTIONAL: the exe keeps extra call-result temporaries (frame / slot order differs); source form unknown
void UIHomeInsideOptionDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_HioSetting setting;
    FUN_1409670e0()->FUN_1410c34f0(&setting);
    ATL::CRBMap<unsigned, MS2Ptr<UgcHomeBgData> >* pBgs = &UgcHomeOptionData::GetInstance()->m_mapBg;
    if (!pBgs->IsEmpty())
    {
        MS2Ptr<Unk_HioCombo> spCombo = FUN_140c28560<Unk_HioCombo>("m_background");
        if (spCombo.get() != 0)
        {
            spCombo.operator->()->FUN_1422dfc10();
            for (POSITION pos = pBgs->GetHeadPosition(); pos != 0; pBgs->GetNext(pos))
            {
                MS2Ptr<UgcHomeBgData> spRow = pBgs->GetValueAt(pos);
                if (!(spRow == 0))
                {
                    ASObj item(2);
                    item.FUN_1407cbb20("label", spRow->m_strName);
                    spCombo.operator->()->FUN_1422dfc70(item);
                }
            }
            unsigned int nSelected = setting.m_nBg;
            spCombo.operator->()->FUN_1422df690(nSelected);
            Unk_HioCombo* pCombo = spCombo.operator->();
            pCombo->vfunc_24(1);
        }
    }
    ATL::CRBMap<unsigned, MS2Ptr<UgcHomeLightData> >* pLights = &UgcHomeOptionData::GetInstance()->m_mapLight;
    if (!pLights->IsEmpty())
    {
        MS2Ptr<Unk_HioCombo> spCombo = FUN_140c28560<Unk_HioCombo>("m_light");
        if (spCombo.get() != 0)
        {
            spCombo.operator->()->FUN_1422dfc10();
            for (POSITION pos = pLights->GetHeadPosition(); pos != 0; pLights->GetNext(pos))
            {
                MS2Ptr<UgcHomeLightData> spRow = pLights->GetValueAt(pos);
                if (!(spRow == 0))
                {
                    ASObj item(2);
                    item.FUN_1407cbb20("label", spRow->m_strName);
                    spCombo.operator->()->FUN_1422dfc70(item);
                }
            }
            unsigned int nSelected = setting.m_nLight;
            spCombo.operator->()->FUN_1422df690(nSelected);
            Unk_HioCombo* pCombo = spCombo.operator->();
            pCombo->vfunc_24(1);
        }
    }
    ATL::CRBMap<unsigned, MS2Ptr<UgcHomeCameraData> >* pCameras = &UgcHomeOptionData::GetInstance()->m_mapCamera;
    if (!pCameras->IsEmpty())
    {
        MS2Ptr<Unk_HioCombo> spCombo = FUN_140c28560<Unk_HioCombo>("m_camera");
        if (spCombo.get() != 0)
        {
            spCombo.operator->()->FUN_1422dfc10();
            for (POSITION pos = pCameras->GetHeadPosition(); pos != 0; pCameras->GetNext(pos))
            {
                MS2Ptr<UgcHomeCameraData> spRow = pCameras->GetValueAt(pos);
                if (!(spRow == 0))
                {
                    ASObj item(2);
                    item.FUN_1407cbb20("label", spRow->m_strName);
                    spCombo.operator->()->FUN_1422dfc70(item);
                }
            }
            unsigned int nSelected = setting.m_nCamera;
            spCombo.operator->()->FUN_1422df690(nSelected);
            Unk_HioCombo* pCombo = spCombo.operator->();
            pCombo->vfunc_24(1);
        }
    }
}

// @0x140c27af0
// MS2-FUNCTIONAL: the exe keeps extra call-result temporaries (frame / slot order differs); source form unknown
int UIHomeInsideOptionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    if (_stricmp("OnApply", szMethod) == 0)
    {
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_140298ea0(CStringW(L"s_home_option_msg_confirm")), 0, CStringW(L""));
        if (box.get() != 0)
        {
            box.operator->()->FUN_141a027c0(HioAnswerDelegate(this, &UIHomeInsideOptionDialog::FUN_140c27fd0));
            FUN_140d73c60(box);
        }
    }
    else if (_stricmp("OnConfirm", szMethod) == 0)
    {
        MS2Ptr<Unk_HioButton> spApply = FUN_140bb4b10("m_apply");
        if (spApply.get() != 0)
        {
            if (spApply.operator->()->FUN_1422c2030() == 0)
            {
                vfunc_67();
            }
            else
            {
                MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_140298ea0(CStringW(L"s_home_option_msg_confirm")), 0, CStringW(L""));
                if (box.get() != 0)
                {
                    box.operator->()->FUN_141a027c0(HioAnswerDelegate(this, &UIHomeInsideOptionDialog::FUN_140c28000));
                    FUN_140d73c60(box);
                }
            }
        }
    }
    return 1;
}

// @0x140c27fd0
bool UIHomeInsideOptionDialog::FUN_140c27fd0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
        FUN_140c280d0();
    return true;
}

// @0x140c28000
// MS2-FUNCTIONAL: the exe keeps three copies of the bind result pointer (frame 0x20 larger); source form unknown
bool UIHomeInsideOptionDialog::FUN_140c28000(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        MS2Ptr<Unk_HioButton> spApply = FUN_140bb4b10("m_apply");
        if (spApply.get() != 0)
        {
            if (spApply.operator->()->FUN_1422c2030() != 0)
                FUN_140c280d0();
            vfunc_67();
        }
    }
    return true;
}

// @0x140c280d0
// MS2-FUNCTIONAL: the exe keeps extra call-result temporaries (frame / slot order differs); source form unknown
void UIHomeInsideOptionDialog::FUN_140c280d0()
{
    MS2Ptr<Unk_HioCombo> spBg = FUN_140c28560<Unk_HioCombo>("m_background");
    if (spBg.get() != 0)
    {
        unsigned char nSelected = spBg.operator->()->FUN_1422df6c0();
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.vfunc_o10_1(0x33);
        packet.vfunc_o10_1(nSelected);
        FUN_140710590(packet);
    }
    MS2Ptr<Unk_HioCombo> spLight = FUN_140c28560<Unk_HioCombo>("m_light");
    if (spLight.get() != 0)
    {
        unsigned char nSelected = spLight.operator->()->FUN_1422df6c0();
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.vfunc_o10_1(0x34);
        packet.vfunc_o10_1(nSelected);
        FUN_140710590(packet);
    }
    MS2Ptr<Unk_HioCombo> spCamera = FUN_140c28560<Unk_HioCombo>("m_camera");
    if (spCamera.get() != 0)
    {
        unsigned char nSelected = spCamera.operator->()->FUN_1422df6c0();
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.vfunc_o10_1(0x36);
        packet.vfunc_o10_1(nSelected);
        FUN_140710590(packet);
    }
    MS2Ptr<Unk_HioButton> spApply = FUN_140bb4b10("m_apply");
    if (spApply.get() != 0)
        spApply.operator->()->FUN_1422c1fe0(0);
}

// @0x140c28560
// MS2-FUNCTIONAL: branch layout of the return-by-value binder differs by two bytes; source form unknown
template <class T> MS2Ptr<T> UIHomeInsideOptionDialog::FUN_140c28560(const CString& strName)
{
    if (FUN_140ba28d0(&m_30, 0))
    {
        return MS2Ptr<T>(0);
    }
    else
    {
        return static_cast<Unk_HioScript*>(m_30.operator->())->FUN_140bbe700<T>(strName);
    }
}
