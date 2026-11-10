// cinematiccomponent.h - the talk-cinematic components of ?\cinematiccomponent.cpp (0x14107ce50-0x141083230):
// CCinematicComponent (RTTI, base CPtred) and its 20 derived classes. One component drives one page of the
// NPC talk UI (UITalkCinematic): vfunc_2 handles a UI message (0x493e2 = the confirm key), vfunc_5 fills the AS page
// object. Header name assumed from the unit path; the class names are the RTTI names.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cinematiccontent.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/questdata.h"

class UITalkCinematic;
void* FUN_141082c00(void* p, unsigned flags);       // the icon entry's deleting destructor (called with 0 by the array)

// A distractor entry of the page: the icon class and the shown text. 16 bytes.
struct Unk_CinIcon
{
    CString m_icon;
    CStringW m_text;
    Unk_CinIcon();
    Unk_CinIcon(const Unk_CinIcon& o);
    ~Unk_CinIcon();
};
MS2_CHECK_SIZE(Unk_CinIcon, 0x10);

// The array of entries. Not the VS2019 CAtlArray: the exe's GrowBuffer grows by max/2 and the relocation goes
// through ATL::Checked::memmove_s.
class Unk_CinIconArray
{
public:
    Unk_CinIconArray();                                         // @0x141082390
    ~Unk_CinIconArray() throw();                                     // @0x141082570
    size_t Add(const Unk_CinIcon& e);                           // @0x141082c40
    size_t GetCount() const;                                    // @0x141082d50
    Unk_CinIcon& GetAt(size_t i) const;                         // @0x141082640 (checked)
    bool GrowBuffer(size_t nNewSize);                           // @0x141082ed0
private:
    Unk_CinIcon* m_pData;
    size_t m_nSize;
    size_t m_nMaxSize;
    int m_nGrowBy;
};
MS2_CHECK_SIZE(Unk_CinIconArray, 0x20);

// Slots: 0 dtor, 1 (selection), 2 (message), 3 (type id), 4 (set content), 5 (fill the page).
class CCinematicComponent : public CPtred
{
public:
    CCinematicComponent(UITalkCinematic* pOwner);               // 0x14107ce50
    virtual ~CCinematicComponent();                             // 0x14107cec0
    virtual void vfunc_1(int nSelect);                          // 1  0x141083070
    virtual int vfunc_2(int nMsg);                              // 2  0x14107cf00
    virtual int vfunc_3();                                      // 3  0x141082d80
    virtual void vfunc_4(MS2Ptr<CCinematicContent> spContent);  // 4  0x1410830c0
    virtual void vfunc_5(ASObj& obj);                           // 5  0x14107cf90

    void FillRewardItems(const ATL::CAtlArray<CQuestData::QuestRewardItem>& rewards, ASObj& obj);   // reward icons of the quest page
    unsigned FillTalkReward(ASObj& obj);                         // the open-talk reward block; nonzero when one was shown
    CStringW FUN_14107dfa0(int nStringId);                      // button text with the key names filled in

    UITalkCinematic* m_pOwner;                                  // +0x18
    MS2Ptr<CCinematicContent> m_spContent;                      // +0x20
    int m_nStarted;                                             // +0x30
};
MS2_CHECK_SIZE(CCinematicComponent, 0x38);
MS2_CHECK_OFFSET(CCinematicComponent, m_pOwner, 0x18);
MS2_CHECK_OFFSET(CCinematicComponent, m_spContent, 0x20);
MS2_CHECK_OFFSET(CCinematicComponent, m_nStarted, 0x30);

// "Next" button page; m_nReward is the result of the reward block (nonzero = a reward was shown).
class CNextCinematicComponent : public CCinematicComponent
{
public:
    CNextCinematicComponent(UITalkCinematic* pOwner);           // 0x14107e190
    virtual ~CNextCinematicComponent();                         // 0x14107e1d0
    virtual int vfunc_2(int nMsg);                              // 0x14107e200
    virtual int vfunc_3();                                      // 0x141082de0
    virtual void vfunc_5(ASObj& obj);                           // 0x14107e2d0
    int m_nReward;                                              // +0x38
};

class CCloseCinematicComponent : public CCinematicComponent
{
public:
    CCloseCinematicComponent(UITalkCinematic* pOwner);          // 0x14107e350
    virtual ~CCloseCinematicComponent();                        // 0x14107e390
    virtual int vfunc_2(int nMsg);                              // 0x14107e3c0
    virtual int vfunc_3();                                      // 0x141082d90
    virtual void vfunc_5(ASObj& obj);                           // 0x14107e480
    int m_nReward;                                              // +0x38
};

