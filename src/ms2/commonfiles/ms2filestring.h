// Pack archives (.m2h index + .m2d data) from commonfiles\ms2filestring.cpp. Class names: RTTI for the stream/header
// version classes; CPackFile (after the v2525 snapshot) and CMS2FileString (after the TU name) are invented.
// filesystem.h keeps its own opaque stand-ins (Unk_FileArchive / Unk_FileArchiveIndex) for the same objects.
#pragma once
#include <windows.h>
#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tfunctor.h"
#include "ms2/placeholder/zlib125.h"

#define MS2_PACK_MAGIC_V1 0x4632534d  // 'MS2F'
#define MS2_PACK_MAGIC_V2 0x4632534e  // 'NS2F'
#define MS2_PACK_MAGIC_V3 0x4632534f  // 'OS2F'
#define MS2_PACK_MAGIC_V4 0x46325350  // 'PS2F' (version-3 layouts)

typedef TFunctor<unsigned long, ParamList<unsigned long, ParamList<unsigned char*, ParamList<unsigned long,
    ParamList<unsigned char**, ParamList<unsigned long, EmptyParam>>>>>> CPackDecodeFunctor;

// Per-entry encoding flags: byte 0 nonzero = zlib-deflated, bit 0 of byte 3 = decoded by the "short" functor.
struct CPackEncodeFlags {
    union {
        unsigned char m_flags[4];
        unsigned int m_value;
    };
};
MS2_CHECK_SIZE(CPackEncodeFlags, 4);

// .m2h stream header (the archive's own header, read right after the magic).
class CPackStreamVerBase {
public:
    CPackStreamVerBase() : m_magic(MS2_PACK_MAGIC_V1) {}
    virtual ~CPackStreamVerBase() {}
    virtual unsigned int GetHeaderSize() = 0;
    virtual void* GetHeaderData() = 0;
    virtual unsigned __int64 GetTableCompressedSize() = 0;
    virtual unsigned __int64 GetTableEncodedSize() = 0;
    virtual unsigned __int64 GetListSize() = 0;
    virtual unsigned __int64 GetListCompressedSize() = 0;
    virtual unsigned __int64 GetListEncodedSize() = 0;
    virtual unsigned int GetFileCount() = 0;
    virtual unsigned __int64 GetTableSize() = 0;
    virtual void SetMagic(unsigned int magic) = 0;
    virtual void SetTableCompressedSize(unsigned __int64 size) = 0;
    virtual void SetTableEncodedSize(unsigned __int64 size) = 0;
    virtual void SetListSize(unsigned __int64 size) = 0;
    virtual void SetListCompressedSize(unsigned __int64 size) = 0;
    virtual void SetListEncodedSize(unsigned __int64 size) = 0;
    virtual void SetFileCount(unsigned int count) = 0;
    virtual void SetTableSize(unsigned __int64 size) = 0;
    unsigned int m_magic;
};
MS2_CHECK_SIZE(CPackStreamVerBase, 0x10);

#pragma pack(push, 4)
struct CPackStreamVer1Data {
    unsigned int m_reserved;
    unsigned __int64 m_tableCompressedSize;
    unsigned __int64 m_tableEncodedSize;
    unsigned __int64 m_listSize;
    unsigned __int64 m_listCompressedSize;
    unsigned __int64 m_listEncodedSize;
    unsigned int m_fileCount;
    unsigned int m_unknown;
    unsigned __int64 m_tableSize;
};
struct CPackStreamVer2Data {
    unsigned int m_fileCount;
    unsigned __int64 m_tableCompressedSize;
    unsigned __int64 m_tableEncodedSize;
    unsigned __int64 m_listSize;
    unsigned __int64 m_listCompressedSize;
    unsigned __int64 m_listEncodedSize;
    unsigned __int64 m_tableSize;
};
#pragma pack(pop)
MS2_CHECK_SIZE(CPackStreamVer1Data, 0x3c);
MS2_CHECK_SIZE(CPackStreamVer2Data, 0x34);
struct CPackStreamVer3Data {
    unsigned int m_fileCount;
    unsigned int m_flags;
    unsigned __int64 m_tableCompressedSize;
    unsigned __int64 m_tableEncodedSize;
    unsigned __int64 m_listSize;
    unsigned __int64 m_listCompressedSize;
    unsigned __int64 m_listEncodedSize;
    unsigned __int64 m_tableSize;
};
MS2_CHECK_SIZE(CPackStreamVer3Data, 0x38);

