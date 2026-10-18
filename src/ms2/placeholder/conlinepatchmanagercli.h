// conlinepatchmanagercli.h - PLACEHOLDER for COnlinePatchManagerCli (RTTI .?AVCOnlinePatchManagerCli@@, 0x30 bytes). NOT an
// original header.
// Bases: TSingleton<COnlinePatchManagerCli> at +0x0. A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; it
// downloads the ./DataPatch/ files the server lists (packet FUN_140a84960, ?\onlinepatchmanagercli.cpp). Members
// from ctor 0x140a848a0.
#pragma once

#include <list>
#include <map>
#include <string>
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class COnlinePatchFileContext;
template <class T> class MS2Ptr;
class COutPacket;
class CInPacket;

class COnlinePatchManagerCli : public TSingleton<COnlinePatchManagerCli>
{
public:
    COnlinePatchManagerCli();                                   // 0x140a848a0
    virtual ~COnlinePatchManagerCli();                          // 0x140a84910

    void DeletePatchFiles(const char* pszDirectory);                         // 0x140a85080
    int CreatePatchDirectory(const char* pszDirectory);                      // 0x140a85170
    int SaveFile(const char* pszRoot, MS2Ptr<COnlinePatchFileContext> spFile);   // 0x140a851c0
    int RequestNextFile();                                                   // 0x140a85420
    int RequestFile(COnlinePatchFileContext* pFile);                         // 0x140a85530
    int CreateDirectories(const char* pszRoot, std::string strPath);         // 0x140a855f0
    MS2Ptr<COnlinePatchFileContext> FindFile(CString strPath);               // 0x140a85810
    void ReloadTables();                                                     // 0x140a858f0

    std::list<CString> m_files;                                 // +0x08 paths still to download
    std::map<CString, MS2Ptr<COnlinePatchFileContext>> m_contexts;   // +0x18
    int m_nState;                                               // +0x28
};
MS2_CHECK_SIZE(COnlinePatchManagerCli, 0x30);
