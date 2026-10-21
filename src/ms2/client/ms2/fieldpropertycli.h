// fieldpropertycli.h - client-side FieldProperty subclasses (Apply/Unapply on map entry/exit). NOT an original header.
// The *Cli classes add no data (except the light ones, which cache the previous entity colour) and override
// vfunc_4 (Apply) / vfunc_5 (Unapply) of FieldProperty (commonfiles/fieldproperty.h). Their destructors only forward to the
// server-class destructor and store no vptr, so they are declared here, bound to the exe through
// progress/symbols-manual.tsv, and written as FUN_<va> forwarding functions in fieldpropertycli.cpp.
#pragma once
#include "ms2/commonfiles/fieldproperty.h"
#include "ms2/placeholder/ascript.h"

#define MS2_FPCLI(Name)                                  \
    class Name##Cli : public Name {                      \
    public:                                              \
        virtual ~Name##Cli();                            \
        virtual void vfunc_4();                          \
        virtual void vfunc_5();

MS2_FPCLI(FieldPropertyGravity) };
MS2_FPCLI(FieldPropertyMusicConcert) };
MS2_FPCLI(FieldPropertyHideMyPC) };
MS2_FPCLI(FieldPropertyLockMyPC) };
MS2_FPCLI(FieldPropertyUserTagSymbol) };
MS2_FPCLI(FieldPropertyWeather) };
MS2_FPCLI(FieldPropertyEnableLocalCamera) };
MS2_FPCLI(FieldPropertyPhotoStudio) };

class FieldPropertyAmbientLightCli : public FieldPropertyAmbientLight {
public:
    virtual ~FieldPropertyAmbientLightCli();
    virtual void vfunc_4();
    virtual void vfunc_5();
    Unk_Vec3f m_vecOld = Unk_Vec3f(0, 0, 0);            // +0x20
    bool m_bCached;                                     // +0x2c
    float m_fCached;                                    // +0x30
};
MS2_CHECK_SIZE(FieldPropertyAmbientLightCli, 0x38);

class FieldPropertyDirectionalLightCli : public FieldPropertyDirectionalLight {
public:
    virtual ~FieldPropertyDirectionalLightCli();
    virtual void vfunc_4();
    virtual void vfunc_5();
    Unk_Vec3f m_vecOld = Unk_Vec3f(0, 0, 0);            // +0x28
    bool m_bCached;                                     // +0x34
    float m_fCached;                                    // +0x38
};
MS2_CHECK_SIZE(FieldPropertyDirectionalLightCli, 0x40);

MS2Ptr<FieldProperty> FUN_140b26ff0(int nType);          // factory: 1..11 = Gravity .. PhotoStudio
