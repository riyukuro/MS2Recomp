// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The web service client: the CSoapClient singleton and its
// requests (game ranking, mentee search, UGC upload), the answer type CSoapResult and the zlib / xor helpers of the
// answer bytes.
// MS2-UNIT: client\ms2\soapclient.cpp
// MS2-RANGE: 0x14176fbb0-0x141773630 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Clear@CComVariant@ATL@@QEAAJXZ 0x141772a70 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCUgcUploadCtrl@@@@V?$CElementTraits@V?$MS2Ptr@VCUgcUploadCtrl@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCUgcUploadCtrl@@@@_K@Z 0x141773200 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\soapclient.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <atlcomtime.h>
#include <comutil.h>
#pragma comment(lib, "comsuppw.lib")   // _com_util::ConvertBSTRToString (FUN_14274bfd0)
#include <stdio.h>
#include <stdlib.h>

#include "soapclient.h"
#include "ugchttpclient.h"
#include "gamerankingcli.h"
#include "ms2/client/ms2/menteesearch.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/csoapclient.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cugcuploadctrl.h"
#include "ms2/placeholder/exception.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/zlib125.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees and data (bound to the exe by their FUN_<va> / DAT_<va> names) ----

extern unsigned char DAT_1439f8630[16];             // the xor key of the answer bytes
extern int DAT_1439f8640;                           // its length
extern char DAT_142f6301c[];                        // "," the field separator of the upload answer

CFeatureManager* FUN_140166410();                   // the content switches
CLogString* GetLogString();
void FUN_1403a1280(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const char* const& pszArg);
int FUN_1406516b0();                                // the server kind
CUgcManager* FUN_14052d220();
CString FUN_140188f50(const char* psz, int n);
CString FUN_14016a5c0(const char* psz, int n);
void FUN_14015f050(const CString& str, ATL::CAtlArray<CString>& rOut, const char* pszSep);    // split into strings
int FUN_1427221f0(z_stream* pStream, int nFlush);   // inflate
unsigned char* FUN_141771b40(const char* pSource, int nSourceSize, int* pnOut);

// ---- CSoapClient ----

// @0x14176fbb0
CSoapClient::CSoapClient()
    : m_queue(10)
{
    m_nMode = 1;
}

// @0x14176fc60
CSoapClient::~CSoapClient()
{
}

// @0x14176fcf0
void CSoapClient::FUN_14176fcf0(CString strPath, int nMode)
{
    int nLength = strPath.GetLength() - 5;
    if (nMode == 2)
    {
        m_nMode = 2;
        nLength = strPath.GetLength() - 0xc;
        m_strPath = strPath.Mid(0, nLength);
    }
    else
    {
        m_nMode = 1;
        m_strPath = "";
    }
}

// @0x14176fde0
CString CSoapClient::GetError()
{
    return m_strError;
}

// @0x14176fe30
void CSoapClient::FUN_14176fe30(CString strError)
{
    m_strError = strError;
    const char* pszError = strError;
    FUN_1403a1280(GetLogString(), 1, 0x13, L"[E] soap : {0}", pszError);
}

