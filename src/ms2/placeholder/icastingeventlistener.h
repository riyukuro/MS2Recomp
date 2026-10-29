// icastingeventlistener.h - PLACEHOLDER for ICastingEventListener (RTTI .?AVICastingEventListener@@), the 8-byte
// (vftable only) interface that the casting-bar users derive from (UIMasteryDialog at +0x178, StateNurturing and
// StateTreeWatering at +0x40, ...). NOT an original header. Ctor 0x140ac2e60 (sets the vftable 0x142dd2140), no virtual
// destructor, two slots: both empty in the base (0x140ac3240, 0x140ac3250). The derived classes override them; the
// UIMasteryDialog ones are "casting finished" (slot 0) and "casting cancelled" (slot 1).
// Declared without a body: the ctor lives in the unit that owns the interface (bound through progress/symbols-manual.tsv).
#pragma once

class ICastingEventListener
{
public:
    ICastingEventListener() throw();        // 0x140ac2e60 (inline in the real header: the users see it cannot throw)
    virtual void OnCastingFinished() {}    // 0 0x140ac3240
    virtual void OnCastingCancelled() {}   // 1 0x140ac3250
};
