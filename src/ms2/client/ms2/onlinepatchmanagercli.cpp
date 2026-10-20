// onlinepatchmanagercli.cpp - COnlinePatchManagerCli: the client side of the ./DataPatch/ download. The server lists the
// patch files (packet type 3), the client requests them one by one (type 4 out, type 5 in), writes each into
// ./DataPatch/ and reloads the data tables. The ranges after the packet handler are the template glue of its
// std::list<CString> / std::map<CString, MS2Ptr<COnlinePatchFileContext>> members.
// MS2-UNIT: client\ms2\onlinepatchmanagercli.cpp
// MS2-RANGE: 0x140a848a0-0x140a89190 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$list@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAA@XZ 0x140a86e00 ; unique
// MS2-PIN: ??8?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140a87120 ; unique
// MS2-PIN: ??9?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140a871a0 ; unique
// MS2-PIN: ?FUN_140a87690@Unk_PatchTextOwner@@QEAAPEAVUnk_PatchTextFilter@@XZ 0x140a87690 ; unique
// MS2-PIN: ?begin@?$list@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x140a88830 ; unique
// MS2-PIN: ?empty@?$list@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEBA_NXZ 0x140a88aa0 ; unique
// MS2-PIN: ?end@?$list@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x140a88b40 ; unique
// MS2-PIN: ?front@?$list@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x140a88f30 ; unique
// MS2-PIN: ?pop_front@?$list@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAAXXZ 0x140a89010 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$list@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAA@XZ 0x140a86fd0
// MS2-PIN: ??D?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x140a87280
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\onlinepatchmanagercli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/conlinepatchmanagercli.h"
#include "ms2/placeholder/conlinepatchfilecontext.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/filebuffer_1.h"
#include "ms2/client/ms2/networkservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Singleton getters of the systems whose tables are reloaded after the patch.
class Unk_PatchTextFilter;
class Unk_PatchTableA;
class Unk_PatchTableB;
class Unk_PatchTableC;
void FUN_1416e4340();
void FUN_14093af30();
Unk_PatchTableA* FUN_1409eed20();
void FUN_14067ee90(Unk_PatchTableA* p);
void FUN_140851750();
void FUN_140855540();
bool FUN_14087ea50(Unk_PatchTextFilter* p);                // reloads the word filter
Unk_PatchTableB* FUN_1401a9d70();
bool FUN_141811960(Unk_PatchTableB* p);
void* FUN_14025e7d0();
void FUN_140259930(void* p);
CNetworkService* FUN_140714f90();

// The text-filter owner (global DAT_143ab2080); the filter sits at +8.
class Unk_PatchTextOwner
{
public:
    virtual ~Unk_PatchTextOwner();
    Unk_PatchTextFilter* FUN_140a87690() { return reinterpret_cast<Unk_PatchTextFilter*>(&m_pad_8); }
private:
    MS2_LAYOUT_FRIEND;
    __int64 m_pad_8;
};
extern Unk_PatchTextOwner* DAT_143ab2080;
Unk_PatchTextOwner* FUN_140a87680();

// @0x140a86e50
COnlinePatchFileContext::COnlinePatchFileContext() : m_pData(0), m_nSize(0), m_nReceived(0)
{
}

// @0x140a87080
COnlinePatchFileContext::~COnlinePatchFileContext()
{
    if (m_pData != 0) {
        delete[] m_pData;
    }
    m_pData = 0;
    m_nSize = 0;
    m_nReceived = 0;
}

// @0x140a87680
Unk_PatchTextOwner* FUN_140a87680()
{
    return DAT_143ab2080;
}

// @0x140a848a0
COnlinePatchManagerCli::COnlinePatchManagerCli()
{
    m_nState = 0;
}

// @0x140a84910
COnlinePatchManagerCli::~COnlinePatchManagerCli()
{
}

// MS2-FUNCTIONAL: behaviour-equivalent; the exe re-reads the stream vptr into a temp per call and has a larger frame (0x1a8)
// @0x140a84960
void FUN_140a84960(void* pManager, CInPacket& packet)
{
    COnlinePatchManagerCli* self = static_cast<COnlinePatchManagerCli*>(pManager);
    CInputStream& stream = packet;
    unsigned char type = stream.vfunc_o8_1();
    if (type == 1) {
        self->DeletePatchFiles("./DataPatch/");
        FUN_140714f90()->FUN_141538cb0();
    } else if (type == 2) {
        FUN_140166420()->FUN_140396d00("./DataPatch/");
        self->ReloadTables();
        FUN_140714f90()->FUN_141538cb0();
    } else if (type == 3) {
        self->DeletePatchFiles("./DataPatch/");
        self->CreatePatchDirectory("./DataPatch/");
        self->m_contexts.clear();
        self->m_files.clear();
        int nCount = stream.vfunc_o8_3();
        for (int i = 0; i < nCount; i = i + 1) {
            MS2Ptr<COnlinePatchFileContext> spFile(new COnlinePatchFileContext);
            spFile->m_strPath = stream.vfunc_o8_6();
            spFile->m_nSize = stream.vfunc_o8_4();
            spFile->m_strDigest = stream.vfunc_o8_7();
            spFile->m_pData = new char[spFile->m_nSize];
            self->m_contexts.insert(std::make_pair(spFile->m_strPath, spFile));
            self->m_files.push_back(spFile->m_strPath);
        }
        if (self->RequestNextFile() != 1) {
            FUN_140714f90()->FUN_141538cb0();
        }
    } else if (type == 5) {
        CString strPath = stream.vfunc_o8_6();
        __int64 nOffset = stream.vfunc_o8_4();
        int nSize = stream.vfunc_o8_3();
        unsigned char bLast = stream.vfunc_o8_1();
        MS2Ptr<COnlinePatchFileContext> spFile = self->FindFile(strPath);
        if (spFile.get() != 0) {
            stream.vfunc_o8_9(spFile->m_pData + nOffset, nSize);
            spFile->m_nReceived += nSize;
            unsigned __int64 nEnd = nOffset + nSize;
            if (nEnd < spFile->m_nSize && bLast != 1) {
                self->RequestFile(spFile.get());
            } else {
                CString strDone(self->m_files.front());
                self->m_files.pop_front();
                self->SaveFile("./DataPatch/", spFile);
                if (self->m_files.size() == 0) {
                    FUN_140166420()->FUN_140396d00("./DataPatch/");
                    self->ReloadTables();
                    FUN_140714f90()->FUN_141538cb0();
                } else {
                    self->RequestNextFile();
                }
            }
        }
    } else {
        MS2_ASSERT_AT(0x81, FALSE);
    }
}

