// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The story quest kinds' overrides and CStringTable (the
// string.xml tables, the lookups every UI uses), plus the ATL glue of its caches.
// MS2-UNIT: client\ms2\stringtable.cpp
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_7CStringTable@@6B?$TSingleton@VCStringTable@@@@@ 0x142f80490
// MS2-PIN: ??_7CStringTable@@6B?$CValidData@VCStringTable@@@@@ 0x142f804a0
// MS2-PIN: ??_7CGFxLanguage@@6B?$TSingleton@VCGFxLanguage@@@@@ 0x142f804c0
// MS2-RANGE: 0x14180f030-0x14181cf50 .text$mn
// MS2-RANGE: 0x14010cf80-0x14010d120 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCQuestManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x1418106b0 ; unique
// MS2-PIN: ??_GCEpicQuest@@UEAAPEAXI@Z 0x1418107b0 ; prop
// MS2-PIN: ??_GCEventQuest@@UEAAPEAXI@Z 0x1418107f0 ; prop
// MS2-PIN: ??_GCFieldQuest@@UEAAPEAXI@Z 0x141810830 ; prop
// MS2-PIN: ??_GCGuildQuest@@UEAAPEAXI@Z 0x141810870 ; prop
// MS2-PIN: ??_GCStoryQuest@@UEAAPEAXI@Z 0x1418108b0 ; prop
// MS2-PIN: ??_GCWorldQuest@@UEAAPEAXI@Z 0x1418108f0 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCQuestManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141810990 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCQuestManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x1418109f0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCQuestManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141810a70 ; unique
// MS2-PIN: memmove_s 0x141810ad0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCDesc@CStringTable@@@@QEAA@$$QEAV0@@Z 0x141816440 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCLevelDesc@CStringTable@@@@QEAA@PEAVCLevelDesc@CStringTable@@@Z 0x141816500 ; prop
// MS2-PIN: ??0CDesc@CStringTable@@QEAA@XZ 0x141816660 ; prop
// MS2-PIN: ??0CLevelDesc@CStringTable@@QEAA@XZ 0x1418166b0 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$MS2Ptr@VCStringCache@CStringTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCStringCache@CStringTable@@@@@3@@ATL@@IEAA@H@Z 0x1418168e0 ; unique
// MS2-PIN: ??1CNode@?$CRBTree@GV?$MS2Ptr@VCDesc@CStringTable@@@@V?$CElementTraits@G@ATL@@V?$CElementTraits@V?$MS2Ptr@VCDesc@CStringTable@@@@@3@@ATL@@QEAA@XZ 0x141816e50 ; prop
// MS2-PIN: ??1CNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VDescValue@CDesc@CStringTable@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VDescValue@CDesc@CStringTable@@@@@2@@ATL@@QEAA@XZ 0x141816e70 ; prop
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCLevelDesc@CStringTable@@@@QEAAAEAV1@PEAVCLevelDesc@CStringTable@@@Z 0x1418170b0 ; prop
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCStringCache@CStringTable@@@@QEAAAEAV1@PEAVCStringCache@CStringTable@@@Z 0x141817160 ; prop
// MS2-PIN: ??C?$MS2Ptr@VCLevelDesc@CStringTable@@@@QEBAPEAVCLevelDesc@CStringTable@@XZ 0x141817270 ; unique
// MS2-PIN: ??_ECGFxLanguage@@W7EAAPEAXI@Z 0x141817290 ; unique
// MS2-PIN: ??_ECStringTable@@W7EAAPEAXI@Z 0x14181729c ; prop
// MS2-PIN: ??_GCNode@?$CRBTree@GV?$MS2Ptr@VCDesc@CStringTable@@@@V?$CElementTraits@G@ATL@@V?$CElementTraits@V?$MS2Ptr@VCDesc@CStringTable@@@@@3@@ATL@@QEAAPEAXI@Z 0x1418174f0 ; unique
// MS2-PIN: ??_GCNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VDescValue@CDesc@CStringTable@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VDescValue@CDesc@CStringTable@@@@@2@@ATL@@QEAAPEAXI@Z 0x141817530 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCDesc@CStringTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCDesc@CStringTable@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x141818610 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCLevelDesc@CStringTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLevelDesc@CStringTable@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x141818700 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCStringCache@CStringTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCStringCache@CStringTable@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1418187f0 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$MS2Ptr@VCStringCache@CStringTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCStringCache@CStringTable@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x1418188e0 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@HV?$MS2Ptr@VCStringCache@CStringTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCStringCache@CStringTable@@@@@3@@ATL@@QEBA_NXZ 0x1418191c0 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$MS2Ptr@VCDesc@CStringTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCDesc@CStringTable@@@@@3@@ATL@@QEBA_NHAEAV?$MS2Ptr@VCDesc@CStringTable@@@@@Z 0x141819600 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$MS2Ptr@VCLevelDesc@CStringTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCLevelDesc@CStringTable@@@@@3@@ATL@@QEBA_NHAEAV?$MS2Ptr@VCLevelDesc@CStringTable@@@@@Z 0x141819670 ; prop
// MS2-PIN: ?RemoveAll@?$CRBTree@GV?$MS2Ptr@VCDesc@CStringTable@@@@V?$CElementTraits@G@ATL@@V?$CElementTraits@V?$MS2Ptr@VCDesc@CStringTable@@@@@3@@ATL@@QEAAXXZ 0x14181b7f0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stringtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cgfxlanguage.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include <typeinfo>
#include <vector>
#include <assert.h>
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/placeholder/questkinds.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/chapterbooktable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uialliancequestdialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static UICommon::CMyPCKeyInputController s_keyController;

// ---- the quest kinds ----------------------------------------------------------------------------------------------

// Services of the exe, bound by their FUN_<va> names.
CStringTable* FUN_1401a9d70();
bool FUN_14064d4e0(const MS2Ptr<CQuestData>&);
void* FUN_140166410();
bool FUN_14036d570(void*, int);
void* FUN_1408e57f0();
int FUN_1422b9e00(void*);
int FUN_14074b030(CQuestData*);
int FUN_14074b840(int);
int FUN_14074b950(int);
int FUN_1418fd280();
CStringW FUN_1416e4df0(int);
CStringW FUN_1416e7fb0(int);
CStringW FUN_1405c2690(CStringW, const CStringW&);
CStringW FUN_1401e8510(const wchar_t*, const CStringW&);
void FUN_1412751f0(const CStringW&, int, int);
CStringW FUN_14028b8e0(const CStringW& str);
CQuestManager* FUN_140764020();
UIRewardNotify* FUN_140938cd0(int);
UIFameContentsNotify* FUN_140e77d80(int);
CChapterBookTable* FUN_140e0a9f0();
WorldService* FUN_1403ed2d0();
MS2Ptr<CMsgBoxData> FUN_140d73d20(int, CStringW, void*, CStringW);
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);

