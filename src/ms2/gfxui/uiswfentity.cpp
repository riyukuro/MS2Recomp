// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISwfEntity, the base of every Scaleform UI object.
// MS2-UNIT: ?\uiswfentity.cpp
// MS2-RANGE: 0x1422db480-0x1422dcbe0 .text$mn
// MS2-RANGE: 0x14013acf0-0x14013ad80 .text$di
// MS2-RANGE: 0x142cc8970-0x142cc89f0 .text$yd
//
// The unit name and directory are assumed: the GFx UI library this unit belongs to (0x1422b0000-0x142304000) has no
// __FILE__ strings and no asserts, so MS2_THIS_FILE is not needed. Unit boundaries: the ctor 0x1422db480 is the
// first function after GFxMovieEventHandler's obj; ASCoreList's obj starts at 0x1422dcbe0. Names are invented
// (see uiswfentity.h); Ghidra's vfunc_<slot> / FUN_<va> are kept so derived-class decompiles map onto them.
#include "ms2/placeholder/ms2stdafx.h"

#include "uiswfentity.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/uiswfentitymanager.h"

#include "hook/ms2hook.h"

// ---- unit-local placeholders (unrecovered singletons / helpers; promote to src/ms2/placeholder/ when shared) ----

class Unk_140e45740     // UI focus/modal manager? (0x1422e6bf0 / 0x1422e6d00 live in the GFx UI library)
{
public:
    int FUN_1422e6bf0(UISwfEntity* p, int n);
    void FUN_1422e6d00(int n);
};
Unk_140e45740* FUN_140e45740();
class Unk_1422d6240     // GFx file system / loader (0x1422f6d50 resolves a swf key to a path)
{
public:
    int FUN_1422f6d50(CString& strOut, CString strKey, void* p);
};
Unk_1422d6240* FUN_1422d6240();
// "{0}"-style formatter (probably a variadic template; 0x140540050 is the (const char*, CString) instance).
CString FUN_140540050(const char* szFormat, const CString& a1);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Delegate<CString(CString, bool)> UISwfEntity::s_swfNameDelegate;   // 0x143b0d2f0
static CString s_strNoPath = "";                                    // 0x143b0d300 FUN_1422db910's failure result
static CString s_strNoKey = "";                                     // 0x143b0d2f8 m_20 while not registered

// @0x1422db480
UISwfEntity::UISwfEntity()
    : m_20(s_strNoKey), m_28(2), m_2c(0), m_30(0), m_40(0), m_44(0), m_48(0), m_4c(0), m_50(1), m_54(0), m_58(1),
      m_5c(0), m_60(0)
{
    FUN_140b632f0()->FUN_1422d0cd0(MS2Ptr<UISwfEntity>(this));
}

// @0x1422db5d0
UISwfEntity::~UISwfEntity()
{
    m_20 = s_strNoKey;
    m_30 = 0;
}

// @0x1422db670
CString UISwfEntity::GetTypeName()
{
    return "SwfEntity";
}
MS2_REPLACE_METHOD(0x1422DB670, UISwfEntity, GetTypeName, 61, 0xE8BD2BD9);

// @0x1422db6c0
void UISwfEntity::vfunc_2()
{
}
MS2_REPLACE_METHOD(0x1422DB6C0, UISwfEntity, vfunc_2, 6, 0xA9AF6E37);

// @0x1422db6d0
void UISwfEntity::vfunc_3()
{
}
MS2_REPLACE_METHOD(0x1422DB6D0, UISwfEntity, vfunc_3, 6, 0xA9AF6E37);

// @0x1422db6e0
CString UISwfEntity::FUN_1422db6e0()
{
    return m_20;
}
MS2_REPLACE_METHOD(0x1422DB6E0, UISwfEntity, FUN_1422db6e0, 66, 0x851538D8);

