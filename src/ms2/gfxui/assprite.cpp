// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASSprite, the AS Sprite wrapper of the GFx UI library.
// MS2-UNIT: ?\assprite.cpp
// MS2-RANGE: 0x1422e5be0-0x1422e6170 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asdisplayobject.h (Ghidra's FUN_<va> names are kept there). The COMDAT tail
// is the "graphics" child lookup for T = ASGraphics (AScript::FUN_140accef0 + the new-and-wrap helper) and the
// MS2Ptr<ASGraphics> members it uses.
// MS2-PIN: ??_GASSprite@@UEAAPEAXI@Z 0x1422e6020
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/gfxui/asgraphics.h"

#include "hook/ms2hook.h"

// new T(v, nMovieId) wrapped in an MS2Ptr (the same helper as uiupperhuddialog.cpp's; one COMDAT per T)
template <class T> inline MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

template <> MS2Ptr<ASGraphics> AScript::FUN_140accef0<ASGraphics>(const CString& strName);   // defined at the end

// @0x1422e5be0
ASSprite::ASSprite(const Scaleform::GFx::Value& v, int nMovieId)
    : ASDisplayObjectContainer(v, nMovieId)
{
}

// @0x1422e5c30
ASSprite::~ASSprite()
{
}

// @0x1422e5c60
MS2Ptr<ASGraphics> ASSprite::FUN_1422e5c60()
{
    return FUN_140accef0<ASGraphics>("graphics");
}
MS2_REPLACE_METHOD(0x1422E5C60, ASSprite, FUN_1422e5c60, 102, 0x79337F97);

// @0x1422e5cd0
void ASSprite::FUN_1422e5cd0(int bUse)
{
    FUN_1407cbbe0("useHandCursor", bUse != 0);
}
MS2_REPLACE_METHOD(0x1422E5CD0, ASSprite, FUN_1422e5cd0, 60, 0xCC6D1C81);

// @0x1422e5d20
int ASSprite::FUN_1422e5d20()
{
    return FUN_1422baa20("useHandCursor").GetBool();
}
MS2_REPLACE_METHOD(0x1422E5D20, ASSprite, FUN_1422e5d20, 91, 0xD750AEA7);

// @0x1422e5d90
void ASSprite::FUN_1422e5d90(int bLockCenter)
{
    FUN_1409ba030("startDrag", bLockCenter);
}
MS2_REPLACE_METHOD(0x1422E5D90, ASSprite, FUN_1422e5d90, 55, 0x35433689);

// @0x1422e5dd0
void ASSprite::FUN_1422e5dd0()
{
    Invoke("stopDrag");
}
MS2_REPLACE_METHOD(0x1422E5DD0, ASSprite, FUN_1422e5dd0, 46, 0x19CD2CE0);

// @0x1422e5eb0
template <> MS2Ptr<ASGraphics> AScript::FUN_140accef0<ASGraphics>(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return Unk_ASCreate<ASGraphics>(m_nMovieId, v);
    return MS2Ptr<ASGraphics>(0);
}
