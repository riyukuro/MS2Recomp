// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingInvitationDialog: see uiweddinginvitationdialog.h.
// MS2-UNIT: ?\uiweddinginvitationdialog.cpp
// MS2-RANGE: 0x1400e33a0-0x1400e3510 .text$di
// MS2-RANGE: 0x140fe5780-0x140fe7390 .text$mn
// MS2-PIN: ??$FUN_14028dfa0@_K_J@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEB_KAEB_J@Z 0x140fe63d0
// MS2-PIN: ??_GUIWeddingInvitationDialog@@UEAAPEAXI@Z 0x140fe6f40
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddinginvitationdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiweddinginvitationdialog.h"
#include "uimessageboxdata.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/fmt/format.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObjectContainer
{
public:
    virtual void vfunc_2(int, int, int);                        // place the movie
    int FUN_1422c13b0();                                        // width
};

// A picked guest (CPtred; the name is at +0x30).
class Unk_WiGuest : public CPtred
{
public:
    void FUN_1409003c0(COutPacket& packet);                     // write the guest into the packet
    __int64 m_18; __int64 m_20; __int64 m_28;
    CStringW m_strName;                                         // +0x30
};

// The own pending invitation: hall, time and the couple's names.
struct Unk_WiTicket
{
    unsigned char m_pad_00[0x20];
    int m_nPackageId;                                           // +0x20
    int m_nHallId;                                              // +0x24
    unsigned char m_pad_28[0x18];
    __int64 m_nTime;                                            // +0x40
    CStringW m_strGroom;                                        // +0x48
    CStringW m_strBride;                                        // +0x50
};
class Unk_WiHallTable { public: int FUN_140908d50(int nPackageId, int nHallId, bool bNight); };
class Unk_WiRefPos
{
public:
    int FUN_141b1d3d0();                                        // x
    int FUN_141b1d460();                                        // y
};
class UIWeddingGuestDialog : public UIObject
{
public:
    virtual int vfunc_48();
    void FUN_140fcdba0();                                       // forget the picked guests
};
class Unk_WiUIManager
{
public:
    void FUN_141adc750(int nId);                                // open a dialog
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
};
class Unk_WiMsgOwner { };

void* FUN_1409eed90();                                          // the singleton of the own character
Unk_WiTicket* FUN_141b87160(void* pCharacter);                  // the character's current wedding hall ticket
Unk_WiHallTable* FUN_1409023c0();
bool FUN_140900f30(__int64 nTime);                              // the time is at night
CStringW FUN_140b8e850(const CMsTime& kTime);                   // the date text
CStringTable* GetStringTable();
CStringW GetStringCommonByKey(const CStringW& strKey);                 // string table text
Unk_WiUIManager* FUN_1403ed2b0();
__int64 FUN_140900da0();                                        // the price of one invitation
Unk_WiRefPos* FUN_140a7b2b0(int nId);                           // a dialog's position record
void FUN_141b1feb0(void* p);
void* FUN_140967100();
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>, CStringW);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
__int64 FUN_140869440();                                        // the current time
void FUN_14086a880(CMsTime& kTime, int nMinutes);
__int64 FUN_140282020(const CMsTime& kTime);

CStringW FUN_14028dfa0(CStringW strKey, const fmt::ArgList& args);        // the string table formatter
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)

UIWeddingGuestDialog* FUN_140fe6700(int nId);                   // the guest dialog, if open

// @0x140fe5780
UIWeddingInvitationDialog::UIWeddingInvitationDialog()
{
    m_2c = 0x1b;
    FUN_1422dc3b0(1);
    FUN_141924170(1);
}

// @0x140fe5810
UIWeddingInvitationDialog::~UIWeddingInvitationDialog()
{
}

// @0x140fe5860
CString UIWeddingInvitationDialog::GetTypeName()
{
    return "WeddingInvitationDialog";
}

// @0x140fe58b0
int UIWeddingInvitationDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140fe58e0
void UIWeddingInvitationDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_guests.clear();
    UIWeddingGuestDialog* pGuest = FUN_140fe6700(0x4f94);
    if (pGuest != 0)
        pGuest->FUN_140fcdba0();
    FUN_141b1feb0(FUN_140967100());
}

