// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Reward / fame-contents HUD notifications.
// MS2-UNIT: client\ms2\uirewardnotify.cpp
// MS2-RANGE: 0x141abe1d0-0x141ac6fa0 .text$mn
// MS2-RANGE: 0x14011bfb0-0x14011c3e0 .text$di
// MS2-RANGE: 0x142cc1ed0-0x142cc20c6 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAHH$0A@@?$pair@HH@std@@QEAA@AEAH$$QEAH@Z 0x141ac2b70 ; unique
// MS2-PIN: ??$?8PEAVUIFameContentsNotify@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x141ac2d60 ; prop
// MS2-PIN: ??$?8PEAVUIRewardNotify@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIRewardNotify@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x141ac2dd0 ; prop
// MS2-PIN: ??$FormatStringId@KV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBKAEBV01@@Z 0x141ac2e90 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x141ac3710
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIRewardNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x141ac37b0
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAA@XZ 0x141ac38e0 ; order
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VAScript@@@@V?$CElementTraits@V?$MS2Ptr@VAScript@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VAScript@@@@_K@Z 0x141ac3960 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x141ac39a0 ; order
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIRewardNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x141ac39e0 ; order
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141ac45a0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIRewardNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141ac4600 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x141ac4660 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIRewardNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x141ac4690 ; unique
// MS2-PIN: ??$Call@VUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x141ac46c0 ; prop
// MS2-PIN: ??$Call@VUIRewardNotify@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIRewardNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIRewardNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x141ac4700 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141ac4740 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIRewardNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141ac47a0 ; unique
// MS2-PIN: memmove_s 0x141ac4800 ; unique
// MS2-PIN: ??$?0PEAVUIRouletteDialog@@P80@EAAXAEAVCInPacket@@@Z$0A@@?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@QEAA@AEBQEAVUIRouletteDialog@@AEBQ82@EAAXAEAVCInPacket@@@Z@Z 0x141ac6470 ; unique
// MS2-PIN: ??$?0VUIRouletteDialog@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBQEAVUIRouletteDialog@@AEBQ81@EAAXAEAVCInPacket@@@Z@Z 0x141ac64b0 ; unique
// MS2-PIN: ??$?8PEAVUIRouletteDialog@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x141ac6540 ; prop
// MS2-PIN: ??$forward@AEBQ8UIRouletteDialog@@EAAXAEAVCInPacket@@@Z@std@@YAAEBQ8UIRouletteDialog@@EAAXAEAVCInPacket@@@ZAEBQ81@EAAX0@Z@Z 0x141ac66f0 ; prop
// MS2-PIN: ??$forward@AEBQEAVUIRouletteDialog@@@std@@YAAEBQEAVUIRouletteDialog@@AEBQEAV1@@Z 0x141ac6700 ; prop
// MS2-PIN: ??$make_pair@AEBQEAVUIRouletteDialog@@AEBQ81@EAAXAEAVCInPacket@@@Z@std@@YA?AU?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@0@AEBQEAVUIRouletteDialog@@AEBQ82@EAAXAEAVCInPacket@@@Z@Z 0x141ac6710 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x141ac67a0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBU?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@Z 0x141ac67f0 ; unique
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAA@XZ 0x141ac6880 ; prop
// MS2-PIN: ??A?$CAtlArray@UUnk_RouletteSpin@@V?$CElementTraits@UUnk_RouletteSpin@@@ATL@@@ATL@@QEAAAEAUUnk_RouletteSpin@@_K@Z 0x141ac68a0 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAPEAXI@Z 0x141ac68e0 ; prop
// MS2-PIN: ??_GUIRouletteDialog@@UEAAPEAXI@Z 0x141ac6920 ; unique
// MS2-PIN: ?Add@?$CAtlArray@UUnk_RouletteSpin@@V?$CElementTraits@UUnk_RouletteSpin@@@ATL@@@ATL@@QEAA_KAEBUUnk_RouletteSpin@@@Z 0x141ac6960 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141ac6e70 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x141ac6ed0 ; unique
// MS2-PIN: ??$Call@VUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x141ac6f00 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIRouletteDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141ac6f40 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?RemoveHead@?$CAtlList@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@QEAA?AU?$pair@HH@std@@XZ 0x141ac4360
// MS2-PIN: ??__Fs_unk1402a9d70@@YAXXZ 0x142cc1f40
// MS2-PIN: ??__Fs_unk1402a9d70_b@@YAXXZ 0x142cc2030
// MS2-PIN: ??$forward@AEAH@std@@YAAEAHAEAH@Z 0x141ac3580
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUIFameContentsNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@6B@ 0x142fdd620
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUIRewardNotify@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@6B@ 0x142fdd5f8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uirewardnotify.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uirewardnotify.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- helpers of other units (opaque here) ----
FMT_VARIADIC_W(CStringW, FormatStringId, int)
CStringW FormatStringId(int id, const fmt::ArgList& args);   // 0x14028dee0

// The client config singleton: the string fields the reward toasts read (icon paths).
struct Unk_RNConfig {
    char m_pad_00[0x158]; CString m_158; char m_pad_160[0x10]; CString m_170, m_178, m_180, m_188, m_190;
    char m_pad_198[8]; CString m_1a0, m_1a8, m_1b0, m_1b8, m_1c0; char m_pad_1c8[8]; CString m_1d0;
    CString FUN_140cca050(int nKind);
};
MS2_CHECK_OFFSET(Unk_RNConfig, m_158, 0x158);
MS2_CHECK_OFFSET(Unk_RNConfig, m_170, 0x170);
MS2_CHECK_OFFSET(Unk_RNConfig, m_190, 0x190);
MS2_CHECK_OFFSET(Unk_RNConfig, m_1a0, 0x1a0);
MS2_CHECK_OFFSET(Unk_RNConfig, m_1c0, 0x1c0);
MS2_CHECK_OFFSET(Unk_RNConfig, m_1d0, 0x1d0);
Unk_RNConfig* FUN_1401d31f0();

// A "NotifyChangedTokenMoney" notice: kind at +0x18, the amount at +0x28.
struct Unk_RNNotice { void* m_0; void* m_8; void* m_10; int m_kind; int m_1c; void* m_20; __int64 m_count; };
MS2_CHECK_OFFSET(Unk_RNNotice, m_kind, 0x18);
MS2_CHECK_OFFSET(Unk_RNNotice, m_count, 0x28);

