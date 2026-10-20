// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The party UI: ASPartyVotePage and UIPartyDialog (the party
// window), UIPartyDPSDialog, UIPerformanceDialog, UIPopupEntity and UIPopUpMenu. The exe range holds five original TUs
// (five header-static initializer groups in .text$di, one memmove_s copy); they are recovered here as one file.
// MS2-UNIT: client\ms2\uipartydialog.cpp
// MS2-RANGE: 0x14011a360-0x14011aab0 .text$di
// MS2-RANGE: 0x141a738f0-0x141a8f3a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipartydialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/header_statics_a.h"
#include "uipartydialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/cpartymember.h"
#include "ms2/placeholder/partyvotecli.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/roomstagedungeoncli.h"
#include "ms2/placeholder/cmycharacter.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/battlerecordmanager.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/mstime.h"
#include <algorithm>
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----
class Unk_PdWorld                                                       // the world service (FUN_1403ed2d0)
{
public:
    MyPC* FUN_141bd0cc0();                                              // the local player
    PC* FUN_141bd1530(__int64 nCharId);                                 // a player by character id
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                              // the current field data
    int FUN_141bc2bc0();
    int FUN_141bc2b30();
};
Unk_PdWorld* FUN_1403ed2d0();
class Unk_PdApp;                                                        // the application (FUN_1403ed2b0)
Unk_PdApp* FUN_1403ed2b0();
void FUN_141add1f0(Unk_PdApp* pApp);                                    // open the merat charge page
CPartyManager* FUN_1409670d0();                                         // TSingleton<CPartyManager>::GetInstance
CFeatureManager* FUN_140166410();                                       // TSingleton<CFeatureManager>::GetInstance
CStringTable* FUN_1401a9d70();                                          // TSingleton<CStringTable>::GetInstance
IClientPlatform* FUN_140d86260();
class Unk_PdPopupMenu;                                                  // UIPopUpMenu (below) as seen by the lookup
UIDialog* FUN_140c30140(int nDialogId);                                 // the open dialog of this id
class Unk_PdClubManager { public: int FUN_140b14cd0(); void FUN_140b15c10(CStringW strName); };
Unk_PdClubManager* FUN_140e0d900();
class Unk_PdNametagFlags { public: char m_00[0x30]; bool m_30; };       // m_30: show the returning-user mark
Unk_PdNametagFlags* FUN_1406c7610();
class Unk_PdKeyState;                                                   // the input state; +8 is the lock set (FUN_1402c4c90)
char* FUN_14025e7b0();
int FUN_1402c4c90(void* pLocks, int nLock);
bool FUN_140930b10();
bool FUN_140930b40();
CMyCharacter* FUN_140931510();
unsigned int FUN_140869420();                                           // the server time (seconds)
extern __int64 DAT_143ab2828;                                           // the own character id
extern int DAT_1439f4a7c;
extern Unk_Inventory DAT_143ab2a90;

CString FUN_140719530(unsigned __int64 n);                              // decimal text
__int64 FUN_140718350(const CString& str);                              // parse an __int64
CStringW FUN_140719630(int n);                                          // decimal text
double FUN_140f17ed0(const Scaleform::GFx::Value& v);                   // a number value
bool FUN_141a4bfb0(const Scaleform::GFx::Value& v);                     // is a bool value
bool FUN_1409c1720(const Scaleform::GFx::Value& v);                     // the bool value
CStringW FUN_1408116a0(int nStringId, const int& n);                    // FormatStringId<int>
CStringW FUN_140632a60(int nStringId, const CStringW& a, const CStringW& b);   // FormatStringId<CStringW, CStringW>
CStringW FUN_14028de60(int nStringId);                                  // the string of an id
CStringW FUN_14028b8e0(const CStringW& strKey);                         // the string of a key
void FUN_1412751f0(const CStringW& strText, int nA, int nB);            // system message
void FUN_140d73bc0(int nStringId, int nA, int nB, CStringW strText);    // notice by id
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, IMessageListener* pListener, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW strText);   // yes / no box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                            // show a box
void FUN_140710590(COutPacket& packet);                                 // send
void FUN_14151f200();                                                   // close the message box
void FUN_14025a680(CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szSep);   // split
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
int FUN_141637c40(CPartyMember* pMember);                               // the member state
double FUN_1407184e0(const CStringW& str);                              // parse a number
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);     // FUN_14028dfa0<CStringW>
CStringW FUN_140c2fcc0(CStringW strFormat, const int& nHour, const int& nMinute, const int& nSecond, const CStringW& strArg);
void FUN_141b70810(unsigned nMs, CStringW& strOut);                     // elapsed time text
// The chat record the notice history is posted as (uichaosdpsdialog.cpp).
struct Unk_PdChat
{
    Unk_PdChat();                                                       // 0x140acd570
    ~Unk_PdChat();                                                      // 0x140acd770
    int state, kind;
    CStringW message, target;
    __int64 value;
};
MS2_CHECK_SIZE(Unk_PdChat, 0x20);
void FUN_141276f80(const Unk_PdChat& kChat);                            // post a chat record
class Unk_PdMainSystem { public: unsigned int FUN_141473460(); float FUN_141473210(); };   // CMainSystem: draw count, fps
Unk_PdMainSystem* FUN_14086d260();
extern const wchar_t DAT_142fd11d4[];                                   // L","
extern const char DAT_142fd1144[];                                      // "x"
extern const char DAT_142fd116c[];                                      // "y"

