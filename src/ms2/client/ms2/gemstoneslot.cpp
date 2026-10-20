// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GemStoneSlot and GemStoneSlotBag: the socket slots of the
// gemstone manage page (ItemSocketSystemPageGemStoneManage), plus the gfxutil.h helpers that set the text of a named
// child of a movie, and ItemInfoSlot::SetupClassInfo (first needed here).
// MS2-UNIT: ?\gemstoneslot.cpp
// MS2-RANGE: 0x140cfd6f0-0x140cff310 .text$mn
// MS2-RANGE: 0x1400d19f0-0x1400d1bc9 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetAt@?$CAtlArray@V?$MS2Ptr@VCGemStoneItem@@@@V?$CElementTraits@V?$MS2Ptr@VCGemStoneItem@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCGemStoneItem@@@@_K@Z 0x140cfea30 ; unique
// MS2-PIN: ?GetClassDesc@GemStoneSlot@@UEBAPEBVClassInfo@efd@@XZ 0x140cfea70 ; prop
// MS2-PIN: ?GetClassDesc@GemStoneSlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x140cfea80 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlArray@V?$MS2Ptr@VCGemStoneItem@@@@V?$CElementTraits@V?$MS2Ptr@VCGemStoneItem@@@@@ATL@@@ATL@@QEBA_NXZ 0x140cfeaa0 ; unique
// MS2-PIN: ?TypeCast@GemStoneSlotBag@@UEBA_NIPEAPEAX@Z 0x140cfeca0 ; unique
// MS2-PIN: ?TypeCast@GemStoneSlotBag@@UEBA_NIPEAPEBX@Z 0x140cfecf0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVGemStoneSlot@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140cfeda0 ; unique
// MS2-PIN: ??$Call@VGemStoneSlot@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVGemStoneSlot@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVGemStoneSlot@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140cfede0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7GemStoneSlot@@6BBindData@NotifyContext@@@ 0x142e249d0 ; hand: primary vftable
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gemstoneslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gemstoneslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
// Game context: FUN_141bd0cc0 returns the local player.
class Unk_GemGameCtx
{
public:
    void* FUN_141bd0cc0();
};
Unk_GemGameCtx* FUN_1403ed2d0();

// The gemstone confirm box (itemsocketsystemutil.cpp).
bool FUN_14062a3d0(MS2Ptr<CItem> spItem, int nSlot, MS2Ptr<CItem> spGem, Delegate<bool(int, const CMsgBoxData&)> cb);
bool FUN_14062abb0(MS2Ptr<CItem> spItem, const CMsgBoxData& box);
CStringW FUN_14062ad80(MS2Ptr<CItem> spItem);               // the gemstone description of an item

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);                      // clear the bag's slots

bool FUN_1409b4d40(const Scaleform::GFx::Value& v);         // the value is an object

// gfxutil.h: a Value wrapped as a display object container (ctor 0x1422c6570 with the movie id, dtor 0x1422c65c0) and
// the child lookups instantiated per wrapper type.
class Unk_GemText : public ASTextField {};
class Unk_GemClip : public ASMovieClip
{
public:
    MS2Ptr<Unk_GemText> FUN_140d01d30(const CString& strName);
};
class Unk_GemNode
{
public:
    Unk_GemNode(const Scaleform::GFx::Value& v, int nMovieId);
    ~Unk_GemNode();
    MS2Ptr<Unk_GemText> FUN_140bc7450(const CString& strName);
    MS2Ptr<Unk_GemClip> FUN_140d01d80(const CString& strName);
private:
    void* m_pad[0x88 / sizeof(void*)];
};
MS2_CHECK_SIZE(Unk_GemNode, 0x88);

// ---- dynamic initializers (.text$di) ----

// @0x1400d19f0
EE_IMPLEMENT_CONCRETE_CLASS_INFO(GemStoneSlot);
// @0x1400d1a10
EE_IMPLEMENT_CONCRETE_CLASS_INFO(GemStoneSlotBag);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"
// @0x1400d1ba0
static CString s_strSkill2("skill");

// ---- GemStoneSlot ----

