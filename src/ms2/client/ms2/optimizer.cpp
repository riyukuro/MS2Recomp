// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COptimizer: per-player model culling / update throttling,
// the frame limiter, Optimization.xml and the hardware log.
// MS2-UNIT: ?\optimizer.cpp
// MS2-RANGE: 0x14161b8c0-0x1416252b0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@@1@0@Z 0x14161dea0 ; unique
// MS2-PIN: ??$Unk_OptLog@H@@YAXPEAVCLogString@@HHPEB_WAEBH@Z 0x14161e160 ; unique
// MS2-PIN: ??$Unk_OptLog@_KH@@YAXPEAVCLogString@@HHPEB_WAEB_KAEBH@Z 0x14161e280 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1416217d0 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1416217e0 ; unique
// MS2-PIN: ??0?$allocator@U?$_List_node@UEntry@COptimizer@@PEAX@std@@@std@@QEAA@XZ 0x141621da0 ; unique
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1416224c0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$allocator@VEntityID@egf@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@VEntityID@egf@@PEAX@2@@Z 0x141623ad0 ; prop
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CB_KUEntry@COptimizer@@@std@@@std@@SAPEAU?$pair@$$CB_KUEntry@COptimizer@@@2@AEAU32@@Z 0x141624fb0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CB_KUEntry@COptimizer@@@std@@PEAU?$_Tree_node@U?$pair@$$CB_KUEntry@COptimizer@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@_KUEntry@COptimizer@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@4@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@std@@@std@@@1@AEAU?$pair@$$CB_KUEntry@COptimizer@@@1@PEAU?$_Tree_node@U?$pair@$$CB_KUEntry@COptimizer@@@std@@PEAX@1@@Z 0x14161f7d0
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CB_KUEntry@COptimizer@@@std@@PEAU?$_Tree_node@U?$pair@$$CB_KUEntry@COptimizer@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@_KUEntry@COptimizer@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@4@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CB_KUEntry@COptimizer@@@1@PEAU?$_Tree_node@U?$pair@$$CB_KUEntry@COptimizer@@@std@@PEAX@1@@Z 0x141620410
// MS2-PIN: ??$_Try_emplace@_K$$V@?$map@_KUEntry@COptimizer@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@4@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@std@@@std@@@std@@_N@1@$$QEA_K@Z 0x1416210b0
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@_KUEntry@COptimizer@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUEntry@COptimizer@@@std@@@4@$0A@@std@@@std@@IEBA_NAEB_K0@Z 0x141622bd0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\optimizer.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <psapi.h>
#include <float.h>
#include "ms2/placeholder/coptimizer.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/ms2recover.h"
#include <errno.h>
#include <string.h>
#include "hook/ms2hook.h"

