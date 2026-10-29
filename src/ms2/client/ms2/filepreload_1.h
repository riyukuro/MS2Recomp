#pragma once
#include <afx.h>
#include <set>
#include <utility>
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tfunctor_small.h"
class CFilePreload;
template<> class TSingleton<CFilePreload> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance=0; }
    static CFilePreload* s_instance;
    static CFilePreload* GetInstance();                 // 0x140ab7a10
};
typedef std::pair<unsigned,unsigned short> Unk_PreloadKey;
struct Unk_PreloadId {
    Unk_PreloadId(const Unk_PreloadKey& k,int p) : key(k),priority(p) {}
    Unk_PreloadId(unsigned id,unsigned short level,int p) : key(id,level),priority(p) {}
    bool operator<(const Unk_PreloadId& other) const { return key<other.key; }
    Unk_PreloadKey key;
    mutable int priority;
};
struct Unk_PreloadPath {
    Unk_PreloadPath(CString value,int p) : priority(p) { path=value; }
    bool operator<(const Unk_PreloadPath& other) const { return path<other.path; }
    CString path;
    mutable int priority;
};
MS2_CHECK_SIZE(Unk_PreloadId,12);
MS2_CHECK_SIZE(Unk_PreloadPath,16);
class CFilePreload : public CThread,public TSingleton<CFilePreload> {
public:
    typedef TFunctor<void,ParamList<int,EmptyParam>> ProgressCallback;
    typedef TFunctor<void,ParamList<void*,EmptyParam>> Job;
    CFilePreload();
    virtual ~CFilePreload();
    virtual unsigned vfunc_1(void*,Unk_140659080&);
    void FUN_14120fcc0();
    void FUN_14120fdb0();
    void FUN_14120fe80();
    void FUN_1412102e0();
    void FUN_141210420(int);
    void FUN_1412104a0(int);
    void FUN_1412104c0(unsigned);
    void FUN_141210540(unsigned,unsigned short,int);
    void FUN_1412106a0(Unk_PreloadKey,int);
    void FUN_141210770(unsigned);
    void FUN_1412107f0(CString,int);
    void FUN_141210960(CString,int);
    void FUN_141210ac0(CString);
    int FUN_141210b60(unsigned);
    void FUN_141210c20();
    int FUN_141210c60();
    int FUN_141210c80();
    static void FUN_141210ca0(bool);
    void FUN_141210cc0(bool);
    void FUN_141210ce0(Job);
    void FUN_141210da0();
    void FUN_141210e10(bool);
    void FUN_141210f00(bool);
    void FUN_141211240(void*);
    void FUN_141211380(void*);
    void FUN_141211480(void*);
    void FUN_1412115e0(void*);
    void FUN_141211700(void*);
    void FUN_141211880(void*);
    void FUN_1412119e0(void*);
    void FUN_141211b30(int);
    static UINT FUN_141211b80(void*);
    void FUN_141211c20();
    ProgressCallback callback;
    Job job;
    int stopped;
    int preloadIds;
    bool asynchronous;
    volatile int initialized;
    int dataReady;
    int phase;
    CLockCriticalSection stateLock;
    volatile int state;
    std::set<unsigned> ids;
    CLockCriticalSection idsLock;
    std::set<Unk_PreloadId> itemRequests;
    CLockCriticalSection itemLock;
    std::set<Unk_PreloadPath> effectRequests;
    CLockCriticalSection effectLock;
    std::set<Unk_PreloadPath> nifRequests;
    CLockCriticalSection nifLock;
    std::set<CString> paths;
    CLockCriticalSection pathLock;
    std::set<unsigned> itemIds;
    CLockCriticalSection itemIdsLock;
    HANDLE semaphore;
    CWinThread* backgroundThread;
};
inline TSingleton<CFilePreload>::TSingleton() { s_instance=static_cast<CFilePreload*>(this); }
MS2_CHECK_SIZE(CFilePreload,0x210);
MS2_CHECK_OFFSET(CFilePreload,callback,0x20);
MS2_CHECK_OFFSET(CFilePreload,stateLock,0x48);
MS2_CHECK_OFFSET(CFilePreload,state,0x78);
MS2_CHECK_OFFSET(CFilePreload,ids,0x80);
MS2_CHECK_OFFSET(CFilePreload,itemRequests,0xc0);
MS2_CHECK_OFFSET(CFilePreload,effectRequests,0x100);
MS2_CHECK_OFFSET(CFilePreload,nifRequests,0x140);
MS2_CHECK_OFFSET(CFilePreload,paths,0x180);
MS2_CHECK_OFFSET(CFilePreload,itemIds,0x1c0);
MS2_CHECK_OFFSET(CFilePreload,semaphore,0x200);
