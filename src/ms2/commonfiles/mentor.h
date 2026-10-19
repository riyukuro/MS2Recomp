// Recovered mentorship packets. Unk_ packet names describe inferred layouts.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
class Unk_MentorReader;
class Unk_MentorWriter;
class CInOutStreamInterface {
public:
    CInOutStreamInterface() throw() {}
    virtual void vfunc_0(Unk_MentorWriter&) = 0;
    virtual void vfunc_1(Unk_MentorReader&) = 0;
};
class Unk_MentorRef { public: void FUN_14015b020(); int FUN_140159bc0(); void FUN_140159ba0(); };
template<class T> class Unk_MentorPtr {
public:
    Unk_MentorPtr() : p(0) {}
    Unk_MentorPtr(int) : p(0) {}                       // 0x140b72f60 (mentoringmanager.cpp: `return 0`)
    Unk_MentorPtr(T* value) : p(value) { AddRef(); }
    ~Unk_MentorPtr() { Release(); }
    Unk_MentorPtr& operator=(T* value) { Unk_MentorPtr temp(value); T* old=p; p=temp.p; temp.p=old; return *this; }
    T* operator->() const { return p; }
    // agents: copy/move/get used by guess\menteesearch.cpp (0x140b6f880 copy, 0x140b6f850 move, 0x140b6fce0 assign, 0x140b6fe60 get)
    Unk_MentorPtr(const Unk_MentorPtr& o) : p(o.p) { AddRef(); }
    Unk_MentorPtr(Unk_MentorPtr&& o) : p(o.p) { o.p = 0; }
    Unk_MentorPtr& operator=(const Unk_MentorPtr& o) { o.AddRef(); Release(); p = o.p; return *this; }
    T* get() const { return p; }
    bool operator==(T* o) const { return p == o; }     // 0x140b733c0 (mentoringmanager.cpp)
private:
    void AddRef() const { if(p) AddRefImpl(0); }
    static void AddRefObject(T* value) { reinterpret_cast<Unk_MentorRef*>(value)->FUN_14015b020(); }
    void AddRefImpl(void*) const { AddRefObject(p); }
    void Release() { if(p) { ReleaseImpl(0); p=0; } }
    void ReleaseImpl(void*) { if(reinterpret_cast<Unk_MentorRef*>(p)->FUN_140159bc0()==0) { AddRefObject(p); reinterpret_cast<Unk_MentorRef*>(p)->FUN_140159ba0(); } }
    void* pad_00; T* p;
};
class CMentor : public CPtred, public CInOutStreamInterface {
public:
    CMentor(); ~CMentor();
    void FUN_14069ae30(Unk_MentorWriter&);
    void FUN_14069af00(Unk_MentorReader&);
    virtual void vfunc_0(Unk_MentorWriter& stream) { FUN_14069ae30(stream); }
    virtual void vfunc_1(Unk_MentorReader& stream) { FUN_14069af00(stream); }
    __int64 a,b,c; CStringW name; unsigned short level; CStringW guild; int x,y; bool online;
};
MS2_CHECK_SIZE(CMentor,0x60);
MS2_CHECK_OFFSET(CMentor,a,0x20);
MS2_CHECK_OFFSET(CMentor,name,0x38);
MS2_CHECK_OFFSET(CMentor,guild,0x48);
class CMentorPairModePacket {
public:
    class CPairMode : public CInOutStreamInterface {
    public:
        CPairMode() : id(0), enabled(false) {}
        void FUN_14069aba0(Unk_MentorWriter&);
        void FUN_14069abe0(Unk_MentorReader&);
        virtual void vfunc_0(Unk_MentorWriter& stream) { FUN_14069aba0(stream); }
        virtual void vfunc_1(Unk_MentorReader& stream) { FUN_14069abe0(stream); }
        __int64 id; bool enabled;
    };
    void FUN_14069ab00(Unk_MentorWriter&);
    void FUN_14069ab50(Unk_MentorReader&);
    unsigned char protocol; ATL::CAtlArray<CPairMode> entries;
};
MS2_CHECK_SIZE(CMentorPairModePacket::CPairMode,0x18);
class Unk_MentorReader {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual unsigned int vfunc_3();
    void FUN_14070f300(bool&); void FUN_14070f340(unsigned char&); void FUN_14070f380(unsigned short&);
    void FUN_14070f480(unsigned int&); void FUN_14070f480(int&); void FUN_14070f4c0(__int64&);
    void FUN_14070f5f0(CStringW&); void FUN_14070f770(CInOutStreamInterface&);
    template<class T> Unk_MentorReader& ReadItems(ATL::CAtlArray<T>& output) {
        unsigned int count=vfunc_3();
        for(unsigned int i=0;i<count;++i) { T item; FUN_14070f770(item); output.Add(item); }
        return *this;
    }
};
class Unk_MentorWriter {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(unsigned int);
    void FUN_14070f820(bool); void FUN_14070f860(unsigned char); void FUN_14070f8a0(unsigned short);
    void FUN_14070f9a0(unsigned int); void FUN_14070f9e0(__int64); void FUN_14070fae0(const CStringW&);
    void FUN_14070fc40(const CInOutStreamInterface&);
    template<class T> Unk_MentorWriter& WriteItems(const ATL::CAtlArray<T>& input) {
        vfunc_3(static_cast<unsigned int>(input.GetCount()));
        for(size_t i=0;i<input.GetCount();++i) FUN_14070fc40(input[i]);
        return *this;
    }
};
namespace PROTOCOL_MENTORING { enum { MENTOR_LIST=2, MENTEE_LIST=3 }; }
class Unk_MentorListPacket {
public:
    void FUN_14069a0b0(Unk_MentorReader& stream);
    void FUN_14069a290(Unk_MentorReader& stream);
    void FUN_14069a1f0(Unk_MentorWriter& stream);
    unsigned char nProtocol; ATL::CAtlArray<Unk_MentorPtr<CMentor>> entries;
};
class Unk_MentorResultPacket {
public:
    void FUN_14069a3d0(Unk_MentorWriter& stream);
    void FUN_14069a420(Unk_MentorReader& stream);
    void FUN_14069a8c0(Unk_MentorWriter& stream);
    void FUN_14069a910(Unk_MentorReader& stream);
    unsigned char protocol,result; int value;
};
class Unk_MentorEmptyPacket {
public:
    void FUN_14069a480(Unk_MentorWriter& stream);
    void FUN_14069a4b0(Unk_MentorReader& stream);
    void FUN_14069a4e0(Unk_MentorWriter& stream);
    void FUN_14069a510(Unk_MentorReader& stream);
    unsigned char protocol;
};
class Unk_MentorNamePacket {
public:
    void FUN_14069a540(Unk_MentorWriter& stream);
    void FUN_14069a5a0(Unk_MentorReader& stream);
    unsigned char protocol; __int64 id; CStringW name;
};
class Unk_MentorIdPacket {
public:
    void FUN_14069a630(Unk_MentorWriter& stream);
    void FUN_14069a670(Unk_MentorReader& stream);
    void FUN_14069a6c0(Unk_MentorWriter& stream);
    void FUN_14069a700(Unk_MentorReader& stream);
    unsigned char protocol; __int64 id;
};
class Unk_MentorDetailPacket {
public:
    void FUN_14069a7e0(Unk_MentorWriter& stream);
    void FUN_14069a850(Unk_MentorReader& stream);
    Unk_MentorDetailPacket(); unsigned char protocol; CStringW name; Unk_MentorPtr<CMentor> mentor;
};
class Unk_MentorValuePacket {
public:
    void FUN_14069a970(Unk_MentorWriter& stream);
    void FUN_14069a9c0(Unk_MentorReader& stream);
    unsigned char protocol; int value; __int64 id;
};
class Unk_MentorTwoValuePacket {
public:
    void FUN_14069aa20(Unk_MentorWriter& stream);
    void FUN_14069aa90(Unk_MentorReader& stream);
    unsigned char protocol; int a,b; __int64 id;
};
class Unk_MentorTwoIdPacket {
public:
    void FUN_14069ac30(Unk_MentorWriter& stream);
    void FUN_14069ac90(Unk_MentorReader& stream);
    unsigned char protocol; __int64 a,b;
};
MS2_CHECK_OFFSET(Unk_MentorListPacket,entries,8);
MS2_CHECK_OFFSET(Unk_MentorDetailPacket,mentor,0x10);
MS2_CHECK_OFFSET(Unk_MentorNamePacket,name,0x10);
MS2_CHECK_OFFSET(Unk_MentorTwoValuePacket,id,0x10);
MS2_CHECK_SIZE(Unk_MentorPtr<CMentor>,0x10);
