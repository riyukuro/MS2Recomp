// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). DamageCalculatorInfo and helpers (commonstruct.cpp#1 slice B).
// Field names come from the debug text in ToString (0x1402728f0); enum type names are invented.
#pragma once
#include <afx.h>
#include "ms2/commonfiles/commonstruct.h"
#include "ms2/placeholder/cptred.h"

enum Unk_CommonDamageType { Unk_CommonDamageType_None };
enum Unk_CommonElementType { Unk_CommonElementType_None };
enum Unk_CommonRangeType { Unk_CommonRangeType_None };
enum Unk_CommonJobCode { Unk_CommonJobCode_None };

// 4 zero bytes; the exe zeroes them with the small out-of-line FUN_14027d5c0 (nothrow: the ctor has no EH state).
struct Unk_CommonBytes4 { int raw; };
Unk_CommonBytes4* FUN_14027d5c0(Unk_CommonBytes4*) noexcept;

// fmt "{0}...{1}" StringFormat instances defined by the neighbouring slice (argument type in the signature).
CStringW FUN_140275280(const wchar_t*,const CStringW&,const unsigned short&);
CStringW FUN_140275590(const wchar_t*,const CStringW&,const int&);
CStringW FUN_1402758a0(const wchar_t*,const CStringW&,const unsigned&);
CStringW FUN_140275bb0(const wchar_t*,const CStringW&,const float&);
CStringW FUN_140275ec0(const wchar_t*,const CStringW&,const Unk_CommonJobCode&);
CStringW FUN_1402761d0(const wchar_t*,const CStringW&,const __int64&);
CStringW FUN_1402764e0(const wchar_t*,const CStringW&,const bool&);

class DamageCalculatorInfo : public CPtred {
public:
    DamageCalculatorInfo();
    virtual ~DamageCalculatorInfo() = default;
    void Write(COutputStream&);
    void Read(CByteBuffer&);
    CStringW ToString();
    void SaveToFile();
    Unk_CommonDamageType damageType;
    int hand;
    float damageRate;
    int m_pad_24;
    __int64 damageValue;
    bool isConstDamage;
    bool isLapenshard;
    bool isPvp;
    bool isUseGrade;
    bool isIgnoreLevelGap;
    char m_pad_35[1];   // an array: /GS treats a stack DamageCalculatorInfo as a GS buffer next to the cookie (scenestategame FUN_14173f860)
    short m_pad_36;
    int m_unk38;   // Unk_CommonBytes4, constructed in the ctor body
    float damageByTargetMaxHP;
    float saInvokeSkillDamage;
    float m_stanceDamageRate;
    __int64 wap;
    unsigned m_skillID;
    unsigned m_additionalID;
    Unk_CommonElementType m_element;
    Unk_CommonRangeType m_rangeType;
    unsigned short m_petLevel;
    short m_pad_62;
    Unk_CommonJobCode casterJobCode;
    int casterPen;
    int casterAtp;
    int casterDex;
    int casterAsp;
    int casterCap;
    int casterCad;
    int casterPap;
    int casterMap;
    int casterLuk;
    float casterDamageR;
    int casterCapIgnoreLimit;
    int casterCapIgnoreLimitExtra;
    int casterCadIgnoreLimit;
    int casterBap;
    float casterTarPen;
    float casterFieldRestrainRate;
    float casterJobSkillWapR;
    float casterJobSkillTapR;
    int casterJobSkillPen;
    int casterJobSkillAsp;
    float casterJobSkillImproveDamage;
    float casterJobSkillFinalOffensive;
    float casterImproveTotalWapR;
    float casterImproveTotalTapR;
    int casterPvpInc;
    float casterScaleRate;
    int casterScaleDef;
    float casterSARateRange;
    float casterSARateElement;
    float casterSARateImproveDamageFinal;
    float casterSARateNpcRank;
    float casterSARateDarkStream;
    __int64 casterCheatV_WAP_D;
    __int64 casterPointV_WAP_D;
    __int64 casterSaV_WAP_D;
    __int64 casterCheatV_WAP_U;
    __int64 casterPointV_WAP_U;
    __int64 casterSaV_WAP_U;
    float casterImproveRate_WAP_D;
    float casterImproveRate_WAP_U;
    int targetNdd;
    int targetEvp;
    int targetLuk;
    int targetAbp;
    int targetPar;
    int targetMar;
    int targetCar;
    int targetAbsoluteEvp;
    int targetDamageV;
    float targetDamageR;
    float targetResWap;
    float targetResCad;
    float targetResAtp;
    float targetResEvp;
    float targetResPen;
    float targetScaleRate;
    __int64 targetScaleTap;
    float targetScaleSpaRate;
    int m_pad_16c;
    __int64 DamageResult;
};
MS2_CHECK_SIZE(DamageCalculatorInfo,0x178);
MS2_CHECK_OFFSET(DamageCalculatorInfo,m_unk38,0x38);
MS2_CHECK_OFFSET(DamageCalculatorInfo,casterJobCode,0x64);
MS2_CHECK_OFFSET(DamageCalculatorInfo,DamageResult,0x170);
