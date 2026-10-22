// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISelectItemBoxDialog: see uiselectitemboxdialog.h.
// MS2-UNIT: ?\uiselectitemboxdialog.cpp
// MS2-RANGE: 0x140f99280-0x140f9b9c0 .text$mn
// MS2-RANGE: 0x1400e13b0-0x1400e1660 .text$di
// MS2-PIN: ??$FUN_14028dfa0@_KI@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEB_KAEBI@Z 0x140f9ae60
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiselectitemboxdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uiselectitemboxdialog.h"

#include <algorithm>
#include <vector>

#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/placeholder/header_statics_a.h"
// The statics of this TU after the shared header's: the sort names of a second header, skill/stun, then an anonymous
// handle static at 0x143acbc50.
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100
static Unk_Handle1401cd100 s_dat_143acbc50(0);                                       // @0x1400e1640

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (unrecovered helpers) ----

// The list event handed to the change handler (ctor 0x1422e2740, dtor 0x140f83bb0) and the row's button wrapper
// (ctor 0x1422cdde0 shared with tabcontentspetevolution.cpp, dtor 0x1422cde30).
class ASListEvent
{
public:
    ASListEvent(const Scaleform::GFx::FunctionHandler::Params& params);
    ~ASListEvent();
    Scaleform::GFx::Value FUN_1422e27d0();                              // the clicked row
    char m_pad[0x40];
};
class Unk_PetButton : public AScript
{
public:
    Unk_PetButton(const Scaleform::GFx::Value& v, int nMovie);
    virtual ~Unk_PetButton();
    void FUN_1422ce090(int n);                                          // select / deselect the row
};

// The item record's properties (+0x320) and argument table (+0x2b0).
class Unk_SibProps { public: int FUN_14054c530(const CStringW& strKey, const int* pDefault); };
class Unk_SibArgs { public: int FUN_1408d1fd0(int nIndex, int nDefault); };
class Unk_SibItemData
{
public:
    char m_pad_0[0x2b0];
    Unk_SibArgs m_args;                     // +0x2b0
    char m_pad_2b1[0x320 - 0x2b0 - 1];
    Unk_SibProps m_props;                   // +0x320
};
extern bool FUN_14092c5c0(const Unk_SibProps& props);                   // the item uses the property form

// The player's item inventory (global object) and the callbacks.
class Unk_SibInventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(unsigned __int64 uid);
    int FUN_140a5f180(unsigned nItemId, int nFlag);
};
extern int DAT_143ab2a90;

class Unk_SibDropParams
{
public:
    Unk_SibDropParams();                    // 0x1402e9180
    int m_n0;
    int m_n4;                               // +4 the player's level
    int m_n8;                               // +8 the player's job
    char m_pad[0x2c - 12];
};

class Unk_SibDropTable { public: void FUN_1402eaf10(int nBoxId, Unk_SibDropParams& params, Unk_PetBoxDropVec& out, int n); };
Unk_SibDropTable* FUN_1405a1fd0();

class Unk_SibPlayer { public: int FUN_141654700(); };               // the local player
int FUN_141658e60(Unk_SibPlayer* pPlayer);                                       // the player's job
class Unk_SibPlayers { public: Unk_SibPlayer* FUN_141bd0cc0(); };
Unk_SibPlayers* FUN_1403ed2d0();


