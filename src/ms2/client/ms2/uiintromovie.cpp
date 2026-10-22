// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Intro movie player: see uiintromovie.h.
// MS2-UNIT: ?\uiintromovie.cpp
// MS2-RANGE: 0x140114c40-0x140114d00 .text$di
// MS2-RANGE: 0x1419950d0-0x141996ec0 .text$mn
// MS2-PIN: ??1MovieInfo@UIIntroMovie@@UEAA@XZ 0x141996190
// MS2-PIN: ??0MovieInfo@UIIntroMovie@@QEAA@XZ 0x141996070
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiintromovie.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

#include "uiintromovie.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

template <> MS2Ptr<Unk_ASVideoPlayer> UISwfEntity::GetChild<Unk_ASVideoPlayer>(const CString& strName);

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_IntroPlayerView { public: void FUN_1422e9360(const CString& strProp); void FUN_1422e97c0(int a, int b); };
class Unk_IntroHub { public: void FUN_1422d4780(UISwfEntity* p, int n); void FUN_1422d4840(UISwfEntity* p, int n); };
Unk_IntroHub* FUN_140b632f0();
class Unk_IntroScenes { public: void FUN_1417e25a0(int nSceneId); };
Unk_IntroScenes* FUN_140aa6d30();
int FUN_1417e2610(Unk_IntroScenes* p);
class Unk_IntroLogin { public: bool FUN_14116d840(); };
Unk_IntroLogin* FUN_14025e7c0();
class Unk_IntroFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_IntroFeatures* FUN_140166410();
class Unk_IntroWindow { public: void FUN_141b91ba0(); };
Unk_IntroWindow* FUN_140aadf80();
class Unk_IntroFiles { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_IntroFiles* FUN_140166420();
CLogString* GetLogString();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
bool FUN_14028f710(Unk_140165cf0* pNode);
int FUN_140873600(Unk_140165cf0* pElem, const char* pszName, CMsTime& rOut);
void FUN_1402928e0(const CStringW& str, ATL::CAtlArray<float>& arr, const wchar_t* pszDelim);
bool FUN_140184310(const CString&, const char*);
unsigned char FUN_1401c0090(const CString&, const CString&);
int FUN_141995eb0();
__int64 FUN_140869440();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1419950d0
UIIntroMovie::UIIntroMovie()
{
    m_50 = 0;
}

// @0x141995140
UIIntroMovie::~UIIntroMovie()
{
}

// MS2-FUNCTIONAL: the exe returns the base call's int result unchanged (frame 0x28 vs 0x38), no source form found
// @0x141995190
int UIIntroMovie::vfunc_52(const CString& strPath, float fVolume)
{
    FUN_140b632f0()->FUN_1422d4780(this, 2);
    int n = UIVideoContents::vfunc_52(strPath, fVolume);
    if (n == 0) FUN_140aadf80()->FUN_141b91ba0();
    return n != 0;
}
MS2_REPLACE_METHOD(0x141995190, UIIntroMovie, vfunc_52, 96, 0x50BBA5E3);

// @0x141995200
int UIIntroMovie::vfunc_53()
{
    FUN_140b632f0()->FUN_1422d4840(this, 2);
    int b = UIVideoContents::vfunc_53();
    FUN_1422dc080();
    return b;
}
MS2_REPLACE_METHOD(0x141995200, UIIntroMovie, vfunc_53, 66, 0xBCE73D48);

// @0x141995250
CString UIIntroMovie::vfunc_1() { return "IntroMovie"; }
MS2_REPLACE_METHOD(0x141995250, UIIntroMovie, vfunc_1, 61, 0xBABA033B);

// @0x1419952a0
void UIIntroMovie::OnLoadInit()
{
    UIObject::OnLoadInit();
    LoadIntroMovie();
    if (MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer")) {
        int nWidth = spPlayer->FUN_1422c1500();
        int nHeight = spPlayer->FUN_1422c1530();
        reinterpret_cast<Unk_IntroPlayerView*>(spPlayer.operator->())->FUN_1422e9360("maintainAspectRatio");
        reinterpret_cast<Unk_IntroPlayerView*>(spPlayer.operator->())->FUN_1422e97c0(0x10, 9);
        spPlayer->FUN_1422e9810(nWidth, nHeight);
    }
}
MS2_REPLACE_METHOD(0x1419952A0, UIIntroMovie, OnLoadInit, 311, 0xE238D1C8);

// @0x1419953e0
void UIIntroMovie::OnLoadComplete()
{
    FUN_140aadf80()->FUN_141b91ba0();
    UIVideoContents::OnLoadComplete();
}
MS2_REPLACE_METHOD(0x1419953E0, UIIntroMovie, OnLoadComplete, 37, 0xBAB0DE70);

// @0x141995410
void UIIntroMovie::vfunc_23(void* p)
{
    FUN_140aadf80()->FUN_141b91ba0();
    UISwfEntity::vfunc_23(p);
}
MS2_REPLACE_METHOD(0x141995410, UIIntroMovie, vfunc_23, 47, 0xF2665358);

// @0x141995450
int UIIntroMovie::vfunc_13()
{
    if (FUN_1417e2610(FUN_140aa6d30()) != 0x620000b) return 0;
    if (FUN_14025e7c0()->FUN_14116d840()) {
        FUN_141995cd0();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141995450, UIIntroMovie, vfunc_13, 77, 0x51321992);

// MS2-FUNCTIONAL: extra else-hop jumps and the url argument load order differ; no source form found
// @0x1419954b0
void UIIntroMovie::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (FUN_1417e2610(FUN_140aa6d30()) == 0x620000b) {
        if (MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer")) {
            if (m_78.IsEmpty()) {
                FUN_141995e70(FUN_141995eb0());
            } else {
                MS2Ptr<MovieInfo> spInfo = m_78.GetHead();
                if (spInfo.get() != 0) {
                    float fTime = spPlayer->FUN_1422e9540();
                    if (spInfo->m_fEndTime <= fTime) {
                        m_78.RemoveHeadNoReturn();
                        if (m_78.GetCount() != 0) {
                            spInfo = m_78.GetHead();
                            if (spInfo.get() != 0) {
                                spPlayer->FUN_1422e9650();
                                const CString& rUrl = spInfo->m_strUrl;
                                spPlayer->FUN_1422e95b0(rUrl);
                            }
                        }
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1419954B0, UIIntroMovie, vfunc_15, 496, 0x174AE2F8);

// @0x1419956b0
void UIIntroMovie::vfunc_30(const CString& a1, const CString& a2, const CString& a3)
{
    if (FUN_140184310(a3, "error") && FUN_1401c0090(a1, m_strPath)) {
        FUN_140aadf80()->FUN_141b91ba0();
        FUN_141995e70(FUN_141995eb0());
        return;
    }
    if (FUN_140184310(a2, "NetStream.Play.Stop")) FUN_141995e70(FUN_141995eb0());
}
MS2_REPLACE_METHOD(0x1419956B0, UIIntroMovie, vfunc_30, 155, 0x7B34F9F1);

// @0x141995760
void UIIntroMovie::vfunc_31(const CString& a1, float a2, const void* a3)
{
    UISwfEntity::vfunc_31(a1, a2, a3);
}
MS2_REPLACE_METHOD(0x141995760, UIIntroMovie, vfunc_31, 56, 0x19E9C6B7);

// @0x1419957a0
void UIIntroMovie::vfunc_16() {}
MS2_REPLACE_METHOD(0x1419957A0, UIIntroMovie, vfunc_16, 6, 0xA9AF6E37);

// @0x1419957b0
bool UIIntroMovie::vfunc_17()
{
    if (MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer")) {
        spPlayer->FUN_1422e9810(spPlayer->FUN_1422c1500(), spPlayer->FUN_1422c1530());
    }
    return true;
}
MS2_REPLACE_METHOD(0x1419957B0, UIIntroMovie, vfunc_17, 201, 0x7929C691);

// @0x141995880
void UIIntroMovie::LoadIntroMovie()
{
    CString strPath = FUN_14071a5b0("Table", "introMovie.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0) return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0) {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("introMovie"); pNode != 0; pNode = pNode->FUN_140168650("introMovie")) {
        CStringW strFeature;
        FUN_140873420(pNode, "feature", strFeature);
        if (!FUN_14028f710(pNode)) continue;
        CMsTime start;
        CMsTime end;
        FUN_140873600(pNode, "startDate", start);
        FUN_140873600(pNode, "endDate", end);
        CMsTime now(FUN_140869440());
        if (start > now && end < now) continue;
        MS2Ptr<MovieInfo> spInfo(new MovieInfo);
        if (spInfo.get() != 0) {
            FUN_1408733e0(pNode, "url", spInfo->m_strUrl);
            CStringW strSeek;
            FUN_140873420(pNode, "seekTime", strSeek);
            ATL::CAtlArray<float> seekTimes;
            FUN_1402928e0(strSeek, seekTimes, L",");
            FUN_140873360(pNode, "endTime", spInfo->m_fEndTime);
            for (size_t i = 0; i < seekTimes.GetCount(); ++i) spInfo->m_seekTimes.AddTail(seekTimes[i]);
            m_78.AddTail(spInfo);
        }
    }
}
MS2_REPLACE_METHOD(0x141995880, UIIntroMovie, LoadIntroMovie, 1091, 0xB4EC1BD2);

// MS2-FUNCTIONAL: extra else-hop jumps differ; no source form found
// @0x141995cd0
void UIIntroMovie::FUN_141995cd0()
{
    if (MS2Ptr<Unk_ASVideoPlayer> spPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer")) {
        if (m_78.IsEmpty()) {
            FUN_141995e70(FUN_141995eb0());
        } else {
            MS2Ptr<MovieInfo> spInfo = m_78.GetHead();
            if (spInfo.get() != 0) {
                if (spInfo->m_seekTimes.GetCount() != 0) {
                    float fTime = spPlayer->FUN_1422e9540();
                    float fSeek = spInfo->m_seekTimes.GetHead();
                    if (fSeek >= fTime) spPlayer->FUN_1422e9690(fSeek);
                    else spInfo->m_seekTimes.RemoveHeadNoReturn();
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141995CD0, UIIntroMovie, FUN_141995cd0, 392, 0x7DAD9A19);

// @0x141995e70
void UIIntroMovie::FUN_141995e70(int)
{
    FUN_140aa6d30()->FUN_1417e25a0(FUN_141995eb0());
}
MS2_REPLACE_METHOD(0x141995E70, UIIntroMovie, FUN_141995e70, 46, 0x459B338F);

// @0x141995eb0
int FUN_141995eb0()
{
    if (FUN_140166410()->FUN_14036d570(0xd8)) return 0x6200085;
    return 0x6200009;
}
MS2_REPLACE(0x141995EB0, FUN_141995eb0, 46, 0xD3368098);

// MS2-FUNCTIONAL: the exe ctor has an EH state (its ATL members are not nothrow there); ours omits it
UIIntroMovie::MovieInfo::MovieInfo() : m_fEndTime(0)
{
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbeac0-0x142cbeaf0 .text$yd
