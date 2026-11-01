// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNifModel: a CEquipModel backed by a single .nif.
// MS2-UNIT: ?\nifmodel.cpp
// MS2-RANGE: 0x141565560-0x141567000 .text$mn
// MS2-RANGE: 0x1400fa540-0x1400fa560 .text$di
// MS2-FUNCTIONAL: vfunc_11 (GS cookie from its char[] stand-in locals) and vfunc_13 (the exe's frame is 0x10 larger
// with every slot 8 higher, and it copies the fourth FUN_1411e99a0 argument through ecx). The node set at +0xf8 is
// walked through Unk_NifNodeSet's begin 0x141209190 / end 0x141209360, not std::set<NiAVObjectPtr>'s.
#include "ms2/placeholder/ms2stdafx.h"
#include "nifmodel.h"
#include "kfmmodel_actor.h"
#include "ms2/client/ms2/nifeffectparam.h"
#include <efd/Matrix3.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

// ---- out-of-unit callees ----
void* FUN_1405a8ed0(void* sp);   void FUN_14097eb60(void* out, void* p);
void* FUN_1411dc7a0(void* owner, void* out);   void FUN_1401bfde0(void* p);
void* FUN_1401c0180(void* p);   int FUN_140527a20(void* p);class CEquipItem   // C3: member view for the former free stand-ins
{
public:
    int FUN_1411dc190(void*);
    struct Unk_EquipItemData* FUN_1411dc7f0();
    MS2Ptr<class CItem> FUN_1411dc7a0();   // the item
    void AddModel(class CEquipModel*);
};
   bool FUN_14053cfd0(void* p);
void FUN_141200e30(class CEquipModel*, int);   // C3: was FUN_141200e30
   int FUN_1412033e0(void* self);
void FUN_14097f710(void* dst, void* src);   char FUN_1409a7f70(void* sp, int n);
void FUN_141200ca0(class CEquipModel*);   // C3: was FUN_141200ca0
void FUN_141209360(void* list, void* out);   void FUN_141209190(void* list, void* out);
char FUN_140b029f0(void* a, void* b);   void* FUN_140b02a60(void* it);   void FUN_140b02a80(void* it);
void* FUN_141b6dea0(void* out, unsigned v);   void* FUN_1414424f0(void* in, void* out, float f);   void FUN_140a0a3a0(void* out, void* in);
class CItemExtraData   // C3: member view for the former free stand-ins
{
public:
    int FUN_140599fd0(unsigned int);
};
void FUN_141b6f000(class NiAVObject*, int, struct Unk_Colc const&);   // C3: was FUN_141b6f000
void* FUN_141200820(class CEquipModel*);   // C3: was FUN_141200820
void* FUN_1412008e0(class CEquipModel*);   // C3: was FUN_1412008e0
void FUN_1412029d0(void* self, CString* out);   void FUN_141202ea0(void* self, CString* s);
int FUN_141422110(void* a, void* b, void* c);void FUN_141ab6e80(class NiAVObject*);   // C3: was FUN_141ab6e80
float FUN_141422340(struct Unk_PickTarget*, int);   // C3: was FUN_141422340
   void FUN_141167840(void* o, const CString& s, float f);
char FUN_140534e50(void* p);   bool FUN_14053d2b0(void* p);void* FUN_1416561a0(void* p);   int FUN_1411e99a0(void* a, unsigned b, const CString& c, unsigned d, int e);
void FUN_140984450(void* out, const char* s);int FUN_141422f30(class NiAVObject*);   // C3: was FUN_141422f30
void FUN_140a0b300(void* o, bool b);   void FUN_14098cb80(void* it, void* o);   void* FUN_14098e0d0(void* it, int n);   void FUN_14098cf00(void* it);
void FUN_1411ffee0(class CEquipModel*, double);   // C3: was FUN_1411ffee0
class CEquipment   // C3: member view for the former free stand-ins
{
public:
    void FUN_1411e75f0();
};
void* FUN_141201c90(void* self);   void FUN_141422b30(void* self, void* a, void* b, void* c, float f);
void FUN_1402bd040(float* p);
void FUN_141203db0(class CEquipModel*);   // C3: was FUN_141203db0
void* FUN_1409a1200(void* p);void FUN_141421f30(class NiMesh*, struct Unk_UgcRoot*);   // C3: was FUN_141421f30
void* FUN_1409f31d0(void* tbl, unsigned id, void* self);
void FUN_1409f2d20(void* tbl, void (*cb)(void*, void*));   void FUN_1409f2e10(void* a, const char* name, unsigned id, void* b, void* tbl);
void FUN_141208010(void* a, void* b);
extern char DAT_143ae2440, DAT_143ae2b38, DAT_143afbbb0;
// The raw 8-byte buffers and m_unk_f0 are the exe's NiAVObjectPtr, m_spNode its NiNodePtr (efd::SmartPointer); calls
// through these views reach the real operators.
#define MS2_AVPTR(p) (*reinterpret_cast<NiAVObjectPtr*>(p))
#define MS2_NODEPTR(sp) reinterpret_cast<NiNodePtr&>(sp)


