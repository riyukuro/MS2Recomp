// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The actor's gem equipment (PCGemEquip) and the gem packet
// requests (equip / unequip, packet 0x47). Second TU of the gem page's code, after gemslot.cpp.
// MS2-UNIT: ?\gemslot.cpp#2
// MS2-RANGE: 0x14126fce0-0x141272630 .text$mn
// MS2-RANGE: 0x1400eb080-0x1400eb270 .text$di
// MS2-PIN: ??0?$MS2Ptr@VCGemBase@@@@QEAA@$$QEAV0@@Z 0x141272250 ; hand: the identical move ctor emitted for this TU
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gemslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/commonfiles/stream.h"
#include "hook/ms2hook.h"

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

enum Unk_GemSlot { Unk_GemSlot_0 };
static ATL::CAtlMap<Unk_GemSlot, unsigned> s_mapGemSlots;                                      // 0x143ad5fb0
static CStringW s_useBindGemEquipItem = L"useBindGemEquipItem";                                 // 0x143ad5fa8

class Unk_ItemEquipData : public CItemData { };         // CItem::FUN_140527840's record

// ---- out-of-unit callees ----
class Unk_GmActor : public PC
{
public:
};
class Unk_GmWorld
{
public:
    Unk_GmActor* FUN_141bd0cc0();                       // the local player's actor
    void FUN_1411a5110(CString strCategory, CString strName, CString strExtra, int nKind, void* pXform, float fVolume,
        int nOwner);                                    // play a sound event
    int FUN_1411a49c0(NoticeMessage& kQuery);           // spawn an effect, returns the handle
    void FUN_1411a6060(int nHandle);                    // stop it
};
Unk_GmWorld* FUN_1403ed2d0();
Unk_GmWorld* FUN_1403ed280();                           // the effect / sound service

class Unk_GemSkins
{
public:
    void FUN_140d329e0(unsigned nId, MS2Ptr<CItem> spItem);                  // register a skin gem item
    void FUN_140d32c20(unsigned nId, MS2Ptr<CItem> spItem, int nFlag);       // unregister it
};
Unk_GemSkins* FUN_1411f91b0();

class Unk_GemBinding
{
public:
    unsigned FUN_140635100();                           // m_nRule & 8
    int FUN_140635120();                                // has a binding
};
Unk_GemBinding* FUN_140527930(CItem* pItem);

class Unk_WsPtred298 : public CPtred
{
public:
    char m_pad[0x152 - 0x18];
    char m_bFlag152;
};
struct Unk_GsWorld { MS2Ptr<Unk_WsPtred298> FUN_141bd30a0(); }; // the world's field record
bool FUN_140222e10(int nGemType);                       // the gem type is valid
unsigned __int64 FUN_140222f50();                            // the count of the gem types
void FUN_140d73bc0(int, int, void*, CStringW);
CStringW FUN_1405c2690(CStringW, CStringW);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_140710590(COutPacket&);
void FUN_1401fd190(unsigned char* payload, COutputStream& stream);
void FUN_1401fd250(unsigned char* payload, COutputStream& stream);

struct Unk_GemItemWire
{
    Unk_GemItemWire();                                  // 0x141272280
    MS2Ptr<CItem> FUN_1401fce40(CInputStream& stream);  // read an item
};

// @0x14126fce0
PCGemEquip::PCGemEquip()
    : m_mapEffect(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_items.SetCount(FUN_140222f50(), -1);
}

// @0x14126fd70
PCGemEquip::~PCGemEquip()
{
    FUN_141271500(FUN_141271290(10));
    FUN_141271500(FUN_141271290(7));
    FUN_141271500(FUN_141271290(11));
    FUN_141271500(FUN_141271290(12));
    m_items.RemoveAll();
}