// AScript members this unit calls that the shared header does not declare (same this / return ABI).
struct Unk_PdScript : AScript
{
    Scaleform::GFx::Value FUN_140f0c520(const char* szMethod, CString a1, Scaleform::GFx::Value a2);   // Invoke(method, string, value)
    Scaleform::GFx::Value FUN_140e06cc0(const char* szMethod, double d);   // Invoke(method, number) (uichaosdpsdialog.cpp)
    Scaleform::GFx::Value FUN_1422bb330(const char* szMethod);             // Invoke(method)
};

// ASObj member setters through an ASData argument (one COMDAT per value type in this unit).
template <class T> void Unk_PdSetData(ASObj* pObj, const char* szName, T value)
{
    ASData data;
    data.FUN_1422b7f70(value);
    FUN_1407cd930(&pObj->FUN_1422bb870(), szName, data.FUN_1422b9260());
}
enum Unk_PdTombType : int { Unk_PdTombNone = 0 };

#define PD_SWF_ERROR(line) new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(line), __FUNCTION__))

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> PdParamsDelegate;

// ======== ASPartyVotePage ========

// @0x141a738f0
ASPartyVotePage::ASPartyVotePage(MS2Ptr<ASMovieClip> spPage)
    : m_page(spPage)
{
}

// @0x141a739c0
ASPartyVotePage::~ASPartyVotePage()
{
}

// MS2-FUNCTIONAL: written from the decompile (frame slots of the binder temporaries unverified)
// @0x141a73a70
void ASPartyVotePage::OnInit()
{
    if (m_page == 0)
        throw PD_SWF_ERROR(0x27);
    m_page->vfunc_4(false);
    m_page->FUN_140beaf20("m_title", m_title);
    if (m_title == 0)
        throw PD_SWF_ERROR(0x2d);
    m_page->FUN_140beaf20("m_yesCount", m_yesCount);
    if (m_yesCount == 0)
        throw PD_SWF_ERROR(0x2e);
    m_page->FUN_140beaf20("m_noCount", m_noCount);
    if (m_noCount == 0)
        throw PD_SWF_ERROR(0x2f);
    m_page->FUN_140bbe640("m_yesButton", m_yesButton);
    if (m_yesButton == 0)
        throw PD_SWF_ERROR(0x30);
    m_page->FUN_140bbe640("m_noButton", m_noButton);
    if (m_noButton == 0)
        throw PD_SWF_ERROR(0x31);
    m_page->FUN_140beaf20("m_votedText", m_votedText);
    if (m_votedText == 0)
        throw PD_SWF_ERROR(0x32);
    m_yesButton->FUN_1422ce240(PdParamsDelegate(this, &ASPartyVotePage::FUN_141a74a60), 0);
    m_noButton->FUN_1422ce240(PdParamsDelegate(this, &ASPartyVotePage::FUN_141a74a90), 0);
}

// @0x141a74760
void ASPartyVotePage::FUN_141a74760()
{
    if (!(m_page == 0))
    {
        MS2Ptr<PartyVoteCli> spVote = FUN_1409670d0()->FUN_14162c350();
        if (!(spVote == 0) && spVote->vfunc_5())
        {
            m_page->vfunc_4(true);
            CStringW strTitle = spVote->vfunc_4();
            m_title->FUN_1422c4f00(strTitle);
            m_yesCount->FUN_1422c4cd0(FUN_140719630((int)spVote->FUN_140a89560()));
            m_noCount->FUN_1422c4cd0(FUN_140719630((int)spVote->FUN_140a89590()));
            bool bVoted = spVote->FUN_140a895c0();
            m_yesButton->vfunc_4(!bVoted);
            m_noButton->vfunc_4(!bVoted);
            m_votedText->vfunc_4(bVoted);
            return;
        }
        m_page->vfunc_4(false);
    }
}

// @0x141a74a60
void ASPartyVotePage::FUN_141a74a60(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_141a74ac0(true);
}

// @0x141a74a90
void ASPartyVotePage::FUN_141a74a90(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_141a74ac0(false);
}

// @0x141a74ac0
void ASPartyVotePage::FUN_141a74ac0(bool bYes)
{
    MS2Ptr<PartyVoteCli> spVote = FUN_1409670d0()->FUN_14162c350();
    if (spVote == 0)
        return;
    spVote->FUN_140a89680(bYes);
}

// ======== UIPartyDialog ========

// @0x141a74b40
UIPartyDialog::UIPartyDialog()
    : m_deadline(0)
{
    m_2c = 0x11;
    FUN_141925e70(0, 1);
}

// @0x141a74c50
UIPartyDialog::~UIPartyDialog()
{
}

// @0x141a74d00
CString UIPartyDialog::vfunc_1()
{
    return "PartyDialog";
}

// @0x141a74d50
void UIPartyDialog::FUN_141a74d50(CPartyMember* pMember, int nFlags)
{
    if (!(m_30 == 0) && pMember != 0)
    {
        ASObj obj(2);
        if (FUN_141a784b0(obj, pMember, nFlags))
            static_cast<Unk_PdScript*>(m_30.get())->FUN_140f0c520("updateMember", FUN_140719530(pMember->user.m_8), obj.FUN_1422bb870());
    }
}

// @0x141a74ea0
void UIPartyDialog::FUN_141a74ea0()
{
    if (FUN_1409670d0()->FUN_14162ab20())
    {
        ATL::CAtlArray<MS2Ptr<CPartyMember>>& members = FUN_1409670d0()->FUN_14162ba30();
        size_t nCount = members.GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            CPartyMember* pMember = members[i].get();
            if (pMember != 0)
                FUN_141a74d50(pMember, 0x180);
        }
    }
}

