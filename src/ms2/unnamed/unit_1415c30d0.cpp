// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Nexon Messenger (NM) client library: the flat request
// API. Each wrapper builds one CNM...Func request on the stack, hands it to CNMManager::CallNMFunc and copies the
// reply out; plus the GameButton path helpers. The library has no __FILE__ strings, so every name here except the
// CNM... class names (RTTI) is invented.
// MS2-UNIT: unit_1415c30d0
// MS2-RANGE: 0x1415c30d0-0x1415c44c0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <strsafe.h>
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#pragma intrinsic(strlen)

// unit_1415c2f20: fills szPath with the NM data directory.
char* FUN_1415c2f20(char* szPath);

// @0x1415c30d0
char* NMCO_GetGameButtonDir(char* szPath)
{
    FUN_1415c2f20(szPath);
    StringCchCatA(szPath, MAX_PATH, "\\GameButton");
    return szPath;
}
MS2_REPLACE(0x1415c30d0, NMCO_GetGameButtonDir, 51, 0x29F6BF27);

// @0x1415c3110
char* NMCO_GetGameButtonFilePath(char* szUrl, char* szPath)
{
    char* szName = NULL;
    NMCO_GetGameButtonDir(szPath);
    StringCchCatA(szPath, MAX_PATH, "\\");
    szName = strrchr(szUrl, '/');
    if (szName != NULL)
        StringCchCatA(szPath, MAX_PATH, szName + 1);
    else
        StringCchCatA(szPath, MAX_PATH, szUrl);
    return szPath;
}
MS2_REPLACE(0x1415c3110, NMCO_GetGameButtonFilePath, 141, 0x143465E2);

// Creates every directory on the way to szPath (each component that ends in a backslash).
// @0x1415c31b0
void NMCO_CreateDirectories(const char* szPath)
{
    char szDir[MAX_PATH];
    int nLen = (int)strlen(szPath);
    int j = 0;
    for (int i = 0; i < nLen; i++)
    {
        if (szPath[i] == '\\')
        {
            szDir[j] = '\0';
            CreateDirectoryA(szDir, NULL);
        }
        szDir[j] = szPath[i];
        j++;
    }
}
MS2_REPLACE(0x1415c31b0, NMCO_CreateDirectories, 258, 0xEB1474CD);

