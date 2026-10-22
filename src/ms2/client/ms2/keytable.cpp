// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's keytable.cpp: CKeyTable, the key bindings
// (key code -> stKeyData), their action index, the default key files (Table/default/Default*Key.xml), the quick slot
// pages and the key-setting categories of the option tabs, plus the template glue of its containers. Names are invented
// from use (see ms2/placeholder/ckeytable.h).
// MS2-UNIT: client\ms2\keytable.cpp
// MS2-RANGE: 0x1414286a0-0x14143d580 .text$mn
// MS2-RANGE: 0x1400f6ce0-0x1400f6db0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141432710 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHPEAVUnk_140165cf0@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x141432800 ; unique
// MS2-PIN: ??$FUN_14028dfa0@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@V12@V12@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBV01@111@Z 0x141432bf0 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@?$_Tree@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHPEAVUnk_140165cf0@@@1@@Z 0x141433030 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x141433050 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@1@AEAU?$pair@$$CBHPEAVUnk_140165cf0@@@1@1@Z 0x1414331b0 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHPEAVUnk_140165cf0@@@1@PEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@1@@Z 0x141433510 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHPEAVUnk_140165cf0@@@1@PEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@1@@Z 0x141434150 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x141434610 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHPEAVUnk_140165cf0@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1414347e0 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1414348b0 ; unique
// MS2-PIN: ??$forward@AEAU?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@YAAEAU?$pair@$$CBHPEAVUnk_140165cf0@@@0@AEAU10@@Z 0x141434960 ; prop
// MS2-PIN: ??0CNode@?$CRBTree@HV?$MS2Ptr@VstKeyData@CKeyTable@@@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VstKeyData@CKeyTable@@@@@3@@ATL@@QEAA@AEBHAEBV?$MS2Ptr@VstKeyData@CKeyTable@@@@@Z 0x1414353d0 ; unique
// MS2-PIN: ??0CPair@?$CRBTree@HV?$MS2Ptr@VstKeyData@CKeyTable@@@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VstKeyData@CKeyTable@@@@@3@@ATL@@IEAA@AEBHAEBV?$MS2Ptr@VstKeyData@CKeyTable@@@@@Z 0x141435500 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141435f30 ; prop
// MS2-PIN: ?Find@?$CRBTree@HV?$MS2Ptr@VstKeyData@CKeyTable@@@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VstKeyData@CKeyTable@@@@@3@@ATL@@IEBAPEAVCNode@12@AEBH@Z 0x1414368d0 ; unique
// MS2-PIN: ?Find@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CDefaultElementTraits@H@2@@ATL@@IEBAPEAVCNode@12@_K@Z 0x1414369c0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HHV?$CDefaultElementTraits@H@ATL@@V12@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x1414375a0 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@HV?$MS2Ptr@VstKeyData@CKeyTable@@@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VstKeyData@CKeyTable@@@@@3@@ATL@@AEAAPEAVCNode@12@AEBHAEBV?$MS2Ptr@VstKeyData@CKeyTable@@@@@Z 0x141437f20 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@_KHV?$CElementTraits@_K@ATL@@V?$CDefaultElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@_KAEBH@Z 0x141438020 ; unique
// MS2-PIN: ?NewNode@?$CRBTree@HV?$MS2Ptr@VstKeyData@CKeyTable@@@@V?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VstKeyData@CKeyTable@@@@@3@@ATL@@AEAAPEAVCNode@12@AEBHAEBV?$MS2Ptr@VstKeyData@CKeyTable@@@@@Z 0x141439150 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@2@XZ 0x14143c160 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x14143c240 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@2@@Z 0x14143c2b0 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@2@@Z 0x14143c980 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@2@_K@Z 0x14143d020 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@PEAX@2@_K@Z 0x14143d050 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HPEAVUnk_140165cf0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHPEAVUnk_140165cf0@@@std@@@std@@@std@@@2@AEBH@Z 0x14143d280 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_pointer@@YAXXZ 0x1400f6d40
// MS2-PIN: memcpy_s 0x14143d430
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCKeySettingParam@@@@V?$CElementTraits@V?$MS2Ptr@VCKeySettingParam@@@@@ATL@@@ATL@@@@6B@ 0x142f12e20
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\keytable.cpp"    // the _wassert path of FUN_141431ae0
// The exe's memcpy_s is a plain call (no /Oi expansion); the pragma must precede the inline copy.
#include <vcruntime_string.h>
#pragma function(memset, memcpy)
#include <corecrt_memcpy_s.h>
#pragma intrinsic(memset)                                   // the ATL array glue clears with the intrinsic
#include "ms2/placeholder/ms2stdafx.h"
#include <stdlib.h>
#include <egf/Entity.h>
#include "ms2/placeholder/ckeytable.h"
#include "ms2/placeholder/ckeysettingparam.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/gameoptioninputdefault.h"
#include "ms2/client/ms2/ms2inputservice.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include <sstream>
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/notifykeytable.h"
#include "ms2/client/ms2/skillslot.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/placeholder/cskillsettable.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uiscenegame.h"
#include <vector>
#include <map>
#include "hook/ms2hook.h"
extern template class MS2Ptr<Unk_RideeData>;          // the riding row's pointer glue is another unit's (0x140788ed0)

// The UCRT's `static __inline memcpy_s` of this TU (kept alive by the pointer below).
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;

// ---- file statics (.text$di): the shared header statics without the sort type names ----
#ifndef MS2_HOOK_DLL
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
#include "ms2/client/ms2/statemanager_statics.h"
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
#endif

// ---- callees in other units ----
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
class Unk_KtLog                                             // CLogString
{
public:
    void FUN_14015eb90(int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg);
    void FUN_1406530d0(int nLevel, int nCategory, const wchar_t* pszFormat, const fmt::ArgList& args);
};
Unk_KtLog* FUN_140166440();
CFeatureManager* FUN_140166410();
MS2InputService* FUN_140a58540();
CStateService* FUN_140aa6d30();
CStringTable* GetStringTable();
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
int FUN_14086f500(Unk_140165cf0* pElem, const char* pszName, int* pOut);       // QueryIntAttribute
int FUN_14086f500(Unk_140165cf0* pElem, const char* pszName, unsigned* pOut);  // QueryIntAttribute (unsigned out)
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);         // Attribute
void FUN_14086f8d0(Unk_140165cf0* pElem, const char* pszName, const char* pszValue);   // SetAttribute
void FUN_14086f920(Unk_140165cf0* pElem, const char* pszName, int nValue);     // SetAttribute (int)
void* FUN_14086e090(void* pParent, void* pChild);                              // LinkEndChild
CString FUN_14028d1f0(const char* psz);
CStringW GetStringCommonByKey(const CStringW& strKey);              // string table text by key
void FUN_1412751f0(const CStringW& strText, int nA, int nB);  // system notice
MS2Ptr<CItemData> FUN_14053f870(int nItemId);               // the item table record
extern int DAT_143af7d40;                                   // input enabled
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pElem);                   // the element is enabled
int FUN_140197350(Unk_140165cf0* pElem, const char* pszName, int nDefault);           // int attribute
unsigned FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned nDefault);  // unsigned attribute
void FUN_1422c9380(const CString& str);                     // the action's binding changed (UI notice)
class Unk_KtHeldData { public: int FUN_14053dc90(); };     // CItemData: the item's skill id
class Unk_KtHeldItem { public: Unk_KtHeldData* FUN_140527840(); };   // CItem: its data
class Unk_KtPlayer                                          // MyPC
{
public:
    int FUN_14165c570();                                    // the active stance skill
    Unk_KtHeldItem* FUN_14165f100();                        // the held item
    int FUN_14165f150();                                    // an item is held
    int FUN_14166c930();                                    // the current state id
    int FUN_1416764d0();                                    // riding
    Ridee* FUN_1416764a0();                                 // the ridee this player rides
    int FUN_141654700();                                    // the job
    int FUN_14166ce30();                                    // busy (a cutscene/state blocks input)
    int FUN_1416595d0();                                    // dead
};
class Unk_KtWorld { public: Unk_KtPlayer* FUN_141bd0cc0(); };   // the local player
class Unk_KtRestrictions { public: int FUN_14138c900(int nKind); };
Unk_KtRestrictions* FUN_1409331e0();
void FUN_141275260(int nStringId, int nA, int nB);          // system notice of a string table entry
bool FUN_140347960(int nSkillId);
class Unk_KtMainPlayerInfo                                  // UIMainPlayerInfo
{
public:
    SkillSlot* FUN_1419f2930(int nIndex);                   // a quick slot
    void FUN_1419f2a90();                                   // leave the skill set mode
};
Unk_KtMainPlayerInfo* FUN_140931900(int nUiId);
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);   // string-table text with two arguments
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);          // string-table text, "{0}" arguments
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* sep);   // split
Unk_KtWorld* FUN_1403ed2d0();
class Unk_KtGameOption { public: unsigned char* FUN_140a58500(); };   // CGameOption: &m_gamepad (its first byte: use the pad)
Unk_KtGameOption* FUN_1409a8b10();
CInputKeyHandler* FUN_14025e7c0();
class Unk_KtNotices { public: void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify); };
Unk_KtNotices* FUN_140939a10();
int SendKeyTableMode8(int nPage);                               // send the quick slot page
class Unk_KtScene                                           // the scene sound/cinematic manager (uiguideeventarrow.cpp)
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
};
Unk_KtScene* FUN_140a94350();
class Unk_KtSkill : public CPtred { public: bool FUN_1407e9d30(); };   // SkillData
class Unk_KtSkillTable { public: MS2Ptr<Unk_KtSkill> FUN_1407ee1d0(int nSkillId); };
Unk_KtSkillTable* FUN_1401958b0();
class Unk_KtQuestList { public: int FUN_140745590(int nQuestId); };   // completed
class Unk_KtQuestMgr                                        // the quest client manager
{
public:
    virtual void vfunc_0();
    void* m_p08;
    Unk_KtQuestList m_list;                                 // +0x10
};
Unk_KtQuestMgr* FUN_140764020();
class Unk_KtSceneMgr                                        // the scene sound/UI scene controller
{
public:
    UISceneEntity* FUN_1422b9e80();                         // the current UI scene
    void FUN_1422b9fd0(int nSceneId);                       // toggle a sub scene
};
Unk_KtSceneMgr* FUN_1408e57f0();
class Unk_KtPopup { public: void FUN_14193bbe0(); void FUN_14193bdf0(); };   // the 0x4e28 popup menu
Unk_KtPopup* FUN_140938b90(int nUiId);
class Unk_KtRuleFlags { public: int FUN_1402c4c90(int nRule); };
class Unk_KtRules { public: unsigned char m_pad[8]; Unk_KtRuleFlags m_flags; };
Unk_KtRules* FUN_14025e7b0();
CUIService* FUN_1403ed2b0();
CStringW FUN_140298ea0(CStringW strKey);                    // string table text (second table)
void FUN_140d73aa0(CStringW strMsg, int nType, int nTarget, CStringW strTag);   // message box
class Unk_ItemEquipData : public CItemData { };             // CItem::FUN_140527840's record (item.cpp owns the real one)
class Unk_KtInventory                                       // the player's inventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid);          // the item of the uid
    MS2Ptr<CItem> FUN_140a5e2e0(int nItemId);               // an item of the id
    void FUN_140a60880(int nTab, ATL::CAtlArray<MS2Ptr<CItem> >& arrOut);   // the items of one inventory tab
};
int UseItem(MS2Ptr<CItem> spItem, int nMode);              // 0x140d1bd60
int FUN_140dffeb0(ItemFunctionArgs* pArgs);                 // the ugc event item command
class Unk_KtCamera { public: int FUN_140af7e30(); };       // the camera manager: its mode
Unk_KtCamera* FUN_1409478c0();
extern Unk_KtInventory DAT_143ab2a90;                       // the player's inventory
void FUN_14092f690(int nSkillId, int nItemId, __int64 nItemUid, int nPage, int nSlot);   // send the quick slot change

// The game TinyXML element (ctor 0x14086f2f0, 0x90 bytes; the document owns and deletes it).
class TiXmlElement
{
public:
    TiXmlElement(const char* szName);
private:
    void* m_pad[0x90 / sizeof(void*)];
};

