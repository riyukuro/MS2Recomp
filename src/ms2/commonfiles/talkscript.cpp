// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CTalkScript (one talk of an NPC or quest), the script tables
// loaded from Script/Quest/questscript*.xml and Script/Npc/npcscript*.xml (reloaded when a file changes on disk), the
// lookups on them and the ATL map / array / smart pointer instances they need.
// MS2-UNIT: ?\talkscript.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x1400bd2a0-0x1400bd460 .text$di
// MS2-RANGE: 0x140854ea0-0x14085f650 .text$mn
// MS2-PIN: ??_7CTalkScript@@6B?$CValidData@VCTalkScript@@@@@ 0x142d9aa48
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@6B@ 0x142d9aa58
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@6B@ 0x142d9aa58
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@6B@ 0x142d9aa68
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAAXMMM_N@Z 0x14085ecb0
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x14085e3f0
// MS2-PIN: ??0?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAA@IMMMI@Z 0x1408598c0
// MS2-PIN: ??0?$CAtlMap@HV?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@@3@@ATL@@QEAA@IMMMI@Z 0x1408597d0
// MS2-PIN: ??0?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAA@IMMMI@Z 0x1408595f0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$Unk_TalkContentPtr@VCScriptContent@@@@QEAA@AEBV0@@Z 0x140859a00 ; unique
// MS2-PIN: ??0?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@QEAA@H@Z 0x140859a70 ; unique
// MS2-PIN: ??0?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@QEAA@AEAV0@@Z 0x140859b90 ; unique
// MS2-PIN: ??0?$TPtredDummy@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@QEAA@XZ 0x140859cb0 ; unique
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAA@II@Z 0x140859d50 ; prop
// MS2-PIN: ??0CNode@?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAA@HI@Z 0x140859e10 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@IEAA@I@Z 0x140859e50 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@@3@@ATL@@IEAA@H@Z 0x140859e90 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@IEAA@H@Z 0x140859f10 ; prop
// MS2-PIN: ??1CPair@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAA@XZ 0x14085a240 ; unique
// MS2-PIN: ??4?$Unk_TalkContentPtr@VCScriptContent@@@@QEAAAEAV0@PEAVCScriptContent@@@Z 0x14085a340 ; unique
// MS2-PIN: ??7?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@QEBA_NXZ 0x14085a3f0 ; unique
// MS2-PIN: ??7?$MS2Ptr@VCNpcData@@@@QEBA_NXZ 0x14085a420 ; prop
// MS2-PIN: ??8?$Unk_ScriptPtr@VCCacheData@@@@QEBA_NPEAVCCacheData@@@Z 0x14085a450 ; prop
// MS2-PIN: ??8?$Unk_ScriptPtr@VCTalkScript@@@@QEBA_NPEAVCTalkScript@@@Z 0x14085a490 ; unique
// MS2-PIN: ??C?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@QEBAPEAV?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@XZ 0x14085a5d0 ; unique
// MS2-PIN: ??C?$Unk_ScriptPtr@VCCacheData@@@@QEBAPEAVCCacheData@@XZ 0x14085a5e0 ; prop
// MS2-PIN: ??_F?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAAXXZ 0x14085a630 ; unique
// MS2-PIN: ??_GCNode@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAAPEAXI@Z 0x14085a7c0 ; unique
// MS2-PIN: ??4?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@QEAAAEAV0@AEBUUnk_GrNewTag@@@Z 0x14085a9b0 ; unique
// MS2-PIN: ?CreateNode@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x14085aaf0 ; prop
// MS2-PIN: ?CreateNode@?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@AEAAPEAVCNode@12@HII@Z 0x14085ac70 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x14085adf0 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x14085b030 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_ScriptPtr@VCTalkScript@@@@_K@Z 0x14085b5f0 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@QEBA_KXZ 0x14085b630 ; unique
// MS2-PIN: ?GetKeyAt@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@@3@@ATL@@QEBAAEBHPEAU__POSITION@@@Z 0x14085b680 ; prop
// MS2-PIN: ?GetKeyAt@?$CAtlMap@HV?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@@3@@ATL@@QEBAAEBHPEAU__POSITION@@@Z 0x14085b6f0 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14085b760 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14085b7b0 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@HV?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14085b800 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14085b850 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14085b940 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14085ba30 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x14085bc10 ; prop
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@@3@@ATL@@QEAAAEAV?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@PEAU__POSITION@@@Z 0x14085bd60 ; prop
// MS2-PIN: ?IsEmpty@?$CAtlMap@HV?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$TPtrValue@V?$CAtlArray@V?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@ATL@@@ATL@@@@@3@@ATL@@QEBA_NXZ 0x14085c4d0 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEBA_NIAEAV?$Unk_ScriptPtr@VCTalkScript@@@@@Z 0x14085c620 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x14085c7e0 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@AEAAPEAVCNode@12@HII@Z 0x14085ce10 ; prop
// MS2-PIN: ?Rehash@?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAAXI@Z 0x14085d3e0 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x14085e4e0 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$Unk_ScriptPtr@VCTalkScript@@@@@Z 0x14085e7e0 ; prop
// MS2-PIN: ?SetAt@?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$Unk_ScriptPtr@VCTalkScript@@@@@Z 0x14085e9f0 ; prop
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@HV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@QEAAXMMM_N@Z 0x14085eaa0 ; unique
// MS2-PIN: ?AddRefImpl@?$TPtrValue@V?$CAtlMap@IV?$Unk_ScriptPtr@VCTalkScript@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_ScriptPtr@VCTalkScript@@@@@3@@ATL@@@@AEBAXPEAX@Z 0x14085f290 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\talkscript.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <set>
#include "talkscript.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

