// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CCacheData (path + last-write time of a loaded data file),
// the file-time map (path -> FILETIME) kept by the data-directory watcher, CDirWatcher (the "./data/" change-notification
// thread) and CThread's out-of-line members.
// MS2-UNIT: ?\cachedata.cpp
// MS2-RANGE: 0x1400b4660-0x1400b46f0 .text$di
// MS2-RANGE: 0x1401d1020-0x1401d4a00 .text$mn
// MS2-RANGE: 0x142c9a200-0x142c9a260 .text$yd
// MS2-PIN: ??_GCThread@@UEAAPEAXI@Z 0x1401d2dd0 ; manual: ICF look-alike of CPtred/CWin32Heap
// MS2-PIN: ?copy@?$char_traits@D@std@@SAPEADQEADQEBD_K@Z 0x1401d48c0 ; manual
// MS2-PIN: ?move@?$char_traits@D@std@@SAPEADQEADQEBD_K@Z 0x1401d49c0 ; manual
// MS2-PIN: ??_7CDirWatcher@@6B?$TSingleton@VCDirWatcher@@@@@ 0x142ceee80 ; manual
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_ECDirWatcher@@WBI@EAAPEAXI@Z 0x1401d2cbc ; unique
// MS2-PIN: ??_G?$TSingleton@VCDirWatcher@@@@UEAAPEAXI@Z 0x1401d2cd0 ; unique
// MS2-PIN: ??_GCCacheData@@UEAAPEAXI@Z 0x1401d2d10 ; prop
// MS2-PIN: ??_GCDirWatcher@@UEAAPEAXI@Z 0x1401d2d50 ; prop
// MS2-PIN: ?RemovePostOrder@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U_FILETIME@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@U_FILETIME@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x1401d3e50 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\cachedata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <string.h>
#pragma function(strlen)   // char_traits<char>::length (0x1401d4920) is a real strlen call
#include <atlcoll.h>
#pragma function(memcpy)   // char_traits<char>::copy (0x1401d48c0) is a real memcpy call
#include <string>
#pragma intrinsic(memcpy)
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cthread_startup.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class CDirWatcher;
class Unk_SingletonObj;
class Unk_SingletonObj1;
namespace Client { class Constants; }
template <> class TSingleton<Client::Constants> { public: static Client::Constants* s_instance; static Client::Constants* GetInstance(); };   // clientconstants.h's specialization (0x143aac5c8)
class Unk_MailService;

// Singleton base at +0x18 that stores the complete object (see logstring.h).
template<> class TSingleton<CDirWatcher> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static CDirWatcher* s_instance;
};

class CDirWatcher : public CThread, public TSingleton<CDirWatcher> {
public:
    CDirWatcher();                                          // 0x1401d1940
    // implicit dtor 0x1401d2980 (no vptr store in the exe)
    virtual unsigned int vfunc_1(void*, Unk_140659080&);    // 0x1401d19b0
    void Stop();                                   // close the directory handle and wait for the thread
    int FUN_1401d1d20() const;                             // the directory handle was closed
private:
    MS2_LAYOUT_FRIEND;
    HANDLE m_hDir;                                          // +0x20
};
MS2_CHECK_SIZE(CDirWatcher, 0x28);
MS2_CHECK_OFFSET(CDirWatcher, m_hDir, 0x20);

inline TSingleton<CDirWatcher>::TSingleton() { s_instance = static_cast<CDirWatcher*>(this); }

// The file-change listener held by value in the statics: TFunctor<void, ParamList<CString, ParamList<FILETIME>>>
// (ms2memfile.cpp builds it from a CFileSystem member; tfunctor2.h). Its out-of-line members here:
// ctor 0x1401d2530, dtor 0x1401d28a0, operator= 0x1401d2a40, IsNull 0x1401d2ff0, operator() 0x1401d2c50,
// Clone 0x1401d2210, Clear 0x1401d3eb0.
#include "ms2/placeholder/tfunctor2.h"
typedef TFunctor<void, ParamList<CString, ParamList<FILETIME, EmptyParam> > > Unk_FileChangeFunctor;
MS2_CHECK_SIZE(Unk_FileChangeFunctor, 8);
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