// The game TinyXML declaration node (ctor 0x1408704d0, 0x68 bytes; the document owns and deletes it).
class TiXmlDeclaration
{
public:
    TiXmlDeclaration(const char* pszVersion, const char* pszEncoding, const char* pszStandalone);
    ~TiXmlDeclaration();
private:
    void* m_pad[0x68 / sizeof(void*)];
};
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* pszPath);   // SaveFile
void FUN_14086e000(TiXmlDocument* pDoc, const TiXmlDeclaration& decl);   // InsertEndChild (a copy)
void FUN_140873ce0(TiXmlElement* pElem, const char* pszName, int nValue);         // SetAttribute (int)
void FUN_140873f20(TiXmlElement* pElem, const char* pszName, const size_t& nValue);   // SetAttribute (size_t)
CString FUN_140540050(const char* pszFormat, const CString& strArg);   // StringFormat<CString>
CString FUN_1412755f0();                                    // the user setting directory
CString FUN_140cc2a00(const CString& strRoot, const CString& strFile);   // path join

// A key code as a custom-formatted fmt argument (as in gameoptioninputdefault.cpp / guess\usercommandcli.cpp).
enum Unk_CommandKeyCode : int {};
template <> inline void fmt::format_arg(BasicFormatter<wchar_t>& f, const wchar_t*& format_str, const Unk_CommandKeyCode& value)
{
    internal::Arg arg;
    internal::Value& arg_value = arg;
    if (std::is_enum<Unk_CommandKeyCode>::value)
    {
        arg.int_value = value;
        arg.type = internal::Arg::INT;
    }
    else
    {
        std::basic_ostringstream<wchar_t> os;
        os << value;
        std::basic_string<wchar_t> str = os.str();
        arg_value = internal::MakeValue<BasicFormatter<wchar_t> >(str);
        arg.type = internal::Arg::STRING;
    }
    format_str = f.format(format_str, arg);
}

template <class T> inline int Unk_BreakFind(const ATL::CAtlArray<T>& values, const T& value)
{
    for (int i = 0; i < (int)values.GetCount(); ++i)
        if (values.GetAt(i) == value)
            return i;
    return -1;
}

// @0x1414286a0
CKeyTable::stKeyData::stKeyData()
    : m_strName(L""), m_nType(0), m_nCode(0), m_nPriority(0), m_nSlot(0)
{
}

// @0x141428730
CKeyTable::stKeyData::stKeyData(const CStringW& strName)
    : m_strName(strName), m_nType(0), m_nCode(0), m_nPriority(0), m_nSlot(0)
{
}

// @0x1414287c0
int CKeyTable::stKeyData::FUN_1414287c0(int nType, __int64 nCode, int nSlot, int nPriority)
{
    if (m_nType != nType)
        return 0;
    if (m_nCode != nCode)
        return 0;
    if (m_nSlot != nSlot)
        return 0;
    if (m_nPriority != nPriority)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1414287C0, CKeyTable::stKeyData, FUN_1414287c0, 99, 0x0097B8F9);

// @0x141428830
CKeyTable::CKeyTable()
    : m_nLoaded(0), m_bDirty(0), m_nMode(1), m_nLocked(0)
{
    FUN_1414307a0();
    FUN_14142a910();
    LoadKeySettingTable();
}

// @0x141428a70
CKeyTable::~CKeyTable()
{
}

// @0x141428bb0
void CKeyTable::OnKeyTable(CInPacket& packet)
{
    int nMode = packet.vfunc_o8_1();
    if (nMode == 0)
    {
        int nDefault = packet.vfunc_o8_1();
        FUN_14142a800();
        if (nDefault == 1)
        {
            FUN_1414297e0("./Data/Xml/Table/default/DefaultKey.xml", 0);
            if (FUN_140166410()->FUN_14036d570(0xb5) == true)
            {
                if (FUN_140a58540()->FUN_140d8ee40() == 2)
                    FUN_141429e60("./Data/Xml/Table/default/DefaultPSKey.xml");
                else
                    FUN_141429e60("./Data/Xml/Table/default/DefaultXboxKey.xml");
            }
        }
        else
        {
            int nCount = packet.vfunc_o8_3();
            if (nCount == 0)
            {
                FUN_1414297e0("./Data/Xml/Table/default/DefaultKey.xml", 0);
                if (FUN_140166410()->FUN_14036d570(0xb5) == true)
                {
                    if (FUN_140a58540()->FUN_140d8ee40() == 2)
                        FUN_141429e60("./Data/Xml/Table/default/DefaultPSKey.xml");
                    else
                        FUN_141429e60("./Data/Xml/Table/default/DefaultXboxKey.xml");
                }
            }
            else
            {
                for (int i = 0; i < nCount; i++)
                {
                    int nKey = packet.vfunc_o8_3();
                    int nType = packet.vfunc_o8_3();
                    __int64 nCode = packet.vfunc_o8_4();
                    int nSlot = packet.vfunc_o8_3();
                    int nPriority = packet.vfunc_o8_1();
                    FUN_141431c80(nKey, nType, nCode, nSlot, nPriority, 0);
                    if (nCode != 0)
                        FUN_141432360((int)nCode);
                }
            }
            int nPage = (unsigned short)packet.vfunc_o8_2();
            m_quickSlots.RemoveAll();
            int nPages = (unsigned short)packet.vfunc_o8_2();
            m_quickSlots.SetCount(nPages, -1);
            for (int i = 0; i < nPages; i++)
            {
                int nSlots = packet.vfunc_o8_3();
                for (int j = 0; j < nSlots; j++)
                {
                    int nSlot = packet.vfunc_o8_3();
                    int nSkillId = packet.vfunc_o8_3();
                    int nItemId = packet.vfunc_o8_3();
                    __int64 nItemUid = packet.vfunc_o8_4();
                    FUN_1414323f0(i, nSlot, nSkillId, nItemId, nItemUid);
                }
            }
            FUN_141431ae0(nPage, 0);
            FUN_1414321f0();
            FUN_14142a510();
        }
        m_nLoaded = 1;
    }
    else if (nMode == 7)
    {
        if (GetLocked())
            return;
        int nPage = (unsigned short)packet.vfunc_o8_2();
        m_quickSlots.RemoveAll();
        int nPages = (unsigned short)packet.vfunc_o8_2();
        m_quickSlots.SetCount(nPages, -1);
        for (int i = 0; i < nPages; i++)
        {
            int nSlots = packet.vfunc_o8_3();
            for (int j = 0; j < nSlots; j++)
            {
                int nSlot = packet.vfunc_o8_3();
                int nSkillId = packet.vfunc_o8_3();
                int nItemId = packet.vfunc_o8_3();
                __int64 nItemUid = packet.vfunc_o8_4();
                FUN_1414323f0(i, nSlot, nSkillId, nItemId, nItemUid);
            }
        }
        FUN_141431ae0(nPage, 0);
    }
}

// @0x1414294e0
void CKeyTable::SendKeyTableMode1(int nKey)
{
    if (m_nLocked != 0)
        return;
    MS2Ptr<stKeyData> spKey = FUN_14142c890(nKey);
    if (spKey.get() != 0)
    {
        COutPacket packet(0x3a, 0);
        packet.Encode1(1);
        packet.Encode4(1);
        packet.Encode4(nKey);
        packet.Encode4(spKey->m_nType);
        packet.Encode8(spKey->m_nCode);
        packet.Encode4(spKey->m_nSlot);
        packet.Encode1((unsigned char)spKey->m_nPriority);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x1414294E0, CKeyTable, SendKeyTableMode1, 281, 0xE9AD9B88);

// @0x141429600
void CKeyTable::FUN_141429600()
{
    if (FUN_140aa6d30()->FUN_1417e2610() != 0x620000c)
        return;
    if (m_bDirty == 0)
        return;
    if (m_nLocked != 0)
        return;
    COutPacket packet(0x3a, 0);
    packet.Encode1(2);
    packet.Encode4((int)m_keys.GetCount());
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        if (spKey.get() != 0)
        {
            int nKey = m_keys.GetKeyAt(pos);
            packet.Encode4(nKey);
            packet.Encode4(spKey->m_nType);
            packet.Encode8(spKey->m_nCode);
            packet.Encode4(spKey->m_nSlot);
            packet.Encode1((unsigned char)spKey->m_nPriority);
        }
    }
    FUN_140710590(packet);
    m_bDirty = 0;
}
MS2_REPLACE_METHOD(0x141429600, CKeyTable, FUN_141429600, 467, 0x64A12F3D);

// @0x1414297e0
int CKeyTable::FUN_1414297e0(const CString& strPath, int n)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    Unk_140165cf0* pConfig = pRoot->FUN_140165cf0("KeyConfig");
    if (pConfig == 0)
    {
        pConfig = reinterpret_cast<Unk_140165cf0*>(new TiXmlElement("KeyConfig"));
        FUN_14086e090(pRoot, reinterpret_cast<TiXmlElement*>(pConfig));
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pConfig, "key", "keyCode", &nodes);
    std::map<int, Unk_140165cf0*> byKey;
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        unsigned nKeyCode = 0;
        FUN_14086f500(pNode, "keyCode", &nKeyCode);
        byKey[nKeyCode] = pNode;
    }
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        int nKey = m_keys.GetKeyAt(pos);
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        if (spKey.IsNull())
            continue;
        if (FUN_141431a90(nKey) != 0)
            continue;
        {
            Unk_140165cf0* pNode = 0;
            std::map<int, Unk_140165cf0*>::iterator it = byKey.find(nKey);
            if (it != byKey.end())
                pNode = it->second;
            if (pNode == 0)
            {
                pNode = reinterpret_cast<Unk_140165cf0*>(new TiXmlElement("key"));
                FUN_14086f8d0(pNode, "code", "");
                FUN_14086f8d0(pNode, "type", "");
                FUN_14086f920(pNode, "keyCode", nKey);
                FUN_14086f8d0(pNode, "priority", "");
                byKey[nKey] = pNode;
            }
            if (FUN_14086f4b0(pNode, "keyCode") != 0)
            {
                int nType = atoi(FUN_14028d1f0(FUN_14086f4b0(pNode, "type")));
                __int64 nCode = _atoi64(FUN_14028d1f0(FUN_14086f4b0(pNode, "code")));
                int nPriority = atoi(FUN_14028d1f0(FUN_14086f4b0(pNode, "priority")));
                spKey->m_nType = nType;
                spKey->m_nCode = nCode;
                spKey->m_nPriority = nPriority;
                FUN_141432360((int)spKey->m_nCode);
            }
        }
    }
    m_bDirty = 1;
    FUN_141429600();
    FUN_1414321f0();
    return 1;
}
MS2_REPLACE_METHOD(0x1414297E0, CKeyTable, FUN_1414297e0, 1645, 0x48DBACBE);

// @0x141429e60
int CKeyTable::FUN_141429e60(const CString& strPath)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    Unk_140165cf0* pConfig = pRoot->FUN_140165cf0("KeyConfig");
    if (pConfig == 0)
    {
        pConfig = reinterpret_cast<Unk_140165cf0*>(new TiXmlElement("KeyConfig"));
        FUN_14086e090(pRoot, reinterpret_cast<TiXmlElement*>(pConfig));
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pConfig, "key", "keyCode", &nodes);
    std::map<int, Unk_140165cf0*> byKey;
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        unsigned nKeyCode = 0;
        FUN_14086f500(pNode, "keyCode", &nKeyCode);
        byKey[nKeyCode] = pNode;
    }
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        int nKey = m_keys.GetKeyAt(pos);
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        if (spKey.IsNull())
            continue;
        if (FUN_141431a90(nKey) == 0)
            continue;
        {
            Unk_140165cf0* pNode = 0;
            std::map<int, Unk_140165cf0*>::iterator it = byKey.find(nKey);
            if (it != byKey.end())
                pNode = it->second;
            if (pNode == 0)
            {
                pNode = reinterpret_cast<Unk_140165cf0*>(new TiXmlElement("key"));
                FUN_14086f8d0(pNode, "code", "");
                FUN_14086f8d0(pNode, "type", "");
                FUN_14086f920(pNode, "keyCode", nKey);
                FUN_14086f8d0(pNode, "priority", "");
                byKey[nKey] = pNode;
            }
            if (pNode != 0 && FUN_14086f4b0(pNode, "keyCode") != 0)
            {
                spKey->m_nType = atoi(FUN_14028d1f0(FUN_14086f4b0(pNode, "type")));
                spKey->m_nCode = _atoi64(FUN_14028d1f0(FUN_14086f4b0(pNode, "code")));
                spKey->m_nPriority = atoi(FUN_14028d1f0(FUN_14086f4b0(pNode, "priority")));
                FUN_141432360((int)spKey->m_nCode);
            }
        }
    }
    m_bDirty = 1;
    FUN_141429600();
    FUN_1414321f0();
    return 1;
}
MS2_REPLACE_METHOD(0x141429E60, CKeyTable, FUN_141429e60, 1700, 0xFF8CA100);

// @0x14142a510
void CKeyTable::FUN_14142a510()
{
    if (m_keys.GetCount() == 0)
        return;
    m_keysBackup.RemoveAll();
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        int nKey = m_keys.GetKeyAt(pos);
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        MS2Ptr<stKeyData> spCopy(new stKeyData(*spKey));
        m_keysBackup.SetAt(nKey, spCopy);
    }
}

