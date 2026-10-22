// CFileSystem: layout from ctor 0x1403962b0; deleting dtor allocates 0x1c8.
#pragma once
#include <atlcoll.h>
#include <map>
#include <list>
#include <string>
#include <vector>
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/filebuffer_1.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/placeholder/tfunctor.h"
typedef TFunctor<unsigned long, ParamList<unsigned long, ParamList<unsigned char*,
    ParamList<unsigned long, ParamList<unsigned char**, ParamList<unsigned long, EmptyParam>>>>>> Unk_FileTransform;
MS2_CHECK_SIZE(Unk_FileTransform, 8);

// Archive reader from ms2filestring.cpp. Construction at 0x1406af2f0;
// allocation in CFileSystem is 0x128. Its implementation remains external.
struct Unk_FileArchiveEntry {
    int index;
    std::string metadata;
};
MS2_CHECK_SIZE(Unk_FileArchiveEntry, 0x28);
MS2_CHECK_OFFSET(Unk_FileArchiveEntry, metadata, 8);
class Unk_FileArchiveIndex {
public:
    typedef std::map<std::string, Unk_FileArchiveEntry> Entries;
    Entries& FUN_1403a9580();
    Entries entries;
    // The original constructor initializes two further 16-byte maps.
    unsigned char otherMaps[0x20];
};
MS2_CHECK_SIZE(Unk_FileArchiveIndex, 0x30);
MS2_CHECK_OFFSET(Unk_FileArchiveIndex, entries, 0);
class Unk_FileArchive {
public:
    Unk_FileArchive();
    ~Unk_FileArchive();
    void FUN_1406b1450();
    int FUN_1406af680(std::string path, int mode);
    void FUN_1406b1ad0(Unk_FileTransform transform);
    void FUN_1406b1b20(Unk_FileTransform transform);
    int FUN_1406b1760(std::string path);
    int FUN_1406b14f0(std::string path, bool stringResource);
    int FUN_1406b1460(std::string path);
    int FUN_1406b0e20(std::string path, void** data, unsigned __int64* size, bool stringResource);
    void FUN_1406b1830(std::list<std::string>& textures);
    const std::string& FUN_1403a9490();
    Unk_FileArchiveIndex& FUN_1403a93e0();
    std::string path;
    Unk_FileArchiveIndex index;
    unsigned char remaining[0xd8];
};
MS2_CHECK_SIZE(Unk_FileArchive, 0x128);
MS2_CHECK_OFFSET(Unk_FileArchive, path, 0);
MS2_CHECK_OFFSET(Unk_FileArchive, index, 0x20);

class CFileSystem : public TSingleton<CFileSystem> {
public:
    typedef Unk_PayloadPtr<CFileBuffer> BufferPtr;
    typedef ATL::CRBMap<CString, BufferPtr, ATL::CStringElementTraits<CString>> Cache;
    CFileSystem();
    virtual ~CFileSystem();
    int FUN_140396770(unsigned char mode, int archiveMode);
    int FUN_140396d00(const char* directory);
    int FUN_1403972f0(const char* path, void** data, unsigned __int64* size, std::string* actualPath);
    int FUN_1403974b0(TiXmlDocument* document, const char* path, int encoding, bool warn, bool localOnly);
    BufferPtr FUN_140397bc0(const char* path, int cacheMode, int flag);
    bool FUN_140398190();
    bool FUN_1403981b0();
    bool FUN_1403981d0();
    int FUN_1403979e0(TiXmlDocument* document, BufferPtr buffer);
    int FUN_140397ab0(TiXmlDocument* document, const CStringW& xml);
    bool FUN_140398200(std::string path);
    bool FUN_140398640(std::string path, bool checkFile);
    int FUN_1403987d0(std::string path);
    bool FUN_14039a160(const char* directory, const char* reference, char* result, unsigned capacity);
    void FUN_14039a640();
    void FUN_14039a660(CString path, void* pUnused);
    unsigned FUN_14039a720();
    void FUN_14039a740();
    unsigned long FUN_14039a790(unsigned long magic, unsigned char* data, unsigned long size,
                                unsigned char** output, unsigned long capacity);
    unsigned long FUN_14039a8a0(unsigned char*,unsigned long,unsigned char**,unsigned long);
    unsigned long FUN_14039aba0(unsigned char*,unsigned long,unsigned char**,unsigned long);
    unsigned long FUN_14039ae90(unsigned char*,unsigned long,unsigned char**,unsigned long);
    unsigned long FUN_14039b180(unsigned char*,unsigned long,unsigned char**,unsigned long);
    unsigned long FUN_14039b470(unsigned long magic, unsigned char* data, unsigned long size,
                                unsigned char** output, unsigned long capacity);
    void FUN_14039b660();
    void FUN_14039b6b0();
    void FUN_14039b7d0(int enabled);
    std::string FUN_14039b810(std::string path);
    std::string FUN_14039bb50(std::string path);
    bool FUN_14039bf70();
    void FUN_14039bf80(std::string& path);
    std::string FUN_14039c050(std::string path, bool checkFile);
    BufferPtr FUN_14039c810(std::string path, int flag);
    BufferPtr FUN_14039cc50(std::string path, int flag);
    BufferPtr FUN_14039d190(std::string resolved, std::string original, int flag);
    void FUN_14039d530(CString& pattern, CString& directory, ATL::CAtlArray<CString>& output, CString& exclude);
    void FUN_14039d9f0(CString& pattern, CString& directory, std::vector<CString>& output, CString& exclude);
    void FUN_14039deb0(const CString& pattern, const CString& directory, ATL::CAtlArray<CString>& output, const CString& exclude);
    void FUN_14039e460(const CString& pattern, const CString& directory, std::vector<CString>& output, const CString& exclude);
    CString FUN_14039ea10(const CString& filename, CString directory);
    bool FUN_14039f3b0(CString path);
    int FUN_14039f4b0(const char* path, void** data, unsigned __int64* size, bool warn);
    int FUN_14039faf0(std::string path);
    int FUN_1403a0320(const char* path, void** data, unsigned __int64* size, std::string* actualPath);
    void FUN_14039ee50();
    bool FUN_1403ab490(const std::string& path, const std::string& prefix);

