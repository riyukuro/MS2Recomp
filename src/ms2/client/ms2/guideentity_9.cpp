// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-condition base class CGuideCondition and the conditions
// False / Trigger / Timeout (part 9 of client\ms2\guideentity.cpp, the class tail). See ms2/placeholder/cguidecondition.h.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: client\ms2\guideentity.cpp#9
// MS2-RANGE: 0x1413a2c00-0x1413a3c60 .text$mn
// MS2-RANGE: 0x1413a3c60-0x1413a4960 .text$mn
// MS2-RANGE: 0x1413a49a0-0x1413a5130 .text$mn
// MS2-RANGE: 0x1413a5130-0x1413a54e0 .text$mn
// MS2-RANGE: 0x1413a54e0-0x1413a6010 .text$mn
// MS2-RANGE: 0x1413b4200-0x1413b4240 .text$mn
// MS2-RANGE: 0x1413b5380-0x1413b53c0 .text$mn
// MS2-RANGE: 0x1413b5400-0x1413b5440 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\guideentity.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <exception>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/client/ms2/guideentity.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
class TiXmlElement   // C3: member view for the former free stand-ins
{
public:
    char const* Attribute(char const*) const;
};
int FUN_1413b1d00(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptInt& oOut);
int FUN_1413b1fc0(Unk_140165cf0* pElem, const char* pszName, int& nOut);
void FUN_1412751b0(const CStringW& text, int a);                        // the debug log

char FUN_1405c7ba0(const Unk_GeRange* pRange);                          // is set
int FUN_1413b1d60(class Unk_140165cf0*, char const*, void*);   // C3: was FUN_1413b1d60
class Unk_ImNullableInt   // C3: member view for the former free stand-ins
{
public:
    bool HasValue() const;
};
const int* FUN_1413989f0(const Unk_GcOptInt* pOpt);                     // Nullable<int>::GetValue
Unk_GcOptInt* FUN_140d11940(Unk_GcOptInt* pOpt);                        // Nullable<int>()

class Unk_140165cf0* FUN_140345b40(class TiXmlDocument*);   // C3: was FUN_140345b40
Unk_GcCondRef FUN_1413a5420(CStringA strTag);                           // the condition class of a tag
void* FUN_141395500(void* pNode);
Unk_GeActRef FUN_141382b90(Unk_140165cf0* pElem);                       // builds the action of an <action> element
// The condition / action lists hold 16-byte handles (the shared placeholder declares them as pointer arrays).
#define GE_REFS(list) reinterpret_cast<ATL::CAtlArray<Unk_GcCondRef>&>((list).m_arr)

// The guide manager: the trigger events that were raised.
class Unk_GeMgr
{
public:
    void FUN_14138d7e0(int nId, int nValue);
    char FUN_14138c0d0(int nTrigger, Unk_GcOptInt oValue, Unk_GcOptInt oSubValue);
    char FUN_14138c210(int nTrigger, const Unk_GeRange& range);
};
class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0

// ---- the std::map<int, int> and 16-byte handle array glue (0x1413a3c60..0x1413a5130) ----------------------------------------

struct Unk_GeNode                                                       // a node of the trigger map (0x28)
{
    Unk_GeNode* m_pLeft; Unk_GeNode* m_pParent; Unk_GeNode* m_pRight;
    char m_cColor; char m_bNil; int m_nKey; int m_nValue;
};
struct Unk_GeTreeHead { Unk_GeNode* m_pHead; unsigned __int64 m_nSize; };
struct Unk_GeIter { Unk_GeNode* m_pNode; };

