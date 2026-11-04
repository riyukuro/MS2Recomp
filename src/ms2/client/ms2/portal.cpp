// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPortal: the client-side object of one map portal.
// MS2-UNIT: unit_14169afb0
// MS2-RANGE: 0x1400fc110-0x1400fc2a0 .text$di
// MS2-RANGE: 0x14169afb0-0x14169d920 .text$mn
// MS2-FUNCTIONAL: b650 (utf8string / SmartPointer COMDAT pins), b890 and ba90 (MS2Ptr<UIDebugTooltip> / texture glue shape), bd40 (countdown formatting), c3b0 (switch layout), c5f0 (static-init order)
// MS2-RANGE: 0x142cb4480-0x142cb45d0 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\portal.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "portal.h"
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/portal_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uidebugtooltip.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/commonfiles/portaltable.h"
#include <efd/AssetID.h>
#include <efd/utf8string.h>
#include <NiNode.h>
#include <NiTexturingProperty.h>
#include <NiMesh.h>
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/nifeffectparam.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/commonfiles/os.h"
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxVec3.h>       // C3: NxVec3 locals (was Unk_CtbVec3)
#pragma pop_macro("max")
#pragma pop_macro("min")

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----

#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60

class EntityWorldManager   // C3: member view for the former free stand-ins
{
public:
    class egf::Entity* FUN_1411cf440(class egf::EntityID const&);
};
class NxBounds3   // C3: member view for the former free stand-ins
{
public:
    void set(float, float, float, float, float, float);
};
class NxMat33   // C3: member view for the former free stand-ins
{
public:
    void id();
    void rotZ(float);
};
void NxCreateBox(class NxBox&, class NxBounds3 const&, class NxMat34 const&);   // C3: was FUN_140adc690
bool NxBoxContainsPoint(class NxBox const&, class NxVec3 const&);   // C3: was FUN_140adc610

// The quest-npc table (singleton): lookups by portal.
class Unk_PortalQuestTable;
struct Unk_QmPortal;
class CQuestMaskTable
{
public:
    int HasPortalMask(Unk_QmPortal* pPortal);
    int CheckPortal(Unk_QmPortal* pPortal);
};
int FUN_140764310(const CString& strA, const CString& strB, QuestMask* pOut);
const char* Unk_AssetUrnText(const efd::AssetID* pAsset);         // the AssetID's URN text

// The content switch table.
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410

// The command string table (singleton).
CStringW GetStringCommonByKey(const CStringW& strKey);                     // string by key
CStringW GetStringCommon(int nId);                                    // string by id
float FUN_14028d280(unsigned uMilliseconds);                        // ms -> seconds

// The clock and tick count.
struct Unk_PortalClockOwner;
int FUN_141472bc0();   // C3: was FUN_141472bc0

// The field world and the portal table.
class Unk_PortalWorld { };
class Unk_PortalTableHolder { public:  };   // CPortalTable::GetName

// The scene: the node of the entity, a fade call and the texture loader.
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                    // scene root of an entity
NiAVObject* FUN_141b6ef70(egf::EntityID kId);                       // scene root by id
void FUN_140ae1e80(NiAVObject* pObject, float a, float b, float c, float d, egf::EntityID kId);
class Unk_ResourceMgr* FUN_140a0afd0();   // C3: was FUN_140a0afd0

// The map record behind a counted pointer (the portal's map image list).

// UIObject slot 8 (0x40) of the tooltip: show / hide.
class Unk_PortalTipSlots
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(int bShown);                               // MS2: slot 8
};

// @0x14169afb0
Unk_PortalBox::Unk_PortalBox()
    : m_pose(true), m_inverse(true)
{
}

// @0x14169b020
Unk_PortalBox::~Unk_PortalBox()
{
}