// ---- the world, the actors and the helper services this unit calls ----------------------------------------------------
class MyPC;
MyPC* FUN_14161e580(const TPtr<PC>& spPC);                       // QueryInterface 0x6200004
class Unk_OptWorld;
Unk_OptWorld* FUN_1403ed2d0();                                      // the world service
int FUN_141bca2e0(Unk_OptWorld* pWorld);                            // the world is ready
PCBase* FUN_141bd0cc0(Unk_OptWorld* pWorld);                        // the local player
PCBase* FUN_141bd1530(Unk_OptWorld* pWorld, unsigned __int64 nUid);
PCBase* FUN_141bd1180(Unk_OptWorld* pWorld, unsigned nId);
class Unk_OptObjMap;                                                // the world's actor table
Unk_OptObjMap* FUN_141bd36b0(Unk_OptWorld* pWorld);
POSITION FUN_140c20a10(Unk_OptObjMap* pMap);                        // GetHeadPosition
TPtr<PC>& FUN_140c20a80(Unk_OptObjMap* pMap, POSITION pos);          // GetValueAt
void FUN_140c20a30(Unk_OptObjMap* pMap, POSITION* pPos);            // GetNext
PC* FUN_140aac420(const TPtr<PC>& spRef);                           // the actor
PC* FUN_140aac440(const TPtr<PC>& spRef);                           // operator->
void* FUN_1409613d0(PCBase* pActor);
GameObject* FUN_1416764a0(PCBase* pActor);                          // the ridee
GameObject* FUN_141676a10(PCBase* pActor);
GameObject* FUN_1416625e0(PCBase* pActor);
bool FUN_141527280(PCBase* pActor);
CPartyManager* FUN_1409670d0();
class CGuildManager;
CGuildManager* FUN_1403ed290();
int FUN_1413bcbc0(CGuildManager* pGuild, std::map<unsigned __int64, PCBase*>& out);   // CGuildManager::FUN_1413bcbc0
bool FUN_14028d470(float a, float b);
struct Unk_OptConstVal { int m_n; };
class Unk_OptOptions { public: unsigned char m_pad_0[0x36d8]; Unk_OptConstVal m_frameLimit; };
Unk_OptOptions* FUN_1401d3200();
int* FUN_1402056b0(Unk_OptConstVal* pSlot);
class Unk_OptClock { public: double FUN_141473260(); float FUN_141473210(); };
Unk_OptClock* FUN_14086d260();
unsigned FUN_140869420();                                           // millisecond clock
class Unk_OptOsInfo { public: CString FUN_14070ee50(); };
Unk_OptOsInfo* FUN_1411b1db0();
bool FUN_14070ee20(Unk_OptOsInfo* pInfo);                           // 64-bit OS
void* FUN_140a0afd0();                                              // memory pressure manager
void FUN_141554ce0(void* pMgr, double fTime);
void FUN_141554d20(void* pMgr);
class Unk_OptGPU { public: void FUN_1413758b0(); void FUN_141375a80(); CStringW FUN_141245ab0(); };
Unk_OptGPU* FUN_141245b20();
class Unk_OptLogText { public: void FUN_1401ce2b0(const char*); void FUN_1401ce270(const CString&); void FUN_1401ce2f0(const char*, ...); };
Unk_OptLogText* FUN_140a44830();
void* FUN_14151e7e0();
void* FUN_1414a56c0();
int FUN_1422e9e50(void* pAllocator);
CString FUN_14016a600(const wchar_t* pszText, int nCodePage);
CString FUN_1412755b0();
CString FUN_140cc2a00(const CString& strRoot, const CString& strFile);
bool FUN_140870fc0(TiXmlDocument* pDoc, const char* pszFile, int nEncoding);
void* FUN_14081b310(TiXmlDocument* pDoc);                           // RootElement
void* FUN_140165cf0(void* pParent, const char* pszName);            // FirstChildElement
int FUN_1408731e0(void* pElement, const char* pszAttr, int& nValue);
void* FUN_1409a8b10();
struct Unk_OptSettings { unsigned char m_pad_0[0x10]; unsigned char m_bOptimize; };
Unk_OptSettings* FUN_140c77560(void* pSettings);
CLogString* FUN_140166440();

// options of Optimization.xml (contiguous dwords) and the "loaded" flag
extern int DAT_143ae2b30, DAT_143ae2b34, DAT_143ae2b38, DAT_143ae2b3c, DAT_143ae2b40, DAT_143ae2b44, DAT_143ae2b48;
extern int DAT_143ae2b4c, DAT_143ae2b50, DAT_143ae2b54, DAT_143ae2b58, DAT_143ae2bf8;

// The unit's log calls (FMT_VARIADIC wrappers over CLogString::FUN_1406530d0).
template <class T> inline void Unk_OptLog(CLogString* log, int level, int category, const wchar_t* format, const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}
template <class T, class U> inline void Unk_OptLog(CLogString* log, int level, int category, const wchar_t* format,
                                                    const T& first, const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// @0x14161b8c0
COptimizer::Entry::Entry(float fDistance, PCBase* pPC)
    : m_fDistance(fDistance), m_pPC(pPC)
{
}

// @0x141621e50
COptimizer::Entry::Entry()
    : m_fDistance(FLT_MAX), m_pPC(0)
{
}

// @0x14161b900
COptimizer::COptimizer()
    : m_nTotalMemory(0), m_fMemoryTime(0), m_fUpdateTime(0), preloadMode(0), m_nSuppressed(0), m_nEnabled(0),
      m_nMode(0), m_nLimit(0), m_fFrameLimit(120.0f), m_nFrameDelay(0), m_nUpdateOn(1), m_nUpdateOn2(1),
      m_nStartTick(0), m_nFirstLoadTick(0), m_nSampleCount(0), m_nSampleCycle(1000)
{
}

// @0x14161ba70
COptimizer::~COptimizer()
{
}

// @0x14161baf0
void COptimizer::FUN_14161baf0()
{
    m_nStartTick = FUN_140869420();
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&status);
    m_nTotalMemory = status.ullTotalPhys / 0x100000;
}

