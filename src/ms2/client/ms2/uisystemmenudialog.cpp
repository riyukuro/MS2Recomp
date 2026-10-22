// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). System menu (UISystemMenuDialog, UI id 0x4e21): the option /
// character select / channel list entries of the game menu and the "leave the room" button whose text and box depend on the
// map type. See uisystemmenudialog.h.
// MS2-UNIT: ?\uisystemmenudialog.cpp
// MS2-RANGE: 0x14011dd60-0x14011de30 .text$di
// MS2-RANGE: 0x141b12ad0-0x141b15900 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uisystemmenudialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uisystemmenudialog.h"

#include <utility>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/uigameoptiondialog.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uiserverlistdialog.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- statics (dynamic initializers 0x14011dd60..0x14011de30) ----

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
#ifndef MS2_HOOK_DLL
static CString s_strStun = "stun";                                                      // @0x14011dd60
static Unk_1401cd100 s_pointer(NULL);                                                   // @0x14011dd90
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);                       // @0x14011ddb0
static UICommon::CMyPCKeyInputController s_keyInputController;                          // @0x14011de00
#endif

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> SmClickDelegate;
typedef Delegate<bool(int, const CMsgBoxData&)> SmBoxDelegate;

// The exit button.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422ce240(const SmClickDelegate& onClick, void* pUserData);   // click callback
    void FUN_1422cdfb0(const CStringW& strLabel);                           // the button text
};

// The scene movie: the "buildChannelList" invoke shape (array, int, string).
class Unk_SmScript : public AScript
{
public:
    // @0x141b151d0
    Scaleform::GFx::Value FUN_141b151d0(const char* szMethod, const ASArray& arr, int n, CStringW str);
};
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& a);    // set a Value from an AS object
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);                // set an Int value
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* sz);    // set a string value

// The world service, the local player and the current field.
class Unk_SmWorld
{
public:
    void* FUN_141bd0cc0();                                  // the local player (a MyPC)
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                  // the current field data
    int FUN_141bd98f0();                                    // the class index of the local player
    int FUN_141bc80c0(int nChannel);                        // the channel is the current one
};
Unk_SmWorld* FUN_1403ed2d0();
class Unk_SmPc
{
public:
    int FUN_14152e950();                                    // the nonzero id of the build the player is in
    void FUN_14152a040();                                   // leave without saving
};

// The cube service (the home rules).
class Unk_SmCubeSvc
{
public:
    bool FUN_1410c3600(int nRule);                          // the mode (1 design, 3 blueprint) is active
    bool FUN_1410d5530();                                   // the design has changes
};
Unk_SmCubeSvc* FUN_1409670e0();

// The dungeon room record.
struct Unk_SmDgData
{
    char m_pad_00[0x140];
    int m_140;                                              // +0x140
};
MS2_CHECK_OFFSET(Unk_SmDgData, m_140, 0x140);
class Unk_SmDgRef
{
public:
    ~Unk_SmDgRef();                                         // 0x14031c0f0 release
    long long FUN_14031c160() const;
    Unk_SmDgData* FUN_1403347d0() const;                    // operator->
private:
    void* m_0;
    void* m_8;
};
MS2_CHECK_SIZE(Unk_SmDgRef, 0x10);
class Unk_SmDgTable { public: Unk_SmDgRef FUN_1403206b0(int nId); };
Unk_SmDgTable* FUN_14031c2a0();
extern int DAT_143ab2884;                                   // the dungeon room id
extern int DAT_143ab0248;                                   // client country

// The constants table (singleton 0x1401d3200): the slot at +0xcfe0 holds the countdown of the leave box in seconds.
class Unk_SmSlot { public: char m_data[0x58]; };
struct Unk_SmConsts
{
    char m_pad_0[0xcfe0];
    Unk_SmSlot m_cfe0;
};
MS2_CHECK_OFFSET(Unk_SmConsts, m_cfe0, 0xcfe0);
Unk_SmConsts* FUN_1401d3200();
int* FUN_1402056b0(Unk_SmSlot* pSlot);

class Unk_SmStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_SmStrings* FUN_1401a9d70();
class Unk_SmUiMgr { public: void FUN_141adc530(int nUiId); };
Unk_SmUiMgr* FUN_1403ed2b0();
class Unk_SmNetwork { public: void FUN_141538820(); };
Unk_SmNetwork* FUN_140714f90();

