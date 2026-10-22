// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMentoringManager: the client side of the mentoring system.
// It keeps the waiting mentors and the accepted mentees and handles the server's mentoring packet (the protocol byte
// selects one of 15 handlers; the payloads are the Unk_Mentor*Packet structs of commonfiles\mentor.cpp). See
// mentoringmanager.h.
// MS2-UNIT: ?\mentoringmanager.cpp
// MS2-RANGE: 0x1400c87f0-0x1400c8960 .text$di
// MS2-RANGE: 0x140b71440-0x140b73c50 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\mentoringmanager.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "mentoringmanager.h"

#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uiinvitementoringdialog.h"
#include "ms2/client/ms2/uicharacterlistdialog.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "hook/ms2hook.h"

// the header statics emitted into this TU (.text$di): sort-type names, "skill", "stun", condition object
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------
// The local player / any player (PC): the mentoring state and a few status queries.
class Unk_MMPlayer
{
public:
    void FUN_14165ffc0(int nState);                         // set the mentoring state
    unsigned FUN_14165ffe0();                               // get the mentoring state
    int FUN_1416595d0();
    int FUN_141675ed0();
    int FUN_14166c930();
};
class Unk_MMWorld
{
public:
    Unk_MMPlayer* FUN_141bd0cc0();                          // the local player
    Unk_MMPlayer* FUN_141bd1290(int nId);                   // a player by id
};
Unk_MMWorld* FUN_1403ed2d0();
class Unk_MMScene { public: int FUN_1422b9e00(); };
Unk_MMScene* FUN_1408e57f0();

class Unk_MMUIService
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
    int FUN_141adc890(int nId);                             // the dialog is open
    void FUN_141adc5d0(int nId);                            // close the dialog
};
Unk_MMUIService* FUN_1403ed2b0();

class MyPC;
CStringW GetStringCommonByKey(const CStringW& str);                // the text of a string id
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArgument);
void FUN_1412751b0(const CStringW& strText, int nType);     // a notice
void FUN_1412751f0(const CStringW& strText, int nA, int nB);    // a notice (error)

// The mentoring dialog (RTTI .?AVUIMentoringDialog@@, class id 0x4f4b; the full class is in uimentoringrewardpage.h).
class UIMentoringDialog : public UIDialog
{
public:
    virtual ~UIMentoringDialog();
    void Refresh();                                         // 0x140e5e8e0
    void RefreshPage();                                     // 0x140e5ea50
};
UIInviteMentoringDialog* FUN_140b6f4c0(int nId);            // unit ?\menteesearch.cpp: the invite dialog by id

// ---- inline helpers of the unit's headers ---------------------------------------------------------------------------
// Moves the read position of the packet back by one byte (the protocol byte is read again by the payload reader).
inline void FUN_140b736c0(CInPacket& packet, int nDelta)
{
    packet.FUN_140715280(packet.m_offset + nDelta);
}

// The dialogs by class id, dynamic-cast to their type.
template <class T> T* Unk_MMDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// ---- payloads: the structs of commonfiles\mentor.h with the constructors of this unit ---------------------------------
typedef Unk_MentorPtr<CMentor> MentorPtr;
typedef ATL::CAtlArray<MentorPtr> MentorArray;

