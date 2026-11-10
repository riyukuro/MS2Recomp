// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PathEngine glue: cPhysXTriangleMeshWrapper (PhysX triangle mesh as an iFaceVertexMesh).
// MS2-UNIT: unit_14164c5a0
// MS2-RANGE: 0x14164c5a0-0x14164cc70 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\cphysxtrianglemeshwrapper.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <new>
#include <vector>

// Unrecovered neighbours (unit_141649870: iFaceVertexMesh).
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
class cCoordinateMapping   // C3: member view for the former free stand-ins
{
public:
    void applyTo(long*) const;
};
int RoundToInt(float);                         // float -> int

class NxVec3
{
public:
    NxVec3();                                     // 0x140a003a0
    NxVec3& operator*=(float f);                  // 0x140adbea0
    float x, y, z;
};
class NxMat33
{
public:
    const NxMat33& operator*=(float f);           // 0x141639400
};
class NxMat34
{
public:
    ~NxMat34();                                   // 0x140adbb80
    void multiply(NxVec3 const&, NxVec3&) const;
    int i0, i1, i2, i3, i4, i5, i6, i7, i8, j0, j1, j2;   // M (3x3), then t at j0
};

class NxTriangleMeshDesc {
public:
    int nVerts;
    int nTris;
    unsigned vStride;
    unsigned tStride;
    const char* verts;
    const char* tris;
    unsigned flags;
    int pad;
    unsigned __int64 q0, q1, q2, q3, q4;
    NxTriangleMeshDesc();   // 0x1416453a0
};

struct Unk_MeshData {
    virtual void Fill(NxTriangleMeshDesc*);
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
    virtual NxMat34 GetXform();   // slot 16
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

class NxTriangleMeshShape;

struct Unk_Tri16 { unsigned short v[3]; };
struct Unk_Tri32 { unsigned v[3]; };

class cPhysXTriangleMeshWrapper : public iFaceVertexMesh {
public:
    cPhysXTriangleMeshWrapper(const NxTriangleMeshShape& source, const cCoordinateMapping& mapping, float scale);
    virtual unsigned __int64 vfunc_1();
    virtual unsigned __int64 vfunc_2();
    virtual int vfunc_3(int tri, int k);
    virtual int vfunc_4(int tri);
    virtual int vfunc_5(int tri);
    virtual float vfunc_6(int tri);
    virtual int vfunc_7(int, int what);
    void SetFlag(bool f);
    std::vector<long> verts;   // 0x08
    std::vector<long> tris;    // 0x20
    bool flag;          // 0x38
};
MS2_CHECK_SIZE(cPhysXTriangleMeshWrapper, 0x40);

// @0x14164c5a0
cPhysXTriangleMeshWrapper::cPhysXTriangleMeshWrapper(const NxTriangleMeshShape& source, const cCoordinateMapping& mapping, float scale) {
    NxMat34 xf = ((Unk_MeshSource*)&source)->GetXform();
    *reinterpret_cast<NxMat33*>(&xf) *= scale;
    *reinterpret_cast<NxVec3*>(&xf.j0) *= scale;
    Unk_MeshData* mesh = ((Unk_MeshSource*)&source)->GetMesh();
    NxTriangleMeshDesc d;
    mesh->Fill(&d);
    verts.reserve((unsigned)(d.nVerts * 3));
    int i;
    const char* p = d.verts;
    for (i = 0; i != d.nVerts; ++i) {
        const char* cur = p;
        NxVec3 v;
        xf.multiply(*(NxVec3 const*)(cur), v);
        long a = RoundToInt(v.x);
        verts.push_back(static_cast<long&&>(a));
        long b = RoundToInt(v.y);
        verts.push_back(static_cast<long&&>(b));
        long c = RoundToInt(v.z);
        verts.push_back(static_cast<long&&>(c));
        p += d.vStride;
    }
    for (i = 0; i != d.nVerts; ++i)
        ((cCoordinateMapping*)&mapping)->applyTo(&verts[(__int64)(i * 3)]);
    tris.reserve((unsigned)(d.nTris * 3));
    p = d.tris;
    if ((d.flags & 2) != 0) {
        for (i = 0; i != d.nTris; ++i) {
            const Unk_Tri16* t = (const Unk_Tri16*)p;
            long a = t->v[0];
            tris.push_back(static_cast<long&&>(a));
            long b = t->v[2];
            tris.push_back(static_cast<long&&>(b));
            long c = t->v[1];
            tris.push_back(static_cast<long&&>(c));
            p += d.tStride;
        }
    } else {
        for (i = 0; i != d.nTris; ++i) {
            const Unk_Tri32* t = (const Unk_Tri32*)p;
            long a = t->v[0];
            tris.push_back(static_cast<long&&>(a));
            long b = t->v[2];
            tris.push_back(static_cast<long&&>(b));
            long c = t->v[1];
            tris.push_back(static_cast<long&&>(c));
            p += d.tStride;
        }
    }
    flag = false;
}

// @0x14164ca30
unsigned __int64 cPhysXTriangleMeshWrapper::vfunc_1() { return tris.size() / 3; }
// @0x14164ca60
unsigned __int64 cPhysXTriangleMeshWrapper::vfunc_2() { return verts.size() / 3; }
// @0x14164ca90
int cPhysXTriangleMeshWrapper::vfunc_3(int tri, int k) { return static_cast<const std::vector<long>&>(tris)[(__int64)(tri * 3 + k)]; }
// @0x14164cad0
int cPhysXTriangleMeshWrapper::vfunc_4(int tri) { return static_cast<const std::vector<long>&>(verts)[(__int64)(tri * 3)]; }
// @0x14164cb10
int cPhysXTriangleMeshWrapper::vfunc_5(int tri) { return static_cast<const std::vector<long>&>(verts)[(__int64)(tri * 3 + 1)]; }
// @0x14164cb50
float cPhysXTriangleMeshWrapper::vfunc_6(int tri) { return (float)static_cast<const std::vector<long>&>(verts)[(__int64)(tri * 3 + 2)]; }
// @0x14164cb90
int cPhysXTriangleMeshWrapper::vfunc_7(int, int what) {
    if (what == 2 && flag) return 1;
    return -1;
}
// @0x14164cbd0
void cPhysXTriangleMeshWrapper::SetFlag(bool f) { flag = f; }
// @0x14164cbf0 implicit ~cPhysXTriangleMeshWrapper
