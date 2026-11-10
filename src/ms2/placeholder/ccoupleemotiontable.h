// ccoupleemotiontable.h - CCoupleEmotionTable (RTTI .?AVCCoupleEmotionTable@@, 0x40 bytes) and its rows
// CCoupleEmotionData / CCoupleEmotionData::AnimationData. NOT an original header (the unit is
// commonfiles\coupleemotiontable.cpp, 0x1402c6c20-0x1402cb2a0). Loaded from Table/coupleEmotion.xml
// (<coupleEmotion id teleport_effect animationDiffGender_* animationSameGenderMale_* animationSameGenderFemale_*/>);
// member and method names are inferred from the xml attributes and the asserts. Created by CGameApp::InitInstance
// (?\ms2.cpp), read by the couple emotion client state.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <typeinfo>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

// One <coupleEmotion> row. RTTI CCoupleEmotionData, 0x58 bytes, base CPtred.
class CCoupleEmotionData : public CPtred
{
public:
    // The animations of one gender pairing. RTTI CCoupleEmotionData::AnimationData, 0x68 bytes, base CPtred; the ctor
    // (0x1402c8d00) and dtor (0x1402c8fe0) are implicit (Load value-initialises it).
    class AnimationData : public CPtred
    {
    public:
        bool m_bLoop;                           // +0x18 "<pair>_loop"
        std::vector<CString> m_requestAnis;     // +0x20 "<pair>_requestUser" ("animationDiffGender_female")
        std::vector<CString> m_targetAnis;      // +0x38 "<pair>_targetUser" ("animationDiffGender_male")
        std::vector<CString> m_nifPaths;        // +0x50 "<pair>_pathNif" (one per animation)
    };

    CCoupleEmotionData();                       // 0x1402c6c20
    virtual ~CCoupleEmotionData();              // 0x1402c6c90

    // Registers the animations of the gender pair (nGender1, nGender2) (0 male, 1 female; order free). 0x1402c6ce0
    bool AddAni(int nGender1, int nGender2, MS2Ptr<AnimationData> spAni);
    // The animations of the gender pair (null when the row has none). 0x1402c6d70
    MS2Ptr<AnimationData> GetAni(int nGender1, int nGender2);

    unsigned int m_nId;                         // +0x18 "id"
    CString m_strTeleportEffect;                // +0x20 "teleport_effect"
    ATL::CRBMap<unsigned int, MS2Ptr<AnimationData> > m_anis;   // +0x28 low gender | high gender << 16 -> animations
};
MS2_CHECK_SIZE(CCoupleEmotionData::AnimationData, 0x68);
MS2_CHECK_OFFSET(CCoupleEmotionData::AnimationData, m_requestAnis, 0x20);
MS2_CHECK_OFFSET(CCoupleEmotionData::AnimationData, m_nifPaths, 0x50);
MS2_CHECK_SIZE(CCoupleEmotionData, 0x58);
MS2_CHECK_OFFSET(CCoupleEmotionData, m_strTeleportEffect, 0x20);
MS2_CHECK_OFFSET(CCoupleEmotionData, m_anis, 0x28);

CString ToCString(const char* psz, int nCodePage);         // narrows a string (the RTTI name in CheckInit)

// Bases: TSingleton<CCoupleEmotionTable> at +0x0 (s_instance DAT_143aad158), CValidData<CCoupleEmotionTable> at +0x8.
class CCoupleEmotionTable : public TSingleton<CCoupleEmotionTable>, public CValidData<CCoupleEmotionTable>
{
public:
    CCoupleEmotionTable();                                  // 0x1402c6e60
    virtual ~CCoupleEmotionTable();                         // 0x1402c6ee0

    int Load();                                                         // 0x1402c6f50 Table/coupleEmotion.xml
    MS2Ptr<CCoupleEmotionData> GetData(unsigned int nId);                       // 0x1402c7e10 (null when missing)
    int Validate(MS2Ptr<CCoupleEmotionData> spData);                    // 0x1402c7ed0
    int ValidateAni(MS2Ptr<CCoupleEmotionData::AnimationData> spAni);   // 0x1402c8100 the three lists line up

    // @0x1402c9380
    static void CheckInit()
    {
        if (!s_bInit)
        {
            CStringA msg;
            msg.Format("%s is not initialized", (const char*)ToCString(typeid(CCoupleEmotionTable).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    // @0x1402cafa0
    static void SetInit(bool bInit) { s_bInit = bInit; }

    static bool s_bInit;                                    // DAT_143aad160

    ATL::CRBMap<unsigned int, MS2Ptr<CCoupleEmotionData> > m_data;   // +0x10 id -> row
};
MS2_CHECK_SIZE(CCoupleEmotionTable, 0x40);
MS2_CHECK_OFFSET(CCoupleEmotionTable, m_data, 0x10);
