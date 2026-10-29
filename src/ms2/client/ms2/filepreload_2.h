#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <set>
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"
#include "ms2/placeholder/tfunctor_search.h"
class CFileSearcher;
template<> class TSingleton<CFileSearcher> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance=0; }
    static CFileSearcher* s_instance;
};
struct Unk_FileSearchEntry { CString path,text; };
MS2_CHECK_SIZE(Unk_FileSearchEntry,0x10);
class CFileSearcher : public CThread,public TSingleton<CFileSearcher> {
public:
    typedef std::list<Unk_FileSearchEntry> EntryList;
    typedef TFunctor<void,ParamList<CString,ParamList<float,EmptyParam>>> ProgressCallback;
    typedef TFunctor<void,EmptyParam> CompletionCallback;
    CFileSearcher();
    virtual ~CFileSearcher();
    virtual unsigned vfunc_1(void*,Unk_140659080&);
    void FUN_141218730(ProgressCallback);
    void FUN_1412187a0(CompletionCallback);
    bool FUN_141218810(const EntryList&,const std::set<CString>&,int,bool);
    void FUN_141218900();
    void FUN_141218920();
    void FUN_141218990(CString directory);
    void FUN_141219020(CString directory);
    void FUN_1412195a0(ATL::CAtlArray<CString>&);
    EntryList queries;
    std::set<CString> directories;
    bool cancelled,running,removeFound;
    int mode;
    ProgressCallback progress;
    CompletionCallback complete;
    EntryList results;
};
inline TSingleton<CFileSearcher>::TSingleton() { s_instance=static_cast<CFileSearcher*>(this); }
MS2_CHECK_SIZE(CFileSearcher,0x68);
MS2_CHECK_OFFSET(CFileSearcher,queries,0x20);
MS2_CHECK_OFFSET(CFileSearcher,directories,0x30);
MS2_CHECK_OFFSET(CFileSearcher,mode,0x44);
MS2_CHECK_OFFSET(CFileSearcher,progress,0x48);
MS2_CHECK_OFFSET(CFileSearcher,results,0x58);