class Unk_RNNotices { public: void FUN_140da4e40(CStringW, Delegate<void(NotifyObject*)>); void FUN_140da4eb0(CStringW, Delegate<void(NotifyObject*)>); };
Unk_RNNotices* FUN_140939a10();
class Unk_RNUIManager { public: void FUN_141adc530(int nUiId); };
Unk_RNUIManager* FUN_1403ed2b0();
CStringW FUN_14016a730(const char*, int);
CStringW FUN_1409404f0(__int64);
CStringW FUN_14052bd00(int, const CStringW&);
CStringW FUN_14086d060(int, const __int64&);
CStringW FUN_140c160b0(CStringW, const __int64&);
CStringW FUN_14062b4f0(CStringW strKey, const int* pn);
CStringW FUN_141b720b0(int, int);
CStringW FUN_140292a70(const wchar_t*, const unsigned int&);
CStringW FUN_14093b970(unsigned);
CStringW FUN_1405c2690(CStringW, const CStringW&);
CString FUN_14021a6b0(int);
bool FUN_140184310(const CString& str, const char* psz);
int FUN_141276180(const CString& str, const CString& strArg);
int FUN_1418dd0d0();
int FUN_1422b9e00(void*);
void* FUN_1408e57f0();
extern int DAT_1439fa004;

class Unk_RNStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_RNStrings* FUN_1401a9d70();
class Unk_RNGrades { public: unsigned long FUN_1405569f0(int); };
Unk_RNGrades* FUN_140281980();

// Item records.
class Unk_RNItemData { public: unsigned char FUN_14053d990(); CString FUN_14053fdd0(); };
class Unk_RNItem { public: int FUN_1405276c0(); int FUN_140526bd0(); Unk_RNItemData* FUN_140527840(); CStringW FUN_140527b10(); CString FUN_140528590(); };
class Unk_RNItemRef {
public:
    Unk_RNItemRef(const Unk_RNItemRef& o) : m_0(o.m_0), m_8(o.m_8) { if (m_8) CPtred::AddRefPtred(static_cast<CPtred*>(m_8)); }   // 0x1402034d0
    ~Unk_RNItemRef();                           // 0x1401bfde0
    Unk_RNItem* FUN_1401c0180() const;
    void* FUN_14052cd70() const;
private:
    void* m_0; void* m_8;
};
MS2_CHECK_SIZE(Unk_RNItemRef, 0x10);
class Unk_RNItemInfo {
public:
    ~Unk_RNItemInfo();                          // 0x1401b50d0
    Unk_RNItemData* FUN_140203c60() const;
    Unk_RNItemData* FUN_1401b52a0() const;
private:
    void* m_0; void* m_8;
};
MS2_CHECK_SIZE(Unk_RNItemInfo, 0x10);
Unk_RNItemInfo FUN_14053f870(int);
bool FUN_14053f900(int);

// Achievements / titles.
class Unk_RNAchieve { public: unsigned FUN_1409399f0(); CString FUN_140159430(int); int FUN_14015a290(); };

// Skills.
struct Unk_RNSkillRow { char m_pad_00[0x48]; CString m_48; unsigned char FUN_1407e9d30(); unsigned char FUN_1407e9de0(); };
class Unk_RNSkillRef {
public:
    ~Unk_RNSkillRef();                          // 0x14063e5c0
    void* FUN_14063ed10() const;
    Unk_RNSkillRow* FUN_14063ed50() const;
    unsigned char FUN_14063eab0(int);
    unsigned char FUN_1407f6e90() const;
private:
    void* m_0; void* m_8;
};
MS2_CHECK_SIZE(Unk_RNSkillRef, 0x10);
class Unk_RNSkillTable { public: Unk_RNSkillRef FUN_1407ee1d0(int nSkillId); };
Unk_RNSkillTable* FUN_1401958b0();
MS2Ptr<ASGameEntity> FUN_140ba77e0(int nUiId, const Scaleform::GFx::Value& root);

// Fishing.
class Unk_RNFishData : public CPtred {
public:
    int FUN_1403b1520(int nLength); int FUN_1403b1590(int nLength); CStringW FUN_1403b1600(); CStringW FUN_1403b1650();
};
class Unk_RNFishTable { public: MS2Ptr<Unk_RNFishData> FUN_1403b2d30(int nId); };
Unk_RNFishTable* FUN_1403b4740();

// ---- unit statics: the shared header statics come first (header_statics_a.h), then the file's own ----
static CString s_strPCTitleGet = "PC_TitleGet";
static CString s_strPCSkillGet = "PC_SkillGet";
static CString s_strTrophyHero = "system_Trophy_Hero";

// @0x141abe1d0
UIRewardNotify::UIRewardNotify() { m_2c = 0x1f; m_block = 0; }

// @0x141abe240
CString UIRewardNotify::vfunc_1() { return "RewardNotify"; }
MS2_REPLACE_METHOD(0x141abe240, UIRewardNotify, vfunc_1, 61, 0x6D329B98);

// Every toast is an AS object built member by member (the setters are ASObj members; the pointer is kept as a
// MS2Ptr<AScript>, the instantiation the exe shares).
#define RN_OBJ(p) static_cast<ASObj*>((p).operator->())

// @0x141abe290
void UIRewardNotify::vfunc_2()
{
    m_block = 0;
    FUN_1422dbf00(0x1f, 0, 0);
}
MS2_REPLACE_METHOD(0x141abe290, UIRewardNotify, vfunc_2, 50, 0xDA01054C);

// @0x141abe2d0
void UIRewardNotify::vfunc_3()
{
    FUN_1422dc080();
    m_queue.RemoveAll();
}
MS2_REPLACE_METHOD(0x141abe2d0, UIRewardNotify, vfunc_3, 41, 0xBABD3D2D);

// @0x141abe300
void UIRewardNotify::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_140939a10()->FUN_140da4e40(L"NotifyLearnEmotion", Delegate<void(NotifyObject*)>(this, &UIRewardNotify::FUN_141abea10));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UIRewardNotify::FUN_141abea50));
}

// @0x141abe4c0
void UIRewardNotify::vfunc_26()
{
    UIObject::vfunc_26();
    FUN_140939a10()->FUN_140da4eb0(L"NotifyLearnEmotion", Delegate<void(NotifyObject*)>(this, &UIRewardNotify::FUN_141abea10));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UIRewardNotify::FUN_141abea50));
}

// @0x141abe680
void UIRewardNotify::vfunc_43()
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity.get()) {
        int n = FUN_1418dd0d0();
        pEntity->vfunc_2(2, 8, -(n + 0x2c));
    }
}
MS2_REPLACE_METHOD(0x141abe680, UIRewardNotify, vfunc_43, 184, 0x9A181B4D);

// @0x141abe740
void UIRewardNotify::vfunc_15()
{
    if (FUN_1422b9e00(FUN_1408e57f0()) != 0x6200031 && m_block == 0 && m_queue.GetCount() != 0) {
        MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pEntity.IsNull()) {
            for (size_t i = 0; i < m_queue.GetCount(); i++) {
                MS2Ptr<AScript> pReward(m_queue[i]);
                FUN_141ac1fe0(pReward);
            }
            m_queue.RemoveAll();
        }
    }
}
MS2_REPLACE_METHOD(0x141abe740, UIRewardNotify, vfunc_15, 353, 0xEB7BD198);

// @0x141abe8b0
int UIRewardNotify::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onReward") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CString strType = data.FUN_1422b8d30();
            if (FUN_140184310(strType, "achieve"))
                FUN_141276180(s_strTrophyHero, "");
        }
        return 1;
    }
    if (_stricmp(szMethod, "onSkillLevelUp") == 0)
        FUN_1403ed2b0()->FUN_141adc530(0x4f2d);
    return 0;
}

