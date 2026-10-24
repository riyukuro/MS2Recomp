// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). RemakeOptionContext: CPtred-derived context of an item
// option remake (class name from RTTI, vftable 0x142d15a38; ??_G in another unit). Layout from the ctor 0x140267390,
// copy ctor 0x140267460 and dtor 0x1402675b0 (hint: work/ext/v2525 RemakeOptionContext.h). Member names invented.
// MS2-UNIT: unit_140267390
// MS2-RANGE: 0x140267390-0x140267670 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

// Refcounted-pointer wrapper (commonstruct_2.cpp Unk_Ref16 instantiation; dtor 0x14027e030 is shared with
// MS2Ptr<CItemOption>). The members are the exe's out-of-line copies in commonstruct_2.cpp.
struct Unk_RemakeOptionRef {
    Unk_RemakeOptionRef();                                          // 0x14027cb50
    Unk_RemakeOptionRef(int nNull);                                 // 0x14027cb30
    ~Unk_RemakeOptionRef();                                         // 0x14027e030
    Unk_RemakeOptionRef& operator=(const Unk_RemakeOptionRef& o);   // 0x14027ea40
    Unk_RemakeOptionRef& operator=(int nNull);                      // 0x14027ea80
    void* m_unknown;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_RemakeOptionRef, 0x10);

// std::vector of 8-byte values (v2525: _Buy multiplies the count by 8).
struct Unk_RemakeOptionList50 {
    Unk_RemakeOptionList50();                                       // 0x14027d690
    ~Unk_RemakeOptionList50();                                      // 0x14027e3f0
    Unk_RemakeOptionList50& operator=(const Unk_RemakeOptionList50& o); // 0x14027eb30
    void* m_p[3];
};
MS2_CHECK_SIZE(Unk_RemakeOptionList50, 0x18);

// std::vector of 16-byte refcounted handles.
struct Unk_RemakeOptionList68 {
    Unk_RemakeOptionList68();                                       // 0x14027d750
    ~Unk_RemakeOptionList68();                                      // 0x14027e4b0
    Unk_RemakeOptionList68& operator=(const Unk_RemakeOptionList68& o); // 0x14027ebb0
    void clear();                                                   // 0x14028a690
    void* m_p[3];
};
MS2_CHECK_SIZE(Unk_RemakeOptionList68, 0x18);

class RemakeOptionContext : public CPtred
{
public:
    RemakeOptionContext();
    RemakeOptionContext(const RemakeOptionContext& other);
    virtual ~RemakeOptionContext();

    int m_value18;                      // +0x18
    int m_value1c;                      // +0x1c
    __int64 m_value20;                  // +0x20
    Unk_RemakeOptionRef m_option28;     // +0x28
    Unk_RemakeOptionRef m_option38;     // +0x38
    int m_value48;                      // +0x48
    int m_value4c;                      // +0x4c
    Unk_RemakeOptionList50 m_list50;    // +0x50
    Unk_RemakeOptionList68 m_list68;    // +0x68
};
MS2_CHECK_SIZE(RemakeOptionContext, 0x80);
MS2_CHECK_OFFSET(RemakeOptionContext, m_option28, 0x28);
MS2_CHECK_OFFSET(RemakeOptionContext, m_list68, 0x68);

// @0x140267390
// MS2-FUNCTIONAL: the exe has no EH-state nop after the m_option38 / m_list50 ctor calls (m_option28 has one, same callee)
RemakeOptionContext::RemakeOptionContext()
    : m_value18(0), m_value1c(0), m_value20(0), m_option28(0), m_option38(0), m_value48(1), m_value4c(1)
{
}

// @0x140267460
RemakeOptionContext::RemakeOptionContext(const RemakeOptionContext& other)
{
    m_value18 = other.m_value18;
    m_value1c = other.m_value1c;
    m_value20 = other.m_value20;
    m_option28 = other.m_option28;
    m_option38 = other.m_option38;
    m_value48 = other.m_value48;
    m_value4c = other.m_value4c;
    m_list50 = other.m_list50;
    m_list68 = other.m_list68;
}

// @0x1402675b0
RemakeOptionContext::~RemakeOptionContext()
{
    m_option28 = 0;
    m_option38 = 0;
    m_list68.clear();
}
