// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNifModel: a CEquipModel backed by a single .nif.
// MS2-UNIT: ?\nifmodel.cpp
// MS2-RANGE: 0x141565560-0x141567000 .text$mn
// MS2-RANGE: 0x1400fa540-0x1400fa560 .text$di
// The node set at +0xf8 (std::set<NiAVObjectPtr>) is walked with its non-const begin 0x141209190 / end 0x141209360.
#include "ms2/placeholder/ms2stdafx.h"
#include "nifmodel.h"
#include "kfmmodel_actor.h"
#include "ms2/client/ms2/nifeffectparam.h"
#include "ms2/client/ms2/equipment.h"  // C3: was a local member view
#include "ms2/placeholder/citemdata.h"
#include <NiAVObject.h>
#include <NiMesh.h>   // C3: ms_RTTI
#include <NiControllerManager.h>
#include "ms2/placeholder/fittingdollpc.h"
#include <efd/Matrix3.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
class Unk_ResourceMgr;

// ---- out-of-unit callees ----
void FUN_14097eb60(void* out, void* p);
int FUN_140527a20(void* p);class CEquipItem : public CPtred   // C3: member view for the former free stand-ins
{
public:
    int FUN_1411dc190(void*);
    struct Unk_EquipItemData* FUN_1411dc7f0();
    MS2Ptr<class CItem> GetItem();   // the item
    void AddModel(class CEquipModel*);
};
void FUN_141200e30(class CEquipModel*, int);   // C3: was FUN_141200e30
   int FUN_1412033e0(class CEquipModel* self);
void FUN_14097f710(void* dst, void* src);
void FUN_141200ca0(class CEquipModel*);   // C3: was FUN_141200ca0
//
char FUN_140b029f0(void* a, void* b);   void* FUN_140b02a60(void* it);   void FUN_140b02a80(void* it);
NiColor FUN_141b6dea0(unsigned v);
class CItemExtraData   // C3: member view for the former free stand-ins
{
public:
    int GetCurrentRgbComponent(unsigned int);
};
void FUN_141b6f000(class NiAVObject*, int, struct Unk_Colc const&);   // C3: was FUN_141b6f000
void* FUN_141200820(class CEquipModel*);   // C3: was FUN_141200820
void* FUN_1412008e0(class CEquipModel*);   // C3: was FUN_1412008e0
void FUN_1412029d0(void* self, CString* out);   void FUN_141202ea0(class CEquipModel* self, CString* s);
unsigned FUN_141422110(NiNode* pRoot, const CString& strPrefix, std::set<NiAVObjectPtr>* pSet);void FUN_141ab6e80(class NiAVObject*);   // C3: was FUN_141ab6e80
float FUN_141422340(class CEquipModel*, int);   // C3: was FUN_141422340
   void FUN_141167840(NiAVObject* o, const CString& s, float f);
void FUN_140984450(void* out, const char* s);int FUN_141422f30(class NiAVObject*);   // C3: was FUN_141422f30
void FUN_1411ffee0(class CEquipModel*, double);   // C3: was FUN_1411ffee0
std::set<NiAVObjectPtr>* FUN_141201c90(CEquipModel* self);
void FUN_141422b30(class CEquipModel* pPart, std::set<NiAVObjectPtr>& kNodes, const struct Vector3& kPos, const struct Vector3& kEuler, float fScale);   // itemugcmesh.cpp
void FUN_1402bd040(float* p);
void FUN_141203db0(class CEquipModel*);   // C3: was FUN_141203db0
void FUN_141421f30(class NiMesh*, struct Unk_UgcRoot*);   // C3: was FUN_141421f30
void* FUN_1409f31d0(void* tbl, unsigned id, void* self);
void FUN_1409f2d20(void* tbl, void (*cb)(void*, void*));   void FUN_1409f2e10(void* a, const char* name, unsigned id, void* b, void* tbl);
void FUN_141208010(void* a, void* b);
extern char DAT_143ae2440, DAT_143ae2b38;
// The raw 8-byte buffers and m_unk_f0 are the exe's NiAVObjectPtr, m_spNode its NiNodePtr (efd::SmartPointer); calls
// through these views reach the real operators.
#define MS2_AVPTR(p) (*reinterpret_cast<NiAVObjectPtr*>(p))
#define MS2_NODEPTR(sp) reinterpret_cast<NiNodePtr&>(sp)


// m_unk_f8 (std::set<NiAVObjectPtr>) as the exe walks it: the non-const _Tree::begin/end (0x141209190 /
// 0x141209360; the const pair is 0x140b02f70 / 0x140b02fe0, called by itemugcmesh).
typedef std::set<NiAVObjectPtr>::const_iterator NodeIt;
//
//
//
//
//
// The depth-first scene walker (0x30 bytes; the exe's shared helper, named after its first unit).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pRoot);           // 0x14098cb80
    ~Unk_NodeQueue();                           // 0x14098cf00
    NiAVObject* Next(bool descend);            // next object
