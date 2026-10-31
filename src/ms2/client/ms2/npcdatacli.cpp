// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NpcDataCli (a client npc row of NpcData/<nnn>.xml) and the
// NpcDataTableCli that loads and caches them, plus the container glue of their members.
// MS2-UNIT: ?\npcdatacli.cpp
// MS2-RANGE: 0x140a7beb0-0x140a848a0 .text$mn
// MS2-PIN: ??1NpcDataTableCli@@UEAA@XZ 0x140a80ae0
// MS2-PIN: ??_GNpcDataTableCli@@UEAAPEAXI@Z 0x140a816c0
// MS2-PIN: ??_GNpcDataCli@@UEAAPEAXI@Z 0x140a81680
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0V?$tuple@AEBI@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@QEAA@AEAV?$tuple@AEBI@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140a7d5e0 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_List_buy@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@@2@@std@@QEAAPEAU?$_List_node@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@PEAX@1@PEAU21@0AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140a7d680 ; unique
// MS2-PIN: ??$_Insert@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$list@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@@2@@std@@QEAAXV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@@std@@@std@@U_Iterator_base0@2@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140a7e260 ; unique
// MS2-PIN: ??$_Try_emplace@AEBI$$V@?$unordered_map@IV?$MS2Ptr@VNpcDataCli@@@@U?$hash@I@std@@U?$equal_to@I@3@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@@std@@@std@@@std@@_N@1@AEBI@Z 0x140a7ec60 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140a7f320 ; unique
// MS2-PIN: ??$emplace@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Hash@V?$_Umap_traits@IV?$MS2Ptr@VNpcDataCli@@@@V?$_Uhash_compare@IU?$hash@I@std@@U?$equal_to@I@2@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@@std@@@std@@@std@@_N@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140a7f5b0 ; unique
// MS2-PIN: ??$emplace_front@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$list@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@@2@@std@@QEAAXAEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140a7f6d0 ; unique
// MS2-PIN: ??$insert@AEAU?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@X@?$map@IV?$MS2Ptr@VNpcDataCli@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@std@@@std@@@std@@@std@@_N@1@AEAU?$pair@$$CBIV?$MS2Ptr@VNpcDataCli@@@@@1@@Z 0x140a7fa40 ; unique
// MS2-PIN: ??_Ginvalid_argument@std@@UEAAPEAXI@Z 0x140a81700 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@HV?$Unk_BmPtr@VCNpcRegionSpawnData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VCNpcRegionSpawnData@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140a81850 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$Unk_BmPtr@VCNpcRegionSpawnData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VCNpcRegionSpawnData@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x140a818a0 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\npcdatacli.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "npcdatacli.h"

#include <ppl.h>
#include "ms2/ms2format.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/commoneffectdummy.h"

// ---- unit-local views of exe objects ----------------------------------------------------------------------------

// The common log (FUN_140166440()) and file system (FUN_140166420()).
class Unk_NpcLog
{
public:
    void FUN_14015eb90(int level, int flags, const wchar_t* format, const CStringA& arg);
};
class CLogString* GetLogString();   // C3: was FUN_140166440
class Unk_NpcFileSystem : public CFileSystem
{
};
CStringA FUN_14071a5b0(const CStringA& strDir, const CStringA& strFile);
CStringA FUN_140513200(const char* szFormat, const int& n);       // StringFormat<int>: the identical-code copy Load calls

// The default effect dummy table (reinterpret_cast<Unk_NpcEffectDummies*>(TSingleton<CommonEffectDummy>::GetInstance())): CommonEffectDummy, its row count and row getter.
class Unk_NpcEffectDummies
{
public:
    size_t FUN_140a40200();
    bool FUN_140a40230(unsigned nIndex, CEffectDummy& dummy);
};

