// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIReportDialog (class name "ReportDialog", UI type 0x4e86,
// 0x210 bytes) is the form in which a player reports a character, a chat line, a wall poster, a design item, a real
// estate page or a pet. The swf calls "onReport" with the category check boxes and a text; the dialog asks for a
// confirmation (the box answers through OnMessage), then sends packet 0x52 and blocks the reported target locally.
// MS2-UNIT: ?\uireportdialog.cpp
// MS2-RANGE: 0x14011bde0-0x14011bfb0 .text$di
// MS2-RANGE: 0x141ab8920-0x141aba6a0 .text$mn
// MS2-RANGE: 0x142cc1e00-0x142cc1ed0 .text$yd
// MS2-PIN: ??_GUIReportDialog@@UEAAPEAXI@Z 0x141aba530
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uireportdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uireportdialog.h"

#include <atlcoll.h>

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static CString s_strReportClose("System_ReportClose");
static CString s_strReportOpen("System_ReportOpen");
#include "ms2/placeholder/header_statics_a.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released
__int64 FUN_140869440();                                        // the server time
void FUN_141275260(int nStringId, int nA, int nB);              // system message
CStringW GetStringCommon(int nStringId);                          // string table text by id
CStringW FUN_1409eec40(int nStringId);                          // string table text by id
void FUN_140d73aa0(CStringW strText, int nType, void* pListener, CStringW strTag);   // open a message box
void FUN_14028cd00(const CStringW& strText, CAtlArray<CStringW>& arrOut, const wchar_t* pszSep, int nMax);   // split
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);    // equals
size_t FUN_14015a000(CAtlArray<CStringW>& arr);                 // element count
void FUN_14151f200();
void FUN_140710590(COutPacket& packet);                         // send

// The notification posted for a freshly blocked design item (the class is built in uitencentuserreportdialog.cpp).
struct Unk_ReportTarget { __int64 low; __int64 high; };
class NotifyObject : public CPtred { public: NotifyObject(); virtual ~NotifyObject(); };
class NotifyBlindTarget : public NotifyObject
{
public:
    NotifyBlindTarget(const int& kind, const Unk_ReportTarget& target);     // 0x140ede4e0
private:
    int m_kind;
    Unk_ReportTarget m_target;
};
class Unk_ReportNotifyManager { public: void FUN_140da4fe0(MS2Ptr<NotifyObject>); };
Unk_ReportNotifyManager* FUN_140939a10();

class Unk_ReportBlindManager
{
public:
    bool FUN_140a25950(int nKind, __int64 nId);
    bool FUN_140a25730(int nKind, CStringW strName);
};
Unk_ReportBlindManager* FUN_1409c1730();
CUgcManager* FUN_14052d220();
CBuddyManager* FUN_14097a780();

// ---- the report form ---------------------------------------------------------------------------------------------------

// @0x141ab8920
UIReportDialog::UIReportDialog()
{
    FUN_141924170(1);
    FUN_141ab9890();
    m_c8 = s_strReportOpen;
    m_d0 = s_strReportClose;
}

// @0x141ab8a70
UIReportDialog::~UIReportDialog()
{
}

// @0x141ab8b40
CString UIReportDialog::GetTypeName()
{
    return "ReportDialog";
}
MS2_REPLACE_METHOD(0x141AB8B40, UIReportDialog, GetTypeName, 61, 0x659308F6);

// Tells the swf which kind of target is reported ("OnSelectCharacter", ...) and the names to show.
// @0x141ab8b90
// MS2-FUNCTIONAL: temp/string copy order differs from the exe (693 vs 696 bytes)
void UIReportDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        CStringW strMode;
        CStringW strExtra;
        if (m_nKind == 1)
            strMode = L"OnSelectCharacter";
        else if (m_nKind == 2)
            strMode = L"OnSelectChatting";
        else if (m_nKind == 3)
            strMode = L"OnSelectWallPoster";
        else if (m_nKind == 4)
        {
            strMode = L"OnSelectDesignItem";
            strExtra = m_strItem;
        }
        else if (m_nKind == 5)
            strMode = L"OnSelectRealStatePage";
        else
        {
            if (m_nKind != 6)
                return;
            strMode = L"OnSelectPet";
            strExtra = m_strPet;
        }
        m_30->FUN_1412e80d0("SetMode", strMode, m_strTarget, strExtra);
        m_178 = FUN_140869440();
    }
}