private:
    ATL::CAtlList<NiAVObject*> pending;
};
MS2_CHECK_SIZE(Unk_NodeQueue, 0x30);
#define NODESET(self) ((self)->m_unk_f8)
#define F8(self) ((void*)((char*)(self) + 0xf8))
//

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

class CItem : public CPtred
{
public:
    unsigned FUN_140527a20();                             // the item's slot kind
public:
    int HasSkin();   // C3: was free HasSkin
public:
    class Unk_ItemEquipData* FUN_140527840();   // C3: was free FUN_140527840
public:
    class Unk_UserProxyItemData* FUN_140527870();   // C3: was free FUN_140527870
};

// @0x141565560
CNifModel::CNifModel(MS2Ptr<CEquipItem> spOwner, void* p18, void* p20)
    : CEquipModel(spOwner, p18, p20)
{
    m_i118 = 0;
    m_i11c = 0;
    m_p120 = 0;
    if (*(int*)&DAT_143ae2b38 != 0) {
        CItem* pItem = spOwner->GetItem().get();
        if (pItem != 0)
            m_i11c = spOwner->GetItem()->FUN_140527a20() == 2;
    }
}

// The .nif loading service (CNifLoadingService; nifeffectparam.h). Only the loader this unit calls.
Unk_ResourceMgr*FUN_140a0afd0();                      // the service singleton

