// survivalstormfx.h - Mushking Royale restore: the storm zone effects and minimap markers (GMS CStormManager visuals).
// NOT recovered KMS code; ported from the GMS 2019 x86 client. Included only by survivalstormfx.cpp.
#pragma once

namespace SurvivalStormFx
{
    // GMS ctor 0x74b530: the base radius at +4 (the A01 nif is modelled for this radius).
    const float kBaseRadius = 5000.0f;
    // GMS 0x74b530: the minimap storm marker names (also the swf icon names).
    extern const wchar_t* const kMarkerStorm;      // L"storm"
    extern const wchar_t* const kMarkerPreview;    // L"storm_preview"
    // GMS 0x74baa0 / 0x74b8d0: UI id of the minimap dialog (KMS UIMinimapDialog::vfunc_48 returns the same id).
    const int kMinimapUiId = 0x4e29;
}
