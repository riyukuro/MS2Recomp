// Recovered UIIntroMovie (UI type 0x4e33 "IntroMovie"): the intro movie player; the playlist (Table/introMovie.xml) is a
// list of movies, each with a url, seek times and an end time. RTTI vftables: dialog at +0, IMessageListener at +0x18.
// File name assumed (the class name). Unnamed helpers and members use invented names.
#pragma once
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/uivideocontents.h"

class UIIntroMovie : public UIVideoContents
{
public:
    // One playlist entry (RTTI UIIntroMovie::MovieInfo, 0x58 bytes, ctor 0x141996070).
    class MovieInfo : public CPtred
    {
    public:
        MovieInfo();
        virtual ~MovieInfo() = default;     // slot 0 (??_G 0x1419962b0)
        CString m_strUrl;                                           // +0x18 "url"
        float m_fEndTime;                                           // +0x20 "endTime"
        ATL::CAtlList<float> m_seekTimes;                           // +0x28 "seekTime" (comma separated)
    };

    UIIntroMovie();                                                 // 0x1419950d0
    virtual ~UIIntroMovie();                                        //  0 0x141995140 (??_G 0x1419962f0)
    virtual CString vfunc_1();                                      //  1 0x141995250
    virtual void OnLoadInit();                                      // 20 0x1419952a0
    virtual void OnLoadComplete();                                  // 22 0x1419953e0
    virtual void vfunc_23(void* p);                                 // 23 0x141995410
    virtual int vfunc_13();                                         // 13 0x141995450
    virtual void vfunc_15();                                        // 15 0x1419954b0
    virtual void vfunc_16();                                        // 16 0x1419957a0
    virtual bool vfunc_17();                                        // 17 0x1419957b0
    virtual void vfunc_30(const CString& a1, const CString& a2, const CString& a3);   // 30 0x1419956b0
    virtual void vfunc_31(const CString& a1, float a2, const void* a3);   // 31 0x141995760
    virtual int vfunc_52(const CString& strPath, float fVolume);    // 52 0x141995190
    virtual int vfunc_53();                                         // 53 0x141995200
    virtual int vfunc_48() { return 0x4e33; }                       // 48 (COMDAT 0x1419967b0)

    void FUN_141995880();                                           // load Table/introMovie.xml
    void FUN_141995cd0();                                           // advance the seek times of the current movie
    void FUN_141995e70(int nUnused);                                // go to the next scene (the argument is ignored)

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<MS2Ptr<MovieInfo> > m_78;                         // +0x78 the playlist
};
MS2_CHECK_SIZE(UIIntroMovie, 0xa8);
MS2_CHECK_OFFSET(UIIntroMovie, m_78, 0x78);
