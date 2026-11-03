// MS2SearchTexturePath (RTTI name): texture search path that asks the resource manager first.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#ifndef EE_EFD_CONFIG_RELEASE
#define EE_EFD_CONFIG_RELEASE
#endif
#ifndef EE_EFD_NO_IMPORT
#define EE_EFD_NO_IMPORT
#endif
#ifndef EE_USE_NATIVE_STL
#define EE_USE_NATIVE_STL
#endif
#include <efd/MemObject.h>

// View of NiTextureSearchPath: sits between NiSearchPath (m_uiNextPath, two 260-char paths) and MS2SearchTexturePath; 0x330 bytes.
// Ctor 0x141f42e30, dtor 0x141f42e80, Reset 0x141f436d0, GetNextSearchPath 0x141f42ff0.
class NiTextureSearchPath : public efd::MemObject {
public:
    NiTextureSearchPath();
    virtual ~NiTextureSearchPath();
    virtual void Reset();
    virtual bool GetNextSearchPath(char* pcPath, unsigned int uiStringLen);
protected:
    unsigned int m_uiNextPath;                  // +0x08
    char m_acFilePath[260];                     // +0x0c
    char m_acReferencePath[260];                // +0x110
    int m_pad_214;
    void* m_pad_218[35];
};
MS2_CHECK_SIZE(NiTextureSearchPath, 0x330);

// Resource manager singleton (FUN_140166420).
class Unk_STPResMgr {
public:
    bool FUN_140398190();
    bool FUN_14039a160(const char* referencePath, const char* filePath, char* pcPath, unsigned int len);
};

class MS2SearchTexturePath : public NiTextureSearchPath {
public:
    MS2SearchTexturePath();                                     // 0x141507ff0
    virtual ~MS2SearchTexturePath();                            // 0x141508030
    virtual void Reset();                                       // 0x1415080d0
    virtual bool GetNextSearchPath(char* pcPath, unsigned int uiStringLen);   // 0x141508100
    bool m_bQueried;                                            // +0x330
};
MS2_CHECK_SIZE(MS2SearchTexturePath, 0x338);

void* FUN_141508060();
void FUN_141508220(char* pcPath);
errno_t FUN_141508240(void* dst, rsize_t dstSize, const void* src, rsize_t srcSize);
