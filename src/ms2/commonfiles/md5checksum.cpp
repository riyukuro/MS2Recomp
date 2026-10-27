// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See md5checksum.h.
// MS2-UNIT: commonfiles\md5checksum.cpp
// MS2-RANGE: 0x140696e00-0x14069a010 .text$mn
// MS2-RANGE: 0x1400bb3c0-0x1400bb3e1 .text$di
// MS2-RANGE: 0x142c9b610-0x142c9b625 .text$yd
//
// Status: every function of the unit byte-matches under cl 19.16 with the game flags (tools/progress.py), incl. the
// COMDAT tail (CAtlMap<CString, CString>, std::count, basic_string::compare, the CRT's static memmove_s).
// The body is the CodeProject source (asserts on the original lines); `// @0x...` tags pair functions with exe VAs.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\md5checksum.cpp"
#include "md5checksum.h"

#include <io.h>

#include <algorithm>

#include <atlcoll.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Magic initialization constants, constants for the transform routine.
#define MD5_INIT_STATE_0 0x67452301
#define MD5_INIT_STATE_1 0xefcdab89
#define MD5_INIT_STATE_2 0x98badcfe
#define MD5_INIT_STATE_3 0x10325476
#define MD5_S11 7
#define MD5_S12 12
#define MD5_S13 17
#define MD5_S14 22
#define MD5_S21 5
#define MD5_S22 9
#define MD5_S23 14
#define MD5_S24 20
#define MD5_S31 4
#define MD5_S32 11
#define MD5_S33 16
#define MD5_S34 23
#define MD5_S41 6
#define MD5_S42 10
#define MD5_S43 15
#define MD5_S44 21
#define MD5_T01 0xd76aa478
#define MD5_T02 0xe8c7b756
#define MD5_T03 0x242070db
#define MD5_T04 0xc1bdceee
#define MD5_T05 0xf57c0faf
#define MD5_T06 0x4787c62a
#define MD5_T07 0xa8304613
#define MD5_T08 0xfd469501
#define MD5_T09 0x698098d8
#define MD5_T10 0x8b44f7af
#define MD5_T11 0xffff5bb1
#define MD5_T12 0x895cd7be
#define MD5_T13 0x6b901122
#define MD5_T14 0xfd987193
#define MD5_T15 0xa679438e
#define MD5_T16 0x49b40821
#define MD5_T17 0xf61e2562
#define MD5_T18 0xc040b340
#define MD5_T19 0x265e5a51
#define MD5_T20 0xe9b6c7aa
#define MD5_T21 0xd62f105d
#define MD5_T22 0x02441453
#define MD5_T23 0xd8a1e681
#define MD5_T24 0xe7d3fbc8
#define MD5_T25 0x21e1cde6
#define MD5_T26 0xc33707d6
#define MD5_T27 0xf4d50d87
#define MD5_T28 0x455a14ed
#define MD5_T29 0xa9e3e905
#define MD5_T30 0xfcefa3f8
#define MD5_T31 0x676f02d9
#define MD5_T32 0x8d2a4c8a
#define MD5_T33 0xfffa3942
#define MD5_T34 0x8771f681
#define MD5_T35 0x6d9d6122
#define MD5_T36 0xfde5380c
#define MD5_T37 0xa4beea44
#define MD5_T38 0x4bdecfa9
#define MD5_T39 0xf6bb4b60
#define MD5_T40 0xbebfbc70
#define MD5_T41 0x289b7ec6
#define MD5_T42 0xeaa127fa
#define MD5_T43 0xd4ef3085
#define MD5_T44 0x04881d05
#define MD5_T45 0xd9d4d039
#define MD5_T46 0xe6db99e5
#define MD5_T47 0x1fa27cf8
#define MD5_T48 0xc4ac5665
#define MD5_T49 0xf4292244
#define MD5_T50 0x432aff97
#define MD5_T51 0xab9423a7
#define MD5_T52 0xfc93a039
#define MD5_T53 0x655b59c3
#define MD5_T54 0x8f0ccc92
#define MD5_T55 0xffeff47d
#define MD5_T56 0x85845dd1
#define MD5_T57 0x6fa87e4f
#define MD5_T58 0xfe2ce6e0
#define MD5_T59 0xa3014314
#define MD5_T60 0x4e0811a1
#define MD5_T61 0xf7537e82
#define MD5_T62 0xbd3af235
#define MD5_T63 0x2ad7d2bb
#define MD5_T64 0xeb86d391