// MS2-FUNCTIONAL: written from the decompile (ternary CString temporaries)
// @0x141a74f50
void UIPartyDialog::FUN_141a74f50(CPartyMember* pOld, CPartyMember* pNew)
{
    if (m_30 == 0)
        return;
    CString strOld = pOld == 0 ? CString("") : FUN_140719530(pOld->FUN_141637bb0());
    CString strNew = pNew == 0 ? CString("") : FUN_140719530(pNew->FUN_141637bb0());
    m_30->FUN_1413127f0("changeChief", strOld, strNew);
    if (FUN_140166410()->FUN_14036d570(0x56) == 1)
    {
        FUN_141a79770();
        FUN_141a75a20();
    }
}

// @0x141a752a0
int UIPartyDialog::FUN_141a752a0(CPartyMember* pMember)
{
    if (!(m_30 == 0))
    {
        ASObj obj(2);
        if (FUN_141a784b0(obj, pMember, 0x1ff) == 0)
            return 0;
        m_30->Invoke("addMember", obj.FUN_1422bb870());
        return 1;
    }
    return 0;
}

// @0x141a753d0
int UIPartyDialog::FUN_141a753d0(CPartyMember* pMember)
{
    if (!(m_30 == 0) && pMember != 0)
    {
        m_30->Invoke("removeMember", FUN_140719530(pMember->user.m_8));
        return 1;
    }
    return 0;
}

// @0x141a75490
int UIPartyDialog::FUN_141a75490(__int64 nCharId, float* pPos)
{
    if (!(m_30 == 0))
    {
        Scaleform::GFx::Value ret = m_30->Invoke("getCameraButtonPos", FUN_140719530(nCharId));
        Scaleform::GFx::Value x;
        Scaleform::GFx::Value y;
        ret.GetMember(DAT_142fd1144, &x);
        ret.GetMember(DAT_142fd116c, &y);
        if (FUN_140f17ed0(x) == 0.0 && FUN_140f17ed0(y) == 0.0)
            return 0;
        pPos[0] = (float)(pPos[0] + FUN_140f17ed0(x));
        pPos[1] = (float)(pPos[1] + FUN_140f17ed0(y));
        return 1;
    }
    return 0;
}

// @0x141a75680
int UIPartyDialog::FUN_141a75680(float* pPos)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe != 0 && pMe->FUN_14166ce30() != 0)
    {
        MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
        if (!(spField == 0) && spField->m_nGlobalSplit != 0)
        {
            ATL::CAtlArray<MS2Ptr<CPartyMember>>& members = FUN_1409670d0()->FUN_14162ba30();
            size_t nCount = members.GetCount();
            for (size_t i = 0; i < nCount; i++)
            {
                MS2Ptr<CPartyMember> spMember = members[i];
                if (spMember->user.m_8 == pMe->FUN_141656a80())
                    continue;
                if (FUN_141a75490(spMember->FUN_141637bb0(), pPos) == 1)
                    return 1;
            }
            return 0;
        }
    }
    return 0;
}

// @0x141a75840
bool UIPartyDialog::FUN_141a75840()
{
    if (!(m_30 == 0))
    {
        MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMe == 0)
            return false;
        if (pMe->FUN_14166ce30() == 0)
            return false;
        MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
        if (!(spField == 0) && spField->m_nGlobalSplit != 0)
        {
            Scaleform::GFx::Value ret = static_cast<Unk_PdScript*>(m_30.get())->FUN_1422bb330("isCanObserveMode");
            if (!FUN_141a4bfb0(ret))
                return false;
            return FUN_1409c1720(ret);
        }
        return false;
    }
    return false;
}

// @0x141a759b0
void UIPartyDialog::FUN_141a759b0()
{
    if (m_vote.get() != 0)
        m_vote->FUN_141a74760();
}

// @0x141a75a00
void UIPartyDialog::FUN_141a75a00(unsigned int nDeadline)
{
    m_deadline = nDeadline;
}

// @0x141a75a20
void UIPartyDialog::FUN_141a75a20()
{
    if (!(m_30 == 0))
        static_cast<Unk_PdScript*>(m_30.get())->FUN_1422bb330("arrangeBottomButton");
}

// MS2-FUNCTIONAL: written from the decompile (binder temporaries)
// @0x141a75a80
void UIPartyDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_30->FUN_140bbe640("m_enterDungeon", m_enterDungeon);
    if (m_enterDungeon == 0)
        throw PD_SWF_ERROR(0x7d);
    m_30->FUN_140bbe640("m_recall", m_recall);
    if (m_recall == 0)
        throw PD_SWF_ERROR(0x7e);
    m_30->FUN_140bbe640("m_createClub", m_createClub);
    if (m_createClub == 0)
        throw PD_SWF_ERROR(0x7f);
    m_30->FUN_140bbe640("m_giveUpDungeon", m_giveUpDungeon);
    if (m_giveUpDungeon == 0)
        throw PD_SWF_ERROR(0x80);
    m_30->FUN_140bbe640("m_dungeonName", m_dungeonName);
    if (m_dungeonName == 0)
        throw PD_SWF_ERROR(0x81);
    m_vote = new ASPartyVotePage(GetChild<ASMovieClip>("m_partyVote"));
    m_vote->OnInit();
    m_createClub->FUN_1422ce240(PdParamsDelegate(this, &UIPartyDialog::FUN_141a77ae0), 0);
    m_enterDungeon->FUN_1422ce240(PdParamsDelegate(this, &UIPartyDialog::FUN_141a77ab0), 0);
    m_giveUpDungeon->FUN_1422ce240(PdParamsDelegate(this, &UIPartyDialog::FUN_141a77dd0), 0);
    FUN_141a792b0();
    PacketHandlerManager::GetInstance()->RegisterHandler(0x53, Delegate<void(CInPacket&)>(this, &UIPartyDialog::FUN_141a77980));
    PacketHandlerManager::GetInstance()->RegisterHandler(0x100, Delegate<void(CInPacket&)>(this, &UIPartyDialog::FUN_141a77a40));
}

