// uicommon.h - the UICommon namespace of the client's uicommon.cpp (UI helpers shared by many dialogs: wallet and
// currency checks, the key-block counters of the main PC, the dialog alignment record). Header name assumed
// (the unit's own __FILE__ is client\ms2\uicommon.cpp).
//
// CAlignmentInfo (RTTI .?AVCAlignmentInfo@UICommon@@, 0x30 bytes, vftable with the deleting dtor only): the placement of
// one dialog (alignment code, offset, and the defaults to fall back to). It derives from CPtred and is held by
// SnowmanPtr<> / MS2Ptr<> in the dialogs.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class Unk_140165cf0;    // game TinyXML element

namespace UICommon {

class CAlignmentInfo : public CPtred
{
public:
    CAlignmentInfo();                                                       // 0x1419014c0 (centre, defaults 5)
    CAlignmentInfo(int nAlign, float x, float y);                           // 0x141901540
    virtual ~CAlignmentInfo();                                              // 0x141904710 (??_G 0x1419049f0)
    void FUN_1419015e0(Unk_140165cf0* pNode);                                         // write offsetX / offsetY / alignType
    bool FUN_141901660(Unk_140165cf0* pNode);                                         // read them back
    void FUN_141901760(MS2Ptr<AScript> spScript);                           // remember the dialog's current placement
    void FUN_141901880(MS2Ptr<AScript> spScript, float fParentW, float fParentH, float fW, float fH);   // classify the position
    void FUN_141901b20(int nAlign, float x, float y);
    void FUN_141901b70(MS2Ptr<AScript> spScript);                           // vslot 2 of the dialog root
    void FUN_141901c10(MS2Ptr<AScript> spScript, int nW, int nH);           // vslot 1 of the dialog root
    void FUN_14015b020();                                                   // SnowmanPtr<> refcount glue (CPtred helpers, same VAs)
    int FUN_140159bc0();
    void FUN_140159ba0();
    void FUN_141901cd0();                                                   // back to the defaults

private:
    MS2_LAYOUT_FRIEND;
    float m_x;                                                              // +0x18
    float m_y;                                                              // +0x1c
    int m_align;                                                            // +0x20
    float m_defaultX;                                                       // +0x24
    float m_defaultY;                                                       // +0x28
    int m_defaultAlign;                                                     // +0x2c
};
MS2_CHECK_SIZE(CAlignmentInfo, 0x30);

}  // namespace UICommon
