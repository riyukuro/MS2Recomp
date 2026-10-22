// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PC bang (internet cafe) play-time bonus dialog.
// MS2-UNIT: ?\uipcbangdialog.cpp
// MS2-RANGE: 0x141322c00-0x14132ba80 .text$mn
// MS2-RANGE: 0x1400ef700-0x1400ef760 .text$di
// MS2-RANGE: 0x142caffc0-0x142cafff6 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strBuySound@@YAXXZ 0x1400ef700 ; probe
// MS2-PIN: ??__Es_strGiftSound@@YAXXZ 0x1400ef730 ; probe
// MS2-PIN: ??$?8PEAVUIPcBangDialog@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIPcBangDialog@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x141326ae0 ; prop
// MS2-PIN: ??$?8PEAVUIPcBangDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIPcBangDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x141326b50 ; prop
// MS2-PIN: ??$?8PEAVUIPcBangDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIPcBangDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x141326bc0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x1413287c0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x141328860 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x141328900 ; prop
// MS2-PIN: ?vfunc_48@UIPcBangDialog@@UEAAHXZ 0x1413298e0 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14132b3b0 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14132b410 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14132b470 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x14132b5e0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14132b610 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x14132b640 ; unique
// MS2-PIN: ??$Call@VUIPcBangDialog@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIPcBangDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x14132b670 ; prop
// MS2-PIN: ??$Call@VUIPcBangDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIPcBangDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14132b6b0 ; prop
// MS2-PIN: ??$Call@VUIPcBangDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIPcBangDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x14132b6f0 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14132b730 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14132b790 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIPcBangDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14132b7f0 ; unique
// MS2-PIN: ??__Fs_strBuySound@@YAXXZ 0x142caffc0 ; probe
// MS2-PIN: ??__Fs_strGiftSound@@YAXXZ 0x142caffe0 ; probe
// MS2-PINS-END tplpin
// File name assumed (the class name; the exe has no assert path for it). The TU ends with the CRT memmove_s copy at
// 0x14132b970; 0x14132ba90 (the "$s_myInfo_*" text helper) belongs to client\ms2\uipcinfodialog.cpp.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipcbangdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uipcbangdialog.h"
#include "uimessageboxdata.h"
#include "mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "pcbase.h"
#include "ms2/commonfiles/additionalactionadditional.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/skilldatatablecli.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>

template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);
template <> MS2Ptr<ASTextField> UISwfEntity::GetChild<ASTextField>(const CString& strName);

// ---- callees (instances in other units; declared with their real argument lists) ------------------------------------
NotifySystem* FUN_140939a10();
PacketHandlerManager* FUN_140bccd50();
CFeatureManager* FUN_140166410();
CStringTable* GetStringTable();
SkillDataTableCli* FUN_1401958b0();                            // TSingleton<SkillDataTableCli>::GetInstance
class Unk_PcBangWorld { public: PCBase* FUN_141bd0cc0(); };     // the world service: the local player
Unk_PcBangWorld* FUN_1403ed2d0();
unsigned FUN_141472bc0();                                       // the server clock (ms)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_141275a10(CItem* pItem);                                // the usable state (1 locked, 2 disabled, 3 condition)
void FUN_140710590(COutPacket& packet);                         // send
void ReadBits(Unk_PartyBits& bits, CInputStream& in);           // 0x14031c1f0 (bitset.inl stream helper)
bool FUN_140184310(const CString& str, const char* psz);        // str == psz
CString FUN_1402bb1c0(const char* szFormat, const int& n);      // StringFormat<int>
CString FUN_140513200(const char* szFormat, const unsigned& n); // StringFormat<unsigned>
CStringW FUN_1408116a0(int nId, const int& nArg);               // system text with one argument
CStringW FUN_140811740(int nId, const int& nArg1, const int& nArg2);
CStringW FUN_1409e97f0(int nId, const unsigned& nArg);          // string table entry, one argument
CStringW GetStringCommonByKey(const CStringW& strKey);                 // the localized text of a key
void FUN_1412751f0(const CStringW& strText, int nA, int nB);    // system chat notice
void FUN_141276180(const CString& strSound, const CString& strExtra);   // play a UI sound
void FUN_140d73bc0(int nStringId, int nType, void* pListener, CStringW strTag);   // pop a system message
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStringId, IMessageListener* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                  // show the message box
void FUN_1409e2ed0(Scaleform::GFx::Value* pRetVal, ItemAble& item);   // the tooltip of a reward item
void FUN_140d00360(const Scaleform::GFx::Value& root, CString strName, unsigned nItemId, unsigned nRank, unsigned nCount);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
void FUN_140cffa50(const Scaleform::GFx::Value& root, CString strName, CString strLabel);
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int nVisible);
void FUN_140d01340(const Scaleform::GFx::Value& target, unsigned nParam, int nMovieId);

