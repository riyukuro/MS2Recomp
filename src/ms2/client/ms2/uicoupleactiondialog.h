// uicoupleactiondialog.h - UICoupleActionDialog (RTTI .?AVUICoupleActionDialog@@, 0x1b0 bytes, UI id 0x4f4e, swf
// "CoupleAction"): the emotion ("couple action") picker. It lists the emotions the local player has learned (the
// skill system's list), filtered by a search text and an "only favorites" switch, sorted by id or reversed, in 30
// slot pages, and sends the favorite flag to the server. NOT an original header (the unit is
// client\ms2\uicoupleactiondialog.cpp; header name assumed). Member names are invented from use.
// Vftables 0x142... (84 slots) and the IMessageListener table at +0x18.
#pragma once
#include <afx.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/client/ms2/uidialog.h"

class ASData;
class NotifyObject;
class Unk_CoupleInput;
class Unk_CoupleList;


// CSkillSystem::stEmotion (RTTI): one learned emotion of the player, 0x40 bytes (std::pair<const int, stEmotion> is
// 0x48: the sized delete of the tree node). The nested name is not used here: the skill system class lives in
// ?\skillslot.cpp / mypc.h without it.
class Unk_Emotion : public CPtred
{
public:
    int m_isNew;                                            // +0x18 "isNew"
    int m_id;                                               // +0x1c the emotion (item) id
    unsigned short m_level;                                 // +0x20
    __int64 m_28;                                           // +0x28 expiry time of a timed action (0 = none)
    void* m_pad_30;
    unsigned char m_pad_38;
    unsigned char m_favorite;                               // +0x39 "isFavorite"
};
MS2_CHECK_SIZE(Unk_Emotion, 0x40);

class UICoupleActionDialog : public UIDialog
{
public:
    UICoupleActionDialog();                                 // 0x140bebfb0
    // virtual dtor 0x140bf1790: implicit (the exe stores no vptr; pinned)
    virtual CString GetTypeName();                              //  1 0x140bec070 "CoupleAction"
    virtual int vfunc_13();                                 // 13 0x140bec570 enter key: take the search text
    virtual void OnLoadInit();                              // 20 0x140bec200 refresh, listen to NotifyLearnEmotion
    virtual void OnLoadComplete();                          // 22 0x140bec2f0 bind the search input
    virtual void vfunc_26();                                // 26 0x140bec470 unbind
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140bec930
    virtual int vfunc_48() { return 0x4f4e; }               // 48 (COMDAT)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140bec760 getTooltip
    virtual int vfunc_65();                                 // 65 0x140bec0c0 open: reset
    virtual void vfunc_67();                                // 67 0x140bec140 close
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140bec1a0

    void FUN_140becea0(NotifyObject* pNotify);              // NotifyLearnEmotion: refresh
    void FUN_140beced0(const Scaleform::GFx::FunctionHandler::Params& params);   // empty (the search input callback)
    void FUN_140becef0();                                   // rebuild the emotions of the player and the pages
    void FUN_140bed170(int nEmotion);                       // "setFocusByEmotion"
    int FUN_140bed1f0(int nEmotion);                        // select an emotion for the player
    void FUN_140bed2a0(unsigned __int64 nSelection);        // m_178 = nSelection
    void FUN_140bed2d0();                                   // "buildActions" in id order
    void FUN_140bed8a0();                                   // "buildActions" in reverse id order
    MS2Ptr<Unk_CoupleList> FUN_140ba4b70(const CString& strName);   // list child lookup (UIDialog member, shared COMDAT)
    void FUN_140bede70(CStringW strSearch);                 // set the search text; refresh when it changed
    CStringW FUN_140bedf00(unsigned int nEmotion);          // the search keywords of an emotion, space separated
    void FUN_140bee040(ASArray& arr);                       // pad the page list with empty slots
    void FUN_140bee150(int nKey);                           // keys: move the selection in "m_list"
    int FUN_140bee590(int nKey);                           // the key has no emotion shortcut
    int FUN_140bee5e0(int nKey, unsigned __int64 nEmotion);    // set a shortcut
    unsigned __int64 FUN_1417f5f70() { return m_178; }     // the selected character (COMDAT, stateskill)

private:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_178;                                 // +0x178 the selected character (account of the partner)
    std::map<unsigned int, MS2Ptr<Unk_Emotion> > m_180;              // +0x180 the learned emotions by id
    MS2Ptr<Unk_CoupleInput> m_190;                          // +0x190 "m_inputSearch"
    bool m_1a0;                                             // +0x1a0 reverse order
    bool m_1a1;                                             // +0x1a1 favorites only
    CStringW m_1a8;                                         // +0x1a8 the search text
};
MS2_CHECK_SIZE(UICoupleActionDialog, 0x1b0);
MS2_CHECK_OFFSET(UICoupleActionDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UICoupleActionDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UICoupleActionDialog, m_190, 0x190);
MS2_CHECK_OFFSET(UICoupleActionDialog, m_1a0, 0x1a0);
MS2_CHECK_OFFSET(UICoupleActionDialog, m_1a8, 0x1a8);
