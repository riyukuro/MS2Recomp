// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A name-keyed record list (vector of 0x20-byte entries) with its
// packet reader / writer, and the std::vector<entry> glue. Class names are not recovered (Unk_BlockList*).
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_1401ba840
// MS2-RANGE: 0x1401ba840-0x1401bcbf0 .text$mn
// MS2-PIN: memmove_s 0x1401bcad0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <vector>
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"

// 0x20 bytes. ctor 0x1401ba840, name ctor 0x1401ba8b0, dtor 0x1401ba940, Clear 0x1401ba990.
struct Unk_BlockEntry
{
    Unk_BlockEntry();
    Unk_BlockEntry(CStringW strName);
    void Clear();
    CString m_strKey;       // +0x00
    CStringW m_strName;     // +0x08
    CStringW m_strExtra;    // +0x10
    unsigned m_nFlags;      // +0x18
    bool m_bEnabled;        // +0x1c
};
MS2_CHECK_SIZE(Unk_BlockEntry, 0x20);
MS2_CHECK_OFFSET(Unk_BlockEntry, m_nFlags, 0x18);

// 0x28 bytes.
class Unk_BlockList
{
public:
    Unk_BlockList();                                        // 0x1401bb300
    Unk_BlockList(unsigned nId);                            // 0x1401baa00
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
MS2_CHECK_OFFSET(Unk_BlockList, m_nId, 0x18);
MS2_CHECK_OFFSET(Unk_BlockList, m_bEnabled, 0x20);

// @0x1401ba840
Unk_BlockEntry::Unk_BlockEntry()
{
    Clear();
}

// @0x1401ba8b0
Unk_BlockEntry::Unk_BlockEntry(CStringW strName)
{
    Clear();
    m_strName = strName;
}

// @0x1401ba990
void Unk_BlockEntry::Clear()
{
    m_strKey = "";
    m_strName = L"";
    m_strExtra = L"";
    m_nFlags = 0;
    m_bEnabled = false;
}

// @0x1401bb300
Unk_BlockList::Unk_BlockList()
{
}

// @0x1401baa00
Unk_BlockList::Unk_BlockList(unsigned nId)
    : m_nId(nId), m_nMode(0), m_bEnabled(false)
{
}

// @0x1401baa50
Unk_BlockList::Unk_BlockList(unsigned nId, unsigned nMode)
    : m_nId(nId), m_nMode(nMode), m_bEnabled(false)
{
}

// @0x1401baaa0
Unk_BlockList::Unk_BlockList(CInPacket& kPacket)
{
    Read(kPacket);
}

// @0x1401baaf0
Unk_BlockList::~Unk_BlockList()
{
    m_entries.clear();
}

// @0x1401bab20
unsigned Unk_BlockList::GetId()
{
    return m_nId;
}

// @0x1401bab40
unsigned Unk_BlockList::GetMode()
{
    return m_nMode;
}

// @0x1401bab60
unsigned short Unk_BlockList::GetCount()
{
    return (unsigned short)m_entries.size();
}

// @0x1401bab90
bool Unk_BlockList::Find(CString strKey, Unk_BlockEntry& kResult)
{
    for (std::vector<Unk_BlockEntry>::iterator it = m_entries.begin(); it != m_entries.end(); it++)
    {
        if (it->m_strKey.Compare(strKey) == 0)
        {
            kResult = *it;
            return true;
        }
    }
    return false;
}

// @0x1401bac80
bool Unk_BlockList::Add(CString strKey, CStringW strName, bool bEnabled)
{
    Unk_BlockEntry kEntry;
    if (Find(strKey, kEntry) == true)
        return false;
    kEntry.m_strKey = strKey;
    kEntry.m_strName = strName;
    kEntry.m_strExtra.Empty();
    kEntry.m_nFlags = 0;
    kEntry.m_bEnabled = bEnabled;
    m_entries.push_back(kEntry);
    return true;
}

// @0x1401badc0
void Unk_BlockList::SetEnabled(bool bEnabled)
{
    m_bEnabled = bEnabled;
}

// @0x1401bade0
void Unk_BlockList::Write(COutputStream& kStream)
{
    kStream.WriteInt32(GetId());
    kStream.WriteInt32(GetMode());
    kStream.WriteBool(m_bEnabled);
    kStream.WriteInt16(GetCount());
    for (std::vector<Unk_BlockEntry>::iterator it = m_entries.begin(); it != m_entries.end(); it++)
    {
        kStream.WriteString(it->m_strKey);
        kStream.WriteUnicodeString(it->m_strName);
        kStream.WriteUnicodeString(it->m_strExtra);
        kStream.WriteUInt8((unsigned char)it->m_nFlags);
        kStream.WriteBool(it->m_bEnabled);
    }
}

// @0x1401bb000
void Unk_BlockList::Read(CInPacket& kPacket)
{
    m_entries.clear();
    m_nId = kPacket.ReadInt32();
    m_nMode = kPacket.ReadInt32();
    m_bEnabled = kPacket.ReadBool();
    unsigned short nCount = kPacket.ReadInt16();
    for (unsigned short i = 0; i < nCount; ++i)
    {
        Unk_BlockEntry kEntry;
        kEntry.m_strKey = kPacket.ReadString();
        kEntry.m_strName = kPacket.ReadUnicodeString();
        kEntry.m_strExtra = kPacket.ReadUnicodeString();
        kEntry.m_nFlags = kPacket.ReadUInt8();
        kEntry.m_bEnabled = kPacket.ReadBool();
        m_entries.push_back(kEntry);
    }
}

// ---- trailing CRT inline ----

// The UCRT header-inline memmove_s (corecrt_memcpy_s.h) ends the unit; the pointer keeps the unreferenced COMDAT.
// @0x1401bcad0
__declspec(selectany) extern errno_t(__cdecl* const g_pBlockListMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;
