// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDungeonSearchSettingDialog: see uidungeonsearchsettingdialog.h.
// MS2-UNIT: client\ms2\uidungeonsearchsettingdialog.cpp
// MS2-RANGE: 0x1400cbd20-0x1400cc000 .text$di
// MS2-RANGE: 0x140c0fdc0-0x140c15460 .text$mn
// MS2-RANGE: 0x142ca23a0-0x142ca24c0 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidungeonsearchsettingdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uidungeonsearchsettingdialog.h"
#include "uidungeoncategory.h"

#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di): the shared header statics a second time (another header of the unit pulls them in) ----
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ParamsDelegate;

// A display-object container built over a GFx value (ctor 0x1422c6570 / dtor 0x1422c65c0 are
// ASDisplayObjectContainer's): the gfxutil.h child search.
class Unk_SsNode : public ASDisplayObjectContainer
{
public:
    Unk_SsNode(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~Unk_SsNode();
    template <class T> MS2Ptr<T> FUN_140c120d0(const CString& strName);
    template <class T> MS2Ptr<T> FUN_140c12120(const Scaleform::GFx::Value& v, const CString& strName);
};

class Unk_SsWorld { public: void* FUN_141bd0cc0(); };            // the local player
Unk_SsWorld* FUN_1403ed2d0();
class Unk_SsUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nUiId); };
Unk_SsUIManager* FUN_1403ed2b0();

DungeonRoomTable* FUN_14031c2a0();
void* FUN_1409670d0();
bool FUN_14162ac70(void*, int);
unsigned FUN_140bd09c0(void* pUserData);
void* FUN_140bd09d0(unsigned n);
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);
MS2Ptr<ASCheckBox> FUN_140a57df0(int nMovieId, const Scaleform::GFx::Value& v);              // new ASCheckBox(v, n)
MS2Ptr<ASItemRendererBase> FUN_140bc6120(int nMovieId, const Scaleform::GFx::Value& v);      // new ASItemRendererBase(v, n)
MS2Ptr<ASDisplayObjectContainer> FUN_140bc5fc0(int nMovieId, const Scaleform::GFx::Value& v);
CStringW FUN_140e14bd0(MS2Ptr<DungeonRoom> pRoom, bool bShowLimit);                 // the room's list text
CStringW FUN_14183e930(const CStringW& str, int nColor);                            // wrap in a color tag
CStringW FUN_14028b8e0(const CStringW& strKey);                                     // the localized string
CStringW FUN_140cbf840(int nGroup);                                                 // the dungeon group's name
void FUN_140d01340(const Scaleform::GFx::Value& target, unsigned nParam, int nMovieId);

#define MS2_ASCRIPT_INL_ASSERT(line, expression) \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\ascript.inl", (unsigned)(line)), 0))
#define MS2_GFXUTIL_ASSERT(line, expression) \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gfxutil.h", (unsigned)(line)), 0))

#define SS_BIND(call, member, line) do { \
    call; \
    if (member == NULL) \
        throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", \
                                                  MS2_THIS_FILE, MS2_LINE(line), __FUNCTION__)); \
} while (0)

UIDungeonControlCenter* FUN_140c125c0(int nUIType);
template <> MS2Ptr<ASCheckBox> AScript::FUN_140c11f50<ASCheckBox>(const CString& strName);
template <> MS2Ptr<ASCheckBox> AScript::FUN_140c12010<ASCheckBox>(const CString& strName, MS2Ptr<ASCheckBox>& outChild);
template <class T> bool FUN_140c123f0(const Scaleform::GFx::Value& root, CString strName, unsigned nCount, std::vector<MS2Ptr<T> >& out, unsigned nStart);

// ---- the dialog ----

// @0x140c0fdc0
UIDungeonSearchSettingDialog::UIDungeonSearchSettingDialog()
    : m_nGroup(0)
{
    FUN_141924170(1);
}

