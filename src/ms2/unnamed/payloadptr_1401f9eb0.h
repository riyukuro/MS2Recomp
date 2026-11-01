// Unit-local spelling of the unknown 16-byte intrusive-pointer template.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
template<class T> class Unk_PayloadPtr {
public:
    Unk_PayloadPtr(){p=0;}
    Unk_PayloadPtr(int){p=0;}
    Unk_PayloadPtr(T* value){p=value;AddRef();}
    Unk_PayloadPtr(const Unk_PayloadPtr& value){p=value.p;AddRef();}
    Unk_PayloadPtr(Unk_PayloadPtr&& value){p=value.p;value.p=0;}
    ~Unk_PayloadPtr(){Release();}
    Unk_PayloadPtr& operator=(const Unk_PayloadPtr& value){value.AddRef();Release();p=value.p;return *this;}
    Unk_PayloadPtr& operator=(int){Release();return *this;}                                            // guilddef#4 0x1404ef9b0
    Unk_PayloadPtr& operator=(T* value){Unk_PayloadPtr tmp(value);T* old=p;p=tmp.p;tmp.p=old;return *this;}   // 0x1404efa90
    operator T*()const{return p;}
    T* operator->()const{return p;}
    T* get()const{return p;}
    bool operator==(T* value)const{return p==value;}
    bool IsNull()const{return p==0;} // a4: CQuest handle null test, 0x1407475b0
private:
    void AddRef()const{if(p)AddRefImpl(0);}
    void AddRefImpl(void*)const{Reference(p);}
    static void Reference(T* value){CPtred::AddRefPtred(reinterpret_cast<CPtred*>(value));}
    void Release(){if(p){ReleaseImpl(0);p=0;}}
    void ReleaseImpl(void*){if(CPtred::ReleasePtred(reinterpret_cast<CPtred*>(p))==0){Reference(p);CPtred::DeletePtred(reinterpret_cast<CPtred*>(p));}}
    void* unknown;T* p;
};
MS2_CHECK_SIZE(Unk_PayloadPtr<int>,16);
