// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's util.cpp: out-of-memory handler, colour/point
// conversions, Win32 file/folder pickers, entity scene-graph lookups and assorted gameplay helpers.
// MS2-UNIT: client\ms2\util.cpp
// MS2-RANGE: 0x141b6db40-0x141b72630 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\util.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <commdlg.h>
#include <shlobj.h>
#include <shlwapi.h>
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"
#include <cmath>
#include <atlcoll.h>
#include <NiRenderObject.h>
#include <NiAVObject.h>
#include <NiMaterialProperty.h>
#include <NiTexturingProperty.h>
#include <NiColorExtraData.h>
#include <NiFloatExtraData.h>
#include <NiSequenceData.h>
#include <NiControllerSequence.h>
#include <NiTextKeyMatch.h>
#include <egf/EntityManager.h>
#include <efd/MemObject.h>
#include <float.h>
#include <efd/utf8string.h>
#include <egmAnimation/AnimationService.h>
#include "ms2/placeholder/ecrcameraservice.h"
#include <egf/Entity.h>
#include <ecr/SceneGraphService.h>
#include <efd/FixedString.h>
#include <NiStringExtraData.h>
#include <NiNode.h>
#include "ms2/commonfiles/filesystem.h"

// ---- externs used by the helpers ----
extern int DAT_143af7d44;                                           // "out of memory already reported"
extern int DAT_143ab0248;                                           // silent mode (no dialog)
extern const wchar_t DAT_142ff376c[];                               // path separator suffix

// The global logger object behind 0x140d8ee90 (category, message).
class Unk_UtilLogger { public: void FUN_140a1f970(const CStringA& kCategory, const CStringA& kMessage); };
Unk_UtilLogger* FUN_140d8ee90();

// The debug-log singleton behind 0x140a44830.
class Unk_UtilDebugLog { public: void FUN_140a43750(DWORD dwThreadId, CStringA kTag); void FUN_140a437d0(DWORD dwThreadId); };
Unk_UtilDebugLog* FUN_140a44830();

// The global out-of-memory report dialog (DAT_143af7e00, a CDialog).
class Unk_UtilErrorDialog : public CDialog
{
public:
    void FUN_140d53570(CStringA kText);                             // sets the caption text (by value: callee destroys)
    void SetKText(CStringA kText);
private:
    char m_pad_after_dialog[0x170 - sizeof(CDialog)];
    CStringA m_kText;                                               // +0x170
};
extern Unk_UtilErrorDialog DAT_143af7e00;

CStringA FUN_14028dc80(int nStringId);                              // UI string table (ANSI)
CStringW GetStringCommon(int nStringId);                              // UI string table (wide)
int FUN_141b6fcf0(const CStringW& kText, const CStringW& kTitle, unsigned nFlags);   // message box + quit prompt
CStringW FUN_14061ad70(const CStringW& kPath, const wchar_t* pszTail);
CStringW FUN_14016a730(const char* pszAnsi, int nCodePage);        // ANSI -> wide conversion
CStringA FUN_14016a600(const wchar_t* pszWide, int nCodePage);       // wide -> ANSI conversion
int FUN_141b72310(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData);   // BrowseForFolder callback
void* FUN_140aadf80();
HWND FUN_14209c720(void* pApp);                                     // main window handle of the app object

int FUN_141b6fd90(size_t nSize);                                   // new handler (reports size 3)

// ---- scene / entity helpers ----
extern char DAT_143ae50c8, DAT_143ae50d0, DAT_143ae50d8;            // NiFixedString keys of the three colour slots
extern NiFixedString DAT_143ae5140;                                 // float extra-data key
extern char DAT_143ae5200;                                          // default material name
struct Unk_MaterialTable;                                           // DAT_143d69198
extern Unk_MaterialTable DAT_143d69198;
struct Unk_Colc { float x, y, z; Unk_Colc(float x, float y, float z); };   // ctor 0x140a56db0

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
    size_t FUN_1414d3ff0();                         // number of pending nodes
    NiAVObject* FUN_1414d4a50();                    // current object
    void FUN_14098d6d0(NiNode* pNode);              // queue the children of a node
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);

NiObject* FUN_14098d8d0(const NiRTTI* pkRTTI, NiObject* pkObj);     // dynamic cast by RTTI
void* FUN_1409f7c90();                                              // the render settings singleton
int FUN_14109a9d0(void* pSettings);                                 // 0 = key by name lookup
const char* FUN_142087e50(const void* pFixed);                      // NiFixedString -> c string
NiMaterial* FUN_140a17cd0(NiRenderObject* pObj);                    // active material
const void* FUN_14106bd50(const NiMaterial* pMat);                  // material name
char FUN_141068d10(const void* pA, const void* pB);                 // name operator!=
char FUN_1409a7ff0(const void* pA, const void* pB);                 // NiFixedString equality
void FUN_1410479a0(NiAVObject* pObj, void* pKey, const Unk_Colc& kValue);   // set a shader constant
void* FUN_140a17af0(Unk_MaterialTable* pTable, const NiMaterial* pMat);
int FUN_140ef4dd0(void* pMatInfo);
NiObject* FUN_141d17b40(NiObjectNET* pObj, const void* pKey);       // extra-data lookup by key
float FUN_140a0fde0(float fValue, float fMax);                      // min(value, max)
float FUN_141b72530(NiObject* pColorData);
NiSequenceData* FUN_141b72540(NiControllerSequence* pSeq);          // sequence data of a controller sequence
float FUN_141b72480(NiControllerSequence* pSeq, const NiFixedString& kKey);   // text key time (-FLT_MAX if unknown)
bool FUN_14028d470(float fA, float fB);                             // float equality
float FUN_140a17940(float fValue, float fMin, float fMax);          // clamp
int FUN_1409618c0(egf::Entity* pEntity, unsigned uPropId, Unk_StreamPoint* pOut);   // read a Point3 property (0 = ok)
int FUN_140961880(egf::Entity* pEntity, unsigned uPropId, float* pOut);             // read a float property (0 = ok)

// NiPoint3 with the out-of-line conversion / move-assign of the exe.
struct Unk_UtilNiPoint3
{
    Unk_UtilNiPoint3(const Unk_StreamPoint& pt);                    // 0x14027dcf0
    Unk_UtilNiPoint3& operator=(Unk_UtilNiPoint3&& pt);             // 0x14097faa0
    float x, y, z;
};
// NiTransform layout: rotation, translation, scale.
struct Unk_UtilTransform
{
    Unk_NiMatrix3 m_kRotate;                                        // +0x00
    Unk_UtilNiPoint3 m_kTranslate;                                  // +0x24
    float m_fScale;                                                 // +0x30
};
MS2_CHECK_SIZE(Unk_UtilTransform, 0x34);
void* FUN_140876480(void* pOut, int nCategory);                    // memory hint for new
float FUN_141b72470(NiObject* pColorData);
float FUN_141b72460(NiObject* pColorData);
CStringA& FUN_140164930(CAtlArray<CStringA>& arr, size_t i);        // CAtlArray<CStringA> operator[]
int FUN_14028c3e0(const CStringA& kText, CAtlArray<CStringA>& arrOut, const char* pszDelim, int nMax);
egf::EntityManager* FUN_1409670f0();
egf::Entity* FUN_1411cf440(egf::EntityManager* pMgr, const egf::EntityID& id);
ecr::SceneGraphService* FUN_1413f98b0();

// ---- 12-byte vector helpers ----
struct Unk_UtilArgb                                                 // packed ARGB unpacked to unit floats
{
    Unk_UtilArgb(unsigned uColor)
    {
        r = 0.003921569f * (float)(BYTE)(uColor >> 16);
        g = 0.003921569f * (float)(BYTE)(uColor >> 8);
        b = 0.003921569f * (float)(BYTE)uColor;
        a = 0.003921569f * (float)(BYTE)(uColor >> 24);
    }
    float r, g, b, a;
};
struct Unk_UtilColor4                                               // four-float colour (packed by 0x1408a90b0)
{
    Unk_UtilColor4(float r, float g, float b, float a);            // 0x1408a86a0
    float r, g, b, a;
};
unsigned FUN_1408a90b0(const Unk_UtilColor4& color);               // colour -> packed ARGB
struct Unk_UtilFloat3
{
    float x, y, z;
    Unk_UtilFloat3 FUN_141b723e0(float fDivisor) const;           // 0x141b723e0 *this / fDivisor (this=rcx, hidden return=rdx)
};
struct Unk_UtilUInt3 { unsigned x, y, z; };
struct Unk_UtilNxVec3
{
    Unk_UtilNxVec3();                                               // 0x140a003a0
    Unk_UtilNxVec3(const Unk_UtilNxVec3&);                          // 0x140a00300
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_UtilNxVec3, 12);

