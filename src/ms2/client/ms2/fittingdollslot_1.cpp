// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). FittingDollPC, the actor the fitting doll window dresses
// (first of the three objects of the fittingdollslot.cpp range; the other two are the slot and its bag).
// MS2-UNIT: client\ms2\fittingdollslot.cpp#1
// MS2-RANGE: 0x14121b350-0x14121d110 .text$mn
// MS2-RANGE: 0x1400e9290-0x1400e9420 .text$di
// MS2-RANGE: 0x142cad860-0x142cad8f0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_7FittingDollPC@@6BIBase@efd@@@ 0x142ec2b60 ; hand: primary vftable
// MS2-PIN: ??_7FittingDollPC@@6BCallbackObject@NiActorManager@@@ 0x142ec3000 ; hand: secondary vftable
// MS2-PIN: ??$format_arg@_WW4Unk_FdResult@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_FdResult@@@Z 0x14121cb10 ; hand: FormatCustomArg call site
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\fittingdollslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/fittingdollpc.h"
#include <new>
#include <NiAVObject.h>
#include <NiColor.h>
#include <NiMatrix3.h>
#include <NiRenderObject.h>
#include <NiSourceTexture.h>
#include <NiTexturingProperty.h>
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/objectdata.h"
#include "ms2/placeholder/citemdata.h"   // C3: CItemData (was Unk_FdItemRec)
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/stateidle.h"
#include "ms2/client/ms2/statetransform.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/nifeffectparam.h"
#include "ms2/client/ms2/material/ms2materials.h"  // C3: MS2StandardMaterial::ms_RTTI
class Unk_PCBaseComp_a58 : public CPtred {};
class Unk_PCBaseComp_a78 : public CPtred {};
class Unk_PCBaseComp_a88 : public CPtred {};
class Unk_PCBaseComp_aa8 : public CPtred {};
class Unk_PCBaseComp_ab8 : public CPtred {};
class Unk_PCBaseComp_ac8 : public CPtred {};
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----

// The world service singleton (FUN_1403ed2d0): the objects by id, the registry of created objects.
class Unk_FdWorld
{
public:
    PCBase* FUN_141bd0cc0();                                // the local player
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    class Unk_WsC_GameObj* FUN_141bd1200(int id);   // C3: the real member (0x141bd1200, an object by id)
    class Unk_WsC_GameObj* FUN_141bd1290(int id);   // C3: the real member (0x141bd1290, an object by id)
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    int FUN_141bbb1e0(GameObject* obj, int bFullInit, unsigned cameraArg);   // C3: the real member, register a created object
    static class WorldService* GetInstance();
};

MS2Ptr<CItemData> FUN_14053f870(int nItemId);   // the item record of an id (install.objCode is the doll object)

// The graphics options (singleton FUN_1409f7c90).
class COptimizer   // C3: member view (coptimizer.h)
{
public:
    int FUN_14109a9d0();                                    // 0: the colour keys are looked up by name
};
class Unk_AvModeSvc* FUN_1409f7c90();   // C3: was FUN_1409f7c90

// The texture swap table of the fitting doll (global config, FUN_1401d31f0): the file names of the textures to swap.
class Unk_FdTexConfig
{
public:
    char m_pad_000[0x108];
    CString m_strBaseFrom;                                  // +0x108
    CString m_strGlossFrom;                                 // +0x110
    CString m_strBaseTo;                                    // +0x118
    CString m_strGlossTo;                                   // +0x120
};
MS2_CHECK_OFFSET(Unk_FdTexConfig, m_strGlossTo, 0x120);
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0

// The texture loader (FUN_140a0afd0).
class Unk_ResourceMgr* FUN_140a0afd0();   // C3: was FUN_140a0afd0

// Depth-first walker over a scene graph (0x30 bytes; unrecovered class).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);            // 0x14098cb80
    ~Unk_NodeQueue();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28;
};
MS2_CHECK_SIZE(Unk_NodeQueue, 0x30);

struct Unk_FdMaterialEntry;
class Unk_CubeKind   // C3: member view for the former free stand-ins
{
public:
    int FUN_140ef4dd0();
};
extern NiFixedString DAT_143ae50c8;                         // colour keys of the three colour slots
extern NiFixedString DAT_143ae50d0;
extern NiFixedString DAT_143ae50d8;
void FUN_1410479a0(class NiObjectNET*, class NiFixedString const&, class NiColor const&);   // C3: was FUN_1410479a0

NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);            // the entity's scene graph
void FUN_140a0b1f0(const NiMatrix3& kRot, efd::Point3& kEuler);   // rotation matrix to euler angles
NiColor FUN_141b6dea0(unsigned nIndex);                     // a skin colour of the colour table
class GameObjectController   // C3: member view for the former free stand-ins
{
public:
    void FUN_14123fbf0(unsigned short);
};

void FUN_141275260(int nStringId, int nA, int nB);          // notice by string id
void FUN_1412752d0(const CStringW& strKey, int nA);         // notice by string key
void FUN_141275460(int nStringId, int nA, int nB, const fmt::ArgList& args);

extern Unk_Inventory g_143ab2a90;

// The id of a doll item result (the notice picks the text).
enum Unk_FdResult : int {};

// fmt message with one argument: the original is a template over the argument type.
template <class A> void Unk_FdMessage(int nStringId, int nA, int nB, const A& x)
{
    const fmt::internal::ArgArray<1>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(x)};
    FUN_141275460(nStringId, nA, nB, fmt::ArgList(fmt::internal::make_type(x), values));
}

EE_IMPLEMENT_CONCRETE_CLASS_INFO(FittingDollPC);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

// @0x14121b350
FittingDollPC::FittingDollPC()
{
    m_spStateMgr.AssignRaw(new CStateManager(this));
    m_spStateMgr->RegisterState(1, new StateIdleFittingDoll(this));
    m_spStateMgr->RegisterState(0x22, new StateTransformDoll(this));
    index = 0;
    unknown12e8 = 0;
    unknown12f0 = 0;
    m_b9d0 = false;
}

// @0x14121b540
FittingDollPC::~FittingDollPC()
{
}

// @0x14121b590
// The doll of a type (0 body, 1 head, 2 other): the registered one, else a new one dressed from the item.
FittingDollPC* FUN_14121b590(int nType, int nSourceId, int nItemId)
{
    PCBase* pObject = 0;
    int nObjectId = 0;
    if (nType == 1)
    {
        nObjectId = 0xf;
        pObject = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1290(0xf));
    }
    else if (nType == 0)
    {
        nObjectId = 0x10;
        pObject = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1290(0x10));
    }
    else if (nType == 2)
    {
        nObjectId = 0x11;
        pObject = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1290(0x11));
    }
    if (pObject == 0 && nObjectId != 0)
    {
        MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
        if (!spItem)
            return 0;
        MS2SvrPtr<CObjectData> spData = FUN_140704ec0(spItem->install.objCode);
        if (!spData)
            return 0;
        pObject = new (efd::MemHint(efd::MemHint::NONE)) FittingDollPC();
        ((FittingDollPC*)pObject)->FUN_14123c5a0(nObjectId);
        if (((FittingDollPC*)pObject)->FUN_14121bab0(nItemId) == 0)
            return 0;
        ((FittingDollPC*)pObject)->type = nType;
        ((FittingDollPC*)pObject)->index = nSourceId;
        if (WorldService::GetInstance()->FUN_141bbb1e0(pObject, 0, 1) == 0)
            return 0;
    }
    return (FittingDollPC*)pObject;
}

// @0x14121b840
// The notice of a doll item result.
void FUN_14121b840(int nResult)
{
    switch (nResult)
    {
    case 0xc:
        FUN_141275260(0x863, 1, 1);
        break;
    case 2:
        FUN_141275260(0x85c, 1, 1);
        break;
    case 3:
        FUN_141275260(0x85f, 1, 1);
        break;
    case 4:
        FUN_141275260(0x860, 1, 1);
        break;
    case 1:
        FUN_141275260(0x85d, 1, 1);
        break;
    case 5:
        FUN_141275260(0x864, 1, 1);
        break;
    case 6:
        FUN_141275260(0x865, 1, 1);
        break;
    case 7:
        FUN_141275260(0x866, 1, 1);
        break;
    case 8:
        FUN_141275260(0x867, 1, 1);
        break;
    case 0x10:
        FUN_141275260(0x868, 1, 1);
        break;
    case 0x12:
        FUN_141275260(0x869, 1, 1);
        break;
    case 0x13:
        FUN_1412752d0(L"s_item_err_binditem_by_gemstone", 1);
        break;
    case 0xd:
        FUN_141275260(0x86a, 1, 1);
        break;
    case 0x14:
        FUN_1412752d0(L"s_fittingdoll_failswap", 1);
        break;
    case 0x15:
        FUN_141275260(0x86b, 1, 1);
        break;
    default:
        Unk_FdMessage(0x85e, 1, 1, reinterpret_cast<const Unk_FdResult&>(nResult));
        break;
    }
}