// Sends the upload and its image (the blueprint case) of the current UGC manager upload, file by file.
// MS2-FUNCTIONAL: same flow, throws and calls; MS2Ptr/CAtlArray copy temps and the second cleanup buffer are laid out differently.
// @0x14176feb0
int CSoapClient::FUN_14176feb0()
{
    MS2Ptr<CUgcUploadCtrl> spCtrl(0);
    ATL::CAtlArray<MS2Ptr<CUgcUploadCtrl> > arrUploads;
    CString strResult("");
    CFileException exFile(0, -1, 0);
    unsigned char* pBuffer = 0;

    spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        throw Exception(CString("pUgcUploadCtrl"), 0xd);
    if (spCtrl->GetImage().get() != 0)
        arrUploads.Add(spCtrl->GetImage());
    arrUploads.Add(spCtrl);
    for (size_t i = 0; i < arrUploads.GetCount(); ++i)
    {
        MS2Ptr<CUgcUploadCtrl> spUpload = arrUploads[i];
        CStringW strPath = spUpload->GetResult();
        if (strPath.GetLength() == 0)
            throw Exception(CString("UploadFilePath"), 0xf);
        CStringW strMode(L"rb");
        FILE* pFile = _wfopen(strPath, strMode);
        if (pFile == 0)
            throw Exception(CString("file.Open"));
        fseek(pFile, 0, SEEK_END);
        long nSize = ftell(pFile);
        if (nSize == 0 || nSize > 0xfffff)
            throw Exception(CString("UploadFilePath"), 0xd2);
        fseek(pFile, 0, SEEK_SET);
        pBuffer = new unsigned char[nSize];
        fread(pBuffer, 1, nSize, pFile);
        MS2Ptr<CSoapResult> spResult(0);
        if (m_nMode != 2)
            throw Exception(CString("NoUploadWithSoap"), 1);
        spResult = FUN_141771040(spUpload, nSize, pBuffer);
        strResult = spResult->m_strText;
        fclose(pFile);
        DeleteFileW(strPath);
        if (pBuffer != 0)
        {
            delete[] pBuffer;
            pBuffer = 0;
        }
    }
    if (pBuffer != 0)
        delete[] pBuffer;
    FUN_14052d220()->FUN_141882d80(spCtrl, 0, strResult);
    return 0;
}

// @0x141770670
MS2Ptr<CGameRankingWebResult> CSoapClient::FUN_141770670(MS2Ptr<CGameRankingParam> spParam)
{
    MS2Ptr<CGameRankingWebResult> spResult(new CGameRankingWebResult);
    if (FUN_140166410()->FUN_14036d570(0x3f) == 0)
    {
        spResult->m_result = 1;
        return spResult;
    }
    if (spParam == 0)
    {
        spResult->m_result = 0x1f;
        return spResult;
    }
    CByteBuffer buffer;
    buffer.WriteInt32(spParam->m_key.m_type);
    buffer.WriteInt32(spParam->m_24);
    buffer.WriteInt64(spParam->m_28);
    buffer.WriteInt64(spParam->m_30);
    buffer.WriteInt64(spParam->m_38);
    buffer.WriteInt32(spParam->m_key.m_sub);
    buffer.WriteInt32(spParam->m_key.m_date);
    int nLen = spParam->m_search.GetLength() * 2;
    buffer.WriteInt32(nLen);
    buffer.WriteBytes(spParam->m_search.GetBuffer(), nLen);
    int nTry = 0;
    int nError = 1;
    char* pBody = 0;
    int nBodySize = 0;
    while (1)
    {
        if (++nTry > 3)
            break;
        CUgcHttpClient http;
        http.Append(buffer);
        CString strUrl = Unk_SocketFormat("{0}{1}", m_strPath, "irrq.aspx");
        if (!http.Request(strUrl))
        {
            nError = 0xc;
            Sleep(500);
            continue;
        }
        nBodySize = http.Result();
        pBody = http.Body();
        nError = 0;
        break;
    }
    spResult->m_result = nError;
    if (nError == 0)
    {
        int nOut = 0;
        unsigned char* pData = FUN_141771b40(pBody, nBodySize, &nOut);
        if (nOut == 0)
        {
            spResult->m_result = 0xc;
            return spResult;
        }
        spResult->m_buffer.WriteBytes(pData, nOut);
        spResult->m_buffer.FUN_140720e90(0);
        if (pData != 0)
        {
            delete[] pData;
            pData = 0;
        }
    }
    return spResult;
}