class CPackStreamVer1 {
public:
    CPackStreamVer1() { memset(&m_data, 0, sizeof(m_data)); }
    virtual ~CPackStreamVer1() {}
    CPackStreamVer1Data m_data;
};
class CPackStreamVer2 {
public:
    CPackStreamVer2() { memset(&m_data, 0, sizeof(m_data)); }
    virtual ~CPackStreamVer2() {}
    CPackStreamVer2Data m_data;
};
class CPackStreamVer3 {
public:
    CPackStreamVer3() { memset(&m_data, 0, sizeof(m_data)); }
    virtual ~CPackStreamVer3() {}
    CPackStreamVer3Data m_data;
};
MS2_CHECK_SIZE(CPackStreamVer1, 0x48);
MS2_CHECK_SIZE(CPackStreamVer2, 0x40);
MS2_CHECK_SIZE(CPackStreamVer3, 0x40);

template<class T> class PackFileStream : public CPackStreamVerBase, public T {
public:
    virtual unsigned int GetHeaderSize() { return sizeof(this->m_data); }
    virtual void* GetHeaderData() { return &this->m_data; }
    virtual unsigned __int64 GetTableCompressedSize() { return this->m_data.m_tableCompressedSize; }
    virtual unsigned __int64 GetTableEncodedSize() { return this->m_data.m_tableEncodedSize; }
    virtual unsigned __int64 GetListSize() { return this->m_data.m_listSize; }
    virtual unsigned __int64 GetListCompressedSize() { return this->m_data.m_listCompressedSize; }
    virtual unsigned __int64 GetListEncodedSize() { return this->m_data.m_listEncodedSize; }
    virtual unsigned int GetFileCount() { return this->m_data.m_fileCount; }
    virtual unsigned __int64 GetTableSize() { return this->m_data.m_tableSize; }
    virtual void SetMagic(unsigned int magic) { m_magic = magic; }
    virtual void SetTableCompressedSize(unsigned __int64 size) { this->m_data.m_tableCompressedSize = size; }
    virtual void SetTableEncodedSize(unsigned __int64 size) { this->m_data.m_tableEncodedSize = size; }
    virtual void SetListSize(unsigned __int64 size) { this->m_data.m_listSize = size; }
    virtual void SetListCompressedSize(unsigned __int64 size) { this->m_data.m_listCompressedSize = size; }
    virtual void SetListEncodedSize(unsigned __int64 size) { this->m_data.m_listEncodedSize = size; }
    virtual void SetFileCount(unsigned int count) { this->m_data.m_fileCount = count; }
    virtual void SetTableSize(unsigned __int64 size) { this->m_data.m_tableSize = size; }
    unsigned int GetFlags() { return this->m_data.m_flags; }  // version 3 only
};
MS2_CHECK_SIZE(PackFileStream<CPackStreamVer1>, 0x58);
MS2_CHECK_SIZE(PackFileStream<CPackStreamVer2>, 0x50);
MS2_CHECK_SIZE(PackFileStream<CPackStreamVer3>, 0x50);

// One file-table entry of the .m2h (decoded and inflated), and the scratch descriptor Open() inflates through.
class CPackFileHeaderVerBase {
public:
    CPackFileHeaderVerBase() {}
    virtual ~CPackFileHeaderVerBase() {}
    virtual unsigned int GetHeaderSize() = 0;
    virtual void* GetHeaderData() = 0;
    virtual unsigned int GetIndex() = 0;
    virtual CPackEncodeFlags GetEncodeFlags() = 0;
    virtual unsigned __int64 GetOffset() = 0;
    virtual unsigned int GetEncodedSize() = 0;
    virtual unsigned __int64 GetCompressedSize() = 0;
    virtual unsigned __int64 GetSize() = 0;
    virtual void SetIndex(unsigned int index) = 0;
    virtual void SetEncodeFlags(CPackEncodeFlags flags) = 0;
    virtual void SetOffset(unsigned __int64 offset) = 0;
    virtual void SetEncodedSize(unsigned int size) = 0;
    virtual void SetCompressedSize(unsigned __int64 size) = 0;
    virtual void SetSize(unsigned __int64 size) = 0;
};
MS2_CHECK_SIZE(CPackFileHeaderVerBase, 8);