// m_unk_f8 (std::set<NiAVObjectPtr>) as the exe walks it: its begin/end are a second instantiation (0x141209190 /
// 0x141209360, not the set's own 0x140b02f70 / 0x140b02fe0), reached through this view.
typedef std::set<NiAVObjectPtr>::const_iterator NodeIt;
struct Unk_NifNodeSet
{
    NodeIt FUN_141209190();   // begin
    NodeIt FUN_141209360();   // end
};
// The depth-first scene walker (0x30 bytes; the exe's shared helper, named after its first unit).
class Unk_CubeSceneIterator
{
public:
    Unk_CubeSceneIterator(NiAVObject* pRoot);           // 0x14098cb80
    ~Unk_CubeSceneIterator();                           // 0x14098cf00
    NiAVObject* FUN_14098e0d0(bool descend);            // next object
private:
    ATL::CAtlList<NiAVObject*> pending;
};
MS2_CHECK_SIZE(Unk_CubeSceneIterator, 0x30);
#define NODESET(self) (*reinterpret_cast<Unk_NifNodeSet*>(&(self)->m_unk_f8))
#define F8(self) ((void*)((char*)(self) + 0xf8))
#define PAIR_BEGIN(self, it, end) FUN_141209360(F8(self), end); FUN_141209190(F8(self), it)

#ifdef __clang__
// clang-cl folds the ClassInfo setup (parent = exe's CEquipModel::ms_ClassInfo) into static data (ADDR64 to an exe
// global, rejected by the post-link check): hide the setup function behind a volatile pointer to force a dynamic init.
static efd::ClassInfo::CLASSINFO_FUNC volatile s_nifSetup = &CNifModel::SetupClassInfo;
const efd::ClassInfo CNifModel::ms_ClassInfo((efd::ClassInfo::CLASSINFO_FUNC)s_nifSetup);
#else
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CNifModel);
#endif
void FUN_141566cb0(CNifModel* p);
void FUN_141566b60(void* p);
void* FUN_141566d90(void* p);
void* FUN_141566db0(void* p);
void* FUN_141566d30(void** p);

// The model's owner (the equipped item; held in MS2Ptr). Only the members this unit calls.
class Unk_EquipModelOwner : public CPtred
{
public:
    MS2Ptr<CItem> FUN_1411dc7a0();                        // the item
};
class CItem : public CPtred
{
public:
    unsigned FUN_140527a20();                             // the item's slot kind
public:
    int FUN_1405258b0();   // C3: was free FUN_1405258b0
public:
    class Unk_ItemEquipData* FUN_140527840();   // C3: was free FUN_140527840
public:
    class Unk_UserProxyItemData* FUN_140527870();   // C3: was free FUN_140527870
};

// @0x141565560
CNifModel::CNifModel(MS2Ptr<Unk_EquipModelOwner> spOwner, void* p18, void* p20)
    : CEquipModel(spOwner, p18, p20)
{
    m_i118 = 0;
    m_i11c = 0;
    m_p120 = 0;
    if (*(int*)&DAT_143ae2b38 != 0) {
        CItem* pItem = spOwner->FUN_1411dc7a0().get();
        if (pItem != 0)
            m_i11c = spOwner->FUN_1411dc7a0()->FUN_140527a20() == 2;
    }
}

// The .nif loading service (CNifLoadingService; nifeffectparam.h). Only the loader this unit calls.
CNifLoadingService* FUN_140a0afd0();                      // the service singleton

// @0x141565700
int CNifModel::vfunc_4(CString strPath)
{
    FUN_141200e30((class CEquipModel*)(this), 1);
    m_unk_f0 = FUN_140a0afd0()->Load(strPath, FUN_1412033e0(this) != 0, 5, 0, 0);
    if (m_unk_f0 == 0)
        return 0;
    m_str38 = strPath;
    FUN_141566cb0(this);
    return 1;
}

