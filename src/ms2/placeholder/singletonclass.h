// singletonclass.h - PLACEHOLDER for SingletonClass<T> (RTTI .?AV?$SingletonClass@V<T>@@@@): the empty singleton base of the
// GFx UI library's managers (GFxManager, GFxService, GFxSceneService, UISwfEntityManager, UIAlignWidgetManager,
// UniqueSwfIDCreator; RTTI puts it right after efd::MemObject, e.g. @9). NOT an original header. Its ctor stores the
// derived object in the class's static instance pointer (static_cast with a null check: 0x1422f7020 for
// T = UniqueSwfIDCreator). The instance pointer is an exe global per T: declared here, never defined, so each T needs a
// progress/symbols-manual.tsv data row (UniqueSwfIDCreator: 0x143b0d2d8, GFxSceneService: 0x143ab25e8).
//
// GetInstance / CreateInstance / DestroyInstance: the per-T COMDATs GFxService's ctor/dtor (?\gfxservice.cpp) create and
// destroy the managers with (names assumed; the exe sorts them between ??_G and DecRefCount / DeleteThis and GetClassDesc
// / GetRefCount, so Create*, Destroy* and GetI*). Each T's GetInstance is an exe function (GFxManager 0x14025e7a0, ...):
// it needs a symbols-manual row. CreateInstance / DestroyInstance need a complete T (EE_NEW / EE_DELETE).
#pragma once

#include <efd/MemObject.h>

template <class T>
class SingletonClass
{
public:
    SingletonClass() { ms_pSingleton = static_cast<T*>(this); }
    ~SingletonClass() { ms_pSingleton = 0; }                                // 0x1422ba450 for T = GFxSceneService
    static T* GetInstance() { return ms_pSingleton; }                       // 0x1422eaa40 for T = GFxAtlasCache
    static T* CreateInstance()                                              // 0x1422ea510 for T = GFxAtlasCache
    {
        return ms_pSingleton ? GetInstance() : EE_NEW T;
    }
    static void DestroyInstance()                                           // 0x1422ea870 for T = GFxAtlasCache
    {
        if (ms_pSingleton)
            EE_DELETE GetInstance();
    }
    static T* ms_pSingleton;
};
