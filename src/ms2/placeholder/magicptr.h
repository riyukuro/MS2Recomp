#pragma once
// The 16 byte smart pointers shared by the magic, cube and world code (out-of-line members bound by VA in
// symbols-manual.tsv). They are MS2Ptr<Unk_FcTag> / MS2Ptr<Unk_FcArea> in functioncubeobject.cpp. The tag/value
// that WorldService::FUN_141bc3470 takes by value (the m_3f0 key/value) are these two types. Moved here from magicdata.h.
#include "ms2/ms2layout.h"

struct Unk_MagicTag;
struct Unk_MagicTagPtr {
    Unk_MagicTagPtr();                                              // 0x141234900
    Unk_MagicTagPtr(int);                                           // 0x1410a6af0
    Unk_MagicTagPtr(const Unk_MagicTagPtr&);                        // 0x1412348c0
    ~Unk_MagicTagPtr();                                             // 0x1410a6d40
    Unk_MagicTagPtr& operator=(const Unk_MagicTagPtr&);             // 0x141235040
    Unk_MagicTag* operator->() const;                               // 0x141235260
    bool operator==(Unk_MagicTag* p) const;                         // 0x141235120
    Unk_MagicTagPtr(Unk_MagicTag* p);                               // 0x1410a6b10 (scenestategame 0x3d)
    Unk_MagicTag* get() const;                                      // 0x1410a7150 (scenestategame 0x3d)
    void* m_pad;
    Unk_MagicTag* m_p;
};
MS2_CHECK_SIZE(Unk_MagicTagPtr, 0x10);
struct Unk_MagicValPtr {
    Unk_MagicValPtr() : m_p(0) {}                                   // 0x1414687c0 (inline)
    Unk_MagicValPtr(int);                                           // 0x141234840
    Unk_MagicValPtr(const Unk_MagicValPtr&);                        // 0x141234800
    ~Unk_MagicValPtr();                                             // 0x141234e70
    Unk_MagicValPtr& operator=(const Unk_MagicValPtr&);             // 0x141235000
    bool operator==(void* p) const;                                 // 0x1412350e0 (defined inline in worldservice_1.cpp)
    void* m_pad;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_MagicValPtr, 0x10);
