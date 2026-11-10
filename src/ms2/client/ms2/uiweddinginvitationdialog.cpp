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
#include "ms2/client/ms2/uitalkcinematic.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/placeholder/weddingguest.h"
#include "ms2/commonfiles/os.h"

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObjectContainer
{
public:
    virtual void vfunc_2(int, int, int);                        // place the movie
};

// A picked guest (CPtred; the name is at +0x30).
class Unk_WiGuest : public CPtred
{
public:
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
class UIWeddingGuestDialog : public UIObject
{
public:
    virtual int vfunc_48();
    void ClearGuests();                                       // forget the picked guests
};
class Unk_WiUIManager
{
public:
};
class Unk_WiMsgOwner { };

class WeddingManager;
class WeddingManager   // C3: member view for the former free stand-ins
{
public:
    class WeddingHallTicket const& GetTicket();
};
bool IsNightTime(__int64 nTime);                              // the time is at night
CStringW FormatYearMonthDayHour(const CMsTime& kTime);                   // the date text
CStringW GetStringCommonByKey(const CStringW& strKey);                 // string table text
__int64 GetWeddingInvitationMeso();                                        // the price of one invitation
UITalkCinematic* FindTalkCinematic(int nId);                           // a dialog's position record
class UITalkManager   // C3: member view for the former free stand-ins
{
public:
    void SendNpcTalkMode0();
};
void* GetUITalkManager();
MS2Ptr<CMsgBoxData> ShowYesNoMessageBox(Delegate<bool(int, const CMsgBoxData&)>, CStringW);
void ShowSystemNotice(const CStringW& text, int nA, int nB);
__int64 GetServerTime();                                        // the current time
void AddMinutes(CMsTime& kTime, int nMinutes);

CStringW FUN_14028dfa0(const CStringW& strKey, const fmt::ArgList& args);        // the string table formatter
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)

UIWeddingGuestDialog* FUN_140fe6700(int nId);                   // the guest dialog, if open

// @0x140fe5780
UIWeddingInvitationDialog::UIWeddingInvitationDialog()
{
    m_2c = 0x1b;
    FUN_1422dc3b0(1);
    SetTweenEnabled(1);
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
        pGuest->ClearGuests();
    ((class UITalkManager*)(void*)(GetUITalkManager()))->SendNpcTalkMode0();
}

// @0x140fe5940
void UIWeddingInvitationDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        UITalkCinematic* pRef = FindTalkCinematic(0x4e40);
        if (pRef != 0)
        {
            int nX = pRef->GetLowerCutGlobalY();
            int nY = pRef->GetIllustGlobalX() - 0x50;
            if (nX != -1 && nY != -1)
            {
                pDialog->vfunc_2(5, nY, nX - pDialog->GetHeightCeil());
                return;
            }
        }
    }
    ASDialog* pDefault = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDefault != 0)
        pDefault->vfunc_2(1, 0, 0);
}

// @0x140fe5a70
void UIWeddingInvitationDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_WiTicket* pTicket = ((struct Unk_WiTicket*)&TSingleton<WeddingManager>::GetInstance()->GetTicket());
    ASObj obj(2);
    obj.SetWStringMember("invitation", GetStringCommonByKey(L"s_wedding_invitation_message"));
    obj.SetWStringMember("groom", CStringW(pTicket->m_strGroom));
    obj.SetWStringMember("bride", CStringW(pTicket->m_strBride));
    obj.SetWStringMember("hall", TSingleton<CStringTable>::GetInstance()->FUN_141811980(3,
        TSingleton<WeddingTable>::GetInstance()->GetHallFieldId(pTicket->m_nPackageId, pTicket->m_nHallId, IsNightTime(pTicket->m_nTime))));
    obj.SetWStringMember("date", FormatYearMonthDayHour(CMsTime(pTicket->m_nTime)));
    m_30->Invoke("setData", obj);
}

// @0x140fe5ce0
int UIWeddingInvitationDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onClickPopup") == 0)
    {
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4f94)));
    }
    else if (_stricmp(szMethod, "onClickSend") == 0)
    {
        if (m_guests.size() != 0)
        {
            unsigned __int64 nCount = m_guests.size();
            __int64 nTotal = nCount * GetWeddingInvitationMeso();
            unsigned __int64 nCountArg = m_guests.size();
            CStringW strMessage = FUN_14028dfa0(CStringW(L"s_wedding_invitation_send"), nCountArg, nTotal);
            MS2Ptr<CMsgBoxData> box = ShowYesNoMessageBox(Delegate<bool(int, const CMsgBoxData&)>(this, &UIWeddingInvitationDialog::SendInvitation), CStringW(strMessage));
        }
        return 1;
    }
    return 0;
}

// @0x140fe5f20
void UIWeddingInvitationDialog::SetGuests(const std::vector<GuestPtr>& guests)
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
size_t UIWeddingInvitationDialog::GetGuestCount()
{
    return m_guests.size();
}

// @0x140fe60d0
bool UIWeddingInvitationDialog::SendInvitation(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    Unk_WiTicket* pTicket = ((struct Unk_WiTicket*)&TSingleton<WeddingManager>::GetInstance()->GetTicket());
    CMsTime kLimit(pTicket->m_nTime);
    AddMinutes(kLimit, -10);
    if (GetServerTime() >= ((class CMsTime*)&static_cast<class CMsTime const&>(kLimit))->Get())
    {
        ShowSystemNotice(GetStringCommonByKey(L"s_wedding_result_invitation_send_late"), 1, 1);
        return true;
    }
    COutPacket packet(static_cast<int>(SendOp::Wedding), 0);
    packet.WriteUInt8(0x1c);
    packet.WriteInt32((int)m_guests.size());
    for (size_t i = 0; i < m_guests.size(); i++)
        reinterpret_cast<WeddingGuest*>(m_guests[i].operator->())->Write(packet);
    FUN_140710590(packet);
    return true;
}

// @0x140fe6700
UIWeddingGuestDialog* FUN_140fe6700(int nId)
{
    if (reinterpret_cast<Unk_WiUIManager*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spObj = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (spObj.get() != 0)
            return dynamic_cast<UIWeddingGuestDialog*>((UIObject*)spObj);
    }
    return 0;
}

// @0x140fe7270
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caaf50-0x142caafe0 .text$yd