class CDistractorCinematicComponent : public CCinematicComponent
{
public:
    CDistractorCinematicComponent(UITalkCinematic* pOwner);     // 0x14107e500
    virtual ~CDistractorCinematicComponent();                   // 0x14107e540
    virtual int vfunc_2(int nMsg);                              // 0x14107e570
    virtual int vfunc_3();                                      // 0x141082db0
    virtual void vfunc_6(const Unk_CinIconArray& icons, ASObj& obj);   // 6  0x14107e600
};

class CQuestAcceptCinematicComponent : public CCinematicComponent
{
public:
    CQuestAcceptCinematicComponent(UITalkCinematic* pOwner);    // 0x14107e7f0
    virtual ~CQuestAcceptCinematicComponent();                  // 0x14107e830
    virtual int vfunc_2(int nMsg);                              // 0x14107e860
    virtual int vfunc_3();                                      // 0x141082e00
    virtual void vfunc_5(ASObj& obj);                           // 0x14107ebd0
    bool OnMsgBoxResult(int nButton, const class CMsgBoxData& data);   // alliance warning box result
    void SendQuestAccept(int nQuestId, bool bRedirect);           // send the accept request
};

class CQuestProgressCinematicComponent : public CCloseCinematicComponent
{
public:
    CQuestProgressCinematicComponent(UITalkCinematic* pOwner);  // 0x14107edf0
    virtual ~CQuestProgressCinematicComponent();                // 0x14107ee30
    virtual int vfunc_2(int nMsg);                              // 0x14107ee60
    virtual int vfunc_3();                                      // 0x141082e20
};

class CQuestCompleteCinematicComponent : public CCinematicComponent
{
public:
    CQuestCompleteCinematicComponent(UITalkCinematic* pOwner);  // 0x14107ef90
    virtual ~CQuestCompleteCinematicComponent();                // 0x14107efd0
    virtual int vfunc_2(int nMsg);                              // 0x14107f000
    virtual int vfunc_3();                                      // 0x141082e10
    virtual void vfunc_5(ASObj& obj);                           // 0x14107f270
};

class CSelectableDistractorCinematicComponent : public CDistractorCinematicComponent
{
public:
    CSelectableDistractorCinematicComponent(UITalkCinematic* pOwner);   // 0x14107f7b0
    virtual ~CSelectableDistractorCinematicComponent();         // 0x14107f7f0
    virtual void vfunc_1(int nSelect);                          // 0x14107f820
    virtual int vfunc_3();                                      // 0x141082e60
    virtual void vfunc_5(ASObj& obj);                           // 0x14107f850
};

class CCustomSelectableDistractorCinematicComponent : public CSelectableDistractorCinematicComponent
{
public:
    CCustomSelectableDistractorCinematicComponent(UITalkCinematic* pOwner);   // 0x14107fac0
    virtual ~CCustomSelectableDistractorCinematicComponent();   // 0x14107fb00
    virtual void vfunc_1(int nSelect);                          // 0x14107fb30
    virtual int vfunc_3();                                      // 0x141082da0
};

class CSelectableBeautyCinematicComponent : public CSelectableDistractorCinematicComponent
{
public:
    CSelectableBeautyCinematicComponent(UITalkCinematic* pOwner);   // 0x14107fbb0
    virtual ~CSelectableBeautyCinematicComponent();             // 0x14107fbf0
    virtual void vfunc_1(int nSelect);                          // 0x14107fc20
    virtual int vfunc_3();                                      // 0x141082e50
    virtual void vfunc_5(ASObj& obj);                           // 0x14107fc50
};

class CSelectableTalkCinematicComponent : public CDistractorCinematicComponent
{
public:
    CSelectableTalkCinematicComponent(UITalkCinematic* pOwner); // 0x14107fc80
    virtual ~CSelectableTalkCinematicComponent();               // 0x14107fcc0
    virtual void vfunc_1(int nSelect);                          // 0x14107fcf0
    virtual int vfunc_3();                                      // 0x141082e70
    virtual void vfunc_5(ASObj& obj);                           // 0x14107fd20
};

// Job change page; the IMessageListener subobject (+0x38) receives the confirmation box result.
class CChangeJobComponent : public CDistractorCinematicComponent, public IMessageListener
{
public:
    CChangeJobComponent(UITalkCinematic* pOwner);               // 0x1410805b0
    virtual ~CChangeJobComponent();                             // 0x141080610
    virtual int vfunc_2(int nMsg);                              // 0x141080680
    virtual int vfunc_3();                                      // 0x141082d70
    virtual void vfunc_5(ASObj& obj);                           // 0x141080890
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener slot 0  0x141080780
};
MS2_CHECK_OFFSET(CChangeJobComponent, m_nStarted, 0x30);