class Unk_StTextFilter { public: void FUN_1416fb340(CStringW& strText); void FUN_1416fb380(CStringW& strText); void FUN_1416fbf60(CStringW& strText, unsigned short nId); };
Unk_StTextFilter* FUN_1403b4750();

class Unk_QmTalkScript;
class Unk_QmTalkScriptPtr {
public:
    Unk_QmTalkScriptPtr(const Unk_QmTalkScriptPtr& o);  // 0x140859bc0
    ~Unk_QmTalkScriptPtr();                             // 0x14078f140
    bool IsNull() const;                                // 0x14085a420
    Unk_QmTalkScript* FUN_14078f3a0() const;            // get
private:
    void* m_0;
    Unk_QmTalkScript* m_p;
};
Unk_QmTalkScriptPtr FUN_1408564b0(int questId, int n);
class Unk_StTalkManager { public: int FUN_141b213f0(Unk_QmTalkScriptPtr script, int npcId, int mode, int n); };
Unk_StTalkManager* FUN_140967100();

class Unk_StRewardOtherDialog : public UIDialog { public: void FUN_1419f6a70(int nType, CStringW strText, int nTime); };
Unk_StRewardOtherDialog* FUN_140e01890(int nUiId);

// The UI manager and the dialog getter (GetDialog<T> instantiations of this unit).
class Unk_StUiManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_StUiManager* FUN_1403ed2b0();

class UIChapterBook : public UIDialog
{
public:
    void FUN_140e0a850(int nChapter);
    void FUN_140e0a890(int nChapter);
};

// @0x141810510
UIAllianceQuestDialog* FUN_141810510(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIAllianceQuestDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x1418105b0
UIChapterBook* FUN_1418105b0(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIChapterBook*>((UIObject*)p);
    }
    return 0;
}

// @0x14180f030
CStoryQuest::CStoryQuest()
{
    m_78 = 1;
    m_7c = 0;
}

// @0x14180f090
CStoryQuest::~CStoryQuest()
{
}

// @0x14180f0d0
void CStoryQuest::DecodeStart(CInPacket& packet)
{
    if (FUN_14036d570(FUN_140166410(), 100))
    {
        int nChapter = FUN_140e0a9f0()->FindIdByPrologue(FUN_140bfc580());
        if (nChapter != 0)
        {
            UIRewardNotify* pNotify = FUN_140938cd0(0x4e5d);
            if (pNotify)
                pNotify->FUN_141abf1f0();
            UIChapterBook* pBook = FUN_1418105b0(0x4f37);
            if (pBook)
                pBook->FUN_140e0a850(nChapter);
        }
    }
    if (FUN_14074b840(FUN_140bfc580()) != 0)
    {
        if (FUN_1422b9e00(FUN_1408e57f0()) == 0x6200031)
        {
            CStringW strMsg = FUN_1405c2690(CStringW(L"s_quest_redirect_accept"), FUN_1416e4df0(FUN_140bfc580()));
            FUN_1412751f0(strMsg, 3, 0);
        }
    }
    if (m_data->m_2f0.m_0 == 3)
        m_7c = 3;
    CQuest::DecodeStart(packet);
}

// @0x14180f290
void CStoryQuest::DecodeProgress(CInPacket& packet)
{
    CQuest::DecodeProgress(packet);
}

// @0x14180f2c0
void CStoryQuest::Complete(CInPacket& packet)
{
    if (m_data->m_2d0.m_id != -1)
    {
        Unk_StRewardOtherDialog* pDlg = FUN_140e01890(0x4e4c);
        if (pDlg)
        {
            CStringW strText = FUN_1405c2690(CStringW(L"s_quest_complete_ui_effect"), FUN_1416e7fb0(m_data->m_28));
            pDlg->FUN_1419f6a70(m_data->m_2d0.m_id, strText, 3000);
        }
    }
    if (FUN_14036d570(FUN_140166410(), 100))
    {
        int nChapter = FUN_140764020()->FUN_1416d0f60(FUN_140bfc580());
        if (nChapter != 0)
        {
            UIRewardNotify* pNotify = FUN_140938cd0(0x4e5d);
            if (pNotify)
                pNotify->FUN_141abf1f0();
            UIChapterBook* pBook = FUN_1418105b0(0x4f37);
            if (pBook)
                pBook->FUN_140e0a890(nChapter);
        }
    }
    if (FUN_14074b950(FUN_140bfc580()) != 0)
    {
        if (FUN_1422b9e00(FUN_1408e57f0()) == 0x6200031)
        {
            CStringW strMsg = FUN_1405c2690(CStringW(L"s_quest_redirect_complete"), FUN_1416e4df0(FUN_140bfc580()));
            FUN_1412751f0(strMsg, 3, 0);
        }
    }
    if (m_data->m_2f0.m_0 == 4)
        m_7c = 4;
    CQuest::Complete(packet);
}

// The dispatch confirmation the story quest raises when it is accepted from another channel.
// MS2-FUNCTIONAL: the exe allocates the dispatch box argument strings in a different frame order (EH state map differs).
// @0x14180f5c0
void CStoryQuest::FUN_140d73960()
{
    CQuest::FUN_140d73960();
    if (m_7c != 0)
    {
        if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001d)
        {
            CStringW strWho = FUN_1401a9d70()->FUN_141811980(0x47, m_data->m_2f0.m_c);
            CStringW strText = FUN_1401e8510((const wchar_t*)strWho, FUN_1401a9d70()->FUN_141811980(3, m_data->m_2f0.m_4));
            FUN_1403b4750()->FUN_1416fb340(strText);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x28, CStringW(L""), 0, CStringW(strText));
            if (spBox.get() != 0)
            {
                spBox->FUN_140534050(FUN_14074b030(m_data.operator->()));
                spBox->FUN_140533ff0(m_7c);
                spBox->FUN_141a015d0(FUN_1403ed2d0()->FUN_141bd0d30());
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(FUN_140764020(), &CQuestManager::SendQuestMode20));
                spBox->FUN_141a01690(FUN_14028b8e0(CStringW(L"s_quest_dispatch_yes")), FUN_14028b8e0(CStringW(L"s_quest_dispatch_no")), CStringW(L""));
                FUN_140d73c60(spBox);
            }
            m_7c = 0;
        }
    }
}