// @0x14142a680
void CKeyTable::FUN_14142a680()
{
    if (m_keysBackup.GetCount() == 0)
        return;
    m_keys.RemoveAll();
    for (POSITION pos = m_keysBackup.GetHeadPosition(); pos != 0; m_keysBackup.GetNext(pos))
    {
        int nKey = m_keysBackup.GetKeyAt(pos);
        MS2Ptr<stKeyData> spKey = m_keysBackup.GetValueAt(pos);
        MS2Ptr<stKeyData> spCopy(new stKeyData(*spKey));
        m_keys.SetAt(nKey, spCopy);
    }
    FUN_1414321f0();
}

// @0x14142a800
void CKeyTable::FUN_14142a800()
{
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData>& spKey = m_keys.GetValueAt(pos);
        spKey->m_nCode = 0;
        spKey->m_nSlot = 0;
        spKey->m_nType = 0;
    }
    FUN_1414321f0();
}
MS2_REPLACE_METHOD(0x14142A800, CKeyTable, FUN_14142a800, 159, 0xE92B4FDD);

// @0x14142a8b0
void CKeyTable::FUN_14142a8b0(__int64 nAction)
{
    CString str;
    str.Format("%I64u", nAction);
    FUN_1422c9380(str);
}
MS2_REPLACE_METHOD(0x14142A8B0, CKeyTable, FUN_14142a8b0, 85, 0x3BC4C506);

// @0x14142a910
void CKeyTable::FUN_14142a910()
{
    m_keys.RemoveAll();
    for (int nKey = 1; nKey < 0xd0; nKey++)
    {
        CStringW strName = GetStringTable()->FUN_1418125b0(nKey);
        if (!strName.IsEmpty())
            m_keys.SetAt((Unk_MyPCKeyId)nKey, new stKeyData(GetStringTable()->FUN_1418125b0(nKey)));
    }
    int nCount = 0;
    for (int nFirst = 0x96; nFirst <= 0x99; nFirst++)
    {
        for (int nSecond = 0x92; nSecond < 0xa2; nSecond++)
        {
            if (nSecond >= 0x96 && nSecond <= 0x99)
                continue;
            unsigned nCombo;
            FUN_141430e70(&nCombo, nFirst, nSecond, 0xf0);
            CStringW strName = CreateCombineKeyString(nFirst, nSecond);
            m_keys.SetAt(nCombo, new stKeyData(strName));
            nCount++;
        }
        for (int nSecond = 0xa3; nSecond < 0xb3; nSecond++)
        {
            unsigned nCombo;
            FUN_141430e70(&nCombo, nFirst, nSecond, 0xf1);
            CStringW strName = CreateCombineKeyString(nFirst, nSecond);
            m_keys.SetAt(nCombo, new stKeyData(strName));
            nCount++;
        }
    }
    m_quickSlotActions.Add(0x7a121);
    m_quickSlotActions.Add(0x7a122);
    m_quickSlotActions.Add(0x7a123);
    m_quickSlotActions.Add(0x7a124);
    m_quickSlotActions.Add(0x7a125);
    m_quickSlotActions.Add(0x7a126);
    m_quickSlotActions.Add(0x7a127);
    m_quickSlotActions.Add(0x7a128);
    m_quickSlotActions.Add(0x7a129);
    m_quickSlotActions.Add(0x7a12a);
    m_quickSlotActions.Add(0x7a12b);
    m_quickSlotActions.Add(0x7a12c);
    m_quickSlotActions.Add(0x7a12d);
    m_quickSlotActions.Add(0x7a12e);
    m_quickSlotActions.Add(0x7a12f);
    m_quickSlotActions.Add(0x7a130);
    m_quickSlotActions.Add(0x7a131);
    m_quickSlotActions.Add(0x7a132);
    m_quickSlotActions.Add(0x7a133);
    m_quickSlotActions.Add(0x7a134);
    m_quickSlotActions.Add(0x7a135);
    m_quickSlotActions.Add(0x7a136);
    m_quickSlotActions.Add(0x7a137);
    m_quickSlotActions.Add(0x7a138);
    m_quickSlotActions.Add(0x7a139);
    m_pairKeys.RemoveAll();
    m_pairKeys.SetAt(0x82, 0x83);
    m_pairKeys.SetAt(0x83, 0x82);
    m_pairKeys.SetAt(0x38, 0x76);
    m_pairKeys.SetAt(0x76, 0x38);
    m_pairKeys.SetAt(0x2a, 0x36);
    m_pairKeys.SetAt(0x36, 0x2a);
    m_pairKeys.SetAt(0x1d, 0x6b);
    m_pairKeys.SetAt(0x6b, 0x1d);
}

// @0x14142b1c0
int CKeyTable::FUN_14142b1c0(int nKey, int nType, __int64 nAction, int nSlot, int nPriority, int nOldKey)
{
    FUN_141430d30(nAction, nKey, nPriority, nOldKey);
    if (FUN_141431c80(nKey, nType, nAction, nSlot, nPriority, 1))
    {
        m_bDirty = 1;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142B1C0, CKeyTable, FUN_14142b1c0, 137, 0x8F634E0D);

// @0x14142b250
int CKeyTable::FUN_14142b250(int nKey, int nType, __int64 nAction, int nSlot, int nPriority)
{
    if (FUN_141431c80(nKey, nType, nAction, nSlot, nPriority, 1))
    {
        SendKeyTableMode1(nKey);
        int nPair;
        if (m_pairKeys.Lookup(nKey, nPair))
            SendKeyTableMode1(nPair);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142B250, CKeyTable, FUN_14142b250, 159, 0xD7F8BAAF);

// @0x14142b300
int CKeyTable::FUN_14142b300(int nKey)
{
    if (FUN_14142b340(nKey))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14142B300, CKeyTable, FUN_14142b300, 45, 0x00F4DB80);

// @0x14142b340
int CKeyTable::FUN_14142b340(int nAction)
{
    if (!FUN_141431fc0())
        return 0;
    if (!FUN_141432010(nAction))
        return 0;
    switch (nAction)
    {
    case 400001:
        FUN_1403ed2b0()->ToggleDialog(eUI_4e2d);
        break;
    case 400002:
        FUN_1403ed2b0()->ToggleDialog(eUI_2711);
        break;
    case 400005:
        FUN_1403ed2b0()->ToggleDialog(eUI_4f2d);
        break;
    case 400006:
        FUN_1403ed2b0()->ToggleDialog(eUI_4e42);
        break;
    case 400007:
        FUN_1403ed2b0()->ToggleDialog(eUI_4e3e);
        break;
    case 400009:
        FUN_1403ed2b0()->ToggleDialog(eUI_4e73);
        break;
    case 400010:
    {
        Unk_KtPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0 && !pPlayer->FUN_14166ce30())
        {
            UISceneEntity* pScene = FUN_1408e57f0()->FUN_1422b9e80();
            if (pScene != 0)
            {
                UISceneGameBeautyShop* pShop = dynamic_cast<UISceneGameBeautyShop*>(pScene->FUN_1422e7a70(0x620001f));
                if (pShop != 0)
                    pShop->FUN_141ac8e70(1);
            }
            FUN_1408e57f0()->FUN_1422b9fd0(0x620001f);
        }
        break;
    }
    case 400011:
    {
        Unk_KtPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0 && !pPlayer->FUN_14166ce30())
            FUN_1408e57f0()->FUN_1422b9fd0(0x620001f);
        break;
    }
    case 300014:
    {
        COutPacket packet(0x2f, 0);
        packet.Encode1(4);
        FUN_140710590(packet);
        break;
    }
    case 400012:
        FUN_1403ed2b0()->ToggleDialog(eUI_4e4d);
        break;
    case 400008:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4e5b);
        break;
    case 400013:
        FUN_1403ed2b0()->ToggleDialog(eUI_4e49);
        break;
    case 400014:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4e4f);
        break;
    case 400015:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4e6a);
        break;
    case 400016:
        FUN_1403ed2b0()->ToggleDialog(eUI_4ec1);
        break;
    case 400017:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4ebc);
        break;
    case 400018:
        if (FUN_140166410()->FUN_14036d570(0xf9))
            FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f84);
        else
            FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f1c);
        break;
    case 400019:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4ec9);
        break;
    case 400020:
        if (FUN_140166410()->FUN_14036d570(0x4e))
            FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f04);
        else
            FUN_140d73aa0(FUN_140298ea0(L"s_pvp_arena_close_test_season_msg"), 0, 0, L"");
        break;
    case 400021:
        FUN_1403ed2b0()->ToggleDialog(eUI_4e97);
        break;
    case 400022:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4efa);
        break;
    case 400036:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f53);
        break;
    case 400037:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4ebd);
        break;
    case 400038:
        if (FUN_140166410()->FUN_14036d570(0xd3))
        {
            if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x5b))
            {
                FUN_141275260(0x2f7, 1, 1);
                break;
            }
            FUN_1403ed2b0()->ToggleDialog(eUI_4f6d);
        }
        break;
    case 800004:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f63);
        break;
    case 400023:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4efd);
        break;
    case 400024:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4efe);
        break;
    case 400025:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f0c);
        break;
    case 400026:
        if (FUN_140166410()->FUN_14036d570(0x4a))
            FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f1b);
        break;
    case 400027:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4eda);
        break;
    case 400028:
    {
        Unk_KtPopup* pPopup = FUN_140938b90(0x4e28);
        if (pPopup != 0)
            pPopup->FUN_14193bbe0();
        break;
    }
    case 400029:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f1e);
        break;
    case 400030:
        if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4f18))
            FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4f18);
        else
        {
            Unk_KtPopup* pPopup = FUN_140938b90(0x4e28);
            if (pPopup != 0)
                pPopup->FUN_14193bdf0();
        }
        break;
    case 400031:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4ef6);
        break;
    case 400032:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f0b);
        break;
    case 400033:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f24);
        break;
    case 400034:
        FUN_1403ed2b0()->ToggleDialog((eUIClassID)0x4f25);
        break;
    case 400035:
        if (FUN_140166410()->FUN_14036d570(0x8c))
            FUN_1403ed2b0()->ToggleDialog(eUI_4f38);
        break;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14142B340, CKeyTable, FUN_14142b340, 1757, 0x7F357C0C);

// @0x14142bad0
void CKeyTable::SetMode(int nMode)
{
    m_nMode = nMode;
}
MS2_REPLACE_METHOD(0x14142BAD0, CKeyTable, SetMode, 22, 0x566B64E3);

// @0x14142baf0
int CKeyTable::GetMode()
{
    return m_nMode;
}
MS2_REPLACE_METHOD(0x14142BAF0, CKeyTable, GetMode, 14, 0xC2D0886F);

