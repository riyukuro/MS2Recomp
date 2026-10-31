// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingHallListDialog: see uiweddinghalllistdialog.h.
// MS2-UNIT: ?\uiweddinghalllistdialog.cpp
// MS2-RANGE: 0x140fd8df0-0x140fdab30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KVWeddingHallTicket@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KVWeddingHallTicket@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CB_KVWeddingHallTicket@@@std@@PEAX@std@@@2@XZ 0x140fda440 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KVWeddingHallTicket@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KVWeddingHallTicket@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KVWeddingHallTicket@@@std@@@std@@@2@XZ 0x140fda460 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GUIWeddingHallListDialog@@UEAAPEAXI@Z 0x140fd9c50
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddinghalllistdialog.cpp"    // assumed

// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"

#include "uiweddinghalllistdialog.h"

#include <stdlib.h>
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/weddingmanager.h"
#include "ms2/placeholder/weddingtable.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The hall tables: package -> hall -> string id of the hall name (day / night).
class Unk_WhHall : public CPtred { public: int FUN_140906e40(bool bNight); };
class Unk_WhPackage : public CPtred { public: MS2Ptr<Unk_WhHall> FUN_140907110(int nHallId); };
class Unk_WhTable { public: MS2Ptr<Unk_WhPackage> FUN_140908b80(int nPackageId); };

// The own character: its wedding hall tickets and the "enter the wedding" request.

unsigned __int64 FUN_140718370(const CStringW& str);                // string to unsigned __int64
__int64 GetServerTime();                                            // the current time
bool FUN_140900f30(__int64 nTime);                                  // the time is at night
CStringW FUN_141b71910(unsigned __int64 n);                         // the number as text
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);      // localized, formatted
CStringTable* GetStringTable();

// @0x140fd8df0
UIWeddingHallListDialog::UIWeddingHallListDialog()
{
    m_bRefresh = 0;
    m_2c = 0xc;
    FUN_1422dc3b0(1);
    FUN_141924170(1);
}

// @0x140fd8e80
UIWeddingHallListDialog::~UIWeddingHallListDialog()
{
}

// @0x140fd8ec0
CString UIWeddingHallListDialog::GetTypeName()
{
    return "WeddingHallListDialog";
}
MS2_REPLACE_METHOD(0x140FD8EC0, UIWeddingHallListDialog, GetTypeName, 61, 0x36C88FDF);

// @0x140fd8f10
int UIWeddingHallListDialog::vfunc_65()
{
    return UIDialog::vfunc_65();
}
MS2_REPLACE_METHOD(0x140FD8F10, UIWeddingHallListDialog, vfunc_65, 24, 0x19660E05);

// @0x140fd8f30
void UIWeddingHallListDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140FD8F30, UIWeddingHallListDialog, vfunc_67, 24, 0x6F5A03D1);

// @0x140fd8f50
void UIWeddingHallListDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_bRefresh == 1) {
        m_bRefresh = 0;
        FUN_140fd9110();
    }
}
MS2_REPLACE_METHOD(0x140FD8F50, UIWeddingHallListDialog, vfunc_72, 63, 0xB770684D);

// @0x140fd8fa0
void UIWeddingHallListDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140fd9110();
}
MS2_REPLACE_METHOD(0x140FD8FA0, UIWeddingHallListDialog, OnLoadComplete, 34, 0x97E35379);

// @0x140fd8fd0
int UIWeddingHallListDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onEnter") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            unsigned __int64 nWeddingSn = FUN_140718370(data.FUN_1422b8f40());
            TSingleton<WeddingManager>::GetInstance()->SendInvitation(nWeddingSn);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140FD8FD0, UIWeddingHallListDialog, vfunc_28, 274, 0x104ECF56);

// @0x140fd90f0
void UIWeddingHallListDialog::FUN_140fd90f0(bool b)
{
    m_bRefresh = 1;
}
MS2_REPLACE_METHOD(0x140FD90F0, UIWeddingHallListDialog, FUN_140fd90f0, 22, 0x418ED914);

// @0x140fd9110
void UIWeddingHallListDialog::FUN_140fd9110()
{
    std::map<unsigned __int64, WeddingHallTicket> halls;
    TSingleton<WeddingManager>::GetInstance()->CollectTickets(halls);
    MS2Ptr<ASScrollingList> pOpenList = FUN_140c02900("m_openList");
    MS2Ptr<ASScrollingList> pProgressList = FUN_140c02900("m_progressList");
    if (pOpenList.IsNull() || pProgressList.IsNull()) {
        vfunc_67();
        return;
    }
    pOpenList->FUN_1422dd1d0();
    pProgressList->FUN_1422dd1d0();
    std::map<unsigned __int64, WeddingHallTicket>::iterator it = halls.begin();
    std::map<unsigned __int64, WeddingHallTicket>::iterator itEnd = halls.end();
    __int64 nNow = GetServerTime();
    for (; it != itEnd; ++it) {
        WeddingHallTicket& ticket = it->second;
        MS2Ptr<Unk_WhPackage> pPackage = reinterpret_cast<Unk_WhTable*>(TSingleton<WeddingTable>::GetInstance())->FUN_140908b80(ticket.m_nPackageId);
        if (pPackage == 0)
            continue;
        MS2Ptr<Unk_WhHall> pHall = pPackage->FUN_140907110(ticket.m_nHallId);
        if (pHall == 0)
            continue;
        CStringW strName = FUN_1408f71a0(CStringW(L"s_wedding_hall_list_name"), ticket.m_strGroom, ticket.m_strBride);
        ASObj row(2);
        row.FUN_1407cbb20("name", strName);
        row.FUN_1407cbb20("hall", GetStringTable()->FUN_141811980(3, pHall->FUN_140906e40(FUN_140900f30(ticket.m_nTime))));
        row.FUN_1407cbb20("weddingSN", FUN_141b71910(it->first));
        if (ticket.m_nTime > nNow)
            pOpenList->FUN_1422dd230(row);
        else
            pProgressList->FUN_1422dd230(row);
    }
    pOpenList->vfunc_24(true);
    pProgressList->vfunc_24(true);
}
MS2_REPLACE_METHOD(0x140FD9110, UIWeddingHallListDialog, FUN_140fd9110, 1258, 0x20B250A4);

// @0x140fd9c90
// (vfunc_48 is inline in the header)
