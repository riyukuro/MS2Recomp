// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDungeonSearchSelectDialog: see uidungeonsearchselectdialog.h.
// MS2-UNIT: client\ms2\uidungeonsearchselectdialog.cpp
// MS2-RANGE: 0x1400d78e0-0x1400d7c80 .text$di
// MS2-RANGE: 0x140e26c20-0x140e291e0 .text$mn
// MS2-RANGE: 0x142ca65d0-0x142ca6720 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidungeonsearchselectdialog.cpp"
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"

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
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/asradiobutton.h"   // the "m_radioRecommend" radio (ASButton::FUN_1422ce240)

// ---- statics (.text$di): the shared header statics a second time (another header of the unit pulls them in) and a bare
// sort-name table ----
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ParamsDelegate;

            // the local player
class Unk_SdUIManager { public: };

UIDungeonSearchDialog* GetDungeonSearchDialog(int nUIType);
class CPartyManager;
class CPartyManager   // C3: member view for the former free stand-ins
{
public:
    bool CanEnterDungeonRoom(int);
};
int FUN_140bd09c0(void*);   // C3: was FUN_140bd09c0
void* FUN_140bd09d0(unsigned n);
MS2Ptr<ASRadioButton> CreateRadioButton(int nMovieId, const Scaleform::GFx::Value& v);   // the radio wrapper creator
template <class T> bool FUN_140c123f0(const Scaleform::GFx::Value& root, CString strName, unsigned nCount, std::vector<MS2Ptr<T> >& out, unsigned nStart);
CStringW GetRoomListText(MS2Ptr<DungeonRoom> pRoom, bool bShowLimit);                 // the room's list text
CStringW FUN_14183e930(const CStringW& str, unsigned nColor);                            // wrap in a color tag
void SetChildText(const Scaleform::GFx::Value& root, CString strName, CStringW strText);

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
template <> inline MS2Ptr<ASRadioButton>::MS2Ptr() { m_p = 0; }
// @0x140e28ef0
template <> inline MS2Ptr<ASRadioButton>::MS2Ptr(const MS2Ptr& o) { m_p = o.m_p; AddRef(); }
// @0x140e28f70
template <> inline MS2Ptr<ASRadioButton>& MS2Ptr<ASRadioButton>::operator=(const MS2Ptr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
// @0x140e28fb0
template <> inline MS2Ptr<ASRadioButton>& MS2Ptr<ASRadioButton>::operator=(int)
{
    Release();
    return *this;
}
// @0x140e28fe0
template <> inline bool MS2Ptr<ASRadioButton>::operator==(ASRadioButton* p) const { return m_p == p; }

// @0x140e28bc0
template <> MS2Ptr<ASRadioButton> AScript::FUN_140e159f0<ASRadioButton>(const CString& strName)
{
    Scaleform::GFx::Value v = GetMember(strName);
    if (((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(v))->IsObject())
        return CreateRadioButton(m_nMovieId, v);
    return MS2Ptr<ASRadioButton>(0);
}
// @0x140e28c80
template <> MS2Ptr<ASRadioButton> AScript::FUN_140bbe640<ASRadioButton>(const CString& strName, MS2Ptr<ASRadioButton>& outChild)
{
    MS2_ASCRIPT_INL_ASSERT(0xd5, outChild == NULL);
    outChild = FUN_140e159f0<ASRadioButton>(strName);
    return outChild;
}

// ---- the dialog ----

// @0x140e26c20
UIDungeonSearchSelectDialog::UIDungeonSearchSelectDialog()
    : m_nPage(1), m_bAll(true)
{
    SetTweenEnabled(1);
}

// @0x140e26d60
UIDungeonSearchSelectDialog::~UIDungeonSearchSelectDialog()
{
}

// @0x140e26e60
CString UIDungeonSearchSelectDialog::GetTypeName()
{
    return "DungeonSearchSelectDialog";
}

// @0x140e26eb0
void UIDungeonSearchSelectDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    BindDragBar("m_dragBar");
    BindCloseButton("m_closeButton");
    SD_BIND(m_30->FUN_140bbe640<ASRadioButton>("m_radioRecommend", m_radio), m_radio, 0x27);
    SD_BIND(m_30->FUN_140bc71c0<ASMovieClip>("m_customPage", m_page), m_page, 0x28);
    SD_BIND(m_30->FUN_140bbe640<ASButton>("m_okButton", m_okButton), m_okButton, 0x29);
    SD_BIND(m_page->FUN_140bc7340<ASScrollingList>("m_customList", m_list), m_list, 0x2b);
    if (!FUN_140c123f0((*m_page).FUN_1422bb890(), "m_listItem", 11, m_rows, 1))
        throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                  MS2_THIS_FILE, MS2_LINE(0x2e), __FUNCTION__));
    unsigned nZero = 0;
    m_roomOfRow.resize(m_rows.size(), nZero);
    m_okButton->FUN_1422c2a70(ParamsDelegate(this, &UIDungeonSearchSelectDialog::FUN_140e281f0), (void*)0);
    m_radio->FUN_1422c2a70(ParamsDelegate(this, &UIDungeonSearchSelectDialog::OnSelectAllClick), (void*)0);
    {
        MS2Ptr<ASCheckBox> spNone(0);
        m_checks.resize(m_rows.size(), spNone);
    }
    for (unsigned i = 0; i < m_rows.size(); ++i) {
        m_rows[i]->SetDataHandler(ParamsDelegate(this, &UIDungeonSearchSelectDialog::FUN_140e28280), FUN_140bd09d0(i));
        if (m_rows[i]->FUN_140c12010<ASCheckBox>("m_checkBox", m_checks[i]).get()) {
            m_checks[i]->AddSelectHandler(ParamsDelegate(this, &UIDungeonSearchSelectDialog::FUN_140e288f0), FUN_140bd09d0(i));
            m_checks[i]->AddClickHandler(ParamsDelegate(this, &UIDungeonSearchSelectDialog::FUN_140e28a40), 0);
        }
    }
    TSingleton<DungeonRoomTable>::GetInstance()->GetGroupRooms((DungeonGroupType)m_nPage, m_rooms);
    InitTitleAndRadio();
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
void UIDungeonSearchSelectDialog::InitSelection(int nPage, std::set<unsigned>& rooms, std::set<unsigned>* pSelected)
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
void UIDungeonSearchSelectDialog::InitTitleAndRadio()
{
    if (m_nPage == 1)
        SetChildText(GetGFxValue(), "m_title", L"$s_dungeonSearchSelect_title_normal");
    else
        SetChildText(GetGFxValue(), "m_title", L"$s_dungeonSearchSelect_title_raid");
    m_radio->SetSelected(m_bAll);
    UpdateListCount();
}

