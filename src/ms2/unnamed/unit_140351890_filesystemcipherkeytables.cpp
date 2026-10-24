// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Setup/teardown of the file-system cipher key tables (the
// 128 per-slot keys/IVs are XOR-combined from the static tables into heap blocks) plus the XOR helper and the CRT
// memmove_s copy that ends the range.
// MS2-UNIT: unit_140351890
// MS2-RANGE: 0x140351890-0x140352350 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Static key tables (32-byte key rows alternate with 16-byte IV rows), the six heap tables derived from them.
extern unsigned char DAT_1439ed030[128][32];
extern unsigned char DAT_1439ee030[128][16];
extern unsigned char DAT_1439ee830[128][32];
extern unsigned char DAT_1439ef830[128][16];
extern unsigned char DAT_1439f0030[128][32];
extern unsigned char DAT_1439f1030[128][16];
extern unsigned char DAT_1439f1830[128][32];
extern unsigned char DAT_1439f2830[128][16];
extern unsigned char DAT_1439f3030[2048];
extern unsigned char DAT_1439f3830[2048];
extern unsigned char DAT_1439f4030[2048];
extern unsigned char DAT_143aad2d0[2048];
extern unsigned char DAT_143aadad0[2048];
extern unsigned char DAT_143aae2d0[2048];
extern unsigned char** DAT_143aaead0;
extern unsigned char** DAT_143aaead8;
extern unsigned char** DAT_143aaeae0;
extern unsigned char** DAT_143aaeae8;
extern unsigned char** DAT_143aaeaf0;
extern unsigned char** DAT_143aaeaf8;

void FUN_140352130(const unsigned char* a, const unsigned char* b, unsigned char* out, unsigned int count);

// @0x140351890
void FUN_140351890()
{
    if (DAT_143aaead0 == 0)
    {
        DAT_143aaead0 = (unsigned char**)new unsigned char[0x400];
        for (unsigned int i = 0; i < 0x80; i++)
        {
            DAT_143aaead0[i] = new unsigned char[0x20];
        }
        for (unsigned int j = 0; j < 0x80; j++)
        {
            FUN_140352130(DAT_1439ed030[j], DAT_1439ee830[j], DAT_143aaead0[j], 0x20);
        }
    }
    if (DAT_143aaead8 == 0)
    {
        DAT_143aaead8 = (unsigned char**)new unsigned char[0x400];
        for (unsigned int i = 0; i < 0x80; i++)
        {
            DAT_143aaead8[i] = new unsigned char[0x10];
        }
        for (unsigned int j = 0; j < 0x80; j++)
        {
            FUN_140352130(DAT_1439ee030[j], DAT_1439ef830[j], DAT_143aaead8[j], 0x10);
        }
    }
    if (DAT_143aaeae0 == 0)
    {
        DAT_143aaeae0 = (unsigned char**)new unsigned char[0x400];
        for (unsigned int i = 0; i < 0x80; i++)
        {
            DAT_143aaeae0[i] = new unsigned char[0x20];
        }
        for (unsigned int j = 0; j < 0x80; j++)
        {
            FUN_140352130(DAT_1439ee830[j], DAT_1439f0030[j], DAT_143aaeae0[j], 0x20);
        }
    }
    if (DAT_143aaeae8 == 0)
    {
        DAT_143aaeae8 = (unsigned char**)new unsigned char[0x400];
        for (unsigned int i = 0; i < 0x80; i++)
        {
            DAT_143aaeae8[i] = new unsigned char[0x10];
        }
        for (unsigned int j = 0; j < 0x80; j++)
        {
            FUN_140352130(DAT_1439ef830[j], DAT_1439f1030[j], DAT_143aaeae8[j], 0x10);
        }
    }
    if (DAT_143aaeaf0 == 0)
    {
        DAT_143aaeaf0 = (unsigned char**)new unsigned char[0x400];
        for (unsigned int i = 0; i < 0x80; i++)
        {
            DAT_143aaeaf0[i] = new unsigned char[0x20];
        }
        for (unsigned int j = 0; j < 0x80; j++)
        {
            FUN_140352130(DAT_1439f0030[j], DAT_1439f1830[j], DAT_143aaeaf0[j], 0x20);
        }
    }
    if (DAT_143aaeaf8 == 0)
    {
        DAT_143aaeaf8 = (unsigned char**)new unsigned char[0x400];
        for (unsigned int i = 0; i < 0x80; i++)
        {
            DAT_143aaeaf8[i] = new unsigned char[0x10];
        }
        for (unsigned int j = 0; j < 0x80; j++)
        {
            FUN_140352130(DAT_1439f1030[j], DAT_1439f2830[j], DAT_143aaeaf8[j], 0x10);
        }
    }
    FUN_140352130(DAT_1439f3030, DAT_1439f3830, DAT_143aad2d0, 0x800);
    FUN_140352130(DAT_1439f3830, DAT_1439f4030, DAT_143aadad0, 0x800);
    FUN_140352130(DAT_1439f4030, DAT_1439f3030, DAT_143aae2d0, 0x800);
}
MS2_REPLACE(0x140351890, FUN_140351890, 1527, 0xAE1F3259);

