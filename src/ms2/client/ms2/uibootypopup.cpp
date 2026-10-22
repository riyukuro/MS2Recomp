// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBootyPopup ("BootyPopup" swf, ui id 0x4ebb, 0x90 bytes):
// the popup anchored above a function-cube object that names the reward item. The owner sets the world anchor
// (FUN_141031660), the entity (FUN_141031690) and the item id (FUN_1410316d0), then shows it (FUN_1410315c0); the
// per-frame vfunc_15 projects the anchor to the screen and moves the clip, FUN_141031a60 pushes the item name and
// the item's skill description to the swf ("setText") and shows or hides it ("setShow").
// MS2-UNIT: ?\uibootypopup.cpp
// MS2-RANGE: 0x141031430-0x141031f80 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibootypopup.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uibootypopup.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names / symbols) ----
extern Unk_StreamPoint DAT_143b01a60;                               // the zero point
class Unk_BootyWorld { public: void* FUN_141bd0cc0(); };            // non-null while the local player is in the world
Unk_BootyWorld* FUN_1403ed2d0();
class Unk_WorldToScreen { public: bool FUN_140af0700(const Unk_StreamPoint& world, Unk_StreamPoint& out); };
Unk_WorldToScreen* FUN_1409478c0();                                 // camera service
class Unk_UIScale;
Unk_UIScale* FUN_14025e7a0();                                       // ui scale service
float FUN_1422afec0(Unk_UIScale* pScale, int nLayer);               // scale of a layer
Unk_StreamPoint* FUN_140ad0c10(Unk_StreamPoint* pt, float f);       // efd::Point3::operator*=
MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);   // new ASGameEntity(v, n)
CStringTable* GetStringTable();                                     // the string tables
CStringW GetStringCommon(int nId);                                    // string table entry
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& nArg);  // formats one number argument into the message
CStringW FUN_1401d0160(const wchar_t* psz, const CStringW& str);    // psz + str
void FUN_141b706a0(int nId, int* pA, int* pB, int* pC);             // three numbers of a skill attribute

// Rows of the item table, the item's linked effect row and the skill attribute (only the fields read here).
class Unk_BootyItem : public CPtred
{
public:
    char m_pad_18[0x1e0 - 0x18];
    int m_nEffectId;                    // +0x1e0
};
MS2_CHECK_OFFSET(Unk_BootyItem, m_nEffectId, 0x1e0);
class Unk_BootyEffect : public CPtred
{
public:
    char m_pad_18[0x188 - 0x18];
    int m_nSkillId;                     // +0x188
    unsigned short m_nSkillLevel;       // +0x18c
};
MS2_CHECK_OFFSET(Unk_BootyEffect, m_nSkillId, 0x188);
MS2_CHECK_OFFSET(Unk_BootyEffect, m_nSkillLevel, 0x18c);
class Unk_BootySkillAttr : public CPtred
{
public:
    char m_pad_18[0x34 - 0x18];
    int m_nValueId;                     // +0x34
};
MS2_CHECK_OFFSET(Unk_BootySkillAttr, m_nValueId, 0x34);
MS2Ptr<Unk_BootyItem> FUN_14053f870(int nItemId);
MS2Ptr<Unk_BootyEffect> FUN_140704ec0(int nEffectId);
class Unk_BootySkillTable { public: MS2Ptr<Unk_BootySkillAttr> FUN_140aafef0(int nSkillId, unsigned short nLevel); };
Unk_BootySkillTable* FUN_1401958b0();
// AS invoker on the popup's movie clip (instance of the AScript::Invoke template).
class Unk_BootyMovie
{
public:
    Scaleform::GFx::Value FUN_140e78470(const char* szMethod, CStringW a1, CStringW a2);
};

// @0x141031430
UIBootyPopup::UIBootyPopup()
    : m_68(DAT_143b01a60), m_74(0), m_78(0), m_7c(0), m_80(), m_88(0)
{
    m_58 = 0;
    FUN_1422dbf00(7, 0, 0);
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
int UIBootyPopup::FUN_1410315a0()
{
    return m_74;
}
MS2_REPLACE_METHOD(0x1410315A0, UIBootyPopup, FUN_1410315a0, 14, 0x99EEE733);

// @0x1410315c0
void UIBootyPopup::FUN_1410315c0()
{
    m_78 = 1;
    m_74 = 1;
}
MS2_REPLACE_METHOD(0x1410315C0, UIBootyPopup, FUN_1410315c0, 30, 0x72EAC5DB);

// @0x1410315f0
void UIBootyPopup::FUN_1410315f0()
{
    FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(this));
    m_78 = 0;
    m_74 = 0;
}
MS2_REPLACE_METHOD(0x1410315F0, UIBootyPopup, FUN_1410315f0, 106, 0x1FFCB117);

