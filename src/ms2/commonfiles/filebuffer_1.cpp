// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: commonfiles\filebuffer.cpp#1
// MS2-RANGE: 0x14038b670-0x1403920a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1NotImplemented@CryptoPP@@UEAA@XZ 0x14038f420 ; order
// MS2-PIN: ??_E?$StringSinkTemplate@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@CryptoPP@@W7EAAPEAXI@Z 0x14038f954 ; unique
// MS2-PIN: ??_EBaseN_Encoder@CryptoPP@@W7EAAPEAXI@Z 0x14038f960 ; unique
// MS2-PIN: ??_EGrouper@CryptoPP@@W7EAAPEAXI@Z 0x14038f96c ; unique
// MS2-PIN: ??_EHexEncoder@CryptoPP@@W7EAAPEAXI@Z 0x14038f978 ; unique
// MS2-PIN: ??_ESimpleProxyFilter@CryptoPP@@W7EAAPEAXI@Z 0x14038f984 ; unique
// MS2-PIN: ??_GInvalidArgument@CryptoPP@@UEAAPEAXI@Z 0x14038fc90 ; prop
// MS2-PIN: ??_GNotImplemented@CryptoPP@@UEAAPEAXI@Z 0x14038fcd0 ; order
// MS2-PIN: ??_GParameterNotUsed@AlgorithmParametersBase@CryptoPP@@UEAAPEAXI@Z 0x14038fd10 ; order
// MS2-PIN: ?IsolatedFlush@?$Bufferless@VFilter@CryptoPP@@@CryptoPP@@UEAA_N_N0@Z 0x140390880 ; unique
// MS2-PIN: ?IsolatedFlush@?$Bufferless@VSink@CryptoPP@@@CryptoPP@@UEAA_N_N0@Z 0x1403908a0 ; unique
// MS2-PIN: ?IsolatedFlush@?$Unflushable@VFilter@CryptoPP@@@CryptoPP@@UEAA_N_N0@Z 0x1403908c0 ; unique
// MS2-PIN: ?ShouldPropagateMessageEnd@Filter@CryptoPP@@MEBA_NXZ 0x140390e50 ; unique
// MS2-PIN: ?ShouldPropagateMessageSeriesEnd@Filter@CryptoPP@@MEBA_NXZ 0x140390e60 ; unique
// MS2-PINS-END tplpin
// Preserved solver outputs from prior passes (local and global exact-caller maps).
// MS2-PIN: ??$forward@AEAPEAU?$_List_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@std@@YAAEAPEAU?$_List_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@0@AEAPEAU10@@Z 0x14038d610 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_List_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@2@XZ 0x140391390 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_List_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@2@XZ 0x1403913a0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_List_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@2@$00@std@@QEAAAEAV?$_List_val@U?$_List_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@2@XZ 0x1403913b0 ; unique
// Explicit RTTI data bindings: namespace-qualified secondary-base tables.
// MS2-PIN: ??_7SimpleProxyFilter@CryptoPP@@6BAlgorithm@1@@ 0x142d30918
// MS2-PIN: ??_7SimpleProxyFilter@CryptoPP@@6BWaitable@1@@ 0x142d30ae0
// MS2-PIN: ??_7BaseN_Encoder@CryptoPP@@6BAlgorithm@1@@ 0x142d30cc8
// MS2-PIN: ??_7BaseN_Encoder@CryptoPP@@6BWaitable@1@@ 0x142d30e50
// MS2-PIN: ??_7Grouper@CryptoPP@@6BAlgorithm@1@@ 0x142d30e70
// MS2-PIN: ??_7Grouper@CryptoPP@@6BWaitable@1@@ 0x142d30ff0
// MS2-PIN: ??_7HexEncoder@CryptoPP@@6BAlgorithm@1@@ 0x142d31010
// MS2-PIN: ??_7HexEncoder@CryptoPP@@6BWaitable@1@@ 0x142d311d8
// MS2-PIN: ??_7?$StringSinkTemplate@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@CryptoPP@@6BAlgorithm@1@@ 0x142d30b00
// MS2-PIN: ??_7?$StringSinkTemplate@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@CryptoPP@@6BWaitable@1@@ 0x142d30c68
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\filebuffer.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include "filebuffer_1.h"
#include <efd/MemoryDefines.h>
#include <intrin.h>
// Crypto++ was built with its assert() diagnostics disabled.
#define NDEBUG
#include <assert.h>
#include "../../../third_party/src/cryptopp562/sha.h"
#include "../../../third_party/src/cryptopp562/hex.h"
#undef NDEBUG
#include <assert.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
CString FUN_14016a600(const wchar_t*,int);
CString FUN_140390ea0(const wchar_t*,int);
CString FUN_140391100(const wchar_t*);
#ifdef __clang__
// Bind the already verified concatenation helper; clang inlines an unavailable
// MFC CopyChars import when compiling CString's friend operator+ here.
CString FUN_14038f6d0(const CString&, const char*);
#endif

