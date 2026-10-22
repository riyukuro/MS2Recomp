// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBirdHead: world-anchored bird head tooltip UI.
// MS2-UNIT: ?\uibirdhead.cpp
// MS2-RANGE: 0x1418ce5e0-0x1418cf080 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibirdhead.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uibirdhead.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names / symbols) ----
extern Unk_StreamPoint DAT_143b01a60;                               // the zero point
extern int DAT_143ae0fc0;                                           // debug switch: UI always shown
int FUN_141277f40();                                                // next UI layer
class Unk_WorldToScreen { public: bool FUN_140af0700(const Unk_StreamPoint& world, Unk_StreamPoint& out); };
Unk_WorldToScreen* FUN_1409478c0();                                 // camera service
class Unk_UIScale;
Unk_UIScale* FUN_14025e7a0();                                       // ui scale service
float FUN_1422afec0(Unk_UIScale* pScale, int nLayer);               // scale of a layer
Unk_StreamPoint* FUN_140ad0c10(Unk_StreamPoint* pt, float f);       // efd::Point3::operator*=
void FUN_1422bfe00(ASDisplayObject* pObj, float fAlpha);            // set the alpha
void FUN_1422c00f0(ASGameEntity* pEntity, float x, float y);        // set the position
MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);   // new ASGameEntity(v, n)
// AS invokers on the tooltip's movie clip (instances of the AScript::Invoke templates).
class Unk_TooltipMovie
{
public:
    Scaleform::GFx::Value FUN_140e0a8c0(const char* szMethod, CStringW a1, int a2);
    Scaleform::GFx::Value FUN_140e78470(const char* szMethod, CStringW a1, CStringW a2);
};

// @0x1418ce5e0
UIBirdHead::UIBirdHead()
    : m_68(1), m_6c(DAT_143b01a60), m_78(0), m_7c(0), m_80(0), m_88(L""), m_90(L""), m_98(L""), m_a0(0.0f)
{
    m_28 = FUN_141277f40();
    m_58 = 0;
    FUN_1422dbf00(2, 0, 0);
}

// @0x1418ce710
UIBirdHead::~UIBirdHead()
{
}

// @0x1418ce790
CString UIBirdHead::GetTypeName()
{
    return "BirdHead";
}
MS2_REPLACE_METHOD(0x1418CE790, UIBirdHead, GetTypeName, 61, 0xF8542D70);

// @0x1418ce7e0
int UIBirdHead::FUN_1418ce7e0()
{
    return m_78;
}
MS2_REPLACE_METHOD(0x1418CE7E0, UIBirdHead, FUN_1418ce7e0, 14, 0xB1F80757);

// @0x1418ce800
void UIBirdHead::FUN_1418ce800()
{
    m_7c = 1;
    m_78 = 1;
}
MS2_REPLACE_METHOD(0x1418CE800, UIBirdHead, FUN_1418ce800, 30, 0x3D58469B);

// @0x1418ce830
void UIBirdHead::FUN_1418ce830()
{
    FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(this));
}
MS2_REPLACE_METHOD(0x1418CE830, UIBirdHead, FUN_1418ce830, 82, 0x099CC8F3);

// @0x1418ce890
void UIBirdHead::FUN_1418ce890()
{
    m_7c = 0;
    m_78 = 0;
}
MS2_REPLACE_METHOD(0x1418CE890, UIBirdHead, FUN_1418ce890, 30, 0xA515CB4B);

// @0x1418ce8c0
void UIBirdHead::FUN_1418ce8c0(const Unk_StreamPoint& pt)
{
    m_6c = pt;
}
MS2_REPLACE_METHOD(0x1418CE8C0, UIBirdHead, FUN_1418ce8c0, 41, 0x197B3CE1);

// @0x1418ce8f0
void UIBirdHead::FUN_1418ce8f0(CStringW strMain, CStringW strExtra)
{
    m_7c = 1;
    m_88 = strMain;
    m_98 = strExtra;
}
MS2_REPLACE_METHOD(0x1418CE8F0, UIBirdHead, FUN_1418ce8f0, 119, 0x3596772E);

// @0x1418ce970
void UIBirdHead::FUN_1418ce970(CStringW strAdditional)
{
    m_7c = 1;
    m_90 = strAdditional;
}
MS2_REPLACE_METHOD(0x1418CE970, UIBirdHead, FUN_1418ce970, 77, 0xB29FF3CF);

// @0x1418ce9d0
void UIBirdHead::FUN_1418ce9d0()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
    {
        if (m_80 != 0)
        {
            pClip->Invoke("showAdditional", 0);
            m_80 = 0;
        }
        else
        {
            pClip->Invoke("showAdditional", 1);
            m_80 = 1;
        }
    }
}
MS2_REPLACE_METHOD(0x1418CE9D0, UIBirdHead, FUN_1418ce9d0, 300, 0x6075389F);

// @0x1418ceb10
void UIBirdHead::vfunc_52()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
    {
        vfunc_8(1);
        FUN_1422bfe00(pClip.operator->(), 100.0f);
        reinterpret_cast<Unk_TooltipMovie*>(pClip.operator->())->FUN_140e78470("setData", m_88, m_98);
        reinterpret_cast<Unk_TooltipMovie*>(pClip.operator->())->FUN_140e0a8c0("setAdditional", m_90, 0);
        pClip->Invoke("setFontSize", 0x12);
        pClip->Invoke("setFontColor", 0x3df0fb);
        m_7c = 0;
    }
}
MS2_REPLACE_METHOD(0x1418CEB10, UIBirdHead, vfunc_52, 627, 0x98249AF1);

// @0x1418ced90
void UIBirdHead::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_30.IsNull())
        return;
    if (m_7c != 0)
        vfunc_52();
    if (FUN_1418ce7e0())
        FUN_1418cee70();
    else
        vfunc_8(0);
}
MS2_REPLACE_METHOD(0x1418CED90, UIBirdHead, vfunc_15, 124, 0x11303266);

// @0x1418cee20
int UIBirdHead::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1418CEE20, UIBirdHead, vfunc_28, 67, 0xFC04CE34);

// @0x1418cee70
void UIBirdHead::FUN_1418cee70()
{
    Unk_StreamPoint screen;
    if (FUN_1409478c0()->FUN_140af0700(m_6c, screen))
    {
        MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pEntity.get())
        {
            vfunc_8(1);
            FUN_140ad0c10(&screen, FUN_1422afec0(FUN_14025e7a0(), m_28));
            FUN_1422c00f0(pEntity.operator->(), screen.x, screen.y + m_a0);
        }
    }
    else
        vfunc_8(0);
}
MS2_REPLACE_METHOD(0x1418CEE70, UIBirdHead, FUN_1418cee70, 330, 0x050CB4DE);

// @0x1418cefc0
void UIBirdHead::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}
MS2_REPLACE_METHOD(0x1418CEFC0, UIBirdHead, vfunc_41, 99, 0xFBAD23FE);
