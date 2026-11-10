// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIFamePointBoardDialog: see uifamepointboarddialog.h.
// MS2-UNIT: ?\uifamepointboarddialog.cpp
// MS2-RANGE: 0x140c15460-0x140c165e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??$FUN_14028dfa0@_J@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEB_J@Z 0x140c160b0
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uifamepointboarddialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/mstime.h"
#include "uifamepointboarddialog.h"
#include "uidailymissiondialog.h"   // C3: UIDailyMissionDialog::FUN_140c02870 (the tab strip lookup)
#include <atlcoll.h>
#include <atltime.h>
#include "ms2/ms2format.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/commonfiles/famegradedata.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/ascript.h"

// ---- unit-local views of exe objects ----


// The movie root with the "setData" call.
class Unk_FpScript : public AScript
{
public:
};


class Unk_EmoNpcTable* GetFameTable();   // C3: was GetFameTable
void* FUN_140764020();   // C3: was FUN_140764020
class CReservedWordTable;
__int64 GetServerTime();                                                // the server time
// FUN_1406c47a0/4760 are CMsTime ctors (16 bytes: Init 0x1406c5270 stores the zone flag at +8); 8-byte ATL::CTime
// locals had that byte written past them (rt1 stackovf.py).
CStringW GetAllianceName(int nAlliance);                                  // the alliance's name
CString GetAllianceSymbol(int nAlliance);                                   // the alliance's symbol
CStringW FUN_140762ee0(int nAlliance, int nGrade);                      // the grade's name
int GetFamePoints(Unk_FameAlliance nAlliance);                          // the player's fame points
void GetFamePointProgress(int nAlliance, int* pnCurrent, int* pnMax, CStringW& strPoint);    // the fame points

extern ATL::CRBMap<__int64, int> DAT_143ab31e8;                         // time -> fame log id

// @0x140c15460
UIFamePointBoardDialog::UIFamePointBoardDialog()
{
    m_80 = 0;
    m_88 = 1;
    m_58 = 1;
}

// @0x140c154d0
UIFamePointBoardDialog::~UIFamePointBoardDialog()
{
}

// @0x140c15510
CString UIFamePointBoardDialog::GetTypeName()
{
    return "FamePointBoardDialog";
}

// @0x140c15560
void UIFamePointBoardDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140c15580
void UIFamePointBoardDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    RebuildTabs();
}

// @0x140c155b0
int UIFamePointBoardDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData unused;
    if (_stricmp("onChangeTab", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nAlliance = data.PopInt();
            SetAllianceData(nAlliance);
        }
        return 1;
    }
    return 0;
}

// @0x140c156d0
int UIFamePointBoardDialog::FUN_140c156d0()
{
    int nResult = 0;
    ATL::CAtlArray<Unk_FameAlliance>& ids = ((class CFameTable*)GetFameTable())->GetAllianceIds();
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        int nQuestId = ((class CFameTable*)GetFameTable())->GetSeasonRequireQuest(ids[i]);
        if (((class CQuestManager*)FUN_140764020())->IsQuestRewarded(nQuestId) != 0)
        {
            nResult = 1;
            break;
        }
    }
    return nResult;
}

// @0x140c15780
void UIFamePointBoardDialog::RebuildTabs()
{
    if (MS2Ptr<ASButtonBar> spTab = reinterpret_cast<UIDailyMissionDialog*>(this)->GetButtonBar("m_tab"))
    {
        spTab->ClearDataProvider();
        ATL::CAtlArray<Unk_FameAlliance>& ids = ((class CFameTable*)GetFameTable())->GetAllianceIds();
        for (size_t i = 0; i < ids.GetCount(); i++)
        {
            Unk_FameAlliance nAlliance = ids[i];
            int nQuestId = ((class CFameTable*)GetFameTable())->GetSeasonRequireQuest(nAlliance);
            if (((class CQuestManager*)FUN_140764020())->IsQuestRewarded(nQuestId) == 0)
                continue;
            ASObj row(2);
            row.SetWStringMember("label", GetAllianceName(nAlliance));
            row.SetStringMember("alliance", GetAllianceSymbol(nAlliance));
            row.SetWStringMember("grade", FUN_140762ee0(nAlliance, GetFamePoints(nAlliance)));
            row.SetIntMember("allianceCode", nAlliance);
            spTab->AddItem(row);
        }
        spTab->SetSelectedIndex(0);
        spTab->vfunc_24(true);
    }
}

// @0x140c15a10
void UIFamePointBoardDialog::SetAllianceData(int nAlliance)
{
    CStringW strPoint;
    int nCurrent;
    int nMax;
    GetFamePointProgress(nAlliance, &nCurrent, &nMax, strPoint);
    ASObj data(2);
    data.SetWStringMember("allianceName", GetAllianceName(nAlliance));
    data.SetWStringMember("allianceGrade", FUN_140762ee0(nAlliance, GetFamePoints((Unk_FameAlliance)nAlliance)));
    data.SetStringMember("alliance", GetAllianceSymbol(nAlliance));
    data.SetIntMember("currentFame", nCurrent);
    data.SetIntMember("maxFame", nMax);
    data.SetWStringMember("famePoint", strPoint);
    CMsTime timeNow(GetServerTime());
    ASArray logs(2);
    for (POSITION pos = DAT_143ab31e8.GetHeadPosition(); pos != 0; DAT_143ab31e8.GetNext(pos))
    {
        int nLogId = DAT_143ab31e8.GetValueAt(pos);
        __int64 nLogTime = DAT_143ab31e8.GetKeyAt(pos);
        if (((class CFameTable*)GetFameTable())->IsLogOfAlliance(nLogId, (Unk_FameAlliance)nAlliance) == 0)
            continue;
        CStringW strMsg = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x43, nLogId);
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectAndValueWords(strMsg);
        CStringW strDate;
        CMsTime timeLog(nLogTime);
        ATL::CTimeSpan span = timeNow - timeLog;
        if (span.GetTotalHours() > 0x18)
        {
            int nDay = timeLog.GetDay();
            int nMonth = timeLog.GetMonth();
            int nYear = timeLog.GetYear();
            strDate = FUN_14028dfa0(CStringW(L"s_fame_point_board_time3"), nYear, nMonth, nDay);
        }
        else if (span.GetTotalMinutes() > 0x3c)
        {
            int nMinute = timeLog.GetMinute();
            int nHour = timeLog.GetHour();
            strDate = FUN_14028dfa0(CStringW(L"s_fame_point_board_time2"), nHour, nMinute);
        }
        else
        {
            __int64 nMinutes = span.GetTotalMinutes();
            strDate = FUN_14028dfa0(CStringW(L"s_fame_point_board_time1"), nMinutes);
        }
        ASObj line(2);
        line.SetWStringMember("msg", strMsg);
        line.SetWStringMember("date", strDate);
        logs.PushObj(line);
    }
    data.FUN_140c16160("log", logs);
    reinterpret_cast<AScript*>(static_cast<Unk_FpScript*>(m_30.operator->()))->Invoke("setData", data);
}

// @0x140c16160
void ASObj::FUN_140c16160(const char* szName, ASArray arr)
{
    ASData data;
    data.AddValue(arr.FUN_1422bb890());
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x140c164c0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