// @0x141b6db40
// MS2-FUNCTIONAL: exe frame is 0x20 smaller (temp slots of the two ref-bound strings are laid out differently)
int FUN_141b6db40(size_t nSize)
{
    if (DAT_143af7d44 != 0)
        return 0;
    if (FUN_140d8ee90() != 0) {
        if (nSize == 1) {
            CStringA kMessage("bad_alloc physx");
            CStringA kCategory("memory");
            FUN_140d8ee90()->FUN_140a1f970(kCategory, kMessage);
        } else if (nSize == 2) {
            CStringA kMessage("bad_alloc cef");
            CStringA kCategory("memory");
            FUN_140d8ee90()->FUN_140a1f970(kCategory, kMessage);
        } else {
            CStringA kMessage("bad_alloc others");
            CStringA kCategory("memory");
            FUN_140d8ee90()->FUN_140a1f970(kCategory, kMessage);
        }
    }
    DAT_143af7d44 = 1;
    if (DAT_143ab0248 == 0) {
        DAT_143af7e00.FUN_140d53570(FUN_14028dc80(0xb22));
        DAT_143af7e00.SetKText(FUN_14028dc80(0xb24));
        if (DAT_143af7e00.DoModal() == -1) {
            FUN_141b6fcf0(GetStringCommon(0xb24), CStringW(L"Error"), 0x10);
        }
    } else {
        FUN_141b6fcf0(GetStringCommon(0xb24), CStringW(L"Error"), 0x10);
    }
    return 0;
}

// @0x141b6de20
void FUN_141b6de20()
{
    AfxSetNewHandler(FUN_141b6fd90);
    if (FUN_140a44830() != 0) {
        FUN_140a44830()->FUN_140a43750(GetCurrentThreadId(), CStringA(""));
    }
}
MS2_REPLACE(0x141b6de20, FUN_141b6de20, 118, 0x4043FAA8);

// @0x141b6dea0
Unk_Vec3Cli FUN_141b6dea0(unsigned uColor)
{
    float fScale = 0.003921569f;
    float fR = 0.003921569f * (float)(BYTE)(uColor >> 16);
    float fG = 0.003921569f * (float)(BYTE)(uColor >> 8);
    float fB = 0.003921569f * (float)(BYTE)uColor;
    float fA = 0.003921569f * (float)(BYTE)(uColor >> 24);
    Unk_Vec3Cli vColor(fR, fG, fB);
    return vColor;
}
MS2_REPLACE(0x141b6dea0, FUN_141b6dea0, 224, 0xF622B07E);

// @0x141b6df90
unsigned FUN_141b6df90(const Unk_UtilFloat3* pColor)
{
    return FUN_1408a90b0(Unk_UtilColor4(pColor->x, pColor->y, pColor->z, 1.0f));
}
MS2_REPLACE(0x141b6df90, FUN_141b6df90, 75, 0x28AAD3F2);

// @0x141b6dff0
Unk_UtilFloat3 FUN_141b6dff0(const Unk_UtilFloat3* pVec)
{
    Unk_UtilFloat3 vCopy;
    vCopy.x = pVec->x;
    vCopy.y = pVec->y;
    vCopy.z = pVec->z;
    return vCopy;
}
MS2_REPLACE(0x141b6dff0, FUN_141b6dff0, 121, 0xB7A204A8);

// @0x141b6e070
Unk_StreamPoint FUN_141b6e070(const Unk_UtilFloat3* pVec)
{
    Unk_StreamPoint vCopy;
    vCopy.x = pVec->x;
    vCopy.y = pVec->y;
    vCopy.z = pVec->z;
    return vCopy;
}
MS2_REPLACE(0x141b6e070, FUN_141b6e070, 105, 0xAE2F521A);

// @0x141b6e0e0
Unk_UtilNxVec3 FUN_141b6e0e0(const Unk_UtilFloat3* pVec)
{
    Unk_UtilNxVec3 vCopy;
    vCopy.x = pVec->x;
    vCopy.y = pVec->y;
    vCopy.z = pVec->z;
    return vCopy;
}
MS2_REPLACE(0x141b6e0e0, FUN_141b6e0e0, 96, 0x9AD7DDE3);

// @0x141b6e150
Unk_StreamPoint FUN_141b6e150(const Unk_UtilFloat3* pVec)
{
    Unk_StreamPoint vCopy;
    vCopy.x = pVec->x;
    vCopy.y = pVec->y;
    vCopy.z = pVec->z;
    return vCopy;
}
MS2_REPLACE(0x141b6e150, FUN_141b6e150, 105, 0xB6F3C78B);

// @0x141b6e1c0
// MS2-FUNCTIONAL: return-slot spill is scheduled earlier than in the exe
CStringA FUN_141b6e1c0(const CStringA& kInitialDir, LPCSTR pszFilter, const CStringA& kDefaultFile)
{
    char szFile[MAX_PATH] = { 0 };
    HWND hWndOwner = FUN_14209c720(FUN_140aadf80());
    if (!kDefaultFile.IsEmpty())
        strcpy_s(szFile, MAX_PATH, (LPCSTR)kDefaultFile);
    OPENFILENAMEA ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWndOwner;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.nFilterIndex = 0;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrFilter = pszFilter;
    ofn.lpstrInitialDir = (LPCSTR)kInitialDir;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
    CStringA kResult;
    if (GetOpenFileNameA(&ofn) == 1)
        kResult = ofn.lpstrFile;
    return kResult;
}

// @0x141b6e360
// MS2-FUNCTIONAL: return-slot spill is scheduled earlier than in the exe
CStringW FUN_141b6e360(const CStringW& kInitialDir, LPCWSTR pszFilter, const CStringW& kDefaultFile)
{
    wchar_t szFile[MAX_PATH] = { 0 };
    HWND hWndOwner = FUN_14209c720(FUN_140aadf80());
    if (!kDefaultFile.IsEmpty())
        wcscpy_s(szFile, MAX_PATH, (LPCWSTR)kDefaultFile);
    OPENFILENAMEW ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWndOwner;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.nFilterIndex = 0;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrFilter = pszFilter;
    ofn.lpstrInitialDir = (LPCWSTR)kInitialDir;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
    CStringW kResult;
    if (GetOpenFileNameW(&ofn) == 1)
        kResult = ofn.lpstrFile;
    return kResult;
}

// @0x141b6e500
CStringA FUN_141b6e500(const CStringA& kInitialDir, LPCSTR pszFilter, const CStringA& kDefaultFile)
{
    return FUN_141b6e1c0(kInitialDir, pszFilter, kDefaultFile);
}
MS2_REPLACE(0x141b6e500, FUN_141b6e500, 78, 0x48E5C3D5);

// @0x141b6e560
// MS2-FUNCTIONAL: return-slot spill/flags scheduling differs
CStringA FUN_141b6e560(const CStringA& kInitialDir, LPCSTR pszFilter, const CStringA& kDefaultFile)
{
    HWND hWndOwner = FUN_14209c720(FUN_140aadf80());
    char szFile[MAX_PATH] = { 0 };
    strcpy_s(szFile, MAX_PATH, (LPCSTR)kDefaultFile);
    OPENFILENAMEA ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWndOwner;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.nFilterIndex = 0;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrFilter = pszFilter;
    ofn.lpstrInitialDir = (LPCSTR)kInitialDir;
    ofn.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
    CStringA kResult;
    if (GetSaveFileNameA(&ofn) == 1)
        kResult = ofn.lpstrFile;
    return kResult;
}

// @0x141b6e6f0
// MS2-FUNCTIONAL: return-slot spill/flags scheduling differs
CStringW FUN_141b6e6f0(const CStringW& kInitialDir, LPCWSTR pszFilter, const CStringW& kDefaultFile)
{
    HWND hWndOwner = FUN_14209c720(FUN_140aadf80());
    wchar_t szFile[MAX_PATH] = { 0 };
    wcscpy_s(szFile, MAX_PATH, (LPCWSTR)kDefaultFile);
    OPENFILENAMEW ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWndOwner;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.nFilterIndex = 0;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrFilter = pszFilter;
    ofn.lpstrInitialDir = (LPCWSTR)kInitialDir;
    ofn.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
    CStringW kResult;
    if (GetSaveFileNameW(&ofn) == 1)
        kResult = ofn.lpstrFile;
    return kResult;
}

// @0x141b6e880
CStringA FUN_141b6e880(const CStringA& kInitialDir, LPCSTR pszFilter, const CStringA& kDefaultFile)
{
    return FUN_141b6e560(kInitialDir, pszFilter, kDefaultFile);
}
MS2_REPLACE(0x141b6e880, FUN_141b6e880, 78, 0x33B131F5);

// @0x141b6e990
// MS2-FUNCTIONAL: temp scheduling differs
CStringW FUN_141b6e990(const CStringW& kStartPath)
{
    wchar_t szPath[MAX_PATH] = { 0 };
    BROWSEINFOW bi = { 0 };
    lstrcpyW(szPath, (LPCWSTR)kStartPath);
    PathRemoveBackslashW(szPath);
    bi.hwndOwner = FUN_14209c720(FUN_140aadf80());
    bi.pszDisplayName = szPath;
    bi.lpszTitle = L"\uD3F4\uB354\uB97C \uC120\uD0DD\uD558\uC138\uC694";
    bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT | BIF_EDITBOX;
    bi.lpfn = FUN_141b72310;
    bi.lParam = (LPARAM)szPath;
    LPITEMIDLIST pidl = SHBrowseForFolderW(&bi);
    if (!SHGetPathFromIDListW(pidl, szPath))
        return kStartPath;
    return FUN_14061ad70(CStringW(szPath), L"\\");
}

