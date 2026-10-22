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
class Unk_140163940 {
public:
    Unk_140163940(CLockCriticalSection&);
    ~Unk_140163940();
    operator int() const;
private: void* m_lock;
};
class Unk_1401b4ec0 {
public:
    Unk_1401b4ec0(CLockCriticalSection&,int);
    ~Unk_1401b4ec0();
private: void* m_lock;
};
MS2_CHECK_SIZE(Unk_140163940,8);
MS2_CHECK_SIZE(Unk_1401b4ec0,8);
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
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
CStringW FUN_1401bf530(Unk_140165cf0*,const char*,CStringW);
CString FUN_1406513d0(CString);
CStringW FUN_14016a730(const char*,int);
void FUN_14025fab0(CStringW&);


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
    FUN_140654790();
}
// @0x140652a40
void CLogString::FUN_140652a40(CStringW name)
{
    m_name=name;
    if(!FUN_140653e60() && !FUN_140654160()) { MessageBoxW(0,L"Failed to Create Log Path",L"LogString Error",0); return; }
    m_directory=StringFormat(L"{0}\\{1}\\",m_root,m_name);
    CreateDirectoryW(m_directory,0);
    HANDLE stop=CreateEventA(0,TRUE,FALSE,0);
    if(stop) m_Handles.Add(stop);
    HANDLE work=CreateEventA(0,FALSE,FALSE,0);
    if(work) m_Handles.Add(work);
}
MS2_REPLACE_METHOD(0x140652a40, CLogString, FUN_140652a40, 375, 0x7FE400C1);

// @0x140652bc0
void CLogString::FUN_140652bc0()
{
    MS2_ASSERT_AT(73,m_Handles.GetCount() > 0);
    SetEvent(m_Handles[0]); FUN_1401d3510(INFINITE);
}
MS2_REPLACE_METHOD(0x140652bc0, CLogString, FUN_140652bc0, 107, 0xE95D6CD3);

// @0x140652c40
void CLogString::FUN_140652c40()
{
    MS2_ASSERT_AT(80,m_Handles.GetCount() > 1);
    SetEvent(m_Handles[1]);
}
MS2_REPLACE_METHOD(0x140652c40, CLogString, FUN_140652c40, 96, 0xE55A0BF7);

