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
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/crashmanagercli.h"
#include "ms2/client/ms2/bigdatalogsystem.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/asmousecursor.h"
#include "ms2/client/ms2/ridee.h"  // C3: was a local member view
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxVec3.h>       // C3: NxVec3 (was Unk_UtilNxVec3)
#pragma pop_macro("max")
#pragma pop_macro("min")
#include <efd/EEMath.h>   // C3: efd::Clamp was FUN_140a17940
#include <efd/File.h>
#include <efd/Matrix3.h>
#include <efd/ParseHelper.h>
#include <NiFloatsExtraData.h>
#include <NiMatrix3.h>
#include "ms2/ms2format.h"
#include "ms2/placeholder/formatstringid.h"
#include "ms2/placeholder/blockformat.h"   // BlockFormat<...> over FUN_14028dee0 (commonutil.cpp)
//
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
#include "ms2/placeholder/ms2color.h"
#include "ms2/client/ms2/memorydepletiondlg.h"
#include <efd/Win32/Win32PlatformService.h>  // C3: efd::Win32PlatformService::GetWindowRef
#include "ms2/commonfiles/os.h"
#include <direct.h>
// The exe links _mkdir statically (0x1420b1a80): redeclare it without dllimport
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winconsistent-dllimport"
#else
#pragma warning(push)
#pragma warning(disable : 4273)  // inconsistent dll linkage: intended
#endif
extern "C" int __cdecl _mkdir(const char* _Path);
#if defined(__clang__)
#pragma clang diagnostic pop
#else
#pragma warning(pop)
#endif
class Unk_AvModeSvc;
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
namespace ecr { class RenderService; }

// ---- externs used by the helpers ----
extern int DAT_143af7d44;                                           // "out of memory already reported"
extern int DAT_143ab0248;                                           // silent mode (no dialog)
extern const wchar_t DAT_142ff376c[];                               // path separator suffix

// The global logger object behind 0x140d8ee90 (category, message).

// The debug-log singleton behind 0x140a44830.

// The global out-of-memory report dialog (DAT_143af7e00, a CDialog).
class Unk_UtilErrorDialog : public CMemoryDepletionDlg
{
public:
    void SetKText(CStringA kText);
};
extern CMemoryDepletionDlg DAT_143af7e00;

CStringA FUN_14028dc80(int nStringId);                              // UI string table (ANSI)
CStringW GetStringCommon(int nStringId);                              // UI string table (wide)
int FUN_141b6fcf0(const CStringW& kText, const CStringW& kTitle, unsigned nFlags);   // message box + quit prompt
CStringW FUN_14016a730(const char* pszAnsi, int nCodePage);        // ANSI -> wide conversion
CStringA FUN_14016a600(const wchar_t* pszWide, int nCodePage);       // wide -> ANSI conversion
int FUN_141b72310(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData);   // BrowseForFolder callback
void* FUN_140aadf80();

int FUN_141b6fd90(size_t nSize);                                   // new handler (reports size 3)

// ---- scene / entity helpers ----
extern NiFixedString DAT_143ae50c8, DAT_143ae50d0, DAT_143ae50d8;            // NiFixedString keys of the three colour slots
extern NiFixedString DAT_143ae5140;                                 // float extra-data key
extern NiFixedString DAT_143ae5200;                                          // default material name
class MS2StandardMaterial { public: static const NiRTTI ms_RTTI; };
struct Unk_Colc { float x, y, z; };   // an rgb view; its out-of-line ctor 0x140a56db0 is Unk_Vec3Cli(float, float, float)

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);              // 0x14098cb80
    ~Unk_NodeQueue();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
    void AddChildren(NiNode* pNode);                // queue the children of a node
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28;
};
void* FUN_1414d3ff0(void* pQueue);                                  // number of pending nodes
struct Unk_OlpList;
// 0x1414d4a50 = CAtlList<NiAVObject*>::RemoveHead (ms2outlinepreprocessor.cpp)
typedef Unk_NodeQueue Unk_SceneWalker;   // C3: was a local stand-in for Unk_NodeQueue
MS2_CHECK_SIZE(Unk_SceneWalker, 0x30);

class Unk_AvModeSvc* GetOptimizer();   // C3: was GetOptimizer
class COptimizer   // C3: member view for the former free stand-ins
{
public:
    int FUN_14109a9d0();
};
void FUN_1410479a0(NiObjectNET* pObj, const NiFixedString& kKey, const NiColor& kValue);   // set a shader constant
class Unk_CubeKind   // C3: member view for the former free stand-ins
{
public:
    int FUN_140ef4dd0();
};
// The exe's out-of-line copies of the inline NiColorExtraData::GetRed/GetGreen/GetBlue and
// NiControllerSequence::GetSequenceData accessors.
class Unk_UtilColorData : public NiColorExtraData
{
public:
    float FUN_141b72530() const;                                    // GetRed
    float FUN_141b72470() const;                                    // GetGreen
    float FUN_141b72460() const;                                    // GetBlue
};
class Unk_UtilSequence : public NiControllerSequence
{
public:
    NiSequenceData* FUN_141b72540() const;                          // GetSequenceData
};
float FUN_141b72480(NiControllerSequence* pSeq, const NiFixedString& kKey);   // text key time (-FLT_MAX if unknown)
bool FUN_14028d470(float fA, float fB);                             // float equality

// NiTransform layout: rotation, translation, scale.
struct Unk_UtilTransform
{
    Unk_NiMatrix3 m_kRotate;                                        // +0x00
    NiPoint3 m_kTranslate;                                          // +0x24
    float m_fScale;                                                 // +0x30
};
MS2_CHECK_SIZE(Unk_UtilTransform, 0x34);
int FUN_14028c3e0(const CStringA& kText, CAtlArray<CStringA>& arrOut, const char* pszDelim, int nMax);
class EntityWorldManager { public: egf::Entity* FindEntity(const egf::EntityID& id); };
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
struct Unk_UtilFloat3
{
    float x, y, z;
};
struct Unk_UtilUInt3 { unsigned x, y, z; };

// @0x141b6db40
int FUN_141b6db40(size_t nSize)
{
    if (DAT_143af7d44 != 0)
        return 0;
    if (TSingleton<CBigDataLogSystem>::GetInstance() != 0) {
        if (nSize == 1) {
            CStringA kMessage("bad_alloc physx");
            CStringA kCategory("memory");
            TSingleton<CBigDataLogSystem>::GetInstance()->SendLog(kCategory, kMessage);
        } else if (nSize == 2) {
            CStringA kMessage("bad_alloc cef");
            CStringA kCategory("memory");
            TSingleton<CBigDataLogSystem>::GetInstance()->SendLog(kCategory, kMessage);
        } else {
            CStringA kMessage("bad_alloc others");
            CStringA kCategory("memory");
            TSingleton<CBigDataLogSystem>::GetInstance()->SendLog(kCategory, kMessage);
        }
    }
    DAT_143af7d44 = 1;
    if (DAT_143ab0248 == 0) {
        DAT_143af7e00.FUN_140d53570(FUN_14028dc80(0xb22));
        reinterpret_cast<Unk_UtilErrorDialog&>(DAT_143af7e00).SetKText(FUN_14028dc80(0xb24));
        if (DAT_143af7e00.DoModal() == -1) {
            FUN_141b6fcf0(GetStringCommon(0xb24), L"Error", 0x10);
        }
    } else {
        FUN_141b6fcf0(GetStringCommon(0xb24), L"Error", 0x10);
    }
    if (nSize == 2)
        return 0;
    return 0;
}