// @0x14126fea0
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
void PCGemEquip::FUN_14126fea0(CInputStream& stream, int nOwner)
{
    int nCount = stream.vfunc_o8_1();
    Unk_GemItemWire kWire;
    for (int i = 0; i < nCount; i++)
    {
        MS2Ptr<CItem> spItem = kWire.FUN_1401fce40(stream);
        if (!(spItem == 0))
        {
            if (spItem->FUN_140527900() != 0)
            {
                spItem->FUN_140526b30(nOwner);
                int nGemType = spItem->FUN_140527900()->vfunc_1();
                FUN_141270030(nGemType, spItem);
                FUN_141271780(nGemType, spItem);
            }
        }
    }
}

// @0x141270030
void PCGemEquip::FUN_141270030(int nGemType, MS2Ptr<CItem> spItem)
{
    int nIndex = FUN_141271290(nGemType);
    FUN_1412716d0(nIndex, spItem);
}

// @0x1412700b0
unsigned PCGemEquip::FUN_1412700b0()
{
    return (unsigned)m_items.GetCount();
}

// @0x1412700e0
int PCGemEquip::FUN_1412700e0(ATL::CAtlArray<MS2Ptr<CItem> >& out)
{
    out.Copy(m_items);
    return out.GetCount() > 0;
}

// @0x141270140
MS2Ptr<CItem> PCGemEquip::FUN_141270140(int nGemType)
{
    if (!FUN_140222e10(nGemType))
        return MS2Ptr<CItem>(0);
    int nIndex = FUN_141271290(nGemType);
    MS2Ptr<CItem> spItem = FUN_141271630(nIndex);
    if (spItem == 0 || spItem->FUN_140527840() == 0)
        return MS2Ptr<CItem>(0);
    if (spItem->FUN_140527840()->FUN_14053e900() != nGemType)
        return MS2Ptr<CItem>(0);
    return spItem;
}

// @0x141270290
bool PCGemEquip::FUN_141270290(int nItemId)
{
    size_t nCount = m_items.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CItem> spItem = m_items.GetAt(i);
        if (spItem.get() != 0)
        {
            if (spItem->FUN_1405276c0() == nItemId)
                return true;
        }
    }
    return false;
}

// @0x141270360
CGemTransparency* PCGemEquip::FUN_141270360(unsigned char nIndex)
{
    CItem* pItem = FUN_141271630(nIndex).get();
    if (pItem == 0)
        return 0;
    if (pItem->FUN_140527900() == 0)
        return 0;
    CGemBase* pGem = pItem->FUN_140527900()->FUN_140d41400().get();
    if (pGem == 0)
        return 0;
    if (pGem->vfunc_1() != 1)
        return 0;
    return static_cast<CGemTransparency*>(pGem);
}

// @0x141270460
CGemTransparency* PCGemEquip::FUN_141270460()
{
    int nCount = (int)m_items.GetCount();
    for (unsigned char i = 0; i < nCount; i++)
    {
        CGemTransparency* pGem = FUN_141270360(i);
        if (pGem != 0)
            return pGem;
    }
    return 0;
}

// @0x1412704d0
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
void PCGemEquip::FUN_1412704d0()
{
    unsigned char nCount = (unsigned char)m_items.GetCount();
    for (unsigned char i = 0; i < nCount; i++)
    {
        MS2Ptr<CItem> spItem = FUN_141271630(i);
        if (!(spItem == 0))
        {
            if (spItem->FUN_140527900() != 0)
            {
                if (m_pOwner->FUN_141662eb0(spItem.get()) != 0)
                    spItem->FUN_140527900()->vfunc_5(m_pOwner, spItem);
            }
        }
    }
}

// @0x141270610
void PCGemEquip::FUN_141270610()
{
    unsigned char nCount = (unsigned char)m_items.GetCount();
    for (unsigned char i = 0; i < nCount; i++)
        FUN_1412712e0(i);
}

// @0x141270680
void PCGemEquip::FUN_141270680()
{
    int nCount = (int)m_items.GetCount();
    for (unsigned char i = 0; i < nCount; i++)
        FUN_141271500(i);
}

