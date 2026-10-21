// scriptcontent.h - the talk/cinematic script contents loaded from the NPC talk xml: CScriptContent (one spoken line),
// CChatballonContent, CCinematicContent (a cinematic talk page with choices) and its helpers CCinematicDistractor (the
// choices, RTTI name) and CCinematicEventScript (RTTI names). Header name assumed; member names are invented from use.
// Replaces the read-only view src/ms2/placeholder/cinematiccontent.h inside this unit (that placeholder keeps serving
// cinematiccomponent.cpp, which never includes this header).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cptred.h"

class Unk_ScriptXmlNode;    // game TinyXML element
class Unk_ScriptTalk;       // a loaded NPC talk script (CPtred based)

class Unk_ScriptRef { public: void FUN_14015b020(); int FUN_140159bc0(); void FUN_140159ba0(); };

// The 16-byte intrusive smart pointer (pointee at +8) of the content classes.
template<class T> class Unk_ScriptPtr {
public:
    Unk_ScriptPtr() : p(0) {}
    Unk_ScriptPtr(int) : p(0) {}
    Unk_ScriptPtr(T* value) : p(value) { AddRef(); }
    Unk_ScriptPtr(const Unk_ScriptPtr& o) : p(o.p) { AddRef(); }
    ~Unk_ScriptPtr() { Release(); }
    Unk_ScriptPtr& operator=(int) { Release(); return *this; }
    Unk_ScriptPtr& operator=(T* value) { Unk_ScriptPtr temp(value); T* old=p; p=temp.p; temp.p=old; return *this; }
    Unk_ScriptPtr& operator=(const Unk_ScriptPtr& o) { o.AddRef(); Release(); p = o.p; return *this; }
    bool operator==(T* o) const { return p == o; }
    T* get() const { return p; }
    T* operator->() const { return p; }
private:
    void AddRef() const { if(p) AddRefImpl(0); }
    static void AddRefObject(T* value) { reinterpret_cast<Unk_ScriptRef*>(value)->FUN_14015b020(); }
    void AddRefImpl(void*) const { AddRefObject(p); }
    void Release() { if(p) { ReleaseImpl(0); p=0; } }
    void ReleaseImpl(void*) { if(reinterpret_cast<Unk_ScriptRef*>(p)->FUN_140159bc0()==0) { AddRefObject(p); reinterpret_cast<Unk_ScriptRef*>(p)->FUN_140159ba0(); } }
    void* pad_00; T* p;
};

// One choice of a talk page (0x18): the shown text and the two jump targets.
struct Unk_ScriptChoice {
    CStringW m_text;                        // +0x00 "text"
    CStringA m_goto;                        // +0x08 "goto"
    CStringA m_gotoFail;                    // +0x10 "gotoFail"
};
MS2_CHECK_SIZE(Unk_ScriptChoice, 0x18);

class CScriptContent : public CPtred {
public:
    CScriptContent();                                       // 0x14078ced0
    virtual ~CScriptContent();                              // 0x14078cf40
    virtual int vfunc_1();                                  // content kind, -1 = none
    virtual int vfunc_2(Unk_ScriptXmlNode* pNode);         // load from xml
    // @0x1407906b0
    virtual void vfunc_3(int) {}
    // @0x1407906c0
    virtual void vfunc_4(int) {}
    virtual void vfunc_5(COutputStream& out);               // write
    virtual void vfunc_6(CByteBuffer& in);                  // read

    CStringW m_text;                        // +0x18 "text"
    CStringA m_voiceId;                     // +0x20 "voiceID"
    CStringA m_illust;                      // +0x28 "illust"
};
MS2_CHECK_SIZE(CScriptContent, 0x30);

class CChatballonContent : public CScriptContent {
public:
    CChatballonContent();                                   // 0x140859d20 (?\talkscript.cpp, holds the vftable)
    virtual ~CChatballonContent();                          // 0x14085a190
    virtual int vfunc_1();                                  // 0x14078d2a0
    virtual int vfunc_2(Unk_ScriptXmlNode* pNode);         // 0x14078d2c0
};

// The choices of a talk page (RTTI CCinematicDistractor, 0x38).
class CCinematicDistractor : public CPtred {
public:
    CCinematicDistractor();                                 // 0x14078d300
    virtual ~CCinematicDistractor();                        // 0x14078d350
    int FUN_14078d3d0() const;
    void FUN_14078d3a0() const;
    void WriteTo(COutputStream& out);                       // 0x14078d410
    void ReadFrom(CByteBuffer& in);                         // 0x14078d540

    ATL::CAtlArray<Unk_ScriptChoice> m_choices;             // +0x18
};
MS2_CHECK_SIZE(CCinematicDistractor, 0x38);

// An event of a talk page: a list of contents, one is picked at random (RTTI CCinematicEventScript, 0x40).
class CCinematicEventScript : public CPtred {
public:
    CCinematicEventScript();                                // 0x14078d720
    virtual ~CCinematicEventScript();                       // 0x14078d770
    int LoadXml(Unk_ScriptXmlNode* pNode);                 // 0x14078d7c0
    Unk_ScriptPtr<CScriptContent> GetRandomContent();       // 0x14078d910

    int m_nId;                              // +0x18 "id"
    int m_pad1c;
    ATL::CAtlArray<Unk_ScriptPtr<CScriptContent> > m_contents;  // +0x20
};
MS2_CHECK_SIZE(CCinematicEventScript, 0x40);

class CCinematicContent : public CScriptContent {
public:
    CCinematicContent();                                    // 0x14078d9c0
    CCinematicContent(CByteBuffer& in);                     // 0x14078db40
    virtual ~CCinematicContent();                           // 0x14078dd60
    virtual int vfunc_1();                                  // 0x14078e3a0
    virtual int vfunc_2(Unk_ScriptXmlNode* pNode);         // 0x14078de70
    virtual void vfunc_3(int nId);                          // 0x14078e3b0
    virtual void vfunc_4(int nId);                          // 0x14078e6f0
    virtual void vfunc_5(COutputStream& out);               // 0x14078ea30
    virtual void vfunc_6(CByteBuffer& in);                  // 0x14078ead0

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
    Unk_ScriptPtr<CCinematicDistractor> m_distractors;      // +0x98
    ATL::CAtlArray<Unk_ScriptPtr<CCinematicEventScript> > m_events;     // +0xa8
};
MS2_CHECK_OFFSET(CCinematicContent, m_movie, 0x40);
MS2_CHECK_OFFSET(CCinematicContent, m_redirect, 0x4c);
MS2_CHECK_OFFSET(CCinematicContent, m_imagePlate, 0x78);
MS2_CHECK_OFFSET(CCinematicContent, m_screenEffectValue, 0x90);
MS2_CHECK_OFFSET(CCinematicContent, m_distractors, 0x98);
MS2_CHECK_OFFSET(CCinematicContent, m_events, 0xa8);
MS2_CHECK_SIZE(CCinematicContent, 0xc8);
