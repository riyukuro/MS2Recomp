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
#include <efd/AssetID.h>
#include <efd/utf8string.h>
#include <NiNode.h>
#include <NiTexturingProperty.h>

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----

extern Unk_StreamPoint DAT_143b01a60;                               // the zero point

egf::EntityManager* FUN_1409670f0();
egf::Entity* FUN_1411cf440(egf::EntityManager* pMgr, const egf::EntityID& id);
int FUN_1409618c0(egf::Entity* pEntity, unsigned uPropId, Unk_StreamPoint* pOut);   // read a Point3 property (0 = ok)
void FUN_140a38a50(egf::Entity* pEntity, unsigned uPropId, const Unk_StreamPoint& pt);   // write a Point3 property
void FUN_140add1a0(Unk_CtbBounds3* pSelf, float x0, float y0, float z0, float x1, float y1, float z1);   // set
void FUN_140adca00(Unk_CtbMat33* pSelf);                            // identity
void FUN_140add040(Unk_CtbMat33* pSelf, float fAngle);              // rotation about z
void FUN_140adc690(Unk_CtbObb* pOut, const Unk_CtbBounds3* pBounds, const Unk_CtbMat34* pPose);   // box from bounds + pose
bool FUN_140adc610(const Unk_CtbObb* pObb, const Unk_CtbVec3& pt);  // point inside the box
void FUN_140adbf00(Unk_CtbObb* pObb, const Unk_CtbVec3& pt);        // set the box centre

// The quest-npc table (singleton): lookups by portal.
class Unk_PortalQuestTable
{
public:
    int FUN_140764d50(CPortal* pPortal);
    int FUN_140764f30(CPortal* pPortal);
    void FUN_140764310(const CString& strA, const CString& strB, QuestMask* pOut);
};
Unk_PortalQuestTable* FUN_14109a710();
void FUN_140764310(const CString& strA, const CString& strB, QuestMask* pOut);

// The content switch table.
class Unk_PortalSwitches
{
public:
    bool FUN_14036d4b0(const CStringW& strFeature);
    bool FUN_14036d750(const CStringW& strLocale);
};
Unk_PortalSwitches* FUN_140166410();

// The command string table (singleton).
class Unk_PortalStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_PortalStrings* FUN_1401a9d70();
CStringW GetStringCommonByKey(const CStringW& strKey);                     // string by key
CStringW GetStringCommon(int nId);                                    // string by id
CStringW FUN_1408f71a0(CStringW strFormat, const CStringW& strArg1, const CStringW& strArg2);   // format with two arguments
bool FUN_140164830(const CStringW& a, const CStringW& b);           // a != b
float FUN_14028d280(unsigned uMilliseconds);                        // ms -> seconds

// The clock and tick count.
struct Unk_PortalClockOwner;
Unk_PortalClockOwner* FUN_14086d260();
unsigned FUN_141473390(Unk_PortalClockOwner* pOwner);               // the server time in seconds
unsigned FUN_141472bc0();                                           // tick count

// The field world and the portal table.
class Unk_PortalWorld { };
Unk_PortalWorld* FUN_1403ed2d0();
unsigned FUN_141bd3060(Unk_PortalWorld* pWorld);                    // the current map id
class Unk_PortalTableHolder { public: CStringW FUN_140730b80(unsigned nMapId, int nPortalId); };   // CPortalTable::GetName
Unk_PortalTableHolder* FUN_1414a5760();

// The dungeon room table and a room row.
class Unk_PortalRoom : public CPtred
{
public:
    int FUN_14031ddd0();
    unsigned char m_pad_18[0x140];
    int m_nBoss;                                                    // +0x158
    unsigned char m_bSpecial;                                       // +0x15c
};
MS2_CHECK_OFFSET(Unk_PortalRoom, m_nBoss, 0x158);
MS2_CHECK_OFFSET(Unk_PortalRoom, m_bSpecial, 0x15c);
class Unk_PortalRoomTable
{
public:
    MS2Ptr<Unk_PortalRoom> FUN_140320950(int nRoomId);
    MS2Ptr<Unk_PortalRoom> FUN_1403206b0(int nRoomId);
};
Unk_PortalRoomTable* FUN_14031c2a0();