// @0x14169b080
int Unk_PortalBox::FUN_14169b080(egf::Entity* pEntity)
{
    Vector3 ptPos;
    Vector3 ptRot;
    Vector3 ptSize;
    Vector3 ptCenter;
    if (reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfb190620, (efd::Point3&)(ptSize)) != 0)
        return 0;
    if (reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0x1e1de032, (efd::Point3&)(ptCenter)) != 0)
        return 0;
    if (reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(ptPos)) != 0)
        return 0;
    if (reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0x68c7c29d, (efd::Point3&)(ptRot)) != 0)
        return 0;
    Vector3 ptHalf = ptSize.FUN_14097fc90(0.5f);
    ((class NxBounds3*)(struct Unk_CtbBounds3*)(&m_bounds))->set(-ptHalf.x, -ptHalf.y, -ptHalf.z, ptHalf.x, ptHalf.y, ptHalf.z);
    m_pose.m_pos.x = ptPos.x;
    m_pose.m_pos.y = ptPos.y;
    m_pose.m_pos.z = ptPos.z;
    ((class NxMat33*)(struct Unk_CtbMat33*)(&m_pose.m_rot))->id();
    ((class NxMat33*)(struct Unk_CtbMat33*)(&m_pose.m_rot))->rotZ((ptRot.z * 3.1415927f) / 180.0f);
    NxCreateBox(*(class NxBox*)(&m_obb), *(class NxBounds3 const*)(&m_bounds), *(class NxMat34 const*)(&m_pose));
    NxVec3 vCenter(ptCenter.x, ptCenter.y, ptCenter.z);
    reinterpret_cast<NxVec3&>(m_obb.m_center) += vCenter;   // move the box centre (0x140adbf00)
    return 1;
}

// @0x14169b2e0
int Unk_PortalBox::FUN_14169b2e0(const Vector3* pPoint)
{
    return NxBoxContainsPoint(*(class NxBox const*)(&m_obb), static_cast<const NxVec3&>(NxVec3(pPoint->x, pPoint->y, pPoint->z))) != 0;
}

// @0x14169b350
CPortal::CPortal()
    : m_idEntity(s_idPortalNone), m_questMask(), m_unk_148(0), m_unk_14c(0), m_unk_150(0), m_unk_154(0), m_unk_158(0),
      m_nType(0), m_nEndTime(0), m_nEventTime(0), m_unk_188(0), m_b18c(false), m_tooltip(0), m_bFlash(0)
{
}

// @0x14169b520
CPortal::~CPortal()
{
    if (m_tooltip.get() != 0)
        m_tooltip->FUN_14191aa70();
    m_tooltip = 0;
}

// @0x14169b650
int CPortal::FUN_14169b650(efd::SmartPointer<egf::Entity> spEntity)
{
    efd::utf8string strModel;
    if (spEntity->GetPropertyValue(0x7d465aa2, strModel) != egf::PropertyResult_OK)
        return 0;
    efd::utf8string strTheme;
    if (spEntity->GetPropertyValue(0x985b4e4f, strTheme) != egf::PropertyResult_OK)
        return 0;
    // no default: a missing position keeps the previous m_pos44
    spEntity->GetPropertyValue(0xfb190620, reinterpret_cast<efd::Point3&>(m_pos44));
    CString strA(strModel.c_str());
    CString strB(strTheme.c_str());
    FUN_140764310(strA, strB, &m_questMask);
    efd::AssetID idImage;
    spEntity->GetPropertyValue(0x770e5fc6, idImage);
    m_strImage = Unk_AssetUrnText(&idImage);
    return 1;
}

// @0x14169b890
int CPortal::FUN_14169b890()
{
    if (m_nEndTime > 0)
    {
        egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
        if (pEntity == 0)
            return 0;
        Vector3 ptPos = DAT_143b01a60;
        reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(ptPos));
        m_tooltip.AssignRaw(new UIDebugTooltip(CString("")));
        m_tooltip->m_68 = 0;
        Vector3 ptCopy = ptPos;
        m_tooltip->FUN_14191aae0(ptCopy);
        m_tooltip->FUN_14191ab10(CStringW(L""));
        m_tooltip->FUN_14191aa10();
    }
    return 1;
}

