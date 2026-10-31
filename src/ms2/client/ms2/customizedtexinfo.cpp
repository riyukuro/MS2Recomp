// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CCustomizedTexInfo (the dye parameters of one customised
// character texture: base / decal texture handles, three tint colours, four params) and the CCustomizedTextureManager
// routine that composes two infos into a new RGBA texture ("CustomizingCache%d.dds"), with the colour / pixel helpers.
// The class layout is shared with charactermeshmerger.cpp (which only creates and fills the infos).
// MS2-UNIT: ?\customizedtexinfo.cpp
// MS2-RANGE: 0x141165f00-0x1411673f0 .text$mn
// MS2-PIN: ??0Unk_CtiTexPtr@@QEAA@PEAX@Z 0x14097ed60
// MS2-PIN: ??1Unk_CtiTexPtr@@QEAA@XZ 0x14097f4a0
// MS2-PIN: ??0Unk_CtiPixPtr@@QEAA@PEAX@Z 0x140a5a500
// MS2-PIN: ??1Unk_CtiPixPtr@@QEAA@XZ 0x140a5a900
// MS2-PIN: ?get@Unk_CtiPixPtr@@QEBAPEAXXZ 0x140a5ac70
// MS2-PIN: ??0Unk_CtiFmtPrefs@@QEAA@XZ 0x140984420
// MS2-PIN: ??0Unk_CtiPixelData@@QEAA@IIAEBUUnk_CtiPixFmt@@II@Z 0x141d31950
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
#include <stdlib.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local types (names invented) ----

struct Unk_CtiColor                                             // 4 floats (r, g, b, a)
{
    float r, g, b, a;
    Unk_CtiColor();                                             // 0x14097f220
    Unk_CtiColor(float fR, float fG, float fB, float fA);       // 0x14097f1d0
    Unk_CtiColor operator*(float fScale) const;                 // 0x141166d50
    Unk_CtiColor operator-(const Unk_CtiColor& kRhs);           // 0x141166e20
    Unk_CtiColor operator+(const Unk_CtiColor& kRhs);           // 0x141166ec0
    Unk_CtiColor& operator+=(const Unk_CtiColor& kRhs);         // 0x141166f60
    explicit Unk_CtiColor(const Unk_CtiColor* pSrc);            // 0x140987930 NiColorA(const efd::ColorA&): this = rcx, source = rdx
};
MS2_CHECK_SIZE(Unk_CtiColor, 0x10);

struct Unk_CtiPixel { unsigned char r, g, b, a; };              // one RGBA8 pixel
struct Unk_CtiUV                                                // NiPoint2-like: its user ctor (0x140a0a600) makes the
{                                                               // return go through a hidden pointer (0x140a0a4c0 rcx)
    Unk_CtiUV(float fU, float fV) : u(fU), v(fV) {}
    float u, v;
};
struct Unk_CtiTexPtr                                            // texture handle (assign 0x14097f9b0)
{
    Unk_CtiTexPtr(void* pRaw);                                  // 0x14097ed60
    ~Unk_CtiTexPtr();                                           // 0x14097f4a0
    void* m_p;
};

struct Unk_CtiPixPtr                                            // resampled pixel data handle (efd::SmartPointer<NiPixelData>)
{
    Unk_CtiPixPtr(void* pRaw);                                  // 0x140a5a500
    ~Unk_CtiPixPtr();                                           // 0x140a5a900
    void* get() const;                                          // 0x140a5ac70
    void* m_p;
};

struct Unk_CtiPixFmt;                                           // NiPixelFormat
struct Unk_CtiPixelData : public efd::MemObject                 // NiPixelData
{
    Unk_CtiPixelData(unsigned w, unsigned h, const Unk_CtiPixFmt& kFmt, unsigned nMips, unsigned nFaces);  // 0x141d31950
    unsigned char m_abData[0x90];                               // opaque
};
MS2_CHECK_SIZE(Unk_CtiPixelData, 0x90);

