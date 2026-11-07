// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Two more small wrapper helpers from the
// unnamed boxed-pointer TU: the first forwards a value to an identity thunk and re-initialises the
// 0x18-byte object it is given; the second wraps one argument through the same thunk and forwards it.
// MS2-UNIT: unit_1415ce610
// MS2-RANGE: 0x1415ce610-0x1415ce690 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

// Unrecovered callees: FUN_1415e4ee0 is the identity getter thunk (mov rax,rcx; ret); FUN_1415e74f0
// zero-initialises the 0x18-byte object it is given and returns it.
extern void* FUN_1415e4ee0(void* p);
extern void* FUN_1415e74f0(void* p);

// The pair the two helpers build, as constructors: an empty tag type passed by value, the forwarded argument
// (empty, so only the forwarding call remains) and the 0x18-byte value member built through its address.
struct Tag_1415ce610 {};
struct Unk_1415ce610
{
    char m_val[0x18];
    Unk_1415ce610(Tag_1415ce610, void* v);
};
struct Unk_1415ce650
{
    Unk_1415ce610 m_pair;
    Unk_1415ce650(void* v);
};

// @0x1415ce610
Unk_1415ce610::Unk_1415ce610(Tag_1415ce610, void* v)
{
    FUN_1415e4ee0(v);
    FUN_1415e74f0(&m_val);
}

// @0x1415ce650
Unk_1415ce650::Unk_1415ce650(void* v) : m_pair(Tag_1415ce610(), FUN_1415e4ee0(v))
{
}
