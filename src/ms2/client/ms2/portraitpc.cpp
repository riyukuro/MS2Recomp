// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See portraitpc.h.
// MS2-UNIT: ?\portraitpc.cpp
// MS2-RANGE: 0x1416999b0-0x14169afb0 .text$mn
// MS2-RANGE: 0x1400fbf80-0x1400fc110 .text$di
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_7PortraitPC@@6B@ 0x142f4eee0
// MS2-PIN: ??_7PortraitPC@@6BIBase@efd@@@ 0x142f4e9d8
// MS2-PIN: ??_7PortraitPC@@6BCallbackObject@NiActorManager@@@ 0x142f4eea8
// MS2-PIN: ??_7PortraitPC@@6BUIItemEventListener@@@ 0x142f4eee0
// MS2-PIN: ??_GPortraitPC@@UEAAPEAXI@Z 0x14169abf0
// MS2-PIN: ?GetClassDesc@PortraitPC@@UEBAPEBVClassInfo@efd@@XZ 0x14169ac50
// MS2-PIN: ?TypeCast@PortraitPC@@UEBA_NIPEAPEAX@Z 0x14169acc0
// MS2-PIN: ?TypeCast@PortraitPC@@UEBA_NIPEAPEBX@Z 0x14169ad10
// MS2-PIN: ?SetupClassInfo@PortraitPC@@SAXPEAVClassInfo@efd@@_K@Z 0x14169ac60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\portraitpc.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "portraitpc.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/placeholder/notifychange.h"
#include "ms2/placeholder/notifysystem.h"
#include <NiActorManager.h>

// ---- unit-local stand-ins for the unrecovered pointee types ----

// UIModelView (UIRenderView subclass, NiRefObject, ?\uimodelview.cpp): slot 11 takes the equip model records.
class UIModelView : public NiRefObject
{
public:
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(int nObjectId);
    virtual void vfunc_11(ATL::CAtlArray<efd::SmartPointer<NiActorManager> >& kEquip);   // 11 shows the equip models
    int FUN_141ab7660();                                    // 0x141ab7660 the view is still loading
};

// The equipment FUN_14165f460 hands out: a PCGemEquip.
class Unk_MyPCEquip : public PCGemEquip {};

// The list of worn items a PC mirrors at +0xd48 (CAtlArray of MS2Ptr<CEquipItem>).
class Unk_PtItemList
{
public:
    MS2Ptr<CEquipItem>& FUN_140c3c720(unsigned __int64 n);  // 0x140c3c720 element n
};

// The entity manager (singleton FUN_1403ed2d0).
class WorldService   // C3: member view (real class not in this TU)
{
public:
    int FUN_141bbb1e0(GameObject*, int, unsigned int);
    void* FUN_141bd0cc0();
    void* FUN_141bd3620();
};
class Unk_PtWorld
{
public:
};
Unk_PtWorld* FUN_1403ed2d0();

// The notify centre (singleton FUN_140939a10): named notify handlers.
NotifySystem* FUN_140939a10();

// The item event hub (singleton FUN_140a6a840).
class Unk_ItemEventSystem   // C3: member view (real class not in this TU)
{
public:
    void FUN_1419cae20(UIItemEventListener*);
    void FUN_1419caeb0(UIItemEventListener*);
};
class Unk_PtItemEvents
{
public:
};
Unk_PtItemEvents* FUN_140a6a840();

// efd::Point3 / NiPoint3 helpers called out of line.
struct Unk_PtVec3 : public Vector3
{
    Unk_PtVec3(const Vector3& pt);                  // 0x14027dcf0 (NiPoint3(const efd::Point3&))
    Unk_PtVec3(float x, float y, float z);                  // 0x14097f250
};

// ---- out-of-unit callees ----

extern char DAT_143acdb20;                                  // set while the avatar previews are disabled
extern Vector3 DAT_143b01a60;                              // the zero point

void FUN_1411e1b80(Unk_PCEquipSet* pEquipSet, ATL::CAtlList<MS2Ptr<CEquipItem> >& kOut);   // the worn items
class CEquipment   // C3: member view for the former free stand-ins
{
public:
    void FUN_1411e3de0(int);
};
void FUN_1411e3600(Unk_PCEquipSet* pEquipSet, MS2Ptr<CEquipItem> spEquip);   // adds a worn item (callee-destroyed arg)
MS2Ptr<CItem> FUN_140ccac60(MS2Ptr<CItem> spItem);          // 0x140ccac60 a copy of the item
Unk_PtVec3 FUN_14169a860();
unsigned __int64 FUN_141662e90(PC* pPC);

// ---- class info and header statics (the exe runs them in this order) ----

EE_IMPLEMENT_CONCRETE_CLASS_INFO(PortraitPC);

#include "ms2/placeholder/header_statics_a.h"

