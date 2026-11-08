// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTriggerState: the Scaleform AS UI component behind the
// trigger editor (an ASUIComponent, 0x88 bytes, vftable 0x142dbf4c0, 25 slots). The class adds no members and no
// virtuals of its own: its vftable is ASUIComponent's slot list (3 / 4 override ASDisplayObject, 16-24 are
// ASUIComponent's, inherited from placeholder/asuicomponent.h with MS2_ASUICOMPONENT_SLOTS).
// MS2-UNIT: ?\astriggerstate.cpp
// MS2-RANGE: 0x1409f00e0-0x1409f01a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\astriggerstate.cpp"
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class ASTriggerState : public ASUIComponent
{
public:
    ASTriggerState(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1409f00e0
    virtual ~ASTriggerState();                                      // 0x1409f0130
};
MS2_CHECK_SIZE(ASTriggerState, 0x88);

// @0x1409f00e0
ASTriggerState::ASTriggerState(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1409f0130
ASTriggerState::~ASTriggerState()
{
}