// @0x141abea10
void UIRewardNotify::FUN_141abea10(NotifyObject* pNotice)
{
    FUN_141abffa0(reinterpret_cast<Unk_RNNotice*>(pNotice)->m_kind);
}
MS2_REPLACE_METHOD(0x141abea10, UIRewardNotify, FUN_141abea10, 47, 0x5232D604);

// @0x141abea50
void UIRewardNotify::FUN_141abea50(NotifyObject* pNotice)
{
    Unk_RNNotice* pN = reinterpret_cast<Unk_RNNotice*>(pNotice);
    if (0 < pN->m_count) {
        __int64 nCount = pN->m_count;
        switch (pN->m_kind) {
        case 3: {
            CStringW strIcon = FUN_14016a730(FUN_1401d31f0()->m_180, 0);
            CStringW strMsg = FUN_14086d060(0x68c, nCount);
            FUN_141ac0cd0(strMsg, strIcon);
            break;
        }
        case 4: {
            CStringW strIcon = FUN_14016a730(FUN_1401d31f0()->m_178, 0);
            CStringW strMsg = FUN_14086d060(0x68d, nCount);
            FUN_141ac0cd0(strMsg, strIcon);
            break;
        }
        case 5: {
            CStringW strIcon = FUN_14016a730(FUN_1401d31f0()->m_188, 0);
            CStringW strMsg = FUN_14086d060(0x68e, nCount);
            FUN_141ac0cd0(strMsg, strIcon);
            break;
        }
        case 6: {
            CStringW strIcon = FUN_14016a730(FUN_1401d31f0()->m_190, 0);
            CStringW strMsg = FUN_14086d060(0x68f, nCount);
            FUN_141ac0cd0(strMsg, strIcon);
            break;
        }
        case 9: {
            CStringW strIcon = FUN_14016a730(FUN_1401d31f0()->m_1a0, 0);
            CStringW strMsg = FUN_140c160b0(L"s_system_achieve_reward_reverse_coin", nCount);
            FUN_141ac0cd0(strMsg, strIcon);
            break;
        }
        case 10: {
            CStringW strIcon = FUN_14016a730(FUN_1401d31f0()->m_1a8, 0);
            CStringW strMsg = FUN_140c160b0(L"s_system_achieve_reward_mentor_token", nCount);
            FUN_141ac0cd0(strMsg, strIcon);
            break;
        }
        case 11: {
            CStringW strIcon = FUN_14016a730(FUN_1401d31f0()->m_1b0, 0);
            CStringW strMsg = FUN_140c160b0(L"s_system_achieve_reward_mentee_token", nCount);
            FUN_141ac0cd0(strMsg, strIcon);
            break;
        }
        case 12: {
            CStringW strIcon = FUN_14016a730(FUN_1401d31f0()->m_1b8, 0);
            CStringW strMsg = FUN_140c160b0(L"s_system_achieve_reward_star_point", nCount);
            FUN_141ac0cd0(strMsg, strIcon);
            break;
        }
        case 13: {
            CStringW strIcon = FUN_14016a730(FUN_1401d31f0()->m_1c0, 0);
            CStringW strMsg = FUN_140c160b0(L"s_system_achieve_reward_meso_market_token", nCount);
            FUN_141ac0cd0(strMsg, strIcon);
            break;
        }
        }
    }
}
MS2_REPLACE_METHOD(0x141abea50, UIRewardNotify, FUN_141abea50, 1885, 0xA81C48DD);

// @0x141abf1f0
void UIRewardNotify::FUN_141abf1f0() { m_block = 1; }
MS2_REPLACE_METHOD(0x141abf1f0, UIRewardNotify, FUN_141abf1f0, 21, 0x9908BB04);

// @0x141abf210
void UIRewardNotify::FUN_141abf210() { m_block = 0; }
MS2_REPLACE_METHOD(0x141abf210, UIRewardNotify, FUN_141abf210, 21, 0x54617667);

// @0x141abf230
void UIRewardNotify::FUN_141abf230(__int64 nExp, __int64 nBonus)
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    if (nBonus < 1) {
        RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14052bd00(0x681, FUN_1409404f0(nExp)));
    } else {
        RN_OBJ(pObj)->FUN_1407cbb20("msg", FormatStringId(0x682, FUN_1409404f0(nExp), nBonus));
    }
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "exp");
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141abf230, UIRewardNotify, FUN_141abf230, 534, 0x9B688EA5);

// @0x141abf450
void UIRewardNotify::FUN_141abf450(__int64 nMoney, __int64 nBonus)
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    if (nBonus < 1) {
        RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14052bd00(0x683, FUN_1409404f0(nMoney)));
    } else {
        RN_OBJ(pObj)->FUN_1407cbb20("msg", FormatStringId(0x684, FUN_1409404f0(nMoney), nBonus));
    }
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "icon");
    RN_OBJ(pObj)->FUN_1407cbb20("icon", FUN_14016a730(FUN_1401d31f0()->m_158, 0));
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141abf450, UIRewardNotify, FUN_141abf450, 647, 0x3500A818);

// @0x141abf6e0
void UIRewardNotify::FUN_141abf6e0(int nItemId, int nGrade)
{
    Unk_RNItemInfo info = FUN_14053f870(nItemId);
    if (info.FUN_140203c60()) {
        unsigned long nCount = FUN_140281980()->FUN_1405569f0(nGrade);
        CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
        CStringW strMsg = FormatStringId(0x687, nCount, strName);
        MS2Ptr<AScript> pObj(new ASObj(2));
        RN_OBJ(pObj)->FUN_1409c0dc0("type", "icon");
        RN_OBJ(pObj)->FUN_1407cbb20("msg", strMsg);
        RN_OBJ(pObj)->FUN_1407cbb20("icon", FUN_14016a730(info.FUN_1401b52a0()->FUN_14053fdd0(), 0));
        RN_OBJ(pObj)->FUN_1409adc90("grade", nGrade);
        RN_OBJ(pObj)->FUN_1407cbbe0("itemPiece", info.FUN_1401b52a0()->FUN_14053d990() == 1);
        RN_OBJ(pObj)->FUN_1409c0d20("key", nItemId);
        FUN_141ac1fe0(pObj);
    }
}
MS2_REPLACE_METHOD(0x141abf6e0, UIRewardNotify, FUN_141abf6e0, 801, 0xC67E6D8B);

