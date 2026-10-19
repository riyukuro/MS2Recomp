// loadingimagetable.h - CLoadingImageTable (RTTI .?AVCLoadingImageTable@@, 0xa8 bytes) and its rows
// CLoadingImageTable::LoadingImage (0x68) / ::LoadingMovie (0x30), recovered from ?\loadingimagetable.cpp
// (0x140d43fe0-0x140d4a310). Header name assumed; member and method names invented.
// Reads Table/loadingImage.xml: <image code startTime endTime bgLoading exceptMap movieFileName playOneTime/>.
// Bases: TSingleton<CLoadingImageTable> at +0x0 (s_instance DAT_143ac2b20), CValidData<CLoadingImageTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/mstime.h"

class Unk_140165cf0;

// The 16-byte CPtred smart pointer of the two row classes (the pointee's count is at CPtred +0x8, the pointer at +0x8).
template <class T>
class Unk_LiRowPtr
{
public:
    Unk_LiRowPtr() { m_p = 0; }
    Unk_LiRowPtr(int) { m_p = 0; }
    Unk_LiRowPtr(T* p) { m_p = p; AddRef(); }
    Unk_LiRowPtr(const Unk_LiRowPtr& o) { m_p = o.m_p; AddRef(); }
    ~Unk_LiRowPtr() { Release(); }
    Unk_LiRowPtr& operator=(const Unk_LiRowPtr& o) { o.AddRef(); Release(); m_p = o.m_p; return *this; }
    T* operator->() const { return m_p; }
    T* get() const { return m_p; }

private:
    void AddRef() const { if (m_p) AddRefImpl((void*)0); }
    void AddRefImpl(void*) const { Reference(m_p); }
    static void Reference(T* p) { CPtred::AddRefPtred(p); }
    void Release() { if (m_p) { ReleaseImpl((void*)0); m_p = 0; } }
    void ReleaseImpl(void*)
    {
        if (CPtred::ReleasePtred(m_p) == 0) {
            Reference(m_p);
            CPtred::DeletePtred(m_p);
        }
    }

    void* m_00;
    T* m_p;
};

class CLoadingImageTable : public TSingleton<CLoadingImageTable>, public CValidData<CLoadingImageTable>
{
public:
    // A map code interval of the exceptMap attribute ("a" or "a-b", comma separated).
    struct Unk_MapRange
    {
        Unk_MapRange(int nFrom, int nTo) { m_nFrom = nFrom; m_nTo = nTo; }
        bool FUN_1403b4ef0(unsigned n) const;                   // n is inside the interval
        int m_nFrom;
        int m_nTo;
    };

    // One <image> row.
    class LoadingImage : public CPtred
    {
    public:
        LoadingImage();                                         // 0x140d43fe0
        virtual ~LoadingImage() = default;                      // 0x140d474f0
        bool IsSameCondition(const LoadingImage& o) const;      // 0x140d44070
        int Load(Unk_140165cf0* pElem);                         // 0x140d44100
        int IsCommon() const;                                   // 0x140d44280 no map code
        int IsInPeriod() const;                                 // 0x140d442c0
        int IsExceptMap(int nMapCode) const;                    // 0x140d44390

        unsigned m_nCode;                                       // +0x18 "code"
        CMsTime m_startTime;                                    // +0x20
        CMsTime m_endTime;                                      // +0x30
        CString m_strFile;                                      // +0x40 LoadingImage/<bgLoading>.dds
        ATL::CAtlArray<Unk_MapRange> m_exceptMaps;              // +0x48
    };

    // The movie of a map: loading movie files by index, "idx:file,idx:file" or one default file.
    class LoadingMovie : public CPtred
    {
    public:
        LoadingMovie();                                         // 0x140d47280
        virtual ~LoadingMovie() = default;                      // 0x140d47530

        int m_n18;                                              // +0x18
        int m_nPlayOneTime;                                     // +0x1c "playOneTime"
        std::map<unsigned, CString> m_files;                         // +0x20
    };

    typedef Unk_LiRowPtr<LoadingImage> ImagePtr;
    typedef Unk_LiRowPtr<LoadingMovie> MoviePtr;

    CLoadingImageTable();                                       // 0x140d44410
    virtual ~CLoadingImageTable();                              // 0x140d444e0

    int Load();                                                 // 0x140d44590 (ms2.cpp calls it as FUN_140d44590)
    int HasImage(int nMapCode);                                 // 0x140d44bd0
    int IsSameImages(int nMapCode, int nOtherCode);             // 0x140d44c50
    CString GetImageFile(int nMapCode, int bCommon);            // 0x140d44e80
    CString GetMovieFile(int nMapCode, unsigned nIndex);            // 0x140d44f90
    void CollectImages(int nMapCode, ATL::CAtlArray<ImagePtr>& aOut, int bCommon);   // 0x140d452d0
    static int ParseExceptMap(Unk_140165cf0* pElem, const char* pszName, ATL::CAtlArray<Unk_MapRange>& aOut);   // 0x140d45660

    // @0x140d47ae0
    static void CheckInit();
    // @0x140d49d80
    static void SetInit(bool bInit) { s_bInit = bInit; }
    static bool s_bInit;                                        // DAT_143ac2b28

    ATL::CAtlArray<ImagePtr> m_images;                          // +0x10 rows valid for every map
    ATL::CRBMultiMap<unsigned, ImagePtr> m_mapImages;                // +0x30 rows by map code
    ATL::CAtlMap<int, MoviePtr> m_movies;                       // +0x60 by map code
};
MS2_CHECK_SIZE(CLoadingImageTable::LoadingImage, 0x68);
MS2_CHECK_SIZE(CLoadingImageTable::LoadingMovie, 0x30);
MS2_CHECK_SIZE(CLoadingImageTable, 0xa8);
MS2_CHECK_OFFSET(CLoadingImageTable, m_images, 0x10);
MS2_CHECK_OFFSET(CLoadingImageTable, m_mapImages, 0x30);
MS2_CHECK_OFFSET(CLoadingImageTable, m_movies, 0x60);