// @0x1412706f0
int PCGemEquip::FUN_1412706f0(int nSlot)
{
    CGemTransparency* pGem = FUN_141270460();
    if (pGem == 0)
        return 0;
    return pGem->FUN_1405a4140(nSlot);
}

// @0x141270740
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
MS2Ptr<CGemBase> PCGemEquip::FUN_141270740(int nGemType)
{
    if (m_items.IsEmpty())
        return MS2Ptr<CGemBase>(0);
    CItem* pItem = FUN_141270140(nGemType).get();
    if (pItem == 0)
        return MS2Ptr<CGemBase>(0);
    if (m_pOwner->FUN_141662eb0(pItem) == 0)
        return MS2Ptr<CGemBase>(0);
    CItemGem* pGem = pItem->FUN_140527900();
    bool bNone = true;
    if (pGem != 0)
    {
        MS2Ptr<CGemBase> spGem = pGem->FUN_140d41400();
        bNone = (spGem == 0);
    }
    if (bNone)
        return MS2Ptr<CGemBase>(0);
    MS2Ptr<CGemBase> spResult = pGem->FUN_140d41400();
    if (spResult->vfunc_1() == nGemType)
        return spResult;
    return MS2Ptr<CGemBase>(0);
}

// @0x1412709d0
MS2Ptr<CItem> PCGemEquip::FUN_1412709d0(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || spItem->FUN_140527900() == 0)
        return MS2Ptr<CItem>(0);
    int nGemType = spItem->FUN_140527900()->vfunc_1();
    return FUN_141270ab0(nGemType);
}

// @0x141270ab0
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
MS2Ptr<CItem> PCGemEquip::FUN_141270ab0(int nGemType)
{
    int nIndex = FUN_141271290(nGemType);
    MS2Ptr<CItem> spItem = FUN_141271500(nIndex);
    if (spItem.get() == 0)
        return MS2Ptr<CItem>(0);
    FUN_141271870(nGemType, spItem);
    FUN_1412716d0(nIndex, MS2Ptr<CItem>(0));
    return spItem;
}

// @0x141270bf0
bool PCGemEquip::FUN_141270bf0(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || spItem->FUN_140527900() == 0)
        return false;
    int nGemType = spItem->FUN_140527900()->vfunc_1();
    FUN_141270cd0(nGemType, spItem);
    return true;
}

// @0x141270cd0
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
bool PCGemEquip::FUN_141270cd0(int nGemType, MS2Ptr<CItem> spItem)
{
    int nIndex = FUN_141271290(nGemType);
    FUN_1412716d0(nIndex, spItem);
    CItem* pItem = FUN_1412712e0(nIndex).get();
    if (pItem != 0)
        FUN_141271780(nGemType, spItem);
    return pItem != 0;
}

// @0x141270e00
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
void PCGemEquip::FUN_141270e00(PCGemEquip& other)
{
    unsigned nCount = other.FUN_1412700b0();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CItem> spItem = other.FUN_141271630((int)i);
        if (!spItem.IsNull())
        {
            MS2Ptr<CItem> spCopy = spItem->FUN_140524250();
            if (spCopy.get() != 0)
                FUN_1412716d0((int)i, spCopy);
        }
    }
}

// @0x141270f10
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
void PCGemEquip::FUN_141270f10(ATL::CAtlArray<MS2Ptr<CItem> >& items, int nOwner)
{
    if (!items.IsEmpty())
    {
        size_t nCount = items.GetCount();
        for (size_t i = 0; i < nCount; i++)
        {
            MS2Ptr<CItem> spItem = items[i];
            if (spItem.get() != 0)
            {
                MS2Ptr<CItemGem> spGem(spItem->FUN_140527900());
                if (spGem.get() != 0)
                {
                    spItem->FUN_140526b30(nOwner);
                    FUN_141270030(spGem->vfunc_1(), spItem);
                }
            }
        }
    }
}