// @0x141a767d0
void UIPartyDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
    if (pMenu != 0)
        pMenu->FUN_141a80770();
    m_vote = 0;
    m_enterDungeon = 0;
    m_recall = 0;
    m_createClub = 0;
    m_giveUpDungeon = 0;
    m_dungeonName = 0;
    PacketHandlerManager::GetInstance()->UnregisterHandler(0x53, Delegate<void(CInPacket&)>(this, &UIPartyDialog::FUN_141a77980));
    PacketHandlerManager::GetInstance()->UnregisterHandler(0x100, Delegate<void(CInPacket&)>(this, &UIPartyDialog::FUN_141a77a40));
}

// @0x141a769d0
void UIPartyDialog::vfunc_15()
{
    if (!(m_30 == 0) && m_timer.Check(1000))
    {
        if (FUN_1409670d0()->FUN_14162c300())
            m_vote->FUN_141a74760();
        if (m_deadline != 0 && m_deadline < FUN_140869420())
            FUN_1409670d0()->FUN_14162c4a0(0);
    }
}

// MS2-FUNCTIONAL: written from the decompile (the three method branches share the result slot)
// @0x141a76a80
int UIPartyDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onPopupMenu", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            float x = data.FUN_1422b8c10();
            float y = data.FUN_1422b8c10();
            __int64 nCharId = FUN_140718350(data.FUN_1422b8d30());
            FUN_141a77760(x, y, nCharId);
        }
        return 1;
    }
    if (_stricmp("onCameraClick", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            __int64 nCharId = FUN_140718350(data.FUN_1422b8d30());
            PC* pTarget = FUN_1403ed2d0()->FUN_141bd1530(nCharId);
            MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pMe != 0 && pTarget != 0)
                pMe->FUN_14152a4a0(pTarget);
        }
        return 1;
    }
    if (_stricmp("onPartyRecall", szMethod) == 0)
    {
        if (!FUN_141a77eb0())
            return 1;
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e040(0x14);
        if (spItem == 0)
        {
            int nMerat = *FUN_1401d3200()->PartyRecallMerat.Get();
            CStringW strText = FUN_1408116a0(0xc64, nMerat);
            if (!FUN_140d86260()->vfunc_40(nMerat))
            {
                FUN_141add1f0(FUN_1403ed2b0());
                return 1;
            }
            FUN_140d86260()->vfunc_43(2, false, 1000);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, strText, this, CStringW(L"buy_scroll"));
            if (spBox == 0)
                return 1;
            FUN_140d73c60(spBox);
            return 1;
        }
        FUN_141a783d0(((CItem*)spItem)->FUN_140526a50());
    }
    return 0;
}

// MS2-FUNCTIONAL: written from the decompile
// @0x141a76ff0
void UIPartyDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (!(strMethod == "getTooltip"))
        return;
    if (m_70 != 0)
        return;
    UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
    if (pMenu != 0)
    {
        bool bSlotMenu = pMenu->FUN_141a80880() == 0 && _stricmp(pMenu->FUN_141a808c0(), "partySlot") == 0;
        if (bSlotMenu)
            return;
    }
    __int64 nCharId = FUN_140718350(pArgs->FUN_1422b8d30());
    if (nCharId == 0)
        return;
    CPartyMember* pMember = FUN_1409670d0()->FUN_14162afc0(nCharId).get();
    if (pMember == 0)
        return;
    int nStringId = pMember->FUN_141637c20() ? 0x57b : 0x57a;
    CStringW strText;
    if (!pMember->FUN_141637c20())
    {
        Unk_UserProxy* pUser = &pMember->user;
        CStringW strInfo;
        if (pUser->m_38 == 0)
        {
            strInfo = L"";
        }
        else
        {
            strInfo = FUN_1408116a0(0x76b, pUser->m_38);
            strInfo += L" ";
        }
        strInfo += FUN_1401a9d70()->FUN_141811980(3, pUser->m_2c);
        strText = FUN_140632a60(0x76c, FUN_14028de60(nStringId), strInfo);
    }
    else
    {
        strText = FUN_14028de60(nStringId);
    }
    if (!strText.IsEmpty())
    {
        ASTooltip tip(1, 2);
        if (tip.FUN_1409e26b0(strText))
        {
            tip.FUN_1409c6dc0(4);
            tip.FUN_1407cb9c0("offsetX", -30);
            tip.FUN_1407cb9c0("offsetY", -1);
            *pRetVal = tip.FUN_1422bb870();
        }
    }
}

// @0x141a774d0
int UIPartyDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) == 0 && pMsg->FUN_1422e4520() == 0)
    {
        if (pMsg->FUN_1422b8a10() == 0)
        {
            CStringW strTag = pMsg->FUN_1422b8f40();
            ATL::CAtlArray<CStringW> parts;
            FUN_14025a680(strTag, parts, DAT_142fd11d4);
            if (parts[0] == L"buy_scroll")
                FUN_141a783d0(-1);
            FUN_14151f200();
        }
        else
        {
            FUN_14151f200();
        }
    }
    return 1;
}

// @0x141a77600
bool UIPartyDialog::FUN_141a77600(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        CStringW strName = box.FUN_141a02d50();
        strName.Trim(L",");
        if (strName.IsEmpty())
            return false;
        FUN_140e0d900()->FUN_140b15c10(strName);
        return true;
    }
    return true;
}

// @0x141a776e0
bool UIPartyDialog::FUN_141a776e0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        COutPacket packet(0x9d, 0);
        packet.Encode1(5);
        FUN_140710590(packet);
    }
    return true;
}

