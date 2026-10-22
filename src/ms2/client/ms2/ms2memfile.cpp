// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2MemFile and ScaleformMemFile (in-memory files over
// CFileSystem buffers) and the startup hooks that route Gamebryo's efd::File, the GFx file opener and the GFx UI's
// XML tables through the client's file system (FUN_141627390 for the packed client, FUN_1416275e0 for the
// developer layout; both called from CGameApp::InitInstance, ms2.cpp). File name guessed from the classes (the TU
// has no __FILE__ strings). Template glue: the Delegate/TFunctor handlers of the loaders, the SDK's
// Scaleform::MemoryFile inlines and the UCRT's per-TU memmove_s.
// MS2-UNIT: unit_141626c30
// MS2-RANGE: 0x141626c30-0x14162a0d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2memfile.cpp"   // guessed (no __FILE__ use)
#include "ms2/placeholder/ms2stdafx.h"

#include <stdlib.h>
#include <string>

#include <efd/File.h>
#include <NiSearchPath.h>

#include "ms2/placeholder/ms2memfile.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/cgfxlanguage.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxfileopener.h"
#include "ms2/placeholder/tfunctor_small.h"
#include "ms2/placeholder/tfunctor2.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/gfxui/nigfxlocalizemanager.h"
#include "ms2/gfxui/uialignwidget.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"

#include "Kernel/SF_File.h"

// ---- externs ----
CFeatureManager* FUN_140166410();
CGFxLanguage* FUN_141371b20();                              // the CGFxLanguage singleton
CString FUN_14071ae20(const CString& strFile);              // the GFx UI's XML path of a file
CString FUN_14071a6f0(const CString& strFile);              // the GFx debug XML path of a file
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
CString FUN_1401d2b10(const CString& strLeft, const CString& strRight);   // the exe's ATL::operator+ copies (clang
CString FUN_14038f6d0(const CString& str, const char* psz);               // would import MFC CopyChars)
struct Unk_PreloadEntry;
class NiString;
typedef int (*Unk_PreloadReader)(NiString kPath, NiString kAnim, Unk_PreloadEntry** ppEntries);
int FUN_1414a90c0(NiString kPath, NiString kAnim, Unk_PreloadEntry** ppEntries);   // ms2animationservice.cpp
void FUN_141c51dd0(Unk_PreloadReader pfn);                  // installs the KF preload table reader (engine side)
CString FUN_14016a600(const wchar_t* psz, int nCodePage);   // narrows a wide string (commonstruct_wc.h)
void* FUN_141508060();                                      // creates an MS2SearchTexturePath (ms2searchtexturepath.cpp)

// The file-change listener of the cache (cachedata.cpp's Unk_CacheListenerPtr is this TFunctor: the exe news a
// ClassFunHandler<TFunctor<void, ParamList<CString, ParamList<_FILETIME>>>, CFileSystem*, ...> for it).
typedef TFunctor<void, ParamList<CString, ParamList<FILETIME, EmptyParam> > > Unk_FileChangeFunctor;
void FUN_1401d17b0(Unk_FileChangeFunctor kListener);        // registers the listener (cachedata.cpp)

// ---- MS2MemFile ----
EE_ImplementDerivedBinaryStream(MS2MemFile, FUN_141627270, FUN_141627370)

// @0x141626e40
MS2MemFile::MS2MemFile(const char* pszPath)
{
    SetEndianSwap(false);
    m_uiPos = 0;
    m_buffer = FUN_140166420()->FUN_140397bc0(pszPath, 0, 0);
    m_bGood = m_buffer.get() ? true : false;
}

// @0x141626f30
MS2MemFile::MS2MemFile(const void* pData, int nSize)
{
    SetEndianSwap(false);
    m_uiPos = 0;
    m_buffer = new CFileBuffer;
    m_buffer->Adopt(const_cast<void*>(pData), nSize);
    m_bGood = m_buffer.get() ? true : false;
}

// @0x141627050
MS2MemFile::~MS2MemFile()
{
}

