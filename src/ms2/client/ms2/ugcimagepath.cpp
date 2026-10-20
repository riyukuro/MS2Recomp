// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The local file layout of downloaded UGC images (item,
// blueprint, profile, guild, banner ... icons): URL -> cache key -> local path, plus the "Custom\Convert" paths of the
// image upload.
// MS2-UNIT: client\ms2\ugcimagepath.cpp
// MS2-RANGE: 0x1400e4330-0x1400e43f0 .text$di
// MS2-RANGE: 0x141026d10-0x14102b4d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugcimagepath.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <io.h>
#include <atlcoll.h>

#include "ms2/ms2format.h"
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- callees ------------------------------------------------------------------------------------------------------

// The root of the download cache (set by stringidinterface.cpp) and the "use the simple cache layout" switch.
extern CString DAT_143accfc0;
extern int DAT_1439f6efc;
extern unsigned DAT_143ab2830;                              // my character's job/type

CStringW FUN_14016a730(const char* psz, int nCodePage);     // multi-byte to wide
CString FUN_1401d4330(const wchar_t* psz, int nCodePage);   // wide to multi-byte
CString FUN_14028d990(const CString& strUrl);
void FUN_14015f050(const CString& str, ATL::CAtlArray<CString>& parts, const char* pszSep);   // split
void FUN_140165270(ATL::CAtlArray<CString>& arr, const CString& str);
void FUN_140165320(ATL::CAtlArray<CStringW>* pArr, const CStringW& str);
CUgcManager* FUN_14052d220();
CBuddyManager* FUN_14097a780();

// The placeholder images of the config singleton (DAT_143aac5c0).
class Unk_SingletonObj
{
public:
    unsigned char m_pad[0x90];
    CString m_strNoProfile;                                 // +0x90
    CString m_strNoGuild;                                   // +0x98
    CString m_strBlocked;                                   // +0xa0 (the +0xa8 is the next one)
    CString m_strBlockedProfile;                            // +0xa8
};
MS2_CHECK_OFFSET(Unk_SingletonObj, m_strNoProfile, 0x90);
MS2_CHECK_OFFSET(Unk_SingletonObj, m_strNoGuild, 0x98);
MS2_CHECK_OFFSET(Unk_SingletonObj, m_strBlockedProfile, 0xa8);
Unk_SingletonObj* FUN_1401d31f0();

// The game rules: content kinds a rule set disables (rule 0xb: UGC).
class Unk_UgcContentRule
{
public:
    bool FUN_1407d1210(int nType);
};
class Unk_UgcGameRules
{
public:
    Unk_UgcContentRule* FUN_14046d0d0(int nRule);
};
Unk_UgcGameRules* FUN_140302b00();

// The client feature flags.
class Unk_SettingsHolder;
Unk_SettingsHolder* FUN_140166410();
unsigned char FUN_14036d570(Unk_SettingsHolder* pHolder, int nFlag);

CString FUN_141026d10(CString strPath);
CString FUN_141026f00(CString strPath);
CString FUN_141027490(CString strId);
CString FUN_141027600(CString strId);
CString FUN_141027770(CString strId);
int FUN_141027bb0(CString strPath);
int FUN_141027c70(CString strPath);
CString FUN_141027d30(int nKind);
CString FUN_1410280d0(int nKind, CString strName);
CString FUN_141028a90(CString strId, int bDefault);
CString FUN_141029090(CString strId);
CString FUN_141029440(CString strId, int bDefault);
CString FUN_1410298b0(CString strId);
int FUN_14102ac40(const CStringW& strPath, ATL::CAtlArray<CStringW>& parts);

// ---- the enum names of the sort order (static init, atexit -> .text$yd) ---------------------------------------------

