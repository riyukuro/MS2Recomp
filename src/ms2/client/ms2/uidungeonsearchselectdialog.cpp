// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDungeonSearchSelectDialog: see uidungeonsearchselectdialog.h.
// MS2-UNIT: client\ms2\uidungeonsearchselectdialog.cpp
// MS2-RANGE: 0x1400d78e0-0x1400d7c80 .text$di
// MS2-RANGE: 0x140e26c20-0x140e291e0 .text$mn
// MS2-RANGE: 0x142ca65d0-0x142ca6720 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidungeonsearchselectdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uidungeonsearchselectdialog.h"
#include "uidungeonsearchdialog.h"

#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di): the shared header statics a second time (another header of the unit pulls them in) and a bare
// sort-name table ----
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ParamsDelegate;

// The radio ("recommend") and the check boxes of the rows.
class Unk_SdToggle : public ASDisplayObject
{
public:
    void FUN_1422cdf20(int bVisible);                           // show
    void FUN_1422cdfb0(const CStringW& strText);                // label
    void FUN_1422ce090(int bChecked);                           // set checked
    unsigned char FUN_1422ce0e0();                              // is checked
    void FUN_1422ce240(const ParamsDelegate& onClick, int nUserData);
    void FUN_1422ce320(const ParamsDelegate& onClick, void* pUserData);
};
class Unk_SdRadio : public Unk_SdToggle {};
class Unk_SdCheck : public Unk_SdToggle {};
class Unk_SdButton : public ASDisplayObject {};
class Unk_SdList : public ASDisplayObject
{
public:
    void FUN_1422dcf40(int nCount);                             // the number of rows
};
// A row of the list.
class Unk_SdRow : public ASDisplayObject
{
public:
    void FUN_1422c6640(int bVisible);
    void FUN_1422e1f50(ParamsDelegate onClick, void* pUserData);
    template <class T> MS2Ptr<T> FUN_140c12010(const CString& strName, MS2Ptr<T>& outChild);   // bind a check box
};

class Unk_SdWorld { public: void* FUN_141bd0cc0(); };            // the local player
Unk_SdWorld* FUN_1403ed2d0();
class Unk_SdUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nUiId); };
Unk_SdUIManager* FUN_1403ed2b0();

UIDungeonSearchDialog* FUN_140e28d40(int nUIType);
DungeonRoomTable* FUN_14031c2a0();
void* FUN_1409670d0();
bool FUN_14162ac70(void*, int);
unsigned FUN_140bd09c0(void* pUserData);
void* FUN_140bd09d0(unsigned n);
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);
MS2Ptr<Unk_SdRadio> FUN_140a463d0(int nMovieId, const Scaleform::GFx::Value& v);   // the radio wrapper creator
bool FUN_140c123f0(const Scaleform::GFx::Value& root, CString strName, unsigned nCount, std::vector<MS2Ptr<Unk_SdRow> >& out, unsigned nStart);
CStringW FUN_140e14bd0(MS2Ptr<DungeonRoom> pRoom, bool bShowLimit);                 // the room's list text
CStringW FUN_14183e930(const CStringW& str, int nColor);                            // wrap in a color tag
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);
void FUN_140e1ba80(UIDungeonSearchDialog* pDialog, int nPage, const std::set<unsigned>& rooms);   // UIDungeonSearchDialog: sets a page's room set

#define MS2_ASCRIPT_INL_ASSERT(line, expression) \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\ascript.inl", (unsigned)(line)), 0))

#define SD_BIND(call, member, line) do { \
    call; \
    if (member == NULL) \
        throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", \
                                                  MS2_THIS_FILE, MS2_LINE(line), __FUNCTION__)); \
} while (0)

// ---- the radio's MS2Ptr and child-binding COMDATs (first instantiated here) ----