void* FUN_141395550(Unk_GeTreeHead* pHead);                             // the container proxy
Unk_GeIter* FUN_141397130(Unk_GeIter* pOut, Unk_GeNode* pNode, void* pProxy);
void* FUN_14139e9f0(void* pMap);                                        // the node allocator
Unk_GeNode** FUN_14139f960(Unk_GeTreeHead* pHead);                      // the root
Unk_GeNode** FUN_14139eee0(Unk_GeTreeHead* pHead);                      // the leftmost
Unk_GeNode** FUN_14139f8e0(Unk_GeTreeHead* pHead);                      // the rightmost
void FUN_14139eff0(Unk_GeTreeHead* pHead, Unk_GeNode* pNode);           // rotate left
void FUN_14139faa0(Unk_GeTreeHead* pHead, Unk_GeNode* pNode);           // rotate right
void FUN_1413a4e30(void* pMap, Unk_GeNode* pNode);                      // frees a node
void* FUN_141398a90(void* pIter);
void* FUN_1413a4830(void* pIter);                                       // map<int,int> iterator operator* (out of line, calls the const one)
void FUN_141389060(Unk_GcCondRef* pRef);
unsigned __int64 FUN_1413a5140(void* pMap);
void* FUN_1413a5160(void* pNode);

// @0x1413a3d00
std::pair<int, int>* FUN_1413a3d00(std::pair<int, int>* pDst, const std::pair<int, int>* pSrc)
{
    pDst->first = pSrc->first;
    pDst->second = pSrc->second;
    return pDst;
}

// @0x1413a3d50
Unk_GeNode* FUN_1413a3d50(void* pMap, Unk_GeNode* pNode, const int& rKey)  // _Buynode_if_nil: a ready node is used as is
{
    return pNode;
}

// @0x1413a46e0
const int& FUN_1413a46e0(const int& rKey)                                 // std::forward
{
    return rKey;
}

// @0x1413a3e00
Unk_GeIter* FUN_1413a3e00(void* pMap, Unk_GeIter* pOut, bool bLeft, Unk_GeNode* pWhere, const int& rKey, Unk_GeNode* pNode)
{
    Unk_GeTreeHead* pHead = ((struct Unk_GeTreeHead*)&((std::_Tree_comp_alloc<std::_Tmap_traits<int, int, std::less<int>, std::allocator<std::pair<int const, int>>, 0>>*)(void*)(pMap))->_Get_data());
    if (FUN_1413a5140(pMap) - 1 <= pHead->m_nSize)
    {
        FUN_1413a4e30(pMap, pNode);
        std::_Xlength_error("map/set<T> too long");
    }
    Unk_GeNode* pNew = FUN_1413a3d50(pMap, pNode, FUN_1413a46e0(rKey));
    pHead->m_nSize = pHead->m_nSize + 1;
    pNew->m_pParent = pWhere;
    if (pWhere == pHead->m_pHead)
    {
        *FUN_14139f960(pHead) = pNew;
        *FUN_14139eee0(pHead) = pNew;
        *FUN_14139f8e0(pHead) = pNew;
    }
    else if (bLeft)
    {
        pWhere->m_pLeft = pNew;
        if (pWhere == *FUN_14139eee0(pHead))
            *FUN_14139eee0(pHead) = pNew;
    }
    else
    {
        pWhere->m_pRight = pNew;
        if (pWhere == *FUN_14139f8e0(pHead))
            *FUN_14139f8e0(pHead) = pNew;
    }
    for (Unk_GeNode* pCur = pNew; pCur->m_pParent->m_cColor == 0; )
    {
        if (pCur->m_pParent == pCur->m_pParent->m_pParent->m_pLeft)
        {
            pWhere = pCur->m_pParent->m_pParent->m_pRight;
            if (pWhere->m_cColor == 0)
            {
                pCur->m_pParent->m_cColor = 1;
                pWhere->m_cColor = 1;
                pCur->m_pParent->m_pParent->m_cColor = 0;
                pCur = pCur->m_pParent->m_pParent;
            }
            else
            {
                if (pCur == pCur->m_pParent->m_pRight)
                {
                    pCur = pCur->m_pParent;
                    FUN_14139eff0(pHead, pCur);
                }
                pCur->m_pParent->m_cColor = 1;
                pCur->m_pParent->m_pParent->m_cColor = 0;
                FUN_14139faa0(pHead, pCur->m_pParent->m_pParent);
            }
        }
        else
        {
            pWhere = pCur->m_pParent->m_pParent->m_pLeft;
            if (pWhere->m_cColor == 0)
            {
                pCur->m_pParent->m_cColor = 1;
                pWhere->m_cColor = 1;
                pCur->m_pParent->m_pParent->m_cColor = 0;
                pCur = pCur->m_pParent->m_pParent;
            }
            else
            {
                if (pCur == pCur->m_pParent->m_pLeft)
                {
                    pCur = pCur->m_pParent;
                    FUN_14139faa0(pHead, pCur);
                }
                pCur->m_pParent->m_cColor = 1;
                pCur->m_pParent->m_pParent->m_cColor = 0;
                FUN_14139eff0(pHead, pCur->m_pParent->m_pParent);
            }
        }
    }
    (*FUN_14139f960(pHead))->m_cColor = 1;
    FUN_141397130(pOut, pNew, FUN_141395550(pHead));
    return pOut;
}