// ASButton's click registration as this unit calls it: the user value goes as a qword (the row index, sign-extended).
class Unk_PcBangGetButton : public ASButton
{
public:
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onClick, __int64 nUser);
};

// The sounds of the dialog (dynamic initializers 0x1400ef700 / 0x1400ef730, atexit 0x142caffc0 / 0x142caffe0).
static CString s_strBuySound("cash_Buy");                       // 0x143ad7ae8
static CString s_strGiftSound("system_pcbang_gift{0}");         // 0x143ad7a98

// The number of set bits of the received-bonus set (bitset.inl count(), nibble table 0x1439f7540).
// @0x14132b4d0
inline unsigned CountBits(const Unk_Bitset8& bits)
{
    static const char s_nibbleBits[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
    int nCount = 0;
    for (int i = 0; i >= 0; i--)
        for (unsigned char c = bits.m_bits[i]; c != 0; c >>= 4)
            nCount += s_nibbleBits[c & 0xf];
    return nCount;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141322c00
UIPcBangDialog::UIPcBangDialog()
    : m_nState(0), m_nGrade(0), m_bGiftOrderDirty(0), m_nReceivable(0), m_playTimeTimer(30000),
      m_receivableTimer(10000), m_banner(3)
{
    FUN_141924170(1);
    FUN_141925e70(3, 1);
    FUN_140939a10()->RegisterNotify(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UIPcBangDialog::OnGameStart));
    FUN_140939a10()->RegisterNotify(L"NotifyChangeMyLevel", Delegate<void(NotifyObject*)>(this, &UIPcBangDialog::OnChangeMyLevel));
    FUN_140bccd50()->RegisterHandler(0xa5, Delegate<void(CInPacket&)>(this, &UIPcBangDialog::OnPacket));
    FUN_140bccd50()->RegisterHandler(0x10b, Delegate<void(CInPacket&)>(this, &UIPcBangDialog::OnResetBonus));
}

// @0x1413230d0
UIPcBangDialog::~UIPcBangDialog()
{
    FUN_140939a10()->UnregisterNotify(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UIPcBangDialog::OnGameStart));
    FUN_140939a10()->UnregisterNotify(L"NotifyChangeMyLevel", Delegate<void(NotifyObject*)>(this, &UIPcBangDialog::OnChangeMyLevel));
    FUN_140bccd50()->UnregisterHandler(0xa5, Delegate<void(CInPacket&)>(this, &UIPcBangDialog::OnPacket));
    FUN_140bccd50()->UnregisterHandler(0x10b, Delegate<void(CInPacket&)>(this, &UIPcBangDialog::OnResetBonus));
}

// @0x141323490
CString UIPcBangDialog::GetTypeName() { return "PcBangDialog"; }
MS2_REPLACE_METHOD(0x141323490, UIPcBangDialog, GetTypeName, 61, 0x332B1B09);

