// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's gameoptioninputdefault.cpp: the key-binding tabs
// of the game options (CGameOptionInputDefault, tab ids 9..13), the pending key input of the option pages and the
// "input changed" notice.
// MS2-UNIT: ?\gameoptioninputdefault.cpp
// MS2-RANGE: 0x141250a80-0x1412558c0 .text$mn
// MS2-RANGE: 0x1400ea840-0x1400ea9f0 .text$di
// MS2-RANGE: 0x142cae070-0x142cae0f0 .text$yd
// MS2-PIN: ??_GCGameOptionInputDefault@@UEAAPEAXI@Z 0x141254110
// MS2-PIN: ??_GNotifyChangeGameOptionInput@@UEAAPEAXI@Z 0x141254150
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameoptioninputdefault.cpp"    // assumed
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"
#include "gameoptioninputdefault.h"
#include <stdlib.h>
#include "ms2/client/ms2/uigameoptiondialog.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/notifychangebuff.h"
#include "ms2/client/ms2/ms2inputservice.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/placeholder/ckeysettingparam.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/pendingkeyinput.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include <sstream>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe types ----

MS2_CHECK_SIZE(ASScrollingList, 0x88);

// A key code as a custom-formatted fmt argument (same name as guess\usercommandcli.cpp's).
enum Unk_CommandKeyCode : int {};
// fmt's ostream formatting of a custom argument with the MS2 enum shortcut in front (same shape as
// itembreakmanager.cpp 0x140534820): the stream branch is dead code for enums.
// @0x141253910
template <> inline void fmt::format_arg(BasicFormatter<wchar_t>& f, const wchar_t*& format_str, const Unk_CommandKeyCode& value)
{
    internal::Arg arg;
    internal::Value& arg_value = arg;
    if (std::is_enum<Unk_CommandKeyCode>::value)
    {
        arg.int_value = value;
        arg.type = internal::Arg::INT;
    }
    else
    {
        std::basic_ostringstream<wchar_t> os;
        os << value;
        std::basic_string<wchar_t> str = os.str();
        arg_value = internal::MakeValue<BasicFormatter<wchar_t> >(str);
        arg.type = internal::Arg::STRING;
    }
    format_str = f.format(format_str, arg);
}

class UIMainPlayerInfo
{
public:
    void RefreshQuickSlots();                                               // refresh the quick slots
    void UpdateModifiedKeys();                                               // back up the quick slots
};

UIMainPlayerInfo* FindMainPlayerInfo(int nUiId);
UIGameOptionDialog* FindGameOptionDialog(int nDialogId);
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
MS2InputService* FUN_140a58540();
class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10
void FUN_14151f200();                                                   // close the open message box
void FUN_141901390(int nRelease, int nUiType);                          // block / release the player's keys for a UI
int FUN_14092f690(int, int, __int64, int, int);   // C3: was FUN_14092f690
void ShowMessageBox(CStringW text, int nType, void* pListener, CStringW tag);       // notice box
void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW tag);          // notice box by string id
MS2Ptr<CMsgBoxData> CreateMessageBox(int nType, CStringW text, void* pListener, CStringW tag);   // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                            // show it
CStringW BlockFormat(int nStrId);                                       // string table text by id
CStringW GetStringCommonByKey(const CStringW& strKey);                         // string table text by key
template <class A> CStringW FormatStringId(int nId, const A& a);

template<class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

// The quick-slot backup of the input tab and the keys captured while no edit was active (exe statics 0x143ad5330 /
// 0x143ad5334).
static CString s_sortNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;                   // 0x143ad52b0
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static int s_nCapturedKey;                                              // 0x143ad5330
static int s_nHeldKey;                                                  // 0x143ad5334

// ---- CGameOptionInputDefault ----

// @0x141250a80
CGameOptionInputDefault::CGameOptionInputDefault(int nId, int nType)
    : CBaseOption(nId, nType), m_nRelease(1)
{
    m_bChanged = 0;
    m_spEdit = 0;
    m_nOldKey = 0;
}