struct Unk_CtiFmtPrefs                                          // NiTexture::FormatPrefs
{
    Unk_CtiFmtPrefs();                                          // 0x140984420
    int m_ePixelLayout;
    int m_eAlphaFmt;
    int m_eMipMapped;
};

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

    Unk_CtiTexPtr m_spBase;                                     // +0x10
    Unk_CtiTexPtr m_spDecal;                                    // +0x18
    Unk_CtiColor m_akColor[3];                                  // +0x20
    float m_fParam0, m_fParam1, m_fParam2, m_fParam3;           // +0x50
};
MS2_CHECK_SIZE(CCustomizedTexInfo, 0x60);

class CCustomizedTextureManager { public: char m_pad_00[8]; };

// ---- exe callees ----
void FUN_14097f9b0(Unk_CtiTexPtr* p, void* pRaw);
void* FUN_14097fbf0(Unk_CtiTexPtr* p);                          // handle -> texture
void* FUN_140a5ac70(void* p);
Unk_CtiTexture* FUN_140a5acb0(Unk_CtiTexPtr* p);
class NiObject   // C3: member view for the former free stand-ins
{
public:
    static class NiObject* DynamicCast(class NiRTTI const*, class NiObject const*);
};
extern char DAT_143afa930[];
extern char DAT_1439fb040[];
void* FUN_140876480(void* out, int cat);
void* FUN_14208a860(unsigned __int64 size, unsigned cat);
class NiPixelData* ConvertToRGBA32(class NiPixelData*, unsigned int, unsigned int);   // C3: was FUN_14184d8c0
void FUN_14184dad0(void* pSampler, Unk_CtiUV kUV, Unk_CtiPixel* pOut, bool b);
class NiPixelData   // C3: member view for the former free stand-ins
{
public:
    unsigned int GetPixelStride() const;
    unsigned char* GetPixels(unsigned int, unsigned int);
};
Unk_CtiUV FUN_140a0a4c0(float fU, float fV);
void* FUN_141d33320(void* pPix, Unk_CtiFmtPrefs& kPrefs, bool b);
void FUN_140a34190(void* pDst, const void* pSrc, int nBytes);
void FUN_141047040(Unk_CtiPixel* p, unsigned char a, unsigned char b, unsigned char c, unsigned char d);
unsigned char* FUN_141048fc0(Unk_CtiPixel* p);
unsigned char* FUN_141048fb0(Unk_CtiPixel* p);
unsigned char* FUN_141048bc0(Unk_CtiPixel* p);
unsigned char* FUN_141048b80(Unk_CtiPixel* p);
void FUN_14015b310(void* p, unsigned __int64 sz);

void* FUN_141166c80(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB);
void* FUN_141166110(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB);
void FUN_141167050(Unk_CtiColor* pColor);
void FUN_1411670f0(Unk_CtiColor* pColor, Unk_CtiPixel* pPix);
void FUN_1411671b0(Unk_CtiPixel* pPix, unsigned* pOut);
void FUN_1411671d0(Unk_CtiPixel* pPix, Unk_CtiColor* pOut);
Unk_CtiPixel* FUN_141166d20(Unk_CtiPixel* pPix);
Unk_CtiColor FUN_141166de0(float fScale, const Unk_CtiColor& kColor);
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
        m_akColor[i] = Unk_CtiColor(0.0f, 0.0f, 0.0f, 0.0f);
}