// @0x14161bb60
void COptimizer::FUN_14161bb60()
{
    float fDelta = (float)FUN_14086d260()->FUN_141473260();
    m_fMemoryTime += fDelta;
    if (5.0f < m_fMemoryTime)
    {
        m_fMemoryTime = 0;
        if (!FUN_14070ee20(FUN_1411b1db0()))
        {
            unsigned __int64 nUsage = FUN_14161bdc0();
            if (0x599 < nUsage)
            {
                FUN_141554ce0(FUN_140a0afd0(), 120.0);
            }
            else if (nUsage < 0x564)
            {
                FUN_141554d20(FUN_140a0afd0());
            }
        }
    }
    if (FUN_1403ed2d0() != 0 && FUN_141bca2e0(FUN_1403ed2d0()) != 0)
    {
        if ((preloadMode & 8) == 0)
        {
            for (std::set<unsigned __int64>::iterator it = m_players.begin(); it != m_players.end(); ++it)
            {
                const unsigned __int64* pId = &*it;
                PCBase* pPC = FUN_141bd1530(FUN_1403ed2d0(), *pId);
                if (pPC != 0)
                {
                    FUN_14161dbe0(pPC, preloadMode);
                }
            }
            m_players.clear();
        }
        else
        {
            bool bUpdate;
            if (FUN_141622790() == 0 || FUN_14161cf40() != 0)
            {
                bUpdate = true;
            }
            else
            {
                bUpdate = false;
            }
            if (bUpdate)
            {
                m_fUpdateTime += fDelta;
                if (0.05f < m_fUpdateTime)
                {
                    m_fUpdateTime = 0;
                    FUN_14161d130(false);
                }
            }
            m_players.clear();
        }
    }
    if (m_nSampleCount != 0)
    {
        FUN_14161c990();
    }
    FUN_141245b20()->FUN_1413758b0();
}

// @0x14161bdc0
unsigned __int64 COptimizer::FUN_14161bdc0() const
{
    PROCESS_MEMORY_COUNTERS_EX counters = {};
    counters.cb = sizeof(counters);
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&counters, sizeof(counters)) == 0)
    {
        return 0;
    }
    return counters.PagefileUsage / 0x100000;
}

// @0x14161be50
unsigned __int64 COptimizer::FUN_14161be50() const
{
    PROCESS_MEMORY_COUNTERS_EX counters = {};
    counters.cb = sizeof(counters);
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&counters, sizeof(counters)) == 0)
    {
        return 0;
    }
    return counters.PrivateUsage / 0x100000;
}