// @0x14180fa50
void CStoryQuest::FUN_140d73950()
{
    m_78 = 1;
}

// @0x14180fa70
int CStoryQuest::FUN_140d73970()
{
    if (m_78 == 0)
        return 0;
    if (FUN_140d738c0() == 0)
        return 0;
    Unk_QmTalkScriptPtr script = FUN_1408564b0(FUN_140bfc580(), 300);
    if (script.IsNull())
        return 0;
    m_78 = 0;
    FUN_140967100()->FUN_141b213f0(script, m_data->m_2ec, 4, 0);
    return 1;
}

// @0x14180fbb0
void CStoryQuest::FUN_140d738e0()
{
    m_78 = 1;
    FUN_140d73970();
}

// @0x14180fbe0
int CStoryQuest::FUN_140d738c0()
{
    if (FUN_14180fc80() == 0)
        return 0;
    if (m_data->m_32c.m_0 != 1)
        return 0;
    return 1;
}

// @0x14180fc30
int CStoryQuest::FUN_140d738d0()
{
    if (FUN_14180fc80() == 0)
        return 0;
    if (m_data->m_32c.m_0 != 2)
        return 0;
    return 1;
}

// @0x14180fc80
int CStoryQuest::FUN_14180fc80()
{
    if (FUN_14064d4e0(m_data))
        return 0;
    if (m_data->m_32c.m_0 == 0)
        return 0;
    if (FUN_1407476d0() != 1)
        return 0;
    if (IsComplete() == 0)
        return 0;
    int nMap = m_data->m_32c.m_4;
    if (nMap != 0)
    {
        if (FUN_1403ed2d0()->FUN_141bd3060() != nMap)
            return 0;
        if (nMap == 62000000 && FUN_1418fd280() == 0)
            return 0;
    }
    if (m_data->m_32c.m_8 != 0)
    {
        if (FUN_140764020()->FUN_1416d0760() == 0)
            return 0;
    }
    return 1;
}

// @0x14180fda0
CEpicQuest::CEpicQuest() {}
// @0x14180fdf0
CEpicQuest::~CEpicQuest() {}
// @0x14180fe30
CWorldQuest::CWorldQuest() {}
// @0x14180fe80
CWorldQuest::~CWorldQuest() {}
// @0x14180fec0
CEventQuest::CEventQuest() {}
// @0x14180ff10
CEventQuest::~CEventQuest() {}
// @0x14180ff50
CGuildQuest::CGuildQuest() {}
// @0x14180ffa0
CGuildQuest::~CGuildQuest() {}
// @0x14180ffe0
CFieldQuest::CFieldQuest() {}
// @0x141810030
CFieldQuest::~CFieldQuest() {}

// @0x141810070
int CFieldQuest::GetTrackingState()
{
    return FUN_140744b90(FUN_1403ed2d0()->FUN_141bd3060());
}

// @0x1418100c0
unsigned char CFieldQuest::GetFlag()
{
    if (!CQuest::GetFlag())
        return 0;
    if (IsActive() == 0)
        return 0;
    if (IsComplete() != 0)
        return 0;
    return 1;
}

// @0x141810140
void CFieldQuest::Complete(CInPacket& packet)
{
    CStoryQuest::Complete(packet);
    UIFameContentsNotify* pNotify = FUN_140e77d80(0x4f5a);
    if (pNotify)
        pNotify->FUN_141ac26a0(FUN_140bfc580());
}

// @0x1418101a0
int CFieldQuest::FUN_140d738d0()
{
    if (IsActive() == 0)
        return 0;
    if (IsComplete() == 0)
        return 0;
    return 1;
}

// @0x141810210
void CAllianceQuest::DecodeStart(CInPacket& packet)
{
    CStoryQuest::DecodeStart(packet);
    UIFameContentsNotify* pNotify = FUN_140e77d80(0x4f5a);
    if (pNotify)
        pNotify->FUN_141ac25b0(FUN_140bfc580());
    UIAllianceQuestDialog* pDlg = FUN_141810510(0x4f50);
    if (pDlg)
    {
        if (pDlg->FUN_140bf94e0(FUN_140bfc580()) != 0 && m_7c == 3)
            m_7c = 0;
    }
}

// @0x1418102b0
void CAllianceQuest::Complete(CInPacket& packet)
{
    CStoryQuest::Complete(packet);
    UIFameContentsNotify* pNotify = FUN_140e77d80(0x4f5a);
    if (pNotify)
        pNotify->FUN_141ac26a0(FUN_140bfc580());
    UIAllianceQuestDialog* pDlg = FUN_141810510(0x4f50);
    if (pDlg)
    {
        if (pDlg->FUN_140bf9530(FUN_140bfc580()) != 0 && m_7c == 4)
            m_7c = 0;
    }
}

// @0x141810350
unsigned char CAllianceQuest::GetFlag()
{
    if (!CQuest::GetFlag())
        return 0;
    if (IsActive() == 0)
        return 0;
    if (IsComplete() != 0)
        return 0;
    return 1;
}

// @0x141810970
int CStoryQuest::GetQuestType() { return 0xb; }
// @0x141810930
int CEpicQuest::GetQuestType() { return 0; }
// @0x141810980
int CWorldQuest::GetQuestType() { return 1; }
// @0x141810940
int CEventQuest::GetQuestType() { return 2; }
// @0x141810960
int CGuildQuest::GetQuestType() { return 6; }
// @0x141810950
int CFieldQuest::GetQuestType() { return 8; }

// ---- CStringTable ---------------------------------------------------------------------------------------------------

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CStringTable::s_bInit;
#endif
extern int DAT_143ae0fc0;                                           // debug switch: append the ids to the texts

