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
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/asbutton.h"
#include "ms2/commonfiles/os.h"  // C3: Unk_OSInput::Read6
#include "ms2/ms2format.h"
#include "ms2/placeholder/packethandlermanager.h"  // C3: PacketHandlerManager::RegisterHandler/UnregisterHandler

// ---- unit-local placeholders (unrecovered singletons / helpers; promote to src/ms2/placeholder/ when shared) ----

// The incoming packet stream is a sub-object at +8 of CInPacket.
class CInPacket { public: void* m_pad_00; Unk_OSInput m_stream; };

// The packet manager: handlers are registered per opcode.
class Unk_140bccd50
{
public:
    void FUN_140da5180(int nOpcode, Delegate<void(CInPacket&)> handler);       // add
    void FUN_140da51e0(int nOpcode, Delegate<void(CInPacket&)> handler);       // remove
};
Unk_140bccd50* GetPacketHandlerManager();

    // string table lookup
CStringW FUN_140e14b70(MS2Ptr<DungeonRoom> pRoom);                          // dungeon name of a room
void SetChildText(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140e176a0
UIDungeonLobby::UIDungeonLobby()
{
    m_2c = 0x16;
    m_80 = 0;
    SetFlag(0, 1);
    ((class PacketHandlerManager*)GetPacketHandlerManager())->RegisterHandler(0xf0, Delegate<void(CInPacket&)>(this, &UIDungeonLobby::OnRoomPacket));
}

// @0x140e177e0
UIDungeonLobby::~UIDungeonLobby()
{
    ((class PacketHandlerManager*)GetPacketHandlerManager())->UnregisterHandler(0xf0, Delegate<void(CInPacket&)>(this, &UIDungeonLobby::OnRoomPacket));
}

// @0x140e178e0
CString UIDungeonLobby::GetTypeName()
{
    return "DungeonLobby";
}
MS2_REPLACE_METHOD(0x140E178E0, UIDungeonLobby, GetTypeName, 61, 0x141A279F);

// @0x140e17930
void UIDungeonLobby::OnRoomPacket(CInPacket& packet)
{
    packet.m_stream.Read6((unsigned&)m_nRoomId);
    packet.m_stream.Read6((unsigned&)m_n17c);
    FUN_141924680();
}
MS2_REPLACE_METHOD(0x140E17930, UIDungeonLobby, OnRoomPacket, 85, 0xCFBA290E);

// @0x140e17990
void UIDungeonLobby::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30 == NULL)
        return;
    {
        FUN_1419260d0("m_webGuideButton", 0);
        do {
            m_30->FUN_140bbe640<ASButton>("m_webGuideButton", m_pWebGuideButton);
            if (m_pWebGuideButton == NULL)
                throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                            MS2_THIS_FILE, MS2_LINE(45), __FUNCTION__));
        } while (0);
        do {
            m_30->FUN_140beaf20<ASTextField>("m_title", m_pTitle);
            if (m_pTitle == NULL)
                throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                            MS2_THIS_FILE, MS2_LINE(46), __FUNCTION__));
        } while (0);
        DungeonRoomPtr pRoom = TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(m_nRoomId);
        if (pRoom == NULL)
            return;
        {
            CStringW strTitle = FUN_14028dfa0<CStringW, CStringW>(L"s_dungeonLobby_title", FUN_140e14b70(pRoom),
                                              TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x14, pRoom->GetDungeonRoomID()));
            m_pTitle->SetTextW(strTitle);
            SetChildText(GetGFxValue(), "m_subTitle", FUN_14028dfa0<unsigned int>(L"s_dungeonLobby_subTitle", (unsigned&)m_n17c));
            if (pRoom->m_groupType == 2 || pRoom->m_groupType == 3) {
                const float fOffset = 10.0f;
                float x = 0.0f;
                float y = 0.0f;
                m_pWebGuideButton->GetPosition(&x, &y);
                x += static_cast<float>(m_pTitle->GetTextWidth()) / 2.0f;
                x += fOffset;
                m_pWebGuideButton->SetPositionFloat(x, y);
            } else {
                m_pWebGuideButton->vfunc_4(false);
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
