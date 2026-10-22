// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The black market pages: the BlackMarketPage base, the item
// search page (BlackMarketPageItemSearch) and the item register page (BlackMarketPageItemRegister).
// MS2-UNIT: client\ms2\uiblackmarketpage.cpp
// MS2-RANGE: 0x1400de020-0x1400de240 .text$di
// MS2-RANGE: 0x140f0be80-0x140f18620 .text$mn
// MS2-PIN: ??$?0VBlackMarketPageItemRegister@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVBlackMarketPageItemRegister@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140f15860 ; the decompile names the Register/Params DelegateImpl
// MS2-PIN: ??$?0VBlackMarketPageItemSearch@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBQEAVBlackMarketPageItemSearch@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140f15a00 ; the remaining look-alike (Search/CMsgBoxData)
// MS2-PIN: ??$FUN_14028dfa0@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HHV12@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBV01@AEBH21@Z 0x140f16cb0 ; the only caller is FUN_140f10d90 (functional: the exe frame is 0x20 smaller)
// MS2-PIN: ??$forward@AEBQEAVBlackMarketPageItemRegister@@@std@@YAAEBQEAVBlackMarketPageItemRegister@@AEBQEAV1@@Z 0x140f17360 ; name order (CAtlStringMgr::Clone is 0x14103c770 by its vftable)
// MS2-PIN: ??$forward@AEBQEAVBlackMarketPageItemSearch@@@std@@YAAEBQEAVBlackMarketPageItemSearch@@AEBQEAV1@@Z 0x140f17370 ; name order
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400de1b0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400de1e0 ; probe
// MS2-PIN: ??_GBlackMarketPage@@UEAAPEAXI@Z 0x140f0c680 ; unique
// MS2-PIN: ??$?0PEAVBlackMarketPageItemRegister@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z$0A@@?$pair@PEAVBlackMarketPageItemRegister@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@QEAA@AEBQEAVBlackMarketPageItemRegister@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140f15820 ; order
// MS2-PIN: ??$?0PEAVBlackMarketPageItemRegister@@P80@EAA_NHAEBVCMsgBoxData@@@Z$0A@@?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@QEAA@AEBQEAVBlackMarketPageItemRegister@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140f158f0 ; order
// MS2-PIN: ??$?0VBlackMarketPageItemRegister@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBQEAVBlackMarketPageItemRegister@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140f15930 ; unique
// MS2-PIN: ??$?0PEAVBlackMarketPageItemSearch@@P80@EAA_NHAEBVCMsgBoxData@@@Z$0A@@?$pair@PEAVBlackMarketPageItemSearch@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@QEAA@AEBQEAVBlackMarketPageItemSearch@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140f159c0 ; order
// MS2-PIN: ??$StringFormat@HHHHHH@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH11111@Z 0x140f15bd0 ; unique
// MS2-PIN: ??$StringFormat@_K_JH@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEB_KAEB_JAEBH@Z 0x140f16020 ; unique
// MS2-PIN: ??$FormatStringId@HHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@HHMMHH@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBH0AEBV01@100AEBM200@Z 0x140f163a0 ; unique
// MS2-PIN: ??$forward@AEBQ8BlackMarketPageItemRegister@@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YAAEBQ8BlackMarketPageItemRegister@@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@ZAEBQ81@EAAX0@Z@Z 0x140f17330 ; order
// MS2-PIN: ??$forward@AEBQ8BlackMarketPageItemRegister@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8BlackMarketPageItemRegister@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x140f17340 ; order
// MS2-PIN: ??$forward@AEBQ8BlackMarketPageItemSearch@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8BlackMarketPageItemSearch@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x140f17350 ; order
// MS2-PIN: ??$make_pair@AEBQEAVBlackMarketPageItemRegister@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA?AU?$pair@PEAVBlackMarketPageItemRegister@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@AEBQEAVBlackMarketPageItemRegister@@AEBQ82@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x140f17380 ; order
// MS2-PIN: ??$make_pair@AEBQEAVBlackMarketPageItemRegister@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA?AU?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@AEBQEAVBlackMarketPageItemRegister@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140f173d0 ; order
// MS2-PIN: ??$make_pair@AEBQEAVBlackMarketPageItemSearch@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA?AU?$pair@PEAVBlackMarketPageItemSearch@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@AEBQEAVBlackMarketPageItemSearch@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140f17420 ; order
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBU?$pair@PEAVBlackMarketPageItemRegister@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@Z 0x140f174c0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x140f17560 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemSearch@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVBlackMarketPageItemSearch@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x140f17600 ; prop
// MS2-PIN: ??0?$SmartPointer@VInvenSlot@@@efd@@QEAA@PEAVInvenSlot@@@Z 0x140f17650 ; unique
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x140f17780 ; order
// MS2-PIN: ??7?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@QEBA_NXZ 0x140f17990 ; unique
// MS2-PIN: ??7?$MS2Ptr@VCBlackMarketProduct@@@@QEBA_NXZ 0x140f179f0 ; unique
// MS2-PIN: ??7?$MS2Ptr@VCBlackMarketSchCond@@@@QEBA_NXZ 0x140f17a20 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCBlackMarketSchCond@@@@QEBAPEAVCBlackMarketSchCond@@XZ 0x140f17a60 ; unique
// MS2-PIN: ??C?$SmartPointer@VInvenSlot@@@efd@@QEBAPEAVInvenSlot@@XZ 0x140f17a70 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAPEAXI@Z 0x140f17a90 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140f17ad0 ; order
// MS2-PIN: ?GetNext@?$CAtlMap@_KV?$MS2Ptr@VCBlackMarketProduct@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBlackMarketProduct@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140f17e40 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@_KV?$MS2Ptr@VCBlackMarketProduct@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCBlackMarketProduct@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VCBlackMarketProduct@@@@PEAU__POSITION@@@Z 0x140f17ee0 ; unique
// MS2-PIN: ?OnInit@?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f18180 ; unique
// MS2-PIN: ?OnInit@?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f181e0 ; unique
// MS2-PIN: ?OnInit@?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemSearch@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f18240 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140f182d0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemSearch@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140f18310 ; unique
// MS2-PIN: ??$Call@VBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140f18380 ; prop
// MS2-PIN: ??$Call@VBlackMarketPageItemSearch@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemSearch@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVBlackMarketPageItemSearch@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140f183b0 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f183e0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemRegister@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f18440 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVBlackMarketPageItemSearch@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f184a0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiblackmarketpage.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiblackmarketpage.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astilelist.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cblackmarketman.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/client/ms2/itempreview.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cmesomarketman.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/gfxui/dragslot.h"
#include "ms2/placeholder/cxmldata.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics of the included headers (internal linkage, one copy per unit) ------------------------------------------

// The sort orders of the meso market lists and of the item lists (names invented; header unidentified).
static CString s_strMesoSortTypeNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // 0x143ac9650
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // 0x143ac9618
static CString s_strSkill = "skill";                                // 0x143ac9698
static CString s_strStun = "stun";                                  // 0x143ac9690
static UICommon::CMyPCKeyInputController s_keyInput;                // 0x143ac95d0

// ---- callees outside the unit ------------------------------------------------------------------------------------

extern __int64 DAT_143ab2820;                                       // the own account id
extern __int64 DAT_143ab2898;                                       // the own mesos
extern Unk_Inventory DAT_143ab2a90;                                 // the player's inventory

void FUN_1407cd930(Scaleform::GFx::Value* pObj, const char* szName, const Scaleform::GFx::Value& v);   // set a member
MS2Ptr<AScript> FUN_1409e7dc0(int nMovieId, const Scaleform::GFx::Value& v);   // wrap an AS value
CStringW FUN_14028de60(int nId);                                    // string table text
CStringW FUN_14028b8e0(const CStringW& str);                        // text of a string key
CStringW FUN_1409404f0(__int64 n);                                  // a money amount as text
CStringW FUN_140719a80(__int64 n);                                  // a 64-bit number as text
unsigned __int64 FUN_140718350(const CString& str);                 // a decimal string as a 64-bit number
CStringW FUN_1413fa9b0(const CStringW& str);                        // the search form of a name
void FUN_140222be0(ATL::CAtlArray<unsigned int>& out);              // the job codes of the search dropdown
int FUN_1402227e0(int nJobCode, int bAll);                          // the job group of a code
unsigned int FUN_140869420();                                       // tick count
int FUN_14028d260(float fSeconds);                                  // seconds -> ticks
int FUN_1406198a0(int nScale, float f);                             // round(f * nScale)
void FUN_1412751f0(const CStringW& text, int nA, int nB);           // system notice text
void FUN_141275260(int nStringId, int nA, int nB);                  // system notice of a string id
void FUN_1412761e0(MS2Ptr<AScript> spRoot, int bLock);              // lock the dialog input while a request runs
void FUN_140d73aa0(CStringW strText, int nA, int nB, CStringW strTitle);   // message box
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStringId, IMessageListener* pListener, CStringW strTitle);   // message box data
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                      // show a message box
bool FUN_140633a90(MS2Ptr<CItem> spItem);                           // the item has a trade count limit
int FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szSep, int nMax);   // split
unsigned int FUN_1401bd000(unsigned int nCategory);                 // the major category of a search category
int FUN_1401bd010(int nCategory);                                   // the minor category of a search category
int FUN_1401bce20(int nGroup, int bPercent, int nStat);             // option key of a basic stat
int FUN_1401bceb0(int nGroup, int bPercent, int nStat);             // option key of a special stat
int FUN_1401bcd30();                                                // default currency
CBlockManager* FUN_140a6a830();                                     // the block manager
void FUN_140a2ff20(const BlockPtr& spBlock, int nAction, int n);    // notice of a blocked action
CStringW FormatStringId(int nId, const fmt::ArgList& args);         // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)

