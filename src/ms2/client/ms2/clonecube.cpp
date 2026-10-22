// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See clonecube.h.
// MS2-UNIT: ?\clonecube.cpp
// MS2-RANGE: 0x141084ad0-0x141086ae0 .text$mn
// MS2-RANGE: 0x1400e53c0-0x1400e53e0 .text$di
// MS2-PIN: ?GetClassDesc@CloneCube@@UEBAPEBVClassInfo@efd@@XZ 0x1410866c0
// MS2-PIN: ?TypeCast@CloneCube@@UEBA_NIPEAPEAX@Z 0x141086760
// MS2-PIN: ?TypeCast@CloneCube@@UEBA_NIPEAPEBX@Z 0x1410867b0
// MS2-PIN: ??_7CloneCube@@6BIBase@efd@@@ 0x142ea7408
// MS2-PIN: ??_7CloneCube@@6BCallbackObject@NiActorManager@@@ 0x142ea7600
// MS2-PIN: ??_7CItemUgcMeshContainer@@6B@ 0x142ea73f8
// MS2-PIN: ??_ECloneCube@@W7EAAPEAXI@Z 0x141086434
// MS2-PIN: ??_GCItemUgcMeshContainer@@UEAAPEAXI@Z 0x141086480
// MS2-PIN: ??_GCloneCube@@UEAAPEAXI@Z 0x1410864c0
// MS2-PIN: ??_GNiBooleanExtraData@@UEAAPEAXI@Z 0x141086520
// MS2-PIN: ??1CItemUgcMeshContainer@@UEAA@XZ 0x141086340
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@VCItemUgcMesh@@@@V?$CElementTraits@V?$MS2Ptr@VCItemUgcMesh@@@@@ATL@@@ATL@@QEAA@XZ 0x1410862a0
// MS2-PIN: ?Reference@?$MS2Ptr@VCItemUgcMesh@@@@CAXPEAVCItemUgcMesh@@@Z 0x141086830
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCItemUgcMesh@@@@AEAAXPEAX@Z 0x141086920
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\clonecube.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "clonecube.h"
#include "itemugcmesh.h"
#include <stdlib.h>
#include <NiNode.h>
#include <NiMesh.h>
#include <NiBooleanExtraData.h>
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- out-of-unit callees ----

NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                    // util.cpp: scene root of an entity
void FUN_141568d80(NiAVObject* pRoot);                              // marks a model tree unlightable (MS2 materials)
extern int DAT_143ae2b34;                                           // nonzero: unlightable marking via FUN_141568d80
extern NiFixedString DAT_143ae51c0;                                 // extra data key of unlightable meshes

// Breadth-first queue of scene-graph nodes (0x30 bytes; alphaanimation.cpp defines the members).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);                              // 0x14098cb80
    ~Unk_NodeQueue();                                               // 0x14098cf00
    NiAVObject* Next(bool bAddChildren);                            // 0x14098e0d0
    void SetRoot(NiAVObject* pkRoot);
    void AddChildren(NiNode* pkNode);

private:
    ATL::CAtlList<NiAVObject*> m_list;
};
MS2_CHECK_SIZE(Unk_NodeQueue, 0x30);

// UIModelView (?\uimodelview.cpp, vftable 0x142e51298, 18 slots; not recovered). Only slot 12 is called here.
// MS2: slot 12 (0x140e67350): shows the nodes of arr in the view; spRoot by value (callee-destroyed).
struct Unk_ModelViewVt
{
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(const ATL::CAtlArray<NiNode*>& arr, NiNodePtr spRoot);
};

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CloneCube);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141084ad0
CloneCube::~CloneCube()
{
    m_spItem = 0;
    m_spItemData = 0;
    m_pModelView = 0;
    m_pListener = 0;
    m_spUgcMesh = 0;
}

