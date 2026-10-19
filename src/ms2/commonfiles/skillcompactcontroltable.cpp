// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSkillCompactControlTable: data/xml/table/SkillCompactControl.xml.
// MS2-UNIT: ?\skillcompactcontroltable.cpp
// MS2-RANGE: 0x1400d58e0-0x1400d5a30 .text$di
// MS2-RANGE: 0x142ca5b30-0x142ca5bd0 .text$yd
// MS2-RANGE: 0x140dca750-0x140dcf0c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$Unk_SocketPtr@VCCompactControlSkill@@@@QEAA@$$QEAV0@@Z 0x140dcb2d0 ; unique
// MS2-PIN: ??0?$Unk_SocketPtr@VCCompactControlSkill@@@@QEAA@H@Z 0x140dcb340 ; unique
// MS2-PIN: ??0?$Unk_SocketPtr@VCCompactControlSkill@@@@QEAA@PEAVCCompactControlSkill@@@Z 0x140dcb360 ; unique
// MS2-PIN: ??0?$Unk_SocketPtr@V?$CAtlList@V?$Unk_SocketPtr@VCCompactControlSkill@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCCompactControlSkill@@@@@ATL@@@ATL@@@@QEAA@$$QEAV0@@Z 0x140dcb3b0 ; unique
// MS2-PIN: ??0?$Unk_SocketPtr@V?$CAtlList@V?$Unk_SocketPtr@VCCompactControlSkill@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCCompactControlSkill@@@@@ATL@@@ATL@@@@QEAA@H@Z 0x140dcb3e0 ; unique
// MS2-PIN: ??1CNode@?$CAtlMap@IV?$Unk_SocketPtr@VCCompactControlSkill@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VCCompactControlSkill@@@@@3@@ATL@@QEAA@XZ 0x140dcb840 ; unique
// MS2-PIN: ??1CNode@?$CAtlMap@W4Unk_CcJob@@V?$Unk_SocketPtr@V?$CAtlList@V?$Unk_SocketPtr@VCCompactControlSkill@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCCompactControlSkill@@@@@ATL@@@ATL@@@@V?$CElementTraits@W4Unk_CcJob@@@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@V?$CAtlList@V?$Unk_SocketPtr@VCCompactControlSkill@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCCompactControlSkill@@@@@ATL@@@ATL@@@@@4@@ATL@@QEAA@XZ 0x140dcb860 ; unique
// MS2-PIN: ??1CPair@?$CAtlMap@IV?$Unk_SocketPtr@VCCompactControlSkill@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_SocketPtr@VCCompactControlSkill@@@@@3@@ATL@@QEAA@XZ 0x140dcb880 ; unique
// MS2-PIN: ?Reference@?$Unk_SocketPtr@VCCompactControlSkill@@@@CAXPEAVCPtred@@@Z 0x140dced80 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ?AddRefImpl@?$Unk_SocketPtr@VCCompactControlSkill@@@@AEBAXPEAX@Z 0x140dcedc0
// MS2-PIN: ?ReleaseImpl@?$Unk_SocketPtr@VCCompactControlSkill@@@@AEAAXPEAX@Z 0x140dcef00
// MS2-PIN: ??_7CSkillCompactControlTable@@6B?$TSingleton@VCSkillCompactControlTable@@@@@ 0x142e38ee8
// MS2-PIN: ??_7CSkillCompactControlTable@@6B?$CValidData@VCSkillCompactControlTable@@@@@ 0x142e38ef8
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlList@V?$Unk_SocketPtr@VCCompactControlSkill@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCCompactControlSkill@@@@@ATL@@@ATL@@@@6B@ 0x142e38f08
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\skillcompactcontroltable.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "skillcompactcontroltable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"

// The UCRT header-inline memmove_s (corecrt_memcpy_s.h) closes the CAtlMap instantiations.
#pragma function(memmove)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode) \
    { int _Expr_val = !!(expr); if (!(_Expr_val)) { errno = errorcode; _invalid_parameter_noinfo(); return errorcode; } }
// @0x140dcefa0
errno_t FUN_140dcefa0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0) return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
class Unk_140166410 { public: bool FUN_14036d570(int nFeature); };      // the content switches
Unk_140166410* FUN_140166410();
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14016a5c0(const char* psz, int n);
bool FUN_14028f710(Unk_140165cf0*);                                       // the element is usable
void FUN_1406363a0(Unk_140165cf0*, const char*, Unk_CcJob&);
void FUN_1408732e0(Unk_140165cf0*, const char*, __int64&);
void FUN_140873220(Unk_140165cf0*, const char*, unsigned&);
unsigned char FUN_1401d1320(CCacheData*);                                 // the file changed since it was loaded

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's flag (symbols.tsv); a local copy stays false -> "is not initialized" box
bool CSkillCompactControlTable::s_bInit;
#endif