// @0x14169ba90
int CPortal::FUN_14169ba90()
{
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (pEntity == 0)
        return 0;
    int nMapId = 0;
    pEntity->GetPropertyValue(0xa162d321, nMapId);
    NiAVObject* pRoot = FUN_141b6efc0(pEntity);
    if (pRoot != 0)
    {
        NiAVObject* pPlane;
        {
            NiFixedString kName("Theme_Image_Plane");
            NiAVObject* pFound = pPlane = pRoot->GetObjectByName(kName);
        }
        if (pPlane != 0 && NiObject::IsExactKindOf(&NiMesh::ms_RTTI, (class NiObject const*)(pPlane)))
        {
            NiTexturingProperty* pTexProp = (NiTexturingProperty*)NiObject::DynamicCast(&NiTexturingProperty::ms_RTTI, (class NiObject const*)(pPlane->GetProperty(NiProperty::TEXTURING)));
            if (pTexProp != 0)
            {
                NiTexturingProperty::Map* pMap = ((class NiTexturingProperty*)(class NiTexturingProperty*)(pTexProp))->GetBaseMap();
                if (pMap != 0)
                {
                    MS2Ptr<CFieldDataCli> spMap = CFieldDataCli::Find(nMapId);
                    if (spMap ? true : false)
                    {
                        if (spMap->m_spMinimap ? true : false)
                        {
                            CString strPath(*(CString*)((char*)spMap->m_spMinimap.operator->() + 0x18));
                            if (!strPath.IsEmpty())
                            {
                                NiTexturePtr spTex = ((class CNifLoadingService*)FUN_140a0afd0())->GetTexture(strPath, 5);
                                if ((NiTexture*)spTex != 0)
                                    ((NiTexturingProperty::Map*)(class NiTexturingProperty::Map*)(pMap))->SetTexture((NiTexture*)spTex);
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

// @0x14169bd40
void CPortal::FUN_14169bd40()
{
    if ((m_nType == 6 || m_nType == 3 || m_nType == 10 || m_nType == 0x10) && m_nEndTime > 0 && m_tooltip.get() != 0)
    {
        CStringW strText;
        unsigned nNow = ((class CMainSystem*)(struct Unk_PortalClockOwner*)(reinterpret_cast<Unk_PortalClockOwner*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473390();
        if (nNow >= m_nEndTime)
        {
            strText = L"00:00";
            m_nEndTime = 0;
        }
        else
        {
            unsigned nRemain = m_nEndTime - nNow;
            int nSeconds = (int)FUN_14028d280(nRemain);
            if (m_bFlash == 0 && nRemain < 500)
            {
                m_bFlash = 1;
                NiAVObject* pNode = FUN_141b6ef70(m_idEntity);
                if (pNode != 0)
                    FUN_140ae1e80(pNode, 1.0f, 0.0f, 0.0f, FUN_14028d280(500), m_idEntity);
            }
            CStringW strTime;
            strTime.Format(L"%02d:%02d", nSeconds / 60, nSeconds % 60);
            if (m_strTime != strTime)
            {
                strText = strTime;
                m_strTime = strTime;
            }
        }
        if (strText.GetLength() > 0)
        {
            if (m_strTip.GetLength() > 0)
                strText += FUN_14028dfa0<CStringW, CStringW>(CStringW(L"s_msg_item_open_massive_portal_tooltip"), m_strTip,
                                         TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, m_unk_148));
            m_tooltip->FUN_14191ab10(strText);
        }
    }
    if (m_nEventTime != 0)
    {
        unsigned nTick = FUN_141472bc0();
        if (nTick > m_nEventTime)
        {
            m_nEventTime = 0;
            FUN_14169cd50(1, 1);
            if (m_tooltip.get() != 0)
                reinterpret_cast<Unk_PortalTipSlots*>(m_tooltip.operator->())->vfunc_8(1);
        }
        else
        {
            FUN_14169cd50(0, 0);
            if (m_tooltip.get() != 0)
                reinterpret_cast<Unk_PortalTipSlots*>(m_tooltip.operator->())->vfunc_8(0);
        }
    }
}

// @0x14169c280
void CPortal::FUN_14169c280()
{
    if (m_nType == 6)
    {
        FUN_14169ba90();
        FUN_14169b890();
    }
    else if (m_nType == 3 || m_nType == 0x10)
    {
        if (m_strTip.GetLength() > 0)
            FUN_14169ba90();
        FUN_14169b890();
    }
    else if (m_nType == 10)
    {
        FUN_14169b890();
    }
    FUN_14169d3a0();
}

// @0x14169c330
int CPortal::FUN_14169c330()
{
    if (!((class CFeatureManager*)FUN_140166410())->IsFeatureEnabledByName(m_strFeature))
        return false;
    if (!((class CFeatureManager*)FUN_140166410())->IsLocaleInList(m_strLocale))
        return false;
    return true;
}

// @0x14169c3b0
CStringW CPortal::FUN_14169c3b0()
{
    switch (m_nType)
    {
    case 8:
        return GetStringCommonByKey(L"s_action_portal_DungeonLobby");
    case 9:
        return GetStringCommonByKey(L"s_action_portal_DungeonRoomIn");
    case 0xc:
        return GetStringCommonByKey(L"s_action_portal_ChaosDungeon");
    case 0xd:
        return GetStringCommonByKey(L"s_action_portal_MoveBackupField");
    case 0xe:
        return GetStringCommonByKey(L"s_action_portal_ReverseRaid");
    case 0x12:
        return GetStringCommonByKey(L"s_action_portal_RandomTarget");
    default:
        return GetStringCommon(0x632);
    }
}

// @0x14169c5f0
CString CPortal::FUN_14169c5f0()
{
    static CString s_strPortal("portal");
    static CString s_strEventPortal("event_portal");
    static CString s_strBossPortalSpecial("boss_portal_special");
    static CString s_strBossPortal("boss_portal");
    static CString s_strDungeonSpecial("dungeon_special");
    static CString s_strDungeon("dungeon");
    switch (m_nType)
    {
    case 4:
        return s_strEventPortal;
    case 8:
    {
        const unsigned nFieldLimit = 100000;
        DungeonRoomPtr spRoom;
        if (m_nId < nFieldLimit)
            spRoom = TSingleton<DungeonRoomTable>::GetInstance()->GetLastRoom(m_nId);
        else
            spRoom = TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(m_nId);
        if (spRoom.get() != 0)
        {
            if (spRoom->m_isUseBossIcon != 0)
                return spRoom->m_isTimeUp != 0 ? s_strBossPortalSpecial : s_strBossPortal;
            else
                return spRoom->m_isTimeUp != 0 ? s_strDungeonSpecial : s_strDungeon;
        }
        break;
    }
    }
    return s_strPortal;
}

// @0x14169cae0
CStringW CPortal::FUN_14169cae0()
{
    if (m_nType == 0x11)
        return TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x14, m_nId);
    unsigned nName = FUN_14169d280();
    if (nName > 0)
        return TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, nName);
    unsigned nMapId = ((class WorldService*)(class Unk_PortalWorld*)(reinterpret_cast<Unk_PortalWorld*>(WorldService::GetInstance())))->FUN_141bd3060();
    CStringW strName = ((CPortalTable*)(Unk_PortalTableHolder*)(reinterpret_cast<Unk_PortalTableHolder*>(TSingleton<CPortalTable>::GetInstance())))->GetName(nMapId, m_nId);
    if (!strName.IsEmpty())
        return strName;
    return CStringW(L"");
}

// @0x14169cc40
int CPortal::FUN_14169cc40()
{
    return TSingleton<CQuestMaskTable>::GetInstance()->CheckPortal(reinterpret_cast<Unk_QmPortal*>(this));
}

// @0x14169cc70
void CPortal::FUN_14169cc70(const Vector3& pos, const Vector3& rot)
{
    efd::SmartPointer<egf::Entity> spEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (spEntity == 0)
        return;
    ((egf::Entity*)spEntity)->SetPropertyValue(0xfd95ca52, reinterpret_cast<const efd::Point3&>(pos));
    ((egf::Entity*)spEntity)->SetPropertyValue(0x68c7c29d, reinterpret_cast<const efd::Point3&>(rot));
    m_box.FUN_14169b080(spEntity.operator->());
}

// @0x14169cd50
void CPortal::FUN_14169cd50(int bShown, int bGlow)
{
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (pEntity == 0)
        return;
    if (!FUN_14169c330())
    {
        bShown = 0;
        bGlow = 0;
    }
    pEntity->SetPropertyValue(0xa0b6b179, bShown != 0);
    pEntity->SetPropertyValue(0x2a7fd9f4, bShown == 0);
    pEntity->SetPropertyValue(0x14969c28, bGlow != 0);
}

// @0x14169ce50
void CPortal::FUN_14169ce50(int bShown, int bGlow, int bExtra)
{
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (pEntity == 0)
        return;
    if (!FUN_14169c330())
    {
        bShown = 0;
        bGlow = 0;
        bExtra = 0;
    }
    pEntity->SetPropertyValue(0xa0b6b179, bShown != 0);
    pEntity->SetPropertyValue(0x2a7fd9f4, bShown == 0);
    pEntity->SetPropertyValue(0x14969c28, bGlow != 0);
    pEntity->SetPropertyValue(0xe084c8de, bExtra != 0);
}

// @0x14169cf90
void CPortal::FUN_14169cf90(int bShown)
{
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (pEntity == 0)
        return;
    if (!FUN_14169c330())
        bShown = 0;
    pEntity->SetPropertyValue(0xa0b6b179, bShown != 0);
    pEntity->SetPropertyValue(0x2a7fd9f4, bShown == 0);
}

// @0x14169d050
void CPortal::FUN_14169d050(int bGlow)
{
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (pEntity == 0)
        return;
    if (!FUN_14169c330())
        bGlow = 0;
    pEntity->SetPropertyValue(0x14969c28, bGlow != 0);
}

// @0x14169d0e0
void CPortal::FUN_14169d0e0()
{
    if (TSingleton<CQuestMaskTable>::GetInstance()->HasPortalMask(reinterpret_cast<Unk_QmPortal*>(this)) != 0)
    {
        int nState = FUN_14169cc40();
        FUN_14169cd50(nState, nState);
    }
    if (((class WorldService*)(class Unk_PortalWorld*)(reinterpret_cast<Unk_PortalWorld*>(WorldService::GetInstance())))->FUN_141bd3060() == 0x1e8673 && m_nId == 2)
        FUN_14169cd50(1, 1);
}

// @0x14169d160
bool CPortal::FUN_14169d160()
{
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (pEntity == 0)
        return false;
    bool bShown = false;
    pEntity->GetPropertyValue(0xa0b6b179, bShown);
    return bShown;
}

// @0x14169d1d0
bool CPortal::FUN_14169d1d0()
{
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (pEntity == 0)
        return false;
    bool bExtra = true;
    bool bOverridden = pEntity->IsPropertyOverridden(0xe084c8de);
    if (bOverridden)
        pEntity->GetPropertyValue(0xe084c8de, bExtra);
    return (bExtra && FUN_14169d160()) ? 1 : 0;
}

// @0x14169d280
int CPortal::FUN_14169d280()
{
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (pEntity == 0)
        return 0;
    int nValue = 0;
    pEntity->GetPropertyValue(0xa162d321, nValue);
    return nValue;
}

// @0x14169d2f0
Vector3 CPortal::FUN_14169d2f0()
{
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (pEntity == 0)
        return DAT_143b01a60;
    Vector3 ptPos = DAT_143b01a60;
    reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(ptPos));
    return ptPos;
}

// @0x14169d3a0
void CPortal::FUN_14169d3a0()
{
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_idEntity);
    if (pEntity == 0)
        return;
    if (m_nType == 0x10)
    {
        float fScale = 1.5f;
        pEntity->SetPropertyValue(0x2d7cad2d, fScale);
    }
}