// @0x140e28f30
template <> MS2Ptr<Unk_SdRadio>::MS2Ptr() { m_p = 0; }
// @0x140e28ef0
template <> MS2Ptr<Unk_SdRadio>::MS2Ptr(const MS2Ptr& o) { m_p = o.m_p; AddRef(); }
// @0x140e28f70
template <> MS2Ptr<Unk_SdRadio>& MS2Ptr<Unk_SdRadio>::operator=(const MS2Ptr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
// @0x140e28fb0
template <> MS2Ptr<Unk_SdRadio>& MS2Ptr<Unk_SdRadio>::operator=(int)
{
    Release();
    return *this;
}
// @0x140e28fe0
template <> bool MS2Ptr<Unk_SdRadio>::operator==(Unk_SdRadio* p) const { return m_p == p; }

// @0x140e28bc0
template <> MS2Ptr<Unk_SdRadio> AScript::FUN_140e159f0<Unk_SdRadio>(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (FUN_1409b4d40(v))
        return FUN_140a463d0(m_nMovieId, v);
    return MS2Ptr<Unk_SdRadio>(0);
}
// @0x140e28c80
template <> MS2Ptr<Unk_SdRadio> AScript::FUN_140bbe640<Unk_SdRadio>(const CString& strName, MS2Ptr<Unk_SdRadio>& outChild)
{
    MS2_ASCRIPT_INL_ASSERT(0xd5, outChild == NULL);
    outChild = FUN_140e159f0<Unk_SdRadio>(strName);
    return outChild;
}

// ---- the dialog ----

// @0x140e26c20
UIDungeonSearchSelectDialog::UIDungeonSearchSelectDialog()
    : m_nPage(1), m_bAll(true)
{
    FUN_141924170(1);
}

// @0x140e26d60
UIDungeonSearchSelectDialog::~UIDungeonSearchSelectDialog()
{
}

// @0x140e26e60
CString UIDungeonSearchSelectDialog::vfunc_1()
{
    return "DungeonSearchSelectDialog";
}

// MS2-FUNCTIONAL: frame/slot order of the AS bind temporaries (0x30 bytes longer than the exe)
// @0x140e26eb0
void UIDungeonSearchSelectDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    FUN_141925fa0("m_dragBar");
    FUN_141925ec0("m_closeButton");
    SD_BIND(m_30->FUN_140bbe640<Unk_SdRadio>("m_radioRecommend", m_radio), m_radio, 0x27);
    SD_BIND(m_30->FUN_140bc71c0<ASMovieClip>("m_customPage", m_page), m_page, 0x28);
    SD_BIND(m_30->FUN_140bbe640<Unk_SdButton>("m_okButton", m_okButton), m_okButton, 0x29);
    SD_BIND(m_page->FUN_140bc7340<Unk_SdList>("m_customList", m_list), m_list, 0x2b);
    if (!FUN_140c123f0((*m_page).FUN_1422bb890(), "m_listItem", 11, m_rows, 1))
        throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                  MS2_THIS_FILE, MS2_LINE(0x2e), __FUNCTION__));
    unsigned nZero = 0;
    m_roomOfRow.assign(m_rows.size(), nZero);
    m_okButton->FUN_1422c2a70(ParamsDelegate(this, &UIDungeonSearchSelectDialog::FUN_140e281f0), 0);
    m_radio->FUN_1422c2a70(ParamsDelegate(this, &UIDungeonSearchSelectDialog::FUN_140e28170), 0);
    m_checks.resize(m_rows.size(), MS2Ptr<Unk_SdCheck>(0));
    for (unsigned i = 0; i < m_rows.size(); ++i) {
        m_rows[i]->FUN_1422e1f50(ParamsDelegate(this, &UIDungeonSearchSelectDialog::FUN_140e28280), FUN_140bd09d0(i));
        if (m_rows[i]->FUN_140c12010<Unk_SdCheck>("m_checkBox", m_checks[i]).get() != 0) {
            m_checks[i]->FUN_1422ce320(ParamsDelegate(this, &UIDungeonSearchSelectDialog::FUN_140e288f0), FUN_140bd09d0(i));
            m_checks[i]->FUN_1422ce240(ParamsDelegate(this, &UIDungeonSearchSelectDialog::FUN_140e28a40), 0);
        }
    }
    FUN_14031c2a0()->GetGroupRooms((DungeonGroupType)m_nPage, m_rooms);
    FUN_140e27f80();
}

// @0x140e27df0
void UIDungeonSearchSelectDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_radio = 0;
    m_page = 0;
    m_okButton = 0;
    m_list = 0;
    m_rows.clear();
    m_checks.clear();
    m_roomOfRow.clear();
    m_rooms.clear();
    m_selected.clear();
}

// @0x140e27ed0
void UIDungeonSearchSelectDialog::FUN_140e27ed0(int nPage, std::set<unsigned>& rooms, std::set<unsigned>* pSelected)
{
    m_nPage = nPage;
    m_allRooms.swap(rooms);
    m_bAll = pSelected->empty();
    if (m_bAll)
        m_selected = m_allRooms;
    else
        m_selected = *pSelected;
}

// @0x140e27f80
void UIDungeonSearchSelectDialog::FUN_140e27f80()
{
    if (m_nPage == 1)
        FUN_140cfee80(FUN_1422dbb40(), "m_title", L"$s_dungeonSearchSelect_title_normal");
    else
        FUN_140cfee80(FUN_1422dbb40(), "m_title", L"$s_dungeonSearchSelect_title_raid");
    m_radio->FUN_1422ce090(m_bAll);
    FUN_140e28100();
}

// @0x140e28100
void UIDungeonSearchSelectDialog::FUN_140e28100()
{
    if (m_list.get() != 0)
        m_list->FUN_1422dcf40((int)m_rooms.size());
}

