// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2UIMaterial: the MS2StandardMaterial used for UI
// geometry. It only turns fog off; its node fragments (MonochromeCompositeFinalRGBColor and friends) are in
// ms2uimaterialnodelibrary.cpp. No __FILE__ strings; file name guessed from the class name.
// MS2-UNIT: ?\ms2uimaterial.cpp
// MS2-RANGE: 0x142777100-0x142777210 .text$mn
// MS2-FLAGS: gamebryo
#include "ms2/placeholder/ms2stdafx.h"

#include <NiStandardMaterial.h>
#include <NiStandardPixelProgramDescriptor.h>
#include <NiMaterialResource.h>
#include "ms2/client/ms2/material/ms2materials.h"
#include "hook/ms2hook.h"

//--------------------------------------------------------------------------------------------------
// @0x142777100
MS2UIMaterial::MS2UIMaterial(bool bAutoCreateCaches) :
    MS2StandardMaterial("MS2UIMaterial", "MS2StandardMaterial", 1, bAutoCreateCaches)
{
}

//--------------------------------------------------------------------------------------------------
// @0x142777200
bool MS2UIMaterial::HandleApplyFog(Context& kContext, NiStandardPixelProgramDescriptor* pkPixDesc,
    NiMaterialResource* pkUnfoggedColor, NiMaterialResource*& pkFogOutput)
{
    pkFogOutput = pkUnfoggedColor;
    return true;
}
MS2_REPLACE_METHOD(0x142777200, MS2UIMaterial, HandleApplyFog, 11, 0xB71BF337);

// NiImplementRTTI(MS2UIMaterial, MS2StandardMaterial): the initializer sits in the shared .text$di run.
// The hook DLL binds the exe's copy (symbols-manual row), so only the byte-match build defines it.
// MS2-RANGE: 0x14014d5d0-0x14014d5f0 .text$di
#ifndef MS2_HOOK_DLL
// @0x14014d5d0
const NiRTTI MS2UIMaterial::ms_RTTI("MS2UIMaterial", &MS2StandardMaterial::ms_RTTI);
#endif

// MS2-PIN: ??_7MS2UIMaterial@@6B@ 0x1431d58c0
// MS2-PIN: ?GetRTTI@MS2UIMaterial@@UEBAPEBVNiRTTI@@XZ 0x1427771f0
// MS2-PIN: ??_7?$NiTArray@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@ZV?$NiTMallocInterface@P6A_NPEAVNiMaterialDescriptor@@W4ReturnCode@NiFragmentMaterial@@IPEAVRenderPassDescriptor@3@IAEAI3@Z@@@@6B@ 0x143020d68
