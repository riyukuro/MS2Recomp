// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxFileOpener, the Scaleform file opener of the GFx UI
// library.
// MS2-UNIT: ?\gfxfileopener.cpp
// MS2-RANGE: 0x1422eaea0-0x1422eb480 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/gfxfileopener.h.
#include "ms2/placeholder/ms2stdafx.h"

#include <stdlib.h>
#include <string.h>

#include "ms2/placeholder/gfxfileopener.h"

#include "hook/ms2hook.h"

using Scaleform::File;

// The GFx UI manager singleton (0x14025e7a0; its class lives in the library's first obj, 0x1422b0060-0x1422b7f20).
class Unk_GFxUIManager
{
public:
    CString FUN_1422b0d10();            // the path of the IME movie
};
Unk_GFxUIManager* FUN_14025e7a0();

int FUN_14083f4d0(CString a, CString b);   // case-insensitive compare (both lower-cased; by value: the callee destroys them)

extern GFxFileOpener::OpenCallback DAT_143b0d790;   // the open callback (0 until FUN_1422eb400 sets it)

// @0x1422eaea0
GFxFileOpener::GFxFileOpener()
    : Scaleform::GFx::FileOpener()
    , m_bImeXmlOpened(0)
    , m_bImeSwfOpened(0)
    , m_strImeXmlPath("./Data/Xml/Table/ime.xml")
{
}

// @0x1422eaf20
GFxFileOpener::~GFxFileOpener()
{
}

#pragma function(strcmp)             // the exe calls the CRT strcmp (no inline compare loop)

// @0x1422eaf60
File* GFxFileOpener::OpenFile(const char* purl, int flags, int mode)
{
    if (m_bImeXmlOpened == 0) {
        char szFName[256] = {};
        char szDrive[3] = {};
        char szDir[260] = {};
        char szExt[260] = {};
        _splitpath_s(purl, szDrive, 3, szDir, 260, szFName, 256, szExt, 260);
        if (strcmp(szFName, "ime") == 0 && strcmp(szExt, ".xml") == 0) {
            m_bImeXmlOpened = 1;
            return FUN_1422eb2f0(m_strImeXmlPath, flags, mode);
        }
    }
    if (m_bImeSwfOpened == 0) {
        char szFName[256] = {};
        char szDrive[3] = {};
        char szDir[260] = {};
        char szExt[260] = {};
        _splitpath_s(purl, szDrive, 3, szDir, 260, szFName, 256, szExt, 260);
        if (FUN_14083f4d0(szFName, "Ime") == 0 && (strcmp(szExt, ".swf") == 0 || strcmp(szExt, ".gfx") == 0)) {
            m_bImeSwfOpened = 1;
            CString strImePath = FUN_14025e7a0()->FUN_1422b0d10();
            return FUN_1422eb2f0(strImePath, flags, mode);
        }
    }
    return FUN_1422eb2f0(purl, flags, mode);
}
MS2_REPLACE_METHOD(0x1422EAF60, GFxFileOpener, OpenFile, 901, 0xFE0947BF);

// @0x1422eb2f0
File* GFxFileOpener::FUN_1422eb2f0(const CString& strPath, int flags, int mode)
{
    File* pFile = NULL;
    if (DAT_143b0d790 != NULL && (flags & Scaleform::FileConstants::Open_Read)) {
        pFile = DAT_143b0d790(strPath);
    }
    else {
        Scaleform::SInt64 nTime = GetFileModifyTime(strPath);
        if (nTime == -1)
            return NULL;
    }
    if (pFile == NULL)
        pFile = Scaleform::GFx::FileOpener::OpenFile(strPath, flags, mode);
    if (pFile != NULL && pFile->IsValid())
        return pFile;
    return NULL;
}
MS2_REPLACE_METHOD(0x1422EB2F0, GFxFileOpener, FUN_1422eb2f0, 252, 0x575A02EC);

// @0x1422eb400
void GFxFileOpener::FUN_1422eb400(OpenCallback pfn)
{
    DAT_143b0d790 = pfn;
}

// MS2-PIN: ??_GGFxFileOpener@@UEAAPEAXI@Z 0x1422eb420
