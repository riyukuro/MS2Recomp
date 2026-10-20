// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client skill table SkillDataTableCli: the common
// SkillDataTable plus the additional effect table (Table/additionaleffect*.xml), and the effect preloading of a skill
// or an additional effect level (CFilePreload). Method names are invented except LoadAdditionalFile.
// MS2-UNIT: ?\skilldatatablecli.cpp
// MS2-RANGE: 0x140aae580-0x140abc2b0 .text$mn
// MS2-RANGE: 0x1400c5340-0x1400c5460 .text$di
// MS2-PIN: ??_7SkillDataTableCli@@6B?$TSingleton@VSkillDataTableCli@@@@@ 0x142dd1668
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\skilldatatablecli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // xmlattr.h asserts (NDEBUG DLL build)
#include <algorithm>
#include <iterator>
#include "skilldatatablecli.h"
#include "filepreload_1.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
int FUN_1407ef260(TiXmlDocument& doc, const char* pszPath);    // skilloverlapcompare.cpp: loads an xml file
bool FUN_1411a4800(const CString& strPath, int nPriority);      // preloads one effect file (false: not found)

// The shop sort names and two attribute names of a shared header (dynamic initializers of every including unit).
// @0x1400c5340
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400c5400
static CString s_skill("skill");

// @0x1400c5430
static CString s_stun("stun");

// The unit's log calls (FMT_VARIADIC wrappers over CLogString::FUN_1406530d0). The one-argument form is the
// exe's 0x140177a80 (first emitted by additionalactionadditional.cpp); the others are emitted here:
//   Log<unsigned, CString>                    0x140ab1290
//   Log<unsigned, unsigned short, int>        0x140ab0bc0
//   Log<unsigned, unsigned short, CString>    0x140ab0f30
// (the tags of the static initializers above must not reach these definitions).
template <class T>
inline void Unk_SkillTableLog(CLogString* log, int level, int category, const wchar_t* format, const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}
// @0x140ab1290
template <class T, class U>
inline void Unk_SkillTableLog(CLogString* log, int level, int category, const wchar_t* format, const T& first,
                              const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}
template <class T, class U, class V>
inline void Unk_SkillTableLog(CLogString* log, int level, int category, const wchar_t* format, const T& first,
                              const U& second, const V& third)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(third)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second, third), args));
}

// @0x140aae580
SkillDataTableCli::SkillDataTableCli()
{
    LoadGlideData();
    LoadSkillData();
    LoadAdditional();
}

// @0x140aae640
void SkillDataTableCli::ReloadFiles()
{
    Reload();
}
MS2_REPLACE_METHOD(0x140aae640, SkillDataTableCli, ReloadFiles, 24, 0xCDC5B560);

// @0x140aae660
SkillAttackData* SkillDataTableCli::FindSkillAttack(unsigned nSkillId, unsigned short nLevel, CString strPoint)
{
    MS2Ptr<SkillLevelData> spLevel = GetSkillLevelData(nSkillId, nLevel);
    if (spLevel == 0)
        return 0;
    return spLevel->FUN_140804030(strPoint);
}
MS2_REPLACE_METHOD(0x140aae660, SkillDataTableCli, FindSkillAttack, 177, 0xF1993DA4);

