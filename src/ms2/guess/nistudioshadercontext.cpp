// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NiStudioShaderContext (NiMain, names inferred): the
// process-wide record of which nif each loaded scene object came from, so a shader that fails to build can name the
// file and node it was generated for. ~NiAVObject drops an object's record (NiAVObject.cpp); NiFragmentMaterial sets
// m_pkCurrentObject around GenerateShader; nif loading adds the records (AddNifPath, nifeffectparam.cpp).
// The TU's first function, a ctor at 0x141d6fcb0 (zeroes m_pkCurrentObject, builds the map head) that nothing calls or
// references, is left out: a user-declared ctor would change the getter's inlined construction.
// MS2-UNIT: ?\nistudioshadercontext.cpp
// MS2-RANGE: 0x141d6fcf0-0x141d6fed0 .text$mn
// MS2-RANGE: 0x142cc4710-0x142cc4720 .text$yd
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <NiNode.h>
#include <NiString.h>
#include <NiStudioShaderContext.h>

#ifndef MS2_HOOK_DLL
// the nif path of m_pkCurrentObject (the nearest ancestor that has one) and the object's own name
// @0x141d6fcf0
bool NiStudioShaderContext::GetCurrentNifPath(NiString& kNifPath, NiString& kNodeName)
{
    for (const NiAVObject* pkObject = m_pkCurrentObject; pkObject; pkObject = pkObject->GetParent())
    {
        std::map<NiAVObject*, NiString>::iterator it = m_kNifPaths.find(const_cast<NiAVObject*>(pkObject));
        if (it != m_kNifPaths.end())
        {
            kNifPath = it->second;
            kNodeName = m_pkCurrentObject->GetName();
            return true;
        }
    }
    return false;
}

// the instance: a function-local static (0x143afb278; atexit dtor 0x142cc4710)
// @0x141d6fd90
NiStudioShaderContext& NiGetStudioShaderContext()
{
    static NiStudioShaderContext s_kContext;
    return s_kContext;
}

// @0x141d6fe20
bool NiStudioShaderContext::GetNifPath(const NiAVObject* pkObject, NiString& kNifPath)
{
    for (; pkObject; pkObject = pkObject->GetParent())
    {
        std::map<NiAVObject*, NiString>::iterator it = m_kNifPaths.find(const_cast<NiAVObject*>(pkObject));
        if (it != m_kNifPaths.end())
        {
            kNifPath = it->second;
            return true;
        }
    }
    return false;
}
#endif