struct Unk_MMResultPacket1                                  // protocol 1 (0x140b73150)
{
    unsigned char protocol, result;
    int value;
    Unk_MMResultPacket1() : protocol(1), result(0), value(0) {}
    void FUN_14069a420(Unk_MentorReader& stream);
};
struct Unk_MMListPacket2                                    // protocol 2 (0x140b730b0)
{
    unsigned char protocol;
    MentorArray entries;
    Unk_MMListPacket2() : protocol(2) {}
    void FUN_14069a0b0(Unk_MentorReader& stream);
};
struct Unk_MMListPacket3                                    // protocol 3 (0x140b73050)
{
    unsigned char protocol;
    MentorArray entries;
    Unk_MMListPacket3() : protocol(3) {}
    void FUN_14069a290(Unk_MentorReader& stream);
};
struct Unk_MMNamePacket5                                    // protocol 5 (0x140b73110)
{
    unsigned char protocol;
    __int64 id;
    CStringW name;
    Unk_MMNamePacket5() : protocol(5), id(0) {}
    void FUN_14069a5a0(Unk_MentorReader& stream);
};
struct Unk_MMIdPacket6                                      // protocol 6 (0x140b73010)
{
    unsigned char protocol;
    __int64 id;
    Unk_MMIdPacket6() : protocol(6), id(0) {}
    void FUN_14069a670(Unk_MentorReader& stream);
};
struct Unk_MMIdPacket7                                      // protocol 7 (0x140b73030)
{
    unsigned char protocol;
    __int64 id;
    Unk_MMIdPacket7() : protocol(7), id(0) {}
    void FUN_14069a700(Unk_MentorReader& stream);
};
struct Unk_MMValuePacket10                                  // protocol 10 (0x140b731a0)
{
    unsigned char protocol;
    int value;
    __int64 id;
    Unk_MMValuePacket10() : protocol(10), value(0), id(0) {}
    void FUN_14069a9c0(Unk_MentorReader& stream);
};
struct Unk_MMTwoValuePacket11                               // protocol 11 (0x140b731d0)
{
    unsigned char protocol;
    int a, b;
    __int64 id;
    Unk_MMTwoValuePacket11() : protocol(11), a(0), b(0), id(0) {}
    void FUN_14069aa90(Unk_MentorReader& stream);
};
struct Unk_MMTwoIdPacket12                                  // protocol 12 (0x140b73180)
{
    unsigned char protocol;
    __int64 a, b;
    Unk_MMTwoIdPacket12() : protocol(12) {}
    void FUN_14069ac90(Unk_MentorReader& stream);
};
struct Unk_MMPairPacket15                                   // protocol 15 (0x140b730e0)
{
    unsigned char protocol;
    ATL::CAtlArray<CMentorPairModePacket::CPairMode> entries;
    Unk_MMPairPacket15() : protocol(15) {}
    void FUN_14069ab50(Unk_MentorReader& stream);
};
struct Unk_MMResultPacket16                                 // protocol 16 (0x140b73080)
{
    unsigned char protocol, result;
    int value;
    Unk_MMResultPacket16() : protocol(16), result(0), value(0) {}
    void FUN_14069a910(Unk_MentorReader& stream);
};

// The payload readers take the packet's input stream (the CInputStream base at +8).
#define MMReader(packet) reinterpret_cast<Unk_MentorReader&>(static_cast<CInputStream&>(packet))

// ---- CMentoringManager --------------------------------------------------------------------------------------------

// @0x140b71440
CMentoringManager::CMentoringManager()
{
    FUN_140b71500();
}

// @0x140b714b0
CMentoringManager::~CMentoringManager()
{
}

// @0x140b71500
void CMentoringManager::FUN_140b71500()
{
    m_n8 = 0;
    m_nC = 0;
    m_n10 = 0;
    m_n18 = 0;
    m_n20 = 0;
    m_mentors.RemoveAll();
    m_mentees.RemoveAll();
}

// @0x140b71580
unsigned CMentoringManager::FUN_140b71580()
{
    Unk_MMPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    return pPlayer->FUN_14165ffe0();
}

// @0x140b715c0
int CMentoringManager::FUN_140b715c0()
{
    int nDays = (int)GetDaysBetween(m_n20, GetServerTime());
    if (nDays > 0)
        return 0;
    return m_n18;
}

// @0x140b71610
bool CMentoringManager::FUN_140b71610()
{
    return m_n20 <= GetServerTime();
}

// @0x140b71650
int CMentoringManager::FUN_140b71650()
{
    if (GetServerTime() > m_n10)
        return 0;
    return m_nC;
}

// @0x140b71680
CMentoringManager::MentorPtr CMentoringManager::FUN_140b71680(int nIndex)
{
    if (!(nIndex >= 0 && nIndex < (int)m_mentees.GetCount()))
        return 0;
    return m_mentees[nIndex];
}

