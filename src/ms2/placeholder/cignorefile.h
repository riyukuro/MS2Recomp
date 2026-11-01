// cignorefile.h - PLACEHOLDER for CIgnoreFile (RTTI .?AVCIgnoreFile@@, 0x30 bytes). NOT an original header.
// Bases: TSingleton<CIgnoreFile> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. It loads the "except" lists of the ignore-pack-file xml:
// a set of lower-case directory prefixes (+0x10) and a set of lower-case file names (+0x20). Member names invented.
#pragma once

#include "ms2/ms2layout.h"
#include <set>
#include <string>
#include "ms2/commonfiles/os.h"

class CIgnoreFile : public TSingleton<CIgnoreFile>
{
public:
    CIgnoreFile();                                          // 0x14050e140
    virtual ~CIgnoreFile();
    bool Load(std::string strPath, int nMode);     // loads the ignore-pack-file list
    bool IsIgnored(std::string strPath);                // is the path a listed file or inside a listed directory
    bool IsIgnoredDir(std::string strPath);                // is the path exactly a listed directory entry
private:
    bool ParseFile(std::string strPath, int nMode);     // parses the xml into the two sets
    MS2_LAYOUT_FRIEND;
    int m_nMode;                                            // +0x08 the mode the lists were filtered for
    int m_pad_c;
    std::set<std::string> m_setDirs;                        // +0x10
    std::set<std::string> m_setFiles;                       // +0x20
};
MS2_CHECK_SIZE(CIgnoreFile, 0x30);
