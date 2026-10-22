// cgloabalfactor.h - CGloabalFactor (RTTI .?AVCGloabalFactor@@, 0x1608 bytes). NOT an original header (the unit is
// commonfiles\gloabalfactor.cpp, 0x1404c11a0-0x1404c5c70). The server-sent global rate tables: experience / meso rate per
// level and kind, and the "multi control" factors (Table/multicontrol.xml) of five systems per group id.
// Bases: TSingleton<CGloabalFactor> at +0x0 (s_instance DAT_143aaef08), CValidData<CGloabalFactor> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates.
#pragma once
#include <afx.h>
#include <map>
#include <typeinfo>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CInPacket;
class Unk_140165cf0;
CString FUN_14016a5c0(const char* psz, int nCodePage);         // narrows a string (the RTTI name in CheckInit)

class CGloabalFactor : public TSingleton<CGloabalFactor>, public CValidData<CGloabalFactor>
{
public:
    // Multi control systems (the "type" attribute of <multi>).
    enum { MULTI_NONE, MULTI_ENCHANT_SCROLL_RECIPE, MULTI_GLOBAL_DROP_ITEM_COUNT, MULTI_EQUIPMENT_SELL_PRICE,
           MULTI_DUNGEON_CLEAR_MESO, MULTI_QUEST_REWARD_MESO };
    typedef std::map<int, float> MultiMap;                  // group id -> factor

    CGloabalFactor();                                       // 0x1404c11a0
    virtual ~CGloabalFactor();                              // 0x1404c1220

    bool Load();                                             // 0x1404c1290 resets both rate tables, then multicontrol.xml
    bool FUN_1404c12f0();                                    // 0x1404c12f0 every experience rate 1.0
    bool FUN_1404c1370();                                    // 0x1404c1370 every meso rate 1.0
    bool LoadMultiControl();                                   // 0x1404c1400 Table/multicontrol.xml
    float FUN_1404c1730(unsigned int nLevel, int nKind);    // 0x1404c1730 meso rate (1.0 outside 1..max level)
    float FUN_1404c17a0(unsigned int nLevel, int nKind);    // 0x1404c17a0 experience rate
    float FUN_1404c1810(int nType, int nGroupId);           // 0x1404c1810 multi control factor of a group (1.0: none)
    void FUN_1404c18c0(CInPacket& packet);                  // 0x1404c18c0 reads both rate tables from the server

    // @0x1404c3ed0
    static void CheckInit()
    {
        if (!s_bInit)
        {
            CString msg;
            msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CGloabalFactor).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    // @0x1404c3f80
    static void SetInit(bool bInit) { s_bInit = bInit; }

    static bool s_bInit;                                    // DAT_143aaef10

private:
    MS2_LAYOUT_FRIEND;
    float m_fExpRate[11][100];                              // +0x10 [kind][level]
    float m_fMesoRate[3][100];                              // +0x1140 [kind][level]
    std::vector<MultiMap> m_multi;                          // +0x15f0 [MULTI_*]
};
MS2_CHECK_SIZE(CGloabalFactor, 0x1608);
MS2_CHECK_OFFSET(CGloabalFactor, m_fExpRate, 0x10);
MS2_CHECK_OFFSET(CGloabalFactor, m_fMesoRate, 0x1140);
MS2_CHECK_OFFSET(CGloabalFactor, m_multi, 0x15f0);
