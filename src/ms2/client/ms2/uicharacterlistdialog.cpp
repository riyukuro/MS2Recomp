// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICharacterListDialog: see uicharacterlistdialog.h.
// MS2-UNIT: ?\uicharacterlistdialog.cpp
// MS2-RANGE: 0x140111400-0x140111600 .text$di
// MS2-RANGE: 0x1418e93f0-0x1418fafd0 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicharacterlistdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uicharacterlistdialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di) ---------------------------------------------------------------------------------------------

// @0x140111400
std::shared_ptr<UICharacterListDialog::DeleteReply> UICharacterListDialog::s_reply(nullptr);

// @0x140111430
static CStringW s_strChangeInvalidCharName(L"changeInvalidCharName");

#include "ms2/placeholder/header_statics_a.h"

// @0x1401115d0
static UICommon::CMyPCKeyInputController s_keyInput;

static int s_nOrder;                                    // 0x143af1980 the next CCharacterInfo order number

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

__int64 FUN_140869440();                                // the server time
class Unk_ClClock { public: unsigned FUN_141473390(); };
Unk_ClClock* FUN_14086d260();                           // the tick clock
CUgcManager* FUN_14052d220();
CStringW FUN_14028b8e0(const CStringW& strKey);         // string table text
void FUN_140d73aa0(CStringW strMsg, int nType, void* pTarget, CStringW strTag);
// The generic reader of an item from a stream (the 0x141272280 object is an empty functor).
class Unk_ClItemReader
{
public:
    Unk_ClItemReader();                                 // 0x141272280
    MS2Ptr<CItem> FUN_1401fce40(CInputStream& s);
};
class Unk_ClPackets { public: void FUN_140da5180(int, Delegate<void(CInPacket&)>); void FUN_140da51e0(int, Delegate<void(CInPacket&)>); };
Unk_ClPackets* FUN_140bccd50();
class Unk_ClUserInfo { public: char m_pad[0x20]; CStringW m_str20; __int64 m_n28; };
class Unk_ClUserMgr { public: Unk_ClUserInfo* FUN_140cfd260(); };
Unk_ClUserMgr* FUN_1409a8b10();
extern char DAT_143ab2946;

// ---- CCharacterInfo -------------------------------------------------------------------------------------------------

// @0x1418e93f0
UICharacterListDialog::CCharacterInfo::CCharacterInfo()
{
    m_nSeconds = 0;
    m_nStarted = 0;
    m_nDeleteTime = 0;
    m_nOrder = 0;
}

// @0x1418e94b0
UICharacterListDialog::CCharacterInfo::~CCharacterInfo()
{
}

// @0x1418e9520
// MS2-FUNCTIONAL: the temps / null-check shape of the three `new CItem` loops (frame 0x188 in the exe) is not reproduced
void UICharacterListDialog::CCharacterInfo::Read(CInPacket& packet)
{
    m_state.FUN_1408eeb60(&packet);
    CInputStream& s = packet;
    m_text368 = s.vfunc_o8_6();
    if (FUN_14052d220()->FUN_14187f3b0() == 1)
        m_text368 = "";
    FUN_1418e9fa0(s.vfunc_o8_4());
    int nCount = s.vfunc_o8_1();
    for (int i = 0; i < nCount; ++i)
    {
        int nId = s.vfunc_o8_3();
        __int64 nUid = s.vfunc_o8_4();
        int nRank = s.vfunc_o8_1();
        int nAmount = s.vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nId, nAmount, 0))
            break;
        spItem->FUN_140526c10(nRank);
        spItem->FUN_140524eb0(s);
        spItem->FUN_140526a70(nUid);
        m_state.m_220.Add(spItem);
    }
    nCount = s.vfunc_o8_1();
    Unk_ClItemReader reader;
    for (int i = 0; i < nCount; ++i)
    {
        MS2Ptr<CItem> spItem = reader.FUN_1401fce40(s);
        if (!(spItem == 0))
            m_state.m_240.Add(spItem);
    }
    if (s.vfunc_o8_0())
    {
        __int64 nFirst = s.vfunc_o8_4();
        __int64 nSecond = s.vfunc_o8_4();
        m_state.m_280 = nFirst;
        m_state.m_288 = nSecond;
        nCount = s.vfunc_o8_1();
        if (nCount != 0)
        {
            for (int i = 0; i < nCount; ++i)
            {
                int nId = s.vfunc_o8_3();
                __int64 nUid = s.vfunc_o8_4();
                int nRank = s.vfunc_o8_1();
                int nAmount = s.vfunc_o8_3();
                MS2Ptr<CItem> spItem(new CItem);
                if (!spItem->FUN_140523c40(nId, nAmount, 0))
                    return;
                spItem->FUN_140526c10(nRank);
                spItem->FUN_140524eb0(s);
                spItem->FUN_140526a70(nUid);
                spItem->FUN_14052a130(2);
                m_state.m_260.Add(spItem);
            }
        }
    }
}

