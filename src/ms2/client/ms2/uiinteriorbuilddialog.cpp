// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIInteriorBuildDialog: the interior package item dialog.
// MS2-UNIT: ?\uiinteriorbuilddialog.cpp
// MS2-RANGE: 0x1400dfa30-0x1400dfba0 .text$di
// MS2-RANGE: 0x140f4b3d0-0x140f4cc50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0V?$tuple@$$QEAH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHUUnk_UGCGroup@@@std@@QEAA@AEAV?$tuple@$$QEAH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140f4c5d0 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_UGCGroup@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x140f4c6b0 ; unique
// MS2-PIN: ??$_Try_emplace@H$$V@?$map@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@@std@@_N@1@$$QEAH@Z 0x140f4c780 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHUUnk_UGCGroup@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCGroup@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_UGCGroup@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHUUnk_UGCGroup@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x140f4c8d0 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HUUnk_UGCGroup@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_UGCGroup@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x140f4c980 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiinteriorbuilddialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiinteriorbuilddialog.h"
#include "uimessagebox.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/commonfiles/ugcmapdata.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/usercommandcli.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include <map>
#include "ms2/client/ms2/uiservice.h"  // C3: CUIService::OpenDialog

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (in the exe's order: the movie name, the shared sort names, then the seed object) ----
class Unk_IbSeed { public: Unk_IbSeed(int n); private: void* m_p; };    // 0x1401cd100
static CString s_itemMovie = "itemMovie";                                                    // @0x1400dfa30
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400dfa60
static CString s_strSkill = "skill";                                                         // @0x1400dfb20
static CString s_strStun = "stun";                                                           // @0x1400dfb50
static Unk_IbSeed s_ibSeed(0);                                                               // @0x1400dfb80

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject
{
};

class Unk_ItemEquipData : public CItemData { };                         // CItem::FUN_140527840's record
   // the nIndex-th function argument

extern Unk_Inventory g_143ab2a90;                                       // the own inventory
extern __int64 DAT_143ab2820;                                           // the own home owner id
                     // the current map id

// The own home record (the cube map information service's accessors).
class Unk_IbHome : public CubeMapInformationService
{
public:
    unsigned char FUN_1410c3470();                                      // width of the own indoor
    unsigned char FUN_1410c34b0();                                      // length of the own indoor
};
class Unk_AkoHouseSvc   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoHouseSvc* GetInstance();
};

void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW tag);    // message box
void FUN_14151f200();                                                   // close the current message box
CString FUN_14016a600(const wchar_t* sz, int n);                        // wide to narrow
CStringW BlockFormat(int nId);                                          // string table text
template <class A> CStringW FormatStringId(int nId, const A& a);             // string table text with one argument
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);   // C3: was FUN_140177de0 (CAtlArray<int>)

CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);              // string table text, formatted
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)

// @0x140f4b3d0
UIInteriorBuildDialog::UIInteriorBuildDialog()
{
    m_178 = 0;
}

// @0x140f4b430
UIInteriorBuildDialog::~UIInteriorBuildDialog()
{
}

// @0x140f4b470
CString UIInteriorBuildDialog::GetTypeName()
{
    return "InteriorBuildDialog";
}
MS2_REPLACE_METHOD(0x140F4B470, UIInteriorBuildDialog, GetTypeName, 61, 0x1FA4570D);

// @0x140f4b4c0
void UIInteriorBuildDialog::FUN_140f4b4c0(__int64 nItemUid)
{
    if (vfunc_55() == 0)
        return;
    m_178 = nItemUid;
    (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4ee8)));
}

// @0x140f4b520
void UIInteriorBuildDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_178 = 0;
}

// @0x140f4b550
void UIInteriorBuildDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140f4b7d0();
}

// @0x140f4b580
int UIInteriorBuildDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnUseItem", szMethod) == 0)
    {
        OnUseItem();
        return 1;
    }
    return 0;
}

// @0x140f4b5f0
int UIInteriorBuildDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender))
    {
        int nAnswer = pMsg->PopInt();
        if (nAnswer == 0)
        {
            CStringW strTag = pMsg->FUN_1422b8f40();
            if (operator==(strTag, L"indoorSizeDifferent") || operator==(strTag, L"indoorEmpty"))
            {
                MS2Ptr<CItem> spItem = g_143ab2a90.FUN_140a5d680(m_178);
                if (spItem == 0)
                    return 0;
                g_143ab2a90.FUN_140a63880(spItem.get(), L"true");
            }
        }
        FUN_14151f200();
        vfunc_67();
    }
    return 0;
}