// @0x1422db730
int UISwfEntity::FUN_1422db730()
{
    return m_28;
}
MS2_REPLACE_METHOD(0x1422DB730, UISwfEntity, FUN_1422db730, 14, 0xD26D6807);

// @0x1422db750
int UISwfEntity::FUN_1422db750()
{
    return m_2c;
}
MS2_REPLACE_METHOD(0x1422DB750, UISwfEntity, FUN_1422db750, 14, 0x6A78E4AB);

// @0x1422db770
int UISwfEntity::FUN_1422db770()
{
    return m_44;
}
MS2_REPLACE_METHOD(0x1422DB770, UISwfEntity, FUN_1422db770, 14, 0x7A15C443);

// @0x1422db790
CString UISwfEntity::FUN_1422db790()
{
    CString strName = vfunc_7();
    if (!s_swfNameDelegate.IsNull())
        return s_swfNameDelegate(strName, m_40 ? true : false);
    if (strName.IsEmpty())
        return "";
    if (m_40)
        return FUN_140540050("Debug_UI{0}.swf", strName);
    return FUN_140540050("UI{0}.swf", strName);
}
// Not hooked: reads s_swfNameDelegate, which the exe sets at startup (0x1416275e0 -> 0x141629ed0). The DLL's copy of
// the static is never set, so a replacement would ignore the installed delegate (see docs/RECOVERY.md section 9).

// @0x1422db910
CString UISwfEntity::FUN_1422db910(void* p)
{
    CString strPath;
    if (FUN_1422d6240()->FUN_1422f6d50(strPath, FUN_1422db6e0(), p))
        return strPath;
    return s_strNoPath;
}
MS2_REPLACE_METHOD(0x1422DB910, UISwfEntity, FUN_1422db910, 219, 0x83201F53);

// @0x1422dba00
MS2Ptr<AScript> UISwfEntity::FUN_1422dba00()
{
    return m_30;
}
MS2_REPLACE_METHOD(0x1422DBA00, UISwfEntity, FUN_1422dba00, 65, 0xEFC795F8);

// @0x1422dba50
MS2Ptr<ASDisplayObject> UISwfEntity::FUN_1422dba50()
{
    return MS2Ptr<ASDisplayObject>(dynamic_cast<ASDisplayObject*>((AScript*)m_30));
}
MS2_REPLACE_METHOD(0x1422DBA50, UISwfEntity, FUN_1422dba50, 105, 0xC95E781A);

// @0x1422dbac0
int UISwfEntity::vfunc_4()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1422DBAC0, UISwfEntity, vfunc_4, 8, 0x7F371472);

// @0x1422dbad0
int UISwfEntity::vfunc_5()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1422DBAD0, UISwfEntity, vfunc_5, 8, 0x7F371472);

// @0x1422dbae0
int UISwfEntity::vfunc_6()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1422DBAE0, UISwfEntity, vfunc_6, 8, 0x7F371472);

// @0x1422dbaf0
CString UISwfEntity::vfunc_7()
{
    return GetTypeName();
}
MS2_REPLACE_METHOD(0x1422DBAF0, UISwfEntity, vfunc_7, 64, 0xA54AF9CB);

// @0x1422dbb40
const Scaleform::GFx::Value& UISwfEntity::FUN_1422dbb40()
{
    static Scaleform::GFx::Value s_undefined;   // 0x143b0d308
    if (m_30 == NULL)
        return s_undefined;
    return m_30->FUN_1422bb870();
}
MS2_REPLACE_METHOD(0x1422DBB40, UISwfEntity, FUN_1422dbb40, 178, 0x0407E03B);

// @0x1422dbc00
const Scaleform::GFx::Value& UISwfEntity::FUN_1422dbc00()
{
    return FUN_1422dbb40();
}
MS2_REPLACE_METHOD(0x1422DBC00, UISwfEntity, FUN_1422dbc00, 24, 0xEBEE8B26);

