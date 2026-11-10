// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CCustomizedTexInfo (the dye parameters of one customised
// character texture: base / decal texture handles, three tint colours, four params) and the CCustomizedTextureManager
// routine that composes two infos into a new RGBA texture ("CustomizingCache%d.dds"), with the colour / pixel helpers.
// The class layout is shared with charactermeshmerger.cpp (which only creates and fills the infos).
// MS2-UNIT: ?\customizedtexinfo.cpp
// MS2-RANGE: 0x141165f00-0x1411673f0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\customizedtexinfo.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2layout.h"
#include <vector>
#include <map>
#include <set>
#include <atlcoll.h>
#include <efd/StdContainers.h>
#include <efd/SmartPointer.h>
#include <NiRefObject.h>
#include <NiSourceTexture.h>
#include <NiPixelData.h>
#include <NiPoint2.h>
#include <efd/Color.h>
#include <NiColor.h>
#include <stdlib.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local types (names invented) ----

// The colours are NiColorA (ctors 0x14097f220 / 0x14097f1d0 / 0x140987930). This ctor-less view carries the
// unit's own colour operators and helpers, which take and return the 4 floats; CTI() views a NiColorA as one.
struct Unk_CtiColor                                             // 4 floats (r, g, b, a)
{
    float r, g, b, a;
    // Never called (no symbol is referenced). A user-declared ctor keeps the view out of /GS's POD-buffer
    // heuristic, which put a cookie into the by-value operators when it was ctor-less.
    Unk_CtiColor();
    Unk_CtiColor operator*(float fScale) const;                 // 0x141166d50
    Unk_CtiColor operator-(const Unk_CtiColor& kRhs);           // 0x141166e20
    Unk_CtiColor operator+(const Unk_CtiColor& kRhs);           // 0x141166ec0
    Unk_CtiColor& operator+=(const Unk_CtiColor& kRhs);         // 0x141166f60
};
MS2_CHECK_SIZE(Unk_CtiColor, 0x10);
#define CTI(x) reinterpret_cast<Unk_CtiColor&>(x)
#define CTI_SRC(x) (*reinterpret_cast<const efd::ColorA*>(&static_cast<const Unk_CtiColor&>(x)))

struct Unk_CtiPixel { unsigned char r, g, b, a; };              // one RGBA8 pixel

class Unk_CtiTexture                                            // a loaded texture
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17();
    virtual unsigned vfunc_18();                                // width
    virtual unsigned vfunc_19();                                // height
    virtual void vfunc_20();                                    // make resident
};

class CCustomizedTexInfo : public NiRefObject
{
public:
    CCustomizedTexInfo();                                       // 0x141165f00
    virtual ~CCustomizedTexInfo();                              // 0x141166020 (??_G 0x141166ff0)

    efd::SmartPointer<NiTexture> m_spBase;                      // +0x10 (ctor 0x14097ed60, dtor 0x14097f4a0, assign 0x14097f9b0)
    efd::SmartPointer<NiTexture> m_spDecal;                     // +0x18
    NiColorA m_akColor[3];                                      // +0x20
    float m_fParam0, m_fParam1, m_fParam2, m_fParam3;           // +0x50
};
MS2_CHECK_SIZE(CCustomizedTexInfo, 0x60);

class CCustomizedTextureManager { public: char m_pad_00[8]; };

// ---- exe callees ----
extern const NiPixelFormat DAT_1439fb040;
void* FUN_140876480(void* out, int cat);
void* FUN_14208a860(unsigned __int64 size, unsigned cat);
class NiPixelData* ConvertToRGBA32(class NiPixelData*, unsigned int, unsigned int);   // C3: was FUN_14184d8c0
struct Unk_TexColor;
int SamplePixelData(NiPixelData* pkPixels, NiPoint2 kUV, Unk_TexColor* pkOut, bool bBilinear);   // textureutil.cpp

void* FUN_141166c80(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB);
void* FUN_141166110(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB);
void ClampColor(Unk_CtiColor* pColor);
void ColorToPixel(Unk_CtiColor* pColor, Unk_CtiPixel* pPix);
void GetPixelPacked(Unk_CtiPixel* pPix, unsigned* pOut);
void PixelToColor(Unk_CtiPixel* pPix, Unk_CtiColor* pOut);
Unk_CtiPixel* FUN_141166d20(Unk_CtiPixel* pPix);
Unk_CtiColor ScaleColor(float fScale, const Unk_CtiColor& kColor);
void* FUN_141167270(void* pTex);