// @0x14038b7c0
CFileBuffer::CFileBuffer() : m_pBuffer(0), m_nSize(0), m_field34(0), m_field38(0), m_key() {}

// @0x14038b840
CFileBuffer::~CFileBuffer()
{
    if (m_ownership == 0) {
        EE_FREE(m_pBuffer);
        m_pBuffer = 0;
    }
    m_pBuffer = 0;
    m_nSize = 0;
}

// @0x14038b8c0
void CFileBuffer::Allocate(unsigned size)
{
    MS2_ASSERT_AT(0x20, m_nSize == 0 && m_pBuffer == NULL);
    m_pBuffer = EE_MALLOC(size + 1);
    m_nSize = size;
    static_cast<char*>(m_pBuffer)[m_nSize] = 0;
    m_ownership = 0;
    m_field2c = 0;
    m_field30 = 0;
}
MS2_REPLACE_METHOD(0x14038b8c0, CFileBuffer, Allocate, 172, 0x94160591);

// @0x14038b980
void CFileBuffer::Adopt(void* data, unsigned size)
{
    MS2_ASSERT_AT(0x2e, m_nSize == 0 && m_pBuffer == NULL);
    m_pBuffer = data;
    m_nSize = size;
    m_ownership = 0;
    m_field2c = 0;
    m_field30 = 0;
}
MS2_REPLACE_METHOD(0x14038b980, CFileBuffer, Adopt, 137, 0x28D9DE4A);

// @0x14038ba10
void CFileBuffer::SetText(const CStringW& text)
{
    CString narrow = FUN_140390ea0(text,0);
    Allocate(narrow.GetAllocLength()+1);
    __movsb(static_cast<unsigned char*>(m_pBuffer), reinterpret_cast<const unsigned char*>(narrow.GetBuffer()), narrow.GetAllocLength());
    narrow.ReleaseBuffer();
}
MS2_REPLACE_METHOD(0x14038ba10, CFileBuffer, SetText, 164, 0x50F5091D);

// @0x14038baf0
unsigned CFileBuffer::GetSize() { return m_nSize; }
MS2_REPLACE_METHOD(0x14038baf0, CFileBuffer, GetSize, 14, 0xD26D6807);
// @0x14038bb10
void* CFileBuffer::GetBuffer() { return m_pBuffer; }
MS2_REPLACE_METHOD(0x14038bb10, CFileBuffer, GetBuffer, 15, 0xCBEE5D21);

// MS2-FUNCTIONAL: identical calls, flags, buffer sizes and control flow; one unused scalar has a different stack slot.
// @0x14038bb30
void FUN_14038bb30(const char* root, const char* relative, std::list<CString>& out)
{
    BOOL more = TRUE;
    unsigned __int64 fileSize;
    CString path(root);
    path.Append(relative);
    WIN32_FIND_DATAA found;
#ifdef __clang__
    HANDLE search = FindFirstFileA(FUN_14038f6d0(path,"*.*"), &found);
#else
    HANDLE search = FindFirstFileA(path + "*.*", &found);
#endif
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[3], directory[260], basename[256];
            _splitpath_s(path,drive,3,directory,260,basename,256,0,0);
            if ((found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0 && found.cFileName[0] != '.') {
                char child[260];
                sprintf_s(child,260,"%s%s%s/",drive,directory,found.cFileName);
                std::string unused(child);
                unused += "*.*";
                std::string subpath(relative);
                subpath += found.cFileName;
                subpath += "/";
                FUN_14038bb30(root,subpath.c_str(),out);
            }
            more = FindNextFileA(search,&found);
        }
        FindClose(search);
    }
    more = TRUE;
