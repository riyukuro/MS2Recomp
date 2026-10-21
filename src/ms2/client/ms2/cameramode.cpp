// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See cameramode.h.
// MS2-UNIT: ?\cameramode.cpp
// MS2-RANGE: 0x140afd490-0x140afe800 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "cameramode.h"
#include "ms2cameraservice.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ecrcameraservice.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

// The engine-side actor of the camera target (CCameraMode::vfunc_6).
class Unk_UpperActor
{
public:
    void FUN_1416781a0(int nMode);
};
Unk_UpperActor* FUN_1409ffd30(void* p);

// An entry of the list at 0x143afa980->+0x190 (vfunc_6 tells each one whether the mode is a free camera).
class Unk_CameraListEntry
{
public:
    // @0x140afe780
    void FUN_140afe780(bool b)
    {
        if (b)
            m_a4 = 0.5f;
        else
            m_a4 = 1.0f;
    }

    char m_pad_00[0xa4];
    float m_a4;
};

struct Unk_CameraListEntryPtr
{
    // @0x140afe6c0
    Unk_CameraListEntry* operator->() const { return m_p; }
    Unk_CameraListEntry* m_p;
};

// The game's intrusive list (MFC CList-like layout: something at +0, the head at +0x08; node: next +0x00, prev +0x08,
// element +0x10). Not MFC CList: its GetNext takes the element address before advancing.
template <class T> class Unk_TList
{
public:
    struct Node
    {
        Node* pNext;
        Node* pPrev;
        T data;
    };
    // @0x140afe720
    POSITION FUN_140afe720() const { return (POSITION)m_pHead; }
    // @0x140afe730
    T& FUN_140afe730(POSITION& pos)
    {
        T& r = ((Node*)pos)->data;
        pos = (POSITION)((Node*)pos)->pNext;
        return r;
    }

    void* m_pad_00;
    Node* m_pHead;                      // +0x08
};
typedef Unk_TList<Unk_CameraListEntryPtr> Unk_CameraList;

class Unk_CameraListOwner
{
public:
    // @0x140afe770
    static Unk_CameraList* FUN_140afe770() { return &s_pInstance->m_list; }

    char m_pad_000[0x190];
    Unk_CameraList m_list;              // +0x190

    static Unk_CameraListOwner* s_pInstance;            // 0x143afa980
};

int FUN_140ae8540();                                    // reloads the camera xml (returns 0 on failure)
Unk_CameraTarget* FUN_1413f98d0();
bool FUN_14028d470(float a, float b);                   // a == b (within epsilon)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140afd490
CCameraMode::CCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : m_pOwner(pOwner)
{
    m_70 = 1.0f;
    FUN_140afdaa0(pPrev);
}

// @0x140afd540
CCameraMode::~CCameraMode()
{
}

// @0x140afd570
void CCameraMode::vfunc_3(Unk_StreamPoint pt)
{
    m_setting.m_c = pt;
    m_pOwner->FUN_140a38dc0(pt);
}
MS2_REPLACE_METHOD(0x140afd570, CCameraMode, vfunc_3, 84, 0xFD1CE8FB);

// @0x140afd5d0
void CCameraMode::vfunc_4(Unk_StreamPoint pt)
{
    m_setting.m_18 = pt;
    m_pOwner->FUN_140a38e00(pt);
}
MS2_REPLACE_METHOD(0x140afd5d0, CCameraMode, vfunc_4, 84, 0xE2149114);

// @0x140afd630
void CCameraMode::vfunc_5(bool b)
{
    m_setting.m_24 = b;
    m_pOwner->FUN_140afe7c0(b);
}
MS2_REPLACE_METHOD(0x140afd630, CCameraMode, vfunc_5, 50, 0x7C24943E);

// @0x140afd670
void CCameraMode::vfunc_6(int n)
{
    Unk_UpperActor* pActor = FUN_1409ffd30(Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60());
    if (pActor)
        pActor->FUN_1416781a0(vfunc_1());
    Unk_CameraList* pList = Unk_CameraListOwner::FUN_140afe770();
    POSITION pos = pList->FUN_140afe720();
    while (pos)
    {
        Unk_CameraListEntry* pEntry = pList->FUN_140afe730(pos).operator->();
        pEntry->FUN_140afe780(!vfunc_2());
    }
}
MS2_REPLACE_METHOD(0x140afd670, CCameraMode, vfunc_6, 193, 0x09C1CC62);