// @0x141165f00
CCustomizedTexInfo::CCustomizedTexInfo()
    : m_spBase(0), m_spDecal(0)
{
    m_fParam0 = 0.0f;
    m_fParam1 = 0.0f;
    m_fParam2 = 0.0f;
    m_fParam3 = 1.0f;
    for (int i = 0; i < 3; ++i)
        m_akColor[i] = NiColorA(0.0f, 0.0f, 0.0f, 0.0f);
}

// @0x141166020
CCustomizedTexInfo::~CCustomizedTexInfo()
{
    m_spBase = (NiTexture*)0;
    m_spDecal = (NiTexture*)0;
}

// @0x1411660b0
void* FUN_1411660b0(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB)
{
    void* pResult = FUN_141166c80(pMgr, pA, pB);
    if (pResult != 0)
        return pResult;
    return FUN_141166110(pMgr, pA, pB);
}

// @0x141166110
void* FUN_141166110(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB)
{
    CCustomizedTexInfo* pResult = EE_NEW CCustomizedTexInfo;
    Unk_CtiTexture* pBaseA = (Unk_CtiTexture*)((void*)NiObject::DynamicCast((class NiRTTI const*)(&NiSourceTexture::ms_RTTI), (class NiObject const*)(pA->m_spBase.operator NiTexture*())));
    if (pBaseA == 0)
        return pResult;

    Unk_CtiTexture* pDecalA = (Unk_CtiTexture*)((void*)NiObject::DynamicCast((class NiRTTI const*)(&NiSourceTexture::ms_RTTI), (class NiObject const*)(pA->m_spDecal.operator NiTexture*())));
    Unk_CtiTexture* pBaseB = (Unk_CtiTexture*)((void*)NiObject::DynamicCast((class NiRTTI const*)(&NiSourceTexture::ms_RTTI), (class NiObject const*)(pB->m_spBase.operator NiTexture*())));
    Unk_CtiTexture* pDecalB = (Unk_CtiTexture*)((void*)NiObject::DynamicCast((class NiRTTI const*)(&NiSourceTexture::ms_RTTI), (class NiObject const*)(pB->m_spDecal.operator NiTexture*())));
    unsigned nWidth = ((Unk_CtiTexture*)pA->m_spBase.operator->())->vfunc_18();
    unsigned nHeight = ((Unk_CtiTexture*)pA->m_spBase.operator->())->vfunc_19();
    if (FUN_141167270(pBaseA) == 0)
        pBaseA->vfunc_20();
    if (pDecalA)
    {
        unsigned nW2 = pDecalA->vfunc_18();
        unsigned nH2 = pDecalA->vfunc_19();
        nWidth = nW2 > nWidth ? nW2 : nWidth;
        nHeight = nH2 > nHeight ? nH2 : nHeight;
        if (FUN_141167270(pDecalA) == 0)
            pDecalA->vfunc_20();
    }
    if (pBaseB && FUN_141167270(pBaseB) == 0)
        pBaseB->vfunc_20();
    if (pDecalB && FUN_141167270(pDecalB) == 0)
        pDecalB->vfunc_20();

    NiPixelDataPtr hBaseA(pBaseA ? ConvertToRGBA32((class NiPixelData*)(FUN_141167270(pBaseA)), nWidth, nHeight) : 0);
    NiPixelDataPtr hDecalA(pDecalA ? ConvertToRGBA32((class NiPixelData*)(FUN_141167270(pDecalA)), nWidth, nHeight) : 0);
    NiPixelDataPtr hBaseB(pBaseB ? ConvertToRGBA32((class NiPixelData*)(FUN_141167270(pBaseB)), nWidth, nHeight) : 0);
    NiPixelDataPtr hDecalB(pDecalB ? ConvertToRGBA32((class NiPixelData*)(FUN_141167270(pDecalB)), nWidth, nHeight) : 0);

    NiPixelData* pPix = EE_NEW NiPixelData(nWidth, nHeight, DAT_1439fb040, 1, 1);
    unsigned nStride = pPix->GetPixelStride();
    char* pDst = ((char*)pPix->GetPixels(0, 0));
    for (unsigned y = 0; y < nHeight; ++y)
    {
        for (unsigned x = 0; x < nWidth; ++x)
        {
            NiPoint2 kUV(((float)x + 0.5f) / (float)nWidth, ((float)y + 0.5f) / (float)nHeight);
            NiColorA kColor;
            Unk_CtiPixel kPix;
            FUN_141166d20(&kPix);
            NiColorA kBase;
            SamplePixelData(hBaseA, kUV, (Unk_TexColor*)&kPix, true);
            PixelToColor(&kPix, &CTI(kBase));
            if ((NiPixelData*)hDecalA != 0)
            {
                NiColorA kMask;
                SamplePixelData(hDecalA, kUV, (Unk_TexColor*)&kPix, true);
                PixelToColor(&kPix, &CTI(kMask));
                NiColorA kTint(CTI_SRC(ScaleColor(kMask.r, CTI(pA->m_akColor[0])) + ScaleColor(kMask.g, CTI(pA->m_akColor[1]))
                    + ScaleColor(1.0f - kMask.r, CTI(pA->m_akColor[2]))));
                NiColorA kMix(CTI_SRC(CTI(kBase) + ScaleColor(kMask.a, CTI(kTint) - CTI(kBase))));
                kColor = kMix;
                kColor.a = 1.0f;
            }
            else
            {
                kColor = kBase;
            }
            if ((NiPixelData*)hBaseB != 0)
            {
                NiColorA kBase2;
                SamplePixelData(hBaseB, kUV, (Unk_TexColor*)&kPix, true);
                PixelToColor(&kPix, &CTI(kBase2));
                if ((NiPixelData*)hDecalB != 0)
                {
                    NiColorA kMask2;
                    SamplePixelData(hDecalB, kUV, (Unk_TexColor*)&kPix, true);
                    PixelToColor(&kPix, &CTI(kMask2));
                    NiColorA kTint2(CTI_SRC(ScaleColor(kMask2.r, CTI(pB->m_akColor[0])) + ScaleColor(kMask2.g, CTI(pB->m_akColor[1]))
                        + ScaleColor(1.0f - kMask2.r, CTI(pB->m_akColor[2]))));
                    NiColorA kMix2(CTI_SRC(CTI(kBase2) + ScaleColor(kMask2.a, CTI(kTint2) - CTI(kBase2))));
                    kColor = kMix2;
                    kColor.a = 1.0f;
                }
                else
                {
                    CTI(kColor) += CTI(kBase2);
                }
            }
            kColor.r = kColor.r * 0.5019608f;
            kColor.g = kColor.g * 0.5019608f;
            kColor.b = kColor.b * 0.5019608f;
            ClampColor(&CTI(kColor));
            ColorToPixel(&CTI(kColor), &kPix);
            unsigned nPacked;
            GetPixelPacked(&kPix, &nPacked);
            efd::Memcpy(pDst, &nPacked, 4);
            pDst = pDst + nStride;
        }
    }
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = (NiTexture::FormatPrefs::PixelLayout)2;
    kPrefs.m_eMipMapped = (NiTexture::FormatPrefs::MipFlag)0;
    pResult->m_spBase = NiSourceTexture::Create(pPix, kPrefs, true);
    return pResult;
}