typedef Unk_ScriptPtr<CTalkScript> TalkPtr;
typedef ATL::CAtlArray<TalkPtr> TalkArray;
typedef ATL::CAtlMap<int, TalkPtr> TalkPickMap;      // s_pick (0x14085bb20 group)
typedef ATL::CAtlMap<unsigned, TalkPtr> TalkIdMap;   // the per-quest talks (a separate COMDAT group, 0x14085b850...; same code)
typedef TPtrValue<TalkArray> TalkArrayPtr;
typedef TPtrValue<TalkIdMap> TalkIdMapPtr;
typedef Unk_ScriptPtr<CCacheData> CachePtr;
// Exe-resident members the file never calls: the unsigned-key twins of the int-key map members, and a second
// operator== COMDAT.
template void TalkIdMap::RemoveAtPos(POSITION);
template void TalkIdMap::SetOptimalLoad(float, float, float, bool);
template bool Unk_ScriptPtr<CCacheData>::operator==(CCacheData*) const;

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----

Unk_ScriptXmlNode* FUN_140165cf0(void* pNode, const char* pszName);                 // first child
Unk_ScriptXmlNode* FUN_140168650(Unk_ScriptXmlNode* pNode, const char* pszName);    // next sibling
const char* FUN_14086f4b0(Unk_ScriptXmlNode* pNode, const char* pszName);           // attribute text (null = absent)
void FUN_14086f600(Unk_ScriptXmlNode* pNode, const char* pszName, int* pOut);
int FUN_140873710(Unk_ScriptXmlNode* pNode, const char* pszName, int* pOut);
int FUN_1408731e0(Unk_ScriptXmlNode* pNode, const char* pszName, int& rOut);
int FUN_140873220(Unk_ScriptXmlNode* pNode, const char* pszName, int& rOut);
int FUN_140873220(Unk_ScriptXmlNode* pNode, const char* pszName, unsigned& rOut);
int FUN_140873420(Unk_ScriptXmlNode* pNode, const char* pszName, CStringW& rOut);
void FUN_1406363a0(Unk_ScriptXmlNode* pNode, const char* pszName, int* pOut);       // job condition
CStringA FUN_14015f710(Unk_ScriptXmlNode* pNode, const char* pszName, CStringA strDefault);
void FUN_140177de0(CStringA& str, ATL::CAtlArray<int>& rOut, const char* pszSep);   // split into ints
bool FUN_14028f710(Unk_ScriptXmlNode* pNode);                                       // element is enabled
unsigned FUN_140767ff0();                                                           // random
CFileSystem* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
void FUN_140399100(CString strMask, CString strDir, ATL::CAtlArray<CString>& rOut, CString strExtra, bool bRecursive);
CString FUN_14028d3c0(CString strPath);                                             // file name of a path
void FUN_1401d3700(CString* pStr);                                                  // lower-case
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);
CString FUN_14016a5c0(const char* pszName, int);

// The <script>/<select>/<job> children of a parent (24 bytes, a vector of element pointers) with index access.
class Unk_ElemArray
{
public:
    void FUN_140163e20();                                           // ctor
    void FUN_1401644e0();                                           // dtor
    unsigned __int64 FUN_14016d900();                               // size
    Unk_ScriptXmlNode*& FUN_140164a30(unsigned __int64 n);          // operator[]
    void *m_a, *m_b, *m_c;
};
void FUN_14028faa0(Unk_ScriptXmlNode* pParent, const char* pszName, const char* pszAttr, Unk_ElemArray* pOut);

