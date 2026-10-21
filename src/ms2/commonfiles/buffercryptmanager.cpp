// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See buffercryptmanager.h for the original CU name
// evidence. The packet buffer crypters (XOR with a 2-byte key, byte substitution through a shuffled 256-entry table,
// and a first-half/second-half swap) plus the singleton that applies them to a packet. Every packet carries a decimal
// sequence number: the encrypt path walks its digits from the least significant one and applies crypters[digit], the
// decrypt path reverses the digits first (the server sends the number most significant digit first).
//
// The unit also carries the shared swap helpers (the exe's originals are the std::forward<unsigned char&/+int&>
// instantiations 0x1401cdb30/0x1401cdb40 and the two-instantiation Swap<> they belong to, reproduced here as plain
// functions because /Ob0 keeps the calls and the names are unknown), the Fisher-Yates shuffle of the substitution
// table, and the copy of Unk_Random's destructor that survived the linker's COMDAT folding.
// MS2-UNIT: ?\buffercryptmanager.cpp
// MS2-RANGE: 0x1401cd310-0x1401ce010 .text$mn
// MS2-PIN: ??1Unk_Random@@QEAA@XZ 0x1401cdc30
// MS2-PIN: ??0?$TSingleton@VCBufferCryptManager@@@@QEAA@XZ 0x1401cdf40
// MS2-PIN: ??1?$TSingleton@VCBufferCryptManager@@@@UEAA@XZ 0x1401cdf70
// MS2-PIN: ??_G?$TSingleton@VCBufferCryptManager@@@@UEAAPEAXI@Z 0x1401cdf90
// MS2-PIN: ??_GCBufferCryptManager@@UEAAPEAXI@Z 0x1401cdfd0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\buffercryptmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>

#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cbuffercryptmanager.h"
#include "ms2/ms2recover.h"

// ---- the game's random generator (commonfiles; 0x40 bytes) ----

// 0x10 unknown bytes, then the lock. Every user folds the destructor together (the exe's ??1Unk_Random /
// ??1Unk_ExpRandom / ??1Unk_MagicRandom / ??1Unk_OptionKey all live at 0x1401cdc30); this unit carries the copy that
// survived, hence the MS2-PIN above.
class Unk_Random
{
public:
    explicit Unk_Random(int nSeed);                 // 0x140768210
    ~Unk_Random() {}                                // destroys m_lock only
    unsigned int FUN_1407684c0();                   // 0x1407684c0 next integer
    float FUN_1407680d0();                          // 0x1407680d0 next float in [0, 1)
private:
    MS2_LAYOUT_FRIEND;
    void* m_unk00[2];                               // +0x00
    CLockCriticalSection m_lock;                    // +0x10
};
MS2_CHECK_SIZE(Unk_Random, 0x40);
MS2_CHECK_OFFSET(Unk_Random, m_lock, 0x10);

// The shuffle helpers, defined further down (the manager's Init reaches them before their definitions).
void FUN_1401cdae0(ATL::CAtlArray<int>* pValues, int nSeed);    // 0x1401cdae0 seeded shuffle
void FUN_1401cdb50(BYTE* pLeft, BYTE* pRight);                  // 0x1401cdb50 byte swap
void FUN_1401cdbb0(int* pLeft, int* pRight);                    // 0x1401cdbb0 int swap

// ---- CXORCrypter: XOR with a 2-byte key, alternating key bytes. Encrypt == Decrypt. ----

// @0x1401cd310
CXORCrypter::CXORCrypter() : m_pKey(0)
{
}

// @0x1401cd350
CXORCrypter::~CXORCrypter()
{
    if (m_pKey != 0)
    {
        delete[] m_pKey;
        m_pKey = 0;
    }
}

// Two generators (seeds 0x9dd / 0x13ba) produce the two key bytes.
// @0x1401cd3b0
void CXORCrypter::Init()
{
    Unk_Random kKey0(0x9dd);
    Unk_Random kKey1(0x13ba);

    m_pKey = new BYTE[2];
    m_pKey[0] = (BYTE)(kKey0.FUN_1407680d0() * 255.0f);
    m_pKey[1] = (BYTE)(kKey1.FUN_1407680d0() * 255.0f);
}

// @0x1401cd490
void CXORCrypter::Encrypt(BYTE* pBuffer, UINT nSize, unsigned* /*pKey*/)
{
    int nKeyIndex = 0;
    for (UINT i = 0; i < nSize; ++i)
    {
        pBuffer[i] ^= m_pKey[nKeyIndex];
        nKeyIndex = (nKeyIndex == 0) ? 1 : 0;
    }
}

