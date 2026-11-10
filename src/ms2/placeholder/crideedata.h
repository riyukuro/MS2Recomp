// crideedata.h - CRideeData, one row of the riding table (Data/Xml/Riding/%08d.xml), its sections (RideeData::Basic,
// Collision, Shadow, FaceCamera, Stat, Passengers) and the seat record RideeData::Rider. PLACEHOLDER, NOT an original
// header: the class bodies come from unit_140781d80_ridingtable.cpp, which defines their members.
#pragma once

#include <afx.h>
#include <map>
#include <vector>
#include <efd/Point3.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/client/ms2/effectdummy.h"

class TiXmlElement;

// Common base of the riding table sections: one pure virtual (vftable 0x142d8a8d8).
class IDataCheck
{
public:
    virtual int vfunc_0() = 0;
};

namespace RideeData
{
    // One <passenger> seat of a riding row (a TPtredDummy<Rider> box shared by the table and the actors).
    struct Rider
    {
        Rider();                                            // 0x140781d80
        bool FUN_140781ef0(const Rider& o);                 // differs
        void FUN_140782110(TiXmlElement* pNode);           // load one seat

        int m_nPassengerId;                                 // +0x00 "passengerid"
        CString m_strRideBone;                              // +0x08 "rideBone"
        efd::Point3 m_vTranslation;                         // +0x10 "rideTranslation"
        efd::Point3 m_vRotation;                            // +0x1c "rideRotation"
        CString m_strAniPC;                                 // +0x28 "rideAniPC"
        CString m_strAniPCIdle;                             // +0x30
        CString m_strAniPCRun;                              // +0x38
        CString m_strAniPCJump;                             // +0x40
        CString m_strAniPCSPIdle;                           // +0x48
        CString m_strAniPCSPRun;                            // +0x50
        CString m_strAniPCSPJump;                           // +0x58
        float m_fNameTagOffsetY;                            // +0x60
        float m_fHpBarOffsetY;                              // +0x64
        int m_nNameTagHide;                                 // +0x68
        int m_nUseRidingNavi;                               // +0x6c
    };
    MS2_CHECK_SIZE(Rider, 0x70);
}

typedef TPtredDummy<RideeData::Rider> Unk_RiderBox;
MS2_CHECK_SIZE(Unk_RiderBox, 0x88);
template<> struct Unk_SocketRef<RideeData::Rider> {
    static CPtred* Base(RideeData::Rider* p)
    {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, Unk_RiderBox, value);
        return result;
    }
    static Unk_RiderBox* New(void*) { return new Unk_RiderBox(); }
    static RideeData::Rider* Value(CPtred* p)
    {
        RideeData::Rider* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<Unk_RiderBox*>(p)->value;
        return result;
    }
    static RideeData::Rider* Create(void*) { return Value(InitRefCount(New(NULL))); }
};
MS2_SOCKETPTR_BOXED(RideeData::Rider)
typedef Unk_SocketPtr<RideeData::Rider> Unk_RiderPtr;

namespace RideeData
{
    // <basic>: the model, speeds and effects of the mount. 0xd8 bytes, vftable 0x142d8a8e8.
    class Basic : public IDataCheck
    {
    public:
        Basic();                                            // 0x140782860
        virtual int vfunc_0();                             // 0x140782f90
        bool FUN_140782b10(const Basic& o);                 // differs
        int FUN_140782fb0(TiXmlElement* pRoot);            // load <basic> (+ the default seat)

        int m_nId;                                          // +0x08 "id"
        int m_nParentId;                                    // +0x0c "pID"
        int m_nType;                                        // +0x10 "type" (default / battle / object)
        CString m_strKfm;                                   // +0x18 "kfm"
        CString m_strKfm2;                                  // +0x20 "kfm2"
        CString m_strNif;                                   // +0x28 "nif"
        float m_fScale;                                     // +0x30 "scale"
        int m_nHideRider;                                   // +0x34
        int m_nBattleLife;                                  // +0x38
        int m_nEnableRideOffUI;                             // +0x3c
        int m_nUseRidingUI;                                 // +0x40
        int m_nHidePCInfo;                                  // +0x44
        int m_nSkillSetId;                                  // +0x48
        float m_fSummonCastTime;                            // +0x4c "rideSummonCastTime" (ms)
        float m_fWalkSpeed;                                 // +0x50
        float m_fRunSpeed;                                  // +0x54
        float m_fRunXSpeed;                                 // +0x58
        float m_fSwimSpeed;                                 // +0x5c
        int m_nEnableSwim;                                  // +0x60
        int m_pad64;                                        // +0x64
        CString m_strIdleXMotion;                           // +0x68
        CString m_strRunXMotion;                            // +0x70
        __int64 m_nRunXConsumeEp;                           // +0x78
        int m_nFallDamageDown;                              // +0x80
        int m_nShowRideeNameTag;                            // +0x84
        int m_nDisablePickUp;                               // +0x88
        int m_nDisableHideOnBush;                           // +0x8c
        CString m_strPressXEffectIdle;                      // +0x90
        CString m_strPressXEffectRun;                       // +0x98
        CString m_strA0;                                    // +0xa0
        CString m_strPressXEffectIdleNonstop;               // +0xa8
        CString m_strPressXEffectRunNonstop;                // +0xb0
        CString m_strLoopEffect;                            // +0xb8
        CString m_strRideOffBySkillEffect;                  // +0xc0
        Unk_RiderPtr m_spRider;                             // +0xc8 the default seat
    };
    MS2_CHECK_SIZE(Basic, 0xd8);