// @0x141084be0
bool CloneCube::vfunc_57()
{
    if (m_spItemData.get())
    {
        vfunc_58(m_spItemData, m_spItem);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x141084BE0, CloneCube, vfunc_57, 189, 0x1293EEE2);

// @0x141084cb0
void CloneCube::SetItem(MS2Ptr<CItem> spItem)
{
    m_spItem = spItem;
}

// @0x141084d00
void CloneCube::FUN_141084d00(UIModelView* pView)
{
    m_pModelView = pView;
    if (m_pModelView && FUN_14123bea0())
        m_bDirty = true;
}
MS2_REPLACE_METHOD(0x141084D00, CloneCube, FUN_141084d00, 77, 0xB230D7AC);

// @0x141084d60
UIModelView* CloneCube::GetModelView()
{
    return m_pModelView;
}
MS2_REPLACE_METHOD(0x141084D60, CloneCube, GetModelView, 18, 0x2475AD70);

// @0x141084d80
bool CloneCube::vfunc_58(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem)
{
    if (vfunc_61(spData, spItem))
        return false;

    CString strPath;
    if (spData.get())
    {
        char szName[_MAX_FNAME] = {};
        _splitpath(spData->install.asset, NULL, NULL, szName, NULL);
        if (!szName)
            return false;
        strPath.Format(m_strModelFormat, szName);
    }
    else
    {
        strPath = m_strModel;
    }

    m_spItemData = spData;
    m_spItem = spItem;
    bool bChanged = strPath != FUN_14123bbd0();
    if (bChanged)
    {
        if (FUN_14123c410())
        {
            if (m_spUgcMesh.get())
                m_spUgcMesh->FUN_141426140();
            FUN_14123bc20(strPath);
            m_bReloading = true;
            if (m_pListener)
                m_pListener->vfunc_3(this);
        }
        else if (spData.get())
        {
            if (spData->install.preset.IsEmpty())
                FUN_14123bb80(strPath);
            else
                m_str88 = spData->install.preset;
        }
        else
        {
            FUN_14123bb80(strPath);
        }
    }
    if (FUN_14123bea0() && !bChanged)
        FUN_141085530(spItem);
    return true;
}

// @0x141085250
void CloneCube::FUN_141085250()
{
    if (m_spUgcMesh.get())
        m_spUgcMesh->FUN_141426980();
}
MS2_REPLACE_METHOD(0x141085250, CloneCube, FUN_141085250, 65, 0xB6016DCA);

// @0x1410852a0
void CloneCube::FUN_1410852a0()
{
    if (!m_pModelView)
        return;

    ATL::CAtlArray<NiNode*> arr;
    NiNode* pNode = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pNode)
    {
        pNode->SetAppCulled(false);
        FUN_141568d80(pNode);
        arr.Add(pNode);
        reinterpret_cast<Unk_ModelViewVt*>(m_pModelView)->vfunc_12(arr, NiNodePtr(0));
    }
    m_bDirty = false;
    if (m_pListener)
        m_pListener->vfunc_2(this);
}
MS2_REPLACE_METHOD(0x1410852A0, CloneCube, FUN_1410852a0, 304, 0x7C318DCB);

// @0x1410853e0
void CloneCube::FUN_1410853e0(bool bVisible)
{
    m_bVisible = bVisible;
    vfunc_47(bVisible);
}
MS2_REPLACE_METHOD(0x1410853E0, CloneCube, FUN_1410853e0, 58, 0x924FA43B);

// @0x141085420
bool CloneCube::IsVisible()
{
    return m_bVisible;
}
MS2_REPLACE_METHOD(0x141085420, CloneCube, IsVisible, 18, 0x76A63993);

static void FUN_1410865e0(NiObjectNET* pObj, const NiFixedString& kKey, bool bValue);