UIServerEventDispatcher* FUN_140933230();
void FUN_141274f50();
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs, UIDialog* pDialog);
int FUN_1418fd280();
int FUN_14092f640();
UIServerListDialog* FUN_14136f520(int nUiId);
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);
void FUN_14151f200();
void FUN_140dffb50(IMessageListener* pListener);                        // the leave request of a field
CStringW GetStringCommon(int nStringId);
CStringW FUN_1409eec40(int nStringId);
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_14052bd00(int nStringId, CStringW strArg);
CStringW FUN_1405c2690(CStringW strKey, CStringW strArg);
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& n);        // one int argument
CStringW FUN_140cd7d20();                                               // the dungeon name
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, IMessageListener* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

// @0x141b15530 / @0x141b14ea0 / @0x141b15520: the answer of the leave box in a normal field (captureless lambda).

// ---- UISystemMenuDialog ----

// @0x141b12ad0
UISystemMenuDialog::UISystemMenuDialog()
    : m_180(0), m_198(0)
{
    FUN_141924170(1);
    FUN_141925e70(1, 1);
}

// @0x141b12c20
CString UISystemMenuDialog::GetTypeName()
{
    return "SystemMenuDialog";
}

// @0x141b12c70
int UISystemMenuDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    FUN_141274f50();
    FUN_140933230()->AddListener(static_cast<UIServerEventListener*>(this));
    return 1;
}

// @0x141b12ce0
void UISystemMenuDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_180 = 0;
    FUN_140933230()->RemoveListener(static_cast<UIServerEventListener*>(this));
}

// @0x141b12d50
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UISystemMenuDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    m_188 = FUN_140bb4b10(CString("m_exitRoom"));
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField.get() != 0)
    {
        if (spField->FUN_1403751b0())
        {
            if (spField->m_nMapType == 3)
            {
                m_188->FUN_1422ce240(SmClickDelegate(this, &UISystemMenuDialog::FUN_141b13b00), 0);
                m_188->FUN_1422cdfb0(FUN_141b146a0(spField->m_nMapType));
                m_188->vfunc_3(1);
            }
            else if (FUN_1418fd280() == 0)
            {
                m_188->FUN_1422ce240(SmClickDelegate(this, &UISystemMenuDialog::FUN_141b13880), 0);
                m_188->FUN_1422cdfb0(FUN_141b146a0(spField->m_nMapType));
                m_188->vfunc_3(1);
            }
        }
    }
    m_30->Invoke("arrangeConrols");
    m_30->Invoke("setSystemOptionNotifyRedCircle", m_198 != 0);
}

// @0x141b13180
void UISystemMenuDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_188 = 0;
}

// The answers of the message boxes: the leave box and the server notice.
// @0x141b131c0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UISystemMenuDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) == 0)
    {
        if (pMsg->FUN_1422e4520() == 0)
        {
            int nResult = pMsg->FUN_1422b8a10();
            CStringW strTag = pMsg->FUN_1422b8f40();
            if (nResult == 0)
            {
                if (FUN_1403b3c40(strTag, L"leaveInField"))
                    FUN_14151f200();
            }
        }
        else
        {
            if (pMsg->FUN_1422e4520() == 0x7d2)
            {
                COutPacket packet(0x6c, 0);
                packet.vfunc_o10_1(1);
                FUN_140710590(packet);
            }
        }
        return 0;
    }
    return 1;
}

// @0x141b132d0
void UISystemMenuDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141923680(1);
    static_cast<UIServerEventListener*>(this)->Notify();
}

