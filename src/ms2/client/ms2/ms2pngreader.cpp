// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2PNGReader: the game's NiImageReader for .png files. It parses the
// IHDR chunk itself (ReadHeader) and lets the statically linked libpng 1.6.17 decode the pixel rows, which are then converted
// row by row into the NiPixelData with a pointer-to-member row converter picked from the bit depth.
// MS2-UNIT: ?\ms2pngreader.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x140d9aba0-0x140d9d370 .text$mn
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2pngreader.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <setjmp.h>
#include <string.h>
#include <NiPixelData.h>
#include <NiPixelFormat.h>
#include <NiPalette.h>
#include <NiImageReader.h>
#include <NiBinaryStream.h>
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"

// ---- libpng 1.6.17 (statically linked, bound to the exe by FUN_<va>) ----
struct Unk_PngStruct;                                       // png_struct, opaque
struct Unk_PngInfo                                          // the png_info fields this unit reads
{
    unsigned int m_uiWidth;                                 // +0x00
    unsigned int m_uiHeight;                                // +0x04
    unsigned int m_uiValid;                                 // +0x08
    unsigned __int64 m_nRowBytes;                           // +0x10
    unsigned char* m_pPalette;                              // +0x18 png_color[3 bytes each]
    unsigned short m_usNumPalette;                          // +0x20
    unsigned short m_usNumTrans;                            // +0x22
    char m_pad24[0xb8 - 0x24];
    unsigned char* m_pTransAlpha;                           // +0xb8
    char m_padc0[0x150 - 0xc0];
    unsigned char** m_ppRowPointers;                        // +0x150
};
MS2_CHECK_OFFSET(Unk_PngInfo, m_pPalette, 0x18);
MS2_CHECK_OFFSET(Unk_PngInfo, m_usNumTrans, 0x22);
MS2_CHECK_OFFSET(Unk_PngInfo, m_pTransAlpha, 0xb8);
MS2_CHECK_OFFSET(Unk_PngInfo, m_ppRowPointers, 0x150);

typedef void (*PngMessageFn)(Unk_PngStruct*, const char*);
typedef void (*PngReadFn)(Unk_PngStruct*, unsigned char*, unsigned int);
Unk_PngStruct* FUN_1427086a0(const char* szVersion, void* pUser, PngMessageFn pfnError, PngMessageFn pfnWarn);   // png_create_read_struct
Unk_PngInfo* FUN_1427062f0(Unk_PngStruct* pPng);                         // png_create_info_struct
void* FUN_142706d40(Unk_PngStruct* pPng);                                // png_get_io_ptr
void FUN_142708730(Unk_PngStruct** ppPng, Unk_PngInfo** ppInfo, Unk_PngInfo** ppEnd);   // png_destroy_read_struct
void FUN_142707920(Unk_PngStruct* pPng, int nNumBytes);                  // png_set_sig_bytes
void FUN_14270bd30(Unk_PngStruct* pPng, Unk_PngInfo* pInfo, int nTransforms, void* pParams);   // png_read_png
void FUN_14270d120(Unk_PngStruct* pPng, void* pIoPtr, PngReadFn pfnRead);   // png_set_read_fn
jmp_buf* FUN_14270ce60(Unk_PngStruct* pPng, void (*pfnLongjmp)(jmp_buf, int), size_t nSize);   // png_set_longjmp_fn

// The exe's NiPixelFormat constants (symbols.tsv does not map them to the NiPixelFormat statics).
extern const NiPixelFormat DAT_1439faff0;                   // the reader's initial format
extern const NiPixelFormat DAT_1439faf00;                   // PAL4
extern const NiPixelFormat DAT_1439fafa0;                   // PAL8
extern const NiPixelFormat DAT_1439fb040;                   // RGBA32

void ChunkTypeToString(unsigned int uiType, char* pcOut);   // 0x140d9cb80
void PngError(Unk_PngStruct* pPng, const char* szMessage);  // 0x140d9cc20
void PngWarning(Unk_PngStruct* pPng, const char* szMessage);   // 0x140d9cc40
void PngRead(Unk_PngStruct* pPng, unsigned char* pucData, unsigned int uiBytes);   // 0x140d9cc60 libpng read callback

