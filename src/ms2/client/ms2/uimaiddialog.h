// uimaiddialog.h - UIMaidDialog (RTTI .?AVUIMaidDialog@@, 0x1f8 bytes: UIDialog + the shown maid and the edit buffer), the
// maid information window ("MaidDialog", UI type 0x4e9d): the maid's portrait, affinity and mood, the profile texts and the
// editable profile (sent to the server with opcode 0x62 mode 4). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13);
// the unit is `?\uimaiddialog.cpp` (dir client\ms2). Header/unit name assumed. Member names are invented from use.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h) with the IMessageListener at +0x18. Overridden slots: 1 (movie name),
// 13 (Tab key), 20 (OnLoadInit), 22 (OnLoadComplete: fill the movie), 28 (AS -> C++ commands), 43 (place the window next to
// the home panel), 48 (UI type 0x4e9d), 65 (open), 67 (close), 79 (packet), IMessageListener 0 (the message box answer).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/maid.h"


class UIMaidDialog : public UIDialog
{
public:
    UIMaidDialog();                                                         // 0x1412d7040
    virtual ~UIMaidDialog();                                                //  0 0x1412d7100 (??_G 0x1412da8d0)
    virtual CString GetTypeName();                                              //  1 0x1412d7170 "MaidDialog"
    virtual int vfunc_13();                                                 // 13 0x1412d7250 Tab key -> "onTabKey"
    virtual void OnLoadInit();                                              // 20 0x1412d74e0
    virtual void OnLoadComplete();                                          // 22 0x1412d7450
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1412d7520
    virtual void vfunc_43();                                                // 43 0x1412d7310
    virtual int vfunc_48();                                                 // 48 0x1412da910: 0x4e9d
    virtual int vfunc_65();                                                 // 65 0x1412d71c0
    virtual void vfunc_67();                                                // 67 0x1412d71f0
    virtual void vfunc_79(void* p);                                         // 79 0x1412d7480
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);               // IMessageListener 0 0x1412d8c40

    void FUN_1412d7aa0();                                                   // 0x1412d7aa0 "setData": the whole movie
    int FUN_1412d8e10(int nField, CStringW strValue, MaidProfile* pProfile);   // 0x1412d8e10 check one edited text
    void FUN_1412d9640(int nMaidId, unsigned __int64 nMaidUid);             // 0x1412d9640 show another maid
    void FUN_1412d9680();                                                   // 0x1412d9680 "updateStatus"
    void FUN_1412d9b90();                                                   // 0x1412d9b90 "updateProperty"
    CStringW FUN_1412da590();                                               // 0x1412da590 the contract end date text

private:
    MS2_LAYOUT_FRIEND;
    int m_nMaidId;                                                          // +0x178 the maid npc's object id
    unsigned __int64 m_nMaidUid;                                            // +0x180 the maid's key (CMaid::m_nId)
    CStringW m_strSpecialTitle;                                             // +0x188 the "special title" text of the maid
    MaidProfile m_profile;                                              // +0x190 the edited profile
};
MS2_CHECK_SIZE(UIMaidDialog, 0x1f8);
MS2_CHECK_OFFSET(UIMaidDialog, m_nMaidId, 0x178);
MS2_CHECK_OFFSET(UIMaidDialog, m_nMaidUid, 0x180);
MS2_CHECK_OFFSET(UIMaidDialog, m_strSpecialTitle, 0x188);
MS2_CHECK_OFFSET(UIMaidDialog, m_profile, 0x190);