// Not hooked (reads TSingleton<CFilePreload>::s_instance through GetInstance).
// @0x140aae720
void SkillDataTableCli::PreloadSkill(unsigned nSkillId, unsigned short nLevel, int nPriority)
{
    MS2Ptr<SkillData> spSkill = GetSkillData(nSkillId);
    if (spSkill.get() != 0)
    {
        MS2Ptr<SkillLevelData> spLevel = spSkill->FUN_1407e90a0(nLevel);
        if (spLevel)
        {
            for (int nMotion = 0; nMotion < spLevel->FUN_140804270(); nMotion++)
            {
                SkillMotionData* pMotion = spLevel->FUN_140803f00(nMotion);
                if (pMotion != 0)
                {
                    if (!FUN_1411a4800(pMotion->m_strMotionEffect, nPriority))
                        Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                          L"Skill PreLoad Effect Failed (motionEffect) ID:{0}", spSkill->GetId());
                    if (!FUN_1411a4800(pMotion->m_strSplashInvokeEffect, nPriority))
                        Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                          L"Skill PreLoad Effect Failed (splashInvokeEffect) ID:{0}", spSkill->GetId());
                    if (!FUN_1411a4800(pMotion->m_strLoopEffect, nPriority))
                        Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                          L"Skill PreLoad Effect Failed (loopEffect) ID:{0}", spSkill->GetId());
                    if (!FUN_1411a4800(pMotion->m_strEndEffect, nPriority))
                        Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                          L"Skill PreLoad Effect Failed (loopEffect) ID:{0}", spSkill->GetId());
                    if (!FUN_1411a4800(pMotion->m_strSplashEndEffect, nPriority))
                        Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                          L"Skill PreLoad Effect Failed (splashEndEffect) ID:{0}", spSkill->GetId());
                    if (!FUN_1411a4800(pMotion->m_strSplashDurationCastEffect, nPriority))
                        Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                          L"Skill PreLoad Effect Failed (splashDurationCastEffect) ID:{0}", spSkill->GetId());
                    for (POSITION pos = pMotion->m_mapTagEffects.GetHeadPosition(); pos != NULL;
                         pMotion->m_mapTagEffects.GetNext(pos))
                    {
                        if (!FUN_1411a4800(pMotion->m_mapTagEffects.GetValueAt(pos), nPriority))
                            Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                              L"Skill PreLoad Effect Failed (tag2Effects) ID:{0} Tag:{1}", spSkill->GetId(),
                                              pMotion->m_mapTagEffects.GetValueAt(pos));
                    }
                    for (int nAttack = 0; pMotion->FUN_140807e20(nAttack) != 0; nAttack++)
                    {
                        const SkillAttackData* pAttack = pMotion->FUN_140807e20(nAttack);
                        const SkillArrow& arrow = pAttack->m_arrow;
                        if (!FUN_1411a4800(arrow.m_strEffect, nPriority))
                            Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                              L"Skill PreLoad Effect Failed (arrow.effect) ID:{0}", spSkill->GetId());
                        if (!FUN_1411a4800(arrow.m_strEffectRemain, nPriority))
                            Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                              L"Skill PreLoad Effect Failed (arrow.effectRemain) ID:{0}", spSkill->GetId());
                        if (!FUN_1411a4800(arrow.m_strEffectDestroy, nPriority))
                            Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                              L"Skill PreLoad Effect Failed (arrow.effectDestroy) ID:{0}", spSkill->GetId());
                        if (!FUN_1411a4800(arrow.m_strTargetKeepEffect, nPriority))
                            Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                              L"Skill PreLoad Effect Failed (arrow.targetKeepEffect) ID:{0}", spSkill->GetId());
                        const SkillDamage& damage = pAttack->m_damage;
                        if (!FUN_1411a4800(damage.m_strEffectHit, nPriority))
                            Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                              L"Skill PreLoad Effect Failed (damage.effectHit) ID:{0}", spSkill->GetId());
                        if (!FUN_1411a4800(damage.m_strEffectRemain, nPriority))
                            Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x134,
                                              L"Skill PreLoad Effect Failed (damage.effectRemain) ID:{0}", spSkill->GetId());
                        for (unsigned i = 0; i < pAttack->m_vSkill.size(); i++)
                        {
                            MS2Ptr<SkillActionSkill> spAction = pAttack->m_vSkill[i];
                            if (spAction == 0)
                                continue;
                            for (unsigned j = 0; j < spAction->m_arrSkillID.GetCount(); j++)
                            {
                                if (spAction->m_arrSkillID[j] == nSkillId)
                                    continue;
                                TSingleton<CFilePreload>::GetInstance()->FUN_141210540(
                                    spAction->m_arrSkillID[j], spAction->m_arrLevel[j], nPriority);
                            }
                        }
                        for (const MS2Ptr<SkillActionAdditional>& spAdditional : pAttack->m_vAdditional)
                        {
                            if (spAdditional == 0)
                                continue;
                            PreloadAdditional(spAdditional->m_nAdditionalID, spAdditional->m_nLevel, nPriority);
                        }
                    }
                }
            }
            for (const MS2Ptr<SkillActionAdditional>& spAdditional : spLevel->m_vAdditional)
                PreloadAdditional(spAdditional->m_nAdditionalID, spAdditional->m_nLevel, nPriority);
        }
    }
}