class __multiple_inheritance MS2PNGReader;
typedef void (MS2PNGReader::*MS2PngRowFn)(const unsigned char* pucSrc, unsigned char* pucDst);

class MS2PNGReader : public NiImageReader
{
public:
    MS2PNGReader();                                         // 0x140d9aba0
    virtual ~MS2PNGReader();                                // 0x140d9ad40
    virtual bool CanReadFile(const char* pcFileExtension) const;   // 0x140d9adc0
    virtual NiPixelData* ReadFile(efd::File& kIst, NiPixelData* pkOptDest);   // 0x140d9ae00
    virtual bool ReadHeader(efd::File& kIst, unsigned int& uiWidth, unsigned int& uiHeight, NiPixelFormat& kFormat,
        bool& bMipmap, unsigned int& uiFaces);              // 0x140d9aec0

    NiPixelData* ReadImage(efd::File& kIst, NiPixelData* pkOptDest);   // 0x140d9b630 the libpng decode
    void Convert4(const unsigned char* pucSrc, unsigned char* pucDst);       // 0x140d9bd80 4-bit indices
    void Convert8(const unsigned char* pucSrc, unsigned char* pucDst);       // 0x140d9be10 8-bit indices
    void ConvertGray24(const unsigned char* pucSrc, unsigned char* pucDst);  // 0x140d9bea0
    void Convert555(const unsigned char* pucSrc, unsigned char* pucDst);     // 0x140d9bf70
    void ConvertPal24(const unsigned char* pucSrc, unsigned char* pucDst);   // 0x140d9c070
    void ConvertPal32(const unsigned char* pucSrc, unsigned char* pucDst);   // 0x140d9c170
    void ConvertBGR24(const unsigned char* pucSrc, unsigned char* pucDst);   // 0x140d9c290
    void ConvertRGB32(const unsigned char* pucSrc, unsigned char* pucDst);   // 0x140d9c340
    void ConvertGray32(const unsigned char* pucSrc, unsigned char* pucDst);  // 0x140d9c400
    void ConvertRGBA32(const unsigned char* pucSrc, unsigned char* pucDst);  // 0x140d9c4c0
    void ReadRawRow(efd::File& kIst);                       // 0x140d9c590 raw (non-libpng) row read into the palette buffer

    NiPixelFormat m_kFormat;                                // +0x38
    MS2PngRowFn m_pfnConvert;                               // +0x80 the row converter (full-size member pointer)
    unsigned char m_aucSignature[8];                        // +0x90
    char m_acChunkType[8];                                  // +0x98
    unsigned char* m_pucRow;                                // +0xa0 the libpng row being converted
    NiPalette::PaletteEntry* m_pkPalette;                   // +0xa8
    union
    {
        unsigned int m_uiChunkLength;                       // +0xb0
        struct
        {
            unsigned char m_ucLen0, m_ucLen1, m_ucLen2, m_ucLen3;
        };
    };
    unsigned int m_uiChunkType;                             // +0xb4
    unsigned int m_uiB8;                                    // +0xb8
    unsigned int m_uiBufferSize;                            // +0xbc raw row buffer bytes
    unsigned int m_uiPaletteCapacity;                       // +0xc0
    unsigned short m_usIndexBias;                           // +0xc4
    unsigned short m_usNumPalette;                          // +0xc6
    unsigned short m_usC8;                                  // +0xc8
    unsigned short m_usCa;                                  // +0xca
    unsigned short m_usWidth;                               // +0xcc
    unsigned short m_usHeight;                              // +0xce
    unsigned char m_ucBitsPerPixel;                         // +0xd0
    unsigned char m_ucD1;                                   // +0xd1
    unsigned char m_ucRawBits;                              // +0xd2
    unsigned char m_ucConverterKind;                        // +0xd3
    unsigned char m_ucD4;                                   // +0xd4
    unsigned char m_ucColorType;                            // +0xd5
    unsigned char m_bHasAlpha;                              // +0xd6
    unsigned char m_bPalettized;                            // +0xd7
    unsigned char m_bFlipVertical;                          // +0xd8
};
MS2_CHECK_SIZE(MS2PNGReader, 0xe0);