// @0x141abfa10
void UIRewardNotify::FUN_141abfa10(Unk_RNItemRef item)
{
    int nItemId = item.FUN_1401c0180()->FUN_1405276c0();
    if (!FUN_14053f900(nItemId)) {
        if (item.FUN_14052cd70()) {
            if (item.FUN_1401c0180()->FUN_140527840()) {
                int nGrade = item.FUN_1401c0180()->FUN_140526bd0();
                unsigned long nCount = FUN_140281980()->FUN_1405569f0(nGrade);
                CStringW strName = item.FUN_1401c0180()->FUN_140527b10();
                CStringW strMsg = FormatStringId(0x687, nCount, strName);
                MS2Ptr<AScript> pObj(new ASObj(2));
                RN_OBJ(pObj)->FUN_1409c0dc0("type", "icon");
                RN_OBJ(pObj)->FUN_1407cbb20("msg", strMsg);
                RN_OBJ(pObj)->FUN_1407cbb20("icon", FUN_14016a730(item.FUN_1401c0180()->FUN_140528590(), 0));
                RN_OBJ(pObj)->FUN_1409adc90("grade", nGrade);
                RN_OBJ(pObj)->FUN_1407cbbe0("itemPiece", item.FUN_1401c0180()->FUN_140527840()->FUN_14053d990() == 1);
                RN_OBJ(pObj)->FUN_1409c0d20("key", item.FUN_1401c0180()->FUN_1405276c0());
                FUN_141ac1fe0(pObj);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141abfa10, UIRewardNotify, FUN_141abfa10, 928, 0x080AE4BB);

// @0x141abfdc0
void UIRewardNotify::FUN_141abfdc0(Unk_RNAchieve* pAchieve)
{
    if (pAchieve) {
        MS2Ptr<AScript> pObj(new ASObj(2));
        RN_OBJ(pObj)->FUN_1409c0dc0("type", "achieve");
        RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14093b970(pAchieve->FUN_1409399f0()));
        RN_OBJ(pObj)->FUN_1407cba60("icon", pAchieve->FUN_140159430(0));
        RN_OBJ(pObj)->FUN_1407cbbe0("emblem", pAchieve->FUN_14015a290() == 9);
        FUN_141ac1fe0(pObj);
    }
}
MS2_REPLACE_METHOD(0x141abfdc0, UIRewardNotify, FUN_141abfdc0, 463, 0xECE96FC9);

// @0x141abffa0
void UIRewardNotify::FUN_141abffa0(int nEmotionId)
{
    Unk_RNSkillRef ref = FUN_1401958b0()->FUN_1407ee1d0(nEmotionId);
    if (ref.FUN_14063ed10()) {
        if (!ref.FUN_14063ed50()->FUN_1407e9d30())
            return;
        MS2Ptr<AScript> pObj(new ASObj(2));
        RN_OBJ(pObj)->FUN_1409c0dc0("type", "icon");
        RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14052bd00(0x85b, FUN_1401a9d70()->FUN_141811980(4, nEmotionId)));
        RN_OBJ(pObj)->FUN_1407cbb20("icon", FUN_14016a730(ref.FUN_14063ed50()->m_48, 0));
        RN_OBJ(pObj)->FUN_1407cb9c0("grade", 1);
        FUN_141ac1fe0(pObj);
    }
}
MS2_REPLACE_METHOD(0x141abffa0, UIRewardNotify, FUN_141abffa0, 610, 0x51241394);

// Learned skills of a player (a list of 16-byte refs).
class Unk_RNLearn { public: unsigned FUN_140637cc0(); char m_pad_00[0x1e]; char m_1e; };
class Unk_RNLearnRef { public: Unk_RNLearn* FUN_14063ed30(); private: void* m_0; void* m_8; };
MS2_CHECK_SIZE(Unk_RNLearnRef, 0x10);
class Unk_RNLearnList {
public:
    Unk_RNLearnList();                          // 0x14063e490
    ~Unk_RNLearnList();                         // 0x14063e800
    Unk_RNLearnRef* FUN_1406420e0();
    Unk_RNLearnRef* FUN_1406421b0();
private:
    void* m_0; void* m_8; void* m_10;
};
MS2_CHECK_SIZE(Unk_RNLearnList, 0x18);
class Unk_RNLook { public: void FUN_1406395c0(Unk_RNLearnList* pOut, int a, int b); };
Unk_RNLook* FUN_1416546d0(PC* pPC);

// @0x141ac0210
void UIRewardNotify::FUN_141ac0210(PC* pPlayer)
{
    Unk_RNLearnList list;
    FUN_1416546d0(pPlayer)->FUN_1406395c0(&list, 1, 1);
    bool bAny = false;
    for (Unk_RNLearnRef* it = list.FUN_1406420e0(); it != list.FUN_1406421b0(); it++) {
        unsigned nSkillId = it->FUN_14063ed30()->FUN_140637cc0();
        Unk_RNSkillRef ref = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
        if (!ref.FUN_1407f6e90()) {
            if (it->FUN_14063ed30()->m_1e) {
                bAny = true;
                MS2Ptr<AScript> pObj(new ASObj(2));
                RN_OBJ(pObj)->FUN_1409c0dc0("type", "learn_skill");
                RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14052bd00(0x804, FUN_1401a9d70()->FUN_141811980(4, it->FUN_14063ed30()->FUN_140637cc0())));
                RN_OBJ(pObj)->FUN_1407cb9c0("skillType", ref.FUN_14063ed50()->FUN_1407e9de0() != 0);
                RN_OBJ(pObj)->FUN_1407cba60("skillIconPath", ref.FUN_14063ed50()->m_48);
                FUN_141ac1fe0(pObj);
            }
        }
    }
    if (bAny)
        FUN_141276180(s_strPCSkillGet, "");
}

// @0x141ac05d0
void UIRewardNotify::FUN_141ac05d0(int nSkillId, CStringW strMsg, int nSkillType)
{
    Unk_RNSkillRef ref = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
    if (ref.FUN_14063eab0(0))
        return;
    FUN_141ac1f40();
    MS2Ptr<AScript> pObj(new ASObj(2));
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "skill_msg");
    RN_OBJ(pObj)->FUN_1407cbb20("msg", strMsg);
    if (nSkillType == 0) {
        RN_OBJ(pObj)->FUN_1407cb9c0("skillType", ref.FUN_14063ed50()->FUN_1407e9de0() != 0);
    } else {
        RN_OBJ(pObj)->FUN_1407cb9c0("skillType", DAT_1439fa004);
    }
    RN_OBJ(pObj)->FUN_1407cba60("skillIconPath", ref.FUN_14063ed50()->m_48);
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141ac05d0, UIRewardNotify, FUN_141ac05d0, 641, 0xFD5E4298);

// @0x141ac0860
void UIRewardNotify::FUN_141ac0860(__int64 nValue)
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14086d060(0x685, nValue));
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "merat");
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141ac0860, UIRewardNotify, FUN_141ac0860, 287, 0xD0EB08AF);

// @0x141ac0990
void UIRewardNotify::FUN_141ac0990(__int64 nValue)
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14086d060(0x685, nValue));
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "merat_red");
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141ac0990, UIRewardNotify, FUN_141ac0990, 287, 0x7A6551AC);

