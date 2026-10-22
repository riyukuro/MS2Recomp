// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CashInventoryBag / CashInventorySlot (the bag of the cash
// inventory "pick up" slots) and CCashMarketMan (the cash shop product lists and the handlers of packet 0x6a), which sat
// in the same translation unit. See cashinventorybag.h and placeholder/ccashmarketman.h.
// (units.tsv lists the mn range as ending at 0x140b0dc70; the tiny CDialogEx::GetThisClass wrapper 0x140b0dc40 inside it
// is CCashUnlockDialog::_GetBaseClass (IMPLEMENT_DYNAMIC of cashunlockdialog.cpp, which starts at 0x140b0dc70).)
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: ?\cashinventorybag.cpp
// MS2-RANGE: 0x140b055c0-0x140b0dc40 .text$mn
// MS2-RANGE: 0x1400c6cf0-0x1400c73cc .text$di
// MS2-PIN: ??_7CashInventorySlot@@6BBindData@NotifyContext@@@ 0x142dd8b58 ; hand: primary vftable
// MS2-PIN: ?GetClassDesc@CashInventoryBag@@UEBAPEBVClassInfo@efd@@XZ 0x140b05bd0 ; hand
// MS2-PIN: ?TypeCast@CashInventoryBag@@UEBA_NIPEAPEAX@Z 0x140b05c80 ; hand
// MS2-PIN: ?TypeCast@CashInventoryBag@@UEBA_NIPEAPEBX@Z 0x140b05cd0 ; hand
// MS2-PIN: ?GetClassDesc@CashInventorySlot@@UEBAPEBVClassInfo@efd@@XZ 0x140b0db30 ; hand
// MS2-PIN: ?TypeCast@CashInventorySlot@@UEBA_NIPEAPEAX@Z 0x140b0dba0 ; hand
// MS2-PIN: ?TypeCast@CashInventorySlot@@UEBA_NIPEAPEBX@Z 0x140b0dbf0 ; hand
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?get@?$MS2Ptr@VCCashInventoryProduct@@@@QEBAPEAVCCashInventoryProduct@@XZ 0x140b05b50 ; unique
// MS2-PIN: ?FUN_140b05c00@CCashMarketMan@@QEAAAEAV?$CAtlArray@V?$MS2Ptr@VCCashInventoryProduct@@@@V?$CElementTraits@V?$MS2Ptr@VCCashInventoryProduct@@@@@ATL@@@ATL@@XZ 0x140b05c00 ; unique
// MS2-PIN: memmove_s 0x140b05d20 ; unique
// MS2-PIN: ??$?0VCCashMarketMan@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBQEAVCCashMarketMan@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140b090d0 ; unique
// MS2-PIN: ??$?0W4Unk_CashResult@@$0A@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@QEAA@AEBW4Unk_CashResult@@@Z 0x140b09160 ; unique
// MS2-PIN: ??$?8PEAVCCashMarketMan@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVCCashMarketMan@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140b091c0 ; unique
// MS2-PIN: ??$Unk_CashMessage@H@@YAXHHHAEBH@Z 0x140b09210 ; unique
// MS2-PIN: ??$Unk_CashMessage@HW4Unk_CashResult@@@@YAXHHHAEBHAEBW4Unk_CashResult@@@Z 0x140b09290 ; unique
// MS2-PIN: ??$FormatCustomArg@W4Unk_CashResult@@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@SAXPEAXPEBX0@Z 0x140b09740 ; unique
// MS2-PIN: ??1CPair@?$CAtlMap@HV?$MS2Ptr@VCCashSaleProduct@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCCashSaleProduct@@@@@3@@ATL@@QEAA@XZ 0x140b0a090 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCMarketBuyLimitHistory@@@@QEAAAEAV1@PEAVCMarketBuyLimitHistory@@@Z 0x140b0a190 ; unique
// MS2-PIN: ??7?$MS2Ptr@VCCashSaleProduct@@@@QEBA_NXZ 0x140b0a200 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCCashSaleProduct@@@@QEBAPEAVCCashSaleProduct@@XZ 0x140b0a2c0 ; unique
// MS2-PIN: ??_G?$MS2Ptr@VCCashSaleProduct@@@@QEAAPEAXI@Z 0x140b0a360 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCCashSaleProduct@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCCashSaleProduct@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140b0aac0 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$MS2Ptr@VCCashSaleProduct@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCCashSaleProduct@@@@@3@@ATL@@QEBA_NHAEAV?$MS2Ptr@VCCashSaleProduct@@@@@Z 0x140b0b290 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@HV?$MS2Ptr@VCCashSaleProduct@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCCashSaleProduct@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$MS2Ptr@VCCashSaleProduct@@@@@Z 0x140b0c410 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCCashMarketMan@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140b0cd80 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCCashMarketMan@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140b0cde0 ; unique
// MS2-PIN: ??$Call@VCCashMarketMan@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVCCashMarketMan@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVCCashMarketMan@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140b0ce20 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCCashMarketMan@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140b0ce50 ; unique
// MS2-PIN: ??$StringFormat@HI@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBHAEBI@Z 0x140b0d790 ; unique
// MS2-PIN: ??7?$MS2Ptr@VCCashInventoryProduct@@@@QEBA_NXZ 0x140b0daa0 ; unique
// MS2-PIN: ??_GCashInventorySlot@@UEAAPEAXI@Z 0x140b0dad0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cashinventorybag.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "cashinventorybag.h"
#include "ms2/placeholder/ccashmarketman.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/cashshopref.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2format.h"
#include "hook/ms2hook.h"
#include <sstream>
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class Unk_CashGameCtx
{
public:
    void* FUN_141bd0cc0();
};
Unk_CashGameCtx* FUN_1403ed2d0();

