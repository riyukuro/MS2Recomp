// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-condition base class CGuideCondition and the conditions
// False / Trigger / Timeout (part 9 of client\ms2\guideentity.cpp, the class tail). See ms2/placeholder/cguidecondition.h.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: client\ms2\guideentity.cpp#9
// MS2-RANGE: 0x1413a2c00-0x1413a3c60 .text$mn
// MS2-RANGE: 0x1413a3c60-0x1413a4960 .text$mn
// MS2-RANGE: 0x1413a49a0-0x1413a5130 .text$mn
// MS2-RANGE: 0x1413a5130-0x1413a54e0 .text$mn
// MS2-RANGE: 0x1413a54e0-0x1413a6010 .text$mn
// MS2-RANGE: 0x1413b2880-0x1413b28e0 .text$mn
// MS2-RANGE: 0x1413b4200-0x1413b4240 .text$mn
// MS2-RANGE: 0x1413b5380-0x1413b53c0 .text$mn
// MS2-RANGE: 0x1413b5400-0x1413b5440 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\guideentity.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <exception>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/client/ms2/guideentity.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/placeholder/cguideaction.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
#include "ms2/placeholder/tixmlelement.h"   // C3: was a local TiXml view; the shared reduced view has the same names
//
//
//
//
// (TiXmlNode::NextSiblingElement(): in the shared view above; the non-const 0x1403f0510 wrapper is the exe callee)
int FUN_1413b1d00(TiXmlElement* pElem, const char* pszName, Unk_GcOptInt& oOut);
int FUN_1413b1fc0(TiXmlElement* pElem, const char* pszName, int& nOut);
void FUN_1412751b0(const CStringW& text, int a);                        // the debug log

struct Unk_MergeRange;
bool FUN_1405c7ba0(const Unk_MergeRange* pRange);                          // is set
int FUN_1413b1d60(class TiXmlElement*, char const*, void*);   // C3: was FUN_1413b1d60
class Unk_ImNullableInt   // C3: member view for the former free stand-ins
{
public:
    bool HasValue() const;
};
const int* FUN_1413989f0(const Unk_GcOptInt* pOpt);                     // Nullable<int>::GetValue
Unk_GcOptInt* FUN_140d11940(Unk_GcOptInt* pOpt);                        // Nullable<int>()

class TiXmlElement* FUN_140345b40(class TiXmlDocument*);   // C3: was FUN_140345b40
MS2Ptr<CGuideCondition> FUN_1413a5420(CStringA strTag);                 // the condition class of a tag
void* FUN_141395500(void* pNode);
// The condition / action lists hold 16-byte handles (the shared placeholder declares them as pointer arrays).
#define GE_REFS(list) ((list).m_arr)
// The condition lists are the exe's CAtlArray<MS2Ptr<CGuideCondition>> (count / [] / Add are its members).
#define GE_CONDS(list) reinterpret_cast<ATL::CAtlArray<MS2Ptr<CGuideCondition> >&>(list)   // m_arr is at +0

