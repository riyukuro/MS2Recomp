// singletonclass.h - PLACEHOLDER for SingletonClass<T> (RTTI .?AV?$SingletonClass@V<T>@@@@): the empty singleton base of the
// GFx UI library's managers (GFxManager, GFxService, GFxSceneService, UISwfEntityManager, UIAlignWidgetManager,
// UniqueSwfIDCreator; RTTI puts it right after efd::MemObject, e.g. @9). NOT an original header. Its ctor stores the
// derived object in the class's static instance pointer (static_cast with a null check: 0x1422f7020 for
// T = UniqueSwfIDCreator). The instance pointer is an exe global per T: declared here, never defined, so each T needs a
// progress/symbols-manual.tsv data row (UniqueSwfIDCreator: 0x143b0d2d8).
#pragma once

template <class T>
class SingletonClass
{
public:
    SingletonClass() { ms_pSingleton = static_cast<T*>(this); }
    static T* ms_pSingleton;
};
