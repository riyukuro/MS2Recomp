// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). EffectSkipMgr: view distance and per-name count limits
// that decide whether an effect may be skipped. See effectskipmgr.h.
// MS2-UNIT: ?\effectskipmgr.cpp
// MS2-RANGE: 0x1400e7d30-0x1400e7eb0 .text$di
// MS2-RANGE: 0x1411b8510-0x1411bcb50 .text$mn
// MS2-PIN: ??_7EffectSkipMgr@@6B?$TSingleton@VEffectSkipMgr@@@@@ 0x142ebc258
// MS2-PIN: ??_7EffectSkipMgr@@6B?$CValidData@VEffectSkipMgr@@@@@ 0x142ebc268
// MS2-PIN: ??1EffectSkipMgr@@UEAA@XZ 0x1411bb110
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0PEBDAEAH$0A@@?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@QEAA@$$QEAPEBDAEAH@Z 0x1411b9d90 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@XZ 0x1411bc010 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\effectskipmgr.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "effectskipmgr.h"
#include <string.h>
#pragma intrinsic(strcmp)
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the unit's header statics (three headers each define "skill", "stun" and a handle) ----
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100
static CString s_strSkill1 = "skill";                // @0x1400e7d30
static CString s_strStun1 = "stun";                  // @0x1400e7d60
static Unk_Handle1401cd100 s_handle1(0);             // @0x1400e7d90
static CString s_strSkill2 = "skill";                // @0x1400e7db0
static CString s_strStun2 = "stun";                  // @0x1400e7de0
static Unk_Handle1401cd100 s_handle2(0);             // @0x1400e7e10
static CString s_strSkill3 = "skill";                // @0x1400e7e30
static CString s_strStun3 = "stun";                  // @0x1400e7e60
static Unk_Handle1401cd100 s_handle3(0);             // @0x1400e7e90

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char*);              // first child element (also takes a document)
    Unk_140165cf0* FUN_140168650(const char*);              // next sibling element
};
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14016a5c0(const char* psz, int n);
int FUN_1408731e0(Unk_140165cf0*, const char*, int&);
void FUN_140873360(Unk_140165cf0*, const char*, float&);
const char* FUN_14086f4b0(Unk_140165cf0*, const char*);
int FUN_1408733e0(Unk_140165cf0*, const char*, CString&);
CString FUN_140188f50(const char* psz, int n);
Unk_140165cf0* FUN_1403f0510(Unk_140165cf0*);                   // next sibling with the same name
int FUN_140bf4fd0(float);                                       // float -> int (round up)

// The 12 byte zero point.
extern Unk_SkipPoint DAT_143b01a60;

// The view-distance probe (the host, its local actor).
class Unk_SkipHost { public: };
Unk_SkipHost* FUN_1409478c0();
int FUN_140a18070(Unk_SkipHost*);
class Unk_SkipActor
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17();
    virtual void GetPosition(Unk_SkipActorPos* pOut);       // slot 18 (+0x90)
};
Unk_SkipActor* FUN_140a38d60(Unk_SkipHost*);
bool FUN_14028d470(float a, float b);                      // float equality test

// The live effect list the skip query walks.
class Unk_SkipEffect
{
public:
    char m_pad_00[0x18];
    int m_nKind;                    // +0x18
    char m_pad_1c[8];
    Unk_SkipPoint m_pos;            // +0x24
    char m_pad_30;
    bool m_bIgnore;                 // +0x31
    char m_pad_32[0x7a];
    float m_fViewDistance;          // +0xac
};
class Unk_SkipContainer;
class Unk_SkipItem;
class Unk_SkipEffectList { public: };
void FUN_140a90120(Unk_SkipEffectList*);
void* FUN_140a901f0(Unk_SkipEffectList*);
Unk_SkipContainer* FUN_14119f540(void*);
__int64 FUN_140a904b0(Unk_SkipContainer*);
Unk_SkipItem* FUN_140a90440(Unk_SkipContainer*, __int64);
Unk_SkipEffect* FUN_140a901e0(Unk_SkipItem*);
void FUN_140a904c0(Unk_SkipContainer*, __int64*);
float* FUN_140552770(std::vector<float>*, size_t);          // const operator[]
void* FUN_1409a8b10();
int* FUN_1409a8ac0(void*);
unsigned char FUN_1401d1320(CCacheData*);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool EffectSkipMgr::s_bInit;
#endif

// @0x1411b8510
Unk_SkipRow::Unk_SkipRow()
{
    m_dist.resize(8, 0);
}

// @0x1411b8570
Unk_SkipCheck::Unk_SkipCheck() : m_nRow(0), m_nCaster(9), m_pos(DAT_143b01a60), m_n14(0), m_fViewDistance(-1.0f)
{
}