// @0x1416999b0
PortraitPC::~PortraitPC()
{
}

// @0x141699a20
PortraitPC* FUN_141699a20(PC* pSource);
PortraitPC* FUN_141699a20(PC* pSource)
{
    if ((unsigned char)DAT_143acdb20 != 0)
        return 0;
    PortraitPC* pPortrait = ((PortraitPC*)((WorldService*)(Unk_PtWorld*)(FUN_1403ed2d0()))->FUN_141bd3620());
    if (pPortrait != 0)
        return pPortrait;
    pPortrait = new (efd::MemHint(efd::MemHint::NONE)) PortraitPC(pSource);
    pPortrait->FUN_14123c5a0(2);
    pPortrait->FUN_141656a50(pSource->FUN_141656a80());
    pPortrait->FUN_14123bb80(pSource->FUN_14123bbd0());
    static_cast<PC*>(pPortrait)->vfunc_19(*reinterpret_cast<const efd::Point3*>(&static_cast<const NiPoint3&>(pSource->vfunc_18())));
    efd::Point3 kDir = *reinterpret_cast<const efd::Point3*>(&static_cast<const Unk_PtVec3&>(FUN_14169a860()));
    static_cast<PC*>(pPortrait)->vfunc_21(kDir);
    pPortrait->vfunc_131((short)pSource->vfunc_78());
    pPortrait->vfunc_76(CStringW(L""));
    pPortrait->FUN_141658e40(((class PC*)(class PC*)(pSource))->FUN_141658e60());
    pPortrait->vfunc_59(1, 0, 0, 0);
    pPortrait->FUN_14166cce0(4);
    pPortrait->FUN_1416591e0(0, pSource->FUN_141659220(0));
    pPortrait->FUN_1416591e0(1, pSource->FUN_141659220(1));
    pPortrait->FUN_141658ed0(((class PC*)(class PC*)(pSource))->FUN_141658f10());
    pPortrait->FUN_141662d60(FUN_141662e90(pSource));
    if (((WorldService*)(Unk_PtWorld*)(FUN_1403ed2d0()))->FUN_141bbb1e0((GameObject*)(PortraitPC*)(pPortrait), 0, 1) != 0)
        return pPortrait;
    return 0;
}

// @0x141699d60
void PortraitPC::vfunc_149()
{
    ((ATL::CAtlArray<MS2Ptr<CItem>, ATL::CElementTraits<MS2Ptr<CItem>>>*)(Unk_PtItemList*)&(reinterpret_cast<Unk_PtItemList&>(m_kListD48)))->RemoveAll();
    if (m_pSourcePC != 0)
    {
        ATL::CAtlList<MS2Ptr<CEquipItem> > kEquips(10);
        FUN_1411e1b80(m_pSourcePC->FUN_1416561a0(), kEquips);
        for (POSITION pos = kEquips.GetHeadPosition(); pos != 0; kEquips.GetNext(pos))
        {
            MS2Ptr<CEquipItem> spEquip = kEquips.GetAt(pos);
            if (spEquip.IsNull())
                continue;
            MS2Ptr<CItem> spItem = spEquip->GetItem();
            if (spItem.get() != 0)
            {
                MS2Ptr<CItem> spCopy = FUN_140ccac60(spItem);
                if (spCopy.get() != 0)
                {
                    spCopy->FUN_140526b30(FUN_14123c580());
                    FUN_141653d10(spCopy);
                }
            }
        }
        vfunc_143();
        Unk_MyPCEquip* pSrcEquip = m_pSourcePC->FUN_14165f460();
        FUN_14165f460()->FUN_141270e00(*pSrcEquip);
    }
    FUN_141087390();
    m_b12f8 = false;
}

// @0x141699fc0
void PortraitPC::vfunc_147(UIModelView* pView)
{
    ClonePC::vfunc_147(pView);
    if (pView != 0)
        FUN_14169a5e0();
}

// @0x14169a000
void PortraitPC::vfunc_33(int nClass, int n)
{
    if (nClass == 0x6200004)
        FUN_1410873b0();
}

// @0x14169a040
void PortraitPC::vfunc_14()
{
    ((Unk_ItemEventSystem*)(Unk_PtItemEvents*)(FUN_140a6a840()))->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_140939a10()->UnregisterNotify(L"NotifyChangeActiveMyCodiTab", Delegate<void(NotifyObject*)>(this, &PortraitPC::FUN_14169a710));
}

// @0x14169a160
PortraitPC::PortraitPC(PC* pSource)
    : ClonePC(pSource)
{
    FUN_141088640(false);
    m_unk_a50 = 0;
}

