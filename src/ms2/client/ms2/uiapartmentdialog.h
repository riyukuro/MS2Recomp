// uiapartmentdialog.h - UIApartmentDialog (RTTI .?AVUIApartmentDialog@@, 0x2a8 bytes, UIDialog + UIUGCEventListener at +0x178,
// UI id 0x4e74, swf "ApartmentDialog"): the apartment (home) broker. Shows the selected apartment's name, the contract button
// and the broker's lines, and starts the contract / the room move. Owning unit: ?\uiapartmentdialog.cpp. Header name assumed
// from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/ugcmapdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiugceventlistener.h"

class Unk_140acd6e0;
class UIMessageBox;

class UIApartmentDialog : public UIDialog, public UIUGCEventListener
{
public:
    UIApartmentDialog();                                        // 0x1418b57f0
    virtual ~UIApartmentDialog();                               //  0 0x1418b5930 (??_G 0x1418b7770)
    virtual CString GetTypeName();                                  //  1 0x1418b5a10 "ApartmentDialog"
    virtual void OnLoadComplete();                              // 22 0x1418b5a60
    virtual int vfunc_13();                                     // 13 0x1418b63d0
    virtual void vfunc_26();                                    // 26 0x1418b62f0
    virtual int vfunc_48() { return 0x4e74; }                   // 48 0x1418b77b0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x1418b6480
    // UIUGCEventListener (+0x178)
    virtual void vfunc_ugc_5();                                 // 5 0x1418b6510 refresh
    virtual void vfunc_ugc_6();                                 // 6 0x1418b6550

    void FUN_1418b6580();                                       // fill the movie: title, contract button, emblems
    void FUN_1418b6840(int nA, int nMapId, int nGroup);         // 0x1418b6840 select the apartment
    void FUN_1418b68c0();                                       // 0x1418b68c0 show the contract effect
    void FUN_1418b6990(int nRoom);                              // 0x1418b6990 move to the apartment
    bool FUN_1418b6ab0(int nMode);                              // 0x1418b6ab0 the contract message box state
    void FUN_1418b6bf0(const Scaleform::GFx::FunctionHandler::Params& params);   // the broker was clicked
    void FUN_1418b6cd0(const Scaleform::GFx::FunctionHandler::Params& params);   // a door was clicked
    void FUN_1418b6d10(const Scaleform::GFx::FunctionHandler::Params& params);   // the other door
    void FUN_1418b6d40(const Scaleform::GFx::FunctionHandler::Params& params);   // nothing
    void FUN_1418b6d60(const Scaleform::GFx::FunctionHandler::Params& params);   // the contract button was clicked
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);        // 0x140bb4b10 bind a button child
    CStringW FUN_1418b6de0();                                   // 0x1418b6de0 the apartment name
    void FUN_1418b6ec0(int nUiType);                            // 0x1418b6ec0 the broker's lines

private:
    MS2_LAYOUT_FRIEND;
    int m_nStyle;                                               // +0x180 0 normal, 1 merat apartment
    int m_nBrokerSaid;                                          // +0x184
    int m_nA;                                                   // +0x188
    int m_nMapId;                                               // +0x18c
    int m_nGroup;                                               // +0x190
    int m_nRoom;                                                // +0x194
    Unk_UGCGroup m_group;                                       // +0x198
    MS2Ptr<Unk_140acd6e0> m_broker;                             // +0x258 "m_broker"
    MS2Ptr<Unk_140acd6e0> m_door0;                              // +0x268
    MS2Ptr<Unk_140acd6e0> m_door1;                              // +0x278
    MS2Ptr<Unk_140acd6e0> m_door2;                              // +0x288
    MS2Ptr<Unk_140acd6e0> m_contract;                           // +0x298 "m_contractButton"
};
MS2_CHECK_SIZE(UIApartmentDialog, 0x2a8);
MS2_CHECK_OFFSET(UIApartmentDialog, m_nStyle, 0x180);
MS2_CHECK_OFFSET(UIApartmentDialog, m_group, 0x198);
MS2_CHECK_OFFSET(UIApartmentDialog, m_broker, 0x258);
MS2_CHECK_OFFSET(UIApartmentDialog, m_contract, 0x298);
