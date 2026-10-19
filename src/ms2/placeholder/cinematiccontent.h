// cinematiccontent.h - PLACEHOLDER for CCinematicContent (RTTI .?AVCCinematicContent@@, base CScriptContent : CPtred,
// vftable 0x142d8aeb0, loader in ?\scriptcontent.cpp, not yet recovered). NOT an original header. Only the fields
// the cinematic components read are named; all of them are read-only here. Never constructed by recovered code.
// CScriptContent (vftable 0x142d8ae50, 0x30 bytes): +0x18 CStringW, +0x20 CStringA, +0x28 CStringA.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

// The distractor texts of the talk script: pointee of the 16-byte handle at CCinematicContent+0x98
// (ctor 0x14078edb0 stores [+8] = 0). The texts are in an array at +0x18 of the pointee.
struct CCinematicDistractor
{
    CStringW m_text;                        // +0x00 shown text
    CStringA m_script;                      // +0x08 (only its length is read)
};

class CCinematicDistractorArray
{
public:
    size_t FUN_14078fad0() const;               // GetCount
    CCinematicDistractor& FUN_14078f310(size_t i);   // checked GetAt
private:
    void* m_data; size_t m_count; size_t m_max; size_t m_grow;
};
MS2_CHECK_SIZE(CCinematicDistractorArray, 0x20);

class CCinematicDistractorTexts : public CPtred
{
public:
    CCinematicDistractorArray m_texts;      // +0x18
};

class CCinematicDistractorHandle
{
public:
    CCinematicDistractorTexts* FUN_14078f390() const;   // get
    CCinematicDistractorTexts* FUN_14078f3b0() const;   // operator->
private:
    void* m_0;
    CCinematicDistractorTexts* m_p;         // +0x08
};
MS2_CHECK_SIZE(CCinematicDistractorHandle, 0x10);

class CScriptContent : public CPtred
{
public:
    virtual ~CScriptContent();
    virtual int vfunc_1();                  // content type (0 = CCinematicContent)
    CStringW m_name;                        // +0x18
    CStringA m_unk20;                       // +0x20
    CStringA m_unk28;                       // +0x28
};
MS2_CHECK_SIZE(CScriptContent, 0x30);

class CCinematicContent : public CScriptContent
{
public:
    virtual ~CCinematicContent();
    int m_buttonSet;                        // +0x30
    int m_questId;                          // +0x34
    int m_openTalkReward;                   // +0x38
    int m_pad3c;
    CStringA m_movie;                       // +0x40
    int m_functionId;                       // +0x48
    int m_redirect;                         // +0x4c
    int m_otherNpcTalk;                     // +0x50
    int m_myTalk;                           // +0x54
    CStringA m_leftIllust;                  // +0x58
    CStringA m_rightIllust;                 // +0x60
    CStringA m_speakerIllust;               // +0x68
    int m_speakerNpc;                       // +0x70
    int m_pad74;
    CStringA m_imagePlate;                  // +0x78
    CStringA m_screenEffectMovie;           // +0x80
    CStringA m_screenEffectAction;          // +0x88
    unsigned m_screenEffectValue;           // +0x90
    int m_pad94;
    CCinematicDistractorHandle m_distractors;   // +0x98
    void* m_events0; void* m_events8; void* m_events10; void* m_events18;   // +0xa8 CAtlArray (0x20)
};
MS2_CHECK_OFFSET(CCinematicContent, m_questId, 0x34);
MS2_CHECK_OFFSET(CCinematicContent, m_movie, 0x40);
MS2_CHECK_OFFSET(CCinematicContent, m_redirect, 0x4c);
MS2_CHECK_OFFSET(CCinematicContent, m_speakerNpc, 0x70);
MS2_CHECK_OFFSET(CCinematicContent, m_screenEffectMovie, 0x80);
MS2_CHECK_OFFSET(CCinematicContent, m_screenEffectValue, 0x90);
MS2_CHECK_OFFSET(CCinematicContent, m_distractors, 0x98);
MS2_CHECK_SIZE(CCinematicContent, 0xc8);