// @0x1422dbc20
void UISwfEntity::vfunc_8(int nVisible)
{
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
        pClip->vfunc_3(nVisible);
}
MS2_REPLACE_METHOD(0x1422DBC20, UISwfEntity, vfunc_8, 151, 0x1A759302);

// @0x1422dbcc0
int UISwfEntity::vfunc_9()
{
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
        return pClip->FUN_1422bfca0();
    return 0;
}
MS2_REPLACE_METHOD(0x1422DBCC0, UISwfEntity, vfunc_9, 164, 0x6E48A992);

// @0x1422dbd70
void UISwfEntity::FUN_1422dbd70(int a1, int a2)
{
    if (FUN_140b632f0()) {
        if (m_20 == s_strNoKey && !FUN_1422db790().IsEmpty()) {
            m_2c = a1;
            FUN_140b632f0()->FUN_1422d1210(m_28, m_20, FUN_1422db790(), a1, a2);
        }
    }
}
MS2_REPLACE_METHOD(0x1422DBD70, UISwfEntity, FUN_1422dbd70, 383, 0x70BEFCBE);

// @0x1422dbf00
void UISwfEntity::FUN_1422dbf00(int a1, int a2, int a3)
{
    FUN_1422dbf80(FUN_1422db790(), a1, a2, a3);
}
MS2_REPLACE_METHOD(0x1422DBF00, UISwfEntity, FUN_1422dbf00, 112, 0x1885C4E6);

// @0x1422dbf80
void UISwfEntity::FUN_1422dbf80(const CString& strPath, int a1, int a2, int a3)
{
    if (FUN_140b632f0() && m_20 == s_strNoKey && !strPath.IsEmpty()) {
        m_44 = a2;
        m_2c = a1;
        FUN_140b632f0()->FUN_1422d1320(m_28, m_20, strPath, a1, a2, a3, this);
    }
}
MS2_REPLACE_METHOD(0x1422DBF80, UISwfEntity, FUN_1422dbf80, 243, 0x45190D1E);

// @0x1422dc080
void UISwfEntity::FUN_1422dc080()
{
    vfunc_4();
    FUN_1422dc0b0();
}
MS2_REPLACE_METHOD(0x1422DC080, UISwfEntity, FUN_1422dc080, 40, 0xB0410145);

// @0x1422dc0b0
void UISwfEntity::FUN_1422dc0b0()
{
    vfunc_26();
    if (FUN_140b632f0())
        m_20 = FUN_140b632f0()->FUN_1422d17a0(m_28, m_20, m_2c);
    vfunc_27();
    m_30 = 0;
    m_4c = 0;
    m_54 = 0;
}
MS2_REPLACE_METHOD(0x1422DC0B0, UISwfEntity, FUN_1422dc0b0, 294, 0x77CAFA8D);

// @0x1422dc1e0
void UISwfEntity::FUN_1422dc1e0()
{
    if (FUN_1422dc310()) {
        int n = m_44;
        m_44 = 0;
        FUN_1422dc080();
        FUN_1422dbf00(m_2c, 0, 0);
        m_44 = n;
        vfunc_40();
    }
}
MS2_REPLACE_METHOD(0x1422DC1E0, UISwfEntity, FUN_1422dc1e0, 117, 0xAA232E42);

// @0x1422dc260
void UISwfEntity::FUN_1422dc260(int n)
{
    FUN_140b632f0()->FUN_1422d1b20(m_28, m_20, n);
}
MS2_REPLACE_METHOD(0x1422DC260, UISwfEntity, FUN_1422dc260, 66, 0x7BE21F98);

// @0x1422dc2b0
void UISwfEntity::FUN_1422dc2b0(int n)
{
    m_4c = n;
}
MS2_REPLACE_METHOD(0x1422DC2B0, UISwfEntity, FUN_1422dc2b0, 22, 0x4DFF2457);