    CLockCriticalSection cacheLock;
    Cache cache;
    bool packed;
    bool alternatePaths;
    unsigned mode;
    std::string workingDirectory;
    std::vector<Unk_FileArchive*> archives;
    std::vector<Unk_FileArchive*> patchArchives;
    std::vector<std::string> paths;
    CLockCriticalSection characterLock;
    unsigned characterMask;
    std::string effectDirectory;
    std::string mapDirectory;
    std::string modelDirectory;
    std::string stringDirectory;
    std::map<std::string, std::string> texturePaths[3];
    int archiveMode;
};
MS2_CHECK_SIZE(CFileSystem, 0x1c8);
MS2_CHECK_OFFSET(CFileSystem, cacheLock, 8);
MS2_CHECK_OFFSET(CFileSystem, cache, 0x38);
MS2_CHECK_OFFSET(CFileSystem, packed, 0x68);
MS2_CHECK_OFFSET(CFileSystem, mode, 0x6c);
MS2_CHECK_OFFSET(CFileSystem, workingDirectory, 0x70);
MS2_CHECK_OFFSET(CFileSystem, archives, 0x90);
MS2_CHECK_OFFSET(CFileSystem, patchArchives, 0xa8);
MS2_CHECK_OFFSET(CFileSystem, paths, 0xc0);
MS2_CHECK_OFFSET(CFileSystem, characterLock, 0xd8);
MS2_CHECK_OFFSET(CFileSystem, characterMask, 0x108);
MS2_CHECK_OFFSET(CFileSystem, effectDirectory, 0x110);
MS2_CHECK_OFFSET(CFileSystem, texturePaths, 0x190);
MS2_CHECK_OFFSET(CFileSystem, archiveMode, 0x1c0);
typedef unsigned long (CFileSystem::*Unk_FileTransformMethod)(unsigned long, unsigned char*, unsigned long,
                                                           unsigned char**, unsigned long);
typedef ClassFunHandler<Unk_FileTransform, CFileSystem*, Unk_FileTransformMethod> Unk_FileTransformHandler;
MS2_CHECK_SIZE(Unk_FileTransformHandler, 0x18);
CFileSystem* GetFileSystem();
void FUN_140399100(CString pattern, CString directory, ATL::CAtlArray<CString>& output, CString exclude, bool localOnly = false);
void FUN_1403992a0(CString pattern, CString directory, std::vector<CString>& output, CString exclude, bool localOnly = false);
void FUN_140399620(CString pattern, CString directory, ATL::CAtlArray<CString>& output, CString exclude, bool localOnly = false);
void FUN_140399c50(CString pattern, CString directory, ATL::CAtlArray<CString>& output, CString exclude);
void FUN_140399de0(CString pattern, CString directory, std::vector<CString>& output, CString exclude);
