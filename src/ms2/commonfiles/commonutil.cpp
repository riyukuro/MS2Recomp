// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Shared game utilities: host/IP lookups, string splitting
// and parsing helpers, easing calculators and the common STL/ATL instantiations they pull in.
// MS2-UNIT: commonfiles\commonutil.cpp
// MS2-RANGE: 0x1400b56f0-0x1400b57d1 .text$di
// MS2-RANGE: 0x14028b820-0x14029dff0 .text$mn
// MS2-RANGE: 0x142c9a450-0x142c9a480 .text$yd
// MS2-RANGE: 0x142c9a4a0-0x142c9a4c0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x140295c10 ; unique
// MS2-PIN: ?_Adopt@_Iterator_base0@std@@QEAAXPEBX@Z 0x140296580 ; order
// MS2-PIN: ??0?$allocator@H@std@@QEAA@XZ 0x140296df0 ; order
// MS2-PIN: ??A?$vector@HV?$allocator@H@std@@@std@@QEAAAEAH_K@Z 0x140297cb0 ; unique
// MS2-PIN: ?__empty_global_delete@@YAXPEAX_K@Z 0x14029a660 ; order
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@V?$_Vector_val@U?$_Simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@XZ 0x14029b920 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@std@@QEBAAEBV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@XZ 0x14029bad0 ; unique
// MS2-PINS-END tplpin
// hand pins (w98): tplpin unique proposals
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@2@_K@Z 0x14029cc90 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@HPEAUUnk_XmlElement@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@HPEAUUnk_XmlElement@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@HPEAUUnk_XmlElement@@@std@@PEAX@2@_K@Z 0x14029ccc0 ; unique
// hand pins (w98): tplpin unique proposals
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@1@XZ 0x140297da0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140297e50 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140297ec0 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140297f30 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140297fc0 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1402980b0 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140298180 ; unique
// hand pins (w98): tplpin unique proposals
// MS2-PIN: ??$?0AEAHAEAPEAUUnk_XmlElement@@$0A@@?$pair@HPEAUUnk_XmlElement@@@std@@QEAA@AEAHAEAPEAUUnk_XmlElement@@@Z 0x1402923f0 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@0@AEAPEAU10@@Z 0x140296790 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@HPEAUUnk_XmlElement@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@HPEAUUnk_XmlElement@@@std@@PEAX@0@AEAPEAU10@@Z 0x1402967a0 ; unique
// MS2-PIN: ??$forward@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140296830 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140296840 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@std@@QEAA@XZ 0x140296cd0 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@QEAA@XZ 0x140296d00 ; unique
// MS2-PIN: ?GetTimeSpan@CTimeSpan@ATL@@QEBA_JXZ 0x140297d10 ; unique
// MS2-PIN: ??HATL@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@0@PEB_WAEBV10@@Z 0x140298360 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@HPEAUUnk_XmlElement@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@U?$pair@HPEAUUnk_XmlElement@@@std@@@2@XZ 0x14029b880 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@HPEAUUnk_XmlElement@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@U?$pair@HPEAUUnk_XmlElement@@@std@@@2@XZ 0x14029b890 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x14029b8a0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x14029b8b0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@std@@@2@XZ 0x14029b8d0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@2@XZ 0x14029b970 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@std@@@2@XZ 0x14029b980 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@HPEAUUnk_XmlElement@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@2@XZ 0x14029b990 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@HPEAUUnk_XmlElement@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@HPEAUUnk_XmlElement@@@std@@@std@@@2@XZ 0x14029b9a0 ; unique
// MS2-PIN: ?_Has_unused_capacity@?$vector@PEAUUnk_XmlElement@@V?$allocator@PEAUUnk_XmlElement@@@std@@@std@@AEBA_NXZ 0x14029bb70 ; unique
// hand pins (w108)
// MS2-PIN: ??$StringFormat@I@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBI@Z 0x140292a70
// MS2-PIN: ??G?$_String_const_iterator@V?$_String_val@U?$_Simple_types@_W@std@@@std@@@std@@QEBA_JAEBV01@@Z 0x140298250
// MS2-PIN: ?size@?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@QEBA_KXZ 0x14029d490

// MS2-PIN: ??0Unk_CommonVec2@@QEAA@XZ 0x140297240
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.cpp"
#include <afx.h>
#include <winsock2.h>
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/commonutil.h"
#include <atlcoll.h>
#include <atltime.h>
#include <atlfile.h>
#include <stdarg.h>
#include <time.h>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/mstime.h"
#include "hook/ms2hook.h"

int FUN_14028c3e0(const CString& strText, CAtlArray<CString>& arrOut, const char* pszDelim, int nMax);

struct Unk_CommonVec3 { float x, y, z; };

struct Unk_CommonVec2
{
    float x, y;
    Unk_CommonVec2() { }                                        // 0x140297240
    Unk_CommonVec2(float fX, float fY) : x(fX), y(fY) { }       // 0x140297200
    Unk_CommonVec2 operator*(float fScale) const { return Unk_CommonVec2(x * fScale, y * fScale); }   // 0x140297e00
};
MS2_CHECK_SIZE(Unk_CommonVec2, 8);

extern long g_lUniqueSeq;
void FUN_1402929a0(const CStringW& strText, std::vector<int>& arrOut, const wchar_t* pszDelim);
int FUN_140274f40(const CStringW& strText);                     // _wtoi
bool FUN_14028d470(float fValue, float fTolerance);
float FUN_14029d220(float fValue);

// Unrecovered helpers.
CString FUN_140188f50(const char* psz, int n);                  // CString from a C string
CString FUN_14016a5c0(const char* psz, int n);
long FUN_140298fd0(long* plValue);                              // interlocked increment
float FUN_140768090();                                          // random float in [0, 1]
__int64 FUN_140869440();                                        // current server time
CString FUN_140298360(const char* pszPrefix, const CString& str);

class Unk_StringMgr                                             // localized string table
{
public:
    CString FUN_140229600(int nId);                             // narrow text of a string id
    CString FUN_140229690(const CString& strKey);               // narrow text of a key
    CStringW FUN_140229760(int nId);                            // wide text of a string id
    CStringW FUN_140229820(const CStringW& strKey);
    CStringW FUN_140229940(const CString& strKey);              // wide text of a "$..." key
};

// Date printed with a strftime format (the format text lives at +8).
class Unk_TimeFormat
{
public:
    Unk_TimeFormat();                                           // 0x14028da50
    void SetFormat(CString strFormat);                          // 0x14028dac0
    CString Format() const;                                     // 0x14028db10
    ~Unk_TimeFormat() { }                                       // 0x140297910

    ATL::CTime m_time;
    CString m_strFormat;
};
MS2_CHECK_SIZE(Unk_TimeFormat, 0x10);

// Easing distance calculators: base interface and its three implementations.
class IDistanceCalculator
{
public:
    virtual float vfunc_0(float fDelta, float fTime, float fDuration, float fDistance) = 0;
};

class LinearCalculator : public IDistanceCalculator
{
public:
    virtual float vfunc_0(float fDelta, float fTime, float fDuration, float fDistance);
};

class EaseOutCalculator : public IDistanceCalculator
{
public:
    virtual float vfunc_0(float fDelta, float fTime, float fDuration, float fDistance);
    float Calc(float fTime, float fDuration, float fDistance);  // 0x1402921d0
};

class EaseInCalculator : public IDistanceCalculator
{
public:
    virtual float vfunc_0(float fDelta, float fTime, float fDuration, float fDistance);
    float Calc(float fTime, float fDuration, float fDistance); // 0x1402922c0
};

void FUN_14015f050(const CString& strText, CAtlArray<CString>& arrOut, const char* pszDelim);
bool FUN_14036e510(void* pFeatures);
void* FUN_140166410();

struct Unk_XmlElement;                                          // XML element node
CStringW FUN_1401bf530(Unk_XmlElement* pElem, const char* pszName, CStringW strDefault);
CString FUN_14015f710(Unk_XmlElement* pElem, const char* pszName, CString strDefault);
bool FUN_14036d4b0(void* pFeatures, const CStringW& strFeature);   // feature enabled
CString FUN_14036d8e0(void* pFeatures);                            // current locale name
bool FUN_1401647e0(const CString& strLeft, const CString& strRight);
Unk_XmlElement* FUN_140165cf0(Unk_XmlElement* pParent, const char* pszName);       // first child
Unk_XmlElement* FUN_140168650(Unk_XmlElement* pElem, const char* pszName);         // next sibling
void FUN_140873420(Unk_XmlElement* pElem, const char* pszName, CStringW& strOut);
void FUN_1408733e0(Unk_XmlElement* pElem, const char* pszName, CString& strOut);
struct Unk_XmlElementList;
Unk_XmlElementList* FUN_14036e160(void* pFeatures, Unk_XmlElementList* pList, Unk_XmlElement* pElem);
int FUN_1406516b0();
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
CStringW FUN_140298ea0(CStringW strKey);
CStringW FUN_14016a730(const char* psz, int n);                 // narrow -> wide
CString FUN_14016a600(const wchar_t* pwsz, int n);              // wide -> narrow
Unk_StringMgr* FUN_14025e7d0();
int FUN_14029dd60(const char* pszText, const char* pszFormat, ...);                // sscanf
void FUN_1401d3700(CString& strPath);
bool FUN_140184310(const CString& strText, const char* pszPrefix);
std::wstring FUN_140291f90(const std::wstring& strToken, int nWhich);

bool FUN_140299100(const CAtlArray<CString>& arr);              // IsEmpty

// @0x14028b820
tm* FUN_14028b820(const __time64_t* pTime)
{
    return _localtime64(pTime);
}

// Overflow-checked add (HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW) on wrap).
// @0x14028b840
HRESULT FUN_14028b840(int nA, unsigned uB, int* pnOut)
{
    if (nA + uB < uB)
        return 0x80070216;
    *pnOut = nA + uB;
    return 0;
}