// @0x14161bee0
void COptimizer::FUN_14161bee0()
{
    CString strText;
    FUN_140a44830()->FUN_1401ce2b0("\n--- COptimizer Log ---");
    strText.Format("OS : %s", (const char*)FUN_1411b1db0()->FUN_14070ee50());
    FUN_140a44830()->FUN_1401ce270(strText);
    unsigned __int64 nMemory = FUN_141245b10();
    FUN_140a44830()->FUN_1401ce2f0("GlobalMemory : %d(MB)", nMemory);
    nMemory = FUN_14161bdc0();
    FUN_140a44830()->FUN_1401ce2f0("Pagefile : %d(MB)", nMemory);
    DWORD dwLength = 0x80;
    HKEY hKey;
    BYTE szCpu[128];
    RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Hardware\\Description\\System\\CentralProcessor\\0", 0, KEY_QUERY_VALUE, &hKey);
    RegQueryValueExA(hKey, "ProcessorNameString", 0, 0, szCpu, &dwLength);
    strText.Format("CPU : %s", szCpu);
    FUN_140a44830()->FUN_1401ce270(strText);
    if (FUN_14151e7e0() != 0)
    {
        strText.Format("GPU : %s", (const char*)FUN_14016a600((const wchar_t*)FUN_141245b20()->FUN_141245ab0(), 0));
        FUN_140a44830()->FUN_1401ce270(strText);
    }
    int nGfx = FUN_1422e9e50(FUN_1414a56c0()) / 0x100000;
    FUN_140a44830()->FUN_1401ce2f0("GFXSysAlloc : %d(MB)", nGfx);
    const char* pszMultiScene;
    if (DAT_143ae2b30 == 0)
    {
        pszMultiScene = "FALSE";
    }
    else
    {
        pszMultiScene = "TRUE";
    }
    FUN_140a44830()->FUN_1401ce2f0("bUseMultiSceneUpdate %s", pszMultiScene);
    const char* pszRemoveExtra;
    if (DAT_143ae2b34 == 0)
    {
        pszRemoveExtra = "FALSE";
    }
    else
    {
        pszRemoveExtra = "TRUE";
    }
    FUN_140a44830()->FUN_1401ce2f0("bUseRemoveExtraData %s", pszRemoveExtra);
    const char* pszExceptRender;
    if (DAT_143ae2b38 == 0)
    {
        pszExceptRender = "FALSE";
    }
    else
    {
        pszExceptRender = "TRUE";
    }
    FUN_140a44830()->FUN_1401ce2f0("bUseExceptRender %s", pszExceptRender);
    const char* pszIndoor;
    if (DAT_143ae2b3c == 0)
    {
        pszIndoor = "FALSE";
    }
    else
    {
        pszIndoor = "TRUE";
    }
    FUN_140a44830()->FUN_1401ce2f0("bUseIndoorInstancing %s", pszIndoor);
    const char* pszProgressive;
    if (DAT_143ae2b40 == 0)
    {
        pszProgressive = "FALSE";
    }
    else
    {
        pszProgressive = "TRUE";
    }
    FUN_140a44830()->FUN_1401ce2f0("bUseProgressiveLoading %s", pszProgressive);
    const char* pszRemoveShadow;
    if (DAT_143ae2b44 == 0)
    {
        pszRemoveShadow = "FALSE";
    }
    else
    {
        pszRemoveShadow = "TRUE";
    }
    FUN_140a44830()->FUN_1401ce2f0("bRemoveShadowEntity %s", pszRemoveShadow);
    const char* pszKfm;
    if (DAT_143ae2b48 == 0)
    {
        pszKfm = "FALSE";
    }
    else
    {
        pszKfm = "TRUE";
    }
    FUN_140a44830()->FUN_1401ce2f0("bMS2KFM %s", pszKfm);
    FUN_141245b20()->FUN_141375a80();
}

// @0x14161c360
float COptimizer::FUN_14161c360()
{
    m_fFrameLimit = (float)*FUN_1402056b0(&FUN_1401d3200()->m_frameLimit);
    if (FUN_14028d470(m_fFrameLimit, 0))
    {
        m_nFrameDelay = 0;
    }
    else
    {
        m_nFrameDelay = (int)(1000.0f / m_fFrameLimit);
    }
    return m_fFrameLimit;
}

// @0x14161c3f0
void COptimizer::FUN_14161c3f0()
{
    m_fFrameLimit = 0;
    m_nFrameDelay = 0;
}

// @0x14161c420
void COptimizer::FUN_14161c420(float fLimit)
{
    m_fFrameLimit = fLimit;
    if (FUN_14028d470(m_fFrameLimit, 0))
    {
        m_nFrameDelay = 0;
    }
    else
    {
        m_nFrameDelay = (int)(1000.0f / m_fFrameLimit);
    }
}