// @0x1413a4620
void FUN_1413a4620(void* pAlloc, std::pair<int, int>* pDst, const std::pair<int, int>& rVal)
{
    void* pNew = ::operator new(8, pDst);
    FUN_1413a3d00(static_cast<std::pair<int, int>*>(pNew), &std::forward<const std::pair<int, int>&>(rVal));
}

// @0x1413a4750
Unk_GcCondRef::Unk_GcCondRef()
{
    m_p = 0;
}

// @0x1413a4770
Unk_GcCondRef& Unk_GcCondRef::operator=(const Unk_GcCondRef& rhs)
{
    const_cast<Unk_GcCondRef&>(rhs).FUN_141388ed0();
    FUN_141389060(this);
    m_p = rhs.m_p;
    return *this;
}

// @0x1413a47b0
bool FUN_1413a47b0(const Unk_GeActRef& ref)
{
    return ref.m_p == 0;
}

// @0x1413a47e0
bool FUN_1413a47e0(const Unk_GcCondRef& ref)
{
    return ref.m_p == 0;
}

// @0x1413a4810
void* FUN_1413a4810(void* pIter)
{
    return FUN_1413a5160(FUN_1413a4830(pIter));
}

// @0x1413a4830
void* FUN_1413a4830(void* pIter)
{
    return FUN_141398a90(pIter);
}

// @0x1413a4b50
bool FUN_1413a4b50()
{
    return false;
}

// ---- the glue in front of the base class: allocator limit, checked memmove, the condition factory ------------------------------

// @0x1413a5130
unsigned __int64 FUN_1413a5130(void* pAlloc)
{
    return 0x666666666666666;
}

// @0x1413a5140
unsigned __int64 FUN_1413a5140(void* pMap)
{
    return FUN_1413a5130(((void*)&((std::_Tree_comp_alloc<std::_Tmap_traits<std::pair<unsigned int, int>, int, std::less<std::pair<unsigned int, int>>, std::allocator<std::pair<std::pair<unsigned int, int> const, int>>, 0>>*)(void*)(pMap))->_Get_data()));
}

// @0x1413a5160
void* FUN_1413a5160(void* pNode)
{
    return FUN_141395500(pNode);
}

// @0x1413a5180
errno_t FUN_1413a5180(void* pDst, size_t nDstSize, const void* pSrc, size_t nCount)
{
    return memmove_s(pDst, nDstSize, pSrc, nCount);
}

// @0x1413a52a0
tm* FUN_1413a52a0(const __time64_t* pTime)
{
    return _localtime64(pTime);
}

// @0x1413a52c0
Unk_GcCondRef FUN_1413a52c0(Unk_140165cf0* pElem)
{
    CStringA strTag(((class TiXmlElement*)(class Unk_140165cf0*)(pElem))->Attribute("type"));
    Unk_GcCondRef ref = FUN_1413a5420(strTag);
    if (ref.FUN_141387b90())
        ref.FUN_141387bb0()->vfunc_2(pElem);
    else
        throw std::exception(StringFormat<CStringA>("Unknown Guide Condition Tag({0})", strTag));
    return ref;
}

