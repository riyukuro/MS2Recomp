// gameoptionlanguage.h - CGameOptionLanguage (RTTI .?AVCGameOptionLanguage@@, base CBaseOption, 0x38 bytes): the
// language / region / voice row of the game options (three drop downs filled from the gameOptionLocale.xml rows of
// CLocaleLanguage). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\gameoptionlanguage.cpp`.
// Header name and member names are assumed.
// vftable: 15 slots; its own are 0 (deleting dtor), 1, 3, 4, 5, 6, 7, 10, 12 and 14.
#pragma once
#include "ms2/client/ms2/baseoption.h"

// The selected language and voice (the copy in the option row at +0x30 and the saved one at +0x198 of the settings).
// Its methods live in another unit (0x14125f090...), declared in the .cpp as FUN_ free functions.
struct Unk_LgState
{
    int m_nLanguage;                // +0x00 language enum
    int m_nVoice;                   // +0x04 voice (language) enum
};
MS2_CHECK_SIZE(Unk_LgState, 8);

class CGameOptionLanguage : public CBaseOption
{
public:
    CGameOptionLanguage(int nId, int nType);                        // 0x140cfb450
    virtual ~CGameOptionLanguage();                                 // 0x140cfb4b0 (deleting dtor 0x140cfd220)

    virtual CString GetTypeName();                                      // 0x140cfce60 "GameOptionLanguage"
    virtual void vfunc_3(int n);                                    // 0x140cfb4e0
    virtual void vfunc_4(int n);                                    // 0x140cfb540
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg); // 0x140cfb570 (not handled)
    virtual void vfunc_6();                                         // 0x140cfb590 write the state into the UI
    virtual void vfunc_7();                                         // 0x140cfb9e0 read the state back from the UI
    virtual void vfunc_10();                                        // 0x140cfcb20
    virtual void vfunc_12();                                        // 0x140cfce00
    virtual int vfunc_14();                                        // 0x140cfceb0 differs from the saved settings

    int FUN_140cfbcd0(int nVoice);                                  // are the sound banks of the voice installed
    void FUN_140cfbf50();                                           // fill the three drop downs
    CStringW FUN_140cfc970(CString strCode);                        // "s_gameoption_language_{0}"
    CStringW FUN_140cfca00(CString strCode);                        // "s_gameoption_voice_{0}"
    CStringW FUN_140cfca90(CString strCode);                        // "s_gameoption_region_{0}"

    Unk_LgState m_state;                                            // +0x30
};
MS2_CHECK_SIZE(CGameOptionLanguage, 0x38);
