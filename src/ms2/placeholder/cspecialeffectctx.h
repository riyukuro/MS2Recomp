// cspecialeffectctx.h - CSpecialEffectCtx (RTTI .?AVCSpecialEffectCtx@@, vftable 0x142d96868) and its subclass
// CSEReduceSkillGroupCooltimeCtx (vftable 0x142f62e40): the argument block of a special effect function
// (CSpecialEffectFunction::vfunc_1). NOT an original header (name assumed). Only the members used by
// specialeffectfunctionmanager.cpp are named; the ctors/dtors live in ?\specialeffectctx.cpp (0x140827420-0x140827540)
// and ?\skillslot.cpp (0x14176cc40, 0x14176cdb0).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cxmldata.h"

// The attribute bag the ctx points at (block of Table/ attributes). The int getter is the one in itemdatastruct.cpp
// (0x14054c530); the float getter is CXmlData::FUN_1408276a0 (specialeffectfunctionmanager.cpp). Both look the name up
// in the string map at +0x18.
class Unk_SEAttrMap
{
public:
    bool FUN_1403ef5f0(const wchar_t* szName, CStringW& strValue);      // 0x1403ef5f0 (map find)
    char m_unk;
};

class Unk_SEParam
{
public:
    int FUN_14054c530(const CStringW& strName, int* pnDefault);        // 0x14054c530

private:
    MS2_LAYOUT_FRIEND;
    char m_pad_00[0x18];
    Unk_SEAttrMap m_attrs;              // +0x18
};
MS2_CHECK_OFFSET(Unk_SEParam, m_attrs, 0x18);

// 16-byte smart pointer to Unk_SEParam (an MS2Ptr shape; its ctor/dtor are out of line in other units).
class Unk_SEParamPtr
{
public:
    Unk_SEParamPtr();                   // 0x1401822f0
    ~Unk_SEParamPtr();                  // 0x1401836d0
    Unk_SEParam* FUN_140194790() const; // 0x140194790: returns m_p
private:
    void* m_unk_00;
    Unk_SEParam* m_p;                   // +0x08
};
MS2_CHECK_SIZE(Unk_SEParamPtr, 0x10);

class CSpecialEffectCtx : public CPtred
{
public:
    CSpecialEffectCtx();                // 0x140827420
    CSpecialEffectCtx(int nKind);       // 0x140827490
    virtual ~CSpecialEffectCtx();       // 0x140827500

    // The function manager looks the effect function up by this id (+0x18) and hands it the ctx.
    int m_nKind;                        // +0x18
    Unk_SEParamPtr m_pParam;            // +0x20
    int m_n30;                          // +0x30

    // Attribute getters (names invented). The name is taken by value (the callee destroys it).
    // @0x140827740
    int GetInt(CStringW strName, int* pnDefault) { return m_pParam.FUN_140194790()->FUN_14054c530(strName, pnDefault); }
    // @0x1408277a0
    float GetFloat(CStringW strName, float* pfDefault) { return reinterpret_cast<CXmlData*>(m_pParam.FUN_140194790())->FUN_1408276a0(strName, pfDefault); }
};
MS2_CHECK_SIZE(CSpecialEffectCtx, 0x38);
MS2_CHECK_OFFSET(CSpecialEffectCtx, m_nKind, 0x18);
MS2_CHECK_OFFSET(CSpecialEffectCtx, m_pParam, 0x20);

class CSEReduceSkillGroupCooltimeCtx : public CSpecialEffectCtx
{
public:
    CSEReduceSkillGroupCooltimeCtx();   // 0x14176cc40
    virtual ~CSEReduceSkillGroupCooltimeCtx();   // 0x14176cdb0

    float m_fReduceRate;                // +0x38 accumulated reduce rate
    int m_nGroupId;                     // +0x3c skill group id
};
MS2_CHECK_SIZE(CSEReduceSkillGroupCooltimeCtx, 0x40);
MS2_CHECK_OFFSET(CSEReduceSkillGroupCooltimeCtx, m_nGroupId, 0x3c);