CStringW FUN_14028dfa0(CStringW strKey, const fmt::ArgList& args);   // string table text of a key, formatted
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* psz);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
int FUN_1418fccc0(int nMsg, void* p2, void* p3, const CStringW& strText);   // the key changes the text input

// The inventory slot (invenslot.cpp, efd class id 0x6200023): only what this unit calls. The owning unit's header is not
// in the tree yet.
class InvenSlot : public MS2DragSlot
{
public:
    __int64 FUN_141405a10();                                        // the item uid
    int FUN_141409150(CItem& item);                                 // may the item be registered on the black market
};

CStringW FUN_141275860(__int64 n);                                  // the meso amount text of the total price
CStringW FUN_141275900(const CStringW& str);                        // the meso amount text of a number string
CStringW FUN_1412757d0(__int64 n);                                  // the fee text (feature 0xc5)
CStringW FUN_140719a00(__int64 n);                                  // a number as text
CStringW FUN_14083cb20(const CStringW& str);                        // grouped digits
CStringW FUN_14083cf10(const CStringW& str);                        // the digits of a money text
CStringW FUN_14083cf50(int nCurrency, bool bIcon);                  // the currency name
CStringW FUN_14083bab0(const CMsTime& t, CStringW strSep);          // a date as text
CString FUN_1407194b0(__int64 t);                                   // a time as text
__int64 FUN_140718320(const CStringW& str);                         // a decimal string as a 64-bit number
__int64 FUN_140718370(const CStringW& str);
__int64 FUN_141b71960(const char* sz);                              // a uid string as a number
CStringW FUN_141b71910(__int64 n);                                  // a uid as text
CStringW FUN_14183e930(const CStringW& str, unsigned int nColor);   // colored text
void FUN_14025a680(CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szSep);   // split
void FUN_141349ba0(MS2Ptr<CItem> spItem, CStringW strText, const CString& strUrl);   // item system message
void FUN_141276180(const CString& strSound, const CString& strArg); // play a UI sound
void FUN_140d73bc0(int nStringId, int nA, int nB, CStringW strTitle);   // message box of a string id
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW strText, int nA, Delegate<bool(int, const CMsgBoxData&)> cb);   // OK box
MS2Ptr<CMsgBoxData> FUN_140d748b0(int nType, const CStringW& strTitle, const CStringW& strText, Delegate<bool(int, const CMsgBoxData&)> cb);
void FUN_140d74e50(int n);                                          // close the message boxes of a kind
__int64 FUN_1401bcdb0(__int64 nTotal);                              // the register deposit of a total price
int FUN_1401bce00();                                                // the fee rate
__int64 FUN_1401bcde0();                                            // the register fee
int FUN_1409c1750(const Scaleform::GFx::Value& v);                  // an AS int
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);     // the bind data of a name

// ---- unit helpers (free functions; names invented) ----------------------------------------------------------------
CStringW FUN_140f14c20(CItem& item);
int FUN_140f14ce0(ASObj& obj, MS2Ptr<CBlackMarketProduct> spEntry, bool bManage);
void FUN_140f15570(ASArray& out, CBlackMarketMan::ProductMap& own);
InvenSlot* FUN_140f15b80(NotifyContext::BindData* p);
CString FUN_140f14ae0(int nState);
int FUN_140f15350(int nFirst, int nEnd, POSITION pos, ASArray& out, CBlackMarketMan::ProductList& list);
int FUN_140f156d0(const CStringW& strSort, BOOL bUp);
void FUN_140f15760(ASObj& out, Unk_BmPtr<CBlackMarketTable::TabInfo> spTab);

// ---- inline AScript / ASObj helpers first instantiated by this unit ------------------------------------------------

// @0x140f0c520
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CString a1, Scaleform::GFx::Value a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// 0x140bbeaa0 (inline COMDAT outside the unit's range)
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, const ASDataProvider& a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bce40(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// 0x140e813f0 (inline COMDAT outside the unit's range)
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, const ASArray& a1, int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce40(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- BlackMarketRequest ---------------------------------------------------------------------------------------------

// @0x140f0be80
BlackMarketRequest::BlackMarketRequest()
{
    Reset();
}

// @0x140f0bec0
void BlackMarketRequest::SetProduct(int nAction, unsigned __int64 nKey, int nCount)
{
    m_nKey = nKey;
    m_nAction = nAction;
    m_nCount = nCount;
}
MS2_REPLACE_METHOD(0x140F0BEC0, BlackMarketRequest, SetProduct, 57, 0xB3507A79);

// @0x140f0bf00
void BlackMarketRequest::SetKeyword(int nAction, const CStringW& strKeyword)
{
    m_nAction = nAction;
    m_strKeyword = strKeyword;
}
MS2_REPLACE_METHOD(0x140F0BF00, BlackMarketRequest, SetKeyword, 57, 0x80A0A2D9);

// @0x140f0bf40
void BlackMarketRequest::Reset()
{
    m_nKey = 0;
    m_nAction = 0;
    m_nCount = 0;
    m_strKeyword = L"";
}
MS2_REPLACE_METHOD(0x140F0BF40, BlackMarketRequest, Reset, 75, 0x61E8A540);

// @0x140f0bfa0
int BlackMarketRequest::Done(int nAction)
{
    if (m_nAction == nAction)
    {
        Reset();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140F0BFA0, BlackMarketRequest, Done, 50, 0x0C2A79CE);

// ---- BlackMarketPage ------------------------------------------------------------------------------------------------

// @0x140f0bfe0
BlackMarketPage::BlackMarketPage(const CString& strName)
    : m_bShown(false), m_50(2), m_58(strName)
{
}

// @0x140f0c090
BlackMarketPage::~BlackMarketPage()
{
    m_20 = 0;
    m_30 = 0;
    m_itemList = 0;
}

// @0x140f0c150
void BlackMarketPage::FUN_140f0c150(MS2Ptr<AScript> spRoot)
{
    m_20 = spRoot;
}
MS2_REPLACE_METHOD(0x140F0C150, BlackMarketPage, FUN_140f0c150, 61, 0xA78669EF);

// @0x140f0c1a0
void BlackMarketPage::FUN_140f0c1a0(int nMovieId)
{
    m_50 = nMovieId;
}
MS2_REPLACE_METHOD(0x140F0C1A0, BlackMarketPage, FUN_140f0c1a0, 22, 0x55CC0123);

// @0x140f0c1c0
void BlackMarketPage::OnInit()
{
    if (m_20 == 0)
        return;
    m_20->FUN_140bc71c0<ASMovieClip>(m_58, m_30);
    if (m_30 == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(79), 0);
        return;
    }
    m_30->FUN_140c57d70<ASTileList>("m_itemList", m_itemList);
    MS2_ASSERT_AT(MS2_LINE(84), m_itemList);
}
MS2_REPLACE_METHOD(0x140F0C1C0, BlackMarketPage, OnInit, 374, 0x0815C70C);

// @0x140f0c340
void BlackMarketPage::vfunc_2()
{
    m_bShown = false;
    m_30 = 0;
    m_itemList = 0;
    m_20 = 0;
}
MS2_REPLACE_METHOD(0x140F0C340, BlackMarketPage, vfunc_2, 80, 0x9BBA0FA6);

// @0x140f0c3a0
void BlackMarketPage::vfunc_5()
{
}
MS2_REPLACE_METHOD(0x140F0C3A0, BlackMarketPage, vfunc_5, 6, 0xA9AF6E37);

// @0x140f0c3b0
MS2Ptr<CBlackMarketProduct> BlackMarketPage::vfunc_6(unsigned __int64 nId)
{
    return MS2Ptr<CBlackMarketProduct>(0);
}
MS2_REPLACE_METHOD(0x140F0C3B0, BlackMarketPage, vfunc_6, 60, 0x1CAB204B);

// @0x140f0c400
void BlackMarketPage::FUN_140f0c400(const CString& strState)
{
    if (m_20 == 0 || m_30 == 0)
        return;
    m_20->Invoke("updateNoticeSymbolFrom", strState, m_30->FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x140F0C400, BlackMarketPage, FUN_140f0c400, 276, 0x92838747);

// @0x140f0c6c0 - the CRT's bounds-checked memmove_s (UCRT static-inline copy of this TU).
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
MS2_EMIT_CRT_MEMMOVE_S();                                           // the other copy, 0x140f18500 (auto-paired)

// ---- BlackMarketPageItemSearch --------------------------------------------------------------------------------------

// @0x140f0c7e0
BlackMarketPageItemSearch::BlackMarketPageItemSearch()
    : BlackMarketPage("m_searchPage"), m_nOptionId(-1), m_nCategory(0), m_dwSearchTick(0), m_bAutoCompleteName(false),
      m_nPending(0), m_bSendPending(false)
{
}

// @0x140f0c900
void BlackMarketPageItemSearch::OnInit()
{
    BlackMarketPage::OnInit();
    if (m_30 == 0)
        return;
    m_30->FUN_140bbe940<ASTextInput>("m_inputName", m_spInputName);
    ASObj data(2);
    data.FUN_1409c48f0("maxLevel", CFeatureManager::GetInstance()->FUN_14036db20());
    data.FUN_1407cbbe0("enableSocketSystem", CFeatureManager::GetInstance()->FUN_14036d570(0x2e));
    m_30->Invoke("initData", data.FUN_1422bb870());
}

// @0x140f0caa0
void BlackMarketPageItemSearch::vfunc_2()
{
    BlackMarketPage::vfunc_2();
    m_spInputName = 0;
    m_spCond = 0;
    m_dwSearchTick = 0;
    m_bAutoCompleteName = false;
    m_bSendPending = false;
    m_nPending = 0;
    m_nOptionId = -1;
    m_request.Reset();
    m_tabs.RemoveAll();
}
MS2_REPLACE_METHOD(0x140F0CAA0, BlackMarketPageItemSearch, vfunc_2, 156, 0xC585BF84);

// @0x140f0cb50
void BlackMarketPageItemSearch::vfunc_3()
{
    if (!m_bShown)
    {
        FUN_140f0e050();
        m_bShown = true;
    }
}
MS2_REPLACE_METHOD(0x140F0CB50, BlackMarketPageItemSearch, vfunc_3, 46, 0xB97140FF);

// @0x140f0cb90
// MS2-FUNCTIONAL: stack frame layout of the seven ASData locals differs
int BlackMarketPageItemSearch::vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnChangeCategory", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nTab = data.FUN_1422b8a10();
            Scaleform::GFx::Value ret = data.FUN_1422b9260();
            MS2Ptr<AScript> spRet = FUN_1409e7dc0(m_50, ret);
            if (spRet.get())
                FUN_140f0efe0(static_cast<ASObj&>(*spRet), nTab);
        }
        return 1;
    }
    if (_stricmp("OnChangeLowCategory", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nTab = data.FUN_1422b8a10();
            Scaleform::GFx::Value ret = data.FUN_1422b9260();
            MS2Ptr<AScript> spRet = FUN_1409e7dc0(m_50, ret);
            if (spRet.get())
                FUN_140f0e940(static_cast<ASObj&>(*spRet), nTab);
        }
        return 1;
    }
    if (_stricmp("OnChangePage", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nFirst = data.FUN_1422b8a10();
            int nCount = data.FUN_1422b8a10();
            Scaleform::GFx::Value ret = data.FUN_1422b9260();
            bool bResult = false;
            if (m_nPending == 0 && FUN_140f0f2c0())
            {
                bResult = true;
                FUN_140f0f0f0(nFirst, nFirst + nCount, CBlackMarketMan::GetInstance()->m_listSearch.FindIndex(nFirst));
            }
            FUN_1407cd930(&ret, "result", Scaleform::GFx::Value(bResult));
        }
        return 1;
    }
    if (_stricmp("OnChangeList", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nPage = data.FUN_1422b8a10();
            Scaleform::GFx::Value ret = data.FUN_1422b9260();
            bool bResult = false;
            if (m_nPending == 0 && FUN_140f0f2c0() && m_spCond.get())
            {
                m_spCond->m_dw48 = nPage;
                m_nPending = m_nCategory;
                m_bSendPending = true;
                bResult = true;
            }
            FUN_1407cd930(&ret, "result", Scaleform::GFx::Value(bResult));
        }
        return 1;
    }
    if (_stricmp("OnClickSearch", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nResult = FUN_140f0f310(&data, 0);
            Scaleform::GFx::Value ret = data.FUN_1422b9260();
            FUN_1407cd930(&ret, "result", Scaleform::GFx::Value(nResult != 0));
        }
        return 1;
    }
    if (_stricmp("OnClickSortButton", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strSort = data.FUN_1422b8f40();
            bool bUp = data.FUN_1422b8a90();
            bool bResult = false;
            Scaleform::GFx::Value ret = data.FUN_1422b9260();
            if (m_nPending == 0 && FUN_140f0f2c0() && m_spCond.get())
            {
                m_spCond->m_dw48 = 1;
                m_spCond->m_dw54 = FUN_140f156d0(strSort, bUp != false);
                m_nPending = m_nCategory;
                m_bSendPending = true;
                bResult = true;
            }
            FUN_1407cd930(&ret, "result", Scaleform::GFx::Value(bResult));
        }
        return 1;
    }
    if (_stricmp("OnClickBuy", szMethod) == 0)
    {
        if (ItemPreviewMgr::GetInstance()->FUN_140d40670() != 0)
            return 1;
        {
            BlockPtr spBlock = FUN_140a6a830()->FindBlockedAction(0x26);
            if (spBlock.get())
            {
                FUN_140a2ff20(spBlock, 0x26, 0);
                return 1;
            }
        }
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            unsigned __int64 nId = FUN_140718350(data.FUN_1422b8d30());
            FUN_140f103c0(nId, data.FUN_1422b8d30());
        }
        return 1;
    }
    return 0;
}