// @0x141271090
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
bool PCGemEquip::FUN_141271090(MS2Ptr<CItem> spItem, const CString& strEffect)
{
    if (m_mapEffect.Lookup(spItem->FUN_140526a50()) == 0)
    {
        NoticeMessage kQuery;
        kQuery.m_strName = strEffect;
        kQuery.m_nObject = 0;
        kQuery.SetActor(m_pOwner->FUN_14123c580());
        int nHandle = FUN_1403ed280()->FUN_1411a49c0(kQuery);
        if (nHandle == 0)
            return false;
        m_mapEffect[spItem->FUN_140526a50()] = nHandle;
        return true;
    }
    return false;
}

// @0x1412711e0
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
void PCGemEquip::FUN_1412711e0(MS2Ptr<CItem> spItem)
{
    int nHandle = 0;
    if (m_mapEffect.Lookup(spItem->FUN_140526a50(), nHandle))
    {
        if (nHandle != 0)
            FUN_1403ed280()->FUN_1411a6060(nHandle);
        m_mapEffect.RemoveKey(spItem->FUN_140526a50());
    }
}

// @0x141271290
int PCGemEquip::FUN_141271290(int nGemType)
{
    if (nGemType == 0)
        return -1;
    int nIndex;
    if (nGemType - 1 < 0)
        nIndex = 0;
    else
        nIndex = nGemType - 1;
    return nIndex;
}

// @0x1412712e0
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
MS2Ptr<CItem> PCGemEquip::FUN_1412712e0(int nIndex)
{
    MS2Ptr<CItem> spItem = FUN_141271630(nIndex);
    if (spItem == 0 || spItem->FUN_140527900() == 0)
        return MS2Ptr<CItem>(0);
    if (m_pOwner->FUN_141662eb0(spItem.get()) == 0)
        return MS2Ptr<CItem>(0);
    char bFlag = reinterpret_cast<Unk_GsWorld*>(FUN_1403ed2d0())->FUN_141bd30a0()->m_bFlag152;
    if (bFlag == 0)
        return MS2Ptr<CItem>(0);
    spItem->FUN_140527900()->vfunc_6(m_pOwner, spItem);
    return spItem;
}

// @0x141271500
MS2Ptr<CItem> PCGemEquip::FUN_141271500(int nIndex)
{
    MS2Ptr<CItem> spItem = FUN_141271630(nIndex);
    if (spItem == 0 || spItem->FUN_140527900() == 0)
        return MS2Ptr<CItem>(0);
    spItem->FUN_140527900()->vfunc_7(m_pOwner, spItem);
    return spItem;
}

// @0x141271630
MS2Ptr<CItem> PCGemEquip::FUN_141271630(int nIndex)
{
    if (nIndex < 0 || nIndex >= (int)m_items.GetCount())
        return MS2Ptr<CItem>(0);
    return m_items[nIndex];
}

// @0x1412716d0
void PCGemEquip::FUN_1412716d0(int nIndex, MS2Ptr<CItem> spItem)
{
    if (nIndex < 0 || nIndex >= (int)m_items.GetCount())
        return;
    m_items.SetAt(nIndex, spItem);
}

// @0x141271750
bool PCGemEquip::FUN_141271750(int nGemType)
{
    if (nGemType == 5 || nGemType == 6)
        return true;
    return false;
}

// @0x141271780
void PCGemEquip::FUN_141271780(int nGemType, MS2Ptr<CItem> spItem)
{
    if (!FUN_141271750(nGemType))
        return;
    unsigned nId = spItem->FUN_140526b10();
    if (nId < 10000)
        return;
    FUN_1411f91b0()->FUN_140d329e0(spItem->FUN_140526b10(), spItem);
}