// @0x1422dc2d0
int UISwfEntity::FUN_1422dc2d0()
{
    return m_4c;
}
MS2_REPLACE_METHOD(0x1422DC2D0, UISwfEntity, FUN_1422dc2d0, 14, 0xAA28048B);

// @0x1422dc2f0
void UISwfEntity::FUN_1422dc2f0(int n)
{
    m_50 = n;
}
MS2_REPLACE_METHOD(0x1422DC2F0, UISwfEntity, FUN_1422dc2f0, 22, 0x55CC0123);

// @0x1422dc310
int UISwfEntity::FUN_1422dc310()
{
    if (FUN_1422db6e0() != s_strNoKey)
        return m_50;
    return 0;
}
MS2_REPLACE_METHOD(0x1422DC310, UISwfEntity, FUN_1422dc310, 87, 0xC22D15C3);

// @0x1422dc370
void UISwfEntity::FUN_1422dc370(int n)
{
    m_54 = n;
}
MS2_REPLACE_METHOD(0x1422DC370, UISwfEntity, FUN_1422dc370, 22, 0x3DC2E0FF);

// @0x1422dc390
int UISwfEntity::FUN_1422dc390()
{
    return m_54;
}
MS2_REPLACE_METHOD(0x1422DC390, UISwfEntity, FUN_1422dc390, 14, 0x5A3CA153);

// @0x1422dc3b0
void UISwfEntity::FUN_1422dc3b0(int n)
{
    m_5c = n;
}
MS2_REPLACE_METHOD(0x1422DC3B0, UISwfEntity, FUN_1422dc3b0, 22, 0x6DD84747);

// @0x1422dc3d0
int UISwfEntity::FUN_1422dc3d0()
{
    return m_5c;
}
MS2_REPLACE_METHOD(0x1422DC3D0, UISwfEntity, FUN_1422dc3d0, 14, 0x8A52079B);

// @0x1422dc410
int UISwfEntity::FUN_1422dc410()
{
    return m_48;
}
MS2_REPLACE_METHOD(0x1422DC410, UISwfEntity, FUN_1422dc410, 14, 0x921EE467);

// @0x1422dc430
int UISwfEntity::FUN_1422dc430()
{
    return m_54;
}
MS2_REPLACE_METHOD(0x1422DC430, UISwfEntity, FUN_1422dc430, 14, 0x5A3CA153);

// @0x1422dc450
void UISwfEntity::FUN_1422dc450()
{
    if (FUN_140e45740()->FUN_1422e6bf0(this, 0))
        FUN_140e45740()->FUN_1422e6d00(0);
    else
        vfunc_43();
    if (m_30.get())
        m_60 = 0;
}
MS2_REPLACE_METHOD(0x1422DC450, UISwfEntity, FUN_1422dc450, 109, 0x311852C0);

// @0x1422dc4d0
void UISwfEntity::vfunc_10()
{
}
MS2_REPLACE_METHOD(0x1422DC4D0, UISwfEntity, vfunc_10, 6, 0xA9AF6E37);

// @0x1422dc4e0
void UISwfEntity::vfunc_11()
{
}
MS2_REPLACE_METHOD(0x1422DC4E0, UISwfEntity, vfunc_11, 6, 0xA9AF6E37);

// @0x1422dc4f0
void UISwfEntity::vfunc_12()
{
}
MS2_REPLACE_METHOD(0x1422DC4F0, UISwfEntity, vfunc_12, 6, 0xA9AF6E37);

// @0x1422dc500
int UISwfEntity::vfunc_13()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1422DC500, UISwfEntity, vfunc_13, 8, 0x7F371472);

// @0x1422dc510
int UISwfEntity::vfunc_14()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1422DC510, UISwfEntity, vfunc_14, 8, 0x7F371472);

// @0x1422dc520
void UISwfEntity::vfunc_15()
{
}
MS2_REPLACE_METHOD(0x1422DC520, UISwfEntity, vfunc_15, 6, 0xA9AF6E37);

