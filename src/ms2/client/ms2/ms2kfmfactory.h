#pragma once
#include <egmAnimation/KFMFactory.h>
#include <egmAnimation/KFMCache.h>
#include "ms2/ms2layout.h"
class MS2KFMFactory : public egmAnimation::KFMFactory {
    EE_DECLARE_CLASS1(MS2KFMFactory,efd::kCLASSID_KFMFactory,egmAnimation::KFMFactory);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    MS2KFMFactory(efd::AssetFactoryManager*,efd::MessageService*);
    virtual ~MS2KFMFactory();
    virtual LoadStatus LoadAsset(efd::AssetFactoryManager*,const efd::AssetLoadRequest*,efd::AssetLoadResponsePtr&);
    class ResponseData : public egmAnimation::KFMFactory::ResponseData {
        EE_DECLARE_CLASS1(MS2KFMFactory::ResponseData,efd::kCLASSID_KFMFactoryData,egmAnimation::KFMFactory::ResponseData);
        EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
    public:
        ResponseData();
        virtual ~ResponseData();
        // Exe extends the response interface with slot 9; bundled SDK base declares this nonvirtual.
        virtual void LoadKFMTool(NiKFMTool*,const egmAnimation::KFMFactoryRequest*);
    };
};
MS2_CHECK_SIZE(MS2KFMFactory,0x78);
MS2_CHECK_SIZE(MS2KFMFactory::ResponseData,0x48);
class MS2KFMCache : public egmAnimation::KFMCache {
    EE_DECLARE_CLASS1(MS2KFMCache,efd::kCLASSID_KFMCache,egmAnimation::KFMCache);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    MS2KFMCache();
    // virtual ~MS2KFMCache();                                 // 0x1414abca0, implicit
    virtual void Init(efd::MessageService*,efd::AssetLocatorService*,efd::AssetFactoryManager*);
};

MS2_CHECK_SIZE(MS2KFMCache,0xe8);
