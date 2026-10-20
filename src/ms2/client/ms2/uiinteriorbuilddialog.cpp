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
#include <map>

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
struct Unk_IbArgs { CStringW FUN_1408d21c0(int nIndex, const wchar_t* szDefault); };   // the nIndex-th function argument
inline Unk_IbArgs& IbArgs(CItemData* p) { return reinterpret_cast<Unk_IbArgs&>(p->function.parameter); }

extern Unk_Inventory DAT_143ab2a90;                                     // the own inventory
extern __int64 DAT_143ab2820;                                           // the own home owner id
class Unk_IbWorld { public: int FUN_141bd3060(); };                     // the current map id
Unk_IbWorld* FUN_1403ed2d0();
void* FUN_1403ed2b0();                                                  // the ui manager
void FUN_141adc530(void* pManager, int nUiId);                          // open a dialog

// The own home record (the cube map information service's accessors).
class Unk_IbHome
{
public:
    __int64 FUN_1410c3180();                                            // owner id
    unsigned char FUN_1410c3470();                                      // width of the own indoor
    unsigned char FUN_1410c34b0();                                      // length of the own indoor
    int FUN_1410d2ee0();                                                // the indoor is empty
};
Unk_IbHome* FUN_1409670e0();

void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW tag);    // message box
void FUN_14151f200();                                                   // close the current message box
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);             // string equals
CString FUN_14016a600(const wchar_t* sz, int n);                        // wide to narrow
CStringW FUN_1409eec40(int nId);                                        // string table text
CStringW FUN_14052bd00(int nStringId, const CStringW& arg);             // string table text with one argument
void FUN_140177de0(const CString& str, ATL::CAtlArray<int>* pOut, const char* pszSep);   // split into numbers
size_t FUN_140186260(ATL::CAtlArray<int>& arr);                         // GetCount
int* FUN_1401844d0(ATL::CAtlArray<int>& arr, unsigned __int64 n);       // GetAt

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
CString UIInteriorBuildDialog::vfunc_1()
{
    return "InteriorBuildDialog";
}
MS2_REPLACE_METHOD(0x140F4B470, UIInteriorBuildDialog, vfunc_1, 61, 0x1FA4570D);

// @0x140f4b4c0
void UIInteriorBuildDialog::FUN_140f4b4c0(__int64 nItemUid)
{
    if (vfunc_55() == 0)
        return;
    m_178 = nItemUid;
    FUN_141adc530(FUN_1403ed2b0(), 0x4ee8);
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
        FUN_140f4bc40();
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: OnMessage: temp / scope layout of the tag string and item handle differs (20 bytes longer)
// @0x140f4b5f0
int UIInteriorBuildDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender))
    {
        int nAnswer = pMsg->FUN_1422b8a10();
        if (nAnswer == 0)
        {
            CStringW strTag = pMsg->FUN_1422b8f40();
            if (FUN_1403b3c40(strTag, L"indoorSizeDifferent") || FUN_1403b3c40(strTag, L"indoorEmpty"))
            {
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_178);
                if (spItem == 0)
                    return 0;
                DAT_143ab2a90.FUN_140a63880(spItem.get(), CStringW(L"true"));
            }
        }
        FUN_14151f200();
        vfunc_67();
    }
    return 0;
}

// MS2-FUNCTIONAL: FUN_140f4b7d0: handle / temp layout of the item data and package pointers differs (frame size)
// @0x140f4b7d0
void UIInteriorBuildDialog::FUN_140f4b7d0()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_178);
    if (spItem == 0)
        return;
    MS2SvrPtr<CItemData> spData(spItem->FUN_140527840());
    if (spData.get() == 0)
        return;
    CString strPackage = FUN_14016a600(IbArgs(spData.get()).FUN_1408d21c0(0, L""), 0);
    UGCMapPackageDataPtr spPackage = FUN_1408b9b90(strPackage);
    if (spPackage == 0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        ASObj obj(m_28);
        obj.FUN_1407cba60(s_itemMovie, spData->property.movie);
        obj.FUN_1407cbb20("packageName", FUN_14052bd00(0x6ed, spItem->FUN_140527b10()));
        obj.FUN_1407cbb20("packageDesc", FUN_1409eec40(0x6ee));
        obj.FUN_1407cbb20("installName", FUN_1409eec40(0x6ef));
        obj.FUN_1407cbb20("installDesc", FUN_14028dee0(0x6f0, spPackage->m_strIndoorSizeType));
        pDialog->FUN_140acd1f0("setData", AScript(obj));
    }
}

// MS2-FUNCTIONAL: FUN_140f4bc40: the exe's cleanup of the package / map / array handles is repeated before every exit (frame size)
// @0x140f4bc40
void UIInteriorBuildDialog::FUN_140f4bc40()
{
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_178);
    if (spItem == 0)
        return;
    if (!CFieldData::FUN_140374410(FUN_1403ed2d0()->FUN_141bd3060()))
    {
        FUN_140d73bc0(0xb8e, 0, 0, CStringW(L""));
        return;
    }
    Unk_ItemEquipData* pData = spItem->FUN_140527840();
    if (pData->function.parameter.FUN_1408d2380() == 0)
    {
        FUN_140d73bc0(0xb8f, 0, 0, CStringW(L""));
        return;
    }
    CString strPackage = FUN_14016a600(IbArgs(pData).FUN_1408d21c0(0, L""), 0);
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
    if (FUN_1409670e0()->FUN_1410c3180() != DAT_143ab2820)
    {
        FUN_140d73bc0(0xb90, 0, 0, CStringW(L""));
        return;
    }
    Unk_UGCMapPtr spMap = FUN_1408ad3f0(FUN_1403ed2d0()->FUN_141bd3060());
    if (spMap == 0)
    {
        FUN_140d73bc0(0xb92, 0, 0, CStringW(L""));
        return;
    }
    std::map<int, Unk_UGCGroup>& groups = spMap->groups;
    if (groups.find(1) == groups.end())
    {
        FUN_140d73bc0(0xb92, 0, 0, CStringW(L""));
        return;
    }
    if (groups[1].indoorSizeType.IsEmpty())
    {
        FUN_140d73bc0(0xb93, 0, 0, CStringW(L""));
        return;
    }
    unsigned char nWidth = FUN_1409670e0()->FUN_1410c3470();
    unsigned char nLength = FUN_1409670e0()->FUN_1410c34b0();
    ATL::CAtlArray<int> aSize;
    FUN_140177de0(spPackage->m_strIndoorSizeType, &aSize, ",");
    if (FUN_140186260(aSize) < 3)
    {
        FUN_140d73bc0(0xb9d, 1, static_cast<IMessageListener*>(this), CStringW(L"indoorSizeDifferent"));
        return;
    }
    if (*FUN_1401844d0(aSize, 0) <= (int)nWidth && *FUN_1401844d0(aSize, 2) <= (int)nLength)
    {
        if (FUN_1409670e0()->FUN_1410d2ee0() == 0)
        {
            FUN_140d73bc0(0xb9e, 1, static_cast<IMessageListener*>(this), CStringW(L"indoorEmpty"));
            return;
        }
        DAT_143ab2a90.FUN_140a63880(spItem.get(), CStringW(L"false"));
        vfunc_67();
        return;
    }
    FUN_140d73bc0(0xb9d, 1, static_cast<IMessageListener*>(this), CStringW(L"indoorSizeDifferent"));
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9890-0x142ca9920 .text$yd