// @0x1413a5420
Unk_GcCondRef FUN_1413a5420(CStringA strTag)
{
    CStringW strClass = StringFormat<CStringA>(L"CGuideCondition{0}", strTag);
    Unk_GcCondRef ref(static_cast<CGuideCondition*>(FUN_1401f7f50(strClass)));
    return ref;
}

// ---- CGuideCondition ------------------------------------------------------------------------------------------------------

// @0x1413a54e0
CGuideCondition::CGuideCondition()
{
    m_n18 = 0;
    m_b1c = false;
    m_n20 = 0;
}

// @0x1413a5540
CGuideCondition::~CGuideCondition()
{
}

// @0x1413a5570
int FUN_1413a5570(CGuideCondition* pCond)
{
    return pCond->vfunc_3();
}

// @0x1413a55a0
int CGuideCondition::FUN_1413a55a0(int nResult)
{
    int nRet;
    if (m_b1c)
        nRet = nResult == 0 ? 1 : 0;
    else
        nRet = nResult;
    return nRet;
}

// @0x1413a5600
int CGuideCondition::FUN_1413a5600(bool bResult)
{
    if (m_b1c)
        return bResult ? 0 : 1;
    return bResult ? 1 : 0;
}

// @0x1413a5670
void CGuideCondition::vfunc_2(Unk_140165cf0* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "value", m_n20);
    XmlGetAttr((class TiXmlElement*)(pElem), "not", m_b1c);
}

// @0x1413a56d0
int CGuideCondition::vfunc_3()
{
    return 0;
}

// @0x1413a56e0
void CGuideCondition::vfunc_4()
{
}

// @0x1413a56f0
void CGuideCondition::vfunc_5()
{
    CStringW str(L"Nothing TestCase");
    FUN_1412751b0(str, 20);
}

// @0x1413a5740
bool CGuideCondition::vfunc_6(Unk_GcCondList* pFailed)
{
    return false;
}

// @0x1413a5760
CStringW CGuideCondition::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"value({0})", m_n20));
    return str;
}

// @0x1413a5810
int CGuideCondition::vfunc_8()
{
    return 0;
}

// @0x1413a5820
CStringW CGuideCondition::FUN_1413a5820()
{
    CStringW str = StringFormat(L"{0}:", GetTypeName());
    if (m_b1c)
        str.Append(L"not ");
    return str;
}

// ---- CGuideConditionFalse -------------------------------------------------------------------------------------------------

// @0x1413a58e0
ClassObject* CGuideConditionFalse::CreateObject()
{
    return new CGuideConditionFalse;
}

// @0x1413a5940
CStringW CGuideConditionFalse::GetTypeName()
{
    return L"CGuideConditionFalse";
}

// @0x1413a5990
int CGuideConditionFalse::vfunc_3()
{
    return 0;
}

// ---- CGuideConditionTrigger -----------------------------------------------------------------------------------------------

// @0x1413a59a0
ClassObject* CGuideConditionTrigger::CreateObject()
{
    return new CGuideConditionTrigger;
}

// @0x1413a5a00
CStringW CGuideConditionTrigger::GetTypeName()
{
    return L"CGuideConditionTrigger";
}

// @0x1413a5a50
CGuideConditionTrigger::CGuideConditionTrigger()
    : m_n28(0)
{
}

// @0x1413a5ad0
void CGuideConditionTrigger::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1413b1fc0(pElem, "trigger", m_n28);
    FUN_1413b1d00(pElem, "value", m_a);
    FUN_1413b1d00(pElem, "subValue", m_b);
    if (((class TiXmlElement*)(class Unk_140165cf0*)(pElem))->Attribute("range") != 0)
        FUN_1413b1d60(pElem, "range", (void*)(&m_range));
    if (m_n28 == 0)
        throw std::exception("Unknown Guide Trigger Tag");
}