// @0x141627090
bool MS2MemFile::Seek(int iOffset, SeekOrigin eSeekFrom)
{
    if (m_bGood)
    {
        if (eSeekFrom == SO_CURRENT)
        {
            int iPos = m_uiPos + iOffset;
            if (iPos >= 0 && iPos < (int)GetFileSize())
            {
                m_uiPos = iPos;
                return true;
            }
        }
        else if (eSeekFrom == SO_BEGIN)
        {
            int iPos = iOffset;
            if (iPos >= 0 && iPos < (int)GetFileSize())
            {
                m_uiPos = iPos;
                return true;
            }
        }
        else if (eSeekFrom == SO_END)
        {
            int iPos = GetFileSize() - iOffset;
            if (iPos >= 0 && iPos < (int)GetFileSize())
            {
                m_uiPos = iPos;
                return true;
            }
        }
    }
    return m_bGood;
}

// @0x1416271a0
bool MS2MemFile::Flush()
{
    m_uiPos = 0;
    return true;
}

// @0x1416271c0
unsigned int MS2MemFile::GetFileSize() const
{
    if (m_buffer.IsNull())
        return 0;
    return m_buffer->GetSize();
}

// @0x141627270
unsigned int MS2MemFile::FUN_141627270(void* pDest, unsigned int nBytes)
{
    if (m_bGood)
    {
        if (m_uiPos >= GetFileSize())
            return 0;
        if (m_uiPos + nBytes > GetFileSize())
            nBytes = GetFileSize() - m_uiPos;
        memcpy(pDest, (unsigned char*)m_buffer->GetBuffer() + m_uiPos, nBytes);
        m_uiPos += nBytes;
        return nBytes;
    }
    else
    {
        return 0;
    }
}

// @0x141627370
unsigned int MS2MemFile::FUN_141627370(const void*, unsigned int)
{
    return 0;
}

// ---- ScaleformMemFile ----
class ScaleformMemFile : public Scaleform::MemoryFile
{
public:
    // @0x141629020
    ScaleformMemFile(const char* pszPath, CFileBuffer* pBuffer)
        : Scaleform::MemoryFile(pszPath, (const Scaleform::UByte*)pBuffer->GetBuffer(), pBuffer->GetSize()),
          m_buffer(pBuffer)
    {
    }
    // @0x141629270
    virtual ~ScaleformMemFile() {}
    // @0x141629990
    virtual bool Close() { return Scaleform::MemoryFile::Close(); }

private:
    MS2_LAYOUT_FRIEND;
    Unk_PayloadPtr<CFileBuffer> m_buffer;                   // +0x30 keeps the bytes alive
};
MS2_CHECK_SIZE(ScaleformMemFile, 0x40);

// ---- the loaders' Delegates: TFunctor handles in the exe ----
// Delegate<bool(TiXmlDocument&)> and Delegate<CString(CString, bool)> hold FunctorImpl handlers (RTTI
// FunctorHandler<TFunctor<...>, Fn>, vftables 0x142f46850 / 0x142f46890): their free-function ctors, copy, destroy
// and clone are specialized here. FunctorImpl's slots 0 (deleting dtor) and 1 (Clone) line up with DelegateImplBase's.
typedef TFunctor<bool, ParamList<TiXmlDocument&, EmptyParam> > Unk_XmlLoaderFunctor;
typedef TFunctor<CString, ParamList<CString, ParamList<bool, EmptyParam> > > Unk_SwfNameFunctor;

// @0x1416289c0
template <>
Delegate<bool(TiXmlDocument&)>::Delegate(bool (*f)(TiXmlDocument&))
    : m_pImpl(reinterpret_cast<DelegateImplBase*>(
          new FunctorHandler<Unk_XmlLoaderFunctor, bool (*)(TiXmlDocument&)>(f)))
{
}

// @0x141628950
template <>
Delegate<CString(CString, bool)>::Delegate(CString (*f)(CString, bool))
    : m_pImpl(reinterpret_cast<DelegateImplBase*>(
          new FunctorHandler<Unk_SwfNameFunctor, CString (*)(CString, bool)>(f)))
{
}

// @0x141628ab0
template <>
Delegate<CString(CString, bool)>::DelegateImplBase* Delegate<CString(CString, bool)>::Clone(DelegateImplBase* p)
{
    if (p == 0)
        return 0;
    DelegateImplBase* pCopy = p->vfunc_1();
    return pCopy;
}

