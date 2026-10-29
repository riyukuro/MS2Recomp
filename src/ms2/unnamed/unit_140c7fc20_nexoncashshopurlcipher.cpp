// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Nexon cash-shop URL builder and the cipher it uses:
// a KISA SEED block cipher in CBC mode (16 rounds, SS-boxes at 0x142e12690..0x142e13690, golden-ratio key schedule)
// behind a 188-byte context (mode, IV, 32 round keys, partial-block buffer, previous block), Encrypt/Decrypt helpers
// that pad (PKCS#7) and a string front end that encrypts "<channel><nxid><date-hash>" style tokens with a fixed key/IV
// from the exe's data. The tail builds "https://nxpay.nexon.com/cash/pay.aspx?id=..&channel=..&type=.." through the
// game's fmt StringFormat; its fmt instances (0x140c854a0, 0x140c85470, 0x140c85860, 0x140c85c20, 0x140c85fe0) are
// emitted by the calls below. The key schedule and block functions are the KISA reference macros, unrolled as in the exe.
// MS2-UNIT: unit_140c7fc20
// MS2-RANGE: 0x140c7fc20-0x140c86000 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/mstime.h"
#include "hook/ms2hook.h"

#include <stdlib.h>
#include <string.h>
#include <intrin.h>
#include <string>

typedef unsigned __int64 u64;

// SEED substitution/permutation tables (SS0..SS3, 256 words each, contiguous) and the fixed key / IV of the pay token.
extern unsigned DAT_142e12690[256];
extern unsigned DAT_142e12a90[256];
extern unsigned DAT_142e12e90[256];
extern unsigned DAT_142e13290[256];
extern unsigned char DAT_1439f5448[16];
extern unsigned char DAT_1439f5458[16];

CString FUN_140695240(const char* psz);                      // hash of a string (hkey)
CString FUN_1401d2b10(const CString& a, const CString& b);   // ATL operator+(CString, CString)
CString FUN_1409a2360(const char* psz, int nCodePage);       // CString from a narrow string (0 = default code page)
std::string FUN_14083fa60(const char* pData, unsigned nLen); // string from a buffer
__int64 FUN_140869440();                                     // GetServerTime

// The cipher context (0xbc bytes).
struct Unk_SeedCbc {
    int m_nMode;               // +0x00: 1 = encrypt, else decrypt
    unsigned char m_aIv[16];   // +0x04: chaining value
    unsigned m_aKey[32];       // +0x14: round keys
    unsigned char m_aBuf[16];  // +0x94: pending partial block
    int m_nBuf;                // +0xa4: bytes pending
    unsigned char m_aLast[16]; // +0xa8: last decrypted block (padding byte at +0xb7)
    int m_nPad;                // +0xb8
};
MS2_CHECK_SIZE(Unk_SeedCbc, 0xbc);

// @0x140c7fc20 - copy n bytes into a fresh word buffer (rounded up to words)
void* FUN_140c7fc20(const unsigned* pSrc, int n)
{
    int nWords;
    if (n % 4 != 0)
        nWords = n / 4 + 1;
    else
        nWords = n / 4;
    unsigned* pDst = (unsigned*)malloc((__int64)nWords << 2);
    for (int i = 0; i < nWords; i++)
        pDst[i] = pSrc[i];
    return pDst;
}

// @0x140c7fcd0 - unpack n bytes from a word buffer into a fresh byte buffer
void* FUN_140c7fcd0(const unsigned* pSrc, int n)
{
    unsigned char* pDst = (unsigned char*)malloc((__int64)n);
    for (int i = 0; i < n; i++)
        pDst[i] = (unsigned char)(pSrc[i / 4] >> ((i % 4) * 8));
    return pDst;
}

