// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The GameEvent subclasses of commonfiles\gameevent.cpp:
// per class a factory (registered by name in the dynamic initializers), the name (GetTypeName), the ctor, the parser of the
// event's string fields (vfunc_2), the packet write / read (vfunc_3 / vfunc_4) and the start / end handlers (OnStart /
// vfunc_6, mostly forwarding to CGameRule). The ctors of the *Context element types and the template glue follow at
// the end of the range; the vftables, ??_G and the implicit dtors are COMDATs of unit_1403e9650.
// MS2-UNIT: commonfiles\gameevent.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x1400b6380-0x1400b8480 .text$di
// MS2-RANGE: 0x1403bb510-0x1403e4a90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@$$QEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@@Z 0x1403d7290 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHH@std@@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHH@1@@Z 0x1403d8530 ; unique
// MS2-PIN: ??$_Buynode@AEAU?$pair@$$CBHH@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEAU?$pair@$$CBHH@1@@Z 0x1403d86c0 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1403d87e0 ; unique
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x1403d8b30 ; prop
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x1403d8c50 ; unique
// MS2-PIN: ??$_Copy_nodes@U_Copy_tag@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEAU21@0U_Copy_tag@01@@Z 0x1403d8d70 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@IH@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@1@PEAU01@@Z 0x1403d9d50 ; prop
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@@std@@@?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@@1@PEAU01@@Z 0x1403d9de0 ; prop
// MS2-PIN: ??$_Insert_at@AEAHPEAU?$_Tree_node@HPEAX@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@_NPEAU?$_Tree_node@HPEAX@1@AEAH1@Z 0x1403d9f20 ; prop
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHH@std@@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEAU?$pair@$$CBHH@1@1@Z 0x1403da5e0 ; prop
// MS2-PIN: ??$_Insert_hint@AEAHPEAU?$_Tree_node@HPEAX@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@V21@AEAHPEAU?$_Tree_node@HPEAX@1@@Z 0x1403dba20 ; prop
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHH@std@@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@AEAU?$pair@$$CBHH@1@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@@Z 0x1403dc660 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAHPEAU?$_Tree_node@HPEAX@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@1@_NAEAHPEAU?$_Tree_node@HPEAX@1@@Z 0x1403ddee0 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHH@std@@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHH@1@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@@Z 0x1403de700 ; prop
// MS2-PIN: ??$_Insert_nohint@AEBU?$pair@IH@std@@U_Not_a_node_tag@2@@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@@std@@_N@1@_NAEBU?$pair@IH@1@U_Not_a_node_tag@1@@Z 0x1403def20 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x1403e00d0 ; unique
// MS2-PIN: ??$_Try_emplace@AEBK$$V@?$map@KHU?$less@K@std@@V?$allocator@U?$pair@$$CBKH@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKH@std@@@std@@@std@@@std@@_N@1@AEBK@Z 0x1403e0220 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@IH@std@@PEAX@0@AEAPEAU10@@Z 0x1403e06a0 ; prop
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@W4Unk_UGCUploadType@@PEAX@0@AEAPEAU10@@Z 0x1403e06b0 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBHH@std@@@std@@YAPEAU?$pair@$$CBHH@0@AEAU10@@Z 0x1403e06c0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@0@AEAV10@@Z 0x1403e06e0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEAPEAU31@@Z 0x1403e07b0 ; prop
// MS2-PIN: ??$construct@U?$pair@IH@std@@AEBU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@IH@std@@PEAX@std@@@1@QEAU?$pair@IH@1@AEBU31@@Z 0x1403e0a50 ; unique
// MS2-PIN: ??$emplace_hint@AEBH@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@V21@AEBH@Z 0x1403e0ed0 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@0@AEAPEAU10@@Z 0x1403e1080 ; prop
// MS2-PIN: ??0?$MS2Ptr@UCard@GalleryContext@@@@QEAA@AEBV0@@Z 0x1403e1a20 ; prop
// MS2-PIN: ??0?$MS2Ptr@UReward@LongTermAttendGiftContext@@@@QEAA@AEBV0@@Z 0x1403e1e50 ; prop
// MS2-PIN: ??0SAHotTimeEventContext@@QEAA@XZ 0x1403e4540 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@PEAU01@@Z 0x1403d9cc0 ; called by map<int,int> _Destroy_if_node 0x1403f57f0, _Erase 0x1403f5950, _Freeheadnode/_Freenode0 and erase 0x1403fab30
// MS2-PINS-END tplpin
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@@Z 0x1403e0c70 ; merge 54's pair: 10 of the unit's one-instruction functions are byte-identical here, the row is at uiinventorydialog's copy 0x1419a8250
// MS2-PIN: ??__Es_sortNames7@@YAXXZ 0x1400b8360
// MS2-PIN: ??__Es_skill@@YAXXZ 0x1400b8420
// MS2-PIN: ??__Es_stun@@YAXXZ 0x1400b8450
// The map<int,int> ctor: symbols.tsv binds the name to 0x1411af7d0, effectservice's map<CString,..> twin (its tree
// ctor forwards less<CStringA>).
// MS2-PIN: ??0?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA@XZ 0x1403e3810
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameevent.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cgamerule.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/cshopeventmanager.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/gameeventuservaluenametable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/logstring.h"
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
class CShutdownEventBillboard;
class CShutdownEventUGCBanner;

// The packet stand-ins of the GameEvent slots are the COutputStream / the CInPacket (its CInputStream base at +8).
#define MS2_GE_OUT(out) (*reinterpret_cast<COutputStream*>(out))
#define MS2_GE_IN(in) (*reinterpret_cast<CInputStream*>(&(in)->reader))
#ifdef __clang__
#define MS2_GE_R(in) (reinterpret_cast<Unk_GEReader*>(reinterpret_cast<char*>(in) + 8))
#else
#define MS2_GE_R(in) (&(in)->reader)
#endif

// Out-of-unit helpers.
// Stream operators of CMsTime (packet.cpp).
class COutputStream& WriteMsTime(class COutputStream&, struct Unk_OSNumber const&);   // C3: was FUN_14070fb70
// ... of CStringW.
COutputStream& WriteUnicodeString(COutputStream& out, const CStringW& str);
// ... of unsigned.
COutputStream& FUN_14070f9a0(COutputStream& out, unsigned value);
// String field parsers (commonutil).
int FUN_140718200(const CStringW& text);                                      // int
int FUN_1407181a0(const CStringW& text);
bool FUN_1407183f0(const CStringW& text);                                     // bool
void FUN_140274fc0(CStringW& text, void* ids, const wchar_t* delims);
void FUN_1402928e0(const CStringW& text, ATL::CAtlArray<float>& values, const wchar_t* delims);
void ParseIntArray(CStringW& text, ATL::CAtlArray<int>& values, const wchar_t* delims);
bool FUN_14081dcd0(int nSaType);                                        // the SA value is a percent
void* GetGameRule();   // C3: was GetGameRule
TiXmlElement * FUN_140345b40(TiXmlDocument *);  // C3: the definition's signature
int FUN_1401d9a00(const CStringW& text);                                    // a token as int
// The dungeon open period value (gameeventvalue.cpp): registers / removes a dungeon tag's open period.
class CGameEventValueDungeonOpenPeriod   // C3: unit-local view (gameeventvalue.h; the former free stand-ins)
{
public:
    bool Add(CStringW strTag, __int64 beginTime, __int64 endTime);   // 0x140427690
    void Remove(CStringW strTag);   // 0x140427780
};
// The guild rate values (gameeventvalue.cpp): set / get the event rate.
class CGameEventValueGuildSkillSale   // C3: member view for the former free stand-ins
{
public:
    void SetRate(int);
};
class CGameEventValueGuildPersonalSkillSale   // C3: member view for the former free stand-ins
{
public:
    void SetRate(int);
};
class CGameEventValueGuildExp   // C3: unit-local view (gameeventvalue.h; the former free stand-ins)
{
public:
    int GetRate();   // 0x140423670
    void SetRate(int rate);   // 0x1404236c0
};
class CGameEventValueGuildFund   // C3: member view for the former free stand-ins
{
public:
    void SetRate(int);
};
class CGameEventValueGuildCoin   // C3: member view for the former free stand-ins
{
public:
    void SetRate(int);
};
// ... the mastery reward / reduce and merat market tab values.
class CGameEventValueMasteryReward   // C3: member view for the former free stand-ins
{
public:
    void Load(unsigned long, int, const CStringW&);
    void Remove(unsigned long);
};
class CGameEventValueMeratMarketOpenTab   // C3: member view for the former free stand-in
{
public:
    void SetTab(const CStringW&);
};
class CGameEventValueMasteryReduce   // C3: member view for the former free stand-ins
{
public:
    void SetRate(int);
};
class CGameEventValueSaleItemsRestricted   // C3: member view for the former free stand-ins
{
public:
    void SetItems(ATL::CAtlArray<unsigned>&);
    void Clear();
};
// The table attribute readers with a default (adventureleveltablehelper.cpp).
int FUN_140197350(TiXmlElement* pElem, const char* pszName, int nDefault);
unsigned FUN_140197390(TiXmlElement* pElem, const char* pszName, unsigned nDefault);
class CGameEventValueItemBox   // C3: unit-local view (gameeventvalue.h; the former free stand-ins)
{
public:
    bool Add(MS2Ptr<ItemBoxEventContext> spContext);   // 0x1404246b0
    void Remove(MS2Ptr<ItemBoxEventContext> spContext);   // 0x1404247e0
};
// The shut down interact objects (shutdownevent): add / remove one (field id, object id).
// The shut down function items (shutdownevent): add / remove one item id.
void FUN_14025a680(CStringW& src, ATL::CAtlArray<CStringW>& out, const wchar_t* pszSep);   // split (commonstringtable.cpp)
// The dungeon helper bonus value: set / reset the rate.
class CGameEventValueDungeonHelperBonus   // C3: member view for the former free stand-ins
{
public:
    void Add(int);
    void Sub(int);
};
// The battle pet spawn values: add / remove the event's spawn list (type 0 / type 1).
class CGameEventValueBattlePetSpawn   // C3: unit-local view (gameeventvalue.h; the former free stand-ins)
{
public:
    void AddSpawn(int eventId, const CStringW& strValues);          // 0x1404255b0
    void RemoveSpawn(int eventId, const CStringW& strValues);       // 0x140425f40
    void AddImprove(unsigned eventId, const CStringW& strValues);   // 0x140426380
    void RemoveImprove(int eventId, const CStringW& strValues);     // 0x1404266f0
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, class CMsTime&);   // C3: was FUN_140873600
bool FUN_1407d1c30(CShutdownEventBillboard *, unsigned int);  // C3: the definition's signature
void FUN_1407d1ca0(CShutdownEventBillboard *, unsigned int);  // C3: the definition's signature
bool FUN_1407d1d90(CShutdownEventUGCBanner *, unsigned int);  // C3: the definition's signature
void FUN_1407d1e00(CShutdownEventUGCBanner *, unsigned int);  // C3: the definition's signature
class CGameEventValuePublicTest   // C3: member view for the former free stand-ins
{
public:
    void SetValue(int);
};
class CGameEventValueBurningLevelup   // C3: unit-local view (gameeventvalue.h; the former free stand-ins)
{
public:
    void Add(MS2Ptr<BurningLevelupContext> spContext);   // 0x1404283e0
    void Remove(MS2Ptr<BurningLevelupContext> spContext);   // 0x1404284a0
};
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int FUN_1407181a0(const CStringW& str);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringW FUN_1401bf530(TiXmlElement* pElem, const char* pszName, CStringW strDefault);  // string attribute or default
CString FUN_1401d4330(const wchar_t* pszWide, int nCodePage);                      // wide to multibyte
CMsTime FUN_140718950(const CString& str);                                          // a date string
__int64 GetServerTime();                                                            // server time
class CGameEventValueFestival   // C3: member view for the former free stand-ins
{
public:
    void Add(unsigned, MS2Ptr<FestivalContext>);
    void Remove(unsigned int);
};
class CGameEventValueCoupleDance   // C3: member view for the former free stand-in
{
public:
    void Set(MS2Ptr<CoupleDanceContext>);
};
class CGameEventValueFieldEffect   // C3: member view for the former free stand-in
{
public:
    void Set(MS2Ptr<FieldEffectContext>);
};
class CGameEventValueExchangeScrollSale   // C3: member view for the former free stand-ins
{
public:
    void Remove(unsigned long);
    void Set(unsigned long, int);
};
void FUN_14025a680(const CStringW& text, ATL::CAtlArray<CStringW>& tokens, const wchar_t* delims);
// The item trade restriction value (gameeventvalue.cpp; the names are RTTI).
class CGameEventValueItemTradeRestriction {
public:
    class RestrictionData : public CPtred {
    public:
        RestrictionData();                                                                      // 0x140428f00
        void SetLimit(Unk_ItemTradeRestrictionType eType, unsigned nItemId, unsigned short nLimit);   // add a rule
        char m_pad_18[0x1b0];
    };
public:
    void Add(unsigned, const MS2Ptr<RestrictionData>&);
    void Remove(unsigned int);   // C3: was free FUN_1404293a0
};
MS2_CHECK_SIZE(CGameEventValueItemTradeRestriction::RestrictionData, 0x1c8);
class CGameEventValueCollectItemGroup   // C3: unit-local view (gameeventvalue.h; the former free stand-ins)
{
public:
    void Add(MS2Ptr<CollectItemGroupContext> spContext);   // 0x140429770
    void Remove(MS2Ptr<CollectItemGroupContext> spContext);   // 0x140429830
};
class CGameEventValueArcadeOpen   // C3: unit-local view (gameeventvalue.h; the former free stand-ins)
{
public:
    bool Add(MS2Ptr<ArcadeOpenContext> spContext);   // 0x140429a30
    void Remove(MS2Ptr<ArcadeOpenContext> spContext);   // 0x140429b80
};
class CGameEventValueBingo   // C3: unit-local view (gameeventvalue.h; the former free stand-ins)
{
public:
    void Set(MS2Ptr<BingoContext> spContext);   // 0x140429d00
    void Clear(MS2Ptr<BingoContext> spContext);   // 0x140429d90
};
int FUN_140873420(TiXmlElement* pElem, const char* pszName, CStringW& rOut);
class CGameEventValueStarShop   // C3: member view for the former free stand-ins
{
public:
    void SetValue(int);
};
int CompareRpsReward(const void* a, const void* b); // qsort order of the rps rewards (gameeventcontext.cpp)
// The npc shop values (gameeventvalue.cpp): set / reset the event's entry.
class CGameEventValueNpcShopTalk   // C3: member view for the former free stand-ins
{
public:
    void Remove(unsigned int);
    void Set(unsigned int, unsigned int);
};
class CGameEventValueNpcShopGivePoint   // C3: member view for the former free stand-ins
{
public:
    void Set(unsigned, MS2Ptr<CNpcShopGivePointContextBase>);
    void Remove(unsigned int);
};
class CGameEventValueNpcShopResetPriceSale   // C3: member view for the former free stand-ins
{
public:
    void Remove(unsigned int);
    void Set(unsigned int, unsigned int);
};
unsigned __int64 FUN_140718370(const CStringW& text);                         // unsigned __int64
CStringW FUN_140718600(const CStringW& value);                         // copy
// The UGC cube palette (ugccubepalette.cpp): the show-item box.
unsigned AddBoxById(unsigned nArgA, unsigned nArgB);
unsigned AddBoxByName(CStringW strName, unsigned nArg);
void FUN_140df1f40(unsigned nBox, unsigned nItemId);
void RemoveBox(unsigned nBox);
// The feature switches (featuremanager): whether feature `nId` is on.
// The common log (GetLogString()).
class Unk_CommonLog : public CLogString
{
public:
    void Log(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* message);
};
class CLogString* GetLogString();
int Parse_14021bc30(const CStringA& value);    // commonenum.cpp

// The event factories (registered by name below each class).
GameEvent* FUN_1403bb510();
GameEvent* CreateGameEventSAHotTime();
GameEvent* CreateGameEventPCBangSAHotTime();
GameEvent* CreateGameEventSaleBeautyShop();
GameEvent* CreateGameEventUserCondition();
GameEvent* CreateGameEventMesoRevival();
GameEvent* CreateGameEventItemBuff();
GameEvent* CreateGameEventDungeonBonusReward();
GameEvent* CreateGameEventFreeAirTaxi();
GameEvent* CreateGameEventOntime();
GameEvent* CreateGameEventSaleEnchant();
GameEvent* CreateGameEventQuestTag();
GameEvent* CreateGameEventBlackMarketFeeDiscount();
GameEvent* CreateGameEventUGCMapSaleCoupon();
GameEvent* CreateGameEventPremiumMarketSale();
GameEvent* CreateGameEventGameMenuPopup();
GameEvent* CreateGameEventEventFieldPopup();
GameEvent* CreateGameEventSaleAutoFishing();
GameEvent* CreateGameEventSaleAutoPlayInstrument();
GameEvent* CreateGameEventTrafficOptimizer();
GameEvent* FUN_1403bff70();
GameEvent* FUN_1403c0290();
GameEvent* FUN_1403c0690();
GameEvent* FUN_1403c0990();
GameEvent* FUN_1403c10e0();
GameEvent* FUN_1403c13e0();
GameEvent* FUN_1403c1560();
GameEvent* FUN_1403c1e00();
GameEvent* FUN_1403c2260();
GameEvent* FUN_1403c2b80();
GameEvent* FUN_1403c2d00();
GameEvent* FUN_1403c2f60();
GameEvent* FUN_1403c33f0();
GameEvent* FUN_1403c3ba0();
GameEvent* FUN_1403c40f0();
GameEvent* FUN_1403c4410();
GameEvent* FUN_1403c4680();
GameEvent* FUN_1403c50c0();
GameEvent* FUN_1403c51b0();
GameEvent* FUN_1403c5b40();
GameEvent* FUN_1403c6110();
GameEvent* FUN_1403c65c0();
GameEvent* FUN_1403c68a0();
GameEvent* FUN_1403c6a80();
GameEvent* FUN_1403c6e80();
GameEvent* FUN_1403c70f0();
GameEvent* FUN_1403c7360();
GameEvent* FUN_1403c7640();
GameEvent* FUN_1403c78b0();
GameEvent* FUN_1403c7b20();
GameEvent* FUN_1403c7e80();
GameEvent* FUN_1403c81a0();
GameEvent* FUN_1403c8400();
GameEvent* FUN_1403c8660();
GameEvent* FUN_1403c88d0();
GameEvent* FUN_1403c8b40();
GameEvent* FUN_1403c9190();
GameEvent* FUN_1403c9430();
GameEvent* FUN_1403c9720();
GameEvent* FUN_1403c9b20();
GameEvent* FUN_1403c9d90();
GameEvent* FUN_1403ca200();
GameEvent* FUN_1403ca470();
GameEvent* FUN_1403ca6e0();
GameEvent* FUN_1403cabf0();
GameEvent* FUN_1403cb1c0();
GameEvent* FUN_1403cb6f0();
GameEvent* FUN_1403cbbf0();
GameEvent* FUN_1403cbed0();
GameEvent* FUN_1403cc130();
GameEvent* FUN_1403cc2b0();
GameEvent* FUN_1403cc6c0();
GameEvent* FUN_1403ccaf0();
GameEvent* FUN_1403cd5e0();
GameEvent* FUN_1403cd970();
GameEvent* FUN_1403cdbe0();
GameEvent* FUN_1403ce7c0();
GameEvent* FUN_1403cf130();
GameEvent* FUN_1403cf400();
GameEvent* FUN_1403cf820();
GameEvent* FUN_1403cfb10();
GameEvent* FUN_1403d0090();
GameEvent* FUN_1403d03f0();
GameEvent* FUN_1403d1240();
GameEvent* FUN_1403d13e0();
GameEvent* FUN_1403d1580();
GameEvent* FUN_1403d16f0();
GameEvent* FUN_1403d1960();
GameEvent* FUN_1403d2930();
GameEvent* FUN_1403d3010();
GameEvent* FUN_1403d3570();
GameEvent* FUN_1403d3ae0();
GameEvent* FUN_1403d3f50();
GameEvent* FUN_1403d47f0();
GameEvent* FUN_1403d4e30();
GameEvent* FUN_1403d50e0();
GameEvent* FUN_1403d5350();
GameEvent* FUN_1403d5900();
GameEvent* FUN_1403d5f10();
GameEvent* FUN_1403d6050();
GameEvent* FUN_1403d6980();
GameEvent* FUN_1403d6ae0();

// Shared header statics (sort names, condition strings).
static CStringA s_sortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");

// MS2Ptr streaming (count-free: the pointee's own operator, a fresh object on read).
template <class T> COutputStream& operator<<(COutputStream& out, const MS2Ptr<T>& sp)
{
    out << *sp;
    return out;
}
template <class T> CInputStream& operator>>(CInputStream& in, MS2Ptr<T>& sp)
{
    sp.AssignRaw(new T);
    in >> *sp;
    return in;
}

// CAtlMap streaming: the count, then key / value pairs.
template <class K, class V, class KTraits, class VTraits>
COutputStream& operator<<(COutputStream& out, ATL::CAtlMap<K, V, KTraits, VTraits>& map)
{
    out.WriteInt32((int)map.GetCount());
    for (POSITION pos = map.GetStartPosition(); pos != NULL; map.GetNext(pos))
    {
        FUN_14070f9a0(out, map.GetKeyAt(pos));
        out << map.GetValueAt(pos);
    }
    return out;
}
template <class K, class V, class KTraits, class VTraits>
CInputStream& operator>>(CInputStream& in, ATL::CAtlMap<K, V, KTraits, VTraits>& map)
{
    unsigned nCount = in.ReadInt32();
    for (unsigned i = 0; i < nCount; ++i)
    {
        V value;
        K key;
        reinterpret_cast<CInputStream&>(reinterpret_cast<Unk_OSInput&>(in).Read6(key)) >> value;
        map.SetAt(key, value);
    }
    return in;
}

// CRBMap streaming (of strings): the count, then key / value pairs.
template <class K, class V, class KTraits, class VTraits>
COutputStream& operator<<(COutputStream& out, ATL::CRBMap<K, V, KTraits, VTraits>& map)
{
    out.WriteInt32((int)map.GetCount());
    for (POSITION pos = map.GetHeadPosition(); pos != NULL; map.GetNext(pos))
    {
        WriteUnicodeString(out, map.GetKeyAt(pos));
        WriteUnicodeString(out, map.GetValueAt(pos));
    }
    return out;
}
template <class K, class V, class KTraits, class VTraits>
CInputStream& operator>>(CInputStream& in, ATL::CRBMap<K, V, KTraits, VTraits>& map)
{
    unsigned nCount = in.ReadInt32();
    for (unsigned i = 0; i < nCount; ++i)
    {
        K key;
        V value;
        reinterpret_cast<Unk_OSInput&>(in).Read11(key).Read11(value);
        map.SetAt(key, value);
    }
    return in;
}

// CAtlArray streaming: the count, then the elements.
template <class T>
COutputStream& operator<<(COutputStream& out, const ATL::CAtlArray<T>& arr)
{
    out.WriteInt32((int)arr.GetCount());
    for (size_t i = 0; i < arr.GetCount(); i++)
        FUN_14070f9a0(out, arr[i]);
    return out;
}
template <class T>
CInputStream& operator>>(CInputStream& in, ATL::CAtlArray<T>& arr)
{
    unsigned nCount = in.ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        T value;
        reinterpret_cast<Unk_OSInput&>(in).Read6(value);
        arr.Add(value);
    }
    return in;
}

// The set flavour of the token splitters above (ParseIntArray & co.): every token, as int, into the set.
template <class T>
void FUN_1403d8040(CStringW& text, std::set<T>& values, const wchar_t* delims)
{
    int nPos = 0;
    CStringW strToken = text.Tokenize(delims, nPos);
    while (!strToken.IsEmpty())
    {
        values.insert(FUN_1401d9a00(strToken));
        strToken = text.Tokenize(delims, nPos);
    }
}

// Count-prefixed streaming of a vector of contexts (their Write / Read members).
template <class T> void operator<<(COutputStream& out, std::vector<MS2Ptr<T> >& vec)
{
    out.WriteInt32((int)vec.size());
    for (typename std::vector<MS2Ptr<T> >::iterator it = vec.begin(); it != vec.end(); it++)
    {
        MS2Ptr<T>& sp = *it;
        sp->Write(out);
    }
}
template <class T> void operator>>(CInputStream& in, std::vector<MS2Ptr<T> >& vec)
{
    unsigned nCount = in.ReadInt32();
    vec.reserve(nCount);
    for (unsigned i = 0; i < nCount; i++)
    {
        MS2Ptr<T> sp(new T);
        sp->Read(in);
        vec.push_back(sp);
    }
}

// commonutil.h's generic token converter: a type without a converter asserts and stays default-constructed.
template <> inline Unk_DayTime XmlConvert<Unk_DayTime>(const CString& str)
{
    (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.h", 159), 0));
    return Unk_DayTime();
}

// An "a-b" attribute into a range (any other token count fails with TIXML_WRONG_TYPE, 2).
template <class T> int XmlValueRange(TiXmlElement* pElem, const char* pszName, T& range)
{
    CString str;
    int nRet = XmlGetAttr((class TiXmlElement*)(pElem), pszName, str);
    if (nRet == 0)
    {
        ATL::CAtlArray<typename T::ValueType> values;
        XmlSplit(str, values, "-");
        if (values.GetCount() != 2)
            return 2;
        range.Init(values[0], values[1]);
    }
    return nRet;
}

// ---- GameEventSaleChat ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleChat(L"GameEventSaleChat", (ClassObjectCreateFn)FUN_1403bb510);
#endif
// @0x1403bb510
GameEvent* FUN_1403bb510() { return new GameEventSaleChat; }

// @0x1403bb570
CStringW GameEventSaleChat::GetTypeName() { return CStringW(L"GameEventSaleChat"); }
MS2_REPLACE_METHOD(0x1403BB570, GameEventSaleChat, GetTypeName, 61, 0xDAB9D4B6);

// @0x1403bb5c0
GameEventSaleChat::GameEventSaleChat()
{
    m_d0 = 10000;
    m_d4 = 10000;
    m_d8 = 10000;
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bb650
void GameEventSaleChat::vfunc_2()
{
    m_d4 = FUN_140718200(m_68);
    m_d8 = FUN_140718200(m_70);
}
MS2_REPLACE_METHOD(0x1403BB650, GameEventSaleChat, vfunc_2, 70, 0x710F8703);

// @0x1403bb6a0
void GameEventSaleChat::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d4);
    out->WriteInt(m_d8);
}
MS2_REPLACE_METHOD(0x1403BB6A0, GameEventSaleChat, vfunc_3, 88, 0x8512DCB2);

// @0x1403bb700
void GameEventSaleChat::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d4 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BB700, GameEventSaleChat, vfunc_4, 124, 0x5A130818);

// @0x1403bb790
void GameEventSaleChat::OnStart() { ((class CGameRule*)GetGameRule())->SetChatMeratRates(m_id, m_d0, m_d4, m_d8); }
MS2_REPLACE_METHOD(0x1403BB790, GameEventSaleChat, OnStart, 74, 0xA2845D21);

// @0x1403bb7e0
void GameEventSaleChat::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveChatMeratRates(m_id); }
MS2_REPLACE_METHOD(0x1403BB7E0, GameEventSaleChat, vfunc_6, 35, 0x24F80A7E);

// @0x1403bb810
__int64 FUN_1403bb810() { return ((class CGameRule*)GetGameRule())->GetSuperChatMeratCost(); }
MS2_REPLACE(0x1403BB810, FUN_1403bb810, 22, 0x5F8463DB);
// @0x1403bb830
int GetWorldChatMeratCost() { return (int)((class CGameRule*)GetGameRule())->GetWorldChatMeratCost(); }
MS2_REPLACE(0x1403BB830, GetWorldChatMeratCost, 22, 0x75EBD94B);
// @0x1403bb850
int GetChannelChatMeratCost() { return (int)((class CGameRule*)GetGameRule())->GetChannelChatMeratCost(); }
MS2_REPLACE(0x1403BB850, GetChannelChatMeratCost, 22, 0xB3D82860);
// @0x1403bb870
unsigned FUN_1403bb870() { return *GetClientConstants()->MeratConsumeSuperChat.Get(); }
MS2_REPLACE(0x1403BB870, FUN_1403bb870, 30, 0x8D4E122B);
// @0x1403bb8a0
unsigned FUN_1403bb8a0() { return *GetClientConstants()->MeratConsumeWorldChat.Get(); }
MS2_REPLACE(0x1403BB8A0, FUN_1403bb8a0, 30, 0xA8A84703);
// @0x1403bb8d0
unsigned FUN_1403bb8d0() { return *GetClientConstants()->MeratConsumeChannelChat.Get(); }
MS2_REPLACE(0x1403BB8D0, FUN_1403bb8d0, 30, 0xAE9B7E9B);

// ---- GameEventSAHotTime ---------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSAHotTime(L"GameEventSAHotTime", (ClassObjectCreateFn)CreateGameEventSAHotTime);
#endif
// @0x1403bb900
GameEvent* CreateGameEventSAHotTime() { return new GameEventSAHotTime; }

// @0x1403bb960
CStringW GameEventSAHotTime::GetTypeName() { return CStringW(L"GameEventSAHotTime"); }
MS2_REPLACE_METHOD(0x1403BB960, GameEventSAHotTime, GetTypeName, 61, 0xDFFD3206);

// @0x1403bb9b0
GameEventSAHotTime::GameEventSAHotTime() : m_e8(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bba50
void GameEventSAHotTime::vfunc_2()
{
    ATL::CAtlArray<unsigned> ids;
    FUN_140274fc0(m_68, &ids, L",");
    ATL::CAtlArray<float> values;
    FUN_1402928e0(m_70, values, L",");
    if (ids.GetCount() != values.GetCount())
        return;
    for (unsigned i = 0; i < ids.GetCount(); i++) {
        unsigned id = ids[i];
        if (FUN_14081dcd0(id))
            m_d0[id] = (int)(values[i] * 1000.0f);
        else
            m_d0[id] = (int)values[i];
    }
    m_e0 = m_80;
    m_e0.Replace(L"\\n", L"\n");
}
MS2_REPLACE_METHOD(0x1403BBA50, GameEventSAHotTime, vfunc_2, 512, 0x37C33D68);

// @0x1403bbc60
void GameEventSAHotTime::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_68);
    out->WriteStringW(m_70);
    out->WriteStringW(m_78);
    out->WriteStringW(m_80);
}
MS2_REPLACE_METHOD(0x1403BBC60, GameEventSAHotTime, vfunc_3, 188, 0x924F9839);

// @0x1403bbd30
void GameEventSAHotTime::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_68 = MS2_GE_R(in)->ReadStringW();
    m_70 = MS2_GE_R(in)->ReadStringW();
    m_78 = MS2_GE_R(in)->ReadStringW();
    m_80 = MS2_GE_R(in)->ReadStringW();
    vfunc_2();
}
MS2_REPLACE_METHOD(0x1403BBD30, GameEventSAHotTime, vfunc_4, 498, 0x00EAE5C2);

// @0x1403bbf30
void GameEventSAHotTime::OnStart()
{
    MS2Ptr<SAHotTimeEventContext> spContext(new SAHotTimeEventContext);
    spContext->m_18 = m_d0;
    spContext->m_28 = m_e0;
    spContext->m_30 = m_e8;
    ((class CGameRule*)GetGameRule())->AddHotTimeEvent(GetID(), spContext);
    ((class CGameRule*)GetGameRule())->FUN_14047d820(GetID(), m_80);
}
MS2_REPLACE_METHOD(0x1403BBF30, GameEventSAHotTime, OnStart, 392, 0x94BE1A07);

// @0x1403bc0c0
void GameEventSAHotTime::vfunc_6()
{
    ((class CGameRule*)GetGameRule())->RemoveHotTimeEvent(GetID());
    ((class CGameRule*)GetGameRule())->FUN_14047d900(GetID());
}
MS2_REPLACE_METHOD(0x1403BC0C0, GameEventSAHotTime, vfunc_6, 80, 0xE280C0AD);

// ---- GameEventPCBangSAHotTime ---------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regPCBangSAHotTime(L"GameEventPCBangSAHotTime", (ClassObjectCreateFn)CreateGameEventPCBangSAHotTime);
#endif
// @0x1403bc120
GameEvent* CreateGameEventPCBangSAHotTime() { return new GameEventPCBangSAHotTime; }

// @0x1403bc180
CStringW GameEventPCBangSAHotTime::GetTypeName() { return CStringW(L"GameEventPCBangSAHotTime"); }
MS2_REPLACE_METHOD(0x1403BC180, GameEventPCBangSAHotTime, GetTypeName, 61, 0xD5AE5269);

// @0x1403bc1d0
GameEventPCBangSAHotTime::GameEventPCBangSAHotTime() { m_e8 = 1; }

// ---- GameEventSaleBeautyShop ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleBeautyShop(L"GameEventSaleBeautyShop", (ClassObjectCreateFn)CreateGameEventSaleBeautyShop);
#endif
// @0x1403bc220
GameEvent* CreateGameEventSaleBeautyShop() { return new GameEventSaleBeautyShop; }

// @0x1403bc280
CStringW GameEventSaleBeautyShop::GetTypeName() { return CStringW(L"GameEventSaleBeautyShop"); }
MS2_REPLACE_METHOD(0x1403BC280, GameEventSaleBeautyShop, GetTypeName, 61, 0xB261509F);

// @0x1403bc2d0
GameEventSaleBeautyShop::GameEventSaleBeautyShop() : m_d4(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bc340
void GameEventSaleBeautyShop::vfunc_2()
{
    m_d0 = FUN_1407181a0(m_68);
    m_d4 = FUN_140718200(m_70);
    m_d8 = FUN_1407181a0(m_78);
}
MS2_REPLACE_METHOD(0x1403BC340, GameEventSaleBeautyShop, vfunc_2, 98, 0x965E1866);

// @0x1403bc3b0
void GameEventSaleBeautyShop::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteInt(m_d4);
    out->WriteByte((unsigned char)m_d8);
}
MS2_REPLACE_METHOD(0x1403BC3B0, GameEventSaleBeautyShop, vfunc_3, 116, 0xEA691A38);

// @0x1403bc430
void GameEventSaleBeautyShop::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d4 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadByte();
}
MS2_REPLACE_METHOD(0x1403BC430, GameEventSaleBeautyShop, vfunc_4, 172, 0x5BC6B538);

// @0x1403bc4f0
void GameEventSaleBeautyShop::OnStart()
{
    BOOL bOn = m_d8 ? FALSE : TRUE;
    ((class CGameRule*)GetGameRule())->SetBeautyShopSaleEvent(m_d0, m_d4, bOn);
}
MS2_REPLACE_METHOD(0x1403BC4F0, GameEventSaleBeautyShop, OnStart, 95, 0x590385D4);

// @0x1403bc560
void GameEventSaleBeautyShop::vfunc_6()
{
    BOOL bOn = m_d8 ? FALSE : TRUE;
    ((class CGameRule*)GetGameRule())->RemoveBeautyShopSaleEvent(m_d0, bOn);
}
MS2_REPLACE_METHOD(0x1403BC560, GameEventSaleBeautyShop, vfunc_6, 83, 0x3BB39145);

// ---- GameEventUserCondition -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regUserCondition(L"GameEventUserCondition", (ClassObjectCreateFn)CreateGameEventUserCondition);
#endif
// @0x1403bc5c0
GameEvent* CreateGameEventUserCondition() { return new GameEventUserCondition; }