// @0x141250b90
CGameOptionInputDefault::~CGameOptionInputDefault()
{
}

// @0x141250c10
void CGameOptionInputDefault::vfunc_3(int n)
{
    if (n == 0)
    {
        CBaseOption::vfunc_3(n);
        BackupKeys();
        FUN_141252460();
        m_bChanged = 0;
        m_bConfirm = 0;
    }
    else
    {
        RefreshKeyList(m_nType);
    }
}
MS2_REPLACE_METHOD(0x141250C10, CGameOptionInputDefault, vfunc_3, 103, 0x93C7A2C7);

// @0x141250c80
void CGameOptionInputDefault::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
    if (n == 0)
        FUN_141252460();
}
MS2_REPLACE_METHOD(0x141250C80, CGameOptionInputDefault, vfunc_4, 49, 0x11C004CC);

// @0x141250cc0
void CGameOptionInputDefault::RefreshKeyList(int nCategory)
{
    MS2Ptr<ASScrollingList> spList = GetOptionDialog()->GetTabChild<ASScrollingList>("m_keyList", nCategory);
    if (spList == 0)
        return;
    double dScroll = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(spList.operator ASScrollingList*()->GetMember("scrollPosition")))->GetNumber();
    int bGamePad = ((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xb5);
    spList.operator ASScrollingList*()->FUN_1422dd1d0();
    TPtrValue<ATL::CAtlList<MS2Ptr<CKeySettingParam> > > spKeys = GetKeyTable()->GetSettingList(m_nId);
    if (spKeys.get() != 0)
    {
        bool bFirst = true;
        for (POSITION pos = spKeys->GetHeadPosition(); pos != 0; spKeys->GetNext(pos))
        {
            MS2Ptr<CKeySettingParam> spKey = spKeys->GetAt(pos);
            int nPrimary = GetKeyTable()->FindKeyByActionAndPriority(spKey->m_nAction, 0);
            int nSecondary = GetKeyTable()->FindKeyByActionAndPriority(spKey->m_nAction, 1);
            int nThirdly = GetKeyTable()->FindKeyByActionAndPriority(spKey->m_nAction, 2);
            ASObj row(2);
            if (spKey->m_nAction == 0x49409)
            {
                ((class AScript&)(row)).SetWStringMember("label", TSingleton<CStringTable>::GetInstance()->FUN_1418125b0(0x49409));
                row.FUN_141253870("keyGUID", 0x49409);
                ((class AScript&)(row)).SetWStringMember("secondaryKey", GetKeyTable()->GetKeyName(1));
            }
            else
            {
                ((class AScript&)(row)).SetWStringMember("label", TSingleton<CStringTable>::GetInstance()->FUN_1418125b0((int)spKey->m_nAction));
                row.SetStringMember("keyGUID", ActionToString(spKey->m_nAction));
                ((class AScript&)(row)).SetWStringMember("secondaryKey", GetKeyTable()->GetKeyName(nSecondary));
            }
            ((class AScript&)(row)).SetWStringMember("primaryKey", GetKeyTable()->GetKeyName(nPrimary));
            ((class AScript&)(row)).SetWStringMember("thirdlyKey", bGamePad ? GetKeyTable()->GetKeyName(nThirdly) : CStringW(L""));
            row.SetBoolMember("primaryEnable", 0 != 1 && spKey->m_nPrimaryLocked == 0);
            row.SetBoolMember("secondaryEnable", 0 != 1 && spKey->m_nSecondaryLocked == 0);
            row.SetBoolMember("thirdlyEnable", 0 != 1 && spKey->m_nThirdlyLocked == 0);
            ((class AScript&)(row)).SetIntMember("isGamePad", bGamePad);
            spList.operator ASScrollingList*()->AddItem(row);
        }
    }
    static_cast<ASObj*>(static_cast<AScript*>(spList.operator ASScrollingList*()))->FUN_140e06d60("scrollPosition", dScroll);
    spList.operator ASScrollingList*()->vfunc_24(true);
    MS2Ptr<ASUIComponent> spTab = GetOptionDialog()->GetTabComponent(m_nType);
    if (static_cast<ASUIComponent*>(spTab) != 0)
        static_cast<AScript*>(spTab.operator->())->Invoke("refreshScrollBar");
}

