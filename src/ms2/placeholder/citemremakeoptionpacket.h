// citemremakeoptionpacket.h - PLACEHOLDER for the item option remake packet records (RTTI-named, nested in
// CCItemRemakeOptionPacket; here a namespace, which mangles the same). NOT an original header. Layouts from the ctors in
// ?\itemremakescrolldata.cpp (0x1406171b0..0x140617990), used by unit_14129cfa0 (UIItemRemakeOptionDialog), which only
// constructs them on the stack, fills members and encodes/decodes them. The bodies stay in the exe (symbols-manual rows).
//   RemakeOptionBase  0x28 : CPtred(0x18) + two __int64 (+0x18, +0x20); slots dtor / vfunc_1 (encode) / vfunc_2 (decode)
//   RemakeOption      0x40 : + the option list (+0x28)
//   RemakeOptionDebug 0x48 : + two ints (+0x40 kind, +0x44 value)
//   ApplyOptionBase   0x10 : vftable + __int64 (+8)
//   ForceFillIngredient 0x18 : vftable + __int64 (+8) + int (+0x10 count)
//   ApplyOptionClient 0x20 : ApplyOptionBase + MS2Ptr<CItem> (+0x10)
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/stream.h"

class CInPacket;

// A locked option (4 bytes; ctor 0x140b98d30), appended to the option list of the debug record.
struct Unk_LockOpt {
    Unk_LockOpt();                                                  // 0x140b98d30
    int m_v;
};
MS2_CHECK_SIZE(Unk_LockOpt, 4);

// The option list of a remake record: a vector of (kind, value) pairs, 0x18 bytes (unit_140267390.cpp defines the same
// struct; ctor 0x14027d690, dtor 0x14027e3f0).
struct Unk_RemakeOptionList50 {
    Unk_RemakeOptionList50();                                       // 0x14027d690
    ~Unk_RemakeOptionList50();                                      // 0x14027e3f0
    Unk_RemakeOptionList50& operator=(const Unk_RemakeOptionList50& o); // 0x14027eb30
    void FUN_140b9b410(const Unk_LockOpt& opt);                     // append
    void* m_first; void* m_last; void* m_end;
};
MS2_CHECK_SIZE(Unk_RemakeOptionList50, 0x18);

namespace CCItemRemakeOptionPacket {

class RemakeOptionBase : public CPtred {
public:
    RemakeOptionBase();                                             // 0x1406171b0
    virtual ~RemakeOptionBase();                                    // 0x140617200
    virtual void vfunc_1(COutputStream& out);                       // 0x140617230
    virtual void vfunc_2(CInPacket& in);                            // 0x140617280
    __int64 m_18;
    __int64 m_20;
};
MS2_CHECK_SIZE(RemakeOptionBase, 0x28);

class RemakeOption : public RemakeOptionBase {
public:
    RemakeOption();                                                 // 0x1406172f0
    virtual ~RemakeOption();                                        // 0x140617340
    virtual void vfunc_1(COutputStream& out);                       // 0x140617380
    virtual void vfunc_2(CInPacket& in);                            // 0x140617450
    Unk_RemakeOptionList50 m_options;                               // +0x28
};
MS2_CHECK_SIZE(RemakeOption, 0x40);

class RemakeOptionDebug : public RemakeOption {
public:
    RemakeOptionDebug();                                            // 0x140617560 (implicit dtor 0x14061ac30)
    virtual void vfunc_1(COutputStream& out);                       // 0x1406175b0
    virtual void vfunc_2(CInPacket& in);                            // 0x140617610
    int m_kind;                                                     // +0x40
    int m_value;                                                    // +0x44
};
MS2_CHECK_SIZE(RemakeOptionDebug, 0x48);

class ApplyOptionBase {
public:
    ApplyOptionBase();                                              // 0x140617690
    virtual ~ApplyOptionBase();                                     // 0x1406176c0
    virtual void vfunc_1(COutputStream& out);                       // 0x1406176e0
    virtual void vfunc_2(CInPacket& in);                            // 0x140617720
    __int64 m_uid;                                                  // +0x08
};
MS2_CHECK_SIZE(ApplyOptionBase, 0x10);

// No base (its ctor/dtor do not call ApplyOptionBase's), but the same leading layout.
class ForceFillIngredient {
public:
    ForceFillIngredient();                                          // 0x140617770
    virtual ~ForceFillIngredient();                                 // 0x1406177b0
    virtual void vfunc_1(COutputStream& out);                       // 0x1406177d0
    virtual void vfunc_2(CInPacket& in);                            // 0x140617820
    __int64 m_uid;                                                  // +0x08
    int m_count;                                                    // +0x10
};
MS2_CHECK_SIZE(ForceFillIngredient, 0x18);

class ApplyOptionClient : public ApplyOptionBase {
public:
    ApplyOptionClient();                                            // 0x140617890
    virtual ~ApplyOptionClient();                                   // 0x1406178e0
    virtual void vfunc_1(COutputStream& out);                       // 0x140617940
    virtual void vfunc_2(CInPacket& in);                            // 0x140617970
    MS2Ptr<CItem> m_item;                                           // +0x10
};
MS2_CHECK_SIZE(ApplyOptionClient, 0x20);

}

// RTTI CCItemRemakeOptionScrollPacket::RemakeOption (0x40 bytes, no base): the option remake request of a remake scroll.
namespace CCItemRemakeOptionScrollPacket {

class RemakeOption {
public:
    RemakeOption();                                                 // 0x1406179e0
    virtual ~RemakeOption();                                        // 0x140617a50
    virtual void vfunc_1(COutputStream& out);                       // 0x140617a90
    virtual void vfunc_2(CInPacket& in);                            // 0x140617bb0
    __int64 m_scrollUid;                                            // +0x08
    __int64 m_itemUid;                                              // +0x10
    __int64 m_ingredientUid;                                        // +0x18
    Unk_RemakeOptionList50 m_options;                               // +0x20
    bool m_bLocked;                                                 // +0x38
};
MS2_CHECK_SIZE(RemakeOption, 0x40);

}