struct CPackFileHeaderVer1Data {
    unsigned int m_reserved;
    unsigned int m_index;
    CPackEncodeFlags m_encodeFlags;
    unsigned __int64 m_offset;
    unsigned int m_encodedSize;
    unsigned __int64 m_compressedSize;
    unsigned __int64 m_size;
};
#pragma pack(push, 4)
struct CPackFileHeaderVer2Data {
    CPackEncodeFlags m_encodeFlags;
    unsigned int m_index;
    unsigned int m_encodedSize;
    unsigned __int64 m_compressedSize;
    unsigned __int64 m_size;
    unsigned __int64 m_offset;
};
#pragma pack(pop)
struct CPackFileHeaderVer3Data {
    CPackEncodeFlags m_encodeFlags;
    unsigned int m_index;
    unsigned int m_encodedSize;
    unsigned int m_extra;
    unsigned __int64 m_compressedSize;
    unsigned __int64 m_size;
    unsigned __int64 m_offset;
};
MS2_CHECK_SIZE(CPackFileHeaderVer1Data, 0x30);
MS2_CHECK_SIZE(CPackFileHeaderVer2Data, 0x24);
MS2_CHECK_SIZE(CPackFileHeaderVer3Data, 0x28);

class CPackFileHeaderVer1 {
public:
    CPackFileHeaderVer1(const void* data) { memcpy_s(&m_data, sizeof(m_data), data, sizeof(m_data)); }
    CPackFileHeaderVer1() { memset(&m_data, 0, sizeof(m_data)); }
    virtual ~CPackFileHeaderVer1() {}
    CPackFileHeaderVer1Data m_data;
};
class CPackFileHeaderVer2 {
public:
    CPackFileHeaderVer2(const void* data) { memcpy_s(&m_data, sizeof(m_data), data, sizeof(m_data)); }
    CPackFileHeaderVer2() { memset(&m_data, 0, sizeof(m_data)); }
    virtual ~CPackFileHeaderVer2() {}
    CPackFileHeaderVer2Data m_data;
};
class CPackFileHeaderVer3 {
public:
    CPackFileHeaderVer3(const void* data) { memcpy_s(&m_data, sizeof(m_data), data, sizeof(m_data)); }
    CPackFileHeaderVer3() { memset(&m_data, 0, sizeof(m_data)); }
    virtual ~CPackFileHeaderVer3() {}
    virtual unsigned int GetExtra() { return m_data.m_extra; }
    virtual void SetExtra(unsigned int extra) { m_data.m_extra = extra; }
    CPackFileHeaderVer3Data m_data;
};
MS2_CHECK_SIZE(CPackFileHeaderVer1, 0x38);
MS2_CHECK_SIZE(CPackFileHeaderVer2, 0x30);
MS2_CHECK_SIZE(CPackFileHeaderVer3, 0x30);

template<class T> class PackFileHeader : public CPackFileHeaderVerBase, public T {
public:
    PackFileHeader(const void* data) : T(data) {}
    PackFileHeader() {}
    virtual unsigned int GetHeaderSize() { return sizeof(this->m_data); }
    virtual void* GetHeaderData() { return &this->m_data; }
    virtual unsigned int GetIndex() { return this->m_data.m_index; }
    virtual CPackEncodeFlags GetEncodeFlags() { return this->m_data.m_encodeFlags; }
    virtual unsigned __int64 GetOffset() { return this->m_data.m_offset; }
    virtual unsigned int GetEncodedSize() { return this->m_data.m_encodedSize; }
    virtual unsigned __int64 GetCompressedSize() { return this->m_data.m_compressedSize; }
    virtual unsigned __int64 GetSize() { return this->m_data.m_size; }
    virtual void SetIndex(unsigned int index) { this->m_data.m_index = index; }
    virtual void SetEncodeFlags(CPackEncodeFlags flags) { this->m_data.m_encodeFlags = flags; }
    virtual void SetOffset(unsigned __int64 offset) { this->m_data.m_offset = offset; }
    virtual void SetEncodedSize(unsigned int size) { this->m_data.m_encodedSize = size; }
    virtual void SetCompressedSize(unsigned __int64 size) { this->m_data.m_compressedSize = size; }
    virtual void SetSize(unsigned __int64 size) { this->m_data.m_size = size; }
};
MS2_CHECK_SIZE(PackFileHeader<CPackFileHeaderVer1>, 0x40);
MS2_CHECK_SIZE(PackFileHeader<CPackFileHeaderVer2>, 0x38);
MS2_CHECK_SIZE(PackFileHeader<CPackFileHeaderVer3>, 0x38);