// @0x141251490
void CGameOptionInputDefault::vfunc_13()
{
    if (m_timer.IsExpired() != 0)
    {
        m_timer.Reset();
        FUN_141252cf0(1);
    }
}

// @0x1412514e0
void CGameOptionInputDefault::vfunc_6()
{
    RefreshKeyList(m_nType);
}
MS2_REPLACE_METHOD(0x1412514E0, CGameOptionInputDefault, vfunc_6, 32, 0xE4042622);

// @0x141251510
void CGameOptionInputDefault::vfunc_7()
{
    RefreshKeyList(m_nType);
}
MS2_REPLACE_METHOD(0x141251510, CGameOptionInputDefault, vfunc_7, 32, 0x73BAC012);

// Polls the key capture while a slot is being edited (reads the unit static s_nHeldKey: not hooked).
// @0x141251540
int CGameOptionInputDefault::vfunc_8()
{
    if (m_spEdit == 0)
        return 0;
    UIGameOptionDialog* pDialog = FindGameOptionDialog(0x4ef3);
    if (pDialog == 0)
        return 0;
    if (m_bConfirm != 0)
        return 0;
    bool bCaptured = false;
    Unk_CommandKeyCode nKey = (Unk_CommandKeyCode)0;
    int nHeld = GetKeyTable()->FindActiveComboPrefixKey(0);
    if (nHeld != 0)
    {
        nKey = (Unk_CommandKeyCode)GetKeyTable()->FindActiveKey(0);
        if (nHeld != nKey)
        {
            if (GetKeyTable()->FUN_141430cb0(nKey) != 0)
            {
                s_nHeldKey = 0;
                bCaptured = false;
                return 0;
            }
            if (nKey != 0)
            {
                s_nHeldKey = 0;
                bCaptured = true;
            }
            else
            {
                if (nHeld != s_nHeldKey)
                    s_nHeldKey = nHeld;
                return 0;
            }
        }
        else
        {
            if (nHeld != s_nHeldKey)
                s_nHeldKey = nHeld;
            return 0;
        }
    }
    else
    {
        nKey = (Unk_CommandKeyCode)GetKeyTable()->FindActiveKey(0);
        if (nKey != 0)
        {
            s_nHeldKey = 0;
            bCaptured = true;
        }
        else if (s_nHeldKey != 0)
        {
            nKey = (Unk_CommandKeyCode)s_nHeldKey;
            s_nHeldKey = 0;
            bCaptured = true;
        }
    }
    if (bCaptured)
    {
        if (FUN_141252d40(nKey) == 0)
        {
            m_bConfirm = 1;
            s_nHeldKey = 0;
            bCaptured = false;
            return 0;
        }
        if (GetKeyTable()->IsKeyRebindable(nKey) == 0)
        {
            FUN_140d73bc0(0x84c, 0, 0, CStringW(L""));
            return 1;
        }
        __int64 nAction = GetKeyTable()->GetKeyAction(nKey);
        if (nAction != 0)
        {
            CStringW strKey = StringFormat(L"{0}", nKey);
            CStringW strName;
            if (GetKeyTable()->IsQuickSlotAction(nAction) != 0)
                strName = StringFormat<CStringW, CStringW>(L"{0}[{1}]", TSingleton<CStringTable>::GetInstance()->FUN_1418125b0((int)GetKeyTable()->GetKeyAction(nKey)), GetKeyTable()->GetKeyName(nKey));
            else
                strName = TSingleton<CStringTable>::GetInstance()->FUN_1418125b0((int)nAction);
            if (GetKeyTable()->FUN_141430470(nAction) == 0)
            {
                m_bConfirm = 1;
                ShowMessageBox(FormatStringId<CStringW>(0x84f, strName), 1, static_cast<IMessageListener*>(this), CStringW(strKey));
            }
            else
            {
                FUN_141252700(nKey);
            }
        }
        else
        {
            FUN_141252700(nKey);
        }
    }
    return 1;
}

