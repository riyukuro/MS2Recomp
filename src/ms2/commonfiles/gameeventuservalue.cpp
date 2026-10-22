// gameeventuservalue.cpp - GameEventVariable / GameEventUserValue: the keyed, time-stamped event values of a user.
//
// MS2-UNIT: commonfiles\gameeventuservalue.cpp
// MS2-RANGE: 0x14041eeb0-0x140421740 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventuservalue.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gameeventuservalue.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit helpers.
unsigned __int64 FUN_140869440();       // the server time
CStringW FUN_140719900(CStringW value); // normalises a user value string (commonutil)

// ---- GameEventVariable::Key ----

// @0x14041eeb0
GameEventVariable::Key::Key() : m_type(0), m_id(0) {}
// @0x14041eee0
GameEventVariable::Key::Key(int type, unsigned int id) : m_type(type), m_id(id) {}
// @0x14041ef20
bool GameEventVariable::Key::operator<(const Key& other) const
{
    if (m_type == other.m_type)
        return m_id < other.m_id;
    return m_type < other.m_type;
}
// @0x14041efa0
bool GameEventVariable::Key::operator>(const Key& other) const
{
    if (*this == other)
        return false;
    return !(*this < other);
}
// @0x14041f000
bool GameEventVariable::Key::operator==(const Key& other) const
{
    return m_type == other.m_type && m_id == other.m_id;
}
// @0x14041f050
void GameEventVariable::Key::Write(COutputStream* stream)
{
    stream->WriteInt32(m_type);
    stream->WriteInt32(m_id);
}
// @0x14041f0a0
void GameEventVariable::Key::Read(CInPacket& packet)
{
    m_type = packet.ReadInt32();
    m_id = packet.ReadInt32();
}

// ---- GameEventVariable ----

// @0x14041f110
GameEventVariable::GameEventVariable() : m_dirty(false) {}
// @0x14041f190
GameEventVariable::GameEventVariable(const Key& key, const CStringW& value, const CMsTime& time, bool dirty)
    : m_key(key), m_value(value), m_time(time), m_dirty(dirty)
{
}
// @0x14041f230
GameEventVariable::Key& GameEventVariable::GetKey() { return m_key; }
// @0x14041f250
int GameEventVariable::GetType() { return m_key.m_type; }
// @0x14041f270
void GameEventVariable::Write(COutputStream* stream)
{
    m_key.Write(stream);
    stream->WriteUnicodeString(m_value);
    stream->WriteInt64(m_time.Get());
}
// @0x14041f300
void GameEventVariable::Read(CInPacket& packet)
{
    m_key.Read(packet);
    m_value = packet.ReadUnicodeString();
    m_time = CMsTime(packet.ReadInt64());
}
// @0x14041f3e0
void GameEventVariable::SetValue(const CStringW& value)
{
    if (m_value == value)
        return;
    m_value = value;
    SetDirty(true);
}
// @0x14041f440
void GameEventVariable::SetValue(const CStringW& value, const CMsTime& time)
{
    if (m_value == value && m_time == time)
        return;
    m_value = value;
    m_time = time;
    SetDirty(true);
}
// @0x14041f4e0
void GameEventVariable::SetDirty(bool dirty) { m_dirty = dirty; }
// @0x14041f500
bool GameEventVariable::IsDirty() { return m_dirty; }
// @0x14041f520
bool GameEventVariable::IsEmpty() { return m_value.IsEmpty(); }

// ---- GameEventUserValue ----

// @0x14041f550
GameEventUserValue::GameEventUserValue() : m_variables(10) {}

static void CopyVariables(GameEventUserValue::VariableMap& dst, const GameEventUserValue::VariableMap& src);

// @0x14041f5a0
void GameEventUserValue::Merge(const VariableMap& variables) { CopyVariables(m_variables, variables); }

// @0x14041f5d0
void GameEventUserValue::ExpireAll()
{
    CMsTime now(FUN_140869440());
    for (POSITION pos = m_variables.GetHeadPosition(); pos != NULL; m_variables.GetNext(pos))
    {
        VariablePtr pVar = m_variables.GetValueAt(pos);
        MS2_ASSERT_AT(0x93, pVar != NULL);
        pVar->SetValue(L"", now);
    }
}

// @0x14041f6e0
void GameEventUserValue::Clear() { m_variables.RemoveAll(); }

// @0x14041f710
void GameEventUserValue::Write(COutputStream* stream)
{
    stream->WriteInt32((int)m_variables.GetCount());
    for (POSITION pos = m_variables.GetHeadPosition(); pos != NULL; m_variables.GetNext(pos))
    {
        VariablePtr& variable = m_variables.GetValueAt(pos);
        variable->Write(stream);
    }
}

// @0x14041f7c0
void GameEventUserValue::Read(CInPacket& packet)
{
    Clear();
    unsigned int count = packet.ReadInt32();
    for (unsigned int i = 0; i < count; ++i)
        ReadVariable(packet);
}

// @0x14041f850
GameEventUserValue::VariablePtr GameEventUserValue::ReadVariable(CInPacket& packet)
{
    VariablePtr variable(new GameEventVariable);
    variable->Read(packet);
    m_variables.SetAt(variable->GetKey(), variable);
    return variable;
}

// @0x14041f940
bool GameEventUserValue::Has(int type) { return Has(type, 0); }
// @0x14041f970
void GameEventUserValue::Reset(int type) { Reset(type, 0); }
// @0x14041f9a0
bool GameEventUserValue::GetTime(int type, CMsTime* time) { return GetTime(type, 0, time); }

// @0x14041f9e0
bool GameEventUserValue::Has(int type, unsigned int id) { return Get(type, id).get() != 0; }

// @0x14041fa70
void GameEventUserValue::Reset(int type, unsigned int id)
{
    CMsTime now(FUN_140869440());
    Set(type, id, CStringW(L""), now);
}

// @0x14041faf0
bool GameEventUserValue::GetTime(int type, unsigned int id, CMsTime* time)
{
    VariablePtr variable = Get(type, id);
    if (variable == 0)
        return false;
    *time = variable->m_time;
    return true;
}

// @0x14041fb90
void GameEventUserValue::Insert(VariablePtr variable) { m_variables.SetAt(variable->GetKey(), variable); }

// @0x14041fbf0
void GameEventUserValue::OnChanged(VariablePtr variable) {}

// @0x14041fc20
GameEventUserValue::VariablePtr GameEventUserValue::Get(int type, unsigned int id)
{
    GameEventVariable::Key key(type, id);
    VariableMap::CPair* pair = m_variables.Lookup(key);
    if (pair == NULL)
        return VariablePtr(0);
    CMsTime now(FUN_140869440());
    if (pair->m_value->m_time <= now)
        return VariablePtr(0);
    return pair->m_value;
}

// @0x14041fd20
static void CopyVariables(GameEventUserValue::VariableMap& dst, const GameEventUserValue::VariableMap& src)
{
    for (POSITION pos = src.GetHeadPosition(); pos != NULL; src.GetNext(pos))
        dst.SetAt(src.GetKeyAt(pos), src.GetValueAt(pos));
}

// @0x14041fda0
void GameEventUserValue::Set(int type, unsigned int id, CStringW value, const CMsTime& time)
{
    GameEventVariable::Key key(type, id);
    VariablePtr variable;
    if (m_variables.Lookup(key, variable))
    {
        variable->SetValue(FUN_140719900(value), time);
    }
    else
    {
        variable.AssignRaw(new GameEventVariable(key, FUN_140719900(value), time, true));
        m_variables.SetAt(variable->GetKey(), variable);
    }
    OnChanged(variable);
}