// @0x141a77760
void UIPartyDialog::FUN_141a77760(float x, float y, __int64 nCharId)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    if (pMe->FUN_141656a80() == nCharId)
    {
        UIPopUpMenu* pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39);
        if (pMenu != 0)
        {
            Unk_PopupMenuInfo info(x, y, 3, 0x63fe, 1, "partySlot", 0);
            pMenu->FUN_141a7e280(info, pMe, 2);
        }
    }
    else
    {
        MS2Ptr<CPartyMember> spMember = FUN_1409670d0()->FUN_14162afc0(nCharId);
        UIPopUpMenu* pMenu;
        if (spMember.get() != 0 && (pMenu = (UIPopUpMenu*)FUN_140c30140(0x4e39)) != 0)
        {
            Unk_PopupMenuInfo info(x, y, 3, 0x63fe, 1, "partySlot", 0);
            pMenu->FUN_141a7f190(info, spMember);
        }
    }
}

// @0x141a77980
void UIPartyDialog::FUN_141a77980(CInPacket& packet)
{
    unsigned char nType = packet.vfunc_o8_1();
    if (nType == 0x11)
    {
        FUN_141a79840();
        FUN_141a75a20();
    }
    else if (nType == 0x19)
    {
        FUN_141a794e0();
        FUN_141a79570();
        FUN_141a75a20();
    }
    else if (nType > 0x2f && nType < 0x32)
    {
        FUN_141a759b0();
        FUN_141a75a20();
    }
}

// @0x141a77a40
void UIPartyDialog::FUN_141a77a40(CInPacket& packet)
{
    unsigned char nType = packet.vfunc_o8_1();
    if (nType > 2 && nType < 5)
    {
        FUN_141a79840();
        FUN_141a75a20();
    }
}

// @0x141a77ab0
void UIPartyDialog::FUN_141a77ab0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1409670d0()->FUN_14162bd40(0);
}

// MS2-FUNCTIONAL: written from the decompile
// @0x141a77ae0
void UIPartyDialog::FUN_141a77ae0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (FUN_1409670d0()->FUN_14162ab60())
    {
        if (FUN_140e0d900()->FUN_140b14cd0() == 1)
        {
            int nKind = 3;
            FUN_1412751f0(FUN_1408116a0(0x381, nKind), 1, 1);
        }
        else
        {
            int nMax = *FUN_1401d3200()->ClubNameLengthMax.Get();
            int nHalf = nMax / 2;
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(10, FUN_14028dfa0(CStringW(L"s_party_create_club"), nHalf, nMax), 0, CStringW(L""));
            if ((CMsgBoxData*)spBox != 0)
            {
                spBox->FUN_141a01d30(2, CStringW(L""), nMax, 0, 0);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIPartyDialog::FUN_141a77600));
                FUN_140d73c60(spBox);
            }
        }
    }
}

// @0x141a77dd0
void UIPartyDialog::FUN_141a77dd0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)>(this, &UIPartyDialog::FUN_141a776e0), CStringW(L"s_party_dungeon_giveup"));
}

// MS2-FUNCTIONAL: written from the decompile
// @0x141a77eb0
bool UIPartyDialog::FUN_141a77eb0()
{
    if (FUN_1402c4c90(FUN_14025e7b0() + 8, 0x1a) != 0)
    {
        FUN_140d73bc0(0x2f7, 0, 0, CStringW(L""));
        return false;
    }
    if (!FUN_1409670d0()->FUN_14162ab20())
    {
        FUN_140d73bc0(0xb5b, 0, 0, CStringW(L""));
        return false;
    }
    int nCount = FUN_1409670d0()->FUN_14162bf20();
    if (nCount - 1 < 1)
    {
        FUN_140d73bc0(0xb5d, 0, 0, CStringW(L""));
        return false;
    }
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return false;
    if (pMe->FUN_14166ce30() != 0)
    {
        FUN_140d73bc0(0xb57, 0, 0, CStringW(L""));
        return false;
    }
    if (pMe->FUN_14166c930() == 0x2c)
    {
        FUN_140d73bc0(0xb57, 0, 0, CStringW(L""));
        return false;
    }
    if (pMe->FUN_14166c930() != 1 || pMe->FUN_141675ed0() != 0)
    {
        FUN_140d73bc0(0xb59, 0, 0, CStringW(L""));
        return false;
    }
    if (DAT_1439f4a7c == 0)
    {
        FUN_140d73bc0(0xb58, 0, 0, CStringW(L""));
        return false;
    }
    if (FUN_140930b10())
    {
        FUN_140d73bc0(0xb58, 0, 0, CStringW(L""));
        return false;
    }
    if (FUN_1403ed2d0()->FUN_141bd30a0()->FUN_140375490() == 0)
    {
        FUN_140d73bc0(0xb58, 0, 0, CStringW(L""));
        return false;
    }
    int nLimit = FUN_1403ed2d0()->FUN_141bd30a0()->vfunc_2();
    if (nLimit > 0)
    {
        int nA = FUN_1403ed2d0()->FUN_141bc2bc0();
        int nB = FUN_1403ed2d0()->FUN_141bc2b30();
        if (nLimit < nB + nCount - 1 + nA)
        {
            FUN_140d73bc0(0xb5f, 0, 0, CStringW(L""));
            return false;
        }
    }
    if (pMe->FUN_141527160(0x2c) == 0)
    {
        FUN_140d73bc0(0xb59, 0, 0, CStringW(L""));
        return false;
    }
    return true;
}

// @0x141a783d0
void UIPartyDialog::FUN_141a783d0(__int64 nItemUid)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe != 0)
    {
        pMe->FUN_14166d970(pMe->vfunc_20());
        pMe->vfunc_59(0x2c, new StateRecallData(reinterpret_cast<void*>(nItemUid)), 0, 0);
    }
}

