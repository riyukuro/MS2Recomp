// morphinganimation.h - CMorphingAnimation (RTTI .?AVCMorphingAnimation@@) and the data it plays, CMorphingAnimationData
// (RTTI .?AVCMorphingAnimationData@@, 0x68 bytes; unit 0x141851ba0-0x141851fd0 in client\ms2\morphinganimationdata.cpp). A morph
// animation steps a table of frame durations over time and, per frame, pushes one weight into the NiInterpController
// found on a named node of the owner's model. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\morphinganimation.cpp` (0x141487a20-0x141487ed0, dir client\ms2). Member names are invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "timebasedanimation.h"
#include <atlcoll.h>
#include <atlstr.h>

class TiXmlElement;                                    // game TinyXML element

// 0x68 bytes, vftable 0x142f84808 (only the deleting dtor), ctor 0x141851ba0, dtor 0x141851f00.
class CMorphingAnimationData : public CPtred
{
public:
    CMorphingAnimationData();                           // 0x141851ba0
    virtual ~CMorphingAnimationData() = default;        // 0x141851f00, ??_G 0x141851f50

    // Index of the frame that time nTime (ms) falls in: walks m_frameTimes, wrapping into the loop from m_nLoopStart.
    int FUN_141851c20(int nTime);                       // 0x141851c20
    void FUN_141851db0(TiXmlElement* pElem);           // 0x141851db0 reads <target>/<weight> elements

    CString m_strNodeName;                              // +0x18 name of the model node that carries the morph controller
    ATL::CAtlArray<int> m_frameTimes;                   // +0x20 duration of every frame
    int m_nLoopStart;                                   // +0x40 first frame of the loop (-1: no loop)
    ATL::CAtlArray<float> m_weights;                    // +0x48 weight of every frame
};
MS2_CHECK_SIZE(CMorphingAnimationData, 0x68);
MS2_CHECK_OFFSET(CMorphingAnimationData, m_frameTimes, 0x20);
MS2_CHECK_OFFSET(CMorphingAnimationData, m_nLoopStart, 0x40);
MS2_CHECK_OFFSET(CMorphingAnimationData, m_weights, 0x48);

class NiAVObject;

// 0x30 bytes, vftable 0x142f199a0 (5 slots), deleting dtor 0x141487e50.
class CMorphingAnimation : public CTimeBasedAnimation
{
public:
    CMorphingAnimation(Unk_MorphOwner* pOwner, CMorphingAnimationData* pData);   // 0x141487a20
    virtual ~CMorphingAnimation();                      // 0x141487a90

    virtual void vfunc_1();                             // 0x141487ac0: show the first frame
    virtual void vfunc_2();                             // 0x141487ae0: reset the weight to 0 and stop
    virtual bool vfunc_3(int nTime);                    // 0x141487b20
    virtual int vfunc_4();                             // 0x141487bc0

    void SetFrame(size_t nFrame);                  // push the weight of frame nFrame
    void SetWeight(float fWeight);                  // push fWeight into every interpolator of the morph controller
    NiAVObject* FindNode(const CString& strNodeName);   // find the render object of the owner's model by name

    CMorphingAnimationData* m_pData;                    // +0x20
    int m_nFrame;                                       // +0x28 current frame (0x7fffffff: none yet)
    bool m_bRunning;                                    // +0x2c
};
MS2_CHECK_SIZE(CMorphingAnimation, 0x30);
MS2_CHECK_OFFSET(CMorphingAnimation, m_pData, 0x20);
MS2_CHECK_OFFSET(CMorphingAnimation, m_nFrame, 0x28);
MS2_CHECK_OFFSET(CMorphingAnimation, m_bRunning, 0x2c);
