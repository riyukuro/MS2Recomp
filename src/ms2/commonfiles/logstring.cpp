// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Asynchronous log writer.
// MS2-UNIT: commonfiles\logstring.cpp
// MS2-PIN: ??_7CLogString@@6B?$TSingleton@VCLogString@@@@@ 0x142d6f500
// MS2-PIN: ??$format_arg@_WW4Unk_LogCategory@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_LogCategory@@@Z 0x140657f80
// MS2-PIN: ??$make_type@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@internal@fmt@@YA_KAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x140658100
// MS2-PIN: ??$make_type@W4Unk_LogCategory@@@internal@fmt@@YA_KAEBW4Unk_LogCategory@@@Z 0x140658140
// MS2-PIN: ??$make_type@_W@internal@fmt@@YA_KAEB_W@Z 0x140658160
// MS2-PIN: ??0?$Unk_1406583d0@VCLogStringCtx@@@@QEAA@AEBV0@@Z 0x140658420
// MS2-PIN: ??0?$Unk_1406583d0@VCLogStringCtx@@@@QEAA@PEAVCLogStringCtx@@@Z 0x140658460
// MS2-PIN: ??1?$Unk_1406583d0@VCLogStringCtx@@@@QEAA@XZ 0x1406588a0
// MS2-PIN: ??4?$Delegate@$$A6AXPEAVCLogStringCtx@@@Z@@QEAAAEAV0@AEBV0@@Z 0x1406589e0
// MS2-PIN: ??8?$Unk_1406583d0@VCLogCustomGroup@@@@QEBA_NPEAVCLogCustomGroup@@@Z 0x140658b60
// MS2-PIN: ?get@?$Unk_1406583d0@VCLogCustomGroup@@@@QEBAPEAVCLogCustomGroup@@XZ 0x140658c90
// MS2-PIN: ?get@?$Unk_1406583d0@VCLogStringCtx@@@@QEBAPEAVCLogStringCtx@@XZ 0x140658ca0
// MS2-PIN: ?Fail@Unk_140659080@@QEAAHH@Z 0x140659080
// MS2-PIN: ?type@?$MakeValue@V?$BasicFormatter@D@fmt@@@internal@fmt@@SA_K_W@Z 0x14065b030
// MS2-RANGE: 0x1406525e0-0x14065b160 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\logstring.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <io.h>

CLogString* TSingleton<CLogString>::s_instance=0;
extern bool g_logLoadingError;
class Unk_140659080 {
public:
    void FUN_1401d42d0();
    int Fail(int result) {
        Unk_140659080* state=this;
        CloseHandle(state->m_wait);
        state->m_result=result==0 ? E_FAIL : result;
        SetEvent(state->m_ready);
        return result;
    }
private:
    void* m_00; void* m_08; void* m_10;
    HANDLE m_ready,m_wait;
    int m_result;
};
MS2_CHECK_SIZE(Unk_140659080,0x30);
class Unk_140165cf0;
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
CStringW FUN_1401bf530(Unk_140165cf0*,const char*,CStringW);
CString FUN_1406513d0(CString);
CStringW FUN_14016a730(const char*,int);
bool FUN_14025fab0(CStringW&);


// The logging callback specialization uses the shared Delegate layout and virtual interface.
template<> inline Delegate<void(CLogStringCtx*)>::Delegate(const Delegate& o) {
    if(o.m_pImpl==0) m_pImpl=0;
    else m_pImpl=o.m_pImpl->vfunc_1();
}
template<> inline Delegate<void(CLogStringCtx*)>::~Delegate() { if(m_pImpl) delete m_pImpl; }
template<> inline Delegate<void(CLogStringCtx*)>& Delegate<void(CLogStringCtx*)>::operator=(const Delegate& o) {
    if(this==&o) return *this;
    if(m_pImpl) delete m_pImpl;
    if(o.m_pImpl==0) m_pImpl=0;
    else m_pImpl=o.m_pImpl->vfunc_1();
    return *this;
}
template<> inline bool Delegate<void(CLogStringCtx*)>::operator==(const Delegate& o) const {
    if(m_pImpl==0 && o.m_pImpl==0) return true;
    if(m_pImpl==0 || o.m_pImpl==0) return false;
    return m_pImpl->vfunc_3(o.m_pImpl);
}
inline void Unk_140657820() {}
template<> inline void Delegate<void(CLogStringCtx*)>::operator()(CLogStringCtx* context) const {
    if(m_pImpl==0) Unk_140657820();
    m_pImpl->vfunc_2(context);
}

