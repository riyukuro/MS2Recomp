// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A second MD5 (RFC 1321 reference structure) beside CMD5Checksum:
// the hex-string helpers and the hasher object. Class and member names are invented from use.
// MS2-UNIT: unit_140695130
// MS2-RANGE: 0x140695130-0x140696e00 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <stdio.h>
#include <string.h>
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// 0x68 bytes: the digest sits behind the 64-byte block buffer.
class Unk_Md5
{
public:
    Unk_Md5();                                                  // 0x140696ae0
    void Init();                                                // 0x140695320
    void Update(const unsigned char* pInput, unsigned nLen);    // 0x1406953a0
    void Final();                                               // 0x140695550
    void Transform(const unsigned char* pBlock);                // 0x140695680
    void Encode(unsigned char* pOut, const unsigned* pIn, unsigned nLen);   // 0x140696950
    void Decode(unsigned* pOut, const unsigned char* pIn, unsigned nLen);   // 0x140696a30
    const unsigned char* Digest();                              // 0x140696b00
    unsigned F(unsigned x, unsigned y, unsigned z);             // 0x140696b10
    unsigned G(unsigned x, unsigned y, unsigned z);             // 0x140696bc0
    unsigned H(unsigned x, unsigned y, unsigned z);             // 0x140696c70
    unsigned I(unsigned x, unsigned y, unsigned z);             // 0x140696d20
    void FF(unsigned& a, unsigned b, unsigned c, unsigned d, unsigned x, int s, unsigned ac);    // 0x140696b40
    void GG(unsigned& a, unsigned b, unsigned c, unsigned d, unsigned x, int s, unsigned ac);    // 0x140696bf0
    void HH(unsigned& a, unsigned b, unsigned c, unsigned d, unsigned x, int s, unsigned ac);    // 0x140696ca0
    void II(unsigned& a, unsigned b, unsigned c, unsigned d, unsigned x, int s, unsigned ac);    // 0x140696d50
    unsigned RotateLeft(unsigned x, int n);                     // 0x140696dd0

    unsigned m_state[4];                                        // +0x00
    unsigned m_count[2];                                        // +0x10 bit count, low word first
    unsigned char m_buffer[64];                                 // +0x18
    unsigned char m_digest[16];                                 // +0x58
};
MS2_CHECK_SIZE(Unk_Md5, 0x68);

static const unsigned char s_padding[64] = {0x80};            // the exe's table is DAT_1439f4850

// @0x140695130
CString FUN_140695130(const unsigned char* pDigest)
{
    int i;
    unsigned nUnused = 0;
    char szHex[256];
    char szByte[24];
    memset(szHex, 0, sizeof(szHex));
    memset(szByte, 0, 10);
    for (i = 0; i < 16; i++)
    {
        sprintf(szByte, "%02x", pDigest[i]);
        strncat(szHex, szByte, 10);
    }
    CString strHex(szHex);
    return strHex;
}

// @0x140695240
// MS2-FUNCTIONAL: the exe measures the string with an inlined length loop into a four-field temp; frame layout differs
CString FUN_140695240(const char* pszText)
{
    Unk_Md5 md5;
    unsigned nLen = (unsigned)strlen(pszText);
    md5.Update((const unsigned char*)pszText, nLen);
    md5.Final();
    return FUN_140695130(md5.Digest());
}

// @0x140696ae0
Unk_Md5::Unk_Md5()
{
    Init();
}

// @0x140695320
void Unk_Md5::Init()
{
    memset(&m_count, 0, 8);
    m_state[0] = 0x67452301;
    m_state[1] = 0xefcdab89;
    m_state[2] = 0x98badcfe;
    m_state[3] = 0x10325476;
}

// @0x1406953a0
void Unk_Md5::Update(const unsigned char* pInput, unsigned nLen)
{
    unsigned i;
    unsigned nIndex = (m_count[0] >> 3) & 0x3f;
    m_count[0] += nLen << 3;
    if (m_count[0] < (nLen << 3))
        m_count[1]++;
    m_count[1] += nLen >> 29;
    unsigned nPartLen = 64 - nIndex;
    if (nLen >= nPartLen)
    {
        memcpy(&m_buffer[nIndex], pInput, nPartLen);
        Transform(m_buffer);
        for (i = nPartLen; i + 63 < nLen; i += 64)
            Transform(&pInput[i]);
        nIndex = 0;
    }
    else
        i = 0;
    memcpy(&m_buffer[nIndex], &pInput[i], nLen - i);
}