// The xml helpers every table unit uses.
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
CString FUN_14071ae20(const CString& strFile);                      // path of a Table file
CString FUN_14016a5c0(const char* psz, int n);
CString FUN_140536a50(const char* szFormat, const CString& strArg);
unsigned FUN_14021c7c0(const CString& str);                         // the id of a string key
int FUN_1408731e0(Unk_140165cf0*, const char*, int&);
int FUN_1408733e0(Unk_140165cf0*, const char*, CString&);
int FUN_140873420(Unk_140165cf0*, const char*, CStringW&);
bool FUN_14028f710(Unk_140165cf0*);                                 // the element is usable
void FUN_14028fd90(Unk_140165cf0*, const char*, const char*, const char*, ATL::CAtlArray<void*>&);
bool FUN_140184310(const CString& str, const char* psz);            // str equals psz
unsigned char FUN_1401d1320(CCacheData*);
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& rOut, const wchar_t* pszSep);
CStringW FUN_14028de60(int nId);                                    // the text of a string id
void* FUN_14025e7a0();
void FUN_1422b09a0(void*);

// @0x1418178d0
void CStringTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CStringTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14181c6c0
void CStringTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x141810bf0
CStringTable::CStringTable()
    : m_caches(17, 0.75f, 0.25f, 2.25f, 10), m_itemDescs(17, 0.75f, 0.25f, 2.25f, 10),
      m_skillDescs(17, 0.75f, 0.25f, 2.25f, 10), m_levelDescs(17, 0.75f, 0.25f, 2.25f, 10),
      m_setItemNames(17, 0.75f, 0.25f, 2.25f, 10), m_ugcSetItemNames(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x141810e40
CStringTable::~CStringTable()
{
}

// @0x141815d50
CGFxLanguage::CGFxLanguage()
{
}

// @0x141816d90
CGFxLanguage::~CGFxLanguage()
{
}

// @0x141815de0
bool CGFxLanguage::LoadKorFlash(TiXmlDocument* pDoc)
{
    CString strPath = FUN_14071ae20("korFlash.xml");
    CCacheData::FUN_1401d1160(CString(strPath));
    return FUN_140166420()->FUN_1403974b0(pDoc, strPath, 0, true, false) ? true : false;
}

// @0x141815db0
void FUN_141815db0()
{
    FUN_1422b09a0(FUN_14025e7a0());
}

// @0x1418176e0
void CStringTable::CStringCache::FUN_1418176e0(CString strFile)
{
    CString strPath = FUN_14071ae20(strFile);
    MS2Ptr<CCacheData> spFile(new CCacheData);
    if (!spFile->FUN_1401d1160(CString(strPath)))
        return;
    m_files.AddTail(spFile);
}

// @0x141819280
int CStringTable::CStringCache::FUN_141819280()
{
    for (POSITION pos = m_files.GetHeadPosition(); pos; m_files.GetNext(pos))
    {
        MS2Ptr<CCacheData> spFile = m_files.GetAt(pos);
        if (spFile == 0)
            continue;
        if (FUN_1401d1320(spFile.operator->()))
            return 1;
    }
    return 0;
}

// The text of a tag; the first read of a text that carries a "$" marker runs it through the text filter.
// @0x141816a60
CStringTable::CDesc::DescValue::DescValue()
    : m_bPending(0)
{
}

// @0x141813a30
CStringW CStringTable::CDesc::FUN_141813a30(const CString& strTag)
{
    const ValueMap::CPair* pPair = m_values.Lookup(strTag);
    if (pPair != 0)
    {
        if (pPair->m_value->m_bPending != 0)
        {
            FUN_1403b4750()->FUN_1416fb380(pPair->m_value->m_strText);
            pPair->m_value->m_bPending = pPair->m_value->m_strText.Find(L"$", 0) != -1;
        }
        return pPair->m_value->m_strText;
    }
    return CStringW(L"");
}

// @0x141813b80
void CStringTable::CDesc::FUN_141813b80(const CString& strTag, const CStringW& strText)
{
    ValuePtr spValue(new DescValue);
    spValue->m_strText = strText;
    spValue->m_bPending = strText.Find(L"$", 0) != -1;
    m_values.SetAt(strTag, spValue);
}

#define MS2_XML_FORMAT_ERROR L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]"

// MS2-FUNCTIONAL: the literal-CString temporaries and the many xml-loader locals are laid out differently from the exe (precedent reactordata.cpp)
// @0x141810f70
bool CStringTable::Load()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("string.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, MS2_XML_FORMAT_ERROR, strPath);
        return false;
    }
    for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
    {
        if (FUN_14028f710(pKey))
        {
            int nId = 0;
            CString strName;
            CString strParser;
            CString strParserValue;
            FUN_1408731e0(pKey, "id", nId);
            FUN_1408733e0(pKey, "name", strName);
            FUN_1408733e0(pKey, "parser", strParser);
            FUN_1408733e0(pKey, "parserValue", strParserValue);
            CachePtr spCache(0);
            if (!m_caches.Lookup(nId, spCache))
            {
                spCache.AssignRaw(new CStringCache);
                spCache->m_strParser = strParser;
                spCache->m_strParserValue = strParserValue;
                m_caches.SetAt(nId, spCache);
            }
            spCache->FUN_1418176e0(FUN_140536a50("{0}.xml", strName));
            FUN_141813c80(CachePtr(spCache), CString(strParser), CString(strParserValue));
        }
    }
    for (POSITION pos = m_caches.GetStartPosition(); pos; m_caches.GetNext(pos))
    {
        int nTable = m_caches.GetKeyAt(pos);
        CachePtr spCache = m_caches.GetValueAt(pos);
        for (POSITION posStr = spCache->m_strings.GetHeadPosition(); posStr; spCache->m_strings.GetNext(posStr))
        {
            DWORD nStringId = spCache->m_strings.GetKeyAt(posStr);
            CStringW strText(spCache->m_strings.GetValueAt(posStr));
            if (strText.Find(L"$", 0) != -1)
            {
                FUN_1403b4750()->FUN_1416fb380(strText);
                spCache->m_strings.SetAt(nStringId, strText);
            }
        }
    }
    FUN_141814750(CString("korItemDescription.xml"), m_itemDescs, m_itemDescStamp);
    m_spAdditional.AssignRaw(new CStringCache);
    m_spAdditional->FUN_1418176e0(CString("stringAdditionalDescription.xml"));
    FUN_141814cf0(m_levelDescs, CachePtr(m_spAdditional));
    FUN_141814750(CString("stringSkillDescription.xml"), m_skillDescs, m_skillDescStamp);
    FUN_141814750(CString("SetItemName.xml"), m_setItemNames, m_setItemNameStamp);
    FUN_141814750(CString("UGCMapSetItemName.xml"), m_ugcSetItemNames, m_ugcSetItemNameStamp);
    SetInit(true);
    return true;
}

