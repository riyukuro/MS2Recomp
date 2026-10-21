// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The talk script contents (spoken lines, cinematic talk pages
// with choices and random events) and the smart pointer / array instances they need.
// MS2-UNIT: ?\scriptcontent.cpp
// MS2-RANGE: 0x14078ced0-0x140790bd0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\scriptcontent.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scriptcontent.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----

int FUN_140873420(Unk_ScriptXmlNode* pNode, const char* pszName, CStringW& rOut);   // xml attribute -> wide string
int FUN_1408733e0(Unk_ScriptXmlNode* pNode, const char* pszName, CStringA& rOut);   // xml attribute -> string
int FUN_1408731e0(Unk_ScriptXmlNode* pNode, const char* pszName, int& rOut);
int FUN_140873220(Unk_ScriptXmlNode* pNode, const char* pszName, int& rOut);
int FUN_140873220(Unk_ScriptXmlNode* pNode, const char* pszName, unsigned& rOut);
int FUN_140873710(Unk_ScriptXmlNode* pNode, const char* pszName, int* pOut);
int FUN_140873890(Unk_ScriptXmlNode* pNode, const char* pszName, int& rOut);
const char* FUN_14086f4b0(Unk_ScriptXmlNode* pNode, const char* pszName);           // attribute text (null = absent)
Unk_ScriptXmlNode* FUN_140165cf0(Unk_ScriptXmlNode* pNode, const char* pszName);    // first child
Unk_ScriptXmlNode* FUN_140168650(Unk_ScriptXmlNode* pNode, const char* pszName);    // next sibling
class Unk_ScriptTextFilter { public: void FUN_1416fb380(CStringW& strText); };
Unk_ScriptTextFilter* FUN_1403b4750();
int FUN_140768010(unsigned nRange, unsigned nBase);                                 // random in base..base+range-1
void FUN_140177de0(CStringA& str, ATL::CAtlArray<int>& rOut, const char* pszSep);   // split into ints
size_t FUN_140186260(ATL::CAtlArray<int>& arr);                                     // GetCount
int* FUN_1401844d0(ATL::CAtlArray<int>& arr, size_t i);                             // GetAt
Unk_ScriptPtr<Unk_ScriptTalk> FUN_140856820(int nNpcId, int nKind);                 // talk script by npc
Unk_ScriptPtr<Unk_ScriptTalk> FUN_1408564b0(int nQuestId, int nKind);               // talk script by quest

// @0x14078ced0
CScriptContent::CScriptContent()
{
}

// @0x14078cf40
CScriptContent::~CScriptContent()
{
}

// @0x14078cfb0
int CScriptContent::vfunc_1()
{
    return -1;
}
MS2_REPLACE_METHOD(0x14078CFB0, CScriptContent, vfunc_1, 11, 0xC99FA0C7);

// @0x14078cfd0
int CScriptContent::vfunc_2(Unk_ScriptXmlNode* pNode)
{
    if (pNode == 0)
        return 0;
    FUN_140873420(pNode, "text", m_text);
    FUN_1408733e0(pNode, "voiceID", m_voiceId);
    FUN_1408733e0(pNode, "illust", m_illust);
    FUN_1403b4750()->FUN_1416fb380(m_text);
    return 1;
}
MS2_REPLACE_METHOD(0x14078CFD0, CScriptContent, vfunc_2, 158, 0x04708005);

// @0x14078d080
void CScriptContent::vfunc_5(COutputStream& out)
{
    out.vfunc_o10_1((unsigned char)vfunc_1());
    out.vfunc_o10_8(m_text);
    out.vfunc_o10_6(m_voiceId);
    out.vfunc_o10_6(m_illust);
}
MS2_REPLACE_METHOD(0x14078D080, CScriptContent, vfunc_5, 178, 0xB1980750);

// @0x14078d140
void CScriptContent::vfunc_6(CByteBuffer& in)
{
    m_text = in.vfunc_o8_8();
    m_voiceId = in.vfunc_o8_6();
    m_illust = in.vfunc_o8_6();
}
MS2_REPLACE_METHOD(0x14078D140, CScriptContent, vfunc_6, 331, 0xB81062FF);

