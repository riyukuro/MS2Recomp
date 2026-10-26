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
#include <stdlib.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local types (names invented) ----

struct Unk_CtiColor                                             // 4 floats (r, g, b, a)
{
    float r, g, b, a;
    Unk_CtiColor();                                             // 0x14097f220
    Unk_CtiColor(float fR, float fG, float fB, float fA);       // 0x14097f1d0
    Unk_CtiColor operator*(float fScale);                       // 0x141166d50
    Unk_CtiColor operator-(const Unk_CtiColor& kRhs);           // 0x141166e20
    Unk_CtiColor operator+(const Unk_CtiColor& kRhs);           // 0x141166ec0
    Unk_CtiColor& operator+=(const Unk_CtiColor& kRhs);         // 0x141166f60
    explicit Unk_CtiColor(const Unk_CtiColor* pSrc);            // 0x140987930 NiColorA(const efd::ColorA&): this = rcx, source = rdx
};
MS2_CHECK_SIZE(Unk_CtiColor, 0x10);

struct Unk_CtiPixel { unsigned char r, g, b, a; };              // one RGBA8 pixel
struct Unk_CtiUV { float u, v; };
struct Unk_CtiTexPtr { void* m_p; };                            // texture handle (ctor 0x14097ed60, assign 0x14097f9b0, release 0x14097f4a0)

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
    float m_afParams[4];                                        // +0x50
};
MS2_CHECK_SIZE(CCustomizedTexInfo, 0x60);

class CCustomizedTextureManager { public: char m_pad_00[8]; };

// ---- exe callees ----
void FUN_14097ed60(Unk_CtiTexPtr* p, void* pRaw);
void FUN_14097f9b0(Unk_CtiTexPtr* p, void* pRaw);
void FUN_14097f4a0(Unk_CtiTexPtr* p);
void* FUN_14097fbf0(Unk_CtiTexPtr* p);                          // handle -> texture
void* FUN_140a5ac70(void* p);
void FUN_140a5a500(void* pOut, void* pRaw);
void FUN_140a5a900(void* p);
Unk_CtiTexture* FUN_140a5acb0(Unk_CtiTexPtr* p);
void* FUN_14098d8d0(void* pRTTI, void* pObject);
extern char DAT_143afa930[];
extern char DAT_1439fb040[];
void* FUN_140876480(void* out, int cat);
void* FUN_14208a860(unsigned __int64 size, unsigned cat);
void* FUN_14184d8c0(void* pTex, unsigned w, unsigned h);
void FUN_14184dad0(void* pSampler, Unk_CtiUV kUV, Unk_CtiPixel* pOut, int n);
void* FUN_141d31950(void* mem, unsigned w, unsigned h, void* pFmt, int a, int b);
unsigned FUN_140d9d2a0(void* pPix);
char* FUN_140d9d2c0(void* pPix, int a, int b);
Unk_CtiUV FUN_140a0a4c0(float fU, float fV);
void FUN_140984420(int* p);
void* FUN_141d33320(void* pPix, int* pArgs, int n);
void FUN_140a34190(void* pDst, const void* pSrc, int nBytes);
void FUN_141047040(Unk_CtiPixel* p, int a, int b, int c, int d);
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
Unk_CtiColor FUN_141166de0(float fScale, Unk_CtiColor kColor);
void* FUN_141167270(void* pTex);

// @0x141165f00
// MS2-FUNCTIONAL: the exe's EH frame carries more unwind states (array-ctor guard) and the colour copies differ
CCustomizedTexInfo::CCustomizedTexInfo()
{
    FUN_14097ed60(&m_spBase, 0);
    FUN_14097ed60(&m_spDecal, 0);
    m_afParams[0] = 0.0f;
    m_afParams[1] = 0.0f;
    m_afParams[2] = 0.0f;
    m_afParams[3] = 1.0f;
    for (int i = 0; i < 3; ++i)
        m_akColor[i] = Unk_CtiColor(0.0f, 0.0f, 0.0f, 0.0f);
}

// @0x141166020
CCustomizedTexInfo::~CCustomizedTexInfo()
{
    FUN_14097f9b0(&m_spBase, 0);
    FUN_14097f9b0(&m_spDecal, 0);
    FUN_14097f4a0(&m_spDecal);
    FUN_14097f4a0(&m_spBase);
}

// @0x1411660b0
// MS2-FUNCTIONAL: the exe branches on the lookup result with a different jump shape (3 bytes shorter)
void* FUN_1411660b0(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB)
{
    void* pResult = FUN_141166c80(pMgr, pA, pB);
    if (pResult == 0)
        pResult = FUN_141166110(pMgr, pA, pB);
    return pResult;
}