// @0x140a85080
void COnlinePatchManagerCli::DeletePatchFiles(const char* pszDirectory)
{
    std::list<CString> files;
    FUN_14038bb30("./DataPatch/", "", files);
    for (std::list<CString>::iterator it = files.begin(); it != files.end(); ++it) {
        CString strPath(pszDirectory);
        strPath.Append(*it);
        DeleteFileA(strPath);
    }
    DeleteFileA(pszDirectory);
}

// @0x140a85170
int COnlinePatchManagerCli::CreatePatchDirectory(const char* pszDirectory)
{
    if (!CreateDirectoryA(pszDirectory, 0)) {
        DWORD nError = GetLastError();
        if (nError != ERROR_ALREADY_EXISTS) {
            return 0;
        }
    }
    return 1;
}

// @0x140a851c0
int COnlinePatchManagerCli::SaveFile(const char* pszRoot, MS2Ptr<COnlinePatchFileContext> spFile)
{
    std::string strFull(pszRoot);
    strFull += spFile->m_strPath;
    std::string strDirectory(strFull);
    size_t nSlash = strFull.rfind('/');
    if (nSlash != std::string::npos) {
        strDirectory = strFull.substr(0, nSlash);
    }
    if (!CreateDirectories(pszRoot, strDirectory)) {
        return 0;
    }
    HANDLE hFile = CreateFileA(strFull.c_str(), GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD nWritten = 0;
        WriteFile(hFile, spFile->m_pData, (DWORD)spFile->m_nSize, &nWritten, 0);
        CloseHandle(hFile);
    }
    return 1;
}

// @0x140a85420
int COnlinePatchManagerCli::RequestNextFile()
{
    if (m_files.empty()) {
        return 0;
    }
    CString strPath(m_files.front());
    std::map<CString, MS2Ptr<COnlinePatchFileContext>>::iterator it = m_contexts.find(strPath);
    if (it == m_contexts.end()) {
        return 0;
    }
    MS2Ptr<COnlinePatchFileContext> spFile = it->second;
    return RequestFile(spFile.get());
}

// @0x140a85530
int COnlinePatchManagerCli::RequestFile(COnlinePatchFileContext* pFile)
{
    if (pFile == 0) {
        return 0;
    }
    if (pFile->m_nSize <= pFile->m_nReceived) {
        return 0;
    }
    COutPacket packet(2, 0);
    packet.Encode1(4);
    packet.vfunc_o10_6(pFile->m_strPath);
    packet.Encode8(pFile->m_nReceived);
    FUN_140710590(packet);
    return 1;
}

// MS2-FUNCTIONAL: behaviour-equivalent; frame 0x10 smaller than the exe, no source form found
// @0x140a855f0
int COnlinePatchManagerCli::CreateDirectories(const char* pszRoot, std::string strPath)
{
    DWORD nAttr = GetFileAttributesA(strPath.c_str());
    if (nAttr == INVALID_FILE_ATTRIBUTES || (nAttr & FILE_ATTRIBUTE_DIRECTORY) == 0) {
        static const std::string strSeparators("\\/");
        nAttr = GetFileAttributesA(strPath.c_str());
        if (nAttr == INVALID_FILE_ATTRIBUTES) {
            size_t nPos = strPath.find_last_of(strSeparators);
            if (nPos != std::string::npos) {
                CreateDirectories(pszRoot, strPath.substr(0, nPos));
            }
            if (!CreateDirectoryA(strPath.c_str(), 0)) {
                return 0;
            }
        } else {
            bool bDirectory = (nAttr & FILE_ATTRIBUTE_DIRECTORY) != 0 || (nAttr & FILE_ATTRIBUTE_REPARSE_POINT) != 0;
            if (!bDirectory) {
                return 0;
            }
        }
    }
    return 1;
}

// @0x140a85810
MS2Ptr<COnlinePatchFileContext> COnlinePatchManagerCli::FindFile(CString strPath)
{
    std::map<CString, MS2Ptr<COnlinePatchFileContext>>::iterator it = m_contexts.find(strPath);
    if (it == m_contexts.end()) {
        return MS2Ptr<COnlinePatchFileContext>(0);
    }
    return it->second;
}

MS2_EMIT_CRT_MEMMOVE_S();

// @0x140a858f0
void COnlinePatchManagerCli::ReloadTables()
{
    FUN_1416e4340();
    FUN_14093af30();
    FUN_14067ee90(FUN_1409eed20());
    FUN_140851750();
    FUN_140855540();
    FUN_14087ea50(FUN_140a87680()->FUN_140a87690());
    FUN_141811960(FUN_1401a9d70());
    FUN_140259930(FUN_14025e7d0());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9f910-0x142c9f930 .text$yd