// Feature switches of the client.
class Unk_CashFeature { public: bool FUN_14036e4c0(); bool FUN_14036e5b0(); };
Unk_CashFeature* FUN_140166410();
int FUN_1401d5a60();
int FUN_1401d5ab0();
int FUN_1401d5b00();
__int64 FUN_140869440();                                // now

// The cash shop dialog (id 0x4ebc); the exe calls its members through the handle of the cash shop ref.
int FUN_141034dc0(UICashShopDialog* pDlg, int nId);
void FUN_141035050(UICashShopDialog* pDlg);
void FUN_141034e00(UICashShopDialog* pDlg, int n);
void FUN_141035080(UICashShopDialog* pDlg, int n);
int FUN_1410356a0(UICashShopDialog* pDlg);
void FUN_141034ef0(UICashShopDialog* pDlg, int n, CInPacket& packet);

// The market bill dialog (id 0x4f17) and the handle it gives of its owner.
class Unk_CashBillOwner { public: int m_pad[7]; int m_nId; };
class Unk_CashBillRef
{
public:
    ~Unk_CashBillRef();                                 // 0x140a8e150
    bool FUN_140a8e270(int n);
    Unk_CashBillOwner* FUN_140a8e380();
private:
    char m_pad[0x20];
};
class UIMarketBillDialog : public UIDialog
{
public:
    Unk_CashBillRef FUN_140ea8da0();
};

// UI service: handle to a registered UI object.
class Unk_CashUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nClass); void FUN_141adc5d0(int nClass); };
Unk_CashUIManager* FUN_1403ed2b0();

// Item data of an item id (only the item class test is used).
class Unk_CashItemData : public CPtred { public: char m_pad[8]; };
MS2Ptr<Unk_CashItemData> FUN_14053f870(int nItemId);
char FUN_14053c6b0(Unk_CashItemData* pData, int nFlag);
void* FUN_1401d3200();
void* FUN_140298f80(void* p);
void FUN_1418fe1c0(void* p);

// The limit rows of the two market buy limit tables.
class Unk_CashLimitRowA : public CPtred
{
public:
    int FUN_1406a4370();
    int FUN_1406a4640();
    char m_pad[0xbc - 0x18];
    int m_nLimit;                                       // +0xbc
};
class Unk_CashLimitRowB : public CPtred
{
public:
    int FUN_1406a09c0();
    char m_pad[0x8c - 0x18];
    int m_nLimit;                                       // +0x8c
    char m_pad2[0xa8 - 0x90];
    int m_nProductId;                                   // +0xa8
};

// Message boxes, system messages and the string table.
void FUN_141275260(int, int, int);
void FUN_141275460(int, int, int, const fmt::ArgList&);
void FUN_140d73bc0(int nTable, int nId, void* pListener, CStringW strExtra);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nId, void* pListener, CStringW strExtra);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
CStringW FUN_14052bd00(int nId, const CStringW& strArg);
void FUN_141276180(const CString&, const CString&);
void FUN_141a02750(CMsgBoxData* pBox, int n);
void FUN_141a01c30(CMsgBoxData* pBox, const CString& strSound);
CStringW GetStringCommon(int nId);                        // string table text by id
void FUN_140710590(COutPacket& packet);                 // send the packet

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

CashInventoryBag* FUN_140b05ac0(NotifyContext::BindData* p);
UIMarketBillDialog* FUN_140b09580(int nClass);

// fmt message wrappers (same shape as itembreakmanager.cpp's Unk_BreakMessage).
enum Unk_CashResult : int {};
template<class A,class B> inline void Unk_CashMessage(int id, int a, int b, const A& x, const B& y) {
    const fmt::internal::ArgArray<2>::Type values={fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(x),fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(y)};
    FUN_141275460(id,a,b,fmt::ArgList(fmt::internal::make_type(x,y),values));
}
template<class A> inline void Unk_CashMessage(int id, int a, int b, const A& x) {
    const fmt::internal::ArgArray<1>::Type values={fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(x)};
    FUN_141275460(id,a,b,fmt::ArgList(fmt::internal::make_type(x),values));
}
// @0x140b09620
template <> inline void fmt::format_arg(BasicFormatter<wchar_t>& f, const wchar_t*& format_str, const Unk_CashResult& value)
{
    internal::Arg arg;
    internal::Value& arg_value = arg;
    if (std::is_enum<Unk_CashResult>::value)
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

// @0x1400c6cf0
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CashInventoryBag);