void FUN_140857f20(CStringA path);
void FUN_140858440(CStringA path);
void FUN_140859160(Unk_ScriptXmlNode* pNode, TalkPtr script);
void FUN_140859320(Unk_ScriptXmlNode* pNode, TalkPtr script);
void FUN_1408559b0();
TalkArrayPtr FUN_140857330(int nNpcId);
TalkArrayPtr FUN_140857660(int nNpcId);

// ---- the script tables (static initializers in .text$di, in this order) ----

MS2_TALKSCRIPT_STATIC TalkPickMap s_pick[2];                         // 0x143ab1ea0 [0] select, [1] job: npc id -> talk
MS2_TALKSCRIPT_STATIC ATL::CAtlMap<int, TalkArrayPtr> s_npcAlt;    // 0x143ab1e10 npc id -> monologues
MS2_TALKSCRIPT_STATIC ATL::CAtlMap<int, TalkArrayPtr> s_npcTalks;  // 0x143ab1dc0 npc id -> talks
MS2_TALKSCRIPT_STATIC ATL::CAtlArray<CachePtr> s_npcFiles;         // 0x143ab1e78 loaded Script/Npc files
MS2_TALKSCRIPT_STATIC ATL::CAtlMap<int, TalkIdMapPtr> s_questTalks;// 0x143ab1d70 quest id -> talks by id
MS2_TALKSCRIPT_STATIC ATL::CAtlArray<CachePtr> s_questFiles;       // 0x143ab1e58 loaded Script/Quest files
MS2_TALKSCRIPT_STATIC CLockCriticalSection s_lock;                 // 0x143ab1d40
MS2_TALKSCRIPT_STATIC bool s_valid;                                // 0x143ab1d30

// @0x14085aa40
static void CheckValid()
{
    if (!s_valid)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CTalkScript).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x14085ed60
static void SetValid(bool bValid) { s_valid = bValid; }

// ---- CChatballonContent (the other virtuals are in ?\scriptcontent.cpp) ----

// @0x140859d20
CChatballonContent::CChatballonContent()
{
}

// @0x14085a190
CChatballonContent::~CChatballonContent()
{
}

// ---- CTalkScript ----

// @0x140854ea0
CTalkScript::CTalkScript()
{
    m_id = 0;
    m_questId = 0;
    m_npcId = 0;
    m_popupState = 9;
    m_popupProp = 100;
    m_randomPick = 0;
    m_jobCondition = 0;
    m_88 = false;
}

// @0x140854fa0
CTalkScript::CTalkScript(CInPacket& in)
{
    Deserialize(in);
}

// @0x140855050
CTalkScript::~CTalkScript()
{
}

// @0x1408550e0
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
void CTalkScript::Serialize(COutputStream* out)
{
    out->vfunc_o10_3(m_npcId);
    out->vfunc_o10_1((unsigned char)m_popupState);
    out->vfunc_o10_3(m_popupProp);
    int randomPick = m_randomPick != 0 ? 1 : 0;
    out->vfunc_o10_1(randomPick);
    out->vfunc_o10_3((int)m_contents.GetCount());
    for (size_t i = 0; i < m_contents.GetCount(); i++)
        m_contents[i]->vfunc_5(*out);
}

// @0x140855210
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
void CTalkScript::Deserialize(CInPacket& in)
{
    m_id = 0;
    m_questId = 0;
    m_npcId = in.vfunc_o8_3();
    m_popupState = in.vfunc_o8_1();
    m_popupProp = in.vfunc_o8_3();
    m_randomPick = in.vfunc_o8_1() == 1;
    m_jobCondition = 0;
    m_88 = true;
    int count = in.vfunc_o8_3();
    for (int i = 0; i < count; i++)
    {
        Unk_TalkContentPtr<CScriptContent> content(0);
        unsigned char type = in.vfunc_o8_1();
        if (type == 0)
            content = new CCinematicContent();
        else if (type == 1)
            content = new CChatballonContent();
        content->vfunc_6(reinterpret_cast<CByteBuffer&>(in));    // same input stream at +8
        m_contents.Add(content);
    }
}

// @0x140855520
bool CTalkScript::Is88() const
{
    return m_88;
}

// ---- lookups ----

// @0x140855cd0
int FUN_140855cd0(unsigned char nFlags)
{
    if ((nFlags & 2) != 0)
        return 1;
    if ((nFlags & 0x20) != 0)
        return 1;
    return 0;
}

