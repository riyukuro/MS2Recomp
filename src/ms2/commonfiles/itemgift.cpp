// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item gift validation and serialization.
// MS2-UNIT: commonfiles\itemgift.cpp
// MS2-PIN: ??_GItemGift@@UEAAPEAXI@Z 0x1405b3ea0
// MS2-RANGE: 0x1405b38e0-0x1405b4080 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemgift.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemgift.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
struct Unk_GiftItem { bool FUN_14053c7c0(); };
struct Unk_GiftItemPtr {
    ~Unk_GiftItemPtr(); // 0x1401b50d0
    bool FUN_1402ffd90();
    Unk_GiftItem* FUN_1401b52a0();
    void* m_00; Unk_GiftItem* m_08;
};
MS2_CHECK_SIZE(Unk_GiftItemPtr,0x10);
Unk_GiftItemPtr FUN_14053f870(unsigned int);
CStringW FUN_140292a70(const wchar_t*,const unsigned int&);
int FUN_14053feb0(unsigned int);
enum { ItemRank_Unknown=0 };
void FUN_140873220(void*,const char*,unsigned int&);
void FUN_1408731e0(void*,const char*,int&);
// @0x1405b38e0
ItemGift::ItemGift() {}
// @0x1405b3930
int ItemGift::ValidateItem(CString& error) {
    Unk_GiftItemPtr item=FUN_14053f870(m_itemId);
    if(item.FUN_1402ffd90()) { error=(const wchar_t*)FUN_140292a70(L"ItemGift::ValidateItem no item:{0}",m_itemId);return 0; }
    if(m_count>1) {
        if(!item.FUN_1401b52a0()->FUN_14053c7c0()) { error=(const wchar_t*)FUN_140292a70(L"ItemGift::ValidateItem no foldable item:{0}",m_itemId);return 0; }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1405B3930, ItemGift, ValidateItem, 363, 0x5ABDEF96);
// @0x1405b3ab0
int ItemGift::vfunc_o18_1() {
    int itemRank=FUN_14053feb0(vfunc_o18_0());
    MS2_ASSERT_AT(32,itemRank != ItemRank_Unknown);
    return itemRank;
}
MS2_REPLACE_METHOD_VIA(0x1405B3AB0, ItemGift, ItemAble, vfunc_o18_1, 92, 0x589C0B82);
// @0x1405b3b20
ItemGiftPcBang::ItemGiftPcBang() : m_giftId(0) {}
// @0x1405b3b70
void ItemGiftPcBang::vfunc_4(void* xml) { ItemEntity::vfunc_2(xml);FUN_140873220(xml,"giftID",m_giftId); }
MS2_REPLACE_METHOD(0x1405B3B70, ItemGiftPcBang, vfunc_4, 63, 0x2610ADE3);
// @0x1405b3bc0
void ItemGiftPcBang::vfunc_5(Unk_GiftOutput& out) { FUN_14026b030(out);out.FUN_14070f9a0(m_giftId); }
MS2_REPLACE_METHOD(0x1405B3BC0, ItemGiftPcBang, vfunc_5, 52, 0x19D5B21B);
// @0x1405b3c00
void ItemGiftPcBang::vfunc_6(Unk_GiftInput& in) { FUN_14026b100(in);in.FUN_14070f480(m_giftId); }
MS2_REPLACE_METHOD(0x1405B3C00, ItemGiftPcBang, vfunc_6, 56, 0x5310BBA1);
// @0x1405b3c40
PlayBonusItemGift::PlayBonusItemGift() : m_systemMailId(0) {}
// @0x1405b3c90
void PlayBonusItemGift::vfunc_4(void* xml) {
    ItemGiftPcBang::vfunc_4(xml);
    int minutes=0;
    FUN_1408731e0(xml,"requireMins",minutes);
    FUN_140873220(xml,"systemMailID",m_systemMailId);
    m_requiredTime=minutes*60*1000;
}
MS2_REPLACE_METHOD(0x1405B3C90, PlayBonusItemGift, vfunc_4, 112, 0x45D5D2E0);
// @0x1405b3d10
void PlayBonusItemGift::vfunc_5(Unk_GiftOutput& out) { ItemGiftPcBang::vfunc_5(out);out.vfunc_3(m_requiredTime);out.vfunc_3(m_3c); }
MS2_REPLACE_METHOD(0x1405B3D10, PlayBonusItemGift, vfunc_5, 82, 0x0E6B1B17);
// @0x1405b3d70
void PlayBonusItemGift::vfunc_6(Unk_GiftInput& in) { ItemGiftPcBang::vfunc_6(in);m_requiredTime=in.vfunc_3();m_3c=in.vfunc_3(); }
MS2_REPLACE_METHOD(0x1405B3D70, PlayBonusItemGift, vfunc_6, 82, 0x1EFACAA7);
// @0x1405b3dd0
unsigned int PlayBonusItemGift::GetHours() { return GetMinutes()/60; }
MS2_REPLACE_METHOD(0x1405B3DD0, PlayBonusItemGift, GetHours, 33, 0xB81DB5E9);
// @0x1405b3e00
unsigned int PlayBonusItemGift::GetMinutes() { return m_requiredTime/1000/60; }
MS2_REPLACE_METHOD(0x1405B3E00, PlayBonusItemGift, GetMinutes, 32, 0xD8CE197E);
MS2_EMIT_CRT_MEMMOVE_S();
