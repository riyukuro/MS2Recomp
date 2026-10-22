// uihousemark.h - the house marks of the cube (UGC) map HUD: one world-anchored icon per salable house group, showing
// its sale state, the owner and the price, with a popup and a contract button. Recovered from uihousemark.cpp (file
// name assumed). Unk_ names are invented from local uses.
#pragma once

#include <afx.h>
#include <deque>
#include <map>
#include <NiPoint3.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/uiheadupdisplay.h"

class ASMovieClip;
class ASTextField;
class CMsgBoxData;
class Unk_140acd6e0;

// The house the cube service reports (its owner keeps it in an MS2Ptr; only these fields are read here).
struct Unk_HouseMarkInfo
{
    char m_pad_0000[0x18];
    int m_nId;                          // +0x18 the salable house group
    NiPoint3 m_pos;                     // +0x1c the world position of the mark
    char m_pad_0028[0x8];
    bool m_b30;                         // +0x30
};
MS2_CHECK_OFFSET(Unk_HouseMarkInfo, m_nId, 0x18);
MS2_CHECK_OFFSET(Unk_HouseMarkInfo, m_pos, 0x1c);
MS2_CHECK_OFFSET(Unk_HouseMarkInfo, m_b30, 0x30);

// The update interval timer (ctor 0x140517b00).
struct Unk_HouseMarkTimer
{
    Unk_HouseMarkTimer();
    int FUN_140268870(int nInterval);   // nonzero once the interval elapsed
    unsigned m_nTick;
    unsigned m_nExtra;
};
MS2_CHECK_SIZE(Unk_HouseMarkTimer, 8);

class UIHouseMarkEntity : public CPtred
{
public:
    UIHouseMarkEntity(const Unk_HouseMarkInfo& info);               // 0x14198aca0
    virtual ~UIHouseMarkEntity();                                   // 0 0x14198adc0 (??_G 0x14198f210)

    void FUN_14198ae60(MS2Ptr<ASMovieClip> spClip);                 // attach the movie clip and its button callbacks
    void FUN_14198b100();                                           // per-frame update
    bool FUN_14198b250();                                           // no clip yet
    int FUN_14198b290();                                            // the group id
    const NiPoint3& FUN_14198b2b0();                                // the world position
    bool FUN_14198b2d0();
    void FUN_14198b2f0();                                           // open the popup
    void FUN_14198b320();                                           // close the popup
    void FUN_14198b340();                                           // place the mark on the screen
    void FUN_14198b5b0();                                           // refresh the sale state from the cube service
    void FUN_14198b7b0();                                           // the debug text
    void FUN_14198b970();                                           // fill the popup's address
    void FUN_14198c0d0(bool bVisible);
    void FUN_14198c140(bool bPopup);
    void FUN_14198c210(int nIconType);
    void FUN_14198c370(int nProgress);
    bool IsPopup();                                           // the popup is open
    void FUN_14198c410();                                           // the button: contract terms, then the contract UI
    void FUN_14198c5a0();                                           // open the contract UI (0x4e76)
    void FUN_14198c610();                                           // show again after a reset
    void FUN_14198c670(const Scaleform::GFx::FunctionHandler::Params& params);    // click
    void FUN_14198c6a0(const Scaleform::GFx::FunctionHandler::Params& params);    // roll over
    void FUN_14198c6d0(const Scaleform::GFx::FunctionHandler::Params& params);    // roll out
    bool FUN_14198c700(int nResult, const CMsgBoxData& box);        // the terms message box result

private:
    MS2_LAYOUT_FRIEND;
    int m_nId;                          // +0x18 the salable house group
    NiPoint3 m_pos;                     // +0x1c
    bool m_b28;                         // +0x28
    bool m_bPopup;                      // +0x29
    int m_nPopupTick;                   // +0x2c the tick the popup opened at
    bool m_bReset;                      // +0x30 show again on the next update
    bool m_bVisible;                    // +0x31
    int m_nWaitingProgress;             // +0x34
    Unk_HouseMarkTimer m_timer;         // +0x38
    int m_nIconType;                    // +0x40 0 sale, 1 waiting, 2 my house, 3 open, 4 closed
    int m_n44;                          // +0x44
    MS2Ptr<ASMovieClip> m_clip;         // +0x48
    MS2Ptr<Unk_140acd6e0> m_btn;        // +0x58
    MS2Ptr<ASTextField> m_debugText;    // +0x68
};
MS2_CHECK_SIZE(UIHouseMarkEntity, 0x78);
MS2_CHECK_OFFSET(UIHouseMarkEntity, m_nId, 0x18);
MS2_CHECK_OFFSET(UIHouseMarkEntity, m_bReset, 0x30);
MS2_CHECK_OFFSET(UIHouseMarkEntity, m_timer, 0x38);
MS2_CHECK_OFFSET(UIHouseMarkEntity, m_clip, 0x48);
MS2_CHECK_OFFSET(UIHouseMarkEntity, m_debugText, 0x68);

class UIHouseMark : public UIHeadUpDisplay
{
public:
    UIHouseMark();                                                  // 0x14198c750
    virtual ~UIHouseMark();                                         // 0 0x14198c7f0
    virtual CString GetTypeName();                                      // 1 "HouseMark"
    virtual void vfunc_3();                                         // 3 hide: drop every mark
    virtual void vfunc_15();                                        // 15 update the marks, add one pending
    virtual void OnLoadComplete();                                  // 22
    virtual int vfunc_48() { return 0x4e88; }                       // 48 0x14198f260 (inline: emitted after ??_G)

    void FUN_14198cb00(const Unk_HouseMarkInfo& info);              // add a house
    void FUN_14198cc20(MS2Ptr<UIHouseMarkEntity> spEntity);         // create its movie clip
    MS2Ptr<UIHouseMarkEntity> FUN_14198ce50(const int& nId) const;  // the mark of a group
    void FUN_14198cf40();
    void FUN_14198cf50();                                           // vfunc_3

private:
    MS2_LAYOUT_FRIEND;
    void* m_70;                                                     // +0x70 not touched by this unit
    std::map<int, MS2Ptr<UIHouseMarkEntity> > m_entities;           // +0x78 by group id
    std::deque<MS2Ptr<UIHouseMarkEntity> > m_pending;               // +0x88 added before the movie loaded
};
MS2_CHECK_SIZE(UIHouseMark, 0xb0);
MS2_CHECK_OFFSET(UIHouseMark, m_entities, 0x78);
MS2_CHECK_OFFSET(UIHouseMark, m_pending, 0x88);