// @0x140857330
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
TalkArrayPtr FUN_140857330(int nNpcId)
{
    CheckValid();
    TalkArrayPtr result(0);
    Unk_LockGuard guard(s_lock);
    if (!guard && s_npcTalks.Lookup(nNpcId, result))
    {
        bool bChanged = false;
        for (unsigned i = 0; i < s_npcFiles.GetCount(); i++)
        {
            if (FUN_1401d1320(s_npcFiles[i].get()))
            {
                bChanged = true;
                break;
            }
        }
        if (bChanged)
        {
            ATL::CAtlArray<CString> paths;
            for (unsigned i = 0; i < s_npcFiles.GetCount(); i++)
                paths.Add(*s_npcFiles[i]->FUN_1401d1140());
            s_npcFiles.RemoveAll();
            s_npcTalks.RemoveAll();
            s_npcAlt.RemoveAll();
            for (int k = 0; k < 2; k++)
                s_pick[k].RemoveAll();
            for (unsigned i = 0; i < paths.GetCount(); i++)
                FUN_140858440(paths[i]);
            if (!s_npcTalks.Lookup(nNpcId, result))
                return TalkArrayPtr(0);
        }
        return result;
    }
    return TalkArrayPtr(0);
}

// @0x140857660
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
TalkArrayPtr FUN_140857660(int nNpcId)
{
    CheckValid();
    TalkArrayPtr result(0);
    Unk_LockGuard guard(s_lock);
    if (!guard && s_npcAlt.Lookup(nNpcId, result))
    {
        bool bChanged = false;
        for (unsigned i = 0; i < s_npcFiles.GetCount(); i++)
        {
            if (FUN_1401d1320(s_npcFiles[i].get()))
            {
                bChanged = true;
                break;
            }
        }
        if (bChanged)
        {
            ATL::CAtlArray<CString> paths;
            for (unsigned i = 0; i < s_npcFiles.GetCount(); i++)
                paths.Add(*s_npcFiles[i]->FUN_1401d1140());
            s_npcFiles.RemoveAll();
            s_npcTalks.RemoveAll();
            s_npcAlt.RemoveAll();
            for (int k = 0; k < 2; k++)
                s_pick[k].RemoveAll();
            for (unsigned i = 0; i < paths.GetCount(); i++)
                FUN_140858440(paths[i]);
            if (!s_npcAlt.Lookup(nNpcId, result))
                return TalkArrayPtr(0);
        }
        return result;
    }
    return TalkArrayPtr(0);
}

// @0x140855d10
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
int FUN_140855d10(int nNpcId)
{
    return !!FUN_140857330(nNpcId);
}

// @0x140855d80
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
bool FUN_140855d80(int nNpcId)
{
    return !!FUN_140857660(nNpcId);
}

// @0x140856820
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
TalkPtr FUN_140856820(int nNpcId, int nTalkId)
{
    TalkArrayPtr list = FUN_140857330(nNpcId);
    if (!list)
        return TalkPtr(0);
    for (size_t i = 0; i < (*list.operator->()).GetCount(); i++)
    {
        TalkPtr script = (*list.operator->())[i];
        if (script->m_id == nTalkId)
            return script;
    }
    return TalkPtr(0);
}

// @0x140856980
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
TalkPtr FUN_140856980(int nNpcId, const CStringW& strTag)
{
    TalkArrayPtr list = FUN_140857330(nNpcId);
    if (!list)
        return TalkPtr(0);
    for (size_t i = 0; i < (*list.operator->()).GetCount(); i++)
    {
        TalkPtr script = (*list.operator->())[i];
        if (script->m_tag == strTag)
            return script;
    }
    return TalkPtr(0);
}

// @0x140856af0
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
TalkPtr FUN_140856af0(int nNpcId, int nTalkId)
{
    TalkArrayPtr list = FUN_140857660(nNpcId);
    if (!list)
        return TalkPtr(0);
    for (size_t i = 0; i < (*list.operator->()).GetCount(); i++)
    {
        TalkPtr script = (*list.operator->())[i];
        if (script->m_id == nTalkId)
            return script;
    }
    return TalkPtr(0);
}

