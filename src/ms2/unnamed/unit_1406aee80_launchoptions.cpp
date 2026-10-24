// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client launch-option block (8 flags, function-local static
// singleton) with its command-line parser and per-flag accessors. Names are invented from use.
// MS2-UNIT: unit_1406aee80
// MS2-RANGE: 0x1406aee80-0x1406af1a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"

bool FUN_140718390(const CString& str);

class Unk_LaunchOptions
{
public:
    Unk_LaunchOptions();
    void FUN_1406aef60(const CString& strArg, const CString& strValue);   // one "-option [value]" pair
    bool FUN_1406af020();
    bool FUN_1406af030();
    bool FUN_1406af040();
    bool FUN_1406af050();
    bool IsDisableValidate();
    bool IsPreloadNoThread();
    bool FUN_1406af0a0();
    bool FUN_1406af0c0();
    void FUN_1406af0e0(bool b);
    bool FUN_1406af100();
    void FUN_1406af130(bool b);
    void FUN_1406af150();
    bool IsSkipNpcLoading();
    bool FUN_1406af190();

    bool m_bDisableValidate;                                // +0 -disableValidate
    bool m_bPreloadNoThread;                                // +1 -preloadNoThread <bool>
    bool m_b2;                                              // +2 = 1
    bool m_b3;                                              // +3
    bool m_b4;                                              // +4
    bool m_bOptimizeUserSync;                               // +5 -optimizeUserSync <bool> (= 1)
    bool m_bSkipNpcLoading;                                 // +6 -skipNpcLoading
    bool m_b7;                                              // +7
};
MS2_CHECK_SIZE(Unk_LaunchOptions, 8);

// @0x1406aee80
Unk_LaunchOptions::Unk_LaunchOptions()
{
    m_bDisableValidate = 0;
    m_bPreloadNoThread = 0;
    m_b2 = 1;
    m_b3 = 0;
    m_b4 = 0;
    m_bOptimizeUserSync = 1;
    m_bSkipNpcLoading = 0;
    m_b7 = 0;
}

// @0x1406aeee0
Unk_LaunchOptions* FUN_1406aeee0()
{
    static Unk_LaunchOptions s_options;
    return &s_options;
}

// @0x1406aef60
void Unk_LaunchOptions::FUN_1406aef60(const CString& strArg, const CString& strValue)
{
    if (strArg.CompareNoCase("-preloadNoThread") == 0)
        m_bPreloadNoThread = FUN_140718390(strValue);
    else if (strArg.CompareNoCase("-optimizeUserSync") == 0)
        m_bOptimizeUserSync = FUN_140718390(strValue);
    else if (strArg.CompareNoCase("-disableValidate") == 0)
        m_bDisableValidate = 1;
    else if (strArg.CompareNoCase("-skipNpcLoading") == 0)
        m_bSkipNpcLoading = 1;
}

// @0x1406af020
bool Unk_LaunchOptions::FUN_1406af020()
{
    return true;
}

// @0x1406af030
bool Unk_LaunchOptions::FUN_1406af030()
{
    return false;
}

// @0x1406af040
bool Unk_LaunchOptions::FUN_1406af040()
{
    return false;
}

// @0x1406af050
bool Unk_LaunchOptions::FUN_1406af050()
{
    return false;
}

// @0x1406af060
bool Unk_LaunchOptions::IsDisableValidate()
{
    return m_bDisableValidate;
}

// @0x1406af080
bool Unk_LaunchOptions::IsPreloadNoThread()
{
    return m_bPreloadNoThread;
}

// @0x1406af0a0
bool Unk_LaunchOptions::FUN_1406af0a0()
{
    return m_b2;
}

// @0x1406af0c0
bool Unk_LaunchOptions::FUN_1406af0c0()
{
    return m_b3;
}

// @0x1406af0e0
void Unk_LaunchOptions::FUN_1406af0e0(bool b)
{
    m_b3 = b;
}

// @0x1406af100
bool Unk_LaunchOptions::FUN_1406af100()
{
    if (m_b4)
        return false;
    return m_bOptimizeUserSync;
}

// @0x1406af130
void Unk_LaunchOptions::FUN_1406af130(bool b)
{
    m_b4 = b;
}

// @0x1406af150
void Unk_LaunchOptions::FUN_1406af150()
{
    m_b7 = 1;
}

// @0x1406af170
bool Unk_LaunchOptions::IsSkipNpcLoading()
{
    return m_bSkipNpcLoading;
}

// @0x1406af190
bool Unk_LaunchOptions::FUN_1406af190()
{
    return m_b7;
}
