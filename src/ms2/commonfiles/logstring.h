// Logging classes; method and field names are inferred except RTTI names.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <vector>
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/ms2format.h"
enum class Unk_LogCategory : int {};
class CLogString;
// This instantiation stores the complete object, whose singleton base is at +0x18.
// The generic header currently stores the base pointer, so use the proven specialization here.
template<> class TSingleton<CLogString> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance=0; }
    static CLogString* s_instance;
    static CLogString* GetInstance();                   // 0x140166440
};
class Unk_1406583d0Ref { public: void FUN_14015b020(); int FUN_140159bc0(); void FUN_140159ba0(); };
template<class T> class Unk_1406583d0 {
public:
    Unk_1406583d0() : m_p(0) {}
    Unk_1406583d0(T* p) : m_p(p) { AddRef(); }
    Unk_1406583d0(const Unk_1406583d0& o) : m_p(o.m_p) { AddRef(); }
    Unk_1406583d0(Unk_1406583d0&& o) : m_p(o.m_p) { o.m_p=0; }
    ~Unk_1406583d0() { Release(); }
    Unk_1406583d0& operator=(const Unk_1406583d0& o) { o.AddRef(); Release(); m_p=o.m_p; return *this; }
    bool operator==(T* p) const { return m_p==p; }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
private:
    void AddRef() const { if(m_p) AddRefImpl(0); }
    static void Reference(T* p) { reinterpret_cast<Unk_1406583d0Ref*>(p)->FUN_14015b020(); }
    void AddRefImpl(void*) const { Reference(m_p); }
    void Release() { if(m_p) { ReleaseImpl(0); m_p=0; } }
    void ReleaseImpl(void*) { if(reinterpret_cast<Unk_1406583d0Ref*>(m_p)->FUN_140159bc0()==0) { Reference(m_p); reinterpret_cast<Unk_1406583d0Ref*>(m_p)->FUN_140159ba0(); } }
    void* m_00; T* m_p;
};
class CLogCustomGroup : public CPtred {
public:
    CLogCustomGroup(CString name);
    virtual ~CLogCustomGroup();
    CString m_name;
    HANDLE m_file;
    ATL::CAtlList<CStringW> m_queue;
};
MS2_CHECK_SIZE(CLogCustomGroup,0x58);
MS2_CHECK_OFFSET(CLogCustomGroup,m_queue,0x28);
class CLogStringCtx : public CPtred {
public:
    CLogStringCtx() {}
    virtual ~CLogStringCtx() = default;
    int m_level;
    int m_category;
    unsigned __int64 m_account;
    unsigned __int64 m_character;
    CStringW m_text;
};
MS2_CHECK_SIZE(CLogStringCtx,0x38);
MS2_CHECK_OFFSET(CLogStringCtx,m_text,0x30);
class CLogString : public CThread, public TSingleton<CLogString> {
public:
    typedef Unk_1406583d0<CLogCustomGroup> GroupPtr;
    typedef Unk_1406583d0<CLogStringCtx> ContextPtr;
    typedef Delegate<void(CLogStringCtx*)> Callback;
    CLogString();
    virtual ~CLogString();
    virtual unsigned int vfunc_1(void*,Unk_140659080&);
    void FUN_140652a40(CStringW name);
    void FUN_140652bc0(); void FUN_140652c40();
    void FUN_1406530d0(int,int,const wchar_t*,const fmt::ArgList&);
    void FUN_140653130(unsigned __int64,unsigned __int64,int,int,const wchar_t*,const fmt::ArgList&);
    void FUN_140653440(const CString&,const wchar_t*,const fmt::ArgList&);
    void FUN_140653550(unsigned __int64,unsigned __int64,int,const wchar_t*,const fmt::ArgList&);
    void FUN_1406535b0(unsigned __int64,unsigned __int64,int,const wchar_t*,const fmt::ArgList&);
    // The argument-less form of the 0x1406535b0 log call (a header inline, first emitted by commonstruct.cpp at
    // 0x1402804e0; the original is probably a variadic template's zero-argument instance).
    void FUN_1402804e0(unsigned __int64 a,unsigned __int64 c,int category,const wchar_t* text) { FUN_1406535b0(a,c,category,text,fmt::ArgList()); }
    void FUN_140653690(unsigned __int64,unsigned __int64,int,const wchar_t*,const fmt::ArgList&);
    void FUN_1406536f0(unsigned __int64,unsigned __int64,int,const wchar_t*,const fmt::ArgList&);
    void FUN_140653750(unsigned __int64,unsigned __int64,int,const wchar_t*,const fmt::ArgList&);
    void FUN_1406537e0(int); void FUN_140653800(int);
    int FUN_140653820(); int FUN_140653840(); int FUN_140653860();
    CStringW FUN_140653880(int fullPath);
    CStringW FUN_140653b30();
    void FUN_140653b80(Callback);
    void FUN_140653bf0(Callback);
    void FUN_140653d40(const CStringW&);
    void FUN_140653de0(unsigned __int64,unsigned __int64,int,int,const CStringW&);
    void FUN_140653e00(int);
    bool FUN_140653e60(); bool FUN_140654160();
    void FUN_140654280(); void FUN_140654410(); void FUN_140654520(GroupPtr); void FUN_140654790();
    bool FUN_140654910();
    void FUN_140654920(unsigned __int64,unsigned __int64,unsigned,const CStringW&);
    void FUN_1406549e0(const CString&,const CStringW&);
    wchar_t FUN_140654b10(int);
    CStringW FUN_140654b70(unsigned __int64,unsigned __int64,int,int,const CStringW&);
    CStringW FUN_140654c70(const CStringW&);
    void FUN_140654d00(ContextPtr);
    GroupPtr FUN_140654df0(CString);
    void FUN_140654f70();
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<HANDLE> m_Handles;
    CLockCriticalSection m_queueLock;
    ATL::CAtlList<CStringW> m_queue;
    HANDLE m_file;
    CStringW m_directory,m_root,m_name;
    unsigned m_day;
    int m_instance,m_loadingError,m_fileLevel,m_debugLevel,m_errors,m_warnings;
    CLockCriticalSection m_callbackLock;
    std::vector<Callback> m_callbacks;
    CLockCriticalSection m_groupLock;
    ATL::CRBMap<CString,GroupPtr,ATL::CStringElementTraitsI<CString>> m_groups;
};
MS2_CHECK_SIZE(CLogString,0x188);
MS2_CHECK_OFFSET(CLogString,m_Handles,0x20);
MS2_CHECK_OFFSET(CLogString,m_queue,0x70);
MS2_CHECK_OFFSET(CLogString,m_file,0xa0);
MS2_CHECK_OFFSET(CLogString,m_callbacks,0x110);
MS2_CHECK_OFFSET(CLogString,m_groups,0x158);
inline TSingleton<CLogString>::TSingleton() { s_instance=static_cast<CLogString*>(this); }
