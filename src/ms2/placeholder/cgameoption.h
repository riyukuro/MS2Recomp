// cgameoption.h - PLACEHOLDER for CGameOption (RTTI .?AVCGameOption@@, 0x468 bytes). NOT an original header.
// Bases: TSingleton<CGameOption> at +0x0.
// The client's game-option store (unit `client\ms2\gameoption.cpp`): one block per option tab (the state structs of the
// CGameOption* page headers), the three XML files GameOption.xml / AccountOption.xml / CharacterOption.xml with their
// shipped defaults, and the benchmark level. CGameApp::InitInstance (?\ms2.cpp) creates it. Member names are invented.
#pragma once

#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/client/ms2/gameoptioncamera.h"
#include "ms2/client/ms2/gameoptioninterface.h"
#include "ms2/client/ms2/gameoptionstatus.h"
#include "ms2/client/ms2/gameoptionbattle.h"
#include "ms2/client/ms2/gameoptioncommunity.h"
#include "ms2/client/ms2/gameoptiongraphicdefault.h"
#include "ms2/client/ms2/gameoptionsounddefault.h"
#include "ms2/client/ms2/gameoptiongamepad.h"
#include "ms2/client/ms2/gameoptionlanguage.h"
#include "ms2/client/ms2/gameoptionpersonalinfoagreement.h"

// The connect block (0x58 bytes): four strings, a wide string and a pointer array; ctor 0x1412604b0, dtor 0x1412455e0.
struct Unk_GoConnect
{
    Unk_GoConnect();                                                // 0x1412604b0
    ~Unk_GoConnect();                                               // 0x1412455e0
    CStringW m_str00;                                               // +0x00
    CStringW m_str08;                                               // +0x08
    CString m_str10;                                                // +0x10
    CString m_str18;                                                // +0x18
    CStringW m_str20;                                               // +0x20
    int m_n28[4];                                                   // +0x28 (written by the ctor)
    ATL::CAtlArray<void*> m_arr;                                    // +0x38
};
MS2_CHECK_SIZE(Unk_GoConnect, 0x58);

// Further blocks the tabs fill from the XML; only their size and the FUN_ helpers are known.
struct Unk_GoAutoLoot { int m_n[5]; };                              // 0x14 bytes (ctor 0x141260ea0)
// +0x10 / +0x18: the server times of the item box "do not ask again" check boxes (open confirm / currency overflow);
// the reset 0x141261780 stores qwords there (unit_140d1ae30 reads and writes them).
struct Unk_GoEtc { int m_n00; int m_n04; __int64 m_n08; __int64 m_n10Time; __int64 m_n18Time; int m_n20[6]; };   // 0x38 bytes (ctor 0x141261750)
struct Unk_GoChroma { int m_n; };                                   // 4 bytes (ctor 0x141261670)

class CGameOption : public TSingleton<CGameOption>
{
public:
    CGameOption();                                          // 0x141241810
    virtual ~CGameOption();                                 // 0x141241aa0 (deleting dtor 0x141245a10)
    CString FUN_141241b60(int nKind, bool bDefault);        // XML path: kind 0 GameOption, 1 AccountOption, 2 CharacterOption
    void FUN_141241f30();                                   // load GameOption.xml into the tab blocks
    void FUN_141242570();                                  // load AccountOption.xml
    void FUN_141242990();                                  // load CharacterOption.xml
    int FUN_141242f60();                                    // load the language block
    void FUN_1412432d0();                                   // save GameOption.xml / AccountOption.xml
    void FUN_141243450();                                   // reset the document roots of game and account options
    void FUN_141243540();                                   // save the character blocks
    void FUN_141243630();                                   // dump the game option file to the log
    void FUN_1412437e0();                                   // reset the character document root
    void FUN_141243850();                                    // MS2::OnPreInit
    void FUN_141243860();                                    // MS2::Run, before the message loop
    void FUN_1412438d0();                                    // MS2::Run, after the message loop
    void FUN_1412438e0();                                    // MS2::OnShutdown
    int FUN_1412438f0();                                    // benchmark level (computed on first use)
    unsigned int FUN_141243f50(int nKind);                  // 1 when the file is missing or its version differs
    void FUN_141244240(int nLevel);                         // set the benchmark level