// @0x140695550
void Unk_Md5::Final()
{
    unsigned char bits[8];
    Encode(bits, m_count, 8);
    unsigned nIndex = (m_count[0] >> 3) & 0x3f;
    unsigned nPadLen = nIndex < 56 ? 56 - nIndex : 120 - nIndex;
    Update(s_padding, nPadLen);
    Update(bits, 8);
    Encode(m_digest, m_state, 16);
    memset(m_count, 0, 8);
    memset(m_state, 0, 16);
    memset(m_buffer, 0, 64);
}

// @0x140695680
void Unk_Md5::Transform(const unsigned char* pBlock)
{
    unsigned a = m_state[0];
    unsigned b = m_state[1];
    unsigned c = m_state[2];
    unsigned d = m_state[3];
    unsigned x[16];
    Decode(x, pBlock, 64);
    FF(a, b, c, d, x[0], 7, 0xd76aa478);
    FF(d, a, b, c, x[1], 12, 0xe8c7b756);
    FF(c, d, a, b, x[2], 17, 0x242070db);
    FF(b, c, d, a, x[3], 22, 0xc1bdceee);
    FF(a, b, c, d, x[4], 7, 0xf57c0faf);
    FF(d, a, b, c, x[5], 12, 0x4787c62a);
    FF(c, d, a, b, x[6], 17, 0xa8304613);
    FF(b, c, d, a, x[7], 22, 0xfd469501);
    FF(a, b, c, d, x[8], 7, 0x698098d8);
    FF(d, a, b, c, x[9], 12, 0x8b44f7af);
    FF(c, d, a, b, x[10], 17, 0xffff5bb1);
    FF(b, c, d, a, x[11], 22, 0x895cd7be);
    FF(a, b, c, d, x[12], 7, 0x6b901122);
    FF(d, a, b, c, x[13], 12, 0xfd987193);
    FF(c, d, a, b, x[14], 17, 0xa679438e);
    FF(b, c, d, a, x[15], 22, 0x49b40821);
    GG(a, b, c, d, x[1], 5, 0xf61e2562);
    GG(d, a, b, c, x[6], 9, 0xc040b340);
    GG(c, d, a, b, x[11], 14, 0x265e5a51);
    GG(b, c, d, a, x[0], 20, 0xe9b6c7aa);
    GG(a, b, c, d, x[5], 5, 0xd62f105d);
    GG(d, a, b, c, x[10], 9, 0x02441453);
    GG(c, d, a, b, x[15], 14, 0xd8a1e681);
    GG(b, c, d, a, x[4], 20, 0xe7d3fbc8);
    GG(a, b, c, d, x[9], 5, 0x21e1cde6);
    GG(d, a, b, c, x[14], 9, 0xc33707d6);
    GG(c, d, a, b, x[3], 14, 0xf4d50d87);
    GG(b, c, d, a, x[8], 20, 0x455a14ed);
    GG(a, b, c, d, x[13], 5, 0xa9e3e905);
    GG(d, a, b, c, x[2], 9, 0xfcefa3f8);
    GG(c, d, a, b, x[7], 14, 0x676f02d9);
    GG(b, c, d, a, x[12], 20, 0x8d2a4c8a);
    HH(a, b, c, d, x[5], 4, 0xfffa3942);
    HH(d, a, b, c, x[8], 11, 0x8771f681);
    HH(c, d, a, b, x[11], 16, 0x6d9d6122);
    HH(b, c, d, a, x[14], 23, 0xfde5380c);
    HH(a, b, c, d, x[1], 4, 0xa4beea44);
    HH(d, a, b, c, x[4], 11, 0x4bdecfa9);
    HH(c, d, a, b, x[7], 16, 0xf6bb4b60);
    HH(b, c, d, a, x[10], 23, 0xbebfbc70);
    HH(a, b, c, d, x[13], 4, 0x289b7ec6);
    HH(d, a, b, c, x[0], 11, 0xeaa127fa);
    HH(c, d, a, b, x[3], 16, 0xd4ef3085);
    HH(b, c, d, a, x[6], 23, 0x04881d05);
    HH(a, b, c, d, x[9], 4, 0xd9d4d039);
    HH(d, a, b, c, x[12], 11, 0xe6db99e5);
    HH(c, d, a, b, x[15], 16, 0x1fa27cf8);
    HH(b, c, d, a, x[2], 23, 0xc4ac5665);
    II(a, b, c, d, x[0], 6, 0xf4292244);
    II(d, a, b, c, x[7], 10, 0x432aff97);
    II(c, d, a, b, x[14], 15, 0xab9423a7);
    II(b, c, d, a, x[5], 21, 0xfc93a039);
    II(a, b, c, d, x[12], 6, 0x655b59c3);
    II(d, a, b, c, x[3], 10, 0x8f0ccc92);
    II(c, d, a, b, x[10], 15, 0xffeff47d);
    II(b, c, d, a, x[1], 21, 0x85845dd1);
    II(a, b, c, d, x[8], 6, 0x6fa87e4f);
    II(d, a, b, c, x[15], 10, 0xfe2ce6e0);
    II(c, d, a, b, x[6], 15, 0xa3014314);
    II(b, c, d, a, x[13], 21, 0x4e0811a1);
    II(a, b, c, d, x[4], 6, 0xf7537e82);
    II(d, a, b, c, x[11], 10, 0xbd3af235);
    II(c, d, a, b, x[2], 15, 0x2ad7d2bb);
    II(b, c, d, a, x[9], 21, 0xeb86d391);
    m_state[0] += a;
    m_state[1] += b;
    m_state[2] += c;
    m_state[3] += d;
    memset(x, 0, sizeof(x));
}