// @0x141628af0
template <>
Delegate<bool(TiXmlDocument&)>::DelegateImplBase* Delegate<bool(TiXmlDocument&)>::Clone(DelegateImplBase* p)
{
    if (p == 0)
        return 0;
    DelegateImplBase* pCopy = p->vfunc_1();
    return pCopy;
}

// @0x141629c20
template <>
void Delegate<CString(CString, bool)>::Reset()
{
    if (m_pImpl)
    {
        delete m_pImpl;
        m_pImpl = 0;
    }
}

// @0x141629c90
template <>
void Delegate<bool(TiXmlDocument&)>::Reset()
{
    if (m_pImpl)
    {
        delete m_pImpl;
        m_pImpl = 0;
    }
}

// @0x1416291c0
template <>
Delegate<CString(CString, bool)>::~Delegate()
{
    Reset();
}

// @0x1416291f0
template <>
Delegate<bool(TiXmlDocument&)>::~Delegate()
{
    Reset();
}

// @0x1416292e0
template <>
Delegate<CString(CString, bool)>& Delegate<CString(CString, bool)>::operator=(const Delegate& o)
{
    Reset();
    m_pImpl = Clone(o.m_pImpl);
    return *this;
}

// @0x141629320
template <>
Delegate<bool(TiXmlDocument&)>& Delegate<bool(TiXmlDocument&)>::operator=(const Delegate& o)
{
    Reset();
    m_pImpl = Clone(o.m_pImpl);
    return *this;
}

// ---- efd::File hooks ----
efd::File* FUN_141627960(const char* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize, bool bFlushOnWrite);
bool FUN_141627aa0(const char* pcName);
bool FUN_141627b70(const char* pcName, efd::File::OpenMode eMode);
efd::File* FUN_141627c50(const char* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize, bool bFlushOnWrite);
efd::File* FUN_141627dd0(const char* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize, bool bFlushOnWrite);
bool FUN_141627e40(const char* pcName, efd::File::OpenMode eMode);
bool FUN_141627ec0(const wchar_t* pcName, efd::File::OpenMode eMode);
bool FUN_141627ef0(const char* pcName, efd::File::OpenMode eMode);
bool FUN_141627f90(const char* pcName);
bool FUN_141628000(const wchar_t* pcName);
efd::File* FUN_141628020(const char* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize, bool bFlushOnWrite);
efd::File* FUN_141628150(const wchar_t* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize,
    bool bFlushOnWrite);
efd::File* FUN_141627910(const wchar_t* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize,
    bool bFlushOnWrite);
Scaleform::File* FUN_1416282e0(CString strPath);
CString FUN_141628470(CString strName, bool bDebug);
bool FUN_141628610(TiXmlDocument& doc);
bool LoadUsmSubtitleText(TiXmlDocument& doc);
bool LoadStringMovie(TiXmlDocument& doc);
bool LoadFlashDebug(TiXmlDocument& doc);
bool LoadAlignWidget(TiXmlDocument& doc);

