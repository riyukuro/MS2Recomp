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

// ---- unit-local views of exe objects ----

// "m_tab": the alliance tab strip.
class Unk_FpTab : public ASDisplayObject
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bVisible);
    void FUN_1422e3400();                                       // clear
    void FUN_1422e3460(const ASObj& row);                       // add a tab
    void FUN_1422e31e0(int nIndex);                             // select a tab
};

// The movie root with the "setData" call.
class Unk_FpScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_140ba4cc0(const char* szMethod, const ASObj& data);
};


CFameTable* FUN_140764010();                                            // the fame table
CQuestManager* FUN_140764020();                                         // the quest manager
CReservedWordTable* FUN_1403b4750();                                    // the text filter
__int64 GetServerTime();                                                // the server time
// FUN_1406c47a0/4760 are CMsTime ctors (16 bytes: Init 0x1406c5270 stores the zone flag at +8); 8-byte ATL::CTime
// locals had that byte written past them (rt1 stackovf.py).
CStringW FUN_140762de0(int nAlliance);                                  // the alliance's name
CString FUN_140762e90(int nAlliance);                                   // the alliance's symbol
CStringW FUN_140762ee0(int nAlliance, int nGrade);                      // the grade's name
int FUN_140931210(int nAlliance);                                       // the player's grade
void FUN_140762fc0(int nAlliance, int* pnCurrent, int* pnMax, CStringW& strPoint);    // the fame points
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member

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
    FUN_140c15780();
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
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nAlliance = data.FUN_1422b8a10();
            FUN_140c15a10(nAlliance);
        }
        return 1;
    }
    return 0;
}

// @0x140c156d0
int UIFamePointBoardDialog::FUN_140c156d0()
{
    int nResult = 0;
    ATL::CAtlArray<Unk_FameAlliance>& ids = FUN_140764010()->GetAllianceIds();
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        int nQuestId = FUN_140764010()->GetSeasonRequireQuest(ids[i]);
        if (FUN_140764020()->FUN_140745590(nQuestId) != 0)
        {
            nResult = 1;
            break;
        }
    }
    return nResult;
}

// @0x140c15780
void UIFamePointBoardDialog::FUN_140c15780()
{
    if (MS2Ptr<Unk_FpTab> spTab = FUN_140c02870("m_tab"))
    {
        spTab->FUN_1422e3400();
        ATL::CAtlArray<Unk_FameAlliance>& ids = FUN_140764010()->GetAllianceIds();
        for (size_t i = 0; i < ids.GetCount(); i++)
        {
            Unk_FameAlliance nAlliance = ids[i];
            int nQuestId = FUN_140764010()->GetSeasonRequireQuest(nAlliance);
            if (FUN_140764020()->FUN_140745590(nQuestId) == 0)
                continue;
            ASObj row(2);
            row.FUN_1407cbb20("label", FUN_140762de0(nAlliance));
            row.FUN_1407cba60("alliance", FUN_140762e90(nAlliance));
            row.FUN_1407cbb20("grade", FUN_140762ee0(nAlliance, FUN_140931210(nAlliance)));
            row.FUN_1407cb9c0("allianceCode", nAlliance);
            spTab->FUN_1422e3460(row);
        }
        spTab->FUN_1422e31e0(0);
        spTab->vfunc_24(true);
    }
}

// @0x140c15a10
void UIFamePointBoardDialog::FUN_140c15a10(int nAlliance)
{
    CStringW strPoint;
    int nCurrent;
    int nMax;
    FUN_140762fc0(nAlliance, &nCurrent, &nMax, strPoint);
    ASObj data(2);
    data.FUN_1407cbb20("allianceName", FUN_140762de0(nAlliance));
    data.FUN_1407cbb20("allianceGrade", FUN_140762ee0(nAlliance, FUN_140931210(nAlliance)));
    data.FUN_1407cba60("alliance", FUN_140762e90(nAlliance));
    data.FUN_1407cb9c0("currentFame", nCurrent);
    data.FUN_1407cb9c0("maxFame", nMax);
    data.FUN_1407cbb20("famePoint", strPoint);
    CMsTime timeNow(GetServerTime());
    ASArray logs(2);
    for (POSITION pos = DAT_143ab31e8.GetHeadPosition(); pos != 0; DAT_143ab31e8.GetNext(pos))
    {
        int nLogId = DAT_143ab31e8.GetValueAt(pos);
        __int64 nLogTime = DAT_143ab31e8.GetKeyAt(pos);
        if (FUN_140764010()->IsLogOfAlliance(nLogId, (Unk_FameAlliance)nAlliance) == 0)
            continue;
        CStringW strMsg = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x43, nLogId);
        FUN_1403b4750()->FUN_1416fb300(strMsg);
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
        line.FUN_1407cbb20("msg", strMsg);
        line.FUN_1407cbb20("date", strDate);
        logs.FUN_1422bbf00(line);
    }
    data.FUN_140c16160("log", logs);
    static_cast<Unk_FpScript*>(m_30.operator->())->FUN_140ba4cc0("setData", data);
}

// @0x140c16160
void ASObj::FUN_140c16160(const char* szName, ASArray arr)
{
    ASData data;
    data.FUN_1422b83f0(arr.FUN_1422bb890());
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140c164c0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
