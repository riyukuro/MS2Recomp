// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CQuestMaskTable: QuestMaskPortal.xml / QuestMaskNpc.xml,
// the per-field quest masks of portals and npcs; the unit also holds the game's random generator (Unk_Random).
// MS2-UNIT: ?\questmasktable.cpp
// MS2-RANGE: 0x1400bc3d0-0x1400bc630 .text$di
// MS2-RANGE: 0x140761a40-0x140768690 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetInstance@?$TSingleton@VCQuestMaskTable@@@@SAPEAVCQuestMaskTable@@XZ 0x14109a710 ; unique
// MS2-PIN: ??0?$Unk_BmPtr@VQuestMask@@@@QEAA@PEAVQuestMask@@@Z 0x140765850 ; unique
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$Unk_BmBoxPtr@V?$CAtlMap@IV?$Unk_BmPtr@VQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VQuestMask@@@@@3@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlMap@IV?$Unk_BmPtr@VQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VQuestMask@@@@@3@@ATL@@@@@3@@ATL@@QEAA@II@Z 0x140765980 ; prop
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$Unk_BmPtr@VQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VQuestMask@@@@@3@@ATL@@QEAA@II@Z 0x1407659c0 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$Unk_BmBoxPtr@V?$CAtlMap@IV?$Unk_BmPtr@VQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VQuestMask@@@@@3@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlMap@IV?$Unk_BmPtr@VQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VQuestMask@@@@@3@@ATL@@@@@3@@ATL@@IEAA@I@Z 0x140765a00 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$Unk_BmPtr@VQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VQuestMask@@@@@3@@ATL@@IEAA@I@Z 0x140765a40 ; prop
// MS2-PIN: ?get@?$Unk_BmPtr@VQuestMask@@@@QEBAPEAVQuestMask@@XZ 0x140765c90 ; unique
// MS2-PIN: ??4?$Unk_BmBoxPtr@V?$CAtlMap@IV?$Unk_BmPtr@VQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VQuestMask@@@@@3@@ATL@@@@QEAAAEAV0@AEBUUnk_BmNewTag@@@Z 0x140765f00 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$Unk_BmPtr@VQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VQuestMask@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140766910 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$Unk_BmBoxPtr@V?$CAtlMap@IV?$Unk_BmPtr@VQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VQuestMask@@@@@3@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlMap@IV?$Unk_BmPtr@VQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VQuestMask@@@@@3@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140766b20 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??0?$TSingleton@VCQuestMaskTable@@@@QEAA@XZ 0x140765950
// MS2-PIN: ??1?$TSingleton@VCQuestMaskTable@@@@UEAA@XZ 0x140765b70
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\questmasktable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "questmasktable.h"
#include "filesystem.h"
#include "logstring.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/famegradedata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/randomeffectparam.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class Unk_140165cf0                         // game TinyXML element
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);          // the first child with the name
    Unk_140165cf0* FUN_140168650(const char* pszName);          // the next sibling with the name
};

// Unrecovered helpers.
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);       // Table/<file>
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
bool FUN_14028f710(Unk_140165cf0* pElem);                                   // the node is an element
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int* pOut);
int FUN_140873890(Unk_140165cf0* pElem, const char* pszName, int* pOut);
void FUN_14015f050(const CStringA& str, ATL::CAtlArray<CStringA>* pOut, const char* pszSep);    // split
void FUN_140177de0(const CStringA& str, ATL::CAtlArray<int>* pOut, const char* pszSep);          // split into numbers
Unk_Z16i* FUN_14027dcb0(Unk_Z16i* t);
unsigned FUN_141092fa0(void* pObject);                                      // the key of an npc object
void* FUN_1403ed2d0();                                                      // the map manager
unsigned FUN_141bd3060(void* pMapManager);                                  // the current field id
int FUN_140869420();                                                        // the clock tick (the random seed)

class Unk_SingletonObj;
extern Unk_SingletonObj* DAT_143ab0d58;
extern Unk_SingletonObj* DAT_143ab0d60;

