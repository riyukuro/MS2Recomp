// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2MaterialLibrary: the NiMaterialLibrary of MS2's fragment
// materials (name string "MS2MaterialLibrary"). It publishes one NiShaderDesc per material for the tools (30 entries)
// and creates/caches the materials by name. Registered from the MS2Material SDM (ms2materialsdm.cpp).
#pragma once

#include <NiMaterialLibrary.h>
#include <NiTFixedStringMap.h>
#include <NiMaterial.h>

class MS2MaterialLibrary : public NiMaterialLibrary
{
public:
    enum { MATERIAL_COUNT = 30 };

    MS2MaterialLibrary();
    virtual ~MS2MaterialLibrary();

    virtual NiMaterial* GetMaterial(const NiFixedString& kName);
    virtual const char* GetMaterialName(unsigned int ui);
    virtual unsigned int GetMaterialCount() const;
    virtual NiShaderDesc* GetFirstMaterialDesc();
    virtual NiShaderDesc* GetNextMaterialDesc();

    static MS2MaterialLibrary* Create();
    NiMaterial* CreateMaterial(const NiFixedString& kName);

    static void _SDMInit();
    static void _SDMShutdown();

    static void AddTextureAttribute(NiShaderDesc* pkDesc, const char* pcName, const char* pcDefault,
        unsigned int uiIndex);
    static void AddStandardTextureAttributes(NiShaderDesc* pkDesc);
    static void CreateCharacterDesc(NiShaderDesc*& pkDesc);

protected:

    NiShaderDesc* m_apkDescs[MATERIAL_COUNT];          // +0x18
    NiTFixedStringMap<NiMaterialPtr> m_kMaterials;     // +0x108

    static MS2MaterialLibrary* ms_pkThis;              // 0x143d691f8
    static unsigned int ms_uiCurrentDesc;              // 0x143d69200
};