// @0x141811960
bool CStringTable::FUN_141811960()
{
    return Load();
}

// ---- the skill / item / player services the lookups reach -----------------------------------------------------------
class Unk_StSkillLevel : public CPtred { public: char m_pad_18[0x18]; CStringW m_strArgs; };   // +0x30 the format arguments
MS2_CHECK_OFFSET(Unk_StSkillLevel, m_strArgs, 0x30);
class Unk_StSkillRow : public CPtred { public: MS2Ptr<Unk_StSkillLevel> FUN_1407e90a0(unsigned short nLevel); };
class Unk_StEffectAttr : public CPtred { public: char m_pad_18[0x10]; CStringW m_strArgs; };   // +0x28 the format arguments
MS2_CHECK_OFFSET(Unk_StEffectAttr, m_strArgs, 0x28);
class Unk_StSkillTable
{
public:
    MS2Ptr<Unk_StSkillRow> FUN_1407ee1d0(int nSkillId);
    MS2Ptr<Unk_StEffectAttr> FUN_140aafef0(int nSkillId, unsigned short nLevel);
};
Unk_StSkillTable* FUN_1401958b0();
class Unk_StSkillSystem { public: CStringW FUN_141767e60(__int64 nId); };
class Unk_StPlayer { public: Unk_StSkillSystem* FUN_141523bc0(); MS2Ptr<CItem> FUN_141655b80(__int64 nItemUid); };
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

class UIClosetDialog : public UIDialog
{
public:
    static int FUN_141818950() { return 0x4f76; }           // the ui id
    CStringW FUN_140be1a00(const __int64& nId);
};

// @0x141815ed0
UIClosetDialog* FUN_141815ed0()
{
    Unk_StUiManager* pManager = FUN_1403ed2b0();
    if (pManager == 0)
        return 0;
    MS2Ptr<UIObject> p = pManager->FUN_141adcea0(UIClosetDialog::FUN_141818950());
    if (p.IsNull())
        return 0;
    return dynamic_cast<UIClosetDialog*>((UIObject*)p);
}

// @0x141811980
CStringW CStringTable::FUN_141811980(int nTable, int nId)
{
    CachePtr spCache(0);
    if (!m_caches.Lookup(nTable, spCache))
    {
        CheckInit();
        return CStringW(L"");
    }
    CStringW strText;
    {
        Unk_CriticalSectionLock lock(spCache->m_lock, 1);
        if (spCache->FUN_141819280() != 0)
        {
            if (FUN_141813c80(CachePtr(spCache), CString(spCache->m_strParser), CString(spCache->m_strParserValue)) == 0)
                return CStringW(L"");
        }
        spCache->m_strings.Lookup(nId, strText);
    }
    if (DAT_143ae0fc0 != 0)
    {
        switch (nTable)
        {
        case 7:
        case 10:
        case 0x13:
            break;
        case 4:
            strText.AppendFormat(L" [%d]", nId);
            break;
        case 0x3b:
            strText.AppendFormat(L" [PET %d]", nId);
            break;
        default:
            if (!strText.IsEmpty())
                strText.AppendFormat(L" [%d]", nId);
            break;
        }
    }
    return strText;
}

// @0x141811c90
CStringW CStringTable::GetItemDescription(int nItemId, CString strTag)
{
    CheckInit();
    DescPtr spDesc;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (FUN_1401d1320(&m_itemDescStamp))
        FUN_141814750(CString("korItemDescription.xml"), m_itemDescs, m_itemDescStamp);
    if (m_itemDescs.Lookup(nItemId, spDesc))
        return spDesc->FUN_141813a30(strTag);
    return CStringW(L"");
}

// @0x141811e50
CStringW CStringTable::GetSkillDescription(int nSkillId, unsigned short nLevel, CString strTag)
{
    CheckInit();
    DescPtr spDesc;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (FUN_1401d1320(&m_skillDescStamp))
        FUN_141814750(CString("stringSkillDescription.xml"), m_skillDescs, m_skillDescStamp);
    if (!m_skillDescs.Lookup(nSkillId, spDesc))
        return CStringW(L"");
    CStringW strText = spDesc->FUN_141813a30(strTag);
    MS2Ptr<Unk_StSkillRow> spSkill = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
    if (spSkill == 0)
        return CStringW(L"");
    MS2Ptr<Unk_StSkillLevel> spLevel = spSkill->FUN_1407e90a0(nLevel);
    if (spLevel == 0)
        return CStringW(L"");
    if (!spLevel->m_strArgs.IsEmpty())
        strText = FUN_141813790(CStringW(strText), CStringW(spLevel->m_strArgs));
    return strText;
}

// @0x141812290
CStringW CStringTable::FUN_141812290(int nBuffId, unsigned short nLevel, CString strTag)
{
    if (m_spAdditional->FUN_141819280() != 0)
    {
        m_levelDescs.RemoveAll();
        FUN_141814cf0(m_levelDescs, CachePtr(m_spAdditional));
    }
    CStringW strText = FUN_141815160(m_levelDescs, &nBuffId, &nLevel, strTag);
    if (strTag.CompareNoCase("tooltipDescription") == 0)
    {
        MS2Ptr<Unk_StEffectAttr> spAttr = FUN_1401958b0()->FUN_140aafef0(nBuffId, nLevel);
        if ((bool)spAttr.get())
        {
            if (!spAttr->m_strArgs.IsEmpty())
                strText = FUN_141813790(strText, CStringW(spAttr->m_strArgs));
        }
    }
    if (strTag.CompareNoCase("name") == 0)
        FUN_1403b4750()->FUN_1416fbf60(strText, nLevel);
    if (DAT_143ae0fc0 != 0 && strTag.CompareNoCase("name") == 0)
        strText.AppendFormat(L" [%d][%d]", nBuffId, nLevel);
    return strText;
}