// @0x140856c50
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
TalkPtr FUN_140856c50(int nNpcId, int nKind)
{
    CheckValid();
    TalkPtr result(0);
    Unk_LockGuard guard(s_lock);
    if (!guard && s_pick[nKind].Lookup(nNpcId, result))
    {
        bool bChanged = false;
        for (unsigned i = 0; i < s_npcFiles.GetCount(); i++)
        {
            if (FUN_1401d1320(s_npcFiles[i].get()))
            {
                bChanged = true;
                break;
            }
        }
        if (bChanged)
        {
            ATL::CAtlArray<CString> paths;
            for (unsigned i = 0; i < s_npcFiles.GetCount(); i++)
                paths.Add(*s_npcFiles[i]->FUN_1401d1140());
            s_npcFiles.RemoveAll();
            s_npcTalks.RemoveAll();
            s_npcAlt.RemoveAll();
            for (int k = 0; k < 2; k++)
                s_pick[k].RemoveAll();
            for (unsigned i = 0; i < paths.GetCount(); i++)
                FUN_140858440(paths[i]);
            if (!s_pick[nKind].Lookup(nNpcId, result))
                return TalkPtr(0);
        }
        return result;
    }
    return TalkPtr(0);
}

// @0x140856fa0
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
TalkPtr FUN_140856fa0(int nNpcId, int nState)
{
    TalkArrayPtr list = FUN_140857660(nNpcId);
    if (!list)
        return TalkPtr(0);
    int total = 0;
    ATL::CAtlArray<TalkPtr> candidates;
    for (size_t i = 0; i < (*list.operator->()).GetCount(); i++)
    {
        TalkPtr script = (*list.operator->())[i];
        if (script->m_popupState != nState)
            continue;
        candidates.Add(script);
        total += script->m_popupProp;
    }
    if (candidates.GetCount() == 0 || total == 0)
        return TalkPtr(0);
    int roll = FUN_140767ff0() % 100;
    if (roll < total)
    {
        roll = FUN_140767ff0() % total;
        int accumulated = 0;
        for (size_t i = 0; i < candidates.GetCount(); i++)
        {
            TalkPtr script = candidates[i];
            accumulated += script->m_popupProp;
            if (accumulated > roll)
                return script;
        }
    }
    return TalkPtr(0);
}

// @0x1408572b0
void FUN_1408572b0()
{
    s_questTalks.RemoveAll();
    s_npcTalks.RemoveAll();
    s_questFiles.RemoveAll();
    s_npcFiles.RemoveAll();
    s_pick[0].RemoveAll();
    s_pick[1].RemoveAll();
}

// @0x1408564b0
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
TalkPtr FUN_1408564b0(int nQuestId, int nTalkId)
{
    CheckValid();
    TalkPtr result(0);
    TalkIdMapPtr talks(0);
    Unk_LockGuard guard(s_lock);
    if (!guard)
    {
        bool bChanged = false;
        for (unsigned i = 0; i < s_questFiles.GetCount(); i++)
        {
            if (FUN_1401d1320(s_questFiles[i].get()))
            {
                bChanged = true;
                break;
            }
        }
        if (bChanged)
        {
            ATL::CAtlArray<CString> paths;
            for (unsigned i = 0; i < s_questFiles.GetCount(); i++)
                paths.Add(*s_questFiles[i]->FUN_1401d1140());
            s_questFiles.RemoveAll();
            s_questTalks.RemoveAll();
            for (unsigned i = 0; i < paths.GetCount(); i++)
                FUN_140857f20(paths[i]);
            if (!s_questTalks.Lookup(nQuestId, talks))
                return TalkPtr(0);
        }
        if (!s_questTalks.Lookup(nQuestId, talks))
            return TalkPtr(0);
        talks->Lookup(nTalkId, result);
        return result;
    }
    return result;
}

// @0x140855ed0
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
TalkPtr FUN_140855ed0(int nQuestId, int nTier, int nJob)
{
    CheckValid();
    TalkPtr unused(0);
    TalkIdMapPtr talks(0);
    Unk_LockGuard guard(s_lock);
    if (!guard)
    {
        bool bChanged = false;
        for (unsigned i = 0; i < s_questFiles.GetCount(); i++)
        {
            if (FUN_1401d1320(s_questFiles[i].get()))
            {
                bChanged = true;
                break;
            }
        }
        if (bChanged)
        {
            ATL::CAtlArray<CString> paths;
            for (unsigned i = 0; i < s_questFiles.GetCount(); i++)
                paths.Add(*s_questFiles[i]->FUN_1401d1140());
            s_questFiles.RemoveAll();
            s_questTalks.RemoveAll();
            for (unsigned i = 0; i < paths.GetCount(); i++)
                FUN_140857f20(paths[i]);
            if (!s_questTalks.Lookup(nQuestId, talks))
                return TalkPtr(0);
        }
        if (!s_questTalks.Lookup(nQuestId, talks))
            return TalkPtr(0);
        int low = 0;
        int high = 0;
        if (nTier == 0) { low = 100; high = 200; }
        else if (nTier == 1) { low = 200; high = 300; }
        else if (nTier == 2) { low = 300; high = 400; }
        TalkPtr jobMatch(0);
        TalkPtr exact(0);
        for (POSITION pos = talks->GetStartPosition(); pos != 0; talks->GetNext(pos))
        {
            TalkPtr script = talks->GetValueAt(pos);
            if (script->m_id < low || high <= script->m_id)
                continue;
            if (script->m_id == low)
                exact = script;
            else if (script->m_jobCondition != 0 && script->m_jobCondition == nJob)
                jobMatch = script;
        }
        if (jobMatch.get())
            return jobMatch;
        if (exact.get())
            return exact;
    }
    return TalkPtr(0);
}