// Header-defined statics (same in every obj that includes the shared header).
#include "ms2/placeholder/header_statics_a.h"

static CStringW s_strUnlockCash(L"unlockcash");                                                     // 0x1400c6e80
static CString s_strBuy8Sort[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;                                                // 0x1400c7040
static CString s_strCashInventoryToBag("cash_InventorytoBag");                                      // 0x1400c7070
static CString s_strCashBuy("cash_Buy");                                                            // 0x1400c70a0

// @0x1400c70d0
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CashInventorySlot);

// Second and third copy of the header statics.
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames4[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_3(17, 0.75f, 0.25f, 2.25f, 10);

// @0x140b055c0
void FUN_140b055c0(const CString& strName, int nType)
{
    CashInventoryBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) CashInventoryBag(strName, nType);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(0x1e);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140b05680
void FUN_140b05680(const CString& strName)
{
    CashInventoryBag* pBag = FUN_140b05ac0(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x140b056d0
CashInventoryBag::CashInventoryBag(const CString& strName, int nType)
    : DragSlotBag(strName), m_nType(nType)
{
}

// @0x140b05720
CashInventoryBag::~CashInventoryBag()
{
}

// @0x140b05750
CString CashInventoryBag::vfunc_15(int nIndex)
{
    return DragSlotBag::vfunc_15(nIndex);
}

// @0x140b057a0
DragSlot* CashInventoryBag::vfunc_16(int nIndex)
{
    MS2Ptr<CItem> spUnused(0);
    const ATL::CAtlArray<MS2Ptr<CCashInventoryProduct> >& aInv = CCashMarketMan::GetInstance()->FUN_140b05c00();
    if ((size_t)nIndex < aInv.GetCount())
    {
        if (aInv[nIndex].get() != 0)
        {
            Unk_CashShopRef ref(FUN_140b04f80(0x4ebc));
            if (ref.FUN_140b051c0() != 0)
            {
                int nProductId = aInv[nIndex]->m_n1c;
                int nType = FUN_141034dc0(ref.FUN_140b051d0(), nProductId);
                CashInventorySlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) CashInventorySlot(vfunc_15(nIndex), nProductId, nType, nIndex);
                return pSlot;
            }
        }
    }
    CashInventorySlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) CashInventorySlot(vfunc_15(nIndex), 0, 0, nIndex);
    return pSlot;
}

// @0x140b05ac0
CashInventoryBag* FUN_140b05ac0(NotifyContext::BindData* p)
{
    CashInventoryBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200061, (void**)&pBag))
        return pBag;
    else
        return 0;
}

// @0x140b05d20 (TypeCast, GetClassDesc, SetupClassInfo: EE_DECLARE_CLASS1 in the header)

// @0x140b05e40
CCashMarketMan::CCashMarketMan()
    : m_nPage(0), m_bFlag(true), m_mapLimit(10)
{
}

// @0x140b05f20
CCashMarketMan::~CCashMarketMan()
{
    m_mapSale.RemoveAll();
    m_aSale.RemoveAll();
    m_aInv.RemoveAll();
}

// @0x140b06000
bool CCashMarketMan::GetFlag() const
{
    return m_bFlag;
}

// @0x140b06020
void CCashMarketMan::OnCash(CInPacket& packet)
{
    char cSub = packet.vfunc_o8_1();
    if (cSub == 0)
        FUN_140b07120(packet);
    else if (cSub == 1)
        FUN_140b072d0(packet);
    else if (cSub == 2)
        FUN_140b07490(packet);
    else if (cSub == 3)
        FUN_140b07cb0(packet);
    else if (cSub == 5)
        FUN_140b08760(packet);
    else if (cSub == 7)
        FUN_140b08ab0(packet);
    else if (cSub == 4)
        FUN_140b084f0(packet);
    else if (cSub == 9)
        FUN_140b08ee0(packet);
    else if (cSub == 8)
        FUN_140b08f50(packet);
    else if (cSub == -0x37)
        FUN_140b06bd0(packet);
    else if (cSub == -0x36)
        FUN_140b06d70(packet);
}

// @0x140b06180
void CCashMarketMan::SendCashMode0()
{
    COutPacket packet(static_cast<int>(SendOp::Cash), 0);
    packet.vfunc_o10_1(0);
    FUN_140710590(packet);
}

// @0x140b061e0
void CCashMarketMan::SendCashMode1()
{
    COutPacket packet(static_cast<int>(SendOp::Cash), 0);
    packet.vfunc_o10_1(1);
    FUN_140710590(packet);
}

