// ms2propertyvisualizationservice.h - PLACEHOLDER for MS2PropertyVisualizationService (RTTI
// .?AVMS2PropertyVisualizationService@@, 0xa8 bytes, no members of its own). NOT an original header. The game's
// egmVisualizers::PropertyVisualizationService; it keeps the engine's class id and only renames the service. It has no
// user-declared ctor: MS2::RegisterServices value-initialises it (the zero fill plus the implicit ctor, 0x1414962a0
// in ?\ms2.cpp). GetDisplayName and the class info live in unit_1414a1c30.
#pragma once

#include <egmVisualizers/PropertyVisualizationService.h>

#include "ms2/ms2layout.h"

class MS2PropertyVisualizationService : public egmVisualizers::PropertyVisualizationService
{
    // EE_DECLARE_CLASS1 without a ms_ClassInfo of its own: the exe's virtuals use the base's (0x143a284b0).
public:
    static const efd::ClassID CLASS_ID = efd::kCLASSID_PropertyVisualizationService;
    typedef MS2PropertyVisualizationService thisClass;
    virtual const efd::ClassInfo* GetClassDesc() const {return &ms_ClassInfo;};
    virtual bool TypeCast(const efd::ClassID id, const void** ppValue) const
    {
        *(ppValue) = ms_ClassInfo.TypeCast(id, this);
        if (*(ppValue) != NULL)
            return true;
        return false;
    }
    virtual bool TypeCast(const efd::ClassID id, void** ppValue) const
    {
        *(ppValue) = ms_ClassInfo.TypeCast(id, this);
        if (*(ppValue) != NULL)
            return true;
        return false;
    }
    virtual const char* GetDisplayName() const;                     // 0x1414a5680
};
MS2_CHECK_SIZE(MS2PropertyVisualizationService, 0xa8);