//
//
//
//
//
//
//
//

typedef ATL::CRBMap<CString, FILETIME> Unk_FileTimeMap;

// Array of cache entries (0x28 each) with the whole-array modified test.
class Unk_CacheDataArray {
public:
    Unk_CacheDataArray();                       // 0x1401d1d60
    void AddPath(CString strPath);              // 0x1401d1d90
    int IsAnyModified();                        // 0x1401d1e20
    void Clear();                               // 0x1401d1e90
private:
    ATL::CAtlArray<CCacheData> m_array;
};

extern bool DAT_143aac548;                      // watcher disabled
extern int DAT_1439f4840;                       // default code page (localepath.cpp)
class CommonResource;
CLogString* GetLogString();
unsigned long GetTickCountMs();   // C3: was FUN_1408693e0
Unk_SingletonObj* GetCommonResource();
#define GetClientConstants() (reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))   // C3: was Unk_SingletonObj1* FUN_1401d3200()
namespace Common { class Constants { public: void Reload(); }; }
class CLua   // C3: member view for the former free stand-ins
{
public:
    void Update();
};
class CommonResource   // C3: member view for the former free stand-ins
{
public:
    void CheckReload();
};
class Unk_BmPriceMgr* GetLuaClient();   // C3: was GetLuaClient
CString FUN_14016a600(const wchar_t* psz, int nCodePage);