// @0x141b6e8e0
// MS2-FUNCTIONAL: hidden temp frame layout differs (0x10 larger)
CStringA FUN_141b6e8e0(const CStringA& kStartPath)
{
    const CStringW& kPicked = FUN_141b6e990(FUN_14016a730((LPCSTR)kStartPath, 0));
    const CStringW& kPickedRef = kPicked;
    return FUN_14016a600((LPCWSTR)kPickedRef, 0);
}

// @0x141b6eb40
CStringA FUN_141b6eb40(const CStringA& kStartPath)
{
    return FUN_141b6e8e0(kStartPath);
}
MS2_REPLACE(0x141b6eb40, FUN_141b6eb40, 58, 0x7BE0BA74);

// @0x141b6ec30
CStringW FUN_141b6ec30(const CStringW& kPath)
{
    wchar_t szFile[256] = { 0 };
    _wsplitpath_s((LPCWSTR)kPath, NULL, 0, NULL, 0, szFile, 256, NULL, 0);
    return CStringW(szFile);
}
MS2_REPLACE(0x141b6ec30, FUN_141b6ec30, 201, 0x1164ACCB);

// @0x141b6eb80
// MS2-FUNCTIONAL: hidden temp frame layout differs
CStringA FUN_141b6eb80(const CStringA& kPath)
{
    const CStringW& kName = FUN_141b6ec30(FUN_14016a730((LPCSTR)kPath, 0));
    const CStringW& kNameRef = kName;
    return FUN_14016a600((LPCWSTR)kNameRef, 0);
}

// @0x141b6ed00
CStringA FUN_141b6ed00(const CStringA& kPath)
{
    return FUN_141b6eb80(kPath);
}
MS2_REPLACE(0x141b6ed00, FUN_141b6ed00, 58, 0xA43FC783);

// @0x141b6ed40
void FUN_141b6ed40(const CStringA& kText, Unk_UtilFloat3* pOut)
{
    CAtlArray<CStringA> arrParts;
    if (FUN_14028c3e0(kText, arrParts, ",", 3) == 0)
        return;
    pOut->x = (float)atof(FUN_140164930(arrParts, 0));
    pOut->y = (float)atof(FUN_140164930(arrParts, 1));
    pOut->z = (float)atof(FUN_140164930(arrParts, 2));
}
MS2_REPLACE(0x141b6ed40, FUN_141b6ed40, 233, 0x97815FBE);

// @0x141b6ee30
CStringA FUN_141b6ee30(const Unk_UtilFloat3* pVec)
{
    CStringA kText;
    kText.Format("%f, %f, %f", (double)pVec->x, (double)pVec->y, (double)pVec->z);
    return kText;
}
MS2_REPLACE(0x141b6ee30, FUN_141b6ee30, 157, 0x3B25AB80);

// @0x141b6eee0
CStringA FUN_141b6eee0(const Unk_UtilUInt3* pVec)
{
    CStringA kText;
    kText.Format("%d,%d,%d", pVec->x, pVec->y, pVec->z);
    return kText;
}
MS2_REPLACE(0x141b6eee0, FUN_141b6eee0, 138, 0x7091A733);

// @0x141b6ef70
NiAVObject* FUN_141b6ef70(egf::EntityID id)
{
    egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), id);
    if (pEntity == NULL)
        return NULL;
    ecr::SceneGraphService* pService = FUN_1413f98b0();
    return pService->GetSceneGraphFromEntity(pEntity);
}
MS2_REPLACE(0x141b6ef70, FUN_141b6ef70, 74, 0x1068FDB3);

// @0x141b6efc0
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity)
{
    if (pEntity == NULL)
        return NULL;
    ecr::SceneGraphService* pService = FUN_1413f98b0();
    return pService->GetSceneGraphFromEntity(pEntity);
}
MS2_REPLACE(0x141b6efc0, FUN_141b6efc0, 51, 0x52369C41);

// @0x141b6f000
// MS2-FUNCTIONAL: stack frame / temp scheduling differs from the exe (same slot layout, extra unused temp)
void FUN_141b6f000(NiAVObject* pRoot, int nSlot, const Unk_Colc& kValue)
{
    if (pRoot == NULL)
        return;
    const char* pszKey = NULL;
    if (FUN_14109a9d0(FUN_1409f7c90()) == 0) {
        if (nSlot == 0)
            pszKey = FUN_142087e50(&DAT_143ae50c8);
        else if (nSlot == 1)
            pszKey = FUN_142087e50(&DAT_143ae50d0);
        else
            pszKey = FUN_142087e50(&DAT_143ae50d8);
    }
    Unk_SceneWalker kWalker(pRoot);
    while (NiAVObject* pNode = kWalker.Next(true)) {
        NiRenderObject* pRender = (NiRenderObject*)FUN_14098d8d0(&NiRenderObject::ms_RTTI, pNode);
        if (pRender == NULL)
            continue;
        NiMaterial* pMaterial = FUN_140a17cd0(pRender);
        if (pMaterial == NULL)
            continue;
        if (!FUN_141068d10(FUN_14106bd50(pMaterial), &DAT_143ae5200))
            continue;
        NiObject* pTexturing = FUN_14098d8d0(&NiTexturingProperty::ms_RTTI, pRender->GetProperty(NiProperty::TEXTURING));
        if (pTexturing == NULL)
            continue;
        if (FUN_14109a9d0(FUN_1409f7c90()) == 0) {
            NiFixedString kName(pszKey);
            FUN_1410479a0(pRender, &kName, kValue);
        } else {
            switch (nSlot) {
            case 0: FUN_1410479a0(pRender, &DAT_143ae50c8, kValue); break;
            case 1: FUN_1410479a0(pRender, &DAT_143ae50d0, kValue); break;
            default: FUN_1410479a0(pRender, &DAT_143ae50d8, kValue); break;
            }
        }
    }
}

// @0x141b6f220
// MS2-FUNCTIONAL: stack frame / temp scheduling differs from the exe (same slot layout, extra unused temp)
void FUN_141b6f220(NiAVObject* pRoot, int nSlot, const Unk_Colc& kValue)
{
    if (pRoot == NULL)
        return;
    const char* pszKey = NULL;
    if (FUN_14109a9d0(FUN_1409f7c90()) == 0) {
        if (nSlot == 0)
            pszKey = FUN_142087e50(&DAT_143ae50c8);
        else if (nSlot == 1)
            pszKey = FUN_142087e50(&DAT_143ae50d0);
        else
            pszKey = FUN_142087e50(&DAT_143ae50d8);
    }
    Unk_SceneWalker kWalker(pRoot);
    while (NiAVObject* pNode = kWalker.Next(true)) {
        NiRenderObject* pRender = (NiRenderObject*)FUN_14098d8d0(&NiRenderObject::ms_RTTI, pNode);
        if (pRender == NULL)
            continue;
        void* pInfo = FUN_140a17af0(&DAT_143d69198, FUN_140a17cd0(pRender));
        if (pInfo == NULL || FUN_140ef4dd0(pInfo) != 2)
            continue;
        NiObject* pTexturing = FUN_14098d8d0(&NiTexturingProperty::ms_RTTI, pRender->GetProperty(NiProperty::TEXTURING));
        if (pTexturing == NULL)
            continue;
        if (FUN_14109a9d0(FUN_1409f7c90()) == 0) {
            NiFixedString kName(pszKey);
            FUN_1410479a0(pRender, &kName, kValue);
        } else {
            switch (nSlot) {
            case 0: FUN_1410479a0(pRender, &DAT_143ae50c8, kValue); break;
            case 1: FUN_1410479a0(pRender, &DAT_143ae50d0, kValue); break;
            default: FUN_1410479a0(pRender, &DAT_143ae50d8, kValue); break;
            }
        }
    }
}

// @0x141b6f440
// MS2-FUNCTIONAL: stack frame / temp scheduling differs from the exe (same slot layout, extra unused temp)
bool FUN_141b6f440(NiAVObject* pRoot, int nSlot, Unk_UtilFloat3* pOut)
{
    if (pRoot == NULL)
        return false;
    const char* pszKey = NULL;
    if (FUN_14109a9d0(FUN_1409f7c90()) == 0) {
        if (nSlot == 0)
            pszKey = FUN_142087e50(&DAT_143ae50c8);
        else if (nSlot == 1)
            pszKey = FUN_142087e50(&DAT_143ae50d0);
        else
            pszKey = FUN_142087e50(&DAT_143ae50d8);
    }
    Unk_SceneWalker kWalker(pRoot);
    NiObject* pColor;
    do {
        NiRenderObject* pRender;
        do {
            NiAVObject* pNode = kWalker.Next(true);
            if (pNode == NULL)
                return false;
            pRender = (NiRenderObject*)FUN_14098d8d0(&NiRenderObject::ms_RTTI, pNode);
        } while (pRender == NULL || FUN_1409a7ff0(FUN_14106bd50(FUN_140a17cd0(pRender)), &DAT_143ae5200));
        if (FUN_14109a9d0(FUN_1409f7c90()) == 0) {
            NiFixedString kName(pszKey);
            pColor = FUN_14098d8d0(&NiColorExtraData::ms_RTTI, FUN_141d17b40(pRender, &kName));
        } else {
            switch (nSlot) {
            case 0: pColor = FUN_14098d8d0(&NiColorExtraData::ms_RTTI, FUN_141d17b40(pRender, &DAT_143ae50c8)); break;
            case 1: pColor = FUN_14098d8d0(&NiColorExtraData::ms_RTTI, FUN_141d17b40(pRender, &DAT_143ae50d0)); break;
            default: pColor = FUN_14098d8d0(&NiColorExtraData::ms_RTTI, FUN_141d17b40(pRender, &DAT_143ae50d8)); break;
            }
        }
    } while (pColor == NULL);
    float fR = FUN_141b72530(pColor);
    float fG = FUN_141b72470(pColor);
    float fB = FUN_141b72460(pColor);
    pOut->x = fR;
    pOut->y = fG;
    pOut->z = fB;
    return true;
}