// Overflow-checked 32-bit multiply.
// @0x14028b890
HRESULT FUN_14028b890(unsigned uA, unsigned uB, unsigned* puOut)
{
    unsigned long long ull64Result = (unsigned long long)uA * uB;
    if (ull64Result <= 0xffffffffull)
    {
        *puOut = (unsigned)ull64Result;
        return 0;
    }
    return 0x80070216;
}

// Looks a key up in the localized string table; empty when the table is not up yet.
// @0x14028b8e0
CStringW FUN_14028b8e0(const CStringW& strKey)
{
    if (FUN_14025e7d0() == 0)
        return L"";
    return FUN_14025e7d0()->FUN_140229820(strKey);
}

// First IPv4 address of this host as a big-endian-packed value (a.b.c.d -> 0xaabbccdd).
// @0x14028b960
unsigned FUN_14028b960()
{
    char szHost[256];
    unsigned uAddr = 0;
    if (gethostname(szHost, 256) == 0)
    {
        hostent* pHost = gethostbyname(szHost);
        if (pHost == 0)
            return 0;
        unsigned char* pbAddr = (unsigned char*)pHost->h_addr_list[0];
        uAddr |= (unsigned)*pbAddr++ << 24;
        uAddr |= (unsigned)*pbAddr++ << 16;
        uAddr |= (unsigned)*pbAddr++ << 8;
        uAddr |= (unsigned)*pbAddr++;
        return uAddr;
    }
    return 0;
}

// Same lookup, little-endian packed.
// @0x14028ba90
unsigned FUN_14028ba90()
{
    char szHost[256];
    unsigned uAddr = 0;
    if (gethostname(szHost, 256) == 0)
    {
        hostent* pHost = gethostbyname(szHost);
        if (pHost == 0)
            return 0;
        unsigned char* pbAddr = (unsigned char*)pHost->h_addr_list[0];
        uAddr |= (unsigned)*pbAddr++;
        uAddr |= (unsigned)*pbAddr++ << 8;
        uAddr |= (unsigned)*pbAddr++ << 16;
        uAddr |= (unsigned)*pbAddr++ << 24;
        return uAddr;
    }
    return 0;
}

// This host's first IPv4 address as dotted text.
// @0x14028bbc0
CString FUN_14028bbc0()
{
    CString strAddr;
    char szHost[256];
    if (gethostname(szHost, 256) == 0)
    {
        hostent* pHost = gethostbyname(szHost);
        if (!pHost)
            return "";
        in_addr* pAddr = (in_addr*)pHost->h_addr_list[0];
        strAddr.Format("%d.%d.%d.%d", pAddr->S_un.S_un_b.s_b1, pAddr->S_un.S_un_b.s_b2, pAddr->S_un.S_un_b.s_b3, pAddr->S_un.S_un_b.s_b4);
    }
    return strAddr;
}

// Dotted text of a packed IPv4 address.
// MS2-FUNCTIONAL: exe frame carries a /GS cookie for an unrecovered local (in_addr copy); ours does not
// @0x14028bd10
CString FUN_14028bd10(int nAddr)
{
    in_addr kAddr;
    kAddr.s_addr = nAddr;
    CString strAddr = FUN_140188f50(inet_ntoa(kAddr), 0);
    return strAddr;
}

// Resolves a host name and picks one of its addresses at random (empty when it does not resolve).
// MS2-FUNCTIONAL: exe frame is 0x10 larger (stack slot order of the pick locals not recovered)
// @0x14028bdb0
CString FUN_14028bdb0(const CString& strHost)
{
    hostent* pHost = gethostbyname(FUN_14016a5c0(strHost, 0));
    if (pHost == 0)
        return "";
    CAtlArray<CString> arrAddr;
    int i = 0;
    while (pHost->h_addr_list[i] != 0)
    {
        CString strAddr = FUN_140188f50(inet_ntoa(*(in_addr*)pHost->h_addr_list[i]), 0);
        if (!strAddr.IsEmpty())
            arrAddr.Add(strAddr);
        i++;
    }
    if (FUN_140299100(arrAddr))
        return "";
    unsigned long long ullRand = rand();
    unsigned long long ullCount = arrAddr.GetCount();
    return arrAddr.GetAt((int)(ullRand % ullCount));
}

// ---- string splitting and parsing helpers ----

// "r,g,b" -> 0xffRRGGBB.
// MS2-FUNCTIONAL: stack slot order of return temp vs r/g/b locals differs
// @0x14028c0d0
unsigned FUN_14028c0d0(const char* pszText)
{
    CString strText(pszText);
    CAtlArray<CString> arrParts;
    if (FUN_14028c3e0(strText, arrParts, ",", 3) == 0)
        return 0;
    unsigned uRed = atoi(arrParts[0]);
    unsigned uGreen = atoi(arrParts[1]);
    unsigned uBlue = atoi(arrParts[2]);
    uRed = (uRed & 0xff) << 16 | 0xff000000 | (uGreen & 0xff) << 8 | uBlue & 0xff;
    return uRed;
}

// 0xffRRGGBB -> "r,g,b".
// @0x14028c210
CString FUN_14028c210(unsigned uColor)
{
    unsigned uRed = uColor >> 16 & 0xff;
    unsigned uGreen = uColor >> 8 & 0xff;
    unsigned uBlue = uColor & 0xff;
    CString strColor;
    strColor.Format("%d,%d,%d", uRed, uGreen, uBlue);
    return strColor;
}

// "x,y,z" -> three floats; left untouched when the text does not split into three parts.
// @0x14028c2d0
void FUN_14028c2d0(CString strText, Unk_CommonVec3* pOut)
{
    CAtlArray<CString> arrParts;
    if (FUN_14028c3e0(strText, arrParts, ",", 3) == 0)
        return;
    pOut->x = (float)atof(arrParts[0]);
    pOut->y = (float)atof(arrParts[1]);
    pOut->z = (float)atof(arrParts[2]);
}

// Tokenizes by any character of pszDelim, at most nMax parts (the last one keeps the remaining text).
// MS2-FUNCTIONAL: stack-slot layout of the compiler temps differs from the exe
// @0x14028c3e0
int FUN_14028c3e0(const CString& strText, CAtlArray<CString>& arrOut, const char* pszDelim, int nMax)
{
    if (nMax < 2)
    {
        arrOut.Add(strText);
        return 1;
    }
    int nPos = 0;
    CString strToken = strText.Tokenize(pszDelim, nPos);
    while (!strToken.IsEmpty())
    {
        arrOut.Add(strToken);
        if ((size_t)(nMax - 1) < arrOut.GetCount())
        {
            arrOut.Add(strText.Mid(nPos));
            return 1;
        }
        strToken = strText.Tokenize(pszDelim, nPos);
    }
    return 0;
}