// @0x1403bc620
CStringW GameEventUserCondition::GetTypeName() { return CStringW(L"GameEventUserCondition"); }
MS2_REPLACE_METHOD(0x1403BC620, GameEventUserCondition, GetTypeName, 61, 0x1E4F1C4B);

// @0x1403bc670
GameEventUserCondition::GameEventUserCondition() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bc6f0
void GameEventUserCondition::vfunc_2()
{
    m_d0 = FUN_140718200(m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403BC6F0, GameEventUserCondition, vfunc_2, 72, 0x3D34AC18);

// @0x1403bc740
void GameEventUserCondition::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403BC740, GameEventUserCondition, vfunc_3, 101, 0x69E749FB);

// @0x1403bc7b0
void GameEventUserCondition::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403BC7B0, GameEventUserCondition, vfunc_4, 179, 0x9603FC7B);

// @0x1403bc870
void GameEventUserCondition::OnStart()
{
    if (m_d0 == 0)
        return;
    ((class CGameRule*)GetGameRule())->SetUserConditionText(m_d0, m_d8);
}
MS2_REPLACE_METHOD(0x1403BC870, GameEventUserCondition, OnStart, 119, 0xA883B333);

// @0x1403bc8f0
void GameEventUserCondition::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveUserCondition(m_d0); }
MS2_REPLACE_METHOD(0x1403BC8F0, GameEventUserCondition, vfunc_6, 38, 0x6A98F778);

// ---- GameEventMesoRevival -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regMesoRevival(L"GameEventMesoRevival", (ClassObjectCreateFn)CreateGameEventMesoRevival);
#endif
// @0x1403bc920
GameEvent* CreateGameEventMesoRevival() { return new GameEventMesoRevival; }

// @0x1403bc980
CStringW GameEventMesoRevival::GetTypeName() { return CStringW(L"GameEventMesoRevival"); }
MS2_REPLACE_METHOD(0x1403BC980, GameEventMesoRevival, GetTypeName, 61, 0xED673EBF);

// @0x1403bc9d0
GameEventMesoRevival::GameEventMesoRevival() : m_d0(false)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bca40
void GameEventMesoRevival::vfunc_2() { m_d0 = FUN_1407183f0(m_68); }
MS2_REPLACE_METHOD(0x1403BCA40, GameEventMesoRevival, vfunc_2, 42, 0xACBF923C);

// @0x1403bca70
void GameEventMesoRevival::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteBool(m_d0);
}
MS2_REPLACE_METHOD(0x1403BCA70, GameEventMesoRevival, vfunc_3, 61, 0x34D82FAC);

// @0x1403bcac0
void GameEventMesoRevival::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadBool();
}
MS2_REPLACE_METHOD(0x1403BCAC0, GameEventMesoRevival, vfunc_4, 78, 0xD08AD047);

// @0x1403bcb20
void GameEventMesoRevival::OnStart()
{
    MS2Ptr<MesoRevivalEventContext> spContext(new MesoRevivalEventContext);
    spContext->m_18 = m_d0;
    ((class CGameRule*)GetGameRule())->AddMesoRevivalEvent(GetID(), spContext);
}
MS2_REPLACE_METHOD(0x1403BCB20, GameEventMesoRevival, OnStart, 233, 0x23BFF202);

// @0x1403bcc10
void GameEventMesoRevival::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveMesoRevivalEvent(GetID()); }
MS2_REPLACE_METHOD(0x1403BCC10, GameEventMesoRevival, vfunc_6, 47, 0xB874E1D4);

// ---- GameEventItemBuff ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regItemBuff(L"GameEventItemBuff", (ClassObjectCreateFn)CreateGameEventItemBuff);
#endif
// @0x1403bcc50
GameEvent* CreateGameEventItemBuff() { return new GameEventItemBuff; }

// @0x1403bccb0
CStringW GameEventItemBuff::GetTypeName() { return CStringW(L"GameEventItemBuff"); }
MS2_REPLACE_METHOD(0x1403BCCB0, GameEventItemBuff, GetTypeName, 61, 0xC4330E28);

// @0x1403bcd00
GameEventItemBuff::GameEventItemBuff() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bcd70
void GameEventItemBuff::vfunc_2()
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_70) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    CStringW strType;
    XmlGetAttr((class TiXmlElement*)(pRoot), "type", strType);
    m_d0 = ((class GameEventUserValueNameTable*)(class GameEventUserValueNameTable*)(TSingleton<GameEventUserValueNameTable>::GetInstance()))->GetId(strType);
}

// @0x1403bce90
void GameEventItemBuff::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403BCE90, GameEventItemBuff, vfunc_3, 61, 0x02BF481F);

// @0x1403bcee0
void GameEventItemBuff::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BCEE0, GameEventItemBuff, vfunc_4, 79, 0x4F54C1BA);

// @0x1403bcf40
void GameEventItemBuff::OnStart() { ((class CGameRule*)GetGameRule())->SetItemBuffType(m_d0); }
MS2_REPLACE_METHOD(0x1403BCF40, GameEventItemBuff, OnStart, 38, 0xD20048DD);

// @0x1403bcf70
void GameEventItemBuff::vfunc_6() { ((class CGameRule*)GetGameRule())->SetItemBuffType(0); }
MS2_REPLACE_METHOD(0x1403BCF70, GameEventItemBuff, vfunc_6, 29, 0x534100EE);

// ---- GameEventDungeonBonusReward ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regDungeonBonusReward(L"GameEventDungeonBonusReward", (ClassObjectCreateFn)CreateGameEventDungeonBonusReward);
#endif
// @0x1403bcfa0
GameEvent* CreateGameEventDungeonBonusReward() { return new GameEventDungeonBonusReward; }

// @0x1403bd000
CStringW GameEventDungeonBonusReward::GetTypeName() { return CStringW(L"GameEventDungeonBonusReward"); }
MS2_REPLACE_METHOD(0x1403BD000, GameEventDungeonBonusReward, GetTypeName, 61, 0x00D72C52);

// @0x1403bd050
GameEventDungeonBonusReward::GameEventDungeonBonusReward()
{
    SetFlag(1);
    SetFlag(3);
    m_d0.AssignRaw(new DungeonBonusRewardCtx);
}

// @0x1403bd120
void GameEventDungeonBonusReward::vfunc_2()
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    TiXmlElement* pElem = FUN_140345b40((TiXmlDocument *)pRoot);
    if ((m_d0.get() ? true : false) && pElem)
        m_d0->Load(pElem);
}
MS2_REPLACE_METHOD(0x1403BD120, GameEventDungeonBonusReward, vfunc_2, 254, 0x317C6221);

// @0x1403bd230
void GameEventDungeonBonusReward::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    MS2_GE_OUT(out) << m_d0;
}
MS2_REPLACE_METHOD(0x1403BD230, GameEventDungeonBonusReward, vfunc_3, 58, 0x2CE714BB);

// @0x1403bd270
void GameEventDungeonBonusReward::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    MS2_GE_IN(in) >> m_d0;
}
MS2_REPLACE_METHOD(0x1403BD270, GameEventDungeonBonusReward, vfunc_4, 62, 0xCEC9B3E2);

// @0x1403bd2c0
void GameEventDungeonBonusReward::OnStart() { ((class CGameRule*)GetGameRule())->AddDungeonBonusReward(m_d0); }
MS2_REPLACE_METHOD(0x1403BD2C0, GameEventDungeonBonusReward, OnStart, 91, 0xA725C0A7);

// @0x1403bd330
void GameEventDungeonBonusReward::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveDungeonBonusReward(m_d0); }
MS2_REPLACE_METHOD(0x1403BD330, GameEventDungeonBonusReward, vfunc_6, 91, 0x977962AF);

// ---- GameEventFreeAirTaxi -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regFreeAirTaxi(L"GameEventFreeAirTaxi", (ClassObjectCreateFn)CreateGameEventFreeAirTaxi);
#endif
// @0x1403bd3a0
GameEvent* CreateGameEventFreeAirTaxi() { return new GameEventFreeAirTaxi; }

// @0x1403bd400
CStringW GameEventFreeAirTaxi::GetTypeName() { return CStringW(L"GameEventFreeAirTaxi"); }
MS2_REPLACE_METHOD(0x1403BD400, GameEventFreeAirTaxi, GetTypeName, 61, 0x691F423F);

// @0x1403bd450
GameEventFreeAirTaxi::GameEventFreeAirTaxi()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bd4b0
void GameEventFreeAirTaxi::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403BD4B0, GameEventFreeAirTaxi, vfunc_2, 6, 0xA9AF6E37);

// @0x1403bd4c0
void GameEventFreeAirTaxi::vfunc_3(Unk_GEOut* out) { GameEvent::vfunc_3(out); }
MS2_REPLACE_METHOD(0x1403BD4C0, GameEventFreeAirTaxi, vfunc_3, 34, 0xA1F079D6);

// @0x1403bd4f0
void GameEventFreeAirTaxi::vfunc_4(Unk_GEIn* in) { GameEvent::vfunc_4(in); }
MS2_REPLACE_METHOD(0x1403BD4F0, GameEventFreeAirTaxi, vfunc_4, 34, 0x52D23EA6);

// @0x1403bd520
void GameEventFreeAirTaxi::OnStart() { ((class CGameRule*)GetGameRule())->AddFreeAirTaxiEvent(GetID()); }
MS2_REPLACE_METHOD(0x1403BD520, GameEventFreeAirTaxi, OnStart, 47, 0xE1812CAC);

// @0x1403bd560
void GameEventFreeAirTaxi::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveFreeAirTaxiEvent(GetID()); }
MS2_REPLACE_METHOD(0x1403BD560, GameEventFreeAirTaxi, vfunc_6, 47, 0x59FF38BC);

// ---- GameEventOntime ------------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regOntime(L"GameEventOntime", (ClassObjectCreateFn)CreateGameEventOntime);
#endif
// @0x1403bd5a0
GameEvent* CreateGameEventOntime() { return new GameEventOntime; }

// @0x1403bd600
CStringW GameEventOntime::GetTypeName() { return CStringW(L"GameEventOntime"); }
MS2_REPLACE_METHOD(0x1403BD600, GameEventOntime, GetTypeName, 61, 0xB2D5BB00);

// @0x1403bd650
GameEventOntime::GameEventOntime()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bd6c0
void GameEventOntime::vfunc_2()
{
    m_d0 = 0;
    const int nValueCount = 7;
    int nType = FUN_1407181a0(m_68);
    ATL::CAtlArray<int> first;
    ATL::CAtlArray<int> second;
    ParseIntArray(m_70, first, L",");
    ParseIntArray(m_78, second, L",");
    if (first.GetCount() != nValueCount || second.GetCount() != nValueCount)
        return;
    m_d0.AssignRaw(new OntimeEventContext);
    m_d0->m_18 = GetID();
    m_d0->m_20 = nType;
    m_d0->m_24.m_0 = first[0];
    m_d0->m_24.m_4 = first[1];
    m_d0->m_24.m_8 = first[2];
    m_d0->m_24.m_10 = first[3];
    m_d0->m_24.m_c = first[4];
    m_d0->m_24.m_14 = first[5];
    m_d0->m_24.m_18 = first[6];
    m_d0->m_40.m_0 = second[0];
    m_d0->m_40.m_4 = second[1];
    m_d0->m_40.m_8 = second[2];
    m_d0->m_40.m_10 = second[3];
    m_d0->m_40.m_c = second[4];
    m_d0->m_40.m_14 = second[5];
    m_d0->m_40.m_18 = second[6];
}
MS2_REPLACE_METHOD(0x1403BD6C0, GameEventOntime, vfunc_2, 1198, 0x8CF46CE6);

// @0x1403bdb80
void GameEventOntime::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt64(m_38.Get());
}
MS2_REPLACE_METHOD(0x1403BDB80, GameEventOntime, vfunc_3, 80, 0xC494E523);

// @0x1403bdbe0
void GameEventOntime::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_38 = CMsTime(MS2_GE_R(in)->ReadInt64());
}
MS2_REPLACE_METHOD(0x1403BDBE0, GameEventOntime, vfunc_4, 98, 0x459DA96A);

// @0x1403bdc50
void GameEventOntime::OnStart()
{
    if (m_d0.get()) {
        m_d0->m_1c = true;
        ((class CGameRule*)GetGameRule())->AddOntimeEvent(GetID(), m_d0);
    }
}
MS2_REPLACE_METHOD(0x1403BDC50, GameEventOntime, OnStart, 158, 0x302A88DF);

// @0x1403bdd00
void GameEventOntime::vfunc_6() { ((class CGameRule*)GetGameRule())->DeactivateOntimeEvent(GetID()); }
MS2_REPLACE_METHOD(0x1403BDD00, GameEventOntime, vfunc_6, 47, 0xB82BE608);

// ---- GameEventSaleEnchant -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleEnchant(L"GameEventSaleEnchant", (ClassObjectCreateFn)CreateGameEventSaleEnchant);
#endif
// @0x1403bdd40
GameEvent* CreateGameEventSaleEnchant() { return new GameEventSaleEnchant; }

// @0x1403bdda0
CStringW GameEventSaleEnchant::GetTypeName() { return CStringW(L"GameEventSaleEnchant"); }
MS2_REPLACE_METHOD(0x1403BDDA0, GameEventSaleEnchant, GetTypeName, 61, 0x97A44702);

// @0x1403bddf0
GameEventSaleEnchant::GameEventSaleEnchant() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bde60
void GameEventSaleEnchant::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403BDE60, GameEventSaleEnchant, vfunc_2, 42, 0x6531D9DD);

// @0x1403bde90
void GameEventSaleEnchant::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403BDE90, GameEventSaleEnchant, vfunc_3, 61, 0x6C5A016F);

// @0x1403bdee0
void GameEventSaleEnchant::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BDEE0, GameEventSaleEnchant, vfunc_4, 79, 0x936AB3EA);

// @0x1403bdf40
void GameEventSaleEnchant::OnStart() { ((class CGameRule*)GetGameRule())->SetSaleEnchantRate(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403BDF40, GameEventSaleEnchant, OnStart, 47, 0x97CFC059);

// @0x1403bdf80
void GameEventSaleEnchant::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveSaleEnchantRate(m_id); }
MS2_REPLACE_METHOD(0x1403BDF80, GameEventSaleEnchant, vfunc_6, 35, 0x8326983A);

// ---- GameEventQuestTag ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regQuestTag(L"GameEventQuestTag", (ClassObjectCreateFn)CreateGameEventQuestTag);
#endif
// @0x1403bdfb0
GameEvent* CreateGameEventQuestTag() { return new GameEventQuestTag; }

// @0x1403be010
CStringW GameEventQuestTag::GetTypeName() { return CStringW(L"GameEventQuestTag"); }
MS2_REPLACE_METHOD(0x1403BE010, GameEventQuestTag, GetTypeName, 61, 0x4C810B65);

// @0x1403be060
GameEventQuestTag::GameEventQuestTag()
{
    SetFlag(1);
    SetFlag(3);
    m_d8 = 0;
}

// @0x1403be0e0
void GameEventQuestTag::vfunc_2()
{
    m_d0 = m_68;
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_70) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    CStringA strType;
    XmlGetAttr((class TiXmlElement*)(pRoot), "type", strType);
    if (strType == "IsNewCharacter")
        m_d8 = 1;
}
MS2_REPLACE_METHOD(0x1403BE0E0, GameEventQuestTag, vfunc_2, 271, 0x760B8D93);

// @0x1403be200
void GameEventQuestTag::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
    out->WriteInt64(m_28.Get());
    out->WriteInt64(m_38.Get());
}
MS2_REPLACE_METHOD(0x1403BE200, GameEventQuestTag, vfunc_3, 166, 0xC79534CB);

// @0x1403be2b0
void GameEventQuestTag::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
    m_28 = CMsTime(MS2_GE_R(in)->ReadInt64());
    m_38 = CMsTime(MS2_GE_R(in)->ReadInt64());
}
MS2_REPLACE_METHOD(0x1403BE2B0, GameEventQuestTag, vfunc_4, 301, 0xE08C631B);

// @0x1403be3f0
void GameEventQuestTag::OnStart()
{
    MS2Ptr<EventQuestContext> spContext(new EventQuestContext);
    spContext->m_strTag = m_d0;
    spContext->m_beginTime = m_28.Get();
    spContext->m_endTime = m_38.Get();
    if (m_d8 != 0)
        spContext->m_newCharacterTime = m_28.Get();
    ((class CGameRule*)GetGameRule())->AddEventQuest(m_d0, spContext);
}
MS2_REPLACE_METHOD(0x1403BE3F0, GameEventQuestTag, OnStart, 458, 0x480EB6B1);

// @0x1403be5c0
void GameEventQuestTag::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveEventQuest(m_d0); }
MS2_REPLACE_METHOD(0x1403BE5C0, GameEventQuestTag, vfunc_6, 92, 0xF48635F9);

// ---- GameEventBlackMarketFeeDiscount --------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regBlackMarketFeeDiscount(L"GameEventBlackMarketFeeDiscount", (ClassObjectCreateFn)CreateGameEventBlackMarketFeeDiscount);
#endif
// @0x1403be630
GameEvent* CreateGameEventBlackMarketFeeDiscount() { return new GameEventBlackMarketFeeDiscount; }

// @0x1403be690
CStringW GameEventBlackMarketFeeDiscount::GetTypeName() { return CStringW(L"GameEventBlackMarketFeeDiscount"); }
MS2_REPLACE_METHOD(0x1403BE690, GameEventBlackMarketFeeDiscount, GetTypeName, 61, 0x46CBC4E5);

// @0x1403be6e0
GameEventBlackMarketFeeDiscount::GameEventBlackMarketFeeDiscount() : m_d0(-1)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403be750
void GameEventBlackMarketFeeDiscount::vfunc_2() { m_d0 = FUN_1407181a0(m_68); }
MS2_REPLACE_METHOD(0x1403BE750, GameEventBlackMarketFeeDiscount, vfunc_2, 42, 0x57A2105A);

// @0x1403be780
void GameEventBlackMarketFeeDiscount::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    ((class Unk_GEOut*)&WriteMsTime(*(class COutputStream*)(out), *(struct Unk_OSNumber const*)(&m_28)));
    ((class Unk_GEOut*)&WriteMsTime(*(class COutputStream*)(out), *(struct Unk_OSNumber const*)(&m_38)));
}
MS2_REPLACE_METHOD(0x1403BE780, GameEventBlackMarketFeeDiscount, vfunc_3, 105, 0x940F1D10);

// @0x1403be7f0
void GameEventBlackMarketFeeDiscount::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    ((class Unk_GEReader*)&((class Unk_OSInput*)(class Unk_GEReader*)(MS2_GE_R(in)))->Read13(*(struct Unk_OSNumber*)(&m_28)));
    ((class Unk_GEReader*)&((class Unk_OSInput*)(class Unk_GEReader*)(MS2_GE_R(in)))->Read13(*(struct Unk_OSNumber*)(&m_38)));
}
MS2_REPLACE_METHOD(0x1403BE7F0, GameEventBlackMarketFeeDiscount, vfunc_4, 131, 0x2643A841);

// @0x1403be880
void GameEventBlackMarketFeeDiscount::OnStart()
{
    static Unk_GameEventIntRange s_range(0, 10000);
    if (s_range.IsInRange(m_d0))
        ((class CGameRule*)GetGameRule())->SetBlackMarketFeeDiscount(m_d0, m_28.Get(), m_38.Get());
    else
        MS2_ASSERT_AT(MS2_LINE(841), FALSE);
}
MS2_REPLACE_METHOD(0x1403BE880, GameEventBlackMarketFeeDiscount, OnStart, 261, 0x9867204A);

// @0x1403be990
void GameEventBlackMarketFeeDiscount::vfunc_6() { ((class CGameRule*)GetGameRule())->SetBlackMarketFeeDiscount(-1, 0, 0); }
MS2_REPLACE_METHOD(0x1403BE990, GameEventBlackMarketFeeDiscount, vfunc_6, 38, 0x03263CEE);

// ---- GameEventUGCMapSaleCoupon --------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regUGCMapSaleCoupon(L"GameEventUGCMapSaleCoupon", (ClassObjectCreateFn)CreateGameEventUGCMapSaleCoupon);
#endif
// @0x1403be9c0
GameEvent* CreateGameEventUGCMapSaleCoupon() { return new GameEventUGCMapSaleCoupon; }

// @0x1403bea20
CStringW GameEventUGCMapSaleCoupon::GetTypeName() { return CStringW(L"GameEventUGCMapSaleCoupon"); }
MS2_REPLACE_METHOD(0x1403BEA20, GameEventUGCMapSaleCoupon, GetTypeName, 61, 0x3CB71A57);

// @0x1403bea70
GameEventUGCMapSaleCoupon::GameEventUGCMapSaleCoupon() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403beae0
void GameEventUGCMapSaleCoupon::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403BEAE0, GameEventUGCMapSaleCoupon, vfunc_2, 42, 0xC59BB9F9);

// @0x1403beb10
void GameEventUGCMapSaleCoupon::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403BEB10, GameEventUGCMapSaleCoupon, vfunc_3, 61, 0x0116D2EB);

// @0x1403beb60
void GameEventUGCMapSaleCoupon::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BEB60, GameEventUGCMapSaleCoupon, vfunc_4, 79, 0x922BFEA6);

// @0x1403bebc0
void GameEventUGCMapSaleCoupon::OnStart() { ((class CGameRule*)GetGameRule())->SetUgcMapSaleCoupon(m_d0); }
MS2_REPLACE_METHOD(0x1403BEBC0, GameEventUGCMapSaleCoupon, OnStart, 38, 0x0BEE936B);

// @0x1403bebf0
void GameEventUGCMapSaleCoupon::vfunc_6() { ((class CGameRule*)GetGameRule())->SetUgcMapSaleCoupon(0); }
MS2_REPLACE_METHOD(0x1403BEBF0, GameEventUGCMapSaleCoupon, vfunc_6, 29, 0xB67F6FA5);

// ---- GameEventPremiumMarketSale -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regPremiumMarketSale(L"GameEventPremiumMarketSale", (ClassObjectCreateFn)CreateGameEventPremiumMarketSale);
#endif
// @0x1403bec20
GameEvent* CreateGameEventPremiumMarketSale() { return new GameEventPremiumMarketSale; }

// @0x1403bec80
CStringW GameEventPremiumMarketSale::GetTypeName() { return CStringW(L"GameEventPremiumMarketSale"); }
MS2_REPLACE_METHOD(0x1403BEC80, GameEventPremiumMarketSale, GetTypeName, 61, 0x7CD92CF0);

// @0x1403becd0
GameEventPremiumMarketSale::GameEventPremiumMarketSale() : m_d0(0), m_e8(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bed60
void GameEventPremiumMarketSale::vfunc_2()
{
    m_d0 = FUN_1407181a0(m_68);
    FUN_1403d8040(m_70, m_d8, L",");
    m_e8 = FUN_140718200(m_78);
}
MS2_REPLACE_METHOD(0x1403BED60, GameEventPremiumMarketSale, vfunc_2, 105, 0x4B5F2112);

// @0x1403bedd0
void GameEventPremiumMarketSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    int nCount = (int)m_d8.size();
    out->WriteInt(nCount);
    for (std::set<int>::iterator it = m_d8.begin(); it != m_d8.end(); ++it)
        out->WriteInt(*it);
    out->WriteInt(m_e8);
}
MS2_REPLACE_METHOD(0x1403BEDD0, GameEventPremiumMarketSale, vfunc_3, 251, 0x0E68AAD7);

// @0x1403beee0
void GameEventPremiumMarketSale::vfunc_4(Unk_GEIn* in)
{
    m_d8.clear();
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    int nCount = MS2_GE_R(in)->ReadInt();
    for (int i = 0; i < nCount; ++i)
    {
        int nValue = MS2_GE_R(in)->ReadInt();
        m_d8.insert(nValue);
    }
    m_e8 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BEEE0, GameEventPremiumMarketSale, vfunc_4, 280, 0x92747EB6);

// @0x1403bf000
void GameEventPremiumMarketSale::OnStart()
{
    MS2Ptr<PreminmMarketSaleEventContext> pContext(new PreminmMarketSaleEventContext);
    MS2_ASSERT_AT(MS2_LINE(967), pContext != NULL);
    pContext->m_18 = m_d0;
    pContext->m_20.insert(m_d8.begin(), m_d8.end());
    pContext->m_30 = m_e8;
    TSingleton<CShopEventManager>::GetInstance()->AddEvent(GetID(), pContext);
}
MS2_REPLACE_METHOD(0x1403BF000, GameEventPremiumMarketSale, OnStart, 403, 0x7A587F4F);

// @0x1403bf1a0
void GameEventPremiumMarketSale::vfunc_6() { TSingleton<CShopEventManager>::GetInstance()->RemoveEvent(GetID()); }
MS2_REPLACE_METHOD(0x1403BF1A0, GameEventPremiumMarketSale, vfunc_6, 47, 0x06CDE691);

// ---- GameEventGameMenuPopup -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGameMenuPopup(L"GameEventGameMenuPopup", (ClassObjectCreateFn)CreateGameEventGameMenuPopup);
#endif
// @0x1403bf1e0
GameEvent* CreateGameEventGameMenuPopup() { return new GameEventGameMenuPopup; }

// @0x1403bf240
CStringW GameEventGameMenuPopup::GetTypeName() { return CStringW(L"GameEventGameMenuPopup"); }
MS2_REPLACE_METHOD(0x1403BF240, GameEventGameMenuPopup, GetTypeName, 61, 0x0033437C);

// @0x1403bf290
GameEventGameMenuPopup::GameEventGameMenuPopup()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bf300
void GameEventGameMenuPopup::vfunc_2()
{
    m_d0 = FUN_1407181a0(m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403BF300, GameEventGameMenuPopup, vfunc_2, 72, 0x0F93E293);

// @0x1403bf350
void GameEventGameMenuPopup::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteShort(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403BF350, GameEventGameMenuPopup, vfunc_3, 102, 0x0F5613F2);

// @0x1403bf3c0
void GameEventGameMenuPopup::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadShort();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403BF3C0, GameEventGameMenuPopup, vfunc_4, 182, 0x7B83F3DF);

// @0x1403bf480
void GameEventGameMenuPopup::OnStart() {}
MS2_REPLACE_METHOD(0x1403BF480, GameEventGameMenuPopup, OnStart, 6, 0xA9AF6E37);

// @0x1403bf490
void GameEventGameMenuPopup::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403BF490, GameEventGameMenuPopup, vfunc_6, 6, 0xA9AF6E37);

// ---- GameEventEventFieldPopup ---------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regEventFieldPopup(L"GameEventEventFieldPopup", (ClassObjectCreateFn)CreateGameEventEventFieldPopup);
#endif
// @0x1403bf4a0
GameEvent* CreateGameEventEventFieldPopup() { return new GameEventEventFieldPopup; }

// @0x1403bf500
CStringW GameEventEventFieldPopup::GetTypeName() { return CStringW(L"GameEventEventFieldPopup"); }
MS2_REPLACE_METHOD(0x1403BF500, GameEventEventFieldPopup, GetTypeName, 61, 0x2C61EBA3);

// @0x1403bf550
GameEventEventFieldPopup::GameEventEventFieldPopup()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bf5b0
void GameEventEventFieldPopup::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403BF5B0, GameEventEventFieldPopup, vfunc_2, 42, 0x8A9C690C);

// @0x1403bf5e0
void GameEventEventFieldPopup::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403BF5E0, GameEventEventFieldPopup, vfunc_3, 61, 0xFCF00514);

// @0x1403bf630
void GameEventEventFieldPopup::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BF630, GameEventEventFieldPopup, vfunc_4, 79, 0xBAF21AA1);

// @0x1403bf690
void GameEventEventFieldPopup::OnStart() { ((class CGameRule*)GetGameRule())->SetEventFieldPopup(m_d0); }
MS2_REPLACE_METHOD(0x1403BF690, GameEventEventFieldPopup, OnStart, 38, 0x672A21AB);

// @0x1403bf6c0
void GameEventEventFieldPopup::vfunc_6() { ((class CGameRule*)GetGameRule())->SetEventFieldPopup(0); }
MS2_REPLACE_METHOD(0x1403BF6C0, GameEventEventFieldPopup, vfunc_6, 29, 0xB5DD45F9);

// ---- GameEventSaleAutoFishing ---------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleAutoFishing(L"GameEventSaleAutoFishing", (ClassObjectCreateFn)CreateGameEventSaleAutoFishing);
#endif
// @0x1403bf6f0
GameEvent* CreateGameEventSaleAutoFishing() { return new GameEventSaleAutoFishing; }

// @0x1403bf750
CStringW GameEventSaleAutoFishing::GetTypeName() { return CStringW(L"GameEventSaleAutoFishing"); }
MS2_REPLACE_METHOD(0x1403BF750, GameEventSaleAutoFishing, GetTypeName, 61, 0xEA4EBEEE);

// @0x1403bf7a0
GameEventSaleAutoFishing::GameEventSaleAutoFishing()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bf810
void GameEventSaleAutoFishing::vfunc_2()
{
    m_d0 = FUN_140718200(m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403BF810, GameEventSaleAutoFishing, vfunc_2, 72, 0x5F9D833B);

// @0x1403bf860
void GameEventSaleAutoFishing::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403BF860, GameEventSaleAutoFishing, vfunc_3, 101, 0x61DCC76E);

// @0x1403bf8d0
void GameEventSaleAutoFishing::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403BF8D0, GameEventSaleAutoFishing, vfunc_4, 179, 0x96AC65FC);

// @0x1403bf990
void GameEventSaleAutoFishing::OnStart()
{
    ((class CGameRule*)GetGameRule())->FUN_1404798e0(m_d0);
    ((class CGameRule*)GetGameRule())->SetAutoFishingName(m_d8);
}
MS2_REPLACE_METHOD(0x1403BF990, GameEventSaleAutoFishing, OnStart, 116, 0x7E5DA331);

// @0x1403bfa10
void GameEventSaleAutoFishing::vfunc_6()
{
    ((class CGameRule*)GetGameRule())->FUN_1404798e0(0);
    ((class CGameRule*)GetGameRule())->SetAutoFishingName(L"");
}
MS2_REPLACE_METHOD(0x1403BFA10, GameEventSaleAutoFishing, vfunc_6, 100, 0x95274BB3);
// ---- GameEventSaleAutoPlayInstrument --------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleAutoPlayInstrument(L"GameEventSaleAutoPlayInstrument", (ClassObjectCreateFn)CreateGameEventSaleAutoPlayInstrument);
#endif
// @0x1403bfa80
GameEvent* CreateGameEventSaleAutoPlayInstrument() { return new GameEventSaleAutoPlayInstrument; }

// @0x1403bfae0
CStringW GameEventSaleAutoPlayInstrument::GetTypeName() { return CStringW(L"GameEventSaleAutoPlayInstrument"); }
MS2_REPLACE_METHOD(0x1403BFAE0, GameEventSaleAutoPlayInstrument, GetTypeName, 61, 0xFC4F68B4);

// @0x1403bfb30
GameEventSaleAutoPlayInstrument::GameEventSaleAutoPlayInstrument()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bfba0
void GameEventSaleAutoPlayInstrument::vfunc_2()
{
    m_d0 = FUN_140718200(m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403BFBA0, GameEventSaleAutoPlayInstrument, vfunc_2, 72, 0x857B3B83);

// @0x1403bfbf0
void GameEventSaleAutoPlayInstrument::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403BFBF0, GameEventSaleAutoPlayInstrument, vfunc_3, 101, 0xE544CC82);

// @0x1403bfc60
void GameEventSaleAutoPlayInstrument::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403BFC60, GameEventSaleAutoPlayInstrument, vfunc_4, 179, 0xBEF43DC2);

// @0x1403bfd20
void GameEventSaleAutoPlayInstrument::OnStart()
{
    ((class CGameRule*)GetGameRule())->FUN_140479a00(m_d0);
    ((class CGameRule*)GetGameRule())->SetAutoPlayInstrumentName(m_d8);
}
MS2_REPLACE_METHOD(0x1403BFD20, GameEventSaleAutoPlayInstrument, OnStart, 116, 0x1960A1F7);

// @0x1403bfda0
void GameEventSaleAutoPlayInstrument::vfunc_6()
{
    ((class CGameRule*)GetGameRule())->FUN_140479a00(0);
    ((class CGameRule*)GetGameRule())->SetAutoPlayInstrumentName(L"");
}
MS2_REPLACE_METHOD(0x1403BFDA0, GameEventSaleAutoPlayInstrument, vfunc_6, 100, 0x484B5738);

// ---- GameEventTrafficOptimizer --------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regTrafficOptimizer(L"GameEventTrafficOptimizer", (ClassObjectCreateFn)CreateGameEventTrafficOptimizer);
#endif
// @0x1403bfe10
GameEvent* CreateGameEventTrafficOptimizer() { return new GameEventTrafficOptimizer; }

// @0x1403bfe70
CStringW GameEventTrafficOptimizer::GetTypeName() { return CStringW(L"GameEventTrafficOptimizer"); }
MS2_REPLACE_METHOD(0x1403BFE70, GameEventTrafficOptimizer, GetTypeName, 61, 0x73597DA3);

// @0x1403bfec0
GameEventTrafficOptimizer::GameEventTrafficOptimizer()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403bff20
void GameEventTrafficOptimizer::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403BFF20, GameEventTrafficOptimizer, vfunc_2, 6, 0xA9AF6E37);

// @0x1403bff30
void GameEventTrafficOptimizer::OnStart() {}
MS2_REPLACE_METHOD(0x1403BFF30, GameEventTrafficOptimizer, OnStart, 6, 0xA9AF6E37);

// @0x1403bff40
void GameEventTrafficOptimizer::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403BFF40, GameEventTrafficOptimizer, vfunc_6, 6, 0xA9AF6E37);

// @0x1403bff50
bool GameEventTrafficOptimizer::vfunc_9(void* other) { return true; }
MS2_REPLACE_METHOD(0x1403BFF50, GameEventTrafficOptimizer, vfunc_9, 13, 0xC078F4D1);

// ---- GameEventDungeonRoomShutdown -----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regDungeonRoomShutdown(L"GameEventDungeonRoomShutdown", (ClassObjectCreateFn)FUN_1403bff70);
#endif
// @0x1403bff70
GameEvent* FUN_1403bff70() { return new GameEventDungeonRoomShutdown; }

// @0x1403bffd0
CStringW GameEventDungeonRoomShutdown::GetTypeName() { return CStringW(L"GameEventDungeonRoomShutdown"); }
MS2_REPLACE_METHOD(0x1403BFFD0, GameEventDungeonRoomShutdown, GetTypeName, 61, 0x58ADE904);

// @0x1403c0020
GameEventDungeonRoomShutdown::GameEventDungeonRoomShutdown()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c0090
void GameEventDungeonRoomShutdown::vfunc_2()
{
    m_d0.AssignRaw(new DungeonRoomShutdownContext);
    m_d0->LoadRoomIds(m_68);
    m_d0->FUN_140343fc0(m_70);
    if (!m_d0->FUN_1403441a0())
        m_d0 = 0;
}
MS2_REPLACE_METHOD(0x1403C0090, GameEventDungeonRoomShutdown, vfunc_2, 255, 0x59566783);

// @0x1403c01a0
void GameEventDungeonRoomShutdown::OnStart() { ((class CGameRule*)GetGameRule())->SetDungeonRoomShutdown(m_d0); }
MS2_REPLACE_METHOD(0x1403C01A0, GameEventDungeonRoomShutdown, OnStart, 91, 0xA67C7DA7);

// @0x1403c0210
void GameEventDungeonRoomShutdown::vfunc_6() { ((class CGameRule*)GetGameRule())->SetDungeonRoomShutdown(0); }
MS2_REPLACE_METHOD(0x1403C0210, GameEventDungeonRoomShutdown, vfunc_6, 79, 0x6FA85DE5);