// @0x14161c490
void COptimizer::FUN_14161c490()
{
    if (DAT_143ae2bf8 == 0)
    {
        TiXmlDocument doc;
        bool bLoaded;
        {
            CString strFile("Optimization.xml");
            bLoaded = FUN_140870fc0(&doc, FUN_140cc2a00(FUN_1412755b0(), strFile), 0);
        }
        if (bLoaded)
        {
            void* pRoot = FUN_14081b310(&doc);
            if (pRoot != 0)
            {
                void* pMultiScene = FUN_140165cf0(pRoot, "multiSceneUpdate");
                if (pMultiScene != 0) FUN_1408731e0(pMultiScene, "value", DAT_143ae2b30);
                void* pRemoveExtra = FUN_140165cf0(pRoot, "removeExtraData");
                if (pRemoveExtra != 0) FUN_1408731e0(pRemoveExtra, "value", DAT_143ae2b34);
                void* pExceptRender = FUN_140165cf0(pRoot, "exceptItemRender");
                if (pExceptRender != 0) FUN_1408731e0(pExceptRender, "value", DAT_143ae2b38);
                void* pIndoor = FUN_140165cf0(pRoot, "IndoorInstancing");
                if (pIndoor != 0) FUN_1408731e0(pIndoor, "value", DAT_143ae2b3c);
                void* pProgressive = FUN_140165cf0(pRoot, "ProgressiveLoading");
                if (pProgressive != 0) FUN_1408731e0(pProgressive, "value", DAT_143ae2b40);
                void* pRemoveShadow = FUN_140165cf0(pRoot, "RemoveShadowEntity");
                if (pRemoveShadow != 0) FUN_1408731e0(pRemoveShadow, "value", DAT_143ae2b44);
                void* pKfm = FUN_140165cf0(pRoot, "MS2KFM");
                if (pKfm != 0) FUN_1408731e0(pKfm, "value", DAT_143ae2b48);
                void* pPiece = FUN_140165cf0(pRoot, "Piece");
                if (pPiece != 0) FUN_1408731e0(pPiece, "value", DAT_143ae2b4c);
                void* pMeshSkin = FUN_140165cf0(pRoot, "MeshMergeSkin");
                if (pMeshSkin != 0) FUN_1408731e0(pMeshSkin, "value", DAT_143ae2b50);
                void* pMeshItem = FUN_140165cf0(pRoot, "MeshMergeItem");
                if (pMeshItem != 0) FUN_1408731e0(pMeshItem, "value", DAT_143ae2b54);
                void* pDebug = FUN_140165cf0(pRoot, "DebugLevel");
                if (pDebug != 0) FUN_1408731e0(pDebug, "value", DAT_143ae2b58);
            }
        }
        else
        {
            int nEnabled = FUN_140c77560(FUN_1409a8b10())->m_bOptimize;
            DAT_143ae2b30 = nEnabled;
            DAT_143ae2b34 = nEnabled;
            DAT_143ae2b38 = nEnabled;
            DAT_143ae2b3c = nEnabled;
            DAT_143ae2b40 = nEnabled;
            DAT_143ae2b44 = nEnabled;
            DAT_143ae2b4c = nEnabled;
            DAT_143ae2b48 = nEnabled;
            DAT_143ae2b50 = 0;
            DAT_143ae2b54 = 0;
            DAT_143ae2b58 = 0;
        }
        DAT_143ae2bf8 = 1;
    }
}

// @0x14161c8c0
void COptimizer::FUN_14161c8c0()
{
    if (m_nFirstLoadTick == 0)
    {
        m_nFirstLoadTick = FUN_140869420();
        if (FUN_140166440() != 0)
        {
            int nElapsed = m_nFirstLoadTick - m_nStartTick;
            Unk_OptLog(FUN_140166440(), 0xb, 6, L"First MyPC Load Time = {0}", nElapsed);
        }
    }
}

// @0x14161c940
void COptimizer::FUN_14161c940(unsigned nCount, int nCycle)
{
    if (m_nSampleCount != 0)
    {
        return;
    }
    m_nSampleCount = nCount;
    m_nSampleCycle = nCycle;
}

