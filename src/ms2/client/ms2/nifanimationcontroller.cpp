// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\nifanimationcontroller.cpp
// MS2-RANGE: 0x1400fa290-0x1400fa2d0 .text$di
// MS2-RANGE: 0x141544660-0x141545470 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\nifanimationcontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "nifanimationcontroller.h"
#include "hook/ms2hook.h"
#include <NiAVObject.h>
#include <NiMultiTargetTransformController.h>
#include <string.h>
#include <errno.h>
#pragma function(memset, memcpy)

// Unrecovered callees (real types unknown).
void FUN_14097eba0(void* h, int a);
void FUN_1409f7170(void* h, int a);
void FUN_140b85910(void* h, int a);
void FUN_140d9ddf0(void* h, int a);
void FUN_1409fabf0(void* h, int a);
void FUN_1409f76f0(void* h, void* v);
void FUN_140b85cd0(void* h, void* v);
void FUN_140af6d60(void* h, void* v);
void FUN_14097f710(void* h, void* v);
void FUN_140d9e050(void* h);
void FUN_1409f74b0(void* h);
void FUN_140b85b20(void* h);
void FUN_1405a85c0(void* h);
void* FUN_140a0afd0();
void* FUN_141551ea0(void* svc, void* out, CStringA s, int a, int b, int c, int d);
bool FUN_140af72f0(void* h, int a);
bool FUN_140b85fc0(void* h, int a);
void* FUN_14098d0f0(void* h);
void* FUN_140a33f90(void* obj);
void* FUN_14098d8d0(const void* rtti, void* obj);
void* FUN_1409475d0(void* h);
void* FUN_1409475f0(void* h);
void* FUN_140e68fd0(void* h);
void* FUN_1409478e0(void* o);
void* FUN_14098dc80(void* o);
void* FUN_14098de40(void* o);
void FUN_14098e870(void* o, int v);
float FUN_140af7f50(void* o);
int FUN_140af7db0(void* o);
void FUN_14098cb80(void* it, void* o);
void* FUN_14098e0d0(void* it, int a);
void FUN_14098cf00(void* it);
void FUN_140aacb60(void* node, void* xf);
void FUN_142083d40(void* m, float x, float y, float z);
void FUN_142085840(void* m, float* x, float* y, float* z);
void FUN_141d16040(void* o, float t, bool b);
char FUN_14098df90(const void* rtti, void* o);
void* FUN_14127cc40(void* o);
void* FUN_14098ddb0(void* o);
void* FUN_14098de00(void* o, void** it);
void* FUN_140993f00(void* o);
unsigned int FUN_14098daf0(void* o);
void* FUN_14098db40(void* o, unsigned int i);
void* FUN_1413f98b0();
void* FUN_1409670f0();
void* FUN_1411cf440(void* a, void* id);
void* FUN_141fff400(void* svc, void* ent);   // ecr::SceneGraphService::GetSceneGraphFromEntity
void FUN_141d24c70(void* o);
void FUN_141d24a50(void* o);
extern char DAT_143af8a00;
extern char DAT_143af89f0;
extern char DAT_143afa950;
extern char DAT_143afa458;
extern char DAT_143b01a60;

// @0x1400fa290
const NiRTTI CNifAnimationController::ms_RTTI("CNifAnimationController", 0);

// @0x1400fa2b0 (static initialised by FUN_1401cd100(&DAT_143ae1a28, 0); zero-initialised handle)
void FUN_1401cd100(void* h, int a);
static void* s_dat_143ae1a28;
static int s_dat_143ae1a28_init = (FUN_1401cd100(&s_dat_143ae1a28, 0), 0);

// @0x141544660
CNifAnimationController::CNifAnimationController()
{
    FUN_14097eba0(&m_10, 0);
    FUN_1409f7170(&m_18, 0);
    FUN_140b85910(&m_20, 0);
    FUN_1409f7170(&m_28, 0);
    FUN_140d9ddf0(&m_30, 0);
    memcpy(&m_38, &DAT_143b01a60, 12);
    memcpy(&m_44, &DAT_143b01a60, 12);
    m_58 = 0;
}

