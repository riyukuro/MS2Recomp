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
// MS2-PIN: ??HATL@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@0@PEBDAEBV10@@Z 0x140298360 ; unique
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
#include <comdef.h>
#pragma comment(lib, "comsuppw.lib")   // _com_issue_error (0x14274be80): the _bstr_t stand-ins below throw _com_error
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/mstime.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/commonstringtable.h"

int FUN_14028c3e0(const CString& strText, CAtlArray<CString>& arrOut, const char* pszDelim, int nMax);

struct Unk_CommonVec3 { Unk_CommonVec3() {} float x, y, z; };

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
__int64 GetServerTime();                                        // current server time
CString FUN_140298360(const char* pszPrefix, const CString& str);

class Unk_StringMgr : public CommonString                                             // localized string table
{
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
CStringW GetStringCommonByKey(const CStringW& strKey)
{
    if (FUN_14025e7d0() == 0)
        return L"";
    return FUN_14025e7d0()->GetWideByKey(strKey);
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
// @0x14028bd10
CString FUN_14028bd10(int nAddr)
{
    sockaddr_in kAddr;
    kAddr.sin_addr.s_addr = nAddr;
    CString strAddr = FUN_140188f50(inet_ntoa(kAddr.sin_addr), 0);
    return strAddr;
}

// Resolves a host name and picks one of its addresses at random (empty when it does not resolve).
// @0x14028bdb0
CString FUN_14028bdb0(const CString& strHost)
{
    hostent* pHost = gethostbyname(FUN_14016a5c0(strHost, 0));
    if (pHost == 0)
        return "";
    CAtlArray<CString> arrAddr;
    for (int i = 0; pHost->h_addr_list[i] != 0; i++)
    {
        CString strAddr = FUN_140188f50(inet_ntoa(*(in_addr*)pHost->h_addr_list[i]), 0);
        if (!strAddr.IsEmpty())
            arrAddr.Add(strAddr);
    }
    if (FUN_140299100(arrAddr))
        return "";
    int nIndex = (int)(rand() % arrAddr.GetCount());
    return arrAddr.GetAt(nIndex);
}

// ---- string splitting and parsing helpers ----

// "r,g,b" -> 0xffRRGGBB.
// @0x14028c0d0
unsigned FUN_14028c0d0(const char* pszText)
{
    CString strText(pszText);
    CAtlArray<CString> arrParts;
    if (FUN_14028c3e0(strText, arrParts, ",", 3) == 0)
        return 0;
    unsigned uRed = (atoi(arrParts[0]) & 0xff) << 16 | 0xff000000;
    unsigned uRedGreen = uRed | (atoi(arrParts[1]) & 0xff) << 8;
    unsigned uColor = uRedGreen | atoi(arrParts[2]) & 0xff;
    return uColor;
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
        if (arrOut.GetCount() > (size_t)(nMax - 1))
        {
            arrOut.Add(strText.Mid(nPos));
            return 1;
        }
        strToken = strText.Tokenize(pszDelim, nPos);
    }
    return 0;
}

// Splits on pszSep, returns whether exactly nExpected parts came out.
// @0x14028c570
int FUN_14028c570(const CString& strText, CAtlArray<CString>& arrOut, const char* pszSep, int nExpected)
{
    CString strPart;
    int nPos = 0;
    int nFound = 0;
    while (true)
    {
        nFound = strText.Find(pszSep, nPos);
        if (nFound == -1)
        {
            strPart = strText.Mid(nPos);
            arrOut.Add(strPart);
            break;
        }
        strPart = strText.Mid(nPos, nFound - nPos);
        arrOut.Add(strPart);
        nPos = nFound + 1;
    }
    if (arrOut.GetCount() != nExpected)
        return 0;
    return 1;
}

// Splits on pszSep.
// @0x14028c700
void FUN_14028c700(const CString& strText, CAtlArray<CString>& arrOut, const char* pszSep)
{
    CString strPart;
    int nPos = 0;
    int nFound = 0;
    while (true)
    {
        nFound = strText.Find(pszSep, nPos);
        if (nFound == -1)
        {
            strPart = strText.Mid(nPos);
            arrOut.Add(strPart);
            break;
        }
        strPart = strText.Mid(nPos, nFound - nPos);
        arrOut.Add(strPart);
        nPos = nFound + 1;
    }
}

// Splits on pszSep into at most nMax parts (the last one keeps the remaining text).
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
        int nFound = 0;
        for (int i = 0; i < nMax; ++i)
        {
            nFound = strText.Find(pszSep, nPos);
            if (nFound == -1)
            {
                strPart = strText.Mid(nPos);
                arrOut.Add(strPart);
                break;
            }
            if (i >= nMax - 1)
            {
                arrOut.Add(strText.Mid(nPos));
                return;
            }
            else
            {
                strPart = strText.Mid(nPos, nFound - nPos);   // just this field
                arrOut.Add(strPart);
                nPos = nFound + 1;
            }
        }
    }
}

