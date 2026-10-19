// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIInteriorPreviewDialog: see uiinteriorpreviewdialog.h.
// MS2-UNIT: ?\uiinteriorpreviewdialog.cpp
// MS2-RANGE: 0x1400dfba0-0x1400dfd9c .text$di
// MS2-RANGE: 0x140f4cc50-0x140f4dfd0 .text$mn
// MS2-PIN: ??0Unk_IpReg@@QEAA@P6AXPEAX0@Z 0x1409f2d20
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiinteriorpreviewdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiinteriorpreviewdialog.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdlib.h>

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types (unrecovered helpers) ----

class ASDialog : public ASDisplayObject { public: void FUN_1422c00f0(float fX, float fY); };   // set the position
struct Unk_IpIdSet { char m_pad[0x38]; };                           // a hash set of item ids (ctor 0x140203150, dtor 0x1402038f0)
struct Unk_IpArgs { CStringW FUN_1408d21c0(int nIndex, CStringW strDefault); };   // ItemFunctionArgs::GetString
class Unk_IpReg { public: Unk_IpReg(void (*pfnCallback)(void*, void*)); };   // registers a callback in a global table
void FUN_140f50a40(void*, void*);
class Unk_IpWorld;
class Unk_IpActor;
class Unk_IpUIMgr { public: void FUN_141adc530(int nClass); };

void FUN_140203150(Unk_IpIdSet* pSet, unsigned nBuckets);
void* FUN_140204740(Unk_IpIdSet* pSet, int nKey, int nDefault);     // lookup: the value or 0
void FUN_140203f00(Unk_IpIdSet* pSet, int nKey);                    // insert
void FUN_1402038f0(Unk_IpIdSet* pSet);
CString FUN_14016a600(const wchar_t* psz, int nCodePage);          // narrow copy
CStringW FUN_14028de60(int nStringId);
void FUN_141415450(const CString& strKey, MS2Ptr<CItem> spItem, int nIndex, int nFlags, int nMask);   // bind the item to a name
void FUN_141415600(const CString& strBindID);                       // release the item bound to the name
Unk_IpWorld* FUN_1403ed2d0();
Unk_IpActor* FUN_141bd0cc0(Unk_IpWorld* pWorld);                    // the local player
Unk_IpUIMgr* FUN_1403ed2b0();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringTable* FUN_1401a9d70();

// ---- header statics ----
static CString s_strBinding("binding");                             // @0x1400dfba0
static CString s_strItemMovie("itemMovie");                         // @0x1400dfbd0
static CString s_strItemName("itemName");                           // @0x1400dfc00
static CString s_strItemPackageList("itemPackageList");             // @0x1400dfc30
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400dfc60
static CString s_strSkill("skill");                                 // @0x1400dfd20
static CString s_strStun("stun");                                   // @0x1400dfd50
static Unk_IpReg s_reg(FUN_140f50a40);                              // @0x1400dfd80

// @0x140f4cc50
UIInteriorPreviewDialog::UIInteriorPreviewDialog()
    : m_178(0), m_17c(0), m_180(0), m_184(0)
{
}

// @0x140f4ccf0
UIInteriorPreviewDialog::~UIInteriorPreviewDialog()
{
}

// @0x140f4cd40
CString UIInteriorPreviewDialog::vfunc_1()
{
    return "InteriorPreviewDialog";
}

// @0x140f4cd90
// MS2-FUNCTIONAL: the MS2Ptr<CItemData> temp / null test (FUN_1401b5240) compiles to a different frame
void UIInteriorPreviewDialog::FUN_140f4cd90(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == (CItemData*)0)
        return;
    if (vfunc_55() == 0)
    {
        if (m_178 != nItemId)
        {
            m_178 = nItemId;
            FUN_140f4d110();
        }
        FUN_1419235d0();
    }
    else if (m_178 != nItemId)
    {
        m_178 = nItemId;
        FUN_1403ed2b0()->FUN_141adc530(0x4ee3);
    }
}

// @0x140f4ce70
void UIInteriorPreviewDialog::FUN_140f4ce70(int nItemId, float fX, float fY)
{
    if (vfunc_55() != 0)
    {
        m_17c = 1;
        m_180 = fX;
        m_184 = fY;
    }
    FUN_140f4cd90(nItemId);
}

