// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Equipment icon container (slot -> ASEquipIcon map and the
// "equipItem" / "changeEquipItem" / "unEquipItem" calls into its movie clip). See uiequipiconcontainer.h.
// MS2-UNIT: client\ms2\uiequipiconcontainer.cpp
// MS2-RANGE: 0x140e29f60-0x140e2cc90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??8?$MS2Ptr@VASEquipIcon@@@@QEBA_NPEAVASEquipIcon@@@Z 0x140e2b8e0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VASEquipIcon@@@@QEBAPEAVASEquipIcon@@XZ 0x140e2b970 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VASEquipIcon@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VASEquipIcon@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140e2bc30 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiequipiconcontainer.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <new>
#include "uiequipiconcontainer.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);          // Value = n (UInt)
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);   // Value = v (callee destroys)
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);           // Value = string
CString FUN_140719210(long n);

// Unit-local declarations; the unidentified names describe uses rather than original class names.
class Unk_ItemEquipData
{
public:
    bool FUN_14053d510();                                                   // the item may be worn in a hand slot
};
class Unk_EquipOutfit : public CPtred
{
public:
    void FUN_140cd3750(ATL::CAtlMap<int, MS2Ptr<CItem> >& mapItems);       // fills slot -> item
};
class Unk_EquipItemPtr
{
public:
    Unk_EquipItemPtr(const Unk_EquipItemPtr& o) : m_00(o.m_00), m_08(o.m_08) { if (m_08) CPtred::AddRefPtred(static_cast<CPtred*>(m_08)); }   // 0x1403bb3b0
    ~Unk_EquipItemPtr();                                                    // 0x1401b50d0
    Unk_ItemEquipData* FUN_1401b52a0() const;
    void* m_00; void* m_08;
};

// @0x140e29f60
UIEquipIconContainer::UIEquipIconContainer()
    : m_28(17, 0.75f, 0.25f, 2.25f, 10), m_70(0)
{
}

// @0x140e2a000
UIEquipIconContainer::~UIEquipIconContainer()
{
    m_18 = 0;
    m_28.RemoveAll();
}

// @0x140e2a090
MS2Ptr<ASEquipIcon> UIEquipIconContainer::FUN_140e2a090(int nSlot, MS2Ptr<CItem> pItem, MS2Ptr<AScript> pSrc, MS2Ptr<Unk_EquipOutfit> pOutfit)
{
    MS2Ptr<ASEquipIcon> pIcon = FUN_140e2a740(nSlot);
    if (pIcon == 0)
        pIcon = FUN_140e2a990(nSlot, pItem, pSrc);
    else
        pIcon = FUN_140e2ad70(pIcon, nSlot, pItem, pSrc);
    if (nSlot == 8 || nSlot == 9 || nSlot == 4 || nSlot == 5)
    {
        if (pOutfit == 0)
            return pIcon;
        int nOther = 0;
        if (nSlot == 8)
            nOther = 9;
        else if (nSlot == 9)
            nOther = 8;
        else if (nSlot == 4)
            nOther = 5;
        else if (nSlot == 5)
            nOther = 4;
        MS2Ptr<ASEquipIcon> pOther = FUN_140e2a740(nOther);
        if (pOther.get() != 0)
        {
            ATL::CAtlMap<int, MS2Ptr<CItem> > mapItems(17, 0.75f, 0.25f, 2.25f, 10);
            pOutfit->FUN_140cd3750(mapItems);
            bool bRemove = true;
            for (POSITION pos = mapItems.GetStartPosition(); pos != 0; mapItems.GetNext(pos))
            {
                MS2Ptr<CItem> pOne = mapItems.GetValueAt(pos);
                if (pOne == 0)
                    continue;
                if (((CItem*)pOne)->FUN_1405276c0() == pOther->FUN_1409b95a0())
                    bRemove = false;
            }
            if (bRemove)
            {
                FUN_140e2b140(nOther);
                pOther = 0;
            }
        }
        if ((bool)pItem.get() && ((CItem*)pItem)->FUN_140527840() && ((CItem*)pItem)->FUN_140527840()->FUN_14053d510())
            m_70 = nSlot;
    }
    return pIcon;
}

MS2_REPLACE_METHOD(0x140E2A090, UIEquipIconContainer, FUN_140e2a090, 1436, 0xC34A9A15);
// @0x140e2a640
void UIEquipIconContainer::FUN_140e2a640(int nSlot)
{
    FUN_140e2b140(nSlot);
}

MS2_REPLACE_METHOD(0x140E2A640, UIEquipIconContainer, FUN_140e2a640, 32, 0x531E2C2D);
// @0x140e2a670
void UIEquipIconContainer::FUN_140e2a670()
{
    m_28.RemoveAll();
    if (m_18.get() != 0)
        m_18->Invoke("unEquipAll");
}

MS2_REPLACE_METHOD(0x140E2A670, UIEquipIconContainer, FUN_140e2a670, 100, 0x7661BBFA);
// @0x140e2a6e0
void UIEquipIconContainer::FUN_140e2a6e0(int nVisible)
{
    if (m_18.get() != 0)
        m_18->vfunc_3(nVisible);
}