// @0x140f4b7d0
void UIInteriorBuildDialog::FUN_140f4b7d0()
{
    MS2Ptr<CItem> spItem = g_143ab2a90.FUN_140a5d680(m_178);
    if (spItem == 0)
        return;
    MS2SvrPtr<CItemData> spData(spItem->FUN_140527840());
    if (spData == 0)
        return;
    CString strPackage = FUN_14016a600(reinterpret_cast<Unk_CommandArgs&>(spData->function.parameter).FUN_1408d21c0(0, L""), 0);
    UGCMapPackageDataPtr spPackage = FUN_1408b9b90(strPackage);
    if (spPackage == 0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        ASObj obj(m_28);
        obj.FUN_1407cba60(s_itemMovie, spData->property.movie);
        ((class AScript&)(obj)).FUN_1407cbb20("packageName", FormatStringId<CStringW>(0x6ed, spItem->FUN_140527b10()));
        ((class AScript&)(obj)).FUN_1407cbb20("packageDesc", BlockFormat(0x6ee));
        ((class AScript&)(obj)).FUN_1407cbb20("installName", BlockFormat(0x6ef));
        ((class AScript&)(obj)).FUN_1407cbb20("installDesc", FUN_14028dee0(0x6f0, spPackage->m_strIndoorSizeType));
        pDialog->FUN_140acd1f0("setData", AScript(obj));
    }
}

// @0x140f4bc40
void UIInteriorBuildDialog::OnUseItem()
{
    MS2Ptr<CItem> spItem = g_143ab2a90.FUN_140a5d680(m_178);
    if (spItem == 0)
        return;
    if (!CFieldData::FUN_140374410(WorldService::GetInstance()->FUN_141bd3060()))
    {
        FUN_140d73bc0(0xb8e, 0, 0, CStringW(L""));
        return;
    }
    if (spItem->FUN_140527840()->function.parameter.FUN_1408d2380() < 1)
    {
        FUN_140d73bc0(0xb8f, 0, 0, CStringW(L""));
        return;
    }
    CString strPackage = FUN_14016a600(reinterpret_cast<Unk_CommandArgs&>(spItem->FUN_140527840()->function.parameter).FUN_1408d21c0(0, L""), 0);
    if (strPackage.IsEmpty())
    {
        FUN_140d73bc0(0xb8f, 0, 0, CStringW(L""));
        return;
    }
    UGCMapPackageDataPtr spPackage = FUN_1408b9b90(strPackage);
    if (spPackage == 0)
    {
        FUN_140d73bc0(0xb8f, 0, 0, CStringW(L""));
        return;
    }
    if (((class Unk_IbHome*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c3180() != DAT_143ab2820)
    {
        FUN_140d73bc0(0xb90, 0, 0, CStringW(L""));
        return;
    }
    Unk_UGCMapPtr spMap = FUN_1408ad3f0(WorldService::GetInstance()->FUN_141bd3060());
    if (spMap == 0)
    {
        FUN_140d73bc0(0xb92, 0, 0, CStringW(L""));
        return;
    }
    if (spMap->groups.find(1) == spMap->groups.end())
    {
        FUN_140d73bc0(0xb92, 0, 0, CStringW(L""));
        return;
    }
    Unk_UGCGroup& group = spMap->groups[1];
    if (group.indoorSizeType.IsEmpty())
    {
        FUN_140d73bc0(0xb93, 0, 0, CStringW(L""));
        return;
    }
    unsigned char nWidth = ((unsigned char)((class CubeMapInformationService*)(((class Unk_IbHome*)Unk_AkoHouseSvc::GetInstance())))->FUN_1410c3470());
    unsigned char nLength = ((unsigned char)((class CubeMapInformationService*)(((class Unk_IbHome*)Unk_AkoHouseSvc::GetInstance())))->FUN_1410c34b0());
    ATL::CAtlArray<int> aSize;
    XmlSplit(spPackage->m_strIndoorSizeType, aSize, "x");
    if (((ATL::CAtlArray<int, ATL::CElementTraits<int>>*)&static_cast<class ATL::CAtlArray<int, class ATL::CElementTraits<int>>&>(aSize))->GetCount() < 3)
    {
        FUN_140d73bc0(0xb9d, 1, static_cast<IMessageListener*>(this), CStringW(L"indoorSizeDifferent"));
        return;
    }
    if (nWidth < aSize[0] || nLength < aSize[2])
    {
        FUN_140d73bc0(0xb9d, 1, static_cast<IMessageListener*>(this), CStringW(L"indoorSizeDifferent"));
        return;
    }
    if (((class Unk_IbHome*)Unk_AkoHouseSvc::GetInstance())->FUN_1410d2ee0() == 0)
    {
        FUN_140d73bc0(0xb9e, 1, static_cast<IMessageListener*>(this), CStringW(L"indoorEmpty"));
        return;
    }
    g_143ab2a90.FUN_140a63880(spItem.get(), L"false");
    vfunc_67();
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9890-0x142ca9920 .text$yd
