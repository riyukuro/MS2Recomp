// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PathEngine glue: cPhysXTriangleMeshWrapper (PhysX triangle mesh as an iFaceVertexMesh).
// MS2-UNIT: unit_14164c5a0
// MS2-RANGE: 0x14164c5a0-0x14164cc70 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\cphysxtrianglemeshwrapper.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <new>

// Unrecovered neighbours (unit_141649870: std::vector<int> instances used by the PathEngine glue, iFaceVertexMesh).
struct Unk_IntVec { void* first; void* last; void* end; Unk_IntVec(); ~Unk_IntVec(); };   // ctor 0x14164b170, dtor 0x141639340 (vector<int> instance)
class iFaceVertexMesh {
public:
    iFaceVertexMesh();                            // 0x14164b1e0
    virtual ~iFaceVertexMesh();                   // 0x14164b2a0 (scalar deleting 0x14164b820)
    virtual unsigned __int64 vfunc_1() = 0;
    virtual unsigned __int64 vfunc_2() = 0;
    virtual int vfunc_3(int, int) = 0;
    virtual int vfunc_4(int) = 0;
    virtual int vfunc_5(int) = 0;
    virtual float vfunc_6(int) = 0;
    virtual int vfunc_7(int, int) = 0;
};
void FUN_14164c450(Unk_IntVec*, unsigned __int64);// vector<int>::reserve
void FUN_14164c370(Unk_IntVec*, int*);            // vector<int>::push_back
unsigned __int64 FUN_14164c550(Unk_IntVec*);      // vector<int>::size
int* FUN_14164b420(Unk_IntVec*, __int64);         // vector<int>::operator[]
int* FUN_1416393a0(Unk_IntVec*, __int64);         // vector<int>::operator[] (second instance)
class cCoordinateMapping   // C3: member view for the former free stand-ins
{
public:
    void applyTo(long*) const;
};
int FUN_140291d90(float);                         // float -> int

struct Unk_MeshVec3 { float x, y, z; Unk_MeshVec3(); };   // ctor 0x140a003a0
struct Unk_MeshAux { int i0, i1, i2, i3, i4, i5, i6; };
void FUN_140adbea0(Unk_MeshAux*, float);   // ctor of the aux part
struct Unk_MeshXform { int i0, i1, i2, i3, i4, i5, i6, i7, i8, j0, j1, j2, j3, j4, j5, j6; ~Unk_MeshXform(); };   // aux part at j0   // dtor 0x140adbb80
void FUN_141639400(Unk_MeshXform*, float);
class NxMat34   // C3: member view for the former free stand-ins
{
public:
    void multiply(class NxVec3 const&, class NxVec3&) const;
};

struct Unk_MeshDesc {
    int nVerts;
    int nTris;
    unsigned vStride;
    unsigned tStride;
    const char* verts;
    const char* tris;
    unsigned flags;
    int pad;
    unsigned __int64 q0, q1, q2, q3, q4;
    Unk_MeshDesc();   // 0x1416453a0
};

struct Unk_MeshData {
    virtual void Fill(Unk_MeshDesc*);
};
struct Unk_MeshSource {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual Unk_MeshXform GetXform();   // slot 16
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual Unk_MeshData* GetMesh();         // slot 40
};

struct Unk_Tri16 { unsigned short v[3]; };
struct Unk_Tri32 { unsigned v[3]; };

class cPhysXTriangleMeshWrapper : public iFaceVertexMesh {
public:
    cPhysXTriangleMeshWrapper(Unk_MeshSource* src, int* axisMap, float scale);
    virtual unsigned __int64 vfunc_1();
    virtual unsigned __int64 vfunc_2();
    virtual int vfunc_3(int tri, int k);
    virtual int vfunc_4(int tri);
    virtual int vfunc_5(int tri);
    virtual float vfunc_6(int tri);
    virtual int vfunc_7(int, int what);
    void SetFlag(bool f);
    Unk_IntVec verts;   // 0x08
    Unk_IntVec tris;    // 0x20
    bool flag;          // 0x38
};
MS2_CHECK_SIZE(cPhysXTriangleMeshWrapper, 0x40);