// @0x140afd740
void CCameraMode::vfunc_7()
{
}

// @0x140afd750
void CCameraMode::vfunc_8(double fTime)
{
}

// @0x140afd770
void CCameraMode::vfunc_9()
{
}

// @0x140afd780
void CCameraMode::vfunc_10()
{
}

// @0x140afd790
void CCameraMode::vfunc_11(float f)
{
    if (!FUN_14028d470(m_setting.m_0, f))
    {
        m_setting.m_0 = f;
        m_pOwner->FUN_140947940(f);
    }
}
MS2_REPLACE_METHOD(0x140afd790, CCameraMode, vfunc_11, 84, 0x5579240C);

// @0x140afd7f0
void CCameraMode::vfunc_12(float fDegree)
{
    m_48 = fDegree * 3.14159265f / 180.0f + 3.14159265f;
}
MS2_REPLACE_METHOD(0x140afd7f0, CCameraMode, vfunc_12, 52, 0x81BC0419);

// @0x140afd830
void CCameraMode::vfunc_13(float fDegree)
{
    m_4c = fDegree * 3.14159265f / 180.0f;
}
MS2_REPLACE_METHOD(0x140afd830, CCameraMode, vfunc_13, 44, 0xFD3AACF7);

// @0x140afd870
void CCameraMode::vfunc_14(float f)
{
    m_58 = f;
}

// @0x140afd8a0
float CCameraMode::vfunc_15()
{
    return m_58;
}

// @0x140afd8c0
void CCameraMode::vfunc_16(float f)
{
    m_54 = f;
}

// @0x140afd8f0
float CCameraMode::vfunc_17()
{
    return m_54;
}

// @0x140afd910
void CCameraMode::vfunc_18(float f1, float f2)
{
    m_60 = f1;
    m_64 = f2;
}

// @0x140afd950
float CCameraMode::vfunc_19()
{
    return m_50;
}

// @0x140afd970
void CCameraMode::vfunc_20(float f)
{
    m_50 = f;
}

// @0x140afd9a0
void CCameraMode::vfunc_21(float f, int n)
{
    m_5c = f;
}

// @0x140afd9d0
float CCameraMode::vfunc_22()
{
    return 0.0f;
}

// @0x140afd9e0
float CCameraMode::vfunc_23()
{
    return 0.0f;
}

// @0x140afd9f0
void CCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
}

// @0x140afda10
Unk_CameraTargetEntity* CCameraMode::vfunc_25()
{
    return 0;
}

// @0x140afda20
Unk_StreamPoint CCameraMode::vfunc_26()
{
    return FUN_1409f2540();
}

// @0x140afda50
float CCameraMode::vfunc_27()
{
    return 0.0f;
}

// @0x140afda60
int CCameraMode::vfunc_28()
{
    return 1;
}

// @0x140afda80
void CCameraMode::vfunc_29(float f1, float f2, float f3)
{
}

// @0x140afdaa0
void CCameraMode::FUN_140afdaa0(MS2Ptr<CCameraMode> pPrev)
{
    if (pPrev.get())
    {
        m_setting = pPrev->m_setting;
        m_48 = pPrev->m_48;
        m_4c = pPrev->m_4c;
        m_50 = pPrev->m_50;
        m_54 = pPrev->m_54;
        m_58 = pPrev->m_58;
        m_68 = pPrev->m_68;
        m_6c = pPrev->m_6c;
        m_60 = pPrev->m_60;
        m_64 = pPrev->m_64;
        m_5c = pPrev->m_5c;
    }
    else
    {
        m_48 = 3.92699082f;
        m_4c = 0.698131740f;
        m_50 = 1200.0f;
        m_54 = 1200.0f;
        m_58 = 400.0f;
        m_68 = 0.785398185f;
        m_6c = 0.872664630f;
        m_60 = 60.0f;
        m_64 = 95.0f;
        m_5c = -1.0f;
        m_setting.m_0 = 40.0f;
        m_setting.m_4 = 250.0f;
        m_setting.m_8 = 18000.0f;
        m_setting.m_c = g_143b01a60;
        m_setting.m_18 = g_143b01a60;
        m_setting.m_18.x += 90.0f;
    }
}
MS2_REPLACE_METHOD(0x140afdaa0, CCameraMode, FUN_140afdaa0, 653, 0xB7F15223);

