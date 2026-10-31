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
#include "ms2/client/ms2/uiservice.h"   // C3: TSingleton<> needs the class
#include "ms2/client/ms2/usercommandcli.h"
#include "ms2/client/ms2/worldservice.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types (unrecovered helpers) ----

class ASDialog : public ASDisplayObject { };   // set the position
   // ItemFunctionArgs::GetString
// efd::ClassInfo (ctor 0x1409f2d20): the setup callback fills a count + 32 parent entries of 0x20, so the object
// needs the real 0x408 bytes or it overwrites the statics after it (s_strStun -> AV in its atexit dtor at Quit).
class Unk_IpReg { public: Unk_IpReg(void (*pfnCallback)(void*, void*)); private: char m_storage[0x408]; };
void FUN_140f50a40(void*, void*);
class Unk_IpWorld;
class Unk_IpActor;
class Unk_IpUIMgr { public: void FUN_141adc530(int nClass); };

CString FUN_14016a600(const wchar_t* psz, int nCodePage);          // narrow copy
CStringW GetStringCommon(int nStringId);
void FUN_141415450(const CString& strKey, MS2Ptr<CItem> spItem, int nIndex, int nFlags, int nMask);   // bind the item to a name
void FUN_141415600(const CString& strBindID);                       // release the item bound to the name
Unk_IpActor* FUN_141bd0cc0(Unk_IpWorld* pWorld);                    // the local player
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringTable* GetStringTable();

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
CString UIInteriorPreviewDialog::GetTypeName()
{
    return "InteriorPreviewDialog";
}

// @0x140f4cd90
void UIInteriorPreviewDialog::FUN_140f4cd90(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == (CItemData*)0)
        return;
    if (vfunc_55() != 0)
    {
        if (m_178 != nItemId)
        {
            m_178 = nItemId;
            reinterpret_cast<Unk_IpUIMgr*>(TSingleton<CUIService>::GetInstance())->FUN_141adc530(0x4ee3);
        }
    }
    else
    {
        if (m_178 != nItemId)
        {
            m_178 = nItemId;
            FUN_140f4d110();
        }
        FUN_1419235d0();
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
void UIInteriorPreviewDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    Unk_IpActor* pActor = FUN_141bd0cc0(reinterpret_cast<Unk_IpWorld*>(WorldService::GetInstance()));
    if (pActor == 0)
        return;
    if (_stricmp("getTooltipFromItemID", (const char*)strMethod) == 0)
    {
        int nItemId = pArgs->FUN_1422b8b10();
        int nRank = pArgs->FUN_1422b8b10();
        ASTooltip tooltip(pActor, 8, m_28);
        if (tooltip.FUN_1409e1770(nItemId, nRank) != 0)
            *pRetVal = tooltip.FUN_1422bb870();
    }
}

#ifndef MS2_HOOK_DLL
// @0x140f4d110
void UIInteriorPreviewDialog::FUN_140f4d110()
{
    MS2Ptr<CItemData> spData = FUN_14053f870(m_178);
    if (spData == (CItemData*)0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        CString strPackage = FUN_14016a600(reinterpret_cast<Unk_CommandArgs*>(&spData->function.parameter)->FUN_1408d21c0(0, L""), 0);
        UGCMapPackageDataPtr spPackage = FUN_1408b9b90(strPackage);
        if (spPackage == (CUGCMapPackageData*)0)
            return;
        ASArray arrItems(m_28);
        ATL::CAtlList<unsigned> seen(10);
        ATL::CAtlArray<UGCMapPackageInfoPtr>& cubes = spPackage->m_cubes;
        unsigned nBound = 0;
        for (unsigned i = 0; i < cubes.GetCount(); ++i)
        {
            UGCMapPackageInfoPtr spInfo = cubes[i];
            if (spInfo.get() != 0)
            {
                int nCubeItemId = spInfo->m_nItemId;
                int nAmount = 0;
                if (seen.Find(nCubeItemId) != 0)
                    continue;
                MS2Ptr<CItemData> spCubeData = FUN_14053f870(nCubeItemId);
                if (spCubeData == (CItemData*)0)
                    continue;
                MS2Ptr<CItem> spItem(new CItem);
                if (spItem->FUN_14052b130(nCubeItemId, nAmount, 0) != 0)
                {
                    spItem->FUN_140526c70(spPackage->FUN_1408b9ab0(nCubeItemId));
                    CString strKey;
                    ++nBound;
                    strKey.Format("%s.%d", (const char*)GetTypeName(), nBound);
                    ASObj objItem(m_28);
                    objItem.FUN_1407cbb20((const char*)s_strItemName, spItem->FUN_140527b10());
                    objItem.FUN_1407cba60((const char*)s_strBinding, strKey);
                    FUN_141415450(strKey, MS2Ptr<CItem>(spItem), nBound, 0x415, 0x800);
                    arrItems.FUN_1422bc050(objItem.FUN_1422bb870());
                    m_188.Add(strKey);
                    seen.AddTail(nCubeItemId);
                }
            }
        }
        if (MS2Ptr<ASTextField> spName = FUN_140bb4cf0("m_itemName"))
            spName->FUN_1422c4cd0(GetStringTable()->FUN_141811980(1, m_178));
        if (MS2Ptr<ASTextField> spSize = FUN_140bb4cf0("m_cubeSize"))
        {
            CStringW strSize = StringFormat(L"{0} {1}", GetStringCommon(0x56c), spPackage->m_strIndoorSizeType);
            spSize->FUN_1422c4cd0(strSize);
        }
        ASObj objData(m_28);
        objData.FUN_1409adbe0((const char*)s_strItemPackageList, arrItems.FUN_1422bb870());
        objData.FUN_1407cba60((const char*)s_strItemMovie, spData->property.movie);
        pDialog->FUN_140acd1f0("setData", objData);
    }
}
#endif

// @0x140f4dac0
void UIInteriorPreviewDialog::FUN_140f4dac0()
{
    for (size_t i = 0; i < m_188.GetCount(); ++i)
        FUN_141415600(m_188[i]);
    m_188.RemoveAll();
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9920-0x142ca9a10 .text$yd