// @0x140d9aba0
MS2PNGReader::MS2PNGReader()
{
    m_ucD4 = 0;
    m_ucColorType = 0;
    m_usIndexBias = 0;
    m_usNumPalette = 0;
    m_ucRawBits = 0;
    m_usC8 = 0;
    m_usCa = 0;
    m_usWidth = 0;
    m_usHeight = 0;
    m_ucBitsPerPixel = 0;
    m_ucD1 = 0;
    m_ucConverterKind = 0;
    m_bHasAlpha = 0;
    m_bPalettized = 0;
    m_bFlipVertical = 0;
    m_kFormat = DAT_1439faff0;
    m_uiBufferSize = 0;
    m_pucRow = 0;
    m_uiPaletteCapacity = 0;
    m_pkPalette = 0;
    m_pfnConvert = 0;
}

// @0x140d9ad40
MS2PNGReader::~MS2PNGReader()
{
    NiFree(m_pucRow);
    NiDelete[] m_pkPalette;
}

// @0x140d9adc0
bool MS2PNGReader::CanReadFile(const char* pcFileExtension) const
{
    if (_stricmp(pcFileExtension, ".png") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// @0x140d9ae00
NiPixelData* MS2PNGReader::ReadFile(efd::File& kIst, NiPixelData* pkOptDest)
{
    unsigned int uiWidth;
    unsigned int uiHeight;
    bool bMipmap;
    unsigned int uiFaces;
    NiPixelFormat kFormat;
    if (!ReadHeader(kIst, uiWidth, uiHeight, kFormat, bMipmap, uiFaces))
        return 0;
    return ReadImage(kIst, pkOptDest);
}

// MS2-FUNCTIONAL: frame 0x10 smaller: the exe materialises the member-function-pointer assignments through stack temps
// @0x140d9aec0
bool MS2PNGReader::ReadHeader(efd::File& kIst, unsigned int& uiWidth, unsigned int& uiHeight, NiPixelFormat& kFormat,
    bool& bMipmap, unsigned int& uiFaces)
{
    unsigned int uiCrc;
    char cInterlace;
    char cFilter;
    char cCompression;
    unsigned char ucColorType;
    char cBitDepth;
    uiFaces = 1;
    NiStreamLoadBinary(kIst, m_aucSignature[0]);
    NiStreamLoadBinary(kIst, m_aucSignature[1]);
    NiStreamLoadBinary(kIst, m_aucSignature[2]);
    NiStreamLoadBinary(kIst, m_aucSignature[3]);
    NiStreamLoadBinary(kIst, m_aucSignature[4]);
    NiStreamLoadBinary(kIst, m_aucSignature[5]);
    NiStreamLoadBinary(kIst, m_aucSignature[6]);
    NiStreamLoadBinary(kIst, m_aucSignature[7]);
    NiStreamLoadBinary(kIst, m_uiChunkLength);
    m_uiChunkLength = (m_ucLen0 << 24) + (m_ucLen1 << 16) + (m_ucLen2 << 8) + m_ucLen3;
    NiStreamLoadBinary(kIst, m_uiChunkType);
    ChunkTypeToString(m_uiChunkType, m_acChunkType);
    cBitDepth = 0;
    if (strcmp(m_acChunkType, "IHDR") == 0)
    {
        NiStreamLoadBinary(kIst, uiWidth);
        uiWidth = (*(unsigned char*)&uiWidth << 24) + (*((unsigned char*)&uiWidth + 1) << 16) + (*((unsigned char*)&uiWidth + 2) << 8) + *((unsigned char*)&uiWidth + 3);
        NiStreamLoadBinary(kIst, uiHeight);
        uiHeight = (*(unsigned char*)&uiHeight << 24) + (*((unsigned char*)&uiHeight + 1) << 16) + (*((unsigned char*)&uiHeight + 2) << 8) + *((unsigned char*)&uiHeight + 3);
        NiStreamLoadBinary(kIst, cBitDepth);
        NiStreamLoadBinary(kIst, m_ucColorType);
        NiStreamLoadBinary(kIst, cCompression);
        NiStreamLoadBinary(kIst, cFilter);
        NiStreamLoadBinary(kIst, cInterlace);
        NiStreamLoadBinary(kIst, uiCrc);
    }
    ucColorType = m_ucColorType;
    if (ucColorType == 0 || ucColorType == 2)
    {
        m_ucBitsPerPixel = cBitDepth * 3;
        m_bPalettized = 0;
    }
    else if (ucColorType == 3)
    {
        m_ucBitsPerPixel = cBitDepth;
        m_bPalettized = 1;
    }
    else if (ucColorType == 4)
    {
        m_ucBitsPerPixel = cBitDepth << 2;
        m_bPalettized = 0;
    }
    else if (ucColorType == 6)
    {
        m_ucBitsPerPixel = cBitDepth << 2;
        m_bHasAlpha = 1;
        m_bPalettized = 0;
    }
    if (m_ucBitsPerPixel == 4)
    {
        m_ucConverterKind = 0;
        m_pfnConvert = &MS2PNGReader::Convert4;
    }
    else if (m_ucBitsPerPixel == 8)
    {
        m_ucConverterKind = 1;
        m_pfnConvert = &MS2PNGReader::Convert8;
    }
    else if (m_ucBitsPerPixel == 0xf || m_ucBitsPerPixel == 0x10)
    {
        m_ucConverterKind = 2;
    }
    else if (m_ucBitsPerPixel == 0x18)
    {
        m_ucConverterKind = 3;
        if (m_ucColorType == 0 && cBitDepth == 8)
            m_pfnConvert = &MS2PNGReader::ConvertGray32;
        else
            m_pfnConvert = &MS2PNGReader::ConvertRGB32;
    }
    else if (m_ucBitsPerPixel == 0x20)
    {
        m_ucConverterKind = 4;
        m_pfnConvert = &MS2PNGReader::ConvertRGBA32;
    }
    m_bHasAlpha = 1;
    if (m_bPalettized == 0)
        m_kFormat = DAT_1439fb040;
    else if (cBitDepth == 4)
        m_kFormat = DAT_1439faf00;
    else
        m_kFormat = DAT_1439fafa0;
    m_usWidth = (unsigned short)uiWidth;
    m_usHeight = (unsigned short)uiHeight;
    kFormat = m_kFormat;
    bMipmap = false;
    return true;
}

// MS2-FUNCTIONAL: not byte-matched (libpng setjmp frame / NiNew shapes)
// @0x140d9b630
NiPixelData* MS2PNGReader::ReadImage(efd::File& kIst, NiPixelData* pkOptDest)
{
    kIst.Seek(0, efd::File::SO_BEGIN);
    Unk_PngStruct* pPng = 0;
    Unk_PngInfo* pInfo = 0;
    int nUser;
    pPng = FUN_1427086a0("1.6.17", &nUser, PngError, PngWarning);
    if (pPng == 0)
        return 0;
    pInfo = FUN_1427062f0(pPng);
    if (pInfo == 0)
    {
        FUN_142708730(&pPng, 0, 0);
        return 0;
    }
    if (setjmp(*FUN_14270ce60(pPng, longjmp, sizeof(jmp_buf))) != 0)
    {
        FUN_142708730(&pPng, &pInfo, 0);
        return 0;
    }
    FUN_14270d120(pPng, &kIst, PngRead);
    FUN_142707920(pPng, 0);
    FUN_14270bd30(pPng, pInfo, 0, 0);
    if (pInfo->m_pPalette != 0)
    {
        m_bPalettized = 1;
        m_usNumPalette = pInfo->m_usNumPalette;
        if (m_uiPaletteCapacity < pInfo->m_usNumPalette)
        {
            m_uiPaletteCapacity = pInfo->m_usNumPalette;
            NiDelete[] m_pkPalette;
            m_pkPalette = NiNew NiPalette::PaletteEntry[m_usNumPalette];
        }
        NiPalette::PaletteEntry* pkEntry = m_pkPalette;
        for (unsigned int ui = 0; ui < m_usNumPalette; ui++)
        {
            pkEntry->m_ucBlue = pInfo->m_pPalette[ui * 3 + 2];
            pkEntry->m_ucGreen = pInfo->m_pPalette[ui * 3 + 1];
            pkEntry->m_ucRed = pInfo->m_pPalette[ui * 3];
            pkEntry->m_ucAlpha = 0xff;
            pkEntry++;
        }
        pkEntry = m_pkPalette;
        if (pInfo->m_pTransAlpha != 0)
        {
            for (unsigned int ui = 0; ui < pInfo->m_usNumTrans; ui++)
            {
                pkEntry->m_ucAlpha = pInfo->m_pTransAlpha[ui];
                pkEntry++;
            }
        }
    }
    NiPixelData* pkPixels;
    if (pkOptDest != 0 && pkOptDest->GetWidth(0, 0) == m_usWidth && pkOptDest->GetHeight(0, 0) == m_usHeight &&
        pkOptDest->GetPixelFormat() == m_kFormat)
    {
        pkPixels = pkOptDest;
    }
    else
    {
        pkPixels = NiNew NiPixelData(m_usWidth, m_usHeight, m_kFormat);
    }
    if (m_bPalettized != 0)
    {
        NiPalette* pkPalette = NiNew NiPalette(m_bHasAlpha != 0, m_usNumPalette, m_pkPalette);
        pkPixels->SetPalette(pkPalette);
    }
    unsigned char* pucDst = pkPixels->GetPixels(0, 0);
    unsigned int uiWidth = pkPixels->GetWidth(0, 0);
    unsigned int uiPitch = uiWidth * pkPixels->GetPixelStride();
    if (uiPitch == 0)
    {
        uiPitch = pkPixels->GetWidth(0, 0);
        uiPitch = uiPitch >> 1;
    }
    if (m_bFlipVertical != 0)
    {
        pucDst = pucDst + (int)(uiPitch * (m_usHeight - 1));
        uiPitch = -(int)uiPitch;
    }
    for (unsigned int uiRow = 0; uiRow < m_usHeight; uiRow++)
    {
        m_pucRow = pInfo->m_ppRowPointers[uiRow];
        (this->*m_pfnConvert)(m_pucRow, pucDst);
        pucDst = pucDst + (int)uiPitch;
    }
    m_pucRow = 0;
    FUN_142708730(&pPng, &pInfo, 0);
    return pkPixels;
}

// @0x140d9bd80
void MS2PNGReader::Convert4(const unsigned char* pucSrc, unsigned char* pucDst)
{
    for (unsigned int ui = 0; ui < (unsigned int)(m_usWidth >> 1); ui++)
    {
        unsigned char c = pucSrc[0] - m_usIndexBias;
        pucSrc++;
        *pucDst = c;
        pucDst++;
    }
}

// @0x140d9be10
void MS2PNGReader::Convert8(const unsigned char* pucSrc, unsigned char* pucDst)
{
    for (unsigned int ui = 0; ui < m_usWidth; ui++)
    {
        unsigned char c = pucSrc[0] - m_usIndexBias;
        pucSrc++;
        *pucDst = c;
        pucDst++;
    }
}

// @0x140d9bea0
void MS2PNGReader::ConvertGray24(const unsigned char* pucSrc, unsigned char* pucDst)
{
    for (unsigned int ui = 0; ui < m_usWidth; ui++)
    {
        pucDst[2] = *pucSrc;
        pucDst[1] = pucDst[2];
        pucDst[0] = pucDst[1];
        pucDst += 3;
        pucSrc++;
    }
}

// @0x140d9bf70
void MS2PNGReader::Convert555(const unsigned char* pucSrc, unsigned char* pucDst)
{
    for (unsigned int ui = 0; ui < m_usWidth; ui++)
    {
        *pucDst++ = (pucSrc[1] & 0x7c) << 1;
        *pucDst++ = ((pucSrc[1] & 3) << 6) + ((pucSrc[0] & 0xe0) >> 2);
        *pucDst++ = (pucSrc[0] & 0x1f) << 3;
        pucSrc += 2;
    }
}

// @0x140d9c070
void MS2PNGReader::ConvertPal24(const unsigned char* pucSrc, unsigned char* pucDst)
{
    for (unsigned int ui = 0; ui < m_usWidth; ui++)
    {
        const unsigned char* pucEntry = (const unsigned char*)(m_pkPalette + (int)(((pucSrc[1] << 8) + pucSrc[0]) - m_usIndexBias));
        *pucDst++ = *pucEntry;
        *pucDst++ = *(pucEntry + 1);
        *pucDst++ = *(pucEntry + 2);
        pucSrc += 2;
    }
}

// @0x140d9c170
void MS2PNGReader::ConvertPal32(const unsigned char* pucSrc, unsigned char* pucDst)
{
    for (unsigned int ui = 0; ui < m_usWidth; ui++)
    {
        const unsigned char* pucEntry = (const unsigned char*)(m_pkPalette + (int)(((pucSrc[1] << 8) + pucSrc[0]) - m_usIndexBias));
        *pucDst++ = *pucEntry;
        *pucDst++ = *(pucEntry + 1);
        *pucDst++ = *(pucEntry + 2);
        *pucDst++ = *(pucEntry + 3);
        pucSrc += 2;
    }
}

// @0x140d9c290
void MS2PNGReader::ConvertBGR24(const unsigned char* pucSrc, unsigned char* pucDst)
{
    for (unsigned int ui = 0; ui < m_usWidth; ui++)
    {
        *pucDst++ = *(pucSrc + 2);
        *pucDst++ = *(pucSrc + 1);
        *pucDst++ = *pucSrc;
        pucSrc += 3;
    }
}

// @0x140d9c340
void MS2PNGReader::ConvertRGB32(const unsigned char* pucSrc, unsigned char* pucDst)
{
    for (unsigned int ui = 0; ui < m_usWidth; ui++)
    {
        *pucDst++ = *pucSrc;
        *pucDst++ = *(pucSrc + 1);
        *pucDst++ = *(pucSrc + 2);
        *pucDst++ = 0xff;
        pucSrc += 3;
    }
}

// @0x140d9c400
void MS2PNGReader::ConvertGray32(const unsigned char* pucSrc, unsigned char* pucDst)
{
    for (unsigned int ui = 0; ui < m_usWidth; ui++)
    {
        *pucDst++ = *pucSrc;
        *pucDst++ = *pucSrc;
        *pucDst++ = *pucSrc;
        *pucDst++ = 0xff;
        pucSrc++;
    }
}

// @0x140d9c4c0
void MS2PNGReader::ConvertRGBA32(const unsigned char* pucSrc, unsigned char* pucDst)
{
    for (unsigned int ui = 0; ui < m_usWidth; ui++)
    {
        *pucDst++ = *pucSrc;
        *pucDst++ = *(pucSrc + 1);
        *pucDst++ = *(pucSrc + 2);
        *pucDst++ = *(pucSrc + 3);
        pucSrc += 4;
    }
}

// MS2-FUNCTIONAL: not byte-matched (raw palette row reader, unreferenced)
// @0x140d9c590
void MS2PNGReader::ReadRawRow(efd::File& kIst)
{
    if (m_uiPaletteCapacity < m_usNumPalette)
    {
        m_uiPaletteCapacity = m_usNumPalette;
        NiDelete[] m_pkPalette;
        m_pkPalette = NiNew NiPalette::PaletteEntry[m_uiPaletteCapacity];
    }
    if (m_uiBufferSize < (unsigned int)m_usNumPalette << 2)
    {
        m_uiBufferSize = (unsigned int)m_usNumPalette << 2;
        NiFree(m_pucRow);
        m_pucRow = NiAlloc(unsigned char, m_uiBufferSize);
    }
    NiPalette::PaletteEntry* pkEntry = m_pkPalette;
    unsigned char ucBits = m_ucRawBits;
    if (ucBits == 8)
    {
        unsigned char* pucSrc = m_pucRow;
        NiStreamLoadBinary(kIst, m_pucRow, m_usNumPalette);
        for (unsigned int ui = 0; ui < m_usNumPalette; ui++)
        {
            pkEntry->m_ucBlue = *pucSrc;
            pkEntry->m_ucGreen = pkEntry->m_ucBlue;
            pkEntry->m_ucRed = pkEntry->m_ucGreen;
            pkEntry->m_ucAlpha = 0xff;
            pkEntry++;
            pucSrc++;
        }
    }
    else if (ucBits > 0xe)
    {
        if (ucBits < 0x11)
        {
            unsigned char* pucSrc = m_pucRow;
            NiStreamLoadBinary(kIst, m_pucRow, (unsigned int)m_usNumPalette << 1);
            for (unsigned int ui = 0; ui < m_usNumPalette; ui++)
            {
                pkEntry->m_ucRed = (pucSrc[1] & 0x7c) << 1;
                pkEntry->m_ucGreen = pucSrc[1] * 64 + ((pucSrc[0] & 0xe0) >> 2);
                pkEntry->m_ucBlue = pucSrc[0] << 3;
                pkEntry->m_ucAlpha = 0xff;
                pkEntry++;
                pucSrc += 2;
            }
        }
        else if (ucBits == 0x18)
        {
            unsigned char* pucSrc = m_pucRow;
            NiStreamLoadBinary(kIst, m_pucRow, m_usNumPalette * 3);
            for (unsigned int ui = 0; ui < m_usNumPalette; ui++)
            {
                pkEntry->m_ucBlue = pucSrc[0];
                pkEntry->m_ucGreen = pucSrc[1];
                pkEntry->m_ucRed = pucSrc[2];
                pucSrc += 3;
                pkEntry->m_ucAlpha = 0xff;
                pkEntry++;
            }
        }
        else if (ucBits == 0x20)
        {
            unsigned char* pucSrc = m_pucRow;
            NiStreamLoadBinary(kIst, m_pucRow, (unsigned int)m_usNumPalette << 2);
            for (unsigned int ui = 0; ui < m_usNumPalette; ui++)
            {
                pkEntry->m_ucBlue = pucSrc[0];
                pkEntry->m_ucGreen = pucSrc[1];
                pkEntry->m_ucRed = pucSrc[2];
                pkEntry->m_ucAlpha = pucSrc[3];
                pucSrc += 4;
                pkEntry++;
            }
        }
    }
}

// @0x140d9cb80
void ChunkTypeToString(unsigned int uiType, char* pcOut)
{
    pcOut[0] = (char)(uiType & 0xff);
    pcOut[1] = (char)((uiType & 0xff00) >> 8);
    pcOut[2] = (char)((uiType & 0xff0000) >> 16);
    pcOut[3] = (char)((uiType & 0xff000000) >> 24);
    pcOut[4] = 0;
}

// @0x140d9cc20
void PngError(Unk_PngStruct*, const char*)
{
}

// @0x140d9cc40
void PngWarning(Unk_PngStruct*, const char*)
{
}

// @0x140d9cc60
void PngRead(Unk_PngStruct* pPng, unsigned char* pucData, unsigned int uiBytes)
{
    void* pvStream = FUN_142706d40(pPng);
    efd::File* pkFile = (efd::File*)pvStream;
    pkFile->Read(pucData, uiBytes);
}