// Not hooked (reads TSingleton<CFilePreload>::s_instance through GetInstance).
// @0x140aaf190
void SkillDataTableCli::PreloadAdditional(unsigned nId, unsigned short nLevel, int nPriority)
{
    MS2Ptr<AdditionalLevelData> spLevel = FUN_140aafef0(nId, nLevel);
    if (spLevel == 0)
        return;
    if (!FUN_1411a4800(spLevel->m_motion.m_strStartEffect, nPriority))
        Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x13,
                          L"AdditionalEffect Failed PreLoad startEffect: ID:{0} Level:{1} {2}", nId, nLevel,
                          spLevel->m_motion.m_strStartEffect);
    if (!FUN_1411a4800(spLevel->m_motion.m_strKeepEffect, nPriority))
        Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x13,
                          L"AdditionalEffect Failed PreLoad keepEffect: ID:{0} Level:{1} {2}", nId, nLevel,
                          spLevel->m_motion.m_strKeepEffect);
    if (!FUN_1411a4800(spLevel->m_motion.m_strStopEffect, nPriority))
        Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x13,
                          L"AdditionalEffect Failed PreLoad stopEffect: ID:{0} Level:{1} {2}", nId, nLevel,
                          spLevel->m_motion.m_strStopEffect);
    if (!FUN_1411a4800(spLevel->m_motion.m_strInvokeEffect, nPriority))
        Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 2, 0x13,
                          L"AdditionalEffect Failed PreLoad invokeEffect: ID:{0} Level:{1} {2}", nId, nLevel,
                          spLevel->m_motion.m_strInvokeEffect);
    for (const MS2Ptr<AdditionalActionSkill>& spSkill : spLevel->m_vSkill)
    {
        if (spSkill == 0)
            continue;
        if (spSkill->m_nSkillID != 0)
            TSingleton<CFilePreload>::GetInstance()->FUN_141210540(spSkill->m_nSkillID, spSkill->m_nLevel, nPriority);
    }
    for (const MS2Ptr<AdditionalActionAdditional>& spAdditional : spLevel->m_vAdditional)
    {
        if (spAdditional == 0)
            continue;
        for (unsigned i = 0; i < spAdditional->m_arrSkillID.GetCount(); i++)
        {
            if (spAdditional->m_arrSkillID[i] == nId)
                continue;
            PreloadAdditional(spAdditional->m_arrSkillID[i], spAdditional->m_arrLevel[i], nPriority);
        }
    }
}

