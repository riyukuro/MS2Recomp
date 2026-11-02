// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The talk script contents (spoken lines, cinematic talk pages
// with choices and random events) and the smart pointer / array instances they need.
// MS2-UNIT: ?\scriptcontent.cpp
// MS2-RANGE: 0x14078ced0-0x140790bd0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\scriptcontent.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scriptcontent.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/commonfiles/os.h"
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----

int FUN_140873420(Unk_ScriptXmlNode* pNode, const char* pszName, CStringW& rOut);   // xml attribute -> wide string
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetBool(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873710
int XmlQuery(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873890
class TiXmlElement   // C3: member view for the former free stand-ins
{
public:
    char const* Attribute(char const*) const;
};
class Unk_XmlNode   // C3: member view for the former free stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
class CReservedWordTable;
int FUN_140768010(int, int);  // C3: the definition's signature
void FUN_140177de0(CStringA& str, ATL::CAtlArray<int>& rOut, const char* pszSep);   // split into ints
size_t FUN_140186260(ATL::CAtlArray<int>& arr);                                     // GetCount
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
    XmlGetAttr((class TiXmlElement*)(pNode), "text", m_text);
    XmlGetAttr((class TiXmlElement*)(pNode), "voiceID", m_voiceId);
    XmlGetAttr((class TiXmlElement*)(pNode), "illust", m_illust);
    TSingleton<CReservedWordTable>::GetInstance()->FUN_1416fb380(m_text);
    return 1;
}
MS2_REPLACE_METHOD(0x14078CFD0, CScriptContent, vfunc_2, 158, 0x04708005);

// @0x14078d080
void CScriptContent::vfunc_5(COutputStream& out)
{
    out.WriteUInt8((unsigned char)vfunc_1());
    out.WriteUnicodeString(m_text);
    out.WriteUnicodeStringA(m_voiceId);
    out.WriteUnicodeStringA(m_illust);
}
MS2_REPLACE_METHOD(0x14078D080, CScriptContent, vfunc_5, 178, 0xB1980750);

// @0x14078d140
void CScriptContent::vfunc_6(CByteBuffer& in)
{
    m_text = in.ReadUnicodeString();
    m_voiceId = in.ReadUnicodeStringA();
    m_illust = in.ReadUnicodeStringA();
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
size_t CCinematicDistractor::FUN_14078d3a0() const
{
    return m_choices.GetCount();
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
    out.WriteUInt8((unsigned char)m_choices.GetCount());
    for (size_t i = 0; i < m_choices.GetCount(); i++) {
        out.WriteUnicodeString(m_choices.GetAt(i).m_text);
        out.WriteUnicodeStringA(m_choices.GetAt(i).m_goto);
        out.WriteUnicodeStringA(m_choices.GetAt(i).m_gotoFail);
    }
}
MS2_REPLACE_METHOD(0x14078D410, CCinematicDistractor, WriteTo, 283, 0x6555DB89);

// @0x14078d540
void CCinematicDistractor::ReadFrom(CByteBuffer& in)
{
    unsigned char nCount = in.ReadUInt8();
    for (unsigned char i = 0; i < nCount; i++) {
        Unk_ScriptChoice choice;
        choice.m_text = in.ReadUnicodeString();
        choice.m_goto = in.ReadUnicodeStringA();
        choice.m_gotoFail = in.ReadUnicodeStringA();
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
    XmlGetAttr((class TiXmlElement*)(pNode), "id", m_nId);
    for (Unk_ScriptXmlNode* pContent = ((class Unk_ScriptXmlNode*)((class Unk_XmlNode*)(class Unk_ScriptXmlNode*)(pNode))->FirstChild("content")); pContent != 0; pContent = ((class Unk_ScriptXmlNode*)((class Unk_XmlNode*)(class Unk_ScriptXmlNode*)(pContent))->NextSibling("content"))) {
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
    m_text = in.ReadUnicodeString();
    m_voiceId = L"";
    m_illust = L"";
    m_buttonSet = in.ReadInt32();
}

// @0x14078dd60
CCinematicContent::~CCinematicContent()
{
    m_distractors = 0;
    m_functionId = 0;
}

// @0x14078ebd0
static int FUN_14078ebd0(Unk_ScriptXmlNode* pNode, const char* pszName, int* pOut)
{
    // the tinyxmlhelper.h enum reader's compile-time-false type guard (ASSERT(FALSE) of its line 231)
    if (false)
    {
        (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 231), 0));
        return 2;
    }
    int nValue = 0;
    int nResult = XmlQuery((class TiXmlElement*)(pNode), pszName, nValue);
    if (nResult != 0)
        return nResult;
    *pOut = nValue;
    return nResult;
}

// @0x14078de70
int CCinematicContent::vfunc_2(Unk_ScriptXmlNode* pNode)
{
    if (CScriptContent::vfunc_2(pNode) == 0)
        return 0;
    if (((class TiXmlElement*)(class Unk_ScriptXmlNode*)(pNode))->Attribute("buttonSet") != 0)
        XmlGetAttr((class TiXmlElement*)(pNode), "buttonSet", m_buttonSet);
    if (((class TiXmlElement*)(class Unk_ScriptXmlNode*)(pNode))->Attribute("openTalkReward") != 0)
        XmlGetBool((class TiXmlElement*)(pNode), "openTalkReward", *(int*)(&m_openTalkReward));
    if (((class TiXmlElement*)(class Unk_ScriptXmlNode*)(pNode))->Attribute("functionID") != 0)
        XmlGetAttr((class TiXmlElement*)(pNode), "functionID", m_functionId);
    if (((class TiXmlElement*)(class Unk_ScriptXmlNode*)(pNode))->Attribute("otherNpcTalk") != 0)
        XmlGetAttr((class TiXmlElement*)(pNode), "otherNpcTalk", reinterpret_cast<unsigned int&>(m_otherNpcTalk));
    XmlGetAttr((class TiXmlElement*)(pNode), "leftIllust", m_leftIllust);
    XmlGetAttr((class TiXmlElement*)(pNode), "rightIllust", m_rightIllust);
    XmlGetAttr((class TiXmlElement*)(pNode), "speakerIllust", m_speakerIllust);
    XmlGetAttr((class TiXmlElement*)(pNode), "speakerNpc", reinterpret_cast<unsigned int&>(m_speakerNpc));
    XmlGetAttr((class TiXmlElement*)(pNode), "imagePlate", m_imagePlate);
    FUN_14078ebd0(pNode, "myTalk", &m_myTalk);
    XmlGetAttr((class TiXmlElement*)(pNode), "movie", m_movie);
    XmlGetAttr((class TiXmlElement*)(pNode), "redirect", m_redirect);
    XmlGetAttr((class TiXmlElement*)(pNode), "screenEffectMovie", m_screenEffectMovie);
    XmlGetAttr((class TiXmlElement*)(pNode), "screenEffectAction", m_screenEffectAction);
    XmlGetAttr((class TiXmlElement*)(pNode), "screenEffectValue", reinterpret_cast<unsigned int&>(m_screenEffectValue));
    Unk_ScriptPtr<CCinematicDistractor> spDistractor(0);
    for (Unk_ScriptXmlNode* pChoice = ((class Unk_ScriptXmlNode*)((class Unk_XmlNode*)(class Unk_ScriptXmlNode*)(pNode))->FirstChild("distractor")); pChoice != 0; pChoice = ((class Unk_ScriptXmlNode*)((class Unk_XmlNode*)(class Unk_ScriptXmlNode*)(pChoice))->NextSibling("distractor"))) {
        if (spDistractor == 0)
            spDistractor = new CCinematicDistractor();
        Unk_ScriptChoice choice;
        XmlGetAttr((class TiXmlElement*)(pChoice), "text", choice.m_text);
        XmlGetAttr((class TiXmlElement*)(pChoice), "goto", choice.m_goto);
        XmlGetAttr((class TiXmlElement*)(pChoice), "gotoFail", choice.m_gotoFail);
        TSingleton<CReservedWordTable>::GetInstance()->FUN_1416fb380(choice.m_text);
        spDistractor->m_choices.Add(choice);
    }
    m_distractors = spDistractor;
    for (Unk_ScriptXmlNode* pEvent = ((class Unk_ScriptXmlNode*)((class Unk_XmlNode*)(class Unk_ScriptXmlNode*)(pNode))->FirstChild("event")); pEvent != 0; pEvent = ((class Unk_ScriptXmlNode*)((class Unk_XmlNode*)(class Unk_ScriptXmlNode*)(pEvent))->NextSibling("event"))) {
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
void CCinematicContent::vfunc_3(int nId)
{
    if (m_distractors.get() != 0) {
        ATL::CAtlArray<Unk_ScriptChoice*> removed;
        for (size_t i = 0; i < m_distractors->m_choices.GetCount(); i++) {
            CStringA strCond(m_distractors->m_choices.GetAt(i).m_goto);
            ATL::CAtlArray<int> ids;
            FUN_140177de0(strCond, ids, ",");
            if (FUN_140186260(ids) == 0)
                continue;
            BOOL bAll = TRUE;
            for (size_t j = 0; j < FUN_140186260(ids); j++) {
                if (FUN_140856820(nId, ids[j]).get() != 0) {
                    bAll = FALSE;
                    break;
                }
            }
            if (bAll)
                removed.Add(&m_distractors->m_choices.GetAt(i));
        }
        for (size_t k = 0; k < removed.GetCount(); k++) {
            for (size_t i = 0; i < m_distractors->m_choices.GetCount(); i++) {
                if (removed.GetAt(k) == &m_distractors->m_choices.GetAt(i)) {
                    m_distractors->m_choices.RemoveAt(i, 1);
                    break;
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14078E3B0, CCinematicContent, vfunc_3, 818, 0x3248A9FB);

// @0x14078e6f0
void CCinematicContent::vfunc_4(int nId)
{
    if (m_distractors.get() != 0) {
        ATL::CAtlArray<Unk_ScriptChoice*> removed;
        for (size_t i = 0; i < m_distractors->m_choices.GetCount(); i++) {
            CStringA strCond(m_distractors->m_choices.GetAt(i).m_goto);
            ATL::CAtlArray<int> ids;
            FUN_140177de0(strCond, ids, ",");
            if (FUN_140186260(ids) == 0)
                continue;
            BOOL bAll = TRUE;
            for (size_t j = 0; j < FUN_140186260(ids); j++) {
                if (FUN_1408564b0(nId, ids[j]).get() != 0) {
                    bAll = FALSE;
                    break;
                }
            }
            if (bAll)
                removed.Add(&m_distractors->m_choices.GetAt(i));
        }
        for (size_t k = 0; k < removed.GetCount(); k++) {
            for (size_t i = 0; i < m_distractors->m_choices.GetCount(); i++) {
                if (removed.GetAt(k) == &m_distractors->m_choices.GetAt(i)) {
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
    out.WriteInt32(m_buttonSet);
    if (m_distractors.get() != 0) {
        out.WriteUInt8(1);
        m_distractors->WriteTo(out);
    } else {
        out.WriteUInt8(0);
    }
}
MS2_REPLACE_METHOD(0x14078EA30, CCinematicContent, vfunc_5, 152, 0xEB69E812);

// @0x14078ead0
void CCinematicContent::vfunc_6(CByteBuffer& in)
{
    CScriptContent::vfunc_6(in);
    m_buttonSet = in.ReadInt32();
    unsigned char bHas = in.ReadUInt8();
    if (bHas == 1) {
        CCinematicDistractor* pDistractor = new CCinematicDistractor();
        pDistractor->ReadFrom(in);
        m_distractors = pDistractor;
    }
}
MS2_REPLACE_METHOD(0x14078EAD0, CCinematicContent, vfunc_6, 241, 0xC33F35E6);