// @0x141166110
// MS2-FUNCTIONAL: unrecovered Ni sampler / pixel helpers of unknown types; temp-slot and frame layout differ over the 3 KB body
void* FUN_141166110(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB)
{
    int nCatTmp;
    int* pCat = (int*)FUN_140876480(&nCatTmp, 0);
    void* pMem = FUN_14208a860(0x60, *pCat);
    CCustomizedTexInfo* pResult = 0;
    if (pMem)
        pResult = new (pMem) CCustomizedTexInfo;
    Unk_CtiTexture* pBaseA = (Unk_CtiTexture*)FUN_14098d8d0(DAT_143afa930, FUN_14097fbf0(&pA->m_spBase));
    if (pBaseA == 0)
        return pResult;

    Unk_CtiTexture* pDecalA = (Unk_CtiTexture*)FUN_14098d8d0(DAT_143afa930, FUN_14097fbf0(&pA->m_spDecal));
    Unk_CtiTexture* pBaseB = (Unk_CtiTexture*)FUN_14098d8d0(DAT_143afa930, FUN_14097fbf0(&pB->m_spBase));
    Unk_CtiTexture* pDecalB = (Unk_CtiTexture*)FUN_14098d8d0(DAT_143afa930, FUN_14097fbf0(&pB->m_spDecal));
    unsigned nWidth = FUN_140a5acb0(&pA->m_spBase)->vfunc_18();
    unsigned nHeight = FUN_140a5acb0(&pA->m_spBase)->vfunc_19();
    if (FUN_141167270(pBaseA) == 0)
        pBaseA->vfunc_20();
    if (pDecalA)
    {
        unsigned nW2 = pDecalA->vfunc_18();
        unsigned nH2 = pDecalA->vfunc_19();
        nWidth = nWidth < nW2 ? nW2 : nWidth;
        nHeight = nHeight < nH2 ? nH2 : nHeight;
        if (FUN_141167270(pDecalA) == 0)
            pDecalA->vfunc_20();
    }
    if (pBaseB && FUN_141167270(pBaseB) == 0)
        pBaseB->vfunc_20();
    if (pDecalB && FUN_141167270(pDecalB) == 0)
        pDecalB->vfunc_20();

    void* pSamplerBaseA = pBaseA ? FUN_14184d8c0(FUN_141167270(pBaseA), nWidth, nHeight) : 0;
    char hBaseA[8];
    FUN_140a5a500(hBaseA, pSamplerBaseA);
    void* pSamplerDecalA = pDecalA ? FUN_14184d8c0(FUN_141167270(pDecalA), nWidth, nHeight) : 0;
    char hDecalA[8];
    FUN_140a5a500(hDecalA, pSamplerDecalA);
    void* pSamplerBaseB = pBaseB ? FUN_14184d8c0(FUN_141167270(pBaseB), nWidth, nHeight) : 0;
    char hBaseB[8];
    FUN_140a5a500(hBaseB, pSamplerBaseB);
    void* pSamplerDecalB = pDecalB ? FUN_14184d8c0(FUN_141167270(pDecalB), nWidth, nHeight) : 0;
    char hDecalB[8];
    FUN_140a5a500(hDecalB, pSamplerDecalB);

    int nCatTmp2;
    int* pCat2 = (int*)FUN_140876480(&nCatTmp2, 0);
    void* pPixMem = FUN_14208a860(0x90, *pCat2);
    void* pPix = 0;
    if (pPixMem)
        pPix = FUN_141d31950(pPixMem, nWidth, nHeight, DAT_1439fb040, 1, 1);
    unsigned nStride = FUN_140d9d2a0(pPix);
    char* pDst = FUN_140d9d2c0(pPix, 0, 0);
    for (unsigned y = 0; y < nHeight; ++y)
    {
        for (unsigned x = 0; x < nWidth; ++x)
        {
            Unk_CtiUV kUV = FUN_140a0a4c0(((float)x + 0.5f) / (float)nWidth, ((float)y + 0.5f) / (float)nHeight);
            Unk_CtiColor kColor;
            Unk_CtiPixel kPix;
            FUN_141166d20(&kPix);
            Unk_CtiColor kBase;
            FUN_14184dad0(FUN_140a5ac70(hBaseA), kUV, &kPix, 1);
            FUN_1411671d0(&kPix, &kBase);
            if (FUN_140a5ac70(hDecalA) == 0)
            {
                kColor = kBase;
            }
            else
            {
                Unk_CtiColor kMask;
                FUN_14184dad0(FUN_140a5ac70(hDecalA), kUV, &kPix, 1);
                FUN_1411671d0(&kPix, &kMask);
                Unk_CtiColor kInv = FUN_141166de0(1.0f - kMask.r, pA->m_akColor[2]);
                Unk_CtiColor kGreen = FUN_141166de0(kMask.g, pA->m_akColor[1]);
                Unk_CtiColor kRed = FUN_141166de0(kMask.r, pA->m_akColor[0]);
                const Unk_CtiColor& kSum = kRed + kGreen + kInv;
                Unk_CtiColor kTint(&kSum);
                Unk_CtiColor kDelta = FUN_141166de0(kMask.a, kTint - kBase);
                const Unk_CtiColor& kMix = kBase + kDelta;
                kColor = Unk_CtiColor(&kMix);
                kColor.a = 1.0f;
            }
            if (FUN_140a5ac70(hBaseB) != 0)
            {
                Unk_CtiColor kBase2;
                FUN_14184dad0(FUN_140a5ac70(hBaseB), kUV, &kPix, 1);
                FUN_1411671d0(&kPix, &kBase2);
                if (FUN_140a5ac70(hDecalB) == 0)
                {
                    kColor += kBase2;
                }
                else
                {
                    Unk_CtiColor kMask2;
                    FUN_14184dad0(FUN_140a5ac70(hDecalB), kUV, &kPix, 1);
                    FUN_1411671d0(&kPix, &kMask2);
                    Unk_CtiColor kInv2 = FUN_141166de0(1.0f - kMask2.r, pB->m_akColor[2]);
                    Unk_CtiColor kGreen2 = FUN_141166de0(kMask2.g, pB->m_akColor[1]);
                    Unk_CtiColor kRed2 = FUN_141166de0(kMask2.r, pB->m_akColor[0]);
                    const Unk_CtiColor& kSum2 = kRed2 + kGreen2 + kInv2;
                    Unk_CtiColor kTint2(&kSum2);
                    Unk_CtiColor kDelta2 = FUN_141166de0(kMask2.a, kTint2 - kBase2);
                    const Unk_CtiColor& kMix2 = kBase2 + kDelta2;
                    kColor = Unk_CtiColor(&kMix2);
                    kColor.a = 1.0f;
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
    int aArgs[4];
    FUN_140984420(aArgs);
    aArgs[0] = 2;
    aArgs[2] = 0;
    FUN_14097f9b0(&pResult->m_spBase, FUN_141d33320(pPix, aArgs, 1));
    FUN_140a5a900(hDecalB);
    FUN_140a5a900(hBaseB);
    FUN_140a5a900(hDecalA);
    FUN_140a5a900(hBaseA);
    return pResult;
}

// @0x141166c80
void* FUN_141166c80(CCustomizedTextureManager* pMgr, CCustomizedTexInfo* pA, CCustomizedTexInfo* pB)
{
    return 0;
}

// the exe's is a member (this unused, hidden return slot in rdx); a free function put the slot in rcx
struct Unk_CtiCacheName { CString FUN_141166ca0(); };

// @0x141166ca0
// MS2-FUNCTIONAL: the exe copies the formatted name into the return slot (no NRVO); the copy shape differs
CString Unk_CtiCacheName::FUN_141166ca0()
{
    CString strName;
    strName.Format("CustomizingCache%d.dds", rand());
    return strName;
}

// @0x141166d20
// MS2-FUNCTIONAL: the exe's frame stores the this/out pointer differently around the ctor call
Unk_CtiPixel* FUN_141166d20(Unk_CtiPixel* pPix)
{
    FUN_141047040(pPix, 0, 0, 0, 0);
    return pPix;
}

// @0x141166d50
Unk_CtiColor Unk_CtiColor::operator*(float fScale)
{
    Unk_CtiColor kRes = *this;
    kRes.r = kRes.r * fScale;
    kRes.g = kRes.g * fScale;
    kRes.b = kRes.b * fScale;
    kRes.a = kRes.a * fScale;
    return kRes;
}

// @0x141166de0
Unk_CtiColor FUN_141166de0(float fScale, Unk_CtiColor kColor)
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
// MS2-FUNCTIONAL: the exe converts through different temp slots for the float->byte casts
void FUN_1411670f0(Unk_CtiColor* pColor, Unk_CtiPixel* pPix)
{
    float fR = pColor->r;
    *FUN_141048fc0(pPix) = (unsigned char)(int)(fR * 255.0f);
    float fG = pColor->g;
    *FUN_141048fb0(pPix) = (unsigned char)(int)(fG * 255.0f);
    float fB = pColor->b;
    *FUN_141048bc0(pPix) = (unsigned char)(int)(fB * 255.0f);
    float fA = pColor->a;
    *FUN_141048b80(pPix) = (unsigned char)(int)(fA * 255.0f);
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