// @0x140b06240
void CCashMarketMan::SendCashMode2(int a, int b)
{
    COutPacket packet(static_cast<int>(SendOp::Cash), 0);
    packet.vfunc_o10_1(2);
    packet.vfunc_o10_3(a);
    packet.vfunc_o10_3(b);
    FUN_140710590(packet);
}

// @0x140b062c0
void CCashMarketMan::SendCashMode3(int a, int b, CString s1, CString s2)
{
    if (FUN_1401d5a60() != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Cash), 0);
        packet.vfunc_o10_1(3);
        packet.vfunc_o10_3(a);
        packet.vfunc_o10_3(b);
        packet.vfunc_o10_6(s1);
        packet.vfunc_o10_6(s2);
        FUN_140710590(packet);
    }
}

// @0x140b063b0
void CCashMarketMan::SendCashMode4(int a, int b, int c)
{
    if (FUN_1401d5ab0() != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Cash), 0);
        packet.vfunc_o10_1(4);
        packet.vfunc_o10_3(a);
        packet.vfunc_o10_3(b);
        packet.vfunc_o10_3(c);
        FUN_140710590(packet);
    }
}

// @0x140b06450
void CCashMarketMan::SendCashMode5(int a)
{
    COutPacket packet(static_cast<int>(SendOp::Cash), 0);
    packet.vfunc_o10_1(5);
    packet.vfunc_o10_3(a);
    FUN_140710590(packet);
}

// @0x140b064c0
void CCashMarketMan::SendCashMode7(int a, int b, int c, int nFlag)
{
    if (nFlag != 1 || FUN_1401d5b00() != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Cash), 0);
        packet.vfunc_o10_1(7);
        packet.vfunc_o10_3(a);
        packet.vfunc_o10_3(b);
        packet.vfunc_o10_3(c);
        packet.vfunc_o10_1((unsigned char)nFlag);
        FUN_140710590(packet);
    }
}

// @0x140b06580
void CCashMarketMan::SendCashMode6(int a, int b)
{
    COutPacket packet(static_cast<int>(SendOp::Cash), 0);
    packet.vfunc_o10_1(6);
    packet.vfunc_o10_3(a);
    packet.vfunc_o10_3(b);
    FUN_140710590(packet);
}

// @0x140b06600
int CCashMarketMan::FUN_140b06600(int nId)
{
    MS2Ptr<CCashSaleProduct> spSale = FUN_140b06750(nId);
    return FUN_140b06680(spSale);
}

// @0x140b06680
int CCashMarketMan::FUN_140b06680(MS2Ptr<CCashSaleProduct> spSale)
{
    if (!spSale)
        return 0x6d;
    __int64 nNow = FUN_140869440();
    if (nNow < spSale->m_data.m_n60)
        return 0x6a;
    if (nNow >= spSale->m_data.m_n68)
        return 0x6a;
    return 0;
}

// @0x140b06750
MS2Ptr<CCashSaleProduct> CCashMarketMan::FUN_140b06750(int nId)
{
    MS2Ptr<CCashSaleProduct> spSale(0);
    m_mapSale.Lookup(nId, spSale);
    return spSale;
}

// @0x140b067d0
MS2Ptr<CCashInventoryProduct> CCashMarketMan::FUN_140b067d0(int nIndex)
{
    if (-1 < nIndex && nIndex < (int)m_aInv.GetCount())
        return m_aInv[nIndex];
    return MS2Ptr<CCashInventoryProduct>(0);
}

// @0x140b06870
MS2Ptr<CCashInventoryProduct> CCashMarketMan::FUN_140b06870(int a, int b)
{
    for (size_t i = 0; i < m_aInv.GetCount(); ++i)
    {
        MS2Ptr<CCashInventoryProduct> sp = m_aInv[i];
        if (sp->m_n1c == a && sp->m_n18 == b)
            return sp;
    }
    return MS2Ptr<CCashInventoryProduct>(0);
}

// @0x140b06980
void CCashMarketMan::FUN_140b06980(int nByte, int nResult)
{
    int nId = 0;
    switch (nResult)
    {
    case 2:
    case 0x65:
        nId = 0xa6b;
        break;
    case 0x66:
        nId = 0xa6c;
        break;
    case 0x67:
        nId = 0xa6d;
        break;
    case 0x68:
        nId = 0xa6e;
        break;
    case 0x69:
        nId = 0xa6f;
        break;
    case 0x6a:
        nId = 0xa71;
        break;
    case 0x6b:
        nId = 0xa72;
        break;
    case 0x6c:
        nId = 0xa73;
        break;
    case 0x6d:
        nId = 0xa74;
        break;
    case 0x6e:
        nId = 0xa75;
        break;
    case 0x6f:
        nId = 0xa76;
        break;
    case 0x70:
        nId = 0xa7d;
        break;
    case 0x73:
        nId = 0xa48;
        break;
    case 0x74:
        nId = 0xa48;
        break;
    case 0x75:
        nId = 0xd56;
        break;
    case 0x76:
        nId = 0xa70;
    }
    if (nId == 0)
        Unk_CashMessage(0xa68, 1, 1, nByte, (Unk_CashResult)nResult);
    else if (nId == 0xa6b)
        FUN_141275260(0xa6b, 1, 1);
    else
        FUN_140d73bc0(nId, 0, 0, CStringW(L""));
}