    Unk_CameraState* FUN_140af7de0();                       // &m_camera (0x140af7de0)
    Unk_CommunityStateB* FUN_140ae6540();                   // &m_account (0x140ae6540)
    Unk_BattleState* FUN_141248630();                       // &m_battle
    Unk_CommunityStateA* FUN_14124ab20();                   // &m_communityA
    Unk_SoundState* FUN_140d13c70();                        // &m_sound
    Unk_GoEtc* FUN_140c9b8b0();                             // &m_etc
    Unk_GraphicState* FUN_1409a8ac0();                      // &m_graphic
    Unk_GraphicState2* FUN_140c77560();                     // &m_graphic2
    TiXmlDocument* FUN_1412442a0();                         // &m_docGameDefault
    TiXmlDocument* FUN_1412442c0();                         // &m_docAccountDefault
    TiXmlDocument* FUN_1412442e0();                         // &m_docGame
    TiXmlDocument* FUN_141244300();                         // &m_docCharacter
    Unk_GpState* FUN_140a58500();                           // &m_gamepad (0x140a58500, stateskill.cpp)
public:
    Unk_CameraState m_camera;                               // +0x08 ctor 0x14125b400
    Unk_InterfaceState m_interface;                         // +0x18 ctor 0x14125b770
    Unk_InterfaceFlag m_interfaceChar;                      // +0x30 ctor 0x14125bc30
    char m_pad31[3];
    Unk_StatusState m_status;                               // +0x34 ctor 0x14125bda0
    Unk_StatusFlag m_statusChar;                            // +0x50 ctor 0x14125c880
    char m_pad51[3];
    Unk_BattleState m_battle;                               // +0x54 ctor 0x14125ca80
    Unk_CommunityStateA m_communityA;                       // +0x68 ctor 0x14125d130
    char m_pad6b;
    Unk_GraphicState m_graphic;                             // +0x6c ctor 0x14125d890
    Unk_GraphicState2 m_graphic2;                           // +0x9c ctor 0x14125ec20
    Unk_SoundState m_sound;                                 // +0xb0 ctor 0x14125f710
    Unk_SoundFlag m_soundChar;                              // +0xe4 ctor 0x141260380
    char m_pade5[3];
    Unk_GoConnect m_connect;                                // +0xe8 ctor 0x1412604b0
    Unk_CommunityStateB m_account;                          // +0x140 ctor 0x14125d330
    Unk_GoAutoLoot m_autoLoot;                              // +0x14c ctor 0x141260ea0
    Unk_GoEtc m_etc;                                        // +0x160 ctor 0x141261750
    Unk_LgState m_language;                                 // +0x198 ctor 0x14125f090
    Unk_GpState m_gamepad;                                  // +0x1a0 ctor 0x14125f290
    Unk_GoChroma m_chroma;                                  // +0x1b0 ctor 0x141261670
    Unk_PiAgreeState m_agree;                               // +0x1b4 ctor 0x141261cf0
    TiXmlDocument m_docGame;                                // +0x1c0
    TiXmlDocument m_docGameDefault;                         // +0x230
    TiXmlDocument m_docAccount;                             // +0x2a0
    TiXmlDocument m_docAccountDefault;                      // +0x310
    TiXmlDocument m_docCharacter;                           // +0x380
    TiXmlDocument m_docCharacterDefault;                    // +0x3f0
    int m_nBenchmark;                                       // +0x460 (-1 until computed)
    int m_n464;                                             // +0x464
};
MS2_CHECK_SIZE(CGameOption, 0x468);