// @0x140cfd6f0
void FUN_140cfd6f0(const CString& strName, MS2Ptr<CGemStoneItem> spGem, int nIndex, int nIconType, int nFlags)
{
    GemStoneSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) GemStoneSlot(strName, spGem, nIndex, nIconType, nFlags);
    if (pSlot)
        FUN_1422c8f10(strName, pSlot);
}

GemStoneSlot* FUN_140cfe620(NotifyContext::BindData* p);
GemStoneSlotBag* FUN_140cfe670(NotifyContext::BindData* p);
ItemInfoSlot* FUN_140cfe6c0(NotifyContext::BindData* p);

// @0x140cfd800
void FUN_140cfd800(const CString& strName)
{
    GemStoneSlot* pSlot = FUN_140cfe620(FUN_1422c8e90(strName));
    if (pSlot)
        FUN_1422c8f70(strName);
}

// @0x140cfd840
GemStoneSlot::GemStoneSlot(const CString& strName, MS2Ptr<CGemStoneItem> spGem, int nIndex, int nIconType, int nFlags)
    : ItemInfoSlot(strName, MS2Ptr<CItem>(0), nIndex, nIconType, nFlags)
{
    SetGem(spGem);
}

// @0x140cfe8b0
GemStoneSlot::~GemStoneSlot()
{
}

// @0x140cfd950
void GemStoneSlot::SetGem(MS2Ptr<CGemStoneItem> spGem)
{
    m_spGem = spGem;
    if (m_spGem.get() == 0)
        SetItem(MS2Ptr<CItem>(0));
    else
        SetItem(MS2Ptr<CItem>(m_spGem->m_gemstone));
}

// @0x140cfda30
int GemStoneSlot::vfunc_8(void* p)
{
    if (m_spGem == 0)
        return 0;
    ASSlot slot(2);
    MS2Ptr<CItem> spItem = m_spItem;
    bool bLocked = m_spGem->GetLocked();
    if (spItem == 0)
    {
        FUN_140cfdc70(&slot, bLocked);
    }
    else if (!slot.FUN_1409c3860(spItem.get(), FUN_1403ed2d0()->FUN_141bd0cc0(), m_nIconType))
    {
        return 0;
    }
    FUN_140cfdcb0(&slot, spItem, bLocked);
    *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
    return 1;
}

// @0x140cfdbe0
int GemStoneSlot::vfunc_18(void* pv)
{
    DragSlot* p = static_cast<DragSlot*>(pv);
    if (p == 0)
        return 1;
    ItemInfoSlot* pSrc = FUN_140cfe6c0(p);
    if (pSrc != 0)
        FUN_140cfddf0(pSrc->vfunc_25());
    return p->vfunc_10();
}

// @0x140cfdc70
void GemStoneSlot::FUN_140cfdc70(ASSlot* pSlot, bool bLocked)
{
    pSlot->FUN_1407cbbe0("lock", bLocked);
}

// @0x140cfdcb0
void GemStoneSlot::FUN_140cfdcb0(ASSlot* pSlot, MS2Ptr<CItem> spItem, bool bLocked)
{
    CStringW strText;
    if (spItem.get() == 0)
    {
        if (!bLocked)
            strText = L"$s_itemsocketsystem_gemstonemanage_msg_socket_empty";
        else
            strText = L"$s_itemsocketsystem_gemstonemanage_msg_socket_lock";
    }
    else
    {
        strText = FUN_14062ad80(spItem);
    }
    pSlot->FUN_1407cbb20("text", strText);
}

// @0x140cfddf0
void GemStoneSlot::FUN_140cfddf0(MS2Ptr<CItem> spGemItem)
{
    if (spGemItem == 0)
        return;
    if (m_spGem == 0)
        return;
    if (m_spGem->m_equipment == 0)
        return;
    MS2Ptr<CItem> spEquip = m_spGem->m_equipment;
    FUN_14062a3d0(spEquip, FUN_1422cc410(), spGemItem,
                  Delegate<bool(int, const CMsgBoxData&)>(this, &GemStoneSlot::FUN_140cfdfe0));
}

// @0x140cfdfe0
bool GemStoneSlot::FUN_140cfdfe0(int nButton, const CMsgBoxData& box)
{
    if (m_spGem != 0 && m_spGem->m_equipment != 0)
    {
        if (nButton == 0)
        {
            MS2Ptr<CItem> spEquip = m_spGem->m_equipment;
            FUN_14062abb0(spEquip, box);
        }
    }
    return true;
}

