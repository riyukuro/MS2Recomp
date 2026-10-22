// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// Header name assumed; FUN names and member names follow addresses when unknown.
#pragma once
#include "ms2/placeholder/uidialog.h"
class CInPacket;
class GameEventVariable;
class Unk_RpsEvent;
class Unk_RpsInts;
class UIRpsEventDialog : public UIDialog {
public:
    UIRpsEventDialog();
    virtual ~UIRpsEventDialog();
    virtual CString GetTypeName();
    virtual void vfunc_72();
    virtual void vfunc_67();
    virtual void OnLoadComplete();
    virtual void vfunc_45(Scaleform::GFx::Value*, const CString&, ASData*);
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual int vfunc_71();
    virtual int OnMessage(UISwfEntity*, UIMsg*);
    virtual int vfunc_48();
    CString FUN_140e83120(int);
    void FUN_140e83200(Unk_RpsInts&);
    int FUN_140e832d0();
    void FUN_140e83370(MS2Ptr<Unk_RpsEvent>);
    void FUN_140e83a30();
    void FUN_140e83e40();
    void FUN_140e83fa0(int);
    int FUN_140e841a0();
    void FUN_140e84350(GameEventVariable*);
    void FUN_140e84380(CInPacket&);
private:
    MS2_LAYOUT_FRIEND;
    bool m_178;
};
MS2_CHECK_SIZE(UIRpsEventDialog, 0x180);
MS2_CHECK_OFFSET(UIRpsEventDialog, m_178, 0x178);