// @0x1406525e0
CLogCustomGroup::CLogCustomGroup(CString name) : m_name(name),m_file(0),m_queue(10) {}
// @0x140652670
CLogCustomGroup::~CLogCustomGroup() { if(m_file) { CloseHandle(m_file); m_file=0; } }
// @0x1406526f0
CLogString::CLogString() : m_queue(10),m_file(0),m_name(L"unknown"),m_day(0),m_instance(0),m_loadingError(0),m_fileLevel(0),m_debugLevel(0),m_errors(0),m_warnings(0),m_groups(10) {}
// @0x1406528a0
CLogString::~CLogString()
{
    for(unsigned i=0;i<m_Handles.GetCount();++i) if(m_Handles[i]) CloseHandle(m_Handles[i]);
    CloseFiles();
}
// @0x140652a40
void CLogString::Init(CStringW name)
{
    m_name=name;
    if(!ReadLogPathFromSettings() && !CreateDefaultLogPath()) { MessageBoxW(0,L"Failed to Create Log Path",L"LogString Error",0); return; }
    m_directory=StringFormat(L"{0}\\{1}\\",m_root,m_name);
    CreateDirectoryW(m_directory,0);
    HANDLE stop=CreateEventA(0,TRUE,FALSE,0);
    if(stop) m_Handles.Add(stop);
    HANDLE work=CreateEventA(0,FALSE,FALSE,0);
    if(work) m_Handles.Add(work);
}
MS2_REPLACE_METHOD(0x140652a40, CLogString, Init, 375, 0x7FE400C1);

// @0x140652bc0
void CLogString::StopThread()
{
    MS2_ASSERT_AT(73,m_Handles.GetCount() > 0);
    SetEvent(m_Handles[0]); FUN_1401d3510(INFINITE);
}
MS2_REPLACE_METHOD(0x140652bc0, CLogString, StopThread, 107, 0xE95D6CD3);

// @0x140652c40
void CLogString::SignalWork()
{
    MS2_ASSERT_AT(80,m_Handles.GetCount() > 1);
    SetEvent(m_Handles[1]);
}
MS2_REPLACE_METHOD(0x140652c40, CLogString, SignalWork, 96, 0xE55A0BF7);

// @0x140652cd0
unsigned int CLogString::vfunc_1(void*,Unk_140659080& start)
{
    if(m_Handles[0]==0) { start.Fail(E_FAIL); return -1; }
    start.FUN_1401d42d0();
    DWORD count=(DWORD)m_Handles.GetCount();
    for(;;) {
        DWORD result=WaitForMultipleObjects(count,&m_Handles[0],FALSE,INFINITE); result-=WAIT_OBJECT_0;
        SYSTEMTIME time; GetLocalTime(&time);
        if(m_day!=time.wDay) { m_day=time.wDay; CloseFiles(); }
        OpenLogFile(); OpenGroupFiles();
        if(!m_queue.IsEmpty()) {
            while(!m_queue.IsEmpty()) {
                CStringW line;
                {
                    Unk_LockGuard guard(m_queueLock);
                    if(guard!=0) {} else {
                        if(m_queue.IsEmpty()) break;
                        line=m_queue.RemoveHead();
                    }
                }
                DWORD written=0;
                WriteFile(m_file,(const wchar_t*)line,line.GetLength()*sizeof(wchar_t),&written,0);
            }
            FlushFileBuffers(m_file);
        }
        FUN_140654f70();
        if(result==WAIT_OBJECT_0) break;
    }
    {
        Unk_LockGuard guard(m_queueLock);
        if(guard!=0) {} else {
            if(!m_queue.IsEmpty()) {
                while(!m_queue.IsEmpty()) {
                    CStringW line=m_queue.RemoveHead(); DWORD written=0;
                    WriteFile(m_file,(const wchar_t*)line,line.GetLength()*sizeof(wchar_t),&written,0);
                }
                FlushFileBuffers(m_file);
            }
        }
    }
    FUN_140654f70(); return 0;
}
MS2_REPLACE_METHOD(0x140652cd0, CLogString, vfunc_1, 1017, 0xB76246D7);