// @0x141ac0ac0
void UIRewardNotify::FUN_141ac0ac0(int nId)
{
    FUN_141276180(s_strPCTitleGet, "");
    MS2Ptr<AScript> pObj(new ASObj(2));
    RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14052bd00(0x689, FUN_141b720b0(nId, 0)));
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "icon");
    RN_OBJ(pObj)->FUN_1407cbb20("icon", FUN_14016a730(FUN_1401d31f0()->m_170, 0));
    FUN_141ac1fe0(pObj);
}

// @0x141ac0cd0
void UIRewardNotify::FUN_141ac0cd0(const CStringW& strMsg, const CStringW& strIcon)
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    RN_OBJ(pObj)->FUN_1407cbb20("msg", strMsg);
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "icon");
    RN_OBJ(pObj)->FUN_1407cbb20("icon", strIcon);
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141ac0cd0, UIRewardNotify, FUN_141ac0cd0, 378, 0x4267BFD9);

// @0x141ac0e50
void UIRewardNotify::FUN_141ac0e50(int nFishId, unsigned nLength)
{
    MS2Ptr<Unk_RNFishData> pFish = FUN_1403b4740()->FUN_1403b2d30(nFishId);
    if (!pFish.IsNull()) {
        int nSize = pFish->FUN_1403b1520(nLength);
        int nMedal = pFish->FUN_1403b1590(nLength);
        MS2Ptr<AScript> pObj(new ASObj(2));
        RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14052bd00(0xbd8, pFish->FUN_1403b1650()));
        RN_OBJ(pObj)->FUN_1409c0dc0("type", "fishing_success");
        RN_OBJ(pObj)->FUN_1407cbb20("icon", pFish->FUN_1403b1600());
        RN_OBJ(pObj)->FUN_1407cbb20("size", FUN_140292a70(L"{0}cm", nLength));
        RN_OBJ(pObj)->FUN_1407cb9c0("success", 1);
        RN_OBJ(pObj)->FUN_1407cbbe0("bigFish", nSize == 3);
        RN_OBJ(pObj)->FUN_140f43b40("medal", nMedal);
        RN_OBJ(pObj)->FUN_1409c0d20("key", nFishId);
        FUN_141ac1fe0(pObj);
    }
}
MS2_REPLACE_METHOD(0x141ac0e50, UIRewardNotify, FUN_141ac0e50, 848, 0xE41F7F22);

// @0x141ac11b0
void UIRewardNotify::FUN_141ac11b0(int nFishId, unsigned nLength)
{
    MS2Ptr<Unk_RNFishData> pFish = FUN_1403b4740()->FUN_1403b2d30(nFishId);
    if (!pFish.IsNull()) {
        int nMedal = pFish->FUN_1403b1590(nLength);
        MS2Ptr<AScript> pObj(new ASObj(2));
        RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14052bd00(0xbd9, pFish->FUN_1403b1650()));
        RN_OBJ(pObj)->FUN_1409c0dc0("type", "fishing_fail");
        RN_OBJ(pObj)->FUN_1407cbb20("icon", pFish->FUN_1403b1600());
        RN_OBJ(pObj)->FUN_1407cbb20("size", FUN_140292a70(L"{0}cm", nLength));
        RN_OBJ(pObj)->FUN_1407cb9c0("success", 0);
        RN_OBJ(pObj)->FUN_140f43b40("medal", nMedal);
        RN_OBJ(pObj)->FUN_1409c0d20("key", nFishId);
        FUN_141ac1fe0(pObj);
    }
}
MS2_REPLACE_METHOD(0x141ac11b0, UIRewardNotify, FUN_141ac11b0, 760, 0xE99C7EF6);

// @0x141ac14b0
void UIRewardNotify::FUN_141ac14b0()
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "skillLevelUp");
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141ac14b0, UIRewardNotify, FUN_141ac14b0, 194, 0x6F4EDF58);

// @0x141ac1580
void UIRewardNotify::FUN_141ac1580(const CStringW& strIcon, const CStringW& strMsg, int nEffect)
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    RN_OBJ(pObj)->FUN_1407cbb20("msg", strMsg);
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "icon");
    RN_OBJ(pObj)->FUN_1407cbb20("icon", strIcon);
    RN_OBJ(pObj)->FUN_1407cb9c0("effect", nEffect);
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141ac1580, UIRewardNotify, FUN_141ac1580, 416, 0x33D96BED);

// @0x141ac1730
void UIRewardNotify::FUN_141ac1730(const CStringW& strMsg, int nSpecial, const CStringW& strTag)
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    RN_OBJ(pObj)->FUN_1407cbb20("msg", strMsg);
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "stamp");
    RN_OBJ(pObj)->FUN_1407cb9c0("isSpecial", nSpecial);
    RN_OBJ(pObj)->FUN_1407cbb20("eventTag", strTag);
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141ac1730, UIRewardNotify, FUN_141ac1730, 416, 0x96962105);

// @0x141ac18e0
void UIRewardNotify::FUN_141ac18e0(bool bOpen)
{
    if (m_30 == 0)
        return;
    m_30->Invoke("OnSkillBookDialog", bOpen);
}
MS2_REPLACE_METHOD(0x141ac18e0, UIRewardNotify, FUN_141ac18e0, 99, 0xA9B9EAE6);

// @0x141ac1950
void UIRewardNotify::FUN_141ac1950(int nPoint, int nKind)
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "icon");
    CStringW strKey = L"s_reward_notify_skill_point";
    if (nKind == 2)
        strKey = L"s_reward_notify_skill_point_sub_1";
    RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14062b4f0(strKey, &nPoint));
    RN_OBJ(pObj)->FUN_1407cba60("icon", FUN_1401d31f0()->FUN_140cca050(nKind));
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141ac1950, UIRewardNotify, FUN_141ac1950, 499, 0xDF525E27);

// @0x141ac1b50
void UIRewardNotify::FUN_141ac1b50(int nPoint)
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    RN_OBJ(pObj)->FUN_1409c0dc0("type", "icon");
    RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_14062b4f0(L"s_reward_notify_stat_point", &nPoint));
    RN_OBJ(pObj)->FUN_1407cba60("icon", FUN_1401d31f0()->m_1d0);
    FUN_141ac1fe0(pObj);
}
MS2_REPLACE_METHOD(0x141ac1b50, UIRewardNotify, FUN_141ac1b50, 430, 0xA44E763B);

// @0x141ac1d10
void UIRewardNotify::FUN_141ac1d10(int nItemId)
{
    MS2Ptr<AScript> pObj(new ASObj(2));
    Unk_RNItemData* pItem = FUN_14053f870(nItemId).FUN_140203c60();
    if (pItem) {
        CString strName = pItem->FUN_14053fdd0();
        RN_OBJ(pObj)->FUN_1409c0dc0("type", "boxOpen");
        RN_OBJ(pObj)->FUN_1409c0dc0("nextType", "cashCoupon");
        RN_OBJ(pObj)->FUN_1407cba60("icon", strName);
        RN_OBJ(pObj)->FUN_1407cbb20("msg", FUN_1401a9d70()->FUN_141811980(1, nItemId));
        FUN_141ac1fe0(pObj);
    }
}
MS2_REPLACE_METHOD(0x141ac1d10, UIRewardNotify, FUN_141ac1d10, 552, 0x6C02BD1D);