// ---- GemStoneSlotBag ----

// @0x140cfe0c0
void FUN_140cfe0c0(const CString& strName, int nCount, void* pSockets, GemStoneSlotBag::GetGemFn pfnGetGem, int nIconType, int nFlags)
{
    GemStoneSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) GemStoneSlotBag(strName, pSockets, pfnGetGem, nIconType, nFlags);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140cfe1b0
void FUN_140cfe1b0(const CString& strName)
{
    GemStoneSlotBag* pBag = FUN_140cfe670(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x140cfe200
GemStoneSlotBag::GemStoneSlotBag(const CString& strName, void* pSockets, GetGemFn pfnGetGem, int nIconType, int nFlags)
    : DragSlotBag(strName), m_pfnGetGem(pfnGetGem), m_pSockets(pSockets), m_nIconType(nIconType), m_nFlags(nFlags)
{
}

// @0x140cfe290
GemStoneSlotBag::~GemStoneSlotBag()
{
}

// @0x140cfe2c0
DragSlot* GemStoneSlotBag::vfunc_16(int nIndex)
{
    CString strName = vfunc_15(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) GemStoneSlot(strName, m_pfnGetGem(m_pSockets, nIndex), nIndex, m_nIconType, m_nFlags);
}

// The socket record at nIndex of the array the bag was created over (a null record when out of range).
// @0x140cfe450
MS2Ptr<CGemStoneItem> FUN_140cfe450(void* pSockets, int nIndex)
{
    ATL::CAtlArray<MS2Ptr<CGemStoneItem> >* pArray = static_cast<ATL::CAtlArray<MS2Ptr<CGemStoneItem> >*>(pSockets);
    if (!pArray->IsEmpty() && nIndex < (int)pArray->GetCount())
        return pArray->GetAt(nIndex);
    return MS2Ptr<CGemStoneItem>(0);
}

// ---- BindData casts ----

// @0x140cfe620
GemStoneSlot* FUN_140cfe620(NotifyContext::BindData* p)
{
    GemStoneSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200030, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x140cfe670
GemStoneSlotBag* FUN_140cfe670(NotifyContext::BindData* p)
{
    GemStoneSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200030, (void**)&pBag))
        return pBag;
    else
        return 0;
}

// @0x140cfe6c0
ItemInfoSlot* FUN_140cfe6c0(NotifyContext::BindData* p)
{
    ItemInfoSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x620002f, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// ---- gfxutil.h: set the text of a named child of a movie ----

// @0x140cfee80
// MS2-FUNCTIONAL: gfxutil.h template instance written against unit-local node views
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<Unk_GemText> spText = node.FUN_140bc7450(strName);
    if (spText == 0)
        return;
    static_cast<ASObj*>(static_cast<AScript*>(spText.get()))->FUN_1407cbb20("text", strText);
}

// @0x140cfefe0
// MS2-FUNCTIONAL: gfxutil.h template instance written against unit-local node views
void FUN_140cfefe0(const Scaleform::GFx::Value& root, CString strClip, CString strName, CStringW strText)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<Unk_GemClip> spClip = node.FUN_140d01d80(strClip);
    if (spClip == 0)
        return;
    MS2Ptr<Unk_GemText> spText = spClip->FUN_140d01d30(strName);
    if (spText.get() != 0)
        static_cast<ASObj*>(static_cast<AScript*>(spText.get()))->FUN_1407cbb20("text", strText);
}

// @0x140cff1b0
// MS2-FUNCTIONAL: gfxutil.h template instance written against unit-local node views
void FUN_140cff1b0(const Scaleform::GFx::Value& root, CString strName, CStringW strText)
{
    if (!FUN_1409b4d40(root))
        return;
    Unk_GemNode node(root, 2);
    MS2Ptr<Unk_GemClip> spClip = node.FUN_140d01d80(strName);
    if (spClip == 0)
        return;
    static_cast<ASObj*>(static_cast<AScript*>(spClip.get()))->FUN_1407cbb20("htmlText", strText);
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca4750-0x142ca4800 .text$yd