class CUgcSignCinematicComponent : public CCinematicComponent
{
public:
    CUgcSignCinematicComponent(UITalkCinematic* pOwner);        // 0x141080900
    virtual ~CUgcSignCinematicComponent();                      // 0x141080940
    virtual int vfunc_2(int nMsg);                              // 0x141080970
    virtual int vfunc_3();                                      // 0x141082eb0
    virtual void vfunc_5(ASObj& obj);                           // 0x141080c20
};

class CPaneltyResolveCinematicComponent : public CCinematicComponent
{
public:
    CPaneltyResolveCinematicComponent(UITalkCinematic* pOwner); // 0x141080c90
    virtual ~CPaneltyResolveCinematicComponent();               // 0x141080cd0
    virtual int vfunc_2(int nMsg);                              // 0x141080d00
    virtual int vfunc_3();                                      // 0x141082df0
    virtual void vfunc_5(ASObj& obj);                           // 0x141080f10
};

class CHomeDoctorCinematicComponent : public CCinematicComponent
{
public:
    CHomeDoctorCinematicComponent(UITalkCinematic* pOwner);     // 0x141080f80
    virtual ~CHomeDoctorCinematicComponent();                   // 0x141080fc0
    virtual int vfunc_2(int nMsg);                              // 0x141080ff0
    virtual int vfunc_3();                                      // 0x141082dd0
    virtual void vfunc_5(ASObj& obj);                           // 0x1410811e0
};

class CTakeBoatCinematicComponent : public CCinematicComponent
{
public:
    CTakeBoatCinematicComponent(UITalkCinematic* pOwner);       // 0x141081250
    virtual ~CTakeBoatCinematicComponent();                     // 0x141081290
    virtual int vfunc_2(int nMsg);                              // 0x1410812c0
    virtual int vfunc_3();                                      // 0x141082ea0
    virtual void vfunc_5(ASObj& obj);                           // 0x1410813a0
};

class CSellUGCMapCinematicComponent : public CCinematicComponent
{
public:
    CSellUGCMapCinematicComponent(UITalkCinematic* pOwner);     // 0x141081410
    virtual ~CSellUGCMapCinematicComponent();                   // 0x141081450
    virtual int vfunc_2(int nMsg);                              // 0x141081480
    virtual int vfunc_3();                                      // 0x141082e80
    virtual void vfunc_5(ASObj& obj);                           // 0x141081530
};

class CRouletteCinematicComponent : public CCinematicComponent
{
public:
    CRouletteCinematicComponent(UITalkCinematic* pOwner);       // 0x1410815a0
    virtual ~CRouletteCinematicComponent();                     // 0x1410815f0
    virtual int vfunc_2(int nMsg);                              // 0x141081620
    virtual int vfunc_3();                                      // 0x141082e30
    virtual void vfunc_5(ASObj& obj);                           // 0x1410816c0
    int m_nSent;                                                // +0x38
};

class CRouletteSkipCinematicComponent : public CCloseCinematicComponent
{
public:
    CRouletteSkipCinematicComponent(UITalkCinematic* pOwner);   // 0x141081730
    virtual ~CRouletteSkipCinematicComponent();                 // 0x141081770
    virtual int vfunc_3();                                      // 0x141082e40
    virtual void vfunc_5(ASObj& obj);                           // 0x1410817a0
};

class CEmptyCinematicComponent : public CCinematicComponent
{
public:
    CEmptyCinematicComponent(UITalkCinematic* pOwner);          // 0x141081810
    virtual ~CEmptyCinematicComponent();                        // 0x141081850
    virtual int vfunc_2(int nMsg);                              // 0x141081880
    virtual int vfunc_3();                                      // 0x141082dc0
    virtual void vfunc_5(ASObj& obj);                           // 0x1410818a0
};

class CStopCinematicComponent : public CCinematicComponent
{
public:
    CStopCinematicComponent(UITalkCinematic* pOwner);           // 0x1410818d0
    virtual ~CStopCinematicComponent();                         // 0x141081910
    virtual int vfunc_2(int nMsg);                              // 0x141081940
    virtual int vfunc_3();                                      // 0x141082e90
    virtual void vfunc_5(ASObj& obj);                           // 0x141081980
};