// @0x141565880
void CNifModel::vfunc_5()
{
    CEquipModel::vfunc_5();
}

// @0x1415658a0
int CNifModel::vfunc_6()
{
    m_nState = 1;
    FUN_141200ca0((class CEquipModel*)(this));
    vfunc_10();
    vfunc_11();
    if (*(int*)&DAT_143ae2b38 != 0 && m_i11c != 0) {
        Unk_NifNodeSet& nodes = NODESET(this);
        for (NodeIt end = nodes.FUN_141209360(), it = nodes.FUN_141209190(); it != end; ++it) {
            NiAVObjectPtr sp = *it;
            if (sp->GetName() == "FA_Skin") {
                m_p120 = sp;
                break;
            }
        }
    }
    return 1;
}

// @0x1415659e0
int CNifModel::vfunc_7()
{
    FUN_141200e30((class CEquipModel*)(this), 1);
    vfunc_5();
    return 1;
}

// @0x141565a20
int FUN_141565a20(CNifModel* self, CString strPath, NiAVObjectPtr spRoot)
{
    self->m_unk_f0 = spRoot;
    self->m_str38 = strPath;
    FUN_141566cb0(self);
    return 1;
}

// @0x141565ab0
int CNifModel::vfunc_8() { return 0; }

// @0x141565ac0
int CNifModel::vfunc_9() { return m_nState; }

// @0x141565ae0
void CNifModel::vfunc_10()
{
    if (FUN_14053cfd0(((class CEquipItem*)(void*)(FUN_1405a8ed0(&m_spOwner)))->FUN_1411dc7f0())) {
        Unk_NifNodeSet& nodes = NODESET(this);
        for (NodeIt end = nodes.FUN_141209360(), it = nodes.FUN_141209190(); it != end; ++it) {
            NiAVObjectPtr sp = *it;
            FUN_141167840(sp, "HR:0", FUN_141422340((struct Unk_PickTarget*)(this), 0));
            FUN_141167840(sp, "HR0:0", FUN_141422340((struct Unk_PickTarget*)(this), 0));
            FUN_141167840(sp, "HR1:1", FUN_141422340((struct Unk_PickTarget*)(this), 1));
        }
    }
}

// @0x141565cb0
void CNifModel::vfunc_11()
{
    char t48[16];
    void* ow = FUN_1411dc7a0(FUN_1405a8ed0(&m_spOwner), t48);
    void* pPartList = ((void*)((class CItem*)(void*)(FUN_1401c0180(ow)))->FUN_140527870());
    FUN_1401bfde0(t48);
    if (pPartList != 0) {
        for (int i = 0; i < 3; ++i) {
            char v70[16];
            FUN_141b6dea0(v70, ((class CItemExtraData*)(void*)(pPartList))->FUN_140599fd0(i));
            if (i == 1) {
                char t38[12], t2c[28], v60[16];
                void* a = FUN_141b6dea0(t38, ((class CItemExtraData*)(void*)(pPartList))->FUN_140599fd0(0));
                void* b = FUN_1414424f0(a, t2c, 1.3f);
                FUN_140a0a3a0(v60, b);
                memcpy(v70, v60, 12);
            }
            char end[8], it[8], sp[8];
            PAIR_BEGIN(this, it, end);
            while (FUN_140b029f0(it, end) != 0) {
                FUN_14097eb60(sp, FUN_140b02a60(it));
                if (MS2_AVPTR(sp).operator NiAVObject*() != 0)
                    FUN_141b6f000((class NiAVObject*)(MS2_AVPTR(sp).operator NiAVObject*()), i, *(struct Unk_Colc const*)(v70));
                MS2_AVPTR(sp).~SmartPointer();
                FUN_140b02a80(it);
            }
        }
        void* p = FUN_141200820((class CEquipModel*)(this));
        if (p != 0)
            ((Unk_ModelActor*)p)->vfunc_139();
    }
}

// @0x141565eb0
void CNifModel::vfunc_12()
{
    void* pNode = FUN_141200820((class CEquipModel*)(this));
    if (pNode == 0) return;
    const CString& strName = FUN_1412029d0();
    if (strName.IsEmpty())
        return;
    FUN_141202ea0(this, (CString*)&strName);
    if (MS2_NODEPTR(m_spNode).operator==((NiNode*)0) != 0)
        return;
    if (FUN_141422110(vfunc_14(), (char*)m_unk_20 + 8, &m_unk_f8) != 0) {
        int iv = ((Unk_ModelActor*)pNode)->vfunc_48();
        Unk_NifNodeSet& nodes = NODESET(this);
        for (NodeIt end = nodes.FUN_141209360(), it = nodes.FUN_141209190(); it != end; ++it) {
            NiAVObjectPtr sp = *it;
            if (sp) {
                NiNode* parent = MS2_NODEPTR(m_spNode).operator->();
                parent->AttachChild(sp, true);
                if (iv != 0)
                    FUN_141ab6e80(sp);
            }
        }
    }
    if (*(int*)((char*)m_unk_20 + 0x34) != 0)
        FUN_141566b60(this);
}