// @0x141b6f700
float FUN_141b6f700(const egf::EntityID& rId)
{
    NiAVObject* pScene = FUN_141b6ef70(rId);
    float fAlpha = 0.0f;
    if (pScene != NULL) {
        Unk_SceneWalker kWalker(pScene);
        while (NiAVObject* pNode = kWalker.Next(true)) {
            NiObject* pMaterial = FUN_14098d8d0(&NiMaterialProperty::ms_RTTI, pNode->GetProperty(NiProperty::MATERIAL));
            if (pMaterial != NULL)
                return ((NiMaterialProperty*)pMaterial)->GetAlpha();
        }
    }
    return fAlpha;
}
MS2_REPLACE(0x141b6f700, FUN_141b6f700, 227, 0x4765F8EE);

// @0x141b6f7f0
CStringW FUN_141b6f7f0(long long nValue)
{
    CStringW kText;
    kText.Format(L"%ld", nValue);
    int nPos;
    for (nPos = kText.GetLength() - 3; nPos > 0; nPos -= 3)
        kText.Insert(nPos, L',');
    return kText;
}
MS2_REPLACE(0x141b6f7f0, FUN_141b6f7f0, 174, 0x25B96EA0);

// @0x141b6f8b0
int FUN_141b6f8b0(int nMin, int nMax)
{
    if (nMin == nMax || nMin > nMax)
        return nMin;
    int nRange = nMax - nMin;
    return nMin + rand() % nRange;
}
MS2_REPLACE(0x141b6f8b0, FUN_141b6f8b0, 80, 0xA2C1A562);

// @0x141b6f910
egmAnimation::AnimationService* FUN_141b6f910()
{
    egmAnimation::AnimationService* pService = g_143b059e8.GetSystemServiceAs<egmAnimation::AnimationService>();
    return pService;
}
MS2_REPLACE(0x141b6f910, FUN_141b6f910, 31, 0x80477666);

// @0x141b6f940
// MS2-FUNCTIONAL: min() temp copies (xmm2 -> xmm0) are scheduled differently
Unk_Vec3Cli FUN_141b6f940(const Unk_UtilFloat3* pColor)
{
    float fB = FUN_140a0fde0(pColor->z * 1.3f, 1.0f);
    float fG = FUN_140a0fde0(pColor->y * 1.3f, 1.0f);
    float fR = FUN_140a0fde0(pColor->x * 1.3f, 1.0f);
    return Unk_Vec3Cli(fR, fG, fB);
}

// @0x141b6fa10
Unk_Vec3Cli FUN_141b6fa10(const Unk_UtilFloat3* pColor)
{
    return Unk_Vec3Cli(pColor->x * 0.7f, pColor->y * 0.7f, pColor->z * 0.7f);
}
MS2_REPLACE(0x141b6fa10, FUN_141b6fa10, 108, 0x2E8B2085);

// @0x141b6fa90
bool FUN_141b6fa90(const egf::EntityID& id, const efd::utf8string& kName)
{
    return FUN_141b6f910()->GetAnimationIdFromName(id, kName) != NiActorManager::INVALID_SEQUENCE_ID;
}
MS2_REPLACE(0x141b6fa90, FUN_141b6fa90, 73, 0x30A74C77);

// @0x141b6fae0
// MS2-FUNCTIONAL: local slots (node / cast / extra-data temps) are allocated in a different order than the exe
void FUN_141b6fae0(NiAVObject* pRoot, float fValue)
{
    Unk_SceneWalker kWalker(pRoot);
    while (NiAVObject* pNode = kWalker.Next(true)) {
        NiRenderObject* pRender = (NiRenderObject*)FUN_14098d8d0(&NiRenderObject::ms_RTTI, pNode);
        if (pRender == NULL)
            continue;
        NiFloatExtraData* pExtra = (NiFloatExtraData*)FUN_14098d8d0(&NiFloatExtraData::ms_RTTI, FUN_141d17b40(pRender, &DAT_143ae5140));
        if (pExtra == NULL) {
            void* pTmp;
            efd::MemHint* pCat = (efd::MemHint*)FUN_140876480(&pTmp, 0);
            NiFloatExtraData* pNew = new (*pCat) NiFloatExtraData(fValue);
            pRender->AddExtraData(DAT_143ae5140, pNew);
        } else {
            pExtra->SetValue(fValue);
        }
    }
    if (pRoot != NULL)
        pRoot->UpdateProperties();
}

// @0x141b6fc50
int FUN_141b6fc50(const CStringA& kText, const CStringA& kTitle, unsigned nFlags)
{
    CStringW kWideText = FUN_14016a730((LPCSTR)kText, 0);
    CStringW kWideTitle = FUN_14016a730((LPCSTR)kTitle, 0);
    return FUN_141b6fcf0(kWideText, kWideTitle, nFlags);
}
MS2_REPLACE(0x141b6fc50, FUN_141b6fc50, 140, 0x0919FD6C);

// @0x141b6fcf0
int FUN_141b6fcf0(const CStringW& kText, const CStringW& kTitle, unsigned nFlags)
{
    HWND hWnd = NULL;
    if (FUN_140aadf80() != NULL && DAT_143af7d44 == 0) {
        hWnd = FUN_14209c720(FUN_140aadf80());
        ShowWindow(hWnd, SW_MINIMIZE);
    }
    return MessageBoxW(hWnd, (LPCWSTR)kText, (LPCWSTR)kTitle, nFlags | 0x40000);
}
MS2_REPLACE(0x141b6fcf0, FUN_141b6fcf0, 154, 0xEE50C620);

// @0x141b6fd90
int FUN_141b6fd90(size_t)
{
    return FUN_141b6db40(3);
}
MS2_REPLACE(0x141b6fd90, FUN_141b6fd90, 24, 0xD9535623);

// @0x141b6fdb0
// MS2-FUNCTIONAL: switch jump layout differs from exe (temp copy of nCurve)
float FUN_141b6fdb0(float fValue, int nCurve)
{
    switch (nCurve) {
    case 2:
        fValue = logf(fValue * 10.0f + 1.0f);
        fValue = fValue / 2.397895f;
        break;
    case 3:
        fValue = (expf(fValue * 5.0f) - 1.0f) / 147.41316f;
        break;
    default:
        break;
    }
    return fValue;
}

// @0x141b6fe40
float FUN_141b6fe40(float fValue, int nCurve)
{
    fValue = FUN_141b6fdb0(fValue, nCurve);
    return FUN_140a17940(fValue, 0.0f, 1.0f);
}
MS2_REPLACE(0x141b6fe40, FUN_141b6fe40, 62, 0x6EFBDA85);

float FUN_141b6fee0(NiSequenceData* pSeqData, const NiFixedString& kKey, float fDivisor);

// @0x141b6fe90
float FUN_141b6fe90(NiControllerSequence* pSeq, const NiFixedString& kKey, float fDivisor)
{
    if (pSeq == NULL)
        return -FLT_MAX;
    return FUN_141b6fee0(FUN_141b72540(pSeq), kKey, fDivisor);
}
MS2_REPLACE(0x141b6fe90, FUN_141b6fe90, 72, 0xF095A001);

// @0x141b6fee0
float FUN_141b6fee0(NiSequenceData* pSeqData, const NiFixedString& kKey, float fDivisor)
{
    if (pSeqData == NULL)
        return -FLT_MAX;
    float fTime = pSeqData->GetKeyTimeAt(kKey);
    if (FUN_14028d470(fTime, -FLT_MAX))
        return pSeqData->GetDuration() / fDivisor;
    return fTime / fDivisor;
}
MS2_REPLACE(0x141b6fee0, FUN_141b6fee0, 120, 0xDB3D7EC8);

// @0x141b6ff60
int FUN_141b6ff60(NiControllerSequence* pSeq, const NiFixedString& kKey)
{
    if (pSeq == NULL)
        return 0;
    return FUN_14028d470(FUN_141b72480(pSeq, kKey), -FLT_MAX) == 0 ? 1 : 0;
}
MS2_REPLACE(0x141b6ff60, FUN_141b6ff60, 88, 0x49F663AD);

// @0x141b6ffc0
int FUN_141b6ffc0(NiSequenceData* pSeqData, const NiFixedString& kKey)
{
    if (pSeqData == NULL)
        return 0;
    return FUN_14028d470(pSeqData->GetKeyTimeAt(kKey), -FLT_MAX) == 0 ? 1 : 0;
}
MS2_REPLACE(0x141b6ffc0, FUN_141b6ffc0, 88, 0x5FA463E7);