// @0x140b06bd0
void CCashMarketMan::FUN_140b06bd0(CInPacket& packet)
{
    Unk_LockGuard guard(m_lock);
    if ((int)guard == 0)
    {
        m_mapLimit.RemoveAll();
        int nCount = packet.vfunc_o8_3();
        for (int i = 0; i < nCount; ++i)
        {
            if (packet.vfunc_o8_1() != 0)
            {
                MS2Ptr<CMarketBuyLimitHistory> sp(new CMarketBuyLimitHistory);
                sp->Read(packet);
                m_mapLimit.SetAt(sp->m_n2c, sp);
            }
        }
    }
}

// @0x140b06d70
void CCashMarketMan::FUN_140b06d70(CInPacket& packet)
{
    CDBMarketBuyLimitHistory row;
    row.Read(packet);
    MS2Ptr<CMarketBuyLimitHistory> sp(0);
    Unk_LockGuard guard(m_lock);
    if ((int)guard != 0)
    {
    }
    else
    {
        m_mapLimit.Lookup(row.m_n2c, sp);
        if (sp == 0)
        {
            sp.AssignRaw(new CMarketBuyLimitHistory(&row));
            m_mapLimit.SetAt(row.m_n2c, sp);
        }
        sp->Merge(&row);
    }
}

// @0x140b06ed0
int CCashMarketMan::FUN_140b06ed0(int nProductId)
{
    MS2Ptr<CMarketBuyLimitHistory> sp(0);
    int nCount = 0;
    Unk_LockGuard guard(m_lock);
    if ((int)guard == 0)
    {
        m_mapLimit.Lookup(nProductId, sp);
        if (sp.get() != 0)
            nCount = sp->m_n30;
    }
    return nCount;
}

// @0x140b06f90
bool CCashMarketMan::FUN_140b06f90(MS2Ptr<Unk_CashLimitRowA> sp)
{
    if (sp == 0 || sp->FUN_1406a4370() == 0)
        return false;
    return FUN_140b06ed0(sp->FUN_1406a4640()) >= sp->m_nLimit;
}

// @0x140b07060
bool CCashMarketMan::FUN_140b07060(MS2Ptr<Unk_CashLimitRowB> sp)
{
    if (sp == 0 || sp->FUN_1406a09c0() == 0)
        return false;
    return FUN_140b06ed0(sp->m_nProductId) >= sp->m_nLimit;
}

// @0x140b07120
void CCashMarketMan::FUN_140b07120(CInPacket& packet)
{
    m_mapSale.RemoveAll();
    m_aSale.RemoveAll();
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; ++i)
    {
        MS2Ptr<CCashSaleProduct> sp(new CCashSaleProduct);
        sp->Read(reinterpret_cast<Unk_CashReader&>(packet));
        m_mapSale.SetAt(sp->m_n18, sp);
        m_aSale.Add(sp);
    }
    if (FUN_140166410()->FUN_14036e4c0())
    {
        Unk_CashShopRef ref(FUN_140b04f80(0x4ebc));
        if (ref.FUN_140b051c0() != 0)
            FUN_141035050(ref.FUN_140b051d0());
    }
}

// @0x140b072d0
void CCashMarketMan::FUN_140b072d0(CInPacket& packet)
{
    int nCode = packet.vfunc_o8_3();
    int nArg = packet.vfunc_o8_3();
    if (nCode == 1)
    {
        if (FUN_140166410()->FUN_14036e4c0())
        {
            Unk_CashShopRef ref(FUN_140b04f80(0x4ebc));
            if (ref.FUN_140b051c0() != 0)
                FUN_141034e00(ref.FUN_140b051d0(), nArg);
        }
    }
    else if (nCode == 0xff)
        FUN_141275260(0xa7a, 1, 1);
    else if (nCode == 0x2ee1)
        FUN_140d73bc0(0xa79, 0, 0, CStringW(L""));
    else if (nCode == 0x2ee2)
        FUN_140d73bc0(0xa7b, 0, 0, CStringW(L""));
    else
        Unk_CashMessage(0xa78, 1, 1, nCode);
}