// @0x141251a30
int CGameOptionInputDefault::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    ASData data;
    if (_stricmp("OnSelectCategory", pszName) == 0)
    {
        if (data.SetArgsIfAny((const Scaleform::GFx::Value*)pArg, nArg) != 0)
            RefreshKeyList(data.PopUInt());
        return 1;
    }
    else if (_stricmp("onFocusInPrimary", pszName) == 0)
    {
        if (data.SetArgsIfAny((const Scaleform::GFx::Value*)pArg, nArg) != 0)
            BeginKeyEdit(data.FUN_1422b8d30(), 0);
        return 1;
    }
    else if (_stricmp("onFocusInSecondary", pszName) == 0)
    {
        if (data.SetArgsIfAny((const Scaleform::GFx::Value*)pArg, nArg) != 0)
            BeginKeyEdit(data.FUN_1422b8d30(), 1);
        return 1;
    }
    else if (_stricmp("onFocusInThirdly", pszName) == 0)
    {
        if (data.SetArgsIfAny((const Scaleform::GFx::Value*)pArg, nArg) != 0)
            BeginKeyEdit(data.FUN_1422b8d30(), 2);
        return 1;
    }
    else if (_stricmp("onFocusOutPrimary", pszName) == 0)
    {
        if (m_bConfirm == 0)
            FUN_141252460();
        return 1;
    }
    else if (_stricmp("onFocusOutSecondary", pszName) == 0)
    {
        if (m_bConfirm == 0)
            FUN_141252460();
        return 1;
    }
    else if (_stricmp("onFocusOutThirdly", pszName) == 0)
    {
        if (m_bConfirm == 0)
            FUN_141252460();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141251A30, CGameOptionInputDefault, vfunc_5, 825, 0xD9D6C1D4);

// @0x141251d90
int CGameOptionInputDefault::vfunc_14()
{
    return m_bChanged;
}

// @0x141251db0
void CGameOptionInputDefault::vfunc_9()
{
    if (m_nId == 9)
    {
        FUN_141252940();
        FUN_141252ae0();
    }
}
MS2_REPLACE_METHOD(0x141251DB0, CGameOptionInputDefault, vfunc_9, 45, 0xE253219B);

// @0x141251df0
void CGameOptionInputDefault::vfunc_10()
{
    CBaseOption::vfunc_10();
    GetKeyTable()->SendKeysToServer();
    BackupKeys();
    m_mapQuickSlots.RemoveAll();
    UIMainPlayerInfo* pInfo = FindMainPlayerInfo(0x4e5f);
    if (pInfo != 0)
        pInfo->UpdateModifiedKeys();
    FUN_1412532f0(MS2Ptr<CGameOptionInputDefault>(this));
    m_bChanged = 0;
}
MS2_REPLACE_METHOD(0x141251DF0, CGameOptionInputDefault, vfunc_10, 151, 0x1D8A8953);

// @0x141251e90
void CGameOptionInputDefault::vfunc_12()
{
    if (GetOptionDialog()->FUN_141254a00() != 0)
    {
        if (((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xb5) == true)
        {
            if (FUN_141252c10() != 0)
            {
                MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(6, GetStringCommonByKey(L"s_gameoption_input_reset_message"), static_cast<IMessageListener*>(this), CStringW(L""));
                if (spBox.get() != 0)
                {
                    int bPad = FUN_140a58540()->GetPadKind() != 0 ? 1 : 0;
                    CStringW strPad = StringFormat<int>(L"{0}", bPad);
                    spBox->AddStringArg(strPad);
                    spBox->SetButtonPreset(2);
                    spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CGameOptionInputDefault::FUN_1412523d0));
                    FUN_140d73c60(spBox);
                }
            }
        }
        else
        {
            ResetKeysToDefault(0);
        }
    }
    else
    {
        ResetKeysToDefault(FUN_140a58540()->GetPadKind());
    }
}
MS2_REPLACE_METHOD(0x141251E90, CGameOptionInputDefault, vfunc_12, 792, 0xC9B934FA);

