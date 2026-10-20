// afterimageeffectparam.h - the "AfterImage" effect (effect XML type 0x16): a trail of fading copies of the owner. Param
// (CEffectParam) only; the runtime CAfterImageEffect (0x98 bytes) lives in another unit. Owning unit: unit_140987430
// (0x140987430-0x140987b20). Header name assumed from the RTTI name.
#pragma once
#include "ms2/client/ms2/effectparam.h"
#include <NiColor.h>

// 16-byte RGBA float colour = Gamebryo's NiColorA: its inline ctors are the exe's NiColorA() 0x14097f220 and
// NiColorA(float x4) 0x14097f1d0 (both forward to efd::ColorA(float x4) 0x14097f050), NiColorA(const efd::ColorA&)
// 0x140987930 (rep movsb).
typedef NiColorA Unk_AfterImageColor;
MS2_CHECK_SIZE(Unk_AfterImageColor, 0x10);

// Handle passed to the CAfterImageEffect constructor (0x140987900 stores the param at +8 and runs 0x140981190).
class Unk_AfterImageRef
{
public:
    Unk_AfterImageRef();                                       // 0x14097eec0
    Unk_AfterImageRef(class CAfterImageEffectParam* pParam);   // 0x140987900
    Unk_AfterImageRef(const Unk_AfterImageRef& kOther);       // 0x14097ee80, non-trivial: passed by address
    ~Unk_AfterImageRef();                                      // 0x14097f560
    Unk_AfterImageRef& operator=(const Unk_AfterImageRef& kOther);   // 0x14097fa60
    class CAfterImageEffectParam* operator->() const;          // 0x14097fc80
    bool operator==(class CAfterImageEffectParam* p) const { return m_pParam == p; }   // @0x14097fb40
    void FUN_140981190();                                      // add a reference (if set)
    void FUN_140981230(void*);                                 // add a reference
    static void FUN_1409811e0(class CAfterImageEffectParam* p);   // CPtred::AddRefPtred
    void FUN_140981680();                                      // drop the reference (if set), clear
    void FUN_140981730(void*);                                 // drop the reference, delete at zero
    void* m_unk_00;
    class CAfterImageEffectParam* m_pParam;
};

class CAfterImageEffect;   // 0x98 bytes, defined in afterimageitem.h

// 0x70 bytes. vftable (see ctor) (overrides slots 1 and 6). Implicit virtual dtor 0x1409874f0, ??_G 0x140987990.
class CAfterImageEffectParam : public CEffectParam
{
public:
    CAfterImageEffectParam();                                   // 0x140987430
    virtual ~CAfterImageEffectParam();                          // 0x1409874f0, ??_G 0x140987990
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x140987520
    virtual CEffectPtr vfunc_6();                               // 6 0x140987740 new CAfterImageEffect

    const Unk_AfterImageColor* GetColor() const;   // 0x140987810
    int GetImageSize() const;           // 0x140987830
    unsigned GetTimeInterval() const;     // 0x140987850 (ms)
    unsigned GetTimeLife() const;             // 0x140987870 (ms)
    float GetMoveInterval() const;   // 0x140987890
    bool GetLightenMode() const;      // 0x1409878b0
public:
    int m_nImageSize;               // +0x48 "imageSize" (0x100)
    bool m_bLightenMode;            // +0x4c "lightenMode" (true)
    Unk_AfterImageColor m_kColor;   // +0x50 "color" (white)
    unsigned m_nTimeInterval;           // +0x60 "timeInterval" seconds * 1000 (250 default)
    float m_fMoveInterval;          // +0x64 "moveInterval" (100.0)
    unsigned m_nTimeLife;               // +0x68 "timeLife" seconds * 1000 (1000)
};
MS2_CHECK_OFFSET(CAfterImageEffectParam, m_nImageSize, 0x48);
MS2_CHECK_OFFSET(CAfterImageEffectParam, m_kColor, 0x50);
MS2_CHECK_OFFSET(CAfterImageEffectParam, m_nTimeLife, 0x68);