// @0x140b07490
void CCashMarketMan::FUN_140b07490(CInPacket& packet)
{
    int nCode = packet.vfunc_o8_3();
    if (nCode == 1)
    {
        int nArg = packet.vfunc_o8_3();
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0, 0x9e0, 0, CStringW(L""));
        if (spBox.get() != 0)
            FUN_141a01c30(spBox.operator->(), s_strCashBuy);
        spBox = 0;
        if (!FUN_140166410()->FUN_14036e4c0())
            return;
        Unk_CashShopRef ref(FUN_140b04f80(0x4ebc));
        if (ref.FUN_140b051c0() != 0)
        {
            if (FUN_1410356a0(ref.FUN_140b051d0()) == 0)
                FUN_140d73bc0(0xa60, 0, 0, CStringW(L""));
            FUN_141034ef0(ref.FUN_140b051d0(), nArg, packet);
        }
        FUN_141276180(s_strCashBuy, CString(""));
        return;
    }
    if (nCode < 0x2afa)
    {
        if (nCode == 0x2af9)
        {
            FUN_140d73bc0(0xa84, 0, 0, CStringW(L""));
            return;
        }
        switch (nCode)
        {
        case 3:
            FUN_140d73bc0(0xa7d, 0, 0, CStringW(L""));
            break;
        case 4:
            FUN_140d73bc0(0xa7e, 0, 0, CStringW(L""));
            break;
        default:
            goto defaultMessage;
        case 0x16:
            FUN_140d73bc0(0xa7f, 0, 0, CStringW(L""));
            break;
        case 0x1a:
            FUN_140d73bc0(0xa80, 0, 0, CStringW(L""));
            break;
        case 0x1e:
            FUN_140d73bc0(0xa81, 0, 0, CStringW(L""));
            break;
        case 0x1f:
            FUN_140d73bc0(0xa82, 0, 0, CStringW(L""));
            break;
        case 0xff:
            FUN_141275260(0xa83, 1, 1);
        }
    }
    else
    {
        if (nCode < 0x2f09)
        {
            if (nCode == 0x2f08)
            {
                FUN_140d73bc0(0xa88, 0, 0, CStringW(L""));
                return;
            }
            if (nCode == 0x2afa)
            {
                FUN_140d73bc0(0xa85, 1, 0, CStringW(s_strUnlockCash));
                return;
            }
            if (nCode == 0x2ee1)
            {
                FUN_140d73bc0(0xa86, 0, 0, CStringW(L""));
                return;
            }
            if (nCode == 0x2ee2)
            {
                FUN_140d73bc0(0xa87, 0, 0, CStringW(L""));
                return;
            }
        }
        else
        {
            if (nCode == 0x2f0c)
            {
                FUN_140d73bc0(0xa89, 0, 0, CStringW(L""));
                return;
            }
            if (nCode == 0x1d4eb)
            {
                FUN_140d73bc0(0xa8a, 0, 0, CStringW(L""));
                return;
            }
            if (nCode == 0x1d4fe)
            {
                FUN_140d73bc0(0xa8b, 0, 0, CStringW(L""));
                return;
            }
        }
defaultMessage:
        Unk_CashMessage(0xa7c, 1, 1, nCode);
    }
}

// @0x140b07cb0
void CCashMarketMan::FUN_140b07cb0(CInPacket& packet)
{
    int nCode = packet.vfunc_o8_3();
    CStringW strArg = packet.vfunc_o8_8();
    if (nCode == 1)
    {
        MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(0));
        if (spBox.get() != 0)
        {
            spBox->SetMsg(FUN_14052bd00(0xa63, strArg));
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &CCashMarketMan::FUN_140b08fe0));
            FUN_140d73c60(spBox);
        }
        return;
    }
    if (nCode < 0x3eb)
    {
        if (nCode == 0x3ea)
        {
            FUN_140d73bc0(0xa99, 0, 0, CStringW(L""));
            return;
        }
        if (nCode < 0x1f)
        {
            if (nCode == 0x1e)
            {
                FUN_140d73bc0(0xa81, 0, 0, CStringW(L""));
                return;
            }
            if (nCode == 3)
            {
                FUN_140d73bc0(0xa7d, 0, 0, CStringW(L""));
                return;
            }
            if (nCode == 4)
            {
                FUN_140d73bc0(0xa9c, 0, 0, CStringW(L""));
                return;
            }
            if (nCode == 0x16)
            {
                FUN_140d73bc0(0xa7f, 0, 0, CStringW(L""));
                return;
            }
            if (nCode == 0x1a)
            {
                FUN_140d73bc0(0xa80, 0, 0, CStringW(L""));
                return;
            }
        }
        else
        {
            if (nCode == 0x1f)
            {
                FUN_140d73bc0(0xa82, 0, 0, CStringW(L""));
                return;
            }
            if (nCode == 0xff)
            {
                FUN_141275260(0xa83, 1, 1);
                return;
            }
            if (nCode == 1000)
            {
                FUN_140d73bc0(0xa97, 0, 0, CStringW(L""));
                return;
            }
            if (nCode == 0x3e9)
            {
                FUN_140d73bc0(0xa98, 0, 0, CStringW(L""));
                return;
            }
        }
    }
    else if (nCode < 0x2f09)
    {
        if (nCode == 0x2f08)
        {
            FUN_140d73bc0(0xa88, 0, 0, CStringW(L""));
            return;
        }
        if (nCode == 0x3eb)
        {
            FUN_140d73bc0(0xa9a, 0, 0, CStringW(L""));
            return;
        }
        if (nCode == 0x2afa)
        {
            FUN_140d73bc0(0xa85, 1, 0, CStringW(s_strUnlockCash));
            return;
        }
        if (nCode == 0x2ee1)
        {
            FUN_140d73bc0(0xa86, 0, 0, CStringW(L""));
            return;
        }
        if (nCode == 0x2ee2)
        {
            FUN_140d73bc0(0xa87, 0, 0, CStringW(L""));
            return;
        }
    }
    else
    {
        if (nCode == 0x2f0c)
        {
            FUN_140d73bc0(0xa89, 0, 0, CStringW(L""));
            return;
        }
        if (nCode == 0x1d4eb)
        {
            FUN_140d73bc0(0xa8a, 0, 0, CStringW(L""));
            return;
        }
        if (nCode == 0x1d4fe)
        {
            FUN_140d73bc0(0xa8b, 0, 0, CStringW(L""));
            return;
        }
    }
    Unk_CashMessage(0xa9b, 1, 1, nCode);
}

