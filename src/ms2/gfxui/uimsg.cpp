// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMsg, the ASData message a UISwfEntity hands to its
// IMessageListener.
// MS2-UNIT: ?\uimsg.cpp
// MS2-RANGE: 0x1422e4490-0x1422e4570 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings). ~UIMsg is implicit; its exe
// copy 0x140c30570 belongs to an earlier unit, so only the ctors, the getter and ??_G are in the range.
#include "ms2/placeholder/ms2stdafx.h"

#include "uimsg.h"

#include "hook/ms2hook.h"

// @0x1422e4490
UIMsg::UIMsg()
    : m_nMessage(0)
{
}

// @0x1422e44d0
UIMsg::UIMsg(int nMessage)
    : m_nMessage(nMessage)
{
}

// @0x1422e4520
int UIMsg::FUN_1422e4520()
{
    return m_nMessage;
}
MS2_REPLACE_METHOD(0x1422E4520, UIMsg, FUN_1422e4520, 14, 0x921EE467);