// @0x14078d2a0
int CChatballonContent::vfunc_1()
{
    return 1;
}
MS2_REPLACE_METHOD(0x14078D2A0, CChatballonContent, vfunc_1, 11, 0x30025ED0);

// @0x14078d2c0
int CChatballonContent::vfunc_2(Unk_ScriptXmlNode* pNode)
{
    if (!CScriptContent::vfunc_2(pNode))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x14078D2C0, CChatballonContent, vfunc_2, 47, 0xD3C1D143);

// @0x14078d300
CCinematicDistractor::CCinematicDistractor()
{
}

// @0x14078d350
CCinematicDistractor::~CCinematicDistractor()
{
    m_choices.RemoveAll();
}

// @0x14078d3a0
void CCinematicDistractor::FUN_14078d3a0() const
{
    m_choices.GetCount();
}
MS2_REPLACE_METHOD(0x14078D3A0, CCinematicDistractor, FUN_14078d3a0, 31, 0x99CA2EA9);

// @0x14078d3d0
int CCinematicDistractor::FUN_14078d3d0() const
{
    return m_choices.GetCount() > 0;
}
MS2_REPLACE_METHOD(0x14078D3D0, CCinematicDistractor, FUN_14078d3d0, 58, 0xA3132CDC);

// @0x14078d410
void CCinematicDistractor::WriteTo(COutputStream& out)
{
    out.vfunc_o10_1((unsigned char)m_choices.GetCount());
    for (size_t i = 0; i < m_choices.GetCount(); i++) {
        out.vfunc_o10_8(m_choices.GetAt(i).m_text);
        out.vfunc_o10_6(m_choices.GetAt(i).m_goto);
        out.vfunc_o10_6(m_choices.GetAt(i).m_gotoFail);
    }
}
MS2_REPLACE_METHOD(0x14078D410, CCinematicDistractor, WriteTo, 283, 0x6555DB89);

// @0x14078d540
void CCinematicDistractor::ReadFrom(CByteBuffer& in)
{
    unsigned char nCount = in.vfunc_o8_1();
    for (unsigned char i = 0; i < nCount; i++) {
        Unk_ScriptChoice choice;
        choice.m_text = in.vfunc_o8_8();
        choice.m_goto = in.vfunc_o8_6();
        choice.m_gotoFail = in.vfunc_o8_6();
        m_choices.Add(choice);
    }
}
MS2_REPLACE_METHOD(0x14078D540, CCinematicDistractor, ReadFrom, 463, 0x598C4BDA);

// @0x14078d720
CCinematicEventScript::CCinematicEventScript()
{
}

// @0x14078d770
CCinematicEventScript::~CCinematicEventScript()
{
    m_contents.RemoveAll();
}