// @0x14121bab0
// Dress the doll from the doll item: the doll's gender, model and default equipment.
int FittingDollPC::FUN_14121bab0(int nItemId)
{
    type = 2;
    index = 0;
    unknown12e8 = nItemId;
    FUN_141658ed0(1);
    PC::FUN_141662da0(1);
    vfunc_59(1, 0, 0, 0);
    AddStateFlags(4);
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem)
        return 0;
    MS2SvrPtr<CObjectData> spData = FUN_140704ec0(spItem->install.objCode);
    if (!spData)
        return 0;
    FUN_141658e40(spData->m_cube.m_fittingDoll.m_nGender);
    CString strAnim("urn:gamebryo-animation:");
    strAnim += spData->m_cube.m_fittingDoll.m_strAsset;
    FUN_14123bb80(strAnim);
    m_colorD98[0] = FUN_141b6dea0(spData->m_cube.m_fittingDoll.m_anSkinColor[0]);
    m_colorD98[1] = FUN_141b6dea0(spData->m_cube.m_fittingDoll.m_anSkinColor[2]);
    ATL::CAtlArray<unsigned>& kItems = spData->m_cube.m_fittingDoll.m_defaultItems;
    for (size_t i = 0; i < kItems.GetCount(); i++)
    {
        MS2Ptr<CItem> spNew(new CItem());
        if (spNew->FUN_140523c40(kItems[i], 1, 0))
        {
            spNew->SetObjectId(FUN_14123c580());
            FUN_141653d10(spNew);
        }
    }
    return 1;
}

// @0x14121bec0
int FittingDollPC::vfunc_10()
{
    if (PC::vfunc_10() == 0)
        return 0;
    if (type == 2)
        ((class GameObjectController*)(class Unk_PCBaseBody*)(m_unk_150))->FUN_14123fbf0(4);
    return 1;
}
MS2_REPLACE_METHOD(0x14121bec0, FittingDollPC, vfunc_10, 72, 0x539D3CE8);

// @0x14121bf10
void FittingDollPC::vfunc_12()
{
    PC::vfunc_12();
    if (type == 0)
        vfunc_42(0.5f, false);
}
MS2_REPLACE_METHOD(0x14121bf10, FittingDollPC, vfunc_12, 68, 0xC90A50CB);

// @0x14121bf60
bool FittingDollPC::vfunc_68(void* a, double t, int b, unsigned c, int d)
{
    return false;
}
MS2_REPLACE_METHOD(0x14121bf60, FittingDollPC, vfunc_68, 24, 0x75150595);

// @0x14121bf80
// Follow the source actor's attach node: the doll takes its position and rotation.
void FittingDollPC::vfunc_53(float f)
{
    PC::vfunc_53(f);
    if (parentName.GetLength() != 0)
    {
        PCBase* pSource = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1200(index));
        if (pSource != 0)
        {
            NiAVObject* pRoot = FUN_141b6efc0(pSource->FUN_14123c410());
            NiAVObject* pNode = pRoot->GetObjectByName(parentName);
            if (pNode != 0)
            {
                vfunc_19(pNode->GetWorldTranslate());
                efd::Point3 kEuler;
                NiMatrix3 kRot = pNode->GetWorldRotate();
                FUN_140a0b1f0(kRot, kEuler);
                vfunc_21(kEuler);
            }
        }
    }
}

// @0x14121c140
void FittingDollPC::vfunc_9(void* p)
{
    PC::vfunc_9(p);
}
MS2_REPLACE_METHOD(0x14121c140, FittingDollPC, vfunc_9, 34, 0xD0A70947);

// @0x14121c170
void FittingDollPC::SetParentName(NiFixedString kParentName)
{
    parentName = kParentName;
}
MS2_REPLACE_METHOD(0x14121c170, FittingDollPC, SetParentName, 63, 0x18348364);

// @0x14121c1c0
// The doll hovers ten units above the position it is given.
void FittingDollPC::vfunc_19(efd::Point3 kPos)
{
    PCBase::vfunc_19(kPos + efd::Point3(0.0f, 0.0f, 10.0f));
}
MS2_REPLACE_METHOD(0x14121c1c0, FittingDollPC, vfunc_19, 98, 0x07749A96);

