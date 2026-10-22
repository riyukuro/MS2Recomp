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

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_FtWorld
{
public:
    MS2Ptr<CInteractObject> FUN_141bc66b0(const CString& strName);      // an interact object by name
};
Unk_FtWorld* FUN_1403ed2d0();
void* FUN_1403ed290();                                                  // the guild manager (its CGuildInfo sits at +8)

// The score table of the guild ranking seasons: the entry of a trophy count has a value at +0x18.
struct Unk_FtSeasonEntry { char m_pad_00[0x18]; int m_nValue; };
class Unk_FtSeasonTable;
Unk_FtSeasonTable* FUN_140dc19b0();
Unk_FtSeasonEntry* FUN_140769000(Unk_FtSeasonTable* pTable, int nTrophy);

class Unk_FtWorldToScreen { public: bool FUN_140af0700(const Unk_StreamPoint& world, Unk_StreamPoint& out); };
Unk_FtWorldToScreen* FUN_1409478c0();                                   // camera service
class Unk_FtUIScale;
Unk_FtUIScale* FUN_14025e7a0();                                         // ui scale service
float FUN_1422afec0(Unk_FtUIScale* pScale, int nLayer);                 // scale of a layer
Unk_StreamPoint* FUN_140ad0c10(Unk_StreamPoint* pt, float f);           // efd::Point3::operator*=
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
    if (m_70 != 0 && FUN_1412c46d0() == 0)
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
// MS2-FUNCTIONAL: behaviour-equivalent; the exe's temporaries / handle slots and EH state layout differ
void UIGuildFlagTooltip::FUN_1412c4050(const CString& strName)
{
    if (m_70 == 1)
        return;
    m_78 = strName;
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get())
    {
        CInteractObject* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_78).get();
        if (pObject == 0)
            return;
        CInteractDisplayImage* pImage = dynamic_cast<CInteractDisplayImage*>(pObject);
        if (pImage == 0)
            return;
        CStringW strCaption = pImage->FUN_141402060();
        int nTrophy = pImage->FUN_1414022a0();
        int nRank = pImage->FUN_1414021c0();
        int nImageType = 0;
        if (pImage->GetRow().get() != 0)
            nImageType = pImage->GetRow()->m_displayUrl.m_nType;
        if (strCaption.GetLength() > 0)
        {
            m_70 = 1;
            pEntity->vfunc_3(1);
            Unk_FtEntity* pMovie = static_cast<Unk_FtEntity*>(pEntity.operator->());
            if (nImageType == 3)
            {
                CGuildInfo* pGuild = reinterpret_cast<CGuildInfo*>((char*)FUN_1403ed290() + 8);
                int nScore = pGuild->FUN_1404d3180()->FUN_1404c6110(nTrophy);
                pMovie->FUN_1412c4a20("showPvp", CStringW(strCaption), nTrophy, nRank, nScore);
            }
            else if (nImageType == 4)
            {
                pMovie->FUN_1412c4930("showBuilder", CStringW(strCaption), nTrophy, nRank);
            }
            else if (nImageType == 5)
            {
                Unk_FtSeasonEntry* pEntry = FUN_140769000(FUN_140dc19b0(), nTrophy);
                pMovie->FUN_1412c4a20("showPvp", CStringW(strCaption), nTrophy, nRank, pEntry->m_nValue);
            }
            else
            {
                pMovie->FUN_1412c4930("show", CStringW(strCaption), nTrophy, nRank);
            }
            FUN_1412c46d0();
        }
    }
}

// @0x1412c45a0
void UIGuildFlagTooltip::FUN_1412c45a0()
{
    if (m_70 != 0)
    {
        MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pEntity.get())
            m_30->Invoke("hideTooltip");
    }
}

// @0x1412c4660
void UIGuildFlagTooltip::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

// @0x1412c46d0
// MS2-FUNCTIONAL: behaviour-equivalent; the exe's temporaries / handle slots and EH state layout differ
bool UIGuildFlagTooltip::FUN_1412c46d0()
{
    if (m_78.GetLength() < 1)
        return false;
    CInteractObject* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_78).get();
    if (pObject == 0)
        return false;
    if (dynamic_cast<CInteractDisplayImage*>(pObject) == 0)
        return false;
    Unk_StreamPoint kWorld = pObject->GetPos();
    kWorld.z += 150.0f;
    Unk_StreamPoint kScreen;
    if (FUN_1409478c0()->FUN_140af0700(kWorld, kScreen))
    {
        MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pEntity.get())
        {
            FUN_140ad0c10(&kScreen, FUN_1422afec0(FUN_14025e7a0(), m_28));
            kScreen.x = kScreen.x - (float)pEntity->FUN_1422c1340() * 0.5f;
            kScreen.y = kScreen.y - (float)pEntity->FUN_1422c13b0() * 0.5f;
            pEntity->FUN_1422c00f0(kScreen.x, kScreen.y);
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