// @0x141ab8e50
void UIReportDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
}
MS2_REPLACE_METHOD(0x141AB8E50, UIReportDialog, OnLoadComplete, 24, 0x65666F60);

// @0x141ab8e70
void UIReportDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x141AB8E70, UIReportDialog, vfunc_67, 24, 0xB6EABBCC);

// @0x141ab8e90
int UIReportDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141AB8E90, UIReportDialog, vfunc_13, 37, 0xD3DCAA5D);

// The confirmation box answers "report" / "reportAndBan" with "<tag>,..." as its tag.
// @0x141ab8ec0
// MS2-FUNCTIONAL: temp/frame layout differs from the exe
int UIReportDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() != 0)
        return 0;
    if (dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        FUN_14151f200();
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (nResult == 0)
        {
            CAtlArray<CStringW> arrTag;
            FUN_14028cd00(strTag, arrTag, L",", 2);
            if (FUN_14015a000(arrTag) == 1)
            {
                if (FUN_1403b3c40(strTag, L"report") == 0)
                {
                    if (FUN_1403b3c40(strTag, L"reportAndBan") != 0)
                    {
                        if (FUN_141ab9d70(m_strMethod, m_nFlags, m_strText) == true)
                        {
                            FUN_141aba110(m_strMethod, m_nFlags);
                            vfunc_67();
                        }
                        else
                        {
                            FUN_140d73aa0(GetStringCommon(0x8ac), 0, 0, CStringW(L""));
                        }
                    }
                }
                else
                {
                    if (FUN_141ab9d70(m_strMethod, m_nFlags, m_strText) == true)
                        vfunc_67();
                    else
                        FUN_140d73aa0(GetStringCommon(0x8ac), 0, 0, CStringW(L""));
                }
            }
        }
    }
    return 1;
}

// @0x141ab9350
// MS2-FUNCTIONAL: temp/frame layout differs from the exe
int UIReportDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onReport", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CString strMethod = data.FUN_1422b8d30();
            int nMode = data.FUN_1422b8a10();
            CStringW strText = data.FUN_1422b8f40();
            bool bCategory1 = data.FUN_1422b8a90();
            bool bCategory2 = data.FUN_1422b8a90();
            bool bCategory3 = data.FUN_1422b8a90();
            bool bCategory4 = data.FUN_1422b8a90();
            bool bCategory5 = data.FUN_1422b8a90();
            unsigned int nFlags = bCategory1 != false;
            if (bCategory2 != false)
                nFlags = nFlags | 2;
            if (bCategory3 != false)
                nFlags = nFlags | 4;
            if (bCategory4 != false)
                nFlags = nFlags | 8;
            if (bCategory5 != false)
                nFlags = nFlags | 0x80;
            if (nFlags == 0)
            {
                FUN_141275260(0x8a5, 1, 1);
                return 1;
            }
            if (strText.GetLength() < 1)
            {
                FUN_141275260(0x8a4, 1, 1);
                return 1;
            }
            m_strMethod = strMethod;
            m_nFlags = nFlags;
            m_strText = strText;
            if (nMode == 1)
            {
                FUN_140d73aa0(FUN_1409eec40(0x8a7), 1, static_cast<IMessageListener*>(this), CStringW(L"report"));
            }
            else
            {
                CStringW strAsk = FUN_1409eec40(0x8a9);
                if (m_strMethod.CompareNoCase("OnSelectCharacter") == 0
                    || m_strMethod.CompareNoCase("OnSelectChatting") == 0
                    || m_strMethod.CompareNoCase("OnSelectPet") == 0)
                {
                    strAsk = FUN_1409eec40(0x8a8);
                }
                FUN_140d73aa0(strAsk, 1, static_cast<IMessageListener*>(this), CStringW(L"reportAndBan"));
            }
        }
        return 1;
    }
    else
    {
        if (_stricmp("OnCancel", szMethod) == 0)
        {
            vfunc_67();
            return 1;
        }
        return 0;
    }
}

