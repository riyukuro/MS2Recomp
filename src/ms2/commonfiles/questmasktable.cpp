// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CQuestMaskTable: QuestMaskPortal.xml / QuestMaskNpc.xml,
// the per-field quest masks of portals and npcs; the unit also holds the game's random generator (Unk_Random).
// MS2-UNIT: ?\questmasktable.cpp
// MS2-RANGE: 0x1400bc3d0-0x1400bc630 .text$di
// MS2-RANGE: 0x140761a40-0x140768690 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetInstance@?$TSingleton@VCQuestMaskTable@@@@SAPEAVCQuestMaskTable@@XZ 0x14109a710 ; unique
// MS2-PIN: ??0?$TPtr@UQuestMask@@@@QEAA@PEAUQuestMask@@@Z 0x140765850 ; unique
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$Unk_BmBoxPtr@V?$CAtlMap@IV?$TPtr@UQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtr@UQuestMask@@@@@3@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlMap@IV?$TPtr@UQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtr@UQuestMask@@@@@3@@ATL@@@@@3@@ATL@@QEAA@II@Z 0x140765980 ; prop
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$TPtr@UQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtr@UQuestMask@@@@@3@@ATL@@QEAA@II@Z 0x1407659c0 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$Unk_BmBoxPtr@V?$CAtlMap@IV?$TPtr@UQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtr@UQuestMask@@@@@3@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlMap@IV?$TPtr@UQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtr@UQuestMask@@@@@3@@ATL@@@@@3@@ATL@@IEAA@I@Z 0x140765a00 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$TPtr@UQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtr@UQuestMask@@@@@3@@ATL@@IEAA@I@Z 0x140765a40 ; prop
// MS2-PIN: ?get@?$TPtr@UQuestMask@@@@QEBAPEAUQuestMask@@XZ 0x140765c90 ; unique
// MS2-PIN: ??4?$Unk_BmBoxPtr@V?$CAtlMap@IV?$TPtr@UQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtr@UQuestMask@@@@@3@@ATL@@@@QEAAAEAV0@AEBUUnk_BmNewTag@@@Z 0x140765f00 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$TPtr@UQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtr@UQuestMask@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140766910 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$Unk_BmBoxPtr@V?$CAtlMap@IV?$TPtr@UQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtr@UQuestMask@@@@@3@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlMap@IV?$TPtr@UQuestMask@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$TPtr@UQuestMask@@@@@3@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140766b20 ; unique
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
#include <vector>
#include <algorithm>
#include "ms2/placeholder/questdata.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/commonfiles/rewardcontentstable.h"
#include "ms2/commonfiles/exptable.h"
#include "ms2/commonfiles/luautil.h"
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/placeholder/cgloabalfactor.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/placeholder/coutpacket.h"
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
class Unk_QmWorld;
Unk_QmWorld* FUN_1403ed2d0();                                               // the world (map manager)
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
    return (&pState->m_checker)->IsSatisfied(spMask.get());
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
        if ((&pState->m_checker)->IsSatisfied((QuestMask*)&pPortal->m_mask) != 0)
            return 1;
    }
    unsigned nField = FUN_141bd3060(FUN_1403ed2d0());
    Unk_QmMaskPtr spMask = GetPortalMask(nField, pPortal->m_nKey);
    if (spMask.get() != 0)
    {
        Unk_QmPlayerState* pState = (Unk_QmPlayerState*)FUN_140764020();
        if ((&pState->m_checker)->IsSatisfied(spMask.get()) != 0)
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
extern Unk_EmoNpcTable* DAT_143aaeb10;
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

// ---- The quest reward / description helpers (0x140761ba0-0x140764010; names invented from use).

// The world and the local player as these helpers use them: the level is PCBase slot 78 (0x270).
class Unk_QmPlayer
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27();
    virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31();
    virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35();
    virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43();
    virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47();
    virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51();
    virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55();
    virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63();
    virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
    virtual void vfunc_68(); virtual void vfunc_69(); virtual void vfunc_70(); virtual void vfunc_71();
    virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75();
    virtual void vfunc_76(); virtual void vfunc_77();
    virtual unsigned short vfunc_78();                          // the level
};
class Unk_QmWorld
{
public:
    Unk_QmPlayer* FUN_141bd0cc0();                              // the local player (NULL outside the field)
};
CGuildManager* FUN_1403ed290();
CGuildXmlData* FUN_1404f4530();
CGloabalFactor* FUN_140302b10();
CExpTable* FUN_1404a1bb0();
CLua* FUN_1401c0db0();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);                 // the quest table row (NULL when unknown)
bool FUN_14028d470(float a, float b);                           // a == b within epsilon
__int64 FUN_140632990(__int64 nValue, float fAdd);              // the Lua bonus added to an exp value
void FUN_1402929a0(const CStringW& str, std::vector<unsigned>& out, const wchar_t* pszSep);    // split into ids
CStringW FUN_14028de60(int nStringId);                          // a common string by id
CStringW FUN_1416e4df0(int nQuestId);                           // the quest's localized name
int FUN_140768010(int nCount, int nBase);

