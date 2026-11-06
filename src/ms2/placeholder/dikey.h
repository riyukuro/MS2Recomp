// dikey.h - PLACEHOLDER for the client's DirectInput key-code type. NOT an original header. Recovered by ua14.
// The exe keeps a separate std::forward copy for this type (0x140aa5630), distinct from std::forward<int> (0x140180c20).
// It is shared by:
// - ChromaManagerImpl::m_keyboardKeys (map<key, RZKEY>; the tuple / _Try_emplace / forward_as_tuple instances and
//   the private less<> at 0x140aa6bb0);
// - UITypingGameDialog::m_keys (vector<pair<key, key>>: pair ctor 0x140ee62b0, make_pair 0x140ee6a80);
// - UIPlayInstrumentDialog::m_octaveKeys (vector<pair<key, int>>: pair ctor 0x14100fa00, make_pair 0x141013ab0).
// In all of these the key field goes through 0x140aa5630 and an int field through 0x140180c20. The values are DIK_*
// scan codes. The real name is unknown; the type is 4 bytes, so a plain enum is used.
#pragma once

enum Unk_DIKey {};