// @0x14121c230
// Tint the doll's meshes: the three colour slots, the base and gloss textures swapped by the config.
void FittingDollPC::vfunc_138(NiAVObject* pRoot, int nSlot, const Unk_CharEquip* pColor)
{
    if (pRoot == 0)
        return;
    const char* pszKey = 0;
    if (((class COptimizer*)FUN_1409f7c90())->FUN_14109a9d0() == 0)
    {
        if (nSlot == 0)
            pszKey = (const char*)DAT_143ae50c8;
        else if (nSlot == 1)
            pszKey = (const char*)DAT_143ae50d0;
        else
            pszKey = (const char*)DAT_143ae50d8;
    }
    Unk_NodeQueue kWalker(pRoot);
    while (NiAVObject* pNode = kWalker.Next(true))
    {
        NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pNode);
        if (pRender != 0)
        {
            Unk_FdMaterialEntry* pInfo = ((struct Unk_FdMaterialEntry*)NiMaterial::DynamicCast(&MS2StandardMaterial::ms_RTTI, ((class NiRenderObject*)(pRender))->GetActiveMaterial()));
            if (pInfo != 0 && ((class Unk_CubeKind*)(struct Unk_FdMaterialEntry*)(pInfo))->FUN_140ef4dd0() == 2)
            {
                NiTexturingProperty* pTexturing = (NiTexturingProperty*)pRender->GetProperty(NiProperty::TEXTURING);
                if (pTexturing != 0)
                {
                    NiTexturingProperty::Map* pBase = pTexturing->GetBaseMap();
                    if (pBase != 0)
                    {
                        NiSourceTexture* pSource = NiDynamicCast(NiSourceTexture, pBase->GetTexture());
                        if (pSource != 0 && pSource->GetFilename() != (const char*)((class Unk_FdTexConfig*)FUN_1401d31f0())->m_strBaseFrom)
                        {
                            pBase->SetTexture(((class CNifLoadingService*)FUN_140a0afd0())->GetTexture(CString(((class Unk_FdTexConfig*)FUN_1401d31f0())->m_strBaseTo), 1));
                        }
                    }
                    NiTexturingProperty::Map* pGloss = pTexturing->GetGlossMap();
                    if (pGloss != 0)
                    {
                        NiSourceTexture* pSource = NiDynamicCast(NiSourceTexture, pGloss->GetTexture());
                        if (pSource != 0 && pSource->GetFilename() != (const char*)((class Unk_FdTexConfig*)FUN_1401d31f0())->m_strGlossFrom)
                        {
                            pGloss->SetTexture(((class CNifLoadingService*)FUN_140a0afd0())->GetTexture(CString(((class Unk_FdTexConfig*)FUN_1401d31f0())->m_strGlossTo), 1));
                        }
                    }
                    if (((class COptimizer*)FUN_1409f7c90())->FUN_14109a9d0() != 0)
                    {
                        switch (nSlot)
                        {
                        case 0:
                            FUN_1410479a0((class NiObjectNET*)(pRender), DAT_143ae50c8, *reinterpret_cast<const NiColor*>(pColor));
                            break;
                        case 1:
                            FUN_1410479a0((class NiObjectNET*)(pRender), DAT_143ae50d0, *reinterpret_cast<const NiColor*>(pColor));
                            break;
                        default:
                            FUN_1410479a0((class NiObjectNET*)(pRender), DAT_143ae50d8, *reinterpret_cast<const NiColor*>(pColor));
                        }
                    }
                    else
                        FUN_1410479a0((class NiObjectNET*)(pRender), pszKey, *reinterpret_cast<const NiColor*>(pColor));
                }
            }
        }
    }
    pRoot->UpdateProperties();
}

// @0x14121c6c0
void* FittingDollPC::FUN_14121c6c0()
{
    return unknown12f0;
}
MS2_REPLACE_METHOD(0x14121c6c0, FittingDollPC, FUN_14121c6c0, 18, 0x0C65A3C7);

// @0x14121c6e0
void FittingDollPC::FUN_14121c6e0(void* p)
{
    unknown12f0 = p;
}
MS2_REPLACE_METHOD(0x14121c6e0, FittingDollPC, FUN_14121c6e0, 28, 0xEF6D5F89);