// The reward calculation context of the per-kind readers below (all fill m_value and m_bonus).
struct Unk_QuestRewardCalc
{
    Unk_QuestRewardCalc();
    int m_enabled;                      // +0x00 ctor 1: 0 = the reward is not paid (value 0)
    unsigned short m_level;             // +0x04 the local player's level
    unsigned short m_guildNpcLevel;     // +0x06 the guild's npc level (CGuildInfo key 6)
    __int64 m_value;                    // +0x08
    float m_bonus;                      // +0x10 the result is m_value * (1 + m_bonus)
};
MS2_CHECK_SIZE(Unk_QuestRewardCalc, 0x18);

void FUN_1407622b0(int nQuestId, Unk_QuestRewardCalc& calc);
void FUN_140762500(int nQuestId, Unk_QuestRewardCalc& calc);
void FUN_1407627a0(int nQuestId, Unk_QuestRewardCalc& calc);
void FUN_1407628a0(int nQuestId, Unk_QuestRewardCalc& calc);
void FUN_1407629a0(int nQuestId, Unk_QuestRewardCalc& calc);
void FUN_140762aa0(int nQuestId, Unk_QuestRewardCalc& calc);
void FUN_140762b40(int nQuestId, Unk_QuestRewardCalc& calc);
void FUN_140762be0(int nQuestId, Unk_QuestRewardCalc& calc);
void FUN_140762c80(int nQuestId, Unk_QuestRewardCalc& calc);
void FUN_140763210(int nQuestId, int nState, CStringW& strDesc, CStringW& strFormat);
void FUN_140763790(int nCount, ATL::CAtlArray<MS2Ptr<CQuestData> >& input, ATL::CAtlArray<MS2Ptr<CQuestData> >& output);

// @0x140761ba0
__int64 FUN_140761ba0(int nQuestId, int bEnabled)
{
    Unk_QuestRewardCalc calc;
    calc.m_enabled = bEnabled;
    FUN_140762500(nQuestId, calc);
    return (__int64)((float)calc.m_value * (1.0f + calc.m_bonus));
}
MS2_REPLACE(0x140761ba0, FUN_140761ba0, 79, 0x90D7AD6D);

// @0x140761c00
__int64 FUN_140761c00(int nQuestId, int bEnabled)
{
    Unk_QuestRewardCalc calc;
    calc.m_enabled = bEnabled;
    FUN_1407628a0(nQuestId, calc);
    return (__int64)((float)calc.m_value * (1.0f + calc.m_bonus));
}
MS2_REPLACE(0x140761c00, FUN_140761c00, 79, 0x12D9C77B);

// @0x140761c60
int FUN_140761c60(int nQuestId, int bEnabled)
{
    Unk_QuestRewardCalc calc;
    calc.m_enabled = bEnabled;
    FUN_1407629a0(nQuestId, calc);
    return (int)((float)calc.m_value * (1.0f + calc.m_bonus));
}
MS2_REPLACE(0x140761c60, FUN_140761c60, 78, 0x77D029ED);