// @0x14161c990
void COptimizer::FUN_14161c990()
{
    if (m_sampleTimer.FUN_140268870(m_nSampleCycle) == 0)
    {
        return;
    }
    m_samples.push_back(FUN_14086d260()->FUN_141473210());
    if (m_samples.size() < m_nSampleCount)
    {
        return;
    }
    m_nSampleCount = 0;
    if (m_samples.empty())
    {
        return;
    }
    float fHighest;
    float fLowest;
    float fAverage;
    fLowest = 1000.0f;
    fHighest = 0.0f;
    fAverage = 0.0f;
    MS2_FOR_EACH(float fFrame, m_samples)
    {
        if (fFrame < fLowest)
        {
            fLowest = fFrame;
        }
        if (fHighest < fFrame)
        {
            fHighest = fFrame;
        }
        fAverage = fAverage + fFrame;
    }
    fAverage = fAverage / (float)m_samples.size();
    if (FUN_140166440() != 0)
    {
        Unk_OptLog(FUN_140166440(), 0xb, 6, L"[SamplingFrame] sampleCount:{0} sampleCycleTick:{1}", m_nSampleCount, m_nSampleCycle);
    }
    if (FUN_140166440() != 0)
    {
        Unk_OptLog(FUN_140166440(), 0xb, 6, L"[SamplingFrame] lowest Frame:{0}", fLowest);
    }
    if (FUN_140166440() != 0)
    {
        Unk_OptLog(FUN_140166440(), 0xb, 6, L"[SamplingFrame] highest Frame:{0}", fHighest);
    }
    if (FUN_140166440() != 0)
    {
        Unk_OptLog(FUN_140166440(), 0xb, 6, L"[SamplingFrame] Avg Frame:{0}", fAverage);
    }
}

// @0x14161cc80
void COptimizer::FUN_14161cc80(int nFlags, int nLimit, int nEnabled, int nMode)
{
    if (nLimit < 0)
    {
        nLimit = 0;
    }
    m_nEnabled = nEnabled;
    m_selected.clear();
    FUN_14161dd30(0, 0);
    m_nMode = nMode;
    FUN_14161dd30(nFlags, nLimit);
}

// @0x14161cd00
void COptimizer::FUN_14161cd00()
{
    m_selected.clear();
    m_players.clear();
    m_suppress.clear();
    m_nSuppressed = 0;
    m_nUpdateOn = 1;
}

// @0x14161cd60
void COptimizer::FUN_14161cd60(unsigned __int64 nId)
{
    if (FUN_1403ed2d0() != 0 && preloadMode != 0 && preloadMode != 1)
    {
        if (FUN_141bca2e0(FUN_1403ed2d0()) != 0)
        {
            m_players.insert(nId);
        }
    }
}

// @0x14161cdd0
void COptimizer::FUN_14161cdd0(unsigned nId)
{
    unsigned __int64 nKey = nId;
    std::map<unsigned __int64, Entry>::iterator it = m_selected.find(nKey);
    if (it != m_selected.end())
    {
        m_selected.erase(it);
    }
}

// @0x14161ce60
int COptimizer::FUN_14161ce60(unsigned nId)
{
    if (FUN_1403ed2d0() != 0 && preloadMode != 0)
    {
        if (FUN_141bca2e0(FUN_1403ed2d0()) != 0)
        {
            PCBase* pPC = FUN_141bd1180(FUN_1403ed2d0(), nId);
            if (pPC != 0)
            {
                return pPC->vfunc_25();
            }
        }
    }
    return 0;
}

// @0x14161cee0
void COptimizer::FUN_14161cee0(int nSuppressed)
{
    m_nSuppressed = nSuppressed;
    if (m_nEnabled != 0)
    {
        if (FUN_1403ed2d0() != 0)
        {
            if (FUN_141bca2e0(FUN_1403ed2d0()) != 0)
            {
                FUN_14161db10(preloadMode);
            }
        }
    }
}

// @0x14161cf40
int COptimizer::FUN_14161cf40() const
{
    return m_nSuppressed;
}

// @0x14161cf60
void COptimizer::FUN_14161cf60(PCBase* pPC)
{
    if (pPC != 0)
    {
        unsigned __int64 nKey = pPC->FUN_141656a80();
        if (m_selected.find(nKey) != m_selected.end())
        {
            FUN_14161dbe0(pPC, 0);
        }
        else
        {
            FUN_14161dbe0(pPC, preloadMode);
        }
    }
}

// @0x14161d010
void COptimizer::FUN_14161d010(const egf::EntityID& kId)
{
    if (m_suppress.empty())
    {
        FUN_14161cee0(1);
    }
    m_suppress.insert(kId);
}

// @0x14161d070
void COptimizer::FUN_14161d070(const egf::EntityID& kId)
{
    if (!m_suppress.empty())
    {
        m_suppress.erase(kId);
        if (m_suppress.empty())
        {
            FUN_14161cee0(0);
            FUN_14109ac50(1);
        }
    }
}