// @0x1403c0270
bool GameEventDungeonRoomShutdown::vfunc_9(void* other) { return true; }
MS2_REPLACE_METHOD(0x1403C0270, GameEventDungeonRoomShutdown, vfunc_9, 13, 0xC078F4D1);

// ---- GameEventDungeonOpenPeriod -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regDungeonOpenPeriod(L"GameEventDungeonOpenPeriod", (ClassObjectCreateFn)FUN_1403c0290);
#endif
// @0x1403c0290
GameEvent* FUN_1403c0290() { return new GameEventDungeonOpenPeriod; }

// @0x1403c02f0
CStringW GameEventDungeonOpenPeriod::GetTypeName() { return CStringW(L"GameEventDungeonOpenPeriod"); }
MS2_REPLACE_METHOD(0x1403C02F0, GameEventDungeonOpenPeriod, GetTypeName, 61, 0xB2E4B68E);

// @0x1403c0340
GameEventDungeonOpenPeriod::GameEventDungeonOpenPeriod()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c03b0
void GameEventDungeonOpenPeriod::vfunc_2() { m_d0 = m_68; }
MS2_REPLACE_METHOD(0x1403C03B0, GameEventDungeonOpenPeriod, vfunc_2, 44, 0x0D59366A);

// @0x1403c03f0
void GameEventDungeonOpenPeriod::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    WriteUnicodeString(MS2_GE_OUT(out), m_d0);
    ((class Unk_GEOut*)&WriteMsTime(*(class COutputStream*)(out), *(struct Unk_OSNumber const*)(&m_28)));
    ((class Unk_GEOut*)&WriteMsTime(*(class COutputStream*)(out), *(struct Unk_OSNumber const*)(&m_38)));
}
MS2_REPLACE_METHOD(0x1403C03F0, GameEventDungeonOpenPeriod, vfunc_3, 102, 0x3A3BD060);

// @0x1403c0460
void GameEventDungeonOpenPeriod::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    reinterpret_cast<Unk_OSInput*>(MS2_GE_R(in))->Read11(m_d0);
    ((class Unk_GEReader*)&((class Unk_OSInput*)(class Unk_GEReader*)(MS2_GE_R(in)))->Read13(*(struct Unk_OSNumber*)(&m_28)));
    ((class Unk_GEReader*)&((class Unk_OSInput*)(class Unk_GEReader*)(MS2_GE_R(in)))->Read13(*(struct Unk_OSNumber*)(&m_38)));
}
MS2_REPLACE_METHOD(0x1403C0460, GameEventDungeonOpenPeriod, vfunc_4, 114, 0x92CEB667);

// @0x1403c04e0
void GameEventDungeonOpenPeriod::OnStart()
{
    if (m_d0.IsEmpty())
        return;
    if (!((CGameEventValueDungeonOpenPeriod*)(TSingleton<CGameEventValueManager>::GetInstance()->GetDungeonOpenPeriod()))->Add(m_d0, m_28.Get(), m_38.Get()))
    {
        static_cast<Unk_CommonLog*>(GetLogString())->Log(0, 0, 0x5f, L"GameEventDungeonOpenPeriod TagID Duplicated");
        m_d0.Empty();
    }
}
MS2_REPLACE_METHOD(0x1403C04E0, GameEventDungeonOpenPeriod, OnStart, 268, 0xBC6FC0A8);

// @0x1403c0600
void GameEventDungeonOpenPeriod::vfunc_6()
{
    if (m_d0.IsEmpty())
        return;
    ((CGameEventValueDungeonOpenPeriod*)(TSingleton<CGameEventValueManager>::GetInstance()->GetDungeonOpenPeriod()))->Remove(m_d0);
}
MS2_REPLACE_METHOD(0x1403C0600, GameEventDungeonOpenPeriod, vfunc_6, 129, 0xB35F834A);

// ---- GameEventFieldShutdown -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regFieldShutdown(L"GameEventFieldShutdown", (ClassObjectCreateFn)FUN_1403c0690);
#endif
// @0x1403c0690
GameEvent* FUN_1403c0690() { return new GameEventFieldShutdown; }

// @0x1403c06f0
CStringW GameEventFieldShutdown::GetTypeName() { return CStringW(L"GameEventFieldShutdown"); }
MS2_REPLACE_METHOD(0x1403C06F0, GameEventFieldShutdown, GetTypeName, 61, 0xCE8D8D4D);

// @0x1403c0740
GameEventFieldShutdown::GameEventFieldShutdown()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c07b0
void GameEventFieldShutdown::vfunc_2()
{
    m_d0.clear();
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    for (TiXmlElement* pNode = FUN_140345b40((TiXmlDocument *)pRoot); pNode; pNode = ((class TiXmlElement*)(class TiXmlElement*)(pNode))->NextSiblingElement())
    {
        unsigned nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", reinterpret_cast<unsigned int&>(nId));
        if (nId > 0)
            m_d0.insert(nId);
    }
}
MS2_REPLACE_METHOD(0x1403C07B0, GameEventFieldShutdown, vfunc_2, 280, 0x89FDD054);

// @0x1403c08d0
void GameEventFieldShutdown::OnStart() { ((class CGameRule*)GetGameRule())->SetFieldShutdownIds(m_d0); }
MS2_REPLACE_METHOD(0x1403C08D0, GameEventFieldShutdown, OnStart, 91, 0x94D3BD97);

// @0x1403c0940
void GameEventFieldShutdown::vfunc_6() { ((class CGameRule*)GetGameRule())->ClearFieldShutdownIds(); }
MS2_REPLACE_METHOD(0x1403C0940, GameEventFieldShutdown, vfunc_6, 27, 0x2DB313CE);

// @0x1403c0970
bool GameEventFieldShutdown::vfunc_9(void* other) { return true; }
MS2_REPLACE_METHOD(0x1403C0970, GameEventFieldShutdown, vfunc_9, 13, 0xC078F4D1);

// ---- GameEventDungeonExtraReward ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regDungeonExtraReward(L"GameEventDungeonExtraReward", (ClassObjectCreateFn)FUN_1403c0990);
#endif
// @0x1403c0990
GameEvent* FUN_1403c0990() { return new GameEventDungeonExtraReward; }

// @0x1403c09f0
CStringW GameEventDungeonExtraReward::GetTypeName() { return CStringW(L"GameEventDungeonExtraReward"); }
MS2_REPLACE_METHOD(0x1403C09F0, GameEventDungeonExtraReward, GetTypeName, 61, 0x8E36E21E);

// @0x1403c0a40
GameEventDungeonExtraReward::GameEventDungeonExtraReward()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c0ae0
void GameEventDungeonExtraReward::vfunc_2()
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    for (TiXmlElement* pNode = FUN_140345b40((TiXmlDocument *)pRoot); pNode; pNode = ((class TiXmlElement*)(class TiXmlElement*)(pNode))->NextSiblingElement())
    {
        MS2Ptr<DungeonExtraRewardCountCtx> spCount(new DungeonExtraRewardCountCtx);
        spCount->m_18 = GetID();
        spCount->Load(pNode);
        if (spCount->m_dungeonID == 0 || spCount->m_count == 0)
            continue;
        m_d0.SetAt(spCount->m_dungeonID, spCount);
    }
}
MS2_REPLACE_METHOD(0x1403C0AE0, GameEventDungeonExtraReward, vfunc_2, 427, 0x5A1AD044);

// @0x1403c0ca0
void GameEventDungeonExtraReward::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    MS2_GE_OUT(out) << m_d0;
}
MS2_REPLACE_METHOD(0x1403C0CA0, GameEventDungeonExtraReward, vfunc_3, 58, 0x7D6F83BC);

// @0x1403c0ce0
void GameEventDungeonExtraReward::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    MS2_GE_IN(in) >> m_d0;
}
MS2_REPLACE_METHOD(0x1403C0CE0, GameEventDungeonExtraReward, vfunc_4, 62, 0x41D09D75);

// @0x1403c0d30
void GameEventDungeonExtraReward::OnStart()
{
    for (POSITION pos = m_d0.GetStartPosition(); pos; m_d0.GetNext(pos))
    {
        if (!((class CGameRule*)GetGameRule())->AddDungeonExtraRewardCount(m_d0.GetKeyAt(pos), m_d0.GetValueAt(pos)))
            static_cast<Unk_CommonLog*>(GetLogString())->Log(0, 0, 0x2c, StringFormat(L"GameEventDungeonExtraReward::OnStart Duplicate DungeonID",
                                                         m_d0.GetKeyAt(pos)));
    }
}
MS2_REPLACE_METHOD(0x1403C0D30, GameEventDungeonExtraReward, OnStart, 359, 0x62073F0A);

// @0x1403c0ea0
void GameEventDungeonExtraReward::vfunc_6()
{
    for (POSITION pos = m_d0.GetStartPosition(); pos; m_d0.GetNext(pos))
    {
        MS2Ptr<DungeonExtraRewardCountCtx> spCount = m_d0.GetValueAt(pos);
        if (spCount.get())
            ((class CGameRule*)GetGameRule())->RemoveDungeonExtraRewardCount(m_d0.GetKeyAt(pos), spCount->m_18);
    }
}
MS2_REPLACE_METHOD(0x1403C0EA0, GameEventDungeonExtraReward, vfunc_6, 225, 0x1D2A0759);

// ---- GameEventSale --------------------------------------------------------------------------------------------------
// @0x1403c0f90
GameEventSale::GameEventSale() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c1000
void GameEventSale::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403C1000, GameEventSale, vfunc_2, 42, 0xB4C424AB);

// @0x1403c1030
void GameEventSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C1030, GameEventSale, vfunc_3, 61, 0x68660156);

// @0x1403c1080
void GameEventSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C1080, GameEventSale, vfunc_4, 79, 0x387A8D8B);

// ---- GameEventSaleRemake --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleRemake(L"GameEventSaleRemake", (ClassObjectCreateFn)FUN_1403c10e0);
#endif
// @0x1403c10e0
GameEvent* FUN_1403c10e0() { return new GameEventSaleRemake; }

// @0x1403c1140
CStringW GameEventSaleRemake::GetTypeName() { return CStringW(L"GameEventSaleRemake"); }
MS2_REPLACE_METHOD(0x1403C1140, GameEventSaleRemake, GetTypeName, 61, 0xB6BF899D);

// @0x1403c1190
GameEventSaleRemake::GameEventSaleRemake() : m_d0(0), m_d4(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c1210
void GameEventSaleRemake::vfunc_2()
{
    m_d0 = FUN_140718200(m_68);
    m_d4 = FUN_1407181a0(m_70);
}
MS2_REPLACE_METHOD(0x1403C1210, GameEventSaleRemake, vfunc_2, 70, 0x58AE9BFB);

// @0x1403c1260
void GameEventSaleRemake::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteByte(m_d4);
}
MS2_REPLACE_METHOD(0x1403C1260, GameEventSaleRemake, vfunc_3, 89, 0x15897305);

// @0x1403c12c0
void GameEventSaleRemake::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d4 = MS2_GE_R(in)->ReadByte();
}
MS2_REPLACE_METHOD(0x1403C12C0, GameEventSaleRemake, vfunc_4, 127, 0x74CFAF45);

// @0x1403c1350
void GameEventSaleRemake::OnStart() { ((class CGameRule*)GetGameRule())->SetRemakeSaleRate(m_id, m_d4, m_d0); }
MS2_REPLACE_METHOD(0x1403C1350, GameEventSaleRemake, OnStart, 59, 0xCCEA410C);

// @0x1403c13a0
void GameEventSaleRemake::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveRemakeSaleRate(m_id, m_d4); }
MS2_REPLACE_METHOD(0x1403C13A0, GameEventSaleRemake, vfunc_6, 47, 0xAB4281F4);

// ---- GameEventSaleGemStoneUpgrade -----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleGemStoneUpgrade(L"GameEventSaleGemStoneUpgrade", (ClassObjectCreateFn)FUN_1403c13e0);
#endif
// @0x1403c13e0
GameEvent* FUN_1403c13e0() { return new GameEventSaleGemStoneUpgrade; }

// @0x1403c1440
CStringW GameEventSaleGemStoneUpgrade::GetTypeName() { return CStringW(L"GameEventSaleGemStoneUpgrade"); }
MS2_REPLACE_METHOD(0x1403C1440, GameEventSaleGemStoneUpgrade, GetTypeName, 61, 0x9E6F808F);

// @0x1403c1490
GameEventSaleGemStoneUpgrade::GameEventSaleGemStoneUpgrade()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c14f0
void GameEventSaleGemStoneUpgrade::OnStart() { ((class CGameRule*)GetGameRule())->SetSaleGemStoneUpgradeRate(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403C14F0, GameEventSaleGemStoneUpgrade, OnStart, 47, 0x689EA1F8);

// @0x1403c1530
void GameEventSaleGemStoneUpgrade::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveSaleGemStoneUpgradeRate(m_id); }
MS2_REPLACE_METHOD(0x1403C1530, GameEventSaleGemStoneUpgrade, vfunc_6, 35, 0xC8B8A187);

// ---- GameEventSaleSkillUpgrade --------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleSkillUpgrade(L"GameEventSaleSkillUpgrade", (ClassObjectCreateFn)FUN_1403c1560);
#endif
// @0x1403c1560
GameEvent* FUN_1403c1560() { return new GameEventSaleSkillUpgrade; }

// @0x1403c15c0
CStringW GameEventSaleSkillUpgrade::GetTypeName() { return CStringW(L"GameEventSaleSkillUpgrade"); }
MS2_REPLACE_METHOD(0x1403C15C0, GameEventSaleSkillUpgrade, GetTypeName, 61, 0x1F5BEC15);

// @0x1403c1610
GameEventSaleSkillUpgrade::GameEventSaleSkillUpgrade()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c16c0
void GameEventSaleSkillUpgrade::vfunc_2()
{
    m_d0 = m_68;
    m_d8 = m_70;
    m_e0 = m_78;
    m_e8 = m_80;
}
MS2_REPLACE_METHOD(0x1403C16C0, GameEventSaleSkillUpgrade, vfunc_2, 163, 0x05EF46DF);

// @0x1403c1770
void GameEventSaleSkillUpgrade::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringA(m_d0);
    out->WriteStringA(m_d8);
    out->WriteStringA(m_e0);
    out->WriteStringW(m_e8);
}
MS2_REPLACE_METHOD(0x1403C1770, GameEventSaleSkillUpgrade, vfunc_3, 194, 0xA552751C);

// @0x1403c1840
void GameEventSaleSkillUpgrade::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringA();
    m_d8 = MS2_GE_R(in)->ReadStringA();
    m_e0 = MS2_GE_R(in)->ReadStringA();
    m_e8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C1840, GameEventSaleSkillUpgrade, vfunc_4, 482, 0x3A8EF457);

// @0x1403c1a30
void GameEventSaleSkillUpgrade::OnStart()
{
    ATL::CAtlArray<unsigned> skillIds;
    ATL::CAtlArray<unsigned> levels;
    ATL::CAtlArray<unsigned> rates;
    XmlSplit(m_d0, skillIds, ",");
    XmlSplit(m_d8, levels, ",");
    XmlSplit(m_e0, rates, ",");
    if (skillIds.GetCount() != levels.GetCount())
        return;
    if (levels.GetCount() != rates.GetCount())
        return;
    for (size_t i = 0; i < skillIds.GetCount(); ++i)
    {
        MS2Ptr<SkillUpgradeSaleEventContext> spContext(new SkillUpgradeSaleEventContext);
        spContext->m_18 = skillIds[i];
        spContext->m_1c = levels[i];
        spContext->m_20 = rates[i];
        ((class CGameRule*)GetGameRule())->SetSkillUpgradeSale(spContext);
    }
    ((class CGameRule*)GetGameRule())->FUN_14047b6d0(m_e8);
}
MS2_REPLACE_METHOD(0x1403C1A30, GameEventSaleSkillUpgrade, OnStart, 789, 0xD857AE3F);

// @0x1403c1d50
void GameEventSaleSkillUpgrade::vfunc_6()
{
    ATL::CAtlArray<unsigned> skillIds;
    XmlSplit(m_d0, skillIds, ",");
    for (size_t i = 0; i < skillIds.GetCount(); ++i)
        ((class CGameRule*)GetGameRule())->RemoveSkillUpgradeSale(skillIds[i]);
}
MS2_REPLACE_METHOD(0x1403C1D50, GameEventSaleSkillUpgrade, vfunc_6, 158, 0x81180E3D);

// ---- GameEventNpcEventDrop ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regNpcEventDrop(L"GameEventNpcEventDrop", (ClassObjectCreateFn)FUN_1403c1e00);
#endif
// @0x1403c1e00
GameEvent* FUN_1403c1e00() { return new GameEventNpcEventDrop; }

// @0x1403c1e60
CStringW GameEventNpcEventDrop::GetTypeName() { return CStringW(L"GameEventNpcEventDrop"); }
MS2_REPLACE_METHOD(0x1403C1E60, GameEventNpcEventDrop, GetTypeName, 61, 0xA2C14318);

// @0x1403c1eb0
GameEventNpcEventDrop::GameEventNpcEventDrop() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c1f30
void GameEventNpcEventDrop::vfunc_2()
{
    m_d0 = 0;
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    TiXmlElement* pNode = FUN_140345b40((TiXmlDocument *)pRoot);
    if (!pNode)
        return;
    MS2Ptr<NpcEventDropEventContext> spContext(new NpcEventDropEventContext);
    XmlGetAttr((class TiXmlElement*)(pNode), "minLevel", spContext->m_minLevel);
    XmlGetAttr((class TiXmlElement*)(pNode), "maxLevel", spContext->m_maxLevel);
    XmlGetAttr((class TiXmlElement*)(pNode), "fieldId", reinterpret_cast<unsigned int&>(spContext->m_fieldId));
    XmlValue(pNode, "npcRank", spContext->m_npcRank);
    XmlTokenList(pNode, "customNpcId", spContext->m_customNpcIds);
    XmlGetAttr((class TiXmlElement*)(pNode), "isShow", reinterpret_cast<bool&>(spContext->m_isShow));
    XmlTokenList(pNode, "dropId", spContext->m_dropIds);
    XmlEnumName<int, Parse_14021bc30>(pNode, "eventTags", reinterpret_cast<int&>(spContext->m_eventTag));
    m_d0 = spContext;
}
MS2_REPLACE_METHOD(0x1403C1F30, GameEventNpcEventDrop, vfunc_2, 598, 0xB54C8D81);

// @0x1403c2190
void GameEventNpcEventDrop::OnStart()
{
    if (m_d0.get())
        ((class CGameRule*)GetGameRule())->AddNpcEventDrop(GetID(), m_d0);
}
MS2_REPLACE_METHOD(0x1403C2190, GameEventNpcEventDrop, OnStart, 135, 0x8347BC99);

// @0x1403c2220
void GameEventNpcEventDrop::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveNpcEventDrop(GetID()); }
MS2_REPLACE_METHOD(0x1403C2220, GameEventNpcEventDrop, vfunc_6, 47, 0x0ADD96DA);

// ---- GameEventBlueMarble --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regBlueMarble(L"GameEventBlueMarble", (ClassObjectCreateFn)FUN_1403c2260);
#endif
// @0x1403c2260
GameEvent* FUN_1403c2260() { return new GameEventBlueMarble; }

// @0x1403c22c0
CStringW GameEventBlueMarble::GetTypeName() { return CStringW(L"GameEventBlueMarble"); }
MS2_REPLACE_METHOD(0x1403C22C0, GameEventBlueMarble, GetTypeName, 61, 0x49E74EC9);

// @0x1403c2310
GameEventBlueMarble::GameEventBlueMarble()
{
    m_d0 = 0;
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c23a0
void GameEventBlueMarble::vfunc_2()
{
    TiXmlDocument docRound;
    TiXmlDocument docSlot;
    if (GetFileSystem()->LoadXmlFromString(&docRound, m_68) == 0)
        return;
    if (GetFileSystem()->LoadXmlFromString(&docSlot, m_70) == 0)
        return;
    MS2Ptr<BlueMarbleEventContext> spContext(new BlueMarbleEventContext(GetID(), GetEndTime()));
    TiXmlElement* pRound = reinterpret_cast<TiXmlElement*>(reinterpret_cast<Unk_XmlNode*>(&docRound)->FirstChild("round"));
    if (pRound)
        spContext->LoadRewards(pRound);
    TiXmlElement* pSlots = reinterpret_cast<TiXmlElement*>(reinterpret_cast<Unk_XmlNode*>(&docSlot)->FirstChild("slots"));
    if (pSlots)
        spContext->LoadSlots(pSlots);
    m_d0 = spContext;
}
MS2_REPLACE_METHOD(0x1403C23A0, GameEventBlueMarble, vfunc_2, 520, 0xE0741D96);

// @0x1403c25b0
void GameEventBlueMarble::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt((int)m_d0->m_rewards.GetCount());
    for (POSITION pos = m_d0->m_rewards.GetHeadPosition(); pos; m_d0->m_rewards.GetNext(pos))
    {
        MS2Ptr<ItemEntity> spItem = m_d0->m_rewards.GetValueAt(pos);
        out->WriteInt(m_d0->m_rewards.GetKeyAt(pos));
        out->WriteInt(spItem->m_itemId);
        out->WriteByte(spItem->vfunc_o18_1());
        out->WriteInt(spItem->m_count);
    }
}
MS2_REPLACE_METHOD(0x1403C25B0, GameEventBlueMarble, vfunc_3, 511, 0xCE411612);

// @0x1403c27c0
void GameEventBlueMarble::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new BlueMarbleEventContext(GetID(), GetEndTime()));
    size_t nCount = (unsigned)MS2_GE_R(in)->ReadInt();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<ItemEntity> spItem(new ItemEntity);
        int nRound = MS2_GE_R(in)->ReadInt();
        spItem->m_itemId = MS2_GE_R(in)->ReadInt();
        spItem->SetRank(MS2_GE_R(in)->ReadByte());
        spItem->m_count = MS2_GE_R(in)->ReadInt();
        m_d0->AddReward(nRound, spItem);
    }
}
MS2_REPLACE_METHOD(0x1403C27C0, GameEventBlueMarble, vfunc_4, 745, 0x0AF8B17F);

// @0x1403c2ab0
void GameEventBlueMarble::OnStart() { ((class CGameRule*)GetGameRule())->SetBlueMarbleEvent(m_d0); }
MS2_REPLACE_METHOD(0x1403C2AB0, GameEventBlueMarble, OnStart, 91, 0x52567E0A);

// @0x1403c2b20
void GameEventBlueMarble::vfunc_6() { ((class CGameRule*)GetGameRule())->SetBlueMarbleEvent(0); }
MS2_REPLACE_METHOD(0x1403C2B20, GameEventBlueMarble, vfunc_6, 79, 0xD37814B8);

// ---- GameEventSaleUGCDesign -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleUGCDesign(L"GameEventSaleUGCDesign", (ClassObjectCreateFn)FUN_1403c2b80);
#endif
// @0x1403c2b80
GameEvent* FUN_1403c2b80() { return new GameEventSaleUGCDesign; }

// @0x1403c2be0
CStringW GameEventSaleUGCDesign::GetTypeName() { return CStringW(L"GameEventSaleUGCDesign"); }
MS2_REPLACE_METHOD(0x1403C2BE0, GameEventSaleUGCDesign, GetTypeName, 61, 0xFCF94496);

// @0x1403c2c30
GameEventSaleUGCDesign::GameEventSaleUGCDesign()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c2c90
void GameEventSaleUGCDesign::OnStart() { ((class CGameRule*)GetGameRule())->SetSaleUgcDesignRate(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403C2C90, GameEventSaleUGCDesign, OnStart, 47, 0x432176DC);

// @0x1403c2cd0
void GameEventSaleUGCDesign::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveSaleUgcDesignRate(m_id); }
MS2_REPLACE_METHOD(0x1403C2CD0, GameEventSaleUGCDesign, vfunc_6, 35, 0xC878D363);

// ---- GameEventMeratMarketNotice -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regMeratMarketNotice(L"GameEventMeratMarketNotice", (ClassObjectCreateFn)FUN_1403c2d00);
#endif
// @0x1403c2d00
GameEvent* FUN_1403c2d00() { return new GameEventMeratMarketNotice; }

// @0x1403c2d60
CStringW GameEventMeratMarketNotice::GetTypeName() { return CStringW(L"GameEventMeratMarketNotice"); }
MS2_REPLACE_METHOD(0x1403C2D60, GameEventMeratMarketNotice, GetTypeName, 61, 0xC9F95959);

// @0x1403c2db0
GameEventMeratMarketNotice::GameEventMeratMarketNotice() : m_d0(L"")
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c2e30
void GameEventMeratMarketNotice::vfunc_2() { m_d0 = m_68; }
MS2_REPLACE_METHOD(0x1403C2E30, GameEventMeratMarketNotice, vfunc_2, 44, 0x73576DA6);

// @0x1403c2e70
void GameEventMeratMarketNotice::vfunc_3(Unk_GEOut* out) { out->WriteStringW(m_d0); }
MS2_REPLACE_METHOD(0x1403C2E70, GameEventMeratMarketNotice, vfunc_3, 59, 0xAE59AA54);

// @0x1403c2ec0
void GameEventMeratMarketNotice::vfunc_4(Unk_GEIn* in) { m_d0 = MS2_GE_R(in)->ReadStringW(); }
MS2_REPLACE_METHOD(0x1403C2EC0, GameEventMeratMarketNotice, vfunc_4, 119, 0xDAD2EB50);

// @0x1403c2f40
void GameEventMeratMarketNotice::OnStart() {}
MS2_REPLACE_METHOD(0x1403C2F40, GameEventMeratMarketNotice, OnStart, 6, 0xA9AF6E37);

// @0x1403c2f50
void GameEventMeratMarketNotice::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403C2F50, GameEventMeratMarketNotice, vfunc_6, 6, 0xA9AF6E37);

// ---- GameEventDungeonEnterTimeLimit ---------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regDungeonEnterTimeLimit(L"GameEventDungeonEnterTimeLimit", (ClassObjectCreateFn)FUN_1403c2f60);
#endif
// @0x1403c2f60
GameEvent* FUN_1403c2f60() { return new GameEventDungeonEnterTimeLimit; }

// @0x1403c2fc0
CStringW GameEventDungeonEnterTimeLimit::GetTypeName() { return CStringW(L"GameEventDungeonEnterTimeLimit"); }
MS2_REPLACE_METHOD(0x1403C2FC0, GameEventDungeonEnterTimeLimit, GetTypeName, 61, 0xDA704B95);

// @0x1403c3010
GameEventDungeonEnterTimeLimit::GameEventDungeonEnterTimeLimit()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c3080
void GameEventDungeonEnterTimeLimit::vfunc_2() { FUN_1403c31c0(m_68); }
MS2_REPLACE_METHOD(0x1403C3080, GameEventDungeonEnterTimeLimit, vfunc_2, 36, 0xE1C0510D);

// @0x1403c30b0
void GameEventDungeonEnterTimeLimit::OnStart() { ((class CGameRule*)GetGameRule())->AddEventTimeLimitDungeons(m_d0); }
MS2_REPLACE_METHOD(0x1403C30B0, GameEventDungeonEnterTimeLimit, OnStart, 51, 0x03061B7D);

// @0x1403c30f0
void GameEventDungeonEnterTimeLimit::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveEventTimeLimitDungeons(GetID()); }
MS2_REPLACE_METHOD(0x1403C30F0, GameEventDungeonEnterTimeLimit, vfunc_6, 47, 0x22EB50E5);

// @0x1403c3130
void GameEventDungeonEnterTimeLimit::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    MS2_GE_OUT(out) << m_d0;
}
MS2_REPLACE_METHOD(0x1403C3130, GameEventDungeonEnterTimeLimit, vfunc_3, 58, 0x7BD7AF3B);

// @0x1403c3170
void GameEventDungeonEnterTimeLimit::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    MS2_GE_IN(in) >> m_d0;
}
MS2_REPLACE_METHOD(0x1403C3170, GameEventDungeonEnterTimeLimit, vfunc_4, 62, 0x87FAC90C);

// @0x1403c31c0
void GameEventDungeonEnterTimeLimit::FUN_1403c31c0(const CStringW& strXml)
{
    m_d0.clear();
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, strXml) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    for (TiXmlElement* pNode = FUN_140345b40((TiXmlDocument *)pRoot); pNode; pNode = ((class TiXmlElement*)(class TiXmlElement*)(pNode))->NextSiblingElement())
    {
        MS2Ptr<EventTimeLimitDungeonContext> spContext(new EventTimeLimitDungeonContext);
        spContext->m_eventId = GetID();
        XmlGetAttr((class TiXmlElement*)(pNode), "dungeonID", reinterpret_cast<unsigned int&>(spContext->m_dungeonId));
        XmlValueRange(pNode, "rangeTime", spContext->m_rangeTime);
        if (spContext->m_dungeonId == 0 || spContext->m_rangeTime.m_start > spContext->m_rangeTime.m_end)
        {
            MS2_ASSERT_AT(MS2_LINE(1829), 0);
            continue;
        }
        m_d0.push_back(spContext);
    }
}
MS2_REPLACE_METHOD(0x1403C31C0, GameEventDungeonEnterTimeLimit, FUN_1403c31c0, 545, 0xAA0ABD16);

// ---- GameEventSaleHousing -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleHousing(L"GameEventSaleHousing", (ClassObjectCreateFn)FUN_1403c33f0);
#endif
// @0x1403c33f0
GameEvent* FUN_1403c33f0() { return new GameEventSaleHousing; }

// @0x1403c3450
CStringW GameEventSaleHousing::GetTypeName() { return CStringW(L"GameEventSaleHousing"); }
MS2_REPLACE_METHOD(0x1403C3450, GameEventSaleHousing, GetTypeName, 61, 0xED0BCDC7);

// @0x1403c34a0
GameEventSaleHousing::GameEventSaleHousing() : m_d0(10)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c3520
void GameEventSaleHousing::vfunc_2()
{
    ATL::CAtlArray<unsigned> keys;
    FUN_140274fc0(m_68, &keys, L",");
    ATL::CAtlArray<unsigned> values1c;
    FUN_140274fc0(m_70, &values1c, L",");
    ATL::CAtlArray<unsigned> values20;
    FUN_140274fc0(m_78, &values20, L",");
    if (keys.GetCount() != values1c.GetCount())
        return;
    if (values1c.GetCount() != values20.GetCount())
        return;
    for (unsigned i = 0; i < keys.GetCount(); i++)
    {
        MS2Ptr<SaleCube> spCube(new SaleCube);
        spCube->m_18 = (Unk_SaleHousingKey)keys[i];
        spCube->m_1c = values1c[i];
        spCube->m_20 = values20[i];
        m_d0.Insert(spCube->m_18, spCube);
    }
}
MS2_REPLACE_METHOD(0x1403C3520, GameEventSaleHousing, vfunc_2, 715, 0x9E5EB17E);

// @0x1403c3800
void GameEventSaleHousing::OnStart() { ((class CGameRule*)GetGameRule())->SetSaleCubes(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403C3800, GameEventSaleHousing, OnStart, 59, 0x0D886633);

// @0x1403c3850
void GameEventSaleHousing::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveSaleCubes(m_id); }
MS2_REPLACE_METHOD(0x1403C3850, GameEventSaleHousing, vfunc_6, 35, 0x1CF60104);

// @0x1403c3880
void GameEventSaleHousing::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt((int)m_d0.GetCount());
    for (POSITION pos = m_d0.GetHeadPosition(); pos; m_d0.GetNext(pos))
    {
        MS2Ptr<SaleCube> spCube = m_d0.GetValueAt(pos);
        out->WriteShort((unsigned short)spCube->m_18);
        out->WriteShort((unsigned short)spCube->m_1c);
        out->WriteInt(spCube->m_20);
    }
}
MS2_REPLACE_METHOD(0x1403C3880, GameEventSaleHousing, vfunc_3, 325, 0x7FD464E2);

// @0x1403c39d0
void GameEventSaleHousing::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    int nCount = MS2_GE_R(in)->ReadInt();
    for (int i = 0; i < nCount; i++)
    {
        MS2Ptr<SaleCube> spCube(new SaleCube);
        spCube->m_18 = (Unk_SaleHousingKey)MS2_GE_R(in)->ReadShort();
        spCube->m_1c = MS2_GE_R(in)->ReadShort();
        spCube->m_20 = MS2_GE_R(in)->ReadInt();
        m_d0.Insert(spCube->m_18, spCube);
    }
}
MS2_REPLACE_METHOD(0x1403C39D0, GameEventSaleHousing, vfunc_4, 458, 0x2F7119E0);

// ---- GameEventEpicRestart -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regEpicRestart(L"GameEventEpicRestart", (ClassObjectCreateFn)FUN_1403c3ba0);
#endif
// @0x1403c3ba0
GameEvent* FUN_1403c3ba0() { return new GameEventEpicRestart; }

// @0x1403c3c00
CStringW GameEventEpicRestart::GetTypeName() { return CStringW(L"GameEventEpicRestart"); }
MS2_REPLACE_METHOD(0x1403C3C00, GameEventEpicRestart, GetTypeName, 61, 0x0985CFB1);

// @0x1403c3c50
GameEventEpicRestart::GameEventEpicRestart()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c3cf0
void GameEventEpicRestart::vfunc_2()
{
    m_d0 = (const wchar_t*)m_68;
    m_e0 = (const wchar_t*)m_70;
    m_d8 = (const wchar_t*)m_78;
}
MS2_REPLACE_METHOD(0x1403C3CF0, GameEventEpicRestart, vfunc_2, 131, 0xE21A7CD6);

// @0x1403c3d80
void GameEventEpicRestart::OnStart() { ((class CGameRule*)GetGameRule())->SetEpicRestart(GetID(), m_38.Get(), m_d0, m_e0, m_d8); }
MS2_REPLACE_METHOD(0x1403C3D80, GameEventEpicRestart, OnStart, 155, 0xDC91DCFD);

// @0x1403c3e30
void GameEventEpicRestart::vfunc_6() { ((class CGameRule*)GetGameRule())->FUN_14047c1e0(); }
MS2_REPLACE_METHOD(0x1403C3E30, GameEventEpicRestart, vfunc_6, 27, 0x4FC9645D);

// @0x1403c3e60
void GameEventEpicRestart::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt64(m_38.Get());
    out->WriteStringA(m_d0);
    out->WriteStringA(m_e0);
    out->WriteStringA(m_d8);
}
MS2_REPLACE_METHOD(0x1403C3E60, GameEventEpicRestart, vfunc_3, 200, 0x37DB4AB8);

// @0x1403c3f30
void GameEventEpicRestart::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_38 = CMsTime(MS2_GE_R(in)->ReadInt64());
    m_d0 = MS2_GE_R(in)->ReadStringA();
    m_e0 = MS2_GE_R(in)->ReadStringA();
    m_d8 = MS2_GE_R(in)->ReadStringA();
}
MS2_REPLACE_METHOD(0x1403C3F30, GameEventEpicRestart, vfunc_4, 440, 0x84F320C1);

// ---- GameEventLevelUpPackage ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regLevelUpPackage(L"GameEventLevelUpPackage", (ClassObjectCreateFn)FUN_1403c40f0);
#endif
// @0x1403c40f0
GameEvent* FUN_1403c40f0() { return new GameEventLevelUpPackage; }

// @0x1403c4150
CStringW GameEventLevelUpPackage::GetTypeName() { return CStringW(L"GameEventLevelUpPackage"); }
MS2_REPLACE_METHOD(0x1403C4150, GameEventLevelUpPackage, GetTypeName, 61, 0xB78A86F4);