// @0x140f0d500
MS2Ptr<CBlackMarketProduct> BlackMarketPageItemSearch::vfunc_6(unsigned __int64 nId)
{
    return CBlackMarketMan::GetInstance()->FUN_140a20ff0(nId);
}
MS2_REPLACE_METHOD(0x140F0D500, BlackMarketPageItemSearch, vfunc_6, 71, 0x1464A8AA);

// @0x140f0d550
void BlackMarketPageItemSearch::vfunc_5()
{
    if (m_bSendPending && m_nPending > 0)
    {
        if (!FUN_140f0f2c0())
            return;
        FUN_140f0c400("loading");
        CBlackMarketMan::GetInstance()->SendBlackMarketMode4(m_spCond);
        m_dwSearchTick = FUN_140869420();
        m_bSendPending = false;
    }
}

// @0x140f0d630
// MS2-FUNCTIONAL: the search candidates list (frame layout)
void BlackMarketPageItemSearch::FUN_140f0d630(int nMsg, void* p2, void* p3)
{
    if (!m_bAutoCompleteName || m_spInputName == 0)
        return;
    if (m_spInputName->FUN_1422c76c0() == 0)
        return;
    CStringW strText = m_spInputName->FUN_1422e0b00();
    if (FUN_1418fccc0(nMsg, p2, p3, strText) == 0)
        return;
    ASDataProvider candidates(2);
    if (strText.GetLength() < 1)
    {
        m_spInputName->Invoke("setCandidates", candidates);
        return;
    }
    strText.TrimRight();
    CStringW strSearch = FUN_1413fa9b0(strText);
    if (strSearch.GetLength() > 0)
    {
        ATL::CRBMap<CStringW, int, ATL::CStringElementTraitsI<CStringW> >* pNames = CItemDataTable::GetInstance()->GetBlackMarketSearchable();
        POSITION pos = pNames->GetHeadPosition();
        while (pos)
        {
            CStringW strName = pNames->GetKeyAt(pos);
            CStringW strNameSearch = FUN_1413fa9b0(strName);
            int nId = pNames->GetValueAt(pos);
            if (!strNameSearch.IsEmpty() && strNameSearch.Find((const wchar_t*)strSearch, 0) != -1)
            {
                ASObj entry(2);
                entry.FUN_1407cbb20("label", strName);
                entry.FUN_1409c0d20("id", nId);
                candidates.FUN_1422bbf00(entry);
            }
            pNames->GetNext(pos);
        }
    }
    m_spInputName->Invoke("setCandidates", candidates);
}

// @0x140f0d990
void BlackMarketPageItemSearch::FUN_140f0d990(int nA, int nB, void* p)
{
    if (m_20.get() && m_spCond.get() && m_nCategory == m_nPending)
    {
        m_nPending = 0;
        ASArray list(2);
        int nCount = FUN_140f15350(nA, nB, (POSITION)p, list, CBlackMarketMan::GetInstance()->m_listSearch);
        m_20->Invoke("buildItemList", list, nCount, (int)(nA == 0));
    }
}

// @0x140f0db00
// MS2-FUNCTIONAL: frame layout of the temporaries
void BlackMarketPageItemSearch::FUN_140f0db00(MS2Ptr<CBlackMarketProduct> spEntry, int nState)
{
    CString strState = FUN_140f14ae0(nState);
    if (!(m_20.get() && spEntry.get() && spEntry->m_item.get()))
        return;
    ASObj obj(2);
    obj.FUN_1407cbb20("marketSN", FUN_140719a80(spEntry->m_qw18));
    obj.FUN_1407cba60("saleState", strState);
    obj.FUN_1407cbb20("price", FUN_1409404f0(spEntry->PriceFor(spEntry->GetRemain())));
    {
        ASSlot slot(2);
        slot.FUN_1409c2190(spEntry->m_item->FUN_140526c50());
        obj.FUN_1409adbe0("slotData", slot.FUN_1422bb870());
    }
    m_20->Invoke("updateItem", obj.FUN_1422bb870(), (long)spEntry->m_n88);
}

// @0x140f0de60
void BlackMarketPageItemSearch::FUN_140f0de60(int nA, int nB, void* p)
{
    if (nB == 0x24)
        FUN_140f0f1d0();
    if (nA == 5)
    {
        if (nB == 0x17)
        {
            MS2Ptr<CBlackMarketProduct> spEntry = CBlackMarketMan::GetInstance()->FUN_140a20ff0((unsigned __int64)p);
            if (spEntry.get())
            {
                spEntry->m_nStateA = 1;
                FUN_140f0db00(spEntry, 4);
            }
        }
        else if (nB == 0x1b)
        {
            MS2Ptr<CBlackMarketProduct> spEntry = CBlackMarketMan::GetInstance()->FUN_140a20ff0((unsigned __int64)p);
            if (spEntry.get())
                FUN_140f0db00(spEntry, 3);
        }
    }
    else if (nA == 4)
    {
        FUN_140f0f250();
    }
}
MS2_REPLACE_METHOD(0x140F0DE60, BlackMarketPageItemSearch, FUN_140f0de60, 365, 0xDD0B319B);

// @0x140f0dfe0
void BlackMarketPageItemSearch::FUN_140f0dfe0(int nAction)
{
    if (m_request.Done(nAction))
        FUN_1412761e0(m_20, 1);
}
MS2_REPLACE_METHOD(0x140F0DFE0, BlackMarketPageItemSearch, FUN_140f0dfe0, 95, 0xF3D8B4A4);

