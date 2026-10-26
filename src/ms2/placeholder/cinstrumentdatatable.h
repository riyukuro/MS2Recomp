// cinstrumentdatatable.h - CInstrumentDataTable (RTTI .?AVCInstrumentDataTable@@, 0xa0 bytes) and its row types
// CInstrumentData (0x78) / CInstrumentCategoryData (0x38). NOT an original header (name assumed); member names are
// invented from use (Table/InstrumentInfo.xml <instrument>, Table/InstrumentCategoryInfo.xml <category>).
// Bases: TSingleton<CInstrumentDataTable> at +0x0, CValidData<CInstrumentDataTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

class Unk_140165cf0;

// One <category> row. RTTI CInstrumentCategoryData, 0x38 bytes, base CPtred.
class CInstrumentCategoryData : public CPtred
{
public:
    CInstrumentCategoryData(Unk_140165cf0* pNode);      // 0x14072c300
    virtual ~CInstrumentCategoryData();                 // 0x14072c420
    CStringW GetName() const;                           // 0x14072c480 string table text of the category
    bool IsPercussion() const;                          // 0x14072c500

    int m_nId;                                          // +0x18 "id"
    int m_nGMId;                                        // +0x1c "GMId"
    int m_nPercussionId;                                // +0x20 "percussionId"
    CString m_strIcon;                                  // +0x28 "icon"
    CString m_strDefaultOctave;                         // +0x30 "defaultOctave"
};
MS2_CHECK_SIZE(CInstrumentCategoryData, 0x38);

// One <instrument> row. RTTI CInstrumentData, 0x78 bytes, base CPtred.
class CInstrumentData : public CPtred
{
public:
    CInstrumentData(Unk_140165cf0* pNode);              // 0x14072bdc0
    virtual ~CInstrumentData();                         // 0x14072c080
    CStringW GetName() const;                           // 0x14072c150
    CStringW GetCategoryName() const;                   // 0x14072c240

    int m_nId;                                          // +0x18 "id"
    int m_nCategory;                                    // +0x1c "category"
    bool m_bExpensive;                                  // +0x20 "isExpensive"
    CString m_strAsset;                                 // +0x28 "asset"
    int m_nEquipItemId;                                 // +0x30 "equipItemId"
    int m_nSoloRelayScoreCount;                         // +0x34 "soloRelayScoreCount" (default 1)
    CString m_strReadyEffect;                           // +0x38 "readyEffect"
    CString m_strPlayEffect;                            // +0x40 "playEffect"
    CString m_strAnimationReady;                        // +0x48 "animationReady"
    CString m_strAnimationPlayIdle;                     // +0x50 "animationPlayIdle"
    CString m_strAnimationPlayLevel1;                   // +0x58 "animationPlayLevel1"
    CString m_strAnimationPlayLevel2;                   // +0x60 "animationPlayLevel2"
    CString m_strAnimationPlayLevel3;                   // +0x68 "animationPlayLevel3"
    CString m_strAnimationPlayLevel4;                   // +0x70 "animationPlayLevel4"
};
MS2_CHECK_SIZE(CInstrumentData, 0x78);
MS2_CHECK_OFFSET(CInstrumentData, m_strAnimationReady, 0x48);
MS2_CHECK_OFFSET(CInstrumentData, m_strAnimationPlayIdle, 0x50);

class CInstrumentDataTable : public TSingleton<CInstrumentDataTable>, public CValidData<CInstrumentDataTable>
{
public:
    typedef MS2Ptr<CInstrumentData> InstrumentPtr;
    typedef MS2Ptr<CInstrumentCategoryData> CategoryPtr;

    CInstrumentDataTable();                                 // 0x14072c520
    virtual ~CInstrumentDataTable();                        // 0x14072c600

    bool Load();                                            // 0x14072c670 both xml files
    bool LoadInstruments();                                 // 0x14072c6c0 Table/InstrumentInfo.xml
    bool LoadCategories();                                  // 0x14072c920 Table/InstrumentCategoryInfo.xml
    InstrumentPtr GetInstrument(int nId);                   // 0x14072cb80
    CategoryPtr GetCategory(int nId);                       // 0x14072cc10
    CategoryPtr GetInstrumentCategory(int nInstrumentId);   // 0x14072cc90
    ATL::CAtlMap<int, InstrumentPtr>& GetInstruments();     // 0x14072cdb0
    ATL::CAtlMap<int, CategoryPtr>& GetCategories();        // 0x14072cdd0

    static CStringW GetCategoryNameById(int nCategoryId);   // 0x14072cdf0 ("" when missing)
    static CString GetCategoryIconById(int nCategoryId);    // 0x14072ceb0 ("" when missing)
    static void CheckInit();                                // 0x14072d7c0
    static void SetInit(bool b);                            // 0x14072f4b0

    static bool s_bInit;                                    // 0x143ab0b98

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<int, InstrumentPtr> m_instruments;         // +0x10 id -> row
    ATL::CAtlMap<int, CategoryPtr> m_categories;            // +0x58 id -> row
};
MS2_CHECK_SIZE(CInstrumentDataTable, 0xa0);
MS2_CHECK_OFFSET(CInstrumentDataTable, m_instruments, 0x10);
MS2_CHECK_OFFSET(CInstrumentDataTable, m_categories, 0x58);
