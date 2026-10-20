// gfxmanager.h - PLACEHOLDER for GFxManager (RTTI .?AVGFxManager@@, vftable 0x1431095e8), the GFx UI manager
// singleton of the game's GFx UI library: the movies by ui/movie id, the movie renderer, the stages. Its code is
// the library's first obj (?\gfxmanager.cpp, 0x1422b0060-0x1422b7f20, not recovered yet). NOT an original header.
// The singleton getter 0x14025e7a0 returns the pointer stored at 0x143aaccf8 (assumed to be the GFxManager the
// methods below belong to: they all live in that obj). Several units still declare the getter with unit-local
// stand-in return types (Unk_GFxUIManager, Unk_UiMgr, ...); new code should include this header instead.
// Declarations only; the layout is unknown (never instantiate or embed).
#pragma once

class GFxMovie;

class GFxManager
{
public:
    GFxMovie* FUN_1422b01a0(int nMovieId);                          // the movie of a movie id (NULL if not loaded)
};
GFxManager* FUN_14025e7a0();                                        // the singleton
