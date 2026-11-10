// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Names of fields are invented.
#pragma once
#include <vector>
#include "ms2/placeholder/uiheadupdisplay.h"
class UIMicroGameCoupleDance : public UIHeadUpDisplay {
public:
    UIMicroGameCoupleDance();
    virtual CString GetTypeName();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_15();
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual void vfunc_41(const Scaleform::GFx::Value&);
    virtual void vfunc_43();
    // @0x140e65860
    virtual int vfunc_48() { return 0x4f70; }
    void Show(int mode, int time);
    void FUN_140e64270();
    void FUN_140e64590(int time);
    void Hide();
    void OnCoupleEvent(int event, struct Unk_CoupleEvent* data);
    void UpdatePosition();
    void SelectDance(int dance);
    void SendPlayArcade(int dance);
    void SendDanceSelection();
    void FUN_140e64e70();
    int ShouldHide();
    // @0x140b8be30
    void SetPrevious(int nPrevious) { m_previous = nPrevious; }
private:
    MS2_LAYOUT_FRIEND;
    int m_selected;
    std::vector<int> m_dances;
    int m_mode;
    int m_previous;
};
MS2_CHECK_SIZE(UIMicroGameCoupleDance, 0x98);
MS2_CHECK_OFFSET(UIMicroGameCoupleDance, m_selected, 0x70);
MS2_CHECK_OFFSET(UIMicroGameCoupleDance, m_dances, 0x78);
MS2_CHECK_OFFSET(UIMicroGameCoupleDance, m_mode, 0x90);
MS2_CHECK_OFFSET(UIMicroGameCoupleDance, m_previous, 0x94);
