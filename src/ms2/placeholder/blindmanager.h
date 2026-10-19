// blindmanager.h - BlindManager (RTTI .?AVBlindManager@@, 0x20 bytes). NOT an original header.
// Bases: TSingleton<BlindManager> at +0x0. The per-type block lists of the merat market / chat (persisted in
// <user dir>\BlindList.xml); a TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates.
#pragma once

#include <afx.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class BlindManager : public TSingleton<BlindManager>
{
public:
    // the value of a blind list: the blocked key and the time (_time64 seconds) the block expires
    struct BlindEntry
    {
        CStringW m_name;                                    // +0x00
        __int64 m_expire;                                   // +0x08
    };
    typedef std::map<CStringW, BlindEntry> BlindList;

    BlindManager();                                         // 0x140a24e90
    virtual ~BlindManager();                                // 0x140a24ef0
    void ClearLists();                                      // 0x140a24f50
    void CreateLists();                                     // 0x140a24ff0
    void Load();                                            // 0x140a250a0 BlindList.xml
    void Save();                                            // 0x140a25400
    bool Block(int nType, CStringW strKey);                 // 0x140a25730
    bool IsBlocked(int nType, CStringW strKey);             // 0x140a25840
    bool BlockId(int nType, unsigned __int64 nId);          // 0x140a25950
    bool IsBlockedId(int nType, unsigned __int64 nId);      // 0x140a259b0
private:
    MS2_LAYOUT_FRIEND;
    std::vector<BlindList*> m_lists;                        // +0x08 six lists, one per blind type
};
MS2_CHECK_SIZE(BlindManager, 0x20);