// @0x1413a5bb0
int CGuideConditionTrigger::vfunc_3()
{
    if (FUN_1405c7ba0(&m_range) == 0)
        return FUN_1413a55a0(((class Unk_GeMgr*)FUN_1409331e0())->FUN_14138c0d0(m_n28, m_a, m_b) != 0);
    return FUN_1413a55a0(((class Unk_GeMgr*)FUN_1409331e0())->FUN_14138c210(m_n28, m_range) != 0);
}

// @0x1413a5c80
CStringW CGuideConditionTrigger::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"type({0})", reinterpret_cast<const Unk_GcEnum1&>(m_n28)));
    if (((class Unk_ImNullableInt*)(struct Unk_GcOptInt const*)(&m_a))->HasValue())
        str.Append(StringFormat(L" ,value({0})", *FUN_1413989f0(&m_a)));
    if (((class Unk_ImNullableInt*)(struct Unk_GcOptInt const*)(&m_b))->HasValue())
        str.Append(StringFormat(L" ,subValue({0})", *FUN_1413989f0(&m_b)));
    str.Append(StringFormat<int, int>(L" ,range({0}-{1})", m_range.m_nMin, m_range.m_nMax));
    return str;
}

// ---- CGuideConditionTimeout -----------------------------------------------------------------------------------------------

// @0x1413a5e90
ClassObject* CGuideConditionTimeout::CreateObject()
{
    return new CGuideConditionTimeout;
}

// @0x1413a5ef0
CStringW CGuideConditionTimeout::GetTypeName()
{
    return L"CGuideConditionTimeout";
}

// @0x1413a5f40
CGuideConditionTimeout::CGuideConditionTimeout()
{
    m_n28 = 0;
}

// @0x1413a5f80
int CGuideConditionTimeout::vfunc_3()
{
    if (m_n28 == 0)
        m_n28 = GetTickCountMs2() + m_n20;
    return FUN_1413a5600(GetTickCountMs2() >= (unsigned)m_n28);
}

// @0x1413a5fe0
void CGuideConditionTimeout::vfunc_4()
{
    CGuideCondition::vfunc_4();
    m_n28 = 0;
}

// ---- CGuideEntity ---------------------------------------------------------------------------------------------------------

// @0x1413a2c00
unsigned CGuideEntity::GetSaveId() const
{
    return m_nSaveId;
}

// @0x1413a2c20
unsigned CGuideEntity::GetSaveStep() const
{
    return m_nSaveStep;
}

// @0x1413a2c40
int CGuideEntity::GetForce() const
{
    return m_nForce;
}

// @0x1413a2c60
int CGuideEntity::IsSaveSkipped() const
{
    return m_nSaveId == 0 || m_nNoSave != 0;
}

// @0x1413a2ca0
int CGuideEntity::CheckStart(bool* pbOpen, unsigned* pnFailed)
{
    for (unsigned i = 0; i < m_condTrigger.FUN_1413886d0(); ++i)
    {
        if (FUN_1413a5570(m_condTrigger.FUN_141387b40(i).FUN_141387bb0()) == 0)
        {
            if (pnFailed != 0)
                *pnFailed = i;
            *pbOpen = true;
            return 0;
        }
    }
    for (unsigned i = 0; i < m_condOpen.FUN_1413886d0(); ++i)
    {
        if (FUN_1413a5570(m_condOpen.FUN_141387b40(i).FUN_141387bb0()) == 0)
        {
            if (pnFailed != 0)
                *pnFailed = i;
            *pbOpen = false;
            return 0;
        }
    }
    return 1;
}

// @0x1413a2dd0
int CGuideEntity::CheckClose(unsigned* pnFailed)
{
    for (unsigned i = 0; i < m_condClose.FUN_1413886d0(); ++i)
    {
        if (FUN_1413a5570(m_condClose.FUN_141387b40(i).FUN_141387bb0()) == 0)
        {
            if (pnFailed != 0)
                *pnFailed = i;
            return 0;
        }
    }
    return 1;
}