// @0x140f0e050
void BlackMarketPageItemSearch::FUN_140f0e050()
{
    ASObj data(2);
    {
        ASArray categories(2);
        {
            CBlackMarketTable::TabListPtr spTabs = CBlackMarketTable::GetInstance()->GetTabs();
            if (spTabs.get())
                FUN_140f0e7b0(categories, spTabs.operator->());
        }
        data.FUN_1409adbe0("categoryArray", categories.FUN_1422bb870());
        ASArray jobs(2);
        ASObj jobAll(2);
        if (FUN_140f10720(jobAll, L"$s_blackmarket_dropdown_joball", "code", 200))
            jobs.FUN_1422bc050(jobAll.FUN_1422bb870());
        ATL::CAtlArray<unsigned int> jobCodes;
        FUN_140222be0(jobCodes);
        size_t nJobs = jobCodes.GetCount();
        for (size_t i = 0; i < nJobs; i++)
        {
            unsigned int nJob = jobCodes.GetAt(i);
            CStringW strJob = CStringTable::GetInstance()->FUN_141811980(0x4d, nJob);
            ASObj job(2);
            if (FUN_140f10720(job, strJob, "code", nJob))
                jobs.FUN_1422bc050(job.FUN_1422bb870());
        }
        data.FUN_1409adbe0("jobArray", jobs.FUN_1422bb870());
        data.FUN_1407cb9c0("maxLevel", 99);
        ASArray ranks(2);
        ASObj rankAll(2);
        if (FUN_140f10720(rankAll, L"$s_blackmarket_dropdown_rankall", "rank", 0))
            ranks.FUN_1422bc050(rankAll.FUN_1422bb870());
        CStringW strRankFormat = FUN_14028de60(0x91c);
        for (int nRank = 2; nRank < 7; nRank++)
        {
            CStringW strRank = StringFormat((const wchar_t*)strRankFormat, CStringTable::GetInstance()->FUN_141813150(nRank));
            ASObj rank(2);
            if (FUN_140f10720(rank, strRank, "rank", nRank))
                ranks.FUN_1422bc050(rank.FUN_1422bb870());
        }
        data.FUN_1409adbe0("itemRankArray", ranks.FUN_1422bb870());
    }
    if (m_20.get())
        m_20->Invoke("buildSearchOptionList", data.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x140F0E050, BlackMarketPageItemSearch, FUN_140f0e050, 1873, 0x3EC94AF5);

// @0x140f0e7b0
void BlackMarketPageItemSearch::FUN_140f0e7b0(ASArray& out, ATL::CAtlList<Unk_BmPtr<CBlackMarketTable::TabInfo> >* pTabs)
{
    for (POSITION pos = pTabs->GetHeadPosition(); pos; pTabs->GetNext(pos))
    {
        Unk_BmPtr<CBlackMarketTable::TabInfo> spTab = pTabs->GetAt(pos);
        if (spTab.get())
        {
            ASObj tab(2);
            FUN_140f15760(tab, spTab);
            out.FUN_1422bc050(tab.FUN_1422bb870());
            m_tabs.SetAt(spTab->m_nId, spTab);
            if (spTab->m_bShowIncludeLowTab)
                FUN_140f0e7b0(out, &spTab->m_children);
        }
    }
}

// @0x140f0e940
// MS2-FUNCTIONAL: frame layout of the option list temporaries
void BlackMarketPageItemSearch::FUN_140f0e940(ASObj& out, int nTabId)
{
    Unk_BmPtr<CBlackMarketTable::TabInfo> spTab(0);
    static CBlackMarketTable* s_pTable = CBlackMarketTable::GetInstance();
    if (s_pTable == 0)
        return;
    if (!m_tabs.Lookup(nTabId, spTab))
        return;
    int nOptionId = spTab->m_nOptionId;
    if (nOptionId > -1 && m_nOptionId != nOptionId)
    {
        CBlackMarketTable::IdArrayPtr spTables = s_pTable->GetOptionStats(nOptionId);
        if (spTables.operator->() && !spTables->IsEmpty())
        {
            size_t nTables = spTables->GetCount();
            for (size_t i = 0; i < nTables; i++)
            {
                unsigned int nTableId = spTables->GetAt(i);
                CBlackMarketTable::StatArrayPtr spStats = s_pTable->GetStatTable(nTableId);
                if (!spStats)
                {
                    size_t nStats = spStats->GetCount();
                    ASArray list(2);
                    ASObj none(2);
                    none.FUN_1409c0dc0("label", "$s_blackmarket_dropdown_notselect");
                    none.FUN_1407cb9c0("idx", -1);
                    list.FUN_1422bc050(none.FUN_1422bb870());
                    CStringW strPercentFormat(L"%s (%%)");
                    for (size_t j = 0; j < nStats; j++)
                    {
                        CBlackMarketTable::StatPtr spStat = spStats->GetAt(j);
                        if (!spStat)
                            continue;
                        ASObj stat(2);
                        CStringW strLabel;
                        if (spStat->m_nPercent == 0)
                            strLabel = spStat->m_strName;
                        else
                            strLabel.Format((const wchar_t*)strPercentFormat, (const wchar_t*)spStat->m_strName);
                        stat.FUN_1407cbb20("label", strLabel);
                        stat.FUN_1407cb9c0("idx", spStat->m_nId);
                        stat.FUN_140f17290("group", spStat->m_nKind);
                        stat.FUN_1407cb9c0("percent", spStat->m_nPercent);
                        stat.FUN_1409c4a30("defaultValue", spStat->m_fDefault);
                        list.FUN_1422bc050(stat.FUN_1422bb870());
                    }
                    m_nOptionId = nOptionId;
                    CString strList = StringFormat("option{0}", i);
                    out.FUN_1409adbe0(strList, list.FUN_1422bb870());
                    CString strId = StringFormat("option{0}_id", i);
                    out.FUN_1409c0d20(strId, nTableId);
                }
            }
        }
    }
    m_bAutoCompleteName = spTab->m_bAutoCompleteName;
    out.FUN_1407cb9c0("optionId", nOptionId);
    out.FUN_1407cbbe0("autoCompleteName", spTab->m_bAutoCompleteName);
    out.FUN_1407cbbe0("result", true);
}

// @0x140f0efe0
void BlackMarketPageItemSearch::FUN_140f0efe0(ASObj& out, int nTabId)
{
    ASArray list(2);
    Unk_BmPtr<CBlackMarketTable::TabInfo> spTab(0);
    if (m_tabs.Lookup(nTabId, spTab) && !spTab->m_bShowIncludeLowTab)
        FUN_140f0e7b0(list, &spTab->m_children);
    out.FUN_1409adbe0("array", list.FUN_1422bb870());
}

// @0x140f0f0f0
void BlackMarketPageItemSearch::FUN_140f0f0f0(int nFirst, int nEnd, POSITION pos)
{
    if (m_20.get())
    {
        ASArray list(2);
        int nCount = FUN_140f15350(nFirst, nEnd, pos, list, CBlackMarketMan::GetInstance()->m_listSearch);
        m_20->Invoke("buildPage", list, nCount);
    }
}

// @0x140f0f1d0
void BlackMarketPageItemSearch::FUN_140f0f1d0()
{
    if (m_spInputName)
        m_spInputName->FUN_1422e0ab0(L"");
}
MS2_REPLACE_METHOD(0x140F0F1D0, BlackMarketPageItemSearch, FUN_140f0f1d0, 110, 0xB6448B2E);

// @0x140f0f250
void BlackMarketPageItemSearch::FUN_140f0f250()
{
    m_nPending = 0;
    m_bSendPending = false;
    if (m_20.get())
        m_20->Invoke("errorSearchFromDelay");
}
MS2_REPLACE_METHOD(0x140F0F250, BlackMarketPageItemSearch, FUN_140f0f250, 104, 0x982CFE0B);

// @0x140f0f2c0
int BlackMarketPageItemSearch::FUN_140f0f2c0()
{
    unsigned int dwNow = FUN_140869420();
    return (unsigned int)(FUN_14028d260(1.0f) + m_dwSearchTick) <= dwNow;
}

// @0x140f0f310
// MS2-FUNCTIONAL: frame layout (40 locals)
int BlackMarketPageItemSearch::FUN_140f0f310(ASData* pArgs, int n)
{
    if (m_nPending > 0)
        return 0;
    if (!m_spCond)
        m_spCond.AssignRaw(new CBlackMarketSchCond());
    Scaleform::GFx::Value ret = pArgs->FUN_1422b9260();
    MS2Ptr<AScript> spData = FUN_1409e7dc0(m_50, ret);
    if (!spData.get())
        return 0;
    int nCategory = spData->FUN_1422baa20("categoryId").GetInt();
    Unk_BmPtr<CBlackMarketTable::TabInfo> spTab(0);
    if (!m_tabs.Lookup(nCategory, spTab))
        return 0;
    CStringW strItemName = spData->FUN_1422bb2b0("itemName");
    int nMinLevel = atoi(spData->FUN_1422baa20("minLevel").GetString());
    int nMaxLevel = atoi(spData->FUN_1422baa20("maxLevel").GetString());
    if (nMaxLevel == 0)
        nMaxLevel = 99;
    nMinLevel = nMinLevel < nMaxLevel ? nMinLevel : nMaxLevel;
    nMaxLevel = nMaxLevel < nMinLevel ? nMinLevel : nMaxLevel;
    int nJobCode = spData->FUN_1422baa20("jobCode").GetInt();
    int nRank = spData->FUN_1422baa20("rank").GetInt();
    int nPage = spData->FUN_1422baa20("pageNumber").GetInt();
    CStringW strSort = spData->FUN_1422bb2b0("sortDataName");
    BOOL bSortUp = spData->FUN_1422baa20("isSortUp").GetBool() != false;
    BOOL bOptionSearch = spData->FUN_1422baa20("isOptionSearch").GetBool() != false;
    int nLimit = 1;
    int nEnchantMin = spData->FUN_1422baa20("enchantMinLevel").GetInt();
    int nEnchantMax = spData->FUN_1422baa20("enchantMaxLevel").GetInt();
    if (nEnchantMax == -1)
        nEnchantMax = 15;
    int nSocketMin = spData->FUN_1422baa20("socketMinCount").GetInt();
    int nSocketMax = spData->FUN_1422baa20("socketMaxCount").GetInt();
    if (nSocketMax == -1)
        nSocketMax = 3;
    if (!m_spCond.get())
        return 0;
    m_nCategory = nCategory;
    m_spCond->m_dw18 = FUN_1401bd000(nCategory);
    m_spCond->m_dw1c = FUN_1401bd010(nCategory);
    m_spCond->m_dw20 = nMinLevel;
    m_spCond->m_dw24 = nMaxLevel;
    m_spCond->m_dw28 = FUN_1402227e0(nJobCode, nJobCode == 200);
    m_spCond->m_dw2c = nRank;
    m_spCond->m_strName = strItemName;
    m_spCond->m_dw48 = nPage;
    m_spCond->m_dw54 = FUN_140f156d0(strSort, bSortUp != 0);
    m_spCond->m_dw5c = bOptionSearch;
    m_spCond->m_dw60 = nLimit;
    m_spCond->m_dw30 = nEnchantMin;
    m_spCond->m_dw34 = nEnchantMax;
    m_spCond->m_dw38 = nSocketMin;
    m_spCond->m_dw3c = nSocketMax;
    if (bOptionSearch)
    {
        CString strKey;
        for (int i = 0; i < 3; i++)
        {
            strKey = StringFormat("option{0}", i);
            Scaleform::GFx::Value option = spData->FUN_1422baa20(strKey);
            if (!option.IsUndefined())
            {
                MS2Ptr<AScript> spOption = FUN_1409e7dc0(m_50, option);
                if (spOption.get())
                {
                    int nStat = spOption->FUN_1422baa20("idx").GetInt();
                    int nGroup = spOption->FUN_1422baa20("group").GetInt();
                    BOOL bPercent = spOption->FUN_1422baa20("percent").GetInt() == 1;
                    if (nGroup == 0)
                        m_spCond->m_aMin[i] = FUN_1401bce20(0, bPercent, nStat);
                    else
                        m_spCond->m_aMin[i] = FUN_1401bceb0(nGroup, bPercent, nStat);
                    double dValue = spOption->FUN_1422baa20("minValue").GetNumber();
                    int nValue = 0;
                    if (!bPercent)
                    {
                        nValue = (int)dValue;
                    }
                    else
                    {
                        int nScaled = FUN_1406198a0(100, (float)dValue);
                        int nRem = nScaled % 10;
                        int nRound = nScaled - nRem;
                        int nStep;
                        if (nScaled == nRound)
                        {
                            nStep = -5;
                        }
                        else
                        {
                            int nUp = nRound;
                            if (nRem > 4)
                                nUp = nRound + 10;
                            nRound = nUp;
                            nStep = nScaled < nUp ? -5 : 5;
                        }
                        int nResult = nRound + nStep;
                        if (nResult < 0)
                            nResult = 0;
                        nValue = nResult;
                    }
                    m_spCond->m_aMax[i] = nValue;
                }
            }
            else
            {
                m_spCond->m_aMin[i] = 0;
                m_spCond->m_aMax[i] = 0;
            }
        }
    }
    if (m_spCond->m_dw5c == 1)
    {
        CStringW strName = m_spCond->m_strName.Trim();
        if (strName.IsEmpty() && m_spCond->m_dw1c == 99999)
        {
            m_spCond = 0;
            FUN_140d73aa0(FUN_14028b8e0(L"s_blackmarket_error_cannot_searchex_without_condition"), 0, 0, L"");
            return 0;
        }
    }
    m_nPending = nCategory;
    m_bSendPending = true;
    return 1;
}

// @0x140f103c0
// MS2-FUNCTIONAL: frame layout of the notice temporaries
void BlackMarketPageItemSearch::FUN_140f103c0(unsigned __int64 nId, const CString& strState)
{
    MS2Ptr<CBlackMarketProduct> spEntry = CBlackMarketMan::GetInstance()->FUN_140a20ff0(nId);
    if (spEntry == 0 || spEntry->m_item == 0)
        return;
    int nState = (int)spEntry->GetState(false);
    CString strNow = FUN_140f14ae0(nState);
    if (strState.CompareNoCase(strNow) != 0)
        FUN_140f0db00(spEntry, nState);
    if (nState == 4)
    {
        FUN_141275260(0x87, 1, 1);
        return;
    }
    if (nState == 3)
    {
        FUN_1412751f0(FUN_14028b8e0(L"s_blackmarket_error_buy_expired"), 1, 1);
        return;
    }
    if (spEntry->m_qw68 == DAT_143ab2820)
    {
        FUN_140d73aa0(FUN_14028b8e0(L"s_blackmarket_error_cannot_buy_ownProduct"), 0, 0, L"");
        return;
    }
    if (spEntry->PriceFor(1) > DAT_143ab2898)
    {
        FUN_141275260(0x34, 1, 1);
        return;
    }
    FUN_140f108e0(spEntry);
}

// @0x140f10720
int BlackMarketPageItemSearch::FUN_140f10720(ASObj& obj, const CStringW& strLabel, const CString& strKey, int nValue)
{
    obj.FUN_1407cbb20("label", strLabel);
    obj.FUN_1407cb9c0(strKey, nValue);
    return 1;
}
MS2_REPLACE_METHOD(0x140F10720, BlackMarketPageItemSearch, FUN_140f10720, 116, 0xB74BC084);

// @0x140f107a0
void BlackMarketPageItemSearch::FUN_140f107a0(unsigned __int64 nId, int nCount)
{
    MS2Ptr<CBlackMarketProduct> spEntry = CBlackMarketMan::GetInstance()->FUN_140a20ff0(nId);
    if (spEntry == 0 || spEntry->m_item == 0)
        return;
    if (spEntry->PriceFor(nCount) > DAT_143ab2898)
    {
        FUN_141275260(0x34, 1, 1);
        return;
    }
    FUN_1412761e0(m_20, 0);
    m_request.SetProduct(5, 0, 0);
    CBlackMarketMan::GetInstance()->SendBlackMarketMode5(nId, nCount);
}

// @0x140f108e0
// MS2-FUNCTIONAL: frame layout of the message box temporaries
void BlackMarketPageItemSearch::FUN_140f108e0(MS2Ptr<CBlackMarketProduct> spEntry)
{
    if (spEntry == 0)
        return;
    int nCount = spEntry->m_nCount;
    if (nCount < 2)
    {
        FUN_140f10d90(spEntry, 1);
        return;
    }
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x12, 0x295, 0, L"");
    if (spBox)
    {
        __int64 nProductId = spEntry->m_qw18;
        MS2Ptr<CItem> spItem = spEntry->m_item;
        int nUnitCount = 1;
        spBox->FUN_141a015d0(FUN_14028de60(0x45f));
        spBox->FUN_141a01700(0x47d, 0x476, 0);
        MS2Ptr<CMsgBoxDataItem> spData = new CMsgBoxDataItem();
        int nRank = spItem->FUN_140526bd0();
        spData->FUN_141a06630(spItem->FUN_140527b10(), true, nRank);
        spData->m_nUnitCount = nUnitCount;
        spData->m_nCount = 1;
        spData->m_nMax = spEntry->RollCount();
        spData->m_nPrice = (int)spEntry->PriceFor(1);
        spData->m_spItem = spItem;
        spBox->FUN_141a01e60(spData);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &BlackMarketPageItemSearch::FUN_140f113e0));
        spBox->FUN_141a024a0(0);
        spBox->FUN_1405340b0(nProductId);
        FUN_140d73c60(spBox);
    }
}