// @0x141166020
CCustomizedTexInfo::~CCustomizedTexInfo()
{
    FUN_14097f9b0(&m_spBase, 0);
    FUN_14097f9b0(&m_spDecal, 0);
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
    Unk_CtiTexture* pBaseA = (Unk_CtiTexture*)((void*)NiObject::DynamicCast((class NiRTTI const*)(DAT_143afa930), (class NiObject const*)(FUN_14097fbf0(&pA->m_spBase))));
    if (pBaseA == 0)
        return pResult;

    Unk_CtiTexture* pDecalA = (Unk_CtiTexture*)((void*)NiObject::DynamicCast((class NiRTTI const*)(DAT_143afa930), (class NiObject const*)(FUN_14097fbf0(&pA->m_spDecal))));
    Unk_CtiTexture* pBaseB = (Unk_CtiTexture*)((void*)NiObject::DynamicCast((class NiRTTI const*)(DAT_143afa930), (class NiObject const*)(FUN_14097fbf0(&pB->m_spBase))));
    Unk_CtiTexture* pDecalB = (Unk_CtiTexture*)((void*)NiObject::DynamicCast((class NiRTTI const*)(DAT_143afa930), (class NiObject const*)(FUN_14097fbf0(&pB->m_spDecal))));
    unsigned nWidth = FUN_140a5acb0(&pA->m_spBase)->vfunc_18();
    unsigned nHeight = FUN_140a5acb0(&pA->m_spBase)->vfunc_19();
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

    Unk_CtiPixPtr hBaseA(pBaseA ? ((void*)ConvertToRGBA32((class NiPixelData*)(FUN_141167270(pBaseA)), nWidth, nHeight)) : 0);
    Unk_CtiPixPtr hDecalA(pDecalA ? ((void*)ConvertToRGBA32((class NiPixelData*)(FUN_141167270(pDecalA)), nWidth, nHeight)) : 0);
    Unk_CtiPixPtr hBaseB(pBaseB ? ((void*)ConvertToRGBA32((class NiPixelData*)(FUN_141167270(pBaseB)), nWidth, nHeight)) : 0);
    Unk_CtiPixPtr hDecalB(pDecalB ? ((void*)ConvertToRGBA32((class NiPixelData*)(FUN_141167270(pDecalB)), nWidth, nHeight)) : 0);

    Unk_CtiPixelData* pPix = EE_NEW Unk_CtiPixelData(nWidth, nHeight, *(const Unk_CtiPixFmt*)DAT_1439fb040, 1, 1);
    unsigned nStride = ((class NiPixelData*)(void*)(pPix))->GetPixelStride();
    char* pDst = ((char*)((class NiPixelData*)(void*)(pPix))->GetPixels(0, 0));
    for (unsigned y = 0; y < nHeight; ++y)
    {
        for (unsigned x = 0; x < nWidth; ++x)
        {
            Unk_CtiUV kUV = FUN_140a0a4c0(((float)x + 0.5f) / (float)nWidth, ((float)y + 0.5f) / (float)nHeight);
            Unk_CtiColor kColor;
            Unk_CtiPixel kPix;
            FUN_141166d20(&kPix);
            Unk_CtiColor kBase;
            FUN_14184dad0(hBaseA.get(), kUV, &kPix, true);
            FUN_1411671d0(&kPix, &kBase);
            if (hDecalA.get() != 0)
            {
                Unk_CtiColor kMask;
                FUN_14184dad0(hDecalA.get(), kUV, &kPix, true);
                FUN_1411671d0(&kPix, &kMask);
                Unk_CtiColor kTint(&static_cast<const Unk_CtiColor&>(FUN_141166de0(kMask.r, pA->m_akColor[0]) + FUN_141166de0(kMask.g, pA->m_akColor[1])
                    + FUN_141166de0(1.0f - kMask.r, pA->m_akColor[2])));
                Unk_CtiColor kMix(&static_cast<const Unk_CtiColor&>(kBase + FUN_141166de0(kMask.a, kTint - kBase)));
                kColor = kMix;
                kColor.a = 1.0f;
            }
            else
            {
                kColor = kBase;
            }
            if (hBaseB.get() != 0)
            {
                Unk_CtiColor kBase2;
                FUN_14184dad0(hBaseB.get(), kUV, &kPix, true);
                FUN_1411671d0(&kPix, &kBase2);
                if (hDecalB.get() != 0)
                {
                    Unk_CtiColor kMask2;
                    FUN_14184dad0(hDecalB.get(), kUV, &kPix, true);
                    FUN_1411671d0(&kPix, &kMask2);
                    Unk_CtiColor kTint2(&static_cast<const Unk_CtiColor&>(FUN_141166de0(kMask2.r, pB->m_akColor[0]) + FUN_141166de0(kMask2.g, pB->m_akColor[1])
                        + FUN_141166de0(1.0f - kMask2.r, pB->m_akColor[2])));
                    Unk_CtiColor kMix2(&static_cast<const Unk_CtiColor&>(kBase2 + FUN_141166de0(kMask2.a, kTint2 - kBase2)));
                    kColor = kMix2;
                    kColor.a = 1.0f;
                }
                else
                {
                    kColor += kBase2;
                }
            }
            kColor.r = kColor.r * 0.5019608f;
            kColor.g = kColor.g * 0.5019608f;
            kColor.b = kColor.b * 0.5019608f;
            FUN_141167050(&kColor);
            FUN_1411670f0(&kColor, &kPix);
            unsigned nPacked;
            FUN_1411671b0(&kPix, &nPacked);
            FUN_140a34190(pDst, &nPacked, 4);
            pDst = pDst + nStride;
        }
    }
    Unk_CtiFmtPrefs kPrefs;
    kPrefs.m_ePixelLayout = 2;
    kPrefs.m_eMipMapped = 0;
    FUN_14097f9b0(&pResult->m_spBase, FUN_141d33320(pPix, kPrefs, true));
    return pResult;
}