// @0x140b084f0
void CCashMarketMan::FUN_140b084f0(CInPacket& packet)
{
    int nCode = packet.vfunc_o8_3();
    if (nCode == 1)
    {
        int n1 = packet.vfunc_o8_3();
        int n2 = packet.vfunc_o8_3();
        int n3 = packet.vfunc_o8_3();
        FUN_140d73bc0(0xa64, 0, 0, CStringW(L""));
    }
    else if (nCode == 2)
        FUN_140d73bc0(0xa93, 0, 0, CStringW(L""));
    else if (nCode == 4)
        FUN_140d73bc0(0xa94, 0, 0, CStringW(L""));
    else if (nCode == 7)
        FUN_140d73bc0(0xa95, 0, 0, CStringW(L""));
    else if (nCode == 8)
        FUN_140d73bc0(0xa96, 0, 0, CStringW(L""));
    else
        Unk_CashMessage(0xa92, 1, 1, nCode);
}

// @0x140b08760
void CCashMarketMan::FUN_140b08760(CInPacket& packet)
{
    int nCode = packet.vfunc_o8_3();
    if (nCode == 1)
    {
        int nPage = packet.vfunc_o8_3();
        int nCount = packet.vfunc_o8_3();
        m_aInv.RemoveAll();
        m_aInv.SetCount(nCount, -1);
        int nIndexBase = 0;
        for (int i = 0; i < nCount; ++i)
        {
            MS2Ptr<CCashInventoryProduct> sp(new CCashInventoryProduct);
            sp->Read(reinterpret_cast<Unk_CashReader&>(packet));
            nIndexBase = (nPage - 1) * 0x1e + i;
            m_aInv[i] = sp;
        }
        if (FUN_140166410()->FUN_14036e4c0())
        {
            Unk_CashShopRef ref(FUN_140b04f80(0x4ebc));
            if (ref.FUN_140b051c0() != 0)
                FUN_141035080(ref.FUN_140b051d0(), nPage);
        }
        m_nPage = nPage;
        if (m_aInv.GetCount() > 0 && FUN_1401d5b00() == 1)
        {
            MS2Ptr<CCashInventoryProduct> spFirst = m_aInv[0];
            if (spFirst.get() != 0)
                SendCashMode7(spFirst->m_n1c, spFirst->m_n18, 1, 1);
        }
    }
    else
    {
        switch (nCode)
        {
        case 0xff:
            FUN_141275260(0xa8d, 1, 1);
            break;
        default:
            Unk_CashMessage(0xa8c, 1, 1, nCode);
        }
    }
}

// @0x140b08ab0
void CCashMarketMan::FUN_140b08ab0(CInPacket& packet)
{
    int nCode = packet.vfunc_o8_3();
    if (nCode == 1)
    {
        int nA = packet.vfunc_o8_3();
        int nB = packet.vfunc_o8_3();
        int nC = packet.vfunc_o8_3();
        unsigned nD = packet.vfunc_o8_3();
        if (!FUN_140166410()->FUN_14036e4c0())
        {
            if (FUN_140166410()->FUN_14036e5b0())
            {
                if (nD < 900000 || 999999 < nD)
                    FUN_140d73bc0(0xa60, 0, 0, CStringW(L""));
                else
                    FUN_140d73bc0(0xa61, 0, 0, CStringW(L""));
                FUN_141276180(s_strCashBuy, CString(""));
            }
        }
        else
        {
            FUN_140d73bc0(0xa65, 0, 0, CStringW(L""));
            FUN_141276180(s_strCashInventoryToBag, CString(""));
        }
        MS2Ptr<CCashInventoryProduct> spProd = GetInstance()->FUN_140b06870(nA, nB);
        if (spProd.get() != 0)
        {
            int nItemId = spProd->m_data.m_n28;
            MS2Ptr<Unk_CashItemData> spData = FUN_14053f870(nItemId);
            if (spData.get() != 0)
            {
                if (FUN_14053c6b0(spData.get(), 0x13))
                    FUN_1418fe1c0(FUN_140298f80((char*)FUN_1401d3200() + 0xdaa0));
            }
        }
    }
    else if (nCode == 2)
        FUN_140d73bc0(0xa8f, 0, 0, CStringW(L""));
    else if (nCode == 3)
        FUN_140d73bc0(0xa90, 0, 0, CStringW(L""));
    else if (nCode == 0xff)
        FUN_141275260(0xa91, 1, 1);
    else
        Unk_CashMessage(0xa8e, 1, 1, nCode);
}