// @0x1403c41a0
GameEventLevelUpPackage::GameEventLevelUpPackage()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c4210
void GameEventLevelUpPackage::vfunc_2()
{
    m_d0 = FUN_140718200(m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403C4210, GameEventLevelUpPackage, vfunc_2, 72, 0x151E7A50);

// @0x1403c4260
void GameEventLevelUpPackage::OnStart() { ((class CGameRule*)GetGameRule())->SetLevelUpPackage(m_d0, m_d8); }
MS2_REPLACE_METHOD(0x1403C4260, GameEventLevelUpPackage, OnStart, 62, 0x4F7D051A);

// @0x1403c42b0
void GameEventLevelUpPackage::vfunc_6() { ((class CGameRule*)GetGameRule())->ClearLevelUpPackage(); }
MS2_REPLACE_METHOD(0x1403C42B0, GameEventLevelUpPackage, vfunc_6, 27, 0x1F6EC9DB);

// @0x1403c42e0
void GameEventLevelUpPackage::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403C42E0, GameEventLevelUpPackage, vfunc_3, 101, 0xE15070E8);

// @0x1403c4350
void GameEventLevelUpPackage::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C4350, GameEventLevelUpPackage, vfunc_4, 179, 0xEBAFE723);

// ---- GameEventUpdateString ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regUpdateString(L"GameEventUpdateString", (ClassObjectCreateFn)FUN_1403c4410);
#endif
// @0x1403c4410
GameEvent* FUN_1403c4410() { return new GameEventUpdateString; }

// @0x1403c4470
CStringW GameEventUpdateString::GetTypeName() { return CStringW(L"GameEventUpdateString"); }
MS2_REPLACE_METHOD(0x1403C4470, GameEventUpdateString, GetTypeName, 61, 0xFF2F4C8C);

// @0x1403c44c0
GameEventUpdateString::GameEventUpdateString()
{
    SetFlag(2);
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c4540
void GameEventUpdateString::vfunc_2() { m_d0 = m_68; }
MS2_REPLACE_METHOD(0x1403C4540, GameEventUpdateString, vfunc_2, 44, 0xB7A08C4F);

// @0x1403c4580
void GameEventUpdateString::OnStart() {}
MS2_REPLACE_METHOD(0x1403C4580, GameEventUpdateString, OnStart, 6, 0xA9AF6E37);

// @0x1403c4590
void GameEventUpdateString::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403C4590, GameEventUpdateString, vfunc_6, 6, 0xA9AF6E37);

// @0x1403c45a0
void GameEventUpdateString::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
}
MS2_REPLACE_METHOD(0x1403C45A0, GameEventUpdateString, vfunc_3, 74, 0x7D451564);

// @0x1403c45f0
void GameEventUpdateString::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C45F0, GameEventUpdateString, vfunc_4, 134, 0x817B68F0);

// ---- GameEventStampEvent --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regStampEvent(L"GameEventStampEvent", (ClassObjectCreateFn)FUN_1403c4680);
#endif
// @0x1403c4680
GameEvent* FUN_1403c4680() { return new GameEventStampEvent; }

// @0x1403c46e0
CStringW GameEventStampEvent::GetTypeName() { return CStringW(L"GameEventStampEvent"); }
MS2_REPLACE_METHOD(0x1403C46E0, GameEventStampEvent, GetTypeName, 61, 0xA9C46086);

// @0x1403c4730
GameEventStampEvent::GameEventStampEvent()
{
    SetFlag(3);
    SetFlag(1);
    m_d8 = 0;
    m_d0 = true;
}

// @0x1403c47c0
void GameEventStampEvent::vfunc_2()
{
    TiXmlDocument docStamp;
    TiXmlDocument docReward;
    if (GetFileSystem()->LoadXmlFromString(&docStamp, m_68) == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(2060), 0);
        return;
    }
    if (GetFileSystem()->LoadXmlFromString(&docReward, m_70) == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(2066), 0);
        return;
    }
    MS2Ptr<StampEventContext> spContext(new StampEventContext(GetID()));
    TiXmlElement* pStampRoot = FUN_140345b40(&docStamp);
    if (pStampRoot)
    {
        TiXmlElement* pTag = ((class TiXmlElement*)((class Unk_XmlNode*)(pStampRoot))->FirstChild("tag"));
        if (pTag)
            XmlGetAttr((class TiXmlElement*)(pTag), "event", spContext->m_strTitle);
        for (TiXmlElement* pStamp = ((class TiXmlElement*)((class Unk_XmlNode*)(pStampRoot))->FirstChild("stamp")); pStamp; pStamp = ((class TiXmlElement*)((class Unk_XmlNode*)(pStamp))->NextSibling("stamp")))
        {
            MS2Ptr<StampEventContext::Stamp> spStamp(new StampEventContext::Stamp);
            XmlGetAttr((class TiXmlElement*)(pStamp), "quest", reinterpret_cast<unsigned int&>(spStamp->m_id));
            XmlGetAttr((class TiXmlElement*)(pStamp), "special", spStamp->m_bStamped);
            XmlGetAttr((class TiXmlElement*)(pStamp), "x", spStamp->m_20);
            XmlGetAttr((class TiXmlElement*)(pStamp), "y", spStamp->m_24);
            spContext->m_stamps.Add(spStamp);
        }
    }
    TiXmlElement* pRewardRoot = FUN_140345b40(&docReward);
    if (pRewardRoot)
    {
        for (TiXmlElement* pReward = ((class TiXmlElement*)((class Unk_XmlNode*)(pRewardRoot))->FirstChild("reward")); pReward;
             pReward = ((class TiXmlElement*)((class Unk_XmlNode*)(pReward))->NextSibling("reward")))
        {
            MS2Ptr<StampEventContext::Reward> spReward(new StampEventContext::Reward);
            XmlGetAttr((class TiXmlElement*)(pReward), "special", spReward->m_bReceived);
            XmlGetAttr((class TiXmlElement*)(pReward), "count", spReward->m_count);
            CStringW strItem1;
            CStringW strItem2;
            XmlGetAttr((class TiXmlElement*)(pReward), "item01", strItem1);
            XmlGetAttr((class TiXmlElement*)(pReward), "item02", strItem2);
            spReward->m_item.vfunc_1(strItem1);
            spReward->m_item2.vfunc_1(strItem2);
            spContext->m_rewards.Add(spReward);
        }
    }
    spContext->m_item.vfunc_1(m_78);
    spContext->m_98 = FUN_1407181a0(m_80);
    spContext->m_endTime = GetEndTime().Get();
    spContext->m_b9c = m_d0;
    m_d8 = spContext;
}
MS2_REPLACE_METHOD(0x1403C47C0, GameEventStampEvent, vfunc_2, 1758, 0x516243D8);

// @0x1403c4eb0
void GameEventStampEvent::OnStart() { ((class CGameRule*)GetGameRule())->AddStampEvent(m_d8); }
MS2_REPLACE_METHOD(0x1403C4EB0, GameEventStampEvent, OnStart, 91, 0x1128F1EB);

// @0x1403c4f20
void GameEventStampEvent::vfunc_6()
{
    ((class CGameRule*)GetGameRule())->RemoveStampEvent(m_d8);
    TSingleton<CUIService>::GetInstance()->CloseDialog(eUI_4f33);
}
MS2_REPLACE_METHOD(0x1403C4F20, GameEventStampEvent, vfunc_6, 109, 0xDCD117E1);

// @0x1403c4fa0
void GameEventStampEvent::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (m_d8.IsNull())
        return;
    m_d8->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403C4FA0, GameEventStampEvent, vfunc_3, 94, 0xC3F5F23D);

// @0x1403c5010
void GameEventStampEvent::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d8.AssignRaw(new StampEventContext(GetID()));
    m_d8->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403C5010, GameEventStampEvent, vfunc_4, 170, 0x5E42215F);

// ---- GameEventStampEventChar ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regStampEventChar(L"GameEventStampEventChar", (ClassObjectCreateFn)FUN_1403c50c0);
#endif
// @0x1403c50c0
GameEvent* FUN_1403c50c0() { return new GameEventStampEventChar; }

// @0x1403c5120
CStringW GameEventStampEventChar::GetTypeName() { return CStringW(L"GameEventStampEventChar"); }
MS2_REPLACE_METHOD(0x1403C5120, GameEventStampEventChar, GetTypeName, 61, 0x93AF1272);

// @0x1403c5170
GameEventStampEventChar::GameEventStampEventChar() { m_d0 = false; }

// ---- GameEventTimeRunEvent ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regTimeRunEvent(L"GameEventTimeRunEvent", (ClassObjectCreateFn)FUN_1403c51b0);
#endif
// @0x1403c51b0
GameEvent* FUN_1403c51b0() { return new GameEventTimeRunEvent; }

// @0x1403c5210
CStringW GameEventTimeRunEvent::GetTypeName() { return CStringW(L"GameEventTimeRunEvent"); }
MS2_REPLACE_METHOD(0x1403C5210, GameEventTimeRunEvent, GetTypeName, 61, 0x48F43C7E);

// @0x1403c5260
GameEventTimeRunEvent::GameEventTimeRunEvent()
{
    SetFlag(3);
    SetFlag(1);
    m_d0 = 0;
}

// @0x1403c52f0
void GameEventTimeRunEvent::vfunc_2()
{
    MS2Ptr<TimeRunEventContext> spContext(new TimeRunEventContext(GetID()));
    if (FUN_1403c5670(spContext) == 0)
        return;
    if (FUN_1403c58e0(spContext) == 0)
        return;
    spContext->m_value = FUN_140718200(m_78);
    spContext->m_endTime = GetEndTime().Get();
    m_d0 = spContext;
}
MS2_REPLACE_METHOD(0x1403C52F0, GameEventTimeRunEvent, vfunc_2, 391, 0x7BB32E72);

// @0x1403c5480
void GameEventTimeRunEvent::OnStart() { ((class CGameRule*)GetGameRule())->SetTimeRunEvent(m_d0); }
MS2_REPLACE_METHOD(0x1403C5480, GameEventTimeRunEvent, OnStart, 91, 0xE2C6979A);

// @0x1403c54f0
void GameEventTimeRunEvent::vfunc_6() { ((class CGameRule*)GetGameRule())->SetTimeRunEvent(0); }
MS2_REPLACE_METHOD(0x1403C54F0, GameEventTimeRunEvent, vfunc_6, 79, 0x0C44DF80);

// @0x1403c5550
void GameEventTimeRunEvent::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (m_d0.IsNull())
        return;
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403C5550, GameEventTimeRunEvent, vfunc_3, 94, 0xC268AE54);

// @0x1403c55c0
void GameEventTimeRunEvent::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new TimeRunEventContext(GetID()));
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403C55C0, GameEventTimeRunEvent, vfunc_4, 170, 0xD50DD980);

// @0x1403c5670
int GameEventTimeRunEvent::FUN_1403c5670(MS2Ptr<TimeRunEventContext> spContext)
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return 0;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return 0;
    for (TiXmlElement* pQuest = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("quest")); pQuest; pQuest = ((class TiXmlElement*)((class Unk_XmlNode*)(pQuest))->NextSibling("quest")))
    {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest(new TimeRunEventContext::QuestContext);
        XmlGetAttr((class TiXmlElement*)(pQuest), "questID", reinterpret_cast<unsigned int&>(spQuest->m_questId));
        XmlGetAttr((class TiXmlElement*)(pQuest), "distance", reinterpret_cast<unsigned int&>(spQuest->m_1c));
        XmlGetAttr((class TiXmlElement*)(pQuest), "openingDay", spQuest->m_20);
        spContext->m_quests.SetAt(spQuest->m_questId, spQuest);
        spContext->m_1c += spQuest->m_1c;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1403C5670, GameEventTimeRunEvent, FUN_1403c5670, 608, 0x6AA1FEF2);

// @0x1403c58e0
int GameEventTimeRunEvent::FUN_1403c58e0(MS2Ptr<TimeRunEventContext> spContext)
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_70) == 0)
        return 0;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return 0;
    for (TiXmlElement* pReward = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("reward")); pReward; pReward = ((class TiXmlElement*)((class Unk_XmlNode*)(pReward))->NextSibling("reward")))
    {
        MS2Ptr<ItemEntity> spItem(new ItemEntity);
        int nDistance = 0;
        XmlGetAttr((class TiXmlElement*)(pReward), "distance", nDistance);
        spItem->vfunc_2(pReward);
        spContext->m_rewards.SetAt(nDistance, spItem);
    }
    TiXmlElement* pFinal = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("final"));
    if (pFinal)
        spContext->m_item.vfunc_2(pFinal);
    return 1;
}
MS2_REPLACE_METHOD(0x1403C58E0, GameEventTimeRunEvent, FUN_1403c58e0, 590, 0xC06EC853);

// The uint64 flavour of FUN_140274fc0: every token, as unsigned __int64, into the array.
// @0x1403d7cb0
unsigned __int64 FUN_1403d7cb0(const CStringW& text) { return _wcstoui64(text, NULL, 10); }
MS2_REPLACE(0x1403D7CB0, FUN_1403d7cb0, 42, 0x3B925566);

// @0x1403d7f80
void ParseUInt64List(CStringW& text, ATL::CAtlArray<unsigned __int64>& values, const wchar_t* delims)
{
    int nPos = 0;
    CStringW strToken = text.Tokenize(delims, nPos);
    while (!strToken.IsEmpty())
    {
        values.Add(FUN_1403d7cb0(strToken));
        strToken = text.Tokenize(delims, nPos);
    }
}
MS2_REPLACE(0x1403D7F80, ParseUInt64List, 191, 0x139C2656);

// ---- GameEventMassiveConstructionEvent ------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regMassiveConstructionEvent(L"GameEventMassiveConstructionEvent", (ClassObjectCreateFn)FUN_1403c5b40);
#endif
// @0x1403c5b40
GameEvent* FUN_1403c5b40() { return new GameEventMassiveConstructionEvent; }

// @0x1403c5ba0
CStringW GameEventMassiveConstructionEvent::GetTypeName() { return CStringW(L"GameEventMassiveConstructionEvent"); }
MS2_REPLACE_METHOD(0x1403C5BA0, GameEventMassiveConstructionEvent, GetTypeName, 61, 0x76A01F5C);

// @0x1403c5bf0
GameEventMassiveConstructionEvent::GameEventMassiveConstructionEvent()
{
    m_d0.RemoveAll();
    m_f0 = 0;
    m_f8.RemoveAll();
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c5cb0
void GameEventMassiveConstructionEvent::vfunc_2()
{
    FUN_140274fc0(m_68, &m_d0, L",");
    m_f0 = FUN_1407181a0(m_70);
    ParseUInt64List(m_78, m_f8, L",");
}
MS2_REPLACE_METHOD(0x1403C5CB0, GameEventMassiveConstructionEvent, vfunc_2, 112, 0xEF12FB45);

// @0x1403c5d30
void GameEventMassiveConstructionEvent::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    unsigned nCount = (unsigned)m_d0.GetCount();
    out->WriteInt(nCount);
    for (size_t i = 0; i < nCount; i++)
        out->WriteInt(m_d0[i]);
    out->WriteInt(m_f0);
    nCount = (unsigned)m_f8.GetCount();
    out->WriteInt(nCount);
    for (size_t i = 0; i < nCount; i++)
        out->WriteInt64(m_f8[i]);
}
MS2_REPLACE_METHOD(0x1403C5D30, GameEventMassiveConstructionEvent, vfunc_3, 326, 0x892A9D0B);

// @0x1403c5e80
void GameEventMassiveConstructionEvent::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    unsigned nCount = MS2_GE_R(in)->ReadInt();
    for (unsigned i = 0; i < nCount; i++)
    {
        unsigned id = MS2_GE_R(in)->ReadInt();
        m_d0.Add(id);
    }
    m_f0 = MS2_GE_R(in)->ReadInt();
    nCount = MS2_GE_R(in)->ReadInt();
    for (unsigned i = 0; i < nCount; i++)
    {
        unsigned __int64 id = MS2_GE_R(in)->ReadInt64();
        m_f8.Add(id);
    }
}
MS2_REPLACE_METHOD(0x1403C5E80, GameEventMassiveConstructionEvent, vfunc_4, 343, 0x425DC70D);

// @0x1403c5fe0
void GameEventMassiveConstructionEvent::OnStart()
{
    for (unsigned i = 0; i < m_d0.GetCount(); i++)
    {
        unsigned id = m_d0[i];
        ((class CGameRule*)GetGameRule())->FUN_14047dba0(id, m_f0);
    }
    for (unsigned i = 0; i < m_f8.GetCount(); i++)
    {
        unsigned __int64 id = m_f8[i];
        ((class CGameRule*)GetGameRule())->FUN_14047df50(id);
    }
}
MS2_REPLACE_METHOD(0x1403C5FE0, GameEventMassiveConstructionEvent, OnStart, 237, 0x4814B149);

// @0x1403c60e0
void GameEventMassiveConstructionEvent::vfunc_6()
{
    ((class CGameRule*)GetGameRule())->FUN_14047dd60();
    ((class CGameRule*)GetGameRule())->FUN_14047e0e0();
}
MS2_REPLACE_METHOD(0x1403C60E0, GameEventMassiveConstructionEvent, vfunc_6, 40, 0xDC8EBBD4);

// ---- GameEventEnchantRate -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regEnchantRate(L"GameEventEnchantRate", (ClassObjectCreateFn)FUN_1403c6110);
#endif
// @0x1403c6110
GameEvent* FUN_1403c6110() { return new GameEventEnchantRate; }

// @0x1403c6170
CStringW GameEventEnchantRate::GetTypeName() { return CStringW(L"GameEventEnchantRate"); }
MS2_REPLACE_METHOD(0x1403C6170, GameEventEnchantRate, GetTypeName, 61, 0x5D3710E8);

// @0x1403c61c0
GameEventEnchantRate::GameEventEnchantRate()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c6230
void GameEventEnchantRate::vfunc_2()
{
    m_pContext.AssignRaw(new EnchantRateEventContext);
    m_pContext->m_nEventId = m_id;
    m_pContext->m_1c = FUN_140718200(m_68);
    m_pContext->m_20 = FUN_140718200(m_70);
}
MS2_REPLACE_METHOD(0x1403C6230, GameEventEnchantRate, vfunc_2, 226, 0x01175DDE);

// @0x1403c6320
void GameEventEnchantRate::OnStart() { ((class CGameRule*)GetGameRule())->AddEnchantRateEvent(m_pContext); }
MS2_REPLACE_METHOD(0x1403C6320, GameEventEnchantRate, OnStart, 91, 0x69FE65A3);

// @0x1403c6390
void GameEventEnchantRate::vfunc_6()
{
    // the original asserts on its member names (m_gameEventID is m_id)
    (void)((!!(m_pContext->m_nEventId == m_id)) ||
           (_wassert(L"m_pContext->m_nEventId == m_gameEventID", _CRT_WIDE(MS2_THIS_FILE), MS2_LINE(2384)), 0));
    ((class CGameRule*)GetGameRule())->RemoveEnchantRateEvent(m_pContext->m_nEventId);
}
MS2_REPLACE_METHOD(0x1403C6390, GameEventEnchantRate, vfunc_6, 119, 0x542B45BA);

// @0x1403c6410
void GameEventEnchantRate::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_pContext->m_1c);
    out->WriteInt(m_pContext->m_20);
}
MS2_REPLACE_METHOD(0x1403C6410, GameEventEnchantRate, vfunc_3, 130, 0x62E36E92);

// @0x1403c64a0
void GameEventEnchantRate::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_pContext.AssignRaw(new EnchantRateEventContext);
    m_pContext->m_nEventId = m_id;
    m_pContext->m_1c = MS2_GE_R(in)->ReadInt();
    m_pContext->m_20 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C64A0, GameEventEnchantRate, vfunc_4, 280, 0x5427E70E);

// ---- GameEventRankDuel ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regRankDuel(L"GameEventRankDuel", (ClassObjectCreateFn)FUN_1403c65c0);
#endif
// @0x1403c65c0
GameEvent* FUN_1403c65c0() { return new GameEventRankDuel; }

// @0x1403c6620
CStringW GameEventRankDuel::GetTypeName() { return CStringW(L"GameEventRankDuel"); }
MS2_REPLACE_METHOD(0x1403C6620, GameEventRankDuel, GetTypeName, 61, 0xD0C386DB);

// @0x1403c6670
GameEventRankDuel::GameEventRankDuel() : m_d8(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c66f0
void GameEventRankDuel::vfunc_2()
{
    m_d0 = m_68;
    if (!m_80.IsEmpty())
        m_d8 = FUN_1407181a0(m_80);
}
MS2_REPLACE_METHOD(0x1403C66F0, GameEventRankDuel, vfunc_2, 101, 0x3F1E221E);

// @0x1403c6760
void GameEventRankDuel::OnStart() { ((class CGameRule*)GetGameRule())->SetRankDuelOpen(true); }
MS2_REPLACE_METHOD(0x1403C6760, GameEventRankDuel, OnStart, 29, 0xCD62C311);

// @0x1403c6790
void GameEventRankDuel::vfunc_6() { ((class CGameRule*)GetGameRule())->SetRankDuelOpen(false); }
MS2_REPLACE_METHOD(0x1403C6790, GameEventRankDuel, vfunc_6, 29, 0x2805BD5A);

// @0x1403c67c0
void GameEventRankDuel::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
}
MS2_REPLACE_METHOD(0x1403C67C0, GameEventRankDuel, vfunc_3, 74, 0xACFA5F52);

// @0x1403c6810
void GameEventRankDuel::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C6810, GameEventRankDuel, vfunc_4, 134, 0x1C2FF7FE);

// ---- GameEventGuildChampionship -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGuildChampionship(L"GameEventGuildChampionship", (ClassObjectCreateFn)FUN_1403c68a0);
#endif
// @0x1403c68a0
GameEvent* FUN_1403c68a0() { return new GameEventGuildChampionship; }

// @0x1403c6900
CStringW GameEventGuildChampionship::GetTypeName() { return CStringW(L"GameEventGuildChampionship"); }
MS2_REPLACE_METHOD(0x1403C6900, GameEventGuildChampionship, GetTypeName, 61, 0x275F1859);

// @0x1403c6950
GameEventGuildChampionship::GameEventGuildChampionship() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c69c0
void GameEventGuildChampionship::vfunc_2()
{
    if (!m_80.IsEmpty())
        m_d0 = FUN_1407181a0(m_80);
}
MS2_REPLACE_METHOD(0x1403C69C0, GameEventGuildChampionship, vfunc_2, 71, 0x83221AF0);

// @0x1403c6a10
void GameEventGuildChampionship::OnStart()
{
    if (!TSingleton<CFeatureManager>::GetInstance()->IsFeatureEnabled(0x110))
        return;
    ((class CGameRule*)GetGameRule())->SetGuildChampionshipOpen(true);
}
MS2_REPLACE_METHOD(0x1403C6A10, GameEventGuildChampionship, OnStart, 56, 0x274DE2BB);

// @0x1403c6a50
void GameEventGuildChampionship::vfunc_6() { ((class CGameRule*)GetGameRule())->SetGuildChampionshipOpen(false); }
MS2_REPLACE_METHOD(0x1403C6A50, GameEventGuildChampionship, vfunc_6, 29, 0x2BB70B0E);

// ---- GameEventQuestAdditionalReward ---------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regQuestAdditionalReward(L"GameEventQuestAdditionalReward", (ClassObjectCreateFn)FUN_1403c6a80);
#endif
// @0x1403c6a80
GameEvent* FUN_1403c6a80() { return new GameEventQuestAdditionalReward; }

// @0x1403c6ae0
CStringW GameEventQuestAdditionalReward::GetTypeName() { return CStringW(L"GameEventQuestAdditionalReward"); }
MS2_REPLACE_METHOD(0x1403C6AE0, GameEventQuestAdditionalReward, GetTypeName, 61, 0xFA4D8A7E);

// @0x1403c6b30
GameEventQuestAdditionalReward::GameEventQuestAdditionalReward()
{
    SetFlag(1);
    SetFlag(3);
    m_d0 = 11;
    m_d4 = 0;
    m_d8.AssignRaw(new QuestAdditionalRewardContext);
}

// @0x1403c6c10
void GameEventQuestAdditionalReward::vfunc_2()
{
    m_d0 = FUN_1407181a0(m_68);
    m_d4 = FUN_1407181a0(m_70);
    m_d8->Load(&m_78);
}
MS2_REPLACE_METHOD(0x1403C6C10, GameEventQuestAdditionalReward, vfunc_2, 117, 0xF78122DB);

// @0x1403c6c90
void GameEventQuestAdditionalReward::OnStart() { ((class CGameRule*)GetGameRule())->SetQuestAdditionalReward(m_d0, m_d4, m_d8); }
MS2_REPLACE_METHOD(0x1403C6C90, GameEventQuestAdditionalReward, OnStart, 114, 0x99961A1D);

// @0x1403c6d10
void GameEventQuestAdditionalReward::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveQuestAdditionalReward(m_d0, m_d4); }
MS2_REPLACE_METHOD(0x1403C6D10, GameEventQuestAdditionalReward, vfunc_6, 50, 0xF99DD3D4);

// @0x1403c6d50
void GameEventQuestAdditionalReward::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteShort((unsigned short)m_d0);
    out->WriteShort((unsigned short)m_d4);
    m_d8->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403C6D50, GameEventQuestAdditionalReward, vfunc_3, 122, 0x31131576);

// @0x1403c6dd0
void GameEventQuestAdditionalReward::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadShort();
    m_d4 = MS2_GE_R(in)->ReadShort();
    m_d8->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403C6DD0, GameEventQuestAdditionalReward, vfunc_4, 162, 0x62AD7514);

// ---- GameEventGuildSkillSale ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGuildSkillSale(L"GameEventGuildSkillSale", (ClassObjectCreateFn)FUN_1403c6e80);
#endif
// @0x1403c6e80
GameEvent* FUN_1403c6e80() { return new GameEventGuildSkillSale; }

// @0x1403c6ee0
CStringW GameEventGuildSkillSale::GetTypeName() { return CStringW(L"GameEventGuildSkillSale"); }
MS2_REPLACE_METHOD(0x1403C6EE0, GameEventGuildSkillSale, GetTypeName, 61, 0x353F259E);

// @0x1403c6f30
GameEventGuildSkillSale::GameEventGuildSkillSale() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c6fa0
void GameEventGuildSkillSale::vfunc_2() { m_d0 = FUN_1407181a0(m_68); }
MS2_REPLACE_METHOD(0x1403C6FA0, GameEventGuildSkillSale, vfunc_2, 42, 0x02B16B0B);

// @0x1403c6fd0
void GameEventGuildSkillSale::OnStart() { ((class CGameEventValueGuildSkillSale*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildSkillSale()))->SetRate(m_d0); }
MS2_REPLACE_METHOD(0x1403C6FD0, GameEventGuildSkillSale, OnStart, 46, 0x396ECFED);

// @0x1403c7010
void GameEventGuildSkillSale::vfunc_6() { ((class CGameEventValueGuildSkillSale*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildSkillSale()))->SetRate(0); }
MS2_REPLACE_METHOD(0x1403C7010, GameEventGuildSkillSale, vfunc_6, 37, 0xA05B3701);

// @0x1403c7040
void GameEventGuildSkillSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C7040, GameEventGuildSkillSale, vfunc_3, 61, 0xCB9AEBE1);

// @0x1403c7090
void GameEventGuildSkillSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C7090, GameEventGuildSkillSale, vfunc_4, 79, 0xF3AF033C);

// ---- GameEventGuildPersonalSkillSale --------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGuildPersonalSkillSale(L"GameEventGuildPersonalSkillSale", (ClassObjectCreateFn)FUN_1403c70f0);
#endif
// @0x1403c70f0
GameEvent* FUN_1403c70f0() { return new GameEventGuildPersonalSkillSale; }

// @0x1403c7150
CStringW GameEventGuildPersonalSkillSale::GetTypeName() { return CStringW(L"GameEventGuildPersonalSkillSale"); }
MS2_REPLACE_METHOD(0x1403C7150, GameEventGuildPersonalSkillSale, GetTypeName, 61, 0x4C2BD31D);

// @0x1403c71a0
GameEventGuildPersonalSkillSale::GameEventGuildPersonalSkillSale() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c7210
void GameEventGuildPersonalSkillSale::vfunc_2() { m_d0 = FUN_1407181a0(m_68); }
MS2_REPLACE_METHOD(0x1403C7210, GameEventGuildPersonalSkillSale, vfunc_2, 42, 0xE4F2E4E1);

// @0x1403c7240
void GameEventGuildPersonalSkillSale::OnStart() { ((class CGameEventValueGuildPersonalSkillSale*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildPersonalSkillSale()))->SetRate(m_d0); }
MS2_REPLACE_METHOD(0x1403C7240, GameEventGuildPersonalSkillSale, OnStart, 46, 0xB5FD3289);

// @0x1403c7280
void GameEventGuildPersonalSkillSale::vfunc_6() { ((class CGameEventValueGuildPersonalSkillSale*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildPersonalSkillSale()))->SetRate(0); }
MS2_REPLACE_METHOD(0x1403C7280, GameEventGuildPersonalSkillSale, vfunc_6, 37, 0x74E6D016);

// @0x1403c72b0
void GameEventGuildPersonalSkillSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C72B0, GameEventGuildPersonalSkillSale, vfunc_3, 61, 0xA598974C);

// @0x1403c7300
void GameEventGuildPersonalSkillSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C7300, GameEventGuildPersonalSkillSale, vfunc_4, 79, 0x85989779);

// ---- GameEventGuildExp ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGuildExp(L"GameEventGuildExp", (ClassObjectCreateFn)FUN_1403c7360);
#endif
// @0x1403c7360
GameEvent* FUN_1403c7360() { return new GameEventGuildExp; }

// @0x1403c73c0
CStringW GameEventGuildExp::GetTypeName() { return CStringW(L"GameEventGuildExp"); }
MS2_REPLACE_METHOD(0x1403C73C0, GameEventGuildExp, GetTypeName, 61, 0x872D1709);

// @0x1403c7410
GameEventGuildExp::GameEventGuildExp() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c7480
void GameEventGuildExp::vfunc_2() { m_d0 = FUN_1407181a0(m_68); }
MS2_REPLACE_METHOD(0x1403C7480, GameEventGuildExp, vfunc_2, 42, 0x65204B4F);

// @0x1403c74b0
void GameEventGuildExp::OnStart()
{
    ((CGameEventValueGuildExp*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildExp()))->SetRate(m_d0);
    TSingleton<CGuildManager>::GetInstance()->SetGuildExpEvent(((unsigned)((CGameEventValueGuildExp*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildExp()))->GetRate()) > 0);
}
MS2_REPLACE_METHOD(0x1403C74B0, GameEventGuildExp, OnStart, 101, 0xE18D34FE);

// @0x1403c7520
void GameEventGuildExp::vfunc_6()
{
    ((CGameEventValueGuildExp*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildExp()))->SetRate(0);
    TSingleton<CGuildManager>::GetInstance()->SetGuildExpEvent(((unsigned)((CGameEventValueGuildExp*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildExp()))->GetRate()) > 0);
}
MS2_REPLACE_METHOD(0x1403C7520, GameEventGuildExp, vfunc_6, 92, 0x199CB83D);

// @0x1403c7590
void GameEventGuildExp::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C7590, GameEventGuildExp, vfunc_3, 61, 0xD36E6E5B);

// @0x1403c75e0
void GameEventGuildExp::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C75E0, GameEventGuildExp, vfunc_4, 79, 0x4BB6E3B6);

// ---- GameEventGuildFund ---------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGuildFund(L"GameEventGuildFund", (ClassObjectCreateFn)FUN_1403c7640);
#endif
// @0x1403c7640
GameEvent* FUN_1403c7640() { return new GameEventGuildFund; }

// @0x1403c76a0
CStringW GameEventGuildFund::GetTypeName() { return CStringW(L"GameEventGuildFund"); }
MS2_REPLACE_METHOD(0x1403C76A0, GameEventGuildFund, GetTypeName, 61, 0x6B63AA40);

// @0x1403c76f0
GameEventGuildFund::GameEventGuildFund() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c7760
void GameEventGuildFund::vfunc_2() { m_d0 = FUN_1407181a0(m_68); }
MS2_REPLACE_METHOD(0x1403C7760, GameEventGuildFund, vfunc_2, 42, 0x82DACA1A);

// @0x1403c7790
void GameEventGuildFund::OnStart() { ((class CGameEventValueGuildFund*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildFund()))->SetRate(m_d0); }
MS2_REPLACE_METHOD(0x1403C7790, GameEventGuildFund, OnStart, 46, 0x48EF6819);

// @0x1403c77d0
void GameEventGuildFund::vfunc_6() { ((class CGameEventValueGuildFund*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildFund()))->SetRate(0); }
MS2_REPLACE_METHOD(0x1403C77D0, GameEventGuildFund, vfunc_6, 37, 0x6FB11BD3);

// @0x1403c7800
void GameEventGuildFund::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C7800, GameEventGuildFund, vfunc_3, 61, 0x6C56B339);

// @0x1403c7850
void GameEventGuildFund::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C7850, GameEventGuildFund, vfunc_4, 79, 0xCC7FB574);

// ---- GameEventGuildCoin ---------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGuildCoin(L"GameEventGuildCoin", (ClassObjectCreateFn)FUN_1403c78b0);
#endif
// @0x1403c78b0
GameEvent* FUN_1403c78b0() { return new GameEventGuildCoin; }

// @0x1403c7910
CStringW GameEventGuildCoin::GetTypeName() { return CStringW(L"GameEventGuildCoin"); }
MS2_REPLACE_METHOD(0x1403C7910, GameEventGuildCoin, GetTypeName, 61, 0x362C4297);

// @0x1403c7960
GameEventGuildCoin::GameEventGuildCoin() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c79d0
void GameEventGuildCoin::vfunc_2() { m_d0 = FUN_1407181a0(m_68); }
MS2_REPLACE_METHOD(0x1403C79D0, GameEventGuildCoin, vfunc_2, 42, 0x0E909E99);

// @0x1403c7a00
void GameEventGuildCoin::OnStart() { ((class CGameEventValueGuildCoin*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildCoin()))->SetRate(m_d0); }
MS2_REPLACE_METHOD(0x1403C7A00, GameEventGuildCoin, OnStart, 46, 0x16A44E78);

// @0x1403c7a40
void GameEventGuildCoin::vfunc_6() { ((class CGameEventValueGuildCoin*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GuildCoin()))->SetRate(0); }
MS2_REPLACE_METHOD(0x1403C7A40, GameEventGuildCoin, vfunc_6, 37, 0xD8029974);

// @0x1403c7a70
void GameEventGuildCoin::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C7A70, GameEventGuildCoin, vfunc_3, 61, 0x0B1A74CF);

// @0x1403c7ac0
void GameEventGuildCoin::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C7AC0, GameEventGuildCoin, vfunc_4, 79, 0x114CC551);

// ---- GameEventMasteryReward -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regMasteryReward(L"GameEventMasteryReward", (ClassObjectCreateFn)FUN_1403c7b20);
#endif
// @0x1403c7b20
GameEvent* FUN_1403c7b20() { return new GameEventMasteryReward; }

// @0x1403c7b80
CStringW GameEventMasteryReward::GetTypeName() { return CStringW(L"GameEventMasteryReward"); }
MS2_REPLACE_METHOD(0x1403C7B80, GameEventMasteryReward, GetTypeName, 61, 0xD35040E8);

// @0x1403c7bd0
GameEventMasteryReward::GameEventMasteryReward()
{
    SetFlag(1);
    SetFlag(3);
    m_d0 = 0;
}

