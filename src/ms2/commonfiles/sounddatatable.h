// sounddatatable.h - CSoundDataTable (RTTI name): the sound length table read from Table/soundDataTable_<lang>.xml
// (three sections: eventSound, programmerSound, triggerVoiceSound; each <sound id= lengthms=>). Header name assumed;
// member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <list>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class TiXmlElement;     // game TinyXML element (commonfiles/tinyxml.h)

// One <sound> row, 0x18 bytes (value of the three maps, also the element of the lists passed to the Set* functions).
struct CSoundDataEntry
{
    int nType;                          // +0 section: 0 eventSound, 1 programmerSound, 2 triggerVoiceSound
    CString strName;                    // +8 "id"
    int nLengthMs;                      // +0x10 "lengthms"
};
MS2_CHECK_SIZE(CSoundDataEntry, 0x18);

// RTTI CSoundDataTable, 0x40 bytes; vftable 0x142d95d80 (+ TSingleton at 0x142d95d70). Keys are the sound ids.
class CSoundDataTable : public TSingleton<CSoundDataTable>
{
public:
    typedef std::map<CString, CSoundDataEntry> SoundMap;
    typedef std::list<CSoundDataEntry> SoundList;

    CSoundDataTable();                  // 0x1408179d0
    virtual ~CSoundDataTable();         // 0x140817ad0

    int Load();                         // 0x140817b50 reads the xml; 1 on success
    int Save();                         // 0x140817d70 writes the xml back
    CString GetPath();                  // 0x140818320
    void SetLanguage(int nLanguage);    // 0x140818370 picks Table/soundDataTable_<language>.xml
    CSoundDataEntry* FindEventSound(const CString& strDir, const CString& strName);   // 0x140818460 key "<dir>/<name>"
    CSoundDataEntry* FindProgrammerSound(CString strName);        // 0x140818570 ("$name$" is stripped)
    CSoundDataEntry* FindTriggerVoiceSound(CString strName);      // 0x140818740 ("$name$" is stripped)
    int GetTriggerVoiceLength(CString strName);                   // 0x140818910
    int GetVoiceLength(const CString& strName);                   // 0x1408189b0 event sound under ms2sound/sound/voice
    void SetEventSounds(const SoundList& list);                   // 0x140818a20
    void SetProgrammerSounds(const SoundList& list);              // 0x140818ad0
    void SetTriggerVoiceSounds(const SoundList& list);            // 0x140818b80
    int ParseSection(TiXmlElement* pRoot, const char* pszTag, int nType, SoundMap& map);   // 0x140818c30

    CString m_strPath;                  // +8
    SoundMap m_eventSounds;             // +0x10
    SoundMap m_programmerSounds;        // +0x20
    SoundMap m_triggerVoiceSounds;      // +0x30
};
MS2_CHECK_SIZE(CSoundDataTable, 0x40);
MS2_CHECK_OFFSET(CSoundDataTable, m_triggerVoiceSounds, 0x30);
