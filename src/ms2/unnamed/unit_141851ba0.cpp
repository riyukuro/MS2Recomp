// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMorphingAnimationData (client\ms2\morphinganimationdata.cpp):
// the frame-time / weight tables of a morph animation, their XML loader, and the small scene-graph visitor that applies a
// weight. See ms2/client/ms2/morphinganimation.h.
// MS2-UNIT: unit_141851ba0
// MS2-RANGE: 0x141851ba0-0x141851fd0 .text$mn
// MS2-PIN: ??_GCMorphingAnimationData@@UEAAPEAXI@Z 0x141851f50
// MS2-PIN: ??1CMorphingAnimationData@@UEAA@XZ 0x141851f00
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\morphinganimationdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/client/ms2/morphinganimation.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered callees (bound by VA) --------------------------------------------------------------------------------

int XmlGetAttr(class TiXmlElement*, char const*, CString&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetBool(class TiXmlElement*, char const*, int&);   // C3: was FUN_140873710
class Unk_XmlNode   // C3: member view for the former free stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
void FUN_1418528d0(void* pVisitor, float fWeight);                               // ctor of the weight visitor (next TU)
#pragma comment(linker, "/alternatename:?FUN_1418528d0@@YAXPEAXM@Z=??0Unk_CtrlValue@@QEAA@M@Z")   // sfr36: full-exe link: unit_141851fd0 defines it as the ctor
void FUN_141852690(void*, struct Unk_CtrlValue*);   // C3: was FUN_141852690

// 0x141851ba0
CMorphingAnimationData::CMorphingAnimationData()
    : m_nLoopStart(-1)
{
}

// @0x141851c20
int CMorphingAnimationData::FUN_141851c20(int nTime)
{
    int nCount = (int)m_frameTimes.GetCount();
    int nLoopBase;
    int j;
    int i;
    int nFrame;
    int nAccum;
    nFrame = 0;
    nAccum = 0;
    nLoopBase = 0;
    for (j = 0; j < nCount; ++j)
    {
        if (j == m_nLoopStart)
            nLoopBase = nAccum;
        nAccum += m_frameTimes[j];
        if (nAccum < nTime)
            ++nFrame;
        else
            break;
    }
    if (nFrame < nCount || m_nLoopStart == -1)
        return nFrame;
    {
        int nLoopSpan = nAccum - nLoopBase;
        if (nLoopSpan == 0)
            return m_nLoopStart;
        nTime = (nTime - nLoopBase) % nLoopSpan;
        nAccum = 0;
        nFrame = m_nLoopStart;
        for (i = m_nLoopStart; i < nCount; ++i)
        {
            nAccum += m_frameTimes[i];
            if (nAccum < nTime)
                ++nFrame;
            else
                break;
        }
    }
    return nFrame;
}
MS2_REPLACE_METHOD(0x141851C20, CMorphingAnimationData, FUN_141851c20, 386, 0xD67399D0);

// @0x141851db0
void CMorphingAnimationData::FUN_141851db0(Unk_140165cf0* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "target", m_strNodeName);
    if (m_strNodeName.IsEmpty())
        m_strNodeName = "FA_Skin";
    for (Unk_140165cf0* pWeight = ((class Unk_140165cf0*)((class Unk_XmlNode*)(class Unk_140165cf0*)(pElem))->FirstChild("weight")); pWeight != 0;
         pWeight = ((class Unk_140165cf0*)((class Unk_XmlNode*)(class Unk_140165cf0*)(pWeight))->NextSibling("weight")))
    {
        float fValue;
        XmlGetAttr((class TiXmlElement*)(pWeight), "value", fValue);
        m_weights.Add(fValue);
        int nDelay = 0;
        XmlGetAttr((class TiXmlElement*)(pWeight), "delay", nDelay);
        m_frameTimes.Add(nDelay);
        int nLoop = 0;
        XmlGetBool((class TiXmlElement*)(pWeight), "loop", *(int*)(&nLoop));
        if (nLoop != 0)
            m_nLoopStart = (int)(m_frameTimes.GetCount() - 1);
    }
}
MS2_REPLACE_METHOD(0x141851DB0, CMorphingAnimationData, FUN_141851db0, 322, 0xB4F3EA33);

// The weight visitor the scene-graph walk takes: a float at +0x00.
struct Unk_MorphWeightVisitor
{
    float m_fWeight;
};

// @0x141851f90
void FUN_141851f90(void* pObject, float fWeight)
{
    Unk_MorphWeightVisitor visitor;
    FUN_1418528d0(&visitor, fWeight);
    FUN_141852690(pObject, (struct Unk_CtrlValue*)(&visitor));
}
MS2_REPLACE(0x141851F90, FUN_141851f90, 51, 0x641A0F3B);