// An entry of the Common::Constants table (the shared Object header, then the value).
void FUN_1402b7560(void*, const char*);
template <class T> struct alignas(8) Unk_NpcConstant
{
    char m_pad_00[8];
    bool m_bSet;                                            // +0x08
    char m_pad_09[0x47];
    T m_value;                                              // +0x50
    // @0x140a81910
    T* Get()
    {
        if (!m_bSet)
            FUN_1402b7560(this, "constants is not set");
        return &m_value;
    }
};
struct Unk_NpcConstants
{
    char m_pad_00[0xae70];
    Unk_NpcConstant<unsigned> m_friendly;                   // +0xae70
    Unk_NpcConstant<unsigned> m_class1;                     // +0xaec8
    Unk_NpcConstant<unsigned> m_unknownaf20;                // +0xaf20
    Unk_NpcConstant<unsigned> m_class3or7;                  // +0xaf78
    Unk_NpcConstant<unsigned> m_class4or6;                  // +0xafd0
};
Unk_NpcConstants* FUN_1401d3200_1();
unsigned int Unk_ColorValue(struct Unk_ConstColor const&);   // C3: was FUN_14056d500

// @0x140a7d630
unsigned NpcConstantValue(Unk_NpcConstant<unsigned>* p)
{
    return Unk_ColorValue(*(struct Unk_ConstColor const*)(p->Get()));
}

// ---- NpcDataCli ---------------------------------------------------------------------------------------------------

// @0x140a7beb0
NpcDataCli::NpcDataCli() : m_bHpBar(false), m_bAttackDamage(false), m_bNametag(false), m_nGender(3)
{
}

// @0x140a7c020
NpcDataCli::~NpcDataCli()
{
}

// @0x140a7c150
bool NpcDataCli::Different(const NpcDataCli* pOther)
{
    if (CNpcData::operator!=(*pOther))
        return true;
    if (m_strIcon != pOther->m_strIcon)
        return true;
    if (m_strMinimapIcon != pOther->m_strMinimapIcon)
        return true;
    if (m_strShopIcon != pOther->m_strShopIcon)
        return true;
    if (m_strSoundStart != pOther->m_strSoundStart)
        return true;
    if (m_strSoundEnd != pOther->m_strSoundEnd)
        return true;
    if (m_strSoundDead != pOther->m_strSoundDead)
        return true;
    if (m_strRegenEffect != pOther->m_strRegenEffect)
        return true;
    if (m_strDeadEffect != pOther->m_strDeadEffect)
        return true;
    if (m_strDamageEffect != pOther->m_strDamageEffect)
        return true;
    if (m_strCreateEffect != pOther->m_strCreateEffect)
        return true;
    if (m_strKeepEffect != pOther->m_strKeepEffect)
        return true;
    if (m_strIllust != pOther->m_strIllust)
        return true;
    if (m_bHpBar != pOther->m_bHpBar)
        return true;
    if (m_bAttackDamage != pOther->m_bAttackDamage)
        return true;
    if (m_bNametag != pOther->m_bNametag)
        return true;
    if (m_nGender != pOther->m_nGender)
        return true;
    return false;
}