// @0x141565700
int CNifModel::vfunc_4(CString strPath)
{
    FUN_141200e30((class CEquipModel*)(this), 1);
    m_unk_f0 = reinterpret_cast<CNifLoadingService *>(FUN_140a0afd0())->Load(strPath, FUN_1412033e0((class CEquipModel*)(this)) != 0, 5, 0, 0);
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
        std::set<NiAVObjectPtr>& nodes = NODESET(this);
        for (NodeIt end = nodes.end(), it = nodes.begin(); it != end; ++it) {
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
    if (reinterpret_cast<CItemData*>(reinterpret_cast<MS2Ptr<CEquipItem>&>(m_spOwner)->FUN_1411dc7f0())->FUN_14053cfd0()) {
        std::set<NiAVObjectPtr>& nodes = NODESET(this);
        for (NodeIt end = nodes.end(), it = nodes.begin(); it != end; ++it) {
            NiAVObjectPtr sp = *it;
            FUN_141167840(sp, "HR:0", FUN_141422340((class CEquipModel*)(this), 0));
            FUN_141167840(sp, "HR0:0", FUN_141422340((class CEquipModel*)(this), 0));
            FUN_141167840(sp, "HR1:1", FUN_141422340((class CEquipModel*)(this), 1));
        }
    }
}

// @0x141565cb0
void CNifModel::vfunc_11()
{
    void* pPartList = ((void*)static_cast<const MS2Ptr<CItem>&>(reinterpret_cast<MS2Ptr<CEquipItem>&>(m_spOwner)->GetItem())->FUN_140527870());
    if (pPartList == 0)
        return;
    for (int i = 0; i < 3; ++i) {
        NiColor kColor = FUN_141b6dea0(((class CItemExtraData*)(void*)(pPartList))->GetCurrentRgbComponent(i));
        if (i == 1)
            kColor = FUN_141b6dea0(((class CItemExtraData*)(void*)(pPartList))->GetCurrentRgbComponent(0)) * 1.3f;
        std::set<NiAVObjectPtr>& nodes = NODESET(this);
        for (NodeIt end = nodes.end(), it = nodes.begin(); it != end; ++it) {
            NiAVObjectPtr sp = *it;
            if (sp)
                FUN_141b6f000(sp, i, *(struct Unk_Colc const*)(&kColor));
        }
    }
    void* p = FUN_141200820((class CEquipModel*)(this));
    if (p != 0)
        ((Unk_ModelActor*)p)->vfunc_139();
}

// @0x141565eb0
void CNifModel::vfunc_12()
{
    void* pNode = FUN_141200820((class CEquipModel*)(this));
    if (pNode == 0) return;
    const CString& strName = FUN_1412029d0();
    if (strName.IsEmpty())
        return;
    FUN_141202ea0((class CEquipModel*)(this), (CString*)&strName);
    if (MS2_NODEPTR(m_spNode).operator==((NiNode*)0) != 0)
        return;
    if (FUN_141422110((NiNode*)vfunc_14(), *(const CString*)((char*)m_unk_20 + 8), &m_unk_f8) != 0) {
        int iv = ((Unk_ModelActor*)pNode)->vfunc_48();
        std::set<NiAVObjectPtr>& nodes = NODESET(this);
        for (NodeIt end = nodes.end(), it = nodes.begin(); it != end; ++it) {
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
    MS2Ptr<CItem> spItem = reinterpret_cast<MS2Ptr<CEquipItem>&>(m_spOwner)->GetItem();
    if (!spItem)
        return;
    int nDebugFlag = ((Unk_ModelActor*)pController)->vfunc_48();
    int nAttrA = reinterpret_cast<CItemData*>(spItem->FUN_140527840())->FUN_14053d2b0();
    int nResult = reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pController)->FUN_1416561a0())->FUN_1411e99a0(spItem->FUN_140527a20(), FUN_1412029d0(), spItem->HasSkin(), nAttrA);
    if (nResult != 0) {
        NiNode* pTarget = *(int*)((char*)m_unk_20 + 0x34) != 0
            ? (NiNode*)NiObject::DynamicCast(&NiNode::ms_RTTI, ((class NiActorManager*)(void*)(pRootNode))->GetNIFRoot())
            : (NiNode*)NiObject::DynamicCast(&NiNode::ms_RTTI, ((class NiActorManager*)(void*)(pRootNode))->GetNIFRoot()->GetObjectByName("Bip01 Head"));
        if (pTarget == 0)
            return;
        if (FUN_141422110((NiNode*)vfunc_14(), *(const CString*)((char*)m_unk_20 + 8), &m_unk_f8) != 0) {
            std::set<NiAVObjectPtr>& nodes = NODESET(this);
            for (NodeIt end = nodes.end(), it = nodes.begin(); it != end; ++it) {
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
    std::set<NiAVObjectPtr>& nodes = NODESET(this);
    for (NodeIt end = nodes.end(), it = nodes.begin(); it != end; ++it) {
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
        reinterpret_cast<NiAVObject*>(m_p120)->SetAppCulled(false);
    bool bActive = m_nState != 0 && vfunc_20() != 0 ? true : false;
    bool bHide = !bActive;
    std::set<NiAVObjectPtr>& nodes = NODESET(this);
    for (NodeIt end = nodes.end(), it = nodes.begin(); it != end; ++it) {
        NiAVObjectPtr sp = *it;
        Unk_NodeQueue walk(sp);
        NiAVObject* o;
        while ((o = walk.Next(true)) != 0) {
            void* c = ((void*)NiObject::DynamicCast(&NiMesh::ms_RTTI, (class NiObject const*)(o)));
            if (c != 0 && m_p120 != c)
                reinterpret_cast<NiAVObject*>(c)->SetAppCulled(bHide);
        }
    }
    Unk_NodeQueue walk((NiAVObject*)vfunc_14());
    NiAVObject* o;
    while ((o = walk.Next(true)) != 0) {
        void* c = ((void*)NiObject::DynamicCast(&NiMesh::ms_RTTI, (class NiObject const*)(o)));
        if (c != 0 && m_p120 != c)
            reinterpret_cast<NiAVObject*>(c)->SetAppCulled(bHide);
    }
}

// @0x141566890
void CNifModel::vfunc_18() {}

// @0x1415668a0
void CNifModel::vfunc_19(double fTime)
{
    FUN_1411ffee0((class CEquipModel*)(this), fTime);
    if (m_i118 != 0) {
        reinterpret_cast<MS2Ptr<CEquipItem>&>(m_spOwner)->FUN_1411dc190(this);
        void* p = FUN_141200820((class CEquipModel*)(this));
        if (p != 0)
            ((class CEquipment*)(void*)(reinterpret_cast<PC*>(p)->FUN_1416561a0()))->FUN_1411e75f0();
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
    FUN_141422b30((class CEquipModel*)this, *FUN_141201c90(this), *(const struct Vector3*)pPos, *(const struct Vector3*)pRotDeg, fScale);
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
    std::set<NiAVObjectPtr>& nodes = NODESET((CNifModel*)self);
    for (NodeIt end = nodes.end(), it = nodes.begin(); it != end; ++it) {
        NiAVObjectPtr sp = *it;
        Unk_NodeQueue walk(sp);
        NiAVObject* o;
        while ((o = walk.Next(true)) != 0) {
            void* c = ((void*)NiObject::DynamicCast(&NiMesh::ms_RTTI, (class NiObject const*)(o)));
            if (c != 0)
                FUN_141421f30((class NiMesh*)(c), (struct Unk_UgcRoot*)(tgt));
        }
    }
}

// @0x141566cb0
void FUN_141566cb0(CNifModel* p)
{
    reinterpret_cast<MS2Ptr<CEquipItem>&>(p->m_spOwner)->AddModel((class CEquipModel*)(p));
    FUN_141203db0((class CEquipModel*)(p));
    p->vfunc_6();
    p->m_i118 = 1;
}

// 0x141566d10 ~CNifModel is implicit (nifmodel.h).

// @0x141566d30
void* FUN_141566d30(void** p) { return *p; }

// @0x141566d90
void* FUN_141566d90(void* p) { return (NiControllerManager*)*reinterpret_cast<efd::SmartPointer<NiControllerManager>*>((char*)p + 0x30); }

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