// @0x140e28100
void UIDungeonSearchSelectDialog::UpdateListCount()
{
    if (m_list.get() != 0)
        m_list->SetEmptyItemCount((int)m_rooms.size());
}

// @0x140e28170
void UIDungeonSearchSelectDialog::OnSelectAllClick(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_bAll)
        return;
    m_bAll = true;
    m_selected.clear();
    m_selected = m_allRooms;
    UpdateListCount();
}

// @0x140e281f0
void UIDungeonSearchSelectDialog::FUN_140e281f0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    UIDungeonSearchDialog* pDialog = GetDungeonSearchDialog(0x4f1c);
    if (pDialog != 0) {
        if (m_bAll)
            m_selected.clear();
        pDialog->SetPageRooms(m_nPage, m_selected);
    }
    vfunc_67();
}

// @0x140e28280
void UIDungeonSearchSelectDialog::FUN_140e28280(const Scaleform::GFx::FunctionHandler::Params& params)
{
    unsigned nRow = FUN_140bd09c0(params.pUserData);
    if (!((unsigned __int64)nRow < m_rows.size()))
        return;
    MS2Ptr<ASItemRendererBase> row = m_rows[nRow];
    MS2Ptr<ASCheckBox> check = m_checks[nRow];
    if (row == NULL || check == NULL)
        return;
    void* pPlayer = WorldService::GetInstance()->GetLocalPlayer();
    if (pPlayer == 0)
        return;
    unsigned nRoom = params.pArgs[0].GetUInt();
    if (!((unsigned __int64)nRoom < m_rooms.size())) {
        row->vfunc_3(0);
        return;
    }
    {
        bool bOk = ((class CPartyManager*)(void*)(reinterpret_cast<void*>(TSingleton<CPartyManager>::GetInstance())))->CanEnterDungeonRoom(m_rooms[nRoom]->GetDungeonRoomID());
        CStringW strName = GetRoomListText(m_rooms[nRoom], true);
        int nColor;
        if (bOk)
            nColor = 0xffffff;
        else
            nColor = 0xff0000;
        strName = FUN_14183e930(strName, nColor);
        row->vfunc_3(1);
        m_roomOfRow[nRow] = nRoom;
        row->SetMouseChildren(1);
        check->SetHtml(1);
        check->FUN_1422cdfb0(strName);
        unsigned nDungeon = m_rooms[nRoom]->GetDungeonRoomID();
        check->SetSelected(m_selected.find(nDungeon) != m_selected.end());
    }
}

// @0x140e286a0
void UIDungeonSearchSelectDialog::OnRowTooltip(const Scaleform::GFx::FunctionHandler::Params& params)
{
    unsigned nRow = FUN_140bd09c0(params.pUserData);
    if (!((unsigned __int64)nRow < m_rows.size()))
        return;
    MS2Ptr<ASItemRendererBase> row = m_rows[nRow];
    MS2Ptr<ASCheckBox> check = m_checks[nRow];
    if (row == NULL || check == NULL)
        return;
    unsigned nRoom = m_roomOfRow[nRow];
    CStringW strName = GetRoomListText(m_rooms[nRoom], true);
    ASTooltip tooltip(1, 2);
    tooltip.SetTooltipClass("export_common_tooltip_tooltipText");
    tooltip.SetOnDelay(300);
    tooltip.SetOffDelay(60000);
    tooltip.SetTooltipAlign(5);
    tooltip.SetText(strName);
    *params.pRetVal = tooltip.GetValue();
}

// @0x140e288f0
void UIDungeonSearchSelectDialog::FUN_140e288f0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    unsigned nRow = FUN_140bd09c0(params.pUserData);
    if (!((unsigned __int64)nRow < m_rows.size()))
        return;
    MS2Ptr<ASCheckBox> check = m_checks[nRow];
    if (check == NULL)
        return;
    unsigned nRoom = m_roomOfRow[nRow];
    unsigned nDungeon = m_rooms[nRoom]->GetDungeonRoomID();
    if (check->IsSelected())
        m_selected.insert(nDungeon);
    else
        m_selected.erase(nDungeon);
}

// @0x140e28a40
void UIDungeonSearchSelectDialog::FUN_140e28a40(const Scaleform::GFx::FunctionHandler::Params& params)
{
    m_bAll = false;
    m_radio->SetSelected(0);
}

// @0x140e28d40
UIDungeonSearchDialog* GetDungeonSearchDialog(int nUIType)
{
    if (reinterpret_cast<Unk_SdUIManager*>(TSingleton<CUIService>::GetInstance())) {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUIType);
        if (p.get())
            return dynamic_cast<UIDungeonSearchDialog*>((UIObject*)p);
    }
    return 0;
}
