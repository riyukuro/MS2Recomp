// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uirandomcoupon.h (name assumed: the
// .cpp's __FILE__ string is not in the exe for this unit).
//
// UIRandomCoupon ("RandomCoupon", UI type 0x4f99, RTTI .?AVUIRandomCoupon@@, 0xa0 bytes): the random coupon draw
// HUD (the sale pick / payback pick animation of the Merat market's random coupon). It shows the picked product
// and, once the button shows ("onButtonShow"), hands the product to the Merat market dialog. Names: virtuals are
// Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiheadupdisplay.h"

class Unk_RcProduct;                                                // the picked product (a CPtred)
class CMeratMarketProduct;

class UIRandomCoupon : public UIHeadUpDisplay
{
public:
    UIRandomCoupon();                                               // 0x140bfe4b0 (m_2c = 0x23)
    virtual ~UIRandomCoupon();                                      //  0 0x140bfe590 (??_G 0x140bfeef0)
    virtual CString vfunc_1();                                      //  1 0x140bfe600 "RandomCoupon"
    virtual void vfunc_2();                                         //  2 0x140bfea40 show: the sound, the layer
    virtual void vfunc_3();                                         //  3 0x140bfea90 hide and reset
    virtual int vfunc_13();                                         // 13 0x140bfe930 close key: play the close
    virtual void OnLoadComplete();                                  // 22 0x140bfe650 push the pick to the movie
    virtual void vfunc_26();                                        // 26 0x140bfe7c0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140bfe7e0
    virtual void vfunc_43();                                        // 43 0x140bfe9e0 align the movie
    virtual int vfunc_48() { return 0x4f99; }                       // 48 0x140bfef30 UI type id

    void FUN_140bfeae0();                                           // reset the pick
    void FUN_140bfeb50(int nMode, int nA, int nB, CStringW strName);   // set the pick (nMode 0: nothing) and show
    void FUN_140bfebf0(MS2Ptr<Unk_RcProduct> spProduct);            // the picked product
    void FUN_140bfebf0(MS2Ptr<CMeratMarketProduct> spProduct);      // 0x140bfebf0 typed with the recovered class (meratmarketman.cpp)
    void FUN_140bfec40();                                           // play the sound of the coupon (m_78)

private:
    MS2_LAYOUT_FRIEND;
    int m_nMode;                                                    // +0x70 1: payback pick, else sale pick
    int m_nA;                                                       // +0x74
    int m_nCoupon;                                                  // +0x78 coupon kind 1..3
    CStringW m_strName;                                             // +0x80
    MS2Ptr<Unk_RcProduct> m_spProduct;                              // +0x88
    char m_bButtonShown;                                            // +0x98
    char m_pad_99[7];
};
MS2_CHECK_SIZE(UIRandomCoupon, 0xa0);
MS2_CHECK_OFFSET(UIRandomCoupon, m_nMode, 0x70);
MS2_CHECK_OFFSET(UIRandomCoupon, m_strName, 0x80);
MS2_CHECK_OFFSET(UIRandomCoupon, m_spProduct, 0x88);
MS2_CHECK_OFFSET(UIRandomCoupon, m_bButtonShown, 0x98);