// Packed client: files come from the archives (or, with FUN_1403981d0, through MS2MemFile).
// @0x141627390
void FUN_141627390()
{
    if (FUN_140166420()->FUN_1403981d0())
    {
        efd::File::SetFileCreateFunc(FUN_141627dd0);
        efd::File::SetFileAccessFunc(FUN_141627b70);
        efd::File::SetDirectoryExistsFunc(FUN_141627aa0);
    }
    else
    {
        efd::File::SetFileCreateFunc(FUN_141627960);
        efd::File::SetFileAccessFunc(FUN_141627ef0);
        efd::File::SetDirectoryExistsFunc((efd::File::DIREXISTSFUNC)efd::File::DefaultDirectoryExistsFunc);
    }
    efd::File::SetCreateDirectoryFunc((efd::File::CREATEDIRFUNC)efd::File::DefaultCreateDirectoryFunc);
    efd::File::SetFileCreateFunc(FUN_141627910);
    efd::File::SetFileAccessFunc((efd::File::FILEACCESSFUNCW)efd::File::DefaultFileAccessFunc);
    efd::File::SetCreateDirectoryFunc((efd::File::CREATEDIRFUNCW)efd::File::DefaultCreateDirectoryFunc);
    efd::File::SetDirectoryExistsFunc((efd::File::DIREXISTSFUNCW)efd::File::DefaultDirectoryExistsFunc);
    NiGFxLocalizeManager::FUN_141629eb0(FUN_140166410()->FUN_14036d8e0());
    NiGFxLocalizeManager::FUN_141629df0(Delegate<bool(TiXmlDocument&)>(FUN_141628610));
    NiGFxLocalizeManager::FUN_141629e70(Delegate<bool(TiXmlDocument&)>(LoadUsmSubtitleText));
    NiGFxLocalizeManager::FUN_141629e30(Delegate<bool(TiXmlDocument&)>(LoadStringMovie));
    NiGFxLocalizeManager::FUN_141629db0(Delegate<bool(TiXmlDocument&)>(LoadFlashDebug));
    NiSearchPath::SetCreateFunc((NiSearchPath::CreateFunction)FUN_141508060);
    // CFileSystem::FUN_14039a660 takes (CString, FILETIME); filesystem.h declares the unused second parameter void*.
    FUN_1401d17b0(Unk_FileChangeFunctor(FUN_140166420(),
        reinterpret_cast<void (CFileSystem::*)(CString, FILETIME)>(&CFileSystem::FUN_14039a660)));
    GFxFileOpener::FUN_1422eb400(FUN_1416282e0);
    FUN_141c51dd0(FUN_1414a90c0);
    UIAlignWidgetManager::FUN_1422e6e20(Delegate<bool(TiXmlDocument&)>(LoadAlignWidget));
}

// Developer layout: loose files through MS2MemFile, debug swf names.
// @0x1416275e0
void FUN_1416275e0()
{
    efd::File::SetFileCreateFunc(FUN_141628020);
    efd::File::SetFileAccessFunc(FUN_141627e40);
    efd::File::SetCreateDirectoryFunc((efd::File::CREATEDIRFUNC)efd::File::DefaultCreateDirectoryFunc);
    efd::File::SetDirectoryExistsFunc(FUN_141627f90);
    efd::File::SetFileCreateFunc(FUN_141628150);
    efd::File::SetFileAccessFunc(FUN_141627ec0);
    efd::File::SetCreateDirectoryFunc((efd::File::CREATEDIRFUNCW)efd::File::DefaultCreateDirectoryFunc);
    efd::File::SetDirectoryExistsFunc(FUN_141628000);
    NiSearchPath::SetCreateFunc((NiSearchPath::CreateFunction)FUN_141508060);
    GFxFileOpener::FUN_1422eb400(FUN_1416282e0);
    UISwfEntity::FUN_141629ed0(Delegate<CString(CString, bool)>(FUN_141628470));
    NiGFxLocalizeManager::FUN_141629eb0(FUN_140166410()->FUN_14036d8e0());
    NiGFxLocalizeManager::FUN_141629df0(Delegate<bool(TiXmlDocument&)>(FUN_141628610));
    NiGFxLocalizeManager::FUN_141629e70(Delegate<bool(TiXmlDocument&)>(LoadUsmSubtitleText));
    NiGFxLocalizeManager::FUN_141629e30(Delegate<bool(TiXmlDocument&)>(LoadStringMovie));
    NiGFxLocalizeManager::FUN_141629db0(Delegate<bool(TiXmlDocument&)>(LoadFlashDebug));
    FUN_141c51dd0(FUN_1414a90c0);
    UIAlignWidgetManager::FUN_1422e6e20(Delegate<bool(TiXmlDocument&)>(LoadAlignWidget));
}

// The swf file of a movie name (debug builds of the movie under ..\GfxDebug).
// @0x1416277e0
CString FUN_1416277e0(CString strName, bool bDebug)
{
    int nPacked = FUN_140166420()->FUN_140398190();
    if (nPacked == 1)
    {
        if (!bDebug)
            return StringFormat("..\\GfxDebug\\{0}.gfx", strName);
        else
            return StringFormat("..\\GfxDebug\\Debug_{0}.gfx", strName);
    }
    if (bDebug)
        return StringFormat("Debug_{0}.swf", strName);
    return StringFormat("{0}.swf", strName);
}