// @0x1413a2e70
int CGuideEntity::CheckCancel(unsigned* pnFailed)
{
    if (GE_REFS(m_condCancel).IsEmpty())
        return 0;
    for (unsigned i = 0; i < m_condCancel.FUN_1413886d0(); ++i)
    {
        if (FUN_1413a5570(m_condCancel.FUN_141387b40(i).FUN_141387bb0()) == 0)
        {
            if (pnFailed != 0)
                *pnFailed = i;
            return 0;
        }
    }
    return 1;
}

// @0x1413a2f30
void CGuideEntity::GetFailedText(CStringW& strOut, bool bTrigger, unsigned nIdx)
{
    if (!bTrigger)
    {
        if (nIdx < m_condOpen.FUN_1413886d0())
            strOut = m_condOpen.FUN_141387b40(nIdx).FUN_141387bb0()->vfunc_7();
    }
    else
    {
        if (nIdx < m_condTrigger.FUN_1413886d0())
            strOut = m_condTrigger.FUN_141387b40(nIdx).FUN_141387bb0()->vfunc_7();
    }
}

// @0x1413a30a0
void CGuideEntity::GetCloseText(CStringW& strOut, unsigned nIdx)
{
    if (nIdx >= m_condClose.FUN_1413886d0())
        return;
    strOut = m_condClose.FUN_141387b40(nIdx).FUN_141387bb0()->vfunc_7();
}

// @0x1413a3150
void CGuideEntity::GetCancelText(CStringW& strOut, unsigned nIdx)
{
    if (nIdx >= m_condCancel.FUN_1413886d0())
        return;
    strOut = m_condCancel.FUN_141387b40(nIdx).FUN_141387bb0()->vfunc_7();
}

// @0x1413a3210
void CGuideEntity::StartActions()
{
    for (unsigned i = 0; i < m_actions.FUN_1413886c0(); ++i)
        m_actions.FUN_141387b00(i).FUN_141387ba0()->vfunc_3();
}

// @0x1413a32a0
void CGuideEntity::StopActions()
{
    for (unsigned i = 0; i < m_actions.FUN_1413886c0(); ++i)
        m_actions.FUN_141387b00(i).FUN_141387ba0()->vfunc_4();
}

// @0x1413a3330
int CGuideEntity::AreActionsDone()
{
    for (unsigned i = 0; i < m_actions.FUN_1413886c0(); ++i)
    {
        if (m_actions.FUN_141387b00(i).FUN_141387ba0()->vfunc_5() == 0)
            return 0;
    }
    return 1;
}

// @0x1413a33c0
bool CGuideEntity::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_nId);
    FUN_140873220(pElem, "saveId", m_nSaveId);
    FUN_140873220(pElem, "saveStep", m_nSaveStep);
    XmlGetAttr((class TiXmlElement*)(pElem), "isForce", m_nForce);
    XmlGetAttr((class TiXmlElement*)(pElem), "isNoSave", m_nNoSave);
    if (!FUN_1413a4b50())
        FUN_140873420(pElem, "desc", m_strDesc);
    for (Unk_140165cf0* pChild = FUN_140345b40((class TiXmlDocument*)(pElem)); pChild != 0; pChild = pChild->NextSiblingElement())
    {
        CStringA strName(pChild->Value());
        if (strName == "open")
            LoadConditions(pChild, m_condOpen);
        else if (strName == "close")
            LoadConditions(pChild, m_condClose);
        else if (strName == "cancel")
            LoadConditions(pChild, m_condCancel);
        else if (strName == "openAction")
            LoadActions(pChild, m_actions);
    }
    return true;
}

// @0x1413a35d0
void CGuideEntity::Clear(bool bNotify)
{
    if (m_nState == 1 || m_nState == 2)
        StopActions();
    if (bNotify)
        SetState(0);
    else
        m_nState = 0;
    ResetConditions(m_condOpen);
    ResetConditions(m_condClose);
    ResetConditions(m_condCancel);
}