// @0x1411b85e0
EffectSkipMgr::EffectSkipMgr() : m_nMaxCount(0), m_nBaseFrame(0), m_bSuspended(false)
{
}

// @0x1411b86e0
int EffectSkipMgr::IsOutOfView(Unk_SkipCheck* pCheck) const
{
    CheckInit();
    if (pCheck->m_nCaster == 0)
        return 0;
    if (pCheck->m_n14 != 0 && pCheck->m_nRow == 1)
        return 0;
    if (FUN_140a18070(FUN_1409478c0()) == 0)
        return 0;
    Unk_SkipActor* pActor = FUN_140a38d60(FUN_1409478c0());
    if (pActor == 0)
        return 0;
    Unk_SkipActorPos pos;
    pActor->GetPosition(&pos);
    Unk_SkipDelta delta = pCheck->m_pos.FUN_140965c40(pos);
    float fDist = delta.FUN_140968990();
    float fView = pCheck->m_fViewDistance;
    if (FUN_14028d470(fView, -1.0f))
        fView = *FUN_140552770(const_cast<std::vector<float>*>(&m_rows[pCheck->m_nRow].m_dist), pCheck->m_nCaster);
    return !FUN_14028d470(fView, 0) && fView <= fDist;
}

// @0x1411b8870
bool EffectSkipMgr::ShouldSkipByView(Unk_SkipEffectList* pList, int nCaster, Unk_SkipEffect* pEffect)
{
    Unk_SkipCheck check;
    check.m_nCaster = nCaster;
    check.m_pos = pEffect->m_pos;
    check.m_n14 = 0;
    __int64 pos = FUN_140a904b0(FUN_14119f540(FUN_140a901f0(pList)));
    for (;;)
    {
        if (pos == 0)
        {
            FUN_140a90120(pList);
            return false;
        }
        Unk_SkipEffect* pItem = FUN_140a901e0(FUN_140a90440(FUN_14119f540(FUN_140a901f0(pList)), pos));
        check.m_nRow = pItem->m_nKind;
        if (!pItem->m_bIgnore)
        {
            check.m_fViewDistance = -1.0f;
            if (pItem->m_nKind == 1)
                check.m_fViewDistance = pItem->m_fViewDistance;
            if (IsOutOfView(&check))
            {
                FUN_140a90120(pList);
                return true;
            }
        }
        FUN_140a904c0(FUN_14119f540(FUN_140a901f0(pList)), &pos);
    }
}

// @0x1411b89e0
bool EffectSkipMgr::LoadOption()
{
    int nOption = *FUN_1409a8ac0(FUN_1409a8b10());
    TiXmlDocument doc;
    CString strPath = FUN_14071a5b0(CString("Table"), CString("effectOption.xml"));
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    CString strOption("option");
    char szNum[8];
    strOption += _itoa(nOption + 1, szNum, 8);
    Unk_140165cf0* pOption = pRoot->FUN_140165cf0(strOption);
    if (pOption != 0)
    {
        LoadElements(pOption->FUN_140165cf0("nif"), 1);
        LoadElements(pOption->FUN_140165cf0("sound"), 2);
        LoadElements(pOption->FUN_140165cf0("swoosh"), 7);
        LoadElements(pOption->FUN_140165cf0("random"), 0xb);
        LoadElements(pOption->FUN_140165cf0("vibrate"), 0xc);
        LoadElements(pOption->FUN_140165cf0("chaoslight"), 0xe);
        LoadElements(pOption->FUN_140165cf0("lightning"), 0x10);
    }
    SetInit(true);
    return true;
}

// @0x1411b8d20
bool EffectSkipMgr::LoadLimitCount()
{
    TiXmlDocument doc;
    CString strPath = FUN_14071a5b0(CString("Table"), CString("effectLimitCount.xml"));
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    m_cache.FUN_1401d1160(strPath);
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    Unk_140165cf0* pDefault = pRoot->FUN_140165cf0("default");
    if (pDefault != 0)
        FUN_1408731e0(pDefault, "maxcount", m_nMaxCount);
    Unk_140165cf0* pAdaptive = pRoot->FUN_140165cf0("adaptive");
    if (pAdaptive != 0)
    {
        FUN_1408731e0(pAdaptive, "baseframe", m_nBaseFrame);
        if (0 < m_nBaseFrame)
            LoadBenchmark();
    }
    Unk_140165cf0* pEffects = pRoot->FUN_140165cf0("effects");
    if (pEffects != 0)
    {
        CString strName;
        int nCount;
        for (Unk_140165cf0* pUnit = pEffects->FUN_140165cf0("unit"); pUnit != 0; pUnit = pUnit->FUN_140168650("effect"))
        {
            FUN_1408733e0(pUnit, "id", strName);
            FUN_1408731e0(pUnit, "count", nCount);
            strName.MakeLower();
            CountMap::iterator it = m_mapLimit.find((const char*)strName);
            if (it == m_mapLimit.end())
                m_mapLimit.insert(CountMap::value_type((const char*)strName, nCount));
            else
                it->second = nCount;
        }
    }
    return true;
}