// MS2-FUNCTIONAL: written from the decompile
// @0x141a784b0
int UIPartyDialog::FUN_141a784b0(ASObj& obj, CPartyMember* pMember, unsigned int nFlags)
{
    static const CString s_level("level");
    static const CString s_job("job");
    static const CString s_name("name");
    static const CString s_hp("hp");
    static const CString s_maxhp("maxhp");
    static const CString s_oriMaxhp("oriMaxhp");
    static const CString s_chief("chief");
    static const CString s_state("state");
    static const CString s_charSN("charSN");
    static const CString s_profile("profile");
    static const CString s_ch("ch");
    static const CString s_chName("chName");
    static const CString s_observeMode("observeMode");
    static const CString s_tombType("tombType");
    static const CString s_diff("diff");
    if (pMember == 0)
        return 0;
    if (nFlags & 8)
        obj.FUN_1409c48f0(s_level, pMember->user.m_34);
    if (nFlags & 4)
        obj.FUN_140bd0d90(s_job, pMember->user.m_40);
    if (nFlags & 0x20)
        obj.FUN_1407cbb20(s_name, pMember->user.FUN_1408f19e0());
    if (nFlags & 2)
    {
        obj.FUN_1407cb9c0(s_hp, pMember->user.m_48);
        obj.FUN_1407cb9c0(s_maxhp, pMember->user.m_44);
        obj.FUN_1407cb9c0(s_oriMaxhp, pMember->user.m_44);
        int nTomb = pMember->user.FUN_1408f1ce0();
        obj.FUN_1407cb9c0(s_tombType, nTomb);
    }
    if (nFlags & 0x10)
        obj.FUN_1407cb9c0(s_chief, pMember->leader);
    if (nFlags & 1)
    {
        if (pMember->FUN_141637c20())
            Unk_PdSetData(&obj, s_tombType, Unk_PdTombNone);
        int nState = FUN_141637c40(pMember);
        obj.FUN_1407cb9c0(s_state, nState);
        Unk_PdSetData(&obj, "readyState", pMember->FUN_141637c90());
    }
    if (nFlags & 0x80)
    {
        CStringW strChName;
        CString strDiff;
        if (pMember->user.m_38 == 0)
            strChName = FUN_14028b8e0(CStringW(L"s_party_ch_dungeon"));
        else
            strChName = FUN_14028dfa0(CStringW(L"s_party_ch"), pMember->user.m_38);
        MS2Ptr<CPartyMember> spMine = FUN_1409670d0()->FUN_14162afc0(DAT_143ab2828);
        if (spMine.get() != 0)
        {
            CPartyMember* pMine = spMine.operator->();
            if (pMine->user.m_38 == pMember->user.m_38)
            {
                if (pMine->user.m_38 == 0)
                {
                    if (pMine->user.m_30 != pMember->user.m_30)
                        strDiff = s_diff;
                }
                else if (pMine->user.m_2c != pMember->user.m_2c)
                {
                    strDiff = s_diff;
                }
            }
            else
            {
                strDiff = s_diff;
            }
        }
        obj.FUN_1407cba60(s_ch, strDiff);
        obj.FUN_1407cbb20(s_chName, strChName);
    }
    if (nFlags & 0x100)
    {
        int nObserve = 0;
        MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        MS2Ptr<CPartyMember> spMine = FUN_1409670d0()->FUN_14162afc0(DAT_143ab2828);
        MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
        if (pMe != 0 && spMine.get() != 0)
        {
            if (pMe->FUN_141656a80() == pMember->user.m_8)
                nObserve = 0;
            else if (pMe->FUN_14166ce30() == 0)
                nObserve = 0;
            else if (!(spField == 0) && spField->m_nGlobalSplit != 0)
            {
                if (!(spField == 0) && spField->m_nCheckPartyObserve != 0)
                {
                    if (pMember->user.m_38 == spMine->user.m_38 && pMember->user.m_2c == spMine->user.m_2c &&
                        pMember->user.m_30 == spMine->user.m_30)
                        nObserve = pMember->role;
                    else
                        nObserve = 0;
                }
                else
                {
                    nObserve = 0;
                }
            }
            else
            {
                nObserve = 0;
            }
        }
        obj.FUN_1407cb9c0(s_observeMode, nObserve);
    }
    if (nFlags & 0x1ff)
    {
        if (FUN_1406c7610()->m_30)
            obj.FUN_1407cbbe0("returnUser", pMember->user.m_180 == 2);
        obj.FUN_1407cba60(s_charSN, FUN_140719530(pMember->user.m_8));
    }
    return 1;
}

// @0x141a792b0
void UIPartyDialog::FUN_141a792b0()
{
    if (!(m_30 == 0))
    {
        FUN_141a794e0();
        FUN_141a79570();
        FUN_141a796b0();
        FUN_141a79770();
        FUN_141a79840();
        FUN_141a759b0();
        FUN_141a75a20();
        ATL::CAtlArray<MS2Ptr<CPartyMember>>& members = FUN_1409670d0()->FUN_14162ba30();
        size_t nCount = members.GetCount();
        ASArray list(2);
        for (size_t i = 0; i < nCount; i++)
        {
            CPartyMember* pMember = members[i].get();
            if (pMember != 0)
            {
                ASObj obj(2);
                if (FUN_141a784b0(obj, pMember, 0x1ff))
                    list.FUN_1422bc050(obj.FUN_1422bb870());
            }
        }
        m_30->Invoke("initMembers", list.FUN_1422bb870());
    }
}