// No hooks on this forwarding family: the core constructs DLL-local CLogStringCtx RTTI.
// @0x1406530d0
void CLogString::FUN_1406530d0(int level,int category,const wchar_t* format,const fmt::ArgList& args) { Log(0,0,level,category,format,args); }
// @0x140653130
void CLogString::Log(unsigned __int64 account,unsigned __int64 character,int level,int category,const wchar_t* format,const fmt::ArgList& args)
{
    if(!m_callbacks.empty()) {
        ContextPtr context(new CLogStringCtx);
        context->m_level=level; context->m_category=category;
        context->m_account=account; context->m_character=character;
        context->m_text=StringFormat(format,args);
        InvokeCallbacks(context);
    }
    if(m_fileLevel<level) return;
    CStringW text=StringFormat(format,args);
    EnqueueLine(FormatLogLine(account,character,level,category,text));
    FUN_140653de0(account,character,level,category,text);
    if(m_debugLevel>=level) OutputDebugStringW(FormatTimestampedLine(text));
    CountLevel(level);
}
// No hook: custom logging can construct DLL-local CLogCustomGroup RTTI.
// @0x140653440
void CLogString::LogToGroup(const CString& group,const wchar_t* format,const fmt::ArgList& args)
{
    SYSTEMTIME time; GetLocalTime(&time);
    CStringW line; line.Format(L"[%02d:%02d:%02d]",time.wHour,time.wMinute,time.wSecond);
    line.Append(StringFormat(format,args)); line.Append(L"\r\n");
    EnqueueGroupLine(group,line);
}
// @0x140653550
void CLogString::LogDebug(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* format,const fmt::ArgList& args) { Log(a,c,12,category,format,args); }
// @0x1406535b0
void CLogString::FUN_1406535b0(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* format,const fmt::ArgList& args)
{
    Log(a,c,1,category,format,args);
    if(m_loadingError && g_logLoadingError) if(FUN_140654910()) {
        MessageBoxW(0,StringFormat(format,args),L"Loading Error",0); g_logLoadingError=false;
    }
}
// @0x140653690
void CLogString::LogInfo(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* format,const fmt::ArgList& args) { Log(a,c,11,category,format,args); }
// @0x1406536f0
void CLogString::LogWarning(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* format,const fmt::ArgList& args) { Log(a,c,2,category,format,args); }
// @0x140653750
void CLogString::LogForced(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* format,const fmt::ArgList& args) { QueueTaggedLine(a,c,category,StringFormat(format,args)); }
MS2_REPLACE_METHOD(0x140653750, CLogString, LogForced, 126, 0x812C0F0B);

// @0x1406537e0
void CLogString::SetFileLevel(int level) { m_fileLevel=level; }
MS2_REPLACE_METHOD(0x1406537e0, CLogString, SetFileLevel, 25, 0x0E391D3B);

// @0x140653800
void CLogString::SetDebugLevel(int level) { m_debugLevel=level; }
MS2_REPLACE_METHOD(0x140653800, CLogString, SetDebugLevel, 25, 0x09284B7F);

// @0x140653820
int CLogString::GetErrors() { return m_errors; }
MS2_REPLACE_METHOD(0x140653820, CLogString, GetErrors, 17, 0x38E3250F);

// @0x140653840
int CLogString::GetWarnings() { return m_warnings; }
MS2_REPLACE_METHOD(0x140653840, CLogString, GetWarnings, 17, 0xD382A09B);