// @0x140afdd40
Unk_StreamPoint CCameraMode::FUN_140afdd40(const Unk_StreamPoint& ptEye, const Unk_StreamPoint& ptAt,
                                           const Unk_StreamPoint& ptUp)
{
    Unk_StreamPoint dir = ptEye.FUN_140965c40(ptAt);
    dir.FUN_140968990();
    Unk_StreamPoint right = dir.FUN_140a00e10(ptUp);
    right.FUN_140968990();
    Unk_StreamPoint up = right.FUN_140a00e10(dir);
    Unk_NiMatrix3 m(dir, up, right);
    Unk_StreamPoint angles;
    m.FUN_142085840(angles.x, angles.y, angles.z);
    angles.x *= -57.2957764f;
    angles.y *= -57.2957764f;
    angles.z *= -57.2957764f;
    return angles;
}
MS2_REPLACE(0x140afdd40, CCameraMode::FUN_140afdd40, 364, 0xA788D22D);

// @0x140afdec0
Unk_StreamPoint CCameraMode::FUN_140afdec0(float t, const Unk_StreamPoint& a, const Unk_StreamPoint& b)
{
    Unk_StreamPoint a0, a1;
    Unk_NiMatrix3 ma;
    ma.FUN_142083d40(a.x * -0.0174532924f, a.y * -0.0174532924f, a.z * -0.0174532924f);
    ma.FUN_140a01190(0, a0);
    ma.FUN_140a01190(1, a1);
    Unk_StreamPoint b0, b1;
    Unk_NiMatrix3 mb;
    mb.FUN_142083d40(b.x * -0.0174532924f, b.y * -0.0174532924f, b.z * -0.0174532924f);
    mb.FUN_140a01190(0, b0);
    mb.FUN_140a01190(1, b1);
    Unk_StreamPoint c0, c1;
    c0 = a0.FUN_14097fd50(FUN_1409ab5c0(t, b0.FUN_140965c40(a0)));
    c0.FUN_140968990();
    c1 = a1.FUN_14097fd50(FUN_1409ab5c0(t, b1.FUN_140965c40(a1)));
    c1.FUN_140968990();
    Unk_StreamPoint c2 = c0.FUN_140a00e10(c1);
    c2.FUN_140968990();
    c1 = c2.FUN_140a00e10(c0);
    c1.FUN_140968990();
    Unk_StreamPoint angles;
    Unk_NiMatrix3 m(c0, c1, c2);
    m.FUN_142085840(angles.x, angles.y, angles.z);
    angles.x *= -57.2957764f;
    angles.y *= -57.2957764f;
    angles.z *= -57.2957764f;
    return angles;
}
MS2_REPLACE(0x140afdec0, CCameraMode::FUN_140afdec0, 936, 0x6D68000D);

// @0x140afe270
void CCameraMode::FUN_140afe270(float f, bool bApply)
{
    m_70 = f;
    if (bApply)
        FUN_140afe4b0();
}
MS2_REPLACE_METHOD(0x140afe270, CCameraMode, FUN_140afe270, 60, 0x4C2590A6);

// @0x140afe2c0
BOOL CCameraMode::vfunc_31()
{
    return FUN_140ae8540();
}
MS2_REPLACE_METHOD(0x140afe2c0, CCameraMode, vfunc_31, 19, 0x6704C278);

// @0x140afe2e0
float CCameraMode::FUN_140afe2e0()
{
    return m_6c;
}

// @0x140afe300
float CCameraMode::FUN_140afe300()
{
    return m_68;
}

// @0x140afe320
void CCameraMode::vfunc_32(float f)
{
    m_68 = f;
}

// @0x140afe350
void CCameraMode::vfunc_33()
{
}