// @0x141ac1f40
void UIRewardNotify::FUN_141ac1f40()
{
    if (m_30 == 0)
        return;
    m_30->Invoke("rewardComplete");
}
MS2_REPLACE_METHOD(0x141ac1f40, UIRewardNotify, FUN_141ac1f40, 89, 0xB3A9AAD0);

// @0x141ac1fa0
void UIRewardNotify::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
}
MS2_REPLACE_METHOD(0x141ac1fa0, UIRewardNotify, vfunc_45, 54, 0xF5BC91C1);

// @0x141ac1fe0
void UIRewardNotify::FUN_141ac1fe0(MS2Ptr<AScript> pReward)
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity == 0 || FUN_1422b9e00(FUN_1408e57f0()) == 0x6200031 || m_block != 0) {
        m_queue.Add(pReward);
    } else {
        pEntity->Invoke("appendReward", pReward);
    }
}
MS2_REPLACE_METHOD(0x141ac1fe0, UIRewardNotify, FUN_141ac1fe0, 300, 0x2850DCE6);

// @0x141ac2120
void UIRewardNotify::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}
MS2_REPLACE_METHOD(0x141ac2120, UIRewardNotify, vfunc_41, 99, 0x7C80D96D);

void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);      // Value = the object's value
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned long long n);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// @0x141ac34b0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, MS2Ptr<AScript> a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bce40(args.FUN_1409b1f70(0), *a1.get());
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141ac3930
// MS2-FUNCTIONAL: exe ~UIRewardNotify stores no vftables (same as ~ASTooltip)
UIRewardNotify::~UIRewardNotify() {}

// @0x141ac3fb0
int UIRewardNotify::vfunc_48() { return 0x4e5d; }
MS2_REPLACE_METHOD(0x141ac3fb0, UIRewardNotify, vfunc_48, 11, 0x81757CC6);

// ---- UIFameContentsNotify ----

MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
void FUN_140762fc0(int nQuestId, int* pCurrent, int* pMax, CStringW& strPoint);
CStringW FUN_140762de0(int nQuestId);

// @0x141ac2190
UIFameContentsNotify::UIFameContentsNotify() : m_list(10)
{
    m_2c = 0x1f;
    FUN_140939a10()->FUN_140da4e40(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UIFameContentsNotify::FUN_141ac2790));
}

// @0x141ac22d0
UIFameContentsNotify::~UIFameContentsNotify()
{
    FUN_140939a10()->FUN_140da4eb0(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UIFameContentsNotify::FUN_141ac2790));
}

// @0x141ac23e0
CString UIFameContentsNotify::vfunc_1() { return "FameContentsNotify"; }
MS2_REPLACE_METHOD(0x141ac23e0, UIFameContentsNotify, vfunc_1, 61, 0x5B6B5C7B);

// @0x141ac2430
void UIFameContentsNotify::vfunc_2() { UIHeadUpDisplay::vfunc_2(); }
MS2_REPLACE_METHOD(0x141ac2430, UIFameContentsNotify, vfunc_2, 24, 0x50A843A8);

// @0x141ac2450
void UIFameContentsNotify::vfunc_3() { UIHeadUpDisplay::vfunc_3(); }
MS2_REPLACE_METHOD(0x141ac2450, UIFameContentsNotify, vfunc_3, 24, 0x9F56C308);

// @0x141ac2470
void UIFameContentsNotify::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    if (FUN_141ac27d0() == 0)
        vfunc_3();
}
MS2_REPLACE_METHOD(0x141ac2470, UIFameContentsNotify, OnLoadComplete, 54, 0x91E93973);

// @0x141ac24b0
void UIFameContentsNotify::vfunc_18()
{
    if (m_30.IsNull())
        return;
    m_30->Invoke("onUpdatePosition");
}
MS2_REPLACE_METHOD(0x141ac24b0, UIFameContentsNotify, vfunc_18, 87, 0xEB70FE28);

// @0x141ac2510
int UIFameContentsNotify::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onHideComplete") == 0) {
        m_list.RemoveHead();
        if (FUN_141ac27d0() == 0)
            vfunc_3();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141ac2510, UIFameContentsNotify, vfunc_28, 142, 0xEA30EA87);

// @0x141ac25b0
void UIFameContentsNotify::FUN_141ac25b0(int nQuestId)
{
    MS2Ptr<CQuestData> pQuest = FUN_14074bc40(nQuestId);
    if (pQuest.IsNull())
        return;
    std::pair<int, int> entry(pQuest->m_4c, 1);
    if (m_list.Find(entry) != 0)
        return;
    m_list.AddTail(entry);
    if (m_30.IsNull())
        vfunc_2();
}
MS2_REPLACE_METHOD(0x141ac25b0, UIFameContentsNotify, FUN_141ac25b0, 234, 0x433D9F6E);

// @0x141ac26a0
void UIFameContentsNotify::FUN_141ac26a0(int nQuestId)
{
    MS2Ptr<CQuestData> pQuest = FUN_14074bc40(nQuestId);
    if (pQuest.IsNull())
        return;
    std::pair<int, int> entry(pQuest->m_4c, 0);
    if (m_list.Find(entry) != 0)
        return;
    m_list.AddTail(entry);
    if (m_30.IsNull())
        vfunc_2();
}
MS2_REPLACE_METHOD(0x141ac26a0, UIFameContentsNotify, FUN_141ac26a0, 234, 0xC16B99F5);

// @0x141ac2790
void UIFameContentsNotify::FUN_141ac2790(NotifyObject* pNotice)
{
    if (m_list.GetCount() != 0)
        vfunc_2();
}
MS2_REPLACE_METHOD(0x141ac2790, UIFameContentsNotify, FUN_141ac2790, 57, 0xF67B0925);

// @0x141ac27d0
int UIFameContentsNotify::FUN_141ac27d0()
{
    if (m_list.GetCount() == 0)
        return 0;
    std::pair<int, int>& front = m_list.GetHead();
    int nId = front.first;
    int nKind = front.second;
    int nCurrent = 0;
    int nMax = 0;
    CStringW strPoint;
    FUN_140762fc0(nId, &nCurrent, &nMax, strPoint);
    CString strAlliance(nKind == 0 ? "Ending_" : "Opening_");
    strAlliance += FUN_14021a6b0(nId);
    CStringW strKey(nKind == 0 ? L"s_fame_contents_notify_ending" : L"s_fame_contents_notify_opening");
    ASObj o(2);
    o.FUN_1407cba60("alliance", strAlliance);
    o.FUN_1407cbb20("msg", FUN_1405c2690(strKey, FUN_140762de0(nId)));
    o.FUN_1407cb9c0("current", nCurrent);
    o.FUN_1407cb9c0("max", nMax);
    o.FUN_1407cbb20("point", strPoint);
    m_30->FUN_140acd1f0("addNotify", o);
    return 1;
}
MS2_REPLACE_METHOD(0x141ac27d0, UIFameContentsNotify, FUN_141ac27d0, 915, 0x363E9242);