// @0x141ab9890
void UIReportDialog::FUN_141ab9890()
{
    m_178 = 0;
    m_nPosterId = 0;
    m_strPosterUrl = L"";
    m_nBannerId = 0;
    m_nItemId = 0;
    m_strItem = L"";
    m_nItemFlag = 0;
    m_strChat = L"";
    m_strTarget = L"";
    m_nCharacterId = 0;
    m_strPet = L"";
    m_nKind = 0;
    m_strMethod = L"";
    m_strText = L"";
    m_nFlags = 0;
    m_nPageArg1 = 0;
    m_nPageArg2 = 0;
    m_key.Reset();
}
MS2_REPLACE_METHOD(0x141AB9890, UIReportDialog, FUN_141ab9890, 376, 0x749B0024);

// @0x141ab9a10
void UIReportDialog::FUN_141ab9a10(__int64 nPosterId, int nBannerId, const CString& strUrl, const CStringW& strTarget)
{
    FUN_141ab9890();
    m_nBannerId = nBannerId;
    m_nPosterId = nPosterId;
    m_strPosterUrl = strUrl;
    m_strTarget = strTarget;
    m_nKind = 3;
}
MS2_REPLACE_METHOD(0x141AB9A10, UIReportDialog, FUN_141ab9a10, 136, 0xF06431EF);

// @0x141ab9aa0
void UIReportDialog::FUN_141ab9aa0(__int64 nCharacterId, const CStringW& strTarget)
{
    FUN_141ab9890();
    m_strTarget = strTarget;
    m_nCharacterId = nCharacterId;
    m_nKind = 1;
}
MS2_REPLACE_METHOD(0x141AB9AA0, UIReportDialog, FUN_141ab9aa0, 91, 0xB1AC1FF9);

// @0x141ab9b10
void UIReportDialog::FUN_141ab9b10(const CStringW& strTarget, const CStringW& strChat)
{
    FUN_141ab9890();
    m_strTarget = strTarget;
    m_strChat = strChat;
    m_nKind = 2;
}
MS2_REPLACE_METHOD(0x141AB9B10, UIReportDialog, FUN_141ab9b10, 99, 0xB82CC288);

// @0x141ab9b80
void UIReportDialog::FUN_141ab9b80(const Unk_MeratProductKey& key, __int64 nItemId, CStringW strItem, CStringW strTarget, int nFlag)
{
    FUN_141ab9890();
    m_key = key;
    m_nItemId = nItemId;
    m_strItem = strItem;
    m_strTarget = strTarget;
    m_nKind = 4;
    m_nItemFlag = nFlag;
}

// @0x141ab9c50
void UIReportDialog::FUN_141ab9c50(__int64 nPageId, const CStringW& strTarget, int nArg1, int nArg2)
{
    FUN_141ab9890();
    m_strTarget = strTarget;
    m_nPageArg1 = nArg1;
    m_nPageId = nPageId;
    m_nPageArg2 = nArg2;
    m_nKind = 5;
}
MS2_REPLACE_METHOD(0x141AB9C50, UIReportDialog, FUN_141ab9c50, 126, 0x0525F9F9);

// @0x141ab9ce0
void UIReportDialog::FUN_141ab9ce0(CStringW strTarget, CStringW strPet)
{
    FUN_141ab9890();
    m_strTarget = strTarget;
    m_strPet = strPet;
    m_nKind = 6;
}