// @0x140761cc0
__int64 FUN_140761cc0(int nQuestId, int bEnabled)
{
    Unk_QuestRewardCalc calc;
    calc.m_enabled = bEnabled;
    FUN_1407622b0(nQuestId, calc);
    return (__int64)((float)calc.m_value * (1.0f + calc.m_bonus));
}
MS2_REPLACE(0x140761cc0, FUN_140761cc0, 79, 0x22C87218);

// @0x140761d20
__int64 FUN_140761d20(int nQuestId, int bEnabled)
{
    Unk_QuestRewardCalc calc;
    calc.m_enabled = bEnabled;
    FUN_1407627a0(nQuestId, calc);
    return (__int64)((float)calc.m_value * (1.0f + calc.m_bonus));
}
MS2_REPLACE(0x140761d20, FUN_140761d20, 79, 0xABFDEDCF);

// @0x140761d80
__int64 FUN_140761d80(int nQuestId, int bEnabled)
{
    Unk_QuestRewardCalc calc;
    calc.m_enabled = bEnabled;
    FUN_140762aa0(nQuestId, calc);
    return (__int64)((float)calc.m_value * (1.0f + calc.m_bonus));
}
MS2_REPLACE(0x140761d80, FUN_140761d80, 79, 0xF209A484);

// @0x140761de0
__int64 FUN_140761de0(int nQuestId, int bEnabled)
{
    Unk_QuestRewardCalc calc;
    calc.m_enabled = bEnabled;
    FUN_140762b40(nQuestId, calc);
    return (__int64)((float)calc.m_value * (1.0f + calc.m_bonus));
}
MS2_REPLACE(0x140761de0, FUN_140761de0, 79, 0x2F5DDB5A);

// @0x140761e40
int FUN_140761e40(int nQuestId, int bEnabled)
{
    Unk_QuestRewardCalc calc;
    calc.m_enabled = bEnabled;
    FUN_140762be0(nQuestId, calc);
    return (int)((float)calc.m_value * (1.0f + calc.m_bonus));
}
MS2_REPLACE(0x140761e40, FUN_140761e40, 78, 0x3495E8AC);

// @0x140761ea0
int FUN_140761ea0(int nQuestId, int bEnabled)
{
    Unk_QuestRewardCalc calc;
    calc.m_enabled = bEnabled;
    FUN_140762c80(nQuestId, calc);
    return (int)((float)calc.m_value * (1.0f + calc.m_bonus));
}
MS2_REPLACE(0x140761ea0, FUN_140761ea0, 78, 0xCFFAEC89);

void FUN_140761f60(const std::vector<unsigned>& ids, int nState);

// @0x140761f00
// "id,id,..." -> FUN_140761f60.
void FUN_140761f00(const CStringW& strIds, int nState)
{
    std::vector<unsigned> ids;
    FUN_1402929a0(strIds, ids, L",");
    FUN_140761f60(ids, nState);
}
MS2_REPLACE(0x140761f00, FUN_140761f00, 85, 0x1CC52EE5);

// @0x140761f60
// The quest list request (packet 0x29 mode 5): the action of nState, the ids and, for the progress actions, the
// condition goals of each quest (0 for the reset actions).
void FUN_140761f60(const std::vector<unsigned>& ids, int nState)
{
    if (ids.empty())
        return;
    int nAction = 0;
    switch (nState)
    {
    case 0:
        nAction = 3;
        break;
    case 1:
        nAction = 1;
        break;
    case 2:
        nAction = 2;
        break;
    case 3:
        nAction = 1;
        break;
    case 4:
        nAction = 0;
        break;
    }
    COutPacket packet(0x29, 0);
    packet.Encode1(5);
    packet.Encode4(nAction);
    packet.Encode4((int)ids.size());
    for (size_t i = 0; i < ids.size(); i++)
    {
        packet.Encode4(ids[i]);
        if (nAction != 0 && nAction != 3)
        {
            MS2Ptr<CQuestData> spData = FUN_14074bc40(ids[i]);
            int nCount = (int)(spData.get() ? spData->m_conditions.GetCount() : 0);
            packet.Encode4(nCount);
            for (int j = 0; j < nCount; j++)
            {
                if (nState == 3 || nState == 2)
                    packet.Encode4((int)spData->m_conditions[j]->m_nGoal);
                else
                    packet.Encode4(0);
            }
        }
    }
    FUN_140710590(packet);
}
MS2_REPLACE(0x140761f60, FUN_140761f60, 608, 0x6646476B);