// The KISA reference macros: byte-order swap, the four SS-box bytes and one Feistel half-round (L ^= F(R, K)).
#define Unk_SeedEndian(x) ((((x) << 8 | (x) >> 24) & 0x00ff00ff) | (((x) << 24 | (x) >> 8) & 0xff00ff00))
#define Unk_SeedB0(x) ((unsigned char)(x))
#define Unk_SeedB1(x) ((unsigned char)((x) >> 8))
#define Unk_SeedB2(x) ((unsigned char)((x) >> 16))
#define Unk_SeedB3(x) ((unsigned char)((x) >> 24))
#define Unk_SeedF(x) (DAT_142e12690[Unk_SeedB0(x)] ^ DAT_142e12a90[Unk_SeedB1(x)] ^ DAT_142e12e90[Unk_SeedB2(x)] ^ DAT_142e13290[Unk_SeedB3(x)])
#define Unk_SeedRound(L0, L1, R0, R1, K) { \
        T0 = R0 ^ (K)[0];                   \
        T1 = R1 ^ (K)[1];                   \
        T1 ^= T0;                           \
        T1 = Unk_SeedF(T1);                 \
        T0 += T1;                           \
        T0 = Unk_SeedF(T0);                 \
        T1 += T0;                           \
        T1 = Unk_SeedF(T1);                 \
        T0 += T1;                           \
        L0 ^= T0; L1 ^= T1;                 \
    }

// The two halves of the key schedule step: rotate A:B right (or C:D left) by 8, then K[0..1] = G(A + C - KC), G(B + KC - D).
#define Unk_SeedKeyUpdate0(K, A, B, C, D, KC) { \
        T0 = A;                                 \
        A = (A >> 8) ^ (B << 24);               \
        B = (B >> 8) ^ (T0 << 24);              \
        T0 = A + C - KC;                        \
        T1 = B + KC - D;                        \
        (K)[0] = Unk_SeedF(T0);                 \
        (K)[1] = Unk_SeedF(T1);                 \
    }
#define Unk_SeedKeyUpdate1(K, A, B, C, D, KC) { \
        T0 = C;                                 \
        C = (C << 8) ^ (D >> 24);               \
        D = (D << 8) ^ (T0 >> 24);              \
        T0 = A + C - KC;                        \
        T1 = B + KC - D;                        \
        (K)[0] = Unk_SeedF(T0);                 \
        (K)[1] = Unk_SeedF(T1);                 \
    }

#pragma function(memset, memcpy)   // the exe calls memset / memcpy here
// @0x140c7fd70 - init the context and expand the 128-bit key (the KISA SeedRoundKey, unrolled)
int FUN_140c7fd70(Unk_SeedCbc* pCtx, int nMode, const unsigned* pKey, const void* pIv)
{
    unsigned T0, T1, A, B, C, D;
    unsigned* K;
    if (pCtx == 0 || pKey == 0 || pIv == 0)
        return 0;
    memset(pCtx, 0, 0xbc);
    K = pCtx->m_aKey;
    pCtx->m_nMode = nMode;
    memcpy(pCtx->m_aIv, pIv, 0x10);
    pCtx->m_nBuf = 0;
    pCtx->m_nPad = 0;
    A = pKey[0];
    B = pKey[1];
    C = pKey[2];
    D = pKey[3];
    A = Unk_SeedEndian(A);
    B = Unk_SeedEndian(B);
    C = Unk_SeedEndian(C);
    D = Unk_SeedEndian(D);
    T0 = A + C - 0x9e3779b9;
    T1 = B + 0x9e3779b9 - D;
    K[0] = Unk_SeedF(T0);
    K[1] = Unk_SeedF(T1);
    Unk_SeedKeyUpdate0(K +  2, A, B, C, D, 0x3c6ef373);
    Unk_SeedKeyUpdate1(K +  4, A, B, C, D, 0x78dde6e6);
    Unk_SeedKeyUpdate0(K +  6, A, B, C, D, 0xf1bbcdcc);
    Unk_SeedKeyUpdate1(K +  8, A, B, C, D, 0xe3779b99);
    Unk_SeedKeyUpdate0(K + 10, A, B, C, D, 0xc6ef3733);
    Unk_SeedKeyUpdate1(K + 12, A, B, C, D, 0x8dde6e67);
    Unk_SeedKeyUpdate0(K + 14, A, B, C, D, 0x1bbcdccf);
    Unk_SeedKeyUpdate1(K + 16, A, B, C, D, 0x3779b99e);
    Unk_SeedKeyUpdate0(K + 18, A, B, C, D, 0x6ef3733c);
    Unk_SeedKeyUpdate1(K + 20, A, B, C, D, 0xdde6e678);
    Unk_SeedKeyUpdate0(K + 22, A, B, C, D, 0xbbcdccf1);
    Unk_SeedKeyUpdate1(K + 24, A, B, C, D, 0x779b99e3);
    Unk_SeedKeyUpdate0(K + 26, A, B, C, D, 0xef3733c6);
    Unk_SeedKeyUpdate1(K + 28, A, B, C, D, 0xde6e678d);
    T0 = A;
    A = (A >> 8) ^ (B << 24);
    B = (B >> 8) ^ (T0 << 24);
    T0 = A + C - 0xbcdccf1b;
    T1 = B - D + 0xbcdccf1b;
    K[30] = Unk_SeedF(T0);
    K[31] = Unk_SeedF(T1);
    return 1;
}
#pragma intrinsic(memset, memcpy)