// The quest state of the local player: slot 23 of the interface at +0x10 tells whether a mask is satisfied.
class Unk_QmChecker
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22();
    virtual int IsSatisfied(QuestMask* pMask);                  // 0xb8
};
struct Unk_QmPlayerState
{
    char m_pad_00[0x10];
    Unk_QmChecker m_checker;                                    // +0x10
};

// @0x140764020
void* FUN_140764020()
{
    return DAT_143ab0d58;
}

// @0x140764030
void* FUN_140764030()
{
    return DAT_143ab0d60;
}

// Header statics (the shared list of header_statics_a.h with the random generator in front of the second name table).
#ifndef MS2_HOOK_DLL
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static Unk_Random s_random;
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif

template class TSingleton<CQuestMaskTable>;

// The exe keeps these ATL array members out of line.
template const Unk_Z16i& ATL::CAtlArray<Unk_Z16i>::operator[](size_t) const;
template Unk_Z16i& ATL::CAtlArray<Unk_Z16i>::operator[](size_t);
template void ATL::CAtlArray<int>::RemoveAt(size_t, size_t);

// @0x1407641f0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

#define MS2_QM_XML_ERR L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]"

// @0x140764480
// The state of a quest object against the three conditions of mode nMode: 0 satisfied, 1 pending, 2 not started.
int FUN_140764480(void* pQuest, int nMode);

// @0x140764760
// Two lists "a,b" (start quest / state) and "c,d" (end quest / state) -> one range.
int FUN_140764760(const CStringA& strStart, const CStringA& strEnd, Unk_Z16i* pRange)
{
    ATL::CAtlArray<int> aStart;
    ATL::CAtlArray<int> aEnd;
    FUN_140177de0(strStart, &aStart, ",");
    FUN_140177de0(strEnd, &aEnd, ",");
    if (aStart.GetCount() != aEnd.GetCount())
        return 0;
    if (aStart.GetCount() != 0)
    {
        pRange->a = aStart[0];
        pRange->c = aEnd[0];
    }
    if (aStart.GetCount() > 1)
    {
        pRange->b = aStart[1];
        pRange->d = aEnd[1];
    }
    return 1;
}

// @0x140764310
// "a,b|a,b" / "c,d|c,d" -> one range per pair, appended to the mask.
int FUN_140764310(const CStringA& strStarts, const CStringA& strEnds, QuestMask* pMask)
{
    ATL::CAtlArray<CStringA> aStarts;
    ATL::CAtlArray<CStringA> aEnds;
    FUN_14015f050(strStarts, &aStarts, "|");
    FUN_14015f050(strEnds, &aEnds, "|");
    if (aStarts.GetCount() != aEnds.GetCount())
        return 0;
    for (size_t i = 0; i < aStarts.GetCount(); ++i)
    {
        Unk_Z16i range;
        FUN_14027dcb0(&range);
        if (FUN_140764760(aStarts[i], aEnds[i], &range) != 0)
            pMask->m_aRanges.Add(range);
    }
    return 1;
}

// QuestMask::QuestMask() (0x140266860) is defined by unit_140266860.cpp.