// @0x1407621d0
Unk_QuestRewardCalc::Unk_QuestRewardCalc()
{
    m_enabled = 1;
    m_level = 0;
    m_guildNpcLevel = 0;
    m_value = 0;
    m_bonus = 0;
    Unk_QmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
        m_level = pPlayer->vfunc_78();
    m_guildNpcLevel = FUN_1403ed290()->FUN_1404d2990(6);
}

// @0x1407622b0
// Meso: the fixed amount, or the reward contents table's (relativeMeso) scaled by the quest's factor and the guild bonus;
// then the global quest meso factor of the quest type.
void FUN_1407622b0(int nQuestId, Unk_QuestRewardCalc& calc)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return;
    if (calc.m_enabled == 0)
        return;
    CQuestData::CompleteReward* pReward = &spData->m_complete;
    if (pReward->m_relativeMeso != 0)
    {
        RewardContentsTable::Result result;
        static_cast<RewardContentsTable*>(FUN_140764030())->GetReward(pReward->m_relativeMeso, calc.m_level, result);
        result.m_nMeso *= (double)pReward->m_40;
        calc.m_value = result.m_nMeso;
        calc.m_bonus = 0;
        if (FUN_14074b050(spData.operator->()) == 6)
        {
            float fFactor = FUN_1404f4530()->FUN_1404d7360(calc.m_guildNpcLevel, 3);
            if (fFactor >= 1.0)
                calc.m_bonus = fFactor - 1.0f;
        }
    }
    else
    {
        calc.m_value = calc.m_enabled ? spData->m_complete.m_money : 0;
        calc.m_bonus = 0;
    }
    float fFactor = FUN_140302b10()->FUN_1404c1810(CGloabalFactor::MULTI_QUEST_REWARD_MESO, FUN_14074b050(spData.operator->()));
    if (!FUN_14028d470(1.0f, fFactor))
        calc.m_value = (__int64)((float)calc.m_value * fFactor);
}
MS2_REPLACE(0x1407622b0, FUN_1407622b0, 581, 0xA351B070);

// @0x140762500
// Exp: the larger of the fixed exp and the exp table's (relativeExp) scaled by the quest's factor, plus the Lua bonus
// of the quest kind (not for kind 5), then the guild bonus.
void FUN_140762500(int nQuestId, Unk_QuestRewardCalc& calc)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return;
    __int64 nExp = 0;
    if (calc.m_enabled != 0)
    {
        __int64 nFixed = spData->m_complete.m_exp;
        __int64 nRelative = 0;
        if (spData->m_complete.m_relativeExp != -1)
        {
            nRelative = FUN_1404a1bb0()->GetTypeValue(calc.m_level, spData->m_complete.m_relativeExp);
            nRelative *= (double)spData->m_complete.m_38;
        }
        nExp = (std::max)(nFixed, nRelative);
    }
    if (spData->m_50 != 5)
    {
        int nExtra = calc.m_enabled ? spData->m_complete.m_rewardExpExtra : 0;
        float fAdd = FUN_1401c0db0()->FUN_140679ea0(FUN_14074b050(spData.operator->()), spData->m_50, nExtra, spData->m_4c);
        if (!FUN_14028d470(fAdd, 0))
            nExp = FUN_140632990(nExp, fAdd);
    }
    calc.m_value = nExp;
    calc.m_bonus = 0;
    if (FUN_14074b050(spData.operator->()) == 6)
    {
        float fFactor = FUN_1404f4530()->FUN_1404d7360(calc.m_guildNpcLevel, 1);
        if (fFactor >= 1.0)
            calc.m_bonus = fFactor - 1.0f;
    }
}
MS2_REPLACE(0x140762500, FUN_140762500, 652, 0x8005B83B);

