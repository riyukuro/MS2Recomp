// unk_blocklist.h - PLACEHOLDER (not an original header) for the name-keyed text list that the UI hands to the
// network callbacks' slot 37 (0x128) for the ban-word / text check of input boxes ("m_inputSearch" etc.): a vector of
// 0x20-byte entries plus the dialog's UI id. Class names are not recovered; the bodies are unit_1401ba840
// (0x1401ba840-0x1401bcbf0), which defines the same two classes locally (keep the declarations identical).
// Other units declare it as Unk_ScRequest / Unk_AcRequest (uiskillcompactcontroldialog, uiachievedialog).
#pragma once
#include <afx.h>
#include <vector>
#include "ms2/ms2layout.h"

class CInPacket;
class COutputStream;

// 0x20 bytes. ctor 0x1401ba840, name ctor 0x1401ba8b0, dtor 0x1401ba940, Clear 0x1401ba990.
struct Unk_BlockEntry
{
    Unk_BlockEntry();
    Unk_BlockEntry(CStringW strName);
    void Clear();
    CString m_strKey;       // +0x00 the control name
    CStringW m_strName;     // +0x08 the text
    CStringW m_strExtra;    // +0x10
    unsigned m_nFlags;      // +0x18
    bool m_bEnabled;        // +0x1c
};
MS2_CHECK_SIZE(Unk_BlockEntry, 0x20);

// 0x28 bytes.
class Unk_BlockList
{
public:
    Unk_BlockList();                                        // 0x1401bb300
    Unk_BlockList(unsigned nId);                            // 0x1401baa00 nId: the dialog's UI id
    Unk_BlockList(unsigned nId, unsigned nMode);            // 0x1401baa50
    Unk_BlockList(CInPacket& kPacket);                      // 0x1401baaa0
    ~Unk_BlockList();                                       // 0x1401baaf0
    unsigned GetId();                                       // 0x1401bab20
    unsigned GetMode();                                     // 0x1401bab40
    unsigned short GetCount();                              // 0x1401bab60
    bool Find(CString strKey, Unk_BlockEntry& kResult);     // 0x1401bab90
    bool Add(CString strKey, CStringW strName, bool bEnabled);   // 0x1401bac80
    void SetEnabled(bool bEnabled);                         // 0x1401badc0
    void Write(COutputStream& kStream);                     // 0x1401bade0
    void Read(CInPacket& kPacket);                          // 0x1401bb000

    std::vector<Unk_BlockEntry> m_entries;                  // +0x00
    unsigned m_nId;                                         // +0x18
    unsigned m_nMode;                                       // +0x1c
    bool m_bEnabled;                                        // +0x20
};
MS2_CHECK_SIZE(Unk_BlockList, 0x28);
