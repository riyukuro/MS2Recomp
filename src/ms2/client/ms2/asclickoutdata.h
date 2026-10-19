// asclickoutdata.h - UIMeratMarketDialogUtil::ASOutData (RTTI .?AVASOutData@UIMeratMarketDialogUtil@@, base AScript; 0x60
// bytes) and ASClickOutData (base ASOutData; 0xa0 bytes): the AS argument of a merat market product button click ("onClick"
// handlers). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed, member names invented. The code
// is in ?\uimeratmarketcommon.cpp: ASOutData ctor 0x140ec2690 (??_G 0x140ec36f0), ASClickOutData ctor 0x140ec2950 (the data
// object is an AScript of the "buyBtnData" child), dtor 0x140ec2a50 (??_G 0x140ec36b0). The definitions live in the exe;
// only the layout is declared here.
//
// The ASOutData ctor wraps the click's AS object, builds the product object from one of its children (a product created
// by ASMeratMarketProductBase::FUN_1409bbc30) and wraps the "renderer" child in an AScript.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asmeratmarketproduct.h"

namespace UIMeratMarketDialogUtil {

class ASOutData : public AScript
{
public:
    ASOutData(Scaleform::GFx::Value& v, int nMovieId);              // 0x140ec2690
    virtual ~ASOutData();                                           //  0 (??_G 0x140ec36f0)

    MS2Ptr<ASMeratMarketProductBase> FUN_140ec28b0();               // 0x140ec28b0 the product object
    MS2Ptr<AScript> FUN_140ec2900();                                // 0x140ec2900 the renderer

    MS2Ptr<ASMeratMarketProductBase> m_spProduct;                   // +0x40 the clicked product row
    MS2Ptr<AScript> m_spRenderer;                                   // +0x50 the "renderer" child
};

class ASClickOutData : public ASOutData
{
public:
    ASClickOutData(Scaleform::GFx::Value& v, int nMovieId);         // 0x140ec2950
    virtual ~ASClickOutData();                                      //  0 0x140ec2a50 (??_G 0x140ec36b0)

    AScript* FUN_140ec2a90();                                       // 0x140ec2a90 &m_buyBtnData

    AScript m_buyBtnData;                                           // +0x60 the "buyBtnData" child (price type etc.)
};

} // namespace UIMeratMarketDialogUtil

MS2_CHECK_SIZE(UIMeratMarketDialogUtil::ASOutData, 0x60);
MS2_CHECK_OFFSET(UIMeratMarketDialogUtil::ASOutData, m_spProduct, 0x40);
MS2_CHECK_OFFSET(UIMeratMarketDialogUtil::ASOutData, m_spRenderer, 0x50);
MS2_CHECK_SIZE(UIMeratMarketDialogUtil::ASClickOutData, 0xa0);
MS2_CHECK_OFFSET(UIMeratMarketDialogUtil::ASClickOutData, m_buyBtnData, 0x60);
