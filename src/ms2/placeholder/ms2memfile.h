// ms2memfile.h - PLACEHOLDER for MS2MemFile (RTTI .?AVMS2MemFile@@, 0x40 bytes, vftable 0x142f46710). NOT an original
// header. An efd::File over a CFileSystem buffer (unit_141626c30, client\ms2\ms2memfile.cpp): the path ctor takes the
// buffer from the file system, the (data, size) ctor hands the bytes to a new CFileBuffer held at +0x30. The raw
// read/write slots 12/13 feed Gamebryo's EE_ImplementDerivedBinaryStream glue, as in efd::Win32File.
// ScaleformMemFile (RTTI, vftable 0x142f46788, 0x40 bytes) is the GFx counterpart: a Scaleform::MemoryFile over a
// CFileBuffer it keeps alive (+0x30).
#pragma once

#include <efd/FileCommon.h>
#include <efd/BinaryStreamMacro.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/filebuffer_1.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"

class MS2MemFile : public efd::FileCommon
{
    EE_DeclareDerivedBinaryStream();                        // 0x141626c30 / 0x141626c70 / 0x141626cb0 / 0x141626d20
public:
    MS2MemFile(const void* pData, int nSize);               // 0x141626f30
    MS2MemFile(const char* pszPath);                        // 0x141626e40: loads the file's bytes
    virtual ~MS2MemFile();                                  // 0x141627050
    virtual bool Seek(int iOffset, SeekOrigin eSeekFrom);  // 8 0x141627090
    virtual bool Flush();                                   // 7 0x1416271a0: rewinds
    virtual unsigned int GetFileSize() const;               // 9 0x1416271c0
    virtual void SetEndianSwap(bool bDoSwap);               // 6 0x141627210
    virtual unsigned int FUN_141627270(void* pDest, unsigned int nBytes);         // 12 raw read: the bytes copied
    virtual unsigned int FUN_141627370(const void* pSrc, unsigned int nBytes);    // 13 raw write: read only, 0
private:
    MS2_LAYOUT_FRIEND;
    unsigned int m_uiPos;                                   // +0x28 read position
    Unk_PayloadPtr<CFileBuffer> m_buffer;                   // +0x30 the shared CFileBuffer handle
};
MS2_CHECK_SIZE(MS2MemFile, 0x40);
MS2_CHECK_OFFSET(MS2MemFile, m_uiPos, 0x28);
MS2_CHECK_OFFSET(MS2MemFile, m_buffer, 0x30);