// @0x140fe5940
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
void UIWeddingInvitationDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    Unk_WiRefPos* pRef;
    if (pDialog != 0 && (pRef = FUN_140a7b2b0(0x4e40)) != 0)
    {
        int nX = pRef->FUN_141b1d3d0();
        int nY = pRef->FUN_141b1d460() - 0x50;
        if (nX != -1 && nY != -1)
        {
            int nWidth = pDialog->FUN_1422c13b0();
            pDialog->vfunc_2(5, nY, nX - nWidth);
            return;
        }
    }
    pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(1, 0, 0);
}

// @0x140fe5a70
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
void UIWeddingInvitationDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_WiTicket* pTicket = FUN_141b87160(FUN_1409eed90());
    ASObj obj(2);
    obj.FUN_1407cbb20("invitation", GetStringCommonByKey(CStringW(L"s_wedding_invitation_message")));
    obj.FUN_1407cbb20("groom", CStringW(pTicket->m_strGroom));
    obj.FUN_1407cbb20("bride", CStringW(pTicket->m_strBride));
    obj.FUN_1407cbb20("hall", GetStringTable()->FUN_141811980(3,
        FUN_1409023c0()->FUN_140908d50(pTicket->m_nPackageId, pTicket->m_nHallId, FUN_140900f30(pTicket->m_nTime))));
    obj.FUN_1407cbb20("date", FUN_140b8e850(CMsTime(pTicket->m_nTime)));
    m_30->Invoke("setData", obj);
}

// @0x140fe5ce0
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
int UIWeddingInvitationDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onClickPopup") == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4f94);
    }
    else if (_stricmp(szMethod, "onClickSend") == 0)
    {
        if (m_guests.size() != 0)
        {
            unsigned __int64 nCount = m_guests.size();
            __int64 nTotal = FUN_140900da0();
            nTotal = nCount * nTotal;
            unsigned __int64 nCountArg = m_guests.size();
            CStringW strMessage = FUN_14028dfa0(CStringW(L"s_wedding_invitation_send"), nCountArg, nTotal);
            MS2Ptr<CMsgBoxData> box = FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &UIWeddingInvitationDialog::FUN_140fe60d0), CStringW(strMessage));
        }
        return 1;
    }
    return 0;
}

// @0x140fe5f20
void UIWeddingInvitationDialog::FUN_140fe5f20(const std::vector<GuestPtr>& guests)
{
    if (m_30 == 0)
        return;
    m_guests.clear();
    m_guests = guests;
    CStringW strNames;
    for (size_t i = 0; i < guests.size(); i++)
    {
        if (strNames.GetLength() > 0)
            strNames += L"; ";
        strNames += guests[i]->m_strName;
    }
    m_30->Invoke("setReceiver", CStringW(strNames));
}

// @0x140fe60a0
size_t UIWeddingInvitationDialog::FUN_140fe60a0()
{
    return m_guests.size();
}

// @0x140fe60d0
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
bool UIWeddingInvitationDialog::FUN_140fe60d0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        Unk_WiTicket* pTicket = FUN_141b87160(FUN_1409eed90());
        CMsTime kLimit(pTicket->m_nTime);
        FUN_14086a880(kLimit, -10);
        __int64 nNow = FUN_140869440();
        if (nNow < FUN_140282020(kLimit))
        {
            COutPacket packet(static_cast<int>(SendOp::Wedding), 0);
            packet.vfunc_o10_1(0x1c);
            packet.vfunc_o10_3((int)m_guests.size());
            for (size_t i = 0; i < m_guests.size(); i++)
                m_guests[i]->FUN_1409003c0(packet);
            FUN_140710590(packet);
        }
        else
        {
            FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_wedding_result_invitation_send_late")), 1, 1);
        }
    }
    return true;
}

// @0x140fe6700
UIWeddingGuestDialog* FUN_140fe6700(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObj = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (spObj.get() != 0)
            return dynamic_cast<UIWeddingGuestDialog*>((UIObject*)spObj);
    }
    return 0;
}

// @0x140fe7270
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caaf50-0x142caafe0 .text$yd