// Function-level statics (.text$di): the three maps, the cache stamp of the file and the lock.
static ATL::CAtlMap<Unk_CcJob, Unk_CcSkillListPtr> s_jobSkills;
static ATL::CAtlMap<Unk_CcJob, __int64> s_baseSP;
static CCacheData s_cache;
static ATL::CAtlMap<unsigned, Unk_CcSkillPtr> s_skills;
static CLockCriticalSection s_lock;

// @0x140dca750
CSkillCompactControlTable::CSkillCompactControlTable()
{
}

// @0x140dca7b0
CSkillCompactControlTable::~CSkillCompactControlTable()
{
}

// @0x140dca800
int CSkillCompactControlTable::Load()
{
    if (!FUN_140166410()->FUN_14036d570(0x10))
        return 1;
    if (Unk_LockGuard guard = s_lock) {} else
    {
        s_skills.RemoveAll();
        s_jobSkills.RemoveAll();
        s_baseSP.RemoveAll();
    }
    CString strPath;
    strPath.Format("./data/xml/table/SkillCompactControl.xml");
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"파일을 읽을 수 없습니다[{0}]", strPath);
        return 0;
    }
    s_cache.FUN_1401d1160(strPath);
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pJob = pRoot->FUN_140165cf0("job"); pJob != 0; pJob = pJob->FUN_140168650("job"))
    {
        Unk_CcSkillListPtr spList(0);
        spList = Unk_SocketNew(0);
        Unk_CcJob nCode = Unk_CcJob_None;
        FUN_1406363a0(pJob, "code", nCode);
        __int64 nBaseSP = 50;
        FUN_1408732e0(pJob, "baseSP", nBaseSP);
        for (Unk_140165cf0* pSkill = pJob->FUN_140165cf0("skill"); pSkill != 0; pSkill = pSkill->FUN_140168650("skill"))
        {
            if (FUN_14028f710(pSkill))
            {
                Unk_CcSkillPtr spSkill(new CCompactControlSkill);
                FUN_140873220(pSkill, "id", spSkill->m_nSkillId);
                FUN_140873220(pSkill, "repeatCount", spSkill->m_nRepeatCount);
                spList->AddTail(spSkill);
                if (Unk_LockGuard guard = s_lock) {} else
                {
                    s_skills.SetAt(spSkill->m_nSkillId, spSkill);
                }
            }
        }
        if (Unk_LockGuard guard = s_lock) {} else
        {
            s_jobSkills.SetAt(nCode, spList);
            s_baseSP.SetAt(nCode, nBaseSP);
        }
    }
    SetInit(true);
    return 1;
}

// @0x140dcacd0
Unk_CcSkillPtr CSkillCompactControlTable::GetSkill(unsigned nSkillId)
{
    CheckInit();
    if (Unk_LockGuard guard = s_lock) {} else
    {
        if (FUN_1401d1320(&s_cache))
            Load();
        Unk_CcSkillPtr spSkill(0);
        s_skills.Lookup(nSkillId, spSkill);
        return spSkill;
    }
}

// @0x140dcada0
Unk_CcSkillListPtr CSkillCompactControlTable::GetJobSkills(Unk_CcJob nJob)
{
    CheckInit();
    if (Unk_LockGuard guard = s_lock) {} else
    {
        if (FUN_1401d1320(&s_cache))
            Load();
        Unk_CcSkillListPtr spList(0);
        s_jobSkills.Lookup(nJob, spList);
        return spList;
    }
}

// @0x140dcae70
__int64 CSkillCompactControlTable::GetBaseSP(Unk_CcJob nJob)
{
    CheckInit();
    __int64 nBaseSP;
    if (Unk_LockGuard guard = s_lock) {} else
    {
        if (FUN_1401d1320(&s_cache))
            Load();
        nBaseSP = 50;
        s_baseSP.Lookup(nJob, nBaseSP);
    }
    return nBaseSP;
}

// @0x140dcb4a0
CCompactControlSkill::CCompactControlSkill()
    : m_nSkillId(0), m_nRepeatCount(0)
{
}

// @0x140dcb800
CCompactControlSkill::~CCompactControlSkill()
{
}

// @0x140dcbc60
void CSkillCompactControlTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CSkillCompactControlTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140dcea70
void CSkillCompactControlTable::SetInit(bool b)
{
    s_bInit = b;
}

// @0x1401ba820
CPtred* FUN_1401ba820(CPtred* p)
{
    p->m_nRef = 1;
    return p;
}