// @0x140c0fee0
UIDungeonSearchSettingDialog::~UIDungeonSearchSettingDialog()
{
}

// @0x140c0ffd0
CString UIDungeonSearchSettingDialog::vfunc_1()
{
    return "DungeonSearchSettingDialog";
}
MS2_REPLACE_METHOD(0x140C0FFD0, UIDungeonSearchSettingDialog, vfunc_1, 61, 0x5109F1D4);

// MS2-FUNCTIONAL: frame/slot order of the AS bind temporaries (0x10 bytes larger frame, the CString argument temps of the
// drag bar / close button calls are built differently); calls and logic identical
// @0x140c10020
void UIDungeonSearchSettingDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    FUN_141925fa0("m_dragBar");
    FUN_141925ec0("m_closeButton");
    SS_BIND(m_30->FUN_140bbe7c0<ASDropdownMenu>("m_groupDropdown", m_group), m_group, 0x27);
    SS_BIND(m_30->FUN_140bc71c0<ASMovieClip>("m_customPage", m_page), m_page, 0x28);
    SS_BIND(m_30->FUN_140bbe640<ASButton>("m_okButton", m_okButton), m_okButton, 0x29);
    SS_BIND(m_page->FUN_140bc7340<ASScrollingList>("m_customList", m_list), m_list, 0x2a);
    if (!FUN_140c123f0((*m_page).FUN_1422bb890(), "m_listItem", 11, m_rows, 1))
        throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                  MS2_THIS_FILE, MS2_LINE(0x2d), __FUNCTION__));
    if (MS2Ptr<ASTextField> spDesc = GetChild<ASTextField>("m_groupDesc"))
        FUN_140d01340((*spDesc).FUN_1422bb890(), 2, 2);
    m_group->FUN_1422dfce0(FUN_14028b8e0(L"s_dungeon_search_setting_group_none"));
    m_group->FUN_1422dfce0(FUN_140cbf840(1));
    m_group->FUN_1422dfce0(FUN_140cbf840(2));
    m_group->FUN_1422df5f0(3);
    m_group->FUN_1422df690(0);
    m_roomOfRow.resize(m_rows.size(), 0);
    m_okButton->FUN_1422c2a70(ParamsDelegate(this, &UIDungeonSearchSettingDialog::FUN_140c113c0), 0);
    m_group->FUN_1422df9a0(ParamsDelegate(this, &UIDungeonSearchSettingDialog::FUN_140c11370), 0);
    m_checks.resize(m_rows.size(), MS2Ptr<ASCheckBox>(0));
    for (unsigned i = 0; i < m_rows.size(); ++i) {
        m_rows[i]->FUN_1422e1f50(ParamsDelegate(this, &UIDungeonSearchSettingDialog::FUN_140c11420), FUN_140bd09d0(i));
        if (m_rows[i]->FUN_140c12010<ASCheckBox>("m_checkBox", m_checks[i]).get() != 0)
            m_checks[i]->FUN_1422ce320(ParamsDelegate(this, &UIDungeonSearchSettingDialog::FUN_140c11840), FUN_140bd09d0(i));
    }
    FUN_140c11190(m_nGroup);
    FUN_140c112e0();
}

// @0x140c110b0
void UIDungeonSearchSettingDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_nGroup = 0;
    m_group = 0;
    m_page = 0;
    m_okButton = 0;
    m_list = 0;
    m_rows.clear();
    m_checks.clear();
    m_roomOfRow.clear();
    m_rooms.clear();
    m_selected.clear();
}
MS2_REPLACE_METHOD(0x140C110B0, UIDungeonSearchSettingDialog, vfunc_26, 218, 0x943477A1);