// @0x140a7c420
bool NpcDataCli::LoadXml(Unk_140165cf0* pElem)
{
    if (!CNpcData::LoadXml(pElem))
        return false;
    FUN_1408733e0(pElem, "iconName", m_strIcon);
    FUN_1408733e0(pElem, "minimapIconName", m_strMinimapIcon);
    FUN_1408733e0(pElem, "shopIconName", m_strShopIcon);
    FUN_1408733e0(pElem, "npcSoundStart", m_strSoundStart);
    FUN_1408733e0(pElem, "npcSoundEnd", m_strSoundEnd);
    FUN_1408733e0(pElem, "npcSoundDead", m_strSoundDead);
    FUN_1408733e0(pElem, "regenEffect", m_strRegenEffect);
    FUN_1408733e0(pElem, "deadEffect", m_strDeadEffect);
    FUN_1408733e0(pElem, "damageEffect", m_strDamageEffect);
    FUN_1408733e0(pElem, "createEffect", m_strCreateEffect);
    FUN_1408733e0(pElem, "keepEffect", m_strKeepEffect);
    FUN_1408733e0(pElem, "illust", m_strIllust);
    FUN_1408730a0(pElem, "hpBar", m_bHpBar);
    FUN_1408730a0(pElem, "attackDamage", m_bAttackDamage);
    FUN_1408730a0(pElem, "nametag", m_bNametag);
    FUN_1408731e0(pElem, "gender", m_nGender);
    {
        CEffectDummy dummy;
        size_t nCount = reinterpret_cast<Unk_NpcEffectDummies*>(TSingleton<CommonEffectDummy>::GetInstance())->FUN_140a40200();
        m_effectDummies.reserve(nCount);
        for (size_t i = 0; i < nCount; i++)
        {
            if (reinterpret_cast<Unk_NpcEffectDummies*>(TSingleton<CommonEffectDummy>::GetInstance())->FUN_140a40230((unsigned)i, dummy))
                m_effectDummies.push_back(dummy);
        }
        Unk_140165cf0* pDummies = pElem->FUN_140165cf0("effectdummy");
        if (pDummies != 0)
        {
            for (Unk_140165cf0* pNode = pDummies->FUN_140165cf0("dummy"); pNode != 0; pNode = pNode->NextSiblingElement())
            {
                bool bFound = false;
                CStringA strName;
                FUN_1408733e0(pNode, "name", strName);
                for (size_t i = 0; i < m_effectDummies.size(); i++)
                {
                    CEffectDummy* pDummy = &m_effectDummies[i];
                    if (pDummy->GetName() == strName)
                    {
                        pDummy->Parse(pNode);
                        bFound = true;
                        break;
                    }
                }
                if (!bFound)
                {
                    CEffectDummy added;
                    added.Parse(pNode);
                    m_effectDummies.push_back(added);
                }
            }
        }
    }
    return true;
}

// @0x140a7c8d0
bool NpcDataCli::GetNametag()
{
    return m_bNametag;
}

// @0x140a7c8f0
bool NpcDataCli::IsFemale()
{
    return m_nGender == 1;
}

// @0x140a7c930
bool NpcDataCli::IsBossNpc()
{
    return IsBoss();
}

// @0x140a7c950
int NpcDataCli::GetUnknown12()
{
    return 0x12;
}

// @0x140a7c970
unsigned NpcDataCli::GetClassConstant()
{
    if (m_nFriendly != 0)
        return NpcConstantValue(&FUN_1401d3200_1()->m_friendly);
    switch (GetClass())
    {
    case 1:
        return NpcConstantValue(&FUN_1401d3200_1()->m_class1);
    case 3:
    case 7:
        return NpcConstantValue(&FUN_1401d3200_1()->m_class3or7);
    case 4:
    case 6:
        return NpcConstantValue(&FUN_1401d3200_1()->m_class4or6);
    }
    return 0;
}

// ---- NpcDataTableCli ----------------------------------------------------------------------------------------------

// @0x140a7ca40
NpcDataTableCli::NpcDataTableCli()
{
}

// @0x140a7cab0
MS2Ptr<NpcDataCli> NpcDataTableCli::Find(unsigned nId)
{
    unsigned nFile = nId / 100000;
    if (NeedsLoad(nFile))
        Load(nFile);
    Unk_CriticalSectionLock guard(m_lock, 1);
    std::unordered_map<unsigned, MS2Ptr<NpcDataCli> >::iterator it = m_mapNpc.find(nId);
    if (it == m_mapNpc.end())
        return MS2Ptr<NpcDataCli>(nullptr);
    return it->second;
}

// @0x140a7cbe0
void FUN_140a7cbe0(void*)
{
}

// @0x140a7cbf0
void NpcDataTableCli::LoadAll()
{
    Concurrency::parallel_for_each(std::begin(m_mapLoaded), std::end(m_mapLoaded), [this](std::pair<const unsigned long, bool> entry) {
        Load((int)entry.first);
    });
}

