// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Template glue over types the exe does not name here: three
// _Enable_shared_from_this1 (non-enabled overload, the empty bodies) with their three callers, and two 8-byte-element
// iterator operator+= copies. Each family uses its own stand-in type.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_1410dc420
// MS2-RANGE: 0x1410dc420-0x1410dc570 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <memory>
#include "ms2/ms2recover.h"

template <int N> struct Unk_Shared { int v[N + 1]; };
struct Unk_Flag { char c; };

template <int N> struct Unk_EnableGlue
{
    // empty body of _Enable_shared_from_this1 (false_type overload)
    static void Enable1(const std::shared_ptr<Unk_Shared<N> >&, Unk_Shared<N>*, Unk_Flag) {}
};

template <int N> struct Unk_Iter
{
    unsigned __int64* m_p;
    void operator+=(__int64 n) { m_p += n; }
};

// @0x1410dc420
// @0x1410dc430
// @0x1410dc440
__declspec(selectany) extern void (* const ms2_unk_glue[])() = {
    (void (*)())&Unk_EnableGlue<1>::Enable1,
    (void (*)())&Unk_EnableGlue<2>::Enable1,
    (void (*)())&Unk_EnableGlue<3>::Enable1,
};
// @0x1410dc450
void Unk_Enable1(const std::shared_ptr<Unk_Shared<1> >& sp, Unk_Shared<1>* p) { Unk_EnableGlue<1>::Enable1(sp, p, Unk_Flag()); }
// @0x1410dc490
void Unk_Enable2(const std::shared_ptr<Unk_Shared<2> >& sp, Unk_Shared<2>* p) { Unk_EnableGlue<2>::Enable1(sp, p, Unk_Flag()); }
// @0x1410dc4d0
void Unk_Enable3(const std::shared_ptr<Unk_Shared<3> >& sp, Unk_Shared<3>* p) { Unk_EnableGlue<3>::Enable1(sp, p, Unk_Flag()); }
// @0x1410dc510
void Unk_IterAdd1(Unk_Iter<1>& it, __int64 n, char) { it.m_p += n; }
// @0x1410dc540
void Unk_IterAdd2(Unk_Iter<2>& it, __int64 n, char) { it.m_p += n; }