// @0x141566110
void CNifModel::vfunc_13()
{
    if (*(int*)((char*)m_unk_20 + 0x2c) == 0) return;
    void* pRootNode = FUN_1412008e0((class CEquipModel*)(this));
    if (pRootNode == 0) return;
    void* pController = FUN_141200820((class CEquipModel*)(this));
    if (pController == 0) return;
    MS2Ptr<CItem> spItem = ((class CEquipItem*)(void*)(FUN_1405a8ed0(&m_spOwner)))->FUN_1411dc7a0();
    if (!spItem)
        return;
    int nDebugFlag = ((Unk_ModelActor*)pController)->vfunc_48();
    int nAttrA = FUN_14053d2b0(spItem->FUN_140527840());
    int nAttrB = spItem->FUN_1405258b0();
    int nResult = FUN_1411e99a0(FUN_1416561a0(pController), spItem->FUN_140527a20(), FUN_1412029d0(), nAttrB, nAttrA);
    if (nResult != 0) {
        NiNode* pTarget = *(int*)((char*)m_unk_20 + 0x34) != 0
            ? (NiNode*)NiObject::DynamicCast(&NiNode::ms_RTTI, ((class NiActorManager*)(void*)(pRootNode))->GetNIFRoot())
            : (NiNode*)NiObject::DynamicCast(&NiNode::ms_RTTI, ((class NiActorManager*)(void*)(pRootNode))->GetNIFRoot()->GetObjectByName("Bip01 Head"));
        if (pTarget == 0)
            return;
        nResult = FUN_141422110(vfunc_14(), (char*)m_unk_20 + 8, &m_unk_f8);
        if (nResult != 0) {
            Unk_NifNodeSet& nodes = NODESET(this);
            for (NodeIt end = nodes.FUN_141209360(), it = nodes.FUN_141209190(); it != end; ++it) {
                NiAVObjectPtr sp = *it;
                pTarget->AttachChild(sp, true);
                if (nDebugFlag != 0)
                    FUN_141ab6e80(sp);
            }
            FUN_141566b60(this);
        }
    }
}

// @0x1415664f0
int CNifModel::vfunc_15()
{
    Unk_NifNodeSet& nodes = NODESET(this);
    for (NodeIt end = nodes.FUN_141209360(), it = nodes.FUN_141209190(); it != end; ++it) {
        NiAVObjectPtr sp = *it;
        if (sp) {
            if (FUN_141422f30(sp))
                return 1;
        }
    }
    return 0;
}

// @0x1415665d0
void* CNifModel::vfunc_14() { return MS2_AVPTR(&m_unk_f0).operator NiAVObject*(); }

// @0x141566600
void CNifModel::vfunc_16()
{
    vfunc_10();
    vfunc_31();
}

// @0x141566640
void CNifModel::vfunc_17()
{
    CEquipModel::vfunc_17();
    if (m_p120 != 0)
        FUN_140a0b300(m_p120, false);
    bool bActive = m_nState != 0 && vfunc_20() != 0 ? true : false;
    bool bHide = !bActive;
    Unk_NifNodeSet& nodes = NODESET(this);
    for (NodeIt end = nodes.FUN_141209360(), it = nodes.FUN_141209190(); it != end; ++it) {
        NiAVObjectPtr sp = *it;
        Unk_CubeSceneIterator walk(sp);
        NiAVObject* o;
        while ((o = walk.FUN_14098e0d0(true)) != 0) {
            void* c = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afbbb0), (class NiObject const*)(o)));
            if (c != 0 && m_p120 != c)
                FUN_140a0b300(c, bHide);
        }
    }
    Unk_CubeSceneIterator walk((NiAVObject*)vfunc_14());
    NiAVObject* o;
    while ((o = walk.FUN_14098e0d0(true)) != 0) {
        void* c = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afbbb0), (class NiObject const*)(o)));
        if (c != 0 && m_p120 != c)
            FUN_140a0b300(c, bHide);
    }
}