// ---- XML loaders ----

// @0x140859160
void FUN_140859160(Unk_ScriptXmlNode* pNode, TalkPtr script)
{
    if (pNode == 0)
        return;
    if (FUN_14086f4b0(pNode, "randomPick") != 0)
        FUN_140873710(pNode, "randomPick", &script->m_randomPick);
    for (Unk_ScriptXmlNode* child = FUN_140165cf0(pNode, "content"); child != 0; child = FUN_140168650(child, "content"))
    {
        Unk_ScriptPtr<CCinematicContent> content(new CCinematicContent());
        content->m_questId = script->m_questId;
        content->vfunc_2(child);
        Unk_TalkContentPtr<CScriptContent> base(content.get());
        script->m_contents.Add(base);
    }
}

// @0x140859320
void FUN_140859320(Unk_ScriptXmlNode* pNode, TalkPtr script)
{
    if (FUN_14086f4b0(pNode, "popupProp") != 0)
        FUN_14086f600(pNode, "popupProp", &script->m_popupProp);
    if (FUN_14086f4b0(pNode, "popupState") != 0)
        FUN_14086f600(pNode, "popupState", &script->m_popupState);
    for (Unk_ScriptXmlNode* child = FUN_140165cf0(pNode, "content"); child != 0; child = FUN_140168650(child, "content"))
    {
        Unk_ScriptPtr<CChatballonContent> content(new CChatballonContent());
        content->vfunc_2(child);
        Unk_TalkContentPtr<CScriptContent> base(content.get());
        script->m_contents.Add(base);
    }
}

// @0x140857f20
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
void FUN_140857f20(CStringA path)
{
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, path, 0, true, false))
        return;
    CachePtr cache(new CCacheData());
    cache->FUN_1401d1160(path);
    s_questFiles.Add(cache);
    Unk_ScriptXmlNode* root = FUN_140165cf0(&doc, "ms2");
    if (!root)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", path);
        return;
    }
    for (Unk_ScriptXmlNode* quest = FUN_140165cf0(root, "quest"); quest != 0; quest = FUN_140168650(quest, "quest"))
    {
        int questId = 0;
        FUN_140873220(quest, "id", questId);
        if (questId == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"\uAC12\uC774 0 \uC785\uB2C8\uB2E4.[<ms2> {0}]", path);
            continue;
        }
        TalkIdMapPtr talks(0);
        Unk_LockGuard guard(s_lock);
        if (!guard && !s_questTalks.Lookup(questId, talks))
        {
            talks = Unk_GrNewTag(0);
            s_questTalks.SetAt(questId, talks);
        }
        Unk_ElemArray nodes;
        nodes.FUN_140163e20();
        FUN_14028faa0(quest, "script", "id", &nodes);
        for (unsigned __int64 i = 0; i < nodes.FUN_14016d900(); i++)
        {
            Unk_ScriptXmlNode* node = nodes.FUN_140164a30(i);
            TalkPtr script(new CTalkScript());
            script->m_questId = questId;
            FUN_1408731e0(node, "id", script->m_id);
            FUN_140873420(node, "tag", script->m_tag);
            FUN_1406363a0(node, "jobCondition", &script->m_jobCondition);
            FUN_140859160(node, script);
            talks->SetAt(script->m_id, script);
        }
        nodes.FUN_1401644e0();
    }
}

