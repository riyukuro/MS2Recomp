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
#include "effectservice.h"
#include <string.h>
#pragma intrinsic(strcmp)
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/placeholder/nipoint3.h"
class TiXmlElement;
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view




int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- the unit's header statics (three headers each define "skill", "stun" and a handle) ----
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static CString s_strSkill1 = "skill";                // @0x1400e7d30
static CString s_strStun1 = "stun";                  // @0x1400e7d60
static egf::EntityID s_handle1(0);               // @0x1400e7d90
static CString s_strSkill2 = "skill";                // @0x1400e7db0
static CString s_strStun2 = "stun";                  // @0x1400e7de0
static egf::EntityID s_handle2(0);               // @0x1400e7e10
static CString s_strSkill3 = "skill";                // @0x1400e7e30
static CString s_strStun3 = "stun";                  // @0x1400e7e60
static egf::EntityID s_handle3(0);               // @0x1400e7e90

// Unrecovered helpers (the same xml loader helpers the other table units use).
// C3 #12: was a local TiXml view







class Unk_140166420 : public CFileSystem { };
class CLogString* GetLogString();   // C3: was FUN_140166440
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was FUN_14015eb90
CString GetXmlPath(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString ToCString(const char* psz, int n);
int FUN_1408731e0(TiXmlElement*, const char*, int&);
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
CString FUN_140188f50(const char* psz, int n);

// The view-distance probe (the host, its local actor).
class Unk_SkipHost { public: };
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
bool IsNearlyEqual(float a, float b);                      // float equality test

// The caller's world transform (NiTransform layout, 0x34 bytes: rotate 0x24, translate, scale). Only the translate is read.
class Unk_SkipEffect
{
public:
    char m_pad_00[0x24];            // NiMatrix3 m_Rotate
    efd::Point3 m_pos;              // +0x24 m_Translate
    float m_fScale;                 // +0x30
};
MS2_CHECK_SIZE(Unk_SkipEffect, 0x34);

// An entry of the live effect list the skip query walks.
class Unk_SkipItem
{
public:
    char m_pad_00[0x18];
    int m_nKind;                    // +0x18
    char m_pad_1c[8];
    efd::Point3 m_pos;              // +0x24
    char m_pad_30;
    bool m_bIgnore;                 // +0x31
    char m_pad_32[0x7a];
    float m_fViewDistance;          // +0xac
};
// C3: FUN_140552770 is std::vector<float>::operator[] const
class CGameOption;
class Unk_AeGameOption { public: class Unk_AeGraphicOption* GetGraphicOption(); };   // C3: unit-local view (def in applyeffect)
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
Unk_SkipCheck::Unk_SkipCheck() : m_nRow(0), m_nCaster(9), m_pos(efd::Point3::ZERO), m_n14(0), m_fViewDistance(-1.0f)
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
    if (((class CameraMgr*)(class Unk_SkipHost*)(reinterpret_cast<Unk_SkipHost*>(TSingleton<CameraMgr>::GetInstance())))->FUN_140a18070() == 0)
        return 0;
    Unk_SkipActor* pActor = ((class Unk_SkipActor*)((class CameraMgr*)(class Unk_SkipHost*)(reinterpret_cast<Unk_SkipHost*>(TSingleton<CameraMgr>::GetInstance())))->FUN_140a38d60());
    if (pActor == 0)
        return 0;
    Unk_SkipActorPos pos;
    pActor->GetPosition(&pos);
    Vector3 delta = (reinterpret_cast<const Vector3&>(pCheck->m_pos) - reinterpret_cast<const Vector3&>(pos));
    float fDist = delta.Unitize();
    float fView = pCheck->m_fViewDistance;
    if (IsNearlyEqual(fView, -1.0f))
        fView = static_cast<const std::vector<float>&>(m_rows[pCheck->m_nRow].m_dist)[pCheck->m_nCaster];
    bool bZero = IsNearlyEqual(fView, 0);
    bool bNear = fDist < fView;
    return !(bZero | bNear);
}

// @0x1411b8870
int EffectSkipMgr::ShouldSkipByView(CEffectDataPtr spData, int nCaster, Unk_SkipEffect* pEffect)
{
    Unk_SkipCheck check;
    check.m_nCaster = nCaster;
    check.m_pos = pEffect->m_pos;
    check.m_n14 = 0;
    for (POSITION pos = spData->GetParams().GetHeadPosition(); pos != 0; spData->GetParams().GetNext(pos))
    {
        Unk_SkipItem* pItem = reinterpret_cast<Unk_SkipItem*>(spData->GetParams().GetAt(pos).get());
        check.m_nRow = pItem->m_nKind;
        if (!pItem->m_bIgnore)
        {
            check.m_fViewDistance = -1.0f;
            if (pItem->m_nKind == 1)
                check.m_fViewDistance = pItem->m_fViewDistance;
            if (IsOutOfView(&check))
                return 1;
        }
    }
    return 0;
}