// @0x141770be0
MS2Ptr<CMenteeSearchWebResult> CSoapClient::FUN_141770be0(MS2Ptr<CMenteeSearchParam> spParam)
{
    MS2Ptr<CMenteeSearchWebResult> spResult(new CMenteeSearchWebResult);
    if (FUN_140166410()->FUN_14036d570(0x91) == 0)
    {
        spResult->m_nResult = 1;
        return spResult;
    }
    if (spParam == 0)
    {
        spResult->m_nResult = 0x1f;
        return spResult;
    }
    CByteBuffer buffer;
    buffer.WriteInt32(spParam->m_nCharType);
    buffer.WriteInt64(spParam->m_nAccountId);
    buffer.WriteInt64(spParam->m_nCharacterId);
    buffer.WriteInt32(spParam->m_nOption30);
    buffer.WriteInt32(spParam->m_nOption34);
    int nTry = 0;
    int nError = 1;
    char* pBody = 0;
    int nBodySize = 0;
    while (1)
    {
        if (++nTry > 3)
            break;
        CUgcHttpClient http;
        http.Append(buffer);
        CString strUrl = Unk_SocketFormat("{0}{1}", m_strPath, "ruq.aspx");
        if (!http.Request(strUrl))
        {
            nError = 0xc;
            Sleep(500);
            continue;
        }
        nBodySize = http.Result();
        pBody = http.Body();
        nError = 0;
        break;
    }
    spResult->m_nResult = nError;
    if (nError == 0)
    {
        int nOut = 0;
        unsigned char* pData = FUN_141771b40(pBody, nBodySize, &nOut);
        spResult->m_buffer.WriteBytes(pData, nOut);
        spResult->m_buffer.FUN_140720e90(0);
        if (pData != 0)
        {
            delete[] pData;
            pData = 0;
        }
    }
    return spResult;
}

// @0x141771040
MS2Ptr<CSoapResult> CSoapClient::FUN_141771040(MS2Ptr<CUgcUploadCtrl> spCtrl, int nSize, void* pData)
{
    if (spCtrl == 0)
        return MS2Ptr<CSoapResult>(new CSoapResult(0xd, ""));
    CByteBuffer buffer;
    buffer.WriteInt32(spCtrl->m_user.m_nType);
    buffer.WriteInt32(spCtrl->m_nKind);
    buffer.WriteInt64(spCtrl->m_user.m_accountId);
    buffer.WriteInt64(spCtrl->m_user.m_characterId);
    buffer.WriteInt64(spCtrl->m_upload.m_uid);
    buffer.WriteInt64(spCtrl->FUN_1418a41a0());
    buffer.WriteInt64(nSize);
    buffer.WriteBytes(pData, nSize);
    int nCode = 0;
    CString strText("");
    int nTry = 0;
    int nMax = 3;
    if (FUN_1406516b0() == 3)
        nMax = 1;
    while (1)
    {
        if (++nTry > nMax)
            break;
        CUgcHttpClient http;
        http.Append(buffer);
        CString strUrl = Unk_SocketFormat("{0}{1}", m_strPath, "urq.aspx");
        if (!http.Request(strUrl))
        {
            nCode = 5;
            Sleep(500);
            continue;
        }
        char* pBody = http.Body();
        CString strBody = FUN_140188f50(pBody, 0);
        ATL::CAtlArray<CString> arrFields;
        FUN_14015f050(strBody, arrFields, DAT_142f6301c);
        if (arrFields.GetCount() != 2)
        {
            nCode = 6;
            Sleep(500);
            continue;
        }
        nCode = atoi(arrFields[0]);
        strText = FUN_14016a5c0(arrFields[1], 0);
        break;
    }
    MS2Ptr<CSoapResult> spResult(new CSoapResult);
    spResult->m_nResult = nCode;
    spResult->m_strText = strText;
    return spResult;
}

// @0x141771600
CString CSoapClient::FUN_141771600(ATL::CComVariant vValue)
{
    CString strValue;
    switch (vValue.vt)
    {
    case VT_I2:
    case VT_UI1:
        strValue = FUN_141771900(vValue.iVal);
        break;
    case VT_I4:
        strValue = FUN_141771900(vValue.lVal);
        break;
    case VT_DECIMAL:
        if (vValue.decVal.sign != 0)
            vValue.decVal.Lo64 = -(__int64)vValue.decVal.Lo64;
        strValue = FUN_1417719b0(vValue.decVal.Lo64);
        break;
    case VT_DATE:
    {
        ATL::COleDateTime dt(vValue);
        strValue = (LPCSTR)dt.Format("%Y-%m-%d %H:%M:%S");
        break;
    }
    case VT_BSTR:
    {
        char* pszText = _com_util::ConvertBSTRToString(vValue.bstrVal);
        strValue = pszText;
        delete[] pszText;
        break;
    }
    default:
        MS2_ASSERT_AT(0xe7, 0);
        break;
    }
    return strValue;
}

