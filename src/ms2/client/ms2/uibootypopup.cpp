// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBootyPopup ("BootyPopup" swf, ui id 0x4ebb, 0x90 bytes):
// the popup anchored above a function-cube object that names the reward item. The owner sets the world anchor
// (FUN_141031660), the entity (SetEntityId) and the item id (SetItemId), then shows it (Show); the
// per-frame vfunc_15 projects the anchor to the screen and moves the clip, FUN_141031a60 pushes the item name and
// the item's skill description to the swf ("setText") and shows or hides it ("setShow").
// MS2-UNIT: ?\uibootypopup.cpp
// MS2-RANGE: 0x141031430-0x141031f80 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibootypopup.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include "uibootypopup.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/commonfiles/additionalactionadditional.h"   // C3: AdditionalLevelData
#include "ms2/client/ms2/camera.h"
#include "ms2/ms2format.h"   // C3: StringFormat<int> (was FUN_1401ceea0)
#include "ms2/commonfiles/objectdata.h"   // C3: CObjectData, FUN_140704ec0

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names / symbols) ----
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
            // non-null while the local player is in the world
class Unk_UIScale;
class Unk_AltStringMgr* GetGFxManager();   // C3: was GetGFxManager
class GFxManager   // C3: member view for the former free stand-ins
{
public:
    float GetMovieScale(int);
};
MS2Ptr<ASGameEntity> CreateGameEntity(int n, const Scaleform::GFx::Value& v);   // new ASGameEntity(v, n)
CStringW GetStringCommon(int nId);                                    // string table entry
void FUN_141b706a0(unsigned int, unsigned int*, unsigned int*, unsigned int*);   // C3: was FUN_141b706a0

// Rows of the item table, the item's linked effect row and the skill attribute (only the fields read here).
class CItemData : public CPtred
{
public:
    char m_pad_18[0x1e0 - 0x18];
    int m_nEffectId;                    // +0x1e0
};
MS2_CHECK_OFFSET(CItemData, m_nEffectId, 0x1e0);
static_assert(offsetof(CObjectData, m_cube.m_firstEffect.m_nEffectId) == 0x188, "the skill id read at +0x188");
static_assert(offsetof(CObjectData, m_cube.m_firstEffect.m_nLevel) == 0x18c, "the skill level read at +0x18c");
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// @0x141031430
UIBootyPopup::UIBootyPopup()
    : m_68(DAT_143b01a60), m_74(0), m_78(0), m_7c(0), m_80(), m_88(0)
{
    m_58 = 0;
    LoadSwf(7, 0, 0);
}

// @0x141031510
UIBootyPopup::~UIBootyPopup()
{
}

// @0x141031550
CString UIBootyPopup::GetTypeName()
{
    return "BootyPopup";
}
MS2_REPLACE_METHOD(0x141031550, UIBootyPopup, GetTypeName, 61, 0x709A4D26);

// @0x1410315a0
int UIBootyPopup::IsShown()
{
    return m_74;
}
MS2_REPLACE_METHOD(0x1410315A0, UIBootyPopup, IsShown, 14, 0x99EEE733);

// @0x1410315c0
void UIBootyPopup::Show()
{
    m_78 = 1;
    m_74 = 1;
}
MS2_REPLACE_METHOD(0x1410315C0, UIBootyPopup, Show, 30, 0x72EAC5DB);

// @0x1410315f0
void UIBootyPopup::Close()
{
    GetUISwfEntityManager()->RemoveEntity(MS2Ptr<UISwfEntity>(this));
    m_78 = 0;
    m_74 = 0;
}
MS2_REPLACE_METHOD(0x1410315F0, UIBootyPopup, Close, 106, 0x1FFCB117);

// @0x141031660
void UIBootyPopup::FUN_141031660(Vector3 pt)
{
    m_68 = pt;
}
MS2_REPLACE_METHOD(0x141031660, UIBootyPopup, FUN_141031660, 41, 0xA4605C70);

// @0x141031690
void UIBootyPopup::SetEntityId(egf::EntityID kId)
{
    m_80 = kId;
}
MS2_REPLACE_METHOD(0x141031690, UIBootyPopup, SetEntityId, 43, 0xB6F93E04);