// @0x141b70020
// MS2-FUNCTIONAL: temp/copy-ctor layout of Unk_UtilTransform math differs
bool FUN_141b70020(egf::Entity* pEntity, Unk_UtilTransform* pOut)
{
    Unk_StreamPoint vTranslation;
    if (FUN_1409618c0(pEntity, 0xfd95ca52, &vTranslation) != 0)
        return false;
    pOut->m_kTranslate = Unk_UtilNiPoint3(vTranslation);
    Unk_StreamPoint vEuler;
    if (FUN_1409618c0(pEntity, 0x68c7c29d, &vEuler) != 0)
        return false;
    Unk_NiMatrix3 kX;
    Unk_NiMatrix3 kY;
    Unk_NiMatrix3 kZ;
    kX.FUN_142084b30(vEuler.x * -0.017453292f);
    kY.FUN_142084ba0(vEuler.y * -0.017453292f);
    kZ.FUN_142084c10(vEuler.z * -0.017453292f);
    pOut->m_kRotate = Unk_NiMatrix3(kX.FUN_140a33480(kY).FUN_140a33480(kZ));
    float fScale;
    if (FUN_140961880(pEntity, 0x2d7cad2d, &fScale) != 0)
        return false;
    pOut->m_fScale = fScale;
    return true;
}

// ---- list / directory / time helpers ----
struct Unk_UtilNodeList;
struct Unk_UtilNode;
unsigned FUN_14106bf60(const Unk_UtilNodeList* pList);              // node count
Unk_UtilNode* FUN_140d89e80(Unk_UtilNodeList* pList, unsigned nIndex);
unsigned char FUN_14106b8f0(const Unk_UtilNode* pNode);             // node flag byte

// @0x141b701f0
bool FUN_141b701f0(Unk_UtilNodeList* pList, unsigned bMask)
{
    if (pList == NULL)
        return false;
    unsigned nCount = FUN_14106bf60(pList);
    if (nCount == 0)
        return false;
    for (unsigned i = 0; i < nCount; i++) {
        Unk_UtilNode* pNode = FUN_140d89e80(pList, i);
        if (pNode != NULL) {
            if ((FUN_14106b8f0(pNode) & bMask) != 0)
                continue;
            return false;
        }
    }
    return true;
}

// The client configuration object behind 0x1401d31f0 (root path at +0x60).
struct Unk_UtilConfig
{
    char m_pad_00[0x60];
    CStringA m_kRoot;
};
Unk_UtilConfig* FUN_1401d31f0();
CStringA FUN_1412755f0();
CStringA FUN_141275640();
CStringA FUN_14016a5c0(const char* psz, int n);
CStringA FUN_14038f6d0(const CStringA& kLeft, const char* pszRight);
bool thunk_FUN_1420b1ae0(const char* pszPath);                      // directory exists

// @0x141b70290
// MS2-FUNCTIONAL: exe statically links _mkdir (call 0x1420b1a80), build imports it
void FUN_141b70290()
{
    CStringA kPath;
    kPath.Format("%s%s", (LPCSTR)FUN_14016a5c0((LPCSTR)FUN_1401d31f0()->m_kRoot, 0), (LPCSTR)FUN_1412755f0());
    if (!thunk_FUN_1420b1ae0((LPCSTR)kPath))
        _mkdir((LPCSTR)kPath);
}

// @0x141b70390
// MS2-FUNCTIONAL: exe statically links _mkdir (call 0x1420b1a80), build imports it
void FUN_141b70390()
{
    CStringA kPath;
    kPath.Format("%s%s", (LPCSTR)FUN_14016a5c0((LPCSTR)FUN_1401d31f0()->m_kRoot, 0), (LPCSTR)FUN_141275640());
    if (!thunk_FUN_1420b1ae0((LPCSTR)kPath))
        _mkdir((LPCSTR)kPath);
}