// @0x141b6de20
void FUN_141b6de20()
{
    AfxSetNewHandler(FUN_141b6fd90);
    if (TSingleton<CrashManagerCli>::GetInstance() != 0) {
        TSingleton<CrashManagerCli>::GetInstance()->SetCrashLogEntry(GetCurrentThreadId(), CStringA(""));
    }
}
MS2_REPLACE(0x141b6de20, FUN_141b6de20, 118, 0x4043FAA8);

// @0x141b6dea0
NiColor FUN_141b6dea0(unsigned uColor)
{
    float fScale = 0.003921569f;
    float fR = 0.003921569f * (float)(BYTE)(uColor >> 16);
    float fG = 0.003921569f * (float)(BYTE)(uColor >> 8);
    float fB = 0.003921569f * (float)(BYTE)uColor;
    float fA = 0.003921569f * (float)(BYTE)(uColor >> 24);
    NiColor vColor(fR, fG, fB);
    return vColor;
}
MS2_REPLACE(0x141b6dea0, FUN_141b6dea0, 224, 0xF622B07E);

// @0x141b6df90
unsigned FUN_141b6df90(const Unk_UtilFloat3* pColor)
{
    return MS2Color(pColor->x, pColor->y, pColor->z, 1.0f).operator unsigned();
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
Vector3 FUN_141b6e070(const Unk_UtilFloat3* pVec)
{
    Vector3 vCopy;
    vCopy.x = pVec->x;
    vCopy.y = pVec->y;
    vCopy.z = pVec->z;
    return vCopy;
}
MS2_REPLACE(0x141b6e070, FUN_141b6e070, 105, 0xAE2F521A);

// @0x141b6e0e0
NxVec3 FUN_141b6e0e0(const efd::Point3& kVec)
{
    NxVec3 vCopy;
    vCopy.x = kVec.x;
    vCopy.y = kVec.y;
    vCopy.z = kVec.z;
    return vCopy;
}
MS2_REPLACE(0x141b6e0e0, FUN_141b6e0e0, 96, 0x9AD7DDE3);

// @0x141b6e150
Vector3 FUN_141b6e150(const Unk_UtilFloat3* pVec)
{
    Vector3 vCopy;
    vCopy.x = pVec->x;
    vCopy.y = pVec->y;
    vCopy.z = pVec->z;
    return vCopy;
}
MS2_REPLACE(0x141b6e150, FUN_141b6e150, 105, 0xB6F3C78B);

// @0x141b6e1c0
CStringA FUN_141b6e1c0(const CStringA& kInitialDir, LPCSTR pszFilter, const CStringA& kDefaultFile)
{
    char szFile[MAX_PATH] = { 0 };
    HWND hWndOwner = ((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef();
    if (!kDefaultFile.IsEmpty())
        strcpy_s(szFile, MAX_PATH, (LPCSTR)kDefaultFile);
    OPENFILENAMEA ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWndOwner;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = pszFilter;
    ofn.nFilterIndex = 0;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = (LPCSTR)kInitialDir;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
    CStringA kResult;
    if (GetOpenFileNameA(&ofn) == 1)
        kResult = ofn.lpstrFile;
    return kResult;
}

// @0x141b6e360
CStringW FUN_141b6e360(const CStringW& kInitialDir, LPCWSTR pszFilter, const CStringW& kDefaultFile)
{
    wchar_t szFile[MAX_PATH] = { 0 };
    HWND hWndOwner = ((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef();
    if (!kDefaultFile.IsEmpty())
        wcscpy_s(szFile, MAX_PATH, (LPCWSTR)kDefaultFile);
    OPENFILENAMEW ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWndOwner;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = pszFilter;
    ofn.nFilterIndex = 0;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
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
CStringA FUN_141b6e560(const CStringA& kInitialDir, LPCSTR pszFilter, const CStringA& kDefaultFile)
{
    HWND hWndOwner = ((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef();
    char szFile[MAX_PATH] = { 0 };
    strcpy_s(szFile, MAX_PATH, (LPCSTR)kDefaultFile);
    OPENFILENAMEA ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWndOwner;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = pszFilter;
    ofn.nFilterIndex = 0;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = (LPCSTR)kInitialDir;
    ofn.Flags = OFN_OVERWRITEPROMPT | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;   // 0x180a, as the exe
    CStringA kResult;
    if (GetSaveFileNameA(&ofn) == 1)
        kResult = ofn.lpstrFile;
    return kResult;
}

// @0x141b6e6f0
CStringW FUN_141b6e6f0(const CStringW& kInitialDir, LPCWSTR pszFilter, const CStringW& kDefaultFile)
{
    HWND hWndOwner = ((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef();
    wchar_t szFile[MAX_PATH] = { 0 };
    wcscpy_s(szFile, MAX_PATH, (LPCWSTR)kDefaultFile);
    OPENFILENAMEW ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWndOwner;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = pszFilter;
    ofn.nFilterIndex = 0;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = (LPCWSTR)kInitialDir;
    ofn.Flags = OFN_OVERWRITEPROMPT | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;   // 0x180a, as the exe
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
CStringW BrowseForFolder(const CStringW& kStartPath)
{
    wchar_t szPath[MAX_PATH] = { 0 };
    BROWSEINFOW bi = { 0 };
    lstrcpyW(szPath, (LPCWSTR)kStartPath);
    PathRemoveBackslashW(szPath);
    bi.hwndOwner = ((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef();
    bi.pszDisplayName = szPath;
    bi.lpszTitle = L"\uD3F4\uB354\uB97C \uC120\uD0DD\uD558\uC138\uC694";
    bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT | BIF_EDITBOX | BIF_NEWDIALOGSTYLE;   // 0x55
    bi.lpfn = FUN_141b72310;
    bi.lParam = (LPARAM)szPath;
    LPITEMIDLIST pidl = SHBrowseForFolderW(&bi);
    if (SHGetPathFromIDListW(pidl, szPath)) {
        return CStringW(szPath) + L"\\";
    } else {
        return kStartPath;
    }
}

// @0x141b6e8e0
CStringA FUN_141b6e8e0(const CStringA& kStartPath)
{
    CStringW kWidePath = FUN_14016a730(kStartPath, 0);
    return FUN_14016a600(BrowseForFolder(kWidePath), 0);
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
CStringA FUN_141b6eb80(const CStringA& kPath)
{
    CStringW kWidePath = FUN_14016a730(kPath, 0);
    return FUN_14016a600(FUN_141b6ec30(kWidePath), 0);
}

// @0x141b6ed00
CStringA FUN_141b6ed00(const CStringA& kPath)
{
    return FUN_141b6eb80(kPath);
}
MS2_REPLACE(0x141b6ed00, FUN_141b6ed00, 58, 0xA43FC783);

// @0x141b6ed40
void ParseVector3(const CStringA& kText, Vector3* pOut)
{
    CAtlArray<CStringA> arrParts;
    if (FUN_14028c3e0(kText, arrParts, ",", 3) == 0)
        return;
    pOut->x = (float)atof(arrParts[(size_t)0]);
    pOut->y = (float)atof(arrParts[(size_t)1]);
    pOut->z = (float)atof(arrParts[(size_t)2]);
}
MS2_REPLACE(0x141b6ed40, ParseVector3, 233, 0x97815FBE);

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
    egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FindEntity(id);
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
void FUN_141b6f000(NiAVObject* pRoot, int nSlot, const Unk_Colc& kValue)
{
    if (pRoot == NULL)
        return;
    const char* pszKey = NULL;
    if (((class COptimizer*)(void*)(((void*)GetOptimizer())))->FUN_14109a9d0() == 0) {
        if (nSlot == 0)
            pszKey = DAT_143ae50c8;
        else if (nSlot == 1)
            pszKey = DAT_143ae50d0;
        else
            pszKey = DAT_143ae50d8;
    }
    Unk_SceneWalker kWalker((NiAVObject*)(pRoot));
    while (NiAVObject* pNode = kWalker.Next(true)) {
        NiRenderObject* pRender = (NiRenderObject*)NiObject::DynamicCast(&NiRenderObject::ms_RTTI, (class NiObject const*)(pNode));
        if (pRender != NULL) {
            NiMaterial* pMaterial = ((class NiMaterial*)((class NiRenderObject*)(class NiRenderObject*)(pRender))->GetActiveMaterial());
            if (pMaterial != NULL) {
                if (((class NiMaterial*)(class NiMaterial const*)(pMaterial))->GetName() != DAT_143ae5200) {
                    NiObject* pTexturing = NiObject::DynamicCast(&NiTexturingProperty::ms_RTTI, (class NiObject const*)(pRender->GetProperty(NiProperty::TEXTURING)));
                    if (pTexturing == NULL)
                        continue;
                    if (((class COptimizer*)(void*)(((void*)GetOptimizer())))->FUN_14109a9d0() != 0) {
                        switch (nSlot) {
                        case 0: FUN_1410479a0(pRender, DAT_143ae50c8, reinterpret_cast<const NiColor&>(kValue)); break;
                        case 1: FUN_1410479a0(pRender, DAT_143ae50d0, reinterpret_cast<const NiColor&>(kValue)); break;
                        default: FUN_1410479a0(pRender, DAT_143ae50d8, reinterpret_cast<const NiColor&>(kValue)); break;
                        }
                    } else {
                        NiFixedString kName(pszKey);
                        FUN_1410479a0(pRender, kName, reinterpret_cast<const NiColor&>(kValue));
                    }
                }
            }
        }
    }
}

// @0x141b6f220
void FUN_141b6f220(NiAVObject* pRoot, int nSlot, const Unk_Colc& kValue)
{
    if (pRoot == NULL)
        return;
    const char* pszKey = NULL;
    if (((class COptimizer*)(void*)(((void*)GetOptimizer())))->FUN_14109a9d0() == 0) {
        if (nSlot == 0)
            pszKey = DAT_143ae50c8;
        else if (nSlot == 1)
            pszKey = DAT_143ae50d0;
        else
            pszKey = DAT_143ae50d8;
    }
    Unk_SceneWalker kWalker((NiAVObject*)(pRoot));
    while (NiAVObject* pNode = kWalker.Next(true)) {
        NiRenderObject* pRender = (NiRenderObject*)NiObject::DynamicCast(&NiRenderObject::ms_RTTI, (class NiObject const*)(pNode));
        if (pRender != NULL) {
            void* pInfo = ((void*)NiMaterial::DynamicCast(&MS2StandardMaterial::ms_RTTI, ((class NiMaterial*)((class NiRenderObject*)(class NiRenderObject*)(pRender))->GetActiveMaterial())));
            if (pInfo != NULL && ((class Unk_CubeKind*)(void*)(pInfo))->FUN_140ef4dd0() == 2) {
                NiObject* pTexturing = NiObject::DynamicCast(&NiTexturingProperty::ms_RTTI, (class NiObject const*)(pRender->GetProperty(NiProperty::TEXTURING)));
                if (pTexturing == NULL)
                    continue;
                if (((class COptimizer*)(void*)(((void*)GetOptimizer())))->FUN_14109a9d0() != 0) {
                    switch (nSlot) {
                    case 0: FUN_1410479a0(pRender, DAT_143ae50c8, reinterpret_cast<const NiColor&>(kValue)); break;
                    case 1: FUN_1410479a0(pRender, DAT_143ae50d0, reinterpret_cast<const NiColor&>(kValue)); break;
                    default: FUN_1410479a0(pRender, DAT_143ae50d8, reinterpret_cast<const NiColor&>(kValue)); break;
                    }
                } else {
                    NiFixedString kName(pszKey);
                    FUN_1410479a0(pRender, kName, reinterpret_cast<const NiColor&>(kValue));
                }
            }
        }
    }
}

// @0x141b6f440
int FUN_141b6f440(NiAVObject* pRoot, int nSlot, Unk_UtilFloat3* pOut)
{
    if (pRoot == NULL)
        return 0;
    const char* pszKey = NULL;
    if (((class COptimizer*)(void*)(((void*)GetOptimizer())))->FUN_14109a9d0() == 0) {
        if (nSlot == 0)
            pszKey = DAT_143ae50c8;
        else if (nSlot == 1)
            pszKey = DAT_143ae50d0;
        else
            pszKey = DAT_143ae50d8;
    }
    Unk_SceneWalker kWalker((NiAVObject*)(pRoot));
    NiAVObject* pNode;
    while ((pNode = kWalker.Next(true)) != NULL) {
        NiRenderObject* pRender = (NiRenderObject*)NiObject::DynamicCast(&NiRenderObject::ms_RTTI, (class NiObject const*)(pNode));
        if (pRender != NULL) {
        if (((class NiMaterial*)(class NiMaterial const*)(((class NiMaterial*)((class NiRenderObject*)(class NiRenderObject*)(pRender))->GetActiveMaterial())))->GetName() == DAT_143ae5200)
            continue;
        NiObject* pColor = NULL;
        if (((class COptimizer*)(void*)(((void*)GetOptimizer())))->FUN_14109a9d0() != 0) {
            switch (nSlot) {
            case 0: pColor = NiObject::DynamicCast(&NiColorExtraData::ms_RTTI, (class NiObject const*)(((class NiObject*)((class NiObjectNET*)(class NiObjectNET*)(pRender))->GetExtraData(*(class NiFixedString const*)(&DAT_143ae50c8))))); break;
            case 1: pColor = NiObject::DynamicCast(&NiColorExtraData::ms_RTTI, (class NiObject const*)(((class NiObject*)((class NiObjectNET*)(class NiObjectNET*)(pRender))->GetExtraData(*(class NiFixedString const*)(&DAT_143ae50d0))))); break;
            default: pColor = NiObject::DynamicCast(&NiColorExtraData::ms_RTTI, (class NiObject const*)(((class NiObject*)((class NiObjectNET*)(class NiObjectNET*)(pRender))->GetExtraData(*(class NiFixedString const*)(&DAT_143ae50d8))))); break;
            }
        } else {
            NiFixedString kName(pszKey);
            pColor = NiObject::DynamicCast(&NiColorExtraData::ms_RTTI, (class NiObject const*)(((class NiObject*)((class NiObjectNET*)(class NiObjectNET*)(pRender))->GetExtraData(*(class NiFixedString const*)(&kName)))));
        }
        if (pColor != NULL) {
            float fR = ((Unk_UtilColorData*)pColor)->FUN_141b72530();
            float fG = ((Unk_UtilColorData*)pColor)->FUN_141b72470();
            float fB = ((Unk_UtilColorData*)pColor)->FUN_141b72460();
            pOut->x = fR;
            pOut->y = fG;
            pOut->z = fB;
            return 1;
        }
        }
    }
    return 0;
}

// @0x141b6f700
float GetEntityAlpha(const egf::EntityID& rId)
{
    NiAVObject* pScene = FUN_141b6ef70(rId);
    float fAlpha = 0.0f;
    if (pScene != NULL) {
        Unk_SceneWalker kWalker((NiAVObject*)(pScene));
        while (NiAVObject* pNode = kWalker.Next(true)) {
            NiObject* pMaterial = NiObject::DynamicCast(&NiMaterialProperty::ms_RTTI, (class NiObject const*)(pNode->GetProperty(NiProperty::MATERIAL)));
            if (pMaterial != NULL)
                return ((NiMaterialProperty*)pMaterial)->GetAlpha();
        }
    }
    return fAlpha;
}
MS2_REPLACE(0x141b6f700, GetEntityAlpha, 227, 0x4765F8EE);

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
    egmAnimation::AnimationService* pService = egf::g_bapiContext.GetSystemServiceAs<egmAnimation::AnimationService>();
    return pService;
}
MS2_REPLACE(0x141b6f910, FUN_141b6f910, 31, 0x80477666);

// @0x141b6f940
Unk_Vec3Cli BrightenColor(const Unk_UtilFloat3* pColor)
{
    return Unk_Vec3Cli(efd::Min<float>(pColor->x * 1.3f, 1.0f), efd::Min<float>(pColor->y * 1.3f, 1.0f), efd::Min<float>(pColor->z * 1.3f, 1.0f));
}

// @0x141b6fa10
Unk_Vec3Cli DarkenColor(const Unk_UtilFloat3* pColor)
{
    return Unk_Vec3Cli(pColor->x * 0.7f, pColor->y * 0.7f, pColor->z * 0.7f);
}
MS2_REPLACE(0x141b6fa10, DarkenColor, 108, 0x2E8B2085);

// @0x141b6fa90
bool HasAnimation(const egf::EntityID& id, const efd::utf8string& kName)
{
    return FUN_141b6f910()->GetAnimationIdFromName(id, kName) != NiActorManager::INVALID_SEQUENCE_ID;
}
MS2_REPLACE(0x141b6fa90, HasAnimation, 73, 0x30A74C77);

// @0x141b6fae0
void FUN_141b6fae0(NiAVObject* pRoot, float fValue)
{
    Unk_SceneWalker kWalker((NiAVObject*)(pRoot));
    while (NiAVObject* pNode = kWalker.Next(true)) {
        NiRenderObject* pRender = (NiRenderObject*)NiObject::DynamicCast(&NiRenderObject::ms_RTTI, (class NiObject const*)(pNode));
        if (pRender != NULL) {
            NiFloatExtraData* pExtra = (NiFloatExtraData*)NiObject::DynamicCast(&NiFloatExtraData::ms_RTTI, (class NiObject const*)(((class NiObject*)((class NiObjectNET*)(class NiObjectNET*)(pRender))->GetExtraData(*(class NiFixedString const*)(&DAT_143ae5140)))));
            if (pExtra == NULL) {
                pExtra = new (efd::MemHint(efd::MemHint::Bits(0))) NiFloatExtraData(fValue);
                pRender->AddExtraData(DAT_143ae5140, pExtra);
            } else {
                pExtra->SetValue(fValue);
            }
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
        hWnd = ((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef();
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

extern "C" float (__cdecl* __imp_logf)(float);
extern "C" float (__cdecl* __imp_expf)(float);

// @0x141b6fdb0
float FUN_141b6fdb0(float fValue, int nCurve)
{
    switch (nCurve) {
        break;   // the exe has a dead jmp-to-end ahead of the first case body
    case 2:
        fValue = __imp_logf(fValue * 10.0f + 1.0f) / 2.397895f;
        break;
    case 3:
        fValue = (__imp_expf(fValue * 5.0f) - 1.0f) / 147.41316f;
        break;
    }
    return fValue;
}

// @0x141b6fe40
float FUN_141b6fe40(float fValue, int nCurve)
{
    fValue = FUN_141b6fdb0(fValue, nCurve);
    return efd::Clamp(fValue, 0.0f, 1.0f);
}
MS2_REPLACE(0x141b6fe40, FUN_141b6fe40, 62, 0x6EFBDA85);

float FUN_141b6fee0(NiSequenceData* pSeqData, const NiFixedString& kKey, float fDivisor);

// @0x141b6fe90
float FUN_141b6fe90(NiControllerSequence* pSeq, const NiFixedString& kKey, float fDivisor)
{
    if (pSeq == NULL)
        return -FLT_MAX;
    return FUN_141b6fee0(((Unk_UtilSequence*)pSeq)->FUN_141b72540(), kKey, fDivisor);
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
bool GetEntityTransform(egf::Entity* pEntity, Unk_UtilTransform* pOut)
{
    Vector3 vTranslation;
    if (reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(vTranslation)) != 0)
        return false;
    pOut->m_kTranslate = reinterpret_cast<const efd::Point3&>(vTranslation);
    Vector3 vEuler;
    if (reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0x68c7c29d, (efd::Point3&)(vEuler)) != 0)
        return false;
    Unk_NiMatrix3 kX;
    Unk_NiMatrix3 kY;
    Unk_NiMatrix3 kZ;
    reinterpret_cast<efd::Matrix3&>(kX).MakeXRotation(vEuler.x * -0.017453292f);
    reinterpret_cast<efd::Matrix3&>(kY).MakeYRotation(vEuler.y * -0.017453292f);
    reinterpret_cast<efd::Matrix3&>(kZ).MakeZRotation(vEuler.z * -0.017453292f);
    NiMatrix3 kRotate(reinterpret_cast<efd::Matrix3&>(kX) * reinterpret_cast<efd::Matrix3&>(kY) * reinterpret_cast<efd::Matrix3&>(kZ));
    pOut->m_kRotate = reinterpret_cast<Unk_NiMatrix3&>(kRotate);
    float fScale;
    if (reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<float>(0x2d7cad2d, fScale) != 0)
        return false;
    pOut->m_fScale = fScale;
    return true;
}

// ---- list / directory / time helpers ----
struct Unk_UtilNodeList;
struct Unk_UtilNode;
class NiMesh   // C3: member view for the former free stand-ins
{
public:
    class NiDataStreamRef* GetStreamRefAt(unsigned int);
    unsigned int GetStreamRefCount() const;
};
class NiDataStreamRef   // C3: member view for the former free stand-ins
{
public:
    unsigned char GetAccessMask() const;
};

// @0x141b701f0
bool FUN_141b701f0(Unk_UtilNodeList* pList, unsigned bMask)
{
    if (pList == NULL)
        return false;
    unsigned nCount = ((class NiMesh*)(struct Unk_UtilNodeList const*)(pList))->GetStreamRefCount();
    if (nCount == 0)
        return false;
    for (unsigned i = 0; i < nCount; i++) {
        Unk_UtilNode* pNode = ((struct Unk_UtilNode*)((class NiMesh*)(struct Unk_UtilNodeList*)(pList))->GetStreamRefAt(i));
        if (pNode != NULL) {
            if ((((class NiDataStreamRef*)(struct Unk_UtilNode const*)(pNode))->GetAccessMask() & bMask) != 0)
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
class Unk_SingletonObj* GetCommonResource();   // C3: was GetCommonResource
CStringA GetCharacterFolder();
CStringA GetAccountFolder();
CStringA ToCString(const char* psz, int n);

// @0x141b70290
void FUN_141b70290()
{
    CStringA kPath;
    kPath.Format("%s%s", (LPCSTR)ToCString((LPCSTR)((struct Unk_UtilConfig*)GetCommonResource())->m_kRoot, 0), (LPCSTR)GetCharacterFolder());
    if (!efd::File::DirectoryExists((LPCSTR)kPath))
        _mkdir((LPCSTR)kPath);
}

// @0x141b70390
void FUN_141b70390()
{
    CStringA kPath;
    kPath.Format("%s%s", (LPCSTR)ToCString((LPCSTR)((struct Unk_UtilConfig*)GetCommonResource())->m_kRoot, 0), (LPCSTR)GetAccountFolder());
    if (!efd::File::DirectoryExists((LPCSTR)kPath))
        _mkdir((LPCSTR)kPath);
}

// @0x141b70490
void FUN_141b70490(const CStringA& kBase)
{
    int nMore = 1;
    CStringA kPath(kBase);
    HANDLE hFind;
    WIN32_FIND_DATAA kFound;
    hFind = FindFirstFileA((LPCSTR)(kPath + "*.*"), &kFound);
    if (hFind != INVALID_HANDLE_VALUE) {
        while (nMore != 0) {
            char szDrive[3];
            char szDir[272];
            char szName[256];
            _splitpath((LPCSTR)kPath, szDrive, szDir, szName, NULL);
            if ((kFound.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
                if (kFound.cFileName[0] != '.') {
                    char szSub[272];
                    sprintf(szSub, "%s%s%s/", szDrive, szDir, kFound.cFileName);
                    CStringA kSub(szSub);
                    FUN_141b70490(kSub);
                    RemoveDirectoryA((LPCSTR)kSub);
                }
            } else {
                CStringA kFile;
                kFile += szDir;
                kFile += kFound.cFileName;
                DeleteFileA((LPCSTR)kFile);
            }
            nMore = FindNextFileA(hFind, &kFound);
        }
        FindClose(hFind);
    }
    nMore = 1;
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

// @0x141b708a0
CStringW FUN_141b708a0(unsigned nSeconds, bool bShowSeconds)
{
    if (nSeconds < 60) {
        CStringW kShort = BlockFormat(0x97b, nSeconds);
        return kShort;
    } else if (nSeconds < 3600) {
        int nMinutes = nSeconds / 60;
        int nRest = nSeconds % 60;
        CStringW kText = nRest == 0 ? BlockFormat(0x97c, nMinutes) : FormatStringId(0x97e, nMinutes, nRest);
        return kText;
    } else {
        int nHours = nSeconds / 3600;
        int nMinutes = (nSeconds / 60) % 60;
        int nRest = nSeconds % 60;
        CStringW kText = L"";
        if (bShowSeconds && nRest != 0)
            kText = FUN_14028dee0(0x980, nHours, nMinutes, nRest);
        else if (nMinutes == 0)
            kText = BlockFormat(0x97d, nHours);
        else
            kText = FormatStringId(0x97f, nHours, nMinutes);
        return kText;
    }
}

extern NiFixedString DAT_143ae5120;                                     // shader constant keys
extern NiFixedString DAT_143ae5128;
extern int DAT_143ae2b34;                                               // instanced rendering enabled
void FUN_141047ac0(NiObjectNET* pObj, const NiFixedString& kKey, float fValue);
unsigned FUN_140d96630(NiAVObject* pObj);                               // scene flags
void FUN_141568ec0(NiAVObject* pObj);
void FUN_1414d4c70(void* pObj, unsigned uFlags);

void FUN_141b70cb0(NiAVObject* pObj, float fValue, const Unk_Colc& kColor, float fEmissive);

// @0x141b70c50
void FUN_141b70c50(NiAVObject* pObj, float fValue, float fEmissive)
{
    Unk_Vec3Cli kGrey(0.78431f, 0.78431f, 0.78431f);
    FUN_141b70cb0(pObj, fValue, reinterpret_cast<const Unk_Colc&>(kGrey), fEmissive);
}
MS2_REPLACE(0x141b70c50, FUN_141b70c50, 87, 0xDAFF5EB1);

// @0x141b70cb0
void FUN_141b70cb0(NiAVObject* pObj, float fValue, const Unk_Colc& kColor, float fEmissive)
{
    if (pObj == NULL) {
        MS2_ASSERT_AT(0x3ad, 0);
        return;
    }
    NiMaterialProperty* pMaterial = (NiMaterialProperty*)NiObject::DynamicCast(&NiMaterialProperty::ms_RTTI, (class NiObject const*)(pObj->GetProperty(NiProperty::MATERIAL)));
    if (pMaterial != NULL)
        ((class NiMaterialProperty*)(class NiMaterialProperty*)(pMaterial))->SetEmittance(*(class NiColor const*)&static_cast<Unk_Vec3Cli const&>(Unk_Vec3Cli(fEmissive, fEmissive, fEmissive)));
    FUN_141047ac0(pObj, DAT_143ae5120, fValue);
    FUN_1410479a0(pObj, DAT_143ae5128, reinterpret_cast<const NiColor&>(kColor));
    if (DAT_143ae2b34 != 0) {
        if (FUN_14028d470(fValue, 0.0f)) {
            unsigned int nFlags = FUN_140d96630(pObj) & 0xfffffff7;
            FUN_1414d4c70(pObj, nFlags);
        } else
            FUN_141568ec0(pObj);
    }
}

// ---- misc string / entity / scene helpers ----
struct Unk_UtilNameSrc;

// @0x141b70dd0
CStringA FUN_141b70dd0(Unk_UtilNameSrc* pSrc)
{
    if (pSrc == NULL)
        return CStringA("");
    efd::utf8string kName;
    efd::ParseHelper<efd::ID128>::ToString(((egf::Entity*)(struct Unk_UtilNameSrc*)(pSrc))->GetDataFileID(), kName);
    return CStringA(kName.c_str());
}
MS2_REPLACE(0x141b70dd0, FUN_141b70dd0, 192, 0xADA3F07D);

CFileSystem* GetFileSystem();

// @0x141b70ea0
unsigned FUN_141b70ea0(const CStringA& kPath)
{
    std::string kName((LPCSTR)kPath);
    return GetFileSystem()->FileExists(kName);
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


// @0x141b70f90
void FUN_141b70f90(const CMsTime& kTime, const CStringW& kFormat, CStringW& kOut)
{
    int nSecond = kTime.GetSecond();
    int nMinute = kTime.GetMinute();
    int nHour = kTime.GetHour();
    int nDay = kTime.GetDay();
    int nMonth = kTime.GetMonth();
    int nYear = kTime.GetYear();
    kOut = StringFormat((LPCWSTR)kFormat, nYear, nMonth, nDay, nHour, nMinute, nSecond);
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
typedef efd::SmartPointer<Unk_WsC_GameObj> Unk_UtilObjRef;   // 8-byte reference to a game object
template <> efd::SmartPointer<Unk_WsC_GameObj>::~SmartPointer();
template <> Unk_WsC_GameObj* efd::SmartPointer<Unk_WsC_GameObj>::operator->() const;
template <> efd::SmartPointer<Unk_WsC_GameObj>::operator Unk_WsC_GameObj*() const;
Unk_UtilHolder* FUN_141b72360(const Unk_UtilObjRef& kRef);

// @0x141b71120
unsigned FUN_141b71120(Unk_UtilObjRef kRef)
{
    if (reinterpret_cast<Unk_UtilObject*>(kRef.operator->())->GetKind() == 0x6200004)
        return 1;
    if (reinterpret_cast<Unk_UtilObject*>(kRef.operator->())->GetKind() == 0x6200045) {
        efd::SmartPointer<Ridee> kHolder((Ridee*)FUN_141b72360(kRef));
        if (kHolder.operator Ridee*() != NULL) {
            Unk_UtilObject* pRider = ((class Unk_UtilObject*)kHolder.operator->()->GetRider());
            if (pRider != NULL && pRider->GetKind() == 0x6200004)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE(0x141b71120, FUN_141b71120, 290, 0x8ACF42B0);

class GFxManager { public: MS2Ptr<ASMouseCursor> GetMouseCursor(int n); };
class Unk_AltStringMgr* GetGFxManager();   // C3: was GetGFxManager

// @0x141b71250
void FUN_141b71250(int nValue)
{
    if (reinterpret_cast<GFxManager*>(GetGFxManager()) != NULL) {
        MS2Ptr<ASMouseCursor> kHud = reinterpret_cast<GFxManager*>(GetGFxManager())->GetMouseCursor(6);
        if (kHud.operator ASMouseCursor*() != NULL)
            kHud.operator->()->SetCursorMode(nValue != 0 ? 1 : 2);
    }
}

// @0x141b712e0
int FUN_141b712e0()
{
    if (reinterpret_cast<GFxManager*>(GetGFxManager()) == NULL)
        return 0;
    MS2Ptr<ASMouseCursor> kHud = reinterpret_cast<GFxManager*>(GetGFxManager())->GetMouseCursor(6);
    if (kHud.operator==(0))
        return 0;
    return kHud.operator->()->GetVisible() != 0;
}

// ---- curve math ----
float Pow(float fBase, float fExp);
float FUN_141b72600(float fBase, float fExp);
float Log(float fValue);

// @0x141b71390
efd::Point3 GetBezierPoint(Vector3 kStart, Vector3 kControl, Vector3 kEnd, float fT)
{
    if (reinterpret_cast<const efd::Point3&>(kStart) == reinterpret_cast<const efd::Point3&>(kControl) || reinterpret_cast<const efd::Point3&>(kEnd) == reinterpret_cast<const efd::Point3&>(kControl)) {
        Vector3 kDelta = (kEnd - kStart);
        return reinterpret_cast<const efd::Point3&>(kStart) + reinterpret_cast<const efd::Point3&>(kDelta) * fT;
    } else {
        float fInverse = 1.0f - fT;
        float fT2 = Pow(fT, 2.0f);
        float fS2 = Pow(fInverse, 2.0f);
        efd::Point3 kResult = reinterpret_cast<const efd::Point3&>(kStart) * fS2;
        (reinterpret_cast<Vector3&>(kResult) += reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((2.0f * kControl))) * fT * fInverse)));
        (reinterpret_cast<Vector3&>(kResult) += reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(kEnd) * fT2)));
        return kResult;
    }
}

// @0x141b71550
float GetBezierLength(Vector3 kStart, Vector3 kControl, Vector3 kEnd)
{
    Vector3 kA;
    Vector3 kB;
    kA = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((kStart - (2.0f * kControl)))) + reinterpret_cast<const efd::Point3&>(kEnd)));
    kA = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((kStart - (2.0f * kControl)))) + reinterpret_cast<const efd::Point3&>(kEnd)));
    kB = ((2.0f * kControl) - (2.0f * kStart));
    kB = ((2.0f * kControl) - (2.0f * kStart));
    float fAA = (reinterpret_cast<const efd::Point3&>(kA) * reinterpret_cast<const efd::Point3&>(kA));
    float fA = 4.0f * (fAA + (reinterpret_cast<const efd::Point3&>(kA) * reinterpret_cast<const efd::Point3&>(kA)));
    float fAB = (reinterpret_cast<const efd::Point3&>(kA) * reinterpret_cast<const efd::Point3&>(kB));
    float fB = 4.0f * (fAB + (reinterpret_cast<const efd::Point3&>(kA) * reinterpret_cast<const efd::Point3&>(kB)));
    float fBB = (reinterpret_cast<const efd::Point3&>(kB) * reinterpret_cast<const efd::Point3&>(kB));
    float fC = fBB + (reinterpret_cast<const efd::Point3&>(kB) * reinterpret_cast<const efd::Point3&>(kB));
    float fSqrtAll = 2.0f * sqrt(fA + fB + fC);
    float fSqrtA = sqrt(fA);
    float fTermA = 2.0f * fA * fSqrtA;
    float fSqrtC = 2.0f * sqrt(fC);
    float fBA = fB / fSqrtA;
    return (fTermA * fSqrtAll + fSqrtA * fB * (fSqrtAll - fSqrtC)
        + (4.0f * fC * fA - fB * fB) * Log((2.0f * fSqrtA + fBA + fSqrtAll) / (fBA + fSqrtC))) / (4.0f * fTermA);
}

// ---- number / colour helpers ----

// @0x141b71910
CStringW FUN_141b71910(__int64 nValue)
{
    return StringFormat(L"{0}", reinterpret_cast<const unsigned __int64&>(nValue));
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
int ParseInt(const char* psz)
{
    if (psz != NULL)
        return atoi(psz);
    return 0;
}
MS2_REPLACE(0x141b71a10, ParseInt, 37, 0xDC1CD1D0);

// @0x141b71a40
double FUN_141b71a40(int nValue)
{
    return (double)nValue;
}
MS2_REPLACE(0x141b71a40, FUN_141b71a40, 11, 0xFC13D90A);

// @0x141b71a60
// efd::Color::operator/(float) (0x141b723e0), then NiColor(const efd::Color&) (0x140a0a3a0) for the assignment
void NormalizeColor(NiColor* pColor)
{
    if (pColor->r > 1.0f || pColor->g > 1.0f || pColor->b > 1.0f)
        *pColor = *pColor / 255.0f;
    FUN_141b71a40(FUN_141b6df90(reinterpret_cast<const Unk_UtilFloat3*>(pColor)));
}

// ---- scene / skin helpers ----
class Unk_UtilWorld;
class Unk_UtilPlayer;
extern NiFixedString DAT_143ae50f8;                                          // extra-data key of the skin tint
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);

// @0x141b71b00
NiObject* FUN_141b71b00()
{
    Unk_UtilPlayer* pPlayer = ((class Unk_UtilPlayer*)((class WorldService*)(class Unk_UtilWorld*)(reinterpret_cast<Unk_UtilWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return NULL;
    NiAVObject* pRoot = FUN_141b6efc0(((class GameObject*)(class Unk_UtilPlayer*)(pPlayer))->GetEntity());
    if (pRoot != NULL) {
        NiFixedString kName("FA_Skin");
        return NiObject::DynamicCast(&NiRenderObject::ms_RTTI, (class NiObject const*)(pRoot->GetObjectByName(kName)));
    }
    return NULL;
}
MS2_REPLACE(0x141b71b00, FUN_141b71b00, 160, 0x8C42B0E0);

// @0x141b71bb0
NiObject* GetPlayerSkinFloatsExtraData()
{
    NiObject* pSkin = FUN_141b71b00();
    if (pSkin != NULL)
        return NiObject::DynamicCast(&NiFloatsExtraData::ms_RTTI, (class NiObject const*)(((class NiObject*)((class NiObjectNET*)(class NiObjectNET*)((NiObjectNET*)pSkin))->GetExtraData(DAT_143ae50f8))));
    return NULL;
}
MS2_REPLACE(0x141b71bb0, GetPlayerSkinFloatsExtraData, 63, 0x4FF135C2);

// ---- item / scene flag helpers ----
struct Unk_ClientConfig;
class Unk_ConstVal;
int FUN_14025a620(Unk_ConstVal* pVal);
struct Unk_ClientConfig { char m_pad_00[0x2b28]; char m_kLimit; };
namespace Client { class Constants; } template<class T> class TSingleton; template<> class TSingleton<Client::Constants> { public: static Client::Constants* GetInstance(); }; class Unk_SingletonObj1;   // C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance)

// @0x141b71c00
int FUN_141b71c00(unsigned short nValue)
{
    int nLimit = FUN_14025a620((Unk_ConstVal*)&((struct Unk_ClientConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_kLimit);
    return (int)nValue >= nLimit ? 1 : 0;
}
MS2_REPLACE(0x141b71c00, FUN_141b71c00, 70, 0x478D9542);

// A range tuning record: +0x144 / +0x148 are the two factors of the attack-range estimate.
struct Unk_UtilRangeEntry { char m_pad_00[0x144]; float m_144; float m_148; };
class Unk_UtilRangeOwner;
ecr::RenderService * GetRenderService(void);  // C3: the definition's signature
ecr::CameraService* GetCameraService();
float FUN_141b72510(const Unk_UtilRangeEntry* pInfo);
float FUN_141b724f0(const Unk_UtilRangeEntry* pInfo);

// @0x141b71c50
float FUN_141b71c50()
{
    Unk_UtilRangeEntry* pEntry = ((struct Unk_UtilRangeEntry*)((ecr::RenderService*)(class Unk_UtilRangeOwner*)((Unk_UtilRangeOwner *)(GetRenderService())))->GetActiveRenderSurface());
    if (pEntry == NULL)
        return FLT_MAX;
    Unk_UtilRangeEntry* pRange = reinterpret_cast<Unk_UtilRangeEntry*>(GetCameraService()->GetActiveCamera(reinterpret_cast<ecr::RenderSurface*>(pEntry)));
    if (pRange == NULL)
        return FLT_MAX;
    Unk_UtilRangeEntry* pSize = ((struct Unk_UtilRangeEntry*)((ecr::CameraData*)(struct Unk_UtilRangeEntry*)(pRange))->GetCamera());
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
extern NiFixedString DAT_143ae51b8;                                          // tag extra-data key
extern NiFixedString DAT_143ae50e8;                                          // tag text that excludes a branch
void RemoveOutline(void *);  // C3: the definition's signature
void AddOutlineColor(void* pObj, void* pColor);
void FUN_1414d37a0(void *, int);  // C3: the definition's signature

// @0x141b71d10
void SetHighlight(NiAVObject* pRoot, bool bEnable, const Unk_Colc& kColor)
{
    if (pRoot == NULL)
        return;
    Unk_SceneWalker kWalk((NiAVObject*)(pRoot));
    while ((size_t)FUN_1414d3ff0(&kWalk) > 0) {
        NiAVObject* pCurrent = reinterpret_cast<ATL::CAtlList<NiAVObject*>*>(&kWalk)->RemoveHead();
        NiObject* pTag = NiObject::DynamicCast(&NiStringExtraData::ms_RTTI, (class NiObject const*)(((class NiObject*)((class NiObjectNET*)(class NiObjectNET*)(pCurrent))->GetExtraData(DAT_143ae51b8))));
        if (pTag != NULL && ((NiStringExtraData*)pTag)->GetValue().ContainsNoCase(DAT_143ae50e8.operator const char*()))
            continue;
        NiRenderObject* pRender = (NiRenderObject*)NiObject::DynamicCast(&NiRenderObject::ms_RTTI, (class NiObject const*)(pCurrent));
        if (pRender != NULL) {
            if (bEnable)
                AddOutlineColor(pRender, (void*)&kColor);
            else
                RemoveOutline(pRender);
        }
        NiNode* pNode = (NiNode*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(pCurrent));
        if (pNode != NULL)
            kWalk.AddChildren(pNode);
    }
}

// @0x141b71f20
void FUN_141b71f20(NiAVObject* pRoot, bool bEnable, unsigned uColor, bool bSkipEffectRoot)
{
    if (pRoot == NULL)
        return;
    Unk_SceneWalker kWalk((NiAVObject*)(pRoot));
    while ((size_t)FUN_1414d3ff0(&kWalk) > 0) {
        NiAVObject* pCurrent = reinterpret_cast<ATL::CAtlList<NiAVObject*>*>(&kWalk)->RemoveHead();
        NiObject* pTag = NiObject::DynamicCast(&NiStringExtraData::ms_RTTI, (class NiObject const*)(((class NiObject*)((class NiObjectNET*)(class NiObjectNET*)(pCurrent))->GetExtraData(DAT_143ae51b8))));
        if (pTag != NULL && ((NiStringExtraData*)pTag)->GetValue().ContainsNoCase(DAT_143ae50e8.operator const char*()))
            continue;
        NiRenderObject* pRender = (NiRenderObject*)NiObject::DynamicCast(&NiRenderObject::ms_RTTI, (class NiObject const*)(pCurrent));
        if (pRender != NULL) {
            if (bEnable)
                FUN_1414d37a0(pRender, uColor);
            else
                RemoveOutline(pRender);
        }
        NiNode* pNode = (NiNode*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(pCurrent));
        if (pNode != NULL) {
            if (!bSkipEffectRoot || !pNode->GetName().EqualsNoCase("Effect Root"))
                kWalk.AddChildren(pNode);
        }
    }
}

// @0x141b71e70
void SetEntityHighlight(egf::EntityID id, bool bEnable, unsigned uColor, bool bSkipEffectRoot)
{
    egf::EntityPtr kEntity(TSingleton<EntityWorldManager>::GetInstance()->FindEntity(id));
    if (kEntity.operator==((egf::Entity*)0))
        return;
    NiAVObject* pRoot = FUN_141b6efc0(kEntity.operator egf::Entity*());
    if (pRoot != NULL)
        FUN_141b71f20(pRoot, bEnable, uColor, bSkipEffectRoot);
}
MS2_REPLACE(0x141b71e70, SetEntityHighlight, 168, 0xFEE15438);

// ---- string table text ----
// @0x141b720b0
CStringW FUN_141b720b0(int nId, __int64 nValue)
{
    CStringW kText = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x16, nId);
    if (TSingleton<CReservedWordTable>::GetInstance() != NULL)
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceTokensForPc(kText, (class PC*)nValue);
    return kText;
}
MS2_REPLACE(0x141b720b0, FUN_141b720b0, 146, 0xA5874D90);

// @0x141b72150
CStringW FUN_141b72150(int nId, int nValue)
{
    CStringW kText = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x16, nId);
    if (TSingleton<CReservedWordTable>::GetInstance() != NULL)
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceTokensForGender(kText, nValue);
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
    if (TSingleton<CrashManagerCli>::GetInstance() == NULL)
        return;
    m_dwThread = GetCurrentThreadId();
    m_kTag = kTag;
    TSingleton<CrashManagerCli>::GetInstance()->SetCrashLogEntry(m_dwThread, m_kTag);
}

// @0x141b722b0
Unk_UtilLogScope::~Unk_UtilLogScope()
{
    if (TSingleton<CrashManagerCli>::GetInstance() == NULL)
        return;
    TSingleton<CrashManagerCli>::GetInstance()->RemoveCrashLogEntry(m_dwThread);
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
    if ((bool)kRef.operator Unk_WsC_GameObj*() && reinterpret_cast<Unk_UtilObject*>(kRef.operator->())->GetProperty(0x6200045, &pHolder))
        return pHolder;
    else
        return NULL;
}

// @0x141b72460
float Unk_UtilColorData::FUN_141b72460() const
{
    return m_kColorA.b;
}
MS2_REPLACE_METHOD(0x141b72460, Unk_UtilColorData, FUN_141b72460, 16, 0x4C93A5B6);

// @0x141b72470
float Unk_UtilColorData::FUN_141b72470() const
{
    return m_kColorA.g;
}
MS2_REPLACE_METHOD(0x141b72470, Unk_UtilColorData, FUN_141b72470, 16, 0x5463A882);


// @0x141b72480
float FUN_141b72480(NiControllerSequence* pSeq, const NiFixedString& kKey)
{
    if (!((efd::FixedString*)&static_cast<class NiFixedString const&>(kKey))->Exists()) {
        return -FLT_MAX;
    } else {
        NiTextKeyMatch kMatch(kKey);
        return pSeq->GetKeyTimeAt(&kMatch);
    }
}

// @0x141b72530
float Unk_UtilColorData::FUN_141b72530() const
{
    return m_kColorA.r;
}
MS2_REPLACE_METHOD(0x141b72530, Unk_UtilColorData, FUN_141b72530, 16, 0x3C5A885E);

// @0x141b72540
NiSequenceData* Unk_UtilSequence::FUN_141b72540() const
{
    return m_spSeqData;
}
MS2_REPLACE_METHOD(0x141b72540, Unk_UtilSequence, FUN_141b72540, 31, 0x4931477F);

// @0x141b72560
float Pow(float fBase, float fExp)
{
    return FUN_141b72600(fBase, fExp);
}
MS2_REPLACE(0x141b72560, Pow, 38, 0x09A6CEAF);

// @0x141b72590
void Unk_UtilErrorDialog::SetKText(CStringA kText)
{
    m_strText = kText;
}
MS2_REPLACE_METHOD(0x141b72590, Unk_UtilErrorDialog, SetKText, 65, 0xD5D7D3A4);

// @0x141b725e0
float Log(float fValue)
{
    return __imp_logf(fValue);
}
MS2_REPLACE(0x141b725e0, Log, 27, 0x3F5FEE04);

// @0x141b72600
extern "C" float (__cdecl* __imp_powf)(float, float);
float FUN_141b72600(float fBase, float fExp)
{
    return __imp_powf(fBase, fExp);
}
MS2_REPLACE(0x141b72600, FUN_141b72600, 39, 0xECCEDFB2);