// @0x1422dc530
void UISwfEntity::vfunc_16()
{
}
MS2_REPLACE_METHOD(0x1422DC530, UISwfEntity, vfunc_16, 6, 0xA9AF6E37);

// @0x1422dc540
bool UISwfEntity::vfunc_17()
{
    return true;
}
MS2_REPLACE_METHOD(0x1422DC540, UISwfEntity, vfunc_17, 8, 0x71679366);

// @0x1422dc550
void UISwfEntity::vfunc_18()
{
    FUN_1422dc450();
    vfunc_15();
}
MS2_REPLACE_METHOD(0x1422DC550, UISwfEntity, vfunc_18, 40, 0x17E87EC1);

// @0x1422dc580
void UISwfEntity::vfunc_19()
{
    m_60 = 1;
    if (FUN_140e45740()->FUN_1422e6bf0(this, 1))
        FUN_140e45740()->FUN_1422e6d00(1);
    else
        vfunc_43();
    if (m_30.get())
        m_60 = 0;
}
MS2_REPLACE_METHOD(0x1422DC580, UISwfEntity, vfunc_19, 127, 0x1E072301);

// @0x1422dc610
void UISwfEntity::OnLoadInit()
{
}
MS2_REPLACE_METHOD(0x1422DC610, UISwfEntity, OnLoadInit, 6, 0xA9AF6E37);

// @0x1422dc620
void UISwfEntity::vfunc_21()
{
}
MS2_REPLACE_METHOD(0x1422DC620, UISwfEntity, vfunc_21, 6, 0xA9AF6E37);

// @0x1422dc630
void UISwfEntity::OnLoadComplete()
{
    vfunc_8(m_58);
    vfunc_5();
    FUN_1422dc450();
}
MS2_REPLACE_METHOD(0x1422DC630, UISwfEntity, OnLoadComplete, 64, 0xFD16787F);

// @0x1422dc680
void UISwfEntity::vfunc_23(void* p)
{
}
MS2_REPLACE_METHOD(0x1422DC680, UISwfEntity, vfunc_23, 11, 0x02239C70);

// @0x1422dc6a0
void UISwfEntity::vfunc_24(float x, float y)
{
}
MS2_REPLACE_METHOD(0x1422DC6A0, UISwfEntity, vfunc_24, 18, 0x23F7B45B);

// @0x1422dc6c0
void UISwfEntity::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
}
// Not hooked: a thunk would have to copy the by-value TPtr (its copy constructor is not mapped).

// @0x1422dc6f0
void UISwfEntity::vfunc_26()
{
}
MS2_REPLACE_METHOD(0x1422DC6F0, UISwfEntity, vfunc_26, 6, 0xA9AF6E37);

// @0x1422dc700
void UISwfEntity::vfunc_27()
{
}
MS2_REPLACE_METHOD(0x1422DC700, UISwfEntity, vfunc_27, 6, 0xA9AF6E37);

// @0x1422dc710
int UISwfEntity::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return 0;
}
MS2_REPLACE_METHOD(0x1422DC710, UISwfEntity, vfunc_28, 23, 0x192A1B0B);

// @0x1422dc730
void UISwfEntity::vfunc_29(void* p)
{
}
MS2_REPLACE_METHOD(0x1422DC730, UISwfEntity, vfunc_29, 11, 0x02239C70);

// @0x1422dc750
void UISwfEntity::vfunc_30(const CString& a1, const CString& a2, const CString& a3)
{
}
MS2_REPLACE_METHOD(0x1422DC750, UISwfEntity, vfunc_30, 21, 0x3C2C5B86);

// @0x1422dc770
void UISwfEntity::vfunc_31(const CString& a1, float a2, const void* a3)
{
}
MS2_REPLACE_METHOD(0x1422DC770, UISwfEntity, vfunc_31, 22, 0x229954E8);

