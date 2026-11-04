// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGuildFlagTooltip: see uiguildflagtooltip.h.
// MS2-UNIT: ?\uiguildflagtooltip.cpp
// MS2-RANGE: 0x1412c3e60-0x1412c4cd0 .text$mn
// MS2-PIN: ??1UIGuildFlagTooltip@@UEAA@XZ 0x1412c4b30
// MS2-PIN: ??_GUIGuildFlagTooltip@@UEAAPEAXI@Z 0x1412c4b60
//
// File name assumed (the class name; the exe has no assert path for it).
#define NOMINMAX                        // NxPhysics (interactobject.h)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiguildflagtooltip.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiguildflagtooltip.h"

#include "ms2/client/ms2/interactobject.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/camera.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class CGuildManager;

// The score table of the guild ranking seasons: the entry of a trophy count has a value at +0x18.
struct Unk_FtSeasonEntry { char m_pad_00[0x18]; int m_nValue; };
class Unk_FtSeasonTable;
class Unk_RankTable* FUN_140dc19b0();   // C3: was FUN_140dc19b0
class CRankingArenaDataTable   // C3: member view for the former free stand-ins
{
public:
    class RankingArenaData* GetGradeOfRating(int);
};

class Unk_FtUIScale;
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: was FUN_14025e7a0
class GFxManager   // C3: member view for the former free stand-ins
{
public:
    float FUN_1422afec0(int);
};
MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);   // new ASGameEntity(v, n)

void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);  // Value = string
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int nValue);          // Value = Int

// AS invokers on the tooltip's movie (this unit's private instances of the AScript::Invoke templates).
class Unk_FtEntity : public ASGameEntity
{
public:
    Scaleform::GFx::Value FUN_1412c4930(const char* szMethod, CStringW a1, int a2, int a3);
    Scaleform::GFx::Value FUN_1412c4a20(const char* szMethod, CStringW a1, int a2, int a3, int a4);
};

// @0x1412c3e60
UIGuildFlagTooltip::UIGuildFlagTooltip()
{
    m_58 = 0;
    m_70 = 0;
    m_2c = 9;
}

// @0x1412c3ee0
CString UIGuildFlagTooltip::GetTypeName()
{
    return "GuildFlagTooltip";
}
MS2_REPLACE_METHOD(0x1412C3EE0, UIGuildFlagTooltip, GetTypeName, 61, 0x9FD37AF0);

// @0x1412c3f30
void UIGuildFlagTooltip::vfunc_3()
{
    m_70 = 0;
    m_78 = "";
    FUN_1422dc080();
}

// @0x1412c3f70
void UIGuildFlagTooltip::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_70 == 0)
        return;
    if (FUN_1412c46d0() == 0)
        vfunc_3();
}

// @0x1412c3fc0
int UIGuildFlagTooltip::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnEndHide", szMethod) == 0) {
        m_70 = 0;
        m_78 = "";
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1412C3FC0, UIGuildFlagTooltip, vfunc_28, 129, 0x5F648DED);

// @0x1412c4050
void UIGuildFlagTooltip::FUN_1412c4050(const CString& strName)
{
    if (m_70 == 1)
        return;
    m_78 = strName;
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
    {
        CInteractObject* pObject = WorldService::GetInstance()->FindProp(m_78).get();
        if (pObject == 0)
            return;
        CInteractDisplayImage* pImage = dynamic_cast<CInteractDisplayImage*>(pObject);
        if (pImage == 0)
            return;
        CStringW strCaption = pImage->GetDisplayName();
        int nTrophy = pImage->GetDisplayScore();
        int nRank = pImage->FUN_1414021c0();
        int nImageType = 0;
        if (pImage->GetRow())
            nImageType = pImage->GetRow()->m_displayUrl.m_nType;
        if (strCaption.GetLength() > 0)
        {
            m_70 = 1;
            pEntity->vfunc_3(1);
            if (nImageType == 3)
            {
                int nScore = reinterpret_cast<CGuildInfo*>((char*)reinterpret_cast<void*>(TSingleton<CGuildManager>::GetInstance()) + 8)->FUN_1404d3180()->FUN_1404c6110(nTrophy);
                static_cast<Unk_FtEntity*>(pEntity.operator->())->FUN_1412c4a20("showPvp", CStringW(strCaption), nTrophy, nRank, nScore);
            }
            else if (nImageType == 4)
            {
                static_cast<Unk_FtEntity*>(pEntity.operator->())->FUN_1412c4930("showBuilder", CStringW(strCaption), nTrophy, nRank);
            }
            else if (nImageType == 5)
            {
                Unk_FtSeasonEntry* pEntry = ((struct Unk_FtSeasonEntry*)((class CRankingArenaDataTable*)(class Unk_FtSeasonTable*)(((class Unk_FtSeasonTable*)FUN_140dc19b0())))->GetGradeOfRating(nTrophy));
                static_cast<Unk_FtEntity*>(pEntity.operator->())->FUN_1412c4a20("showPvp", CStringW(strCaption), nTrophy, nRank, pEntry->m_nValue);
            }
            else
            {
                static_cast<Unk_FtEntity*>(pEntity.operator->())->FUN_1412c4930("show", CStringW(strCaption), nTrophy, nRank);
            }
            FUN_1412c46d0();
        }
    }
}

// @0x1412c45a0
void UIGuildFlagTooltip::FUN_1412c45a0()
{
    if (m_70 == 0)
        return;
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
        m_30->Invoke("hideTooltip");
}

// @0x1412c4660
void UIGuildFlagTooltip::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

// @0x1412c46d0
bool UIGuildFlagTooltip::FUN_1412c46d0()
{
    if (m_78.GetLength() < 1)
        return false;
    CInteractObject* pObject = WorldService::GetInstance()->FindProp(m_78).get();
    if (pObject == 0)
        return false;
    CInteractDisplayImage* pImage = dynamic_cast<CInteractDisplayImage*>(pObject);
    if (pImage == 0)
        return false;
    Vector3 kWorld = pObject->GetPos();
    kWorld.z += 150.0f;
    Vector3 kScreen;
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140af0700(reinterpret_cast<const efd::Point3&>(kWorld), reinterpret_cast<NiPoint3&>(kScreen)))
    {
        MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pEntity.get())
        {
            reinterpret_cast<efd::Point3&>(kScreen) *= ((class GFxManager*)(class Unk_FtUIScale*)(((class Unk_FtUIScale*)FUN_14025e7a0())))->FUN_1422afec0(m_28);
            kScreen.x -= pEntity->FUN_1422c1340() * 0.5;
            kScreen.y -= pEntity->GetHeightCeil() * 0.5;
            pEntity->SetPositionFloat(kScreen.x, kScreen.y);
            return true;
        }
    }
    return false;
}

// @0x1412c4930
Scaleform::GFx::Value Unk_FtEntity::FUN_1412c4930(const char* szMethod, CStringW a1, int a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcea0(args.FUN_1409b1f70(0), (const wchar_t*)a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1412c4a20
Scaleform::GFx::Value Unk_FtEntity::FUN_1412c4a20(const char* szMethod, CStringW a1, int a2, int a3, int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcea0(args.FUN_1409b1f70(0), (const wchar_t*)a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
