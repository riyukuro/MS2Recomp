// casyncimageloader.h - PLACEHOLDER for CAsyncImageLoader (RTTI .?AVCAsyncImageLoader@@, 0x98 bytes). NOT an original header.
// Bases: CThread at +0x0, TSingleton<CAsyncImageLoader> at +0x18. A TSingleton that CGameApp::InitInstance (?\ms2.cpp)
// creates; it loads UI images (Scaleform images backed by Gamebryo textures) on its own thread. Owning unit:
// client\ms2\asyncimageloader.cpp. The members are named from use.
//
// Flow: a caller queues a request (FUN_140a589d0: an ImageLoaderParam with the file name and the Scaleform image) in
// m_68; the thread moves the queue to a local list, reads every file (FUN_140a59090: texture cache or NiImageConverter) and
// appends the loaded ones to m_78; the main thread (FUN_140a58b90, from the frame update) moves m_78 to m_88 and binds the
// textures to their Scaleform images (FUN_140a59540), dropping each request it could apply.
#pragma once

#include <list>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"
#include "ms2/placeholder/clockcriticalsection.h"

class CPtred;
void FUN_14015b020(CPtred* p);              // CPtred::AddRef
int FUN_140159bc0(CPtred* p);               // CPtred::Release (the new count)
void FUN_140159ba0(CPtred* p);              // CPtred::Delete

class ImageLoaderParam;
class GfxImageLoaderParam;
class Unk_GfxImage;

// The 16-byte reference to a request kept in the queues: +0 unused, the pointer at +8 (same shape as logstring.h's
// Unk_1406583d0). Copies add a reference, moves steal it.
template <class T>
class Unk_ImgPtr
{
public:
    // @0x140a5a5b0
    Unk_ImgPtr(T* p) : m_p(p) { AddRef(); }
    // @0x140a5a570
    Unk_ImgPtr(const Unk_ImgPtr& o) : m_p(o.m_p) { AddRef(); }
    // @0x140a5a540
    Unk_ImgPtr(Unk_ImgPtr&& o) : m_p(o.m_p) { o.m_p = 0; }
    // @0x140a5a960
    ~Unk_ImgPtr() { Release(); }
    // @0x140a5abb0
    bool operator!() const { return m_p == 0; }
    // @0x140a5acc0
    T* operator->() const { return m_p; }
    // @0x140a5af80
    T* get() const { return m_p; }

private:
    // @0x140a5b040
    void AddRef() const
    {
        if (m_p)
            AddRefImpl(0);
    }
    // @0x140a5b070
    static void Reference(T* p) { FUN_14015b020((CPtred*)p); }
    // @0x140a5b090
    void AddRefImpl(void*) const { Reference(m_p); }
    // @0x140a5b410
    void Release()
    {
        if (m_p)
        {
            ReleaseImpl(0);
            m_p = 0;
        }
    }
    // @0x140a5b450
    void ReleaseImpl(void*)
    {
        if (FUN_140159bc0((CPtred*)m_p) == 0)
        {
            Reference(m_p);
            FUN_140159ba0((CPtred*)m_p);
        }
    }
    void* m_00;
    T* m_p;
};
MS2_CHECK_SIZE(Unk_ImgPtr<ImageLoaderParam>, 0x10);

struct Unk_ImgSize
{
    // @0x140a5a490
    Unk_ImgSize(int w, int h) { Set(w, h); }
    // @0x140a5b010
    void Set(int w, int h)
    {
        m_w = w;
        m_h = h;
    }
    int m_w;
    int m_h;
};

// A Scaleform image of the UI (slot 1 adds a reference, slot 2 releases it).
class Unk_GfxImage
{
public:
    virtual void vfunc_0();
    virtual void AddRef();
    virtual void Release();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual Unk_ImgSize* GetSize(Unk_ImgSize* pOut);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void* vfunc_24(void* pCtx);                     // the renderer object of the image
};

// The counted pointer to it (TPtr<>); passed by value, the callee destroys it.
class Unk_GfxRef
{
public:
    // @0x140a5a450
    Unk_GfxRef(Unk_GfxImage* p)
    {
        if (p)
            p->AddRef();
        m_p = p;
    }
    // @0x140a5a8c0
    ~Unk_GfxRef()
    {
        if (m_p)
            m_p->Release();
    }
    // @0x140a5aac0
    Unk_GfxRef& operator=(const Unk_GfxRef& o)
    {
        if (o.get())
            o.operator->()->AddRef();
        if (m_p)
            m_p->Release();
        m_p = o.get();
        return *this;
    }
    // @0x140a5ac60
    Unk_GfxImage* get() const { return m_p; }
    // @0x140a5ac90
    Unk_GfxImage* operator->() const { return m_p; }

private:
    Unk_GfxImage* m_p;
};

class CAsyncImageLoader : public CThread, public TSingleton<CAsyncImageLoader>
{
public:
    typedef Unk_ImgPtr<ImageLoaderParam> ParamPtr;
    typedef std::list<ParamPtr> ParamList;

    CAsyncImageLoader();                                    // 0x140a58820
    virtual ~CAsyncImageLoader();                           // 0x140a58900
    virtual unsigned int vfunc_1(void*, Unk_140659080&);    // 0x140a58d70 the loader thread
    void FUN_140a589d0(const CString& strFile, Unk_GfxRef spImage);   // queue a request
    void FUN_140a58b90();                                   // bind the loaded textures (main thread)
    void FUN_140a58b10();                                   // stops it
    bool FUN_140a59090(ParamPtr spParam);                   // read the file of a request (loader thread)
    bool FUN_140a59540(ParamPtr spParam);                   // bind the texture of a request to its image
    void FUN_140a597a0();                                   // drop all requests
private:
    MS2_LAYOUT_FRIEND;
    bool m_20;                                              // +0x20 stop the thread
    HANDLE m_28;                                            // +0x28 event: wakes the thread up for the exit
    HANDLE m_30;                                            // +0x30 semaphore: counts the queued requests
    CLockCriticalSection m_38;                              // +0x38 guards the three lists
    ParamList m_68;                                         // +0x68 requests not read yet
    ParamList m_78;                                         // +0x78 requests that are read
    ParamList m_88;                                         // +0x88 requests waiting to be bound
};
MS2_CHECK_SIZE(CAsyncImageLoader, 0x98);
MS2_CHECK_OFFSET(CAsyncImageLoader, m_38, 0x38);
MS2_CHECK_OFFSET(CAsyncImageLoader, m_68, 0x68);
MS2_CHECK_OFFSET(CAsyncImageLoader, m_88, 0x88);