// @0x141566890
void CNifModel::vfunc_18() {}

// @0x1415668a0
void CNifModel::vfunc_19(double fTime)
{
    FUN_1411ffee0((class CEquipModel*)(this), fTime);
    if (m_i118 != 0) {
        ((class CEquipItem*)(void*)(FUN_1405a8ed0(&m_spOwner)))->FUN_1411dc190(this);
        void* p = FUN_141200820((class CEquipModel*)(this));
        if (p != 0)
            ((class CEquipment*)(void*)(FUN_1416561a0(p)))->FUN_1411e75f0();
        m_i118 = 0;
    }
    if (m_b111 != 0) {
        if (vfunc_20() != 0) {
            if (FUN_141200820((class CEquipModel*)(this)) != 0) {
                Unk_ModelActor* p = (Unk_ModelActor*)FUN_141200820((class CEquipModel*)(this));
                vfunc_32(p->vfunc_65());
            }
            m_b111 = false;
        }
    }
}

// @0x1415669c0
void CNifModel::vfunc_29(void* pPos, void* pRotDeg, float fScale)
{
    NiPoint3 a = *(NiPoint3*)pPos;
    vfunc_24(a);
    NiPoint3 b = *(NiPoint3*)pRotDeg;
    vfunc_26(b);
    vfunc_22(fScale);
    FUN_141422b30(this, FUN_141201c90(this), pPos, pRotDeg, fScale);
}

// @0x141566aa0
void CNifModel::vfunc_28(void* pPos, void* pMatrix3, float fScale)
{
    efd::Point3 v;
    ((efd::Matrix3*)pMatrix3)->ToEulerAnglesXYZ(v.x, v.y, v.z);
    v.x = (v.x * 180.0f) / 3.1415927f;
    v.y = (v.y * 180.0f) / 3.1415927f;
    v.z = (v.z * 180.0f) / 3.1415927f;
    vfunc_29(pPos, &v, fScale);
}

// @0x141566b60
void FUN_141566b60(void* self)
{
    void* lVar = FUN_1412008e0((class CEquipModel*)(self));
    if (lVar == 0) return;
    void* tgt = FUN_141566db0(FUN_141566d90(lVar));
    if (tgt == 0) return;
    Unk_NifNodeSet& nodes = NODESET((CNifModel*)self);
    for (NodeIt end = nodes.FUN_141209360(), it = nodes.FUN_141209190(); it != end; ++it) {
        NiAVObjectPtr sp = *it;
        Unk_CubeSceneIterator walk(sp);
        NiAVObject* o;
        while ((o = walk.FUN_14098e0d0(true)) != 0) {
            void* c = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afbbb0), (class NiObject const*)(o)));
            if (c != 0)
                FUN_141421f30((class NiMesh*)(c), (struct Unk_UgcRoot*)(tgt));
        }
    }
}

// @0x141566cb0
void FUN_141566cb0(CNifModel* p)
{
    ((class CEquipItem*)(void*)(FUN_1405a8ed0(&p->m_spOwner)))->AddModel((class CEquipModel*)(p));
    FUN_141203db0((class CEquipModel*)(p));
    p->vfunc_6();
    p->m_i118 = 1;
}

// 0x141566d10 ~CNifModel is implicit (nifmodel.h).

// @0x141566d30
void* FUN_141566d30(void** p) { return *p; }

// @0x141566d90
void* FUN_141566d90(void* p) { return FUN_1409a1200((char*)p + 0x30); }

// @0x141566db0
void* FUN_141566db0(void* p) { return FUN_141566d30((void**)((char*)p + 0xa8)); }

// @0x141566ee0
int FUN_141566ee0(void* dst, size_t dstSize, const void* src, size_t count)
{
    if (count == 0) return 0;
    // The checks are the CRT's _CRT_MEMCPY_S_VALIDATE_RETURN_ERRCODE (memmove_s in vcruntime_string.h).
    {
        int bValid = !!(dst != 0);
        if (!bValid) { *_errno() = EINVAL; _invalid_parameter_noinfo(); return EINVAL; }
    }
    {
        int bValid = !!(src != 0);
        if (!bValid) { *_errno() = EINVAL; _invalid_parameter_noinfo(); return EINVAL; }
    }
    {
        int bValid = !!(dstSize >= count);
        if (!bValid) { *_errno() = ERANGE; _invalid_parameter_noinfo(); return ERANGE; }
    }
    memmove(dst, src, count);
    return 0;
}