// Splits on pszSep, returns whether exactly nExpected parts came out.
// MS2-FUNCTIONAL: stack-slot layout of the compiler temps differs from the exe
// @0x14028c570
int FUN_14028c570(const CString& strText, CAtlArray<CString>& arrOut, const char* pszSep, int nExpected)
{
    CString strPart;
    int nPos = 0;
    int nFound;
    while ((nFound = strText.Find(pszSep, nPos)) != -1)
    {
        strPart = strText.Mid(nPos);
        arrOut.Add(strPart);
        nPos = nFound + 1;
    }
    strPart = strText.Mid(nPos);
    arrOut.Add(strPart);
    if (arrOut.GetCount() == nExpected)
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: stack-slot layout of the compiler temps differs from the exe
// @0x14028c700
void FUN_14028c700(const CString& strText, CAtlArray<CString>& arrOut, const char* pszSep)
{
    CString strPart;
    int nPos = 0;
    int nFound;
    while ((nFound = strText.Find(pszSep, nPos)) != -1)
    {
        strPart = strText.Mid(nPos);
        arrOut.Add(strPart);
        nPos = nFound + 1;
    }
    strPart = strText.Mid(nPos);
    arrOut.Add(strPart);
}

// Splits on pszSep into at most nMax parts (the last one keeps the remaining text).
// MS2-FUNCTIONAL: stack-slot layout of the compiler temps differs from the exe
// @0x14028c850
void FUN_14028c850(const CString& strText, CAtlArray<CString>& arrOut, const char* pszSep, int nMax)
{
    if (nMax < 2)
    {
        arrOut.Add(strText);
    }
    else
    {
        CString strPart;
        int nPos = 0;
        for (int i = 0; i < nMax; ++i)
        {
            int nFound = strText.Find(pszSep, nPos);
            if (nFound == -1)
            {
                strPart = strText.Mid(nPos);
                arrOut.Add(strPart);
                break;
            }
            if (nMax - 1 <= i)
            {
                arrOut.Add(strText.Mid(nPos));
                return;
            }
            strPart = strText.Mid(nPos);
            arrOut.Add(strPart);
            nPos = nFound + 1;
        }
    }
}

// Collects the text between each pair of strOpen/strClose markers.
// MS2-FUNCTIONAL: stack-slot layout of the compiler temps differs from the exe
// @0x14028ca50
void FUN_14028ca50(const CString& strText, CAtlArray<CString>& arrOut, const CString& strOpen, const CString& strClose)
{
    if (strText.IsEmpty())
        return;
    int nPos = 0;
    while (true)
    {
        int nOpen = strText.Find(strOpen, nPos);
        if (nOpen == -1)
            break;
        nPos = strText.Find(strClose, nPos);
        if (nPos == -1)
            return;
        CString strInner = strText.Mid(nOpen);
        if (0 < strInner.GetLength())
            arrOut.Add(strInner);
        nPos = nPos + 1;
    }
}

// MS2-FUNCTIONAL: not yet byte-matched (std::string glue pairing / frame layout)
// @0x14028cb70
int FUN_14028cb70(const CStringW& strText, CAtlArray<CStringW>& arrOut, const wchar_t* pszSep, int nExpected)
{
    CStringW strPart;
    int nPos = 0;
    int nFound;
    while ((nFound = strText.Find(pszSep, nPos)) != -1)
    {
        strPart = strText.Mid(nPos);
        arrOut.Add(strPart);
        nPos = nFound + 1;
    }
    strPart = strText.Mid(nPos);
    arrOut.Add(strPart);
    if (arrOut.GetCount() == nExpected)
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: not yet byte-matched (std::string glue pairing / frame layout)
// @0x14028cd00
void FUN_14028cd00(const CStringW& strText, CAtlArray<CStringW>& arrOut, const wchar_t* pszSep, int nMax)
{
    if (nMax < 2)
    {
        arrOut.Add(strText);
    }
    else
    {
        CStringW strPart;
        int nPos = 0;
        for (int i = 0; i < nMax; ++i)
        {
            int nFound = strText.Find(pszSep, nPos);
            if (nFound == -1)
            {
                strPart = strText.Mid(nPos);
                arrOut.Add(strPart);
                break;
            }
            if (nMax - 1 <= i)
            {
                arrOut.Add(strText.Mid(nPos));
                return;
            }
            strPart = strText.Mid(nPos);
            arrOut.Add(strPart);
            nPos = nFound + 1;
        }
    }
}

// MS2-FUNCTIONAL: not yet byte-matched (std::string glue pairing / frame layout)
// @0x14028cf00
void FUN_14028cf00(const CStringW& strText, CAtlArray<CStringW>& arrOut, const CStringW& strOpen, const CStringW& strClose)
{
    if (strText.IsEmpty())
        return;
    int nPos = 0;
    while (true)
    {
        int nOpen = strText.Find(strOpen, nPos);
        if (nOpen == -1)
            break;
        nPos = strText.Find(strClose, nPos);
        if (nPos == -1)
            return;
        CStringW strInner = strText.Mid(nOpen);
        if (0 < strInner.GetLength())
            arrOut.Add(strInner);
        nPos = nPos + 1;
    }
}

// Sums 1 << (n - 1) over a comma separated list of numbers (a bit mask from 1-based indices).
// @0x14028d020
int FUN_14028d020(const CStringW& strList)
{
    int nMask = 0;
    std::vector<int> arrValues;
    FUN_1402929a0(strList, arrValues, L",");
    for (size_t i = 0; i < arrValues.size(); ++i)
        nMask = nMask + (1 << (arrValues[i] - 1));
    return nMask;
}

// Unique 64-bit id: server time (offset by 1e9) followed by five digits of a process-wide counter.
// @0x14028d0e0
__int64 FUN_14028d0e0()
{
    __int64 nId = 0;
    int nSeq = FUN_140298fd0(&g_lUniqueSeq);
    __int64 nTime = FUN_140869440();
    nTime = nTime - 1000000000;
    CString strId;
    strId.Format("%09I64d%05d", nTime, nSeq % 100000);
    nId = _atoi64(strId);
    return nId;
}

// @0x14028d1a0
void FUN_14028d1a0(const CString& strText, int* pnOut)
{
    *pnOut = 0;
    if (strText.CompareNoCase("true") == 0)
        *pnOut = 1;
}

// @0x14028d1f0
CString FUN_14028d1f0(const char* psz)
{
    if (psz == 0)
        return "";
    return FUN_140188f50(psz, 0);
}

// Seconds <-> milliseconds helpers.
// @0x14028d260
__int64 FUN_14028d260(float fSeconds)
{
    return (__int64)(fSeconds * 1000.0f);
}

// @0x14028d280
float FUN_14028d280(unsigned uMilliseconds)
{
    return (float)uMilliseconds * 0.001f;
}

// Random float in [-1, 1].
// @0x14028d2a0
float FUN_14028d2a0()
{
    return -1.0f + (2.0f * (float)rand()) / 32767.0f;
}

// Random float in [0, 1].
// @0x14028d2e0
float FUN_14028d2e0()
{
    return (float)rand() / 32767.0f;
}

// Rolls a probability: never for (nearly) zero, always for exactly 1.
// @0x14028d310
BOOL FUN_14028d310(float fChance)
{
    if (FUN_14028d470(fChance, 0.0f))
        return FALSE;
    else if (fChance == 1.0f)
        return TRUE;
    return FUN_14028d2e0() <= fChance;
}

// @0x14028d380
float FUN_14028d380(float fValue)
{
    return fValue * 100.0f;
}

// @0x14028d3a0
float FUN_14028d3a0(float fValue)
{
    return fValue * 0.01f;
}

// Directory part of a path.
// @0x14028d3c0
CString FUN_14028d3c0(CString strPath)
{
    char szDir[256];
    _splitpath(strPath, 0, 0, szDir, 0);
    return CString(szDir);
}

// Whether two floats are closer than 1e-6.
// @0x14028d470
bool FUN_14028d470(float fA, float fB)
{
    if (FUN_14029d220(fA - fB) < 1e-06f)
        return true;
    return false;
}

// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d4b0
int FUN_14028d4b0(const Unk_CommonVec3* pA, const Unk_CommonVec3* pB)
{
    if (FUN_14028d470(pA->x, pB->x) && FUN_14028d470(pA->y, pB->y) && FUN_14028d470(pA->z, pB->z))
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d530
int FUN_14028d530(const Unk_CommonVec3* pA, const Unk_CommonVec3* pB)
{
    if (FUN_14028d470(pA->x, pB->x) && FUN_14028d470(pA->y, pB->y) && FUN_14028d470(pA->z, pB->z))
        return 1;
    return 0;
}

// Wraps an angle in degrees into [-180, 180].
// @0x14028d5b0
float FUN_14028d5b0(float fDegrees)
{
    fDegrees = fmodf(fDegrees, 360.0f);
    if (180.0f < fDegrees)
        fDegrees = fDegrees - 360.0f;
    if (fDegrees < -180.0f)
        fDegrees = fDegrees + 360.0f;
    return fDegrees;
}

// A random direction (uniform angle) scaled by fScale.
// @0x14028d630
Unk_CommonVec2 FUN_14028d630(float fScale)
{
    float fAngle = FUN_140768090() * 360.0f;
    Unk_CommonVec2 kDir;
    kDir.x = cos(fAngle * 3.1415927f / 180.0f);
    kDir.y = sin(fAngle * 3.1415927f / 180.0f);
    return kDir * fScale;
}

// Appends the first nCount (or nLen when nCount is 0) bytes as upper-case hex.
// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d6d0
void FUN_14028d6d0(const unsigned char* pData, int nLen, CString& strOut, int nCount)
{
    if (nCount == 0)
        nCount = nLen;
    for (int i = 0; i < nLen && i < nCount; ++i)
        strOut.AppendFormat("%02X", pData[i]);
}

// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d760
bool FUN_14028d760(char c)
{
    return c ? true : false;
}

// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d780
bool FUN_14028d780(char c)
{
    return c ? true : false;
}

// ---- file/path name helpers and localized text ----

// Last "/"-separated component of a path.
// @0x14028d7a0
CString FUN_14028d7a0(const CString& strPath)
{
    CAtlArray<CString> arrParts;
    FUN_14015f050(strPath, arrParts, "/");
    if (arrParts.GetCount() == 0)
        return "";
    int nLast = (int)arrParts.GetCount() - 1;
    CString strName = arrParts[nLast];
    return strName;
}

// Second-to-last "/"-separated component of a path (the parent folder name).
// @0x14028d890
CString FUN_14028d890(const CString& strPath)
{
    CAtlArray<CString> arrParts;
    FUN_14015f050(strPath, arrParts, "/");
    if (arrParts.GetCount() < 2)
        return "";
    int nLast = (int)arrParts.GetCount() - 2;
    CString strName = arrParts[nLast];
    return strName;
}

// @0x14028d990
CString FUN_14028d990(const CString& strPath)
{
    if (FUN_14036e510(FUN_140166410()))
        return FUN_14028d890(strPath);
    return FUN_14028d7a0(strPath);
}

// @0x14028da10
unsigned char FUN_14028da10()
{
    int nType = FUN_1406516b0();
    unsigned char ucResult = 0;
    if (nType == 3)
        ucResult = 4;
    else
        ucResult = 1;
    return ucResult;
}

// Current server time plus the format used to print it.
// @0x14028da50
Unk_TimeFormat::Unk_TimeFormat() : m_time(FUN_140869440())
{
    m_strFormat = L"%A, %B %d, %Y, %H:%M";
}

// @0x14028dac0
void Unk_TimeFormat::SetFormat(CString strFormat)
{
    m_strFormat = strFormat;
}

// @0x14028db10
CString Unk_TimeFormat::Format() const
{
    return m_time.Format(m_strFormat);
}

// @0x14028db70
CString FUN_14028db70()
{
    Unk_TimeFormat kTime;
    return kTime.Format();
}

// "Mon DD YYYY HH:MM:SS" of the build.
// @0x14028dbd0
CString FUN_14028dbd0()
{
    CString strBuild;
    strBuild.Format("%s %s", "Apr 13 2022", "17:36:52");
    return FUN_140188f50(strBuild, 0);
}

// @0x14028dc60
void* FUN_14028dc60(void* p)
{
    return p;
}

// String table lookups: narrow text of an id / of a key, wide text with {n} arguments.
// @0x14028dc80
CString FUN_14028dc80(int nId)
{
    return FUN_14025e7d0()->FUN_140229600(nId);
}

// @0x14028dcd0
CString FUN_14028dcd0(const CString& strKey)
{
    return FUN_14025e7d0()->FUN_140229690(strKey);
}

// @0x14028dd20
CString FUN_14028dd20(int nId, const fmt::ArgList& args)
{
    return FUN_14016a600(FUN_14028dee0(nId, args), 0);
}

// @0x14028ddb0
CString FUN_14028ddb0(const CString& strKey, const fmt::ArgList& args)
{
    return FUN_14016a600(FUN_140298ea0(FUN_14016a730(strKey, 0)), 0);
}

// @0x14028de60
CStringW FUN_14028de60(int nId)
{
    if (FUN_14025e7d0() == 0)
        return L"";
    return FUN_14025e7d0()->FUN_140229760(nId);
}

// @0x14028dee0
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args)
{
    CStringW strText = FUN_14028de60(nId);
    if (strText.IsEmpty())
        return L"";
    return StringFormat(strText, args);
}

// @0x14028dfa0
CStringW FUN_14028dfa0(const CStringW& strKey, const fmt::ArgList& args)
{
    CStringW strText = FUN_14028b8e0(strKey);
    if (strText.IsEmpty())
        return L"";
    return StringFormat(strText, args);
}

// @0x14028e060
CStringW FUN_14028e060(const CString& strKey, const fmt::ArgList& args)
{
    if (FUN_14025e7d0() == 0)
        return L"";
    CStringW strText = FUN_14025e7d0()->FUN_140229940(strKey);
    if (strText.IsEmpty())
        return L"";
    return StringFormat(strText, args);
}

// Day-of-week number (1 = Sun .. 7 = Sat) of a three-letter abbreviation, 0 when unknown.
// @0x14028e160
int FUN_14028e160(CString& strDay)
{
    if (strDay.IsEmpty())
        return 0;
    if (strDay.CompareNoCase("sun") == 0)
        return 1;
    else if (strDay.CompareNoCase("mon") == 0)
        return 2;
    else if (strDay.CompareNoCase("tue") == 0)
        return 3;
    else if (strDay.CompareNoCase("wed") == 0)
        return 4;
    else if (strDay.CompareNoCase("thu") == 0)
        return 5;
    else if (strDay.CompareNoCase("fri") == 0)
        return 6;
    else if (strDay.CompareNoCase("sat") == 0)
        return 7;
    return 0;
}

// Parses a date/time text with a scanf-style format into a CMsTime; false when out of range.
// MS2-FUNCTIONAL: compiler temp-copy spill layout and EH state count differ
// @0x14028e280
int FUN_14028e280(CMsTime& kOut, const CString& strFormat, const CString& strText)
{
    int nYear = 0;
    int nMonth = 0;
    int nDay = 0;
    int nHour = 0;
    int nMinute = 0;
    int nSecond = 0;
    FUN_14029dd60((LPCSTR)CString(strText), (LPCSTR)CString(strFormat), &nYear, &nMonth, &nDay, &nHour, &nMinute, &nSecond);
    if (!(nYear < 1900 || nMonth < 1 || nMonth > 12 || nDay < 1 || nDay > 31 || nHour < 0 || nHour > 23 || nMinute < 0
          || nMinute > 59 || nSecond < 0 || nSecond > 59))
    {
        kOut = CMsTime(nYear, nMonth, nDay, nHour, nMinute, nSecond);
        return 1;
    }
    return 0;
}

// @0x14028e440
CString FUN_14028e440(const CMsTime& kTime, const CString& strFormat)
{
    CString strResult;
    strResult.Format(strFormat, kTime.GetYear(), kTime.GetMonth(), kTime.GetDay(), kTime.GetHour(), kTime.GetMinute(),
                     kTime.GetSecond());
    return strResult;
}

// Replaces every "(token)" in the text with its translation; true when anything was found.
// MS2-FUNCTIONAL: std::string temp/EH layout differs
// @0x14028e560
bool FUN_14028e560(std::wstring& strText, int nWhich)
{
    bool bFound = false;
    const wchar_t* pwszDelim = L"()";
    while (true)
    {
        size_t nOpen = strText.find(pwszDelim[0], 0);
        if (nOpen == (size_t)-1)
            return bFound;
        size_t nClose = strText.find(pwszDelim[1], nOpen);
        if (nClose == (size_t)-1)
            break;
        std::wstring strToken;
        strToken = strText.substr(nOpen + 1, nClose - nOpen - 1);
        if (strToken.size() == 0)
            return bFound;
        bFound = true;
        std::wstring strTranslated = FUN_140291f90(strToken, nWhich);
        strText.replace(strText.begin() + nOpen, strText.begin() + nClose + 1, strTranslated.c_str(), strTranslated.size());
    }
    return bFound;
}

// @0x14028e7c0
void FUN_14028e7c0(CString& strPath)
{
    FUN_1401d3700(strPath);
    CString strHead = strPath.Left(4);
    if (FUN_140184310(strHead, "data"))
        strPath = FUN_140298360("./", strPath);
    else if (FUN_140184310(strHead, "/data"))
        strPath = FUN_140298360(".", strPath);
    strPath.Replace('\\', '/');
}

// @0x14028e900
int FUN_14028e900(CString strPath)
{
    int nResult = 0;
    try
    {
        CFile::Remove(strPath, 0);
        nResult = 1;
    }
    catch (CFileException* pException)
    {
        pException->Delete();
    }
    return nResult;
}

// Easing calculator factory: 0 linear, 1 ease out, 2 ease in.
// @0x14028e960
IDistanceCalculator* FUN_14028e960(int nType)
{
    if (nType == 0)
        return new LinearCalculator();
    else if (nType == 1)
        return new EaseOutCalculator();
    else if (nType == 2)
        return new EaseInCalculator();
    else
        return 0;
}

bool FUN_14028f650(Unk_XmlElement* pElem);

// Collects every sibling element of the given name that passes the feature filter.
// @0x14028f5d0
void FUN_14028f5d0(Unk_XmlElement* pParent, const char* pszChild, std::vector<Unk_XmlElement*>& arrOut)
{
    for (Unk_XmlElement* pElem = FUN_140165cf0(pParent, pszChild); pElem != 0; pElem = FUN_140168650(pElem, pszChild))
    {
        if (!FUN_14028f650(pElem))
            continue;
        arrOut.push_back(pElem);
    }
}

// True when the element's "feature" attribute is empty or enabled.
// @0x14028f650
bool FUN_14028f650(Unk_XmlElement* pElem)
{
    CStringW strFeature = FUN_1401bf530(pElem, "feature", CStringW(L""));
    if (!strFeature.IsEmpty())
    {
        if (!FUN_14036d4b0(FUN_140166410(), strFeature))
            return false;
    }
    return true;
}

// True when the element's "locale" matches the current locale and its "feature" is enabled.
// MS2-FUNCTIONAL: wide default-string temp and EH cookie slot placement differ
// @0x14028f710
bool FUN_14028f710(Unk_XmlElement* pElem)
{
    CString strLocale = FUN_14015f710(pElem, "locale", CString(""));
    bool bMatch = !strLocale.IsEmpty() && FUN_1401647e0(strLocale, FUN_14036d8e0(FUN_140166410()));
    if (bMatch)
        return false;
    CStringW strFeature = FUN_1401bf530(pElem, "feature", CStringW(L""));
    if (!strFeature.IsEmpty())
    {
        if (!FUN_14036d4b0(FUN_140166410(), strFeature))
            return false;
    }
    return true;
}

// Collects the <environment> children whose locale/feature conditions pass.
// MS2-FUNCTIONAL: not yet byte-matched (temp lifetime flags)
// @0x14028f8d0
Unk_XmlElementList* FUN_14028f8d0(Unk_XmlElement* pParent)
{
    Unk_XmlElementList* pResult = 0;
    for (Unk_XmlElement* pElem = FUN_140165cf0(pParent, "environment"); pElem; pElem = FUN_140168650(pElem, "environment"))
    {
        CStringW strFeature;
        CString strLocale;
        FUN_140873420(pElem, "feature", strFeature);
        FUN_1408733e0(pElem, "locale", strLocale);
        bool bLocale = !strLocale.IsEmpty() && FUN_1401647e0(strLocale, FUN_14036d8e0(FUN_140166410()));
        if (!bLocale)
        {
            if (!FUN_14036d4b0(FUN_140166410(), strFeature))
                continue;
            pResult = FUN_14036e160(FUN_140166410(), pResult, pElem);
        }
    }
    return pResult;
}

// Shows a modal error box: caption + Format(fmt, nCode) + the suffix text.
// MS2-FUNCTIONAL: not yet byte-matched (by-value CString params destroyed by callee)
// @0x14028bfb0
void FUN_14028bfb0(CString strCaption, CString strFormat, unsigned int nCode, CString strSuffix)
{
    CString strText;
    strText.Format((const char*)strFormat, nCode);
    strText += FUN_140298360(" ", strSuffix);
    const char* pszCaption = strCaption;
    MessageBoxA(0, (const char*)strText, pszCaption, MB_ICONERROR);
}

// @0x14028c0b0
void FUN_14028c0b0()
{
    PostQuitMessage(0);
}

CStringW FormatStringId(int nId, const fmt::ArgList& args);     // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)

// Appends a timestamped line to .\\log\\<name>_<date>.txt (the per-name file name is cached in a local map).
// @0x14028ea70
void FUN_14028ea70(const char* pszName, const char* pszFormat, ...)
{
    CRBMap<CString, CString, CStringElementTraits<CString> > mapFile(10);
    CString strName(pszName);
    CString strMsg;
    va_list args;
    va_start(args, pszFormat);
    strMsg.FormatV(pszFormat, args);
    va_end(args);
    SYSTEMTIME kTime;
    GetLocalTime(&kTime);
    CString strLine;
    strLine.Format("[%02d:%02d:%02d.%03d]", kTime.wHour, kTime.wMinute, kTime.wSecond, kTime.wMilliseconds);
    strLine += strMsg;
    strLine += "\r\n";
    CString strFile("");
    mapFile.Lookup(strName, strFile);
    if (strFile.IsEmpty() == true)
    {
        strFile.Format("%s_%04d%02d%02d.txt", pszName, kTime.wYear, kTime.wMonth, kTime.wDay);
        CString strDir(".\\log");
        char szFull[260];
        _fullpath(szFull, FUN_14016a5c0(strDir, 0), 260);
        CreateDirectoryA(szFull, 0);
        mapFile.SetAt(strName, strFile);
    }
    ATL::CAtlFile file;
#ifdef __clang__
    CString strPath(".\\log\\"); // clang would import MFC CopyChars for operator+
    strPath.Append(strFile);
    file.Create(strPath, GENERIC_WRITE, 3, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0, 0);
#else
    file.Create(".\\log\\" + strFile, GENERIC_WRITE, 3, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0, 0);
#endif
    file.Seek(0, FILE_END);
    ATL::CStringT<char, ATL::StrTraitATL<char, ATL::ChTraitsCRT<char> > > strWrite(strLine);
    file.Write(strWrite.GetString(), strWrite.GetLength(), (DWORD*)0);
    file.Close();
}

// Wraps the text with the current-time prefix when flag 8 is set and the time converts.
// @0x14028ee20
CStringW FUN_14028ee20(unsigned int nFlags, CStringW strText)
{
    if (nFlags & 8)
    {
        __time64_t tNow = FUN_140869440();
        tm* pTm = FUN_14028b820(&tNow);
        if (pTm)
            return FormatStringId(0xa9, pTm->tm_hour, pTm->tm_min, strText);
    }
    return strText;
}

// "x,y,z" of a float triple.
// @0x14028ef00
CString FUN_14028ef00(const Unk_CommonVec3* pVec)
{
    CString strOut;
    strOut.Format("%f,%f,%f", (double)pVec->x, (double)pVec->y, (double)pVec->z);
    return strOut;
}

// @0x14028efb0
CStringW FUN_14028efb0(const Unk_CommonVec3* pVec)
{
    CStringW strOut;
    strOut.Format(L"%f,%f,%f", (double)pVec->x, (double)pVec->y, (double)pVec->z);
    return strOut;
}

extern const Unk_CommonVec3 g_vCommonZero;                      // 0x143b01a60
void FUN_1401780b0(const CString& strText, CAtlArray<float>& arrOut, const char* pszDelim);
void FUN_1402928e0(const CStringW& strText, CAtlArray<float>& arrOut, const wchar_t* pszDelim);

// Parses "x,y,z"; anything else gives the zero vector.
// MS2-FUNCTIONAL: not yet byte-matched (struct copy lowering)
// @0x14028f060
Unk_CommonVec3 FUN_14028f060(CString strText)
{
    Unk_CommonVec3 vResult = g_vCommonZero;
    CAtlArray<float> arrParts;
    FUN_1401780b0(strText, arrParts, ",");
    if (arrParts.GetCount() == 3)
    {
        vResult.x = arrParts[0];
        vResult.y = arrParts[1];
        vResult.z = arrParts[2];
    }
    return vResult;
}

// MS2-FUNCTIONAL: not yet byte-matched (std::string glue pairing / frame layout)
// @0x14028f190
Unk_CommonVec3 FUN_14028f190(CStringW strText)
{
    Unk_CommonVec3 vResult = g_vCommonZero;
    CAtlArray<float> arrParts;
    FUN_1402928e0(strText, arrParts, L",");
    if (arrParts.GetCount() == 3)
    {
        vResult.x = arrParts[0];
        vResult.y = arrParts[1];
        vResult.z = arrParts[2];
    }
    return vResult;
}

// Maps a locale/region id to its group id.
// @0x14028f2c0
int FUN_14028f2c0(int nKind, int nUnused)
{
    switch (nKind)
    {
    case 1:
        return 9;
    case 3:
    case 7:
        return 11;
    case 4:
    case 6:
        return 12;
    default:
        return 0;
    }
}

// @0x14028f460
void FUN_14028f460(void* pUnused, CString strUnused)
{
}

// @0x14028f490
int FUN_14028f490(unsigned int nId, CString strError)
{
    CString strText;
    strText.Format("ADDITIONALEFFECT [%d] ERROR[%s]", nId, (const char*)strError);
    MessageBoxA(0, (const char*)strText, "ExcelTaskSkill", 0);
    return 0;
}

// Escapes the angle brackets for XML text.
// @0x14028f530
void FUN_14028f530(CString& strText)
{
    strText.Replace("<", "&lt;");
    strText.Replace(">", "&gt;");
}

// @0x14028f580
void FUN_14028f580(CStringW& strText)
{
    strText.Replace(L"<", L"&lt;");
    strText.Replace(L">", L"&gt;");
}

#include <string>
#include "ms2/placeholder/clockcriticalsection.h"

// Item tab name table: per inventory tab the names it is known by (English keys, then localized names).
class CItemTabNameTable
{
public:
    CItemTabNameTable();                                        // 0x140290460
    void Init();                                                // 0x1402906b0
    int FindIndex(std::string strName);                         // 0x1402904d0
    const std::string& GetTabName(int nTab);                    // 0x1402905e0

    std::vector<std::string> m_arrNames[15];                    // +0x00
    CLockCriticalSection m_lock;                                // +0x168
};
MS2_CHECK_SIZE(CItemTabNameTable, 0x198);

static CStringA s_strSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};  // 0x143aacda0
CItemTabNameTable g_ItemTabNames;                               // 0x143aacde0

// @0x140290460
CItemTabNameTable::CItemTabNameTable()
{
    Init();
}

// Fills the table. The localized names are CP949 text.
// MS2-FUNCTIONAL: not yet byte-matched (string temp slots)
// @0x1402906b0
void CItemTabNameTable::Init()
{
    Unk_LockGuard guard(m_lock);
    m_arrNames[0].push_back(std::string("game"));
    m_arrNames[1].push_back(std::string("skin"));
    m_arrNames[2].push_back(std::string("summon"));
    m_arrNames[3].push_back(std::string("material"));
    m_arrNames[4].push_back(std::string("life"));
    m_arrNames[5].push_back(std::string("quest"));
    m_arrNames[6].push_back(std::string("gem"));
    m_arrNames[7].push_back(std::string("misc"));
    m_arrNames[8].push_back(std::string("mastery"));
    m_arrNames[9].push_back(std::string("pet"));
    m_arrNames[13].push_back(std::string("lapenshard"));
    m_arrNames[10].push_back(std::string("activeskill"));
    m_arrNames[11].push_back(std::string("coin"));
    m_arrNames[12].push_back(std::string("badge"));
    m_arrNames[14].push_back(std::string("piece"));
    for (unsigned int nTab = 0; nTab < 15; ++nTab)
    {
        for (unsigned int nSub = 0; nSub < m_arrNames[nTab].size(); ++nSub)
        {
            if (m_arrNames[nTab][nSub].size() == 0)
                _wassert(L"vTabNames[tabIndex][subIndex].size()", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.cpp", 0x811);
        }
    }
    m_arrNames[0].push_back(std::string("equip"));
    m_arrNames[0].push_back(std::string("\xc0\xe5\xba\xf1"));
    m_arrNames[1].push_back(std::string("\xbd\xba\xc5\xb2"));
    m_arrNames[2].push_back(std::string("\xbc\xd2\xc8\xaf"));
    m_arrNames[3].push_back(std::string("\xc0\xe7\xb7\xe1"));
    m_arrNames[4].push_back(std::string("\xbb\xfd\xc8\xb0"));
    m_arrNames[5].push_back(std::string("\xc4\xf9\xbd\xba\xc6\xae"));
    m_arrNames[6].push_back(std::string("gemstone"));
    m_arrNames[6].push_back(std::string("\xc1\xaa\xbd\xba\xc5\xe6"));
    m_arrNames[7].push_back(std::string("etc"));
    m_arrNames[7].push_back(std::string("\xb1\xe2\xc5\xb8"));
    m_arrNames[8].push_back(std::string("\xbb\xfd\xc8\xb0\xb1\xe2\xbc\xfa"));
    m_arrNames[9].push_back(std::string("\xc6\xea"));
    m_arrNames[13].push_back(std::string("\xb6\xf3\xc6\xe6\xbb\xfe\xb5\xe5"));
    m_arrNames[10].push_back(std::string("\xbc\xd2\xba\xf1"));
    m_arrNames[11].push_back(std::string("\xc8\xad\xc6\xf3"));
    m_arrNames[12].push_back(std::string("\xb9\xe8\xc1\xf6"));
    m_arrNames[14].push_back(std::string("\xc1\xb6\xb0\xa2"));
}

// Tab index that knows the name, or -1.
// MS2-FUNCTIONAL: not yet byte-matched
// @0x1402904d0
int CItemTabNameTable::FindIndex(std::string strName)
{
    for (unsigned int nTab = 0; nTab < 15; ++nTab)
    {
        for (unsigned int nSub = 0; nSub < m_arrNames[nTab].size(); ++nSub)
        {
            if (strName.compare(m_arrNames[nTab][nSub]) == 0)
                return nTab;
        }
    }
    _wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.cpp", 0x841);
    return -1;
}

// @0x140291150
char FUN_140291150(int nTab)
{
    int bValid;
    if (nTab > -1 && nTab < 15)
        bValid = 1;
    else
        bValid = 0;
    return bValid;
}

// First name of the tab.
// MS2-FUNCTIONAL: not yet byte-matched
// @0x1402905e0
const std::string& CItemTabNameTable::GetTabName(int nTab)
{
    static std::string s_strEmpty;
    if (!FUN_140291150(nTab))
    {
        _wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.cpp", 0x82f);
        return s_strEmpty;
    }
    return m_arrNames[nTab][0];
}

// MS2-FUNCTIONAL: not yet byte-matched (std::string glue pairing / frame layout)
// @0x140291190
int FUN_140291190(std::string strName)
{
    return g_ItemTabNames.FindIndex(strName);
}

// MS2-FUNCTIONAL: not yet byte-matched (std::string glue pairing / frame layout)
// @0x140291200
int FUN_140291200(CString strName)
{
    std::string strText((const char*)strName);
    return g_ItemTabNames.FindIndex(strText);
}

// @0x1402912d0
int FUN_1402912d0(CStringW strName)
{
    return FUN_140291200(CString((const wchar_t*)strName));
}

// MS2-FUNCTIONAL: not yet byte-matched (std::string glue pairing / frame layout)
// @0x140291340
bool FUN_140291340(int nTab, std::string& strOut)
{
    strOut = g_ItemTabNames.GetTabName(nTab);
    return strOut.size() != 0;
}

bool FUN_140292820(const std::string& strLeft, const char* pszRight);   // string equals
ATL::CTime FUN_1406c47a0(__int64 nTime);                                // CTime from a time_t
ATL::CTime FUN_1406c47d0(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec);
__int64 FUN_140282020(const ATL::CTime& time);                          // time_t of a CTime
__int64 FUN_14086b190(int nKind, __int64 nTime);
const std::string& FUN_14018ef70(const std::string& str);
void* FUN_1401d3200();                                                  // game config singleton
void FUN_1402b7560(void* pEntry, const char* pszMessage);

// Config option entries: set flag at +8, value after the header.
struct Unk_IntOptionEntry
{
    void* m_unk00;
    bool m_bSet;
    unsigned char m_unk09[0x47];
    int m_nValue;
    int& FUN_140298f40();                                       // 0x140298f40
};

struct Unk_StringOptionEntry
{
    void* m_unk00;
    bool m_bSet;
    unsigned char m_unk09[0x47];
    CString m_strValue;
    CString& FUN_140298f80();                                   // 0x140298f80
};

// Item tab key of a tab string (empty string = "all"); the tab key is also written to strTabOut.
// MS2-FUNCTIONAL: not yet byte-matched
// @0x1402913b0
int FUN_1402913b0(CString strTab, CString& strTabOut)
{
    int nTab = -1;
    strTabOut = "";
    if (strTab.IsEmpty())
    {
        nTab = 15;
        strTabOut = "all";
    }
    else
    {
        nTab = FUN_140291200(strTab);
    }
    if (FUN_140291150(nTab))
    {
        std::string strName;
        FUN_140291340(nTab, strName);
        strTabOut = strName.c_str();
    }
    if (nTab == 0)
        strTabOut = "equip";
    else if (nTab == 6)
        strTabOut = "gemstone";
    else if (nTab == 7)
        strTabOut = "etc";
    if (strTabOut.IsEmpty())
        _wassert(L"!outTabStr.IsEmpty()", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.cpp", 0x883);
    return nTab;
}

// Avatar tab key.
// @0x140291550
std::string FUN_140291550(int nKind)
{
    switch (nKind)
    {
    case 0:
        return std::string("game");
    case 1:
        return std::string("skin");
    case 2:
        return std::string("codi");
    default:
        return std::string("");
    }
}

// @0x140291620
int FUN_140291620(const std::string& strKey)
{
    if (FUN_140292820(strKey, "game"))
        return 0;
    else if (FUN_140292820(strKey, "skin"))
        return 1;
    else if (FUN_140292820(strKey, "codi"))
        return 2;
    return 3;
}

// Time of the next reset: 1 = next midnight, 2 = server-defined, 3 = first of next month, else the far future.
// MS2-FUNCTIONAL: not yet byte-matched
// @0x1402916a0
__int64 FUN_1402916a0(__int64 nTime, int nMode)
{
    ATL::CTime timeNow = FUN_1406c47a0(nTime);
    __int64 nResult;
    if (nMode == 1)
    {
        ATL::CTime timeDay = FUN_1406c47d0(timeNow.GetYear(), timeNow.GetMonth(), timeNow.GetDay(), 0, 0, 0);
        timeDay += ATL::CTimeSpan(1, 0, 0, 0);
        nResult = FUN_140282020(timeDay);
    }
    else if (nMode == 2)
    {
        ATL::CTime timeOther = FUN_1406c47a0(FUN_14086b190(6, nTime));
        nResult = FUN_140282020(timeOther);
    }
    else if (nMode == 3)
    {
        int nYear = timeNow.GetYear();
        int nMonth = timeNow.GetMonth();
        nMonth = nMonth + 1;
        if (nMonth > 12)
        {
            nMonth = 1;
            nYear = nYear + 1;
        }
        ATL::CTime timeMonth = FUN_1406c47d0(nYear, nMonth, 1, 0, 0, 0);
        nResult = FUN_140282020(timeMonth);
    }
    else
    {
        ATL::CTime timeFar = FUN_1406c47d0(2500, 1, 1, 0, 0, 0);
        nResult = FUN_140282020(timeFar);
    }
    return nResult;
}

// Wraps a degree value into [0, 360).
// @0x140291b70
void FUN_140291b70(float* pfDegrees)
{
    int nDegrees = (int)*pfDegrees;
    nDegrees = nDegrees % 360;
    if (nDegrees < 0)
        nDegrees = nDegrees + 360;
    *pfDegrees = (float)nDegrees;
}

// @0x140291bc0
void FUN_140291bc0(Unk_CommonVec3* pVec)
{
    FUN_140291b70(&pVec->x);
    FUN_140291b70(&pVec->y);
    FUN_140291b70(&pVec->z);
}

// @0x140291c10
CString FUN_140291c10(int nKind)
{
    switch (nKind)
    {
    case 1:
        return reinterpret_cast<Unk_StringOptionEntry*>((char*)FUN_1401d3200() + 0x8170)->FUN_140298f80();
    case 2:
        return reinterpret_cast<Unk_StringOptionEntry*>((char*)FUN_1401d3200() + 0x81d0)->FUN_140298f80();
    case 3:
        return reinterpret_cast<Unk_StringOptionEntry*>((char*)FUN_1401d3200() + 0x8230)->FUN_140298f80();
    default:
        return CString("");
    }
}

// MS2-FUNCTIONAL: not yet byte-matched (std::string glue pairing / frame layout)
// @0x140291d10
int FUN_140291d10(int nKind)
{
    switch (nKind)
    {
    case 1:
        return reinterpret_cast<Unk_IntOptionEntry*>((char*)FUN_1401d3200() + 0x8068)->FUN_140298f40();
    case 2:
        return reinterpret_cast<Unk_IntOptionEntry*>((char*)FUN_1401d3200() + 0x80c0)->FUN_140298f40();
    case 3:
        return reinterpret_cast<Unk_IntOptionEntry*>((char*)FUN_1401d3200() + 0x8118)->FUN_140298f40();
    default:
        return 0;
    }
}

// Rounds half away from zero.
// @0x140291dc0
int FUN_140291dc0(float fValue, float fBias)
{
    if (FUN_14028d470(fValue, 0) == true)
        return 0;
    if (fValue > 0.0f)
        fValue = fValue + fBias;
    else if (fValue < 0.0f)
        fValue = fValue - fBias;
    return (int)fValue;
}

int FUN_140291dc0(float fValue, float fBias);

// @0x140291d90
int FUN_140291d90(float fValue)
{
    return FUN_140291dc0(fValue, 0.5f);
}

// @0x140291e40
void FUN_140291e40(CStringW strUnused, char cUnused, void* pUnused)
{
}

// @0x140291e70
unsigned long FUN_140291e70(CString strAddr)
{
    return inet_addr(FUN_14016a5c0(strAddr, 0));
}

// @0x140291f00
CString FUN_140291f00(int nId)
{
    return CString(FUN_14028dc80(nId));
}

// @0x140291f40
CString FUN_140291f40(int nId, const fmt::ArgList& args)
{
    return CString(FUN_14028dd20(nId, args));
}

// Text before ('/' first token) or after the first '/' of the token.
// MS2-FUNCTIONAL: not yet byte-matched
// @0x140291f90
std::wstring FUN_140291f90(const std::wstring& strToken, int nWhich)
{
    size_t nPos = strToken.find(L"/", 0);
    if (nPos == std::wstring::npos)
        return std::wstring(L"");
    else if (nWhich == 0)
        return std::wstring(strToken, 0, nPos);
    else
        return std::wstring(strToken, nPos + 1, std::wstring::npos);
}

// @0x140292110
float LinearCalculator::vfunc_0(float fDelta, float fTime, float fDuration, float fDistance)
{
    return fDistance * (fDelta / fDuration);
}

// @0x140292150
float EaseOutCalculator::vfunc_0(float fDelta, float fTime, float fDuration, float fDistance)
{
    return Calc(fTime, fDuration, fDistance) - Calc(fTime - fDelta, fDuration, fDistance);
}

// MS2-FUNCTIONAL: exe imports powf/sqrtf from the CRT DLL (indirect calls); this build links them statically
// @0x1402921d0
float EaseOutCalculator::Calc(float fTime, float fDuration, float fDistance)
{
    return fDistance * sqrtf(fabsf(1.0f - powf((fTime - fDuration) / fDuration, 2.0f)));
}

// @0x140292240
float EaseInCalculator::vfunc_0(float fDelta, float fTime, float fDuration, float fDistance)
{
    return Calc(fTime, fDuration, fDistance) - Calc(fTime - fDelta, fDuration, fDistance);
}

// MS2-FUNCTIONAL: exe imports powf/sqrtf from the CRT DLL (indirect calls); this build links them statically
// @0x1402922c0
float EaseInCalculator::Calc(float fTime, float fDuration, float fDistance)
{
    return fDistance * (1.0f - sqrtf(fabsf(1.0f - powf(fTime / fDuration, 2.0f))));
}

// @0x140292820
bool FUN_140292820(const std::string& strText, const char* pszText)
{
    return strText == pszText;
}

// Wide text as a float.
// @0x1402928b0
float FUN_1402928b0(const CStringW& strText)
{
    return (float)_wtof((const wchar_t*)strText);
}

// Splits on the delimiter characters and appends each token as a float.
// @0x1402928e0
void FUN_1402928e0(const CStringW& strText, CAtlArray<float>& arrOut, const wchar_t* pszDelim)
{
    int nStart = 0;
    CStringW strToken = strText.Tokenize(pszDelim, nStart);
    while (!strToken.IsEmpty())
    {
        arrOut.Add(FUN_1402928b0(strToken));
        strToken = strText.Tokenize(pszDelim, nStart);
    }
}

// Same, as ints.
// @0x1402929a0
void FUN_1402929a0(const CStringW& strText, std::vector<int>& arrOut, const wchar_t* pszDelim)
{
    int nStart = 0;
    CStringW strToken = strText.Tokenize(pszDelim, nStart);
    while (!strToken.IsEmpty())
    {
        arrOut.push_back(FUN_140274f40(strToken));
        strToken = strText.Tokenize(pszDelim, nStart);
    }
}

// Icon name of a currency/token kind (kind 2 is the item-id icon).
// @0x1402918a0
CStringW FUN_1402918a0(int nKind, unsigned nItemId)
{
    switch (nKind)
    {
    case 0:
        return CStringW(L"");
    case 1:
        return CStringW(L"icon_0");
    case 2:
        return StringFormat(L"icon_{0}", nItemId);
    case 3:
        return CStringW(L"icon_merat");
    case 4:
        return CStringW(L"icon_30000252");
    case 5:
        return CStringW(L"icon_30000193");
    case 6:
        return CStringW(L"export_common_icon_lu");
    case 7:
        return CStringW(L"export_common_icon_habi");
    case 8:
        return CStringW(L"");
    case 9:
        return CStringW(L"icon_redmerat");
    case 10:
        return CStringW(L"icon_rbmerat");
    case 12:
        return CStringW(L"export_common_icon_reverse_coin");
    case 13:
        return CStringW(L"export_common_icon_mentor_token");
    case 14:
        return CStringW(L"export_common_icon_mentee_token");
    default:
        return CStringW(L"");
    }
}

#include <map>
#include <set>

typedef std::pair<int, Unk_XmlElement*> Unk_XmlSlot;           // document position + element
typedef std::map<CStringW, Unk_XmlSlot> Unk_XmlSlotMap;
typedef std::set<Unk_XmlSlot> Unk_XmlSlotSet;

// Collects the passing children <pszChild>, one per pszKeyAttr value, in document order.
// MS2-FUNCTIONAL: not yet byte-matched (inlined map/set code is a separate function in the exe)
// @0x14028faa0
void FUN_14028faa0(Unk_XmlElement* pParent, const char* pszChild, const char* pszKeyAttr, std::vector<Unk_XmlElement*>& arrOut)
{
    Unk_XmlSlotMap mapByKey;
    Unk_XmlSlotSet setOrdered;
    int nIndex = 0;
    for (Unk_XmlElement* pElem = FUN_140165cf0(pParent, pszChild); pElem; pElem = FUN_140168650(pElem, pszChild))
    {
        if (FUN_14028f710(pElem))
        {
            ++nIndex;
            CStringW strKey;
            FUN_140873420(pElem, pszKeyAttr, strKey);
            if (mapByKey.find(strKey) != mapByKey.end())
            {
                Unk_XmlElement* pPick = reinterpret_cast<Unk_XmlElement*>(FUN_14036e160(FUN_140166410(), reinterpret_cast<Unk_XmlElementList*>(mapByKey[strKey].second), pElem));
                if (pPick == pElem)
                {
                    setOrdered.erase(mapByKey[strKey]);
                    mapByKey[strKey] = Unk_XmlSlot(nIndex, pElem);
                    setOrdered.insert(mapByKey[strKey]);
                }
            }
            else
            {
                mapByKey[strKey] = Unk_XmlSlot(nIndex, pElem);
                setOrdered.insert(mapByKey[strKey]);
            }
        }
    }
    arrOut.reserve(setOrdered.size());
    for (Unk_XmlSlotSet::iterator it = setOrdered.begin(); it != setOrdered.end(); ++it)
        arrOut.push_back(it->second);
}

// Same, keyed by "<attr1>_<attr2>".
// MS2-FUNCTIONAL: not yet byte-matched (inlined map/set code is a separate function in the exe)
// @0x14028fd90
void FUN_14028fd90(Unk_XmlElement* pParent, const char* pszChild, const char* pszKeyAttr1, const char* pszKeyAttr2, std::vector<Unk_XmlElement*>& arrOut)
{
    Unk_XmlSlotMap mapByKey;
    Unk_XmlSlotSet setOrdered;
    int nIndex = 0;
    for (Unk_XmlElement* pElem = FUN_140165cf0(pParent, pszChild); pElem; pElem = FUN_140168650(pElem, pszChild))
    {
        if (FUN_14028f710(pElem))
        {
            ++nIndex;
            CStringW strKey1;
            CStringW strKey2;
            FUN_140873420(pElem, pszKeyAttr1, strKey1);
            FUN_140873420(pElem, pszKeyAttr2, strKey2);
#ifdef __clang__
            CStringW strKey(strKey1); // clang would import MFC CopyChars for operator+
            strKey.Append(L"_");
            strKey.Append(strKey2);
#else
            CStringW strKey = (const wchar_t*)((const wchar_t*)strKey1 + CStringW(L"_")) + strKey2;
#endif
            if (mapByKey.find(strKey) != mapByKey.end())
            {
                Unk_XmlElement* pPick = reinterpret_cast<Unk_XmlElement*>(FUN_14036e160(FUN_140166410(), reinterpret_cast<Unk_XmlElementList*>(mapByKey[strKey].second), pElem));
                if (pPick == pElem)
                {
                    setOrdered.erase(mapByKey[strKey]);
                    mapByKey[strKey] = Unk_XmlSlot(nIndex, pElem);
                    setOrdered.insert(mapByKey[strKey]);
                }
            }
            else
            {
                mapByKey[strKey] = Unk_XmlSlot(nIndex, pElem);
                setOrdered.insert(mapByKey[strKey]);
            }
        }
    }
    arrOut.reserve(setOrdered.size());
    for (Unk_XmlSlotSet::iterator it = setOrdered.begin(); it != setOrdered.end(); ++it)
        arrOut.push_back(it->second);
}

// Same, keyed by an attribute of the sub-element <pszSub> of each child.
// MS2-FUNCTIONAL: not yet byte-matched (inlined map/set code is a separate function in the exe)
// @0x140290150
void FUN_140290150(Unk_XmlElement* pParent, const char* pszChild, const char* pszSub, const char* pszKeyAttr, std::vector<Unk_XmlElement*>& arrOut)
{
    Unk_XmlSlotMap mapByKey;
    Unk_XmlSlotSet setOrdered;
    int nIndex = 0;
    for (Unk_XmlElement* pElem = FUN_140165cf0(pParent, pszChild); pElem; pElem = FUN_140168650(pElem, pszChild))
    {
        if (!FUN_14028f710(pElem))
            continue;
        Unk_XmlElement* pSub = FUN_140165cf0(pElem, pszSub);
        if (!pSub)
            continue;
        ++nIndex;
        CStringW strKey;
        FUN_140873420(pSub, pszKeyAttr, strKey);
        if (mapByKey.find(strKey) != mapByKey.end())
        {
            Unk_XmlElement* pPick = reinterpret_cast<Unk_XmlElement*>(FUN_14036e160(FUN_140166410(), reinterpret_cast<Unk_XmlElementList*>(mapByKey[strKey].second), pElem));
            if (pPick == pElem)
            {
                setOrdered.erase(mapByKey[strKey]);
                mapByKey[strKey] = Unk_XmlSlot(nIndex, pElem);
                setOrdered.insert(mapByKey[strKey]);
            }
        }
        else
        {
            mapByKey[strKey] = Unk_XmlSlot(nIndex, pElem);
            setOrdered.insert(mapByKey[strKey]);
        }
    }
    arrOut.reserve(setOrdered.size());
    for (Unk_XmlSlotSet::iterator it = setOrdered.begin(); it != setOrdered.end(); ++it)
        arrOut.push_back(it->second);
}

// @0x140298f40
int& Unk_IntOptionEntry::FUN_140298f40()
{
    if (!m_bSet)
        FUN_1402b7560(this, "constants is not set");
    return m_nValue;
}

// @0x140298f80
CString& Unk_StringOptionEntry::FUN_140298f80()
{
    if (!m_bSet)
        FUN_1402b7560(this, "constants is not set");
    return m_strValue;
}

// @0x140298fd0
long FUN_140298fd0(long* plValue)
{
    return InterlockedIncrement(plValue);
}

// MS2-FUNCTIONAL: not yet byte-matched (CRT import / inline layout)
// @0x140299100
bool FUN_140299100(const CAtlArray<CString>& arr)
{
    return arr.GetCount() == 0;
}

// MS2-FUNCTIONAL: not yet byte-matched (CRT import / inline layout)
// @0x14029dba0
float FUN_14029dba0(float fAngle)
{
    return sinf(fAngle);
}

// MS2-FUNCTIONAL: not yet byte-matched (CRT import / inline layout)
// @0x14029cc60
float FUN_14029cc60(float fAngle)
{
    return cosf(fAngle);
}

// MS2-FUNCTIONAL: not yet byte-matched (CRT import / inline layout)
// @0x14029d430
float FUN_14029d430(float fX, float fY)
{
    return fmodf(fX, fY);
}

// MS2-FUNCTIONAL: not yet byte-matched (CRT import / inline layout)
// @0x14029dd40
float FUN_14029dd40(float fValue)
{
    return (float)fabs((double)fValue);
}

// @0x14029d220
float FUN_14029d220(float fValue)
{
    return FUN_14029dd40(fValue);
}

// @0x14029dd60
int FUN_14029dd60(const char* pszText, const char* pszFormat, ...)
{
    va_list args;
    va_start(args, pszFormat);
    int nCount = vsscanf(pszText, pszFormat, args);
    va_end(args);
    return nCount;
}

// BSTR plus a narrow conversion buffer.
struct Unk_BstrHolder
{
    BSTR m_bstr;
    char* m_pszNarrow;
    void FUN_14029b610();                                       // 0x14029b610
    unsigned FUN_1402992b0();                                   // 0x1402992b0
};

struct Unk_BstrHolderRef
{
    Unk_BstrHolder* m_pHolder;
    unsigned FUN_14029d4b0();                                   // 0x14029d4b0
};

// @0x14029b610
void Unk_BstrHolder::FUN_14029b610()
{
    if (m_bstr)
    {
        SysFreeString(m_bstr);
        m_bstr = NULL;
    }
    if (m_pszNarrow)
    {
        delete[] m_pszNarrow;
        m_pszNarrow = NULL;
    }
}

// @0x1402992b0
unsigned Unk_BstrHolder::FUN_1402992b0()
{
    return m_bstr ? SysStringLen(m_bstr) : 0;
}

// @0x14029d4b0
unsigned Unk_BstrHolderRef::FUN_14029d4b0()
{
    return m_pHolder ? m_pHolder->FUN_1402992b0() : 0;
}

// Reference-counted object (count at +0x10).
struct Unk_BindHost
{
    void* m_unk00;
    void* m_unk08;
    volatile long m_nRefs;
    long FUN_140298720();                                       // 0x140298720
};

struct Unk_BindHostPtr
{
    Unk_BindHost* m_pHost;
    void FUN_140299e30();                                       // 0x140299e30
};

extern void FUN_140297a00(void* p);

// Destroy-and-free helper of the bind host (flag bit 0 = free the block).
// @0x1402986c0
void* FUN_1402986c0(void* p, unsigned nFlags)
{
    FUN_140297a00(p);
    if (nFlags & 1)
        operator delete(p, (size_t)0x18);
    return p;
}

// @0x140298720
long Unk_BindHost::FUN_140298720()
{
    InterlockedIncrement(&m_nRefs);
    return m_nRefs;
}

// @0x140299e30
void Unk_BindHostPtr::FUN_140299e30()
{
    if (m_pHost)
        m_pHost->FUN_140298720();
}

// BSTR-concatenation helper family (ATL CComBSTR-like holders, 0x18-byte heap blocks: BSTR, spare, refcount).
struct Unk_BstrBlock
{
    void* m_pData;
    void* m_unk08;
    int m_nRefs;
};

extern void FUN_14016ad80(void* pThis, void* pArg);
void* FUN_140297a40(size_t nBytes);
extern void FUN_140297790(void* p);
extern void FUN_1402978c0(void* p);
extern void** FUN_140298fc0(void* pHolder);
extern void FUN_14028b5b0(void* pDst, unsigned long long nDstBytes, const void* pSrc, unsigned long long nCount);
extern void* FUN_140183290(void* pOut);
extern unsigned long long* FUN_14029dcd0();
extern void FUN_14029b680(void** pp);
extern void FUN_140297a20(void** pp);
extern void* FUN_140297620(void** pp, void* pArg);
extern void* FUN_140298560(void** pp, void* pArg);

// @0x1402969f0
void** FUN_1402969f0(void** p, void* pVtbl, void* pArg)
{
    *p = pVtbl;
    FUN_14016ad80(p, pArg);
    return p;
}

// @0x140296c30
void** FUN_140296c30(void** p, void* pVtbl, void* pArg)
{
    *p = pVtbl;
    FUN_14016ad80(p, pArg);
    return p;
}

// @0x140296c90
void** FUN_140296c90(void** p, void* pVtbl, void* pArg)
{
    *p = pVtbl;
    FUN_14016ad80(p, pArg);
    return p;
}

// @0x140297a40
void* FUN_140297a40(size_t nBytes)
{
    return operator new(nBytes);
}

// @0x1402973e0
Unk_BstrBlock* FUN_1402973e0(Unk_BstrBlock* p, void* pArg)
{
    p->m_unk08 = NULL;
    p->m_nRefs = 1;
    p->m_pData = SysAllocString((BSTR)pArg);   // 0x14274c0f0 is an import thunk
    return p;
}

// @0x140297430
Unk_BstrBlock* FUN_140297430(Unk_BstrBlock* p, const wchar_t* pszText)
{
    p->m_unk08 = NULL;
    p->m_nRefs = 1;
    p->m_pData = SysAllocString(pszText);
    if (p->m_pData == NULL && pszText != NULL)
        AtlThrow(E_OUTOFMEMORY);
    return p;
}

// @0x140297250
Unk_BstrBlock* FUN_140297250(Unk_BstrBlock* p, Unk_BstrHolderRef* pA, Unk_BstrHolderRef* pB)
{
    p->m_unk08 = NULL;
    p->m_nRefs = 1;
    unsigned nLenA = pA->FUN_14029d4b0();
    unsigned nLenB = pB->FUN_14029d4b0();
    int nTotal;
    unsigned nBytes;
    if (FUN_14028b840(nLenA, nLenB, &nTotal) < 0 || FUN_14028b890(nTotal, 2, &nBytes) < 0)
        AtlThrow(E_OUTOFMEMORY);
    BSTR bstr = SysAllocStringLen(NULL, nLenA + nLenB);
    p->m_pData = bstr;
    if (bstr == NULL)
    {
        if (nLenA + nLenB != 0)
            AtlThrow(E_OUTOFMEMORY);
    }
    else
    {
        const void* pSrcA = pA->m_pHolder ? *FUN_140298fc0(pA->m_pHolder) : NULL;
        if (pSrcA)
            FUN_14028b5b0(bstr, (unsigned long long)(nLenA + 1 + nLenB) << 1, pSrcA, (unsigned long long)(nLenA + 1) << 1);
        const void* pSrcB = pB->m_pHolder ? *FUN_140298fc0(pB->m_pHolder) : NULL;
        if (pSrcB)
            FUN_14028b5b0(bstr + nLenA, (unsigned long long)(nLenB + 1) << 1, pSrcB, (unsigned long long)(nLenB + 1) << 1);
    }
    return p;
}

// @0x140297550
Unk_BindHostPtr* FUN_140297550(Unk_BindHostPtr* pThis, const Unk_BindHostPtr* pOther)
{
    pThis->m_pHost = pOther->m_pHost;
    pThis->FUN_140299e30();
    return pThis;
}

// @0x140297590
Unk_BstrBlock** FUN_140297590(Unk_BstrBlock** pp, void* pArg)
{
    void* pMem = FUN_140297a40(0x18);
    *pp = pMem ? FUN_1402973e0((Unk_BstrBlock*)pMem, pArg) : NULL;
    if (*pp == NULL)
        AtlThrow(E_OUTOFMEMORY);
    return pp;
}

// @0x140297620
void* FUN_140297620(void** pp, void* pArg)
{
    void* pMem = FUN_140297a40(0x18);
    *pp = pMem ? FUN_140297430((Unk_BstrBlock*)pMem, (const wchar_t*)pArg) : NULL;
    if (*pp == NULL)
        AtlThrow(E_OUTOFMEMORY);
    return pp;
}

// @0x140298560
void* FUN_140298560(void** pp, void* pArg)
{
    void* pMem = FUN_140297a40(0x18);
    void* pNew = pMem ? FUN_140297250((Unk_BstrBlock*)pMem, (Unk_BstrHolderRef*)pp, (Unk_BstrHolderRef*)pArg) : NULL;
    if (pNew == NULL)
        AtlThrow(E_OUTOFMEMORY);
    FUN_14029b680(pp);
    *pp = pNew;
    return pp;
}

// @0x1402982e0
Unk_BindHostPtr* FUN_1402982e0(Unk_BindHostPtr* pOut, void* pA, void* pB, void* pC)
{
    void* pTmp[1];
    FUN_140297620(pTmp, pA);
    FUN_140298560(pTmp, pB);
    FUN_140297550(pOut, (Unk_BindHostPtr*)pTmp);
    FUN_140297a20(pTmp);
    return pOut;
}

// @0x1402978a0
void FUN_1402978a0(void* p)
{
    FUN_140297790(p);
}

// @0x140297a20
void FUN_140297a20(void** pp)
{
    FUN_14029b680(pp);
}

// @0x140297d20
void* FUN_140297d20(Unk_BstrHolderRef* p)
{
    return p->m_pHolder ? *FUN_140298fc0(p->m_pHolder) : NULL;
}

// @0x1402979b0
void FUN_1402979b0(void* p)
{
    ((CLockCriticalSection*)((char*)p + 0x168))->~CLockCriticalSection();
    for (int i = 14; i >= 0; --i)
        FUN_1402978c0((char*)p + i * 0x18);
}

// @0x1402999c0
unsigned long FUN_1402999c0(Unk_BindHost* p)
{
    long nRefs = InterlockedDecrement(&p->m_nRefs);
    if (nRefs == 0 && p)
        FUN_1402986c0(p, 1);
    return nRefs;
}

// @0x14029b680
void FUN_14029b680(void** pp)
{
    if (*pp)
    {
        FUN_1402999c0((Unk_BindHost*)*pp);
        *pp = NULL;
    }
}

// @0x140298ea0
void* FUN_140298ea0(void* pOut, CStringW* pStr, void* pUnused, void* pArgs)
{
    char buf[24];
    CStringW strOut = FUN_14028dfa0(*pStr, *(const fmt::ArgList*)FUN_140183290(buf));
    (void)pOut; (void)pUnused; (void)pArgs; (void)strOut;
    return pOut;
}

// @0x14029dce0
void FUN_14029dce0(const char* pszBuf, const char* pszFormat, _locale_t pLocale, va_list args)
{
    __stdio_common_vsscanf(*FUN_14029dcd0() | 1, pszBuf, (size_t)-1, pszFormat, pLocale, args);
}

MS2_REPLACE(0x14028B820, FUN_14028b820, 25, 0x5B243679);
MS2_REPLACE(0x14028B840, FUN_14028b840, 60, 0x6C3E9287);
MS2_REPLACE(0x14028B890, FUN_14028b890, 68, 0x51B88B44);
MS2_REPLACE_METHOD(0x140298F40, Unk_IntOptionEntry, FUN_140298f40, 53, 0xC651AF56);
MS2_REPLACE_METHOD(0x140298F80, Unk_StringOptionEntry, FUN_140298f80, 53, 0x8459A15E);
MS2_REPLACE(0x140298FD0, FUN_140298fd0, 24, 0xE9DE9F2E);
MS2_REPLACE_METHOD(0x1402992B0, Unk_BstrHolder, FUN_1402992b0, 57, 0x39A7E074);
MS2_REPLACE_METHOD(0x14029B610, Unk_BstrHolder, FUN_14029b610, 100, 0x78F0708C);
MS2_REPLACE_METHOD(0x14029D4B0, Unk_BstrHolderRef, FUN_14029d4b0, 56, 0xD03F266E);
MS2_REPLACE_METHOD(0x140298720, Unk_BindHost, FUN_140298720, 26, 0xC507010C);
MS2_REPLACE_METHOD(0x140299E30, Unk_BindHostPtr, FUN_140299e30, 38, 0x01C0B517);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9a480-0x142c9a4a0 .text$yd