// @0x1418125b0
CStringW CStringTable::FUN_1418125b0(int nId)
{
    const int nMin = 0x56057c1;
    const int nMax = 90300000;
    if (nId >= nMin && nId < nMax)
        return FUN_141811980(4, nId);
    if (nId >= 0xaae61 && nId <= 0xaae63)
    {
        Unk_StPlayer* pPlayer = static_cast<Unk_StPlayer*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pPlayer != 0)
        {
            CStringW strName = pPlayer->FUN_141523bc0()->FUN_141767e60(nId);
            if (!strName.IsEmpty())
                return FUN_1401e8510(FUN_141811980(5, nId), strName);
        }
    }
    else if (nId >= 0xdbba1 && nId <= 0xdbbaa)
    {
        CStringW strExtra;
        UIClosetDialog* pCloset = FUN_141815ed0();
        if (pCloset != 0)
            strExtra = pCloset->FUN_140be1a00(nId);
        return FUN_1401e8510(FUN_141811980(5, nId), strExtra);
    }
    return FUN_141811980(5, nId);
}

// @0x1418128c0
CStringW CStringTable::GetSetItemName(int nSetId, CString strTag)
{
    CheckInit();
    if (FUN_1401d1320(&m_setItemNameStamp))
        FUN_141814750(CString("SetItemName.xml"), m_setItemNames, m_setItemNameStamp);
    DescPtr spDesc;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_setItemNames.Lookup(nSetId, spDesc))
        return spDesc->FUN_141813a30(strTag);
    return CStringW(L"");
}

// @0x141812a80
CStringW CStringTable::GetUGCMapSetItemName(int nSetId, CString strTag)
{
    CheckInit();
    if (FUN_1401d1320(&m_ugcSetItemNameStamp))
        FUN_141814750(CString("UGCMapSetItemName.xml"), m_ugcSetItemNames, m_ugcSetItemNameStamp);
    DescPtr spDesc;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_ugcSetItemNames.Lookup(nSetId, spDesc))
        return spDesc->FUN_141813a30(strTag);
    return CStringW(L"");
}

// @0x141812c40
int CStringTable::FUN_141812c40(int nTable, const CStringW& strName)
{
    CachePtr spCache(0);
    if (!m_caches.Lookup(nTable, spCache))
    {
        CheckInit();
        return -1;
    }
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (spCache->FUN_141819280() != 0)
    {
        if (FUN_141813c80(CachePtr(spCache), CString(spCache->m_strParser), CString(spCache->m_strParserValue)) == 0)
            return -1;
    }
    for (POSITION pos = spCache->m_strings.GetHeadPosition(); pos; spCache->m_strings.GetNext(pos))
    {
        if (strName.CompareNoCase(spCache->m_strings.GetValueAt(pos)) == 0)
            return spCache->m_strings.GetKeyAt(pos);
    }
    return -1;
}

// @0x141812ec0
CStringW CStringTable::FUN_141812ec0(int n)
{
    if (n == 0)
        return FUN_14028de60(0x487);
    if (n == 1)
        return FUN_14028de60(0x488);
    return FUN_14028de60(0x489);
}

// @0x141812f60
CStringW CStringTable::FUN_141812f60(int nItemId)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return CStringW(L"");
    int nStringId = spItem->FUN_14053c620();
    if (nStringId == 0)
        return FUN_14028de60(0);
    return FUN_1401a9d70()->FUN_141811980(8, nStringId);
}

// @0x141813060
CStringW CStringTable::FUN_141813060(int nRank, int nItemId)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return CStringW(L"");
    if (spItem->FUN_14053c5a0() != 0)
        return FUN_14028de60(0);
    return FUN_141813150(nRank);
}

// @0x141813150
CStringW CStringTable::FUN_141813150(int nRank)
{
    if (nRank == 0)
        return FUN_14028de60(0x4f9);
    CStringW strKey;
    strKey.Format(L"s_word_rank_%02d", nRank);
    return FUN_14028b8e0(strKey);
}

// @0x141813200
CStringW CStringTable::FUN_141813200(__int64 nItemUid)
{
    Unk_StPlayer* pPlayer = static_cast<Unk_StPlayer*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return FUN_14028de60(0);
    MS2Ptr<CItem> spItem = pPlayer->FUN_141655b80(nItemUid);
    if (spItem.get() != 0)
        return FUN_141813150(spItem->FUN_140526bd0());
    return FUN_14028de60(0);
}

// @0x141813300
CStringW CStringTable::FUN_141813300(int nTab)
{
    switch (nTab)
    {
    case 0: return FUN_14028de60(0x259);
    case 4: return FUN_14028de60(0x25a);
    case 7: return FUN_14028de60(0x25b);
    case 2: return FUN_14028de60(0x25c);
    case 1: return FUN_14028de60(0x25d);
    case 6: return FUN_14028de60(0x25e);
    case 5: return FUN_14028de60(0x25f);
    case 3: return FUN_14028de60(0x260);
    case 8: return FUN_14028de60(0x261);
    case 9: return FUN_14028de60(0x262);
    case 10: return FUN_14028de60(0x263);
    case 11: return FUN_14028de60(0x264);
    case 12: return FUN_14028de60(0x265);
    case 0xd: return FUN_14028b8e0(L"s_inventory_tab_lapenshard");
    case 0xe: return FUN_14028b8e0(L"s_inventory_tab_piece");
    default: return FUN_14028de60(0);
    }
}

// @0x141813610
CStringW CStringTable::FUN_141813610(int a, int b, int c)
{
    if (a == 0)
    {
        if (b == 0 && c == 0)
            return FUN_14028de60(0x2cf);
        if (b == 0)
            return FUN_14028de60(0x2d0);
        if (c == 0)
            return FUN_14028de60(0x2d1);
        return FUN_14028de60(0x2d2);
    }
    else if (b == 0)
    {
        if (c == 0)
            return FUN_14028de60(0x2d3);
        return FUN_14028de60(0x2d4);
    }
    else if (c == 0)
        return FUN_14028de60(0x2d5);
    return FUN_14028de60(0);
}

// The format arguments of a text: the type bits of the arguments and their values.
struct Unk_StFmtArg { unsigned long long m_a; unsigned long long m_b; };
struct Unk_StFmtPack { char m_pad[0x20]; };
unsigned long long FUN_1401cfc00(const CStringW& str);
Unk_StFmtArg FUN_1401cfcf0(const CStringW& str);
Unk_StFmtPack FUN_140163e50(unsigned long long nTypes, const Unk_StFmtArg* pArgs);
CStringW FUN_1401d02a0(const wchar_t* pszFormat, const Unk_StFmtPack& rPack);