// @0x1413a3670
void CGuideEntity::SetState(int nState)
{
    m_nState = nState;
    ((class Unk_GeMgr*)FUN_1409331e0())->FUN_14138d7e0(13, 0);
}

// @0x1413a36b0
void CGuideEntity::UpdateConditions()
{
    PruneConditions(m_condOpen);
    PruneConditions(m_condClose);
    PruneConditions(m_condCancel);
}

// @0x1413a3710
void FUN_1413a3710(CGuideEntity* pEntity)
{
}

// @0x1413a3720
void CGuideEntity::MoveStartedConditions()
{
    Unk_GcCondList keep;
    for (unsigned i = 0; i < m_condOpen.FUN_1413886d0(); ++i)
    {
        if (m_condOpen.FUN_141387b40(i).FUN_141387bb0()->m_n18 == 0)
            keep.FUN_141388460(m_condOpen.FUN_141387b40(i));
        else
            m_condTrigger.FUN_141388460(m_condOpen.FUN_141387b40(i));
    }
    GE_REFS(m_condOpen).RemoveAll();
    GE_REFS(m_condOpen).Append(GE_REFS(keep));
}

// @0x1413a3820
void CGuideEntity::CollectTriggerValues(std::map<int, int>& mapValues)
{
    for (unsigned i = 0; i < m_condTrigger.FUN_1413886d0(); ++i)
    {
        int nKind = m_condTrigger.FUN_141387b40(i).FUN_141387bb0()->m_n18;
        if (nKind == 0)
            continue;
        int nValue = m_condTrigger.FUN_141387b40(i).FUN_141387bb0()->vfunc_8();
        std::map<int, int>::iterator it = mapValues.find(nKind);
        if (it == mapValues.end())
            mapValues.insert(std::make_pair(nKind, nValue));
        else
            it->second = 0;
    }
}

// @0x1413a3960
void CGuideEntity::LoadConditions(Unk_140165cf0* pElem, Unk_GcCondList& list)
{
    for (Unk_140165cf0* pCond = pElem->FUN_140165cf0("condition"); pCond != 0; pCond = pCond->FUN_140168650("condition"))
    {
        Unk_GcCondRef ref = FUN_1413a52c0(pCond);
        (void)((FUN_1413a47e0(ref) == 0) || (_wassert(L"condition", _CRT_WIDE(MS2_THIS_FILE), 200), 0));
        if (ref.FUN_141387b90())
            list.FUN_141388460(ref);
    }
}

// @0x1413a3a30
void CGuideEntity::LoadActions(Unk_140165cf0* pElem, Unk_GeActList& list)
{
    for (Unk_140165cf0* pAct = pElem->FUN_140165cf0("action"); pAct != 0; pAct = pAct->FUN_140168650("action"))
    {
        Unk_GeActRef ref = FUN_141382b90(pAct);
        if (FUN_1413a47b0(ref))
            _wassert(L"action", _CRT_WIDE(MS2_THIS_FILE), 212);
        if (ref.FUN_141387ba0() != 0)
            list.FUN_1413883b0(ref);
        ref.FUN_141387630();
    }
}

// @0x1413a3b00
void CGuideEntity::PruneConditions(Unk_GcCondList& list)
{
    Unk_GcCondList keep;
    for (unsigned i = 0; i < list.FUN_1413886d0(); ++i)
    {
        if (!list.FUN_141387b40(i).FUN_141387bb0()->vfunc_6(&keep))
            keep.FUN_141388460(list.FUN_141387b40(i));
    }
    GE_REFS(list).RemoveAll();
    GE_REFS(list).Append(GE_REFS(keep));
}

// @0x1413a3be0
void CGuideEntity::ResetConditions(Unk_GcCondList& list)
{
    for (unsigned i = 0; i < list.FUN_1413886d0(); ++i)
        list.FUN_141387b40(i).FUN_141387bb0()->vfunc_4();
}