// @0x1407627a0
void FUN_1407627a0(int nQuestId, Unk_QuestRewardCalc& calc)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return;
    calc.m_value = calc.m_enabled ? spData->m_complete.m_guildFund : 0;
    calc.m_bonus = 0;
    if (FUN_14074b050(spData.operator->()) == 6)
    {
        float fFactor = FUN_1404f4530()->FUN_1404d7360(calc.m_guildNpcLevel, 2);
        if (fFactor >= 1.0)
            calc.m_bonus = fFactor - 1.0f;
    }
}
MS2_REPLACE(0x1407627a0, FUN_1407627a0, 248, 0x94CC36E3);

// @0x1407628a0
void FUN_1407628a0(int nQuestId, Unk_QuestRewardCalc& calc)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return;
    calc.m_value = calc.m_enabled ? spData->m_complete.m_guildExp : 0;
    calc.m_bonus = 0;
    if (FUN_14074b050(spData.operator->()) == 6)
    {
        float fFactor = FUN_1404f4530()->FUN_1404d7360(calc.m_guildNpcLevel, 0);
        if (fFactor >= 1.0)
            calc.m_bonus = fFactor - 1.0f;
    }
}
MS2_REPLACE(0x1407628a0, FUN_1407628a0, 245, 0xB21C7C45);

// @0x1407629a0
void FUN_1407629a0(int nQuestId, Unk_QuestRewardCalc& calc)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return;
    calc.m_value = calc.m_enabled ? spData->m_complete.m_guildCoin : 0;
    calc.m_bonus = 0;
    if (FUN_14074b050(spData.operator->()) == 6)
    {
        float fFactor = FUN_1404f4530()->FUN_1404d7360(calc.m_guildNpcLevel, 4);
        if (fFactor >= 1.0)
            calc.m_bonus = fFactor - 1.0f;
    }
}
MS2_REPLACE(0x1407629a0, FUN_1407629a0, 248, 0xEA6FEA53);

// @0x140762aa0
void FUN_140762aa0(int nQuestId, Unk_QuestRewardCalc& calc)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return;
    calc.m_value = calc.m_enabled ? spData->m_complete.m_karma : 0;
    calc.m_bonus = 0;
}
MS2_REPLACE(0x140762aa0, FUN_140762aa0, 148, 0x1EEFAF27);

// @0x140762b40
void FUN_140762b40(int nQuestId, Unk_QuestRewardCalc& calc)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return;
    calc.m_value = calc.m_enabled ? spData->m_complete.m_lu : 0;
    calc.m_bonus = 0;
}
MS2_REPLACE(0x140762b40, FUN_140762b40, 148, 0xA36A513D);

// @0x140762be0
void FUN_140762be0(int nQuestId, Unk_QuestRewardCalc& calc)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return;
    calc.m_value = calc.m_enabled ? spData->m_complete.m_menteeCoin : 0;
    calc.m_bonus = 0;
}
MS2_REPLACE(0x140762be0, FUN_140762be0, 148, 0xF48F2739);

// @0x140762c80
// Fame points: the Lua value of the quest kind for the alliance's current grade (useMainFamePoint quests only).
void FUN_140762c80(int nQuestId, Unk_QuestRewardCalc& calc)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (!spData)
        return;
    if (calc.m_enabled == 0)
        return;
    CQuestData::CompleteReward* pReward = &spData->m_complete;
    if (pReward->m_useMainFamePoint == 0)
        return;
    int nKind = spData->m_50;
    Unk_FameAlliance nAlliance = spData->m_4c;
    int nPoint = FUN_140762280(&calc, nAlliance);
    int nGrade = FameTable()->GetGradeByPoint(nAlliance, nPoint);
    calc.m_value = FUN_1401c0db0()->FUN_140679ca0(nKind, nGrade, pReward->m_useMainFamePoint, spData->m_4c);
    calc.m_bonus = 0;
}
MS2_REPLACE(0x140762c80, FUN_140762c80, 331, 0xDADB60B6);