// @0x140f10d90
// MS2-FUNCTIONAL: frame layout of the message box temporaries
void BlackMarketPageItemSearch::FUN_140f10d90(MS2Ptr<CBlackMarketProduct> spEntry, int nCount)
{
    if (spEntry == 0)
        return;
    MS2Ptr<CItem> spItem = spEntry->m_item;
    if (spItem == 0)
        return;
    MS2Ptr<CItem> spShow = spItem;
    if (nCount != spShow->FUN_140526c50())
    {
        spShow.AssignRaw(new CItem());
        int nRank = spItem->FUN_140526bd0();
        int nId = spItem->FUN_1405276c0();
        spShow->FUN_14052b2e0(nId, nRank, 0, nCount);
    }
    __int64 nProductId = spEntry->m_qw18;
    __int64 nPrice = spEntry->PriceFor(nCount);
    CStringW strMsg;
    CStringW strPrice = FUN_1409404f0(nPrice);
    CStringW strDefault = FUN_14028b8e0(L"s_msg_blackmarket_ask_buy_text_default");
    if (!FUN_140633a90(spItem))
    {
        strMsg = FormatStringId(0x947, strPrice, strDefault);
    }
    else
    {
        int nTradeCount = spItem->FUN_1405273a0();
        int nLeft = nTradeCount - 1;
        strMsg = FUN_14028dfa0(CStringW(L"s_msg_blackmarket_ask_buy_limit_tradecount"), strPrice, nTradeCount, nLeft, strDefault);
    }
    MS2Ptr<CMsgBoxData> spBox = new CMsgBoxData(0x11);
    spBox->FUN_141a01ee0(spShow, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
    spBox->FUN_141a01570(strMsg);
    spBox->FUN_141a01700(0x477, 0x478, 0);
    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &BlackMarketPageItemSearch::FUN_140f115b0));
    spBox->FUN_1405340b0(nProductId);
    spBox->FUN_140533ff0(nCount);
    FUN_140d73c60(spBox);
}

