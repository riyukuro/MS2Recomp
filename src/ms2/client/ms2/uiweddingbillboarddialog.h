// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiweddingbillboarddialog.h (name
// assumed: the exe has no __FILE__ string for this unit).
//
// UIWeddingBillboardDialog ("WeddingBillboardDialog", UI type 0x4f90) is the wedding hall notice board: it asks the
// server for the booked wedding halls (packet 0xbb sub-op 4), receives the list (packet 0x12a, type 4: a count and
// per entry the wedding hall serial number + a WeddingHallTicket), sorts it by wedding time and shows 12 per page
// ("onPrev"/"onNext"/"onRefresh"); "onAttend" asks the own character to attend the picked wedding.
// RTTI .?AVUIWeddingBillboardDialog@@, 0x198 bytes = UIDialog + the page and the sorted ticket list.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; the page/list names are inferred.
#pragma once

#include <afx.h>
#include <utility>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/weddinghallticket.h"

class ASTextField;
class CInPacket;
class Unk_WbList;
class Unk_140acd6e0;

class UIWeddingBillboardDialog : public UIDialog
{
public:
    typedef std::pair<unsigned __int64, WeddingHallTicket> Entry;   // wedding hall serial number + its ticket

    UIWeddingBillboardDialog();                                         // 0x140fc2c50 (open tween 1)
    virtual ~UIWeddingBillboardDialog();                                //  0 0x140fc2cf0 (??_G 0x140fc6400)
    virtual CString vfunc_1();                                          //  1 0x140fc2d40 "WeddingBillboardDialog"
    virtual void OnLoadComplete();                                      // 22 0x140fc2e70 listen to the list packet, ask for it
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                        // 28 0x140fc2f70
    virtual void vfunc_43();                                            // 43 0x140fc3280 move the movie up
    virtual int vfunc_48() { return 0x4f90; }                           // 48 0x140fc6440 UI type id
    virtual int vfunc_65();                                             // 65 0x140fc2d90
    virtual void vfunc_67();                                            // 67 0x140fc2dc0 close: stop listening

    void FUN_140fc3300(CInPacket& packet);                              // the list packet (0x12a)
    void FUN_140fc3680();                                               // show the current page
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);          // 0x140bb4cf0 text field child lookup
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);        // 0x140bb4b10 bind a button child
    MS2Ptr<Unk_WbList> FUN_140c02900(const CString& strName);           // 0x140c02900 bind a list child

private:
    MS2_LAYOUT_FRIEND;
    int m_nPage;                                                        // +0x178 current page (12 tickets each)
    std::vector<Entry> m_tickets;                                       // +0x180 sorted by wedding time
};
MS2_CHECK_SIZE(UIWeddingBillboardDialog, 0x198);
MS2_CHECK_OFFSET(UIWeddingBillboardDialog, m_tickets, 0x180);

// Sort order of the notice board (0x140fc3500).
bool FUN_140fc3500(const UIWeddingBillboardDialog::Entry& a, const UIWeddingBillboardDialog::Entry& b);