// Sends the report (packet 0x52): the target name, the text, then the kind-specific target.
// @0x141ab9d70
// MS2-FUNCTIONAL: temp/frame layout differs from the exe
bool UIReportDialog::FUN_141ab9d70(CString strMethod, unsigned int nFlags, CStringW strText)
{
    int nLength = strText.GetLength();
    if (nLength < 0xfa1 && 0 < nLength)
    {
        if (FUN_141aba4b0(strMethod) == false)
            return false;
        COutPacket packet(0x52, 0);
        packet.vfunc_o10_8(m_strTarget);
        packet.vfunc_o10_8(strText);
        if (strMethod.CompareNoCase("OnSelectCharacter") == 0)
        {
            packet.vfunc_o10_1(0);
            packet.vfunc_o10_3(nFlags);
        }
        else if (strMethod.CompareNoCase("OnSelectChatting") == 0)
        {
            packet.vfunc_o10_1(1);
            packet.vfunc_o10_3(nFlags);
            packet.vfunc_o10_8(m_strChat);
        }
        else if (strMethod.CompareNoCase("OnSelectWallPoster") == 0)
        {
            packet.vfunc_o10_1(2);
            packet.vfunc_o10_3(nFlags);
            packet.vfunc_o10_4(m_nPosterId);
            packet.vfunc_o10_6(m_strPosterUrl);
        }
        else if (strMethod.CompareNoCase("OnSelectDesignItem") == 0)
        {
            packet.vfunc_o10_1(3);
            packet.vfunc_o10_3(nFlags);
            packet.vfunc_o10_4(m_nItemId);
        }
        else if (strMethod.CompareNoCase("OnSelectRealStateItem") == 0)
        {
            packet.vfunc_o10_1(4);
            packet.vfunc_o10_3(nFlags);
            packet.vfunc_o10_4(m_nPageId);
            packet.vfunc_o10_3(m_nPageArg1);
            packet.vfunc_o10_3(m_nPageArg2);
        }
        else
        {
            if (strMethod.CompareNoCase("OnSelectPet") != 0)
                return false;
            packet.vfunc_o10_1(7);
            packet.vfunc_o10_3(nFlags);
            packet.vfunc_o10_8(m_strPet);
        }
        FUN_140710590(packet);
        return true;
    }
    return false;
}

// After a report went out: block the reported target (friend list entry, blind list, banner, notification).
// @0x141aba110
// MS2-FUNCTIONAL: temp/frame layout differs from the exe
void UIReportDialog::FUN_141aba110(CString strMethod, unsigned int nFlags)
{
    if (FUN_141aba4b0(strMethod) == false)
        return;
    if (strMethod.CompareNoCase("OnSelectCharacter") == 0
        || strMethod.CompareNoCase("OnSelectChatting") == 0
        || strMethod.CompareNoCase("OnSelectPet") == 0)
    {
        __int64 nBuddyId = 0;
        bool bRequest = true;
        CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4880(m_nCharacterId);
        if (spBuddy.get() != 0)
        {
            nBuddyId = spBuddy->FUN_1401cc2f0();
            if (spBuddy->FUN_1401cc5b0() != 0)
                bRequest = false;
        }
        spBuddy = 0;
        if (bRequest)
        {
            Unk_BuddyRequest request;
            request.protocol = 5;
            request.name = m_strTarget;
            request.memo = GetStringCommon(0x8af);
            request.id = nBuddyId;
            FUN_14097a780()->FUN_140ae4820(request);
        }
    }
    else if (strMethod.CompareNoCase("OnSelectWallPoster") == 0)
    {
        FUN_1409c1730()->FUN_140a25950(2, m_nPosterId);
        FUN_14052d220()->FUN_1418885b0(m_nBannerId);
    }
    else if (strMethod.CompareNoCase("OnSelectDesignItem") == 0)
    {
        FUN_1409c1730()->FUN_140a25950(3, m_nItemId);
        int nKind = 3;
        FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyBlindTarget(nKind, reinterpret_cast<const Unk_ReportTarget&>(m_key))));
    }
    else if (strMethod.CompareNoCase("OnSelectRealStatePage") == 0)
    {
        FUN_1409c1730()->FUN_140a25730(4, m_strTarget);
    }
}

// The target name must be 1..24 characters (16 for a real estate page).
// @0x141aba4b0
// MS2-FUNCTIONAL: return-value branch layout differs from the exe
bool UIReportDialog::FUN_141aba4b0(const CString& strMethod)
{
    int nMax = 0x18;
    if (strMethod.CompareNoCase("OnSelectRealStatePage") == 0)
        nMax = 0x10;
    if (m_strTarget.GetLength() != 0)
    {
        if (m_strTarget.GetLength() <= nMax)
            return true;
    }
    return false;
}

MS2_EMIT_CRT_MEMMOVE_S();