// string-table text with arguments (the shared FUN_14028dfa0 back end and its instances)
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_14028dfa0(CStringW strKey, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
void FUN_1412752d0(const CStringW& strMessage, int n);                  // pop a notice
void FUN_141276180(const CString& strCommand, const CString& strArg);
CString FUN_140b62550(unsigned nIndex);                                 // the index text
CString FUN_14016a600(const wchar_t* psz, int n);                       // wide -> narrow
class Unk_SibPacketSender { public: void FUN_140a1f970(const CString& strFunction, const CString& strArgs); };
Unk_SibPacketSender* FUN_140d8ee90();
void FUN_140d1d3d0(void* pItemUid, const CStringW& str);
void* FUN_14052cd70(MS2Ptr<CItem>& item);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140f99280
UISelectItemBoxDialog::UISelectItemBoxDialog()
    : m_uItemUid(0)
    , m_nSelectCount(0)
    , m_binder("SelectItemBoxDialog")
    , m_binderSel("SelectItemBoxDialog_Sel")
{
    FUN_141924170(1);
    FUN_140d432d0(&m_binder, 0x411);
    FUN_140d432d0(&m_binderSel, 0x411);
}

// @0x140f99420
UISelectItemBoxDialog::~UISelectItemBoxDialog()
{
}

// @0x140f99500
CString UISelectItemBoxDialog::GetTypeName()
{
    return "SelectItemBoxDialog";
}

// MS2-FUNCTIONAL: MS2Ptr temp / vector resize glue and frame size differ (large function)
// MS2-FUNCTIONAL: MS2Ptr temp / vector resize glue and frame size differ (large function)
// @0x140f99550
void UISelectItemBoxDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_close");
    MS2Ptr<CItem> item = ((Unk_SibInventory*)&DAT_143ab2a90)->FUN_140a5d680(m_uItemUid);
    if (item == 0)
        return;
    {
        MS2Ptr<Unk_SibButton> ok = FUN_140bc6d10("m_okButton", &m_okButton);
        if (ok.get() != 0) {
            Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb(this, &UISelectItemBoxDialog::FUN_140f9a230);
            m_okButton->FUN_1422ce240(cb, 0);
        }
    }
    {
        MS2Ptr<Unk_SibList> list = FUN_140e8d030("m_selectItemList", &m_selectItemList);
        if (list.get() != 0) {
            Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb(this, &UISelectItemBoxDialog::FUN_140f9a5f0);
            m_selectItemList->FUN_1422de0e0(cb, 0);
        }
    }
    m_selectedSlots.clear();
    m_selectedSlots.resize(6);
    for (unsigned i = 0; i < 6; ++i) {
        MS2Ptr<Unk_SibSlot> slot = FUN_140c57ce0(StringFormat("m_selectedSlot{0}", i), &m_selectedSlots[i]);
    }
    {
        MS2Ptr<Unk_SibText> t = FUN_140e48d80("m_selectedCount", &m_selectedCount);
    }
    {
        MS2Ptr<Unk_SibText> t = FUN_140e48d80("m_selectNotice", &m_selectNotice);
    }
    int nDropBoxId = 0;
    Unk_SibItemData* pData = reinterpret_cast<Unk_SibItemData*>(item->FUN_140527840());
    if (FUN_14092c5c0(pData->m_props) == false) {
        int nDefault = 0;
        m_nSelectCount = pData->m_props.FUN_14054c530(CStringW(L"selectCount"), &nDefault);
        int nDefault2 = 0;
        nDropBoxId = pData->m_props.FUN_14054c530(CStringW(L"individualDropBoxId"), &nDefault2);
    } else {
        m_nSelectCount = pData->m_args.FUN_1408d1fd0(0, 0);
        nDropBoxId = pData->m_args.FUN_1408d1fd0(1, 0);
    }
    if (nDropBoxId == 0 || m_nSelectCount == 0)
        return;
    Unk_SibPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    Unk_SibDropParams params;
    params.m_n4 = pPlayer->FUN_141654700();
    params.m_n8 = FUN_141658e60(pPlayer);
    m_rewards.FUN_140f9b7d0();
    FUN_1405a1fd0()->FUN_1402eaf10(nDropBoxId, params, m_rewards, 0);
    m_binder.FUN_140d43990();
    unsigned nMax = 0x12;
    unsigned nSize = (unsigned)m_rewards.FUN_140314170();
    nMax = (std::min)(nSize, nMax);
    ASDataProvider list(2);
    for (unsigned i = 0; i < nMax; ++i) {
        if (i < m_rewards.FUN_140314170()) {
            CString strBind = m_binder.FUN_140d43510(m_rewards.FUN_140c461b0(i));
            if (!strBind.IsEmpty()) {
                ASObj entry(2);
                entry.FUN_1407cba60("bindID", strBind);
                list.FUN_1422bc050(entry.FUN_1422bb890());
            }
        } else {
            ASObj entry(2);
            list.FUN_1422bc050(entry.FUN_1422bb890());
        }
    }
    m_selectItemList->Invoke("resetRenderer");
    m_selectItemList->vfunc_50(list.FUN_1422bb870());
    m_selectItemList->vfunc_24(true);
    int nNext = pData->m_args.FUN_1408d1fd0(4, 1);
    int nHave = ((Unk_SibInventory*)&DAT_143ab2a90)->FUN_140a5f180(item->FUN_1405276c0(), 0);
    if (nNext == 1 && 1 < nHave)
        m_okButton->FUN_1422cdfb0(GetStringCommonByKey(CStringW(L"s_selectItemBox_select_next")));
    else
        m_okButton->FUN_1422cdfb0(GetStringCommonByKey(CStringW(L"s_selectItemBox_select_ok")));
    FUN_140f9a700();
}

// @0x140f9a140
void UISelectItemBoxDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_binder.FUN_140d43990();
    m_binderSel.FUN_140d43990();
    m_okButton = 0;
    m_selectItemList = 0;
    m_selectedSlots.clear();
    m_selectedCount = 0;
    m_selectNotice = 0;
    m_rewards.FUN_140f9b7d0();
}

