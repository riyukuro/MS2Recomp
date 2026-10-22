// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uidungeonlobby.h.
// MS2-UNIT: client\ms2\uidungeonlobby.cpp
// MS2-RANGE: 0x140e176a0-0x140e186e0 .text$mn
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidungeonlobby.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uidungeonlobby.h"

#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxexception.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (unrecovered singletons / helpers; promote to src/ms2/placeholder/ when shared) ----

// The incoming packet stream (a sub-object at +8 of CInPacket); FUN_14070f480 reads one int.
class Unk_CInStream { public: void FUN_14070f480(int& n); };
class CInPacket { public: void* m_pad_00; Unk_CInStream m_stream; };

// The packet manager: handlers are registered per opcode.
class Unk_140bccd50
{
public:
    void FUN_140da5180(int nOpcode, Delegate<void(CInPacket&)> handler);       // add
    void FUN_140da51e0(int nOpcode, Delegate<void(CInPacket&)> handler);       // remove
};
Unk_140bccd50* FUN_140bccd50();

// The dungeon room record looked up by room id; +0x1c is the room kind (2 and 3 move the web guide button).
class Unk_DungeonRoomData
{
public:
    int FUN_14031ddd0();                                // dungeon id
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; int m_pad_18;
public:
    int m_nKind;                                        // +0x1c
};
MS2_CHECK_SIZE(Unk_DungeonRoomData, 0x20);
class Unk_14031c2a0 { public: MS2Ptr<Unk_DungeonRoomData> FUN_1403206b0(int nRoomId); };
Unk_14031c2a0* FUN_14031c2a0();
class Unk_1401a9d70 { public: CStringW FUN_141811980(int nCategory, int nId); };    // string table lookup
Unk_1401a9d70* FUN_1401a9d70();
CStringW FUN_140e14b70(MS2Ptr<Unk_DungeonRoomData> pRoom);                          // dungeon name of a room
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);      // localized, formatted
CStringW FUN_140938ae0(CStringW strKey, const int& n);                              // localized, formatted
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
// "GfxError:{0} {1}({2}) function:{3}"-style formatter (probably a variadic template taking const T&...).
CString FUN_140be2000(const char* szFormat, const char* a1, const char* a2, const int& a3, const char* a4);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140e176a0
UIDungeonLobby::UIDungeonLobby()
{
    m_2c = 0x16;
    m_80 = 0;
    FUN_141925e70(0, 1);
    FUN_140bccd50()->FUN_140da5180(0xf0, Delegate<void(CInPacket&)>(this, &UIDungeonLobby::FUN_140e17930));
}

// @0x140e177e0
UIDungeonLobby::~UIDungeonLobby()
{
    FUN_140bccd50()->FUN_140da51e0(0xf0, Delegate<void(CInPacket&)>(this, &UIDungeonLobby::FUN_140e17930));
}

// @0x140e178e0
CString UIDungeonLobby::GetTypeName()
{
    return "DungeonLobby";
}
MS2_REPLACE_METHOD(0x140E178E0, UIDungeonLobby, GetTypeName, 61, 0x141A279F);

// @0x140e17930
void UIDungeonLobby::FUN_140e17930(CInPacket& packet)
{
    packet.m_stream.FUN_14070f480(m_nRoomId);
    packet.m_stream.FUN_14070f480(m_n17c);
    FUN_141924680();
}
MS2_REPLACE_METHOD(0x140E17930, UIDungeonLobby, FUN_140e17930, 85, 0xCFBA290E);

// @0x140e17990
void UIDungeonLobby::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30 == NULL)
        return;
    {
        FUN_1419260d0("m_webGuideButton", 0);
        do {
            m_30->FUN_140bbe640("m_webGuideButton", m_pWebGuideButton);
            if (m_pWebGuideButton == NULL)
                throw new GfxExceptionSwfLoad(FUN_140be2000("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                            MS2_THIS_FILE, MS2_LINE(45), __FUNCTION__));
        } while (0);
        do {
            m_30->FUN_140bbe640("m_title", m_pTitle);
            if (m_pTitle == NULL)
                throw new GfxExceptionSwfLoad(FUN_140be2000("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                            MS2_THIS_FILE, MS2_LINE(46), __FUNCTION__));
        } while (0);
        MS2Ptr<Unk_DungeonRoomData> pRoom = FUN_14031c2a0()->FUN_1403206b0(m_nRoomId);
        if (pRoom == NULL)
            return;
        {
            CStringW strTitle = FUN_1408f71a0(L"s_dungeonLobby_title", FUN_140e14b70(pRoom),
                                              FUN_1401a9d70()->FUN_141811980(0x14, pRoom->FUN_14031ddd0()));
            m_pTitle->FUN_1422c4cd0(strTitle);
            FUN_140cfee80(FUN_1422dbb40(), "m_subTitle", FUN_140938ae0(L"s_dungeonLobby_subTitle", m_n17c));
            if (pRoom->m_nKind == 2 || pRoom->m_nKind == 3) {
                const float fOffset = 10.0f;
                float x = 0.0f;
                float y = 0.0f;
                m_pWebGuideButton->FUN_1422c0f60(&x, &y);
                x += static_cast<float>(m_pTitle->FUN_1422c5970()) / 2.0f;
                x += fOffset;
                m_pWebGuideButton->FUN_1422c00f0(x, y);
            } else {
                m_pWebGuideButton->vfunc_4(0);
            }
        }
    }
}

MS2_REPLACE_METHOD(0x140E17990, UIDungeonLobby, OnLoadComplete, 1886, 0xE7410DF1);

// @0x140e18140
void UIDungeonLobby::vfunc_26()
{
    UIDialog::vfunc_26();
    m_pWebGuideButton = 0;
    m_pTitle = 0;
}
MS2_REPLACE_METHOD(0x140E18140, UIDungeonLobby, vfunc_26, 66, 0x8BFB28DE);

MS2_EMIT_CRT_MEMMOVE_S();