// @0x141a794e0
void UIPartyDialog::FUN_141a794e0()
{
    int bEnable = 0;
    if (!FUN_140930b40() && FUN_1409670d0()->FUN_14162abe0())
        bEnable = 1;
    if ((ASButton*)m_enterDungeon != 0)
        m_enterDungeon->vfunc_3(bEnable);
}

// @0x141a79570
void UIPartyDialog::FUN_141a79570()
{
    if (!(m_dungeonName == 0))
    {
        int nDungeonId = FUN_1409670d0()->FUN_14162c090();
        if (!FUN_140930b40() && nDungeonId != 0)
        {
            m_dungeonName->vfunc_4(true);
            m_30->Invoke("setDungeonName", FUN_1401a9d70()->FUN_141811980(0x14, nDungeonId));
        }
        else
        {
            m_dungeonName->vfunc_4(false);
        }
    }
}

// @0x141a796b0
void UIPartyDialog::FUN_141a796b0()
{
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (!(spField == 0) && spField->FUN_140375490() != 0)
        m_recall->vfunc_3(1);
    else
        m_recall->vfunc_3(0);
}

// @0x141a79770
void UIPartyDialog::FUN_141a79770()
{
    if (FUN_140166410()->FUN_14036d570(0x56) == 1)
    {
        if (FUN_1409670d0()->FUN_14162ab60())
            m_createClub->vfunc_3(1);
        else
            m_createClub->vfunc_3(0);
    }
    else
    {
        m_createClub->vfunc_3(0);
    }
}

// @0x141a79840
void UIPartyDialog::FUN_141a79840()
{
    RoomStageDungeonCli* pStage = FUN_140931510()->FUN_140d9f4e0().get();
    if (pStage != 0 && pStage->IsStageFlagSet() && FUN_1409670d0()->FUN_14162ab60())
    {
        m_giveUpDungeon->vfunc_4(true);
        return;
    }
    m_giveUpDungeon->vfunc_4(false);
}

// @0x141a7aa70
int UIPartyDialog::vfunc_48()
{
    return 0x4e45;
}

// ======== UIPartyDPSDialog ========

// The sort key shared by the ranking comparator and the rebuild (0x143af5008).
static int s_nPdSortMode;
bool FUN_141a7c2a0(MS2Ptr<CPartyMember> spA, MS2Ptr<CPartyMember> spB);

// @0x141a7b050
UIPartyDPSDialog::UIPartyDPSDialog()
{
    m_2c = 0x11;
    m_nGroup = 1;
    m_nMode = 0;
    FUN_141925e70(0, 1);
}

// @0x141a7b100
UIPartyDPSDialog::~UIPartyDPSDialog()
{
}

// @0x141a7b150
CString UIPartyDPSDialog::vfunc_1()
{
    return "PartyDPSDialog";
}

// @0x141a7b1a0
bool UIPartyDPSDialog::FUN_141a7b1a0(ASObj& obj, CPartyMember* pMember, unsigned int nRank)
{
    if (pMember != 0)
    {
        obj.FUN_1409c0d20("rank", nRank);
        obj.FUN_1409c48f0("level", pMember->user.m_34);
        obj.FUN_140bd0d90("job", pMember->user.m_40);
        obj.FUN_1407cbb20("name", pMember->user.FUN_1408f19e0());
        double dMeter = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(m_nGroup, pMember->FUN_141637bb0(), m_nMode));
        obj.FUN_140e06d60("meterValue", dMeter);
        CStringW strMeter = CBattleRecordManager::GetInstance()->FUN_140a04830(m_nGroup, pMember->FUN_141637bb0(), m_nMode);
        obj.FUN_1407cbb20("meterText", strMeter);
    }
    return pMember != 0;
}

// @0x141a7b3c0
void UIPartyDPSDialog::FUN_141a7b3c0()
{
    if (m_30.IsNull())
        return;
    CStringW strTitle = FUN_1405c2690(CStringW(L"s_partydps_titlebar"), CBattleRecordManager::FUN_140a04bc0(m_nMode));
    m_30->Invoke("setTitle", strTitle);
    m_30->Invoke("setAscendingMeterValue", m_nMode == 6);
}

#ifndef MS2_HOOK_DLL
// @0x141a7b540
void UIPartyDPSDialog::FUN_141a7b540()
{
    if (m_30.IsNull() == 0)
    {
        CStringW strTime = CBattleRecordManager::GetInstance()->FUN_140a04b00(m_nGroup);
        m_30->Invoke("setTime", strTime);
        ATL::CAtlArray<MS2Ptr<CPartyMember> >& members = FUN_1409670d0()->FUN_14162ba30();
        if (members.IsEmpty() == 0)
        {
            m_members.clear();
            for (unsigned i = 0; i < members.GetCount(); i++)
            {
                CPartyMember* pMember = members[i].get();
                if (pMember != 0)
                    m_members.push_back(MS2Ptr<CPartyMember>(pMember));
            }
            s_nPdSortMode = m_nMode;
            std::sort(m_members.begin(), m_members.end(), FUN_141a7c2a0);
            MS2Ptr<CPartyMember> spLast = m_members[m_members.size() - 1];
            if (spLast.get() != 0)
            {
                double dBottom = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(m_nGroup, spLast->FUN_141637bb0(), m_nMode));
                static_cast<Unk_PdScript*>(m_30.operator->())->FUN_140e06cc0("setBottomMeterValue", dBottom);
            }
            for (unsigned i = 0; i < m_members.size(); i++)
            {
                MS2Ptr<CPartyMember> spMember = m_members[i];
                if (i < 10)
                {
                    ASObj obj(2);
                    if (FUN_141a7b1a0(obj, spMember.get(), i + 1) != 0)
                        m_30->Invoke("UpdateMember", Scaleform::GFx::Value(obj.FUN_1422bb870()));
                }
                PCBase* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pMe != 0)
                {
                    __int64 nMyId = pMe->FUN_141656a80();
                    if (nMyId == spMember->user.m_8)
                    {
                        ASObj objMy(2);
                        if (FUN_141a7b1a0(objMy, spMember.get(), i + 1) != 0)
                            m_30->Invoke("SetMyRank", Scaleform::GFx::Value(objMy.FUN_1422bb870()));
                    }
                }
            }
        }
    }
}
#endif