// @0x141166c80
void* FUN_141166c80(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB)
{
    return 0;
}

// the exe's is a member (this unused, hidden return slot in rdx); a free function put the slot in rcx
struct Unk_CtiCacheName { CString MakeCacheFileName(CCustomizedTexInfo* pA, CCustomizedTexInfo* pB); };   // both infos unused

// @0x141166ca0
CString Unk_CtiCacheName::MakeCacheFileName(CCustomizedTexInfo* pA, CCustomizedTexInfo* pB)
{
    CString strName;
    strName.Format("CustomizingCache%d.dds", rand());
    return strName;
}

// @0x141166d20
Unk_CtiPixel* FUN_141166d20(Unk_CtiPixel* pPix)
{
    reinterpret_cast<efd::ColorA_UInt8*>(pPix)->ColorA_UInt8::ColorA_UInt8(0, 0, 0, 0);   // C3: 0x141047040
    return pPix;
}

// @0x141166d50
Unk_CtiColor Unk_CtiColor::operator*(float fScale) const
{
    Unk_CtiColor kRes = *this;
    kRes.r = kRes.r * fScale;
    kRes.g = kRes.g * fScale;
    kRes.b = kRes.b * fScale;
    kRes.a = kRes.a * fScale;
    return kRes;
}

// @0x141166de0
Unk_CtiColor ScaleColor(float fScale, const Unk_CtiColor& kColor)
{
    return kColor * fScale;
}

