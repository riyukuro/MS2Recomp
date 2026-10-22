// rideeinterpolator.h - RideeInterpolator (RTTI "RideeInterpolator" 0x143acce28, 0x58 bytes, NiTransformInterpolator): drives
// the seat node of a Ridee from the rider's body node every frame (Update), always updated. Created by Ridee (m_pDC0).
// Owning unit: ?\rideeinterpolator.cpp. Header name assumed from the unit path; member names are invented.
#pragma once
#include <NiTransformInterpolator.h>
#include "ms2/ms2layout.h"

class RideeInterpolator : public NiTransformInterpolator
{
    NiDeclareRTTI;                                              // GetRTTI 0x141020bc0
public:
    RideeInterpolator();                                        // 0x141020350
    RideeInterpolator(NiTransformData* pData);                  // 0x1410203a0
    virtual ~RideeInterpolator();                               // 0x141020400 (??_G 0x141020b60)
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);   // 0x141020430
    virtual bool AlwaysUpdate() const;                          // 0x141020a90

    void SetObjectId(int nObjectId);                          // the rider's object id

private:
    MS2_LAYOUT_FRIEND;
    int m_nObjectId;                                            // +0x50
    bool m_bAlwaysUpdate;                                       // +0x54
};
MS2_CHECK_SIZE(RideeInterpolator, 0x58);
MS2_CHECK_OFFSET(RideeInterpolator, m_nObjectId, 0x50);