// @0x141ac3fa0
int UIFameContentsNotify::vfunc_48() { return 0x4f5a; }
MS2_REPLACE_METHOD(0x141ac3fa0, UIFameContentsNotify, vfunc_48, 11, 0xE46FF48A);

// ---- UIRouletteDialog (a second source file fused into this unit: it includes the header statics again) ----

static CString s_strSortTypeNames_b[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill_b = "skill";
static CString s_strStun_b = "stun";
static Unk_1402a9d70 s_unk1402a9d70_b(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSpinMultiSelect = "spin_MultiSelect";
static CString s_strSpinMultiStart = "spin_MultiStart";
static CString s_strSpinSelect = "spin_Select";
static CString s_strSpinStart = "spin_Start";

// The root AS object of the roulette movie.
class ASDialog : public ASDisplayObject {
public:
    Scaleform::GFx::Value FUN_140f356e0(const char* szMethod, int nIndex, unsigned char bFlag);   // "spin"
    Scaleform::GFx::Value FUN_141ac65b0(const char* szMethod, CString strBind, unsigned long long nSlot, CString strName, int nRarity);   // "bind"
    void FUN_1407cb9c0(const char* szName, int n);
};

class Unk_RLPackets { public: void FUN_140da5180(int, Delegate<void(CInPacket&)>); void FUN_140da51e0(int, Delegate<void(CInPacket&)>); };
Unk_RLPackets* FUN_140bccd50();
class Unk_RLPlayerMgr { public: void* FUN_141bd0cc0(); };
Unk_RLPlayerMgr* FUN_1403ed2d0();
class Unk_RLSound { public: int FUN_1411a5a60(const CString& strName, const CString& strArg); void FUN_1411a6060(int hSound); };
Unk_RLSound* FUN_1403ed280();
class Unk_RLChat { public: void FUN_1416fb300(const CStringW& str); };
Unk_RLChat* FUN_1403b4750();
class Unk_RLRewardUI { public: int FUN_141b1d3d0(); void FUN_141b1ac40(ATL::CAtlArray<MS2Ptr<CItem> >& items, const CStringW& strTitle, int a, int b, int c); void FUN_141b1a8e0(const CStringW& str, const CString& a, const CString& b); };
Unk_RLRewardUI* FUN_140a7b2b0(int nId);
class Unk_RLHud { public: CStringW FUN_141b20ed0(); void FUN_141b21ae0(const CString& strName); void FUN_141b1feb0(); };
Unk_RLHud* FUN_140967100();
UIRewardNotify* FUN_140938cd0(int nId);
#include "ms2/commonfiles/commonutil.h"
void* FUN_14025e7c0();
unsigned char FUN_14116d720(void*);
void FUN_141415450(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, int nIconType, int nFlags);
void FUN_141415600(const CString& strBindID);
void* FUN_14052cd70(const MS2Ptr<CItem>& spItem);
void FUN_140710590(COutPacket&);
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);

// @0x141ac65b0
inline Scaleform::GFx::Value ASDialog::FUN_141ac65b0(const char* szMethod, CString strBind, unsigned long long nSlot, CString strName, int nRarity)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bce70(args.FUN_1409b1f70(0), strBind);
    FUN_1422bce00(args.FUN_1409b1f70(1), nSlot);
    FUN_1422bce70(args.FUN_1409b1f70(2), strName);
    FUN_1422bccb0(args.FUN_1409b1f70(3), nRarity);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141ac4920
UIRouletteDialog::UIRouletteDialog()
{
    m_2c = 0xc;
    m_178 = 0;
    FUN_140bccd50()->FUN_140da5180(0x7c, Delegate<void(CInPacket&)>(this, &UIRouletteDialog::FUN_141ac5e70));
}

// @0x141ac4a90
UIRouletteDialog::~UIRouletteDialog()
{
    FUN_140bccd50()->FUN_140da51e0(0x7c, Delegate<void(CInPacket&)>(this, &UIRouletteDialog::FUN_141ac5e70));
}

// @0x141ac4bd0
CString UIRouletteDialog::vfunc_1() { return "RouletteDialog"; }
MS2_REPLACE_METHOD(0x141ac4bd0, UIRouletteDialog, vfunc_1, 61, 0x67513A0F);

// @0x141ac4c20
int UIRouletteDialog::vfunc_65() { return UIDialog::vfunc_65() != 0; }

// @0x141ac4c50
void UIRouletteDialog::vfunc_67()
{
    for (size_t i = 0; i < m_binds.GetCount(); i++)
        FUN_141415600(m_binds[i]);
    m_binds.RemoveAll();
    if (m_30.IsNull())
        UIDialog::vfunc_67();
    else
        m_30->Invoke("hide");
    FUN_1403ed280()->FUN_1411a6060(m_hSound);
}
MS2_REPLACE_METHOD(0x141ac4c50, UIRouletteDialog, vfunc_67, 222, 0x62B94300);

// @0x141ac4d40
void UIRouletteDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_141ac5a30();
}
MS2_REPLACE_METHOD(0x141ac4d40, UIRouletteDialog, OnLoadInit, 34, 0x1E783064);

// @0x141ac4d70
void UIRouletteDialog::vfunc_43()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    Unk_RLRewardUI* pUI;
    int n;
    if (pDlg != 0 && (pUI = FUN_140a7b2b0(0x4e40)) != 0 && (n = pUI->FUN_141b1d3d0()) != -1) {
        pDlg->vfunc_2(1, 0, (n - pDlg->FUN_1422c13b0()) - 2);
        return;
    }
    pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->vfunc_2(1, 0, 0);
}
MS2_REPLACE_METHOD(0x141ac4d70, UIRouletteDialog, vfunc_43, 269, 0xCD6A52D0);

// @0x141ac4e90
void UIRouletteDialog::vfunc_15() {}

// @0x141ac4eb0
int UIRouletteDialog::vfunc_13() { return 0; }
MS2_REPLACE_METHOD(0x141ac4eb0, UIRouletteDialog, vfunc_13, 8, 0x7F371472);

