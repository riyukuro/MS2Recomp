// GameEvent subclasses of gameeventlobbymap.cpp (names from the exe's RTTI / registration strings).
#pragma once
#include "gameevent.h"

class GameEventLobbyMap : public GameEvent {
public:
    GameEventLobbyMap();
    virtual CStringW GetTypeName();
    virtual void vfunc_2();
    virtual void vfunc_3(Unk_GEOut* out);
    virtual void vfunc_4(Unk_GEIn* in);
    virtual void OnStart();
    virtual void vfunc_6();
private:
    MS2_LAYOUT_FRIEND;
    int m_mapId;            // +0xd0
    int m_pad_d4;
};
MS2_CHECK_SIZE(GameEventLobbyMap, 0xd8);

class GameEventLoginNotice : public GameEvent {
public:
    GameEventLoginNotice();
    virtual CStringW GetTypeName();
    virtual void vfunc_2();
    virtual void OnStart();
    virtual void vfunc_6();
};
MS2_CHECK_SIZE(GameEventLoginNotice, 0xd0);

class GameEventCharacterCountRestricted : public GameEvent {
public:
    GameEventCharacterCountRestricted();
    virtual CStringW GetTypeName();
    virtual void vfunc_2();
    virtual void vfunc_3(Unk_GEOut* out);
    virtual void vfunc_4(Unk_GEIn* in);
    virtual void OnStart();
    virtual void vfunc_6();
private:
    int m_limit;            // +0xd0
    int m_pad_d4;
};
MS2_CHECK_SIZE(GameEventCharacterCountRestricted, 0xd8);

class GameEventOnlinePatch : public GameEvent {
public:
    GameEventOnlinePatch();
    virtual CStringW GetTypeName();
    virtual void vfunc_2();
    virtual void vfunc_3(Unk_GEOut* out);
    virtual void vfunc_4(Unk_GEIn* in);
    virtual void OnStart();
    virtual void vfunc_6();
};
MS2_CHECK_SIZE(GameEventOnlinePatch, 0xd0);