// @0x141544750
CNifAnimationController::~CNifAnimationController()
{
    FUN_1409fabf0(&m_10, 0);
    FUN_1409f76f0(&m_18, 0);
    FUN_140b85cd0(&m_20, 0);
    FUN_140af6d60(&m_30, 0);
    FUN_1409f76f0(&m_28, 0);
    FUN_140d9e050(&m_30);
    FUN_1409f74b0(&m_28);
    FUN_140b85b20(&m_20);
    FUN_1409f74b0(&m_18);
    FUN_1405a85c0(&m_10);
}

// @0x141545340
const NiRTTI* CNifAnimationController::GetRTTI() const { return &ms_RTTI; }

// @0x141544850
// MS2-FUNCTIONAL: opaque handle helpers and local transform temp layout not matched exactly
bool CNifAnimationController::FUN_141544850(int mode, CStringA name, float* euler)
{
    m_58 = mode;
    if (m_58 == 0) {
        void* svc = FUN_140a0afd0();
        char tmp[8];
        void* h = FUN_141551ea0(svc, tmp, name, 0, 5, 0, 0);
        FUN_14097f710(&m_10, h);
        FUN_1405a85c0(tmp);
        if (FUN_140af72f0(&m_10, 0)) {
            char xf[0x34];
            memcpy(xf, FUN_140a33f90(FUN_14098d0f0(&m_10)), 0x34);
            FUN_142083d40(xf, (-euler[0] * 3.1415927f) / 180.0f, (-euler[1] * 3.1415927f) / 180.0f, (-euler[2] * 3.1415927f) / 180.0f);
            FUN_140aacb60(FUN_14098d0f0(&m_10), xf);
            NiFixedString dummy("Dummy01");
            void* root = FUN_14098d0f0(&m_10);
            void* d = static_cast<NiAVObject*>(root)->GetObjectByName(dummy);
            FUN_1409f76f0(&m_18, FUN_14098d8d0(&NiNode::ms_RTTI, d));
        }
        // dummy dtor via scope end
        if (FUN_1409475d0(&m_18) != 0) {
            for (void* c = FUN_14098dc80(FUN_1409475f0(&m_18)); c != 0; c = FUN_14098de40(c)) {
                float t = FUN_140af7f50(c);
                if (m_54 < t)
                    m_54 = FUN_140af7f50(c);
                NiMultiTargetTransformController* mt = (NiMultiTargetTransformController*)FUN_14098d8d0(&DAT_143af8a00, c);
                if (mt != 0 && FUN_140b85fc0(&m_20, 0)) {
                    for (unsigned short i = 0;; ++i) {
                        unsigned short n = mt->GetInterpolatorCount();
                        if ((int)i >= (int)n)
                            break;
                        void* tg = mt->GetInterpolator(i);
                        FUN_140b85cd0(&m_20, FUN_14098d8d0(&DAT_143af89f0, tg));
                        if (FUN_140b85fc0(&m_20, 0))
                            break;
                    }
                }
            }
        }
    } else if (m_58 == 1) {
        void* svc = FUN_140a0afd0();
        char tmp[8];
        void* h = FUN_141551ea0(svc, tmp, name, 0, 5, 0, 0);
        FUN_14097f710(&m_10, h);
        FUN_1405a85c0(tmp);
        if (FUN_140af72f0(&m_10, 0)) {
            NiFixedString cam("Camera01");
            void* root = FUN_14098d0f0(&m_10);
            void* d = static_cast<NiAVObject*>(root)->GetObjectByName(cam);
            FUN_1409f76f0(&m_28, FUN_14098d8d0(&NiNode::ms_RTTI, d));
            char it[0x30];
            FUN_14098cb80(it, FUN_1409475d0(&m_28));
            void* n;
            while ((n = FUN_14098e0d0(it, 1)) != 0) {
                void* c = FUN_14098dc80(n);
                while (c != 0 && FUN_140af7db0(c) == 1) {
                    FUN_14098e870(c, 0);
                    c = FUN_14098de40(c);
                }
                FUN_140af6d60(&m_30, FUN_14098d8d0(&DAT_143afa950, n));
            }
            FUN_14098cf00(it);
        }
    }
    return true;
}