// @0x140762fc0
// The fame board of an alliance: the points into the current grade over the grade's span ("s_fame_point_board_max"
// and 1 / 1 at the top grade).
void FUN_140762fc0(int nAlliance, int* pnCur, int* pnMax, CStringW& strText)
{
    int nPoint = FUN_140931210(nAlliance);
    int nGrade = FameTable()->GetGradeByPoint((Unk_FameAlliance)nAlliance, nPoint);
    if (nGrade == FameTable()->GetMaxGrade((Unk_FameAlliance)nAlliance))
    {
        *pnCur = 1;
        *pnMax = 1;
        strText = FUN_14028b8e0(L"s_fame_point_board_max");
    }
    else
    {
        int nStart = FameTable()->GetGradePoint((Unk_FameAlliance)nAlliance, nGrade);
        int nNext = FameTable()->GetNextGradePoint((Unk_FameAlliance)nAlliance, nGrade);
        *pnCur = nPoint - nStart;
        *pnMax = nNext - nStart;
        strText = StringFormat(L"{0} / {1}", FUN_140763e10(*pnCur), FUN_140763e10(*pnMax));
    }
}
MS2_REPLACE(0x140762fc0, FUN_140762fc0, 529, 0x18535EF7);

// @0x140763210
// The description and the format string ids of a quest in state nState (0 offerable, 1 in progress, 2 completable);
// an in-progress quest whose conditions are all met counts as completable.
void FUN_140763210(int nQuestId, int nState, CStringW& strDesc, CStringW& strFormat)
{
    Unk_QmPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData == 0)
        return;
    unsigned short nReqLevel = spData->m_require.m_level;
    int nFormatId = 0;
    int nDescId = 0;
    if (nState == 1)
    {
        Unk_PayloadPtr<CQuest> spQuest = static_cast<CQuestManager*>(FUN_140764020())->vfunc_o10_3(nQuestId);
        if ((spQuest.get() ? true : false) && spQuest->IsComplete() != 0)
            nState = 2;
    }
    if (nState == 0)
    {
        if (pPlayer->vfunc_78() < nReqLevel)
        {
            nDescId = 0x739;
            nFormatId = 0x743;
        }
        else
        {
            if (FUN_140764040(spData.operator->()))
                nDescId = 0x734;
            else if (FUN_140764080(spData.operator->()))
                nDescId = 0x735;
            else if (FUN_1407640c0(spData.operator->()))
                nDescId = 0x737;
            else
                nDescId = 0x736;
            nFormatId = 0x742;
        }
    }
    else if (nState == 2)
    {
        if (FUN_140764040(spData.operator->()))
            nDescId = 0x730;
        else if (FUN_140764080(spData.operator->()))
            nDescId = 0x731;
        else if (FUN_1407640c0(spData.operator->()))
            nDescId = 0x733;
        else
            nDescId = 0x732;
        nFormatId = 0x740;
    }
    else if (nState == 1)
    {
        nDescId = 0x738;
        nFormatId = 0x741;
    }
    strDesc = FUN_14028de60(nDescId);
    strFormat = FUN_14028de60(nFormatId);
}
MS2_REPLACE(0x140763210, FUN_140763210, 814, 0xACF85F89);

// @0x140763550
// The quest's state line: the format of FUN_140763210 over the description, the level and the quest name.
CStringW FUN_140763550(int nQuestId, int nState)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData == 0)
        return CStringW(L"");
    CStringW strDesc;
    CStringW strFormat;
    FUN_140763210(nQuestId, nState, strDesc, strFormat);
    return StringFormat((const wchar_t*)strFormat, strDesc, spData->m_level, FUN_1416e4df0(nQuestId));
}
MS2_REPLACE(0x140763550, FUN_140763550, 357, 0xA03B3A40);

