// scenestategame.h - CSceneStateGame (efd RTTI name "CSceneStateGame", class id 0x0620000c): the
// in-field scene state. It dispatches every field packet (OnPacket, opcode switch 0x9..0x139) to its handlers and
// keeps the reconnect loop. Header name assumed from the unit path; handler names are FUN_<va> (opcode in the comment).
//
// Bases: CSceneStateBase (0x10), IWorldServiceCallback at +0x10 (vftable 0x142f5faa0; overrides slots 1 and 4).
// Primary vftable 0x142f5fa18 (16 slots), ??_G 0x1417476f0 (0x78 bytes), ClassInfo 0x143ae7560.
#pragma once
#include "scenestatebase.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/timer.h"

class CInPacket;
class CInputStream;
class CMsgBoxData;
class NotifyObject;
class PCBase;

class CSceneStateGame : public CSceneStateBase, public IWorldServiceCallback
{
    EE_DECLARE_CLASS1(CSceneStateGame, 0x0620000c, efd::IBase);

public:
    CSceneStateGame();                                      // 0x14170bda0
    virtual ~CSceneStateGame();                             // 0x14170be40

    int vfunc_15() override;                                // 0x14170be90
    void OnEnter(int nPrevState) override;                  // 0x14170beb0
    void OnLeave(int nNextState) override;                  // 0x14170bfd0
    void OnUpdate(double fTime) override;                   // 0x14170c0c0
    void OnPacket(CInPacket& packet) override;              // 0x14170c5b0
    void vfunc_1(int) override;                             // 0x14170d9f0 (IWorldServiceCallback slot 1: field entered)
    void vfunc_4(int) override;                             // 0x14170daf0 (IWorldServiceCallback slot 4: disconnected)
    int vfunc_14() override;                                // 0x14170dbc0
    void OnWndMessage(unsigned int nMsg, int wParam, int lParam) override;  // 0x14170dbe0

