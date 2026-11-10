// UIAdPushDialog (the advertisement push dialog that hosts the limited-time bundle ("limitedbundle") badges) and its
// entity classes AdPushEntityBase / AdPushEntityLimitedBundle. Names from the exe's RTTI; member names are inferred from
// the XML loaders ("rateX", "minimize", "endTime", ...). w175.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <set>
#include <NiPoint2.h>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uidialogeventdispatcher.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/intervaltimer.h"
#include "ms2/commonfiles/meratproductkey.h"   // C3: the product key (Unk_MeratProductKey::FUN_1409b0470)

class NotifyObject;
class ASMovieClip;
class ASDialog;
class UIAdPushLimitedDialog;
class AdPushEntityBase;
class CMeratMarketProduct;
class Unk_AdXmlNode;

// The limited-time bundle entry (entity kind 1). Its vftable follows the base: 1 Show, 2 Close(bool), 3 Remove, 4 Save,
// 5 Load, 6 GetName, 7 IsAccount, 8 Tooltip, 9 Tick, 10 IsFloating, 11 Maximize.
class AdPushEntityBase : public CPtred {
public:
    explicit AdPushEntityBase(const int& nId);                  // 0x140e424e0
    virtual bool vfunc_1() { return false; }
    virtual void vfunc_2(bool bRemove) {}
    virtual void vfunc_3() {}
    virtual void vfunc_4(Unk_AdXmlNode* pRoot, Unk_AdXmlNode* pNode) {}
    virtual void vfunc_5(Unk_AdXmlNode* pNode) {}
    virtual CStringA vfunc_6() { return ""; }
    virtual bool vfunc_7() { return false; }
    virtual void vfunc_8(Scaleform::GFx::Value* pValue, ASData* pData) {}
    virtual void vfunc_9() {}
    virtual bool vfunc_10() { return false; }
    virtual bool vfunc_11() { return true; }
    int GetKind() { return m_nKind; }
    int GetId() { return m_nId; }
    bool FUN_140e42580() { return m_bTick; }
protected:
    MS2_LAYOUT_FRIEND;
    int m_nId;                      // +0x18
    bool m_bTick;                   // +0x1c
    int m_nKind;                    // +0x20
};
MS2_CHECK_SIZE(AdPushEntityBase, 0x28);

// The market item (the pointee of the bundle's MS2Ptr at +0x58) is CMeratMarketProduct (meratmarketbasketinfo.h):
// the dialog reads m_key (+0x18) and its premium product m_premium (+0x30): m_nId "sn" (+0x48), m_nBuyLimit (+0xb8),
// m_nf4 (+0x124) and m_n104 (+0x134, the seconds the offer lasts).























class AdPushEntityLimitedBundle : public AdPushEntityBase {
    friend class UIAdPushDialog;
    friend class UIAdPushLimitedDialog;
public:
    explicit AdPushEntityLimitedBundle(const int& nId);         // 0x140e425a0
    virtual bool vfunc_1();
    virtual void vfunc_2(bool bRemove);
    virtual void vfunc_3();
    virtual void vfunc_4(Unk_AdXmlNode* pRoot, Unk_AdXmlNode* pNode);
    virtual void vfunc_5(Unk_AdXmlNode* pNode);
    virtual CStringA vfunc_6();
    virtual bool vfunc_7();
    virtual void vfunc_8(Scaleform::GFx::Value* pValue, ASData* pData);
    virtual void vfunc_9();
    virtual bool vfunc_10();
    virtual bool vfunc_11();
    void Reset();                                               // 0x140e42670
    void OnMaximize(const Scaleform::GFx::FunctionHandler::Params&);   // 0x140e42830
    void SetMinimized(bool b);                                  // 0x140e42a20
    bool UpdateRemainTime();                                    // 0x140e42a60
    void SetMaximizePos(float x, float y);                      // 0x140e42c90
    NiPoint2* GetMaximizePos();               // 0x140e42cd0
    void SetMarketItem(MS2Ptr<CMeratMarketProduct> p);             // 0x140e42cf0
    void Update(MS2Ptr<CMeratMarketProduct> p);                    // 0x140e42740
    void SetBadge(MS2Ptr<ASMovieClip> badge);                   // 0x140e42860
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<UIAdPushLimitedDialog> m_dlg;        // +0x28 the floating (maximized) dialog
    MS2Ptr<ASMovieClip> m_badge;                // +0x38 the badge movie clip in the push dialog
    bool m_bMinimized;                          // +0x48
    int m_n4c;                                  // +0x4c
    int m_n50;                                  // +0x50
    MS2Ptr<CMeratMarketProduct> m_item;            // +0x58
    bool m_bShowRemain;                         // +0x68
    __int64 m_endTime;                          // +0x70
    __int64 m_n78;                              // +0x78
    __int64 m_saleEndTime;                      // +0x80
    MS2Ptr<ASTextField> m_remain;               // +0x88 "m_remainTime"
    NiPoint2 m_max;                             // +0x98 where the maximized dialog opens
};
MS2_CHECK_SIZE(AdPushEntityLimitedBundle, 0xa0);

