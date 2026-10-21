// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\depthoffieldmanager.cpp
// MS2-RANGE: 0x141177ee0-0x141178340 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\depthoffieldmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "depthoffieldmanager.h"
#include "hook/ms2hook.h"

// Unrecovered callees (real types unknown).
void* FUN_1409a8b20();
void* FUN_1409a8b10();
void* FUN_1409a8ac0(void* p);
void* FUN_1409a8c40(void* p);
void* FUN_1414cfbe0(void* p);
void FUN_1414cf920(void* p, unsigned char v);
void* FUN_1416a3a90(void* p, int n);
void FUN_1416a3920(void* p, int n, unsigned char v);
void FUN_1416aa6a0(void* p, int n, unsigned char v);
void FUN_1409a5770(void* obj, void* value, int n);
bool FUN_140c900e0(void* name, void* data, int n);
void* FUN_140c8f690(void* p);
unsigned char FUN_1411782b0(void* p);
void* FUN_1411782c0(void* p, int n);
struct Unk_DOFW { void* FUN_1411782f0(); void* m_0; };
void* FUN_141178310(void* p);
void* FUN_141178320(void* p);
void FUN_1411781e0(void* name, void* data, int n);
void** FUN_141178210(void* a, __int64 idx);
void* FUN_141178240(void** p);
extern char DAT_143ae53a8;
extern char DAT_143ae53b0;
extern char DAT_143ae53b8;
struct Unk_DOFVecA { Unk_DOFVecA(float x, float y); float a, b, c, d; };   // 0x140a0a600
struct Unk_DOFVecB { Unk_DOFVecB(float x, float y); float a, b, c, d; };   // 0x140a0a4c0

// @0x141177ee0
CDepthOfFieldManager::CDepthOfFieldManager() : m_10(0), m_50(1)
{
}

// @0x141177f50
CDepthOfFieldManager::~CDepthOfFieldManager()
{
    m_10 = 0;
}

// @0x141177fa0
void CDepthOfFieldManager::FUN_141177fa0()
{
    m_10 = FUN_1416a3a90(FUN_1409a8b20(), 4);
    FUN_141178020(FUN_1411782b0(FUN_1409a8ac0(FUN_1409a8b10())));
}
MS2_REPLACE_METHOD(0x141177FA0, CDepthOfFieldManager, FUN_141177fa0, 75, 0xEEBEED69);

// @0x141178000
void FUN_141178000(void* a, double b)
{
}

// @0x141178020
void CDepthOfFieldManager::FUN_141178020(unsigned char on)
{
    if (m_10 == 0)
        return;
    m_50 = on;
    FUN_1416a3920(FUN_1409a8b20(), 4, on);
    FUN_1416aa6a0(FUN_1409a8b20(), 1, on);
    Unk_DOFVecA v(1.5f, 1.5f);
    FUN_140c900e0(&DAT_143ae53a8, &v, 1);
}
MS2_REPLACE_METHOD(0x141178020, CDepthOfFieldManager, FUN_141178020, 142, 0x215C81C8);

// @0x1411780c0
unsigned char CDepthOfFieldManager::FUN_1411780c0()
{
    return m_50;
}

// @0x1411780e0
void FUN_1411780e0(void* a, float x, float y)
{
    Unk_DOFVecB v(x, y);
    FUN_1411781e0(&DAT_143ae53b0, &v, 1);
    FUN_1409a5770(&DAT_143ae53b8, &x, 1);
}
MS2_REPLACE(0x1411780E0, FUN_1411780e0, 94, 0xC811E5B5);

// @0x141178150
void FUN_141178150(unsigned char on)
{
    void* a = FUN_1411782c0(FUN_1409a8b20(), 1);
    void* b = FUN_1409a8c40(a);
    void* p = FUN_1414cfbe0(b);
    FUN_1414cf920(FUN_141178240(FUN_141178210(p, 1)), on);
    FUN_1414cf920(FUN_141178240(FUN_141178210(p, 2)), on);
}
MS2_REPLACE(0x141178150, FUN_141178150, 138, 0x939E3141);

// @0x1411781e0
void FUN_1411781e0(void* name, void* data, int n)
{
    FUN_140c900e0(name, data, n);
}

// @0x141178210
void** FUN_141178210(void* a, __int64 idx)
{
    return *(void***)FUN_141178320(a) + idx;
}

// @0x141178240
void* FUN_141178240(void** p)
{
    return *p;
}

// @0x141178250 is the compiler-generated scalar deleting destructor (size 0x58)

// @0x1411782b0
unsigned char FUN_1411782b0(void* p)
{
    return *((unsigned char*)p + 0x1a);
}

// @0x1411782c0
void* FUN_1411782c0(void* p, int n)
{
    return FUN_140c8f690((char*)p + 0xb8 + (__int64)n * 8);
}

// @0x1411782f0
void* Unk_DOFW::FUN_1411782f0()
{
    return FUN_141178310(&m_0);
}

// @0x141178310
void* FUN_141178310(void* p)
{
    return p;
}

// @0x141178320
void* FUN_141178320(void* p)
{
    return ((Unk_DOFW*)p)->FUN_1411782f0();
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x141178000, FUN_141178000, 12, 0x49415BA5);
MS2_REPLACE_METHOD(0x1411780c0, CDepthOfFieldManager, FUN_1411780c0, 15, 0x637A06FD);
MS2_REPLACE(0x1411781e0, FUN_1411781e0, 44, 0x583FFD4D);
MS2_REPLACE(0x141178210, FUN_141178210, 41, 0x02953BDC);
MS2_REPLACE(0x141178240, FUN_141178240, 14, 0x82C92E11);
MS2_REPLACE(0x1411782c0, FUN_1411782c0, 44, 0x1FAF8A83);
MS2_REPLACE_METHOD(0x1411782f0, Unk_DOFW, FUN_1411782f0, 27, 0x3558844D);
MS2_REPLACE(0x141178310, FUN_141178310, 11, 0x3BE09B6E);
MS2_REPLACE(0x141178320, FUN_141178320, 24, 0xD648BDD6);