// @0x140a7cc70
void NpcDataTableCli::IndexAllRegions()
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    if (m_mapTag[0].GetCount() > 0)
        return;
    for (POSITION pos = m_mapSpawn.GetStartPosition(); pos != 0; m_mapSpawn.GetNext(pos))
        IndexRegionSpawn(m_mapSpawn.GetValueAt(pos));
}

// @0x140a7cd70
void NpcDataTableCli::Load(int nFile)
{
    CStringA strPath = FUN_14071a5b0("NpcData", FUN_140513200("{0:03d}.xml", nFile));
    TiXmlDocument doc;
    if (((class Unk_NpcFileSystem*)GetFileSystem())->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        ((class Unk_NpcLog*)GetLogString())->FUN_14015eb90(1, 0x13, L"NpcDataTable ::ReadFromFile: File not found {0}", strPath);
        return;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        ((class Unk_NpcLog*)GetLogString())->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    std::vector<MS2Ptr<NpcDataCli> > list;
    list.reserve(100);
    for (Unk_140165cf0* pNode : pRoot->FUN_140165cf0("npc"))
    {
        MS2Ptr<NpcDataCli> pData(new NpcDataCli);
        if (!pData->Load(pNode))
            continue;
        list.push_back(pData);
    }
    Unk_CriticalSectionLock guard(m_lock, 1);
    m_mapLoaded[reinterpret_cast<const unsigned long&>(nFile)] = true;
    for (MS2Ptr<NpcDataCli> pData : list)
        m_mapNpc[pData->GetId()] = pData;
}

// @0x140a7d1a0
CStringA NpcDataTableCli::GetIllust(unsigned nId)
{
    MS2Ptr<NpcDataCli> pData = Find(nId);
    if (pData.get() != 0)
        return pData->m_strIllust;
    return CStringA("");
}

// @0x140a7d260
void NpcDataTableCli::Collect(std::map<unsigned, MS2Ptr<NpcDataCli> >& mapOut)
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    for (std::pair<const unsigned, MS2Ptr<NpcDataCli> > entry : m_mapNpc)
    {
        if (entry.second.get() != 0)
            mapOut.insert(static_cast<const std::pair<const unsigned, MS2Ptr<NpcDataCli> >&>(entry));
    }
}

// @0x140a84780
MS2_EMIT_CRT_MEMMOVE_S();

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x140a7d630, NpcConstantValue, 32, 0xE0140F56);
MS2_REPLACE_METHOD(0x140a7c150, NpcDataCli, Different, 711, 0xD224B019);
MS2_REPLACE_METHOD(0x140a7c420, NpcDataCli, LoadXml, 1191, 0x8292CE11);
MS2_REPLACE_METHOD(0x140a7c8d0, NpcDataCli, GetNametag, 18, 0x6892930A);
MS2_REPLACE_METHOD(0x140a7c8f0, NpcDataCli, IsFemale, 48, 0xE93E6AD5);
MS2_REPLACE_METHOD(0x140a7c930, NpcDataCli, IsBossNpc, 24, 0x026BE602);
MS2_REPLACE_METHOD(0x140a7c950, NpcDataCli, GetUnknown12, 11, 0xCC810D29);
MS2_REPLACE_METHOD(0x140a7c970, NpcDataCli, GetClassConstant, 162, 0xFD3F06CD);
MS2_REPLACE(0x140a7cbe0, FUN_140a7cbe0, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x140a7cbf0, NpcDataTableCli, LoadAll, 107, 0xE972F120);
MS2_REPLACE_METHOD(0x140a7cc70, NpcDataTableCli, IndexAllRegions, 240, 0x62AFCDC1);
MS2_REPLACE_METHOD(0x140a7d260, NpcDataTableCli, Collect, 228, 0x687C6E21);