// @0x141b13330
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
int UISystemMenuDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) == 0)
    {
        if (FUN_1418fc760(szMethod, pArgs, nArgs, 0) == 0)
        {
            ASData data;
            if (_stricmp("OnGameOptionDialog", szMethod) == 0)
            {
                FUN_141b14560(1);
                return 1;
            }
            if (_stricmp("OnSelectCharacter", szMethod) == 0)
            {
                OnSelectCharacter();
                return 1;
            }
            if (_stricmp("onGraphic", szMethod) == 0)
            {
                FUN_141b14560(6);
                return 1;
            }
            if (_stricmp("OnChangeChannel", szMethod) == 0)
            {
                ASData channel;
                if (channel.FUN_1422b9620(pArgs, nArgs) != 0)
                {
                    int nChannel = channel.FUN_1422b8a10();
                    if (FUN_1403ed2d0()->FUN_141bc80c0(nChannel) == 0)
                        FUN_141b14630();
                }
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 1;
}

// @0x141b13570
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UISystemMenuDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    if (vfunc_55() == 0 && !(m_30 == 0) && pPacket->FUN_14070fe80() == 0x10 && !(m_30 == 0) && pPacket->vfunc_o8_1() != 0)
        FUN_141b14630();
}

// A server event arrived: rebuild the channel list.
// @0x141b13640
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UISystemMenuDialog::Notify()
{
    if (FUN_1422dc2d0() != 0 && !(m_30 == 0))
    {
        ASArray array(2);
        int nSelected = 0;
        m_180 = FUN_14092f640();
        UIServerListDialog* pList = FUN_14136f520(0x4ef0);
        if (pList != 0)
            pList->FUN_141ad2f60(array, &nSelected, m_180);
        CStringW strName;
        CStringW strPrefix;
        if (DAT_143ab0248 == 2)
        {
            strName = L"";
        }
        else
        {
            int nClass = FUN_1403ed2d0()->FUN_141bd98f0();
            strName = FUN_1401a9d70()->FUN_141811980(0x17, nClass);
        }
        if (!strName.IsEmpty())
        {
            strPrefix = strName;
            strPrefix.Append(L" ");
        }
        static_cast<Unk_SmScript*>(m_30.operator->())->FUN_141b151d0("buildChannelList", array, nSelected, CStringW(strPrefix));
    }
}

// The leave click of a normal field: ask, or leave at once in the dungeon-like fields.
// @0x141b13880
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UISystemMenuDialog::FUN_141b13880(const Scaleform::GFx::FunctionHandler::Params&)
{
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (!(spField == 0))
        return;
    if (spField->m_nFieldID == 0x3a2c94b)
    {
        FUN_140dffb50(static_cast<IMessageListener*>(this));
    }
    else
    {
        CStringW strText = FUN_141b149d0(spField->m_nMapType);
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0, CStringW(strText), static_cast<IMessageListener*>(this), CStringW(L"leaveInField"));
        if (spBox.get() != 0)
        {
            spBox->FUN_141a01700(0x476, 0, 0);
            spBox->FUN_141a01ca0(*FUN_1402056b0(&FUN_1401d3200()->m_cfe0), 1, GetStringCommon(0x2b8));
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
        }
    }
}

// @0x141b13b00
void UISystemMenuDialog::FUN_141b13b00(const Scaleform::GFx::FunctionHandler::Params&)
{
    FUN_141b13b30();
}

// The leave click of a home: leave at once, or ask first when the design has changes.
// @0x141b13b30
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UISystemMenuDialog::FUN_141b13b30()
{
    Unk_SmPc* pPc = static_cast<Unk_SmPc*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    if (FUN_1409670e0()->FUN_1410c3600(2) == 0)
    {
        if (FUN_1409670e0()->FUN_1410c3600(1) == 0)
        {
            if (FUN_1409670e0()->FUN_1410c3600(3) == 0)
            {
                int nBuild = pPc->FUN_14152e950();
                if (nBuild == 0)
                {
                    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_1409eec40(0x877), 0, CStringW(L""));
                    spBox->FUN_141a01800(1);
                    auto lambda = [](int nResult, const CMsgBoxData&) -> bool
                    {
                        if (nResult == 0)
                        {
                            COutPacket packet(0x6c, 0);
                            packet.vfunc_o10_1(1);
                            FUN_140710590(packet);
                        }
                        return true;
                    };
                    spBox->FUN_141a027c0(SmBoxDelegate(lambda));
                    FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
                }
                else
                {
                    CStringW strText = FUN_14052bd00(0x876, FUN_1401a9d70()->FUN_141811980(3, nBuild));
                    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, CStringW(strText), 0, CStringW(L""));
                    if (spBox.get() != 0)
                    {
                        spBox->FUN_141a01800(1);
                        spBox->FUN_141a027c0(SmBoxDelegate(this, &UISystemMenuDialog::FUN_141b14510));
                        FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
                    }
                }
            }
            else
            {
                if (FUN_1409670e0()->FUN_1410d5530() == 0)
                {
                    pPc->FUN_14152a040();
                }
                else
                {
                    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommonByKey(CStringW(L"s_home_info_exit_blueprint_messagebox_save")), 0, CStringW(L""));
                    spBox->FUN_141a024a0(0);
                    spBox->FUN_141a01800(1);
                    spBox->FUN_141a027c0(SmBoxDelegate(this, &UISystemMenuDialog::FUN_141b14510));
                    FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
                }
            }
        }
        else
        {
            if (FUN_1409670e0()->FUN_1410d5530() == 0)
            {
                pPc->FUN_14152a040();
            }
            else
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommonByKey(CStringW(L"s_home_info_exit_messagebox_save")), 0, CStringW(L""));
                spBox->FUN_141a024a0(0);
                spBox->FUN_141a01800(1);
                spBox->FUN_141a027c0(SmBoxDelegate(this, &UISystemMenuDialog::FUN_141b14510));
                FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
            }
        }
    }
    else
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_1409eec40(0x877), 0, CStringW(L""));
        spBox->FUN_141a01800(1);
        spBox->FUN_141a027c0(SmBoxDelegate(this, &UISystemMenuDialog::FUN_141b14510));
        FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
    }
}