// @0x1403c7c50
void GameEventMasteryReward::vfunc_2()
{
    m_d0 = FUN_1407181a0(m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403C7C50, GameEventMasteryReward, vfunc_2, 72, 0x8C04152C);

// @0x1403c7ca0
void GameEventMasteryReward::OnStart()
{
    if (m_d0 == 0)
        return;
    reinterpret_cast<CGameEventValueMasteryReward*>(TSingleton<CGameEventValueManager>::GetInstance()->MasteryReward())->Load(m_id, m_d0, m_d8);
}
MS2_REPLACE_METHOD(0x1403C7CA0, GameEventMasteryReward, OnStart, 95, 0xCEFD2DB8);

// @0x1403c7d10
void GameEventMasteryReward::vfunc_6() { ((class CGameEventValueMasteryReward*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->MasteryReward()))->Remove(m_id); }
MS2_REPLACE_METHOD(0x1403C7D10, GameEventMasteryReward, vfunc_6, 43, 0x57F16CC7);

// @0x1403c7d50
void GameEventMasteryReward::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403C7D50, GameEventMasteryReward, vfunc_3, 101, 0x0F899DB2);

// @0x1403c7dc0
void GameEventMasteryReward::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C7DC0, GameEventMasteryReward, vfunc_4, 179, 0x2141B150);

// ---- GameEventMeratMarketOpenTab ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regMeratMarketOpenTab(L"GameEventMeratMarketOpenTab", (ClassObjectCreateFn)FUN_1403c7e80);
#endif
// @0x1403c7e80
GameEvent* FUN_1403c7e80() { return new GameEventMeratMarketOpenTab; }

// @0x1403c7ee0
CStringW GameEventMeratMarketOpenTab::GetTypeName() { return CStringW(L"GameEventMeratMarketOpenTab"); }
MS2_REPLACE_METHOD(0x1403C7EE0, GameEventMeratMarketOpenTab, GetTypeName, 61, 0x4E8C3DA0);

// @0x1403c7f30
GameEventMeratMarketOpenTab::GameEventMeratMarketOpenTab()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c7fa0
void GameEventMeratMarketOpenTab::vfunc_2() { m_d0 = FUN_140718600(m_68); }
MS2_REPLACE_METHOD(0x1403C7FA0, GameEventMeratMarketOpenTab, vfunc_2, 97, 0xAA34B383);

// @0x1403c8010
void GameEventMeratMarketOpenTab::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
}
MS2_REPLACE_METHOD(0x1403C8010, GameEventMeratMarketOpenTab, vfunc_3, 74, 0x33840CEA);

// @0x1403c8060
void GameEventMeratMarketOpenTab::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C8060, GameEventMeratMarketOpenTab, vfunc_4, 134, 0xBFB0DF06);

// @0x1403c80f0
void GameEventMeratMarketOpenTab::OnStart() { reinterpret_cast<CGameEventValueMeratMarketOpenTab*>(TSingleton<CGameEventValueManager>::GetInstance()->MeratMarketOpenTab())->SetTab(m_d0); }
MS2_REPLACE_METHOD(0x1403C80F0, GameEventMeratMarketOpenTab, OnStart, 59, 0x623AFBA5);

// @0x1403c8140
void GameEventMeratMarketOpenTab::vfunc_6()
{
    CStringW strEmpty(L"");
    reinterpret_cast<CGameEventValueMeratMarketOpenTab*>(TSingleton<CGameEventValueManager>::GetInstance()->MeratMarketOpenTab())->SetTab(strEmpty);
}
MS2_REPLACE_METHOD(0x1403C8140, GameEventMeratMarketOpenTab, vfunc_6, 80, 0x2E26EE7B);

// ---- GameEventWorldmapIcon ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regWorldmapIcon(L"GameEventWorldmapIcon", (ClassObjectCreateFn)FUN_1403c81a0);
#endif
// @0x1403c81a0
GameEvent* FUN_1403c81a0() { return new GameEventWorldmapIcon; }

// @0x1403c8200
CStringW GameEventWorldmapIcon::GetTypeName() { return CStringW(L"GameEventWorldmapIcon"); }
MS2_REPLACE_METHOD(0x1403C8200, GameEventWorldmapIcon, GetTypeName, 61, 0x9F63268F);

// @0x1403c8250
GameEventWorldmapIcon::GameEventWorldmapIcon()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c82c0
void GameEventWorldmapIcon::vfunc_2() { m_d0 = m_68; }
MS2_REPLACE_METHOD(0x1403C82C0, GameEventWorldmapIcon, vfunc_2, 44, 0x3A4EA00A);

// @0x1403c8300
void GameEventWorldmapIcon::OnStart() {}
MS2_REPLACE_METHOD(0x1403C8300, GameEventWorldmapIcon, OnStart, 6, 0xA9AF6E37);

// @0x1403c8310
void GameEventWorldmapIcon::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403C8310, GameEventWorldmapIcon, vfunc_6, 6, 0xA9AF6E37);

// @0x1403c8320
void GameEventWorldmapIcon::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
}
MS2_REPLACE_METHOD(0x1403C8320, GameEventWorldmapIcon, vfunc_3, 74, 0x90D7B421);

// @0x1403c8370
void GameEventWorldmapIcon::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C8370, GameEventWorldmapIcon, vfunc_4, 134, 0x4F43BF29);

// ---- GameEventMasteryReduce -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regMasteryReduce(L"GameEventMasteryReduce", (ClassObjectCreateFn)FUN_1403c8400);
#endif
// @0x1403c8400
GameEvent* FUN_1403c8400() { return new GameEventMasteryReduce; }

// @0x1403c8460
CStringW GameEventMasteryReduce::GetTypeName() { return CStringW(L"GameEventMasteryReduce"); }
MS2_REPLACE_METHOD(0x1403C8460, GameEventMasteryReduce, GetTypeName, 61, 0x6E5ADEFA);

// @0x1403c84b0
GameEventMasteryReduce::GameEventMasteryReduce()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c8510
void GameEventMasteryReduce::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403C8510, GameEventMasteryReduce, vfunc_2, 42, 0xD5B9BC39);

// @0x1403c8540
void GameEventMasteryReduce::OnStart() { ((class CGameEventValueMasteryReduce*)(struct Unk_GameEventIntValue*)(TSingleton<CGameEventValueManager>::GetInstance()->MasteryReduce()))->SetRate(m_d0); }
MS2_REPLACE_METHOD(0x1403C8540, GameEventMasteryReduce, OnStart, 46, 0x889011F9);

// @0x1403c8580
void GameEventMasteryReduce::vfunc_6() { ((class CGameEventValueMasteryReduce*)(struct Unk_GameEventIntValue*)(TSingleton<CGameEventValueManager>::GetInstance()->MasteryReduce()))->SetRate(0); }
MS2_REPLACE_METHOD(0x1403C8580, GameEventMasteryReduce, vfunc_6, 37, 0x3AE96BBF);

// @0x1403c85b0
void GameEventMasteryReduce::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C85B0, GameEventMasteryReduce, vfunc_3, 61, 0x716A8CCB);

// @0x1403c8600
void GameEventMasteryReduce::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C8600, GameEventMasteryReduce, vfunc_4, 79, 0x568F6686);

// ---- GameEventUGCMapContractSale ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regUGCMapContractSale(L"GameEventUGCMapContractSale", (ClassObjectCreateFn)FUN_1403c8660);
#endif
// @0x1403c8660
GameEvent* FUN_1403c8660() { return new GameEventUGCMapContractSale; }

// @0x1403c86c0
CStringW GameEventUGCMapContractSale::GetTypeName() { return CStringW(L"GameEventUGCMapContractSale"); }
MS2_REPLACE_METHOD(0x1403C86C0, GameEventUGCMapContractSale, GetTypeName, 61, 0x1AF8ADCA);

// @0x1403c8710
GameEventUGCMapContractSale::GameEventUGCMapContractSale() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c8780
void GameEventUGCMapContractSale::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403C8780, GameEventUGCMapContractSale, vfunc_2, 42, 0x28D4D427);

// @0x1403c87b0
void GameEventUGCMapContractSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C87B0, GameEventUGCMapContractSale, vfunc_3, 61, 0x83765A39);

// @0x1403c8800
void GameEventUGCMapContractSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C8800, GameEventUGCMapContractSale, vfunc_4, 79, 0x3CEA8454);

// @0x1403c8860
void GameEventUGCMapContractSale::OnStart() { ((class CGameRule*)GetGameRule())->SetUgcMapContractSaleRate(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403C8860, GameEventUGCMapContractSale, OnStart, 47, 0x1E1D85C1);

// @0x1403c88a0
void GameEventUGCMapContractSale::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveUgcMapContractSaleRate(m_id); }
MS2_REPLACE_METHOD(0x1403C88A0, GameEventUGCMapContractSale, vfunc_6, 35, 0x88C86AFF);

// ---- GameEventUGCMapExtensionSale -----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regUGCMapExtensionSale(L"GameEventUGCMapExtensionSale", (ClassObjectCreateFn)FUN_1403c88d0);
#endif
// @0x1403c88d0
GameEvent* FUN_1403c88d0() { return new GameEventUGCMapExtensionSale; }

// @0x1403c8930
CStringW GameEventUGCMapExtensionSale::GetTypeName() { return CStringW(L"GameEventUGCMapExtensionSale"); }
MS2_REPLACE_METHOD(0x1403C8930, GameEventUGCMapExtensionSale, GetTypeName, 61, 0x164B8C71);

// @0x1403c8980
GameEventUGCMapExtensionSale::GameEventUGCMapExtensionSale() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c89f0
void GameEventUGCMapExtensionSale::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403C89F0, GameEventUGCMapExtensionSale, vfunc_2, 42, 0xEAD35C6C);

// @0x1403c8a20
void GameEventUGCMapExtensionSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C8A20, GameEventUGCMapExtensionSale, vfunc_3, 61, 0x60A945AF);

// @0x1403c8a70
void GameEventUGCMapExtensionSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C8A70, GameEventUGCMapExtensionSale, vfunc_4, 79, 0x4C71D44A);

// @0x1403c8ad0
void GameEventUGCMapExtensionSale::OnStart() { ((class CGameRule*)GetGameRule())->SetUgcMapExtensionSaleRate(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403C8AD0, GameEventUGCMapExtensionSale, OnStart, 47, 0x7ABE58BB);

// @0x1403c8b10
void GameEventUGCMapExtensionSale::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveUgcMapExtensionSaleRate(m_id); }
MS2_REPLACE_METHOD(0x1403C8B10, GameEventUGCMapExtensionSale, vfunc_6, 35, 0xB5927B20);

// ---- GameEventConstructShowItem -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regConstructShowItem(L"GameEventConstructShowItem", (ClassObjectCreateFn)FUN_1403c8b40);
#endif
// @0x1403c8b40
GameEvent* FUN_1403c8b40() { return new GameEventConstructShowItem; }

// @0x1403c8ba0
CStringW GameEventConstructShowItem::GetTypeName() { return CStringW(L"GameEventConstructShowItem"); }
MS2_REPLACE_METHOD(0x1403C8BA0, GameEventConstructShowItem, GetTypeName, 61, 0x16234975);

// @0x1403c8bf0
GameEventConstructShowItem::GameEventConstructShowItem() : m_d0(0), m_d8(L""), m_e0(0), m_108(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c8cb0
void GameEventConstructShowItem::vfunc_2()
{
    m_d0 = FUN_140718200(m_68);
    m_d8 = FUN_140718600(m_70);
    m_e0 = FUN_140718200(m_78);
    FUN_140274fc0(m_80, &m_e8, L",");
}
MS2_REPLACE_METHOD(0x1403C8CB0, GameEventConstructShowItem, vfunc_2, 191, 0x8BED3EDA);

// @0x1403c8d80
void GameEventConstructShowItem::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
    out->WriteShort((unsigned short)m_e0);
    out->WriteShort((unsigned short)m_e8.GetCount());
    for (size_t i = 0; i < m_e8.GetCount(); i++)
    {
        unsigned nItemId = m_e8[i];
        out->WriteInt(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403C8D80, GameEventConstructShowItem, vfunc_3, 279, 0x091D9521);

// @0x1403c8ea0
void GameEventConstructShowItem::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
    m_e0 = MS2_GE_R(in)->ReadShort();
    size_t nCount = MS2_GE_R(in)->ReadShort();
    for (size_t i = 0; i < nCount; i++)
    {
        unsigned nItemId = MS2_GE_R(in)->ReadInt();
        m_e8.Add(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403C8EA0, GameEventConstructShowItem, vfunc_4, 422, 0x0FEEC4C1);

// @0x1403c9050
void GameEventConstructShowItem::OnStart()
{
    if (m_d8.IsEmpty())
        m_108 = AddBoxById(m_d0, m_e0);
    else
        m_108 = AddBoxByName(m_d8, m_e0);
    for (unsigned i = 0; i < m_e8.GetCount(); i++)
    {
        unsigned nItemId = m_e8[i];
        FUN_140df1f40(m_108, nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403C9050, GameEventConstructShowItem, OnStart, 260, 0xE6FCC000);

// @0x1403c9160
void GameEventConstructShowItem::vfunc_6() { RemoveBox(m_108); }
MS2_REPLACE_METHOD(0x1403C9160, GameEventConstructShowItem, vfunc_6, 30, 0x417D1A43);

// ---- GameEventTransferItemBound -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regTransferItemBound(L"GameEventTransferItemBound", (ClassObjectCreateFn)FUN_1403c9190);
#endif
// @0x1403c9190
GameEvent* FUN_1403c9190() { return new GameEventTransferItemBound; }

// @0x1403c91f0
CStringW GameEventTransferItemBound::GetTypeName() { return CStringW(L"GameEventTransferItemBound"); }
MS2_REPLACE_METHOD(0x1403C91F0, GameEventTransferItemBound, GetTypeName, 61, 0x055A17FE);

// @0x1403c9240
GameEventTransferItemBound::GameEventTransferItemBound() : m_d0(true)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c92b0
void GameEventTransferItemBound::vfunc_2()
{
    if (!m_68.IsEmpty())
        m_d0 = FUN_1407183f0(m_68);
}
MS2_REPLACE_METHOD(0x1403C92B0, GameEventTransferItemBound, vfunc_2, 67, 0x41D5E5F7);

// @0x1403c9300
void GameEventTransferItemBound::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteBool(m_d0);
}
MS2_REPLACE_METHOD(0x1403C9300, GameEventTransferItemBound, vfunc_3, 61, 0xE304EFF0);

// @0x1403c9350
void GameEventTransferItemBound::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadBool();
}
MS2_REPLACE_METHOD(0x1403C9350, GameEventTransferItemBound, vfunc_4, 78, 0x7AF36612);

// @0x1403c93b0
void GameEventTransferItemBound::OnStart() { ((class CGameRule*)GetGameRule())->SetTransferItemBound(m_d0); }
MS2_REPLACE_METHOD(0x1403C93B0, GameEventTransferItemBound, OnStart, 39, 0x1D75E411);

// @0x1403c93e0
void GameEventTransferItemBound::vfunc_6() { ((class CGameRule*)GetGameRule())->SetTransferItemBound(!m_d0); }
MS2_REPLACE_METHOD(0x1403C93E0, GameEventTransferItemBound, vfunc_6, 60, 0xFF7D7960);

// ---- GameEventSaleItemsRestricted -----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleItemsRestricted(L"GameEventSaleItemsRestricted", (ClassObjectCreateFn)FUN_1403c9430);
#endif
// @0x1403c9430
GameEvent* FUN_1403c9430() { return new GameEventSaleItemsRestricted; }

// @0x1403c9490
CStringW GameEventSaleItemsRestricted::GetTypeName() { return CStringW(L"GameEventSaleItemsRestricted"); }
MS2_REPLACE_METHOD(0x1403C9490, GameEventSaleItemsRestricted, GetTypeName, 61, 0x5751C17B);

// @0x1403c94e0
GameEventSaleItemsRestricted::GameEventSaleItemsRestricted()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c9550
void GameEventSaleItemsRestricted::vfunc_2()
{
    if (!m_68.IsEmpty())
        FUN_140274fc0(m_68, &m_d0, CStringW(","));
}
MS2_REPLACE_METHOD(0x1403C9550, GameEventSaleItemsRestricted, vfunc_2, 149, 0x2587F906);

// @0x1403c95f0
void GameEventSaleItemsRestricted::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    MS2_GE_OUT(out) << m_d0;
}
MS2_REPLACE_METHOD(0x1403C95F0, GameEventSaleItemsRestricted, vfunc_3, 58, 0x0C2E8B42);

// @0x1403c9630
void GameEventSaleItemsRestricted::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.RemoveAll();
    MS2_GE_IN(in) >> m_d0;
}
MS2_REPLACE_METHOD(0x1403C9630, GameEventSaleItemsRestricted, vfunc_4, 81, 0x89DCC8A7);

// @0x1403c9690
void GameEventSaleItemsRestricted::OnStart()
{
    if (m_d0.IsEmpty())
        return;
    reinterpret_cast<CGameEventValueSaleItemsRestricted*>(TSingleton<CGameEventValueManager>::GetInstance()->SaleItemsRestricted())->SetItems(m_d0);
}
MS2_REPLACE_METHOD(0x1403C9690, GameEventSaleItemsRestricted, OnStart, 87, 0xA29CA15B);

// @0x1403c96f0
void GameEventSaleItemsRestricted::vfunc_6() { ((class CGameEventValueSaleItemsRestricted*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->SaleItemsRestricted()))->Clear(); }
MS2_REPLACE_METHOD(0x1403C96F0, GameEventSaleItemsRestricted, vfunc_6, 35, 0xE41DF6E7);

// ---- GameEventUgcMapCommendationGM ----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regUgcMapCommendationGM(L"GameEventUgcMapCommendationGM", (ClassObjectCreateFn)FUN_1403c9720);
#endif
// @0x1403c9720
GameEvent* FUN_1403c9720() { return new GameEventUgcMapCommendationGM; }

// @0x1403c9780
CStringW GameEventUgcMapCommendationGM::GetTypeName() { return CStringW(L"GameEventUgcMapCommendationGM"); }
MS2_REPLACE_METHOD(0x1403C9780, GameEventUgcMapCommendationGM, GetTypeName, 61, 0x37F13374);

// @0x1403c97d0
GameEventUgcMapCommendationGM::GameEventUgcMapCommendationGM()
{
    m_d0 = 0;
    m_d8 = 0;
    m_e0 = L"";
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c9880
void GameEventUgcMapCommendationGM::vfunc_2()
{
    m_d0 = FUN_1407181a0(m_68);
    m_d8 = FUN_140718370(m_70);
    m_e0 = m_78;
}
MS2_REPLACE_METHOD(0x1403C9880, GameEventUgcMapCommendationGM, vfunc_2, 101, 0xF623363A);

// @0x1403c98f0
void GameEventUgcMapCommendationGM::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteInt64(m_d8);
    out->WriteStringW(m_e0);
}
MS2_REPLACE_METHOD(0x1403C98F0, GameEventUgcMapCommendationGM, vfunc_3, 129, 0xC2CC5233);

// @0x1403c9980
void GameEventUgcMapCommendationGM::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadInt64();
    m_e0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C9980, GameEventUgcMapCommendationGM, vfunc_4, 225, 0x40094F89);

// @0x1403c9a70
void GameEventUgcMapCommendationGM::OnStart() { ((class CGameRule*)GetGameRule())->SetUgcMapCommendationEvent(m_d0, m_d8, m_e0); }
MS2_REPLACE_METHOD(0x1403C9A70, GameEventUgcMapCommendationGM, OnStart, 115, 0x22E4A6EC);

// @0x1403c9af0
void GameEventUgcMapCommendationGM::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveUgcMapCommendationEvent(m_d0); }
MS2_REPLACE_METHOD(0x1403C9AF0, GameEventUgcMapCommendationGM, vfunc_6, 38, 0x26132507);

// ---- GameEventDeleteUrlCache ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regDeleteUrlCache(L"GameEventDeleteUrlCache", (ClassObjectCreateFn)FUN_1403c9b20);
#endif
// @0x1403c9b20
GameEvent* FUN_1403c9b20() { return new GameEventDeleteUrlCache; }

// @0x1403c9b80
CStringW GameEventDeleteUrlCache::GetTypeName() { return CStringW(L"GameEventDeleteUrlCache"); }
MS2_REPLACE_METHOD(0x1403C9B80, GameEventDeleteUrlCache, GetTypeName, 61, 0x52EC09CC);

// @0x1403c9bd0
GameEventDeleteUrlCache::GameEventDeleteUrlCache() : m_d0(0)
{
    SetFlag(2);
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c9c50
void GameEventDeleteUrlCache::vfunc_2() { m_d0 = FUN_1407181a0(m_68); }
MS2_REPLACE_METHOD(0x1403C9C50, GameEventDeleteUrlCache, vfunc_2, 42, 0x5A54E61A);

// @0x1403c9c80
void GameEventDeleteUrlCache::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteByte((unsigned char)m_d0);
}
MS2_REPLACE_METHOD(0x1403C9C80, GameEventDeleteUrlCache, vfunc_3, 62, 0xED75FA3A);

// @0x1403c9cd0
void GameEventDeleteUrlCache::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadByte();
}
MS2_REPLACE_METHOD(0x1403C9CD0, GameEventDeleteUrlCache, vfunc_4, 82, 0xC85C5644);

// @0x1403c9d30
void GameEventDeleteUrlCache::OnStart() { ((class CGameRule*)GetGameRule())->SetDeleteUrlCache(m_d0); }
MS2_REPLACE_METHOD(0x1403C9D30, GameEventDeleteUrlCache, OnStart, 38, 0x9737F55E);

// @0x1403c9d60
void GameEventDeleteUrlCache::vfunc_6() { ((class CGameRule*)GetGameRule())->SetDeleteUrlCache(0); }
MS2_REPLACE_METHOD(0x1403C9D60, GameEventDeleteUrlCache, vfunc_6, 29, 0x9173CFD7);

// ---- GameEventPetMastery --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regPetMastery(L"GameEventPetMastery", (ClassObjectCreateFn)FUN_1403c9d90);
#endif
// @0x1403c9d90
GameEvent* FUN_1403c9d90() { return new GameEventPetMastery; }

// @0x1403c9df0
CStringW GameEventPetMastery::GetTypeName() { return CStringW(L"GameEventPetMastery"); }
MS2_REPLACE_METHOD(0x1403C9DF0, GameEventPetMastery, GetTypeName, 61, 0x1A3DF688);

// @0x1403c9e40
GameEventPetMastery::GameEventPetMastery() : m_d0(0), m_d4(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403c9ec0
void GameEventPetMastery::vfunc_2()
{
    ATL::CAtlArray<unsigned> types;
    ATL::CAtlArray<unsigned> values;
    FUN_140274fc0(m_68, &types, L",");
    FUN_140274fc0(m_70, &values, L",");
    if (types.IsEmpty() || values.IsEmpty())
        return;
    if (types.GetCount() != values.GetCount())
        return;
    for (unsigned i = 0; i < types.GetCount(); i++)
    {
        if (types[i] == 1)
            m_d0 = values[i];
        else if (types[i] == 2)
            m_d4 = values[i];
    }
}
MS2_REPLACE_METHOD(0x1403C9EC0, GameEventPetMastery, vfunc_2, 419, 0x7A2472EC);

// @0x1403ca070
void GameEventPetMastery::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteInt(m_d4);
}
MS2_REPLACE_METHOD(0x1403CA070, GameEventPetMastery, vfunc_3, 88, 0xDE8A4540);

// @0x1403ca0d0
void GameEventPetMastery::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d4 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403CA0D0, GameEventPetMastery, vfunc_4, 124, 0xD0D78123);

// @0x1403ca160
void GameEventPetMastery::OnStart()
{
    ((class CGameRule*)GetGameRule())->SetPetMasteryRate(m_id, m_d0);
    ((class CGameRule*)GetGameRule())->FUN_14047f180(m_id, m_d4);
}
MS2_REPLACE_METHOD(0x1403CA160, GameEventPetMastery, OnStart, 80, 0xC297F8CB);

// @0x1403ca1c0
void GameEventPetMastery::vfunc_6()
{
    ((class CGameRule*)GetGameRule())->RemovePetMasteryRate(m_id);
    ((class CGameRule*)GetGameRule())->FUN_14047f1f0(m_id);
}
MS2_REPLACE_METHOD(0x1403CA1C0, GameEventPetMastery, vfunc_6, 56, 0x17A2B462);

// ---- GameEventPetBattleExp ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regPetBattleExp(L"GameEventPetBattleExp", (ClassObjectCreateFn)FUN_1403ca200);
#endif
// @0x1403ca200
GameEvent* FUN_1403ca200() { return new GameEventPetBattleExp; }

// @0x1403ca260
CStringW GameEventPetBattleExp::GetTypeName() { return CStringW(L"GameEventPetBattleExp"); }
MS2_REPLACE_METHOD(0x1403CA260, GameEventPetBattleExp, GetTypeName, 61, 0x5999CF35);

// @0x1403ca2b0
GameEventPetBattleExp::GameEventPetBattleExp() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403ca320
void GameEventPetBattleExp::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403CA320, GameEventPetBattleExp, vfunc_2, 42, 0x69C58673);

// @0x1403ca350
void GameEventPetBattleExp::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403CA350, GameEventPetBattleExp, vfunc_3, 61, 0x7171311C);

// @0x1403ca3a0
void GameEventPetBattleExp::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403CA3A0, GameEventPetBattleExp, vfunc_4, 79, 0x6B14DA29);

// @0x1403ca400
void GameEventPetBattleExp::OnStart() { ((class CGameRule*)GetGameRule())->SetPetBattleExpRate(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403CA400, GameEventPetBattleExp, OnStart, 47, 0x87E55C7F);

// @0x1403ca440
void GameEventPetBattleExp::vfunc_6() { ((class CGameRule*)GetGameRule())->RemovePetBattleExpRate(m_id); }
MS2_REPLACE_METHOD(0x1403CA440, GameEventPetBattleExp, vfunc_6, 35, 0xD43D95A8);

// ---- GameEventPetComposeSale ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regPetComposeSale(L"GameEventPetComposeSale", (ClassObjectCreateFn)FUN_1403ca470);
#endif
// @0x1403ca470
GameEvent* FUN_1403ca470() { return new GameEventPetComposeSale; }

// @0x1403ca4d0
CStringW GameEventPetComposeSale::GetTypeName() { return CStringW(L"GameEventPetComposeSale"); }
MS2_REPLACE_METHOD(0x1403CA4D0, GameEventPetComposeSale, GetTypeName, 61, 0xA9C55261);

// @0x1403ca520
GameEventPetComposeSale::GameEventPetComposeSale() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403ca590
void GameEventPetComposeSale::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403CA590, GameEventPetComposeSale, vfunc_2, 42, 0xFD0C0C19);

// @0x1403ca5c0
void GameEventPetComposeSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403CA5C0, GameEventPetComposeSale, vfunc_3, 61, 0x0EEFF51B);

// @0x1403ca610
void GameEventPetComposeSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403CA610, GameEventPetComposeSale, vfunc_4, 79, 0x47594ED6);

// @0x1403ca670
void GameEventPetComposeSale::OnStart() { ((class CGameRule*)GetGameRule())->SetPetComposeSaleRate(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403CA670, GameEventPetComposeSale, OnStart, 47, 0x7AD9EAA4);

// @0x1403ca6b0
void GameEventPetComposeSale::vfunc_6() { ((class CGameRule*)GetGameRule())->RemovePetComposeSaleRate(m_id); }
MS2_REPLACE_METHOD(0x1403CA6B0, GameEventPetComposeSale, vfunc_6, 35, 0x448E3F17);

// ---- GameEventItemBox -----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regItemBox(L"GameEventItemBox", (ClassObjectCreateFn)FUN_1403ca6e0);
#endif
// @0x1403ca6e0
GameEvent* FUN_1403ca6e0() { return new GameEventItemBox; }

// @0x1403ca740
CStringW GameEventItemBox::GetTypeName() { return CStringW(L"GameEventItemBox"); }
MS2_REPLACE_METHOD(0x1403CA740, GameEventItemBox, GetTypeName, 61, 0x0AF964E2);

// @0x1403ca790
GameEventItemBox::GameEventItemBox() : m_d0(0), m_e0(false)
{
    SetFlag(3);
    SetFlag(1);
}

// @0x1403ca810
void GameEventItemBox::vfunc_2()
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    MS2Ptr<ItemBoxEventContext> spBox(new ItemBoxEventContext);
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    spBox->m_3c = m_id;
    spBox->Load(pRoot);
    m_d0 = spBox;
}
MS2_REPLACE_METHOD(0x1403CA810, GameEventItemBox, vfunc_2, 319, 0x2F681F5C);

// @0x1403ca960
void GameEventItemBox::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (m_d0 == 0)
        m_d0.AssignRaw(new ItemBoxEventContext);
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403CA960, GameEventItemBox, vfunc_3, 186, 0x8A3F3283);

// @0x1403caa20
void GameEventItemBox::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new ItemBoxEventContext);
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403CAA20, GameEventItemBox, vfunc_4, 158, 0xEF0D903E);

// The open box dialog of the item box event (RTTI .?AVUIItemEventOpenBoxDialog@@, class id 0x4f42): only the refresh
// OnStart calls.
class UIItemEventOpenBoxDialog : public UIDialog
{
public:
    void FUN_140e48050();
};

// The ui object of a class id cast to its dialog class (0 while the ui service is not up).
template <class T> T* Unk_GameEventDialog(eUIClassID nClass)
{
    if (TSingleton<CUIService>::GetInstance())
    {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject(nClass);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// @0x1403caad0
void GameEventItemBox::OnStart()
{
    m_e0 = ((CGameEventValueItemBox*)(TSingleton<CGameEventValueManager>::GetInstance()->ItemBox()))->Add(m_d0);
    if (UIItemEventOpenBoxDialog* pDialog = Unk_GameEventDialog<UIItemEventOpenBoxDialog>(eUI_4f42))
        pDialog->FUN_140e48050();
}
MS2_REPLACE_METHOD(0x1403CAAD0, GameEventItemBox, OnStart, 143, 0x2230898A);

// @0x1403cab70
void GameEventItemBox::vfunc_6()
{
    if (m_e0)
        ((CGameEventValueItemBox*)(TSingleton<CGameEventValueManager>::GetInstance()->ItemBox()))->Remove(m_d0);
}
MS2_REPLACE_METHOD(0x1403CAB70, GameEventItemBox, vfunc_6, 115, 0x11447945);

// ---- GameEventShutdownInteractObjectId ------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regShutdownInteractObjectId(L"GameEventShutdownInteractObjectId", (ClassObjectCreateFn)FUN_1403cabf0);
#endif
// @0x1403cabf0
GameEvent* FUN_1403cabf0() { return new GameEventShutdownInteractObjectId; }

// @0x1403cac50
CStringW GameEventShutdownInteractObjectId::GetTypeName() { return CStringW(L"GameEventShutdownInteractObjectId"); }
MS2_REPLACE_METHOD(0x1403CAC50, GameEventShutdownInteractObjectId, GetTypeName, 61, 0x2CDB7EE0);

// @0x1403caca0
GameEventShutdownInteractObjectId::GameEventShutdownInteractObjectId()
{
    SetFlag(3);
    SetFlag(1);
}

// @0x1403cad10
void GameEventShutdownInteractObjectId::vfunc_2()
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v")); pNode; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("v")))
    {
        unsigned nFieldId = FUN_140197390(pNode, "fieldId", 0);
        int nObjectId = FUN_140197350(pNode, "objectId", 0);
        if (nFieldId == 0 || nObjectId == 0)
            continue;
        m_d0.insert(std::make_pair(nFieldId, nObjectId));
    }
}
MS2_REPLACE_METHOD(0x1403CAD10, GameEventShutdownInteractObjectId, vfunc_2, 321, 0xA9508BF9);

// @0x1403cae60
void GameEventShutdownInteractObjectId::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt((int)m_d0.size());
    for (std::set<std::pair<unsigned, int> >::iterator it = m_d0.begin(), itEnd = m_d0.end(); it != itEnd; ++it)
    {
        out->WriteInt((*it).first);
        out->WriteInt((*it).second);
    }
}
MS2_REPLACE_METHOD(0x1403CAE60, GameEventShutdownInteractObjectId, vfunc_3, 242, 0x1A39E46E);

// @0x1403caf60
void GameEventShutdownInteractObjectId::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.clear();
    int nCount = MS2_GE_R(in)->ReadInt();
    for (int i = 0; i < nCount; i++)
    {
        std::pair<unsigned, int> v;
        v.first = MS2_GE_R(in)->ReadInt();
        v.second = MS2_GE_R(in)->ReadInt();
        m_d0.insert(v);
    }
}
MS2_REPLACE_METHOD(0x1403CAF60, GameEventShutdownInteractObjectId, vfunc_4, 241, 0x23A8AD86);

// @0x1403cb060
void GameEventShutdownInteractObjectId::OnStart()
{
    for (std::set<std::pair<unsigned, int> >::iterator it = m_d0.begin(), itEnd = m_d0.end(); it != itEnd; ++it)
        ((class CShutdownEventInteractObject*)(class CShutdownEventInteractObject*)(TSingleton<CGameEventValueManager>::GetInstance()->ShutdownInteractObjectId()))->FUN_1407d0420((*it).first, (*it).second);
}
MS2_REPLACE_METHOD(0x1403CB060, GameEventShutdownInteractObjectId, OnStart, 165, 0x329092AB);

// @0x1403cb110
void GameEventShutdownInteractObjectId::vfunc_6()
{
    for (std::set<std::pair<unsigned, int> >::iterator it = m_d0.begin(), itEnd = m_d0.end(); it != itEnd; ++it)
        ((class CShutdownEventInteractObject*)(class CShutdownEventInteractObject*)(TSingleton<CGameEventValueManager>::GetInstance()->ShutdownInteractObjectId()))->FUN_1407d04c0((*it).first, (*it).second);
}
MS2_REPLACE_METHOD(0x1403CB110, GameEventShutdownInteractObjectId, vfunc_6, 165, 0xD1095170);

// ---- GameEventShutdownFunctionItem ----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regShutdownFunctionItem(L"GameEventShutdownFunctionItem", (ClassObjectCreateFn)FUN_1403cb1c0);
#endif
// @0x1403cb1c0
GameEvent* FUN_1403cb1c0() { return new GameEventShutdownFunctionItem; }

// @0x1403cb220
CStringW GameEventShutdownFunctionItem::GetTypeName() { return CStringW(L"GameEventShutdownFunctionItem"); }
MS2_REPLACE_METHOD(0x1403CB220, GameEventShutdownFunctionItem, GetTypeName, 61, 0xF8577A8A);

// @0x1403cb270
GameEventShutdownFunctionItem::GameEventShutdownFunctionItem()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403cb2e0
void GameEventShutdownFunctionItem::vfunc_2()
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v")); pNode; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("v")))
    {
        unsigned nItemId = FUN_140197390(pNode, "itemId", 0);
        if (nItemId == 0)
            continue;
        m_d0.insert(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403CB2E0, GameEventShutdownFunctionItem, vfunc_2, 271, 0x594383D5);

// @0x1403cb400
void GameEventShutdownFunctionItem::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt((int)m_d0.size());
    for (std::set<unsigned>::iterator it = m_d0.begin(), itEnd = m_d0.end(); it != itEnd; ++it)
        out->WriteInt(*it);
}
MS2_REPLACE_METHOD(0x1403CB400, GameEventShutdownFunctionItem, vfunc_3, 203, 0x8595B692);