// @0x140653860
int CLogString::GetFileLevel() { return m_fileLevel; }
MS2_REPLACE_METHOD(0x140653860, CLogString, GetFileLevel, 17, 0x03AA79F7);

// @0x140653880
CStringW CLogString::BuildLogFileName(int fullPath)
{
    wchar_t module[MAX_PATH],drive[_MAX_DRIVE],directory[_MAX_DIR],file[_MAX_FNAME],computer[MAX_COMPUTERNAME_LENGTH+1];
    GetModuleFileNameW(0,module,MAX_PATH); _wsplitpath(module,drive,directory,file,0);
    DWORD length=MAX_COMPUTERNAME_LENGTH+1; GetComputerNameW(computer,&length);
    SYSTEMTIME time; GetLocalTime(&time);
    CStringW name;
    if(m_instance) name=StringFormat(L"{0}_{1}_{2}_{3:04d}{4:02d}{5:02d}.txt",file,m_instance,computer,time.wYear,time.wMonth,time.wDay);
    else name=StringFormat(L"{0}_{1}_{2:04d}{3:02d}{4:02d}.txt",file,computer,time.wYear,time.wMonth,time.wDay);
    if(fullPath) name=StringFormat(L"{0}{1}",m_directory,name);
    FUN_14025fab0(name); m_day=time.wDay; return name;
}
MS2_REPLACE_METHOD(0x140653880, CLogString, BuildLogFileName, 672, 0x448DA939);

// @0x140653b30
CStringW CLogString::GetRoot() { return m_root; }
MS2_REPLACE_METHOD(0x140653b30, CLogString, GetRoot, 68, 0x44C95B86);

// @0x140653b80
void CLogString::AddCallback(Callback callback) { Unk_CriticalSectionLock guard(m_callbackLock,1); m_callbacks.push_back(callback); }
MS2_REPLACE_METHOD(0x140653b80, CLogString, AddCallback, 105, 0x1E498D94);

// @0x140653bf0
void CLogString::RemoveCallback(Callback callback)
{
    Unk_CriticalSectionLock guard(m_callbackLock,1);
    for(unsigned i=0;i<m_callbacks.size();++i) if(m_callbacks[i]==callback) { m_callbacks.erase(m_callbacks.begin()+i); return; }
}
MS2_REPLACE_METHOD(0x140653bf0, CLogString, RemoveCallback, 325, 0xEDF114DF);

// @0x140653d40
void CLogString::EnqueueLine(const CStringW& text)
{
    CStringW line=FormatTimestampedLine(text); Unk_LockGuard guard(m_queueLock);
    if(guard!=0) {} else { m_queue.AddTail(line); SignalWork(); }
}
MS2_REPLACE_METHOD(0x140653d40, CLogString, EnqueueLine, 143, 0xD9B70076);

// @0x140653de0
void CLogString::FUN_140653de0(unsigned __int64,unsigned __int64,int,int,const CStringW&) {}
MS2_REPLACE_METHOD(0x140653de0, CLogString, FUN_140653de0, 21, 0x088A195E);

// @0x140653e00
void CLogString::CountLevel(int level)
{
    switch(level) {
    case 1: ++m_errors; break;
    case 2: ++m_warnings; break;
    }
}
MS2_REPLACE_METHOD(0x140653e00, CLogString, CountLevel, 89, 0x4E51C3B9);