// @0x140b71720
size_t CMentoringManager::FUN_140b71720()
{
    return m_mentees.GetCount();
}

// @0x140b71750
size_t CMentoringManager::FUN_140b71750()
{
    return m_mentors.GetCount();
}

// @0x140b71780
CStringW CMentoringManager::FUN_140b71780()
{
    UICharacterListDialog* pDialog = Unk_MMDialog<UICharacterListDialog>(0x4ef1);
    if (pDialog != 0)
    {
        int nCount = pDialog->FUN_1418f1c20();
        for (int i = 0; i < nCount; i = i + 1)
        {
            UICharacterListDialog::CharPtr spCharacter = pDialog->FUN_1418f0730(i);
            if (spCharacter.get() ? true : false)
            {
                if (spCharacter->FUN_1418e9cb0() == m_n28)
                    return spCharacter->FUN_1418e9cd0();
            }
        }
    }
    return CStringW(L"");
}

// @0x140b718b0
CStringW CMentoringManager::FUN_140b718b0()
{
    UICharacterListDialog* pDialog = Unk_MMDialog<UICharacterListDialog>(0x4ef1);
    if (pDialog != 0)
    {
        int nCount = pDialog->FUN_1418f1c20();
        for (int i = 0; i < nCount; i = i + 1)
        {
            UICharacterListDialog::CharPtr spCharacter = pDialog->FUN_1418f0730(i);
            if (spCharacter.get() ? true : false)
            {
                if (spCharacter->FUN_1418e9cb0() == m_n30)
                    return spCharacter->FUN_1418e9cd0();
            }
        }
    }
    return CStringW(L"");
}

// @0x140b719e0
// MS2-FUNCTIONAL: jump-table data and relocs differ only
void CMentoringManager::OnPacket(CInPacket& packet)
{
    int nProtocol = packet.vfunc_o8_1();
    switch (nProtocol)
    {
    case 1:
        OnResult(packet);
        break;
    case 2:
        OnMentorList(packet);
        break;
    case 3:
        OnMenteeList(packet);
        break;
    case 4:
        OnMenteeRegistered(packet);
        break;
    case 5:
        OnInviteMentee(packet);
        break;
    case 6:
        OnMentorApproved(packet);
        break;
    case 7:
        OnMentorDeclined(packet);
        break;
    case 8:
        OnMentorRegistered(packet);
        break;
    case 9:
        OnShowDialog(packet);
        break;
    case 10:
        OnSetDate(packet);
        break;
    case 11:
        OnSetCounts(packet);
        break;
    case 12:
        OnSetIds(packet);
        break;
    case 14:
        OnMentorRequest(packet);
        break;
    case 15:
        OnPairMode(packet);
        break;
    case 16:
        OnError(packet);
        break;
    }
}

// @0x140b71bb0
void CMentoringManager::OnResult(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMResultPacket1 data;
    data.FUN_14069a420(MMReader(packet));
    Unk_MMPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(data.value);
    if (pPlayer != 0)
        pPlayer->FUN_14165ffc0(data.result);
}

// @0x140b71c30
void CMentoringManager::OnMentorList(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMListPacket2 data;
    data.FUN_14069a0b0(MMReader(packet));
    m_mentors.RemoveAll();
    m_mentors.Copy(data.entries);
    Unk_MentorPtr<UIInviteMentoringDialog> spDialog(FUN_140b6f4c0(0x4f4c));
    if (spDialog == 0)
        return;
    spDialog->FUN_140c2f070(m_mentors);
}

// @0x140b71d40
void CMentoringManager::OnMenteeList(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMListPacket3 data;
    data.FUN_14069a290(MMReader(packet));
    m_mentees.RemoveAll();
    m_mentees.Copy(data.entries);
    UIMentoringDialog* pDialog = Unk_MMDialog<UIMentoringDialog>(0x4f4b);
    if (pDialog != 0)
        pDialog->RefreshPage();
}