// @0x1412521b0
CString CGameOptionInputDefault::GetTypeName()
{
    return CString("GameOptionInput");
}
MS2_REPLACE_METHOD(0x1412521B0, CGameOptionInputDefault, GetTypeName, 61, 0x6290AFE9);

// @0x141252200
void CGameOptionInputDefault::ResetKeysToDefault(int nPadKind)
{
    if (FUN_141252c10() != 0)
    {
        FUN_141252970();
        BOOL bDefault = FALSE;
        if (((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xb5) == true)
        {
            if (nPadKind == 2)
            {
                CString strPath("./Data/Xml/Table/default/DefaultPSKey.xml");
                GetKeyTable()->FUN_141429e60(strPath);
            }
            else if (nPadKind == 1 || nPadKind == 3)
            {
                CString strPath("./Data/Xml/Table/default/DefaultXboxKey.xml");
                GetKeyTable()->FUN_141429e60(strPath);
            }
            else
            {
                bDefault = TRUE;
            }
        }
        else
        {
            bDefault = TRUE;
        }
        if (bDefault)
        {
            CString strPath("./Data/Xml/Table/default/DefaultKey.xml");
            GetKeyTable()->FUN_1414297e0(strPath, 0);
        }
        UIMainPlayerInfo* pInfo = FindMainPlayerInfo(0x4e5f);
        if (pInfo != 0)
            pInfo->RefreshQuickSlots();
        FUN_1412532f0(MS2Ptr<CGameOptionInputDefault>(this));
    }
    if (IsCurrentTab() != 0)
        RefreshKeyList(m_nType);
    m_spEdit = 0;
}
MS2_REPLACE_METHOD(0x141252200, CGameOptionInputDefault, ResetKeysToDefault, 447, 0xA3356950);

// @0x1412523d0
bool CGameOptionInputDefault::FUN_1412523d0(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        int nPad = _wtoi(data.FUN_141a02d50());
        if (nPad == 0)
            ResetKeysToDefault(0);
        else
            ResetKeysToDefault(FUN_140a58540()->GetPadKind());
    }
    return true;
}
MS2_REPLACE_METHOD(0x1412523D0, CGameOptionInputDefault, FUN_1412523d0, 133, 0xE03E012E);

// @0x141252460
void CGameOptionInputDefault::FUN_141252460()
{
    if (FUN_141252ea0() == 1)
    {
        m_spEdit = 0;
        m_nOldKey = 0;
        m_timer.Reset();
        FUN_141252cf0(1);
    }
    else
    {
        FUN_141252840(0);
    }
}
MS2_REPLACE_METHOD(0x141252460, CGameOptionInputDefault, FUN_141252460, 106, 0x663E098F);

// @0x1412524d0
void CGameOptionInputDefault::FUN_1412524d0(__int64 nAction, int nPriority)
{
    int nKey = GetKeyTable()->FindKeyByActionAndPriority(nAction, nPriority);
    if (nKey != 0)
        GetKeyTable()->FUN_14142b1c0(nKey, 0, 0, 0, nPriority, -1);
}
MS2_REPLACE_METHOD(0x1412524D0, CGameOptionInputDefault, FUN_1412524d0, 105, 0x3F233A27);

// @0x141252540
CString CGameOptionInputDefault::ActionToString(__int64 nAction)
{
    CString str;
    str.Format("%I64u", nAction);
    return str;
}
MS2_REPLACE_METHOD(0x141252540, CGameOptionInputDefault, ActionToString, 119, 0xDEBE352D);

// @0x1412525c0
void CGameOptionInputDefault::BeginKeyEdit(CString strAction, int nPriority)
{
    m_bChanged = 1;
    __int64 nAction = atoi(strAction);
    if (nAction == 0)
        return;
    MS2Ptr<CKeySettingParam> spKey = GetKeyTable()->FindSettingParam(nAction);
    if (spKey.get() != 0)
    {
        m_nOldKey = GetKeyTable()->FindKeyByActionAndPriority(nAction, nPriority);
        m_spEdit = spKey;
        m_spEdit->m_nPriority = nPriority;
        FUN_1412524d0(nAction, nPriority);
        FUN_141252cf0(0);
        GetKeyTable()->FUN_14142a8b0(nAction);
    }
    FUN_140a02d90(1);
}
MS2_REPLACE_METHOD(0x1412525C0, CGameOptionInputDefault, BeginKeyEdit, 300, 0x3E06C36B);

