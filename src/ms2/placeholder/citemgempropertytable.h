// citemgempropertytable.h - CItemGemPropertyTable (RTTI .?AVCItemGemPropertyTable@@, 0xa8 bytes). NOT an original header
// (the unit is commonfiles\itemgempropertytable.cpp, 0x1405abd00-0x1405b0b70). Loaded from Table/ItemGemProperty_*.xml
// (<tomb>, <swim>, <charEffect>, <effect> rows keyed by "id"); created by CGameApp::InitInstance (?\ms2.cpp). The rows
// are in commonfiles/itemgem.h.
// Bases: TSingleton<CItemGemPropertyTable> at +0x0 (s_instance DAT_143aafd08), CValidData<CItemGemPropertyTable> at +0x8.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <typeinfo>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cvaliddata.h"

class CGemDataBase;
class Unk_140165cf0;

CString FUN_14016a5c0(const char* psz, int nCodePage);         // narrows a string (the RTTI name in CheckInit)

class CItemGemPropertyTable : public TSingleton<CItemGemPropertyTable>,
                              public CValidData<CItemGemPropertyTable>
{
public:
    CItemGemPropertyTable();                                // 0x1405abd00
    virtual ~CItemGemPropertyTable();                       // 0x1405abdc0

    bool Load();                                            // 0x1405abe50 the four ItemGemProperty_*.xml
    MS2Ptr<CGemDataBase> FUN_1405ac160(int nGemId);         // 0x1405ac160 the row of a gem (null when missing)
    bool FUN_1405ac260();                                   // 0x1405ac260 reloads when a file changed on disk

    // @0x1405afa00
    static void CheckInit()
    {
        if (!s_bInit)
        {
            CStringA msg;
            msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemGemPropertyTable).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    // @0x1405b0900
    static void SetInit(bool bInit) { s_bInit = bInit; }

    static bool s_bInit;                                    // DAT_143aafd10

private:
    MS2_LAYOUT_FRIEND;
    // Loads one file: rows of <pszTag> become T, keyed by "id" (0x1405adec0 .. 0x1405aeb80, one per row class).
    template <class T> bool LoadGems(const CString& strFile, const CString& strTag);

    CLockCriticalSection m_lock;                            // +0x10
    ATL::CAtlArray<MS2Ptr<CCacheData> > m_caches;           // +0x40 one per loaded xml (path, write time)
public:
    ATL::CAtlMap<int, MS2Ptr<CGemDataBase> > m_gems;        // +0x60 gem id -> row
};
MS2_CHECK_SIZE(CItemGemPropertyTable, 0xa8);
