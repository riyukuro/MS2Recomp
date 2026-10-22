// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICubeUGCHead: the label above a UGC cube.
// MS2-UNIT: ?\uicubeugchead.cpp
// MS2-RANGE: 0x141906490-0x141906f30 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicubeugchead.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uicubeugchead.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names / symbols) ----
extern Vector3 DAT_143b01a60;                               // the zero point
extern int DAT_143ae0fc0;                                           // debug switch: UI always shown
int FUN_141277f40();                                                // next UI layer
int FUN_140707660(int nKind);
int FUN_140707710(int nKind);
class Unk_UgcUiMgr { public: int FUN_141adc890(int nUIType); };
Unk_UgcUiMgr* FUN_1403ed2b0();
struct Unk_UgcRes16 { Unk_UgcRes16(const Unk_UgcRes16& o) : m_a(o.m_a), m_b(o.m_b) {} __int64 m_a, m_b; };
Unk_UgcRes16 FUN_1408a15b0(Unk_UgcCell cell, Vector3 ptOrigin);   // the world point of a cell
Unk_UgcRes16 FUN_14027dcf0(Unk_UgcRes16 res);
class Unk_WorldToScreen { public: bool FUN_140af0700(Unk_UgcRes16 world, Vector3& out); };
Unk_WorldToScreen* FUN_1409478c0();                                 // camera service
class Unk_UIScale;
Unk_UIScale* FUN_14025e7a0();                                       // ui scale service
float FUN_1422afec0(Unk_UIScale* pScale, int nLayer);               // scale of a layer
Vector3* FUN_140ad0c10(Vector3* pt, float f);       // efd::Point3::operator*=
void FUN_1422bfe00(ASDisplayObject* pObj, float fAlpha);            // set the alpha
void FUN_1422c00f0(ASGameEntity* pEntity, float x, float y);        // set the position
MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);   // new ASGameEntity(v, n)
// AS invoker on the label's movie clip (instance of the AScript::Invoke template).
class Unk_UgcMovie
{
public:
    Scaleform::GFx::Value FUN_140e78470(const char* szMethod, CStringW a1, CStringW a2);
};

// @0x141906490
UICubeUGCHead::UICubeUGCHead(Unk_UgcCell cell, CStringW strName, int nType)
    : m_68(cell), m_78(strName), m_80(0), m_84(0), m_8c(nType)
{
    m_2c = 2;
    m_58 = 0;
    m_28 = FUN_141277f40();
    FUN_1422dbf00(m_2c, 1, 0);
}

// @0x1419065a0
CString UICubeUGCHead::GetTypeName()
{
    return "CubeUGCHead";
}

// @0x1419065f0
int UICubeUGCHead::FUN_1419065f0()
{
    return m_80;
}

// @0x141906610
void UICubeUGCHead::FUN_141906610(int nId)
{
    m_88 = nId;
    m_84 = 1;
    m_80 = 1;
}

// @0x141906650
void UICubeUGCHead::FUN_141906650()
{
    m_84 = 0;
    m_80 = 0;
}

// @0x141906680
void UICubeUGCHead::FUN_141906680()
{
    vfunc_8(0);
    FUN_141906650();
    FUN_1422dc080();
}

// @0x1419066c0
int UICubeUGCHead::FUN_1419066c0()
{
    if (FUN_140707660(m_8c) != 0 || FUN_140707710(m_8c) != 0)
    {
        if (FUN_1403ed2b0()->FUN_141adc890(0x4e6b) != 0)
            return 1;
    }
    if (DAT_143ae0fc0 != 0)
        return 1;
    return 0;
}

// @0x141906730
void UICubeUGCHead::vfunc_2()
{
    UISwfEntity::vfunc_2();
    FUN_1422dbf00(m_2c, m_44, 0);
    FUN_141906610(m_88);
}

// @0x141906790
void UICubeUGCHead::vfunc_3()
{
    UISwfEntity::vfunc_3();
    FUN_1422dc080();
    FUN_141906650();
}

// MS2-FUNCTIONAL: operator-> / Invoke store order differs
// @0x1419067d0
void UICubeUGCHead::vfunc_52()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
    {
        if (FUN_1419066c0() != 0)
            vfunc_8(1);
        else
            vfunc_8(0);
        FUN_1422bfe00(pClip.operator->(), 100.0f);
        CStringW strId;
        strId.Format(L"ID:%d", m_88);
        reinterpret_cast<Unk_UgcMovie*>(pClip.operator->())->FUN_140e78470("setData", strId, m_78);
        pClip->Invoke("setFontSize", 0x12);
        if (FUN_140707660(m_8c) != 0)
            pClip->Invoke("setFontColor", 0x45ff98);
        else
            pClip->Invoke("setFontColor", 0x3df0fb);
        m_84 = 0;
    }
}

// @0x141906a80
void UICubeUGCHead::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_30.IsNull())
        return;
    if (m_84 != 0)
        vfunc_52();
    if (FUN_1419065f0())
        FUN_141906b60();
    else
        vfunc_8(0);
}

// @0x141906b10
int UICubeUGCHead::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: stack-slot layout of the world-point temporaries differs
// @0x141906b60
void UICubeUGCHead::FUN_141906b60()
{
    Vector3 screen;
    Vector3 ptZero = DAT_143b01a60;
    Unk_UgcRes16 world = FUN_14027dcf0(FUN_1408a15b0(m_68, ptZero));
    if (FUN_1409478c0()->FUN_140af0700(world, screen) == 0)
        vfunc_8(0);
    else
    {
        MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pEntity.get())
        {
            if (FUN_1419066c0() != 0)
                vfunc_8(1);
            else
                vfunc_8(0);
            FUN_140ad0c10(&screen, FUN_1422afec0(FUN_14025e7a0(), m_28));
            FUN_1422c00f0(pEntity.operator->(), screen.x, screen.y);
        }
    }
}

// @0x141906d20
void UICubeUGCHead::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}

// @0x141906d90
UICubeUGCHead::~UICubeUGCHead()
{
}

MS2_EMIT_CRT_MEMMOVE_S();
