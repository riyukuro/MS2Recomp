// uiugccubebilldialog.h - UIUGCCubeBillDialog (RTTI .?AVUIUGCCubeBillDialog@@, 0x178 bytes: a bare UIDialog, UI type
// 0x4f29, swf "UGCCubeBillDialog"), the bill the player confirms before buying an UGC cube / a blueprint ("OnBuy"):
// the cost (pay type -> amount) the server sent is kept in unit statics (Cost / PendingCost, RTTI nested names) and
// shown through "setData" (meso / bluemerat / redmerat and the merat list). Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the class names are from RTTI, the header name is assumed.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h) with the IMessageListener at +0x18. Overridden slots: 0, 1 (class
// name), 22 (OnLoadComplete: push the bill), 28 ("OnBuy"), 48 (UI type 0x4f29), 67 (clear the cost on close).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/client/ms2/tmarketbilldataparam.h"      // ePayType
class CMsgBoxData;

class ASTextField;
class Unk_UcbButton;

class UIUGCCubeBillDialog : public UIDialog
{
public:
    // What the server asked the player to pay for (kind 1: a cube, 3: a blueprint) and for which id.
    class PendingCost
    {
    public:
        PendingCost();                                  // 0x140ee8900
        virtual ~PendingCost();                         //  0 0x140ee89f0 (??_G 0x140ee8ae0)
        virtual void Reset();                           //  1 0x140ee9890
        virtual void Assign(const PendingCost& o);      //  2 0x140ee8ba0 (copies the three fields)

        int m_nKind;                                    // +0x08 1 cube, 3 blueprint
        __int64 m_nBlueprintUid;                        // +0x10 the blueprint item (kind 3)
        int m_nCubeId;                                  // +0x18 the cube (kind 1)
    };

    // The confirmed bill: the pending cost plus the amounts per pay type.
    class Cost : public PendingCost
    {
    public:
        Cost();                                         // 0x140ee88a0
        // The destructor (0x140ee89c0) and deleting destructor (0x140ee8aa0) are implicit.
        virtual void Reset();                           //  1 0x140ee9850

        bool m_bPreview;                                // +0x20 the bill is a blueprint cost preview (no buy)
        int m_nArg;                                     // +0x24 the argument of the description text
        ATL::CRBMap<ePayType, __int64> m_map;           // +0x28 pay type -> amount
    };

    UIUGCCubeBillDialog();                              // 0x140ee7610
    virtual ~UIUGCCubeBillDialog();                     //  0 0x140ee76a0 (??_G 0x140ee8b20)
    virtual CString vfunc_1();                          //  1 0x140ee76e0 "UGCCubeBillDialog"
    virtual void OnLoadComplete();                      // 22 0x140ee7760
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ee7f40 "OnBuy"
    virtual int vfunc_48();                             // 48 0x140ee8e20 UI type id
    virtual void vfunc_67();                            // 67 0x140ee7730 forget the cost

    bool FUN_140ee8000(int nButton, const CMsgBoxData& box);   // 0x140ee8000 the blueprint open box result (unit_140d1ae30)
    void SendRequestCube();                               // 0x140ee80a0 buy: ask the server for the bill / the purchase
    MS2Ptr<Unk_UcbButton> FUN_140bb4b10(const CString& strName);        // 0x140bb4b10 bind a button child (a UIDialog member)
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);          // 0x140bb4cf0 text field child lookup (a UIDialog member)

    static PendingCost s_pending;                       // DAT_143ac8f00
    static Cost s_cost;                                 // DAT_143ac8f20
};
MS2_CHECK_SIZE(UIUGCCubeBillDialog, 0x178);
MS2_CHECK_SIZE(UIUGCCubeBillDialog::PendingCost, 0x20);
MS2_CHECK_SIZE(UIUGCCubeBillDialog::Cost, 0x58);
MS2_CHECK_OFFSET(UIUGCCubeBillDialog::Cost, m_bPreview, 0x20);
MS2_CHECK_OFFSET(UIUGCCubeBillDialog::Cost, m_map, 0x28);
