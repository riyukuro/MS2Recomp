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
#include "ms2/placeholder/ms2stdafx.h"
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

// The key list control of an input tab ("m_keyList": clear / append rows, slot 24 refresh). The exe object is an
// ASTileCacheList (RTTI .?AVASTileCacheList@@, vftable 0x143111728, base ASTileList, ctor 0x1422cf590, 0x88 bytes).
class Unk_GiKeyList : public AScript
{
public:
    Unk_GiKeyList(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422cf590
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                               // clear
    void FUN_1422dd230(const ASObj& row);                               // append a row
private:
    void* m_unrecovered_40[9];
};
MS2_CHECK_SIZE(Unk_GiKeyList, 0x88);

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
    void FUN_1419f19c0();                                               // refresh the quick slots
    void FUN_1419f1e60();                                               // back up the quick slots
};

UIMainPlayerInfo* FUN_140931900(int nUiId);
UIGameOptionDialog* FUN_140a02e60(int nDialogId);
CFeatureManager* FUN_140166410();
MS2InputService* FUN_140a58540();
CStringTable* GetStringTable();
NotifySystem* FUN_140939a10();
bool FUN_1407cce10(const Scaleform::GFx::Value* v);                     // the value is an object
double FUN_140f17ed0(const Scaleform::GFx::Value& v);                   // Value::GetNumber
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
void FUN_14151f200();                                                   // close the open message box
void FUN_141901390(int nRelease, int nUiType);                          // block / release the player's keys for a UI
void FUN_14092f690(int nSkillId, int nItemId, __int64 nItemUid, int nPage, unsigned int nSlot);   // put a quick slot
void FUN_140d73aa0(CStringW text, int nType, void* pListener, CStringW tag);       // notice box
void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW tag);          // notice box by string id
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pListener, CStringW tag);   // create a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                            // show it
CStringW FUN_1409eec40(int nStrId);                                     // string table text by id
CStringW GetStringCommonByKey(const CStringW& strKey);                         // string table text by key
CStringW FUN_14052bd00(int nStrId, const CStringW& strArg);             // formatted string table text
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& nArg);      // StringFormat<int>
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& strArg0, const CStringW& strArg1);   // StringFormat<CStringW, CStringW>

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
        FUN_141252910();
        FUN_141252460();
        m_bChanged = 0;
        m_bConfirm = 0;
    }
    else
    {
        FUN_141250cc0(m_nType);
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
void CGameOptionInputDefault::FUN_141250cc0(int nCategory)
{
    MS2Ptr<Unk_GiKeyList> spList = GetOptionDialog()->GetTabChild<Unk_GiKeyList>("m_keyList", nCategory);
    if (spList == 0)
        return;
    double dScroll = FUN_140f17ed0(spList.operator Unk_GiKeyList*()->FUN_1422baa20("scrollPosition"));
    int bGamePad = FUN_140166410()->FUN_14036d570(0xb5);
    spList.operator Unk_GiKeyList*()->FUN_1422dd1d0();
    TPtrValue<ATL::CAtlList<MS2Ptr<CKeySettingParam> > > spKeys = FUN_1409331f0()->FUN_141430710(m_nId);
    if (spKeys.get() != 0)
    {
        bool bFirst = true;
        for (POSITION pos = spKeys->GetHeadPosition(); pos != 0; spKeys->GetNext(pos))
        {
            MS2Ptr<CKeySettingParam> spKey = spKeys->GetAt(pos);
            int nPrimary = FUN_1409331f0()->FUN_14142c940(spKey->m_nAction, 0);
            int nSecondary = FUN_1409331f0()->FUN_14142c940(spKey->m_nAction, 1);
            int nThirdly = FUN_1409331f0()->FUN_14142c940(spKey->m_nAction, 2);
            ASObj row(2);
            if (spKey->m_nAction == 0x49409)
            {
                row.FUN_1407cbb20("label", GetStringTable()->FUN_1418125b0(0x49409));
                row.FUN_141253870("keyGUID", 0x49409);
                row.FUN_1407cbb20("secondaryKey", FUN_1409331f0()->FUN_14142d220(1));
            }
            else
            {
                row.FUN_1407cbb20("label", GetStringTable()->FUN_1418125b0((int)spKey->m_nAction));
                row.FUN_1407cba60("keyGUID", FUN_141252540(spKey->m_nAction));
                row.FUN_1407cbb20("secondaryKey", FUN_1409331f0()->FUN_14142d220(nSecondary));
            }
            row.FUN_1407cbb20("primaryKey", FUN_1409331f0()->FUN_14142d220(nPrimary));
            row.FUN_1407cbb20("thirdlyKey", bGamePad ? FUN_1409331f0()->FUN_14142d220(nThirdly) : CStringW(L""));
            row.FUN_1407cbbe0("primaryEnable", 0 != 1 && spKey->m_nPrimaryLocked == 0);
            row.FUN_1407cbbe0("secondaryEnable", 0 != 1 && spKey->m_nSecondaryLocked == 0);
            row.FUN_1407cbbe0("thirdlyEnable", 0 != 1 && spKey->m_nThirdlyLocked == 0);
            row.FUN_1407cb9c0("isGamePad", bGamePad);
            spList.operator Unk_GiKeyList*()->FUN_1422dd230(row);
        }
    }
    static_cast<ASObj*>(static_cast<AScript*>(spList.operator Unk_GiKeyList*()))->FUN_140e06d60("scrollPosition", dScroll);
    spList.operator Unk_GiKeyList*()->vfunc_24(true);
    MS2Ptr<ASUIComponent> spTab = GetOptionDialog()->FUN_14124ff50(m_nType);
    if (static_cast<ASUIComponent*>(spTab) != 0)
        static_cast<AScript*>(spTab.operator->())->Invoke("refreshScrollBar");
}

// @0x141251490
void CGameOptionInputDefault::vfunc_13()
{
    if (m_timer.FUN_140868c00() != 0)
    {
        m_timer.FUN_1408687f0();
        FUN_141252cf0(1);
    }
}

// @0x1412514e0
void CGameOptionInputDefault::vfunc_6()
{
    FUN_141250cc0(m_nType);
}
MS2_REPLACE_METHOD(0x1412514E0, CGameOptionInputDefault, vfunc_6, 32, 0xE4042622);

// @0x141251510
void CGameOptionInputDefault::vfunc_7()
{
    FUN_141250cc0(m_nType);
}
MS2_REPLACE_METHOD(0x141251510, CGameOptionInputDefault, vfunc_7, 32, 0x73BAC012);

// Polls the key capture while a slot is being edited (reads the unit static s_nHeldKey: not hooked).
// MS2-FUNCTIONAL: branch layout of the held-key capture differs from the exe (14 bytes short); calls and semantics are equivalent
// @0x141251540
int CGameOptionInputDefault::vfunc_8()
{
    if (m_spEdit == 0)
        return 0;
    if (FUN_140a02e60(0x4ef3) == 0)
        return 0;
    if (m_bConfirm != 0)
        return 0;
    bool bCaptured = false;
    Unk_CommandKeyCode nKey = (Unk_CommandKeyCode)0;
    int nHeld = FUN_1409331f0()->FUN_14142e470(0);
    if (nHeld != 0)
    {
        nKey = (Unk_CommandKeyCode)FUN_1409331f0()->FUN_14142e340(0);
        if (nHeld != nKey)
        {
            if (FUN_1409331f0()->FUN_141430cb0(nKey) != 0)
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
        nKey = (Unk_CommandKeyCode)FUN_1409331f0()->FUN_14142e340(0);
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
        if (FUN_1409331f0()->FUN_14142cc40(nKey) == 0)
        {
            FUN_140d73bc0(0x84c, 0, 0, CStringW(L""));
            return 1;
        }
        __int64 nAction = FUN_1409331f0()->FUN_14142d190(nKey);
        if (nAction != 0)
        {
            CStringW strKey = StringFormat(L"{0}", nKey);
            CStringW strName;
            if (FUN_1409331f0()->FUN_14142cf10(nAction) != 0)
                strName = FUN_140656190(L"{0}[{1}]", GetStringTable()->FUN_1418125b0((int)FUN_1409331f0()->FUN_14142d190(nKey)), FUN_1409331f0()->FUN_14142d220(nKey));
            else
                strName = GetStringTable()->FUN_1418125b0((int)nAction);
            if (FUN_1409331f0()->FUN_141430470(nAction) == 0)
            {
                m_bConfirm = 1;
                FUN_140d73aa0(FUN_14052bd00(0x84f, strName), 1, static_cast<IMessageListener*>(this), CStringW(strKey));
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
        if (data.FUN_1422b9620((const Scaleform::GFx::Value*)pArg, nArg) != 0)
            FUN_141250cc0(data.FUN_1422b8b10());
        return 1;
    }
    else if (_stricmp("onFocusInPrimary", pszName) == 0)
    {
        if (data.FUN_1422b9620((const Scaleform::GFx::Value*)pArg, nArg) != 0)
            FUN_1412525c0(data.FUN_1422b8d30(), 0);
        return 1;
    }
    else if (_stricmp("onFocusInSecondary", pszName) == 0)
    {
        if (data.FUN_1422b9620((const Scaleform::GFx::Value*)pArg, nArg) != 0)
            FUN_1412525c0(data.FUN_1422b8d30(), 1);
        return 1;
    }
    else if (_stricmp("onFocusInThirdly", pszName) == 0)
    {
        if (data.FUN_1422b9620((const Scaleform::GFx::Value*)pArg, nArg) != 0)
            FUN_1412525c0(data.FUN_1422b8d30(), 2);
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

// MS2-FUNCTIONAL: the exe returns an int (xor eax,eax); the CBaseOption slot is declared bool (xor al,al)
// @0x141251d90
int CGameOptionInputDefault::vfunc_14()
{
    return m_bChanged != 0;
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
    FUN_1409331f0()->FUN_141429600();
    FUN_141252910();
    m_mapQuickSlots.RemoveAll();
    UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo != 0)
        pInfo->FUN_1419f1e60();
    FUN_1412532f0(MS2Ptr<CGameOptionInputDefault>(this));
    m_bChanged = 0;
}
MS2_REPLACE_METHOD(0x141251DF0, CGameOptionInputDefault, vfunc_10, 151, 0x1D8A8953);

// @0x141251e90
void CGameOptionInputDefault::vfunc_12()
{
    if (GetOptionDialog()->FUN_141254a00() != 0)
    {
        if (FUN_140166410()->FUN_14036d570(0xb5) == true)
        {
            if (FUN_141252c10() != 0)
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(6, GetStringCommonByKey(L"s_gameoption_input_reset_message"), static_cast<IMessageListener*>(this), CStringW(L""));
                if (spBox.get() != 0)
                {
                    int bPad = FUN_140a58540()->FUN_140d8ee40() != 0 ? 1 : 0;
                    CStringW strPad = FUN_1401ceea0(L"{0}", bPad);
                    spBox->FUN_140b76940(strPad);
                    spBox->FUN_141a01800(2);
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &CGameOptionInputDefault::FUN_1412523d0));
                    FUN_140d73c60(spBox);
                }
            }
        }
        else
        {
            FUN_141252200(0);
        }
    }
    else
    {
        FUN_141252200(FUN_140a58540()->FUN_140d8ee40());
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
void CGameOptionInputDefault::FUN_141252200(int nPadKind)
{
    if (FUN_141252c10() != 0)
    {
        FUN_141252970();
        BOOL bDefault = FALSE;
        if (FUN_140166410()->FUN_14036d570(0xb5) == true)
        {
            if (nPadKind == 2)
            {
                CString strPath("./Data/Xml/Table/default/DefaultPSKey.xml");
                FUN_1409331f0()->FUN_141429e60(strPath);
            }
            else if (nPadKind == 1 || nPadKind == 3)
            {
                CString strPath("./Data/Xml/Table/default/DefaultXboxKey.xml");
                FUN_1409331f0()->FUN_141429e60(strPath);
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
            FUN_1409331f0()->FUN_1414297e0(strPath, 0);
        }
        UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
        if (pInfo != 0)
            pInfo->FUN_1419f19c0();
        FUN_1412532f0(MS2Ptr<CGameOptionInputDefault>(this));
    }
    if (FUN_141252ca0() != 0)
        FUN_141250cc0(m_nType);
    m_spEdit = 0;
}
MS2_REPLACE_METHOD(0x141252200, CGameOptionInputDefault, FUN_141252200, 447, 0xA3356950);

// @0x1412523d0
bool CGameOptionInputDefault::FUN_1412523d0(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        int nPad = _wtoi(data.FUN_141a02d50());
        if (nPad == 0)
            FUN_141252200(0);
        else
            FUN_141252200(FUN_140a58540()->FUN_140d8ee40());
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
        m_timer.FUN_1408687f0();
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
    int nKey = FUN_1409331f0()->FUN_14142c940(nAction, nPriority);
    if (nKey != 0)
        FUN_1409331f0()->FUN_14142b1c0(nKey, 0, 0, 0, nPriority, -1);
}
MS2_REPLACE_METHOD(0x1412524D0, CGameOptionInputDefault, FUN_1412524d0, 105, 0x3F233A27);

// @0x141252540
CString CGameOptionInputDefault::FUN_141252540(__int64 nAction)
{
    CString str;
    str.Format("%I64u", nAction);
    return str;
}
MS2_REPLACE_METHOD(0x141252540, CGameOptionInputDefault, FUN_141252540, 119, 0xDEBE352D);

// @0x1412525c0
void CGameOptionInputDefault::FUN_1412525c0(CString strAction, int nPriority)
{
    m_bChanged = 1;
    __int64 nAction = atoi(strAction);
    if (nAction == 0)
        return;
    MS2Ptr<CKeySettingParam> spKey = FUN_1409331f0()->FUN_141430590(nAction);
    if (spKey.get() != 0)
    {
        m_nOldKey = FUN_1409331f0()->FUN_14142c940(nAction, nPriority);
        m_spEdit = spKey;
        m_spEdit->m_nPriority = nPriority;
        FUN_1412524d0(nAction, nPriority);
        FUN_141252cf0(0);
        FUN_1409331f0()->FUN_14142a8b0(nAction);
    }
    FUN_140a02d90(1);
}
MS2_REPLACE_METHOD(0x1412525C0, CGameOptionInputDefault, FUN_1412525c0, 300, 0x3E06C36B);

// @0x141252700
void CGameOptionInputDefault::FUN_141252700(int nKey)
{
    if (m_spEdit == 0 || nKey == 0)
        return;
    if (FUN_1409331f0()->FUN_14142b1c0(nKey, m_spEdit->m_nType, m_spEdit->m_nAction, 0, m_spEdit->m_nPriority, m_nOldKey) != 0)
    {
        FUN_141250cc0(m_nType);
        m_timer.FUN_140868750(300);
        FUN_1409331f0()->FUN_14142a8b0(m_spEdit->m_nAction);
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
        FUN_140d73aa0(FUN_1409eec40(nMsgId), 0, static_cast<IMessageListener*>(this), CStringW(L""));
}
MS2_REPLACE_METHOD(0x141252840, CGameOptionInputDefault, FUN_141252840, 201, 0xD16B40F0);

// @0x141252910
void CGameOptionInputDefault::FUN_141252910()
{
    if (m_nId == 9)
        FUN_1409331f0()->FUN_14142a510();
}
MS2_REPLACE_METHOD(0x141252910, CGameOptionInputDefault, FUN_141252910, 38, 0x7A1FD070);

// @0x141252940
void CGameOptionInputDefault::FUN_141252940()
{
    if (m_nId == 9)
        FUN_1409331f0()->FUN_14142a680();
}
MS2_REPLACE_METHOD(0x141252940, CGameOptionInputDefault, FUN_141252940, 38, 0xEAAB0136);

// @0x141252970
void CGameOptionInputDefault::FUN_141252970()
{
    if (FUN_141252c10() != 0)
    {
        m_mapQuickSlots.RemoveAll();
        ATL::CAtlArray<Unk_MyPCKeyId> aSlots;
        FUN_1409331f0()->FUN_14142c5d0(aSlots);
        for (unsigned int i = 0; i < aSlots.GetCount(); i++)
        {
            int nSkillId = FUN_1409331f0()->FUN_14142dad0(aSlots[i]);
            __int64 nItemUid = FUN_1409331f0()->FUN_14142ded0(aSlots[i]);
            int nSlot = FUN_1409331f0()->FUN_14142e090(nSkillId, nItemUid);
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
    int nPage = FUN_1409331f0()->FUN_140a700b0();
    for (POSITION pos = m_mapQuickSlots.GetStartPosition(); pos != 0; m_mapQuickSlots.GetNext(pos))
    {
        Unk_SsQuickEntry& entry = m_mapQuickSlots.GetValueAt(pos);
        unsigned int nSlot = m_mapQuickSlots.GetKeyAt(pos);
        FUN_14092f690(entry.m_nSkillId, entry.m_nItemId, entry.m_nItemUid, nPage, nSlot);
    }
    UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo != 0)
        pInfo->FUN_1419f19c0();
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
int CGameOptionInputDefault::FUN_141252ca0()
{
    return GetOptionDialog()->FUN_141254590() == m_nType;
}
MS2_REPLACE_METHOD(0x141252CA0, CGameOptionInputDefault, FUN_141252ca0, 64, 0xD437D43C);

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
    if (FUN_1409331f0()->FUN_141430b10(m_spEdit->m_nAction) != 0 && FUN_1409331f0()->FUN_141430c30(nKey) == 0)
    {
        FUN_141252840(0x853);
        return 0;
    }
    if (FUN_1409331f0()->FUN_141430c30(nKey) != 0 &&
        FUN_1409331f0()->FUN_141430b10(FUN_1409331f0()->FUN_14142d190(nKey)) != 0 &&
        FUN_1409331f0()->FUN_141430b10(m_spEdit->m_nAction) == 0)
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
    else if (FUN_1409331f0()->FUN_141431a90(nKey) != 0)
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
    if (FUN_1409331f0()->FUN_141430b10(nAction) != 0)
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
        int nResult = pMsg->FUN_1422b8a10();
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
    int nHeld = FUN_1409331f0()->FUN_14142e470(0);
    if (nHeld != 0)
    {
        nKey = FUN_1409331f0()->FUN_14142e340(0);
        if (nHeld != nKey)
        {
            if (FUN_1409331f0()->FUN_141430cb0(nKey) != 0)
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
        nKey = FUN_1409331f0()->FUN_14142e340(0);
        if (nKey != 0)
        {
            s_nCapturedKey = 0;
            bCaptured = true;
        }
        else if (s_nCapturedKey != 0)
        {
            if (FUN_1409331f0()->FUN_141430b90(s_nCapturedKey) != 0)
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
        int nLayout = FUN_1409331f0()->FUN_1414319f0();
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
bool CGameOptionInputDefault::FUN_1412532b0(int nKey)
{
    return FUN_1409331f0()->FUN_14142d190(nKey) == 0;
}
MS2_REPLACE(0x1412532B0, CGameOptionInputDefault::FUN_1412532b0, 58, 0x0E6A6F96);

// @0x1412532f0
void CGameOptionInputDefault::FUN_1412532f0(MS2Ptr<CGameOptionInputDefault> sp)
{
    if (sp == 0 || sp.get()->GetActive() == 0)
        return;
    FUN_140939a10()->Post(MS2Ptr<NotifyObject>(new NotifyChangeGameOptionInput(sp.get()->FUN_140a02e50())));
}

// @0x1412533f0
void CGameOptionInputDefault::FUN_1412533f0()
{
    for (int nOption = 9; nOption <= 13; nOption++)
        FUN_140939a10()->Post(MS2Ptr<NotifyObject>(new NotifyChangeGameOptionInput(nOption)));
}
MS2_REPLACE(0x1412533F0, CGameOptionInputDefault::FUN_1412533f0, 172, 0x3EB74F2D);

// ---- inline COMDATs first used here ----

// @0x141253870
void ASObj::FUN_141253870(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1412536b0
template <class T> MS2Ptr<T> UIGameOptionDialog::GetTabChild(CString strName, int nIndex)
{
    if (!m_30)
        return MS2Ptr<T>(0);
    Scaleform::GFx::Value child = m_30->Invoke("getTabChild", strName, nIndex);
    if (FUN_1407cce10(&child))
    {
        MS2Ptr<T> sp = Unk_ASCreate<T>(m_28, child);
        if (static_cast<T*>(sp) != 0)
            return sp;
    }
    return MS2Ptr<T>(0);
}