// MS2-FUNCTIONAL: stack layout differs (the exe keeps the 0x24-byte transform and its 0x1c-byte aux at 0xe8/0x10c; MSVC aligns our copies differently, +0x10 frame)
// @0x14164c5a0
cPhysXTriangleMeshWrapper::cPhysXTriangleMeshWrapper(Unk_MeshSource* src, int* axisMap, float scale) {
    Unk_MeshXform xf = src->GetXform();
    FUN_141639400(&xf, scale);
    FUN_140adbea0(reinterpret_cast<Unk_MeshAux*>(&xf.j0), scale);
    Unk_MeshData* mesh = src->GetMesh();
    Unk_MeshDesc d;
    mesh->Fill(&d);
    FUN_14164c450(&verts, (unsigned)(d.nVerts * 3));
    int i;
    const char* p = d.verts;
    for (i = 0; i != d.nVerts; ++i) {
        const char* cur = p;
        Unk_MeshVec3 v;
            ((class NxMat34*)(struct Unk_MeshXform*)(&xf))->multiply(*(class NxVec3 const*)(cur), *(class NxVec3*)(&v));
        int a = FUN_140291d90(v.x);
        FUN_14164c370(&verts, &a);
        int b = FUN_140291d90(v.y);
        FUN_14164c370(&verts, &b);
        int c = FUN_140291d90(v.z);
        FUN_14164c370(&verts, &c);
        p += d.vStride;
    }
    for (i = 0; i != d.nVerts; ++i)
        ((class cCoordinateMapping*)(int*)(axisMap))->applyTo((long*)(FUN_1416393a0(&verts, (__int64)(i * 3))));
    FUN_14164c450(&tris, (unsigned)(d.nTris * 3));
    p = d.tris;
    if ((d.flags & 2) != 0) {
        for (i = 0; i != d.nTris; ++i) {
            const Unk_Tri16* t = (const Unk_Tri16*)p;
            int a = t->v[0];
            FUN_14164c370(&tris, &a);
            int b = t->v[2];
            FUN_14164c370(&tris, &b);
            int c = t->v[1];
            FUN_14164c370(&tris, &c);
            p += d.tStride;
        }
    } else {
        for (i = 0; i != d.nTris; ++i) {
            const Unk_Tri32* t = (const Unk_Tri32*)p;
            int a = t->v[0];
            FUN_14164c370(&tris, &a);
            int b = t->v[2];
            FUN_14164c370(&tris, &b);
            int c = t->v[1];
            FUN_14164c370(&tris, &c);
            p += d.tStride;
        }
    }
    flag = false;
}

// @0x14164ca30
unsigned __int64 cPhysXTriangleMeshWrapper::vfunc_1() { return FUN_14164c550(&tris) / 3; }
// @0x14164ca60
unsigned __int64 cPhysXTriangleMeshWrapper::vfunc_2() { return FUN_14164c550(&verts) / 3; }
// @0x14164ca90
int cPhysXTriangleMeshWrapper::vfunc_3(int tri, int k) { return *FUN_14164b420(&tris, (__int64)(tri * 3 + k)); }
// @0x14164cad0
int cPhysXTriangleMeshWrapper::vfunc_4(int tri) { return *FUN_14164b420(&verts, (__int64)(tri * 3)); }
// @0x14164cb10
int cPhysXTriangleMeshWrapper::vfunc_5(int tri) { return *FUN_14164b420(&verts, (__int64)(tri * 3 + 1)); }
// @0x14164cb50
float cPhysXTriangleMeshWrapper::vfunc_6(int tri) { return (float)*FUN_14164b420(&verts, (__int64)(tri * 3 + 2)); }
// @0x14164cb90
int cPhysXTriangleMeshWrapper::vfunc_7(int, int what) {
    if (what == 2 && flag) return 1;
    return -1;
}
// @0x14164cbd0
void cPhysXTriangleMeshWrapper::SetFlag(bool f) { flag = f; }
// @0x14164cbf0 implicit ~cPhysXTriangleMeshWrapper