// @0x1401cd530
BOOL CXORCrypter::Decrypt(BYTE* pBuffer, UINT nSize, unsigned* /*pKey*/)
{
    int nKeyIndex = 0;
    for (UINT i = 0; i < nSize; ++i)
    {
        pBuffer[i] ^= m_pKey[nKeyIndex];
        nKeyIndex = (nKeyIndex == 0) ? 1 : 0;
    }
    return TRUE;
}

// ---- CTableCrypter: byte substitution through a 256-entry permutation (and its inverse for Decrypt) ----

// @0x1401cd5d0
CTableCrypter::CTableCrypter() : m_pEncryptTable(0), m_pDecryptTable(0)
{
}

// @0x1401cd620
CTableCrypter::~CTableCrypter()
{
    if (m_pEncryptTable != 0)
    {
        delete[] m_pEncryptTable;
        m_pEncryptTable = 0;
    }
    if (m_pDecryptTable != 0)
    {
        delete[] m_pDecryptTable;
        m_pDecryptTable = 0;
    }
}

// The permutation is 0..255 shuffled with the fixed seed 0x6148c9; the second loop turns it into the inverse table as
// well. The tables are looked up by byte value, so the int array is read as a byte array.
// @0x1401cd6b0
void CTableCrypter::Init()
{
    m_pEncryptTable = new BYTE[256];
    m_pDecryptTable = new BYTE[256];

    ATL::CAtlArray<int> kValues;
    for (int i = 0; i <= 0xff; ++i)
        kValues.Add(i);
    FUN_1401cdae0(&kValues, 0x6148c9);

    for (int i = 0; i <= 0xff; ++i)
    {
        m_pEncryptTable[i] = (BYTE)kValues[i];
        m_pDecryptTable[m_pEncryptTable[i]] = (BYTE)i;
    }
}

// @0x1401cd7d0
void CTableCrypter::Encrypt(BYTE* pBuffer, UINT nSize, unsigned* /*pKey*/)
{
    for (UINT i = 0; i < nSize; ++i)
        pBuffer[i] = m_pEncryptTable[pBuffer[i]];
}

// @0x1401cd840
BOOL CTableCrypter::Decrypt(BYTE* pBuffer, UINT nSize, unsigned* /*pKey*/)
{
    for (UINT i = 0; i < nSize; ++i)
        pBuffer[i] = m_pDecryptTable[pBuffer[i]];
    return TRUE;
}

// ---- CRearrangeCrypter: swap the two halves of the buffer (an odd size leaves the last byte alone) ----

// @0x1401cd8b0
CRearrangeCrypter::CRearrangeCrypter()
{
}

// @0x1401cd8f0
CRearrangeCrypter::~CRearrangeCrypter()
{
}

// @0x1401cd910
void CRearrangeCrypter::Init()
{
}

// @0x1401cd920
void CRearrangeCrypter::Encrypt(BYTE* pBuffer, UINT nSize, unsigned* /*pKey*/)
{
    UINT nHalf = nSize / 2;
    for (UINT i = 0; i < nHalf; ++i)
        FUN_1401cdb50(&pBuffer[i], &pBuffer[nHalf + i]);
}

// @0x1401cd9b0
BOOL CRearrangeCrypter::Decrypt(BYTE* pBuffer, UINT nSize, unsigned* /*pKey*/)
{
    UINT nHalf = nSize / 2;
    for (UINT i = 0; i < nHalf; ++i)
        FUN_1401cdb50(&pBuffer[i], &pBuffer[nHalf + i]);
    return TRUE;
}

// ---- the substitution table's shuffle ----

// Fisher-Yates: walk the array from the back and swap each element with a random one below or at it.
// @0x1401cda40
void FUN_1401cda40(ATL::CAtlArray<int>* pValues, Unk_Random* pRandom)
{
    int nCount = (int)pValues->GetCount();
    for (int i = nCount - 1; i >= 1; --i)
    {
        int j = pRandom->FUN_1407684c0() % (i + 1);
        if (i != j)
            FUN_1401cdbb0(&(*pValues)[i], &(*pValues)[j]);
    }
}

// @0x1401cdae0
void FUN_1401cdae0(ATL::CAtlArray<int>* pValues, int nSeed)
{
    Unk_Random kRandom(nSeed);
    FUN_1401cda40(pValues, &kRandom);
}

// ---- the swap helpers (the exe's std::forward<unsigned char&> / std::forward<int&> and their Swap<>) ----

// @0x1401cdb30
BYTE* FUN_1401cdb30(BYTE* pValue)
{
    return pValue;
}

// @0x1401cdb40
int* FUN_1401cdb40(int* pValue)
{
    return pValue;
}

// @0x1401cdb50
void FUN_1401cdb50(BYTE* pLeft, BYTE* pRight)
{
    BYTE nTemp = *FUN_1401cdb30(pLeft);
    *FUN_1401cdb30(pLeft) = *FUN_1401cdb30(pRight);
    *FUN_1401cdb30(pRight) = nTemp;
}