// MS2-FUNCTIONAL: the exe destroys the polymorphic entries (vector::clear glue); the element type is unrecovered.
// @0x140f9b7d0
void Unk_PetBoxDropVec::FUN_140f9b7d0()
{
    m_end = m_begin;
}

// @0x140f9a200
void UISelectItemBoxDialog::SetItemUid(unsigned __int64 uItemUid)
{
    m_uItemUid = uItemUid;
}

// MS2-FUNCTIONAL: frame / temp order differs (GS cookie, MS2Ptr copies)
// MS2-FUNCTIONAL: frame / temp order differs (GS cookie, MS2Ptr copies)
// @0x140f9a230
void UISelectItemBoxDialog::FUN_140f9a230(const Scaleform::GFx::FunctionHandler::Params& params)
{
    MS2Ptr<CItem> item = ((Unk_SibInventory*)&DAT_143ab2a90)->FUN_140a5d680(m_uItemUid);
    if (item == 0)
        return;
    ATL::CAtlArray<unsigned> selected;
    m_selectItemList->FUN_1422cfa30(selected);
    if (selected.GetCount() != m_nSelectCount)
        return;
    CStringW strIndices;
    for (unsigned i = 0; i < selected.GetCount(); ++i) {
        if (selected[i] >= m_rewards.FUN_140314170()) {
            FUN_1412752d0(CStringW(L"s_selectItemBox_select_wrong"), 1);
            return;
        }
        strIndices += FUN_140b62550(selected[i]);
        if (i < selected.GetCount() - 1U)
            strIndices += L",";
    }
    FUN_140d8ee90()->FUN_140a1f970("select_item_box_function", FUN_14016a600(strIndices, 0));
    FUN_140d1d3d0(FUN_14052cd70(item), CStringW(strIndices));
    vfunc_67();
    FUN_141276180("select_confirm", "");
}

// MS2-FUNCTIONAL: frame / temp order differs (no GS cookie in the exe)
// MS2-FUNCTIONAL: frame / temp order differs (no GS cookie in the exe)
// @0x140f9a5f0
void UISelectItemBoxDialog::FUN_140f9a5f0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    unsigned nSelected = m_selectItemList->FUN_1422cf920();
    if (m_nSelectCount < nSelected) {
        ASListEvent evt(params);
        Scaleform::GFx::Value value = evt.FUN_1422e27d0();
        Unk_PetButton row(value, 2);
        row.FUN_1422ce090(0);
        FUN_1412752d0(CStringW(L"s_selectItemBox_cant_select_more"), 1);
    } else {
        FUN_140f9a700();
    }
}

// MS2-FUNCTIONAL: frame / temp order differs
// MS2-FUNCTIONAL: frame / temp order differs
// @0x140f9a700
void UISelectItemBoxDialog::FUN_140f9a700()
{
    MS2Ptr<CItem> item = ((Unk_SibInventory*)&DAT_143ab2a90)->FUN_140a5d680(m_uItemUid);
    if (item == 0)
        return;
    ATL::CAtlArray<unsigned> selected;
    m_selectItemList->FUN_1422cfa30(selected);
    if (selected.IsEmpty()) {
        m_selectedCount->vfunc_3(false);
        for (unsigned i = 0; i < m_selectedSlots.size(); ++i)
            ((Unk_SibSlot*)m_selectedSlots[i])->vfunc_3(false);
        m_selectNotice->vfunc_3(true);
        m_selectNotice->FUN_1422c4cd0(FUN_14028dfa0(CStringW(L"s_selectItemBox_select_notice"), m_nSelectCount));
    } else {
        m_selectNotice->vfunc_3(false);
        m_selectedCount->vfunc_3(true);
        size_t nCount = selected.GetCount();
        m_selectedCount->FUN_1422c4cd0(FUN_14028dfa0(CStringW(L"s_selectItemBox_select_itemCount"), nCount, m_nSelectCount));
        m_binderSel.FUN_140d43990();
        for (unsigned i = 0; i < m_selectedSlots.size(); ++i) {
            if (i < selected.GetCount()) {
                unsigned nIdx = selected[i];
                if (nIdx < m_rewards.FUN_140314170()) {
                    ((Unk_SibSlot*)m_selectedSlots[i])->vfunc_3(true);
                    CString strBind = m_binderSel.FUN_140d43510(m_rewards.FUN_140c461b0(nIdx));
                    ((Unk_SibSlot*)m_selectedSlots[i])->Invoke("setData", strBind);
                }
            } else {
                ((Unk_SibSlot*)m_selectedSlots[i])->Invoke("setData", "");
                ((Unk_SibSlot*)m_selectedSlots[i])->vfunc_3(false);
            }
        }
    }
    m_okButton->FUN_1422c1fe0(selected.GetCount() == m_nSelectCount);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caa320-0x142caa420 .text$yd