#ifdef __clang__
    search = FindFirstFileA(FUN_14038f6d0(path,"*.*"),&found);
#else
    search = FindFirstFileA(path + "*.*",&found);
#endif
    if (search != INVALID_HANDLE_VALUE) {
        while (more != FALSE) {
            char drive[3], directory[260], basename[256];
            _splitpath_s(path,drive,3,directory,260,basename,256,0,0);
            if ((found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
                CString name;
                name += relative;
                name += found.cFileName;
                out.push_back(name);
                fileSize = found.nFileSizeLow | (static_cast<unsigned __int64>(found.nFileSizeHigh) << 32);
            }
            more = FindNextFileA(search,&found);
        }
        FindClose(search);
    }
}
MS2_REPLACE(0x14038bb30, FUN_14038bb30, 1001, 0x0F1F4D97);

// Not hooked: constructs COnlinePatchFileBuffer with unit-local RTTI.
COnlinePatchFileBuffer* FUN_14038bf20(const char* root, const char* relative);
#ifndef MS2_HOOK_DLL
// @0x14038bf20
COnlinePatchFileBuffer* FUN_14038bf20(const char* root, const char* relative)
{
    CString path(root);
    path += relative;
    HANDLE file = CreateFileA(path,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,0,0);
    if (file == INVALID_HANDLE_VALUE) return 0;
    DWORD high = 0;
    DWORD low = GetFileSize(file,&high);
    unsigned __int64 size = (static_cast<unsigned __int64>(high)<<32) | low;
    char* bytes = new char[size];
    DWORD read = 0;
    ReadFile(file,bytes,static_cast<DWORD>(size),&read,0);
    CloseHandle(file);
    // Preserve the original failure paths and its low-DWORD byte-count test.
    if (read != static_cast<DWORD>(size)) return 0;
    std::string digest = FUN_14038c1f0(bytes,size);
    if (digest.length() == 0) return 0;
    COnlinePatchFileBuffer* result = new COnlinePatchFileBuffer;
    result->name = relative;
    result->data = bytes;
    result->size = size;
    result->digest = digest.c_str();
    return result;
}
#endif

// Not hooked: constructs Crypto++ objects with unit-local RTTI.
#ifndef MS2_HOOK_DLL
// @0x14038c1f0
std::string FUN_14038c1f0(const void* data, size_t size)
{
    if (data == 0) return std::string("");
    CryptoPP::SHA1 sha;
    CryptoPP::HexEncoder encoder;
    std::string result;
    byte digest[CryptoPP::SHA1::DIGESTSIZE];
    sha.CalculateDigest(digest,static_cast<const byte*>(data),size);
    encoder.Attach(new CryptoPP::StringSink(result));
    encoder.Put(digest,CryptoPP::SHA1::DIGESTSIZE);
    encoder.MessageEnd();
    return result;
}
#endif

// @0x14038e1b0
COnlinePatchFileBuffer::COnlinePatchFileBuffer() : data(0), size(0) {}

// @0x14038f1f0
COnlinePatchFileBuffer::~COnlinePatchFileBuffer()
{
    if (data != 0) delete[] static_cast<char*>(data);
    data = 0;
    size = 0;
}

// @0x140390ea0
CString FUN_140390ea0(const wchar_t* text, int)
{
    return FUN_140391100(text);
}
MS2_REPLACE(0x140390ea0, FUN_140390ea0, 63, 0xC1107041);

// @0x140391100
CString FUN_140391100(const wchar_t* text)
{
    CString result = FUN_14016a600(text, CP_UTF8);
    return result;
}
MS2_REPLACE(0x140391100, FUN_140391100, 101, 0x6F3B0172);