// @0x140b71df0
void CMentoringManager::OnPairMode(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMPairPacket15 data;
    data.FUN_14069ab50(MMReader(packet));
    for (unsigned i = 0; i < data.entries.GetCount(); i = i + 1)
    {
        const CMentorPairModePacket::CPairMode& entry = data.entries.GetAt(i);
        for (size_t j = 0; j < m_mentees.GetCount(); j = j + 1)
        {
            MentorPtr spMentee(m_mentees[j]);
            if (spMentee->c == entry.id)
                spMentee->online = entry.enabled;
        }
    }
    UIMentoringDialog* pDialog = Unk_MMDialog<UIMentoringDialog>(0x4f4b);
    if (pDialog != 0)
        pDialog->RefreshPage();
}

// @0x140b71f70
void CMentoringManager::OnMenteeRegistered(CInPacket& packet)
{
    if (FUN_1403ed2b0()->FUN_141adc890(0x4f4b) != 0)
        FUN_1403ed2b0()->FUN_141adc5d0(0x4f4b);
    FUN_1412751b0(GetStringCommonByKey(L"s_mentoring_register_mentee"), 0x10);
}

// @0x140b72020
void CMentoringManager::OnInviteMentee(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMNamePacket5 data;
    data.FUN_14069a5a0(MMReader(packet));
    FUN_1412751b0(FUN_1405c2690(CStringW(L"s_mentoring_invite_invite_mentee"), data.name), 0x10);
}

// @0x140b720f0
// MS2-FUNCTIONAL: loop-continue branch shape (exe duplicates the continue edge)
void CMentoringManager::OnMentorApproved(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMIdPacket6 data;
    data.FUN_14069a670(MMReader(packet));
    CStringW strName(L"");
    for (unsigned i = 0; i < m_mentors.GetCount(); i = i + 1)
    {
        MentorPtr spMentor(m_mentors.GetAt(i));
        if (!(spMentor == 0))
        {
            if (spMentor->a == data.id)
            {
                strName = spMentor->name;
                m_mentees.Add(spMentor);
                break;
            }
        }
    }
    m_mentors.RemoveAll();
    if (!strName.IsEmpty())
        FUN_1412751b0(FUN_1405c2690(CStringW(L"s_mentoring_invite_approve_mentor"), strName), 0x10);
    FUN_1403ed2b0()->FUN_141adc5d0(0x4f4b);
}

// @0x140b722f0
// MS2-FUNCTIONAL: loop-continue branch shape as OnMentorApproved
void CMentoringManager::OnMentorDeclined(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMIdPacket7 data;
    data.FUN_14069a700(MMReader(packet));
    for (unsigned i = 0; i < m_mentors.GetCount(); i = i + 1)
    {
        MentorPtr spMentor(m_mentors.GetAt(i));
        if (!(spMentor == 0))
        {
            if (spMentor->a == data.id)
            {
                m_mentors.RemoveAt(i, 1);
                if (spMentor->name.GetLength() > 0)
                    FUN_1412751b0(FUN_1405c2690(CStringW(L"s_mentoring_invite_decline_mentor"), spMentor->name), 0x10);
                break;
            }
        }
    }
    Unk_MentorPtr<UIInviteMentoringDialog> spDialog(FUN_140b6f4c0(0x4f4c));
    if (!(spDialog == 0))
        spDialog->FUN_140c2f070(m_mentors);
}

// @0x140b72540
void CMentoringManager::OnMentorRegistered(CInPacket& packet)
{
    if (FUN_1403ed2b0()->FUN_141adc890(0x4f4b) != 0)
        FUN_1403ed2b0()->FUN_141adc5d0(0x4f4b);
    FUN_1412751b0(GetStringCommonByKey(L"s_mentoring_register_mentor"), 0x10);
}

// @0x140b725f0
void CMentoringManager::OnShowDialog(CInPacket& packet)
{
    Unk_MentorPtr<UIMentoringDialog> spDialog(Unk_MMDialog<UIMentoringDialog>(0x4f4b));
    if (spDialog.get() != 0)
    {
        if (spDialog->FUN_141924630() != 0)
            spDialog->Refresh();
        else
            spDialog->FUN_141924680();
    }
}