// @0x140f113e0
bool BlackMarketPageItemSearch::FUN_140f113e0(int nResult, const CMsgBoxData& box)
{
    if (!(m_20 == 0) && nResult == 0)
    {
        CStringW strText = box.FUN_141a02d50();
        ATL::CAtlArray<CStringW> parts;
        if (FUN_14028cb70(strText, parts, L",", 2))
        {
            __int64 nId = box.FUN_141a02f10(0, 0);
            int nCount = FUN_1407181a0(parts[1]);
            MS2Ptr<CBlackMarketProduct> spEntry = CBlackMarketMan::GetInstance()->FUN_140a20ff0(nId);
            if (!(spEntry == 0) && !(spEntry->m_item == 0))
            {
                FUN_140f10d90(spEntry, nCount);
                return true;
            }
        }
    }
    return true;
}

// @0x140f115b0
bool BlackMarketPageItemSearch::FUN_140f115b0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        __int64 nId = box.FUN_141a02f10(0, 0);
        int nCount = box.FUN_141a02e50(1, 0);
        FUN_140f107a0(nId, nCount);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140F115B0, BlackMarketPageItemSearch, FUN_140f115b0, 94, 0xDFDE82A5);

// ---- BlackMarketRegisterItem ----------------------------------------------------------------------------------------

// @0x140f11620
BlackMarketRegisterItem::BlackMarketRegisterItem()
    : m_nItemId(0), m_nRank(0), m_nPrice(0), m_nDefault(0)
{
    m_nDefault = FUN_1401bcd30();
}

// @0x140f11680
void BlackMarketRegisterItem::Reset()
{
    m_nItemId = 0;
    m_nRank = 0;
    m_nPrice = 0;
    m_nDefault = FUN_1401bcd30();
}
MS2_REPLACE_METHOD(0x140F11680, BlackMarketRegisterItem, Reset, 63, 0xB592D8CF);

// @0x140f116d0
int BlackMarketRegisterItem::IsSame(int nId, int nRank)
{
    if (nId == m_nItemId && nRank == m_nRank)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140F116D0, BlackMarketRegisterItem, IsSame, 51, 0xC5340896);

// @0x140f11710
int BlackMarketRegisterItem::Set(MS2Ptr<CItem> spItem)
{
    if (!spItem)
    {
        Reset();
        return 0;
    }
    int nId = spItem->FUN_1405276c0();
    int nRank = spItem->FUN_140526bd0();
    if (IsSame(nId, nRank))
        return 0;
    m_nItemId = nId;
    m_nRank = nRank;
    m_nPrice = 0;
    m_nDefault = FUN_1401bcd30();
    return 1;
}
MS2_REPLACE_METHOD(0x140F11710, BlackMarketRegisterItem, Set, 244, 0x53030FD3);

// @0x140f11810
void BlackMarketRegisterItem::SetPrice(unsigned __int64 nPrice)
{
    m_nPrice = nPrice;
}
MS2_REPLACE_METHOD(0x140F11810, BlackMarketRegisterItem, SetPrice, 25, 0x4B644A6B);

// @0x140f11830
unsigned __int64 BlackMarketRegisterItem::GetPrice()
{
    return m_nPrice;
}
MS2_REPLACE_METHOD(0x140F11830, BlackMarketRegisterItem, GetPrice, 15, 0x5B8A7339);

// ---- BlackMarketPageItemRegister ------------------------------------------------------------------------------------

// @0x140f11850
BlackMarketPageItemRegister::BlackMarketPageItemRegister()
    : BlackMarketPage("m_registerPage")
{
}

// @0x140f11910
void BlackMarketPageItemRegister::OnInit()
{
    BlackMarketPage::OnInit();
    ASObj data(2);
    {
        __int64 nMin = TSingleton<Client::Constants>::GetInstance()->BlackMarketSellMinPrice.Read();
        __int64 nMax = TSingleton<Client::Constants>::GetInstance()->BlackMarketSellMaxPrice.Read();
        CStringW strTooltip = FormatStringId(0x94a, FUN_1409404f0(nMin), FUN_1409404f0(nMax));
        data.FUN_1409c1180("minPrice", nMin);
        data.FUN_1409c1180("maxPrice", nMax);
        data.FUN_1407cbb20("tooltipSellPrice", strTooltip);
        CStringW strFee = FUN_140f14900(0);
        data.FUN_1407cbb20("noticeFee", strFee);
    }
    m_30->Invoke("initData", data.FUN_1422bb870());
    m_spCounter = m_30->FUN_1409b4620("m_counter");
    MS2Ptr<ASMovieClip> spControl = m_30->FUN_1409b4560("m_registerControl");
    if (spControl)
    {
        m_spTotalPrice = spControl->FUN_1409b4620("m_totalprice");
        MS2Ptr<ASTextField> spNumber = spControl->FUN_1409b4620("m_totalpriceNumberString");
        if (spNumber)
        {
            if (CFeatureManager::GetInstance()->FUN_14036d570(0xc5) == true)
            {
                spNumber->vfunc_4(true);
                spNumber->FUN_1422c4f00(FUN_141275860(0));
                m_spTotalPriceNumber = spNumber;
            }
            else
            {
                spNumber->vfunc_4(false);
                MS2Ptr<ASTextField> spMax = spControl->FUN_1409b4620("m_maxPrice");
                float y = spNumber->FUN_1422c1110();
                if (spMax)
                    spMax->FUN_1422c05a0(y);
                MS2Ptr<ASTextField> spTextMax = spControl->FUN_1409b4620("m_textMaxPrice");
                if (spTextMax)
                    spTextMax->FUN_1422c05a0(y);
            }
        }
    }
    CString strEvent("changeTotalPrice");
    m_30->FUN_1422c3600(strEvent, Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageItemRegister::FUN_140f13610), 0, 0, 0, 0);
}

// @0x140f12090
void BlackMarketPageItemRegister::vfunc_2()
{
    BlackMarketPage::vfunc_2();
    m_bFilled = false;
    m_spCounter = 0;
    m_spTotalPriceNumber = 0;
    m_spTotalPrice = 0;
    m_item.Reset();
    m_request.Reset();
}
MS2_REPLACE_METHOD(0x140F12090, BlackMarketPageItemRegister, vfunc_2, 132, 0xA12DB105);

// @0x140f12120
void BlackMarketPageItemRegister::vfunc_3()
{
    if (!m_bShown)
    {
        FUN_140f132c0(CBlackMarketMan::GetInstance()->m_mapOwn);
        m_bFilled = true;
        m_bShown = true;
    }
}
MS2_REPLACE_METHOD(0x140F12120, BlackMarketPageItemRegister, vfunc_3, 69, 0x752ABA5E);

// @0x140f12170
int BlackMarketPageItemRegister::vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnEnableRegister", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CString strSlot = data.FUN_1422b8d30();
            Scaleform::GFx::Value vResult = data.FUN_1422b9260();
            efd::SmartPointer<InvenSlot> spSlot = FUN_140f15b80(FUN_1422c8e90(strSlot));
            if (spSlot)
            {
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(spSlot->FUN_141405a10());
                if (spItem.get())
                {
                    if (spSlot->FUN_141409150(*spItem))
                    {
                        MS2Ptr<AScript> spResult = FUN_1409e7dc0(m_50, vResult);
                        if (spResult.get())
                        {
                            if (FUN_140f14650(static_cast<ASObj&>(*spResult), *spItem, m_item))
                            {
                                static_cast<ASObj*>(spResult.operator->())->FUN_1407cbbe0("success", true);
                                FUN_140f13ce0(spItem);
                            }
                        }
                    }
                }
            }
        }
        return 1;
    }
    if (_stricmp("OnClickRegister", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            __int64 nUid = FUN_141b71960(data.FUN_1422b8d30());
            __int64 nPrice = FUN_140718320(data.FUN_1422b8f40());
            int nCount = data.FUN_1422b8a10();
            FUN_140f13e70(nUid, nPrice, nCount);
        }
        return 1;
    }
    if (_stricmp("OnClickCancelSell", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            unsigned __int64 nId = FUN_140718350(data.FUN_1422b8d30());
            MS2Ptr<CBlackMarketProduct> spEntry = CBlackMarketMan::GetInstance()->FUN_140a20e70(nId);
            if (spEntry.get())
            {
                m_request.SetProduct(3, nId, spEntry->GetRemain());
                int nRemain = spEntry->GetRemain();
                __int64 nPrice = spEntry->PriceFor(nRemain);
                CStringW strMsg;
                int nState = (int)spEntry->GetState(true);
                if (nState == 5)
                    strMsg = FUN_14028dfa0(CStringW(L"s_msg_blackmarket_ask_stopsale_hide"), FUN_1409404f0(nPrice));
                else if (nState == 3)
                    strMsg = FUN_14028dfa0(CStringW(L"s_msg_blackmarket_ask_stopsale_expired"), FUN_1409404f0(nPrice));
                else
                    strMsg = FUN_14028dfa0(CStringW(L"s_msg_blackmarket_ask_stopsale"), FUN_1409404f0(nPrice));
                MS2Ptr<CMsgBoxData> spBox = new CMsgBoxData(0x11);
                spBox->FUN_141a01ee0(spEntry->m_item, spEntry->m_item->FUN_140527b10(), 1, 0, -1, -1, 1);
                spBox->FUN_141a01570(strMsg);
                spBox->FUN_141a01700(0x477, 0x478, 0);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &BlackMarketPageItemRegister::FUN_140f13950));
                FUN_140d73c60(spBox);
            }
        }
        return 1;
    }
    if (_stricmp("OnClearSlot", szMethod) == 0)
    {
        m_item.Reset();
        return 1;
    }
    return 0;
}

// @0x140f12c10
MS2Ptr<CBlackMarketProduct> BlackMarketPageItemRegister::vfunc_6(unsigned __int64 nId)
{
    return CBlackMarketMan::GetInstance()->FUN_140a20e70(nId);
}
MS2_REPLACE_METHOD(0x140F12C10, BlackMarketPageItemRegister, vfunc_6, 71, 0x93A8B238);