// The scene: the node of the entity, a fade call and the texture loader.
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                    // scene root of an entity
NiAVObject* FUN_141b6ef70(egf::EntityID kId);                       // scene root by id
void FUN_140ae1e80(NiAVObject* pObject, float a, float b, float c, float d, egf::EntityID kId);
bool FUN_14109a9a0(const NiRTTI* pRTTI, NiAVObject* pObject);       // IsKindOf
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);    // dynamic cast through an NiRTTI
extern char DAT_143afbbb0;                                          // NiMesh::ms_RTTI
extern char DAT_143afa4f0;                                          // NiTexturingProperty::ms_RTTI
NiTexturingProperty::Map* FUN_14109a6b0(NiTexturingProperty* pProp);   // GetBaseMap
void FUN_140981040(NiTexturingProperty::Map* pMap, void* pTexture);    // SetTexture
void* FUN_140a0afd0();                                              // texture manager
void FUN_141552f90(void* pMgr, void* pOutTexture, CString* pPath, char bFlag);   // load a texture
void* FUN_14097fbf0(void* pTexture);                                // texture pointer
void FUN_14097f4a0(void* pTexture);                                 // release

// The map record behind a counted pointer (the portal's map image list).
struct Unk_PortalMapRef
{
    void* m_unk_00;
    void* m_p;
};
Unk_PortalMapRef* FUN_140a55460(Unk_PortalMapRef* pOut, int nMapId);
void* FUN_1409657a0(Unk_PortalMapRef* pRef);                        // operator T*
void* FUN_140885340(Unk_PortalMapRef* pRef);                        // operator->
void FUN_1408850f0(Unk_PortalMapRef* pRef);                         // release
void* FUN_140a56f90(void* pList);                                   // first element, or null
void* FUN_140a56fa0(void* pList);                                   // first element

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
    Unk_StreamPoint ptPos;
    Unk_StreamPoint ptRot;
    Unk_StreamPoint ptSize;
    Unk_StreamPoint ptCenter;
    if (FUN_1409618c0(pEntity, 0xfb190620, &ptSize) != 0)
        return 0;
    if (FUN_1409618c0(pEntity, 0x1e1de032, &ptCenter) != 0)
        return 0;
    if (FUN_1409618c0(pEntity, 0xfd95ca52, &ptPos) != 0)
        return 0;
    if (FUN_1409618c0(pEntity, 0x68c7c29d, &ptRot) != 0)
        return 0;
    Unk_StreamPoint ptHalf = ptSize.FUN_14097fc90(0.5f);
    FUN_140add1a0(&m_bounds, -ptHalf.x, -ptHalf.y, -ptHalf.z, ptHalf.x, ptHalf.y, ptHalf.z);
    m_pose.m_pos.x = ptPos.x;
    m_pose.m_pos.y = ptPos.y;
    m_pose.m_pos.z = ptPos.z;
    FUN_140adca00(&m_pose.m_rot);
    FUN_140add040(&m_pose.m_rot, (ptRot.z * 3.1415927f) / 180.0f);
    FUN_140adc690(&m_obb, &m_bounds, &m_pose);
    Unk_CtbVec3 vCenter(ptCenter.x, ptCenter.y, ptCenter.z);
    FUN_140adbf00(&m_obb, vCenter);
    return 1;
}

