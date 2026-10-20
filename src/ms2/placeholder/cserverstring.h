// cserverstring.h - PLACEHOLDER for CServerString (RTTI .?AVCServerString@@, 0x260 bytes) and CServerStringGroup
// (RTTI .?AVCServerStringGroup@@, 0xc8 bytes). NOT original headers (names from the RTTI, members assumed).
// CServerString is a TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; it owns three groups of server strings
// (stringTrigger.xml, stringNpcAi.xml, stringGameEvent.xml). Each group is a CCacheData of its XML file with two
// key -> text maps: the strings of the file (+0x38) and the strings added at run time (+0x80).
#pragma once

#include <atlcoll.h>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

typedef ATL::CAtlMap<CStringW, CStringW, ATL::CStringElementTraits<CStringW> > CServerStringMap;

class CServerStringGroup : public CCacheData, public CValidData<CServerStringGroup>
{
public:
    CServerStringGroup(CStringA strFile);                   // 0x14087e8c0
    virtual ~CServerStringGroup();                          // 0x14087e9c0

    bool Load();                                            // 0x14087ea50 reads <ms2><key id name/> into the file map
    CStringW GetString(const CStringW& strKey);             // 0x14087ede0 "$key$" -> text, "NO KEY : {0}" when missing
    void SetString(const CStringW& strKey, const CStringW& strText);   // 0x14087f0f0 into the run time map
    bool RemoveString(const CStringW& strKey);              // 0x14087f140 from the run time map

    static void CheckInit();                                // 0x14087f7b0
    static void SetInit(bool bInit);                        // 0x1408805c0

    static bool s_bInit;                                    // DAT_143ab2078
private:
    MS2_LAYOUT_FRIEND;
    CStringA m_strFile;                                     // +0x30
    CServerStringMap m_mapFile;                             // +0x38
    CServerStringMap m_mapRuntime;                          // +0x80
};
MS2_CHECK_SIZE(CServerStringGroup, 0xc8);
MS2_CHECK_OFFSET(CServerStringGroup, m_strFile, 0x30);
MS2_CHECK_OFFSET(CServerStringGroup, m_mapFile, 0x38);
MS2_CHECK_OFFSET(CServerStringGroup, m_mapRuntime, 0x80);

class CServerString : public TSingleton<CServerString>
{
public:
    CServerString();                                        // 0x14087f180
    virtual ~CServerString();                               // 0x14087f280

    bool Load();                                            // 0x14087f2f0 loads the three groups
    bool LoadTrigger();                                     // 0x14087f350
    bool LoadNpcAi();                                       // 0x14087f380
    bool LoadGameEvent();                                   // 0x14087f3b0
    CServerStringGroup* GetGameEvent() { return &m_gameEvent; }   // inline (0x140be95b0, ?\uicollectitemgroupeventdialog.cpp)

private:
    MS2_LAYOUT_FRIEND;
    CServerStringGroup m_trigger;                           // +0x8   stringTrigger.xml
    CServerStringGroup m_npcAi;                             // +0xd0  stringNpcAi.xml
    CServerStringGroup m_gameEvent;                         // +0x198 stringGameEvent.xml
};
MS2_CHECK_SIZE(CServerString, 0x260);
MS2_CHECK_OFFSET(CServerString, m_trigger, 0x8);
MS2_CHECK_OFFSET(CServerString, m_npcAi, 0xd0);
MS2_CHECK_OFFSET(CServerString, m_gameEvent, 0x198);