#ifndef MS2_HOOK_DLL
// @0x1400e4330
CString DAT_143accf88[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
#endif

// ---- paths of the downloaded images ---------------------------------------------------------------------------------

// @0x141026d10
CString FUN_141026d10(CString strPath)
{
    CString strKind("");
    if (strPath.Find(".m2u", 0) >= 0)
    {
        strKind = "mxd2_pic";
    }
    else if (strPath.Find(".png", 0) >= 0 || strPath.Find(".jpg", 0) >= 0 || strPath.Find(".dds", 0) >= 0)
    {
        strKind = "mxd2_png";
    }
    else
    {
        MS2_ASSERT_AT(0x69, 0);
        return CString("");
    }
    CString strBase = StringFormat("{0}{1}/0", DAT_143accfc0, strKind);
    CString strFile(strPath);
    strFile.Replace('/', '_');
    CString strFull = StringFormat("{0}/{1}/0", strBase, strFile);
    return strFull;
}

// @0x141026f00
CString FUN_141026f00(CString strPath)
{
    int nPos = strPath.Find(DAT_143accfc0, 0);
    if (nPos == -1)
        return CString("");
    CString strKind("");
    if (strPath.Find(".m2u", 0) >= 0)
    {
        strKind = "mxd2_pic";
    }
    else if (strPath.Find(".png", 0) >= 0 || strPath.Find(".jpg", 0) >= 0 || strPath.Find(".dds", 0) >= 0)
    {
        strKind = "mxd2_png";
    }
    else
    {
        MS2_ASSERT_AT(0x8a, 0);
        return CString("");
    }
    CString strBase = StringFormat("{0}{1}/0", DAT_143accfc0, strKind);
    CString strRest = strPath.Mid(strBase.GetLength() + 1);
    int nLen = strRest.GetLength() - 2;
    strRest = strRest.Mid(0, nLen);
    strRest.Replace('_', '/');
    if (strPath.Find("_icon.png/0", 0) >= 0 && strRest.Find("/icon.png", 0) >= 0)
        strRest.Replace("/icon.png", "_icon.png");
    return strRest;
}

// @0x141027200
CString FUN_141027200(CString strName)
{
    if (DAT_1439f6efc == 0)
        return FUN_141026d10(strName);
    CString strKey = StringFormat("{0}/{1}", DAT_143accfc0, strName);
    return strKey;
}

// @0x1410272e0
CString FUN_1410272e0(CString strUrl)
{
    if (DAT_1439f6efc == 0)
        return FUN_141026f00(strUrl);
    int nPos = strUrl.Find(DAT_143accfc0, 0);
    if (nPos == -1)
        return CString("");
    CString strFile = strUrl.Mid(DAT_143accfc0.GetLength() + 1);
    return strFile;
}

// @0x141027420
int FUN_141027420(CString strUrl)
{
    int nPos = strUrl.Find(DAT_143accfc0, 0);
    if (nPos == -1)
        return 0;
    return 1;
}

// @0x141027490
CString FUN_141027490(CString strId)
{
    CString strResult;
    ATL::CAtlArray<CString> parts;
    FUN_14015f050(strId, parts, "/");
    if (parts.GetCount() == 5)
        strResult = Unk_SocketFormat("{0}{1}_{2}_{3}", parts[1], parts[2], parts[3], parts[4]);
    return strResult;
}

// @0x141027600
CString FUN_141027600(CString strId)
{
    CString strResult;
    ATL::CAtlArray<CString> parts;
    FUN_14015f050(strId, parts, "/");
    if (parts.GetCount() == 6)
        strResult = Unk_SocketFormat("{0}{1}_{2}_{3}", parts[1], parts[2], parts[3], parts[5]);
    return strResult;
}

// @0x141027770
CString FUN_141027770(CString strId)
{
    CString strResult;
    ATL::CAtlArray<CString> parts;
    FUN_14015f050(strId, parts, "/");
    if (parts.GetCount() == 3)
        strResult = StringFormat("{0}", parts[2]);
    return strResult;
}

// @0x141027880
CString FUN_141027880(const CString& strPath)
{
    if (strPath.GetLength() == 0)
        return CString("");
    if (FUN_141027bb0(strPath) == 1)
        return CString(strPath);
    if (strPath.Find("item/", 0) == -1)
        return CString("");
    if (strPath.Find(".m2u", 0) == -1)
        return CString("");
    CString strIcon(strPath);
    strIcon.Replace("item/", "itemicon/");
    strIcon.Replace(".m2u", ".png");
    return CString(strIcon);
}

// @0x141027a20
CString FUN_141027a20(const CString& strPath)
{
    if (strPath.GetLength() == 0)
        return CString("");
    if (FUN_141027c70(strPath) == 1)
        return CString(strPath);
    if (strPath.Find("blueprint/", 0) == -1)
        return CString("");
    if (strPath.Find(".png", 0) == -1)
        return CString("");
    CString strIcon(strPath);
    strIcon.Replace(".png", "_icon.png");
    return CString(strIcon);
}

// @0x141027bb0
int FUN_141027bb0(CString strPath)
{
    if (strPath.GetLength() == 0)
        return 0;
    if (strPath.Find("itemicon/", 0) == -1)
        return 0;
    if (strPath.Find(".png", 0) == -1)
        return 0;
    return 1;
}

// @0x141027c70
int FUN_141027c70(CString strPath)
{
    if (strPath.GetLength() == 0)
        return 0;
    if (strPath.Find("blueprint/", 0) == -1)
        return 0;
    if (strPath.Find("_icon.png", 0) == -1)
        return 0;
    return 1;
}

// @0x141027d30
CString FUN_141027d30(int nKind)
{
    CString strDir;
    switch (nKind)
    {
    case 1:
        strDir = ".\\Custom\\Download\\Item";
        break;
    case 3:
        strDir = ".\\Custom\\Download";
        break;
    case 2:
        strDir = ".\\Custom\\Download\\Item";
        break;
    case 5:
        strDir = ".\\Custom\\Download\\Profile";
        break;
    case 0xc9:
        strDir = ".\\Custom\\Download\\Icon";
        break;
    case 6:
        strDir = ".\\Custom\\Download\\Guild";
        break;
    case 8:
        strDir = ".\\Custom\\Download\\Guild\\Poster";
        break;
    case 7:
        strDir = ".\\Custom\\Download\\Item";
        break;
    case 0xca:
        strDir = ".\\Custom\\Download\\BannderAd";
        break;
    case 0xcb:
        strDir = ".\\Custom\\Download\\CashshopBanner";
        break;
    case 0xcc:
        strDir = ".\\Custom\\Download\\MeratMarket\\Banner";
        break;
    case 0xcf:
        if (FUN_14036d570(FUN_140166410(), 0x108) != 0)
            strDir = ".\\Custom\\Download\\MeratMarket\\Special";
        else
            strDir = ".\\Custom\\Download\\MeratMarket\\Limited";
        break;
    case 0xd2:
        strDir = ".\\Custom\\Download\\MeratMarket\\HomeProduct";
        break;
    case 0xcd:
        strDir = ".\\Custom\\Download\\BannderAd";
        break;
    case 0xce:
        strDir = ".\\Custom\\Download\\BannderAd";
        break;
    case 9:
        strDir = ".\\Custom\\Download\\Blueprint";
        break;
    case 0xd1:
        strDir = ".\\Custom\\Download\\Blueprint";
        break;
    case 10:
        strDir = ".\\Custom\\Download\\WeddingProfile";
        break;
    default:
        MS2_ASSERT_AT(0x177, 0);
        break;
    }
    return strDir;
}

// @0x1410280d0
CString FUN_1410280d0(int nKind, CString strName)
{
    if (FUN_140302b00() != 0)
    {
        if (FUN_140302b00()->FUN_14046d0d0(0xb)->FUN_1407d1210(nKind))
            return CString("");
    }
    CString strPath;
    if (nKind == 3 || nKind == 1 || nKind == 2 || nKind == 7 || nKind == 5 || nKind == 6 || nKind == 10)
    {
        strPath = StringFormat("{0}\\{1}", FUN_141027d30(nKind), FUN_141027490(strName));
    }
    else if (nKind == 8)
    {
        strPath = StringFormat("{0}\\{1}", FUN_141027d30(nKind), FUN_141027600(strName));
    }
    else if (nKind == 0xce)
    {
        strPath = StringFormat("{0}\\{1}", FUN_141027d30(nKind), FUN_141027770(strName));
    }
    else if (nKind == 0xc9)
    {
        CString strIcon = FUN_141027880(strName);
        strPath = StringFormat("{0}\\{1}", FUN_141027d30(nKind), FUN_141027490(strIcon));
    }
    else if (nKind == 9)
    {
        strPath = StringFormat("{0}\\{1}", FUN_141027d30(nKind), FUN_141027490(strName));
    }
    else if (nKind == 0xd1)
    {
        CString strIcon = FUN_141027a20(strName);
        strPath = StringFormat("{0}\\{1}", FUN_141027d30(nKind), FUN_141027490(strIcon));
    }
    else
    {
        strPath.Format("%s\\%s", (const char*)FUN_141027d30(nKind), (const char*)strName);
    }
    return strPath;
}

// @0x141028910
CStringW FUN_141028910(int nKind)
{
    CString strDir;
    switch (nKind)
    {
    case 1:
        strDir = "./Custom/Equip";
        break;
    case 3:
        strDir = "./Custom/Banner";
        break;
    case 2:
        strDir = "./Custom/Cube";
        break;
    case 5:
        strDir = "./Custom/Profile";
        break;
    case 6:
        strDir = "./Custom/Guild";
        break;
    case 8:
        strDir = "./Custom/Guild/Poster";
        break;
    case 7:
        strDir = "./Custom/Ridee";
        break;
    default:
        MS2_ASSERT_AT(0x1c4, 0);
    }
    return FUN_14016a730(strDir, 0);
}

// @0x141028a90
CString FUN_141028a90(CString strId, int bDefault)
{
    if (strId.IsEmpty() && bDefault == 1)
        return CString(FUN_1401d31f0()->m_strNoProfile);
    CString strPath;
    strPath.Format("%s/%s", "./Custom/Download/Profile", (const char*)FUN_141027490(strId));
    return CString(strPath);
}

// @0x141028be0
// MS2-FUNCTIONAL: exe forwards strUrl by move into FUN_141884e30 (no copy/dtor on that path); not expressible with the by-value callee signature
CString FUN_141028be0(__int64 nId, const CString& strName, int bNoDownload, CString strUrl)
{
    {
        CBuddyManager::Ptr spBuddy = FUN_14097a780()->FUN_140ae4880(nId);
        if (spBuddy.get() != 0)
        {
            if (spBuddy->FUN_1401cc5b0() != 0)
                return CString(FUN_1401d31f0()->m_strBlockedProfile);
        }
    }
    if (!strName.IsEmpty())
    {
        CString strFile = FUN_1410280d0(5, strName);
        CString strResult("");
        if (_waccess(FUN_14016a730(strFile, 0), 4) != 0)
        {
            FUN_14052d220()->FUN_141884e30(DAT_143ab2830, 0, nId, strName, strUrl);
            strResult = (bNoDownload != 0) ? CString(FUN_1401d31f0()->m_strNoProfile) : FUN_141028a90(strName, 0);
        }
        else
        {
            strResult = FUN_141028a90(strName, 0);
        }
        return CString(strResult);
    }
    else
    {
        return CString(FUN_1401d31f0()->m_strNoProfile);
    }
}

// @0x141029090
CString FUN_141029090(CString strId)
{
    if (strId.IsEmpty())
        return CString(FUN_1401d31f0()->m_strNoProfile);
    CString strPath;
    strPath.Format("%s/%s", "./Custom/Download/WeddingProfile", (const char*)FUN_141027490(strId));
    return CString(strPath);
}

// @0x1410291d0
CString FUN_1410291d0(__int64 nId, const CString& strName)
{
    if (!strName.IsEmpty())
    {
        CString strFile = FUN_1410280d0(10, strName);
        CString strResult("");
        if (_waccess(FUN_14016a730(strFile, 0), 4) != 0)
        {
            FUN_14052d220()->FUN_141884fd0(DAT_143ab2830, 0, nId, strName);
            strResult = FUN_1401d31f0()->m_strNoProfile;
        }
        else
        {
            strResult = FUN_141029090(strName);
        }
        return CString(strResult);
    }
    return CString(FUN_1401d31f0()->m_strNoProfile);
}

// @0x141029440
CString FUN_141029440(CString strId, int bDefault)
{
    if (strId.IsEmpty() && bDefault == 1)
        return CString(FUN_1401d31f0()->m_strNoGuild);
    CString strPath;
    strPath.Format("%s/%s", "./Custom/Download/Guild", (const char*)FUN_141027490(strId));
    return CString(strPath);
}

// @0x141029590
// MS2-FUNCTIONAL: exe block layout of the empty-name path differs by one jmp
CString FUN_141029590(unsigned __int64 nGuildId, const CString& strName, const CString& strUrl, CString strDefault)
{
    if (!strName.IsEmpty())
    {
        CString strFile = FUN_1410280d0(6, strName);
        if (_waccess(FUN_14016a730(strFile, 0), 0) != 0)
        {
            FUN_14052d220()->FUN_141885090(nGuildId, strName, strUrl);
            if (strDefault.GetLength() > 0)
                strFile = strDefault;
            else
                strFile = FUN_1401d31f0()->m_strNoGuild;
        }
        else
        {
            strFile = FUN_141029440(strName, 0);
        }
        return CString(strFile);
    }
    else
    {
        if (strDefault.GetLength() > 0)
            return CString(strDefault);
        return CString(FUN_1401d31f0()->m_strNoGuild);
    }
}

// @0x1410298b0
CString FUN_1410298b0(CString strId)
{
    if (strId.IsEmpty())
        return CString();
    CString strPath;
    strPath.Format("%s/%s", "./Custom/Download/Guild/Poster", (const char*)FUN_141027600(strId));
    return CString(strPath);
}

// @0x1410299f0
// MS2-FUNCTIONAL: exe materializes the access() result in a bool local and nests the download branch differently
CString FUN_1410299f0(unsigned __int64 nGuildId, const CString& strName, int nIndex, const CString& strUrl, bool bDownload)
{
    if (strName.IsEmpty())
        return CString(FUN_1401d31f0()->m_strNoGuild);
    CString strFile = FUN_1410280d0(8, strName);
    if (_waccess(FUN_14016a730(strFile, 0), 0) == 0)
    {
        strFile = FUN_1410298b0(strName);
    }
    else
    {
        if (bDownload)
            FUN_14052d220()->FUN_1418851e0(nGuildId, strName, nIndex, strUrl);
        strFile = FUN_1401d31f0()->m_strNoGuild;
    }
    return CString(strFile);
}

// @0x141029ca0
CString FUN_141029ca0(const CString& strUrl)
{
    if (strUrl.IsEmpty())
        return CString();
    CString strName = FUN_14028d990(strUrl);
    if (strName.IsEmpty())
        return CString();
    CString strFile = FUN_1410280d0(0xca, strName);
    if (_waccess(FUN_14016a730(strFile, 0), 0) != 0)
    {
        if (FUN_14052d220() != 0)
            FUN_14052d220()->FUN_141885340(strUrl);
    }
    else
    {
        return CString(strFile);
    }
    return CString();
}

// @0x141029ed0
CString FUN_141029ed0(int nKind, const CString& strUrl)
{
    if (strUrl.IsEmpty())
        return CString();
    CString strName = FUN_14028d990(strUrl);
    if (strName.IsEmpty())
        return CString();
    CString strFile = FUN_1410280d0(nKind, strName);
    if (_waccess(FUN_14016a730(strFile, 0), 0) == 0)
        return CString(strFile);
    return CString();
}

// @0x14102a0b0
CString FUN_14102a0b0(int nKind, const CString& strKey, const CString& strUrl, CString strEntity)
{
    if (strUrl.IsEmpty())
        return CString();
    CString strName = FUN_14028d990(strUrl);
    if (strName.IsEmpty())
        return CString();
    CString strFile = FUN_1410280d0(nKind, strName);
    if (_waccess(FUN_14016a730(strFile, 0), 0) != 0)
    {
        if (FUN_14052d220() != 0)
        {
            MS2Ptr<CUgcShopBannerProxy> spProxy(new CUgcShopBannerProxy);
            spProxy->m_strKey = strKey;
            spProxy->m_strEntity = strEntity;
            FUN_14052d220()->FUN_141885570(spProxy, nKind, strUrl);
        }
    }
    else
    {
        return CString(strFile);
    }
    return CString();
}

// ---- the paths of the image upload ------------------------------------------------------------------------------------

// @0x14102a420
CStringW FUN_14102a420(const CStringW& strSrc)
{
    CStringW strPath;
    strPath.Format(L"%s\\upload.dds", (const wchar_t*)FUN_14016a730(".\\Custom\\Convert", 0));
    return CStringW(strPath);
}

// @0x14102a4d0
CStringW FUN_14102a4d0()
{
    CStringW strPath;
    strPath.Format(L"%s\\%s", (const wchar_t*)FUN_14016a730(".\\Custom\\Convert", 0), (const wchar_t*)FUN_14016a730("upload_i.png", 0));
    return CStringW(strPath);
}

// @0x14102a5d0
CStringW FUN_14102a5d0(const CStringW& strPath)
{
    ATL::CAtlArray<CStringW> parts;
    int nError = FUN_14102ac40(strPath, parts);
    if (nError != 0)
        return CStringW(L"");
    CStringW strResult;
    strResult.Format(L"%s\\%s.png", (const wchar_t*)FUN_14016a730(".\\Custom\\Thumbnail", 0), (const wchar_t*)parts[2]);
    return CStringW(strResult);
}

// @0x14102a720
CStringW FUN_14102a720(const CStringW& strPath)
{
    ATL::CAtlArray<CStringW> parts;
    int nError = FUN_14102ac40(strPath, parts);
    if (nError != 0)
        return CStringW(L"");
    CStringW strResult;
    strResult.Format(L"%s\\%s.png", (const wchar_t*)FUN_14016a730(".\\Custom\\Convert", 0), (const wchar_t*)parts[2]);
    return CStringW(strResult);
}

// @0x14102a870
CStringW FUN_14102a870(const CStringW& strSrc)
{
    CStringW strPath;
    strPath.Format(L"%s\\upload.m2u", (const wchar_t*)FUN_14016a730(".\\Custom\\Convert", 0));
    return CStringW(strPath);
}

// @0x14102a920
CStringW FUN_14102a920(const CStringW& strPath)
{
    ATL::CAtlArray<CStringW> parts;
    FUN_14102ac40(strPath, parts);
    if (parts.GetCount() != 4)
        return CStringW(L"");
    CStringW strResult;
    strResult.Format(L"%s\\%s.dds", (const wchar_t*)FUN_14016a730(".\\Custom\\Convert", 0), (const wchar_t*)parts.GetAt(2));
    return CStringW(strResult);
}

// @0x14102aa70
CStringW FUN_14102aa70(const CStringW& strSrc)
{
    CStringW strPath;
    strPath.Format(L"%s\\decompress.dds", (const wchar_t*)FUN_14016a730(".\\Custom\\Convert", 0));
    return CStringW(strPath);
}

// @0x14102ab20
int FUN_14102ab20(const CString& strPath, ATL::CAtlArray<CString>& out)
{
    CStringW strWide = FUN_14016a730(strPath, 0);
    ATL::CAtlArray<CStringW> parts;
    int nResult = FUN_14102ac40(strWide, parts);
    out.RemoveAll();
    for (unsigned i = 0; i < parts.GetCount(); i++)
        FUN_140165270(out, FUN_1401d4330(parts[i], 0));
    return nResult;
}

// @0x14102ac40
int FUN_14102ac40(const CStringW& strPath, ATL::CAtlArray<CStringW>& parts)
{
    parts.RemoveAll();
    wchar_t szDir[256] = { 0 };
    wchar_t szDrive[3] = { 0 };
    wchar_t szName[256] = { 0 };
    wchar_t szExt[256] = { 0 };
    if (_waccess(strPath, 0) != 0)
        return 0x34;
    _wsplitpath_s(strPath, szDrive, 3, szDir, 0x100, szName, 0x100, szExt, 0x100);
    {
        CStringW strDrive(szDrive);
        FUN_140165320(&parts, strDrive);
    }
    {
        CStringW strDir(szDir);
        FUN_140165320(&parts, strDir);
    }
    {
        CStringW strName(szName);
        FUN_140165320(&parts, strName);
    }
    {
        CStringW strExt(szExt);
        FUN_140165320(&parts, strExt);
    }
    return 0;
}

// the memmove_s the ATL string copies inline
// @0x14102b3b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cab560-0x142cab590 .text$yd