// @0x141166e20
Unk_CtiColor Unk_CtiColor::operator-(const Unk_CtiColor& kRhs)
{
    Unk_CtiColor kRes = *this;
    kRes.r = kRes.r - kRhs.r;
    kRes.g = kRes.g - kRhs.g;
    kRes.b = kRes.b - kRhs.b;
    kRes.a = kRes.a - kRhs.a;
    return kRes;
}

// @0x141166ec0
Unk_CtiColor Unk_CtiColor::operator+(const Unk_CtiColor& kRhs)
{
    Unk_CtiColor kRes = *this;
    kRes.r = kRes.r + kRhs.r;
    kRes.g = kRes.g + kRhs.g;
    kRes.b = kRes.b + kRhs.b;
    kRes.a = kRes.a + kRhs.a;
    return kRes;
}

// @0x141166f60
Unk_CtiColor& Unk_CtiColor::operator+=(const Unk_CtiColor& kRhs)
{
    r = r + kRhs.r;
    g = g + kRhs.g;
    b = b + kRhs.b;
    a = a + kRhs.a;
    return *this;
}

// @0x141167050
void ClampColor(Unk_CtiColor* pColor)
{
    if (1.0f < pColor->r)
        pColor->r = 1.0f;
    if (1.0f < pColor->g)
        pColor->g = 1.0f;
    if (1.0f < pColor->b)
        pColor->b = 1.0f;
    if (1.0f < pColor->a)
        pColor->a = 1.0f;
}

// @0x1411670f0
void ColorToPixel(Unk_CtiColor* pColor, Unk_CtiPixel* pPix)
{
    unsigned char r = (unsigned char)(pColor->r * 255.0f);
    reinterpret_cast<efd::ColorA_UInt8*>(pPix)->r() = r;
    unsigned char g = (unsigned char)(pColor->g * 255.0f);
    reinterpret_cast<efd::ColorA_UInt8*>(pPix)->g() = g;
    unsigned char b = (unsigned char)(pColor->b * 255.0f);
    reinterpret_cast<efd::ColorA_UInt8*>(pPix)->b() = b;
    unsigned char a = (unsigned char)(pColor->a * 255.0f);
    reinterpret_cast<efd::ColorA_UInt8*>(pPix)->a() = a;
}

// @0x1411671b0
void GetPixelPacked(Unk_CtiPixel* pPix, unsigned* pOut)
{
    *pOut = *(unsigned*)pPix;
}

// @0x1411672c0
unsigned char* FUN_1411672c0(Unk_CtiPixel* pPix) { return (unsigned char*)pPix; }
// @0x1411672b0
unsigned char* FUN_1411672b0(Unk_CtiPixel* pPix) { return (unsigned char*)pPix + 1; }
// @0x1411672a0
unsigned char* FUN_1411672a0(Unk_CtiPixel* pPix) { return (unsigned char*)pPix + 2; }
// @0x141167290
unsigned char* FUN_141167290(Unk_CtiPixel* pPix) { return (unsigned char*)pPix + 3; }

// @0x1411671d0
void PixelToColor(Unk_CtiPixel* pPix, Unk_CtiColor* pOut)
{
    pOut->r = (float)*FUN_1411672c0(pPix) / 255.0f;
    pOut->g = (float)*FUN_1411672b0(pPix) / 255.0f;
    pOut->b = (float)*FUN_1411672a0(pPix) / 255.0f;
    pOut->a = (float)*FUN_141167290(pPix) / 255.0f;
}

// @0x141167270
void* FUN_141167270(void* pTex)
{
    return reinterpret_cast<const efd::SmartPointer<NiPixelData>*>((char*)pTex + 0x70)->operator NiPixelData*();
}

// The UCRT's `static __inline memmove_s` of this TU (unreferenced copy).
// @0x1411672d0
MS2_EMIT_CRT_MEMMOVE_S();
