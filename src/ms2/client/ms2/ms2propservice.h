#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "ms2/placeholder/ms2stdafx.h"
#include <ecrPhysX/PropService.h>
#include <egf/IPropertyCallback.h>
#include "ms2/ms2layout.h"

namespace ecr { class SceneGraphCache; }

class MS2PropService : public ecrPhysX::PropService, public egf::IPropertyCallback {
public:
    static const efd::ClassInfo ms_ClassInfo;
    virtual const efd::ClassInfo* GetClassDesc() const { return &ms_ClassInfo; }
    virtual bool TypeCast(efd::ClassID id, const void** out) const {
        *out = ms_ClassInfo.TypeCast(id, this); if (*out != NULL) return true; return false;
    }
    virtual bool TypeCast(efd::ClassID id, void** out) const {
        *out = ms_ClassInfo.TypeCast(id, this); if (*out != NULL) return true; return false;
    }
    virtual void IncRefCount() const { ++m_RefCount; }
    virtual void DecRefCount() const { if (--m_RefCount == 0) DeleteThis(); }
    virtual efd::UInt32 GetRefCount() const { return m_RefCount; }
protected:
    virtual void DeleteThis() const { EE_DELETE this; }
public:
    MS2PropService();
    virtual ~MS2PropService();
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar*);
    virtual efd::AsyncResult OnInit();
    virtual void OnPropertyUpdate(const efd::ClassID&, egf::Entity*, const egf::PropertyID&,
                                  const egf::IProperty*, efd::UInt32);
    virtual bool AddPhysXPropToPropData(egf::Entity*, PropData*);
    virtual bool RemovePropFromScene(PropData*);
};

MS2_CHECK_SIZE(ecrPhysX::PropService, 0x78);
MS2_CHECK_SIZE(MS2PropService, 0x88);