// @0x140f12c60
void BlackMarketPageItemRegister::vfunc_5()
{
    if (m_bFilled)
    {
        if (m_spCounter)
        {
            int nCount = (int)CBlackMarketMan::GetInstance()->FUN_140a210b0();
            int nMax = 0x1c;
            CStringW strText = FUN_14028dfa0(CStringW(L"s_blackmarket_register_counter"), nCount, nMax);
            m_spCounter->FUN_1422c4f00(strText);
        }
        m_bFilled = false;
    }
}
MS2_REPLACE_METHOD(0x140F12C60, BlackMarketPageItemRegister, vfunc_5, 205, 0x99A30F19);

// @0x140f12d40
void BlackMarketPageItemRegister::FUN_140f12d40(MS2Ptr<CBlackMarketProduct> spEntry)
{
    if (m_20 == 0 || spEntry == 0)
        return;
    if (!m_bShown)
        return;
    ASObj obj(2);
    if (FUN_140f14ce0(obj, spEntry, true))
    {
        int nIndex = FUN_1409c1750(m_20->Invoke("registItemComplete", obj.FUN_1422bb870()));
        spEntry->m_n88 = nIndex;
    }
    int nDays = TSingleton<Client::Constants>::GetInstance()->BlackMarketSellEndDay.Read();
    CStringW strMsg = FormatStringId(0x943, nDays);
    FUN_141349ba0(spEntry->m_item, strMsg, CString(""));
    FUN_141276180("BlackMarket_Ready", "");
    m_bFilled = true;
}

// @0x140f13030
void BlackMarketPageItemRegister::FUN_140f13030(MS2Ptr<CBlackMarketProduct> spEntry, int nReason)
{
    if (m_20 == 0 || spEntry == 0)
        return;
    if (!m_bShown)
        return;
    m_20->Invoke("removeItemComplete", FUN_140719a80(spEntry->m_qw18));
    m_bFilled = true;
    CStringW strMsg;
    if (nReason == 0)
        strMsg = FUN_14028de60(0x944);
    else
        strMsg = FUN_14028b8e0(L"s_msg_blackmarket_complete_remove_already");
    FUN_141349ba0(spEntry->m_item, strMsg, CString(""));
}

// @0x140f132c0
void BlackMarketPageItemRegister::FUN_140f132c0(CBlackMarketMan::ProductMap& own)
{
    if (m_20 == 0)
        return;
    ASArray list(2);
    FUN_140f15570(list, own);
    m_20->Invoke("buildOwnerItemList", list.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x140F132C0, BlackMarketPageItemRegister, FUN_140f132c0, 220, 0x467E0E18);

// @0x140f133b0
void BlackMarketPageItemRegister::FUN_140f133b0(int nAction)
{
    if (m_request.Done(nAction))
        FUN_1412761e0(m_20, 1);
}
MS2_REPLACE_METHOD(0x140F133B0, BlackMarketPageItemRegister, FUN_140f133b0, 97, 0xCCD30EAC);

// @0x140f13420
void BlackMarketPageItemRegister::FUN_140f13420(NotifyContext::BindData* pSlot, CItem& item)
{
    if (m_20 == 0)
        return;
    NotifyContext::BindData* pBind = FUN_1422c8e90(pSlot->FUN_1422c89f0());
    if (pBind != 0)
    {
        ASObj obj(2);
        if (FUN_140f14650(obj, item, m_item))
        {
            m_20->Invoke("setRegisterItem", pBind->FUN_1422c8d40(), obj.FUN_1422bb870());
            FUN_140f13ce0(MS2Ptr<CItem>(&item));
        }
    }
}

// @0x140f13610
void BlackMarketPageItemRegister::FUN_140f13610(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_spTotalPriceNumber == 0 || m_spTotalPrice == 0)
        return;
    CStringW strPrice = FUN_14083cf10(m_spTotalPrice->FUN_1422c4da0());
    CStringW strText = FUN_14028dfa0(CStringW(L"s_blackmarket_totalprice_numberstring"), FUN_141275900(strPrice));
    m_spTotalPriceNumber->vfunc_4(true);
    m_spTotalPriceNumber->FUN_1422c4f00(strText);
}
MS2_REPLACE_METHOD(0x140F13610, BlackMarketPageItemRegister, FUN_140f13610, 380, 0xC3B47861);

// @0x140f137a0
void BlackMarketPageItemRegister::FUN_140f137a0(int nItemId, int nRank, unsigned __int64 nPrice)
{
    if (m_20 == 0)
        return;
    if (!m_item.IsSame(nItemId, nRank))
        return;
    m_item.SetPrice(nPrice);
    if (m_20.get())
    {
        CStringW strPrice(nPrice == 0 ? L"$s_blackmarket_price_in_shop_unknown" : (const wchar_t*)FUN_1409404f0(nPrice));
        m_20->Invoke("setRefPrice", strPrice);
    }
}

// @0x140f13950
bool BlackMarketPageItemRegister::FUN_140f13950(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        FUN_1412761e0(m_20, 0);
        CBlackMarketMan::GetInstance()->SendBlackMarketMode3(m_request.m_nKey);
    }
    else
    {
        m_request.Reset();
    }
    return true;
}
MS2_REPLACE_METHOD(0x140F13950, BlackMarketPageItemRegister, FUN_140f13950, 127, 0xB38F8A72);

// @0x140f139e0
bool BlackMarketPageItemRegister::FUN_140f139e0(int nResult, const CMsgBoxData& box)
{
    FUN_140f13d80();
    return true;
}
MS2_REPLACE_METHOD(0x140F139E0, BlackMarketPageItemRegister, FUN_140f139e0, 35, 0xEE40416C);

// @0x140f13a10
bool BlackMarketPageItemRegister::FUN_140f13a10(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        FUN_140d74e50(6);
        int nRate = CGameRule::GetInstance()->FUN_140479560();
        if (nRate < 0)
        {
            FUN_140f13d80();
        }
        else
        {
            __int64 nBegin = CGameRule::GetInstance()->FUN_140479580();
            __int64 nEnd = CGameRule::GetInstance()->FUN_1404795a0();
            CStringW strMsg = FormatStringId(0x949, FUN_14083bab0(CMsTime(nBegin), L"/"), FUN_14083bab0(CMsTime(nEnd), L"/"), FUN_14083cf50(nRate, true));
            FUN_140d74390(strMsg, 0, Delegate<bool(int, const CMsgBoxData&)>(this, &BlackMarketPageItemRegister::FUN_140f139e0));
        }
    }
    return true;
}

// @0x140f13ce0
void BlackMarketPageItemRegister::FUN_140f13ce0(MS2Ptr<CItem> spItem)
{
    if (!spItem)
        return;
    if (m_item.Set(spItem))
        CBlackMarketMan::GetInstance()->SendBlackMarketMode8(m_item.m_nItemId, m_item.m_nRank);
}
MS2_REPLACE_METHOD(0x140F13CE0, BlackMarketPageItemRegister, FUN_140f13ce0, 154, 0x160E98B9);

// @0x140f13d80
void BlackMarketPageItemRegister::FUN_140f13d80()
{
    CStringW strKeyword = m_request.m_strKeyword;
    ATL::CAtlArray<CStringW> parts;
    FUN_14025a680(strKeyword, parts, L",");
    if (parts.GetCount() >= 3)
    {
        __int64 nUid = FUN_140718370(parts.GetAt(0));
        __int64 nPrice = FUN_140718320(parts.GetAt(1));
        int nCount = FUN_1407181a0(parts.GetAt(2));
        CBlackMarketMan::GetInstance()->SendBlackMarketMode2(nUid, nPrice, nCount);
    }
}
MS2_REPLACE_METHOD(0x140F13D80, BlackMarketPageItemRegister, FUN_140f13d80, 232, 0xE2EC43A2);

// @0x140f13e70
// MS2-FUNCTIONAL: frame layout of the message box temporaries
void BlackMarketPageItemRegister::FUN_140f13e70(unsigned __int64 nUid, __int64 nPrice, int nCount)
{
    if (nUid == 0)
        return;
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
    if (!spItem)
    {
        FUN_140d73bc0(0x935, 0, 0, L"");
        return;
    }
    if (spItem->FUN_140526c50() < (unsigned int)nCount)
    {
        FUN_140d73bc0(0x931, 0, 0, L"");
        return;
    }
    {
        BlockPtr spBlock = FUN_140a6a830()->FindBlockedAction(0x25);
        if (spBlock.get())
        {
            FUN_140a2ff20(spBlock, 0x25, 0);
            return;
        }
    }
    __int64 nTotal = nPrice * nCount;
    __int64 nMin = TSingleton<Client::Constants>::GetInstance()->BlackMarketSellMinPrice.Read();
    __int64 nMax = TSingleton<Client::Constants>::GetInstance()->BlackMarketSellMaxPrice.Read();
    if (nTotal < nMin || nMax < nTotal)
    {
        FUN_140d73aa0(FormatStringId(0x930, FUN_1409404f0(nMin), FUN_1409404f0(nMax)), 0, 0, L"");
        return;
    }
    __int64 nDeposit = FUN_1401bcdb0(nTotal);
    if (DAT_143ab2898 < nDeposit)
    {
        CStringW strKey(L"s_blackmarket_error_register_lack_deposit");
        FUN_140d73aa0(FUN_14028b8e0(strKey), 0, 0, L"");
        return;
    }
    if ((int)CBlackMarketMan::GetInstance()->FUN_140a210b0() < 0x1c)
    {
        CStringW strKeyword = StringFormat(L"{0},{1},{2}", nUid, nPrice, nCount);
        m_request.SetKeyword(2, strKeyword);
        Unk_MesoLimits& limits = CMesoMarketMan::GetInstance()->FUN_140d6e940();
        CStringW strTitle = FormatStringId(0x9d8, FUN_1409404f0(nDeposit));
        float fRateB = limits.FUN_140d6e210();
        float fRateA = limits.FUN_140d6e1f0();
        int nFeeRate = FUN_1401bce00();
        CStringW strText = FormatStringId(0x9d9, *TSingleton<Client::Constants>::GetInstance()->BlackMarketSellEndDay.Get(),
            nFeeRate, FUN_1409404f0(FUN_1401bcde0()), FUN_14083cf50(FUN_1401bcd30(), false),
            *TSingleton<Client::Constants>::GetInstance()->MailExpiryDays.Get(), limits.m_n24, fRateA, fRateB, limits.m_n1C,
            limits.m_n20);
        FUN_140d748b0(6, strTitle, strText, Delegate<bool(int, const CMsgBoxData&)>(this, &BlackMarketPageItemRegister::FUN_140f13a10));
    }
    else
    {
        int nLimit = 0x1c;
        FUN_140d73aa0(FormatStringId(0x933, nLimit), 0, 0, L"");
    }
}