// @0x141771900
CString CSoapClient::FUN_141771900(int nValue)
{
    CString strText;
    char szBuf[16];
    _itoa(nValue, szBuf, 10);
    strText = szBuf;
    return strText;
}

// @0x1417719b0
CString CSoapClient::FUN_1417719b0(__int64 nValue)
{
    CString strText;
    char szBuf[24];
    _i64toa(nValue, szBuf, 20);
    strText = szBuf;
    return strText;
}

// ---- the answer bytes ----

// Xors the bytes with the repeating key (the key length is made odd-ish by the remainder rule).
// @0x141771a60
void FUN_141771a60(char* pData, int nSize)
{
    int nHalf = DAT_1439f8640 / 2;
    int nRem = nSize % DAT_1439f8640;
    int nStep = 0;
    if (nRem < nHalf)
        nStep = DAT_1439f8640 - nRem;
    else
        nStep = nRem;
    int nKey = 0;
    int nIdx = 0;
    for (int i = 0; i < nSize; ++i)
    {
        nIdx = nKey % nStep;
        ((unsigned char*)pData)[i] ^= DAT_1439f8630[nIdx];
        ++nKey;
    }
}

// zlib's zpipe inf() over a memory block: returns the new[]'d result (doubling from 1 MB) or 0.
// MS2-FUNCTIONAL: same zlib calls, buffer growth and results; locals are laid out differently.
// @0x141771b40
unsigned char* FUN_141771b40(const char* pSource, int nSourceSize, int* pnOut)
{
    *pnOut = 0;
    z_stream strm;
    unsigned char in[0x20000];
    unsigned char out[0x30000];
    memset(&strm, 0, sizeof(strm));
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    if (inflateInit(&strm) != Z_OK)
        return 0;
    int nRead = 0;
    int nCapacity = 0x100000;
    unsigned char* pResult = new unsigned char[nCapacity];
    int nTotal = 0;
    int status = 0;
    do
    {
        if (nSourceSize - nRead < 0x20000)
        {
            memcpy(in, pSource, nSourceSize - nRead);
            strm.avail_in = nSourceSize - nRead;
            nRead = nSourceSize;
        }
        else
        {
            memcpy(in, pSource, 0x20000);
            strm.avail_in = 0x20000;
            nRead += 0x20000;
        }
        if (strm.avail_in == 0)
            break;
        strm.next_in = in;
        do
        {
            strm.avail_out = 0x30000;
            strm.next_out = out;
            status = FUN_1427221f0(&strm, Z_NO_FLUSH);
            if (status == Z_STREAM_ERROR)
                return 0;
            if (status > Z_BUF_ERROR && (status < Z_STREAM_ERROR || status == Z_NEED_DICT))
            {
                inflateEnd(&strm);
                return 0;
            }
            unsigned have = 0x30000 - strm.avail_out;
            if (nCapacity <= (int)(nTotal + have))
            {
                nCapacity <<= 1;
                unsigned char* pNew = new unsigned char[nCapacity];
                memcpy(pNew, pResult, nTotal);
                if (pResult != 0)
                    delete[] pResult;
                pResult = pNew;
            }
            memcpy(pResult + nTotal, out, have);
            nTotal += have;
        } while (strm.avail_out == 0);
    } while (status != Z_STREAM_END);
    inflateEnd(&strm);
    if (status == Z_STREAM_END)
        *pnOut = nTotal;
    else
        pResult = 0;
    return pResult;
}

// Swaps the two halves of the bytes.
// @0x141771e40
void FUN_141771e40(char* pData, int nSize)
{
    int nHalf = nSize / 2;
    for (int i = 0; i < nHalf; ++i)
    {
        char c = pData[i];
        pData[i] = pData[nHalf + i];
        pData[nHalf + i] = c;
    }
}

// ---- CSoapResult ----

// @0x141772820
CSoapResult::CSoapResult(int nResult, const CString& strText)
{
    m_nResult = nResult;
    m_strText = strText;
}

// @0x1417728a0
CSoapResult::CSoapResult()
{
    m_nResult = 1;
    m_strText = "";
}

MS2_EMIT_CRT_MEMMOVE_S();