// @0x141544ec0
void CNifAnimationController::FUN_141544ec0(float time)
{
    if (m_58 == 1) {
        FUN_141d16040(FUN_1409475f0(&m_28), time, true);
        void* xf = FUN_140a33f90(FUN_1409475f0(&m_28));
        ((Vector3*)&m_38)->operator=(*(Vector3*)((char*)xf + 0x24));
        float* e = (float*)&m_44;
        FUN_142085840(FUN_1409478e0(FUN_140e68fd0(&m_30)), &e[0], &e[1], &e[2]);
        e[0] = -((e[0] * 180.0f) / 3.1415927f);
        e[1] = -((e[1] * 180.0f) / 3.1415927f);
        e[2] = -((e[2] * 180.0f) / 3.1415927f);
    }
}

// @0x141545020
Unk_NACRaw12* CNifAnimationController::FUN_141545020(Unk_NACRaw12* out) { *out = m_38; return out; }

// @0x141545050
Unk_NACRaw12* CNifAnimationController::FUN_141545050(Unk_NACRaw12* out) { *out = m_44; return out; }

// @0x141545080
void FUN_141545080(int value, void* node)
{
    for (void* c = FUN_14098dc80(node); c != 0; c = FUN_14098de40(c))
        FUN_14098e870(c, value);
    if (FUN_14098df90(&DAT_143afa458, node)) {
        void* it = FUN_14098ddb0(FUN_14127cc40(node));
        while (it != 0) {
            void* ch = FUN_140993f00(FUN_14098de00(FUN_14127cc40(node), &it));
            if (ch != 0 && FUN_14098dc80(ch) != 0)
                FUN_141545080(value, ch);
        }
    }
    if (FUN_14098df90(&NiNode::ms_RTTI, node)) {
        for (unsigned int i = 0; i < FUN_14098daf0(node); ++i) {
            void* ch = FUN_14098db40(node, i);
            if (ch != 0)
                FUN_141545080(value, ch);
        }
    }
}

// @0x1415451d0
void FUN_1415451d0(int value, void* entityId)
{
    void* sg = FUN_1413f98b0();
    if (sg != 0) {
        void* ent = FUN_1411cf440(FUN_1409670f0(), entityId);
        if (ent != 0) {
            void* n = FUN_141fff400(sg, ent);
            if (n != 0)
                FUN_141545080(value, n);
        }
    }
}

// @0x141545250
void FUN_141545250(void* entityId, int mode)
{
    void* sg = FUN_1413f98b0();
    if (sg != 0) {
        void* ent = FUN_1411cf440(FUN_1409670f0(), entityId);
        if (ent != 0) {
            void* n = FUN_141fff400(sg, ent);
            if (n != 0) {
                if (mode == 0)
                    FUN_141d24c70(n);
                else
                    FUN_141d24a50(n);
            }
        }
    }
}

// @0x141545350 (memmove_s)
unsigned __int64 FUN_141545350(void* dst, unsigned __int64 dstSize, void* src, unsigned __int64 n)
{
    if (n == 0)
        return 0;
    if (dst == 0) { *_errno() = 22; _invalid_parameter_noinfo(); return 22; }
    if (src == 0) { *_errno() = 22; _invalid_parameter_noinfo(); return 22; }
    if (dstSize < n) { *_errno() = 34; _invalid_parameter_noinfo(); return 34; }
    memmove(dst, src, n);
    return 0;
}