    // packet handlers (opcode)
    void FUN_14170dc90(CInPacket& packet);                  // 0x9
    void FUN_14170dd60(CInPacket& packet);                  // 0x15
    void FUN_14170e800(CInPacket& packet);                  // 0x7d
    void FUN_14170f930(CInPacket& packet);                  // 0x16
    void FUN_14170fc70(CInPacket& packet);                  // 0x19
    void OnAddUser(CInPacket& packet);                  // 0x17
    void FUN_141711dc0(CInPacket& packet);                  // 0x18
    void FUN_141711e70(CInPacket& packet);                  // 0x2b
    void FUN_141712340(CInPacket& packet);                  // 0x2c
    void FUN_141712420(CInPacket& packet);                  // 0x2d
    void FUN_141712690(CInPacket& packet);                  // 0x1c
    void FUN_141712710(CInPacket& packet);                  // 0x7a
    void FUN_141712a90(CInPacket& packet);                  // 0x1f
    void FUN_141712fb0(CInPacket& packet);                  // 0x20
    void FUN_1417132b0(CInPacket& packet);                  // 0xce
    void FUN_141713fb0(CInPacket& packet);                  // 0x21
    void FUN_141715bd0(CInPacket& packet);                  // 0x23
    void FUN_141716200(CInPacket& packet);                  // 0x24
    void FUN_141716680(CInPacket& packet);                  // 0x25
    void FUN_141716b60(CInPacket& packet);                  // 0x26
    void FUN_141716d10(CInPacket& packet);                  // 0x27
    void FUN_141717000(CInPacket& packet);                  // 0x28
    void FUN_141717140(CInPacket& packet);                  // 0x2a
    void FUN_141717340(CInPacket& packet);                  // 0x30
    void FUN_141717560(CInPacket& packet);                  // 0x29
    void FUN_141717580(CInPacket& packet);                  // 0x2f
    void FUN_1417176b0(CInPacket& packet);                  // 0x2e
    void FUN_141717b40(CInPacket& packet);                  // 0x3c
    void FUN_141718150(CInPacket& packet);                  // 0x3e
    void FUN_141718680(CInPacket& packet);                  // 0x3f
    void FUN_1417187b0(CInPacket& packet);                  // 0x40
    void FUN_141718b80(CInPacket& packet);                  // 0x41
    void FUN_141718cf0(CInPacket& packet);                  // 0x55
    void FUN_1417195f0(CInPacket& packet);                  // 0x56
    void FUN_1417197c0(CInPacket& packet);                  // 0x57
    void FUN_141719840(CInPacket& packet);                  // 0x58
    void FUN_141719990(CInPacket& packet);                  // 0x59
    void FUN_141719a30(CInPacket& packet);                  // 0x4b
    void FUN_141719a60(CInPacket& packet);                  // 0x5a
    void FUN_14171a2e0(CInPacket& packet);                  // 0x5b
    void FUN_14171a5f0(CInPacket& packet);                  // 0x5c
    void FUN_14171a6c0(CInPacket& packet);                  // 0x32
    void FUN_14171a730(CInPacket& packet);                  // 0x33
    void FUN_14171a900(CInPacket& packet);                  // 0x34
    void FUN_14171aa90(CInPacket& packet);                  // 0x35
    void FUN_14171ab00(CInPacket& packet);                  // 0x37
    void FUN_14171aec0(CInPacket& packet);                  // 0x38
    void FUN_14171b380(CInPacket& packet);                  // 0xae
    void FUN_14171b630(CInPacket& packet);                  // 0x39
    void FUN_14171b750(CInPacket& packet);                  // 0x3a
    void FUN_14171bad0(CInPacket& packet);                  // 0x117
    void FUN_14171bd90(CInPacket& packet);                  // 0x3b
    void FUN_14171c0b0(CInPacket& packet);                  // 0x3d
    void FUN_14171c1d0(CInPacket& packet);                  // 0x3d mode 0
    void FUN_14171cdf0(CInPacket& packet);                  // 0x3d mode 1
    void FUN_14171d610(CInPacket& packet);                  // 0x3d mode 3
    void FUN_14171d820(CInPacket& packet);                  // 0x3d mode 4
    void FUN_14171dc40(CInPacket& packet);                  // 0x3d mode 5
    void FUN_14171e440(CInPacket& packet);                  // 0x3d mode 6
    void FUN_14171e860(CInPacket& packet);                  // 0x3d mode 7
    void FUN_14171e9a0(CInPacket& packet);                  // 0x3d mode 8
    void FUN_14171ee80(CInPacket& packet);                  // 0x48
    void FUN_14171f8a0(CInPacket& packet);                  // 0x49
    void FUN_141720480(CInPacket& packet);                  // 0x47
    void FUN_141720c60(CInPacket& packet);                  // 0x130
    void FUN_141720e50(CInPacket& packet);                  // 0x4c
    void FUN_141721270(CInPacket& packet);                  // 0x4e
    void FUN_1417212a0(CInPacket& packet);                  // 0x4d
    void FUN_1417212d0(CInPacket& packet);                  // 0x4f
    void FUN_1417215a0(CInPacket& packet);                  // 0x5d
    void FUN_141721940(CInPacket& packet);                  // 0x36
    void FUN_141721a30(CInPacket& packet);                  // 0x5f
    void FUN_141721c50(CInPacket& packet);                  // 0x61
    void FUN_141721c90(CInPacket& packet);                  // 0x62
    void FUN_141721cd0(CInPacket& packet);                  // 0x54
    void FUN_141722f70(CInPacket& packet);                  // 0x60
    void FUN_141722fb0(CInPacket& packet);                  // 0x64
    void FUN_141723050(CInPacket& packet);                  // 0x65
    void FUN_141723260(CInPacket& packet);                  // 0x66
    void FUN_1417232a0(CInPacket& packet);                  // 0x67
    void FUN_141723330(CInPacket& packet);                  // 0x70
    void FUN_1417235a0(CInPacket& packet);                  // (cube item placed by an actor)
    void FUN_141723410(CInPacket& packet);                  // 0x68
    void FUN_141723670(CInPacket& packet);                  // 0x69
    void FUN_141728110(CInPacket& packet);                  // 0x6a
    void FUN_141728c20(CInPacket& packet);                  // 0x71
    void FUN_141729250(CInPacket& packet);                  // 0x73
    void FUN_141729ce0(CInPacket& packet);                  // 0x74
    void FUN_14172a1c0(CInPacket& packet);                  // 0x75
    void FUN_14172a7b0(CInPacket& packet);                  // 0x76
    void FUN_14172a850(CInPacket& packet);                  // 0x77
    void FUN_14172a8f0(CInPacket& packet);                  // 0x79
    void FUN_14172b350(CInPacket& packet);                  // 0x7b
    void FUN_14172c170(CInPacket& packet);                  // 0x6e
    void FUN_14172d0f0(CInPacket& packet);                  // 0x63
    void FUN_14172f030(CInPacket& packet);                  // 0x42
    void FUN_14172f1c0(CInPacket& packet);                  // 0x43
    void FUN_14172f210(CInPacket& packet);                  // 0x44
    void FUN_14172f480(CInPacket& packet);                  // 0x45
    void FUN_14172f500(CInPacket& packet);                  // 0x7e
    void FUN_141730920(CInPacket& packet);                  // 0x7f
    void FUN_141731160(CInPacket& packet);                  // 0x89
    void FUN_141731190(CInPacket& packet);                  // 0x94
    void FUN_141731350(CInPacket& packet);                  // 0x95
    void FUN_141731470(CInPacket& packet);                  // 0x80
    void FUN_141731610(CInPacket& packet);                  // 0x81
    void FUN_1417316d0(CInPacket& packet);                  // 0x83
    void FUN_141731730(CInPacket& packet);                  // 0x86
    void FUN_141731ac0(CInPacket& packet);                  // 0x96
    void FUN_141731af0(CInPacket& packet);                  // 0xdb
    void FUN_141731b20(CInPacket& packet);                  // 0xc
    void FUN_141731c10(CInPacket& packet);                  // 0x8c
    void FUN_141732350(CInPacket& packet);                  // 0xb6
    void FUN_141732ac0(CInPacket& packet);                  // 0x9d
    void FUN_141732af0(CInPacket& packet);                  // 0x9e
    void FUN_141732b20(CInPacket& packet);                  // 0x97
    void FUN_141733140(CInPacket& packet);                  // 0x9b
    void FUN_141733440(CInPacket& packet);                  // 0x9f
    void FUN_141733660(CInPacket& packet);                  // 0xa1
    void FUN_1417337c0(CInPacket& packet);                  // 0xa2
    void FUN_141733850(CInPacket& packet);                  // 0xa3
    void FUN_141733b30(CInPacket& packet);                  // 0xb0
    void FUN_141733e40(CInPacket& packet);                  // 0xb1
    void FUN_141733f50(CInPacket& packet);                  // 0xb5
    void FUN_1417340f0(CInPacket& packet);                  // 0xb7
    void FUN_1417343c0(CInPacket& packet);                  // 0xb9
    void FUN_1417343f0(CInPacket& packet);                  // 0xba
    void FUN_141734530(CInPacket& packet);                  // 0xbc
    void FUN_141734930(CInPacket& packet);                  // 0xbe
    void FUN_141734950(CInPacket& packet);                  // 0xbf
    void FUN_141734b20(CInPacket& packet);                  // 0xc1
    void FUN_141734b70(CInPacket& packet);                  // 0xc2
    void FUN_141734bc0(CInPacket& packet);                  // 0xc3
    void FUN_141734c70(CInPacket& packet);                  // 0xc4
    void FUN_141734ca0(CInPacket& packet);                  // 0xc5
    void FUN_141734e00(CInPacket& packet);                  // 0xd8
    void FUN_1417353b0(CInPacket& packet);                  // 0xc7
    void FUN_1417353e0(CInPacket& packet);                  // 0xca
    void FUN_141735410(CInPacket& packet);                  // 0xcb
    void FUN_141735440(CInPacket& packet);                  // 0xcd
    void FUN_141735dd0(CInPacket& packet);                  // 0xf7
    void FUN_141736240(CInPacket& packet);                  // 0xf9
    void FUN_141736880(CInPacket& packet);                  // 0xa6
    void FUN_141736940(CInPacket& packet);                  // 0xa8
    void FUN_141737360(CInPacket& packet);                  // 0x1a
    void FUN_1417373d0(CInPacket& packet);                  // 0xaa
    void FUN_141737d60(CInPacket& packet);                  // 0xd1
    void FUN_141737db0(CInputStream& in);                   // 0xd3
    void FUN_1417380c0(CInPacket& packet);                  // 0xd6
    void FUN_141738120(CInPacket& packet);                  // 0xd7
    void FUN_141738290(CInPacket& packet);                  // 0xdc
    void FUN_141738380(CInPacket& packet);                  // 0xdd
    void FUN_141738430(CInPacket& packet);                  // 0xe8
    void FUN_141738ad0(CInPacket& packet);                  // 0xe7
    void FUN_141738b40(CInPacket& packet);                  // 0xea
    void FUN_141739910(CInPacket& packet);                  // 0xab
    void FUN_141739e40(CInPacket& packet);                  // 0xac
    void FUN_141739f90(CInPacket& packet);                  // 0xeb
    void FUN_14173a0d0(CInPacket& packet);                  // 0xec
    void FUN_14173a0f0(CInPacket& packet);                  // 0x101
    void FUN_14173a370(CInPacket& packet);                  // 0xe9
    void FUN_14173a420(CInPacket& packet);                  // 0xf1
    void FUN_14173a5b0(CInPacket& packet);                  // 0xf2
    void FUN_14173a5e0(CInPacket& packet);                  // 0xf3
    void FUN_14173a720(CInPacket& packet);                  // 0xf4
    void FUN_14173a990(CInPacket& packet);                  // 0xf8
    void FUN_14173aa10(CInPacket& packet);                  // mode 2
    void FUN_14173ad60(CInPacket& packet);                  // mode 0
    void FUN_14173b080(CInPacket& packet);                  // 0xfa
    void FUN_14173b1d0(CInPacket& packet);                  // 0xfb
    void FUN_14173b220(CInPacket& packet);                  // 0xfd
    void FUN_14173b380(CInPacket& packet);                  // 0xfe
    void FUN_14173b420(CInPacket& packet);                  // 0x103
    void FUN_14173b5a0(CInPacket& packet);                  // 0x105
    void FUN_14173c090(CInPacket& packet);                  // 0x106
    void FUN_14173c0f0(CInPacket& packet);                  // 0x106 mode 1
    void FUN_14173c2d0(CInPacket& packet);                  // 0x141739910 sub-handler (codi tab activated)
    void FUN_141715860(CInPacket& packet);  // 0x141713fb0 sub-handler (mode 8, item list)
    void FUN_14173c630(CInPacket& packet);                  // 0x141739910 sub-handler (beauty shop open)
    void FUN_14173c7a0(CInPacket& packet);                  // 0x111
    void FUN_14173c870(CInPacket& packet);                  // 0x115
    void FUN_14173ce30(CInPacket& packet);                  // 0x118
    void FUN_14173d180(CInPacket& packet);                  // 0x11a
    void FUN_14173d2e0(CInPacket& packet);                  // 0x11b
    void FUN_14173d4d0(CInPacket& packet);                  // 0x11c
    void FUN_14173ddf0(CInPacket& packet);                  // 0x120
    void FUN_14173de10(CInPacket& packet);                  // 0x121
    void FUN_14173def0(CInPacket& packet);                  // 0x91
    void FUN_14173dfd0(CInPacket& packet);                  // 0x11f
    void FUN_14173e440(CInPacket& packet);                  // 0x126
    void FUN_14173e4b0(CInPacket& packet);                  // 0xef
    void FUN_14173e510(CInPacket& packet);                  // 0xf5
    void FUN_14173e5b0(CInPacket& packet);                  // 0x12b
    void FUN_14173f0c0(CInPacket& packet);                  // 0x12c
    void FUN_14173f1a0(CInPacket& packet);                  // 0x12e
    void FUN_14173f280(CInPacket& packet);                  // 0x12f
    void FUN_14173f550(CInPacket& packet);                  // 0xde
    void FUN_14173f7c0(CInPacket& packet);                  // 0x131
    void FUN_14173f810(CInPacket& packet);                  // 0x135
    void FUN_14173f860(CInPacket& packet);                  // 0x136
    void FUN_14173fc00(CInPacket& packet);                  // 0x138
    void FUN_14173fc40(CInPacket& packet);                  // 0x139

