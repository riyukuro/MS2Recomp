// Recovered dungeon closing photo dialog (the end-of-dungeon record screen: up to ten party members, each with a
// rendered avatar, a record text and a rank). Unk_ names are local reconstruction names.
#pragma once
#include <vector>
#include "uiskillpreviewdialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cptred.h"
class CInPacket;
class UIAvatarPC;
class Unk_ClosingActor;
// One party member's slot: the character uid, the rendered avatar, the AS clip it is shown in, the record text and
// the rank. The user-declared dtor makes the vector's element destroy go through the scalar deleting dtor (0x140e11c60).
struct Unk_ClosingEntry
{
    // @0x140e11a10
    Unk_ClosingEntry() {}
    // @0x140e11b10
    ~Unk_ClosingEntry() {}
    Unk_ClosingEntry(const Unk_ClosingEntry&) = default;
    Unk_ClosingEntry(Unk_ClosingEntry&&) = default;
    __int64 m_uid;                      // +0x00
    MS2Ptr<UIAvatarPC> m_avatar;        // +0x08
    MS2Ptr<ASUIComponent> m_clip;       // +0x18
    CStringW m_text;                    // +0x28
    int m_rank;                         // +0x30
};
MS2_CHECK_SIZE(Unk_ClosingEntry, 0x38);
class UIDungeonClosingPhotoDialog : public UIDialog, public IUIAvatarEventListener
{
public:
    UIDungeonClosingPhotoDialog();
    virtual ~UIDungeonClosingPhotoDialog();
    virtual CString GetTypeName();
    virtual void vfunc_26();
    virtual void vfunc_67();
    virtual void vfunc_72();
    virtual void OnLoadComplete();
    virtual void vfunc_25(void*, TPtr<Unk_UISwfEntity_25>, void*, void*);
    virtual void vfunc_16();
    virtual bool vfunc_17();
    virtual void vfunc_79(void*);
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual int vfunc_o178_1(void*);
    // @0x140e11cf0
    virtual int vfunc_48() { return 20249; }
    bool FUN_140e0ea40();
    void FUN_140e0eb40(CInPacket&);
    void FUN_140e0f6b0();
    void FUN_140e0f790();
    void FUN_140e0fcf0(int);
    void FUN_140e0fd20(int);
    void FUN_140e0fe40();
    void FUN_140e0ff50();
    void FUN_140e10010(int&, int&, unsigned&, int, int);
    void FUN_140e102b0(Unk_ClosingEntry*);
    void FUN_140e104d0(int);
    void FUN_140e10800(int, CStringW);
private:
    MS2_LAYOUT_FRIEND;
    std::vector<Unk_ClosingEntry> m_entries;    // +0x180
    std::vector<int> m_pending;                 // +0x198 slots whose clip was not loaded yet
    unsigned m_1b0;                             // +0x1b0 tick at which the dialog closes itself
    unsigned m_1b4;                             // +0x1b4 tick at which the timeout runs
    bool m_1b8;
    int m_1bc;                                  // +0x1bc map id the dungeon ended in
};
MS2_CHECK_SIZE(UIDungeonClosingPhotoDialog, 0x1c0);
MS2_CHECK_OFFSET(UIDungeonClosingPhotoDialog, m_entries, 0x180);
MS2_CHECK_OFFSET(UIDungeonClosingPhotoDialog, m_pending, 0x198);
MS2_CHECK_OFFSET(UIDungeonClosingPhotoDialog, m_1b0, 0x1b0);
MS2_CHECK_OFFSET(UIDungeonClosingPhotoDialog, m_1b8, 0x1b8);
MS2_CHECK_OFFSET(UIDungeonClosingPhotoDialog, m_1bc, 0x1bc);