// @0x1407636f0
// nCount random quests of a vector (FUN_140763790 over a copy).
void FUN_1407636f0(int nCount, std::vector<MS2Ptr<CQuestData> >& input, ATL::CAtlArray<MS2Ptr<CQuestData> >& output)
{
    ATL::CAtlArray<MS2Ptr<CQuestData> > arr;
    for (size_t i = 0; i < input.size(); i++)
        arr.Add(input[i]);
    FUN_140763790(nCount, arr, output);
}
MS2_REPLACE(0x1407636f0, FUN_1407636f0, 144, 0x5D70141C);

// @0x140763790
// Up to nCount distinct random entries of input (the unit's generator), appended to output.
void FUN_140763790(int nCount, ATL::CAtlArray<MS2Ptr<CQuestData> >& input, ATL::CAtlArray<MS2Ptr<CQuestData> >& output)
{
    if (input.GetCount() == 0)
        return;
    nCount = (std::min)(nCount, (int)input.GetCount());
    ATL::CAtlArray<int> pool;
    for (int i = 0; i < (int)input.GetCount(); i++)
        pool.Add(i);
    for (int j = 0; j < nCount; j++)
    {
        int nSel = FUN_140768010((int)pool.GetCount(), 0);
        int nIndex = pool[nSel];
        if (nIndex < 0 || nIndex >= (int)input.GetCount())
            continue;
        output.Add(input[nIndex]);
        pool.RemoveAt(nSel, 1);
    }
}
MS2_REPLACE(0x140763790, FUN_140763790, 329, 0x43B6DFA9);

// @0x1407638e0
// FUN_140763790 with the caller's generator.
void FUN_1407638e0(int nCount, ATL::CAtlArray<MS2Ptr<CQuestData> >& input, ATL::CAtlArray<MS2Ptr<CQuestData> >& output,
                   Unk_Random& random)
{
    if (input.GetCount() == 0)
        return;
    nCount = (std::min)(nCount, (int)input.GetCount());
    ATL::CAtlArray<int> pool;
    for (int i = 0; i < (int)input.GetCount(); i++)
        pool.Add(i);
    for (int j = 0; j < nCount; j++)
    {
        if (pool.GetCount() == 0)
            return;
        int nSel = (int)(random.FUN_1407684c0() % pool.GetCount());
        int nIndex = pool[nSel];
        if (nIndex < 0 || nIndex >= (int)input.GetCount())
            continue;
        output.Add(input[nIndex]);
        pool.RemoveAt(nSel, 1);
    }
}
MS2_REPLACE(0x1407638e0, FUN_1407638e0, 428, 0x4CF69B83);

// @0x140764010
Unk_EmoNpcTable* FUN_140764010()
{
    return DAT_143aaeb10;
}

// @0x140764480
// The state of a quest against mode nMode (1 completable, 2 rewarded, 3 rewarded only): 0 satisfied, 1 pending,
// 2 not met.
int FUN_140764480(Unk_PayloadPtr<CQuest> spQuest, int nMode)
{
    BOOL bActive = FALSE;
    BOOL bCompleted = FALSE;
    BOOL bRewarded = FALSE;
    BOOL bAbsent = FALSE;
    if (spQuest.get())
    {
        bActive = spQuest->FUN_1407476d0() == 1 && spQuest->IsComplete() == 0;
        bCompleted = spQuest->FUN_1407476d0() == 1 && spQuest->IsComplete() != 0;
        bRewarded = spQuest->FUN_1407476d0() == 2;
    }
    else
        bAbsent = TRUE;
    switch (nMode)
    {
    case 1:
        if (bAbsent)
            return 2;
        if (bActive)
            return 0;
        if (bCompleted || bRewarded)
            return 1;
        break;
    case 2:
        if (bAbsent || bActive)
            return 2;
        if (bCompleted)
            return 0;
        if (bRewarded)
            return 1;
        break;
    case 3:
        if (bRewarded)
            return 0;
        if (bAbsent || bActive || bCompleted)
            return 2;
        break;
    }
    return 2;
}
MS2_REPLACE(0x140764480, FUN_140764480, 729, 0xA9111DF5);

#ifndef MS2_HOOK_DLL
// @0x140767ff0
unsigned FUN_140767ff0()
{
    return s_random.FUN_1407684c0();
}
#endif