    // <collision>: the PhysX box. vftable 0x142d8a8f8.
    class Collision : public IDataCheck
    {
    public:
        int FUN_1407836c0(TiXmlElement*);                                       // always 1 (name invented)
        Collision();                                        // 0x1407836e0
        virtual int vfunc_0();                             // 0x1407837e0
        bool FUN_140783760(const Collision& o);             // differs
        int FUN_140783800(TiXmlElement* pRoot);            // load <collision>

        float m_fWidth;                                     // +0x08
        float m_fHeight;                                    // +0x0c
        float m_fDepth;                                     // +0x10
        bool m_bPhysic;                                     // +0x14
    };
    MS2_CHECK_SIZE(Collision, 0x18);

    // <shadow>. vftable 0x142d8a908.
    class Shadow : public IDataCheck
    {
    public:
        int FUN_1407838c0(TiXmlElement*);                                       // always 1 (name invented)
        Shadow();                                           // 0x1407838e0
        virtual int vfunc_0();                             // 0x140783960
        bool FUN_140783930(const Shadow& o);                // differs
        int FUN_140783980(TiXmlElement* pRoot);            // load <shadow>

        float m_fScale;                                     // +0x08
    };
    MS2_CHECK_SIZE(Shadow, 0x10);

    // <faceCamera>. vftable 0x142d8a918.
    class FaceCamera : public IDataCheck
    {
    public:
        int FUN_1407839e0(TiXmlElement*);                                       // always 1 (name invented)
        FaceCamera();                                       // 0x140783a00
        virtual int vfunc_0();                             // 0x140783ae0
        bool FUN_140783a70(const FaceCamera& o);            // differs
        int FUN_140783b00(TiXmlElement* pRoot);            // load <faceCamera>

        efd::Point3 m_vLookAtPosition;                      // +0x08
        efd::Point3 m_vCameraPosition;                      // +0x14
    };
    MS2_CHECK_SIZE(FaceCamera, 0x20);

    // The 35 stat values of a mount. vftable 0x142d8a928.
    class Stat : public IDataCheck
    {
    public:
        int FUN_140783d70(TiXmlElement*);                                       // always 1 (name invented)
        Stat();                                             // 0x140783d90
        virtual int vfunc_0();                             // 0x140783e40
        bool FUN_140783de0(const Stat& o);                  // differs
        int FUN_140783e60(TiXmlElement* pRoot);            // load <stat>

        __int64 m_values[0x23];                             // +0x08
    };
    MS2_CHECK_SIZE(Stat, 0x120);

    // The <passengers> seats by passenger id. vftable 0x142d8a938.
    class Passengers : public IDataCheck
    {
    public:
        int FUN_140783f30(TiXmlElement*);                                       // always 1 (name invented)
        Passengers();                                       // 0x140783f50
        virtual int vfunc_0();                             // 0x140783ff0
        bool FUN_140783fb0(const Passengers& o);            // differs
        int FUN_140784010(TiXmlElement* pRoot);            // load <passengers>
        int FUN_140784120(TiXmlElement*);                         // always 1 (name invented)
        int FUN_140784140();                               // there are seats
        size_t FUN_140784180();                             // seat count
        Unk_RiderPtr FUN_1407841b0(int nIndex);             // seat nIndex (null when out of range)

        std::map<int, Unk_RiderPtr> m_seats;                // +0x08
    };
    MS2_CHECK_SIZE(Passengers, 0x18);
}

// One riding row. 0x298 bytes, CCacheData-derived; vftable 0x142d8a948.
class CRideeData : public CCacheData
{
public:
    CRideeData();                                           // 0x140784250
    virtual ~CRideeData();                                  // 0x140784320

    bool IsDifferent(const CRideeData& o);                // differs
    CString GetKfmName(int nLevel);                      // animation (kfm) name for the rider's level
    CString GetNifName(int nLevel);                      // scene graph (nif) name (nLevel unused)
    Unk_RiderPtr GetDefaultRider();                           // the default seat
    Unk_RiderPtr GetPassenger(int nIndex);                 // seat nIndex of the passengers

    RideeData::Basic m_basic;                               // +0x28
    RideeData::Collision m_collision;                       // +0x100
    RideeData::Shadow m_shadow;                             // +0x118
    RideeData::Stat m_stat;                                 // +0x128
    RideeData::FaceCamera m_faceCamera;                     // +0x248
    RideeData::Passengers m_passengers;                     // +0x268
    std::vector<CEffectDummy> m_effectDummies;              // +0x280
};
MS2_CHECK_SIZE(CRideeData, 0x298);
MS2_CHECK_OFFSET(CRideeData, m_collision, 0x100);
MS2_CHECK_OFFSET(CRideeData, m_stat, 0x128);
MS2_CHECK_OFFSET(CRideeData, m_passengers, 0x268);
MS2_CHECK_OFFSET(CRideeData, m_effectDummies, 0x280);

typedef MS2SvrPtr<CRideeData> CRideeDataPtr;
CRideeDataPtr GetRideeData(unsigned nId);                  // the riding row of an id (unit_140781d80)