template<class T, class U> inline void Unk_FileLog(CLogString* log, int level, int category, const wchar_t* format,
                                                 const T& first, const U& second) {
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(first),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

static Unk_FileChangeFunctor s_listener;         // 0x143aac5b0
CDirWatcher* TSingleton<CDirWatcher>::s_instance = 0;   // 0x143aac5b8
static Unk_FileTimeMap s_map(10);               // 0x143aac580
CLockCriticalSection g_cacheLock;               // 0x143aac550

CDirWatcher* GetDirWatcher();
CString FUN_1401d4330(const wchar_t* psz, int nCodePage = 0);
void ToLower(CString& str);
unsigned char FUN_1401d1730(CString strPath, FILETIME* pTime);

// @0x1401d1020
CCacheData::CCacheData()
{
}

// @0x1401d1070
CCacheData::CCacheData(CString strPath)
{
    SetPath(strPath);
}

// @0x1401d1100
CCacheData::~CCacheData()
{
}

// @0x1401d1140
CString* CCacheData::GetPath()
{
    return &m_strPath;
}

// @0x1401d1160
bool CCacheData::SetPath(CString strPath)
{
    FILETIME kTime;
    if (GetFileWriteTime(strPath, &kTime) == 0)
    {
        std::string kFound = GetFileSystem()->GetLocalePath(std::string(strPath));
        if (GetFileWriteTime(CString(kFound.c_str()), &kTime) == 0)
            return false;
        else
            strPath = kFound.c_str();
    }
    m_strPath = strPath;
    m_ftWrite = kTime;
    return true;
}

// @0x1401d1320
unsigned char FUN_1401d1320(CCacheData* pData)
{
    if (GetFileSystem()->FUN_140398190())
    {
        return 0;
    }
    else
    {
        if (pData->m_strPath.IsEmpty())
            return 0;
        FILETIME kNow;
        if (FUN_1401d1730(pData->m_strPath, &kNow) == 0)
            return 0;
        if (ATL::CFileTime(pData->m_ftWrite) != ATL::CFileTime(kNow))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void OnFileChanged(CString strPath);
#ifndef MS2_HOOK_DLL
// @0x1401d1400
void OnFileChanged(CString strPath)
{
    ToLower(strPath);
    if (strPath.Find("shaders") != -1)
        return;
    HANDLE hFile = INVALID_HANDLE_VALUE;
    DWORD dwError = 0;
    int nTry = 0;
    do
    {
        nTry = nTry + 1;
        Sleep(1);
        hFile = CreateFileA(strPath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            dwError = 0;
            break;
        }
        dwError = GetLastError();
        if (GetDirWatcher()->FUN_1401d1d20())
            return;
        if (nTry > 20)
            return;
        Unk_FileLog(GetLogString(), 12, 0x13, L"try = {0} file = {1}", nTry, (const char*)CString(strPath));
        Sleep(100);
    } while (dwError == ERROR_SHARING_VIOLATION);
    if (dwError != 0)
    {
        CloseHandle(hFile);
        return;
    }
    if (hFile == INVALID_HANDLE_VALUE)
        return;
    FILETIME kCreate, kAccess, kWrite;
    if (GetFileTime(hFile, &kCreate, &kAccess, &kWrite) == 0)
        return;
    CloseHandle(hFile);
    if (Unk_LockGuard kGuard = g_cacheLock)
    {
    }
    else
    {
        FILETIME kOld;
        if (!s_listener.IsNull() && s_map.Lookup(strPath, kOld) && memcmp(&kOld, &kWrite, 1) != 0)
            s_listener(strPath, kWrite);
        s_map.SetAt(strPath, kWrite);
    }
}
#endif

// @0x1401d1730
unsigned char FUN_1401d1730(CString strPath, FILETIME* pTime)
{
    ToLower(strPath);
    Unk_CriticalSectionLock kGuard(g_cacheLock, 1);
    return s_map.Lookup(strPath, *pTime);
}

// @0x1401d17b0
void SetFileChangeListener(Unk_FileChangeFunctor kListener)
{
    s_listener = kListener;
}

// @0x1401d17f0
int CCacheData::GetFileWriteTime(CString strPath, FILETIME* pTime)
{
    if (GetFileSystem()->FUN_140398190())
    {
        GetSystemTimeAsFileTime(pTime);
        return 1;
    }
    else
    {
        HANDLE hFile = CreateFileA(strPath, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
        if (hFile == INVALID_HANDLE_VALUE)
            return 0;
        FILETIME kCreate, kAccess;
        if (GetFileTime(hFile, &kCreate, &kAccess, pTime) == 0)
            return 0;
        CloseHandle(hFile);
        return 1;
    }
}

// @0x1401d1940
CDirWatcher::CDirWatcher()
    : m_hDir(INVALID_HANDLE_VALUE)
{
}

// @0x1401d19b0
unsigned int CDirWatcher::vfunc_1(void*, Unk_140659080& kStart)
{
    kStart.FUN_1401d42d0();
    srand(GetTickCountMs());
    CString strRoot("./data/");
    m_hDir = CreateFileA(strRoot, FILE_LIST_DIRECTORY, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING,
                         FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, 0);
    char acBuffer[0x10000] = {0};
    DWORD dwBytes = 0;
    for (;;)
    {
        if (ReadDirectoryChangesW(m_hDir, acBuffer, 0x10000, TRUE, 0x50, &dwBytes, 0, 0) != 0)
        {
            if (FUN_1401d1d20() != 0)
                break;
            if (DAT_143aac548 != 0)
                continue;
            FILE_NOTIFY_INFORMATION* pInfo = (FILE_NOTIFY_INFORMATION*)acBuffer;
            while (pInfo != 0)
            {
                if (FUN_1401d1d20() != 0)
                    break;
                wchar_t awcName[0x105] = {0};
                memcpy(awcName, pInfo->FileName,
                       (size_t)pInfo->FileNameLength > 0x208 ? (size_t)0x208 : (size_t)pInfo->FileNameLength);
                CString strName = FUN_1401d4330(awcName, 0);
                strName.Replace("\\", "/");
                strName = strRoot + strName;
                OnFileChanged(strName);
                if (pInfo->NextEntryOffset != 0)
                    pInfo = (FILE_NOTIFY_INFORMATION*)((char*)pInfo + pInfo->NextEntryOffset);
                else
                    pInfo = 0;
            }
            ((Common::Constants*)GetClientConstants())->Reload();
            ((class CLua*)(class Unk_MailService*)(((class Unk_MailService*)GetLuaClient())))->Update();
            ((class CommonResource*)(class Unk_SingletonObj*)(GetCommonResource()))->CheckReload();
        }
        else
        {
            break;
        }
    }
    return 0;
}

// @0x1401d1cd0
void CDirWatcher::Stop()
{
    if (m_hDir != 0)
    {
        CloseHandle(m_hDir);
        m_hDir = INVALID_HANDLE_VALUE;
        FUN_1401d3510(0xffffffff);
    }
}

// @0x1401d1d20
int CDirWatcher::FUN_1401d1d20() const
{
    return m_hDir == INVALID_HANDLE_VALUE;
}

// @0x1401d1d60
Unk_CacheDataArray::Unk_CacheDataArray() {}

// @0x1401d1d90
void Unk_CacheDataArray::AddPath(CString strPath)
{
    CCacheData kData;
    kData.SetPath(strPath);
    m_array.Add(kData);
}

// @0x1401d1e90
void Unk_CacheDataArray::Clear()
{
    m_array.RemoveAll();
}

// @0x1401d1e20
int Unk_CacheDataArray::IsAnyModified()
{
    for (unsigned int i = 0; i < m_array.GetCount(); i++)
    {
        if (FUN_1401d1320(&m_array.GetAt(i)))
            return 1;
    }
    return 0;
}

// @0x1401d2670
CCacheData::CCacheData(const CCacheData& kOther)
    : CPtred(kOther), m_ftWrite(kOther.m_ftWrite), m_strPath(kOther.m_strPath)
{
}

// @0x1401d27f0
CThread::CThread()
    : m_threadId(0), m_thread(0)
{
}

// @0x1401d29f0
CThread::~CThread()
{
    FUN_1401d2fa0();
}

inline void* ExchangeHandle(HANDLE* pHandle, void* pNew)
{
    return _InterlockedExchangePointer(pHandle, pNew);
}

// @0x1401d2fa0
void CThread::FUN_1401d2fa0()
{
    m_threadId = 0;
    HANDLE hThread = (HANDLE)ExchangeHandle(&m_thread, 0);
    if (hThread != 0)
        CloseHandle(hThread);
}

// @0x1401d31e0
CDirWatcher* GetDirWatcher()
{
    return TSingleton<CDirWatcher>::s_instance;
}

// @0x1401d31f0
Unk_SingletonObj* GetCommonResource()
{
    return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CommonResource>::s_instance);
}

// @0x1401d3200
Client::Constants* TSingleton<Client::Constants>::GetInstance()   // C3: was Unk_SingletonObj1* FUN_1401d3200()
{
    return TSingleton<Client::Constants>::s_instance;
}

// @0x1401d3510
int CThread::FUN_1401d3510(DWORD dwTimeout)
{
    if (m_thread == 0)
        return 1;
    else if (m_threadId == GetCurrentThreadId())
        return 0;
    DWORD dwResult = WaitForSingleObject(m_thread, dwTimeout);
    if (dwResult != 0)
        MessageBeep(0x20);
    return dwResult == 0;
}

// @0x1401d3720
// The exe catches CException* (MakeLower throws CMemoryException*); the named catch object is the frame's extra slot.
inline bool FUN_1401d3720(CString& str)
{
    try
    {
        str.MakeLower();
    }
    catch (CException* e)
    {
        (void)e;
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\stringutil.h", 0x193), 0));
        return false;
    }
    return true;
}

// @0x1401d3700
void ToLower(CString& str)
{
    FUN_1401d3720(str);
}

// @0x1401d4030
unsigned int CThread::vfunc_1(void*, Unk_140659080& kStart)
{
    kStart.FUN_1401d42d0();
    return 0;
}

// @0x1401d42d0
void Unk_140659080::FUN_1401d42d0()
{
    Unk_140659080* pState = this;
    HANDLE hResume = pState->resume;
    pState->error = 0;
    SetEvent(pState->ready);
    WaitForSingleObject(hResume, INFINITE);
    CloseHandle(hResume);
}

// @0x1401d4330
CString FUN_1401d4330(const wchar_t* psz, int nCodePage)
{
    int nUse = nCodePage == 0 ? DAT_1439f4840 : nCodePage;
    return FUN_14016a600(psz, nUse);
}