// @0x141271870
void PCGemEquip::FUN_141271870(int nGemType, MS2Ptr<CItem> spItem)
{
    if (!FUN_141271750(nGemType))
        return;
    unsigned nId = spItem->FUN_140526b10();
    if (nId < 10000)
        return;
    FUN_1411f91b0()->FUN_140d32c20(spItem->FUN_140526b10(), spItem, 1);
}

// @0x141271960
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
bool FUN_141271960(MS2Ptr<CItem> spItem, int nSlot, int nFlag)
{
    if (!(spItem == 0))
    {
        Unk_GmActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pActor == 0)
            return false;
        if (pActor->FUN_14166ce30() == 0)
        {
            if (nFlag == 0)
            {
                if (FUN_140527930(spItem.operator->())->FUN_140635100() != 0
                    && FUN_140527930(spItem.operator->())->FUN_140635120() == 0)
                {
                    CStringW strMsg = FUN_1405c2690(L"s_msg_transfer_bind_when_equip", pActor->vfunc_77());
                    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(17, strMsg, 0, s_useBindGemEquipItem);
                    if (spBox.get() != 0)
                    {
                        spBox->FUN_140533ff0(nSlot);
                        spBox->FUN_141a01600(spItem->FUN_140526a50());
                        spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
                        spBox->FUN_141a01700(1143, 1144, 0);
                        FUN_140d73c60(spBox);
                        return true;
                    }
                }
            }
            Unk_GemEquipReq kReq;
            kReq.m_nItemUid = spItem->FUN_140526a50();
            kReq.m_nSlot = (unsigned char)nSlot;
            COutPacket kPacket(0x47, 0);
            kPacket.vfunc_o10_1(0);
            FUN_1401fd190((unsigned char*)&kReq, kPacket);
            FUN_140710590(kPacket);
            MS2Ptr<CItemData> spData(spItem->FUN_140527840());
            if (spData.get() != 0)
                FUN_1403ed280()->FUN_1411a5110("ms2sound/sound/item", spData->FUN_14053eca0(), "", 0, 0, 1.0f, 0);
            return true;
        }
        FUN_140d73bc0(0x42, 0, 0, L"");
        return false;
    }
    return false;
}

// @0x141271f90
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
bool FUN_141271f90(MS2Ptr<CItem> spItem)
{
    if (!(spItem == 0))
    {
        Unk_GmActor* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pActor == 0)
            return false;
        if (pActor->FUN_14166ce30() == 0)
        {
            Unk_GemUnequipReq kReq;
            kReq.m_nSlot = (unsigned char)spItem->FUN_140526b50();
            COutPacket kPacket(0x47, 0);
            kPacket.vfunc_o10_1(1);
            FUN_1401fd250((unsigned char*)&kReq, kPacket);
            FUN_140710590(kPacket);
            MS2Ptr<CItemData> spData(spItem->FUN_140527840());
            if (spData.get() != 0)
                FUN_1403ed280()->FUN_1411a5110("ms2sound/sound/item", spData->FUN_14053eca0(), "", 0, 0, 1.0f, 0);
            return true;
        }
        FUN_140d73bc0(0x42, 0, 0, L"");
        return false;
    }
    return false;
}

// @0x141272280
Unk_GemItemWire::Unk_GemItemWire()
{
}

// @0x141272290
Unk_GemUnequipReq::Unk_GemUnequipReq()
{
    m_nSlot = 0;
}

// @0x1412722b0
Unk_GemEquipReq::Unk_GemEquipReq()
{
    m_nItemUid = 0;
    m_nSlot = 0;
}

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
#pragma function(memcpy, memset)
// @0x1412723c0
// MS2-FUNCTIONAL: same behaviour; MS2Ptr temporaries/block layout differ from the exe
static __inline errno_t ms2_gem_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnGemMemcpyS)(void*, size_t, const void*, size_t) = &ms2_gem_memcpy_s;
#pragma intrinsic(memcpy, memset)
