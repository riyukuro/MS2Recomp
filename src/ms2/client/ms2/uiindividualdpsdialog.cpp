// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uiindividualdpsdialog.h.
// MS2-UNIT: ?\uiindividualdpsdialog.cpp
// MS2-RANGE: 0x140f4ab90-0x140f4b3d0 .text$mn
// MS2-RANGE: 0x1400df8c0-0x1400dfa30 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "uiindividualdpsdialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/battlerecordmanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>
#include "ms2/placeholder/cgameoption.h"   // C3: TSingleton<> needs the class
#include "ms2/client/ms2/worldservice.h"

// ---- unit-local views of exe objects ----

// The game option block (the second member of the settings singleton).
struct Unk_InterfaceState;
bool IsIndividualDamageMeterOn(const Unk_InterfaceState* p);          // 0x14125bb90 the meter is enabled (gameoptionstruct.cpp)
struct Unk_IndOpt
{
    char m_pad_00[3];
    char m_bFlag;                                           // +3 cleared when the dialog is closed
};
class Unk_IndSettings
{
public:
    char m_pad_00[0x18];
    Unk_IndOpt m_opt;                                       // +0x18
};

class PCBase;
class Unk_IndWorld;
class PCBase   // C3: member view for the former free stand-ins
{
public:
    __int64 FUN_141656a80();
};
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
class Unk_ChaosSettings { public: struct Unk_ChaosOpt* FUN_140e09150(); };   // CGameOption view, defined in uichaosdpsdialog.cpp (0x140e09150)
// The AS root object of the dialog, with the invoke the exe instantiates for it.
class Unk_IndAS : public AScript
{
};

// @0x140f4ab90
UIIndividualDPSDialog::UIIndividualDPSDialog()
{
    m_2c = 0x11;
    m_nGroup = 0;
    m_nMode = 0;
    SetFlag(0, 1);
}

// @0x140f4ac30
UIIndividualDPSDialog::~UIIndividualDPSDialog()
{
}

// @0x140f4ac70
CString UIIndividualDPSDialog::GetTypeName()
{
    return "IndividualDPSDialog";
}

// @0x140f4acc0
void UIIndividualDPSDialog::OnTextToggle()
{
    if (m_30.IsNull())
        return;
    CStringW strTitle = FUN_14028dfa0<CStringW>(CStringW(L"s_individualdps_titlebar"), CBattleRecordManager::FUN_140a04bc0(m_nMode));
    static_cast<Unk_IndAS*>(m_30.operator->())->Invoke("setTitle", strTitle);
}

// @0x140f4ade0
void UIIndividualDPSDialog::UpdateMeterText()
{
    if (m_30.IsNull())
        return;
    PCBase* pPC = ((class PCBase*)((class WorldService*)(class Unk_IndWorld*)(reinterpret_cast<Unk_IndWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    {
        CStringW strMeter = CBattleRecordManager::GetInstance()->FUN_140a04830(m_nGroup, ((class PCBase*)(class PCBase*)(pPC))->FUN_141656a80(), m_nMode);
        static_cast<Unk_IndAS*>(m_30.operator->())->Invoke("setMeterText", strMeter);
        CStringW strTime = CBattleRecordManager::GetInstance()->GetElapsedTimeText(m_nGroup);
        static_cast<Unk_IndAS*>(m_30.operator->())->Invoke("setTime", strTime);
    }
}

// @0x140f4afa0
void UIIndividualDPSDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140f4afc0
void UIIndividualDPSDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_tick.Init();
    PCBase* pPC = ((class PCBase*)((class WorldService*)(class Unk_IndWorld*)(reinterpret_cast<Unk_IndWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    {
        CBattleRecordManager::GetInstance()->StartGroupIfInactive(m_nGroup);
        CBattleRecordManager::GetInstance()->AddRecord(m_nGroup, ((class PCBase*)(class PCBase*)(pPC))->FUN_141656a80());
        OnTextToggle();
        UpdateMeterText();
    }
}

// @0x140f4b070
int UIIndividualDPSDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnCloseDialog", szMethod) == 0)
    {
        reinterpret_cast<Unk_IndOpt*>(reinterpret_cast<Unk_InterfaceState*>(reinterpret_cast<Unk_ChaosSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140e09150()))->m_bFlag = 0;
        CBattleRecordManager::GetInstance()->StopGroup(m_nGroup);
        vfunc_67();
        return 1;
    }
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onReset", szMethod) == 0)
    {
        CBattleRecordManager::GetInstance()->StartGroup(m_nGroup);
        return 1;
    }
    else if (_stricmp("onTextToggle", szMethod) == 0)
    {
        m_nMode = m_nMode + 1;
        if (m_nMode >= 9)
            m_nMode = 0;
        OnTextToggle();
        return 1;
    }
    return 0;
}

// @0x140f4b1b0
void UIIndividualDPSDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (IsIndividualDamageMeterOn(reinterpret_cast<const Unk_InterfaceState*>(reinterpret_cast<Unk_InterfaceState*>(reinterpret_cast<Unk_ChaosSettings*>(TSingleton<CGameOption>::GetInstance())->FUN_140e09150()))) == 0)
        vfunc_67();
    else
    {
        if (m_30.IsNull())
            return;
        if (!m_tick.Check(100))
            return;
        PCBase* pPC = ((class PCBase*)((class WorldService*)(class Unk_IndWorld*)(reinterpret_cast<Unk_IndWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
        if (pPC == 0)
            return;
        UpdateMeterText();
    }
}

MS2_EMIT_CRT_MEMMOVE_S();

MS2_REPLACE_METHOD(0x140F4ACC0, UIIndividualDPSDialog, OnTextToggle, 280, 0xEF98DA96);
MS2_REPLACE_METHOD(0x140F4ADE0, UIIndividualDPSDialog, UpdateMeterText, 440, 0x83C29D4A);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9800-0x142ca9890 .text$yd