// MS2-FUNCTIONAL: the argument pack helpers are unit-local stand-ins
// @0x141813790
CStringW CStringTable::FUN_141813790(CStringW strFormat, CStringW strArgs)
{
    ATL::CAtlArray<CStringW> aTexts;
    FUN_14025a680(strArgs, aTexts, L",");
    ATL::CAtlArray<Unk_StFmtArg> aArgs;
    unsigned long long nTypes = 0;
    for (size_t i = 0; i < aTexts.GetCount(); i++)
    {
        CStringW strText = aTexts[i];
        if (aArgs.IsEmpty())
            nTypes = FUN_1401cfc00(strText);
        else
        {
            unsigned long long n = FUN_1401cfc00(strText);
            nTypes |= n << (((unsigned char)aArgs.GetCount() & 0xf) << 2);
        }
        aArgs.Add(FUN_1401cfcf0(strText));
    }
    return FUN_1401d02a0(strFormat, FUN_140163e50(nTypes, &aArgs[0]));
}

// @0x141813970
void CStringTable::FUN_141813970(Unk_140165cf0* pRoot)
{
    FUN_141815a20(m_itemDescs, pRoot);
}

// @0x1418139b0
void CStringTable::FUN_1418139b0(Unk_140165cf0* pRoot)
{
    FUN_141815b30(m_levelDescs, pRoot);
}

// @0x1418139f0
void CStringTable::FUN_1418139f0(Unk_140165cf0* pRoot)
{
    FUN_141815a20(m_skillDescs, pRoot);
}

// @0x141813c80
int CStringTable::FUN_141813c80(CachePtr spCache, CString strParser, CString strParserValue)
{
    if (FUN_140184310(strParser, "raceName"))
        return FUN_141813f10(CachePtr(spCache));
    else if (FUN_140184310(strParser, "customValue"))
        return FUN_141814310(CachePtr(spCache), CString(strParserValue));
    return FUN_141813e70(CachePtr(spCache));
}

// @0x141813e70
int CStringTable::FUN_141813e70(CachePtr spCache)
{
    return FUN_141814310(CachePtr(spCache), CString("name"));
}

// @0x141813f10
int CStringTable::FUN_141813f10(CachePtr spCache)
{
    Unk_CriticalSectionLock lock(spCache->m_lock, 1);
    spCache->m_strings.RemoveAll();
    for (POSITION pos = spCache->m_files.GetHeadPosition(); ; spCache->m_files.GetNext(pos))
    {
        if (pos == 0)
            return 1;
        MS2Ptr<CCacheData> spFile = spCache->m_files.GetAt(pos);
        if (spFile == 0)
            continue;
        TiXmlDocument doc;
        if (FUN_140166420()->FUN_1403974b0(&doc, *spFile->FUN_1401d1140(), 0, true, false) == 0)
            return 0;
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, MS2_XML_FORMAT_ERROR, *spFile->FUN_1401d1140());
            return 0;
        }
        for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
        {
            if (FUN_14028f710(pKey))
            {
                CString strId;
                CStringW strText;
                FUN_1408733e0(pKey, "id", strId);
                FUN_140873420(pKey, "name", strText);
                strText.Replace(L"\\n", L"\n");
                unsigned nId = FUN_14021c7c0(strId);
                spCache->m_strings.SetAt(nId, strText);
            }
        }
        spFile->FUN_1401d1160(CString(*spFile->FUN_1401d1140()));
    }
}

// @0x141814310
int CStringTable::FUN_141814310(CachePtr spCache, CString strAttr)
{
    Unk_CriticalSectionLock lock(spCache->m_lock, 1);
    spCache->m_strings.RemoveAll();
    for (POSITION pos = spCache->m_files.GetHeadPosition(); ; spCache->m_files.GetNext(pos))
    {
        if (pos == 0)
            return 1;
        MS2Ptr<CCacheData> spFile = spCache->m_files.GetAt(pos);
        if (spFile == 0)
            continue;
        TiXmlDocument doc;
        if (FUN_140166420()->FUN_1403974b0(&doc, *spFile->FUN_1401d1140(), 0, true, false) == 0)
            return 0;
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, MS2_XML_FORMAT_ERROR, *spFile->FUN_1401d1140());
            return 0;
        }
        for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
        {
            if (FUN_14028f710(pKey))
            {
                int nId = 0;
                CStringW strText;
                FUN_1408731e0(pKey, "id", nId);
                FUN_140873420(pKey, strAttr, strText);
                if (!strText.IsEmpty())
                {
                    strText.Replace(L"\\n", L"\n");
                    spCache->m_strings.SetAt(nId, strText);
                }
            }
        }
        spFile->FUN_1401d1160(CString(*spFile->FUN_1401d1140()));
    }
}

// @0x141814750
int CStringTable::FUN_141814750(CString strFile, DescMap& rMap, CCacheData& rCache)
{
    CString strPath = FUN_14071ae20(strFile);
    Unk_CriticalSectionLock lock(m_lock, 1);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, MS2_XML_FORMAT_ERROR, strPath);
        return 0;
    }
    for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
    {
        if (!FUN_14028f710(pKey))
            continue;
        DescPtr spDesc = FUN_1418154e0(pKey);
        if (spDesc == 0)
            continue;
        int nId = 0;
        FUN_1408731e0(pKey, "id", nId);
        rMap.SetAt(nId, spDesc);
    }
    rCache.FUN_1401d1160(CString(strPath));
    return 1;
}

// @0x141814a20
int CStringTable::FUN_141814a20(CString strFile, DescMap& rMap, CCacheData& rCache, ATL::CAtlArray<CString>& rTags)
{
    CString strPath = FUN_14071ae20(strFile);
    Unk_CriticalSectionLock lock(m_lock, 1);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, MS2_XML_FORMAT_ERROR, strPath);
        return 0;
    }
    for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
    {
        if (!FUN_14028f710(pKey))
            continue;
        DescPtr spDesc = FUN_141815650(pKey, rTags);
        if (spDesc == 0)
            continue;
        int nId = 0;
        FUN_1408731e0(pKey, "id", nId);
        rMap.SetAt(nId, spDesc);
    }
    rCache.FUN_1401d1160(CString(strPath));
    return 1;
}