// @0x141a7bb70
void UIPartyDPSDialog::FUN_141a7bb70()
{
    if (m_30.IsNull())
        return;
    int nCount = FUN_1409670d0()->FUN_14162af00();
    if (nCount < 10)
        m_30->Invoke("RemoveMember");
}

// @0x141a7bbf0
void UIPartyDPSDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x141a7bc10
void UIPartyDPSDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_tick.Init();
    CBattleRecordManager::GetInstance()->FUN_140a03f60(m_nGroup);
    FUN_141a7b3c0();
    FUN_141a7b540();
}

// MS2-FUNCTIONAL: same body as UIChaosDPSDialog::vfunc_28 (register / stack allocation)
// @0x141a7bc70
int UIPartyDPSDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnCloseDialog", szMethod) == 0)
    {
        CBattleRecordManager::GetInstance()->FUN_140a03fe0(m_nGroup);
        vfunc_67();
        return 1;
    }
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onReset", szMethod) == 0)
    {
        CBattleRecordManager::GetInstance()->FUN_140a03fa0(m_nGroup);
        return 1;
    }
    if (_stricmp("onNotice", szMethod) == 0)
    {
        CMsTime kNow(GetServerTime());
        int nSecond = kNow.GetSecond();
        int nMinute = kNow.GetMinute();
        int nHour = kNow.GetHour();
        CStringW strHistory = FUN_140c2fcc0(CStringW(L"s_partydps_notice_history_prefix"), nHour, nMinute, nSecond, CBattleRecordManager::FUN_140a04bc0(m_nMode));
        CStringW strRow = FUN_14028b8e0(L"s_partydps_notice_history_row");
        for (unsigned i = 0; i < m_members.size() && i <= 9; i++)
        {
            MS2Ptr<CPartyMember> spMember = m_members[i];
            strHistory.Append(StringFormat((const wchar_t*)strRow, i + 1, spMember->user.FUN_1408f19e0(),
                CBattleRecordManager::GetInstance()->FUN_140a04830(m_nGroup, spMember->FUN_141637bb0(), m_nMode)));
        }
        int nNow = GetTickCountMs2();
        int nTime = CBattleRecordManager::GetInstance()->FUN_140a04060(m_nGroup);
        nTime = nNow - nTime;
        CStringW strTotal;
        FUN_141b70810(nTime, strTotal);
        strHistory.Append(FUN_1405c2690(CStringW(L"s_partydps_notice_history_total_time"), strTotal));
        Unk_PdChat kChat;
        kChat.kind = 7;
        kChat.message = strHistory;
        FUN_141276f80(kChat);
        return 1;
    }
    if (_stricmp("onTextToggle", szMethod) == 0)
    {
        m_nMode = m_nMode + 1;
        if (6 < m_nMode)
            m_nMode = 0;
        FUN_141a7b3c0();
        return 1;
    }
    return 0;
}

// @0x141a7c210
void UIPartyDPSDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (!FUN_1409670d0()->FUN_14162ab20())
    {
        vfunc_67();
        return;
    }
    if (m_30.IsNull() == 0 && m_tick.Check(100) != 0)
        FUN_141a7b540();
}

// Orders the ranking: descending meter value (ascending for mode 6).
#ifndef MS2_HOOK_DLL
// @0x141a7c2a0
bool FUN_141a7c2a0(MS2Ptr<CPartyMember> spA, MS2Ptr<CPartyMember> spB)
{
    double dA = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(1, spA->FUN_141637bb0(), s_nPdSortMode));
    double dB = FUN_1407184e0(CBattleRecordManager::GetInstance()->FUN_140a04260(1, spB->FUN_141637bb0(), s_nPdSortMode));
    bool bLess;
    if (s_nPdSortMode == 6)
        bLess = dA < dB;
    else
        bLess = dB < dA;
    return bLess;
}
#endif

// @0x141a7c4b0
int UIPartyDPSDialog::vfunc_48()
{
    return 0x4e8c;
}

// ======== UIPerformanceDialog ========

// @0x141a7c4c0
UIPerformanceDialog::UIPerformanceDialog()
{
    m_80 = 1;
    m_88 = 0;
    FUN_141925e70(0, 1);
}

// @0x141a7c560
UIPerformanceDialog::~UIPerformanceDialog()
{
}

// @0x141a7c5b0
CString UIPerformanceDialog::vfunc_1()
{
    return "PerformanceDialog";
}

// @0x141a7c600
void UIPerformanceDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141923680(1);
    m_text = GetChild<ASTextField>("m_text");
}

// @0x141a7c6a0
void UIPerformanceDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_text = 0;
}

// @0x141a7c6e0
void UIPerformanceDialog::vfunc_72()
{
    if ((ASTextField*)m_text != 0)
    {
        unsigned int nDraw = FUN_14086d260()->FUN_141473460();
        float fFps = FUN_14086d260()->FUN_141473210();
        m_text->FUN_1422c4c80(StringFormat("{0:0.1f}({1})", fFps, nDraw));
    }
}

// @0x141a7cae0
int UIPerformanceDialog::vfunc_48()
{
    return 0x4e7d;
}
