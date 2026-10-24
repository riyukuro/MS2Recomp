// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUserLimitHistory serialization and state initialization.
// MS2-UNIT: unit_140269160
// MS2-RANGE: 0x140269160-0x140269440 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"

class CUserLimitArchive
{
public:
    virtual void Slot0() = 0;
    virtual void Transfer32(unsigned int& value) = 0; // byte offset 0x08
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Transfer64(unsigned __int64& value) = 0; // byte offset 0x20
};

class CUserLimitHistory
{
public:
    CUserLimitHistory();
    void Initialize();
    void Serialize(CUserLimitArchive& archive);
    void Deserialize(CUserLimitArchive& archive);
    void* m_vftable;
    char m_base[0x10];
    unsigned __int64 m_value18;
    unsigned __int64 m_value20;
    unsigned __int64 m_value28;
    unsigned int m_value30;
    unsigned int m_pad34;
    unsigned __int64 m_value38;
    unsigned int m_value40;
    unsigned int m_pad44;
    unsigned __int64 m_value48;
};
MS2_CHECK_SIZE(CUserLimitHistory, 0x50);

// @0x140269160
CUserLimitHistory::CUserLimitHistory() : m_vftable(nullptr), m_base{}
{
    Initialize();
}

// @0x1402691b0
void CUserLimitHistory::Initialize()
{
    m_value18 = 0;
    m_value20 = 0;
    m_value28 = 0;
    m_value30 = 0;
    m_value38 = 0;
    m_value40 = 0;
    m_value48 = 0;
}

// @0x140269220
void CUserLimitHistory::Serialize(CUserLimitArchive& archive)
{
    archive.Transfer64(m_value18);
    archive.Transfer64(m_value20);
    archive.Transfer64(m_value28);
    archive.Transfer32(m_value30);
    archive.Transfer64(m_value38);
    archive.Transfer32(m_value40);
    archive.Transfer64(m_value48);
}

// @0x1402692f0
void CUserLimitHistory::Deserialize(CUserLimitArchive& archive)
{
    archive.Transfer64(m_value18);
    archive.Transfer64(m_value20);
    archive.Transfer64(m_value28);
    archive.Transfer32(m_value30);
    archive.Transfer64(m_value38);
    archive.Transfer32(m_value40);
    archive.Transfer64(m_value48);
}