// One file-list entry: file index and the (encoded) archive suffix of its .m2d. A plain class, not std::pair: its
// implicit dtor sorts after ~CPackStreamVerBase in the exe's COMDAT tail, and ~pair<int, string> has its own copy.
class SFileStringInfo {
public:
    SFileStringInfo() : m_index(0) {}
    int m_index;
    std::string m_archive;
};
MS2_CHECK_SIZE(SFileStringInfo, 0x28);

// The .m2h file list ("index,name" or "index,archive,name" lines) and the open .m2d handles.
class CMS2FileString {
public:
    typedef std::map<std::string, SFileStringInfo> FileMap;
    ~CMS2FileString();
    int GetIndex(std::string name);
    int Add(std::string path);
    int Add(std::string path, std::string archive);
    std::string GetName(unsigned int index);
    int Load(char* data, unsigned int size);
    int Save(HANDLE file);
    void Parse(char* line);
    bool Find(std::string name, SFileStringInfo& info);
    void GetArchiveNames(std::set<std::string>& names);
    int Open(unsigned int magic, std::string path, std::map<unsigned int, HANDLE>& handles, const char* directory);
    int OpenSingle(unsigned int magic, std::string path, std::map<unsigned int, HANDLE>& handles, const char* directory);
    int Create(unsigned int magic, std::string path, std::map<unsigned int, HANDLE>& handles);
    int CreateSingle(unsigned int magic, std::string path, std::map<unsigned int, HANDLE>& handles);
    static char* Encode(std::string name);
    static char* ToMultiByte(const wchar_t* text);
    static wchar_t* ToWide(const char* text);
    static size_t CountLetters(const char* text, size_t length);
    static int GetLetterCode(char c);
    FileMap& GetFiles() { return m_files; }
    FileMap m_files;
    std::map<std::string, HANDLE> m_archives;
    std::map<unsigned int, std::string> m_names;
};
MS2_CHECK_SIZE(CMS2FileString, 0x30);

class CPackFile {
public:
    CPackFile();
    CPackFile(std::string path, CPackDecodeFunctor decode, CPackDecodeFunctor decodeShort);
    ~CPackFile();
    int Open(std::string path, const char* directory);
    int Read(std::string path, unsigned char** data, unsigned __int64* size, bool stringFile);
    void Close();
    bool Exists(std::string path);
    int IsPacked(std::string path, bool stringFile);
    int Contains(std::string text);
    void GetTexturePaths(std::list<std::string>& paths);
    void SetDecode(CPackDecodeFunctor decode);
    void SetDecodeShort(CPackDecodeFunctor decode);
    CPackFileHeaderVerBase* GetHeader(std::string path);
    int Inflate(HANDLE file, CPackFileHeaderVerBase* header, unsigned char** out, unsigned __int64 capacity,
                unsigned __int64* written);
    CPackFileHeaderVerBase* GetHeader(unsigned int index);
    std::string GetModePath(std::string path);
    std::string GetLocalePath(std::string path, bool stringFile);
    const std::string& GetPath() { return m_path; }
    CMS2FileString& GetIndex() { return m_index; }
    std::string m_path;
    CMS2FileString m_index;
    z_stream m_stream;
    unsigned __int64 m_remaining;
    CLockCriticalSection m_lock;
    std::map<unsigned int, CPackFileHeaderVerBase*> m_headers;
    CPackDecodeFunctor m_decode;
    CPackDecodeFunctor m_decodeShort;
    unsigned int m_magic;
    std::map<unsigned int, HANDLE> m_handles;
    LONGLONG m_elapsed;
    LARGE_INTEGER m_start;
};
MS2_CHECK_OFFSET(CPackFile, m_index, 0x20);
MS2_CHECK_OFFSET(CPackFile, m_stream, 0x50);
MS2_CHECK_OFFSET(CPackFile, m_remaining, 0xa8);
MS2_CHECK_OFFSET(CPackFile, m_lock, 0xb0);
MS2_CHECK_OFFSET(CPackFile, m_headers, 0xe0);
MS2_CHECK_OFFSET(CPackFile, m_decode, 0xf0);
MS2_CHECK_OFFSET(CPackFile, m_magic, 0x100);
MS2_CHECK_OFFSET(CPackFile, m_handles, 0x108);
MS2_CHECK_OFFSET(CPackFile, m_elapsed, 0x118);
MS2_CHECK_SIZE(CPackFile, 0x128);