// @0x1418e9cb0
unsigned __int64 UICharacterListDialog::CCharacterInfo::FUN_1418e9cb0()
{
    return m_state.m_8;
}

// @0x1418e9cd0
CStringW UICharacterListDialog::CCharacterInfo::FUN_1418e9cd0()
{
    return m_state.FUN_1408f19e0();
}

// @0x1418e9d20
void UICharacterListDialog::CCharacterInfo::FUN_1418e9d20(const CStringW& strName)
{
    m_state.FUN_1408f07e0(strName);
}

// @0x1418e9d50
Unk_UserProxy* UICharacterListDialog::CCharacterInfo::FUN_1418e9d50()
{
    return &m_state;
}

// @0x1418e9d70
const Unk_UserProxy* UICharacterListDialog::CCharacterInfo::FUN_1418e9d70() const
{
    return &m_state;
}

// @0x1418e9d90
CString UICharacterListDialog::CCharacterInfo::FUN_1418e9d90()
{
    return m_text368;
}

// @0x1418e9de0
void UICharacterListDialog::CCharacterInfo::FUN_1418e9de0(CString str)
{
    m_text368 = str;
}

// @0x1418e9e30
void UICharacterListDialog::CCharacterInfo::FUN_1418e9e30(CString str)
{
    m_text370 = str;
}

// @0x1418e9e80
CString UICharacterListDialog::CCharacterInfo::FUN_1418e9e80()
{
    return m_text370;
}

// @0x1418e9ed0
void UICharacterListDialog::CCharacterInfo::FUN_1418e9ed0(unsigned nSeconds)
{
    m_nSeconds = nSeconds;
    if (nSeconds > 0)
        m_nStarted = FUN_14086d260()->FUN_141473390();
    else
        m_nStarted = 0;
}

// @0x1418e9f30
int UICharacterListDialog::CCharacterInfo::FUN_1418e9f30()
{
    if (m_nStarted > 0 && m_nSeconds > 0)
    {
        unsigned nPassed = (FUN_14086d260()->FUN_141473390() - m_nStarted) / 1000;
        return m_nSeconds - nPassed;
    }
    return 0;
}

// @0x1418e9fa0
int UICharacterListDialog::CCharacterInfo::FUN_1418e9fa0(__int64 nDeleteTime)
{
    m_nDeleteTime = nDeleteTime;
    __int64 nNow = FUN_140869440();
    int nSeconds = 0;
    if (nNow < m_nDeleteTime)
        nSeconds = (int)(m_nDeleteTime - nNow);
    FUN_1418e9ed0(nSeconds);
    return nSeconds;
}

// @0x1418ea020
__int64 UICharacterListDialog::CCharacterInfo::FUN_1418ea020()
{
    return m_nDeleteTime;
}

// @0x1418ea040
void UICharacterListDialog::CCharacterInfo::FUN_1418ea040(int nOrder)
{
    m_nOrder = nOrder;
}

// @0x1418ea060
int UICharacterListDialog::CCharacterInfo::FUN_1418ea060()
{
    return m_nOrder;
}

// @0x1418ea080
int UICharacterListDialog::CCharacterInfo::FUN_1418ea080()
{
    return ++s_nOrder;
}

// @0x1418ea0a0
void UICharacterListDialog::CCharacterInfo::FUN_1418ea0a0()
{
    s_nOrder = 0;
}

// ---- CDeleteCharacterInfo -------------------------------------------------------------------------------------------

// @0x1418ea0c0
UICharacterListDialog::CDeleteCharacterInfo::CDeleteCharacterInfo(CharPtr spCharacter, MS2Ptr<ASMovieClip> spMovie)
    : m_spCharacter(spCharacter), m_spMovie(spMovie)
{
}

// @0x1418ea150
UICharacterListDialog::CDeleteCharacterInfo::~CDeleteCharacterInfo()
{
    m_spCharacter = 0;
    m_spMovie = 0;
}

// @0x1418ea1e0
UICharacterListDialog::DeleteReply::DeleteReply(unsigned char nResult, const CStringW& str1, const CStringW& str2, const CStringW& str3)
    : m_nResult(0)
{
    m_nResult = nResult;
    m_str8 = str1;
    m_str10 = str2;
    m_str18 = str3;
}