// @0x140c11190
void UIDungeonSearchSettingDialog::FUN_140c11190(int nGroup)
{
    m_rooms.clear();
    m_nGroup = nGroup;
    switch (nGroup) {
    case 0:
        FUN_14031c2a0()->GetGroupRooms((DungeonGroupType)1, m_rooms);
        FUN_14031c2a0()->GetGroupRooms((DungeonGroupType)2, m_rooms);
        break;
    case 1:
        FUN_14031c2a0()->GetGroupRooms((DungeonGroupType)1, m_rooms);
        break;
    case 2:
        FUN_14031c2a0()->GetGroupRooms((DungeonGroupType)2, m_rooms);
        break;
    }
}
MS2_REPLACE_METHOD(0x140C11190, UIDungeonSearchSettingDialog, FUN_140c11190, 262, 0xF2E97D1F);

// @0x140c112a0
void UIDungeonSearchSettingDialog::FUN_140c112a0(const std::set<unsigned>& selected)
{
    m_selected = selected;
}
MS2_REPLACE_METHOD(0x140C112A0, UIDungeonSearchSettingDialog, FUN_140c112a0, 43, 0x1EB6C01A);

// @0x140c112e0
void UIDungeonSearchSettingDialog::FUN_140c112e0()
{
    FUN_140c11300();
}
MS2_REPLACE_METHOD(0x140C112E0, UIDungeonSearchSettingDialog, FUN_140c112e0, 24, 0x56AAF3CF);

// @0x140c11300
void UIDungeonSearchSettingDialog::FUN_140c11300()
{
    if (m_list)
        m_list->FUN_1422dcf40((int)m_rooms.size());
}
MS2_REPLACE_METHOD(0x140C11300, UIDungeonSearchSettingDialog, FUN_140c11300, 94, 0xBF7D9412);

// @0x140c11370
void UIDungeonSearchSettingDialog::FUN_140c11370(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nGroup = m_group->FUN_1422df6c0();
    FUN_140c11190(nGroup);
    FUN_140c112e0();
}
MS2_REPLACE_METHOD(0x140C11370, UIDungeonSearchSettingDialog, FUN_140c11370, 74, 0x86F00231);

// @0x140c113c0
void UIDungeonSearchSettingDialog::FUN_140c113c0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    UIDungeonControlCenter* pCenter = FUN_140c125c0(0x4f84);
    if (pCenter != 0)
        pCenter->FUN_140c0ba70(m_selected);
    vfunc_67();
}
MS2_REPLACE_METHOD(0x140C113C0, UIDungeonSearchSettingDialog, FUN_140c113c0, 85, 0xAFBE2F18);

// MS2-FUNCTIONAL: the dungeon id argument of FUN_14162ac70 is reloaded through ecx in the exe (mov ecx,[x]; mov edx,ecx)
// @0x140c11420
void UIDungeonSearchSettingDialog::FUN_140c11420(const Scaleform::GFx::FunctionHandler::Params& params)
{
    unsigned nRow = FUN_140bd09c0(params.pUserData);
    if (nRow >= m_rows.size())
        return;
    {
        MS2Ptr<ASItemRendererBase> row = m_rows[nRow];
        MS2Ptr<ASCheckBox> check = m_checks[nRow];
        if (row == NULL || check == NULL)
            return;
        void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return;
        unsigned nRoom = params.pArgs[0].GetUInt();
        if (!(nRoom < m_rooms.size())) {
            row->vfunc_3(0);
            return;
        }
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
        row->FUN_1422c6640(true);
        check->FUN_1422cdf20(true);
        check->FUN_1422cdfb0(strName);
        unsigned nDungeon = m_rooms[nRoom]->GetDungeonRoomID();
        unsigned nChecked = m_selected.find(nDungeon) != m_selected.end();
        check->FUN_1422ce090(nChecked);
    }
}
MS2_REPLACE_METHOD(0x140C11420, UIDungeonSearchSettingDialog, FUN_140c11420, 1039, 0xF3C3DE4F);