// @0x140afe360
Unk_StreamPoint CCameraMode::vfunc_35()
{
    Unk_StreamPoint pt(0.0f, 0.0f, 0.0f);
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pTarget)
    {
        pt = pTarget->vfunc_17();
        pt.z += vfunc_27();
    }
    return pt;
}
MS2_REPLACE_METHOD(0x140afe360, CCameraMode, vfunc_35, 168, 0x05D23C7F);

// @0x140afe410
void CCameraMode::vfunc_36(Unk_CameraPreset* pPreset)
{
    if (pPreset)
    {
        vfunc_16(pPreset->m_1c);
        vfunc_12(pPreset->m_24);
        vfunc_13(pPreset->m_20);
        vfunc_18(pPreset->m_28, pPreset->m_2c);
    }
}
MS2_REPLACE_METHOD(0x140afe410, CCameraMode, vfunc_36, 147, 0x12A9C619);

// @0x140afe4b0
void CCameraMode::FUN_140afe4b0()
{
    efd::SmartPointer<ecr::CameraService> spCamera = g_143b059e8.GetSystemServiceAs<ecr::CameraService>();
    if (spCamera)
    {
        Unk_CameraTarget* pTarget = FUN_1413f98d0();
        if (pTarget)
        {
            ecr::CameraData* pCamera = FUN_14200aae0(spCamera.operator->(), pTarget);
            if (pCamera)
            {
                pCamera->SetZoomFactor(m_70);
                static_cast<MS2CameraService*>(spCamera.operator->())->FUN_1414af480(pCamera);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140afe4b0, CCameraMode, FUN_140afe4b0, 172, 0xD091821F);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x140afd740, CCameraMode, vfunc_7, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x140afd750, CCameraMode, vfunc_8, 12, 0x49415BA5);
MS2_REPLACE_METHOD(0x140afd770, CCameraMode, vfunc_9, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x140afd780, CCameraMode, vfunc_10, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x140afd870, CCameraMode, vfunc_14, 28, 0x4790B6C2);
MS2_REPLACE_METHOD(0x140afd8a0, CCameraMode, vfunc_15, 16, 0x3BBB249E);
MS2_REPLACE_METHOD(0x140afd8c0, CCameraMode, vfunc_16, 28, 0xDF9C3366);
MS2_REPLACE_METHOD(0x140afd8f0, CCameraMode, vfunc_17, 16, 0x03D8E18A);
MS2_REPLACE_METHOD(0x140afd910, CCameraMode, vfunc_18, 50, 0xA38AFCCF);
MS2_REPLACE_METHOD(0x140afd950, CCameraMode, vfunc_19, 16, 0xEBCFC166);
MS2_REPLACE_METHOD(0x140afd970, CCameraMode, vfunc_20, 28, 0xF7A5538A);
MS2_REPLACE_METHOD(0x140afd9a0, CCameraMode, vfunc_21, 33, 0xC5D18E21);
MS2_REPLACE_METHOD(0x140afd9d0, CCameraMode, vfunc_22, 9, 0x4FE1E1A5);
MS2_REPLACE_METHOD(0x140afd9e0, CCameraMode, vfunc_23, 9, 0x4FE1E1A5);
MS2_REPLACE_METHOD(0x140afd9f0, CCameraMode, vfunc_24, 16, 0x661BAEE5);
MS2_REPLACE_METHOD(0x140afda10, CCameraMode, vfunc_25, 8, 0x7F371472);
MS2_REPLACE_METHOD(0x140afda50, CCameraMode, vfunc_27, 9, 0x4FE1E1A5);
MS2_REPLACE_METHOD(0x140afda60, CCameraMode, vfunc_28, 11, 0x30025ED0);
MS2_REPLACE_METHOD(0x140afda80, CCameraMode, vfunc_29, 24, 0x905D2B1C);
MS2_REPLACE_METHOD(0x140afe2e0, CCameraMode, FUN_140afe2e0, 16, 0x33EB21D2);
MS2_REPLACE_METHOD(0x140afe300, CCameraMode, FUN_140afe300, 16, 0x1BE201AE);
MS2_REPLACE_METHOD(0x140afe320, CCameraMode, vfunc_32, 28, 0x27B793D2);
MS2_REPLACE_METHOD(0x140afe350, CCameraMode, vfunc_33, 6, 0xA9AF6E37);