// @0x1413234e0
void UIPcBangDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    for (int i = 0; i < 6; i++)
    {
        MS2Ptr<ASMovieClip> spRow = m_30->FUN_1409b4560(FUN_1402bb1c0("m_timeBonus{0}", i));
        if (spRow == 0)
            break;
        MS2Ptr<ASButton> spButton = spRow->FUN_140acce30<ASButton>("itemGetButton");
        if (spButton == 0)
            break;
        static_cast<Unk_PcBangGetButton*>(spButton.operator->())->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIPcBangDialog::OnClickItemGet), i);
        m_getButtons.Add(spButton);
        m_rows.Add(spRow);
    }
    m_spGiftList = FUN_140ba4b70("m_giftList");
    m_spBanner = GetChild<ASMovieClip>("m_banner");
    m_spBanner->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIPcBangDialog::OnClickBanner), 0);
    m_banner.LoadBanner();
    RebuildGiftOrder();
    RefreshAll();
    RequestInfo();
}
MS2_REPLACE_METHOD(0x1413234E0, UIPcBangDialog, OnLoadInit, 1058, 0x9669BC69);

// @0x141323910
void UIPcBangDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_getButtons.RemoveAll();
    m_rows.RemoveAll();
    m_spGiftList = 0;
    m_spBanner = 0;
    m_strBanner.Empty();
}
MS2_REPLACE_METHOD(0x141323910, UIPcBangDialog, vfunc_26, 124, 0x21BE2C1D);

// @0x1413239a0
void UIPcBangDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    CString strType = pArgs->FUN_1422b8d30();
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (FUN_140184310(strType, "giftItem"))
    {
        unsigned nGiftId = pArgs->FUN_1422b8b10();
        MS2Ptr<ItemGiftPcBang> spGift;
        if (!m_gifts.Lookup(nGiftId, spGift))
            return;
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b130(spGift->m_itemId, spGift->vfunc_o18_1(), 0) != 0)
        {
            spItem->FUN_140526c70(spGift->m_count);
            MS2Ptr<CItem> spWorn = static_cast<MyPC*>(pPlayer)->FUN_14152e2f0(spItem);
            ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), 4, 2);
            if (tip.FUN_1409e13a0(spWorn.get(), spItem.get()) != 0)
                *pRetVal = tip.FUN_1422bb870();
        }
    }
    else if (FUN_140184310(strType, "playGift"))
    {
        unsigned nIndex = pArgs->FUN_1422b8b10();
        if (nIndex >= m_playBonus.GetCount())
            return;
        MS2Ptr<PlayBonusItemGift> spBonus = m_playBonus[nIndex];
        FUN_1409e2ed0(pRetVal, *spBonus);
    }
}
MS2_REPLACE_METHOD(0x1413239A0, UIPcBangDialog, vfunc_49, 941, 0xBB590DFD);

// @0x141323d60
void UIPcBangDialog::vfunc_72()
{
    if (FUN_1422dc2d0())
    {
        if (m_banner.TakeReady())
            UpdateBanner();
        if (IsPcBang())
        {
            if (m_playTimeTimer.FUN_140268870(0))
            {
                UpdatePlayTime();
                UpdateProgress();
            }
        }
    }
    if (IsPcBang())
    {
        if (m_receivableTimer.FUN_140268870(0))
            UpdateReceivable();
    }
}
MS2_REPLACE_METHOD(0x141323D60, UIPcBangDialog, vfunc_72, 172, 0xFE4015C0);

// @0x141323e20
int UIPcBangDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onClickReceive") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nIndex = data.FUN_1422b8b10();
            COutPacket packet(static_cast<int>(SendOp::PcBangBonus), 0);
            packet.vfunc_o10_1(2);
            packet.vfunc_o10_3(nIndex);
            FUN_140710590(packet);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141323E20, UIPcBangDialog, vfunc_28, 280, 0x00357DA8);

// @0x141323f40
void UIPcBangDialog::OnPacket(CInPacket& packet)
{
    int nCode = packet.vfunc_o8_1();
    switch (nCode)
    {
    case 0: OnPacketInfo(packet); break;
    case 1: OnPacketPlayed(packet); break;
    case 2: OnPacketReward(packet); break;
    case 3: OnPacketStatus(packet); break;
    case 5: OnPacketNotice(packet); break;
    }
}
MS2_REPLACE_METHOD(0x141323F40, UIPcBangDialog, OnPacket, 188, 0xF2997A0E);