// @0x1407648d0
CQuestMaskTable::CQuestMaskTable()
    : m_npcMasks(17, 0.75f, 0.25f, 2.25f, 10)
    , m_portalMasks(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140764980
CQuestMaskTable::~CQuestMaskTable()
{
}

// @0x1407649d0
bool CQuestMaskTable::Load()
{
    if (!LoadFile(CStringA("QuestMaskPortal.xml"), m_portalMasks))
        return false;
    if (!LoadFile(CStringA("QuestMaskNpc.xml"), m_npcMasks))
        return false;
    return true;
}

// @0x140764a90
Unk_QmMaskPtr CQuestMaskTable::GetPortalMask(unsigned nField, int nKey)
{
    Unk_QmFieldPtr spField(0);
    if (m_portalMasks.Lookup(nField, spField))
    {
        Unk_QmMaskPtr spMask(0);
        if (spField->Lookup(nKey, spMask))
            return spMask;
    }
    return Unk_QmMaskPtr(0);
}

// @0x140764b90
Unk_QmMaskPtr CQuestMaskTable::GetNpcMask(unsigned nField, int nKey)
{
    Unk_QmFieldPtr spField(0);
    if (m_npcMasks.Lookup(nField, spField))
    {
        Unk_QmMaskPtr spMask(0);
        if (spField->Lookup(nKey, spMask))
            return spMask;
    }
    return Unk_QmMaskPtr(0);
}

// @0x140764c90
bool CQuestMaskTable::HasNpcMask(void* pNpc)
{
    if (pNpc == 0)
        return false;
    return HasNpcMaskHere(FUN_141092fa0(pNpc));
}

// @0x140764cd0
bool CQuestMaskTable::HasNpcMaskHere(int nKey)
{
    unsigned nField = FUN_141bd3060(FUN_1403ed2d0());
    Unk_QmMaskPtr spMask = GetNpcMask(nField, nKey);
    return spMask.get() != 0;
}

// @0x140764d50
bool CQuestMaskTable::HasPortalMask(Unk_QmPortal* pPortal)
{
    if (pPortal == 0)
        return false;
    if (pPortal->m_mask.FUN_140266970())
        return true;
    unsigned nField = FUN_141bd3060(FUN_1403ed2d0());
    Unk_QmMaskPtr spMask = GetPortalMask(nField, pPortal->m_nKey);
    return spMask.get() != 0;
}

// @0x140764e00
void CQuestMaskTable::CheckNpcHere(int nKey)
{
    unsigned nField = FUN_141bd3060(FUN_1403ed2d0());
    CheckNpc(nField, nKey);
}

// @0x140764e40
int CQuestMaskTable::CheckNpc(unsigned nField, int nKey)
{
    Unk_QmMaskPtr spMask = GetNpcMask(nField, nKey);
    if (spMask.get() == 0)
        return 1;
    Unk_QmPlayerState* pState = (Unk_QmPlayerState*)FUN_140764020();
    return pState->m_checker.IsSatisfied(spMask.get());
}

// @0x140764ef0
int CQuestMaskTable::CheckNpcObject(void* pNpc)
{
    if (pNpc == 0)
        return 0;
    CheckNpcHere(FUN_141092fa0(pNpc));
    return 0;
}

// @0x140764f30
int CQuestMaskTable::CheckPortal(Unk_QmPortal* pPortal)
{
    if (pPortal == 0)
        return 0;
    if (!HasPortalMask(pPortal))
        return 1;
    if (pPortal->m_mask.FUN_140266970())
    {
        Unk_QmPlayerState* pState = (Unk_QmPlayerState*)FUN_140764020();
        if (pState->m_checker.IsSatisfied((QuestMask*)&pPortal->m_mask) != 0)
            return 1;
    }
    unsigned nField = FUN_141bd3060(FUN_1403ed2d0());
    Unk_QmMaskPtr spMask = GetPortalMask(nField, pPortal->m_nKey);
    if (spMask.get() != 0)
    {
        Unk_QmPlayerState* pState = (Unk_QmPlayerState*)FUN_140764020();
        if (pState->m_checker.IsSatisfied(spMask.get()) != 0)
            return 1;
    }
    return 0;
}

// @0x140765080
// MS2-FUNCTIONAL: XML loader temp layout differs
bool CQuestMaskTable::LoadFile(const CStringA& strFile, Unk_QmFieldMap& rMap)
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString(strFile));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(CLogString::GetInstance(), 1, 0x13, MS2_QM_XML_ERR, strPath);
        return false;
    }
    for (Unk_140165cf0* pField = pRoot->FUN_140165cf0("field"); pField != 0; pField = pField->FUN_140168650("field"))
    {
        int nFieldId = 0;
        FUN_140873220(pField, "fieldID", &nFieldId);
        if (nFieldId != 0)
        {
            Unk_QmFieldPtr spField(0);
            if (!rMap.Lookup(nFieldId, spField))
            {
                spField = Unk_BmNewTag(0);
                rMap.SetAt(nFieldId, spField);
            }
            for (Unk_140165cf0* pKey = pField->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
            {
                int nKey = 0;
                FUN_140873220(pKey, "id", &nKey);
                if (nKey != 0)
                {
                    Unk_QmMaskPtr spMask(new QuestMask);
                    FUN_1408731e0(pKey, "enableInMask", &spMask->m_nEnable);
                    for (Unk_140165cf0* pMask = pKey->FUN_140165cf0("mask"); pMask != 0; pMask = pMask->FUN_140168650("mask"))
                    {
                        if (FUN_14028f710(pMask))
                        {
                            Unk_Z16i range;
                            FUN_14027dcb0(&range);
                            FUN_140873220(pMask, "startQuestID", &range.a);
                            FUN_140873890(pMask, "startQuestState", &range.c);
                            FUN_140873220(pMask, "endQuestID", &range.b);
                            FUN_140873890(pMask, "endQuestState", &range.d);
                            spMask->m_aRanges.Add(range);
                        }
                    }
                    if (spMask->FUN_140266970() != 0)
                        spField->SetAt(nKey, spMask);
                }
            }
        }
    }
    return true;
}