// @0x14161d0f0
int COptimizer::FUN_14161d0f0() const
{
    int nResult;
    if (m_nUpdateOn2 != 0 && m_nUpdateOn != 0)
    {
        nResult = 1;
    }
    else
    {
        nResult = 0;
    }
    return nResult;
}

// @0x14161d130
void COptimizer::FUN_14161d130(bool bForce)
{
    if (FUN_1403ed2d0() != 0)
    {
        if (FUN_141bca2e0(FUN_1403ed2d0()) != 0)
        {
            std::map<unsigned __int64, PCBase*> preferred;
            PCBase* pLocal = FUN_141bd0cc0(FUN_1403ed2d0());
            if (pLocal != 0)
            {
                if ((preloadMode & 2) != 0 && FUN_141527280(pLocal))
                {
                    int nCount = FUN_1409670d0()->FUN_14162af00();
                    for (int i = 0; i < nCount; i = i + 1)
                    {
                        MS2Ptr<CPartyMember> spMember = FUN_1409670d0()->FUN_14162b360(i);
                        unsigned __int64 nKey = spMember->FUN_141637bb0();
                        PCBase* pOther = FUN_141bd1530(FUN_1403ed2d0(), nKey);
                        if (pOther != 0 && pLocal != pOther)
                        {
                            preferred[nKey] = pOther;
                        }
                    }
                }
                if ((preloadMode & 4) != 0)
                {
                    FUN_1413bcbc0(FUN_1403ed290(), preferred);
                }
            }
            std::map<unsigned __int64, Entry> selected;
            for (std::map<unsigned __int64, PCBase*>::iterator it = preferred.begin(); it != preferred.end(); ++it)
            {
                std::map<unsigned __int64, Entry>::iterator itOld = m_selected.find(it->first);
                if (itOld == m_selected.end())
                {
                    FUN_14161dbe0(it->second, preloadMode);
                    selected[it->first] = Entry(0, it->second);
                }
                else
                {
                    selected[itOld->first] = itOld->second;
                    m_selected.erase(itOld);
                }
            }
            if ((preloadMode & 8) != 0)
            {
                std::list<Entry> candidates;
                Unk_OptObjMap* pMap = FUN_141bd36b0(FUN_1403ed2d0());
                POSITION pos = FUN_140c20a10(pMap);
                while (pos != 0)
                {
                    TPtr<PC>& spRef = FUN_140c20a80(pMap, pos);
                    if (FUN_140aac420(spRef) != 0 && FUN_14161e580(spRef) == 0)
                    {
                        if (FUN_140aac440(spRef)->GetClassID() != 0x6200044)
                        {
                            if (FUN_140aac440(spRef)->GetClassID() != 0x6200047)
                            {
                                if (FUN_140aac440(spRef)->GetClassID() != 0x620005e)
                                {
                                    if (FUN_140aac440(spRef)->GetClassID() != 0x6200016)
                                    {
                                        unsigned __int64 nUid = FUN_140aac440(spRef)->FUN_141656a80();
                                        if (selected.find(nUid) == selected.end())
                                        {
                                            PCBase* pActor = FUN_140aac420(spRef);
                                            float fDistance = FUN_140aac440(spRef)->FUN_140f4a450();
                                            candidates.push_back(Entry(fDistance, pActor));
                                        }
                                    }
                                }
                            }
                        }
                    }
                    FUN_140c20a30(pMap, &pos);
                }
                if (bForce)
                {
                    for (std::list<Entry>::iterator it = candidates.begin(); it != candidates.end(); ++it)
                    {
                        unsigned __int64 nKey = it->m_pPC->FUN_141656a80();
                        if (selected.find(nKey) == selected.end())
                        {
                            FUN_14161dbe0(it->m_pPC, preloadMode);
                        }
                    }
                    m_selected.clear();
                }
                if (preferred.size() < (unsigned __int64)m_nLimit)
                {
                    candidates.sort();
                    unsigned __int64 nWant = (__int64)m_nLimit - preferred.size();
                    unsigned __int64 nAdded = 0;
                    std::list<Entry>::iterator it = candidates.begin();
                    while (it != candidates.end() && nAdded < nWant)
                    {
                        unsigned __int64 nKey = it->m_pPC->FUN_141656a80();
                        std::map<unsigned __int64, Entry>::iterator itOld = m_selected.find(nKey);
                        if (itOld == m_selected.end())
                        {
                            FUN_14161dbe0(it->m_pPC, 0);
                            selected[it->m_pPC->FUN_141656a80()] = Entry(0, it->m_pPC);
                        }
                        else
                        {
                            selected[it->m_pPC->FUN_141656a80()] = *it;
                            m_selected.erase(itOld);
                        }
                        nAdded = nAdded + 1;
                        ++it;
                    }
                }
            }
            for (std::map<unsigned __int64, Entry>::iterator it = m_selected.begin(); it != m_selected.end(); ++it)
            {
                PCBase* pOld = FUN_141bd1530(FUN_1403ed2d0(), it->first);
                if (pOld != 0)
                {
                    FUN_14161dbe0(pOld, preloadMode);
                }
            }
            m_selected.clear();
            if (!selected.empty())
            {
                m_selected = selected;
            }
        }
    }
}