// @0x141031660
void UIBootyPopup::FUN_141031660(const Unk_StreamPoint& pt)
{
    m_68 = pt;
}
MS2_REPLACE_METHOD(0x141031660, UIBootyPopup, FUN_141031660, 41, 0xA4605C70);

// @0x141031690
void UIBootyPopup::FUN_141031690(const egf::EntityID& kId)
{
    m_80 = kId;
}
MS2_REPLACE_METHOD(0x141031690, UIBootyPopup, FUN_141031690, 43, 0xB6F93E04);

// @0x1410316d0
void UIBootyPopup::FUN_1410316d0(int nItemId)
{
    m_88 = nItemId;
}
MS2_REPLACE_METHOD(0x1410316D0, UIBootyPopup, FUN_1410316d0, 25, 0x7F044B87);

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
    void* pWorld = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    if (m_78 != 0)
        vfunc_52();
    if (FUN_1410315a0())
        FUN_141031890();
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
void UIBootyPopup::FUN_141031890()
{
    void* pWorld = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pWorld == 0)
        return;
    if (m_7c != 0)
    {
        Unk_StreamPoint screen;
        if (FUN_1409478c0()->FUN_140af0700(m_68, screen))
        {
            MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
            if (pEntity.get())
            {
                vfunc_8(1);
                FUN_140ad0c10(&screen, FUN_1422afec0(FUN_14025e7a0(), m_28));
                pEntity->FUN_1422c00f0(screen.x - (float)(pEntity->FUN_1422c1340() / 2),
                                       (screen.y - (float)pEntity->FUN_1422c13b0()) - 15.0f);
            }
        }
        else
            vfunc_8(0);
    }
}
MS2_REPLACE_METHOD(0x141031890, UIBootyPopup, FUN_141031890, 453, 0xA0BF2377);

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
            CStringW strName = GetStringTable()->FUN_141811980(1, m_88);
            CStringW strDesc(L"");
            MS2Ptr<Unk_BootyItem> spItem = FUN_14053f870(m_88);
            if (spItem.get() != 0)
            {
                MS2Ptr<Unk_BootyEffect> spEffect = FUN_140704ec0(spItem->m_nEffectId);
                if (spEffect.get() != 0)
                {
                    int nSkillId = spEffect->m_nSkillId;
                    unsigned short nSkillLevel = spEffect->m_nSkillLevel;
                    strDesc = GetStringTable()->FUN_141812290(nSkillId, nSkillLevel, CString("tooltipDescription"));
                    MS2Ptr<Unk_BootySkillAttr> spAttr = FUN_1401958b0()->FUN_140aafef0(nSkillId, nSkillLevel);
                    if (spAttr.get() != 0)
                    {
                        int nA = 0;
                        int nC = 0;
                        int nB = 0;
                        FUN_141b706a0(spAttr->m_nValueId, &nA, &nC, &nB);
                        CStringW strLine = FUN_1401ceea0(GetStringCommon(0x9a8), nA);
                        strDesc += FUN_1401d0160(L"\n", strLine);
                    }
                }
            }
            reinterpret_cast<Unk_BootyMovie*>(m_30.operator->())->FUN_140e78470("setText", strName, strDesc);
        }
        m_30.operator->()->Invoke("setShow", bShow);
    }
}
MS2_REPLACE_METHOD(0x141031A60, UIBootyPopup, FUN_141031a60, 1100, 0x988C31D6);

// @0x141031ec0
void UIBootyPopup::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}
MS2_REPLACE_METHOD(0x141031EC0, UIBootyPopup, vfunc_41, 99, 0x5BE21341);

// @0x141031f70
int UIBootyPopup::vfunc_48()
{
    return 0x4ebb;
}
MS2_REPLACE_METHOD(0x141031F70, UIBootyPopup, vfunc_48, 11, 0x14F4E3CC);