// @0x1422dc790
int UISwfEntity::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    return 0;
}
MS2_REPLACE_METHOD_VIA(0x1422DC790, UISwfEntity, IMessageListener, OnMessage, 18, 0x4ECEA66C);

// @0x1422dc7b0
void UISwfEntity::vfunc_32(void* p, float x, float y)
{
}
MS2_REPLACE_METHOD(0x1422DC7B0, UISwfEntity, vfunc_32, 23, 0xAB83DBEC);

// @0x1422dc7d0
void UISwfEntity::vfunc_33(void* p, float x, float y)
{
}
MS2_REPLACE_METHOD(0x1422DC7D0, UISwfEntity, vfunc_33, 23, 0xAB83DBEC);

// @0x1422dc7f0
void UISwfEntity::vfunc_34(void* p, float x, float y)
{
}
MS2_REPLACE_METHOD(0x1422DC7F0, UISwfEntity, vfunc_34, 23, 0xAB83DBEC);

// @0x1422dc810
void UISwfEntity::vfunc_35(void* p, float x, float y)
{
}
MS2_REPLACE_METHOD(0x1422DC810, UISwfEntity, vfunc_35, 23, 0xAB83DBEC);

// @0x1422dc830
void UISwfEntity::vfunc_36(void* p, float x, float y)
{
}
MS2_REPLACE_METHOD(0x1422DC830, UISwfEntity, vfunc_36, 23, 0xAB83DBEC);

// @0x1422dc850
void UISwfEntity::vfunc_37(void* p, float x, float y)
{
}
MS2_REPLACE_METHOD(0x1422DC850, UISwfEntity, vfunc_37, 23, 0xAB83DBEC);

// @0x1422dc870
void UISwfEntity::vfunc_38(void* p, float x, float y)
{
}
MS2_REPLACE_METHOD(0x1422DC870, UISwfEntity, vfunc_38, 23, 0xAB83DBEC);

// @0x1422dc890
void UISwfEntity::vfunc_39(void* p, float x, float y, float f)
{
}
MS2_REPLACE_METHOD(0x1422DC890, UISwfEntity, vfunc_39, 23, 0xAB83DBEC);

// @0x1422dc8b0
void UISwfEntity::vfunc_40()
{
}
MS2_REPLACE_METHOD(0x1422DC8B0, UISwfEntity, vfunc_40, 6, 0xA9AF6E37);

// @0x1422dc8c0
void UISwfEntity::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140d01be0(m_28, root);
}
MS2_REPLACE_METHOD(0x1422DC8C0, UISwfEntity, vfunc_41, 99, 0xB253EB49);

// @0x1422dc930
void UISwfEntity::vfunc_42(GfxException* pException)
{
}
MS2_REPLACE_METHOD(0x1422DC930, UISwfEntity, vfunc_42, 11, 0x02239C70);

// @0x1422dc950
void UISwfEntity::vfunc_43()
{
}
MS2_REPLACE_METHOD(0x1422DC950, UISwfEntity, vfunc_43, 6, 0xA9AF6E37);

// @0x1422dc960
void UISwfEntity::vfunc_44(int a1, int a2, int a3, int* pWidth, int* pHeight)
{
    MS2Ptr<ASDisplayObject> pRoot = FUN_1422dba50();
    if (pRoot.get()) {
        pRoot->vfunc_2(a1, a2, a3);
        *pWidth = pRoot->FUN_1422c1340();
        *pHeight = pRoot->FUN_1422c13b0();
    }
}
MS2_REPLACE_METHOD(0x1422DC960, UISwfEntity, vfunc_44, 173, 0xD653F439);

// @0x1422dca20
void UISwfEntity::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
}
MS2_REPLACE_METHOD(0x1422DCA20, UISwfEntity, vfunc_45, 21, 0x3C2C5B86);

// @0x1422dca40
int UISwfEntity::vfunc_46()
{
    if (m_30 == NULL)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1422DCA40, UISwfEntity, vfunc_46, 49, 0xD8622995);