// @0x1415c32c0
int NMCO_ExecutePatcher(const char* szUrl, const char* szPatchDir, const char* szExecPath, int n4, int n5, int n6)
{
    CNMExecutePatcherFunc func(szUrl, szPatchDir, szExecPath, n4, n5, n6);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE(0x1415c32c0, NMCO_ExecutePatcher, 182, 0xCF0CF228);

// @0x1415c3380
int NMCO_ExecuteLauncher(int nGameCode, int n2, const char* szArgument, int n4, int n5)
{
    CNMExecuteLauncherFunc func(nGameCode, n2, szArgument, n4, n5);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE(0x1415c3380, NMCO_ExecuteLauncher, 168, 0x8147EDA4);

// @0x1415c3430
int NMCO_ExecuteNGMPatcher(int nGameCode, const char* sz2, const char* sz3, const char* sz4, int n5, int n6, int n7,
                           const char* sz8, int n9, const char* sz10, int n11)
{
    CNMExecuteNGMPatcherFunc func(nGameCode, sz2, sz3, sz4, n5, n6, n7, sz8, n9, sz10, n11);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE(0x1415c3430, NMCO_ExecuteNGMPatcher, 247, 0x4C783E19);

// @0x1415c3530
int NMCO_ExecuteNGMPatcher2(const char* szArgument, int n2)
{
    CNMExecuteNGMPatcher2Func func(szArgument, n2);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE(0x1415c3530, NMCO_ExecuteNGMPatcher2, 136, 0xBCB7C674);

// @0x1415c35c0
int NMCO_ExecuteNGMLauncher(int nGameCode, int n2, const char* sz3, int n4, const char* sz5, int n6, const char* sz7,
                            const char* sz8, int n9)
{
    CNMExecuteNGMLauncherFunc func(nGameCode, n2, sz3, n4, sz5, n6, sz7, sz8, n9);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE(0x1415c35c0, NMCO_ExecuteNGMLauncher, 218, 0x6D0D825D);

// @0x1415c36a0
int NMCO_ExecuteNGMInstaller(int nGameCode, int n2, int n3, const char* sz4, const char* sz5, const char* sz6,
                             const char* sz7, int n8)
{
    CNMExecuteNGMInstallerFunc func(nGameCode, n2, n3, sz4, sz5, sz6, sz7, n8);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE(0x1415c36a0, NMCO_ExecuteNGMInstaller, 209, 0x0DF625FA);

// @0x1415c3780
int NMCO_IsNGMInstalled()
{
    CNMIsNGMInstalledFunc func;
    if (CNMManager::GetInstance()->CallNMFunc(&func))
        return func.m_bInstalled;
    return FALSE;
}
MS2_REPLACE(0x1415c3780, NMCO_IsNGMInstalled, 97, 0x2302B52F);

// @0x1415c37f0
int NMCO_GetUrlEx(int nGameCode, char* szUrl, int n3, const char* sz4, int n5, int n6, int n7, int n8)
{
    if (szUrl != NULL)
    {
        CNMGetUrlExFunc func;
        func.m_nUrlType = 1;
        func.m_nGameCode = nGameCode;
        func.m_n248 = n3;
        if (sz4 != NULL)
            StringCchCopyA(func.m_sz24c, 0x100, sz4);
        func.m_n34c = n5;
        func.m_n350 = n6;
        func.m_n354 = n7;
        func.m_n358 = n8;
        if (CNMManager::GetInstance()->CallNMFunc(&func))
        {
            StringCchCopyA(szUrl, 0x400, func.m_szUrl);
            return TRUE;
        }
    }
    return FALSE;
}
MS2_REPLACE(0x1415c37f0, NMCO_GetUrlEx, 313, 0xF3A82C44);

// @0x1415c3930
int NMCO_GetUrlEx2(int n1, char* szUrl, int n3, int n4, int n5, int n6)
{
    if (szUrl != NULL)
    {
        CNMGetUrlExFunc func;
        func.m_nUrlType = 2;
        func.m_n38 = n1;
        func.m_n34c = n3;
        func.m_n350 = n4;
        func.m_n354 = n5;
        func.m_n358 = n6;
        if (CNMManager::GetInstance()->CallNMFunc(&func))
        {
            StringCchCopyA(szUrl, 0x400, func.m_szUrl);
            return TRUE;
        }
    }
    return FALSE;
}
MS2_REPLACE(0x1415c3930, NMCO_GetUrlEx2, 262, 0x7F3E059B);

// @0x1415c3a40
int NMCO_GetUrlEx3(unsigned __int64 n1, char* szUrl, int n3, int n4, int n5, int n6)
{
    if (szUrl != NULL)
    {
        CNMGetUrlExFunc func;
        func.m_nUrlType = 3;
        func.m_n40 = n1;
        func.m_n34c = n3;
        func.m_n350 = n4;
        func.m_n354 = n5;
        func.m_n358 = n6;
        if (CNMManager::GetInstance()->CallNMFunc(&func))
        {
            StringCchCopyA(szUrl, 0x400, func.m_szUrl);
            return TRUE;
        }
    }
    return FALSE;
}
MS2_REPLACE(0x1415c3a40, NMCO_GetUrlEx3, 265, 0x8AB48384);

// @0x1415c3b50
int NMCO_GetUrlEx4(const char* sz1, char* szUrl, int n3, int n4, int n5)
{
    if (sz1 != NULL && szUrl != NULL)
    {
        CNMGetUrlExFunc func;
        func.m_nUrlType = 4;
        StringCchCopyA(func.m_sz48, 0x200, sz1);
        func.m_n34c = 1;
        func.m_n350 = n3;
        func.m_n354 = n4;
        func.m_n358 = n5;
        if (CNMManager::GetInstance()->CallNMFunc(&func))
        {
            StringCchCopyA(szUrl, 0x400, func.m_szUrl);
            return TRUE;
        }
    }
    return FALSE;
}
MS2_REPLACE(0x1415c3b50, NMCO_GetUrlEx4, 287, 0x8053F02A);

// @0x1415c3c80
int NMCO_GetSessionValue(const char* szName, char* szValue)
{
    CNMGetSessionValueFunc func(szName);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        StringCchCopyA(szValue, 0x100, func.m_szValue);
        return TRUE;
    }
    return FALSE;
}
MS2_REPLACE(0x1415c3c80, NMCO_GetSessionValue, 181, 0x6F267202);

// @0x1415c3d40
int NMCO_SetSessionValue(const char* szName, const char* szValue, int n3)
{
    CNMSetSessionValueFunc func(szName, szValue, n3);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE(0x1415c3d40, NMCO_SetSessionValue, 144, 0xD60DD8EC);

// @0x1415c3de0
int NMCO_BringForwardStandAloneMsg(const char* szName)
{
    CNMBringForwardStandAloneMsgFunc func(szName);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE(0x1415c3de0, NMCO_BringForwardStandAloneMsg, 118, 0x5DC380BB);

// @0x1415c3e60
int NMCO_DownloadFile(const char* szUrl, const char* szPath)
{
    CNMDownloadFileFunc func(szUrl, szPath);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE(0x1415c3e60, NMCO_DownloadFile, 131, 0x47FED3E1);

// @0x1415c3ef0
int NMCO_UploadFile(const char* szUrl, const char* sz2, const char* sz3, char* szResult, int n5)
{
    CNMUploadFileFunc func(szUrl, sz2, sz3, n5);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        StringCchCopyA(szResult, 0x400, func.m_szResult);
        return TRUE;
    }
    szResult[0] = '\0';
    return FALSE;
}
MS2_REPLACE(0x1415c3ef0, NMCO_UploadFile, 239, 0x6EB07D51);

// Not hooked (nor NMCO_GetGameServerList): the vector assignment would reallocate the caller's exe-heap buffer
// with the DLL's allocator.
// @0x1415c3ff0
int NMCO_GetSupportGameList(std::vector<CNMGameCode>& aGameCode)
{
    CNMGetSupportGameListFunc func(0);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        aGameCode = func.m_aGameCode;
        return TRUE;
    }
    return FALSE;
}

// @0x1415c4080
int NMCO_GetGameServerList(int nGameCode, std::vector<CNMGameServerCode>& aServerCode)
{
    CNMGetGameServerListFunc func(nGameCode);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        aServerCode = func.m_aServerCode;
        return TRUE;
    }
    return FALSE;
}

// @0x1415c4110
int NMCO_GetGameFullName(int nGameCode, char* szName)
{
    CNMGetGameFullNameFunc func(nGameCode);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        StringCchCopyA(szName, 0x80, func.m_szName);
        return TRUE;
    }
    return FALSE;
}
MS2_REPLACE(0x1415c4110, NMCO_GetGameFullName, 176, 0x8E610FE1);

// @0x1415c41d0
int NMCO_GetGameShortName(int nGameCode, char* szName)
{
    CNMGetGameShortNameFunc func(nGameCode);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        StringCchCopyA(szName, 0x80, func.m_szName);
        return TRUE;
    }
    return FALSE;
}
MS2_REPLACE(0x1415c41d0, NMCO_GetGameShortName, 176, 0x763FA3F1);

// @0x1415c4290
int NMCO_GetGameFriendTitle(int nGameCode, char* szTitle)
{
    CNMGetGameFriendTitleFunc func(nGameCode);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        StringCchCopyA(szTitle, 0x80, func.m_szTitle);
        return TRUE;
    }
    return FALSE;
}
MS2_REPLACE(0x1415c4290, NMCO_GetGameFriendTitle, 176, 0x890FAD11);

// @0x1415c4350
int NMCO_GetGameServerName(int nGameCode, int nServerCode, char* szName)
{
    CNMGetGameServerNameFunc func(nGameCode, nServerCode);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        StringCchCopyA(szName, 0x80, func.m_szName);
        return TRUE;
    }
    return FALSE;
}
MS2_REPLACE(0x1415c4350, NMCO_GetGameServerName, 188, 0x0EFA0545);

// @0x1415c4420
int NMCO_DownloadGuildMarkFile(int nGameCode, unsigned __int64 nGuildKey, const char* szPath)
{
    CNMDownloadGuildMarkFileFunc func(nGameCode, nGuildKey, szPath);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE(0x1415c4420, NMCO_DownloadGuildMarkFile, 142, 0xCD0DA965);
