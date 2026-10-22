// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIEnterEventFieldDialog: see uientereventfielddialog.h. w276.
// MS2-UNIT: ?\uientereventfielddialog.cpp
// MS2-RANGE: 0x140f3fb10-0x140f40ce0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVUIEnterEventFieldDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIEnterEventFieldDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x140f40670 ; prop
// MS2-PIN: ??$?8PEAVUIEnterEventFieldDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIEnterEventFieldDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140f406e0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIEnterEventFieldDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x140f40820 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIEnterEventFieldDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f40a70 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIEnterEventFieldDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f40ad0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIEnterEventFieldDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140f40b30 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIEnterEventFieldDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140f40b60 ; unique
// MS2-PIN: ??$Call@VUIEnterEventFieldDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIEnterEventFieldDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIEnterEventFieldDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x140f40ba0 ; unique
// MS2-PIN: ??$Call@VUIEnterEventFieldDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIEnterEventFieldDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIEnterEventFieldDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140f40be0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIEnterEventFieldDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f40c20 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIEnterEventFieldDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f40c80 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GUIEnterEventFieldDialog@@UEAAPEAXI@Z 0x140f40a20
// MS2-PIN: ?vfunc_48@UIEnterEventFieldDialog@@UEAAHXZ 0x140f40a60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uientereventfielddialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uientereventfielddialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe types ----

// The movie root of the dialog (the exe's dynamic_cast target).
class ASDialog : public ASGameEntity
{
public:
    float FUN_1422c10a0();                                      // x
    float FUN_1422c1110();                                      // y
};

// WorldService singleton (FUN_1403ed2d0).
class Unk_EnterWorld
{
public:
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                      // the current field data
};
Unk_EnterWorld* FUN_1403ed2d0();

// The string table (FUN_1401a9d70).
class Unk_EnterStrings
{
public:
    CStringW FUN_141811980(int nTable, int nIndex);
};
Unk_EnterStrings* FUN_1401a9d70();

// The notice dispatcher (FUN_140939a10).
class Unk_EnterNotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb);    // subscribe
};
Unk_EnterNotices* FUN_140939a10();

CStringW FUN_14052bd00(int id, const CStringW& arg);            // formatted system text
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int nType);    // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                    // show it
void FUN_140710590(COutPacket& packet);                         // send the packet
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released
UIObject* FUN_140c9b540(int nClass);                            // the HUD dialog of this class id
int FUN_1422c2510(ASMovieClip* p, double* pX, __int64* pY);     // x position of a clip

// @0x140f3fb10
UIEnterEventFieldDialog::UIEnterEventFieldDialog()
{
    m_2c = 0x19;
    FUN_141925e70(0, 1);
    m_nFieldId = 0;
}

// @0x140f3fba0
UIEnterEventFieldDialog::~UIEnterEventFieldDialog()
{
}

// @0x140f3fbe0
CString UIEnterEventFieldDialog::GetTypeName()
{
    return "EnterEventFieldDialog";
}
MS2_REPLACE_METHOD(0x140F3FBE0, UIEnterEventFieldDialog, GetTypeName, 61, 0x33340729);

// @0x140f3fc30
void UIEnterEventFieldDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140F3FC30, UIEnterEventFieldDialog, vfunc_67, 24, 0xA0D210C0);

// @0x140f3fc50
// MS2-FUNCTIONAL: the exe override returns a bool (al) in an int slot
int UIEnterEventFieldDialog::vfunc_65()
{
    return UIDialog::vfunc_65() != 0;
}
MS2_REPLACE_METHOD(0x140F3FC50, UIEnterEventFieldDialog, vfunc_65, 37, 0xAB784FE8);

// @0x140f3fc80
void UIEnterEventFieldDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140939a10()->FUN_140da4e40(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UIEnterEventFieldDialog::OnNotifyGameStart));
    m_tick.FUN_140268840();
    UpdateVisible();
}
MS2_REPLACE_METHOD(0x140F3FC80, UIEnterEventFieldDialog, OnLoadComplete, 255, 0x60BA1C25);