// @0x1411b89e0
bool EffectSkipMgr::LoadOption()
{
    int nOption = *(int*)((Unk_AeGameOption*)reinterpret_cast<void*>(TSingleton<CGameOption>::GetInstance()))->GetGraphicOption();
    TiXmlDocument doc;
    CString strPath = GetXmlPath("Table", "effectOption.xml");
    if (((class Unk_140166420*)GetFileSystem())->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return false;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    CString strOption("option");
    char szNum[8];
    strOption += _itoa(nOption + 1, szNum, 8);
    TiXmlElement* pOption = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild(strOption));
    if (pOption != 0)
    {
        LoadElements(((class TiXmlElement*)((class Unk_XmlNode*)(pOption))->FirstChild("nif")), 1);
        LoadElements(((class TiXmlElement*)((class Unk_XmlNode*)(pOption))->FirstChild("sound")), 2);
        LoadElements(((class TiXmlElement*)((class Unk_XmlNode*)(pOption))->FirstChild("swoosh")), 7);
        LoadElements(((class TiXmlElement*)((class Unk_XmlNode*)(pOption))->FirstChild("random")), 0xb);
        LoadElements(((class TiXmlElement*)((class Unk_XmlNode*)(pOption))->FirstChild("vibrate")), 0xc);
        LoadElements(((class TiXmlElement*)((class Unk_XmlNode*)(pOption))->FirstChild("chaoslight")), 0xe);
        LoadElements(((class TiXmlElement*)((class Unk_XmlNode*)(pOption))->FirstChild("lightning")), 0x10);
    }
    SetInit(true);
    return true;
}

// @0x1411b8d20
bool EffectSkipMgr::LoadLimitCount()
{
    TiXmlDocument doc;
    CString strPath = GetXmlPath("Table", "effectLimitCount.xml");
    if (((class Unk_140166420*)GetFileSystem())->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return false;
    m_cache.SetPath(strPath);
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    TiXmlElement* pDefault = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("default"));
    if (pDefault != 0)
        XmlGetAttr((class TiXmlElement*)(pDefault), "maxcount", reinterpret_cast<int&>(m_nMaxCount));
    TiXmlElement* pAdaptive = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("adaptive"));
    if (pAdaptive != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pAdaptive), "baseframe", reinterpret_cast<int&>(m_nBaseFrame));
        if (0 < m_nBaseFrame)
            LoadBenchmark();
    }
    TiXmlElement* pEffects = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("effects"));
    if (pEffects != 0)
    {
        CString strName;
        int nCount;
        for (TiXmlElement* pUnit = ((class TiXmlElement*)((class Unk_XmlNode*)(pEffects))->FirstChild("unit")); pUnit != 0; pUnit = ((class TiXmlElement*)((class Unk_XmlNode*)(pUnit))->NextSibling("effect")))
        {
            XmlGetAttr((class TiXmlElement*)(pUnit), "id", strName);
            XmlGetAttr((class TiXmlElement*)(pUnit), "count", reinterpret_cast<int&>(nCount));
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
    for (TiXmlElement* pElement = ((class TiXmlElement*)((class Unk_XmlNode*)(static_cast<TiXmlElement*>(pNode)))->FirstChild("element")); pElement != 0;
         pElement = ((class TiXmlElement*)(pElement))->NextSiblingElement())
    {
        CString strCaster = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pElement))->Attribute("caster"), 0);
        int nCaster;
        float fView = 0;
        XmlGetAttr((class TiXmlElement*)(pElement), "viewDistance", reinterpret_cast<float&>(fView));
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
    if (m_nBaseFrame <= 0)
        return;
    TiXmlDocument doc;
    CString strPath = GetXmlPath("Table", "effect_benchmark.xml");
    if (((class Unk_140166420*)GetFileSystem())->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
        return;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    CString strName;
    for (TiXmlElement* pE = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("e")); pE != 0; pE = ((class TiXmlElement*)((class Unk_XmlNode*)(pE))->NextSibling("e")))
    {
        int nTime;
        XmlGetAttr((class TiXmlElement*)(pE), "p", strName);
        XmlGetAttr((class TiXmlElement*)(pE), "t", reinterpret_cast<int&>(nTime));
        strName.MakeLower();
        int nCount = (int)ceil(50000.0f / (float)(nTime * m_nBaseFrame));
        CountMap::iterator it = m_mapLimit.find((const char*)strName);
        if (it == m_mapLimit.end())
            m_mapLimit.insert(CountMap::value_type((const char*)strName, nCount));
        else
            it->second = nCount;
    }
}

// @0x1411bb610
void EffectSkipMgr::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)ToCString(typeid(EffectSkipMgr).name(), 0));
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
