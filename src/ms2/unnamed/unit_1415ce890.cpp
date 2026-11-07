// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Two more small wrapper helpers from the
// unnamed boxed-pointer TU: the first forwards a value to an identity thunk and re-initialises the
// 0x18-byte object it is given; the second wraps one argument through the same thunk and forwards it.
// MS2-UNIT: unit_1415ce890
// MS2-RANGE: 0x1415ce890-0x1415ce910 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

// Unrecovered callees: FUN_1415e4f30 is the identity getter thunk (mov rax,rcx; ret); FUN_1415e77b0
// zero-initialises the 0x18-byte object it is given and returns it.
extern void* FUN_1415e4f30(void* p);
extern void* FUN_1415e77b0(void* p);

// The pair the two helpers build, as constructors: an empty tag type passed by value, the forwarded argument
// (empty, so only the forwarding call remains) and the 0x18-byte value member built through its address.
struct Tag_1415ce890 {};
struct Unk_1415ce890
{
    char m_val[0x18];
    Unk_1415ce890(Tag_1415ce890, void* v);
};
struct Unk_1415ce8d0
{
    Unk_1415ce890 m_pair;
    Unk_1415ce8d0(void* v);
};

// @0x1415ce890
Unk_1415ce890::Unk_1415ce890(Tag_1415ce890, void* v)
{
    FUN_1415e4f30(v);
    FUN_1415e77b0(&m_val);
}

// @0x1415ce8d0
Unk_1415ce8d0::Unk_1415ce8d0(void* v) : m_pair(Tag_1415ce890(), FUN_1415e4f30(v))
{
}