// @0x140858440
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
void FUN_140858440(CStringA path)
{
    Unk_CriticalSectionLock lock(s_lock, 1);
    TiXmlDocument doc;
    if (!FUN_140166420()->FUN_1403974b0(&doc, path, 0, true, false))
        return;
    Unk_ScriptXmlNode* root = FUN_140165cf0(&doc, "ms2");
    if (!root)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \uD615\uC2DD\uC774 \uC798\uBABB \uB418\uC5C8\uC2B5\uB2C8\uB2E4[<ms2> {0}]", path);
        return;
    }
    CachePtr cache(new CCacheData());
    cache->FUN_1401d1160(path);
    s_npcFiles.Add(cache);
    for (Unk_ScriptXmlNode* npc = FUN_140165cf0(root, "npc"); npc != 0; npc = FUN_140168650(npc, "npc"))
    {
        int npcId = 0;
        FUN_140873220(npc, "id", npcId);
        std::set<unsigned> usedIds;
        TalkArrayPtr talks(Unk_GrNewTag(0));
        Unk_ElemArray scriptNodes;
        scriptNodes.FUN_140163e20();
        FUN_14028faa0(npc, "script", "id", &scriptNodes);
        for (unsigned __int64 i = 0; i < scriptNodes.FUN_14016d900(); i++)
        {
            Unk_ScriptXmlNode* node = scriptNodes.FUN_140164a30(i);
            TalkPtr script(new CTalkScript());
            script->m_npcId = npcId;
            FUN_1408731e0(node, "id", script->m_id);
            FUN_140873420(node, "tag", script->m_tag);
            {
                CStringA gotoIds = FUN_14015f710(node, "gotoConditionTalkID", "");
                if (gotoIds.GetLength() != 0)
                    FUN_140177de0(gotoIds, script->m_gotoConditionTalkIds, ",");
            }
            FUN_140859160(node, script);
            if (script->m_randomPick == 1 && script->m_contents.GetCount() == 0)
                continue;
            talks->Add(script);
            usedIds.insert(script->m_id);
        }
        if (talks->GetCount() != 0)
            s_npcTalks.SetAt(npcId, talks);
        scriptNodes.FUN_1401644e0();

        TalkArrayPtr monologues(Unk_GrNewTag(0));
        for (Unk_ScriptXmlNode* node = FUN_140165cf0(npc, "monologue"); node != 0; node = FUN_140168650(node, "monologue"))
        {
            if (!FUN_14028f710(node))
                continue;
            TalkPtr script(new CTalkScript());
            script->m_npcId = npcId;
            FUN_1408731e0(node, "id", script->m_id);
            FUN_140873420(node, "tag", script->m_tag);
            FUN_140859320(node, script);
            monologues->Add(script);
            usedIds.insert(script->m_id);
        }
        if (monologues->GetCount() != 0)
            s_npcAlt.SetAt(npcId, monologues);

        bool hasSelect = false;
        const char* kinds[2] = { "select", "job" };
        for (int k = 0; k < 2; k++)
        {
            Unk_ElemArray nodes;
            nodes.FUN_140163e20();
            FUN_14028faa0(npc, kinds[k], "id", &nodes);
            if (nodes.FUN_14016d900() != 0)
            {
                Unk_ScriptXmlNode* node = nodes.FUN_140164a30(0);
                TalkPtr script(new CTalkScript());
                script->m_npcId = npcId;
                FUN_1408731e0(node, "id", script->m_id);
                FUN_140873420(node, "tag", script->m_tag);
                FUN_140859160(node, script);
                usedIds.insert(script->m_id);
                if (k == 0)
                {
                    hasSelect = true;
                    if (script->m_contents.GetCount() == 0)
                    {
                        Unk_ScriptPtr<CCinematicContent> content(new CCinematicContent());
                        script->m_contents.Add(Unk_TalkContentPtr<CScriptContent>(content.get()));
                    }
                }
                s_pick[k].SetAt(npcId, script);
            }
            nodes.FUN_1401644e0();
        }
        if (!hasSelect)
        {
            unsigned id = 0;
            do
            {
                id = FUN_140767ff0();
            } while (usedIds.find(id) != usedIds.end());
            TalkPtr script(new CTalkScript());
            script->m_npcId = npcId;
            script->m_id = id;
            Unk_ScriptPtr<CCinematicContent> content(new CCinematicContent());
            script->m_contents.Add(Unk_TalkContentPtr<CScriptContent>(content.get()));
            usedIds.insert(script->m_id);
            s_pick[0].SetAt(npcId, script);
        }
    }
}

