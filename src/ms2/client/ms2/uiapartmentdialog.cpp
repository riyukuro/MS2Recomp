// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIApartmentDialog: see uiapartmentdialog.h.
// MS2-UNIT: ?\uiapartmentdialog.cpp
// MS2-RANGE: 0x1418b57f0-0x1418b7a10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiapartmentdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiapartmentdialog.h"
#include "uimessagebox.h"
#include "uimessageboxdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> AptClickDelegate;

// The broker / door / contract buttons.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422ce240(const AptClickDelegate& onClick, void* pUserData);
};

class Unk_AptScript : public AScript
{
public:
    // @0x1418b7550
    Scaleform::GFx::Value FUN_1418b7550(const char* szMethod, int n);
};

class Unk_AptPlayer { public: void FUN_14152a0c0(int nA, int nMapId, int nGroup, int nRoom, CStringW strA, CStringW strB); };
class Unk_AptWorld
{
public:
    Unk_AptPlayer* FUN_141bd0cc0();                             // the local player
    unsigned FUN_141bd3060();                                   // the current map id
};
Unk_AptWorld* FUN_1403ed2d0();

class Unk_AptUIMgr
{
public:
    int FUN_141adc890(int nUiId);                               // is shown
    void FUN_141adc530(int nUiId);                              // close
};
Unk_AptUIMgr* FUN_1403ed2b0();

class Unk_AptContractDialog { public: void FUN_141ab4000(int nGroup, unsigned nMapId); };
Unk_AptContractDialog* FUN_140961690(int nUiId);                // GetDialog

class Unk_AptUgcEvents { public: void FUN_141b38be0(UIUGCEventListener* p); void FUN_141b38c70(UIUGCEventListener* p); };
Unk_AptUgcEvents* FUN_140bc09f0();

bool FUN_140a467d0(const MS2Ptr<AScript>*);                     // has the AS object been released
int FUN_1408a0d30(int nGroup, Unk_UGCGroup& rResult, int nMapId);   // the apartment group row
class Unk_AptStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_AptStrings* FUN_1401a9d70();
CStringW FUN_140979570(int nMap);                               // the map name
bool FUN_140e45240(const CStringW& s, const char* c);          // case-insensitive equal
CStringW FUN_14028de60(int nStringId);                          // string table text
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int bOn);
void FUN_140cffa50(const Scaleform::GFx::Value& root, CString strName, CString strFrame);
void FUN_140cffb90(const Scaleform::GFx::Value& root, CString strName, int bPlay);
void FUN_140cfefe0(const Scaleform::GFx::Value& root, CString strName, CString strField, CStringW strText);
void FUN_14151f200();
UIMessageBox* FUN_14151f890();
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
extern int DAT_143ab288c;                                       // the portal's map id
CInputKeyHandler* FUN_14025e7c0();

// @0x1418b57f0
UIApartmentDialog::UIApartmentDialog()
    : m_nStyle(0), m_nA(0), m_nMapId(0), m_nGroup(0)
{
    FUN_141924170(1);
}

// @0x1418b5930
UIApartmentDialog::~UIApartmentDialog()
{
}

// @0x1418b5a10
CString UIApartmentDialog::vfunc_1()
{
    return "ApartmentDialog";
}