// @0x141252700
void CGameOptionInputDefault::FUN_141252700(int nKey)
{
    if (m_spEdit == 0 || nKey == 0)
        return;
    if (GetKeyTable()->FUN_14142b1c0(nKey, m_spEdit->m_nType, m_spEdit->m_nAction, 0, m_spEdit->m_nPriority, m_nOldKey) != 0)
    {
        RefreshKeyList(m_nType);
        m_timer.Start(300);
        GetKeyTable()->FUN_14142a8b0(m_spEdit->m_nAction);
        m_spEdit = 0;
        m_nOldKey = 0;
    }
}
MS2_REPLACE_METHOD(0x141252700, CGameOptionInputDefault, FUN_141252700, 302, 0xB96707DF);

// @0x141252840
void CGameOptionInputDefault::FUN_141252840(int nMsgId)
{
    FUN_141252700(m_nOldKey);
    if (nMsgId != 0)
        ShowMessageBox(BlockFormat(nMsgId), 0, static_cast<IMessageListener*>(this), CStringW(L""));
}
MS2_REPLACE_METHOD(0x141252840, CGameOptionInputDefault, FUN_141252840, 201, 0xD16B40F0);

// @0x141252910
void CGameOptionInputDefault::BackupKeys()
{
    if (m_nId == 9)
        GetKeyTable()->BackupKeys();
}
MS2_REPLACE_METHOD(0x141252910, CGameOptionInputDefault, BackupKeys, 38, 0x7A1FD070);

// @0x141252940
void CGameOptionInputDefault::FUN_141252940()
{
    if (m_nId == 9)
        GetKeyTable()->RestoreKeysFromBackup();
}
MS2_REPLACE_METHOD(0x141252940, CGameOptionInputDefault, FUN_141252940, 38, 0xEAAB0136);