// @0x141b70490
// MS2-FUNCTIONAL: frame is 16 bytes larger than the exe's
void FUN_141b70490(const CStringA& kBase)
{
    int nMore = 1;
    CStringA kPath(kBase);
    HANDLE hFind;
    WIN32_FIND_DATAA kFound;
    hFind = FindFirstFileA((LPCSTR)FUN_14038f6d0(kPath, "*.*"), &kFound);
    if (hFind != INVALID_HANDLE_VALUE) {
        while (nMore != 0) {
            char szDrive[4];
            char szDir[272];
            char szName[256];
            _splitpath((LPCSTR)kPath, szDrive, szDir, szName, NULL);
            if ((kFound.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
                CStringA kFile;
                kFile += szDir;
                kFile += kFound.cFileName;
                DeleteFileA((LPCSTR)kFile);
            } else if (kFound.cFileName[0] != '.') {
                char szSub[272];
                sprintf(szSub, "%s%s%s/", szDrive, szDir, kFound.cFileName);
                CStringA kSub(szSub);
                FUN_141b70490(kSub);
                RemoveDirectoryA((LPCSTR)kSub);
            }
            nMore = FindNextFileA(hFind, &kFound);
        }
        FindClose(hFind);
    }
}

// @0x141b706a0
void FUN_141b706a0(unsigned nMs, unsigned* pMinutes, unsigned* pSeconds, unsigned* pCentis)
{
    *pMinutes = nMs / 1000 / 60;
    *pSeconds = (nMs / 1000) % 60;
    *pCentis = (nMs % 1000) / 10;
}
MS2_REPLACE(0x141b706a0, FUN_141b706a0, 111, 0x3E16FC5F);

void FUN_141b70760(unsigned nMs, CStringA& kOut, unsigned* pMinutes, unsigned* pSeconds, unsigned* pCentis);

// @0x141b70720
void FUN_141b70720(unsigned nMs, CStringA& kOut)
{
    unsigned nMinutes, nSeconds, nCentis;
    FUN_141b70760(nMs, kOut, &nMinutes, &nSeconds, &nCentis);
}
MS2_REPLACE(0x141b70720, FUN_141b70720, 52, 0xEA0FFF7B);

// @0x141b70760
void FUN_141b70760(unsigned nMs, CStringA& kOut, unsigned* pMinutes, unsigned* pSeconds, unsigned* pCentis)
{
    *pCentis = 0;
    *pSeconds = 0;
    *pMinutes = 0;
    FUN_141b706a0(nMs, pMinutes, pSeconds, pCentis);
    if (!kOut.IsEmpty())
        kOut = "";
    kOut.Format("%02d:%02d:%02d", *pMinutes, *pSeconds, *pCentis);
}
MS2_REPLACE(0x141b70760, FUN_141b70760, 166, 0x9F509A13);

// @0x141b70810
void FUN_141b70810(unsigned nMs, CStringW& kOut)
{
    int nSeconds = nMs / 1000;
    int nHours = nSeconds / 3600;
    int nMinutes = (nSeconds / 60) % 60;
    int nRest = nSeconds % 60;
    kOut.Format(L"%02d:%02d:%02d", nHours, nMinutes, nRest);
}
MS2_REPLACE(0x141b70810, FUN_141b70810, 131, 0xAAF110A7);

// ---- duration text / material tinting ----
CStringW FUN_1409e97f0(int nId, const unsigned& nArg);                  // string table entry, one argument
CStringW FUN_1408116a0(int nId, const int& nArg);
CStringW FUN_140811740(int nId, const int& nArg1, const int& nArg2);
CStringW FUN_1412e7520(int nId, const int& nArg1, const int& nArg2, const int& nArg3);

// @0x141b708a0
// MS2-FUNCTIONAL: frame is 16 bytes larger than the exe (ternary temporaries)
CStringW FUN_141b708a0(unsigned nSeconds, bool bShowSeconds)
{
    if (nSeconds < 60) {
        CStringW kShort = FUN_1409e97f0(0x97b, nSeconds);
        return kShort;
    }
    if (nSeconds < 3600) {
        int nMinutes = nSeconds / 60;
        int nRest = nSeconds % 60;
        bool bHasRest = nRest != 0;
        CStringW kText = bHasRest ? FUN_140811740(0x97e, nMinutes, nRest) : FUN_1408116a0(0x97c, nMinutes);
        return kText;
    }
    int nHours = nSeconds / 3600;
    int nMinutes = (nSeconds / 60) % 60;
    int nRest = nSeconds % 60;
    CStringW kText = L"";
    if (!bShowSeconds || nRest == 0) {
        if (nMinutes == 0)
            kText = FUN_1408116a0(0x97d, nHours);
        else
            kText = FUN_140811740(0x97f, nHours, nMinutes);
    } else {
        kText = FUN_1412e7520(0x980, nHours, nMinutes, nRest);
    }
    return kText;
}

extern NiFixedString DAT_143ae5120;                                     // shader constant keys
extern NiFixedString DAT_143ae5128;
extern int DAT_143ae2b34;                                               // instanced rendering enabled
void FUN_14116d500(NiMaterialProperty* pMaterial, const Unk_Colc& kColor);
void FUN_141047ac0(NiObjectNET* pObj, const NiFixedString& kKey, float fValue);
unsigned FUN_140d96630(NiAVObject* pObj);                               // scene flags
void FUN_141568ec0(NiAVObject* pObj);
void FUN_1414d4c70(void* pObj, unsigned uFlags);

void FUN_141b70cb0(NiAVObject* pObj, float fValue, const Unk_Colc& kColor, float fEmissive);

// @0x141b70c50
void FUN_141b70c50(NiAVObject* pObj, float fValue, float fEmissive)
{
    Unk_Colc kGrey(0.78431f, 0.78431f, 0.78431f);
    FUN_141b70cb0(pObj, fValue, kGrey, fEmissive);
}
MS2_REPLACE(0x141b70c50, FUN_141b70c50, 87, 0xDAFF5EB1);

// @0x141b70cb0
// MS2-FUNCTIONAL: exe keeps the last callee result in an extra 8-byte slot (frame layout differs)
void FUN_141b70cb0(NiAVObject* pObj, float fValue, const Unk_Colc& kColor, float fEmissive)
{
    if (pObj == NULL) {
        MS2_ASSERT_AT(0x3ad, 0);
        return;
    }
    NiMaterialProperty* pMaterial = (NiMaterialProperty*)FUN_14098d8d0(&NiMaterialProperty::ms_RTTI, pObj->GetProperty(NiProperty::MATERIAL));
    if (pMaterial != NULL)
        FUN_14116d500(pMaterial, Unk_Colc(fEmissive, fEmissive, fEmissive));
    FUN_141047ac0(pObj, DAT_143ae5120, fValue);
    FUN_1410479a0(pObj, &DAT_143ae5128, kColor);
    if (DAT_143ae2b34 != 0) {
        if (!FUN_14028d470(fValue, 0.0f))
            FUN_141568ec0(pObj);
        else
            FUN_1414d4c70(pObj, FUN_140d96630(pObj) & 0xfffffff7);
    }
}

// ---- misc string / entity / scene helpers ----
struct Unk_UtilNameSrc;
struct Unk_UtilNameTable;
Unk_UtilNameTable* FUN_140ae1be0(Unk_UtilNameSrc* pSrc);
void FUN_140ae1f60(Unk_UtilNameTable* pTable, efd::utf8string& kOut);

// @0x141b70dd0
CStringA FUN_141b70dd0(Unk_UtilNameSrc* pSrc)
{
    if (pSrc == NULL)
        return CStringA("");
    efd::utf8string kName;
    FUN_140ae1f60(FUN_140ae1be0(pSrc), kName);
    return CStringA(kName.c_str());
}
MS2_REPLACE(0x141b70dd0, FUN_141b70dd0, 192, 0xADA3F07D);

CFileSystem* GetFileSystem();

// @0x141b70ea0
unsigned FUN_141b70ea0(const CStringA& kPath)
{
    std::string kName((LPCSTR)kPath);
    return GetFileSystem()->FUN_1403987d0(kName);
}
MS2_REPLACE(0x141b70ea0, FUN_141b70ea0, 168, 0x8E07B1D5);

// @0x141b70f50
bool FUN_141b70f50(const CStringW& kLeft, const CStringW& kRight)
{
    if (kLeft.CompareNoCase((LPCWSTR)kRight) == 0)
        return true;
    return false;
}
MS2_REPLACE(0x141b70f50, FUN_141b70f50, 54, 0x9623C308);

CStringW FUN_140f15bd0(const wchar_t* pszFormat, const int& nYear, const int& nMonth, const int& nDay, const int& nHour,
                       const int& nMinute, const int& nSecond);

// @0x141b70f90
void FUN_141b70f90(const CMsTime& kTime, const CStringW& kFormat, CStringW& kOut)
{
    int nSecond = kTime.GetSecond();
    int nMinute = kTime.GetMinute();
    int nHour = kTime.GetHour();
    int nDay = kTime.GetDay();
    int nMonth = kTime.GetMonth();
    int nYear = kTime.GetYear();
    kOut = FUN_140f15bd0((LPCWSTR)kFormat, nYear, nMonth, nDay, nHour, nMinute, nSecond);
}
MS2_REPLACE(0x141b70f90, FUN_141b70f90, 264, 0x35B5B258);

int FUN_1413faf90(wchar_t wc);

// @0x141b710a0
int FUN_141b710a0(unsigned short wc)
{
    if (wc >= 0x30 && wc <= 0x39)
        return 1;
    if (wc >= 0x41 && wc <= 0x5a)
        return 1;
    if (wc >= 0x61 && wc <= 0x7a)
        return 1;
    if (FUN_1413faf90(wc) != 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x141b710a0, FUN_141b710a0, 118, 0x42E751F1);

// ---- game object references ----
class Unk_UtilObject
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual bool GetProperty(unsigned uId, void* pOut);             // slot 5
    virtual void s6();
    virtual int GetKind();                                          // slot 7
};
class Unk_UtilHolder;
class Unk_UtilObjRef                                                // 8-byte reference to a game object
{
public:
    Unk_UtilObjRef(const Unk_UtilObjRef& kOther);                   // copy for by-value passing
    ~Unk_UtilObjRef();                                              // 0x140964870
    Unk_UtilObject* FUN_1409658c0() const;                          // operator->
    Unk_UtilObject* FUN_140965780() const;                          // raw object pointer (NULL when unset)
private:
    void* m_p;
};
class Unk_UtilHolderRef                                             // 8-byte reference to the holder
{
public:
    Unk_UtilHolderRef(Unk_UtilHolder* p);                           // 0x140963df0
    ~Unk_UtilHolderRef();                                           // 0x1409648b0
    Unk_UtilHolder* FUN_140965790() const;                          // get
    Unk_UtilHolder* FUN_140975bc0() const;                          // operator->
private:
    Unk_UtilHolder* m_p;
};
Unk_UtilObject* FUN_141706540(Unk_UtilHolder* pHolder);             // the holder's rider
Unk_UtilHolder* FUN_141b72360(const Unk_UtilObjRef& kRef);

// @0x141b71120
unsigned FUN_141b71120(Unk_UtilObjRef kRef)
{
    if (kRef.FUN_1409658c0()->GetKind() == 0x6200004)
        return 1;
    if (kRef.FUN_1409658c0()->GetKind() == 0x6200045) {
        Unk_UtilHolderRef kHolder(FUN_141b72360(kRef));
        if (kHolder.FUN_140965790() != NULL) {
            Unk_UtilObject* pRider = FUN_141706540(kHolder.FUN_140975bc0());
            if (pRider != NULL && pRider->GetKind() == 0x6200004)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE(0x141b71120, FUN_141b71120, 290, 0x8ACF42B0);

class Unk_UtilHudDlg { public: void FUN_1422cecb0(int nMode); bool FUN_1422bfca0(); };
class Unk_UtilHudPtr
{
public:
    ~Unk_UtilHudPtr();                                              // 0x140a58400
    void* FUN_140a58470();
    bool FUN_140d41080(int nNull);
    Unk_UtilHudDlg* FUN_140a584a0();
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
};
class Unk_UtilHudMgr { public: Unk_UtilHudPtr FUN_1422b0370(int n); };
Unk_UtilHudMgr* FUN_14025e7a0();

// @0x141b71250
// MS2-FUNCTIONAL: exe destroys the HUD handle with an explicit call and keeps no EH state slot
void FUN_141b71250(int nValue)
{
    if (FUN_14025e7a0() != NULL) {
        Unk_UtilHudPtr kHud = FUN_14025e7a0()->FUN_1422b0370(6);
        if (kHud.FUN_140a58470() != NULL)
            kHud.FUN_140a584a0()->FUN_1422cecb0(nValue != 0 ? 1 : 2);
    }
}

// @0x141b712e0
int FUN_141b712e0()
{
    if (FUN_14025e7a0() == NULL)
        return 0;
    Unk_UtilHudPtr kHud = FUN_14025e7a0()->FUN_1422b0370(6);
    if (kHud.FUN_140d41080(0))
        return 0;
    return kHud.FUN_140a584a0()->FUN_1422bfca0() != 0;
}

// ---- curve math ----
float FUN_141b72560(float fBase, float fExp);
float FUN_141b72600(float fBase, float fExp);
float FUN_141b725e0(float fValue);
float FUN_14096b1c0(float fValue);                                  // sqrtf
float FUN_140993fe0(const Unk_StreamPoint& kA, const Unk_StreamPoint& kB);   // dot product

// @0x141b71390
// MS2-FUNCTIONAL: temp slot order of the two power terms differs
Unk_StreamPoint FUN_141b71390(const Unk_StreamPoint& kStart, const Unk_StreamPoint& kControl, const Unk_StreamPoint& kEnd, float fT)
{
    if (kStart.FUN_140552690(kControl) || kEnd.FUN_140552690(kControl)) {
        Unk_StreamPoint kDelta = kEnd.FUN_140965c40(kStart);
        return kStart.FUN_14097fd50(kDelta.FUN_14097fc90(fT));
    } else {
        float fInverse = 1.0f - fT;
        float fT2 = FUN_141b72560(fT, 2.0f);
        float fS2 = FUN_141b72560(fInverse, 2.0f);
        Unk_StreamPoint kResult = kStart.FUN_14097fc90(fS2);
        kResult.FUN_140a4e560(FUN_1409ab5c0(2.0f, kControl).FUN_14097fc90(fT).FUN_14097fc90(1.0f - fT));
        kResult.FUN_140a4e560(kEnd.FUN_14097fc90(fT2));
        return kResult;
    }
}

// @0x141b71550
// MS2-FUNCTIONAL: float temporaries are scheduled differently in the arc-length term
float FUN_141b71550(const Unk_StreamPoint& kStart, const Unk_StreamPoint& kControl, const Unk_StreamPoint& kEnd)
{
    Unk_StreamPoint kA;
    Unk_StreamPoint kB;
    kA = kStart.FUN_140965c40(FUN_1409ab5c0(2.0f, kControl)).FUN_14097fd50(kEnd);
    kA = kStart.FUN_140965c40(FUN_1409ab5c0(2.0f, kControl)).FUN_14097fd50(kEnd);
    kB = FUN_1409ab5c0(2.0f, kControl).FUN_140965c40(FUN_1409ab5c0(2.0f, kStart));
    kB = FUN_1409ab5c0(2.0f, kControl).FUN_140965c40(FUN_1409ab5c0(2.0f, kStart));
    float fAA = FUN_140993fe0(kA, kA);
    float fA = (fAA + FUN_140993fe0(kA, kA)) * 4.0f;
    float fAB = FUN_140993fe0(kA, kB);
    float fB = (fAB + FUN_140993fe0(kA, kB)) * 4.0f;
    float fBB = FUN_140993fe0(kB, kB);
    float fC = fBB + FUN_140993fe0(kB, kB);
    float fSqrtAll = FUN_14096b1c0(fA + fB + fC);
    fSqrtAll = fSqrtAll * 2.0f;
    float fSqrtA = FUN_14096b1c0(fA);
    float fTermA = fA * 2.0f * fSqrtA;
    float fSqrtC = FUN_14096b1c0(fC);
    float fNumer = fTermA * fSqrtAll + fSqrtA * fB * (fSqrtAll - fSqrtC * 2.0f);
    float fDet = fC * 4.0f * fA - fB * fB;
    float fLog = FUN_141b725e0((fSqrtA * 2.0f + fB / fSqrtA + fSqrtAll) / (fB / fSqrtA + fSqrtC * 2.0f));
    return (fNumer + fDet * fLog) / (fTermA * 4.0f);
}

// ---- number / colour helpers ----
CStringW FUN_1406c6bd0(const wchar_t* pszFormat, const __int64& nArg);

// @0x141b71910
CStringW FUN_141b71910(__int64 nValue)
{
    return FUN_1406c6bd0(L"{0}", nValue);
}
MS2_REPLACE(0x141b71910, FUN_141b71910, 65, 0xA5DE623F);

// @0x141b71960
__int64 FUN_141b71960(const char* psz)
{
    if (psz != NULL)
        return _atoi64(psz);
    return 0;
}
MS2_REPLACE(0x141b71960, FUN_141b71960, 37, 0x77CC3CDD);

// @0x141b71990
CStringW FUN_141b71990(unsigned nValue)
{
    CStringW kText;
    kText.Format(L"%u", nValue);
    return kText;
}
MS2_REPLACE(0x141b71990, FUN_141b71990, 113, 0x5B004633);

// @0x141b71a10
int FUN_141b71a10(const char* psz)
{
    if (psz != NULL)
        return atoi(psz);
    return 0;
}
MS2_REPLACE(0x141b71a10, FUN_141b71a10, 37, 0xDC1CD1D0);

// @0x141b71a40
double FUN_141b71a40(int nValue)
{
    return (double)nValue;
}
MS2_REPLACE(0x141b71a40, FUN_141b71a40, 11, 0xFC13D90A);

// @0x141b71a60
// MS2-FUNCTIONAL: exe copies the divided colour through an out-of-line copy ctor (0x140a0a3a0)
void FUN_141b71a60(Unk_UtilFloat3* pColor)
{
    if (pColor->x > 1.0f || pColor->y > 1.0f || pColor->z > 1.0f)
        *pColor = pColor->FUN_141b723e0(255.0f);
    FUN_141b71a40(FUN_141b6df90(pColor));
}

// ---- scene / skin helpers ----
class Unk_UtilWorld;
class Unk_UtilPlayer;
Unk_UtilWorld* FUN_1403ed2d0();
Unk_UtilPlayer* FUN_141bd0cc0(Unk_UtilWorld* pWorld);
egf::Entity* FUN_14123c410(Unk_UtilPlayer* pPlayer);
extern NiRTTI DAT_143afafe0;
extern char DAT_143ae50f8;                                          // extra-data key of the skin tint
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);

// @0x141b71b00
NiObject* FUN_141b71b00()
{
    Unk_UtilPlayer* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == NULL)
        return NULL;
    NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410(pPlayer));
    if (pRoot != NULL) {
        NiFixedString kName("FA_Skin");
        return FUN_14098d8d0(&NiRenderObject::ms_RTTI, pRoot->GetObjectByName(kName));
    }
    return NULL;
}
MS2_REPLACE(0x141b71b00, FUN_141b71b00, 160, 0x8C42B0E0);

// @0x141b71bb0
NiObject* FUN_141b71bb0()
{
    NiObject* pSkin = FUN_141b71b00();
    if (pSkin != NULL)
        return FUN_14098d8d0(&DAT_143afafe0, FUN_141d17b40((NiObjectNET*)pSkin, &DAT_143ae50f8));
    return NULL;
}
MS2_REPLACE(0x141b71bb0, FUN_141b71bb0, 63, 0x4FF135C2);

// ---- item / scene flag helpers ----
struct Unk_ClientConfig;
class Unk_14025a620 { public: int FUN_14025a620(); };
struct Unk_ClientConfig { char m_pad_00[0x2b28]; Unk_14025a620 m_kLimit; };
Unk_ClientConfig* FUN_1401d3200();

// @0x141b71c00
int FUN_141b71c00(unsigned short nValue)
{
    int nLimit = FUN_1401d3200()->m_kLimit.FUN_14025a620();
    return (int)nValue >= nLimit ? 1 : 0;
}
MS2_REPLACE(0x141b71c00, FUN_141b71c00, 70, 0x478D9542);

// A range tuning record: +0x144 / +0x148 are the two factors of the attack-range estimate.
struct Unk_UtilRangeEntry { char m_pad_00[0x144]; float m_144; float m_148; };
class Unk_UtilRangeOwner;
class Unk_UtilRangeBook;
Unk_UtilRangeOwner* FUN_1413f9890();
Unk_UtilRangeEntry* FUN_140af7da0(Unk_UtilRangeOwner* pOwner);
Unk_UtilRangeBook* FUN_1413f9910();
Unk_UtilRangeEntry* FUN_14200aae0(Unk_UtilRangeBook* pBook, Unk_UtilRangeEntry* pEntry);
Unk_UtilRangeEntry* FUN_142008b80(Unk_UtilRangeEntry* pEntry);
float FUN_141b72510(const Unk_UtilRangeEntry* pInfo);
float FUN_141b724f0(const Unk_UtilRangeEntry* pInfo);

// @0x141b71c50
float FUN_141b71c50()
{
    Unk_UtilRangeEntry* pEntry = FUN_140af7da0(FUN_1413f9890());
    if (pEntry == NULL)
        return FLT_MAX;
    Unk_UtilRangeEntry* pRange = FUN_14200aae0(FUN_1413f9910(), pEntry);
    if (pRange == NULL)
        return FLT_MAX;
    Unk_UtilRangeEntry* pSize = FUN_142008b80(pRange);
    if (pSize == NULL)
        return FLT_MAX;
    float fScale = 10000.0f;
    float fWidth = FUN_141b72510(pSize);
    return fWidth * FUN_141b724f0(pSize) * fScale;
}

// @0x141b72510
float FUN_141b72510(const Unk_UtilRangeEntry* pInfo)
{
    return pInfo->m_144;
}
MS2_REPLACE(0x141b72510, FUN_141b72510, 19, 0x14872315);

// @0x141b724f0
float FUN_141b724f0(const Unk_UtilRangeEntry* pInfo)
{
    return pInfo->m_148;
}
MS2_REPLACE(0x141b724f0, FUN_141b724f0, 19, 0x44AEFC71);

// ---- scene walkers ----
extern NiRTTI DAT_143afb000;                                        // NiStringExtraData tag RTTI
extern char DAT_143ae51b8;                                          // tag extra-data key
extern char DAT_143ae50e8;                                          // tag text that excludes a branch
efd::FixedString* FUN_141168130(NiObject* pStringData);
efd::FixedString* FUN_1409a8b90(NiNode* pNode);
void FUN_1414d3930(NiRenderObject* pObj);
void FUN_1414d38b0(NiRenderObject* pObj, const Unk_Colc& kColor);
void FUN_1414d37a0(NiRenderObject* pObj, unsigned uColor);

// @0x141b71d10
// MS2-FUNCTIONAL: exe reuses one pointer slot for the tag/render/node casts; frame is 16 bytes smaller
void FUN_141b71d10(NiAVObject* pRoot, bool bEnable, const Unk_Colc& kColor)
{
    if (pRoot == NULL)
        return;
    Unk_SceneWalker kWalk(pRoot);
    while (kWalk.FUN_1414d3ff0() != 0) {
        NiAVObject* pCurrent = kWalk.FUN_1414d4a50();
        NiObject* pTag = FUN_14098d8d0(&DAT_143afb000, FUN_141d17b40(pCurrent, &DAT_143ae51b8));
        if (pTag != NULL && FUN_141168130(pTag)->ContainsNoCase(FUN_142087e50(&DAT_143ae50e8)))
            continue;
        NiRenderObject* pRender = (NiRenderObject*)FUN_14098d8d0(&NiRenderObject::ms_RTTI, pCurrent);
        if (pRender != NULL) {
            if (!bEnable)
                FUN_1414d3930(pRender);
            else
                FUN_1414d38b0(pRender, kColor);
        }
        NiNode* pNode = (NiNode*)FUN_14098d8d0(&NiNode::ms_RTTI, pCurrent);
        if (pNode != NULL)
            kWalk.FUN_14098d6d0(pNode);
    }
}

// @0x141b71f20
// MS2-FUNCTIONAL: exe reuses one pointer slot for the tag/render/node casts; frame is 16 bytes smaller
void FUN_141b71f20(NiAVObject* pRoot, bool bEnable, unsigned uColor, bool bSkipEffectRoot)
{
    if (pRoot == NULL)
        return;
    Unk_SceneWalker kWalk(pRoot);
    while (kWalk.FUN_1414d3ff0() != 0) {
        NiAVObject* pCurrent = kWalk.FUN_1414d4a50();
        NiObject* pTag = FUN_14098d8d0(&DAT_143afb000, FUN_141d17b40(pCurrent, &DAT_143ae51b8));
        if (pTag != NULL && FUN_141168130(pTag)->ContainsNoCase(FUN_142087e50(&DAT_143ae50e8)))
            continue;
        NiRenderObject* pRender = (NiRenderObject*)FUN_14098d8d0(&NiRenderObject::ms_RTTI, pCurrent);
        if (pRender != NULL) {
            if (!bEnable)
                FUN_1414d3930(pRender);
            else
                FUN_1414d37a0(pRender, uColor);
        }
        NiNode* pNode = (NiNode*)FUN_14098d8d0(&NiNode::ms_RTTI, pCurrent);
        if (pNode != NULL) {
            if (bSkipEffectRoot && FUN_1409a8b90(pNode)->EqualsNoCase("Effect Root"))
                continue;
            kWalk.FUN_14098d6d0(pNode);
        }
    }
}

// Smart pointer to an entity (8 bytes).
class Unk_UtilEntityRef
{
public:
    Unk_UtilEntityRef(egf::Entity* pEntity);
    ~Unk_UtilEntityRef();                                           // 0x1408a8720
    bool FUN_1408b70b0(int nNull) const;                            // == NULL
    egf::Entity* FUN_1408a9090() const;                             // operator->
private:
    egf::Entity* m_p;
};

// @0x141b71e70
void FUN_141b71e70(egf::EntityID id, bool bEnable, unsigned uColor, bool bSkipEffectRoot)
{
    Unk_UtilEntityRef kEntity(FUN_1411cf440(FUN_1409670f0(), id));
    if (kEntity.FUN_1408b70b0(0))
        return;
    NiAVObject* pRoot = FUN_141b6efc0(kEntity.FUN_1408a9090());
    if (pRoot != NULL)
        FUN_141b71f20(pRoot, bEnable, uColor, bSkipEffectRoot);
}
MS2_REPLACE(0x141b71e70, FUN_141b71e70, 168, 0xFEE15438);

// ---- string table text ----
class Unk_1401a9d70 { public: CStringW FUN_141811980(int nCategory, int nId); };
Unk_1401a9d70* FUN_1401a9d70();
class Unk_UtilTextFilter
{
public:
    void FUN_1416fbc20(CStringW& kText, __int64 nValue);
    void FUN_1416fbda0(CStringW& kText, int nValue);
};
Unk_UtilTextFilter* FUN_1403b4750();

// @0x141b720b0
CStringW FUN_141b720b0(int nId, __int64 nValue)
{
    CStringW kText = FUN_1401a9d70()->FUN_141811980(0x16, nId);
    if (FUN_1403b4750() != NULL)
        FUN_1403b4750()->FUN_1416fbc20(kText, nValue);
    return kText;
}
MS2_REPLACE(0x141b720b0, FUN_141b720b0, 146, 0xA5874D90);

// @0x141b72150
CStringW FUN_141b72150(int nId, int nValue)
{
    CStringW kText = FUN_1401a9d70()->FUN_141811980(0x16, nId);
    if (FUN_1403b4750() != NULL)
        FUN_1403b4750()->FUN_1416fbda0(kText, nValue);
    return kText;
}
MS2_REPLACE(0x141b72150, FUN_141b72150, 146, 0x145A9D20);

// ---- debug-log scope ----
class Unk_UtilLogScope
{
public:
    Unk_UtilLogScope(CStringA kTag);                                // 0x141b721f0
    ~Unk_UtilLogScope();                                            // 0x141b722b0
private:
    DWORD m_dwThread;
    CStringA m_kTag;
};
MS2_CHECK_SIZE(Unk_UtilLogScope, 0x10);

// @0x141b721f0
Unk_UtilLogScope::Unk_UtilLogScope(CStringA kTag)
{
    if (FUN_140a44830() == NULL)
        return;
    m_dwThread = GetCurrentThreadId();
    m_kTag = kTag;
    FUN_140a44830()->FUN_140a43750(m_dwThread, m_kTag);
}

// @0x141b722b0
Unk_UtilLogScope::~Unk_UtilLogScope()
{
    if (FUN_140a44830() == NULL)
        return;
    FUN_140a44830()->FUN_140a437d0(m_dwThread);
}

// @0x141b72310
int FUN_141b72310(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
    switch (uMsg) {
    case BFFM_INITIALIZED:
        SendMessageA(hWnd, BFFM_SETSELECTIONA, TRUE, lpData);
        break;
    }
    return 0;
}
MS2_REPLACE(0x141b72310, FUN_141b72310, 74, 0xEE31BF70);

// @0x141b72360
Unk_UtilHolder* FUN_141b72360(const Unk_UtilObjRef& kRef)
{
    Unk_UtilHolder* pHolder = NULL;
    if ((bool)kRef.FUN_140965780() && kRef.FUN_1409658c0()->GetProperty(0x6200045, &pHolder))
        return pHolder;
    else
        return NULL;
}

// @0x141b723e0
// MS2-FUNCTIONAL: exe copies the 12-byte value through plain locals without a security cookie
Unk_UtilFloat3 Unk_UtilFloat3::FUN_141b723e0(float fDivisor) const
{
    Unk_UtilFloat3 kResult = *this;
    kResult.x = kResult.x / fDivisor;
    kResult.y = kResult.y / fDivisor;
    kResult.z = kResult.z / fDivisor;
    return kResult;
}
MS2_REPLACE_METHOD(0x141b723e0, Unk_UtilFloat3, FUN_141b723e0, 124, 0x629791A5);

// @0x141b72460
// MS2-FUNCTIONAL: exe reads the NiColorA member inline; the header only offers the by-value GetValue()
float FUN_141b72460(NiObject* pColorData)
{
    return ((NiColorExtraData*)pColorData)->GetValue().b;
}
MS2_REPLACE(0x141b72460, FUN_141b72460, 16, 0x4C93A5B6);

// @0x141b72470
// MS2-FUNCTIONAL: exe reads the NiColorA member inline; the header only offers the by-value GetValue()
float FUN_141b72470(NiObject* pColorData)
{
    return ((NiColorExtraData*)pColorData)->GetValue().g;
}
MS2_REPLACE(0x141b72470, FUN_141b72470, 16, 0x5463A882);

bool FUN_142087fc0(const NiFixedString& kKey);                      // key is not empty

// @0x141b72480
float FUN_141b72480(NiControllerSequence* pSeq, const NiFixedString& kKey)
{
    if (!FUN_142087fc0(kKey)) {
        return -FLT_MAX;
    } else {
        NiTextKeyMatch kMatch(kKey);
        return pSeq->GetKeyTimeAt(&kMatch);
    }
}

// @0x141b72530
// MS2-FUNCTIONAL: exe reads the NiColorA member inline; the header only offers the by-value GetValue()
float FUN_141b72530(NiObject* pColorData)
{
    return ((NiColorExtraData*)pColorData)->GetValue().r;
}
MS2_REPLACE(0x141b72530, FUN_141b72530, 16, 0x3C5A885E);

// @0x141b72540
// MS2-FUNCTIONAL: exe calls the out-of-line NiPointer accessor 0x140998eb0 on the +0x38 member
NiSequenceData* FUN_141b72540(NiControllerSequence* pSeq)
{
    return pSeq->GetSequenceData();
}
MS2_REPLACE(0x141b72540, FUN_141b72540, 31, 0x4931477F);

// @0x141b72560
float FUN_141b72560(float fBase, float fExp)
{
    return FUN_141b72600(fBase, fExp);
}
MS2_REPLACE(0x141b72560, FUN_141b72560, 38, 0x09A6CEAF);

// @0x141b72590
void Unk_UtilErrorDialog::SetKText(CStringA kText)
{
    m_kText = kText;
}
MS2_REPLACE_METHOD(0x141b72590, Unk_UtilErrorDialog, SetKText, 65, 0xD5D7D3A4);

// @0x141b725e0
// MS2-FUNCTIONAL: exe imports logf from the CRT DLL; this build links it statically
float FUN_141b725e0(float fValue)
{
    return logf(fValue);
}
MS2_REPLACE(0x141b725e0, FUN_141b725e0, 27, 0x3F5FEE04);

// @0x141b72600
// MS2-FUNCTIONAL: exe imports powf from the CRT DLL; this build links it statically
float FUN_141b72600(float fBase, float fExp)
{
    return powf(fBase, fExp);
}
MS2_REPLACE(0x141b72600, FUN_141b72600, 39, 0xECCEDFB2);