// @0x140b72680
void CMentoringManager::OnSetDate(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMValuePacket10 data;
    data.FUN_14069a9c0(MMReader(packet));
    m_n18 = data.value;
    m_n20 = data.id;
}

// @0x140b726f0
void CMentoringManager::OnSetCounts(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMTwoValuePacket11 data;
    data.FUN_14069aa90(MMReader(packet));
    m_n8 = data.a;
    m_nC = data.b;
    m_n10 = data.id;
}

// @0x140b72760
void CMentoringManager::OnMentorRequest(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MentorDetailPacket data;
    data.FUN_14069a850(MMReader(packet));
    m_mentors.Add(data.mentor);
    Unk_MentorPtr<UIInviteMentoringDialog> spDialog(FUN_140b6f4c0(0x4f4c));
    if (spDialog.get() != 0)
        spDialog->FUN_140c2f070(m_mentors);
    FUN_1412751b0(FUN_1405c2690(CStringW(L"s_mentoring_notify_mentor_request"), data.name), 0x10);
}

// @0x140b72d80
void CMentoringManager::OnSetIds(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMTwoIdPacket12 data;
    data.FUN_14069ac90(MMReader(packet));
    m_n28 = data.a;
    m_n30 = data.b;
}

// @0x140b728b0
// MS2-FUNCTIONAL: branch layout/EH state map differs
void CMentoringManager::OnError(CInPacket& packet)
{
    FUN_140b736c0(packet, -1);
    Unk_MMResultPacket16 data;
    data.FUN_14069a910(MMReader(packet));
    switch (data.result)
    {
    case 1:
        FUN_1412751f0(GetStringCommonByKey(L"s_mentoring_error_is_not_return_user"), 1, 1);
        break;
    case 2:
        FUN_1412751f0(GetStringCommonByKey(L"s_mentoring_error_target_not_exists"), 1, 1);
        break;
    case 3:
        FUN_1412751f0(GetStringCommonByKey(L"s_mentoring_error_invalid_target"), 1, 1);
        break;
    case 4:
        FUN_1412751f0(GetStringCommonByKey(L"s_mentoring_error_mentor_has_max_count_waiting"), 1, 1);
        break;
    case 5:
        FUN_1412751f0(GetStringCommonByKey(L"s_mentoring_error_mentee_has_max_count_received"), 1, 1);
        break;
    case 6:
        FUN_1412751f0(GetStringCommonByKey(L"s_mentoring_error_mentee_is_not_mentee"), 1, 1);
        break;
    case 7:
        FUN_1412751f0(GetStringCommonByKey(L"s_mentoring_error_mentee_has_already_mento"), 1, 1);
        break;
    case 8:
        FUN_1412751f0(GetStringCommonByKey(L"s_mentoring_error_already_requested_to_mentee"), 1, 1);
        break;
    case 9:
        FUN_1412751f0(GetStringCommonByKey(L"s_mentoring_error_full_earn_coin"), 1, 1);
        break;
    }
}

// @0x140b73bc0
// MS2-FUNCTIONAL: the exe's tail merges the false returns differently (2 bytes)
bool FUN_140b73bc0(MyPC* pMyPC)
{
    if (pMyPC == 0)
        return false;
    if (FUN_1408e57f0()->FUN_1422b9e00() == 0x620001f)
        return false;
    if (((Unk_MMPlayer*)pMyPC)->FUN_1416595d0() == 1)
        return false;
    if (((Unk_MMPlayer*)pMyPC)->FUN_141675ed0() == 1)
        return false;
    int nValue = ((Unk_MMPlayer*)pMyPC)->FUN_14166c930();
    if (nValue <= 0)
        return false;
    if (nValue <= 2 || nValue == 4)
        return true;
    return false;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca0e10-0x142ca0ea0 .text$yd