// @0x1410316d0
void UIBootyPopup::SetItemId(int nItemId)
{
    m_88 = nItemId;
}
MS2_REPLACE_METHOD(0x1410316D0, UIBootyPopup, SetItemId, 25, 0x7F044B87);

// @0x1410316f0
void UIBootyPopup::vfunc_52()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
    {
        vfunc_8(0);
        m_78 = 0;
    }
}
MS2_REPLACE_METHOD(0x1410316F0, UIBootyPopup, vfunc_52, 167, 0x80B0F769);

// @0x1410317a0
void UIBootyPopup::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_30.IsNull())
        return;
    void* pWorld = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    if (m_78 != 0)
        vfunc_52();
    if (IsShown())
        UpdateScreenPosition();
    else
        vfunc_8(0);
}
MS2_REPLACE_METHOD(0x1410317A0, UIBootyPopup, vfunc_15, 152, 0xA4E1DF49);

// @0x141031840
int UIBootyPopup::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141031840, UIBootyPopup, vfunc_28, 67, 0x0A02777B);

// @0x141031890
void UIBootyPopup::UpdateScreenPosition()
{
    void* pWorld = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    if (m_7c != 0)
    {
        Vector3 screen;
        if (TSingleton<CameraMgr>::GetInstance()->FUN_140af0700(reinterpret_cast<const efd::Point3&>(m_68), reinterpret_cast<NiPoint3&>(screen)))
        {
            MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
            if (pEntity.get())
            {
                vfunc_8(1);
                reinterpret_cast<efd::Point3&>(screen) *= ((class GFxManager*)(class Unk_UIScale*)(((class Unk_UIScale*)GetGFxManager())))->GetMovieScale(m_28);
                pEntity->SetPositionFloat(screen.x - (float)(pEntity->GetWidthCeil() / 2),
                                       (screen.y - (float)pEntity->GetHeightCeil()) - 15.0f);
            }
        }
        else
            vfunc_8(0);
    }
}
MS2_REPLACE_METHOD(0x141031890, UIBootyPopup, UpdateScreenPosition, 453, 0xA0BF2377);

// Show or hide the popup; showing first pushes the item name and the description of the skill the item grants.
// @0x141031a60
void UIBootyPopup::FUN_141031a60(int bShow)
{
    if (m_30.IsNull())
        return;
    if (m_7c == bShow)
        return;
    {
        m_7c = bShow;
        if (bShow != 0)
        {
            CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, m_88);
            CStringW strDesc(L"");
            MS2Ptr<CItemData> spItem = FUN_14053f870(m_88);
            if (spItem.get() != 0)
            {
                CObjectDataPtr spEffect = GetObjectData(spItem->m_nEffectId);
                if (spEffect.get() != 0)
                {
                    int nSkillId = spEffect->m_cube.m_firstEffect.m_nEffectId;
                    unsigned short nSkillLevel = spEffect->m_cube.m_firstEffect.m_nLevel;
                    strDesc = TSingleton<CStringTable>::GetInstance()->FUN_141812290(nSkillId, nSkillLevel, CString("tooltipDescription"));
                    MS2Ptr<AdditionalLevelData> spAttr = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(nSkillId, nSkillLevel);
                    if (spAttr.get() != 0)
                    {
                        int nA = 0;
                        int nC = 0;
                        int nB = 0;
                        FUN_141b706a0(spAttr->m_nDurationTick, (unsigned int*)(&nA), (unsigned int*)(&nC), (unsigned int*)(&nB));
                        CStringW strLine = StringFormat<int>(GetStringCommon(0x9a8), nA);
                        strDesc += L"\n" + strLine;
                    }
                }
            }
            m_30.operator->()->Invoke("setText", strName, strDesc);
        }
        m_30.operator->()->Invoke("setShow", bShow);
    }
}
MS2_REPLACE_METHOD(0x141031A60, UIBootyPopup, FUN_141031a60, 1100, 0x988C31D6);

// @0x141031ec0
void UIBootyPopup::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = CreateGameEntity(m_28, root);
}
MS2_REPLACE_METHOD(0x141031EC0, UIBootyPopup, vfunc_41, 99, 0x5BE21341);

// @0x141031f70
int UIBootyPopup::vfunc_48()
{
    return 0x4ebb;
}
MS2_REPLACE_METHOD(0x141031F70, UIBootyPopup, vfunc_48, 11, 0x14F4E3CC);