// @0x14078d7c0
int CCinematicEventScript::LoadXml(Unk_ScriptXmlNode* pNode)
{
    if (pNode == 0)
        return 0;
    FUN_1408731e0(pNode, "id", m_nId);
    for (Unk_ScriptXmlNode* pContent = FUN_140165cf0(pNode, "content"); pContent != 0; pContent = FUN_140168650(pContent, "content")) {
        Unk_ScriptPtr<CScriptContent> spContent(new CScriptContent());
        if (spContent->vfunc_2(pContent) == 0)
            return 0;
        m_contents.Add(spContent);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14078D7C0, CCinematicEventScript, LoadXml, 327, 0x0ED6B91D);

// @0x14078d910
Unk_ScriptPtr<CScriptContent> CCinematicEventScript::GetRandomContent()
{
    if (m_contents.GetCount() == 0)
        return Unk_ScriptPtr<CScriptContent>(0);
    unsigned n = FUN_140768010((unsigned)m_contents.GetCount(), 0);
    return m_contents.GetAt(n);
}

// @0x14078d9c0
CCinematicContent::CCinematicContent()
    : m_buttonSet(0), m_questId(0), m_openTalkReward(0)
{
    m_distractors = 0;
    m_functionId = 0;
    m_otherNpcTalk = 0;
    m_myTalk = 0;
    m_redirect = 0;
    m_speakerNpc = 0;
    m_screenEffectValue = 0;
}

// @0x14078db40
CCinematicContent::CCinematicContent(CByteBuffer& in)
{
    m_questId = 0;
    m_openTalkReward = 0;
    m_distractors = 0;
    m_functionId = 0;
    m_otherNpcTalk = 0;
    m_myTalk = 0;
    m_redirect = 0;
    m_speakerNpc = 0;
    m_screenEffectValue = 0;
    m_text = in.vfunc_o8_8();
    m_voiceId = L"";
    m_illust = L"";
    m_buttonSet = in.vfunc_o8_3();
}

// @0x14078dd60
CCinematicContent::~CCinematicContent()
{
    m_distractors = 0;
    m_functionId = 0;
}

// @0x14078ebd0
// MS2-FUNCTIONAL: the exe copy has a dead assert(0)/return 2 branch (a compile-time type switch) in front of the xml read
static int FUN_14078ebd0(Unk_ScriptXmlNode* pNode, const char* pszName, int* pOut)
{
    int nValue = 0;
    int nResult = FUN_140873890(pNode, pszName, nValue);
    if (nResult == 0)
        *pOut = nValue;
    return nResult;
}

// @0x14078de70
int CCinematicContent::vfunc_2(Unk_ScriptXmlNode* pNode)
{
    if (CScriptContent::vfunc_2(pNode) == 0)
        return 0;
    if (FUN_14086f4b0(pNode, "buttonSet") != 0)
        FUN_1408731e0(pNode, "buttonSet", m_buttonSet);
    if (FUN_14086f4b0(pNode, "openTalkReward") != 0)
        FUN_140873710(pNode, "openTalkReward", &m_openTalkReward);
    if (FUN_14086f4b0(pNode, "functionID") != 0)
        FUN_1408731e0(pNode, "functionID", m_functionId);
    if (FUN_14086f4b0(pNode, "otherNpcTalk") != 0)
        FUN_140873220(pNode, "otherNpcTalk", m_otherNpcTalk);
    FUN_1408733e0(pNode, "leftIllust", m_leftIllust);
    FUN_1408733e0(pNode, "rightIllust", m_rightIllust);
    FUN_1408733e0(pNode, "speakerIllust", m_speakerIllust);
    FUN_140873220(pNode, "speakerNpc", m_speakerNpc);
    FUN_1408733e0(pNode, "imagePlate", m_imagePlate);
    FUN_14078ebd0(pNode, "myTalk", &m_myTalk);
    FUN_1408733e0(pNode, "movie", m_movie);
    FUN_1408731e0(pNode, "redirect", m_redirect);
    FUN_1408733e0(pNode, "screenEffectMovie", m_screenEffectMovie);
    FUN_1408733e0(pNode, "screenEffectAction", m_screenEffectAction);
    FUN_140873220(pNode, "screenEffectValue", m_screenEffectValue);
    Unk_ScriptPtr<CCinematicDistractor> spDistractor(0);
    for (Unk_ScriptXmlNode* pChoice = FUN_140165cf0(pNode, "distractor"); pChoice != 0; pChoice = FUN_140168650(pChoice, "distractor")) {
        if (spDistractor == 0)
            spDistractor = new CCinematicDistractor();
        Unk_ScriptChoice choice;
        FUN_140873420(pChoice, "text", choice.m_text);
        FUN_1408733e0(pChoice, "goto", choice.m_goto);
        FUN_1408733e0(pChoice, "gotoFail", choice.m_gotoFail);
        FUN_1403b4750()->FUN_1416fb380(choice.m_text);
        spDistractor->m_choices.Add(choice);
    }
    m_distractors = spDistractor;
    for (Unk_ScriptXmlNode* pEvent = FUN_140165cf0(pNode, "event"); pEvent != 0; pEvent = FUN_140168650(pEvent, "event")) {
        Unk_ScriptPtr<CCinematicEventScript> spEvent(new CCinematicEventScript());
        if (spEvent->LoadXml(pEvent) == 0)
            return 0;
        m_events.Add(spEvent);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14078DE70, CCinematicContent, vfunc_2, 1313, 0xFB301327);

// @0x14078e3a0
int CCinematicContent::vfunc_1()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14078E3A0, CCinematicContent, vfunc_1, 8, 0x7F371472);

// @0x14078e3b0
// MS2-FUNCTIONAL: exe keeps ~60 more bytes of EH temporaries around the talk lookup/split; behaviour the same
void CCinematicContent::vfunc_3(int nId)
{
    if (m_distractors.get() != 0) {
        ATL::CAtlArray<Unk_ScriptChoice*> removed;
        for (size_t i = 0; i < m_distractors->m_choices.GetCount(); i++) {
            CStringA strCond(m_distractors->m_choices.GetAt(i).m_goto);
            ATL::CAtlArray<int> ids;
            FUN_140177de0(strCond, ids, ",");
            if (FUN_140186260(ids) != 0) {
                bool bAll = true;
                for (size_t j = 0; j < FUN_140186260(ids); j++) {
                    Unk_ScriptTalk* pTalk = FUN_140856820(nId, *FUN_1401844d0(ids, j)).get();
                    if (pTalk != 0) {
                        bAll = false;
                        break;
                    }
                }
                if (bAll) {
                    Unk_ScriptChoice* pChoice = &m_distractors->m_choices.GetAt(i);
                    removed.Add(pChoice);
                }
            }
        }
        for (size_t k = 0; k < removed.GetCount(); k++) {
            for (size_t i = 0; i < m_distractors->m_choices.GetCount(); i++) {
                Unk_ScriptChoice** ppRemoved = &removed.GetAt(k);
                if (*ppRemoved == &m_distractors->m_choices.GetAt(i)) {
                    m_distractors->m_choices.RemoveAt(i, 1);
                    break;
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14078E3B0, CCinematicContent, vfunc_3, 818, 0x3248A9FB);

// @0x14078e6f0
// MS2-FUNCTIONAL: exe keeps ~60 more bytes of EH temporaries around the talk lookup/split; behaviour the same
void CCinematicContent::vfunc_4(int nId)
{
    if (m_distractors.get() != 0) {
        ATL::CAtlArray<Unk_ScriptChoice*> removed;
        for (size_t i = 0; i < m_distractors->m_choices.GetCount(); i++) {
            CStringA strCond(m_distractors->m_choices.GetAt(i).m_goto);
            ATL::CAtlArray<int> ids;
            FUN_140177de0(strCond, ids, ",");
            if (FUN_140186260(ids) != 0) {
                bool bAll = true;
                for (size_t j = 0; j < FUN_140186260(ids); j++) {
                    Unk_ScriptTalk* pTalk = FUN_1408564b0(nId, *FUN_1401844d0(ids, j)).get();
                    if (pTalk != 0) {
                        bAll = false;
                        break;
                    }
                }
                if (bAll) {
                    Unk_ScriptChoice* pChoice = &m_distractors->m_choices.GetAt(i);
                    removed.Add(pChoice);
                }
            }
        }
        for (size_t k = 0; k < removed.GetCount(); k++) {
            for (size_t i = 0; i < m_distractors->m_choices.GetCount(); i++) {
                Unk_ScriptChoice** ppRemoved = &removed.GetAt(k);
                if (*ppRemoved == &m_distractors->m_choices.GetAt(i)) {
                    m_distractors->m_choices.RemoveAt(i, 1);
                    break;
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14078E6F0, CCinematicContent, vfunc_4, 818, 0xCFCF62C5);

// @0x14078ea30
void CCinematicContent::vfunc_5(COutputStream& out)
{
    CScriptContent::vfunc_5(out);
    out.vfunc_o10_3(m_buttonSet);
    if (m_distractors.get() != 0) {
        out.vfunc_o10_1(1);
        m_distractors->WriteTo(out);
    } else {
        out.vfunc_o10_1(0);
    }
}
MS2_REPLACE_METHOD(0x14078EA30, CCinematicContent, vfunc_5, 152, 0xEB69E812);

// @0x14078ead0
void CCinematicContent::vfunc_6(CByteBuffer& in)
{
    CScriptContent::vfunc_6(in);
    m_buttonSet = in.vfunc_o8_3();
    unsigned char bHas = in.vfunc_o8_1();
    if (bHas == 1) {
        CCinematicDistractor* pDistractor = new CCinematicDistractor();
        pDistractor->ReadFrom(in);
        m_distractors = pDistractor;
    }
}
MS2_REPLACE_METHOD(0x14078EAD0, CCinematicContent, vfunc_6, 241, 0xC33F35E6);