// @0x140768600
static int Unk_RandomStep(int* pState)
{
    int nValue = *pState;
    *pState = *pState * 0x343fd + 0x269ec3;
    return nValue;
}

// @0x140768110
Unk_Random::Unk_Random()
{
    int nSeed = FUN_140869420() + rand();
    unsigned s1 = Unk_RandomStep(&nSeed);
    unsigned s2 = Unk_RandomStep(&nSeed);
    unsigned s3 = Unk_RandomStep(&nSeed);
    SetState(s1, s2, s3);
}

// @0x1407681b0
Unk_Random::Unk_Random(const Unk_Random& o)
{
    m_s1 = o.m_s1;
    m_s2 = o.m_s2;
    m_s3 = o.m_s3;
}

// @0x140768210
Unk_Random::Unk_Random(int nSeed)
{
    unsigned s1 = Unk_RandomStep(&nSeed);
    unsigned s2 = Unk_RandomStep(&nSeed);
    unsigned s3 = Unk_RandomStep(&nSeed);
    SetState(s1, s2, s3);
}

// @0x140768290
Unk_Random::Unk_Random(unsigned s1, unsigned s2, unsigned s3)
{
    SetState(s1, s2, s3);
}

// @0x1407682f0
void Unk_Random::Seed(int nSeed)
{
    unsigned s1 = Unk_RandomStep(&nSeed);
    unsigned s2 = Unk_RandomStep(&nSeed);
    unsigned s3 = Unk_RandomStep(&nSeed);
    SetState(s1, s2, s3);
}

// @0x140768350
void Unk_Random::SetState(unsigned s1, unsigned s2, unsigned s3)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_s1 = s1 | 0x100000;
    m_s2 = s2 | 0x1000;
    m_s3 = s3 | 0x10;
}

// @0x1407683d0
void Unk_Random::GetState(unsigned* s1, unsigned* s2, unsigned* s3)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    *s1 = m_s1;
    *s2 = m_s2;
    *s3 = m_s3;
}

// @0x140768450
void Unk_Random::SetRaw(unsigned s1, unsigned s2, unsigned s3)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_s1 = s1;
    m_s2 = s2;
    m_s3 = s3;
}

// @0x1407684c0
unsigned Unk_Random::FUN_1407684c0()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_s1 = (m_s1 & 0xfffffffe) << 12 ^ (m_s1 << 13 ^ m_s1) >> 19;
    m_s2 = (m_s2 & 0xfffffff8) << 4 ^ (m_s2 << 2 ^ m_s2) >> 25;
    m_s3 = (m_s3 & 0xfffffff0) << 17 ^ (m_s3 << 3 ^ m_s3) >> 11;
    return m_s1 ^ m_s2 ^ m_s3;
}

// @0x1407685b0
int Unk_Random::Range(unsigned nCount, int nBase)
{
    if (nCount != 0)
        nBase += (int)((unsigned long long)FUN_1407684c0() % nCount);
    return nBase;
}

#ifndef MS2_HOOK_DLL
// @0x140768010
int FUN_140768010(int nCount, int nBase)
{
    return s_random.Range(nCount, nBase);
}

