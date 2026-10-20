// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: ?\uimainplayerinfo.cpp (header name assumed from
// the class name; the unit has no __FILE__ string).
//
// UIMainPlayerInfo is the HUD panel of the local player (UI type 0x4e5f, RTTI .?AVUIMainPlayerInfo@@, 0x240 bytes): the
// portrait clip "m_playerInfo" (HP / SP / EP bars, level, job, name with titles, riding state, the infinity tag), the
// buff strip "m_effectManager" (an ASEffectManager; buffs that arrive before the movie is loaded wait in m_pending),
// the skill / common shortkey slot bars ("SlotInfo.skill.0" in the slot manager) with their modified-key labels and
// shortkey page, and the ridee render target.
// It is a UIBuiltInDialog (0x178) and listens to status and item events: four vftables, the listener bases are
// 8-byte vptr-only sub-objects at +0x178 (UIStatusEventListener) and +0x180 (UIItemEventListener).
// Member names are invented where the exe has no name (vfunc_N / FUN_<va> otherwise).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/placeholder/uibuiltindialog.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/client/ms2/aseffect.h"

class CItem;
class NotifyObject;
class UIMsg;
class Unk_UISwfEntity_25;
class Unk_MpAchieve;
class Unk_MpSlot;

// The ridee avatar of the render target (an UIAvatarRidee, new 0xd8): 16-byte handle, pointer at +8.
class UIAvatarRidee;
class Unk_MpRideePtr
{
public:
    explicit Unk_MpRideePtr(int nNull);                     // 0x141314100
    Unk_MpRideePtr(UIAvatarRidee* p);                       // 0x141314120
    Unk_MpRideePtr(const Unk_MpRideePtr& o);                // 0x1413140d0 (uimeratmarketdialog.cpp)
    bool operator==(UIAvatarRidee* p) const;                // 0x141314e40 (uimeratmarketdialog.cpp)
    ~Unk_MpRideePtr();                                      // 0x1413146e0
    Unk_MpRideePtr& operator=(int nNull);                   // 0x1419f41d0
    Unk_MpRideePtr& AssignRaw(UIAvatarRidee* p);            // 0x1419f4200
    UIAvatarRidee* get() const;                             // 0x141314ec0
    UIAvatarRidee* operator->() const;                      // 0x141314f00
    void Release();                                         // 0x141316680
    void* m_0;
    UIAvatarRidee* m_p;
};
MS2_CHECK_SIZE(Unk_MpRideePtr, 0x10);

// The render-target camera of the ridee avatar (8-byte handle; the same COMDATs as Unk_PetBoxCameraPtr).
class Unk_MpCamera;
class Unk_MpCameraPtr
{
public:
    explicit Unk_MpCameraPtr(int nNull);                    // 0x14108aea0
    ~Unk_MpCameraPtr();                                     // 0x140cb1460
    Unk_MpCameraPtr& operator=(int nNull);                  // 0x14108b5b0
    Unk_MpCameraPtr& operator=(const Unk_MpCameraPtr& o);   // 0x1413149a0
    Unk_MpCamera* operator->() const;                       // 0x1409f7910
    Unk_MpCamera* m_p;
};
MS2_CHECK_SIZE(Unk_MpCameraPtr, 8);