#pragma function(memcpy)   // the exe calls memcpy for the CBC copies
void FUN_140c81ae0(const unsigned* pIn, unsigned* pOut, const unsigned* pKey);
void FUN_140c83540(const unsigned* pIn, unsigned* pOut, const unsigned* pKey);

// @0x140c810a0 - CBC update: process whole blocks of pIn, keep the rest pending
int FUN_140c810a0(Unk_SeedCbc* pCtx, const unsigned* pIn, int nLen, unsigned* pOut, int* pnOut)
{
    int n = 0x10;
    if (pCtx == 0 || pIn == 0 || pOut == 0 || nLen < 0)
        return 0;
    pCtx->m_nBuf = nLen - n;
    const unsigned* pPrev;
    if (pCtx->m_nMode == 1) {
        pPrev = (const unsigned*)pCtx->m_aIv;
        while (n <= nLen) {
            pOut[0] = pIn[0] ^ pPrev[0];
            pOut[1] = pIn[1] ^ pPrev[1];
            pOut[2] = pIn[2] ^ pPrev[2];
            pOut[3] = pIn[3] ^ pPrev[3];
            FUN_140c81ae0(pOut, pOut, pCtx->m_aKey);
            pPrev = pOut;
            n += 0x10;
            pIn += 4;
            pOut += 4;
        }
        *pnOut = n - 0x10;
        pCtx->m_nBuf = nLen - *pnOut;
        memcpy(pCtx->m_aIv, pPrev, 0x10);
        memcpy(pCtx->m_aBuf, pIn, pCtx->m_nBuf);
    } else {
        pPrev = (const unsigned*)pCtx->m_aIv;
        while (n <= nLen) {
            FUN_140c83540(pIn, pOut, pCtx->m_aKey);
            pOut[0] = pOut[0] ^ pPrev[0];
            pOut[1] = pOut[1] ^ pPrev[1];
            pOut[2] = pOut[2] ^ pPrev[2];
            pOut[3] = pOut[3] ^ pPrev[3];
            pPrev = pIn;
            n += 0x10;
            pIn += 4;
            pOut += 4;
        }
        *pnOut = n - 0x10;
        memcpy(pCtx->m_aIv, pPrev, 0x10);
        memcpy(pCtx->m_aLast, pOut - 4, 0x10);
    }
    return 1;
}

