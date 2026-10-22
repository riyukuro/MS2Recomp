// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uiindividualdpsdialog.h.
// MS2-UNIT: ?\uiindividualdpsdialog.cpp
// MS2-RANGE: 0x140f4ab90-0x140f4b3d0 .text$mn
// MS2-RANGE: 0x1400df8c0-0x1400dfa30 .text$di
// MS2-FUNCTIONAL: FUN_140f4ade0 (arg copied through rcx), vfunc_28 and vfunc_72 (branch layout) differ in codegen only; behaviour-equivalent.
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

// ---- unit-local views of exe objects ----

// The game option block (the second member of the settings singleton).
struct Unk_IndOpt
{
    bool FUN_14125bb90();                                   // 0x14125bb90 the meter is enabled
    char m_pad_00[3];
    char m_bFlag;                                           // +3 cleared when the dialog is closed
};
class Unk_IndSettings
{
public:
    Unk_IndOpt* FUN_140e09150();                            // 0x140e09150 &m_18
    char m_pad_00[0x18];
    Unk_IndOpt m_opt;                                       // +0x18
};
Unk_IndSettings* FUN_1409a8b10();

class PCBase;
class Unk_IndWorld;
Unk_IndWorld* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(Unk_IndWorld* pWorld);
__int64 FUN_141656a80(PCBase* pPC);
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);

// The AS root object of the dialog, with the invoke the exe instantiates for it.
class Unk_IndAS : public AScript
{
public:
    Scaleform::GFx::Value FUN_140acd130(const char* szMethod, CStringW str);        // 0x140acd130 Invoke(name, string)
};

// @0x140f4ab90
UIIndividualDPSDialog::UIIndividualDPSDialog()
{
    m_2c = 0x11;
    m_nGroup = 0;
    m_nMode = 0;
    FUN_141925e70(0, 1);
}

// @0x140f4ac30
UIIndividualDPSDialog::~UIIndividualDPSDialog()
{
}

// @0x140f4ac70
CString UIIndividualDPSDialog::vfunc_1()
{
    return "IndividualDPSDialog";
}

// @0x140f4acc0
void UIIndividualDPSDialog::OnTextToggle()
{
    if (m_30.IsNull())
        return;
    CStringW strTitle = FUN_1405c2690(CStringW(L"s_individualdps_titlebar"), CBattleRecordManager::FUN_140a04bc0(m_nMode));
    static_cast<Unk_IndAS*>(m_30.operator->())->FUN_140acd130("setTitle", strTitle);
}

// @0x140f4ade0
void UIIndividualDPSDialog::FUN_140f4ade0()
{
    if (m_30.IsNull())
        return;
    PCBase* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPC == 0)
        return;
    {
        __int64 nId = FUN_141656a80(pPC);
        CStringW strMeter = CBattleRecordManager::GetInstance()->FUN_140a04830(m_nGroup, nId, m_nMode);
        static_cast<Unk_IndAS*>(m_30.operator->())->FUN_140acd130("setMeterText", strMeter);
        CStringW strTime = CBattleRecordManager::GetInstance()->FUN_140a04b00(m_nGroup);
        static_cast<Unk_IndAS*>(m_30.operator->())->FUN_140acd130("setTime", strTime);
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
    m_tick.FUN_140268840();
    PCBase* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPC == 0)
        return;
    {
        CBattleRecordManager::GetInstance()->FUN_140a03f60(m_nGroup);
        CBattleRecordManager::GetInstance()->FUN_140a04100(m_nGroup, FUN_141656a80(pPC));
        OnTextToggle();
        FUN_140f4ade0();
    }
}

// @0x140f4b070
int UIIndividualDPSDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    int nResult;
    if (_stricmp("OnCloseDialog", szMethod) == 0)
    {
        FUN_1409a8b10()->FUN_140e09150()->m_bFlag = 0;
        CBattleRecordManager::GetInstance()->FUN_140a03fe0(m_nGroup);
        vfunc_67();
        nResult = 1;
    }
    else
    {
        int nBase = UIDialog::vfunc_28(szMethod, pArgs, nArgs);
        if (nBase == 0)
        {
            if (_stricmp("onReset", szMethod) == 0)
            {
                CBattleRecordManager::GetInstance()->FUN_140a03fa0(m_nGroup);
                nResult = 1;
            }
            else if (_stricmp("onTextToggle", szMethod) == 0)
            {
                m_nMode = m_nMode + 1;
                if (m_nMode >= 9)
                    m_nMode = 0;
                OnTextToggle();
                nResult = 1;
            }
            else
                nResult = 0;
        }
        else
            nResult = 1;
    }
    return nResult;
}

// @0x140f4b1b0
void UIIndividualDPSDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (FUN_1409a8b10()->FUN_140e09150()->FUN_14125bb90() == 0)
        vfunc_67();
    else
    {
        bool bNull = m_30.IsNull();
        if (bNull == 0)
        {
            int nElapsed = m_tick.FUN_140268870(100);
            if (nElapsed != 0)
            {
                PCBase* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
                if (pPC == 0)
                    return;
                FUN_140f4ade0();
            }
        }
    }
}

MS2_EMIT_CRT_MEMMOVE_S();

MS2_REPLACE_METHOD(0x140F4ACC0, UIIndividualDPSDialog, OnTextToggle, 280, 0xEF98DA96);
MS2_REPLACE_METHOD(0x140F4ADE0, UIIndividualDPSDialog, FUN_140f4ade0, 440, 0x83C29D4A);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9800-0x142ca9890 .text$yd