MS2_REPLACE_METHOD(0x140E2A6E0, UIEquipIconContainer, FUN_140e2a6e0, 82, 0xF786E9B1);
// @0x140e2a740
MS2Ptr<ASEquipIcon> UIEquipIconContainer::FUN_140e2a740(int nSlot)
{
    MS2Ptr<ASEquipIcon> pIcon(0);
    if (!m_28.IsEmpty())
        m_28.Lookup(nSlot, pIcon);
    return pIcon;
}

MS2_REPLACE_METHOD(0x140E2A740, UIEquipIconContainer, FUN_140e2a740, 145, 0xCB8B754A);
// @0x140e2a7e0
int UIEquipIconContainer::FUN_140e2a7e0(Unk_EquipItemPtr pItem)
{
    if (!pItem.FUN_1401b52a0()->FUN_14053d510())
        return 0;
    MS2Ptr<ASEquipIcon> pA = FUN_140e2a740(4);
    MS2Ptr<ASEquipIcon> pB = FUN_140e2a740(5);
    if (pA == 0 && pB == 0)
        return 5;
    if (pA == 0)
        return 4;
    if (pB == 0)
        return 5;
    return (m_70 == 4) ? 5 : 4;
}

// no MS2_REPLACE_METHOD: FUN_140e2a7e0 is overloaded (MS2Ptr<CItemData> spelling in uimeratmarketdialog), the hook macro cannot take &Class::Method
// @0x140e2a990
MS2Ptr<ASEquipIcon> UIEquipIconContainer::FUN_140e2a990(int nSlot, MS2Ptr<CItem> pItem, MS2Ptr<AScript> pSrc)
{
    if (pSrc == 0)
        return MS2Ptr<ASEquipIcon>(0);
    MS2Ptr<ASEquipIcon> pIcon(new ASEquipIcon(2));
    if (pIcon == 0)
        return MS2Ptr<ASEquipIcon>(0);
    pIcon->FUN_1409b9150(pSrc);
    pIcon->FUN_1409b91f0(pItem);
    m_28.SetAt(nSlot, pIcon);
    if (m_18.get() != 0)
    {
        Scaleform::GFx::Value vInfo = m_18->Invoke("equipItem", (unsigned int)nSlot, Scaleform::GFx::Value(pSrc->FUN_1422bb870()));
        MS2Ptr<ASUIComponent> pComp(new ASUIComponent(vInfo, 2));
        pIcon->FUN_1409b91a0(pComp);
    }
    return pIcon;
}

MS2_REPLACE_METHOD(0x140E2A990, UIEquipIconContainer, FUN_140e2a990, 976, 0x1FEF0C2F);
// @0x140e2ad70
MS2Ptr<ASEquipIcon> UIEquipIconContainer::FUN_140e2ad70(MS2Ptr<ASEquipIcon> pIcon, int nSlot, MS2Ptr<CItem> pItem, MS2Ptr<AScript> pSrc)
{
    if (pIcon == 0)
        return MS2Ptr<ASEquipIcon>(0);
    pIcon->FUN_1409b9150(pSrc);
    pIcon->FUN_1409b91f0(pItem);
    if ((bool)m_18.get() && (bool)pIcon->FUN_1409b92e0().get())
    {
        m_18->Invoke("changeEquipItem", Scaleform::GFx::Value(pIcon->FUN_1409b92e0()->FUN_1422bb870()), FUN_140719210(nSlot), Scaleform::GFx::Value(pSrc->FUN_1422bb870()));
    }
    return pIcon;
}

MS2_REPLACE_METHOD(0x140E2AD70, UIEquipIconContainer, FUN_140e2ad70, 962, 0x0958F663);
// @0x140e2b140
void UIEquipIconContainer::FUN_140e2b140(int nSlot)
{
    if (m_28.IsEmpty())
        return;
    MS2Ptr<ASEquipIcon> pIcon(0);
    if (m_28.Lookup(nSlot, pIcon))
    {
        MS2Ptr<ASUIComponent> pComp = pIcon->FUN_1409b92e0();
        if ((bool)m_18.get() && (bool)pComp.get())
            m_18->Invoke("unEquipItem", Scaleform::GFx::Value(pComp->FUN_1422bb870()));
        m_28.RemoveKey(nSlot);
    }
}

MS2_REPLACE_METHOD(0x140E2B140, UIEquipIconContainer, FUN_140e2b140, 395, 0x38131CDE);
// @0x140e2b2d0
// MS2-FUNCTIONAL: frame is 0x10 larger (the exe's ASArgList is 0x18 bytes; the shared asdata.h placeholder says 0x20)
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, unsigned int a1, Scaleform::GFx::Value a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140e2b3d0
// MS2-FUNCTIONAL: frame is 0x10 larger (the exe's ASArgList is 0x18 bytes; the shared asdata.h placeholder says 0x20)
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, CString a2, Scaleform::GFx::Value a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcc70(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