// @0x1418b5a60
void UIApartmentDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_nStyle = 0;
    if (m_group.FUN_1408ad2f0() != 0)
        m_nStyle = 1;
    m_broker = FUN_140bb4b10("m_broker");
    static_cast<Unk_AptScript*>(m_30.operator->())->FUN_1418b7550("setStyle", m_nStyle);
    if (m_nStyle == 0)
    {
        m_door0 = FUN_140bb4b10("m_door0");
        m_door1 = FUN_140bb4b10("m_door1");
        m_door2 = FUN_140bb4b10("m_door2");
    }
    else
    {
        m_door0 = FUN_140bb4b10("m_door3");
        m_door1 = FUN_140bb4b10("m_door4");
        m_door2 = FUN_140bb4b10("m_door5");
    }
    m_contract = FUN_140bb4b10("m_contractButton");
    m_broker->FUN_1422ce240(AptClickDelegate(this, &UIApartmentDialog::FUN_1418b6bf0), 0);
    m_door0->FUN_1422ce240(AptClickDelegate(this, &UIApartmentDialog::FUN_1418b6cd0), 0);
    m_door1->FUN_1422ce240(AptClickDelegate(this, &UIApartmentDialog::FUN_1418b6d10), 0);
    m_door2->FUN_1422ce240(AptClickDelegate(this, &UIApartmentDialog::FUN_1418b6d40), 0);
    m_contract->FUN_1422ce240(AptClickDelegate(this, &UIApartmentDialog::FUN_1418b6d60), 0);
    vfunc_47(0);
    FUN_1418b6580();
    FUN_140bc09f0()->FUN_141b38be0(static_cast<UIUGCEventListener*>(this));
}

// @0x1418b62f0
void UIApartmentDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_140bc09f0()->FUN_141b38c70(static_cast<UIUGCEventListener*>(this));
    m_broker = 0;
    m_contract = 0;
    m_door0 = 0;
    m_door1 = 0;
    m_door2 = 0;
    vfunc_47(1);
}

// @0x1418b63d0
int UIApartmentDialog::vfunc_13()
{
    Unk_AptPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (FUN_14025e7c0()->FUN_14116d840())
    {
        vfunc_67();
        return 1;
    }
    else if (FUN_14025e7c0()->FUN_14116dd30(0x493e2, 0, 0))
    {
        if (m_nRoom != 0)
            FUN_1418b6990(m_nRoom);
        return 1;
    }
    return 0;
}

// @0x1418b6480
int UIApartmentDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x1418b6510
void UIApartmentDialog::vfunc_ugc_5()
{
    FUN_1418b6580();
    FUN_1418b68c0();
}

// @0x1418b6550
void UIApartmentDialog::vfunc_ugc_6()
{
    FUN_1418b6580();
}

// @0x1418b6580
// MS2-FUNCTIONAL: frame / call-result temporaries differ from the exe (exe 0x10 smaller); source form unknown
void UIApartmentDialog::FUN_1418b6580()
{
    if (FUN_140a467d0(&m_30))
        return;
    Unk_AptPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    FUN_140cfee80(FUN_1422dbc00(), CString("m_title"), FUN_1418b6de0());
    int nNoRoom = m_nRoom;
    FUN_140cff840(FUN_1422dbc00(), CString("m_contractButton"), nNoRoom == 0);
    FUN_140cff840(FUN_1422dbc00(), CString("m_contractEffect"), 0);
    int nNormal = m_group.FUN_1408ad2f0();
    FUN_140cff840(FUN_1422dbc00(), CString("m_emblem_normal"), nNormal == 0);
    int nMerat = m_group.FUN_1408ad2f0();
    FUN_140cff840(FUN_1422dbc00(), CString("m_emblem_merat"), nMerat);
}

// @0x1418b6840
void UIApartmentDialog::FUN_1418b6840(int nA, int nMapId, int nGroup)
{
    m_nA = nA;
    m_nMapId = nMapId;
    m_nGroup = nGroup;
    FUN_1408a0d30(m_nGroup, m_group, FUN_1403ed2d0()->FUN_141bd3060());
}

// @0x1418b68c0
void UIApartmentDialog::FUN_1418b68c0()
{
    if (FUN_1422dc2d0() == 0)
        return;
    FUN_140cff840(FUN_1422dbc00(), "m_contractEffect", 1);
    FUN_140cffb90(FUN_1422dbc00(), "m_contractEffect", 1);
}

// @0x1418b6990
void UIApartmentDialog::FUN_1418b6990(int nRoom)
{
    Unk_AptPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (m_nMapId == 0)
        return;
    DAT_143ab288c = m_nMapId;
    pPlayer->FUN_14152a0c0(m_nA, m_nMapId, m_nGroup, nRoom, CStringW(L""), CStringW(L""));
}