// @0x1403cb4e0
void GameEventShutdownFunctionItem::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.clear();
    int nCount = MS2_GE_R(in)->ReadInt();
    for (int i = 0; i < nCount; i++)
    {
        unsigned nItemId = MS2_GE_R(in)->ReadInt();
        m_d0.insert(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403CB4E0, GameEventShutdownFunctionItem, vfunc_4, 190, 0x967CA248);

// @0x1403cb5b0
void GameEventShutdownFunctionItem::OnStart()
{
    for (std::set<unsigned>::iterator it = m_d0.begin(), itEnd = m_d0.end(); it != itEnd; ++it)
        ((class CShutdownEventFunctionItem*)(class CShutdownEventFunctionItem*)(TSingleton<CGameEventValueManager>::GetInstance()->ShutdownFunctionItem()))->FUN_1407d0c30(*it);
}
MS2_REPLACE_METHOD(0x1403CB5B0, GameEventShutdownFunctionItem, OnStart, 141, 0x94440A91);

// @0x1403cb650
void GameEventShutdownFunctionItem::vfunc_6()
{
    for (std::set<unsigned>::iterator it = m_d0.begin(), itEnd = m_d0.end(); it != itEnd; ++it)
        ((class CShutdownEventFunctionItem*)(class CShutdownEventFunctionItem*)(TSingleton<CGameEventValueManager>::GetInstance()->ShutdownFunctionItem()))->FUN_1407d0cb0(*it);
}
MS2_REPLACE_METHOD(0x1403CB650, GameEventShutdownFunctionItem, vfunc_6, 141, 0x8AF4E104);

// ---- GameEventShutdownSkillItem -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regShutdownSkillItem(L"GameEventShutdownSkillItem", (ClassObjectCreateFn)FUN_1403cb6f0);
#endif
// @0x1403cb6f0
GameEvent* FUN_1403cb6f0() { return new GameEventShutdownSkillItem; }

// @0x1403cb750
CStringW GameEventShutdownSkillItem::GetTypeName() { return CStringW(L"GameEventShutdownSkillItem"); }
MS2_REPLACE_METHOD(0x1403CB750, GameEventShutdownSkillItem, GetTypeName, 61, 0x3F87668B);

// @0x1403cb7a0
GameEventShutdownSkillItem::GameEventShutdownSkillItem()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403cb810
void GameEventShutdownSkillItem::vfunc_2()
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v")); pNode; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("v")))
    {
        unsigned nItemId = FUN_140197390(pNode, "itemId", 0);
        if (nItemId == 0)
            continue;
        m_d0.emplace(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403CB810, GameEventShutdownSkillItem, vfunc_2, 271, 0x3748FE0A);

// @0x1403cb930
void GameEventShutdownSkillItem::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt((int)m_d0.size());
    std::set<unsigned>& ids = m_d0;
    for (std::set<unsigned>::_Unchecked_iterator it = ids._Unchecked_begin(), itEnd = ids._Unchecked_end(); it != itEnd; ++it)
    {
        unsigned nItemId = *it;
        out->WriteInt(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403CB930, GameEventShutdownSkillItem, vfunc_3, 199, 0xE4549125);

// @0x1403cba00
void GameEventShutdownSkillItem::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.clear();
    int nCount = MS2_GE_R(in)->ReadInt();
    for (int i = 0; i < nCount; i++)
    {
        unsigned nItemId = MS2_GE_R(in)->ReadInt();
        m_d0.emplace(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403CBA00, GameEventShutdownSkillItem, vfunc_4, 190, 0xCDA18DF6);

// @0x1403cbad0
void GameEventShutdownSkillItem::OnStart()
{
    std::set<unsigned>& ids = m_d0;
    for (std::set<unsigned>::_Unchecked_iterator it = ids._Unchecked_begin(), itEnd = ids._Unchecked_end(); it != itEnd; ++it)
    {
        unsigned nItemId = *it;
        TSingleton<CGameEventValueManager>::GetInstance()->ShutdownSkillItem()->SetShutdown(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403CBAD0, GameEventShutdownSkillItem, OnStart, 137, 0x54B797D2);

// @0x1403cbb60
void GameEventShutdownSkillItem::vfunc_6()
{
    std::set<unsigned>& ids = m_d0;
    for (std::set<unsigned>::_Unchecked_iterator it = ids._Unchecked_begin(), itEnd = ids._Unchecked_end(); it != itEnd; ++it)
    {
        unsigned nItemId = *it;
        TSingleton<CGameEventValueManager>::GetInstance()->ShutdownSkillItem()->ResetShutdown(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403CBB60, GameEventShutdownSkillItem, vfunc_6, 137, 0x73A937C6);

// ---- GameEventShutdownUGCUpload -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regShutdownUGCUpload(L"GameEventShutdownUGCUpload", (ClassObjectCreateFn)FUN_1403cbbf0);
#endif
// @0x1403cbbf0
GameEvent* FUN_1403cbbf0() { return new GameEventShutdownUGCUpload; }

// @0x1403cbc50
CStringW GameEventShutdownUGCUpload::GetTypeName() { return CStringW(L"GameEventShutdownUGCUpload"); }
MS2_REPLACE_METHOD(0x1403CBC50, GameEventShutdownUGCUpload, GetTypeName, 61, 0xFFEA9B7E);

// @0x1403cbca0
GameEventShutdownUGCUpload::GameEventShutdownUGCUpload() : m_f0(0)
{
    SetFlag(1);
    SetFlag(2);
}

// @0x1403cbd20
void GameEventShutdownUGCUpload::vfunc_2()
{
    FUN_140274fc0(m_68, &m_d0, L",");
    if (!m_70.IsEmpty())
        m_f0 = FUN_1407183f0(m_70) == true;
}
MS2_REPLACE_METHOD(0x1403CBD20, GameEventShutdownUGCUpload, vfunc_2, 132, 0x0D5D5CF9);

// The UGC upload kind (an enum: its std::less is a separate copy of less<int> in the exe).
enum Unk_UGCUploadType
{
};
// The shut down UGC upload kinds handed to the shutdown event value (shutdowneventvalue.cpp keeps a copy per event).
struct Unk_ShutdownUGCUploadInfo
{
    // @0x1403e3e90
    Unk_ShutdownUGCUploadInfo() : m_bFlag(0) {}
    std::set<Unk_UGCUploadType> m_ids;          // +0x00
    BOOL m_bFlag;                               // +0x10
};
bool FUN_1407d1ef0(class CShutdownEventUGCUpload*, unsigned int, struct Unk_ShutdownUGCUploadInfo const&);   // C3: was FUN_1407d1ef0
void RemoveEvent(class CShutdownEventUGCUpload*, unsigned int);   // C3: was FUN_1407d1f70

// @0x1403cbdb0
void GameEventShutdownUGCUpload::OnStart()
{
    Unk_ShutdownUGCUploadInfo info;
    info.m_bFlag = m_f0;
    for (size_t i = 0; i < m_d0.GetCount(); i++)
        info.m_ids.insert((Unk_UGCUploadType)m_d0[i]);
    FUN_1407d1ef0((class CShutdownEventUGCUpload*)(TSingleton<CGameEventValueManager>::GetInstance()->ShutdownUGCUpload()), GetID(), info);
}
MS2_REPLACE_METHOD(0x1403CBDB0, GameEventShutdownUGCUpload, OnStart, 208, 0x414A87F9);

// @0x1403cbe90
void GameEventShutdownUGCUpload::vfunc_6() { RemoveEvent((class CShutdownEventUGCUpload*)(TSingleton<CGameEventValueManager>::GetInstance()->ShutdownUGCUpload()), GetID()); }
MS2_REPLACE_METHOD(0x1403CBE90, GameEventShutdownUGCUpload, vfunc_6, 55, 0xC4914FA2);

// ---- GameEventFindDungeonHelperBonus --------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regFindDungeonHelperBonus(L"GameEventFindDungeonHelperBonus", (ClassObjectCreateFn)FUN_1403cbed0);
#endif
// @0x1403cbed0
GameEvent* FUN_1403cbed0() { return new GameEventFindDungeonHelperBonus; }

// @0x1403cbf30
CStringW GameEventFindDungeonHelperBonus::GetTypeName() { return CStringW(L"GameEventFindDungeonHelperBonus"); }
MS2_REPLACE_METHOD(0x1403CBF30, GameEventFindDungeonHelperBonus, GetTypeName, 61, 0x217288B8);

// @0x1403cbf80
GameEventFindDungeonHelperBonus::GameEventFindDungeonHelperBonus() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403cbff0
void GameEventFindDungeonHelperBonus::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403CBFF0, GameEventFindDungeonHelperBonus, vfunc_2, 42, 0xE118841E);

// @0x1403cc020
void GameEventFindDungeonHelperBonus::OnStart() { ((class CGameEventValueDungeonHelperBonus*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->FindDungeonHelperBonus()))->Add(m_d0); }
MS2_REPLACE_METHOD(0x1403CC020, GameEventFindDungeonHelperBonus, OnStart, 46, 0x48CD8444);

// @0x1403cc060
void GameEventFindDungeonHelperBonus::vfunc_6() { ((class CGameEventValueDungeonHelperBonus*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->FindDungeonHelperBonus()))->Sub(m_d0); }
MS2_REPLACE_METHOD(0x1403CC060, GameEventFindDungeonHelperBonus, vfunc_6, 46, 0x8E27CDF4);

// @0x1403cc0a0
void GameEventFindDungeonHelperBonus::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070f9a0(MS2_GE_OUT(out), m_d0);
}
MS2_REPLACE_METHOD(0x1403CC0A0, GameEventFindDungeonHelperBonus, vfunc_3, 55, 0x1497D454);

// @0x1403cc0e0
void GameEventFindDungeonHelperBonus::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    reinterpret_cast<Unk_OSInput&>(MS2_GE_IN(in)).Read6(m_d0);
}
MS2_REPLACE_METHOD(0x1403CC0E0, GameEventFindDungeonHelperBonus, vfunc_4, 62, 0x6A3215F3);

// ---- GameEventGuildVsGameOpen ---------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGuildVsGameOpen(L"GameEventGuildVsGameOpen", (ClassObjectCreateFn)FUN_1403cc130);
#endif
// @0x1403cc130
GameEvent* FUN_1403cc130() { return new GameEventGuildVsGameOpen; }

// @0x1403cc190
CStringW GameEventGuildVsGameOpen::GetTypeName() { return CStringW(L"GameEventGuildVsGameOpen"); }
MS2_REPLACE_METHOD(0x1403CC190, GameEventGuildVsGameOpen, GetTypeName, 61, 0xDBD49CBD);

// @0x1403cc1e0
GameEventGuildVsGameOpen::GameEventGuildVsGameOpen()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403cc240
void GameEventGuildVsGameOpen::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403CC240, GameEventGuildVsGameOpen, vfunc_2, 6, 0xA9AF6E37);

// @0x1403cc250
void GameEventGuildVsGameOpen::OnStart()
{
    ((class CGameRule*)GetGameRule())->FUN_14047ec80(true);
    TSingleton<CGuildManager>::GetInstance()->NotifyVsGameCanRegister();
}
MS2_REPLACE_METHOD(0x1403CC250, GameEventGuildVsGameOpen, OnStart, 42, 0xA6426729);

// @0x1403cc280
void GameEventGuildVsGameOpen::vfunc_6() { ((class CGameRule*)GetGameRule())->FUN_14047ec80(false); }
MS2_REPLACE_METHOD(0x1403CC280, GameEventGuildVsGameOpen, vfunc_6, 29, 0xCD21E29A);

// ---- GameEventChatFiltering -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regChatFiltering(L"GameEventChatFiltering", (ClassObjectCreateFn)FUN_1403cc2b0);
#endif
// @0x1403cc2b0
GameEvent* FUN_1403cc2b0() { return new GameEventChatFiltering; }

// @0x1403cc310
CStringW GameEventChatFiltering::GetTypeName() { return CStringW(L"GameEventChatFiltering"); }
MS2_REPLACE_METHOD(0x1403CC310, GameEventChatFiltering, GetTypeName, 61, 0xA54067BE);

// @0x1403cc360
GameEventChatFiltering::GameEventChatFiltering()
{
    SetFlag(1);
    SetFlag(3);
    m_d0.RemoveAll();
}

// @0x1403cc3f0
void GameEventChatFiltering::vfunc_2() { FUN_14025a680(m_68, m_d0, L","); }
MS2_REPLACE_METHOD(0x1403CC3F0, GameEventChatFiltering, vfunc_2, 49, 0xAEF5114D);

// @0x1403cc430
void GameEventChatFiltering::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    unsigned nCount = (unsigned)m_d0.GetCount();
    out->WriteInt(nCount);
    for (unsigned i = 0; i < nCount; i++)
        out->WriteStringW(m_d0.GetAt(i));
}
MS2_REPLACE_METHOD(0x1403CC430, GameEventChatFiltering, vfunc_3, 161, 0x12E7C33C);

// @0x1403cc4e0
void GameEventChatFiltering::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    unsigned nCount = MS2_GE_R(in)->ReadInt();
    for (unsigned i = 0; i < nCount; i++)
    {
        const CStringW& str = MS2_GE_R(in)->ReadStringW();
        m_d0.Add(str);
    }
}
MS2_REPLACE_METHOD(0x1403CC4E0, GameEventChatFiltering, vfunc_4, 199, 0x48D45BA5);

// @0x1403cc5b0
void GameEventChatFiltering::OnStart()
{
    if (CBanTextChecker* pChecker = CommonString::GetInstance()->GetChecker())
        pChecker->SetBanWords(m_id, m_d0);
}
MS2_REPLACE_METHOD(0x1403CC5B0, GameEventChatFiltering, OnStart, 131, 0x69EEFF9B);

// @0x1403cc640
void GameEventChatFiltering::vfunc_6()
{
    if (CBanTextChecker* pChecker = CommonString::GetInstance()->GetChecker())
        pChecker->RemoveBanWords(m_id);
}
MS2_REPLACE_METHOD(0x1403CC640, GameEventChatFiltering, vfunc_6, 117, 0x9083579C);

// ---- GameEventBattlePetSpawn ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regBattlePetSpawn(L"GameEventBattlePetSpawn", (ClassObjectCreateFn)FUN_1403cc6c0);
#endif
// @0x1403cc6c0
GameEvent* FUN_1403cc6c0() { return new GameEventBattlePetSpawn; }

// @0x1403cc720
CStringW GameEventBattlePetSpawn::GetTypeName() { return CStringW(L"GameEventBattlePetSpawn"); }
MS2_REPLACE_METHOD(0x1403CC720, GameEventBattlePetSpawn, GetTypeName, 61, 0xCD360C59);

// @0x1403cc770
GameEventBattlePetSpawn::GameEventBattlePetSpawn() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403cc7f0
void GameEventBattlePetSpawn::vfunc_2()
{
    m_d0 = FUN_140718200(m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403CC7F0, GameEventBattlePetSpawn, vfunc_2, 72, 0x3DBD65E8);

// @0x1403cc840
void GameEventBattlePetSpawn::OnStart()
{
    if (m_d0 == 0)
        ((CGameEventValueBattlePetSpawn*)TSingleton<CGameEventValueManager>::GetInstance()->GetBattlePetSpawn())->AddSpawn(GetID(), m_d8);
    else if (m_d0 == 1)
        ((CGameEventValueBattlePetSpawn*)TSingleton<CGameEventValueManager>::GetInstance()->GetBattlePetSpawn())->AddImprove(GetID(), m_d8);
}
MS2_REPLACE_METHOD(0x1403CC840, GameEventBattlePetSpawn, OnStart, 174, 0xB546D265);

// @0x1403cc900
void GameEventBattlePetSpawn::vfunc_6()
{
    if (m_d0 == 0)
        ((CGameEventValueBattlePetSpawn*)TSingleton<CGameEventValueManager>::GetInstance()->GetBattlePetSpawn())->RemoveSpawn(GetID(), m_d8);
    else if (m_d0 == 1)
        ((CGameEventValueBattlePetSpawn*)TSingleton<CGameEventValueManager>::GetInstance()->GetBattlePetSpawn())->RemoveImprove(GetID(), m_d8);
}
MS2_REPLACE_METHOD(0x1403CC900, GameEventBattlePetSpawn, vfunc_6, 174, 0x7FF2D2B0);

// @0x1403cc9c0
void GameEventBattlePetSpawn::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteByte((unsigned char)m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403CC9C0, GameEventBattlePetSpawn, vfunc_3, 102, 0xBFB31AB5);

// @0x1403cca30
void GameEventBattlePetSpawn::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadByte();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403CCA30, GameEventBattlePetSpawn, vfunc_4, 182, 0x29CCF119);

// ---- GameEventGallery -----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGallery(L"GameEventGallery", (ClassObjectCreateFn)FUN_1403ccaf0);
#endif
// @0x1403ccaf0
GameEvent* FUN_1403ccaf0() { return new GameEventGallery; }

// @0x1403ccb50
CStringW GameEventGallery::GetTypeName() { return CStringW(L"GameEventGallery"); }
MS2_REPLACE_METHOD(0x1403CCB50, GameEventGallery, GetTypeName, 61, 0xAD44891E);

// @0x1403ccba0
GameEventGallery::GameEventGallery()
{
    SetFlag(3);
    SetFlag(1);
    m_d0 = 0;
}

// @0x1403ccc30
void GameEventGallery::vfunc_2()
{
    MS2Ptr<GalleryContext> pContext(new GalleryContext(GetID()));
    if (!pContext)
    {
        MS2_ASSERT_AT(MS2_LINE(3905), "pContext" && 0);
        return;
    }
    if (!ReadCardData(pContext))
    {
        MS2_ASSERT_AT(MS2_LINE(3907), "ReadCardData(pContext)" && 0);
        return;
    }
    if (!ReadRewardData(pContext))
    {
        MS2_ASSERT_AT(MS2_LINE(3908), "ReadRewardData(pContext)" && 0);
        return;
    }
    pContext->m_60 = FUN_1407181a0(m_78);
    pContext->m_strTitle = FUN_140718600(m_80);
    pContext->m_endTime = GetEndTime().Get();
    m_d0 = pContext;
}
MS2_REPLACE_METHOD(0x1403CCC30, GameEventGallery, vfunc_2, 664, 0x6895C365);

// @0x1403cced0
void GameEventGallery::OnStart() { ((class CGameRule*)GetGameRule())->SetGallery(m_d0); }
MS2_REPLACE_METHOD(0x1403CCED0, GameEventGallery, OnStart, 91, 0x8F4A3CE5);

// @0x1403ccf40
void GameEventGallery::vfunc_6() { ((class CGameRule*)GetGameRule())->SetGallery(MS2Ptr<GalleryContext>(0)); }
MS2_REPLACE_METHOD(0x1403CCF40, GameEventGallery, vfunc_6, 79, 0x6AAB184B);

// @0x1403ccfa0
void GameEventGallery::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (!m_d0)
        return;
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403CCFA0, GameEventGallery, vfunc_3, 94, 0xD2043C6A);

// @0x1403cd010
void GameEventGallery::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new GalleryContext(GetID()));
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403CD010, GameEventGallery, vfunc_4, 170, 0xA20E7AB8);

// @0x1403cd0c0
bool GameEventGallery::ReadCardData(MS2Ptr<GalleryContext> pContext)
{
    if (!pContext)
    {
        MS2_ASSERT_AT(MS2_LINE(3948), "pContext" && 0);
        return false;
    }
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(3951), "CFileSystem::GetInstance()->GetXmlFromString(doc, m_v1)" && 0);
        return false;
    }
    TiXmlElement* root = FUN_140345b40(&doc);
    if (root == NULL)
    {
        MS2_ASSERT_AT(MS2_LINE(3954), "root" && 0);
        return false;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(root))->FirstChild("v")); pNode; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("v")))
    {
        MS2Ptr<GalleryContext::Card> card(new GalleryContext::Card);
        if (!card)
        {
            MS2_ASSERT_AT(MS2_LINE(3959), "card" && 0);
            return false;
        }
        XmlGetAttr((class TiXmlElement*)(pNode), "quest", reinterpret_cast<unsigned int&>(card->m_id));
        pContext->m_cards.Add(card);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1403CD0C0, GameEventGallery, ReadCardData, 736, 0x26F5E172);

// @0x1403cd3b0
bool GameEventGallery::ReadRewardData(MS2Ptr<GalleryContext> pContext)
{
    if (!pContext)
    {
        MS2_ASSERT_AT(MS2_LINE(3971), "pContext" && 0);
        return false;
    }
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_70) == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(3974), "CFileSystem::GetInstance()->GetXmlFromString(doc, m_v2)" && 0);
        return false;
    }
    TiXmlElement* root = FUN_140345b40(&doc);
    if (root == NULL)
    {
        MS2_ASSERT_AT(MS2_LINE(3977), "root" && 0);
        return false;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(root))->FirstChild("v")); pNode; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("v")))
    {
        ItemEntity item;
        item.vfunc_2(pNode);
        pContext->m_items.Add(item);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1403CD3B0, GameEventGallery, ReadRewardData, 554, 0x9ABB4F03);

// ---- GameEventIgnoreConstructionLockEvent ---------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regIgnoreConstructionLockEvent(L"GameEventIgnoreConstructionLockEvent", (ClassObjectCreateFn)FUN_1403cd5e0);
#endif
// @0x1403cd5e0
GameEvent* FUN_1403cd5e0() { return new GameEventIgnoreConstructionLockEvent; }

// @0x1403cd640
CStringW GameEventIgnoreConstructionLockEvent::GetTypeName() { return CStringW(L"GameEventIgnoreConstructionLockEvent"); }
MS2_REPLACE_METHOD(0x1403CD640, GameEventIgnoreConstructionLockEvent, GetTypeName, 61, 0xA97987F0);

// @0x1403cd690
GameEventIgnoreConstructionLockEvent::GameEventIgnoreConstructionLockEvent()
{
    m_d0.RemoveAll();
    SetFlag(1);
    SetFlag(3);
}

// @0x1403cd720
void GameEventIgnoreConstructionLockEvent::vfunc_2() { ParseUInt64List(m_68, m_d0, L","); }
MS2_REPLACE_METHOD(0x1403CD720, GameEventIgnoreConstructionLockEvent, vfunc_2, 49, 0x251F99A2);

// @0x1403cd760
void GameEventIgnoreConstructionLockEvent::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    unsigned nCount = (unsigned)m_d0.GetCount();
    out->WriteInt(nCount);
    for (size_t i = 0; i < nCount; i++)
        out->WriteInt64(m_d0[i]);
}
MS2_REPLACE_METHOD(0x1403CD760, GameEventIgnoreConstructionLockEvent, vfunc_3, 167, 0x6C6AA60C);

// @0x1403cd810
void GameEventIgnoreConstructionLockEvent::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    unsigned nCount = MS2_GE_R(in)->ReadInt();
    for (unsigned i = 0; i < nCount; i++)
    {
        unsigned __int64 id = MS2_GE_R(in)->ReadInt64();
        m_d0.Add(id);
    }
}
MS2_REPLACE_METHOD(0x1403CD810, GameEventIgnoreConstructionLockEvent, vfunc_4, 167, 0x0652B919);

// @0x1403cd8c0
void GameEventIgnoreConstructionLockEvent::OnStart()
{
    for (unsigned i = 0; i < m_d0.GetCount(); i++)
    {
        unsigned __int64 id = m_d0[i];
        ((class CGameRule*)GetGameRule())->AddIgnoredConstructionLockId(id);
    }
}
MS2_REPLACE_METHOD(0x1403CD8C0, GameEventIgnoreConstructionLockEvent, OnStart, 121, 0x7F51EA0E);

// @0x1403cd940
void GameEventIgnoreConstructionLockEvent::vfunc_6() { ((class CGameRule*)GetGameRule())->ClearIgnoredConstructionLockIds(); }
MS2_REPLACE_METHOD(0x1403CD940, GameEventIgnoreConstructionLockEvent, vfunc_6, 27, 0xB6FF65BC);

// ---- GameEventStarShop ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regStarShop(L"GameEventStarShop", (ClassObjectCreateFn)FUN_1403cd970);
#endif
// @0x1403cd970
GameEvent* FUN_1403cd970() { return new GameEventStarShop; }

// @0x1403cd9d0
CStringW GameEventStarShop::GetTypeName() { return CStringW(L"GameEventStarShop"); }
MS2_REPLACE_METHOD(0x1403CD9D0, GameEventStarShop, GetTypeName, 61, 0x331EB3E6);

// @0x1403cda20
GameEventStarShop::GameEventStarShop() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403cda90
void GameEventStarShop::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403CDA90, GameEventStarShop, vfunc_2, 42, 0xB28B9F7C);

// @0x1403cdac0
void GameEventStarShop::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403CDAC0, GameEventStarShop, vfunc_3, 61, 0xDE7142F4);

// @0x1403cdb10
void GameEventStarShop::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403CDB10, GameEventStarShop, vfunc_4, 79, 0x004B9E41);

// @0x1403cdb70
void GameEventStarShop::OnStart() { ((class CGameEventValueStarShop*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetStarShop()))->SetValue(m_d0); }
MS2_REPLACE_METHOD(0x1403CDB70, GameEventStarShop, OnStart, 46, 0x6D33F816);

// @0x1403cdbb0
void GameEventStarShop::vfunc_6() { ((class CGameEventValueStarShop*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetStarShop()))->SetValue(0); }
MS2_REPLACE_METHOD(0x1403CDBB0, GameEventStarShop, vfunc_6, 37, 0x64449FE9);

// ---- GameEventSnowman -----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSnowman(L"GameEventSnowman", (ClassObjectCreateFn)FUN_1403cdbe0);
#endif
// @0x1403cdbe0
GameEvent* FUN_1403cdbe0() { return new GameEventSnowman; }

// @0x1403cdc40
CStringW GameEventSnowman::GetTypeName() { return CStringW(L"GameEventSnowman"); }
MS2_REPLACE_METHOD(0x1403CDC40, GameEventSnowman, GetTypeName, 61, 0xCB05291C);

// @0x1403cdc90
GameEventSnowman::GameEventSnowman()
{
    SetFlag(3);
    SetFlag(1);
    m_d0 = 0;
    m_e0 = L"";
}

// @0x1403cdd50
void GameEventSnowman::vfunc_2()
{
    MS2Ptr<SnowmanContext> pContext(new SnowmanContext(GetID()));
    if (!pContext)
    {
        MS2_ASSERT_AT(MS2_LINE(4099), "pContext" && 0);
        return;
    }
    if (!ReadSnowmanData(pContext))
    {
        MS2_ASSERT_AT(MS2_LINE(4101), "ReadSnowmanData(pContext)" && 0);
        return;
    }
    pContext->m_endTime = GetEndTime().Get();
    m_d0 = pContext;
    m_e0 = m_70;
}
MS2_REPLACE_METHOD(0x1403CDD50, GameEventSnowman, vfunc_2, 434, 0xBF2FA666);

// @0x1403cdf10
void GameEventSnowman::OnStart() { ((class CGameRule*)GetGameRule())->SetSnowman(m_d0); }
MS2_REPLACE_METHOD(0x1403CDF10, GameEventSnowman, OnStart, 91, 0xFFE10E1E);

// @0x1403cdf80
void GameEventSnowman::vfunc_6() { ((class CGameRule*)GetGameRule())->SetSnowman(MS2Ptr<SnowmanContext>(0)); }
MS2_REPLACE_METHOD(0x1403CDF80, GameEventSnowman, vfunc_6, 79, 0xB759FB8F);

// @0x1403cdfe0
void GameEventSnowman::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (!m_d0)
        return;
    m_d0->Write(MS2_GE_OUT(out));
    out->WriteStringW(m_e0);
}
MS2_REPLACE_METHOD(0x1403CDFE0, GameEventSnowman, vfunc_3, 134, 0xDDB8A9A5);

// @0x1403ce070
void GameEventSnowman::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new SnowmanContext(GetID()));
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
    m_e0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403CE070, GameEventSnowman, vfunc_4, 261, 0x2A93DA46);

// @0x1403ce180
bool GameEventSnowman::ReadSnowmanData(MS2Ptr<SnowmanContext> pContext)
{
    if (!pContext)
    {
        MS2_ASSERT_AT(MS2_LINE(4142), "pContext" && 0);
        return false;
    }
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(4145), "CFileSystem::GetInstance()->GetXmlFromString(doc, m_v1)" && 0);
        return false;
    }
    TiXmlElement* root = FUN_140345b40(&doc);
    if (root == NULL)
    {
        MS2_ASSERT_AT(MS2_LINE(4148), "root" && 0);
        return false;
    }
    TiXmlElement* xelOption = ((class TiXmlElement*)((class Unk_XmlNode*)(root))->FirstChild("option"));
    if (xelOption)
        XmlGetAttr((class TiXmlElement*)(xelOption), "thema", pContext->m_strTitle);
    for (TiXmlElement* xel = ((class TiXmlElement*)((class Unk_XmlNode*)(root))->FirstChild("snowman")); xel; xel = ((class TiXmlElement*)((class Unk_XmlNode*)(xel))->NextSibling("snowman")))
    {
        MS2Ptr<SnowmanContext::Snowman> snowman(new SnowmanContext::Snowman);
        if (!snowman)
        {
            MS2_ASSERT_AT(MS2_LINE(4159), "snowman" && 0);
            return false;
        }
        TiXmlElement* xelCondition = ((class TiXmlElement*)((class Unk_XmlNode*)(xel))->FirstChild("condition"));
        if (xelCondition == NULL)
        {
            MS2_ASSERT_AT(MS2_LINE(4162), "xelCondition" && 0);
            return false;
        }
        XmlGetAttr((class TiXmlElement*)(xelCondition), "snowflakeCount", snowman->m_18);
        XmlGetAttr((class TiXmlElement*)(xelCondition), "dailyMaxCount", snowman->m_1c);
        XmlGetAttr((class TiXmlElement*)(xelCondition), "accumMaxCount", snowman->m_20);
        if (!ReadRewardData(((class TiXmlElement*)((class Unk_XmlNode*)(xel))->FirstChild("rewardItems")), snowman->m_items))
        {
            MS2_ASSERT_AT(MS2_LINE(4168), "ReadRewardData(xel->FirstChildElement(\"rewardItems\"), snowman->dailyCompelteRewards)" && 0);
            return false;
        }
        if (!ReadRewardData(((class TiXmlElement*)((class Unk_XmlNode*)(xel))->FirstChild("accumRewardItems")), snowman->m_bonusItems))
        {
            MS2_ASSERT_AT(MS2_LINE(4169), "ReadRewardData(xel->FirstChildElement(\"accumRewardItems\"), snowman->accumCompleteRewards)" && 0);
            return false;
        }
        pContext->m_snowmen.Add(snowman);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1403CE180, GameEventSnowman, ReadSnowmanData, 1362, 0x0B581B97);

// @0x1403ce6e0
bool GameEventSnowman::ReadRewardData(TiXmlElement* xelReward, ATL::CAtlArray<ItemEntity>& rewards)
{
    if (xelReward == NULL)
    {
        MS2_ASSERT_AT(MS2_LINE(4179), "xelReward" && 0);
        return false;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(xelReward))->FirstChild("v")); pNode; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("v")))
    {
        ItemEntity item;
        item.vfunc_2(pNode);
        rewards.Add(item);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1403CE6E0, GameEventSnowman, ReadRewardData, 204, 0xC6BC6B86);

// ---- GameEventRps ---------------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regRps(L"GameEventRps", (ClassObjectCreateFn)FUN_1403ce7c0);
#endif
// @0x1403ce7c0
GameEvent* FUN_1403ce7c0() { return new GameEventRps; }

// @0x1403ce820
CStringW GameEventRps::GetTypeName() { return CStringW(L"GameEventRps"); }
MS2_REPLACE_METHOD(0x1403CE820, GameEventRps, GetTypeName, 61, 0xC89FAB34);

// @0x1403ce870
GameEventRps::GameEventRps()
{
    SetFlag(3);
    SetFlag(1);
    m_d0 = 0;
}

// @0x1403ce900
void GameEventRps::vfunc_2()
{
    MS2Ptr<RpsContext> pContext(new RpsContext(GetID()));
    if (pContext == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(4209), 0);
        return;
    }
    if (!ReadRpsData(pContext))
        return;
    pContext->m_strTitle = m_70;
    pContext->m_endTime = GetEndTime().Get();
    m_d0 = pContext;
}
MS2_REPLACE_METHOD(0x1403CE900, GameEventRps, vfunc_2, 396, 0x7CD51416);

// @0x1403ceaa0
void GameEventRps::OnStart() { ((class CGameRule*)GetGameRule())->SetRps(m_d0); }
MS2_REPLACE_METHOD(0x1403CEAA0, GameEventRps, OnStart, 91, 0x36634EAA);

// @0x1403ceb10
void GameEventRps::vfunc_6() { ((class CGameRule*)GetGameRule())->SetRps(MS2Ptr<RpsContext>(0)); }
MS2_REPLACE_METHOD(0x1403CEB10, GameEventRps, vfunc_6, 79, 0x1511C25C);

// @0x1403ceb70
void GameEventRps::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (!m_d0)
        return;
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403CEB70, GameEventRps, vfunc_3, 94, 0x4202E158);

// @0x1403cebe0
void GameEventRps::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new RpsContext(GetID()));
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403CEBE0, GameEventRps, vfunc_4, 170, 0x5C6C07B5);

// @0x1403cec90
bool GameEventRps::ReadRpsData(MS2Ptr<RpsContext> pContext)
{
    if (pContext == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(4226), 0);
        return false;
    }
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(4233), 0);
        return false;
    }
    TiXmlElement* root = FUN_140345b40(&doc);
    if (root == NULL)
    {
        MS2_ASSERT_AT(MS2_LINE(4240), 0);
        return false;
    }
    TiXmlElement* xel = FUN_140345b40((TiXmlDocument *)root);
    if (xel == NULL)
    {
        MS2_ASSERT_AT(MS2_LINE(4247), 0);
        return false;
    }
    do
    {
        TiXmlElement* xelTicket = ((class TiXmlElement*)((class Unk_XmlNode*)(xel))->FirstChild("gameTicket"));
        if (xelTicket == NULL)
        {
            MS2_ASSERT_AT(MS2_LINE(4255), 0);
            break;
        }
        XmlGetAttr((class TiXmlElement*)(xelTicket), "itemID", reinterpret_cast<unsigned int&>(pContext->m_20));
    } while (0);
    for (TiXmlElement* xelReward = ((class TiXmlElement*)((class Unk_XmlNode*)(xel))->FirstChild("rewardData")); xelReward; xelReward = ((class TiXmlElement*)((class Unk_XmlNode*)(xelReward))->NextSibling("rewardData")))
    {
        MS2Ptr<RpsContext::RewardData> reward(new RpsContext::RewardData);
        XmlGetAttr((class TiXmlElement*)(xelReward), "condPlayCount", reward->m_count);
        TiXmlElement* xelItems = ((class TiXmlElement*)((class Unk_XmlNode*)(xelReward))->FirstChild("items"));
        if (xelItems == NULL)
        {
            MS2_ASSERT_AT(MS2_LINE(4270), 0);
            return false;
        }
        for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(xelItems))->FirstChild("v")); pNode; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("v")))
        {
            ItemEntity item;
            item.vfunc_2(pNode);
            reward->m_items.Add(item);
        }
        pContext->m_rewards.Add(reward);
    }
    qsort(pContext->m_rewards.GetData(), pContext->m_rewards.GetCount(), sizeof(MS2Ptr<RpsContext::RewardData>), CompareRpsReward);
    return true;
}
MS2_REPLACE_METHOD(0x1403CEC90, GameEventRps, ReadRpsData, 1167, 0x8689EC48);

// ---- GameEventNpcShopTalk -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regNpcShopTalk(L"GameEventNpcShopTalk", (ClassObjectCreateFn)FUN_1403cf130);
#endif
// @0x1403cf130
GameEvent* FUN_1403cf130() { return new GameEventNpcShopTalk; }