// @0x14161db10
void COptimizer::FUN_14161db10(int nFlags)
{
    if (FUN_1403ed2d0() != 0)
    {
        if (FUN_141bca2e0(FUN_1403ed2d0()) != 0)
        {
            Unk_OptObjMap* pMap = FUN_141bd36b0(FUN_1403ed2d0());
            for (POSITION pos = FUN_140c20a10(pMap); pos != 0; FUN_140c20a30(pMap, &pos))
            {
                TPtr<PC> spActor(FUN_140c20a80(pMap, pos));
                FUN_14161dbe0(spActor.get(), nFlags);
            }
        }
    }
}

// @0x14161dbe0
void COptimizer::FUN_14161dbe0(PCBase* pPC, int nFlags)
{
    if (pPC != 0)
    {
        if (FUN_1409613d0(pPC) != 0)
        {
            return;
        }
        if (pPC->GetClassID() == 0x6200044)
        {
            return;
        }
        if (pPC->GetClassID() == 0x6200047)
        {
            return;
        }
        if (pPC->GetClassID() == 0x620005e)
        {
            return;
        }
        if (pPC->GetClassID() == 0x6200016)
        {
            return;
        }
        pPC->vfunc_24(nFlags);
        GameObject* pRidee = FUN_1416764a0(pPC);
        if (pRidee != 0)
        {
            pRidee->vfunc_24(nFlags);
        }
        GameObject* pWorldObject = FUN_141676a10(pPC);
        if (pWorldObject != 0)
        {
            pWorldObject->vfunc_24(nFlags);
        }
        GameObject* pAttached = FUN_1416625e0(pPC);
        if (pAttached != 0)
        {
            pAttached->vfunc_24(nFlags);
        }
    }
}

// @0x14161dd30
void COptimizer::FUN_14161dd30(int nFlags, int nLimit)
{
    m_nLimit = nLimit;
    preloadMode = nFlags;
    m_fUpdateTime = 0;
    if (FUN_1403ed2d0() != 0)
    {
        if (FUN_141bca2e0(FUN_1403ed2d0()) != 0)
        {
            if ((preloadMode & 8) != 0 && nLimit != 0)
            {
                FUN_14161d130(true);
            }
            else
            {
                FUN_14161db10(nFlags);
            }
        }
    }
}

// @0x14161e580
MyPC* FUN_14161e580(const TPtr<PC>& spPC)
{
    MyPC* pMyPC = 0;
    if (FUN_140aac420(spPC) ? true : false)
    {
        PC* pPC = FUN_140aac440(spPC);
        if (pPC->TypeCast(0x6200004, (void**)&pMyPC))
        {
            return pMyPC;
        }
    }
    return 0;
}

// @0x1416226d0
bool operator<(const COptimizer::Entry& left, const COptimizer::Entry& right)
{
    return left.m_fDistance < right.m_fDistance ? 1 : 0;
}

// @0x141622790
int COptimizer::FUN_141622790() const
{
    return m_nEnabled;
}

// @0x141625160
// The UCRT's memcpy_s (checked copy that zeroes the destination on failure), as an ordinary function.
#pragma function(memcpy, memset)
int FUN_141625160(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
