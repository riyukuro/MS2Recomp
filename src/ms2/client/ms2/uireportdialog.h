// uireportdialog.h - UIReportDialog (RTTI .?AVUIReportDialog@@, 0x210 bytes, UI type 0x4e86 "ReportDialog"): the swf form
// in which the player reports another player, a chat line, a wall poster, a design item, a real-estate page or a pet.
// The caller fills the target through one of the FUN_ setup members (one per report kind), the swf calls "onReport" with
// the category check boxes and a text, and the dialog sends packet 0x52 and updates the block lists. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\uireportdialog.cpp` (0x141ab8920-0x141aba6a0 .text$mn,
// dir client\ms2). Header name and member names assumed.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h) with IMessageListener at +0x18. Overridden slots: 0 (dtor), 1 (class
// name), 13, 20 (OnLoadInit), 22 (OnLoadComplete), 28 (swf callbacks), 48 (UI type), 67 (close); IMessageListener 0.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"

class UIReportDialog : public UIDialog
{
public:
    UIReportDialog();                                                // 0x141ab8920
    virtual ~UIReportDialog();                                       //  0 0x141ab8a70 (??_G 0x141aba530)
    virtual CString GetTypeName();                                       //  1 0x141ab8b40: "ReportDialog"
    virtual int vfunc_13();                                          // 13 0x141ab8e90
    virtual void OnLoadInit();                                       // 20 0x141ab8b90 tell the swf the report kind
    virtual void OnLoadComplete();                                   // 22 0x141ab8e50
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                     // 28 0x141ab9350 "onReport" / "OnCancel"
    virtual int vfunc_48() { return 0x4e86; }                        // 48 (COMDAT 0x141aba570)
    virtual void vfunc_67();                                         // 67 0x141ab8e70
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);        // IMessageListener 0 0x141ab8ec0 the confirm box

    void FUN_141ab9890();                                            // 0x141ab9890 forget the target
    void FUN_141ab9a10(__int64 nPosterId, int nBannerId, const CString& strUrl, const CStringW& strTarget);   // 0x141ab9a10 wall poster
    void FUN_141ab9aa0(__int64 nCharacterId, const CStringW& strTarget);                                       // 0x141ab9aa0 character
    void FUN_141ab9b10(const CStringW& strTarget, const CStringW& strChat);                                    // 0x141ab9b10 chat line
    void FUN_141ab9b80(const Unk_MeratProductKey& key, __int64 nItemId, CStringW strItem, CStringW strTarget, int nFlag);
                                                                     // 0x141ab9b80 design item
    void FUN_141ab9c50(__int64 nPageId, const CStringW& strTarget, int nArg1, int nArg2);                      // 0x141ab9c50 real estate
    void FUN_141ab9ce0(CStringW strTarget, CStringW strPet);         // 0x141ab9ce0 pet
    bool FUN_141ab9d70(CString strMethod, unsigned int nFlags, CStringW strText);   // 0x141ab9d70 send packet 0x52
    void FUN_141aba110(CString strMethod, unsigned int nFlags);      // 0x141aba110 block the reported target
    bool FUN_141aba4b0(const CString& strMethod);                    // 0x141aba4b0 target name length is valid

private:
    MS2_LAYOUT_FRIEND;
    __int64 m_178;                  // +0x178 server time when the swf was initialised
    __int64 m_nPosterId;            // +0x180 wall poster id
    CString m_strPosterUrl;         // +0x188
    int m_nBannerId;                // +0x190
    Unk_MeratProductKey m_key;      // +0x198 design item key
    __int64 m_nItemId;              // +0x1a8 design item id
    CStringW m_strItem;             // +0x1b0 design item name
    int m_nItemFlag;                // +0x1b8
    CStringW m_strChat;             // +0x1c0 reported chat line
    __int64 m_nPageId;              // +0x1c8 real estate page id
    int m_nPageArg1;                // +0x1d0
    int m_nPageArg2;                // +0x1d4
    CStringW m_strPet;              // +0x1d8 reported pet
    CStringW m_strTarget;           // +0x1e0 name of the reported player
    __int64 m_nCharacterId;         // +0x1e8
    int m_nKind;                    // +0x1f0 1 character, 2 chat, 3 poster, 4 design item, 5 real estate, 6 pet
    CString m_strMethod;            // +0x1f8 swf callback that picked the target ("OnSelectCharacter"...)
    CStringW m_strText;             // +0x200 report text
    unsigned int m_nFlags;          // +0x208 category bits
};
MS2_CHECK_SIZE(UIReportDialog, 0x210);
MS2_CHECK_OFFSET(UIReportDialog, m_key, 0x198);
MS2_CHECK_OFFSET(UIReportDialog, m_strTarget, 0x1e0);
MS2_CHECK_OFFSET(UIReportDialog, m_strMethod, 0x1f8);
MS2_CHECK_OFFSET(UIReportDialog, m_nFlags, 0x208);