// @0x140c81460 - finish: pad and encrypt the last block, or report the padding length of the decrypted stream
int FUN_140c81460(Unk_SeedCbc* pCtx, unsigned char* pOut, unsigned* pnOut)
{
    unsigned char* pEnd = pOut;
    *pnOut = 0;
    if (pOut == 0)
        return 0;
    unsigned nPad;
    int i;
    if (pCtx->m_nMode == 1) {
        nPad = 0x10 - pCtx->m_nBuf;
        for (i = pCtx->m_nBuf; i < 0x10; i++)
            pCtx->m_aBuf[i] = (unsigned char)nPad;
        ((unsigned*)pCtx->m_aBuf)[0] = ((unsigned*)pCtx->m_aBuf)[0] ^ ((unsigned*)pCtx->m_aIv)[0];
        ((unsigned*)pCtx->m_aBuf)[1] = ((unsigned*)pCtx->m_aBuf)[1] ^ ((unsigned*)pCtx->m_aIv)[1];
        ((unsigned*)pCtx->m_aBuf)[2] = ((unsigned*)pCtx->m_aBuf)[2] ^ ((unsigned*)pCtx->m_aIv)[2];
        ((unsigned*)pCtx->m_aBuf)[3] = ((unsigned*)pCtx->m_aBuf)[3] ^ ((unsigned*)pCtx->m_aIv)[3];
        FUN_140c81ae0((const unsigned*)pCtx->m_aBuf, (unsigned*)pOut, pCtx->m_aKey);
        pOut += 0x10;
        *pnOut = 0x10;
    } else {
        nPad = pCtx->m_aLast[15];
        if (nPad > 0 && nPad <= 0x10) {
            for (i = nPad; i > 0; i--)
                *(pEnd - i) = 0;
            *pnOut = nPad;
        } else {
            return 0;
        }
    }
    return 1;
}

// @0x140c816b0 - encrypt nLen bytes (PKCS#7 padded) with a 128-bit key and IV; returns the cipher length
int FUN_140c816b0(const unsigned* pKey, const void* pIv, const void* pIn, int nLen, void* pOut)
{
    Unk_SeedCbc ctx;
    int nWords = 0;
    int nOut = 0;
    int nTail = 0;
    int nPad = 0x10 - nLen % 16;
    void* pCopy = malloc((size_t)(nLen + nPad));
    memcpy(pCopy, pIn, (__int64)nLen);
    FUN_140c7fd70(&ctx, 1, pKey, pIv);
    nWords = nLen / 16 * 4 + 4;
    unsigned* pCipher = (unsigned*)malloc((__int64)nWords << 2);
    unsigned* pWords = (unsigned*)FUN_140c7fc20((const unsigned*)pCopy, nLen);
    FUN_140c810a0(&ctx, pWords, nLen, pCipher, &nOut);
    FUN_140c81460(&ctx, (unsigned char*)(pCipher + nOut / 4), (unsigned*)&nTail);
    void* pBytes = FUN_140c7fcd0(pCipher, nOut + nTail);
    memcpy(pOut, pBytes, (size_t)(nOut + nTail));
    free(pWords);
    free(pBytes);
    free(pCipher);
    free(pCopy);
    return nOut + nTail;
}