// @0x14169a200
int PortraitPC::vfunc_10()
{
    PC::vfunc_10();
    vfunc_149();
    vfunc_109(0);
    PC* pMyPC = ((PC*)((WorldService*)(Unk_PtWorld*)(FUN_1403ed2d0()))->FUN_141bd0cc0());
    if (pMyPC != 0 && m_pSourcePC != 0)
    {
        if (m_pSourcePC->FUN_14123c580() == pMyPC->FUN_14123c580())
        {
            FUN_140939a10()->RegisterNotify(L"NotifyChangeActiveMyCodiTab", Delegate<void(NotifyObject*)>(this, &PortraitPC::FUN_14169a710));
            ((Unk_ItemEventSystem*)(Unk_PtItemEvents*)(FUN_140a6a840()))->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
        }
    }
    return 1;
}

// @0x14169a3d0
void PortraitPC::vfunc_143()
{
    ((class CEquipment*)(struct Unk_PCEquipSet*)(&m_kEquipDE0))->FUN_1411e3de0(1);
    for (unsigned __int64 i = 0; i < ((ATL::CAtlArray<MS2Ptr<CItem>, ATL::CElementTraits<MS2Ptr<CItem>>>*)(Unk_PtItemList*)&(reinterpret_cast<Unk_PtItemList&>(m_kListD48)))->GetCount(); i++)
    {
        MS2Ptr<CEquipItem> spEquip = reinterpret_cast<Unk_PtItemList&>(m_kListD48).FUN_140c3c720(i);
        if (spEquip.get() != 0)
            FUN_1411e3600(&m_kEquipDE0, MS2Ptr<CEquipItem>(spEquip));
    }
    vfunc_139();
    ((ATL::CAtlArray<MS2Ptr<CItem>, ATL::CElementTraits<MS2Ptr<CItem>>>*)(Unk_PtItemList*)&(reinterpret_cast<Unk_PtItemList&>(m_kListD48)))->RemoveAll();
    FUN_141653f00();
}

// @0x14169a4f0
void PortraitPC::vfunc_53(float f)
{
    PC::vfunc_53(f);
    if (m_b12f8)
        vfunc_149();
    FUN_141087770();
    if (m_b12f9 && (static_cast<UIModelView*>(m_spModelView) ? true : false))
    {
        if (m_spModelView->FUN_141ab7660() == 0 || m_unk_1318.FUN_140268870(500) != 0)
            FUN_14169a5e0();
    }
    FUN_141087790();
}

// @0x14169a5e0
void PortraitPC::FUN_14169a5e0()
{
    if (static_cast<UIModelView*>(m_spModelView) == 0)
        return;
    if (FUN_141656750() == 0)
        return;
    ATL::CAtlArray<efd::SmartPointer<NiActorManager> > kEquip;
    FUN_1410879c0(kEquip);
    m_spModelView->vfunc_11(kEquip);
    if (m_pSourcePC != 0)
        FUN_14166ef10(m_pSourcePC->FUN_14166f740(), 1, 1, 0);
    m_b12f9 = false;
}

// @0x14169a710
void PortraitPC::FUN_14169a710(NotifyObject*)
{
    FUN_1410873b0();
}

// @0x14169a740
void PortraitPC::vfunc_21(void*)
{
    FUN_1410873b0();
}

// @0x14169a770
void PortraitPC::vfunc_22(void*)
{
    FUN_1410873b0();
}

// @0x14169a7a0
void PortraitPC::vfunc_24(void*)
{
    FUN_1410873b0();
}

// @0x14169a7d0
void PortraitPC::vfunc_25(void*)
{
    FUN_1410873b0();
}

// @0x14169a800
void PortraitPC::vfunc_30(void*)
{
    FUN_1410873b0();
}

// @0x14169a830
void PortraitPC::vfunc_31(void*)
{
    FUN_1410873b0();
}

// @0x14169a860
Unk_PtVec3 FUN_14169a860()
{
    PC* pMyPC = ((PC*)((WorldService*)(Unk_PtWorld*)(FUN_1403ed2d0()))->FUN_141bd0cc0());
    if (pMyPC != 0)
    {
        efd::Point3 kLook(0.0f, -1.0f, 0.0f);
        efd::Point3 kDir;
        efd::Point3 kSide;
        pMyPC->vfunc_67(&kDir, &kSide);
        float fZ = pMyPC->FUN_14166dad0(kLook, kSide);
        return Unk_PtVec3(0.0f, 0.0f, fZ);
    }
    return Unk_PtVec3(DAT_143b01a60);
}

// The CRT's memmove_s (static inline in corecrt_memcpy_s.h) sits in this unit's range; referencing it instantiates it.
void Unk_PortraitPCMoveAnchor(void* pDst, size_t nDst, void* pSrc, size_t nSrc)
{
    memmove_s(pDst, nDst, pSrc, nSrc);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb43f0-0x142cb4480 .text$yd
