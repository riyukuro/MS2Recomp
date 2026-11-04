// fieldpropertycli.h - client-side FieldProperty subclasses (Apply/Unapply on map entry/exit). NOT an original header.
// The *Cli classes add no data (except the light ones, which cache the previous entity colour) and override
// vfunc_4 (Apply) / vfunc_5 (Unapply) of FieldProperty (commonfiles/fieldproperty.h). Their destructors are implicit (the
// exe's only forward to the server-class destructor and store no vptr), emitted with the vftables in fieldpropertycli.cpp.
#pragma once
#include "ms2/commonfiles/fieldproperty.h"
#include "ms2/placeholder/ascript.h"

#define MS2_FPCLI(Name)                                  \
    class Name##Cli : public Name {                      \
    public:                                              \
        virtual void vfunc_4();
#define MS2_FPCLI5(Name) MS2_FPCLI(Name) virtual void vfunc_5();

MS2_FPCLI(FieldPropertyGravity) };
MS2_FPCLI5(FieldPropertyMusicConcert) };
MS2_FPCLI5(FieldPropertyHideMyPC) };
MS2_FPCLI5(FieldPropertyLockMyPC) };
MS2_FPCLI(FieldPropertyUserTagSymbol) };
MS2_FPCLI5(FieldPropertyWeather) };
MS2_FPCLI5(FieldPropertyEnableLocalCamera) };
MS2_FPCLI5(FieldPropertyPhotoStudio) };

class FieldPropertyAmbientLightCli : public FieldPropertyAmbientLight {
public:
    virtual void vfunc_4();
    Unk_Vec3f m_vecOld = Unk_Vec3f(0, 0, 0);            // +0x20
    bool m_bCached;                                     // +0x2c
    float m_fCached;                                    // +0x30
};
MS2_CHECK_SIZE(FieldPropertyAmbientLightCli, 0x38);

class FieldPropertyDirectionalLightCli : public FieldPropertyDirectionalLight {
public:
    virtual void vfunc_4();
    Unk_Vec3f m_vecOld = Unk_Vec3f(0, 0, 0);            // +0x28
    bool m_bCached;                                     // +0x34
    float m_fCached;                                    // +0x38
};
MS2_CHECK_SIZE(FieldPropertyDirectionalLightCli, 0x40);

MS2Ptr<FieldProperty> FUN_140b26ff0(int nType);          // factory: 1..11 = Gravity .. PhotoStudio