// @0x141b144f0
void UISystemMenuDialog::FUN_141b144f0(char b)
{
    m_198 = b;
}

// The leave box answered: leave on OK.
// @0x141b14510
bool UISystemMenuDialog::FUN_141b14510(int nResult, const CMsgBoxData&)
{
    Unk_SmPc* pPc = static_cast<Unk_SmPc*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPc == 0)
        return false;
    if (nResult == 0)
        pPc->FUN_14152a040();
    return true;
}

// Open the option dialog at a page and close the menu.
// @0x141b14560
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UISystemMenuDialog::FUN_141b14560(int nPage)
{
    FUN_140a02e60(0x4ef3)->FUN_141b15670(nPage);
    FUN_1403ed2b0()->FUN_141adc530(0x4ef3);
    vfunc_67();
}

// @0x141b145c0
void UISystemMenuDialog::FUN_141b145c0()
{
    FUN_140714f90()->FUN_141538820();
    vfunc_67();
}

// @0x141b14600
void UISystemMenuDialog::OnSelectCharacter()
{
    FUN_140714f90()->FUN_141538820();
}

// Select the current channel in the list.
// @0x141b14630
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
void UISystemMenuDialog::FUN_141b14630()
{
    if (!(m_30 == 0))
        m_30->Invoke("setSelectedChannel", m_180);
}

// The text of the leave button by map type.
// @0x141b146a0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
CStringW UISystemMenuDialog::FUN_141b146a0(int nMapType)
{
    switch (nMapType)
    {
    case 3:
        if (FUN_1409670e0()->FUN_1410c3600(1) == 0)
        {
            if (FUN_1409670e0()->FUN_1410c3600(3) == 0)
            {
                if (FUN_1409670e0()->FUN_1410c3600(2) == 0)
                    return GetStringCommon(0xaaf);
                return GetStringCommon(0xabd);
            }
            return GetStringCommon(0xabc);
        }
        return GetStringCommon(0xabb);
    default:
        return GetStringCommonByKey(FUN_1401ceea0(L"s_room_exit_name_{0}", nMapType));
    case 5:
        return GetStringCommonByKey(CStringW(L"s_room_exit_dungeon"));
    case 7:
        return GetStringCommon(0xab0);
    case 8:
    case 0xe:
        return FUN_14052bd00(0xab1, FUN_140cd7d20());
    case 9:
        return GetStringCommon(0xab2);
    case 0xd:
        return GetStringCommonByKey(CStringW(L"s_room_exit_arcade"));
    }
}

// The text of the leave box by map type.
// @0x141b149d0
// MS2-FUNCTIONAL: code generation differs (register allocation / block layout)
CStringW UISystemMenuDialog::FUN_141b149d0(int nMapType)
{
    int nRoom = DAT_143ab2884;
    switch (nMapType)
    {
    case 3:
        return FUN_14052bd00(0xab3, FUN_140cd7d20());
    default:
        return FUN_1405c2690(FUN_1401ceea0(L"s_room_exit_msg_{0}", nMapType), FUN_140cd7d20());
    case 5:
        if (DAT_143ab2884 != 0)
        {
            Unk_SmDgRef spRoom = FUN_14031c2a0()->FUN_1403206b0(nRoom);
            if (spRoom.FUN_14031c160() != 0 && spRoom.FUN_1403347d0()->m_140 != 0)
                return FUN_1405c2690(CStringW(L"s_room_exit_msg_default_revival_limit_dungeon"), FUN_140cd7d20());
        }
        return FUN_1405c2690(CStringW(L"s_room_exit_msg_dungeon"), FUN_140cd7d20());
    case 7:
        return FUN_14052bd00(0xab7, FUN_140cd7d20());
    case 8:
    case 0xe:
        return FUN_14052bd00(0xab8, FUN_140cd7d20());
    case 9:
        return FUN_14052bd00(0xab9, FUN_140cd7d20());
    case 0xd:
        return FUN_1405c2690(CStringW(L"s_room_exit_msg_arcade"), FUN_140cd7d20());
    }
}

// @0x141b151d0
Scaleform::GFx::Value Unk_SmScript::FUN_141b151d0(const char* szMethod, const ASArray& arr, int n, CStringW str)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce40(args.FUN_1409b1f70(0), arr);
    FUN_1422bccb0(args.FUN_1409b1f70(1), n);
    FUN_1422bcea0(args.FUN_1409b1f70(2), str);
    return FUN_1422bb8f0(szMethod, args);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc2b40-0x142cc2ba0 .text$yd