// @0x14142bb10
void CKeyTable::FUN_14142bb10()
{
    if (!FUN_141431fc0())
        return;
    Unk_KtPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (pPlayer->FUN_1416595d0())
        return;
    int nCameraMode = FUN_1409478c0()->FUN_140af7e30();
    switch (nCameraMode)
    {
    case 6:
    case 7:
        return;
    }
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return;
    for (POSITION pos = pPage->GetStartPosition(); pos != 0; pPage->GetNext(pos))
    {
        unsigned nSlot = pPage->GetKeyAt(pos);
        Unk_MyPCKeyId nPrimary = (Unk_MyPCKeyId)FUN_14142cb40(nSlot, 0);
        Unk_MyPCKeyId nSecondary = (Unk_MyPCKeyId)FUN_14142cb40(nSlot, 1);
        Unk_MyPCKeyId nThirdly = (Unk_MyPCKeyId)FUN_14142cb40(nSlot, 2);
        ATL::CAtlArray<Unk_MyPCKeyId> aKeys;
        if (nPrimary != 0)
        {
            aKeys.Add(nPrimary);
            Unk_MyPCKeyId nPair = (Unk_MyPCKeyId)0;
            if (FUN_14142c830(nPrimary, (int&)nPair))
                aKeys.Add(nPair);
        }
        if (nSecondary != 0)
        {
            aKeys.Add(nSecondary);
            Unk_MyPCKeyId nPair = (Unk_MyPCKeyId)0;
            if (FUN_14142c830(nSecondary, (int&)nPair))
                aKeys.Add(nPair);
        }
        if (nThirdly != 0)
        {
            aKeys.Add(nThirdly);
            Unk_MyPCKeyId nPair = (Unk_MyPCKeyId)0;
            if (FUN_14142c830(nThirdly, (int&)nPair))
                aKeys.Add(nPair);
        }
        for (unsigned i = 0; i < aKeys.GetCount(); i++)
        {
            int nKey = aKeys[i];
            if (FUN_14025e7c0()->FUN_14116d9c0(nKey, false, 0))
            {
                if (FUN_14142e6f0(nKey))
                    continue;
                Unk_SsQuickEntry entry = pPage->GetValueAt(pos);
                if (entry.m_nItemId == 0)
                    continue;
                MS2Ptr<CItemData> spData = FUN_14053f870(entry.m_nItemId);
                if (!spData)
                    continue;
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(entry.m_nItemUid);
                if (spItem.get())
                {
                    if (spData->FUN_14053cd90())
                        UseItem(spItem, 0);
                }
                else
                {
                    MS2Ptr<CItem> spAny = DAT_143ab2a90.FUN_140a5e2e0(entry.m_nItemId);
                    if (spAny.get())
                    {
                        if (spData->FUN_14053cd90())
                            UseItem(spAny, 0);
                    }
                    else if (spData->FUN_14053c6f0() == 0xd9)
                    {
                        ItemFunction* pFunc = &spData->function;
                        if (pFunc->parameter.FUN_1408d21c0(0, L"") == L"ugcevent")
                            FUN_140dffeb0(&pFunc->parameter);
                    }
                    else
                    {
                        FUN_141275260(0xe6, 1, 1);
                        continue;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14142BB10, CKeyTable, FUN_14142bb10, 1449, 0x8EF2B619);

// @0x14142c0c0
int CKeyTable::FUN_14142c0c0(int nSkillId)
{
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        int nKey = m_keys.GetKeyAt(pos);
        if (!FUN_14142cf60(spKey))
            continue;
        if (FUN_14142cf10(spKey->m_nCode))
        {
            int nIndex = FUN_14142e090(nSkillId, 0);
            if (nIndex < 0)
                continue;
        }
        else
        {
            if (spKey->m_nSlot != nSkillId)
                continue;
        }
        if (FUN_140a58540()->FUN_140d8ac50(nKey, 0))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142C0C0, CKeyTable, FUN_14142c0c0, 415, 0x7B9191EF);

// @0x14142c270
int CKeyTable::FUN_14142c270(int nAction)
{
    __int64 nCode = nAction;
    POSITION pos = m_actionKeys.FindFirstWithKey(nCode);
    while (pos != 0)
    {
        int nKey = m_actionKeys.GetNextValueWithKey(pos, nCode);
        if (FUN_140a58540()->FUN_140d8ac50(nKey, 0))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142C270, CKeyTable, FUN_14142c270, 138, 0x83F4819B);

// @0x14142c300
int CKeyTable::FUN_14142c300(int nSkillId)
{
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        int nKey = m_keys.GetKeyAt(pos);
        if (!FUN_14142cf60(spKey))
            continue;
        if (FUN_14142cf10(spKey->m_nCode))
        {
            int nIndex = FUN_14142e090(nSkillId, 0);
            if (nIndex < 0)
                continue;
        }
        else
        {
            if (spKey->m_nSlot != nSkillId)
                continue;
        }
        if (FUN_140a58540()->FUN_140d8ad60(nKey))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142C300, CKeyTable, FUN_14142c300, 412, 0x9817887F);

// @0x14142c4b0
int CKeyTable::FUN_14142c4b0(int nAction)
{
    __int64 nCode = nAction;
    POSITION pos = m_actionKeys.FindFirstWithKey(nCode);
    while (pos != 0)
    {
        int nKey = m_actionKeys.GetNextValueWithKey(pos, nCode);
        if (FUN_140a58540()->FUN_140d8ad60(nKey))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142C4B0, CKeyTable, FUN_14142c4b0, 135, 0xBC98637E);

// @0x14142c540
int CKeyTable::FUN_14142c540(int nAction)
{
    __int64 nCode = nAction;
    POSITION pos = m_actionKeys.FindFirstWithKey(nCode);
    while (pos != 0)
    {
        int nKey = m_actionKeys.GetNextValueWithKey(pos, nCode);
        if (FUN_140a58540()->FUN_140d8af70(nKey))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142C540, CKeyTable, FUN_14142c540, 135, 0x7AAC129D);

// @0x14142c5d0
void CKeyTable::FUN_14142c5d0(ATL::CAtlArray<Unk_MyPCKeyId>& aOut)
{
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData>& spKey = m_keys.GetValueAt(pos);
        Unk_MyPCKeyId nKey = (Unk_MyPCKeyId)m_keys.GetKeyAt(pos);
        if (FUN_14142cf60(spKey) == 0)
            continue;
        if (spKey->m_nType == 0)
            continue;
        aOut.Add(nKey);
    }
}
MS2_REPLACE_METHOD(0x14142C5D0, CKeyTable, FUN_14142c5d0, 227, 0xFF2FE0A8);

// @0x14142c6c0
void CKeyTable::FUN_14142c6c0(ATL::CAtlArray<Unk_MyPCKeyId>& aOut, int nSkillId)
{
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        Unk_MyPCKeyId nKey = (Unk_MyPCKeyId)m_keys.GetKeyAt(pos);
        if (FUN_14142cf60(spKey) == 0)
            continue;
        if (spKey->m_nType == 0)
            continue;
        if (FUN_14142d9b0(spKey.get()) != nSkillId)
            continue;
        aOut.Add(nKey);
    }
}
MS2_REPLACE_METHOD(0x14142C6C0, CKeyTable, FUN_14142c6c0, 349, 0x6D66EC02);

// @0x14142c830
int CKeyTable::FUN_14142c830(int nKey, int& nPair)
{
    return m_pairKeys.Lookup(nKey, nPair) != 0;
}
MS2_REPLACE_METHOD(0x14142C830, CKeyTable, FUN_14142c830, 81, 0x7206F89F);

// @0x14142c890
MS2Ptr<CKeyTable::stKeyData> CKeyTable::FUN_14142c890(int nKey)
{
    MS2Ptr<stKeyData> spKey(0);
    if (m_keys.Lookup(nKey, spKey))
        return spKey;
    return MS2Ptr<stKeyData>(0);
}
MS2_REPLACE_METHOD(0x14142C890, CKeyTable, FUN_14142c890, 169, 0x3D0D87EE);

// @0x14142c940
int CKeyTable::FUN_14142c940(__int64 nAction, int nPriority)
{
    if (nAction == 0)
        return 0;
    POSITION pos = m_actionKeys.FindFirstWithKey(nAction);
    while (pos != 0)
    {
        int nKey = m_actionKeys.GetNextValueWithKey(pos, nAction);
        MS2Ptr<stKeyData> spKey(0);
        if (m_keys.Lookup(nKey, spKey))
        {
            if (spKey->m_nPriority != nPriority)
                continue;
            return nKey;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142C940, CKeyTable, FUN_14142c940, 243, 0xBA488D8E);

// @0x14142ca40
int CKeyTable::FUN_14142ca40(int nId, int nPriority)
{
    if (nId == 0)
        return 0;
    POSITION pos = m_d8.FindFirstWithKey(nId);
    while (pos != 0)
    {
        int nKey = m_d8.GetNextValueWithKey(pos, nId);
        MS2Ptr<stKeyData> spKey(0);
        if (m_keys.Lookup(nKey, spKey))
        {
            if (spKey->m_nPriority != nPriority)
                continue;
            return nKey;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142CA40, CKeyTable, FUN_14142ca40, 240, 0xEF244DAB);

// @0x14142cb40
int CKeyTable::FUN_14142cb40(unsigned nIndex, int nPriority)
{
    if (m_quickSlotActions.GetCount() <= nIndex)
        return 0;
    return FUN_14142c940(m_quickSlotActions[(int)nIndex], nPriority);
}
MS2_REPLACE_METHOD(0x14142CB40, CKeyTable, FUN_14142cb40, 98, 0x88201520);

// @0x14142cbb0
size_t CKeyTable::FUN_14142cbb0()
{
    return m_quickSlotActions.GetCount();
}
MS2_REPLACE_METHOD(0x14142CBB0, CKeyTable, FUN_14142cbb0, 33, 0x2B1D3988);

// @0x14142cbe0
__int64 CKeyTable::FUN_14142cbe0(unsigned nIndex)
{
    if (m_quickSlotActions.GetCount() <= nIndex)
        return 0;
    return m_quickSlotActions[(int)nIndex];
}
MS2_REPLACE_METHOD(0x14142CBE0, CKeyTable, FUN_14142cbe0, 78, 0xDE3D617A);

// @0x14142cc40
int CKeyTable::FUN_14142cc40(int nKey)
{
    if (nKey == 1)
        return 0;
    if (nKey == 0x83)
        return 0;
    if (nKey == 0x82)
        return 0;
    if (nKey == 0x1c)
        return 0;
    if (nKey >= 0xa3 && nKey <= 0xa6)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x14142CC40, CKeyTable, FUN_14142cc40, 89, 0x5FBDDE9B);

// @0x14142cca0
int CKeyTable::FUN_14142cca0(int nKey)
{
    MS2Ptr<stKeyData> spKey(0);
    if (!m_keys.Lookup(nKey, spKey))
        return 0;
    return FUN_14142cf60(spKey);
}
MS2_REPLACE_METHOD(0x14142CCA0, CKeyTable, FUN_14142cca0, 161, 0x15AABA96);

// @0x14142cd50
int CKeyTable::FUN_14142cd50(int nKey, int nAction)
{
    MS2Ptr<stKeyData> spKey(0);
    if (m_keys.Lookup(nKey, spKey))
    {
        if (spKey->m_nType == 0)
            return 0;
        if (spKey->m_nCode == nAction)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142CD50, CKeyTable, FUN_14142cd50, 186, 0xB49DAE0B);

// @0x14142ce10
int CKeyTable::FUN_14142ce10(int nKey)
{
    for (size_t i = 0; i < m_quickSlotActions.GetCount(); i++)
    {
        if (FUN_14142c940(m_quickSlotActions.GetAt(i), 0) == nKey)
            return 1;
        if (FUN_14142c940(m_quickSlotActions.GetAt(i), 1) == nKey)
            return 1;
        if (FUN_14142c940(m_quickSlotActions.GetAt(i), 2) == nKey)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142CE10, CKeyTable, FUN_14142ce10, 244, 0x0EED7FEC);

// @0x14142cf10
int CKeyTable::FUN_14142cf10(__int64 nAction)
{
    return Unk_BreakFind(m_quickSlotActions, nAction) != -1;
}
MS2_REPLACE_METHOD(0x14142CF10, CKeyTable, FUN_14142cf10, 70, 0xBDE6A588);

// @0x14142cf60
int CKeyTable::FUN_14142cf60(MS2Ptr<stKeyData> spKey)
{
    if (spKey == 0)
        return 0;
    if (spKey->m_nType == 0)
        return 0;
    if (spKey->m_nCode == 0)
        return 0;
    if (FUN_14142cf10(spKey->m_nCode))
    {
        int nSlot = FUN_14142e220(spKey->m_nCode);
        Unk_SsQuickEntry entry;
        if (!FUN_14142e030(nSlot, entry))
            return 0;
        if (entry.m_nSkillId == 0 && entry.m_nItemId == 0 && entry.m_nItemUid == 0)
            return 0;
    }
    else
    {
        if (spKey->m_nType == 1 && spKey->m_nSlot == 0)
            return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14142CF60, CKeyTable, FUN_14142cf60, 407, 0x9F237905);

// @0x14142d100
int CKeyTable::FUN_14142d100(int nKey)
{
    MS2Ptr<stKeyData> spKey(0);
    if (m_keys.Lookup(nKey, spKey))
        return spKey->m_nType;
    return 0;
}
MS2_REPLACE_METHOD(0x14142D100, CKeyTable, FUN_14142d100, 129, 0xB070A024);

// @0x14142d190
__int64 CKeyTable::FUN_14142d190(int nKey)
{
    MS2Ptr<stKeyData> spKey(0);
    if (m_keys.Lookup(nKey, spKey))
        return spKey->m_nCode;
    return 0;
}
MS2_REPLACE_METHOD(0x14142D190, CKeyTable, FUN_14142d190, 134, 0x17DAE7B5);

// @0x14142d220
CStringW CKeyTable::FUN_14142d220(int nKey)
{
    MS2Ptr<stKeyData> spKey(0);
    if (m_keys.Lookup(nKey, spKey))
    {
        if (FUN_140166410()->FUN_14036d570(0xb5) == true)
        {
            if (FUN_141431a90(nKey) == 0)
            {
                return spKey->m_strName;
            }
            else
            {
                CStringW strName = spKey->m_strName.MakeLower();
                CStringW strLayout = FUN_140a58540()->FUN_140d8c690();
                ATL::CAtlArray<CStringW> aParts;
                FUN_14025a680(strName, aParts, L",");
                if (aParts.GetCount() > 1)
                    return FUN_14028dfa0(L"s_gamepad_key_icon_combine", strLayout, aParts[0], strLayout, aParts[1]);
                else
                    return FUN_1408f71a0(L"s_gamepad_key_icon", strLayout, strName);
            }
        }
        else
        {
            return spKey->m_strName;
        }
    }
    return L"";
}
MS2_REPLACE_METHOD(0x14142D220, CKeyTable, FUN_14142d220, 801, 0x02B623A0);

// @0x14142d580
CStringW CKeyTable::FUN_14142d580(int nKey)
{
    if (nKey == 0x1d)
        return L"LCtrl";
    else if (nKey == 0x6b)
        return L"RCtrl";
    else if (nKey == 0x82)
        return L"LWindow";
    else if (nKey == 0x83)
        return L"RWindow";
    else if (nKey == 0x38)
        return L"LAlt";
    else if (nKey == 0x76)
        return L"RAlt";
    else if (nKey == 0x2a)
        return L"LShift";
    else if (nKey == 0x36)
        return L"RShift";
    return FUN_14142d220(nKey);
}
MS2_REPLACE_METHOD(0x14142D580, CKeyTable, FUN_14142d580, 433, 0xC3BED9B7);

// @0x14142d760
CStringW CKeyTable::FUN_14142d760(int nAction, int nPriority)
{
    __int64 nCode = nAction;
    int nKey = FUN_14142c940(nCode, nPriority);
    return FUN_14142d220(nKey);
}
MS2_REPLACE_METHOD(0x14142D760, CKeyTable, FUN_14142d760, 107, 0xA4DDC314);

// @0x14142d7e0
CStringW CKeyTable::FUN_14142d7e0(const int& nKey)
{
    unsigned __int64 nAction = FUN_1409331f0()->FUN_14142d190(nKey);
    if (FUN_14142ce10(nKey))
        return StringFormat(L"{0}[{1}]", GetStringTable()->FUN_1418125b0((int)nAction), FUN_1409331f0()->FUN_14142d220(nKey));
    else if (nAction >= 0xaae61 && nAction <= 0xaae63)
        return GetStringTable()->FUN_1418125b0((int)nAction);
    else if (nAction >= 0xdbba1 && nAction <= 0xdbbaa)
        return GetStringTable()->FUN_1418125b0((int)nAction);
    return GetStringTable()->FUN_1418125b0((int)nAction);
}
MS2_REPLACE_METHOD(0x14142D7E0, CKeyTable, FUN_14142d7e0, 442, 0x7180F4EA);

// @0x14142d9b0
int CKeyTable::FUN_14142d9b0(stKeyData* pKey)
{
    if (pKey == 0)
        return 0;
    if (FUN_14142cf10(pKey->m_nCode))
    {
        int nIndex = FUN_14142e220(pKey->m_nCode);
        if (nIndex < 0)
            return 0;
        Unk_SsQuickEntry entry;
        if (!FUN_14142e030(nIndex, entry))
            return 0;
        return entry.m_nSkillId;
    }
    else if (pKey->m_nType == 1)
    {
        if (FUN_1409331e0()->FUN_14138c900(8))
        {
            FUN_141275260(0x888, 1, 1);
            return 0;
        }
        return pKey->m_nSlot;
    }
    else if (pKey->m_nType == 2)
    {
        if (FUN_140347960((int)pKey->m_nCode))
            return (int)pKey->m_nCode;
        return 0;
    }
    return pKey->m_nSlot;
}
MS2_REPLACE_METHOD(0x14142D9B0, CKeyTable, FUN_14142d9b0, 264, 0xE98EBD47);

// @0x14142dad0
int CKeyTable::FUN_14142dad0(unsigned nKey)
{
    Unk_KtPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (FUN_14142cd50(nKey, 0x49401))
    {
        if (pPlayer->FUN_1416764d0())
            return 0;
        if (pPlayer->FUN_14166c930() == 0x1b || pPlayer->FUN_14166c930() == 0x1c)
            return 0x1312d01;
        else
            return pPlayer->FUN_14165c570();
    }
    else if (FUN_14142cd50(nKey, 0x493e2))
    {
        Unk_KtPlayer* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        Unk_KtHeldItem* pHeld;
        if (pMe != 0 && pMe->FUN_14165f150() && (pHeld = pMe->FUN_14165f100()) != 0)
            return pHeld->FUN_140527840()->FUN_14053dc90();
    }
    return FUN_14142d9b0(FUN_14142c890(nKey).get());
}
MS2_REPLACE_METHOD(0x14142DAD0, CKeyTable, FUN_14142dad0, 364, 0x70BB5782);

// @0x14142dc50
int CKeyTable::FUN_14142dc50(unsigned nSlot)
{
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return 0;
    Unk_SsQuickEntry entry;
    pPage->Lookup(nSlot, entry);
    return entry.m_nSkillId;
}
MS2_REPLACE_METHOD(0x14142DC50, CKeyTable, FUN_14142dc50, 89, 0x47A866FE);

// @0x14142dcb0
int CKeyTable::FUN_14142dcb0(int nKey, int& nIndex)
{
    for (size_t i = 0; i < m_quickSlotActions.GetCount(); i++)
    {
        int nPrimary = FUN_14142c940(m_quickSlotActions.GetAt(i), 0);
        if (nPrimary == nKey)
        {
            nIndex = (int)i;
            return 1;
        }
        else if (nPrimary != 0)
        {
            int nPair = 0;
            if (FUN_14142c830(nPrimary, nPair) != 0 && nPair == nKey)
            {
                nIndex = (int)i;
                return 1;
            }
        }
        int nSecondary = FUN_14142c940(m_quickSlotActions.GetAt(i), 1);
        if (nSecondary == nKey)
        {
            nIndex = (int)i;
            return 1;
        }
        else if (nSecondary != 0)
        {
            int nPair = 0;
            if (FUN_14142c830(nSecondary, nPair) != 0 && nPair == nKey)
            {
                nIndex = (int)i;
                return 1;
            }
        }
        int nThirdly = FUN_14142c940(m_quickSlotActions.GetAt(i), 2);
        if (nThirdly == nKey)
        {
            nIndex = (int)i;
            return 1;
        }
        else if (nThirdly != 0)
        {
            int nPair = 0;
            if (FUN_14142c830(nThirdly, nPair) != 0 && nPair == nKey)
            {
                nIndex = (int)i;
                return 1;
            }
        }
    }
    nIndex = -1;
    return 0;
}
MS2_REPLACE_METHOD(0x14142DCB0, CKeyTable, FUN_14142dcb0, 527, 0x8EA568DC);

// @0x14142ded0
__int64 CKeyTable::FUN_14142ded0(unsigned nKey)
{
    int nIndex = 0;
    Unk_KtMainPlayerInfo* pInfo;
    SkillSlot* pSlot;
    if (FUN_14142dcb0(nKey, nIndex) && (pInfo = FUN_140931900(0x4e5f)) != 0 && (pSlot = pInfo->FUN_1419f2930(nIndex)) != 0)
    {
        MS2Ptr<CItem> spItem = pSlot->vfunc_25();
        if (spItem.get())
            return spItem->FUN_140526a50();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142DED0, CKeyTable, FUN_14142ded0, 204, 0x6795B4C7);

// @0x14142dfb0
int CKeyTable::FUN_14142dfb0(unsigned nKey)
{
    int nIndex = 0;
    Unk_KtMainPlayerInfo* pInfo;
    SkillSlot* pSlot;
    if (FUN_14142dcb0(nKey, nIndex) && (pInfo = FUN_140931900(0x4e5f)) != 0 && (pSlot = pInfo->FUN_1419f2930(nIndex)) != 0)
        return pSlot->GetItemId();
    return 0;
}
MS2_REPLACE_METHOD(0x14142DFB0, CKeyTable, FUN_14142dfb0, 113, 0x6C96D5D5);

// @0x14142e030
bool CKeyTable::FUN_14142e030(unsigned nSlot, Unk_SsQuickEntry& entry)
{
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return false;
    return pPage->Lookup(nSlot, entry);
}
MS2_REPLACE_METHOD(0x14142E030, CKeyTable, FUN_14142e030, 80, 0x4C1331C1);

// @0x14142e090
int CKeyTable::FUN_14142e090(int nSkillId, __int64 nItemUid)
{
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return 0;
    for (POSITION pos = pPage->GetStartPosition(); pos != 0; pPage->GetNext(pos))
    {
        Unk_SsQuickEntry& entry = pPage->GetValueAt(pos);
        if (entry.m_nSkillId == nSkillId && entry.m_nItemUid == nItemUid)
            return pPage->GetKeyAt(pos);
    }
    return -1;
}
MS2_REPLACE_METHOD(0x14142E090, CKeyTable, FUN_14142e090, 176, 0x7B0AC73E);

// @0x14142e150
int CKeyTable::FUN_14142e150(int nSkillId, int nItemId, __int64 nItemUid)
{
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return 0;
    for (POSITION pos = pPage->GetStartPosition(); pos != 0; pPage->GetNext(pos))
    {
        Unk_SsQuickEntry& entry = pPage->GetValueAt(pos);
        if (entry.m_nSkillId == nSkillId && entry.m_nItemId == nItemId && entry.m_nItemUid == nItemUid)
            return pPage->GetKeyAt(pos);
    }
    return -1;
}
MS2_REPLACE_METHOD(0x14142E150, CKeyTable, FUN_14142e150, 198, 0xA02EF2EE);

// @0x14142e220
int CKeyTable::FUN_14142e220(__int64 nAction)
{
    int nCount = (int)m_quickSlotActions.GetCount();
    for (int i = 0; i < nCount; i++)
    {
        if (m_quickSlotActions.GetAt(i) == nAction)
            return i;
    }
    return -1;
}
MS2_REPLACE_METHOD(0x14142E220, CKeyTable, FUN_14142e220, 120, 0x63DE7BEB);

// @0x14142e2a0
void CKeyTable::FUN_14142e2a0(unsigned nSlot, const Unk_SsQuickEntry& entry)
{
    FUN_14142e2e0(m_nQuickSlotPage, nSlot, entry);
}
MS2_REPLACE_METHOD(0x14142E2A0, CKeyTable, FUN_14142e2a0, 54, 0x2A0E873A);

// @0x14142e2e0
void CKeyTable::FUN_14142e2e0(int nPage, unsigned nSlot, const Unk_SsQuickEntry& entry)
{
    QuickSlotPage* pPage = FUN_141431c20(nPage);
    if (pPage == 0)
        return;
    pPage->SetAt(nSlot, entry);
}
MS2_REPLACE_METHOD(0x14142E2E0, CKeyTable, FUN_14142e2e0, 76, 0x0E630629);

// @0x14142e340
int CKeyTable::FUN_14142e340(int bPressed)
{
    if (DAT_143af7d40 == 0)
        return 0;
    for (POSITION pos = m_keys.GetTailPosition(); pos != 0; m_keys.GetPrev(pos))
    {
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        int nKey = m_keys.GetKeyAt(pos);
        if (bPressed)
        {
            if (FUN_140a58540()->FUN_140d8ad60(nKey))
                return nKey;
        }
        else
        {
            if (FUN_140a58540()->FUN_140d8ac50(nKey, 0))
                return nKey;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142E340, CKeyTable, FUN_14142e340, 290, 0x98582408);

// @0x14142e470
int CKeyTable::FUN_14142e470(int bPressed)
{
    if (DAT_143af7d40 == 0)
        return 0;
    for (int nKey = 0x96; nKey <= 0x99; nKey++)
    {
        if (bPressed)
        {
            if (FUN_140a58540()->FUN_140d8ad60(nKey))
                return nKey;
        }
        else
        {
            if (FUN_140a58540()->FUN_140d8ac50(nKey, 1))
                return nKey;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142E470, CKeyTable, FUN_14142e470, 140, 0x4FA7D96B);

// @0x14142e510
bool CKeyTable::FUN_14142e510(unsigned nCombo)
{
    union { unsigned int value; struct { unsigned char low, high, mode, pad; } bytes; } packed;
    packed.value = nCombo;
    if (packed.bytes.mode == 0xf0 || packed.bytes.mode == 0xf1)
    {
        int nFirst = packed.bytes.high + 0x91;
        int nSecond = packed.bytes.low + 0x91;
        MS2Ptr<stKeyData> spKey(0);
        if (!m_keys.Lookup(nFirst, spKey))
            return false;
        if (m_keys.Lookup(nSecond, spKey))
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14142E510, CKeyTable, FUN_14142e510, 228, 0xC5362B35);

// @0x14142e600
void CKeyTable::FUN_14142e600(__int64 nAction, ATL::CAtlArray<Unk_MyPCKeyId>& aOut)
{
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        Unk_MyPCKeyId nKey = (Unk_MyPCKeyId)m_keys.GetKeyAt(pos);
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        if (spKey->m_nCode != nAction)
            continue;
        aOut.Add(nKey);
    }
}
MS2_REPLACE_METHOD(0x14142E600, CKeyTable, FUN_14142e600, 222, 0xF13E6B05);

// @0x14142e6f0
int CKeyTable::FUN_14142e6f0(int nKey)
{
    if (m_shortKeys.Lookup(nKey))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14142E6F0, CKeyTable, FUN_14142e6f0, 56, 0x1D23C6E6);

// @0x14142e730
void CKeyTable::FUN_14142e730(int nKey)
{
    m_shortKeys.SetAt(nKey, nKey);
}
MS2_REPLACE_METHOD(0x14142E730, CKeyTable, FUN_14142e730, 47, 0x7BDF8918);

// @0x14142e770
void CKeyTable::FUN_14142e770(int nKey)
{
    m_shortKeys.RemoveKey(nKey);
}
MS2_REPLACE_METHOD(0x14142E770, CKeyTable, FUN_14142e770, 42, 0x359C743D);

// @0x14142e7a0
int CKeyTable::GetLocked()
{
    return m_nLocked;
}
MS2_REPLACE_METHOD(0x14142E7A0, CKeyTable, GetLocked, 14, 0x5ADC0513);

// @0x14142e7c0
int CKeyTable::FUN_14142e7c0(int nSkillId, int nItemId, __int64 nItemUid, unsigned nCount)
{
    static int s_aSlotIndex[25] = { 4, 5, 6, 7, 0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
    if (nCount > 25)
        nCount = 25;
    Unk_KtMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (!pInfo)
        return 0;
    for (unsigned i = 0; i < nCount; i++)
    {
        SkillSlot* pSlot = pInfo->FUN_1419f2930(s_aSlotIndex[i]);
        if (!pSlot)
            continue;
        if (nItemId != 0 && pSlot->GetItemId() == nItemId)
            return 1;
        if (nSkillId != 0 && pSlot->GetSkillId() == nSkillId)
            return 1;
        if (nItemUid != 0 && pSlot->GetItemUid() == nItemUid)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14142E7C0, CKeyTable, FUN_14142e7c0, 245, 0x4845B103);

// @0x14142e8c0
void CKeyTable::FUN_14142e8c0(MS2Ptr<CSkillSet> spSet)
{
    static int s_aSlotIndex[25] = { 4, 5, 6, 7, 0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
    m_nLocked = 1;
    unsigned nPages = (unsigned)m_quickSlots.GetCount();
    m_quickSlots.RemoveAll();
    m_quickSlots.SetCount(nPages, -1);
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return;
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifySkillSetMode(true)));
    Unk_KtMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo == 0)
        return;
    size_t nSkill = 0;
    size_t nItem = 0;
    for (unsigned i = 0; i < 25; i++)
    {
        SkillSlot* pSlot = pInfo->FUN_1419f2930(s_aSlotIndex[i]);
        if (!pSlot)
            continue;
        pSlot->vfunc_11();
        if (nSkill < spSet->m_arrSkillIds.size())
        {
            Unk_SsQuickEntry entry;
            entry.m_nSkillId = spSet->m_arrSkillIds[nSkill];
            pPage->SetAt(s_aSlotIndex[i], entry);
            pSlot->SetSkillId(entry.m_nSkillId);
            nSkill++;
        }
        else if (nItem < spSet->m_arrItemIds.size())
        {
            int nItemId = FUN_14142f870(spSet->m_arrItemIds[nItem]);
            MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
            if (spItem == 0)
            {
                pPage->SetAt(s_aSlotIndex[i], Unk_SsQuickEntry());
                nItem++;
                continue;
            }
            Unk_SsQuickEntry entry;
            entry.m_nSkillId = spItem->FUN_14053dc20();
            entry.m_nItemId = nItemId;
            entry.m_nItemUid = 0;
            pPage->SetAt(s_aSlotIndex[i], entry);
            pSlot->SetItemId(entry.m_nItemId);
            pSlot->SetSkillId(entry.m_nSkillId);
            nItem++;
        }
        if (spSet->m_nSlotLock != 0)
            pSlot->SetFixed(1);
        pSlot->vfunc_10();
    }
}

// @0x14142ece0
void CKeyTable::FUN_14142ece0(const ATL::CAtlArray<unsigned>& aItemIds)
{
    static int s_aSlotIndex[25] = { 4, 5, 6, 7, 0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
    m_nLocked = 1;
    unsigned nPages = (unsigned)m_quickSlots.GetCount();
    m_quickSlots.RemoveAll();
    m_quickSlots.SetCount(nPages, -1);
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return;
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifySkillSetMode(true)));
    Unk_KtMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo == 0)
        return;
    for (unsigned i = 0; i < 25; i++)
    {
        SkillSlot* pSlot = pInfo->FUN_1419f2930(s_aSlotIndex[i]);
        if (!pSlot)
            continue;
        pSlot->vfunc_11();
        if (i < aItemIds.GetCount())
        {
            Unk_SsQuickEntry entry;
            entry.m_nSkillId = 0;
            entry.m_nItemId = aItemIds[i];
            entry.m_nItemUid = 0;
            pPage->SetAt(s_aSlotIndex[i], entry);
            pSlot->SetItemId(aItemIds[i]);
        }
        pSlot->SetFixed(1);
        pSlot->vfunc_10();
    }
}

// @0x14142ef50
void CKeyTable::FUN_14142ef50(int nSkillId, int nItemId, __int64 nItemUid, unsigned nCount)
{
    static int s_aSlotIndex[25] = { 4, 5, 6, 7, 0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
    if (m_nLocked != 1)
        return;
    Unk_KtMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (!pInfo)
        return;
    if (nCount > 25)
        nCount = 25;
    for (unsigned i = 0; i < nCount; i++)
    {
        SkillSlot* pSlot = pInfo->FUN_1419f2930(s_aSlotIndex[i]);
        if (!pSlot)
            continue;
        if (nItemId != 0 && pSlot->GetItemId() == nItemId)
            return;
        if (nSkillId != 0 && pSlot->GetSkillId() == nSkillId)
            return;
        if (nItemUid != 0 && pSlot->GetItemUid() == nItemUid)
            return;
    }
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (!pPage)
        return;
    for (unsigned j = 0; j < nCount; j++)
    {
        SkillSlot* pSlot = pInfo->FUN_1419f2930(s_aSlotIndex[j]);
        if (!pSlot)
            continue;
        if (pSlot->GetItemId() == 0 && pSlot->GetSkillId() == 0 && pSlot->GetItemUid() == 0)
        {
            Unk_SsQuickEntry entry;
            entry.m_nSkillId = nSkillId;
            entry.m_nItemId = nItemId;
            entry.m_nItemUid = nItemUid;
            pPage->SetAt(s_aSlotIndex[j], entry);
            pSlot->SetSkillId(nSkillId);
            pSlot->SetItemId(nItemId);
            pSlot->SetItemUid(nItemUid);
            pSlot->SetFixed(0);
            pSlot->vfunc_10();
            FUN_1414321f0();
            return;
        }
    }
}
MS2_REPLACE_METHOD(0x14142EF50, CKeyTable, FUN_14142ef50, 607, 0x560846BE);

// @0x14142f1c0
void CKeyTable::FUN_14142f1c0(int nSkillId, int nItemId, __int64 nItemUid)
{
    Unk_KtMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo == 0)
        return;
    int nSlot = FUN_141432650(nItemId);
    if (nSlot == -1)
        return;
    SkillSlot* pSlot = pInfo->FUN_1419f2930(nSlot);
    if (pSlot == 0)
        return;
    if (pSlot->GetSkillId() != 0 || pSlot->GetItemUid() != 0 || pSlot->GetItemId() != 0)
        return;
    if (FUN_14142e7c0(nSkillId, nItemId, nItemUid, 25))
        return;
    Unk_KtPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer)
    {
        if (pPlayer->FUN_141654700() == 90)
        {
            if (!FUN_140764020()->m_list.FUN_140745590(90000414))
                return;
            if (!FUN_140764020()->m_list.FUN_140745590(90000415))
                return;
        }
        if (pPlayer->FUN_141654700() == 110)
        {
            if (!FUN_140764020()->m_list.FUN_140745590(90000444))
                return;
        }
        if (pPlayer->FUN_141654700() == 100)
        {
            if (!FUN_140764020()->m_list.FUN_140745590(90000431))
                return;
        }
    }
    QuickSlotPage* pPage = FUN_141431c20(m_nQuickSlotPage);
    if (pPage == 0)
        return;
    Unk_SsQuickEntry entry;
    entry.m_nSkillId = nSkillId;
    entry.m_nItemUid = nItemUid;
    entry.m_nItemId = nItemId;
    pPage->SetAt(nSlot, entry);
    pSlot->SetSkillId(nSkillId);
    pSlot->SetItemUid(nItemUid);
    pSlot->SetItemId(nItemId);
    pSlot->SetFixed(0);
    pSlot->vfunc_10();
    FUN_1414321f0();
    FUN_14092f690(nSkillId, nItemId, nItemUid, m_nQuickSlotPage, nSlot);
}
MS2_REPLACE_METHOD(0x14142F1C0, CKeyTable, FUN_14142f1c0, 668, 0xE69F370C);

// @0x14142f470
void CKeyTable::FUN_14142f470(int nPage, int nSlot)
{
    Unk_KtMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo == 0)
        return;
    QuickSlotPage* pPage = FUN_141431c20(nPage);
    if (pPage == 0)
        return;
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    DAT_143ab2a90.FUN_140a60880(10, items);
    for (size_t i = 0; i < items.GetCount(); i++)
    {
        int nSkillId = items[i]->FUN_140527840()->FUN_14053dc20();
        __int64 nItemUid = items[i]->FUN_140526a50();
        int nItemId = items[i]->FUN_1405276c0();
        int nJobSlot = FUN_141432650(nItemId);
        if (nJobSlot == -1)
            continue;
        if (nSlot != nJobSlot)
            continue;
        if (FUN_14142e7c0(nSkillId, nItemId, nItemUid, 25))
            continue;
        Unk_SsQuickEntry entry;
        entry.m_nSkillId = nSkillId;
        entry.m_nItemUid = nItemUid;
        entry.m_nItemId = nItemId;
        pPage->SetAt(nSlot, entry);
        if (nPage == m_nQuickSlotPage)
        {
            SkillSlot* pSlot = pInfo->FUN_1419f2930(nJobSlot);
            if (pSlot == 0)
                continue;
            pSlot->SetSkillId(nSkillId);
            pSlot->SetItemUid(nItemUid);
            pSlot->SetItemId(nItemId);
            pSlot->SetFixed(0);
            pSlot->vfunc_10();
        }
        FUN_1414321f0();
        FUN_14092f690(nSkillId, nItemId, nItemUid, nPage, nSlot);
    }
}
MS2_REPLACE_METHOD(0x14142F470, CKeyTable, FUN_14142f470, 650, 0xA4530BDC);

// @0x14142f700
void CKeyTable::SendKeyTableMode7()
{
    if (m_nLocked == 0)
        return;
    Unk_KtMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo)
        pInfo->FUN_1419f2a90();
    m_nLocked = 0;
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifySkillSetMode(false)));
    FUN_141429600();
    COutPacket packet(0x3a, 0);
    packet.Encode1(7);
    FUN_140710590(packet);
}

// @0x14142f830
int CKeyTable::FUN_14142f830(int nSlot)
{
    Unk_KtPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return nSlot;
    return nSlot;
}
MS2_REPLACE_METHOD(0x14142F830, CKeyTable, FUN_14142f830, 54, 0x89DB0C7A);

// @0x14142f870
int CKeyTable::FUN_14142f870(int nSlot)
{
    Unk_KtPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return nSlot;
    return nSlot;
}
MS2_REPLACE_METHOD(0x14142F870, CKeyTable, FUN_14142f870, 54, 0xBF6F947A);

// The unit's log call (an FMT_VARIADIC wrapper over CLogString::FUN_1406530d0; instance 0x141432850).
template <class T> void Unk_KtLogFormat(Unk_KtLog* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    pLog->FUN_1406530d0(nLevel, nCategory, pszFormat, fmt::ArgList(fmt::internal::make_type(first), args));
}

// @0x14142f8b0
void CKeyTable::SaveKeySetting(CString strName)
{
    Unk_KtMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo == 0)
        return;
    TiXmlDocument doc;
    TiXmlDeclaration decl("1.0", "utf-8", "");
    FUN_14086e000(&doc, decl);
    TiXmlElement* pRoot = new TiXmlElement("ms2");
    for (size_t i = 0; i < 25; i++)
    {
        SkillSlot* pSlot = pInfo->FUN_1419f2930((int)i);
        if (!pSlot)
            continue;
        int nItemId = pSlot->GetItemId();
        int nSkillId = pSlot->GetSkillId();
        int nJobItemId = FUN_14142f830(nItemId);
        if (nJobItemId != nItemId)
        {
            MS2Ptr<CItemData> spItem = FUN_14053f870(nJobItemId);
            if (spItem)
                nSkillId = spItem->FUN_14053dc20();
        }
        TiXmlElement* pSetting = new TiXmlElement("setting");
        FUN_140873f20(pSetting, "index", i);
        FUN_140873ce0(pSetting, "itemId", nJobItemId);
        FUN_140873ce0(pSetting, "skillId", nSkillId);
        FUN_14086e090(pRoot, pSetting);
    }
    FUN_14086e090(&doc, pRoot);
    CString strFile = FUN_140540050("keySetting_{0}.xml", strName);
    FUN_1408710c0(&doc, FUN_140cc2a00(FUN_1412755f0(), strFile));
}
MS2_REPLACE_METHOD(0x14142F8B0, CKeyTable, SaveKeySetting, 843, 0x96150CB6);

// @0x14142fc10
void CKeyTable::LoadKeySetting(CString strName)
{
    Unk_KtMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo == 0)
        return;
    CString strFile = FUN_140540050("keySetting_{0}.xml", strName);
    TiXmlDocument doc;
    if (!doc.FUN_140870fc0(FUN_140cc2a00(FUN_1412755f0(), strFile), 0))
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    unsigned nPages = (unsigned)m_quickSlots.GetCount();
    m_quickSlots.RemoveAll();
    m_quickSlots.SetCount(nPages, -1);
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("setting"); pNode != 0; pNode = pNode->FUN_140168650("setting"))
    {
        int nIndex = FUN_140197350(pNode, "index", -1);
        int nItemId = FUN_140197390(pNode, "itemId", 0);
        int nSkillId = FUN_140197390(pNode, "skillId", 0);
        if (nIndex > 25 || nIndex < 0)
            continue;
        int nJobItemId = FUN_14142f870(nItemId);
        if (nJobItemId != nItemId)
        {
            MS2Ptr<CItemData> spItem = FUN_14053f870(nJobItemId);
            if (spItem)
                nSkillId = spItem->FUN_14053dc20();
        }
        SkillSlot* pSlot = pInfo->FUN_1419f2930(nIndex);
        if (!pSlot)
            continue;
        pSlot->vfunc_11();
        if (nJobItemId == 0 && nSkillId == 0)
            continue;
        Unk_SsQuickEntry entry;
        entry.m_nSkillId = nSkillId;
        entry.m_nItemId = nJobItemId;
        entry.m_nItemUid = 0;
        FUN_14142e2a0(nIndex, entry);
        pSlot->SetSkillId(nSkillId);
        pSlot->SetItemId(nJobItemId);
        pSlot->vfunc_10();
    }
}
MS2_REPLACE_METHOD(0x14142FC10, CKeyTable, LoadKeySetting, 978, 0x3C20ED15);

// @0x14142fff0
int CKeyTable::LoadKeySettingTable()
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, FUN_14071a5b0("Table", "keySetting.xml"), 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        Unk_KtLogFormat(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", "keySetting.xml");
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("key"); pNode != 0; pNode = pNode->FUN_140168650("key"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CStringW strLocale;
        FUN_140873420(pNode, "locale", strLocale);
        if (!FUN_140166410()->FUN_14036d750(strLocale))
            continue;
        MS2Ptr<CKeySettingParam> spParam(new CKeySettingParam());
        int nType = 0;
        int nCategory = 0;
        int nKeyGuid = 0;
        FUN_1408731e0(pNode, "type", nType);
        FUN_1408731e0(pNode, "category", nCategory);
        FUN_1408731e0(pNode, "keyGuid", nKeyGuid);
        FUN_1408731e0(pNode, "disableprimary", spParam->m_nPrimaryLocked);
        FUN_1408731e0(pNode, "disablesecondary", spParam->m_nSecondaryLocked);
        FUN_1408731e0(pNode, "disablethirdly", spParam->m_nThirdlyLocked);
        spParam->m_nAction = nKeyGuid;
        spParam->m_nType = nType;
        SettingList spList(0);
        if (!m_settings.Lookup(nCategory, spList))
        {
            spList = Unk_GrNewTag(0);
            m_settings.SetAt(nCategory, spList);
        }
        spList->AddTail(spParam);
    }
    return 1;
}

// @0x141430470
int CKeyTable::FUN_141430470(__int64 nAction)
{
    const int nCategory = 12;
    SettingList spList;
    if (m_settings.Lookup(nCategory, spList))
    {
        for (POSITION pos = spList->GetHeadPosition(); pos != 0; spList->GetNext(pos))
        {
            MS2Ptr<CKeySettingParam> spParam = spList->GetAt(pos);
            if (spParam->m_nAction == nAction)
                return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141430470, CKeyTable, FUN_141430470, 273, 0x5FDCA844);

// @0x141430590
MS2Ptr<CKeySettingParam> CKeyTable::FUN_141430590(__int64 nAction) const
{
    for (POSITION pos = m_settings.GetStartPosition(); pos != 0; m_settings.GetNext(pos))
    {
        SettingList spList = m_settings.GetValueAt(pos);
        for (POSITION posParam = spList->GetHeadPosition(); posParam != 0; spList->GetNext(posParam))
        {
            MS2Ptr<CKeySettingParam> spParam = spList->GetAt(posParam);
            if (spParam->m_nAction == nAction)
                return spParam;
        }
    }
    return MS2Ptr<CKeySettingParam>(0);
}
MS2_REPLACE_METHOD(0x141430590, CKeyTable, FUN_141430590, 374, 0xBC02E11B);

// @0x141430710
CKeyTable::SettingList CKeyTable::FUN_141430710(int nCategory)
{
    SettingList spList(0);
    m_settings.Lookup(nCategory, spList);
    return spList;
}
MS2_REPLACE_METHOD(0x141430710, CKeyTable, FUN_141430710, 123, 0x8348C6B3);

// @0x1414307a0
void CKeyTable::FUN_1414307a0()
{
    m_1e0.RemoveAll();
    m_200.RemoveAll();
    m_220.RemoveAll();
    m_240.RemoveAll();
    m_1e0.Add(0xc3501);
    m_1e0.Add(0xc3502);
    m_1e0.Add(0xc3503);
    m_200.Add((Unk_MyPCKeyId)0x94);
    m_200.Add((Unk_MyPCKeyId)0x92);
    m_200.Add((Unk_MyPCKeyId)0x95);
    m_200.Add((Unk_MyPCKeyId)0x93);
    m_200.Add((Unk_MyPCKeyId)0x9c);
    m_200.Add((Unk_MyPCKeyId)0x9a);
    m_200.Add((Unk_MyPCKeyId)0x9d);
    m_200.Add((Unk_MyPCKeyId)0x9b);
    m_220.Add((Unk_MyPCKeyId)0x96);
    m_220.Add((Unk_MyPCKeyId)0x97);
    m_220.Add((Unk_MyPCKeyId)0x98);
    m_220.Add((Unk_MyPCKeyId)0x99);
    for (size_t i = 0; i < m_220.GetCount(); i++)
    {
        for (size_t j = 0; j < m_200.GetCount(); j++)
        {
            unsigned nCombo;
            FUN_141430e70(&nCombo, m_220[i], m_200[j], 0xf0);
            m_240.Add((Unk_MyPCKeyId)nCombo);
        }
    }
}
MS2_REPLACE_METHOD(0x1414307A0, CKeyTable, FUN_1414307a0, 862, 0x918D9639);

// @0x141430b10
int CKeyTable::FUN_141430b10(__int64 nAction)
{
    for (size_t i = 0; i < m_1e0.GetCount(); i++)
    {
        if (nAction == m_1e0[i])
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141430B10, CKeyTable, FUN_141430b10, 114, 0x0CC9897B);

// @0x141430b90
int CKeyTable::FUN_141430b90(int nKey)
{
    MS2Ptr<stKeyData> spKey(0);
    if (m_keys.Lookup(nKey, spKey))
    {
        if (FUN_141430b10(spKey->m_nCode))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141430B90, CKeyTable, FUN_141430b90, 148, 0x314DB862);

// @0x141430c30
int CKeyTable::FUN_141430c30(int nKey)
{
    for (size_t i = 0; i < m_220.GetCount(); i++)
    {
        if (nKey == m_220[i])
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141430C30, CKeyTable, FUN_141430c30, 111, 0x141EF281);

// @0x141430cb0
int CKeyTable::FUN_141430cb0(int nKey)
{
    for (size_t i = 0; i < m_240.GetCount(); i++)
    {
        if (nKey == m_240[i])
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141430CB0, CKeyTable, FUN_141430cb0, 111, 0xB349CD99);

// @0x141430d30
void CKeyTable::FUN_141430d30(__int64 nAction, int nKey, int nPriority, int nOldKey)
{
    if (nPriority != 2)
        return;
    if (!FUN_141430b10(nAction))
        return;
    if (!FUN_141430c30(nKey))
        return;
    if (nKey == nOldKey)
        return;
    MS2Ptr<stKeyData> spKey = FUN_14142c890(nKey);
    if (spKey.get())
    {
        FUN_1414310f0(nOldKey, nKey, spKey->m_nCode, nAction);
        if (FUN_141430b90(nKey))
            FUN_141431c80(nOldKey, 2, spKey->m_nCode, 0, 2, 1);
    }
}
MS2_REPLACE_METHOD(0x141430D30, CKeyTable, FUN_141430d30, 309, 0x36A93CDE);

// @0x141430e70
unsigned* CKeyTable::FUN_141430e70(unsigned* pOut, int nFirst, int nSecond, int nMode)
{
    union { unsigned int value; struct { unsigned char low, high, mode, pad; } bytes; } packed;
    packed.bytes.pad = 0;
    packed.bytes.mode = nMode;
    packed.bytes.high = (nFirst - 0x91) & 0xff;
    packed.bytes.low = (nSecond - 0x91) & 0xff;
    *pOut = packed.value;
    return pOut;
}
MS2_REPLACE_METHOD(0x141430E70, CKeyTable, FUN_141430e70, 93, 0x06A76195);

// @0x141430ee0
CStringW CKeyTable::CreateCombineKeyString(int nFirst, int nSecond)
{
    CStringW strKey;
    MS2Ptr<stKeyData> spFirst(0);
    MS2Ptr<stKeyData> spSecond(0);
    m_keys.Lookup(nFirst, spFirst);
    m_keys.Lookup(nSecond, spSecond);
    if (spFirst == 0 || spSecond == 0)
    {
        MessageBoxW(0, StringFormat(L"{0} {1} Have not key string (keyName.xml)", (const Unk_CommandKeyCode&)nFirst, (const Unk_CommandKeyCode&)nSecond),
            L"CKeyTable::CreateCombineKeyString Error", 0);
        exit(1);
    }
    strKey.Format(L"%s,%s", (const wchar_t*)spFirst->m_strName, (const wchar_t*)spSecond->m_strName);
    return strKey;
}
MS2_REPLACE_METHOD(0x141430EE0, CKeyTable, CreateCombineKeyString, 431, 0xF8C5E308);

// @0x1414310a0
void CKeyTable::FUN_1414310a0(unsigned nKey, int* pFirst, int* pSecond)
{
    union { unsigned int value; struct { unsigned char low, high, mode, pad; } bytes; } packed;
    packed.value = nKey;
    *pFirst = packed.bytes.high + 0x91;
    *pSecond = packed.bytes.low + 0x91;
}
MS2_REPLACE_METHOD(0x1414310A0, CKeyTable, FUN_1414310a0, 68, 0x7BA7262D);

// @0x1414310f0
void CKeyTable::FUN_1414310f0(int nKey, int nOtherKey, __int64 nAction, __int64 nOtherAction)
{
    MS2Ptr<stKeyData> spKey = FUN_14142c890(nKey);
    MS2Ptr<stKeyData> spOther = FUN_14142c890(nOtherKey);
    int bOther = FUN_141430b90(nOtherKey);
    __int64 nBase = FUN_1414317b0(nAction);
    __int64 nOtherBase = FUN_1414317b0(nOtherAction);
    int nCount = nOtherBase == 0x7a131 ? 6 : 8;
    ATL::CAtlArray<Unk_MyPCKeyId> aCombos;
    ATL::CAtlArray<Unk_MyPCKeyId> aOtherCombos;
    ATL::CAtlArray<unsigned> aSlots;
    ATL::CAtlArray<unsigned> aOtherSlots;
    ATL::CAtlArray<__int64> aActions;
    ATL::CAtlArray<__int64> aOtherActions;
    for (int i = (int)nOtherBase; (unsigned __int64)(__int64)i < (unsigned __int64)(nOtherBase + nCount); i++)
    {
        int nCombo = FUN_14142c940(i, 2);
        if (nCombo == 0)
            continue;
        int nFirst;
        int nSecond;
        FUN_1414310a0(nCombo, &nFirst, &nSecond);
        unsigned nNewCombo;
        FUN_141430e70(&nNewCombo, nOtherKey, nSecond, 0xf0);
        int nSlot = FUN_14142dad0(nCombo);
        aCombos.Add((Unk_MyPCKeyId)nNewCombo);
        aSlots.Add(nSlot);
        aActions.Add(i);
    }
    if (bOther)
    {
        nCount = nBase == 0x7a131 ? 6 : 8;
        for (int i = (int)nBase; (unsigned __int64)(__int64)i < (unsigned __int64)(nBase + nCount); i++)
        {
            int nCombo = FUN_14142c940(i, 2);
            if (nCombo == 0)
                continue;
            int nFirst;
            int nSecond;
            FUN_1414310a0(nCombo, &nFirst, &nSecond);
            unsigned nNewCombo;
            FUN_141430e70(&nNewCombo, nKey, nSecond, 0xf0);
            int nSlot = FUN_14142dad0(nCombo);
            aOtherCombos.Add((Unk_MyPCKeyId)nNewCombo);
            aOtherSlots.Add(nSlot);
            aOtherActions.Add(i);
        }
        FUN_1414316e0(nOtherKey, nAction);
    }
    FUN_1414316e0(nKey, nOtherAction);
    for (size_t i = 0; i < aActions.GetCount(); i++)
    {
        int nCombo = aCombos[i];
        int nSlot = aSlots[i];
        __int64 nComboAction = aActions[i];
        FUN_141431c80(nCombo, 2, nComboAction, nSlot, 2, 1);
        FUN_14142a8b0(nComboAction);
    }
    for (size_t i = 0; i < aOtherActions.GetCount(); i++)
    {
        int nCombo = aOtherCombos[i];
        int nSlot = aOtherSlots[i];
        __int64 nComboAction = aOtherActions[i];
        FUN_141431c80(nCombo, 2, nComboAction, nSlot, 2, 1);
        FUN_14142a8b0(nComboAction);
    }
}
MS2_REPLACE_METHOD(0x1414310F0, CKeyTable, FUN_1414310f0, 1506, 0x0411AC44);

// @0x1414316e0
void CKeyTable::FUN_1414316e0(int nKey, __int64 nAction)
{
    for (size_t i = 0; i < m_200.GetCount(); i++)
    {
        Unk_MyPCKeyId nSecond = m_200[i];
        unsigned nCombo;
        FUN_141430e70(&nCombo, nKey, nSecond, 0xf0);
        FUN_141431c80(nCombo, 2, 0, 0, 2, 1);
    }
}
MS2_REPLACE_METHOD(0x1414316E0, CKeyTable, FUN_1414316e0, 188, 0xE6CF03B9);

// @0x1414317b0
__int64 CKeyTable::FUN_1414317b0(__int64 nAction)
{
    __int64 nBase = 0;
    switch (nAction)
    {
    case 0xc3501: nBase = 0x7a121; break;
    case 0xc3502: nBase = 0x7a129; break;
    case 0xc3503: nBase = 0x7a131; break;
    }
    return nBase;
}
MS2_REPLACE_METHOD(0x1414317B0, CKeyTable, FUN_1414317b0, 104, 0xEB7B6208);

// @0x141431820
CStringW CKeyTable::FUN_141431820(int nKey)
{
    if (*FUN_1409a8b10()->FUN_140a58500())
    {
        if (FUN_140a58540()->FUN_140d8ee40() == 2)
        {
            switch (nKey)
            {
            case 0x96:
                return L"L1";
            case 0x97:
                return L"L2";
            case 0x98:
                return L"R1";
            case 0x99:
                return L"R2";
            }
        }
        else
        {
            MS2Ptr<stKeyData> spKey(0);
            if (m_keys.Lookup(nKey, spKey))
                return spKey->m_strName;
        }
    }
    return L"";
}
MS2_REPLACE_METHOD(0x141431820, CKeyTable, FUN_141431820, 445, 0xA9F48A3D);

// @0x1414319f0
int CKeyTable::FUN_1414319f0()
{
    if (*FUN_1409a8b10()->FUN_140a58500() != 0)
        return 2;
    else
        return 0;
}
MS2_REPLACE_METHOD(0x1414319F0, CKeyTable, FUN_1414319f0, 43, 0xD1F3830F);

// @0x141431a30
int CKeyTable::FUN_141431a30(int nKey)
{
    if (nKey < 0x91)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141431A30, CKeyTable, FUN_141431a30, 29, 0x573705D5);

// @0x141431a60
int CKeyTable::FUN_141431a60(int nKey)
{
    if (nKey > 0xc8 && nKey < 0xd0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141431A60, CKeyTable, FUN_141431a60, 39, 0xB42A4CF0);

// @0x141431a90
int CKeyTable::FUN_141431a90(int nKey)
{
    if (nKey > 0x91 && nKey < 0xb3)
        return 1;
    if (nKey > 0xf00000 && nKey < 0xf10811)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141431A90, CKeyTable, FUN_141431a90, 66, 0x3C69A6F2);

// @0x141431ae0
void CKeyTable::FUN_141431ae0(int nPage, bool bSend)
{
    if (nPage < 0 || nPage >= (int)m_quickSlots.GetCount())
    {
        MS2_ASSERT_AT(2973, 0);
        return;
    }
    int nPrev = m_nQuickSlotPage;
    m_nQuickSlotPage = nPage;
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyShortkeyPage(nPrev, nPage)));
    if (bSend)
        SendKeyTableMode8(nPage);
}

// @0x141431c20
CKeyTable::QuickSlotPage* CKeyTable::FUN_141431c20(int nPage)
{
    if (nPage < 0 || nPage >= (int)m_quickSlots.GetCount())
        return 0;
    return &m_quickSlots[nPage];
}
MS2_REPLACE_METHOD(0x141431C20, CKeyTable, FUN_141431c20, 79, 0x4BB3C385);

// @0x141431c80
int CKeyTable::FUN_141431c80(int nKey, int nType, __int64 nCode, int nSlot, int nPriority, int bSave)
{
    MS2Ptr<stKeyData> spKey(0);
    if (!m_keys.Lookup(nKey, spKey))
        return 0;
    if (FUN_14142cf10(nCode))
        nSlot = 0;
    if (spKey->FUN_1414287c0(nType, nCode, nSlot, nPriority))
        return 0;
    CStringW strName = GetStringTable()->FUN_1418125b0((int)nCode);
    if (nCode != 0 && strName.IsEmpty())
        return 0;
    spKey->m_nType = nType;
    spKey->m_nCode = nCode;
    spKey->m_nPriority = nPriority;
    spKey->m_nSlot = nSlot;
    int nPair;
    if (m_pairKeys.Lookup(nKey, nPair) && m_keys.Lookup(nPair, spKey))
    {
        spKey->m_nType = nType;
        spKey->m_nCode = nCode;
        spKey->m_nPriority = nPriority;
        spKey->m_nSlot = nSlot;
    }
    if (bSave)
    {
        FUN_1414321f0();
        FUN_141431f20(nKey);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141431C80, CKeyTable, FUN_141431c80, 651, 0xF9583AF2);

// @0x141431f20
void CKeyTable::FUN_141431f20(int nKey)
{
    CString str;
    str.Format("%d", nKey);
    FUN_1422c9380(str);
    int nPair;
    if (m_pairKeys.Lookup(nKey, nPair))
    {
        str.Format("%d", nPair);
        FUN_1422c9380(str);
    }
}
MS2_REPLACE_METHOD(0x141431F20, CKeyTable, FUN_141431f20, 153, 0xDC75732D);

// @0x141431fc0
int CKeyTable::FUN_141431fc0()
{
    if (m_nMode == 0)
        return 0;
    if (FUN_14025e7c0()->FUN_14116d7a0(0xf))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x141431FC0, CKeyTable, FUN_141431fc0, 63, 0x6C16D997);

// @0x141432010
int CKeyTable::FUN_141432010(int nAction)
{
    Unk_KtPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 1;
    efd::SmartPointer<Ridee> spRidee = pPlayer->FUN_1416764a0();
    if (spRidee == 0)
        return 1;
    if (spRidee->GetData()->m_nSeats == 0)
        return 1;
    switch (nAction)
    {
    case 0x61a81:
    case 0x61a82:
    case 0x61a85:
        FUN_1412751f0(GetStringCommonByKey(L"s_hide_pcinfo_dialog_disable_message"), 1, 1);
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141432010, CKeyTable, FUN_141432010, 462, 0x677DEC51);

// @0x1414321f0
void CKeyTable::FUN_1414321f0()
{
    m_actionKeys.RemoveAll();
    m_d8.RemoveAll();
    for (POSITION pos = m_keys.GetHeadPosition(); pos != 0; m_keys.GetNext(pos))
    {
        MS2Ptr<stKeyData> spKey = m_keys.GetValueAt(pos);
        if (spKey.IsNull())
            continue;
        if (spKey->m_nCode == 0)
            continue;
        int nKey = m_keys.GetKeyAt(pos);
        m_actionKeys.Insert(spKey->m_nCode, nKey);
        m_d8.Insert(spKey->m_nSlot, nKey);
    }
    FUN_140a94350()->vfunc_9();
}
MS2_REPLACE_METHOD(0x1414321F0, CKeyTable, FUN_1414321f0, 354, 0xEBF564A2);

// @0x141432360
void CKeyTable::FUN_141432360(int nSkillId)
{
    if (nSkillId == 0)
        return;
    MS2Ptr<Unk_KtSkill> spSkill = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
    if (spSkill.get())
    {
        if (spSkill->FUN_1407e9d30())
            m_18.SetAt(nSkillId, nSkillId);
    }
}
MS2_REPLACE_METHOD(0x141432360, CKeyTable, FUN_141432360, 137, 0x7A083E09);

// @0x1414323f0
void CKeyTable::FUN_1414323f0(int nPage, unsigned nSlot, int nSkillId, int nItemId, __int64 nItemUid)
{
    if (m_nLocked != 0)
        return;
    QuickSlotPage* pPage = FUN_141431c20(nPage);
    if (pPage == 0)
        return;
    Unk_SsQuickEntry entry;
    entry.m_nSkillId = nSkillId;
    entry.m_nItemId = nItemId;
    entry.m_nItemUid = nItemUid;
    pPage->SetAt(nSlot, entry);
}
MS2_REPLACE_METHOD(0x1414323F0, CKeyTable, FUN_1414323f0, 125, 0xEA0D85D3);

// @0x141432480
TiXmlDocument CKeyTable::FUN_141432480(const CString& strPath)
{
    TiXmlDocument doc;
    TiXmlDeclaration* pDecl = new TiXmlDeclaration("1.0", "utf-8", "");
    FUN_14086e090(&doc, pDecl);
    TiXmlElement* pRoot = new TiXmlElement("ms2");
    FUN_14086e090(&doc, pRoot);
    TiXmlElement* pConfig = new TiXmlElement("KeyConfig");
    FUN_14086e090(pRoot, pConfig);
    FUN_1408710c0(&doc, strPath);
    return doc;
}
MS2_REPLACE_METHOD(0x141432480, CKeyTable, FUN_141432480, 446, 0xBEC6CC5E);

// @0x141432650
int CKeyTable::FUN_141432650(int nCode)
{
    if (nCode == 0x1312d1c || nCode == 0x13130d6)
        return 8;
    if (nCode == 0x1312d16 || nCode == 0x1312fb4)
        return 9;
    return -1;
}

// ---- the unit's small classes ----

// @0x141435250
CKeySettingParam::CKeySettingParam()
{
    m_nAction = 0;
    m_nType = 0;
    m_nPriority = 1;
    m_nPrimaryLocked = 0;
    m_nSecondaryLocked = 0;
    m_nThirdlyLocked = 0;
}

// @0x141435590
NotifyShortkeyPage::NotifyShortkeyPage(int nPrev, int nCur)
{
    m_nPrev = nPrev;
    m_nCur = nCur;
}

// @0x1414355e0
NotifySkillSetMode::NotifySkillSetMode(bool bMode)
{
    m_bMode = bMode;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2230-0x142cb2290 .text$yd