// @0x14169b2e0
int Unk_PortalBox::FUN_14169b2e0(const Unk_StreamPoint* pPoint)
{
    return FUN_140adc610(&m_obb, Unk_CtbVec3(pPoint->x, pPoint->y, pPoint->z)) != 0;
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
bool CPortal::FUN_14169b650(efd::SmartPointer<egf::Entity> spEntity)
{
    efd::utf8string strModel;
    if (((egf::Entity*)spEntity)->GetPropertyValue(0x7d465aa2, strModel) != egf::PropertyResult_OK)
        return false;
    efd::utf8string strTheme;
    if (((egf::Entity*)spEntity)->GetPropertyValue(0x985b4e4f, strTheme) != egf::PropertyResult_OK)
        return false;
    NiPoint3 ptSize = reinterpret_cast<const NiPoint3&>(DAT_143b01a60);
    ((egf::Entity*)spEntity)->GetPropertyValue(0xfb190620, static_cast<efd::Point3&>(ptSize));
    m_pos44 = reinterpret_cast<const Unk_StreamPoint&>(ptSize);
    CString strA(strModel.c_str());
    CString strB(strTheme.c_str());
    FUN_140764310(strA, strB, &m_questMask);
    efd::AssetID idImage;
    ((egf::Entity*)spEntity)->GetPropertyValue(0x770e5fc6, idImage);
    m_strImage = idImage.GetURN().c_str();
    return true;
}

// @0x14169b890
bool CPortal::FUN_14169b890()
{
    if (m_nEndTime != 0)
    {
        egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
        if (pEntity == 0)
            return false;
        Unk_StreamPoint ptPos = DAT_143b01a60;
        FUN_1409618c0(pEntity, 0xfd95ca52, &ptPos);
        m_tooltip = new UIDebugTooltip(CString(""));
        m_tooltip->SetFollowsAnchor(0);
        Unk_StreamPoint ptCopy = ptPos;
        m_tooltip->FUN_14191aae0(ptCopy);
        m_tooltip->FUN_14191ab10(CStringW(L""));
        m_tooltip->FUN_14191aa10();
    }
    return true;
}

// @0x14169ba90
bool CPortal::FUN_14169ba90()
{
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
    if (pEntity == 0)
        return false;
    int nMapId = 0;
    pEntity->GetPropertyValue(0xa162d321, nMapId);
    NiAVObject* pRoot = FUN_141b6efc0(pEntity);
    if (pRoot != 0)
    {
        NiAVObject* pPlane = pRoot->GetObjectByName(NiFixedString("Theme_Image_Plane"));
        if (pPlane != 0 && FUN_14109a9a0((const NiRTTI*)&DAT_143afbbb0, pPlane))
        {
            NiProperty* pProp = pPlane->GetProperty(NiProperty::TEXTURING);
            NiTexturingProperty* pTexProp = (NiTexturingProperty*)FUN_14098d8d0((const NiRTTI*)&DAT_143afa4f0, pProp);
            NiTexturingProperty::Map* pMap = 0;
            if (pTexProp != 0 && (pMap = FUN_14109a6b0(pTexProp)) != 0)
            {
                Unk_PortalMapRef spMap;
                FUN_140a55460(&spMap, nMapId);
                if (FUN_1409657a0(&spMap) != 0)
                {
                    void* pList = (char*)FUN_140885340(&spMap) + 0x160;
                    if (FUN_140a56f90(pList) != 0)
                    {
                        CString strPath(*(CString*)((char*)FUN_140a56fa0(pList) + 0x18));
                        if (!strPath.IsEmpty())
                        {
                            CString strLoad(strPath);
                            void* spTex[2];
                            FUN_141552f90(FUN_140a0afd0(), spTex, &strLoad, 5);
                            if (FUN_14097fbf0(spTex) != 0)
                                FUN_140981040(pMap, FUN_14097fbf0(spTex));
                            FUN_14097f4a0(spTex);
                        }
                    }
                }
                FUN_1408850f0(&spMap);
            }
        }
    }
    return true;
}

// @0x14169bd40
void CPortal::FUN_14169bd40()
{
    if ((m_nType == 6 || m_nType == 3 || m_nType == 10 || m_nType == 0x10) && m_nEndTime != 0 && m_tooltip.get() != 0)
    {
        CStringW strText;
        unsigned nNow = FUN_141473390(FUN_14086d260());
        if (nNow < m_nEndTime)
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
            unsigned nSecond = nSeconds % 60;
            strTime.Format(L"%02d:%02d", nSeconds / 60, nSecond);
            if (FUN_140164830(m_strTime, strTime))
            {
                strText = strTime;
                m_strTime = strTime;
            }
        }
        else
        {
            strText = L"00:00";
            m_nEndTime = 0;
        }
        if (strText.GetLength() > 0)
        {
            if (m_strTip.GetLength() > 0)
                strText += FUN_1408f71a0(CStringW(L"s_msg_item_open_massive_portal_tooltip"), m_strTip,
                                         FUN_1401a9d70()->FUN_141811980(3, m_unk_148));
            m_tooltip->FUN_14191ab10(strText);
        }
    }
    if (m_nEventTime != 0)
    {
        unsigned nTick = FUN_141472bc0();
        if (m_nEventTime < nTick)
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
    if (!FUN_140166410()->FUN_14036d4b0(m_strFeature))
        return false;
    if (!FUN_140166410()->FUN_14036d750(m_strLocale))
        return false;
    return true;
}

// @0x14169c3b0
CStringW CPortal::FUN_14169c3b0()
{
    switch (m_nType)
    {
    case 8:
        return GetStringCommonByKey(CStringW(L"s_action_portal_DungeonLobby"));
    case 9:
        return GetStringCommonByKey(CStringW(L"s_action_portal_DungeonRoomIn"));
    default:
        return GetStringCommon(0x632);
    case 0xc:
        return GetStringCommonByKey(CStringW(L"s_action_portal_ChaosDungeon"));
    case 0xd:
        return GetStringCommonByKey(CStringW(L"s_action_portal_MoveBackupField"));
    case 0xe:
        return GetStringCommonByKey(CStringW(L"s_action_portal_ReverseRaid"));
    case 0x12:
        return GetStringCommonByKey(CStringW(L"s_action_portal_RandomTarget"));
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
        MS2Ptr<Unk_PortalRoom> spRoom;
        if (m_nId < nFieldLimit)
            spRoom = FUN_14031c2a0()->FUN_140320950(m_nId);
        else
            spRoom = FUN_14031c2a0()->FUN_1403206b0(m_nId);
        if (spRoom.get() != 0)
        {
            if (spRoom->m_bSpecial != 0)
                return spRoom->m_nBoss != 0 ? s_strBossPortalSpecial : s_strBossPortal;
            else
                return spRoom->m_nBoss != 0 ? s_strDungeonSpecial : s_strDungeon;
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
        return FUN_1401a9d70()->FUN_141811980(0x14, m_nId);
    unsigned nName = FUN_14169d280();
    if (nName > 0)
        return FUN_1401a9d70()->FUN_141811980(3, nName);
    unsigned nMapId = FUN_141bd3060(FUN_1403ed2d0());
    CStringW strName = FUN_1414a5760()->FUN_140730b80(nMapId, m_nId);
    if (!strName.IsEmpty())
        return strName;
    return CStringW(L"");
}

// @0x14169cc40
int CPortal::FUN_14169cc40()
{
    return FUN_14109a710()->FUN_140764f30(this);
}

// @0x14169cc70
void CPortal::FUN_14169cc70(const Unk_StreamPoint& pos, const Unk_StreamPoint& rot)
{
    efd::SmartPointer<egf::Entity> spEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
    if (spEntity == 0)
        return;
    FUN_140a38a50((egf::Entity*)spEntity, 0xfd95ca52, pos);
    FUN_140a38a50((egf::Entity*)spEntity, 0x68c7c29d, rot);
    m_box.FUN_14169b080(spEntity.operator->());
}

// @0x14169cd50
void CPortal::FUN_14169cd50(int bShown, int bGlow)
{
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
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
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
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
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
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
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
    if (pEntity == 0)
        return;
    if (!FUN_14169c330())
        bGlow = 0;
    pEntity->SetPropertyValue(0x14969c28, bGlow != 0);
}

// @0x14169d0e0
void CPortal::FUN_14169d0e0()
{
    if (FUN_14109a710()->FUN_140764d50(this) != 0)
    {
        int nState = FUN_14169cc40();
        FUN_14169cd50(nState, nState);
    }
    if (FUN_141bd3060(FUN_1403ed2d0()) == 0x1e8673 && m_nId == 2)
        FUN_14169cd50(1, 1);
}

// @0x14169d160
bool CPortal::FUN_14169d160()
{
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
    if (pEntity == 0)
        return false;
    bool bShown = false;
    pEntity->GetPropertyValue(0xa0b6b179, bShown);
    return bShown;
}

// @0x14169d1d0
bool CPortal::FUN_14169d1d0()
{
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
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
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
    if (pEntity == 0)
        return 0;
    int nValue = 0;
    pEntity->GetPropertyValue(0xa162d321, nValue);
    return nValue;
}

// @0x14169d2f0
Unk_StreamPoint CPortal::FUN_14169d2f0()
{
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
    if (pEntity == 0)
        return DAT_143b01a60;
    Unk_StreamPoint ptPos = DAT_143b01a60;
    FUN_1409618c0(pEntity, 0xfd95ca52, &ptPos);
    return ptPos;
}

// @0x14169d3a0
void CPortal::FUN_14169d3a0()
{
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_idEntity);
    if (pEntity == 0)
        return;
    if (m_nType == 0x10)
    {
        float fScale = 1.5f;
        pEntity->SetPropertyValue(0x2d7cad2d, fScale);
    }
}