// @0x140c818a0 - decrypt nLen bytes; returns the plain length (0 on a bad length or padding)
int FUN_140c818a0(const unsigned* pKey, const void* pIv, const void* pIn, int nLen, void* pOut)
{
    Unk_SeedCbc ctx;
    int nWords = 0;
    int nOut = 0;
    int nTail = 0;
    int nResult = 0;
    if (nLen % 16 > 0)
        return 0;
    void* pCopy = malloc((__int64)nLen);
    memcpy(pCopy, pIn, (__int64)nLen);
    void* pPlain = malloc((__int64)nLen);
    FUN_140c7fd70(&ctx, 0, pKey, pIv);
    nWords = nLen / 16 << 2;
    unsigned* pCipher = (unsigned*)malloc((__int64)nWords << 2);
    unsigned* pWords = (unsigned*)FUN_140c7fc20((const unsigned*)pCopy, nLen);
    FUN_140c810a0(&ctx, pWords, nLen, pCipher, &nOut);
    if (FUN_140c81460(&ctx, (unsigned char*)(pCipher + nOut / 4), (unsigned*)&nTail) > 0) {
        void* pBytes = FUN_140c7fcd0(pCipher, nOut - nTail);
        memcpy(pPlain, pBytes, (__int64)(nOut - nTail));
        nResult = nOut - nTail;
        if (nResult < 0)
            nResult = 0;
        memcpy(pOut, pPlain, (__int64)nResult);
        free(pWords);
        free(pBytes);
        free(pCipher);
        free(pPlain);
        return nResult;
    }
    free(pPlain);
    return 0;
}

#pragma intrinsic(memcpy)

// @0x140c81ae0 - encrypt one 16-byte block
void FUN_140c81ae0(const unsigned* pIn, unsigned* pOut, const unsigned* pKey)
{
    unsigned L0, L1, R0, R1, T0, T1;
    const unsigned* K = pKey;
    L0 = pIn[0];
    L1 = pIn[1];
    R0 = pIn[2];
    R1 = pIn[3];
    L0 = Unk_SeedEndian(L0);
    L1 = Unk_SeedEndian(L1);
    R0 = Unk_SeedEndian(R0);
    R1 = Unk_SeedEndian(R1);
    Unk_SeedRound(L0, L1, R0, R1, K +  0);
    Unk_SeedRound(R0, R1, L0, L1, K +  2);
    Unk_SeedRound(L0, L1, R0, R1, K +  4);
    Unk_SeedRound(R0, R1, L0, L1, K +  6);
    Unk_SeedRound(L0, L1, R0, R1, K +  8);
    Unk_SeedRound(R0, R1, L0, L1, K + 10);
    Unk_SeedRound(L0, L1, R0, R1, K + 12);
    Unk_SeedRound(R0, R1, L0, L1, K + 14);
    Unk_SeedRound(L0, L1, R0, R1, K + 16);
    Unk_SeedRound(R0, R1, L0, L1, K + 18);
    Unk_SeedRound(L0, L1, R0, R1, K + 20);
    Unk_SeedRound(R0, R1, L0, L1, K + 22);
    Unk_SeedRound(L0, L1, R0, R1, K + 24);
    Unk_SeedRound(R0, R1, L0, L1, K + 26);
    Unk_SeedRound(L0, L1, R0, R1, K + 28);
    Unk_SeedRound(R0, R1, L0, L1, K + 30);
    L0 = Unk_SeedEndian(L0);
    L1 = Unk_SeedEndian(L1);
    R0 = Unk_SeedEndian(R0);
    R1 = Unk_SeedEndian(R1);
    pOut[0] = R0;
    pOut[1] = R1;
    pOut[2] = L0;
    pOut[3] = L1;
}