// @0x1403cf190
CStringW GameEventNpcShopTalk::GetTypeName() { return CStringW(L"GameEventNpcShopTalk"); }
MS2_REPLACE_METHOD(0x1403CF190, GameEventNpcShopTalk, GetTypeName, 61, 0x218FD688);

// @0x1403cf1e0
GameEventNpcShopTalk::GameEventNpcShopTalk()
{
    SetFlag(3);
    SetFlag(1);
}

// @0x1403cf240
void GameEventNpcShopTalk::vfunc_2()
{
    m_d0 = FUN_140718200(m_68);
    m_d4 = FUN_140718200(m_70);
}
MS2_REPLACE_METHOD(0x1403CF240, GameEventNpcShopTalk, vfunc_2, 70, 0x401550DF);

// @0x1403cf290
void GameEventNpcShopTalk::OnStart() { ((class CGameEventValueNpcShopTalk*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetNpcShopTalk()))->Set(m_d0, m_d4); }
MS2_REPLACE_METHOD(0x1403CF290, GameEventNpcShopTalk, OnStart, 58, 0x21F3548C);

// @0x1403cf2d0
void GameEventNpcShopTalk::vfunc_6() { ((class CGameEventValueNpcShopTalk*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetNpcShopTalk()))->Remove(m_d0); }
MS2_REPLACE_METHOD(0x1403CF2D0, GameEventNpcShopTalk, vfunc_6, 46, 0x674DA7E5);

// @0x1403cf310
void GameEventNpcShopTalk::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteInt(m_d4);
}
MS2_REPLACE_METHOD(0x1403CF310, GameEventNpcShopTalk, vfunc_3, 88, 0xE6820023);

// @0x1403cf370
void GameEventNpcShopTalk::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d4 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403CF370, GameEventNpcShopTalk, vfunc_4, 124, 0x40C53A95);

// ---- GameEventNpcShopGivePoint --------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regNpcShopGivePoint(L"GameEventNpcShopGivePoint", (ClassObjectCreateFn)FUN_1403cf400);
#endif
// @0x1403cf400
GameEvent* FUN_1403cf400() { return new GameEventNpcShopGivePoint; }

// @0x1403cf460
CStringW GameEventNpcShopGivePoint::GetTypeName() { return CStringW(L"GameEventNpcShopGivePoint"); }
MS2_REPLACE_METHOD(0x1403CF460, GameEventNpcShopGivePoint, GetTypeName, 61, 0x215A644C);

// @0x1403cf4b0
GameEventNpcShopGivePoint::GameEventNpcShopGivePoint() : m_d0(0), m_d4(0)
{
    SetFlag(3);
    SetFlag(1);
}

// @0x1403cf540
void GameEventNpcShopGivePoint::vfunc_2()
{
    m_d0 = FUN_140718200(m_68);
    m_d4 = FUN_1407181a0(m_70);
    m_d8 = m_78;
}
MS2_REPLACE_METHOD(0x1403CF540, GameEventNpcShopGivePoint, vfunc_2, 100, 0x6A4F5517);

// @0x1403cf5b0
void GameEventNpcShopGivePoint::OnStart()
{
    MS2Ptr<CNpcShopGivePointContextBase> spContext = CNpcShopGivePointContextBase::Create(m_d4, m_d8);
    if (spContext.get())
        reinterpret_cast<CGameEventValueNpcShopGivePoint*>(TSingleton<CGameEventValueManager>::GetInstance()->GetNpcShopGivePoint())->Set(m_d0, spContext);
}
MS2_REPLACE_METHOD(0x1403CF5B0, GameEventNpcShopGivePoint, OnStart, 163, 0x6FC2B2E4);

// @0x1403cf660
void GameEventNpcShopGivePoint::vfunc_6() { ((class CGameEventValueNpcShopGivePoint*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetNpcShopGivePoint()))->Remove(m_d0); }
MS2_REPLACE_METHOD(0x1403CF660, GameEventNpcShopGivePoint, vfunc_6, 46, 0x357C9667);

// @0x1403cf6a0
void GameEventNpcShopGivePoint::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteByte((unsigned char)m_d4);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403CF6A0, GameEventNpcShopGivePoint, vfunc_3, 129, 0xF736C0F5);

// @0x1403cf730
void GameEventNpcShopGivePoint::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d4 = MS2_GE_R(in)->ReadByte();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403CF730, GameEventNpcShopGivePoint, vfunc_4, 227, 0xD8618411);

// ---- GameEventNpcShopResetPriceSale ---------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regNpcShopResetPriceSale(L"GameEventNpcShopResetPriceSale", (ClassObjectCreateFn)FUN_1403cf820);
#endif
// @0x1403cf820
GameEvent* FUN_1403cf820() { return new GameEventNpcShopResetPriceSale; }

// @0x1403cf880
CStringW GameEventNpcShopResetPriceSale::GetTypeName() { return CStringW(L"GameEventNpcShopResetPriceSale"); }
MS2_REPLACE_METHOD(0x1403CF880, GameEventNpcShopResetPriceSale, GetTypeName, 61, 0x7D90DEC1);

// @0x1403cf8d0
GameEventNpcShopResetPriceSale::GameEventNpcShopResetPriceSale() : m_d0(0), m_d4(0)
{
    SetFlag(3);
    SetFlag(1);
}

// @0x1403cf950
void GameEventNpcShopResetPriceSale::vfunc_2()
{
    m_d0 = FUN_140718200(m_68);
    m_d4 = FUN_140718200(m_70);
}
MS2_REPLACE_METHOD(0x1403CF950, GameEventNpcShopResetPriceSale, vfunc_2, 70, 0x8CC2E78F);

// @0x1403cf9a0
void GameEventNpcShopResetPriceSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteInt(m_d4);
}
MS2_REPLACE_METHOD(0x1403CF9A0, GameEventNpcShopResetPriceSale, vfunc_3, 88, 0x5F8BA8A2);

// @0x1403cfa00
void GameEventNpcShopResetPriceSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d4 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403CFA00, GameEventNpcShopResetPriceSale, vfunc_4, 124, 0xF0C4ABC0);

// @0x1403cfa90
void GameEventNpcShopResetPriceSale::OnStart() { ((class CGameEventValueNpcShopResetPriceSale*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetNpcShopResetPriceSale()))->Set(m_d0, m_d4); }
MS2_REPLACE_METHOD(0x1403CFA90, GameEventNpcShopResetPriceSale, OnStart, 58, 0xCCE9A4AF);

// @0x1403cfad0
void GameEventNpcShopResetPriceSale::vfunc_6() { ((class CGameEventValueNpcShopResetPriceSale*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetNpcShopResetPriceSale()))->Remove(m_d0); }
MS2_REPLACE_METHOD(0x1403CFAD0, GameEventNpcShopResetPriceSale, vfunc_6, 46, 0x3D6B5191);

// ---- GameEventReactor -----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regReactor(L"GameEventReactor", (ClassObjectCreateFn)FUN_1403cfb10);
#endif
// @0x1403cfb10
GameEvent* FUN_1403cfb10() { return new GameEventReactor; }

// @0x1403cfb70
CStringW GameEventReactor::GetTypeName() { return CStringW(L"GameEventReactor"); }
MS2_REPLACE_METHOD(0x1403CFB70, GameEventReactor, GetTypeName, 61, 0x50BD97D2);

// @0x1403cfbc0
GameEventReactor::GameEventReactor()
{
    SetFlag(3);
    SetFlag(1);
    m_d0 = 0;
}

// @0x1403cfc50
void GameEventReactor::vfunc_2()
{
    MS2Ptr<ReactorContext> pContext(new ReactorContext(GetID()));
    if (!pContext)
    {
        MS2_ASSERT_AT(MS2_LINE(4541), 0);
        return;
    }
    if (!ReadReactorData(pContext))
    {
        MS2_ASSERT_AT(MS2_LINE(4547), 0);
        return;
    }
    pContext->m_endTime = GetEndTime().Get();
    m_d0 = pContext;
}
MS2_REPLACE_METHOD(0x1403CFC50, GameEventReactor, vfunc_2, 374, 0x54D82440);

// @0x1403cfdd0
void GameEventReactor::OnStart() { ((class CGameRule*)GetGameRule())->SetReactor(m_d0); }
MS2_REPLACE_METHOD(0x1403CFDD0, GameEventReactor, OnStart, 91, 0x57C06D3C);

// @0x1403cfe40
void GameEventReactor::vfunc_6() { ((class CGameRule*)GetGameRule())->SetReactor(MS2Ptr<ReactorContext>(0)); }
MS2_REPLACE_METHOD(0x1403CFE40, GameEventReactor, vfunc_6, 79, 0x0AE46477);

// @0x1403cfea0
void GameEventReactor::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (!m_d0)
        return;
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403CFEA0, GameEventReactor, vfunc_3, 94, 0x1436D458);

// @0x1403cff10
void GameEventReactor::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new ReactorContext(GetID()));
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403CFF10, GameEventReactor, vfunc_4, 170, 0x2E1A0517);

// @0x1403cffc0
bool GameEventReactor::ReadReactorData(MS2Ptr<ReactorContext> pContext)
{
    if (!pContext)
    {
        MS2_ASSERT_AT(MS2_LINE(4587), 0);
        return false;
    }
    FUN_140274fc0(m_68, &pContext->m_30, L",");
    pContext->m_28 = FUN_1407181a0(m_70);
    return true;
}
MS2_REPLACE_METHOD(0x1403CFFC0, GameEventReactor, ReadReactorData, 197, 0xD96E4B75);

// ---- GameEventCustomTriggerString -----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regCustomTriggerString(L"GameEventCustomTriggerString", (ClassObjectCreateFn)FUN_1403d0090);
#endif
// @0x1403d0090
GameEvent* FUN_1403d0090() { return new GameEventCustomTriggerString; }

// @0x1403d00f0
CStringW GameEventCustomTriggerString::GetTypeName() { return CStringW(L"GameEventCustomTriggerString"); }
MS2_REPLACE_METHOD(0x1403D00F0, GameEventCustomTriggerString, GetTypeName, 61, 0x26A68B16);

// @0x1403d0140
GameEventCustomTriggerString::GameEventCustomTriggerString()
{
    SetFlag(3);
    SetFlag(1);
}

// @0x1403d01c0
void GameEventCustomTriggerString::vfunc_2()
{
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    for (TiXmlElement* pNode = FUN_140345b40((TiXmlDocument *)pRoot); pNode; pNode = ((class TiXmlElement*)(class TiXmlElement*)(pNode))->NextSiblingElement())
    {
        CStringW strId;
        CStringW strName;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", strId);
        XmlGetAttr((class TiXmlElement*)(pNode), "name", strName);
        if (strId.IsEmpty())
            continue;
        m_d0.SetAt(strId, strName);
    }
}
MS2_REPLACE_METHOD(0x1403D01C0, GameEventCustomTriggerString, vfunc_2, 369, 0x5AB2DEBE);

// @0x1403d0340
void GameEventCustomTriggerString::OnStart() {}
MS2_REPLACE_METHOD(0x1403D0340, GameEventCustomTriggerString, OnStart, 6, 0xA9AF6E37);

// @0x1403d0350
void GameEventCustomTriggerString::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403D0350, GameEventCustomTriggerString, vfunc_6, 6, 0xA9AF6E37);

// @0x1403d0360
void GameEventCustomTriggerString::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    MS2_GE_OUT(out) << m_d0;
}
MS2_REPLACE_METHOD(0x1403D0360, GameEventCustomTriggerString, vfunc_3, 58, 0xC221EB62);

// @0x1403d03a0
void GameEventCustomTriggerString::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    MS2_GE_IN(in) >> m_d0;
}
MS2_REPLACE_METHOD(0x1403D03A0, GameEventCustomTriggerString, vfunc_4, 62, 0xA06AFFB7);

// ---- GameEventTreeWatering ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regTreeWatering(L"GameEventTreeWatering", (ClassObjectCreateFn)FUN_1403d03f0);
#endif
// @0x1403d03f0
GameEvent* FUN_1403d03f0() { return new GameEventTreeWatering; }

// @0x1403d0450
CStringW GameEventTreeWatering::GetTypeName() { return CStringW(L"GameEventTreeWatering"); }
MS2_REPLACE_METHOD(0x1403D0450, GameEventTreeWatering, GetTypeName, 61, 0x95D2CAA5);

// @0x1403d04a0
GameEventTreeWatering::GameEventTreeWatering()
{
    SetFlag(3);
    SetFlag(1);
    m_d0 = 0;
    m_f0 = false;
}

// @0x1403d0550
void GameEventTreeWatering::vfunc_2()
{
    MS2Ptr<TreeWateringContext> pContext(new TreeWateringContext(GetID()));
    if (!pContext)
    {
        MS2_ASSERT_AT(MS2_LINE(4671), 0);
        return;
    }
    if (!ReadTreeWateringData(pContext))
    {
        MS2_ASSERT_AT(MS2_LINE(4677), 0);
        return;
    }
    m_d0 = pContext;
}
MS2_REPLACE_METHOD(0x1403D0550, GameEventTreeWatering, vfunc_2, 318, 0x7DF70203);

// @0x1403d06a0
void GameEventTreeWatering::OnStart()
{
    if (m_d0 == 0)
        return;
    ((class CGameRule*)GetGameRule())->SetTreeWatering(m_d0);
}
MS2_REPLACE_METHOD(0x1403D06A0, GameEventTreeWatering, OnStart, 121, 0x04F4AC3E);

// @0x1403d0720
void GameEventTreeWatering::vfunc_6()
{
    if (m_d0 == 0)
        return;
    ((class CGameRule*)GetGameRule())->SetTreeWatering(MS2Ptr<TreeWateringContext>(0));
}
MS2_REPLACE_METHOD(0x1403D0720, GameEventTreeWatering, vfunc_6, 109, 0x524ACF6C);

// @0x1403d07a0
void GameEventTreeWatering::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (!m_d0)
        return;
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403D07A0, GameEventTreeWatering, vfunc_3, 94, 0xC23C5C12);

// @0x1403d0810
void GameEventTreeWatering::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new TreeWateringContext(GetID()));
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403D0810, GameEventTreeWatering, vfunc_4, 170, 0xC30FE115);

// @0x1403d08c0
int GameEventTreeWatering::vfunc_8() { return m_d0 == 0; }
MS2_REPLACE_METHOD(0x1403D08C0, GameEventTreeWatering, vfunc_8, 38, 0x2CD6D6FA);

// @0x1403d08f0
bool GameEventTreeWatering::ReadTreeWateringData(MS2Ptr<TreeWateringContext> pContext)
{
    {
        TiXmlDocument doc;
        if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
            return false;
        TiXmlElement* pRoot = reinterpret_cast<TiXmlElement*>(reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
        if (pRoot == NULL)
            return false;
        TiXmlElement* pTreeStep = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("tree_step"));
        if (pTreeStep)
        {
            for (TiXmlElement* pStep = ((class TiXmlElement*)((class Unk_XmlNode*)(pTreeStep))->FirstChild("step")); pStep; pStep = ((class TiXmlElement*)((class Unk_XmlNode*)(pStep))->NextSibling("step")))
            {
                MS2Ptr<TreeWatering_TreeStep> spStep(new TreeWatering_TreeStep);
                XmlGetAttr((class TiXmlElement*)(pStep), "step", spStep->m_step);
                XmlGetAttr((class TiXmlElement*)(pStep), "begin", spStep->m_beginTime);
                XmlGetAttr((class TiXmlElement*)(pStep), "end", spStep->m_endTime);
                pContext->m_steps.SetAt(spStep->m_step, spStep);
            }
        }
        TiXmlElement* pEmotionDay = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("emotion_day"));
        if (pEmotionDay)
        {
            for (TiXmlElement* pTime = ((class TiXmlElement*)((class Unk_XmlNode*)(pEmotionDay))->FirstChild("time")); pTime; pTime = ((class TiXmlElement*)((class Unk_XmlNode*)(pTime))->NextSibling("time")))
            {
                MS2Ptr<TreeWatering_EmotionDay> spDay(new TreeWatering_EmotionDay);
                XmlGetAttr((class TiXmlElement*)(pTime), "begin", spDay->m_beginTime);
                XmlGetAttr((class TiXmlElement*)(pTime), "end", spDay->m_endTime);
                pContext->m_emotionDays.Add(spDay);
            }
        }
    }
    {
        TiXmlDocument doc;
        if (GetFileSystem()->LoadXmlFromString(&doc, m_70) == 0)
            return false;
        TiXmlElement* pRoot = reinterpret_cast<TiXmlElement*>(reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
        if (pRoot == NULL)
            return false;
        TiXmlElement* pWatering = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("watering_reward"));
        if (pWatering)
        {
            XmlGetAttr((class TiXmlElement*)(pWatering), "MaxRewardCountDaily", pContext->m_nDailyLimit);
            XmlGetAttr((class TiXmlElement*)(pWatering), "itemID", reinterpret_cast<unsigned int&>(pContext->m_8c));
            XmlGetAttr((class TiXmlElement*)(pWatering), "grade", pContext->m_90);
            XmlGetAttr((class TiXmlElement*)(pWatering), "count", reinterpret_cast<unsigned int&>(pContext->m_94));
        }
        TiXmlElement* pEmotion = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("emotion_reward"));
        if (pEmotion)
        {
            XmlGetAttr((class TiXmlElement*)(pEmotion), "MaxRewardCountDaily", pContext->m_nBonusLimit);
            XmlGetAttr((class TiXmlElement*)(pEmotion), "itemID", reinterpret_cast<unsigned int&>(pContext->m_9c));
            XmlGetAttr((class TiXmlElement*)(pEmotion), "grade", pContext->m_a0);
            XmlGetAttr((class TiXmlElement*)(pEmotion), "count", reinterpret_cast<unsigned int&>(pContext->m_a4));
        }
    }
    {
        TiXmlDocument doc;
        if (GetFileSystem()->LoadXmlFromString(&doc, m_78) == 0)
            return false;
        TiXmlElement* pRoot = reinterpret_cast<TiXmlElement*>(reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2"));
        if (pRoot == NULL)
            return false;
        TiXmlElement* pResource = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("resource"));
        if (pResource)
        {
            XmlGetAttr((class TiXmlElement*)(pResource), "FieldID", reinterpret_cast<unsigned int&>(pContext->m_f0));
            XmlGetAttr((class TiXmlElement*)(pResource), "TreeNameTag", pContext->m_strTreeName);
            XmlGetAttr((class TiXmlElement*)(pResource), "WaterPotItemID", reinterpret_cast<unsigned int&>(pContext->m_nWaterItemId));
            XmlGetAttr((class TiXmlElement*)(pResource), "WateringAnimation", pContext->m_strStateWater);
            XmlGetAttr((class TiXmlElement*)(pResource), "EmotionAnimation", pContext->m_strStateBonus);
            XmlGetAttr((class TiXmlElement*)(pResource), "EmotionDayEffect", pContext->m_str118);
        }
        TiXmlElement* pTreeResource = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("tree_resource"));
        if (pTreeResource)
        {
            for (TiXmlElement* pStep = ((class TiXmlElement*)((class Unk_XmlNode*)(pTreeResource))->FirstChild("step")); pStep; pStep = ((class TiXmlElement*)((class Unk_XmlNode*)(pStep))->NextSibling("step")))
            {
                MS2Ptr<TreeWatering_TreeResource> spResource(new TreeWatering_TreeResource);
                XmlGetAttr((class TiXmlElement*)(pStep), "step", spResource->m_id);
                XmlGetAttr((class TiXmlElement*)(pStep), "nif_id", spResource->m_20);
                pContext->m_resources.SetAt(spResource->m_id, spResource);
            }
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x1403D08F0, GameEventTreeWatering, ReadTreeWateringData, 2378, 0xF05F1FFC);

// ---- GameEventShutdownBillboard -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regShutdownBillboard(L"GameEventShutdownBillboard", (ClassObjectCreateFn)FUN_1403d1240);
#endif
// @0x1403d1240
GameEvent* FUN_1403d1240() { return new GameEventShutdownBillboard; }

// @0x1403d12a0
CStringW GameEventShutdownBillboard::GetTypeName() { return CStringW(L"GameEventShutdownBillboard"); }
MS2_REPLACE_METHOD(0x1403D12A0, GameEventShutdownBillboard, GetTypeName, 61, 0x1CEDC64C);

// @0x1403d12f0
GameEventShutdownBillboard::GameEventShutdownBillboard()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d1350
void GameEventShutdownBillboard::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403D1350, GameEventShutdownBillboard, vfunc_2, 6, 0xA9AF6E37);

// @0x1403d1360
void GameEventShutdownBillboard::OnStart() { FUN_1407d1c30((CShutdownEventBillboard *)(TSingleton<CGameEventValueManager>::GetInstance()->ShutdownBillboard()), m_id); }
MS2_REPLACE_METHOD(0x1403D1360, GameEventShutdownBillboard, OnStart, 43, 0xBFBF27ED);

// @0x1403d13a0
void GameEventShutdownBillboard::vfunc_6() { FUN_1407d1ca0((CShutdownEventBillboard *)(TSingleton<CGameEventValueManager>::GetInstance()->ShutdownBillboard()), m_id); }
MS2_REPLACE_METHOD(0x1403D13A0, GameEventShutdownBillboard, vfunc_6, 43, 0xF627A47D);

// ---- GameEventShutdownUGCBanner -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regShutdownUGCBanner(L"GameEventShutdownUGCBanner", (ClassObjectCreateFn)FUN_1403d13e0);
#endif
// @0x1403d13e0
GameEvent* FUN_1403d13e0() { return new GameEventShutdownUGCBanner; }

// @0x1403d1440
CStringW GameEventShutdownUGCBanner::GetTypeName() { return CStringW(L"GameEventShutdownUGCBanner"); }
MS2_REPLACE_METHOD(0x1403D1440, GameEventShutdownUGCBanner, GetTypeName, 61, 0x75239B35);

// @0x1403d1490
GameEventShutdownUGCBanner::GameEventShutdownUGCBanner()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d14f0
void GameEventShutdownUGCBanner::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403D14F0, GameEventShutdownUGCBanner, vfunc_2, 6, 0xA9AF6E37);

// @0x1403d1500
void GameEventShutdownUGCBanner::OnStart() { FUN_1407d1d90((CShutdownEventUGCBanner *)(TSingleton<CGameEventValueManager>::GetInstance()->ShutdownUGCBanner()), m_id); }
MS2_REPLACE_METHOD(0x1403D1500, GameEventShutdownUGCBanner, OnStart, 43, 0x166029F4);

// @0x1403d1540
void GameEventShutdownUGCBanner::vfunc_6() { FUN_1407d1e00((CShutdownEventUGCBanner *)(TSingleton<CGameEventValueManager>::GetInstance()->ShutdownUGCBanner()), m_id); }
MS2_REPLACE_METHOD(0x1403D1540, GameEventShutdownUGCBanner, vfunc_6, 43, 0x2C142084);

// ---- GameEventPublicTest --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regPublicTest(L"GameEventPublicTest", (ClassObjectCreateFn)FUN_1403d1580);
#endif
// @0x1403d1580
GameEvent* FUN_1403d1580() { return new GameEventPublicTest; }

// @0x1403d15e0
CStringW GameEventPublicTest::GetTypeName() { return CStringW(L"GameEventPublicTest"); }
MS2_REPLACE_METHOD(0x1403D15E0, GameEventPublicTest, GetTypeName, 61, 0x03DA0F8B);

// @0x1403d1630
GameEventPublicTest::GameEventPublicTest()
{
    SetFlag(3);
    SetFlag(2);
    SetFlag(1);
}

// @0x1403d16a0
void GameEventPublicTest::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403D16A0, GameEventPublicTest, vfunc_2, 6, 0xA9AF6E37);

// @0x1403d16b0
void GameEventPublicTest::OnStart() { ((class CGameEventValuePublicTest*)(struct Unk_GameEventIntValue*)(TSingleton<CGameEventValueManager>::GetInstance()->GetPublicTest()))->SetValue(1); }
MS2_REPLACE_METHOD(0x1403D16B0, GameEventPublicTest, OnStart, 40, 0xC09BDAC0);

// @0x1403d16e0
void GameEventPublicTest::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403D16E0, GameEventPublicTest, vfunc_6, 6, 0xA9AF6E37);

// ---- GameEventAdventureLevelBonusExpRate ----------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regAdventureLevelBonusExpRate(L"GameEventAdventureLevelBonusExpRate", (ClassObjectCreateFn)FUN_1403d16f0);
#endif
// @0x1403d16f0
GameEvent* FUN_1403d16f0() { return new GameEventAdventureLevelBonusExpRate; }

// @0x1403d1750
CStringW GameEventAdventureLevelBonusExpRate::GetTypeName() { return CStringW(L"GameEventAdventureLevelBonusExpRate"); }
MS2_REPLACE_METHOD(0x1403D1750, GameEventAdventureLevelBonusExpRate, GetTypeName, 61, 0x3D816E6A);

// @0x1403d17a0
GameEventAdventureLevelBonusExpRate::GameEventAdventureLevelBonusExpRate() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d1810
void GameEventAdventureLevelBonusExpRate::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403D1810, GameEventAdventureLevelBonusExpRate, vfunc_2, 42, 0xD2DEE1A6);

// @0x1403d1840
void GameEventAdventureLevelBonusExpRate::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403D1840, GameEventAdventureLevelBonusExpRate, vfunc_3, 61, 0xCC47F319);

// @0x1403d1890
void GameEventAdventureLevelBonusExpRate::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403D1890, GameEventAdventureLevelBonusExpRate, vfunc_4, 79, 0x36F47E14);

// @0x1403d18f0
void GameEventAdventureLevelBonusExpRate::OnStart() { ((class CGameRule*)GetGameRule())->SetAdventureLevelBonusExpRate(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403D18F0, GameEventAdventureLevelBonusExpRate, OnStart, 47, 0x54120E91);

// @0x1403d1930
void GameEventAdventureLevelBonusExpRate::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveAdventureLevelBonusExpRate(m_id); }
MS2_REPLACE_METHOD(0x1403D1930, GameEventAdventureLevelBonusExpRate, vfunc_6, 35, 0xA8BB55AA);

// ---- GameEventBurningLevelup ------------------------------------------------------------------------------------------
// The jumping item's log lines (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
template <class T, class U>
inline void Unk_BurningLevelupLog(Unk_CommonLog* log, int level, int category, const wchar_t* format, const T& first,
                                  const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// CXmlData::GetInt (COMDAT 0x1403d8110) is the inline in cxmldata.h.
MS2_REPLACE_METHOD(0x1403D8110, CXmlData, GetInt, 142, 0xEF9D94D9);

#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regBurningLevelup(L"GameEventBurningLevelup", (ClassObjectCreateFn)FUN_1403d1960);
#endif
// @0x1403d1960
GameEvent* FUN_1403d1960() { return new GameEventBurningLevelup; }

// @0x1403d19c0
CStringW GameEventBurningLevelup::GetTypeName() { return CStringW(L"GameEventBurningLevelup"); }
MS2_REPLACE_METHOD(0x1403D19C0, GameEventBurningLevelup, GetTypeName, 61, 0xB1A8D55A);

// @0x1403d1a10
GameEventBurningLevelup::GameEventBurningLevelup() : m_d0(new BurningLevelupContext)
{
    SetFlag(2);
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d1ad0
void GameEventBurningLevelup::vfunc_2()
{
    m_d0->m_eventId = GetID();
    m_d0->m_endTime = m_38.Get();
    {
        TiXmlDocument doc;
        if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
            return;
        TiXmlElement* pRoot = FUN_140345b40(&doc);
        if (pRoot == NULL)
            return;
        TiXmlElement* pNode = FUN_140345b40((TiXmlDocument *)pRoot);
        if (pNode == NULL)
            return;
        XmlGetAttr((class TiXmlElement*)(pNode), "beginLevel", m_d0->m_beginLevel);
        XmlGetAttr((class TiXmlElement*)(pNode), "endLevel", m_d0->m_endLevel);
        XmlGetAttr((class TiXmlElement*)(pNode), "burningBonus", reinterpret_cast<unsigned int&>(m_d0->m_burningBonus));
        XmlGetAttr((class TiXmlElement*)(pNode), "additionalEffectId", reinterpret_cast<unsigned int&>(m_d0->m_additionalEffectId));
        XmlGetAttr((class TiXmlElement*)(pNode), "setCharacterPopupStringKey", m_d0->m_setCharacterPopupStringKey);
        m_d0->m_setCharacterPopupBottomStringKey =
            FUN_1401bf530(pNode, "setCharacterPopupBottomStringKey", CStringW(L""));
        XmlGetAttr((class TiXmlElement*)(pNode), "descPopupStringKey", m_d0->m_descPopupStringKey);
        XmlGetAttr((class TiXmlElement*)(pNode), "rewardUiTitleStringKey", m_d0->m_rewardUiTitleStringKey);
        XmlGetAttr((class TiXmlElement*)(pNode), "equipNametagSymbolID", m_d0->m_equipNametagSymbolId);
    }
    {
        TiXmlDocument doc;
        if (GetFileSystem()->LoadXmlFromString(&doc, m_70) == 0)
            return;
        TiXmlElement* pRoot = FUN_140345b40(&doc);
        if (pRoot == NULL)
            return;
        TiXmlElement* pNode = FUN_140345b40((TiXmlDocument *)pRoot);
        if (pNode == NULL)
            return;
        for (pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("v")); pNode; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("v")))
        {
            ItemEntity item;
            item.vfunc_2(pNode);
            m_d0->m_rewardItems.push_back(item);
        }
    }
    {
        ATL::CAtlArray<int> ids;
        ParseIntArray(m_78, ids, L",");
        for (size_t i = 0; i < ids.GetCount(); i++)
            m_d0->m_28.insert(ids[i]);
    }
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_80) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    TiXmlElement* pJumping = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("jumpingOption"));
    if (pJumping)
    {
        XmlGetAttr((class TiXmlElement*)(pJumping), "tutorialEndFieldId", reinterpret_cast<unsigned int&>(m_d0->m_tutorialEndFieldId));
        XmlGetAttr((class TiXmlElement*)(pJumping), "jumpingItemDescPopupStringKey", m_d0->m_jumpingItemDescPopupStringKey);
        XmlGetAttr((class TiXmlElement*)(pJumping), "jumpingItemNotifyStringKey", m_d0->m_jumpingItemNotifyStringKey);
        XmlGetAttr((class TiXmlElement*)(pJumping), "jumpingCompleteStringKey", m_d0->m_jumpingCompleteStringKey);
        TiXmlElement* pItem = ((class TiXmlElement*)((class Unk_XmlNode*)(pJumping))->FirstChild("item"));
        if (pItem == NULL)
        {
            MS2_ASSERT_AT(MS2_LINE(5154), 0);
            return;
        }
        MS2Ptr<ItemEntity> spItem(new ItemEntity);
        spItem->vfunc_2(pItem);
        MS2Ptr<CItemData> spItemData = FUN_14053f870(spItem->vfunc_o18_0());
        if (spItemData == 0)
        {
            Unk_BurningLevelupLog(static_cast<Unk_CommonLog*>(GetLogString()), 1, 0x13,
                                  L"Item 정보를 읽을 수 없습니다.burning levelup event({0}) invalid itemID {1}",
                                  m_d0->m_eventId, spItem->vfunc_o18_0());
            MS2_ASSERT_AT(MS2_LINE(5164), 0);
            return;
        }
        if (!spItemData->IsFunctionName(L"LevelPotion"))
        {
            Unk_BurningLevelupLog(static_cast<Unk_CommonLog*>(GetLogString()), 1, 0x13,
                                  L"Item 정보를 읽을 수 없습니다.burning levelup event({0}) itemID {1} NOT LEVEL POTION",
                                  m_d0->m_eventId, spItem->vfunc_o18_0());
            MS2_ASSERT_AT(MS2_LINE(5170), 0);
            return;
        }
        if (!spItemData->FUN_14053d7c0())
        {
            Unk_BurningLevelupLog(static_cast<Unk_CommonLog*>(GetLogString()), 1, 0x13,
                                  L"Item 정보를 읽을 수 없습니다.burning levelup event({0}) itemID {1} NOT BIND CHARACTER",
                                  m_d0->m_eventId, spItem->vfunc_o18_0());
            MS2_ASSERT_AT(MS2_LINE(5176), 0);
            return;
        }
        unsigned short nTargetLevel = (unsigned short)spItemData->function.xml.GetInt(L"targetLevel", 0);
        if (nTargetLevel == 0)
        {
            Unk_BurningLevelupLog(static_cast<Unk_CommonLog*>(GetLogString()), 1, 0x13,
                                  L"Item 정보를 읽을 수 없습니다.burning levelup event({0}) itemID {1} invalid target level",
                                  m_d0->m_eventId, spItem->vfunc_o18_0());
            MS2_ASSERT_AT(MS2_LINE(5183), 0);
            return;
        }
        m_d0->m_spJumpingItem = spItem;
        m_d0->m_8c = nTargetLevel;
    }
}
MS2_REPLACE_METHOD(0x1403D1AD0, GameEventBurningLevelup, vfunc_2, 3286, 0xA544360B);

// @0x1403d27b0
void GameEventBurningLevelup::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403D27B0, GameEventBurningLevelup, vfunc_3, 66, 0xF4F397DE);

// @0x1403d2800
void GameEventBurningLevelup::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403D2800, GameEventBurningLevelup, vfunc_4, 66, 0xF59C940A);

// @0x1403d2850
void GameEventBurningLevelup::OnStart() { ((CGameEventValueBurningLevelup*)(TSingleton<CGameEventValueManager>::GetInstance()->GetBurningLevelup()))->Add(m_d0); }
MS2_REPLACE_METHOD(0x1403D2850, GameEventBurningLevelup, OnStart, 99, 0x57FF77AF);

// @0x1403d28c0
void GameEventBurningLevelup::vfunc_6() { ((CGameEventValueBurningLevelup*)(TSingleton<CGameEventValueManager>::GetInstance()->GetBurningLevelup()))->Remove(m_d0); }
MS2_REPLACE_METHOD(0x1403D28C0, GameEventBurningLevelup, vfunc_6, 99, 0xF75D4F8C);

// ---- GameEventFestival ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regFestival(L"GameEventFestival", (ClassObjectCreateFn)FUN_1403d2930);
#endif
// @0x1403d2930
GameEvent* FUN_1403d2930() { return new GameEventFestival; }

// @0x1403d2990
CStringW GameEventFestival::GetTypeName() { return CStringW(L"GameEventFestival"); }
MS2_REPLACE_METHOD(0x1403D2990, GameEventFestival, GetTypeName, 61, 0x027A9636);

// @0x1403d29e0
GameEventFestival::GameEventFestival() : m_d0(new FestivalContext)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d2a90
void GameEventFestival::vfunc_2()
{
    if (m_d0 == 0)
        m_d0.AssignRaw(new FestivalContext);
    m_d0->m_18 = FUN_140718200(m_68);
    m_d0->m_1c = FUN_140718200(m_70);
    if (!m_78.IsEmpty())
        m_d0->m_beginTime = FUN_140718950(FUN_1401d4330(m_78, 0));
    if (!m_80.IsEmpty())
        m_d0->m_endTime = FUN_140718950(FUN_1401d4330(m_80, 0));
}
MS2_REPLACE_METHOD(0x1403D2A90, GameEventFestival, vfunc_2, 569, 0x26B4B9AD);

// @0x1403d2cd0
void GameEventFestival::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (!m_d0)
        return;
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403D2CD0, GameEventFestival, vfunc_3, 94, 0x8366FA6E);