// @0x1401cdbb0
void FUN_1401cdbb0(int* pLeft, int* pRight)
{
    int nTemp = *FUN_1401cdb40(pLeft);
    *FUN_1401cdb40(pLeft) = *FUN_1401cdb40(pRight);
    *FUN_1401cdb40(pRight) = nTemp;
}

// ---- the crypter interface and the singleton ----

// @0x1401cdc10
IBufferCrypter::IBufferCrypter()
{
}

// @0x1401cdc50
CBufferCryptManager::CBufferCryptManager()
{
    // The digit table is filled out of order (and m_crypters[0] stays empty: the digit 0 crypts nothing).
    m_crypters[0] = 0;
    m_crypters[3] = &m_tableCrypter;
    m_crypters[1] = &m_rearrangeCrypter;
    m_crypters[2] = &m_xorCrypter;
    for (int i = 1; i <= 3; ++i)
        m_crypters[i]->Init();
}

// @0x1401cdd70
CBufferCryptManager::~CBufferCryptManager()
{
}

// ---- the packet drivers ----

// Encrypt: walk the sequence number's decimal digits from the least significant one up.
// The divisions are unsigned (the exe has no cdq/idiv pair): the digit arithmetic is done on the unsigned value.
// The exe's function has no eax setup on any path (its `ret` exposes whatever the last division left) - it returns
// void; packet.cpp's int return is that caller's spelling of a value it ignores (free functions do not mangle the
// return type, so the two agree at link time).
// @0x1401cddd0
void FUN_1401cddd0(CBufferCryptManager* pManager, unsigned char* pData, int nLength, int nConnectionState,
                   unsigned* pKey)
{
    for (; nConnectionState != 0; nConnectionState = (int)((unsigned int)nConnectionState / 10))
    {
        IBufferCrypter* pCrypter = pManager->m_crypters[(unsigned int)nConnectionState % 10];
        if (pCrypter != 0)
            pCrypter->Encrypt(pData, nLength, pKey);
    }
}

// Decrypt: the digits arrive most significant first, so the number is reversed into nCode before the crypters run.
// @0x1401cde60
int FUN_1401cde60(CBufferCryptManager* pManager, unsigned char* pData, int nLength, int nConnectionState,
                  unsigned* pKey)
{
    int nCode = 0;
    for (; nConnectionState != 0; nConnectionState = (int)((unsigned int)nConnectionState / 10))
        nCode = nCode * 10 + (int)((unsigned int)nConnectionState % 10);
    for (; nCode != 0; nCode = (int)((unsigned int)nCode / 10))
    {
        IBufferCrypter* pCrypter = pManager->m_crypters[(unsigned int)nCode % 10];
        if (pCrypter != 0 && !pCrypter->Decrypt(pData, nLength, pKey))
            return 0;
    }
    return 1;
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
#include "hook/ms2hook.h"
MS2_REPLACE_METHOD(0x1401cd490, CXORCrypter, Encrypt, 141, 0xC2E8D752);
MS2_REPLACE_METHOD(0x1401cd530, CXORCrypter, Decrypt, 146, 0x416CBFED);
MS2_REPLACE_METHOD(0x1401cd7d0, CTableCrypter, Encrypt, 94, 0xEE661B00);
MS2_REPLACE_METHOD(0x1401cd840, CTableCrypter, Decrypt, 99, 0x8BEE29AF);
MS2_REPLACE_METHOD(0x1401cd910, CRearrangeCrypter, Init, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x1401cd920, CRearrangeCrypter, Encrypt, 126, 0x566F6F41);
MS2_REPLACE_METHOD(0x1401cd9b0, CRearrangeCrypter, Decrypt, 131, 0x8AE4685C);
MS2_REPLACE(0x1401cda40, FUN_1401cda40, 157, 0x50CC8F22);
MS2_REPLACE(0x1401cdae0, FUN_1401cdae0, 74, 0xDC3759AD);
MS2_REPLACE(0x1401cdb30, FUN_1401cdb30, 11, 0x3BE09B6E);
MS2_REPLACE(0x1401cdb40, FUN_1401cdb40, 11, 0x3BE09B6E);
MS2_REPLACE(0x1401cdb50, FUN_1401cdb50, 88, 0x671D7725);
MS2_REPLACE(0x1401cdbb0, FUN_1401cdbb0, 85, 0x157B6DDC);
MS2_REPLACE(0x1401cddd0, FUN_1401cddd0, 128, 0x7B198022);
MS2_REPLACE(0x1401cde60, FUN_1401cde60, 213, 0xDCD4A622);

