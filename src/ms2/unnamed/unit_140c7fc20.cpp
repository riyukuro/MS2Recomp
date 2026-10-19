// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Nexon cash-shop URL builder and the cipher it uses:
// a KISA SEED block cipher in CBC mode (16 rounds, SS-boxes at 0x142e12690..0x142e13690, golden-ratio key schedule)
// behind a 188-byte context (mode, IV, 32 round keys, partial-block buffer, previous block), Encrypt/Decrypt helpers
// that pad (PKCS#7) and a string front end that encrypts "<channel><nxid><date-hash>" style tokens with a fixed key/IV
// from the exe's data. The tail builds "https://nxpay.nexon.com/cash/pay.aspx?id=..&channel=..&type=.." through the
// game's fmt StringFormat; its fmt instances (0x140c854a0, 0x140c85470, 0x140c85860, 0x140c85c20, 0x140c85fe0) are
// emitted by the calls below. The exe unrolls the rounds; the source uses loops (functional).
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

static unsigned Unk_SeedG(unsigned x)
{
    return DAT_142e12690[x & 0xff] ^ DAT_142e12a90[(x >> 8) & 0xff] ^ DAT_142e12e90[(x >> 16) & 0xff] ^ DAT_142e13290[x >> 24];
}

// @0x140c7fc20 - copy n bytes into a fresh word buffer (rounded up to words)
void* FUN_140c7fc20(const unsigned* pSrc, int n)
{
    int nWords;
    if (n % 4 == 0)
        nWords = n / 4;
    else
        nWords = n / 4 + 1;
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

// @0x140c7fd70 - init the context and expand the 128-bit key
int FUN_140c7fd70(Unk_SeedCbc* pCtx, int nMode, const unsigned* pKey, const void* pIv)
{
    if (pCtx == 0 || pKey == 0 || pIv == 0)
        return 0;
    memset(pCtx, 0, 0xbc);
    pCtx->m_nMode = nMode;
    memcpy(pCtx->m_aIv, pIv, 0x10);
    pCtx->m_nBuf = 0;
    pCtx->m_nPad = 0;

    unsigned A = _byteswap_ulong(pKey[0]);
    unsigned B = _byteswap_ulong(pKey[1]);
    unsigned C = _byteswap_ulong(pKey[2]);
    unsigned D = _byteswap_ulong(pKey[3]);
    for (int i = 0; i < 16; i++) {
        unsigned kc = _rotl(0x9e3779b9u, i);
        unsigned t0 = A + C - kc;
        unsigned t1 = B - D + kc;
        pCtx->m_aKey[2 * i] = Unk_SeedG(t0);
        pCtx->m_aKey[2 * i + 1] = Unk_SeedG(t1);
        if ((i & 1) == 0) {
            unsigned t = A;
            A = (A >> 8) ^ (B << 24);
            B = (B >> 8) ^ (t << 24);
        } else {
            unsigned t = C;
            C = (C << 8) ^ (D >> 24);
            D = (D << 8) ^ (t >> 24);
        }
    }
    return 1;
}

// One Feistel half-round: L ^= F(R, k0, k1).
static void Unk_SeedRound(unsigned& l0, unsigned& l1, unsigned r0, unsigned r1, unsigned k0, unsigned k1)
{
    unsigned t0 = r0 ^ k0;
    unsigned t1 = r1 ^ k1 ^ t0;
    t1 = Unk_SeedG(t1);
    t0 = t0 + t1;
    t0 = Unk_SeedG(t0);
    t1 = t1 + t0;
    t1 = Unk_SeedG(t1);
    t0 = t0 + t1;
    l0 ^= t0;
    l1 ^= t1;
}

static void Unk_SeedBlock(const unsigned* pIn, unsigned* pOut, const unsigned* pKey, bool bDecrypt)
{
    unsigned l0 = _byteswap_ulong(pIn[0]);
    unsigned l1 = _byteswap_ulong(pIn[1]);
    unsigned r0 = _byteswap_ulong(pIn[2]);
    unsigned r1 = _byteswap_ulong(pIn[3]);
    for (int i = 0; i < 16; i += 2) {
        int ka = bDecrypt ? 30 - 2 * i : 2 * i;
        int kb = bDecrypt ? 30 - 2 * (i + 1) : 2 * (i + 1);
        Unk_SeedRound(l0, l1, r0, r1, pKey[ka], pKey[ka + 1]);
        Unk_SeedRound(r0, r1, l0, l1, pKey[kb], pKey[kb + 1]);
    }
    pOut[0] = _byteswap_ulong(r0);
    pOut[1] = _byteswap_ulong(r1);
    pOut[2] = _byteswap_ulong(l0);
    pOut[3] = _byteswap_ulong(l1);
}

// @0x140c810a0 - CBC update: process whole blocks of pIn, keep the rest pending
int FUN_140c810a0(Unk_SeedCbc* pCtx, const unsigned* pIn, int nLen, unsigned* pOut, int* pnOut)
{
    int n = 0x10;
    if (pCtx == 0 || pIn == 0 || pOut == 0 || nLen < 0)
        return 0;
    pCtx->m_nBuf = nLen - 0x10;
    if (pCtx->m_nMode == 1) {
        const unsigned* pPrev = (const unsigned*)pCtx->m_aIv;
        for (; n <= nLen; n += 0x10) {
            pOut[0] = pIn[0] ^ pPrev[0];
            pOut[1] = pIn[1] ^ pPrev[1];
            pOut[2] = pIn[2] ^ pPrev[2];
            pOut[3] = pIn[3] ^ pPrev[3];
            Unk_SeedBlock(pOut, pOut, pCtx->m_aKey, false);
            pPrev = pOut;
            pIn += 4;
            pOut += 4;
        }
        *pnOut = n - 0x10;
        pCtx->m_nBuf = nLen - *pnOut;
        memcpy(pCtx->m_aIv, pPrev, 0x10);
        memcpy(pCtx->m_aBuf, pIn, pCtx->m_nBuf);
    } else {
        const unsigned* pPrev = (const unsigned*)pCtx->m_aIv;
        for (; n <= nLen; n += 0x10) {
            Unk_SeedBlock(pIn, pOut, pCtx->m_aKey, true);
            pOut[0] = pOut[0] ^ pPrev[0];
            pOut[1] = pOut[1] ^ pPrev[1];
            pOut[2] = pOut[2] ^ pPrev[2];
            pOut[3] = pOut[3] ^ pPrev[3];
            pPrev = pIn;
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
    *pnOut = 0;
    if (pOut == 0)
        return 0;
    if (pCtx->m_nMode == 1) {
        char cPad = (char)(0x10 - pCtx->m_nBuf);
        for (int i = pCtx->m_nBuf; i < 0x10; i++)
            pCtx->m_aBuf[i] = cPad;
        unsigned* pBuf = (unsigned*)pCtx->m_aBuf;
        const unsigned* pIv = (const unsigned*)pCtx->m_aIv;
        pBuf[0] ^= pIv[0];
        pBuf[1] ^= pIv[1];
        pBuf[2] ^= pIv[2];
        pBuf[3] ^= pIv[3];
        Unk_SeedBlock(pBuf, (unsigned*)pOut, pCtx->m_aKey, false);
        *pnOut = 0x10;
    } else {
        unsigned nPad = pCtx->m_aLast[15];
        if (nPad == 0 || nPad > 0x10)
            return 0;
        int n = (int)nPad;
        for (; n > 0; n--)
            pOut[-n] = 0;
        *pnOut = nPad;
    }
    return 1;
}

// @0x140c816b0 - encrypt nLen bytes (PKCS#7 padded) with a 128-bit key and IV; returns the cipher length
int FUN_140c816b0(const unsigned* pKey, const void* pIv, const void* pIn, int nLen, void* pOut)
{
    Unk_SeedCbc ctx;
    int nOut = 0;
    int nTail = 0;
    int nPad = 0x10 - nLen % 16;
    int nCopy = nLen + nPad;
    void* pCopy = malloc((__int64)nCopy);
    memcpy(pCopy, pIn, (__int64)nLen);
    FUN_140c7fd70(&ctx, 1, pKey, pIv);
    int nWords = nLen / 16 * 4 + 4;
    unsigned* pCipher = (unsigned*)malloc((__int64)nWords << 2);
    unsigned* pWords = (unsigned*)FUN_140c7fc20((const unsigned*)pCopy, nLen);
    FUN_140c810a0(&ctx, pWords, nLen, pCipher, &nOut);
    FUN_140c81460(&ctx, (unsigned char*)(pCipher + nOut / 4), (unsigned*)&nTail);
    void* pBytes = FUN_140c7fcd0(pCipher, nOut + nTail);
    int nTotal = nOut + nTail;
    memcpy(pOut, pBytes, (__int64)nTotal);
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
    int nOut = 0;
    int nTail = 0;
    int nResult = 0;
    if (nLen % 16 < 1) {
        void* pCopy = malloc((__int64)nLen);
        memcpy(pCopy, pIn, (__int64)nLen);
        void* pPlain = malloc((__int64)nLen);
        FUN_140c7fd70(&ctx, 0, pKey, pIv);
        int nWords = nLen / 16 << 2;
        unsigned* pCipher = (unsigned*)malloc((__int64)nWords << 2);
        unsigned* pWords = (unsigned*)FUN_140c7fc20((const unsigned*)pCopy, nLen);
        FUN_140c810a0(&ctx, pWords, nLen, pCipher, &nOut);
        int bOk = FUN_140c81460(&ctx, (unsigned char*)(pCipher + nOut / 4), (unsigned*)&nTail);
        if (bOk < 1) {
            free(pPlain);
            nResult = 0;
        } else {
            void* pBytes = FUN_140c7fcd0(pCipher, nOut - nTail);
            nResult = nOut - nTail;
            memcpy(pPlain, pBytes, (__int64)nResult);
            if (nResult < 0)
                nResult = 0;
            memcpy(pOut, pPlain, (__int64)nResult);
            free(pWords);
            free(pBytes);
            free(pCipher);
            free(pPlain);
        }
    } else {
        nResult = 0;
    }
    return nResult;
}

// @0x140c81ae0 - encrypt one 16-byte block
void FUN_140c81ae0(const unsigned* pIn, unsigned* pOut, const unsigned* pKey)
{
    Unk_SeedBlock(pIn, pOut, pKey, false);
}

// @0x140c83540 - decrypt one 16-byte block
void FUN_140c83540(const unsigned* pIn, unsigned* pOut, const unsigned* pKey)
{
    Unk_SeedBlock(pIn, pOut, pKey, true);
}

// @0x140c84fb0
void FUN_140c84fb0()
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
    int nHour = time.GetHour();
    nHour = nHour % 12;
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
    CString strAnsi = FUN_1409a2360((const char*)strPlain, 0);
    std::string str((const char*)strAnsi);
    strAnsi.Empty();
    const char* pszPlain = str.c_str();
    unsigned char aBuf[0x400];
    memset(aBuf, 0, sizeof(aBuf));
    int nLen = (int)str.size();
    int nOut = FUN_140c816b0((const unsigned*)DAT_1439f5448, DAT_1439f5458, pszPlain, nLen, aBuf);
    std::string strHex = FUN_14083fa60((const char*)aBuf, nOut);
    return CString(strHex.c_str());
}