class UIMainPlayerInfo : public UIBuiltInDialog,
                         public UIStatusEventListener,
                         public UIItemEventListener
{
public:
    UIMainPlayerInfo();                                                                             // 0x1419ee140
    virtual ~UIMainPlayerInfo();                                                                    //  0 0x1419ee5d0 (??_G 0x1419f4300)
    virtual CString vfunc_1();                                                                      //  1 0x1419eea30 "MainPlayerInfo"
    virtual int vfunc_13();                                                                         // 13 0x1419ef930 shortkey page keys
    virtual void vfunc_15();                                                                        // 15 0x1419ef820 per-frame update
    virtual void vfunc_16();                                                                        // 16 0x1419efcb0
    virtual bool vfunc_17();                                                                        // 17 0x1419efce0
    virtual void OnLoadInit();                                                                      // 20 0x1419eed40
    virtual void OnLoadComplete();                                                                  // 22 0x1419ef110
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);              // 25 0x1419efa60 render target
    virtual void vfunc_26();                                                                        // 26 0x1419ef330
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419ef5f0
    virtual void vfunc_43();                                                                        // 43 0x1419ef370
    virtual int vfunc_48() { return 0x4e5f; }                                                        // 48 0x1419f4800
    virtual int vfunc_53(void* pCfg);                                                               // 53 0x1419eeb20 save
    virtual int vfunc_54(void* pCfg);                                                               // 54 0x1419eeb80 load
    virtual int vfunc_65();                                                                         // 65 0x1419eebe0
    virtual void vfunc_67();                                                                        // 67 0x1419eec10 close
    // IMessageListener (+0x18)
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);                                      // o18 0 0x1419ef400
    // UIStatusEventListener (+0x178)
    virtual int vfunc_oa0_1();                                                                      // o178 1 0x1419eead0
    virtual void vfunc_oa0_3(int nCur, int nMax);                                                   // o178 3 0x1419efec0 HP
    virtual void vfunc_oa0_4(int nCur, int nMax);                                                   // o178 4 0x1419effe0 SP
    virtual void vfunc_oa0_5(int nCur, int nMax);                                                   // o178 5 0x1419f00d0 EP
    virtual void vfunc_oa0_7(int nJob, CStringW s);                                                 // o178 7 0x1419efd30
    virtual void vfunc_oa0_8(CStringW s);                                                           // o178 8 0x1419efe00
    virtual void vfunc_oa0_9(unsigned short nLevel);                                                // o178 9 0x1419efe50
    virtual void vfunc_oa0_20(int bRiding);                                                         // o178 20 0x1419f0460
    virtual void vfunc_oa0_24(int n);                                                               // o178 24 0x1419f01f0
    virtual void vfunc_oa0_25(void* p);                                                             // o178 25 0x1419f0280
    virtual void vfunc_oa0_26(void* p);                                                             // o178 26 0x1419f0320
    virtual void vfunc_oa0_27(int a1, int a2);                                                      // o178 27 0x1419f03c0
    // UIItemEventListener (+0x180)
    virtual int vfunc_il1();                                                                        // o180 1 0x1419eea80
    virtual void vfunc_2(void* pItem);                                                              // o180 2 0x1419f09e0
    virtual void vfunc_3(void* pItem, bool b);                                                      // o180 3 0x1419f0a80
    virtual void vfunc_4(void* pItem, int n);                                                       // o180 4 0x1419f0b10
    virtual void vfunc_21(void* pItem);                                                             // o180 21 0x1419f0960
    virtual void vfunc_22(void* pItem);                                                             // o180 22 0x1419f09a0
    virtual void vfunc_33(int nClassId, int);                                                       // o180 33 0x1419f0b70

    // ---- non-virtual members, sorted by address ----
    void FUN_1419f0bb0(Unk_MpAchieve* pAchieve);
    void FUN_1419f0ef0(const CStringW& strMessage, const CString& strType);
    void FUN_1419f0fe0(MS2Ptr<Unk_AsBuff> spBuff);
    void FUN_1419f10b0(MS2Ptr<Unk_AsBuff> spBuff);
    void FUN_1419f1180(int nBuffId);
    void FUN_1419f1200(int nId, int nLevel);
    void FUN_1419f1370(int nId);
    void FUN_1419f13b0(int bInfinity, int bForce);
    void FUN_1419f14b0(NotifyObject* pNotify);
    void FUN_1419f14e0(NotifyObject* pNotify);
    void FUN_1419f1580(NotifyObject* pNotify);
    void FUN_1419f1600();
    int FUN_1419f16b0();
    void FUN_1419f1820();
    void FUN_1419f1880(int bBattle);
    void FUN_1419f18f0();
    void FUN_1419f19c0();
    void FUN_1419f1c80();
    void FUN_1419f1d10(unsigned int nMask, bool bShow);
    void FUN_1419f1da0(int nSlot);
    void FUN_1419f1e60();
    void FUN_1419f21b0();
    void FUN_1419f22a0(int nKey, int bPress);
    void FUN_1419f24f0(int nPage);
    void FUN_1419f2560(bool bForce);
    void FUN_1419f26b0(bool bEnable);
    void FUN_1419f2720(bool bHideAndSeek);
    Unk_MpSlot* FUN_1419f27e0(CItem* pItem);
    Unk_MpSlot* FUN_1419f2930(int nIndex);
    int FUN_1419f29c0();
    void FUN_1419f2a90();
    int FUN_1419f2b60();
    void FUN_1419f2d90(CItem* pItem);
    void FUN_1419f2e10(CItem* pItem);
    void FUN_1419f2e60(CItem* pItem);
    void FUN_1419f2eb0();
    CString FUN_1419f31f0();
    void FUN_1419f3280();
    void FUN_1419f32f0();
    void FUN_1419f3370();
    int FUN_1419f3400(int nId);
    CStringW FUN_1419f3420();
    void FUN_1419f3590();
    bool FUN_1419f3630();
    bool FUN_1419f36c0();
    void FUN_1419f3740();

private:
    MS2_LAYOUT_FRIEND;

    MS2Ptr<ASUIComponent> m_playerInfo;                 // +0x188 "m_playerInfo"
    MS2Ptr<ASEffectManager> m_effectManager;            // +0x198 "m_effectManager"
    ATL::CAtlMap<int, MS2Ptr<Unk_AsBuff> > m_pending;   // +0x1a8 buff id -> buff, kept until the strip is bound
    int m_nHP[2];                                       // +0x1f0 [0] current, [1] max
    int m_nSP[2];                                       // +0x1f8
    int m_nEP[2];                                       // +0x200
    CString m_strSlotName;                              // +0x208 "SlotInfo.skill"
    int m_nLastTick;                                    // +0x210 last cooldown refresh (ms)
    int m_bInfinity;                                    // +0x214
    int m_bSkillMinimize;                               // +0x218 "skillMinimize"
    int m_bCommonMinimize;                              // +0x21c "commonMinimize"
    int m_nSlotMode;                                    // +0x220 1 = riding / hide and seek slot mode
    unsigned int m_nHideMask;                           // +0x224 reasons to hide the panel (0 = shown)
    Unk_MpRideePtr m_ridee;                             // +0x228
    Unk_MpCameraPtr m_camera;                           // +0x238
};
MS2_CHECK_SIZE(UIMainPlayerInfo, 0x240);
MS2_CHECK_OFFSET(UIMainPlayerInfo, m_playerInfo, 0x188);
MS2_CHECK_OFFSET(UIMainPlayerInfo, m_effectManager, 0x198);
MS2_CHECK_OFFSET(UIMainPlayerInfo, m_pending, 0x1a8);
MS2_CHECK_OFFSET(UIMainPlayerInfo, m_nHP, 0x1f0);
MS2_CHECK_OFFSET(UIMainPlayerInfo, m_strSlotName, 0x208);
MS2_CHECK_OFFSET(UIMainPlayerInfo, m_nSlotMode, 0x220);
MS2_CHECK_OFFSET(UIMainPlayerInfo, m_ridee, 0x228);
MS2_CHECK_OFFSET(UIMainPlayerInfo, m_camera, 0x238);