// @0x141ac4ec0
int UIRouletteDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onSpinResult") == 0) {
        if (m_spins.GetCount() == 1)
            FUN_141276180(s_strSpinSelect, "");
        else
            FUN_141276180(s_strSpinMultiSelect, "");
    } else if (_stricmp(szMethod, "onSpinComplete") == 0) {
        if ((int)m_spins.GetCount() <= m_spinIndex)
            return 1;
        if (m_spins.GetCount() == 1) {
            UIRewardNotify* pReward = FUN_140938cd0(0x4e5d);
            if (pReward != 0)
                pReward->FUN_141abf6e0(m_spins[0].m_itemId, m_spins[0].m_rarity);
        } else {
            m_hSound = FUN_1403ed280()->FUN_1411a5a60(s_strSpinMultiStart, "");
        }
        ATL::CAtlArray<MS2Ptr<CItem> > items;
        MS2Ptr<CItem> item(new CItem);
        if (item->FUN_140523c40(m_spins[m_spinIndex].m_itemId, m_spins[m_spinIndex].m_rarity, 0)) {
            item->FUN_140526c70(m_spins[m_spinIndex].m_count);
            items.Add(item);
        }
        m_spinIndex++;
        if (m_spinIndex < (int)m_spins.GetCount()) {
            ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDlg != 0)
                pDlg->FUN_140f356e0("spin", m_spins[m_spinIndex].m_slot + 1, FUN_14116d720(FUN_14025e7c0()));
            CStringW strResult = FUN_140967100()->FUN_141b20ed0();
            CStringW strTitle = FUN_14028b8e0(L"s_roulette_reward");
            FUN_1403b4750()->FUN_1416fb300(strResult);
            FUN_1403b4750()->FUN_1416fb300(strTitle);
            Unk_RLRewardUI* pUI = FUN_140a7b2b0(0x4e40);
            if (pUI != 0) {
                if (items.GetCount() != 0)
                    pUI->FUN_141b1ac40(items, strTitle, 0, 0, 0);
                pUI->FUN_141b1a8e0(strResult, "", "");
            }
        } else {
            COutPacket packet(0x43, 0);
            packet.vfunc_o10_1(3);
            FUN_140710590(packet);
            vfunc_67();
        }
    } else if (_stricmp(szMethod, "onHideComplete") == 0) {
        UIDialog::vfunc_67();
        FUN_140967100()->FUN_141b1feb0();
    }
    return 0;
}

// @0x141ac5540
void UIRouletteDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    CString strName = pArgs->FUN_1422b8d30();
    if (FUN_140184310(strName, "resultItem")) {
        int nIndex = pArgs->FUN_1422b8b10() - 1;
        MS2Ptr<CItem> item(new CItem);
        if (item->FUN_14052b130(m_itemIds[nIndex], m_rarities[nIndex], 0)) {
            item->FUN_140526c70(m_counts[nIndex]);
            ASTooltip tooltip(pPlayer, 0x800, 2);
            if (tooltip.FUN_1409e0d40(item.get())) {
                *pRetVal = tooltip.FUN_1422bb870();
                return;
            }
        }
    }
    int nFound = strName.Find("slot_", 0);
    if (nFound != -1) {
        int nIndex = atoi(strName.Mid(nFound + 5)) - 1;
        MS2Ptr<CItem> item(new CItem);
        if (item->FUN_14052b130(m_itemIds[nIndex], m_rarities[nIndex], 0)) {
            item->FUN_140526c70(m_counts[nIndex]);
            ASTooltip tooltip(pPlayer, 0x800, 2);
            if (tooltip.FUN_1409e0d40(item.get())) {
                *pRetVal = tooltip.FUN_1422bb870();
                return;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141ac5540, UIRouletteDialog, vfunc_49, 1169, 0x1B141379);

// @0x141ac59e0
int UIRouletteDialog::FUN_141ac59e0() { return m_spinIndex; }
MS2_REPLACE_METHOD(0x141ac59e0, UIRouletteDialog, FUN_141ac59e0, 17, 0xA19D11F5);

// @0x141ac5a00
int UIRouletteDialog::FUN_141ac5a00() { return (int)m_spins.GetCount(); }
MS2_REPLACE_METHOD(0x141ac5a00, UIRouletteDialog, FUN_141ac5a00, 33, 0x13EDAFA4);

// @0x141ac5a30
void UIRouletteDialog::FUN_141ac5a30()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg == 0)
        return;
    if (m_itemIds.GetCount() != m_rarities.GetCount() || m_rarities.GetCount() != m_counts.GetCount() || m_itemIds.GetCount() != 0xc)
        return;
    for (int i = 0; i < 0xc; i++) {
        int nItemId = m_itemIds[i];
        unsigned nRarity = m_rarities[i];
        int nCount = m_counts[i];
        MS2Ptr<CItem> item(new CItem);
        if (item->FUN_140523c40(nItemId, nRarity, 0)) {
            item->FUN_140526c70(nCount);
            CString strBind;
            strBind.Format("%s_%d", (const char*)vfunc_1(), i + 1);
            FUN_141415450(strBind, item, i, 0x415, 0);
            pDlg->FUN_141ac65b0("bind", strBind, i + 1, item->FUN_140528590(), nCount);
            m_binds.Add(strBind);
        }
    }
    pDlg->FUN_1407cb9c0("selectedIndex", 1);
}
MS2_REPLACE_METHOD(0x141ac5a30, UIRouletteDialog, FUN_141ac5a30, 1071, 0x93B7D820);

#ifndef MS2_HOOK_DLL
// @0x141ac5e70
void UIRouletteDialog::FUN_141ac5e70(CInPacket& pkt)
{
    unsigned char nMode = pkt.vfunc_o8_1();
    if (nMode == 1) {
        if (FUN_141924630() == 0) {
            m_itemIds.RemoveAll();
            m_rarities.RemoveAll();
            m_counts.RemoveAll();
            m_1e0 = pkt.vfunc_o8_1();
            unsigned nCount = pkt.vfunc_o8_3();
            for (unsigned long long i = 0; i < nCount; i++) {
                int nItemId = pkt.vfunc_o8_3();
                unsigned nRarity = pkt.vfunc_o8_1();
                int nCnt = pkt.vfunc_o8_3();
                m_itemIds.Add(nItemId);
                m_rarities.Add(nRarity);
                m_counts.Add(nCnt);
            }
            m_178 = pkt.vfunc_o8_3();
            FUN_140967100()->FUN_141b21ae0("RouletteDialog");
        }
    } else if (nMode == 2 && FUN_141924630() != 0) {
        m_spinIndex = 0;
        m_spins.RemoveAll();
        int nCount = pkt.vfunc_o8_3();
        for (int i = 0; i < nCount; i++) {
            Unk_RouletteSpin spin;
            spin.m_slot = pkt.vfunc_o8_3();
            spin.m_itemId = pkt.vfunc_o8_3();
            spin.m_count = pkt.vfunc_o8_3();
            spin.m_rarity = (unsigned short)pkt.vfunc_o8_2();
            m_spins.Add(spin);
        }
        m_spinIndex = 0;
        if (m_spins.GetCount() != 0) {
            ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDlg != 0)
                pDlg->FUN_140f356e0("spin", m_spins[m_spinIndex].m_slot + 1, FUN_14116d720(FUN_14025e7c0()));
            if (m_spins.GetCount() == 1)
                m_hSound = FUN_1403ed280()->FUN_1411a5a60(s_strSpinStart, "");
            else
                m_hSound = FUN_1403ed280()->FUN_1411a5a60(s_strSpinMultiStart, "");
        }
    }
}
#endif

// @0x141ac6ad0
int UIRouletteDialog::vfunc_48() { return 0x4e6d; }
MS2_REPLACE_METHOD(0x141ac6ad0, UIRouletteDialog, vfunc_48, 11, 0xEBE9F8F6);