// @0x140351e90
void FUN_140351e90()
{
    if (DAT_143aaead0 != 0)
    {
        for (unsigned int i = 0; i < 0x80; i++)
        {
            delete[] DAT_143aaead0[i];
        }
        delete[] DAT_143aaead0;
        DAT_143aaead0 = 0;
    }
    if (DAT_143aaead8 != 0)
    {
        for (unsigned int i = 0; i < 0x80; i++)
        {
            delete[] DAT_143aaead8[i];
        }
        delete[] DAT_143aaead8;
        DAT_143aaead8 = 0;
    }
    if (DAT_143aaeae0 != 0)
    {
        for (unsigned int i = 0; i < 0x80; i++)
        {
            delete[] DAT_143aaeae0[i];
        }
        delete[] DAT_143aaeae0;
        DAT_143aaeae0 = 0;
    }
    if (DAT_143aaeae8 != 0)
    {
        for (unsigned int i = 0; i < 0x80; i++)
        {
            delete[] DAT_143aaeae8[i];
        }
        delete[] DAT_143aaeae8;
        DAT_143aaeae8 = 0;
    }
    if (DAT_143aaeaf0 != 0)
    {
        for (unsigned int i = 0; i < 0x80; i++)
        {
            delete[] DAT_143aaeaf0[i];
        }
        delete[] DAT_143aaeaf0;
        DAT_143aaeaf0 = 0;
    }
    if (DAT_143aaeaf8 != 0)
    {
        for (unsigned int i = 0; i < 0x80; i++)
        {
            delete[] DAT_143aaeaf8[i];
        }
        delete[] DAT_143aaeaf8;
        DAT_143aaeaf8 = 0;
    }
}
MS2_REPLACE(0x140351E90, FUN_140351e90, 663, 0xB9E5C11F);

// @0x140352130 out[i] = a[i] ^ b[i] over count bytes (dword loop, then the byte tail).
void FUN_140352130(const unsigned char* a, const unsigned char* b, unsigned char* out, unsigned int count)
{
    unsigned int i;
    unsigned int words = count >> 2;
    unsigned int tail = count & 3;
    const unsigned int* pa = (const unsigned int*)a;
    const unsigned int* pb = (const unsigned int*)b;
    unsigned int* po = (unsigned int*)out;
    for (i = 0; i < words; i++)
    {
        po[i] = pa[i] ^ pb[i];
    }
    i = i * 4;
    for (unsigned int j = 0; j < tail; j++)
    {
        out[i + j] = a[i + j] ^ b[i + j];
    }
}
MS2_REPLACE(0x140352130, FUN_140352130, 253, 0xACFC606B);

// @0x140352230
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