// @0x141252970
void CGameOptionInputDefault::FUN_141252970()
{
    if (FUN_141252c10() != 0)
    {
        m_mapQuickSlots.RemoveAll();
        ATL::CAtlArray<Unk_MyPCKeyId> aSlots;
        GetKeyTable()->GetBoundKeys(aSlots);
        for (unsigned int i = 0; i < aSlots.GetCount(); i++)
        {
            int nSkillId = GetKeyTable()->GetSkillIdByKey(aSlots[i]);
            __int64 nItemUid = GetKeyTable()->GetQuickSlotItemUidByKey(aSlots[i]);
            int nSlot = GetKeyTable()->FindQuickSlotBySkillAndItemUid(nSkillId, nItemUid);
            if (nSlot != -1)
            {
                Unk_SsQuickEntry entry;
                entry.m_nSkillId = nSkillId;
                entry.m_nItemUid = nItemUid;
                m_mapQuickSlots.SetAt(nSlot, entry);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141252970, CGameOptionInputDefault, FUN_141252970, 355, 0xF2819452);

// @0x141252ae0
void CGameOptionInputDefault::FUN_141252ae0()
{
    int nPage = GetKeyTable()->FUN_140a700b0();
    for (POSITION pos = m_mapQuickSlots.GetStartPosition(); pos != 0; m_mapQuickSlots.GetNext(pos))
    {
        Unk_SsQuickEntry& entry = m_mapQuickSlots.GetValueAt(pos);
        unsigned int nSlot = m_mapQuickSlots.GetKeyAt(pos);
        FUN_14092f690(entry.m_nSkillId, entry.m_nItemId, entry.m_nItemUid, nPage, nSlot);
    }
    UIMainPlayerInfo* pInfo = FindMainPlayerInfo(0x4e5f);
    if (pInfo != 0)
        pInfo->RefreshQuickSlots();
    FUN_1412532f0(MS2Ptr<CGameOptionInputDefault>(this));
}
MS2_REPLACE_METHOD(0x141252AE0, CGameOptionInputDefault, FUN_141252ae0, 283, 0x4FC0DDCF);

// @0x141252c10
int CGameOptionInputDefault::FUN_141252c10()
{
    int nTab = GetOptionDialog()->FUN_141254590();
    if (m_nId >= 9 && m_nId <= 12)
        return m_nType == nTab;
    else
        return m_nType == 9;
}
MS2_REPLACE_METHOD(0x141252C10, CGameOptionInputDefault, FUN_141252c10, 129, 0xAF14C376);

// @0x141252ca0
int CGameOptionInputDefault::IsCurrentTab()
{
    return GetOptionDialog()->FUN_141254590() == m_nType;
}
MS2_REPLACE_METHOD(0x141252CA0, CGameOptionInputDefault, IsCurrentTab, 64, 0xD437D43C);

// @0x141252cf0
void CGameOptionInputDefault::FUN_141252cf0(int bRelease)
{
    if (m_nRelease == bRelease)
        return;
    m_nRelease = bRelease;
    FUN_141901390(m_nRelease, 0x4ef3);
}
MS2_REPLACE_METHOD(0x141252CF0, CGameOptionInputDefault, FUN_141252cf0, 64, 0xB70E74E8);

// @0x141252d40
int CGameOptionInputDefault::FUN_141252d40(int nKey)
{
    if (GetKeyTable()->FUN_141430b10(m_spEdit->m_nAction) != 0 && GetKeyTable()->IsGamepadShoulderKey(nKey) == 0)
    {
        FUN_141252840(0x853);
        return 0;
    }
    if (GetKeyTable()->IsGamepadShoulderKey(nKey) != 0 &&
        GetKeyTable()->FUN_141430b10(GetKeyTable()->GetKeyAction(nKey)) != 0 &&
        GetKeyTable()->FUN_141430b10(m_spEdit->m_nAction) == 0)
    {
        FUN_141252840(0x853);
        return 0;
    }
    if (m_spEdit->m_nPriority == 2)
    {
        if (nKey < 0x91)
        {
            FUN_141252840(0x855);
            return 0;
        }
    }
    else if (GetKeyTable()->IsGamepadKey(nKey) != 0)
    {
        FUN_141252840(0x854);
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141252D40, CGameOptionInputDefault, FUN_141252d40, 343, 0x7D4536E8);

// @0x141252ea0
int CGameOptionInputDefault::FUN_141252ea0()
{
    if (m_spEdit == 0)
        return 1;
    __int64 nAction = 0;
    nAction = m_spEdit->m_nAction;
    if (GetKeyTable()->FUN_141430b10(nAction) != 0)
        return 0;
    else
        return 1;
}
MS2_REPLACE_METHOD(0x141252EA0, CGameOptionInputDefault, FUN_141252ea0, 113, 0xB1C1C0E1);

// The answer of the "key already used" confirm box (0x84f).
// @0x141252f20
int CGameOptionInputDefault::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0 && pSender == dynamic_cast<UIMessageBox*>(pSender))
    {
        m_bConfirm = 0;
        FUN_14151f200();
        int nResult = pMsg->PopInt();
        CStringW strKey = pMsg->FUN_1422b8f40();
        int nKey = _wtoi(strKey);
        if (nResult == 0)
        {
            FUN_141252700(nKey);
        }
        else if ((m_spEdit.get() ? true : false) && m_nOldKey != 0)
        {
            FUN_141252700(m_nOldKey);
        }
        FUN_141252460();
    }
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x141252F20, CGameOptionInputDefault, IMessageListener, OnMessage, 310, 0xEB9FFB93);

// ---- CGameOptionCommon::PendingKeyInput ----

// @0x141253060
CGameOptionCommon::PendingKeyInput::PendingKeyInput()
{
    m_bBusy = false;
    m_nKey = 0;
}

// @0x1412530b0
void CGameOptionCommon::PendingKeyInput::Clear()
{
    m_nKey = 0;
    m_bBusy = false;
}
MS2_REPLACE_METHOD(0x1412530B0, CGameOptionCommon::PendingKeyInput, Clear, 27, 0xC0432774);

// The key captured for the option pages without an edit (reads the unit static s_nCapturedKey: not hooked).
// @0x1412530e0
bool CGameOptionInputDefault::FUN_1412530e0(int* pKey)
{
    *pKey = 0;
    bool bCaptured = false;
    int nKey = 0;
    int nHeld = GetKeyTable()->FindActiveComboPrefixKey(0);
    if (nHeld != 0)
    {
        nKey = GetKeyTable()->FindActiveKey(0);
        if (nHeld != nKey)
        {
            if (GetKeyTable()->FUN_141430cb0(nKey) != 0)
            {
                s_nCapturedKey = 0;
                bCaptured = false;
                return false;
            }
            if (nKey != 0)
            {
                s_nCapturedKey = 0;
                bCaptured = true;
            }
            else
            {
                if (nHeld != s_nCapturedKey)
                    s_nCapturedKey = nHeld;
                return false;
            }
        }
        else
        {
            if (nHeld != s_nCapturedKey)
                s_nCapturedKey = nHeld;
            return false;
        }
    }
    else
    {
        nKey = GetKeyTable()->FindActiveKey(0);
        if (nKey != 0)
        {
            s_nCapturedKey = 0;
            bCaptured = true;
        }
        else if (s_nCapturedKey != 0)
        {
            if (GetKeyTable()->FUN_141430b90(s_nCapturedKey) != 0)
            {
                s_nCapturedKey = 0;
                bCaptured = false;
                return false;
            }
            nKey = s_nCapturedKey;
            s_nCapturedKey = 0;
            bCaptured = true;
        }
    }
    *pKey = nKey;
    if (bCaptured && nKey != 0)
    {
        int nLayout = GetKeyTable()->FUN_1414319f0();
        if (nLayout == 2)
        {
            if (nKey < 0x91)
                return false;
        }
        else if (nKey > 0x91)
        {
            return false;
        }
        *pKey = nKey;
        return true;
    }
    return false;
}

// @0x1412532b0
bool CGameOptionInputDefault::IsKeyUnassigned(int nKey)
{
    return GetKeyTable()->GetKeyAction(nKey) == 0;
}
MS2_REPLACE(0x1412532B0, CGameOptionInputDefault::IsKeyUnassigned, 58, 0x0E6A6F96);

// @0x1412532f0
void CGameOptionInputDefault::FUN_1412532f0(MS2Ptr<CGameOptionInputDefault> sp)
{
    if (sp == 0 || sp.get()->GetActive() == 0)
        return;
    ((class NotifySystem*)FUN_140939a10())->Post(MS2Ptr<NotifyObject>(new NotifyChangeGameOptionInput(sp.get()->GetId())));
}

// @0x1412533f0
void CGameOptionInputDefault::FUN_1412533f0()
{
    for (int nOption = 9; nOption <= 13; nOption++)
        ((class NotifySystem*)FUN_140939a10())->Post(MS2Ptr<NotifyObject>(new NotifyChangeGameOptionInput(nOption)));
}
MS2_REPLACE(0x1412533F0, CGameOptionInputDefault::FUN_1412533f0, 172, 0x3EB74F2D);

// ---- inline COMDATs first used here ----

// @0x141253870
void ASObj::FUN_141253870(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1412536b0
template <class T> MS2Ptr<T> UIGameOptionDialog::GetTabChild(CString strName, int nIndex)
{
    if (!m_30)
        return MS2Ptr<T>(0);
    Scaleform::GFx::Value child = m_30->Invoke("getTabChild", strName, nIndex);
    if (((Scaleform::GFx::Value*)(void*)(&child))->IsDisplayObject())
    {
        MS2Ptr<T> sp = Unk_ASCreate<T>(m_28, child);
        if (static_cast<T*>(sp) != 0)
            return sp;
    }
    return MS2Ptr<T>(0);
}