// @0x140696950
void Unk_Md5::Encode(unsigned char* pOut, const unsigned* pIn, unsigned nLen)
{
    unsigned i, j;
    for (i = 0, j = 0; j < nLen; i++, j += 4)
    {
        pOut[j] = (unsigned char)(pIn[i] & 0xff);
        pOut[j + 1] = (unsigned char)((pIn[i] >> 8) & 0xff);
        pOut[j + 2] = (unsigned char)((pIn[i] >> 16) & 0xff);
        pOut[j + 3] = (unsigned char)((pIn[i] >> 24) & 0xff);
    }
}

// @0x140696a30
void Unk_Md5::Decode(unsigned* pOut, const unsigned char* pIn, unsigned nLen)
{
    unsigned i, j;
    for (i = 0, j = 0; j < nLen; i++, j += 4)
        pOut[i] = ((unsigned)pIn[j]) | (((unsigned)pIn[j + 1]) << 8) | (((unsigned)pIn[j + 2]) << 16) |
                  (((unsigned)pIn[j + 3]) << 24);
}

// @0x140696b00
const unsigned char* Unk_Md5::Digest()
{
    return m_digest;
}

// @0x140696b10
unsigned Unk_Md5::F(unsigned x, unsigned y, unsigned z)
{
    return (x & y) | (~x & z);
}

// @0x140696b40
void Unk_Md5::FF(unsigned& a, unsigned b, unsigned c, unsigned d, unsigned x, int s, unsigned ac)
{
    a += F(b, c, d) + x + ac;
    a = RotateLeft(a, s);
    a += b;
}

// @0x140696bc0
unsigned Unk_Md5::G(unsigned x, unsigned y, unsigned z)
{
    return (x & z) | (y & ~z);
}

// @0x140696bf0
void Unk_Md5::GG(unsigned& a, unsigned b, unsigned c, unsigned d, unsigned x, int s, unsigned ac)
{
    a += G(b, c, d) + x + ac;
    a = RotateLeft(a, s);
    a += b;
}

// @0x140696c70
unsigned Unk_Md5::H(unsigned x, unsigned y, unsigned z)
{
    return x ^ y ^ z;
}

// @0x140696ca0
void Unk_Md5::HH(unsigned& a, unsigned b, unsigned c, unsigned d, unsigned x, int s, unsigned ac)
{
    a += H(b, c, d) + x + ac;
    a = RotateLeft(a, s);
    a += b;
}

// @0x140696d20
unsigned Unk_Md5::I(unsigned x, unsigned y, unsigned z)
{
    return y ^ (x | ~z);
}

// @0x140696d50
void Unk_Md5::II(unsigned& a, unsigned b, unsigned c, unsigned d, unsigned x, int s, unsigned ac)
{
    a += I(b, c, d) + x + ac;
    a = RotateLeft(a, s);
    a += b;
}

// @0x140696dd0
unsigned Unk_Md5::RotateLeft(unsigned x, int n)
{
    return (x << n) | (x >> (32 - n));
}