// @0x140653e60
bool CLogString::ReadLogPathFromSettings()
{
    TiXmlDocument doc;
    bool bFailed=!doc.FUN_140870fc0(ATL::CA2AEX<128>(FUN_1406513d0("setting.xml")),0) ? TRUE : FALSE;
    if(bFailed && !doc.FUN_140870fc0("setting.xml",0)) return false;
    Unk_140165cf0* root=((class Unk_140165cf0*)reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
    if(!root) return false;
    Unk_140165cf0* node=((class Unk_140165cf0*)((class Unk_XmlNode*)(root))->FirstChild("logpath"));
    if(!node) return false;
    CStringW path=FUN_1401bf530(node,"logpath",L"");
    if(path.IsEmpty()) return false;
    m_root=path;
    if(!CreateDirectoryW(m_root,0)) { DWORD error=GetLastError(); if(error!=ERROR_ALREADY_EXISTS) return false; }
    return true;
}
MS2_REPLACE_METHOD(0x140653e60, CLogString, ReadLogPathFromSettings, 760, 0xA20C55A1);

// @0x140654160
bool CLogString::CreateDefaultLogPath()
{
    wchar_t module[MAX_PATH],drive[_MAX_DRIVE],directory[_MAX_DIR];
    GetModuleFileNameW(0,module,MAX_PATH); _wsplitpath(module,drive,directory,0,0);
    m_root=StringFormat(L"{0}{1}Log",drive,directory);
    if(!CreateDirectoryW(m_root,0)) { DWORD error=GetLastError(); if(error!=ERROR_ALREADY_EXISTS) return false; }
    return true;
}
MS2_REPLACE_METHOD(0x140654160, CLogString, CreateDefaultLogPath, 267, 0xC1B3B87D);

// @0x140654280
void CLogString::OpenLogFile()
{
    if(m_file) return;
    {
        CStringW path=StringFormat(L"{0}\\{1}",m_directory,BuildLogFileName(0));
        bool bExists=_waccess(path,0)==0 ? true : false;
        m_file=CreateFileW(path,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,0,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
        if(!bExists) { DWORD written=0; wchar_t bom=0xfeff; WriteFile(m_file,&bom,2,&written,0); }
        LARGE_INTEGER offset; offset.QuadPart=0; SetFilePointerEx(m_file,offset,0,FILE_END);
    }
}
MS2_REPLACE_METHOD(0x140654280, CLogString, OpenLogFile, 388, 0xBB875AD9);

// @0x140654410
void CLogString::OpenGroupFiles()
{
    Unk_CriticalSectionLock guard(m_groupLock,1);
    for(POSITION pos=m_groups.GetHeadPosition();pos;m_groups.GetNext(pos)) {
        GroupPtr group=m_groups.GetValueAt(pos);
        if(!group->m_file) OpenGroupFile(group);
    }
}
MS2_REPLACE_METHOD(0x140654410, CLogString, OpenGroupFiles, 253, 0xF740BBC3);

// @0x140654520
void CLogString::OpenGroupFile(GroupPtr group)
{
    if(group==NULL) return;
    if(group->m_file) { FlushFileBuffers(group->m_file); CloseHandle(group->m_file); }
    CStringW path=StringFormat(L"{0}\\{1}_{2}",m_directory,FUN_14016a730(group->m_name,0),BuildLogFileName(0));
    bool bExists=_waccess(path,0)==0 ? true : false;
    group->m_file=CreateFileW(path,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,0,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
    if(!bExists) { DWORD written=0; wchar_t bom=0xfeff; WriteFile(group->m_file,&bom,2,&written,0); }
    LARGE_INTEGER offset; offset.QuadPart=0; SetFilePointerEx(group->m_file,offset,0,FILE_END);
}
MS2_REPLACE_METHOD(0x140654520, CLogString, OpenGroupFile, 607, 0xD962302B);

// @0x140654790
void CLogString::CloseFiles()
{
    if(m_file) { FlushFileBuffers(m_file); CloseHandle(m_file); m_file=0; }
    Unk_LockGuard guard(m_groupLock);
    if(guard!=0) {} else {
        for(POSITION pos=m_groups.GetHeadPosition();pos;m_groups.GetNext(pos)) {
            GroupPtr group=m_groups.GetValueAt(pos);
            if((group.get() ? true : false) && group->m_file) { FlushFileBuffers(group->m_file); CloseHandle(group->m_file); group->m_file=0; }
        }
    }
}
MS2_REPLACE_METHOD(0x140654790, CLogString, CloseFiles, 370, 0x57C96FE3);

// @0x140654910
bool CLogString::FUN_140654910() { return true; }
MS2_REPLACE_METHOD(0x140654910, CLogString, FUN_140654910, 8, 0x71679366);

// @0x140654920
void CLogString::QueueTaggedLine(unsigned __int64 account,unsigned __int64 character,unsigned category,const CStringW& text)
{
    CStringW line;
    line.Format(L"[F][LT%02u]",category);
    if (!(account==0 && character==0))
    {
        line.AppendFormat(L"[ac=%I64u][ch=%I64u]",account,character);
        line.Append(text);
    }
    else
        line.Append(text);
    EnqueueLine(line);
}
MS2_REPLACE_METHOD(0x140654920, CLogString, QueueTaggedLine, 178, 0x52509381);

// No hook: creates a custom group on first use (DLL-local RTTI).
// @0x1406549e0
void CLogString::EnqueueGroupLine(const CString& name,const CStringW& text)
{
    Unk_CriticalSectionLock guard(m_groupLock,1);
    GroupPtr group;
    if(!m_groups.Lookup(name,group)) group=CreateGroup(name);
    group->m_queue.AddTail(text); SignalWork();
}
// @0x140654b10
wchar_t CLogString::GetLevelChar(int level)
{
    switch(level) {
    case 1: return L'E';
    case 2: return L'W';
    case 11: return L'I';
    case 12: return L'D';
    }
    return L'U';
}
MS2_REPLACE_METHOD(0x140654b10, CLogString, GetLevelChar, 84, 0xACA69F93);

// @0x140654b70
CStringW CLogString::FormatLogLine(unsigned __int64 account,unsigned __int64 character,int level,int category,const CStringW& text)
{
    if(account!=0 || character!=0) return StringFormat(L"[{0}][LT{1:02}][ac={2}][ch={3}]{4}",GetLevelChar(level),reinterpret_cast<const Unk_LogCategory&>(category),account,character,text);
    return StringFormat(L"[{0}][LT{1:02}]{2}",GetLevelChar(level),reinterpret_cast<const Unk_LogCategory&>(category),text);
}
MS2_REPLACE_METHOD(0x140654b70, CLogString, FormatLogLine, 237, 0xA8607059);

// @0x140654c70
CStringW CLogString::FormatTimestampedLine(const CStringW& text)
{
    SYSTEMTIME time; GetLocalTime(&time);
    return StringFormat(L"[{0:02}:{1:02}:{2:02}]{3}\r\n",time.wHour,time.wMinute,time.wSecond,text);
}
MS2_REPLACE_METHOD(0x140654c70, CLogString, FormatTimestampedLine, 134, 0x2C74BB4C);

// @0x140654d00
void CLogString::InvokeCallbacks(ContextPtr context)
{
    std::vector<Callback> callbacks;
    { Unk_LockGuard guard(m_callbackLock); if(guard!=0) {} else callbacks=m_callbacks; }
    for(unsigned i=0;i<callbacks.size();++i) callbacks[i](context.get());
}
MS2_REPLACE_METHOD(0x140654d00, CLogString, InvokeCallbacks, 234, 0x5F59D737);

// No hook: constructs DLL-local CLogCustomGroup RTTI.
// @0x140654df0
CLogString::GroupPtr CLogString::CreateGroup(CString name)
{
    Unk_CriticalSectionLock guard(m_groupLock,1);
    GroupPtr group(new CLogCustomGroup(name));
    OpenGroupFile(group); m_groups.SetAt(name,group); return group;
}
// @0x140654f70
void CLogString::FUN_140654f70()
{
    Unk_CriticalSectionLock guard(m_groupLock,1);
    for(POSITION pos=m_groups.GetHeadPosition();pos;m_groups.GetNext(pos)) {
        GroupPtr group=m_groups.GetValueAt(pos);
        if((group.get() ? true : false) && group->m_file) {
            if(!group->m_queue.IsEmpty()) {
                while(!group->m_queue.IsEmpty()) {
                    CStringW line=group->m_queue.RemoveHead(); DWORD written=0;
                    WriteFile(group->m_file,(const wchar_t*)line,line.GetLength()*sizeof(wchar_t),&written,0);
                }
                FlushFileBuffers(group->m_file);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140654f70, CLogString, FUN_140654f70, 485, 0x80970B99);

MS2_EMIT_CRT_MEMMOVE_S();
