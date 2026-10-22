// Recovered UIGambleDialog (the gamble / loot box result dialog, UI type 0x4e98, 0x200 bytes); a sibling of
// UIRouletteDialog. Names of fields are inferred. Original header name assumed.
#pragma once
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

// Element types of the three arrays (distinct pointer types: each has its own CAtlArray COMDAT in the exe; names invented).
class Unk_GbListA;
class Unk_GbListB;
class Unk_GbListC;

class UIGambleDialog : public UIDialog
{
public:
    UIGambleDialog();                                                      // 0x141935200
    virtual ~UIGambleDialog() = default;                                         //  0 0x141935d40 (??_G 0x141935db0)
    virtual CString GetTypeName();                                             //  1 0x1419352b0
    virtual int vfunc_13();                                                // 13 0x141935660
    virtual void vfunc_15();                                               // 15 0x1419354d0 (returns this)
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141935670
    virtual void vfunc_43();                                               // 43 0x1419353c0
    virtual int vfunc_48();                                                // 48 0x141935df0
    virtual int vfunc_65();                                                // 65 0x141935300
    virtual void vfunc_67();                                               // 67 0x141935330
    virtual void vfunc_79(void* pPacket);                                  // 79 0x1419354f0

    int FUN_141935710();                                                   // fill the result items into the movie

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<Unk_GbListA*> m_178;                                  // +0x178 (only constructed / destroyed here)
    ATL::CAtlArray<Unk_GbListB*> m_198;                                           // +0x198
    ATL::CAtlArray<Unk_GbListC*> m_1b8;                                           // +0x1b8
    int m_1d8;                                                             // +0x1d8
    ATL::CAtlArray<CString> m_binds;                                       // +0x1e0 bind ids of the result icons
};
MS2_CHECK_SIZE(UIGambleDialog, 0x200);
MS2_CHECK_OFFSET(UIGambleDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIGambleDialog, m_1d8, 0x1d8);
MS2_CHECK_OFFSET(UIGambleDialog, m_binds, 0x1e0);