// @0x1403d2d40
void GameEventFestival::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    if (!m_d0)
        m_d0.AssignRaw(new FestivalContext);
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403D2D40, GameEventFestival, vfunc_4, 184, 0x85D0B06A);

// @0x1403d2e00
void GameEventFestival::OnStart() { reinterpret_cast<CGameEventValueFestival*>(TSingleton<CGameEventValueManager>::GetInstance()->GetFestival())->Add(GetID(), m_d0); }
MS2_REPLACE_METHOD(0x1403D2E00, GameEventFestival, OnStart, 119, 0x77406360);

// @0x1403d2e80
void GameEventFestival::vfunc_6() { ((class CGameEventValueFestival*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetFestival()))->Remove(GetID()); }
MS2_REPLACE_METHOD(0x1403D2E80, GameEventFestival, vfunc_6, 55, 0x2B580719);

// @0x1403d2ec0
int GameEventFestival::GetValue1()
{
    if (m_d0 == 0)
        return 0;
    return m_d0->m_18;
}
MS2_REPLACE_METHOD(0x1403D2EC0, GameEventFestival, GetValue1, 68, 0x48F1FA32);

// @0x1403d2f10
int GameEventFestival::GetValue2()
{
    if (m_d0 == 0)
        return 0;
    return m_d0->m_1c;
}
MS2_REPLACE_METHOD(0x1403D2F10, GameEventFestival, GetValue2, 68, 0x6443EA8D);

// @0x1403d2f60
BOOL GameEventFestival::IsInPeriod()
{
    if (m_d0 == 0)
        return FALSE;
    CMsTime now(GetServerTime());
    if (m_d0->m_beginTime <= now && m_d0->m_endTime > now)
        return TRUE;
    return FALSE;
}
MS2_REPLACE_METHOD(0x1403D2F60, GameEventFestival, IsInPeriod, 159, 0x3DA8F208);

// ---- GameEventCoupleDance -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regCoupleDance(L"GameEventCoupleDance", (ClassObjectCreateFn)FUN_1403d3010);
#endif
// @0x1403d3010
GameEvent* FUN_1403d3010() { return new GameEventCoupleDance; }

// @0x1403d3070
CStringW GameEventCoupleDance::GetTypeName() { return CStringW(L"GameEventCoupleDance"); }
MS2_REPLACE_METHOD(0x1403D3070, GameEventCoupleDance, GetTypeName, 61, 0x0F6CCC20);

// @0x1403d30c0
GameEventCoupleDance::GameEventCoupleDance() : m_d0(new CoupleDanceContext)
{
    SetFlag(3);
    SetFlag(1);
}

// @0x1403d3170
void GameEventCoupleDance::vfunc_2()
{
    m_d0->m_eventId = GetID();
    m_d0->m_beginTime = m_38.Get();
    m_d0->m_endTime = m_28.Get();
    {
        TiXmlDocument doc;
        if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        {
            MS2_ASSERT_AT(MS2_LINE(4337), 0);
            return;
        }
        TiXmlElement* pRoot = FUN_140345b40(&doc);
        if (pRoot == NULL)
        {
            MS2_ASSERT_AT(MS2_LINE(4344), 0);
            return;
        }
        m_d0->LoadReward(pRoot);
    }
    {
        TiXmlDocument doc;
        if (GetFileSystem()->LoadXmlFromString(&doc, m_70) == 0)
        {
            MS2_ASSERT_AT(MS2_LINE(4354), 0);
            return;
        }
        TiXmlElement* pRoot = FUN_140345b40(&doc);
        if (pRoot == NULL)
        {
            MS2_ASSERT_AT(MS2_LINE(4361), 0);
            return;
        }
        m_d0->LoadDance(pRoot);
    }
}
MS2_REPLACE_METHOD(0x1403D3170, GameEventCoupleDance, vfunc_2, 643, 0xCAE3F087);

// @0x1403d3400
void GameEventCoupleDance::OnStart() { reinterpret_cast<CGameEventValueCoupleDance*>(TSingleton<CGameEventValueManager>::GetInstance()->GetCoupleDance())->Set(m_d0); }
MS2_REPLACE_METHOD(0x1403D3400, GameEventCoupleDance, OnStart, 99, 0x4BEC5AF9);

// @0x1403d3470
void GameEventCoupleDance::vfunc_6()
{
    reinterpret_cast<CGameEventValueCoupleDance*>(TSingleton<CGameEventValueManager>::GetInstance()->GetCoupleDance())->Set(MS2Ptr<CoupleDanceContext>(0));
}
MS2_REPLACE_METHOD(0x1403D3470, GameEventCoupleDance, vfunc_6, 87, 0x3BD4A29E);

// @0x1403d34d0
void GameEventCoupleDance::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403D34D0, GameEventCoupleDance, vfunc_3, 66, 0x13D952DB);

// @0x1403d3520
void GameEventCoupleDance::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403D3520, GameEventCoupleDance, vfunc_4, 66, 0x1D864C52);

// ---- GameEventFieldEffect -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regFieldEffect(L"GameEventFieldEffect", (ClassObjectCreateFn)FUN_1403d3570);
#endif
// @0x1403d3570
GameEvent* FUN_1403d3570() { return new GameEventFieldEffect; }

// @0x1403d35d0
CStringW GameEventFieldEffect::GetTypeName() { return CStringW(L"GameEventFieldEffect"); }
MS2_REPLACE_METHOD(0x1403D35D0, GameEventFieldEffect, GetTypeName, 61, 0x000C59E1);

// @0x1403d3620
GameEventFieldEffect::GameEventFieldEffect() : m_d0(new FieldEffectContext)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d36d0
void GameEventFieldEffect::vfunc_2()
{
    CStringW text(m_68);
    ATL::CAtlArray<CStringW> tokens;
    FUN_14025a680(text, tokens, L",");
    for (size_t i = 0; i < tokens.GetCount(); i++)
        m_d0->m_fieldIds.Add(FUN_140718200(tokens[i]));
    m_d0->m_effect = m_70;
}
MS2_REPLACE_METHOD(0x1403D36D0, GameEventFieldEffect, vfunc_2, 272, 0x84A0FAF1);

// @0x1403d37f0
void GameEventFieldEffect::OnStart()
{
    reinterpret_cast<CGameEventValueFieldEffect*>(TSingleton<CGameEventValueManager>::GetInstance()->GetFieldEffect())->Set(m_d0);
    if (m_d0.get())
    {
        if (m_d0->HasField(WorldService::GetInstance()->FUN_141bd3060()))
            TSingleton<CEffectService>::GetInstance()/*C3:TSingleton<CEffectService>::GetInstance*/->SetAreaEffectName(FUN_1401d4330(m_d0->m_effect, 0));
    }
}
MS2_REPLACE_METHOD(0x1403D37F0, GameEventFieldEffect, OnStart, 284, 0xD060D530);

// @0x1403d3920
void GameEventFieldEffect::vfunc_6()
{
    reinterpret_cast<CGameEventValueFieldEffect*>(TSingleton<CGameEventValueManager>::GetInstance()->GetFieldEffect())->Set(MS2Ptr<FieldEffectContext>(0));
    TSingleton<CEffectService>::GetInstance()/*C3:TSingleton<CEffectService>::GetInstance*/->SetAreaEffectName("");
}
MS2_REPLACE_METHOD(0x1403D3920, GameEventFieldEffect, vfunc_6, 136, 0x45F894E8);

// @0x1403d39b0
void GameEventFieldEffect::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (!m_d0)
        return;
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403D39B0, GameEventFieldEffect, vfunc_3, 94, 0x2D10F56A);

// @0x1403d3a20
void GameEventFieldEffect::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    if (!m_d0)
        m_d0.AssignRaw(new FieldEffectContext);
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403D3A20, GameEventFieldEffect, vfunc_4, 184, 0x153206A0);

// ---- GameEventExchangeScrollSale ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regExchangeScrollSale(L"GameEventExchangeScrollSale", (ClassObjectCreateFn)FUN_1403d3ae0);
#endif
// @0x1403d3ae0
GameEvent* FUN_1403d3ae0() { return new GameEventExchangeScrollSale; }

// @0x1403d3b40
CStringW GameEventExchangeScrollSale::GetTypeName() { return CStringW(L"GameEventExchangeScrollSale"); }
MS2_REPLACE_METHOD(0x1403D3B40, GameEventExchangeScrollSale, GetTypeName, 61, 0x74CCA507);

// @0x1403d3c00
void GameEventExchangeScrollSale::vfunc_2()
{
    ParseIntArray(m_68, m_d0, L",");
    m_f0 = FUN_140718200(m_70);
}
MS2_REPLACE_METHOD(0x1403D3C00, GameEventExchangeScrollSale, vfunc_2, 77, 0x926C60E3);

// @0x1403d3c60
void GameEventExchangeScrollSale::OnStart()
{
    for (size_t i = 0; i < m_d0.GetCount(); i++)
        ((class CGameEventValueExchangeScrollSale*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetExchangeScrollSale()))->Set(m_d0[i], m_f0);
}
MS2_REPLACE_METHOD(0x1403D3C60, GameEventExchangeScrollSale, OnStart, 135, 0x130BABE3);

// @0x1403d3cf0
void GameEventExchangeScrollSale::vfunc_6()
{
    for (size_t i = 0; i < m_d0.GetCount(); i++)
        ((class CGameEventValueExchangeScrollSale*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetExchangeScrollSale()))->Remove(m_d0[i]);
}
MS2_REPLACE_METHOD(0x1403D3CF0, GameEventExchangeScrollSale, vfunc_6, 123, 0x3116DF5F);

// @0x1403d3d80
void GameEventExchangeScrollSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    int nCount = (int)m_d0.GetCount();
    out->WriteInt(m_f0);
    out->WriteInt(nCount);
    for (size_t i = 0; i < m_d0.GetCount(); i++)
        out->WriteInt(m_d0[i]);
}
MS2_REPLACE_METHOD(0x1403D3D80, GameEventExchangeScrollSale, vfunc_3, 208, 0xF376D2AF);

// @0x1403d3e60
void GameEventExchangeScrollSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_f0 = MS2_GE_READ_INT(in);
    unsigned nCount = MS2_GE_READ_INT(in);
    m_d0.RemoveAll();
    for (unsigned i = 0; i < nCount; i++)
        m_d0.Add(MS2_GE_READ_INT(in));
}
MS2_REPLACE_METHOD(0x1403D3E60, GameEventExchangeScrollSale, vfunc_4, 221, 0x69D64CFD);

// ---- GameEventItemTradeRestriction ----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regItemTradeRestriction(L"GameEventItemTradeRestriction", (ClassObjectCreateFn)FUN_1403d3f50);
#endif
// @0x1403d3f50
GameEvent* FUN_1403d3f50() { return new GameEventItemTradeRestriction; }

// @0x1403d3fb0
CStringW GameEventItemTradeRestriction::GetTypeName() { return CStringW(L"GameEventItemTradeRestriction"); }
MS2_REPLACE_METHOD(0x1403D3FB0, GameEventItemTradeRestriction, GetTypeName, 61, 0x7F5D7FAE);

// @0x1403d40a0
void GameEventItemTradeRestriction::vfunc_2()
{
    FUN_14025a680(m_68, m_d0, L",");
    ParseIntArray(m_70, m_f0, L",");
    m_110 = FUN_140718200(m_78);
}
MS2_REPLACE_METHOD(0x1403D40A0, GameEventItemTradeRestriction, vfunc_2, 113, 0x65254863);

// @0x1403d4120
void GameEventItemTradeRestriction::OnStart()
{
    ATL::CAtlArray<Unk_ItemTradeRestrictionType> types;
    for (size_t i = 0; i < m_d0.GetCount(); i++)
    {
        const CStringW& strType = m_d0[i];
        if (operator==(strType, L"BlackMarketSell"))
            types.Add(eItemTradeRestriction_BlackMarketSell);
        else if (operator==(strType, L"BlackMarketBuy"))
            types.Add(eItemTradeRestriction_BlackMarketBuy);
        else if (operator==(strType, L"TradeSend"))
            types.Add(eItemTradeRestriction_TradeSend);
        else if (operator==(strType, L"TradeRecv"))
            types.Add(eItemTradeRestriction_TradeRecv);
        else if (operator==(strType, L"DropItem"))
            types.Add(eItemTradeRestriction_DropItem);
        else if (operator==(strType, L"PickupItem"))
            types.Add(eItemTradeRestriction_PickupItem);
        else
            MS2_ASSERT_AT(MS2_LINE(5462), FALSE);
    }
    MS2Ptr<CGameEventValueItemTradeRestriction::RestrictionData> spData(
        new CGameEventValueItemTradeRestriction::RestrictionData);
    for (size_t i = 0; i < m_f0.GetCount(); i++)
    {
        int nItemId = m_f0[i];
        for (size_t j = 0; j < types.GetCount(); j++)
        {
            Unk_ItemTradeRestrictionType eType = types[j];
            spData->SetLimit(eType, nItemId, m_110);
        }
    }
    reinterpret_cast<CGameEventValueItemTradeRestriction*>(TSingleton<CGameEventValueManager>::GetInstance()->GetItemTradeRestriction())->Add(GetID(), spData);
}
MS2_REPLACE_METHOD(0x1403D4120, GameEventItemTradeRestriction, OnStart, 843, 0x984F5098);

// @0x1403d4480
void GameEventItemTradeRestriction::vfunc_6()
{
    ((class CGameEventValueItemTradeRestriction*)(void*)(TSingleton<CGameEventValueManager>::GetInstance()->GetItemTradeRestriction()))->Remove(GetID());
}
MS2_REPLACE_METHOD(0x1403D4480, GameEventItemTradeRestriction, vfunc_6, 55, 0x1BAE2831);

// @0x1403d44c0
void GameEventItemTradeRestriction::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_110);
    size_t nTypes = m_d0.GetCount();
    out->WriteShort((unsigned short)nTypes);
    for (size_t i = 0; i < nTypes; i++)
        out->WriteStringW(m_d0[i]);
    size_t nItems = m_f0.GetCount();
    out->WriteShort((unsigned short)nItems);
    for (size_t i = 0; i < nItems; i++)
        out->WriteInt(m_f0[i]);
}
MS2_REPLACE_METHOD(0x1403D44C0, GameEventItemTradeRestriction, vfunc_3, 345, 0x9E621839);

// @0x1403d4620
void GameEventItemTradeRestriction::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_110 = MS2_GE_R(in)->ReadInt();
    size_t nTypes = MS2_GE_R(in)->ReadShort();
    for (size_t i = 0; i < nTypes; i++)
        m_d0.Add(MS2_GE_R(in)->ReadStringW());
    size_t nItems = MS2_GE_R(in)->ReadShort();
    for (size_t i = 0; i < nItems; i++)
        m_f0.Add(MS2_GE_R(in)->ReadInt());
}
MS2_REPLACE_METHOD(0x1403D4620, GameEventItemTradeRestriction, vfunc_4, 446, 0x4EBB4467);

// ---- GameEventCollectItemGroup --------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regCollectItemGroup(L"GameEventCollectItemGroup", (ClassObjectCreateFn)FUN_1403d47f0);
#endif
// @0x1403d47f0
GameEvent* FUN_1403d47f0() { return new GameEventCollectItemGroup; }

// @0x1403d4850
CStringW GameEventCollectItemGroup::GetTypeName() { return CStringW(L"GameEventCollectItemGroup"); }
MS2_REPLACE_METHOD(0x1403D4850, GameEventCollectItemGroup, GetTypeName, 61, 0x32A21825);

// @0x1403d48a0
GameEventCollectItemGroup::GameEventCollectItemGroup()
{
    SetFlag(1);
    SetFlag(3);
    m_d0 = 0;
}

// @0x1403d4930
void GameEventCollectItemGroup::vfunc_2()
{
    m_d0.AssignRaw(new CollectItemGroupContext);
    m_d0->m_eventId = GetID();
    m_d0->m_beginTime = m_28.Get();
    m_d0->m_endTime = m_38.Get();
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    TiXmlElement* pInfo = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("info"));
    if (pInfo == NULL)
        return;
    XmlGetAttr((class TiXmlElement*)(pInfo), "name", m_d0->m_name);
    TiXmlElement* pResult = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("result"));
    if (pResult == NULL)
        return;
    ItemEntity result;
    m_d0->m_result.vfunc_2(pResult);
    for (TiXmlElement* pCondition = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("condition")); pCondition;
         pCondition = ((class TiXmlElement*)((class Unk_XmlNode*)(pCondition))->NextSibling("condition")))
    {
        ItemEntity item;
        item.vfunc_2(pCondition);
        m_d0->AddCondition(item);
    }
}
MS2_REPLACE_METHOD(0x1403D4930, GameEventCollectItemGroup, vfunc_2, 771, 0x3ADCB592);

// @0x1403d4c40
void GameEventCollectItemGroup::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (m_d0.get())
        m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403D4C40, GameEventCollectItemGroup, vfunc_3, 90, 0xA4493279);

// @0x1403d4ca0
void GameEventCollectItemGroup::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new CollectItemGroupContext);
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403D4CA0, GameEventCollectItemGroup, vfunc_4, 158, 0x4BD70CD9);

// @0x1403d4d50
void GameEventCollectItemGroup::OnStart() { ((CGameEventValueCollectItemGroup*)(TSingleton<CGameEventValueManager>::GetInstance()->GetCollectItemGroup()))->Add(m_d0); }
MS2_REPLACE_METHOD(0x1403D4D50, GameEventCollectItemGroup, OnStart, 99, 0x47F29891);

// @0x1403d4dc0
void GameEventCollectItemGroup::vfunc_6() { ((CGameEventValueCollectItemGroup*)(TSingleton<CGameEventValueManager>::GetInstance()->GetCollectItemGroup()))->Remove(m_d0); }
MS2_REPLACE_METHOD(0x1403D4DC0, GameEventCollectItemGroup, vfunc_6, 99, 0x03C44F0D);

// ---- GameEventShutdownDummy -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regShutdownDummy(L"GameEventShutdownDummy", (ClassObjectCreateFn)FUN_1403d4e30);
#endif
// @0x1403d4e30
GameEvent* FUN_1403d4e30() { return new GameEventShutdownDummy; }

// @0x1403d4e90
CStringW GameEventShutdownDummy::GetTypeName() { return CStringW(L"GameEventShutdownDummy"); }
MS2_REPLACE_METHOD(0x1403D4E90, GameEventShutdownDummy, GetTypeName, 61, 0x541F71D7);

// @0x1403d4ee0
GameEventShutdownDummy::GameEventShutdownDummy() : m_d0(0)
{
    SetFlag(2);
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d4f60
void GameEventShutdownDummy::vfunc_2() { m_id = GetID(); }
MS2_REPLACE_METHOD(0x1403D4F60, GameEventShutdownDummy, vfunc_2, 32, 0x07622CC4);

// @0x1403d4f90
void GameEventShutdownDummy::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt64(m_d0);
}
MS2_REPLACE_METHOD(0x1403D4F90, GameEventShutdownDummy, vfunc_3, 73, 0xA724847B);

// @0x1403d4fe0
void GameEventShutdownDummy::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = (unsigned)MS2_GE_R(in)->ReadInt64();
}
MS2_REPLACE_METHOD(0x1403D4FE0, GameEventShutdownDummy, vfunc_4, 79, 0x31D04805);

// @0x1403d5040
void GameEventShutdownDummy::OnStart() {}
MS2_REPLACE_METHOD(0x1403D5040, GameEventShutdownDummy, OnStart, 6, 0xA9AF6E37);

// @0x1403d5050
void GameEventShutdownDummy::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403D5050, GameEventShutdownDummy, vfunc_6, 6, 0xA9AF6E37);

// @0x1403d5060
bool GameEventShutdownDummy::vfunc_9(void* other) { return true; }
MS2_REPLACE_METHOD(0x1403D5060, GameEventShutdownDummy, vfunc_9, 13, 0xC078F4D1);

// @0x1403d5080
void GameEventShutdownDummy::vfunc_7(MS2Ptr<GameEvent> spPrev)
{
    if (spPrev.get())
        spPrev->vfunc_6();
}
MS2_REPLACE_METHOD(0x1403D5080, GameEventShutdownDummy, vfunc_7, 85, 0x4989C6BF);

// ---- GameEventSalePetCrystal ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSalePetCrystal(L"GameEventSalePetCrystal", (ClassObjectCreateFn)FUN_1403d50e0);
#endif
// @0x1403d50e0
GameEvent* FUN_1403d50e0() { return new GameEventSalePetCrystal; }

// @0x1403d5140
CStringW GameEventSalePetCrystal::GetTypeName() { return CStringW(L"GameEventSalePetCrystal"); }
MS2_REPLACE_METHOD(0x1403D5140, GameEventSalePetCrystal, GetTypeName, 61, 0x0BE93E08);

// @0x1403d5190
GameEventSalePetCrystal::GameEventSalePetCrystal() : m_d0(0)
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d5200
void GameEventSalePetCrystal::vfunc_2() { m_d0 = FUN_140718200(m_68); }
MS2_REPLACE_METHOD(0x1403D5200, GameEventSalePetCrystal, vfunc_2, 42, 0xCC508F14);

// @0x1403d5230
void GameEventSalePetCrystal::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403D5230, GameEventSalePetCrystal, vfunc_3, 61, 0x142A7226);

// @0x1403d5280
void GameEventSalePetCrystal::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403D5280, GameEventSalePetCrystal, vfunc_4, 79, 0xB32A48BB);

// @0x1403d52e0
void GameEventSalePetCrystal::OnStart() { ((class CGameRule*)GetGameRule())->SetPetCrystalSaleRate(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403D52E0, GameEventSalePetCrystal, OnStart, 47, 0xCFD5DC47);

// @0x1403d5320
void GameEventSalePetCrystal::vfunc_6() { ((class CGameRule*)GetGameRule())->RemovePetCrystalSaleRate(m_id); }
MS2_REPLACE_METHOD(0x1403D5320, GameEventSalePetCrystal, vfunc_6, 35, 0x327FD4C0);

// ---- GameEventArcadeOpen --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regArcadeOpen(L"GameEventArcadeOpen", (ClassObjectCreateFn)FUN_1403d5350);
#endif
// @0x1403d5350
GameEvent* FUN_1403d5350() { return new GameEventArcadeOpen; }

// @0x1403d53b0
CStringW GameEventArcadeOpen::GetTypeName() { return CStringW(L"GameEventArcadeOpen"); }
MS2_REPLACE_METHOD(0x1403D53B0, GameEventArcadeOpen, GetTypeName, 61, 0xE362445C);

// @0x1403d5400
GameEventArcadeOpen::GameEventArcadeOpen()
{
    SetFlag(1);
    SetFlag(3);
    m_e0 = false;
    m_d0 = 0;
}

// @0x1403d5490
void GameEventArcadeOpen::vfunc_2()
{
    m_d0.AssignRaw(new ArcadeOpenContext);
    m_e0 = false;
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFromString(&doc, m_68) == 0)
        return;
    TiXmlElement* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    TiXmlElement* pInfo = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("info"));
    if (pInfo == NULL)
        return;
    m_d0->m_eventId = GetID();
    XmlGetAttr((class TiXmlElement*)(pInfo), "arcadeId", m_d0->m_arcadeId);
    XmlGetAttr((class TiXmlElement*)(pInfo), "rewardCountPerDay", m_d0->m_rewardCountPerDay);
    for (TiXmlElement* pReward = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("reward")); pReward; pReward = ((class TiXmlElement*)((class Unk_XmlNode*)(pReward))->NextSibling("reward")))
    {
        ItemEntity item;
        item.vfunc_2(pReward);
        m_d0->m_rewards.push_back(item);
    }
}
MS2_REPLACE_METHOD(0x1403D5490, GameEventArcadeOpen, vfunc_2, 585, 0x143D1250);

// @0x1403d56e0
void GameEventArcadeOpen::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (m_d0.get())
        m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403D56E0, GameEventArcadeOpen, vfunc_3, 90, 0xE73388CB);

// @0x1403d5740
void GameEventArcadeOpen::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new ArcadeOpenContext);
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403D5740, GameEventArcadeOpen, vfunc_4, 158, 0xF05FCD13);

// @0x1403d57f0
void GameEventArcadeOpen::OnStart() { m_e0 = ((CGameEventValueArcadeOpen*)(TSingleton<CGameEventValueManager>::GetInstance()->GetArcadeOpen()))->Add(m_d0); }
MS2_REPLACE_METHOD(0x1403D57F0, GameEventArcadeOpen, OnStart, 110, 0x2C19282F);

// @0x1403d5870
void GameEventArcadeOpen::vfunc_6()
{
    if (m_e0)
        ((CGameEventValueArcadeOpen*)(TSingleton<CGameEventValueManager>::GetInstance()->GetArcadeOpen()))->Remove(m_d0);
    m_e0 = false;
}
MS2_REPLACE_METHOD(0x1403D5870, GameEventArcadeOpen, vfunc_6, 127, 0x88628A37);

// ---- GameEventBingoEvent --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regBingoEvent(L"GameEventBingoEvent", (ClassObjectCreateFn)FUN_1403d5900);
#endif
// @0x1403d5900
GameEvent* FUN_1403d5900() { return new GameEventBingoEvent; }

// @0x1403d5960
CStringW GameEventBingoEvent::GetTypeName() { return CStringW(L"GameEventBingoEvent"); }
MS2_REPLACE_METHOD(0x1403D5960, GameEventBingoEvent, GetTypeName, 61, 0xEC17028F);

// @0x1403d59b0
GameEventBingoEvent::GameEventBingoEvent()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d5a20
void GameEventBingoEvent::vfunc_2()
{
    m_d0.AssignRaw(new BingoContext);
    if (!m_d0->LoadNumbers(m_68))
        return;
    if (!m_d0->LoadRewards(m_70))
        return;
    if (!m_d0->LoadFreeItem(m_78))
        return;
    if (!m_d0->LoadCashItem(m_80))
        return;
    m_d0->m_eventId = GetID();
    m_d0->m_beginTime = GetBeginTime();
    m_d0->m_endTime = GetEndTime();
}
MS2_REPLACE_METHOD(0x1403D5A20, GameEventBingoEvent, vfunc_2, 740, 0x650C259D);

// @0x1403d5d10
void GameEventBingoEvent::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (!m_d0)
        return;
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403D5D10, GameEventBingoEvent, vfunc_3, 94, 0x13B9065C);

// @0x1403d5d80
void GameEventBingoEvent::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new BingoContext);
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403D5D80, GameEventBingoEvent, vfunc_4, 158, 0x18B38944);

// @0x1403d5e30
void GameEventBingoEvent::OnStart() { ((CGameEventValueBingo*)(TSingleton<CGameEventValueManager>::GetInstance()->GetBingoEvent()))->Set(m_d0); }
MS2_REPLACE_METHOD(0x1403D5E30, GameEventBingoEvent, OnStart, 99, 0x236E2604);

// @0x1403d5ea0
void GameEventBingoEvent::vfunc_6() { ((CGameEventValueBingo*)(TSingleton<CGameEventValueManager>::GetInstance()->GetBingoEvent()))->Clear(m_d0); }
MS2_REPLACE_METHOD(0x1403D5EA0, GameEventBingoEvent, vfunc_6, 99, 0xBF565714);

// ---- GameEventFinishPayback -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regFinishPayback(L"GameEventFinishPayback", (ClassObjectCreateFn)FUN_1403d5f10);
#endif
// @0x1403d5f10
GameEvent* FUN_1403d5f10() { return new GameEventFinishPayback; }

// @0x1403d5f70
CStringW GameEventFinishPayback::GetTypeName() { return CStringW(L"GameEventFinishPayback"); }
MS2_REPLACE_METHOD(0x1403D5F70, GameEventFinishPayback, GetTypeName, 61, 0xF28598AE);

// @0x1403d5fc0
GameEventFinishPayback::GameEventFinishPayback()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d6020
void GameEventFinishPayback::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403D6020, GameEventFinishPayback, vfunc_2, 6, 0xA9AF6E37);

// @0x1403d6030
void GameEventFinishPayback::OnStart() {}
MS2_REPLACE_METHOD(0x1403D6030, GameEventFinishPayback, OnStart, 6, 0xA9AF6E37);

// @0x1403d6040
void GameEventFinishPayback::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403D6040, GameEventFinishPayback, vfunc_6, 6, 0xA9AF6E37);

// ---- GameEventLongTermAttendGift ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regLongTermAttendGift(L"GameEventLongTermAttendGift", (ClassObjectCreateFn)FUN_1403d6050);
#endif
// @0x1403d6050
GameEvent* FUN_1403d6050() { return new GameEventLongTermAttendGift; }

// @0x1403d60b0
CStringW GameEventLongTermAttendGift::GetTypeName() { return CStringW(L"GameEventLongTermAttendGift"); }
MS2_REPLACE_METHOD(0x1403D60B0, GameEventLongTermAttendGift, GetTypeName, 61, 0xAE01EFBA);

// @0x1403d6100
GameEventLongTermAttendGift::GameEventLongTermAttendGift()
{
    SetFlag(1);
    SetFlag(3);
    m_d8 = 0;
    m_d0 = true;
}

// @0x1403d6190
void GameEventLongTermAttendGift::vfunc_2()
{
    TiXmlDocument docInfo;
    TiXmlDocument docReward;
    if (m_68.IsEmpty() || m_70.IsEmpty())
        return;
    if (GetFileSystem()->LoadXmlFromString(&docInfo, m_68) == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(5899), 0);
        return;
    }
    if (GetFileSystem()->LoadXmlFromString(&docReward, m_70) == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(5905), 0);
        return;
    }
    MS2Ptr<LongTermAttendGiftContext> spContext(new LongTermAttendGiftContext(GetID()));
    TiXmlElement* pInfo;
    TiXmlElement* pInfoRoot = FUN_140345b40(&docInfo);
    if (pInfoRoot && (pInfo = ((class TiXmlElement*)((class Unk_XmlNode*)(pInfoRoot))->FirstChild("info"))) != NULL)
    {
        XmlGetAttr((class TiXmlElement*)(pInfo), "title", spContext->m_title);
        XmlGetAttr((class TiXmlElement*)(pInfo), "maxattendance", reinterpret_cast<unsigned int&>(spContext->m_maxAttendance));
        XmlGetAttr((class TiXmlElement*)(pInfo), "merat", reinterpret_cast<unsigned int&>(spContext->m_merat));
        XmlGetAttr((class TiXmlElement*)(pInfo), "eventTag", spContext->m_eventTag);
    }
    TiXmlElement* pRewardRoot = FUN_140345b40(&docReward);
    if (pRewardRoot)
    {
        for (TiXmlElement* pReward = ((class TiXmlElement*)((class Unk_XmlNode*)(pRewardRoot))->FirstChild("reward")); pReward;
             pReward = ((class TiXmlElement*)((class Unk_XmlNode*)(pReward))->NextSibling("reward")))
        {
            MS2Ptr<LongTermAttendGiftContext::Reward> spReward(new LongTermAttendGiftContext::Reward);
            XmlGetAttr((class TiXmlElement*)(pReward), "count", spReward->m_count);
            CStringW strItem01;
            CStringW strItem02;
            XmlGetAttr((class TiXmlElement*)(pReward), "item01", strItem01);
            XmlGetAttr((class TiXmlElement*)(pReward), "item02", strItem02);
            spReward->m_item01.vfunc_1(strItem01);
            spReward->m_item02.vfunc_1(strItem02);
            spContext->m_rewards.Add(spReward);
        }
    }
    spContext->m_48 = 0;
    spContext->m_40 = GetEndTime().Get();
    spContext->m_4c = m_d0;
    spContext->m_beginTime = m_28;
    spContext->m_endTime = m_38;
    m_d8 = spContext;
}
MS2_REPLACE_METHOD(0x1403D6190, GameEventLongTermAttendGift, vfunc_2, 1514, 0x3DBC74BB);

// @0x1403d6780
void GameEventLongTermAttendGift::OnStart() { ((class CGameRule*)GetGameRule())->SetLongTermAttendGift(m_d8); }
MS2_REPLACE_METHOD(0x1403D6780, GameEventLongTermAttendGift, OnStart, 91, 0xDE8151D3);

// @0x1403d67f0
void GameEventLongTermAttendGift::vfunc_6() { ((class CGameRule*)GetGameRule())->ClearLongTermAttendGift(m_d8); }
MS2_REPLACE_METHOD(0x1403D67F0, GameEventLongTermAttendGift, vfunc_6, 91, 0x3DC7D238);

// @0x1403d6860
void GameEventLongTermAttendGift::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (!m_d8)
        return;
    m_d8->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403D6860, GameEventLongTermAttendGift, vfunc_3, 94, 0x9E25EBC0);

// @0x1403d68d0
void GameEventLongTermAttendGift::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d8.AssignRaw(new LongTermAttendGiftContext(GetID()));
    m_d8->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403D68D0, GameEventLongTermAttendGift, vfunc_4, 170, 0xFD1B888A);

// ---- GameEventSaleLapenshardUpgradeRGB ------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regSaleLapenshardUpgradeRGB(L"GameEventSaleLapenshardUpgradeRGB", (ClassObjectCreateFn)FUN_1403d6980);
#endif
// @0x1403d6980
GameEvent* FUN_1403d6980() { return new GameEventSaleLapenshardUpgradeRGB; }

// @0x1403d69e0
CStringW GameEventSaleLapenshardUpgradeRGB::GetTypeName() { return CStringW(L"GameEventSaleLapenshardUpgradeRGB"); }
MS2_REPLACE_METHOD(0x1403D69E0, GameEventSaleLapenshardUpgradeRGB, GetTypeName, 61, 0x9B2877AB);

// @0x1403d6a30
GameEventSaleLapenshardUpgradeRGB::GameEventSaleLapenshardUpgradeRGB() {}

// @0x1403d6a70
void GameEventSaleLapenshardUpgradeRGB::OnStart() { ((class CGameRule*)GetGameRule())->SetLapenshardUpgradeSaleRate(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403D6A70, GameEventSaleLapenshardUpgradeRGB, OnStart, 47, 0x1B157730);

// @0x1403d6ab0
void GameEventSaleLapenshardUpgradeRGB::vfunc_6() { ((class CGameRule*)GetGameRule())->RemoveLapenshardUpgradeSaleRate(m_id); }
MS2_REPLACE_METHOD(0x1403D6AB0, GameEventSaleLapenshardUpgradeRGB, vfunc_6, 35, 0x51CC3C66);

// ---- GameEventGuildEventFund ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regGuildEventFund(L"GameEventGuildEventFund", (ClassObjectCreateFn)FUN_1403d6ae0);
#endif
// @0x1403d6ae0
GameEvent* FUN_1403d6ae0() { return new GameEventGuildEventFund; }

// @0x1403d6b40
CStringW GameEventGuildEventFund::GetTypeName() { return CStringW(L"GameEventGuildEventFund"); }
MS2_REPLACE_METHOD(0x1403D6B40, GameEventGuildEventFund, GetTypeName, 61, 0xC4FDA0BA);

// @0x1403d6b90
GameEventGuildEventFund::GameEventGuildEventFund()
{
    SetFlag(4);
    SetFlag(1);
    SetFlag(3);
}

// @0x1403d6c00
void GameEventGuildEventFund::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403D6C00, GameEventGuildEventFund, vfunc_2, 6, 0xA9AF6E37);

// @0x1403d6c10
void GameEventGuildEventFund::OnStart() {}
MS2_REPLACE_METHOD(0x1403D6C10, GameEventGuildEventFund, OnStart, 6, 0xA9AF6E37);

// @0x1403d6c20
void GameEventGuildEventFund::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403D6C20, GameEventGuildEventFund, vfunc_6, 6, 0xA9AF6E37);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9a850-0x142c9a8c0 .text$yd