// @0x140768040
bool FUN_140768040(unsigned nChance)
{
    bool bHit = (unsigned)FUN_140768010(10000, 0) < nChance;
    return bHit;
}

// @0x140768090
float FUN_140768090()
{
    union { unsigned u; float f; } v;
    v.u = s_random.FUN_1407684c0() & 0x7fffff | 0x3f800000;
    return v.f - 1.0f;
}
#endif

// @0x1407680d0
float FUN_1407680d0(Unk_Random* pRandom)
{
    union { unsigned u; float f; } v;
    v.u = pRandom->FUN_1407684c0() & 0x7fffff | 0x3f800000;
    return v.f - 1.0f;
}

// @0x140768640
int FUN_140768640(Unk_Random* pRandom, unsigned nCount, int nBase)
{
    int nResult;
    if (nCount != 0)
        nResult = nBase + pRandom->FUN_1407684c0() % nCount;
    else
        nResult = nBase;
    return nResult;
}

// @0x140765520
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
int FUN_140765520(Unk_140165cf0* pElem, const char* pszName, int* pnOut)
{
    if (FALSE) {
        MS2_ASSERT_AT(0xe7, FALSE);
        return 2;
    }
    int nValue = 0;
    int nResult = FUN_140873890(pElem, pszName, &nValue);
    if (nResult != 0)
        return nResult;
    *pnOut = nValue;
    return nResult;
}
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\questmasktable.cpp"

// The fame table's getter (the exe types it Unk_EmoNpcTable).
class Unk_EmoNpcTable;
Unk_EmoNpcTable* FUN_140764010();
static inline CFameTable* FameTable()
{
    return reinterpret_cast<CFameTable*>(FUN_140764010());
}
class CQuestData;
int FUN_14074b050(CQuestData* pData);
int FUN_14074b070(CQuestData* pData);
int FUN_140931210(int n);
CStringW FUN_140298ea0(CStringW str);
CString FUN_14021a6b0(int n);
CStringW FUN_14028b8e0(const CStringW& str);
CStringW FUN_140719630(int n);
CStringW FUN_14083cb20(const CStringW& str);

// @0x140762280
int FUN_140762280(void* pUnused, int n)
{
    return FUN_140931210(n);
}

// @0x140762de0
CStringW FUN_140762de0(int nQuestId)
{
    return FUN_14028b8e0(StringFormat(L"s_quest_alliance_{0}", FUN_14021a6b0(nQuestId)));
}

// @0x140762e90
CString FUN_140762e90(int nAlliance)
{
    return FameTable()->GetSymbol((Unk_FameAlliance)nAlliance);
}

// @0x140762ee0
CStringW FUN_140762ee0(int nAlliance, int nPoint);

// @0x140762f50
CStringW FUN_140762f50(int nAlliance, int nGrade)
{
    return FUN_140298ea0(StringFormat(L"s_fame_grade_{0}", nGrade));
}

CStringW FUN_140762ee0(int nAlliance, int nPoint)
{
    int nGrade = FameTable()->GetGradeByPoint((Unk_FameAlliance)nAlliance, nPoint);
    return FUN_140762f50(nAlliance, nGrade);
}

// @0x1407631e0
int FUN_1407631e0(int nAlliance)
{
    return FameTable()->IsExped((Unk_FameAlliance)nAlliance);
}

// @0x1407636c0
int FUN_1407636c0(int nNpcId)
{
    return FameTable()->GetAllianceByNpc(nNpcId);
}

// @0x140763e10
CStringW FUN_140763e10(int nValue)
{
    return FUN_14083cb20(FUN_140719630(nValue));
}

// @0x140764040
bool FUN_140764040(CQuestData* pData)
{
    return FUN_14074b050(pData) == 0;
}

// @0x140764080
bool FUN_140764080(CQuestData* pData)
{
    return FUN_14074b050(pData) == 2;
}

// @0x1407640c0
bool FUN_1407640c0(CQuestData* pData)
{
    return FUN_14074b070(pData) != 0;
}