// @0x140f14650
int BlackMarketPageItemRegister::FUN_140f14650(ASObj& obj, CItem& item, BlackMarketRegisterItem& reg)
{
    __int64 nDefault = 0;
    int nId = item.FUN_1405276c0();
    int nRank = item.FUN_140526bd0();
    if (reg.IsSame(nId, nRank))
    {
        if (reg.GetPrice() != 0)
            obj.FUN_1407cbb20("refPrice", FUN_1409404f0(reg.GetPrice()));
    }
    __int64 nMax = TSingleton<Client::Constants>::GetInstance()->BlackMarketSellMaxPrice.Read();
    obj.FUN_1407cbb20("maxPrice", FUN_1409404f0(nMax));
    obj.FUN_1407cbb20("defaultPrice", FUN_1409404f0(nDefault));
    obj.FUN_1407cbb20("itemGUID", FUN_141b71910(item.FUN_140526a50()));
    obj.FUN_1407cbb20("itemName", FUN_140f14c20(item));
    int nItemRank = item.FUN_140526bd0();
    if (nItemRank != reg.m_nRank && reg.m_nDefault != FUN_1401bcd30())
    {
        CStringW strFee = FUN_140f14900(nItemRank);
        obj.FUN_1407cbb20("noticeFee", strFee);
    }
    return 1;
}

// @0x140f14900
CStringW BlackMarketPageItemRegister::FUN_140f14900(int nRank)
{
    int nDays = TSingleton<Client::Constants>::GetInstance()->BlackMarketSellEndDay.Read();
    int nCurrency = FUN_1401bcd30();
    int nFeeRate = FUN_1401bce00();
    __int64 nFee = FUN_1401bcde0();
    CStringW strFee;
    if (CFeatureManager::GetInstance()->FUN_14036d570(0xc5))
        strFee = FUN_1412757d0(nFee);
    else
        strFee = FUN_14083cb20(FUN_140719a00(nFee));
    return FormatStringId(0x92a, nDays, FUN_14083cf50(nCurrency, false), nFeeRate, strFee);
}
MS2_REPLACE_METHOD(0x140F14900, BlackMarketPageItemRegister, FUN_140f14900, 462, 0xB381B06F);

// ---- free helpers ---------------------------------------------------------------------------------------------------

// @0x140f14ae0
CString FUN_140f14ae0(int nState)
{
    switch (nState)
    {
    case 1: return "wait";
    case 2: return "sale";
    case 3: return "expired";
    case 4: return "soldout";
    case 5: return "hide";
    default: return "";
    }
}
MS2_REPLACE(0x140F14AE0, FUN_140f14ae0, 302, 0x062046CE);

// @0x140f14c20
CStringW FUN_140f14c20(CItem& item)
{
    unsigned int nColor = CItemDataTable::GetInstance()->GetTextColor((ItemGradeKey)item.FUN_140526bd0());
    CStringW strName = FUN_14183e930(item.FUN_140527b10(), nColor);
    return strName;
}
MS2_REPLACE(0x140F14C20, FUN_140f14c20, 178, 0xE7807FED);

// @0x140f14ce0
// MS2-FUNCTIONAL: frame layout of the temporaries
int FUN_140f14ce0(ASObj& obj, MS2Ptr<CBlackMarketProduct> spEntry, bool bManage)
{
    if (!spEntry || !spEntry->m_item)
        return 0;
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        MS2Ptr<CItem> spItem = spEntry->m_item;
        if (spItem.get())
        {
            ASSlot slot(2);
            if (slot.FUN_1409c3860(spItem.get(), pPlayer, 0x4415))
                obj.FUN_1409adbe0("slotData", slot.FUN_1422bb870());
            obj.FUN_1407cbb20("marketSN", FUN_140719a80(spEntry->m_qw18));
            obj.FUN_1407cbb20("name", FUN_140f14c20(*spItem));
            obj.FUN_1409c48f0("level", spItem->FUN_1405282d0());
            __int64 nUnitPrice = spEntry->m_nUnitPrice;
            obj.FUN_1407cbb20("price", FUN_1409404f0(spEntry->PriceFor(spEntry->GetRemain())));
            {
                // CItem::FUN_140527840 returns the item's CItemData (citem.h keeps the older placeholder type).
                MS2Ptr<CItemData> spData = reinterpret_cast<CItemData*>(spItem->FUN_140527840());
                if (spData && spData->property.slotMax > 1)
                    obj.FUN_1407cbb20("price_1", FormatStringId(0x91b, FUN_1409404f0(nUnitPrice)));
            }
            int nState = (int)spEntry->GetState(bManage);
            obj.FUN_1407cba60("saleState", FUN_140f14ae0(nState));
            if (!bManage)
            {
                if (spEntry->m_qw68 == DAT_143ab2820)
                    obj.FUN_1407cbbe0("myItem", true);
            }
            else
            {
                obj.FUN_1407cbbe0("manage", bManage);
                obj.FUN_1407cba60("createtime", FUN_1407194b0(spEntry->m_qw20));
                if (nState == 2)
                {
                    CMsTime tEnd(spEntry->m_nExpire);
                    CStringW strPeriod = StringFormat((const wchar_t*)FUN_14028de60(0x91d), tEnd.GetYear(), tEnd.GetMonth(),
                        tEnd.GetDay(), tEnd.GetHour(), tEnd.GetMinute(), tEnd.GetSecond());
                    obj.FUN_1407cbb20("period", strPeriod);
                }
            }
        }
    }
    return 1;
}

// @0x140f15350
int FUN_140f15350(int nFirst, int nEnd, POSITION pos, ASArray& out, CBlackMarketMan::ProductList& list)
{
    if (nFirst > -1 && nFirst <= nEnd && !list.IsEmpty())
    {
        int nLast = nEnd;
        if (nFirst + 6 < nEnd)
            nLast = nFirst + 6;
        POSITION p = pos;
        if (pos == 0)
            p = list.GetHeadPosition();
        POSITION cur = p;
        for (int i = nFirst; cur != 0 && i <= nLast; i++)
        {
            MS2Ptr<CBlackMarketProduct> spEntry = list.GetAt(cur);
            if (spEntry.get())
            {
                ASObj obj(2);
                if (FUN_140f14ce0(obj, spEntry, false))
                {
                    spEntry->m_n88 = i;
                    out.FUN_1422bc050(obj.FUN_1422bb870());
                }
            }
            list.GetNext(cur);
        }
    }
    return (int)list.GetCount();
}

// @0x140f15570
void FUN_140f15570(ASArray& out, CBlackMarketMan::ProductMap& own)
{
    int nIndex = 0;
    for (POSITION pos = own.GetStartPosition(); pos != 0; own.GetNext(pos), nIndex++)
    {
        ASObj obj(2);
        MS2Ptr<CBlackMarketProduct> spEntry = own.GetValueAt(pos);
        if (spEntry.get())
        {
            if (FUN_140f14ce0(obj, spEntry, true))
            {
                out.FUN_1422bc050(obj.FUN_1422bb870());
                spEntry->m_n88 = nIndex;
            }
        }
    }
}
MS2_REPLACE(0x140F15570, FUN_140f15570, 338, 0xD2F5FFBA);

// @0x140f156d0
int FUN_140f156d0(const CStringW& strSort, BOOL bUp)
{
    if (strSort.CompareNoCase(L"level") == 0)
        return bUp ? 0xb : 0xc;
    else if (strSort.CompareNoCase(L"price") == 0)
        return bUp ? 0x15 : 0x16;
    return 0;
}
MS2_REPLACE(0x140F156D0, FUN_140f156d0, 126, 0x3DDFD6BF);

// @0x140f15760
void FUN_140f15760(ASObj& out, Unk_BmPtr<CBlackMarketTable::TabInfo> spTab)
{
    if (spTab.get())
    {
        out.FUN_1407cbb20("label", spTab->m_strName);
        out.FUN_1407cb9c0("id", spTab->m_nId);
        out.FUN_1407cb9c0("priority", spTab->m_nPriority);
    }
}
MS2_REPLACE(0x140F15760, FUN_140f15760, 185, 0x82EC7B5D);

// @0x140f15b80
InvenSlot* FUN_140f15b80(NotifyContext::BindData* p)
{
    InvenSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200023, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}
MS2_REPLACE(0x140F15B80, FUN_140f15b80, 73, 0xA75D82B9);

// ---- inline COMDATs of the unit (definition order is irrelevant: COMDATs follow the unit's own functions) ----------

// @0x140f17080
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, const ASArray& a1, int a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce40(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f17150
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, Scaleform::GFx::Value a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f17290
inline void ASObj::FUN_140f17290(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca8e80-0x142ca8f40 .text$yd