// @0x141166c80
void* FUN_141166c80(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB)
{
    return 0;
}

// the exe's is a member (this unused, hidden return slot in rdx); a free function put the slot in rcx
struct Unk_CtiCacheName { CString FUN_141166ca0(CCustomizedTexInfo* pA, CCustomizedTexInfo* pB); };   // both infos unused

// @0x141166ca0
CString Unk_CtiCacheName::FUN_141166ca0(CCustomizedTexInfo* pA, CCustomizedTexInfo* pB)
{
    CString strName;
    strName.Format("CustomizingCache%d.dds", rand());
    return strName;
}

// @0x141166d20
Unk_CtiPixel* FUN_141166d20(Unk_CtiPixel* pPix)
{
    FUN_141047040(pPix, 0, 0, 0, 0);
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
Unk_CtiColor FUN_141166de0(float fScale, const Unk_CtiColor& kColor)
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
void FUN_141167050(Unk_CtiColor* pColor)
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
void FUN_1411670f0(Unk_CtiColor* pColor, Unk_CtiPixel* pPix)
{
    unsigned char r = (unsigned char)(pColor->r * 255.0f);
    *FUN_141048fc0(pPix) = r;
    unsigned char g = (unsigned char)(pColor->g * 255.0f);
    *FUN_141048fb0(pPix) = g;
    unsigned char b = (unsigned char)(pColor->b * 255.0f);
    *FUN_141048bc0(pPix) = b;
    unsigned char a = (unsigned char)(pColor->a * 255.0f);
    *FUN_141048b80(pPix) = a;
}

// @0x1411671b0
void FUN_1411671b0(Unk_CtiPixel* pPix, unsigned* pOut)
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
void FUN_1411671d0(Unk_CtiPixel* pPix, Unk_CtiColor* pOut)
{
    pOut->r = (float)*FUN_1411672c0(pPix) / 255.0f;
    pOut->g = (float)*FUN_1411672b0(pPix) / 255.0f;
    pOut->b = (float)*FUN_1411672a0(pPix) / 255.0f;
    pOut->a = (float)*FUN_141167290(pPix) / 255.0f;
}

// @0x141167270
void* FUN_141167270(void* pTex)
{
    return FUN_140a5ac70((char*)pTex + 0x70);
}

// The UCRT's `static __inline memmove_s` of this TU (unreferenced copy).
// @0x1411672d0
MS2_EMIT_CRT_MEMMOVE_S();