// @0x1411b9180
int EffectSkipMgr::ParseCaster(const char* pszCaster, int* pnCaster)
{
    int bOk = 0;
    if (strcmp(pszCaster, "myPC") == 0)
    {
        *pnCaster = 1;
        bOk = 1;
    }
    else if (strcmp(pszCaster, "PC") == 0)
    {
        *pnCaster = 3;
        bOk = 1;
    }
    else if (strcmp(pszCaster, "monster") == 0)
    {
        *pnCaster = 5;
        bOk = 1;
    }
    else if (strcmp(pszCaster, "bossMonster") == 0)
    {
        *pnCaster = 6;
        bOk = 1;
    }
    else if (strcmp(pszCaster, "background") == 0)
    {
        *pnCaster = 7;
        bOk = 1;
    }
    return bOk;
}

// @0x1411b92f0
void EffectSkipMgr::LoadElements(void* pNode, int nRow)
{
    for (Unk_140165cf0* pElement = static_cast<Unk_140165cf0*>(pNode)->FUN_140165cf0("element"); pElement != 0;
         pElement = FUN_1403f0510(pElement))
    {
        CString strCaster = FUN_140188f50(FUN_14086f4b0(pElement, "caster"), 0);
        int nCaster;
        float fView = 0;
        FUN_140873360(pElement, "viewDistance", fView);
        if (ParseCaster(strCaster, &nCaster))
            m_rows[nRow].m_dist[nCaster] = fView;
    }
}

// @0x1411b93f0
bool EffectSkipMgr::CanPlay(const char* pszName)
{
    if (FUN_1401d1320(&m_cache))
        LoadLimitCount();
    if (m_bSuspended || !(0 < m_nMaxCount || 0 < m_nBaseFrame))
        return false;
    CountMap::const_iterator itCount = m_mapCount.find(pszName);
    if (itCount == m_mapCount.end())
        return false;
    CString strLower(pszName);
    strLower.MakeLower();
    int nLimit = m_nMaxCount;
    CountMap::const_iterator itLimit = m_mapLimit.find((const char*)strLower);
    if (itLimit != m_mapLimit.end())
        nLimit = (*itLimit).second;
    if ((*itCount).second >= nLimit)
        return true;
    return false;
}

// @0x1411b9620
void EffectSkipMgr::AddCount(const char* pszName)
{
    if (m_bSuspended || !(0 < m_nMaxCount || 0 < m_nBaseFrame))
        return;
    CountMap::iterator it = m_mapCount.find(pszName);
    if (it == m_mapCount.end())
    {
        int nOne = 1;
        m_mapCount.insert(CountMap::value_type(pszName, nOne));
    }
    else
        ++it->second;
}

// @0x1411b97a0
void EffectSkipMgr::RemoveCount(const char* pszName)
{
    if (m_bSuspended || !(0 < m_nMaxCount || 0 < m_nBaseFrame))
        return;
    CountMap::iterator it = m_mapCount.find(pszName);
    if (it != m_mapCount.end())
    {
        if (it->second <= 1)
            m_mapCount.erase(it);
        else
            --it->second;
    }
}

// @0x1411b98e0
void EffectSkipMgr::SetSuspended(bool b)
{
    m_bSuspended = b;
}

// @0x1411b9900
void EffectSkipMgr::LoadBenchmark()
{
    if (0 < m_nBaseFrame)
    {
        TiXmlDocument doc;
        CString strPath = FUN_14071a5b0(CString("Table"), CString("effect_benchmark.xml"));
        const char* pszPath = strPath;
        if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
            return;
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
            return;
        }
        CString strName;
        for (Unk_140165cf0* pE = pRoot->FUN_140165cf0("e"); pE != 0; pE = pE->FUN_140168650("e"))
        {
            int nTime[2];
            FUN_1408733e0(pE, "p", strName);
            FUN_1408731e0(pE, "t", nTime[0]);
            strName.MakeLower();
            nTime[1] = (int)FUN_140bf4fd0(50000.0f / (float)(nTime[0] * m_nBaseFrame));
            CountMap::iterator it = m_mapLimit.find((const char*)strName);
            if (it == m_mapLimit.end())
                m_mapLimit.insert(CountMap::value_type((const char*)strName, nTime[1]));
            else
                it->second = nTime[1];
        }
    }
}

// @0x1411bb610
void EffectSkipMgr::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(EffectSkipMgr).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1411bb6c0
void EffectSkipMgr::SetInit(bool b)
{
    s_bInit = b;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cace40-0x142cacf00 .text$yd