// @0x140c83540 - decrypt one 16-byte block
void FUN_140c83540(const unsigned* pIn, unsigned* pOut, const unsigned* pKey)
{
    unsigned L0, L1, R0, R1, T0, T1;
    const unsigned* K = pKey;
    L0 = pIn[0];
    L1 = pIn[1];
    R0 = pIn[2];
    R1 = pIn[3];
    L0 = Unk_SeedEndian(L0);
    L1 = Unk_SeedEndian(L1);
    R0 = Unk_SeedEndian(R0);
    R1 = Unk_SeedEndian(R1);
    Unk_SeedRound(L0, L1, R0, R1, K + 30);
    Unk_SeedRound(R0, R1, L0, L1, K + 28);
    Unk_SeedRound(L0, L1, R0, R1, K + 26);
    Unk_SeedRound(R0, R1, L0, L1, K + 24);
    Unk_SeedRound(L0, L1, R0, R1, K + 22);
    Unk_SeedRound(R0, R1, L0, L1, K + 20);
    Unk_SeedRound(L0, L1, R0, R1, K + 18);
    Unk_SeedRound(R0, R1, L0, L1, K + 16);
    Unk_SeedRound(L0, L1, R0, R1, K + 14);
    Unk_SeedRound(R0, R1, L0, L1, K + 12);
    Unk_SeedRound(L0, L1, R0, R1, K + 10);
    Unk_SeedRound(R0, R1, L0, L1, K +  8);
    Unk_SeedRound(L0, L1, R0, R1, K +  6);
    Unk_SeedRound(R0, R1, L0, L1, K +  4);
    Unk_SeedRound(L0, L1, R0, R1, K +  2);
    Unk_SeedRound(R0, R1, L0, L1, K +  0);
    L0 = Unk_SeedEndian(L0);
    L1 = Unk_SeedEndian(L1);
    R0 = Unk_SeedEndian(R0);
    R1 = Unk_SeedEndian(R1);
    pOut[0] = R0;
    pOut[1] = R1;
    pOut[2] = L0;
    pOut[3] = L1;
}

// @0x140c84fb0
void FUN_140c84fb0(void* p)
{
}

// @0x140c85110 - the channel id
CString FUN_140c85110()
{
    return CString("MS2");
}

// @0x140c85150 - "<nxid>@nx"
CString FUN_140c85150(u64 nNxId)
{
    return Unk_SocketFormat("{0}@nx", nNxId);
}

// @0x140c851a0 - payment type
int FUN_140c851a0()
{
    return 1;
}

// @0x140c851b0 - hkey: hash of channel + nxid + "yyyyMMddhh" (12-hour clock) of the server time
CString FUN_140c851b0(const CString& strChannel, const CString& strNxId, CMsTime& time)
{
    int nHour = time.GetHour() % 12;
    if (nHour == 0)
        nHour = 12;
    int nDay = time.GetDay();
    int nMonth = time.GetMonth();
    int nYear = time.GetYear();
    CString strDate = Unk_SocketFormat("{0:04d}{1:02d}{2:02d}{3:02d}", nYear, nMonth, nDay, nHour);
    CString strKey = FUN_1401d2b10(FUN_1401d2b10(strChannel, strNxId), strDate);
    return FUN_140695240(strKey.GetBuffer());
}

CString FUN_140c85310(const CString& strPlain);

// @0x140c84fc0 - the cash-shop pay URL for a Nexon id
CString FUN_140c84fc0(u64 nNxId)
{
    CMsTime time(FUN_140869440());
    CString strChannel = FUN_140c85110();
    CString strNxId = FUN_140c85150(nNxId);
    int nType = FUN_140c851a0();
    CString strKey = FUN_140c851b0(strChannel, strNxId, time);
    CString strToken = Unk_SocketFormat("chid={0}&nxid={1}&ctype={2}&hkey={3}", strChannel, strNxId, nType, strKey);
    CString strCipher = FUN_140c85310(strToken);
    return StringFormat("{0}?id={1}&channel={2}&type={3}", "https://nxpay.nexon.com/cash/pay.aspx",
                        strCipher, strChannel, nType);
}

// @0x140c85310 - hex token of the SEED-encrypted string
CString FUN_140c85310(const CString& strPlain)
{
    std::string str((const char*)FUN_1409a2360((const char*)strPlain, 0));
    const char* pszPlain = str.c_str();
    unsigned char aBuf[0x400];
    memset(aBuf, 0, sizeof(aBuf));
    int nOut = FUN_140c816b0((const unsigned*)DAT_1439f5448, DAT_1439f5458, pszPlain, (int)str.size(), aBuf);
    std::string strHex = FUN_14083fa60((const char*)aBuf, nOut);
    return CString(strHex.c_str());
}
