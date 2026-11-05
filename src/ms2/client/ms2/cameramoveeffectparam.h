// cameramoveeffectparam.h - the "CameraMove" effect (effect XML type 0x11): plays a camera path file through the
// camera manager. Param (CEffectParam) + runtime effect (CEffect). Owning unit: ?\cameramoveeffectparam.cpp
// (0x140afe800-0x140afef30). Header name assumed from the unit path.
#pragma once
#include "ms2/client/ms2/effectparam.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/bitset.h"

// commonfiles\bitset.inl bitset<3> (bitset.h). The ctor/Fill/Trim COMDATs were emitted in this unit
// (0x140afed60/0x140afee90/0x140afeef0); Set is the copy in commonfiles\dungeonmatch.cpp (0x140314670).
typedef Unk_Bitset<3> Unk_CamMoveBits;
MS2_CHECK_SIZE(Unk_CamMoveBits, 1);

// 0x88 bytes. vftable 0x142dd6d98 (8 slots; overrides 1, 6, 7). Implicit virtual dtor 0x140afed80, ??_G 0x140afee30.
class CCameraMoveEffectParam : public CEffectParam
{
public:
    CCameraMoveEffectParam();                                   // 0x140afe800
    virtual void vfunc_1(TiXmlElement* pNode);                 // 1 0x140afe8f0
    virtual CEffectPtr vfunc_6();                               // 6 0x140afeaf0 new CCameraMoveEffect
    virtual bool vfunc_7(Unk_EffectTarget* p);                  // 7 0x140afeb90 also skip for target kind 3
public:
    CString m_strFilePath;          // +0x48 "filePath"
    CString m_str50;                // +0x50
    Vector3 m_kTranslate;   // +0x58 transform "translate"
    Vector3 m_kRotation;    // +0x64 transform "rotation"
    bool m_bAttachToNode;           // +0x70 attachInfo "attachToNode" = true
    bool m_bApplyNodeTransform;     // +0x71 attachInfo "applyNodeTransform"
    CString m_strParentNode;        // +0x78 attachInfo "parentNode"
    Unk_CamMoveBits m_update;       // +0x80 bit 0 update translate, bit 1 update rotation
};
MS2_CHECK_OFFSET(CCameraMoveEffectParam, m_strFilePath, 0x48);
MS2_CHECK_OFFSET(CCameraMoveEffectParam, m_kTranslate, 0x58);
MS2_CHECK_OFFSET(CCameraMoveEffectParam, m_bAttachToNode, 0x70);
MS2_CHECK_OFFSET(CCameraMoveEffectParam, m_strParentNode, 0x78);
MS2_CHECK_OFFSET(CCameraMoveEffectParam, m_update, 0x80);

// 0x30 bytes (CEffect, no members). vftable 0x142dd6de0 (13 slots). ??_G 0x140afedd0.
class CCameraMoveEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x140afee80; ms_RTTI 0x143ab9c60
public:
    CCameraMoveEffect();                                        // 0x140afebe0
    virtual ~CCameraMoveEffect();                               // 0x140afec20
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x140afec50 start the path
    virtual void vfunc_7();                                     // 7  0x140afed50 {}
    virtual bool vfunc_9();                                     // 9  0x140afece0 still running
    virtual int vfunc_12();                                     // 12 0x140afee70 return 0x11
};
MS2_CHECK_SIZE(CCameraMoveEffect, 0x30);