typedef ATL::CRBMap<int, MS2Ptr<AdPushEntityBase> > Unk_AdEntityMap;

class UIAdPushDialog : public UIDialog, public UIDialogEventDispatcher {
public:
    UIAdPushDialog();                                           // 0x140e3efd0
    virtual ~UIAdPushDialog();                                  // 0x140e3f140
    virtual CString GetTypeName();
    virtual int vfunc_4();
    virtual int vfunc_5();
    virtual int vfunc_48() { return 0x4f34; }
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual void vfunc_43();
    virtual void vfunc_44(int a1, int a2, int a3, int* pWidth, int* pHeight);
    virtual void vfunc_49(Scaleform::GFx::Value* pValue, ASData* pData);
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void vfunc_72();
    virtual void vfunc_76();
    bool AddBundle(MS2Ptr<CMeratMarketProduct> item, int n4c, int n50, bool bMinimized);   // 0x140e406c0
    bool RemoveEntityKey(const int& nId);                       // 0x140e409b0
    bool RemoveBundle(MS2Ptr<AdPushEntityLimitedBundle> bundle);    // 0x140e40a30
    bool Refresh(unsigned nFlags);                              // 0x140e40b20
    void UpdateBundles(MS2Ptr<CMeratMarketProduct> item);          // 0x140e40de0
    void OnNotifyGameEventChanged(NotifyObject* pNotify);       // 0x140e41000
    bool IsAnyAnimating();                                      // 0x140e41110
    bool MaximizeAll();                                         // 0x140e411d0
    Unk_AdXmlNode* FindLoadedEntry(const CStringA& strName, bool bAccount);   // 0x140e41280
    Unk_AdXmlNode* GetLoadedRoot(bool bAccount);                   // 0x140e41350
    Unk_AdXmlNode* FindSaveEntry(const CStringA& strName, bool bAccount);   // 0x140e413c0
    Unk_AdXmlNode* GetSaveRoot(bool bAccount);                 // 0x140e41430
    Unk_AdXmlNode* FindByName(Unk_AdXmlNode* pRoot, const CStringA& strName);   // 0x140e414a0
    CStringA GetStatePath();                                  // 0x140e41520
    CStringA GetAccountStatePath();                                  // 0x140e41610
    void OnNotifyCompleteMyPC(NotifyObject* pNotify);           // 0x140e416f0
    MS2Ptr<ASMovieClip> AddBadge(MS2Ptr<AScript> value);        // 0x140e41720
    bool RemoveBadge(MS2Ptr<ASMovieClip> badge);                // 0x140e41940
    bool RemoveEntityById(const int& nId);                      // 0x140e41a50
    bool LoadEntity(MS2Ptr<AdPushEntityBase> entity);           // 0x140e41b00
    void ShowOrRetry();                                         // 0x140e41c60
    void CloseAll();                                            // 0x140e41cc0
    void FindDirtyPos(float* pX, float* pY);                      // 0x140e41d80
    bool FindMinimizePos(float* pX, float* pY);                 // 0x140e41f30 (pY unused)
    void OnDirtyPos(const Scaleform::GFx::FunctionHandler::Params&);   // 0x140e42210
    void FixPosition();                                         // 0x140e42250
private:
    MS2_LAYOUT_FRIEND;
    Unk_AdEntityMap m_entities;                                 // +0x1a0 id -> entity
    Unk_AdEntityMap m_pending;                                  // +0x1d0 entities waiting for the saved state
    TiXmlDocument m_xmlLoaded;                                 // +0x200
    TiXmlDocument m_xmlSave;                                   // +0x270
    TiXmlDocument m_xmlAccountLoaded;                                 // +0x2e0
    TiXmlDocument m_xmlAccountSave;                            // +0x350
    int m_nFlags;                                               // +0x3c0
    int m_nShowState;                                           // +0x3c4
    Unk_IntervalTimer m_tick;                                   // +0x3c8
    MS2Ptr<ASDialog> m_limitedBundle;                           // +0x3d0
    std::set<int> m_sns;                                          // +0x3e0
};
MS2_CHECK_SIZE(UIAdPushDialog, 0x3f0);
MS2_CHECK_OFFSET(UIAdPushDialog, m_entities, 0x1a0);
MS2_CHECK_OFFSET(UIAdPushDialog, m_xmlLoaded, 0x200);
MS2_CHECK_OFFSET(UIAdPushDialog, m_nFlags, 0x3c0);
MS2_CHECK_OFFSET(UIAdPushDialog, m_limitedBundle, 0x3d0);
MS2_CHECK_OFFSET(UIAdPushDialog, m_sns, 0x3e0);