// @0x140c11840
void UIDungeonSearchSettingDialog::FUN_140c11840(const Scaleform::GFx::FunctionHandler::Params& params)
{
    unsigned nRow = FUN_140bd09c0(params.pUserData);
    if (nRow >= m_rows.size())
        return;
    MS2Ptr<ASCheckBox> check = m_checks[nRow];
    if (check == NULL)
        return;
    unsigned nRoom = m_roomOfRow[nRow];
    unsigned nDungeon = m_rooms[nRoom]->GetDungeonRoomID();
    if (check->FUN_1422ce0e0())
        m_selected.insert(nDungeon);
    else
        m_selected.erase(nDungeon);
}
MS2_REPLACE_METHOD(0x140C11840, UIDungeonSearchSettingDialog, FUN_140c11840, 321, 0xF0904311);

// ---- template COMDATs first instantiated here ----

// @0x140c11f50
template <> MS2Ptr<ASCheckBox> AScript::FUN_140c11f50<ASCheckBox>(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (FUN_1409b4d40(v))
        return FUN_140a57df0(m_nMovieId, v);
    return MS2Ptr<ASCheckBox>(0);
}

// @0x140c12010
template <> MS2Ptr<ASCheckBox> AScript::FUN_140c12010<ASCheckBox>(const CString& strName, MS2Ptr<ASCheckBox>& outChild)
{
    MS2_ASCRIPT_INL_ASSERT(0xd5, outChild == NULL);
    outChild = FUN_140c11f50<ASCheckBox>(strName);
    return outChild;
}

// @0x140c120d0
template <class T> MS2Ptr<T> Unk_SsNode::FUN_140c120d0(const CString& strName)
{
    return FUN_140c12120<T>(m_value, strName);
}

// @0x140c12120: getChildByName, else a depth-first search of the children
template <class T> MS2Ptr<T> Unk_SsNode::FUN_140c12120(const Scaleform::GFx::Value& v, const CString& strName)
{
    MS2Ptr<ASDisplayObjectContainer> spObj = FUN_140bc5fc0(m_nMovieId, v);
    if (!spObj->FUN_1422ba9f0("getChildByName"))
        return MS2Ptr<T>(0);
    Scaleform::GFx::Value child = spObj->FUN_1422c6b00(strName);
    if (child.IsObject())
        return FUN_140bc6120(m_nMovieId, child);
    if (!spObj->FUN_1422ba9f0("numChildren"))
        return MS2Ptr<T>(0);
    int nCount = spObj->FUN_1422c6670();
    for (int i = 0; i < nCount; i++) {
        Scaleform::GFx::Value sub = spObj->FUN_1422c6aa0(i);
        if (!sub.IsObject())
            continue;
        MS2Ptr<T> spFound = FUN_140c12120<T>(sub, strName);
        if (spFound.get() != 0)
            return spFound;
    }
    return MS2Ptr<T>(0);
}

// @0x140c123f0: gfxutil.h, binds strName<nStart>..strName<nStart+nCount-1> into out.
template <class T> bool FUN_140c123f0(const Scaleform::GFx::Value& root, CString strName, unsigned nCount, std::vector<MS2Ptr<T> >& out, unsigned nStart)
{
    if (!FUN_1409b4d40(root))
        return false;
    out.clear();
    out.reserve(nCount);
    for (unsigned i = nStart; i < nCount + nStart; ++i) {
        Unk_SsNode node(root, 2);
        MS2Ptr<T> spChild = node.FUN_140c120d0<T>(StringFormat("{0}{1}", strName, i));
        if (spChild == NULL) {
            MS2_GFXUTIL_ASSERT(99, 0);
            return false;
        }
        out.push_back(spChild);
    }
    return true;
}

// @0x140c125c0
UIDungeonControlCenter* FUN_140c125c0(int nUIType)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nUIType);
        if (p.get())
            return dynamic_cast<UIDungeonControlCenter*>((UIObject*)p);
    }
    return 0;
}