// @0x141627910
efd::File* FUN_141627910(const wchar_t* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize,
    bool bFlushOnWrite)
{
    efd::File* pFile = efd::File::DefaultFileCreateFunc(pcName, eMode, uiBufferSize, bFlushOnWrite);
    return pFile;
}

// Read-only opens try the file system's resolved path first.
// @0x141627960
efd::File* FUN_141627960(const char* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize, bool bFlushOnWrite)
{
    if (eMode == efd::File::READ_ONLY && FUN_140166420() != 0)
    {
        std::string strPath = FUN_140166420()->FUN_14039b810(std::string(pcName));
        efd::File* pFile = efd::File::DefaultFileCreateFunc(strPath.c_str(), eMode, uiBufferSize, bFlushOnWrite);
        if (pFile != 0)
            return pFile;
    }
    efd::File* pFile = efd::File::DefaultFileCreateFunc(pcName, eMode, uiBufferSize, bFlushOnWrite);
    return pFile;
}

// @0x141627aa0
bool FUN_141627aa0(const char* pcName)
{
    if (FUN_140166420()->FUN_140398640(std::string(pcName), false))
        return false;
    if (FUN_140166420()->FUN_140398200(std::string(pcName)))
        return true;
    return efd::File::DefaultDirectoryExistsFunc(pcName);
}

// @0x141627b70
bool FUN_141627b70(const char* pcName, efd::File::OpenMode eMode)
{
    if (eMode == efd::File::READ_ONLY)
    {
        if (FUN_140166420()->FUN_140398640(std::string(pcName), true))
            return false;
        if (FUN_140166420()->FUN_1403987d0(std::string(pcName)))
            return true;
        return false;
    }
    return efd::File::DefaultFileAccessFunc(pcName, eMode);
}

// @0x141627c50
efd::File* FUN_141627c50(const char* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize, bool bFlushOnWrite)
{
    if (eMode == efd::File::READ_ONLY)
    {
        if (FUN_140166420()->FUN_140398640(std::string(pcName), true))
            return 0;
        efd::File* pFile = EE_NEW MS2MemFile(pcName);
        if (pFile->IsGood())
            return pFile;
        else
            EE_DELETE pFile;
    }
    return efd::File::DefaultFileCreateFunc(pcName, eMode, uiBufferSize, bFlushOnWrite);
}

// @0x141627dd0
efd::File* FUN_141627dd0(const char* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize, bool bFlushOnWrite)
{
    if (eMode == efd::File::READ_ONLY)
        return FUN_141627c50(pcName, eMode, uiBufferSize, bFlushOnWrite);
    efd::File* pFile = efd::File::DefaultFileCreateFunc(pcName, eMode, uiBufferSize, bFlushOnWrite);
    return pFile;
}

// @0x141627e40
bool FUN_141627e40(const char* pcName, efd::File::OpenMode eMode)
{
    if (eMode == efd::File::READ_ONLY)
    {
        if (FUN_140166420()->FUN_1403987d0(std::string(pcName)))
            return true;
        return false;
    }
    return efd::File::DefaultFileAccessFunc(pcName, eMode);
}

// @0x141627ec0
bool FUN_141627ec0(const wchar_t* pcName, efd::File::OpenMode eMode)
{
    return efd::File::DefaultFileAccessFunc(pcName, eMode);
}

// @0x141627ef0
bool FUN_141627ef0(const char* pcName, efd::File::OpenMode eMode)
{
    if (FUN_140166420() == 0)
        return efd::File::DefaultFileAccessFunc(pcName, eMode);
    return FUN_140166420()->FUN_1403987d0(std::string(pcName)) ? true : false;
}

// @0x141627f90
bool FUN_141627f90(const char* pcName)
{
    if (FUN_140166420()->FUN_140398200(std::string(pcName)))
        return true;
    return efd::File::DefaultDirectoryExistsFunc(pcName);
}

// @0x141628000
bool FUN_141628000(const wchar_t* pcName)
{
    return efd::File::DefaultDirectoryExistsFunc(pcName);
}