// @0x140aaf6a0
bool SkillDataTableCli::CheckAdditionalChain(MS2Ptr<SkillLevelData> spLevel, unsigned nDepth)
{
    if (spLevel == 0)
        return true;
    if (nDepth == 0)
        return false;
    Unk_SkillTableLog(TSingleton<CLogString>::GetInstance(), 0xc, 0x13, L"LevelData = {0}, {1}, {2}",
                      spLevel->FUN_140803dc0(), spLevel->FUN_140803df0(), nDepth);
    for (const MS2Ptr<SkillActionAdditional>& spAdditional : spLevel->m_vAdditional)
    {
        if (CheckSkillChain(spAdditional->m_nAdditionalID, spAdditional->m_nLevel, spLevel->FUN_140803dc0(),
                            spLevel->FUN_140803df0(), nDepth) == 0)
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140aaf6a0, SkillDataTableCli, CheckAdditionalChain, 525, 0x4B9F6707);

// @0x140aaf8c0
int SkillDataTableCli::CheckSkillChain(unsigned nId, unsigned short nLevel, unsigned nSkillId,
                                       unsigned short nSkillLevel, unsigned nDepth)
{
    MS2Ptr<AdditionalLevelData> spLevel = FUN_140aafef0(nId, nLevel);
    if (spLevel == 0)
        return 1;
    for (const MS2Ptr<AdditionalActionSkill>& spSkill : spLevel->m_vSkill)
    {
        if (spSkill == 0 || spSkill->m_nSkillID == 0)
            continue;
        if (spSkill->m_nSkillID == nSkillId && spSkill->m_nLevel == nSkillLevel)
            return 0;
        MS2Ptr<SkillLevelData> spNext = GetSkillLevelData(spSkill->m_nSkillID, spSkill->m_nLevel);
        if (spNext == 0)
            continue;
        if (!CheckAdditionalChain(spNext, nDepth - 1))
            return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140aaf8c0, SkillDataTableCli, CheckSkillChain, 588, 0x8FF74872);

// @0x140aafb20
void SkillDataTableCli::GetSkillIds(std::set<unsigned>& out)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    for (std::pair<const unsigned, MS2Ptr<SkillData> > entry : m_skills)
    {
        if (entry.second.get() != 0)
            out.insert(entry.second->GetId());
    }
}
MS2_REPLACE_METHOD(0x140aafb20, SkillDataTableCli, GetSkillIds, 257, 0xB119FA4C);

// @0x140aafc30
void SkillDataTableCli::GetGlides(std::vector<MS2Ptr<SkillGlideData> >& out)
{
    Unk_CriticalSectionLock lock(m_cs, 1);
    std::transform(m_glides.begin(), m_glides.end(), std::back_inserter(out),
                   [](const std::pair<const int, MS2Ptr<SkillGlideData> >& entry) { return entry.second; });
    std::sort(out.begin(), out.end(), [](const MS2Ptr<SkillGlideData>& a, const MS2Ptr<SkillGlideData>& b) {
        return (unsigned)a->FUN_140802ab0() < (unsigned)b->FUN_140802ab0();
    });
}
MS2_REPLACE_METHOD(0x140aafc30, SkillDataTableCli, GetGlides, 298, 0x5ED668CE);

// @0x140aafd60
MS2Ptr<AdditionalData> SkillDataTableCli::GetAdditional(unsigned nId)
{
    if (nId == 0)
        return nullptr;
    Unk_CriticalSectionLock lock(m_csAdditional, 1);
    std::unordered_map<unsigned, MS2Ptr<AdditionalData> >::iterator it = m_additionals.find(nId);
    if (it == m_additionals.end())
        return nullptr;
    return it->second;
}
MS2_REPLACE_METHOD(0x140aafd60, SkillDataTableCli, GetAdditional, 278, 0xFF6DCA0C);

// MS2-FUNCTIONAL: the exe re-extends the level (movzx ecx, word; movzx r9d, cx) before the call; no source form found.
// @0x140aafe80
MS2Ptr<AdditionalLevelData> SkillDataTableCli::GetAdditionalLevel(unsigned __int64 nKey)
{
    unsigned short nLevel = (unsigned short)AdditionalLevelData::GetKeyLevel(nKey);
    return FUN_140aafef0((int)AdditionalLevelData::GetKeyID(nKey), nLevel);
}
MS2_REPLACE_METHOD(0x140aafe80, SkillDataTableCli, GetAdditionalLevel, 100, 0x596DA5D6);

// @0x140aafef0
MS2Ptr<AdditionalLevelData> SkillDataTableCli::FUN_140aafef0(int nId, unsigned short nLevel)
{
    MS2Ptr<AdditionalData> spData = GetAdditional(nId);
    if (spData == 0)
        return nullptr;
    return spData->GetLevel(nLevel);
}
MS2_REPLACE_METHOD(0x140aafef0, SkillDataTableCli, FUN_140aafef0, 182, 0x91ABDFD2);

// @0x140aaffb0
std::set<unsigned>* SkillDataTableCli::GetAdditionalGroup(unsigned nGroupId)
{
    Unk_CriticalSectionLock lock(m_csAdditional, 1);
    std::map<unsigned, std::set<unsigned> >::iterator it = m_additionalGroups.find(nGroupId);
    if (it == m_additionalGroups.end())
        return 0;
    return &it->second;
}
MS2_REPLACE_METHOD(0x140aaffb0, SkillDataTableCli, GetAdditionalGroup, 191, 0x1B08DDAA);

// @0x140ab0080
std::vector<MS2Ptr<AdditionalData> > SkillDataTableCli::GetAdditionals()
{
    std::vector<MS2Ptr<AdditionalData> > vOut;
    for (std::pair<const unsigned, MS2Ptr<AdditionalData> > entry : m_additionals)
        vOut.push_back(entry.second);
    return vOut;
}
MS2_REPLACE_METHOD(0x140ab0080, SkillDataTableCli, GetAdditionals, 235, 0x04379D47);

// @0x140ab0180
void SkillDataTableCli::LoadAdditionalFile(CString strPath)
{
    TiXmlDocument doc;
    if (FUN_1407ef260(doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    for (Unk_140165cf0* pElem : pRoot->FUN_140165cf0("additional"))
    {
        MS2Ptr<AdditionalData> spData(new AdditionalData);
        spData->Load(pElem);
        Unk_CriticalSectionLock lock(m_csAdditional, 1);
        std::unordered_map<unsigned, MS2Ptr<AdditionalData> >::iterator it = m_additionals.find(spData->GetID());
        if (it != m_additionals.end())
        {
            if (spData->GetFirstLevelGroupIDs() != 0)
            {
                std::set<unsigned>& group = m_additionalGroups[spData->GetFirstLevelGroupIDs()];
                group.erase(spData->GetID());
            }
            m_additionals.erase(spData->GetID());
        }
        m_additionals.insert(std::make_pair(spData->GetID(), spData));
        if (spData->GetFirstLevelGroupIDs() != 0)
        {
            std::set<unsigned>& group = m_additionalGroups[spData->GetFirstLevelGroupIDs()];
            group.insert(spData->GetID());
        }
    }
}
MS2_REPLACE_METHOD(0x140ab0180, SkillDataTableCli, LoadAdditionalFile, 1046, 0xD60AF176);

// The preloader singleton (the explicit TSingleton<CFilePreload> of filepreload_1.h; first used here).
// @0x140ab7a10
CFilePreload* TSingleton<CFilePreload>::GetInstance()
{
    return s_instance;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9fbe0-0x142c9fc50 .text$yd