// The guide manager: the trigger events that were raised.
class Unk_GeMgr
{
public:
    bool FUN_14138c210(int nTrigger, const Unk_MergeRange& range);
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
// (0x141397130 is the _Tree_iterator<pair<const CGuideManager::Occurrence, int>>(_Nodeptr, const _Mytree*) ctor)
void* FUN_14139e9f0(void* pMap);                                        // the node allocator
Unk_GeNode** FUN_14139f960(Unk_GeTreeHead* pHead);                      // the root
Unk_GeNode** FUN_14139eee0(Unk_GeTreeHead* pHead);                      // the leftmost
Unk_GeNode** FUN_14139f8e0(Unk_GeTreeHead* pHead);                      // the rightmost
void FUN_14139eff0(Unk_GeTreeHead* pHead, Unk_GeNode* pNode);           // rotate left
void FUN_14139faa0(Unk_GeTreeHead* pHead, Unk_GeNode* pNode);           // rotate right
typedef std::_Tree<std::_Tmap_traits<int, int, std::less<int>, std::allocator<std::pair<const int, int>>, false>> Unk_GeTree; struct Unk_GeTreeAccess : Unk_GeTree { static Unk_GeIter* FUN_1413a3e00(void* pMap, Unk_GeIter* pOut, bool bLeft, Unk_GeNode* pWhere, const int& rKey, Unk_GeNode* pNode); };   // protected _Destroy_if_node (was FUN_1413a4e30)
void* FUN_141398a90(void* pIter);
void* FUN_1413a4830(void* pIter);                                       // map<int,int> iterator operator* (out of line, calls the const one)
unsigned __int64 FUN_1413a5140(void* pMap);
void* FUN_1413a5160(void* pNode);

// @0x1413a3d00
std::pair<int, int>* FUN_1413a3d00(std::pair<int, int>* pDst, const std::pair<int, int>* pSrc)
{
    pDst->first = std::forward<CGuideManager::Occurrence>(*(CGuideManager::Occurrence*)&pSrc->first);
    pDst->second = std::forward<int>(*(int*)&pSrc->second);
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
Unk_GeIter* Unk_GeTreeAccess::FUN_1413a3e00(void* pMap, Unk_GeIter* pOut, bool bLeft, Unk_GeNode* pWhere, const int& rKey, Unk_GeNode* pNode)
{
    Unk_GeTreeHead* pHead = ((struct Unk_GeTreeHead*)&((std::_Tree_comp_alloc<std::_Tmap_traits<int, int, std::less<int>, std::allocator<std::pair<int const, int>>, 0>>*)(void*)(pMap))->_Get_data());
    if (FUN_1413a5140(pMap) - 1 <= pHead->m_nSize)
    {
        reinterpret_cast<Unk_GeTreeAccess*>(pMap)->_Destroy_if_node(reinterpret_cast<Unk_GeTree::_Nodeptr>(pNode));
        std::_Xlength_error("map/set<T> too long");
    }
    Unk_GeNode* pNew = FUN_1413a3d50(pMap, pNode, FUN_1413a46e0(rKey));
    pHead->m_nSize = pHead->m_nSize + 1;
    pNew->m_pParent = pWhere;
    if (pWhere == pHead->m_pHead)
    {
        reinterpret_cast<Unk_GeNode*&>(((std::_Tree_val<std::_Tree_simple_types<long>>*)pHead)->_Root()) = pNew;
        reinterpret_cast<Unk_GeNode*&>(((std::_Tree_val<std::_Tree_simple_types<std::pair<CStringA const, int>>>*)pHead)->_Lmost()) = pNew;
        reinterpret_cast<Unk_GeNode*&>(((std::_Tree_val<std::_Tree_simple_types<long>>*)pHead)->_Rmost()) = pNew;
    }
    else if (bLeft)
    {
        pWhere->m_pLeft = pNew;
        if (pWhere == reinterpret_cast<Unk_GeNode*&>(((std::_Tree_val<std::_Tree_simple_types<std::pair<CStringA const, int>>>*)pHead)->_Lmost()))
            reinterpret_cast<Unk_GeNode*&>(((std::_Tree_val<std::_Tree_simple_types<std::pair<CStringA const, int>>>*)pHead)->_Lmost()) = pNew;
    }
    else
    {
        pWhere->m_pRight = pNew;
        if (pWhere == reinterpret_cast<Unk_GeNode*&>(((std::_Tree_val<std::_Tree_simple_types<long>>*)pHead)->_Rmost()))
            reinterpret_cast<Unk_GeNode*&>(((std::_Tree_val<std::_Tree_simple_types<long>>*)pHead)->_Rmost()) = pNew;
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
                    ((std::_Tree_val<std::_Tree_simple_types<long>>*)pHead)->_Lrotate((std::_Tree_node<long, void*>*)(pCur));
                }
                pCur->m_pParent->m_cColor = 1;
                pCur->m_pParent->m_pParent->m_cColor = 0;
                ((std::_Tree_val<std::_Tree_simple_types<long>>*)pHead)->_Rrotate((std::_Tree_node<long, void*>*)(pCur->m_pParent->m_pParent));
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
                    ((std::_Tree_val<std::_Tree_simple_types<long>>*)pHead)->_Rrotate((std::_Tree_node<long, void*>*)(pCur));
                }
                pCur->m_pParent->m_cColor = 1;
                pCur->m_pParent->m_pParent->m_cColor = 0;
                ((std::_Tree_val<std::_Tree_simple_types<long>>*)pHead)->_Lrotate((std::_Tree_node<long, void*>*)(pCur->m_pParent->m_pParent));
            }
        }
    }
    reinterpret_cast<Unk_GeNode*&>(((std::_Tree_val<std::_Tree_simple_types<long>>*)pHead)->_Root())->m_cColor = 1;
    reinterpret_cast<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CGuideManager::Occurrence const, int>>>>*>(pOut)->std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CGuideManager::Occurrence const, int>>>>::_Tree_iterator((std::_Tree_node<std::pair<CGuideManager::Occurrence const, int>, void*>*)pNew, std::addressof(*(std::_Tree_val<std::_Tree_simple_types<std::pair<CGuideManager::Occurrence const, int>>>*)pHead));
    return pOut;
}