// @0x141814cf0
int CStringTable::FUN_141814cf0(LevelDescMap& rMap, CachePtr spCache)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (POSITION pos = spCache->m_files.GetHeadPosition(); pos; spCache->m_files.GetNext(pos))
    {
        MS2Ptr<CCacheData> spFile = spCache->m_files.GetAt(pos);
        if (spFile == 0)
            continue;
        TiXmlDocument doc;
        if (FUN_140166420()->FUN_1403974b0(&doc, *spFile->FUN_1401d1140(), 0, true, false) == 0)
            continue;
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, MS2_XML_FORMAT_ERROR, *spFile->FUN_1401d1140());
            continue;
        }
        ATL::CAtlArray<void*> aNodes;
        FUN_14028fd90(pRoot, "key", "id", "level", aNodes);
        for (size_t i = 0; i < aNodes.GetCount(); i++)
        {
            Unk_140165cf0* pNode = static_cast<Unk_140165cf0*>(aNodes[i]);
            if (pNode == 0)
                continue;
            int nId = 0;
            FUN_1408731e0(pNode, "id", nId);
            int nLevel = 1;
            FUN_1408731e0(pNode, "level", nLevel);
            DescPtr spDesc = FUN_1418158b0(pNode);
            if (spDesc == 0)
            {
                (void)((!!(0)) || (_wassert(L"FALSE", _CRT_WIDE(MS2_THIS_FILE), 0x327), 0));
                continue;
            }
            LevelDescPtr spLevels;
            if (!rMap.Lookup(nId, spLevels))
                spLevels.AssignRaw(new CLevelDesc());
            spLevels->m_levels.SetAt((unsigned short)nLevel, spDesc);
            rMap.SetAt(nId, spLevels);
        }
    }
    return 1;
}

// @0x141815160
CStringW CStringTable::FUN_141815160(LevelDescMap& rMap, int* pnId, unsigned short* pnLevel, const CString& strTag)
{
    LevelDescPtr spLevels;
    DescPtr spDesc;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (rMap.Lookup(*pnId, spLevels))
    {
        if (!spLevels->m_levels.Lookup(*pnLevel, spDesc))
            return FUN_141815330(spLevels, pnLevel, strTag);
        return spDesc->FUN_141813a30(strTag);
    }
    return CStringW(L"");
}

// @0x141815330
CStringW CStringTable::FUN_141815330(LevelDescPtr& spLevels, unsigned short* pnLevel, const CString& strTag)
{
    CStringW strText(L"");
    for (POSITION pos = spLevels->m_levels.GetHeadPosition(); pos; spLevels->m_levels.GetNext(pos))
    {
        const DescPtr& rDesc = spLevels->m_levels.GetValueAt(pos);
        const unsigned short& rLevel = spLevels->m_levels.GetKeyAt(pos);
        if (*pnLevel >= rLevel)
            strText = rDesc->FUN_141813a30(strTag);
        else
            return strText;
    }
    return strText;
}

// @0x1418154e0
CStringTable::DescPtr CStringTable::FUN_1418154e0(Unk_140165cf0* pNode)
{
    ATL::CAtlArray<CString> aTags;
    aTags.Add("mainDescription");
    aTags.Add("functionDescription");
    aTags.Add("tooltipDescription");
    aTags.Add("guideDescription");
    aTags.Add("name");
    return FUN_141815650(pNode, aTags);
}

// @0x141815650
CStringTable::DescPtr CStringTable::FUN_141815650(Unk_140165cf0* pNode, ATL::CAtlArray<CString>& rTags)
{
    DescPtr spDesc(new CDesc());
    {
        CStringW strText;
        FUN_140873420(pNode, "name", strText);
        if (!strText.IsEmpty())
        {
            strText.Replace(L"\\n", L"\n");
            spDesc->FUN_141813b80("name", strText);
        }
    }
    if (!rTags.IsEmpty())
    {
        for (size_t i = 0; i < rTags.GetCount(); i++)
        {
            CStringW strText;
            CString strTag(rTags[i]);
            FUN_140873420(pNode, strTag, strText);
            if (!strText.IsEmpty())
            {
                strText.Replace(L"\\n", L"\n");
                spDesc->FUN_141813b80(strTag, strText);
            }
        }
    }
    return spDesc;
}

// @0x1418158b0
CStringTable::DescPtr CStringTable::FUN_1418158b0(Unk_140165cf0* pNode)
{
    ATL::CAtlArray<CString> aTags;
    aTags.Add("uiDescription");
    aTags.Add("mainDescription");
    aTags.Add("functionDescription");
    aTags.Add("tooltipDescription");
    aTags.Add("guideDescription");
    return FUN_141815650(pNode, aTags);
}

// @0x141815a20
void CStringTable::FUN_141815a20(DescMap& rMap, Unk_140165cf0* pRoot)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
    {
        if (!FUN_14028f710(pKey))
            continue;
        DescPtr spDesc = FUN_1418154e0(pKey);
        if (spDesc == 0)
            continue;
        int nId = 0;
        FUN_1408731e0(pKey, "id", nId);
        rMap.SetAt(nId, spDesc);
    }
}

// @0x141815b30
void CStringTable::FUN_141815b30(LevelDescMap& rMap, Unk_140165cf0* pRoot)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (Unk_140165cf0* pKey = pRoot->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
    {
        if (!FUN_14028f710(pKey))
            continue;
        int nId = 0;
        FUN_1408731e0(pKey, "id", nId);
        int nLevel = 1;
        FUN_1408731e0(pKey, "level", nLevel);
        DescPtr spDesc = FUN_1418158b0(pKey);
        if (spDesc == 0)
        {
            (void)((!!(0)) || (_wassert(L"FALSE", _CRT_WIDE(MS2_THIS_FILE), 0x298), 0));
            continue;
        }
        LevelDescPtr spLevels;
        if (!rMap.Lookup(nId, spLevels))
            spLevels.AssignRaw(new CLevelDesc());
        spLevels->m_levels.SetAt((unsigned short)nLevel, spDesc);
        rMap.SetAt(nId, spLevels);
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbb6d0-0x142cbb780 .text$yd
