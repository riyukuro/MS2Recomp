// uiadpushlimiteddialog.h - UIAdPushLimitedDialog (RTTI .?AVUIAdPushLimitedDialog@@, base UIDialog; 0x1c8 bytes): the
// floating (maximized) window of a limited-time merat market bundle offer shown by the advertisement push dialog. Recovered
// from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed, member names invented. Ctor 0x140e01f50 (operator new
// 0x1c8 in AdPushEntityLimitedBundle::GetTypeName, unit_140e3efd0.cpp), dtor 0x140e02060 (deleting dtor 0x140e04d80). The
// definitions belong to unit `?\uiadpushlimiteddialog.cpp`; only the layout is declared here so other units can use the type.
//
// The dialog is created and owned by an AdPushEntityLimitedBundle (m_owner is the back pointer). Its movie holds a product
// clip ("m_limitedRenderer" inside "m_maxComp") that shows the offer; the buy button builds a purchase request through the
// merat market (FUN_140e039c0), either a bill dialog (TMeratMarketBillDataParam) or a direct CMeratMarketBuy.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/shopbannerinfo.h"
#include "ms2/client/ms2/tmeratmarketbilldataparam.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ascript.h"

class ASData;
class ASDialog;
class ASUIComponent;
class AdPushEntityLimitedBundle;
class Unk_CadGiftClip;
class UIMsg;
class UISwfEntity;

class UIAdPushLimitedDialog : public UIDialog
{
public:
    UIAdPushLimitedDialog();                                        // 0x140e01f50
    virtual ~UIAdPushLimitedDialog();                               //  0 0x140e02060 (??_G 0x140e04d80)
    virtual CString GetTypeName();                                      //  1 0x140e020f0 "AdPushLimitedDialog"
    virtual int vfunc_5();                                          //  5 0x140e02ce0 restore the saved window position
    virtual void OnLoadComplete();                                  // 22 0x140e02140 send initData (the offer product row)
    virtual void vfunc_26();                                        // 26 0x140e02590 drop the members
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e02890 onClickBuy / onClickMinMax
    virtual void vfunc_43();                                        // 43 0x140e03010 keep the window on screen / float it
    virtual int vfunc_48();                                         // 48 0x140e04dc0 returns 0x4f35
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140e02e90 getTooltip (the offer's item)
    virtual int vfunc_52();                                         // 52 0x140e02720 returns 1
    virtual int vfunc_54(void* pCfg);                               // 54 0x140e02c50 move to the owner's maximized position
    virtual void vfunc_67();                                        // 67 0x140e02740 Close: remember the position
    virtual void vfunc_69();                                        // 69 0x140e02fc0 minimize instead of closing
    virtual void vfunc_77();                                        // 77 0x140e02620 end of the move: remember the position
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // IMessageListener 0 0x140e02a10 "setImgPath"

    void FUN_140e03440(MS2Ptr<AdPushEntityLimitedBundle> spOwner);  // 0x140e03440 bind the owner, look up the banner (the callee releases spOwner)
    void FUN_140e036e0(CStringA strA, CStringA strImgPath, bool bUnused);   // 0x140e036e0 a banner image arrived (strings destroyed by the callee)
    void FUN_140e039c0(const CStringA& strMethod, ASData& data);    // 0x140e039c0 the buy button
    MS2Ptr<TMeratMarketBillDataParam> FUN_140e04070(const CStringA& strMovie, int nType, int nSource);   // 0x140e04070 build the bill dialog's argument block
    bool FUN_140e04350(MS2Ptr<TMarketBillDataParam> spParam, const TMarketBillDataParam::PaymentMap& mapPay);   // 0x140e04350 buy callback
    bool FUN_140e043e0(Scaleform::GFx::Value* pRetVal, ASData& data, MS2Ptr<TMarketBillDataParam> spParam);     // 0x140e043e0 tooltip callback
    void FUN_140e04460(bool bMinimize);                             // 0x140e04460 minimize / restore the owner
    bool FUN_140e044b0();                                           // 0x140e044b0 open (unless a banner image is pending)
    int FUN_IsFloating() { return m_bFloating; }                    // inlined by AdPushEntityLimitedBundle::vfunc_10 (name invented)

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ShopBannerInfo> m_spBanner;                              // +0x178 the running banner of the offer
    bool m_bBannerEmpty;                                            // +0x188 the banner had no image yet
    MS2Ptr<Unk_CadGiftClip> m_spRenderer;                            // +0x190 "m_limitedRenderer" (inside m_maxComp; the gift row clip class of uicashattenddialog.cpp)
    MS2Ptr<ASUIComponent> m_spMaxComp;                              // +0x1a0 "m_maxComp"
    MS2Ptr<AdPushEntityLimitedBundle> m_spOwner;                    // +0x1b0 the bundle that owns this window
    bool m_bFloating;                                               // +0x1c0 positioned by the owner (maximized)
};
MS2_CHECK_SIZE(UIAdPushLimitedDialog, 0x1c8);
MS2_CHECK_OFFSET(UIAdPushLimitedDialog, m_spBanner, 0x178);
MS2_CHECK_OFFSET(UIAdPushLimitedDialog, m_bBannerEmpty, 0x188);
MS2_CHECK_OFFSET(UIAdPushLimitedDialog, m_spRenderer, 0x190);
MS2_CHECK_OFFSET(UIAdPushLimitedDialog, m_spMaxComp, 0x1a0);
MS2_CHECK_OFFSET(UIAdPushLimitedDialog, m_spOwner, 0x1b0);
MS2_CHECK_OFFSET(UIAdPushLimitedDialog, m_bFloating, 0x1c0);
