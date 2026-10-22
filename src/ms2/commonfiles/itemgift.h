// Recovered item gift types. Field names inferred; class/base names from RTTI.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
struct Unk_GiftOutput { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(unsigned int); void FUN_14070f9a0(unsigned int); };
struct Unk_GiftInput { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual unsigned int vfunc_3(); void FUN_14070f480(unsigned int&); };
struct ItemAble {
    virtual unsigned int vfunc_o18_0() = 0;
    virtual int vfunc_o18_1() = 0;
    virtual unsigned int vfunc_o18_2() = 0;
    virtual bool vfunc_o18_3() = 0;
};
struct ItemEntity : CPtred, ItemAble {
    ItemEntity();
    // Both member-wise forms exist in the exe (0x1401dbe60 / 0x14027dbd0).
    // Explicitly retain them despite the recovered out-of-line destructor declaration.
    ItemEntity(const ItemEntity&) = default;
    ItemEntity(ItemEntity&&) = default;
    ItemEntity& operator=(const ItemEntity&) = default;
    ItemEntity(unsigned id,int rank,unsigned count,bool b28,bool b2a,bool b29,bool b2b);   // 0x14026abf0 (rx2a)
    ItemEntity(ItemAble& source);                                                             // 0x14026acb0 (rx2a)
    virtual ~ItemEntity() = default;   // 0x1401dc170 (exe body: only call CPtred::~CPtred)
    virtual void vfunc_1(CStringW);
    virtual void vfunc_2(void*);
    virtual unsigned int vfunc_o18_0();
    virtual int vfunc_o18_1();
    virtual unsigned int vfunc_o18_2();
    virtual bool vfunc_o18_3();
    void FUN_14026b030(Unk_GiftOutput&);
    void FUN_14026b030(Unk_GiftOutput&) const;   // same function, called through a const ItemEntity& (SnowmanContext::Write)
    void FUN_14026b100(Unk_GiftInput&);
    bool FUN_14026aff0(); bool FUN_14026b010(); void FUN_14026b1c0(int rank);   // rx2a: byte getters/setter
    unsigned int m_itemId;
    unsigned int m_count;
    bool m_28,m_29,m_2a,m_2b;
    int m_rank;
};
struct ItemGift : ItemEntity {
    ItemGift();
    virtual ~ItemGift(); // Existing shared destructor, outside this unit's function map.
    virtual int ValidateItem(CString&);
    virtual int vfunc_o18_1();
};
struct ItemGiftPcBang : ItemGift {
    ItemGiftPcBang();
    virtual void vfunc_4(void*);
    virtual void vfunc_5(Unk_GiftOutput&);
    virtual void vfunc_6(Unk_GiftInput&);
    unsigned int m_giftId;
};
struct PlayBonusItemGift : ItemGiftPcBang {
    PlayBonusItemGift();
    virtual void vfunc_4(void*);
    virtual void vfunc_5(Unk_GiftOutput&);
    virtual void vfunc_6(Unk_GiftInput&);
    unsigned int GetHours();
    unsigned int GetMinutes();
    unsigned int m_requiredTime;
    unsigned int m_3c;
    unsigned int m_systemMailId;
};
MS2_CHECK_SIZE(ItemAble,8);
MS2_CHECK_SIZE(ItemEntity,0x30);
MS2_CHECK_OFFSET(ItemEntity,m_itemId,0x20);
MS2_CHECK_OFFSET(ItemEntity,m_count,0x24);
MS2_CHECK_SIZE(ItemGift,0x30);
MS2_CHECK_SIZE(ItemGiftPcBang,0x38);
MS2_CHECK_OFFSET(ItemGiftPcBang,m_giftId,0x30);
MS2_CHECK_SIZE(PlayBonusItemGift,0x48);
MS2_CHECK_OFFSET(PlayBonusItemGift,m_requiredTime,0x38);
MS2_CHECK_OFFSET(PlayBonusItemGift,m_systemMailId,0x40);
