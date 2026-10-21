// talkscript.h - CTalkScript (RTTI .?AVCTalkScript@@, 0x90 bytes, bases CPtred and CValidData<CTalkScript>): one talk of
// an NPC or quest, loaded from Script/Npc and Script/Quest xml or read from a packet. NOT an original header; member
// names come from the xml attribute names (the loaders 0x140857f20 / 0x140858440). Typed over guess/scriptcontent.h; the
// read-only view src/ms2/placeholder/ctalkscript.h serves the talk UI units and is the same 0x90 layout.
#pragma once

// hk1 2026-10-20: storage class of talkscript.cpp's file statics that stand for exe globals (the `// 0x...` ones). The hook DLL
// declares them extern and progress/symbols-manual.tsv binds them to the exe objects, so hooked and exe code share them.
#ifdef MS2_HOOK_DLL
#define MS2_TALKSCRIPT_STATIC extern
#else
#define MS2_TALKSCRIPT_STATIC static
#endif
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/guess/scriptcontent.h"

class CInPacket;

// A second instance of the content pointer (own AddRef/AddRefImpl COMDATs in the exe, 0x14085f0f0).
template<class T> class Unk_TalkContentPtr {
public:
    Unk_TalkContentPtr() : p(0) {}
    Unk_TalkContentPtr(int) : p(0) {}
    Unk_TalkContentPtr(T* value) : p(value) { AddRef(); }
    Unk_TalkContentPtr(const Unk_TalkContentPtr& o) : p(o.p) { AddRef(); }
    ~Unk_TalkContentPtr() { Release(); }
    Unk_TalkContentPtr& operator=(int) { Release(); return *this; }
    Unk_TalkContentPtr& operator=(T* value) { Unk_TalkContentPtr temp(value); T* old=p; p=temp.p; temp.p=old; return *this; }
    Unk_TalkContentPtr& operator=(const Unk_TalkContentPtr& o) { o.AddRef(); Release(); p = o.p; return *this; }
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

class CTalkScript : public CPtred, public CValidData<CTalkScript>
{
public:
    CTalkScript();                                          // 0x140854ea0
    CTalkScript(CInPacket& in);                             // 0x140854fa0
    virtual ~CTalkScript();                                 // 0x140855050
    void Serialize(COutputStream* out);                     // 0x1408550e0
    void Deserialize(CInPacket& in);                        // 0x140855210
    bool Is88() const;                                      // 0x140855520

    int m_id;                                               // +0x20 "id"
    int m_npcId;                                            // +0x24
    int m_questId;                                          // +0x28
    int m_jobCondition;                                     // +0x2c "jobCondition"
    CStringW m_tag;                                         // +0x30 "tag"
    int m_popupState;                                       // +0x38
    int m_popupProp;                                        // +0x3c
    ATL::CAtlArray<int> m_gotoConditionTalkIds;             // +0x40 "gotoConditionTalkID"
    int m_randomPick;                                       // +0x60 "randomPick"
    int m_pad64;
    ATL::CAtlArray<Unk_TalkContentPtr<CScriptContent> > m_contents;  // +0x68
    bool m_88;                                              // +0x88 read from a packet
};
MS2_CHECK_OFFSET(CTalkScript, m_npcId, 0x24);
MS2_CHECK_OFFSET(CTalkScript, m_tag, 0x30);
MS2_CHECK_OFFSET(CTalkScript, m_gotoConditionTalkIds, 0x40);
MS2_CHECK_OFFSET(CTalkScript, m_contents, 0x68);
MS2_CHECK_SIZE(CTalkScript, 0x90);
