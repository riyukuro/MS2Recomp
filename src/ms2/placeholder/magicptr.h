#pragma once
// The 16 byte smart pointers shared by the magic, cube and world code. They are MS2Ptr<Unk_FcTag> / MS2Ptr<Unk_FcArea>,
// the same types functioncubeobject.cpp uses (CFunctionCubeService::SetTagArea). The tag/value that
// WorldService::FUN_141bc3470 takes by value (the m_3f0 key/value) are these two types. Moved here from magicdata.h.
// C3: these were the stand-in structs Unk_MagicTagPtr / Unk_MagicValPtr; the names are kept as typedefs.
// Tag members: ctor 0x141234900, (int) 0x1410a6af0, copy 0x1412348c0, dtor 0x1410a6d40, operator= 0x141235040,
// operator Unk_FcTag* 0x141235260, operator== 0x141235120, (Unk_FcTag*) 0x1410a6b10, get 0x1410a7150.
// Value members: (int) 0x141234840, copy 0x141234800, dtor 0x141234e70, operator= 0x141235000, operator== 0x1412350e0.
// The tag pointee is a SkillTargetRecord (skillrecord.h); Unk_FcTag keeps the functioncubeobject name.
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class Unk_FcTag;
class Unk_FcArea;
typedef MS2Ptr<Unk_FcTag> Unk_MagicTagPtr;
typedef MS2Ptr<Unk_FcArea> Unk_MagicValPtr;