// Collects each strOpen...strClose span (markers included).
// @0x14028ca50
void FUN_14028ca50(const CString& strText, CAtlArray<CString>& arrOut, const CString& strOpen, const CString& strClose)
{
    if (strText.IsEmpty())
        return;
    int nPos = 0;
    int nOpen = 0;
    int nClose = 0;
    while (true)
    {
        nOpen = strText.Find(strOpen, nPos);
        if (nOpen == -1)
            return;
        nClose = strText.Find(strClose, nPos);
        if (nClose == -1)
            return;
        CString strInner = strText.Mid(nOpen, nClose - nOpen + 1);
        if (strInner.GetLength() > 0)
            arrOut.Add(strInner);
        nPos = nClose + 1;
    }
}

// Splits on pszSep, returns whether exactly nExpected parts came out.
// @0x14028cb70
int FUN_14028cb70(const CStringW& strText, CAtlArray<CStringW>& arrOut, const wchar_t* pszSep, int nExpected)
{
    CStringW strPart;
    int nPos = 0;
    int nFound = 0;
    while (true)
    {
        nFound = strText.Find(pszSep, nPos);
        if (nFound == -1)
        {
            strPart = strText.Mid(nPos);
            arrOut.Add(strPart);
            break;
        }
        strPart = strText.Mid(nPos, nFound - nPos);
        arrOut.Add(strPart);
        nPos = nFound + 1;
    }
    if (arrOut.GetCount() != nExpected)
        return 0;
    return 1;
}

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
        int nFound = 0;
        for (int i = 0; i < nMax; ++i)
        {
            nFound = strText.Find(pszSep, nPos);
            if (nFound == -1)
            {
                strPart = strText.Mid(nPos);
                arrOut.Add(strPart);
                break;
            }
            if (i >= nMax - 1)
            {
                arrOut.Add(strText.Mid(nPos));
                return;
            }
            else
            {
                strPart = strText.Mid(nPos, nFound - nPos);   // just this field
                arrOut.Add(strPart);
                nPos = nFound + 1;
            }
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
    int nOpen = 0;
    int nClose = 0;
    while (true)
    {
        nOpen = strText.Find(strOpen, nPos);
        if (nOpen == -1)
            break;
        nClose = strText.Find(strClose, nPos);
        if (nClose == -1)
            break;
        CStringW strInner = strText.Mid(nOpen, nClose - nOpen + 1);
        if (0 < strInner.GetLength())
            arrOut.Add(strInner);
        nPos = nClose + 1;
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
    __int64 nTime = GetServerTime();
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

// @0x14028d4b0
bool FUN_14028d4b0(const Unk_CommonVec3* pA, const Unk_CommonVec3* pB)
{
    if (FUN_14028d470(pA->x, pB->x) && FUN_14028d470(pA->y, pB->y) && FUN_14028d470(pA->z, pB->z))
        return true;
    return false;
}

// @0x14028d530
bool FUN_14028d530(const Unk_CommonVec3* pA, const Unk_CommonVec3* pB)
{
    if (FUN_14028d470(pA->x, pB->x) && FUN_14028d470(pA->y, pB->y) && FUN_14028d470(pA->z, pB->z))
        return true;
    return false;
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
// @0x14028d6d0
void FUN_14028d6d0(const unsigned char* pData, int nLen, CString& strOut, int nCount)
{
    if (nCount == 0)
        nCount = nLen;
    for (int i = 0; i < nLen && i < nCount; ++i)
    {
        unsigned char nByte = pData[i];
        strOut.AppendFormat("%02X", nByte);
    }
}

// @0x14028d760
bool FUN_14028d760(bool b)
{
    if (b)
        return true;
    return false;
}

// The exe takes an unsigned byte (movzx); callers declare it with char/bool, which binds by name and passes the same byte.
// @0x14028d780
bool FUN_14028d780(unsigned char c)
{
    if (c)
        return true;
    return false;
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
Unk_TimeFormat::Unk_TimeFormat() : m_time(GetServerTime())
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
    return FUN_14025e7d0()->GetNarrow(nId);
}

// @0x14028dcd0
CString FUN_14028dcd0(const CString& strKey)
{
    return FUN_14025e7d0()->GetNarrowByKey(strKey);
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
CStringW GetStringCommon(int nId)
{
    if (FUN_14025e7d0() == 0)
        return L"";
    return FUN_14025e7d0()->GetWide(nId);
}

// @0x14028dee0
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args)
{
    CStringW strText = GetStringCommon(nId);
    if (strText.IsEmpty())
        return L"";
    return StringFormat(strText, args);
}

// @0x14028dfa0
CStringW FUN_14028dfa0(const CStringW& strKey, const fmt::ArgList& args)
{
    CStringW strText = GetStringCommonByKey(strKey);
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
    FUN_14029dd60(CString(strText).GetString(), (LPCSTR)CString(strFormat), &nYear, &nMonth, &nDay, &nHour, &nMinute, &nSecond);
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
// @0x14028f710
bool FUN_14028f710(Unk_XmlElement* pElem)
{
    CString strLocale = FUN_14015f710(pElem, "locale", CString(""));
    bool bMatch = !strLocale.IsEmpty() && strLocale != static_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d8e0();
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
        bool bLocale = !strLocale.IsEmpty() && strLocale != static_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d8e0();
        if (bLocale)
            continue;
        if (!FUN_14036d4b0(FUN_140166410(), strFeature))
            continue;
        pResult = FUN_14036e160(FUN_140166410(), pResult, pElem);
    }
    return pResult;
}

// Shows a modal error box: caption + Format(fmt, nCode) + the suffix text.
// @0x14028bfb0
void FUN_14028bfb0(CString strCaption, CString strFormat, unsigned int nCode, CString strSuffix)
{
    CString strText;
    strText.Format((const char*)strFormat, nCode);
    strText += FUN_140298360(" ", strSuffix);
    MessageBoxA(0, strText, strCaption, MB_ICONERROR);
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
        __time64_t tNow = GetServerTime();
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
    if (arrParts.GetCount() != 3)
        return vResult;
    vResult.x = arrParts[0];
    vResult.y = arrParts[1];
    vResult.z = arrParts[2];
    return vResult;
}

// MS2-FUNCTIONAL: not yet byte-matched (std::string glue pairing / frame layout)
// @0x14028f190
Unk_CommonVec3 FUN_14028f190(CStringW strText)
{
    Unk_CommonVec3 vResult = g_vCommonZero;
    CAtlArray<float> arrParts;
    FUN_1402928e0(strText, arrParts, L",");
    if (arrParts.GetCount() != 3)
        return vResult;
    vResult.x = arrParts[0];
    vResult.y = arrParts[1];
    vResult.z = arrParts[2];
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
    ~CItemTabNameTable();                                       // 0x1402979b0
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
// @0x1402906b0
void CItemTabNameTable::Init()
{
    Unk_CriticalSectionLock guard(m_lock, 1);
    m_arrNames[0].push_back("game");
    m_arrNames[1].push_back("skin");
    m_arrNames[2].push_back("summon");
    m_arrNames[3].push_back("material");
    m_arrNames[4].push_back("life");
    m_arrNames[5].push_back("quest");
    m_arrNames[6].push_back("gem");
    m_arrNames[7].push_back("misc");
    m_arrNames[8].push_back("mastery");
    m_arrNames[9].push_back("pet");
    m_arrNames[13].push_back("lapenshard");
    m_arrNames[10].push_back("activeskill");
    m_arrNames[11].push_back("coin");
    m_arrNames[12].push_back("badge");
    m_arrNames[14].push_back("piece");
    for (unsigned int nTab = 0; nTab < 15; ++nTab)
    {
        for (unsigned int nSub = 0; nSub < m_arrNames[nTab].size(); ++nSub)
        {
            (void)((!!(m_arrNames[nTab][nSub].size())) || (_wassert(L"vTabNames[tabIndex][subIndex].size()", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.cpp", 0x811), 0));
        }
    }
    m_arrNames[0].push_back("equip");
    m_arrNames[0].push_back("\xc0\xe5\xba\xf1");
    m_arrNames[1].push_back("\xbd\xba\xc5\xb2");
    m_arrNames[2].push_back("\xbc\xd2\xc8\xaf");
    m_arrNames[3].push_back("\xc0\xe7\xb7\xe1");
    m_arrNames[4].push_back("\xbb\xfd\xc8\xb0");
    m_arrNames[5].push_back("\xc4\xf9\xbd\xba\xc6\xae");
    m_arrNames[6].push_back("gemstone");
    m_arrNames[6].push_back("\xc1\xaa\xbd\xba\xc5\xe6");
    m_arrNames[7].push_back("etc");
    m_arrNames[7].push_back("\xb1\xe2\xc5\xb8");
    m_arrNames[8].push_back("\xbb\xfd\xc8\xb0\xb1\xe2\xbc\xfa");
    m_arrNames[9].push_back("\xc6\xea");
    m_arrNames[13].push_back("\xb6\xf3\xc6\xe6\xbb\xfe\xb5\xe5");
    m_arrNames[10].push_back("\xbc\xd2\xba\xf1");
    m_arrNames[11].push_back("\xc8\xad\xc6\xf3");
    m_arrNames[12].push_back("\xb9\xe8\xc1\xf6");
    m_arrNames[14].push_back("\xc1\xb6\xb0\xa2");
}

// Tab index that knows the name, or -1.
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
    (void)((!!(0)) || (_wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.cpp", 0x841), 0));
    return -1;
}

// @0x140291150
unsigned char FUN_140291150(int nTab)
{
    int bValid;
    if (nTab > -1 && nTab < 15)
        bValid = 1;
    else
        bValid = 0;
    return bValid;
}

// First name of the tab.
// @0x1402905e0
const std::string& CItemTabNameTable::GetTabName(int nTab)
{
    static std::string s_strEmpty;
    if (!FUN_140291150(nTab))
    {
        (void)((!!(0)) || (_wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.cpp", 0x82f), 0));
        return s_strEmpty;
    }
    return m_arrNames[nTab][0];
}

// @0x140291190
int FUN_140291190(std::string strName)
{
    CItemTabNameTable& table = g_ItemTabNames;
    return table.FindIndex(strName);
}

// @0x140291200
int FUN_140291200(CString strName)
{
    const char* pszName = strName;
    std::string strText(pszName);
    CItemTabNameTable& table = g_ItemTabNames;
    return table.FindIndex(strText);
}

// @0x1402912d0
int FUN_1402912d0(CStringW strName)
{
    return FUN_140291200(CString((const wchar_t*)strName));
}

// @0x140291340
bool FUN_140291340(int nTab, std::string& strOut)
{
    CItemTabNameTable& table = g_ItemTabNames;
    strOut = table.GetTabName(nTab);
    return strOut.size() != 0;
}

bool FUN_140292820(const std::string& strLeft, const char* pszRight);   // string equals
__int64 NextWeekdayStart(int nKind, __int64 nTime);
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
// @0x1402913b0
int FUN_1402913b0(const CString& strTab, CString& strTabOut)
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
    (void)((!!(!strTabOut.IsEmpty())) || (_wassert(L"!outTabStr.IsEmpty()", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.cpp", 0x883), 0));
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
// The times are 16-byte CMsTime (0x1406c47a0/47d0 end in Init 0x1406c5270, which also stores the zone flag at +8);
// 8-byte ATL::CTime locals had that byte written past them (rt1 stackovf.py).
// MS2-FUNCTIONAL: not yet byte-matched
// @0x1402916a0
__int64 FUN_1402916a0(__int64 nTime, int nMode)
{
    __int64 nResult = 0;
    CMsTime timeNow(nTime);
    if (nMode == 1)
    {
        CMsTime timeDay(timeNow.GetYear(), timeNow.GetMonth(), timeNow.GetDay(), 0, 0, 0);
        timeDay += ATL::CTimeSpan(1, 0, 0, 0);
        nResult = timeDay.Get();
    }
    else if (nMode == 2)
    {
        CMsTime timeOther(NextWeekdayStart(6, nTime));
        nResult = timeOther.Get();
    }
    else if (nMode == 3)
    {
        int nYear = timeNow.GetYear();
        int nMonth = timeNow.GetMonth() + 1;
        if (nMonth > 12)
        {
            nMonth = 1;
            nYear = nYear + 1;
        }
        CMsTime timeMonth(nYear, nMonth, 1, 0, 0, 0);
        nResult = timeMonth.Get();
    }
    else
    {
        CMsTime timeFar(2500, 1, 1, 0, 0, 0);
        nResult = timeFar.Get();
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

// @0x140291d10
float FUN_140291d10(int nKind)
{
    switch (nKind)
    {
    case 1:
        return reinterpret_cast<float&>(reinterpret_cast<Unk_IntOptionEntry*>((char*)FUN_1401d3200() + 0x8068)->FUN_140298f40());
    case 2:
        return reinterpret_cast<float&>(reinterpret_cast<Unk_IntOptionEntry*>((char*)FUN_1401d3200() + 0x80c0)->FUN_140298f40());
    case 3:
        return reinterpret_cast<float&>(reinterpret_cast<Unk_IntOptionEntry*>((char*)FUN_1401d3200() + 0x8118)->FUN_140298f40());
    default:
        return 0.0f;
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
// @0x140291f90
std::wstring FUN_140291f90(const std::wstring& strToken, int nWhich)
{
    size_t nPos = strToken.find(L"/", 0);
    if (nPos == std::wstring::npos)
        return L"";
    if (nWhich == 0)
        return strToken.substr(0, nPos).c_str();
    else
        return strToken.substr(nPos + 1, std::wstring::npos).c_str();
}

// @0x140292110
float LinearCalculator::vfunc_0(float fDelta, float fTime, float fDuration, float fDistance)
{
    return fDistance * (fDelta / fDuration);
}

// the exe calls these CRT math functions through its imports
extern "C" float (__cdecl* __imp_sinf)(float);
extern "C" float (__cdecl* __imp_cosf)(float);
extern "C" float (__cdecl* __imp_fmodf)(float, float);
extern "C" float (__cdecl* __imp_powf)(float, float);
extern "C" float (__cdecl* __imp_sqrtf)(float);

// @0x140292150
float EaseOutCalculator::vfunc_0(float fDelta, float fTime, float fDuration, float fDistance)
{
    return Calc(fTime, fDuration, fDistance) - Calc(fTime - fDelta, fDuration, fDistance);
}

// @0x1402921d0
float EaseOutCalculator::Calc(float fTime, float fDuration, float fDistance)
{
    return fDistance * __imp_sqrtf(FUN_14029d220(1.0f - __imp_powf((fTime - fDuration) / fDuration, 2.0f)));
}

// @0x140292240
float EaseInCalculator::vfunc_0(float fDelta, float fTime, float fDuration, float fDistance)
{
    return Calc(fTime, fDuration, fDistance) - Calc(fTime - fDelta, fDuration, fDistance);
}

// @0x1402922c0
float EaseInCalculator::Calc(float fTime, float fDuration, float fDistance)
{
    return fDistance * (1.0f - __imp_sqrtf(FUN_14029d220(1.0f - __imp_powf(fTime / fDuration, 2.0f))));
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
    case 12:
        return CStringW(L"export_common_icon_reverse_coin");
    case 13:
        return CStringW(L"export_common_icon_mentor_token");
    case 14:
        return CStringW(L"export_common_icon_mentee_token");
    case 9:
        return CStringW(L"icon_redmerat");
    case 10:
        return CStringW(L"icon_rbmerat");
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

// CAtlArray's data pointer and count, read directly as the exe does
struct Unk_CuArrayView { void* m_pData; size_t m_nSize; };

// @0x140299100
bool FUN_140299100(const CAtlArray<CString>& arr)
{
    return reinterpret_cast<const Unk_CuArrayView&>(arr).m_nSize == 0;
}

// @0x14029dba0
float FUN_14029dba0(float fAngle)
{
    return __imp_sinf(fAngle);
}

// @0x14029cc60
float FUN_14029cc60(float fAngle)
{
    return __imp_cosf(fAngle);
}

// @0x14029d430
float FUN_14029d430(float fX, float fY)
{
    return __imp_fmodf(fX, fY);
}

// the exe calls fabs out of line through the ucrt import (not the /Oi intrinsic)
#pragma function(fabs)
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
    Unk_BindHostPtr(const wchar_t* pszText);                    // 0x140297620
    Unk_BindHostPtr(const Unk_BindHostPtr& other);              // 0x140297550
    ~Unk_BindHostPtr() noexcept(false);                         // 0x140297a20
    Unk_BindHostPtr& operator+=(const Unk_BindHostPtr& other);  // 0x140298560
    void FUN_140299e30();                                       // 0x140299e30
};

// Releases a bind host's BSTR holder (the holder sits at the block's start).
// @0x140297a00
void FUN_140297a00(void* p)
{
    static_cast<Unk_BstrHolder*>(p)->FUN_14029b610();
}

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
    Unk_BstrBlock(void* pArg);                                  // 0x1402973e0
    Unk_BstrBlock(const wchar_t* pszText);                      // 0x140297430
    Unk_BstrBlock(Unk_BstrHolderRef* pA, Unk_BstrHolderRef* pB);    // 0x140297250
    static void* operator new(size_t nBytes);                   // 0x140297a40
};

extern void FUN_14016ad80(void* pThis, void* pArg);
extern void FUN_140297790(void* p);
extern void** FUN_140298fc0(void* pHolder);
extern void* FUN_140183290(void* pOut);
extern unsigned long long* FUN_14029dcd0();
extern void FUN_14029b680(void** pp);
void* FUN_140297d20(Unk_BstrHolderRef* p);

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
void* Unk_BstrBlock::operator new(size_t nBytes)
{
    return ::operator new(nBytes);
}

// @0x1402973e0
Unk_BstrBlock::Unk_BstrBlock(void* pArg)
{
    m_unk08 = NULL;
    m_nRefs = 1;
    m_pData = SysAllocString((BSTR)pArg);   // 0x14274c0f0 is an import thunk
}

// @0x140297430
Unk_BstrBlock::Unk_BstrBlock(const wchar_t* pszText)
{
    m_unk08 = NULL;
    m_nRefs = 1;
    m_pData = SysAllocString(pszText);
    if (m_pData == NULL && pszText != NULL)
        _com_issue_error(E_OUTOFMEMORY);
}

// @0x140297250
Unk_BstrBlock::Unk_BstrBlock(Unk_BstrHolderRef* pA, Unk_BstrHolderRef* pB)
{
    m_unk08 = NULL;
    m_nRefs = 1;
    const unsigned nLenA = pA->FUN_14029d4b0();
    const unsigned nLenB = pB->FUN_14029d4b0();
    int nNewLen;
    if (FUN_14028b840(nLenA, nLenB, &nNewLen) < 0 || FUN_14028b890(nNewLen, 2, (unsigned*)&nNewLen) < 0)
    {
        _com_issue_error(E_OUTOFMEMORY);
        return;
    }
    m_pData = SysAllocStringByteLen(NULL, (nLenA + nLenB) * sizeof(wchar_t));
    if (m_pData == NULL)
    {
        if (nLenA + nLenB == 0)
            return;
        _com_issue_error(E_OUTOFMEMORY);
        return;
    }
    const wchar_t* pszA = (const wchar_t*)FUN_140297d20(pA);
    if (pszA != NULL)
        memcpy_s(m_pData, (nLenA + nLenB + 1) * sizeof(wchar_t), pszA, (nLenA + 1) * sizeof(wchar_t));
    const wchar_t* pszB = (const wchar_t*)FUN_140297d20(pB);
    if (pszB != NULL)
        memcpy_s((wchar_t*)m_pData + nLenA, (nLenB + 1) * sizeof(wchar_t), pszB, (nLenB + 1) * sizeof(wchar_t));
}

// @0x140297550
Unk_BindHostPtr::Unk_BindHostPtr(const Unk_BindHostPtr& other)
{
    m_pHost = other.m_pHost;
    FUN_140299e30();
}

// @0x140297590
Unk_BstrBlock** FUN_140297590(Unk_BstrBlock** pp, void* pArg)
{
    *pp = new Unk_BstrBlock(pArg);
    if (*pp == NULL)
        _com_issue_error(E_OUTOFMEMORY);
    return pp;
}

// @0x140297620
Unk_BindHostPtr::Unk_BindHostPtr(const wchar_t* pszText)
{
    m_pHost = (Unk_BindHost*)new Unk_BstrBlock(pszText);
    if (m_pHost == NULL)
        _com_issue_error(E_OUTOFMEMORY);
}

// @0x140298560
Unk_BindHostPtr& Unk_BindHostPtr::operator+=(const Unk_BindHostPtr& other)
{
    Unk_BstrBlock* pNew = new Unk_BstrBlock((Unk_BstrHolderRef*)this, (Unk_BstrHolderRef*)&other);
    if (pNew == NULL)
    {
        _com_issue_error(E_OUTOFMEMORY);
    }
    else
    {
        FUN_14029b680((void**)this);
        m_pHost = (Unk_BindHost*)pNew;
    }
    return *this;
}

// @0x1402982e0
Unk_BindHostPtr FUN_1402982e0(const wchar_t* pszA, const Unk_BindHostPtr& b)
{
    Unk_BindHostPtr str(pszA);
    str += b;
    return str;
}

// @0x1402978a0
void FUN_1402978a0(void* p)
{
    FUN_140297790(p);
}

// @0x140297a20
Unk_BindHostPtr::~Unk_BindHostPtr() noexcept(false)
{
    FUN_14029b680((void**)this);
}

// @0x140297d20
void* FUN_140297d20(Unk_BstrHolderRef* p)
{
    return p->m_pHolder ? *FUN_140298fc0(p->m_pHolder) : NULL;
}

// @0x1402979b0
CItemTabNameTable::~CItemTabNameTable()
{
}

// @0x1402999c0
unsigned long FUN_1402999c0(Unk_BindHost* p)
{
    long nRefs = InterlockedDecrement(&p->m_nRefs);
    if (nRefs == 0)
    {
        Unk_BindHost* pHost = p;
        Unk_BindHost* pDel = pHost;
        pDel ? FUN_1402986c0(pDel, 1) : NULL;
    }
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
__declspec(safebuffers) CStringW FUN_140298ea0(CStringW strKey)      // the exe has no /GS cookie here
{
    char buf[16];                                       // the fmt::ArgList FUN_140183290 constructs
    return FUN_14028dfa0(strKey, *(const fmt::ArgList*)FUN_140183290(buf));
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