// @0x14121c710
// The doll item's mode (0 when the item places no fitting doll ui).
int FittingDollPC::FUN_14121c710()
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(unknown12e8);
    if (!spItem)
        return 0;
    MS2SvrPtr<CObjectData> spData = FUN_140704ec0(spItem->install.objCode);
    if (!spData)
        return 0;
    if (FUN_1407072e0(spItem->install.objCode) == 0)
        return 0;
    return spData->m_cube.m_fittingDoll.m_nType;
}
MS2_REPLACE_METHOD(0x14121c710, FittingDollPC, FUN_14121c710, 273, 0x12C8E586);

// @0x14121c830
int FittingDollPC::FUN_14121c830()
{
    return FUN_14121c710() == 0;
}

// @0x14121c870
// The result of putting an item on the doll: 0 when it fits.
int FittingDollPC::FUN_14121c870(CItem* pItem)
{
    if (pItem == 0)
        return 0xc;
    PCBase* pPlayer = ((PCBase*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0xb;
    if (pPlayer->IsDead() != 0)
        return 0xb;
    if (g_143ab2a90.FUN_140a65770(pItem) != 0)
        return 6;
    if (g_143ab2a90.FUN_140a63900(pItem, 0) == 0)
        return 5;
    return 0;
}
MS2_REPLACE_METHOD(0x14121c870, FittingDollPC, FUN_14121c870, 149, 0xA3A28DB7);

// @0x14121c910
int FittingDollPC::FUN_14121c910(CItem* pItem)
{
    if (pItem == 0)
        return 0xc;
    if (pItem->HasSkin() != FUN_14121c710())
        return FUN_14121c710() ? 4 : 3;
    if (pItem->FUN_1405267d0(FUN_141658e60()) == 0)
        return FUN_141658e60() == 0 ? 7 : 8;
    return 0;
}

// @0x14121c9d0
int FittingDollPC::FUN_14121c9d0(CItem* pItem)
{
    if (pItem == 0)
        return 0xc;
    if (g_143ab2a90.FUN_140a61430(g_143ab2a90.FUN_140a617f0(MS2Ptr<CItem>(pItem))) == 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14121c9d0, FittingDollPC, FUN_14121c9d0, 108, 0x2E031D17);

// @0x14121ca50
int FittingDollPC::vfunc_145()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14121ca50, FittingDollPC, vfunc_145, 8, 0x7F371472);

// @0x14121cd00
MS2Ptr<Unk_PCBaseComp_ac8> FittingDollPC::vfunc_87()
{
    return MS2Ptr<Unk_PCBaseComp_ac8>(0);
}
MS2_REPLACE_METHOD(0x14121cd00, FittingDollPC, vfunc_87, 55, 0xB3870EE1);

// @0x14121cd40
MS2Ptr<Unk_PCBaseComp_aa8> FittingDollPC::vfunc_85()
{
    return MS2Ptr<Unk_PCBaseComp_aa8>(0);
}
MS2_REPLACE_METHOD(0x14121cd40, FittingDollPC, vfunc_85, 55, 0x868A316C);

// @0x14121cd90
MS2Ptr<Unk_PCBaseComp_a88> FittingDollPC::vfunc_83()
{
    return MS2Ptr<Unk_PCBaseComp_a88>(0);
}
MS2_REPLACE_METHOD(0x14121cd90, FittingDollPC, vfunc_83, 55, 0xD7416C94);

// @0x14121cdd0
UISwfEntity* FittingDollPC::vfunc_88()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14121cdd0, FittingDollPC, vfunc_88, 8, 0x7F371472);

// @0x14121ce10
MS2Ptr<Unk_PCBaseComp_a58> FittingDollPC::vfunc_80()
{
    return MS2Ptr<Unk_PCBaseComp_a58>(0);
}
MS2_REPLACE_METHOD(0x14121ce10, FittingDollPC, vfunc_80, 55, 0xB3F14174);

// @0x14121ce50
MS2Ptr<Unk_PCBaseComp_a78> FittingDollPC::vfunc_82()
{
    return MS2Ptr<Unk_PCBaseComp_a78>(0);
}
MS2_REPLACE_METHOD(0x14121ce50, FittingDollPC, vfunc_82, 55, 0xCAA3897D);

// @0x14121ce90
MS2Ptr<Unk_PCBaseComp_ab8> FittingDollPC::vfunc_86()
{
    return MS2Ptr<Unk_PCBaseComp_ab8>(0);
}
MS2_REPLACE_METHOD(0x14121ce90, FittingDollPC, vfunc_86, 55, 0xE1D7BD9D);

MS2_EMIT_CRT_MEMMOVE_S();