// MS2-FUNCTIONAL: Equivalent queue-drain loop; local lifetimes and byte-count temporaries differ.
// @0x140652cd0
unsigned int CLogString::vfunc_1(void*,Unk_140659080& start)
{
    if(m_Handles[0]==0) { start.Fail(E_FAIL); return -1; }
    start.FUN_1401d42d0();
    DWORD count=(DWORD)m_Handles.GetCount();
    DWORD result;
    do {
        result=WaitForMultipleObjects(count,&m_Handles[0],FALSE,INFINITE);
        SYSTEMTIME time; GetLocalTime(&time);
        if(m_day!=time.wDay) { m_day=time.wDay; FUN_140654790(); }
        FUN_140654280(); FUN_140654410();
        if(!m_queue.IsEmpty()) {
            while(!m_queue.IsEmpty()) {
                CStringW line;
                {
                    Unk_140163940 guard(m_queueLock);
                    if(guard==0) {
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
    } while(result!=WAIT_OBJECT_0);
    {
        Unk_140163940 guard(m_queueLock);
        if(guard==0 && !m_queue.IsEmpty()) {
            while(!m_queue.IsEmpty()) {
                CStringW line=m_queue.RemoveHead(); DWORD written=0;
                WriteFile(m_file,(const wchar_t*)line,line.GetLength()*sizeof(wchar_t),&written,0);
            }
            FlushFileBuffers(m_file);
        }
    }
    FUN_140654f70(); return 0;
}
MS2_REPLACE_METHOD(0x140652cd0, CLogString, vfunc_1, 1017, 0xB76246D7);

// No hooks on this forwarding family: the core constructs DLL-local CLogStringCtx RTTI.
// @0x1406530d0
void CLogString::FUN_1406530d0(int level,int category,const wchar_t* format,const fmt::ArgList& args) { FUN_140653130(0,0,level,category,format,args); }
// MS2-FUNCTIONAL: Equivalent callback creation and log routing; temporary placement differs.
// @0x140653130
void CLogString::FUN_140653130(unsigned __int64 account,unsigned __int64 character,int level,int category,const wchar_t* format,const fmt::ArgList& args)
{
    if(!m_callbacks.empty()) {
        ContextPtr context(new CLogStringCtx);
        context->m_level=level; context->m_category=category;
        context->m_account=account; context->m_character=character;
        context->m_text=StringFormat(format,args);
        FUN_140654d00(context);
    }
    if(level<=m_fileLevel) {
        CStringW text=StringFormat(format,args);
        FUN_140653d40(FUN_140654b70(account,character,level,category,text));
        FUN_140653de0(account,character,level,category,text);
        if(level<=m_debugLevel) OutputDebugStringW(FUN_140654c70(text));
        FUN_140653e00(level);
    }
}
// No hook: custom logging can construct DLL-local CLogCustomGroup RTTI.
// @0x140653440
void CLogString::FUN_140653440(const CString& group,const wchar_t* format,const fmt::ArgList& args)
{
    SYSTEMTIME time; GetLocalTime(&time);
    CStringW line; line.Format(L"[%02d:%02d:%02d]",time.wHour,time.wMinute,time.wSecond);
    line.Append(StringFormat(format,args)); line.Append(L"\r\n");
    FUN_1406549e0(group,line);
}
// @0x140653550
void CLogString::FUN_140653550(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* format,const fmt::ArgList& args) { FUN_140653130(a,c,12,category,format,args); }
// @0x1406535b0
void CLogString::FUN_1406535b0(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* format,const fmt::ArgList& args)
{
    FUN_140653130(a,c,1,category,format,args);
    if(m_loadingError && g_logLoadingError) if(FUN_140654910()) {
        MessageBoxW(0,StringFormat(format,args),L"Loading Error",0); g_logLoadingError=false;
    }
}
// @0x140653690
void CLogString::FUN_140653690(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* format,const fmt::ArgList& args) { FUN_140653130(a,c,11,category,format,args); }
// @0x1406536f0
void CLogString::FUN_1406536f0(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* format,const fmt::ArgList& args) { FUN_140653130(a,c,2,category,format,args); }
// @0x140653750
void CLogString::FUN_140653750(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* format,const fmt::ArgList& args) { FUN_140654920(a,c,category,StringFormat(format,args)); }
MS2_REPLACE_METHOD(0x140653750, CLogString, FUN_140653750, 126, 0x812C0F0B);

// @0x1406537e0
void CLogString::FUN_1406537e0(int level) { m_fileLevel=level; }
MS2_REPLACE_METHOD(0x1406537e0, CLogString, FUN_1406537e0, 25, 0x0E391D3B);

// @0x140653800
void CLogString::FUN_140653800(int level) { m_debugLevel=level; }
MS2_REPLACE_METHOD(0x140653800, CLogString, FUN_140653800, 25, 0x09284B7F);

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
CStringW CLogString::FUN_140653880(int fullPath)
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
MS2_REPLACE_METHOD(0x140653880, CLogString, FUN_140653880, 672, 0x448DA939);

// @0x140653b30
CStringW CLogString::GetRoot() { return m_root; }
MS2_REPLACE_METHOD(0x140653b30, CLogString, GetRoot, 68, 0x44C95B86);

// @0x140653b80
void CLogString::FUN_140653b80(Callback callback) { Unk_1401b4ec0 guard(m_callbackLock,1); m_callbacks.push_back(callback); }
MS2_REPLACE_METHOD(0x140653b80, CLogString, FUN_140653b80, 105, 0x1E498D94);

// @0x140653bf0
void CLogString::FUN_140653bf0(Callback callback)
{
    Unk_1401b4ec0 guard(m_callbackLock,1);
    for(unsigned i=0;i<m_callbacks.size();++i) if(m_callbacks[i]==callback) { m_callbacks.erase(m_callbacks.begin()+i); return; }
}
MS2_REPLACE_METHOD(0x140653bf0, CLogString, FUN_140653bf0, 325, 0xEDF114DF);

// MS2-FUNCTIONAL: Equivalent guarded queue insertion; condition lifetime differs.
// @0x140653d40
void CLogString::FUN_140653d40(const CStringW& text)
{
    CStringW line=FUN_140654c70(text); Unk_140163940 guard(m_queueLock);
    if(guard==0) { m_queue.AddTail(line); FUN_140652c40(); }
}
MS2_REPLACE_METHOD(0x140653d40, CLogString, FUN_140653d40, 143, 0xD9B70076);

// @0x140653de0
void CLogString::FUN_140653de0(unsigned __int64,unsigned __int64,int,int,const CStringW&) {}
MS2_REPLACE_METHOD(0x140653de0, CLogString, FUN_140653de0, 21, 0x088A195E);

// MS2-FUNCTIONAL: Equivalent severity counters expressed with conditional branches.
// @0x140653e00
void CLogString::FUN_140653e00(int level) { if(level==1) ++m_errors; else if(level==2) ++m_warnings; }
MS2_REPLACE_METHOD(0x140653e00, CLogString, FUN_140653e00, 89, 0x4E51C3B9);

// MS2-FUNCTIONAL: Equivalent settings lookup and directory creation with earlier failure returns.
// @0x140653e60
bool CLogString::FUN_140653e60()
{
    TiXmlDocument doc;
    if(!doc.FUN_140870fc0(ATL::CA2AEX<128>(FUN_1406513d0("setting.xml")),0) && !doc.FUN_140870fc0("setting.xml",0)) return false;
    Unk_140165cf0* root=reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if(!root) return false;
    Unk_140165cf0* node=root->FUN_140165cf0("logpath");
    if(!node) return false;
    CStringW path=FUN_1401bf530(node,"logpath",L"");
    if(path.IsEmpty()) return false;
    m_root=path;
    if(!CreateDirectoryW(m_root,0)) { DWORD error=GetLastError(); if(error!=ERROR_ALREADY_EXISTS) return false; }
    return true;
}
MS2_REPLACE_METHOD(0x140653e60, CLogString, FUN_140653e60, 760, 0xA20C55A1);

// MS2-FUNCTIONAL: Equivalent fallback directory creation; GetLastError temporary omitted.
// @0x140654160
bool CLogString::FUN_140654160()
{
    wchar_t module[MAX_PATH],drive[_MAX_DRIVE],directory[_MAX_DIR];
    GetModuleFileNameW(0,module,MAX_PATH); _wsplitpath(module,drive,directory,0,0);
    m_root=StringFormat(L"{0}{1}Log",drive,directory);
    if(!CreateDirectoryW(m_root,0)) { if(GetLastError()!=ERROR_ALREADY_EXISTS) return false; }
    return true;
}
MS2_REPLACE_METHOD(0x140654160, CLogString, FUN_140654160, 267, 0xC1B3B87D);

// MS2-FUNCTIONAL: Equivalent file creation, UTF-16 BOM and seek; local ordering differs.
// @0x140654280
void CLogString::FUN_140654280()
{
    if(!m_file) {
        CStringW path=StringFormat(L"{0}\\{1}",m_directory,FUN_140653880(0));
        int exists=_waccess(path,0);
        m_file=CreateFileW(path,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,0,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
        if(exists!=0) { DWORD written=0; wchar_t bom=0xfeff; WriteFile(m_file,&bom,2,&written,0); }
        LARGE_INTEGER offset; offset.QuadPart=0; SetFilePointerEx(m_file,offset,0,FILE_END);
    }
}
MS2_REPLACE_METHOD(0x140654280, CLogString, FUN_140654280, 388, 0xBB875AD9);

// @0x140654410
void CLogString::FUN_140654410()
{
    Unk_1401b4ec0 guard(m_groupLock,1);
    for(POSITION pos=m_groups.GetHeadPosition();pos;m_groups.GetNext(pos)) {
        GroupPtr group=m_groups.GetValueAt(pos);
        if(!group->m_file) FUN_140654520(group);
    }
}
MS2_REPLACE_METHOD(0x140654410, CLogString, FUN_140654410, 253, 0xF740BBC3);

// MS2-FUNCTIONAL: Equivalent custom file creation; temporary lifetimes differ.
// @0x140654520
void CLogString::FUN_140654520(GroupPtr group)
{
    if(group==NULL) return;
    if(group->m_file) { FlushFileBuffers(group->m_file); CloseHandle(group->m_file); }
    CStringW path=StringFormat(L"{0}\\{1}_{2}",m_directory,FUN_14016a730(group->m_name,0),FUN_140653880(0));
    int exists=_waccess(path,0);
    group->m_file=CreateFileW(path,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,0,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
    if(exists!=0) { DWORD written=0; wchar_t bom=0xfeff; WriteFile(group->m_file,&bom,2,&written,0); }
    LARGE_INTEGER offset; offset.QuadPart=0; SetFilePointerEx(group->m_file,offset,0,FILE_END);
}
MS2_REPLACE_METHOD(0x140654520, CLogString, FUN_140654520, 607, 0xD962302B);

// MS2-FUNCTIONAL: Equivalent guarded handle cleanup; condition lifetime differs.
// @0x140654790
void CLogString::FUN_140654790()
{
    if(m_file) { FlushFileBuffers(m_file); CloseHandle(m_file); m_file=0; }
    Unk_140163940 guard(m_groupLock);
    if(guard==0) {
        for(POSITION pos=m_groups.GetHeadPosition();pos;m_groups.GetNext(pos)) {
            GroupPtr group=m_groups.GetValueAt(pos);
            if(group.get() && group->m_file) { FlushFileBuffers(group->m_file); CloseHandle(group->m_file); group->m_file=0; }
        }
    }
}
MS2_REPLACE_METHOD(0x140654790, CLogString, FUN_140654790, 370, 0x57C96FE3);

// @0x140654910
bool CLogString::FUN_140654910() { return true; }
MS2_REPLACE_METHOD(0x140654910, CLogString, FUN_140654910, 8, 0x71679366);

// @0x140654920
void CLogString::FUN_140654920(unsigned __int64 account,unsigned __int64 character,unsigned category,const CStringW& text)
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
    FUN_140653d40(line);
}
MS2_REPLACE_METHOD(0x140654920, CLogString, FUN_140654920, 178, 0x52509381);

// No hook: creates a custom group on first use (DLL-local RTTI).
// @0x1406549e0
void CLogString::FUN_1406549e0(const CString& name,const CStringW& text)
{
    Unk_1401b4ec0 guard(m_groupLock,1);
    GroupPtr group;
    if(!m_groups.Lookup(name,group)) group=FUN_140654df0(name);
    group->m_queue.AddTail(text); FUN_140652c40();
}
// MS2-FUNCTIONAL: Same character result in the low return bits; wchar_t return code differs.
// @0x140654b10
wchar_t CLogString::FUN_140654b10(int level)
{
    if(level==1) return L'E'; else if(level==2) return L'W'; else if(level==11) return L'I'; else if(level==12) return L'D'; return L'U';
}
MS2_REPLACE_METHOD(0x140654b10, CLogString, FUN_140654b10, 84, 0xACA69F93);

// MS2-FUNCTIONAL: Equivalent category formatting with explicit enum conversion.
// @0x140654b70
CStringW CLogString::FUN_140654b70(unsigned __int64 account,unsigned __int64 character,int level,int category,const CStringW& text)
{
    if(account==0 && character==0) return StringFormat(L"[{0}][LT{1:02}]{2}",FUN_140654b10(level),static_cast<Unk_LogCategory>(category),text);
    return StringFormat(L"[{0}][LT{1:02}][ac={2}][ch={3}]{4}",FUN_140654b10(level),static_cast<Unk_LogCategory>(category),account,character,text);
}
MS2_REPLACE_METHOD(0x140654b70, CLogString, FUN_140654b70, 237, 0xA8607059);

// @0x140654c70
CStringW CLogString::FUN_140654c70(const CStringW& text)
{
    SYSTEMTIME time; GetLocalTime(&time);
    return StringFormat(L"[{0:02}:{1:02}:{2:02}]{3}\r\n",time.wHour,time.wMinute,time.wSecond,text);
}
MS2_REPLACE_METHOD(0x140654c70, CLogString, FUN_140654c70, 134, 0x2C74BB4C);

// MS2-FUNCTIONAL: Equivalent callback snapshot and invocation; loop temporaries differ.
// @0x140654d00
void CLogString::FUN_140654d00(ContextPtr context)
{
    std::vector<Callback> callbacks;
    { Unk_140163940 guard(m_callbackLock); if(guard==0) callbacks=m_callbacks; }
    for(unsigned i=0;i<callbacks.size();++i) callbacks[i](context.get());
}
MS2_REPLACE_METHOD(0x140654d00, CLogString, FUN_140654d00, 234, 0x5F59D737);

// No hook: constructs DLL-local CLogCustomGroup RTTI.
// @0x140654df0
CLogString::GroupPtr CLogString::FUN_140654df0(CString name)
{
    Unk_1401b4ec0 guard(m_groupLock,1);
    GroupPtr group(new CLogCustomGroup(name));
    FUN_140654520(group); m_groups.SetAt(name,group); return group;
}
// MS2-FUNCTIONAL: Equivalent custom queue draining; byte-count temporary placement differs.
// @0x140654f70
void CLogString::FUN_140654f70()
{
    Unk_1401b4ec0 guard(m_groupLock,1);
    for(POSITION pos=m_groups.GetHeadPosition();pos;m_groups.GetNext(pos)) {
        GroupPtr group=m_groups.GetValueAt(pos);
        if(group.get() && group->m_file) {
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
