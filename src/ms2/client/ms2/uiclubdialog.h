// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiclubdialog.h (name assumed: the
// .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIClubDialog is the club window (UI type 0x4f25, "ClubDialog"): a category list (the clubs the player joined), the
// member list of the selected club, and the buff / withdrawal / rename / add-member message boxes. RTTI
// .?AVUIClubDialog@@, 0x188 bytes, vftables 0x142e415a0 (84 slots) and the IMessageListener one at +0x18.
// Member and method names are invented where the exe has no name (vfunc_N / FUN_<va> otherwise).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"

class ASObj;
class CClubMember;
class CMsgBoxData;
class Unk_ClubClip;
class Unk_ClubList;

class UIClubDialog : public UIDialog
{
public:
    UIClubDialog();                                                 // 0x140e0aa10
    virtual ~UIClubDialog();                                        //  0 0x140e0aa80 (??_G 0x140e0d8c0)

    virtual CString GetTypeName();                                      //  1 "ClubDialog"
    virtual void OnLoadComplete();                                  // 22 hides the web guide button, fills the lists
    virtual void vfunc_26();                                        // 26
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 swf callbacks
    virtual int vfunc_48() { return 0x4f25; }                       // 48 UI type id (COMDAT 0x140e0d910)
    virtual int vfunc_65();                                         // 65
    virtual void vfunc_67();                                        // 67
    virtual int vfunc_73();                                         // 73 can open: the club feature flag 0x31

    void FUN_140e0bc30();                                           // refresh the lists, or clear them when no club is joined
    bool FUN_140e0bcd0(int nResult, const CMsgBoxData& data);       // "add member" input box result
    bool FUN_140e0bdb0(int nResult, const CMsgBoxData& data);       // withdrawal confirm result
    bool FUN_140e0be00(int nResult, const CMsgBoxData& data);       // buff setting confirm result
    bool FUN_140e0bef0(int nResult, const CMsgBoxData& data);       // rename input box result
    void FUN_140e0bfd0();                                           // fill the category list (m_category)
    void FUN_140e0c570(__int64 nClubId);                            // fill the member list (m_items) of one club
    void FUN_140e0ca20(ASObj& row, MS2Ptr<CClubMember> spMember);   // one member row (name, job/level, location, picture)
    void FUN_140e0d180(ASObj& row, int nBuffId, unsigned short nLevel);   // "buffIcon" of a club row
    void FUN_140e0d230(ASObj& row, __int64 nNameChangeTime);        // "nameChange" flag of a club row

    // Unrecovered child-binding helpers of the swf entity base (this is the original UISwfEntity subobject).
    MS2Ptr<Unk_ClubClip> FUN_140ba7930(const CString& strName);     // bind a movie clip child
    MS2Ptr<Unk_ClubList> FUN_140c02900(const CString& strName);     // bind a list child
    __int64 FUN_141904a70() { return m_nClubId; }                   // 0x141904a70 (inline, uicommon.cpp)

private:
    MS2_LAYOUT_FRIEND;
    __int64 m_nClubId;                                              // +0x178 selected club serial number
    int m_nCategory;                                                // +0x180 selected category index
};
MS2_CHECK_SIZE(UIClubDialog, 0x188);
MS2_CHECK_OFFSET(UIClubDialog, m_nClubId, 0x178);
MS2_CHECK_OFFSET(UIClubDialog, m_nCategory, 0x180);