// @0x141628020
efd::File* FUN_141628020(const char* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize, bool bFlushOnWrite)
{
    if (eMode == efd::File::READ_ONLY)
    {
        efd::File* pFile = EE_NEW MS2MemFile(pcName);
        if (pFile->IsGood())
            return pFile;
        else
            EE_DELETE pFile;
    }
    return efd::File::DefaultFileCreateFunc(pcName, eMode, uiBufferSize, bFlushOnWrite);
}

// @0x141628150
efd::File* FUN_141628150(const wchar_t* pcName, efd::File::OpenMode eMode, unsigned int uiBufferSize,
    bool bFlushOnWrite)
{
    if (eMode == efd::File::READ_ONLY)
    {
        efd::File* pFile = EE_NEW MS2MemFile(FUN_14016a600(pcName, 0));
        if (pFile->IsGood())
            return pFile;
        else
            EE_DELETE pFile;
    }
    return efd::File::DefaultFileCreateFunc(pcName, eMode, uiBufferSize, bFlushOnWrite);
}

// The GFx file opener's callback: a ScaleformMemFile over the file system's buffer (NULL when missing).
// @0x1416282e0
Scaleform::File* FUN_1416282e0(CString strPath)
{
    Scaleform::File* pFile = 0;
    char szExt[MAX_PATH];
    _splitpath(strPath, 0, 0, 0, szExt);
    CFileSystem::BufferPtr buffer = FUN_140166420()->FUN_140397bc0(strPath, FUN_140166420()->FUN_1403981b0() ? 1 : 0, 1);
    if (buffer.get() != 0)
        pFile = new ScaleformMemFile(strPath, buffer.get());
    return pFile;
}

// UISwfEntity's swf name in the developer layout.
// @0x141628470
CString FUN_141628470(CString strName, bool bDebug)
{
    if (!bDebug)
        return FUN_14038f6d0(FUN_1401d2b10(FUN_14016a5c0("..\\GfxDebug\\UI", 0), strName), ".gfx");
    else
        return FUN_14038f6d0(FUN_1401d2b10(FUN_14016a5c0("..\\GfxDebug\\Debug_UI", 0), strName), ".gfx");
}

// @0x141628610
bool FUN_141628610(TiXmlDocument& doc)
{
    return FUN_141371b20()->LoadKorFlash(&doc);
}

// @0x141628640
bool LoadUsmSubtitleText(TiXmlDocument& doc)
{
    CString strPath = FUN_14071ae20("usmSubtitleText.xml");
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    return true;
}

// @0x141628700
bool LoadStringMovie(TiXmlDocument& doc)
{
    CString strPath = FUN_14071ae20("stringMovie.xml");
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    return true;
}

// @0x1416287c0
bool LoadFlashDebug(TiXmlDocument& doc)
{
    CString strPath = FUN_14071a6f0("flashDebug.xml");
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    return true;
}

// @0x141628880
bool LoadAlignWidget(TiXmlDocument& doc)
{
    CString strPath = FUN_14071a5b0("Table", "alignWidget.xml");
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    return true;
}

// ---- loader setters ----
// @0x141629db0
void NiGFxLocalizeManager::FUN_141629db0(Delegate<bool(TiXmlDocument&)> loader)
{
    ms_kXmlLoader4 = loader;
}

// @0x141629df0
void NiGFxLocalizeManager::FUN_141629df0(Delegate<bool(TiXmlDocument&)> loader)
{
    ms_kXmlLoader1 = loader;
}

// @0x141629e30
void NiGFxLocalizeManager::FUN_141629e30(Delegate<bool(TiXmlDocument&)> loader)
{
    ms_kXmlLoader3 = loader;
}

// @0x141629e70
void NiGFxLocalizeManager::FUN_141629e70(Delegate<bool(TiXmlDocument&)> loader)
{
    ms_kXmlLoader2 = loader;
}

// @0x141629eb0
void NiGFxLocalizeManager::FUN_141629eb0(const CString& strLocale)
{
    ms_strLocale = strLocale;
}

// @0x141629ed0
void UISwfEntity::FUN_141629ed0(Delegate<CString(CString, bool)> d)
{
    s_swfNameDelegate = d;
}

// The UCRT's per-TU `static __inline memmove_s` copy that ends the range.
// @0x141629fb0
MS2_EMIT_CRT_MEMMOVE_S();