// Tells every content which npc / quest it belongs to.
// @0x1408559b0
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
void FUN_1408559b0()
{
    Unk_LockGuard guard(s_lock);
    if (!guard)
    {
        for (POSITION pos = s_npcTalks.GetStartPosition(); pos != 0; s_npcTalks.GetNext(pos))
        {
            int npcId = s_npcTalks.GetKeyAt(pos);
            TalkArrayPtr list = s_npcTalks.GetValueAt(pos);
            for (size_t i = 0; i < (*list.operator->()).GetCount(); i++)
            {
                TalkPtr script = (*list.operator->())[i];
                for (size_t j = 0; j < script->m_contents.GetCount(); j++)
                    script->m_contents[j]->vfunc_3(npcId);
            }
        }
        for (POSITION pos = s_questTalks.GetStartPosition(); pos != 0; s_questTalks.GetNext(pos))
        {
            int questId = s_questTalks.GetKeyAt(pos);
            TalkIdMapPtr talks = s_questTalks.GetValueAt(pos);
            for (POSITION inner = talks->GetStartPosition(); inner != 0; talks->GetNext(inner))
            {
                TalkPtr script = talks->GetValueAt(inner);
                for (size_t j = 0; j < script->m_contents.GetCount(); j++)
                    script->m_contents[j]->vfunc_4(questId);
            }
        }
    }
}

// @0x140855540
void LoadTalkScripts()
{
    {
        ATL::CAtlArray<CString> files;
        FUN_140399100("*.xml", FUN_14071a5b0("Script/Quest", ""), files, "", false);
        for (size_t i = 0; i < files.GetCount(); i++)
        {
            CString name = FUN_14028d3c0(files[i]);
            FUN_1401d3700(&name);
            if (name.Find("questscript", 0) == 0)
                FUN_140857f20(files[i]);
        }
    }
    {
        ATL::CAtlArray<CString> files;
        FUN_140399100("*.xml", FUN_14071a5b0("Script/Npc", ""), files, "", false);
        for (size_t i = 0; i < files.GetCount(); i++)
        {
            CString name = FUN_14028d3c0(files[i]);
            FUN_1401d3700(&name);
            if (name.Find("npcscript", 0) == 0)
                FUN_140858440(files[i]);
        }
    }
    SetValid(true);
    FUN_1408559b0();
}

// @0x140855df0
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
int FUN_140855df0(unsigned nNpcId, TalkPtr script)
{
    CheckValid();
    for (size_t i = 0; i < 2; i++)
    {
        TalkPtr found(0);
        if (s_pick->Lookup(nNpcId, found))
        {
            if (found == script.get())
                return 1;
        }
    }
    return 0;
}

// The button set the talk window shows for a page.
// @0x140857990
// MS2-FUNCTIONAL: calls into ATL/TPtr COMDATs owned by other units resolve to different targets and the hand-written control flow differs in the large body; permuter lane
int FUN_140857990(TalkPtr script, unsigned char nFlags, int nNpcId, int nPage)
{
    if (!script.get())
        return 0;
    if (nPage >= (int)script->m_contents.GetCount())
        return 0;
    if (script->m_contents[nPage]->vfunc_1() != 0)
        return 0;
    CCinematicContent* content = static_cast<CCinematicContent*>(script->m_contents[nPage].get());
    bool isLast = nPage == (int)script->m_contents.GetCount() - 1;
    if (isLast)
        isLast = script->m_gotoConditionTalkIds.GetCount() == 0;
    if ((nFlags & 8) != 0)
        return 5;
    if (content->m_buttonSet != 0)
        return content->m_buttonSet;
    MS2Ptr<CNpcData> npc = FUN_1406cd330(nNpcId);
    if (!npc)
        return 0;
    int hasBit = (npc->GetNpcTypeGroup() != 3 && (nFlags & 1) != 0) ? 1 : 0;
    if (content->m_distractors.get() && content->m_distractors->FUN_14078d3d0() != 0 && hasBit == 0)
    {
        if (script->Is88())
            return 0x13;
        return 9;
    }
    if (!isLast)
        return 4;
    if ((nFlags & 1) != 0)
        return npc->GetNpcTypeGroup();
    if (FUN_140855cd0(nFlags) != 0)
        return 3;
    if ((nFlags & 4) != 0)
    {
        if (script->m_id >= 300)
            return 7;
        if (script->m_id >= 100 && script->m_id < 200)
            return 6;
        return 8;
    }
    if ((nFlags & 0x10) != 0)
        return 3;
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c4d0-0x142c9c540 .text$yd
// MS2-RANGE: 0x142c9c560-0x142c9c580 .text$yd
// MS2-RANGE: 0x142c9c5a0-0x142c9c5c0 .text$yd
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142c9c540-0x142c9c560 .text$yd
// MS2-RANGE: 0x142c9c580-0x142c9c5a0 .text$yd