// @0x1413a4620
void FUN_1413a4620(void* pAlloc, std::pair<int, int>* pDst, const std::pair<int, int>& rVal)
{
    void* pNew = ::operator new(8, pDst);
    FUN_1413a3d00(static_cast<std::pair<int, int>*>(pNew), &std::forward<const std::pair<int, int>&>(rVal));
}

// @0x1413a47b0
bool FUN_1413a47b0(const MS2Ptr<CGuideAction>& ref)
{
    struct Layout { void* m_unk_00; CGuideAction* m_p; };   // MS2Ptr (m_p is private)
    return reinterpret_cast<const Layout&>(ref).m_p == 0;
}

// @0x1413a47e0
bool FUN_1413a47e0(const MS2Ptr<CGuideCondition>& ref)
{
    struct Layout { void* m_unk_00; CGuideCondition* m_p; };   // MS2Ptr (m_p is private)
    return reinterpret_cast<const Layout&>(ref).m_p == 0;
}

// @0x1413a4810
void* FUN_1413a4810(void* pIter)
{
    return FUN_1413a5160(FUN_1413a4830(pIter));
}

// @0x1413a4830
void* FUN_1413a4830(void* pIter)
{
    return (void*)&**(std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CGuideManager::Occurrence const, int>>>>*)pIter;
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
    return std::addressof(*(std::pair<CGuideManager::Occurrence const, int>*)pNode);
}