// Null data (except the first BYTE) used to finalise the checksum calculation. 0x1439f4890 (.data)
static unsigned char PADDING[64] = {
    0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

// A file-static CString -> CString map, unused by the code here (ctor 0x1406991e0 via the dynamic initializer
// 0x1400bb3c0, dtor 0x1406992d0 via atexit 0x142c9b610; object at 0x143ab0420). The CAtlMap is a member (not a base):
// the wrapper's ctor/dtor load `this` into rax before passing it on. The class name is unknown; it sorts after
// "CPair@?$CAtlMap" in the COMDAT tail, so it starts with a letter >= 'C'.
class CStringToStringMap
{
public:
    CAtlMap<CString, CString> m_map;
};
static CStringToStringMap s_mapUnknown;

MS2_EMIT_CRT_MEMMOVE_S();  // memmove_s 0x140699ef0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140696e00
CString CMD5Checksum::GetMD5(BYTE* pBuf, UINT nLength)
{
    //entry invariants
    AfxIsValidAddress(pBuf, nLength, FALSE);

    //calculate and return the checksum
    CMD5Checksum MD5Checksum;
    MD5Checksum.Update(pBuf, nLength);
    return MD5Checksum.Final();
}
MS2_REPLACE_OVERLOAD(0x140696E00, CString(BYTE*, UINT), CMD5Checksum::GetMD5, 190, 0xC902BD34);

// @0x140696ed0
CString CMD5Checksum::GetMD5(CFile& File)
{
    try
    {
        CMD5Checksum MD5Checksum;       //checksum object
        int nLength = 0;                //number of bytes read from the file
        const int nBufferSize = 1024;   //checksum the file in blocks of 1024 bytes
        BYTE Buffer[nBufferSize];       //buffer for data read from the file

        //checksum the file in blocks of 1024 bytes
        while ((nLength = File.Read(Buffer, nBufferSize)) > 0)
        {
            MD5Checksum.Update(Buffer, nLength);
        }

        //finalise the checksum and return it
        return MD5Checksum.Final();
    }

    //report any file exceptions in debug mode only
    catch (CFileException* e)
    {
        TRACE0("CMD5Checksum::GetMD5: CFileException caught");
        throw e;
    }
}

// @0x140696fd0
CString CMD5Checksum::GetMD5(const CString& strFilePath)
{
    //open the file as a binary file in readonly mode, denying write access
    CFile File(strFilePath, CFile::shareDenyWrite | CFile::typeBinary);

    //the file has been successfully opened, so now get and return its checksum
    return GetMD5(File);
}

// @0x140699cc0
DWORD CMD5Checksum::RotateLeft(DWORD x, int n)
{
    //check that DWORD is 4 bytes long - true in Visual C++ 6 and 32 bit Windows
    ASSERT(sizeof(x) == 4);

    //rotate and return x
    return (x << n) | (x >> (32 - n));
}

// @0x1406993b0
void CMD5Checksum::FF(DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
    DWORD F = (B & C) | (~B & D);
    A += F + X + T;
    A = RotateLeft(A, S);
    A += B;
}

// @0x140699590
void CMD5Checksum::GG(DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
    DWORD G = (B & D) | (C & ~D);
    A += G + X + T;
    A = RotateLeft(A, S);
    A += B;
}

// @0x140699630
void CMD5Checksum::HH(DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
    DWORD H = (B ^ C ^ D);
    A += H + X + T;
    A = RotateLeft(A, S);
    A += B;
}

// @0x1406996b0
void CMD5Checksum::II(DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T)
{
    DWORD I = (C ^ (B | ~D));
    A += I + X + T;
    A = RotateLeft(A, S);
    A += B;
}

// @0x1406989b0
void CMD5Checksum::ByteToDWord(DWORD* Output, BYTE* Input, UINT nLength)
{
    //entry invariants
    MS2_ASSERT_AT(273, nLength % 4 == 0);
    MS2_ASSERT_AT(274, AfxIsValidAddress(Output, nLength/4, TRUE));
    MS2_ASSERT_AT(275, AfxIsValidAddress(Input, nLength, FALSE));

    //initialisations
    UINT i = 0;    //index to Output array
    UINT j = 0;    //index to Input array

    //transfer the data by shifting and copying
    for (; j < nLength; i++, j += 4)
    {
        Output[i] = (ULONG)Input[j] |
                    (ULONG)Input[j + 1] << 8 |
                    (ULONG)Input[j + 2] << 16 |
                    (ULONG)Input[j + 3] << 24;
    }
}

// @0x140697110
void CMD5Checksum::Transform(BYTE Block[64])
{
    //initialise local data with current checksum
    ULONG a = m_lMD5[0];
    ULONG b = m_lMD5[1];
    ULONG c = m_lMD5[2];
    ULONG d = m_lMD5[3];

    //copy BYTES from input 'Block' to an array of ULONGS 'X'
    ULONG X[16];
    ByteToDWord(X, Block, 64);

    //Perform Round 1 of the transformation
    FF (a, b, c, d, X[ 0], MD5_S11, MD5_T01);
    FF (d, a, b, c, X[ 1], MD5_S12, MD5_T02);
    FF (c, d, a, b, X[ 2], MD5_S13, MD5_T03);
    FF (b, c, d, a, X[ 3], MD5_S14, MD5_T04);
    FF (a, b, c, d, X[ 4], MD5_S11, MD5_T05);
    FF (d, a, b, c, X[ 5], MD5_S12, MD5_T06);
    FF (c, d, a, b, X[ 6], MD5_S13, MD5_T07);
    FF (b, c, d, a, X[ 7], MD5_S14, MD5_T08);
    FF (a, b, c, d, X[ 8], MD5_S11, MD5_T09);
    FF (d, a, b, c, X[ 9], MD5_S12, MD5_T10);
    FF (c, d, a, b, X[10], MD5_S13, MD5_T11);
    FF (b, c, d, a, X[11], MD5_S14, MD5_T12);
    FF (a, b, c, d, X[12], MD5_S11, MD5_T13);
    FF (d, a, b, c, X[13], MD5_S12, MD5_T14);
    FF (c, d, a, b, X[14], MD5_S13, MD5_T15);
    FF (b, c, d, a, X[15], MD5_S14, MD5_T16);

    //Perform Round 2 of the transformation
    GG (a, b, c, d, X[ 1], MD5_S21, MD5_T17);
    GG (d, a, b, c, X[ 6], MD5_S22, MD5_T18);
    GG (c, d, a, b, X[11], MD5_S23, MD5_T19);
    GG (b, c, d, a, X[ 0], MD5_S24, MD5_T20);
    GG (a, b, c, d, X[ 5], MD5_S21, MD5_T21);
    GG (d, a, b, c, X[10], MD5_S22, MD5_T22);
    GG (c, d, a, b, X[15], MD5_S23, MD5_T23);
    GG (b, c, d, a, X[ 4], MD5_S24, MD5_T24);
    GG (a, b, c, d, X[ 9], MD5_S21, MD5_T25);
    GG (d, a, b, c, X[14], MD5_S22, MD5_T26);
    GG (c, d, a, b, X[ 3], MD5_S23, MD5_T27);
    GG (b, c, d, a, X[ 8], MD5_S24, MD5_T28);
    GG (a, b, c, d, X[13], MD5_S21, MD5_T29);
    GG (d, a, b, c, X[ 2], MD5_S22, MD5_T30);
    GG (c, d, a, b, X[ 7], MD5_S23, MD5_T31);
    GG (b, c, d, a, X[12], MD5_S24, MD5_T32);

    //Perform Round 3 of the transformation
    HH (a, b, c, d, X[ 5], MD5_S31, MD5_T33);
    HH (d, a, b, c, X[ 8], MD5_S32, MD5_T34);
    HH (c, d, a, b, X[11], MD5_S33, MD5_T35);
    HH (b, c, d, a, X[14], MD5_S34, MD5_T36);
    HH (a, b, c, d, X[ 1], MD5_S31, MD5_T37);
    HH (d, a, b, c, X[ 4], MD5_S32, MD5_T38);
    HH (c, d, a, b, X[ 7], MD5_S33, MD5_T39);
    HH (b, c, d, a, X[10], MD5_S34, MD5_T40);
    HH (a, b, c, d, X[13], MD5_S31, MD5_T41);
    HH (d, a, b, c, X[ 0], MD5_S32, MD5_T42);
    HH (c, d, a, b, X[ 3], MD5_S33, MD5_T43);
    HH (b, c, d, a, X[ 6], MD5_S34, MD5_T44);
    HH (a, b, c, d, X[ 9], MD5_S31, MD5_T45);
    HH (d, a, b, c, X[12], MD5_S32, MD5_T46);
    HH (c, d, a, b, X[15], MD5_S33, MD5_T47);
    HH (b, c, d, a, X[ 2], MD5_S34, MD5_T48);

    //Perform Round 4 of the transformation
    II (a, b, c, d, X[ 0], MD5_S41, MD5_T49);
    II (d, a, b, c, X[ 7], MD5_S42, MD5_T50);
    II (c, d, a, b, X[14], MD5_S43, MD5_T51);
    II (b, c, d, a, X[ 5], MD5_S44, MD5_T52);
    II (a, b, c, d, X[12], MD5_S41, MD5_T53);
    II (d, a, b, c, X[ 3], MD5_S42, MD5_T54);
    II (c, d, a, b, X[10], MD5_S43, MD5_T55);
    II (b, c, d, a, X[ 1], MD5_S44, MD5_T56);
    II (a, b, c, d, X[ 8], MD5_S41, MD5_T57);
    II (d, a, b, c, X[15], MD5_S42, MD5_T58);
    II (c, d, a, b, X[ 6], MD5_S43, MD5_T59);
    II (b, c, d, a, X[13], MD5_S44, MD5_T60);
    II (a, b, c, d, X[ 4], MD5_S41, MD5_T61);
    II (d, a, b, c, X[11], MD5_S42, MD5_T62);
    II (c, d, a, b, X[ 2], MD5_S43, MD5_T63);
    II (b, c, d, a, X[ 9], MD5_S44, MD5_T64);

    //add the transformed values to the current checksum
    m_lMD5[0] += a;
    m_lMD5[1] += b;
    m_lMD5[2] += c;
    m_lMD5[3] += d;
}

// @0x140697050
CMD5Checksum::CMD5Checksum()
{
    // zero members
    memset(m_lpszBuffer, 0, 64);
    m_nCount[0] = m_nCount[1] = 0;

    // Load magic state initialization constants
    m_lMD5[0] = MD5_INIT_STATE_0;
    m_lMD5[1] = MD5_INIT_STATE_1;
    m_lMD5[2] = MD5_INIT_STATE_2;
    m_lMD5[3] = MD5_INIT_STATE_3;
}

// @0x140698820
void CMD5Checksum::DWordToByte(BYTE* Output, DWORD* Input, UINT nLength)
{
    //entry invariants
    MS2_ASSERT_AT(431, nLength % 4 == 0);
    MS2_ASSERT_AT(432, AfxIsValidAddress(Output, nLength, TRUE));
    MS2_ASSERT_AT(433, AfxIsValidAddress(Input, nLength/4, FALSE));

    //transfer the data by shifting and copying
    UINT i = 0;
    UINT j = 0;
    for (; j < nLength; i++, j += 4)
    {
        Output[j] = (UCHAR)(Input[i] & 0xff);
        Output[j + 1] = (UCHAR)((Input[i] >> 8) & 0xff);
        Output[j + 2] = (UCHAR)((Input[i] >> 16) & 0xff);
        Output[j + 3] = (UCHAR)((Input[i] >> 24) & 0xff);
    }
}

// @0x140698580
CString CMD5Checksum::Final()
{
    //Save number of bits
    BYTE Bits[8];
    DWordToByte(Bits, m_nCount, 8);

    //Pad out to 56 mod 64.
    UINT nIndex = (UINT)((m_nCount[0] >> 3) & 0x3f);
    UINT nPadLen = (nIndex < 56) ? (56 - nIndex) : (120 - nIndex);
    Update(PADDING, nPadLen);

    //Append length (before padding)
    Update(Bits, 8);

    //Store final state in 'lpszMD5'
    const int nMD5Size = 16;
    unsigned char lpszMD5[nMD5Size];
    DWordToByte(lpszMD5, m_lMD5, nMD5Size);

    //Convert the hexadecimal checksum to a CString
    CString strMD5;
    for (int i = 0; i < nMD5Size; i++)
    {
        CString Str;
        if (lpszMD5[i] == 0) {
            Str = CString("00");
        }
        else if (lpszMD5[i] <= 15) {
            Str.Format("0%x", lpszMD5[i]);
        }
        else {
            Str.Format("%x", lpszMD5[i]);
        }

        MS2_ASSERT_AT(491, Str.GetLength() == 2);
        strMD5 += Str;
    }
    MS2_ASSERT_AT(494, strMD5.GetLength() == 32);
    return strMD5;
}

// @0x1406983d0
void CMD5Checksum::Update(BYTE* Input, ULONG nInputLen)
{
    //Compute number of bytes mod 64
    UINT nIndex = (UINT)((m_nCount[0] >> 3) & 0x3F);

    //Update number of bits
    if ((m_nCount[0] += nInputLen << 3) < (nInputLen << 3))
    {
        m_nCount[1]++;
    }
    m_nCount[1] += (nInputLen >> 29);

    //Transform as many times as possible.
    UINT i = 0;
    UINT nPartLen = 64 - nIndex;
    if (nInputLen >= nPartLen)
    {
        memcpy(&m_lpszBuffer[nIndex], Input, nPartLen);
        Transform(m_lpszBuffer);
        for (i = nPartLen; i + 63 < nInputLen; i += 64)
        {
            Transform(&Input[i]);
        }
        nIndex = 0;
    }
    else
    {
        i = 0;
    }

    // Buffer remaining input
    memcpy(&m_lpszBuffer[nIndex], &Input[i], nInputLen - i);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Nexon additions

// @0x140698b10
void MD5Unknown0()
{
}

// @0x140698b20
void MD5Unknown1(void* p)
{
}

// @0x140698b30
void FindFilesRecursive(std::string strExt, std::string strPath, std::vector<std::string>& vecFiles, int nDepth,
                        int nMaxDepth)
{
    std::string strFind = strPath + "\\*.*";
    _finddata_t fd;
    long hFind = _findfirst(strFind.c_str(), &fd);
    int nResult = 1;
    if (hFind == -1)
        return;

    while (nResult != -1)
    {
        if (fd.attrib & _A_SUBDIR)
        {
            if (std::string("..").compare(fd.name) == 0)
            {
            }
            else if (std::string(".svn").compare(fd.name) == 0)
            {
            }
            else if (std::string(".").compare(fd.name) == 0)
            {
            }
            else
            {
                int nCount = std::count(strPath.begin(), strPath.end(), '\\');
                if (nCount < nDepth + nMaxDepth)
                    FindFilesRecursive(strExt, strPath + "\\" + fd.name, vecFiles, nDepth, nMaxDepth);
            }
        }
        else
        {
            std::string strName(fd.name);
            if (strName.find(strExt) != std::string::npos)
            {
                std::transform(strName.begin(), strName.end(), strName.begin(), tolower);
                vecFiles.push_back(strPath + "\\" + strName);
            }
        }
        nResult = _findnext(hFind, &fd);
    }
    _findclose(hFind);
}