    // helpers
    void FUN_1417127b0(CInPacket& packet, PCBase* pActor);    // read an actor's skill/buff list
    void FUN_141739450(bool bFlag);                         // spawn the taxi-station markers
    void FUN_141738240(CInPacket& packet);                  // (no dispatch case: reads the mode byte only)
    void FUN_141739220(CInPacket& packet);                  // 0xea sub-handler: formatted notice
    void FUN_1417398d0();                                   // refresh the individual pvp dialog
    void FUN_141739880();                                   // drop the taxi effect (m_nTaxiEffect)
    int FUN_14173fe20();                                    // Ctrl+Alt+... debug key combination
    void FUN_14173feb0();                                   // the debug key action
    void FUN_141740200(const CStringW& strName, int nType); // send packet 0x51 (mode 0, name, type)
    bool FUN_141740280(int nButton, const CMsgBoxData& data); // message box callback: answers packet 0x51

public:   // members (names inferred)
    bool m_b18;                                             // +0x18 (true)
    double m_f20;                                           // +0x20 (OnEnter: FUN_141473280)
    int m_nOpcode;                                          // +0x28 opcode of the packet being handled
    int m_nTaxiEffect;                                      // +0x2c effect handle (FUN_1411a49c0)
    bool m_bReconnecting;                                   // +0x30
    Timer m_reconnectTimer;                                 // +0x38
    int m_nRetry;                                           // +0x70
};
MS2_CHECK_SIZE(CSceneStateGame, 0x78);
MS2_CHECK_OFFSET(CSceneStateGame, m_nOpcode, 0x28);
MS2_CHECK_OFFSET(CSceneStateGame, m_reconnectTimer, 0x38);
MS2_CHECK_OFFSET(CSceneStateGame, m_nRetry, 0x70);