// @0x1413a5180
errno_t FUN_1413a5180(void* pDst, size_t nDstSize, const void* pSrc, size_t nCount)
{
    if (nCount == 0)
        return 0;
    { int _Expr_val = !!(pDst != NULL); if (!(_Expr_val)) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int _Expr_val = !!(pSrc != NULL); if (!(_Expr_val)) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int _Expr_val = !!(nDstSize >= nCount); if (!(_Expr_val)) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memmove(pDst, pSrc, nCount);
    return 0;
}

// @0x1413a52a0
tm* FUN_1413a52a0(const __time64_t* pTime)
{
    return _localtime64(pTime);
}

// @0x1413a52c0
MS2Ptr<CGuideCondition> FUN_1413a52c0(TiXmlElement* pElem)
{
    CStringA strTag(((class TiXmlElement*)(class TiXmlElement*)(pElem))->Attribute("type"));
    MS2Ptr<CGuideCondition> ref = FUN_1413a5420(strTag);
    if (ref.get())
        ref->vfunc_2(pElem);
    else
        throw std::exception(StringFormat<CStringA>("Unknown Guide Condition Tag({0})", strTag));
    return ref;
}

// @0x1413a5420
MS2Ptr<CGuideCondition> FUN_1413a5420(CStringA strTag)
{
    CStringW strClass = StringFormat<CStringA>(L"CGuideCondition{0}", strTag);
    MS2Ptr<CGuideCondition> ref(static_cast<CGuideCondition*>(FUN_1401f7f50(strClass)));
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
void CGuideCondition::vfunc_2(TiXmlElement* pElem)
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
void CGuideConditionTrigger::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1413b1fc0(pElem, "trigger", m_n28);
    FUN_1413b1d00(pElem, "value", m_a);
    FUN_1413b1d00(pElem, "subValue", m_b);
    if (((class TiXmlElement*)(class TiXmlElement*)(pElem))->Attribute("range") != 0)
        FUN_1413b1d60(pElem, "range", (void*)(&m_range));
    if (m_n28 == 0)
        throw std::exception("Unknown Guide Trigger Tag");
}

// @0x1413a5bb0
int CGuideConditionTrigger::vfunc_3()
{
    if (FUN_1405c7ba0((const Unk_MergeRange*)&m_range))
        return FUN_1413a55a0(((class Unk_GeMgr*)FUN_1409331e0())->FUN_14138c210(m_n28, m_range) != 0);
    return FUN_1413a55a0(((class CGuideManager*)FUN_1409331e0())->CheckTrigger((CGuideManager::TriggerType)m_n28, m_a, m_b) != 0);
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
    for (unsigned i = 0; i < GE_CONDS(m_condTrigger).GetCount(); ++i)
    {
        if (FUN_1413a5570(GE_CONDS(m_condTrigger)[i].operator->()) == 0)
        {
            if (pnFailed != 0)
                *pnFailed = i;
            *pbOpen = true;
            return 0;
        }
    }
    for (unsigned i = 0; i < GE_CONDS(m_condOpen).GetCount(); ++i)
    {
        if (FUN_1413a5570(GE_CONDS(m_condOpen)[i].operator->()) == 0)
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
    for (unsigned i = 0; i < GE_CONDS(m_condClose).GetCount(); ++i)
    {
        if (FUN_1413a5570(GE_CONDS(m_condClose)[i].operator->()) == 0)
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
    for (unsigned i = 0; i < GE_CONDS(m_condCancel).GetCount(); ++i)
    {
        if (FUN_1413a5570(GE_CONDS(m_condCancel)[i].operator->()) == 0)
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
    if (bTrigger)
    {
        if (nIdx >= GE_CONDS(m_condTrigger).GetCount())
            return;
        strOut = GE_CONDS(m_condTrigger)[nIdx]->vfunc_7();
    }
    else
    {
        if (nIdx >= GE_CONDS(m_condOpen).GetCount())
            return;
        strOut = GE_CONDS(m_condOpen)[nIdx]->vfunc_7();
    }
}

// @0x1413a30a0
void CGuideEntity::GetCloseText(CStringW& strOut, unsigned nIdx)
{
    if (nIdx >= GE_CONDS(m_condClose).GetCount())
        return;
    strOut = GE_CONDS(m_condClose)[nIdx]->vfunc_7();
}

// @0x1413a3150
void CGuideEntity::GetCancelText(CStringW& strOut, unsigned nIdx)
{
    if (nIdx >= GE_CONDS(m_condCancel).GetCount())
        return;
    strOut = GE_CONDS(m_condCancel)[nIdx]->vfunc_7();
}

// @0x1413a3210
void CGuideEntity::StartActions()
{
    for (unsigned i = 0; i < m_actions.GetCount(); ++i)
        m_actions[i]->vfunc_3();
}

// @0x1413a32a0
void CGuideEntity::StopActions()
{
    for (unsigned i = 0; i < m_actions.GetCount(); ++i)
        m_actions[i]->vfunc_4();
}

// @0x1413a3330
int CGuideEntity::AreActionsDone()
{
    for (unsigned i = 0; i < m_actions.GetCount(); ++i)
    {
        if (m_actions[i]->vfunc_5() == 0)
            return 0;
    }
    return 1;
}

// @0x1413a33c0
bool CGuideEntity::Load(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "id", m_nId);
    XmlGetAttr((class TiXmlElement*)(pElem), "saveId", m_nSaveId);
    XmlGetAttr((class TiXmlElement*)(pElem), "saveStep", m_nSaveStep);
    XmlGetAttr((class TiXmlElement*)(pElem), "isForce", m_nForce);
    XmlGetAttr((class TiXmlElement*)(pElem), "isNoSave", m_nNoSave);
    if (!FUN_1413a4b50())
        XmlGetAttr((class TiXmlElement*)(pElem), "desc", m_strDesc);
    for (TiXmlElement* pChild = FUN_140345b40((class TiXmlDocument*)(pElem)); pChild != 0; pChild = (TiXmlElement*)((const TiXmlNode*)pChild)->NextSiblingElement())
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
    ((class CGuideManager*)FUN_1409331e0())->QueueOccurrence((CGuideManager::Occurrence)13, 0);
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
    for (unsigned i = 0; i < GE_CONDS(m_condOpen).GetCount(); ++i)
    {
        if (GE_CONDS(m_condOpen)[i]->m_n18 != 0)
            GE_CONDS(m_condTrigger).Add(GE_CONDS(m_condOpen)[i]);
        else
            GE_CONDS(keep).Add(GE_CONDS(m_condOpen)[i]);
    }
    GE_REFS(m_condOpen).RemoveAll();
    GE_REFS(m_condOpen).Append(GE_REFS(keep));
}

// @0x1413a3820
void CGuideEntity::CollectTriggerValues(std::map<int, int>& mapValues)
{
    for (unsigned i = 0; i < GE_CONDS(m_condTrigger).GetCount(); ++i)
    {
        int nKind = GE_CONDS(m_condTrigger)[i]->m_n18;
        if (nKind == 0)
            continue;
        int nValue = GE_CONDS(m_condTrigger)[i]->vfunc_8();
        std::map<int, int>::iterator it = mapValues.find(nKind);
        if (it == mapValues.end())
            mapValues.insert(std::make_pair(nKind, nValue));
        else
            it->second = 0;
    }
}

// @0x1413a3960
void CGuideEntity::LoadConditions(TiXmlElement* pElem, Unk_GcCondList& list)
{
    for (TiXmlElement* pCond = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("condition")); pCond != 0; pCond = ((class TiXmlElement*)((class Unk_XmlNode*)(pCond))->NextSibling("condition")))
    {
        MS2Ptr<CGuideCondition> ref = FUN_1413a52c0(pCond);
        (void)((FUN_1413a47e0(ref) == 0) || (_wassert(L"condition", _CRT_WIDE(MS2_THIS_FILE), 200), 0));
        if (ref.get())
            GE_CONDS(list).Add(ref);
    }
}

// @0x1413a3a30
void CGuideEntity::LoadActions(TiXmlElement* pElem, CAtlArray<MS2Ptr<CGuideAction> >& list)
{
    for (TiXmlElement* pAct = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("action")); pAct != 0; pAct = ((class TiXmlElement*)((class Unk_XmlNode*)(pAct))->NextSibling("action")))
    {
        MS2Ptr<CGuideAction> ref = FUN_141382b90(pAct);
        (void)((FUN_1413a47b0(ref) == 0) || (_wassert(L"action", _CRT_WIDE(MS2_THIS_FILE), 212), 0));
        if (ref.operator->())
            list.Add(ref);
    }
}

// @0x1413a3b00
void CGuideEntity::PruneConditions(Unk_GcCondList& list)
{
    Unk_GcCondList keep;
    for (unsigned i = 0; i < GE_CONDS(list).GetCount(); ++i)
    {
        if (!GE_CONDS(list)[i]->vfunc_6(&keep))
            GE_CONDS(keep).Add(GE_CONDS(list)[i]);
    }
    GE_CONDS(list).RemoveAll();
    GE_CONDS(list).Append(GE_REFS(keep));
}

// @0x1413a3be0
void CGuideEntity::ResetConditions(Unk_GcCondList& list)
{
    for (unsigned i = 0; i < GE_CONDS(list).GetCount(); ++i)
        GE_CONDS(list)[i]->vfunc_4();
}
// MS2-PIN: ?FUN_1413a3e00@Unk_GeTreeAccess@@SAPEAUUnk_GeIter@@PEAXPEAU2@_NPEAUUnk_GeNode@@AEBH3@Z 0x1413a3e00 ; _Insert_at stand-in, a static member of a _Tree<map<int,int>> view for the protected _Destroy_if_node