// @0x140b08ee0
void CCashMarketMan::FUN_140b08ee0(CInPacket& packet)
{
    m_bFlag = packet.vfunc_o8_1() == 1;
}

// @0x140b08f50
void CCashMarketMan::FUN_140b08f50(CInPacket& packet)
{
    int nByte = packet.vfunc_o8_1();
    int nResult = packet.vfunc_o8_3();
    FUN_140b06980(nByte, nResult);
    if (nResult == 0x70)
        SendCashMode0();
}

// @0x140b08fe0
bool CCashMarketMan::FUN_140b08fe0(int, const CMsgBoxData&)
{
    UIMarketBillDialog* pBill = FUN_140b09580(0x4f17);
    if (pBill != 0)
    {
        Unk_CashBillRef ref = pBill->FUN_140ea8da0();
        if (!ref.FUN_140a8e270(0))
        {
            if (ref.FUN_140a8e380()->m_nId == 0x4ebc)
                FUN_1403ed2b0()->FUN_141adc5d0(0x4f17);
        }
    }
    return true;
}

// @0x140b09580
UIMarketBillDialog* FUN_140b09580(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObj = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObj.get() != 0)
            return dynamic_cast<UIMarketBillDialog*>(spObj.operator->());
    }
    return 0;
}

// @0x140b0ceb0
CashInventorySlot::CashInventorySlot(const CString& strName, int nProductId, int nType, int nIndex)
    : MS2DragSlot(strName, nIndex), m_nProductId(nProductId), m_nType(nType)
{
    m_spItem = CashInventorySlot::vfunc_25();
}

// @0x140b0cf90
CashInventorySlot::~CashInventorySlot()
{
    m_spItem = 0;
}

// @0x140b0d010
int CashInventorySlot::vfunc_18(void* p)
{
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x140b0d040
int CashInventorySlot::vfunc_13()
{
    FUN_140b0d440();
    return 1;
}

// @0x140b0d070
int CashInventorySlot::vfunc_14()
{
    FUN_140b0d440();
    return 1;
}

// @0x140b0d0a0 (ITooltip::vfunc_0)
int CashInventorySlot::vfunc_0(void* p)
{
    ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), 0x20, 2);
    if (tip.FUN_1409e0d40(m_spItem.get()))
    {
        tip.FUN_1409c65f0(GetStringCommon(0xa5d));
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140b0d1a0
int CashInventorySlot::vfunc_8(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(m_spItem.get(), pPlayer, 1))
    {
        slot.FUN_1409c24f0(m_nType);
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140b0d290
MS2Ptr<CItem> CashInventorySlot::vfunc_25()
{
    MS2Ptr<CCashInventoryProduct> spProd = CCashMarketMan::GetInstance()->FUN_140b067d0(GetIndex());
    if (!spProd)
        return MS2Ptr<CItem>(0);
    MS2Ptr<CItem> spItem(new CItem);
    if (!spItem->FUN_140523c40(spProd->m_data.m_n28, spProd->m_data.m_n2c, 0))
        return MS2Ptr<CItem>(0);
    return spItem;
}

// @0x140b0d440
void CashInventorySlot::FUN_140b0d440()
{
    if (m_spItem.get() == 0)
        return;
    MS2Ptr<CCashInventoryProduct> spProd = CCashMarketMan::GetInstance()->FUN_140b067d0(GetIndex());
    if (!spProd)
        return;
    int nMsg = spProd->m_data.m_n50 == 0 ? 0xa56 : 0xa57;
    UICashShopDialog* pShop = FUN_140b04f80(0x4ebc);
    CStringW strPickup = StringFormat(L"pickup:{0},{1}", spProd->m_n1c, (const unsigned&)spProd->m_n18);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x1d, nMsg, pShop == 0 ? 0 : (void*)((char*)pShop + 0x18), CStringW(strPickup));
    if (spBox.get() != 0)
    {
        int bFlag = spProd->m_data.m_n50 != 0 && spProd->m_strA8.GetLength() == 0;
        FUN_141a02750(spBox.operator->(), bFlag);
        spBox->FUN_141a01ee0(m_spItem, m_spItem.get()->FUN_140527b10(), 1, 0, -1, -1, 1);
        spBox->FUN_141a01800(1);
        FUN_140d73c60(spBox);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca0610-0x142ca08a0 .text$yd