// @0x140e28170
void UIDungeonSearchSelectDialog::FUN_140e28170(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_bAll)
        return;
    m_bAll = true;
    m_selected.clear();
    m_selected = m_allRooms;
    FUN_140e28100();
}

// @0x140e281f0
void UIDungeonSearchSelectDialog::FUN_140e281f0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    UIDungeonSearchDialog* pDialog = FUN_140e28d40(0x4f1c);
    if (pDialog != 0) {
        if (m_bAll)
            m_selected.clear();
        FUN_140e1ba80(pDialog, m_nPage, m_selected);
    }
    vfunc_67();
}

// MS2-FUNCTIONAL: frame slot order of the MS2Ptr copies and the widened index
// @0x140e28280
void UIDungeonSearchSelectDialog::FUN_140e28280(const Scaleform::GFx::FunctionHandler::Params& params)
{
    unsigned nRow = FUN_140bd09c0(params.pUserData);
    unsigned __int64 nRowWide = nRow;
    if (!(nRowWide < m_rows.size()))
        return;
    MS2Ptr<Unk_SdRow> row = m_rows[nRow];
    MS2Ptr<Unk_SdCheck> check = m_checks[nRow];
    if (row == NULL || check == NULL)
        return;
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    unsigned nRoom = params.pArgs->GetUInt();
    unsigned __int64 nRoomWide = nRoom;
    if (nRoomWide < m_rooms.size()) {
        int nDungeonId = m_rooms[nRoom]->GetDungeonRoomID();
        bool bOk = FUN_14162ac70(FUN_1409670d0(), nDungeonId);
        CStringW strName = FUN_140e14bd0(m_rooms[nRoom], true);
        int nColor;
        if (bOk)
            nColor = 0xffffff;
        else
            nColor = 0xff0000;
        strName = FUN_14183e930(strName, nColor);
        row->vfunc_3(1);
        m_roomOfRow[nRow] = nRoom;
        row->FUN_1422c6640(1);
        check->FUN_1422cdf20(1);
        check->FUN_1422cdfb0(strName);
        int nDungeon = m_rooms[nRoom]->GetDungeonRoomID();
        unsigned nChecked = m_selected.find(nDungeon) == m_selected.end();
        check->FUN_1422ce090(nChecked);
    } else {
        row->vfunc_3(0);
    }
}

// MS2-FUNCTIONAL: frame slot order of the MS2Ptr copies and the widened index
// @0x140e286a0
void UIDungeonSearchSelectDialog::FUN_140e286a0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    unsigned nRow = FUN_140bd09c0(params.pUserData);
    unsigned __int64 nRowWide = nRow;
    if (!(nRowWide < m_rows.size()))
        return;
    MS2Ptr<Unk_SdRow> row = m_rows[nRow];
    MS2Ptr<Unk_SdCheck> check = m_checks[nRow];
    if (row == NULL || check == NULL)
        return;
    CStringW strName = FUN_140e14bd0(m_rooms[m_roomOfRow[nRow]], true);
    ASTooltip tooltip(1, 2);
    tooltip.FUN_1409c6d70("export_common_tooltip_tooltipText");
    tooltip.FUN_1409c6e00(300);
    tooltip.FUN_1409c6e30(60000);
    tooltip.FUN_1409c6dc0(5);
    tooltip.FUN_1409c6cb0(strName);
    FUN_1409b4bc0(params.pRetVal, tooltip.FUN_1422bb870());
}

// MS2-FUNCTIONAL: frame slot order of the MS2Ptr copy, the widened index and the set::insert result
// @0x140e288f0
void UIDungeonSearchSelectDialog::FUN_140e288f0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    unsigned nRow = FUN_140bd09c0(params.pUserData);
    unsigned __int64 nRowWide = nRow;
    if (!(nRowWide < m_rows.size()))
        return;
    MS2Ptr<Unk_SdCheck> check = m_checks[nRow];
    if (check == NULL)
        return;
    unsigned nRoom = m_roomOfRow[nRow];
    int nDungeon = m_rooms[nRoom]->GetDungeonRoomID();
    if (check->FUN_1422ce0e0())
        m_selected.insert(nDungeon);
    else
        m_selected.erase(nDungeon);
}

// @0x140e28a40
void UIDungeonSearchSelectDialog::FUN_140e28a40(const Scaleform::GFx::FunctionHandler::Params& params)
{
    m_bAll = false;
    m_radio->FUN_1422ce090(0);
}

// @0x140e28d40
UIDungeonSearchDialog* FUN_140e28d40(int nUIType)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nUIType);
        if (p.get())
            return dynamic_cast<UIDungeonSearchDialog*>((UIObject*)p);
    }
    return 0;
}