// @0x140f4cef0
void UIInteriorPreviewDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_178 = 0;
    m_17c = 0;
    m_180 = 0;
    m_184 = 0;
    FUN_140f4dac0();
}

// @0x140f4cf60
void UIInteriorPreviewDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_17c != 0)
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
            pDialog->FUN_1422c00f0(m_180, m_184);
        m_17c = 0;
    }
    FUN_140f4d110();
}

// @0x140f4d010
// MS2-FUNCTIONAL: temp / frame layout differs around the ASTooltip local
void UIInteriorPreviewDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    Unk_IpActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return;
    if (_stricmp("getTooltipFromItemID", (const char*)strMethod) != 0)
        return;
    int nItemId = pArgs->FUN_1422b8b10();
    int nRank = pArgs->FUN_1422b8b10();
    ASTooltip tooltip(pActor, 8, m_28);
    if (tooltip.FUN_1409e1770(nItemId, nRank) != 0)
        *pRetVal = tooltip.FUN_1422bb870();
}

#ifndef MS2_HOOK_DLL
// @0x140f4d110
// MS2-FUNCTIONAL: a 2.4 KB list builder over unrecovered containers (id set, bound item keys); temp / frame layout differs
void UIInteriorPreviewDialog::FUN_140f4d110()
{
    MS2Ptr<CItemData> spData = FUN_14053f870(m_178);
    if (spData == (CItemData*)0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    CStringW strDefault(L"");
    CString strPackage = FUN_14016a600(reinterpret_cast<Unk_IpArgs*>(&spData->function.parameter)->FUN_1408d21c0(0, strDefault), 0);
    UGCMapPackageDataPtr spPackage = FUN_1408b9b90(strPackage);
    if (spPackage == (CUGCMapPackageData*)0)
        return;
    ASArray arrItems(m_28);
    Unk_IpIdSet seen;
    FUN_140203150(&seen, 10);
    unsigned nBound = 0;
    for (unsigned i = 0; i < spPackage->m_cubes.GetCount(); ++i)
    {
        UGCMapPackageInfoPtr spInfo = spPackage->m_cubes[i];
        if (spInfo.get() == 0)
            continue;
        int nCubeItemId = spInfo->m_nItemId;
        if (FUN_140204740(&seen, nCubeItemId, 0) != 0)
            continue;
        MS2Ptr<CItemData> spCubeData = FUN_14053f870(nCubeItemId);
        if (spCubeData == (CItemData*)0)
            continue;
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_14052b130(nCubeItemId, 0, 0) != 0)
        {
            int nCount = spPackage->FUN_1408b9ab0(nCubeItemId);
            spItem->FUN_140526c70(nCount);
            CString strKey;
            ++nBound;
            strKey.Format("%s.%d", (const char*)vfunc_1(), (unsigned __int64)nBound);
            ASObj objItem(m_28);
            objItem.FUN_1407cbb20((const char*)s_strItemName, spItem->FUN_140527b10());
            objItem.FUN_1407cba60((const char*)s_strBinding, strKey);
            FUN_141415450(strKey, MS2Ptr<CItem>(spItem), nBound, 0x415, 0x800);
            arrItems.FUN_1422bc050(objItem.FUN_1422bb870());
            m_188.Add(strKey);
            FUN_140203f00(&seen, nCubeItemId);
        }
    }
    MS2Ptr<ASTextField> spName = FUN_140bb4cf0("m_itemName");
    if (spName.get() != 0)
        spName->FUN_1422c4cd0(FUN_1401a9d70()->FUN_141811980(1, m_178));
    MS2Ptr<ASTextField> spSize = FUN_140bb4cf0("m_cubeSize");
    if (spSize.get() != 0)
        spSize->FUN_1422c4cd0(StringFormat(L"{0} {1}", FUN_14028de60(0x56c), spPackage->m_strIndoorSizeType));
    ASObj objData(m_28);
    objData.FUN_1409adbe0((const char*)s_strItemPackageList, arrItems.FUN_1422bb870());
    objData.FUN_1407cba60((const char*)s_strItemMovie, spData->property.movie);
    pDialog->FUN_140acd1f0("setData", objData);
    FUN_1402038f0(&seen);
}
#endif

// @0x140f4dac0
void UIInteriorPreviewDialog::FUN_140f4dac0()
{
    for (size_t i = 0; i < m_188.GetCount(); ++i)
        FUN_141415600(m_188[i]);
    m_188.RemoveAll();
}