// @0x141085440
void CloneCube::FUN_141085440()
{
    NiAVObject* pRoot = NiDynamicCast(NiAVObject, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot)
    {
        if (DAT_143ae2b34)
        {
            FUN_141568d80(pRoot);
        }
        else
        {
            Unk_NodeQueue kQueue(pRoot);
            while (NiAVObject* pObj = kQueue.Next(true))
            {
                NiMesh* pMesh = NiDynamicCast(NiMesh, pObj);
                if (pMesh && !pMesh->GetExtraData(DAT_143ae51c0))
                    FUN_1410865e0(pMesh, DAT_143ae51c0, true);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141085440, CloneCube, FUN_141085440, 222, 0x8B641787);

// @0x141085530
void CloneCube::FUN_141085530(MS2Ptr<CItem> spItem)
{
    if (!FUN_14123bea0())
        return;
    vfunc_59(spItem);
}

// @0x1410855b0
void CloneCube::FUN_1410855b0()
{
    if (m_spUgcMesh == 0)
        m_spUgcMesh.AssignRaw(new CItemUgcMeshContainer);
    if (m_spUgcMesh.get())
        m_spUgcMesh->FUN_141426540(m_spItemData, NiAVObjectPtr(FUN_141b6efc0(FUN_14123c410())));
}
MS2_REPLACE_METHOD(0x1410855B0, CloneCube, FUN_1410855b0, 329, 0xE3C47C83);

// @0x141085700
NiTexturePtr CloneCube::FUN_141085700()
{
    return m_spUgcMesh.get() ? m_spUgcMesh->FUN_141426d40() : NiTexturePtr(0);
}
MS2_REPLACE_METHOD(0x141085700, CloneCube, FUN_141085700, 284, 0x9CED1E0E);

// @0x141085830
MS2Ptr<CItemUgcMeshContainer> CloneCube::GetUgcMesh()
{
    return m_spUgcMesh;
}

// @0x141085880
MS2Ptr<CItemData> CloneCube::GetItemData()
{
    return m_spItemData;
}

// @0x1410858d0
void CloneCube::vfunc_9(void* p)
{
    vfunc_57();
    GameObject::vfunc_9(p);
}
MS2_REPLACE_METHOD(0x1410858D0, CloneCube, vfunc_9, 53, 0x4D2936E1);

// @0x141085910
int CloneCube::vfunc_10()
{
    if (!GameObject::vfunc_10())
        return 0;
    if (m_pListener)
        m_pListener->vfunc_0(this);
    vfunc_60();
    m_bDirty = true;
    return 1;
}
MS2_REPLACE_METHOD(0x141085910, CloneCube, vfunc_10, 117, 0x4A1D7D9B);

// @0x141085990
void CloneCube::vfunc_12()
{
    GameObject::vfunc_12();
    if (m_pListener)
        m_pListener->vfunc_1(this);
}
MS2_REPLACE_METHOD(0x141085990, CloneCube, vfunc_12, 74, 0x17E15D5E);

// @0x1410859e0
void CloneCube::vfunc_13(void* a, efd::Category cat)
{
    GameObject::vfunc_13(a, cat);
    if (m_bReloading)
    {
        vfunc_60();
        if (m_pListener)
            m_pListener->vfunc_4(this);
    }
    m_bDirty = true;
    m_bReloading = false;
}

// @0x141085ab0
void CloneCube::SetListener(IAvatarObjectEventListener* p)
{
    m_pListener = p;
}
MS2_REPLACE_METHOD(0x141085AB0, CloneCube, SetListener, 28, 0x329EF226);

// @0x141085ae0
IAvatarObjectEventListener* CloneCube::GetListener()
{
    return m_pListener;
}
MS2_REPLACE_METHOD(0x141085AE0, CloneCube, GetListener, 18, 0x8EEA29A0);

// @0x141085b00
CloneCube::CloneCube(MS2Ptr<CItemData> spData, const CString& strModel)
    : m_pModelView(0)
    , m_bDirty(false)
    , m_bVisible(false)
    , m_pListener(0)
    , m_spItem(0)
    , m_spItemData(spData)
    , m_strModel(strModel)
    , m_bReloading(false)
{
    m_unk_b0 = 0;
    m_str88 = "MS2NolightableMesh";
    m_unk_d0 = 1;
    m_strModelFormat = "urn:gamebryo-scenegraph:%s";
}

// @0x141085c70
void CloneCube::vfunc_49()
{
}
MS2_REPLACE_METHOD(0x141085C70, CloneCube, vfunc_49, 6, 0xA9AF6E37);

// @0x141085c80
void CloneCube::vfunc_53(float f)
{
    GameObject::vfunc_53(f);
    if (m_bDirty)
        FUN_1410852a0();
    FUN_141085440();
}
MS2_REPLACE_METHOD(0x141085C80, CloneCube, vfunc_53, 72, 0xF3D31688);

// @0x141085cd0
bool CloneCube::vfunc_56(float f)
{
    if (m_bVisible)
        return GameObject::vfunc_56(f);
    return false;
}
MS2_REPLACE_METHOD(0x141085CD0, CloneCube, vfunc_56, 56, 0x8B2C1D81);

// @0x141085d10
bool CloneCube::vfunc_55(float a, float b)
{
    if (m_bVisible)
        return GameObject::vfunc_55(a, b);
    return false;
}
MS2_REPLACE_METHOD(0x141085D10, CloneCube, vfunc_55, 68, 0x7439B4BF);

// @0x141085d60
void CloneCube::vfunc_59(MS2Ptr<CItem> spItem)
{
}

// @0x141085d90
void CloneCube::vfunc_60()
{
    if (m_spUgcMesh == 0 && (m_spItemData.get() ? true : false))
        FUN_1410855b0();
    if (m_spItem.get())
        FUN_141085530(m_spItem);
}
MS2_REPLACE_METHOD(0x141085D90, CloneCube, vfunc_60, 175, 0x92332E21);

// @0x141085e50
bool CloneCube::vfunc_61(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem)
{
    if (FUN_14123bea0())
    {
        MS2Ptr<CItemData> spCurData(m_spItemData);
        MS2Ptr<CItem> spCurItem(m_spItem);
        if ((spData.get() ? true : false) && (spCurData.get() ? true : false)
            && spData->FUN_14053c510() == spCurData->FUN_14053c510())
        {
            if (spCurItem == spItem.get())
                return true;
            __int64 nCurUid = (spCurItem.get() ? true : false) && ((CItem*)spCurItem)->FUN_140525f10()
                ? ((CItem*)spCurItem)->FUN_1405278d0()->m_nUgcUid : 0;
            __int64 nUid = (spItem.get() ? true : false) && ((CItem*)spItem)->FUN_140525f10()
                ? ((CItem*)spItem)->FUN_1405278d0()->m_nUgcUid : 0;
            if (nCurUid == nUid)
                return true;
        }
    }
    return false;
}

// Sets the boolean extra data kKey of pObj to bValue, adding it when missing.
// @0x1410865e0
static void FUN_1410865e0(NiObjectNET* pObj, const NiFixedString& kKey, bool bValue)
{
    NiBooleanExtraData* pData = NiDynamicCast(NiBooleanExtraData, pObj->GetExtraData(kKey));
    if (!pData)
    {
        pData = NiNew NiBooleanExtraData(bValue);
        pObj->AddExtraData(kKey, pData);
    }
    else
    {
        pData->SetValue(bValue);
    }
}