// @0x141324010
void UIPcBangDialog::OnPacketInfo(CInPacket& packet)
{
    ResetInfo();
    if (!FUN_140166410()->FUN_14036d570(0x3c))
        return;
    m_nGrade = packet.vfunc_o8_1();
    m_nStartTime = packet.vfunc_o8_3();
    m_nPlayTime = packet.vfunc_o8_3();
    ReadBits(m_received, packet);
    m_nBuffId = packet.vfunc_o8_3();
    int nBonus = packet.vfunc_o8_3();
    for (int i = 0; i < nBonus; i++)
    {
        MS2Ptr<PlayBonusItemGift> spBonus(new PlayBonusItemGift());
        spBonus->vfunc_6(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_playBonus.Add(spBonus);
    }
    int nGifts = packet.vfunc_o8_3();
    for (int j = 0; j < nGifts; j++)
    {
        MS2Ptr<ItemGiftPcBang> spGift(new ItemGiftPcBang());
        spGift->vfunc_6(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_gifts.SetAt(spGift->m_giftId, spGift);
    }
    int bShow = packet.vfunc_o8_1();
    RebuildGiftOrder();
    m_nState = 1;
    FUN_140939a10()->Post(MS2Ptr<NotifyObject>(new NotifyPcBang()));
    if (FUN_141924630())
        RefreshAll();
    else if (bShow)
        FUN_141924680();
}
MS2_REPLACE_METHOD(0x141324010, UIPcBangDialog, OnPacketInfo, 1199, 0xB392450C);

// @0x1413244d0
void UIPcBangDialog::OnPacketPlayed(CInPacket& packet)
{
    unsigned nIndex = packet.vfunc_o8_1();
    ReadBits(m_received, packet);
    UpdateProgress();
    m_nReceivable = CountReachedBonus() - CountBits(m_received);
    FUN_140939a10()->Post(MS2Ptr<NotifyObject>(new NotifyPcBang()));
    if (nIndex >= m_playBonus.GetCount())
        return;
    FUN_141276180(FUN_140513200(s_strGiftSound, nIndex), "");
}
MS2_REPLACE_METHOD(0x1413244D0, UIPcBangDialog, OnPacketPlayed, 463, 0xC1B82850);

// @0x1413246b0
void UIPcBangDialog::OnPacketReward(CInPacket& packet)
{
    unsigned nGiftId = packet.vfunc_o8_3();
    MS2Ptr<ItemGiftPcBang> spGift;
    if (!m_gifts.Lookup(nGiftId, spGift))
        return;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x11, 0xad4, 0, L"");
    if (spBox.get() != 0)
    {
        MS2Ptr<CItem> spItem(new CItem());
        if (!spItem->FUN_140523c40(spGift->m_itemId, spGift->vfunc_o18_1(), 0))
            return;
        spItem->FUN_140526c70(spGift->m_count);
        spBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
        spBox->FUN_141a01700(0x475, 0, 0);
        FUN_140d73c60(spBox);
        FUN_141276180(s_strBuySound, "");
    }
}
MS2_REPLACE_METHOD(0x1413246B0, UIPcBangDialog, OnPacketReward, 909, 0xC06E72E2);

// @0x141324a50
void UIPcBangDialog::OnPacketStatus(CInPacket& packet)
{
    m_nGrade = packet.vfunc_o8_1();
    m_nStartTime = packet.vfunc_o8_3();
    m_nPlayTime = packet.vfunc_o8_3();
    ReadBits(m_received, packet);
    if (FUN_1422dc2d0())
    {
        UpdatePlayTime();
        UpdatePcBangFlag();
        UpdateProgress();
    }
}
MS2_REPLACE_METHOD(0x141324A50, UIPcBangDialog, OnPacketStatus, 227, 0xC48C7838);

// @0x141324b40
void UIPcBangDialog::OnPacketNotice(CInPacket& packet)
{
    int nCode = packet.vfunc_o8_1();
    switch (nCode)
    {
    case 1: FUN_140d73bc0(0xad3, 0, 0, L""); break;
    case 4: FUN_140d73bc0(0xad2, 0, 0, L""); break;
    }
}
MS2_REPLACE_METHOD(0x141324B40, UIPcBangDialog, OnPacketNotice, 192, 0xCF468095);

// @0x141324c10
void UIPcBangDialog::OnResetBonus(CInPacket& packet)
{
    FUN_1412751f0(GetStringCommonByKey(L"s_pcbang_msg_reset_bonus"), 1, 1);
    if (FUN_141924630())
    {
        COutPacket packet(static_cast<int>(SendOp::PcBangBonus), 0);
        packet.vfunc_o10_1(0);
        packet.vfunc_o10_1(0);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x141324C10, UIPcBangDialog, OnResetBonus, 209, 0x308DC8F2);

// @0x141324cf0
void UIPcBangDialog::OnGameStart(NotifyObject* pNotify) { ResetInfo(); }
MS2_REPLACE_METHOD(0x141324CF0, UIPcBangDialog, OnGameStart, 29, 0x14914E06);

// @0x141324d20
void UIPcBangDialog::OnChangeMyLevel(NotifyObject* pNotify)
{
    m_bGiftOrderDirty = 1;
    if (FUN_141924630())
        RefreshGiftList();
}
MS2_REPLACE_METHOD(0x141324D20, UIPcBangDialog, OnChangeMyLevel, 58, 0xC53F4AA3);

// @0x141324d60
int UIPcBangDialog::GetState() { return m_nState; }
MS2_REPLACE_METHOD(0x141324D60, UIPcBangDialog, GetState, 17, 0x24676F72);

// @0x141324d80
int UIPcBangDialog::GetPcBangGrade()
{
    if (m_nState == 0)
        return -1;
    return m_nGrade;
}
MS2_REPLACE_METHOD(0x141324D80, UIPcBangDialog, GetPcBangGrade, 39, 0x6DE44024);

// @0x141324db0
int UIPcBangDialog::GetReceivableCount() { return m_nReceivable; }
MS2_REPLACE_METHOD(0x141324DB0, UIPcBangDialog, GetReceivableCount, 17, 0x76860A55);

// @0x141324dd0
void UIPcBangDialog::RefreshAll()
{
    if (!FUN_1422dc2d0())
        return;
    UpdatePlayTime();
    UpdatePcBangFlag();
    UpdateBuff();
    UpdateBanner();
    UpdateRows();
    RefreshGiftList();
}
MS2_REPLACE_METHOD(0x141324DD0, UIPcBangDialog, RefreshAll, 90, 0x097ABC8A);

// @0x141324e30
void UIPcBangDialog::UpdatePcBangFlag()
{
    if (!FUN_1422dc2d0())
        return;
    m_30->Invoke("setPlayPcBang", IsPcBang());
}
MS2_REPLACE_METHOD(0x141324E30, UIPcBangDialog, UpdatePcBangFlag, 95, 0xD0F866F9);

// @0x141324ea0
void UIPcBangDialog::UpdatePlayTime()
{
    if (!FUN_1422dc2d0())
        return;
    m_30->Invoke("setPlayTime", GetPlayTimeText());
}
MS2_REPLACE_METHOD(0x141324EA0, UIPcBangDialog, UpdatePlayTime, 141, 0xD859FAEA);

// @0x141324f40
void UIPcBangDialog::UpdateBuff()
{
    if (!FUN_1422dc2d0())
        return;
    MS2Ptr<AdditionalLevelData> spBuff = FUN_1401958b0()->FUN_140aafef0(m_nBuffId, 1);
    if (spBuff == 0)
        return;
    m_30->Invoke("setIcon", spBuff->GetIcon());
    if (MS2Ptr<ASTextField> spText = GetChild<ASTextField>("buffText"))
    {
        spText->FUN_1422c4f00(GetStringTable()->FUN_141812290(spBuff->GetID(), spBuff->GetLevel(), "tooltipDescription"));
        FUN_140d01340((*spText).FUN_1422bb890(), 2, 2);
    }
}
MS2_REPLACE_METHOD(0x141324F40, UIPcBangDialog, UpdateBuff, 627, 0xA4EEA7A6);

// @0x1413251c0
void UIPcBangDialog::UpdateBanner()
{
    if (!FUN_1422dc2d0())
        return;
    CString strPath = m_banner.GetPath();
    if (strPath.IsEmpty())
        return;
    if (m_strBanner != strPath)
    {
        m_30->Invoke("setBanner", CString(strPath));
        m_strBanner = strPath;
    }
}
MS2_REPLACE_METHOD(0x1413251C0, UIPcBangDialog, UpdateBanner, 278, 0x3D6294DA);

// @0x1413252e0
void UIPcBangDialog::UpdateRows()
{
    if (!FUN_1422dc2d0())
        return;
    for (unsigned i = 0; i < m_rows.GetCount(); i++)
    {
        if (i >= m_playBonus.GetCount())
        {
            m_rows[i]->vfunc_3(0);
            continue;
        }
        m_rows[i]->vfunc_3(1);
        MS2Ptr<PlayBonusItemGift> spBonus = m_playBonus[i];
        const Scaleform::GFx::Value& row = m_rows[i]->FUN_1422bb870();
        FUN_140d00360(row, "itemSlot", spBonus->m_itemId, spBonus->vfunc_o18_1(), spBonus->m_count);
        FUN_140cfee80(row, "itemName", GetStringTable()->FUN_141811980(1, spBonus->m_itemId));
        FUN_140cfee80(row, "reqPlayTime", FUN_1409e97f0(0x97c, spBonus->GetMinutes()));
    }
    UpdateProgress();
}
MS2_REPLACE_METHOD(0x1413252E0, UIPcBangDialog, UpdateRows, 906, 0xE307FE3F);

// @0x141325670
void UIPcBangDialog::UpdateProgress()
{
    if (!FUN_1422dc2d0())
        return;
    unsigned nPlayTime = GetPlayTime();
    for (unsigned i = 0; i < m_rows.GetCount(); i++)
    {
        if (i >= m_playBonus.GetCount())
            continue;
        MS2Ptr<PlayBonusItemGift> spBonus = m_playBonus[i];
        const Scaleform::GFx::Value& row = m_rows[i]->FUN_1422bb870();
        bool bReached = nPlayTime >= spBonus->m_requiredTime;
        FUN_140cffa50(row, "bgColor", bReached ? "black" : "white");
        bool bEnable;
        if (bReached && !m_received[i])
            bEnable = true;
        else
            bEnable = false;
        m_getButtons[i]->vfunc_4(bEnable);
        FUN_140cff840(row, "isGetItem", m_received[i]);
    }
}
MS2_REPLACE_METHOD(0x141325670, UIPcBangDialog, UpdateProgress, 725, 0x612D0622);

// @0x141325950
void UIPcBangDialog::RefreshGiftList()
{
    if (!FUN_1422dc2d0())
        return;
    m_spGiftList->Invoke("resetRenderer");
    for (int i = 0; i < (int)m_giftOrder.size(); i++)
    {
        MS2Ptr<ItemGiftPcBang>& spGift = m_giftOrder[i];
        MS2Ptr<CItemData> spData = FUN_14053f870(spGift->m_itemId);
        if (!spData)
            continue;
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_140523c40(spGift->m_itemId, spGift->vfunc_o18_1(), 0))
        {
            ASObj obj(2);
            obj.FUN_1409c0d20("id", spGift->m_giftId);
            obj.FUN_1407cbb20("label", GetStringTable()->FUN_141811980(1, spGift->m_itemId));
            obj.FUN_1409adc90("itemGrade", spGift->vfunc_o18_1());
            obj.FUN_1407cba60("iconPath", spData->FUN_14053fdd0());
            obj.FUN_1407cb9c0("itemPcBang", spItem->FUN_140525ca0());
            int nState = FUN_141275a10(spItem.get());
            if (nState == 2)
                obj.FUN_1407cb9c0("disable", 1);
            else if (nState == 1)
                obj.FUN_1407cb9c0("itemLock", 1);
            else if (nState == 3)
                obj.FUN_1407cb9c0("itemConditionLock", 1);
            m_spGiftList->FUN_1422dd230(obj);
        }
    }
    m_spGiftList->vfunc_24(true);
}
MS2_REPLACE_METHOD(0x141325950, UIPcBangDialog, RefreshGiftList, 1029, 0xB59F7145);

// @0x141325d60
void UIPcBangDialog::FUN_141325d60() {}

// @0x141325d70
void UIPcBangDialog::OnClickItemGet(const Scaleform::GFx::FunctionHandler::Params& params)
{
    COutPacket packet(static_cast<int>(SendOp::PcBangBonus), 0);
    packet.vfunc_o10_1(1);
    packet.vfunc_o10_1((unsigned char)(unsigned __int64)params.pUserData);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x141325D70, UIPcBangDialog, OnClickItemGet, 99, 0x1DF98A6C);

// @0x141325de0
void UIPcBangDialog::OnClickBanner(const Scaleform::GFx::FunctionHandler::Params& params) { m_banner.OpenLink(); }
MS2_REPLACE_METHOD(0x141325DE0, UIPcBangDialog, OnClickBanner, 38, 0x7AFCB0C4);

// @0x141325e10
void UIPcBangDialog::ResetInfo()
{
    m_bGiftOrderDirty = 1;
    m_nGrade = 0;
    m_nStartTime = 0;
    m_nPlayTime = 0;
    m_received.FUN_140b91330();             // none(), result unused: the bonus bits are NOT cleared here
    m_strBanner = "";
    m_nBuffId = 0;
    m_playBonus.RemoveAll();
    m_gifts.RemoveAll();
    m_giftOrder.clear();
}
MS2_REPLACE_METHOD(0x141325E10, UIPcBangDialog, ResetInfo, 189, 0xD9ED76DE);

// @0x141325ee0
unsigned UIPcBangDialog::GetPlayTime()
{
    if (!IsPcBang())
        return m_nPlayTime;
    unsigned nNow = FUN_141472bc0();
    unsigned nElapsed = nNow > m_nStartTime ? nNow - m_nStartTime : 0;
    unsigned nTotal = nElapsed + m_nPlayTime;
    return nTotal;
}
MS2_REPLACE_METHOD(0x141325EE0, UIPcBangDialog, GetPlayTime, 135, 0x0FDBEE44);

// @0x141325f70
CStringW UIPcBangDialog::GetPlayTimeText()
{
    const int nSecPerHour = 3600;
    const int nSecPerMinute = 60;
    int nSec = GetPlayTime() / 1000;
    int nHour = nSec / nSecPerHour;
    int nMinute = nSec % nSecPerHour / nSecPerMinute;
    if (nHour > 0)
        return FUN_140811740(0xad0, nHour, nMinute);
    else
        return FUN_1408116a0(0xad1, nMinute);
}
MS2_REPLACE_METHOD(0x141325F70, UIPcBangDialog, GetPlayTimeText, 194, 0x38EF9990);

// The level-limited gifts sort by the item level limit, then by gift id (a stateless functor; operator() 0x1413291f0).
struct Unk_PcBangGiftLevelLess
{
    // @0x1413291f0
    bool operator()(const MS2Ptr<ItemGiftPcBang>& a, const MS2Ptr<ItemGiftPcBang>& b) const
    {
        MS2Ptr<CItemData> spA = FUN_14053f870(a->m_itemId);
        MS2Ptr<CItemData> spB = FUN_14053f870(b->m_itemId);
        if (spA->limit.levelLimit != spB->limit.levelLimit)
            return spA->limit.levelLimit < spB->limit.levelLimit;
        return a->m_giftId < b->m_giftId;
    }
};

// @0x141326040
void UIPcBangDialog::RebuildGiftOrder()
{
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (m_bGiftOrderDirty == 0)
        return;
    m_giftOrder.clear();
    m_giftOrder.reserve(m_gifts.GetCount());
    std::vector<MS2Ptr<ItemGiftPcBang> > vecLevel;          // the gifts with a level limit, by level
    for (POSITION pos = m_gifts.GetHeadPosition(); pos != 0; m_gifts.GetNext(pos))
    {
        MS2Ptr<ItemGiftPcBang> spGift = m_gifts.GetValueAt(pos);
        MS2Ptr<CItemData> spData = FUN_14053f870(spGift->m_itemId);
        if (spData == 0)
            continue;
        if (spData->FUN_14053cbc0() && !spData->FUN_14053cf90())
            vecLevel.push_back(spGift);
        else
            m_giftOrder.push_back(spGift);
    }
    std::sort(vecLevel.begin(), vecLevel.end(), Unk_PcBangGiftLevelLess());
    // The gifts from the highest level limit the player reached come first, then the higher ones, then the lower ones.
    unsigned nLevel = (unsigned short)pPlayer->vfunc_78();
    std::vector<MS2Ptr<ItemGiftPcBang> >::iterator it = vecLevel.begin();
    std::vector<MS2Ptr<ItemGiftPcBang> >::iterator itSplit = vecLevel.begin();
    for (; it != vecLevel.end(); it++)
    {
        MS2Ptr<ItemGiftPcBang> spSplit = *itSplit;
        MS2Ptr<ItemGiftPcBang> spCur = *it;
        MS2Ptr<CItemData> spSplitData = FUN_14053f870(spSplit->m_itemId);
        MS2Ptr<CItemData> spCurData = FUN_14053f870(spCur->m_itemId);
        if (spSplitData->limit.levelLimit == spCurData->limit.levelLimit)
            continue;
        if (nLevel < spCurData->limit.levelLimit)
            break;
        itSplit = it;
    }
    for (it = itSplit; it != vecLevel.end(); it++)
        m_giftOrder.push_back(*it);
    for (it = vecLevel.begin(); it != itSplit; it++)
        m_giftOrder.push_back(*it);
    m_bGiftOrderDirty = 0;
}
MS2_REPLACE_METHOD(0x141326040, UIPcBangDialog, RebuildGiftOrder, 1274, 0x7DAA8738);

// @0x141326540
void UIPcBangDialog::RequestInfo()
{
    COutPacket packet(static_cast<int>(SendOp::PcBangBonus), 0);
    packet.vfunc_o10_1(3);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x141326540, UIPcBangDialog, RequestInfo, 75, 0x9BEF4278);

// @0x1413265a0
void UIPcBangDialog::UpdateReceivable()
{
    if (CountBits(m_received) >= m_playBonus.GetCount())
        return;
    int nPrev = m_nReceivable;
    m_nReceivable = CountReachedBonus() - CountBits(m_received);
    if (nPrev != m_nReceivable)
        FUN_140939a10()->Post(MS2Ptr<NotifyObject>(new NotifyPcBang()));
}
MS2_REPLACE_METHOD(0x1413265A0, UIPcBangDialog, UpdateReceivable, 308, 0xC35F1551);

// @0x1413266e0
int UIPcBangDialog::CountReachedBonus()
{
    unsigned nPlayTime = GetPlayTime();
    int nCount = 0;
    for (unsigned i = 0; i < m_playBonus.GetCount(); i++)
    {
        MS2Ptr<PlayBonusItemGift> spBonus = m_playBonus[i];
        if (nPlayTime < spBonus->m_requiredTime)
            break;
        nCount = i + 1;
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x1413266E0, UIPcBangDialog, CountReachedBonus, 198, 0xFB091189);

// @0x1413267b0
int UIPcBangDialog::IsPcBang() { return m_nGrade > 0; }
MS2_REPLACE_METHOD(0x1413267B0, UIPcBangDialog, IsPcBang, 49, 0xD7B8B170);

MS2_EMIT_CRT_MEMMOVE_S();