// @0x1418b6ab0
// MS2-FUNCTIONAL: the exe nests the checks with its own temporaries (frame 0x10 larger); source form unknown
bool UIApartmentDialog::FUN_1418b6ab0(int nMode)
{
    if (FUN_1422dc2d0() == 0)
        return false;
    UIMessageBox* pBox = FUN_14151f890();
    if (pBox == 0)
        return false;
    if (pBox->FUN_1419f8270() != 0)
        return false;
    MS2Ptr<CMsgBoxData> spBox = pBox->FUN_1419f8470();
    if (!(spBox == 0))
    {
        if (!FUN_140e45240(spBox->GetExtra(), "roomNumber"))
        {
            if (nMode == 1)
            {
                pBox->FUN_1419f82b0(FUN_14028de60(0x9cc));
                return true;
            }
            return false;
        }
    }
    return false;
}

// @0x1418b6bf0
void UIApartmentDialog::FUN_1418b6bf0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_140cffa50(FUN_1422dbc00(), "m_brokerSay", "click");
    if (m_nBrokerSaid == 0)
    {
        Scaleform::GFx::FunctionHandler::Params none;
        memset(&none, 0, sizeof(none));
        FUN_1418b6d60(none);
    }
}

// @0x1418b6cd0
void UIApartmentDialog::FUN_1418b6cd0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_nRoom != 0)
        FUN_1418b6990(m_nRoom);
}

// @0x1418b6d10
void UIApartmentDialog::FUN_1418b6d10(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1418b6990(-1);
}

// @0x1418b6d40
void UIApartmentDialog::FUN_1418b6d40(const Scaleform::GFx::FunctionHandler::Params& params)
{
}

// @0x1418b6d60
void UIApartmentDialog::FUN_1418b6d60(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (FUN_1403ed2b0()->FUN_141adc890(0x4e76))
        return;
    Unk_AptContractDialog* pDialog = FUN_140961690(0x4e76);
    if (pDialog != 0)
        pDialog->FUN_141ab4000(m_nGroup, FUN_1403ed2d0()->FUN_141bd3060());
    FUN_1403ed2b0()->FUN_141adc530(0x4e76);
}

// @0x1418b6de0
CStringW UIApartmentDialog::FUN_1418b6de0()
{
    unsigned nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    Unk_UGCGroup group;
    if (FUN_1408a0d30(m_nGroup, group, nMapId) != 0)
        return FUN_140979570(nMapId);
    return FUN_1401a9d70()->FUN_141811980(3, nMapId);
}

// @0x1418b6ec0
void UIApartmentDialog::FUN_1418b6ec0(int nUiType)
{
    if (nUiType == 0x2f)
    {
        FUN_140cfefe0(FUN_1422dbc00(), "m_brokerSay", "m_default", FUN_14028de60(0x7ef));
        FUN_140cfefe0(FUN_1422dbc00(), "m_brokerSay", "m_say", FUN_14028de60(0x7f2));
    }
    else if (nUiType == 0x31)
    {
        FUN_140cfefe0(FUN_1422dbc00(), "m_brokerSay", "m_default", FUN_14028de60(0x7f0));
        FUN_140cfefe0(FUN_1422dbc00(), "m_brokerSay", "m_say", FUN_14028de60(0x7f3));
    }
    else
    {
        FUN_140cfefe0(FUN_1422dbc00(), "m_brokerSay", "m_default", FUN_14028de60(0x7ee));
        FUN_140cfefe0(FUN_1422dbc00(), "m_brokerSay", "m_say", FUN_14028de60(0x7f1));
    }
}

// @0x1418b7550
Scaleform::GFx::Value Unk_AptScript::FUN_1418b7550(const char* szMethod, int n)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bccb0(args.FUN_1409b1f70(0), n);
    return FUN_1422bb8f0(szMethod, args);
}