// @0x140f3fd90
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe
int UIEnterEventFieldDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onEnterEventField", szMethod) != 0)
        return 0;
    CStringW strText = FUN_14052bd00(0xc3e, FUN_1401a9d70()->FUN_141811980(3, m_nFieldId));
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(strText, 1);
    if (spBox.get() != 0)
    {
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIEnterEventFieldDialog::OnEnterConfirm));
        FUN_140d73c60(spBox);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140F3FD90, UIEnterEventFieldDialog, vfunc_28, 533, 0x78B53F59);

// @0x140f3ffb0
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe
void UIEnterEventFieldDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    bool bMove = false;
    bool bInside;
    if (m_60 == 0 && m_78 != 0 && vfunc_52() != 0)
        bInside = true;
    else
        bInside = false;
    if (bInside)
    {
        int nWidth = pDialog->FUN_1422c1500();
        float fX = pDialog->FUN_1422c10a0();
        if (fX <= (float)nWidth)
        {
            int nHeight = pDialog->FUN_1422c1530();
            float fY = pDialog->FUN_1422c1110();
            if (fY <= (float)nHeight && pDialog->FUN_1422c10a0() >= 0.0f && pDialog->FUN_1422c1110() >= 0.0f)
                goto LAB_check;
        }
        bMove = true;
    }
    else
    {
        bMove = true;
    }
LAB_check:
    UIObject* pHud;
    if (bMove && (pHud = FUN_140c9b540(0x4e29)) != 0)
    {
        if (pHud->FUN_1422dc430() == 0)
        {
            m_60 = 1;
        }
        else
        {
            int nX = 0;
            MS2Ptr<AScript> spRoot = pHud->FUN_1422dba00();
            MS2Ptr<ASMovieClip> spClip(dynamic_cast<ASMovieClip*>((AScript*)spRoot));
            if (spClip.get() != 0)
            {
                double dX = 0.0;
                __int64 nY = 0;
                if (FUN_1422c2510(spClip.operator->(), &dX, &nY) != 0)
                    nX = (int)((dX - (double)(int)((float)pDialog->FUN_1422c1340() * 0.5f)) + 10.0);
            }
            int nPos;
            if (nX < 1)
                nPos = 0;
            else
                nPos = nX;
            pDialog->FUN_1422bffe0(nPos, 0);
        }
    }
}
MS2_REPLACE_METHOD(0x140F3FFB0, UIEnterEventFieldDialog, vfunc_43, 739, 0xEFA05646);

// @0x140f402a0
void UIEnterEventFieldDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (FUN_1422dc2d0() == 0)
        return;
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    if (m_tick.FUN_140268870(1000) == 0)
        return;
    UpdateVisible();
}
MS2_REPLACE_METHOD(0x140F402A0, UIEnterEventFieldDialog, vfunc_72, 108, 0xC5888A85);

// @0x140f40320
void UIEnterEventFieldDialog::SetFieldId(int nFieldId)
{
    m_nFieldId = nFieldId;
}
MS2_REPLACE_METHOD(0x140F40320, UIEnterEventFieldDialog, SetFieldId, 25, 0x11D24FAE);

// @0x140f40340
bool UIEnterEventFieldDialog::OnEnterConfirm(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::EnterEventField), 0);
        FUN_140710590(packet);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140F40340, UIEnterEventFieldDialog, OnEnterConfirm, 81, 0xA9B4A6D5);

// @0x140f403a0
void UIEnterEventFieldDialog::OnNotifyGameStart(NotifyObject* pNotify)
{
    vfunc_43();
}
MS2_REPLACE_METHOD(0x140F403A0, UIEnterEventFieldDialog, OnNotifyGameStart, 38, 0xBFA0D68B);

// @0x140f403d0
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe
void UIEnterEventFieldDialog::UpdateVisible()
{
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (!(spField == 0))
    {
        int nShow = 1;
        if (spField->HasTutorialType() != 0)
        {
            nShow = 0;
        }
        else
        {
            if (spField->m_nFieldID == m_nFieldId)
                nShow = 0;
            else if (spField->FUN_1403752c0() == 0)
                nShow = 0;
        }
        if (nShow != vfunc_9())
            vfunc_8(nShow);
    }
}
MS2_REPLACE_METHOD(0x140F403D0, UIEnterEventFieldDialog, UpdateVisible, 241, 0xF00C4EE7);
