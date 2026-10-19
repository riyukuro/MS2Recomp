// unit_140bd7e10.h - UIChangeJobDialog (RTTI .?AVUIChangeJobDialog@@, 0x1c8 bytes: UIDialog + the chosen job and a CAtlMap-shaped
// table), the job change window ("ChangeJobDialog", UI type 0x4f6b): it shows the job the player may change to (name,
// description, the movie and two skill lists with tooltips) and asks the server through the CChangeJobTable when "onChangeJob"
// arrives. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `unit_140bd7e10` (the exe has no path for it,
// the guess `?\uichangejobdialog.cpp` was rejected). Member names are invented from use.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h) with the IMessageListener at +0x18. Overridden slots: 1 (movie name),
// 22 (OnLoadComplete: show the player's next job), 28 (AS -> C++ commands), 48 (UI type 0x4f6b).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"

// +0x180 (0x48): a CAtlMap-shaped table (ctor 0x1401d7020, dtor 0x1401d73c0, out-of-unit COMDATs of ?\changejobtable.cpp).
class Unk_CjMap;
void FUN_1401d7020(Unk_CjMap* p, int nBins, float fOptimal, float fLow, float fHigh, int nBlock) noexcept;    // ctor
void FUN_1401d73c0(Unk_CjMap* p) noexcept;                                                                  // dtor
class Unk_CjMap
{
public:
    __int64 m_raw[9];
};
MS2_CHECK_SIZE(Unk_CjMap, 0x48);

class UIChangeJobDialog : public UIDialog
{
public:
    UIChangeJobDialog();                                                    // 0x140bd7e10
    virtual ~UIChangeJobDialog();                                           //  0 0x140bd7eb0 (??_G 0x140bd8b20)
    virtual CString vfunc_1();                                              //  1 0x140bd7f00 "ChangeJobDialog"
    virtual void OnLoadComplete();                                          // 22 0x140bd7f50
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140bd7fa0
    virtual int vfunc_48();                                                 // 48 0x140bd8b70: 0x4f6b

    void FUN_140bd8040(int nJobCode);                                       // 0x140bd8040 "setData": show the job
    int FUN_140bd88e0();                                                    // 0x140bd88e0 the player may change job now
    void FUN_140bd89d0(int nJobCode);                                       // 0x140bd89d0 announce the new job

private:
    MS2_LAYOUT_FRIEND;
    int m_nJobCode;                                                         // +0x178 the job shown
    Unk_CjMap m_map;                                                        // +0x180
};
MS2_CHECK_SIZE(UIChangeJobDialog, 0x1c8);
MS2_CHECK_OFFSET(UIChangeJobDialog, m_nJobCode, 0x178);
MS2_CHECK_OFFSET(UIChangeJobDialog, m_map, 0x180);
